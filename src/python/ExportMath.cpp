//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>

#include <memory>
#include <vector>

#ifdef ENABLE_MKL
#include "mkl.h"
#else
#include "cblas.h"
#endif

#include "DenseMatrix.hpp"
#include "ErrorHandler.hpp"
#include "ExportGeneral.hpp"
#include "ExportMath.hpp"
#include "MathConst.hpp"
#include "TwoIndexes.hpp"

namespace py = pybind11;

namespace vlx_math {  // vlx_math namespace

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
    return vlx_general::pointer_to_numpy(self.values(), self.getNumberOfRows(), self.getNumberOfColumns());
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

    errors::assertMsgCritical(c_style | f_style, errsrc);

    // create CDenseMatrix from numpy array

    std::vector<double> vec(arr.size());

    if (c_style)
    {
        std::memcpy(vec.data(), arr.data(), arr.size() * sizeof(double));
    }
    else if (f_style)
    {
        for (ssize_t i = 0; i < arr.shape(0); i++)
        {
            for (ssize_t j = 0; j < arr.shape(1); j++)
            {
                vec.data()[i * arr.shape(1) + j] = arr.data()[j * arr.shape(0) + i];
            }
        }
    }

    int32_t nrows = static_cast<int32_t>(arr.shape(0));

    int32_t ncols = static_cast<int32_t>(arr.shape(1));

    return std::shared_ptr<CDenseMatrix>(new CDenseMatrix(vec, nrows, ncols));
}

static py::array_t<double>
matmul(const py::array_t<double>& A, const py::array_t<double>& B)
{
    // check dimension and shape

    errors::assertMsgCritical(A.ndim() == 2, "matmul - Invalid shape of matrix A");

    errors::assertMsgCritical(B.ndim() == 2, "matmul - Invalid shape of matrix B");

    auto nrow_A = A.shape(0);

    auto ncol_A = A.shape(1);

    auto nrow_B = B.shape(0);

    auto ncol_B = B.shape(1);

    errors::assertMsgCritical(ncol_A == nrow_B, "matmul - Inconsistent sizes");

    // check storage style

    auto c_style_A = py::detail::check_flags(A.ptr(), py::array::c_style);

    auto f_style_A = py::detail::check_flags(A.ptr(), py::array::f_style);

    errors::assertMsgCritical(c_style_A | f_style_A, "matmul - Matrix A is noncontiguous");

    auto c_style_B = py::detail::check_flags(B.ptr(), py::array::c_style);

    auto f_style_B = py::detail::check_flags(B.ptr(), py::array::f_style);

    errors::assertMsgCritical(c_style_B | f_style_B, "matmul - Matrix B is noncontiguous");

    // check transpose

    auto trans_A = CblasNoTrans;

    auto lda_A = ncol_A;

    if (f_style_A)
    {
        trans_A = CblasTrans;

        lda_A = nrow_A;
    }

    auto trans_B = CblasNoTrans;

    auto lda_B = ncol_B;

    if (f_style_B)
    {
        trans_B = CblasTrans;

        lda_B = nrow_B;
    }

    // compute matrix-matrix multiplication

    py::array_t<double> C({nrow_A, ncol_B});

    auto lda_C = ncol_B;

    cblas_dgemm(CblasRowMajor,
                trans_A,
                trans_B,
                nrow_A,
                ncol_B,
                ncol_A,
                1.0,
                A.data(),
                lda_A,
                B.data(),
                lda_B,
                0.0,
                C.mutable_data(),
                lda_C);

    return C;
}

// Exports classes/functions in src/math to python

void
export_math(py::module& m)
{
    // CDenseMatrix class

    py::class_<CDenseMatrix, std::shared_ptr<CDenseMatrix>>(m, "DenseMatrix")
        .def(py::init<>())
        .def(py::init<const int32_t>())
        .def(py::init<const int32_t, const int32_t>())
        .def(py::init<const CDenseMatrix&>())
        .def(py::init(&CDenseMatrix_from_numpy))
        .def("__str__", &CDenseMatrix_str)
        .def("to_numpy", &CDenseMatrix_to_numpy)
        .def("number_of_rows", &CDenseMatrix::getNumberOfRows)
        .def("number_of_columns", &CDenseMatrix::getNumberOfColumns)
        .def("symmetrize", &CDenseMatrix::symmetrize)
        .def("slice", &CDenseMatrix::slice)
        .def(py::self == py::self);

    // CTwoIndexes class

    py::class_<CTwoIndexes, std::shared_ptr<CTwoIndexes>>(m, "TwoIndexes")
        .def(py::init<>())
        .def(py::init<const int32_t, const int32_t>())
        .def("first", &CTwoIndexes::first)
        .def("second", &CTwoIndexes::second);

    // exposing functions

    m.def("mathconst_pi", &mathconst::getPiValue);

    m.def("matmul", &matmul);
}

}  // namespace vlx_math
