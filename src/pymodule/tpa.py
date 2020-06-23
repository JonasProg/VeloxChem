import numpy as np
import time
import sys

from .veloxchemlib import ElectricDipoleIntegralsDriver
from .veloxchemlib import mpi_master
from .inputparser import parse_frequencies
from .cppsolver import ComplexResponse
from .tpadriver import TPAdriver
from .linearsolver import LinearSolver


class TPA(LinearSolver):
    """
    Implements the isotropic cubic response function for two-photon absorption
    (TPA)

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - frequencies: The frequencies.
        - damping: The damping parameter.
    """

    def __init__(self, comm, ostream):
        np.set_printoptions(threshold=sys.maxsize)
        self.iso = True
        self.reduced = True
        self.full = False
        self.mix = False


        # cpp settings
        self.frequencies = 0
        self.comp = "zzzz,0,0,0"
        self.damping = 0.004556335294880438
        self.lindep_thresh = 1.0e-10
        self.conv_thresh = 1.0e-4
        self.max_iter = 50
        self.eri_thresh = 1.0e-15
        self.qq_type = 'QQ_DEN'

        # mpi information
        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()
        self.ostream = ostream

    def update_settings(self, rsp_dict, method_dict=None):
        """
        Updates response and method settings in complex liner response solver
        used for TPA

        :param rsp_dict:
            The dictionary of response dict.
        :param method_dict:
            The dictionary of method rsp_dict.
        """

        if method_dict is None:
            method_dict = {}

        # TODO: include unit in parse_frequencies

        if 'frequencies' in rsp_dict:
            if 'unit' in rsp_dict:
                if rsp_dict['unit'] in 'eV':
                    ev_frequencies = rsp_dict['frequencies']
                    star = float(
                        ev_frequencies.split("-")[0]) / 27.218679420751958
                    en = float(
                        ev_frequencies.split("-")[1]) / 27.218679420751958
                    step = float(
                        ev_frequencies.split("-")[2]) / 27.218679420751958
                    self.frequencies = str(star) + "-" + str(en) + "-" + str(
                        step)
            else:
                self.frequencies = rsp_dict['frequencies']
        if 'damping' in rsp_dict:
            self.damping = float(rsp_dict['damping'])
        if 'reduced' in rsp_dict:
            self.reduced = rsp_dict['reduced']
            if self.reduced in 'True':
                self.reduced = True
            else:
                self.reduced = False
        if 'component' in rsp_dict:
            self.comp = rsp_dict['component']
            if self.comp in 'isotropic':
                self.iso = True
            else:
                self.iso = False

        if 'eri_thresh' in rsp_dict:
            self.eri_thresh = float(rsp_dict['eri_thresh'])
        if 'qq_type' in rsp_dict:
            self.qq_type = rsp_dict['qq_type']

        if 'max_iter' in rsp_dict:
            self.max_iter = int(rsp_dict['max_iter'])
        if 'conv_thresh' in rsp_dict:
            self.conv_thresh = float(rsp_dict['conv_thresh'])

        if 'lindep_thresh' in rsp_dict:
            self.lindep_thresh = float(rsp_dict['lindep_thresh'])
        # Used to specify it the user wants to compute the full cubic response which is valid in all spectral regions
        # or the reduced which is only valid in one-photon off-resonance regions, or both at the same time.
        if 'tpa' in rsp_dict:
            self.rsp = rsp_dict['tpa']
            if self.rsp in 'reduced':
                self.reduced = True
                self.full = False
                self.mix = False
            elif self.rsp in 'verify':
                self.mix = True
                self.full = False
                self.reduced = False
            elif self.rsp in 'full':
                self.full = True
                self.reduced = False
                self.mix = False

    def compute(self, molecule, ao_basis, scf_tensors):
        """
        Computes the isotropic cubic response function for two-photon
        absorption

        :param molecule:
            The molecule.
        :param basis:
            The AO basis.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.

        :return t4_dict:
              A dictonary containing the isotropic T[4] contractions
        :return t3_dict:
              A dictonary containing the isotropic T[3] contractions
        :return NaX3NyNz:
              A dictonary containing the isotropic X[3] contractions
        :return NaA3NxNy:
              A dictonary containing the isotropic A[3] contractions
        :return NaX2Nyz:
              A dictonary containing the isotropic X[2] contractions
        :return NxA2Nyz:
              A dictonary containing the isotropic A[2] contractions
        :return gamma:
              A dictonary containing the isotropic cubic response functions for
              TPA
        :return t3_dict_red:
              A dictonary containing the isotropic T[3] contractions for
              one-photon off-resonance TPA calculations
        :return NaX2Nyz_red:
              A dictonary containing the isotropic X[2] contractions for
              one-photo off-resonance TPA calculations
        :return NxA2Nyz_red:
              A dictonary containing the isotropic A[2] contractions for
              one-photo off-resonance TPA calculations
        :return gamma_red:
              A dictonary containing the reduced isotropic cubic response
              functions for TPA
        """

        time_start = time.time()

        tpa_drv = TPAdriver(self.comm, self.ostream)

        tpa_drv.update_settings({
            'damping': self.damping,
            'conv_thresh': self.conv_thresh,
            'lindep_thresh': self.lindep_thresh,
            'max_iter': self.max_iter,
            'eri_thresh': self.eri_thresh,
            'qq_type': self.qq_type,
        })

        if self.rank == mpi_master():
            S = scf_tensors['S']
            da = scf_tensors['D'][0]
            mo = scf_tensors['C']
            d_a_mo = np.linalg.multi_dot([mo.T, S, da, S, mo])
            nocc = molecule.number_of_alpha_electrons()
            norb = mo.shape[1]
            w = parse_frequencies(self.frequencies)
        else:
            S = None
            da = None
            mo = None
            d_a_mo = None
            nocc = None
            norb = None
            w = None

        # Computing first-order gradient vectors
        dipole_drv = ElectricDipoleIntegralsDriver(self.comm)
        dipole_mats = dipole_drv.compute(molecule, ao_basis)

        operator = 'dipole'
        component = 'xyz'

        b_rhs = self.get_complex_rhs(operator, component, molecule, ao_basis,
                                     scf_tensors)

        # Storing the dipole integral matrices used for the X[3],X[2],A[3] and
        # A[2] contractions in MO basis
        if self.rank == mpi_master():
            v1 = {(op, wi): v for op, v in zip(component, b_rhs) for wi in w}
            X = {
                'x': 2 * tpa_drv.ao2mo(mo, dipole_mats.x_to_numpy()),
                'y': 2 * tpa_drv.ao2mo(mo, dipole_mats.y_to_numpy()),
                'z': 2 * tpa_drv.ao2mo(mo, dipole_mats.z_to_numpy())
            }
            self.comp = self.get_comp(w)
        else:
            v1 = None
            X = None
            self.comp = None

        Nx = {}
        kX = {}
        Focks = {}

        # Updating settings for the first-order response vectors
        Nb_drv = ComplexResponse(self.comm, self.ostream)
        Nb_drv.update_settings({
            'frequencies': self.frequencies,
            'damping': self.damping,
            'lindep_thresh': self.lindep_thresh,
            'conv_thresh': self.conv_thresh,
            'max_iter': self.max_iter,
            'eri_thresh': self.eri_thresh,
            'qq_type': self.qq_type,
        })

        # Computing the first-order response vectors 3 per frequency
        Nb_Drv = Nb_drv.compute(molecule, ao_basis, scf_tensors, v1)

        if self.rank == mpi_master():

            Nx['Nb'] = Nb_Drv['solutions']
            kX['Nb'] = Nb_Drv['kappas']
            Focks['Fb'] = Nb_Drv['focks']

            

            Nx['Nc'] = {}
            kX['Nc'] = {}
            Focks['Fc'] = {}
            Focks['Fd'] = {}

            # The first-order response vectors with negative frequency are
            # obtained from the first-order response vectors with positive
            # frequency by using flip_zy, see article.

            for (op, freq) in Nx['Nb']:
                Nx['Nc'][(op, -freq)] = tpa_drv.flip_yz(Nx['Nb'][(op, freq)])

                # Creating the response matrix for the negative first-order
                # response vectors

                kX['Nc'][(op, -freq)] = (
                    LinearSolver.lrvec2mat(Nx['Nc'][(op, -freq)].real, nocc,
                                           norb) +
                    1j * LinearSolver.lrvec2mat(Nx['Nc'][
                        (op, -freq)].imag, nocc, norb))

                # The first-order Fock matrices with positive and negative
                # frequencies are each other complex conjugates

                Focks['Fc'][(op, -freq)] = Focks['Fb'][(op, freq)]
                Focks['Fd'][(op, freq)] = np.conjugate(Focks['Fb'][(op,
                                                                    freq)]).T

            # For the cubic-response with all operators being the dipole μ Nb=Na=Nd
            # Likewise, Fb=Fd

            Focks['Fb'].update(Focks['Fd'])

            Nx['Na'] = Nx['Nb']
            kX['Na'] = kX['Nb']

            Nx['Nd'] = Nx['Nb']
            kX['Nd'] = kX['Nb']

            # Storing the largest imaginary component of the response vector
            # for plotting
            # Nb Im
            vec_x = []
            vec_y = []
            vec_z = []

            for k in Nx['Nb'].keys():
                if k[0] in 'x':
                    vec_x.append(np.linalg.norm(Nx['Nb'][k].imag))
                if k[0] in 'y':
                    vec_y.append(np.linalg.norm(Nx['Nb'][k].imag))
                if k[0] in 'z':
                    vec_z.append(np.linalg.norm(Nx['Nb'][k].imag))

        # Computing the third-order gradient and also the contractions of
        # A[3] and A[2] which formally are not part of the third-order gradient
        # but which are used for the cubic response function
       
        # Computes for both the reduced and full gamma tensors   
        if self.mix is True:
            (n_xy_dict,NaX3NyNz, NaA3NxNy, NaX2Nyz, NxA2Nyz, E3_dict, E4_dict, NaX2Nyz_red,
             NxA2Nyz_red, E3_dict_red) = tpa_drv.main(Focks, self.iso, Nx, w, X,
                                                      d_a_mo, kX, self.comp, S, da,
                                                      mo, nocc, norb, scf_tensors,
                                                      molecule, ao_basis,self.full,self.reduced,self.mix)
        # Computes for only the reduced gamma tensor
        if self.reduced is True:
            (n_xy_dict,NaX2Nyz_red,
             NxA2Nyz_red, E3_dict_red) = tpa_drv.main(Focks, self.iso, Nx, w, X,
                                                      d_a_mo, kX, self.comp, S, da,
                                                      mo, nocc, norb, scf_tensors,
                                                      molecule, ao_basis,self.full,self.reduced,self.mix)
        # Computes for only the full gamma tensor 
        if self.full is True:
            (n_xy_dict,NaX3NyNz, NaA3NxNy, NaX2Nyz, NxA2Nyz, E3_dict, E4_dict) = tpa_drv.main(Focks, self.iso, Nx, w, X,
                                                      d_a_mo, kX, self.comp, S, da,
                                                      mo, nocc, norb, scf_tensors,
                                                      molecule, ao_basis,self.full,self.reduced,self.mix)

        if self.rank == mpi_master():

            if self.mix is True:
                t4_dict = tpa_drv.get_t4(w, E4_dict, Nx, kX, self.comp, d_a_mo,
                                         nocc, norb)
                t3_dict = tpa_drv.get_t3(w, E3_dict, Nx, self.comp)
                t3_dict_red = tpa_drv.get_t3(w, E3_dict_red, Nx, self.comp)     

            if self.reduced is True:
                t3_dict_red = tpa_drv.get_t3(w, E3_dict_red, Nx, self.comp)     

            if self.full is True:
                t4_dict = tpa_drv.get_t4(w, E4_dict, Nx, kX, self.comp, d_a_mo,
                                         nocc, norb)
                t3_dict = tpa_drv.get_t3(w, E3_dict, Nx, self.comp)

        else:
            t4_dict = None
            t3_dict = None
            t3_dict_red = None

        gamma = {}
        gamma_red = {}

        # Combining all the terms to evaluate the iso-tropic cubic response
        # function. For TPA Full and reduced, see article

        if self.rank == mpi_master():
            for i in range(len(w)):
                if self.mix is True or self.full is True:
                    gamma[(w[i], -w[i],
                           w[i])] = 1 / 15 * (t4_dict[(w[i], -w[i], w[i])] +
                                              t3_dict[(w[i], -w[i], w[i])] +
                                              NaX3NyNz[(w[i], -w[i], w[i])] +
                                              NaA3NxNy[(w[i], -w[i], w[i])] +
                                              NaX2Nyz[(w[i], -w[i], w[i])] +
                                              NxA2Nyz[(w[i], -w[i], w[i])])
                if self.mix is True or self.reduced is True:
                    gamma_red[(
                        w[i], -w[i],
                        w[i])] = 1 / 15 * (t3_dict_red[(w[i], -w[i], w[i])] +
                                           NaX2Nyz_red[(w[i], -w[i], w[i])] +
                                           NxA2Nyz_red[(w[i], -w[i], w[i])])

            self.print_header()
            if self.mix is True or self.full is True:
                self.print_results(self.iso, w, gamma, self.comp, t4_dict, t3_dict,
                                   NaX3NyNz, NaA3NxNy, NaX2Nyz, NxA2Nyz)
                if self.full is True:
                    t3_dict_red = {}
                    NaX2Nyz_red = {}
                    NxA2Nyz_red = {}
            if self.mix is True or self.reduced is True:
                self.print_results_red(self.iso, w, gamma_red, self.comp,
                                       t3_dict_red, NaX2Nyz_red, NxA2Nyz_red)
                if self.reduced is True:
                    t4_dict = {}
                    t3_dict = {}
                    NaX3NyNz = {}
                    NaA3NxNy = {}
                    NaX2Nyz = {}
                    NxA2Nyz = {}


            self.make_plots(n_xy_dict,w, gamma, gamma_red, vec_x,vec_y,vec_z,t4_dict,t3_dict,NaX3NyNz,NaA3NxNy,NaX2Nyz,NxA2Nyz,t3_dict_red, NaX2Nyz_red, NxA2Nyz_red)
        else:
            gamma = {}
            gamma_red = {}

        width = 50
        w_str = "Total time =  {:.8f}".format(time.time() - time_start)
        self.ostream.print_header(w_str.ljust(width))

        if self.rank == mpi_master():
            if self.full is True:
                return (w,t4_dict, t3_dict, NaX3NyNz, NaA3NxNy, NaX2Nyz, NxA2Nyz,
                        gamma)
            if self.reduced is True:
                return (w, t3_dict_red, NaX2Nyz_red, NxA2Nyz_red, gamma_red)
        else:
            if self.full is True:
                return (None, None, None, None, None, None, None, None)
            if self.reduced is True:
                return (None, None, None, None, None)
            if self.mix is True:
                return (None, None, None, None, None, None, None, None, None, None,
                        None, None)

    def print_header(self):
        """
        Prints TPA setup header to output stream.
        """

        self.ostream.print_blank()
        self.ostream.print_header("Two-Photon Absorbtion Driver Setup")
        self.ostream.print_header(31 * "=")
        self.ostream.print_blank()

        width = 50

        cur_str = "Frequencies : " + str(
            self.frequencies) + " (start-stop-step)"
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = "Damping     : " + \
            "{:.1e}".format(self.damping)
        self.ostream.print_header(cur_str.ljust(width))
        self.ostream.print_blank()
        self.ostream.print_header(('-' * len(cur_str)).ljust(width))
        cur_str = "Eri threshold for response solver : " + str(self.eri_thresh)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = "Convergance threshold for response solver : " + str(
            self.conv_thresh)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = "Linear-dep threshold for response solver : " + str(
            self.lindep_thresh)
        self.ostream.print_header(cur_str.ljust(width))
        cur_str = "Max iterations for response solver : " + str(self.max_iter)
        self.ostream.print_header(cur_str.ljust(width))

        self.ostream.flush()

    def print_results(self, iso, w1, gamma, comp, t4_dict, t3_dict, NaX3NyNz,
                      NaA3NxNy, NaX2Nyz, NxA2Nyz):
        """
        Prints the results from the TPA calculation.

        :param t4_dict:
              A dictonary containing the isotropic T[4] contractions
        :param t3_dict:
              A dictonary containing the isotropic T[3] contractions
        :param NaX3NyNz:
              A dictonary containing the isotropic X[3] contractions
        :param NaA3NxNy:
              A dictonary containing the isotropic A[3] contractions
        :param NaX2Nyz:
              A dictonary containing the isotropic X[2] contractions
        :param NxA2Nyz:
              A dictonary containing the isotropic A[2] contractions
        :param gamma:
              A dictonary containing the isotropic cubic response functions for
              TPA
        """

        width = 50

        self.ostream.print_blank()
        self.ostream.print_blank()
        w_str = "Gamma tensor components computed per frequency"
        self.ostream.print_blank()
        self.ostream.print_header(w_str.ljust(width))
        self.ostream.print_blank()
        count = 1
        for a in range(int(len(comp) * (1 / len(w1)))):
            w_str = str(count) + '. ' + str(comp[a].split(",")[0])
            self.ostream.print_header(w_str.ljust(width))
            count += 1

        self.ostream.print_blank()

        for w in w1:
            if iso is False:
                w_str = "ΣNaT3NxNyz =  {:.8f}".format(t3_dict[w, -w, w])
            else:
                w_str = "ΣNaT3NxNyz =  {:.8f}".format(t3_dict[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNaT4NxNyNz =  {:.8f}".format(t4_dict[w, -w, w])
            else:
                w_str = "ΣNaT4NxNyNz =  {:.8f}".format(t4_dict[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNaX2Nyz =  {:.8f}".format(NaX2Nyz[w, -w, w])
            else:
                w_str = "ΣNaX2Nyz =  {:.8f}".format(NaX2Nyz[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNaX3NyNz =  {:.8f}".format(NaX3NyNz[w, -w, w])
            else:
                w_str = "ΣNaX3NyNz =  {:.8f}".format(NaX3NyNz[w, -w, w] / 15)

            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNxA2Nyz =  {:.8f}".format(NxA2Nyz[w, -w, w])
            else:
                w_str = "ΣNxA2Nyz =  {:.8f}".format(NxA2Nyz[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNaA3NxNy =  {:.8f}".format(NaA3NxNy[w, -w, w])
            else:
                w_str = "ΣNaA3NxNy =  {:.8f}".format(NaA3NxNy[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            w_str = 'Σ<<μ;μ,μ,μ>>= {:.8f}, ω=({:.4f},{:.4f},{:.4f}), hω =({:.4f} eV)'.format(
                gamma[w, -w, w], w, -w, w, w * 54.437358841503915 / 2)
            self.ostream.print_header(w_str.ljust(width))
            self.ostream.print_header(('-' * len(w_str)).ljust(width))
            self.ostream.print_blank()

    def print_results_red(self, iso, w1, gamma, comp, t3_dict, NaX2Nyz,
                          NxA2Nyz):
        """
        Prints the results from the reduced TPA calculation.

        :param t3_dict_red:
            A dictonary containing the isotropic T[3] contractions for
            one-photon off-resonance TPA calculations
        :param NaX2Nyz_red:
            A dictonary containing the isotropic X[2] contractions for
            one-photo off-resonance TPA calculations
        :param NxA2Nyz_red:
            A dictonary containing the isotropic A[2] contractions for
            one-photo off-resonance TPA calculations
        :param gamma_red:
            A dictonary containing the reduced isotropic cubic response
            functions for TPA
        """
        width = 50

        self.ostream.print_blank()
        self.ostream.print_blank()
        w_str = "Gamma tensor components computed per frequency"
        self.ostream.print_blank()
        self.ostream.print_header(w_str.ljust(width))
        self.ostream.print_blank()
        count = 1
        for a in range(int(len(comp) * (1 / len(w1)))):
            w_str = str(count) + '. ' + str(comp[a].split(",")[0])
            self.ostream.print_header(w_str.ljust(width))
            count += 1

        self.ostream.print_blank()

        for w in w1:

            if iso is False:
                w_str = "ΣNaT3NxNyz =  {:.8f}".format(t3_dict[w, -w, w])
            else:
                w_str = "ΣNaT3NxNyz =  {:.8f}".format(t3_dict[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNaX2Nyz =  {:.8f}".format(NaX2Nyz[w, -w, w])
            else:
                w_str = "ΣNaX2Nyz =  {:.8f}".format(NaX2Nyz[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            if iso is False:
                w_str = "ΣNxA2Nyz =  {:.8f}".format(NxA2Nyz[w, -w, w])
            else:
                w_str = "ΣNxA2Nyz =  {:.8f}".format(NxA2Nyz[w, -w, w] / 15)
            self.ostream.print_header(w_str.ljust(width))

            w_str = '<<A;B,C,D>>= {:.8f}, w=({:.4f},{:.4f},{:.4f}), hω =({:.4f} eV)'.format(
                gamma[w, -w, w], w, -w, w, w * 54.437358841503915 / 2)
            self.ostream.print_header(w_str.ljust(width))
            self.ostream.print_header(('-' * len(w_str)).ljust(width))
            self.ostream.print_blank()

    def get_comp(self, w):
        """
        Makes a list of all the gamma tensor components that are to be computed
        for printing purposes and for the contraction of X[3],X[2],A[3],A[2]

        :param w:
            A list of all the frequencies for the TPA calculation
        :return comp:
            A list of gamma tensors components inlcuded in the isotropic cubic
            response with their corresponding frequencies
        """

        if self.iso is True:
            spat_A = ['x', 'y', 'z']
            comp_iso = []

            for a, b, e in ((a, b, e) for e in range(len(w))
                            for b in range(len(spat_A))
                            for a in range(len(spat_A))):
                comp_iso.append(
                    str(spat_A[a]) + str(spat_A[a]) + str(spat_A[b]) +
                    str(spat_A[b]) + ',' + str(w[e]) + ',' + str(-w[e]) + ',' +
                    str(w[e]))
                comp_iso.append(
                    str(spat_A[a]) + str(spat_A[b]) + str(spat_A[a]) +
                    str(spat_A[b]) + ',' + str(w[e]) + ',' + str(-w[e]) + ',' +
                    str(w[e]))
                comp_iso.append(
                    str(spat_A[a]) + str(spat_A[b]) + str(spat_A[b]) +
                    str(spat_A[a]) + ',' + str(w[e]) + ',' + str(-w[e]) + ',' +
                    str(w[e]))

            self.comp = sorted(comp_iso, key=comp_iso.index)

        else:

            Track = self.comp.split(",")
            count = 0
            comp = []
            for i in range(len(w)):
                for case in Track:
                    t = case[0] + case[1] + case[2] + case[3] + ',' + str(
                        w[i]) + ',' + str(-w[i]) + ',' + str(w[i])
                    comp.append(t)
                self.comp = comp
                count += 1
        return self.comp

    def make_plots(self,n_xy_dict, w, gamma, gamma_red, vec_x,vec_y,vec_z,t4_dict,t3_dict,NaX3NyNz,NaA3NxNy,NaX2Nyz,NxA2Nyz,t3_dict_red, NaX2Nyz_red, NxA2Nyz_red):
        """
        Makes plots of the two-photon cross section [GM] 
          1 a.u. = 1.896788 10^{-50} cm^4 s/photon
          1 GM = 10^{-50} cm^4 s/photon
        
        :param gamma:
              A dictonary containing the isotropic cubic response functions for TPA
        :param gamma_red:
              A dictonary containing the reduced isotropic cubic response functions for TPA
        """

        g_comb = open('py_plot_comb.py', "w")
        add_stuff = 'import matplotlib \nimport matplotlib.pyplot as plt \n'
        g_comb.write(add_stuff)
        
        N_lamtau_xx = 'N_lamtau_xx = [' 
        N_lamtau_yy = 'N_lamtau_yy = [' 
        N_lamtau_zz = 'N_lamtau_zz = [' 
        N_lamtau_xy = 'N_lamtau_xy = [' 
        N_lamtau_xz = 'N_lamtau_xz = [' 
        N_lamtau_yz = 'N_lamtau_yz = [' 
        N_lam_tot = 'N_lam_tot = []'

        N_sig_xx = 'N_sig_xx = [' 
        N_sig_yy = 'N_sig_yy = [' 
        N_sig_zz = 'N_sig_zz = [' 
        N_sig_xy = 'N_sig_xy = [' 
        N_sig_xz = 'N_sig_xz = [' 
        N_sig_yz = 'N_sig_yz = [' 
        N_sig_tot = 'N_sig_tot = []'

        for k in n_xy_dict.keys():
            if k[0][0] in 'N_lamtau_xx':
                N_lamtau_xx += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_lamtau_yy':
                N_lamtau_yy += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_lamtau_zz':
                N_lamtau_zz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_lamtau_xy':
                N_lamtau_xy += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_lamtau_xz':
                N_lamtau_xz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_lamtau_yz':
                N_lamtau_yz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","

            if k[0][0] in 'N_sig_xx':
                N_sig_xx += str(np.linalg.norm(n_xy_dict[k].imag)) + "," 
            if k[0][0] in 'N_sig_yy':
                N_sig_yy += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_sig_zz':
                N_sig_zz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_sig_xy':
                N_sig_xy += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_sig_xz': 
                N_sig_xz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","
            if k[0][0] in 'N_sig_yz':
                N_sig_yz += str(np.linalg.norm(n_xy_dict[k].imag)) + ","

        N_lamtau_xx +=  "]\n" 
        N_lamtau_yy +=  "]\n" 
        N_lamtau_zz +=  "]\n" 
        N_lamtau_xy +=  "]\n" 
        N_lamtau_xz +=  "]\n" 
        N_lamtau_yz +=  "]\n" 

        N_sig_xx +=  "]\n" 
        N_sig_yy +=  "]\n" 
        N_sig_zz +=  "]\n" 
        N_sig_xy +=  "]\n" 
        N_sig_xz +=  "]\n" 
        N_sig_yz +=  "]\n" 

        g_comb.write(N_lamtau_xx)
        g_comb.write(N_lamtau_yy)
        g_comb.write(N_lamtau_zz)
        g_comb.write(N_lamtau_xy)
        g_comb.write(N_lamtau_xz)
        g_comb.write(N_lamtau_yz)

        
        g_comb.write(N_sig_xx)
        g_comb.write(N_sig_yy)
        g_comb.write(N_sig_zz)
        g_comb.write(N_sig_xy)
        g_comb.write(N_sig_xz)
        g_comb.write(N_sig_yz)

        N_x = 'N_x = ['
        N_y = 'N_y = ['
        N_z = 'N_z = ['
        N_t = 'N_t = ['

        x3 = 'x3 = ['
        a3 = 'a3 = ['
        x2 = 'x2 = ['
        x2_red = 'x2_red = ['
        a2 = 'a2 = ['
        a2_red = 'a2_red = ['
        t4 = 't4 = ['
        t3 = 't3 = ['
        t3_red = 't3_red = ['

        N1 = 4
        af = 1 / 137
        pi = 3.14159265359
        c = 1.896788
        C = c*N1 * pi**(2) * af**(2)
        omega_for_plot = 'ω = ['

        for i in range(len(w)):
            omega_for_plot += str(w[i] * 54.437358841503915 / 2) + ","
            N_x += str(vec_x[i]) + ","
            N_y += str(vec_y[i]) + ","
            N_z += str(vec_z[i]) + ","
            N_t += str(vec_x[i]+vec_y[i]+vec_z[i]) + ","
        N_x += "]\n"
        N_y += "]\n"
        N_z += "]\n"
        N_t += "]\n"
        g_comb.write(N_x)
        g_comb.write(N_y)
        g_comb.write(N_z)
        g_comb.write(N_t)
        omega_for_plot += "] \n"
        g_comb.write(omega_for_plot)

        if self.mix is True or self.full is True:
            data_for_plot = 'σ = ['
            # Contstats for the evauation of the cross section from the iso-tropic cubic response function
            for i in range(len(w)):
                data_for_plot += str(
                    C * w[i]**2 * gamma[(w[i], -w[i], w[i])].imag) + ","
                t4 += str(
                    C * w[i]**2 * t4_dict[(w[i], -w[i], w[i])].imag) + ","
                t3 += str(
                    C * w[i]**2 * t3_dict[(w[i], -w[i], w[i])].imag) + ","
                x3 += str(
                    C * w[i]**2 * NaX3NyNz[(w[i], -w[i], w[i])].imag) + ","
                a3 += str(
                    C * w[i]**2 * NaA3NxNy[(w[i], -w[i], w[i])].imag) + ","
                x2 += str(
                    C * w[i]**2 * NaX2Nyz[(w[i], -w[i], w[i])].imag) + ","
                a2 += str(
                    C * w[i]**2 * NxA2Nyz[(w[i], -w[i], w[i])].imag) + ","
            data_for_plot += "]\n"
            t4 += "]\n"
            t3 += "]\n"
            x3 += "]\n"
            a3 += "]\n"
            x2 += "]\n"
            a2 += "]\n"
            g_comb.write(data_for_plot)
            g_comb.write(t4)
            g_comb.write(t3)
            g_comb.write(x3)
            g_comb.write(a3)
            g_comb.write(x2)
            g_comb.write(a2)

        if self.mix is True or self.reduced is True:
            data_for_plot = 'σ_red = ['
            for i in range(len(w)):
                data_for_plot += str(
                    C * w[i]**2 * gamma_red[(w[i], -w[i], w[i])].imag) + ","
                t3_red += str(
                    C * w[i]**2 * t3_dict_red[(w[i], -w[i], w[i])].imag) + ","
                x2_red += str(
                    C * w[i]**2 * NaX2Nyz_red[(w[i], -w[i], w[i])].imag) + ","
                a2_red += str(
                    C * w[i]**2 * NxA2Nyz_red[(w[i], -w[i], w[i])].imag) + ","
            data_for_plot += "]\n"
            t3_red += "]\n"
            x2_red += "]\n"
            a2_red += "]\n"

            g_comb.write(data_for_plot)
            g_comb.write(t3_red)
            g_comb.write(x2_red)
            g_comb.write(a2_red)


        if self.mix is True:
            data_for_plot = 'σ_comp = ['
            for i in range(len(w)):
                data_for_plot += str(
                    abs(C * w[i]**2 * gamma_red[(w[i], -w[i], w[i])].imag-C * w[i]**2 * gamma[(w[i], -w[i], w[i])].imag)) + ","
            data_for_plot += "]\n"
            g_comb.write(data_for_plot)


        g_comb.write('\nfig,ax1=plt.subplots()')
        g_comb.write('\nax2 = ax1.twinx()')
        g_comb.write('\nplt.xlabel(\'ω eV\')')
        g_comb.write('\nplt.ylabel(\'σ TPA cross [GM]\')')
        
        ## Plot shows if there are any imaginary elements present in the first-order response vectors
        g_comb.write('\nax2.plot(ω,N_x,\'--*c\',label=\'Nb Im x\')')
        g_comb.write('\nax2.plot(ω,N_y,\'--hc\',label=\'Nb Im y\')')
        g_comb.write('\nax2.plot(ω,N_z,\'--+c\',label=\'Nb Im z\')')
        g_comb.write('\nax2.plot(ω,N_t,\'--+c\',label=\'Nb Im x+y+z\')')

        g_comb.write('\nplt.legend()')
        if self.mix is True or self.full is True:
            g_comb.write('\nax1.plot(ω,σ,\'-Dk\',label=\'Full\')')
        if self.mix is True or self.reduced is True:
            g_comb.write('\nax1.plot(ω,σ_red,\'-or\',label=\'Reduced\')\nplt.legend()')
        if self.mix is True:
            g_comb.write('\nax1.plot(ω,σ_comp,\'-.y\',label=\'error\')\nplt.legend()')
        g_comb.write('\nplt.show()')
        #g_comb.write('\nplt.savefig(\"filename.eps\", facecolor=\'w\', edgecolor=\'w\',orientation=\'portrait\', papertype=None, format=\'eps\',transparent=True,frameon=None, metadata=None)')
                                                                          

