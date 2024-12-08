#
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

import numpy as np
import time as tm

from .molecule import Molecule
from .griddriver import GridDriver
from .hessiandriver import HessianDriver
from .scfgradientdriver import ScfGradientDriver
from .firstorderprop import FirstOrderProperties
from .hessianorbitalresponse import HessianOrbitalResponse
from .profiler import Profiler
from .matrices import Matrices
from .dftutils import get_default_grid_level
from .veloxchemlib import mpi_master
from .veloxchemlib import XCMolecularHessian
from .errorhandler import assert_msg_critical
from .oneeints import compute_electric_dipole_integrals

# vlx integrals
from .veloxchemlib import ElectricDipoleMomentGeom100Driver
from .veloxchemlib import OverlapGeom100Driver

# For PySCF integral derivatives
from .import_from_pyscf import overlap_second_deriv
from .import_from_pyscf import hcore_second_deriv
from .import_from_pyscf import eri_second_deriv
from .import_from_pyscf import dipole_deriv

class ScfHessianDriver(HessianDriver):
    """
    Implements SCF Hessian driver.

    :param scf_drv:
        The SCF driver.

    Instance variables
        - hessian: The Hessian in Hartree per Bohr**2.
        - flag: The type of Hessian driver.
        - do_pople_hessian: Evaluate the Hessian the Pople or
                the Ahlrichs/Furche way.
        - numerical_grad: Perform numerical gradient calculation.
        - perturbed_density: The perturbed density
    """

    def __init__(self, scf_drv, comm=None, ostream=None):
        """
        Initializes SCF Hessian driver.
        """

        super().__init__(scf_drv.comm, scf_drv.ostream)

        self.flag = 'SCF Hessian Driver'
        self.scf_driver = scf_drv

        self.numerical_grad = False

        self.do_pople_hessian = False

        self.perturbed_density = None

        # TODO TEMPORARY FLAG
        # Only run orbital response for performance testing
        self.orbrsp_only = False

        # flag for printing the Hessian
        self.do_print_hessian = False

        # TODO: determine _block_size_factor for SCF Hessian driver
        # self._block_size_factor = 4

        self._xcfun_ldstaging = scf_drv._xcfun_ldstaging

        self._input_keywords['hessian'].update({
                'do_pople_hessian': ('bool', 'whether to compute Pople Hessian'),
                'numerical_grad': ('bool', 'whether the gradient is numerical'),
                'orbrsp_only': ('bool', 'whether to only run CPHF orbital response'),
            })

    def update_settings(self, method_dict, hess_dict=None, cphf_dict=None):
        """
        Updates settings in ScfHessianDriver.

        :param method_dict:
            The input dictionary of method settings group.
        :param hess_dict:
            The input dictionary of Hessian settings group.
        :param cphf_dict:
            The input dictionary of CPHF (orbital response) settings.
        :param rsp_dict:
            The input dictionary for linear response settings
            (needed to compute the polarizability gradient).
        """

        super().update_settings(method_dict, hess_dict)

        if cphf_dict is None:
            cphf_dict = {}

        self.cphf_dict = dict(cphf_dict)

    def compute(self, molecule, ao_basis):
        """
        Computes the analytical or numerical nuclear Hessian.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """

        if self.rank == mpi_master():
            self.print_header()

        start_time = tm.time()

        # TODO: find a better place for the profiler?
        profiler = Profiler({
            'timing': self.timing,
            'profiling': self.profiling,
            'memory_profiling': self.memory_profiling,
            'memory_tracing': self.memory_tracing,
        })

        # Save the electronic energy
        self.elec_energy = self.scf_driver.get_scf_energy()

        # TODO TEMPORARY
        if self.orbrsp_only:
            self.ostream.print_header('*** WARNING only computing Hessian orbital response!')
            self.compute_orbital_response(molecule, ao_basis)
            self.ostream.print_header('*** Hessian orbital response only: DONE  ***')
            self.ostream.flush()
            return

        if self.numerical:
            self.compute_numerical(molecule, ao_basis)
        else:
            self.compute_analytical(molecule, ao_basis, profiler)

        # Calculate the gradient of the dipole moment for IR intensities
        if self.do_dipole_gradient and (self.perturbed_density is not None):
            self.compute_dipole_gradient(molecule, ao_basis)

        if self.rank == mpi_master():
            # print Hessian
            if self.do_print_hessian:
                self.print_geometry(molecule)
                self.ostream.print_blank()
                self.print_hessian(molecule)

            valstr = '*** Time spent in Hessian calculation: '
            valstr += '{:.2f} sec ***'.format(tm.time() - start_time)
            self.ostream.print_header(valstr)
            self.ostream.print_blank()
            self.ostream.print_blank()
            self.ostream.flush()

    # TODO: check if compute numerical works with MPI
    def compute_numerical(self, molecule, ao_basis):
        """
        Performs the calculation of a numerical Hessian based only
        on the energy.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """

        self.ostream.mute()

        # atom labels
        labels = molecule.get_labels()

        # number of atoms
        natm = molecule.number_of_atoms()

        # atom coordinates (nx3)
        coords = molecule.get_coordinates_in_bohr()

        # charge and spin multiplicity
        charge = molecule.get_charge()
        multiplicity = molecule.get_multiplicity()

        # Hessian
        hessian = np.zeros((natm, 3, natm, 3))

        # First-order properties for gradient of dipole moment
        prop = FirstOrderProperties(self.comm, self.ostream)
        # numerical gradient (3 dipole components, no. atoms x 3 atom coords)
        if self.rank == mpi_master():
            self.dipole_gradient = np.zeros((3, 3 * natm))

        self.scf_driver.restart = False
        scf_results = self.scf_driver.compute(molecule, ao_basis)
        assert_msg_critical(self.scf_driver.is_converged,
                            'ScfHessianDriver: SCF did not converge')
        energy_0 = self.scf_driver.get_scf_energy()

        for i in range(natm):
            for x in range(3):
                # Plus x
                coords[i, x] += self.delta_h
                new_mol = Molecule(labels, coords, units='au')
                new_mol.set_charge(charge)
                new_mol.set_multiplicity(multiplicity)
                scf_results = self.scf_driver.compute(new_mol, ao_basis)
                assert_msg_critical(self.scf_driver.is_converged,
                                    'ScfHessianDriver: SCF did not converge')
                energy_ixp = self.scf_driver.get_scf_energy()

                prop.compute_scf_prop(new_mol, ao_basis, scf_results)
                if self.rank == mpi_master():
                    mu_plus = prop.get_property('dipole moment')

                # Minus x
                coords[i, x] -= 2.0 * self.delta_h
                new_mol = Molecule(labels, coords, units='au')
                new_mol.set_charge(charge)
                new_mol.set_multiplicity(multiplicity)
                scf_results = self.scf_driver.compute(new_mol, ao_basis)
                assert_msg_critical(self.scf_driver.is_converged,
                                    'ScfHessianDriver: SCF did not converge')
                energy_ixm = self.scf_driver.get_scf_energy()

                prop.compute_scf_prop(new_mol, ao_basis, scf_results)
                if self.rank == mpi_master():
                    mu_minus = prop.get_property('dipole moment')

                if self.rank == mpi_master():
                    for c in range(3):
                        self.dipole_gradient[c, 3 * i + x] = (
                                (mu_plus[c] - mu_minus[c]) / (2.0 * self.delta_h))

                hessian[i, x, i, x] = ((energy_ixp - 2 * energy_0 + energy_ixm) /
                              self.delta_h**2)
                coords[i, x] += self.delta_h

                for j in range(i, natm):
                    for y in range(3):
                        if (j == i and x != y) or (j != i):
                            # Plus y
                            coords[j, y] += self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            new_mol.set_charge(charge)
                            new_mol.set_multiplicity(multiplicity)
                            scf_results = self.scf_driver.compute(
                                new_mol, ao_basis)
                            assert_msg_critical(
                                self.scf_driver.is_converged,
                                'ScfHessianDriver: SCF did not converge')
                            energy_jyp = self.scf_driver.get_scf_energy()

                            # Plus x, plus y
                            coords[i, x] += self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            new_mol.set_charge(charge)
                            new_mol.set_multiplicity(multiplicity)
                            scf_results = self.scf_driver.compute(
                                new_mol, ao_basis)
                            assert_msg_critical(
                                self.scf_driver.is_converged,
                                'ScfHessianDriver: SCF did not converge')
                            energy_ixp_jyp = self.scf_driver.get_scf_energy()
                            coords[i, x] -= self.delta_h

                            # Minus y
                            coords[j, y] -= 2.0 * self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            new_mol.set_charge(charge)
                            new_mol.set_multiplicity(multiplicity)
                            scf_results = self.scf_driver.compute(
                                new_mol, ao_basis)
                            assert_msg_critical(
                                self.scf_driver.is_converged,
                                'ScfHessianDriver: SCF did not converge')
                            energy_jym = self.scf_driver.get_scf_energy()

                            # Minus x, minus y:
                            coords[i, x] -= self.delta_h
                            new_mol = Molecule(labels, coords, units='au')
                            new_mol.set_charge(charge)
                            new_mol.set_multiplicity(multiplicity)
                            scf_results = self.scf_driver.compute(
                                new_mol, ao_basis)
                            assert_msg_critical(
                                self.scf_driver.is_converged,
                                'ScfHessianDriver: SCF did not converge')
                            energy_ixm_jym = self.scf_driver.get_scf_energy()

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
        scf_results = self.scf_driver.compute(molecule, ao_basis)
        assert_msg_critical(self.scf_driver.is_converged,
                            'ScfHessianDriver: SCF did not converge')
        self.ostream.unmute()

    def compute_analytical(self, molecule, ao_basis, profiler):
        """
        Computes the analytical nuclear Hessian.
        So far only for restricted Hartree-Fock with PySCF integral derivatives...

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param profiler:
            The profiler.
        """

        natm = molecule.number_of_atoms()
        scf_tensors = self.scf_driver.scf_tensors

        if self.rank == mpi_master(): 
            density = scf_tensors['D_alpha']
            mo = scf_tensors['C_alpha']
            nao = mo.shape[0]
            nocc = molecule.number_of_alpha_electrons()
            mo_occ = mo[:, :nocc]
            mo_vir = mo[:, nocc:]
            nvir = mo_vir.shape[1]
            mo_energies = scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            eoo = eocc.reshape(-1, 1) + eocc  # ei+ej
            omega_ao = - np.linalg.multi_dot([mo_occ, np.diag(eocc), mo_occ.T])

        else:
            density = None
        density = self.comm.bcast(density, root=mpi_master())

        # Solve CPHF equations
        cphf_solver = HessianOrbitalResponse(self.comm, self.ostream)
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)
        cphf_solver.compute(molecule, ao_basis, scf_tensors)

        cphf_solution_dict = cphf_solver.cphf_results
        
        if self.rank == mpi_master():
            cphf_ov = cphf_solution_dict['cphf_ov'].reshape(natm, 3, nocc, nvir)

            """
            ovlp_deriv_oo = cphf_solution_dict['ovlp_deriv_oo']

            perturbed_density = np.zeros((natm, 3, nao, nao))
            for x in range(natm):
                for y in range(3):
                    perturbed_density[x, y] = (
                            # mj,xyij,ni->xymn
                            - np.linalg.multi_dot([mo_occ, ovlp_deriv_oo[x, y].T, mo_occ.T])
                            # ma,xyia,ni->xymn
                            + np.linalg.multi_dot([mo_vir, cphf_ov[x, y].T, mo_occ.T]) 
                            # mi,xyia,na->xymn
                            + np.linalg.multi_dot([mo_occ, cphf_ov[x, y], mo_vir.T]) 
                            )
            """

            t1 = tm.time()
        
            # Parts related to first-order integral derivatives
            if self.do_pople_hessian:
                fock_uij = cphf_solution_dict['fock_uij']

                fock_deriv_ao = cphf_solution_dict['fock_deriv_ao']

                fock_deriv_oo = np.zeros((natm, 3, nocc, nocc))
                orben_ovlp_deriv_oo = np.zeros((natm, 3, nocc, nocc))
                for x in range(natm):
                    for y in range(3):
                        # mi,xymn,nj->xyij
                        fock_deriv_oo[x, y] = np.linalg.multi_dot([
                            mo_occ.T, fock_deriv_ao[x, y], mo_occ])
                        # ij,xyij->xyij (element-wise multiplication)
                        orben_ovlp_deriv_oo[x, y] = np.multiply(eoo, ovlp_deriv_oo[x,y])
            else:
                dist_fock_deriv_ao = cphf_solution_dict['dist_fock_deriv_ao']
        else:
            #ovlp_deriv_oo = None
            cphf_ov = None
            perturbed_density = None

            if self.do_pople_hessian:
                fock_uij = None
                fock_deriv_ao = None
                fock_deriv_oo = None
                orben_ovlp_deriv_oo = None
            else:
                dist_fock_deriv_ao = cphf_solution_dict['dist_fock_deriv_ao']

        #ovlp_deriv_oo = self.comm.bcast(ovlp_deriv_oo, root=mpi_master())
        cphf_ov = self.comm.bcast(cphf_ov, root=mpi_master())

        #perturbed_density = self.comm.bcast(perturbed_density,
        #                                    root=mpi_master())

        dist_cphf_rhs = cphf_solution_dict['dist_cphf_rhs']

        if self.do_pople_hessian:
            fock_uij = self.comm.bcast(fock_uij, root=mpi_master())
            fock_deriv_ao = self.comm.bcast(fock_deriv_ao, root=mpi_master())
            fock_deriv_oo = self.comm.bcast(fock_deriv_oo, root=mpi_master())
            orben_ovlp_deriv_oo = self.comm.bcast(orben_ovlp_deriv_oo,
                                                 root=mpi_master())
            hessian_first_order_derivatives = self.compute_pople(molecule,
                                    ao_basis, -0.5 * ovlp_deriv_oo, cphf_ov,
                                    fock_uij, fock_deriv_oo,
                                    orben_ovlp_deriv_oo,
                                    perturbed_density, profiler)
        else:
            # TODO: should we also take ovlp_deriv_ao from cphf_solution_dict?
            hessian_first_order_derivatives = self.compute_furche(molecule,
                                    ao_basis, dist_cphf_rhs, 
                                    cphf_ov, dist_fock_deriv_ao, profiler)

        # TODO: need to test LDA and pure GGA functional

        # amount of exact exchange
        frac_K = 1.0

        # DFT:
        if self._dft:
            if self.scf_driver.xcfun.is_hybrid():
                frac_K = self.scf_driver.xcfun.get_frac_exact_exchange()
            else:
                frac_K = 0.0

            xc_mol_hess = XCMolecularHessian()
            hessian_dft_xc = xc_mol_hess.integrate_exc_hessian(molecule,
                                                ao_basis,
                                                [density], self.scf_driver._mol_grid,
                                                self.scf_driver.xcfun.get_func_label())
            hessian_dft_xc = self.comm.reduce(hessian_dft_xc, root=mpi_master())

        if self.rank == mpi_master():
            t2 = tm.time()
            self.ostream.print_info('First order derivative contributions'
                                    + ' to the Hessian computed in' +
                                     ' {:.2f} sec.'.format(t2 - t1))
            self.ostream.print_blank()
            self.ostream.flush()

            # Parts related to second-order integral derivatives
            hessian_2nd_order_derivatives = np.zeros((natm, natm, 3, 3))
            for i in range(natm):
                # do only upper triangular matrix
                for j in range(i, natm):
                    # Get integral second-order derivatives
                    ovlp_2nd_deriv_ii, ovlp_2nd_deriv_ij = overlap_second_deriv(
                                                    molecule, ao_basis, i, j)
                    hcore_2nd_deriv_ij = hcore_second_deriv(
                                            molecule, ao_basis, i, j)
                    eri_2nd_deriv_ii, eri_2nd_deriv_ij = eri_second_deriv(
                                            molecule, ao_basis, i, j)
                    if i == j:
                        # Add diagonal (same atom) contributions, 2S + 2J - K

                        # Build Fock matrices by contractig the density matrix
                        # with the second order derivatives of the two-electron
                        # integrals 

                        aux_ii_Fock_2nd_deriv_j = np.zeros((3, 3, nao, nao))
                        aux_ii_Fock_2nd_deriv_k = np.zeros((3, 3, nao, nao))
                        for x in range(3):
                            for y in range(3):
                                # mn,xymn->xy
                                hessian_2nd_order_derivatives[i, i, x, y] += 2.0 * (
                                        np.linalg.multi_dot([
                                            omega_ao.reshape(nao**2), 
                                            ovlp_2nd_deriv_ii[x, y].reshape(nao**2)])
                                        )
                                # kl,xymnkl->xymn
                                aux_ii_Fock_2nd_deriv_j[x, y] = np.linalg.multi_dot([
                                    density.reshape(nao**2), 
                                    (eri_2nd_deriv_ii[x, y].transpose(2,3,0,1)).reshape(nao**2,nao**2)
                                    ]).reshape(nao, nao)
                                # kl,xymknl->xymn
                                aux_ii_Fock_2nd_deriv_k[x, y] = np.linalg.multi_dot([
                                    density.reshape(nao**2), 
                                    (eri_2nd_deriv_ii[x, y].transpose(1,3,0,2)).reshape(nao**2,nao**2)
                                    ]).reshape(nao, nao)
                                # mn,xymn->xy
                                hessian_2nd_order_derivatives[i, i, x, y] += 2.0 * (
                                        np.linalg.multi_dot([
                                            density.reshape(nao**2), 
                                            aux_ii_Fock_2nd_deriv_j[x, y].reshape(nao**2)
                                        ]))
                                # mn,xymn->xy
                                hessian_2nd_order_derivatives[i, i, x, y] -= frac_K * (
                                        np.linalg.multi_dot([
                                            density.reshape(nao**2), 
                                            aux_ii_Fock_2nd_deriv_k[x, y].reshape(nao**2)
                                        ]))

                    # Add non-diagonal contributions, 2S + 2J - K + 2h

                    aux_ij_Fock_2nd_deriv_j = np.zeros((3, 3, nao, nao))
                    aux_ij_Fock_2nd_deriv_k = np.zeros((3, 3, nao, nao))
                    for x in range(3):
                        for y in range(3):
                            # kl,xymnkl->xymn
                            aux_ij_Fock_2nd_deriv_j[x, y] = np.linalg.multi_dot([
                                density.reshape(nao**2), 
                                (eri_2nd_deriv_ij[x, y].transpose(2, 3, 0, 1)).reshape(nao**2, nao**2)
                                ]).reshape(nao, nao)
                            # kl,xymknl->xymn
                            aux_ij_Fock_2nd_deriv_k[x, y] = np.linalg.multi_dot([
                                density.reshape(nao**2), 
                                (eri_2nd_deriv_ij[x, y].transpose(1, 3, 0, 2)).reshape(nao**2, nao**2)
                                ]).reshape(nao, nao)
                            # mn, xymn->xy
                            hessian_2nd_order_derivatives[i, j, x, y] += 2.0 * (
                                    np.linalg.multi_dot([
                                        density.reshape(nao**2),
                                        aux_ij_Fock_2nd_deriv_j[x, y].reshape(nao**2)]))
                            # mn,xymn->xy
                            hessian_2nd_order_derivatives[i, j, x, y] -= frac_K * (
                                    np.linalg.multi_dot([
                                        density.reshape(nao**2),
                                        aux_ij_Fock_2nd_deriv_k[x, y].reshape(nao**2)]))
                            # mn,xymn->xy
                            hessian_2nd_order_derivatives[i, j, x, y] += 2.0 * (
                                    np.linalg.multi_dot([
                                        omega_ao.reshape(nao**2),
                                        ovlp_2nd_deriv_ij[x, y].reshape(nao**2)]))
                            # mn,xymn->xy
                            hessian_2nd_order_derivatives[i, j, x, y] += 2.0 * (
                                    np.linalg.multi_dot([
                                        density.reshape(nao**2),
                                        hcore_2nd_deriv_ij[x, y].reshape(nao**2)]))

                # lower triangle is transpose of the upper part
                for j in range(i):
                    hessian_2nd_order_derivatives[i,j] += (
                                hessian_2nd_order_derivatives[j,i].T )

            ## Nuclear-nuclear repulsion contribution
            hessian_nuclear_nuclear = self.hess_nuc_contrib(molecule)

            ## Sum up the terms and reshape for final Hessian
            self.hessian = ( hessian_first_order_derivatives
                            + hessian_2nd_order_derivatives
                            + hessian_nuclear_nuclear
                            ).transpose(0,2,1,3).reshape(3*natm, 3*natm)

            if self._dft:
                self.hessian += hessian_dft_xc

            # save perturbed density as instance variable: needed for dipole
            # gradient
            #self.perturbed_density = perturbed_density

            t3 = tm.time()
            self.ostream.print_info('Second order derivative contributions'
                                    + ' to the Hessian computed in' +
                                     ' {:.2f} sec.'.format(t3 - t2))
            self.ostream.print_blank()
            self.ostream.flush()

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
            orbital energies (ei+ej)S^chi_ij
        :param perturbed_density:
            The perturbed density matrix.
        :param profiler:
            The profiler.
        """

        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()

        if self.rank == mpi_master():
            scf_tensors = self.scf_driver.scf_tensors
            mo = scf_tensors['C_alpha']
            mo_occ = mo[:, :nocc].copy()
            mo_vir = mo[:, nocc:].copy()
            nao = mo.shape[0]
            density = scf_tensors['D_alpha']
            mo_energies = scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            eo_diag = np.diag(eocc)
            epsilon_dm_ao = - np.linalg.multi_dot([mo_occ, eo_diag, mo_occ.T])

            dof = 3

            # Construct the perturbed density matrix, and perturbed omega
            # TODO: consider if using the transpose makes the
            # computation faster; consider using cphf coefficients in AO
            # to compute the perturbed density matrix.

            orben_perturbed_density = np.zeros((natm, dof, nao, nao))
            mo_e_occ = np.multiply(mo_occ, eocc)
            for x in range(natm):
                for y in range(dof):
                    orben_perturbed_density[x, y] = (
                            # i,mj,xyij,ni->xymn
                            np.linalg.multi_dot([
                                mo_occ, cphf_oo[x, y].T, mo_e_occ.T])
                            # i,mi,xyij,nj->xymn
                            + np.linalg.multi_dot([
                                mo_e_occ, cphf_oo[x, y], mo_occ.T])
                            # i,ma,xyia,ni->xymn
                            + np.linalg.multi_dot([
                                mo_vir, cphf_ov[x, y].T, mo_e_occ.T])
                            # i,mi,xyia,na->xymn
                            + np.linalg.multi_dot([
                                mo_e_occ, cphf_ov[x, y], mo_vir.T])
                            )
        else:
            density = None

        if self._dft:
            grid_drv = GridDriver()
            grid_level = (get_default_grid_level(self.xcfun)
                          if self.scf_driver.grid_level is None else self.scf_driver.grid_level)
            grid_drv.set_level(grid_level)
            mol_grid = grid_drv.generate(molecule)

        density = self.comm.bcast(density, root=mpi_master())

        fock_uia_numpy = self.construct_fock_matrix_cphf(molecule, ao_basis,
                                                         cphf_ov)

        if self.rank == mpi_master():
            fock_cphf_oo = np.zeros((natm, dof, nocc, nocc))
            fock_cphf_ov = np.zeros((natm, dof, nocc, nocc))
            perturbed_omega_ao = np.zeros((natm, dof, nao, nao))
            for x in range(natm):
                for y in range(dof):
                    fock_cphf_oo[x, y] = (
                            # mi,xymn,nj->xyij
                            np.linalg.multi_dot([
                                mo_occ.T, fock_uij[x, y], mo_occ])
                            )
                    fock_cphf_ov[x, y] = (
                            # mi,xymn,nj->xyij
                            np.linalg.multi_dot([
                                mo_occ.T, fock_uia_numpy[x, y], mo_occ])
                            # mj,xymn,ni->xyij
                            + np.linalg.multi_dot([
                                mo_occ.T, fock_uia_numpy[x, y], mo_occ]).T
                            )

                    # Construct the derivative of the omega multipliers:
                    perturbed_omega_ao[x, y] = -1.0 * (
                            orben_perturbed_density[x,y]
                            # mi,xyij,nj->xymn
                            + np.linalg.multi_dot([
                                mo_occ, fock_deriv_oo[x, y], mo_occ.T])
                            # mi,xyij,nj->xymn
                            - 0.5 * np.linalg.multi_dot([
                                mo_occ, orben_ovlp_deriv_oo[x,y], mo_occ.T])
                            # mi,xyij,nj->xymn
                            + 2.0 * np.linalg.multi_dot([
                                mo_occ, fock_cphf_oo[x, y], mo_occ.T])
                            # mi,xyij,nj->xymn
                            + np.linalg.multi_dot([
                                mo_occ, fock_cphf_ov[x, y], mo_occ.T])
                            )

            # First integral derivatives: partial Fock and overlap matrix
            # derivatives
            hessian_first_integral_derivatives = np.zeros((natm, natm, 3, 3))

        if self._dft: 
            xc_mol_hess = XCMolecularHessian()
        for i in range(natm):
            # upper triangular part
            for j in range(i, natm):
                if self._dft:
                    # First derivative of the Vxc matrix elements
                    vxc_deriv_j = xc_mol_hess.integrate_vxc_fock_gradient(
                                    molecule, ao_basis, [density], mol_grid,
                                    self.scf_driver.xcfun.get_func_label(), j)
                    vxc_deriv_j = self.comm.reduce(vxc_deriv_j,
                                                   root=mpi_master())
                if self.rank == mpi_master():
                    # First derivative of the Fock matrix
                    fock_deriv_j =  fock_deriv(molecule, ao_basis, density, j,
                                               self.scf_driver)
                    if self._dft:
                        fock_deriv_j += vxc_deriv_j

                    # First derivative of overlap matrix
                    ovlp_deriv_j = overlap_deriv(molecule, ao_basis, j)
                    # Add the contribution of the perturbed density matrix
                    for x in range(dof):
                        for y in range(dof):
                            hessian_first_integral_derivatives[i, j, x, y] += (
                                    # xmn,ymn->xy
                                    np.linalg.multi_dot([2.0 * perturbed_density[i, x].reshape(nao**2),
                                                         fock_deriv_j[y].reshape(nao**2)])
                                    # xmn,ymn->xy
                                    + np.linalg.multi_dot([2.0 * perturbed_omega_ao[i, x].reshape(nao**2),
                                                           ovlp_deriv_j[y].reshape(nao**2)])
                                    )

            if self.rank == mpi_master():
                # lower triangular part
                for j in range(i):
                    hessian_first_integral_derivatives[i,j] += (
                                     hessian_first_integral_derivatives[j,i].T )

        if self.rank == mpi_master():
            return hessian_first_integral_derivatives
        else:
            return None


    def compute_furche(self, molecule, ao_basis, dist_cphf_rhs, cphf_ov,
                       dist_fock_deriv_ao, profiler):
        """
        Computes the analytical nuclear Hessian the Furche/Ahlrichs way.
        Chem. Phys. Lett. 362, 511–518 (2002).
        DOI: 10.1016/S0009-2614(02)01084-9

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param dist_cphf_rhs:
            The distributed RHS of the CPHF equations in MO basis.
        :param cphf_ov:
            The ov block of the CPHF coefficients.
        :param profiler:
            The profiler.
        """

        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()

        if self.rank == mpi_master():
            scf_tensors = self.scf_driver.scf_tensors
            mo = scf_tensors['C_alpha']
            mo_occ = mo[:, :nocc].copy()
            mo_vir = mo[:, nocc:].copy()
            nvir = mo_vir.shape[1]
            nao = mo.shape[0]
            density = scf_tensors['D_alpha']
            mo_energies = scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            omega_ao = - np.linalg.multi_dot([mo_occ, np.diag(eocc), mo_occ.T])
        else:
            density = None
            scf_tensors = None

        density = self.comm.bcast(density, root=mpi_master())

        # TODO: the MPI is not done properly here,
        # fix once the new integral code is ready.

        # RHS contracted with CPHF coefficients (ov)
        if self.rank == mpi_master():
            hessian_cphf_coeff_rhs = np.zeros((natm, natm, 3, 3))

        ijxy_list = [(i,j,x,y)
                     for i in range(natm)
                     for j in range(natm)
                     for x in range(3)
                     for y in range(3)]

        for i,j,x,y in ijxy_list:
            cphf_rhs_j_y = dist_cphf_rhs.get_full_vector(col=j*3+y)

            if self.rank == mpi_master():
                hessian_cphf_coeff_rhs[i,j,x,y] = 4.0 * (
                    np.dot(cphf_ov[i,x].reshape(nocc*nvir), cphf_rhs_j_y))

        # First integral derivatives: partial Fock and overlap
        # matrix derivatives
        if self.rank == mpi_master():
            hessian_first_integral_derivatives = np.zeros((natm, natm, 3, 3))

        if self._dft: 
            xc_mol_hess = XCMolecularHessian()

        ovlp_grad_drv = OverlapGeom100Driver()

        for i in range(natm):

            ovlp_deriv_i = []
            gmats = ovlp_grad_drv.compute(molecule, ao_basis, i)
            for label in ['X', 'Y', 'Z']:
                gmat = gmats.matrix_to_numpy(label)
                ovlp_deriv_i.append(gmat + gmat.T)
            gmats = Matrices()

            fock_deriv_ix = dist_fock_deriv_ao.get_full_vector(col=i*3+0)
            fock_deriv_iy = dist_fock_deriv_ao.get_full_vector(col=i*3+1)
            fock_deriv_iz = dist_fock_deriv_ao.get_full_vector(col=i*3+2)

            if self.rank == mpi_master():
                fock_deriv_i = [fock_deriv_ix.reshape(nao, nao),
                                fock_deriv_iy.reshape(nao, nao),
                                fock_deriv_iz.reshape(nao, nao)]

            # Note: upper triangular part
            for j in range(i, natm):

                ovlp_deriv_j = []
                gmats = ovlp_grad_drv.compute(molecule, ao_basis, j)
                for label in ['X', 'Y', 'Z']:
                    gmat = gmats.matrix_to_numpy(label)
                    ovlp_deriv_j.append(gmat + gmat.T)
                gmats = Matrices()

                fock_deriv_jx = dist_fock_deriv_ao.get_full_vector(col=j*3+0)
                fock_deriv_jy = dist_fock_deriv_ao.get_full_vector(col=j*3+1)
                fock_deriv_jz = dist_fock_deriv_ao.get_full_vector(col=j*3+2)

                if self.rank == mpi_master():
                    fock_deriv_j = [fock_deriv_jx.reshape(nao, nao),
                                    fock_deriv_jy.reshape(nao, nao),
                                    fock_deriv_jz.reshape(nao, nao)]
            
                    Fix_Sjy = np.zeros((3,3))
                    Fjy_Six = np.zeros((3,3))
                    Six_Sjy = np.zeros((3,3))

                    xy_list = [(x,y) for x in range(3) for y in range(3)]

                    for x, y in xy_list:
                        Fix_Sjy[x,y] = np.trace(np.linalg.multi_dot([
                            density, fock_deriv_i[x], density,
                            ovlp_deriv_j[y]]))
                        Fjy_Six[x,y] = np.trace(np.linalg.multi_dot([
                            density, fock_deriv_j[y],
                            density, ovlp_deriv_i[x]]))
                        Six_Sjy[x,y] = 2.0 * np.trace(np.linalg.multi_dot([
                            omega_ao, ovlp_deriv_i[x], density,
                            ovlp_deriv_j[y]]))

                    hessian_first_integral_derivatives[i,j] += -2.0 * (
                            Fix_Sjy + Fjy_Six + Six_Sjy)
   
            if self.rank == mpi_master(): 
                # Note: lower triangular part
                for j in range(i):
                    hessian_first_integral_derivatives[i,j] += (
                            hessian_first_integral_derivatives[j,i].T)

        if self.rank == mpi_master():
            # Overlap derivative with ERIs
            hessian_eri_overlap = np.zeros((natm, natm, 3, 3))

        # We use comp_lr_fock from CphfSolver to compute the eri
        # and xc contributions
        cphf_solver = HessianOrbitalResponse(self.comm, self.ostream)
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)

        # ERI information
        eri_dict = cphf_solver._init_eri(molecule, ao_basis)
        # DFT information
        dft_dict = cphf_solver._init_dft(molecule, scf_tensors)
        # PE information
        pe_dict = cphf_solver._init_pe(molecule, ao_basis)

        for i in range(natm):

            ovlp_deriv_i = []
            gmats = ovlp_grad_drv.compute(molecule, ao_basis, i)
            for label in ['X', 'Y', 'Z']:
                gmat = gmats.matrix_to_numpy(label)
                ovlp_deriv_i.append(gmat + gmat.T)
            gmats = Matrices()

            # upper triangular part
            for j in range(i, natm):

                ovlp_deriv_j = []
                gmats = ovlp_grad_drv.compute(molecule, ao_basis, j)
                for label in ['X', 'Y', 'Z']:
                    gmat = gmats.matrix_to_numpy(label)
                    ovlp_deriv_j.append(gmat + gmat.T)
                gmats = Matrices()

                if self.rank == mpi_master():
                    # Overlap derivative contracted with two density matrices
                    P_P_Six = np.zeros((3, nao, nao))
                    P_P_Sjy = np.zeros((3, nao, nao))
                    for x in range(3):
                        # mn,xnk,kl->xml
                        P_P_Six[x] = np.linalg.multi_dot([
                        density, ovlp_deriv_i[x], density])
                        # mn,xnk,kl->xml
                        P_P_Sjy[x] = np.linalg.multi_dot([
                            density, ovlp_deriv_j[x], density])

                    # Create a list of 2D numpy arrays to create
                    # AODensityMatrix objects
                    # and calculate auxiliary Fock matrix with ERI driver
                    P_P_Six_ao_list = [P_P_Six[x] for x in range(3)]
                else:
                    P_P_Six_ao_list = None

                P_P_Six_ao_list = self.comm.bcast(P_P_Six_ao_list, root=mpi_master())

                # MPI issue
                P_P_Six_fock_ao = cphf_solver._comp_lr_fock(P_P_Six_ao_list,
                                          molecule, ao_basis, eri_dict,
                                          dft_dict, pe_dict, profiler)

                if self.rank == mpi_master():
                    # Convert the auxiliary Fock matrices to numpy arrays 
                    # for further use
                    np_P_P_Six_fock = np.zeros((3,nao,nao))
                    for k in range(3):
                        np_P_P_Six_fock[k] = P_P_Six_fock_ao[k]

                    for x in range(3):
                        for y in range(3):
                            # xmn,ymn->xy
                            hessian_eri_overlap[i,j,x,y] += 2.0 * (np.linalg.multi_dot([
                                np_P_P_Six_fock[x].reshape(nao**2), 
                                P_P_Sjy[y].reshape(nao**2)]))

            # lower triangular part
            for j in range(i):
                if self.rank == mpi_master():
                    hessian_eri_overlap[i,j] += hessian_eri_overlap[j,i].T

        # return the sum of the three contributions
        if self.rank == mpi_master():
            return ( hessian_cphf_coeff_rhs
                   + hessian_first_integral_derivatives
                   + hessian_eri_overlap)
        else:
            return None


    def construct_fock_matrix_cphf(self, molecule, ao_basis, cphf_ov):
        """
        Contracts the CPHF coefficients with the two-electron
        integrals and returns an auxiliary fock matrix as a
        numpy array.

        :param molecule:
            The Molecule.
        :param ao_basis:
            The AO Basis.
        :param chpf_ov:
            The occupied-virtual block of the CPHF coefficients.
        """
        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()

        if self.rank == mpi_master():
            scf_tensors = self.scf_driver.scf_tensors
            mo = scf_tensors['C_alpha']
            mo_occ = mo[:, :nocc].copy()
            mo_vir = mo[:, nocc:].copy()
            nao = mo.shape[0]
            density = scf_tensors['D_alpha']
            mo_energies = scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            eo_diag = np.diag(eocc)
            epsilon_dm_ao = - np.linalg.multi_dot([mo_occ, eo_diag, mo_occ.T])
            # Transform the CPHF coefficients to AO:
            uia_ao = np.zeros((natm, 3, nao, nao))
            for x in range(natm):
                for y in range(3):
                    uia_ao[x,y] = np.linalg.multi_dot([
                        mo_occ, cphf_ov[x,y], mo_vir.T])
            uia_ao = uia_ao.reshape(3*natm, nao, nao)
            
            # create AODensity and Fock matrix objects, contract with ERI
            uia_ao_list = [uia_ao[x] for x in range(natm * 3)]
        else:
            scf_tensors = None
            uia_ao_list = None

        uia_ao_list = self.comm.bcast(uia_ao_list, root=mpi_master())

        # We use comp_lr_fock from CphfSolver to compute the eri
        # and xc contributions
        cphf_solver = HessianOrbitalResponse(self.comm, self.ostream)
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)
        # ERI information
        eri_dict = cphf_solver._init_eri(molecule, ao_basis)
        # DFT information
        dft_dict = cphf_solver._init_dft(molecule, scf_tensors)
        # PE information
        pe_dict = cphf_solver._init_pe(molecule, ao_basis)

        profiler = Profiler({
            'timing': self.timing,
            'profiling': self.profiling,
            'memory_profiling': self.memory_profiling,
            'memory_tracing': self.memory_tracing,
        })

        fock_uia = cphf_solver._comp_lr_fock(uia_ao_list, molecule, ao_basis,
                                 eri_dict, dft_dict, pe_dict, profiler)

        if self.rank == mpi_master():
            # TODO: can this be done in a different way?
            fock_uia_numpy = np.zeros((natm,3,nao,nao))
            for i in range(natm):
                for x in range(3):
                    fock_uia_numpy[i,x] = fock_uia[3*i + x]

            return fock_uia_numpy
        else:
            return None

    # FIXME the function below is unused
    def compute_perturbed_energy_weighted_density_matrix(self, molecule,
                                                         ao_basis):
        """
        Calculates the perturbed energy weighted density matrix
        and returns it as a numpy array.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """
        natm = molecule.number_of_atoms()
        nocc = molecule.number_of_alpha_electrons()
        scf_tensors = self.scf_driver.scf_tensors
        mo = scf_tensors['C']
        mo_occ = mo[:, :nocc].copy()
        mo_vir = mo[:, nocc:].copy()
        nao = mo.shape[0]
        nmo = mo.shape[1]
        nvir = nmo - nocc
        mo_energies = scf_tensors['E']
        eocc = mo_energies[:nocc]
        eoo = eocc.reshape(-1, 1) + eocc #ei+ej
        # Set up a CPHF solver
        cphf_solver = HessianOrbitalResponse(self.comm, self.ostream)
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)

        # Solve the CPHF equations
        cphf_solver.compute(molecule, ao_basis, scf_tensors, self.scf_driver)

        # Extract the relevant results
        cphf_solution_dict = cphf_solver.cphf_results
        cphf_ov = cphf_solution_dict['cphf_ov'].reshape(natm, 3, nocc, nvir)
        ovlp_deriv_oo = cphf_solution_dict['ovlp_deriv_oo']
        cphf_oo = -0.5 * ovlp_deriv_oo

        fock_uij = cphf_solution_dict['fock_uij']
        fock_deriv_ao = cphf_solution_dict['fock_deriv_ao']
        fock_deriv_oo = np.einsum('mi,xymn,nj->xyij', mo_occ,
                                   fock_deriv_ao, mo_occ)
        fock_uia_numpy = self.construct_fock_matrix_cphf(molecule, ao_basis,
                                                         cphf_ov)

        # (ei+ej)S^chi_ij
        orben_ovlp_deriv_oo = np.einsum('ij,xyij->xyij', eoo, ovlp_deriv_oo)

        fock_cphf_oo = np.einsum('mi,xymn,nj->xyij', mo_occ, fock_uij, mo_occ)

        fock_cphf_ov = ( np.einsum('mi,xymn,nj->xyij', mo_occ,
                                   fock_uia_numpy, mo_occ)
                        +np.einsum('mj,xymn,ni->xyij', mo_occ,
                                   fock_uia_numpy, mo_occ)
                        )

        orben_perturbed_density = ( np.einsum('i,mj,xyij,ni->xymn',
                                            eocc, mo_occ, cphf_oo, mo_occ)
                                  + np.einsum('i,mi,xyij,nj->xymn',
                                            eocc, mo_occ, cphf_oo, mo_occ)
                                  + np.einsum('i,ma,xyia,ni->xymn',
                                            eocc, mo_vir, cphf_ov, mo_occ)
                                  +np.einsum('i,mi,xyia,na->xymn',
                                            eocc, mo_occ, cphf_ov, mo_vir)
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
        return perturbed_omega_ao

    # TODO: make this option available
    def compute_numerical_with_analytical_gradient(self, molecule, ao_basis,
                                                   profiler=None):

        """
        Performs calculation of numerical Hessian.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
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
        grad_dict = dict(self.hess_dict)
        if self.numerical_grad:
            grad_dict['numerical'] = 'yes'
            warn_msg = '*** Warning: Numerical Hessian will be calculated '
            warn_msg += 'based on numerical gradient.'
            self.ostream.print_header(warn_msg.ljust(56))
            warn_msg = '  This takes a long time and has limited accuracy.'
            self.ostream.print_header(warn_msg.ljust(56))
            self.ostream.print_blank()
            self.ostream.flush()
        else:
            grad_dict['numerical'] = 'no'

        self.ostream.mute()

        # atom labels
        labels = molecule.get_labels()

        # number of atoms
        natm = molecule.number_of_atoms()

        # atom coordinates (nx3)
        coords = molecule.get_coordinates()

        # gradient driver
        grad_drv = ScfGradientDriver(self.scf_driver)
        grad_drv.update_settings(grad_dict, self.method_dict)

        # number of atomic orbitals
        scf_tensors = self.scf_driver.scf_tensors
        nao = scf_tensors['D_alpha'].shape[0]

        # Hessian
        hessian = np.zeros((natm, 3, natm, 3))

        # First-order properties for gradient of dipole moment
        prop = FirstOrderProperties(self.comm, self.ostream)
        # numerical gradient (3 dipole components, no. atoms x 3 atom coords)
        self.dipole_gradient = np.zeros((3, 3 * natm))

        if not self.do_four_point:
            for i in range(natm):
                for d in range(3):
                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_plus = prop.get_property('dipole moment')

                    coords[i, d] -= 2.0 * self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_minus = prop.get_property('dipole moment')

                    for c in range(3):
                        self.dipole_gradient[c, 3*i + d] = (
                            (mu_plus[c] - mu_minus[c]) / (2.0 * self.delta_h) )
                    coords[i, d] += self.delta_h
                    hessian[i, d, :, :] = (
                           (grad_plus - grad_minus) / (2.0 * self.delta_h) )
        else:
            # Four-point numerical derivative approximation
            # for debugging of analytical Hessian:
            # [ f(x - 2h) - 8 f(x - h) + 8 f(x + h) - f(x + 2h) ] / ( 12h )
            for i in range(natm):
                for d in range(3):
                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus1 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_plus1 = prop.get_property('dipole moment')

                    coords[i, d] += self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_plus2 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_plus2 = prop.get_property('dipole moment')

                    coords[i, d] -= 3.0 * self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus1 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_minus1 = prop.get_property('dipole moment')

                    coords[i, d] -= self.delta_h
                    new_mol = Molecule(labels, coords, units='au')
                    self.scf_driver.compute(new_mol, ao_basis)
                    grad_drv.compute(new_mol, ao_basis)
                    grad_minus2 = grad_drv.get_gradient()

                    prop.compute_scf_prop(new_mol, ao_basis,
                                          self.scf_driver.scf_tensors)
                    mu_minus2 = prop.get_property('dipole moment')

                    for c in range(3):
                        self.dipole_gradient[c, 3*i + d] = (
                          ( mu_minus2[c] - 8.0 * mu_minus1[c] 
                        + 8.0 * mu_plus1[c] - mu_plus2[c])
                        / (12.0 * self.delta_h) )
                    coords[i, d] += 2.0 * self.delta_h
                    # f'(x) ~ [ f(x - 2h) - 8 f(x - h) + 8 f(x + h)
                    # - f(x + 2h) ] / ( 12h )
                    hessian[i, d] = (grad_minus2 - 8.0 * grad_minus1
                       + 8.0 * grad_plus1 - grad_plus2) / (12.0 * self.delta_h)

        # reshaped Hessian as member variable
        self.hessian = hessian.reshape(3*natm, 3*natm)

        self.scf_driver.compute(molecule, ao_basis)
        self.ostream.unmute()

    def compute_dipole_gradient(self, molecule, ao_basis):
        """
        Computes the analytical gradient of the dipole moment.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param scf_drv:
            The SCF driver.
        :param perturbed_density: #TODO remove this if setup approved
            The perturbed density matrix.
        """

        # Number of atoms and atomic charges
        natm = molecule.number_of_atoms()
        nuclear_charges = molecule.get_element_ids()

        scf_tensors = self.scf_driver.scf_tensors 
        perturbed_density = self.perturbed_density

        density = scf_tensors['D_alpha']
        nao = perturbed_density.shape[-1] # need for reshaping

        # Dipole integrals
        dipole_mats = compute_electric_dipole_integrals(molecule, ao_basis, [0.0, 0.0, 0.0])
        # Note: compute_dipole_gradient uses r instead of mu for dipole operator
        dipole_ints = (
            -1.0 * dipole_mats[0],
            -1.0 * dipole_mats[1],
            -1.0 * dipole_mats[2],
        )

        # Initialize a local dipole gradient to zero
        dipole_gradient = np.zeros((3, natm, 3))

        # Put the nuclear contributions to the right place
        natm_zeros = np.zeros((natm))
        dipole_gradient[0] = np.vstack((nuclear_charges,
                                        natm_zeros, natm_zeros)).T
        dipole_gradient[1] = np.vstack((natm_zeros,
                                        nuclear_charges, natm_zeros)).T
        dipole_gradient[2] = np.vstack((natm_zeros,
                                        natm_zeros, nuclear_charges)).T

        # TODO: replace once veloxchem analytical integral derivatives 
        # are available
        # TODO: replace the full array of dipole integrals derivatives with
        # the derivative with respect to each atom and contract with 
        # the densities in the same way as done for the energy gradient.
        #dipole_integrals_deriv = self.compute_dipole_integral_derivatives(
        #                                                molecule, ao_basis)
        dipole_integrals_deriv = self.compute_dipole_integral_derivatives(
                                                        molecule, ao_basis)

        # Add the electronic contributions
        for a in range(natm):
            for c in range(3):
                for x in range(3):
                    dipole_gradient[c,a,x] += -2.0 * (
                            np.linalg.multi_dot([
                                density.reshape(nao**2),
                                dipole_integrals_deriv[c,a,x].reshape(nao**2)])
                            + np.linalg.multi_dot([
                                perturbed_density[a,x].reshape(nao**2),
                                dipole_ints[c].reshape(nao**2)]))

        self.dipole_gradient = dipole_gradient.reshape(3, 3 * natm)

    # TODO remove this function
    def compute_pyscf_dipole_integral_derivatives(self, molecule, ao_basis):
        """
        LEGACY FUNCTION:  REPLACED BY VLX INTEGRALS
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

        #scf_tensors = self.scf_driver.scf_tensors
        # number of atomic orbitals
        #nao = scf_tensors['D_alpha'].shape[0]
        nao = ao_basis.get_dimensions_of_basis()

        # 3 dipole components x No. atoms x 3 atomic coordinates
        # x No. basis x No. basis
        dipole_integrals_gradient = np.zeros((3, natm, 3, nao, nao))

        for i in range(natm):
            dipole_integrals_gradient[:,i,:,:,:] = (
                                dipole_deriv(molecule, ao_basis, i)
                                )

        return dipole_integrals_gradient

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
        nao = ao_basis.get_dimensions_of_basis()
        
        dip_grad_drv = ElectricDipoleMomentGeom100Driver()
        dipole_integrals_gradient = np.zeros((3, natm, 3, nao, nao))

        for iatom in range(natm):
            gmats_dip = dip_grad_drv.compute(molecule, ao_basis, [0.0, 0.0, 0.0], iatom)

            # the keys of the dipole gmat
            gmats_dip_components = (['X_X', 'X_Y', 'X_Z', 'Y_X' ]
                                  + [ 'Y_Y', 'Y_Z', 'Z_X', 'Z_Y', 'Z_Z'])

            # dictionary to convert from string idx to integer idx
            comp_to_idx = {'X': 0, 'Y': 1, 'Z': 2}

            for i, label in enumerate(gmats_dip_components):
                gmat_dip = gmats_dip.matrix_to_numpy(label)
                gmat_dip += gmat_dip.T

                icoord = comp_to_idx[label[0]] # atom coordinate component
                icomp = comp_to_idx[label[-1]] # dipole operator component

                # reorder indices to first is operator comp, second is coord
                dipole_integrals_gradient[icomp, iatom, icoord] += gmat_dip

        return dipole_integrals_gradient

    def compute_orbital_response(self, molecule, ao_basis):
        """
        TEMPORARY FUNCTION FOR PERFORMACE TESTING
        Computes the CPHF orbital response.

        :param molecule:
            The molecule.
        :param ao_basis:
            Tha AO basis.
        """

        # get SCF tensors
        scf_tensors = self.scf_driver.scf_tensors

        # Set up a CPHF solver
        cphf_solver = HessianOrbitalResponse(self.comm, self.ostream)
        cphf_solver.update_settings(self.cphf_dict, self.method_dict)

        # Solve the CPHF equations
        cphf_solver.compute(molecule, ao_basis, scf_tensors, self.scf_driver)

