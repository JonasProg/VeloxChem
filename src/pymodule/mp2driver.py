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
import sys

from .veloxchemlib import AODensityMatrix
from .veloxchemlib import AOFockMatrix
from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import mpi_master
from .veloxchemlib import denmat
from .veloxchemlib import fockmat
from .outputstream import OutputStream
from .mointsdriver import MOIntegralsDriver
from .subcommunicators import SubCommunicators
from .qqscheme import get_qq_scheme
from .qqscheme import get_qq_type
from .errorhandler import assert_msg_critical
from .inputparser import parse_input


class Mp2Driver:
    """
    Implements MP2 driver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variable
        - e_mp2: The MP2 correlation energy.
        - comm: The MPI communicator.
        - rank: The MPI rank.
        - nodes: Number of MPI processes.
        - qq_type: The electron repulsion integrals screening scheme.
        - eri_thresh: The electron repulsion integrals screening threshold.
        - batch_size: The number of Fock matrices in each batch.
        - comm_size: The size of each subcommunicator.
        - ostream: The output stream.
        - conventional: The flag for using conventional (in-memory) AO-to-MO
          integral transformation.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes MP2 driver.
        """

        if comm is None:
            comm = MPI.COMM_WORLD

        if ostream is None:
            if comm.Get_rank() == mpi_master():
                ostream = OutputStream(sys.stdout)
            else:
                ostream = OutputStream(None)

        # mp2 energy
        self.e_mp2 = None

        # mpi information
        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()

        # screening scheme and batch size for Fock build
        self.qq_type = 'QQ_DEN'
        self.eri_thresh = 1.0e-12
        self.batch_size = 100

        # size of subcommunicator
        self.comm_size = 1

        # output stream
        self.ostream = ostream

        # use conventional (in-memory) AO-to-MO integral transformation?
        self.conventional = False

    def update_settings(self, mp2_dict, method_dict=None):
        """
        Updates settings in MP2 driver.

        :param mp2_dict:
            The dictionary of MP2 input.
        :param method_dict:
            The dictionary of method settings.
        """

        if method_dict is None:
            method_dict = {}

        mp2_keywords = {
            'qq_type': 'str_upper',
            'eri_thresh': 'float',
            'batch_size': 'int',
            'comm_size': 'int',
            'conventional': 'bool',
        }

        parse_input(self, mp2_keywords, mp2_dict)

        if self.comm_size != 1:
            if self.nodes % self.comm_size != 0:
                self.comm_size = 1

        if 'xcfun' in method_dict:
            errmsg = 'Mp2Driver: The \'xcfun\' keyword is not supported in MP2 '
            errmsg += 'calculation.'
            if self.rank == mpi_master():
                assert_msg_critical(False, errmsg)

        if 'potfile' in method_dict:
            errmsg = 'Mp2Driver: The \'potfile\' keyword is not supported in '
            errmsg += 'MP2 calculation.'
            if self.rank == mpi_master():
                assert_msg_critical(False, errmsg)

        if 'electric_field' in method_dict:
            errmsg = 'Mp2Driver: The \'electric field\' keyword is not '
            errmsg += 'supported in MP2 calculation.'
            if self.rank == mpi_master():
                assert_msg_critical(False, errmsg)

    def compute(self, molecule, ao_basis, mol_orbs):
        """
        Performs MP2 calculation.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param mol_orbs:
            The molecular orbitals.
        """

        if self.conventional:
            self.compute_conventional(molecule, ao_basis, mol_orbs)
        else:
            self.compute_distributed(molecule, ao_basis, mol_orbs)

    def compute_conventional(self, molecule, ao_basis, mol_orbs):
        """
        Performs conventional MP2 calculation.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param mol_orbs:
            The molecular orbitals.
        """

        moints_drv = MOIntegralsDriver(self.comm, self.ostream)

        if self.rank == mpi_master():

            orb_ene = mol_orbs.ea_to_numpy()
            nocc = molecule.number_of_alpha_electrons()
            eocc = orb_ene[:nocc]
            evir = orb_ene[nocc:]
            e_vv = evir.reshape(-1, 1) + evir

            self.e_mp2 = 0.0
            phys_oovv = moints_drv.compute_in_memory(molecule, ao_basis,
                                                     mol_orbs, 'phys_oovv')
            for i in range(phys_oovv.shape[0]):
                for j in range(phys_oovv.shape[1]):
                    ab = phys_oovv[i, j, :, :]
                    denom = e_vv - eocc[i] - eocc[j]
                    self.e_mp2 -= np.sum(ab * (2.0 * ab - ab.T) / denom)

            mp2_str = '*** MP2 correlation energy: %20.12f a.u.' % self.e_mp2
            self.ostream.print_header(mp2_str.ljust(92))
            self.ostream.print_blank()

    def compute_distributed(self, molecule, basis, mol_orbs):
        """
        Performs MP2 calculation via distributed Fock builds.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        :param mol_orbs:
            The molecular orbitals.
        """

        # subcommunicators

        if self.rank == mpi_master():
            assert_msg_critical(self.nodes % self.comm_size == 0,
                                'MP2 driver: invalid size of subcommunicator')

        grps = [p // self.comm_size for p in range(self.nodes)]
        subcomm = SubCommunicators(self.comm, grps)
        local_comm = subcomm.local_comm
        cross_comm = subcomm.cross_comm

        cross_rank = cross_comm.Get_rank()
        cross_nodes = cross_comm.Get_size()

        local_master = (local_comm.Get_rank() == mpi_master())
        global_master = (self.rank == mpi_master())

        # screening data

        eri_drv = ElectronRepulsionIntegralsDriver(local_comm)
        screening = eri_drv.compute(get_qq_scheme(self.qq_type),
                                    self.eri_thresh, molecule, basis)

        # prepare MO integrals

        if local_master:
            e_mp2 = 0.0
            mol_orbs.broadcast(cross_comm.Get_rank(), cross_comm)
            nocc = molecule.number_of_alpha_electrons()

            mo = mol_orbs.alpha_to_numpy()
            mo_occ = mo[:, :nocc].copy()
            mo_vir = mo[:, nocc:].copy()

            orb_ene = mol_orbs.ea_to_numpy()
            evir = orb_ene[nocc:]
            eab = evir.reshape(-1, 1) + evir

            mo_ints_ids = [
                (i, j) for i in range(nocc) for j in range(i + 1, nocc)
            ] + [(i, i) for i in range(nocc)]
            self.print_header(len(mo_ints_ids))
            valstr = 'Monitoring calculation on master node.'
            self.ostream.print_header(valstr.ljust(80))
            self.ostream.print_blank()

            ave, res = divmod(len(mo_ints_ids), cross_nodes)
            count = [ave + 1 if i < res else ave for i in range(cross_nodes)]
            displ = [sum(count[:i]) for i in range(cross_nodes)]

            valstr = '{:d} Fock matrices '.format(count[cross_rank])
            valstr += 'will be processed on master node.'
            self.ostream.print_header(valstr.ljust(80))
            self.ostream.print_blank()
            self.ostream.flush()

            mo_ints_start = displ[cross_rank]
            mo_ints_end = mo_ints_start + count[cross_rank]

            num_batches = count[cross_rank] // self.batch_size
            if count[cross_rank] % self.batch_size != 0:
                num_batches += 1
        else:
            num_batches = None

        num_batches = local_comm.bcast(num_batches, root=mpi_master())

        # compute MO integrals in batches

        batch_t0 = tm.time()

        for batch_ind in range(num_batches):

            if local_master:

                batch_start = mo_ints_start + batch_ind * self.batch_size
                batch_end = min(batch_start + self.batch_size, mo_ints_end)
                batch_ids = mo_ints_ids[batch_start:batch_end]

                dks = []
                for i, j in batch_ids:
                    mo_ij = np.zeros((nocc, nocc))
                    mo_ij[i, j] = 1.0
                    dks.append(np.linalg.multi_dot([mo_occ, mo_ij, mo_occ.T]))
                dens = AODensityMatrix(dks, denmat.rest)
            else:
                dens = AODensityMatrix()

            dens.broadcast(local_comm.Get_rank(), local_comm)

            fock = AOFockMatrix(dens)
            for i in range(fock.number_of_fock_matrices()):
                fock.set_fock_type(fockmat.rgenk, i)

            eri_drv.compute(fock, dens, molecule, basis, screening)
            fock.reduce_sum(local_comm.Get_rank(), local_comm.Get_size(),
                            local_comm)

            if local_master:
                for ind, (i, j) in enumerate(batch_ids):
                    f_ao = fock.alpha_to_numpy(ind)
                    f_vv = np.linalg.multi_dot([mo_vir.T, f_ao, mo_vir])
                    de = orb_ene[i] + orb_ene[j] - eab

                    ab = f_vv
                    e_mp2 += np.sum(ab * (2.0 * ab - ab.T) / de)

                    if i != j:
                        ba = f_vv.T
                        e_mp2 += np.sum(ba * (2.0 * ba - ba.T) / de)

            if global_master:
                valstr = '{:d} / {:d}'.format(batch_end - mo_ints_start,
                                              mo_ints_end - mo_ints_start)
                valstr += ' Fock matrices processed. Time: {:.2f} sec'.format(
                    tm.time() - batch_t0)
                self.ostream.print_header(valstr.ljust(80))
                self.ostream.print_blank()
                self.ostream.flush()

        if local_master:
            e_mp2 = cross_comm.reduce(e_mp2, root=mpi_master())

        if global_master:
            self.e_mp2 = e_mp2
            mp2_str = '*** MP2 correlation energy: {:20.12f} a.u. '.format(
                self.e_mp2)
            self.ostream.print_header(mp2_str.ljust(80))
            self.ostream.print_blank()
            self.ostream.flush()

    def print_header(self, num_matrices):
        """
        Prints header for the MP2 driver.

        :param num_matrices:
            The number of Fock matrices to be computed.
        """

        self.ostream.print_blank()
        self.ostream.print_header('MP2 Driver Setup')
        self.ostream.print_header(18 * '=')
        self.ostream.print_blank()

        str_width = 60
        cur_str = 'Number of Fock Matrices      : ' + str(num_matrices)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'Size of Fock Matrices Batch  : ' + str(self.batch_size)
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = 'Number of Subcommunicators   : '
        cur_str += str(self.nodes // self.comm_size)
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = 'ERI Screening Scheme         : ' + get_qq_type(self.qq_type)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = 'ERI Screening Threshold      : {:.1e}'.format(
            self.eri_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))
        self.ostream.print_blank()
        self.ostream.flush()
