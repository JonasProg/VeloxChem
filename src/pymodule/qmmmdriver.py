from mpi4py import MPI
import numpy as np
import time as tm
import contextlib
import sys
import os
from pathlib import Path
import matplotlib.pyplot as plt
import MDAnalysis as mda
from MDAnalysis.topology.guessers import guess_atom_element

from .molecule import Molecule
from .scfrestdriver import ScfRestrictedDriver
from .inputparser import InputParser
from .outputstream import OutputStream
from .rspabsorption import Absorption
from .veloxchemlib import hartree_in_ev


class QMMMDriver:
    """
    Implements QMMM driver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - comm: The MPI communicator.
        - rank: The rank of MPI process.
        - ostream: The output stream.
        - tpr_file: The tpr filename.
        - xtc_file: The xtc filename.
        - sampling_time: The time (in picosecond) for extracting frames from
          trajectory.
        - qm_region: The string for selecting QM region.
        - mm_pol_region: The string for selecting polarizable MM region.
        - mm_nonpol_region: The string for selecting non-polarizable MM region.
        - filename: The filename for the calculation.
        - nstates: The number of excited states.
        - diff_tol: if the first excitation energy is not too far away from
          averaged spectrum that np.abs(excitation energy - average)
          >= diff_tol * average
        - traj_unit: trajectory unit
        - line profile: either Gaussian or Lorentzian
        - line_param: line broadening parameter
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes QMMM driver.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            ostream = OutputStream(sys.stdout)

        self.comm = comm
        self.ostream = ostream

        self.tpr_file = None
        self.xtc_file = None
        self.sampling_time = np.zeros(1)

        self.qm_region = None
        self.mm_pol_region = None
        self.mm_nonpol_region = None

        self.filename = None
        self.method_dict = None
        self.description = 'N/A'

        self.nstates = 3

        self.diff_tol = 0.4

        self.line_profile = 'Gaussian'
        self.line_param = 0.1

        self.charges = None
        self.polarizabilities = None

    def update_settings(self,
                        qmmm_dict,
                        spect_dict,
                        rsp_dict,
                        method_dict=None):
        """
        Updates settings in qmmm driver.

        :param qmmm_dict:
            The input dictionary of qmmm group.
        :param spect_dict:
            The input dictionary of spectrum settings
        :param rsp_dict:
            The input dictionary of response settings
        :param method_dict:
            The input dicitonary of method settings group.
        """

        if 'topology_file' in qmmm_dict:
            self.tpr_file = qmmm_dict['topology_file']
        if 'trajectory_file' in qmmm_dict:
            self.xtc_file = qmmm_dict['trajectory_file']
        if 'sampling_time' in qmmm_dict:
            self.sampling_time = np.array(
                InputParser.parse_frequencies(qmmm_dict['sampling_time']))

        if 'quantum_region' in qmmm_dict:
            self.qm_region = qmmm_dict['quantum_region']
        if 'classical_polarizable_region' in qmmm_dict:
            self.mm_pol_region = qmmm_dict['classical_polarizable_region']
        if 'classical_non-polarizable_region' in qmmm_dict:
            self.mm_nonpol_region = qmmm_dict[
                'classical_non-polarizable_region']

        if 'filename' in qmmm_dict:
            self.filename = qmmm_dict['filename']
        if 'description' in qmmm_dict:
            self.description = qmmm_dict['description']

        if 'charges' in qmmm_dict:
            self.charges = qmmm_dict['charges']
        if 'polarizabilities' in qmmm_dict:
            self.polarizabilities = qmmm_dict['polarizabilities']

        if method_dict is not None:
            self.method_dict = dict(method_dict)

        if 'line_profile' in spect_dict:
            self.line_profile = str(spect_dict['line_profile'])

        if 'broadening_parameter' in spect_dict:
            self.line_param = float(spect_dict['broadening_parameter'])
            if 'units' in spect_dict and spect_dict['units'].lower() == 'ev':
                self.line_param /= hartree_in_ev()

        if 'nstates' in rsp_dict:
            self.nstates = int(rsp_dict['nstates'])

    def compute(self, molecule, basis, min_basis):
        """
        Performs QMMM calculation.

        :param frame_numbers:
            a list contains the frame numbers
        :param list_ex_energy:
            excitation energies in the follwoing format (frame1(S1,S2..Sn),
            frame2(S1,S2...Sn) ....frame_n(S1,S2...Sn)
        :param list_osci_strength:
            as above but for scillator strengths
        """

        self.print_header()

        start_time = tm.time()

        qm_elems = molecule.get_labels()
        qm_charge = molecule.get_charge()
        qm_multiplicity = molecule.get_multiplicity()

        output_dir = Path(self.filename + '_files')
        output_dir.mkdir(parents=True, exist_ok=True)

        u = mda.Universe(self.tpr_file, self.xtc_file, refresh_offsets=True)

        # set up variables for average spectrum calculations
        frame_numbers = []
        list_ex_energy = []
        list_osci_strength = []

        # go through frames in trajectory
        for ts in u.trajectory:
            # skip frames that are not in sampling_time
            if np.min(np.abs(self.sampling_time - u.trajectory.time)) > 1e-6:
                continue
            self.print_frame_and_time(ts.frame, u.trajectory.time)

            # select QM, MM_pol and MM_nonpol regions
            qm = u.select_atoms(self.qm_region)
            mm_pol_select = 'byres around ' + self.mm_pol_region + ' ' + self.qm_region
            mm_pol = u.select_atoms(mm_pol_select)

            if int(self.mm_nonpol_region) >= int(self.mm_pol_region):
                mm_nonpol_select = ('byres around ' + self.mm_nonpol_region +
                                    ' ' + self.qm_region)
                mm_nonpol = u.select_atoms(mm_nonpol_select)
                mm_nonpol = mm_nonpol - mm_pol

            # crate pdb files
            with open(os.devnull, 'w') as f_devnull:
                with contextlib.redirect_stderr(f_devnull):
                    qm.write(output_dir /
                             f'{self.filename}_frame_{ts.frame}.pdb')

            # make QM molecule whole
            qm.unwrap()
            # shift QM, MM_pol and MM_nonpol to center of the box
            box_center = 0.5 * np.sum(ts.triclinic_dimensions, axis=0)
            shift = box_center - qm.center_of_geometry()
            qm.positions += shift
            mm_pol.positions += shift
            mm_nonpol.positions += shift
            # apply periodic boundary condition for MM
            mm_pol.pack_into_box()
            mm_nonpol.pack_into_box()
            # shift QM, MM_pol and MM_nonpol to (0,0,0)
            qm.positions -= box_center
            mm_pol.positions -= box_center
            mm_nonpol.positions -= box_center

            # create molecule
            qm_mol = Molecule(qm_elems, qm.positions, 'angstrom')
            qm_mol.set_charge(qm_charge)
            qm_mol.set_multiplicity(qm_multiplicity)

            # create potential file
            potfile = output_dir / f'{self.filename}_frame_{ts.frame}.pot'

            with open(str(potfile), 'w') as f_pot:
                f_pot.write('@environment' + os.linesep)
                f_pot.write('units: angstrom' + os.linesep)
                f_pot.write('xyz:' + os.linesep)

                res_count = 0

                # write coordinates for the polarizable region
                res_name = 'water'
                for res in mm_pol.residues:
                    res_count += 1
                    for atom in res.atoms:
                        atom_label = guess_atom_element(atom.name)
                        f_pot.write(f'{atom_label:<5s}' +
                                    f'{atom.position[0]:15.8f}' +
                                    f'{atom.position[1]:15.8f}' +
                                    f'{atom.position[2]:15.8f}' +
                                    f'{res_name:>10s}' + f'{res_count:8d}' +
                                    os.linesep)

                # write coordinate for the non-polarizable region
                res_name = 'water-n'
                for res in mm_nonpol.residues:
                    res_count += 1
                    for atom in res.atoms:
                        atom_label = guess_atom_element(atom.name)
                        f_pot.write(f'{atom_label:<5s}' +
                                    f'{atom.position[0]:15.8f}' +
                                    f'{atom.position[1]:15.8f}' +
                                    f'{atom.position[2]:15.8f}' +
                                    f'{res_name:>10s}' + f'{res_count:8d}' +
                                    os.linesep)

                f_pot.write('@end' + os.linesep + os.linesep)

                # charges
                if self.charges:
                    f_pot.write('@charges' + os.linesep)
                    for line in self.charges:
                        f_pot.write(line + os.linesep)
                    f_pot.write('@end' + os.linesep + os.linesep)

                # polarizabilities
                if self.polarizabilities:
                    f_pot.write('@polarizabilities' + os.linesep)
                    for line in self.polarizabilities:
                        f_pot.write(line + os.linesep)
                    f_pot.write('@end' + os.linesep + os.linesep)

            # update method_dict with potential file
            if Path(potfile).is_file():
                self.method_dict['potfile'] = str(potfile)
            else:
                self.method_dict.pop('potfile', None)

            # setup output stream
            output = output_dir / '{}_frame_{}.out'.format(
                self.filename, ts.frame)
            ostream = OutputStream(str(output))
            self.print_molecule_and_basis(qm_mol, basis, ostream)

            # run SCF
            scf_drv = ScfRestrictedDriver(self.comm, ostream)
            scf_drv.update_settings({}, self.method_dict)
            scf_drv.compute(qm_mol, basis)

            scf_energy = scf_drv.get_scf_energy()
            self.print_scf_energy(scf_energy)

            # run response for spectrum
            abs_spec = Absorption({'nstates': self.nstates}, self.method_dict)
            abs_spec.init_driver(self.comm, ostream)
            abs_spec.compute(qm_mol, basis, scf_drv.scf_tensors)
            abs_spec.print_property(ostream)

            excitation_energies = abs_spec.get_property('eigenvalues')
            oscillator_strengths = abs_spec.get_property('oscillator_strengths')
            self.print_excited_states(excitation_energies, oscillator_strengths)

            # save frame number, excitation energies& oscillator strength
            frame_numbers.append(ts.frame)
            list_ex_energy.append(excitation_energies)
            list_osci_strength.append(oscillator_strengths)

        # create json file for spectra data
        json_data = open(str(output_dir / 'spectrum.json'), 'w+')
        json_data.write('{' + os.linesep)
        json_data.write(f'  "{self.qm_region}":' + '{' + os.linesep)
        json_data.write(f'    "description": {self.description},' + os.linesep)
        json_data.write('    "excitation energies & ocillator strength": [' +
                        os.linesep)

        for item1, item2 in zip(list_ex_energy, list_osci_strength):
            ene_str = ','.join([str(x) for x in item1])
            osc_str = ','.join([str(x) for x in item2])
            json_data.write(f'      [[{ene_str}],' + os.linesep)
            json_data.write(f'       [{osc_str}]],' + os.linesep)

        json_data.write('    ]' + os.linesep)
        json_data.write('  }' + os.linesep)
        json_data.write('}' + os.linesep)
        json_data.close()

        # run spectrum broadening
        self.spectrum_broadening(list_ex_energy, list_osci_strength,
                                 frame_numbers, output_dir)

        # print time spent in QMMM
        valstr = '*** Time spent in QMMM calculation: '
        valstr += '{:.2f} sec ***'.format(tm.time() - start_time)
        self.ostream.print_header(valstr)
        self.ostream.print_blank()
        self.ostream.flush()

    def print_header(self):
        """
        Prints header for QMMM driver.
        """

        self.ostream.print_blank()
        self.ostream.print_header('QMMM Driver Setup')
        self.ostream.print_header(19 * '=')
        self.ostream.print_blank()

        lines = []
        lines.append('TPR file                 :    ' + self.tpr_file)
        lines.append('XTC file                 :    ' + self.xtc_file)
        lines.append('QM region                :    ' + self.qm_region)
        lines.append('Pol. MM Region           :    ' + self.mm_pol_region)
        lines.append('Non-Pol. MM Region       :    ' + self.mm_nonpol_region)

        lines.append('Spect Line Profile       :    ' + self.line_profile)
        lines.append('Broadening parameter     :    ' + str(self.line_param))

        maxlen = max([len(line) for line in lines])
        for line in lines:
            self.ostream.print_header(line.ljust(maxlen))

        self.ostream.print_blank()
        self.ostream.flush()

    def print_frame_and_time(self, frame, time):
        """
        Prints frame number and simulation time to output stream.

        :param frame:
            The frame number.
        :param time:
            The simulation time.
        """

        info_text = 'Frame: {:d}  (Time: {:.3f} ps)'.format(frame, time)
        self.ostream.print_blank()
        self.ostream.print_info(info_text)
        self.ostream.print_blank()
        self.ostream.flush()

    def print_molecule_and_basis(self, molecule, basis, ostream):
        """
        Prints molecule and basis set to output stream.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        :param ostream:
            The output stream.
        """

        ostream.print_block(molecule.get_string())
        ostream.print_block(molecule.more_info())
        ostream.print_blank()
        ostream.print_block(basis.get_string('Atomic Basis', molecule))
        ostream.flush()

    def print_scf_energy(self, scf_energy):
        """
        Prints SCF energy to output stream.

        :param scf_energy:
            The SCF energy.
        """

        self.ostream.print_info('SCF energy: {:.10f} a.u.'.format(scf_energy))
        self.ostream.print_blank()
        self.ostream.flush()

    def print_excited_states(self, excitation_energies, oscillator_strengths):
        """
        Prints excited states to output stream.

        :param excitation_energies:
            The excitation energies.
        :param oscillator_strengths:
            The oscillator strengths.
        """

        for s in range(self.nstates):
            e = excitation_energies[s] * hartree_in_ev()
            f = oscillator_strengths[s]
            valstr = 'excited state S{:d}:'.format(s + 1)
            valstr += '{:12.6f} eV     Osc.Str. {:10.4f}'.format(e, f)
            self.ostream.print_info(valstr)
        self.ostream.print_blank()
        self.ostream.flush()

    def spectrum_broadening(self, list_ex_energy, list_osci_strength,
                            frame_numbers, output_dir):
        """
        Calculate the spectrum with either a Gaussian or Lourenzian line profile

        :param Xmin-Xmax:
            the range for x-axis (Energy in Hartees).
        :param x:
            data for x axis.
        :param y:
            data for y axis.
        """

        x_min = np.amin(list_ex_energy) - 0.02
        x_max = np.amax(list_ex_energy) + 0.02
        x = np.arange(x_min, x_max, 0.001)
        y = np.zeros((len(list_ex_energy), len(x)))

        # go through the frames and calculate the spectrum for each frame
        for i in range(len(list_ex_energy)):
            for xp in range(len(x)):
                for e, f in zip(list_ex_energy[i], list_osci_strength[i]):
                    if self.line_profile == 'Gaussian':
                        y[i][xp] += f * np.exp(-(
                            (e - x[xp]) / self.line_param)**2)
                    elif self.line_profile == 'Lorentzian':
                        y[i][xp] += 0.5 * self.line_param * f / (np.pi * (
                            (x[xp] - e)**2 + 0.25 * self.line_param**2))

        # x_max: the corresponding excitation energy
        # absorption_max: the largest peak
        x_max, absorption_max = self.plot_spectra(x, y, output_dir, 'initial')

        # Decide which frames to be deleted
        # Depending on whether the first absorption lies too far away from average
        for i in range(len(y)):
            if np.abs(list_ex_energy[i][0] - x_max) >= self.diff_tol * x_max:
                np.delete(y, i, 0)
                frame = int(frame_numbers[i])
                self.ostream.print_info(
                    'frame {} is very distorted, check geometry'.format(frame))

        self.plot_spectra(x, y, output_dir, 'final')

    def plot_spectra(self, x, y, output_dir, label):
        """
        calculate & plot averaged spectra, return peak value

        :param: x_max
            x value (energy) for the largest(first) excitation
        :param: absorption_max
            y value (absorption)  for the largest(first) excitation

        :return:
            x_max, absorption_max
        """

        # calculate the average spectrum
        y_averaged = []
        for i in range(len(x)):
            tot = 0
            for j in range(len(y)):
                tot += y[j][i]
            y_averaged.append(tot / len(y))

        # obtain absorption_max and x_max
        absorption_max = max(y_averaged)
        x_max = None
        for a, b in zip(x, y_averaged):
            if b == absorption_max:
                x_max = a

        hartee_to_nm = 45.563

        # plot spectra in output_dir folder
        plt.figure(figsize=(8, 4))
        plt.plot(hartee_to_nm / x, y_averaged)
        plt.ylabel('Absorption')
        plt.xlabel('Wavelength (nm)')
        plt.savefig(output_dir / 'average-spec_{}nm-{}.pdf'.format(
            round(hartee_to_nm / x_max, 2), label))

        return x_max, absorption_max
