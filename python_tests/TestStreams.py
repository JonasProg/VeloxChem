from mpi4py import MPI
from VeloxChemMP import *
from HelperClass import *

import numpy as np
import unittest

class TestStreams(unittest.TestCase):

    def test_get_state(self):

        ostream = OutputStream("")
        istream = InputStream("inputs/water.inp", ostream)

        self.assertTrue(istream.get_state())
        self.assertTrue(ostream.get_state())

if __name__ == "__main__":
    unittest.main()
