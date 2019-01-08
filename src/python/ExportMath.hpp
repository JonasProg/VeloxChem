//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef ExportMath_hpp
#define ExportMath_hpp

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <memory>

#include "DenseMatrix.hpp"

namespace py = pybind11;

namespace bp_math { // bp_math namespace

/**
 Converts numpy array to CDenseMatrix

 @param arr the numpy array.
 @return a CDenseMatrix object.
 */
std::shared_ptr<CDenseMatrix>
CDenseMatrix_from_numpy(const py::array_t<double>& arr);

/**
 Exports classes/functions in src/math to python.
 */
void export_math(py::module& m);

} // bp_math namespace

#endif /* ExportMath_hpp */
