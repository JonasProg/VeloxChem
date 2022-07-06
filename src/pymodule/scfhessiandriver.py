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
import numpy as np
import time as tm
import sys

from .molecule import Molecule
from .gradientdriver import GradientDriver
from .hessiandriver import HessianDriver
from .scfgradientdriver import ScfGradientDriver
from .outputstream import OutputStream
from .firstorderprop import FirstOrderProperties
from .orbitalresponse import OrbitalResponse
from .cphfsolver import CphfSolver
from .lrsolver import LinearResponseSolver
from .profiler import Profiler
from .qqscheme import get_qq_scheme
from .veloxchemlib import mpi_master
from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import denmat
from .veloxchemlib import fockmat
from .veloxchemlib import AODensityMatrix
from .veloxchemlib import AOFockMatrix
from .veloxchemlib import ElectricDipoleIntegralsDriver

# For PySCF integral derivatives
from .import_from_pyscf import overlap_deriv
from .import_from_pyscf import fock_deriv
from .import_from_pyscf import eri_deriv
from .import_from_pyscf import overlap_second_deriv
from .import_from_pyscf import hcore_second_deriv
from .import_from_pyscf import eri_second_deriv
from .import_from_pyscf import dipole_deriv
from .import_from_pyscf import dft_xc_second_deriv


class ScfHessianDriver(HessianDriver):
    """
    Implements SCF Hessian driver.

    :param scf_drv:
        The SCF driver.
    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - scf_drv: The SCF driver.
        - do_raman: Additionally calculate Raman intensities
                (at significantly higher computational cost).
        - pople_hessian: Evaluate the Hessian the Pople or
                the Ahlrichs/Furche way.
    """

    def __init__(self, scf_drv, comm=None, ostream=None):
        """
        Initializes SCF Hessian driver.
        """

        super().__init__(comm, ostream)

        self.flag = 'SCF Hessian Driver'
        self.scf_drv = scf_drv
        self.do_raman = False
        self.pople_hessian = False

        # Solver setup
        self.conv_thresh = 1.0e-4
        self.max_iter = 50
        self.iter_count = 0
        self.is_converged = False


    def update_settings(self, method_dict, freq_dict=None, cphf_dict=None):
        """
        Updates settings in ScfHessianDriver.

        :param method_dict:
            The input dictionary of method settings group.
        :param freq_dict:
            The input dictionary of Hessian/frequency settings group.
        :param cphf_dict:
            The input dictionary of CPHF (orbital response) settings.
        """

        super().update_settings(method_dict, freq_dict)

        if freq_dict is None:
            freq_dict = {}

        # Settings for orbital response module
        if cphf_dict is None:
            cphf_dict = {}
        self.cphf_dict = dict(cphf_dict)

        if 'conv_thresh' in cphf_dict:
            self.conv_thresh = float(cphf_dict['conv_thresh'])

        if 'max_iter' in cphf_dict:
            self.max_iter = int(cphf_dict['max_iter'])

        if 'pople_hessian' in freq_dict:
            key = freq_dict['pople_hessian'].lower()
            self.pople_hessian = True if key in ['yes', 'y'] else False

        # check if Raman intensities are to be calculated (numerically)
        if 'do_raman' in freq_dict:
            key = freq_dict['do_raman'].lower()
            self.do_raman = (key in ['yes', 'y'])

        # The electronic energy
        self.elec_energy = self.scf_drv.get_scf_energy()


    def compute(self, molecule, ao_basis, min_basis=None):
        """
        Computes the analytical or numerical nuclear Hessian.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        """
        self.print_header()

        start_time = tm.time()

        profiler = Profiler({
            'timing': self.timing,
            'profiling': self.profiling,
            'memory_profiling': self.memory_profiling,
            'memory_tracing': self.memory_tracing,
        })

        if self.numerical:
            self.compute_numerical(molecule, ao_basis, min_basis)
        else:
            self.compute_analytical(molecule, ao_basis, min_basis, profiler)

        # print Hessian
        if self.do_print_hessian is True:
            self.print_geometry(molecule)
            self.ostream.print_blank()
            self.print_hessian(molecule)

        valstr = '*** Time spent in Hessian calculation: '
        valstr += '{:.2f} sec ***'.format(tm.time() - start_time)
        self.ostream.print_header(valstr)
        self.ostream.print_blank()
        self.ostream.print_blank()
        self.ostream.flush()


    def compute_numerical(self, molecule, ao_basis, min_basis):
        """
        Performs the calculation of a numerical Hessian based only
        on the energy.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        """

        scf_ostream_state = self.scf_drv.ostream.state
        self.scf_drv.ostream.state = False

        # atom labels
        labels = molecule.get_labels()

        # number of atoms
        natm = molecule.number_of_atoms()

        # atom coordinates (nx3)
        coords = molecule.get_coordinates()

        # Hessian
        hessian = np.zeros((natm, 3, natm, 3))

        # First-order properties for gradient of dipole moment
        prop = FirstOrderProperties(self.comm, self.ostream)
        # numerical gradient (3 dipole components, no. atoms x 3 atom coords)
        if self.rank == mpi_master():
            self.dipole_gradient = np.zeros((3, 3 * natm))

        # If Raman intensities are calculated,
        # set up LR solver and member variable
        if self.do_raman:
            # linear response driver for polarizability calculation
            lr_drv = LinearResponseSolver(self.comm, self.scf_drv.ostream)
            # polarizability: 3 coordinates x 3 coordinates
            # (ignoring frequencies)
            # polarizability gradient: dictionary goes through
            # 3 coordinates x 3 coordinates
            # each entry having values for no. atoms x 3 coordinates
            if self.rank == mpi_master():
                self.polarizability_gradient = np.zeros((3, 3, 3 * natm))

        self.scf_drv.compute(molecule, ao_basis, min_basis)
        energy_0 = self.scf_drv.get_scf_energy()

        for i in range(natm):
            for x in range(3):
                # Plus x
                coords[i, x] += self.delta_h
                new_mol = Molecule(labels, coords, units='au')
                self.scf_drv.compute(new_mol, ao_basis, min_basis)
                energy_ixp = self.scf_drv.get_scf_energy()

                prop.compute_scf_prop(new_mol, ao_basis,
                                      self.scf_drv.scf_tensors)
                if self.rank == mpi_master():
                    mu_plus = prop.get_property('dipole moment')

                if self.do_raman:
                    lr_drv.is_converged = False
                    lr_results_p = lr_drv.compute(new_mol, ao_basis,
                                                  self.scf_drv.scf_tensors)

                # Minus x
                coords[i, x] -= 2.0 * self.delta_h
                new_mol = Molecule(labels, coords, units='au')
                self.scf_drv.compute(new_mol, ao_basis, min_basis)
                energy_ixm = self.scf_drv.get_scf_energy()

                prop.compute_scf_prop(new_mol, ao_basis,
                                      self.scf_drv.scf_tensors)
                if self.rank == mpi_master():
                    mu_minus = prop.get_property('dipole moment')

                if self.do_raman:
                    lr_drv.is_converged = False
                    lr_results_m = lr_drv.compute(new_mol, ao_basis,
                                                  self.scf_drv.scf_tensors)
                    if self.rank == mpi_master():
                        for ind_aop, aop in enumerate('xyz'):
                            for ind_bop, bop in enumerate('xyz'):
                                # TODO: here the freq. is hard-coded to 0.0!
                                comp_plus = (
                                    lr_results_p['response_functions'][aop, bop,
                                                                       0.0])
                                comp_minus = (
                                    lr_results_m['response_functions'][aop, bop,
                                                                       0.0])
                                self.polarizability_gradient[
                                    ind_aop, ind_bop,
                                    3 * i + x] = ((comp_plus - comp_minus) /
                                                  (2.0 * self.delta_h))

                if self.rank == mpi_master():
                    for c in range(3):
                        self.dipole_gradient[c, 3 * i +
                                             x] = ((mu_plus[c] - mu_minus[c]) /
                                                   (2.0 * self.delta_h))

                hessian[i, x, i,
                        x] = ((energy_ixp - 2 * energy_0 + energy_ixm) /
                              self.delta_h**2)
                coords[i, x] += self.delta_h

                for j in range(i, natm):
                    for y in range(3):
                        if (j == i and x != y) or (j != i):
                            # Plus y
                            coords[j, y] += self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            self.scf_drv.compute(new_mol, ao_basis, min_basis)
                            energy_jyp = self.scf_drv.get_scf_energy()

                            # Plus x, plus y
                            coords[i, x] += self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            self.scf_drv.compute(new_mol, ao_basis, min_basis)
                            energy_ixp_jyp = self.scf_drv.get_scf_energy()
                            coords[i, x] -= self.delta_h

                            # Minus y
                            coords[j, y] -= 2.0 * self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            self.scf_drv.compute(new_mol, ao_basis, min_basis)
                            energy_jym = self.scf_drv.get_scf_energy()

                            # Minus x, minus y:
                            coords[i, x] -= self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            self.scf_drv.compute(new_mol, ao_basis, min_basis)
                            energy_ixm_jym = self.scf_drv.get_scf_energy()

                            coords[i, x] += self.delta_h
                            coords[j, y] += self.delta_h

                            hessian[i, x, j, y] = (
                                (energy_ixp_jyp - energy_ixp - energy_jyp +
                                 2 * energy_0 - energy_ixm - energy_jym +
                                 energy_ixm_jym) / (2 * self.delta_h**2))
                            hessian[j, y, i, x] = hessian[i, x, j, y]
        # reshaped Hessian as member variable
        self.hessian = hessian.reshape(3 * natm, 3 * natm)

        # restore scf_drv to initial state
        self.scf_drv.compute(molecule, ao_basis, min_basis)
        self.scf_drv.ostream.state = scf_ostream_state


    def compute_analytical(self, molecule, ao_basis, min_basis, profiler):
        """
        Computes the analytical nuclear Hessian.
        So far only for restricted Hartree-Fock with PySCF integral derivatives...

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        :param profiler:
            The profiler.
        """

        scf_tensors = self.scf_drv.scf_tensors
        density = scf_tensors['D_alpha']
        natm = molecule.number_of_atoms()
        mo = scf_tensors['C_alpha']
        nao = mo.shape[0]
        nocc = molecule.number_of_alpha_electrons()
        mo_occ = mo[:, :nocc]
        mo_vir = mo[:, nocc:]
        nvir = mo_vir.shape[1]
        mo_energies = scf_tensors['E']
        eocc = mo_energies[:nocc]
        eoo = eocc.reshape(-1, 1) + eocc #ei+ej
        omega_ao = - np.linalg.multi_dot([mo_occ, np.diag(eocc), mo_occ.T])


        # Set up a CPHF solver
        cphf_solver = CphfSolver(self.comm, self.ostream, self.scf_drv) # TODO: remove scf_drv
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)

        # Solve the CPHF equations
        cphf_solver.compute(molecule, ao_basis, scf_tensors)
        cphf_solution_dict = cphf_solver.cphf_results
        cphf_ov = cphf_solution_dict['cphf_ov'].reshape(natm, 3, nocc, nvir)
        ovlp_deriv_oo = cphf_solution_dict['ovlp_deriv_oo']

        # Calculate the perturbed density matrix
        # cphf_oo = -0.5*ovlp_deriv_oo
        perturbed_density = ( - np.einsum('mj,xyij,ni->xymn',
                                        mo_occ, ovlp_deriv_oo, mo_occ)
                              + np.einsum('ma,xyia,ni->xymn',
                                        mo_vir, cphf_ov, mo_occ)
                              + np.einsum('mi,xyia,na->xymn',
                                        mo_occ, cphf_ov, mo_vir)
                            )

        # Parts related to first-order integral derivatives
        if self.pople_hessian:
            fock_uij = cphf_solution_dict['fock_uij']
            fock_deriv_ao = cphf_solution_dict['fock_deriv_ao']
            fock_deriv_oo = np.einsum('mi,xymn,nj->xyij', mo_occ, fock_deriv_ao, mo_occ)
            # (ei+ej)S^\chi_ij
            orben_ovlp_deriv_oo = np.einsum('ij,xyij->xyij', eoo, ovlp_deriv_oo)
            hessian_first_order_derivatives = self.compute_pople(molecule, ao_basis,
                                             -0.5 * ovlp_deriv_oo, cphf_ov, fock_uij,
                                              fock_deriv_oo, orben_ovlp_deriv_oo, perturbed_density,
                                              profiler)
        else:
            cphf_rhs = cphf_solution_dict['cphf_rhs'].reshape(natm, 3, nocc, nvir)
            hessian_first_order_derivatives = self.compute_furche(molecule, ao_basis,
                                                         cphf_rhs, -0.5 * ovlp_deriv_oo, cphf_ov,
                                                         profiler)

        # amount of exact exchange
        frac_K = 1.0

        # DFT:
        if self.dft:
            if self.scf_drv.xcfun.is_hybrid():
                frac_K = self.scf_drv.xcfun.get_frac_exact_exchange()
            else:
                frac_K = 0.0

            # DFT exchange and correlation contribution
            hessian_dft_xc = dft_xc_second_deriv(molecule, ao_basis, self.scf_drv)

        # Parts related to second-order integral derivatives
        hessian_2nd_order_derivatives = np.zeros((natm, natm, 3, 3))
        for i in range(natm):
            # do only upper triangular matrix
            for j in range(i, natm):
                # Get integral second-order derivatives
                ovlp_2nd_deriv_ii, ovlp_2nd_deriv_ij = overlap_second_deriv(molecule, ao_basis, i, j)
                hcore_2nd_deriv_ij = hcore_second_deriv(molecule, ao_basis, i, j)
                eri_2nd_deriv_ii, eri_2nd_deriv_ij = eri_second_deriv(molecule, ao_basis, i, j)
                if i == j:
                    # Add diagonal (same atom) contributions, 2S + 2J - K
                    hessian_2nd_order_derivatives[i,i] += 2*np.einsum('mn,xymn->xy', omega_ao, ovlp_2nd_deriv_ii)
                    hessian_2nd_order_derivatives[i,i] += 2*np.einsum('mn,kl,xymnkl->xy', density, density, eri_2nd_deriv_ii)
                    hessian_2nd_order_derivatives[i,i] -= frac_K*np.einsum('mk,nl,xymnkl->xy', density, density, eri_2nd_deriv_ii)
                # Add non-diagonal contributions, 2S + 2J - K + 2h
                hessian_2nd_order_derivatives[i,j] += 2*np.einsum('mn,kl,xymnkl->xy', density, density, eri_2nd_deriv_ij)
                hessian_2nd_order_derivatives[i,j] -= frac_K*np.einsum('mk,nl,xymnkl->xy', density, density, eri_2nd_deriv_ij)
                hessian_2nd_order_derivatives[i,j] += 2*np.einsum('mn,xymn->xy', omega_ao, ovlp_2nd_deriv_ij)
                hessian_2nd_order_derivatives[i,j] += 2*np.einsum('mn,xymn->xy', density, hcore_2nd_deriv_ij)

            # lower triangle is transpose of the upper part
            for j in range(i):
                hessian_2nd_order_derivatives[i,j] += hessian_2nd_order_derivatives[j,i].T

        # Nuclear-nuclear repulsion contribution
        hessian_nuclear_nuclear = self.hess_nuc_contrib(molecule)

        # Sum up the terms and reshape for final Hessian
        self.hessian = ( hessian_first_order_derivatives + hessian_2nd_order_derivatives
                       + hessian_nuclear_nuclear ).transpose(0,2,1,3).reshape(3*natm, 3*natm)

        if self.dft:
            self.hessian += hessian_dft_xc.transpose(0,2,1,3).reshape(3*natm, 3*natm)

        # Calculate the gradient of the dipole moment, needed for IR intensities
        self.compute_dipole_gradient(molecule, ao_basis, perturbed_density)


    def compute_pople(self, molecule, ao_basis, cphf_oo, cphf_ov, fock_uij,
                      fock_deriv_oo, orben_ovlp_deriv_oo, perturbed_density,
                      profiler):
        """
        Computes the analytical nuclear Hessian the Pople way.
        Int. J. Quantum Chem. Quantum Chem. Symp. 13, 225-241 (1979).
        DOI: 10.1002/qua.560160825

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param cphf_oo:
            The oo block of the CPHF coefficients.
        :param cphf_ov:
            The ov block of the CPHF coefficients.
        :param fock_uij:
            The auxiliary Fock matrix constructed
            using the oo block of the CPHF coefficients
            and two electron integrals.
        :param fock_deriv_oo:
            The oo block of the derivative of the Fock matrix
            with respect to nuclear coordinates
        :param orben_ovlp_deriv_oo:
            The oo block of the derivative of the overlap matrix
            with respect to nuclear coordinates, multiplied with
            orbital energies (ei+ej)S^\chi_ij
        :param perturbed_density:
            The perturbed density matrix.
        :param profiler:
            The profiler.
        """

        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()
        mo = self.scf_drv.scf_tensors['C']
        mo_occ = mo[:, :nocc].copy()
        mo_vir = mo[:, nocc:].copy()
        nao = mo.shape[0]
        density = self.scf_drv.scf_tensors['D_alpha']
        mo_energies = self.scf_drv.scf_tensors['E']
        eocc = mo_energies[:nocc]
        eo_diag = np.diag(eocc)
        epsilon_dm_ao = - np.linalg.multi_dot([mo_occ, eo_diag, mo_occ.T])

        # Construct the perturbed density matrix, and perturbed omega
        # TODO: consider if using the transpose makes the
        # computation faster; consider using cphf coefficients in AO
        # to compute the perturbed density matrix.
        ##perturbed_density = ( 2 * np.einsum('mj,xyij,ni->xymn',
        ##                                mo_occ, cphf_oo, mo_occ)
        ##                      + np.einsum('ma,xyia,ni->xymn',
        ##                                mo_vir, cphf_ov, mo_occ)
        ##                      + np.einsum('mi,xyia,na->xymn',
        ##                                mo_occ, cphf_ov, mo_vir)
        ##                    )
        orben_perturbed_density = ( np.einsum('i,mj,xyij,ni->xymn',
                                            eocc, mo_occ, cphf_oo, mo_occ)
                                  + np.einsum('i,mi,xyij,nj->xymn',
                                            eocc, mo_occ, cphf_oo, mo_occ)
                                  + np.einsum('i,ma,xyia,ni->xymn',
                                            eocc, mo_vir, cphf_ov, mo_occ)
                                  +np.einsum('i,mi,xyia,na->xymn',
                                            eocc, mo_occ, cphf_ov, mo_vir)
                                 )

        # Transform the CPHF coefficients to AO:
        uia_ao = np.einsum('mk,xykb,nb->xymn', mo_occ, cphf_ov, mo_vir).reshape((3*natm, nao, nao))

        # create AODensity and Fock matrix objects, contract with ERI
        uia_ao_list = list([uia_ao[x] for x in range(natm * 3)])
        ao_density_uia = AODensityMatrix(uia_ao_list, denmat.rest)

        fock_uia = AOFockMatrix(ao_density_uia)

        fock_flag = fockmat.rgenjk
        for i in range(natm*3):
            fock_uia.set_fock_type(fock_flag, i)

        # TODO: remove commented out code.
        #eri_drv = ElectronRepulsionIntegralsDriver(self.comm)
        #screening = eri_drv.compute(get_qq_scheme(self.scf_drv.qq_type),
        #                            self.scf_drv.eri_thresh, molecule, ao_basis)
        #eri_drv.compute(fock_uia, ao_density_uia, molecule, ao_basis, screening)

        # We use comp_lr_fock from CphfSolver to compute the eri
        # and xc contributions
        cphf_solver = CphfSolver(self.comm, self.ostream, self.scf_drv) # TODO: remove scf_drv
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)
        # ERI information
        eri_dict = cphf_solver.init_eri(molecule, ao_basis)
        # DFT information
        dft_dict = cphf_solver.init_dft(molecule, self.scf_drv.scf_tensors)
        # PE information
        pe_dict = cphf_solver.init_pe(molecule, ao_basis)

        cphf_solver.comp_lr_fock(fock_uia, ao_density_uia, molecule, ao_basis,
                                 eri_dict, dft_dict, pe_dict, profiler)

        # TODO: can this be done in a different way?
        fock_uia_numpy = np.zeros((natm,3,nao,nao))
        for i in range(natm):
            for x in range(3):
                fock_uia_numpy[i,x] = fock_uia.to_numpy(3*i + x)

        fock_cphf_oo = np.einsum('mi,xymn,nj->xyij', mo_occ, fock_uij, mo_occ)

        fock_cphf_ov = ( np.einsum('mi,xymn,nj->xyij', mo_occ,
                                   fock_uia_numpy, mo_occ)
                        +np.einsum('mj,xymn,ni->xyij', mo_occ,
                                   fock_uia_numpy, mo_occ)
                        )
        # Construct the derivative of the omega multipliers:
        perturbed_omega_ao = - ( orben_perturbed_density
                                + np.einsum('mi,xyij,nj->xymn', mo_occ,
                                            fock_deriv_oo, mo_occ)
                                -0.5*np.einsum('mi,xyij,nj->xymn', mo_occ,
                                                orben_ovlp_deriv_oo, mo_occ)
                                + 2*np.einsum('mi,xyij,nj->xymn', mo_occ,
                                            fock_cphf_oo, mo_occ)
                                + np.einsum('mi,xyij,nj->xymn', mo_occ,
                                            fock_cphf_ov, mo_occ)
                                )

        # First integral derivatives: partial Fock and overlap matrix derivatives
        hessian_first_integral_derivatives = np.zeros((natm, natm, 3, 3))

        for i in range(natm):
            # upper triangular part
            for j in range(i, natm):
                # First derivative of the Fock matrix
                fock_deriv_j = fock_deriv(molecule, ao_basis, density, j, self.scf_drv)
                # First derivative of overlap matrix
                ovlp_deriv_j = overlap_deriv(molecule, ao_basis, j)
                # Add the contribution of the perturbed density matrix
                hessian_first_integral_derivatives[i,j] += np.einsum('xmn,ymn->xy', 2*perturbed_density[i], fock_deriv_j)
                hessian_first_integral_derivatives[i,j] += np.einsum('xmn,ymn->xy', 2*perturbed_omega_ao[i], ovlp_deriv_j)

            # lower triangular part
            for j in range(i):
                hessian_first_integral_derivatives[i,j] += hessian_first_integral_derivatives[j,i].T

        return hessian_first_integral_derivatives


    def compute_furche(self, molecule, ao_basis, cphf_rhs, cphf_oo, cphf_ov,
                       profiler):
        """
        Computes the analytical nuclear Hessian the Furche/Ahlrichs way.
        Chem. Phys. Lett. 362, 511–518 (2002).
        DOI: 10.1016/S0009-2614(02)01084-9

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param cphf_rhs:
            The RHS of the CPHF equations in MO basis.
        :param cphf_oo:
            The oo block of the CPHF coefficients.
        :param cphf_ov:
            The ov block of the CPHF coefficients.
        :param profiler:
            The profiler.
        """

        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()
        mo = self.scf_drv.scf_tensors['C']
        mo_occ = mo[:, :nocc].copy()
        nao = mo.shape[0]
        density = self.scf_drv.scf_tensors['D_alpha']
        mo_energies = self.scf_drv.scf_tensors['E']
        eocc = mo_energies[:nocc]
        omega_ao = - np.linalg.multi_dot([mo_occ, np.diag(eocc), mo_occ.T])

        # TODO: remove commented out code
        #eri_drv = ElectronRepulsionIntegralsDriver(self.comm)
        #screening = eri_drv.compute(get_qq_scheme(self.scf_drv.qq_type),
        #                            self.scf_drv.eri_thresh, molecule, ao_basis)

        # We use comp_lr_fock from CphfSolver to compute the eri
        # and xc contributions
        cphf_solver = CphfSolver(self.comm, self.ostream, self.scf_drv) # TODO: remove scf_drv
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)
        # ERI information
        eri_dict = cphf_solver.init_eri(molecule, ao_basis)
        # DFT information
        dft_dict = cphf_solver.init_dft(molecule, self.scf_drv.scf_tensors)
        # PE information
        pe_dict = cphf_solver.init_pe(molecule, ao_basis)

        # RHS contracted with CPHF coefficients (ov)
        #hessian_cphf_coeff_rhs = np.zeros((natm, natm, 3, 3))
        #for i in range(natm):
        #    for j in range(natm):
        #        hessian_cphf_coeff_rhs[i,j] += 4*np.einsum('xia,yia->xy', cphf_ov[i], cphf_rhs[j])
        hessian_cphf_coeff_rhs = 4 * np.einsum('ixka,jyka->ijxy', cphf_ov, cphf_rhs)

        # First integral derivatives: partial Fock and overlap matrix derivatives
        hessian_first_integral_derivatives = np.zeros((natm, natm, 3, 3))
        for i in range(natm):
            fock_deriv_i = fock_deriv(molecule, ao_basis, density, i, self.scf_drv)
            ovlp_deriv_i = overlap_deriv(molecule, ao_basis, i)
            # upper triangular part
            for j in range(i, natm):
                ovlp_deriv_j = overlap_deriv(molecule, ao_basis, j)
                fock_deriv_j = fock_deriv(molecule, ao_basis, density, j, self.scf_drv)
                Fix_Sjy = np.zeros((3,3))
                Fjy_Six = np.zeros((3,3))
                Six_Sjy = np.zeros((3,3))
                for x in range(3):
                    for y in range(3):
                        Fix_Sjy[x,y] = np.trace(np.linalg.multi_dot([density, fock_deriv_i[x], density, ovlp_deriv_j[y]]))
                        Fjy_Six[x,y] = np.trace(np.linalg.multi_dot([density, fock_deriv_j[y], density, ovlp_deriv_i[x]]))
                        Six_Sjy[x,y] = ( 2*np.trace(np.linalg.multi_dot([omega_ao, ovlp_deriv_i[x], density, ovlp_deriv_j[y]])) )
                hessian_first_integral_derivatives[i,j] += -2 * (Fix_Sjy + Fjy_Six + Six_Sjy)
                ##hessian_first_integral_derivatives[i,j] += 2*(-np.einsum('xmn,ykl,mk,nl->xy', fock_deriv_i, ovlp_deriv_j, density, density)
                ##                                                           -np.einsum('ymn,xkl,mk,nl->xy', fock_deriv_j, ovlp_deriv_i, density, density)
                ##                                                           - np.einsum('xmn,ykl,mk,nl->xy', ovlp_deriv_i, ovlp_deriv_j, omega_ao, density)
                ##                                                           - np.einsum('xmn,ykl,nl,mk->xy', ovlp_deriv_i, ovlp_deriv_j, omega_ao, density)
                ##                                                  )
                ##
                ##
                ##

            # lower triangular part
            for j in range(i):
                hessian_first_integral_derivatives[i,j] += hessian_first_integral_derivatives[j,i].T

        # Overlap derivative with ERIs
        hessian_eri_overlap = np.zeros((natm, natm, 3, 3))
        for i in range(natm):
            ovlp_deriv_i = overlap_deriv(molecule, ao_basis, i)
            # upper triangular part
            for j in range(i, natm):
                ovlp_deriv_j = overlap_deriv(molecule, ao_basis, j)

                # Overlap derivative contracted with two density matrices
                ##P_P_Six = np.zeros((3, nao, nao))
                ##P_P_Sjy = np.zeros((3, nao, nao))
                ##for x in range(3):
                ##    P_P_Six[x] = (np.linalg.multi_dot([density, ovlp_deriv_i[x], density]))
                ##    P_P_Sjy[x] = (np.linalg.multi_dot([density, ovlp_deriv_j[x], density]))
                P_P_Six = np.einsum('mn,xnk,kl->xml', density, ovlp_deriv_i, density)
                P_P_Sjy = np.einsum('mn,xnk,kl->xml', density, ovlp_deriv_j, density)

                # Create a list of 2D numpy arrays to create AODensityMatrix objects
                # and calculate auxiliary Fock matrix with ERI driver
                P_P_Six_ao_list = list([P_P_Six[x] for x in range(3)])
                P_P_Six_dm_ao = AODensityMatrix(P_P_Six_ao_list, denmat.rest)
                P_P_Six_fock_ao = AOFockMatrix(P_P_Six_dm_ao)

                # TODO: remove commented out code
                #eri_drv.compute(P_P_Six_fock_ao, P_P_Six_dm_ao, molecule, ao_basis, screening)
                cphf_solver.comp_lr_fock(P_P_Six_fock_ao, P_P_Six_dm_ao, molecule, ao_basis,
                                         eri_dict, dft_dict, pe_dict, profiler)

                # Convert the auxiliary Fock matrices to numpy arrays for further use
                np_P_P_Six_fock = np.zeros((3,nao,nao))
                for k in range(3):
                    np_P_P_Six_fock[k] = P_P_Six_fock_ao.to_numpy(k)

                hessian_eri_overlap[i,j] += 2.0 * np.einsum('xmn,ymn->xy', np_P_P_Six_fock, P_P_Sjy)

            # lower triangular part
            for j in range(i):
                hessian_eri_overlap[i,j] += hessian_eri_overlap[j,i].T

        # return the sum of the three contributions
        return (hessian_cphf_coeff_rhs + hessian_first_integral_derivatives
                         + hessian_eri_overlap)


    # TODO: make this option available
    def compute_numerical_with_analytical_gradient(self, molecule, ao_basis, min_basis=None, profiler=None):

        """
        Performs calculation of numerical Hessian.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        :param profiler:
            The profiler.
        """

        if profiler is None:
            profiler = Profiler({
                'timing': self.timing,
                'profiling': self.profiling,
                'memory_profiling': self.memory_profiling,
                'memory_tracing': self.memory_tracing,
            })


        # settings dictionary for gradient driver
        grad_dict = dict(self.freq_dict)
        if self.numerical_grad:
            grad_dict['numerical'] = 'yes'
            warn_msg = '*** Warning: Numerical Hessian will be calculated based on numerical gradient.'
            self.ostream.print_header(warn_msg.ljust(56))
            warn_msg = '  This takes a long time and has limited accuracy.'
            self.ostream.print_header(warn_msg.ljust(56))
            self.ostream.print_blank()
            self.ostream.flush()
        else:
            grad_dict['numerical'] = 'no'

        scf_ostream_state = self.scf_drv.ostream.state
        self.scf_drv.ostream.state = False

        # atom labels
        labels = molecule.get_labels()

        # number of atoms
        natm = molecule.number_of_atoms()

        # atom coordinates (nx3)
        coords = molecule.get_coordinates()

        # gradient driver
        grad_drv = ScfGradientDriver(self.scf_drv, self.scf_drv.comm, self.scf_drv.ostream)
        grad_drv.update_settings(grad_dict, self.method_dict)

        # number of atomic orbitals
        nao = self.scf_drv.scf_tensors['D_alpha'].shape[0]

        # Hessian
        hessian = np.zeros((natm, 3, natm, 3))

        # First-order properties for gradient of dipole moment
        prop = FirstOrderProperties(self.comm, self.ostream)
        # numerical gradient (3 dipole components, no. atoms x 3 atom coords)
        #self.dipole_gradient = np.zeros((3, natm, 3))
        self.dipole_gradient = np.zeros((3, 3 * natm))

        # If Raman intensities are calculated, set up LR solver and member variable
        if self.do_raman:
            # linear response driver for polarizability calculation
            lr_drv = LinearResponseSolver(self.comm, self.scf_drv.ostream)
            #lr_ostream_state = lr_drv.ostream.state
            #lr_drv.ostream.state = False
            # polarizability: 3 coordinates x 3 coordinates (ignoring frequencies)
            # polarizability gradient: dictionary goes through 3 coordinates x 3 coordinates
            # each entry having values for no. atoms x 3 coordinates
            self.polarizability_gradient = np.zeros((3, 3, 3 * natm))
            # dictionary to translate from numbers to operator components 'xyz'
            component_dict = {0: 'x', 1: 'y', 2: 'z'}


        if not self.do_four_point:
            for i in range(natm):
                for d in range(3):
                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_plus = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_p = lr_drv.compute(new_mol, ao_basis,
                                                      self.scf_drv.scf_tensors)


                    coords[i, d] -= 2.0 * self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_minus = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_m = lr_drv.compute(new_mol, ao_basis,
                                                           self.scf_drv.scf_tensors)
                        for aop in range(3):
                            #for bop in lr_drv.b_components:
                            for bop in range(3):
                                self.polarizability_gradient[aop, bop, 3*i + d] = (
                                    # TODO: careful with the hard-coded frequency!!
                                    ( lr_results_p['response_functions'][component_dict[aop], component_dict[bop], 0.0]
                                    - lr_results_m['response_functions'][component_dict[aop], component_dict[bop], 0.0] ) /
                                    (2.0 * self.delta_h) )


                    for c in range(3):
                        self.dipole_gradient[c, 3*i + d] = (mu_plus[c] - mu_minus[c]) / (2.0 * self.delta_h)
                    coords[i, d] += self.delta_h
                    hessian[i, d, :, :] = (grad_plus - grad_minus) / (2.0 * self.delta_h)
        else:
            # Four-point numerical derivative approximation
            # for debugging of analytical Hessian:
            # [ f(x - 2h) - 8 f(x - h) + 8 f(x + h) - f(x + 2h) ] / ( 12h )
            for i in range(natm):
                for d in range(3):
                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus1 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_plus1 = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_p1 = lr_drv.compute(new_mol, ao_basis,
                                                           self.scf_drv.scf_tensors)

                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus2 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_plus2 = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_p2 = lr_drv.compute(new_mol, ao_basis,
                                                           self.scf_drv.scf_tensors)

                    coords[i, d] -= 3.0 * self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus1 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_minus1 = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_m1 = lr_drv.compute(new_mol, ao_basis,
                                                           self.scf_drv.scf_tensors)

                    coords[i, d] -= self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_drv.compute(new_mol, ao_basis, min_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus2 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis, self.scf_drv.scf_tensors)
                    mu_minus2 = prop.get_property('dipole moment')

                    if self.do_raman:
                        lr_drv.is_converged = False
                        lr_results_m2 = lr_drv.compute(new_mol, ao_basis,
                                                           self.scf_drv.scf_tensors)

                        for aop in range(3):
                            for bop in range(3):
                                self.polarizability_gradient[aop, bop, 3*i + d] = (
                                    ( lr_results_m2['response_functions'][component_dict[aop], component_dict[bop], 0.0]
                                    - 8 * lr_results_m1['response_functions'][component_dict[aop], component_dict[bop], 0.0]
                                    + 8 * lr_results_p1['response_functions'][component_dict[aop], component_dict[bop], 0.0]
                                    - lr_results_p2['response_functions'][component_dict[aop], component_dict[bop], 0.0] ) /
                                    (12.0 * self.delta_h) )

                    for c in range(3):
                        self.dipole_gradient[c, 3*i + d] = (mu_minus2[c] - 8.0 * mu_minus1[c]
                                                         + 8.0 * mu_plus1[c] - mu_plus2[c]) / (12.0 * self.delta_h)
                    coords[i, d] += 2.0 * self.delta_h
                    # f'(x) ~ [ f(x - 2h) - 8 f(x - h) + 8 f(x + h) - f(x + 2h) ] / ( 12h )
                    hessian[i, d] = (grad_minus2 - 8.0 * grad_minus1
                                           + 8.0 * grad_plus1 - grad_plus2) / (12.0 * self.delta_h)

        # reshaped Hessian as member variable
        self.hessian = hessian.reshape(3*natm, 3*natm)

        #self.ostream.print_blank()

        self.scf_drv.compute(molecule, ao_basis, min_basis)
        self.scf_drv.ostream.state = scf_ostream_state

    def compute_dipole_gradient(self, molecule, ao_basis, perturbed_density):
        """
        Computes the analytical gradient of the dipole moment.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param perturbed_density:
            The perturbed density matrix.
        """

        # Number of atoms and atomic charges
        natm = molecule.number_of_atoms()
        nuclear_charges = molecule.elem_ids_to_numpy()

        density = self.scf_drv.scf_tensors['D_alpha']

        # Dipole integrals
        dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
        dipole_mats = dipole_drv.compute(molecule, ao_basis)
        dipole_ints = np.array((dipole_mats.x_to_numpy(), dipole_mats.y_to_numpy(),
                       dipole_mats.z_to_numpy()))

        # Initialize a local dipole gradient to zero
        dipole_gradient = np.zeros((3, natm, 3))

        # Put the nuclear contributions to the right place
        natm_zeros = np.zeros((natm))
        dipole_gradient[0] = np.vstack((nuclear_charges, natm_zeros, natm_zeros)).T
        dipole_gradient[1] = np.vstack((natm_zeros, nuclear_charges, natm_zeros)).T
        dipole_gradient[2] = np.vstack((natm_zeros, natm_zeros, nuclear_charges)).T

        # TODO: replace once veloxchem analytical integral derivatives are available
        # TODO: replace the full array of dipole integrals derivatives with
        # the derivative with respect to each atom and contract with the densities
        # in the same way as done for the energy gradient.
        dipole_integrals_deriv = self.compute_dipole_integral_derivatives(molecule, ao_basis)

        # Add the electronic contributions
        dipole_gradient += -2 * (np.einsum('mn,caxmn->cax', density, dipole_integrals_deriv)
                           + np.einsum('axmn,cmn->cax', perturbed_density, dipole_ints)
                           )

        self.dipole_gradient = dipole_gradient.reshape(3, 3 * natm)


    def compute_dipole_integral_derivatives(self, molecule, ao_basis):
        """
        Imports the analytical derivatives of dipole integrals.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.

        :return:
            The dipole integral derivatives.
        """

        # number of atoms
        natm = molecule.number_of_atoms()

        # number of atomic orbitals
        nao = self.scf_drv.scf_tensors['D_alpha'].shape[0]

        # 3 dipole components x No. atoms x 3 atomic coordinates x No. basis x No. basis
        dipole_integrals_gradient = np.zeros((3, natm, 3, nao, nao))

        for i in range(natm):
            dipole_integrals_gradient[:,i,:,:,:] = (
                                dipole_deriv(molecule, ao_basis, i)
                                )

        return dipole_integrals_gradient

