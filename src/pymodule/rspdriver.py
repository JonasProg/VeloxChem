from .veloxchemlib import mpi_master
from .tdaexcidriver import TDAExciDriver
from .lrsolver import LinearResponseSolver
from .qqscheme import get_qq_type


class ResponseDriver:
    """Implements response driver.

    Implements response driver for molecular property calculations using
    conventional Hatree-Fock/Kohn-Sham response theory.

    rank
        The rank of MPI process.
    nodes
        The number of MPI processes.
    """

    def __init__(self, comm, ostream):
        """Initializes Response driver.

        Initializes Response driver to default setup.

        Parameters
        ----------
        comm
            The MPI communicator.
        ostream
            The output stream.
        """

        # calculation type
        self.prop_type = 'SINGEX_TDA'
        self.nstates = 3

        # solver settings
        self.conv_thresh = 1.0e-4
        self.max_iter = 50

        # ERI settings
        self.eri_thresh = 1.0e-15
        self.qq_type = 'QQ_DEN'

        # mpi information
        self.comm = comm
        self.rank = self.comm.Get_rank()
        self.nodes = self.comm.Get_size()

        # output stream
        self.ostream = ostream

    def update_settings(self, rsp_input):

        # calculation type
        if 'nstates' in rsp_input:
            self.nstates = int(rsp_input['nstates'])

        # solver settings
        if 'conv_thresh' in rsp_input:
            self.conv_thresh = float(rsp_input['conv_thresh'])
        if 'max_iter' in rsp_input:
            self.max_iter = int(rsp_input['max_iter'])

        # ERI settings
        if 'eri_thresh' in rsp_input:
            self.eri_thresh = float(rsp_input['eri_thresh'])
        if 'qq_type' in rsp_input:
            self.qq_type = rsp_input['qq_type'].upper()

        # properties
        if rsp_input['property'].lower() == 'polarizability':
            self.prop_type = 'POLARIZABILITY'
            self.a_ops, self.b_ops = rsp_input['operators']
            self.frequencies = rsp_input['frequencies']

        elif rsp_input['property'].lower() == 'absorption':
            self.prop_type = 'SINGEX_TDA'

    def compute(self, molecule, ao_basis, scf_tensors):
        """Performs molecular property calculation.

        Performs molecular property calculation using molecular data

        Parameters
        ----------
        molecule
            The molecule.
        ao_basis
            The AO basis set.
        scf_tensors
            The tensors from converged SCF wavefunction.
        """

        if self.rank == mpi_master():
            self.print_header()

        # TDA singlet/triplet excited states

        if self.prop_type.upper() in ["SINGEX_TDA", "TRIPEX_TDA"]:
            tda_exci = TDAExciDriver(self.comm, self.ostream)

            tda_exci.update_settings({
                'nstates': self.nstates,
                'spin': self.prop_type[0].upper(),
                'eri_thresh': self.eri_thresh,
                'qq_type': self.qq_type,
                'conv_thresh': self.conv_thresh,
                'max_iter': self.max_iter
            })

            return tda_exci.compute(molecule, ao_basis, scf_tensors)

        # Linear response solver

        if self.prop_type.upper() in ["POLARIZABILITY"]:
            lr_solver = LinearResponseSolver(self.comm, self.ostream)

            lr_solver.update_settings({
                'a_ops': self.a_ops,
                'b_ops': self.b_ops,
                'frequencies': self.frequencies,
                'eri_thresh': self.eri_thresh,
                'qq_type': self.qq_type,
                'conv_thresh': self.conv_thresh,
                'max_iter': self.max_iter
            })

            return lr_solver.compute(molecule, ao_basis, scf_tensors)

    def print_header(self):
        """Prints response driver setup header to output stream.

        Prints molecular property calculation setup details to output stream.
        """

        self.ostream.print_blank()
        self.ostream.print_header("Response Driver Setup")
        self.ostream.print_header(23 * "=")
        self.ostream.print_blank()

        str_width = 60

        cur_str = "Molecular Property Type   : " + self.prop_str()
        self.ostream.print_header(cur_str.ljust(str_width))

        if self.prop_type in ['SINGEX_TDA', 'TRIPEX_TDA']:
            cur_str = "Number Of Excited States  : " + str(self.nstates)
            self.ostream.print_header(cur_str.ljust(str_width))

        if self.prop_type in ['SINGEX_TDA', 'TRIPEX_TDA']:
            cur_str = "Response Equations Type   : Tamm-Dancoff"
            self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = "Max. Number Of Iterations : " + str(self.max_iter)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = "Convergence Threshold     : " + \
            "{:.1e}".format(self.conv_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))

        cur_str = "ERI screening scheme      : " + get_qq_type(self.qq_type)
        self.ostream.print_header(cur_str.ljust(str_width))
        cur_str = "ERI Screening Threshold   : " + \
            "{:.1e}".format(self.eri_thresh)
        self.ostream.print_header(cur_str.ljust(str_width))
        self.ostream.print_blank()

        self.ostream.flush()

    def prop_str(self):
        """Gets string with type of molecular property calculation.

        Gets string with type of molecular property calculation (Excited
        states, linear and non-linear spectroscopies).

        Returns
        -------
        The string with type of molecular property calculation.
        """

        if self.prop_type == "SINGEX_TDA":
            return "Singlet Excited States"

        if self.prop_type == "POLARIZABILITY":
            return "Polarizability"

        return "Undefined"
