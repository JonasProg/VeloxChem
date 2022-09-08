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

#ifndef GtoEvaluator_hpp
#define GtoEvaluator_hpp

#include "GtoContainer.hpp"
#include "MemBlock2D.hpp"
#include "XCFuncType.hpp"

namespace gtoeval {  // gtoeval namespace

void computeGtosValuesForGGA(CMemBlock2D<double>&      gtoValues,
                             CMemBlock2D<double>&      gtoValuesX,
                             CMemBlock2D<double>&      gtoValuesY,
                             CMemBlock2D<double>&      gtoValuesZ,
                             const CGtoContainer*      gtoContainer,
                             const double*             gridCoordinatesX,
                             const double*             gridCoordinatesY,
                             const double*             gridCoordinatesZ,
                             const int32_t             gridBlockPosition,
                             const int32_t             gridOffset,
                             const int32_t             nGridPoints,
                             const CMemBlock<int32_t>& skipCgtoIds);

}  // namespace gtoeval

#endif /* GtoEvaluator_hpp */
