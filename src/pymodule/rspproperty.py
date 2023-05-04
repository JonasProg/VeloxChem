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
import sys

from .veloxchemlib import mpi_master
from .rspdriver import ResponseDriver
from .outputstream import OutputStream
from .errorhandler import assert_msg_critical


class ResponseProperty:
    """
    Implements the base class for response property/spectroscopy.

    :param rsp_dict:
        The input dictionary that defines the property/spectroscopy.
    :param method_dict:
        The dictionary of method settings.

    Instance variables
        - rsp_dict: The dictionary of response input.
        - method_dict: The dictionary of method settings.
        - rsp_driver: The response driver.
        - rsp_property: The dictionary of response property.
    """

    def __init__(self, rsp_dict=None, method_dict=None):
        """
        Initializes response property/spectroscopy.
        """

        self._rsp_dict = rsp_dict
        self._method_dict = method_dict

        self._rsp_driver = None
        self._rsp_property = None

    def init_driver(self, comm=None, ostream=None):
        """
        Initializes response driver.

        :param comm:
            The MPI communicator.
        :param ostream:
            The output stream.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            if comm.Get_rank() == mpi_master():
                ostream = OutputStream(sys.stdout)
            else:
                ostream = OutputStream(None)

        self._rsp_driver = ResponseDriver(comm, ostream)
        self._rsp_driver.update_settings(self._rsp_dict, self._method_dict)

    def print_keywords(self):
        """
        Prints input keywords for response property.
        """

        assert_msg_critical(
            self._rsp_driver is not None,
            'ResponseProperty: response driver not initialized')

        assert_msg_critical(
            self.solver is not None,
            'ResponseProperty: response solver not initialized')

        self.solver.print_keywords()

    def compute(self, molecule, basis, scf_tensors):
        """
        Computes response property/spectroscopy.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.
        """

        self._rsp_property = self._rsp_driver.compute(molecule, basis,
                                                      scf_tensors)

        if not self.is_converged:
            return

        if self._rsp_driver.rank == mpi_master():
            self.print_property(self._rsp_driver.ostream)

    @property
    def solver(self):
        """
        Returns the response solver.
        """

        return self._rsp_driver.solver

    @property
    def is_converged(self):
        """
        Returns whether the response calculation is converged.
        """

        return self._rsp_driver.is_converged

    @property
    def rsp_property(self):
        """
        Returns the response property dictionary.
        """

        return self._rsp_property

    def get_property(self, key):
        """
        Gets response property/spectroscopy.

        :param key:
            The keyword for the property.

        :return:
            The property.
        """

        return None

    def print_property(self, ostream):
        """
        Prints response property/spectroscopy to output stream.

        :param ostream:
            The output stream.
        """

        return
