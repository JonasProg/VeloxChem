from pathlib import Path
import numpy as np
import pytest
import sys

try:
    import openmm
except ImportError:
    pass

from veloxchem.veloxchemlib import is_mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.forcefieldgenerator import ForceFieldGenerator


@pytest.mark.filterwarnings(
    'ignore:.*tostring.*tobytes:DeprecationWarning:geometric')
class TestForceField:

    def get_gaff_file(self, gaff_path, gaff_name):

        from urllib.request import urlopen

        gaff_url = ('https://raw.githubusercontent.com/openmm/' +
                    'openmmforcefields/master/amber/gaff/dat/' + gaff_name)

        with urlopen(gaff_url) as f_gaff:
            content = f_gaff.read().decode('utf-8')

        with Path(gaff_path, gaff_name).open('w') as f_gaff:
            f_gaff.write(content)

    @pytest.mark.skipif('openmm' not in sys.modules,
                        reason='openmm not available')
    def test_force_field(self):

        here = Path(__file__).parent
        inpfile = str(here / 'inputs' / 'butane.inp')

        task = MpiTask([inpfile])

        if is_mpi_master(task.mpi_comm):
            gaff_file = here / 'inputs' / 'gaff-2.11.dat'
            if not gaff_file.is_file():
                self.get_gaff_file(gaff_file.parent, gaff_file.name)
        task.mpi_comm.barrier()

        ff_dict = (task.input_dict['force_field']
                   if 'force_field' in task.input_dict else {})
        resp_dict = (task.input_dict['resp_charges']
                     if 'resp_charges' in task.input_dict else {})

        ff_dict['filename'] = task.input_dict['filename']
        resp_dict['filename'] = task.input_dict['filename']

        ff_drv = ForceFieldGenerator(task.mpi_comm, task.ostream)
        ff_drv.update_settings(ff_dict, resp_dict)
        ff_drv.compute(task.molecule, task.ao_basis)

        if is_mpi_master(task.mpi_comm):
            ref_atom_inds = [1, 5, 8, 11]
            ref_funct_type = 3
            ref_parameters = np.array(
                [4.82579, 10.74424, 0.17548, -15.10881, 1.85225, -2.59463])

            new_itp_file = here / 'inputs' / 'butane_files' / 'butane_01.itp'
            with new_itp_file.open('r') as f_itp:
                itp_lines = f_itp.readlines()

            last_line_content = itp_lines[-1].split()
            dih_atom_inds = [int(x) for x in last_line_content[:4]]
            dih_funct_type = int(last_line_content[4])
            dih_parameters = np.array(
                [float(x) for x in last_line_content[5:11]])

            assert dih_atom_inds == ref_atom_inds
            assert dih_funct_type == ref_funct_type
            assert np.max(np.abs(dih_parameters - ref_parameters)) < 1.0e-3

            if gaff_file.is_file():
                gaff_file.unlink()

            pdb_file = Path(inpfile).with_suffix('.pdb')
            if pdb_file.is_file():
                pdb_file.unlink()

            scf_h5_file = Path(inpfile).with_suffix('.scf.h5')
            if scf_h5_file.is_file():
                scf_h5_file.unlink()

            scf_final_h5_file = Path(inpfile).with_suffix('.scf.tensors.h5')
            if scf_final_h5_file.is_file():
                scf_final_h5_file.unlink()
