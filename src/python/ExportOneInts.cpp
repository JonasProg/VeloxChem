//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2019 by VeloxChem developers. All rights reserved.

#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>

#include <mpi.h>
#include <memory>
#include <string>

#include "AngularMomentumIntegralsDriver.hpp"
#include "AngularMomentumMatrix.hpp"
#include "DenseMatrix.hpp"
#include "ElectricDipoleIntegralsDriver.hpp"
#include "ElectricDipoleMatrix.hpp"
#include "ExportGeneral.hpp"
#include "ExportMath.hpp"
#include "ExportOneInts.hpp"
#include "KineticEnergyIntegralsDriver.hpp"
#include "KineticEnergyMatrix.hpp"
#include "LinearMomentumIntegralsDriver.hpp"
#include "LinearMomentumMatrix.hpp"
#include "MolecularBasis.hpp"
#include "Molecule.hpp"
#include "NuclearPotentialIntegralsDriver.hpp"
#include "NuclearPotentialMatrix.hpp"
#include "OverlapIntegralsDriver.hpp"
#include "OverlapMatrix.hpp"

namespace py = pybind11;

namespace vlx_oneints {  // vlx_oneints namespace

// Helper function for COverlapIntegralsDriver constructor

static std::shared_ptr<COverlapIntegralsDriver>
COverlapIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<COverlapIntegralsDriver>(new COverlapIntegralsDriver(*comm_ptr));
}

// Helper function for printing COverlapMatrix

static std::string
COverlapMatrix_str(const COverlapMatrix& self)
{
    return self.getString();
}

// Helper function for converting COverlapMatrix to numpy array

static py::array_t<double>
COverlapMatrix_to_numpy(const COverlapMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.values(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Helper function for COverlapMatrix constructor

static std::shared_ptr<COverlapMatrix>
COverlapMatrix_from_numpy(const py::array_t<double>& arr)
{
    auto mp = vlx_math::CDenseMatrix_from_numpy(arr);

    return std::shared_ptr<COverlapMatrix>(new COverlapMatrix(*mp));
}

// Helper function for CKineticEnergyIntegralsDriver constructor

static std::shared_ptr<CKineticEnergyIntegralsDriver>
CKineticEnergyIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CKineticEnergyIntegralsDriver>(new CKineticEnergyIntegralsDriver(*comm_ptr));
}

// Helper function for printing CKineticEnergyMatrix

static std::string
CKineticEnergyMatrix_str(const CKineticEnergyMatrix& self)
{
    return self.getString();
}

// Helper function for converting CKineticEnergyMatrix to numpy array

static py::array_t<double>
CKineticEnergyMatrix_to_numpy(const CKineticEnergyMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.values(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Helper function for CKineticEnergyMatrix constructor

static std::shared_ptr<CKineticEnergyMatrix>
CKineticEnergyMatrix_from_numpy(const py::array_t<double>& arr)
{
    auto mp = vlx_math::CDenseMatrix_from_numpy(arr);

    return std::shared_ptr<CKineticEnergyMatrix>(new CKineticEnergyMatrix(*mp));
}

// Helper function for CNuclearPotentialIntegralsDriver constructor

static std::shared_ptr<CNuclearPotentialIntegralsDriver>
CNuclearPotentialIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CNuclearPotentialIntegralsDriver>(new CNuclearPotentialIntegralsDriver(*comm_ptr));
}

// Helper function for printing CNuclearPotentialMatrix

static std::string
CNuclearPotentialMatrix_str(const CNuclearPotentialMatrix& self)
{
    return self.getString();
}

// Helper function for converting CNuclearPotentialMatrix to numpy array

static py::array_t<double>
CNuclearPotentialMatrix_to_numpy(const CNuclearPotentialMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.values(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Helper function for CNuclearPotentialMatrix constructor

static std::shared_ptr<CNuclearPotentialMatrix>
CNuclearPotentialMatrix_from_numpy(const py::array_t<double>& arr)
{
    auto mp = vlx_math::CDenseMatrix_from_numpy(arr);

    return std::shared_ptr<CNuclearPotentialMatrix>(new CNuclearPotentialMatrix(*mp));
}

// Helper function for CElectricDipoleIntegralsDriver constructor

static std::shared_ptr<CElectricDipoleIntegralsDriver>
CElectricDipoleIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CElectricDipoleIntegralsDriver>(new CElectricDipoleIntegralsDriver(*comm_ptr));
}

// Helper function for printing CElectricDipoleMatrix

static std::string
CElectricDipoleMatrix_str(const CElectricDipoleMatrix& self)
{
    return self.getStringForComponentX() + self.getStringForComponentY() + self.getStringForComponentZ();
}

// Helper function for converting CElectricDipoleMatrix to numpy array

static py::array_t<double>
CElectricDipoleMatrix_x_to_numpy(const CElectricDipoleMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.xvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CElectricDipoleMatrix_y_to_numpy(const CElectricDipoleMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.yvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CElectricDipoleMatrix_z_to_numpy(const CElectricDipoleMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.zvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Helper function for CLinearMomentumIntegralsDriver constructor

static std::shared_ptr<CLinearMomentumIntegralsDriver>
CLinearMomentumIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CLinearMomentumIntegralsDriver>(new CLinearMomentumIntegralsDriver(*comm_ptr));
}

// Helper function for printing CLinearMomentumMatrix

static std::string
CLinearMomentumMatrix_str(const CLinearMomentumMatrix& self)
{
    return self.getStringForComponentX() + self.getStringForComponentY() + self.getStringForComponentZ();
}

// Helper function for converting CLinearMomentumMatrix to numpy array

static py::array_t<double>
CLinearMomentumMatrix_x_to_numpy(const CLinearMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.xvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CLinearMomentumMatrix_y_to_numpy(const CLinearMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.yvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CLinearMomentumMatrix_z_to_numpy(const CLinearMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.zvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Helper function for CAngularMomentumIntegralsDriver constructor

static std::shared_ptr<CAngularMomentumIntegralsDriver>
CAngularMomentumIntegralsDriver_create(py::object py_comm)
{
    MPI_Comm* comm_ptr = vlx_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CAngularMomentumIntegralsDriver>(new CAngularMomentumIntegralsDriver(*comm_ptr));
}

// Helper function for printing CAngularMomentumMatrix

static std::string
CAngularMomentumMatrix_str(const CAngularMomentumMatrix& self)
{
    return self.getStringForComponentX() + self.getStringForComponentY() + self.getStringForComponentZ();
}

// Helper function for converting CAngularMomentumMatrix to numpy array

static py::array_t<double>
CAngularMomentumMatrix_x_to_numpy(const CAngularMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.xvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CAngularMomentumMatrix_y_to_numpy(const CAngularMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.yvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

static py::array_t<double>
CAngularMomentumMatrix_z_to_numpy(const CAngularMomentumMatrix& self)
{
    return vlx_general::pointer_to_numpy(self.zvalues(), self.getNumberOfRows(), self.getNumberOfColumns());
}

// Exports classes/functions in src/oneints to python

void
export_oneints(py::module& m)
{
    // COverlapMatrix class

    py::class_<COverlapMatrix, std::shared_ptr<COverlapMatrix>>(m, "OverlapMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&>())
        .def(py::init<const COverlapMatrix&>())
        .def(py::init(&COverlapMatrix_from_numpy))
        .def("__str__", &COverlapMatrix_str)
        .def("to_numpy", &COverlapMatrix_to_numpy)
        .def("get_ortho_matrix", &COverlapMatrix::getOrthogonalizationMatrix)
        .def(py::self == py::self);

    // COverlapIntegralsDriver class

    py::class_<COverlapIntegralsDriver, std::shared_ptr<COverlapIntegralsDriver>>(m, "OverlapIntegralsDriver")
        .def(py::init(&COverlapIntegralsDriver_create))
        .def("compute",
             (COverlapMatrix(COverlapIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&) const) &
                 COverlapIntegralsDriver::compute)
        .def("compute",
             (COverlapMatrix(COverlapIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 COverlapIntegralsDriver::compute)
        .def("compute",
             (COverlapMatrix(COverlapIntegralsDriver::*)(const CMolecule&, const CMolecule&, const CMolecularBasis&)
                  const) &
                 COverlapIntegralsDriver::compute)
        .def("compute",
             (COverlapMatrix(COverlapIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 COverlapIntegralsDriver::compute);

    // CKineticEnergyMatrix class

    py::class_<CKineticEnergyMatrix, std::shared_ptr<CKineticEnergyMatrix>>(m, "KineticEnergyMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&>())
        .def(py::init<const CKineticEnergyMatrix&>())
        .def(py::init(&CKineticEnergyMatrix_from_numpy))
        .def("__str__", &CKineticEnergyMatrix_str)
        .def("to_numpy", &CKineticEnergyMatrix_to_numpy)
        .def("get_energy", &CKineticEnergyMatrix::getKineticEnergy)
        .def(py::self == py::self);

    // CKineticEnergyIntegralsDriver class

    py::class_<CKineticEnergyIntegralsDriver, std::shared_ptr<CKineticEnergyIntegralsDriver>>(
        m, "KineticEnergyIntegralsDriver")
        .def(py::init(&CKineticEnergyIntegralsDriver_create))
        .def("compute",
             (CKineticEnergyMatrix(CKineticEnergyIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&) const) &
                 CKineticEnergyIntegralsDriver::compute)
        .def("compute",
             (CKineticEnergyMatrix(CKineticEnergyIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CKineticEnergyIntegralsDriver::compute)
        .def("compute",
             (CKineticEnergyMatrix(CKineticEnergyIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&) const) &
                 CKineticEnergyIntegralsDriver::compute)
        .def("compute",
             (CKineticEnergyMatrix(CKineticEnergyIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CKineticEnergyIntegralsDriver::compute);

    // CNuclearPotentialMatrix class

    py::class_<CNuclearPotentialMatrix, std::shared_ptr<CNuclearPotentialMatrix>>(m, "NuclearPotentialMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&>())
        .def(py::init<const CNuclearPotentialMatrix&>())
        .def(py::init(&CNuclearPotentialMatrix_from_numpy))
        .def("__str__", &CNuclearPotentialMatrix_str)
        .def("to_numpy", &CNuclearPotentialMatrix_to_numpy)
        .def("get_energy", &CNuclearPotentialMatrix::getNuclearPotentialEnergy)
        .def(py::self == py::self);

    // CNuclearPotentialIntegralsDriver class

    py::class_<CNuclearPotentialIntegralsDriver, std::shared_ptr<CNuclearPotentialIntegralsDriver>>(
        m, "NuclearPotentialIntegralsDriver")
        .def(py::init(&CNuclearPotentialIntegralsDriver_create))
        .def("compute",
             (CNuclearPotentialMatrix(CNuclearPotentialIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&)
                  const) &
                 CNuclearPotentialIntegralsDriver::compute)
        .def("compute",
             (CNuclearPotentialMatrix(CNuclearPotentialIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecule&) const) &
                 CNuclearPotentialIntegralsDriver::compute)
        .def("compute",
             (CNuclearPotentialMatrix(CNuclearPotentialIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&, const CMolecule&) const) &
                 CNuclearPotentialIntegralsDriver::compute)
        .def("compute",
             (CNuclearPotentialMatrix(CNuclearPotentialIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecule&) const) &
                 CNuclearPotentialIntegralsDriver::compute)
        .def("compute",
             (CNuclearPotentialMatrix(CNuclearPotentialIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&, const CMolecule&)
                  const) &
                 CNuclearPotentialIntegralsDriver::compute);

    // CElectricDipoleMatrix class

    py::class_<CElectricDipoleMatrix, std::shared_ptr<CElectricDipoleMatrix>>(m, "ElectricDipoleMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&,
                      const CDenseMatrix&,
                      const CDenseMatrix&,
                      const double,
                      const double,
                      const double>())
        .def(py::init<const CElectricDipoleMatrix&>())
        .def("__str__", &CElectricDipoleMatrix_str)
        .def("x_to_numpy", &CElectricDipoleMatrix_x_to_numpy)
        .def("y_to_numpy", &CElectricDipoleMatrix_y_to_numpy)
        .def("z_to_numpy", &CElectricDipoleMatrix_z_to_numpy)
        .def(py::self == py::self);

    // CElectricDipoleIntegralsDriver class

    py::class_<CElectricDipoleIntegralsDriver, std::shared_ptr<CElectricDipoleIntegralsDriver>>(
        m, "ElectricDipoleIntegralsDriver")
        .def(py::init(&CElectricDipoleIntegralsDriver_create))
        .def("set_origin", &CElectricDipoleIntegralsDriver::setElectricDipoleOrigin)
        .def(
            "compute",
            (CElectricDipoleMatrix(CElectricDipoleIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&) const) &
                CElectricDipoleIntegralsDriver::compute)
        .def("compute",
             (CElectricDipoleMatrix(CElectricDipoleIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CElectricDipoleIntegralsDriver::compute)
        .def("compute",
             (CElectricDipoleMatrix(CElectricDipoleIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&) const) &
                 CElectricDipoleIntegralsDriver::compute)
        .def("compute",
             (CElectricDipoleMatrix(CElectricDipoleIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CElectricDipoleIntegralsDriver::compute);

    // CLinearMomentumMatrix class

    py::class_<CLinearMomentumMatrix, std::shared_ptr<CLinearMomentumMatrix>>(m, "LinearMomentumMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&, const CDenseMatrix&, const CDenseMatrix&>())
        .def(py::init<const CLinearMomentumMatrix&>())
        .def("__str__", &CLinearMomentumMatrix_str)
        .def("x_to_numpy", &CLinearMomentumMatrix_x_to_numpy)
        .def("y_to_numpy", &CLinearMomentumMatrix_y_to_numpy)
        .def("z_to_numpy", &CLinearMomentumMatrix_z_to_numpy)
        .def(py::self == py::self);

    // CLinearMomentumIntegralsDriver class

    py::class_<CLinearMomentumIntegralsDriver, std::shared_ptr<CLinearMomentumIntegralsDriver>>(
        m, "LinearMomentumIntegralsDriver")
        .def(py::init(&CLinearMomentumIntegralsDriver_create))
        .def(
            "compute",
            (CLinearMomentumMatrix(CLinearMomentumIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&) const) &
                CLinearMomentumIntegralsDriver::compute)
        .def("compute",
             (CLinearMomentumMatrix(CLinearMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CLinearMomentumIntegralsDriver::compute)
        .def("compute",
             (CLinearMomentumMatrix(CLinearMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&) const) &
                 CLinearMomentumIntegralsDriver::compute)
        .def("compute",
             (CLinearMomentumMatrix(CLinearMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CLinearMomentumIntegralsDriver::compute);

    // CAngularMomentumMatrix class

    py::class_<CAngularMomentumMatrix, std::shared_ptr<CAngularMomentumMatrix>>(m, "AngularMomentumMatrix")
        .def(py::init<>())
        .def(py::init<const CDenseMatrix&,
                      const CDenseMatrix&,
                      const CDenseMatrix&,
                      const double,
                      const double,
                      const double>())
        .def(py::init<const CAngularMomentumMatrix&>())
        .def("__str__", &CAngularMomentumMatrix_str)
        .def("x_to_numpy", &CAngularMomentumMatrix_x_to_numpy)
        .def("y_to_numpy", &CAngularMomentumMatrix_y_to_numpy)
        .def("z_to_numpy", &CAngularMomentumMatrix_z_to_numpy)
        .def(py::self == py::self);

    // CAngularMomentumIntegralsDriver class

    py::class_<CAngularMomentumIntegralsDriver, std::shared_ptr<CAngularMomentumIntegralsDriver>>(
        m, "AngularMomentumIntegralsDriver")
        .def(py::init(&CAngularMomentumIntegralsDriver_create))
        .def("set_origin", &CAngularMomentumIntegralsDriver::setAngularMomentumOrigin)
        .def("compute",
             (CAngularMomentumMatrix(CAngularMomentumIntegralsDriver::*)(const CMolecule&, const CMolecularBasis&)
                  const) &
                 CAngularMomentumIntegralsDriver::compute)
        .def("compute",
             (CAngularMomentumMatrix(CAngularMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CAngularMomentumIntegralsDriver::compute)
        .def("compute",
             (CAngularMomentumMatrix(CAngularMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&) const) &
                 CAngularMomentumIntegralsDriver::compute)
        .def("compute",
             (CAngularMomentumMatrix(CAngularMomentumIntegralsDriver::*)(
                 const CMolecule&, const CMolecule&, const CMolecularBasis&, const CMolecularBasis&) const) &
                 CAngularMomentumIntegralsDriver::compute);
}

}  // namespace vlx_oneints
