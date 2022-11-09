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

from pathlib import Path
from datetime import datetime
from collections import deque
import numpy as np
import time as tm
import math
import sys

from .veloxchemlib import DispersionModel
from .veloxchemlib import OverlapIntegralsDriver
from .veloxchemlib import KineticEnergyIntegralsDriver
from .veloxchemlib import NuclearPotentialIntegralsDriver
from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import GridDriver
from .veloxchemlib import MolecularGrid
from .veloxchemlib import XCIntegrator, XCNewIntegrator
from .veloxchemlib import AOKohnShamMatrix
from .veloxchemlib import DenseMatrix
from .veloxchemlib import mpi_master
from .veloxchemlib import parse_xc_func
from .veloxchemlib import molorb, xcfun
from .profiler import Profiler
from .molecularbasis import MolecularBasis
from .aofockmatrix import AOFockMatrix
from .aodensitymatrix import AODensityMatrix
from .molecularorbitals import MolecularOrbitals
from .subcommunicators import SubCommunicators
from .signalhandler import SignalHandler
from .denguess import DensityGuess
from .inputparser import (parse_input, print_keywords, print_attributes,
                          get_datetime_string)
from .qqscheme import get_qq_type
from .qqscheme import get_qq_scheme
from .errorhandler import assert_msg_critical
from .checkpoint import create_hdf5, write_scf_tensors


class ScfDriver:
    """
    Implements SCF method with C2-DIIS and two-level C2-DIIS convergence
    accelerators.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - den_guess: The initial density guess driver.
        - acc_type: The type of SCF convergence accelerator.
        - max_err_vecs: The maximum number of error vectors.
        - max_iter: The maximum number of SCF iterations.
        - first_step: The flag for first step in two-level C2-DIIS convergence
          acceleration.
        - qq_type: The electron repulsion integrals screening scheme.
        - qq_dyn: The flag for enabling dynamic thresholds in electron
          repulsion integrals screening scheme.
        - conv_thresh: The SCF convergence threshold.
        - eri_thresh: The electron repulsion integrals screening threshold.
        - ovl_thresh: The atomic orbitals linear dependency threshold.
        - diis_thresh: The C2-DIIS switch on threshold.
        - iter_data: The dictionary of SCF iteration data (scf energy, scf
          energy change, gradient, density change, etc.).
        - is_converged: The flag for SCF convergence.
        - scf_energy: The SCF energy.
        - num_iter: The current number of SCF iterations.
        - fock_matrices: The list of stored Fock/Kohn-Sham matrices.
        - den_matrices: The list of stored density matrices.
        - density: The current density matrix.
        - mol_orbs: The current molecular orbitals.
        - nuc_energy: The nuclear repulsion energy of molecule.
        - comm: The MPI communicator.
        - rank: The rank of MPI process.
        - nodes: The number of MPI processes.
        - restart: The flag for restarting from checkpoint file.
        - checkpoint_file: The name of checkpoint file.
        - ref_mol_orbs: The reference molecular orbitals read from checkpoint
          file.
        - scf_type: The type of SCF calculation (restricted, unrestricted, or
          restricted open-shell).
        - dft: The flag for running DFT.
        - grid_level: The accuracy level of DFT grid.
        - xcfun: The XC functional.
        - molgrid: The molecular grid.
        - pe: The flag for running polarizable embedding calculation.
        - V_es: The polarizable embedding matrix.
        - pe_options: The dictionary with options for polarizable embedding.
        - pe_summary: The summary string for polarizable embedding.
        - use_split_comm: The flag for using split communicators.
        - split_comm_ratio: The list of ratios for split communicators.
        - dispersion: The flag for calculating D4 dispersion correction.
        - d4_energy: The D4 dispersion correction to energy.
        - electric_field: The static electric field.
        - ef_nuc_energy: The electric potential energy of the nuclei in the
          static electric field.
        - dipole_origin: The origin of the dipole operator.
        - timing: The flag for printing timing information.
        - profiling: The flag for printing profiling information.
        - memory_profiling: The flag for printing memory usage.
        - memory_tracing: The flag for tracing memory allocation using
        - program_end_time: The end time of the program.
        - filename: The filename.
    """

    def __init__(self, comm, ostream):
        """
        Initializes SCF driver to default setup (convergence threshold, initial
        guess, etc).
        """

        # scf accelerator
        self.acc_type = 'L2_DIIS'
        self.max_err_vecs = 10
        self.max_iter = 50
        self._first_step = False

        # screening scheme
        self.qq_type = 'QQ_DEN'
        self.qq_dyn = True

        # thresholds
        self.conv_thresh = 1.0e-6
        self.ovl_thresh = 1.0e-6
        self.diis_thresh = 1000.0
        self.eri_thresh = 1.0e-12
        self.eri_thresh_tight = 1.0e-15

        # iterations data
        self._iter_data = None
        self._is_converged = False
        self._scf_energy = 0.0
        self._num_iter = 0

        # DIIS data
        self._fock_matrices = deque()
        self._fock_matrices_beta = deque()
        self._fock_matrices_proj = deque()

        self._den_matrices = deque()
        self._den_matrices_beta = deque()

        # density matrix and molecular orbitals
        self._density = AODensityMatrix()
        self._molecular_orbitals = MolecularOrbitals()

        # nuclear repulsion energy
        self._nuc_energy = 0.0

        # mpi information
        self._comm = comm
        self._rank = self._comm.Get_rank()
        self._nodes = self._comm.Get_size()

        # output stream
        self._ostream = ostream

        # restart information
        self.restart = True
        self.checkpoint_file = None
        self._ref_mol_orbs = None

        # Maximum overlap constraint
        self._mom = None

        # closed shell?
        self._scf_type = 'restricted'

        # D4 dispersion correction
        self.dispersion = False
        self._d4_energy = 0.0

        # dft
        self.xcfun = None
        self.grid_level = 4
        self._dft = False
        self._mol_grid = None

        # polarizable embedding
        self.potfile = None
        self.pe_options = {}
        self._pe = False
        self._V_es = None
        self._pe_summary = ''

        # split communicators
        self.use_split_comm = False
        self._split_comm_ratio = None

        # static electric field
        self.electric_field = None
        self._ef_nuc_energy = 0.0
        self._dipole_origin = None

        # scf tensors
        self._scf_tensors = None

        # timing and profiling
        self.timing = False
        self.profiling = False
        self.memory_profiling = False
        self.memory_tracing = False

        # verbosity of output (1-3)
        self.print_level = 2

        # program end time for graceful exit
        self.program_end_time = None

        # filename
        self._filename = f'veloxchem_scf_{get_datetime_string()}'

        # input keywords
        self._input_keywords = {
            'scf': {
                'acc_type':
                    ('str_upper', 'type of SCF convergence accelerator'),
                'max_iter': ('int', 'maximum number of SCF iterations'),
                'conv_thresh': ('float', 'SCF convergence threshold'),
                'qq_type': ('str_upper', 'ERI screening scheme'),
                'eri_thresh': ('float', 'ERI screening threshold'),
                'restart': ('bool', 'restart from checkpoint file'),
                'checkpoint_file': ('str', 'name of checkpoint file'),
                'timing': ('bool', 'print timing information'),
                'profiling': ('bool', 'print profiling information'),
                'memory_profiling': ('bool', 'print memory usage'),
                'memory_tracing': ('bool', 'trace memory allocation'),
                'print_level': ('int', 'verbosity of output (1-3)'),
            },
            'method_settings': {
                'dispersion': ('bool', 'use D4 dispersion correction'),
                'xcfun': ('str_upper', 'exchange-correlation functional'),
                'grid_level': ('int', 'accuracy level of DFT grid (1-6)'),
                'potfile': ('str', 'potential file for polarizable embedding'),
                'electric_field': ('seq_fixed', 'static electric field'),
                'use_split_comm': ('bool', 'use split communicators'),
            },
        }

    @property
    def scf_type(self):
        """
        Returns the SCF type.
        """

        return self._scf_type

    @property
    def comm(self):
        """
        Returns the MPI communicator.
        """

        return self._comm

    @property
    def rank(self):
        """
        Returns the MPI rank.
        """

        return self._rank

    @property
    def nodes(self):
        """
        Returns the number of MPI processes.
        """

        return self._nodes

    @property
    def nnodes(self):
        """
        Returns the number of MPI processes.
        """

        return self._nodes

    @property
    def ostream(self):
        """
        Returns the output stream.
        """

        return self._ostream

    @property
    def is_converged(self):
        """
        Returns whether SCF is converged.
        """

        return self._is_converged

    @property
    def scf_energy(self):
        """
        Returns SCF energy.
        """

        return self._scf_energy

    @property
    def density(self):
        """
        Returns the density matrix.
        """

        return self._density

    @property
    def molecular_orbitals(self):
        """
        Returns the molecular orbitals.
        """

        return self._molecular_orbitals

    @property
    def mol_orbs(self):
        """
        Returns the molecular orbitals (for backward compatibility).
        """

        return self._molecular_orbitals

    @property
    def scf_tensors(self):
        """
        Returns the SCF tensors.
        """

        return self._scf_tensors

    def print_keywords(self):
        """
        Prints input keywords in SCF driver.
        """

        print_keywords(self._input_keywords, self.ostream)

    def print_attributes(self):
        """
        Prints attributes in SCF driver.
        """

        print_attributes(self._input_keywords, self.ostream)

    def update_settings(self, scf_dict, method_dict=None):
        """
        Updates settings in SCF driver.

        :param scf_dict:
            The dictionary of scf input.
        :param method_dict:
            The dicitonary of method settings.
        """

        if method_dict is None:
            method_dict = {}

        scf_keywords = {
            key: val[0] for key, val in self._input_keywords['scf'].items()
        }

        parse_input(self, scf_keywords, scf_dict)

        if 'program_end_time' in scf_dict:
            self.program_end_time = scf_dict['program_end_time']
        if 'filename' in scf_dict:
            self._filename = scf_dict['filename']
            if 'checkpoint_file' not in scf_dict:
                self.checkpoint_file = f'{self._filename}.scf.h5'

        method_keywords = {
            key: val[0]
            for key, val in self._input_keywords['method_settings'].items()
        }

        parse_input(self, method_keywords, method_dict)

        self._dft_sanity_check()

        self._pe_sanity_check(method_dict)

        if self.electric_field is not None:
            assert_msg_critical(
                len(self.electric_field) == 3,
                'SCF driver: Expecting 3 values in \'electric field\' input')
            assert_msg_critical(
                not self._pe,
                'SCF driver: \'electric field\' input is incompatible with ' +
                'polarizable embedding')
            # disable restart of calculation with static electric field since
            # checkpoint file does not contain information about the electric
            # field
            self.restart = False

    def _dft_sanity_check(self):
        """
        Checks DFT settings and updates relevant attributes.
        """

        # check xc functional
        if self.xcfun is not None:
            if isinstance(self.xcfun, str):
                self.xcfun = parse_xc_func(self.xcfun.upper())
            assert_msg_critical(not self.xcfun.is_undefined(),
                                'SCF driver: Undefined XC functional')
        self._dft = (self.xcfun is not None)

        # check grid level
        if self._dft and (self.grid_level < 1 or self.grid_level > 6):
            warn_msg = f'*** Warning: Invalid DFT grid level {self.grid_level}.'
            warn_msg += ' Using default value. ***'
            self.ostream.print_blank()
            self.ostream.print_header(warn_msg)
            self.ostream.print_blank()
            self.ostream.flush()
            self.grid_level = 4

    def _pe_sanity_check(self, method_dict=None):
        """
        Checks PE settings and updates relevant attributes.

        :param method_dict:
            The dicitonary of method settings.
        """

        if method_dict:
            if 'pe_options' in method_dict:
                self.pe_options = dict(method_dict['pe_options'])
            else:
                self.pe_options = {}

        if self.potfile:
            self.pe_options['potfile'] = self.potfile

        self._pe = ('potfile' in self.pe_options)

        if self._pe:
            from .polembed import PolEmbed

            cppe_potfile = None
            if self.rank == mpi_master():
                potfile = self.pe_options['potfile']
                if not Path(potfile).is_file():
                    potfile = str(
                        Path(self._filename).parent / Path(potfile).name)
                cppe_potfile = PolEmbed.write_cppe_potfile(potfile)
            cppe_potfile = self.comm.bcast(cppe_potfile, root=mpi_master())
            self.pe_options['potfile'] = cppe_potfile

    def compute(self, molecule, ao_basis, min_basis=None):
        """
        Performs SCF calculation using molecular data.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        """

        profiler = Profiler()

        if min_basis is None:
            if self.rank == mpi_master():
                min_basis = MolecularBasis.read(molecule,
                                                'AO-START-GUESS',
                                                basis_path='.',
                                                ostream=None)
            else:
                min_basis = MolecularBasis()
            min_basis.broadcast(self.rank, self.comm)

        # check dft setup
        self._dft_sanity_check()

        # check pe setup
        self._pe_sanity_check()

        # check print level (verbosity of output)
        if self.print_level < 2:
            self.print_level = 1
        if self.print_level > 2:
            self.print_level = 3

        # initial guess
        if self.restart:
            self._den_guess = DensityGuess('RESTART', self.checkpoint_file)
            self.restart = self._den_guess.validate_checkpoint(
                self.rank, self.comm, molecule.elem_ids_to_numpy(),
                ao_basis.get_label(), self.scf_type)

        if self.restart:
            self.acc_type = 'DIIS'
            if self.rank == mpi_master():
                self._ref_mol_orbs = MolecularOrbitals.read_hdf5(
                    self.checkpoint_file)
                self._molecular_orbitals = MolecularOrbitals(self._ref_mol_orbs)
        else:
            self._den_guess = DensityGuess('SAD')

        # nuclear repulsion energy
        self._nuc_energy = molecule.nuclear_repulsion_energy()

        if self.rank == mpi_master():
            self._print_header()
            valstr = 'Nuclear repulsion energy: {:.10f} a.u.'.format(
                self._nuc_energy)
            self.ostream.print_info(valstr)
            self.ostream.print_blank()

        # D4 dispersion correction
        if self.dispersion:
            if self.rank == mpi_master():
                disp = DispersionModel()
                xc_label = self.xcfun.get_func_label() if self._dft else 'HF'
                disp.compute(molecule, xc_label)
                self._d4_energy = disp.get_energy()
            else:
                self._d4_energy = 0.0
            self._d4_energy = self.comm.bcast(self._d4_energy,
                                              root=mpi_master())
        else:
            self._d4_energy = 0.0

        # generate integration grid
        if self._dft:
            grid_drv = GridDriver(self.comm)
            grid_drv.set_level(self.grid_level)

            grid_t0 = tm.time()
            self._mol_grid = grid_drv.generate(molecule)
            n_grid_points = self._mol_grid.number_of_points()
            self.ostream.print_info(
                'Molecular grid with {0:d} points generated in {1:.2f} sec.'.
                format(n_grid_points,
                       tm.time() - grid_t0))
            self.ostream.print_blank()

        # set up polarizable embedding
        if self._pe:
            from .polembed import PolEmbed
            self._pe_drv = PolEmbed(molecule, ao_basis, self.pe_options,
                                    self.comm)
            self._V_es = self._pe_drv.compute_multipole_potential_integrals()

            cppe_info = 'Using CPPE {} for polarizable embedding.'.format(
                self._pe_drv.get_cppe_version())
            self.ostream.print_info(cppe_info)
            self.ostream.print_blank()

            pot_info = 'Reading polarizable embedding potential: {}'.format(
                self.pe_options['potfile'])
            self.ostream.print_info(pot_info)
            self.ostream.print_blank()

        # C2-DIIS method
        if self.acc_type == 'DIIS':
            self._comp_diis(molecule, ao_basis, min_basis, profiler)

        # two level C2-DIIS method
        if self.acc_type == 'L2_DIIS':

            # first step
            self._first_step = True

            old_thresh = self.conv_thresh
            self.conv_thresh = 1.0e-3

            old_max_iter = self.max_iter
            self.max_iter = 5

            val_basis = ao_basis.get_valence_basis()
            self._comp_diis(molecule, val_basis, min_basis, profiler)

            # second step
            self._first_step = False

            self.diis_thresh = 1000.0
            self.conv_thresh = old_thresh
            self.max_iter = old_max_iter
            self._den_guess.guess_type = 'PRCMO'

            self._comp_diis(molecule, ao_basis, val_basis, profiler)

        self._fock_matrices.clear()
        self._den_matrices.clear()

        self._fock_matrices_beta.clear()
        self._den_matrices_beta.clear()

        self._fock_matrices_proj.clear()

        profiler.end(self.ostream, scf_flag=True)

        if not self.is_converged:
            self.ostream.print_header(
                '*** Warning: SCF is not converged!'.ljust(92))
            self.ostream.print_blank()
            self.ostream.flush()
            return

        if self.rank == mpi_master():
            self._print_scf_energy()
            s2 = self.compute_s2(molecule, self.scf_tensors)
            self._print_ground_state(molecule, s2)
            if self.print_level == 2:
                self.molecular_orbitals.print_orbitals(molecule, ao_basis,
                                                       False, self.ostream)
            if self.print_level == 3:
                self.molecular_orbitals.print_orbitals(molecule, ao_basis, True,
                                                       self.ostream)
            self.ostream.flush()

    def maximum_overlap(self, molecule, orbitals, alpha_list, beta_list):
        """
        Constraint the SCF calculation to find orbitals that maximize overlap with a reference set.

        :param molecule:
            The molecule.
        :param orbitals:
            The reference MolecularOrbital object.
        :param alpha_list:
            The list of alpha occupied orbitals
        :param beta_list:
            The list of beta occupied orbitals
        """

        if self.rank == mpi_master():
            N_alpha = molecule.number_of_alpha_electrons()
            N_beta = molecule.number_of_beta_electrons()

            err_excitations = "ScfDriver.maximum_overlap: incorrect definition of occupation lists"
            assert_msg_critical(len(alpha_list)==N_alpha, err_excitations)
            assert_msg_critical(len(beta_list)==N_beta, err_excitations)
            if self.scf_type == 'restricted':
                assert_msg_critical(alpha_list==beta_list, err_excitations)

            C_a = orbitals.alpha_to_numpy()[:,alpha_list]
            C_b = orbitals.beta_to_numpy()[:,beta_list]
            self._mom = [C_a,C_b]

    def set_start_orbitals(self, molecule, basis, array):
        """
        Creates checkpoint file from numpy array containing starting orbitals.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        :param array:
            The numpy array (or list/tuple of numpy arrays).
        """

        # create MolecularOrbitals object from numpy array

        if self.rank == mpi_master():
            if isinstance(array, np.ndarray):
                C_alpha = array
                C_beta = None
            elif isinstance(array, (tuple, list)):
                C_alpha = array[0]
                C_beta = array[1] if len(array) > 1 else None
            else:
                C_alpha = None
                C_beta = None

            n_ao = basis.get_dimensions_of_basis(molecule)
            err_ao = 'ScfDriver.set_start_orbitals: inconsistent number of AOs'
            err_array = 'ScfDriver.set_start_orbitals: invalid array'

            if C_beta is None:
                assert_msg_critical(isinstance(C_alpha, np.ndarray), err_array)
                assert_msg_critical(n_ao == C_alpha.shape[0], err_ao)
                E_alpha = np.zeros(C_alpha.shape[1])
                occ_alpha = molecule.get_aufbau_occupation(n_ao, 'restricted')
                self._molecular_orbitals = MolecularOrbitals([C_alpha],
                                                             [E_alpha],
                                                             [occ_alpha],
                                                             molorb.rest)
            else:
                assert_msg_critical(
                    isinstance(C_alpha, np.ndarray) and
                    isinstance(C_beta, np.ndarray), err_array)
                assert_msg_critical(
                    n_ao == C_alpha.shape[0] and n_ao == C_beta.shape[0],
                    err_ao)
                E_alpha = np.zeros(C_alpha.shape[1])
                E_beta = np.zeros(C_beta.shape[1])

                occ_alpha, occ_beta = molecule.get_aufbau_occupation(
                    n_ao, 'unrestricted')

                self._molecular_orbitals = MolecularOrbitals(
                    [C_alpha, C_beta], [E_alpha, E_beta], [occ_alpha, occ_beta],
                    molorb.unrest)
        else:
            self._molecular_orbitals = MolecularOrbitals()

        # write checkpoint file and sychronize MPI processes

        self.restart = True
        if self.checkpoint_file is None:
            self.checkpoint_file = f'{self._filename}.scf.h5'
        self.write_checkpoint(molecule.elem_ids_to_numpy(), basis.get_label())
        self.comm.barrier()

    def write_checkpoint(self, nuclear_charges, basis_set):
        """
        Writes molecular orbitals to checkpoint file.

        :param nuclear_charges:
            The nuclear charges.
        :param basis_set:
            Name of the basis set.
        """

        if self.rank == mpi_master():
            if self.checkpoint_file and isinstance(self.checkpoint_file, str):
                self.molecular_orbitals.write_hdf5(self.checkpoint_file,
                                                   nuclear_charges, basis_set)
                self.ostream.print_blank()
                checkpoint_text = 'Checkpoint written to file: '
                checkpoint_text += self.checkpoint_file
                self.ostream.print_info(checkpoint_text)

    def _comp_diis(self, molecule, ao_basis, min_basis, profiler):
        """
        Performs SCF calculation with C2-DIIS acceleration.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        :param profiler:
            The profiler.
        """

        if not self._first_step:
            profiler.begin({
                'timing': self.timing,
                'profiling': self.profiling,
                'memory_profiling': self.memory_profiling,
                'memory_tracing': self.memory_tracing,
            })

        diis_start_time = tm.time()

        self._fock_matrices.clear()
        self._den_matrices.clear()

        self._fock_matrices_beta.clear()
        self._den_matrices_beta.clear()

        self._fock_matrices_proj.clear()

        ovl_mat, kin_mat, npot_mat, dipole_mats = self._comp_one_ints(
            molecule, ao_basis)

        if self.rank == mpi_master() and self.electric_field is not None:
            dipole_ints = (dipole_mats.x_to_numpy(), dipole_mats.y_to_numpy(),
                           dipole_mats.z_to_numpy())

        linear_dependency = False

        if self.rank == mpi_master():
            t0 = tm.time()

            oao_mat = ovl_mat.get_ortho_matrix(self.ovl_thresh)
            self._scf_tensors = {'S': ovl_mat.to_numpy()}

            self.ostream.print_info('Orthogonalization matrix computed in' +
                                    ' {:.2f} sec.'.format(tm.time() - t0))
            self.ostream.print_blank()

            nrow = oao_mat.number_of_rows()
            ncol = oao_mat.number_of_columns()
            linear_dependency = (nrow != ncol)

            if linear_dependency:
                ndim = nrow - ncol
                self.ostream.print_info(
                    'Removed ' + str(ndim) + ' linearly dependent' +
                    ' vector{:s}.'.format('' if ndim == 1 else 's'))
                self.ostream.print_blank()
            self.ostream.flush()

        else:
            oao_mat = None

        linear_dependency = self.comm.bcast(linear_dependency,
                                            root=mpi_master())

        if (linear_dependency and self.eri_thresh > self.eri_thresh_tight):
            self.eri_thresh = self.eri_thresh_tight

            if self.rank == mpi_master():
                self.ostream.print_info('ERI screening threshold tightened to' +
                                        ' {:.1e}.'.format(self.eri_thresh))
                self.ostream.print_blank()

        den_mat = self._comp_guess_density(molecule, ao_basis, min_basis)

        den_mat.broadcast(self.rank, self.comm)

        self._density = AODensityMatrix(den_mat)

        fock_mat = AOFockMatrix(den_mat)

        if self._dft and not self._first_step:
            self._update_fock_type(fock_mat)

        if self.use_split_comm:
            self.use_split_comm = ((self._dft or self._pe) and self.nodes >= 8)

        if self.use_split_comm and not self._first_step:
            qq_data = None
            if not self._first_step:
                valstr = 'ERI'
                if self._dft:
                    valstr += '/DFT'
                if self._pe:
                    valstr += '/PE'
                self.ostream.print_info(
                    'Using sub-communicators for {}.'.format(valstr))
        else:
            eri_drv = ElectronRepulsionIntegralsDriver(self.comm)
            qq_data = eri_drv.compute(get_qq_scheme(self.qq_type),
                                      self.eri_thresh, molecule, ao_basis)

        profiler.check_memory_usage('Initial guess')

        self._split_comm_ratio = None

        e_grad = None

        if self.rank == mpi_master():
            self._print_scf_title()

        if not self._first_step:
            signal_handler = SignalHandler()
            signal_handler.add_sigterm_function(self._graceful_exit, molecule,
                                                ao_basis)

        for i in self._get_scf_range():

            # set the current number of SCF iterations
            # (note the extra SCF cycle when starting from scratch)
            if self.restart:
                self._num_iter = i + 1
            else:
                self._num_iter = i

            profiler.set_timing_key(f'Iteration {self._num_iter:d}')

            iter_start_time = tm.time()

            vxc_mat, e_pe, V_pe = self._comp_2e_fock(fock_mat, den_mat,
                                                     molecule, ao_basis,
                                                     qq_data, e_grad, profiler)

            profiler.start_timer('CompEnergy')

            e_el = self._comp_energy(fock_mat, vxc_mat, e_pe, kin_mat, npot_mat,
                                     den_mat)

            self._comp_full_fock(fock_mat, vxc_mat, V_pe, kin_mat, npot_mat)

            if self.rank == mpi_master() and self.electric_field is not None:
                efpot = sum([
                    ef * mat
                    for ef, mat in zip(self.electric_field, dipole_ints)
                ])

                if self.scf_type == 'restricted':
                    e_el += 2.0 * np.trace(
                        np.matmul(efpot, den_mat.alpha_to_numpy(0)))
                    fock_mat.add_matrix(DenseMatrix(efpot), 0)
                else:
                    e_el += np.trace(
                        np.matmul(efpot, (den_mat.alpha_to_numpy(0) +
                                          den_mat.beta_to_numpy(0))))
                    fock_mat.add_matrix(DenseMatrix(efpot), 0, 'alpha')
                    fock_mat.add_matrix(DenseMatrix(efpot), 0, 'beta')

                self._ef_nuc_energy = 0.0
                coords = molecule.get_coordinates()
                elem_ids = molecule.elem_ids_to_numpy()
                for i in range(molecule.number_of_atoms()):
                    self._ef_nuc_energy -= np.dot(
                        elem_ids[i] * (coords[i] - self._dipole_origin),
                        self.electric_field)

            e_grad, max_grad = self._comp_gradient(fock_mat, ovl_mat, den_mat,
                                                   oao_mat)

            # compute density change and energy change

            diff_den = self._comp_density_change(den_mat, self.density)

            e_scf = (e_el + self._nuc_energy + self._d4_energy +
                     self._ef_nuc_energy)

            diff_e_scf = e_scf - self.scf_energy

            self._iter_data = {
                'energy': e_scf,
                'gradient_norm': e_grad,
                'max_gradient': max_grad,
                'diff_density': diff_den,
                'diff_energy': diff_e_scf,
            }

            # update density and energy

            self._density = AODensityMatrix(den_mat)

            self._scf_energy = e_scf

            profiler.stop_timer('CompEnergy')
            profiler.check_memory_usage('Iteration {:d} Fock build'.format(
                self._num_iter))

            # print iteration and check convergence

            self._print_iter_data(i)

            self._check_convergence()

            if self.is_converged:
                break

            # compute new Fock matrix, molecular orbitals and density

            profiler.start_timer('FockDiag')

            self._store_diis_data(fock_mat, den_mat, e_grad)

            eff_fock_mat = self._get_effective_fock(fock_mat, ovl_mat, oao_mat)

            self._molecular_orbitals = self._gen_molecular_orbitals(
                molecule, eff_fock_mat, oao_mat)

            if self._mom is not None:
                self._apply_mom(molecule, ovl_mat)

            self._update_mol_orbs_phase()

            den_mat = self._gen_new_density(molecule, self.scf_type)

            den_mat.broadcast(self.rank, self.comm)

            profiler.stop_timer('FockDiag')

            profiler.check_memory_usage('Iteration {:d} Fock diag.'.format(
                self._num_iter))

            if not self._first_step:
                iter_in_hours = (tm.time() - iter_start_time) / 3600
                if self._need_graceful_exit(iter_in_hours):
                    self._graceful_exit(molecule, ao_basis)

        if not self._first_step:
            signal_handler.remove_sigterm_function()

            self.write_checkpoint(molecule.elem_ids_to_numpy(),
                                  ao_basis.get_label())

        if self.rank == mpi_master() and not self._first_step:
            S = ovl_mat.to_numpy()

            C_alpha = self.molecular_orbitals.alpha_to_numpy()
            C_beta = self.molecular_orbitals.beta_to_numpy()

            E_alpha = self.molecular_orbitals.ea_to_numpy()
            E_beta = self.molecular_orbitals.eb_to_numpy()

            D_alpha = self.density.alpha_to_numpy(0)
            D_beta = self.density.beta_to_numpy(0)

            F_alpha = fock_mat.alpha_to_numpy(0)
            F_beta = fock_mat.beta_to_numpy(0)

            self._scf_tensors = {
                'S': S,
                'C_alpha': C_alpha,
                'C_beta': C_beta,
                'E_alpha': E_alpha,
                'E_beta': E_beta,
                'D_alpha': D_alpha,
                'D_beta': D_beta,
                'F_alpha': F_alpha,
                'F_beta': F_beta,
                # for backward compatibility
                'C': C_alpha,
                'E': E_alpha,
                'D': (D_alpha, D_beta),
                'F': (F_alpha, F_beta),
            }

            if self.is_converged:
                self._write_final_hdf5(molecule, ao_basis)

        else:
            self._scf_tensors = None

        if self.rank == mpi_master():
            self._print_scf_finish(diis_start_time)

        profiler.check_memory_usage('End of SCF')

    def _need_graceful_exit(self, iter_in_hours):
        """
        Checks if a graceful exit is needed.

        :param iter_in_hours:
            The time spent in one iteration (in hours).

        :return:
            True if a graceful exit is needed, False otherwise.
        """

        if self.program_end_time is not None:
            remaining_hours = (self.program_end_time -
                               datetime.now()).total_seconds() / 3600
            # exit gracefully when the remaining time is not sufficient to
            # complete the next iteration (plus 25% to be on the safe side).
            if remaining_hours < iter_in_hours * 1.25:
                return True
        return False

    def _graceful_exit(self, molecule, basis):
        """
        Gracefully exits the program.

        :param molecule:
            The molecule.
        :param basis:
            The basis set.

        :return:
            The return code.
        """

        self.ostream.print_blank()
        self.ostream.print_info('Preparing for a graceful termination...')
        self.ostream.flush()

        self.write_checkpoint(molecule.elem_ids_to_numpy(), basis.get_label())

        self.ostream.print_blank()
        self.ostream.print_info('...done.')
        self.ostream.print_blank()
        self.ostream.print_info('Exiting program.')
        self.ostream.print_blank()
        self.ostream.flush()

        sys.exit(0)

    def _comp_one_ints(self, molecule, basis):
        """
        Computes one-electron integrals (overlap, kinetic energy and nuclear
        potential) using molecular data.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.

        :return:
            The one-electron integrals.
        """

        t0 = tm.time()

        ovl_drv = OverlapIntegralsDriver(self.comm)
        ovl_mat = ovl_drv.compute(molecule, basis)

        t1 = tm.time()

        kin_drv = KineticEnergyIntegralsDriver(self.comm)
        kin_mat = kin_drv.compute(molecule, basis)

        t2 = tm.time()

        if molecule.number_of_atoms() >= self.nodes and self.nodes > 1:
            npot_mat = self._comp_npot_mat_split_comm(molecule, basis)
        else:
            npot_drv = NuclearPotentialIntegralsDriver(self.comm)
            npot_mat = npot_drv.compute(molecule, basis)

        t3 = tm.time()

        if self.electric_field is not None:
            if molecule.get_charge() != 0:
                coords = molecule.get_coordinates()
                nuclear_charges = molecule.elem_ids_to_numpy()
                self._dipole_origin = np.sum(coords.T * nuclear_charges,
                                             axis=1) / np.sum(nuclear_charges)
            else:
                self._dipole_origin = np.zeros(3)
            dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
            dipole_drv.origin = tuple(self._dipole_origin)
            dipole_mats = dipole_drv.compute(molecule, basis)
        else:
            dipole_mats = None

        t4 = tm.time()

        if self.rank == mpi_master() and self.print_level > 1:

            self.ostream.print_info('Overlap matrix computed in' +
                                    ' {:.2f} sec.'.format(t1 - t0))
            self.ostream.print_blank()

            self.ostream.print_info('Kinetic energy matrix computed in' +
                                    ' {:.2f} sec.'.format(t2 - t1))
            self.ostream.print_blank()

            self.ostream.print_info('Nuclear potential matrix computed in' +
                                    ' {:.2f} sec.'.format(t3 - t2))
            self.ostream.print_blank()

            if self.electric_field is not None:
                self.ostream.print_info('Electric dipole matrices computed in' +
                                        ' {:.2f} sec.'.format(t4 - t3))
                self.ostream.print_blank()

            self.ostream.flush()

        return ovl_mat, kin_mat, npot_mat, dipole_mats

    def _comp_npot_mat_split_comm(self, molecule, basis):
        """
        Computes one-electron nuclear potential integral on split
        communicators.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.

        :return:
            The one-electron nuclear potential matrix.
        """

        node_grps = [p for p in range(self.nodes)]
        subcomm = SubCommunicators(self.comm, node_grps)
        local_comm = subcomm.local_comm
        cross_comm = subcomm.cross_comm

        ave, res = divmod(molecule.number_of_atoms(), self.nodes)
        counts = [ave + 1 if p < res else ave for p in range(self.nodes)]

        start = sum(counts[:self.rank])
        end = sum(counts[:self.rank + 1])

        charges = molecule.elem_ids_to_numpy()[start:end].astype(float)
        coords = np.vstack(
            (molecule.x_to_numpy()[start:end], molecule.y_to_numpy()[start:end],
             molecule.z_to_numpy()[start:end])).T

        npot_drv = NuclearPotentialIntegralsDriver(local_comm)
        npot_mat = npot_drv.compute(molecule, basis, charges, coords)

        if local_comm.Get_rank() == mpi_master():
            npot_mat.reduce_sum(cross_comm.Get_rank(), cross_comm.Get_size(),
                                cross_comm)

        return npot_mat

    def _comp_guess_density(self, molecule, ao_basis, min_basis):
        """
        Computes initial density guess for SCF using superposition of atomic
        densities or molecular orbitals projection methods.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.

        :return:
            The density matrix.
        """

        # guess: read from checkpoint file
        if self._den_guess.guess_type == 'RESTART':

            return self._den_guess.restart_density(molecule, self.rank,
                                                   self.ostream, self.scf_type)

        # guess: superposition of atomic densities
        if self._den_guess.guess_type == 'SAD':

            return self._den_guess.sad_density(molecule, ao_basis, min_basis,
                                               self.scf_type, self.comm,
                                               self.ostream)

        # guess: projection of molecular orbitals from reduced basis
        if self._den_guess.guess_type == 'PRCMO':

            if self.rank == mpi_master():
                return self._den_guess.prcmo_density(molecule, ao_basis,
                                                     min_basis,
                                                     self.molecular_orbitals,
                                                     self.scf_type)
            else:
                return AODensityMatrix()

        return AODensityMatrix()

    def _comp_2e_fock(self,
                      fock_mat,
                      den_mat,
                      molecule,
                      basis,
                      screening,
                      e_grad=None,
                      profiler=None):
        """
        Computes Fock/Kohn-Sham matrix (only 2e part).

        :param fock_mat:
            The AO Fock matrix (only 2e-part).
        :param den_mat:
            The AO density matrix.
        :param molecule:
            The molecule.
        :param basis:
            The basis set.
        :param screening:
            The screening container object.
        :param e_grad:
            The electronic gradient.
        :param profiler:
            The profiler.

        :return:
            The AO Kohn-Sham (Vxc) matrix.
        """

        if self.use_split_comm and not self._first_step:
            vxc_mat, e_pe, V_pe = self._comp_2e_fock_split_comm(
                fock_mat, den_mat, molecule, basis, screening, e_grad)

        else:
            vxc_mat, e_pe, V_pe = self._comp_2e_fock_single_comm(
                fock_mat, den_mat, molecule, basis, screening, e_grad, profiler)

        return vxc_mat, e_pe, V_pe

    def _comp_2e_fock_single_comm(self,
                                  fock_mat,
                                  den_mat,
                                  molecule,
                                  basis,
                                  screening,
                                  e_grad=None,
                                  profiler=None):
        """
        Computes Fock/Kohn-Sham matrix on single communicator.

        :param fock_mat:
            The AO Fock matrix (only 2e-part).
        :param den_mat:
            The AO density matrix.
        :param molecule:
            The molecule.
        :param basis:
            The basis set.
        :param screening:
            The screening container object.
        :param e_grad:
            The electronic gradient.
        :param profiler:
            The profiler.

        :return:
            The AO Kohn-Sham (Vxc) matrix.
        """

        if self.qq_dyn and e_grad is not None:
            screening.set_threshold(self._get_dyn_threshold(e_grad))
        eri_drv = ElectronRepulsionIntegralsDriver(self.comm)

        eri_t0 = tm.time()

        eri_drv.compute(fock_mat, den_mat, molecule, basis, screening)
        fock_mat.reduce_sum(self.rank, self.nodes, self.comm)

        if self.timing:
            profiler.add_timing_info('FockERI', tm.time() - eri_t0)
        vxc_t0 = tm.time()

        if self._dft and not self._first_step:
            if not self.xcfun.is_hybrid():
                if self.scf_type == 'restricted':
                    fock_mat.scale(2.0, 0)

            if (self.scf_type == 'restricted' and
                    self.xcfun.get_func_type() in [xcfun.lda, xcfun.gga]):
                xc_drv = XCNewIntegrator(self.comm)
                self._mol_grid.partition_grid_points()
                self._mol_grid.distribute_counts_and_displacements(
                    self.rank, self.nodes, self.comm)
                vxc_mat = xc_drv.integrate_vxc_fock(molecule, basis, den_mat,
                                                    self._mol_grid,
                                                    self.xcfun.get_func_label())
            else:
                xc_drv = XCIntegrator(self.comm)
                self._mol_grid.distribute(self.rank, self.nodes, self.comm)
                vxc_mat = xc_drv.integrate(den_mat, molecule, basis,
                                           self._mol_grid,
                                           self.xcfun.get_func_label())
            vxc_mat.reduce_sum(self.rank, self.nodes, self.comm)
        else:
            vxc_mat = None

        if self.timing and self._dft:
            profiler.add_timing_info('FockXC', tm.time() - vxc_t0)
        pe_t0 = tm.time()

        if self._pe and not self._first_step:
            self._pe_drv.V_es = self._V_es.copy()
            dm = den_mat.alpha_to_numpy(0) + den_mat.beta_to_numpy(0)
            e_pe, V_pe = self._pe_drv.get_pe_contribution(dm)
            self._pe_summary = self._pe_drv.cppe_state.summary_string
        else:
            e_pe, V_pe = 0.0, None

        if self.timing and self._pe:
            profiler.add_timing_info('FockPE', tm.time() - pe_t0)

        return vxc_mat, e_pe, V_pe

    def _comp_2e_fock_split_comm(self,
                                 fock_mat,
                                 den_mat,
                                 molecule,
                                 basis,
                                 screening,
                                 e_grad=None):
        """
        Computes Fock/Kohn-Sham matrix on split communicators.

        :param fock_mat:
            The AO Fock matrix (only 2e-part).
        :param den_mat:
            The AO density matrix.
        :param molecule:
            The molecule.
        :param basis:
            The basis set.
        :param screening:
            The screening container object.
        :param e_grad:
            The electronic gradient.

        :return:
            The AO Kohn-Sham (Vxc) matrix.
        """

        if self._split_comm_ratio is None:
            if self._dft and self._pe:
                self._split_comm_ratio = [0.34, 0.33, 0.33]
            elif self._dft:
                self._split_comm_ratio = [0.5, 0.5, 0.0]
            elif self._pe:
                self._split_comm_ratio = [0.5, 0.0, 0.5]
            else:
                self._split_comm_ratio = [1.0, 0.0, 0.0]

        if self._dft:
            dft_nodes = int(float(self.nodes) * self._split_comm_ratio[1] + 0.5)
            dft_nodes = max(1, dft_nodes)
        else:
            dft_nodes = 0

        if self._pe:
            pe_nodes = int(float(self.nodes) * self._split_comm_ratio[2] + 0.5)
            pe_nodes = max(1, pe_nodes)
        else:
            pe_nodes = 0

        eri_nodes = max(1, self.nodes - dft_nodes - pe_nodes)

        if eri_nodes == max(eri_nodes, dft_nodes, pe_nodes):
            eri_nodes = self.nodes - dft_nodes - pe_nodes
        elif dft_nodes == max(eri_nodes, dft_nodes, pe_nodes):
            dft_nodes = self.nodes - eri_nodes - pe_nodes
        else:
            pe_nodes = self.nodes - eri_nodes - dft_nodes

        node_grps = [0] * eri_nodes + [1] * dft_nodes + [2] * pe_nodes
        eri_comm = (node_grps[self.rank] == 0)
        dft_comm = (node_grps[self.rank] == 1)
        pe_comm = (node_grps[self.rank] == 2)

        subcomms = SubCommunicators(self.comm, node_grps)
        local_comm = subcomms.local_comm
        cross_comm = subcomms.cross_comm

        # reset molecular grid for DFT and V_es for PE
        if self.rank != mpi_master():
            self._mol_grid = MolecularGrid()
            self._V_es = np.zeros(0)
        if self._dft:
            if local_comm.Get_rank() == mpi_master():
                self._mol_grid.broadcast(cross_comm.Get_rank(), cross_comm)
        if self._pe:
            if local_comm.Get_rank() == mpi_master():
                self._V_es = cross_comm.bcast(self._V_es, root=mpi_master())

        t0 = tm.time()

        # calculate Fock on ERI nodes
        if eri_comm:
            eri_drv = ElectronRepulsionIntegralsDriver(local_comm)
            local_screening = eri_drv.compute(get_qq_scheme(self.qq_type),
                                              self.eri_thresh, molecule, basis)
            if self.qq_dyn and e_grad is not None:
                local_screening.set_threshold(self._get_dyn_threshold(e_grad))
            eri_drv.compute(fock_mat, den_mat, molecule, basis, local_screening)
            fock_mat.reduce_sum(local_comm.Get_rank(), local_comm.Get_size(),
                                local_comm)
            if self._dft and (not self.xcfun.is_hybrid()):
                if self.scf_type == 'restricted':
                    fock_mat.scale(2.0, 0)

        # calculate Vxc on DFT nodes
        if dft_comm:
            xc_drv = XCIntegrator(local_comm)
            self._mol_grid.distribute(local_comm.Get_rank(),
                                      local_comm.Get_size(), local_comm)
            vxc_mat = xc_drv.integrate(den_mat, molecule, basis, self._mol_grid,
                                       self.xcfun.get_func_label())
            vxc_mat.reduce_sum(local_comm.Get_rank(), local_comm.Get_size(),
                               local_comm)
        else:
            vxc_mat = AOKohnShamMatrix()

        # calculate e_pe and V_pe on PE nodes
        if pe_comm:
            from .polembed import PolEmbed
            self._pe_drv = PolEmbed(molecule, basis, self.pe_options,
                                    local_comm)
            self._pe_drv.V_es = self._V_es.copy()
            dm = den_mat.alpha_to_numpy(0) + den_mat.beta_to_numpy(0)
            e_pe, V_pe = self._pe_drv.get_pe_contribution(dm)
            self._pe_summary = self._pe_drv.cppe_state.summary_string
        else:
            e_pe, V_pe = 0.0, None
            self._pe_summary = ''

        dt = tm.time() - t0

        # collect Vxc to master node
        if self._dft:
            if local_comm.Get_rank() == mpi_master():
                vxc_mat.collect(cross_comm.Get_rank(), cross_comm.Get_size(),
                                cross_comm, 1)

        # collect PE results to master node
        if self._pe:
            pe_root = 2 if self._dft else 1
            if local_comm.Get_rank() == mpi_master():
                e_pe = cross_comm.bcast(e_pe, root=pe_root)
                V_pe = cross_comm.bcast(V_pe, root=pe_root)
                self._pe_summary = cross_comm.bcast(self._pe_summary,
                                                    root=pe_root)

        if local_comm.Get_rank() == mpi_master():
            dt = cross_comm.gather(dt, root=mpi_master())

        if self.rank == mpi_master():
            time_eri = dt[0] * eri_nodes
            time_dft = 0.0
            if self._dft:
                time_dft = dt[1] * dft_nodes
            time_pe = 0.0
            if self._pe:
                pe_root = 2 if self._dft else 1
                time_pe = dt[pe_root] * pe_nodes
            time_sum = time_eri + time_dft + time_pe
            self._split_comm_ratio = [
                time_eri / time_sum,
                time_dft / time_sum,
                time_pe / time_sum,
            ]
        self._split_comm_ratio = self.comm.bcast(self._split_comm_ratio,
                                                 root=mpi_master())

        return vxc_mat, e_pe, V_pe

    def _comp_energy(self, fock_mat, vxc_mat, e_pe, kin_mat, npot_mat, den_mat):
        """
        Computes the sum of SCF energy components: electronic energy, kinetic
        energy, and nuclear potential energy.

        :param fock_mat:
            The Fock/Kohn-Sham matrix (only 2e-part).
        :param vxc_mat:
            The Vxc matrix.
        :param e_pe:
            The polarizable embedding energy.
        :param kin_mat:
            The kinetic energy matrix.
        :param npot_mat:
            The nuclear potential matrix.
        :param den_mat:
            The density matrix.

        :return:
            The sum of electronic energy, kinetic energy and nuclear potential
            energy.
        """

        if self.rank == mpi_master():
            # electronic, kinetic, nuclear energy
            e_ee = fock_mat.get_energy(0, den_mat, 0)
            e_kin = 2.0 * kin_mat.get_energy(den_mat, 0)
            e_en = -2.0 * npot_mat.get_energy(den_mat, 0)
            if self._dft and not self._first_step:
                e_ee += vxc_mat.get_energy()
            if self._pe and not self._first_step:
                e_ee += e_pe
            e_sum = e_ee + e_kin + e_en
        else:
            e_sum = 0.0
        e_sum = self.comm.bcast(e_sum, root=mpi_master())

        return e_sum

    def _comp_full_fock(self, fock_mat, vxc_mat, pe_mat, kin_mat, npot_mat):
        """
        Computes full Fock/Kohn-Sham matrix by adding to 2e-part of
        Fock/Kohn-Sham matrix the kinetic energy and nuclear potential
        matrices.

        :param fock_mat:
            The Fock/Kohn-Sham matrix (2e-part).
        :param vxc_mat:
            The Vxc matrix.
        :param pe_mat:
            The polarizable embedding matrix.
        :param kin_mat:
            The kinetic energy matrix.
        :param npot_mat:
            The nuclear potential matrix.
        """

        if self.rank == mpi_master():
            fock_mat.add_hcore(kin_mat, npot_mat, 0)

            if self._dft and not self._first_step:
                fock_mat.add_matrix(vxc_mat.get_matrix(), 0)
                if self.scf_type in ['unrestricted', 'restricted_openshell']:
                    fock_mat.add_matrix(vxc_mat.get_matrix(True), 0, 'beta')

            if self._pe and not self._first_step:
                fock_mat.add_matrix(DenseMatrix(pe_mat), 0)

    def _comp_gradient(self, fock_mat, ovl_mat, den_mat, oao_mat):
        """
        Computes electronic gradient using Fock/Kohn-Sham matrix.

        :param fock_mat:
            The Fock/Kohn-Sham matrix.
        :param ovl_mat:
            The overlap matrix.
        :param den_mat:
            The density matrix.
        :param oao_mat:
            The orthogonalization matrix.

        :return:
            The electronic gradient.
        """

        return 0.0

    def _comp_density_change(self, den_mat, old_den_mat):
        """
        Computes norm of density change between two density matrices.

        :param den_mat:
            The current density matrix.
        :param old_den_mat:
            The previous density matrix.

        :return:
            The norm of change between two density matrices.
        """

        return 0.0

    def _store_diis_data(self, fock_mat, den_mat):
        """
        Stores Fock/Kohn-Sham and density matrices for current iteration.

        :param fock_mat:
            The Fock/Kohn-Sham matrix.
        :param den_mat:
            The density matrix.
        :param e_grad:
            The electronic gradient.
        """

        return

    def _get_effective_fock(self, fock_mat, ovl_mat, oao_mat):
        """
        Computes effective Fock/Kohn-Sham matrix in OAO basis by applying
        Lowdin or canonical orthogonalization to AO Fock/Kohn-Sham matrix.

        :param fock_mat:
            The Fock/Kohn-Sham matrix.
        :param ovl_mat:
            The overlap matrix.
        :param oao_mat:
            The orthogonalization matrix.

        :return:
            The effective Fock/Kohn-Sham matrix.
        """

        return None

    def _gen_molecular_orbitals(self, molecule, fock_mat, oao_mat):
        """
        Generates molecular orbital by diagonalizing Fock/Kohn-Sham matrix.

        :param molecule:
            The molecule.
        :param fock_mat:
            The Fock/Kohn-Sham matrix.
        :param oao_mat:
            The orthogonalization matrix.

        :return:
            The molecular orbitals.
        """

        return MolecularOrbitals()

    def _apply_mom(self, molecule, ovl_mat):
        """
        Apply the maximum overlap constraint

        :param molecule:
            The molecule.
        :param ovl_mat:
            The overlap matrix..

        """
        if self.rank == mpi_master():
            smat = ovl_mat.to_numpy()

            mo_a = self.molecular_orbitals.alpha_to_numpy()
            ea = self.molecular_orbitals.ea_to_numpy()
            occ_a = self.molecular_orbitals.occa_to_numpy()
            N_alpha = molecule.number_of_alpha_electrons()

            ovl = np.dot(self._mom[0].transpose(),np.dot(smat,mo_a))
            argsort = np.argsort(np.sum(np.abs(ovl),0))[::-1]
            #restore energy ordering
            argsort[:N_alpha] = np.sort(argsort[:N_alpha])
            argsort[N_alpha:] = np.sort(argsort[N_alpha:])
            mo_a = mo_a[:,argsort]
            ea = ea[argsort]

            if self.scf_type == 'restricted':
                self._molecular_orbitals = MolecularOrbitals([mo_a], [ea], [occ_a],
                                                             molorb.rest)
            else:
                N_beta = molecule.number_of_beta_electrons()
                if self.scf_type == 'unrestricted':
                    mo_b = self.molecular_orbitals.beta_to_numpy()
                    eb = self.molecular_orbitals.eb_to_numpy()
                    occ_b = self.molecular_orbitals.occb_to_numpy()
                elif self.scf_type == 'restricted_openshell':
                    #For ROHF, the beta orbitals have to be a subset of the alpha
                    mo_b = mo_a[:,:N_alpha]

                ovl = np.dot(self._mom[1].transpose(),np.dot(smat,mo_b))
                argsort_b = np.argsort(np.sum(np.abs(ovl),0))[::-1]
                #restore energy ordering
                argsort_b[:N_beta] = np.sort(argsort_b[:N_beta])
                argsort_b[N_beta:] = np.sort(argsort_b[N_beta:])

                if self.scf_type == 'unrestricted':
                    mo_b = mo_b[:,argsort_b]
                    eb = eb[argsort_b]
                    self._molecular_orbitals = MolecularOrbitals([mo_a, mo_b],
                                                                 [ea, eb],
                                                                 [occ_a, occ_b],
                                                                 molorb.unrest)
                elif self.scf_type == 'restricted_openshell':
                    mo_a[:,:N_alpha] = mo_a[:,argsort_b]
                    ea[:N_alpha] = ea[argsort_b]
                    self._molecular_orbitals = MolecularOrbitals([mo_a], [ea], [occ_a],
                                                                 molorb.rest)

    def _update_mol_orbs_phase(self):
        """
        Updates phase of molecular orbitals.
        """

        if self.rank == mpi_master():
            if self._ref_mol_orbs is None:
                return

            ref_mo = self._ref_mol_orbs.alpha_to_numpy()
            mo = self.molecular_orbitals.alpha_to_numpy()
            ea = self.molecular_orbitals.ea_to_numpy()
            occa = self.molecular_orbitals.occa_to_numpy()

            for col in range(mo.shape[1]):
                if np.dot(mo[:, col], ref_mo[:, col]) < 0.0:
                    mo[:, col] *= -1.0

            if self.molecular_orbitals.get_orbitals_type() == molorb.rest:
                self._molecular_orbitals = MolecularOrbitals([mo], [ea], [occa],
                                                             molorb.rest)

            elif self.molecular_orbitals.get_orbitals_type() == molorb.unrest:
                ref_mo_b = self._ref_mol_orbs.beta_to_numpy()
                mo_b = self.molecular_orbitals.beta_to_numpy()
                eb = self.molecular_orbitals.eb_to_numpy()
                occb = self.molecular_orbitals.occb_to_numpy()

                for col in range(mo_b.shape[1]):
                    if np.dot(mo_b[:, col], ref_mo_b[:, col]) < 0.0:
                        mo_b[:, col] *= -1.0

                self._molecular_orbitals = MolecularOrbitals([mo, mo_b],
                                                             [ea, eb],
                                                             [occa, occb],
                                                             molorb.unrest)

    def _gen_new_density(self, molecule, scf_type):
        """
        Generates density matrix from current molecular orbitals.

        :param molecule:
            The molecule.
        :param scf_type:
            The type of SCF calculation (restricted, unrestricted, or
            restricted open-shell).

        :return:
            The density matrix.
        """

        if self.rank == mpi_master():
            return self.molecular_orbitals.get_density(molecule, scf_type)

        return AODensityMatrix()

    def _get_dyn_threshold(self, e_grad):
        """
        Computes screening threshold for electron repulsion integrals based on
        value of electronic gradient.

        :param e_grad:
            The electronic gradient.

        :return:
            The screening threshold.
        """

        if e_grad < 1.0e-6:
            return self.eri_thresh

        nteri = math.pow(10, math.floor(math.log10(e_grad)))

        nteri = 1.0e-10 * nteri

        if nteri > 1.0e-10:
            return 1.0e-10

        if nteri < self.eri_thresh:
            return self.eri_thresh

        return nteri

    def _check_convergence(self):
        """
        Sets SCF convergence flag by checking if convergence condition for
        electronic gradient is fullfiled.
        """

        self._is_converged = False

        if self._num_iter > 0:

            e_grad = self._iter_data['gradient_norm']

            if e_grad < self.conv_thresh:
                self._is_converged = True

    def _get_scf_range(self):
        """
        Creates range of SCF iterations from maximum number of SCF iterations.

        :return:
            The range of SCF iterations.
        """

        # set the maximum number of SCF iterations
        # (note the extra SCF cycle when starting from scratch)
        if self.restart:
            return range(self.max_iter)
        else:
            return range(self.max_iter + 1)

    def _print_scf_energy(self):
        """
        Prints SCF energy information to output stream.
        """

        valstr = self.get_scf_type_str() + ':'
        self.ostream.print_header(valstr.ljust(92))
        self.ostream.print_header(('-' * len(valstr)).ljust(92))
        self._print_energy_components()

        if self._pe:
            self.ostream.print_blank()
            for line in self._pe_summary.splitlines():
                self.ostream.print_header(line.ljust(92))
            self.ostream.flush()

    def _print_header(self):
        """
        Prints SCF calculation setup details to output stream,
        """

        self.ostream.print_blank()
        self.ostream.print_header('Self Consistent Field Driver Setup')
        self.ostream.print_header(36 * '=')
        self.ostream.print_blank()

        str_width = 84
        cur_str = 'Wave Function Model             : ' + self.get_scf_type_str()
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Initial Guess Model             : ' + self._get_guess_type()
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = 'Convergence Accelerator         : ' + self._get_acc_type()
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Max. Number of Iterations       : ' + str(self.max_iter)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Max. Number of Error Vectors    : ' + str(self.max_err_vecs)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Convergence Threshold           : {:.1e}'.format(
            self.conv_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = 'ERI Screening Scheme            : ' + get_qq_type(
            self.qq_type)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'ERI Screening Mode              : ' + self._get_qq_dyn()
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'ERI Screening Threshold         : {:.1e}'.format(
            self.eri_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Linear Dependence Threshold     : {:.1e}'.format(
            self.ovl_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))

        if self._dft:
            cur_str = 'Exchange-Correlation Functional : '
            cur_str += self.xcfun.get_func_label().upper()
            self.ostream.print_header(cur_str.ljust(str_width))
            cur_str = 'Molecular Grid Level            : ' + str(
                self.grid_level)
            self.ostream.print_header(cur_str.ljust(str_width))

        if self.electric_field is not None:
            cur_str = 'Static Electric Field           : '
            cur_str += str(self.electric_field)
            self.ostream.print_header(cur_str.ljust(str_width))

        self.ostream.print_blank()

    def _print_scf_title(self):
        """
        Prints SCF cycles header to output stream.
        """

        if self._first_step:
            self.ostream.print_info('Starting Reduced Basis SCF calculation...')

        else:
            self.ostream.print_blank()
            if self._dft:
                valstr = '{} | {} | {} | {} | {} | {}'.format(
                    'Iter.', '   Kohn-Sham Energy', 'Energy Change',
                    'Gradient Norm', 'Max. Gradient', 'Density Change')
                self.ostream.print_header(valstr)
            else:
                valstr = '{} | {} | {} | {} | {} | {}'.format(
                    'Iter.', 'Hartree-Fock Energy', 'Energy Change',
                    'Gradient Norm', 'Max. Gradient', 'Density Change')
                self.ostream.print_header(valstr)
            self.ostream.print_header(92 * '-')

    def _print_scf_finish(self, start_time):
        """
        Prints SCF calculation finish message to output stream,

        :param start_time:
            The start time of SCF calculation.
        """

        if self._first_step:
            valstr = '...done. SCF energy in reduced basis set: '
            valstr += '{:.12f}'.format(self._scf_energy)
            valstr += ' a.u. Time: '
            valstr += '{:.2f}'.format(tm.time() - start_time) + ' sec.'
            self.ostream.print_info(valstr)
            self.ostream.print_blank()

        else:
            valstr = '*** SCF '
            if self.is_converged:
                valstr += 'converged in '
            else:
                valstr += 'NOT converged in '
            valstr += str(self._num_iter)
            valstr += ' iterations. Time: '
            valstr += '{:.2f}'.format(tm.time() - start_time) + ' sec.'
            self.ostream.print_blank()
            self.ostream.print_header(valstr.ljust(92))
            self.ostream.print_blank()

        self.ostream.flush()

    def _print_iter_data(self, i):
        """
        Prints SCF iteration data to output stream,

        :param i:
            The current SCF iteration.
        """

        if self.rank == mpi_master():
            # no output for first step in two level DIIS
            if self._first_step:
                return

            # DIIS or second step in two level DIIS
            if self._num_iter > 0:

                if self._iter_data:
                    te = self._iter_data['energy']
                    diff_te = self._iter_data['diff_energy']
                    e_grad = self._iter_data['gradient_norm']
                    max_grad = self._iter_data['max_gradient']
                    diff_den = self._iter_data['diff_density']

                if self._num_iter == 1:
                    diff_te = 0.0
                    diff_den = 0.0

                valstr = ' {:3d}   {:20.12f} {:15.10f} '.format(
                    self._num_iter, te, diff_te)
                valstr += '{:15.8f} {:15.8f} {:15.8f} '.format(
                    e_grad, max_grad, diff_den)

                self.ostream.print_header(valstr)
                self.ostream.flush()

    def get_scf_energy(self):
        """
        Gets SCF energy from previous SCF iteration.

        :return:
            The SCF energy.
        """

        return self._scf_energy

    def get_scf_type_str(self):
        """
        Gets string with type of SCF calculation (defined in derrived classes).

        :return:
            The string with type of SCF calculation.
        """

        return 'Undefined'

    def _get_guess_type(self):
        """
        Gets string with type of initial guess (superposition of atomic
        densities or projection of molecular orbitals).

        :return:
            The string with type of initial guess.
        """

        if self._den_guess.guess_type == 'SAD':
            return 'Superposition of Atomic Densities'

        if self._den_guess.guess_type == 'RESTART':
            return 'Restart from Checkpoint'

        return 'Undefined'

    def _get_acc_type(self):
        """
        Gets string with type of SCF convergence accelerator (DIIS or two level
        DIIS).

        :return:
            The string with type of SCF convergence accelerator.
        """

        if self.acc_type == 'DIIS':
            return 'Direct Inversion of Iterative Subspace'

        if self.acc_type == 'L2_DIIS':
            return 'Two Level Direct Inversion of Iterative Subspace'

        return 'Undefined'

    def _get_qq_dyn(self):
        """
        Gets string with application method (static or dynamic) of electron
        repulsion integrals screening.

        :return:
            The string with application method of electron repulsion integrals
            screening.
        """

        if self.qq_dyn:
            return 'Dynamic'

        return 'Static'

    def _update_fock_type(self, fock_mat):
        """
        Updates Fock matrix to fit selected functional in Kohn-Sham
        calculations.

        :param fock_mat:
            The Fock/Kohn-Sham matrix.
        """

        return

    def _delete_mos(self, mol_orbs, mol_eigs):
        """
        Generates trimmed molecular orbital by deleting MOs with coeficients
        exceeding 1.0 / sqrt(ovl_thresh).

        :param mol_orbs:
            The molecular orbitals.
        :param mol_eigs:
            The eigenvalues of molecular orbitals.

        :return:
            The tuple (trimmed molecular orbitals, eigenvalues).
        """

        fmax = 1.0 / math.sqrt(self.ovl_thresh)

        mvec = np.amax(np.abs(mol_orbs), axis=0)

        molist = []
        for i in range(mvec.shape[0]):
            if mvec[i] < fmax:
                molist.append(i)

        return (mol_orbs[:, molist], mol_eigs[molist])

    def compute_s2(self, molecule, scf_tensors):
        """
        Computes expectation value of the S**2 operator.

        :param molecule:
            The molecule.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.

        :return:
            Expectation value <S**2>.
        """

        nalpha = molecule.number_of_alpha_electrons()
        nbeta = molecule.number_of_beta_electrons()

        smat = scf_tensors['S']
        Cocc_a = scf_tensors['C_alpha'][:, :nalpha]
        Cocc_b = scf_tensors['C_beta'][:, :nbeta]

        a_b = float(nalpha - nbeta) / 2.0
        s2_exact = a_b * (a_b + 1.0)

        ovl_a_b = np.matmul(Cocc_a.T, np.matmul(smat, Cocc_b))
        s2 = s2_exact + nbeta - np.sum(ovl_a_b**2)

        return s2

    def _print_ground_state(self, molecule, s2):
        """
        Prints ground state information to output stream.

        :param molecule:
            The molecule.
        :param s2:
            The expectation value of S**2.
        """

        self.ostream.print_blank()

        self.ostream.print_header('Ground State Information'.ljust(92))
        self.ostream.print_header('------------------------'.ljust(92))

        chg = molecule.get_charge()
        valstr = 'Charge of Molecule            :{:5.1f}'.format(chg)
        self.ostream.print_header(valstr.ljust(92))

        mult = molecule.get_multiplicity()
        if self.scf_type == 'restricted':
            valstr = 'Multiplicity (2S+1)           :{:5.1f}'.format(mult)
            self.ostream.print_header(valstr.ljust(92))

        sz = 0.5 * (mult - 1.0)
        valstr = 'Magnetic Quantum Number (M_S) :{:5.1f}'.format(sz)
        self.ostream.print_header(valstr.ljust(92))

        if self.scf_type in ['unrestricted', 'restricted_openshell']:
            valstr = 'Expectation value of S**2     :{:8.4f}'.format(s2)
            self.ostream.print_header(valstr.ljust(92))

        self.ostream.print_blank()

    def _print_energy_components(self):
        """
        Prints SCF energy components to output stream.
        """

        enuc = self._nuc_energy

        e_d4 = self._d4_energy

        e_ef_nuc = self._ef_nuc_energy

        etot = self._iter_data['energy']

        e_el = etot - enuc - e_d4 - e_ef_nuc

        valstr = f'Total Energy                       :{etot:20.10f} a.u.'
        self.ostream.print_header(valstr.ljust(92))

        valstr = f'Electronic Energy                  :{e_el:20.10f} a.u.'
        self.ostream.print_header(valstr.ljust(92))

        valstr = f'Nuclear Repulsion Energy           :{enuc:20.10f} a.u.'
        self.ostream.print_header(valstr.ljust(92))

        if self.dispersion:
            valstr = f'D4 Dispersion Correction           :{e_d4:20.10f} a.u.'
            self.ostream.print_header(valstr.ljust(92))

        if self.electric_field is not None:
            valstr = f'Nuclei in Static Electric Field    :{e_ef_nuc:20.10f} a.u.'
            self.ostream.print_header(valstr.ljust(92))

        self.ostream.print_header(
            '------------------------------------'.ljust(92))

        grad = self._iter_data['gradient_norm']
        valstr = 'Gradient Norm                      :{:20.10f} a.u.'.format(
            grad)
        self.ostream.print_header(valstr.ljust(92))

        self.ostream.print_blank()

        if self.dispersion:
            valstr = '*** Reference for D4 dispersion correction: '
            self.ostream.print_header(valstr.ljust(92))
            valstr = 'E. Caldeweyher, S. Ehlert, A. Hansen, H. Neugebauer, '
            valstr += 'S. Spicher, C. Bannwarth'
            self.ostream.print_header(valstr.ljust(92))
            valstr = 'and S. Grimme, J. Chem Phys, 2019, 150, 154122.'
            self.ostream.print_header(valstr.ljust(92))

    def _write_final_hdf5(self, molecule, ao_basis):
        """
        Writes final HDF5 that contains SCF tensors.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """

        if self.checkpoint_file is None:
            return

        final_h5_fname = str(
            Path(self.checkpoint_file).with_suffix('.tensors.h5'))

        if self._dft:
            xc_label = self.xcfun.get_func_label()
        else:
            xc_label = 'HF'

        if self._pe:
            with open(str(self.pe_options['potfile']), 'r') as f_pot:
                potfile_text = '\n'.join(f_pot.readlines())
        else:
            potfile_text = ''

        create_hdf5(final_h5_fname, molecule, ao_basis, xc_label, potfile_text)
        write_scf_tensors(final_h5_fname, self.scf_tensors)

        self.ostream.print_blank()
        checkpoint_text = 'SCF tensors written to file: '
        checkpoint_text += final_h5_fname
        self.ostream.print_info(checkpoint_text)
