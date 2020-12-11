from mpi4py import MPI
from pathlib import Path
import numpy as np
import unittest

from veloxchem.veloxchemlib import mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.scfgradientdriver import ScfGradientDriver


class TestGrad(unittest.TestCase):

    def run_grad(self, inpfile, ref_grad):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        grad_drv = ScfGradientDriver(task.mpi_comm, task.ostream, scf_drv)
        grad_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        if task.mpi_rank == mpi_master():
            grad = grad_drv.get_gradient()
            self.assertTrue(np.max(np.abs(grad - ref_grad)) < 1.0e-6)

    def test_nh3(self):

        here = Path(__file__).parent
        inpfile = str(here / 'inputs' / 'nh3.inp')

        ref_grad = np.array([
            [0.0133714, -0.0004248, -0.0062534, -0.0066932],
            [-0.0056538, 0.0113812, -0.0033086, -0.0024188],
            [-0.0006128, 0.0005803, 0.0089449, -0.0089123],
        ]).T

        self.run_grad(inpfile, ref_grad)


if __name__ == "__main__":
    unittest.main()
