#
#                           VELOXCHEM 1.0-RC2
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
#  Contact: https://veloxchem.org/contact
#
#  SPDX-License-Identifier: LGPL-3.0-or-later
#
#  This file is part of VeloxChem.
#
#  VeloxChem is free software: you can redistribute it and/or modify it under
#  the terms of the GNU Lesser General Public License as published by the Free
#  Software Foundation, either version 3 of the License, or (at your option)
#  any later version.
#
#  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
#  License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

from mpi4py import MPI
import numpy as np
import sys
import os
from collections import Counter

from .lrsolver import LinearResponseSolver
from .inputparser import InputParser
from .outputstream import OutputStream
from .veloxchemlib import get_basis_function_indices_for_atom
from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import mpi_master
from .veloxchemlib import bohr_in_angstroms
from .errorhandler import assert_msg_critical


class LoPropDriver:
    """
    Implements the LoProp driver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.
    """

    def __init__(self, comm=None, ostream=None):
        """
        Initializes the LoProp driver.
        """

        if comm is None:
            comm = MPI.COMM_WORLD
        if ostream is None:
            ostream = OutputStream(sys.stdout)

        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()
        self.ostream = ostream

    def compute(self, molecule, basis, scf_tensors):
        """
        calculate the loprop transformation matrix T
        patial charge (Qab) and localized polarizabilities

        :param molecule:
            the molecule
        :param basis:
            the bais functions
        :param scf_tensors:
            The tensors from the converged SCF calculation.

        :return:
            A dictionary containing localized charges and localized
            polarizabilities.
        """

        natoms = molecule.number_of_atoms()

        if self.rank == mpi_master():

            S = scf_tensors['S']
            C = scf_tensors['C_alpha']
            D = scf_tensors['D_alpha'] + scf_tensors['D_beta']

            # number of orbitals
            n_ao = C.shape[0]
            n_mo = C.shape[1]

            # re-arrange AOs according to principal quantum number
            re_arranged_indices = []
            for i in range(molecule.number_of_atoms()):
                indices, angmoms = get_basis_function_indices_for_atom(
                    molecule, basis, i)
                re_arranged_indices.append(indices)
            re_arranged_indices = np.concatenate(re_arranged_indices)

            # obtain occupied & virtual orbital lists
            ao_per_atom, ao_occ, ao_vir = self.get_ao_indices(molecule, basis)

            # TO transforation: re-arrange S
            S0 = S[re_arranged_indices, :][:, re_arranged_indices]

            # T1 transformation: Gram-Schmidt
            T1 = np.zeros((n_ao, n_ao))
            ri = 0
            for a in range(natoms):
                rf = ri + ao_per_atom[a]
                smat = S0[ri:rf, ri:rf]
                L = np.linalg.cholesky(smat)
                tmat = np.linalg.inv(L.T)
                T1[ri:rf, ri:rf] = tmat
                ri += ao_per_atom[a]
            S1 = np.linalg.multi_dot([T1.T, S0, T1])

            # T2 transformation: Lodwin occupied and virtual
            T2 = np.zeros((n_ao, n_ao))
            n_occ_ao = len(ao_occ)
            n_vir_ao = len(ao_vir)
            # occupied
            smat = S1[ao_occ, :][:, ao_occ]
            tmat = self.lowdin_orthonormalize(smat)
            for r in range(n_occ_ao):
                for c in range(n_occ_ao):
                    T2[ao_occ[r], ao_occ[c]] = tmat[r, c]
            # virtural
            smat = S1[ao_vir, :][:, ao_vir]
            tmat = self.lowdin_orthonormalize(smat)
            for r in range(n_vir_ao):
                for c in range(n_vir_ao):
                    T2[ao_vir[r], ao_vir[c]] = tmat[r, c]
            S2 = np.linalg.multi_dot([T2.T, S1, T2])

            # T3: projection to virtual
            T3 = np.identity(n_ao)
            # selected the overlap between occupied and virtual
            T3_ov = S2[ao_occ, :][:, ao_vir]
            # projection
            for ao_o_ind, ao_o in enumerate(ao_occ):
                for ao_v_ind, ao_v in enumerate(ao_vir):
                    T3[ao_o, ao_v] = -T3_ov[ao_o_ind, ao_v_ind]
            S3 = np.linalg.multi_dot([T3.T, S2, T3])

            # T4: lodwin virtural
            T4_virtual = S3[ao_vir, :][:, ao_vir]
            T4_virtual = self.lowdin_orthonormalize(T4_virtual)
            T4 = np.identity(n_ao)
            for ao_v_ind, ao_v in enumerate(ao_vir):
                for ao_v_1_ind, ao_v_1 in enumerate(ao_vir):
                    T4[ao_v, ao_v_1] = T4_virtual[ao_v_ind, ao_v_1_ind]

            # total transformation T becomes:
            T = np.linalg.multi_dot([T1, T2, T3, T4])

            # obtain density matrix D in loprop basis set
            T_inv = np.linalg.pinv(T)
            D = D[re_arranged_indices, :][:, re_arranged_indices]
            D_loprop = np.linalg.multi_dot([T_inv, D, T_inv.T])

            # calculated localized charges
            Qab = np.zeros((natoms, natoms))
            start_point = 0
            for atom in range(natoms):
                select = np.arange(start_point, start_point + ao_per_atom[atom])
                Qab[atom, atom] = -np.trace(D_loprop[select, :][:, select])
                start_point += ao_per_atom[atom]

            # nuclear charge
            nuclear_charge = molecule.elem_ids_to_numpy()
            for a in range(natoms):
                Qab[a, a] += nuclear_charge[a]

        # solve linear response
        lrs_drv = LinearResponseSolver(self.comm, self.ostream)
        lrs_out = lrs_drv.compute(molecule, basis, scf_tensors)

        if self.rank == mpi_master():

            # obtain response vectors
            Nx = lrs_out['solutions'][('x', 0)]
            Ny = lrs_out['solutions'][('y', 0)]
            Nz = lrs_out['solutions'][('z', 0)]

            # unpact response vectors to matrix form
            nocc = molecule.number_of_alpha_electrons()
            norb = n_mo
            kappa_x = self.lrmat(Nx, nocc, norb)
            kappa_y = self.lrmat(Ny, nocc, norb)
            kappa_z = self.lrmat(Nz, nocc, norb)

            # perturbed densities
            # factor of 2 from spin-adapted excitation vectors
            Dx = 2.0 * np.linalg.multi_dot([C, kappa_x, C.T])
            Dy = 2.0 * np.linalg.multi_dot([C, kappa_y, C.T])
            Dz = 2.0 * np.linalg.multi_dot([C, kappa_z, C.T])

            # convert purterbed density to loprop basis
            Dx = Dx[re_arranged_indices, :][:, re_arranged_indices]
            Dy = Dy[re_arranged_indices, :][:, re_arranged_indices]
            Dz = Dz[re_arranged_indices, :][:, re_arranged_indices]
            Dx_loprop = np.linalg.multi_dot([T_inv, Dx, T_inv.T])
            Dy_loprop = np.linalg.multi_dot([T_inv, Dy, T_inv.T])
            Dz_loprop = np.linalg.multi_dot([T_inv, Dz, T_inv.T])
            Dk_loprop = np.concatenate(([Dx_loprop], [Dy_loprop], [Dz_loprop]))

        # dipole
        dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
        dipole_mats = dipole_drv.compute(molecule, basis)

        if self.rank == mpi_master():

            x_ao = dipole_mats.x_to_numpy()
            y_ao = dipole_mats.y_to_numpy()
            z_ao = dipole_mats.z_to_numpy()

            # convert to loprop basis
            x_ao = x_ao[re_arranged_indices, :][:, re_arranged_indices]
            y_ao = y_ao[re_arranged_indices, :][:, re_arranged_indices]
            z_ao = z_ao[re_arranged_indices, :][:, re_arranged_indices]
            x_ao_loprop = np.linalg.multi_dot([T.T, x_ao, T])
            y_ao_loprop = np.linalg.multi_dot([T.T, y_ao, T])
            z_ao_loprop = np.linalg.multi_dot([T.T, z_ao, T])
            dipole = np.concatenate(
                ([x_ao_loprop], [y_ao_loprop], [z_ao_loprop]))

            # localized polarizabilities:
            #
            #    aAB = -rAB delta DAB + dQab (Ra-Rb)
            #
            #    where dQab is obtained by solving the following Lagragian with
            #    minimal charge transfer, here a penaty function is also introduced
            #
            #    contribution from localized dipoles: rAB*delta DAB = Aab
            #    bond contribution:  dQab (Ra-Rb)

            # dQa:charge shift per atom
            dQa = np.zeros((natoms, 3))
            # dQa array as [[Ax,Ay,Az],[Bx,By,Bz]]
            it = 0
            for a in range(natoms):
                select = np.arange(it, it + ao_per_atom[a])
                dQa[a][0] = np.trace(Dx_loprop[select, :][:, select])
                dQa[a][1] = np.trace(Dy_loprop[select, :][:, select])
                dQa[a][2] = np.trace(Dz_loprop[select, :][:, select])
                it += ao_per_atom[a]

            # coord_matrix, the rab matrix in equation above
            molecule_coord = molecule.get_coordinates()
            coord_matrix = np.zeros((natoms, natoms, 3))
            for i in range(natoms):
                # a==b: rab=ra
                coord_matrix[i][i] = molecule_coord[i]
                for j in range(i + 1, natoms):
                    # a!=b: rab = (ra-rb)/2
                    # TODO: double check absolute value
                    #checked
                    rij = 0.5 * np.abs(molecule_coord[i] - molecule_coord[j])
                    coord_matrix[i][j] = rij
                    coord_matrix[j][i] = rij

            # contribution from localized dipole
            loc_dipole = np.zeros((3, 3, natoms, natoms))
            for i in range(3):
                for j in range(3):
                    it_a = 0
                    for a in range(natoms):
                        select_a = np.arange(it_a, it_a + ao_per_atom[a])
                        it_b = 0
                        for b in range(natoms):
                            # select the subblock[a][b] region in dks_lp
                            select_b = np.arange(it_b, it_b + ao_per_atom[b])
                            # selected the lp basis for subblock[A][B] in purterbed
                            # density matrix
                            D_AB = Dk_loprop[i][select_a, :][:, select_b]
                            # selected the dipole matrice for subblock[A][B] in
                            # purterbed density matrix
                            dipole_select = dipole[j][select_a, :][:, select_b]
                            dipole_select = dipole_select.transpose()

                            loc_dipole[i, j, a, b] += np.trace(
                                np.matmul(dipole_select, D_AB))
                            it_b += ao_per_atom[b]

                        loc_dipole[i, j, a,
                                   a] -= dQa[a, j] * coord_matrix[a, a, i]
                        it_a += ao_per_atom[a]

            # Lagragian
            Fab = np.zeros((natoms, natoms))
            for a in range(natoms):
                za = nuclear_charge[a]
                Ra = molecule_coord[a]
                for b in range(a):
                    zb = nuclear_charge[b]
                    Rb = molecule_coord[b]
                    Fab[a, b] = self.penalty_fc(za, Ra, zb, Rb)
                    Fab[b, a] = Fab[a][b]
                for a in range(natoms):
                    Fab[a, a] += -sum(Fab[a, :])

            Lab = Fab + 2.0 * np.max(np.abs(Fab))

            dQa = dQa.swapaxes(0, 1)
            lagragian = [np.linalg.solve(Lab, rhs) for rhs in dQa]

            # dQab
            dQab = np.zeros((natoms, natoms, 3))
            for i in range(3):
                for a in range(natoms):
                    za = nuclear_charge[a]
                    Ra = molecule_coord[a]
                    for b in range(a):
                        zb = nuclear_charge[b]
                        Rb = molecule_coord[b]
                        dQab[a, b, i] = -(lagragian[i][a] -
                                          lagragian[i][b]) * self.penalty_fc(
                                              za, Ra, zb, Rb)
                        dQab[b, a, i] -= dQab[a, b, i]

            # dRab matrix: mid point of Ra-Rb
            dRab = np.zeros((natoms, natoms, 3))

            for a in range(natoms):
                for b in range(natoms):
                    for i in range(3):
                        dRab[a][b][i] = 0.5 * (molecule_coord[a][i] -
                                               molecule_coord[b][i])
                        dRab[b][a][i] = -dRab[a][b][i]

            # charge transfer from bond polarisability
            bond_polarizabilities = np.zeros((3, 3, natoms, natoms))
            for i in range(3):
                for j in range(3):
                    for a in range(natoms):
                        for b in range(natoms):
                            bond_polarizabilities[
                                i, j, a, b] = dRab[a, b, i] * dQab[
                                    a, b, j] + dRab[a, b, j] * dQab[a, b, i]

            local_polarizabilities = loc_dipole + 0.5 * bond_polarizabilities

            # molecular polarizabilities
            molecule_polarizabilities = (loc_dipole +
                                         0.5 * bond_polarizabilities).sum(
                                             axis=3).sum(axis=2)

            # obtain atom polarizabilities & re-arrange Qab in 1D array
            atom_polarizabilities = np.zeros((natoms, 6))
            Qab_array = np.zeros(natoms)
            for i in range(natoms):
                Qab_array[i] = Qab[i, i]

                atom_pol_matrix = local_polarizabilities.sum(axis=3)[:, :, i]
                # in the order xx, xy, xz, yy, yz, zz
                atom_polarizabilities[i, 0] = atom_pol_matrix[0, 0]
                atom_polarizabilities[i, 1] = 0.5 * (atom_pol_matrix[0, 1] +
                                                     atom_pol_matrix[1, 0])
                atom_polarizabilities[i, 2] = 0.5 * (atom_pol_matrix[0, 2] +
                                                     atom_pol_matrix[2, 0])
                atom_polarizabilities[i, 3] = atom_pol_matrix[1, 1]
                atom_polarizabilities[i, 4] = 0.5 * (atom_pol_matrix[1, 2] +
                                                     atom_pol_matrix[2, 1])
                atom_polarizabilities[i, 5] = atom_pol_matrix[2, 2]

            atom_polarizabilities = atom_polarizabilities * (
                bohr_in_angstroms()**3)
            self.print_results(molecule, natoms, Qab, local_polarizabilities,
                               molecule_polarizabilities, atom_polarizabilities)

            return {
                'localized_charges': Qab_array,
                'localized_polarizabilities': atom_polarizabilities,
            }
        else:
            return None

    def penalty_fc(self, za, Ra, zb, Rb):
        """
        penalty function

        :param za:
            atomic number for atom a
        :param Ra:
            position vector for atom a
        :param zb:
            atomic number for atom b
        :param Rb:
            position vector for atom b

        :return:
            The penalty function
        """

        # Ra/Rb are the position vectors
        RBS = np.array([
            0, 0.25, 0.25, 1.45, 1.05, 0.85, 0.7, 0.65, 0.5, 0.43, 1.8, 1.5,
            1.25, 1.1, 1.0, 1.0, 1.0, 1.0
        ]) / bohr_in_angstroms()
        # TODO: check if it is possible to go beyond Cl
        # we just have to update RBS array and get_ao_indices function
        # have to decide how far we want to go
        assert_msg_critical(za <= 17 or zb <= 17,
                            'LoPropDriver: we currently support up to Cl')
        ra = RBS[za]
        rb = RBS[zb]
        # Ra and Rb taking from r_mat: 0,1,2 represents x y z directions
        rab2 = (Ra[0] - Rb[0])**2 + (Ra[1] - Rb[1])**2 + (Ra[2] - Rb[2])**2
        # alpha set to 2
        f = 0.5 * np.exp(-2 * (rab2 / (ra + rb)**2))
        return f

    def lrmat(self, vec, nocc, norb):
        """
        unpact response vector to matrix form

        :param vec:
            the response vector
        :param nocc:
            number of contracted orbitals (alpha electrons)
        :param norb:
            number of orbitals

        :return:
            unpacked response vector
        """

        # TODO: use a different name from lrvec2mat
        kappa = np.zeros((norb, norb))
        nvir = norb - nocc
        n_ov = nocc * nvir
        kappa[:nocc, nocc:] = vec[:n_ov].reshape(nocc, nvir)
        kappa = kappa + kappa.T
        return kappa

    def lowdin_orthonormalize(self, A):
        """
        Lodwin orthonormaliztaion.

        :param A:
            The input matrix.

        :return:
            The orthonormalised vector.
        """

        eigs, U = np.linalg.eigh(A)
        return np.linalg.multi_dot([U, np.diag(1.0 / np.sqrt(eigs)), U.T])

    def get_ao_indices(self, molecule, basis):
        """
        Gets information about occupied/virtual orbitals by counting the basis
        set functions.

        :param molecule:
            The molecule.
        :param basis:
            The molecular basis set.

        :return:
            ao_per_atom, ao_occ, and ao_vir
        """

        elements = molecule.elem_ids_to_numpy()

        # TODO: check if it is possible to extract the information from the
        #       basis set object
        #       yes
        # potential problems with reading the basis set file:j
        # 1) the basis set may be in the current folder and not the basis folder
        # 2) there will be Pople type basis set with 'SP' functions
        angular_momentum_string = 'SPDFGHI'
        ao_count = dict(S = 1, P = 3, D = 5, F = 7, G = 9, H = 11, I = 13 )
        
        basis_info = {}
        for atombasis in basis:            
             angular_momenta = [
                 angular_momentum_string[basisfunc.angular_momentum]
                 for basisfunc in atombasis
            ]
             
             element_id = atombasis.get_elemental_id()
             basis_info[element_id] = angular_momenta        
             
        ao_per_atom = []
        ao_occ = []
        ao_vir = []
        iterr = 0
        for element_id in elements:
            angular_momenta = basis_info[element_id]
            angular_momentum_counter = Counter(angular_momenta)

            """TODO: check if it is possible to go beyond Ne
            now it's support up to Ar 
            if we want to support more element then we have to 
            update RBS radius list           
            """
            assert_msg_critical(element_id <= 18,
                                'LoProp: we currently support up to Ar')
            # For H and He: 1s
            ao_occ.append(iterr)

            offset_2p = angular_momentum_counter['S'] + iterr
            # For Li-Ne: + 2s 2p
            if (element_id >= 3 and element_id >11):
                ao_occ.append(iterr + 1)                
                ao_occ.append(offset_2p + 0)
                ao_occ.append(offset_2p + 1)
                ao_occ.append(offset_2p + 2)
             #for Na-Ar atoms: + 2s 3s 2p 3p
            elif element_id >= 11 :              
                #2s,3s
                 ao_occ.append(iterr + 1)
                 ao_occ.append(iterr + 2)
                #2p
                 ao_occ.append(offset_2p + 0)
                 ao_occ.append(offset_2p + 1)
                 ao_occ.append(offset_2p + 2)
                #3p
                 offset_3p = offset_2p + angular_momentum_counter['P'] 
                 ao_occ.append(offset_3p + 0)
                 ao_occ.append(offset_3p + 1)
                 ao_occ.append(offset_3p + 2)

            # sum number of orbitals. used to calculate virtual orbitals later
            orb = sum(ao_count[k] * v for k, v in angular_momentum_counter.items())
            iterr += orb
            ao_per_atom.append(orb)

        total_orb_array = np.arange(iterr)

        for i in total_orb_array:
            if i not in ao_occ:
                ao_vir.append(i)

        return ao_per_atom, ao_occ, ao_vir

    def print_results(self, molecule, natoms, Qab, local_polarizabilities, Am,
                      atom_polarizabilities):
        """
        Prints results for loprop calculation.

        param: molecule
            the molecule
        param: natoms
            number of atoms
        param: Qab
            localized charges
        param: local_polarizabilities
            localized polarizabilities
        param: Am
            molecular polarizabilities
        """

        element_names = molecule.get_labels()

        title = 'Local Properties (LoProp) Calculations'
        self.ostream.print_header(title)
        self.ostream.print_header('=' * (len(title) + 2))
        self.ostream.print_blank()

        title = 'Molecular Polarisabilities'
        self.ostream.print_header(title)
        self.ostream.print_header('-' * len(title))

        for a, comp in enumerate('xyz'):
            output_iter = 'alpha_{}{} : {:12.4f}'.format(comp, comp, Am[a, a])
            self.ostream.print_header(output_iter)
        self.ostream.print_blank()

        # print localized chagres
        title = 'LoProp localized charges'
        self.ostream.print_header(title)
        self.ostream.print_header('-' * len(title))

        for a in range(natoms):
            output_iter = ' {:<4s} : '.format(element_names[a])
            output_iter += '{:15.4f} '.format(Qab[a, a])
            self.ostream.print_header(output_iter)
        self.ostream.print_blank()

        title = 'LoProp Localised polarizabilities'
        self.ostream.print_header(title)
        self.ostream.print_header('-' * len(title))

        output_order = ' ' * 20
        output_order += '{:10s} {:10s} {:10s} '.format('xx', 'xy', 'xz')
        output_order += '{:10s} {:10s} {:10s}'.format('yy', 'yz', 'zz')
        self.ostream.print_header(output_order)
        for a in range(natoms):
            output_iter = ' {:<4s} : '.format(element_names[a])
            output_iter += '{:10.4f} {:10.4f} {:10.4f} '.format(
                atom_polarizabilities[a][0], atom_polarizabilities[a][1],
                atom_polarizabilities[a][2])
            output_iter += '{:10.4f} {:10.4f} {:10.4f}'.format(
                atom_polarizabilities[a][3], atom_polarizabilities[a][4],
                atom_polarizabilities[a][5])
            self.ostream.print_header(output_iter)
        self.ostream.print_blank()

        self.ostream.flush()
