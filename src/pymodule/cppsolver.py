import numpy as np
import time as tm
import psutil
import math
import sys

from .veloxchemlib import mpi_master
from .profiler import Profiler
from .distributedarray import DistributedArray
from .signalhandler import SignalHandler
from .linearsolver import LinearSolver
from .errorhandler import assert_msg_critical
from .inputparser import parse_frequencies
from .checkpoint import check_rsp_hdf5
from .checkpoint import append_rsp_solution_hdf5


class ComplexResponse(LinearSolver):
    """
    Implements the complex linear response solver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - a_operator: The A operator.
        - a_components: Cartesian components of the A operator.
        - b_operator: The B operator.
        - b_components: Cartesian components of the B operator.
        - frequencies: The frequencies.
        - damping: The damping parameter.
    """

    def __init__(self, comm, ostream):
        """
        Initializes complex linear response solver to default setup.
        """

        super().__init__(comm, ostream)

        self.a_operator = 'dipole'
        self.a_components = 'xyz'
        self.b_operator = 'dipole'
        self.b_components = 'xyz'

        self.frequencies = (0,)
        self.damping = 0.004556335294880438

    def update_settings(self, rsp_dict, method_dict={}):
        """
        Updates response and method settings in complex liner response solver.

        :param rsp_dict:
            The dictionary of response dict.
        :param method_dict:
            The dictionary of method rsp_dict.
        """

        super().update_settings(rsp_dict, method_dict)

        if 'a_operator' in rsp_dict:
            self.a_operator = rsp_dict['a_operator'].lower()
        if 'a_components' in rsp_dict:
            self.a_components = rsp_dict['a_components'].lower()
        if 'b_operator' in rsp_dict:
            self.b_operator = rsp_dict['b_operator'].lower()
        if 'b_components' in rsp_dict:
            self.b_components = rsp_dict['b_components'].lower()

        if 'frequencies' in rsp_dict:
            self.frequencies = parse_frequencies(rsp_dict['frequencies'])
        if 'damping' in rsp_dict:
            self.damping = float(rsp_dict['damping'])

    def get_precond(self, orb_ene, nocc, norb, w, d):
        """
        Constructs the preconditioners.

        :param orb_ene:
            The orbital energies.
        :param nocc:
            The number of doubly occupied orbitals.
        :param norb:
            The number of orbitals.
        :param w:
            The frequency.
        :param d:
            The damping parameter.

        :return:
            The distributed preconditioners.
        """

        # spawning needed components

        ediag, sdiag = self.construct_ed_sd_half(orb_ene, nocc, norb)
        ediag_sq = ediag**2
        sdiag_sq = sdiag**2
        sdiag_fp = sdiag**4
        w_sq = w**2
        d_sq = d**2

        # constructing matrix block diagonals

        a_diag = ediag * (ediag_sq - (w_sq - d_sq) * sdiag_sq)
        b_diag = (w * sdiag) * (ediag_sq - (w_sq + d_sq) * sdiag_sq)
        c_diag = (d * sdiag) * (ediag_sq + (w_sq + d_sq) * sdiag_sq)
        d_diag = (2 * w * d * ediag) * sdiag_sq
        p_diag = 1.0 / ((ediag_sq - (w_sq - d_sq) * sdiag_sq)**2 +
                        (4 * w_sq * d_sq * sdiag_fp))

        pa_diag = p_diag * a_diag
        pb_diag = p_diag * b_diag
        pc_diag = p_diag * c_diag
        pd_diag = p_diag * d_diag

        return tuple([
            DistributedArray(p, self.comm)
            for p in [pa_diag, pb_diag, pc_diag, pd_diag]
        ])

    def preconditioning(self, precond, v_in):
        """
        Applies preconditioner to a tuple of distributed trial vectors.

        :param precond:
            The preconditioner.
        :param v_in:
            The input trial vectors.

        :return:
            A tuple of distributed trail vectors after preconditioning.
        """

        pa, pb, pc, pd = [p.data for p in precond]

        v_in_rg, v_in_ru, v_in_iu, v_in_ig = [v.data for v in v_in]

        v_out_rg = pa * v_in_rg + pb * v_in_ru + pc * v_in_iu + pd * v_in_ig
        v_out_ru = pb * v_in_rg + pa * v_in_ru + pd * v_in_iu + pc * v_in_ig
        v_out_iu = pc * v_in_rg + pd * v_in_ru - pa * v_in_iu - pb * v_in_ig
        v_out_ig = pd * v_in_rg + pc * v_in_ru - pb * v_in_iu - pa * v_in_ig

        return tuple([
            DistributedArray(v, self.comm, distribute=False)
            for v in [v_out_rg, v_out_ru, v_out_iu, v_out_ig]
        ])

    def precond_trials(self, vectors, precond):
        """
        Applies preconditioner to distributed trial vectors.

        :param vectors:
            The set of vectors.
        :param precond:
            The preconditioner.

        :return:
            The preconditioned gerade and ungerade trial vectors.
        """

        trials_ger = []
        trials_ung = []
        sqrt_2 = math.sqrt(2.0)

        for (op, w), vec in vectors.items():
            v = self.preconditioning(precond[w], vec)
            norms = [sqrt_2 * p.norm() for p in v]
            vn = math.sqrt(sum([n**2 for n in norms]))

            if vn > self.small_thresh:
                # real gerade
                if norms[0] > self.small_thresh:
                    trials_ger.append(v[0].data)
                # real ungerade
                if norms[1] > self.small_thresh:
                    trials_ung.append(v[1].data)
                # imaginary ungerade
                if norms[2] > self.small_thresh:
                    trials_ung.append(v[2].data)
                # imaginary gerade
                if norms[3] > self.small_thresh:
                    trials_ger.append(v[3].data)

        new_ger = np.array(trials_ger).T
        new_ung = np.array(trials_ung).T

        dist_new_ger = DistributedArray(new_ger, self.comm, distribute=False)
        dist_new_ung = DistributedArray(new_ung, self.comm, distribute=False)

        return dist_new_ger, dist_new_ung

    def compute(self, molecule, basis, scf_tensors, v1=None):
        """
        Solves for the response vector iteratively while checking the residuals
        for convergence.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis.
        :param scf_tensors:
            The dictionary of tensors from converged SCF wavefunction.
        :param v1:
            The gradients on the right-hand side. If not provided, v1 will be
            computed for the B operator.

        :return:
            A dictionary containing response functions, solutions and a
            dictionarry containing solutions and kappa values when called from
            a non-linear response module.
        """

        self.dist_bger = None
        self.dist_bung = None
        self.dist_e2bger = None
        self.dist_e2bung = None

        profiler = Profiler({
            'timing': self.timing,
            'profiling': self.profiling,
            'memory_profiling': self.memory_profiling,
            'memory_tracing': self.memory_tracing,
        })

        if self.rank == mpi_master():
            self.print_header('Complex Response Solver')

        self.start_time = tm.time()

        # sanity check
        nalpha = molecule.number_of_alpha_electrons()
        nbeta = molecule.number_of_beta_electrons()
        assert_msg_critical(
            nalpha == nbeta,
            'ComplexResponseSolver: not implemented for unrestricted case')

        if self.rank == mpi_master():
            orb_ene = scf_tensors['E']
        else:
            orb_ene = None
        orb_ene = self.comm.bcast(orb_ene, root=mpi_master())
        norb = orb_ene.shape[0]
        nocc = molecule.number_of_alpha_electrons()

        # ERI information
        eri_dict = self.init_eri(molecule, basis)

        # DFT information
        dft_dict = self.init_dft(molecule, scf_tensors)

        # PE information
        pe_dict = self.init_pe(molecule, basis)

        timing_dict = {}

        # right-hand side (gradient)
        valid_v1 = False
        if self.rank == mpi_master():
            valid_v1 = (v1 is not None)
        valid_v1 = self.comm.bcast(valid_v1, root=mpi_master())

        if not valid_v1:
            nonlinear_flag = False
            b_rhs = self.get_complex_rhs(self.b_operator, self.b_components,
                                         molecule, basis, scf_tensors)
            
            if self.rank == mpi_master():
                v1 = {(op, w): v for op, v in zip(self.b_components, b_rhs)
                      for w in self.frequencies}
        else:
            nonlinear_flag = True

        # operators, frequencies and preconditioners
        if self.rank == mpi_master():
            op_freq_keys = list(v1.keys())
        else:
            op_freq_keys = None
        op_freq_keys = self.comm.bcast(op_freq_keys, root=mpi_master())

        d = self.damping
        freqs = set([w for (op, w) in op_freq_keys])
        precond = {
            w: self.get_precond(orb_ene, nocc, norb, w, d) for w in freqs
        }

        # distribute the right-hand side
        # dist_v1 will also serve as initial guess
        dist_v1 = {}
        for key in op_freq_keys:
            if self.rank == mpi_master():
                gradger, gradung = self.decomp_grad(v1[key])
                grad_rg = gradger.real
                grad_ru = gradung.real
                grad_iu = gradung.imag
                grad_ig = gradger.imag
            else:
                grad_rg, grad_ru = None, None
                grad_iu, grad_ig = None, None
            dist_v1[key] = (DistributedArray(grad_rg, self.comm),
                            DistributedArray(grad_ru, self.comm),
                            DistributedArray(grad_iu, self.comm),
                            DistributedArray(grad_ig, self.comm))

        rsp_vector_labels = [
            'CLR_bger_half_size',
            'CLR_bung_half_size',
            'CLR_e2bger_half_size',
            'CLR_e2bung_half_size',
        ]

        # check validity of checkpoint file
        if self.restart:
            if self.rank == mpi_master():
                self.restart = check_rsp_hdf5(self.checkpoint_file,
                                              rsp_vector_labels, molecule,
                                              basis, dft_dict, pe_dict)
            self.restart = self.comm.bcast(self.restart, root=mpi_master())

        # read initial guess from restart file
        if self.restart:
            self.read_vectors(rsp_vector_labels)

        # generate initial guess from scratch
        else:
            bger, bung = self.setup_trials(dist_v1, precond)

            Fock_ger_mat,Fock_ung_mat = self.e2n_half_size(bger, bung, molecule, basis, scf_tensors,
                               eri_dict, dft_dict, pe_dict, timing_dict)

        profiler.check_memory_usage('Initial guess')
        
        Focks = {}
        solutions = {}
        residuals = {}
        relative_residual_norm = {}

        signal_handler = SignalHandler()
        signal_handler.add_sigterm_function(self.graceful_exit, molecule, basis,
                                            dft_dict, pe_dict,
                                            rsp_vector_labels)

        iter_per_trail_in_hours = None
        sqrt_2 = math.sqrt(2.0)

        # start iterations
        for iteration in range(self.max_iter):

            iter_start_time = tm.time()

            profiler.start_timer(iteration, 'ReducedSpace')

            xvs = []
            self.cur_iter = iteration

            n_ger = self.dist_bger.shape(1)
            n_ung = self.dist_bung.shape(1)

            e2gg = self.dist_bger.matmul_AtB(self.dist_e2bger, 2.0)
            e2uu = self.dist_bung.matmul_AtB(self.dist_e2bung, 2.0)
            s2ug = self.dist_bung.matmul_AtB(self.dist_bger, 4.0)

            for op, w in op_freq_keys:
                if (iteration == 0 or
                        relative_residual_norm[(op, w)] > self.conv_thresh):

                    grad_rg, grad_ru, grad_iu, grad_ig = dist_v1[(op, w)]

                    # projections onto gerade and ungerade subspaces:

                    g_realger = self.dist_bger.matmul_AtB(grad_rg, 2.0)
                    g_imagger = self.dist_bger.matmul_AtB(grad_ig, 2.0)
                    g_realung = self.dist_bung.matmul_AtB(grad_ru, 2.0)
                    g_imagung = self.dist_bung.matmul_AtB(grad_iu, 2.0)

                    # creating gradient and matrix for linear equation

                    size = 2 * (n_ger + n_ung)

                    if self.rank == mpi_master():

                        # gradient

                        g = np.zeros(size)

                        g[:n_ger] = g_realger[:]
                        g[n_ger:n_ger + n_ung] = g_realung[:]
                        g[n_ger + n_ung:size - n_ger] = -g_imagung[:]
                        g[size - n_ger:] = -g_imagger[:]

                        # matrix

                        mat = np.zeros((size, size))

                        # filling E2gg

                        mat[:n_ger, :n_ger] = e2gg[:, :]
                        mat[size - n_ger:, size - n_ger:] = -e2gg[:, :]

                        # filling E2uu

                        mat[n_ger:n_ger + n_ung,
                            n_ger:n_ger + n_ung] = e2uu[:, :]

                        mat[n_ger + n_ung:size - n_ger,
                            n_ger + n_ung:size - n_ger] = -e2uu[:, :]

                        # filling S2ug

                        mat[n_ger:n_ger + n_ung, :n_ger] = -w * s2ug[:, :]

                        mat[n_ger + n_ung:size - n_ger, :n_ger] = d * s2ug[:, :]

                        mat[n_ger:n_ger + n_ung, size - n_ger:] = d * s2ug[:, :]

                        mat[n_ger + n_ung:size - n_ger,
                            size - n_ger:] = w * s2ug[:, :]

                        # filling S2ug.T (interchanging of row and col)

                        mat[:n_ger, n_ger:n_ger + n_ung] = -w * s2ug.T[:, :]

                        mat[:n_ger,
                            n_ger + n_ung:size - n_ger] = d * s2ug.T[:, :]

                        mat[size - n_ger:,
                            n_ger:n_ger + n_ung] = d * s2ug.T[:, :]

                        mat[size - n_ger:,
                            n_ger + n_ung:size - n_ger] = w * s2ug.T[:, :]

                        # solving matrix equation

                        c = np.linalg.solve(mat, g)
                    else:
                        c = None
                    c = self.comm.bcast(c, root=mpi_master())

                    # extracting the 4 components of c...

                    c_realger = c[:n_ger]
                    c_realung = c[n_ger:n_ger + n_ung]
                    c_imagung = c[n_ger + n_ung:size - n_ger]
                    c_imagger = c[size - n_ger:]

                    # ...and projecting them onto respective subspace

                    x_realger = self.dist_bger.matmul_AB_no_gather(c_realger)
                    x_realung = self.dist_bung.matmul_AB_no_gather(c_realung)
                    x_imagung = self.dist_bung.matmul_AB_no_gather(c_imagung)
                    x_imagger = self.dist_bger.matmul_AB_no_gather(c_imagger)

                    # composing E2 matrices projected onto solution subspace

                    e2realger = self.dist_e2bger.matmul_AB_no_gather(c_realger)
                    e2imagger = self.dist_e2bger.matmul_AB_no_gather(c_imagger)
                    e2realung = self.dist_e2bung.matmul_AB_no_gather(c_realung)
                    e2imagung = self.dist_e2bung.matmul_AB_no_gather(c_imagung)

                    Fock_real_ger = 0
                    Fock_real_ung = 0
                    Fock_imag_ung = 0
                    Fock_imag_ger = 0


                    for p in range(len(Fock_ger_mat)):
                        Fock_real_ger += Fock_ger_mat[p]*c_realger[p]
                        Fock_imag_ger += Fock_ger_mat[p]*c_imagger[p]

                    for q in range(len(Fock_ung_mat)):
                        Fock_real_ung += Fock_ung_mat[q]*c_realung[q]
                        Fock_imag_ung += Fock_ung_mat[q]*c_imagung[q]


                    Fock_matrix = Fock_real_ger + Fock_real_ung - 1j*(Fock_imag_ger+Fock_imag_ung)

                    Focks.update({(op,w): Fock_matrix})

                    # calculating the residual components

                    s2realger = 2.0 * x_realger.data
                    s2imagger = 2.0 * x_imagger.data
                    s2realung = 2.0 * x_realung.data
                    s2imagung = 2.0 * x_imagung.data

                    r_realger = (e2realger.data - w * s2realung +
                                 d * s2imagung - grad_rg.data)
                    r_realung = (e2realung.data - w * s2realger +
                                 d * s2imagger - grad_ru.data)
                    r_imagung = (-e2imagung.data + w * s2imagger +
                                 d * s2realger + grad_iu.data)
                    r_imagger = (-e2imagger.data + w * s2imagung +
                                 d * s2realung + grad_ig.data)

                    r_realger = DistributedArray(r_realger,
                                                 self.comm,
                                                 distribute=False)
                    r_realung = DistributedArray(r_realung,
                                                 self.comm,
                                                 distribute=False)
                    r_imagung = DistributedArray(r_imagung,
                                                 self.comm,
                                                 distribute=False)
                    r_imagger = DistributedArray(r_imagger,
                                                 self.comm,
                                                 distribute=False)

                    # calculating relative residual norm
                    # for convergence check

                    r = (r_realger, r_realung, r_imagung, r_imagger)
                    x = (x_realger, x_realung, x_imagung, x_imagger)

                    x_full = self.get_full_solution_vector(x)
                    if self.rank == mpi_master():
                        xv = np.dot(x_full, v1[(op, w)])
                        xvs.append((op, w, xv))

                    r_norms = [sqrt_2 * p.norm() for p in r]
                    x_norms = [sqrt_2 * p.norm() for p in x]

                    rn = math.sqrt(sum([n**2 for n in r_norms]))
                    xn = math.sqrt(sum([n**2 for n in x_norms]))

                    if xn != 0:
                        relative_residual_norm[(op, w)] = rn / xn
                    else:
                        relative_residual_norm[(op, w)] = rn

                    if relative_residual_norm[(op, w)] < self.conv_thresh:
                        solutions[(op, w)] = x
                    else:
                        residuals[(op, w)] = r

            # write to output
            if self.rank == mpi_master():

                self.ostream.print_info(
                    '{:d} gerade trial vectors in reduced space'.format(n_ger))
                self.ostream.print_info(
                    '{:d} ungerade trial vectors in reduced space'.format(
                        n_ung))
                self.ostream.print_blank()

                profiler.print_memory_subspace(
                    {
                        'dist_bger': self.dist_bger,
                        'dist_bung': self.dist_bung,
                        'dist_e2bger': self.dist_e2bger,
                        'dist_e2bung': self.dist_e2bung,
                        'precond': precond,
                        'solutions': solutions,
                        'residuals': residuals,
                    }, self.ostream)

                profiler.check_memory_usage(
                    'Iteration {:d} subspace'.format(iteration + 1))

                profiler.print_memory_tracing(self.ostream)

                self.print_iteration(relative_residual_norm, xvs)

            profiler.stop_timer(iteration, 'ReducedSpace')

            # check convergence

            self.check_convergence(relative_residual_norm)

            if self.is_converged:
                break

            profiler.start_timer(iteration, 'Orthonorm.')

            # spawning new trial vectors from residuals

            new_trials_ger, new_trials_ung = self.setup_trials(
                residuals, precond, self.dist_bger, self.dist_bung)

            residuals.clear()

            profiler.stop_timer(iteration, 'Orthonorm.')

            if self.rank == mpi_master():
                n_new_trials = new_trials_ger.shape(1) + new_trials_ung.shape(1)
            else:
                n_new_trials = None
            n_new_trials = self.comm.bcast(n_new_trials, root=mpi_master())

            if iter_per_trail_in_hours is not None:
                next_iter_in_hours = iter_per_trail_in_hours * n_new_trials
                if self.need_graceful_exit(next_iter_in_hours):
                    self.graceful_exit(molecule, basis, dft_dict, pe_dict,
                                       rsp_vector_labels)

            profiler.start_timer(iteration, 'FockBuild')

            # creating new sigma and rho linear transformations

            new_Fock_ger_mat,new_Fock_ung_mat= self.e2n_half_size(new_trials_ger, new_trials_ung, molecule, basis,
                               scf_tensors, eri_dict, dft_dict, pe_dict,
                               timing_dict)
            for a in new_Fock_ger_mat:
                Fock_ger_mat.append(a)

            for b in new_Fock_ung_mat:
                Fock_ung_mat.append(b)

            iter_in_hours = (tm.time() - iter_start_time) / 3600
            iter_per_trail_in_hours = iter_in_hours / n_new_trials

            profiler.stop_timer(iteration, 'FockBuild')
            if self.dft or self.pe:
                profiler.update_timer(iteration, timing_dict)

            profiler.check_memory_usage(
                'Iteration {:d} sigma build'.format(iteration + 1))

        signal_handler.remove_sigterm_function()

        self.write_checkpoint(molecule, basis, dft_dict, pe_dict,
                              rsp_vector_labels)

        # converged?
        if self.rank == mpi_master():
            self.print_convergence('Complex response')

        profiler.print_timing(self.ostream)
        profiler.print_profiling_summary(self.ostream)

        profiler.check_memory_usage('End of CPP solver')
        profiler.print_memory_usage(self.ostream)

        # calculate response functions
        if not nonlinear_flag:
            a_rhs = self.get_complex_rhs(self.a_operator, self.a_components,
                                         molecule, basis, scf_tensors)

            if self.is_converged:
                key_0 = list(solutions.keys())[0]
                x_0 = self.get_full_solution_vector(solutions[key_0])

                if self.rank == mpi_master():
                    avail_mem = psutil.virtual_memory().available
                    write_solution_to_file = (
                        avail_mem < sys.getsizeof(x_0) * len(solutions) * 2)
                    full_solutions = {}

                    va = {op: v for op, v in zip(self.a_components, a_rhs)}
                    rsp_funcs = {}

                for bop, w in solutions:
                    x = self.get_full_solution_vector(solutions[(bop, w)])

                    if self.rank == mpi_master():
                        for aop in self.a_components:
                            rsp_funcs[(aop, bop, w)] = -np.dot(va[aop], x)

                            if write_solution_to_file:
                                append_rsp_solution_hdf5(
                                    self.checkpoint_file,
                                    '{:s}_{:s}_{:.8f}'.format(aop, bop, w), x)
                            else:
                                full_solutions[(bop, w)] = x

                if self.rank == mpi_master():
                    if write_solution_to_file:
                        return {'response_functions': rsp_funcs}
                    else:
                        return {
                            'response_functions': rsp_funcs,
                            'solutions': full_solutions
                        }

        else:
            if self.is_converged:
                if self.rank == mpi_master():
                    kappas = {}
                
                exp_sol = {}
                for op, w in solutions:
                    x = self.get_full_solution_vector(solutions[(op, w)])
                    exp_sol.update({(op, w): x})

                    if self.rank == mpi_master():
                        kappas[(op,
                                w)] = (self.lrvec2mat(x.real, nocc, norb) +
                                       1j * self.lrvec2mat(x.imag, nocc, norb))

                if self.rank == mpi_master():
                    return {'Focks': Focks,'solutions': exp_sol,'kappas': kappas}

        return {}

    def get_full_solution_vector(self, solution):
        """
        Gets a full solution vector from the distributed solution.

        :param solution:
            The distributed solution as a tuple.

        :return:
            The full solution vector.
        """

        (dist_x_realger, dist_x_realung, dist_x_imagung,
         dist_x_imagger) = solution

        x_realger = dist_x_realger.get_full_vector()
        x_realung = dist_x_realung.get_full_vector()
        x_imagung = dist_x_imagung.get_full_vector()
        x_imagger = dist_x_imagger.get_full_vector()

        if self.rank == mpi_master():
            x_realger_full = np.hstack((x_realger, x_realger))
            x_realung_full = np.hstack((x_realung, -x_realung))
            x_imagung_full = np.hstack((x_imagung, -x_imagung))
            x_imagger_full = np.hstack((x_imagger, x_imagger))

            x_real = x_realger_full + x_realung_full
            x_imag = x_imagung_full + x_imagger_full
            return x_real + 1j * x_imag
        else:
            return None

    def print_iteration(self, relative_residual_norm, xvs):
        """
        Prints information of the iteration.

        :param relative_residual_norm:
            Relative residual norms.
        :param xvs:
            A list of tuples containing operator component, frequency, and
            property.
        """

        width = 92

        output_header = '*** Iteration:   {} '.format(self.cur_iter + 1)
        output_header += '* Residuals (Max,Min): '
        output_header += '{:.2e} and {:.2e}'.format(
            max(relative_residual_norm.values()),
            min(relative_residual_norm.values()))
        self.ostream.print_header(output_header.ljust(width))
        self.ostream.print_blank()

        output_header = 'Operator:  {} ({})'.format(self.b_operator,
                                                    self.b_components)
        self.ostream.print_header(output_header.ljust(width))
        self.ostream.print_blank()

        for op, freq, xv in xvs:
            ops_label = '<<{};{}>>_{:.4f}'.format(op, op, freq)
            rel_res = relative_residual_norm[(op, freq)]
            output_iter = '{:<15s}: {:15.8f} {:15.8f}j   '.format(
                ops_label, -xv.real, -xv.imag)
            output_iter += 'Residual Norm: {:.8f}'.format(rel_res)
            self.ostream.print_header(output_iter.ljust(width))
        self.ostream.print_blank()
        self.ostream.flush()
