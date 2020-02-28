import io
import sys
import textwrap
from unittest.mock import MagicMock, patch

# from mpi4py import MPI

from veloxchem.main import main
# from veloxchem.mpitask import MpiTask


def test_loprop_called_from_main(tmpdir):
    inp = textwrap.dedent(
        """
        @jobs
        task: loprop
        @end

        @method settings
        basis: cc-pvdz
        @end

        @molecule
        charge: 0
        multiplicity: 1
        units: au
        xyz:
        O   0.0   0.0   0.0
        H   0.0   1.4   1.1
        H   0.0  -1.4   1.1
        @end
        """
    )
    out = io.StringIO()

    input_file = f'{tmpdir/"water.inp"}'
    with open(input_file, 'w') as f:
        f.write(inp)

    task = MagicMock()  # MpiTask((inp, out), MPI.COMM_WORLD)
    molecule = MagicMock()  # task.molecule
    basis = MagicMock()  # task.ao_basis
    comm = MagicMock()  # task.mpi_comm
    rank = MagicMock()  # task.mpi_rank

    with patch('veloxchem.main.LoPropDriver', autospec=True) as mock_prop:
        sys.argv[1:] = [input_file]
        main()

    assert mock_prop.called
