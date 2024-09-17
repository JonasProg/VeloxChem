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

from os import environ
import psutil
import ctypes

from .veloxchemlib import mpi_master


def get_batch_size(input_batch_size, n_total, n_ao, comm):
    """
    Gets batch size for Fock matrix computation.

    :param input_batch_size:
        The batch size from input.
    :param n_total:
        The total number of Fock matrices.
    :param n_ao:
        The number of atomic orbitals in one Fock matrix.
    :param comm:
        The communicator.

    :return:
        The batch size for Fock matrix computation..
    """

    batch_size = input_batch_size

    # check available memories on the nodes
    total_mem = psutil.virtual_memory().total
    total_mem_list = comm.gather(total_mem, root=mpi_master())

    if comm.Get_rank() == mpi_master():

        # check if master node has larger memory
        mem_adjust = 0.0
        if total_mem > min(total_mem_list):
            mem_adjust = total_mem - min(total_mem_list)

        # computes maximum batch size from available memory
        avail_mem = psutil.virtual_memory().available - mem_adjust
        if 'SLURM_NTASKS_PER_NODE' in environ:
            avail_mem //= int(environ['SLURM_NTASKS_PER_NODE'])
        mem_per_mat = n_ao**2 * ctypes.sizeof(ctypes.c_double)
        nthreads = int(environ['OMP_NUM_THREADS'])
        # TODO: double check the esitation of max_batch_size
        max_batch_size = int(avail_mem / (mem_per_mat * nthreads))
        max_batch_size = max(1, max_batch_size)

        # note: batch_size will be zero if n_total is zero
        if batch_size is None:
            batch_size = min(n_total, max_batch_size)

    batch_size = comm.bcast(batch_size, root=mpi_master())

    return batch_size


def get_number_of_batches(n_total, batch_size, comm):
    """
    Gets number of batches for Fock matrix computation.

    :param n_total:
        The total number of Fock matrices.
    :param batch_size:
        The batch size for Fock matrix computation.
    :param comm:
        The communicator.

    :return:
        The number of batches for Fock matrix computation.
    """

    num_batches = None

    # TODO: double check batch size

    # note: num_batches will be zero if batch_size is zero
    if comm.Get_rank() == mpi_master():
        if batch_size > 0:
            num_batches = n_total // batch_size
            if n_total % batch_size != 0:
                num_batches += 1
        else:
            num_batches = 0

    num_batches = comm.bcast(num_batches, root=mpi_master())

    return num_batches
