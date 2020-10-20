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
        - filename: The filename that will be used by geomeTRIC.
        - grad_drv: The gradient driver.
        - flag: The type of the optimization driver.
    """

    def __init__(self, filename, grad_drv, flag):
        """
        Initializes optimization driver.
        """

        self.comm = grad_drv.comm
        self.rank = grad_drv.comm.Get_rank()
        self.ostream = grad_drv.ostream

        self.coordsys = 'tric'
        self.constraints = None
        self.check_interval = 0

        self.transition = False
        self.hessian = 'never'

        self.filename = filename
        self.grad_drv = grad_drv
        self.flag = flag

    def update_settings(self, opt_dict):
        """
        Updates settings in optimization driver.

        :param opt_dict:
            The input dictionary of optimize group.
        """

        if 'coordsys' in opt_dict:
            self.coordsys = opt_dict['coordsys'].lower()
        if 'constraints' in opt_dict:
            self.constraints = list(opt_dict['constraints'])
        if 'check_interval' in opt_dict:
            self.check_interval = int(opt_dict['check_interval'])

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
                                        self.grad_drv, self.flag)

        # filename is used by geomeTRIC to create .log and other files. On
        # master node filename is determined based on the input/output file.
        # On other nodes filename points to file in a temporary directory.

        with tempfile.TemporaryDirectory() as temp_dir:
            if self.rank == mpi_master():
                filename = self.filename
            else:
                filename = os.path.join(temp_dir, 'tmp_{:d}'.format(self.rank))

            if self.constraints is not None:
                constr_filename = filename + '_constr.txt'
                with open(constr_filename, 'w') as fh:
                    fh.write(os.linesep.join(self.constraints))
            else:
                constr_filename = None

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
                            constraints=constr_filename,
                            transition=self.transition,
                            hessian=self.hessian,
                            input=filename)

        coords = m.xyzs[-1] / geometric.nifty.bohr2ang
        labels = molecule.get_labels()

        if self.rank == mpi_master():
            final_mol = Molecule(labels, coords.reshape(-1, 3), units='au')
        else:
            final_mol = Molecule()
        final_mol.broadcast(self.rank, self.comm)

        if self.rank == mpi_master():
            self.print_scan_result()

        return final_mol

    def print_scan_result(self):

        scan_file = 'scan-final.xyz'

        self.ostream.print_blank()
        self.ostream.print_info('Summary of geometry scan:')

        if '$scan' in self.constraints and os.path.isfile(scan_file):
            with open(scan_file, 'r') as fh:
                while True:
                    line = fh.readline()
                    if not line:
                        break
                    natoms = int(line.split()[0])
                    line = fh.readline()
                    self.ostream.print_info(line.strip())
                    for i in range(natoms):
                        line = fh.readline()

        self.ostream.print_blank()
        self.ostream.flush()
