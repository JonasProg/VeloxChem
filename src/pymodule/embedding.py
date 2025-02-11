from io import StringIO
from contextlib import redirect_stdout
import numpy as np

from .veloxchemlib import (compute_electric_field_integrals,
                           compute_electric_field_values,
                           compute_electric_field_integrals_gradient)
from .oneeints import (compute_nuclear_potential_integrals,
                       compute_nuclear_potential_gradient_bfs,
                       compute_electrostatic_potential_hessian,
                       compute_electrostatic_integrals_gradient,
                       compute_electric_field_fock_gradient,
                       compute_electric_field_potential_gradient_for_mm)
from .errorhandler import assert_msg_critical

try:
    from pyframe.embedding import (read_input, electrostatic_interactions,
                                   induction_interactions,
                                   repulsion_interactions,
                                   dispersion_interactions)
    from pyframe.embedding.subsystem import ClassicalSubsystem, QuantumSubsystem
    from pyframe.simulation_box import SimulationBox
except ImportError:
    raise ImportError('Unable to import PyFraME. Please install PyFraME.')


class EmbeddingIntegralDriver:

    def __init__(self, molecule, ao_basis):

        self.molecule = molecule
        self.basis = ao_basis

    def multipole_potential_integrals(
            self, multipole_coordinates: np.ndarray,
            multipole_orders: np.ndarray,
            multipoles: list[np.ndarray]) -> np.ndarray:
        """Calculate the electronic potential integrals and multiply with the
        multipoles.

        Args:
            multipole_coordinates: Coordinates of the Multipoles.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            multipole_orders: Multipole orders of all multipoles.
                Shape: (number of atoms)
                Dtype: np.int64
            multipoles: Multipoles multiplied with degeneracy coefficients and
                        taylor coefficients.
                Shape: (number of atoms, number of multipole elements)
                Dtype: np.float64

        Returns:
            Product of electronic potential integrals and multipoles.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64
        """

        # if np.any(multipole_orders > 2):
        #     raise NotImplementedError("""Multipole potential integrals not
        #                                      implemented for order > 2.""")

        op = 0

        # 0 order
        idx = np.where(multipole_orders >= 0)[0]
        charge_coordinates = multipole_coordinates[idx]
        charges = np.array([multipoles[i][0] for i in idx])

        op += compute_nuclear_potential_integrals(
            molecule=self.molecule,
            basis=self.basis,
            coordinates=charge_coordinates,
            charges=charges)

        # 1 order
        if np.any(multipole_orders >= 1):
            idx = np.where(multipole_orders >= 1)[0]
            dipole_coordinates = multipole_coordinates[idx]
            dipoles = np.array([multipoles[i][1:4] for i in idx])

            op += compute_electric_field_integrals(self.molecule, self.basis,
                                                   dipole_coordinates, dipoles)

        return op

    def electronic_fields(self, coordinates: np.ndarray,
                          density_matrix: np.ndarray) -> np.ndarray:
        """Calculate the electronic fields on coordinates.

        Args:
            coordinates: Coordinates on which the fields are to be evaluated.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64

        Returns:
            Electronic fields.
                Shape: (number of atoms, 3)
                Dtype: np.float64.
        """

        return compute_electric_field_values(self.molecule, self.basis,
                                                    coordinates, density_matrix)


    def electronic_electrostatic_energy_gradients(self,
            multipole_coordinates: np.ndarray,
            multipole_orders: np.ndarray,
            multipoles: list[np.ndarray],
            density_matrix: np.ndarray) -> np.ndarray:
        """Calculate the electronic electrostatic energy gradients.

        Args:
            multipole_coordinates: Coordinates of the Multipoles.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            multipole_orders: Multipole orders of all multipoles.
                Shape: (number of atoms)
                Dtype: np.int64
            multipoles: Multipoles multiplied with degeneracy coefficients and
                        taylor coefficients.
                Shape: (number of atoms, number of multipole elements)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64

        Returns:
            Electronic electrostatic energy gradients.
                Shape: (number of nuclei, 3)
                Dtype: np.float64
        """
        op = 0
        # 0 order
        idx = np.where(multipole_orders >= 0)[0]
        charge_coordinates = multipole_coordinates[idx]
        charges = np.array([multipoles[i][0] for i in idx])

        op += compute_nuclear_potential_gradient_bfs(
            molecule=self.molecule,
            basis=self.basis,
            coordinates=charge_coordinates,
            charges=charges,
            density=density_matrix)
        return op


    def electronic_induction_energy_gradients(self,
                                             induced_dipoles:np.ndarray,
                                             coordinates: np.ndarray,
                                             density_matrix: np.ndarray) -> np.ndarray:
        """Calculate the electronic induction energy gradients.

        Args:
            induced_dipoles: Induced dipoles
                Shape (number of induced dipoles, 3)
                Dtype: np.float64
            coordinates: Coordinates on which the fields are to be evaluated.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64

        Returns:
            Electronic induction energy gradients.
                Shape: (number of nuclei, 3)
                Dtype: np.float64
        """

        return compute_electric_field_integrals_gradient(
            self.molecule, self.basis, coordinates, induced_dipoles, density_matrix)

    def electronic_induction_fock_gradient(self,
                                             induced_dipoles:np.ndarray,
                                             coordinates: np.ndarray,
                                             i: int) -> np.ndarray:
        """Calculate the electronic induction energy hessian.

        Args:
            induced_dipoles: Induced dipoles
                Shape (number of induced dipoles, 3)
                Dtype: np.float64
            coordinates: Coordinates on which the fields are to be evaluated.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            i: Index of nucleus "i".
                Shape: (1)
                Dtype: np.int64

        Returns:
            Electronic induction energy gradients.
                Shape: (number of nuclei, 3)
                Dtype: np.float64
        """
        return compute_electric_field_fock_gradient(molecule=self.molecule,
                                                    basis=self.basis,
                                                    dipole_coords=coordinates,
                                                    dipole_moments=induced_dipoles,
                                                    qm_atom_index=i)

    def induced_dipoles_potential_integrals(self,
                                            induced_dipoles: np.ndarray,
                                            coordinates: np.ndarray) -> np.ndarray:
        """Calculate the electronic potential integrals and contract with the
        induced dipoles of Atoms.

        Args:
            induced_dipoles: Induced dipoles
                Shape (number of induced dipoles, 3)
                Dtype: np.float64
            coordinates: Coordinates of the induced dipoles on which the
                         integrals are to be evaluated.
                Shape (number of induced dipoles, 3)
                Dtype: np.float64

        Returns:
            Product of the electronic potential integrals and the induced dipoles.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64
        """

        return compute_electric_field_integrals(self.molecule,
                                                self.basis,
                                                coordinates,
                                                induced_dipoles)

    def electronic_electrostatic_energy_hessian(self,
                                                   multipole_coordinates: np.ndarray,
                                                   multipole_orders: np.ndarray,
                                                   multipoles: list[np.ndarray],
                                                   density_matrix: np.ndarray,
                                                   nuc_i: int,
                                                   nuc_j: int
                                                   ):
        """Calculate the electronic electrostatic energy Hessian.

        Args:
            multipole_coordinates: Coordinates of the Multipoles.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            multipole_orders: Multipole orders of all multipoles.
                Shape: (number of atoms)
                Dtype: np.int64
            multipoles: Multipoles multiplied with degeneracy coefficients and
                        taylor coefficients.
                Shape: (number of atoms, number of multipole elements)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64
            nuc_i: Index of nucleus "i" corresponding to the Hessian indexing H_ij.
                Shape: (1)
                Dtype: np.int64
            nuc_j: Index of nucleus "j" corresponding to the Hessian indexing H_ij.
                Shape: (1)
                Dtype: np.int64
        Returns:
            Electronic electrostatic energy Hessian.
                Shape: (3,3)
                Dtype: np.float64
        """
        op = 0
        # 0 order
        idx = np.where(multipole_orders >= 0)[0]
        charge_coordinates = multipole_coordinates[idx]
        charges = np.array([multipoles[i][0] for i in idx])

        op += compute_electrostatic_potential_hessian(molecule=self.molecule,
                                                      basis=self.basis,
                                                      mm_coordinates=charge_coordinates,
                                                      mm_charges=charges,
                                                      density=density_matrix,
                                                      qm_atom_index_i=nuc_i,
                                                      qm_atom_index_j=nuc_j)
        return op

    def electronic_electrostatic_fock_gradient(self,
                                                multipole_coordinates: np.ndarray,
                                                multipole_orders: np.ndarray,
                                                multipoles: list[np.ndarray],
                                                i: int):
        """Calculate the electronic electrostatic fock gradient.

        Args:
            multipole_coordinates: Coordinates of the Multipoles.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            multipole_orders: Multipole orders of all multipoles.
                Shape: (number of atoms)
                Dtype: np.int64
            multipoles: Multipoles multiplied with degeneracy coefficients and
                        taylor coefficients.
                Shape: (number of atoms, number of multipole elements)
                Dtype: np.float64
            i: Index of nucleus "i".
                Shape: (1)
                Dtype: np.int64

        Returns:
            Electronic induction energy
        """
        op = 0
        # 0 order
        idx = np.where(multipole_orders >= 0)[0]
        charge_coordinates = multipole_coordinates[idx]
        charges = np.array([multipoles[i][0] for i in idx])
        op += compute_electrostatic_integrals_gradient(molecule=self.molecule,
                                                       basis=self.basis,
                                                       mm_charges=charges,
                                                       mm_coordinates=charge_coordinates,
                                                       qm_atom_index_i=i)
        return op

    def compute_electronic_field_gradients(self,
                                           coordinates: np.ndarray,
                                           density_matrix: np.ndarray,
                                           i: int):
        """Calculate the electronic field gradients on coordinates.

        Args:
            coordinates: Coordinates on which the fields are to be evaluated.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64
            i: Index of nucleus "i".
                Shape: (1)
                Dtype: np.int64

        Returns:
            Electronic field gradients.
                Shape: (3, number of atoms, 3)
                Dtype: np.float64.
        """
        return compute_electric_field_potential_gradient_for_mm(
            molecule=self.molecule,
            basis=self.basis,
            dipole_coords=coordinates,
            density=density_matrix,
            qm_atom_index=i
        )

    def electronic_fields(self, coordinates: np.ndarray,
                          density_matrix: np.ndarray) -> np.ndarray:
        """Calculate the electronic fields on coordinates.

        Args:
            coordinates: Coordinates on which the fields are to be evaluated.
                Shape: (number of atoms, 3)
                Dtype: np.float64
            density_matrix: Density Matrix that is the source of the electronic field.
                Shape: (number of ao functions, number of ao functions)
                Dtype: np.float64

        Returns:
            Electronic fields.
                Shape: (number of atoms, 3)
                Dtype: np.float64.
        """

        return compute_electric_field_values(self.molecule, self.basis,
                                                    coordinates, density_matrix)

class PolarizableEmbedding:
    """
    Implements the fragment-based polarizable embedding (PE) method.

    :param molecule: The molecule to be embedded.
    :param ao_basis: The AO basis set.
    :param options: Dictionary with settings and inputs.
        settings:
            - embedding_method: string to set embedding method.
            - vdw: dictionary with keys: method and combination_rule.
                - method
                - combination_rule
            - induced_dipoles: dictionary with keys: threshold, max_iterations,
                               and solver.
                - solver
                - threshold
                - max_iterations
                - mic
                - simulation_box
            - environment_energy: bool which decides if the environment energy
                                  will be calculated.
        inputs:
            - json_file: string that is the path to the json file that contains
                         the embedding potentials.
            - objects:
                - quantum_subsystem: PyFraME class subsystem.QuantumSubsystem.
                - classical_subsystem: PyFraME class subsystem.ClassicalSubsystem.
    :param comm: The MPI communicator.
    :param log_level: Sets the logging level to be used.

    Instance variables:
        - comm: The MPI communicator.
        - molecule: The molecule.
        - basis: The AO basis set.
        - options: Dictionary with the options and inputs.
        - quantum_subsystem: Instance of PyFraME QuantumSubsystem.
        - classical_subsystem: Instance of PyFraME ClassicalSubsystem.
        - simulation_box: Instance of PyFraME SimulationBox.
        - _integral_driver: Instance of EmbeddingIntegralDriver to calculate
                            all relevant integrals.
        - _e_induction: Induction energy.
        - _threshold: Threshold for solving induced dipoles.
        - _max_iterations: Maximum iterations for solving induced dipoles.
        - _solver: Solver method for induced dipoles.
        - _mic: Bool which decides if minimum-image convention (MIC) is used.
    """

    def __init__(self, molecule, ao_basis, options, comm=None, log_level=20):

        self.options = options

        assert_msg_critical(
            self.options['settings']['embedding_method'] == 'PE',
            'PolarizableEmbedding: Invalid embedding_method. Only PE is supported.'
        )

        self.comm = comm
        self.molecule = molecule
        self.basis = ao_basis

        self._integral_driver = EmbeddingIntegralDriver(molecule=self.molecule,
                                                        ao_basis=self.basis)
        self._create_pyframe_objects()
        self._e_induction = None

        induced_dipoles_options = self.options['settings'].get(
            'induced_dipoles', {})

        self._threshold = induced_dipoles_options.get('threshold', 1e-8)
        self._max_iterations = induced_dipoles_options.get(
            'max_iterations', 100)
        self._solver = induced_dipoles_options.get('solver', 'jidiis')
        self._mic = induced_dipoles_options.get('mic', True)
        # FIXME temporary update coords
        self.quantum_subsystem.coordinates = molecule.get_coordinates_in_bohr()

    def _create_pyframe_objects(self):
        def categorize_subsystems(reader_output):
            """Categorize components from the reader output tuple."""
            simulation_box = SimulationBox()
            quantum_subsystems = []
            classical_subsystems = []

            for item in reader_output:
                if isinstance(item, SimulationBox):
                    simulation_box = item
                elif isinstance(item, QuantumSubsystem):
                    quantum_subsystems.append(item)
                elif isinstance(item, ClassicalSubsystem):
                    classical_subsystems.append(item)
                else:
                    raise ValueError(f"Unexpected object type returned by reader: {type(item)}")

            return simulation_box, quantum_subsystems, classical_subsystems

        if "json_file" in self.options['inputs']:
            with redirect_stdout(StringIO()) as fg_out:
                reader_output = read_input.reader(
                    input_data=self.options['inputs']['json_file'],
                    comm=self.comm
                )
                simulation_box, quantum_subsystems, classical_subsystems = categorize_subsystems(reader_output)

                # Handle single or multiple quantum/classical subsystems
                self.simulation_box = simulation_box
                self.quantum_subsystem = quantum_subsystems if len(quantum_subsystems) > 1 else \
                quantum_subsystems[0] if quantum_subsystems else None
                self.classical_subsystem = classical_subsystems if len(classical_subsystems) > 1 else \
                classical_subsystems[0] if classical_subsystems else None

        elif "objects" in self.options['inputs']:
            # Directly use the provided objects
            self.simulation_box = self.options['inputs']['objects']['simulation_box']
            self.quantum_subsystem = self.options['inputs']['objects']['quantum_subsystem']
            self.classical_subsystem = self.options['inputs']['objects']['classical_subsystem']


class PolarizableEmbeddingSCF(PolarizableEmbedding):
    """
    Subclass for Self-Consistent Field (SCF) calculations with polarizable embedding.

    Instance variables:
        - e: Sum of PE contributions (E_rep + E_disp + E_ind + E_es).
        - v: Sum of PE Fock matrix contributions.
        - _e_es: Electrostatic energy.
        - vdw_method: The VDW method to be used.
        - vdw_combination_rule: The VDW combination rule to be used.
        - _f_elec_es: Electrostatic Fock matrix.
        - _e_nuc_es: Electrostatic nuclear energy.
        - _e_vdw: VDW energy.
        - _environment_energy: Interaction energy between multipoles in the
                               classical_subsystem.
    """

    def __init__(self, molecule, ao_basis, options, comm=None, log_level=20):

        super().__init__(molecule, ao_basis, options, comm, log_level)

        self._f_elec_es = electrostatic_interactions.es_fock_matrix_contributions(
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver)

        self._e_nuc_es = electrostatic_interactions.compute_electrostatic_nuclear_energy(
            quantum_subsystem=self.quantum_subsystem,
            classical_subsystem=self.classical_subsystem)

        vdw_options = self.options['settings'].get('vdw', {})
        self.vdw_method = vdw_options.get('method', 'LJ')
        self.vdw_combination_rule = vdw_options.get('combination_rule',
                                                    'Lorentz-Berthelot')

        if 'vdw' in self.options['settings']:
            self._e_vdw = repulsion_interactions.compute_repulsion_interactions(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)

            self._e_vdw += dispersion_interactions.compute_dispersion_interactions(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)

        else:
            self._e_vdw = 0.0

        self._environment_energy = (self.classical_subsystem.
                                    environment_energy(vdw_method=self.vdw_method,
                                                       vdw_combination_rule=self.vdw_combination_rule)
                                    if self.options['settings'].get(
                                        'environment_energy', False) else 0.0)

        self.pe_summary = None

    def compute_pe_contributions(self, density_matrix):

        if self._e_nuc_es is None:
            self._e_nuc_es = electrostatic_interactions.compute_electrostatic_nuclear_energy(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem)

        if self._f_elec_es is None:
            self._f_elec_es = electrostatic_interactions.es_fock_matrix_contributions(
                classical_subsystem=self.classical_subsystem,
                integral_driver=self._integral_driver)

        e_elec_es = np.sum(self._f_elec_es * density_matrix)

        el_fields = self.quantum_subsystem.compute_electronic_fields(
            coordinates=self.classical_subsystem.coordinates,
            density_matrix=density_matrix,
            integral_driver=self._integral_driver)

        nuc_fields = self.quantum_subsystem.compute_nuclear_fields(
            self.classical_subsystem.coordinates)

        self.classical_subsystem.solve_induced_dipoles(
            external_fields=(el_fields + nuc_fields),
            threshold=self._threshold,
            max_iterations=self._max_iterations,
            solver=self._solver,
            mic=self._mic,
            box=self.simulation_box.box)

        self._e_induction = induction_interactions.compute_induction_energy(
            induced_dipoles=self.classical_subsystem.induced_dipoles.
            induced_dipoles,
            total_fields=el_fields + nuc_fields +
            self.classical_subsystem.multipole_fields)

        f_elec_ind = induction_interactions.ind_fock_matrix_contributions(
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver)

        e_emb = self._e_induction + self._e_nuc_es + e_elec_es + self._e_vdw

        V_emb = self._f_elec_es - f_elec_ind

        self.pe_summary = []

        self.pe_summary.append(
            'Polarizable Embedding (PE) Energy Contributions')
        self.pe_summary.append('------------------------------------')

        self.pe_summary.append('Electrostatic Contribution         :' +
                               f'{self._e_nuc_es + e_elec_es:20.10f} a.u.')

        self.pe_summary.append('Induced Contribution               :' +
                               f'{self._e_induction:20.10f} a.u.')

        if self._e_vdw != 0.0:
            self.pe_summary.append('Van der Waals Contribution         :' +
                                   f'{self._e_vdw:20.10f} a.u.')

        if self._environment_energy != 0.0:
            self.pe_summary.append('Environment Contribution           :' +
                                   f'{self._environment_energy:20.10f} a.u.')

        self.pe_summary.append('------------------------------------')

        return e_emb, V_emb

    def get_pe_summary(self):

        return self.pe_summary


class PolarizableEmbeddingLRS(PolarizableEmbedding):
    """
    Subclass for Linear Response Solver (LRS) calculations with polarizable embedding.
    """

    def __init__(self, molecule, ao_basis, options, comm=None, log_level=20):

        super().__init__(molecule, ao_basis, options, comm, log_level)

    def compute_pe_contributions(self, density_matrix):

        el_fields = self.quantum_subsystem.compute_electronic_fields(
            coordinates=self.classical_subsystem.coordinates,
            density_matrix=density_matrix,
            integral_driver=self._integral_driver)

        self.classical_subsystem.solve_induced_dipoles(
            external_fields=el_fields,
            threshold=self._threshold,
            max_iterations=self._max_iterations,
            solver=self._solver,
            exclude_static_internal_fields=True,
            mic=self._mic,
            box=self.simulation_box.box)

        f_elec_ind = induction_interactions.ind_fock_matrix_contributions(
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver)

        return -1.0 * f_elec_ind

class PolarizableEmbeddingGrad(PolarizableEmbedding):
    """
    Subclass for Gradient (Grad) calculations utilizing polarizable embedding.
    """

    def __init__(self, molecule, ao_basis, options, comm=None, log_level=20):
        super().__init__(molecule, ao_basis, options, comm, log_level)
        # TODO read in from options gradient specific options?
        self._e_es_nuc_grad = electrostatic_interactions.compute_electrostatic_nuclear_gradients(
            quantum_subsystem=self.quantum_subsystem,
            classical_subsystem=self.classical_subsystem)
        self._nuc_field_grad = self.quantum_subsystem.compute_nuclear_field_gradients(
            coordinates=self.classical_subsystem.coordinates)
        vdw_options = self.options['settings'].get('vdw', {})
        self.vdw_method = vdw_options.get('method', 'LJ')
        self.vdw_combination_rule = vdw_options.get('combination_rule',
                                                    'Lorentz-Berthelot')

        if 'vdw' in self.options['settings']:
            self._e_vdw_grad = repulsion_interactions.compute_repulsion_interactions_gradient(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)

            self._e_vdw_grad += dispersion_interactions.compute_dispersion_interactions_gradient(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)
        else:
            self._e_vdw_grad = 0.0

    def compute_pe_contributions(self, density_matrix):
        # FIXME -> ind dipoles only necessary if not passed from scf results
        # usecase call gradients several times? -> yes different geometries though -> guess of recalculation of ind dipoles from previous set of ind dipoles -> DIIS scheme
        if np.all(self.classical_subsystem.induced_dipoles.induced_dipoles == 0):
            el_fields = self.quantum_subsystem.compute_electronic_fields(
                coordinates=self.classical_subsystem.coordinates,
                density_matrix=density_matrix,
                integral_driver=self._integral_driver)

            nuc_fields = self.quantum_subsystem.compute_nuclear_fields(
                self.classical_subsystem.coordinates)

            self.classical_subsystem.solve_induced_dipoles(
                external_fields=(el_fields + nuc_fields),
                threshold=self._threshold,
                max_iterations=self._max_iterations,
                solver=self._solver,
                mic=self._mic,
                box=self.simulation_box.box)
        e_es_elec_grad = electrostatic_interactions.compute_electronic_electrostatic_energy_gradients(
            density_matrix=density_matrix,
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver)
        e_ind_el_grad = induction_interactions.compute_electronic_induction_energy_gradients(
            density_matrix=density_matrix,
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver)
        e_ind_nuc_grad = induction_interactions.compute_induction_energy_gradient(
            induced_dipoles=self.classical_subsystem.induced_dipoles.induced_dipoles,
            total_field_gradients=self._nuc_field_grad)

        return self._e_es_nuc_grad + e_ind_nuc_grad + e_ind_el_grad + self._e_vdw_grad + e_es_elec_grad


class PolarizableEmbeddingHess(PolarizableEmbedding):
    """
    Subclass for Hessian (Hess) calculations utilizing polarizable embedding.
    """

    def __init__(self, molecule, ao_basis, options, comm=None, log_level=20):
        super().__init__(molecule, ao_basis, options, comm, log_level)
        self._e_es_nuc_hess = electrostatic_interactions.compute_electrostatic_nuclear_hessian(
            quantum_subsystem=self.quantum_subsystem,
            classical_subsystem=self.classical_subsystem)
        self._nuc_field_hess = self.quantum_subsystem.compute_nuclear_field_gradients(
            coordinates=self.classical_subsystem.coordinates)
        vdw_options = self.options['settings'].get('vdw', {})
        self.vdw_method = vdw_options.get('method', 'LJ')
        self.vdw_combination_rule = vdw_options.get('combination_rule',
                                                    'Lorentz-Berthelot')

        if 'vdw' in self.options['settings']:
            self._e_vdw_hess = repulsion_interactions.compute_repulsion_interactions_hessian(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)

            self._e_vdw_hess += dispersion_interactions.compute_dispersion_interactions_hessian(
                quantum_subsystem=self.quantum_subsystem,
                classical_subsystem=self.classical_subsystem,
                method=self.vdw_method,
                combination_rule=self.vdw_combination_rule)
        else:
            self._e_vdw_hess = 0.0

    def compute_pe_fock_gradient_contributions(self, i):

        es_fock_grad = electrostatic_interactions.compute_electronic_electrostatic_fock_gradient(
            i=i,
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver
        )

        ind_fock_grad = induction_interactions.compute_electronic_induction_fock_gradient(
            i=i,
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver
        )
        return es_fock_grad + ind_fock_grad

    def compute_pe_energy_hess_contributions(self, density_matrix):
        nuc_list = np.arange(self.quantum_subsystem.num_nuclei, dtype=np.int64)
        e_es_elec_hess = electrostatic_interactions.compute_electronic_electrostatic_energy_hessian(
            nuc_list=nuc_list,
            density_matrix=density_matrix,
            classical_subsystem=self.classical_subsystem,
            integral_driver=self._integral_driver
            )
        e_es_nuc_hess = electrostatic_interactions.compute_electrostatic_nuclear_hessian(
            quantum_subsystem=self.quantum_subsystem,
            classical_subsystem= self.classical_subsystem)
        e_ind_hess = induction_interactions.compute_electronic_induction_energy_hessian(
            density_matrix=density_matrix,
            classical_subsystem=self.classical_subsystem,
            quantum_subsystem=self.quantum_subsystem,
            integral_driver=self._integral_driver,
            threshold=self._threshold,
            max_iterations=self._max_iterations,
            mic=self._mic,
            box=self.simulation_box.box,
            solver=self._solver
            )
        return e_es_elec_hess + e_es_nuc_hess + e_ind_hess + self._e_vdw_hess
