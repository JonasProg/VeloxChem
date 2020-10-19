import os
import sys
import tempfile
import contextlib
import geometric

from .veloxchemlib import mpi_master
from .molecule import Molecule
from .optimizationengine import OptimizationEngine


class OptimizationDriver:
    """
    Implements optimization driver.

    :param comm:
        The MPI communicator.
    :param ostream:
        The output stream.

    Instance variables
        - rank: The rank of MPI process.
        - coordsys: The coordinate system.
        - constraints: The constraints.
        - check_interval: The interval (number of steps) for checking
          coordinate system.
        - transition: The flag for transition state searching.
        - hessian: The flag for computing Hessian.
        - input_filename: The input filename.
        - energy_driver: The energy driver.
        - gradient_driver: The gradient driver.
        - flag: The type of the optimization driver.
    """

    def __init__(self, comm, ostream, inp_fname, ener_drv, grad_drv, flag):
        """
        Initializes optimization driver.
        """

        self.comm = comm
        self.rank = comm.Get_rank()
        self.ostream = ostream

        self.coordsys = 'tric'
        self.check_interval = 0
        self.constraints = None

        self.transition = False
        self.hessian = 'never'

        self.input_filename = inp_fname
        self.energy_driver = ener_drv
        self.gradient_driver = grad_drv
        self.flag = flag

    def update_settings(self, opt_dict):
        """
        Updates settings in optimization driver.

        :param opt_dict:
            The input dictionary of optimize group.
        :param scf_dict:
            The input dictionary of scf group.
        :param method_dict:
            The input dicitonary of method settings group.
        """

        if 'coordsys' in opt_dict:
            self.coordsys = opt_dict['coordsys'].lower()
        if 'check_interval' in opt_dict:
            self.check_interval = int(opt_dict['check_interval'])
        if 'constraints' in opt_dict:
            self.constraints = opt_dict['constraints']

        if 'transition' in opt_dict:
            key = opt_dict['transition'].lower()
            self.transition = True if key == 'yes' else False

        if 'hessian' in opt_dict:
            self.hessian = opt_dict['hessian'].lower()
        elif self.transition:
            self.hessian = 'first'

    def compute(self, molecule, ao_basis, min_basis=None):
        """
        Performs geometry optimization.

        :param molecule:
            The molecule.
        :param ao_basis:
            The AO basis set.
        :param min_basis:
            The minimal AO basis set.

        :return:
            The molecule with final geometry.
        """

        opt_engine = OptimizationEngine(molecule, ao_basis, min_basis,
                                        self.energy_driver,
                                        self.gradient_driver, self.flag)

        # input_fname is used by geomeTRIC to create .log and other files. On
        # master node input_fname is determined based on the checkpoint file.
        # On other nodes input_fname points to file in a temporary directory.

        if self.rank == mpi_master():
            suffix = '.inp'
            if self.input_filename[-len(suffix):] == suffix:
                input_fname = self.input_filename[:-len(suffix)]
            else:
                input_fname = self.input_filename

        with tempfile.TemporaryDirectory() as temp_dir:

            if self.rank != mpi_master():
                input_fname = os.path.join(temp_dir,
                                           'tmp_{:d}'.format(self.rank))

            # geomeTRIC prints information to stdout and stderr. On master node
            # this is redirected to the output stream. On other nodes this is
            # redirected to os.devnull.

            with open(os.devnull, 'w') as devnull:

                if self.rank == mpi_master():
                    fh = sys.stdout
                else:
                    fh = devnull

                with contextlib.redirect_stdout(fh):
                    with contextlib.redirect_stderr(fh):
                        m = geometric.optimize.run_optimizer(
                            customengine=opt_engine,
                            coordsys=self.coordsys,
                            check=self.check_interval,
                            constraints=self.constraints,
                            transition=self.transition,
                            hessian=self.hessian,
                            input=input_fname)

        coords = m.xyzs[-1] / geometric.nifty.bohr2ang
        labels = molecule.get_labels()

        if self.rank == mpi_master():
            final_mol = Molecule(labels, coords.reshape(-1, 3), units='au')
        else:
            final_mol = Molecule()
        final_mol.broadcast(self.rank, self.comm)

        return final_mol
