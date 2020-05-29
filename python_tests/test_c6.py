from mpi4py import MPI
import numpy as np
import unittest
import os

from veloxchem.veloxchemlib import mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.c6solver import C6Solver
from veloxchem.rspc6 import C6


class TestC6(unittest.TestCase):

    def run_c6(self, inpfile, potfile, xcfun_label, data_lines, ref_c6_value):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        # if potfile is not None:
        #     task.input_dict['method_settings']['potfile'] = potfile
        #     try:
        #         import cppe
        #     except ImportError:
        #         return

        if xcfun_label is not None:
            task.input_dict['method_settings']['xcfun'] = xcfun_label

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        ref_freqs, ref_results, ref_c6_value = self.comp_ref_c6(data_lines)
        ref_n_points = len(ref_freqs)

        c6_solver = C6Solver(task.mpi_comm, task.ostream)
        c6_solver.update_settings({'n_points': ref_n_points},
                                  task.input_dict['method_settings'])
        c6_results = c6_solver.compute(task.molecule, task.ao_basis,
                                       scf_drv.scf_tensors)

        if task.mpi_rank == mpi_master():
            freqs = set()
            for op, iw in c6_results['keys']:
                freqs.add(iw)
            freqs = sorted(list(freqs), reverse=True)[:-1]
            diff_freq = np.max(np.abs(np.array(freqs) - np.array(ref_freqs)))
            self.assertTrue(diff_freq < 1.0e-6)

            prop = np.array([
                -c6_results['response_functions'][(a, b, iw)]
                for iw in freqs
                for (a, b) in ['xx', 'yy', 'zz', 'xy', 'xz', 'yz']
            ])
            ref_prop = np.array([
                -ref_results['response_functions'][(a, b, iw)]
                for iw in ref_freqs
                for (a, b) in ['xx', 'yy', 'zz', 'xy', 'xz', 'yz']
            ])
            diff_prop = np.max(np.abs(prop - ref_prop))
            self.assertTrue(diff_prop < 1.0e-4)

            points, weights = np.polynomial.legendre.leggauss(ref_n_points)
            c6_value = C6.integrate(c6_results, freqs, points, weights, 0.3)
            self.assertTrue(abs(c6_value - ref_c6_value) < 1.0e-4)

    @staticmethod
    def comp_ref_c6(data_lines):

        ref_freqs = set()
        ref_results = {'response_functions': {}}

        for line in data_lines:
            content = line.split()

            a_op = content[1].lower()[0]
            b_op = content[2].lower()[0]
            freq = float(content[3])
            prop_real = float(content[4])

            ref_freqs.add(freq)
            ref_results['response_functions'][(a_op, b_op,
                                               freq)] = -(prop_real + 0j)

        ref_freqs = sorted(list(ref_freqs), reverse=True)[:-1]
        ref_n_points = len(ref_freqs)

        points, weights = np.polynomial.legendre.leggauss(ref_n_points)
        ref_c6_value = C6.integrate(ref_results, ref_freqs, points, weights,
                                    0.3)

        return ref_freqs, ref_results, ref_c6_value

    def test_c6_hf(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = None

        #   --------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part
        #   --------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        7.251840
             2   YDIPLEN   YDIPLEN    0.000000        8.724528
             3   ZDIPLEN   ZDIPLEN    0.000000        7.880569
             4   XDIPLEN   YDIPLEN    0.000000        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000        0.000000
             6   YDIPLEN   ZDIPLEN    0.000000       -0.000000
             7   XDIPLEN   XDIPLEN    0.006077        7.250980
             8   YDIPLEN   YDIPLEN    0.006077        8.723851
             9   ZDIPLEN   ZDIPLEN    0.006077        7.879847
            10   XDIPLEN   YDIPLEN    0.006077        0.000000
            11   XDIPLEN   ZDIPLEN    0.006077        0.000000
            12   YDIPLEN   ZDIPLEN    0.006077       -0.000000
            13   XDIPLEN   XDIPLEN    0.033952        7.225189
            14   YDIPLEN   YDIPLEN    0.033952        8.703479
            15   ZDIPLEN   ZDIPLEN    0.033952        7.858125
            16   XDIPLEN   YDIPLEN    0.033952        0.000000
            17   XDIPLEN   ZDIPLEN    0.033952        0.000000
            18   YDIPLEN   ZDIPLEN    0.033952       -0.000000
            19   XDIPLEN   XDIPLEN    0.093305        7.060265
            20   YDIPLEN   YDIPLEN    0.093305        8.568694
            21   ZDIPLEN   ZDIPLEN    0.093305        7.716148
            22   XDIPLEN   YDIPLEN    0.093305        0.000000
            23   XDIPLEN   ZDIPLEN    0.093305        0.000000
            24   YDIPLEN   ZDIPLEN    0.093305       -0.000000
            25   XDIPLEN   XDIPLEN    0.206999        6.468356
            26   YDIPLEN   YDIPLEN    0.206999        8.019561
            27   ZDIPLEN   ZDIPLEN    0.206999        7.164827
            28   XDIPLEN   YDIPLEN    0.206999        0.000000
            29   XDIPLEN   ZDIPLEN    0.206999        0.000000
            30   YDIPLEN   ZDIPLEN    0.206999       -0.000000
            31   XDIPLEN   XDIPLEN    0.434785        5.092646
            32   YDIPLEN   YDIPLEN    0.434785        6.390553
            33   ZDIPLEN   ZDIPLEN    0.434785        5.691196
            34   XDIPLEN   YDIPLEN    0.434785        0.000000
            35   XDIPLEN   ZDIPLEN    0.434785        0.000000
            36   YDIPLEN   ZDIPLEN    0.434785        0.000000
            37   XDIPLEN   XDIPLEN    0.964575        2.916907
            38   YDIPLEN   YDIPLEN    0.964575        3.423636
            39   ZDIPLEN   ZDIPLEN    0.964575        3.175088
            40   XDIPLEN   YDIPLEN    0.964575        0.000000
            41   XDIPLEN   ZDIPLEN    0.964575        0.000000
            42   YDIPLEN   ZDIPLEN    0.964575        0.000000
            43   XDIPLEN   XDIPLEN    2.650817        0.803666
            44   YDIPLEN   YDIPLEN    2.650817        0.842586
            45   ZDIPLEN   ZDIPLEN    2.650817        0.827618
            46   XDIPLEN   YDIPLEN    2.650817        0.000000
            47   XDIPLEN   ZDIPLEN    2.650817        0.000000
            48   YDIPLEN   ZDIPLEN    2.650817       -0.000000
            49   XDIPLEN   XDIPLEN   14.809490        0.035343
            50   YDIPLEN   YDIPLEN   14.809490        0.035496
            51   ZDIPLEN   ZDIPLEN   14.809490        0.035432
            52   XDIPLEN   YDIPLEN   14.809490        0.000000
            53   XDIPLEN   ZDIPLEN   14.809490        0.000000
            54   YDIPLEN   ZDIPLEN   14.809490       -0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        ref_c6_value = 36.230454

        self.run_c6(inpfile, potfile, xcfun_label, data_lines, ref_c6_value)

    def test_c6_dft(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'b3lyp'

        #   --------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part
        #   --------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        8.769176
             2   YDIPLEN   YDIPLEN    0.000000        9.696176
             3   ZDIPLEN   ZDIPLEN    0.000000        9.066348
             4   XDIPLEN   YDIPLEN    0.000000        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000       -0.000000
             6   YDIPLEN   ZDIPLEN    0.000000       -0.000000
             7   XDIPLEN   XDIPLEN    0.006077        8.767399
             8   YDIPLEN   YDIPLEN    0.006077        9.695275
             9   ZDIPLEN   ZDIPLEN    0.006077        9.065171
            10   XDIPLEN   YDIPLEN    0.006077        0.000000
            11   XDIPLEN   ZDIPLEN    0.006077       -0.000000
            12   YDIPLEN   ZDIPLEN    0.006077       -0.000000
            13   XDIPLEN   XDIPLEN    0.033952        8.714428
            14   YDIPLEN   YDIPLEN    0.033952        9.668164
            15   ZDIPLEN   ZDIPLEN    0.033952        9.029850
            16   XDIPLEN   YDIPLEN    0.033952        0.000000
            17   XDIPLEN   ZDIPLEN    0.033952       -0.000000
            18   YDIPLEN   ZDIPLEN    0.033952       -0.000000
            19   XDIPLEN   XDIPLEN    0.093305        8.388972
            20   YDIPLEN   YDIPLEN    0.093305        9.489670
            21   ZDIPLEN   ZDIPLEN    0.093305        8.803011
            22   XDIPLEN   YDIPLEN    0.093305        0.000000
            23   XDIPLEN   ZDIPLEN    0.093305       -0.000000
            24   YDIPLEN   ZDIPLEN    0.093305       -0.000000
            25   XDIPLEN   XDIPLEN    0.206999        7.367332
            26   YDIPLEN   YDIPLEN    0.206999        8.777294
            27   ZDIPLEN   ZDIPLEN    0.206999        7.978451
            28   XDIPLEN   YDIPLEN    0.206999        0.000000
            29   XDIPLEN   ZDIPLEN    0.206999        0.000000
            30   YDIPLEN   ZDIPLEN    0.206999       -0.000000
            31   XDIPLEN   XDIPLEN    0.434785        5.465732
            32   YDIPLEN   YDIPLEN    0.434785        6.781963
            33   ZDIPLEN   ZDIPLEN    0.434785        6.057655
            34   XDIPLEN   YDIPLEN    0.434785        0.000000
            35   XDIPLEN   ZDIPLEN    0.434785        0.000000
            36   YDIPLEN   ZDIPLEN    0.434785       -0.000000
            37   XDIPLEN   XDIPLEN    0.964575        2.970734
            38   YDIPLEN   YDIPLEN    0.964575        3.481899
            39   ZDIPLEN   ZDIPLEN    0.964575        3.229928
            40   XDIPLEN   YDIPLEN    0.964575        0.000000
            41   XDIPLEN   ZDIPLEN    0.964575        0.000000
            42   YDIPLEN   ZDIPLEN    0.964575       -0.000000
            43   XDIPLEN   XDIPLEN    2.650817        0.798664
            44   YDIPLEN   YDIPLEN    2.650817        0.839972
            45   ZDIPLEN   ZDIPLEN    2.650817        0.825605
            46   XDIPLEN   YDIPLEN    2.650817        0.000000
            47   XDIPLEN   ZDIPLEN    2.650817        0.000000
            48   YDIPLEN   ZDIPLEN    2.650817       -0.000000
            49   XDIPLEN   XDIPLEN   14.809490        0.035158
            50   YDIPLEN   YDIPLEN   14.809490        0.035549
            51   ZDIPLEN   ZDIPLEN   14.809490        0.035467
            52   XDIPLEN   YDIPLEN   14.809490        0.000000
            53   XDIPLEN   ZDIPLEN   14.809490        0.000000
            54   YDIPLEN   ZDIPLEN   14.809490        0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        ref_c6_value = 42.315098

        self.run_c6(inpfile, potfile, xcfun_label, data_lines, ref_c6_value)

    def test_c6_dft_slda(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'slda'

        #   --------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part
        #   --------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        9.287658
             2   YDIPLEN   YDIPLEN    0.000000        9.980757
             3   ZDIPLEN   ZDIPLEN    0.000000        9.449695
             4   XDIPLEN   YDIPLEN    0.000000        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000       -0.000000
             6   YDIPLEN   ZDIPLEN    0.000000        0.000000
             7   XDIPLEN   XDIPLEN    0.006077        9.285571
             8   YDIPLEN   YDIPLEN    0.006077        9.979787
             9   ZDIPLEN   ZDIPLEN    0.006077        9.448365
            10   XDIPLEN   YDIPLEN    0.006077        0.000000
            11   XDIPLEN   ZDIPLEN    0.006077       -0.000000
            12   YDIPLEN   ZDIPLEN    0.006077        0.000000
            13   XDIPLEN   XDIPLEN    0.033952        9.223464
            14   YDIPLEN   YDIPLEN    0.033952        9.950588
            15   ZDIPLEN   ZDIPLEN    0.033952        9.408517
            16   XDIPLEN   YDIPLEN    0.033952        0.000000
            17   XDIPLEN   ZDIPLEN    0.033952       -0.000000
            18   YDIPLEN   ZDIPLEN    0.033952        0.000000
            19   XDIPLEN   XDIPLEN    0.093305        8.844825
            20   YDIPLEN   YDIPLEN    0.093305        9.758587
            21   ZDIPLEN   ZDIPLEN    0.093305        9.153665
            22   XDIPLEN   YDIPLEN    0.093305        0.000000
            23   XDIPLEN   ZDIPLEN    0.093305       -0.000000
            24   YDIPLEN   ZDIPLEN    0.093305        0.000000
            25   XDIPLEN   XDIPLEN    0.206999        7.685719
            26   YDIPLEN   YDIPLEN    0.206999        8.996280
            27   ZDIPLEN   ZDIPLEN    0.206999        8.241285
            28   XDIPLEN   YDIPLEN    0.206999        0.000000
            29   XDIPLEN   ZDIPLEN    0.206999        0.000000
            30   YDIPLEN   ZDIPLEN    0.206999        0.000000
            31   XDIPLEN   XDIPLEN    0.434785        5.615926
            32   YDIPLEN   YDIPLEN    0.434785        6.892611
            33   ZDIPLEN   ZDIPLEN    0.434785        6.180450
            34   XDIPLEN   YDIPLEN    0.434785        0.000000
            35   XDIPLEN   ZDIPLEN    0.434785        0.000000
            36   YDIPLEN   ZDIPLEN    0.434785        0.000000
            37   XDIPLEN   XDIPLEN    0.964575        3.007170
            38   YDIPLEN   YDIPLEN    0.964575        3.500276
            39   ZDIPLEN   ZDIPLEN    0.964575        3.253097
            40   XDIPLEN   YDIPLEN    0.964575        0.000000
            41   XDIPLEN   ZDIPLEN    0.964575        0.000000
            42   YDIPLEN   ZDIPLEN    0.964575       -0.000000
            43   XDIPLEN   XDIPLEN    2.650817        0.800788
            44   YDIPLEN   YDIPLEN    2.650817        0.840180
            45   ZDIPLEN   ZDIPLEN    2.650817        0.826151
            46   XDIPLEN   YDIPLEN    2.650817        0.000000
            47   XDIPLEN   ZDIPLEN    2.650817        0.000000
            48   YDIPLEN   ZDIPLEN    2.650817        0.000000
            49   XDIPLEN   XDIPLEN   14.809490        0.035212
            50   YDIPLEN   YDIPLEN   14.809490        0.035603
            51   ZDIPLEN   ZDIPLEN   14.809490        0.035510
            52   XDIPLEN   YDIPLEN   14.809490        0.000000
            53   XDIPLEN   ZDIPLEN   14.809490        0.000000
            54   YDIPLEN   ZDIPLEN   14.809490        0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        ref_c6_value = 44.494604

        self.run_c6(inpfile, potfile, xcfun_label, data_lines, ref_c6_value)


if __name__ == "__main__":
    unittest.main()
