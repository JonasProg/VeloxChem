//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "ExportXTB.hpp"

#include <memory>

#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <mpi.h>

#include "ExportGeneral.hpp"
#include "Molecule.hpp"
#include "XTBDriver.hpp"

namespace py = pybind11;

namespace vlx_xtb {  // vlx_xtb namespace

// Exports classes/functions in src/xtb to python

// Helper function for CXTBDriver constructor

static std::shared_ptr<CXTBDriver>
CXTBDriver_create(py::object py_comm)
{
    if (py_comm.is_none())
    {
        return std::make_shared<CXTBDriver>(MPI_COMM_WORLD);
    }
    else
    {
        auto comm_ptr = vlx_general::get_mpi_comm(py_comm);

        return std::make_shared<CXTBDriver>(*comm_ptr);
    }
}

static py::array_t<double>
CXTBDriver_gradient_to_numpy(CXTBDriver& self)
{
    auto grad = self.getGradient(); 

    return vlx_general::pointer_to_numpy(grad.data(), grad.size() / 3, 3);
}

void
export_xtb(py::module& m)
{
    // CXTBDriver class

    py::class_<CXTBDriver, std::shared_ptr<CXTBDriver>>(m, "XTBDriver")
        .def(py::init(&CXTBDriver_create), py::arg("py_comm") = py::none())
        .def("is_master_node", &CXTBDriver::isMasterNode)
        .def("set_max_iter", &CXTBDriver::setMaxIterations)
        .def("set_elec_temp", &CXTBDriver::setElectronicTemp)
        .def("set_method", &CXTBDriver::setMethod)
        .def("set_output_filename", &CXTBDriver::setOutputFilename)
        .def("get_output", &CXTBDriver::getOutput)
        .def("get_output_filename", &CXTBDriver::getOutputFilename)
        .def("get_energy", &CXTBDriver::getEnergy)
        .def("get_gradient", &CXTBDriver_gradient_to_numpy)
        .def("_compute", &CXTBDriver::compute);
}

}  // namespace vlx_xtb
