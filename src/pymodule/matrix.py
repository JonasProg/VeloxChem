from mpi4py import MPI

from .veloxchemlib import Matrix


def _Matrix_sum(matrix_a, matrix_b, datatype):
    """
    Helper function to enable matrices addition.

    :param matrix_a:
        The first matrix to be added.
    :param sub_matrix_b:
        The second matrix to be added.
    :param datatype:
        The datatype information (currently, not used).

    :return:
        The sum of two matrices.
    """
    return matrix_a + matrix_b


@staticmethod
def _Matrix_reduce(matrix, comm, mpi_id):
    """
    Reduces matrix over MPI communicator to specific root process.
    
    TODO: Replace this implementation with direct submatrices reduction
    code to overcome 2Gb limit in MPI4PY communications.
    
    :param matrix:
        The matrix to reduce.
    :param comm:
        The MPI communicator.
    :param mpi_id:
        The identifier of root process.

    :return:
        The reduced matrix.
    """

    sum_op = MPI.Op.Create(_Matrix_sum, commute=True)
    return comm.reduce(matrix, op=sum_op, root=mpi_id)


Matrix.reduce = _Matrix_reduce
