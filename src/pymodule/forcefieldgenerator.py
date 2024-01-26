#
#                           VELOXCHEM 1.0-RC3
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2022 by VeloxChem developers. All rights reserved.
#  Contact: https://veloxchem.org/contact
#
#  SPDX-License-Identifier: LGPL-3.0-or-later
#
#  This file is part of VeloxChem.
#
#  VeloxChem is free software: you can redistribute it and/or modify it under
#  the terms of the GNU Lesser General Public License as published by the Free
#  Software Foundation, either version 3 of the License, or (at your option)
#  any later version.
#
#  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
#  License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

from mpi4py import MPI
from pathlib import Path
import numpy as np
import tempfile
import sys
import re

from .veloxchemlib import mpi_master, bohr_in_angstrom, hartree_in_kcalpermol
from .atomtypeidentifier import AtomTypeIdentifier
from .molecule import Molecule
from .outputstream import OutputStream
from .respchargesdriver import RespChargesDriver
from .openmmdriver import OpenMMDriver
from .openmmgradientdriver import OpenMMGradientDriver
from .optimizationdriver import OptimizationDriver
from .inputparser import parse_input, get_random_string_parallel
from .errorhandler import assert_msg_critical


class ForceFieldGenerator:
    """
    Parameterizes general Amber force field and creates Gromacs topologies.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables:
        - molecule_name: The name of the molecule.
        - eq_param: If equilibrium bond lengths and angles should be used.
        - r_thresh: The threshold for warning if bond lenghts deviate (nm).
        - theta_thresh: The threshold for warning if bond angle deviate (deg).
        - gen_pairs: If 1-4 parameters should be generated.
        - fudgeLJ: The factor by which to multiply Lennard-Jones 1-4 interactions.
        - fudgeQQ: The factor by which to multiply electrostatic 1-4 interactions.
        - comb_rule: The number of the combination rule in Gromacs.
        - nbfunc: The non-bonded function type (1: Lennard-Jones, 2: Buckingham).
        - nrexcl: Number of neighboring bonds to be excluded for non-bonded interaction.
        - force_field_data: The filename of the data file with force field parameters.
        - force_field_data_extension: The filename of the data file with user-specified
          parameters.
        - gromacs_include_path: The path to topology folder of Gromacs.
        - scan_dih_angles: The dihedral angles for MM scans (list of list).
        - scan_energies: The energies from QM scans (list of list).
        - scan_geometries: The optimized geometries from QM scan (list of list).
        - target_dihedrals: The target dihedral angles for parameterization.
        - ffversion: The version of the force field.
        - workdir: The working directory.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes force field generator.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            if comm.Get_rank() == mpi_master():
                ostream = OutputStream(sys.stdout)
            else:
                ostream = OutputStream(None)

        # mpi information
        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()

        # output stream
        self.ostream = ostream

        # molecule
        self.molecule_name = 'veloxchem_ff_' + get_random_string_parallel(
            self.comm)
        self.scan_xyz_files = None
        self.atom_types = None

        # topology settings
        self.eq_param = True
        self.r_thresh = 0.005
        self.theta_thresh = 10.
        self.gen_pairs = True
        self.fudgeLJ = 0.5
        self.fudgeQQ = (1.0 / 1.2)
        self.comb_rule = 2
        self.nbfunc = 1
        self.nrexcl = 3
        self.force_field_data = None
        self.force_field_data_extension = None

        # number of rounds for fitting dihedral potentials
        self.n_rounds = 3

        self.partial_charges = None
        self.original_top_file = None

        # MM settings
        self.gromacs_include_path = None

        # scan settings
        self.scan_dih_angles = None
        self.scan_energies = None
        self.scan_geometries = None
        self.target_dihedrals = None
        self.ffversion = 0

        self._workdir = None

        # resp settings
        self.resp_dict = None

        self.keep_files = True

    @property
    def workdir(self):
        """
        Getter function for protected workdir attribute.
        """

        return self._workdir

    @workdir.setter
    def workdir(self, value):
        """
        Setter function for protected workdir attribute.
        """

        self._workdir = value

    def update_settings(self, ffg_dict, resp_dict=None):
        """
        Updates settings in force field generator.

        :param ffg_dict:
            The input dictionary of force field group.
        :param resp_dict:
            The input dictionary of resp charges group.
        """

        ffg_keywords = {
            'molecule_name': 'str',
            'workdir': 'str',
            'scan_xyz_files': 'seq_fixed_str',
            'atom_types': 'seq_fixed_str',
            'eq_param': 'bool',
            'r_thresh': 'float',
            'theta_thresh': 'float',
            'gen_pairs': 'bool',
            'fudgeLJ': 'float',
            'fudgeQQ': 'float',
            'comb_rule': 'int',
            'nbfunc': 'int',
            'nrexcl': 'int',
            'gromacs_include_path': 'str',
            'force_field_data': 'str',
            'force_field_data_extension': 'str',
            'n_rounds': 'int',
            'partial_charges': 'seq_fixed',
            'original_top_file': 'str',
            'keep_files': 'bool',
        }

        parse_input(self, ffg_keywords, ffg_dict)

        if 'filename' in ffg_dict and 'molecule_name' not in ffg_dict:
            self.molecule_name = ffg_dict['filename']

        if self.force_field_data is not None:
            force_field_file = Path(
                self.molecule_name).parent / self.force_field_data
            if force_field_file.is_file():
                self.force_field_data = str(force_field_file)
                assert_msg_critical(
                    'gaff' in Path(self.force_field_data).name.lower(),
                    'ForceFieldGenerator: unrecognized force field ' +
                    f'{self.force_field_data}. Only GAFF is supported.')
                if self.force_field_data_extension is None:
                    ff_file = Path(self.force_field_data)
                    self.force_field_data_extension = str(
                        ff_file.parent / (ff_file.stem + '_extension.dat'))

        if resp_dict is None:
            resp_dict = {}
        self.resp_dict = dict(resp_dict)

    def compute(self, molecule, basis):
        """
        Runs force field optimization.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        """

        # atom type identification

        if self.atom_types is None:
            atomtypeidentifier = AtomTypeIdentifier(self.comm, self.ostream)
            self.atom_types = atomtypeidentifier.generate_gaff_atomtypes(
                molecule)

        # sanity check

        assert_msg_critical(
            self.scan_xyz_files is not None,
            'ForceFieldGenerator.compute: scan_xyz_files not defined ')

        assert_msg_critical(
            self.atom_types is not None,
            'ForceFieldGenerator.compute: atom_types not defined ')

        assert_msg_critical(
            len(self.atom_types) == molecule.number_of_atoms(),
            'ForceFieldGenerator.compute: inconsistent number of atom_types')

        self.molecule = molecule

        # RESP charges

        if self.partial_charges is None and self.original_top_file is None:
            resp_drv = RespChargesDriver(self.comm, self.ostream)
            resp_drv.update_settings(self.resp_dict)
            self.partial_charges = resp_drv.compute(self.molecule, basis,
                                                    'resp')

        # read QM scan

        self.ostream.print_blank()
        title = 'Force Field Generator'
        self.ostream.print_header(title)
        self.ostream.print_header('=' * (len(title) + 2))
        self.ostream.print_blank()

        self.scan_dih_angles = []
        self.scan_energies = []
        self.scan_geometries = []
        self.target_dihedrals = []

        inp_dir = Path(self.molecule_name).parent
        self.read_qm_scan_xyz_files(self.scan_xyz_files, inp_dir)

        mol_name = Path(self.molecule_name).stem

        self.ffversion = 0

        use_temp_dir = (self._workdir is None)

        if use_temp_dir:
            try:
                temp_dir = tempfile.TemporaryDirectory(
                    ignore_cleanup_errors=True)
            except TypeError:
                temp_dir = tempfile.TemporaryDirectory()
            self._workdir = Path(temp_dir.name)

        if self.original_top_file is None:
            original_itp_file = self._workdir / (mol_name +
                                                 f'_{self.ffversion:02d}.itp')
            original_top_file = original_itp_file.with_suffix('.top')

            if self.rank == mpi_master():
                self.write_original_itp(original_itp_file,
                                        list(self.atom_types),
                                        self.partial_charges)
                self.write_top(original_top_file, original_itp_file)
            self.comm.barrier()

        else:
            original_top_file = Path(self.original_top_file)

        self.ostream.print_info(
            f'Original topology file: {original_top_file.name}')
        self.ostream.print_blank()
        self.ostream.flush()

        # validate original force field

        for i, dih in enumerate(self.target_dihedrals):
            self.validate_force_field(original_top_file, i)

        # fit dihedral potentials

        n_rounds = self.n_rounds if len(self.scan_dih_angles) > 1 else 1
        target_top_file = original_top_file
        for i_round in range(n_rounds):
            for i, dih in enumerate(self.target_dihedrals):
                target_top_file = self.dihedral_correction(target_top_file, i)

        # validate final force field

        for i, dih in enumerate(self.target_dihedrals):
            self.validate_force_field(target_top_file, i)

        # save output files

        if self.rank == mpi_master() and self.keep_files:
            out_dir = Path(self.molecule_name + '_files')
            for ffver in range(self.ffversion + 1):
                for ftype in ['itp', 'top']:
                    fname = mol_name + f'_{ffver:02d}.{ftype}'
                    self.copy_file(self._workdir / fname, out_dir / fname)
                    valstr = f'Saving file: {str(out_dir / fname)}'
                    self.ostream.print_info(valstr)

            self.ostream.print_blank()
            self.ostream.flush()

        if use_temp_dir:
            try:
                temp_dir.cleanup()
            except (NotADirectoryError, PermissionError):
                pass
            self._workdir = None

    def read_qm_scan_xyz_files(self, scan_xyz_files, inp_dir=None):
        """
        Reads QM scan xyz files.

        :param scan_xyz_files:
            The list of xyz files from QM scan.
        """

        if self.scan_dih_angles is None:
            self.scan_dih_angles = []

        if self.scan_energies is None:
            self.scan_energies = []

        if self.scan_geometries is None:
            self.scan_geometries = []

        if self.target_dihedrals is None:
            self.target_dihedrals = []

        # reading QM data

        if inp_dir is None:
            inp_dir = Path('.')
        elif isinstance(inp_dir, str):
            inp_dir = Path(inp_dir)

        self.ostream.print_info('Reading QM scan from file...')

        for xyz in scan_xyz_files:
            xyz_fname = str(inp_dir / xyz)

            self.ostream.print_info(f'  {xyz_fname}')
            self.ostream.flush()

            geometries = []
            energies = []
            dih_angles = []

            # read geometries

            xyz_lines = None
            if self.rank == mpi_master():
                with open(xyz_fname, 'r') as f_xyz:
                    xyz_lines = f_xyz.readlines()
            xyz_lines = self.comm.bcast(xyz_lines, root=mpi_master())

            n_atoms = int(xyz_lines[0].split()[0])
            n_geoms = len(xyz_lines) // (n_atoms + 2)

            for i_geom in range(n_geoms):
                i_start = i_geom * (n_atoms + 2)
                i_end = i_start + (n_atoms + 2)

                assert_msg_critical(
                    int(xyz_lines[i_start].split()[0]) == n_atoms,
                    'ForceFieldGenerator.read_qm_scan_xyz_files: ' +
                    'inconsistent number of atoms')

                mol_str = ''.join(xyz_lines[i_start + 2:i_end])
                geometries.append(
                    Molecule.read_molecule_string(mol_str, units='angstrom'))

            self.scan_geometries.append(geometries)

            # read energies and dihedral angles

            pattern = re.compile(r'\AScan')

            for line in xyz_lines:
                if re.search(pattern, line):
                    energies.append(float(line.split('Energy')[1].split()[0]))
                    dih_angles.append(float(line.split('=')[1].split()[0]))
                    dih_inds = [
                        int(i)
                        for i in line.split('Dihedral')[1].split()[0].split('-')
                    ]
            self.scan_energies.append(energies)
            self.scan_dih_angles.append(dih_angles)
            self.target_dihedrals.append(dih_inds)

        self.ostream.print_blank()

    def update_dihedral_range(self, dih_start_end, i):
        """
        Updates the range of dihedral angles for i-th dihedral (0-based index).

        :param dih_start_end:
            A tuple containing the starting and ending values of dihedral angle.
        :param i:
            The index of the target dihedral.
        """

        new_scan_dih_angles = []
        new_scan_energies = []
        new_scan_geometries = []

        for angle, ene, geom in zip(
                self.scan_dih_angles[i],
                self.scan_energies[i],
                self.scan_geometries[i],
        ):
            if angle >= dih_start_end[0] and angle <= dih_start_end[1]:
                new_scan_dih_angles.append(angle)
                new_scan_energies.append(ene)
                new_scan_geometries.append(geom)

        self.scan_dih_angles[i] = new_scan_dih_angles
        self.scan_energies[i] = new_scan_energies
        self.scan_geometries[i] = new_scan_geometries

    def write_top(self, top_file, itp_file):
        """
        Writes a topology file.

        :param top_file:
            The topology file.
        :param itp_file:
            The included itp file.
        """

        top_fname = top_file if isinstance(top_file, str) else str(top_file)
        itp_fname = itp_file if isinstance(itp_file, str) else str(itp_file)

        mol_name = Path(self.molecule_name).stem

        with open(top_fname, 'w') as f_top:

            # header

            f_top.write('; Generated by VeloxChem\n')

            # defaults

            f_top.write('\n[ defaults ]\n')
            cur_str = '; nbfunc        comb-rule       gen-pairs'
            cur_str += '       fudgeLJ fudgeQQ\n'
            f_top.write(cur_str)
            gen_pairs = 'yes' if self.gen_pairs else 'no'
            f_top.write('{}{:16}{:>18}{:19.4f}{:8.4f}\n'.format(
                self.nbfunc, self.comb_rule, gen_pairs, self.fudgeLJ,
                self.fudgeQQ))

            # include itp

            f_top.write('\n#include "' + Path(itp_fname).name + '"\n')

            # system

            f_top.write('\n[ system ]\n')
            f_top.write(' {}\n'.format(mol_name))

            # molecules

            f_top.write('\n[ molecules ]\n')
            f_top.write('; Compound        nmols\n')
            f_top.write('{:>10}{:9}\n'.format(mol_name, 1))

    @staticmethod
    def get_gaff_data_lines():
        """
        Reads GAFF data lines into a list.
        """

        from urllib.request import urlopen

        openmmff_commit = 'b3e92a373c80bfb8fd791e4a72beafc035fcc722'
        gaff_url = (
            'https://raw.githubusercontent.com/openmm/openmmforcefields/' +
            openmmff_commit + '/openmmforcefields/ffxml/amber/gaff/dat/' +
            'gaff-2.11.dat')

        with urlopen(gaff_url) as f_gaff:
            content = f_gaff.read().decode('utf-8')

        return content.splitlines()
    
    # def identify_atom_types(self):  
    #     '''
    #     Identifies GAFF atom types.
    #     '''

    #     atomtypeidentifier = AtomTypeIdentifier(self.comm, self.ostream)
    #     self.atom_types = atomtypeidentifier.generate_gaff_atomtypes(
    #         self.molecule)
    #     atomtypeidentifier.check_for_bad_assignations(self.get_gaff_data_lines())
    #     self.connectivity_matrix = np.copy(atomtypeidentifier.connectivity_matrix)

    def analize_topology(self):
        '''
        Analizes the topology of the molecule and find parameters in GAFF.
        '''

        # Initialize the topology dictionary, the fields are:
        # - atomtypes: The atom types as the GROMACS directive.
        # - atoms: The atoms as the GROMACS directive.
        # - bonds: The bonds as the GROMACS directive.
        # - pairs: The pairs as the GROMACS directive.
        # - angles: The angles as the GROMACS directive.
        # - dihedrals: The dihedrals as the GROMACS directive.
        # - impropers: The impropers as the GROMACS directive. 

        topology = {
            'atomtypes': [],
            'atoms': [],
            'bonds': [],
            'pairs': [],
            'angles': [],
            'dihedrals': [],
            'impropers': [],
        }

        # Read the force field data lines.

        if self.force_field_data is None:
            ff_data_lines = self.get_gaff_data_lines()
        else:
            with open(self.force_field_data, 'r') as ff_data:
                ff_data_lines = ff_data.readlines()
     
        # Molecular information

        coords = self.molecule.get_coordinates_in_bohr()
        n_atoms = self.molecule.number_of_atoms()

        atomtypeidentifier = AtomTypeIdentifier()
        atomtypeidentifier.ostream.mute()

        # The atomtypes shall be accesible for the validation of the force field.
        self.atom_types = atomtypeidentifier.generate_gaff_atomtypes(self.molecule)
        atomtypeidentifier.check_for_bad_assignations(ff_data_lines)
        self.connectivity_matrix = np.copy(atomtypeidentifier.connectivity_matrix)
 
        # preparing atomtypes and atoms

        assert_msg_critical(
            len(self.atom_types) == n_atoms,
            'ForceFieldGenerator: inconsistent atom_types')

        for i in range(n_atoms):
           self.atom_types[i] = f'{self.atom_types[i].strip():<2s}'
        self.unique_atom_types = list(set(self.atom_types))
                
        atom_names = self.get_atom_names()

        # Bonds

        bond_indices = set()
        for i in range(n_atoms):
            for j in range(i + 1, n_atoms):
                if self.connectivity_matrix[i, j] == 1:
                    bond_indices.add((i, j))
        bond_indices = sorted(list(bond_indices))

        # Angles

        angle_indices = set()

        for i, j in bond_indices:
            for k in range(n_atoms):
                if k in [i, j]:
                    continue
                if self.connectivity_matrix[j, k] == 1:
                    inds = (i, j, k) if i < k else (k, j, i)
                    angle_indices.add(inds)
                if self.connectivity_matrix[k, i] == 1:
                    inds = (k, i, j) if k < j else (j, i, k)
                    angle_indices.add(inds)
        angle_indices = sorted(list(angle_indices))

        # Dihedrals

        dihedral_indices = set()

        for i, j, k in angle_indices:
            for l in range(n_atoms):
                if l in [i, j, k]:
                    continue
                if self.connectivity_matrix[k, l] == 1:
                    inds = (i, j, k, l) if i < l else (l, k, j, i)
                    dihedral_indices.add(inds)
                if self.connectivity_matrix[l, i] == 1:
                    inds = (l, i, j, k) if l < k else (k, j, i, l)
                    dihedral_indices.add(inds)
        dihedral_indices = sorted(list(dihedral_indices))

        # Exclusions

        exclusion_indices = []
        if self.nrexcl >= 2:
            for i, j in bond_indices:
                exclusion_indices.append((i, j))
        if self.nrexcl >= 3:
            for i, j, k in angle_indices:
                exclusion_indices.append((i, k))

        # 1-4 pairs

        pairs_14 = set()
        for i, j, k, l in dihedral_indices:
            if (i, l) not in exclusion_indices:
                pairs_14.add((i, l))
        pairs_14 = sorted(list(pairs_14))

        # Read the force field and include the data in the topology dictionary.

        # Atomtypes

        for at in self.unique_atom_types:
            atom_type_found = False

            for line in ff_data_lines:
                if line.startswith(f'  {at}     '):
                    atom_ff = line[5:].strip().split()
                    sigma = float(atom_ff[0]) * 2**(-1 / 6) * 2 / 10
                    epsilon = float(atom_ff[1]) * 4.184
                    comment = 'GAFF'
                    atom_type_found = True
                    break
            
            if not atom_type_found:
                warnmsg = f'ForceFieldGenerator: atom type {at} is not in GAFF.'
                self.ostream.print_warning(warnmsg)
                sigma = 0.0
                epsilon = 0.0
                comment = 'Unknown'


            # Save the data in the 'atomtypes' field of the topology dictionary.
            topology['atomtypes'].append(
                (at, sigma, epsilon, comment))
                
        # Atoms
                
        for i in range(n_atoms):
                    
                    atom_type = self.atom_types[i]
                    atom_name = atom_names[i]
                    if self.partial_charges is None:
                        charge = 0.0
                        warnmsg = f'ForceFieldGenerator: No partial charges'
                    else:
                        charge = self.partial_charges[i]

                    mass = self.molecule.masses_to_numpy()[i]
        
                    # Save the data in the 'atoms' field of the topology dictionary.
                    topology['atoms'].append(
                        (i + 1, atom_type, atom_name, i + 1, charge, mass))
                    
        # Bonds

        for i, j in bond_indices: 

            r_eq = np.linalg.norm(coords[i] - coords[j])
            r_eq *= bohr_in_angstrom() * 0.1

            at_1 = self.atom_types[i]
            at_2 = self.atom_types[j]
            patterns = [
                re.compile(r'\A' + f'{at_1}-{at_2}  '),
                re.compile(r'\A' + f'{at_2}-{at_1}  '),
            ]

            bond_found = False

            for line in ff_data_lines:
                matches = [re.search(p, line) for p in patterns]
                if any(matches):
                    bond_ff = line[5:].strip().split()
                    r = float(bond_ff[1]) * 0.1
                    k_r = float(bond_ff[0]) * 4.184 * 2 * 100
                    comment = 'GAFF'
                    bond_found = True
                    break

            if not bond_found:
                warnmsg = f'ForceFieldGenerator: bond {at_1}-{at_2}'
                warnmsg += ' is not available'
                self.ostream.print_warning(warnmsg)
                r = r_eq
                k_r = 250000 #Default value for bonds
                comment = 'Unknown'

            if self.eq_param:
                if abs(r - r_eq) > self.r_thresh:
                    msg = f'Updated bond length {i+1}-{j+1} '
                    msg += f'({at_1}-{at_2}) to {r_eq:.3f} nm'
                    self.ostream.print_info(msg)
                    self.ostream.flush()
                r = r_eq

            # Save the data in the 'bonds' field of the topology dictionary.
            topology['bonds'].append((i, j, r, k_r, comment))

        # Pairs

        for i, j in pairs_14:
            topology['pairs'].append((i, j))

        # Angles

        for i, j, k in angle_indices:
                
                a = coords[i] - coords[j]
                b = coords[k] - coords[j]
                theta_eq = np.arccos(
                    np.dot(a, b) / np.linalg.norm(a) /
                    np.linalg.norm(b)) * 180 / np.pi
    
                at_1 = self.atom_types[i]
                at_2 = self.atom_types[j]
                at_3 = self.atom_types[k]
                patterns = [
                    re.compile(r'\A' + f'{at_1}-{at_2}-{at_3} '),
                    re.compile(r'\A' + f'{at_3}-{at_2}-{at_1} '),
                ]
    
                angle_found = False
    
                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        angle_ff = line[8:].strip().split()
                        theta = float(angle_ff[1])
                        k_theta = float(angle_ff[0]) * 4.184 * 2
                        comment = 'GAFF'
                        angle_found = True
    
                if not angle_found:
                    warnmsg = f'ForceFieldGenerator: angle {at_1}-{at_2}-{at_3}'
                    warnmsg += ' is not available.'
                    self.ostream.print_warning(warnmsg)
                    theta = theta_eq
                    k_theta = 1000
                    comment = 'Unknown'

                if self.eq_param:
                    if abs(theta - theta_eq) > self.theta_thresh:
                        msg = f'Updated bond angle {i+1}-{j+1}-{k+1} '
                        msg += f'({at_1}-{at_2}-{at_3}) to {theta_eq:.3f} deg'
                        self.ostream.print_info(msg)
                        self.ostream.flush()
                    theta = theta_eq

                # Save the data in the 'angles' field of the topology dictionary.
                topology['angles'].append((i, j, k, theta, k_theta, comment))

        # Dihedrals

        for i, j, k, l in dihedral_indices:

            at_1 = self.atom_types[i]
            at_2 = self.atom_types[j]
            at_3 = self.atom_types[k]
            at_4 = self.atom_types[l]

            patterns = [
                re.compile(r'\A' + f'{at_1}-{at_2}-{at_3}-{at_4} '),
                re.compile(r'\A' + f'{at_4}-{at_3}-{at_2}-{at_1} '),
            ]

            dihedral_found = False

            dihedral_ff_lines = []
            for line in ff_data_lines:
                matches = [re.search(p, line) for p in patterns]
                if any(matches):
                    dihedral_ff = line[11:60].strip().split()
                    if len(dihedral_ff) == 4:
                        dihedral_ff_lines.append(line)
                        comment = 'GAFF'
                        dihedral_found = True

            if not dihedral_found:
                patterns = [
                    re.compile(r'\A' + f'X -{at_2}-{at_3}-X  '),
                    re.compile(r'\A' + f'X -{at_3}-{at_2}-X  '),
                ]

                dihedral_ff_lines = []
                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        dihedral_ff = line[11:60].strip().split()
                        if len(dihedral_ff) == 4:
                            dihedral_ff_lines.append(line)
                            comment = 'GAFF'
                            dihedral_found = True

            if not dihedral_found:
                warnmsg = f'ForceFieldGenerator: dihedral {at_1}-{at_2}-{at_3}-{at_4}'
                warnmsg += ' is not available.'
                self.ostream.print_warning(warnmsg)
                comment = 'Unknown'

            for line in dihedral_ff_lines:
                dihedral_ff = line[11:60].strip().split()

                multiplicity = int(dihedral_ff[0])
                barrier = float(dihedral_ff[1]) * 4.184 / multiplicity
                phase = float(dihedral_ff[2])
                # Note: negative periodicity implies multitermed dihedral
                # See https://ambermd.org/FileFormats.php
                try:
                    periodicity = int(dihedral_ff[3])
                except ValueError:
                    periodicity = int(float(dihedral_ff[3]))

                # Save the data in the 'dihedrals' field of the topology dictionary.
                topology['dihedrals'].append((i, j, k, l, multiplicity, barrier, phase, periodicity, comment))

                if periodicity > 0:
                    break
                

        # Impropers
                
        sp2_atom_types = [
            'c ', 'cs', 'c2', 'ca', 'cp', 'cq', 'cc', 'cd', 'ce', 'cf',
            'cu', 'cv', 'cz', 'n ', 'n2', 'na', 'nb', 'nc', 'nd', 'ne',
            'nf', 'pb', 'pc', 'pd', 'pe', 'pf'
        ]

        improper_atom_inds = []

        for i, j, k in angle_indices:
            at_1 = self.atom_types[i]
            at_2 = self.atom_types[j]
            at_3 = self.atom_types[k]

            if at_2 not in sp2_atom_types:
                continue

            if j not in improper_atom_inds:
                improper_atom_inds.append(j)
            else:
                continue

            for l in range(n_atoms):
                if (l in [i, j, k]) or (self.connectivity_matrix[l, j] != 1):
                    continue
                at_4 = self.atom_types[l]

                patterns = [
                    re.compile(r'\A' + f'{at_4}-{at_1}-{at_2}-{at_3} '),
                    re.compile(r'\A' + f'{at_4}-{at_3}-{at_2}-{at_1} '),
                    re.compile(r'\A' + f'{at_1}-{at_3}-{at_2}-{at_4} '),
                    re.compile(r'\A' + f'{at_1}-{at_4}-{at_2}-{at_3} '),
                    re.compile(r'\A' + f'{at_3}-{at_1}-{at_2}-{at_4} '),
                    re.compile(r'\A' + f'{at_3}-{at_4}-{at_2}-{at_1} '),
                ]

                dihedral_found = False

                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        dihedral_ff = line[11:60].strip().split()
                        if len(dihedral_ff) == 3:
                            comment = 'GAFF'
                            dihedral_found = True
                            break

                if not dihedral_found:
                    patterns = [
                        re.compile(r'\A' + f'X -{at_1}-{at_2}-{at_3} '),
                        re.compile(r'\A' + f'X -{at_3}-{at_2}-{at_1} '),
                        re.compile(r'\A' + f'X -{at_3}-{at_2}-{at_4} '),
                        re.compile(r'\A' + f'X -{at_4}-{at_2}-{at_3} '),
                        re.compile(r'\A' + f'X -{at_1}-{at_2}-{at_4} '),
                        re.compile(r'\A' + f'X -{at_4}-{at_2}-{at_1} '),
                    ]

                    for line in ff_data_lines:
                        matches = [re.search(p, line) for p in patterns]
                        if any(matches):
                            dihedral_ff = line[11:60].strip().split()
                            if len(dihedral_ff) == 3:
                                comment = 'GAFF'
                                dihedral_found = True
                                break


                if not dihedral_found:
                    patterns = [
                        re.compile(r'\A' + f'X -X -{at_2}-{at_3} '),
                        re.compile(r'\A' + f'X -X -{at_2}-{at_1} '),
                        re.compile(r'\A' + f'X -X -{at_2}-{at_4} '),
                    ]

                    for line in ff_data_lines:
                        matches = [re.search(p, line) for p in patterns]
                        if any(matches):
                            dihedral_ff = line[11:60].strip().split()
                            if len(dihedral_ff) == 3:
                                comment = 'GAFF'
                                dihedral_found = True
                                break

                if not dihedral_found:
                    warnmsg = f'ForceFieldGenerator: improper {at_1}-{at_2}-{at_3}-{at_4}'
                    warnmsg += ' is not available.'
                    # Defaults for impropers (1.1 kcal/mol, 180 deg, 2)
                    self.ostream.print_warning(warnmsg)
                    dihedral_ff = ['1.1', '180.0', '2']
                    comment = 'Unknown'
                    continue

                barrier = float(dihedral_ff[0]) * 4.184
                phase = float(dihedral_ff[1])
                periodicity = abs(int(float(dihedral_ff[2])))
                comment = 'GAFF'

                assert_msg_critical(
                    phase == 180.0,
                    'ForceFieldGenerator: invalid improper dihedral phase')
                assert_msg_critical(
                    periodicity == 2,
                    'ForceFieldGenerator: invalid improper dihedral periodicity'
                )

                # Save the data in the 'impropers' field of the topology dictionary.
                topology['impropers'].append((i, j, k, l, barrier, phase, periodicity, comment))
        
        return topology
        
    

    def generate_topology(self):
        '''
        Generate topology dictionary.
        '''

        topology = self.analize_topology()

        # Atoms
          
        self.atoms = {}

        ids = []
        types = []
        masses = []
        charges = []
        sigmas = []
        epsilons = []

        for i in topology['atoms']:
            ids.append(i[0] + 1) # IDs start at 1
            types.append(i[1])
            masses.append(i[-1])
            charges.append(i[-2])

        for i in types:
            # Look for the type in the atomtypes dictionary
            for j in topology['atomtypes']:
                if i == j[0]:
                    sigmas.append(j[1])
                    epsilons.append(j[2])

        for i in range(len(ids)):
            self.atoms[ids[i]] = {'type': types[i], 'mass': masses[i], 'charge': charges[i], 'sigma': sigmas[i], 'epsilon': epsilons[i]}

        # Bonds
            
        self.bonds = {}

        ids = []
        force_constants = []
        equilibrium_distances = []
        comments = []

        for i in topology['bonds']:
            ids.append((i[0] + 1, i[1] + 1))
            force_constants.append(i[3])
            equilibrium_distances.append(i[2])
            comments.append(i[-1])

        for i in range(len(ids)):
            self.bonds[ids[i]] = {'fc': force_constants[i], 'eq': equilibrium_distances[i], 'comment': comments[i]}


        # Angles
            
        self.angles = {}

        ids = []
        force_constants = []
        equilibrium_angles = []
        comments = []

        for i in topology['angles']:
            ids.append((i[0] + 1, i[1] + 1, i[2] + 1))
            force_constants.append(i[4])
            equilibrium_angles.append(i[3])
            comments.append(i[-1])

        for i in range(len(ids)):
            self.angles[ids[i]] = {'fc': force_constants[i], 'eq': equilibrium_angles[i], 'comment': comments[i]}

        # Dihedrals
            
        self.dihedrals = {}

        ids = []
        force_constants = []
        equilibrium_angles = []
        periodicities = []
        comments = []

        for i in topology['dihedrals']:
            ids.append((i[0] + 1, i[1] + 1, i[2] + 1, i[3] + 1))
            force_constants.append(i[5])
            equilibrium_angles.append(i[6])
            periodicities.append(i[7])
            comments.append(i[-1])

        for i in range(len(ids)):
            self.dihedrals[ids[i]] = {'fc': force_constants[i], 'eq': equilibrium_angles[i], 'periodicity': periodicities[i], 'comment': comments[i]}

        # Impropers
            
        self.impropers = {}

        ids = []
        force_constants = []
        equilibrium_angles = []
        periodicities = []
        comments = []

        for i in topology['impropers']:
            ids.append((i[0] + 1, i[1] + 1, i[2] + 1, i[3] + 1))
            force_constants.append(i[4])
            equilibrium_angles.append(i[5])
            periodicities.append(i[6])
            comments.append(i[-1])

        for i in range(len(ids)):
            self.impropers[ids[i]] = {'fc': force_constants[i], 'eq': equilibrium_angles[i], 'periodicity': periodicities[i], 'comment': comments[i]}

        # Pairs
            
        self.pairs = {}

        ids = []

        for i in topology['pairs']:
            ids.append((i[0] + 1, i[1] + 1))

        for i in range(len(ids)):
            self.pairs[ids[i]] = {}

    def reparameterize(self,
                       hessian_matrix=None,
                       origin='XTB',
                       keys=None,
                       element=None,
                       print_all=False,
                       only_eq=False,
                       no_repar=False,
                       repar_imp=False):
        """
        Reparameterizes all unknown parameters with the seminario method using the given hessian

        :param heassian_matrix:
            Hessian matrix, if origin is 'Other' this must be provided. 2D numpy array.
        :param origin:
            Origin of the hessian file, can be 'Other' or 'XTB'
        :param keys:
            List of tuples with the atom indices of the parameters to be reparameterized
        :param element:
            Element to be reparameterized
        :param print_all:
            Print all the parameters, not only the ones that are going to be reparameterized
        :param only_eq:
            Only reparameterize the equilibrium values
        :param no_repar:
            Do not reparameterize the force-field, only print the parameters
        :param repar_imp:
            Reparameterize the improper parameters. Experimental.

        """
        from .seminario import Seminario
        from .xtbdriver import XtbDriver
        from .xtbhessiandriver import XtbHessianDriver
        from .xtbgradientdriver import XtbGradientDriver
        from .optimizationdriver import OptimizationDriver

        print("""

VeloxChem Force-Field Reparameterization
Based on the Seminario method
------------------------------------------------------------------------------------------
Reference:
J. M. Seminario (1996) Calculation of intramolecular force fields from second-derivative tensors. 
Internat. J. Quant. Chem. 60:1271-1277

Disclaimer: Dihedral and improper parameters are not reparameterized with this method.
Consider scanning manually sensitive diherals and impropers.

        """)

        A_to_nm = 0.1  #1 angstrom is 0.1 nm
        Bohr_to_nm = bohr_in_angstrom() * A_to_nm
        cal_to_joule = 4.184  #1 calorie is 4.184 joule
        Hartree_to_kJmol = hartree_in_kcalpermol() * cal_to_joule

        if (type(keys) == tuple):
            keys = [keys]

        # Generate the hessian matrix depending on the origin

        if origin == 'Other':
            # The hessian must be directly provided as a numpy array
            hessian = hessian_matrix
        elif origin == 'XTB':
            # XTB optimization of the molecule before computing the hessian
            xtb_drv = XtbDriver()
            method_settings = {'xtb': 'gfn2'}
            xtb_drv.set_method(method_settings['xtb'].lower())
            xtb_grad_drv = XtbGradientDriver()
            xtb_grad_drv.ostream.mute()
            xtb_opt_drv = OptimizationDriver(xtb_grad_drv)
            xtb_opt_drv.ostream.mute()
            print("Optimizing the molecule with XTB...")
            self.molecule = xtb_opt_drv.compute(self.molecule, xtb_drv)
            print('Molecule optimized')
            # XTB hessian
            xtb_hessian = XtbHessianDriver()
            xtb_hessian.ostream.mute()
            print("Computing the hessian with XTB")
            xtb_hessian.compute(self.molecule, xtb_drv)
            self.hessian = xtb_hessian.hessian
            print("""
                  
Hessian computed with the XTB method
------------------------------------------------------------------------------------------------
C. Bannwarth, E. Caldeweyher, S. Ehlert, A. Hansen, P. Pracht, J. Seibert, S. Spicher, S. Grimme 
WIres Comput. Mol. Sci., 2020, 11, e01493. DOI: 10.1002/wcms.1493
                  
                  """)
            
        # Method pending to be implemented. Waiting for the VeloxChem hessian.
        elif origin == 'VeloxChem':
            print("Method yet not implemented, please use the XTB driver")
            return
        else:
            raise Exception(
                "Please specify the origin of the hessian as 'Other' or 'XTB'")

        coordinates = self.molecule.get_coordinates_in_bohr(
        )  #Coordinates in Bohr
        
        sem = Seminario(self.hessian, coordinates)

        def process_parameter(parameters, label):
            for ids in parameters.keys():
                eq = parameters[ids]["eq"]
                fc = parameters[ids]["fc"]

                if label == "bond":
                    neweq = AtomTypeIdentifier.measure_length(
                        coordinates[ids[0] - 1], coordinates[ids[1] - 1])
                    neweq *= Bohr_to_nm  #Convert to nm

                    newfc = sem.bond_fc(ids[0] - 1, ids[1] - 1)  #fc in H/Bohr^2
                    newfc *= Hartree_to_kJmol / (Bohr_to_nm**2
                                                )  #Convert to kJ/mol nm^2
                elif label == "angle":
                    neweq = AtomTypeIdentifier.measure_angle(
                        coordinates[ids[0] - 1], coordinates[ids[1] - 1],
                        coordinates[ids[2] - 1])
                    newfc = sem.angle_fc(ids[0] - 1, ids[1] - 1, ids[2] -
                                         1)  #Returns in H/rad^2 i think
                    newfc *= Hartree_to_kJmol  #Convert to kJmol^-1/rad^2
                elif label == "dihedral":
                    perio = self.dihedrals[ids]["periodicity"]
                elif label == "improper":
                    perio = self.impropers[ids]["periodicity"]
                    if repar_imp:
                        neweq = AtomTypeIdentifier.measure_dihedral(
                            coordinates[ids[0] - 1], coordinates[ids[1] - 1],
                            coordinates[ids[2] - 1], coordinates[ids[3] - 1])
                        newfc = sem.dihed_fc(
                            ids[0] - 1,
                            ids[1] - 1,
                            ids[2] - 1,
                            ids[3] - 1,
                            avg_improper=True)  #Returns in H/rad^2 i think
                        newfc *= Hartree_to_kJmol  #Convert to kJmol^-1/rad^2
                    else:
                        neweq = 0
                        newfc = 0

                comment = parameters[ids]["comment"]  #GAFF2 or unknown

                repar = False
                if no_repar:
                    ""
                elif keys is not None:
                    if ids in keys:
                        repar = True
                elif keys is None and element is not None:
                    for id in ids:
                        if element == self.molecule.get_labels()[id - 1]:
                            repar = True
                elif keys is None and element is None and 'Unknown' in comment:
                    repar = True

                if repar:
                    if label == "dihedral" and not repar_imp:
                        comment += ", not reparameterizing dihedrals"
                    elif not label == "dihedral":
                        parameters[ids]["eq"] = neweq
                        if not only_eq:
                            parameters[ids]["fc"] = newfc
                            comment += f", reparameterized from (eq,fc)=({eq:>.1f},{fc:.1f}) to (eq,fc)=({neweq:.1f},{newfc:.1f})"
                        else:
                            comment += f", reparameterized from eq={eq:>.1f} to eq={neweq:.1f}"
                        parameters[ids]["comment"] = comment

                        if label == "improper":
                            parameters[ids]["type"] = 2
                            parameters[ids]["periodicity"] = ""
                    else:
                        comment += ", reparameterization of proper dihedrals should be done with other method"

                if repar or print_all:
                    if label == "bond":
                        print(
                            f"{f'{ids}:':<{10}}\t{eq:>6f}\t{fc:>6f}\t\t{neweq:>6f}\t{newfc:>6f}\t\t{comment}"
                        )
                    if label == "angle":
                        print(
                            f"{f'{ids}:':<{15}}\t{eq:>6f}\t{fc:>6f}\t\t{neweq:>6f}\t{newfc:>6f}\t\t{comment}"
                        )
                    if label == "dihedral":
                        print(
                            f"{f'{ids}: ':<{20}}{eq:>6f}\t{fc:>6f}\t\t{abs(perio)}\t\t{comment}"
                        )
                    if label == "improper":
                        print(
                            f"{f'{ids}: ':<{20}}{eq:>6f}\t{fc:>6f}\t\t{perio}\t\t{neweq:.<3f}\t{newfc:.<3f}\t\t{perio}\t\t{comment}"
                        )

        print(
            "Bond \t\tr0(nm) \t\tfc(kJmol^-1/nm^2) \tNew r0(nm) \tNew fc(kJmol^-1/nm^2) \tComment"
        )
        process_parameter(self.bonds, "bond")

        print(
            "\nAngle \t\ttheta0(deg)  \tfc(kJmol^-1/rad^2) \tNew theta0(deg)\tNew fc(kJmol^-1/rad^2) \tComment"
        )
        process_parameter(self.angles, "angle")

        print("\nDihedrals\t\teq(deg)  \tfc(kJmol^-1) \tPeriodicity \tComment")
        process_parameter(self.dihedrals, "dihedral")

        print(
            "\nImpropers\t\teq(deg)  \tfc(kJmol^-1/rad^2?) \tperiodicity \tNew eq(deg) \tNew fc(kJmol^-1/rad^2?)\tNew periodicity\tComment"
        )
        process_parameter(self.impropers, "improper")


    def write_top_file(self, top_file):
        '''
        Writes top file.
        '''
        # Will use the information contained in the dictionary self.topology
        # to write the GROMACS top file.

        top_fname = top_file if isinstance(top_file, str) else str(top_file)

        mol_name = Path(self.molecule_name).stem

        with open(top_fname, 'w') as f_top:
                
                # header
    
                f_top.write('; Generated by VeloxChem\n')
    
                # defaults
    
                f_top.write('\n[ defaults ]\n')
                cur_str = '; nbfunc        comb-rule       gen-pairs'
                cur_str += '       fudgeLJ fudgeQQ\n'
                f_top.write(cur_str)
                gen_pairs = 'yes' if self.gen_pairs else 'no'
                f_top.write('{}{:16}{:>18}{:19.4f}{:8.4f}\n'.format(
                    self.nbfunc, self.comb_rule, gen_pairs, self.fudgeLJ,
                    self.fudgeQQ))
    
                # include itp
    
                f_top.write('\n#include "' + Path(self.molecule_name).name + '.itp"\n')
    
                # system
    
                f_top.write('\n[ system ]\n')
                f_top.write(' {}\n'.format(mol_name))
    
                # molecules
    
                f_top.write('\n[ molecules ]\n')
                f_top.write('; Compound        nmols\n')
                f_top.write('{:>10}{:9}\n'.format(mol_name, 1))



    def write_original_itp(self, itp_file, atom_types, charges):
        """
        Writes an itp file with the original parameters.

        :param itp_file:
            The itp file.
        :param atom_types:
            The atom types.
        :param charges:
            The charges.
        """

        itp_fname = itp_file if isinstance(itp_file, str) else str(itp_file)

        mol_name = Path(self.molecule_name).stem

        # molecular information

        coords = self.molecule.get_coordinates_in_bohr()
        n_atoms = self.molecule.number_of_atoms()

        atomtypeidentifier = AtomTypeIdentifier()
        atomtypeidentifier.ostream.mute()
        atom_types = atomtypeidentifier.generate_gaff_atomtypes(self.molecule)
        self.connectivity_matrix = np.copy(atomtypeidentifier.self.connectivity_matrix)

        # preparing atom types and atom names

        assert_msg_critical(
            len(atom_types) == n_atoms,
            'ForceFieldGenerator: inconsistent atom_types')

        for i in range(n_atoms):
            atom_types[i] = f'{atom_types[i].strip():<2s}'
        unique_atom_types = list(set(atom_types))

        atom_names = self.get_atom_names()

        # preparing 1-4 pairs

        bond_indices = set()
        for i in range(n_atoms):
            for j in range(i + 1, n_atoms):
                if self.connectivity_matrix[i, j] == 1:
                    bond_indices.add((i, j))
        bond_indices = sorted(list(bond_indices))

        angle_indices = set()
        for i, j in bond_indices:
            for k in range(n_atoms):
                if k in [i, j]:
                    continue
                if self.connectivity_matrix[j, k] == 1:
                    inds = (i, j, k) if i < k else (k, j, i)
                    angle_indices.add(inds)
                if self.connectivity_matrix[k, i] == 1:
                    inds = (k, i, j) if k < j else (j, i, k)
                    angle_indices.add(inds)
        angle_indices = sorted(list(angle_indices))

        dihedral_indices = set()
        for i, j, k in angle_indices:
            for l in range(n_atoms):
                if l in [i, j, k]:
                    continue
                if self.connectivity_matrix[k, l] == 1:
                    inds = (i, j, k, l) if i < l else (l, k, j, i)
                    dihedral_indices.add(inds)
                if self.connectivity_matrix[l, i] == 1:
                    inds = (l, i, j, k) if l < k else (k, j, i, l)
                    dihedral_indices.add(inds)
        dihedral_indices = sorted(list(dihedral_indices))

        exclusion_indices = []
        if self.nrexcl >= 2:
            for i, j in bond_indices:
                exclusion_indices.append((i, j))
        if self.nrexcl >= 3:
            for i, j, k in angle_indices:
                exclusion_indices.append((i, k))

        pairs_14 = set()
        for i, j, k, l in dihedral_indices:
            if (i, l) not in exclusion_indices:
                pairs_14.add((i, l))
        pairs_14 = sorted(list(pairs_14))

        if self.force_field_data is None:
            ff_data_lines = self.get_gaff_data_lines()
        else:
            with open(self.force_field_data, 'r') as ff_data:
                ff_data_lines = ff_data.readlines()

        if (self.force_field_data_extension is not None and
                Path(self.force_field_data_extension).is_file()):
            with open(self.force_field_data_extension, 'r') as ff_extension:
                ff_data_lines += ff_extension.readlines()

        with open(itp_fname, 'w') as f_itp:

            # header

            f_itp.write('; Generated by VeloxChem\n')

            # atom types

            f_itp.write('\n[ atomtypes ]\n')
            cur_str = ';name   bond_type     mass     charge'
            cur_str += '   ptype   sigma         epsilon\n'
            f_itp.write(cur_str)

            for at in unique_atom_types:
                atom_type_found = False

                for line in ff_data_lines:
                    if line.startswith(f'  {at}     '):
                        cur_str = '{:>3}{:>9}{:17.5f}{:9.5f}{:>4}'.format(
                            at, at, 0., 0., 'A')
                        cur_str += '{:16.5e}{:14.5e}\n'.format(
                            float(line.split()[1]) * 2**(-1 / 6) * 2 / 10,
                            float(line.split()[2]) * 4.184)
                        f_itp.write(cur_str)
                        atom_type_found = True
                        break

                assert_msg_critical(
                    atom_type_found,
                    f'ForceFieldGenerator: Unknown atom type {at}')

            # molecule type

            f_itp.write('\n[ moleculetype ]\n')
            f_itp.write(';name            nrexcl\n')
            f_itp.write('{:>10}{:10}\n'.format(mol_name, self.nrexcl))

            # atoms

            f_itp.write('\n[ atoms ]\n')
            cur_str = ';   nr  type  resi  res  atom  cgnr'
            cur_str += '     charge      mass\n'
            f_itp.write(cur_str)

            for i, at in enumerate(atom_types):
                for line in ff_data_lines:
                    if line.startswith(f'{at} '):
                        mass_i = float(line.split()[1])
                        cur_str = '{:6}{:>5}{:6}{:>6}{:>6}'.format(
                            i + 1, atom_types[i], 1, 'RES', atom_names[i])
                        cur_str += '{:5}{:13.6f}{:13.5f}\n'.format(
                            i + 1, charges[i], mass_i)
                        f_itp.write(cur_str)

            # bonds

            f_itp.write('\n[ bonds ]\n')
            f_itp.write(';    i      j    funct       r           k_r\n')

            for i, j in bond_indices:
                r_eq = np.linalg.norm(coords[i] - coords[j])
                r_eq *= bohr_in_angstrom() * 0.1

                at_1 = atom_types[i]
                at_2 = atom_types[j]
                patterns = [
                    re.compile(r'\A' + f'{at_1}-{at_2}  '),
                    re.compile(r'\A' + f'{at_2}-{at_1}  '),
                ]

                bond_found = False

                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        bond_ff = line[5:].strip().split()
                        r = float(bond_ff[1]) * 0.1
                        k_r = float(bond_ff[0]) * 4.184 * 2 * 100
                        bond_found = True
                        break

                errmsg = f'ForceFieldGenerator: bond {at_1}-{at_2}'
                errmsg += ' is not available'
                assert_msg_critical(bond_found, errmsg)

                if self.eq_param:
                    if abs(r - r_eq) > self.r_thresh:
                        msg = f'Updated bond length {i+1}-{j+1} '
                        msg += f'({at_1}-{at_2}) to {r_eq:.3f} nm'
                        self.ostream.print_info(msg)
                        self.ostream.flush()
                    r = r_eq

                cur_str = '{:6}{:7}{:7}{:14.4e}{:14.4e} ; {}-{}\n'.format(
                    i + 1, j + 1, 1, r, k_r, atom_names[i], atom_names[j])
                f_itp.write(cur_str)

            # pairs

            f_itp.write('\n[ pairs ]\n')
            f_itp.write(';    i      j    funct\n')
            for i, j in pairs_14:
                f_itp.write('{:6}{:7}{:7}\n'.format(i + 1, j + 1, 1))

            # angles

            f_itp.write('\n[ angles ]\n')
            cur_str = ';    i      j      k    funct'
            cur_str += '     theta       k_theta\n'
            f_itp.write(cur_str)

            for i, j, k in angle_indices:
                a = coords[i] - coords[j]
                b = coords[k] - coords[j]
                theta_eq = np.arccos(
                    np.dot(a, b) / np.linalg.norm(a) /
                    np.linalg.norm(b)) * 180 / np.pi

                at_1 = atom_types[i]
                at_2 = atom_types[j]
                at_3 = atom_types[k]
                patterns = [
                    re.compile(r'\A' + f'{at_1}-{at_2}-{at_3} '),
                    re.compile(r'\A' + f'{at_3}-{at_2}-{at_1} '),
                ]

                angle_found = False

                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        angle_ff = line[8:].strip().split()
                        theta = float(angle_ff[1])
                        k_theta = float(angle_ff[0]) * 4.184 * 2
                        angle_found = True

                errmsg = f'ForceFieldGenerator: angle {at_1}-{at_2}-{at_3}'
                errmsg += ' is not available.'
                assert_msg_critical(angle_found, errmsg)

                if self.eq_param:
                    if abs(theta - theta_eq) > self.theta_thresh:
                        msg = f'Updated bond angle {i+1}-{j+1}-{k+1} '
                        msg += f'({at_1}-{at_2}-{at_3}) to {theta_eq:.1f} deg'
                        self.ostream.print_info(msg)
                        self.ostream.flush()
                    theta = theta_eq

                cur_str = '{:6}{:7}{:7}{:7}{:14.4e}{:14.4e}'.format(
                    i + 1, j + 1, k + 1, 1, theta, k_theta)
                cur_str += ' ; {}-{}-{}\n'.format(atom_names[i], atom_names[j],
                                                  atom_names[k])
                f_itp.write(cur_str)

            # dihedrals

            f_itp.write('\n[ dihedrals ]\n')

            cur_str = ';    i      j      k      l    funct'
            cur_str += '    phase     k_d      n\n'
            f_itp.write(cur_str)

            cur_str = ';                                   '
            cur_str += '     C0         C1         C2         C3'
            cur_str += '         C4         C5\n'
            f_itp.write(cur_str)

            # proper dihedrals

            f_itp.write('; propers\n')

            for i, j, k, l in dihedral_indices:
                at_1 = atom_types[i]
                at_2 = atom_types[j]
                at_3 = atom_types[k]
                at_4 = atom_types[l]
                patterns = [
                    re.compile(r'\A' + f'{at_1}-{at_2}-{at_3}-{at_4} '),
                    re.compile(r'\A' + f'{at_4}-{at_3}-{at_2}-{at_1} '),
                ]

                dihedral_found = False

                dihedral_ff_lines = []
                for line in ff_data_lines:
                    matches = [re.search(p, line) for p in patterns]
                    if any(matches):
                        dihedral_ff = line[11:60].strip().split()
                        if len(dihedral_ff) == 4:
                            dihedral_ff_lines.append(line)
                            dihedral_found = True

                if not dihedral_found:
                    patterns = [
                        re.compile(r'\A' + f'X -{at_2}-{at_3}-X  '),
                        re.compile(r'\A' + f'X -{at_3}-{at_2}-X  '),
                    ]

                    dihedral_ff_lines = []
                    for line in ff_data_lines:
                        matches = [re.search(p, line) for p in patterns]
                        if any(matches):
                            dihedral_ff = line[11:60].strip().split()
                            if len(dihedral_ff) == 4:
                                dihedral_ff_lines.append(line)
                                dihedral_found = True

                errmsg = 'ForceFieldGenerator: proper dihedral'
                errmsg += f' {at_1}-{at_2}-{at_3}-{at_4} is not available.'
                assert_msg_critical(dihedral_found, errmsg)

                for line in dihedral_ff_lines:
                    dihedral_ff = line[11:60].strip().split()

                    multiplicity = int(dihedral_ff[0])
                    barrier = float(dihedral_ff[1]) * 4.184 / multiplicity
                    phase = float(dihedral_ff[2])
                    # Note: negative periodicity implies multitermed dihedral
                    # See https://ambermd.org/FileFormats.php
                    try:
                        periodicity = int(dihedral_ff[3])
                    except ValueError:
                        periodicity = int(float(dihedral_ff[3]))

                    cur_str = '{:6}{:7}{:7}{:7}'.format(i + 1, j + 1, k + 1,
                                                        l + 1)
                    cur_str += '{:7}{:11.2f}{:11.5f}{:4}'.format(
                        9, phase, barrier, abs(periodicity))
                    cur_str += ' ; {}-{}-{}-{}\n'.format(
                        atom_names[i], atom_names[j], atom_names[k],
                        atom_names[l])
                    f_itp.write(cur_str)

                    if periodicity > 0:
                        break

            # improper dihedrals

            sp2_atom_types = [
                'c ', 'cs', 'c2', 'ca', 'cp', 'cq', 'cc', 'cd', 'ce', 'cf',
                'cu', 'cv', 'cz', 'n ', 'n2', 'na', 'nb', 'nc', 'nd', 'ne',
                'nf', 'pb', 'pc', 'pd', 'pe', 'pf'
            ]

            f_itp.write('; impropers\n')

            improper_atom_inds = []

            for i, j, k in angle_indices:
                at_1 = atom_types[i]
                at_2 = atom_types[j]
                at_3 = atom_types[k]

                if at_2 not in sp2_atom_types:
                    continue

                if j not in improper_atom_inds:
                    improper_atom_inds.append(j)
                else:
                    continue

                for l in range(n_atoms):
                    if (l in [i, j, k]) or (self.connectivity_matrix[l, j] != 1):
                        continue
                    at_4 = atom_types[l]

                    patterns = [
                        re.compile(r'\A' + f'{at_4}-{at_1}-{at_2}-{at_3} '),
                        re.compile(r'\A' + f'{at_4}-{at_3}-{at_2}-{at_1} '),
                        re.compile(r'\A' + f'{at_1}-{at_3}-{at_2}-{at_4} '),
                        re.compile(r'\A' + f'{at_1}-{at_4}-{at_2}-{at_3} '),
                        re.compile(r'\A' + f'{at_3}-{at_1}-{at_2}-{at_4} '),
                        re.compile(r'\A' + f'{at_3}-{at_4}-{at_2}-{at_1} '),
                    ]

                    dihedral_found = False

                    for line in ff_data_lines:
                        matches = [re.search(p, line) for p in patterns]
                        if any(matches):
                            dihedral_ff = line[11:60].strip().split()
                            if len(dihedral_ff) == 3:
                                dihedral_found = True
                                break

                    if not dihedral_found:
                        patterns = [
                            re.compile(r'\A' + f'X -{at_1}-{at_2}-{at_3} '),
                            re.compile(r'\A' + f'X -{at_3}-{at_2}-{at_1} '),
                            re.compile(r'\A' + f'X -{at_3}-{at_2}-{at_4} '),
                            re.compile(r'\A' + f'X -{at_4}-{at_2}-{at_3} '),
                            re.compile(r'\A' + f'X -{at_1}-{at_2}-{at_4} '),
                            re.compile(r'\A' + f'X -{at_4}-{at_2}-{at_1} '),
                        ]

                        for line in ff_data_lines:
                            matches = [re.search(p, line) for p in patterns]
                            if any(matches):
                                dihedral_ff = line[11:60].strip().split()
                                if len(dihedral_ff) == 3:
                                    dihedral_found = True
                                    break

                    if not dihedral_found:
                        patterns = [
                            re.compile(r'\A' + f'X -X -{at_2}-{at_3} '),
                            re.compile(r'\A' + f'X -X -{at_2}-{at_1} '),
                            re.compile(r'\A' + f'X -X -{at_2}-{at_4} '),
                        ]

                        for line in ff_data_lines:
                            matches = [re.search(p, line) for p in patterns]
                            if any(matches):
                                dihedral_ff = line[11:60].strip().split()
                                if len(dihedral_ff) == 3:
                                    dihedral_found = True
                                    break

                    errmsg = 'ForceFieldGenerator: improper dihedral'
                    errmsg += f' {at_4}-{at_3}-{at_2}-{at_1} is not available.'
                    assert_msg_critical(dihedral_found, errmsg)

                    barrier = float(dihedral_ff[0]) * 4.184
                    phase = float(dihedral_ff[1])
                    periodicity = abs(int(float(dihedral_ff[2])))

                    assert_msg_critical(
                        phase == 180.0,
                        'ForceFieldGenerator: invalid improper dihedral phase')
                    assert_msg_critical(
                        periodicity == 2,
                        'ForceFieldGenerator: invalid improper dihedral periodicity'
                    )

                    cur_str = '{:6}{:7}{:7}{:7}'.format(l + 1, i + 1, j + 1,
                                                        k + 1)
                    cur_str += '{:7}{:11.2f}{:11.5f}{:4}'.format(
                        4, phase, barrier, periodicity)
                    cur_str += ' ; {}-{}-{}-{}\n'.format(
                        atom_names[l], atom_names[i], atom_names[j],
                        atom_names[k])
                    f_itp.write(cur_str)

    @staticmethod
    def copy_file(src, dest):
        """
        Copies file (from src to dest).

        :param src:
            The source of copy.
        :param dest:
            The destination of copy.
        """

        if (not dest.is_file()) or (not src.samefile(dest)):
            if not dest.parent.is_dir():
                dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_text(src.read_text())

    def dihedral_correction(self, top_file, i, kT=None):
        """
        Corrects dihedral parameters.

        :param top_filename:
            The topology file.
        :param i:
            The index of the target dihedral.
        :param kT:
            kT for Boltzmann factor (used in weighted fitting).
        """

        try:
            from scipy.optimize import curve_fit
        except ImportError:
            raise ImportError('Unable to import scipy. Please install scipy ' +
                              'via pip or conda.')

        # Ryckaert-Bellemans function

        def rbpot(phi, c0, c1, c2, c3, c4, c5):
            v = c0 + c1 * np.cos((180 - phi) * 2 * np.pi / 360)
            v += c2 * np.cos((180 - phi) * 2 * np.pi / 360)**2
            v += c3 * np.cos((180 - phi) * 2 * np.pi / 360)**3
            v += c4 * np.cos((180 - phi) * 2 * np.pi / 360)**4
            v += c5 * np.cos((180 - phi) * 2 * np.pi / 360)**5
            return v

        top_fname = top_file if isinstance(top_file, str) else str(top_file)

        if self.rank == mpi_master():
            itp_fname = self.get_included_file(top_fname)
        else:
            itp_fname = None
        itp_fname = self.comm.bcast(itp_fname, root=mpi_master())

        mol_name = Path(self.molecule_name).stem

        workdir = Path('.') if self._workdir is None else self._workdir

        self.ffversion += 1
        new_itp_fname = str(workdir / f'{mol_name}_{self.ffversion:02d}.itp')
        new_top_fname = str(workdir / f'{mol_name}_{self.ffversion:02d}.top')

        if itp_fname != new_itp_fname:
            if self.rank == mpi_master():
                self.copy_file(Path(itp_fname), Path(new_itp_fname))
                self.write_top(new_top_fname, new_itp_fname)
            self.comm.barrier()

        dih = self.target_dihedrals[i]
        geom = self.scan_geometries[i]
        qm_scan = self.scan_energies[i]
        angles = self.scan_dih_angles[i]

        self.ostream.print_info('Fitting dihedral angle ' +
                                '{}-{}-{}-{}'.format(*dih) + '...')
        self.ostream.flush()

        # MM scan with dihedral parameters set to zero

        output_dir = workdir / f'{mol_name}_dih_corr' / f'{i+1}'
        zero_itp_file = output_dir / f'{mol_name}_zero.itp'
        zero_top_file = output_dir / f'{mol_name}_zero.top'

        if self.rank == mpi_master():
            output_dir.mkdir(parents=True, exist_ok=True)
            self.copy_file(Path(new_itp_fname), zero_itp_file)
            self.write_top(zero_top_file, zero_itp_file)
            self.set_dihedral_parameters(zero_itp_file, dih, [0.] * 6)
        self.comm.barrier()

        mm_zero_scan = self.perform_mm_scan(zero_top_file,
                                            dih,
                                            geom,
                                            angles,
                                            print_energies=False)

        # fitting Ryckaert-Bellemans function

        if self.rank == mpi_master():
            rel_e_qm = np.array(qm_scan) - min(qm_scan)
            rel_e_qm *= hartree_in_kcalpermol() * 4.184
            rel_e_mm = np.array(mm_zero_scan) - min(mm_zero_scan)

            difference = rel_e_qm - rel_e_mm
            initial_coef = tuple([0.] * 6)

            if kT is not None:
                sigma = 1.0 / np.exp(-rel_e_qm / kT)
                coef, cv = curve_fit(rbpot,
                                     angles,
                                     difference,
                                     initial_coef,
                                     sigma,
                                     absolute_sigma=False)
            else:
                coef, cv = curve_fit(rbpot, angles, difference, initial_coef)

            self.set_dihedral_parameters(new_itp_fname, dih, coef.tolist())
        self.comm.barrier()

        self.ostream.print_info('...done.')
        self.ostream.print_blank()
        self.ostream.print_info(
            f'Generated new topology file: {Path(new_top_fname).name}')
        self.ostream.print_blank()
        self.ostream.flush()

        return Path(new_top_fname)

    def validate_force_field(self, top_file, i):
        """
        Validates force field by RMSD of dihedral potentials.

        :param top_file:
            The topology file.
        :param i:
            The index of the target dihedral.

        :return:
            A dictionary containing the results of validation.
        """

        self.ostream.print_info(f'Validating {top_file.name} ...')
        self.ostream.print_blank()
        self.ostream.flush()

        dih = self.target_dihedrals[i]

        self.ostream.print_info(
            '  Target dihedral angle: {}-{}-{}-{}'.format(*dih))
        self.ostream.print_blank()

        geom = self.scan_geometries[i]
        angles = self.scan_dih_angles[i]
        mm_scan = self.perform_mm_scan(top_file, dih, geom, angles)
        mm_scan = np.array(mm_scan) - min(mm_scan)

        qm_scan = np.array(self.scan_energies[i]) - min(self.scan_energies[i])
        qm_scan *= hartree_in_kcalpermol() * 4.184

        self.ostream.print_blank()
        self.ostream.print_info(
            '      Dihedral      MM energy(rel)      QM energy(rel)       diff')
        self.ostream.print_info(
            '  ---------------------------------------------------------------')
        for angle, e_mm, e_qm in zip(angles, mm_scan, qm_scan):
            self.ostream.print_info(
                f'  {angle:8.1f} deg {e_mm:12.3f} kJ/mol {e_qm:12.3f} kJ/mol ' +
                f'{(e_mm - e_qm):10.3f}')
        self.ostream.print_blank()
        self.ostream.flush()

        return {
            'dihedral_indices': list(dih),
            'dihedral_angles': list(angles),
            'mm_scan_kJpermol': mm_scan.copy(),
            'qm_scan_kJpermol': qm_scan.copy(),
        }

    def perform_mm_scan(self,
                        top_file,
                        dihedral,
                        geometries,
                        angles,
                        print_energies=True):
        """
        Performs MM scan of a specific dihedral.

        :param top_file:
            The topology file.
        :param dihedral:
            The dihedral.
        :param geometries:
            The scanned geometris for this dihedral.
        :param angles:
            The scanned angles for this dihedral.
        """

        # select scan angles and geometries from QM data

        top_fname = top_file if isinstance(top_file, str) else str(top_file)

        if self.rank == mpi_master():
            itp_fname = self.get_included_file(top_fname)
        else:
            itp_fname = None
        itp_fname = self.comm.bcast(itp_fname, root=mpi_master())

        top_file = Path(top_fname)

        scan_dir = top_file.parent / (top_file.stem + '_scan')
        if self.rank == mpi_master():
            scan_dir.mkdir(parents=True, exist_ok=True)
        self.comm.barrier()

        if print_energies:
            self.ostream.print_info('      Dihedral           MM energy')
            self.ostream.print_info('  --------------------------------')
            self.ostream.flush()

        energies = []
        for i, (geom, angle) in enumerate(zip(geometries, angles)):

            output_dir = scan_dir / f'{i+1}'
            local_itp_fname = str(output_dir / f'{i+1}.itp')
            local_top_fname = str(output_dir / f'{i+1}.top')

            if self.rank == mpi_master():
                output_dir.mkdir(parents=True, exist_ok=True)
                self.copy_file(Path(itp_fname), Path(local_itp_fname))
                self.write_top(local_top_fname, local_itp_fname)
            self.comm.barrier()

            # energy minimization with dihedral constraint
            constraints = ['$set']
            constraints += ['dihedral {} {} {} {} {}'.format(*dihedral, angle)]
            pot_energy = self.minimize_mm_energy(geom, local_top_fname,
                                                 constraints)
            # convert to kJ/mol
            pot_energy *= 4.184 * hartree_in_kcalpermol()
            energies.append(pot_energy)

            if print_energies:
                self.ostream.print_info(
                    f'  {angle:8.1f} deg {pot_energy:12.3f} kJ/mol')
                self.ostream.flush()

        return energies

    def minimize_mm_energy(self, molecule, top_file, constraints):
        """
        Minimizes MM energy of a topology using OpenMM.

        :param molecule:
            The molecule.
        :param top_file:
            The topology.
        :param constraints:
            The constraints.
        """

        openmm_drv = OpenMMDriver(self.comm)
        openmm_drv.add_topology(top_file, self.gromacs_include_path)

        grad_drv = OpenMMGradientDriver(self.comm)
        grad_drv.ostream.mute()

        opt_drv = OptimizationDriver(grad_drv)
        opt_drv.update_settings({
            'constraints': constraints,
            'filename': str(Path(top_file).parent / Path(top_file).stem),
            'keep_files': self.keep_files,
        })
        final_mol = opt_drv.compute(molecule, openmm_drv)

        openmm_drv.compute(final_mol)

        return openmm_drv.get_energy()

    def set_dihedral_parameters(self, itp_file, dihedral, coefficients):
        """
        Sets dihedral parameters of topology.

        :param itp_file:
            The internal topology file.
        :param dihedral:
            The dihedral.
        :param coefficients:
            The coefficients for Ryckaert-Bellemans funciton.
        """

        itp_fname = itp_file if isinstance(itp_file, str) else str(itp_file)

        atom_names = self.get_atom_names()

        # read itp file and remove existing parameters for chosen dihedral

        dihedral_flag = False
        dihedral_pattern = re.compile(r'\[\s*dihedrals\s*\]')
        saved_itp_lines = []

        added_dih_str = False
        dih_str = '{:6}{:7}{:7}{:7}{:7}'.format(*dihedral, 3)
        for coef in coefficients:
            dih_str += '{:11.5f}'.format(coef)
        dih_str += ' ; {}-{}-{}-{}\n'.format(atom_names[dihedral[0] - 1],
                                             atom_names[dihedral[1] - 1],
                                             atom_names[dihedral[2] - 1],
                                             atom_names[dihedral[3] - 1])

        with open(itp_fname, 'r') as f_itp:
            for line in f_itp:
                title = line.split(';')[0].strip()

                if title.startswith('['):
                    if re.search(dihedral_pattern, title):
                        dihedral_flag = True
                    else:
                        dihedral_flag = False

                if dihedral_flag:
                    content = line.split()
                    try:
                        i, j, k, l, funct = tuple(
                            [int(content[n]) for n in range(5)])
                        condition_1 = (funct in [1, 3, 9])
                        condition_2 = ([i, j, k, l] == dihedral or
                                       [l, k, j, i] == dihedral or
                                       [j, k] == dihedral[1:3] or
                                       [k, j] == dihedral[1:3])
                        if condition_1 and condition_2:
                            if not added_dih_str:
                                saved_itp_lines.append(dih_str)
                                added_dih_str = True
                        else:
                            saved_itp_lines.append(line)
                    except (ValueError, IndexError):
                        saved_itp_lines.append(line)
                else:
                    saved_itp_lines.append(line)

        # update itp file with constraints for chosen dihedral

        with open(itp_fname, 'w') as f_itp:
            for line in saved_itp_lines:
                f_itp.write(line)

    def visualize(self, validation_result):
        """
        Visualizes dihedral potential.

        :param validation_result:
            The dictionary containing the result of validation.
        """

        try:
            import matplotlib.pyplot as plt
        except ImportError:
            raise ImportError('Unable to import Matplotlib. Please install ' +
                              'Matplotlib via \'conda install matplotlib\'')

        qm_scan_kJpermol = validation_result['qm_scan_kJpermol']
        mm_scan_kJpermol = validation_result['mm_scan_kJpermol']
        dihedral_angles = validation_result['dihedral_angles']
        dihedral_indices = validation_result['dihedral_indices']

        plt.plot(dihedral_angles, qm_scan_kJpermol, '-o', label="QM")
        plt.plot(dihedral_angles, mm_scan_kJpermol, '-o', label="MM")

        plt.grid()
        plt.legend(loc='upper right')
        plt.xlabel('dihedral angle {}-{}-{}-{}'.format(*dihedral_indices))
        plt.ylabel('E in kJ/mol')
        plt.title('dihedral potential of {}'.format(self.molecule_name))
        plt.show()

    def get_connectivity(self):
        """
        Gets connectivity.

        :return:
            A 2d array containing the connectivity information of the molecule.
        """

        coords = self.molecule.get_coordinates_in_bohr()
        n_atoms = self.molecule.number_of_atoms()
        covalent_radii = self.molecule.covalent_radii_to_numpy()

        connectivity = np.full((n_atoms, n_atoms), False, dtype='bool')
        tolerance = 0.4 / bohr_in_angstrom()
        for i in range(n_atoms):
            for j in range(i + 1, n_atoms):
                r_ij = np.linalg.norm(coords[i] - coords[j])
                if abs(r_ij - covalent_radii[i] -
                       covalent_radii[j]) < tolerance:
                    connectivity[i, j] = True
                    connectivity[j, i] = True

        return connectivity

    def get_included_file(self, top_fname):
        """
        Gets the name of the included itp file.

        :param top_fname:
            The topology file.
        """

        itp_file = None

        with open(top_fname, 'r') as top:
            pattern = re.compile(r'\A#include')
            for line in top:
                if re.search(pattern, line):
                    itp_file = Path(top_fname).parent / line.split('"')[1]

        assert_msg_critical(
            itp_file is not None,
            'ForceFieldGenerator.get_included_file: could not find ' +
            'included file')

        return str(itp_file)

    def get_atom_names(self):
        """
        Gets the atom names.

        :return:
            A list of atom names.
        """

        atom_names = []
        counter = {}

        for label in self.molecule.get_labels():
            if label not in counter:
                counter[label] = 0
            counter[label] += 1
            atom_names.append(label + str(counter[label]))

        for i, label in enumerate(self.molecule.get_labels()):
            if counter[label] == 1:
                atom_names[i] = label

        return atom_names


