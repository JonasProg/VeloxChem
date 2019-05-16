from mpi4py import MPI
import unittest

from veloxchem.veloxchemlib import mpi_master
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.crsp import ComplexResponse
from veloxchem.mpitask import MpiTask


class TestCppDriver(unittest.TestCase):

    def test_water_cpp(self):

        # scf
        task = MpiTask(["inputs/water.inp", None], MPI.COMM_WORLD)
        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)

        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)
        scf_tensors = scf_drv.scf_tensors

        # cpp
        cpp_solver = ComplexResponse(task.mpi_comm, task.ostream)

        cpp_solver.update_settings({
            'operators': 'xyz',
            'frequencies': '0, 0.5',
            'damping': 1.0,
            'eri_thresh': 1.0e-12,
            'qq_type': 'QQ_DEN',
            'conv_thresh': 1.0e-6,
            'max_iter': 50,
        })

        results = cpp_solver.compute(task.molecule, task.ao_basis, scf_tensors)

        if task.mpi_rank == mpi_master():

            reference = {
                ('x', 0): complex(2.817683, 0.000000),
                ('y', 0): complex(3.292074, 0.000000),
                ('z', 0): complex(3.061127, 0.000000),
                ('x', 0.5): complex(2.398085, 1.264313),
                ('y', 0.5): complex(2.661202, 1.628714),
                ('z', 0.5): complex(2.554879, 1.439370),
            }

            for key in results:
                real_val = results[key].real
                imag_val = results[key].imag
                real_ref = reference[key].real
                imag_ref = reference[key].imag
                self.assertTrue(abs(real_val - real_ref) < 1.0e-6)
                self.assertTrue(abs(imag_val - imag_ref) < 1.0e-6)

        task.finish()


if __name__ == "__main__":
    unittest.main()
