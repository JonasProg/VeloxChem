# Define names for sphinx-api

from unittest.mock import Mock

AtomBasis = Mock()
BasisFunction = Mock()
OverlapIntegralsDriver = Mock()
KineticEnergyIntegralsDriver = Mock()
NuclearPotentialIntegralsDriver = Mock()
ElectricFieldIntegralsDriver = Mock()
ElectricDipoleIntegralsDriver = Mock()
LinearMomentumIntegralsDriver = Mock()
AngularMomentumIntegralsDriver = Mock()
ElectronRepulsionIntegralsDriver = Mock()
MolecularGrid = Mock()
GridDriver = Mock()
XCFunctional = Mock()
XCIntegrator = Mock()
SADGuessDriver = Mock()
DispersionModel = Mock()
TwoIndexes = Mock()
MOIntsBatch = Mock()
ExcitationVector = Mock()
DenseMatrix = Mock()
AOKohnShamMatrix = Mock()
XTBDriver = Mock()

mpi_master = Mock()
mpi_size_limit = Mock()
mpi_initialized = Mock()
mathconst_pi = Mock()
bohr_in_angstroms = Mock()
hartree_in_ev = Mock()
hartree_in_kcalpermol = Mock()
dipole_in_debye = Mock()
rotatory_strength_in_cgs = Mock()

denmat = Mock()
ericut = Mock()
molorb = Mock()
moints = Mock()
fockmat = Mock()
szblock = Mock()

assert_msg_critical = Mock()
get_dimer_ao_indices = Mock()
to_angular_momentum = Mock()
parse_xc_func = Mock()
ao_matrix_to_veloxchem = Mock()
ao_matrix_to_dalton = Mock()

Molecule = Mock()
MolecularBasis = Mock()
ChemicalElement = Mock()
AODensityMatrix = Mock()
AOFockMatrix = Mock()
MolecularOrbitals = Mock()
VisualizationDriver = Mock()
CubicGrid = Mock()
