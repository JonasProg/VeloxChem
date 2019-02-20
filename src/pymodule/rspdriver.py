from .veloxchemlib import ElectronRepulsionIntegralsDriver
from .veloxchemlib import MolecularOrbitals
from .veloxchemlib import ScreeningContainer
from .veloxchemlib import mpi_master
from .veloxchemlib import ericut
from .veloxchemlib import molorb

from .qqscheme import get_qq_type
from .qqscheme import get_qq_scheme

import numpy as np
import time as tm
import math

class ResponseDriver:
    """Implements response driver.
        
    Implements response driver for molecular property calculations using
    conventional Hatree-Fock/Kohn-Sham response theory.
    
    rank
        The rank of MPI process.
    nodes
        The number of MPI processes.
    """

    def __init__(self):
        """Initializes Response driver.
            
        Initializes Response driver to default setup.
        """
        
        # convergence information
        self.max_iter = 50
        
        # screening scheme
        self.qq_type = "QQ_DEN"
        
        # thresholds
        self.conv_thresh = 1.0e-4
        self.eri_thresh  = 1.0e-15
        
        # mpi information
        self.rank = 0
        self.nodes = 1
    
    def compute_task(self, mol_orbs, task):
        """Performs molecular propery calculation using response theory.
            
        Performs molecular property calculation using data from MPI task.
            
        Parameters
        ----------
        mol_orbs
            The molecular orbitals.
        task
            The response input data as MPI task.
        """

        self.compute(mol_orbs, task.molecule, task.ao_basis, task.mpi_comm,
                     task.ostream)
    
    def compute(self, mol_orbs, molecule, ao_basis, comm, ostream):
        """Performs SCF calculation.
            
        Performs molecular property calculation using molecular data, MPI
        communicator and output stream.
        
        Parameters
        ----------
        mol_orbs
            The molecular orbitals.
        molecule
            The molecule.
        ao_basis
            The AO basis set.
        min_basis
            The minimal AO basis set.
        comm
            The MPI communicator.
        ostream
            The output stream.
        """
        
        self.rank = comm.Get_rank()
        self.nodes = comm.Get_size()
        
        if self.rank == mpi_master():
            self.print_header(ostream)

        # compute eri's screening factors
        
        eri_drv = ElectronRepulsionIntegralsDriver(self.rank, self.nodes, comm)
    
        qq_data = eri_drv.compute(get_qq_scheme(self.qq_type), self.eri_thresh,
                                  molecule, ao_basis)

    def print_header(self, ostream):
        """Prints response driver setup header to output stream.
            
        Prints molecular property calculation setup details to output stream.
        
        Parameters
        ----------
        ostream
            The output stream.
        """
    
        ostream.print_blank()
        ostream.print_header("Response Driver Setup")
        ostream.print_header(23 * "=")
        ostream.print_blank()
        
        str_width = 80
       
        cur_str = "Max. Number Of Iterations    : " + str(self.max_iter)
        ostream.print_header(cur_str.ljust(str_width))
        cur_str = "Convergence Threshold        : " + \
            "{:.1e}".format(self.conv_thresh)
        ostream.print_header(cur_str.ljust(str_width))

        cur_str = "ERI screening scheme         : " + get_qq_type(self.qq_type)
        ostream.print_header(cur_str.ljust(str_width))
        cur_str = "ERI Screening Threshold      : " + \
            "{:.1e}".format(self.eri_thresh)
        ostream.print_header(cur_str.ljust(str_width))





