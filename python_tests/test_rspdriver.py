from mpi4py import MPI
from veloxchem.veloxchemlib import ElectronRepulsionIntegralsDriver
from veloxchem.veloxchemlib import ericut
from veloxchem.veloxchemlib import mpi_master
from veloxchem.outputstream import OutputStream
from veloxchem.molecularorbitals import MolecularOrbitals
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.tdaexcidriver import TDAExciDriver
from veloxchem.rspdriver import ResponseDriver
from veloxchem.lrsolver import LinearResponseSolver
from veloxchem.mpitask import MpiTask

import numpy as np
import unittest


class TestRspDriver(unittest.TestCase):

    def test_h2se_tda(self):

        # scf
        task = MpiTask(["inputs/h2se.inp", None], MPI.COMM_WORLD)
        scf_drv = ScfRestrictedDriver()

        scf_drv.compute_task(task)
        mol_orbs = scf_drv.mol_orbs

        # TDA
        tda_exci = TDAExciDriver(task.mpi_rank, task.mpi_size)

        tda_exci.set_number_states(3)
        tda_exci.set_eri(1.0e-12, 'QQ_DEN')
        tda_exci.set_solver(1.0e-4, 50)

        eri_drv = ElectronRepulsionIntegralsDriver(task.mpi_rank, task.mpi_size,
                                                   task.mpi_comm)

        qq_data = eri_drv.compute(ericut.qq, 1.0e-12, task.molecule,
                                  task.ao_basis)

        tda_exci.compute(mol_orbs, task.molecule, task.ao_basis, task.mpi_comm,
                         OutputStream())

        if task.mpi_rank == mpi_master():

            reigs, rnorms = tda_exci.solver.get_eigenvalues()

            ref_eigs = np.array([0.207436, 0.257474, 0.368358])

            self.assertTrue(np.max(np.abs(reigs - ref_eigs)) < 1.0e-6)

        # polarizability
        lr_solver = LinearResponseSolver()

        lr_solver.set_eri(1.0e-12, 'QQ_DEN')
        lr_solver.set_solver(1.0e-5, 50)

        lr_prop = lr_solver.compute(mol_orbs, task.molecule, task.ao_basis,
                                    task.mpi_comm, OutputStream())

        if task.mpi_rank == mpi_master():

            ref_polar = {
                ('x', 'x', 0): 15.2673,
                ('x', 'y', 0): 0.0,
                ('y', 'x', 0): 0.0,
                ('y', 'y', 0): 23.2248,
                ('x', 'z', 0): 0.0,
                ('z', 'x', 0): 0.0,
                ('y', 'z', 0): -0.759273,
                ('z', 'y', 0): -0.759273,
                ('z', 'z', 0): 23.2248,
            }

            for key, val in lr_prop.items():
                ref = -ref_polar[key]
                diff = abs(val - ref)
                if abs(ref) > 0.0:
                    rel_diff = abs(diff / ref)
                    self.assertTrue(rel_diff < 5.0e-6)
                else:
                    self.assertTrue(diff < 1.0e-10)

        task.finish()


if __name__ == "__main__":
    unittest.main()
