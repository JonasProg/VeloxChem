//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "OverlapRecFuncForGF.hpp"

namespace ovlrecfunc {  // ovlrecfunc namespace

void
compOverlapForGF(CMemBlock2D<double>&       primBuffer,
                 const CRecursionMap&       recursionMap,
                 const CMemBlock2D<double>& osFactors,
                 const int32_t              nOSFactors,
                 const CMemBlock2D<double>& paDistances,
                 const CGtoBlock&           braGtoBlock,
                 const CGtoBlock&           ketGtoBlock,
                 const int32_t              iContrGto)
{
    ovlrecfunc::compOverlapForGF_0_50(primBuffer, recursionMap, osFactors, nOSFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    ovlrecfunc::compOverlapForGF_50_100(primBuffer, recursionMap, osFactors, nOSFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);

    ovlrecfunc::compOverlapForGF_100_150(primBuffer, recursionMap, osFactors, nOSFactors, paDistances, braGtoBlock, ketGtoBlock, iContrGto);
}

void
compOverlapForGF_0_50(CMemBlock2D<double>&       primBuffer,
                      const CRecursionMap&       recursionMap,
                      const CMemBlock2D<double>& osFactors,
                      const int32_t              nOSFactors,
                      const CMemBlock2D<double>& paDistances,
                      const CGtoBlock&           braGtoBlock,
                      const CGtoBlock&           ketGtoBlock,
                      const int32_t              iContrGto)
{
    // Batch of Integrals (0,50)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_s_4_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_s_4_3_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_s_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_3_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {2, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(nOSFactors * idx);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        // set up pointers to auxilary integrals

        auto ts_xxx_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx);

        auto ts_xxx_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 1);

        auto ts_xxx_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 2);

        auto ts_xxx_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 3);

        auto ts_xxx_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 4);

        auto ts_xxx_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 5);

        auto ts_xxx_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 6);

        auto ts_xxx_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 7);

        auto ts_xxx_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 8);

        auto ts_xxx_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 9);

        auto ts_xxy_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 10);

        auto ts_xxy_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 11);

        auto ts_xxy_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 12);

        auto ts_xxy_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 13);

        auto ts_xxy_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 14);

        auto ts_xxy_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 15);

        auto ts_xxy_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 16);

        auto ts_xxy_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 17);

        auto ts_xxy_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 18);

        auto ts_xxy_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 19);

        auto ts_xxz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 20);

        auto ts_xxz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 21);

        auto ts_xxz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 22);

        auto ts_xxz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 23);

        auto ts_xxz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 24);

        auto ts_xxz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 25);

        auto ts_xxz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 26);

        auto ts_xxz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 27);

        auto ts_xxz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 28);

        auto ts_xxz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 29);

        auto ts_xyy_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 30);

        auto ts_xyy_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 31);

        auto ts_xyy_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 32);

        auto ts_xyy_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 33);

        auto ts_xyy_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 34);

        auto ts_xyy_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 35);

        auto ts_xyy_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 36);

        auto ts_xyy_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 37);

        auto ts_xyy_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 38);

        auto ts_xyy_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 39);

        auto ts_xyz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 40);

        auto ts_xyz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 41);

        auto ts_xyz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 42);

        auto ts_xyz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 43);

        auto ts_xyz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 44);

        auto ts_xyz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 45);

        auto ts_xyz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 46);

        auto ts_xyz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 47);

        auto ts_xyz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 48);

        auto ts_xyz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 49);

        auto ts_xx_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx);

        auto ts_xx_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 1);

        auto ts_xx_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 2);

        auto ts_xx_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 3);

        auto ts_xx_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 4);

        auto ts_xx_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 5);

        auto ts_xx_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 6);

        auto ts_xx_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 7);

        auto ts_xx_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 8);

        auto ts_xx_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 9);

        auto ts_xy_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 10);

        auto ts_xy_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 11);

        auto ts_xy_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 12);

        auto ts_xy_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 13);

        auto ts_xy_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 14);

        auto ts_xy_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 15);

        auto ts_xy_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 16);

        auto ts_xy_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 17);

        auto ts_xy_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 18);

        auto ts_xy_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 19);

        auto ts_xz_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 20);

        auto ts_xz_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 21);

        auto ts_xz_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 22);

        auto ts_xz_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 23);

        auto ts_xz_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 24);

        auto ts_xz_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 25);

        auto ts_xz_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 26);

        auto ts_xz_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 27);

        auto ts_xz_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 28);

        auto ts_xz_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 29);

        auto ts_yy_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 30);

        auto ts_yy_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 31);

        auto ts_yy_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 32);

        auto ts_yy_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 33);

        auto ts_yy_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 34);

        auto ts_yy_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 35);

        auto ts_yy_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 36);

        auto ts_yy_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 37);

        auto ts_yy_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 38);

        auto ts_yy_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 39);

        auto ts_yz_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 40);

        auto ts_yz_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 41);

        auto ts_yz_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 42);

        auto ts_yz_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 43);

        auto ts_yz_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 44);

        auto ts_yz_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 45);

        auto ts_yz_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 46);

        auto ts_yz_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 47);

        auto ts_yz_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 48);

        auto ts_yz_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 49);

        auto ts_xxx_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx);

        auto ts_xxx_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 1);

        auto ts_xxx_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 2);

        auto ts_xxx_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 3);

        auto ts_xxx_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 4);

        auto ts_xxx_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 5);

        auto ts_xxy_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 6);

        auto ts_xxy_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 7);

        auto ts_xxy_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 8);

        auto ts_xxy_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 9);

        auto ts_xxy_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 10);

        auto ts_xxy_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 11);

        auto ts_xxz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 12);

        auto ts_xxz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 13);

        auto ts_xxz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 14);

        auto ts_xxz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 15);

        auto ts_xxz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 16);

        auto ts_xxz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 17);

        auto ts_xyy_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 18);

        auto ts_xyy_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 19);

        auto ts_xyy_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 20);

        auto ts_xyy_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 21);

        auto ts_xyy_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 22);

        auto ts_xyy_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 23);

        auto ts_xyz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 24);

        auto ts_xyz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 25);

        auto ts_xyz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 26);

        auto ts_xyz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 27);

        auto ts_xyz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 28);

        auto ts_xyz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 29);

        // set up pointers to integrals

        auto ts_xxxx_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx);

        auto ts_xxxx_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 1);

        auto ts_xxxx_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 2);

        auto ts_xxxx_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 3);

        auto ts_xxxx_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 4);

        auto ts_xxxx_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 5);

        auto ts_xxxx_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 6);

        auto ts_xxxx_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 7);

        auto ts_xxxx_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 8);

        auto ts_xxxx_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 9);

        auto ts_xxxy_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 10);

        auto ts_xxxy_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 11);

        auto ts_xxxy_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 12);

        auto ts_xxxy_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 13);

        auto ts_xxxy_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 14);

        auto ts_xxxy_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 15);

        auto ts_xxxy_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 16);

        auto ts_xxxy_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 17);

        auto ts_xxxy_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 18);

        auto ts_xxxy_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 19);

        auto ts_xxxz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 20);

        auto ts_xxxz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 21);

        auto ts_xxxz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 22);

        auto ts_xxxz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 23);

        auto ts_xxxz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 24);

        auto ts_xxxz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 25);

        auto ts_xxxz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 26);

        auto ts_xxxz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 27);

        auto ts_xxxz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 28);

        auto ts_xxxz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 29);

        auto ts_xxyy_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 30);

        auto ts_xxyy_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 31);

        auto ts_xxyy_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 32);

        auto ts_xxyy_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 33);

        auto ts_xxyy_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 34);

        auto ts_xxyy_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 35);

        auto ts_xxyy_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 36);

        auto ts_xxyy_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 37);

        auto ts_xxyy_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 38);

        auto ts_xxyy_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 39);

        auto ts_xxyz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 40);

        auto ts_xxyz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 41);

        auto ts_xxyz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 42);

        auto ts_xxyz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 43);

        auto ts_xxyz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 44);

        auto ts_xxyz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 45);

        auto ts_xxyz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 46);

        auto ts_xxyz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 47);

        auto ts_xxyz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 48);

        auto ts_xxyz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 49);

        // Batch of Integrals (0,50)

        #pragma omp simd aligned(fx, pa_x, ts_xx_xxx_0, ts_xx_xxy_0, ts_xx_xxz_0, ts_xx_xyy_0, \
                                     ts_xx_xyz_0, ts_xx_xzz_0, ts_xx_yyy_0, ts_xx_yyz_0, ts_xx_yzz_0, ts_xx_zzz_0, \
                                     ts_xxx_xx_0, ts_xxx_xxx_0, ts_xxx_xxy_0, ts_xxx_xxz_0, ts_xxx_xy_0, ts_xxx_xyy_0, \
                                     ts_xxx_xyz_0, ts_xxx_xz_0, ts_xxx_xzz_0, ts_xxx_yy_0, ts_xxx_yyy_0, ts_xxx_yyz_0, \
                                     ts_xxx_yz_0, ts_xxx_yzz_0, ts_xxx_zz_0, ts_xxx_zzz_0, ts_xxxx_xxx_0, \
                                     ts_xxxx_xxy_0, ts_xxxx_xxz_0, ts_xxxx_xyy_0, ts_xxxx_xyz_0, ts_xxxx_xzz_0, \
                                     ts_xxxx_yyy_0, ts_xxxx_yyz_0, ts_xxxx_yzz_0, ts_xxxx_zzz_0, ts_xxxy_xxx_0, \
                                     ts_xxxy_xxy_0, ts_xxxy_xxz_0, ts_xxxy_xyy_0, ts_xxxy_xyz_0, ts_xxxy_xzz_0, \
                                     ts_xxxy_yyy_0, ts_xxxy_yyz_0, ts_xxxy_yzz_0, ts_xxxy_zzz_0, ts_xxxz_xxx_0, \
                                     ts_xxxz_xxy_0, ts_xxxz_xxz_0, ts_xxxz_xyy_0, ts_xxxz_xyz_0, ts_xxxz_xzz_0, \
                                     ts_xxxz_yyy_0, ts_xxxz_yyz_0, ts_xxxz_yzz_0, ts_xxxz_zzz_0, ts_xxy_xx_0, \
                                     ts_xxy_xxx_0, ts_xxy_xxy_0, ts_xxy_xxz_0, ts_xxy_xy_0, ts_xxy_xyy_0, ts_xxy_xyz_0, \
                                     ts_xxy_xz_0, ts_xxy_xzz_0, ts_xxy_yy_0, ts_xxy_yyy_0, ts_xxy_yyz_0, ts_xxy_yz_0, \
                                     ts_xxy_yzz_0, ts_xxy_zz_0, ts_xxy_zzz_0, ts_xxyy_xxx_0, ts_xxyy_xxy_0, \
                                     ts_xxyy_xxz_0, ts_xxyy_xyy_0, ts_xxyy_xyz_0, ts_xxyy_xzz_0, ts_xxyy_yyy_0, \
                                     ts_xxyy_yyz_0, ts_xxyy_yzz_0, ts_xxyy_zzz_0, ts_xxyz_xxx_0, ts_xxyz_xxy_0, \
                                     ts_xxyz_xxz_0, ts_xxyz_xyy_0, ts_xxyz_xyz_0, ts_xxyz_xzz_0, ts_xxyz_yyy_0, \
                                     ts_xxyz_yyz_0, ts_xxyz_yzz_0, ts_xxyz_zzz_0, ts_xxz_xx_0, ts_xxz_xxx_0, \
                                     ts_xxz_xxy_0, ts_xxz_xxz_0, ts_xxz_xy_0, ts_xxz_xyy_0, ts_xxz_xyz_0, ts_xxz_xz_0, \
                                     ts_xxz_xzz_0, ts_xxz_yy_0, ts_xxz_yyy_0, ts_xxz_yyz_0, ts_xxz_yz_0, ts_xxz_yzz_0, \
                                     ts_xxz_zz_0, ts_xxz_zzz_0, ts_xy_xxx_0, ts_xy_xxy_0, ts_xy_xxz_0, ts_xy_xyy_0, \
                                     ts_xy_xyz_0, ts_xy_xzz_0, ts_xy_yyy_0, ts_xy_yyz_0, ts_xy_yzz_0, ts_xy_zzz_0, \
                                     ts_xyy_xx_0, ts_xyy_xxx_0, ts_xyy_xxy_0, ts_xyy_xxz_0, ts_xyy_xy_0, ts_xyy_xyy_0, \
                                     ts_xyy_xyz_0, ts_xyy_xz_0, ts_xyy_xzz_0, ts_xyy_yy_0, ts_xyy_yyy_0, ts_xyy_yyz_0, \
                                     ts_xyy_yz_0, ts_xyy_yzz_0, ts_xyy_zz_0, ts_xyy_zzz_0, ts_xyz_xx_0, ts_xyz_xxx_0, \
                                     ts_xyz_xxy_0, ts_xyz_xxz_0, ts_xyz_xy_0, ts_xyz_xyy_0, ts_xyz_xyz_0, ts_xyz_xz_0, \
                                     ts_xyz_xzz_0, ts_xyz_yy_0, ts_xyz_yyy_0, ts_xyz_yyz_0, ts_xyz_yz_0, ts_xyz_yzz_0, \
                                     ts_xyz_zz_0, ts_xyz_zzz_0, ts_xz_xxx_0, ts_xz_xxy_0, ts_xz_xxz_0, ts_xz_xyy_0, \
                                     ts_xz_xyz_0, ts_xz_xzz_0, ts_xz_yyy_0, ts_xz_yyz_0, ts_xz_yzz_0, ts_xz_zzz_0, \
                                     ts_yy_xxx_0, ts_yy_xxy_0, ts_yy_xxz_0, ts_yy_xyy_0, ts_yy_xyz_0, ts_yy_xzz_0, \
                                     ts_yy_yyy_0, ts_yy_yyz_0, ts_yy_yzz_0, ts_yy_zzz_0, ts_yz_xxx_0, ts_yz_xxy_0, \
                                     ts_yz_xxz_0, ts_yz_xyy_0, ts_yz_xyz_0, ts_yz_xzz_0, ts_yz_yyy_0, ts_yz_yyz_0, \
                                     ts_yz_yzz_0, ts_yz_zzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fx = fx[j];

            ts_xxxx_xxx_0[j] = pa_x[j] * ts_xxx_xxx_0[j] + 1.5 * fl1_fx * ts_xx_xxx_0[j] + 1.5 * fl1_fx * ts_xxx_xx_0[j];

            ts_xxxx_xxy_0[j] = pa_x[j] * ts_xxx_xxy_0[j] + 1.5 * fl1_fx * ts_xx_xxy_0[j] + fl1_fx * ts_xxx_xy_0[j];

            ts_xxxx_xxz_0[j] = pa_x[j] * ts_xxx_xxz_0[j] + 1.5 * fl1_fx * ts_xx_xxz_0[j] + fl1_fx * ts_xxx_xz_0[j];

            ts_xxxx_xyy_0[j] = pa_x[j] * ts_xxx_xyy_0[j] + 1.5 * fl1_fx * ts_xx_xyy_0[j] + 0.5 * fl1_fx * ts_xxx_yy_0[j];

            ts_xxxx_xyz_0[j] = pa_x[j] * ts_xxx_xyz_0[j] + 1.5 * fl1_fx * ts_xx_xyz_0[j] + 0.5 * fl1_fx * ts_xxx_yz_0[j];

            ts_xxxx_xzz_0[j] = pa_x[j] * ts_xxx_xzz_0[j] + 1.5 * fl1_fx * ts_xx_xzz_0[j] + 0.5 * fl1_fx * ts_xxx_zz_0[j];

            ts_xxxx_yyy_0[j] = pa_x[j] * ts_xxx_yyy_0[j] + 1.5 * fl1_fx * ts_xx_yyy_0[j];

            ts_xxxx_yyz_0[j] = pa_x[j] * ts_xxx_yyz_0[j] + 1.5 * fl1_fx * ts_xx_yyz_0[j];

            ts_xxxx_yzz_0[j] = pa_x[j] * ts_xxx_yzz_0[j] + 1.5 * fl1_fx * ts_xx_yzz_0[j];

            ts_xxxx_zzz_0[j] = pa_x[j] * ts_xxx_zzz_0[j] + 1.5 * fl1_fx * ts_xx_zzz_0[j];

            ts_xxxy_xxx_0[j] = pa_x[j] * ts_xxy_xxx_0[j] + fl1_fx * ts_xy_xxx_0[j] + 1.5 * fl1_fx * ts_xxy_xx_0[j];

            ts_xxxy_xxy_0[j] = pa_x[j] * ts_xxy_xxy_0[j] + fl1_fx * ts_xy_xxy_0[j] + fl1_fx * ts_xxy_xy_0[j];

            ts_xxxy_xxz_0[j] = pa_x[j] * ts_xxy_xxz_0[j] + fl1_fx * ts_xy_xxz_0[j] + fl1_fx * ts_xxy_xz_0[j];

            ts_xxxy_xyy_0[j] = pa_x[j] * ts_xxy_xyy_0[j] + fl1_fx * ts_xy_xyy_0[j] + 0.5 * fl1_fx * ts_xxy_yy_0[j];

            ts_xxxy_xyz_0[j] = pa_x[j] * ts_xxy_xyz_0[j] + fl1_fx * ts_xy_xyz_0[j] + 0.5 * fl1_fx * ts_xxy_yz_0[j];

            ts_xxxy_xzz_0[j] = pa_x[j] * ts_xxy_xzz_0[j] + fl1_fx * ts_xy_xzz_0[j] + 0.5 * fl1_fx * ts_xxy_zz_0[j];

            ts_xxxy_yyy_0[j] = pa_x[j] * ts_xxy_yyy_0[j] + fl1_fx * ts_xy_yyy_0[j];

            ts_xxxy_yyz_0[j] = pa_x[j] * ts_xxy_yyz_0[j] + fl1_fx * ts_xy_yyz_0[j];

            ts_xxxy_yzz_0[j] = pa_x[j] * ts_xxy_yzz_0[j] + fl1_fx * ts_xy_yzz_0[j];

            ts_xxxy_zzz_0[j] = pa_x[j] * ts_xxy_zzz_0[j] + fl1_fx * ts_xy_zzz_0[j];

            ts_xxxz_xxx_0[j] = pa_x[j] * ts_xxz_xxx_0[j] + fl1_fx * ts_xz_xxx_0[j] + 1.5 * fl1_fx * ts_xxz_xx_0[j];

            ts_xxxz_xxy_0[j] = pa_x[j] * ts_xxz_xxy_0[j] + fl1_fx * ts_xz_xxy_0[j] + fl1_fx * ts_xxz_xy_0[j];

            ts_xxxz_xxz_0[j] = pa_x[j] * ts_xxz_xxz_0[j] + fl1_fx * ts_xz_xxz_0[j] + fl1_fx * ts_xxz_xz_0[j];

            ts_xxxz_xyy_0[j] = pa_x[j] * ts_xxz_xyy_0[j] + fl1_fx * ts_xz_xyy_0[j] + 0.5 * fl1_fx * ts_xxz_yy_0[j];

            ts_xxxz_xyz_0[j] = pa_x[j] * ts_xxz_xyz_0[j] + fl1_fx * ts_xz_xyz_0[j] + 0.5 * fl1_fx * ts_xxz_yz_0[j];

            ts_xxxz_xzz_0[j] = pa_x[j] * ts_xxz_xzz_0[j] + fl1_fx * ts_xz_xzz_0[j] + 0.5 * fl1_fx * ts_xxz_zz_0[j];

            ts_xxxz_yyy_0[j] = pa_x[j] * ts_xxz_yyy_0[j] + fl1_fx * ts_xz_yyy_0[j];

            ts_xxxz_yyz_0[j] = pa_x[j] * ts_xxz_yyz_0[j] + fl1_fx * ts_xz_yyz_0[j];

            ts_xxxz_yzz_0[j] = pa_x[j] * ts_xxz_yzz_0[j] + fl1_fx * ts_xz_yzz_0[j];

            ts_xxxz_zzz_0[j] = pa_x[j] * ts_xxz_zzz_0[j] + fl1_fx * ts_xz_zzz_0[j];

            ts_xxyy_xxx_0[j] = pa_x[j] * ts_xyy_xxx_0[j] + 0.5 * fl1_fx * ts_yy_xxx_0[j] + 1.5 * fl1_fx * ts_xyy_xx_0[j];

            ts_xxyy_xxy_0[j] = pa_x[j] * ts_xyy_xxy_0[j] + 0.5 * fl1_fx * ts_yy_xxy_0[j] + fl1_fx * ts_xyy_xy_0[j];

            ts_xxyy_xxz_0[j] = pa_x[j] * ts_xyy_xxz_0[j] + 0.5 * fl1_fx * ts_yy_xxz_0[j] + fl1_fx * ts_xyy_xz_0[j];

            ts_xxyy_xyy_0[j] = pa_x[j] * ts_xyy_xyy_0[j] + 0.5 * fl1_fx * ts_yy_xyy_0[j] + 0.5 * fl1_fx * ts_xyy_yy_0[j];

            ts_xxyy_xyz_0[j] = pa_x[j] * ts_xyy_xyz_0[j] + 0.5 * fl1_fx * ts_yy_xyz_0[j] + 0.5 * fl1_fx * ts_xyy_yz_0[j];

            ts_xxyy_xzz_0[j] = pa_x[j] * ts_xyy_xzz_0[j] + 0.5 * fl1_fx * ts_yy_xzz_0[j] + 0.5 * fl1_fx * ts_xyy_zz_0[j];

            ts_xxyy_yyy_0[j] = pa_x[j] * ts_xyy_yyy_0[j] + 0.5 * fl1_fx * ts_yy_yyy_0[j];

            ts_xxyy_yyz_0[j] = pa_x[j] * ts_xyy_yyz_0[j] + 0.5 * fl1_fx * ts_yy_yyz_0[j];

            ts_xxyy_yzz_0[j] = pa_x[j] * ts_xyy_yzz_0[j] + 0.5 * fl1_fx * ts_yy_yzz_0[j];

            ts_xxyy_zzz_0[j] = pa_x[j] * ts_xyy_zzz_0[j] + 0.5 * fl1_fx * ts_yy_zzz_0[j];

            ts_xxyz_xxx_0[j] = pa_x[j] * ts_xyz_xxx_0[j] + 0.5 * fl1_fx * ts_yz_xxx_0[j] + 1.5 * fl1_fx * ts_xyz_xx_0[j];

            ts_xxyz_xxy_0[j] = pa_x[j] * ts_xyz_xxy_0[j] + 0.5 * fl1_fx * ts_yz_xxy_0[j] + fl1_fx * ts_xyz_xy_0[j];

            ts_xxyz_xxz_0[j] = pa_x[j] * ts_xyz_xxz_0[j] + 0.5 * fl1_fx * ts_yz_xxz_0[j] + fl1_fx * ts_xyz_xz_0[j];

            ts_xxyz_xyy_0[j] = pa_x[j] * ts_xyz_xyy_0[j] + 0.5 * fl1_fx * ts_yz_xyy_0[j] + 0.5 * fl1_fx * ts_xyz_yy_0[j];

            ts_xxyz_xyz_0[j] = pa_x[j] * ts_xyz_xyz_0[j] + 0.5 * fl1_fx * ts_yz_xyz_0[j] + 0.5 * fl1_fx * ts_xyz_yz_0[j];

            ts_xxyz_xzz_0[j] = pa_x[j] * ts_xyz_xzz_0[j] + 0.5 * fl1_fx * ts_yz_xzz_0[j] + 0.5 * fl1_fx * ts_xyz_zz_0[j];

            ts_xxyz_yyy_0[j] = pa_x[j] * ts_xyz_yyy_0[j] + 0.5 * fl1_fx * ts_yz_yyy_0[j];

            ts_xxyz_yyz_0[j] = pa_x[j] * ts_xyz_yyz_0[j] + 0.5 * fl1_fx * ts_yz_yyz_0[j];

            ts_xxyz_yzz_0[j] = pa_x[j] * ts_xyz_yzz_0[j] + 0.5 * fl1_fx * ts_yz_yzz_0[j];

            ts_xxyz_zzz_0[j] = pa_x[j] * ts_xyz_zzz_0[j] + 0.5 * fl1_fx * ts_yz_zzz_0[j];
        }

        idx++;
    }
}

void
compOverlapForGF_50_100(CMemBlock2D<double>&       primBuffer,
                        const CRecursionMap&       recursionMap,
                        const CMemBlock2D<double>& osFactors,
                        const int32_t              nOSFactors,
                        const CMemBlock2D<double>& paDistances,
                        const CGtoBlock&           braGtoBlock,
                        const CGtoBlock&           ketGtoBlock,
                        const int32_t              iContrGto)
{
    // Batch of Integrals (50,100)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_s_4_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_s_4_3_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_s_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_3_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {2, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(nOSFactors * idx);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_x = paDistances.data(3 * idx);

        // set up pointers to auxilary integrals

        auto ts_xzz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 50);

        auto ts_xzz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 51);

        auto ts_xzz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 52);

        auto ts_xzz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 53);

        auto ts_xzz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 54);

        auto ts_xzz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 55);

        auto ts_xzz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 56);

        auto ts_xzz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 57);

        auto ts_xzz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 58);

        auto ts_xzz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 59);

        auto ts_yyy_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 60);

        auto ts_yyy_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 61);

        auto ts_yyy_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 62);

        auto ts_yyy_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 63);

        auto ts_yyy_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 64);

        auto ts_yyy_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 65);

        auto ts_yyy_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 66);

        auto ts_yyy_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 67);

        auto ts_yyy_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 68);

        auto ts_yyy_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 69);

        auto ts_yyz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 70);

        auto ts_yyz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 71);

        auto ts_yyz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 72);

        auto ts_yyz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 73);

        auto ts_yyz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 74);

        auto ts_yyz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 75);

        auto ts_yyz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 76);

        auto ts_yyz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 77);

        auto ts_yyz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 78);

        auto ts_yyz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 79);

        auto ts_yzz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 80);

        auto ts_yzz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 81);

        auto ts_yzz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 82);

        auto ts_yzz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 83);

        auto ts_yzz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 84);

        auto ts_yzz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 85);

        auto ts_yzz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 86);

        auto ts_yzz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 87);

        auto ts_yzz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 88);

        auto ts_yzz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 89);

        auto ts_zzz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 90);

        auto ts_zzz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 91);

        auto ts_zzz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 92);

        auto ts_zzz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 93);

        auto ts_zzz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 94);

        auto ts_zzz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 95);

        auto ts_zzz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 96);

        auto ts_zzz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 97);

        auto ts_zzz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 98);

        auto ts_zzz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 99);

        auto ts_zz_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 50);

        auto ts_zz_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 51);

        auto ts_zz_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 52);

        auto ts_zz_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 53);

        auto ts_zz_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 54);

        auto ts_zz_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 55);

        auto ts_zz_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 56);

        auto ts_zz_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 57);

        auto ts_zz_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 58);

        auto ts_zz_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 59);

        auto ts_xzz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 30);

        auto ts_xzz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 31);

        auto ts_xzz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 32);

        auto ts_xzz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 33);

        auto ts_xzz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 34);

        auto ts_xzz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 35);

        auto ts_yyy_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 36);

        auto ts_yyy_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 37);

        auto ts_yyy_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 38);

        auto ts_yyy_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 39);

        auto ts_yyy_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 40);

        auto ts_yyy_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 41);

        auto ts_yyz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 42);

        auto ts_yyz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 43);

        auto ts_yyz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 44);

        auto ts_yyz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 45);

        auto ts_yyz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 46);

        auto ts_yyz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 47);

        auto ts_yzz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 48);

        auto ts_yzz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 49);

        auto ts_yzz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 50);

        auto ts_yzz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 51);

        auto ts_yzz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 52);

        auto ts_yzz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 53);

        auto ts_zzz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 54);

        auto ts_zzz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 55);

        auto ts_zzz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 56);

        auto ts_zzz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 57);

        auto ts_zzz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 58);

        auto ts_zzz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 59);

        // set up pointers to integrals

        auto ts_xxzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 50);

        auto ts_xxzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 51);

        auto ts_xxzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 52);

        auto ts_xxzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 53);

        auto ts_xxzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 54);

        auto ts_xxzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 55);

        auto ts_xxzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 56);

        auto ts_xxzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 57);

        auto ts_xxzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 58);

        auto ts_xxzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 59);

        auto ts_xyyy_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 60);

        auto ts_xyyy_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 61);

        auto ts_xyyy_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 62);

        auto ts_xyyy_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 63);

        auto ts_xyyy_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 64);

        auto ts_xyyy_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 65);

        auto ts_xyyy_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 66);

        auto ts_xyyy_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 67);

        auto ts_xyyy_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 68);

        auto ts_xyyy_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 69);

        auto ts_xyyz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 70);

        auto ts_xyyz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 71);

        auto ts_xyyz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 72);

        auto ts_xyyz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 73);

        auto ts_xyyz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 74);

        auto ts_xyyz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 75);

        auto ts_xyyz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 76);

        auto ts_xyyz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 77);

        auto ts_xyyz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 78);

        auto ts_xyyz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 79);

        auto ts_xyzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 80);

        auto ts_xyzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 81);

        auto ts_xyzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 82);

        auto ts_xyzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 83);

        auto ts_xyzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 84);

        auto ts_xyzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 85);

        auto ts_xyzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 86);

        auto ts_xyzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 87);

        auto ts_xyzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 88);

        auto ts_xyzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 89);

        auto ts_xzzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 90);

        auto ts_xzzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 91);

        auto ts_xzzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 92);

        auto ts_xzzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 93);

        auto ts_xzzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 94);

        auto ts_xzzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 95);

        auto ts_xzzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 96);

        auto ts_xzzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 97);

        auto ts_xzzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 98);

        auto ts_xzzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 99);

        // Batch of Integrals (50,100)

        #pragma omp simd aligned(fx, pa_x, ts_xxzz_xxx_0, ts_xxzz_xxy_0, ts_xxzz_xxz_0, ts_xxzz_xyy_0, \
                                     ts_xxzz_xyz_0, ts_xxzz_xzz_0, ts_xxzz_yyy_0, ts_xxzz_yyz_0, ts_xxzz_yzz_0, \
                                     ts_xxzz_zzz_0, ts_xyyy_xxx_0, ts_xyyy_xxy_0, ts_xyyy_xxz_0, ts_xyyy_xyy_0, \
                                     ts_xyyy_xyz_0, ts_xyyy_xzz_0, ts_xyyy_yyy_0, ts_xyyy_yyz_0, ts_xyyy_yzz_0, \
                                     ts_xyyy_zzz_0, ts_xyyz_xxx_0, ts_xyyz_xxy_0, ts_xyyz_xxz_0, ts_xyyz_xyy_0, \
                                     ts_xyyz_xyz_0, ts_xyyz_xzz_0, ts_xyyz_yyy_0, ts_xyyz_yyz_0, ts_xyyz_yzz_0, \
                                     ts_xyyz_zzz_0, ts_xyzz_xxx_0, ts_xyzz_xxy_0, ts_xyzz_xxz_0, ts_xyzz_xyy_0, \
                                     ts_xyzz_xyz_0, ts_xyzz_xzz_0, ts_xyzz_yyy_0, ts_xyzz_yyz_0, ts_xyzz_yzz_0, \
                                     ts_xyzz_zzz_0, ts_xzz_xx_0, ts_xzz_xxx_0, ts_xzz_xxy_0, ts_xzz_xxz_0, ts_xzz_xy_0, \
                                     ts_xzz_xyy_0, ts_xzz_xyz_0, ts_xzz_xz_0, ts_xzz_xzz_0, ts_xzz_yy_0, ts_xzz_yyy_0, \
                                     ts_xzz_yyz_0, ts_xzz_yz_0, ts_xzz_yzz_0, ts_xzz_zz_0, ts_xzz_zzz_0, ts_xzzz_xxx_0, \
                                     ts_xzzz_xxy_0, ts_xzzz_xxz_0, ts_xzzz_xyy_0, ts_xzzz_xyz_0, ts_xzzz_xzz_0, \
                                     ts_xzzz_yyy_0, ts_xzzz_yyz_0, ts_xzzz_yzz_0, ts_xzzz_zzz_0, ts_yyy_xx_0, \
                                     ts_yyy_xxx_0, ts_yyy_xxy_0, ts_yyy_xxz_0, ts_yyy_xy_0, ts_yyy_xyy_0, ts_yyy_xyz_0, \
                                     ts_yyy_xz_0, ts_yyy_xzz_0, ts_yyy_yy_0, ts_yyy_yyy_0, ts_yyy_yyz_0, ts_yyy_yz_0, \
                                     ts_yyy_yzz_0, ts_yyy_zz_0, ts_yyy_zzz_0, ts_yyz_xx_0, ts_yyz_xxx_0, ts_yyz_xxy_0, \
                                     ts_yyz_xxz_0, ts_yyz_xy_0, ts_yyz_xyy_0, ts_yyz_xyz_0, ts_yyz_xz_0, ts_yyz_xzz_0, \
                                     ts_yyz_yy_0, ts_yyz_yyy_0, ts_yyz_yyz_0, ts_yyz_yz_0, ts_yyz_yzz_0, ts_yyz_zz_0, \
                                     ts_yyz_zzz_0, ts_yzz_xx_0, ts_yzz_xxx_0, ts_yzz_xxy_0, ts_yzz_xxz_0, ts_yzz_xy_0, \
                                     ts_yzz_xyy_0, ts_yzz_xyz_0, ts_yzz_xz_0, ts_yzz_xzz_0, ts_yzz_yy_0, ts_yzz_yyy_0, \
                                     ts_yzz_yyz_0, ts_yzz_yz_0, ts_yzz_yzz_0, ts_yzz_zz_0, ts_yzz_zzz_0, ts_zz_xxx_0, \
                                     ts_zz_xxy_0, ts_zz_xxz_0, ts_zz_xyy_0, ts_zz_xyz_0, ts_zz_xzz_0, ts_zz_yyy_0, \
                                     ts_zz_yyz_0, ts_zz_yzz_0, ts_zz_zzz_0, ts_zzz_xx_0, ts_zzz_xxx_0, ts_zzz_xxy_0, \
                                     ts_zzz_xxz_0, ts_zzz_xy_0, ts_zzz_xyy_0, ts_zzz_xyz_0, ts_zzz_xz_0, ts_zzz_xzz_0, \
                                     ts_zzz_yy_0, ts_zzz_yyy_0, ts_zzz_yyz_0, ts_zzz_yz_0, ts_zzz_yzz_0, ts_zzz_zz_0, \
                                     ts_zzz_zzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fx = fx[j];

            ts_xxzz_xxx_0[j] = pa_x[j] * ts_xzz_xxx_0[j] + 0.5 * fl1_fx * ts_zz_xxx_0[j] + 1.5 * fl1_fx * ts_xzz_xx_0[j];

            ts_xxzz_xxy_0[j] = pa_x[j] * ts_xzz_xxy_0[j] + 0.5 * fl1_fx * ts_zz_xxy_0[j] + fl1_fx * ts_xzz_xy_0[j];

            ts_xxzz_xxz_0[j] = pa_x[j] * ts_xzz_xxz_0[j] + 0.5 * fl1_fx * ts_zz_xxz_0[j] + fl1_fx * ts_xzz_xz_0[j];

            ts_xxzz_xyy_0[j] = pa_x[j] * ts_xzz_xyy_0[j] + 0.5 * fl1_fx * ts_zz_xyy_0[j] + 0.5 * fl1_fx * ts_xzz_yy_0[j];

            ts_xxzz_xyz_0[j] = pa_x[j] * ts_xzz_xyz_0[j] + 0.5 * fl1_fx * ts_zz_xyz_0[j] + 0.5 * fl1_fx * ts_xzz_yz_0[j];

            ts_xxzz_xzz_0[j] = pa_x[j] * ts_xzz_xzz_0[j] + 0.5 * fl1_fx * ts_zz_xzz_0[j] + 0.5 * fl1_fx * ts_xzz_zz_0[j];

            ts_xxzz_yyy_0[j] = pa_x[j] * ts_xzz_yyy_0[j] + 0.5 * fl1_fx * ts_zz_yyy_0[j];

            ts_xxzz_yyz_0[j] = pa_x[j] * ts_xzz_yyz_0[j] + 0.5 * fl1_fx * ts_zz_yyz_0[j];

            ts_xxzz_yzz_0[j] = pa_x[j] * ts_xzz_yzz_0[j] + 0.5 * fl1_fx * ts_zz_yzz_0[j];

            ts_xxzz_zzz_0[j] = pa_x[j] * ts_xzz_zzz_0[j] + 0.5 * fl1_fx * ts_zz_zzz_0[j];

            ts_xyyy_xxx_0[j] = pa_x[j] * ts_yyy_xxx_0[j] + 1.5 * fl1_fx * ts_yyy_xx_0[j];

            ts_xyyy_xxy_0[j] = pa_x[j] * ts_yyy_xxy_0[j] + fl1_fx * ts_yyy_xy_0[j];

            ts_xyyy_xxz_0[j] = pa_x[j] * ts_yyy_xxz_0[j] + fl1_fx * ts_yyy_xz_0[j];

            ts_xyyy_xyy_0[j] = pa_x[j] * ts_yyy_xyy_0[j] + 0.5 * fl1_fx * ts_yyy_yy_0[j];

            ts_xyyy_xyz_0[j] = pa_x[j] * ts_yyy_xyz_0[j] + 0.5 * fl1_fx * ts_yyy_yz_0[j];

            ts_xyyy_xzz_0[j] = pa_x[j] * ts_yyy_xzz_0[j] + 0.5 * fl1_fx * ts_yyy_zz_0[j];

            ts_xyyy_yyy_0[j] = pa_x[j] * ts_yyy_yyy_0[j];

            ts_xyyy_yyz_0[j] = pa_x[j] * ts_yyy_yyz_0[j];

            ts_xyyy_yzz_0[j] = pa_x[j] * ts_yyy_yzz_0[j];

            ts_xyyy_zzz_0[j] = pa_x[j] * ts_yyy_zzz_0[j];

            ts_xyyz_xxx_0[j] = pa_x[j] * ts_yyz_xxx_0[j] + 1.5 * fl1_fx * ts_yyz_xx_0[j];

            ts_xyyz_xxy_0[j] = pa_x[j] * ts_yyz_xxy_0[j] + fl1_fx * ts_yyz_xy_0[j];

            ts_xyyz_xxz_0[j] = pa_x[j] * ts_yyz_xxz_0[j] + fl1_fx * ts_yyz_xz_0[j];

            ts_xyyz_xyy_0[j] = pa_x[j] * ts_yyz_xyy_0[j] + 0.5 * fl1_fx * ts_yyz_yy_0[j];

            ts_xyyz_xyz_0[j] = pa_x[j] * ts_yyz_xyz_0[j] + 0.5 * fl1_fx * ts_yyz_yz_0[j];

            ts_xyyz_xzz_0[j] = pa_x[j] * ts_yyz_xzz_0[j] + 0.5 * fl1_fx * ts_yyz_zz_0[j];

            ts_xyyz_yyy_0[j] = pa_x[j] * ts_yyz_yyy_0[j];

            ts_xyyz_yyz_0[j] = pa_x[j] * ts_yyz_yyz_0[j];

            ts_xyyz_yzz_0[j] = pa_x[j] * ts_yyz_yzz_0[j];

            ts_xyyz_zzz_0[j] = pa_x[j] * ts_yyz_zzz_0[j];

            ts_xyzz_xxx_0[j] = pa_x[j] * ts_yzz_xxx_0[j] + 1.5 * fl1_fx * ts_yzz_xx_0[j];

            ts_xyzz_xxy_0[j] = pa_x[j] * ts_yzz_xxy_0[j] + fl1_fx * ts_yzz_xy_0[j];

            ts_xyzz_xxz_0[j] = pa_x[j] * ts_yzz_xxz_0[j] + fl1_fx * ts_yzz_xz_0[j];

            ts_xyzz_xyy_0[j] = pa_x[j] * ts_yzz_xyy_0[j] + 0.5 * fl1_fx * ts_yzz_yy_0[j];

            ts_xyzz_xyz_0[j] = pa_x[j] * ts_yzz_xyz_0[j] + 0.5 * fl1_fx * ts_yzz_yz_0[j];

            ts_xyzz_xzz_0[j] = pa_x[j] * ts_yzz_xzz_0[j] + 0.5 * fl1_fx * ts_yzz_zz_0[j];

            ts_xyzz_yyy_0[j] = pa_x[j] * ts_yzz_yyy_0[j];

            ts_xyzz_yyz_0[j] = pa_x[j] * ts_yzz_yyz_0[j];

            ts_xyzz_yzz_0[j] = pa_x[j] * ts_yzz_yzz_0[j];

            ts_xyzz_zzz_0[j] = pa_x[j] * ts_yzz_zzz_0[j];

            ts_xzzz_xxx_0[j] = pa_x[j] * ts_zzz_xxx_0[j] + 1.5 * fl1_fx * ts_zzz_xx_0[j];

            ts_xzzz_xxy_0[j] = pa_x[j] * ts_zzz_xxy_0[j] + fl1_fx * ts_zzz_xy_0[j];

            ts_xzzz_xxz_0[j] = pa_x[j] * ts_zzz_xxz_0[j] + fl1_fx * ts_zzz_xz_0[j];

            ts_xzzz_xyy_0[j] = pa_x[j] * ts_zzz_xyy_0[j] + 0.5 * fl1_fx * ts_zzz_yy_0[j];

            ts_xzzz_xyz_0[j] = pa_x[j] * ts_zzz_xyz_0[j] + 0.5 * fl1_fx * ts_zzz_yz_0[j];

            ts_xzzz_xzz_0[j] = pa_x[j] * ts_zzz_xzz_0[j] + 0.5 * fl1_fx * ts_zzz_zz_0[j];

            ts_xzzz_yyy_0[j] = pa_x[j] * ts_zzz_yyy_0[j];

            ts_xzzz_yyz_0[j] = pa_x[j] * ts_zzz_yyz_0[j];

            ts_xzzz_yzz_0[j] = pa_x[j] * ts_zzz_yzz_0[j];

            ts_xzzz_zzz_0[j] = pa_x[j] * ts_zzz_zzz_0[j];
        }

        idx++;
    }
}

void
compOverlapForGF_100_150(CMemBlock2D<double>&       primBuffer,
                         const CRecursionMap&       recursionMap,
                         const CMemBlock2D<double>& osFactors,
                         const int32_t              nOSFactors,
                         const CMemBlock2D<double>& paDistances,
                         const CGtoBlock&           braGtoBlock,
                         const CGtoBlock&           ketGtoBlock,
                         const int32_t              iContrGto)
{
    // Batch of Integrals (100,150)

    // set up pointers to primitives data on bra side

    auto spos = braGtoBlock.getStartPositions();

    auto epos = braGtoBlock.getEndPositions();

    // set up pointers to primitives data on ket side

    auto nprim = ketGtoBlock.getNumberOfPrimGtos();

    // set up index of integral

    auto pidx_s_4_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {4, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    // check if integral is needed in recursion expansion

    if (pidx_s_4_3_m0 == -1) return;

    // set up indexes of auxilary integral

    auto pidx_s_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {2, -1, -1, -1}, {3, -1, -1, -1}, 1, 1, 0));

    auto pidx_s_3_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Overlap"}, 0, true, {3, -1, -1, -1}, {2, -1, -1, -1}, 1, 1, 0));

    // loop over contracted GTO on bra side

    int32_t idx = 0;

    for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
    {
        // set up pointers to Obara-Saika factors

        auto fx = osFactors.data(nOSFactors * idx);

        // set up pointers to tensors product of distances R(PA) = P - A

        auto pa_y = paDistances.data(3 * idx + 1);

        auto pa_z = paDistances.data(3 * idx + 2);

        // set up pointers to auxilary integrals

        auto ts_yyy_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 60);

        auto ts_yyy_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 61);

        auto ts_yyy_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 62);

        auto ts_yyy_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 63);

        auto ts_yyy_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 64);

        auto ts_yyy_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 65);

        auto ts_yyy_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 66);

        auto ts_yyy_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 67);

        auto ts_yyy_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 68);

        auto ts_yyy_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 69);

        auto ts_yyz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 70);

        auto ts_yyz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 71);

        auto ts_yyz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 72);

        auto ts_yyz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 73);

        auto ts_yyz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 74);

        auto ts_yyz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 75);

        auto ts_yyz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 76);

        auto ts_yyz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 77);

        auto ts_yyz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 78);

        auto ts_yyz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 79);

        auto ts_yzz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 80);

        auto ts_yzz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 81);

        auto ts_yzz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 82);

        auto ts_yzz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 83);

        auto ts_yzz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 84);

        auto ts_yzz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 85);

        auto ts_yzz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 86);

        auto ts_yzz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 87);

        auto ts_yzz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 88);

        auto ts_yzz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 89);

        auto ts_zzz_xxx_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 90);

        auto ts_zzz_xxy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 91);

        auto ts_zzz_xxz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 92);

        auto ts_zzz_xyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 93);

        auto ts_zzz_xyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 94);

        auto ts_zzz_xzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 95);

        auto ts_zzz_yyy_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 96);

        auto ts_zzz_yyz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 97);

        auto ts_zzz_yzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 98);

        auto ts_zzz_zzz_0 = primBuffer.data(pidx_s_3_3_m0 + 100 * idx + 99);

        auto ts_yy_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 30);

        auto ts_yy_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 31);

        auto ts_yy_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 32);

        auto ts_yy_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 33);

        auto ts_yy_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 34);

        auto ts_yy_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 35);

        auto ts_yy_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 36);

        auto ts_yy_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 37);

        auto ts_yy_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 38);

        auto ts_yy_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 39);

        auto ts_yz_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 40);

        auto ts_yz_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 41);

        auto ts_yz_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 42);

        auto ts_yz_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 43);

        auto ts_yz_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 44);

        auto ts_yz_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 45);

        auto ts_yz_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 46);

        auto ts_yz_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 47);

        auto ts_yz_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 48);

        auto ts_yz_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 49);

        auto ts_zz_xxx_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 50);

        auto ts_zz_xxy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 51);

        auto ts_zz_xxz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 52);

        auto ts_zz_xyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 53);

        auto ts_zz_xyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 54);

        auto ts_zz_xzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 55);

        auto ts_zz_yyy_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 56);

        auto ts_zz_yyz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 57);

        auto ts_zz_yzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 58);

        auto ts_zz_zzz_0 = primBuffer.data(pidx_s_2_3_m0 + 60 * idx + 59);

        auto ts_yyy_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 36);

        auto ts_yyy_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 37);

        auto ts_yyy_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 38);

        auto ts_yyy_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 39);

        auto ts_yyy_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 40);

        auto ts_yyy_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 41);

        auto ts_yyz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 42);

        auto ts_yyz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 43);

        auto ts_yyz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 44);

        auto ts_yyz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 45);

        auto ts_yyz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 46);

        auto ts_yyz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 47);

        auto ts_yzz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 48);

        auto ts_yzz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 49);

        auto ts_yzz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 50);

        auto ts_yzz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 51);

        auto ts_yzz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 52);

        auto ts_yzz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 53);

        auto ts_zzz_xx_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 54);

        auto ts_zzz_xy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 55);

        auto ts_zzz_xz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 56);

        auto ts_zzz_yy_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 57);

        auto ts_zzz_yz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 58);

        auto ts_zzz_zz_0 = primBuffer.data(pidx_s_3_2_m0 + 60 * idx + 59);

        // set up pointers to integrals

        auto ts_yyyy_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 100);

        auto ts_yyyy_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 101);

        auto ts_yyyy_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 102);

        auto ts_yyyy_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 103);

        auto ts_yyyy_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 104);

        auto ts_yyyy_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 105);

        auto ts_yyyy_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 106);

        auto ts_yyyy_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 107);

        auto ts_yyyy_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 108);

        auto ts_yyyy_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 109);

        auto ts_yyyz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 110);

        auto ts_yyyz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 111);

        auto ts_yyyz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 112);

        auto ts_yyyz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 113);

        auto ts_yyyz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 114);

        auto ts_yyyz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 115);

        auto ts_yyyz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 116);

        auto ts_yyyz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 117);

        auto ts_yyyz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 118);

        auto ts_yyyz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 119);

        auto ts_yyzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 120);

        auto ts_yyzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 121);

        auto ts_yyzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 122);

        auto ts_yyzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 123);

        auto ts_yyzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 124);

        auto ts_yyzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 125);

        auto ts_yyzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 126);

        auto ts_yyzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 127);

        auto ts_yyzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 128);

        auto ts_yyzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 129);

        auto ts_yzzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 130);

        auto ts_yzzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 131);

        auto ts_yzzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 132);

        auto ts_yzzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 133);

        auto ts_yzzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 134);

        auto ts_yzzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 135);

        auto ts_yzzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 136);

        auto ts_yzzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 137);

        auto ts_yzzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 138);

        auto ts_yzzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 139);

        auto ts_zzzz_xxx_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 140);

        auto ts_zzzz_xxy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 141);

        auto ts_zzzz_xxz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 142);

        auto ts_zzzz_xyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 143);

        auto ts_zzzz_xyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 144);

        auto ts_zzzz_xzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 145);

        auto ts_zzzz_yyy_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 146);

        auto ts_zzzz_yyz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 147);

        auto ts_zzzz_yzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 148);

        auto ts_zzzz_zzz_0 = primBuffer.data(pidx_s_4_3_m0 + 150 * idx + 149);

        // Batch of Integrals (100,150)

        #pragma omp simd aligned(fx, pa_y, pa_z, ts_yy_xxx_0, ts_yy_xxy_0, ts_yy_xxz_0, ts_yy_xyy_0, \
                                     ts_yy_xyz_0, ts_yy_xzz_0, ts_yy_yyy_0, ts_yy_yyz_0, ts_yy_yzz_0, ts_yy_zzz_0, \
                                     ts_yyy_xx_0, ts_yyy_xxx_0, ts_yyy_xxy_0, ts_yyy_xxz_0, ts_yyy_xy_0, ts_yyy_xyy_0, \
                                     ts_yyy_xyz_0, ts_yyy_xz_0, ts_yyy_xzz_0, ts_yyy_yy_0, ts_yyy_yyy_0, ts_yyy_yyz_0, \
                                     ts_yyy_yz_0, ts_yyy_yzz_0, ts_yyy_zz_0, ts_yyy_zzz_0, ts_yyyy_xxx_0, \
                                     ts_yyyy_xxy_0, ts_yyyy_xxz_0, ts_yyyy_xyy_0, ts_yyyy_xyz_0, ts_yyyy_xzz_0, \
                                     ts_yyyy_yyy_0, ts_yyyy_yyz_0, ts_yyyy_yzz_0, ts_yyyy_zzz_0, ts_yyyz_xxx_0, \
                                     ts_yyyz_xxy_0, ts_yyyz_xxz_0, ts_yyyz_xyy_0, ts_yyyz_xyz_0, ts_yyyz_xzz_0, \
                                     ts_yyyz_yyy_0, ts_yyyz_yyz_0, ts_yyyz_yzz_0, ts_yyyz_zzz_0, ts_yyz_xx_0, \
                                     ts_yyz_xxx_0, ts_yyz_xxy_0, ts_yyz_xxz_0, ts_yyz_xy_0, ts_yyz_xyy_0, ts_yyz_xyz_0, \
                                     ts_yyz_xz_0, ts_yyz_xzz_0, ts_yyz_yy_0, ts_yyz_yyy_0, ts_yyz_yyz_0, ts_yyz_yz_0, \
                                     ts_yyz_yzz_0, ts_yyz_zz_0, ts_yyz_zzz_0, ts_yyzz_xxx_0, ts_yyzz_xxy_0, \
                                     ts_yyzz_xxz_0, ts_yyzz_xyy_0, ts_yyzz_xyz_0, ts_yyzz_xzz_0, ts_yyzz_yyy_0, \
                                     ts_yyzz_yyz_0, ts_yyzz_yzz_0, ts_yyzz_zzz_0, ts_yz_xxx_0, ts_yz_xxy_0, ts_yz_xxz_0, \
                                     ts_yz_xyy_0, ts_yz_xyz_0, ts_yz_xzz_0, ts_yz_yyy_0, ts_yz_yyz_0, ts_yz_yzz_0, \
                                     ts_yz_zzz_0, ts_yzz_xx_0, ts_yzz_xxx_0, ts_yzz_xxy_0, ts_yzz_xxz_0, ts_yzz_xy_0, \
                                     ts_yzz_xyy_0, ts_yzz_xyz_0, ts_yzz_xz_0, ts_yzz_xzz_0, ts_yzz_yy_0, ts_yzz_yyy_0, \
                                     ts_yzz_yyz_0, ts_yzz_yz_0, ts_yzz_yzz_0, ts_yzz_zz_0, ts_yzz_zzz_0, ts_yzzz_xxx_0, \
                                     ts_yzzz_xxy_0, ts_yzzz_xxz_0, ts_yzzz_xyy_0, ts_yzzz_xyz_0, ts_yzzz_xzz_0, \
                                     ts_yzzz_yyy_0, ts_yzzz_yyz_0, ts_yzzz_yzz_0, ts_yzzz_zzz_0, ts_zz_xxx_0, \
                                     ts_zz_xxy_0, ts_zz_xxz_0, ts_zz_xyy_0, ts_zz_xyz_0, ts_zz_xzz_0, ts_zz_yyy_0, \
                                     ts_zz_yyz_0, ts_zz_yzz_0, ts_zz_zzz_0, ts_zzz_xx_0, ts_zzz_xxx_0, ts_zzz_xxy_0, \
                                     ts_zzz_xxz_0, ts_zzz_xy_0, ts_zzz_xyy_0, ts_zzz_xyz_0, ts_zzz_xz_0, ts_zzz_xzz_0, \
                                     ts_zzz_yy_0, ts_zzz_yyy_0, ts_zzz_yyz_0, ts_zzz_yz_0, ts_zzz_yzz_0, ts_zzz_zz_0, \
                                     ts_zzz_zzz_0, ts_zzzz_xxx_0, ts_zzzz_xxy_0, ts_zzzz_xxz_0, ts_zzzz_xyy_0, \
                                     ts_zzzz_xyz_0, ts_zzzz_xzz_0, ts_zzzz_yyy_0, ts_zzzz_yyz_0, ts_zzzz_yzz_0, \
                                     ts_zzzz_zzz_0: VLX_ALIGN)
        for (int32_t j = 0; j < nprim; j++)
        {
            double fl1_fx = fx[j];

            ts_yyyy_xxx_0[j] = pa_y[j] * ts_yyy_xxx_0[j] + 1.5 * fl1_fx * ts_yy_xxx_0[j];

            ts_yyyy_xxy_0[j] = pa_y[j] * ts_yyy_xxy_0[j] + 1.5 * fl1_fx * ts_yy_xxy_0[j] + 0.5 * fl1_fx * ts_yyy_xx_0[j];

            ts_yyyy_xxz_0[j] = pa_y[j] * ts_yyy_xxz_0[j] + 1.5 * fl1_fx * ts_yy_xxz_0[j];

            ts_yyyy_xyy_0[j] = pa_y[j] * ts_yyy_xyy_0[j] + 1.5 * fl1_fx * ts_yy_xyy_0[j] + fl1_fx * ts_yyy_xy_0[j];

            ts_yyyy_xyz_0[j] = pa_y[j] * ts_yyy_xyz_0[j] + 1.5 * fl1_fx * ts_yy_xyz_0[j] + 0.5 * fl1_fx * ts_yyy_xz_0[j];

            ts_yyyy_xzz_0[j] = pa_y[j] * ts_yyy_xzz_0[j] + 1.5 * fl1_fx * ts_yy_xzz_0[j];

            ts_yyyy_yyy_0[j] = pa_y[j] * ts_yyy_yyy_0[j] + 1.5 * fl1_fx * ts_yy_yyy_0[j] + 1.5 * fl1_fx * ts_yyy_yy_0[j];

            ts_yyyy_yyz_0[j] = pa_y[j] * ts_yyy_yyz_0[j] + 1.5 * fl1_fx * ts_yy_yyz_0[j] + fl1_fx * ts_yyy_yz_0[j];

            ts_yyyy_yzz_0[j] = pa_y[j] * ts_yyy_yzz_0[j] + 1.5 * fl1_fx * ts_yy_yzz_0[j] + 0.5 * fl1_fx * ts_yyy_zz_0[j];

            ts_yyyy_zzz_0[j] = pa_y[j] * ts_yyy_zzz_0[j] + 1.5 * fl1_fx * ts_yy_zzz_0[j];

            ts_yyyz_xxx_0[j] = pa_y[j] * ts_yyz_xxx_0[j] + fl1_fx * ts_yz_xxx_0[j];

            ts_yyyz_xxy_0[j] = pa_y[j] * ts_yyz_xxy_0[j] + fl1_fx * ts_yz_xxy_0[j] + 0.5 * fl1_fx * ts_yyz_xx_0[j];

            ts_yyyz_xxz_0[j] = pa_y[j] * ts_yyz_xxz_0[j] + fl1_fx * ts_yz_xxz_0[j];

            ts_yyyz_xyy_0[j] = pa_y[j] * ts_yyz_xyy_0[j] + fl1_fx * ts_yz_xyy_0[j] + fl1_fx * ts_yyz_xy_0[j];

            ts_yyyz_xyz_0[j] = pa_y[j] * ts_yyz_xyz_0[j] + fl1_fx * ts_yz_xyz_0[j] + 0.5 * fl1_fx * ts_yyz_xz_0[j];

            ts_yyyz_xzz_0[j] = pa_y[j] * ts_yyz_xzz_0[j] + fl1_fx * ts_yz_xzz_0[j];

            ts_yyyz_yyy_0[j] = pa_y[j] * ts_yyz_yyy_0[j] + fl1_fx * ts_yz_yyy_0[j] + 1.5 * fl1_fx * ts_yyz_yy_0[j];

            ts_yyyz_yyz_0[j] = pa_y[j] * ts_yyz_yyz_0[j] + fl1_fx * ts_yz_yyz_0[j] + fl1_fx * ts_yyz_yz_0[j];

            ts_yyyz_yzz_0[j] = pa_y[j] * ts_yyz_yzz_0[j] + fl1_fx * ts_yz_yzz_0[j] + 0.5 * fl1_fx * ts_yyz_zz_0[j];

            ts_yyyz_zzz_0[j] = pa_y[j] * ts_yyz_zzz_0[j] + fl1_fx * ts_yz_zzz_0[j];

            ts_yyzz_xxx_0[j] = pa_y[j] * ts_yzz_xxx_0[j] + 0.5 * fl1_fx * ts_zz_xxx_0[j];

            ts_yyzz_xxy_0[j] = pa_y[j] * ts_yzz_xxy_0[j] + 0.5 * fl1_fx * ts_zz_xxy_0[j] + 0.5 * fl1_fx * ts_yzz_xx_0[j];

            ts_yyzz_xxz_0[j] = pa_y[j] * ts_yzz_xxz_0[j] + 0.5 * fl1_fx * ts_zz_xxz_0[j];

            ts_yyzz_xyy_0[j] = pa_y[j] * ts_yzz_xyy_0[j] + 0.5 * fl1_fx * ts_zz_xyy_0[j] + fl1_fx * ts_yzz_xy_0[j];

            ts_yyzz_xyz_0[j] = pa_y[j] * ts_yzz_xyz_0[j] + 0.5 * fl1_fx * ts_zz_xyz_0[j] + 0.5 * fl1_fx * ts_yzz_xz_0[j];

            ts_yyzz_xzz_0[j] = pa_y[j] * ts_yzz_xzz_0[j] + 0.5 * fl1_fx * ts_zz_xzz_0[j];

            ts_yyzz_yyy_0[j] = pa_y[j] * ts_yzz_yyy_0[j] + 0.5 * fl1_fx * ts_zz_yyy_0[j] + 1.5 * fl1_fx * ts_yzz_yy_0[j];

            ts_yyzz_yyz_0[j] = pa_y[j] * ts_yzz_yyz_0[j] + 0.5 * fl1_fx * ts_zz_yyz_0[j] + fl1_fx * ts_yzz_yz_0[j];

            ts_yyzz_yzz_0[j] = pa_y[j] * ts_yzz_yzz_0[j] + 0.5 * fl1_fx * ts_zz_yzz_0[j] + 0.5 * fl1_fx * ts_yzz_zz_0[j];

            ts_yyzz_zzz_0[j] = pa_y[j] * ts_yzz_zzz_0[j] + 0.5 * fl1_fx * ts_zz_zzz_0[j];

            ts_yzzz_xxx_0[j] = pa_y[j] * ts_zzz_xxx_0[j];

            ts_yzzz_xxy_0[j] = pa_y[j] * ts_zzz_xxy_0[j] + 0.5 * fl1_fx * ts_zzz_xx_0[j];

            ts_yzzz_xxz_0[j] = pa_y[j] * ts_zzz_xxz_0[j];

            ts_yzzz_xyy_0[j] = pa_y[j] * ts_zzz_xyy_0[j] + fl1_fx * ts_zzz_xy_0[j];

            ts_yzzz_xyz_0[j] = pa_y[j] * ts_zzz_xyz_0[j] + 0.5 * fl1_fx * ts_zzz_xz_0[j];

            ts_yzzz_xzz_0[j] = pa_y[j] * ts_zzz_xzz_0[j];

            ts_yzzz_yyy_0[j] = pa_y[j] * ts_zzz_yyy_0[j] + 1.5 * fl1_fx * ts_zzz_yy_0[j];

            ts_yzzz_yyz_0[j] = pa_y[j] * ts_zzz_yyz_0[j] + fl1_fx * ts_zzz_yz_0[j];

            ts_yzzz_yzz_0[j] = pa_y[j] * ts_zzz_yzz_0[j] + 0.5 * fl1_fx * ts_zzz_zz_0[j];

            ts_yzzz_zzz_0[j] = pa_y[j] * ts_zzz_zzz_0[j];

            ts_zzzz_xxx_0[j] = pa_z[j] * ts_zzz_xxx_0[j] + 1.5 * fl1_fx * ts_zz_xxx_0[j];

            ts_zzzz_xxy_0[j] = pa_z[j] * ts_zzz_xxy_0[j] + 1.5 * fl1_fx * ts_zz_xxy_0[j];

            ts_zzzz_xxz_0[j] = pa_z[j] * ts_zzz_xxz_0[j] + 1.5 * fl1_fx * ts_zz_xxz_0[j] + 0.5 * fl1_fx * ts_zzz_xx_0[j];

            ts_zzzz_xyy_0[j] = pa_z[j] * ts_zzz_xyy_0[j] + 1.5 * fl1_fx * ts_zz_xyy_0[j];

            ts_zzzz_xyz_0[j] = pa_z[j] * ts_zzz_xyz_0[j] + 1.5 * fl1_fx * ts_zz_xyz_0[j] + 0.5 * fl1_fx * ts_zzz_xy_0[j];

            ts_zzzz_xzz_0[j] = pa_z[j] * ts_zzz_xzz_0[j] + 1.5 * fl1_fx * ts_zz_xzz_0[j] + fl1_fx * ts_zzz_xz_0[j];

            ts_zzzz_yyy_0[j] = pa_z[j] * ts_zzz_yyy_0[j] + 1.5 * fl1_fx * ts_zz_yyy_0[j];

            ts_zzzz_yyz_0[j] = pa_z[j] * ts_zzz_yyz_0[j] + 1.5 * fl1_fx * ts_zz_yyz_0[j] + 0.5 * fl1_fx * ts_zzz_yy_0[j];

            ts_zzzz_yzz_0[j] = pa_z[j] * ts_zzz_yzz_0[j] + 1.5 * fl1_fx * ts_zz_yzz_0[j] + fl1_fx * ts_zzz_yz_0[j];

            ts_zzzz_zzz_0[j] = pa_z[j] * ts_zzz_zzz_0[j] + 1.5 * fl1_fx * ts_zz_zzz_0[j] + 1.5 * fl1_fx * ts_zzz_zz_0[j];
        }

        idx++;
    }
}

}  // namespace ovlrecfunc
