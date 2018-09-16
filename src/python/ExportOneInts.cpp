//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include <boost/python.hpp>
#include <mpi.h>
#include <mpi4py/mpi4py.h>

#include <memory>
#include <string>

#include "MpiFunc.hpp"
#include "OutputStream.hpp"
#include "Molecule.hpp"
#include "MolecularBasis.hpp"
#include "DenseMatrix.hpp"
#include "OverlapMatrix.hpp"
#include "OverlapIntegralsDriver.hpp"
#include "KineticEnergyMatrix.hpp"
#include "KineticEnergyIntegralsDriver.hpp"
#include "NuclearPotentialMatrix.hpp"
#include "NuclearPotentialIntegralsDriver.hpp"

#include "ExportGeneral.hpp"
#include "ExportOneInts.hpp"

namespace bp = boost::python;

namespace bp_oneints { // bp_oneints namespace

// Helper function for creating a COverlapIntegralsDriver object

static std::shared_ptr<COverlapIntegralsDriver>
COverlapIntegralsDriver_create(int32_t    globRank,
                               int32_t    globNodes,
                               bp::object py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return std::shared_ptr<COverlapIntegralsDriver>(
        new COverlapIntegralsDriver(globRank, globNodes, *comm_ptr)
        );
}

// Helper functions for overloading COverlapIntegralsDriver::compute

COverlapMatrix
COverlapIntegralsDriver_compute_1(
          COverlapIntegralsDriver& self,
    const CMolecule&               molecule,
    const CMolecularBasis&         basis,
          COutputStream&           oStream,
          bp::object               py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, basis, oStream, *comm_ptr);
}

COverlapMatrix
COverlapIntegralsDriver_compute_2(
          COverlapIntegralsDriver& self,
    const CMolecule&               molecule,
    const CMolecularBasis&         braBasis,
    const CMolecularBasis&         ketBasis,
          COutputStream&           oStream,
          bp::object               py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, braBasis, ketBasis, oStream, *comm_ptr);
}

COverlapMatrix
COverlapIntegralsDriver_compute_3(
          COverlapIntegralsDriver& self,
    const CMolecule&               braMolecule,
    const CMolecule&               ketMolecule,
    const CMolecularBasis&         basis,
          COutputStream&           oStream,
          bp::object               py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, basis, oStream, *comm_ptr);
}

COverlapMatrix
COverlapIntegralsDriver_compute_4(
          COverlapIntegralsDriver& self,
    const CMolecule&               braMolecule,
    const CMolecule&               ketMolecule,
    const CMolecularBasis&         braBasis,
    const CMolecularBasis&         ketBasis,
          COutputStream&           oStream,
          bp::object               py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, braBasis, ketBasis,
                        oStream, *comm_ptr);
}

// Helper function for printing COverlapMatrix

std::string
COverlapMatrix_str (const COverlapMatrix& self)
{
    return self.getString();
}

// Helper function for creating a CKineticEnergyIntegralsDriver object

static std::shared_ptr<CKineticEnergyIntegralsDriver>
CKineticEnergyIntegralsDriver_create(int32_t    globRank,
                                     int32_t    globNodes,
                                     bp::object py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CKineticEnergyIntegralsDriver>(
        new CKineticEnergyIntegralsDriver(globRank, globNodes, *comm_ptr)
        );
}

// Helper functions for overloading CKineticEnergyIntegralsDriver::compute

CKineticEnergyMatrix
CKineticEnergyIntegralsDriver_compute_1(
          CKineticEnergyIntegralsDriver& self,
    const CMolecule&                     molecule,
    const CMolecularBasis&               basis,
          COutputStream&                 oStream, 
          bp::object                     py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, basis, oStream, *comm_ptr);
}

CKineticEnergyMatrix
CKineticEnergyIntegralsDriver_compute_2(
          CKineticEnergyIntegralsDriver& self,
    const CMolecule&                     molecule,
    const CMolecularBasis&               braBasis,
    const CMolecularBasis&               ketBasis,
          COutputStream&                 oStream, 
          bp::object                     py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, braBasis, ketBasis, oStream, *comm_ptr);
}

CKineticEnergyMatrix
CKineticEnergyIntegralsDriver_compute_3(
          CKineticEnergyIntegralsDriver& self,
    const CMolecule&                     braMolecule,
    const CMolecule&                     ketMolecule,
    const CMolecularBasis&               basis,
          COutputStream&                 oStream, 
          bp::object                     py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, basis, oStream, *comm_ptr);
}

CKineticEnergyMatrix
CKineticEnergyIntegralsDriver_compute_4(
          CKineticEnergyIntegralsDriver& self,
    const CMolecule&                     braMolecule,
    const CMolecule&                     ketMolecule,
    const CMolecularBasis&               braBasis,
    const CMolecularBasis&               ketBasis,
          COutputStream&                 oStream, 
          bp::object                     py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, braBasis, ketBasis,
                        oStream, *comm_ptr);
}

// Helper function for printing CKineticEnergyMatrix

std::string
CKineticEnergyMatrix_str (const CKineticEnergyMatrix& self)
{
    return self.getString();
}

// Helper function for creating a CKineticEnergyIntegralsDriver object

static std::shared_ptr<CNuclearPotentialIntegralsDriver>
CNuclearPotentialIntegralsDriver_create(int32_t    globRank,
                                        int32_t    globNodes,
                                        bp::object py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return std::shared_ptr<CNuclearPotentialIntegralsDriver>(
        new CNuclearPotentialIntegralsDriver(globRank, globNodes, *comm_ptr)
        );
}

// Helper functions for overloading CNuclearPotentialIntegralsDriver::compute

CNuclearPotentialMatrix
CNuclearPotentialIntegralsDriver_compute_0(
          CNuclearPotentialIntegralsDriver& self,
    const CMolecule&                        molecule,
    const CMolecularBasis&                  basis,
          COutputStream&                    oStream, 
          bp::object                        py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, basis, oStream, *comm_ptr);
}

CNuclearPotentialMatrix
CNuclearPotentialIntegralsDriver_compute_1(
          CNuclearPotentialIntegralsDriver& self,
    const CMolecule&                        molecule,
    const CMolecularBasis&                  basis,
    const CMolecule&                        pchgMolecule,
          COutputStream&                    oStream, 
          bp::object                        py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, basis, pchgMolecule, oStream, *comm_ptr);
}

CNuclearPotentialMatrix
CNuclearPotentialIntegralsDriver_compute_2(
          CNuclearPotentialIntegralsDriver& self,
    const CMolecule&                        molecule,
    const CMolecularBasis&                  braBasis,
    const CMolecularBasis&                  ketBasis,
    const CMolecule&                        pchgMolecule,
          COutputStream&                    oStream, 
          bp::object                        py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(molecule, braBasis, ketBasis, pchgMolecule,
                        oStream, *comm_ptr);
}

CNuclearPotentialMatrix
CNuclearPotentialIntegralsDriver_compute_3(
          CNuclearPotentialIntegralsDriver& self,
    const CMolecule&                        braMolecule,
    const CMolecule&                        ketMolecule,
    const CMolecularBasis&                  basis,
    const CMolecule&                        pchgMolecule,
          COutputStream&                    oStream, 
          bp::object                        py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, basis, pchgMolecule,
                        oStream, *comm_ptr);
}

CNuclearPotentialMatrix
CNuclearPotentialIntegralsDriver_compute_4(
          CNuclearPotentialIntegralsDriver& self,
    const CMolecule&                        braMolecule,
    const CMolecule&                        ketMolecule,
    const CMolecularBasis&                  braBasis,
    const CMolecularBasis&                  ketBasis,
    const CMolecule&                        pchgMolecule,
          COutputStream&                    oStream, 
          bp::object                        py_comm)
{
    MPI_Comm* comm_ptr = bp_general::get_mpi_comm(py_comm);

    return self.compute(braMolecule, ketMolecule, braBasis, ketBasis, pchgMolecule,
                        oStream, *comm_ptr);
}

// Helper function for printing CNuclearPotentialMatrix

std::string
CNuclearPotentialMatrix_str (const CNuclearPotentialMatrix& self)
{
    return self.getString();
}

// Exports classes/functions in src/oneints to python

void export_oneints()
{
    // initialize mpi4py's C-API

    if (import_mpi4py() < 0) return;

    // COverlapMatrix class

    bp::class_< COverlapMatrix, std::shared_ptr<COverlapMatrix> >
        (
            "COverlapMatrix",
            bp::init<const CDenseMatrix&>()
        )
        .def(bp::init<>())
        .def("__str__", &bp_oneints::COverlapMatrix_str)
        .def(bp::self == bp::other<COverlapMatrix>())
    ;

    // COverlapIntegralsDriver class

    bp::class_< COverlapIntegralsDriver, std::shared_ptr<COverlapIntegralsDriver> >
        (
            "COverlapIntegralsDriver",
            bp::init<const int32_t, const int32_t, MPI_Comm>()
        )
        .def("create", &bp_oneints::COverlapIntegralsDriver_create)
        .staticmethod("create")
        .def("compute", &bp_oneints::COverlapIntegralsDriver_compute_1)
        .def("compute", &bp_oneints::COverlapIntegralsDriver_compute_2)
        .def("compute", &bp_oneints::COverlapIntegralsDriver_compute_3)
        .def("compute", &bp_oneints::COverlapIntegralsDriver_compute_4)
    ;

    // CKineticEnergyMatrix class

    bp::class_< CKineticEnergyMatrix, std::shared_ptr<CKineticEnergyMatrix> >
        (
            "CKineticEnergyMatrix",
            bp::init<const CDenseMatrix&>()
        )
        .def(bp::init<>())
        .def("__str__", &bp_oneints::CKineticEnergyMatrix_str)
        .def(bp::self == bp::other<CKineticEnergyMatrix>())
    ;

    // CKineticEnergyIntegralsDriver class

    bp::class_< CKineticEnergyIntegralsDriver, std::shared_ptr<CKineticEnergyIntegralsDriver> >
        (
            "CKineticEnergyIntegralsDriver",
            bp::init<const int32_t, const int32_t, MPI_Comm>()
        )
        .def("create", &bp_oneints::CKineticEnergyIntegralsDriver_create)
        .staticmethod("create")
        .def("compute", &bp_oneints::CKineticEnergyIntegralsDriver_compute_1)
        .def("compute", &bp_oneints::CKineticEnergyIntegralsDriver_compute_2)
        .def("compute", &bp_oneints::CKineticEnergyIntegralsDriver_compute_3)
        .def("compute", &bp_oneints::CKineticEnergyIntegralsDriver_compute_4)
    ;

    // CNuclearPotentialMatrix class

    bp::class_< CNuclearPotentialMatrix, std::shared_ptr<CNuclearPotentialMatrix> >
        (
            "CNuclearPotentialMatrix",
            bp::init<const CDenseMatrix&>()
        )
        .def(bp::init<>())
        .def("__str__", &bp_oneints::CNuclearPotentialMatrix_str)
        .def(bp::self == bp::other<CNuclearPotentialMatrix>())
    ;

    // CNuclearPotentialIntegralsDriver class

    bp::class_< CNuclearPotentialIntegralsDriver, std::shared_ptr<CNuclearPotentialIntegralsDriver> >
        (
            "CNuclearPotentialIntegralsDriver",
            bp::init<const int32_t, const int32_t, MPI_Comm>()
        )
        .def("create", &bp_oneints::CNuclearPotentialIntegralsDriver_create)
        .staticmethod("create")
        .def("compute", &bp_oneints::CNuclearPotentialIntegralsDriver_compute_0)
        .def("compute", &bp_oneints::CNuclearPotentialIntegralsDriver_compute_1)
        .def("compute", &bp_oneints::CNuclearPotentialIntegralsDriver_compute_2)
        .def("compute", &bp_oneints::CNuclearPotentialIntegralsDriver_compute_3)
        .def("compute", &bp_oneints::CNuclearPotentialIntegralsDriver_compute_4)
    ;
}

} // bp_oneints namespace
