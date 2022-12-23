import numpy as np

from veloxchem.veloxchemlib import GridDriver, XCNewIntegrator
from veloxchem.veloxchemlib import is_mpi_master, mpi_master
from veloxchem.veloxchemlib import denmat
from veloxchem.molecule import Molecule
from veloxchem.molecularbasis import MolecularBasis
from veloxchem.scfrestopendriver import ScfRestrictedOpenDriver
from veloxchem.aodensitymatrix import AODensityMatrix


class TestPDFT:

    def run_RODFT(self, func, pfunc):

        O2_xyz = """
            O 0.0 0.0 -0.6
            O 0.0 0.0  0.6
        """
        molecule = Molecule.read_str(O2_xyz)
        molecule.set_multiplicity(3)
        basis = MolecularBasis.read(molecule, 'cc-pvdz', ostream=None)

        # Optimize ROHF wavefunction
        scfdrv = ScfRestrictedOpenDriver()
        scfdrv.ostream.state = False
        scfdrv.compute(molecule, basis)

        # Compute SLDA correction
        grid_drv = GridDriver()
        molgrid = grid_drv.generate(molecule)

        xc_drv = XCNewIntegrator()
        vxc_mat = xc_drv.integrate_vxc_fock(molecule, basis, scfdrv.density,
                                            molgrid, func)
        vxc_mat.reduce_sum(scfdrv.rank, scfdrv.nodes, scfdrv.comm)

        # Compute total and on-top pair densities
        if scfdrv.rank == mpi_master():
            total_density = (scfdrv.scf_tensors['D_alpha'] +
                             scfdrv.scf_tensors['D_beta'])
            den_mat = AODensityMatrix([total_density], denmat.rest)
        else:
            den_mat = AODensityMatrix()
        den_mat.broadcast(scfdrv.rank, scfdrv.comm)

        # Only in the 2 singly occupied orbitals
        Dact = np.identity(2)
        D2act = -0.5 * np.einsum('mt,np->mntp', Dact,
                                 Dact)  # True density minus "closed shell"

        if scfdrv.rank == mpi_master():
            mo_act = scfdrv.mol_orbs.alpha_to_numpy()[:, [7, 8]]
        else:
            mo_act = None
        mo_act = scfdrv.comm.bcast(mo_act, root=mpi_master())

        pdft_mat = xc_drv.integrate_vxc_pdft(den_mat, D2act, mo_act.T.copy(),
                                             molecule, basis, molgrid, pfunc)
        pdft_mat.reduce_sum(scfdrv.rank, scfdrv.nodes, scfdrv.comm)

        if scfdrv.rank == mpi_master():
            return vxc_mat.get_energy(), pdft_mat.get_energy()
        else:
            return None, None

    def test_O2_ROLDA(self):
        ksdft, pdft = self.run_RODFT('slda', 'plda')
        if is_mpi_master():
            assert abs(ksdft - pdft) < 1.0e-6

    def test_O2_ROGGA(self):
        ksdft, pdft = self.run_RODFT('pbe', 'ppbe')
        if is_mpi_master():
           assert abs(-16.88550889838203 - pdft) < 1.0e-6
