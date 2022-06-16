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

import numpy as np
import time as tm

from .veloxchemlib import mpi_master
from .molecule import Molecule
from .outputstream import OutputStream
from .gradientdriver import GradientDriver
from .firstorderprop import FirstOrderProperties

# For PySCF integral derivatives
from .import_from_pyscf import overlap_deriv
from .import_from_pyscf import fock_deriv
from .import_from_pyscf import eri_deriv
from .import_from_pyscf import hcore_deriv
from .import_from_pyscf import vxc_deriv


class ScfGradientDriver(GradientDriver):
    """
    Implements SCF gradient driver.

    :param scf_drv:
        The SCF driver.
    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - scf_drv: The SCF driver.
        - delta_h: The displacement for finite difference.
    """

    def __init__(self, scf_drv, comm=None, ostream=None):
        """
        Initializes gradient driver.
        """

        super().__init__(scf_drv, comm, ostream)

        self.flag = 'SCF Gradient Driver'
        self.scf_drv = scf_drv
        self.delta_h = 0.001

    def update_settings(self, grad_dict, method_dict):
        """
        Updates settings in ScfGradientDriver.

        :param grad_dict:
            The input dictionary of gradient settings group.
        :param method_dict:
            The input dicitonary of method settings group.
        """

        super().update_settings(grad_dict, method_dict)

    def compute(self, molecule, ao_basis, min_basis=None):
        """
        Computes the analytical or numerical nuclear gradient.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.
        """

        if self.rank == mpi_master():
            self.print_header()

        start_time = tm.time()

        if self.numerical:
            scf_ostream_state = self.scf_drv.ostream.state
            self.scf_drv.ostream.state = False
            self.compute_numerical(molecule, ao_basis, min_basis)
            self.scf_drv.ostream.state = scf_ostream_state
        else:
            self.compute_analytical(molecule, ao_basis)

        if self.rank == mpi_master():
            # print gradient
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
        if self.rank == mpi_master():
            natm = molecule.number_of_atoms()
            nocc = molecule.number_of_alpha_electrons()
            mo = self.scf_drv.scf_tensors['C_alpha']
            mo_occ = mo[:, :nocc].copy()
            one_pdm_ao = self.scf_drv.scf_tensors['D_alpha']
            mo_energies = self.scf_drv.scf_tensors['E_alpha']
            eocc = mo_energies[:nocc]
            eo_diag = np.diag(eocc)
            epsilon_dm_ao = - np.linalg.multi_dot([mo_occ, eo_diag, mo_occ.T])

            # analytical gradient
            self.gradient = np.zeros((natm, 3))
            exc_gradient = np.zeros((natm, 3))

            for i in range(natm):
                d_ovlp = overlap_deriv(molecule, ao_basis, i)
                d_hcore = hcore_deriv(molecule, ao_basis, i)
                d_eri = eri_deriv(molecule, ao_basis, i)

                self.gradient[i] = ( 2.0 * np.einsum('mn,xmn->x', one_pdm_ao, d_hcore)
                                   + 2.0 * np.einsum('mn,xmn->x', epsilon_dm_ao, d_ovlp)
                                   )

                if self.dft:
                    if self.xcfun.is_hybrid():
                        fact_xc = self.xcfun.get_frac_exact_exchange()
                    else:
                        fact_xc = 0
                    self.gradient[i] += (
                                + 2.0 * np.einsum('mt,np,xmtnp->x', one_pdm_ao, one_pdm_ao, d_eri)
                                - fact_xc * np.einsum('mt,np,xmnpt->x', one_pdm_ao, one_pdm_ao, d_eri)
                                )
                else:
                    self.gradient[i] += (
                                + 2.0 * np.einsum('mt,np,xmtnp->x', one_pdm_ao, one_pdm_ao, d_eri)
                                - 1.0 * np.einsum('mt,np,xmnpt->x', one_pdm_ao, one_pdm_ao, d_eri)
                                )

        # Add the xc contribution
        if self.dft:
            density = self.scf_drv.density
            xcfun_label = self.scf_drv.xcfun.get_func_label()
            vxc_contrib = self.grad_vxc_contrib(molecule, ao_basis, density, density, xcfun_label)
            if self.rank == mpi_master():
                self.gradient += vxc_contrib

        # Add the nuclear contribution
        if self.rank == mpi_master():
            self.gradient += self.grad_nuc_contrib(molecule)

            self.omega_ao = epsilon_dm_ao #TODO remove again

    def compute_energy(self, molecule, ao_basis, min_basis=None):
        """
        Computes the energy at current geometry.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.

        :return:
            The energy.
        """

        self.scf_drv.compute(molecule, ao_basis, min_basis)
        return self.scf_drv.get_scf_energy()
