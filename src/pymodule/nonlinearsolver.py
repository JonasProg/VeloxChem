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
import numpy as np
import time as tm

from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import GridDriver
from .veloxchemlib import MolecularGrid
from .veloxchemlib import mpi_master
from .veloxchemlib import denmat
from .veloxchemlib import fockmat
from .veloxchemlib import XCFunctional
from .aodensitymatrix import AODensityMatrix
from .aofockmatrix import AOFockMatrix
from .linearsolver import LinearSolver
from .distributedarray import DistributedArray
from .errorhandler import assert_msg_critical
from .inputparser import parse_input, print_keywords, get_datetime_string
from .qqscheme import get_qq_scheme
from .batchsize import get_batch_size
from .batchsize import get_number_of_batches
from .veloxchemlib import new_parse_xc_func
from .veloxchemlib import XCNewIntegrator


class NonLinearSolver:
    """
    Implements nonlinear solver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - eri_thresh: The electron repulsion integrals screening threshold.
        - qq_type: The electron repulsion integrals screening scheme.
        - batch_size: The batch size for computation of Fock matrices.
        - dft: The flag for running DFT.
        - grid_level: The accuracy level of DFT grid.
        - xcfun: The XC functional.
        - electric_field: The static electric field.
        - conv_thresh: The convergence threshold for the solver.
        - max_iter: The maximum number of solver iterations.
        - lindep_thresh: The threshold for removing linear dependence in the
          trial vectors.
        - is_converged: The flag for convergence.
        - comm: The MPI communicator.
        - rank: The MPI rank.
        - nodes: Number of MPI processes.
        - ostream: The output stream.
        - restart: The flag for restarting from checkpoint file.
        - checkpoint_file: The name of checkpoint file.
        - timing: The flag for printing timing information.
        - profiling: The flag for printing profiling information.
        - memory_profiling: The flag for printing memory usage.
        - memory_tracing: The flag for tracing memory allocation.
        - filename: The filename.
        - program_end_time: The end time of the program.
    """

    def __init__(self, comm, ostream):
        """
        Initializes linear solver to default setup.
        """

        # ERI settings
        self.eri_thresh = 1.0e-15
        self.qq_type = 'QQ_DEN'
        self.batch_size = None

        # dft
        self._dft = False
        self.xcfun = None
        self.grid_level = 4

        # polarizable embedding
        self.potfile = None

        # static electric field
        self.electric_field = None

        # solver setup
        self.conv_thresh = 1.0e-4
        self.max_iter = 150
        self.lindep_thresh = 1.0e-6
        self._is_converged = False

        # mpi information
        self._comm = comm
        self._rank = self._comm.Get_rank()
        self._nodes = self._comm.Get_size()

        # output stream
        self._ostream = ostream

        # restart information
        self.restart = True
        self.checkpoint_file = None

        # timing and profiling
        self.timing = False
        self.profiling = False
        self.memory_profiling = False
        self.memory_tracing = False

        # program end time for graceful exit
        self.program_end_time = None

        # filename
        self._filename = f'veloxchem_rsp_{get_datetime_string()}'

        # input keywords
        self._input_keywords = {
            'response': {
                'eri_thresh': ('float', 'ERI screening threshold'),
                'qq_type': ('str_upper', 'ERI screening scheme'),
                'batch_size': ('int', 'batch size for Fock build'),
                'max_iter': ('int', 'maximum number of iterations'),
                'conv_thresh': ('float', 'convergence threshold'),
                'lindep_thresh': ('float', 'threshold for linear dependence'),
                'restart': ('bool', 'restart from checkpoint file'),
                'checkpoint_file': ('str', 'name of checkpoint file'),
                'timing': ('bool', 'print timing information'),
                'profiling': ('bool', 'print profiling information'),
                'memory_profiling': ('bool', 'print memory usage'),
                'memory_tracing': ('bool', 'trace memory allocation'),
            },
            'method_settings': {
                'xcfun': ('str_upper', 'exchange-correlation functional'),
                'grid_level': ('int', 'accuracy level of DFT grid'),
                'potfile': ('str', 'potential file for polarizable embedding'),
                'electric_field': ('seq_fixed', 'static electric field'),
            },
        }

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
        Returns whether linear solver is converged.
        """

        return self._is_converged

    def print_keywords(self):
        """
        Prints input keywords in nonlinear solver.
        """

        print_keywords(self._input_keywords, self.ostream)

    def update_settings(self, rsp_dict, method_dict=None):
        """
        Updates response and method settings in nonlinear solver.

        :param rsp_dict:
            The dictionary of response input.
        :param method_dict:
            The dictionary of method settings.
        """

        if method_dict is None:
            method_dict = {}

        self.method_dict = dict(method_dict)

        rsp_keywords = {
            key: val[0]
            for key, val in self._input_keywords['response'].items()
        }

        parse_input(self, rsp_keywords, rsp_dict)

        if 'program_end_time' in rsp_dict:
            self.program_end_time = rsp_dict['program_end_time']
        if 'filename' in rsp_dict:
            self._filename = rsp_dict['filename']
            if 'checkpoint_file' not in rsp_dict:
                self.checkpoint_file = f'{self._filename}.rsp.h5'

        method_keywords = {
            key: val[0]
            for key, val in self._input_keywords['method_settings'].items()
        }

        parse_input(self, method_keywords, method_dict)

        self._dft_sanity_check()

        if self.potfile is not None:
            errmsg = 'NonLinearSolver: The \'potfile\' keyword is not supported '
            errmsg += 'in nonlinear response calculation.'
            if self.rank == mpi_master():
                assert_msg_critical(False, errmsg)

        if self.electric_field is not None:
            errmsg = 'NonLinearSolver: The \'electric field\' keyword is not '
            errmsg += 'supported in nonlinear response calculation.'
            if self.rank == mpi_master():
                assert_msg_critical(False, errmsg)

    def _dft_sanity_check(self):
        """
        Checks DFT settings and updates relevant attributes.
        """

        # check xc functional
        if self.xcfun is not None:
            if isinstance(self.xcfun, str):
                self.xcfun = new_parse_xc_func(self.xcfun.upper())
            assert_msg_critical(not self.xcfun.is_undefined(),
                                'NonLinearSolver: Undefined XC functional')
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

    def _init_eri(self, molecule, basis):
        """
        Initializes ERI.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.

        :return:
            The dictionary of ERI information.
        """

        eri_drv = ElectronRepulsionIntegralsDriver(self.comm)
        screening = eri_drv.compute(get_qq_scheme(self.qq_type),
                                    self.eri_thresh, molecule, basis)

        return {
            'screening': screening,
        }

    def _init_dft(self, molecule, scf_tensors):
        """
        Initializes DFT.

        :param molecule:
            The molecule.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.

        :return:
            The dictionary of DFT information.
        """

        if self._dft:
            grid_drv = GridDriver(self.comm)
            grid_drv.set_level(self.grid_level)

            grid_t0 = tm.time()
            molgrid = grid_drv.generate(molecule)
            n_grid_points = molgrid.number_of_points()
            self.ostream.print_info(
                'Molecular grid with {0:d} points generated in {1:.2f} sec.'.
                format(n_grid_points,
                       tm.time() - grid_t0))
            self.ostream.print_blank()

            if self.rank == mpi_master():
                gs_density = AODensityMatrix([scf_tensors['D_alpha']],
                                             denmat.rest)
            else:
                gs_density = AODensityMatrix()
            gs_density.broadcast(self.rank, self.comm)

            dft_func_label = self.xcfun.get_func_label().upper()
        else:
            molgrid = MolecularGrid()
            gs_density = AODensityMatrix()
            dft_func_label = 'HF'

        return {
            'molgrid': molgrid,
            'gs_density': gs_density,
            'dft_func_label': dft_func_label,
        }

    def compute(self, molecule, basis, scf_tensors):
        """
        Solves for the nonlinear response functions.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.

        :return:
            A dictionary containing response functions, solutions, etc.
        """

        return None

    def _comp_nlr_fock(self,
                       mo,
                       molecule,
                       ao_basis,
                       fock_flag,
                       dft_dict,
                       first_order_dens,
                       second_order_dens,
                       third_oder_dens,
                       mode,
                       profiler=None):
        """
        Computes and returns a list of Fock matrices.

        :param mo:
            The MO coefficients
        :param D:
            A list of densities
        :param molecule:
            The molecule
        :param ao_basis:
            The AO basis set
        :param fock_flag:
            The type of Fock matrices
        :param dft_dict:
            The dictionary containing DFT information
        :param first_order_dens:
            A list of first order densitiy matrices
        :param second_order_dens:
            A list of second order densitiy matrices
        :param mode:
            The mode for densities in quadratic response
        :param profiler:
            The profiler

        :return:
            A list of Fock matrices
        """

        f_total = self._comp_two_el_int(mo, molecule, ao_basis, dft_dict,
                                        first_order_dens, second_order_dens,third_oder_dens,
                                        mode, profiler)
        nrows = f_total.data.shape[0]
        half_ncols = f_total.data.shape[1] // 2
        ff_data = np.zeros((nrows, half_ncols), dtype='complex128')
        if fock_flag == 'real_and_imag':
            for i in range(half_ncols):
                ff_data[:, i] = (f_total.data[:, 2 * i] +
                                 1j * f_total.data[:, 2 * i + 1])
            return DistributedArray(ff_data, self.comm, distribute=False)
        elif fock_flag == 'real':
            return f_total
        else:
            return None

    def _comp_two_el_int(self,
                         mo,
                         molecule,
                         ao_basis,
                         dft_dict,
                         first_order_dens,
                         second_order_dens,
                         third_order_dens,
                         mode,
                         profiler=None):
        """
        Computes the two-electron (HF) and vxc part of the two and three-time perturbed Fock matrices

        :param mo:
            The MO coefficients
        :param molecule:
            The molecule
        :param ao_basis:
            The AO basis set
        :param dft_dict:
            The dictionary containing DFT information
        :param first_order_dens:
            A list of first-order densitiy matrices
        :param second_order_dens:
            A list of second-order densitiy matrices
        :param third_order_dens:
            A list of third-order densitiy matrices
        :param mode:
            The mode for densities in quadratic/cubic response
        :param profiler:
            The profiler.

        :return:
            A tuple containing the two-electron part of the Fock matix (in MO
            basis)
        """

        if profiler is not None:
            profiler.set_timing_key('Nonlinear Fock')

        eri_driver = ElectronRepulsionIntegralsDriver(self.comm)
        screening = eri_driver.compute(get_qq_scheme(self.qq_type),self.eri_thresh, molecule, ao_basis)

        # determine number of batches

        if self.rank == mpi_master():
            if mode.lower() in ['crf' ,'tpa']:
                n_total = len(third_order_dens)
                n_ao = third_order_dens[0].shape[0]
            else:
                n_total = len(second_order_dens)
                n_ao = second_order_dens[0].shape[0]
            norb = mo.shape[1]
        else:
            n_total = None
            n_ao = None

        batch_size = get_batch_size(self.batch_size, n_total, n_ao, self.comm)
        num_batches = get_number_of_batches(n_total, batch_size, self.comm)

        # double-check batch size for DFT

        if self._dft:
            if self.rank == mpi_master():
                if mode.lower() in ['crf' ,'tpa'] :
                    num_1 = len(first_order_dens)
                    num_2 = len(second_order_dens)
                    num_3 = len(third_order_dens)
                elif mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii','redtpa_i','redtpa_ii','crf_i','crf_ii','shg_red']:
                    num_1 = len(first_order_dens)
                    num_2 = len(second_order_dens)

                if mode.lower() == 'shg':
                    # 6 first-order densities per frequency
                    # 12 second-order densities per frequency
                    # see get_densities in shgdriver
                    size_1, size_2 = 6, 12
                elif mode.lower() == 'qrf':
                    # 4 first-order densities per frequency
                    # 2 second-order densities per frequency
                    # see get_densities in quadraticresponsedriver
                    size_1, size_2 = 4, 2
                elif mode.lower() == 'crf':
                     # 6 first-order densities per frequency
                     # 6 second-order densities per frequency
                     # 2 third-order densities per frequency
                     size_1, size_2, size_3 = 6, 6, 2
                elif mode.lower() == 'tpa':
                     # 12 first-order densities per frequency
                     # 24 second-order densities per frequency
                     # 6 third-order densities per frequency
                     size_1, size_2, size_3 = 12, 24, 6
                elif mode.lower() == 'tpa_i':
                     # 12 first-order densities per frequency
                     # 24 second-order densities per frequency
                     size_1, size_2 = 12, 24
                elif mode.lower() == 'tpa_ii':
                     # 36 first-order densities per frequency
                     # 6 second-order densities per frequency
                     size_1, size_2 = 36, 6
                elif mode.lower() == 'redtpa_i':
                     # 36 first-order densities per frequency
                     # 6 second-order densities per frequency
                     size_1, size_2 = 18, 6
                elif mode.lower() == 'redtpa_ii':
                     # 36 first-order densities per frequency
                     # 6 second-order densities per frequency
                     size_1, size_2 = 18, 6
                elif mode.lower() == 'crf_i':
                     # 36 first-order densities per frequency
                     # 6 second-order densities per frequency
                     size_1, size_2 = 6, 6
                elif mode.lower() == 'crf_ii':
                     # 12 first-order densities per frequency
                     # 6 second-order densities per frequency
                     size_1, size_2 = 12, 6
                elif mode.lower() == 'shg_red':
                    # 6 first-order densities
                    # 6 second-order densities
                    # see get_densities in shgdriver
                    size_1, size_2 = 6, 6

                # condition = ((num_1 % size_1 == 0) and (num_2 % size_2 == 0) and
                #              (num_1 // size_1 == num_2 // size_2))

                if mode.lower() in ['crf', 'tpa']:
                    
                    batch_size = max((batch_size // size_3) * size_3, size_3)

                    batch_size_second_order = (batch_size // size_3) * size_2

                    batch_size_first_order = (batch_size // size_3) * size_1

                else:

                    batch_size = max((batch_size // size_2) * size_2, size_2)

                    batch_size_first_order = (batch_size // size_2) * size_1

                # errmsg = 'NonLinearSolver._comp_nlr_fock: '
                # errmsg += f'inconsistent number of density matrices (mode={mode})'
                # assert_msg_critical(condition, errmsg)
            else:
                batch_size = None
                batch_size_first_order = None
                batch_size_second_order = None

            batch_size = self.comm.bcast(batch_size, root=mpi_master())
            batch_size_first_order = self.comm.bcast(batch_size_first_order,
                                                     root=mpi_master())
            num_batches = get_number_of_batches(n_total, batch_size, self.comm)

        # go through batches

        dist_fabs = None

        if self.rank == mpi_master():
            batch_str = 'Processing Fock builds...'
            batch_str += ' (batch size: {:d})'.format(batch_size)
            self.ostream.print_info(batch_str)

        # for batch_ind in range(num_batches):

        # if self.rank == mpi_master():
        #         self.ostream.print_info('  batch {}/{}'.format(batch_ind + 1, num_batches))
        #         self.ostream.flush()

        if self.rank == mpi_master():
            if self._dft:
                # batch_start_first_order = batch_size_first_order * batch_ind
                # batch_end_first_order = min(batch_start_first_order + batch_size_first_order,len(first_order_dens))

                #  One,two and three-time perturbed Fock matrices all use one-time perturbed densities
                dts1 = [np.ascontiguousarray(dab) for dab in first_order_dens]
                dens1 = AODensityMatrix(dts1, denmat.rest)

                if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii', 'redtpa_i','redtpa_ii' ,'crf_i','crf_ii','shg_red']:
                    # If computing two-time perturbed Fock matrices (DFT) then include first and second-order perturbed densities
                    # batch_start = batch_size * batch_ind
                    # batch_end = min(batch_start + batch_size, n_total) 

                    dts2 = [np.ascontiguousarray(dab)for dab in second_order_dens]
                    dens2 = AODensityMatrix(dts2, denmat.rest)

                elif mode.lower() in ['crf','tpa']:
                    # If computing three-time perturbed Fock matrices (DFT) then include first,second and third-order perturbed densities
                    # batch_start_second_order = batch_size_second_order * batch_ind
                    # batch_end_second_order = min(batch_start_second_order + batch_size_second_order,len(second_order_dens))
                    # batch_start = batch_size * batch_ind
                    # batch_end = min(batch_start + batch_size, n_total)

                    dts2 = [np.ascontiguousarray(dab) for dab in second_order_dens]
                    dens2 = AODensityMatrix(dts2, denmat.rest)
                    dts3 = [np.ascontiguousarray(dab) for dab in third_order_dens]
                    dens3 = AODensityMatrix(dts3, denmat.rest)
                    dts4 = dts2 + dts3
                    dens4 = AODensityMatrix(dts4, denmat.rest)

            else:
                # If HF on MPI_master
                if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii', 'redtpa_i','redtpa_ii' ,'crf_i','crf_ii','shg_red']:
                    # If computing two-time perturbed Fock matrices at HF level only second-order perturbed densities are needed
                    # batch_start = batch_size * batch_ind
                    # batch_end = min(batch_start + batch_size, n_total) 
                    dts2 = [np.ascontiguousarray(dab)for dab in second_order_dens]
                    dens2 = AODensityMatrix(dts2, denmat.rest)

                elif mode.lower() in ['crf','tpa']:
                    # If computing three-time perturbed Fock matrices at HF level only third-order perturbed densities are needed
                    # batch_start = batch_size * batch_ind
                    # batch_end = min(batch_start + batch_size, n_total) 
                    dts3 = [np.ascontiguousarray(dab) for dab in third_order_dens]
                    dens3 = AODensityMatrix(dts3, denmat.rest)
        else:
            # If not MPI master 
            if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii','redtpa_i','redtpa_ii','crf_i','crf_ii','shg_red']:
                dens2 = AODensityMatrix()
                if self._dft:
                    # for dft we also need dens 1 for quadratic contribution
                    dens1 = AODensityMatrix()
            elif mode.lower() in ['crf','tpa']:
                dens3 = AODensityMatrix()
                dens4 = AODensityMatrix()
                if self._dft: 
                    # for dft we also need dens1 and dens 2 for cubic contributions
                    dens1 = AODensityMatrix()
                    dens2 = AODensityMatrix()

        # Construct Fock matrix object for two-time transformed Fock matrices 
        if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii','redtpa_i','redtpa_ii','crf_i','crf_ii','shg_red']:
            # For two-time perturbed Fock matrices we have as many Fock matrices as len dens2
            dens2.broadcast(self.rank, self.comm)
            fock = AOFockMatrix(dens2)
            if self._dft:
                dens1.broadcast(self.rank, self.comm)

        # Construct Fock matrix object for three-time transformed Fock matrices 
        elif mode.lower() in ['crf','tpa']:
            dens3.broadcast(self.rank, self.comm)
            # For  three-time perturbed Fock matrices we have as many Fock matrices as len dens3 
            if self._dft:
                dens4.broadcast(self.rank, self.comm)
                fock = AOFockMatrix(dens4)
                dens1.broadcast(self.rank, self.comm)
                dens2.broadcast(self.rank, self.comm)
            else:
                fock = AOFockMatrix(dens3)

            
        fock_flag = fockmat.rgenjk
        if self._dft:
            if self.xcfun.is_hybrid():
                fock_flag = fockmat.rgenjkx
                fact_xc = self.xcfun.get_frac_exact_exchange()
                for i in range(fock.number_of_fock_matrices()):
                    fock.set_scale_factor(fact_xc, i)
            else:
                fock_flag = fockmat.rgenj

        for i in range(fock.number_of_fock_matrices()):
            fock.set_fock_type(fock_flag, i)

        t0 = tm.time()

        # Compute HF/two-electron part of two-time perturbed Fock matrices
        if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii','redtpa_i','redtpa_ii','crf_i','crf_ii','shg_red']:
            # For two-time perturbed Fock matrix, the two-electron (HF) part is only contracted with dens2
            eri_driver.compute(fock, dens2, molecule, ao_basis, screening)

        # Compute HF/two-electron part of three-time perturbed Fock matrices
        elif mode.lower() in ['crf','tpa']:
            # For three-time perturbed Fock matrix, the two-electron (HF) part is only contracted with dens3
            if self._dft:
                eri_driver.compute(fock, dens4, molecule, ao_basis, screening)
            else:
                eri_driver.compute(fock, dens3, molecule, ao_basis, screening)
            

        if self._dft and not self.xcfun.is_hybrid():
            for ifock in range(fock.number_of_fock_matrices()):
                fock.scale(2.0, ifock)

        if profiler is not None:
            profiler.add_timing_info('FockERI', tm.time() - t0)

        if self._dft:
            t0 = tm.time()

            xc_drv = XCNewIntegrator(self.comm)
            molgrid = dft_dict['molgrid']
            gs_density = dft_dict['gs_density']

            molgrid.partition_grid_points()
            molgrid.distribute_counts_and_displacements(
                self.rank, self.nodes, self.comm)

            if mode.lower() in ['qrf','shg','tpa_i', 'tpa_ii','redtpa_i','redtpa_ii','crf_i','crf_ii','shg_red']:
                # Compute vxc contribution for two-time transformed Fock matrics
                xc_drv.integrate_kxc_fock(fock, molecule, ao_basis, dens1,dens2, gs_density, molgrid,self.xcfun.get_func_label(), mode)

            elif mode.lower() in ['crf','tpa']:
                # Compute vxc contribution for three-time transformed Fock matrics
                xc_drv.integrate_kxclxc_fock(fock, molecule, ao_basis, dens1, dens2, dens3, gs_density, molgrid,self.xcfun.get_func_label(), mode)

            if profiler is not None:
                profiler.add_timing_info('FockXC', tm.time() - t0)

        fock.reduce_sum(self.rank, self.nodes, self.comm)

        t0 = tm.time()

        if self.rank == mpi_master():
            nfocks = fock.number_of_fock_matrices()
            fock_mo = np.zeros((norb**2, nfocks))
            for i in range(nfocks):
                fock_mo[:, i] = self.ao2mo(mo,
                                            fock.to_numpy(i).T).reshape(-1)
        else:
            fock_mo = None

        if profiler is not None:
            profiler.add_timing_info('AOtoMO', tm.time() - t0)

        dist_fock_mo = DistributedArray(fock_mo, self.comm)

        if dist_fabs is None:
            dist_fabs = DistributedArray(dist_fock_mo.data,
                                            self.comm,
                                            distribute=False)
        else:
            dist_fabs.append(dist_fock_mo, axis=1)

        self.ostream.print_blank()

        return dist_fabs

    @staticmethod
    def flip_yz(X):
        """
        This method takes a first-order response vector with a given sign of
        the frequency and returns the first-order response vector with reversed
        frequency argument.

        :param X:
            A response vector N(ω,x) = (Z,-Y^*)

        :return:
            A response vector with reversed optical frequency N(-ω,x) =
            (Y,-Z^*)
        """

        if X.ndim == 1:
            new_yz = np.zeros_like(X)
            half_len = X.shape[0] // 2
            new_yz[:half_len] = -X.real[half_len:] + 1j * X.imag[half_len:]
            new_yz[half_len:] = -X.real[:half_len] + 1j * X.imag[:half_len]
            return new_yz

        return None

    def _print_fock_header(self):
        """
        Prints header for Fock computation
        """

        title = 'Fock Matrix Computation'
        self.ostream.print_header(title)
        self.ostream.print_header('=' * (len(title) + 2))
        self.ostream.print_blank()

    def _print_fock_time(self, time):
        """
        Prints time for Fock computation

        :param time:
            Total time to compute Fock matrices
        """

        cur_str = 'Time spent in Fock matrices: {:.2f} sec'.format(time)
        self.ostream.print_info(cur_str)
        self.ostream.print_blank()
        self.ostream.flush()

    def _s4(self, k1, k2, k3, D, nocc, norb):
        """
        Used for the contraction of the S[4] tensor with three response vectors

        :param k1:
            A response matrix
        :param k2:
            A response matrix
        :param k3:
            A response matrix
        :param D:
            A density matrix
        :param nocc:
            The number of occupied orbtials
        :param norb:
            The number of total orbitals

        :return:
            The contraction of S[4] for S[4] dict
        """

        S4_123 = self._s4_contract(k1, k2, k3, D, nocc, norb)
        S4_132 = self._s4_contract(k1, k3, k2, D, nocc, norb)

        return S4_123 + S4_132

    def _s4_contract(self, k1, k2, k3, D, nocc, norb):
        """
        Returns the contraction of the S[4] tensor 

        :param k1:
            A response matrix
        :param k2:
            A response matrix
        :param k3:
            A response matrix
        :param D:
            A density matrix
        :param nocc:
            The number of occupied orbtials
        :param norb:
            The number of total orbitals

        :return:
            The contraction of S[4] for S[4] dict
        """

        S4N1N2N3 = self.commut(self.commut(k3, self.commut(k2, k1)), D.T)
        S4N1N2N3_c = self.complex_lrmat2vec(S4N1N2N3, nocc, norb)
        return (2. / 6) * S4N1N2N3_c

    @staticmethod
    def flip_xy(X):
        """
        Swaps upper and lower parts of a response vector.

        :param X:
            A response vector v = (Z,-Y^*)

        :return:
            A response vector of the form v' = (-Y^*,Z)
        """

        if X.ndim == 1:
            new_xy = np.zeros_like(X)
            half_len = X.shape[0] // 2
            new_xy[:half_len] = X[half_len:]
            new_xy[half_len:] = X[:half_len]
            return new_xy

        return None

    def _s4_for_r4(self, k1, k2, k3, D, nocc, norb):
        """
        Returns the contraction of S[4] for the contraction of R[4]

        :param k1:
            A response matrix
        :param k2:
            A response matrix
        :param k3:
            A response matrix
        :param D:
            A density matrix
        :param nocc:
            The number of occupied orbtials
        :param norb:
            The number of total orbitals

        :return:
            The contraction of S[4] for the contraction of R[4]
        """

        S4_123 = self._s4_contract(k1, k2, k3, D, nocc, norb)

        return S4_123

    def _collect_vectors_in_columns(self, sendbuf):
        """
        Collects vectors into 2d array (column-wise).

        :param sendbuf:
            The 2d array containing the vector segments in columns.

        :return:
            A 2d array containing the full vectors in columns.
        """

        counts = self.comm.gather(sendbuf.size, root=mpi_master())
        if self.rank == mpi_master():
            displacements = [sum(counts[:p]) for p in range(self.nodes)]
            recvbuf = np.zeros(sum(counts), dtype=sendbuf.dtype).reshape(
                -1, sendbuf.shape[1])
        else:
            displacements = None
            recvbuf = None

        if sendbuf.dtype == np.dtype('float64'):
            mpi_data_type = MPI.DOUBLE
        elif sendbuf.dtype == np.dtype('complex128'):
            mpi_data_type = MPI.C_DOUBLE_COMPLEX

        self.comm.Gatherv(sendbuf,
                          [recvbuf, counts, displacements, mpi_data_type],
                          root=mpi_master())

        return recvbuf

    @staticmethod
    def ao2mo(mo, A):
        """
        Transform a matrix to molecular basis

        :param mo:
            molecular orbital coefficent matrix
        :param A:
            The matrix in AO basis that is the converted to MO basis

        :return:
            The matrix in MO basis
        """

        return np.linalg.multi_dot([mo.T, A, mo])

    @staticmethod
    def commut_mo_density(A, nocc):
        """
        Commutes matrix A and MO density

        :param A:
            Matrix A.
        :param nocc:
            Number of occupied orbitals.

        :return:
            A D_mo - D_mo A
        """

        # | 0    -A_ov |
        # | A_vo  0    |

        mat = np.zeros(A.shape, dtype=A.dtype)
        mat[:nocc, nocc:] = -A[:nocc, nocc:]
        mat[nocc:, :nocc] = A[nocc:, :nocc]

        return mat

    @staticmethod
    def commut(A, B):
        """
        Commutes two matricies A and B

        :param A:
            Matrix A.
        :param B:
            Matrix B.

        :return:
            AB - BA
        """

        return np.matmul(A, B) - np.matmul(B, A)

    def _x3_contract(self, k1, k2, X, D, nocc, norb):
        """
        Contracts the generalized dipole gradient tensor of rank 3 with two
        first-order response matrices. X[3]N1N2 = (1/2)[[k2,[k1,X]],D.T]

        :param: k1:
            First-order response matrix
        :param: k2:
            First-order response matrix
        :param X:
            Dipole intergral matrix
        :param D:
            Density matrix
        :param nocc:
            Number of occupied orbitals
        :param norb:
            Number of total orbtials

        :return:
            Returns a matrix
        """

        X3NxNy = self.commut(self.commut(k2, self.commut(k1, X)), D.T)
        X3NxNy_c = self.complex_lrmat2vec(X3NxNy, nocc, norb)
        return (1. / 2) * X3NxNy_c

    def _x2_contract(self, k, X, D, nocc, norb):
        """
        Contracts the generalized dipole gradient tensor of rank 2 with a
        second-order response matrix. X[2]N1 = [[k1,X],D.T]

        :param: k:
            Respose vector in matrix representation
        :param X:
            Property operator in matrix represatiation
        :param D:
            Density matrix
        :param nocc:
            Number of occupied orbitals
        :param norb:
            Number of total orbtials

        :return:
            Returns a matrix
        """

        XNx = self.commut(self.commut(k, X), D.T)
        X2Nx_c = self.complex_lrmat2vec(XNx, nocc, norb)
        return X2Nx_c

    def _a2_contract(self, k, A, D, nocc, norb):
        """
        Contracts the generalized dipole gradient tensor of rank 2 with a
        second-order response matrix. A[2]N1 = -(1 / 2)[[k1,X],D.T]

        # Note that the sign needs further investigation.

        :param: k:
            Respose vector in matrix representation
        :param A:
            Property operator in matrix represatiation
        :param D:
            Density matrix
        :param nocc:
            Number of occupied orbitals
        :param norb:
            Number of total orbtials

        :return:
            Returns a matrix
        """

        ANx = self.commut(self.commut(k.T, A), D.T)
        A2Nx_c = self.complex_lrmat2vec(ANx, nocc, norb)
        return -(1. / 2) * A2Nx_c

    def _a3_contract(self, k1, k2, A, D, nocc, norb):
        """
        Contracts the generalized dipole gradient tensor of rank 3 with two
        first-order response matrices. A[3]N1N2 = -(1/6)[[k2,[k1,A]],D.T]

        :param: k1:
            First-order response matrix
        :param: k2:
            First-order response matrix
        :param A:
            A dipole intergral matrix
        :param D:
            Density matrix
        :param nocc:
            Number of occupied orbitals
        :param norb:
            Number of total orbtials

        :return:
            Returns a matrix
        """

        A3NxNy = self.commut(self.commut(k2.T, self.commut(k1.T, A)), D.T)
        A3NxNy_c = self.complex_lrmat2vec(A3NxNy, nocc, norb)
        return -(1. / 6) * A3NxNy_c

    def _zi(self, kB, kC, kD, Fc, Fd, Fbc, F0):
        """
        Returns a matrix used for the E[4] contraction

        :param kA:
            First-order response matrix
        :param kB:
            First-order response matrix
        :param Fa:
            First-order perturbed Fock matrix
        :param Fb:
            First-order perturbed Fock matrix
        :param F0:
            SCF Fock matrix

        :return:
            Returns a matrix
        """
        M1 = self.commut(kC, self.commut(kD, F0) + 3 * Fd)
        M2 = self.commut(kD, self.commut(kC, F0) + 3 * Fc)

        return (self.commut(kB, M1 + M2 + 3 * Fbc))

    @staticmethod
    def anti_sym(vec):
        """
        Returns an antisymetrized vector

        :param vec:
            The vector to be anti-symetrized

        :return:
            An antisymetrized vector
        """

        if vec.ndim == 1:
            new_vec = np.zeros_like(vec)
            half_len = vec.shape[0] // 2
            new_vec[:half_len] = vec[:half_len]
            new_vec[half_len:] = -vec[half_len:]
            return new_vec

        return None

    def _xi(self, kA, kB, Fa, Fb, F0):
        """
        Returns a matrix used for the E[3] contraction

        :param kA:
            First-order response matrix
        :param kB:
            First-order response matrix
        :param Fa:
            First-order perturbed Fock matrix
        :param Fb:
            First-order perturbed Fock matrix
        :param F0:
            SCF Fock matrix

        :return:
            Returns a matrix
        """

        return 0.5 * (self.commut(kA,
                                  self.commut(kB, F0) + 2 * Fb) +
                      self.commut(kB,
                                  self.commut(kA, F0) + 2 * Fa))

    @staticmethod
    def complex_lrmat2vec(mat, nocc, norb):
        """
        Converts complex matrix to vector.

        :param mat:
            The complex matrix.
        :param nocc:
            Number of occupied orbitals.
        :param norb:
            Number of orbitals.

        :return:
            The complex vector.
        """

        return (LinearSolver.lrmat2vec(mat.real, nocc, norb) +
                1j * LinearSolver.lrmat2vec(mat.imag, nocc, norb))
