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
from datetime import datetime, timedelta

from .veloxchemlib import mpi_initialized, mpi_master
from .mpitask import MpiTask
from .scfrestdriver import ScfRestrictedDriver
from .scfunrestdriver import ScfUnrestrictedDriver
from .scfrestopendriver import ScfRestrictedOpenDriver
from .firstorderprop import FirstOrderProperties
from .respchargesdriver import RespChargesDriver
from .excitondriver import ExcitonModelDriver
from .mp2driver import Mp2Driver
from .loprop import LoPropDriver
from .trajectorydriver import TrajectoryDriver
from .optimizationdriver import OptimizationDriver
from .pulsedrsp import PulsedResponse
from .rsppolarizability import Polarizability
from .rspabsorption import Absorption
from .rsplinabscross import LinearAbsorptionCrossSection
from .rspcdspec import CircularDichroismSpectrum
from .rspc6 import C6
from .rspshg import SHG
from .rsptpa import TPA
from .scfgradientdriver import ScfGradientDriver
from .tdhfgradientdriver import TdhfGradientDriver
from .scfhessiandriver import ScfHessianDriver
from .tdhfhessiandriver import TdhfHessianDriver
from .cphfsolver import CphfSolver
from .rspcustomproperty import CustomProperty
from .visualizationdriver import VisualizationDriver
from .xtbdriver import XTBDriver
from .xtbgradientdriver import XTBGradientDriver
from .cli import cli
from .errorhandler import assert_msg_critical
from .slurminfo import get_slurm_end_time


def select_scf_driver(task, scf_type):
    """
    Selects SCF driver.

    :param task:
        The MPI task.
    :param scf_type:
        The type of SCF calculation (restricted, unrestricted, or
        restricted_openshell).

    :return:
        The SCF driver object.
    """

    # check number of MPI nodes
    if task.mpi_rank == mpi_master():
        n_ao = task.ao_basis.get_dimensions_of_basis(task.molecule)
        assert_msg_critical(task.mpi_size == 1 or task.mpi_size <= n_ao,
                            'SCF: too many MPI processes')

    nalpha = task.molecule.number_of_alpha_electrons()
    nbeta = task.molecule.number_of_beta_electrons()

    if scf_type == 'restricted' and nalpha == nbeta:
        scf_drv = ScfRestrictedDriver(task.mpi_comm, task.ostream)
    elif scf_type == 'restricted' and nalpha != nbeta:
        scf_drv = ScfUnrestrictedDriver(task.mpi_comm, task.ostream)
    elif scf_type == 'unrestricted':
        scf_drv = ScfUnrestrictedDriver(task.mpi_comm, task.ostream)
    elif scf_type == 'restricted_openshell':
        scf_drv = ScfRestrictedOpenDriver(task.mpi_comm, task.ostream)
    else:
        assert_msg_critical(False, f'SCF: invalide scf_type {scf_type}')

    return scf_drv


def select_rsp_property(task, mol_orbs, rsp_dict, method_dict):
    """
    Selects response property.

    :param task:
        The MPI task.
    :param mol_orbs:
        The molecular orbitals.
    :param rsp_dict:
        The dictionary of response input.
    :param method_dict:
        The dictionary of method settings.

    :return:
        The response property object.
    """

    # check number of MPI nodes
    if task.mpi_rank == mpi_master():
        nocc = task.molecule.number_of_alpha_electrons()
        n_ov = nocc * (mol_orbs.number_mos() - nocc)
        assert_msg_critical(task.mpi_size == 1 or task.mpi_size <= n_ov,
                            'Response: too many MPI processes')

    # check property type
    if 'property' in rsp_dict:
        prop_type = rsp_dict['property'].lower()
    else:
        prop_type = 'custom'

    if prop_type in [
            'polarizability',
            'dipole polarizability',
    ]:
        rsp_prop = Polarizability(rsp_dict, method_dict)

    elif prop_type in [
            'absorption',
            'uv-vis',
            'ecd',
    ]:
        rsp_prop = Absorption(rsp_dict, method_dict)

    elif prop_type in [
            'linear absorption cross-section',
            'linear absorption (cpp)',
            'absorption (cpp)',
    ]:
        rsp_prop = LinearAbsorptionCrossSection(rsp_dict, method_dict)

    elif prop_type in [
            'circular dichroism spectrum',
            'circular dichroism (cpp)',
            'ecd (cpp)',
    ]:
        rsp_prop = CircularDichroismSpectrum(rsp_dict, method_dict)

    elif prop_type == 'c6':
        rsp_prop = C6(rsp_dict, method_dict)

    elif prop_type == 'tpa':
        rsp_prop = TPA(rsp_dict, method_dict)

    elif prop_type == 'shg':
        rsp_prop = SHG(rsp_dict, method_dict)

    elif prop_type == 'custom':
        rsp_prop = CustomProperty(rsp_dict, method_dict)

    else:
        assert_msg_critical(
            False, f'Response: invalide response property {prop_type}')

    return rsp_prop


def updated_dict_with_eri_settings(settings_dict, scf_drv):
    """
    Returns an updated dictionary with ERI settings from SCF driver.

    :param settings_dict:
        The original dictionary of settings.
    :param scf_drv:
        The SCF driver.

    :return:
        An updated dictionary with updated ERI settings.
    """

    new_dict = dict(settings_dict)

    if 'eri_thresh' not in new_dict:
        new_dict['eri_thresh'] = scf_drv.eri_thresh
    if 'qq_type' not in new_dict:
        new_dict['qq_type'] = scf_drv.qq_type
    if not scf_drv.restart:
        new_dict['restart'] = 'no'

    return new_dict


def main():
    """
    Runs VeloxChem with command line arguments.
    """

    program_start_time = datetime.now()

    assert_msg_critical(mpi_initialized(), "MPI not initialized")

    # Parse command line

    parser = cli()
    args = parser.parse_args()

    # MPI task

    task = MpiTask([args.input_file, args.output_file], MPI.COMM_WORLD)
    task_type = task.input_dict['jobs']['task'].lower()

    # Timelimit

    if 'maximum_hours' in task.input_dict['jobs']:
        maximum_hours = float(task.input_dict['jobs']['maximum_hours'])
        program_end_time = program_start_time + timedelta(hours=maximum_hours)
    else:
        if task.mpi_rank == mpi_master():
            program_end_time = get_slurm_end_time()
        else:
            program_end_time = None
        program_end_time = task.mpi_comm.bcast(program_end_time,
                                               root=mpi_master())

    # Method settings
    # Note: the @pe group is added to method_dict as pe_options

    method_dict = (dict(task.input_dict['method_settings'])
                   if 'method_settings' in task.input_dict else {})

    method_dict['pe_options'] = (dict(task.input_dict['pe'])
                                 if 'pe' in task.input_dict else {})

    use_xtb = ('xtb' in method_dict)

    # Exciton model

    if task_type == 'exciton':
        exciton_dict = (task.input_dict['exciton']
                        if 'exciton' in task.input_dict else {})

        exciton_dict['program_end_time'] = program_end_time
        exciton_dict['filename'] = task.input_dict['filename']

        exciton_drv = ExcitonModelDriver(task.mpi_comm, task.ostream)
        exciton_drv.update_settings(exciton_dict, method_dict)
        exciton_drv.compute(task.molecule, task.ao_basis, task.min_basis)

    # Spectrum from trajectory

    if task_type == 'trajectory':
        traj_dict = (dict(task.input_dict['trajectory'])
                     if 'trajectory' in task.input_dict else {})
        spect_dict = (dict(task.input_dict['spectrum_settings'])
                      if 'spectrum_settings' in task.input_dict else {})
        rsp_dict = (dict(task.input_dict['response'])
                    if 'response' in task.input_dict else {})

        traj_dict['filename'] = task.input_dict['filename']
        traj_dict['charges'] = task.input_dict['charges']
        traj_dict['polarizabilities'] = task.input_dict['polarizabilities']

        traj_drv = TrajectoryDriver(task.mpi_comm, task.ostream)
        traj_drv.update_settings(traj_dict, spect_dict, rsp_dict, method_dict)
        traj_drv.compute(task.molecule, task.ao_basis, task.min_basis)

    # Self-consistent field

    run_scf = task_type in [
        'hf', 'rhf', 'uhf', 'rohf', 'scf', 'uscf', 'roscf', 'wavefunction',
        'wave function', 'mp2', 'gradient', 'optimize', 'response', 'pulses',
        'visualization', 'loprop', 'frequencies', 'freq', 'cphf'
    ]

    if task_type == 'visualization' and 'visualization' in task.input_dict:
        run_scf = 'read_dalton' not in task.input_dict['visualization']['cubes']

    scf_type = 'restricted'
    if task_type in ['uhf', 'uscf']:
        scf_type = 'unrestricted'
    elif task_type in ['rohf', 'roscf']:
        scf_type = 'restricted_openshell'

    if run_scf:
        assert_msg_critical(task.molecule.number_of_atoms(),
                            'Molecule: no atoms found in molecule')

        scf_dict = task.input_dict['scf'] if 'scf' in task.input_dict else {}

        scf_dict['program_end_time'] = program_end_time
        scf_dict['filename'] = task.input_dict['filename']

        if use_xtb:
            if 'potfile' in method_dict:
                errmsg = 'XTBDriver: The \'potfile\' keyword is not supported '
                errmsg += 'in XTB calculation.'
                if task.mpi_rank == mpi_master():
                    assert_msg_critical(False, errmsg)
            xtb_drv = XTBDriver(task.mpi_comm)
            xtb_drv.set_method(method_dict['xtb'].lower())
            xtb_drv.compute(task.molecule, task.ostream)
        else:
            scf_drv = select_scf_driver(task, scf_type)
            scf_drv.update_settings(scf_dict, method_dict)
            scf_drv.compute(task.molecule, task.ao_basis, task.min_basis)

            mol_orbs = scf_drv.mol_orbs
            density = scf_drv.density
            scf_tensors = scf_drv.scf_tensors

            if not scf_drv.is_converged:
                return

            # SCF first-order properties
            scf_prop = FirstOrderProperties(task.mpi_comm, task.ostream)
            if task.mpi_rank == mpi_master():
                total_density = scf_tensors['D_alpha'] + scf_tensors['D_beta']
            else:
                total_density = None
            scf_prop.compute(task.molecule, task.ao_basis, total_density)
            if task.mpi_rank == mpi_master():
                scf_prop.print_properties(task.molecule)

            if (scf_drv.electric_field is not None and
                    task.molecule.get_charge() != 0):
                task.finish()
                return

    # Gradient

    if task_type == 'gradient':
        if use_xtb:
            grad_drv = XTBGradientDriver(xtb_drv, task.mpi_comm, task.ostream)
            grad_drv.compute(task.molecule)
        elif scf_drv.scf_type == 'restricted':
            if 'gradient' in task.input_dict:
                grad_dict = task.input_dict['gradient']
            else:
                grad_dict = {}
            grad_drv = ScfGradientDriver(scf_drv, task.mpi_comm, task.ostream)
            grad_drv.update_settings(grad_dict, method_dict)
            grad_drv.compute(task.molecule, task.ao_basis, task.min_basis)

    # Geometry optimization

    if task_type == 'optimize':
        if 'potfile' in method_dict:
            errmsg = 'OptimizationDriver: The \'potfile\' keyword is not '
            errmsg += 'supported in geometry optimization.'
            if task.mpi_rank == mpi_master():
                assert_msg_critical(False, errmsg)

        opt_dict = (task.input_dict['optimize']
                    if 'optimize' in task.input_dict else {})

        opt_dict['filename'] = task.input_dict['filename']

        if use_xtb:
            grad_drv = XTBGradientDriver(xtb_drv, task.mpi_comm, task.ostream)
            opt_drv = OptimizationDriver(grad_drv, 'XTB')
        elif scf_drv.scf_type == 'restricted':
            grad_drv = ScfGradientDriver(scf_drv, task.mpi_comm, task.ostream)
            opt_drv = OptimizationDriver(grad_drv, 'SCF')

        opt_drv.update_settings(opt_dict)
        opt_drv.compute(task.molecule, task.ao_basis, task.min_basis)

    # Ground state Hessian / Vibrational analysis

    if task_type in ['freq', 'frequencies']:

        if 'frequencies' in task.input_dict:
            freq_dict = task.input_dict['frequencies']
        else:
            freq_dict = {}

        hessian_drv = ScfHessianDriver(scf_drv, task.mpi_comm, task.ostream)
        hessian_drv.update_settings(method_dict, freq_dict)
        hessian_drv.compute(task.molecule, task.ao_basis)
        # TODO: add output file name for geomeTRIC vibrational analysis
        hessian_drv.vibrational_analysis(task.molecule, task.ao_basis)

    # TODO: maybe remove (this was included for testing the MPI-parallelization)
    if task_type in ['cphf']:
        if 'cphf_settings' in task.input_dict:
            cphf_dict = task.input_dict['cphf_settings']
        else:
            cphf_dict = {}

        cphf_drv = CphfSolver(task.mpi_comm, task.ostream)
        cphf_drv.update_settings(cphf_dict, method_dict)
        cphf_drv.compute(task.molecule, task.ao_basis, scf_drv.scf_tensors) 
    

    # Response

    if task_type == 'response' and scf_drv.scf_type == 'restricted':
        rsp_dict = (dict(task.input_dict['response'])
                    if 'response' in task.input_dict else {})

        rsp_dict['program_end_time'] = program_end_time
        rsp_dict['filename'] = task.input_dict['filename']

        rsp_dict = updated_dict_with_eri_settings(rsp_dict, scf_drv)

        rsp_prop = select_rsp_property(task, mol_orbs, rsp_dict, method_dict)
        rsp_prop.init_driver(task.mpi_comm, task.ostream)
        rsp_prop.compute(task.molecule, task.ao_basis, scf_tensors)
        if not rsp_prop.converged():
            return

        if task.mpi_rank == mpi_master():
            rsp_prop.print_property(task.ostream)

        # Calculate the excited-state gradient

        if 'property' in rsp_dict:
            prop_type = rsp_dict['property'].lower()
        else:
            prop_type = None

        if prop_type in ['absorption', 'uv-vis', 'ecd']: 

            if 'orbital_response' in task.input_dict:
                orbrsp_dict = task.input_dict['orbital_response']
            else:
                orbrsp_dict = {}

            # Excited state gradient
            if 'gradient' in task.input_dict:
                grad_dict = task.input_dict['gradient']
                tdhfgrad_drv = TdhfGradientDriver(scf_drv, 
                                                  task.mpi_comm, task.ostream)
                tdhfgrad_drv.update_settings(grad_dict, rsp_dict,
                                             orbrsp_dict, method_dict)
                tdhfgrad_drv.compute(task.molecule, task.ao_basis,
                                     rsp_prop.rsp_driver.solver, rsp_prop.rsp_property)
                                     # solver is the actual RPA/TDA driver
                                     # with rsp_prop.rsp_driver it works for TDA, but not RPA

            # Excited state Hessian and vibrational analysis
            if 'frequencies' in task.input_dict:
                freq_dict = task.input_dict['frequencies']
                tdhfhessian_drv = TdhfHessianDriver(scf_drv, 
                                                    task.mpi_comm,
                                                    task.ostream)
                tdhfhessian_drv.update_settings(method_dict, rsp_dict,
                                                freq_dict, orbrsp_dict)
                tdhfhessian_drv.compute(task.molecule, task.ao_basis,
                                        rsp_prop.rsp_driver)
                tdhfhessian_drv.vibrational_analysis(task.molecule,
                                                     task.ao_basis)
        else:
            task.ostream.print_blank()
            info_msg = 'The excited state derivatives '
            info_msg += 'can only be computed if the response '
            info_msg += 'property is "absorption", "uv-vis", or "ecd".'
            task.ostream.print_info(info_msg)
            info_msg = 'Computation of gradient/Hessian will be skipped.'
            task.ostream.print_info(info_msg)
            task.ostream.print_blank()
            task.ostream.flush()

    # Pulsed Linear Response Theory

    if ((task_type == 'pulses' or 'pulses' in task.input_dict) and
            scf_drv.scf_type == 'restricted'):
        prt_dict = (task.input_dict['pulses']
                    if 'pulses' in task.input_dict else {})

        cpp_dict = updated_dict_with_eri_settings({}, scf_drv)

        pulsed_response = PulsedResponse(task.mpi_comm, task.ostream)
        pulsed_response.update_settings(prt_dict, cpp_dict, method_dict)
        pulsed_response.compute(task.molecule, task.ao_basis, scf_tensors)

    # MP2 perturbation theory

    if task_type == 'mp2' and scf_drv.scf_type == 'restricted':
        mp2_dict = task.input_dict['mp2'] if 'mp2' in task.input_dict else {}

        mp2_dict = updated_dict_with_eri_settings(mp2_dict, scf_drv)

        mp2_drv = Mp2Driver(task.mpi_comm, task.ostream)
        mp2_drv.update_settings(mp2_dict, method_dict)
        mp2_drv.compute(task.molecule, task.ao_basis, mol_orbs)

    # Cube file

    if task_type == 'visualization':
        cube_dict = (task.input_dict['visualization']
                     if 'visualization' in task.input_dict else {})

        if 'read_dalton' not in task.input_dict['visualization']['cubes']:
            mol_orbs.broadcast(task.mpi_rank, task.mpi_comm)
            density.broadcast(task.mpi_rank, task.mpi_comm)
        else:
            mol_orbs = None
            density = None

        vis_drv = VisualizationDriver(task.mpi_comm)
        vis_drv.gen_cubes(cube_dict, task.molecule, task.ao_basis, mol_orbs,
                          density)

    # LoProp

    if task_type == 'loprop':
        loprop_driver = LoPropDriver(task.mpi_comm, task.ostream)
        loprop_driver.compute(task.molecule, task.ao_basis, scf_tensors)

    # RESP and ESP charges

    if task_type in ['resp charges', 'esp charges']:
        if (task_type == 'resp charges' and 'resp_charges' in task.input_dict):
            charges_dict = task.input_dict['resp_charges']
        elif (task_type == 'esp charges' and 'esp_charges' in task.input_dict):
            charges_dict = task.input_dict['esp_charges']
        else:
            charges_dict = {}

        charges_dict['filename'] = task.input_dict['filename']

        chg_drv = RespChargesDriver(task.mpi_comm, task.ostream)
        chg_drv.update_settings(charges_dict, method_dict)

        if task_type == 'resp charges':
            chg_drv.compute(task.molecule, task.ao_basis, 'resp')
        elif task_type == 'esp charges':
            chg_drv.compute(task.molecule, task.ao_basis, 'esp')

    # All done

    task.finish()
