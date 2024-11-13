import numpy as np
import pytest

from veloxchem.veloxchemlib import FockGeom1000Driver, T4CScreener
from veloxchem.veloxchemlib import partition_atoms, make_matrix
from veloxchem.veloxchemlib import mpi_master, mat_t
from veloxchem.molecule import Molecule
from veloxchem.molecularbasis import MolecularBasis
from veloxchem.scfrestdriver import ScfRestrictedDriver
from veloxchem.fockdriver import FockDriver


@pytest.mark.solvers
class TestNumericalGradient:

    def run_numgrad(self, mol, bas_label):

        bas = MolecularBasis.read(mol, bas_label)

        scf_drv = ScfRestrictedDriver()
        scf_drv.ostream.mute()
        scf_results = scf_drv.compute(mol, bas)

        if scf_drv.rank == mpi_master():
            D = scf_results['D_alpha']
            mo = scf_results['C_alpha']
            nocc = mol.number_of_alpha_electrons()
            nvir = mo.shape[1] - nocc

            mo_occ = mo[:, :nocc].copy()
            mo_vir = mo[:, nocc:].copy()

            tmat = np.zeros((nocc, nvir))
            tmat[nocc - 1, 0] = 1.0
            tmat = np.linalg.multi_dot([mo_occ, tmat, mo_vir.T])

            tmat2 = np.zeros((nocc, nvir))
            tmat2[nocc - 2, 0] = 1.0
            tmat2 = np.linalg.multi_dot([mo_occ, tmat2, mo_vir.T])
        else:
            D = None
            tmat = None
            tmat2 = None

        D = scf_drv.comm.bcast(D, root=mpi_master())
        tmat = scf_drv.comm.bcast(tmat, root=mpi_master())
        tmat2 = scf_drv.comm.bcast(tmat2, root=mpi_master())

        natoms = mol.number_of_atoms()
        local_atoms = partition_atoms(natoms, scf_drv.rank, scf_drv.nodes)

        fock_grad_drv = FockGeom1000Driver()

        screening = T4CScreener()
        screening.partition(bas, mol, 'eri')

        fock_drv = FockDriver()

        exchange_scaling_factor = 0.2
        thresh_int = 12

        for density, fock_type in zip([tmat, tmat2],
                                      ['2jk', '2jkx', 'j', 'k', 'kx']):

            den_mat = make_matrix(bas, mat_t.general)
            den_mat.set_values(density)

            local_anagrad = {}

            for iatom in local_atoms:
                atom_screening = T4CScreener()
                atom_screening.partition_atom(bas, mol, 'eri', iatom)

                gmats = fock_grad_drv.compute(bas, atom_screening, screening,
                                              den_mat, iatom, fock_type,
                                              exchange_scaling_factor, 0.0,
                                              thresh_int)

                for c, label in enumerate(['X', 'Y', 'Z']):
                    gmat = gmats.matrix(label).to_numpy()
                    local_anagrad[(iatom, label.lower())] = gmat

            local_anagrads = scf_drv.comm.gather(local_anagrad,
                                                 root=mpi_master())

            if scf_drv.rank == mpi_master():
                anagrad = {}
                for local_anagrad in local_anagrads:
                    anagrad.update(local_anagrad)

            labels = mol.get_labels()
            coords = mol.get_coordinates_in_bohr()
            charge = mol.get_charge()
            multiplicity = mol.get_multiplicity()

            delta_h = 0.0005

            for i in range(mol.number_of_atoms()):
                for d in range(3):
                    coords[i, d] += delta_h
                    new_mol = Molecule(labels, coords, 'au')
                    new_mol.set_charge(charge)
                    new_mol.set_multiplicity(multiplicity)

                    new_bas = MolecularBasis.read(new_mol,
                                                  bas_label,
                                                  ostream=None)
                    new_screening = T4CScreener()
                    new_screening.partition(new_bas, new_mol, 'eri')
                    fock_mat = fock_drv.compute(new_screening, den_mat,
                                                fock_type,
                                                exchange_scaling_factor, 0.0,
                                                thresh_int)
                    f_plus = fock_mat.to_numpy()
                    f_plus = scf_drv.comm.reduce(f_plus, root=mpi_master())

                    coords[i, d] -= 2.0 * delta_h
                    new_mol = Molecule(labels, coords, 'au')
                    new_mol.set_charge(charge)
                    new_mol.set_multiplicity(multiplicity)

                    new_bas = MolecularBasis.read(new_mol,
                                                  bas_label,
                                                  ostream=None)
                    new_screening = T4CScreener()
                    new_screening.partition(new_bas, new_mol, 'eri')
                    fock_mat = fock_drv.compute(new_screening, den_mat,
                                                fock_type,
                                                exchange_scaling_factor, 0.0,
                                                thresh_int)
                    f_minus = fock_mat.to_numpy()
                    f_minus = scf_drv.comm.reduce(f_minus, root=mpi_master())

                    coords[i, d] += delta_h

                    if scf_drv.rank == mpi_master():
                        anagrad_i_d = anagrad[(i, 'xyz'[d])]
                        numgrad_i_d = (f_plus - f_minus) / (2.0 * delta_h)

                        assert np.max(np.abs(anagrad_i_d -
                                             numgrad_i_d)) < 1.0e-7

    def test_nh3_svp(self):

        molstr = """
        N         -1.96309        1.59755       -0.01963
        H         -1.95876        2.61528        0.03109
        H         -2.48929        1.27814        0.79244
        H         -2.52930        1.35928       -0.83265
        """
        mol = Molecule.read_molecule_string(molstr, units='bohr')

        self.run_numgrad(mol, 'def2-svp')
