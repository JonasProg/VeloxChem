from mpi4py import MPI
import numpy as np
import unittest
from pathlib import Path

from veloxchem.veloxchemlib import mpi_master
from veloxchem.mpitask import MpiTask
from veloxchem.cubicgrid import CubicGrid
from veloxchem.molecularorbitals import MolecularOrbitals
from veloxchem.visualizationdriver import VisualizationDriver
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.tdaexcidriver import TDAExciDriver
from veloxchem.lreigensolver import LinearResponseEigenSolver


class TestNTO(unittest.TestCase):

    def run_nto(self, inpfile, xcfun_label, ref_eig_vals, ref_nto_lambdas,
                ref_nto_cube_vals, flag):

        task = MpiTask([inpfile, None], MPI.COMM_WORLD)
        task.input_dict['scf']['checkpoint_file'] = None

        if xcfun_label is not None:
            task.input_dict['method_settings']['xcfun'] = xcfun_label

        # run SCF

        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
        scf_drv.update_settings(task.input_dict['scf'],
                                task.input_dict['method_settings'])
        scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

        # run TDA/RPA

        if flag == 'tda':
            rsp_drv = TDAExciDriver(task.mpi_comm, task.ostream)
        elif flag == 'rpa':
            rsp_drv = LinearResponseEigenSolver(task.mpi_comm, task.ostream)
        rsp_drv.update_settings({'nstates': ref_eig_vals.shape[0]},
                                task.input_dict['method_settings'])
        rsp_results = rsp_drv.compute(task.molecule, task.ao_basis,
                                      scf_drv.scf_tensors)

        nocc = task.molecule.number_of_alpha_electrons()

        # get eigenvalues and eigenvectors

        if task.mpi_rank == mpi_master():
            mo = scf_drv.scf_tensors['C']
            mo_occ = mo[:, :nocc]
            mo_vir = mo[:, nocc:]

            nocc = mo_occ.shape[1]
            nvir = mo_vir.shape[1]

            eig_vals = rsp_results['eigenvalues']
            eig_vecs = rsp_results['eigenvectors']

            nto_lambdas = []
            nto_cube_vals = []

        for s in range(ref_eig_vals.shape[0]):

            # calculate lambdas and NTOs

            if task.mpi_rank == mpi_master():
                eig_vec = eig_vecs[:, s].copy()
                if flag == 'tda':
                    t_mat = eig_vec.reshape(nocc, nvir)
                elif flag == 'rpa':
                    t_mat = eig_vec[:eig_vec.shape[0] // 2].reshape(
                        nocc, nvir) * np.sqrt(2.0)
                lam_diag, nto_mo = rsp_drv.get_nto(t_mat, mo_occ, mo_vir)
            else:
                lam_diag = None
                nto_mo = MolecularOrbitals()
            lam_diag = task.mpi_comm.bcast(lam_diag, root=mpi_master())
            nto_mo.broadcast(task.mpi_rank, task.mpi_comm)

            # check sum of lambdas for TDA

            if flag == 'tda':
                self.assertAlmostEqual(np.sum(lam_diag), 1.0, 8)

            nto_lambdas.append(lam_diag[0])

            # compute NTO on grid points

            grid = CubicGrid([-0.1, -0.1, -0.1], [0.3, 0.3, 0.2], [2, 2, 3])

            vis_drv = VisualizationDriver(task.mpi_comm)

            ind_occ = nocc - 1
            vis_drv.compute(grid, task.molecule, task.ao_basis, nto_mo, ind_occ,
                            'alpha')
            if task.mpi_rank == mpi_master():
                nto_cube_vals.append(grid.values_to_numpy().flatten())

            ind_vir = nocc
            vis_drv.compute(grid, task.molecule, task.ao_basis, nto_mo, ind_vir,
                            'alpha')
            if task.mpi_rank == mpi_master():
                nto_cube_vals.append(grid.values_to_numpy().flatten())

        # compare NTO on grid points with reference

        if task.mpi_rank == mpi_master():
            nto_lambdas = np.array(nto_lambdas)
            nto_cube_vals = np.array(nto_cube_vals)

            thresh = 1.0e-6 if xcfun_label is None else 1.0e-5
            self.assertTrue(np.max(np.abs(eig_vals - ref_eig_vals)) < thresh)

            thresh = 1.0e-4 if xcfun_label is None else 1.0e-3
            self.assertTrue(
                np.max(np.abs(nto_lambdas - ref_nto_lambdas)) < thresh)

            for s in range(nto_cube_vals.shape[0]):
                if np.vdot(nto_cube_vals[s, :], ref_nto_cube_vals[s, :]) < 0.0:
                    nto_cube_vals[s, :] *= -1.0
            self.assertTrue(
                np.max(np.abs(nto_cube_vals - ref_nto_cube_vals)) < 1.0e-4)

    def test_nto_tda(self):

        here = Path(__file__).parent
        inpfile = str(here / 'inputs' / 'c2h4.inp')

        xcfun_label = None
        nstates = 5

        raw_vals = """
            0.31643416  0.939996
            0.34674141  0.658068
            0.34866292  0.998586
            0.35831265  0.660147
            0.38623776  0.611341
        """
        vals = np.array([float(x) for x in raw_vals.split()])
        vals = vals.reshape(nstates, -1)

        eig_vals = vals[:, 0]
        nto_lambdas = vals[:, 1]

        raw_vals = """
            3.08300E-02  3.08300E-02  3.41697E-02
            3.02083E-02  3.02083E-02  3.33643E-02
           -6.04152E-02 -6.04152E-02 -6.67266E-02
           -5.92120E-02 -5.92120E-02 -6.51781E-02
            4.19373E-03 -4.19373E-03 -1.33649E-02
            4.06161E-03 -4.06161E-03 -1.29179E-02
           -8.12234E-03  8.12234E-03  2.58328E-02
           -7.87085E-03  7.87085E-03  2.49837E-02
            3.11244E-03 -3.11244E-03 -1.00451E-02
           -6.02484E-03  6.02484E-03  1.94061E-02
            3.00892E-03 -3.00892E-03 -9.69226E-03
           -5.82780E-03  5.82780E-03  1.87359E-02
            4.54510E-03 -4.54510E-03 -1.45426E-02
            4.39760E-03 -4.39760E-03 -1.40423E-02
           -8.79436E-03  8.79436E-03  2.80818E-02
           -8.51372E-03  8.51372E-03  2.71320E-02
           -3.08300E-02 -3.08300E-02 -3.41697E-02
           -3.02083E-02 -3.02083E-02 -3.33643E-02
            6.04152E-02  6.04152E-02  6.67266E-02
            5.92120E-02  5.92120E-02  6.51781E-02
           -7.71797E-03 -7.71797E-03 -1.20185E-02
           -7.34438E-03 -7.34438E-03 -1.10426E-02
           -6.58723E-03 -6.58723E-03 -1.02655E-02
           -6.27868E-03 -6.27868E-03 -9.40533E-03
           -3.08300E-02 -3.08300E-02 -3.41697E-02
           -3.02083E-02 -3.02083E-02 -3.33643E-02
            6.04152E-02  6.04152E-02  6.67266E-02
            5.92120E-02  5.92120E-02  6.51781E-02
            2.62157E-02  2.62157E-02  2.84788E-02
           -5.13050E-02 -5.13050E-02 -5.55604E-02
            2.56648E-02  2.56648E-02  2.77928E-02
           -5.02375E-02 -5.02375E-02 -5.42392E-02
           -3.39884E-01 -3.39884E-01 -3.45196E-01
           -3.31899E-01 -3.31899E-01 -3.36173E-01
           -3.32479E-01 -3.32479E-01 -3.36811E-01
           -3.24750E-01 -3.24750E-01 -3.28112E-01
            4.99796E-03 -4.99796E-03 -1.59590E-02
            4.83409E-03 -4.83409E-03 -1.54049E-02
           -9.66732E-03  9.66732E-03  3.08069E-02
           -9.35542E-03  9.35542E-03  2.97545E-02
        """
        nto_cube_vals = np.array([float(x) for x in raw_vals.split()])
        nto_cube_vals = nto_cube_vals.reshape(nstates * 2, -1)

        self.run_nto(inpfile, xcfun_label, eig_vals, nto_lambdas, nto_cube_vals,
                     'tda')

    def test_nto_rpa(self):

        here = Path(__file__).parent
        inpfile = str(here / 'inputs' / 'c2h4.inp')

        xcfun_label = 'b3lyp'
        nstates = 5

        raw_vals = """
            0.30465317  9.81738000e-01
            0.30537184  9.90163214e-01
            0.31770840  9.97655472e-01
            0.33176863  9.81756714e-01
            0.35264869  8.96190203e-01
        """
        vals = np.array([float(x) for x in raw_vals.split()])
        vals = vals.reshape(nstates, -1)

        eig_vals = vals[:, 0]
        nto_lambdas = vals[:, 1]

        raw_vals = """
            3.21430E-03 -3.21430E-03 -1.03578E-02
           -6.22010E-03  6.22010E-03  2.00043E-02
            3.10657E-03 -3.10657E-03 -9.99144E-03
           -6.01501E-03  6.01501E-03  1.93083E-02
            4.77717E-03 -4.77717E-03 -1.52606E-02
            4.62157E-03 -4.62157E-03 -1.47339E-02
           -9.24233E-03  9.24233E-03  2.94651E-02
           -8.94621E-03  8.94621E-03  2.84649E-02
            3.05252E-02  3.05252E-02  3.41449E-02
            2.99013E-02  2.99013E-02  3.33239E-02
           -5.98010E-02 -5.98010E-02 -6.66455E-02
           -5.85944E-02 -5.85944E-02 -6.50684E-02
            4.36168E-03 -4.36168E-03 -1.39084E-02
            4.22290E-03 -4.22290E-03 -1.34388E-02
           -8.44485E-03  8.44485E-03  2.68744E-02
           -8.18069E-03  8.18069E-03  2.59826E-02
            3.05252E-02  3.05252E-02  3.41449E-02
            2.99013E-02  2.99013E-02  3.33239E-02
           -5.98010E-02 -5.98010E-02 -6.66455E-02
           -5.85944E-02 -5.85944E-02 -6.50684E-02
            1.78746E-02  1.78746E-02  2.28482E-02
            1.71020E-02  1.71020E-02  2.14232E-02
            1.64037E-02  1.64037E-02  2.07118E-02
            1.57078E-02  1.57078E-02  1.94172E-02
            3.05252E-02  3.05252E-02  3.41449E-02
            2.99013E-02  2.99013E-02  3.33239E-02
           -5.98010E-02 -5.98010E-02 -6.66455E-02
           -5.85944E-02 -5.85944E-02 -6.50684E-02
           -2.38075E-02 -2.38075E-02 -2.61538E-02
            4.65993E-02  4.65993E-02  5.10177E-02
           -2.33117E-02 -2.33117E-02 -2.55212E-02
            4.56395E-02  4.56395E-02  4.98006E-02
           -3.05252E-02 -3.05252E-02 -3.41449E-02
           -2.99013E-02 -2.99013E-02 -3.33239E-02
            5.98010E-02  5.98010E-02  6.66455E-02
            5.85944E-02  5.85944E-02  6.50684E-02
            3.06410E-03 -3.06410E-03 -7.40479E-03
            3.37437E-03 -3.37437E-03 -8.51925E-03
            3.39094E-03 -3.39094E-03 -8.56887E-03
            3.67531E-03 -3.67531E-03 -9.58616E-03
        """
        nto_cube_vals = np.array([float(x) for x in raw_vals.split()])
        nto_cube_vals = nto_cube_vals.reshape(nstates * 2, -1)

        self.run_nto(inpfile, xcfun_label, eig_vals, nto_lambdas, nto_cube_vals,
                     'rpa')


if __name__ == "__main__":
    unittest.main()
