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
from copy import deepcopy
import time as tm
import numpy as np

from .veloxchemlib import (XCFunctional, MolecularGrid)
from .veloxchemlib import mpi_master
from .outputstream import OutputStream
from .gradientdriver import GradientDriver
from .errorhandler import assert_msg_critical
from .sanitychecks import dft_sanity_check

# For PySCF integral derivatives
from .import_from_pyscf import overlap_deriv
from .import_from_pyscf import eri_deriv
from .import_from_pyscf import hcore_deriv


class ScfGradientDriver(GradientDriver):
    """
    Implements SCF gradient driver.

    :param scf_drv:
        The SCF driver.

    Instance variables
        - flag: The driver flag.
        - delta_h: The displacement for finite difference.
    """

    def __init__(self, scf_drv):
        """
        Initializes gradient driver.
        """

        super().__init__(scf_drv.comm, scf_drv.ostream)

        self.scf_driver = scf_drv
        self.flag = 'SCF Gradient Driver'

    def compute(self, molecule, ao_basis):
        """
        Computes the analytical or numerical nuclear gradient.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """

        dft_sanity_check(self, 'compute')

        if self.rank == mpi_master():
            self.print_header()

        start_time = tm.time()

        # compute gradient
        if self.numerical:
            self.ostream.mute()
            self.compute_numerical(molecule, ao_basis)
            self.ostream.unmute()
        else:
            self.compute_analytical(molecule, ao_basis)

        # print gradient

        if self.rank == mpi_master():
            self.print_geometry(molecule)
            self.print_gradient(molecule)

            valstr = '*** Time spent in gradient calculation: '
            valstr += '{:.2f} sec ***'.format(tm.time() - start_time)
            self.ostream.print_header(valstr)
            self.ostream.print_blank()
            self.ostream.flush()

    def compute_analytical(self, molecule, ao_basis):
        """
        Computes the analytical nuclear gradient.
        So far only for restricted Hartree-Fock with PySCF integral derivatives...

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        """

        natm = molecule.number_of_atoms()

        self.gradient = np.zeros((natm, 3))

        if self.rank == mpi_master():
            nocc = molecule.number_of_alpha_electrons()

            mo = self.scf_driver.scf_tensors['C_alpha']
            mo_occ = mo[:, :nocc].copy()

            one_pdm_ao = self.scf_driver.scf_tensors['D_alpha']

            eo_diag = np.diag(self.scf_driver.scf_tensors['E_alpha'][:nocc])
            epsilon_dm_ao = -np.linalg.multi_dot([mo_occ, eo_diag, mo_occ.T])

            for i in range(natm):
                t0 = tm.time()
                d_ovlp = overlap_deriv(molecule, ao_basis, i)
                d_hcore = hcore_deriv(molecule, ao_basis, i)
                d_eri_partial = eri_deriv(molecule, ao_basis, i, full_deriv=False) 
                t1 = tm.time()
                self.ostream.print_info("Import of integral derivatives"
                                    + ' took'
                                    + ' {:.2f} sec.'.format(t1 - t0))
                self.ostream.flush()

                self.gradient[i] = (
                    2.0 * np.einsum('mn,xmn->x', one_pdm_ao, d_hcore) +
                    2.0 * np.einsum('mn,xmn->x', epsilon_dm_ao, d_ovlp))
                t2 = tm.time()
                self.ostream.print_info("Core Hamiltonian and overlap"
                                    + ' derivative contribution computed in'
                                    + ' {:.2f} sec.'.format(t2 - t1))
                self.ostream.flush()
                if self._dft:
                    if self.xcfun.is_hybrid():
                        frac_K = self.xcfun.get_frac_exact_exchange()
                    else:
                        frac_K = 0.0
                else:
                    frac_K = 1.0

                # place in C-layer, aux Fock build, (derivative on first AO index, m)
                # (m* n | t p)
                aux_Fock_deriv_j = np.einsum('xmntp,tp->xmn', d_eri_partial, one_pdm_ao)
                aux_Fock_deriv_k = np.einsum('xmtnp,tp->xmn', d_eri_partial, one_pdm_ao)
                aux_Fock_deriv = 2 * aux_Fock_deriv_j - frac_K * aux_Fock_deriv_k

                # The factor 4 comes from the permutations of the AO index where the derivative is taken 
                self.gradient[i] += 4.0 * np.einsum('xmn,mn->x', aux_Fock_deriv, one_pdm_ao)

                # TODO: remove old commented out code
                #self.gradient[i] += 2.0 * np.einsum(
                #    'mt,np,xmtnp->x', one_pdm_ao, one_pdm_ao, d_eri)
                #self.gradient[i] -= frac_K * np.einsum(
                #    'mt,np,xmnpt->x', one_pdm_ao, one_pdm_ao, d_eri)

                t3 = tm.time()
                self.ostream.print_info("Two electron integral derivatives"
                                    + ' contribution computed in'
                                    + ' {:.2f} sec.'.format(t3 - t2))
                self.ostream.print_blank()
                self.ostream.flush()
        # Add the xc contribution
        if self._dft:
            density = self.scf_driver.density
            xcfun_label = self.scf_driver.xcfun.get_func_label()

            vxc_contrib = self.grad_vxc_contrib(molecule, ao_basis, density,
                                                density, xcfun_label)

            if self.rank == mpi_master():
                self.gradient += vxc_contrib

        # Add the nuclear contribution
        if self.rank == mpi_master():
            self.gradient += self.grad_nuc_contrib(molecule)

    def compute_energy(self, molecule, ao_basis):
        """
        Computes the energy at current geometry.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.

        :return:
            The energy.
        """

        self.ostream.mute()
        self.scf_driver.restart = False
        self.scf_driver.compute(molecule, ao_basis)
        assert_msg_critical(self.scf_driver.is_converged,
                            'ScfGradientDriver: SCF did not converge')
        self.ostream.unmute()

        return self.scf_driver.get_scf_energy()

    def __deepcopy__(self, memo):
        """
        Implements deepcopy.

        :param memo:
            The memo dictionary for deepcopy.

        :return:
            A deepcopy of self.
        """

        new_grad_drv = ScfGradientDriver(self.comm, self.ostream)

        for key, val in vars(self).items():
            if isinstance(val, (MPI.Intracomm, OutputStream)):
                pass
            elif isinstance(val, XCFunctional):
                new_grad_drv.key = XCFunctional(val)
            elif isinstance(val, MolecularGrid):
                new_grad_drv.key = MolecularGrid(val)
            else:
                new_grad_drv.key = deepcopy(val)

        return new_grad_drv
