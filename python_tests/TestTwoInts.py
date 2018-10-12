from mpi4py import MPI
from veloxchem.VeloxChemLib import AODensityMatrix
from veloxchem.VeloxChemLib import AOFockMatrix
from veloxchem.VeloxChemLib import denmat
from veloxchem.VeloxChemLib import fockmat

import numpy as np
import unittest


class TestTwoInts(unittest.TestCase):

    def test_fock_matrix(self):

        data_j = [[ 1., .2, ], [ .2, 1., ]]
        data_k = [[ .9, .5, ], [ .5, .9, ]]

        arr_j = np.array(data_j)
        arr_k = np.array(data_k)
        arr_jk = arr_j + arr_k

        x = -0.5
        arr_kx = x * arr_k
        arr_jkx = arr_j + arr_kx

        fock = AOFockMatrix.from_numpy_list(
            [arr_jk, arr_jkx, arr_j, arr_k, arr_kx],
            [fockmat.restjk, fockmat.restjkx,
                fockmat.restj, fockmat.restk, fockmat.restkx],
            [1.0, x, 1.0, 1.0, x],
            [0, 0, 0, 0, 0])

        np_jkx = fock.to_numpy(1)
        np_j = fock.to_numpy(2)
        np_k = fock.to_numpy(3)

        self.assertEqual(0, np.max(np.abs(arr_j - np_j)))
        self.assertEqual(0, np.max(np.abs(arr_k - np_k)))
        self.assertEqual(0, np.max(np.abs(arr_jkx - np_jkx)))

        self.assertEqual(fockmat.restjk, fock.get_fock_type(0))
        self.assertEqual(x, fock.get_scale_factor(1))
        self.assertEqual(0, fock.get_density_identifier(2))

    def test_fock_rest_density(self):

        data_a = [[ 1., .2, ], [ .2, 1., ]]

        d_rest = AODensityMatrix.from_numpy_list([data_a], denmat.rest)

        f_rest = AOFockMatrix(d_rest)

        self.assertEqual(fockmat.restjk, f_rest.get_fock_type(0))
        self.assertEqual(1.0, f_rest.get_scale_factor(0))
        self.assertEqual(0, f_rest.get_density_identifier(0))


if __name__ == "__main__":
    unittest.main()
