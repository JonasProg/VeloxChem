#
#                              VELOXCHEM
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2024 by VeloxChem developers. All rights reserved.
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

# C++ classes
from .veloxchemlib import Point
from .veloxchemlib import BasisFunction
from .veloxchemlib import AtomBasis
from .veloxchemlib import GtoBlock
from .veloxchemlib import GtoPairBlock
from .veloxchemlib import BlockedGtoPairBlock
from .veloxchemlib import OverlapDriver
from .veloxchemlib import KineticEnergyDriver
from .veloxchemlib import NuclearPotentialDriver
from .veloxchemlib import NuclearPotentialErfDriver
from .veloxchemlib import ElectricDipoleMomentDriver
from .veloxchemlib import OverlapGeom100Driver
from .veloxchemlib import OverlapGeom200Driver
from .veloxchemlib import OverlapGeom101Driver
from .veloxchemlib import KineticEnergyGeom100Driver
from .veloxchemlib import KineticEnergyGeom200Driver
from .veloxchemlib import KineticEnergyGeom101Driver
from .veloxchemlib import NuclearPotentialGeom010Driver
from .veloxchemlib import NuclearPotentialGeom020Driver
from .veloxchemlib import NuclearPotentialGeom100Driver
from .veloxchemlib import NuclearPotentialGeom200Driver
from .veloxchemlib import NuclearPotentialGeom110Driver
from .veloxchemlib import NuclearPotentialGeom101Driver
from .veloxchemlib import ElectricDipoleMomentGeom100Driver
from .veloxchemlib import T4CScreener
from .veloxchemlib import AODensityMatrix
from .veloxchemlib import FockGeom1000Driver

# C++ functions
from .veloxchemlib import upper_case
from .veloxchemlib import lower_case
from .veloxchemlib import pi_value
from .veloxchemlib import bohr_in_angstrom
from .veloxchemlib import hartree_in_ev
from .veloxchemlib import is_chemical_element
from .veloxchemlib import chemical_element_name
from .veloxchemlib import chemical_element_label
from .veloxchemlib import chemical_element_identifier
from .veloxchemlib import chemical_element_mass
from .veloxchemlib import chemical_element_max_angular_momentum
from .veloxchemlib import chemical_element_max_identifier
from .veloxchemlib import tensor_cartesian_labels
from .veloxchemlib import tensor_spherical_labels
from .veloxchemlib import tensor_cartesian_index
from .veloxchemlib import tensor_label
from .veloxchemlib import tensor_order
from .veloxchemlib import number_of_cartesian_components
from .veloxchemlib import number_of_spherical_components
from .veloxchemlib import make_gto_blocks
from .veloxchemlib import make_gto_pair_blocks
from .veloxchemlib import make_matrix
from .veloxchemlib import make_matrices
from .veloxchemlib import number_of_batches
from .veloxchemlib import batch_range
from .veloxchemlib import set_number_of_threads
from .veloxchemlib import get_number_of_threads
from .veloxchemlib import make_work_tasks
from .veloxchemlib import make_diag_work_tasks
from .veloxchemlib import make_work_group
from .veloxchemlib import partition_atoms
from .veloxchemlib import spherical_momentum_s_factors
from .veloxchemlib import spherical_momentum_p_factors
from .veloxchemlib import spherical_momentum_d_factors
from .veloxchemlib import spherical_momentum_f_factors
from .veloxchemlib import spherical_momentum_g_factors
from .veloxchemlib import mpi_master

# C++ enums
from .veloxchemlib import mat_t

# Python functions
from .errorhandler import assert_msg_critical

# Python classes
from .inputparser import InputParser
from .outputstream import OutputStream
from .submatrix import SubMatrix
from .matrix import Matrix
from .matrices import Matrices
from .molecule import Molecule
from .molecularbasis import MolecularBasis
from .molecularorbitals import MolecularOrbitals, molorb
from .fockdriver import FockDriver
from .scfrestdriver import ScfRestrictedDriver
from .scfunrestdriver import ScfUnrestrictedDriver
from .scfrestopendriver import ScfRestrictedOpenDriver
from .lrsolver import LinearResponseSolver
from .lreigensolver import LinearResponseEigenSolver
from .tdaeigensolver import TdaEigenSolver
from .cppsolver import ComplexResponse
from .c6driver import C6Driver
from .moleculargradientdriver import MolecularGradientDriver
from .scfgradientdriver import ScfGradientDriver

# Environment variable: basis set path, number of OpenMP threads, MKL linking
from .environment import (set_vlxbasispath, set_omp_num_threads, get_basis_path,
                          configure_mkl_rt)

set_vlxbasispath()
set_omp_num_threads()
configure_mkl_rt()

__version__ = "1.0rc3"
