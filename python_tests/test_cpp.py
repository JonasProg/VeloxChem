from mpi4py import MPI
import numpy as np
import unittest
import random
import pytest
import sys
import os
try:
    import cppe
except ImportError:
    pass

from veloxchem.veloxchemlib import mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.cppsolver import ComplexResponse


class TestCPP(unittest.TestCase):

    def run_cpp(self, inpfile, potfile, xcfun_label, data_lines):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        if potfile is not None:
            task.input_dict['method_settings']['potfile'] = potfile

        if xcfun_label is not None:
            task.input_dict['method_settings']['xcfun'] = xcfun_label

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        ref_freqs = []
        for line in data_lines:
            if float(line.split()[3]) not in ref_freqs:
                ref_freqs.append(float(line.split()[3]))
        ref_freqs_str = [str(x) for x in ref_freqs]
        ref_prop_real = [float(line.split()[4]) for line in data_lines]
        ref_prop_imag = [float(line.split()[5]) for line in data_lines]

        cpp_solver = ComplexResponse(task.mpi_comm, task.ostream)
        cpp_solver.update_settings(
            {
                'frequencies': ','.join(ref_freqs_str),
                'batch_size': random.choice([1, 10, 100])
            }, task.input_dict['method_settings'])
        cpp_results = cpp_solver.compute(task.molecule, task.ao_basis,
                                         scf_drv.scf_tensors)

        if task.mpi_rank == mpi_master():
            prop = np.array([
                -cpp_results['response_functions'][(a, b, w)]
                for w in ref_freqs
                for (a, b) in ['xx', 'yy', 'zz', 'xy', 'xz', 'yz']
            ])
            self.assertTrue(np.max(np.abs(prop.real - ref_prop_real)) < 1.0e-4)
            self.assertTrue(np.max(np.abs(prop.imag - ref_prop_imag)) < 1.0e-4)

    def test_cpp_hf(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = None

        #   ------------------------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part       Imag part
        #   ------------------------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        7.251351        0.000000
             2   YDIPLEN   YDIPLEN    0.000000        8.724135       -0.000000
             3   ZDIPLEN   ZDIPLEN    0.000000        7.880179       -0.000000
             4   XDIPLEN   YDIPLEN    0.000000       -0.000000       -0.000000
             5   XDIPLEN   ZDIPLEN    0.000000       -0.000000        0.000000
             6   YDIPLEN   ZDIPLEN    0.000000       -0.000001        0.000000
             7   XDIPLEN   XDIPLEN    0.050000        7.310582        0.010992
             8   YDIPLEN   YDIPLEN    0.050000        8.770219        0.008458
             9   ZDIPLEN   ZDIPLEN    0.050000        7.929579        0.009102
            10   XDIPLEN   YDIPLEN    0.050000       -0.000000        0.000000
            11   XDIPLEN   ZDIPLEN    0.050000       -0.000000        0.000000
            12   YDIPLEN   ZDIPLEN    0.050000       -0.000001       -0.000000
            13   XDIPLEN   XDIPLEN    0.100000        7.501748        0.024595
            14   YDIPLEN   YDIPLEN    0.100000        8.912291        0.017626
            15   ZDIPLEN   ZDIPLEN    0.100000        8.084292        0.019433
            16   XDIPLEN   YDIPLEN    0.100000       -0.000000        0.000000
            17   XDIPLEN   ZDIPLEN    0.100000        0.000000        0.000000
            18   YDIPLEN   ZDIPLEN    0.100000       -0.000001       -0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_cpp(inpfile, potfile, xcfun_label, data_lines)

    def test_cpp_dft(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'b3lyp'

        #   ------------------------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part       Imag part
        #   ------------------------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        8.768177        0.000000
             2   YDIPLEN   YDIPLEN    0.000000        9.695669       -0.000000
             3   ZDIPLEN   ZDIPLEN    0.000000        9.065686       -0.000000
             4   XDIPLEN   YDIPLEN    0.000000       -0.000000        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000        0.000000       -0.000000
             6   YDIPLEN   ZDIPLEN    0.000000       -0.000000       -0.000000
             7   XDIPLEN   XDIPLEN    0.050000        8.892111        0.023320
             8   YDIPLEN   YDIPLEN    0.050000        9.757128        0.011297
             9   ZDIPLEN   ZDIPLEN    0.050000        9.146641        0.015001
            10   XDIPLEN   YDIPLEN    0.050000       -0.000000        0.000000
            11   XDIPLEN   ZDIPLEN    0.050000        0.000000        0.000000
            12   YDIPLEN   ZDIPLEN    0.050000       -0.000000       -0.000000
            13   XDIPLEN   XDIPLEN    0.100000        9.316354        0.057235
            14   YDIPLEN   YDIPLEN    0.100000        9.947768        0.023764
            15   ZDIPLEN   ZDIPLEN    0.100000        9.406230        0.033220
            16   XDIPLEN   YDIPLEN    0.100000       -0.000000        0.000000
            17   XDIPLEN   ZDIPLEN    0.100000        0.000000        0.000000
            18   YDIPLEN   ZDIPLEN    0.100000       -0.000000       -0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_cpp(inpfile, potfile, xcfun_label, data_lines)

    def test_cpp_dft_slda(self):

        inpfile = os.path.join('inputs', 'water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = None

        xcfun_label = 'slda'

        #   ------------------------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part       Imag part
        #   ------------------------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        9.286484        0.000000
             2   YDIPLEN   YDIPLEN    0.000000        9.980211        0.000000
             3   ZDIPLEN   ZDIPLEN    0.000000        9.448947       -0.000000
             4   XDIPLEN   YDIPLEN    0.000000       -0.000000       -0.000000
             5   XDIPLEN   ZDIPLEN    0.000000        0.000000       -0.000000
             6   YDIPLEN   ZDIPLEN    0.000000        0.000000       -0.000000
             7   XDIPLEN   XDIPLEN    0.050000        9.432332        0.027519
             8   YDIPLEN   YDIPLEN    0.050000       10.046436        0.012177
             9   ZDIPLEN   ZDIPLEN    0.050000        9.540451        0.016980
            10   XDIPLEN   YDIPLEN    0.050000       -0.000000        0.000000
            11   XDIPLEN   ZDIPLEN    0.050000        0.000000        0.000000
            12   YDIPLEN   ZDIPLEN    0.050000        0.000000        0.000000
            13   XDIPLEN   XDIPLEN    0.100000        9.937587        0.068826
            14   YDIPLEN   YDIPLEN    0.100000       10.252178        0.025677
            15   ZDIPLEN   ZDIPLEN    0.100000        9.835558        0.037937
            16   XDIPLEN   YDIPLEN    0.100000       -0.000000        0.000000
            17   XDIPLEN   ZDIPLEN    0.100000        0.000000        0.000000
            18   YDIPLEN   ZDIPLEN    0.100000        0.000000        0.000000
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_cpp(inpfile, potfile, xcfun_label, data_lines)

    @pytest.mark.skipif('cppe' not in sys.modules, reason='cppe not available')
    def test_cpp_hf_pe(self):

        inpfile = os.path.join('inputs', 'pe_water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = os.path.join('inputs', 'pe_water.pot')
        if not os.path.isfile(potfile):
            potfile = os.path.join('python_tests', potfile)

        xcfun_label = None

        #   ------------------------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part       Imag part
        #   ------------------------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        8.746878        0.000000
             2   YDIPLEN   YDIPLEN    0.000000        7.609015        0.000000
             3   ZDIPLEN   ZDIPLEN    0.000000        8.106846        0.000000
             4   XDIPLEN   YDIPLEN    0.000000        0.374077        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000        0.250180       -0.000000
             6   YDIPLEN   ZDIPLEN    0.000000        0.273085       -0.000000
             7   XDIPLEN   XDIPLEN    0.050000        8.792642        0.008401
             8   YDIPLEN   YDIPLEN    0.050000        7.669364        0.011180
             9   ZDIPLEN   ZDIPLEN    0.050000        8.157647        0.009357
            10   XDIPLEN   YDIPLEN    0.050000        0.372130       -0.000379
            11   XDIPLEN   ZDIPLEN    0.050000        0.254698        0.000836
            12   YDIPLEN   ZDIPLEN    0.050000        0.276004        0.000536
            13   XDIPLEN   XDIPLEN    0.100000        8.933902        0.017543
            14   YDIPLEN   YDIPLEN    0.100000        7.862654        0.024715
            15   ZDIPLEN   ZDIPLEN    0.100000        8.316520        0.019932
            16   XDIPLEN   YDIPLEN    0.100000        0.364602       -0.001089
            17   XDIPLEN   ZDIPLEN    0.100000        0.269121        0.001838
            18   YDIPLEN   ZDIPLEN    0.100000        0.284970        0.001107
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_cpp(inpfile, potfile, xcfun_label, data_lines)

    @pytest.mark.skipif('cppe' not in sys.modules, reason='cppe not available')
    def test_cpp_dft_pe(self):

        inpfile = os.path.join('inputs', 'pe_water.inp')
        if not os.path.isfile(inpfile):
            inpfile = os.path.join('python_tests', inpfile)

        potfile = os.path.join('inputs', 'pe_water.pot')
        if not os.path.isfile(potfile):
            potfile = os.path.join('python_tests', potfile)

        xcfun_label = 'b3lyp'

        #   ------------------------------------------------------------------
        #   No    A-oper    B-oper   Frequency       Real part       Imag part
        #   ------------------------------------------------------------------
        raw_data = """
             1   XDIPLEN   XDIPLEN    0.000000        9.714674        0.000000
             2   YDIPLEN   YDIPLEN    0.000000        9.121690       -0.000000
             3   ZDIPLEN   ZDIPLEN    0.000000        9.297862       -0.000000
             4   XDIPLEN   YDIPLEN    0.000000        0.269645        0.000000
             5   XDIPLEN   ZDIPLEN    0.000000        0.327164        0.000000
             6   YDIPLEN   ZDIPLEN    0.000000        0.292680       -0.000000
             7   XDIPLEN   XDIPLEN    0.050000        9.776774        0.011430
             8   YDIPLEN   YDIPLEN    0.050000        9.240618        0.022287
             9   ZDIPLEN   ZDIPLEN    0.050000        9.379095        0.015038
            10   XDIPLEN   YDIPLEN    0.050000        0.258629       -0.002117
            11   XDIPLEN   ZDIPLEN    0.050000        0.335171        0.001493
            12   YDIPLEN   ZDIPLEN    0.050000        0.295142        0.000437
            13   XDIPLEN   XDIPLEN    0.100000        9.970574        0.024287
            14   YDIPLEN   YDIPLEN    0.100000        9.640607        0.053196
            15   ZDIPLEN   ZDIPLEN    0.100000        9.638487        0.033083
            16   XDIPLEN   YDIPLEN    0.100000        0.217754       -0.005816
            17   XDIPLEN   ZDIPLEN    0.100000        0.361531        0.003442
            18   YDIPLEN   ZDIPLEN    0.100000        0.301579        0.000664
        """
        data_lines = raw_data.split(os.linesep)[1:-1]

        self.run_cpp(inpfile, potfile, xcfun_label, data_lines)


if __name__ == "__main__":
    unittest.main()
