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

#include "MathFunc.hpp"

#include "MathConst.hpp"

namespace mathfunc {  // mathfunc namespace
void
scale(double* vector, const double factor, const int32_t nElements)
{
#pragma omp simd aligned(vector : VLX_ALIGN)
    for (int32_t i = 0; i < nElements; i++)
        vector[i] *= factor;
}

void
add_scaled(double* aVector, const double* bVector, const double factor, const int32_t nElements)
{
#pragma omp simd aligned(aVector, bVector : VLX_ALIGN)
    for (int32_t i = 0; i < nElements; i++)
    {
        aVector[i] += factor * bVector[i];
    }
}

void
normalize(double* vector, const int32_t nElements)
{
    auto factor = 1.0 / mathfunc::sum(vector, nElements);

#pragma omp simd aligned(vector : VLX_ALIGN)
    for (int32_t i = 0; i < nElements; i++)
        vector[i] *= factor;
}

void
indexes(int32_t* aVector, const int32_t* bVector, const int32_t nElements)
{
    int32_t index = 0;

    for (int32_t i = 0; i < nElements; i++)
    {
        aVector[i] = index;

        index += bVector[i];
    }
}

void
indexes(int32_t* aVector, const int32_t* bVector, const int32_t offset, const int32_t nElements)
{
    int32_t index = offset;

    for (int32_t i = 0; i < nElements; i++)
    {
        aVector[i] = index;

        index += bVector[i];
    }
}

void
ordering(int32_t* aVector, const int32_t* bVector, const int32_t nElements)
{
    int32_t cidx = 0;

    for (int32_t i = 0; i < nElements; i++)
    {
        if (bVector[i] == 1)
        {
            aVector[cidx] = i;

            cidx++;
        }
    }
}

void
distances(double*       abDistancesX,
          double*       abDistancesY,
          double*       abDistancesZ,
          const double  aCoordX,
          const double  aCoordY,
          const double  aCoordZ,
          const double* bCoordsX,
          const double* bCoordsY,
          const double* bCoordsZ,
          const int32_t nElements)
{
#pragma omp simd aligned(abDistancesX, abDistancesY, abDistancesZ, bCoordsX, bCoordsY, bCoordsZ : VLX_ALIGN)
    for (int32_t i = 0; i < nElements; i++)
    {
        abDistancesX[i] = aCoordX - bCoordsX[i];

        abDistancesY[i] = aCoordY - bCoordsY[i];

        abDistancesZ[i] = aCoordZ - bCoordsZ[i];
    }
}

void
quadChebyshevOfKindTwo(double* coordinates, double* weights, const int32_t nPoints)
{
    // prefactor

    auto fstep = mathconst::getPiValue() / (static_cast<double>(nPoints) + 1.0);

    // loop over grid points

    for (int32_t i = 1; i < nPoints + 1; i++)
    {
        auto farg = static_cast<double>(i) * fstep;

        coordinates[i - 1] = std::cos(farg);

        auto warg = std::sin(farg);

        weights[i - 1] = fstep * warg * warg;
    }
}

int32_t
maxTensorComponents(const int32_t order)
{
    int32_t ncomps = 0;

    if (order == 0) ncomps = 1;

    if (order > 0)
    {
        ncomps = 3;

        for (int32_t i = 1; i < order; i++)
        {
            ncomps *= 3;
        }
    }

    return ncomps;
}

}  // namespace mathfunc
