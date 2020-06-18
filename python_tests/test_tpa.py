from mpi4py import MPI
import numpy as np
import unittest
import os

from veloxchem.veloxchemlib import mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.tpa import TPA


class TestTPA(unittest.TestCase):

    def run_tpa_full(self, inpfile):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)
        scf_tensors = scf_drv.scf_tensors

        tpa = TPA(task.mpi_comm, task.ostream)
        tpa.update_settings({
            'damping': task.input_dict['response']['damping'],
            'frequencies': task.input_dict['response']['frequencies'],
            'conv_thresh': '1.0e-8','tpa': task.input_dict['response']['tpa']
        })
        (w,T4, T3, X3, A3, X2, A2, gamma) = tpa.compute(task.molecule, task.ao_basis, scf_tensors)

        w = 0.05
        T3_ref = 42.19841751 + 0.28695214j
        T4_ref = -11.43071305 - 0.04957732j
        X2_ref = -270.69041328 - 2.67837597j
        X3_ref = 81.62345190 + 0.35812832j
        A2_ref = -270.83461366 - 0.52758094j
        A3_ref = 27.21320341 + 0.03029788j
        gamma_ref = -401.92066716 - 2.58015589j

        if task.mpi_rank == mpi_master():
            self.assertTrue(
                np.max(np.abs(1 / 15 * T3[(w, -w, w)].real -
                              T3_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * T3[(w, -w, w)].imag -
                              T3_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(1 / 15 * T4[(w, -w, w)].real -
                              T4_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * T4[(w, -w, w)].imag -
                              T4_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(1 / 15 * X2[(w, -w, w)].real -
                              X2_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * X2[(w, -w, w)].imag -
                              X2_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(1 / 15 * X3[(w, -w, w)].real -
                              X3_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * X3[(w, -w, w)].imag -
                              X3_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(1 / 15 * A2[(w, -w, w)].real -
                              A2_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * A2[(w, -w, w)].imag -
                              A2_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(1 / 15 * A3[(w, -w, w)].real -
                              A3_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(1 / 15 * A3[(w, -w, w)].imag -
                              A3_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(gamma[(w, -w, w)].real -
                              gamma_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(gamma[(w, -w, w)].imag -
                              gamma_ref.imag)) < 1.0e-4)

    def run_tpa_red(self, inpfile):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)
        scf_tensors = scf_drv.scf_tensors

        tpa = TPA(task.mpi_comm, task.ostream)
        tpa.update_settings({
            'damping': task.input_dict['response']['damping'],
            'frequencies': task.input_dict['response']['frequencies'],
            'conv_thresh': '1.0e-8','tpa': task.input_dict['response']['tpa']
        })
        (w, T3_red, X2_red, A2_red,gamma_red) = tpa.compute(task.molecule, task.ao_basis, scf_tensors)

        w = 0.05

        T3_red_ref =  15.12982062+0.19793495j
        X2_red_ref =  -96.30910639-1.72679037j
        A2_red_ref =   -96.36431088-0.51886895j
        gamma_red_ref = -177.54359664-2.04772438j

        if task.mpi_rank == mpi_master():
            #Reduced
            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * T3_red[(w, -w, w)].real -
                           T3_red_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * T3_red[(w, -w, w)].imag -
                           T3_red_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * X2_red[(w, -w, w)].real -
                           X2_red_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * X2_red[(w, -w, w)].imag -
                           X2_red_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * A2_red[(w, -w, w)].real -
                           A2_red_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(
                    np.abs(1 / 15 * A2_red[(w, -w, w)].imag -
                           A2_red_ref.imag)) < 1.0e-4)

            self.assertTrue(
                np.max(np.abs(gamma_red[(w, -w, w)].real -
                              gamma_red_ref.real)) < 1.0e-4)
            self.assertTrue(
                np.max(np.abs(gamma_red[(w, -w, w)].imag -
                              gamma_red_ref.imag)) < 1.0e-4)

    def test_tpa(self):
        inpfile = os.path.join('inputs', 'water_tpa_full.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        self.run_tpa_full(inpfile)


        inpfile = os.path.join('inputs', 'water_tpa_red.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        self.run_tpa_red(inpfile)

if __name__ == "__main__":
    unittest.main()
