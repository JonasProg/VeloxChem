from mpi4py import MPI
import sys

from .veloxchemlib import mpi_initialized
from .veloxchemlib import mpi_master
from .mpitask import MpiTask
from .scfrestdriver import ScfRestrictedDriver
from .rspdriver import ResponseDriver
from .rsppolarizability import Polarizability
from .rspabsorption import Absorption
from .mp2driver import Mp2Driver
from .visualizationdriver import VisualizationDriver
from .molecularorbitals import MolecularOrbitals
from .errorhandler import assert_msg_critical


def main():

    assert_msg_critical(mpi_initialized(), "MPI: Initialized")

    # set up MPI task

    task = MpiTask(sys.argv[1:], MPI.COMM_WORLD)

    task_type = task.input_dict['jobs']['task'].lower()

    # Hartree-Fock

    if task_type in ['hf', 'mp2', 'cube', 'response']:

        # initialize scf driver and run scf

        if 'scf' in task.input_dict:
            scf_dict = task.input_dict['scf']
        else:
            scf_dict = None

        scf_drv = ScfRestrictedDriver(scf_dict)
        scf_drv.compute_task(task)

        # molecular orbitals

        if task.mpi_rank == mpi_master():
            mol_orbs = scf_drv.mol_orbs
        else:
            mol_orbs = MolecularOrbitals()

    # Response

    if task_type == 'response':

        if 'response' in task.input_dict:

            rsp_dict = task.input_dict['response']

            if rsp_dict['property'].lower() == 'polarizability':
                polar = Polarizability(rsp_dict)
                polar.compute_task(mol_orbs, task)
                if task.mpi_rank == mpi_master():
                    polar.print_property(task.ostream)

            elif rsp_dict['property'].lower() == 'absorption':
                abs_spec = Absorption(rsp_dict)
                abs_spec.compute_task(mol_orbs, task)
                if task.mpi_rank == mpi_master():
                    abs_spec.print_property(task.ostream)

            else:
                if task.mpi_rank == mpi_master():
                    assert_msg_critical(False, 'response: invalid property')

        else:
            rsp_drv = ResponseDriver({'property': 'absorption'})
            rsp_drv.compute_task(mol_orbs, task)

    # MP2 perturbation theory

    if task_type == 'mp2':

        mp2_drv = Mp2Driver(task.mpi_comm, task.ostream)
        mp2_drv.compute(task.molecule, task.ao_basis, mol_orbs)

    # Cube

    if task_type == 'cube':

        # generate cube file

        if task.mpi_rank == mpi_master():
            vis_drv = VisualizationDriver()

            mol_orbs = scf_drv.mol_orbs
            density = scf_drv.density

            nelec = task.molecule.number_of_electrons()
            homo = nelec // 2 - 1

            cubic_grid = vis_drv.gen_cubic_grid(task.molecule)
            vis_drv.write_cube('homo.cube', cubic_grid, task.molecule,
                               task.ao_basis, mol_orbs, homo, "alpha")
            vis_drv.write_cube('density.cube', cubic_grid, task.molecule,
                               task.ao_basis, density, 0, "alpha")

    # all done, print finish header to output stream

    task.finish()
