from mpi4py import MPI
import numpy as np
import unittest
import random
import os

from veloxchem.veloxchemlib import mpi_master
from veloxchem.veloxchemlib import hartree_in_ev
from veloxchem.mpitask import MpiTask
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.lreigensolver import LinearResponseEigenSolver


class TestRPA(unittest.TestCase):

    def run_rpa(self, inpfile, potfile, xcfun_label, data_lines):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        if potfile is not None:
            task.input_dict['method_settings']['potfile'] = potfile
            try:
                import cppe
            except ImportError:
                return

        if xcfun_label is not None:
            task.input_dict['method_settings']['xcfun'] = xcfun_label

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        ref_exc_ene = [float(line.split()[1]) for line in data_lines]
        ref_osc_str = [float(line.split()[3]) for line in data_lines]
        ref_rot_str = [float(line.split()[4]) for line in data_lines]

        rpa_solver = LinearResponseEigenSolver(task.mpi_comm, task.ostream)
        rpa_solver.update_settings(
            {
                'nstates': len(ref_exc_ene),
                'batch_size': random.choice([1, 10, 100])
            }, task.input_dict['method_settings'])
        rpa_results = rpa_solver.compute(task.molecule, task.ao_basis,
                                         scf_drv.scf_tensors)

        if task.mpi_rank == mpi_master():
            exc_ene = rpa_results['eigenvalues'] * hartree_in_ev()
            osc_str = rpa_results['oscillator_strengths']
            rot_str = rpa_results['rotatory_strengths']

            self.assertTrue(np.max(np.abs(exc_ene - ref_exc_ene)) < 5.0e-4)
            self.assertTrue(np.max(np.abs(osc_str - ref_osc_str)) < 5.0e-4)
            self.assertTrue(np.max(np.abs(rot_str - ref_rot_str)) < 1.0e-2)

    def test_rpa_hf(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = None

        #  State Frequency   Oscillator Strength    Rotatory  Strength
        #          (eV)      Velocity     Length    Velocity    Length
        #  -----------------------------------------------------------
        raw_data = """
            1     8.7456     0.0532     0.0519    -0.0000    -0.0000
            2    10.4328     0.0000     0.0000    -0.0000     0.0000
            3    11.1388     0.1003     0.1018     0.0000     0.0000
            4    12.1540     0.0025     0.0048    -0.0000     0.0000
            5    12.7907     0.0235     0.0237    -0.0000    -0.0000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_rpa(inpfile, potfile, xcfun_label, data_lines)

    def test_rpa_dft(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'b3lyp'

        #  State Frequency   Oscillator Strength    Rotatory  Strength
        #          (eV)      Velocity     Length    Velocity    Length
        #  -----------------------------------------------------------
        raw_data = """
            1     6.9865     0.0522     0.0520    -0.0000     0.0000
            2     8.4274     0.0000     0.0000     0.0000     0.0000
            3     9.1958     0.0818     0.0848    -0.0000    -0.0000
            4    10.2976     0.0004     0.0000    -0.0000    -0.0000
            5    10.6191     0.0111     0.0116    -0.0000    -0.0000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_rpa(inpfile, potfile, xcfun_label, data_lines)

    def test_rpa_dft_slda(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'slda'

        #  State Frequency   Oscillator Strength    Rotatory  Strength
        #          (eV)      Velocity     Length    Velocity    Length
        #  -----------------------------------------------------------
        raw_data = """
            1     6.7693     0.0555     0.0551    -0.0000     0.0000
            2     8.2202     0.0000     0.0000     0.0000    -0.0000
            3     8.8886     0.0823     0.0851    -0.0000    -0.0000
            4    10.1292     0.0014     0.0002     0.0000     0.0000
            5    10.3354     0.0099     0.0106     0.0000     0.0000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_rpa(inpfile, potfile, xcfun_label, data_lines)

    def test_rpa_hf_pe(self):

        inpfile = os.path.join('inputs', 'pe_water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = os.path.join('inputs', 'pe_water.pot')
        if not os.path.isfile(potfile):
            potfile = os.path.join('python_tests', potfile)

        xcfun_label = None

        #  State Frequency   Oscillator Strength    Rotatory  Strength
        #          (eV)      Velocity     Length    Velocity    Length
        #  -----------------------------------------------------------
        raw_data = """
            1     9.1117     0.0582     0.0590     0.1640     0.6486
            2    11.1318     0.0115     0.0122    -0.5366    -0.4150
            3    11.4239     0.1144     0.1179    -0.1943    -0.9426
            4    11.9383     0.0007     0.0014     0.1049     0.1939
            5    12.8292     0.0004     0.0004    -0.0033    -0.2579
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_rpa(inpfile, potfile, xcfun_label, data_lines)

    def test_rpa_dft_pe(self):

        inpfile = os.path.join('inputs', 'pe_water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = os.path.join('inputs', 'pe_water.pot')
        if not os.path.isfile(potfile):
            potfile = os.path.join('python_tests', potfile)

        xcfun_label = 'b3lyp'

        #  State Frequency   Oscillator Strength    Rotatory  Strength
        #          (eV)      Velocity     Length    Velocity    Length
        #  -----------------------------------------------------------
        raw_data = """
            1     7.3121     0.0540     0.0568     0.1649     0.8479
            2     9.0031     0.0065     0.0071    -0.0945     0.0751
            3     9.5084     0.0886     0.0946    -0.3706    -1.2063
            4    10.1815     0.0005     0.0003    -0.1341    -0.3188
            5    11.0079     0.0046     0.0025     0.2632    -0.1881
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_rpa(inpfile, potfile, xcfun_label, data_lines)


if __name__ == "__main__":
    unittest.main()
