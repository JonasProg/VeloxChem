//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "KineticEnergyRecFuncForGG.hpp"

namespace kinrecfunc {  // kinrecfunc namespace

void
compKineticEnergyForGG(CMemBlock2D<double>&       primBuffer,
                       const CRecursionMap&       recursionMap,
                       const CMemBlock2D<double>& osFactors,
                       const CMemBlock2D<double>& paDistances,
                       const CGtoBlock&           braGtoBlock,
                       const CGtoBlock&           ketGtoBlock,
                       const int32_t              iContrGto)
{
    kinrecfunc::compKineticEnergyForGG_0_45(primBuffer, recursionMap, osFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    kinrecfunc::compKineticEnergyForGG_45_90(primBuffer, recursionMap, osFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    kinrecfunc::compKineticEnergyForGG_90_135(primBuffer, recursionMap, osFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    kinrecfunc::compKineticEnergyForGG_135_180(primBuffer, recursionMap, osFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    kinrecfunc::compKineticEnergyForGG_180_225(primBuffer, recursionMap, osFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);
}

void
compKineticEnergyForGG_0_45(CMemBlock2D<double>&       primBuffer,
                            const CRecursionMap&       recursionMap,
                            const CMemBlock2D<double>& osFactors,
                            const CMemBlock2D<double>& paDistances,
                            const CGtoBlock&           braGtoBlock,
                            const CGtoBlock&           ketGtoBlock,
                            const int32_t              iContrGto)
{
    // Batch of Integrals (0,45)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_t_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_t_4_4_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_t_3_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(4 * idx);

        auto fz = osFactors.data(4 * idx + 1);

        auto fga = osFactors.data(4 * idx + 2);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        // set up pointers to auxilary integrals

        auto tt_xxx_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx);

        auto tt_xxx_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 1);

        auto tt_xxx_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 2);

        auto tt_xxx_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 3);

        auto tt_xxx_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 4);

        auto tt_xxx_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 5);

        auto tt_xxx_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 6);

        auto tt_xxx_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 7);

        auto tt_xxx_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 8);

        auto tt_xxx_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 9);

        auto tt_xxx_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 10);

        auto tt_xxx_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 11);

        auto tt_xxx_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 12);

        auto tt_xxx_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 13);

        auto tt_xxx_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 14);

        auto tt_xxy_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 15);

        auto tt_xxy_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 16);

        auto tt_xxy_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 17);

        auto tt_xxy_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 18);

        auto tt_xxy_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 19);

        auto tt_xxy_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 20);

        auto tt_xxy_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 21);

        auto tt_xxy_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 22);

        auto tt_xxy_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 23);

        auto tt_xxy_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 24);

        auto tt_xxy_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 25);

        auto tt_xxy_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 26);

        auto tt_xxy_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 27);

        auto tt_xxy_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 28);

        auto tt_xxy_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 29);

        auto tt_xxz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 30);

        auto tt_xxz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 31);

        auto tt_xxz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 32);

        auto tt_xxz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 33);

        auto tt_xxz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 34);

        auto tt_xxz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 35);

        auto tt_xxz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 36);

        auto tt_xxz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 37);

        auto tt_xxz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 38);

        auto tt_xxz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 39);

        auto tt_xxz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 40);

        auto tt_xxz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 41);

        auto tt_xxz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 42);

        auto tt_xxz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 43);

        auto tt_xxz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 44);

        auto tt_xx_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx);

        auto tt_xx_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 1);

        auto tt_xx_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 2);

        auto tt_xx_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 3);

        auto tt_xx_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 4);

        auto tt_xx_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 5);

        auto tt_xx_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 6);

        auto tt_xx_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 7);

        auto tt_xx_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 8);

        auto tt_xx_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 9);

        auto tt_xx_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 10);

        auto tt_xx_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 11);

        auto tt_xx_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 12);

        auto tt_xx_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 13);

        auto tt_xx_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 14);

        auto tt_xy_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 15);

        auto tt_xy_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 16);

        auto tt_xy_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 17);

        auto tt_xy_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 18);

        auto tt_xy_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 19);

        auto tt_xy_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 20);

        auto tt_xy_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 21);

        auto tt_xy_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 22);

        auto tt_xy_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 23);

        auto tt_xy_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 24);

        auto tt_xy_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 25);

        auto tt_xy_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 26);

        auto tt_xy_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 27);

        auto tt_xy_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 28);

        auto tt_xy_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 29);

        auto tt_xz_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 30);

        auto tt_xz_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 31);

        auto tt_xz_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 32);

        auto tt_xz_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 33);

        auto tt_xz_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 34);

        auto tt_xz_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 35);

        auto tt_xz_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 36);

        auto tt_xz_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 37);

        auto tt_xz_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 38);

        auto tt_xz_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 39);

        auto tt_xz_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 40);

        auto tt_xz_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 41);

        auto tt_xz_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 42);

        auto tt_xz_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 43);

        auto tt_xz_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 44);

        auto tt_xxx_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx);

        auto tt_xxx_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 1);

        auto tt_xxx_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 2);

        auto tt_xxx_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 3);

        auto tt_xxx_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 4);

        auto tt_xxx_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 5);

        auto tt_xxx_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 6);

        auto tt_xxx_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 7);

        auto tt_xxx_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 8);

        auto tt_xxx_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 9);

        auto tt_xxy_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 10);

        auto tt_xxy_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 11);

        auto tt_xxy_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 12);

        auto tt_xxy_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 13);

        auto tt_xxy_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 14);

        auto tt_xxy_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 15);

        auto tt_xxy_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 16);

        auto tt_xxy_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 17);

        auto tt_xxy_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 18);

        auto tt_xxy_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 19);

        auto tt_xxz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 20);

        auto tt_xxz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 21);

        auto tt_xxz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 22);

        auto tt_xxz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 23);

        auto tt_xxz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 24);

        auto tt_xxz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 25);

        auto tt_xxz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 26);

        auto tt_xxz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 27);

        auto tt_xxz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 28);

        auto tt_xxz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 29);

        auto ts_xxxx_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx);

        auto ts_xxxx_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 1);

        auto ts_xxxx_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 2);

        auto ts_xxxx_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 3);

        auto ts_xxxx_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 4);

        auto ts_xxxx_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 5);

        auto ts_xxxx_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 6);

        auto ts_xxxx_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 7);

        auto ts_xxxx_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 8);

        auto ts_xxxx_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 9);

        auto ts_xxxx_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 10);

        auto ts_xxxx_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 11);

        auto ts_xxxx_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 12);

        auto ts_xxxx_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 13);

        auto ts_xxxx_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 14);

        auto ts_xxxy_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 15);

        auto ts_xxxy_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 16);

        auto ts_xxxy_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 17);

        auto ts_xxxy_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 18);

        auto ts_xxxy_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 19);

        auto ts_xxxy_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 20);

        auto ts_xxxy_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 21);

        auto ts_xxxy_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 22);

        auto ts_xxxy_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 23);

        auto ts_xxxy_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 24);

        auto ts_xxxy_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 25);

        auto ts_xxxy_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 26);

        auto ts_xxxy_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 27);

        auto ts_xxxy_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 28);

        auto ts_xxxy_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 29);

        auto ts_xxxz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 30);

        auto ts_xxxz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 31);

        auto ts_xxxz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 32);

        auto ts_xxxz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 33);

        auto ts_xxxz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 34);

        auto ts_xxxz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 35);

        auto ts_xxxz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 36);

        auto ts_xxxz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 37);

        auto ts_xxxz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 38);

        auto ts_xxxz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 39);

        auto ts_xxxz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 40);

        auto ts_xxxz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 41);

        auto ts_xxxz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 42);

        auto ts_xxxz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 43);

        auto ts_xxxz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 44);

        auto ts_xx_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx);

        auto ts_xx_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 1);

        auto ts_xx_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 2);

        auto ts_xx_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 3);

        auto ts_xx_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 4);

        auto ts_xx_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 5);

        auto ts_xx_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 6);

        auto ts_xx_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 7);

        auto ts_xx_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 8);

        auto ts_xx_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 9);

        auto ts_xx_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 10);

        auto ts_xx_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 11);

        auto ts_xx_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 12);

        auto ts_xx_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 13);

        auto ts_xx_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 14);

        auto ts_xy_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 15);

        auto ts_xy_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 16);

        auto ts_xy_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 17);

        auto ts_xy_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 18);

        auto ts_xy_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 19);

        auto ts_xy_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 20);

        auto ts_xy_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 21);

        auto ts_xy_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 22);

        auto ts_xy_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 23);

        auto ts_xy_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 24);

        auto ts_xy_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 25);

        auto ts_xy_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 26);

        auto ts_xy_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 27);

        auto ts_xy_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 28);

        auto ts_xy_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 29);

        auto ts_xz_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 30);

        auto ts_xz_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 31);

        auto ts_xz_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 32);

        auto ts_xz_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 33);

        auto ts_xz_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 34);

        auto ts_xz_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 35);

        auto ts_xz_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 36);

        auto ts_xz_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 37);

        auto ts_xz_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 38);

        auto ts_xz_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 39);

        auto ts_xz_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 40);

        auto ts_xz_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 41);

        auto ts_xz_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 42);

        auto ts_xz_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 43);

        auto ts_xz_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 44);

        // set up pointers to integrals

        auto tt_xxxx_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx);

        auto tt_xxxx_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 1);

        auto tt_xxxx_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 2);

        auto tt_xxxx_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 3);

        auto tt_xxxx_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 4);

        auto tt_xxxx_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 5);

        auto tt_xxxx_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 6);

        auto tt_xxxx_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 7);

        auto tt_xxxx_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 8);

        auto tt_xxxx_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 9);

        auto tt_xxxx_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 10);

        auto tt_xxxx_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 11);

        auto tt_xxxx_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 12);

        auto tt_xxxx_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 13);

        auto tt_xxxx_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 14);

        auto tt_xxxy_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 15);

        auto tt_xxxy_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 16);

        auto tt_xxxy_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 17);

        auto tt_xxxy_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 18);

        auto tt_xxxy_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 19);

        auto tt_xxxy_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 20);

        auto tt_xxxy_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 21);

        auto tt_xxxy_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 22);

        auto tt_xxxy_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 23);

        auto tt_xxxy_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 24);

        auto tt_xxxy_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 25);

        auto tt_xxxy_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 26);

        auto tt_xxxy_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 27);

        auto tt_xxxy_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 28);

        auto tt_xxxy_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 29);

        auto tt_xxxz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 30);

        auto tt_xxxz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 31);

        auto tt_xxxz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 32);

        auto tt_xxxz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 33);

        auto tt_xxxz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 34);

        auto tt_xxxz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 35);

        auto tt_xxxz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 36);

        auto tt_xxxz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 37);

        auto tt_xxxz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 38);

        auto tt_xxxz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 39);

        auto tt_xxxz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 40);

        auto tt_xxxz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 41);

        auto tt_xxxz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 42);

        auto tt_xxxz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 43);

        auto tt_xxxz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 44);

        // Batch of Integrals (0,45)

        #pragma omp simd aligned(fga, fx, fz, pa_x, ts_xx_xxxx_0, ts_xx_xxxy_0, ts_xx_xxxz_0, ts_xx_xxyy_0, \
                                     ts_xx_xxyz_0, ts_xx_xxzz_0, ts_xx_xyyy_0, ts_xx_xyyz_0, ts_xx_xyzz_0, ts_xx_xzzz_0, \
                                     ts_xx_yyyy_0, ts_xx_yyyz_0, ts_xx_yyzz_0, ts_xx_yzzz_0, ts_xx_zzzz_0, \
                                     ts_xxxx_xxxx_0, ts_xxxx_xxxy_0, ts_xxxx_xxxz_0, ts_xxxx_xxyy_0, ts_xxxx_xxyz_0, \
                                     ts_xxxx_xxzz_0, ts_xxxx_xyyy_0, ts_xxxx_xyyz_0, ts_xxxx_xyzz_0, ts_xxxx_xzzz_0, \
                                     ts_xxxx_yyyy_0, ts_xxxx_yyyz_0, ts_xxxx_yyzz_0, ts_xxxx_yzzz_0, ts_xxxx_zzzz_0, \
                                     ts_xxxy_xxxx_0, ts_xxxy_xxxy_0, ts_xxxy_xxxz_0, ts_xxxy_xxyy_0, ts_xxxy_xxyz_0, \
                                     ts_xxxy_xxzz_0, ts_xxxy_xyyy_0, ts_xxxy_xyyz_0, ts_xxxy_xyzz_0, ts_xxxy_xzzz_0, \
                                     ts_xxxy_yyyy_0, ts_xxxy_yyyz_0, ts_xxxy_yyzz_0, ts_xxxy_yzzz_0, ts_xxxy_zzzz_0, \
                                     ts_xxxz_xxxx_0, ts_xxxz_xxxy_0, ts_xxxz_xxxz_0, ts_xxxz_xxyy_0, ts_xxxz_xxyz_0, \
                                     ts_xxxz_xxzz_0, ts_xxxz_xyyy_0, ts_xxxz_xyyz_0, ts_xxxz_xyzz_0, ts_xxxz_xzzz_0, \
                                     ts_xxxz_yyyy_0, ts_xxxz_yyyz_0, ts_xxxz_yyzz_0, ts_xxxz_yzzz_0, ts_xxxz_zzzz_0, \
                                     ts_xy_xxxx_0, ts_xy_xxxy_0, ts_xy_xxxz_0, ts_xy_xxyy_0, ts_xy_xxyz_0, ts_xy_xxzz_0, \
                                     ts_xy_xyyy_0, ts_xy_xyyz_0, ts_xy_xyzz_0, ts_xy_xzzz_0, ts_xy_yyyy_0, ts_xy_yyyz_0, \
                                     ts_xy_yyzz_0, ts_xy_yzzz_0, ts_xy_zzzz_0, ts_xz_xxxx_0, ts_xz_xxxy_0, ts_xz_xxxz_0, \
                                     ts_xz_xxyy_0, ts_xz_xxyz_0, ts_xz_xxzz_0, ts_xz_xyyy_0, ts_xz_xyyz_0, ts_xz_xyzz_0, \
                                     ts_xz_xzzz_0, ts_xz_yyyy_0, ts_xz_yyyz_0, ts_xz_yyzz_0, ts_xz_yzzz_0, ts_xz_zzzz_0, \
                                     tt_xx_xxxx_0, tt_xx_xxxy_0, tt_xx_xxxz_0, tt_xx_xxyy_0, tt_xx_xxyz_0, tt_xx_xxzz_0, \
                                     tt_xx_xyyy_0, tt_xx_xyyz_0, tt_xx_xyzz_0, tt_xx_xzzz_0, tt_xx_yyyy_0, tt_xx_yyyz_0, \
                                     tt_xx_yyzz_0, tt_xx_yzzz_0, tt_xx_zzzz_0, tt_xxx_xxx_0, tt_xxx_xxxx_0, \
                                     tt_xxx_xxxy_0, tt_xxx_xxxz_0, tt_xxx_xxy_0, tt_xxx_xxyy_0, tt_xxx_xxyz_0, \
                                     tt_xxx_xxz_0, tt_xxx_xxzz_0, tt_xxx_xyy_0, tt_xxx_xyyy_0, tt_xxx_xyyz_0, \
                                     tt_xxx_xyz_0, tt_xxx_xyzz_0, tt_xxx_xzz_0, tt_xxx_xzzz_0, tt_xxx_yyy_0, \
                                     tt_xxx_yyyy_0, tt_xxx_yyyz_0, tt_xxx_yyz_0, tt_xxx_yyzz_0, tt_xxx_yzz_0, \
                                     tt_xxx_yzzz_0, tt_xxx_zzz_0, tt_xxx_zzzz_0, tt_xxxx_xxxx_0, tt_xxxx_xxxy_0, \
                                     tt_xxxx_xxxz_0, tt_xxxx_xxyy_0, tt_xxxx_xxyz_0, tt_xxxx_xxzz_0, tt_xxxx_xyyy_0, \
                                     tt_xxxx_xyyz_0, tt_xxxx_xyzz_0, tt_xxxx_xzzz_0, tt_xxxx_yyyy_0, tt_xxxx_yyyz_0, \
                                     tt_xxxx_yyzz_0, tt_xxxx_yzzz_0, tt_xxxx_zzzz_0, tt_xxxy_xxxx_0, tt_xxxy_xxxy_0, \
                                     tt_xxxy_xxxz_0, tt_xxxy_xxyy_0, tt_xxxy_xxyz_0, tt_xxxy_xxzz_0, tt_xxxy_xyyy_0, \
                                     tt_xxxy_xyyz_0, tt_xxxy_xyzz_0, tt_xxxy_xzzz_0, tt_xxxy_yyyy_0, tt_xxxy_yyyz_0, \
                                     tt_xxxy_yyzz_0, tt_xxxy_yzzz_0, tt_xxxy_zzzz_0, tt_xxxz_xxxx_0, tt_xxxz_xxxy_0, \
                                     tt_xxxz_xxxz_0, tt_xxxz_xxyy_0, tt_xxxz_xxyz_0, tt_xxxz_xxzz_0, tt_xxxz_xyyy_0, \
                                     tt_xxxz_xyyz_0, tt_xxxz_xyzz_0, tt_xxxz_xzzz_0, tt_xxxz_yyyy_0, tt_xxxz_yyyz_0, \
                                     tt_xxxz_yyzz_0, tt_xxxz_yzzz_0, tt_xxxz_zzzz_0, tt_xxy_xxx_0, tt_xxy_xxxx_0, \
                                     tt_xxy_xxxy_0, tt_xxy_xxxz_0, tt_xxy_xxy_0, tt_xxy_xxyy_0, tt_xxy_xxyz_0, \
                                     tt_xxy_xxz_0, tt_xxy_xxzz_0, tt_xxy_xyy_0, tt_xxy_xyyy_0, tt_xxy_xyyz_0, \
                                     tt_xxy_xyz_0, tt_xxy_xyzz_0, tt_xxy_xzz_0, tt_xxy_xzzz_0, tt_xxy_yyy_0, \
                                     tt_xxy_yyyy_0, tt_xxy_yyyz_0, tt_xxy_yyz_0, tt_xxy_yyzz_0, tt_xxy_yzz_0, \
                                     tt_xxy_yzzz_0, tt_xxy_zzz_0, tt_xxy_zzzz_0, tt_xxz_xxx_0, tt_xxz_xxxx_0, \
                                     tt_xxz_xxxy_0, tt_xxz_xxxz_0, tt_xxz_xxy_0, tt_xxz_xxyy_0, tt_xxz_xxyz_0, \
                                     tt_xxz_xxz_0, tt_xxz_xxzz_0, tt_xxz_xyy_0, tt_xxz_xyyy_0, tt_xxz_xyyz_0, \
                                     tt_xxz_xyz_0, tt_xxz_xyzz_0, tt_xxz_xzz_0, tt_xxz_xzzz_0, tt_xxz_yyy_0, \
                                     tt_xxz_yyyy_0, tt_xxz_yyyz_0, tt_xxz_yyz_0, tt_xxz_yyzz_0, tt_xxz_yzz_0, \
                                     tt_xxz_yzzz_0, tt_xxz_zzz_0, tt_xxz_zzzz_0, tt_xy_xxxx_0, tt_xy_xxxy_0, \
                                     tt_xy_xxxz_0, tt_xy_xxyy_0, tt_xy_xxyz_0, tt_xy_xxzz_0, tt_xy_xyyy_0, tt_xy_xyyz_0, \
                                     tt_xy_xyzz_0, tt_xy_xzzz_0, tt_xy_yyyy_0, tt_xy_yyyz_0, tt_xy_yyzz_0, tt_xy_yzzz_0, \
                                     tt_xy_zzzz_0, tt_xz_xxxx_0, tt_xz_xxxy_0, tt_xz_xxxz_0, tt_xz_xxyy_0, tt_xz_xxyz_0, \
                                     tt_xz_xxzz_0, tt_xz_xyyy_0, tt_xz_xyyz_0, tt_xz_xyzz_0, tt_xz_xzzz_0, tt_xz_yyyy_0, \
                                     tt_xz_yyyz_0, tt_xz_yyzz_0, tt_xz_yzzz_0, tt_xz_zzzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fga = fga[j];

            double fl1_fx = fx[j];

            double fl1_fz = fz[j];

            tt_xxxx_xxxx_0[j] = pa_x[j] * tt_xxx_xxxx_0[j] + 1.5 * fl1_fx * tt_xx_xxxx_0[j] + 2.0 * fl1_fx * tt_xxx_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxxx_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxxx_0[j];

            tt_xxxx_xxxy_0[j] = pa_x[j] * tt_xxx_xxxy_0[j] + 1.5 * fl1_fx * tt_xx_xxxy_0[j] + 1.5 * fl1_fx * tt_xxx_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxxy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxxy_0[j];

            tt_xxxx_xxxz_0[j] = pa_x[j] * tt_xxx_xxxz_0[j] + 1.5 * fl1_fx * tt_xx_xxxz_0[j] + 1.5 * fl1_fx * tt_xxx_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxxz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxxz_0[j];

            tt_xxxx_xxyy_0[j] = pa_x[j] * tt_xxx_xxyy_0[j] + 1.5 * fl1_fx * tt_xx_xxyy_0[j] + fl1_fx * tt_xxx_xyy_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxyy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxyy_0[j];

            tt_xxxx_xxyz_0[j] = pa_x[j] * tt_xxx_xxyz_0[j] + 1.5 * fl1_fx * tt_xx_xxyz_0[j] + fl1_fx * tt_xxx_xyz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxyz_0[j];

            tt_xxxx_xxzz_0[j] = pa_x[j] * tt_xxx_xxzz_0[j] + 1.5 * fl1_fx * tt_xx_xxzz_0[j] + fl1_fx * tt_xxx_xzz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xxzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xxzz_0[j];

            tt_xxxx_xyyy_0[j] = pa_x[j] * tt_xxx_xyyy_0[j] + 1.5 * fl1_fx * tt_xx_xyyy_0[j] + 0.5 * fl1_fx * tt_xxx_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xyyy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xyyy_0[j];

            tt_xxxx_xyyz_0[j] = pa_x[j] * tt_xxx_xyyz_0[j] + 1.5 * fl1_fx * tt_xx_xyyz_0[j] + 0.5 * fl1_fx * tt_xxx_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xyyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xyyz_0[j];

            tt_xxxx_xyzz_0[j] = pa_x[j] * tt_xxx_xyzz_0[j] + 1.5 * fl1_fx * tt_xx_xyzz_0[j] + 0.5 * fl1_fx * tt_xxx_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xyzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xyzz_0[j];

            tt_xxxx_xzzz_0[j] = pa_x[j] * tt_xxx_xzzz_0[j] + 1.5 * fl1_fx * tt_xx_xzzz_0[j] + 0.5 * fl1_fx * tt_xxx_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxxx_xzzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_xx_xzzz_0[j];

            tt_xxxx_yyyy_0[j] = pa_x[j] * tt_xxx_yyyy_0[j] + 1.5 * fl1_fx * tt_xx_yyyy_0[j] + 2.0 * fl1_fz * ts_xxxx_yyyy_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_xx_yyyy_0[j];

            tt_xxxx_yyyz_0[j] = pa_x[j] * tt_xxx_yyyz_0[j] + 1.5 * fl1_fx * tt_xx_yyyz_0[j] + 2.0 * fl1_fz * ts_xxxx_yyyz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_xx_yyyz_0[j];

            tt_xxxx_yyzz_0[j] = pa_x[j] * tt_xxx_yyzz_0[j] + 1.5 * fl1_fx * tt_xx_yyzz_0[j] + 2.0 * fl1_fz * ts_xxxx_yyzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_xx_yyzz_0[j];

            tt_xxxx_yzzz_0[j] = pa_x[j] * tt_xxx_yzzz_0[j] + 1.5 * fl1_fx * tt_xx_yzzz_0[j] + 2.0 * fl1_fz * ts_xxxx_yzzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_xx_yzzz_0[j];

            tt_xxxx_zzzz_0[j] = pa_x[j] * tt_xxx_zzzz_0[j] + 1.5 * fl1_fx * tt_xx_zzzz_0[j] + 2.0 * fl1_fz * ts_xxxx_zzzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_xx_zzzz_0[j];

            tt_xxxy_xxxx_0[j] = pa_x[j] * tt_xxy_xxxx_0[j] + fl1_fx * tt_xy_xxxx_0[j] + 2.0 * fl1_fx * tt_xxy_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xxxx_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xxxx_0[j];

            tt_xxxy_xxxy_0[j] = pa_x[j] * tt_xxy_xxxy_0[j] + fl1_fx * tt_xy_xxxy_0[j] + 1.5 * fl1_fx * tt_xxy_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xxxy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xxxy_0[j];

            tt_xxxy_xxxz_0[j] = pa_x[j] * tt_xxy_xxxz_0[j] + fl1_fx * tt_xy_xxxz_0[j] + 1.5 * fl1_fx * tt_xxy_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xxxz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xxxz_0[j];

            tt_xxxy_xxyy_0[j] = pa_x[j] * tt_xxy_xxyy_0[j] + fl1_fx * tt_xy_xxyy_0[j] + fl1_fx * tt_xxy_xyy_0[j] + 2.0 * fl1_fz * ts_xxxy_xxyy_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xy_xxyy_0[j];

            tt_xxxy_xxyz_0[j] = pa_x[j] * tt_xxy_xxyz_0[j] + fl1_fx * tt_xy_xxyz_0[j] + fl1_fx * tt_xxy_xyz_0[j] + 2.0 * fl1_fz * ts_xxxy_xxyz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xy_xxyz_0[j];

            tt_xxxy_xxzz_0[j] = pa_x[j] * tt_xxy_xxzz_0[j] + fl1_fx * tt_xy_xxzz_0[j] + fl1_fx * tt_xxy_xzz_0[j] + 2.0 * fl1_fz * ts_xxxy_xxzz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xy_xxzz_0[j];

            tt_xxxy_xyyy_0[j] = pa_x[j] * tt_xxy_xyyy_0[j] + fl1_fx * tt_xy_xyyy_0[j] + 0.5 * fl1_fx * tt_xxy_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xyyy_0[j];

            tt_xxxy_xyyz_0[j] = pa_x[j] * tt_xxy_xyyz_0[j] + fl1_fx * tt_xy_xyyz_0[j] + 0.5 * fl1_fx * tt_xxy_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xyyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xyyz_0[j];

            tt_xxxy_xyzz_0[j] = pa_x[j] * tt_xxy_xyzz_0[j] + fl1_fx * tt_xy_xyzz_0[j] + 0.5 * fl1_fx * tt_xxy_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xyzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xyzz_0[j];

            tt_xxxy_xzzz_0[j] = pa_x[j] * tt_xxy_xzzz_0[j] + fl1_fx * tt_xy_xzzz_0[j] + 0.5 * fl1_fx * tt_xxy_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxxy_xzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_xzzz_0[j];

            tt_xxxy_yyyy_0[j] =
                pa_x[j] * tt_xxy_yyyy_0[j] + fl1_fx * tt_xy_yyyy_0[j] + 2.0 * fl1_fz * ts_xxxy_yyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_yyyy_0[j];

            tt_xxxy_yyyz_0[j] =
                pa_x[j] * tt_xxy_yyyz_0[j] + fl1_fx * tt_xy_yyyz_0[j] + 2.0 * fl1_fz * ts_xxxy_yyyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_yyyz_0[j];

            tt_xxxy_yyzz_0[j] =
                pa_x[j] * tt_xxy_yyzz_0[j] + fl1_fx * tt_xy_yyzz_0[j] + 2.0 * fl1_fz * ts_xxxy_yyzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_yyzz_0[j];

            tt_xxxy_yzzz_0[j] =
                pa_x[j] * tt_xxy_yzzz_0[j] + fl1_fx * tt_xy_yzzz_0[j] + 2.0 * fl1_fz * ts_xxxy_yzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_yzzz_0[j];

            tt_xxxy_zzzz_0[j] =
                pa_x[j] * tt_xxy_zzzz_0[j] + fl1_fx * tt_xy_zzzz_0[j] + 2.0 * fl1_fz * ts_xxxy_zzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xy_zzzz_0[j];

            tt_xxxz_xxxx_0[j] = pa_x[j] * tt_xxz_xxxx_0[j] + fl1_fx * tt_xz_xxxx_0[j] + 2.0 * fl1_fx * tt_xxz_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xxxx_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xxxx_0[j];

            tt_xxxz_xxxy_0[j] = pa_x[j] * tt_xxz_xxxy_0[j] + fl1_fx * tt_xz_xxxy_0[j] + 1.5 * fl1_fx * tt_xxz_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xxxy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xxxy_0[j];

            tt_xxxz_xxxz_0[j] = pa_x[j] * tt_xxz_xxxz_0[j] + fl1_fx * tt_xz_xxxz_0[j] + 1.5 * fl1_fx * tt_xxz_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xxxz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xxxz_0[j];

            tt_xxxz_xxyy_0[j] = pa_x[j] * tt_xxz_xxyy_0[j] + fl1_fx * tt_xz_xxyy_0[j] + fl1_fx * tt_xxz_xyy_0[j] + 2.0 * fl1_fz * ts_xxxz_xxyy_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xz_xxyy_0[j];

            tt_xxxz_xxyz_0[j] = pa_x[j] * tt_xxz_xxyz_0[j] + fl1_fx * tt_xz_xxyz_0[j] + fl1_fx * tt_xxz_xyz_0[j] + 2.0 * fl1_fz * ts_xxxz_xxyz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xz_xxyz_0[j];

            tt_xxxz_xxzz_0[j] = pa_x[j] * tt_xxz_xxzz_0[j] + fl1_fx * tt_xz_xxzz_0[j] + fl1_fx * tt_xxz_xzz_0[j] + 2.0 * fl1_fz * ts_xxxz_xxzz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_xz_xxzz_0[j];

            tt_xxxz_xyyy_0[j] = pa_x[j] * tt_xxz_xyyy_0[j] + fl1_fx * tt_xz_xyyy_0[j] + 0.5 * fl1_fx * tt_xxz_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xyyy_0[j];

            tt_xxxz_xyyz_0[j] = pa_x[j] * tt_xxz_xyyz_0[j] + fl1_fx * tt_xz_xyyz_0[j] + 0.5 * fl1_fx * tt_xxz_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xyyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xyyz_0[j];

            tt_xxxz_xyzz_0[j] = pa_x[j] * tt_xxz_xyzz_0[j] + fl1_fx * tt_xz_xyzz_0[j] + 0.5 * fl1_fx * tt_xxz_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xyzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xyzz_0[j];

            tt_xxxz_xzzz_0[j] = pa_x[j] * tt_xxz_xzzz_0[j] + fl1_fx * tt_xz_xzzz_0[j] + 0.5 * fl1_fx * tt_xxz_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxxz_xzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_xzzz_0[j];

            tt_xxxz_yyyy_0[j] =
                pa_x[j] * tt_xxz_yyyy_0[j] + fl1_fx * tt_xz_yyyy_0[j] + 2.0 * fl1_fz * ts_xxxz_yyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_yyyy_0[j];

            tt_xxxz_yyyz_0[j] =
                pa_x[j] * tt_xxz_yyyz_0[j] + fl1_fx * tt_xz_yyyz_0[j] + 2.0 * fl1_fz * ts_xxxz_yyyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_yyyz_0[j];

            tt_xxxz_yyzz_0[j] =
                pa_x[j] * tt_xxz_yyzz_0[j] + fl1_fx * tt_xz_yyzz_0[j] + 2.0 * fl1_fz * ts_xxxz_yyzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_yyzz_0[j];

            tt_xxxz_yzzz_0[j] =
                pa_x[j] * tt_xxz_yzzz_0[j] + fl1_fx * tt_xz_yzzz_0[j] + 2.0 * fl1_fz * ts_xxxz_yzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_yzzz_0[j];

            tt_xxxz_zzzz_0[j] =
                pa_x[j] * tt_xxz_zzzz_0[j] + fl1_fx * tt_xz_zzzz_0[j] + 2.0 * fl1_fz * ts_xxxz_zzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_xz_zzzz_0[j];
        }

        idx++;
    }
}

void
compKineticEnergyForGG_45_90(CMemBlock2D<double>&       primBuffer,
                             const CRecursionMap&       recursionMap,
                             const CMemBlock2D<double>& osFactors,
                             const CMemBlock2D<double>& paDistances,
                             const CGtoBlock&           braGtoBlock,
                             const CGtoBlock&           ketGtoBlock,
                             const int32_t              iContrGto)
{
    // Batch of Integrals (45,90)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_t_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_t_4_4_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_t_3_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(4 * idx);

        auto fz = osFactors.data(4 * idx + 1);

        auto fga = osFactors.data(4 * idx + 2);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        // set up pointers to auxilary integrals

        auto tt_xyy_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 45);

        auto tt_xyy_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 46);

        auto tt_xyy_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 47);

        auto tt_xyy_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 48);

        auto tt_xyy_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 49);

        auto tt_xyy_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 50);

        auto tt_xyy_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 51);

        auto tt_xyy_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 52);

        auto tt_xyy_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 53);

        auto tt_xyy_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 54);

        auto tt_xyy_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 55);

        auto tt_xyy_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 56);

        auto tt_xyy_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 57);

        auto tt_xyy_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 58);

        auto tt_xyy_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 59);

        auto tt_xyz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 60);

        auto tt_xyz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 61);

        auto tt_xyz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 62);

        auto tt_xyz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 63);

        auto tt_xyz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 64);

        auto tt_xyz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 65);

        auto tt_xyz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 66);

        auto tt_xyz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 67);

        auto tt_xyz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 68);

        auto tt_xyz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 69);

        auto tt_xyz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 70);

        auto tt_xyz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 71);

        auto tt_xyz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 72);

        auto tt_xyz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 73);

        auto tt_xyz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 74);

        auto tt_xzz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 75);

        auto tt_xzz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 76);

        auto tt_xzz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 77);

        auto tt_xzz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 78);

        auto tt_xzz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 79);

        auto tt_xzz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 80);

        auto tt_xzz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 81);

        auto tt_xzz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 82);

        auto tt_xzz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 83);

        auto tt_xzz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 84);

        auto tt_xzz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 85);

        auto tt_xzz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 86);

        auto tt_xzz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 87);

        auto tt_xzz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 88);

        auto tt_xzz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 89);

        auto tt_yy_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 45);

        auto tt_yy_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 46);

        auto tt_yy_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 47);

        auto tt_yy_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 48);

        auto tt_yy_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 49);

        auto tt_yy_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 50);

        auto tt_yy_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 51);

        auto tt_yy_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 52);

        auto tt_yy_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 53);

        auto tt_yy_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 54);

        auto tt_yy_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 55);

        auto tt_yy_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 56);

        auto tt_yy_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 57);

        auto tt_yy_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 58);

        auto tt_yy_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 59);

        auto tt_yz_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 60);

        auto tt_yz_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 61);

        auto tt_yz_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 62);

        auto tt_yz_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 63);

        auto tt_yz_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 64);

        auto tt_yz_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 65);

        auto tt_yz_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 66);

        auto tt_yz_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 67);

        auto tt_yz_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 68);

        auto tt_yz_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 69);

        auto tt_yz_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 70);

        auto tt_yz_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 71);

        auto tt_yz_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 72);

        auto tt_yz_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 73);

        auto tt_yz_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 74);

        auto tt_zz_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 75);

        auto tt_zz_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 76);

        auto tt_zz_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 77);

        auto tt_zz_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 78);

        auto tt_zz_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 79);

        auto tt_zz_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 80);

        auto tt_zz_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 81);

        auto tt_zz_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 82);

        auto tt_zz_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 83);

        auto tt_zz_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 84);

        auto tt_zz_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 85);

        auto tt_zz_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 86);

        auto tt_zz_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 87);

        auto tt_zz_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 88);

        auto tt_zz_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 89);

        auto tt_xyy_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 30);

        auto tt_xyy_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 31);

        auto tt_xyy_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 32);

        auto tt_xyy_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 33);

        auto tt_xyy_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 34);

        auto tt_xyy_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 35);

        auto tt_xyy_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 36);

        auto tt_xyy_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 37);

        auto tt_xyy_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 38);

        auto tt_xyy_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 39);

        auto tt_xyz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 40);

        auto tt_xyz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 41);

        auto tt_xyz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 42);

        auto tt_xyz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 43);

        auto tt_xyz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 44);

        auto tt_xyz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 45);

        auto tt_xyz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 46);

        auto tt_xyz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 47);

        auto tt_xyz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 48);

        auto tt_xyz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 49);

        auto tt_xzz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 50);

        auto tt_xzz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 51);

        auto tt_xzz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 52);

        auto tt_xzz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 53);

        auto tt_xzz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 54);

        auto tt_xzz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 55);

        auto tt_xzz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 56);

        auto tt_xzz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 57);

        auto tt_xzz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 58);

        auto tt_xzz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 59);

        auto ts_xxyy_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 45);

        auto ts_xxyy_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 46);

        auto ts_xxyy_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 47);

        auto ts_xxyy_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 48);

        auto ts_xxyy_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 49);

        auto ts_xxyy_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 50);

        auto ts_xxyy_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 51);

        auto ts_xxyy_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 52);

        auto ts_xxyy_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 53);

        auto ts_xxyy_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 54);

        auto ts_xxyy_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 55);

        auto ts_xxyy_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 56);

        auto ts_xxyy_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 57);

        auto ts_xxyy_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 58);

        auto ts_xxyy_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 59);

        auto ts_xxyz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 60);

        auto ts_xxyz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 61);

        auto ts_xxyz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 62);

        auto ts_xxyz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 63);

        auto ts_xxyz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 64);

        auto ts_xxyz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 65);

        auto ts_xxyz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 66);

        auto ts_xxyz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 67);

        auto ts_xxyz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 68);

        auto ts_xxyz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 69);

        auto ts_xxyz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 70);

        auto ts_xxyz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 71);

        auto ts_xxyz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 72);

        auto ts_xxyz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 73);

        auto ts_xxyz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 74);

        auto ts_xxzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 75);

        auto ts_xxzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 76);

        auto ts_xxzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 77);

        auto ts_xxzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 78);

        auto ts_xxzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 79);

        auto ts_xxzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 80);

        auto ts_xxzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 81);

        auto ts_xxzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 82);

        auto ts_xxzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 83);

        auto ts_xxzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 84);

        auto ts_xxzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 85);

        auto ts_xxzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 86);

        auto ts_xxzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 87);

        auto ts_xxzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 88);

        auto ts_xxzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 89);

        auto ts_yy_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 45);

        auto ts_yy_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 46);

        auto ts_yy_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 47);

        auto ts_yy_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 48);

        auto ts_yy_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 49);

        auto ts_yy_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 50);

        auto ts_yy_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 51);

        auto ts_yy_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 52);

        auto ts_yy_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 53);

        auto ts_yy_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 54);

        auto ts_yy_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 55);

        auto ts_yy_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 56);

        auto ts_yy_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 57);

        auto ts_yy_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 58);

        auto ts_yy_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 59);

        auto ts_yz_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 60);

        auto ts_yz_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 61);

        auto ts_yz_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 62);

        auto ts_yz_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 63);

        auto ts_yz_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 64);

        auto ts_yz_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 65);

        auto ts_yz_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 66);

        auto ts_yz_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 67);

        auto ts_yz_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 68);

        auto ts_yz_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 69);

        auto ts_yz_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 70);

        auto ts_yz_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 71);

        auto ts_yz_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 72);

        auto ts_yz_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 73);

        auto ts_yz_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 74);

        auto ts_zz_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 75);

        auto ts_zz_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 76);

        auto ts_zz_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 77);

        auto ts_zz_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 78);

        auto ts_zz_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 79);

        auto ts_zz_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 80);

        auto ts_zz_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 81);

        auto ts_zz_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 82);

        auto ts_zz_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 83);

        auto ts_zz_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 84);

        auto ts_zz_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 85);

        auto ts_zz_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 86);

        auto ts_zz_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 87);

        auto ts_zz_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 88);

        auto ts_zz_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 89);

        // set up pointers to integrals

        auto tt_xxyy_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 45);

        auto tt_xxyy_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 46);

        auto tt_xxyy_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 47);

        auto tt_xxyy_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 48);

        auto tt_xxyy_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 49);

        auto tt_xxyy_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 50);

        auto tt_xxyy_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 51);

        auto tt_xxyy_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 52);

        auto tt_xxyy_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 53);

        auto tt_xxyy_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 54);

        auto tt_xxyy_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 55);

        auto tt_xxyy_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 56);

        auto tt_xxyy_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 57);

        auto tt_xxyy_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 58);

        auto tt_xxyy_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 59);

        auto tt_xxyz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 60);

        auto tt_xxyz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 61);

        auto tt_xxyz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 62);

        auto tt_xxyz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 63);

        auto tt_xxyz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 64);

        auto tt_xxyz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 65);

        auto tt_xxyz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 66);

        auto tt_xxyz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 67);

        auto tt_xxyz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 68);

        auto tt_xxyz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 69);

        auto tt_xxyz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 70);

        auto tt_xxyz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 71);

        auto tt_xxyz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 72);

        auto tt_xxyz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 73);

        auto tt_xxyz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 74);

        auto tt_xxzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 75);

        auto tt_xxzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 76);

        auto tt_xxzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 77);

        auto tt_xxzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 78);

        auto tt_xxzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 79);

        auto tt_xxzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 80);

        auto tt_xxzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 81);

        auto tt_xxzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 82);

        auto tt_xxzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 83);

        auto tt_xxzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 84);

        auto tt_xxzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 85);

        auto tt_xxzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 86);

        auto tt_xxzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 87);

        auto tt_xxzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 88);

        auto tt_xxzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 89);

        // Batch of Integrals (45,90)

        #pragma omp simd aligned(fga, fx, fz, pa_x, ts_xxyy_xxxx_0, ts_xxyy_xxxy_0, ts_xxyy_xxxz_0, \
                                     ts_xxyy_xxyy_0, ts_xxyy_xxyz_0, ts_xxyy_xxzz_0, ts_xxyy_xyyy_0, ts_xxyy_xyyz_0, \
                                     ts_xxyy_xyzz_0, ts_xxyy_xzzz_0, ts_xxyy_yyyy_0, ts_xxyy_yyyz_0, ts_xxyy_yyzz_0, \
                                     ts_xxyy_yzzz_0, ts_xxyy_zzzz_0, ts_xxyz_xxxx_0, ts_xxyz_xxxy_0, ts_xxyz_xxxz_0, \
                                     ts_xxyz_xxyy_0, ts_xxyz_xxyz_0, ts_xxyz_xxzz_0, ts_xxyz_xyyy_0, ts_xxyz_xyyz_0, \
                                     ts_xxyz_xyzz_0, ts_xxyz_xzzz_0, ts_xxyz_yyyy_0, ts_xxyz_yyyz_0, ts_xxyz_yyzz_0, \
                                     ts_xxyz_yzzz_0, ts_xxyz_zzzz_0, ts_xxzz_xxxx_0, ts_xxzz_xxxy_0, ts_xxzz_xxxz_0, \
                                     ts_xxzz_xxyy_0, ts_xxzz_xxyz_0, ts_xxzz_xxzz_0, ts_xxzz_xyyy_0, ts_xxzz_xyyz_0, \
                                     ts_xxzz_xyzz_0, ts_xxzz_xzzz_0, ts_xxzz_yyyy_0, ts_xxzz_yyyz_0, ts_xxzz_yyzz_0, \
                                     ts_xxzz_yzzz_0, ts_xxzz_zzzz_0, ts_yy_xxxx_0, ts_yy_xxxy_0, ts_yy_xxxz_0, \
                                     ts_yy_xxyy_0, ts_yy_xxyz_0, ts_yy_xxzz_0, ts_yy_xyyy_0, ts_yy_xyyz_0, ts_yy_xyzz_0, \
                                     ts_yy_xzzz_0, ts_yy_yyyy_0, ts_yy_yyyz_0, ts_yy_yyzz_0, ts_yy_yzzz_0, ts_yy_zzzz_0, \
                                     ts_yz_xxxx_0, ts_yz_xxxy_0, ts_yz_xxxz_0, ts_yz_xxyy_0, ts_yz_xxyz_0, ts_yz_xxzz_0, \
                                     ts_yz_xyyy_0, ts_yz_xyyz_0, ts_yz_xyzz_0, ts_yz_xzzz_0, ts_yz_yyyy_0, ts_yz_yyyz_0, \
                                     ts_yz_yyzz_0, ts_yz_yzzz_0, ts_yz_zzzz_0, ts_zz_xxxx_0, ts_zz_xxxy_0, ts_zz_xxxz_0, \
                                     ts_zz_xxyy_0, ts_zz_xxyz_0, ts_zz_xxzz_0, ts_zz_xyyy_0, ts_zz_xyyz_0, ts_zz_xyzz_0, \
                                     ts_zz_xzzz_0, ts_zz_yyyy_0, ts_zz_yyyz_0, ts_zz_yyzz_0, ts_zz_yzzz_0, ts_zz_zzzz_0, \
                                     tt_xxyy_xxxx_0, tt_xxyy_xxxy_0, tt_xxyy_xxxz_0, tt_xxyy_xxyy_0, tt_xxyy_xxyz_0, \
                                     tt_xxyy_xxzz_0, tt_xxyy_xyyy_0, tt_xxyy_xyyz_0, tt_xxyy_xyzz_0, tt_xxyy_xzzz_0, \
                                     tt_xxyy_yyyy_0, tt_xxyy_yyyz_0, tt_xxyy_yyzz_0, tt_xxyy_yzzz_0, tt_xxyy_zzzz_0, \
                                     tt_xxyz_xxxx_0, tt_xxyz_xxxy_0, tt_xxyz_xxxz_0, tt_xxyz_xxyy_0, tt_xxyz_xxyz_0, \
                                     tt_xxyz_xxzz_0, tt_xxyz_xyyy_0, tt_xxyz_xyyz_0, tt_xxyz_xyzz_0, tt_xxyz_xzzz_0, \
                                     tt_xxyz_yyyy_0, tt_xxyz_yyyz_0, tt_xxyz_yyzz_0, tt_xxyz_yzzz_0, tt_xxyz_zzzz_0, \
                                     tt_xxzz_xxxx_0, tt_xxzz_xxxy_0, tt_xxzz_xxxz_0, tt_xxzz_xxyy_0, tt_xxzz_xxyz_0, \
                                     tt_xxzz_xxzz_0, tt_xxzz_xyyy_0, tt_xxzz_xyyz_0, tt_xxzz_xyzz_0, tt_xxzz_xzzz_0, \
                                     tt_xxzz_yyyy_0, tt_xxzz_yyyz_0, tt_xxzz_yyzz_0, tt_xxzz_yzzz_0, tt_xxzz_zzzz_0, \
                                     tt_xyy_xxx_0, tt_xyy_xxxx_0, tt_xyy_xxxy_0, tt_xyy_xxxz_0, tt_xyy_xxy_0, \
                                     tt_xyy_xxyy_0, tt_xyy_xxyz_0, tt_xyy_xxz_0, tt_xyy_xxzz_0, tt_xyy_xyy_0, \
                                     tt_xyy_xyyy_0, tt_xyy_xyyz_0, tt_xyy_xyz_0, tt_xyy_xyzz_0, tt_xyy_xzz_0, \
                                     tt_xyy_xzzz_0, tt_xyy_yyy_0, tt_xyy_yyyy_0, tt_xyy_yyyz_0, tt_xyy_yyz_0, \
                                     tt_xyy_yyzz_0, tt_xyy_yzz_0, tt_xyy_yzzz_0, tt_xyy_zzz_0, tt_xyy_zzzz_0, \
                                     tt_xyz_xxx_0, tt_xyz_xxxx_0, tt_xyz_xxxy_0, tt_xyz_xxxz_0, tt_xyz_xxy_0, \
                                     tt_xyz_xxyy_0, tt_xyz_xxyz_0, tt_xyz_xxz_0, tt_xyz_xxzz_0, tt_xyz_xyy_0, \
                                     tt_xyz_xyyy_0, tt_xyz_xyyz_0, tt_xyz_xyz_0, tt_xyz_xyzz_0, tt_xyz_xzz_0, \
                                     tt_xyz_xzzz_0, tt_xyz_yyy_0, tt_xyz_yyyy_0, tt_xyz_yyyz_0, tt_xyz_yyz_0, \
                                     tt_xyz_yyzz_0, tt_xyz_yzz_0, tt_xyz_yzzz_0, tt_xyz_zzz_0, tt_xyz_zzzz_0, \
                                     tt_xzz_xxx_0, tt_xzz_xxxx_0, tt_xzz_xxxy_0, tt_xzz_xxxz_0, tt_xzz_xxy_0, \
                                     tt_xzz_xxyy_0, tt_xzz_xxyz_0, tt_xzz_xxz_0, tt_xzz_xxzz_0, tt_xzz_xyy_0, \
                                     tt_xzz_xyyy_0, tt_xzz_xyyz_0, tt_xzz_xyz_0, tt_xzz_xyzz_0, tt_xzz_xzz_0, \
                                     tt_xzz_xzzz_0, tt_xzz_yyy_0, tt_xzz_yyyy_0, tt_xzz_yyyz_0, tt_xzz_yyz_0, \
                                     tt_xzz_yyzz_0, tt_xzz_yzz_0, tt_xzz_yzzz_0, tt_xzz_zzz_0, tt_xzz_zzzz_0, \
                                     tt_yy_xxxx_0, tt_yy_xxxy_0, tt_yy_xxxz_0, tt_yy_xxyy_0, tt_yy_xxyz_0, tt_yy_xxzz_0, \
                                     tt_yy_xyyy_0, tt_yy_xyyz_0, tt_yy_xyzz_0, tt_yy_xzzz_0, tt_yy_yyyy_0, tt_yy_yyyz_0, \
                                     tt_yy_yyzz_0, tt_yy_yzzz_0, tt_yy_zzzz_0, tt_yz_xxxx_0, tt_yz_xxxy_0, tt_yz_xxxz_0, \
                                     tt_yz_xxyy_0, tt_yz_xxyz_0, tt_yz_xxzz_0, tt_yz_xyyy_0, tt_yz_xyyz_0, tt_yz_xyzz_0, \
                                     tt_yz_xzzz_0, tt_yz_yyyy_0, tt_yz_yyyz_0, tt_yz_yyzz_0, tt_yz_yzzz_0, tt_yz_zzzz_0, \
                                     tt_zz_xxxx_0, tt_zz_xxxy_0, tt_zz_xxxz_0, tt_zz_xxyy_0, tt_zz_xxyz_0, tt_zz_xxzz_0, \
                                     tt_zz_xyyy_0, tt_zz_xyyz_0, tt_zz_xyzz_0, tt_zz_xzzz_0, tt_zz_yyyy_0, tt_zz_yyyz_0, \
                                     tt_zz_yyzz_0, tt_zz_yzzz_0, tt_zz_zzzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fga = fga[j];

            double fl1_fx = fx[j];

            double fl1_fz = fz[j];

            tt_xxyy_xxxx_0[j] = pa_x[j] * tt_xyy_xxxx_0[j] + 0.5 * fl1_fx * tt_yy_xxxx_0[j] + 2.0 * fl1_fx * tt_xyy_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxxx_0[j] - fl1_fz * fl1_fga * ts_yy_xxxx_0[j];

            tt_xxyy_xxxy_0[j] = pa_x[j] * tt_xyy_xxxy_0[j] + 0.5 * fl1_fx * tt_yy_xxxy_0[j] + 1.5 * fl1_fx * tt_xyy_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxxy_0[j] - fl1_fz * fl1_fga * ts_yy_xxxy_0[j];

            tt_xxyy_xxxz_0[j] = pa_x[j] * tt_xyy_xxxz_0[j] + 0.5 * fl1_fx * tt_yy_xxxz_0[j] + 1.5 * fl1_fx * tt_xyy_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxxz_0[j] - fl1_fz * fl1_fga * ts_yy_xxxz_0[j];

            tt_xxyy_xxyy_0[j] = pa_x[j] * tt_xyy_xxyy_0[j] + 0.5 * fl1_fx * tt_yy_xxyy_0[j] + fl1_fx * tt_xyy_xyy_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxyy_0[j] - fl1_fz * fl1_fga * ts_yy_xxyy_0[j];

            tt_xxyy_xxyz_0[j] = pa_x[j] * tt_xyy_xxyz_0[j] + 0.5 * fl1_fx * tt_yy_xxyz_0[j] + fl1_fx * tt_xyy_xyz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxyz_0[j] - fl1_fz * fl1_fga * ts_yy_xxyz_0[j];

            tt_xxyy_xxzz_0[j] = pa_x[j] * tt_xyy_xxzz_0[j] + 0.5 * fl1_fx * tt_yy_xxzz_0[j] + fl1_fx * tt_xyy_xzz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xxzz_0[j] - fl1_fz * fl1_fga * ts_yy_xxzz_0[j];

            tt_xxyy_xyyy_0[j] = pa_x[j] * tt_xyy_xyyy_0[j] + 0.5 * fl1_fx * tt_yy_xyyy_0[j] + 0.5 * fl1_fx * tt_xyy_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xyyy_0[j] - fl1_fz * fl1_fga * ts_yy_xyyy_0[j];

            tt_xxyy_xyyz_0[j] = pa_x[j] * tt_xyy_xyyz_0[j] + 0.5 * fl1_fx * tt_yy_xyyz_0[j] + 0.5 * fl1_fx * tt_xyy_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xyyz_0[j] - fl1_fz * fl1_fga * ts_yy_xyyz_0[j];

            tt_xxyy_xyzz_0[j] = pa_x[j] * tt_xyy_xyzz_0[j] + 0.5 * fl1_fx * tt_yy_xyzz_0[j] + 0.5 * fl1_fx * tt_xyy_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xyzz_0[j] - fl1_fz * fl1_fga * ts_yy_xyzz_0[j];

            tt_xxyy_xzzz_0[j] = pa_x[j] * tt_xyy_xzzz_0[j] + 0.5 * fl1_fx * tt_yy_xzzz_0[j] + 0.5 * fl1_fx * tt_xyy_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxyy_xzzz_0[j] - fl1_fz * fl1_fga * ts_yy_xzzz_0[j];

            tt_xxyy_yyyy_0[j] =
                pa_x[j] * tt_xyy_yyyy_0[j] + 0.5 * fl1_fx * tt_yy_yyyy_0[j] + 2.0 * fl1_fz * ts_xxyy_yyyy_0[j] - fl1_fz * fl1_fga * ts_yy_yyyy_0[j];

            tt_xxyy_yyyz_0[j] =
                pa_x[j] * tt_xyy_yyyz_0[j] + 0.5 * fl1_fx * tt_yy_yyyz_0[j] + 2.0 * fl1_fz * ts_xxyy_yyyz_0[j] - fl1_fz * fl1_fga * ts_yy_yyyz_0[j];

            tt_xxyy_yyzz_0[j] =
                pa_x[j] * tt_xyy_yyzz_0[j] + 0.5 * fl1_fx * tt_yy_yyzz_0[j] + 2.0 * fl1_fz * ts_xxyy_yyzz_0[j] - fl1_fz * fl1_fga * ts_yy_yyzz_0[j];

            tt_xxyy_yzzz_0[j] =
                pa_x[j] * tt_xyy_yzzz_0[j] + 0.5 * fl1_fx * tt_yy_yzzz_0[j] + 2.0 * fl1_fz * ts_xxyy_yzzz_0[j] - fl1_fz * fl1_fga * ts_yy_yzzz_0[j];

            tt_xxyy_zzzz_0[j] =
                pa_x[j] * tt_xyy_zzzz_0[j] + 0.5 * fl1_fx * tt_yy_zzzz_0[j] + 2.0 * fl1_fz * ts_xxyy_zzzz_0[j] - fl1_fz * fl1_fga * ts_yy_zzzz_0[j];

            tt_xxyz_xxxx_0[j] = pa_x[j] * tt_xyz_xxxx_0[j] + 0.5 * fl1_fx * tt_yz_xxxx_0[j] + 2.0 * fl1_fx * tt_xyz_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxxx_0[j] - fl1_fz * fl1_fga * ts_yz_xxxx_0[j];

            tt_xxyz_xxxy_0[j] = pa_x[j] * tt_xyz_xxxy_0[j] + 0.5 * fl1_fx * tt_yz_xxxy_0[j] + 1.5 * fl1_fx * tt_xyz_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxxy_0[j] - fl1_fz * fl1_fga * ts_yz_xxxy_0[j];

            tt_xxyz_xxxz_0[j] = pa_x[j] * tt_xyz_xxxz_0[j] + 0.5 * fl1_fx * tt_yz_xxxz_0[j] + 1.5 * fl1_fx * tt_xyz_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxxz_0[j] - fl1_fz * fl1_fga * ts_yz_xxxz_0[j];

            tt_xxyz_xxyy_0[j] = pa_x[j] * tt_xyz_xxyy_0[j] + 0.5 * fl1_fx * tt_yz_xxyy_0[j] + fl1_fx * tt_xyz_xyy_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxyy_0[j] - fl1_fz * fl1_fga * ts_yz_xxyy_0[j];

            tt_xxyz_xxyz_0[j] = pa_x[j] * tt_xyz_xxyz_0[j] + 0.5 * fl1_fx * tt_yz_xxyz_0[j] + fl1_fx * tt_xyz_xyz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxyz_0[j] - fl1_fz * fl1_fga * ts_yz_xxyz_0[j];

            tt_xxyz_xxzz_0[j] = pa_x[j] * tt_xyz_xxzz_0[j] + 0.5 * fl1_fx * tt_yz_xxzz_0[j] + fl1_fx * tt_xyz_xzz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xxzz_0[j] - fl1_fz * fl1_fga * ts_yz_xxzz_0[j];

            tt_xxyz_xyyy_0[j] = pa_x[j] * tt_xyz_xyyy_0[j] + 0.5 * fl1_fx * tt_yz_xyyy_0[j] + 0.5 * fl1_fx * tt_xyz_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xyyy_0[j] - fl1_fz * fl1_fga * ts_yz_xyyy_0[j];

            tt_xxyz_xyyz_0[j] = pa_x[j] * tt_xyz_xyyz_0[j] + 0.5 * fl1_fx * tt_yz_xyyz_0[j] + 0.5 * fl1_fx * tt_xyz_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xyyz_0[j] - fl1_fz * fl1_fga * ts_yz_xyyz_0[j];

            tt_xxyz_xyzz_0[j] = pa_x[j] * tt_xyz_xyzz_0[j] + 0.5 * fl1_fx * tt_yz_xyzz_0[j] + 0.5 * fl1_fx * tt_xyz_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xyzz_0[j] - fl1_fz * fl1_fga * ts_yz_xyzz_0[j];

            tt_xxyz_xzzz_0[j] = pa_x[j] * tt_xyz_xzzz_0[j] + 0.5 * fl1_fx * tt_yz_xzzz_0[j] + 0.5 * fl1_fx * tt_xyz_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxyz_xzzz_0[j] - fl1_fz * fl1_fga * ts_yz_xzzz_0[j];

            tt_xxyz_yyyy_0[j] =
                pa_x[j] * tt_xyz_yyyy_0[j] + 0.5 * fl1_fx * tt_yz_yyyy_0[j] + 2.0 * fl1_fz * ts_xxyz_yyyy_0[j] - fl1_fz * fl1_fga * ts_yz_yyyy_0[j];

            tt_xxyz_yyyz_0[j] =
                pa_x[j] * tt_xyz_yyyz_0[j] + 0.5 * fl1_fx * tt_yz_yyyz_0[j] + 2.0 * fl1_fz * ts_xxyz_yyyz_0[j] - fl1_fz * fl1_fga * ts_yz_yyyz_0[j];

            tt_xxyz_yyzz_0[j] =
                pa_x[j] * tt_xyz_yyzz_0[j] + 0.5 * fl1_fx * tt_yz_yyzz_0[j] + 2.0 * fl1_fz * ts_xxyz_yyzz_0[j] - fl1_fz * fl1_fga * ts_yz_yyzz_0[j];

            tt_xxyz_yzzz_0[j] =
                pa_x[j] * tt_xyz_yzzz_0[j] + 0.5 * fl1_fx * tt_yz_yzzz_0[j] + 2.0 * fl1_fz * ts_xxyz_yzzz_0[j] - fl1_fz * fl1_fga * ts_yz_yzzz_0[j];

            tt_xxyz_zzzz_0[j] =
                pa_x[j] * tt_xyz_zzzz_0[j] + 0.5 * fl1_fx * tt_yz_zzzz_0[j] + 2.0 * fl1_fz * ts_xxyz_zzzz_0[j] - fl1_fz * fl1_fga * ts_yz_zzzz_0[j];

            tt_xxzz_xxxx_0[j] = pa_x[j] * tt_xzz_xxxx_0[j] + 0.5 * fl1_fx * tt_zz_xxxx_0[j] + 2.0 * fl1_fx * tt_xzz_xxx_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxxx_0[j] - fl1_fz * fl1_fga * ts_zz_xxxx_0[j];

            tt_xxzz_xxxy_0[j] = pa_x[j] * tt_xzz_xxxy_0[j] + 0.5 * fl1_fx * tt_zz_xxxy_0[j] + 1.5 * fl1_fx * tt_xzz_xxy_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxxy_0[j] - fl1_fz * fl1_fga * ts_zz_xxxy_0[j];

            tt_xxzz_xxxz_0[j] = pa_x[j] * tt_xzz_xxxz_0[j] + 0.5 * fl1_fx * tt_zz_xxxz_0[j] + 1.5 * fl1_fx * tt_xzz_xxz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxxz_0[j] - fl1_fz * fl1_fga * ts_zz_xxxz_0[j];

            tt_xxzz_xxyy_0[j] = pa_x[j] * tt_xzz_xxyy_0[j] + 0.5 * fl1_fx * tt_zz_xxyy_0[j] + fl1_fx * tt_xzz_xyy_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxyy_0[j] - fl1_fz * fl1_fga * ts_zz_xxyy_0[j];

            tt_xxzz_xxyz_0[j] = pa_x[j] * tt_xzz_xxyz_0[j] + 0.5 * fl1_fx * tt_zz_xxyz_0[j] + fl1_fx * tt_xzz_xyz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxyz_0[j] - fl1_fz * fl1_fga * ts_zz_xxyz_0[j];

            tt_xxzz_xxzz_0[j] = pa_x[j] * tt_xzz_xxzz_0[j] + 0.5 * fl1_fx * tt_zz_xxzz_0[j] + fl1_fx * tt_xzz_xzz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xxzz_0[j] - fl1_fz * fl1_fga * ts_zz_xxzz_0[j];

            tt_xxzz_xyyy_0[j] = pa_x[j] * tt_xzz_xyyy_0[j] + 0.5 * fl1_fx * tt_zz_xyyy_0[j] + 0.5 * fl1_fx * tt_xzz_yyy_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xyyy_0[j] - fl1_fz * fl1_fga * ts_zz_xyyy_0[j];

            tt_xxzz_xyyz_0[j] = pa_x[j] * tt_xzz_xyyz_0[j] + 0.5 * fl1_fx * tt_zz_xyyz_0[j] + 0.5 * fl1_fx * tt_xzz_yyz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xyyz_0[j] - fl1_fz * fl1_fga * ts_zz_xyyz_0[j];

            tt_xxzz_xyzz_0[j] = pa_x[j] * tt_xzz_xyzz_0[j] + 0.5 * fl1_fx * tt_zz_xyzz_0[j] + 0.5 * fl1_fx * tt_xzz_yzz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xyzz_0[j] - fl1_fz * fl1_fga * ts_zz_xyzz_0[j];

            tt_xxzz_xzzz_0[j] = pa_x[j] * tt_xzz_xzzz_0[j] + 0.5 * fl1_fx * tt_zz_xzzz_0[j] + 0.5 * fl1_fx * tt_xzz_zzz_0[j] +
                                2.0 * fl1_fz * ts_xxzz_xzzz_0[j] - fl1_fz * fl1_fga * ts_zz_xzzz_0[j];

            tt_xxzz_yyyy_0[j] =
                pa_x[j] * tt_xzz_yyyy_0[j] + 0.5 * fl1_fx * tt_zz_yyyy_0[j] + 2.0 * fl1_fz * ts_xxzz_yyyy_0[j] - fl1_fz * fl1_fga * ts_zz_yyyy_0[j];

            tt_xxzz_yyyz_0[j] =
                pa_x[j] * tt_xzz_yyyz_0[j] + 0.5 * fl1_fx * tt_zz_yyyz_0[j] + 2.0 * fl1_fz * ts_xxzz_yyyz_0[j] - fl1_fz * fl1_fga * ts_zz_yyyz_0[j];

            tt_xxzz_yyzz_0[j] =
                pa_x[j] * tt_xzz_yyzz_0[j] + 0.5 * fl1_fx * tt_zz_yyzz_0[j] + 2.0 * fl1_fz * ts_xxzz_yyzz_0[j] - fl1_fz * fl1_fga * ts_zz_yyzz_0[j];

            tt_xxzz_yzzz_0[j] =
                pa_x[j] * tt_xzz_yzzz_0[j] + 0.5 * fl1_fx * tt_zz_yzzz_0[j] + 2.0 * fl1_fz * ts_xxzz_yzzz_0[j] - fl1_fz * fl1_fga * ts_zz_yzzz_0[j];

            tt_xxzz_zzzz_0[j] =
                pa_x[j] * tt_xzz_zzzz_0[j] + 0.5 * fl1_fx * tt_zz_zzzz_0[j] + 2.0 * fl1_fz * ts_xxzz_zzzz_0[j] - fl1_fz * fl1_fga * ts_zz_zzzz_0[j];
        }

        idx++;
    }
}

void
compKineticEnergyForGG_90_135(CMemBlock2D<double>&       primBuffer,
                              const CRecursionMap&       recursionMap,
                              const CMemBlock2D<double>& osFactors,
                              const CMemBlock2D<double>& paDistances,
                              const CGtoBlock&           braGtoBlock,
                              const CGtoBlock&           ketGtoBlock,
                              const int32_t              iContrGto)
{
    // Batch of Integrals (90,135)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_t_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_t_4_4_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_t_3_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(4 * idx);

        auto fz = osFactors.data(4 * idx + 1);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        // set up pointers to auxilary integrals

        auto tt_yyy_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 90);

        auto tt_yyy_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 91);

        auto tt_yyy_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 92);

        auto tt_yyy_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 93);

        auto tt_yyy_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 94);

        auto tt_yyy_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 95);

        auto tt_yyy_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 96);

        auto tt_yyy_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 97);

        auto tt_yyy_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 98);

        auto tt_yyy_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 99);

        auto tt_yyy_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 100);

        auto tt_yyy_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 101);

        auto tt_yyy_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 102);

        auto tt_yyy_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 103);

        auto tt_yyy_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 104);

        auto tt_yyz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 105);

        auto tt_yyz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 106);

        auto tt_yyz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 107);

        auto tt_yyz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 108);

        auto tt_yyz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 109);

        auto tt_yyz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 110);

        auto tt_yyz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 111);

        auto tt_yyz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 112);

        auto tt_yyz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 113);

        auto tt_yyz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 114);

        auto tt_yyz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 115);

        auto tt_yyz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 116);

        auto tt_yyz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 117);

        auto tt_yyz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 118);

        auto tt_yyz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 119);

        auto tt_yzz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 120);

        auto tt_yzz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 121);

        auto tt_yzz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 122);

        auto tt_yzz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 123);

        auto tt_yzz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 124);

        auto tt_yzz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 125);

        auto tt_yzz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 126);

        auto tt_yzz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 127);

        auto tt_yzz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 128);

        auto tt_yzz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 129);

        auto tt_yzz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 130);

        auto tt_yzz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 131);

        auto tt_yzz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 132);

        auto tt_yzz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 133);

        auto tt_yzz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 134);

        auto tt_yyy_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 60);

        auto tt_yyy_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 61);

        auto tt_yyy_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 62);

        auto tt_yyy_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 63);

        auto tt_yyy_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 64);

        auto tt_yyy_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 65);

        auto tt_yyy_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 66);

        auto tt_yyy_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 67);

        auto tt_yyy_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 68);

        auto tt_yyy_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 69);

        auto tt_yyz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 70);

        auto tt_yyz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 71);

        auto tt_yyz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 72);

        auto tt_yyz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 73);

        auto tt_yyz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 74);

        auto tt_yyz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 75);

        auto tt_yyz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 76);

        auto tt_yyz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 77);

        auto tt_yyz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 78);

        auto tt_yyz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 79);

        auto tt_yzz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 80);

        auto tt_yzz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 81);

        auto tt_yzz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 82);

        auto tt_yzz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 83);

        auto tt_yzz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 84);

        auto tt_yzz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 85);

        auto tt_yzz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 86);

        auto tt_yzz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 87);

        auto tt_yzz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 88);

        auto tt_yzz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 89);

        auto ts_xyyy_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 90);

        auto ts_xyyy_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 91);

        auto ts_xyyy_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 92);

        auto ts_xyyy_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 93);

        auto ts_xyyy_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 94);

        auto ts_xyyy_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 95);

        auto ts_xyyy_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 96);

        auto ts_xyyy_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 97);

        auto ts_xyyy_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 98);

        auto ts_xyyy_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 99);

        auto ts_xyyy_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 100);

        auto ts_xyyy_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 101);

        auto ts_xyyy_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 102);

        auto ts_xyyy_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 103);

        auto ts_xyyy_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 104);

        auto ts_xyyz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 105);

        auto ts_xyyz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 106);

        auto ts_xyyz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 107);

        auto ts_xyyz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 108);

        auto ts_xyyz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 109);

        auto ts_xyyz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 110);

        auto ts_xyyz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 111);

        auto ts_xyyz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 112);

        auto ts_xyyz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 113);

        auto ts_xyyz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 114);

        auto ts_xyyz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 115);

        auto ts_xyyz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 116);

        auto ts_xyyz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 117);

        auto ts_xyyz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 118);

        auto ts_xyyz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 119);

        auto ts_xyzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 120);

        auto ts_xyzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 121);

        auto ts_xyzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 122);

        auto ts_xyzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 123);

        auto ts_xyzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 124);

        auto ts_xyzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 125);

        auto ts_xyzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 126);

        auto ts_xyzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 127);

        auto ts_xyzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 128);

        auto ts_xyzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 129);

        auto ts_xyzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 130);

        auto ts_xyzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 131);

        auto ts_xyzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 132);

        auto ts_xyzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 133);

        auto ts_xyzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 134);

        // set up pointers to integrals

        auto tt_xyyy_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 90);

        auto tt_xyyy_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 91);

        auto tt_xyyy_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 92);

        auto tt_xyyy_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 93);

        auto tt_xyyy_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 94);

        auto tt_xyyy_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 95);

        auto tt_xyyy_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 96);

        auto tt_xyyy_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 97);

        auto tt_xyyy_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 98);

        auto tt_xyyy_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 99);

        auto tt_xyyy_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 100);

        auto tt_xyyy_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 101);

        auto tt_xyyy_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 102);

        auto tt_xyyy_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 103);

        auto tt_xyyy_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 104);

        auto tt_xyyz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 105);

        auto tt_xyyz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 106);

        auto tt_xyyz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 107);

        auto tt_xyyz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 108);

        auto tt_xyyz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 109);

        auto tt_xyyz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 110);

        auto tt_xyyz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 111);

        auto tt_xyyz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 112);

        auto tt_xyyz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 113);

        auto tt_xyyz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 114);

        auto tt_xyyz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 115);

        auto tt_xyyz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 116);

        auto tt_xyyz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 117);

        auto tt_xyyz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 118);

        auto tt_xyyz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 119);

        auto tt_xyzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 120);

        auto tt_xyzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 121);

        auto tt_xyzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 122);

        auto tt_xyzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 123);

        auto tt_xyzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 124);

        auto tt_xyzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 125);

        auto tt_xyzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 126);

        auto tt_xyzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 127);

        auto tt_xyzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 128);

        auto tt_xyzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 129);

        auto tt_xyzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 130);

        auto tt_xyzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 131);

        auto tt_xyzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 132);

        auto tt_xyzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 133);

        auto tt_xyzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 134);

        // Batch of Integrals (90,135)

        #pragma omp simd aligned(fx, fz, pa_x, ts_xyyy_xxxx_0, ts_xyyy_xxxy_0, ts_xyyy_xxxz_0, \
                                     ts_xyyy_xxyy_0, ts_xyyy_xxyz_0, ts_xyyy_xxzz_0, ts_xyyy_xyyy_0, ts_xyyy_xyyz_0, \
                                     ts_xyyy_xyzz_0, ts_xyyy_xzzz_0, ts_xyyy_yyyy_0, ts_xyyy_yyyz_0, ts_xyyy_yyzz_0, \
                                     ts_xyyy_yzzz_0, ts_xyyy_zzzz_0, ts_xyyz_xxxx_0, ts_xyyz_xxxy_0, ts_xyyz_xxxz_0, \
                                     ts_xyyz_xxyy_0, ts_xyyz_xxyz_0, ts_xyyz_xxzz_0, ts_xyyz_xyyy_0, ts_xyyz_xyyz_0, \
                                     ts_xyyz_xyzz_0, ts_xyyz_xzzz_0, ts_xyyz_yyyy_0, ts_xyyz_yyyz_0, ts_xyyz_yyzz_0, \
                                     ts_xyyz_yzzz_0, ts_xyyz_zzzz_0, ts_xyzz_xxxx_0, ts_xyzz_xxxy_0, ts_xyzz_xxxz_0, \
                                     ts_xyzz_xxyy_0, ts_xyzz_xxyz_0, ts_xyzz_xxzz_0, ts_xyzz_xyyy_0, ts_xyzz_xyyz_0, \
                                     ts_xyzz_xyzz_0, ts_xyzz_xzzz_0, ts_xyzz_yyyy_0, ts_xyzz_yyyz_0, ts_xyzz_yyzz_0, \
                                     ts_xyzz_yzzz_0, ts_xyzz_zzzz_0, tt_xyyy_xxxx_0, tt_xyyy_xxxy_0, tt_xyyy_xxxz_0, \
                                     tt_xyyy_xxyy_0, tt_xyyy_xxyz_0, tt_xyyy_xxzz_0, tt_xyyy_xyyy_0, tt_xyyy_xyyz_0, \
                                     tt_xyyy_xyzz_0, tt_xyyy_xzzz_0, tt_xyyy_yyyy_0, tt_xyyy_yyyz_0, tt_xyyy_yyzz_0, \
                                     tt_xyyy_yzzz_0, tt_xyyy_zzzz_0, tt_xyyz_xxxx_0, tt_xyyz_xxxy_0, tt_xyyz_xxxz_0, \
                                     tt_xyyz_xxyy_0, tt_xyyz_xxyz_0, tt_xyyz_xxzz_0, tt_xyyz_xyyy_0, tt_xyyz_xyyz_0, \
                                     tt_xyyz_xyzz_0, tt_xyyz_xzzz_0, tt_xyyz_yyyy_0, tt_xyyz_yyyz_0, tt_xyyz_yyzz_0, \
                                     tt_xyyz_yzzz_0, tt_xyyz_zzzz_0, tt_xyzz_xxxx_0, tt_xyzz_xxxy_0, tt_xyzz_xxxz_0, \
                                     tt_xyzz_xxyy_0, tt_xyzz_xxyz_0, tt_xyzz_xxzz_0, tt_xyzz_xyyy_0, tt_xyzz_xyyz_0, \
                                     tt_xyzz_xyzz_0, tt_xyzz_xzzz_0, tt_xyzz_yyyy_0, tt_xyzz_yyyz_0, tt_xyzz_yyzz_0, \
                                     tt_xyzz_yzzz_0, tt_xyzz_zzzz_0, tt_yyy_xxx_0, tt_yyy_xxxx_0, tt_yyy_xxxy_0, \
                                     tt_yyy_xxxz_0, tt_yyy_xxy_0, tt_yyy_xxyy_0, tt_yyy_xxyz_0, tt_yyy_xxz_0, \
                                     tt_yyy_xxzz_0, tt_yyy_xyy_0, tt_yyy_xyyy_0, tt_yyy_xyyz_0, tt_yyy_xyz_0, \
                                     tt_yyy_xyzz_0, tt_yyy_xzz_0, tt_yyy_xzzz_0, tt_yyy_yyy_0, tt_yyy_yyyy_0, \
                                     tt_yyy_yyyz_0, tt_yyy_yyz_0, tt_yyy_yyzz_0, tt_yyy_yzz_0, tt_yyy_yzzz_0, \
                                     tt_yyy_zzz_0, tt_yyy_zzzz_0, tt_yyz_xxx_0, tt_yyz_xxxx_0, tt_yyz_xxxy_0, \
                                     tt_yyz_xxxz_0, tt_yyz_xxy_0, tt_yyz_xxyy_0, tt_yyz_xxyz_0, tt_yyz_xxz_0, \
                                     tt_yyz_xxzz_0, tt_yyz_xyy_0, tt_yyz_xyyy_0, tt_yyz_xyyz_0, tt_yyz_xyz_0, \
                                     tt_yyz_xyzz_0, tt_yyz_xzz_0, tt_yyz_xzzz_0, tt_yyz_yyy_0, tt_yyz_yyyy_0, \
                                     tt_yyz_yyyz_0, tt_yyz_yyz_0, tt_yyz_yyzz_0, tt_yyz_yzz_0, tt_yyz_yzzz_0, \
                                     tt_yyz_zzz_0, tt_yyz_zzzz_0, tt_yzz_xxx_0, tt_yzz_xxxx_0, tt_yzz_xxxy_0, \
                                     tt_yzz_xxxz_0, tt_yzz_xxy_0, tt_yzz_xxyy_0, tt_yzz_xxyz_0, tt_yzz_xxz_0, \
                                     tt_yzz_xxzz_0, tt_yzz_xyy_0, tt_yzz_xyyy_0, tt_yzz_xyyz_0, tt_yzz_xyz_0, \
                                     tt_yzz_xyzz_0, tt_yzz_xzz_0, tt_yzz_xzzz_0, tt_yzz_yyy_0, tt_yzz_yyyy_0, \
                                     tt_yzz_yyyz_0, tt_yzz_yyz_0, tt_yzz_yyzz_0, tt_yzz_yzz_0, tt_yzz_yzzz_0, \
                                     tt_yzz_zzz_0, tt_yzz_zzzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fx = fx[j];

            double fl1_fz = fz[j];

            tt_xyyy_xxxx_0[j] = pa_x[j] * tt_yyy_xxxx_0[j] + 2.0 * fl1_fx * tt_yyy_xxx_0[j] + 2.0 * fl1_fz * ts_xyyy_xxxx_0[j];

            tt_xyyy_xxxy_0[j] = pa_x[j] * tt_yyy_xxxy_0[j] + 1.5 * fl1_fx * tt_yyy_xxy_0[j] + 2.0 * fl1_fz * ts_xyyy_xxxy_0[j];

            tt_xyyy_xxxz_0[j] = pa_x[j] * tt_yyy_xxxz_0[j] + 1.5 * fl1_fx * tt_yyy_xxz_0[j] + 2.0 * fl1_fz * ts_xyyy_xxxz_0[j];

            tt_xyyy_xxyy_0[j] = pa_x[j] * tt_yyy_xxyy_0[j] + fl1_fx * tt_yyy_xyy_0[j] + 2.0 * fl1_fz * ts_xyyy_xxyy_0[j];

            tt_xyyy_xxyz_0[j] = pa_x[j] * tt_yyy_xxyz_0[j] + fl1_fx * tt_yyy_xyz_0[j] + 2.0 * fl1_fz * ts_xyyy_xxyz_0[j];

            tt_xyyy_xxzz_0[j] = pa_x[j] * tt_yyy_xxzz_0[j] + fl1_fx * tt_yyy_xzz_0[j] + 2.0 * fl1_fz * ts_xyyy_xxzz_0[j];

            tt_xyyy_xyyy_0[j] = pa_x[j] * tt_yyy_xyyy_0[j] + 0.5 * fl1_fx * tt_yyy_yyy_0[j] + 2.0 * fl1_fz * ts_xyyy_xyyy_0[j];

            tt_xyyy_xyyz_0[j] = pa_x[j] * tt_yyy_xyyz_0[j] + 0.5 * fl1_fx * tt_yyy_yyz_0[j] + 2.0 * fl1_fz * ts_xyyy_xyyz_0[j];

            tt_xyyy_xyzz_0[j] = pa_x[j] * tt_yyy_xyzz_0[j] + 0.5 * fl1_fx * tt_yyy_yzz_0[j] + 2.0 * fl1_fz * ts_xyyy_xyzz_0[j];

            tt_xyyy_xzzz_0[j] = pa_x[j] * tt_yyy_xzzz_0[j] + 0.5 * fl1_fx * tt_yyy_zzz_0[j] + 2.0 * fl1_fz * ts_xyyy_xzzz_0[j];

            tt_xyyy_yyyy_0[j] = pa_x[j] * tt_yyy_yyyy_0[j] + 2.0 * fl1_fz * ts_xyyy_yyyy_0[j];

            tt_xyyy_yyyz_0[j] = pa_x[j] * tt_yyy_yyyz_0[j] + 2.0 * fl1_fz * ts_xyyy_yyyz_0[j];

            tt_xyyy_yyzz_0[j] = pa_x[j] * tt_yyy_yyzz_0[j] + 2.0 * fl1_fz * ts_xyyy_yyzz_0[j];

            tt_xyyy_yzzz_0[j] = pa_x[j] * tt_yyy_yzzz_0[j] + 2.0 * fl1_fz * ts_xyyy_yzzz_0[j];

            tt_xyyy_zzzz_0[j] = pa_x[j] * tt_yyy_zzzz_0[j] + 2.0 * fl1_fz * ts_xyyy_zzzz_0[j];

            tt_xyyz_xxxx_0[j] = pa_x[j] * tt_yyz_xxxx_0[j] + 2.0 * fl1_fx * tt_yyz_xxx_0[j] + 2.0 * fl1_fz * ts_xyyz_xxxx_0[j];

            tt_xyyz_xxxy_0[j] = pa_x[j] * tt_yyz_xxxy_0[j] + 1.5 * fl1_fx * tt_yyz_xxy_0[j] + 2.0 * fl1_fz * ts_xyyz_xxxy_0[j];

            tt_xyyz_xxxz_0[j] = pa_x[j] * tt_yyz_xxxz_0[j] + 1.5 * fl1_fx * tt_yyz_xxz_0[j] + 2.0 * fl1_fz * ts_xyyz_xxxz_0[j];

            tt_xyyz_xxyy_0[j] = pa_x[j] * tt_yyz_xxyy_0[j] + fl1_fx * tt_yyz_xyy_0[j] + 2.0 * fl1_fz * ts_xyyz_xxyy_0[j];

            tt_xyyz_xxyz_0[j] = pa_x[j] * tt_yyz_xxyz_0[j] + fl1_fx * tt_yyz_xyz_0[j] + 2.0 * fl1_fz * ts_xyyz_xxyz_0[j];

            tt_xyyz_xxzz_0[j] = pa_x[j] * tt_yyz_xxzz_0[j] + fl1_fx * tt_yyz_xzz_0[j] + 2.0 * fl1_fz * ts_xyyz_xxzz_0[j];

            tt_xyyz_xyyy_0[j] = pa_x[j] * tt_yyz_xyyy_0[j] + 0.5 * fl1_fx * tt_yyz_yyy_0[j] + 2.0 * fl1_fz * ts_xyyz_xyyy_0[j];

            tt_xyyz_xyyz_0[j] = pa_x[j] * tt_yyz_xyyz_0[j] + 0.5 * fl1_fx * tt_yyz_yyz_0[j] + 2.0 * fl1_fz * ts_xyyz_xyyz_0[j];

            tt_xyyz_xyzz_0[j] = pa_x[j] * tt_yyz_xyzz_0[j] + 0.5 * fl1_fx * tt_yyz_yzz_0[j] + 2.0 * fl1_fz * ts_xyyz_xyzz_0[j];

            tt_xyyz_xzzz_0[j] = pa_x[j] * tt_yyz_xzzz_0[j] + 0.5 * fl1_fx * tt_yyz_zzz_0[j] + 2.0 * fl1_fz * ts_xyyz_xzzz_0[j];

            tt_xyyz_yyyy_0[j] = pa_x[j] * tt_yyz_yyyy_0[j] + 2.0 * fl1_fz * ts_xyyz_yyyy_0[j];

            tt_xyyz_yyyz_0[j] = pa_x[j] * tt_yyz_yyyz_0[j] + 2.0 * fl1_fz * ts_xyyz_yyyz_0[j];

            tt_xyyz_yyzz_0[j] = pa_x[j] * tt_yyz_yyzz_0[j] + 2.0 * fl1_fz * ts_xyyz_yyzz_0[j];

            tt_xyyz_yzzz_0[j] = pa_x[j] * tt_yyz_yzzz_0[j] + 2.0 * fl1_fz * ts_xyyz_yzzz_0[j];

            tt_xyyz_zzzz_0[j] = pa_x[j] * tt_yyz_zzzz_0[j] + 2.0 * fl1_fz * ts_xyyz_zzzz_0[j];

            tt_xyzz_xxxx_0[j] = pa_x[j] * tt_yzz_xxxx_0[j] + 2.0 * fl1_fx * tt_yzz_xxx_0[j] + 2.0 * fl1_fz * ts_xyzz_xxxx_0[j];

            tt_xyzz_xxxy_0[j] = pa_x[j] * tt_yzz_xxxy_0[j] + 1.5 * fl1_fx * tt_yzz_xxy_0[j] + 2.0 * fl1_fz * ts_xyzz_xxxy_0[j];

            tt_xyzz_xxxz_0[j] = pa_x[j] * tt_yzz_xxxz_0[j] + 1.5 * fl1_fx * tt_yzz_xxz_0[j] + 2.0 * fl1_fz * ts_xyzz_xxxz_0[j];

            tt_xyzz_xxyy_0[j] = pa_x[j] * tt_yzz_xxyy_0[j] + fl1_fx * tt_yzz_xyy_0[j] + 2.0 * fl1_fz * ts_xyzz_xxyy_0[j];

            tt_xyzz_xxyz_0[j] = pa_x[j] * tt_yzz_xxyz_0[j] + fl1_fx * tt_yzz_xyz_0[j] + 2.0 * fl1_fz * ts_xyzz_xxyz_0[j];

            tt_xyzz_xxzz_0[j] = pa_x[j] * tt_yzz_xxzz_0[j] + fl1_fx * tt_yzz_xzz_0[j] + 2.0 * fl1_fz * ts_xyzz_xxzz_0[j];

            tt_xyzz_xyyy_0[j] = pa_x[j] * tt_yzz_xyyy_0[j] + 0.5 * fl1_fx * tt_yzz_yyy_0[j] + 2.0 * fl1_fz * ts_xyzz_xyyy_0[j];

            tt_xyzz_xyyz_0[j] = pa_x[j] * tt_yzz_xyyz_0[j] + 0.5 * fl1_fx * tt_yzz_yyz_0[j] + 2.0 * fl1_fz * ts_xyzz_xyyz_0[j];

            tt_xyzz_xyzz_0[j] = pa_x[j] * tt_yzz_xyzz_0[j] + 0.5 * fl1_fx * tt_yzz_yzz_0[j] + 2.0 * fl1_fz * ts_xyzz_xyzz_0[j];

            tt_xyzz_xzzz_0[j] = pa_x[j] * tt_yzz_xzzz_0[j] + 0.5 * fl1_fx * tt_yzz_zzz_0[j] + 2.0 * fl1_fz * ts_xyzz_xzzz_0[j];

            tt_xyzz_yyyy_0[j] = pa_x[j] * tt_yzz_yyyy_0[j] + 2.0 * fl1_fz * ts_xyzz_yyyy_0[j];

            tt_xyzz_yyyz_0[j] = pa_x[j] * tt_yzz_yyyz_0[j] + 2.0 * fl1_fz * ts_xyzz_yyyz_0[j];

            tt_xyzz_yyzz_0[j] = pa_x[j] * tt_yzz_yyzz_0[j] + 2.0 * fl1_fz * ts_xyzz_yyzz_0[j];

            tt_xyzz_yzzz_0[j] = pa_x[j] * tt_yzz_yzzz_0[j] + 2.0 * fl1_fz * ts_xyzz_yzzz_0[j];

            tt_xyzz_zzzz_0[j] = pa_x[j] * tt_yzz_zzzz_0[j] + 2.0 * fl1_fz * ts_xyzz_zzzz_0[j];
        }

        idx++;
    }
}

void
compKineticEnergyForGG_135_180(CMemBlock2D<double>&       primBuffer,
                               const CRecursionMap&       recursionMap,
                               const CMemBlock2D<double>& osFactors,
                               const CMemBlock2D<double>& paDistances,
                               const CGtoBlock&           braGtoBlock,
                               const CGtoBlock&           ketGtoBlock,
                               const int32_t              iContrGto)
{
    // Batch of Integrals (135,180)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_t_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_t_4_4_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_t_3_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(4 * idx);

        auto fz = osFactors.data(4 * idx + 1);

        auto fga = osFactors.data(4 * idx + 2);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        auto pa_y = paDistances.data(3 * idx + 1);

        // set up pointers to auxilary integrals

        auto tt_yyy_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 90);

        auto tt_yyy_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 91);

        auto tt_yyy_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 92);

        auto tt_yyy_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 93);

        auto tt_yyy_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 94);

        auto tt_yyy_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 95);

        auto tt_yyy_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 96);

        auto tt_yyy_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 97);

        auto tt_yyy_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 98);

        auto tt_yyy_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 99);

        auto tt_yyy_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 100);

        auto tt_yyy_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 101);

        auto tt_yyy_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 102);

        auto tt_yyy_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 103);

        auto tt_yyy_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 104);

        auto tt_yyz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 105);

        auto tt_yyz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 106);

        auto tt_yyz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 107);

        auto tt_yyz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 108);

        auto tt_yyz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 109);

        auto tt_yyz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 110);

        auto tt_yyz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 111);

        auto tt_yyz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 112);

        auto tt_yyz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 113);

        auto tt_yyz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 114);

        auto tt_yyz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 115);

        auto tt_yyz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 116);

        auto tt_yyz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 117);

        auto tt_yyz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 118);

        auto tt_yyz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 119);

        auto tt_zzz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 135);

        auto tt_zzz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 136);

        auto tt_zzz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 137);

        auto tt_zzz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 138);

        auto tt_zzz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 139);

        auto tt_zzz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 140);

        auto tt_zzz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 141);

        auto tt_zzz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 142);

        auto tt_zzz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 143);

        auto tt_zzz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 144);

        auto tt_zzz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 145);

        auto tt_zzz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 146);

        auto tt_zzz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 147);

        auto tt_zzz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 148);

        auto tt_zzz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 149);

        auto tt_yy_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 45);

        auto tt_yy_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 46);

        auto tt_yy_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 47);

        auto tt_yy_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 48);

        auto tt_yy_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 49);

        auto tt_yy_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 50);

        auto tt_yy_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 51);

        auto tt_yy_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 52);

        auto tt_yy_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 53);

        auto tt_yy_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 54);

        auto tt_yy_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 55);

        auto tt_yy_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 56);

        auto tt_yy_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 57);

        auto tt_yy_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 58);

        auto tt_yy_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 59);

        auto tt_yz_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 60);

        auto tt_yz_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 61);

        auto tt_yz_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 62);

        auto tt_yz_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 63);

        auto tt_yz_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 64);

        auto tt_yz_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 65);

        auto tt_yz_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 66);

        auto tt_yz_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 67);

        auto tt_yz_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 68);

        auto tt_yz_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 69);

        auto tt_yz_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 70);

        auto tt_yz_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 71);

        auto tt_yz_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 72);

        auto tt_yz_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 73);

        auto tt_yz_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 74);

        auto tt_yyy_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 60);

        auto tt_yyy_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 61);

        auto tt_yyy_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 62);

        auto tt_yyy_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 63);

        auto tt_yyy_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 64);

        auto tt_yyy_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 65);

        auto tt_yyy_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 66);

        auto tt_yyy_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 67);

        auto tt_yyy_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 68);

        auto tt_yyy_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 69);

        auto tt_yyz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 70);

        auto tt_yyz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 71);

        auto tt_yyz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 72);

        auto tt_yyz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 73);

        auto tt_yyz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 74);

        auto tt_yyz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 75);

        auto tt_yyz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 76);

        auto tt_yyz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 77);

        auto tt_yyz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 78);

        auto tt_yyz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 79);

        auto tt_zzz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 90);

        auto tt_zzz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 91);

        auto tt_zzz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 92);

        auto tt_zzz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 93);

        auto tt_zzz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 94);

        auto tt_zzz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 95);

        auto tt_zzz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 96);

        auto tt_zzz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 97);

        auto tt_zzz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 98);

        auto tt_zzz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 99);

        auto ts_xzzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 135);

        auto ts_xzzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 136);

        auto ts_xzzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 137);

        auto ts_xzzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 138);

        auto ts_xzzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 139);

        auto ts_xzzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 140);

        auto ts_xzzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 141);

        auto ts_xzzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 142);

        auto ts_xzzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 143);

        auto ts_xzzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 144);

        auto ts_xzzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 145);

        auto ts_xzzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 146);

        auto ts_xzzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 147);

        auto ts_xzzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 148);

        auto ts_xzzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 149);

        auto ts_yyyy_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 150);

        auto ts_yyyy_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 151);

        auto ts_yyyy_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 152);

        auto ts_yyyy_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 153);

        auto ts_yyyy_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 154);

        auto ts_yyyy_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 155);

        auto ts_yyyy_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 156);

        auto ts_yyyy_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 157);

        auto ts_yyyy_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 158);

        auto ts_yyyy_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 159);

        auto ts_yyyy_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 160);

        auto ts_yyyy_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 161);

        auto ts_yyyy_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 162);

        auto ts_yyyy_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 163);

        auto ts_yyyy_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 164);

        auto ts_yyyz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 165);

        auto ts_yyyz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 166);

        auto ts_yyyz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 167);

        auto ts_yyyz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 168);

        auto ts_yyyz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 169);

        auto ts_yyyz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 170);

        auto ts_yyyz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 171);

        auto ts_yyyz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 172);

        auto ts_yyyz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 173);

        auto ts_yyyz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 174);

        auto ts_yyyz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 175);

        auto ts_yyyz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 176);

        auto ts_yyyz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 177);

        auto ts_yyyz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 178);

        auto ts_yyyz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 179);

        auto ts_yy_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 45);

        auto ts_yy_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 46);

        auto ts_yy_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 47);

        auto ts_yy_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 48);

        auto ts_yy_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 49);

        auto ts_yy_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 50);

        auto ts_yy_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 51);

        auto ts_yy_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 52);

        auto ts_yy_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 53);

        auto ts_yy_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 54);

        auto ts_yy_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 55);

        auto ts_yy_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 56);

        auto ts_yy_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 57);

        auto ts_yy_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 58);

        auto ts_yy_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 59);

        auto ts_yz_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 60);

        auto ts_yz_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 61);

        auto ts_yz_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 62);

        auto ts_yz_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 63);

        auto ts_yz_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 64);

        auto ts_yz_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 65);

        auto ts_yz_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 66);

        auto ts_yz_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 67);

        auto ts_yz_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 68);

        auto ts_yz_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 69);

        auto ts_yz_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 70);

        auto ts_yz_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 71);

        auto ts_yz_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 72);

        auto ts_yz_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 73);

        auto ts_yz_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 74);

        // set up pointers to integrals

        auto tt_xzzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 135);

        auto tt_xzzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 136);

        auto tt_xzzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 137);

        auto tt_xzzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 138);

        auto tt_xzzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 139);

        auto tt_xzzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 140);

        auto tt_xzzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 141);

        auto tt_xzzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 142);

        auto tt_xzzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 143);

        auto tt_xzzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 144);

        auto tt_xzzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 145);

        auto tt_xzzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 146);

        auto tt_xzzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 147);

        auto tt_xzzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 148);

        auto tt_xzzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 149);

        auto tt_yyyy_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 150);

        auto tt_yyyy_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 151);

        auto tt_yyyy_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 152);

        auto tt_yyyy_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 153);

        auto tt_yyyy_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 154);

        auto tt_yyyy_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 155);

        auto tt_yyyy_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 156);

        auto tt_yyyy_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 157);

        auto tt_yyyy_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 158);

        auto tt_yyyy_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 159);

        auto tt_yyyy_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 160);

        auto tt_yyyy_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 161);

        auto tt_yyyy_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 162);

        auto tt_yyyy_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 163);

        auto tt_yyyy_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 164);

        auto tt_yyyz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 165);

        auto tt_yyyz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 166);

        auto tt_yyyz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 167);

        auto tt_yyyz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 168);

        auto tt_yyyz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 169);

        auto tt_yyyz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 170);

        auto tt_yyyz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 171);

        auto tt_yyyz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 172);

        auto tt_yyyz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 173);

        auto tt_yyyz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 174);

        auto tt_yyyz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 175);

        auto tt_yyyz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 176);

        auto tt_yyyz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 177);

        auto tt_yyyz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 178);

        auto tt_yyyz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 179);

        // Batch of Integrals (135,180)

        #pragma omp simd aligned(fga, fx, fz, pa_x, pa_y, ts_xzzz_xxxx_0, ts_xzzz_xxxy_0, ts_xzzz_xxxz_0, \
                                     ts_xzzz_xxyy_0, ts_xzzz_xxyz_0, ts_xzzz_xxzz_0, ts_xzzz_xyyy_0, ts_xzzz_xyyz_0, \
                                     ts_xzzz_xyzz_0, ts_xzzz_xzzz_0, ts_xzzz_yyyy_0, ts_xzzz_yyyz_0, ts_xzzz_yyzz_0, \
                                     ts_xzzz_yzzz_0, ts_xzzz_zzzz_0, ts_yy_xxxx_0, ts_yy_xxxy_0, ts_yy_xxxz_0, \
                                     ts_yy_xxyy_0, ts_yy_xxyz_0, ts_yy_xxzz_0, ts_yy_xyyy_0, ts_yy_xyyz_0, ts_yy_xyzz_0, \
                                     ts_yy_xzzz_0, ts_yy_yyyy_0, ts_yy_yyyz_0, ts_yy_yyzz_0, ts_yy_yzzz_0, ts_yy_zzzz_0, \
                                     ts_yyyy_xxxx_0, ts_yyyy_xxxy_0, ts_yyyy_xxxz_0, ts_yyyy_xxyy_0, ts_yyyy_xxyz_0, \
                                     ts_yyyy_xxzz_0, ts_yyyy_xyyy_0, ts_yyyy_xyyz_0, ts_yyyy_xyzz_0, ts_yyyy_xzzz_0, \
                                     ts_yyyy_yyyy_0, ts_yyyy_yyyz_0, ts_yyyy_yyzz_0, ts_yyyy_yzzz_0, ts_yyyy_zzzz_0, \
                                     ts_yyyz_xxxx_0, ts_yyyz_xxxy_0, ts_yyyz_xxxz_0, ts_yyyz_xxyy_0, ts_yyyz_xxyz_0, \
                                     ts_yyyz_xxzz_0, ts_yyyz_xyyy_0, ts_yyyz_xyyz_0, ts_yyyz_xyzz_0, ts_yyyz_xzzz_0, \
                                     ts_yyyz_yyyy_0, ts_yyyz_yyyz_0, ts_yyyz_yyzz_0, ts_yyyz_yzzz_0, ts_yyyz_zzzz_0, \
                                     ts_yz_xxxx_0, ts_yz_xxxy_0, ts_yz_xxxz_0, ts_yz_xxyy_0, ts_yz_xxyz_0, ts_yz_xxzz_0, \
                                     ts_yz_xyyy_0, ts_yz_xyyz_0, ts_yz_xyzz_0, ts_yz_xzzz_0, ts_yz_yyyy_0, ts_yz_yyyz_0, \
                                     ts_yz_yyzz_0, ts_yz_yzzz_0, ts_yz_zzzz_0, tt_xzzz_xxxx_0, tt_xzzz_xxxy_0, \
                                     tt_xzzz_xxxz_0, tt_xzzz_xxyy_0, tt_xzzz_xxyz_0, tt_xzzz_xxzz_0, tt_xzzz_xyyy_0, \
                                     tt_xzzz_xyyz_0, tt_xzzz_xyzz_0, tt_xzzz_xzzz_0, tt_xzzz_yyyy_0, tt_xzzz_yyyz_0, \
                                     tt_xzzz_yyzz_0, tt_xzzz_yzzz_0, tt_xzzz_zzzz_0, tt_yy_xxxx_0, tt_yy_xxxy_0, \
                                     tt_yy_xxxz_0, tt_yy_xxyy_0, tt_yy_xxyz_0, tt_yy_xxzz_0, tt_yy_xyyy_0, tt_yy_xyyz_0, \
                                     tt_yy_xyzz_0, tt_yy_xzzz_0, tt_yy_yyyy_0, tt_yy_yyyz_0, tt_yy_yyzz_0, tt_yy_yzzz_0, \
                                     tt_yy_zzzz_0, tt_yyy_xxx_0, tt_yyy_xxxx_0, tt_yyy_xxxy_0, tt_yyy_xxxz_0, \
                                     tt_yyy_xxy_0, tt_yyy_xxyy_0, tt_yyy_xxyz_0, tt_yyy_xxz_0, tt_yyy_xxzz_0, \
                                     tt_yyy_xyy_0, tt_yyy_xyyy_0, tt_yyy_xyyz_0, tt_yyy_xyz_0, tt_yyy_xyzz_0, \
                                     tt_yyy_xzz_0, tt_yyy_xzzz_0, tt_yyy_yyy_0, tt_yyy_yyyy_0, tt_yyy_yyyz_0, \
                                     tt_yyy_yyz_0, tt_yyy_yyzz_0, tt_yyy_yzz_0, tt_yyy_yzzz_0, tt_yyy_zzz_0, \
                                     tt_yyy_zzzz_0, tt_yyyy_xxxx_0, tt_yyyy_xxxy_0, tt_yyyy_xxxz_0, tt_yyyy_xxyy_0, \
                                     tt_yyyy_xxyz_0, tt_yyyy_xxzz_0, tt_yyyy_xyyy_0, tt_yyyy_xyyz_0, tt_yyyy_xyzz_0, \
                                     tt_yyyy_xzzz_0, tt_yyyy_yyyy_0, tt_yyyy_yyyz_0, tt_yyyy_yyzz_0, tt_yyyy_yzzz_0, \
                                     tt_yyyy_zzzz_0, tt_yyyz_xxxx_0, tt_yyyz_xxxy_0, tt_yyyz_xxxz_0, tt_yyyz_xxyy_0, \
                                     tt_yyyz_xxyz_0, tt_yyyz_xxzz_0, tt_yyyz_xyyy_0, tt_yyyz_xyyz_0, tt_yyyz_xyzz_0, \
                                     tt_yyyz_xzzz_0, tt_yyyz_yyyy_0, tt_yyyz_yyyz_0, tt_yyyz_yyzz_0, tt_yyyz_yzzz_0, \
                                     tt_yyyz_zzzz_0, tt_yyz_xxx_0, tt_yyz_xxxx_0, tt_yyz_xxxy_0, tt_yyz_xxxz_0, \
                                     tt_yyz_xxy_0, tt_yyz_xxyy_0, tt_yyz_xxyz_0, tt_yyz_xxz_0, tt_yyz_xxzz_0, \
                                     tt_yyz_xyy_0, tt_yyz_xyyy_0, tt_yyz_xyyz_0, tt_yyz_xyz_0, tt_yyz_xyzz_0, \
                                     tt_yyz_xzz_0, tt_yyz_xzzz_0, tt_yyz_yyy_0, tt_yyz_yyyy_0, tt_yyz_yyyz_0, \
                                     tt_yyz_yyz_0, tt_yyz_yyzz_0, tt_yyz_yzz_0, tt_yyz_yzzz_0, tt_yyz_zzz_0, \
                                     tt_yyz_zzzz_0, tt_yz_xxxx_0, tt_yz_xxxy_0, tt_yz_xxxz_0, tt_yz_xxyy_0, tt_yz_xxyz_0, \
                                     tt_yz_xxzz_0, tt_yz_xyyy_0, tt_yz_xyyz_0, tt_yz_xyzz_0, tt_yz_xzzz_0, tt_yz_yyyy_0, \
                                     tt_yz_yyyz_0, tt_yz_yyzz_0, tt_yz_yzzz_0, tt_yz_zzzz_0, tt_zzz_xxx_0, \
                                     tt_zzz_xxxx_0, tt_zzz_xxxy_0, tt_zzz_xxxz_0, tt_zzz_xxy_0, tt_zzz_xxyy_0, \
                                     tt_zzz_xxyz_0, tt_zzz_xxz_0, tt_zzz_xxzz_0, tt_zzz_xyy_0, tt_zzz_xyyy_0, \
                                     tt_zzz_xyyz_0, tt_zzz_xyz_0, tt_zzz_xyzz_0, tt_zzz_xzz_0, tt_zzz_xzzz_0, \
                                     tt_zzz_yyy_0, tt_zzz_yyyy_0, tt_zzz_yyyz_0, tt_zzz_yyz_0, tt_zzz_yyzz_0, \
                                     tt_zzz_yzz_0, tt_zzz_yzzz_0, tt_zzz_zzz_0, tt_zzz_zzzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fga = fga[j];

            double fl1_fx = fx[j];

            double fl1_fz = fz[j];

            tt_xzzz_xxxx_0[j] = pa_x[j] * tt_zzz_xxxx_0[j] + 2.0 * fl1_fx * tt_zzz_xxx_0[j] + 2.0 * fl1_fz * ts_xzzz_xxxx_0[j];

            tt_xzzz_xxxy_0[j] = pa_x[j] * tt_zzz_xxxy_0[j] + 1.5 * fl1_fx * tt_zzz_xxy_0[j] + 2.0 * fl1_fz * ts_xzzz_xxxy_0[j];

            tt_xzzz_xxxz_0[j] = pa_x[j] * tt_zzz_xxxz_0[j] + 1.5 * fl1_fx * tt_zzz_xxz_0[j] + 2.0 * fl1_fz * ts_xzzz_xxxz_0[j];

            tt_xzzz_xxyy_0[j] = pa_x[j] * tt_zzz_xxyy_0[j] + fl1_fx * tt_zzz_xyy_0[j] + 2.0 * fl1_fz * ts_xzzz_xxyy_0[j];

            tt_xzzz_xxyz_0[j] = pa_x[j] * tt_zzz_xxyz_0[j] + fl1_fx * tt_zzz_xyz_0[j] + 2.0 * fl1_fz * ts_xzzz_xxyz_0[j];

            tt_xzzz_xxzz_0[j] = pa_x[j] * tt_zzz_xxzz_0[j] + fl1_fx * tt_zzz_xzz_0[j] + 2.0 * fl1_fz * ts_xzzz_xxzz_0[j];

            tt_xzzz_xyyy_0[j] = pa_x[j] * tt_zzz_xyyy_0[j] + 0.5 * fl1_fx * tt_zzz_yyy_0[j] + 2.0 * fl1_fz * ts_xzzz_xyyy_0[j];

            tt_xzzz_xyyz_0[j] = pa_x[j] * tt_zzz_xyyz_0[j] + 0.5 * fl1_fx * tt_zzz_yyz_0[j] + 2.0 * fl1_fz * ts_xzzz_xyyz_0[j];

            tt_xzzz_xyzz_0[j] = pa_x[j] * tt_zzz_xyzz_0[j] + 0.5 * fl1_fx * tt_zzz_yzz_0[j] + 2.0 * fl1_fz * ts_xzzz_xyzz_0[j];

            tt_xzzz_xzzz_0[j] = pa_x[j] * tt_zzz_xzzz_0[j] + 0.5 * fl1_fx * tt_zzz_zzz_0[j] + 2.0 * fl1_fz * ts_xzzz_xzzz_0[j];

            tt_xzzz_yyyy_0[j] = pa_x[j] * tt_zzz_yyyy_0[j] + 2.0 * fl1_fz * ts_xzzz_yyyy_0[j];

            tt_xzzz_yyyz_0[j] = pa_x[j] * tt_zzz_yyyz_0[j] + 2.0 * fl1_fz * ts_xzzz_yyyz_0[j];

            tt_xzzz_yyzz_0[j] = pa_x[j] * tt_zzz_yyzz_0[j] + 2.0 * fl1_fz * ts_xzzz_yyzz_0[j];

            tt_xzzz_yzzz_0[j] = pa_x[j] * tt_zzz_yzzz_0[j] + 2.0 * fl1_fz * ts_xzzz_yzzz_0[j];

            tt_xzzz_zzzz_0[j] = pa_x[j] * tt_zzz_zzzz_0[j] + 2.0 * fl1_fz * ts_xzzz_zzzz_0[j];

            tt_yyyy_xxxx_0[j] = pa_y[j] * tt_yyy_xxxx_0[j] + 1.5 * fl1_fx * tt_yy_xxxx_0[j] + 2.0 * fl1_fz * ts_yyyy_xxxx_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_yy_xxxx_0[j];

            tt_yyyy_xxxy_0[j] = pa_y[j] * tt_yyy_xxxy_0[j] + 1.5 * fl1_fx * tt_yy_xxxy_0[j] + 0.5 * fl1_fx * tt_yyy_xxx_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xxxy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xxxy_0[j];

            tt_yyyy_xxxz_0[j] = pa_y[j] * tt_yyy_xxxz_0[j] + 1.5 * fl1_fx * tt_yy_xxxz_0[j] + 2.0 * fl1_fz * ts_yyyy_xxxz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_yy_xxxz_0[j];

            tt_yyyy_xxyy_0[j] = pa_y[j] * tt_yyy_xxyy_0[j] + 1.5 * fl1_fx * tt_yy_xxyy_0[j] + fl1_fx * tt_yyy_xxy_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xxyy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xxyy_0[j];

            tt_yyyy_xxyz_0[j] = pa_y[j] * tt_yyy_xxyz_0[j] + 1.5 * fl1_fx * tt_yy_xxyz_0[j] + 0.5 * fl1_fx * tt_yyy_xxz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xxyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xxyz_0[j];

            tt_yyyy_xxzz_0[j] = pa_y[j] * tt_yyy_xxzz_0[j] + 1.5 * fl1_fx * tt_yy_xxzz_0[j] + 2.0 * fl1_fz * ts_yyyy_xxzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_yy_xxzz_0[j];

            tt_yyyy_xyyy_0[j] = pa_y[j] * tt_yyy_xyyy_0[j] + 1.5 * fl1_fx * tt_yy_xyyy_0[j] + 1.5 * fl1_fx * tt_yyy_xyy_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xyyy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xyyy_0[j];

            tt_yyyy_xyyz_0[j] = pa_y[j] * tt_yyy_xyyz_0[j] + 1.5 * fl1_fx * tt_yy_xyyz_0[j] + fl1_fx * tt_yyy_xyz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xyyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xyyz_0[j];

            tt_yyyy_xyzz_0[j] = pa_y[j] * tt_yyy_xyzz_0[j] + 1.5 * fl1_fx * tt_yy_xyzz_0[j] + 0.5 * fl1_fx * tt_yyy_xzz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_xyzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_xyzz_0[j];

            tt_yyyy_xzzz_0[j] = pa_y[j] * tt_yyy_xzzz_0[j] + 1.5 * fl1_fx * tt_yy_xzzz_0[j] + 2.0 * fl1_fz * ts_yyyy_xzzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_yy_xzzz_0[j];

            tt_yyyy_yyyy_0[j] = pa_y[j] * tt_yyy_yyyy_0[j] + 1.5 * fl1_fx * tt_yy_yyyy_0[j] + 2.0 * fl1_fx * tt_yyy_yyy_0[j] +
                                2.0 * fl1_fz * ts_yyyy_yyyy_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_yyyy_0[j];

            tt_yyyy_yyyz_0[j] = pa_y[j] * tt_yyy_yyyz_0[j] + 1.5 * fl1_fx * tt_yy_yyyz_0[j] + 1.5 * fl1_fx * tt_yyy_yyz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_yyyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_yyyz_0[j];

            tt_yyyy_yyzz_0[j] = pa_y[j] * tt_yyy_yyzz_0[j] + 1.5 * fl1_fx * tt_yy_yyzz_0[j] + fl1_fx * tt_yyy_yzz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_yyzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_yyzz_0[j];

            tt_yyyy_yzzz_0[j] = pa_y[j] * tt_yyy_yzzz_0[j] + 1.5 * fl1_fx * tt_yy_yzzz_0[j] + 0.5 * fl1_fx * tt_yyy_zzz_0[j] +
                                2.0 * fl1_fz * ts_yyyy_yzzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_yy_yzzz_0[j];

            tt_yyyy_zzzz_0[j] = pa_y[j] * tt_yyy_zzzz_0[j] + 1.5 * fl1_fx * tt_yy_zzzz_0[j] + 2.0 * fl1_fz * ts_yyyy_zzzz_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_yy_zzzz_0[j];

            tt_yyyz_xxxx_0[j] =
                pa_y[j] * tt_yyz_xxxx_0[j] + fl1_fx * tt_yz_xxxx_0[j] + 2.0 * fl1_fz * ts_yyyz_xxxx_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xxxx_0[j];

            tt_yyyz_xxxy_0[j] = pa_y[j] * tt_yyz_xxxy_0[j] + fl1_fx * tt_yz_xxxy_0[j] + 0.5 * fl1_fx * tt_yyz_xxx_0[j] +
                                2.0 * fl1_fz * ts_yyyz_xxxy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xxxy_0[j];

            tt_yyyz_xxxz_0[j] =
                pa_y[j] * tt_yyz_xxxz_0[j] + fl1_fx * tt_yz_xxxz_0[j] + 2.0 * fl1_fz * ts_yyyz_xxxz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xxxz_0[j];

            tt_yyyz_xxyy_0[j] = pa_y[j] * tt_yyz_xxyy_0[j] + fl1_fx * tt_yz_xxyy_0[j] + fl1_fx * tt_yyz_xxy_0[j] + 2.0 * fl1_fz * ts_yyyz_xxyy_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_yz_xxyy_0[j];

            tt_yyyz_xxyz_0[j] = pa_y[j] * tt_yyz_xxyz_0[j] + fl1_fx * tt_yz_xxyz_0[j] + 0.5 * fl1_fx * tt_yyz_xxz_0[j] +
                                2.0 * fl1_fz * ts_yyyz_xxyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xxyz_0[j];

            tt_yyyz_xxzz_0[j] =
                pa_y[j] * tt_yyz_xxzz_0[j] + fl1_fx * tt_yz_xxzz_0[j] + 2.0 * fl1_fz * ts_yyyz_xxzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xxzz_0[j];

            tt_yyyz_xyyy_0[j] = pa_y[j] * tt_yyz_xyyy_0[j] + fl1_fx * tt_yz_xyyy_0[j] + 1.5 * fl1_fx * tt_yyz_xyy_0[j] +
                                2.0 * fl1_fz * ts_yyyz_xyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xyyy_0[j];

            tt_yyyz_xyyz_0[j] = pa_y[j] * tt_yyz_xyyz_0[j] + fl1_fx * tt_yz_xyyz_0[j] + fl1_fx * tt_yyz_xyz_0[j] + 2.0 * fl1_fz * ts_yyyz_xyyz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_yz_xyyz_0[j];

            tt_yyyz_xyzz_0[j] = pa_y[j] * tt_yyz_xyzz_0[j] + fl1_fx * tt_yz_xyzz_0[j] + 0.5 * fl1_fx * tt_yyz_xzz_0[j] +
                                2.0 * fl1_fz * ts_yyyz_xyzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xyzz_0[j];

            tt_yyyz_xzzz_0[j] =
                pa_y[j] * tt_yyz_xzzz_0[j] + fl1_fx * tt_yz_xzzz_0[j] + 2.0 * fl1_fz * ts_yyyz_xzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_xzzz_0[j];

            tt_yyyz_yyyy_0[j] = pa_y[j] * tt_yyz_yyyy_0[j] + fl1_fx * tt_yz_yyyy_0[j] + 2.0 * fl1_fx * tt_yyz_yyy_0[j] +
                                2.0 * fl1_fz * ts_yyyz_yyyy_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_yyyy_0[j];

            tt_yyyz_yyyz_0[j] = pa_y[j] * tt_yyz_yyyz_0[j] + fl1_fx * tt_yz_yyyz_0[j] + 1.5 * fl1_fx * tt_yyz_yyz_0[j] +
                                2.0 * fl1_fz * ts_yyyz_yyyz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_yyyz_0[j];

            tt_yyyz_yyzz_0[j] = pa_y[j] * tt_yyz_yyzz_0[j] + fl1_fx * tt_yz_yyzz_0[j] + fl1_fx * tt_yyz_yzz_0[j] + 2.0 * fl1_fz * ts_yyyz_yyzz_0[j] -
                                2.0 * fl1_fz * fl1_fga * ts_yz_yyzz_0[j];

            tt_yyyz_yzzz_0[j] = pa_y[j] * tt_yyz_yzzz_0[j] + fl1_fx * tt_yz_yzzz_0[j] + 0.5 * fl1_fx * tt_yyz_zzz_0[j] +
                                2.0 * fl1_fz * ts_yyyz_yzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_yzzz_0[j];

            tt_yyyz_zzzz_0[j] =
                pa_y[j] * tt_yyz_zzzz_0[j] + fl1_fx * tt_yz_zzzz_0[j] + 2.0 * fl1_fz * ts_yyyz_zzzz_0[j] - 2.0 * fl1_fz * fl1_fga * ts_yz_zzzz_0[j];
        }

        idx++;
    }
}

void
compKineticEnergyForGG_180_225(CMemBlock2D<double>&       primBuffer,
                               const CRecursionMap&       recursionMap,
                               const CMemBlock2D<double>& osFactors,
                               const CMemBlock2D<double>& paDistances,
                               const CGtoBlock&           braGtoBlock,
                               const CGtoBlock&           ketGtoBlock,
                               const int32_t              iContrGto)
{
    // Batch of Integrals (180,225)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_t_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_t_4_4_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_t_3_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_4_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_4_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {4, -1, -1, -1}, 1, 1, 0));

    auto pidx_t_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Kinetic Energy"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(4 * idx);

        auto fz = osFactors.data(4 * idx + 1);

        auto fga = osFactors.data(4 * idx + 2);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_y = paDistances.data(3 * idx + 1);

        auto pa_z = paDistances.data(3 * idx + 2);

        // set up pointers to auxilary integrals

        auto tt_yzz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 120);

        auto tt_yzz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 121);

        auto tt_yzz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 122);

        auto tt_yzz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 123);

        auto tt_yzz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 124);

        auto tt_yzz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 125);

        auto tt_yzz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 126);

        auto tt_yzz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 127);

        auto tt_yzz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 128);

        auto tt_yzz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 129);

        auto tt_yzz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 130);

        auto tt_yzz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 131);

        auto tt_yzz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 132);

        auto tt_yzz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 133);

        auto tt_yzz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 134);

        auto tt_zzz_xxxx_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 135);

        auto tt_zzz_xxxy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 136);

        auto tt_zzz_xxxz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 137);

        auto tt_zzz_xxyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 138);

        auto tt_zzz_xxyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 139);

        auto tt_zzz_xxzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 140);

        auto tt_zzz_xyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 141);

        auto tt_zzz_xyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 142);

        auto tt_zzz_xyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 143);

        auto tt_zzz_xzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 144);

        auto tt_zzz_yyyy_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 145);

        auto tt_zzz_yyyz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 146);

        auto tt_zzz_yyzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 147);

        auto tt_zzz_yzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 148);

        auto tt_zzz_zzzz_0 = primBuffer.data(pidx_t_3_4_m0 + 150 * idx + 149);

        auto tt_zz_xxxx_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 75);

        auto tt_zz_xxxy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 76);

        auto tt_zz_xxxz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 77);

        auto tt_zz_xxyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 78);

        auto tt_zz_xxyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 79);

        auto tt_zz_xxzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 80);

        auto tt_zz_xyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 81);

        auto tt_zz_xyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 82);

        auto tt_zz_xyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 83);

        auto tt_zz_xzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 84);

        auto tt_zz_yyyy_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 85);

        auto tt_zz_yyyz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 86);

        auto tt_zz_yyzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 87);

        auto tt_zz_yzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 88);

        auto tt_zz_zzzz_0 = primBuffer.data(pidx_t_2_4_m0 + 90 * idx + 89);

        auto tt_yzz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 80);

        auto tt_yzz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 81);

        auto tt_yzz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 82);

        auto tt_yzz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 83);

        auto tt_yzz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 84);

        auto tt_yzz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 85);

        auto tt_yzz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 86);

        auto tt_yzz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 87);

        auto tt_yzz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 88);

        auto tt_yzz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 89);

        auto tt_zzz_xxx_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 90);

        auto tt_zzz_xxy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 91);

        auto tt_zzz_xxz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 92);

        auto tt_zzz_xyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 93);

        auto tt_zzz_xyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 94);

        auto tt_zzz_xzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 95);

        auto tt_zzz_yyy_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 96);

        auto tt_zzz_yyz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 97);

        auto tt_zzz_yzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 98);

        auto tt_zzz_zzz_0 = primBuffer.data(pidx_t_3_3_m0 + 100 * idx + 99);

        auto ts_yyzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 180);

        auto ts_yyzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 181);

        auto ts_yyzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 182);

        auto ts_yyzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 183);

        auto ts_yyzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 184);

        auto ts_yyzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 185);

        auto ts_yyzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 186);

        auto ts_yyzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 187);

        auto ts_yyzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 188);

        auto ts_yyzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 189);

        auto ts_yyzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 190);

        auto ts_yyzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 191);

        auto ts_yyzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 192);

        auto ts_yyzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 193);

        auto ts_yyzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 194);

        auto ts_yzzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 195);

        auto ts_yzzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 196);

        auto ts_yzzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 197);

        auto ts_yzzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 198);

        auto ts_yzzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 199);

        auto ts_yzzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 200);

        auto ts_yzzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 201);

        auto ts_yzzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 202);

        auto ts_yzzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 203);

        auto ts_yzzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 204);

        auto ts_yzzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 205);

        auto ts_yzzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 206);

        auto ts_yzzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 207);

        auto ts_yzzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 208);

        auto ts_yzzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 209);

        auto ts_zzzz_xxxx_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 210);

        auto ts_zzzz_xxxy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 211);

        auto ts_zzzz_xxxz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 212);

        auto ts_zzzz_xxyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 213);

        auto ts_zzzz_xxyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 214);

        auto ts_zzzz_xxzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 215);

        auto ts_zzzz_xyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 216);

        auto ts_zzzz_xyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 217);

        auto ts_zzzz_xyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 218);

        auto ts_zzzz_xzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 219);

        auto ts_zzzz_yyyy_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 220);

        auto ts_zzzz_yyyz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 221);

        auto ts_zzzz_yyzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 222);

        auto ts_zzzz_yzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 223);

        auto ts_zzzz_zzzz_0 = primBuffer.data(pidx_s_4_4_m0 + 225 * idx + 224);

        auto ts_zz_xxxx_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 75);

        auto ts_zz_xxxy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 76);

        auto ts_zz_xxxz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 77);

        auto ts_zz_xxyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 78);

        auto ts_zz_xxyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 79);

        auto ts_zz_xxzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 80);

        auto ts_zz_xyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 81);

        auto ts_zz_xyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 82);

        auto ts_zz_xyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 83);

        auto ts_zz_xzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 84);

        auto ts_zz_yyyy_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 85);

        auto ts_zz_yyyz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 86);

        auto ts_zz_yyzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 87);

        auto ts_zz_yzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 88);

        auto ts_zz_zzzz_0 = primBuffer.data(pidx_s_2_4_m0 + 90 * idx + 89);

        // set up pointers to integrals

        auto tt_yyzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 180);

        auto tt_yyzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 181);

        auto tt_yyzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 182);

        auto tt_yyzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 183);

        auto tt_yyzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 184);

        auto tt_yyzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 185);

        auto tt_yyzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 186);

        auto tt_yyzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 187);

        auto tt_yyzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 188);

        auto tt_yyzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 189);

        auto tt_yyzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 190);

        auto tt_yyzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 191);

        auto tt_yyzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 192);

        auto tt_yyzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 193);

        auto tt_yyzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 194);

        auto tt_yzzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 195);

        auto tt_yzzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 196);

        auto tt_yzzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 197);

        auto tt_yzzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 198);

        auto tt_yzzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 199);

        auto tt_yzzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 200);

        auto tt_yzzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 201);

        auto tt_yzzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 202);

        auto tt_yzzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 203);

        auto tt_yzzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 204);

        auto tt_yzzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 205);

        auto tt_yzzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 206);

        auto tt_yzzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 207);

        auto tt_yzzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 208);

        auto tt_yzzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 209);

        auto tt_zzzz_xxxx_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 210);

        auto tt_zzzz_xxxy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 211);

        auto tt_zzzz_xxxz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 212);

        auto tt_zzzz_xxyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 213);

        auto tt_zzzz_xxyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 214);

        auto tt_zzzz_xxzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 215);

        auto tt_zzzz_xyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 216);

        auto tt_zzzz_xyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 217);

        auto tt_zzzz_xyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 218);

        auto tt_zzzz_xzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 219);

        auto tt_zzzz_yyyy_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 220);

        auto tt_zzzz_yyyz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 221);

        auto tt_zzzz_yyzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 222);

        auto tt_zzzz_yzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 223);

        auto tt_zzzz_zzzz_0 = primBuffer.data(pidx_t_4_4_m0 + 225 * idx + 224);

        // Batch of Integrals (180,225)

        #pragma omp simd aligned(fga, fx, fz, pa_y, pa_z, ts_yyzz_xxxx_0, ts_yyzz_xxxy_0, ts_yyzz_xxxz_0, \
                                     ts_yyzz_xxyy_0, ts_yyzz_xxyz_0, ts_yyzz_xxzz_0, ts_yyzz_xyyy_0, ts_yyzz_xyyz_0, \
                                     ts_yyzz_xyzz_0, ts_yyzz_xzzz_0, ts_yyzz_yyyy_0, ts_yyzz_yyyz_0, ts_yyzz_yyzz_0, \
                                     ts_yyzz_yzzz_0, ts_yyzz_zzzz_0, ts_yzzz_xxxx_0, ts_yzzz_xxxy_0, ts_yzzz_xxxz_0, \
                                     ts_yzzz_xxyy_0, ts_yzzz_xxyz_0, ts_yzzz_xxzz_0, ts_yzzz_xyyy_0, ts_yzzz_xyyz_0, \
                                     ts_yzzz_xyzz_0, ts_yzzz_xzzz_0, ts_yzzz_yyyy_0, ts_yzzz_yyyz_0, ts_yzzz_yyzz_0, \
                                     ts_yzzz_yzzz_0, ts_yzzz_zzzz_0, ts_zz_xxxx_0, ts_zz_xxxy_0, ts_zz_xxxz_0, \
                                     ts_zz_xxyy_0, ts_zz_xxyz_0, ts_zz_xxzz_0, ts_zz_xyyy_0, ts_zz_xyyz_0, ts_zz_xyzz_0, \
                                     ts_zz_xzzz_0, ts_zz_yyyy_0, ts_zz_yyyz_0, ts_zz_yyzz_0, ts_zz_yzzz_0, ts_zz_zzzz_0, \
                                     ts_zzzz_xxxx_0, ts_zzzz_xxxy_0, ts_zzzz_xxxz_0, ts_zzzz_xxyy_0, ts_zzzz_xxyz_0, \
                                     ts_zzzz_xxzz_0, ts_zzzz_xyyy_0, ts_zzzz_xyyz_0, ts_zzzz_xyzz_0, ts_zzzz_xzzz_0, \
                                     ts_zzzz_yyyy_0, ts_zzzz_yyyz_0, ts_zzzz_yyzz_0, ts_zzzz_yzzz_0, ts_zzzz_zzzz_0, \
                                     tt_yyzz_xxxx_0, tt_yyzz_xxxy_0, tt_yyzz_xxxz_0, tt_yyzz_xxyy_0, tt_yyzz_xxyz_0, \
                                     tt_yyzz_xxzz_0, tt_yyzz_xyyy_0, tt_yyzz_xyyz_0, tt_yyzz_xyzz_0, tt_yyzz_xzzz_0, \
                                     tt_yyzz_yyyy_0, tt_yyzz_yyyz_0, tt_yyzz_yyzz_0, tt_yyzz_yzzz_0, tt_yyzz_zzzz_0, \
                                     tt_yzz_xxx_0, tt_yzz_xxxx_0, tt_yzz_xxxy_0, tt_yzz_xxxz_0, tt_yzz_xxy_0, \
                                     tt_yzz_xxyy_0, tt_yzz_xxyz_0, tt_yzz_xxz_0, tt_yzz_xxzz_0, tt_yzz_xyy_0, \
                                     tt_yzz_xyyy_0, tt_yzz_xyyz_0, tt_yzz_xyz_0, tt_yzz_xyzz_0, tt_yzz_xzz_0, \
                                     tt_yzz_xzzz_0, tt_yzz_yyy_0, tt_yzz_yyyy_0, tt_yzz_yyyz_0, tt_yzz_yyz_0, \
                                     tt_yzz_yyzz_0, tt_yzz_yzz_0, tt_yzz_yzzz_0, tt_yzz_zzz_0, tt_yzz_zzzz_0, \
                                     tt_yzzz_xxxx_0, tt_yzzz_xxxy_0, tt_yzzz_xxxz_0, tt_yzzz_xxyy_0, tt_yzzz_xxyz_0, \
                                     tt_yzzz_xxzz_0, tt_yzzz_xyyy_0, tt_yzzz_xyyz_0, tt_yzzz_xyzz_0, tt_yzzz_xzzz_0, \
                                     tt_yzzz_yyyy_0, tt_yzzz_yyyz_0, tt_yzzz_yyzz_0, tt_yzzz_yzzz_0, tt_yzzz_zzzz_0, \
                                     tt_zz_xxxx_0, tt_zz_xxxy_0, tt_zz_xxxz_0, tt_zz_xxyy_0, tt_zz_xxyz_0, tt_zz_xxzz_0, \
                                     tt_zz_xyyy_0, tt_zz_xyyz_0, tt_zz_xyzz_0, tt_zz_xzzz_0, tt_zz_yyyy_0, tt_zz_yyyz_0, \
                                     tt_zz_yyzz_0, tt_zz_yzzz_0, tt_zz_zzzz_0, tt_zzz_xxx_0, tt_zzz_xxxx_0, \
                                     tt_zzz_xxxy_0, tt_zzz_xxxz_0, tt_zzz_xxy_0, tt_zzz_xxyy_0, tt_zzz_xxyz_0, \
                                     tt_zzz_xxz_0, tt_zzz_xxzz_0, tt_zzz_xyy_0, tt_zzz_xyyy_0, tt_zzz_xyyz_0, \
                                     tt_zzz_xyz_0, tt_zzz_xyzz_0, tt_zzz_xzz_0, tt_zzz_xzzz_0, tt_zzz_yyy_0, \
                                     tt_zzz_yyyy_0, tt_zzz_yyyz_0, tt_zzz_yyz_0, tt_zzz_yyzz_0, tt_zzz_yzz_0, \
                                     tt_zzz_yzzz_0, tt_zzz_zzz_0, tt_zzz_zzzz_0, tt_zzzz_xxxx_0, tt_zzzz_xxxy_0, \
                                     tt_zzzz_xxxz_0, tt_zzzz_xxyy_0, tt_zzzz_xxyz_0, tt_zzzz_xxzz_0, tt_zzzz_xyyy_0, \
                                     tt_zzzz_xyyz_0, tt_zzzz_xyzz_0, tt_zzzz_xzzz_0, tt_zzzz_yyyy_0, tt_zzzz_yyyz_0, \
                                     tt_zzzz_yyzz_0, tt_zzzz_yzzz_0, tt_zzzz_zzzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fga = fga[j];

            double fl1_fx = fx[j];

            double fl1_fz = fz[j];

            tt_yyzz_xxxx_0[j] =
                pa_y[j] * tt_yzz_xxxx_0[j] + 0.5 * fl1_fx * tt_zz_xxxx_0[j] + 2.0 * fl1_fz * ts_yyzz_xxxx_0[j] - fl1_fz * fl1_fga * ts_zz_xxxx_0[j];

            tt_yyzz_xxxy_0[j] = pa_y[j] * tt_yzz_xxxy_0[j] + 0.5 * fl1_fx * tt_zz_xxxy_0[j] + 0.5 * fl1_fx * tt_yzz_xxx_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xxxy_0[j] - fl1_fz * fl1_fga * ts_zz_xxxy_0[j];

            tt_yyzz_xxxz_0[j] =
                pa_y[j] * tt_yzz_xxxz_0[j] + 0.5 * fl1_fx * tt_zz_xxxz_0[j] + 2.0 * fl1_fz * ts_yyzz_xxxz_0[j] - fl1_fz * fl1_fga * ts_zz_xxxz_0[j];

            tt_yyzz_xxyy_0[j] = pa_y[j] * tt_yzz_xxyy_0[j] + 0.5 * fl1_fx * tt_zz_xxyy_0[j] + fl1_fx * tt_yzz_xxy_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xxyy_0[j] - fl1_fz * fl1_fga * ts_zz_xxyy_0[j];

            tt_yyzz_xxyz_0[j] = pa_y[j] * tt_yzz_xxyz_0[j] + 0.5 * fl1_fx * tt_zz_xxyz_0[j] + 0.5 * fl1_fx * tt_yzz_xxz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xxyz_0[j] - fl1_fz * fl1_fga * ts_zz_xxyz_0[j];

            tt_yyzz_xxzz_0[j] =
                pa_y[j] * tt_yzz_xxzz_0[j] + 0.5 * fl1_fx * tt_zz_xxzz_0[j] + 2.0 * fl1_fz * ts_yyzz_xxzz_0[j] - fl1_fz * fl1_fga * ts_zz_xxzz_0[j];

            tt_yyzz_xyyy_0[j] = pa_y[j] * tt_yzz_xyyy_0[j] + 0.5 * fl1_fx * tt_zz_xyyy_0[j] + 1.5 * fl1_fx * tt_yzz_xyy_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xyyy_0[j] - fl1_fz * fl1_fga * ts_zz_xyyy_0[j];

            tt_yyzz_xyyz_0[j] = pa_y[j] * tt_yzz_xyyz_0[j] + 0.5 * fl1_fx * tt_zz_xyyz_0[j] + fl1_fx * tt_yzz_xyz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xyyz_0[j] - fl1_fz * fl1_fga * ts_zz_xyyz_0[j];

            tt_yyzz_xyzz_0[j] = pa_y[j] * tt_yzz_xyzz_0[j] + 0.5 * fl1_fx * tt_zz_xyzz_0[j] + 0.5 * fl1_fx * tt_yzz_xzz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_xyzz_0[j] - fl1_fz * fl1_fga * ts_zz_xyzz_0[j];

            tt_yyzz_xzzz_0[j] =
                pa_y[j] * tt_yzz_xzzz_0[j] + 0.5 * fl1_fx * tt_zz_xzzz_0[j] + 2.0 * fl1_fz * ts_yyzz_xzzz_0[j] - fl1_fz * fl1_fga * ts_zz_xzzz_0[j];

            tt_yyzz_yyyy_0[j] = pa_y[j] * tt_yzz_yyyy_0[j] + 0.5 * fl1_fx * tt_zz_yyyy_0[j] + 2.0 * fl1_fx * tt_yzz_yyy_0[j] +
                                2.0 * fl1_fz * ts_yyzz_yyyy_0[j] - fl1_fz * fl1_fga * ts_zz_yyyy_0[j];

            tt_yyzz_yyyz_0[j] = pa_y[j] * tt_yzz_yyyz_0[j] + 0.5 * fl1_fx * tt_zz_yyyz_0[j] + 1.5 * fl1_fx * tt_yzz_yyz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_yyyz_0[j] - fl1_fz * fl1_fga * ts_zz_yyyz_0[j];

            tt_yyzz_yyzz_0[j] = pa_y[j] * tt_yzz_yyzz_0[j] + 0.5 * fl1_fx * tt_zz_yyzz_0[j] + fl1_fx * tt_yzz_yzz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_yyzz_0[j] - fl1_fz * fl1_fga * ts_zz_yyzz_0[j];

            tt_yyzz_yzzz_0[j] = pa_y[j] * tt_yzz_yzzz_0[j] + 0.5 * fl1_fx * tt_zz_yzzz_0[j] + 0.5 * fl1_fx * tt_yzz_zzz_0[j] +
                                2.0 * fl1_fz * ts_yyzz_yzzz_0[j] - fl1_fz * fl1_fga * ts_zz_yzzz_0[j];

            tt_yyzz_zzzz_0[j] =
                pa_y[j] * tt_yzz_zzzz_0[j] + 0.5 * fl1_fx * tt_zz_zzzz_0[j] + 2.0 * fl1_fz * ts_yyzz_zzzz_0[j] - fl1_fz * fl1_fga * ts_zz_zzzz_0[j];

            tt_yzzz_xxxx_0[j] = pa_y[j] * tt_zzz_xxxx_0[j] + 2.0 * fl1_fz * ts_yzzz_xxxx_0[j];

            tt_yzzz_xxxy_0[j] = pa_y[j] * tt_zzz_xxxy_0[j] + 0.5 * fl1_fx * tt_zzz_xxx_0[j] + 2.0 * fl1_fz * ts_yzzz_xxxy_0[j];

            tt_yzzz_xxxz_0[j] = pa_y[j] * tt_zzz_xxxz_0[j] + 2.0 * fl1_fz * ts_yzzz_xxxz_0[j];

            tt_yzzz_xxyy_0[j] = pa_y[j] * tt_zzz_xxyy_0[j] + fl1_fx * tt_zzz_xxy_0[j] + 2.0 * fl1_fz * ts_yzzz_xxyy_0[j];

            tt_yzzz_xxyz_0[j] = pa_y[j] * tt_zzz_xxyz_0[j] + 0.5 * fl1_fx * tt_zzz_xxz_0[j] + 2.0 * fl1_fz * ts_yzzz_xxyz_0[j];

            tt_yzzz_xxzz_0[j] = pa_y[j] * tt_zzz_xxzz_0[j] + 2.0 * fl1_fz * ts_yzzz_xxzz_0[j];

            tt_yzzz_xyyy_0[j] = pa_y[j] * tt_zzz_xyyy_0[j] + 1.5 * fl1_fx * tt_zzz_xyy_0[j] + 2.0 * fl1_fz * ts_yzzz_xyyy_0[j];

            tt_yzzz_xyyz_0[j] = pa_y[j] * tt_zzz_xyyz_0[j] + fl1_fx * tt_zzz_xyz_0[j] + 2.0 * fl1_fz * ts_yzzz_xyyz_0[j];

            tt_yzzz_xyzz_0[j] = pa_y[j] * tt_zzz_xyzz_0[j] + 0.5 * fl1_fx * tt_zzz_xzz_0[j] + 2.0 * fl1_fz * ts_yzzz_xyzz_0[j];

            tt_yzzz_xzzz_0[j] = pa_y[j] * tt_zzz_xzzz_0[j] + 2.0 * fl1_fz * ts_yzzz_xzzz_0[j];

            tt_yzzz_yyyy_0[j] = pa_y[j] * tt_zzz_yyyy_0[j] + 2.0 * fl1_fx * tt_zzz_yyy_0[j] + 2.0 * fl1_fz * ts_yzzz_yyyy_0[j];

            tt_yzzz_yyyz_0[j] = pa_y[j] * tt_zzz_yyyz_0[j] + 1.5 * fl1_fx * tt_zzz_yyz_0[j] + 2.0 * fl1_fz * ts_yzzz_yyyz_0[j];

            tt_yzzz_yyzz_0[j] = pa_y[j] * tt_zzz_yyzz_0[j] + fl1_fx * tt_zzz_yzz_0[j] + 2.0 * fl1_fz * ts_yzzz_yyzz_0[j];

            tt_yzzz_yzzz_0[j] = pa_y[j] * tt_zzz_yzzz_0[j] + 0.5 * fl1_fx * tt_zzz_zzz_0[j] + 2.0 * fl1_fz * ts_yzzz_yzzz_0[j];

            tt_yzzz_zzzz_0[j] = pa_y[j] * tt_zzz_zzzz_0[j] + 2.0 * fl1_fz * ts_yzzz_zzzz_0[j];

            tt_zzzz_xxxx_0[j] = pa_z[j] * tt_zzz_xxxx_0[j] + 1.5 * fl1_fx * tt_zz_xxxx_0[j] + 2.0 * fl1_fz * ts_zzzz_xxxx_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_zz_xxxx_0[j];

            tt_zzzz_xxxy_0[j] = pa_z[j] * tt_zzz_xxxy_0[j] + 1.5 * fl1_fx * tt_zz_xxxy_0[j] + 2.0 * fl1_fz * ts_zzzz_xxxy_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_zz_xxxy_0[j];

            tt_zzzz_xxxz_0[j] = pa_z[j] * tt_zzz_xxxz_0[j] + 1.5 * fl1_fx * tt_zz_xxxz_0[j] + 0.5 * fl1_fx * tt_zzz_xxx_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xxxz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xxxz_0[j];

            tt_zzzz_xxyy_0[j] = pa_z[j] * tt_zzz_xxyy_0[j] + 1.5 * fl1_fx * tt_zz_xxyy_0[j] + 2.0 * fl1_fz * ts_zzzz_xxyy_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_zz_xxyy_0[j];

            tt_zzzz_xxyz_0[j] = pa_z[j] * tt_zzz_xxyz_0[j] + 1.5 * fl1_fx * tt_zz_xxyz_0[j] + 0.5 * fl1_fx * tt_zzz_xxy_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xxyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xxyz_0[j];

            tt_zzzz_xxzz_0[j] = pa_z[j] * tt_zzz_xxzz_0[j] + 1.5 * fl1_fx * tt_zz_xxzz_0[j] + fl1_fx * tt_zzz_xxz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xxzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xxzz_0[j];

            tt_zzzz_xyyy_0[j] = pa_z[j] * tt_zzz_xyyy_0[j] + 1.5 * fl1_fx * tt_zz_xyyy_0[j] + 2.0 * fl1_fz * ts_zzzz_xyyy_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_zz_xyyy_0[j];

            tt_zzzz_xyyz_0[j] = pa_z[j] * tt_zzz_xyyz_0[j] + 1.5 * fl1_fx * tt_zz_xyyz_0[j] + 0.5 * fl1_fx * tt_zzz_xyy_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xyyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xyyz_0[j];

            tt_zzzz_xyzz_0[j] = pa_z[j] * tt_zzz_xyzz_0[j] + 1.5 * fl1_fx * tt_zz_xyzz_0[j] + fl1_fx * tt_zzz_xyz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xyzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xyzz_0[j];

            tt_zzzz_xzzz_0[j] = pa_z[j] * tt_zzz_xzzz_0[j] + 1.5 * fl1_fx * tt_zz_xzzz_0[j] + 1.5 * fl1_fx * tt_zzz_xzz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_xzzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_xzzz_0[j];

            tt_zzzz_yyyy_0[j] = pa_z[j] * tt_zzz_yyyy_0[j] + 1.5 * fl1_fx * tt_zz_yyyy_0[j] + 2.0 * fl1_fz * ts_zzzz_yyyy_0[j] -
                                3.0 * fl1_fz * fl1_fga * ts_zz_yyyy_0[j];

            tt_zzzz_yyyz_0[j] = pa_z[j] * tt_zzz_yyyz_0[j] + 1.5 * fl1_fx * tt_zz_yyyz_0[j] + 0.5 * fl1_fx * tt_zzz_yyy_0[j] +
                                2.0 * fl1_fz * ts_zzzz_yyyz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_yyyz_0[j];

            tt_zzzz_yyzz_0[j] = pa_z[j] * tt_zzz_yyzz_0[j] + 1.5 * fl1_fx * tt_zz_yyzz_0[j] + fl1_fx * tt_zzz_yyz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_yyzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_yyzz_0[j];

            tt_zzzz_yzzz_0[j] = pa_z[j] * tt_zzz_yzzz_0[j] + 1.5 * fl1_fx * tt_zz_yzzz_0[j] + 1.5 * fl1_fx * tt_zzz_yzz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_yzzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_yzzz_0[j];

            tt_zzzz_zzzz_0[j] = pa_z[j] * tt_zzz_zzzz_0[j] + 1.5 * fl1_fx * tt_zz_zzzz_0[j] + 2.0 * fl1_fx * tt_zzz_zzz_0[j] +
                                2.0 * fl1_fz * ts_zzzz_zzzz_0[j] - 3.0 * fl1_fz * fl1_fga * ts_zz_zzzz_0[j];
        }

        idx++;
    }
}

}  // namespace kinrecfunc
