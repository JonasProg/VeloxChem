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

#include "GtoFuncForMGGA.hpp"

#include <cmath>

#include "GenFunc.hpp"

namespace mggarec {  // mggarec namespace

    void
    compGtoValuesForS(CMemBlock2D<double>& spherGtoGridBuffer,
                      const double*        gridCoordinatesX,
                      const double*        gridCoordinatesY,
                      const double*        gridCoordinatesZ,
                      const int32_t        gridOffset,
                      const CGtoBlock&     gtoBlock,
                      const int32_t        iContrGto)
    {
        // initialize buffer to zero

        spherGtoGridBuffer.zero();

        // set up number of grid points

        auto ngpnts = spherGtoGridBuffer.size(0);

        // set up pointers to primitives data

        auto bfnorms = gtoBlock.getNormFactors();

        auto bfexps = gtoBlock.getExponents();

        // set up pointers to primitives coordinates

        auto bfx = gtoBlock.getCoordinatesX();

        auto bfy = gtoBlock.getCoordinatesY();

        auto bfz = gtoBlock.getCoordinatesZ();

        // set up coordinates to primitives positions

        auto spos = gtoBlock.getStartPositions();

        auto epos = gtoBlock.getEndPositions();

        // set up pointer to spherical GTOs values

        auto f0_0 = spherGtoGridBuffer.data(0);

        auto fx_0 = spherGtoGridBuffer.data(1);

        auto fy_0 = spherGtoGridBuffer.data(2);

        auto fz_0 = spherGtoGridBuffer.data(3);

        auto fxx_0 = spherGtoGridBuffer.data(4);

        auto fxy_0 = spherGtoGridBuffer.data(5);

        auto fxz_0 = spherGtoGridBuffer.data(6);

        auto fyy_0 = spherGtoGridBuffer.data(7);

        auto fyz_0 = spherGtoGridBuffer.data(8);

        auto fzz_0 = spherGtoGridBuffer.data(9);

        // initialize Cartesian buffer to zero

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // primitive data

            auto bexp = bfexps[i];

            auto bnorm = bfnorms[i];

            // primitive position

            auto rx = bfx[i];

            auto ry = bfy[i];

            auto rz = bfz[i];

            // loop over grid points

            #pragma omp simd
            for (int32_t j = 0; j < ngpnts; j++)
            {
                double dx = gridCoordinatesX[gridOffset + j] - rx;

                double dy = gridCoordinatesY[gridOffset + j] - ry;

                double dz = gridCoordinatesZ[gridOffset + j] - rz;

                double g0 = bnorm * std::exp(-bexp * (dx * dx + dy * dy + dz * dz));

                double g1 = -2.0 * bexp * g0;

                double g2 = -2.0 * bexp * g1;

                f0_0[j] += g0;

                fx_0[j] += dx * g1;

                fy_0[j] += dy * g1;

                fz_0[j] += dz * g1;

                fxx_0[j] += (dx * dx) * g2 + g1;

                fxy_0[j] += (dx * dy) * g2;

                fxz_0[j] += (dx * dz) * g2;

                fyy_0[j] += (dy * dy) * g2 + g1;

                fyz_0[j] += (dy * dz) * g2;

                fzz_0[j] += (dz * dz) * g2 + g1;
            }
        }
    }

    void
    compGtoValuesForP(CMemBlock2D<double>& spherGtoGridBuffer,
                      CMemBlock2D<double>& cartGtoGridBuffer,
                      const double*        gridCoordinatesX,
                      const double*        gridCoordinatesY,
                      const double*        gridCoordinatesZ,
                      const int32_t        gridOffset,
                      const CGtoBlock&     gtoBlock,
                      const int32_t        iContrGto)
    {
        // initialize buffers to zero

        spherGtoGridBuffer.zero();

        cartGtoGridBuffer.zero();

        // set up number of grid points

        auto ngpnts = spherGtoGridBuffer.size(0);

        // set up pointers to primitives data

        auto bfnorms = gtoBlock.getNormFactors();

        auto bfexps = gtoBlock.getExponents();

        // set up pointers to primitives coordinates

        auto bfx = gtoBlock.getCoordinatesX();

        auto bfy = gtoBlock.getCoordinatesY();

        auto bfz = gtoBlock.getCoordinatesZ();

        // set up coordinates to primitives positions

        auto spos = gtoBlock.getStartPositions();

        auto epos = gtoBlock.getEndPositions();

        // set up pointer to Cartesian GTOs values

        auto f0_x = cartGtoGridBuffer.data(0);

        auto fx_x = cartGtoGridBuffer.data(1);

        auto fy_x = cartGtoGridBuffer.data(2);

        auto fz_x = cartGtoGridBuffer.data(3);

        auto fxx_x = cartGtoGridBuffer.data(4);

        auto fxy_x = cartGtoGridBuffer.data(5);

        auto fxz_x = cartGtoGridBuffer.data(6);

        auto fyy_x = cartGtoGridBuffer.data(7);

        auto fyz_x = cartGtoGridBuffer.data(8);

        auto fzz_x = cartGtoGridBuffer.data(9);

        auto f0_y = cartGtoGridBuffer.data(10);

        auto fx_y = cartGtoGridBuffer.data(11);

        auto fy_y = cartGtoGridBuffer.data(12);

        auto fz_y = cartGtoGridBuffer.data(13);

        auto fxx_y = cartGtoGridBuffer.data(14);

        auto fxy_y = cartGtoGridBuffer.data(15);

        auto fxz_y = cartGtoGridBuffer.data(16);

        auto fyy_y = cartGtoGridBuffer.data(17);

        auto fyz_y = cartGtoGridBuffer.data(18);

        auto fzz_y = cartGtoGridBuffer.data(19);

        auto f0_z = cartGtoGridBuffer.data(20);

        auto fx_z = cartGtoGridBuffer.data(21);

        auto fy_z = cartGtoGridBuffer.data(22);

        auto fz_z = cartGtoGridBuffer.data(23);

        auto fxx_z = cartGtoGridBuffer.data(24);

        auto fxy_z = cartGtoGridBuffer.data(25);

        auto fxz_z = cartGtoGridBuffer.data(26);

        auto fyy_z = cartGtoGridBuffer.data(27);

        auto fyz_z = cartGtoGridBuffer.data(28);

        auto fzz_z = cartGtoGridBuffer.data(29);

        // initialize Cartesian buffer to zero

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // primitive data

            auto bexp = bfexps[i];

            auto bnorm = bfnorms[i];

            // primitive position

            auto rx = bfx[i];

            auto ry = bfy[i];

            auto rz = bfz[i];

            // loop over grid points

            #pragma omp simd
            for (int32_t j = 0; j < ngpnts; j++)
            {
                double dx = gridCoordinatesX[gridOffset + j] - rx;

                double dy = gridCoordinatesY[gridOffset + j] - ry;

                double dz = gridCoordinatesZ[gridOffset + j] - rz;

                double f0_0 = bnorm * std::exp(-bexp * (dx * dx + dy * dy + dz * dz));

                double fg_0 = -2.0 * bexp;

                double fg_1 = f0_0 * fg_0;

                double fg_2 = fg_1 * fg_0;

                // leading p_x

                f0_x[j] += f0_0 * dx;

                fx_x[j] += f0_0 * (1.0 + dx * dx * fg_0);

                fy_x[j] += f0_0 * dx * dy * fg_0;

                fz_x[j] += f0_0 * dx * dz * fg_0;

                fxx_x[j] += fg_2 * dx * dx * dx + 3.0 * fg_1 * dx;

                fxy_x[j] += fg_2 * dx * dx * dy + fg_1 * dy;

                fxz_x[j] += fg_2 * dx * dx * dz + fg_1 * dz;

                fyy_x[j] += fg_2 * dx * dy * dy + fg_1 * dx;

                fyz_x[j] += fg_2 * dx * dy * dz;

                fzz_x[j] += fg_2 * dx * dz * dz + fg_1 * dx;

                // leading p_y

                f0_y[j] += f0_0 * dy;

                fx_y[j] += f0_0 * dy * dx * fg_0;

                fy_y[j] += f0_0 * (1.0 + dy * dy * fg_0);

                fz_y[j] += f0_0 * dy * dz * fg_0;

                fxx_y[j] += fg_2 * dy * dx * dx + fg_1 * dy;

                fxy_y[j] += fg_2 * dy * dy * dx + fg_1 * dx;

                fxz_y[j] += fg_2 * dy * dx * dz;

                fyy_y[j] += fg_2 * dy * dy * dy + 3.0 * fg_1 * dy;

                fyz_y[j] += fg_2 * dy * dy * dz + fg_1 * dz;

                fzz_y[j] += fg_2 * dy * dz * dz + fg_1 * dy;

                // leading p_z

                f0_z[j] += f0_0 * dz;

                fx_z[j] += f0_0 * dz * dx * fg_0;

                fy_z[j] += f0_0 * dz * dy * fg_0;

                fz_z[j] += f0_0 * (1.0 + dz * dz * fg_0);

                fxx_z[j] += fg_2 * dz * dx * dx + fg_1 * dz;

                fxy_z[j] += fg_2 * dz * dy * dx;

                fxz_z[j] += fg_2 * dz * dz * dx + fg_1 * dx;

                fyy_z[j] += fg_2 * dz * dy * dy + fg_1 * dz;

                fyz_z[j] += fg_2 * dz * dz * dy + fg_1 * dy;

                fzz_z[j] += fg_2 * dz * dz * dz + 3.0 * fg_1 * dz;
            }
        }

        genfunc::transform(spherGtoGridBuffer, cartGtoGridBuffer, CSphericalMomentum(1), 0, 0, ngpnts, 10);
    }

    void
    compGtoValuesForD(CMemBlock2D<double>& spherGtoGridBuffer,
                      CMemBlock2D<double>& cartGtoGridBuffer,
                      const double*        gridCoordinatesX,
                      const double*        gridCoordinatesY,
                      const double*        gridCoordinatesZ,
                      const int32_t        gridOffset,
                      const CGtoBlock&     gtoBlock,
                      const int32_t        iContrGto)
    {
        // initialize buffer to zero

        spherGtoGridBuffer.zero();

        cartGtoGridBuffer.zero();

        // set up number of grid points

        auto ngpnts = spherGtoGridBuffer.size(0);

        // set up pointers to primitives data

        auto bfnorms = gtoBlock.getNormFactors();

        auto bfexps = gtoBlock.getExponents();

        // set up pointers to primitives coordinates

        auto bfx = gtoBlock.getCoordinatesX();

        auto bfy = gtoBlock.getCoordinatesY();

        auto bfz = gtoBlock.getCoordinatesZ();

        // set up coordinates to primitives positions

        auto spos = gtoBlock.getStartPositions();

        auto epos = gtoBlock.getEndPositions();

        // set up pointer to spherical GTOs values

        auto f0_xx = cartGtoGridBuffer.data(0);

        auto fx_xx = cartGtoGridBuffer.data(1);

        auto fy_xx = cartGtoGridBuffer.data(2);

        auto fz_xx = cartGtoGridBuffer.data(3);

        auto fxx_xx = cartGtoGridBuffer.data(4);

        auto fxy_xx = cartGtoGridBuffer.data(5);

        auto fxz_xx = cartGtoGridBuffer.data(6);

        auto fyy_xx = cartGtoGridBuffer.data(7);

        auto fyz_xx = cartGtoGridBuffer.data(8);

        auto fzz_xx = cartGtoGridBuffer.data(9);

        auto f0_xy = cartGtoGridBuffer.data(10);

        auto fx_xy = cartGtoGridBuffer.data(11);

        auto fy_xy = cartGtoGridBuffer.data(12);

        auto fz_xy = cartGtoGridBuffer.data(13);

        auto fxx_xy = cartGtoGridBuffer.data(14);

        auto fxy_xy = cartGtoGridBuffer.data(15);

        auto fxz_xy = cartGtoGridBuffer.data(16);

        auto fyy_xy = cartGtoGridBuffer.data(17);

        auto fyz_xy = cartGtoGridBuffer.data(18);

        auto fzz_xy = cartGtoGridBuffer.data(19);

        auto f0_xz = cartGtoGridBuffer.data(20);

        auto fx_xz = cartGtoGridBuffer.data(21);

        auto fy_xz = cartGtoGridBuffer.data(22);

        auto fz_xz = cartGtoGridBuffer.data(23);

        auto fxx_xz = cartGtoGridBuffer.data(24);

        auto fxy_xz = cartGtoGridBuffer.data(25);

        auto fxz_xz = cartGtoGridBuffer.data(26);

        auto fyy_xz = cartGtoGridBuffer.data(27);

        auto fyz_xz = cartGtoGridBuffer.data(28);

        auto fzz_xz = cartGtoGridBuffer.data(29);

        auto f0_yy = cartGtoGridBuffer.data(30);

        auto fx_yy = cartGtoGridBuffer.data(31);

        auto fy_yy = cartGtoGridBuffer.data(32);

        auto fz_yy = cartGtoGridBuffer.data(33);

        auto fxx_yy = cartGtoGridBuffer.data(34);

        auto fxy_yy = cartGtoGridBuffer.data(35);

        auto fxz_yy = cartGtoGridBuffer.data(36);

        auto fyy_yy = cartGtoGridBuffer.data(37);

        auto fyz_yy = cartGtoGridBuffer.data(38);

        auto fzz_yy = cartGtoGridBuffer.data(39);

        auto f0_yz = cartGtoGridBuffer.data(40);

        auto fx_yz = cartGtoGridBuffer.data(41);

        auto fy_yz = cartGtoGridBuffer.data(42);

        auto fz_yz = cartGtoGridBuffer.data(43);

        auto fxx_yz = cartGtoGridBuffer.data(44);

        auto fxy_yz = cartGtoGridBuffer.data(45);

        auto fxz_yz = cartGtoGridBuffer.data(46);

        auto fyy_yz = cartGtoGridBuffer.data(47);

        auto fyz_yz = cartGtoGridBuffer.data(48);

        auto fzz_yz = cartGtoGridBuffer.data(49);

        auto f0_zz = cartGtoGridBuffer.data(50);

        auto fx_zz = cartGtoGridBuffer.data(51);

        auto fy_zz = cartGtoGridBuffer.data(52);

        auto fz_zz = cartGtoGridBuffer.data(53);

        auto fxx_zz = cartGtoGridBuffer.data(54);

        auto fxy_zz = cartGtoGridBuffer.data(55);

        auto fxz_zz = cartGtoGridBuffer.data(56);

        auto fyy_zz = cartGtoGridBuffer.data(57);

        auto fyz_zz = cartGtoGridBuffer.data(58);

        auto fzz_zz = cartGtoGridBuffer.data(59);

        // initialize Cartesian buffer to zero

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // primitive data

            auto bexp = bfexps[i];

            auto bnorm = bfnorms[i];

            // primitive position

            auto rx = bfx[i];

            auto ry = bfy[i];

            auto rz = bfz[i];

            // loop over grid points

            #pragma omp simd
            for (int32_t j = 0; j < ngpnts; j++)
            {
                double dx = gridCoordinatesX[gridOffset + j] - rx;

                double dy = gridCoordinatesY[gridOffset + j] - ry;

                double dz = gridCoordinatesZ[gridOffset + j] - rz;

                double f0_0 = bnorm * std::exp(-bexp * (dx * dx + dy * dy + dz * dz));

                double fg_0 = -2.0 * bexp;

                double fg_1 = f0_0 * fg_0;

                double fg_2 = fg_1 * fg_0;

                // leading xx component

                double f0_x = dx * f0_0;

                f0_xx[j] += f0_x * dx;

                fx_xx[j] += f0_x * (2.0 + fg_0 * dx * dx);

                fy_xx[j] += f0_x * fg_0 * dx * dy;

                fz_xx[j] += f0_x * fg_0 * dx * dz;

                fxx_xx[j] += fg_2 * dx * dx * dx * dx + 5.0 * fg_1 * dx * dx + 2.0 * f0_0;

                fxy_xx[j] += fg_2 * dx * dx * dx * dy + 2.0 * fg_1 * dx * dy;

                fxz_xx[j] += fg_2 * dx * dx * dx * dz + 2.0 * fg_1 * dx * dz;

                fyy_xx[j] += fg_2 * dx * dx * dy * dy + 1.0 * fg_1 * dx * dx;

                fyz_xx[j] += fg_2 * dx * dx * dy * dz;

                fzz_xx[j] += fg_2 * dx * dx * dz * dz + 1.0 * fg_1 * dx * dx;

                // leading xy component

                double f0_y = dy * f0_0;

                f0_xy[j] += f0_x * dy;

                fx_xy[j] += f0_y * (1.0 + fg_0 * dx * dx);

                fy_xy[j] += f0_x * (1.0 + fg_0 * dy * dy);

                fz_xy[j] += f0_x * fg_0 * dy * dz;

                fxx_xy[j] += fg_2 * dx * dx * dx * dy + 3.0 * fg_1 * dx * dy;

                fxy_xy[j] += fg_2 * dx * dx * dy * dy + 1.0 * fg_1 * (dx * dx + dy * dy) + f0_0;

                fxz_xy[j] += fg_2 * dx * dx * dy * dz + 1.0 * fg_1 * dy * dz;

                fyy_xy[j] += fg_2 * dy * dy * dy * dx + 3.0 * fg_1 * dy * dx;

                fyz_xy[j] += fg_2 * dy * dy * dx * dz + 1.0 * fg_1 * dx * dz;

                fzz_xy[j] += fg_2 * dx * dy * dz * dz + 1.0 * fg_1 * dx * dy;

                // leading xz component

                double f0_z = dz * f0_0;

                f0_xz[j] += f0_x * dz;

                fx_xz[j] += f0_z * (1.0 + fg_0 * dx * dx);

                fy_xz[j] += f0_x * fg_0 * dz * dy;

                fz_xz[j] += f0_x * (1.0 + fg_0 * dz * dz);

                fxx_xz[j] += fg_2 * dx * dx * dx * dz + 3.0 * fg_1 * dx * dz;

                fxy_xz[j] += fg_2 * dx * dx * dz * dy + 1.0 * fg_1 * dz * dy;

                fxz_xz[j] += fg_2 * dx * dx * dz * dz + 1.0 * fg_1 * (dx * dx + dz * dz) + f0_0;

                fyy_xz[j] += fg_2 * dx * dz * dy * dy + 1.0 * fg_1 * dx * dz;

                fyz_xz[j] += fg_2 * dz * dz * dx * dy + 1.0 * fg_1 * dx * dy;

                fzz_xz[j] += fg_2 * dz * dz * dz * dx + 3.0 * fg_1 * dz * dx;

                // leading yy component

                f0_yy[j] += f0_y * dy;

                fx_yy[j] += f0_y * fg_0 * dy * dx;

                fy_yy[j] += f0_y * (2.0 + fg_0 * dy * dy);

                fz_yy[j] += f0_y * fg_0 * dy * dz;

                fxx_yy[j] += fg_2 * dy * dy * dx * dx + 1.0 * fg_1 * dy * dy;

                fxy_yy[j] += fg_2 * dy * dy * dy * dx + 2.0 * fg_1 * dy * dx;

                fxz_yy[j] += fg_2 * dy * dy * dx * dz;

                fyy_yy[j] += fg_2 * dy * dy * dy * dy + 5.0 * fg_1 * dy * dy + 2.0 * f0_0;

                fyz_yy[j] += fg_2 * dy * dy * dy * dz + 2.0 * fg_1 * dy * dz;

                fzz_yy[j] += fg_2 * dy * dy * dz * dz + 1.0 * fg_1 * dy * dy;

                // leading yz component

                f0_yz[j] += f0_y * dz;

                fx_yz[j] += f0_y * fg_0 * dz * dx;

                fy_yz[j] += f0_z * (1.0 + fg_0 * dy * dy);

                fz_yz[j] += f0_y * (1.0 + fg_0 * dz * dz);

                fxx_yz[j] += fg_2 * dz * dy * dx * dx + 1.0 * fg_1 * dz * dy;

                fxy_yz[j] += fg_2 * dy * dy * dz * dx + 1.0 * fg_1 * dz * dx;

                fxz_yz[j] += fg_2 * dz * dz * dy * dx + 1.0 * fg_1 * dy * dx;

                fyy_yz[j] += fg_2 * dy * dy * dy * dz + 3.0 * fg_1 * dy * dz;

                fyz_yz[j] += fg_2 * dz * dz * dy * dy + 1.0 * fg_1 * (dz * dz + dy * dy) + f0_0;

                fzz_yz[j] += fg_2 * dz * dz * dz * dy + 3.0 * fg_1 * dz * dy;

                // leading zz component

                f0_zz[j] += f0_z * dz;

                fx_zz[j] += f0_z * fg_0 * dz * dx;

                fy_zz[j] += f0_z * fg_0 * dz * dy;

                fz_zz[j] += f0_z * (2.0 + fg_0 * dz * dz);

                fxx_zz[j] += fg_2 * dz * dz * dx * dx + 1.0 * fg_1 * dz * dz;

                fxy_zz[j] += fg_2 * dz * dz * dy * dx;

                fxz_zz[j] += fg_2 * dz * dz * dz * dx + 2.0 * fg_1 * dz * dx;

                fyy_zz[j] += fg_2 * dz * dz * dy * dy + 1.0 * fg_1 * dz * dz;

                fyz_zz[j] += fg_2 * dz * dz * dz * dy + 2.0 * fg_1 * dz * dy;

                fzz_zz[j] += fg_2 * dz * dz * dz * dz + 5.0 * fg_1 * dz * dz + 2.0 * f0_0;
            }
        }

        genfunc::transform(spherGtoGridBuffer, cartGtoGridBuffer, CSphericalMomentum(2), 0, 0, ngpnts, 10);
    }

}  // namespace mggarec
