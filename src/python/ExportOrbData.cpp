//
//                           VELOXCHEM 1.0-RC2
//         ----------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact
//
//  SPDX-License-Identifier: LGPL-3.0-or-later
//
//  This file is part of VeloxChem.
//
//  VeloxChem is free software: you can redistribute it and/or modify it under
//  the terms of the GNU Lesser General Public License as published by the Free
//  Software Foundation, either version 3 of the License, or (at your option)
//  any later version.
//
//  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
//  License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

#include "ExportOrbData.hpp"

#include <mpi.h>
#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <fstream>
#include <string>

#include "AODensityMatrix.hpp"
#include "AOIndices.hpp"
#include "DenseMatrix.hpp"
#include "DensityMatrixType.hpp"
#include "ErrorHandler.hpp"
#include "ExportGeneral.hpp"
#include "ExportMath.hpp"
#include "GtoTransform.hpp"
#include "MolecularBasis.hpp"
#include "MolecularOrbitals.hpp"
#include "MolecularOrbitalsType.hpp"
#include "Molecule.hpp"
#include "PackedGtoPairContainer.hpp"
#include "SADGuessDriver.hpp"
#include "StringFormat.hpp"

namespace py = pybind11;
using namespace py::literals;

namespace vlx_orbdata {  // vlx_orbdata namespace

int32_t
get_number_of_atomic_orbitals(const CMolecule& molecule, const CMolecularBasis& basis)
{
    auto natoms = molecule.getNumberOfAtoms();

    auto max_angl = basis.getMolecularMaxAngularMomentum(molecule);

    int32_t nao = 0;

    for (int32_t angl = 0; angl <= max_angl; angl++)
    {
        for (int32_t s = -angl; s <= angl; s++)
        {
            for (int32_t atomidx = 0; atomidx < natoms; atomidx++)
            {
                int32_t idelem = molecule.getIdsElemental()[atomidx];

                nao += basis.getNumberOfBasisFunctions(idelem, angl);
            }
        }
    }

    return nao;
}

// Helper function for CAODensityMatrix constructor

static std::shared_ptr<CAODensityMatrix>
CAODensityMatrix_from_numpy_list(const std::vector<py::array_t<double>>& arrays, const denmat den_type)
{
    std::vector<CDenseMatrix> dmat;

    for (size_t i = 0; i < arrays.size(); i++)
    {
        auto mp = vlx_math::CDenseMatrix_from_numpy(arrays[i]);

        dmat.push_back(*mp);
    }

    return std::make_shared<CAODensityMatrix>(dmat, den_type);
}

// Helper function for CMolecularOrbitals constructor

static std::shared_ptr<CMolecularOrbitals>
CMolecularOrbitals_from_numpy_list(const std::vector<py::array_t<double>>& mol_orbs,
                                   const std::vector<py::array_t<double>>& eig_vals,
                                   const std::vector<py::array_t<double>>& occupations,
                                   const molorb                            orbs_type)
{
    py::ssize_t nmo = -1;

    std::string errnmo("MolecularOrbitals: Inconsistent number of MOs");

    std::string erreig("MolecularOrbitals: Expecting 1D numpy arrays for eigenvalues");

    std::string errocc("MolecularOrbitals: Expecting 1D numpy arrays for occupations");

    std::vector<CDenseMatrix> cmos;

    for (size_t i = 0; i < mol_orbs.size(); i++)
    {
        if (nmo == -1) nmo = mol_orbs[i].shape(1);

        errors::assertMsgCritical(nmo == mol_orbs[i].shape(1), errnmo);

        auto mp = vlx_math::CDenseMatrix_from_numpy(mol_orbs[i]);

        cmos.push_back(*mp);
    }

    std::vector<CMemBlock<double>> ceigs;

    for (size_t i = 0; i < eig_vals.size(); i++)
    {
        if (nmo == -1) nmo = eig_vals[i].size();

        errors::assertMsgCritical(nmo == eig_vals[i].size(), errnmo);

        const py::array_t<double>& arr = eig_vals[i];

        errors::assertMsgCritical(arr.ndim() == 1, erreig);

        if (arr.data() == nullptr || arr.size() == 0)
        {
            return std::make_shared<CMolecularOrbitals>();
        }

        std::vector<double> vec(arr.data(), arr.data() + arr.size());

        ceigs.push_back(CMemBlock<double>(vec));
    }

    std::vector<CMemBlock<double>> coccs;

    for (size_t i = 0; i < occupations.size(); i++)
    {
        if (nmo == -1) nmo = occupations[i].size();

        errors::assertMsgCritical(nmo == occupations[i].size(), errnmo);

        const py::array_t<double>& arr = occupations[i];

        errors::assertMsgCritical(arr.ndim() == 1, errocc);

        std::vector<double> vec(arr.data(), arr.data() + arr.size());

        coccs.push_back(CMemBlock<double>(vec));
    }

    return std::make_shared<CMolecularOrbitals>(cmos, ceigs, coccs, orbs_type);
}

// Exports classes/functions in src/orbdata to python

void
export_orbdata(py::module& m)
{
    // denmat enum class

    // clang-format off
    py::enum_<denmat>(m, "denmat")
        .value("rest", denmat::rest)
        .value("unrest", denmat::unrest)
        .value("rmoij", denmat::rmoij)
        .value("umoij", denmat::umoij)
        .value("rgen", denmat::rgen);
    // clang-format on

    // molorb enum class

    // clang-format off
    py::enum_<molorb>(m, "molorb")
        .value("rest", molorb::rest)
        .value("unrest", molorb::unrest);
    // clang-format on

    // CBasisFunction class

    PyClass<CBasisFunction>(m, "BasisFunction")
        .def(py::init<>())
        .def(py::init<const std::vector<double>&, const std::vector<double>&, const int32_t>())
        .def("__repr__", &CBasisFunction::repr)
        .def("normalize", &CBasisFunction::normalize, "Normalizes basis function.")
        .def_property("angular_momentum", &CBasisFunction::getAngularMomentum, &CBasisFunction::setAngularMomentum)
        .def_property("exponents", &CBasisFunction::getExponents, &CBasisFunction::setExponents)
        .def_property("normalization_factors", &CBasisFunction::getNormalizationFactors, &CBasisFunction::setNormalizationFactors)
        .def_property_readonly("n_primitives", &CBasisFunction::getNumberOfPrimitiveFunctions);

    // CAtomBasis class

    PyClass<CAtomBasis>(m, "AtomBasis")
        .def(py::init<>())
        .def("__repr__", &CAtomBasis::repr)
        .def("add_basis_function", &CAtomBasis::addBasisFunction, "Adds basis function object to atom basis.", "basisFunction"_a)
        .def("set_elemental_id", &CAtomBasis::setIdElemental, "Sets identifier of chemical element in atom basis.", "idElemental"_a)
        .def("get_elemental_id", &CAtomBasis::getIdElemental, "Gets identifier of chemical element.")
        .def(
            "__iter__",
            [](const CAtomBasis& obj) { return py::make_iterator(obj.begin(), obj.end()); },
            py::keep_alive<0, 1>() /* Essential: keep object alive while iterator exists */);

    // CMolecularBasis class

    PyClass<CMolecularBasis>(m, "MolecularBasis")
        .def(py::init<>())
        .def(py::init<const CMolecularBasis&>())
        .def("__repr__", &CMolecularBasis::repr)
        .def("get_string",
             py::overload_cast<const std::string&, const CMolecule&>(&CMolecularBasis::printBasis, py::const_),
             "Prints AO basis information to output stream for selected molecule.",
             "title"_a,
             "molecule"_a)
        .def("get_string",
             py::overload_cast<const CMolecule&>(&CMolecularBasis::printBasis, py::const_),
             "Prints AO basis information to output stream for selected molecule.",
             "molecule"_a)
        .def("set_label", &CMolecularBasis::setLabel, "Sets name of molecular basis.", "label"_a)
        .def("get_label", &CMolecularBasis::getLabel, "Gets name of molecular basis.")
        .def("get_ao_basis_map", &CMolecularBasis::getAOBasisMap, "Creates string representation map of basis functions.", "molecule"_a)
        .def(
            "broadcast",
            [](CMolecularBasis& self, int32_t rank, py::object py_comm) -> void {
                auto comm = vlx_general::get_mpi_comm(py_comm);
                self.broadcast(rank, *comm);
            },
            "Broadcasts MolecularBasis object.",
            "rank"_a,
            "py_comm"_a)
        .def("get_valence_basis", &CMolecularBasis::reduceToValenceBasis, "Reduces molecular basis to valence molecular basis.")
        .def("add_atom_basis", &CMolecularBasis::addAtomBasis, "Adds atom basis object to molecular basis.", "atomBasis"_a)
        .def("get_dimension_of_basis",
             &CMolecularBasis::getDimensionsOfBasis,
             "Determines size of contracted AO basis for selected molecule.",
             "molecule"_a)
        .def("get_dimensions_of_basis",
             &CMolecularBasis::getDimensionsOfBasis,
             "Determines size of contracted AO basis for selected molecule.",
             "molecule"_a)
        .def("get_dimension_of_primitive_basis",
             &CMolecularBasis::getDimensionsOfPrimitiveBasis,
             "Determines size of primitive AO basis for selected molecule.",
             "molecule"_a)
        .def("get_dimensions_of_primitive_basis",
             &CMolecularBasis::getDimensionsOfPrimitiveBasis,
             "Determines size of primitive AO basis for selected molecule.",
             "molecule"_a)
        .def(
            "get_index_map", &CMolecularBasis::getIndexMap, "Maps the atomic orbital indices of veloxchem to pyscf and Dalton indices.", "molecule"_a)
        .def("n_basis_functions",
             py::overload_cast<const CMolecule&, int32_t>(&CMolecularBasis::getNumberOfBasisFunctions, py::const_),
             "Determines number of basis functions with specific angular momentum in molecular basis of selected molecule.",
             "molecule"_a,
             "angularMomentum"_a)
        .def("n_primitive_basis_functions",
             py::overload_cast<const CMolecule&, int32_t>(&CMolecularBasis::getNumberOfPrimitiveBasisFunctions, py::const_),
             "Determines number of primitive Gaussian functions with specific angular momentum in molecular basis of selected molecule.",
             "molecule"_a,
             "angularMomentum"_a)
        .def(
            "__iter__",
            [](const CMolecularBasis& obj) { return py::make_iterator(obj.begin(), obj.end()); },
            py::keep_alive<0, 1>() /* Essential: keep object alive while iterator exists */)
        .def(py::self == py::self);

    // CAODensityMatrix class

    PyClass<CAODensityMatrix>(m, "AODensityMatrix")
        .def(py::init<>())
        .def(py::init<const CAODensityMatrix&>())
        .def(py::init(&CAODensityMatrix_from_numpy_list))
        .def("__str__", &CAODensityMatrix::getString)
        .def(
            "alpha_to_numpy",
            [](const CAODensityMatrix& self, const int32_t iDensityMatrix) -> py::array_t<double> {
                auto numRows = self.getNumberOfRows(iDensityMatrix);
                auto numCols = self.getNumberOfColumns(iDensityMatrix);
                return vlx_general::pointer_to_numpy(self.alphaDensity(iDensityMatrix), numRows, numCols);
            },
            "Converts alpha density matrix to numpy array.",
            "iDensityMatrix"_a)
        .def(
            "beta_to_numpy",
            [](const CAODensityMatrix& self, const int32_t iDensityMatrix) -> py::array_t<double> {
                auto numRows = self.getNumberOfRows(iDensityMatrix);
                auto numCols = self.getNumberOfColumns(iDensityMatrix);
                return vlx_general::pointer_to_numpy(self.betaDensity(iDensityMatrix), numRows, numCols);
            },
            "Converts beta density matrix to numpy array.",
            "iDensityMatrix"_a)
        .def("number_of_density_matrices", &CAODensityMatrix::getNumberOfDensityMatrices, "Gets number of density matrices.")
        .def("get_density_type", &CAODensityMatrix::getDensityType, "Gets type of density matrix.")
        .def("sub",
             &CAODensityMatrix::sub,
             "Creates difference AO density matrix between this AO density matrix and given AO density matrix.",
             "other"_a)
        .def("append", &CAODensityMatrix::append, "Appends AO density matrix object to current AO density matrix object.", "other"_a)
        .def(
            "broadcast",
            [](CAODensityMatrix& self, int32_t rank, py::object py_comm) -> void {
                auto comm = vlx_general::get_mpi_comm(py_comm);
                self.broadcast(rank, *comm);
            },
            "Broadcasts AODensityMatrix object.",
            "rank"_a,
            "py_comm"_a)
        .def(py::self == py::self);

    // CMolecularOrbitals class

    PyClass<CMolecularOrbitals>(m, "MolecularOrbitals")
        .def(py::init<>())
        .def(py::init<const CMolecularOrbitals&>())
        .def(py::init(&CMolecularOrbitals_from_numpy_list))
        .def("__str__", &CMolecularOrbitals::getString)
        .def(
            "alpha_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.alphaOrbitals(), self.getNumberOfRows(), self.getNumberOfColumns());
            },
            "Converts alpha MO coefficients in MolecularOrbitals to numpy array.")
        .def(
            "beta_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.betaOrbitals(), self.getNumberOfRows(), self.getNumberOfColumns());
            },
            "Converts beta MO coefficients in MolecularOrbitals to numpy array.")
        .def(
            "ea_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.alphaEnergies(), self.getNumberOfColumns());
            },
            "Converts alpha orbital energies in MolecularOrbitals to numpy array.")
        .def(
            "eb_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.betaEnergies(), self.getNumberOfColumns());
            },
            "Converts beta orbital energies in MolecularOrbitals to numpy array.")
        .def(
            "occa_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.alphaOccupations(), self.getNumberOfColumns());
            },
            "Converts alpha orbital energies in MolecularOrbitals to numpy array.")
        .def(
            "occb_to_numpy",
            [](const CMolecularOrbitals& self) -> py::array_t<double> {
                return vlx_general::pointer_to_numpy(self.betaOccupations(), self.getNumberOfColumns());
            },
            "Converts beta orbital energies in MolecularOrbitals to numpy array.")
        .def("get_orbitals_type", &CMolecularOrbitals::getOrbitalsType, "Gets type of molecular orbital matrix.")
        .def("get_ao_density",
             py::overload_cast<const int32_t>(&CMolecularOrbitals::getAODensity, py::const_),
             "Computes spin restricted electron density matrix in AO basis for specific number of electrons.",
             "nElectrons"_a)
        .def("get_ao_density",
             py::overload_cast<const int32_t, const int32_t>(&CMolecularOrbitals::getAODensity, py::const_),
             "Computes spin unrestricted electron density matrix in AO basis for specific number of alpha and beta electrons.",
             "nAlphaElectrons"_a,
             "nBetaElectrons"_a)
        .def("get_pair_density",
             py::overload_cast<const std::vector<int32_t>&, const std::vector<int32_t>&>(&CMolecularOrbitals::getRestrictedPairDensity, py::const_),
             "Computes set of restricted pair C_i C_j^T density matrices in AO basis.",
             "iMolecularOrbitals"_a,
             "ecularOrbitals"_a)
        .def("get_pair_density",
             py::overload_cast<const int32_t, const int32_t>(&CMolecularOrbitals::getRestrictedPairDensity, py::const_),
             "Computes restricted pair C_i C_j^T density matrix in AO basis.",
             "iMolecularOrbital"_a,
             "jMolecularOrbital"_a)
        .def("insert",
             &CMolecularOrbitals::insert,
             "Creates molecular orbitals objects from this molecular orbitals object according to given basis sets pair.",
             "molecule"_a,
             "aoBasis"_a,
             "minBasis"_a)
        .def("number_aos", &CMolecularOrbitals::getNumberOfRows, "Gets number of rows in specific molecular orbital matrix.")
        .def("number_of_aos", &CMolecularOrbitals::getNumberOfRows, "Gets number of rows in specific molecular orbital matrix.")
        .def("number_mos", &CMolecularOrbitals::getNumberOfColumns, "Gets number of columns in specific molecular orbital matrix.")
        .def("number_of_mos", &CMolecularOrbitals::getNumberOfColumns, "Gets number of columns in specific molecular orbital matrix.")
        .def("alpha_orbitals",
             py::overload_cast<const int32_t, const int32_t>(&CMolecularOrbitals::alphaOrbitals, py::const_),
             "Gets alpha orbitals within specific range.",
             "iMolecularOrbital"_a,
             "nMolecularOrbitals"_a)
        .def("beta_orbitals",
             py::overload_cast<const int32_t, const int32_t>(&CMolecularOrbitals::betaOrbitals, py::const_),
             "Gets beta orbitals within specific range.",
             "iMolecularOrbital"_a,
             "nMolecularOrbitals"_a)
        .def("transform",
             &CMolecularOrbitals::transform,
             "Transforms matrix in AO basis to matrix in MO basis using selected molecular orbitals.",
             "aoMatrix"_a,
             "spinPair"_a)
        .def(
            "broadcast",
            [](CMolecularOrbitals& self, int32_t rank, py::object py_comm) -> void {
                auto comm = vlx_general::get_mpi_comm(py_comm);
                self.broadcast(rank, *comm);
            },
            "Broadcasts MolecularOrbitals object.",
            "rank"_a,
            "py_comm"_a)
        .def(py::self == py::self);

    // CSADGuessDriver class

    PyClass<CSADGuessDriver>(m, "SADGuessDriver")
        .def(py::init(&vlx_general::create<CSADGuessDriver>), "comm"_a = py::none())
        .def("compute", &CSADGuessDriver::compute, "Computes SAD initial guess.", "molecule"_a, "basis_1"_a, "basis_2"_a, "densityType"_a)
        .def("set_number_of_unpaired_electrons_on_atoms",
             &CSADGuessDriver::setNumberOfUnpairedElectronsOnAtoms,
             "Sets number of unpaired electrons on atoms for SAD initial guess.",
             "num_unpaired_electrons"_a);

    // CPackedGtoPairContainer class

    PyClass<CPackedGtoPairContainer<double, mem::Host>>(m, "PackedGtoPairContainer")
        .def(py::init<>())
        .def(py::init<const CPackedGtoPairContainer<double, mem::Host>&>())
        .def("summary", &CPackedGtoPairContainer<double, mem::Host>::printSummary);

    // exposing functions

    m.def("get_dimer_ao_indices",
          &aoindices::getDimerAOIndices,
          "Gets AO indices of the two molecules in a molecular dimer.",
          "mol_1"_a,
          "mol_2"_a,
          "basis_1"_a,
          "basis_2"_a);

    m.def("ao_matrix_to_veloxchem",
          &gtotra::to_veloxchem,
          "Transforms AO matrix from Dalton to VeloxChem format.",
          "matrix"_a,
          "basis"_a,
          "molecule"_a);

    m.def("ao_matrix_to_dalton", &gtotra::to_dalton, "Transforms AO matrix from VeloxChem to Dalton format.", "matrix"_a, "basis"_a, "molecule"_a);

    m.def("get_basis_function_indices_for_atom",
          &gtotra::getBasisFunctionIndicesForAtom,
          "Gets basis function indices for an atom.",
          "molecule"_a,
          "basis"_a,
          "atomIdx"_a);
}

}  // namespace vlx_orbdata
