#
#                           VELOXCHEM 1.0-RC2
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
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
import time
import sys

from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import mpi_master, hartree_in_wavenumbers
from .profiler import Profiler
from .outputstream import OutputStream
from .cppsolver import ComplexResponse
from .linearsolver import LinearSolver
from .nonlinearsolver import NonLinearSolver
from .distributedarray import DistributedArray
from .errorhandler import assert_msg_critical
from .checkpoint import (check_distributed_focks, read_distributed_focks,
                         write_distributed_focks)


class CubicResponseDriver(NonLinearSolver):
    """
    Implements a general cubic response driver

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - is_converged: The flag for convergence.
        - comp: The list of all the gamma tensor components
        - damping: The damping parameter.
        - lindep_thresh: The threshold for removing linear dependence in the
          trial vectors.
        - conv_thresh: The convergence threshold for the solver.
        - max_iter: The maximum number of solver iterations.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes the cubic response driver.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            ostream = OutputStream(sys.stdout)

        super().__init__(comm, ostream)

        self.is_converged = False

        # cpp settings
        self.b_frequencies = (0,)
        self.c_frequencies = (0,)
        self.d_frequencies = (0,)
        self.comp = None
        self.damping = 1000.0 / hartree_in_wavenumbers()
        self.lindep_thresh = 1.0e-10
        self.conv_thresh = 1.0e-4
        self.max_iter = 50

        self.a_components = 'z'
        self.b_components = 'z'
        self.c_components = 'z'
        self.d_components = 'z'

        # input keywords
        self.input_keywords['response'].update({
            'b_frequencies': ('seq_range', 'B frequencies'),
            'c_frequencies': ('seq_range', 'C frequencies'),
            'd_frequencies': ('seq_range', 'D frequencies'),
            'damping': ('float', 'damping parameter'),
            'a_components': ('str_lower', 'Cartesian components of A operator'),
            'b_components': ('str_lower', 'Cartesian components of B operator'),
            'c_components': ('str_lower', 'Cartesian components of C operator'),
            'd_components': ('str_lower', 'Cartesian components of D operator'),
        })

    def update_settings(self, rsp_dict, method_dict=None):
        """
        Updates response and method settings

        :param rsp_dict:
            The dictionary of response dict.
        :param method_dict:
            The dictionary of method rsp_dict.
        """

        if method_dict is None:
            method_dict = {}

        super().update_settings(rsp_dict, method_dict)

    def compute(self, molecule, ao_basis, scf_tensors):
        """
        Computes a cubic response function.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.

        :return:
              A dictonary containing the E[3], X[2], A[2] contractions
        """

        profiler = Profiler({
            'timing': False,
            'profiling': self.profiling,
            'memory_profiling': self.memory_profiling,
            'memory_tracing': self.memory_tracing,
        })

        if self.rank == mpi_master():
            self.print_header()

        start_time = time.time()

        # sanity check
        nalpha = molecule.number_of_alpha_electrons()
        nbeta = molecule.number_of_beta_electrons()
        assert_msg_critical(
            nalpha == nbeta,
            'CubicResponseDriver: not implemented for unrestricted case')

        if self.rank == mpi_master():
            S = scf_tensors['S']
            da = scf_tensors['D'][0]
            mo = scf_tensors['C']
            d_a_mo = np.linalg.multi_dot([mo.T, S, da, S, mo])
            norb = mo.shape[1]
        else:
            d_a_mo = None
            norb = None
        d_a_mo = self.comm.bcast(d_a_mo, root=mpi_master())
        norb = self.comm.bcast(norb, root=mpi_master())

        # Computing first-order gradient vectors
        dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
        dipole_mats = dipole_drv.compute(molecule, ao_basis)

        operator = 'dipole'
        linear_solver = LinearSolver(self.comm, self.ostream)
        a_rhs = linear_solver.get_complex_prop_grad(operator, self.a_components,
                                                    molecule, ao_basis,
                                                    scf_tensors)
        b_rhs = linear_solver.get_complex_prop_grad(operator, self.b_components,
                                                    molecule, ao_basis,
                                                    scf_tensors)
        c_rhs = linear_solver.get_complex_prop_grad(operator, self.c_components,
                                                    molecule, ao_basis,
                                                    scf_tensors)
        d_rhs = linear_solver.get_complex_prop_grad(operator, self.d_components,
                                                    molecule, ao_basis,
                                                    scf_tensors)

        if self.rank == mpi_master():
            inv_sqrt_2 = 1.0 / np.sqrt(2.0)

            a_rhs = list(a_rhs)
            for ind in range(len(a_rhs)):
                a_rhs[ind] *= inv_sqrt_2

            b_rhs = list(b_rhs)
            for ind in range(len(b_rhs)):
                b_rhs[ind] *= inv_sqrt_2

            c_rhs = list(c_rhs)
            for ind in range(len(c_rhs)):
                c_rhs[ind] *= inv_sqrt_2

            d_rhs = list(d_rhs)
            for ind in range(len(d_rhs)):
                d_rhs[ind] *= inv_sqrt_2

        # Storing the dipole integral matrices used for the X[3],X[2],A[3] and
        # A[2] contractions in MO basis
        wa = [
            sum(x) for x in zip(
                self.b_frequencies,
                self.c_frequencies,
                self.d_frequencies,
            )
        ]

        freqpairs = [
            wl for wl in zip(
                self.b_frequencies,
                self.c_frequencies,
                self.d_frequencies,
            )
        ]

        ABCD = {}

        if self.rank == mpi_master():
            A = {(op, w): v for op, v in zip('A', a_rhs) for w in wa}
            B = {(op, w): v for op, v in zip('B', b_rhs)
                 for w in self.b_frequencies}
            C = {(op, w): v for op, v in zip('C', c_rhs)
                 for w in self.c_frequencies}
            D = {(op, w): v for op, v in zip('D', d_rhs)
                 for w in self.d_frequencies}

            ABCD.update(A)
            ABCD.update(B)
            ABCD.update(C)
            ABCD.update(D)

            X = {
                'x': 2 * self.ao2mo(mo, dipole_mats.x_to_numpy()),
                'y': 2 * self.ao2mo(mo, dipole_mats.y_to_numpy()),
                'z': 2 * self.ao2mo(mo, dipole_mats.z_to_numpy())
            }
        else:
            X = None
            self.comp = None

        # Computing the first-order response vectors (3 per frequency)
        N_drv = ComplexResponse(self.comm, self.ostream)

        cpp_keywords = {
            'damping', 'lindep_thresh', 'conv_thresh', 'max_iter', 'eri_thresh',
            'qq_type', 'timing', 'memory_profiling', 'batch_size', 'restart',
            'program_start_time', 'maximum_hours'
        }

        for key in cpp_keywords:
            setattr(N_drv, key, getattr(self, key))

        if self.checkpoint_file is not None:
            N_drv.checkpoint_file = str(
                Path(self.checkpoint_file).with_suffix('.crf_1.h5'))

        N_results = N_drv.compute(molecule, ao_basis, scf_tensors, ABCD)

        kX = N_results['kappas']
        Focks = N_results['focks']

        profiler.check_memory_usage('1st CPP')

        cubic_dict = self.compute_cubic_components(Focks, freqpairs, X, d_a_mo,
                                                   kX, self.comp, scf_tensors,
                                                   molecule, ao_basis, profiler)

        valstr = '*** Time spent in cubic response calculation: '
        valstr += '{:.2f} sec ***'.format(time.time() - start_time)
        self.ostream.print_header(valstr)
        self.ostream.print_blank()
        self.ostream.flush()

        profiler.end(self.ostream)

        self.is_converged = True

        return cubic_dict

    def compute_cubic_components(self, Focks, freqpairs, X, d_a_mo, kX, track,
                                 scf_tensors, molecule, ao_basis, profiler):
        """
        Computes all the relevent terms to compute a general cubic response function

        :param w:
            A list of all the frequencies
        :param X:
            A dictonary of matricies containing all the dipole integrals
        :param d_a_mo:
            The SCF density in MO basis
        :param kX:
            A dictonary containing all the response matricies
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.
        :param molecule:
            The molecule.
        :param basis:
            The AO basis.
        :param profiler:
            The profiler.

        :return:

        """

        if self.rank == mpi_master():
            S = scf_tensors['S']
            D0 = scf_tensors['D'][0]
            mo = scf_tensors['C']
            F0 = np.linalg.multi_dot([mo.T, scf_tensors['F'][0], mo])
            norb = mo.shape[1]
        else:
            S = None
            D0 = None
            mo = None
            F0 = None
            norb = None

        F0 = self.comm.bcast(F0, root=mpi_master())
        norb = self.comm.bcast(norb, root=mpi_master())

        nocc = molecule.number_of_alpha_electrons()

        # computing all compounded first-order densities
        if self.rank == mpi_master():
            density_list = self.get_densities(freqpairs, kX, S, D0, mo)
        else:
            density_list = None

        profiler.check_memory_usage('1st densities')

        #  computing the compounded first-order Fock matrices
        fock_dict = self.get_fock_dict(freqpairs, density_list, F0, mo,
                                       molecule, ao_basis)

        profiler.check_memory_usage('1st Focks')

        e4_dict, s4_dict, r4_dict = self.get_esr4(freqpairs, kX, fock_dict,
                                                  Focks, nocc, norb, d_a_mo)

        profiler.check_memory_usage('E[4]')

        k_xy, f_xy = self.get_nxy(freqpairs, kX, fock_dict, Focks, nocc, norb,
                                  d_a_mo, X, molecule, ao_basis, scf_tensors)

        profiler.check_memory_usage('2nd CPP')

        if self.rank == mpi_master():
            density_list_ii = self.get_densities_ii(freqpairs, kX, k_xy, S, D0,
                                                    mo)
        else:
            density_list_ii = None

        profiler.check_memory_usage('2nd densities')

        fock_dict_ii = self.get_fock_dict_ii(freqpairs, density_list_ii, F0, mo,
                                             molecule, ao_basis)

        profiler.check_memory_usage('2nd Focks')

        e3_dict = self.get_e3(freqpairs, kX, k_xy, Focks, fock_dict_ii, f_xy,
                              nocc, norb)

        profiler.check_memory_usage('E[3]')

        result = {}

        if self.rank == mpi_master():

            A = X[self.a_components]
            B = X[self.b_components]
            C = X[self.c_components]
            D = X[self.d_components]

            for (wb, wc, wd) in freqpairs:

                Na = self.complex_lrmat2vec(kX[('A', wb + wc + wd)], nocc, norb)
                Nb = self.complex_lrmat2vec(kX[('B', wb)], nocc, norb)
                Nc = self.complex_lrmat2vec(kX[('C', wc)], nocc, norb)
                Nd = self.complex_lrmat2vec(kX[('D', wd)], nocc, norb)

                Nbd = self.complex_lrmat2vec(k_xy[('BD', wb, wd), wb + wd],
                                             nocc, norb)
                Nbc = self.complex_lrmat2vec(k_xy[('BC', wb, wc), wb + wc],
                                             nocc, norb)
                Ncd = self.complex_lrmat2vec(k_xy[('CD', wc, wd), wc + wd],
                                             nocc, norb)

                NaE4NbNcNd = np.dot(Na, e4_dict[wb])
                NaS4NbNcNd = np.dot(Na, s4_dict[wb])
                NaR4NbNcNd = r4_dict[wb]

                NaE3NbNcd = np.dot(Na, e3_dict[(('E3NbNcd'), (wb, wc, wd))])
                NaE3NcNbd = np.dot(Na, e3_dict[(('E3NcNbd'), (wb, wc, wd))])
                NaE3NdNbc = np.dot(Na, e3_dict[(('E3NdNbc'), (wb, wc, wd))])

                # X3 terms
                NaB3NcNd = np.dot(
                    Na.T,
                    self.x3_contract(kX[('C', wc)], kX[('D', wd)], B, d_a_mo,
                                     nocc, norb))
                NaB3NdNc = np.dot(
                    Na.T,
                    self.x3_contract(kX[('D', wd)], kX[('C', wc)], B, d_a_mo,
                                     nocc, norb))

                NaC3NbNd = np.dot(
                    Na.T,
                    self.x3_contract(kX[('B', wb)], kX[('D', wd)], C, d_a_mo,
                                     nocc, norb))
                NaC3NdNb = np.dot(
                    Na.T,
                    self.x3_contract(kX[('D', wd)], kX[('B', wb)], C, d_a_mo,
                                     nocc, norb))

                NaD3NbNc = np.dot(
                    Na.T,
                    self.x3_contract(kX[('B', wb)], kX[('C', wc)], D, d_a_mo,
                                     nocc, norb))
                NaD3NcNb = np.dot(
                    Na.T,
                    self.x3_contract(kX[('C', wc)], kX[('B', wb)], D, d_a_mo,
                                     nocc, norb))

                # X2 contraction
                NaB2Ncd = np.dot(
                    Na.T,
                    self.x2_contract(k_xy[('CD', wc, wd), wc + wd], B, d_a_mo,
                                     nocc, norb))
                NaC2Nbd = np.dot(
                    Na.T,
                    self.x2_contract(k_xy[('BD', wb, wd), wb + wd], C, d_a_mo,
                                     nocc, norb))
                NaD2Nbc = np.dot(
                    Na.T,
                    self.x2_contract(k_xy[('BC', wb, wc), wb + wc], D, d_a_mo,
                                     nocc, norb))

                # A3 contraction
                NdA3NbNc = np.dot(
                    self.a3_contract(kX[('B', wb)], kX[('C', wc)], A, d_a_mo,
                                     nocc, norb), Nd)
                NdA3NcNb = np.dot(
                    self.a3_contract(kX[('C', wc)], kX[('B', wb)], A, d_a_mo,
                                     nocc, norb), Nd)

                NbA3NcNd = np.dot(
                    self.a3_contract(kX[('C', wc)], kX[('D', wd)], A, d_a_mo,
                                     nocc, norb), Nb)
                NbA3NdNc = np.dot(
                    self.a3_contract(kX[('D', wd)], kX[('C', wc)], A, d_a_mo,
                                     nocc, norb), Nb)

                NcA3NbNd = np.dot(
                    self.a3_contract(kX[('B', wb)], kX[('D', wd)], A, d_a_mo,
                                     nocc, norb), Nc)
                NcA3NdNb = np.dot(
                    self.a3_contract(kX[('D', wd)], kX[('B', wb)], A, d_a_mo,
                                     nocc, norb), Nc)

                # A2 contraction
                NbA2Ncd = np.dot(
                    self.a2_contract(kX[('B', wb)], A, d_a_mo, nocc, norb), Ncd)
                NcdA2Nb = np.dot(
                    self.a2_contract(k_xy[('CD', wc, wd), wc + wd], A, d_a_mo,
                                     nocc, norb), Nb)

                NcA2Nbd = np.dot(
                    self.a2_contract(kX[('C', wc)], A, d_a_mo, nocc, norb), Nbd)
                NbdA2Nc = np.dot(
                    self.a2_contract(k_xy[('BD', wb, wd), wb + wd], A, d_a_mo,
                                     nocc, norb), Nc)

                NdA2Nbc = np.dot(
                    self.a2_contract(kX[('D', wd)], A, d_a_mo, nocc, norb), Nbc)
                NbcA2Nd = np.dot(
                    self.a2_contract(k_xy[('BC', wb, wc), wb + wc], A, d_a_mo,
                                     nocc, norb), Nd)

                val_E3 = -(NaE3NbNcd + NaE3NcNbd + NaE3NdNbc)
                val_T4 = -(NaE4NbNcNd - NaS4NbNcNd - NaR4NbNcNd)
                val_X2 = NaB2Ncd + NaC2Nbd + NaD2Nbc
                val_X3 = NaB3NcNd + NaB3NdNc + NaC3NbNd + NaC3NdNb + NaD3NbNc + NaD3NcNb
                val_A2 = NbA2Ncd + NcdA2Nb + NcA2Nbd + NbdA2Nc + NdA2Nbc + NbcA2Nd
                val_A3 = -(NdA3NbNc + NdA3NcNb + NbA3NcNd + NbA3NdNc +
                           NcA3NbNd + NcA3NdNb)

                # Cubic response function
                gamma = val_T4 + val_E3 + val_X3 + val_A3 + val_X2 + val_A2

                self.ostream.print_blank()
                w_str = 'Cubic response function: << {};{},{},{} >>  ({},{},{})'.format(
                    self.a_components, self.b_components, self.c_components,
                    self.d_components, str(wb), str(wc), str(wd))
                self.ostream.print_header(w_str)
                self.ostream.print_header('=' * (len(w_str) + 2))
                self.ostream.print_blank()

                title = '{:<9s} {:>20s} {:>21s}'.format('Component', 'Real',
                                                        'Imaginary')
                width = len(title)
                self.ostream.print_header(title.ljust(width))
                self.ostream.print_header(('-' * len(title)).ljust(width))
                self.print_component('E3', val_E3, width)
                self.print_component('T4', val_T4, width)
                self.print_component('X2', val_X2, width)
                self.print_component('X3', val_X3, width)
                self.print_component('A2', val_A2, width)
                self.print_component('A3', val_A3, width)
                self.print_component('gamma', gamma, width)
                self.ostream.print_blank()

                result[('E3', wb, wc, wd)] = val_E3
                result[('T4', wb, wc, wd)] = val_T4
                result[('X3', wb, wc, wd)] = val_X3
                result[('X2', wb, wc, wd)] = val_X2
                result[('A3', wb, wc, wd)] = val_A3
                result[('A2', wb, wc, wd)] = val_A2

        profiler.check_memory_usage('End of CRF')

        return result

    def get_e3(self, wi, kX, k_xy, fo, fo2, fo3, nocc, norb):
        """
        Contracts E[3] for CRF

        :param wi:
            A list of freqs
        :param kX:
            A dict of the single index response matricies
        :param kXY:
            A dict of the two index response matrices
        :param fo:
            A dictonary of transformed Fock matricies from fock_dict
        :param fo2:
            A dictonarty of transfromed Fock matricies from fock_dict_two
        :param nocc:
            The number of occupied orbitals
        :param norb:
            The total number of orbitals

        :return:
            A dictonary of compounded E[3] tensors for the isotropic cubic
            response function for CRF
        """

        e3vec = {}

        for (wb, wc, wd) in wi:

            vec_pack = np.array([
                fo[('B', wb)].data,
                fo[('C', wc)].data,
                fo[('D', wd)].data,
                fo2['Fb_cd'][(wb, wc, wd)].data,
                fo2['Fcd_b'][(wb, wc, wd)].data,
                fo2['Fc_bd'][(wb, wc, wd)].data,
                fo2['Fbd_c'][(wb, wc, wd)].data,
                fo2['Fd_bc'][(wb, wc, wd)].data,
                fo2['Fbc_d'][(wb, wc, wd)].data,
                fo3[(('BC', wb, wc), wb + wc)].data,
                fo3[(('BD', wb, wd), wb + wd)].data,
                fo3[(('CD', wc, wd), wc + wd)].data,
            ]).T.copy()

            vec_pack = self.collect_vectors_in_columns(vec_pack)

            if self.rank != mpi_master():
                continue

            vec_pack = vec_pack.T.copy().reshape(-1, norb, norb)

            (fb, fc, fd, fb_cd, fcd_b, fc_bd, fbd_c, fd_bc, fbc_d, fbc, fbd,
             fcd) = vec_pack

            fb = np.conjugate(fb).T
            fc = np.conjugate(fc).T
            fd = np.conjugate(fd).T
            fbc = np.conjugate(fbc).T
            fcd = np.conjugate(fcd).T
            fbd = np.conjugate(fbd).T

            F0_a = fo2['F0']

            # E3NbNcd

            kb = kX[('B', wb)].T
            kcd = k_xy[('CD', wc, wd), wc + wd].T

            xi = self.xi(kb, kcd, fb, fcd, F0_a)

            e3fock = xi.T + (0.5 * fb_cd + 0.5 * fcd_b).T

            e3vec[('E3NbNcd', (wb, wc, wd))] = self.anti_sym(
                -2 * LinearSolver.lrmat2vec(e3fock, nocc, norb))

            # E3NcNbd

            kc = kX[('C', wc)].T
            kbd = k_xy[('BD', wb, wd), wb + wd].T

            xi = self.xi(kc, kbd, fc, fbd, F0_a)

            e3fock = xi.T + (0.5 * fc_bd + 0.5 * fbd_c).T

            e3vec[('E3NcNbd', (wb, wc, wd))] = self.anti_sym(
                -2 * LinearSolver.lrmat2vec(e3fock, nocc, norb))

            # E3NdNbc

            kd = kX[('D', wd)].T
            kbc = k_xy[('BC', wb, wc), wb + wc].T

            xi = self.xi(kd, kbc, fd, fbc, F0_a)

            e3fock = xi.T + (0.5 * fd_bc + 0.5 * fbc_d).T

            e3vec[('E3NdNbc', (wb, wc, wd))] = self.anti_sym(
                -2 * LinearSolver.lrmat2vec(e3fock, nocc, norb))

        return e3vec

    def get_densities(self, freqpairs, kX, S, D0, mo):
        """
        Computes the  densities needed for the Fock matrices.

        :param wi:
            A list of the frequencies
        :param kX:
            A dictonary with all the first-order response matrices
        :param S:
            The overlap matrix
        :param D0:
            The SCF density matrix in AO basis
        :param mo:
            A matrix containing the MO coefficents

        :return:
            A list of tranformed compounded densities
        """

        density_list = []

        for (wb, wc, wd) in freqpairs:

            # convert response matrix to ao basis #

            kb = self.mo2ao(mo, kX[('B', wb)])
            kc = self.mo2ao(mo, kX[('C', wc)])
            kd = self.mo2ao(mo, kX[('D', wd)])

            # create the first order single indexed densiteies #

            Db = self.transform_dens(kb, D0, S)
            Dc = self.transform_dens(kc, D0, S)
            Dd = self.transform_dens(kd, D0, S)

            # create the first order two indexed densities #

            Dbc = self.transform_dens(kb, Dc, S)
            Dcb = self.transform_dens(kc, Db, S)

            Dbd = self.transform_dens(kb, Dd, S)
            Ddb = self.transform_dens(kd, Db, S)

            Ddc = self.transform_dens(kd, Dc, S)
            Dcd = self.transform_dens(kc, Dd, S)

            # create the first order three indexed densities #

            Dbcd = self.transform_dens(kb, Dcd, S)
            Dbdc = self.transform_dens(kb, Ddc, S)

            Dcbd = self.transform_dens(kc, Dbd, S)
            Dcdb = self.transform_dens(kc, Ddb, S)

            Ddbc = self.transform_dens(kd, Dbc, S)
            Ddcb = self.transform_dens(kd, Dcb, S)

            density_list.append(Dbc)
            density_list.append(Dcb)
            density_list.append(Dbd)
            density_list.append(Ddb)
            density_list.append(Ddc)
            density_list.append(Dcd)

            density_list.append(Dbcd)
            density_list.append(Dbdc)
            density_list.append(Dcbd)
            density_list.append(Dcdb)
            density_list.append(Ddbc)
            density_list.append(Ddcb)

        return density_list

    def get_densities_ii(self, freqpairs, kX, k_xy, S, D0, mo):
        """
        Computes the  densities needed for the Fock matrices.

        :param wi:
            A list of the frequencies
        :param kX:
            A dictonary with all the first-order response matrices
        :param S:
            The overlap matrix
        :param D0:
            The SCF density matrix in AO basis
        :param mo:
            A matrix containing the MO coefficents

        :return:
            A list of tranformed compounded densities
        """

        density_list = []

        for (wb, wc, wd) in freqpairs:

            # convert response matrix to ao basis #

            kb = self.mo2ao(mo, kX[('B', wb)])
            kc = self.mo2ao(mo, kX[('C', wc)])
            kd = self.mo2ao(mo, kX[('D', wd)])

            kbc = self.mo2ao(mo, k_xy[(('BC', wb, wc), wb + wc)])
            kbd = self.mo2ao(mo, k_xy[(('BD', wb, wd), wb + wd)])
            kcd = self.mo2ao(mo, k_xy[(('CD', wc, wd), wc + wd)])

            # create the first order single indexed densiteies #

            Db = self.transform_dens(kb, D0, S)
            Dc = self.transform_dens(kc, D0, S)
            Dd = self.transform_dens(kd, D0, S)

            # create the second-order two indexed densities #

            Dbc = self.transform_dens(kbc, D0, S)
            Dbd = self.transform_dens(kbd, D0, S)
            Dcd = self.transform_dens(kcd, D0, S)

            # create the second-order three indexed densities #

            Db_cd = self.transform_dens(kb, Dcd, S)
            Dcd_b = self.transform_dens(kcd, Db, S)

            Dc_bd = self.transform_dens(kc, Dbd, S)
            Dbd_c = self.transform_dens(kbd, Dc, S)

            Dd_bc = self.transform_dens(kd, Dbc, S)
            Dbc_d = self.transform_dens(kbc, Dd, S)

            density_list.append(Db_cd)
            density_list.append(Dcd_b)
            density_list.append(Dc_bd)
            density_list.append(Dbd_c)
            density_list.append(Dd_bc)
            density_list.append(Dbc_d)

        return density_list

    def get_fock_dict(self, wi, density_list, F0, mo, molecule, ao_basis):
        """
        Computes the Fock matrices for a cubic response function

        :param wi:
            A list of the frequencies
        :param density_list:
            A list of tranformed compounded densities
        :param F0:
            The Fock matrix in MO basis
        :param mo:
            A matrix containing the MO coefficents
        :param molecule:
            The molecule
        :param ao_basis:
            The AO basis set

        :return:
            A dictonary of compounded first-order Fock-matrices
        """

        if self.rank == mpi_master():
            self.print_fock_header()

        keys = [
            'Fbc',
            'Fcb',
            'Fbd',
            'Fdb',
            'Fdc',
            'Fcd',
            'Fbcd',
            'Fbdc',
            'Fcbd',
            'Fcdb',
            'Fdbc',
            'Fdcb',
        ]

        if self.checkpoint_file is not None:
            fock_file = str(
                Path(self.checkpoint_file).with_suffix('.crf_fock_1.h5'))
        else:
            fock_file = None

        fock_freqs = [wb for (wb, wc, wd) in wi]

        if self.restart:
            if self.rank == mpi_master():
                self.restart = check_distributed_focks(fock_file, keys,
                                                       fock_freqs)
            self.restart = self.comm.bcast(self.restart, mpi_master())

        if self.restart:
            focks = read_distributed_focks(fock_file, keys, fock_freqs,
                                           self.comm, self.ostream)
            focks['F0'] = F0
            return focks

        time_start_fock = time.time()
        dist_focks = self.comp_nlr_fock(mo, density_list, molecule, ao_basis,
                                        'real_and_imag')
        time_end_fock = time.time()

        total_time_fock = time_end_fock - time_start_fock
        self.print_fock_time(total_time_fock)

        focks = {'F0': F0}
        for key in keys:
            focks[key] = {}

        fock_index = 0
        for wb in fock_freqs:
            for key in keys:
                focks[key][wb] = DistributedArray(dist_focks.data[:,
                                                                  fock_index],
                                                  self.comm,
                                                  distribute=False)
                fock_index += 1

        write_distributed_focks(fock_file, focks, keys, fock_freqs, self.comm,
                                self.ostream)

        return focks

    def get_fock_dict_ii(self, wi, density_list, F0, mo, molecule, ao_basis):
        """
        Computes the Fock matrices for a cubic response function

        :param wi:
            A list of the frequencies
        :param density_list:
            A list of tranformed compounded densities
        :param F0:
            The Fock matrix in MO basis
        :param mo:
            A matrix containing the MO coefficents
        :param molecule:
            The molecule
        :param ao_basis:
            The AO basis set

        :return:
            A dictonary of compounded first-order Fock-matrices
        """

        if self.rank == mpi_master():
            self.print_fock_header()

        keys = [
            'Fb_cd',
            'Fcd_b',
            'Fc_bd',
            'Fbd_c',
            'Fd_bc',
            'Fbc_d',
        ]

        if self.checkpoint_file is not None:
            fock_file = str(
                Path(self.checkpoint_file).with_suffix('.crf_fock_2.h5'))
        else:
            fock_file = None

        if self.restart:
            if self.rank == mpi_master():
                self.restart = check_distributed_focks(fock_file, keys, wi)
            self.restart = self.comm.bcast(self.restart, mpi_master())

        if self.restart:
            focks = read_distributed_focks(fock_file, keys, wi, self.comm,
                                           self.ostream)
            focks['F0'] = F0
            return focks

        time_start_fock = time.time()
        dist_focks = self.comp_nlr_fock(mo, density_list, molecule, ao_basis,
                                        'real_and_imag')
        time_end_fock = time.time()

        total_time_fock = time_end_fock - time_start_fock
        self.print_fock_time(total_time_fock)

        focks = {'F0': F0}
        for key in keys:
            focks[key] = {}

        fock_index = 0
        for (wb, wc, wd) in wi:
            for key in keys:
                focks[key][(wb, wc,
                            wd)] = DistributedArray(dist_focks.data[:,
                                                                    fock_index],
                                                    self.comm,
                                                    distribute=False)
                fock_index += 1

        write_distributed_focks(fock_file, focks, keys, wi, self.comm,
                                self.ostream)

        return focks

    def get_esr4(self, wi, kX, fo, fo2, nocc, norb, D0):
        """
        Contracts E[4], S[4], R[4]

        :param wi:
            A list of freqs
        :param kX:
            A dict of the single index response matricies
        :param kXY:
            A dict of the two index response matrices
        :param fo:
            A dictonary of transformed Fock matricies from fock_dict
        :param fo2:
            A dictonarty of transfromed Fock matricies from fock_dict_two
        :param nocc:
            The number of occupied orbitals
        :param norb:
            The total number of orbitals

        :return:
            A dictonary of E[4], S[4], R[4] tensor contractions.
        """

        e4_vec = {}
        s4_vec = {}
        r4_vec = {}

        for (wb, wc, wd) in wi:

            vec_pack = np.array([
                fo2[('B', wb)].data,
                fo2[('C', wc)].data,
                fo2[('D', wd)].data,
                fo['Fbc'][wb].data,
                fo['Fcb'][wb].data,
                fo['Fbd'][wb].data,
                fo['Fdb'][wb].data,
                fo['Fcd'][wb].data,
                fo['Fdc'][wb].data,
                fo['Fbcd'][wb].data,
                fo['Fbdc'][wb].data,
                fo['Fcbd'][wb].data,
                fo['Fcdb'][wb].data,
                fo['Fdbc'][wb].data,
                fo['Fdcb'][wb].data,
            ]).T.copy()

            vec_pack = self.collect_vectors_in_columns(vec_pack)

            if self.rank != mpi_master():
                continue

            vec_pack = vec_pack.T.copy().reshape(-1, norb, norb)

            (fb, fc, fd, fbc, fcb, fbd, fdb, fcd, fdc, fbcd, fbdc, fcbd, fcdb,
             fdbc, fdcb) = vec_pack

            fb = np.conjugate(fb).T
            fc = np.conjugate(fc).T
            fd = np.conjugate(fd).T

            F0_a = fo['F0']

            # Response

            kb = kX[('B', wb)].T
            kc = kX[('C', wc)].T
            kd = kX[('D', wd)].T

            zi_bcd = self.zi(kb, kc, kd, fc, fd, fcd, fdc, F0_a)
            zi_cbd = self.zi(kc, kb, kd, fb, fd, fbd, fdb, F0_a)
            zi_dbc = self.zi(kd, kb, kc, fb, fc, fbc, fcb, F0_a)

            e4fock = (zi_bcd + zi_cbd + zi_dbc) + (fbcd + fbdc + fcbd + fcdb +
                                                   fdbc + fdcb)

            e4vec = 2. / 6 * self.anti_sym(
                LinearSolver.lrmat2vec(e4fock.T, nocc, norb))

            ka = kX[('A', (wb + wc + wd))]
            kb = kX[('B', wb)]
            kc = kX[('C', wc)]
            kd = kX[('D', wd)]

            s4_term = wb * self.s4(kb, kc, kd, D0, nocc, norb)
            s4_term += wc * self.s4(kc, kb, kd, D0, nocc, norb)
            s4_term += wd * self.s4(kd, kb, kc, D0, nocc, norb)

            Nb = self.complex_lrmat2vec(kb, nocc, norb)
            Nc = self.complex_lrmat2vec(kc, nocc, norb)
            Nd = self.complex_lrmat2vec(kd, nocc, norb)

            Nb_h = self.flip_xy(Nb)
            Nc_h = self.flip_xy(Nc)
            Nd_h = self.flip_xy(Nd)

            r4_term = 1j * self.damping * np.dot(
                Nd_h, self.s4_for_r4(ka.T, kb, kc, D0, nocc, norb))
            r4_term += 1j * self.damping * np.dot(
                Nc_h, self.s4_for_r4(ka.T, kb, kd, D0, nocc, norb))
            r4_term += 1j * self.damping * np.dot(
                Nd_h, self.s4_for_r4(ka.T, kc, kb, D0, nocc, norb))
            r4_term += 1j * self.damping * np.dot(
                Nb_h, self.s4_for_r4(ka.T, kc, kd, D0, nocc, norb))
            r4_term += 1j * self.damping * np.dot(
                Nc_h, self.s4_for_r4(ka.T, kd, kb, D0, nocc, norb))
            r4_term += 1j * self.damping * np.dot(
                Nb_h, self.s4_for_r4(ka.T, kd, kc, D0, nocc, norb))

            e4_vec[wb] = e4vec
            s4_vec[wb] = s4_term
            r4_vec[wb] = r4_term

        return e4_vec, s4_vec, r4_vec

    def get_nxy(self, wi, kX, fo, fo2, nocc, norb, d_a_mo, X, molecule,
                ao_basis, scf_tensors):
        """
        Computed NXY

        :param wi:
            A list of freqs
        :param kX:
            A dict of the single index response matricies
        :param kXY:
            A dict of the two index response matrices
        :param fo:
            A dictonary of transformed Fock matricies from fock_dict
        :param fo2:
            A dictonarty of transfromed Fock matricies from fock_dict_two
        :param nocc:
            The number of occupied orbitals
        :param norb:
            The total number of orbitals

        :return:
            A dictonary of E[4], S[4], R[4] tensor contractions.
        """

        BC = {}
        CD = {}
        BD = {}

        XY = {}

        for (wb, wc, wd) in wi:

            vec_pack = np.array([
                fo2[('B', wb)].data,
                fo2[('C', wc)].data,
                fo2[('D', wd)].data,
                fo['Fbc'][wb].data,
                fo['Fcb'][wb].data,
                fo['Fbd'][wb].data,
                fo['Fdb'][wb].data,
                fo['Fcd'][wb].data,
                fo['Fdc'][wb].data,
                fo['Fbcd'][wb].data,
                fo['Fbdc'][wb].data,
                fo['Fcbd'][wb].data,
                fo['Fcdb'][wb].data,
                fo['Fdbc'][wb].data,
                fo['Fdcb'][wb].data,
            ]).T.copy()

            vec_pack = self.collect_vectors_in_columns(vec_pack)

            if self.rank != mpi_master():
                continue

            vec_pack = vec_pack.T.copy().reshape(-1, norb, norb)

            (fb, fc, fd, fbc, fcb, fbd, fdb, fcd, fdc, fbcd, fbdc, fcbd, fcdb,
             fdbc, fdcb) = vec_pack

            fb = np.conjugate(fb).T
            fc = np.conjugate(fc).T
            fd = np.conjugate(fd).T

            F0_a = fo['F0']

            # Response

            kb = kX[('B', wb)].T
            kc = kX[('C', wc)].T
            kd = kX[('D', wd)].T

            B = X[self.b_components]
            C = X[self.c_components]
            D = X[self.d_components]

            # BC

            xi = self.xi(kb, kc, fb, fc, F0_a)

            e3fock = xi.T + (0.5 * fbc + 0.5 * fcb).T
            E3NbNc = self.anti_sym(-LinearSolver.lrmat2vec(e3fock, nocc, norb))

            C2Nb = 0.5 * self.x2_contract(kX[('B', wb)], C, d_a_mo, nocc, norb)
            B2Nc = 0.5 * self.x2_contract(kX[('C', wc)], B, d_a_mo, nocc, norb)

            BC[(('BC', wb, wc), wb + wc)] = E3NbNc - C2Nb - B2Nc

            # BD

            xi = self.xi(kb, kd, fb, fd, F0_a)

            e3fock = xi.T + (0.5 * fbd + 0.5 * fdb).T
            E3NbNd = self.anti_sym(-LinearSolver.lrmat2vec(e3fock, nocc, norb))

            D2Nb = 0.5 * self.x2_contract(kX[('B', wb)], D, d_a_mo, nocc, norb)
            B2Nd = 0.5 * self.x2_contract(kX[('D', wd)], B, d_a_mo, nocc, norb)

            BD[(('BD', wb, wd), wb + wd)] = E3NbNd - D2Nb - B2Nd

            # CD

            xi = self.xi(kc, kd, fc, fd, F0_a)

            e3fock = xi.T + (0.5 * fcd + 0.5 * fdc).T
            E3NcNd = self.anti_sym(-LinearSolver.lrmat2vec(e3fock, nocc, norb))

            C2Nd = 0.5 * self.x2_contract(kX[('D', wd)], C, d_a_mo, nocc, norb)
            D2Nc = 0.5 * self.x2_contract(kX[('C', wc)], D, d_a_mo, nocc, norb)

            CD[(('CD', wc, wd), wc + wd)] = E3NcNd - C2Nd - D2Nc

            XY.update(BC)
            XY.update(BD)
            XY.update(CD)

        Nxy_drv = ComplexResponse(self.comm, self.ostream)

        cpp_keywords = {
            'damping', 'lindep_thresh', 'conv_thresh', 'max_iter', 'eri_thresh',
            'qq_type', 'timing', 'memory_profiling', 'batch_size', 'restart',
            'program_start_time', 'maximum_hours'
        }

        for key in cpp_keywords:
            setattr(Nxy_drv, key, getattr(self, key))

        if self.checkpoint_file is not None:
            Nxy_drv.checkpoint_file = str(
                Path(self.checkpoint_file).with_suffix('.crf_2.h5'))

        Nxy_results = Nxy_drv.compute(molecule, ao_basis, scf_tensors, XY)

        kX = Nxy_results['kappas']
        Focks = Nxy_results['focks']

        return kX, Focks

    def print_header(self):
        """
        Prints CRF setup header to output stream.
        """

        self.ostream.print_blank()

        title = 'Cubic Response Driver Setup'
        self.ostream.print_header(title)
        self.ostream.print_header('=' * (len(title) + 2))
        self.ostream.print_blank()

        width = 50

        cur_str = 'ERI Screening Threshold         : {:.1e}'.format(
            self.eri_thresh)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = 'Convergance Threshold           : {:.1e}'.format(
            self.conv_thresh)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = 'Max. Number of Iterations       : {:d}'.format(self.max_iter)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = 'Damping Parameter               : {:.6e}'.format(
            self.damping)
        self.ostream.print_header(cur_str.ljust(width))

        self.ostream.print_blank()
        self.ostream.flush()
