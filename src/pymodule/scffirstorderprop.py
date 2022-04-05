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
import sys

from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import mpi_master
from .veloxchemlib import dipole_in_debye
from .outputstream import OutputStream


class ScfFirstOrderProperties:
    """
    Implements SCF first-order properties.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables:
        - properties: The dictionary of properties.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes SCF first-order properties.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            if comm.Get_rank() == mpi_master():
                ostream = OutputStream(sys.stdout)
            else:
                ostream = OutputStream(None)

        self.comm = comm
        self.rank = comm.Get_rank()

        self.ostream = ostream

        self.properties = {}

    def compute(self, molecule, basis, scf_tensors):
        """
        Computes SCF first-order properties.

        :param molecule:
            The molecule
        :param basis:
            The AO basis set.
        :param scf_tensors:
            The tensors from the converged SCF calculation.
        """

        if molecule.get_charge() != 0:
            coords = molecule.get_coordinates()
            nuclear_charges = molecule.elem_ids_to_numpy()
            origin = np.sum(coords.T * nuclear_charges,
                            axis=1) / np.sum(nuclear_charges)
        else:
            origin = np.zeros(3)

        # dipole integrals
        dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
        dipole_drv.origin = origin
        dipole_mats = dipole_drv.compute(molecule, basis)

        if self.rank == mpi_master():
            dipole_ints = (dipole_mats.x_to_numpy(), dipole_mats.y_to_numpy(),
                           dipole_mats.z_to_numpy())

            # electronic contribution
            total_density = scf_tensors['D_alpha'] + scf_tensors['D_beta']
            electronic_dipole = -1.0 * np.array(
                [np.sum(dipole_ints[d] * total_density) for d in range(3)])

            # nuclear contribution
            coords = molecule.get_coordinates()
            nuclear_charges = molecule.elem_ids_to_numpy()
            nuclear_dipole = np.sum((coords - origin).T * nuclear_charges,
                                    axis=1)

            self.properties['dipole moment'] = (nuclear_dipole +
                                                electronic_dipole)

    def get_property(self, key):
        """
        Gets SCF first-order property.

        :param key:
            The name of the property.

        :return:
            The property.
        """

        return self.properties[key]

    def print_properties(self, molecule):
        """
        Prints SCF first-order properties.

        :param molecule:
            The molecule.
        """

        self.ostream.print_blank()

        title = 'Ground-State Dipole Moment'
        self.ostream.print_header(title)
        self.ostream.print_header('-' * (len(title) + 2))

        # prints warning if the molecule is charged
        if molecule.get_charge() != 0:
            warn_msg = '*** Warning: Molecule has non-zero charge. Dipole'
            self.ostream.print_header(warn_msg.ljust(56))
            warn_msg = '    moment will be dependent on the choice of origin.'
            self.ostream.print_header(warn_msg.ljust(56))
            warn_msg = '    Center of nulcear charge is chosen as the origin.'
            self.ostream.print_header(warn_msg.ljust(56))

        self.ostream.print_blank()

        dip = self.properties['dipole moment']
        dip_au = list(dip) + [np.linalg.norm(dip)]
        dip_debye = [m * dipole_in_debye() for m in dip_au]

        for i, a in enumerate(['  X', '  Y', '  Z', 'Total']):
            valstr = '{:<5s} :'.format(a)
            valstr += '{:17.6f} a.u.'.format(dip_au[i])
            valstr += '{:17.6f} Debye   '.format(dip_debye[i])
            self.ostream.print_header(valstr)

        self.ostream.print_blank()
        self.ostream.flush()
