from mpi4py import MPI
import sys

from .veloxchemlib import mpi_initialized
from .veloxchemlib import mpi_master

from .mpitask import MpiTask
from .scfrestdriver import ScfRestrictedDriver
from .rspdriver import ResponseDriver
from .mointsdriver import MOIntegralsDriver
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

        scf_drv = ScfRestrictedDriver()

        scf_drv.compute_task(task)

    # Response

    if task_type == 'response':

        # molecular orbitals

        if task.mpi_rank == mpi_master():
            mol_orbs = scf_drv.mol_orbs
        else:
            mol_orbs = MolecularOrbitals()

        rsp_drv = ResponseDriver()

        rsp_drv.compute_task(mol_orbs, task)

    # MP2 perturbation theory

    if task_type == 'mp2':

        # molecular orbitals

        if task.mpi_rank == mpi_master():
            mol_orbs = scf_drv.mol_orbs
        else:
            mol_orbs = MolecularOrbitals()

        # MO integrals

        moints_drv = MOIntegralsDriver()
        oovv = moints_drv.compute_task(task, mol_orbs, "OOVV")

        # MP2 energy

        nocc = task.molecule.number_of_alpha_electrons()
        e_mp2 = moints_drv.compute_mp2_energy(mol_orbs, nocc, oovv)

        if task.mpi_rank == mpi_master():
            mp2_str = "*** MP2 correlation energy: %20.12f a.u." % e_mp2
            task.ostream.print_header(mp2_str.ljust(92))
            task.ostream.print_blank()

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
