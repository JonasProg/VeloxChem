import numpy as np
import itertools

from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import LinearMomentumIntegralsDriver
from .veloxchemlib import AngularMomentumIntegralsDriver
from .veloxchemlib import AODensityMatrix
from .veloxchemlib import AOFockMatrix
from .veloxchemlib import ExcitationVector
from .veloxchemlib import mpi_master
from .veloxchemlib import denmat
from .veloxchemlib import fockmat
from .veloxchemlib import szblock
from .errorhandler import assert_msg_critical


class LinearResponseMatrixVectorDriver:
    """Implements linear response solver"""

    def __init__(self, comm):
        """Initializes linear response matrix vector driver.

        Initializes linear response matrix vector driver to default setup.

        Parameters
        ----------
        comm
            The MPI communicator.
        """

        # mpi information
        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()

    def e2n(self, vecs, tensors, screening, molecule, basis):

        if self.rank == mpi_master():
            assert_msg_critical(
                len(vecs.shape) == 2,
                'LinearResponseSolver.e2n: invalid shape of vecs')

            mo = tensors['C']
            S = tensors['S']
            da, db = tensors['D']
            fa, fb = tensors['F']

            nocc = molecule.number_of_alpha_electrons()
            norb = mo.shape[1]

            dks = []
            kns = []

            for col in range(vecs.shape[1]):
                vec = vecs[:, col]

                kN = lrvec2mat(vec, nocc, norb).T
                kn = mo @ kN @ mo.T

                dak = kn.T @ S @ da - da @ S @ kn.T
                dbk = kn.T @ S @ db - db @ S @ kn.T

                dks.append((dak, dbk))
                kns.append(kn)

            dks = tuple(dks)
        else:
            dks = None

        fks = self.get_two_el_fock(dks, screening, molecule, basis)

        if self.rank == mpi_master():
            gv = np.zeros(vecs.shape)

            for col, (kn, (fak, fbk)) in enumerate(zip(kns, fks)):

                kfa = S @ kn @ fa - fa @ kn @ S
                kfb = S @ kn @ fb - fb @ kn @ S

                fat = fak + kfa
                fbt = fbk + kfb

                gao = S @ (da @ fat.T + db @ fbt.T) - (fat.T @ da +
                                                       fbt.T @ db) @ S
                gmo = mo.T @ gao @ mo

                gv[:, col] = -lrmat2vec(gmo, nocc, norb)
            return gv
        else:
            return None

    def get_two_el_fock(self, dabs, screening, molecule, basis):

        # TODO: make this routine more general (for both rest and unrest)

        if self.rank == mpi_master():
            dts = []
            for dab in dabs:
                da, db = dab
                dt = da + db
                dts.append(dt)

                # Note: skip spin density for restricted case
                # ds = da - db
                # dts.append(ds)

            dens = AODensityMatrix(dts, denmat.rest)
        else:
            dens = AODensityMatrix()
        dens.broadcast(self.rank, self.comm)

        fock = AOFockMatrix(dens)

        # for i in range(0, 2 * len(dabs), 2):
        #    fock.set_fock_type(fockmat.rgenjk, i)
        #    fock.set_fock_type(fockmat.rgenk, i + 1)

        # Note: skip spin density for restricted case
        # for i in range(len(dabs)):
        #    fock.set_fock_type(fockmat.rgenjk, i)
        for i in range(fock.number_of_fock_matrices()):
            fock.set_fock_type(fockmat.rgenjk, i)

        eri_drv = ElectronRepulsionIntegralsDriver(self.comm)
        eri_drv.compute(fock, dens, molecule, basis, screening)
        fock.reduce_sum(self.rank, self.nodes, self.comm)

        fabs = []
        if self.rank == mpi_master():

            # for i in range(0, 2 * len(dabs), 2):
            #    ft = fock.to_numpy(i).T
            #    fs = -fock.to_numpy(i + 1).T
            #    fa = (ft + fs) / 2
            #    fb = (ft - fs) / 2
            #    fabs.append((fa, fb))

            # Note: skip spin density for restricted case
            for i in range(len(dabs)):
                ft = fock.to_numpy(i).T
                fa = ft * 0.5
                fb = ft * 0.5
                fabs.append((fa, fb))

            return tuple(fabs)
        else:
            return None

    def s2n(self, vecs, tensors, nocc):

        assert_msg_critical(
            len(vecs.shape) == 2,
            'LinearResponseSolver.s2n: invalid shape of vecs')

        mo = tensors['C']
        S = tensors['S']
        D = tensors['D'][0] + tensors['D'][1]

        norb = mo.shape[1]

        s2n_vecs = np.ndarray(vecs.shape)
        rows, columns = vecs.shape

        for c in range(columns):
            kappa = lrvec2mat(vecs[:, c], nocc, norb).T
            kappa_ao = mo @ kappa @ mo.T

            s2n_ao = kappa_ao.T @ S @ D - D @ S @ kappa_ao.T
            s2n_mo = mo.T @ S @ s2n_ao @ S @ mo
            s2n_vecs[:, c] = -lrmat2vec(s2n_mo, nocc, norb)

        return s2n_vecs


def get_rhs(operator, components, molecule, basis, scf_tensors, rank, comm):
    """Creates right-hand side of linear response equations"""

    # compute 1e integral

    assert_msg_critical(
        operator in [
            'dipole', 'linear_momentum', 'linear momentum', 'angular_momentum',
            'angular momentum'
        ], 'get_rhs: unsupported operator {}'.format(operator))

    if operator == 'dipole':
        xc, yc, zc = molecule.center_of_nuclear_charge()
        dipole_drv = ElectricDipoleIntegralsDriver(comm)
        dipole_mats = dipole_drv.compute(molecule, basis)

        if rank == mpi_master():
            integrals = (dipole_mats.x_to_numpy(), dipole_mats.y_to_numpy(),
                         dipole_mats.z_to_numpy())
        else:
            integrals = tuple()

    elif operator in ['linear_momentum', 'linear momentum']:
        linmom_drv = LinearMomentumIntegralsDriver(comm)
        linmom_mats = linmom_drv.compute(molecule, basis)

        if rank == mpi_master():
            integrals = (linmom_mats.x_to_numpy(), linmom_mats.y_to_numpy(),
                         linmom_mats.z_to_numpy())
        else:
            integrals = tuple()

    elif operator in ['angular_momentum', 'angular momentum']:
        xc, yc, zc = molecule.center_of_nuclear_charge()
        angmom_drv = AngularMomentumIntegralsDriver(comm)
        angmom_mats = angmom_drv.compute(molecule, basis)

        if rank == mpi_master():
            integrals = (angmom_mats.x_to_numpy(), angmom_mats.y_to_numpy(),
                         angmom_mats.z_to_numpy())
        else:
            integrals = tuple()

    # compute right-hand side

    if rank == mpi_master():
        indices = {'x': 0, 'y': 1, 'z': 2}
        integral_comps = [integrals[indices[p]] for p in components]

        mo = scf_tensors['C']
        S = scf_tensors['S']
        D = scf_tensors['D'][0] + scf_tensors['D'][1]

        nocc = molecule.number_of_alpha_electrons()
        norb = mo.shape[1]

        matrices = tuple(
            mo.T @ (S @ D @ P.T - P.T @ D @ S) @ mo for P in integral_comps)

        gradients = tuple(lrmat2vec(m, nocc, norb) for m in matrices)
        return gradients

    else:
        return tuple()


def lrvec2mat(vec, nocc, norb):

    zlen = len(vec) // 2
    z, y = vec[:zlen], vec[zlen:]

    xv = ExcitationVector(szblock.aa, 0, nocc, nocc, norb, True)
    xv.set_yzcoefficients(z, y)

    kz = xv.get_zmatrix()
    ky = xv.get_ymatrix()

    rows = kz.number_of_rows() + ky.number_of_rows()
    cols = kz.number_of_columns() + ky.number_of_columns()

    kzy = np.zeros((rows, cols))
    kzy[:kz.number_of_rows(), ky.number_of_columns():] = kz.to_numpy()
    kzy[kz.number_of_rows():, :ky.number_of_columns()] = ky.to_numpy()

    return kzy


def lrmat2vec(mat, nocc, norb):

    xv = ExcitationVector(szblock.aa, 0, nocc, nocc, norb, True)
    excitations = list(
        itertools.product(xv.bra_unique_indexes(), xv.ket_unique_indexes()))

    z = [mat[i, j] for i, j in excitations]
    y = [mat[j, i] for i, j in excitations]
    return np.array(z + y)


def truncate_and_normalize(basis, small_threshold):

    Sb = np.matmul(basis.T, basis)
    l, T = np.linalg.eigh(Sb)
    b_norm = np.sqrt(Sb.diagonal())
    mask = l > b_norm * small_threshold
    truncated = np.matmul(basis, T[:, mask])

    Sb = np.matmul(truncated.T, truncated)
    l, T = np.linalg.eigh(Sb)
    inverse_sqrt = np.matmul(T * np.sqrt(1.0 / l), T.T)
    return np.matmul(truncated, inverse_sqrt)


def construct_ed_sd(orb_ene, nocc, norb):
    """Returns the E0 and S0 diagonal elements as arrays.
    """

    xv = ExcitationVector(szblock.aa, 0, nocc, nocc, norb, True)
    excitations = list(
        itertools.product(xv.bra_unique_indexes(), xv.ket_unique_indexes()))

    z = [2.0 * (orb_ene[j] - orb_ene[i]) for i, j in excitations]
    ediag = np.array(z + z)

    lz = len(excitations)
    sdiag = 2.0 * np.ones(2 * lz)
    sdiag[lz:] = -2.0

    return ediag, sdiag


def swap_xy(xy):
    """Swaps X and Y parts of response vector"""

    assert_msg_critical(
        len(xy.shape) == 1 or len(xy.shape) == 2,
        'LinearResponseSolver.swap: invalid shape of XY')

    half_rows = xy.shape[0] // 2
    yx = xy.copy()

    if len(xy.shape) == 1:
        yx[:half_rows] = xy[half_rows:]
        yx[half_rows:] = xy[:half_rows]

    elif len(xy.shape) == 2:
        yx[:half_rows, :] = xy[half_rows:, :]
        yx[half_rows:, :] = xy[:half_rows, :]

    return yx
