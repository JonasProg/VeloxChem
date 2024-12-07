#                              VELOXCHEM
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2024 by VeloxChem developers. All rights reserved.
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

# TODO: remove commented out code;
from mpi4py import MPI
from pathlib import Path
import numpy as np
import time as tm
import sys
import math

from .veloxchemlib import AODensityMatrix
from .veloxchemlib import T4CScreener
from .veloxchemlib import XCMolecularHessian
from .veloxchemlib import mpi_master, denmat
from .veloxchemlib import make_matrix, mat_t, partition_atoms
from .veloxchemlib import (OverlapGeom100Driver, KineticEnergyGeom100Driver,
                           NuclearPotentialGeom100Driver,
                           NuclearPotentialGeom010Driver, FockGeom1000Driver)
from .outputstream import OutputStream
from .matrices import Matrices
from .distributedarray import DistributedArray
from .cphfsolver import CphfSolver
from .errorhandler import assert_msg_critical
from .inputparser import parse_input
from .batchsize import get_batch_size
from .batchsize import get_number_of_batches
from .dftutils import get_default_grid_level


class HessianOrbitalResponse(CphfSolver):
    """
    Implements solver for the coupled-perturbed Hartree-Fock (CPHF) equations
    for the Hessian orbital response

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - use_subspace_solver: flag to use subspace solver
          instead of conjugate gradient.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes orbital response driver to default setup.

        """

        super().__init__(comm, ostream)

    def update_settings(self, cphf_dict, method_dict=None):
        """
        Updates response and method settings in CPHF solver.

        :param cphf_dict:
            The dictionary of CPHF (orbital response) settings.
        :param method_dict:
            The dictionary of method settings.
        """

        super().update_settings(cphf_dict, method_dict)

    def compute_rhs(self, molecule, basis, scf_tensors, eri_dict, dft_dict, pe_dict):
        """
        Computes the right hand side for the CPHF equations for
        the analytical Hessian, all atomic coordinates.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        :param scf_tensors:
            The tensors from the converged SCF calculation.

        :returns:
            The RHS of the CPHF equations.
        """

        self.profiler.start_timer('RHS')

        # number of atoms
        natm = molecule.number_of_atoms()
        nao = basis.get_dimensions_of_basis()
        nocc = molecule.number_of_alpha_electrons()

        if self.rank == mpi_master():
            density = scf_tensors['D_alpha']
            mo = scf_tensors['C_alpha']
            mo_energies = scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            # DFT
        else:
            density = None
            eocc = None
            mo = None

        # DFT grid
        mol_grid = dft_dict['molgrid'] 
        gs_density = dft_dict['gs_density']

        density = self.comm.bcast(density, root=mpi_master())
        gs_density = self.comm.bcast(gs_density, root=mpi_master())
        eocc = self.comm.bcast(eocc, root=mpi_master())
        mo = self.comm.bcast(mo, root=mpi_master())

        # MO coefficients
        mo_occ = mo[:, :nocc].copy()
        mo_vir = mo[:, nocc:].copy()
        nvir = mo_vir.shape[1]

        # partition atoms for parallellisation
        # TODO: use partition_atoms in e.g. scfgradientdriver
        local_atoms = partition_atoms(natm, self.rank, self.nodes)

        # preparing the CPHF RHS
        # TODO: consider using local_atoms instead of all atoms
        ovlp_deriv_ao = np.zeros((natm, 3, nao, nao))
        fock_deriv_ao = np.zeros((natm, 3, nao, nao))

        # For some reason the commented-out line results in a
        # profiler error which I don't understand. Not sure why.
        # It works if it's commented out. TODO: remove?
        #self.profiler.set_timing_key('derivs')
        # TODO: double check the use of profiler
        self.profiler.start_timer('derivs')

        t0 = tm.time()

        if self._dft: 
            xc_mol_hess = XCMolecularHessian()

        ovlp_grad_drv = OverlapGeom100Driver()

        for iatom in local_atoms:

            # compute overlap gradient integrals matrices
            gmats = ovlp_grad_drv.compute(molecule, basis, iatom)

            for x, label in enumerate(['X', 'Y', 'Z']):
                gmat = gmats.matrix_to_numpy(label)
                ovlp_deriv_ao[iatom, x] = gmat + gmat.T

            gmats = Matrices()

            # compute full Fock integrals matrix
            fock_deriv_ao[iatom] = self._compute_fmat_deriv(
                molecule, basis, density, iatom, eri_dict)

        # Note: Parallelization of DFT integration is done over grid points
        # instead of atoms.
        # TODO: Should we change integrate_vxc_fock_gradient to atomwise
        # parallelization?
        # TODO: Think about how to store the (Natm,3,Nao,Nao) objects
        if self._dft:
            for iatom in range(natm):
                vxc_deriv_i = xc_mol_hess.integrate_vxc_fock_gradient(
                    molecule, basis, gs_density, mol_grid,
                    self.xcfun.get_func_label(), iatom)
                fock_deriv_ao[iatom] += vxc_deriv_i

        ovlp_deriv_ao = self.comm.allreduce(ovlp_deriv_ao, op=MPI.SUM)
        fock_deriv_ao = self.comm.allreduce(fock_deriv_ao, op=MPI.SUM)

        t1 = tm.time()

        if self.rank == mpi_master():
            self.ostream.print_info("CPHF/CPKS import of integral derivatives"
                                    + ' took'
                                    + ' {:.2f} sec.'.format(t1 - t0))
            self.ostream.print_blank()
            self.ostream.flush()
            
        self.profiler.stop_timer('derivs')

        ovlp_deriv_ov = np.zeros((natm, 3, nocc, nvir))
        ovlp_deriv_oo = np.zeros((natm, 3, nocc, nocc))
        fock_deriv_ov = np.zeros((natm, 3, nocc, nvir))
        orben_ovlp_deriv_ov = np.zeros((natm, 3, nocc, nvir))

        # transform integral derivatives to MO basis
        for iatom in local_atoms:
            for x in range(3):
                ovlp_deriv_ov[iatom,x,:,:] = np.linalg.multi_dot([
                    mo_occ.T, ovlp_deriv_ao[iatom,x], mo_vir
                ])
                ovlp_deriv_oo[iatom,x,:,:] = np.linalg.multi_dot([
                    mo_occ.T, ovlp_deriv_ao[iatom,x], mo_occ
                ])
                fock_deriv_ov[iatom,x,:,:] = np.linalg.multi_dot([
                    mo_occ.T, fock_deriv_ao[iatom,x], mo_vir
                ])
                orben_ovlp_deriv_ov[iatom,x,:,:] = (
                    eocc.reshape(-1, 1) * ovlp_deriv_ov[iatom,x]
                ) 

        # the oo part of the CPHF coefficients in AO basis,
        # transforming the oo overlap derivative back to AO basis
        # (not equal to the initial one)
        uij_ao = np.zeros((natm, 3, nao, nao))
        
        for iatom in local_atoms:
            for x in range(3):
                uij_ao[iatom,x,:,:] = np.linalg.multi_dot([
                   mo_occ, -0.5 * ovlp_deriv_oo[iatom,x], mo_occ.T 
                ])

        uij_ao = self.comm.reduce(uij_ao, root=mpi_master())
                   
        if self.rank == mpi_master():
            uij_ao_list = [uij_ao[iatom,x] for iatom in range(natm) for x in range(3)]
        else:
            uij_ao_list = None

        # create AODensity and Fock matrix objects, contract with ERI
        fock_uij = self._comp_lr_fock(uij_ao_list, molecule, basis, eri_dict,
                                      dft_dict, pe_dict, self.profiler)

        # _comp_lr_fock only returns value to master
        # TODO: broadcast matrix by matrix
        # TODO: think about parallel storage of fock_uij
        fock_uij = self.comm.bcast(fock_uij, root=mpi_master())

        fock_uij = np.array(fock_uij).reshape(natm, 3, nao, nao)

        # sum up the terms of the RHS

        cphf_rhs = fock_deriv_ov - orben_ovlp_deriv_ov

        for iatom in local_atoms:
            for x in range(3):
                # transform to MO basis
                fock_uij_mo = np.linalg.multi_dot([
                    mo_occ.T, fock_uij[iatom, x], mo_vir
                    ])
                cphf_rhs[iatom,x] += 2.0 * fock_uij_mo

        cphf_rhs = self.comm.reduce(cphf_rhs, root=mpi_master())

        t2 = tm.time() 

        if self.rank == mpi_master():
            self.ostream.print_info('CPHF/CPKS RHS computed in' +
                                     ' {:.2f} sec.'.format(t2 - t1))
            self.ostream.print_blank()
            self.ostream.flush()

        self.profiler.stop_timer('RHS')

        if self.rank == mpi_master():
            return {
                'cphf_rhs': cphf_rhs.reshape(natm * 3, nocc, nvir),
                'ovlp_deriv_oo': ovlp_deriv_oo,
                'fock_deriv_ao': fock_deriv_ao,
                'fock_uij': fock_uij,
            }
        else:
            return None

    def _compute_fmat_deriv(self, molecule, basis, density, i, eri_dict):
        """
        Computes the derivative of the Fock matrix with respect
        to the coordinates of atom i.

        :param molecule:
            The molecule.
        :param basis:
            The basis set.
        :param density:
            The density matrix in AO basis.
        :param i:
            The atom index.
        :param eri_dict:
            The dictionary containing ERI information.

        :return fmat_deriv:
            The derivative of the Fock matrix wrt. atom i.
        """

        # number of atomic orbitals
        nao = basis.get_dimensions_of_basis()

        # initialize fmat variable
        fmat_deriv = np.zeros((3, nao, nao))

        # kinetic integral gadient
        kin_grad_drv = KineticEnergyGeom100Driver()

        gmats_kin = kin_grad_drv.compute(molecule, basis, i)

        for x, label in enumerate(['X', 'Y', 'Z']):
            gmat_kin = gmats_kin.matrix_to_numpy(label)
            fmat_deriv[x] += gmat_kin + gmat_kin.T

        gmats_kin = Matrices()

        # nuclear potential integral gradients
        npot_grad_100_drv = NuclearPotentialGeom100Driver()
        npot_grad_010_drv = NuclearPotentialGeom010Driver()

        gmats_npot_100 = npot_grad_100_drv.compute(molecule, basis, i)
        gmats_npot_010 = npot_grad_010_drv.compute(molecule, basis, i)

        for x, label in enumerate(['X', 'Y', 'Z']):
            gmat_npot_100 = gmats_npot_100.matrix_to_numpy(label)
            gmat_npot_010 = gmats_npot_010.matrix_to_numpy(label)
            fmat_deriv[x] -= gmat_npot_100 + gmat_npot_100.T + gmat_npot_010

        gmats_npot_100 = Matrices()
        gmats_npot_010 = Matrices()

        if self._dft:
            if self.xcfun.is_hybrid():
                fock_type = '2jkx'
                exchange_scaling_factor = self.xcfun.get_frac_exact_exchange()
            else:
                fock_type = 'j'
                exchange_scaling_factor = 0.0
        else:
            exchange_scaling_factor = 1.0
            fock_type = "2jk"

        # TODO: range-separated Fock
        need_omega = (self._dft and self.xcfun.is_range_separated())
        if need_omega:
            assert_msg_critical(
                False, 'HessianOrbitalResponse: Not implemented for' +
                ' range-separated functional')
        
        den_mat_for_fock = make_matrix(basis, mat_t.symmetric)
        den_mat_for_fock.set_values(density)

        # ERI threshold
        thresh_int = int(-math.log10(self.eri_thresh))

        # screening
        screener = eri_dict['screening']

        screener_atom = T4CScreener()
        screener_atom.partition_atom(basis, molecule, 'eri', i)

        # Fock gradient
        fock_grad_drv = FockGeom1000Driver()
        gmats_eri = fock_grad_drv.compute(basis, screener_atom, screener,
                                          den_mat_for_fock, i, fock_type,
                                          exchange_scaling_factor, 0.0,
                                          thresh_int)

        # scaling of Fock gradient for non-hybrid functionals
        factor = 2.0 if fock_type == 'j' else 1.0

        # calculate gradient contributions
        for x, label in enumerate(['X', 'Y', 'Z']):
            gmat_eri = gmats_eri.matrix_to_numpy(label)
            fmat_deriv[x] += gmat_eri * factor

        gmats_eri = Matrices()

        return fmat_deriv

    def print_cphf_header(self, title):
        """
        Prints information on the solver setup
        """

        self.ostream.print_blank()
        self.ostream.print_header('{:s} Setup'.format(title))
        self.ostream.print_header('=' * (len(title) + 8))
        self.ostream.print_blank()

        str_width = 70

        # print general info
        cur_str = 'Solver Type                     : '
        if self.use_subspace_solver:
            cur_str += 'Iterative Subspace Algorithm'
        else:
            cur_str += 'Conjugate Gradient'
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = 'Max. Number of Iterations       : ' + str(self.max_iter)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Convergence Threshold           : {:.1e}'.format(
            self.conv_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))

        self.ostream.print_blank()
        self.ostream.flush()
