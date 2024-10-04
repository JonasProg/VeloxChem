from mpi4py import MPI
from pathlib import Path

from veloxchem.veloxchemlib import mpi_master
from veloxchem.cubicgrid import CubicGrid
from veloxchem.inputparser import get_random_string_serial


class TestCheckpoint:

    def write_cube(self, fname):

        text = """
            test mo=9
            MO coefficients
              -6   -0.100000   -0.100000   -0.100000    1
               2    0.300000    0.000000    0.000000
               2    0.000000    0.300000    0.000000
               3    0.000000    0.000000    0.200000
               6    6.000000    0.000000    0.000000   -1.243600
               6    6.000000    0.000000    0.000000    1.243600
               1    1.000000    0.000000    1.727200   -2.323000
               1    1.000000    0.000000   -1.727200   -2.323000
               1    1.000000    0.000000    1.727200    2.323000
               1    1.000000    0.000000   -1.727200    2.323000
               1    9
             4.77717E-03 -4.77717E-03 -1.52606E-02
             4.62157E-03 -4.62157E-03 -1.47339E-02
            -9.24233E-03  9.24233E-03  2.94651E-02
            -8.94621E-03  8.94621E-03  2.84649E-02
        """

        with open(fname, 'w') as f_cube:
            for line in text.splitlines():
                if line.strip():
                    print(line.lstrip(), file=f_cube)

    def test_cube(self):

        if MPI.COMM_WORLD.Get_rank() == mpi_master():
            here = Path(__file__).parent
            random_string = get_random_string_serial()
            fpath = here / 'data' / f'vlx_cube_test_{random_string}.cube'
            fname = str(fpath)

            self.write_cube(fname)

            grid_1 = CubicGrid.read_cube(fname)
            grid_2 = CubicGrid.read_cube(fname)
            diff = grid_1.compare(grid_2)
            assert diff < 1.0e-12

            if fpath.is_file():
                fpath.unlink()
