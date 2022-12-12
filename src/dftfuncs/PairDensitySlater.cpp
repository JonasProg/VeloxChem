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

#include "PairDensitySlater.hpp"

#include <cmath>

#include <iostream>

#include "MathConst.hpp"

namespace pdftslater {  // pdftslater namespace

void
compute_exc_vxc(const int32_t np, const double* rho, double* exc, double* vrho)
{
    double frg = - std::pow(6.0 / mathconst::getPiValue(), 1.0 / 3.0);

    double fre = 0.75 * frg;

    double fp = 1.0 / 3.0;

    for (int32_t g = 0; g < np; g++)
    {
        //density = rho[2 * g + 0];

        //pair_density = rho[2 * g + 1];

        double rhoa = rho[2 * g + 0];

        double rhob = rho[2 * g + 1];

        double fxa = std::pow(rhoa, fp);

        double fxb = std::pow(rhob, fp);

        exc[g] = fre * (rhoa * fxa +  rhob * fxb);
        vrho[2 * g + 0] = 0.0;
        vrho[2 * g + 1] = 0.0;
    }
}

}  // namespace pdftslater
