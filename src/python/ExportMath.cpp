//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/operators.h>

#include <memory>
#include <vector>

#include "DenseMatrix.hpp"
#include "MathConst.hpp"
#include "ErrorHandler.hpp"
#include "ExportGeneral.hpp"
#include "ExportMath.hpp"

namespace py = pybind11;

namespace bp_math { // bp_math namespace

// Helper function for printing CDenseMatrix

static std::string
CDenseMatrix_str(const CDenseMatrix& self)
{
    return self.getString();
}

// Helper function for converting CDenseMatrix to numpy array

static py::array_t<double>
CDenseMatrix_to_numpy(const CDenseMatrix& self)
{
    return bp_general::pointer_to_numpy(self.values(),
                                        self.getNumberOfRows(),
                                        self.getNumberOfColumns());
}

// Helper function for CDenseMatrix constructor
// Not a static function; used in other files

std::shared_ptr<CDenseMatrix>
CDenseMatrix_from_numpy(const py::array_t<double>& arr)
{
    // check dimension

    std::string errdim("Matrix_from_numpy: need a 2D numpy array");

    errors::assertMsgCritical(arr.ndim() == 2, errdim);

    if (arr.data() == nullptr || arr.size() == 0)
    {
        return std::shared_ptr<CDenseMatrix>(new CDenseMatrix());
    }

    // check that the numpy array is c-style contiguous

    std::string errsrc("Matrix_from_numpy: need a contiguous numpy array");

    auto c_style = py::detail::check_flags(arr.ptr(), py::array::c_style);

    auto f_style = py::detail::check_flags(arr.ptr(), py::array::f_style);

    errors::assertMsgCritical(c_style ^ f_style, errsrc);

    // create CDenseMatrix from numpy array

    std::vector<double> vec(arr.size());

    if (c_style)
    {
        std::memcpy(vec.data(), arr.data(), arr.size() * sizeof(double));
    }
    else if (f_style)
    {
        for (size_t i = 0; i < arr.shape(0); i++)
        {
            for (size_t j = 0; j < arr.shape(1); j++)
            {
                vec.data()[i * arr.shape(1) + j] = arr.data()[j * arr.shape(0) + i];
            }
        }
    }

    int32_t nrows = static_cast<int32_t>(arr.shape(0));

    int32_t ncols = static_cast<int32_t>(arr.shape(1));

    return std::shared_ptr<CDenseMatrix>(new CDenseMatrix(vec, nrows, ncols));
}

// Exports classes/functions in src/math to python

void export_math(py::module& m)
{
    // CDenseMatrix class

    py::class_< CDenseMatrix, std::shared_ptr<CDenseMatrix> >
        (
            m, "DenseMatrix"
        )
        .def(py::init<>())
        .def(py::init<const int32_t>())
        .def(py::init<const int32_t, const int32_t>())
        .def(py::init<const CDenseMatrix&>())
        .def(py::init(&CDenseMatrix_from_numpy))
        .def("__str__", &CDenseMatrix_str)
        .def("to_numpy", &CDenseMatrix_to_numpy)
        .def("number_of_rows", &CDenseMatrix::getNumberOfRows)
        .def("number_of_columns", &CDenseMatrix::getNumberOfColumns)
        .def("zero", &CDenseMatrix::zero)
        .def("symmetrize", &CDenseMatrix::symmetrize)
        .def("slice", &CDenseMatrix::slice)
        .def(py::self == py::self)
    ;

    // exposing functions

    m.def("mathconst_pi", &mathconst::getPiValue);
}

} // bp_math namespace
