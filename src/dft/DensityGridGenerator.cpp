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

#include "DensityGridGenerator.hpp"

#include <cstring>

#include "DenseLinearAlgebra.hpp"

namespace dengridgen {  // dengridgen namespace

CDensityGrid
generateDensityGridForLDA(const int32_t       npoints,
                          const CDenseMatrix& gtoValues,
                          const CDenseMatrix& densityMatrix,
                          const xcfun         xcFunType,
                          CMultiTimer&        timer)
{
    CDensityGrid dengrid(npoints, 1, xcFunType, dengrid::ab);

    dengrid.zero();

    auto rhoa = dengrid.alphaDensity(0);

    auto rhob = dengrid.betaDensity(0);

    // eq.(26), JCTC 2021, 17, 1512-1521

    timer.start("Density grid matmul");

    auto mat_F = denblas::multAB(densityMatrix, gtoValues);

    timer.stop("Density grid matmul");

    // eq.(27), JCTC 2021, 17, 1512-1521

    timer.start("Density grid rho");

    auto naos = gtoValues.getNumberOfRows();

    for (int32_t nu = 0; nu < naos; nu++)
    {
        auto F_nu = mat_F.row(nu);

        auto chi_nu = gtoValues.row(nu);

        for (int32_t g = 0; g < npoints; g++)
        {
            rhoa[g] += F_nu[g] * chi_nu[g];
        }
    }

    std::memcpy(rhob, rhoa, npoints * sizeof(double));

    timer.stop("Density grid rho");

    return dengrid;
}

CDensityGrid
generateDensityGridForGGA(const int32_t           npoints,
                          const CDenseMatrix&     gtoValues,
                          const CDenseMatrix&     gtoValuesX,
                          const CDenseMatrix&     gtoValuesY,
                          const CDenseMatrix&     gtoValuesZ,
                          const CAODensityMatrix& densityMatrix,
                          const xcfun             xcFunType,
                          CMultiTimer&            timer)
{
    CDensityGrid dengrid(npoints, densityMatrix.getNumberOfDensityMatrices(), xcFunType, dengrid::ab);

    dengrid.zero();

    auto rhoa = dengrid.alphaDensity(0);

    auto rhob = dengrid.betaDensity(0);

    auto grada = dengrid.alphaDensityGradient(0);

    auto gradb = dengrid.betaDensityGradient(0);

    auto gradab = dengrid.mixedDensityGradient(0);

    auto gradax = dengrid.alphaDensityGradientX(0);

    auto graday = dengrid.alphaDensityGradientY(0);

    auto gradaz = dengrid.alphaDensityGradientZ(0);

    auto gradbx = dengrid.betaDensityGradientX(0);

    auto gradby = dengrid.betaDensityGradientY(0);

    auto gradbz = dengrid.betaDensityGradientZ(0);

    // eq.(26), JCTC 2021, 17, 1512-1521

    timer.start("Density grid matmul");

    const CDenseMatrix& mat_chi = gtoValues;

    const CDenseMatrix& mat_chi_x = gtoValuesX;

    const CDenseMatrix& mat_chi_y = gtoValuesY;

    const CDenseMatrix& mat_chi_z = gtoValuesZ;

    auto den_mat = densityMatrix.getReferenceToDensity(0);

    auto mat_F = denblas::multAB(den_mat, mat_chi);

    timer.stop("Density grid matmul");

    // eq.(27), JCTC 2021, 17, 1512-1521

    timer.start("Density grid rho");

    auto naos = mat_chi.getNumberOfRows();

    for (int32_t nu = 0; nu < naos; nu++)
    {
        auto F_nu = mat_F.row(nu);

        auto chi_nu = mat_chi.row(nu);

        auto chi_x_nu = mat_chi_x.row(nu);

        auto chi_y_nu = mat_chi_y.row(nu);

        auto chi_z_nu = mat_chi_z.row(nu);

        for (int32_t g = 0; g < npoints; g++)
        {
            rhoa[g] += F_nu[g] * chi_nu[g];

            gradax[g] += 2.0 * F_nu[g] * chi_x_nu[g];

            graday[g] += 2.0 * F_nu[g] * chi_y_nu[g];

            gradaz[g] += 2.0 * F_nu[g] * chi_z_nu[g];
        }
    }

    std::memcpy(rhob, rhoa, npoints * sizeof(double));

    std::memcpy(gradbx, gradax, npoints * sizeof(double));

    std::memcpy(gradby, graday, npoints * sizeof(double));

    std::memcpy(gradbz, gradaz, npoints * sizeof(double));

    for (int32_t g = 0; g < npoints; g++)
    {
        grada[g] = std::sqrt(gradax[g] * gradax[g] + graday[g] * graday[g] + gradaz[g] * gradaz[g]);

        gradb[g] = std::sqrt(gradbx[g] * gradbx[g] + gradby[g] * gradby[g] + gradbz[g] * gradbz[g]);

        gradab[g] = gradax[g] * gradbx[g] + graday[g] * gradby[g] + gradaz[g] * gradbz[g];
    }

    timer.stop("Density grid rho");

    return dengrid;
}

}  // namespace dengridgen
