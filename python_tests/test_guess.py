from pathlib import Path
import numpy as np
import unittest

from veloxchem.veloxchemlib import OverlapIntegralsDriver
from veloxchem.veloxchemlib import SADGuessDriver
from veloxchem.veloxchemlib import is_mpi_master
from veloxchem.mpitask import MpiTask


class TestInitialGuess(unittest.TestCase):

    def test_sad_guess(self):

        here = Path(__file__).parent
        inpfile = here / 'inputs' / 'water.inp'
        outfile = inpfile.with_suffix('.out')

        task = MpiTask([str(inpfile), str(outfile)])

        molecule = task.molecule
        ao_basis = task.ao_basis
        min_basis = task.min_basis

        # compute overlap

        ovldrv = OverlapIntegralsDriver(task.mpi_comm)
        S12 = ovldrv.compute(molecule, min_basis, ao_basis)
        S22 = ovldrv.compute(molecule, ao_basis)

        # compute initial guess

        saddrv = SADGuessDriver(task.mpi_comm)
        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, True)

        # matrix to numpy

        overlap = S22.to_numpy()
        density = D.alpha_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(density.ndim, 2)
            self.assertEqual(density.shape[0], 41)
            self.assertEqual(density.shape[1], 41)

            # number of electrons

            self.assertEqual(molecule.number_of_electrons(), 10)
            self.assertEqual(molecule.number_of_alpha_electrons(), 5)
            self.assertEqual(molecule.number_of_beta_electrons(), 5)

            self.assertAlmostEqual(2.0 * np.sum(density * overlap), 10., 13)

        # compute other initial guess

        charge = molecule.get_charge()
        multiplicity = molecule.get_multiplicity()

        # closed-shell cation initial guess

        molecule.set_charge(charge + 2)
        molecule.set_multiplicity(multiplicity)

        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, True)

        density_a = D.alpha_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(molecule.number_of_electrons(), 8)
            self.assertEqual(molecule.number_of_alpha_electrons(), 4)
            self.assertEqual(molecule.number_of_beta_electrons(), 4)

            self.assertAlmostEqual(np.sum(density_a * overlap), 4., 13)

        # closed-shell anion initial guess

        molecule.set_charge(charge - 2)
        molecule.set_multiplicity(multiplicity)

        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, True)

        density_a = D.alpha_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(molecule.number_of_electrons(), 12)
            self.assertEqual(molecule.number_of_alpha_electrons(), 6)
            self.assertEqual(molecule.number_of_beta_electrons(), 6)

            self.assertAlmostEqual(np.sum(density_a * overlap), 6., 13)

        # open-shell cation initial guess

        molecule.set_charge(charge + 1)
        molecule.set_multiplicity(multiplicity + 1)

        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, False)

        density_a = D.alpha_to_numpy(0)
        density_b = D.beta_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(molecule.number_of_electrons(), 9)
            self.assertEqual(molecule.number_of_alpha_electrons(), 5)
            self.assertEqual(molecule.number_of_beta_electrons(), 4)

            self.assertAlmostEqual(np.sum(density_a * overlap), 5., 13)
            self.assertAlmostEqual(np.sum(density_b * overlap), 4., 13)

        # open-shell anion initial guess

        molecule.set_charge(charge - 1)
        molecule.set_multiplicity(multiplicity + 1)

        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, False)

        density_a = D.alpha_to_numpy(0)
        density_b = D.beta_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(molecule.number_of_electrons(), 11)
            self.assertEqual(molecule.number_of_alpha_electrons(), 6)
            self.assertEqual(molecule.number_of_beta_electrons(), 5)

            self.assertAlmostEqual(np.sum(density_a * overlap), 6., 13)
            self.assertAlmostEqual(np.sum(density_b * overlap), 5., 13)

        # open-shell triplet initial guess

        molecule.set_charge(charge)
        molecule.set_multiplicity(multiplicity + 2)

        D = saddrv.compute(molecule, min_basis, ao_basis, S12, S22, False)

        density_a = D.alpha_to_numpy(0)
        density_b = D.beta_to_numpy(0)

        if is_mpi_master(task.mpi_comm):

            self.assertEqual(molecule.number_of_electrons(), 10)
            self.assertEqual(molecule.number_of_alpha_electrons(), 6)
            self.assertEqual(molecule.number_of_beta_electrons(), 4)

            self.assertAlmostEqual(np.sum(density_a * overlap), 6., 13)
            self.assertAlmostEqual(np.sum(density_b * overlap), 4., 13)


if __name__ == "__main__":
    unittest.main()
