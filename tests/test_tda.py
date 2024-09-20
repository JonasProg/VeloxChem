import numpy as np

from veloxchem import Molecule
from veloxchem import MolecularBasis
from veloxchem import ScfRestrictedDriver
from veloxchem import TdaEigenSolver


class TestTDA:

    def run_tda(self, xcfun_label, ref_exc_enes, ref_osc_str, tol):

        xyz_string = """3
        xyz
        O   -0.1858140  -1.1749469   0.7662596
        H   -0.1285513  -0.8984365   1.6808606
        H   -0.0582782  -0.3702550   0.2638279
        """
        mol = Molecule.read_xyz_string(xyz_string)
        mol.check_multiplicity()

        basis_label = 'def2-svp'
        bas = MolecularBasis.read(mol, basis_label, ostream=None)

        scf_drv = ScfRestrictedDriver()
        scf_drv.ostream.mute()
        scf_drv.xcfun = xcfun_label
        scf_results = scf_drv.compute(mol, bas)

        lr_drv = TdaEigenSolver()
        lr_drv.ostream.mute()
        lr_drv.nstates = 5
        lr_results = lr_drv.compute(mol, bas, scf_results)

        assert np.max(np.abs(ref_exc_enes - lr_results['eigenvalues'])) < tol
        assert np.max(np.abs(ref_osc_str -
                             lr_results['oscillator_strengths'])) < 1.0e-4

    def test_hf(self):

        ref_exc_enes = np.array(
            [0.34189725, 0.40717708, 0.43577895, 0.50150019, 0.55485041])

        ref_osc_str = np.array([0.0229, 0.0000, 0.1039, 0.0975, 0.3060])

        self.run_tda('hf', ref_exc_enes, ref_osc_str, 1.0e-6)

    def test_b3lyp(self):

        ref_exc_enes = np.array(
            [0.28045483, 0.35053288, 0.36504833, 0.43904962, 0.51570229])

        ref_osc_str = np.array([0.0180, 0.0000, 0.0854, 0.0695, 0.3006])

        self.run_tda('b3lyp', ref_exc_enes, ref_osc_str, 1.0e-5)
