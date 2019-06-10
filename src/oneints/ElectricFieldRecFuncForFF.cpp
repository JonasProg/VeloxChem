//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "ElectricFieldRecFuncForFF.hpp"

namespace efieldrecfunc { // efieldrecfunc namespace

    void
    compElectricFieldForFF(      CMemBlock2D<double>& primBuffer,
                           const CRecursionMap&       recursionMap,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pcDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        efieldrecfunc::compElectricFieldForFF_0_50(primBuffer,
                                                   recursionMap,
                                                   osFactors,
                                                   paDistances, 
                                                   pcDistances, 
                                                   braGtoBlock,
                                                   ketGtoBlock,
                                                   iContrGto); 

        efieldrecfunc::compElectricFieldForFF_50_100(primBuffer,
                                                     recursionMap,
                                                     osFactors,
                                                     paDistances, 
                                                     pcDistances, 
                                                     braGtoBlock,
                                                     ketGtoBlock,
                                                     iContrGto); 

        efieldrecfunc::compElectricFieldForFF_100_150(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      paDistances, 
                                                      pcDistances, 
                                                      braGtoBlock,
                                                      ketGtoBlock,
                                                      iContrGto); 

        efieldrecfunc::compElectricFieldForFF_150_200(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      paDistances, 
                                                      pcDistances, 
                                                      braGtoBlock,
                                                      ketGtoBlock,
                                                      iContrGto); 

        efieldrecfunc::compElectricFieldForFF_200_250(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      paDistances, 
                                                      pcDistances, 
                                                      braGtoBlock,
                                                      ketGtoBlock,
                                                      iContrGto); 

        efieldrecfunc::compElectricFieldForFF_250_300(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      paDistances, 
                                                      pcDistances, 
                                                      braGtoBlock,
                                                      ketGtoBlock,
                                                      iContrGto); 
    }

    void
    compElectricFieldForFF_0_50(      CMemBlock2D<double>& primBuffer,
                                const CRecursionMap&       recursionMap,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pcDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto)
    {
        // Batch of Integrals (0,50)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_1_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_1_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_x = paDistances.data(3 * idx);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_x = pcDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tex_xx_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx); 

                auto tey_xx_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx); 

                auto tez_xx_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx); 

                auto tex_xx_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 1); 

                auto tey_xx_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 1); 

                auto tez_xx_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 1); 

                auto tex_xx_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 2); 

                auto tey_xx_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 2); 

                auto tez_xx_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 2); 

                auto tex_xx_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 3); 

                auto tey_xx_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 3); 

                auto tez_xx_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 3); 

                auto tex_xx_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 4); 

                auto tey_xx_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 4); 

                auto tez_xx_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 4); 

                auto tex_xx_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 5); 

                auto tey_xx_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 5); 

                auto tez_xx_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 5); 

                auto tex_xx_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 6); 

                auto tey_xx_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 6); 

                auto tez_xx_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 6); 

                auto tex_xx_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 7); 

                auto tey_xx_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 7); 

                auto tez_xx_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 7); 

                auto tex_xx_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 8); 

                auto tey_xx_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 8); 

                auto tez_xx_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 8); 

                auto tex_xx_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 9); 

                auto tey_xx_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 9); 

                auto tez_xx_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 9); 

                auto tex_xy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 10); 

                auto tey_xy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 10); 

                auto tez_xy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 10); 

                auto tex_xy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 11); 

                auto tey_xy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 11); 

                auto tez_xy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 11); 

                auto tex_xy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 12); 

                auto tey_xy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 12); 

                auto tez_xy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 12); 

                auto tex_xy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 13); 

                auto tey_xy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 13); 

                auto tez_xy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 13); 

                auto tex_xy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 14); 

                auto tey_xy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 14); 

                auto tez_xy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 14); 

                auto tex_xy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 15); 

                auto tey_xy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 15); 

                auto tez_xy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 15); 

                auto tex_xy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 16); 

                auto tey_xy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 16); 

                auto tex_xx_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx); 

                auto tey_xx_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx); 

                auto tez_xx_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx); 

                auto tex_xx_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 1); 

                auto tey_xx_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 1); 

                auto tez_xx_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 1); 

                auto tex_xx_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 2); 

                auto tey_xx_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 2); 

                auto tez_xx_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 2); 

                auto tex_xx_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 3); 

                auto tey_xx_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 3); 

                auto tez_xx_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 3); 

                auto tex_xx_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 4); 

                auto tey_xx_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 4); 

                auto tez_xx_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 4); 

                auto tex_xx_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 5); 

                auto tey_xx_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 5); 

                auto tez_xx_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 5); 

                auto tex_xx_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 6); 

                auto tey_xx_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 6); 

                auto tez_xx_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 6); 

                auto tex_xx_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 7); 

                auto tey_xx_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 7); 

                auto tez_xx_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 7); 

                auto tex_xx_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 8); 

                auto tey_xx_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 8); 

                auto tez_xx_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 8); 

                auto tex_xx_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 9); 

                auto tey_xx_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 9); 

                auto tez_xx_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 9); 

                auto tex_xy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 10); 

                auto tey_xy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 10); 

                auto tez_xy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 10); 

                auto tex_xy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 11); 

                auto tey_xy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 11); 

                auto tez_xy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 11); 

                auto tex_xy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 12); 

                auto tey_xy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 12); 

                auto tez_xy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 12); 

                auto tex_xy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 13); 

                auto tey_xy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 13); 

                auto tez_xy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 13); 

                auto tex_xy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 14); 

                auto tey_xy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 14); 

                auto tez_xy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 14); 

                auto tex_xy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 15); 

                auto tey_xy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 15); 

                auto tez_xy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 15); 

                auto tex_xy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 16); 

                auto tey_xy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 16); 

                auto tex_x_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx); 

                auto tey_x_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx); 

                auto tez_x_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx); 

                auto tex_x_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 1); 

                auto tey_x_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 1); 

                auto tez_x_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 1); 

                auto tex_x_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 2); 

                auto tey_x_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 2); 

                auto tez_x_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 2); 

                auto tex_x_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 3); 

                auto tey_x_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 3); 

                auto tez_x_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 3); 

                auto tex_x_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 4); 

                auto tey_x_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 4); 

                auto tez_x_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 4); 

                auto tex_x_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 5); 

                auto tey_x_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 5); 

                auto tez_x_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 5); 

                auto tex_x_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 6); 

                auto tey_x_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 6); 

                auto tez_x_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 6); 

                auto tex_x_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 7); 

                auto tey_x_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 7); 

                auto tez_x_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 7); 

                auto tex_x_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 8); 

                auto tey_x_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 8); 

                auto tez_x_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 8); 

                auto tex_x_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 9); 

                auto tey_x_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 9); 

                auto tez_x_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 9); 

                auto tex_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 10); 

                auto tey_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 10); 

                auto tez_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 10); 

                auto tex_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 11); 

                auto tey_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 11); 

                auto tez_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 11); 

                auto tex_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 12); 

                auto tey_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 12); 

                auto tez_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 12); 

                auto tex_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 13); 

                auto tey_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 13); 

                auto tez_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 13); 

                auto tex_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 14); 

                auto tey_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 14); 

                auto tez_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 14); 

                auto tex_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 15); 

                auto tey_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 15); 

                auto tez_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 15); 

                auto tex_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 16); 

                auto tey_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 16); 

                auto tex_x_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx); 

                auto tey_x_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx); 

                auto tez_x_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx); 

                auto tex_x_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 1); 

                auto tey_x_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 1); 

                auto tez_x_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 1); 

                auto tex_x_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 2); 

                auto tey_x_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 2); 

                auto tez_x_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 2); 

                auto tex_x_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 3); 

                auto tey_x_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 3); 

                auto tez_x_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 3); 

                auto tex_x_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 4); 

                auto tey_x_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 4); 

                auto tez_x_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 4); 

                auto tex_x_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 5); 

                auto tey_x_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 5); 

                auto tez_x_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 5); 

                auto tex_x_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 6); 

                auto tey_x_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 6); 

                auto tez_x_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 6); 

                auto tex_x_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 7); 

                auto tey_x_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 7); 

                auto tez_x_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 7); 

                auto tex_x_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 8); 

                auto tey_x_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 8); 

                auto tez_x_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 8); 

                auto tex_x_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 9); 

                auto tey_x_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 9); 

                auto tez_x_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 9); 

                auto tex_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 10); 

                auto tey_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 10); 

                auto tez_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 10); 

                auto tex_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 11); 

                auto tey_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 11); 

                auto tez_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 11); 

                auto tex_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 12); 

                auto tey_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 12); 

                auto tez_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 12); 

                auto tex_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 13); 

                auto tey_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 13); 

                auto tez_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 13); 

                auto tex_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 14); 

                auto tey_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 14); 

                auto tez_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 14); 

                auto tex_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 15); 

                auto tey_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 15); 

                auto tez_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 15); 

                auto tex_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 16); 

                auto tey_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 16); 

                auto tex_xx_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx); 

                auto tey_xx_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx); 

                auto tez_xx_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx); 

                auto tex_xx_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 1); 

                auto tey_xx_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 1); 

                auto tez_xx_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 1); 

                auto tex_xx_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 2); 

                auto tey_xx_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 2); 

                auto tez_xx_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 2); 

                auto tex_xx_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 3); 

                auto tey_xx_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 3); 

                auto tez_xx_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 3); 

                auto tex_xx_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 4); 

                auto tey_xx_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 4); 

                auto tez_xx_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 4); 

                auto tex_xx_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 5); 

                auto tey_xx_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 5); 

                auto tez_xx_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 5); 

                auto tex_xy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 6); 

                auto tey_xy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 6); 

                auto tez_xy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 6); 

                auto tex_xy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 7); 

                auto tey_xy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 7); 

                auto tez_xy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 7); 

                auto tex_xy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 8); 

                auto tey_xy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 8); 

                auto tez_xy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 8); 

                auto tex_xy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 9); 

                auto tey_xy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 9); 

                auto tez_xy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 9); 

                auto tex_xy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 10); 

                auto tey_xy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 10); 

                auto tez_xy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 10); 

                auto tex_xy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 11); 

                auto tey_xy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 11); 

                auto tez_xy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 11); 

                auto tex_xx_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx); 

                auto tey_xx_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx); 

                auto tez_xx_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx); 

                auto tex_xx_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 1); 

                auto tey_xx_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 1); 

                auto tez_xx_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 1); 

                auto tex_xx_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 2); 

                auto tey_xx_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 2); 

                auto tez_xx_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 2); 

                auto tex_xx_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 3); 

                auto tey_xx_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 3); 

                auto tez_xx_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 3); 

                auto tex_xx_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 4); 

                auto tey_xx_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 4); 

                auto tez_xx_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 4); 

                auto tex_xx_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 5); 

                auto tey_xx_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 5); 

                auto tez_xx_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 5); 

                auto tex_xy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 6); 

                auto tey_xy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 6); 

                auto tez_xy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 6); 

                auto tex_xy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 7); 

                auto tey_xy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 7); 

                auto tez_xy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 7); 

                auto tex_xy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 8); 

                auto tey_xy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 8); 

                auto tez_xy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 8); 

                auto tex_xy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 9); 

                auto tey_xy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 9); 

                auto tez_xy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 9); 

                auto tex_xy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 10); 

                auto tey_xy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 10); 

                auto tez_xy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 10); 

                auto tex_xy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 11); 

                auto tey_xy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 11); 

                auto tez_xy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 11); 

                auto ta_xx_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx); 

                auto ta_xx_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 1); 

                auto ta_xx_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 2); 

                auto ta_xx_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 3); 

                auto ta_xx_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 4); 

                auto ta_xx_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 5); 

                auto ta_xx_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 6); 

                auto ta_xx_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 7); 

                auto ta_xx_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 8); 

                auto ta_xx_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 9); 

                auto ta_xy_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 10); 

                auto ta_xy_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 11); 

                auto ta_xy_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 12); 

                auto ta_xy_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 13); 

                auto ta_xy_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 14); 

                auto ta_xy_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 15); 

                auto ta_xy_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 16); 

                // set up pointers to integrals

                auto tex_xxx_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx); 

                auto tey_xxx_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx); 

                auto tez_xxx_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx); 

                auto tex_xxx_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 1); 

                auto tey_xxx_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 1); 

                auto tez_xxx_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 1); 

                auto tex_xxx_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 2); 

                auto tey_xxx_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 2); 

                auto tez_xxx_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 2); 

                auto tex_xxx_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 3); 

                auto tey_xxx_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 3); 

                auto tez_xxx_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 3); 

                auto tex_xxx_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 4); 

                auto tey_xxx_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 4); 

                auto tez_xxx_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 4); 

                auto tex_xxx_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 5); 

                auto tey_xxx_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 5); 

                auto tez_xxx_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 5); 

                auto tex_xxx_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 6); 

                auto tey_xxx_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 6); 

                auto tez_xxx_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 6); 

                auto tex_xxx_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 7); 

                auto tey_xxx_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 7); 

                auto tez_xxx_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 7); 

                auto tex_xxx_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 8); 

                auto tey_xxx_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 8); 

                auto tez_xxx_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 8); 

                auto tex_xxx_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 9); 

                auto tey_xxx_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 9); 

                auto tez_xxx_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 9); 

                auto tex_xxy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 10); 

                auto tey_xxy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 10); 

                auto tez_xxy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 10); 

                auto tex_xxy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 11); 

                auto tey_xxy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 11); 

                auto tez_xxy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 11); 

                auto tex_xxy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 12); 

                auto tey_xxy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 12); 

                auto tez_xxy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 12); 

                auto tex_xxy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 13); 

                auto tey_xxy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 13); 

                auto tez_xxy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 13); 

                auto tex_xxy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 14); 

                auto tey_xxy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 14); 

                auto tez_xxy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 14); 

                auto tex_xxy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 15); 

                auto tey_xxy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 15); 

                auto tez_xxy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 15); 

                auto tex_xxy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 16); 

                auto tey_xxy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 16); 

                // Batch of Integrals (0,50)

                #pragma omp simd aligned(fx, pa_x, pc_x, ta_xx_xxx_1, ta_xx_xxy_1, ta_xx_xxz_1, ta_xx_xyy_1, \
                                         ta_xx_xyz_1, ta_xx_xzz_1, ta_xx_yyy_1, ta_xx_yyz_1, ta_xx_yzz_1, ta_xx_zzz_1, \
                                         ta_xy_xxx_1, ta_xy_xxy_1, ta_xy_xxz_1, ta_xy_xyy_1, ta_xy_xyz_1, ta_xy_xzz_1, \
                                         ta_xy_yyy_1, tex_x_xxx_0, tex_x_xxx_1, tex_x_xxy_0, tex_x_xxy_1, tex_x_xxz_0, \
                                         tex_x_xxz_1, tex_x_xyy_0, tex_x_xyy_1, tex_x_xyz_0, tex_x_xyz_1, tex_x_xzz_0, \
                                         tex_x_xzz_1, tex_x_yyy_0, tex_x_yyy_1, tex_x_yyz_0, tex_x_yyz_1, tex_x_yzz_0, \
                                         tex_x_yzz_1, tex_x_zzz_0, tex_x_zzz_1, tex_xx_xx_0, tex_xx_xx_1, tex_xx_xxx_0, \
                                         tex_xx_xxx_1, tex_xx_xxy_0, tex_xx_xxy_1, tex_xx_xxz_0, tex_xx_xxz_1, tex_xx_xy_0, \
                                         tex_xx_xy_1, tex_xx_xyy_0, tex_xx_xyy_1, tex_xx_xyz_0, tex_xx_xyz_1, tex_xx_xz_0, \
                                         tex_xx_xz_1, tex_xx_xzz_0, tex_xx_xzz_1, tex_xx_yy_0, tex_xx_yy_1, tex_xx_yyy_0, \
                                         tex_xx_yyy_1, tex_xx_yyz_0, tex_xx_yyz_1, tex_xx_yz_0, tex_xx_yz_1, tex_xx_yzz_0, \
                                         tex_xx_yzz_1, tex_xx_zz_0, tex_xx_zz_1, tex_xx_zzz_0, tex_xx_zzz_1, tex_xxx_xxx_0, \
                                         tex_xxx_xxy_0, tex_xxx_xxz_0, tex_xxx_xyy_0, tex_xxx_xyz_0, tex_xxx_xzz_0, \
                                         tex_xxx_yyy_0, tex_xxx_yyz_0, tex_xxx_yzz_0, tex_xxx_zzz_0, tex_xxy_xxx_0, \
                                         tex_xxy_xxy_0, tex_xxy_xxz_0, tex_xxy_xyy_0, tex_xxy_xyz_0, tex_xxy_xzz_0, \
                                         tex_xxy_yyy_0, tex_xy_xx_0, tex_xy_xx_1, tex_xy_xxx_0, tex_xy_xxx_1, tex_xy_xxy_0, \
                                         tex_xy_xxy_1, tex_xy_xxz_0, tex_xy_xxz_1, tex_xy_xy_0, tex_xy_xy_1, tex_xy_xyy_0, \
                                         tex_xy_xyy_1, tex_xy_xyz_0, tex_xy_xyz_1, tex_xy_xz_0, tex_xy_xz_1, tex_xy_xzz_0, \
                                         tex_xy_xzz_1, tex_xy_yy_0, tex_xy_yy_1, tex_xy_yyy_0, tex_xy_yyy_1, tex_xy_yz_0, \
                                         tex_xy_yz_1, tex_xy_zz_0, tex_xy_zz_1, tex_y_xxx_0, tex_y_xxx_1, tex_y_xxy_0, \
                                         tex_y_xxy_1, tex_y_xxz_0, tex_y_xxz_1, tex_y_xyy_0, tex_y_xyy_1, tex_y_xyz_0, \
                                         tex_y_xyz_1, tex_y_xzz_0, tex_y_xzz_1, tex_y_yyy_0, tex_y_yyy_1, tey_x_xxx_0, \
                                         tey_x_xxx_1, tey_x_xxy_0, tey_x_xxy_1, tey_x_xxz_0, tey_x_xxz_1, tey_x_xyy_0, \
                                         tey_x_xyy_1, tey_x_xyz_0, tey_x_xyz_1, tey_x_xzz_0, tey_x_xzz_1, tey_x_yyy_0, \
                                         tey_x_yyy_1, tey_x_yyz_0, tey_x_yyz_1, tey_x_yzz_0, tey_x_yzz_1, tey_x_zzz_0, \
                                         tey_x_zzz_1, tey_xx_xx_0, tey_xx_xx_1, tey_xx_xxx_0, tey_xx_xxx_1, tey_xx_xxy_0, \
                                         tey_xx_xxy_1, tey_xx_xxz_0, tey_xx_xxz_1, tey_xx_xy_0, tey_xx_xy_1, tey_xx_xyy_0, \
                                         tey_xx_xyy_1, tey_xx_xyz_0, tey_xx_xyz_1, tey_xx_xz_0, tey_xx_xz_1, tey_xx_xzz_0, \
                                         tey_xx_xzz_1, tey_xx_yy_0, tey_xx_yy_1, tey_xx_yyy_0, tey_xx_yyy_1, tey_xx_yyz_0, \
                                         tey_xx_yyz_1, tey_xx_yz_0, tey_xx_yz_1, tey_xx_yzz_0, tey_xx_yzz_1, tey_xx_zz_0, \
                                         tey_xx_zz_1, tey_xx_zzz_0, tey_xx_zzz_1, tey_xxx_xxx_0, tey_xxx_xxy_0, \
                                         tey_xxx_xxz_0, tey_xxx_xyy_0, tey_xxx_xyz_0, tey_xxx_xzz_0, tey_xxx_yyy_0, \
                                         tey_xxx_yyz_0, tey_xxx_yzz_0, tey_xxx_zzz_0, tey_xxy_xxx_0, tey_xxy_xxy_0, \
                                         tey_xxy_xxz_0, tey_xxy_xyy_0, tey_xxy_xyz_0, tey_xxy_xzz_0, tey_xxy_yyy_0, \
                                         tey_xy_xx_0, tey_xy_xx_1, tey_xy_xxx_0, tey_xy_xxx_1, tey_xy_xxy_0, tey_xy_xxy_1, \
                                         tey_xy_xxz_0, tey_xy_xxz_1, tey_xy_xy_0, tey_xy_xy_1, tey_xy_xyy_0, tey_xy_xyy_1, \
                                         tey_xy_xyz_0, tey_xy_xyz_1, tey_xy_xz_0, tey_xy_xz_1, tey_xy_xzz_0, tey_xy_xzz_1, \
                                         tey_xy_yy_0, tey_xy_yy_1, tey_xy_yyy_0, tey_xy_yyy_1, tey_xy_yz_0, tey_xy_yz_1, \
                                         tey_xy_zz_0, tey_xy_zz_1, tey_y_xxx_0, tey_y_xxx_1, tey_y_xxy_0, tey_y_xxy_1, \
                                         tey_y_xxz_0, tey_y_xxz_1, tey_y_xyy_0, tey_y_xyy_1, tey_y_xyz_0, tey_y_xyz_1, \
                                         tey_y_xzz_0, tey_y_xzz_1, tey_y_yyy_0, tey_y_yyy_1, tez_x_xxx_0, tez_x_xxx_1, \
                                         tez_x_xxy_0, tez_x_xxy_1, tez_x_xxz_0, tez_x_xxz_1, tez_x_xyy_0, tez_x_xyy_1, \
                                         tez_x_xyz_0, tez_x_xyz_1, tez_x_xzz_0, tez_x_xzz_1, tez_x_yyy_0, tez_x_yyy_1, \
                                         tez_x_yyz_0, tez_x_yyz_1, tez_x_yzz_0, tez_x_yzz_1, tez_x_zzz_0, tez_x_zzz_1, \
                                         tez_xx_xx_0, tez_xx_xx_1, tez_xx_xxx_0, tez_xx_xxx_1, tez_xx_xxy_0, tez_xx_xxy_1, \
                                         tez_xx_xxz_0, tez_xx_xxz_1, tez_xx_xy_0, tez_xx_xy_1, tez_xx_xyy_0, tez_xx_xyy_1, \
                                         tez_xx_xyz_0, tez_xx_xyz_1, tez_xx_xz_0, tez_xx_xz_1, tez_xx_xzz_0, tez_xx_xzz_1, \
                                         tez_xx_yy_0, tez_xx_yy_1, tez_xx_yyy_0, tez_xx_yyy_1, tez_xx_yyz_0, tez_xx_yyz_1, \
                                         tez_xx_yz_0, tez_xx_yz_1, tez_xx_yzz_0, tez_xx_yzz_1, tez_xx_zz_0, tez_xx_zz_1, \
                                         tez_xx_zzz_0, tez_xx_zzz_1, tez_xxx_xxx_0, tez_xxx_xxy_0, tez_xxx_xxz_0, \
                                         tez_xxx_xyy_0, tez_xxx_xyz_0, tez_xxx_xzz_0, tez_xxx_yyy_0, tez_xxx_yyz_0, \
                                         tez_xxx_yzz_0, tez_xxx_zzz_0, tez_xxy_xxx_0, tez_xxy_xxy_0, tez_xxy_xxz_0, \
                                         tez_xxy_xyy_0, tez_xxy_xyz_0, tez_xxy_xzz_0, tez_xy_xx_0, tez_xy_xx_1, tez_xy_xxx_0, \
                                         tez_xy_xxx_1, tez_xy_xxy_0, tez_xy_xxy_1, tez_xy_xxz_0, tez_xy_xxz_1, tez_xy_xy_0, \
                                         tez_xy_xy_1, tez_xy_xyy_0, tez_xy_xyy_1, tez_xy_xyz_0, tez_xy_xyz_1, tez_xy_xz_0, \
                                         tez_xy_xz_1, tez_xy_xzz_0, tez_xy_xzz_1, tez_xy_yy_0, tez_xy_yy_1, tez_xy_yz_0, \
                                         tez_xy_yz_1, tez_xy_zz_0, tez_xy_zz_1, tez_y_xxx_0, tez_y_xxx_1, tez_y_xxy_0, \
                                         tez_y_xxy_1, tez_y_xxz_0, tez_y_xxz_1, tez_y_xyy_0, tez_y_xyy_1, tez_y_xyz_0, \
                                         tez_y_xyz_1, tez_y_xzz_0, tez_y_xzz_1: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tex_xxx_xxx_0[j] = pa_x[j] * tex_xx_xxx_0[j] - pc_x[j] * tex_xx_xxx_1[j] + fl1_fx * tex_x_xxx_0[j] - fl1_fx * tex_x_xxx_1[j] + 1.5 * fl1_fx * tex_xx_xx_0[j] - 1.5 * fl1_fx * tex_xx_xx_1[j] + ta_xx_xxx_1[j];

                    tey_xxx_xxx_0[j] = pa_x[j] * tey_xx_xxx_0[j] - pc_x[j] * tey_xx_xxx_1[j] + fl1_fx * tey_x_xxx_0[j] - fl1_fx * tey_x_xxx_1[j] + 1.5 * fl1_fx * tey_xx_xx_0[j] - 1.5 * fl1_fx * tey_xx_xx_1[j];

                    tez_xxx_xxx_0[j] = pa_x[j] * tez_xx_xxx_0[j] - pc_x[j] * tez_xx_xxx_1[j] + fl1_fx * tez_x_xxx_0[j] - fl1_fx * tez_x_xxx_1[j] + 1.5 * fl1_fx * tez_xx_xx_0[j] - 1.5 * fl1_fx * tez_xx_xx_1[j];

                    tex_xxx_xxy_0[j] = pa_x[j] * tex_xx_xxy_0[j] - pc_x[j] * tex_xx_xxy_1[j] + fl1_fx * tex_x_xxy_0[j] - fl1_fx * tex_x_xxy_1[j] + fl1_fx * tex_xx_xy_0[j] - fl1_fx * tex_xx_xy_1[j] + ta_xx_xxy_1[j];

                    tey_xxx_xxy_0[j] = pa_x[j] * tey_xx_xxy_0[j] - pc_x[j] * tey_xx_xxy_1[j] + fl1_fx * tey_x_xxy_0[j] - fl1_fx * tey_x_xxy_1[j] + fl1_fx * tey_xx_xy_0[j] - fl1_fx * tey_xx_xy_1[j];

                    tez_xxx_xxy_0[j] = pa_x[j] * tez_xx_xxy_0[j] - pc_x[j] * tez_xx_xxy_1[j] + fl1_fx * tez_x_xxy_0[j] - fl1_fx * tez_x_xxy_1[j] + fl1_fx * tez_xx_xy_0[j] - fl1_fx * tez_xx_xy_1[j];

                    tex_xxx_xxz_0[j] = pa_x[j] * tex_xx_xxz_0[j] - pc_x[j] * tex_xx_xxz_1[j] + fl1_fx * tex_x_xxz_0[j] - fl1_fx * tex_x_xxz_1[j] + fl1_fx * tex_xx_xz_0[j] - fl1_fx * tex_xx_xz_1[j] + ta_xx_xxz_1[j];

                    tey_xxx_xxz_0[j] = pa_x[j] * tey_xx_xxz_0[j] - pc_x[j] * tey_xx_xxz_1[j] + fl1_fx * tey_x_xxz_0[j] - fl1_fx * tey_x_xxz_1[j] + fl1_fx * tey_xx_xz_0[j] - fl1_fx * tey_xx_xz_1[j];

                    tez_xxx_xxz_0[j] = pa_x[j] * tez_xx_xxz_0[j] - pc_x[j] * tez_xx_xxz_1[j] + fl1_fx * tez_x_xxz_0[j] - fl1_fx * tez_x_xxz_1[j] + fl1_fx * tez_xx_xz_0[j] - fl1_fx * tez_xx_xz_1[j];

                    tex_xxx_xyy_0[j] = pa_x[j] * tex_xx_xyy_0[j] - pc_x[j] * tex_xx_xyy_1[j] + fl1_fx * tex_x_xyy_0[j] - fl1_fx * tex_x_xyy_1[j] + 0.5 * fl1_fx * tex_xx_yy_0[j] - 0.5 * fl1_fx * tex_xx_yy_1[j] + ta_xx_xyy_1[j];

                    tey_xxx_xyy_0[j] = pa_x[j] * tey_xx_xyy_0[j] - pc_x[j] * tey_xx_xyy_1[j] + fl1_fx * tey_x_xyy_0[j] - fl1_fx * tey_x_xyy_1[j] + 0.5 * fl1_fx * tey_xx_yy_0[j] - 0.5 * fl1_fx * tey_xx_yy_1[j];

                    tez_xxx_xyy_0[j] = pa_x[j] * tez_xx_xyy_0[j] - pc_x[j] * tez_xx_xyy_1[j] + fl1_fx * tez_x_xyy_0[j] - fl1_fx * tez_x_xyy_1[j] + 0.5 * fl1_fx * tez_xx_yy_0[j] - 0.5 * fl1_fx * tez_xx_yy_1[j];

                    tex_xxx_xyz_0[j] = pa_x[j] * tex_xx_xyz_0[j] - pc_x[j] * tex_xx_xyz_1[j] + fl1_fx * tex_x_xyz_0[j] - fl1_fx * tex_x_xyz_1[j] + 0.5 * fl1_fx * tex_xx_yz_0[j] - 0.5 * fl1_fx * tex_xx_yz_1[j] + ta_xx_xyz_1[j];

                    tey_xxx_xyz_0[j] = pa_x[j] * tey_xx_xyz_0[j] - pc_x[j] * tey_xx_xyz_1[j] + fl1_fx * tey_x_xyz_0[j] - fl1_fx * tey_x_xyz_1[j] + 0.5 * fl1_fx * tey_xx_yz_0[j] - 0.5 * fl1_fx * tey_xx_yz_1[j];

                    tez_xxx_xyz_0[j] = pa_x[j] * tez_xx_xyz_0[j] - pc_x[j] * tez_xx_xyz_1[j] + fl1_fx * tez_x_xyz_0[j] - fl1_fx * tez_x_xyz_1[j] + 0.5 * fl1_fx * tez_xx_yz_0[j] - 0.5 * fl1_fx * tez_xx_yz_1[j];

                    tex_xxx_xzz_0[j] = pa_x[j] * tex_xx_xzz_0[j] - pc_x[j] * tex_xx_xzz_1[j] + fl1_fx * tex_x_xzz_0[j] - fl1_fx * tex_x_xzz_1[j] + 0.5 * fl1_fx * tex_xx_zz_0[j] - 0.5 * fl1_fx * tex_xx_zz_1[j] + ta_xx_xzz_1[j];

                    tey_xxx_xzz_0[j] = pa_x[j] * tey_xx_xzz_0[j] - pc_x[j] * tey_xx_xzz_1[j] + fl1_fx * tey_x_xzz_0[j] - fl1_fx * tey_x_xzz_1[j] + 0.5 * fl1_fx * tey_xx_zz_0[j] - 0.5 * fl1_fx * tey_xx_zz_1[j];

                    tez_xxx_xzz_0[j] = pa_x[j] * tez_xx_xzz_0[j] - pc_x[j] * tez_xx_xzz_1[j] + fl1_fx * tez_x_xzz_0[j] - fl1_fx * tez_x_xzz_1[j] + 0.5 * fl1_fx * tez_xx_zz_0[j] - 0.5 * fl1_fx * tez_xx_zz_1[j];

                    tex_xxx_yyy_0[j] = pa_x[j] * tex_xx_yyy_0[j] - pc_x[j] * tex_xx_yyy_1[j] + fl1_fx * tex_x_yyy_0[j] - fl1_fx * tex_x_yyy_1[j] + ta_xx_yyy_1[j];

                    tey_xxx_yyy_0[j] = pa_x[j] * tey_xx_yyy_0[j] - pc_x[j] * tey_xx_yyy_1[j] + fl1_fx * tey_x_yyy_0[j] - fl1_fx * tey_x_yyy_1[j];

                    tez_xxx_yyy_0[j] = pa_x[j] * tez_xx_yyy_0[j] - pc_x[j] * tez_xx_yyy_1[j] + fl1_fx * tez_x_yyy_0[j] - fl1_fx * tez_x_yyy_1[j];

                    tex_xxx_yyz_0[j] = pa_x[j] * tex_xx_yyz_0[j] - pc_x[j] * tex_xx_yyz_1[j] + fl1_fx * tex_x_yyz_0[j] - fl1_fx * tex_x_yyz_1[j] + ta_xx_yyz_1[j];

                    tey_xxx_yyz_0[j] = pa_x[j] * tey_xx_yyz_0[j] - pc_x[j] * tey_xx_yyz_1[j] + fl1_fx * tey_x_yyz_0[j] - fl1_fx * tey_x_yyz_1[j];

                    tez_xxx_yyz_0[j] = pa_x[j] * tez_xx_yyz_0[j] - pc_x[j] * tez_xx_yyz_1[j] + fl1_fx * tez_x_yyz_0[j] - fl1_fx * tez_x_yyz_1[j];

                    tex_xxx_yzz_0[j] = pa_x[j] * tex_xx_yzz_0[j] - pc_x[j] * tex_xx_yzz_1[j] + fl1_fx * tex_x_yzz_0[j] - fl1_fx * tex_x_yzz_1[j] + ta_xx_yzz_1[j];

                    tey_xxx_yzz_0[j] = pa_x[j] * tey_xx_yzz_0[j] - pc_x[j] * tey_xx_yzz_1[j] + fl1_fx * tey_x_yzz_0[j] - fl1_fx * tey_x_yzz_1[j];

                    tez_xxx_yzz_0[j] = pa_x[j] * tez_xx_yzz_0[j] - pc_x[j] * tez_xx_yzz_1[j] + fl1_fx * tez_x_yzz_0[j] - fl1_fx * tez_x_yzz_1[j];

                    tex_xxx_zzz_0[j] = pa_x[j] * tex_xx_zzz_0[j] - pc_x[j] * tex_xx_zzz_1[j] + fl1_fx * tex_x_zzz_0[j] - fl1_fx * tex_x_zzz_1[j] + ta_xx_zzz_1[j];

                    tey_xxx_zzz_0[j] = pa_x[j] * tey_xx_zzz_0[j] - pc_x[j] * tey_xx_zzz_1[j] + fl1_fx * tey_x_zzz_0[j] - fl1_fx * tey_x_zzz_1[j];

                    tez_xxx_zzz_0[j] = pa_x[j] * tez_xx_zzz_0[j] - pc_x[j] * tez_xx_zzz_1[j] + fl1_fx * tez_x_zzz_0[j] - fl1_fx * tez_x_zzz_1[j];

                    tex_xxy_xxx_0[j] = pa_x[j] * tex_xy_xxx_0[j] - pc_x[j] * tex_xy_xxx_1[j] + 0.5 * fl1_fx * tex_y_xxx_0[j] - 0.5 * fl1_fx * tex_y_xxx_1[j] + 1.5 * fl1_fx * tex_xy_xx_0[j] - 1.5 * fl1_fx * tex_xy_xx_1[j] + ta_xy_xxx_1[j];

                    tey_xxy_xxx_0[j] = pa_x[j] * tey_xy_xxx_0[j] - pc_x[j] * tey_xy_xxx_1[j] + 0.5 * fl1_fx * tey_y_xxx_0[j] - 0.5 * fl1_fx * tey_y_xxx_1[j] + 1.5 * fl1_fx * tey_xy_xx_0[j] - 1.5 * fl1_fx * tey_xy_xx_1[j];

                    tez_xxy_xxx_0[j] = pa_x[j] * tez_xy_xxx_0[j] - pc_x[j] * tez_xy_xxx_1[j] + 0.5 * fl1_fx * tez_y_xxx_0[j] - 0.5 * fl1_fx * tez_y_xxx_1[j] + 1.5 * fl1_fx * tez_xy_xx_0[j] - 1.5 * fl1_fx * tez_xy_xx_1[j];

                    tex_xxy_xxy_0[j] = pa_x[j] * tex_xy_xxy_0[j] - pc_x[j] * tex_xy_xxy_1[j] + 0.5 * fl1_fx * tex_y_xxy_0[j] - 0.5 * fl1_fx * tex_y_xxy_1[j] + fl1_fx * tex_xy_xy_0[j] - fl1_fx * tex_xy_xy_1[j] + ta_xy_xxy_1[j];

                    tey_xxy_xxy_0[j] = pa_x[j] * tey_xy_xxy_0[j] - pc_x[j] * tey_xy_xxy_1[j] + 0.5 * fl1_fx * tey_y_xxy_0[j] - 0.5 * fl1_fx * tey_y_xxy_1[j] + fl1_fx * tey_xy_xy_0[j] - fl1_fx * tey_xy_xy_1[j];

                    tez_xxy_xxy_0[j] = pa_x[j] * tez_xy_xxy_0[j] - pc_x[j] * tez_xy_xxy_1[j] + 0.5 * fl1_fx * tez_y_xxy_0[j] - 0.5 * fl1_fx * tez_y_xxy_1[j] + fl1_fx * tez_xy_xy_0[j] - fl1_fx * tez_xy_xy_1[j];

                    tex_xxy_xxz_0[j] = pa_x[j] * tex_xy_xxz_0[j] - pc_x[j] * tex_xy_xxz_1[j] + 0.5 * fl1_fx * tex_y_xxz_0[j] - 0.5 * fl1_fx * tex_y_xxz_1[j] + fl1_fx * tex_xy_xz_0[j] - fl1_fx * tex_xy_xz_1[j] + ta_xy_xxz_1[j];

                    tey_xxy_xxz_0[j] = pa_x[j] * tey_xy_xxz_0[j] - pc_x[j] * tey_xy_xxz_1[j] + 0.5 * fl1_fx * tey_y_xxz_0[j] - 0.5 * fl1_fx * tey_y_xxz_1[j] + fl1_fx * tey_xy_xz_0[j] - fl1_fx * tey_xy_xz_1[j];

                    tez_xxy_xxz_0[j] = pa_x[j] * tez_xy_xxz_0[j] - pc_x[j] * tez_xy_xxz_1[j] + 0.5 * fl1_fx * tez_y_xxz_0[j] - 0.5 * fl1_fx * tez_y_xxz_1[j] + fl1_fx * tez_xy_xz_0[j] - fl1_fx * tez_xy_xz_1[j];

                    tex_xxy_xyy_0[j] = pa_x[j] * tex_xy_xyy_0[j] - pc_x[j] * tex_xy_xyy_1[j] + 0.5 * fl1_fx * tex_y_xyy_0[j] - 0.5 * fl1_fx * tex_y_xyy_1[j] + 0.5 * fl1_fx * tex_xy_yy_0[j] - 0.5 * fl1_fx * tex_xy_yy_1[j] + ta_xy_xyy_1[j];

                    tey_xxy_xyy_0[j] = pa_x[j] * tey_xy_xyy_0[j] - pc_x[j] * tey_xy_xyy_1[j] + 0.5 * fl1_fx * tey_y_xyy_0[j] - 0.5 * fl1_fx * tey_y_xyy_1[j] + 0.5 * fl1_fx * tey_xy_yy_0[j] - 0.5 * fl1_fx * tey_xy_yy_1[j];

                    tez_xxy_xyy_0[j] = pa_x[j] * tez_xy_xyy_0[j] - pc_x[j] * tez_xy_xyy_1[j] + 0.5 * fl1_fx * tez_y_xyy_0[j] - 0.5 * fl1_fx * tez_y_xyy_1[j] + 0.5 * fl1_fx * tez_xy_yy_0[j] - 0.5 * fl1_fx * tez_xy_yy_1[j];

                    tex_xxy_xyz_0[j] = pa_x[j] * tex_xy_xyz_0[j] - pc_x[j] * tex_xy_xyz_1[j] + 0.5 * fl1_fx * tex_y_xyz_0[j] - 0.5 * fl1_fx * tex_y_xyz_1[j] + 0.5 * fl1_fx * tex_xy_yz_0[j] - 0.5 * fl1_fx * tex_xy_yz_1[j] + ta_xy_xyz_1[j];

                    tey_xxy_xyz_0[j] = pa_x[j] * tey_xy_xyz_0[j] - pc_x[j] * tey_xy_xyz_1[j] + 0.5 * fl1_fx * tey_y_xyz_0[j] - 0.5 * fl1_fx * tey_y_xyz_1[j] + 0.5 * fl1_fx * tey_xy_yz_0[j] - 0.5 * fl1_fx * tey_xy_yz_1[j];

                    tez_xxy_xyz_0[j] = pa_x[j] * tez_xy_xyz_0[j] - pc_x[j] * tez_xy_xyz_1[j] + 0.5 * fl1_fx * tez_y_xyz_0[j] - 0.5 * fl1_fx * tez_y_xyz_1[j] + 0.5 * fl1_fx * tez_xy_yz_0[j] - 0.5 * fl1_fx * tez_xy_yz_1[j];

                    tex_xxy_xzz_0[j] = pa_x[j] * tex_xy_xzz_0[j] - pc_x[j] * tex_xy_xzz_1[j] + 0.5 * fl1_fx * tex_y_xzz_0[j] - 0.5 * fl1_fx * tex_y_xzz_1[j] + 0.5 * fl1_fx * tex_xy_zz_0[j] - 0.5 * fl1_fx * tex_xy_zz_1[j] + ta_xy_xzz_1[j];

                    tey_xxy_xzz_0[j] = pa_x[j] * tey_xy_xzz_0[j] - pc_x[j] * tey_xy_xzz_1[j] + 0.5 * fl1_fx * tey_y_xzz_0[j] - 0.5 * fl1_fx * tey_y_xzz_1[j] + 0.5 * fl1_fx * tey_xy_zz_0[j] - 0.5 * fl1_fx * tey_xy_zz_1[j];

                    tez_xxy_xzz_0[j] = pa_x[j] * tez_xy_xzz_0[j] - pc_x[j] * tez_xy_xzz_1[j] + 0.5 * fl1_fx * tez_y_xzz_0[j] - 0.5 * fl1_fx * tez_y_xzz_1[j] + 0.5 * fl1_fx * tez_xy_zz_0[j] - 0.5 * fl1_fx * tez_xy_zz_1[j];

                    tex_xxy_yyy_0[j] = pa_x[j] * tex_xy_yyy_0[j] - pc_x[j] * tex_xy_yyy_1[j] + 0.5 * fl1_fx * tex_y_yyy_0[j] - 0.5 * fl1_fx * tex_y_yyy_1[j] + ta_xy_yyy_1[j];

                    tey_xxy_yyy_0[j] = pa_x[j] * tey_xy_yyy_0[j] - pc_x[j] * tey_xy_yyy_1[j] + 0.5 * fl1_fx * tey_y_yyy_0[j] - 0.5 * fl1_fx * tey_y_yyy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectricFieldForFF_50_100(      CMemBlock2D<double>& primBuffer,
                                  const CRecursionMap&       recursionMap,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pcDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto)
    {
        // Batch of Integrals (50,100)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_1_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_1_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_x = paDistances.data(3 * idx);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_x = pcDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tez_xy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 16); 

                auto tex_xy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 17); 

                auto tey_xy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 17); 

                auto tez_xy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 17); 

                auto tex_xy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 18); 

                auto tey_xy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 18); 

                auto tez_xy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 18); 

                auto tex_xy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 19); 

                auto tey_xy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 19); 

                auto tez_xy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 19); 

                auto tex_xz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 20); 

                auto tey_xz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 20); 

                auto tez_xz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 20); 

                auto tex_xz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 21); 

                auto tey_xz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 21); 

                auto tez_xz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 21); 

                auto tex_xz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 22); 

                auto tey_xz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 22); 

                auto tez_xz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 22); 

                auto tex_xz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 23); 

                auto tey_xz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 23); 

                auto tez_xz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 23); 

                auto tex_xz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 24); 

                auto tey_xz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 24); 

                auto tez_xz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 24); 

                auto tex_xz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 25); 

                auto tey_xz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 25); 

                auto tez_xz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 25); 

                auto tex_xz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 26); 

                auto tey_xz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 26); 

                auto tez_xz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 26); 

                auto tex_xz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 27); 

                auto tey_xz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 27); 

                auto tez_xz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 27); 

                auto tex_xz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 28); 

                auto tey_xz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 28); 

                auto tez_xz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 28); 

                auto tex_xz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 29); 

                auto tey_xz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 29); 

                auto tez_xz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 29); 

                auto tex_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 30); 

                auto tey_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 30); 

                auto tez_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 30); 

                auto tex_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 31); 

                auto tey_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 31); 

                auto tez_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 31); 

                auto tex_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 32); 

                auto tey_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 32); 

                auto tez_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 32); 

                auto tex_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 33); 

                auto tez_xy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 16); 

                auto tex_xy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 17); 

                auto tey_xy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 17); 

                auto tez_xy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 17); 

                auto tex_xy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 18); 

                auto tey_xy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 18); 

                auto tez_xy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 18); 

                auto tex_xy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 19); 

                auto tey_xy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 19); 

                auto tez_xy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 19); 

                auto tex_xz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 20); 

                auto tey_xz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 20); 

                auto tez_xz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 20); 

                auto tex_xz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 21); 

                auto tey_xz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 21); 

                auto tez_xz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 21); 

                auto tex_xz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 22); 

                auto tey_xz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 22); 

                auto tez_xz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 22); 

                auto tex_xz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 23); 

                auto tey_xz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 23); 

                auto tez_xz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 23); 

                auto tex_xz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 24); 

                auto tey_xz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 24); 

                auto tez_xz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 24); 

                auto tex_xz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 25); 

                auto tey_xz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 25); 

                auto tez_xz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 25); 

                auto tex_xz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 26); 

                auto tey_xz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 26); 

                auto tez_xz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 26); 

                auto tex_xz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 27); 

                auto tey_xz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 27); 

                auto tez_xz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 27); 

                auto tex_xz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 28); 

                auto tey_xz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 28); 

                auto tez_xz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 28); 

                auto tex_xz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 29); 

                auto tey_xz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 29); 

                auto tez_xz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 29); 

                auto tex_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 30); 

                auto tey_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 30); 

                auto tez_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 30); 

                auto tex_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 31); 

                auto tey_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 31); 

                auto tez_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 31); 

                auto tex_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 32); 

                auto tey_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 32); 

                auto tez_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 32); 

                auto tex_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 33); 

                auto tez_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 16); 

                auto tex_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 17); 

                auto tey_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 17); 

                auto tez_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 17); 

                auto tex_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 18); 

                auto tey_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 18); 

                auto tez_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 18); 

                auto tex_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 19); 

                auto tey_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 19); 

                auto tez_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 19); 

                auto tex_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 20); 

                auto tey_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 21); 

                auto tey_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 22); 

                auto tey_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 23); 

                auto tey_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 24); 

                auto tey_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 25); 

                auto tey_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 26); 

                auto tey_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 27); 

                auto tey_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 28); 

                auto tey_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 29); 

                auto tey_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 29); 

                auto tez_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 16); 

                auto tex_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 17); 

                auto tey_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 17); 

                auto tez_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 17); 

                auto tex_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 18); 

                auto tey_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 18); 

                auto tez_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 18); 

                auto tex_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 19); 

                auto tey_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 19); 

                auto tez_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 19); 

                auto tex_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 20); 

                auto tey_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 21); 

                auto tey_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 22); 

                auto tey_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 23); 

                auto tey_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 24); 

                auto tey_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 25); 

                auto tey_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 26); 

                auto tey_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 27); 

                auto tey_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 28); 

                auto tey_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 29); 

                auto tey_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 29); 

                auto tex_xz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 12); 

                auto tey_xz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 12); 

                auto tez_xz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 12); 

                auto tex_xz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 13); 

                auto tey_xz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 13); 

                auto tez_xz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 13); 

                auto tex_xz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 14); 

                auto tey_xz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 14); 

                auto tez_xz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 14); 

                auto tex_xz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 15); 

                auto tey_xz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 15); 

                auto tez_xz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 15); 

                auto tex_xz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 16); 

                auto tey_xz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 16); 

                auto tez_xz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 16); 

                auto tex_xz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 17); 

                auto tey_xz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 17); 

                auto tez_xz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 17); 

                auto tex_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 18); 

                auto tey_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 18); 

                auto tez_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 18); 

                auto tex_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 19); 

                auto tey_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 19); 

                auto tez_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 19); 

                auto tex_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 20); 

                auto tey_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 20); 

                auto tez_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 20); 

                auto tex_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 21); 

                auto tex_xz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 12); 

                auto tey_xz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 12); 

                auto tez_xz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 12); 

                auto tex_xz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 13); 

                auto tey_xz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 13); 

                auto tez_xz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 13); 

                auto tex_xz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 14); 

                auto tey_xz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 14); 

                auto tez_xz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 14); 

                auto tex_xz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 15); 

                auto tey_xz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 15); 

                auto tez_xz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 15); 

                auto tex_xz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 16); 

                auto tey_xz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 16); 

                auto tez_xz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 16); 

                auto tex_xz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 17); 

                auto tey_xz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 17); 

                auto tez_xz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 17); 

                auto tex_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 18); 

                auto tey_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 18); 

                auto tez_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 18); 

                auto tex_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 19); 

                auto tey_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 19); 

                auto tez_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 19); 

                auto tex_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 20); 

                auto tey_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 20); 

                auto tez_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 20); 

                auto tex_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 21); 

                auto ta_xy_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 17); 

                auto ta_xy_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 18); 

                auto ta_xy_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 19); 

                auto ta_xz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 20); 

                auto ta_xz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 21); 

                auto ta_xz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 22); 

                auto ta_xz_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 23); 

                auto ta_xz_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 24); 

                auto ta_xz_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 25); 

                auto ta_xz_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 26); 

                auto ta_xz_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 27); 

                auto ta_xz_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 28); 

                auto ta_xz_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 29); 

                auto ta_yy_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 30); 

                auto ta_yy_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 31); 

                auto ta_yy_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 32); 

                auto ta_yy_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 33); 

                // set up pointers to integrals

                auto tez_xxy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 16); 

                auto tex_xxy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 17); 

                auto tey_xxy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 17); 

                auto tez_xxy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 17); 

                auto tex_xxy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 18); 

                auto tey_xxy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 18); 

                auto tez_xxy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 18); 

                auto tex_xxy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 19); 

                auto tey_xxy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 19); 

                auto tez_xxy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 19); 

                auto tex_xxz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 20); 

                auto tey_xxz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 20); 

                auto tez_xxz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 20); 

                auto tex_xxz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 21); 

                auto tey_xxz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 21); 

                auto tez_xxz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 21); 

                auto tex_xxz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 22); 

                auto tey_xxz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 22); 

                auto tez_xxz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 22); 

                auto tex_xxz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 23); 

                auto tey_xxz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 23); 

                auto tez_xxz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 23); 

                auto tex_xxz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 24); 

                auto tey_xxz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 24); 

                auto tez_xxz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 24); 

                auto tex_xxz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 25); 

                auto tey_xxz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 25); 

                auto tez_xxz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 25); 

                auto tex_xxz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 26); 

                auto tey_xxz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 26); 

                auto tez_xxz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 26); 

                auto tex_xxz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 27); 

                auto tey_xxz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 27); 

                auto tez_xxz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 27); 

                auto tex_xxz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 28); 

                auto tey_xxz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 28); 

                auto tez_xxz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 28); 

                auto tex_xxz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 29); 

                auto tey_xxz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 29); 

                auto tez_xxz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 29); 

                auto tex_xyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 30); 

                auto tey_xyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 30); 

                auto tez_xyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 30); 

                auto tex_xyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 31); 

                auto tey_xyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 31); 

                auto tez_xyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 31); 

                auto tex_xyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 32); 

                auto tey_xyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 32); 

                auto tez_xyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 32); 

                auto tex_xyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 33); 

                // Batch of Integrals (50,100)

                #pragma omp simd aligned(fx, pa_x, pc_x, ta_xy_yyz_1, ta_xy_yzz_1, ta_xy_zzz_1, ta_xz_xxx_1, \
                                         ta_xz_xxy_1, ta_xz_xxz_1, ta_xz_xyy_1, ta_xz_xyz_1, ta_xz_xzz_1, ta_xz_yyy_1, \
                                         ta_xz_yyz_1, ta_xz_yzz_1, ta_xz_zzz_1, ta_yy_xxx_1, ta_yy_xxy_1, ta_yy_xxz_1, \
                                         ta_yy_xyy_1, tex_xxy_yyz_0, tex_xxy_yzz_0, tex_xxy_zzz_0, tex_xxz_xxx_0, \
                                         tex_xxz_xxy_0, tex_xxz_xxz_0, tex_xxz_xyy_0, tex_xxz_xyz_0, tex_xxz_xzz_0, \
                                         tex_xxz_yyy_0, tex_xxz_yyz_0, tex_xxz_yzz_0, tex_xxz_zzz_0, tex_xy_yyz_0, \
                                         tex_xy_yyz_1, tex_xy_yzz_0, tex_xy_yzz_1, tex_xy_zzz_0, tex_xy_zzz_1, \
                                         tex_xyy_xxx_0, tex_xyy_xxy_0, tex_xyy_xxz_0, tex_xyy_xyy_0, tex_xz_xx_0, \
                                         tex_xz_xx_1, tex_xz_xxx_0, tex_xz_xxx_1, tex_xz_xxy_0, tex_xz_xxy_1, tex_xz_xxz_0, \
                                         tex_xz_xxz_1, tex_xz_xy_0, tex_xz_xy_1, tex_xz_xyy_0, tex_xz_xyy_1, tex_xz_xyz_0, \
                                         tex_xz_xyz_1, tex_xz_xz_0, tex_xz_xz_1, tex_xz_xzz_0, tex_xz_xzz_1, tex_xz_yy_0, \
                                         tex_xz_yy_1, tex_xz_yyy_0, tex_xz_yyy_1, tex_xz_yyz_0, tex_xz_yyz_1, tex_xz_yz_0, \
                                         tex_xz_yz_1, tex_xz_yzz_0, tex_xz_yzz_1, tex_xz_zz_0, tex_xz_zz_1, tex_xz_zzz_0, \
                                         tex_xz_zzz_1, tex_y_yyz_0, tex_y_yyz_1, tex_y_yzz_0, tex_y_yzz_1, tex_y_zzz_0, \
                                         tex_y_zzz_1, tex_yy_xx_0, tex_yy_xx_1, tex_yy_xxx_0, tex_yy_xxx_1, tex_yy_xxy_0, \
                                         tex_yy_xxy_1, tex_yy_xxz_0, tex_yy_xxz_1, tex_yy_xy_0, tex_yy_xy_1, tex_yy_xyy_0, \
                                         tex_yy_xyy_1, tex_yy_xz_0, tex_yy_xz_1, tex_yy_yy_0, tex_yy_yy_1, tex_z_xxx_0, \
                                         tex_z_xxx_1, tex_z_xxy_0, tex_z_xxy_1, tex_z_xxz_0, tex_z_xxz_1, tex_z_xyy_0, \
                                         tex_z_xyy_1, tex_z_xyz_0, tex_z_xyz_1, tex_z_xzz_0, tex_z_xzz_1, tex_z_yyy_0, \
                                         tex_z_yyy_1, tex_z_yyz_0, tex_z_yyz_1, tex_z_yzz_0, tex_z_yzz_1, tex_z_zzz_0, \
                                         tex_z_zzz_1, tey_xxy_yyz_0, tey_xxy_yzz_0, tey_xxy_zzz_0, tey_xxz_xxx_0, \
                                         tey_xxz_xxy_0, tey_xxz_xxz_0, tey_xxz_xyy_0, tey_xxz_xyz_0, tey_xxz_xzz_0, \
                                         tey_xxz_yyy_0, tey_xxz_yyz_0, tey_xxz_yzz_0, tey_xxz_zzz_0, tey_xy_yyz_0, \
                                         tey_xy_yyz_1, tey_xy_yzz_0, tey_xy_yzz_1, tey_xy_zzz_0, tey_xy_zzz_1, \
                                         tey_xyy_xxx_0, tey_xyy_xxy_0, tey_xyy_xxz_0, tey_xz_xx_0, tey_xz_xx_1, tey_xz_xxx_0, \
                                         tey_xz_xxx_1, tey_xz_xxy_0, tey_xz_xxy_1, tey_xz_xxz_0, tey_xz_xxz_1, tey_xz_xy_0, \
                                         tey_xz_xy_1, tey_xz_xyy_0, tey_xz_xyy_1, tey_xz_xyz_0, tey_xz_xyz_1, tey_xz_xz_0, \
                                         tey_xz_xz_1, tey_xz_xzz_0, tey_xz_xzz_1, tey_xz_yy_0, tey_xz_yy_1, tey_xz_yyy_0, \
                                         tey_xz_yyy_1, tey_xz_yyz_0, tey_xz_yyz_1, tey_xz_yz_0, tey_xz_yz_1, tey_xz_yzz_0, \
                                         tey_xz_yzz_1, tey_xz_zz_0, tey_xz_zz_1, tey_xz_zzz_0, tey_xz_zzz_1, tey_y_yyz_0, \
                                         tey_y_yyz_1, tey_y_yzz_0, tey_y_yzz_1, tey_y_zzz_0, tey_y_zzz_1, tey_yy_xx_0, \
                                         tey_yy_xx_1, tey_yy_xxx_0, tey_yy_xxx_1, tey_yy_xxy_0, tey_yy_xxy_1, tey_yy_xxz_0, \
                                         tey_yy_xxz_1, tey_yy_xy_0, tey_yy_xy_1, tey_yy_xz_0, tey_yy_xz_1, tey_z_xxx_0, \
                                         tey_z_xxx_1, tey_z_xxy_0, tey_z_xxy_1, tey_z_xxz_0, tey_z_xxz_1, tey_z_xyy_0, \
                                         tey_z_xyy_1, tey_z_xyz_0, tey_z_xyz_1, tey_z_xzz_0, tey_z_xzz_1, tey_z_yyy_0, \
                                         tey_z_yyy_1, tey_z_yyz_0, tey_z_yyz_1, tey_z_yzz_0, tey_z_yzz_1, tey_z_zzz_0, \
                                         tey_z_zzz_1, tez_xxy_yyy_0, tez_xxy_yyz_0, tez_xxy_yzz_0, tez_xxy_zzz_0, \
                                         tez_xxz_xxx_0, tez_xxz_xxy_0, tez_xxz_xxz_0, tez_xxz_xyy_0, tez_xxz_xyz_0, \
                                         tez_xxz_xzz_0, tez_xxz_yyy_0, tez_xxz_yyz_0, tez_xxz_yzz_0, tez_xxz_zzz_0, \
                                         tez_xy_yyy_0, tez_xy_yyy_1, tez_xy_yyz_0, tez_xy_yyz_1, tez_xy_yzz_0, tez_xy_yzz_1, \
                                         tez_xy_zzz_0, tez_xy_zzz_1, tez_xyy_xxx_0, tez_xyy_xxy_0, tez_xyy_xxz_0, \
                                         tez_xz_xx_0, tez_xz_xx_1, tez_xz_xxx_0, tez_xz_xxx_1, tez_xz_xxy_0, tez_xz_xxy_1, \
                                         tez_xz_xxz_0, tez_xz_xxz_1, tez_xz_xy_0, tez_xz_xy_1, tez_xz_xyy_0, tez_xz_xyy_1, \
                                         tez_xz_xyz_0, tez_xz_xyz_1, tez_xz_xz_0, tez_xz_xz_1, tez_xz_xzz_0, tez_xz_xzz_1, \
                                         tez_xz_yy_0, tez_xz_yy_1, tez_xz_yyy_0, tez_xz_yyy_1, tez_xz_yyz_0, tez_xz_yyz_1, \
                                         tez_xz_yz_0, tez_xz_yz_1, tez_xz_yzz_0, tez_xz_yzz_1, tez_xz_zz_0, tez_xz_zz_1, \
                                         tez_xz_zzz_0, tez_xz_zzz_1, tez_y_yyy_0, tez_y_yyy_1, tez_y_yyz_0, tez_y_yyz_1, \
                                         tez_y_yzz_0, tez_y_yzz_1, tez_y_zzz_0, tez_y_zzz_1, tez_yy_xx_0, tez_yy_xx_1, \
                                         tez_yy_xxx_0, tez_yy_xxx_1, tez_yy_xxy_0, tez_yy_xxy_1, tez_yy_xxz_0, tez_yy_xxz_1, \
                                         tez_yy_xy_0, tez_yy_xy_1, tez_yy_xz_0, tez_yy_xz_1, tez_z_xxx_0, tez_z_xxx_1, \
                                         tez_z_xxy_0, tez_z_xxy_1, tez_z_xxz_0, tez_z_xxz_1, tez_z_xyy_0, tez_z_xyy_1, \
                                         tez_z_xyz_0, tez_z_xyz_1, tez_z_xzz_0, tez_z_xzz_1, tez_z_yyy_0, tez_z_yyy_1, \
                                         tez_z_yyz_0, tez_z_yyz_1, tez_z_yzz_0, tez_z_yzz_1, tez_z_zzz_0, tez_z_zzz_1: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tez_xxy_yyy_0[j] = pa_x[j] * tez_xy_yyy_0[j] - pc_x[j] * tez_xy_yyy_1[j] + 0.5 * fl1_fx * tez_y_yyy_0[j] - 0.5 * fl1_fx * tez_y_yyy_1[j];

                    tex_xxy_yyz_0[j] = pa_x[j] * tex_xy_yyz_0[j] - pc_x[j] * tex_xy_yyz_1[j] + 0.5 * fl1_fx * tex_y_yyz_0[j] - 0.5 * fl1_fx * tex_y_yyz_1[j] + ta_xy_yyz_1[j];

                    tey_xxy_yyz_0[j] = pa_x[j] * tey_xy_yyz_0[j] - pc_x[j] * tey_xy_yyz_1[j] + 0.5 * fl1_fx * tey_y_yyz_0[j] - 0.5 * fl1_fx * tey_y_yyz_1[j];

                    tez_xxy_yyz_0[j] = pa_x[j] * tez_xy_yyz_0[j] - pc_x[j] * tez_xy_yyz_1[j] + 0.5 * fl1_fx * tez_y_yyz_0[j] - 0.5 * fl1_fx * tez_y_yyz_1[j];

                    tex_xxy_yzz_0[j] = pa_x[j] * tex_xy_yzz_0[j] - pc_x[j] * tex_xy_yzz_1[j] + 0.5 * fl1_fx * tex_y_yzz_0[j] - 0.5 * fl1_fx * tex_y_yzz_1[j] + ta_xy_yzz_1[j];

                    tey_xxy_yzz_0[j] = pa_x[j] * tey_xy_yzz_0[j] - pc_x[j] * tey_xy_yzz_1[j] + 0.5 * fl1_fx * tey_y_yzz_0[j] - 0.5 * fl1_fx * tey_y_yzz_1[j];

                    tez_xxy_yzz_0[j] = pa_x[j] * tez_xy_yzz_0[j] - pc_x[j] * tez_xy_yzz_1[j] + 0.5 * fl1_fx * tez_y_yzz_0[j] - 0.5 * fl1_fx * tez_y_yzz_1[j];

                    tex_xxy_zzz_0[j] = pa_x[j] * tex_xy_zzz_0[j] - pc_x[j] * tex_xy_zzz_1[j] + 0.5 * fl1_fx * tex_y_zzz_0[j] - 0.5 * fl1_fx * tex_y_zzz_1[j] + ta_xy_zzz_1[j];

                    tey_xxy_zzz_0[j] = pa_x[j] * tey_xy_zzz_0[j] - pc_x[j] * tey_xy_zzz_1[j] + 0.5 * fl1_fx * tey_y_zzz_0[j] - 0.5 * fl1_fx * tey_y_zzz_1[j];

                    tez_xxy_zzz_0[j] = pa_x[j] * tez_xy_zzz_0[j] - pc_x[j] * tez_xy_zzz_1[j] + 0.5 * fl1_fx * tez_y_zzz_0[j] - 0.5 * fl1_fx * tez_y_zzz_1[j];

                    tex_xxz_xxx_0[j] = pa_x[j] * tex_xz_xxx_0[j] - pc_x[j] * tex_xz_xxx_1[j] + 0.5 * fl1_fx * tex_z_xxx_0[j] - 0.5 * fl1_fx * tex_z_xxx_1[j] + 1.5 * fl1_fx * tex_xz_xx_0[j] - 1.5 * fl1_fx * tex_xz_xx_1[j] + ta_xz_xxx_1[j];

                    tey_xxz_xxx_0[j] = pa_x[j] * tey_xz_xxx_0[j] - pc_x[j] * tey_xz_xxx_1[j] + 0.5 * fl1_fx * tey_z_xxx_0[j] - 0.5 * fl1_fx * tey_z_xxx_1[j] + 1.5 * fl1_fx * tey_xz_xx_0[j] - 1.5 * fl1_fx * tey_xz_xx_1[j];

                    tez_xxz_xxx_0[j] = pa_x[j] * tez_xz_xxx_0[j] - pc_x[j] * tez_xz_xxx_1[j] + 0.5 * fl1_fx * tez_z_xxx_0[j] - 0.5 * fl1_fx * tez_z_xxx_1[j] + 1.5 * fl1_fx * tez_xz_xx_0[j] - 1.5 * fl1_fx * tez_xz_xx_1[j];

                    tex_xxz_xxy_0[j] = pa_x[j] * tex_xz_xxy_0[j] - pc_x[j] * tex_xz_xxy_1[j] + 0.5 * fl1_fx * tex_z_xxy_0[j] - 0.5 * fl1_fx * tex_z_xxy_1[j] + fl1_fx * tex_xz_xy_0[j] - fl1_fx * tex_xz_xy_1[j] + ta_xz_xxy_1[j];

                    tey_xxz_xxy_0[j] = pa_x[j] * tey_xz_xxy_0[j] - pc_x[j] * tey_xz_xxy_1[j] + 0.5 * fl1_fx * tey_z_xxy_0[j] - 0.5 * fl1_fx * tey_z_xxy_1[j] + fl1_fx * tey_xz_xy_0[j] - fl1_fx * tey_xz_xy_1[j];

                    tez_xxz_xxy_0[j] = pa_x[j] * tez_xz_xxy_0[j] - pc_x[j] * tez_xz_xxy_1[j] + 0.5 * fl1_fx * tez_z_xxy_0[j] - 0.5 * fl1_fx * tez_z_xxy_1[j] + fl1_fx * tez_xz_xy_0[j] - fl1_fx * tez_xz_xy_1[j];

                    tex_xxz_xxz_0[j] = pa_x[j] * tex_xz_xxz_0[j] - pc_x[j] * tex_xz_xxz_1[j] + 0.5 * fl1_fx * tex_z_xxz_0[j] - 0.5 * fl1_fx * tex_z_xxz_1[j] + fl1_fx * tex_xz_xz_0[j] - fl1_fx * tex_xz_xz_1[j] + ta_xz_xxz_1[j];

                    tey_xxz_xxz_0[j] = pa_x[j] * tey_xz_xxz_0[j] - pc_x[j] * tey_xz_xxz_1[j] + 0.5 * fl1_fx * tey_z_xxz_0[j] - 0.5 * fl1_fx * tey_z_xxz_1[j] + fl1_fx * tey_xz_xz_0[j] - fl1_fx * tey_xz_xz_1[j];

                    tez_xxz_xxz_0[j] = pa_x[j] * tez_xz_xxz_0[j] - pc_x[j] * tez_xz_xxz_1[j] + 0.5 * fl1_fx * tez_z_xxz_0[j] - 0.5 * fl1_fx * tez_z_xxz_1[j] + fl1_fx * tez_xz_xz_0[j] - fl1_fx * tez_xz_xz_1[j];

                    tex_xxz_xyy_0[j] = pa_x[j] * tex_xz_xyy_0[j] - pc_x[j] * tex_xz_xyy_1[j] + 0.5 * fl1_fx * tex_z_xyy_0[j] - 0.5 * fl1_fx * tex_z_xyy_1[j] + 0.5 * fl1_fx * tex_xz_yy_0[j] - 0.5 * fl1_fx * tex_xz_yy_1[j] + ta_xz_xyy_1[j];

                    tey_xxz_xyy_0[j] = pa_x[j] * tey_xz_xyy_0[j] - pc_x[j] * tey_xz_xyy_1[j] + 0.5 * fl1_fx * tey_z_xyy_0[j] - 0.5 * fl1_fx * tey_z_xyy_1[j] + 0.5 * fl1_fx * tey_xz_yy_0[j] - 0.5 * fl1_fx * tey_xz_yy_1[j];

                    tez_xxz_xyy_0[j] = pa_x[j] * tez_xz_xyy_0[j] - pc_x[j] * tez_xz_xyy_1[j] + 0.5 * fl1_fx * tez_z_xyy_0[j] - 0.5 * fl1_fx * tez_z_xyy_1[j] + 0.5 * fl1_fx * tez_xz_yy_0[j] - 0.5 * fl1_fx * tez_xz_yy_1[j];

                    tex_xxz_xyz_0[j] = pa_x[j] * tex_xz_xyz_0[j] - pc_x[j] * tex_xz_xyz_1[j] + 0.5 * fl1_fx * tex_z_xyz_0[j] - 0.5 * fl1_fx * tex_z_xyz_1[j] + 0.5 * fl1_fx * tex_xz_yz_0[j] - 0.5 * fl1_fx * tex_xz_yz_1[j] + ta_xz_xyz_1[j];

                    tey_xxz_xyz_0[j] = pa_x[j] * tey_xz_xyz_0[j] - pc_x[j] * tey_xz_xyz_1[j] + 0.5 * fl1_fx * tey_z_xyz_0[j] - 0.5 * fl1_fx * tey_z_xyz_1[j] + 0.5 * fl1_fx * tey_xz_yz_0[j] - 0.5 * fl1_fx * tey_xz_yz_1[j];

                    tez_xxz_xyz_0[j] = pa_x[j] * tez_xz_xyz_0[j] - pc_x[j] * tez_xz_xyz_1[j] + 0.5 * fl1_fx * tez_z_xyz_0[j] - 0.5 * fl1_fx * tez_z_xyz_1[j] + 0.5 * fl1_fx * tez_xz_yz_0[j] - 0.5 * fl1_fx * tez_xz_yz_1[j];

                    tex_xxz_xzz_0[j] = pa_x[j] * tex_xz_xzz_0[j] - pc_x[j] * tex_xz_xzz_1[j] + 0.5 * fl1_fx * tex_z_xzz_0[j] - 0.5 * fl1_fx * tex_z_xzz_1[j] + 0.5 * fl1_fx * tex_xz_zz_0[j] - 0.5 * fl1_fx * tex_xz_zz_1[j] + ta_xz_xzz_1[j];

                    tey_xxz_xzz_0[j] = pa_x[j] * tey_xz_xzz_0[j] - pc_x[j] * tey_xz_xzz_1[j] + 0.5 * fl1_fx * tey_z_xzz_0[j] - 0.5 * fl1_fx * tey_z_xzz_1[j] + 0.5 * fl1_fx * tey_xz_zz_0[j] - 0.5 * fl1_fx * tey_xz_zz_1[j];

                    tez_xxz_xzz_0[j] = pa_x[j] * tez_xz_xzz_0[j] - pc_x[j] * tez_xz_xzz_1[j] + 0.5 * fl1_fx * tez_z_xzz_0[j] - 0.5 * fl1_fx * tez_z_xzz_1[j] + 0.5 * fl1_fx * tez_xz_zz_0[j] - 0.5 * fl1_fx * tez_xz_zz_1[j];

                    tex_xxz_yyy_0[j] = pa_x[j] * tex_xz_yyy_0[j] - pc_x[j] * tex_xz_yyy_1[j] + 0.5 * fl1_fx * tex_z_yyy_0[j] - 0.5 * fl1_fx * tex_z_yyy_1[j] + ta_xz_yyy_1[j];

                    tey_xxz_yyy_0[j] = pa_x[j] * tey_xz_yyy_0[j] - pc_x[j] * tey_xz_yyy_1[j] + 0.5 * fl1_fx * tey_z_yyy_0[j] - 0.5 * fl1_fx * tey_z_yyy_1[j];

                    tez_xxz_yyy_0[j] = pa_x[j] * tez_xz_yyy_0[j] - pc_x[j] * tez_xz_yyy_1[j] + 0.5 * fl1_fx * tez_z_yyy_0[j] - 0.5 * fl1_fx * tez_z_yyy_1[j];

                    tex_xxz_yyz_0[j] = pa_x[j] * tex_xz_yyz_0[j] - pc_x[j] * tex_xz_yyz_1[j] + 0.5 * fl1_fx * tex_z_yyz_0[j] - 0.5 * fl1_fx * tex_z_yyz_1[j] + ta_xz_yyz_1[j];

                    tey_xxz_yyz_0[j] = pa_x[j] * tey_xz_yyz_0[j] - pc_x[j] * tey_xz_yyz_1[j] + 0.5 * fl1_fx * tey_z_yyz_0[j] - 0.5 * fl1_fx * tey_z_yyz_1[j];

                    tez_xxz_yyz_0[j] = pa_x[j] * tez_xz_yyz_0[j] - pc_x[j] * tez_xz_yyz_1[j] + 0.5 * fl1_fx * tez_z_yyz_0[j] - 0.5 * fl1_fx * tez_z_yyz_1[j];

                    tex_xxz_yzz_0[j] = pa_x[j] * tex_xz_yzz_0[j] - pc_x[j] * tex_xz_yzz_1[j] + 0.5 * fl1_fx * tex_z_yzz_0[j] - 0.5 * fl1_fx * tex_z_yzz_1[j] + ta_xz_yzz_1[j];

                    tey_xxz_yzz_0[j] = pa_x[j] * tey_xz_yzz_0[j] - pc_x[j] * tey_xz_yzz_1[j] + 0.5 * fl1_fx * tey_z_yzz_0[j] - 0.5 * fl1_fx * tey_z_yzz_1[j];

                    tez_xxz_yzz_0[j] = pa_x[j] * tez_xz_yzz_0[j] - pc_x[j] * tez_xz_yzz_1[j] + 0.5 * fl1_fx * tez_z_yzz_0[j] - 0.5 * fl1_fx * tez_z_yzz_1[j];

                    tex_xxz_zzz_0[j] = pa_x[j] * tex_xz_zzz_0[j] - pc_x[j] * tex_xz_zzz_1[j] + 0.5 * fl1_fx * tex_z_zzz_0[j] - 0.5 * fl1_fx * tex_z_zzz_1[j] + ta_xz_zzz_1[j];

                    tey_xxz_zzz_0[j] = pa_x[j] * tey_xz_zzz_0[j] - pc_x[j] * tey_xz_zzz_1[j] + 0.5 * fl1_fx * tey_z_zzz_0[j] - 0.5 * fl1_fx * tey_z_zzz_1[j];

                    tez_xxz_zzz_0[j] = pa_x[j] * tez_xz_zzz_0[j] - pc_x[j] * tez_xz_zzz_1[j] + 0.5 * fl1_fx * tez_z_zzz_0[j] - 0.5 * fl1_fx * tez_z_zzz_1[j];

                    tex_xyy_xxx_0[j] = pa_x[j] * tex_yy_xxx_0[j] - pc_x[j] * tex_yy_xxx_1[j] + 1.5 * fl1_fx * tex_yy_xx_0[j] - 1.5 * fl1_fx * tex_yy_xx_1[j] + ta_yy_xxx_1[j];

                    tey_xyy_xxx_0[j] = pa_x[j] * tey_yy_xxx_0[j] - pc_x[j] * tey_yy_xxx_1[j] + 1.5 * fl1_fx * tey_yy_xx_0[j] - 1.5 * fl1_fx * tey_yy_xx_1[j];

                    tez_xyy_xxx_0[j] = pa_x[j] * tez_yy_xxx_0[j] - pc_x[j] * tez_yy_xxx_1[j] + 1.5 * fl1_fx * tez_yy_xx_0[j] - 1.5 * fl1_fx * tez_yy_xx_1[j];

                    tex_xyy_xxy_0[j] = pa_x[j] * tex_yy_xxy_0[j] - pc_x[j] * tex_yy_xxy_1[j] + fl1_fx * tex_yy_xy_0[j] - fl1_fx * tex_yy_xy_1[j] + ta_yy_xxy_1[j];

                    tey_xyy_xxy_0[j] = pa_x[j] * tey_yy_xxy_0[j] - pc_x[j] * tey_yy_xxy_1[j] + fl1_fx * tey_yy_xy_0[j] - fl1_fx * tey_yy_xy_1[j];

                    tez_xyy_xxy_0[j] = pa_x[j] * tez_yy_xxy_0[j] - pc_x[j] * tez_yy_xxy_1[j] + fl1_fx * tez_yy_xy_0[j] - fl1_fx * tez_yy_xy_1[j];

                    tex_xyy_xxz_0[j] = pa_x[j] * tex_yy_xxz_0[j] - pc_x[j] * tex_yy_xxz_1[j] + fl1_fx * tex_yy_xz_0[j] - fl1_fx * tex_yy_xz_1[j] + ta_yy_xxz_1[j];

                    tey_xyy_xxz_0[j] = pa_x[j] * tey_yy_xxz_0[j] - pc_x[j] * tey_yy_xxz_1[j] + fl1_fx * tey_yy_xz_0[j] - fl1_fx * tey_yy_xz_1[j];

                    tez_xyy_xxz_0[j] = pa_x[j] * tez_yy_xxz_0[j] - pc_x[j] * tez_yy_xxz_1[j] + fl1_fx * tez_yy_xz_0[j] - fl1_fx * tez_yy_xz_1[j];

                    tex_xyy_xyy_0[j] = pa_x[j] * tex_yy_xyy_0[j] - pc_x[j] * tex_yy_xyy_1[j] + 0.5 * fl1_fx * tex_yy_yy_0[j] - 0.5 * fl1_fx * tex_yy_yy_1[j] + ta_yy_xyy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectricFieldForFF_100_150(      CMemBlock2D<double>& primBuffer,
                                   const CRecursionMap&       recursionMap,
                                   const CMemBlock2D<double>& osFactors,
                                   const CMemBlock2D<double>& paDistances,
                                   const CMemBlock2D<double>& pcDistances,
                                   const CGtoBlock&           braGtoBlock,
                                   const CGtoBlock&           ketGtoBlock,
                                   const int32_t              iContrGto)
    {
        // Batch of Integrals (100,150)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_x = paDistances.data(3 * idx);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_x = pcDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tey_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 33); 

                auto tez_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 33); 

                auto tex_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 34); 

                auto tey_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 34); 

                auto tez_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 34); 

                auto tex_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 35); 

                auto tey_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 35); 

                auto tez_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 35); 

                auto tex_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 36); 

                auto tey_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 36); 

                auto tez_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 36); 

                auto tex_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 37); 

                auto tey_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 37); 

                auto tez_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 37); 

                auto tex_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 38); 

                auto tey_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 38); 

                auto tez_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 38); 

                auto tex_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 39); 

                auto tey_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 39); 

                auto tez_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 39); 

                auto tex_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 40); 

                auto tey_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 40); 

                auto tez_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 40); 

                auto tex_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 41); 

                auto tey_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 41); 

                auto tez_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 41); 

                auto tex_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 42); 

                auto tey_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 42); 

                auto tez_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 42); 

                auto tex_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 43); 

                auto tey_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 43); 

                auto tez_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 43); 

                auto tex_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 44); 

                auto tey_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 44); 

                auto tez_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 44); 

                auto tex_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 45); 

                auto tey_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 45); 

                auto tez_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 45); 

                auto tex_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 46); 

                auto tey_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 46); 

                auto tez_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 46); 

                auto tex_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 47); 

                auto tey_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 47); 

                auto tez_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 47); 

                auto tex_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 48); 

                auto tey_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 48); 

                auto tez_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 48); 

                auto tex_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 49); 

                auto tey_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 49); 

                auto tez_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 49); 

                auto tey_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 33); 

                auto tez_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 33); 

                auto tex_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 34); 

                auto tey_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 34); 

                auto tez_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 34); 

                auto tex_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 35); 

                auto tey_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 35); 

                auto tez_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 35); 

                auto tex_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 36); 

                auto tey_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 36); 

                auto tez_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 36); 

                auto tex_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 37); 

                auto tey_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 37); 

                auto tez_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 37); 

                auto tex_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 38); 

                auto tey_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 38); 

                auto tez_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 38); 

                auto tex_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 39); 

                auto tey_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 39); 

                auto tez_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 39); 

                auto tex_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 40); 

                auto tey_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 40); 

                auto tez_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 40); 

                auto tex_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 41); 

                auto tey_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 41); 

                auto tez_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 41); 

                auto tex_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 42); 

                auto tey_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 42); 

                auto tez_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 42); 

                auto tex_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 43); 

                auto tey_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 43); 

                auto tez_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 43); 

                auto tex_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 44); 

                auto tey_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 44); 

                auto tez_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 44); 

                auto tex_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 45); 

                auto tey_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 45); 

                auto tez_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 45); 

                auto tex_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 46); 

                auto tey_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 46); 

                auto tez_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 46); 

                auto tex_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 47); 

                auto tey_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 47); 

                auto tez_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 47); 

                auto tex_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 48); 

                auto tey_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 48); 

                auto tez_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 48); 

                auto tex_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 49); 

                auto tey_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 49); 

                auto tez_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 49); 

                auto tey_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 21); 

                auto tez_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 21); 

                auto tex_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 22); 

                auto tey_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 22); 

                auto tez_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 22); 

                auto tex_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 23); 

                auto tey_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 23); 

                auto tez_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 23); 

                auto tex_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 24); 

                auto tey_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 24); 

                auto tez_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 24); 

                auto tex_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 25); 

                auto tey_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 25); 

                auto tez_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 25); 

                auto tex_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 26); 

                auto tey_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 26); 

                auto tez_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 26); 

                auto tex_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 27); 

                auto tey_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 27); 

                auto tez_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 27); 

                auto tex_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 28); 

                auto tey_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 28); 

                auto tez_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 28); 

                auto tex_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 29); 

                auto tey_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 29); 

                auto tez_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 29); 

                auto tey_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 21); 

                auto tez_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 21); 

                auto tex_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 22); 

                auto tey_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 22); 

                auto tez_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 22); 

                auto tex_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 23); 

                auto tey_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 23); 

                auto tez_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 23); 

                auto tex_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 24); 

                auto tey_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 24); 

                auto tez_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 24); 

                auto tex_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 25); 

                auto tey_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 25); 

                auto tez_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 25); 

                auto tex_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 26); 

                auto tey_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 26); 

                auto tez_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 26); 

                auto tex_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 27); 

                auto tey_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 27); 

                auto tez_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 27); 

                auto tex_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 28); 

                auto tey_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 28); 

                auto tez_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 28); 

                auto tex_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 29); 

                auto tey_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 29); 

                auto tez_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 29); 

                auto ta_yy_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 34); 

                auto ta_yy_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 35); 

                auto ta_yy_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 36); 

                auto ta_yy_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 37); 

                auto ta_yy_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 38); 

                auto ta_yy_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 39); 

                auto ta_yz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 40); 

                auto ta_yz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 41); 

                auto ta_yz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 42); 

                auto ta_yz_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 43); 

                auto ta_yz_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 44); 

                auto ta_yz_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 45); 

                auto ta_yz_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 46); 

                auto ta_yz_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 47); 

                auto ta_yz_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 48); 

                auto ta_yz_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 49); 

                // set up pointers to integrals

                auto tey_xyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 33); 

                auto tez_xyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 33); 

                auto tex_xyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 34); 

                auto tey_xyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 34); 

                auto tez_xyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 34); 

                auto tex_xyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 35); 

                auto tey_xyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 35); 

                auto tez_xyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 35); 

                auto tex_xyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 36); 

                auto tey_xyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 36); 

                auto tez_xyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 36); 

                auto tex_xyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 37); 

                auto tey_xyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 37); 

                auto tez_xyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 37); 

                auto tex_xyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 38); 

                auto tey_xyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 38); 

                auto tez_xyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 38); 

                auto tex_xyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 39); 

                auto tey_xyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 39); 

                auto tez_xyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 39); 

                auto tex_xyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 40); 

                auto tey_xyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 40); 

                auto tez_xyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 40); 

                auto tex_xyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 41); 

                auto tey_xyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 41); 

                auto tez_xyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 41); 

                auto tex_xyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 42); 

                auto tey_xyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 42); 

                auto tez_xyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 42); 

                auto tex_xyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 43); 

                auto tey_xyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 43); 

                auto tez_xyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 43); 

                auto tex_xyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 44); 

                auto tey_xyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 44); 

                auto tez_xyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 44); 

                auto tex_xyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 45); 

                auto tey_xyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 45); 

                auto tez_xyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 45); 

                auto tex_xyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 46); 

                auto tey_xyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 46); 

                auto tez_xyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 46); 

                auto tex_xyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 47); 

                auto tey_xyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 47); 

                auto tez_xyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 47); 

                auto tex_xyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 48); 

                auto tey_xyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 48); 

                auto tez_xyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 48); 

                auto tex_xyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 49); 

                auto tey_xyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 49); 

                auto tez_xyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 49); 

                // Batch of Integrals (100,150)

                #pragma omp simd aligned(fx, pa_x, pc_x, ta_yy_xyz_1, ta_yy_xzz_1, ta_yy_yyy_1, ta_yy_yyz_1, \
                                         ta_yy_yzz_1, ta_yy_zzz_1, ta_yz_xxx_1, ta_yz_xxy_1, ta_yz_xxz_1, ta_yz_xyy_1, \
                                         ta_yz_xyz_1, ta_yz_xzz_1, ta_yz_yyy_1, ta_yz_yyz_1, ta_yz_yzz_1, ta_yz_zzz_1, \
                                         tex_xyy_xyz_0, tex_xyy_xzz_0, tex_xyy_yyy_0, tex_xyy_yyz_0, tex_xyy_yzz_0, \
                                         tex_xyy_zzz_0, tex_xyz_xxx_0, tex_xyz_xxy_0, tex_xyz_xxz_0, tex_xyz_xyy_0, \
                                         tex_xyz_xyz_0, tex_xyz_xzz_0, tex_xyz_yyy_0, tex_xyz_yyz_0, tex_xyz_yzz_0, \
                                         tex_xyz_zzz_0, tex_yy_xyz_0, tex_yy_xyz_1, tex_yy_xzz_0, tex_yy_xzz_1, tex_yy_yyy_0, \
                                         tex_yy_yyy_1, tex_yy_yyz_0, tex_yy_yyz_1, tex_yy_yz_0, tex_yy_yz_1, tex_yy_yzz_0, \
                                         tex_yy_yzz_1, tex_yy_zz_0, tex_yy_zz_1, tex_yy_zzz_0, tex_yy_zzz_1, tex_yz_xx_0, \
                                         tex_yz_xx_1, tex_yz_xxx_0, tex_yz_xxx_1, tex_yz_xxy_0, tex_yz_xxy_1, tex_yz_xxz_0, \
                                         tex_yz_xxz_1, tex_yz_xy_0, tex_yz_xy_1, tex_yz_xyy_0, tex_yz_xyy_1, tex_yz_xyz_0, \
                                         tex_yz_xyz_1, tex_yz_xz_0, tex_yz_xz_1, tex_yz_xzz_0, tex_yz_xzz_1, tex_yz_yy_0, \
                                         tex_yz_yy_1, tex_yz_yyy_0, tex_yz_yyy_1, tex_yz_yyz_0, tex_yz_yyz_1, tex_yz_yz_0, \
                                         tex_yz_yz_1, tex_yz_yzz_0, tex_yz_yzz_1, tex_yz_zz_0, tex_yz_zz_1, tex_yz_zzz_0, \
                                         tex_yz_zzz_1, tey_xyy_xyy_0, tey_xyy_xyz_0, tey_xyy_xzz_0, tey_xyy_yyy_0, \
                                         tey_xyy_yyz_0, tey_xyy_yzz_0, tey_xyy_zzz_0, tey_xyz_xxx_0, tey_xyz_xxy_0, \
                                         tey_xyz_xxz_0, tey_xyz_xyy_0, tey_xyz_xyz_0, tey_xyz_xzz_0, tey_xyz_yyy_0, \
                                         tey_xyz_yyz_0, tey_xyz_yzz_0, tey_xyz_zzz_0, tey_yy_xyy_0, tey_yy_xyy_1, \
                                         tey_yy_xyz_0, tey_yy_xyz_1, tey_yy_xzz_0, tey_yy_xzz_1, tey_yy_yy_0, tey_yy_yy_1, \
                                         tey_yy_yyy_0, tey_yy_yyy_1, tey_yy_yyz_0, tey_yy_yyz_1, tey_yy_yz_0, tey_yy_yz_1, \
                                         tey_yy_yzz_0, tey_yy_yzz_1, tey_yy_zz_0, tey_yy_zz_1, tey_yy_zzz_0, tey_yy_zzz_1, \
                                         tey_yz_xx_0, tey_yz_xx_1, tey_yz_xxx_0, tey_yz_xxx_1, tey_yz_xxy_0, tey_yz_xxy_1, \
                                         tey_yz_xxz_0, tey_yz_xxz_1, tey_yz_xy_0, tey_yz_xy_1, tey_yz_xyy_0, tey_yz_xyy_1, \
                                         tey_yz_xyz_0, tey_yz_xyz_1, tey_yz_xz_0, tey_yz_xz_1, tey_yz_xzz_0, tey_yz_xzz_1, \
                                         tey_yz_yy_0, tey_yz_yy_1, tey_yz_yyy_0, tey_yz_yyy_1, tey_yz_yyz_0, tey_yz_yyz_1, \
                                         tey_yz_yz_0, tey_yz_yz_1, tey_yz_yzz_0, tey_yz_yzz_1, tey_yz_zz_0, tey_yz_zz_1, \
                                         tey_yz_zzz_0, tey_yz_zzz_1, tez_xyy_xyy_0, tez_xyy_xyz_0, tez_xyy_xzz_0, \
                                         tez_xyy_yyy_0, tez_xyy_yyz_0, tez_xyy_yzz_0, tez_xyy_zzz_0, tez_xyz_xxx_0, \
                                         tez_xyz_xxy_0, tez_xyz_xxz_0, tez_xyz_xyy_0, tez_xyz_xyz_0, tez_xyz_xzz_0, \
                                         tez_xyz_yyy_0, tez_xyz_yyz_0, tez_xyz_yzz_0, tez_xyz_zzz_0, tez_yy_xyy_0, \
                                         tez_yy_xyy_1, tez_yy_xyz_0, tez_yy_xyz_1, tez_yy_xzz_0, tez_yy_xzz_1, tez_yy_yy_0, \
                                         tez_yy_yy_1, tez_yy_yyy_0, tez_yy_yyy_1, tez_yy_yyz_0, tez_yy_yyz_1, tez_yy_yz_0, \
                                         tez_yy_yz_1, tez_yy_yzz_0, tez_yy_yzz_1, tez_yy_zz_0, tez_yy_zz_1, tez_yy_zzz_0, \
                                         tez_yy_zzz_1, tez_yz_xx_0, tez_yz_xx_1, tez_yz_xxx_0, tez_yz_xxx_1, tez_yz_xxy_0, \
                                         tez_yz_xxy_1, tez_yz_xxz_0, tez_yz_xxz_1, tez_yz_xy_0, tez_yz_xy_1, tez_yz_xyy_0, \
                                         tez_yz_xyy_1, tez_yz_xyz_0, tez_yz_xyz_1, tez_yz_xz_0, tez_yz_xz_1, tez_yz_xzz_0, \
                                         tez_yz_xzz_1, tez_yz_yy_0, tez_yz_yy_1, tez_yz_yyy_0, tez_yz_yyy_1, tez_yz_yyz_0, \
                                         tez_yz_yyz_1, tez_yz_yz_0, tez_yz_yz_1, tez_yz_yzz_0, tez_yz_yzz_1, tez_yz_zz_0, \
                                         tez_yz_zz_1, tez_yz_zzz_0, tez_yz_zzz_1: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tey_xyy_xyy_0[j] = pa_x[j] * tey_yy_xyy_0[j] - pc_x[j] * tey_yy_xyy_1[j] + 0.5 * fl1_fx * tey_yy_yy_0[j] - 0.5 * fl1_fx * tey_yy_yy_1[j];

                    tez_xyy_xyy_0[j] = pa_x[j] * tez_yy_xyy_0[j] - pc_x[j] * tez_yy_xyy_1[j] + 0.5 * fl1_fx * tez_yy_yy_0[j] - 0.5 * fl1_fx * tez_yy_yy_1[j];

                    tex_xyy_xyz_0[j] = pa_x[j] * tex_yy_xyz_0[j] - pc_x[j] * tex_yy_xyz_1[j] + 0.5 * fl1_fx * tex_yy_yz_0[j] - 0.5 * fl1_fx * tex_yy_yz_1[j] + ta_yy_xyz_1[j];

                    tey_xyy_xyz_0[j] = pa_x[j] * tey_yy_xyz_0[j] - pc_x[j] * tey_yy_xyz_1[j] + 0.5 * fl1_fx * tey_yy_yz_0[j] - 0.5 * fl1_fx * tey_yy_yz_1[j];

                    tez_xyy_xyz_0[j] = pa_x[j] * tez_yy_xyz_0[j] - pc_x[j] * tez_yy_xyz_1[j] + 0.5 * fl1_fx * tez_yy_yz_0[j] - 0.5 * fl1_fx * tez_yy_yz_1[j];

                    tex_xyy_xzz_0[j] = pa_x[j] * tex_yy_xzz_0[j] - pc_x[j] * tex_yy_xzz_1[j] + 0.5 * fl1_fx * tex_yy_zz_0[j] - 0.5 * fl1_fx * tex_yy_zz_1[j] + ta_yy_xzz_1[j];

                    tey_xyy_xzz_0[j] = pa_x[j] * tey_yy_xzz_0[j] - pc_x[j] * tey_yy_xzz_1[j] + 0.5 * fl1_fx * tey_yy_zz_0[j] - 0.5 * fl1_fx * tey_yy_zz_1[j];

                    tez_xyy_xzz_0[j] = pa_x[j] * tez_yy_xzz_0[j] - pc_x[j] * tez_yy_xzz_1[j] + 0.5 * fl1_fx * tez_yy_zz_0[j] - 0.5 * fl1_fx * tez_yy_zz_1[j];

                    tex_xyy_yyy_0[j] = pa_x[j] * tex_yy_yyy_0[j] - pc_x[j] * tex_yy_yyy_1[j] + ta_yy_yyy_1[j];

                    tey_xyy_yyy_0[j] = pa_x[j] * tey_yy_yyy_0[j] - pc_x[j] * tey_yy_yyy_1[j];

                    tez_xyy_yyy_0[j] = pa_x[j] * tez_yy_yyy_0[j] - pc_x[j] * tez_yy_yyy_1[j];

                    tex_xyy_yyz_0[j] = pa_x[j] * tex_yy_yyz_0[j] - pc_x[j] * tex_yy_yyz_1[j] + ta_yy_yyz_1[j];

                    tey_xyy_yyz_0[j] = pa_x[j] * tey_yy_yyz_0[j] - pc_x[j] * tey_yy_yyz_1[j];

                    tez_xyy_yyz_0[j] = pa_x[j] * tez_yy_yyz_0[j] - pc_x[j] * tez_yy_yyz_1[j];

                    tex_xyy_yzz_0[j] = pa_x[j] * tex_yy_yzz_0[j] - pc_x[j] * tex_yy_yzz_1[j] + ta_yy_yzz_1[j];

                    tey_xyy_yzz_0[j] = pa_x[j] * tey_yy_yzz_0[j] - pc_x[j] * tey_yy_yzz_1[j];

                    tez_xyy_yzz_0[j] = pa_x[j] * tez_yy_yzz_0[j] - pc_x[j] * tez_yy_yzz_1[j];

                    tex_xyy_zzz_0[j] = pa_x[j] * tex_yy_zzz_0[j] - pc_x[j] * tex_yy_zzz_1[j] + ta_yy_zzz_1[j];

                    tey_xyy_zzz_0[j] = pa_x[j] * tey_yy_zzz_0[j] - pc_x[j] * tey_yy_zzz_1[j];

                    tez_xyy_zzz_0[j] = pa_x[j] * tez_yy_zzz_0[j] - pc_x[j] * tez_yy_zzz_1[j];

                    tex_xyz_xxx_0[j] = pa_x[j] * tex_yz_xxx_0[j] - pc_x[j] * tex_yz_xxx_1[j] + 1.5 * fl1_fx * tex_yz_xx_0[j] - 1.5 * fl1_fx * tex_yz_xx_1[j] + ta_yz_xxx_1[j];

                    tey_xyz_xxx_0[j] = pa_x[j] * tey_yz_xxx_0[j] - pc_x[j] * tey_yz_xxx_1[j] + 1.5 * fl1_fx * tey_yz_xx_0[j] - 1.5 * fl1_fx * tey_yz_xx_1[j];

                    tez_xyz_xxx_0[j] = pa_x[j] * tez_yz_xxx_0[j] - pc_x[j] * tez_yz_xxx_1[j] + 1.5 * fl1_fx * tez_yz_xx_0[j] - 1.5 * fl1_fx * tez_yz_xx_1[j];

                    tex_xyz_xxy_0[j] = pa_x[j] * tex_yz_xxy_0[j] - pc_x[j] * tex_yz_xxy_1[j] + fl1_fx * tex_yz_xy_0[j] - fl1_fx * tex_yz_xy_1[j] + ta_yz_xxy_1[j];

                    tey_xyz_xxy_0[j] = pa_x[j] * tey_yz_xxy_0[j] - pc_x[j] * tey_yz_xxy_1[j] + fl1_fx * tey_yz_xy_0[j] - fl1_fx * tey_yz_xy_1[j];

                    tez_xyz_xxy_0[j] = pa_x[j] * tez_yz_xxy_0[j] - pc_x[j] * tez_yz_xxy_1[j] + fl1_fx * tez_yz_xy_0[j] - fl1_fx * tez_yz_xy_1[j];

                    tex_xyz_xxz_0[j] = pa_x[j] * tex_yz_xxz_0[j] - pc_x[j] * tex_yz_xxz_1[j] + fl1_fx * tex_yz_xz_0[j] - fl1_fx * tex_yz_xz_1[j] + ta_yz_xxz_1[j];

                    tey_xyz_xxz_0[j] = pa_x[j] * tey_yz_xxz_0[j] - pc_x[j] * tey_yz_xxz_1[j] + fl1_fx * tey_yz_xz_0[j] - fl1_fx * tey_yz_xz_1[j];

                    tez_xyz_xxz_0[j] = pa_x[j] * tez_yz_xxz_0[j] - pc_x[j] * tez_yz_xxz_1[j] + fl1_fx * tez_yz_xz_0[j] - fl1_fx * tez_yz_xz_1[j];

                    tex_xyz_xyy_0[j] = pa_x[j] * tex_yz_xyy_0[j] - pc_x[j] * tex_yz_xyy_1[j] + 0.5 * fl1_fx * tex_yz_yy_0[j] - 0.5 * fl1_fx * tex_yz_yy_1[j] + ta_yz_xyy_1[j];

                    tey_xyz_xyy_0[j] = pa_x[j] * tey_yz_xyy_0[j] - pc_x[j] * tey_yz_xyy_1[j] + 0.5 * fl1_fx * tey_yz_yy_0[j] - 0.5 * fl1_fx * tey_yz_yy_1[j];

                    tez_xyz_xyy_0[j] = pa_x[j] * tez_yz_xyy_0[j] - pc_x[j] * tez_yz_xyy_1[j] + 0.5 * fl1_fx * tez_yz_yy_0[j] - 0.5 * fl1_fx * tez_yz_yy_1[j];

                    tex_xyz_xyz_0[j] = pa_x[j] * tex_yz_xyz_0[j] - pc_x[j] * tex_yz_xyz_1[j] + 0.5 * fl1_fx * tex_yz_yz_0[j] - 0.5 * fl1_fx * tex_yz_yz_1[j] + ta_yz_xyz_1[j];

                    tey_xyz_xyz_0[j] = pa_x[j] * tey_yz_xyz_0[j] - pc_x[j] * tey_yz_xyz_1[j] + 0.5 * fl1_fx * tey_yz_yz_0[j] - 0.5 * fl1_fx * tey_yz_yz_1[j];

                    tez_xyz_xyz_0[j] = pa_x[j] * tez_yz_xyz_0[j] - pc_x[j] * tez_yz_xyz_1[j] + 0.5 * fl1_fx * tez_yz_yz_0[j] - 0.5 * fl1_fx * tez_yz_yz_1[j];

                    tex_xyz_xzz_0[j] = pa_x[j] * tex_yz_xzz_0[j] - pc_x[j] * tex_yz_xzz_1[j] + 0.5 * fl1_fx * tex_yz_zz_0[j] - 0.5 * fl1_fx * tex_yz_zz_1[j] + ta_yz_xzz_1[j];

                    tey_xyz_xzz_0[j] = pa_x[j] * tey_yz_xzz_0[j] - pc_x[j] * tey_yz_xzz_1[j] + 0.5 * fl1_fx * tey_yz_zz_0[j] - 0.5 * fl1_fx * tey_yz_zz_1[j];

                    tez_xyz_xzz_0[j] = pa_x[j] * tez_yz_xzz_0[j] - pc_x[j] * tez_yz_xzz_1[j] + 0.5 * fl1_fx * tez_yz_zz_0[j] - 0.5 * fl1_fx * tez_yz_zz_1[j];

                    tex_xyz_yyy_0[j] = pa_x[j] * tex_yz_yyy_0[j] - pc_x[j] * tex_yz_yyy_1[j] + ta_yz_yyy_1[j];

                    tey_xyz_yyy_0[j] = pa_x[j] * tey_yz_yyy_0[j] - pc_x[j] * tey_yz_yyy_1[j];

                    tez_xyz_yyy_0[j] = pa_x[j] * tez_yz_yyy_0[j] - pc_x[j] * tez_yz_yyy_1[j];

                    tex_xyz_yyz_0[j] = pa_x[j] * tex_yz_yyz_0[j] - pc_x[j] * tex_yz_yyz_1[j] + ta_yz_yyz_1[j];

                    tey_xyz_yyz_0[j] = pa_x[j] * tey_yz_yyz_0[j] - pc_x[j] * tey_yz_yyz_1[j];

                    tez_xyz_yyz_0[j] = pa_x[j] * tez_yz_yyz_0[j] - pc_x[j] * tez_yz_yyz_1[j];

                    tex_xyz_yzz_0[j] = pa_x[j] * tex_yz_yzz_0[j] - pc_x[j] * tex_yz_yzz_1[j] + ta_yz_yzz_1[j];

                    tey_xyz_yzz_0[j] = pa_x[j] * tey_yz_yzz_0[j] - pc_x[j] * tey_yz_yzz_1[j];

                    tez_xyz_yzz_0[j] = pa_x[j] * tez_yz_yzz_0[j] - pc_x[j] * tez_yz_yzz_1[j];

                    tex_xyz_zzz_0[j] = pa_x[j] * tex_yz_zzz_0[j] - pc_x[j] * tex_yz_zzz_1[j] + ta_yz_zzz_1[j];

                    tey_xyz_zzz_0[j] = pa_x[j] * tey_yz_zzz_0[j] - pc_x[j] * tey_yz_zzz_1[j];

                    tez_xyz_zzz_0[j] = pa_x[j] * tez_yz_zzz_0[j] - pc_x[j] * tez_yz_zzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectricFieldForFF_150_200(      CMemBlock2D<double>& primBuffer,
                                   const CRecursionMap&       recursionMap,
                                   const CMemBlock2D<double>& osFactors,
                                   const CMemBlock2D<double>& paDistances,
                                   const CMemBlock2D<double>& pcDistances,
                                   const CGtoBlock&           braGtoBlock,
                                   const CGtoBlock&           ketGtoBlock,
                                   const int32_t              iContrGto)
    {
        // Batch of Integrals (150,200)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_1_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_1_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_x = paDistances.data(3 * idx);

                auto pa_y = paDistances.data(3 * idx + 1);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_x = pcDistances.data(3 * idx);

                auto pc_y = pcDistances.data(3 * idx + 1);

                // set up pointers to auxilary integrals

                auto tex_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 30); 

                auto tey_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 30); 

                auto tez_yy_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 30); 

                auto tex_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 31); 

                auto tey_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 31); 

                auto tez_yy_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 31); 

                auto tex_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 32); 

                auto tey_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 32); 

                auto tez_yy_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 32); 

                auto tex_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 33); 

                auto tey_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 33); 

                auto tez_yy_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 33); 

                auto tex_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 34); 

                auto tey_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 34); 

                auto tez_yy_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 34); 

                auto tex_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 35); 

                auto tey_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 35); 

                auto tez_yy_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 35); 

                auto tex_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 36); 

                auto tey_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 36); 

                auto tex_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 50); 

                auto tey_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 51); 

                auto tey_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 52); 

                auto tey_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 53); 

                auto tey_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 53); 

                auto tez_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 53); 

                auto tex_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 54); 

                auto tey_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 54); 

                auto tez_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 54); 

                auto tex_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 55); 

                auto tey_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 55); 

                auto tez_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 55); 

                auto tex_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 56); 

                auto tey_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 56); 

                auto tez_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 56); 

                auto tex_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 57); 

                auto tey_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 57); 

                auto tez_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 57); 

                auto tex_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 58); 

                auto tey_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 58); 

                auto tez_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 58); 

                auto tex_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 59); 

                auto tey_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 59); 

                auto tez_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 59); 

                auto tex_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 30); 

                auto tey_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 30); 

                auto tez_yy_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 30); 

                auto tex_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 31); 

                auto tey_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 31); 

                auto tez_yy_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 31); 

                auto tex_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 32); 

                auto tey_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 32); 

                auto tez_yy_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 32); 

                auto tex_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 33); 

                auto tey_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 33); 

                auto tez_yy_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 33); 

                auto tex_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 34); 

                auto tey_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 34); 

                auto tez_yy_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 34); 

                auto tex_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 35); 

                auto tey_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 35); 

                auto tez_yy_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 35); 

                auto tex_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 36); 

                auto tey_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 36); 

                auto tex_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 50); 

                auto tey_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 51); 

                auto tey_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 52); 

                auto tey_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 53); 

                auto tey_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 53); 

                auto tez_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 53); 

                auto tex_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 54); 

                auto tey_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 54); 

                auto tez_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 54); 

                auto tex_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 55); 

                auto tey_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 55); 

                auto tez_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 55); 

                auto tex_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 56); 

                auto tey_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 56); 

                auto tez_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 56); 

                auto tex_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 57); 

                auto tey_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 57); 

                auto tez_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 57); 

                auto tex_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 58); 

                auto tey_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 58); 

                auto tez_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 58); 

                auto tex_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 59); 

                auto tey_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 59); 

                auto tez_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 59); 

                auto tex_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 10); 

                auto tey_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 10); 

                auto tez_y_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 10); 

                auto tex_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 11); 

                auto tey_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 11); 

                auto tez_y_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 11); 

                auto tex_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 12); 

                auto tey_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 12); 

                auto tez_y_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 12); 

                auto tex_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 13); 

                auto tey_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 13); 

                auto tez_y_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 13); 

                auto tex_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 14); 

                auto tey_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 14); 

                auto tez_y_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 14); 

                auto tex_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 15); 

                auto tey_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 15); 

                auto tez_y_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 15); 

                auto tex_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 16); 

                auto tey_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 16); 

                auto tex_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 10); 

                auto tey_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 10); 

                auto tez_y_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 10); 

                auto tex_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 11); 

                auto tey_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 11); 

                auto tez_y_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 11); 

                auto tex_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 12); 

                auto tey_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 12); 

                auto tez_y_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 12); 

                auto tex_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 13); 

                auto tey_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 13); 

                auto tez_y_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 13); 

                auto tex_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 14); 

                auto tey_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 14); 

                auto tez_y_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 14); 

                auto tex_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 15); 

                auto tey_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 15); 

                auto tez_y_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 15); 

                auto tex_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 16); 

                auto tey_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 16); 

                auto tex_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 18); 

                auto tey_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 18); 

                auto tez_yy_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 18); 

                auto tex_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 19); 

                auto tey_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 19); 

                auto tez_yy_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 19); 

                auto tex_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 20); 

                auto tey_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 20); 

                auto tez_yy_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 20); 

                auto tex_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 21); 

                auto tey_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 21); 

                auto tex_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 30); 

                auto tey_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 31); 

                auto tey_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 31); 

                auto tez_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 31); 

                auto tex_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 32); 

                auto tey_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 32); 

                auto tez_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 32); 

                auto tex_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 33); 

                auto tey_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 33); 

                auto tez_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 33); 

                auto tex_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 34); 

                auto tey_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 34); 

                auto tez_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 34); 

                auto tex_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 35); 

                auto tey_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 35); 

                auto tez_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 35); 

                auto tex_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 18); 

                auto tey_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 18); 

                auto tez_yy_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 18); 

                auto tex_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 19); 

                auto tey_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 19); 

                auto tez_yy_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 19); 

                auto tex_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 20); 

                auto tey_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 20); 

                auto tez_yy_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 20); 

                auto tex_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 21); 

                auto tey_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 21); 

                auto tex_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 30); 

                auto tey_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 31); 

                auto tey_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 31); 

                auto tez_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 31); 

                auto tex_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 32); 

                auto tey_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 32); 

                auto tez_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 32); 

                auto tex_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 33); 

                auto tey_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 33); 

                auto tez_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 33); 

                auto tex_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 34); 

                auto tey_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 34); 

                auto tez_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 34); 

                auto tex_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 35); 

                auto tey_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 35); 

                auto tez_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 35); 

                auto ta_yy_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 30); 

                auto ta_yy_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 31); 

                auto ta_yy_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 32); 

                auto ta_yy_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 33); 

                auto ta_yy_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 34); 

                auto ta_yy_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 35); 

                auto ta_yy_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 36); 

                auto ta_zz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 50); 

                auto ta_zz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 51); 

                auto ta_zz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 52); 

                auto ta_zz_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 53); 

                auto ta_zz_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 54); 

                auto ta_zz_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 55); 

                auto ta_zz_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 56); 

                auto ta_zz_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 57); 

                auto ta_zz_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 58); 

                auto ta_zz_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 59); 

                // set up pointers to integrals

                auto tex_xzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 50); 

                auto tey_xzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 50); 

                auto tez_xzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 50); 

                auto tex_xzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 51); 

                auto tey_xzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 51); 

                auto tez_xzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 51); 

                auto tex_xzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 52); 

                auto tey_xzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 52); 

                auto tez_xzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 52); 

                auto tex_xzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 53); 

                auto tey_xzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 53); 

                auto tez_xzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 53); 

                auto tex_xzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 54); 

                auto tey_xzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 54); 

                auto tez_xzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 54); 

                auto tex_xzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 55); 

                auto tey_xzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 55); 

                auto tez_xzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 55); 

                auto tex_xzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 56); 

                auto tey_xzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 56); 

                auto tez_xzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 56); 

                auto tex_xzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 57); 

                auto tey_xzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 57); 

                auto tez_xzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 57); 

                auto tex_xzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 58); 

                auto tey_xzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 58); 

                auto tez_xzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 58); 

                auto tex_xzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 59); 

                auto tey_xzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 59); 

                auto tez_xzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 59); 

                auto tex_yyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 60); 

                auto tey_yyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 60); 

                auto tez_yyy_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 60); 

                auto tex_yyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 61); 

                auto tey_yyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 61); 

                auto tez_yyy_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 61); 

                auto tex_yyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 62); 

                auto tey_yyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 62); 

                auto tez_yyy_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 62); 

                auto tex_yyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 63); 

                auto tey_yyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 63); 

                auto tez_yyy_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 63); 

                auto tex_yyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 64); 

                auto tey_yyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 64); 

                auto tez_yyy_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 64); 

                auto tex_yyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 65); 

                auto tey_yyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 65); 

                auto tez_yyy_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 65); 

                auto tex_yyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 66); 

                auto tey_yyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 66); 

                // Batch of Integrals (150,200)

                #pragma omp simd aligned(fx, pa_x, pa_y, pc_x, pc_y, ta_yy_xxx_1, ta_yy_xxy_1, ta_yy_xxz_1, \
                                         ta_yy_xyy_1, ta_yy_xyz_1, ta_yy_xzz_1, ta_yy_yyy_1, ta_zz_xxx_1, ta_zz_xxy_1, \
                                         ta_zz_xxz_1, ta_zz_xyy_1, ta_zz_xyz_1, ta_zz_xzz_1, ta_zz_yyy_1, ta_zz_yyz_1, \
                                         ta_zz_yzz_1, ta_zz_zzz_1, tex_xzz_xxx_0, tex_xzz_xxy_0, tex_xzz_xxz_0, \
                                         tex_xzz_xyy_0, tex_xzz_xyz_0, tex_xzz_xzz_0, tex_xzz_yyy_0, tex_xzz_yyz_0, \
                                         tex_xzz_yzz_0, tex_xzz_zzz_0, tex_y_xxx_0, tex_y_xxx_1, tex_y_xxy_0, tex_y_xxy_1, \
                                         tex_y_xxz_0, tex_y_xxz_1, tex_y_xyy_0, tex_y_xyy_1, tex_y_xyz_0, tex_y_xyz_1, \
                                         tex_y_xzz_0, tex_y_xzz_1, tex_y_yyy_0, tex_y_yyy_1, tex_yy_xx_0, tex_yy_xx_1, \
                                         tex_yy_xxx_0, tex_yy_xxx_1, tex_yy_xxy_0, tex_yy_xxy_1, tex_yy_xxz_0, tex_yy_xxz_1, \
                                         tex_yy_xy_0, tex_yy_xy_1, tex_yy_xyy_0, tex_yy_xyy_1, tex_yy_xyz_0, tex_yy_xyz_1, \
                                         tex_yy_xz_0, tex_yy_xz_1, tex_yy_xzz_0, tex_yy_xzz_1, tex_yy_yy_0, tex_yy_yy_1, \
                                         tex_yy_yyy_0, tex_yy_yyy_1, tex_yyy_xxx_0, tex_yyy_xxy_0, tex_yyy_xxz_0, \
                                         tex_yyy_xyy_0, tex_yyy_xyz_0, tex_yyy_xzz_0, tex_yyy_yyy_0, tex_zz_xx_0, \
                                         tex_zz_xx_1, tex_zz_xxx_0, tex_zz_xxx_1, tex_zz_xxy_0, tex_zz_xxy_1, tex_zz_xxz_0, \
                                         tex_zz_xxz_1, tex_zz_xy_0, tex_zz_xy_1, tex_zz_xyy_0, tex_zz_xyy_1, tex_zz_xyz_0, \
                                         tex_zz_xyz_1, tex_zz_xz_0, tex_zz_xz_1, tex_zz_xzz_0, tex_zz_xzz_1, tex_zz_yy_0, \
                                         tex_zz_yy_1, tex_zz_yyy_0, tex_zz_yyy_1, tex_zz_yyz_0, tex_zz_yyz_1, tex_zz_yz_0, \
                                         tex_zz_yz_1, tex_zz_yzz_0, tex_zz_yzz_1, tex_zz_zz_0, tex_zz_zz_1, tex_zz_zzz_0, \
                                         tex_zz_zzz_1, tey_xzz_xxx_0, tey_xzz_xxy_0, tey_xzz_xxz_0, tey_xzz_xyy_0, \
                                         tey_xzz_xyz_0, tey_xzz_xzz_0, tey_xzz_yyy_0, tey_xzz_yyz_0, tey_xzz_yzz_0, \
                                         tey_xzz_zzz_0, tey_y_xxx_0, tey_y_xxx_1, tey_y_xxy_0, tey_y_xxy_1, tey_y_xxz_0, \
                                         tey_y_xxz_1, tey_y_xyy_0, tey_y_xyy_1, tey_y_xyz_0, tey_y_xyz_1, tey_y_xzz_0, \
                                         tey_y_xzz_1, tey_y_yyy_0, tey_y_yyy_1, tey_yy_xx_0, tey_yy_xx_1, tey_yy_xxx_0, \
                                         tey_yy_xxx_1, tey_yy_xxy_0, tey_yy_xxy_1, tey_yy_xxz_0, tey_yy_xxz_1, tey_yy_xy_0, \
                                         tey_yy_xy_1, tey_yy_xyy_0, tey_yy_xyy_1, tey_yy_xyz_0, tey_yy_xyz_1, tey_yy_xz_0, \
                                         tey_yy_xz_1, tey_yy_xzz_0, tey_yy_xzz_1, tey_yy_yy_0, tey_yy_yy_1, tey_yy_yyy_0, \
                                         tey_yy_yyy_1, tey_yyy_xxx_0, tey_yyy_xxy_0, tey_yyy_xxz_0, tey_yyy_xyy_0, \
                                         tey_yyy_xyz_0, tey_yyy_xzz_0, tey_yyy_yyy_0, tey_zz_xx_0, tey_zz_xx_1, tey_zz_xxx_0, \
                                         tey_zz_xxx_1, tey_zz_xxy_0, tey_zz_xxy_1, tey_zz_xxz_0, tey_zz_xxz_1, tey_zz_xy_0, \
                                         tey_zz_xy_1, tey_zz_xyy_0, tey_zz_xyy_1, tey_zz_xyz_0, tey_zz_xyz_1, tey_zz_xz_0, \
                                         tey_zz_xz_1, tey_zz_xzz_0, tey_zz_xzz_1, tey_zz_yy_0, tey_zz_yy_1, tey_zz_yyy_0, \
                                         tey_zz_yyy_1, tey_zz_yyz_0, tey_zz_yyz_1, tey_zz_yz_0, tey_zz_yz_1, tey_zz_yzz_0, \
                                         tey_zz_yzz_1, tey_zz_zz_0, tey_zz_zz_1, tey_zz_zzz_0, tey_zz_zzz_1, tez_xzz_xxx_0, \
                                         tez_xzz_xxy_0, tez_xzz_xxz_0, tez_xzz_xyy_0, tez_xzz_xyz_0, tez_xzz_xzz_0, \
                                         tez_xzz_yyy_0, tez_xzz_yyz_0, tez_xzz_yzz_0, tez_xzz_zzz_0, tez_y_xxx_0, \
                                         tez_y_xxx_1, tez_y_xxy_0, tez_y_xxy_1, tez_y_xxz_0, tez_y_xxz_1, tez_y_xyy_0, \
                                         tez_y_xyy_1, tez_y_xyz_0, tez_y_xyz_1, tez_y_xzz_0, tez_y_xzz_1, tez_yy_xx_0, \
                                         tez_yy_xx_1, tez_yy_xxx_0, tez_yy_xxx_1, tez_yy_xxy_0, tez_yy_xxy_1, tez_yy_xxz_0, \
                                         tez_yy_xxz_1, tez_yy_xy_0, tez_yy_xy_1, tez_yy_xyy_0, tez_yy_xyy_1, tez_yy_xyz_0, \
                                         tez_yy_xyz_1, tez_yy_xz_0, tez_yy_xz_1, tez_yy_xzz_0, tez_yy_xzz_1, tez_yyy_xxx_0, \
                                         tez_yyy_xxy_0, tez_yyy_xxz_0, tez_yyy_xyy_0, tez_yyy_xyz_0, tez_yyy_xzz_0, \
                                         tez_zz_xx_0, tez_zz_xx_1, tez_zz_xxx_0, tez_zz_xxx_1, tez_zz_xxy_0, tez_zz_xxy_1, \
                                         tez_zz_xxz_0, tez_zz_xxz_1, tez_zz_xy_0, tez_zz_xy_1, tez_zz_xyy_0, tez_zz_xyy_1, \
                                         tez_zz_xyz_0, tez_zz_xyz_1, tez_zz_xz_0, tez_zz_xz_1, tez_zz_xzz_0, tez_zz_xzz_1, \
                                         tez_zz_yy_0, tez_zz_yy_1, tez_zz_yyy_0, tez_zz_yyy_1, tez_zz_yyz_0, tez_zz_yyz_1, \
                                         tez_zz_yz_0, tez_zz_yz_1, tez_zz_yzz_0, tez_zz_yzz_1, tez_zz_zz_0, tez_zz_zz_1, \
                                         tez_zz_zzz_0, tez_zz_zzz_1: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tex_xzz_xxx_0[j] = pa_x[j] * tex_zz_xxx_0[j] - pc_x[j] * tex_zz_xxx_1[j] + 1.5 * fl1_fx * tex_zz_xx_0[j] - 1.5 * fl1_fx * tex_zz_xx_1[j] + ta_zz_xxx_1[j];

                    tey_xzz_xxx_0[j] = pa_x[j] * tey_zz_xxx_0[j] - pc_x[j] * tey_zz_xxx_1[j] + 1.5 * fl1_fx * tey_zz_xx_0[j] - 1.5 * fl1_fx * tey_zz_xx_1[j];

                    tez_xzz_xxx_0[j] = pa_x[j] * tez_zz_xxx_0[j] - pc_x[j] * tez_zz_xxx_1[j] + 1.5 * fl1_fx * tez_zz_xx_0[j] - 1.5 * fl1_fx * tez_zz_xx_1[j];

                    tex_xzz_xxy_0[j] = pa_x[j] * tex_zz_xxy_0[j] - pc_x[j] * tex_zz_xxy_1[j] + fl1_fx * tex_zz_xy_0[j] - fl1_fx * tex_zz_xy_1[j] + ta_zz_xxy_1[j];

                    tey_xzz_xxy_0[j] = pa_x[j] * tey_zz_xxy_0[j] - pc_x[j] * tey_zz_xxy_1[j] + fl1_fx * tey_zz_xy_0[j] - fl1_fx * tey_zz_xy_1[j];

                    tez_xzz_xxy_0[j] = pa_x[j] * tez_zz_xxy_0[j] - pc_x[j] * tez_zz_xxy_1[j] + fl1_fx * tez_zz_xy_0[j] - fl1_fx * tez_zz_xy_1[j];

                    tex_xzz_xxz_0[j] = pa_x[j] * tex_zz_xxz_0[j] - pc_x[j] * tex_zz_xxz_1[j] + fl1_fx * tex_zz_xz_0[j] - fl1_fx * tex_zz_xz_1[j] + ta_zz_xxz_1[j];

                    tey_xzz_xxz_0[j] = pa_x[j] * tey_zz_xxz_0[j] - pc_x[j] * tey_zz_xxz_1[j] + fl1_fx * tey_zz_xz_0[j] - fl1_fx * tey_zz_xz_1[j];

                    tez_xzz_xxz_0[j] = pa_x[j] * tez_zz_xxz_0[j] - pc_x[j] * tez_zz_xxz_1[j] + fl1_fx * tez_zz_xz_0[j] - fl1_fx * tez_zz_xz_1[j];

                    tex_xzz_xyy_0[j] = pa_x[j] * tex_zz_xyy_0[j] - pc_x[j] * tex_zz_xyy_1[j] + 0.5 * fl1_fx * tex_zz_yy_0[j] - 0.5 * fl1_fx * tex_zz_yy_1[j] + ta_zz_xyy_1[j];

                    tey_xzz_xyy_0[j] = pa_x[j] * tey_zz_xyy_0[j] - pc_x[j] * tey_zz_xyy_1[j] + 0.5 * fl1_fx * tey_zz_yy_0[j] - 0.5 * fl1_fx * tey_zz_yy_1[j];

                    tez_xzz_xyy_0[j] = pa_x[j] * tez_zz_xyy_0[j] - pc_x[j] * tez_zz_xyy_1[j] + 0.5 * fl1_fx * tez_zz_yy_0[j] - 0.5 * fl1_fx * tez_zz_yy_1[j];

                    tex_xzz_xyz_0[j] = pa_x[j] * tex_zz_xyz_0[j] - pc_x[j] * tex_zz_xyz_1[j] + 0.5 * fl1_fx * tex_zz_yz_0[j] - 0.5 * fl1_fx * tex_zz_yz_1[j] + ta_zz_xyz_1[j];

                    tey_xzz_xyz_0[j] = pa_x[j] * tey_zz_xyz_0[j] - pc_x[j] * tey_zz_xyz_1[j] + 0.5 * fl1_fx * tey_zz_yz_0[j] - 0.5 * fl1_fx * tey_zz_yz_1[j];

                    tez_xzz_xyz_0[j] = pa_x[j] * tez_zz_xyz_0[j] - pc_x[j] * tez_zz_xyz_1[j] + 0.5 * fl1_fx * tez_zz_yz_0[j] - 0.5 * fl1_fx * tez_zz_yz_1[j];

                    tex_xzz_xzz_0[j] = pa_x[j] * tex_zz_xzz_0[j] - pc_x[j] * tex_zz_xzz_1[j] + 0.5 * fl1_fx * tex_zz_zz_0[j] - 0.5 * fl1_fx * tex_zz_zz_1[j] + ta_zz_xzz_1[j];

                    tey_xzz_xzz_0[j] = pa_x[j] * tey_zz_xzz_0[j] - pc_x[j] * tey_zz_xzz_1[j] + 0.5 * fl1_fx * tey_zz_zz_0[j] - 0.5 * fl1_fx * tey_zz_zz_1[j];

                    tez_xzz_xzz_0[j] = pa_x[j] * tez_zz_xzz_0[j] - pc_x[j] * tez_zz_xzz_1[j] + 0.5 * fl1_fx * tez_zz_zz_0[j] - 0.5 * fl1_fx * tez_zz_zz_1[j];

                    tex_xzz_yyy_0[j] = pa_x[j] * tex_zz_yyy_0[j] - pc_x[j] * tex_zz_yyy_1[j] + ta_zz_yyy_1[j];

                    tey_xzz_yyy_0[j] = pa_x[j] * tey_zz_yyy_0[j] - pc_x[j] * tey_zz_yyy_1[j];

                    tez_xzz_yyy_0[j] = pa_x[j] * tez_zz_yyy_0[j] - pc_x[j] * tez_zz_yyy_1[j];

                    tex_xzz_yyz_0[j] = pa_x[j] * tex_zz_yyz_0[j] - pc_x[j] * tex_zz_yyz_1[j] + ta_zz_yyz_1[j];

                    tey_xzz_yyz_0[j] = pa_x[j] * tey_zz_yyz_0[j] - pc_x[j] * tey_zz_yyz_1[j];

                    tez_xzz_yyz_0[j] = pa_x[j] * tez_zz_yyz_0[j] - pc_x[j] * tez_zz_yyz_1[j];

                    tex_xzz_yzz_0[j] = pa_x[j] * tex_zz_yzz_0[j] - pc_x[j] * tex_zz_yzz_1[j] + ta_zz_yzz_1[j];

                    tey_xzz_yzz_0[j] = pa_x[j] * tey_zz_yzz_0[j] - pc_x[j] * tey_zz_yzz_1[j];

                    tez_xzz_yzz_0[j] = pa_x[j] * tez_zz_yzz_0[j] - pc_x[j] * tez_zz_yzz_1[j];

                    tex_xzz_zzz_0[j] = pa_x[j] * tex_zz_zzz_0[j] - pc_x[j] * tex_zz_zzz_1[j] + ta_zz_zzz_1[j];

                    tey_xzz_zzz_0[j] = pa_x[j] * tey_zz_zzz_0[j] - pc_x[j] * tey_zz_zzz_1[j];

                    tez_xzz_zzz_0[j] = pa_x[j] * tez_zz_zzz_0[j] - pc_x[j] * tez_zz_zzz_1[j];

                    tex_yyy_xxx_0[j] = pa_y[j] * tex_yy_xxx_0[j] - pc_y[j] * tex_yy_xxx_1[j] + fl1_fx * tex_y_xxx_0[j] - fl1_fx * tex_y_xxx_1[j];

                    tey_yyy_xxx_0[j] = pa_y[j] * tey_yy_xxx_0[j] - pc_y[j] * tey_yy_xxx_1[j] + fl1_fx * tey_y_xxx_0[j] - fl1_fx * tey_y_xxx_1[j] + ta_yy_xxx_1[j];

                    tez_yyy_xxx_0[j] = pa_y[j] * tez_yy_xxx_0[j] - pc_y[j] * tez_yy_xxx_1[j] + fl1_fx * tez_y_xxx_0[j] - fl1_fx * tez_y_xxx_1[j];

                    tex_yyy_xxy_0[j] = pa_y[j] * tex_yy_xxy_0[j] - pc_y[j] * tex_yy_xxy_1[j] + fl1_fx * tex_y_xxy_0[j] - fl1_fx * tex_y_xxy_1[j] + 0.5 * fl1_fx * tex_yy_xx_0[j] - 0.5 * fl1_fx * tex_yy_xx_1[j];

                    tey_yyy_xxy_0[j] = pa_y[j] * tey_yy_xxy_0[j] - pc_y[j] * tey_yy_xxy_1[j] + fl1_fx * tey_y_xxy_0[j] - fl1_fx * tey_y_xxy_1[j] + 0.5 * fl1_fx * tey_yy_xx_0[j] - 0.5 * fl1_fx * tey_yy_xx_1[j] + ta_yy_xxy_1[j];

                    tez_yyy_xxy_0[j] = pa_y[j] * tez_yy_xxy_0[j] - pc_y[j] * tez_yy_xxy_1[j] + fl1_fx * tez_y_xxy_0[j] - fl1_fx * tez_y_xxy_1[j] + 0.5 * fl1_fx * tez_yy_xx_0[j] - 0.5 * fl1_fx * tez_yy_xx_1[j];

                    tex_yyy_xxz_0[j] = pa_y[j] * tex_yy_xxz_0[j] - pc_y[j] * tex_yy_xxz_1[j] + fl1_fx * tex_y_xxz_0[j] - fl1_fx * tex_y_xxz_1[j];

                    tey_yyy_xxz_0[j] = pa_y[j] * tey_yy_xxz_0[j] - pc_y[j] * tey_yy_xxz_1[j] + fl1_fx * tey_y_xxz_0[j] - fl1_fx * tey_y_xxz_1[j] + ta_yy_xxz_1[j];

                    tez_yyy_xxz_0[j] = pa_y[j] * tez_yy_xxz_0[j] - pc_y[j] * tez_yy_xxz_1[j] + fl1_fx * tez_y_xxz_0[j] - fl1_fx * tez_y_xxz_1[j];

                    tex_yyy_xyy_0[j] = pa_y[j] * tex_yy_xyy_0[j] - pc_y[j] * tex_yy_xyy_1[j] + fl1_fx * tex_y_xyy_0[j] - fl1_fx * tex_y_xyy_1[j] + fl1_fx * tex_yy_xy_0[j] - fl1_fx * tex_yy_xy_1[j];

                    tey_yyy_xyy_0[j] = pa_y[j] * tey_yy_xyy_0[j] - pc_y[j] * tey_yy_xyy_1[j] + fl1_fx * tey_y_xyy_0[j] - fl1_fx * tey_y_xyy_1[j] + fl1_fx * tey_yy_xy_0[j] - fl1_fx * tey_yy_xy_1[j] + ta_yy_xyy_1[j];

                    tez_yyy_xyy_0[j] = pa_y[j] * tez_yy_xyy_0[j] - pc_y[j] * tez_yy_xyy_1[j] + fl1_fx * tez_y_xyy_0[j] - fl1_fx * tez_y_xyy_1[j] + fl1_fx * tez_yy_xy_0[j] - fl1_fx * tez_yy_xy_1[j];

                    tex_yyy_xyz_0[j] = pa_y[j] * tex_yy_xyz_0[j] - pc_y[j] * tex_yy_xyz_1[j] + fl1_fx * tex_y_xyz_0[j] - fl1_fx * tex_y_xyz_1[j] + 0.5 * fl1_fx * tex_yy_xz_0[j] - 0.5 * fl1_fx * tex_yy_xz_1[j];

                    tey_yyy_xyz_0[j] = pa_y[j] * tey_yy_xyz_0[j] - pc_y[j] * tey_yy_xyz_1[j] + fl1_fx * tey_y_xyz_0[j] - fl1_fx * tey_y_xyz_1[j] + 0.5 * fl1_fx * tey_yy_xz_0[j] - 0.5 * fl1_fx * tey_yy_xz_1[j] + ta_yy_xyz_1[j];

                    tez_yyy_xyz_0[j] = pa_y[j] * tez_yy_xyz_0[j] - pc_y[j] * tez_yy_xyz_1[j] + fl1_fx * tez_y_xyz_0[j] - fl1_fx * tez_y_xyz_1[j] + 0.5 * fl1_fx * tez_yy_xz_0[j] - 0.5 * fl1_fx * tez_yy_xz_1[j];

                    tex_yyy_xzz_0[j] = pa_y[j] * tex_yy_xzz_0[j] - pc_y[j] * tex_yy_xzz_1[j] + fl1_fx * tex_y_xzz_0[j] - fl1_fx * tex_y_xzz_1[j];

                    tey_yyy_xzz_0[j] = pa_y[j] * tey_yy_xzz_0[j] - pc_y[j] * tey_yy_xzz_1[j] + fl1_fx * tey_y_xzz_0[j] - fl1_fx * tey_y_xzz_1[j] + ta_yy_xzz_1[j];

                    tez_yyy_xzz_0[j] = pa_y[j] * tez_yy_xzz_0[j] - pc_y[j] * tez_yy_xzz_1[j] + fl1_fx * tez_y_xzz_0[j] - fl1_fx * tez_y_xzz_1[j];

                    tex_yyy_yyy_0[j] = pa_y[j] * tex_yy_yyy_0[j] - pc_y[j] * tex_yy_yyy_1[j] + fl1_fx * tex_y_yyy_0[j] - fl1_fx * tex_y_yyy_1[j] + 1.5 * fl1_fx * tex_yy_yy_0[j] - 1.5 * fl1_fx * tex_yy_yy_1[j];

                    tey_yyy_yyy_0[j] = pa_y[j] * tey_yy_yyy_0[j] - pc_y[j] * tey_yy_yyy_1[j] + fl1_fx * tey_y_yyy_0[j] - fl1_fx * tey_y_yyy_1[j] + 1.5 * fl1_fx * tey_yy_yy_0[j] - 1.5 * fl1_fx * tey_yy_yy_1[j] + ta_yy_yyy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectricFieldForFF_200_250(      CMemBlock2D<double>& primBuffer,
                                   const CRecursionMap&       recursionMap,
                                   const CMemBlock2D<double>& osFactors,
                                   const CMemBlock2D<double>& paDistances,
                                   const CMemBlock2D<double>& pcDistances,
                                   const CGtoBlock&           braGtoBlock,
                                   const CGtoBlock&           ketGtoBlock,
                                   const int32_t              iContrGto)
    {
        // Batch of Integrals (200,250)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_1_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_1_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_y = paDistances.data(3 * idx + 1);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_y = pcDistances.data(3 * idx + 1);

                // set up pointers to auxilary integrals

                auto tez_yy_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 36); 

                auto tex_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 37); 

                auto tey_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 37); 

                auto tez_yy_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 37); 

                auto tex_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 38); 

                auto tey_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 38); 

                auto tez_yy_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 38); 

                auto tex_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 39); 

                auto tey_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 39); 

                auto tez_yy_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 39); 

                auto tex_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 40); 

                auto tey_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 40); 

                auto tez_yz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 40); 

                auto tex_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 41); 

                auto tey_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 41); 

                auto tez_yz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 41); 

                auto tex_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 42); 

                auto tey_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 42); 

                auto tez_yz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 42); 

                auto tex_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 43); 

                auto tey_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 43); 

                auto tez_yz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 43); 

                auto tex_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 44); 

                auto tey_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 44); 

                auto tez_yz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 44); 

                auto tex_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 45); 

                auto tey_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 45); 

                auto tez_yz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 45); 

                auto tex_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 46); 

                auto tey_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 46); 

                auto tez_yz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 46); 

                auto tex_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 47); 

                auto tey_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 47); 

                auto tez_yz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 47); 

                auto tex_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 48); 

                auto tey_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 48); 

                auto tez_yz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 48); 

                auto tex_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 49); 

                auto tey_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 49); 

                auto tez_yz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 49); 

                auto tex_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 50); 

                auto tey_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 51); 

                auto tey_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 52); 

                auto tey_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 53); 

                auto tez_yy_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 36); 

                auto tex_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 37); 

                auto tey_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 37); 

                auto tez_yy_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 37); 

                auto tex_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 38); 

                auto tey_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 38); 

                auto tez_yy_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 38); 

                auto tex_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 39); 

                auto tey_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 39); 

                auto tez_yy_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 39); 

                auto tex_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 40); 

                auto tey_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 40); 

                auto tez_yz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 40); 

                auto tex_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 41); 

                auto tey_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 41); 

                auto tez_yz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 41); 

                auto tex_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 42); 

                auto tey_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 42); 

                auto tez_yz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 42); 

                auto tex_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 43); 

                auto tey_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 43); 

                auto tez_yz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 43); 

                auto tex_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 44); 

                auto tey_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 44); 

                auto tez_yz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 44); 

                auto tex_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 45); 

                auto tey_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 45); 

                auto tez_yz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 45); 

                auto tex_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 46); 

                auto tey_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 46); 

                auto tez_yz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 46); 

                auto tex_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 47); 

                auto tey_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 47); 

                auto tez_yz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 47); 

                auto tex_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 48); 

                auto tey_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 48); 

                auto tez_yz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 48); 

                auto tex_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 49); 

                auto tey_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 49); 

                auto tez_yz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 49); 

                auto tex_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 50); 

                auto tey_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 51); 

                auto tey_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 52); 

                auto tey_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 53); 

                auto tez_y_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 16); 

                auto tex_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 17); 

                auto tey_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 17); 

                auto tez_y_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 17); 

                auto tex_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 18); 

                auto tey_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 18); 

                auto tez_y_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 18); 

                auto tex_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 19); 

                auto tey_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 19); 

                auto tez_y_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 19); 

                auto tex_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 20); 

                auto tey_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 21); 

                auto tey_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 22); 

                auto tey_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 23); 

                auto tey_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 24); 

                auto tey_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 25); 

                auto tey_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 26); 

                auto tey_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 27); 

                auto tey_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 28); 

                auto tey_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 29); 

                auto tey_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 29); 

                auto tez_y_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 16); 

                auto tex_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 17); 

                auto tey_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 17); 

                auto tez_y_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 17); 

                auto tex_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 18); 

                auto tey_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 18); 

                auto tez_y_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 18); 

                auto tex_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 19); 

                auto tey_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 19); 

                auto tez_y_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 19); 

                auto tex_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 20); 

                auto tey_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 21); 

                auto tey_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 22); 

                auto tey_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 23); 

                auto tey_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 24); 

                auto tey_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 25); 

                auto tey_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 26); 

                auto tey_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 27); 

                auto tey_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 28); 

                auto tey_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 29); 

                auto tey_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 29); 

                auto tez_yy_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 21); 

                auto tex_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 22); 

                auto tey_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 22); 

                auto tez_yy_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 22); 

                auto tex_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 23); 

                auto tey_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 23); 

                auto tez_yy_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 23); 

                auto tex_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 24); 

                auto tey_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 24); 

                auto tez_yz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 24); 

                auto tex_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 25); 

                auto tey_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 25); 

                auto tez_yz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 25); 

                auto tex_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 26); 

                auto tey_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 26); 

                auto tez_yz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 26); 

                auto tex_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 27); 

                auto tey_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 27); 

                auto tez_yz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 27); 

                auto tex_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 28); 

                auto tey_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 28); 

                auto tez_yz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 28); 

                auto tex_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 29); 

                auto tey_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 29); 

                auto tez_yz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 29); 

                auto tex_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 30); 

                auto tey_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 31); 

                auto tez_yy_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 21); 

                auto tex_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 22); 

                auto tey_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 22); 

                auto tez_yy_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 22); 

                auto tex_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 23); 

                auto tey_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 23); 

                auto tez_yy_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 23); 

                auto tex_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 24); 

                auto tey_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 24); 

                auto tez_yz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 24); 

                auto tex_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 25); 

                auto tey_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 25); 

                auto tez_yz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 25); 

                auto tex_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 26); 

                auto tey_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 26); 

                auto tez_yz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 26); 

                auto tex_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 27); 

                auto tey_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 27); 

                auto tez_yz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 27); 

                auto tex_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 28); 

                auto tey_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 28); 

                auto tez_yz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 28); 

                auto tex_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 29); 

                auto tey_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 29); 

                auto tez_yz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 29); 

                auto tex_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 30); 

                auto tey_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 31); 

                auto ta_yy_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 37); 

                auto ta_yy_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 38); 

                auto ta_yy_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 39); 

                auto ta_yz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 40); 

                auto ta_yz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 41); 

                auto ta_yz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 42); 

                auto ta_yz_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 43); 

                auto ta_yz_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 44); 

                auto ta_yz_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 45); 

                auto ta_yz_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 46); 

                auto ta_yz_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 47); 

                auto ta_yz_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 48); 

                auto ta_yz_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 49); 

                auto ta_zz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 50); 

                auto ta_zz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 51); 

                auto ta_zz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 52); 

                // set up pointers to integrals

                auto tez_yyy_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 66); 

                auto tex_yyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 67); 

                auto tey_yyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 67); 

                auto tez_yyy_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 67); 

                auto tex_yyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 68); 

                auto tey_yyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 68); 

                auto tez_yyy_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 68); 

                auto tex_yyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 69); 

                auto tey_yyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 69); 

                auto tez_yyy_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 69); 

                auto tex_yyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 70); 

                auto tey_yyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 70); 

                auto tez_yyz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 70); 

                auto tex_yyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 71); 

                auto tey_yyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 71); 

                auto tez_yyz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 71); 

                auto tex_yyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 72); 

                auto tey_yyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 72); 

                auto tez_yyz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 72); 

                auto tex_yyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 73); 

                auto tey_yyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 73); 

                auto tez_yyz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 73); 

                auto tex_yyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 74); 

                auto tey_yyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 74); 

                auto tez_yyz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 74); 

                auto tex_yyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 75); 

                auto tey_yyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 75); 

                auto tez_yyz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 75); 

                auto tex_yyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 76); 

                auto tey_yyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 76); 

                auto tez_yyz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 76); 

                auto tex_yyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 77); 

                auto tey_yyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 77); 

                auto tez_yyz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 77); 

                auto tex_yyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 78); 

                auto tey_yyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 78); 

                auto tez_yyz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 78); 

                auto tex_yyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 79); 

                auto tey_yyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 79); 

                auto tez_yyz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 79); 

                auto tex_yzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 80); 

                auto tey_yzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 80); 

                auto tez_yzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 80); 

                auto tex_yzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 81); 

                auto tey_yzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 81); 

                auto tez_yzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 81); 

                auto tex_yzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 82); 

                auto tey_yzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 82); 

                auto tez_yzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 82); 

                auto tex_yzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 83); 

                // Batch of Integrals (200,250)

                #pragma omp simd aligned(fx, pa_y, pc_y, ta_yy_yyz_1, ta_yy_yzz_1, ta_yy_zzz_1, ta_yz_xxx_1, \
                                         ta_yz_xxy_1, ta_yz_xxz_1, ta_yz_xyy_1, ta_yz_xyz_1, ta_yz_xzz_1, ta_yz_yyy_1, \
                                         ta_yz_yyz_1, ta_yz_yzz_1, ta_yz_zzz_1, ta_zz_xxx_1, ta_zz_xxy_1, ta_zz_xxz_1, \
                                         tex_y_yyz_0, tex_y_yyz_1, tex_y_yzz_0, tex_y_yzz_1, tex_y_zzz_0, tex_y_zzz_1, \
                                         tex_yy_yyz_0, tex_yy_yyz_1, tex_yy_yz_0, tex_yy_yz_1, tex_yy_yzz_0, tex_yy_yzz_1, \
                                         tex_yy_zz_0, tex_yy_zz_1, tex_yy_zzz_0, tex_yy_zzz_1, tex_yyy_yyz_0, \
                                         tex_yyy_yzz_0, tex_yyy_zzz_0, tex_yyz_xxx_0, tex_yyz_xxy_0, tex_yyz_xxz_0, \
                                         tex_yyz_xyy_0, tex_yyz_xyz_0, tex_yyz_xzz_0, tex_yyz_yyy_0, tex_yyz_yyz_0, \
                                         tex_yyz_yzz_0, tex_yyz_zzz_0, tex_yz_xx_0, tex_yz_xx_1, tex_yz_xxx_0, tex_yz_xxx_1, \
                                         tex_yz_xxy_0, tex_yz_xxy_1, tex_yz_xxz_0, tex_yz_xxz_1, tex_yz_xy_0, tex_yz_xy_1, \
                                         tex_yz_xyy_0, tex_yz_xyy_1, tex_yz_xyz_0, tex_yz_xyz_1, tex_yz_xz_0, tex_yz_xz_1, \
                                         tex_yz_xzz_0, tex_yz_xzz_1, tex_yz_yy_0, tex_yz_yy_1, tex_yz_yyy_0, tex_yz_yyy_1, \
                                         tex_yz_yyz_0, tex_yz_yyz_1, tex_yz_yz_0, tex_yz_yz_1, tex_yz_yzz_0, tex_yz_yzz_1, \
                                         tex_yz_zz_0, tex_yz_zz_1, tex_yz_zzz_0, tex_yz_zzz_1, tex_yzz_xxx_0, \
                                         tex_yzz_xxy_0, tex_yzz_xxz_0, tex_yzz_xyy_0, tex_z_xxx_0, tex_z_xxx_1, tex_z_xxy_0, \
                                         tex_z_xxy_1, tex_z_xxz_0, tex_z_xxz_1, tex_z_xyy_0, tex_z_xyy_1, tex_z_xyz_0, \
                                         tex_z_xyz_1, tex_z_xzz_0, tex_z_xzz_1, tex_z_yyy_0, tex_z_yyy_1, tex_z_yyz_0, \
                                         tex_z_yyz_1, tex_z_yzz_0, tex_z_yzz_1, tex_z_zzz_0, tex_z_zzz_1, tex_zz_xx_0, \
                                         tex_zz_xx_1, tex_zz_xxx_0, tex_zz_xxx_1, tex_zz_xxy_0, tex_zz_xxy_1, tex_zz_xxz_0, \
                                         tex_zz_xxz_1, tex_zz_xy_0, tex_zz_xy_1, tex_zz_xyy_0, tex_zz_xyy_1, tey_y_yyz_0, \
                                         tey_y_yyz_1, tey_y_yzz_0, tey_y_yzz_1, tey_y_zzz_0, tey_y_zzz_1, tey_yy_yyz_0, \
                                         tey_yy_yyz_1, tey_yy_yz_0, tey_yy_yz_1, tey_yy_yzz_0, tey_yy_yzz_1, tey_yy_zz_0, \
                                         tey_yy_zz_1, tey_yy_zzz_0, tey_yy_zzz_1, tey_yyy_yyz_0, tey_yyy_yzz_0, \
                                         tey_yyy_zzz_0, tey_yyz_xxx_0, tey_yyz_xxy_0, tey_yyz_xxz_0, tey_yyz_xyy_0, \
                                         tey_yyz_xyz_0, tey_yyz_xzz_0, tey_yyz_yyy_0, tey_yyz_yyz_0, tey_yyz_yzz_0, \
                                         tey_yyz_zzz_0, tey_yz_xx_0, tey_yz_xx_1, tey_yz_xxx_0, tey_yz_xxx_1, tey_yz_xxy_0, \
                                         tey_yz_xxy_1, tey_yz_xxz_0, tey_yz_xxz_1, tey_yz_xy_0, tey_yz_xy_1, tey_yz_xyy_0, \
                                         tey_yz_xyy_1, tey_yz_xyz_0, tey_yz_xyz_1, tey_yz_xz_0, tey_yz_xz_1, tey_yz_xzz_0, \
                                         tey_yz_xzz_1, tey_yz_yy_0, tey_yz_yy_1, tey_yz_yyy_0, tey_yz_yyy_1, tey_yz_yyz_0, \
                                         tey_yz_yyz_1, tey_yz_yz_0, tey_yz_yz_1, tey_yz_yzz_0, tey_yz_yzz_1, tey_yz_zz_0, \
                                         tey_yz_zz_1, tey_yz_zzz_0, tey_yz_zzz_1, tey_yzz_xxx_0, tey_yzz_xxy_0, \
                                         tey_yzz_xxz_0, tey_z_xxx_0, tey_z_xxx_1, tey_z_xxy_0, tey_z_xxy_1, tey_z_xxz_0, \
                                         tey_z_xxz_1, tey_z_xyy_0, tey_z_xyy_1, tey_z_xyz_0, tey_z_xyz_1, tey_z_xzz_0, \
                                         tey_z_xzz_1, tey_z_yyy_0, tey_z_yyy_1, tey_z_yyz_0, tey_z_yyz_1, tey_z_yzz_0, \
                                         tey_z_yzz_1, tey_z_zzz_0, tey_z_zzz_1, tey_zz_xx_0, tey_zz_xx_1, tey_zz_xxx_0, \
                                         tey_zz_xxx_1, tey_zz_xxy_0, tey_zz_xxy_1, tey_zz_xxz_0, tey_zz_xxz_1, tez_y_yyy_0, \
                                         tez_y_yyy_1, tez_y_yyz_0, tez_y_yyz_1, tez_y_yzz_0, tez_y_yzz_1, tez_y_zzz_0, \
                                         tez_y_zzz_1, tez_yy_yy_0, tez_yy_yy_1, tez_yy_yyy_0, tez_yy_yyy_1, tez_yy_yyz_0, \
                                         tez_yy_yyz_1, tez_yy_yz_0, tez_yy_yz_1, tez_yy_yzz_0, tez_yy_yzz_1, tez_yy_zz_0, \
                                         tez_yy_zz_1, tez_yy_zzz_0, tez_yy_zzz_1, tez_yyy_yyy_0, tez_yyy_yyz_0, \
                                         tez_yyy_yzz_0, tez_yyy_zzz_0, tez_yyz_xxx_0, tez_yyz_xxy_0, tez_yyz_xxz_0, \
                                         tez_yyz_xyy_0, tez_yyz_xyz_0, tez_yyz_xzz_0, tez_yyz_yyy_0, tez_yyz_yyz_0, \
                                         tez_yyz_yzz_0, tez_yyz_zzz_0, tez_yz_xx_0, tez_yz_xx_1, tez_yz_xxx_0, tez_yz_xxx_1, \
                                         tez_yz_xxy_0, tez_yz_xxy_1, tez_yz_xxz_0, tez_yz_xxz_1, tez_yz_xy_0, tez_yz_xy_1, \
                                         tez_yz_xyy_0, tez_yz_xyy_1, tez_yz_xyz_0, tez_yz_xyz_1, tez_yz_xz_0, tez_yz_xz_1, \
                                         tez_yz_xzz_0, tez_yz_xzz_1, tez_yz_yy_0, tez_yz_yy_1, tez_yz_yyy_0, tez_yz_yyy_1, \
                                         tez_yz_yyz_0, tez_yz_yyz_1, tez_yz_yz_0, tez_yz_yz_1, tez_yz_yzz_0, tez_yz_yzz_1, \
                                         tez_yz_zz_0, tez_yz_zz_1, tez_yz_zzz_0, tez_yz_zzz_1, tez_yzz_xxx_0, \
                                         tez_yzz_xxy_0, tez_yzz_xxz_0, tez_z_xxx_0, tez_z_xxx_1, tez_z_xxy_0, tez_z_xxy_1, \
                                         tez_z_xxz_0, tez_z_xxz_1, tez_z_xyy_0, tez_z_xyy_1, tez_z_xyz_0, tez_z_xyz_1, \
                                         tez_z_xzz_0, tez_z_xzz_1, tez_z_yyy_0, tez_z_yyy_1, tez_z_yyz_0, tez_z_yyz_1, \
                                         tez_z_yzz_0, tez_z_yzz_1, tez_z_zzz_0, tez_z_zzz_1, tez_zz_xx_0, tez_zz_xx_1, \
                                         tez_zz_xxx_0, tez_zz_xxx_1, tez_zz_xxy_0, tez_zz_xxy_1, tez_zz_xxz_0, tez_zz_xxz_1: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tez_yyy_yyy_0[j] = pa_y[j] * tez_yy_yyy_0[j] - pc_y[j] * tez_yy_yyy_1[j] + fl1_fx * tez_y_yyy_0[j] - fl1_fx * tez_y_yyy_1[j] + 1.5 * fl1_fx * tez_yy_yy_0[j] - 1.5 * fl1_fx * tez_yy_yy_1[j];

                    tex_yyy_yyz_0[j] = pa_y[j] * tex_yy_yyz_0[j] - pc_y[j] * tex_yy_yyz_1[j] + fl1_fx * tex_y_yyz_0[j] - fl1_fx * tex_y_yyz_1[j] + fl1_fx * tex_yy_yz_0[j] - fl1_fx * tex_yy_yz_1[j];

                    tey_yyy_yyz_0[j] = pa_y[j] * tey_yy_yyz_0[j] - pc_y[j] * tey_yy_yyz_1[j] + fl1_fx * tey_y_yyz_0[j] - fl1_fx * tey_y_yyz_1[j] + fl1_fx * tey_yy_yz_0[j] - fl1_fx * tey_yy_yz_1[j] + ta_yy_yyz_1[j];

                    tez_yyy_yyz_0[j] = pa_y[j] * tez_yy_yyz_0[j] - pc_y[j] * tez_yy_yyz_1[j] + fl1_fx * tez_y_yyz_0[j] - fl1_fx * tez_y_yyz_1[j] + fl1_fx * tez_yy_yz_0[j] - fl1_fx * tez_yy_yz_1[j];

                    tex_yyy_yzz_0[j] = pa_y[j] * tex_yy_yzz_0[j] - pc_y[j] * tex_yy_yzz_1[j] + fl1_fx * tex_y_yzz_0[j] - fl1_fx * tex_y_yzz_1[j] + 0.5 * fl1_fx * tex_yy_zz_0[j] - 0.5 * fl1_fx * tex_yy_zz_1[j];

                    tey_yyy_yzz_0[j] = pa_y[j] * tey_yy_yzz_0[j] - pc_y[j] * tey_yy_yzz_1[j] + fl1_fx * tey_y_yzz_0[j] - fl1_fx * tey_y_yzz_1[j] + 0.5 * fl1_fx * tey_yy_zz_0[j] - 0.5 * fl1_fx * tey_yy_zz_1[j] + ta_yy_yzz_1[j];

                    tez_yyy_yzz_0[j] = pa_y[j] * tez_yy_yzz_0[j] - pc_y[j] * tez_yy_yzz_1[j] + fl1_fx * tez_y_yzz_0[j] - fl1_fx * tez_y_yzz_1[j] + 0.5 * fl1_fx * tez_yy_zz_0[j] - 0.5 * fl1_fx * tez_yy_zz_1[j];

                    tex_yyy_zzz_0[j] = pa_y[j] * tex_yy_zzz_0[j] - pc_y[j] * tex_yy_zzz_1[j] + fl1_fx * tex_y_zzz_0[j] - fl1_fx * tex_y_zzz_1[j];

                    tey_yyy_zzz_0[j] = pa_y[j] * tey_yy_zzz_0[j] - pc_y[j] * tey_yy_zzz_1[j] + fl1_fx * tey_y_zzz_0[j] - fl1_fx * tey_y_zzz_1[j] + ta_yy_zzz_1[j];

                    tez_yyy_zzz_0[j] = pa_y[j] * tez_yy_zzz_0[j] - pc_y[j] * tez_yy_zzz_1[j] + fl1_fx * tez_y_zzz_0[j] - fl1_fx * tez_y_zzz_1[j];

                    tex_yyz_xxx_0[j] = pa_y[j] * tex_yz_xxx_0[j] - pc_y[j] * tex_yz_xxx_1[j] + 0.5 * fl1_fx * tex_z_xxx_0[j] - 0.5 * fl1_fx * tex_z_xxx_1[j];

                    tey_yyz_xxx_0[j] = pa_y[j] * tey_yz_xxx_0[j] - pc_y[j] * tey_yz_xxx_1[j] + 0.5 * fl1_fx * tey_z_xxx_0[j] - 0.5 * fl1_fx * tey_z_xxx_1[j] + ta_yz_xxx_1[j];

                    tez_yyz_xxx_0[j] = pa_y[j] * tez_yz_xxx_0[j] - pc_y[j] * tez_yz_xxx_1[j] + 0.5 * fl1_fx * tez_z_xxx_0[j] - 0.5 * fl1_fx * tez_z_xxx_1[j];

                    tex_yyz_xxy_0[j] = pa_y[j] * tex_yz_xxy_0[j] - pc_y[j] * tex_yz_xxy_1[j] + 0.5 * fl1_fx * tex_z_xxy_0[j] - 0.5 * fl1_fx * tex_z_xxy_1[j] + 0.5 * fl1_fx * tex_yz_xx_0[j] - 0.5 * fl1_fx * tex_yz_xx_1[j];

                    tey_yyz_xxy_0[j] = pa_y[j] * tey_yz_xxy_0[j] - pc_y[j] * tey_yz_xxy_1[j] + 0.5 * fl1_fx * tey_z_xxy_0[j] - 0.5 * fl1_fx * tey_z_xxy_1[j] + 0.5 * fl1_fx * tey_yz_xx_0[j] - 0.5 * fl1_fx * tey_yz_xx_1[j] + ta_yz_xxy_1[j];

                    tez_yyz_xxy_0[j] = pa_y[j] * tez_yz_xxy_0[j] - pc_y[j] * tez_yz_xxy_1[j] + 0.5 * fl1_fx * tez_z_xxy_0[j] - 0.5 * fl1_fx * tez_z_xxy_1[j] + 0.5 * fl1_fx * tez_yz_xx_0[j] - 0.5 * fl1_fx * tez_yz_xx_1[j];

                    tex_yyz_xxz_0[j] = pa_y[j] * tex_yz_xxz_0[j] - pc_y[j] * tex_yz_xxz_1[j] + 0.5 * fl1_fx * tex_z_xxz_0[j] - 0.5 * fl1_fx * tex_z_xxz_1[j];

                    tey_yyz_xxz_0[j] = pa_y[j] * tey_yz_xxz_0[j] - pc_y[j] * tey_yz_xxz_1[j] + 0.5 * fl1_fx * tey_z_xxz_0[j] - 0.5 * fl1_fx * tey_z_xxz_1[j] + ta_yz_xxz_1[j];

                    tez_yyz_xxz_0[j] = pa_y[j] * tez_yz_xxz_0[j] - pc_y[j] * tez_yz_xxz_1[j] + 0.5 * fl1_fx * tez_z_xxz_0[j] - 0.5 * fl1_fx * tez_z_xxz_1[j];

                    tex_yyz_xyy_0[j] = pa_y[j] * tex_yz_xyy_0[j] - pc_y[j] * tex_yz_xyy_1[j] + 0.5 * fl1_fx * tex_z_xyy_0[j] - 0.5 * fl1_fx * tex_z_xyy_1[j] + fl1_fx * tex_yz_xy_0[j] - fl1_fx * tex_yz_xy_1[j];

                    tey_yyz_xyy_0[j] = pa_y[j] * tey_yz_xyy_0[j] - pc_y[j] * tey_yz_xyy_1[j] + 0.5 * fl1_fx * tey_z_xyy_0[j] - 0.5 * fl1_fx * tey_z_xyy_1[j] + fl1_fx * tey_yz_xy_0[j] - fl1_fx * tey_yz_xy_1[j] + ta_yz_xyy_1[j];

                    tez_yyz_xyy_0[j] = pa_y[j] * tez_yz_xyy_0[j] - pc_y[j] * tez_yz_xyy_1[j] + 0.5 * fl1_fx * tez_z_xyy_0[j] - 0.5 * fl1_fx * tez_z_xyy_1[j] + fl1_fx * tez_yz_xy_0[j] - fl1_fx * tez_yz_xy_1[j];

                    tex_yyz_xyz_0[j] = pa_y[j] * tex_yz_xyz_0[j] - pc_y[j] * tex_yz_xyz_1[j] + 0.5 * fl1_fx * tex_z_xyz_0[j] - 0.5 * fl1_fx * tex_z_xyz_1[j] + 0.5 * fl1_fx * tex_yz_xz_0[j] - 0.5 * fl1_fx * tex_yz_xz_1[j];

                    tey_yyz_xyz_0[j] = pa_y[j] * tey_yz_xyz_0[j] - pc_y[j] * tey_yz_xyz_1[j] + 0.5 * fl1_fx * tey_z_xyz_0[j] - 0.5 * fl1_fx * tey_z_xyz_1[j] + 0.5 * fl1_fx * tey_yz_xz_0[j] - 0.5 * fl1_fx * tey_yz_xz_1[j] + ta_yz_xyz_1[j];

                    tez_yyz_xyz_0[j] = pa_y[j] * tez_yz_xyz_0[j] - pc_y[j] * tez_yz_xyz_1[j] + 0.5 * fl1_fx * tez_z_xyz_0[j] - 0.5 * fl1_fx * tez_z_xyz_1[j] + 0.5 * fl1_fx * tez_yz_xz_0[j] - 0.5 * fl1_fx * tez_yz_xz_1[j];

                    tex_yyz_xzz_0[j] = pa_y[j] * tex_yz_xzz_0[j] - pc_y[j] * tex_yz_xzz_1[j] + 0.5 * fl1_fx * tex_z_xzz_0[j] - 0.5 * fl1_fx * tex_z_xzz_1[j];

                    tey_yyz_xzz_0[j] = pa_y[j] * tey_yz_xzz_0[j] - pc_y[j] * tey_yz_xzz_1[j] + 0.5 * fl1_fx * tey_z_xzz_0[j] - 0.5 * fl1_fx * tey_z_xzz_1[j] + ta_yz_xzz_1[j];

                    tez_yyz_xzz_0[j] = pa_y[j] * tez_yz_xzz_0[j] - pc_y[j] * tez_yz_xzz_1[j] + 0.5 * fl1_fx * tez_z_xzz_0[j] - 0.5 * fl1_fx * tez_z_xzz_1[j];

                    tex_yyz_yyy_0[j] = pa_y[j] * tex_yz_yyy_0[j] - pc_y[j] * tex_yz_yyy_1[j] + 0.5 * fl1_fx * tex_z_yyy_0[j] - 0.5 * fl1_fx * tex_z_yyy_1[j] + 1.5 * fl1_fx * tex_yz_yy_0[j] - 1.5 * fl1_fx * tex_yz_yy_1[j];

                    tey_yyz_yyy_0[j] = pa_y[j] * tey_yz_yyy_0[j] - pc_y[j] * tey_yz_yyy_1[j] + 0.5 * fl1_fx * tey_z_yyy_0[j] - 0.5 * fl1_fx * tey_z_yyy_1[j] + 1.5 * fl1_fx * tey_yz_yy_0[j] - 1.5 * fl1_fx * tey_yz_yy_1[j] + ta_yz_yyy_1[j];

                    tez_yyz_yyy_0[j] = pa_y[j] * tez_yz_yyy_0[j] - pc_y[j] * tez_yz_yyy_1[j] + 0.5 * fl1_fx * tez_z_yyy_0[j] - 0.5 * fl1_fx * tez_z_yyy_1[j] + 1.5 * fl1_fx * tez_yz_yy_0[j] - 1.5 * fl1_fx * tez_yz_yy_1[j];

                    tex_yyz_yyz_0[j] = pa_y[j] * tex_yz_yyz_0[j] - pc_y[j] * tex_yz_yyz_1[j] + 0.5 * fl1_fx * tex_z_yyz_0[j] - 0.5 * fl1_fx * tex_z_yyz_1[j] + fl1_fx * tex_yz_yz_0[j] - fl1_fx * tex_yz_yz_1[j];

                    tey_yyz_yyz_0[j] = pa_y[j] * tey_yz_yyz_0[j] - pc_y[j] * tey_yz_yyz_1[j] + 0.5 * fl1_fx * tey_z_yyz_0[j] - 0.5 * fl1_fx * tey_z_yyz_1[j] + fl1_fx * tey_yz_yz_0[j] - fl1_fx * tey_yz_yz_1[j] + ta_yz_yyz_1[j];

                    tez_yyz_yyz_0[j] = pa_y[j] * tez_yz_yyz_0[j] - pc_y[j] * tez_yz_yyz_1[j] + 0.5 * fl1_fx * tez_z_yyz_0[j] - 0.5 * fl1_fx * tez_z_yyz_1[j] + fl1_fx * tez_yz_yz_0[j] - fl1_fx * tez_yz_yz_1[j];

                    tex_yyz_yzz_0[j] = pa_y[j] * tex_yz_yzz_0[j] - pc_y[j] * tex_yz_yzz_1[j] + 0.5 * fl1_fx * tex_z_yzz_0[j] - 0.5 * fl1_fx * tex_z_yzz_1[j] + 0.5 * fl1_fx * tex_yz_zz_0[j] - 0.5 * fl1_fx * tex_yz_zz_1[j];

                    tey_yyz_yzz_0[j] = pa_y[j] * tey_yz_yzz_0[j] - pc_y[j] * tey_yz_yzz_1[j] + 0.5 * fl1_fx * tey_z_yzz_0[j] - 0.5 * fl1_fx * tey_z_yzz_1[j] + 0.5 * fl1_fx * tey_yz_zz_0[j] - 0.5 * fl1_fx * tey_yz_zz_1[j] + ta_yz_yzz_1[j];

                    tez_yyz_yzz_0[j] = pa_y[j] * tez_yz_yzz_0[j] - pc_y[j] * tez_yz_yzz_1[j] + 0.5 * fl1_fx * tez_z_yzz_0[j] - 0.5 * fl1_fx * tez_z_yzz_1[j] + 0.5 * fl1_fx * tez_yz_zz_0[j] - 0.5 * fl1_fx * tez_yz_zz_1[j];

                    tex_yyz_zzz_0[j] = pa_y[j] * tex_yz_zzz_0[j] - pc_y[j] * tex_yz_zzz_1[j] + 0.5 * fl1_fx * tex_z_zzz_0[j] - 0.5 * fl1_fx * tex_z_zzz_1[j];

                    tey_yyz_zzz_0[j] = pa_y[j] * tey_yz_zzz_0[j] - pc_y[j] * tey_yz_zzz_1[j] + 0.5 * fl1_fx * tey_z_zzz_0[j] - 0.5 * fl1_fx * tey_z_zzz_1[j] + ta_yz_zzz_1[j];

                    tez_yyz_zzz_0[j] = pa_y[j] * tez_yz_zzz_0[j] - pc_y[j] * tez_yz_zzz_1[j] + 0.5 * fl1_fx * tez_z_zzz_0[j] - 0.5 * fl1_fx * tez_z_zzz_1[j];

                    tex_yzz_xxx_0[j] = pa_y[j] * tex_zz_xxx_0[j] - pc_y[j] * tex_zz_xxx_1[j];

                    tey_yzz_xxx_0[j] = pa_y[j] * tey_zz_xxx_0[j] - pc_y[j] * tey_zz_xxx_1[j] + ta_zz_xxx_1[j];

                    tez_yzz_xxx_0[j] = pa_y[j] * tez_zz_xxx_0[j] - pc_y[j] * tez_zz_xxx_1[j];

                    tex_yzz_xxy_0[j] = pa_y[j] * tex_zz_xxy_0[j] - pc_y[j] * tex_zz_xxy_1[j] + 0.5 * fl1_fx * tex_zz_xx_0[j] - 0.5 * fl1_fx * tex_zz_xx_1[j];

                    tey_yzz_xxy_0[j] = pa_y[j] * tey_zz_xxy_0[j] - pc_y[j] * tey_zz_xxy_1[j] + 0.5 * fl1_fx * tey_zz_xx_0[j] - 0.5 * fl1_fx * tey_zz_xx_1[j] + ta_zz_xxy_1[j];

                    tez_yzz_xxy_0[j] = pa_y[j] * tez_zz_xxy_0[j] - pc_y[j] * tez_zz_xxy_1[j] + 0.5 * fl1_fx * tez_zz_xx_0[j] - 0.5 * fl1_fx * tez_zz_xx_1[j];

                    tex_yzz_xxz_0[j] = pa_y[j] * tex_zz_xxz_0[j] - pc_y[j] * tex_zz_xxz_1[j];

                    tey_yzz_xxz_0[j] = pa_y[j] * tey_zz_xxz_0[j] - pc_y[j] * tey_zz_xxz_1[j] + ta_zz_xxz_1[j];

                    tez_yzz_xxz_0[j] = pa_y[j] * tez_zz_xxz_0[j] - pc_y[j] * tez_zz_xxz_1[j];

                    tex_yzz_xyy_0[j] = pa_y[j] * tex_zz_xyy_0[j] - pc_y[j] * tex_zz_xyy_1[j] + fl1_fx * tex_zz_xy_0[j] - fl1_fx * tex_zz_xy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectricFieldForFF_250_300(      CMemBlock2D<double>& primBuffer,
                                   const CRecursionMap&       recursionMap,
                                   const CMemBlock2D<double>& osFactors,
                                   const CMemBlock2D<double>& paDistances,
                                   const CMemBlock2D<double>& pcDistances,
                                   const CGtoBlock&           braGtoBlock,
                                   const CGtoBlock&           ketGtoBlock,
                                   const int32_t              iContrGto)
    {
        // Batch of Integrals (250,300)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        auto bdim = epos[iContrGto] - spos[iContrGto];

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electric Field"},
                                             {3, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_e_3_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {3, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_e_3_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_e_2_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_2_2_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_2_2_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {2, -1, -1, -1}, {2, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_a_2_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Nuclear Potential"}, 0, true, 
                                                             {2, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            auto pidx_e_1_3_m0 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord));

            auto pidx_e_1_3_m1 = recursionMap.getIndexOfTerm(CRecursionTerm({"Electric Field"}, 1, true, 
                                                             {1, -1, -1, -1}, {3, -1, -1, -1}, 
                                                             1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fx = osFactors.data(3 * idx);

                // set up pointers to tensors product of distances R(PA) = P - A

                auto pa_y = paDistances.data(3 * idx + 1);

                auto pa_z = paDistances.data(3 * idx + 2);

                // set up pointers to tensors product of distances R(PC) = P - C

                auto pc_y = pcDistances.data(3 * idx + 1);

                auto pc_z = pcDistances.data(3 * idx + 2);

                // set up pointers to auxilary integrals

                auto tex_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 50); 

                auto tey_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 51); 

                auto tey_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 52); 

                auto tey_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 53); 

                auto tey_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 53); 

                auto tez_zz_xyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 53); 

                auto tex_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 54); 

                auto tey_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 54); 

                auto tez_zz_xyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 54); 

                auto tex_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 55); 

                auto tey_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 55); 

                auto tez_zz_xzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 55); 

                auto tex_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 56); 

                auto tey_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 56); 

                auto tez_zz_yyy_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 56); 

                auto tex_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 57); 

                auto tey_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 57); 

                auto tez_zz_yyz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 57); 

                auto tex_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 58); 

                auto tey_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 58); 

                auto tez_zz_yzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 58); 

                auto tex_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * idx + 59); 

                auto tey_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 60 * bdim + 60 * idx + 59); 

                auto tez_zz_zzz_0 = primBuffer.data(pidx_e_2_3_m0 + 120 * bdim + 60 * idx + 59); 

                auto tex_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 50); 

                auto tey_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 50); 

                auto tez_zz_xxx_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 50); 

                auto tex_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 51); 

                auto tey_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 51); 

                auto tez_zz_xxy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 51); 

                auto tex_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 52); 

                auto tey_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 52); 

                auto tez_zz_xxz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 52); 

                auto tex_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 53); 

                auto tey_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 53); 

                auto tez_zz_xyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 53); 

                auto tex_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 54); 

                auto tey_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 54); 

                auto tez_zz_xyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 54); 

                auto tex_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 55); 

                auto tey_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 55); 

                auto tez_zz_xzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 55); 

                auto tex_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 56); 

                auto tey_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 56); 

                auto tez_zz_yyy_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 56); 

                auto tex_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 57); 

                auto tey_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 57); 

                auto tez_zz_yyz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 57); 

                auto tex_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 58); 

                auto tey_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 58); 

                auto tez_zz_yzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 58); 

                auto tex_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * idx + 59); 

                auto tey_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 60 * bdim + 60 * idx + 59); 

                auto tez_zz_zzz_1 = primBuffer.data(pidx_e_2_3_m1 + 120 * bdim + 60 * idx + 59); 

                auto tex_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 20); 

                auto tey_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 21); 

                auto tey_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 22); 

                auto tey_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 23); 

                auto tey_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 24); 

                auto tey_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 25); 

                auto tey_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 26); 

                auto tey_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 27); 

                auto tey_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 28); 

                auto tey_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * idx + 29); 

                auto tey_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_0 = primBuffer.data(pidx_e_1_3_m0 + 60 * bdim + 30 * idx + 29); 

                auto tex_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 20); 

                auto tey_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 20); 

                auto tez_z_xxx_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 20); 

                auto tex_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 21); 

                auto tey_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 21); 

                auto tez_z_xxy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 21); 

                auto tex_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 22); 

                auto tey_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 22); 

                auto tez_z_xxz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 22); 

                auto tex_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 23); 

                auto tey_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 23); 

                auto tez_z_xyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 23); 

                auto tex_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 24); 

                auto tey_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 24); 

                auto tez_z_xyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 24); 

                auto tex_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 25); 

                auto tey_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 25); 

                auto tez_z_xzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 25); 

                auto tex_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 26); 

                auto tey_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 26); 

                auto tez_z_yyy_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 26); 

                auto tex_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 27); 

                auto tey_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 27); 

                auto tez_z_yyz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 27); 

                auto tex_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 28); 

                auto tey_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 28); 

                auto tez_z_yzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 28); 

                auto tex_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * idx + 29); 

                auto tey_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 30 * bdim + 30 * idx + 29); 

                auto tez_z_zzz_1 = primBuffer.data(pidx_e_1_3_m1 + 60 * bdim + 30 * idx + 29); 

                auto tex_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 30); 

                auto tey_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 31); 

                auto tey_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 31); 

                auto tez_zz_xy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 31); 

                auto tex_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 32); 

                auto tey_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 32); 

                auto tez_zz_xz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 32); 

                auto tex_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 33); 

                auto tey_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 33); 

                auto tez_zz_yy_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 33); 

                auto tex_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 34); 

                auto tey_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 34); 

                auto tez_zz_yz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 34); 

                auto tex_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * idx + 35); 

                auto tey_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 36 * bdim + 36 * idx + 35); 

                auto tez_zz_zz_0 = primBuffer.data(pidx_e_2_2_m0 + 72 * bdim + 36 * idx + 35); 

                auto tex_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 30); 

                auto tey_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 30); 

                auto tez_zz_xx_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 30); 

                auto tex_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 31); 

                auto tey_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 31); 

                auto tez_zz_xy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 31); 

                auto tex_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 32); 

                auto tey_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 32); 

                auto tez_zz_xz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 32); 

                auto tex_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 33); 

                auto tey_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 33); 

                auto tez_zz_yy_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 33); 

                auto tex_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 34); 

                auto tey_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 34); 

                auto tez_zz_yz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 34); 

                auto tex_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * idx + 35); 

                auto tey_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 36 * bdim + 36 * idx + 35); 

                auto tez_zz_zz_1 = primBuffer.data(pidx_e_2_2_m1 + 72 * bdim + 36 * idx + 35); 

                auto ta_zz_xxx_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 50); 

                auto ta_zz_xxy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 51); 

                auto ta_zz_xxz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 52); 

                auto ta_zz_xyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 53); 

                auto ta_zz_xyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 54); 

                auto ta_zz_xzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 55); 

                auto ta_zz_yyy_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 56); 

                auto ta_zz_yyz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 57); 

                auto ta_zz_yzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 58); 

                auto ta_zz_zzz_1 = primBuffer.data(pidx_a_2_3_m1 + 60 * idx + 59); 

                // set up pointers to integrals

                auto tey_yzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 83); 

                auto tez_yzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 83); 

                auto tex_yzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 84); 

                auto tey_yzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 84); 

                auto tez_yzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 84); 

                auto tex_yzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 85); 

                auto tey_yzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 85); 

                auto tez_yzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 85); 

                auto tex_yzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 86); 

                auto tey_yzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 86); 

                auto tez_yzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 86); 

                auto tex_yzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 87); 

                auto tey_yzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 87); 

                auto tez_yzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 87); 

                auto tex_yzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 88); 

                auto tey_yzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 88); 

                auto tez_yzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 88); 

                auto tex_yzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 89); 

                auto tey_yzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 89); 

                auto tez_yzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 89); 

                auto tex_zzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 90); 

                auto tey_zzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 90); 

                auto tez_zzz_xxx_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 90); 

                auto tex_zzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 91); 

                auto tey_zzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 91); 

                auto tez_zzz_xxy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 91); 

                auto tex_zzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 92); 

                auto tey_zzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 92); 

                auto tez_zzz_xxz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 92); 

                auto tex_zzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 93); 

                auto tey_zzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 93); 

                auto tez_zzz_xyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 93); 

                auto tex_zzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 94); 

                auto tey_zzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 94); 

                auto tez_zzz_xyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 94); 

                auto tex_zzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 95); 

                auto tey_zzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 95); 

                auto tez_zzz_xzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 95); 

                auto tex_zzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 96); 

                auto tey_zzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 96); 

                auto tez_zzz_yyy_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 96); 

                auto tex_zzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 97); 

                auto tey_zzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 97); 

                auto tez_zzz_yyz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 97); 

                auto tex_zzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 98); 

                auto tey_zzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 98); 

                auto tez_zzz_yzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 98); 

                auto tex_zzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * idx + 99); 

                auto tey_zzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 100 * bdim + 100 * idx + 99); 

                auto tez_zzz_zzz_0 = primBuffer.data(pidx_e_3_3_m0 + 200 * bdim + 100 * idx + 99); 

                // Batch of Integrals (250,300)

                #pragma omp simd aligned(fx, pa_y, pa_z, pc_y, pc_z, ta_zz_xxx_1, ta_zz_xxy_1, ta_zz_xxz_1, \
                                         ta_zz_xyy_1, ta_zz_xyz_1, ta_zz_xzz_1, ta_zz_yyy_1, ta_zz_yyz_1, ta_zz_yzz_1, \
                                         ta_zz_zzz_1, tex_yzz_xyz_0, tex_yzz_xzz_0, tex_yzz_yyy_0, tex_yzz_yyz_0, \
                                         tex_yzz_yzz_0, tex_yzz_zzz_0, tex_z_xxx_0, tex_z_xxx_1, tex_z_xxy_0, tex_z_xxy_1, \
                                         tex_z_xxz_0, tex_z_xxz_1, tex_z_xyy_0, tex_z_xyy_1, tex_z_xyz_0, tex_z_xyz_1, \
                                         tex_z_xzz_0, tex_z_xzz_1, tex_z_yyy_0, tex_z_yyy_1, tex_z_yyz_0, tex_z_yyz_1, \
                                         tex_z_yzz_0, tex_z_yzz_1, tex_z_zzz_0, tex_z_zzz_1, tex_zz_xx_0, tex_zz_xx_1, \
                                         tex_zz_xxx_0, tex_zz_xxx_1, tex_zz_xxy_0, tex_zz_xxy_1, tex_zz_xxz_0, tex_zz_xxz_1, \
                                         tex_zz_xy_0, tex_zz_xy_1, tex_zz_xyy_0, tex_zz_xyy_1, tex_zz_xyz_0, tex_zz_xyz_1, \
                                         tex_zz_xz_0, tex_zz_xz_1, tex_zz_xzz_0, tex_zz_xzz_1, tex_zz_yy_0, tex_zz_yy_1, \
                                         tex_zz_yyy_0, tex_zz_yyy_1, tex_zz_yyz_0, tex_zz_yyz_1, tex_zz_yz_0, tex_zz_yz_1, \
                                         tex_zz_yzz_0, tex_zz_yzz_1, tex_zz_zz_0, tex_zz_zz_1, tex_zz_zzz_0, tex_zz_zzz_1, \
                                         tex_zzz_xxx_0, tex_zzz_xxy_0, tex_zzz_xxz_0, tex_zzz_xyy_0, tex_zzz_xyz_0, \
                                         tex_zzz_xzz_0, tex_zzz_yyy_0, tex_zzz_yyz_0, tex_zzz_yzz_0, tex_zzz_zzz_0, \
                                         tey_yzz_xyy_0, tey_yzz_xyz_0, tey_yzz_xzz_0, tey_yzz_yyy_0, tey_yzz_yyz_0, \
                                         tey_yzz_yzz_0, tey_yzz_zzz_0, tey_z_xxx_0, tey_z_xxx_1, tey_z_xxy_0, tey_z_xxy_1, \
                                         tey_z_xxz_0, tey_z_xxz_1, tey_z_xyy_0, tey_z_xyy_1, tey_z_xyz_0, tey_z_xyz_1, \
                                         tey_z_xzz_0, tey_z_xzz_1, tey_z_yyy_0, tey_z_yyy_1, tey_z_yyz_0, tey_z_yyz_1, \
                                         tey_z_yzz_0, tey_z_yzz_1, tey_z_zzz_0, tey_z_zzz_1, tey_zz_xx_0, tey_zz_xx_1, \
                                         tey_zz_xxx_0, tey_zz_xxx_1, tey_zz_xxy_0, tey_zz_xxy_1, tey_zz_xxz_0, tey_zz_xxz_1, \
                                         tey_zz_xy_0, tey_zz_xy_1, tey_zz_xyy_0, tey_zz_xyy_1, tey_zz_xyz_0, tey_zz_xyz_1, \
                                         tey_zz_xz_0, tey_zz_xz_1, tey_zz_xzz_0, tey_zz_xzz_1, tey_zz_yy_0, tey_zz_yy_1, \
                                         tey_zz_yyy_0, tey_zz_yyy_1, tey_zz_yyz_0, tey_zz_yyz_1, tey_zz_yz_0, tey_zz_yz_1, \
                                         tey_zz_yzz_0, tey_zz_yzz_1, tey_zz_zz_0, tey_zz_zz_1, tey_zz_zzz_0, tey_zz_zzz_1, \
                                         tey_zzz_xxx_0, tey_zzz_xxy_0, tey_zzz_xxz_0, tey_zzz_xyy_0, tey_zzz_xyz_0, \
                                         tey_zzz_xzz_0, tey_zzz_yyy_0, tey_zzz_yyz_0, tey_zzz_yzz_0, tey_zzz_zzz_0, \
                                         tez_yzz_xyy_0, tez_yzz_xyz_0, tez_yzz_xzz_0, tez_yzz_yyy_0, tez_yzz_yyz_0, \
                                         tez_yzz_yzz_0, tez_yzz_zzz_0, tez_z_xxx_0, tez_z_xxx_1, tez_z_xxy_0, tez_z_xxy_1, \
                                         tez_z_xxz_0, tez_z_xxz_1, tez_z_xyy_0, tez_z_xyy_1, tez_z_xyz_0, tez_z_xyz_1, \
                                         tez_z_xzz_0, tez_z_xzz_1, tez_z_yyy_0, tez_z_yyy_1, tez_z_yyz_0, tez_z_yyz_1, \
                                         tez_z_yzz_0, tez_z_yzz_1, tez_z_zzz_0, tez_z_zzz_1, tez_zz_xx_0, tez_zz_xx_1, \
                                         tez_zz_xxx_0, tez_zz_xxx_1, tez_zz_xxy_0, tez_zz_xxy_1, tez_zz_xxz_0, tez_zz_xxz_1, \
                                         tez_zz_xy_0, tez_zz_xy_1, tez_zz_xyy_0, tez_zz_xyy_1, tez_zz_xyz_0, tez_zz_xyz_1, \
                                         tez_zz_xz_0, tez_zz_xz_1, tez_zz_xzz_0, tez_zz_xzz_1, tez_zz_yy_0, tez_zz_yy_1, \
                                         tez_zz_yyy_0, tez_zz_yyy_1, tez_zz_yyz_0, tez_zz_yyz_1, tez_zz_yz_0, tez_zz_yz_1, \
                                         tez_zz_yzz_0, tez_zz_yzz_1, tez_zz_zz_0, tez_zz_zz_1, tez_zz_zzz_0, tez_zz_zzz_1, \
                                         tez_zzz_xxx_0, tez_zzz_xxy_0, tez_zzz_xxz_0, tez_zzz_xyy_0, tez_zzz_xyz_0, \
                                         tez_zzz_xzz_0, tez_zzz_yyy_0, tez_zzz_yyz_0, tez_zzz_yzz_0, tez_zzz_zzz_0: VLX_ALIGN)
                for (int32_t j = 0; j < nprim; j++)
                {
                    double fl1_fx = fx[j];

                    tey_yzz_xyy_0[j] = pa_y[j] * tey_zz_xyy_0[j] - pc_y[j] * tey_zz_xyy_1[j] + fl1_fx * tey_zz_xy_0[j] - fl1_fx * tey_zz_xy_1[j] + ta_zz_xyy_1[j];

                    tez_yzz_xyy_0[j] = pa_y[j] * tez_zz_xyy_0[j] - pc_y[j] * tez_zz_xyy_1[j] + fl1_fx * tez_zz_xy_0[j] - fl1_fx * tez_zz_xy_1[j];

                    tex_yzz_xyz_0[j] = pa_y[j] * tex_zz_xyz_0[j] - pc_y[j] * tex_zz_xyz_1[j] + 0.5 * fl1_fx * tex_zz_xz_0[j] - 0.5 * fl1_fx * tex_zz_xz_1[j];

                    tey_yzz_xyz_0[j] = pa_y[j] * tey_zz_xyz_0[j] - pc_y[j] * tey_zz_xyz_1[j] + 0.5 * fl1_fx * tey_zz_xz_0[j] - 0.5 * fl1_fx * tey_zz_xz_1[j] + ta_zz_xyz_1[j];

                    tez_yzz_xyz_0[j] = pa_y[j] * tez_zz_xyz_0[j] - pc_y[j] * tez_zz_xyz_1[j] + 0.5 * fl1_fx * tez_zz_xz_0[j] - 0.5 * fl1_fx * tez_zz_xz_1[j];

                    tex_yzz_xzz_0[j] = pa_y[j] * tex_zz_xzz_0[j] - pc_y[j] * tex_zz_xzz_1[j];

                    tey_yzz_xzz_0[j] = pa_y[j] * tey_zz_xzz_0[j] - pc_y[j] * tey_zz_xzz_1[j] + ta_zz_xzz_1[j];

                    tez_yzz_xzz_0[j] = pa_y[j] * tez_zz_xzz_0[j] - pc_y[j] * tez_zz_xzz_1[j];

                    tex_yzz_yyy_0[j] = pa_y[j] * tex_zz_yyy_0[j] - pc_y[j] * tex_zz_yyy_1[j] + 1.5 * fl1_fx * tex_zz_yy_0[j] - 1.5 * fl1_fx * tex_zz_yy_1[j];

                    tey_yzz_yyy_0[j] = pa_y[j] * tey_zz_yyy_0[j] - pc_y[j] * tey_zz_yyy_1[j] + 1.5 * fl1_fx * tey_zz_yy_0[j] - 1.5 * fl1_fx * tey_zz_yy_1[j] + ta_zz_yyy_1[j];

                    tez_yzz_yyy_0[j] = pa_y[j] * tez_zz_yyy_0[j] - pc_y[j] * tez_zz_yyy_1[j] + 1.5 * fl1_fx * tez_zz_yy_0[j] - 1.5 * fl1_fx * tez_zz_yy_1[j];

                    tex_yzz_yyz_0[j] = pa_y[j] * tex_zz_yyz_0[j] - pc_y[j] * tex_zz_yyz_1[j] + fl1_fx * tex_zz_yz_0[j] - fl1_fx * tex_zz_yz_1[j];

                    tey_yzz_yyz_0[j] = pa_y[j] * tey_zz_yyz_0[j] - pc_y[j] * tey_zz_yyz_1[j] + fl1_fx * tey_zz_yz_0[j] - fl1_fx * tey_zz_yz_1[j] + ta_zz_yyz_1[j];

                    tez_yzz_yyz_0[j] = pa_y[j] * tez_zz_yyz_0[j] - pc_y[j] * tez_zz_yyz_1[j] + fl1_fx * tez_zz_yz_0[j] - fl1_fx * tez_zz_yz_1[j];

                    tex_yzz_yzz_0[j] = pa_y[j] * tex_zz_yzz_0[j] - pc_y[j] * tex_zz_yzz_1[j] + 0.5 * fl1_fx * tex_zz_zz_0[j] - 0.5 * fl1_fx * tex_zz_zz_1[j];

                    tey_yzz_yzz_0[j] = pa_y[j] * tey_zz_yzz_0[j] - pc_y[j] * tey_zz_yzz_1[j] + 0.5 * fl1_fx * tey_zz_zz_0[j] - 0.5 * fl1_fx * tey_zz_zz_1[j] + ta_zz_yzz_1[j];

                    tez_yzz_yzz_0[j] = pa_y[j] * tez_zz_yzz_0[j] - pc_y[j] * tez_zz_yzz_1[j] + 0.5 * fl1_fx * tez_zz_zz_0[j] - 0.5 * fl1_fx * tez_zz_zz_1[j];

                    tex_yzz_zzz_0[j] = pa_y[j] * tex_zz_zzz_0[j] - pc_y[j] * tex_zz_zzz_1[j];

                    tey_yzz_zzz_0[j] = pa_y[j] * tey_zz_zzz_0[j] - pc_y[j] * tey_zz_zzz_1[j] + ta_zz_zzz_1[j];

                    tez_yzz_zzz_0[j] = pa_y[j] * tez_zz_zzz_0[j] - pc_y[j] * tez_zz_zzz_1[j];

                    tex_zzz_xxx_0[j] = pa_z[j] * tex_zz_xxx_0[j] - pc_z[j] * tex_zz_xxx_1[j] + fl1_fx * tex_z_xxx_0[j] - fl1_fx * tex_z_xxx_1[j];

                    tey_zzz_xxx_0[j] = pa_z[j] * tey_zz_xxx_0[j] - pc_z[j] * tey_zz_xxx_1[j] + fl1_fx * tey_z_xxx_0[j] - fl1_fx * tey_z_xxx_1[j];

                    tez_zzz_xxx_0[j] = pa_z[j] * tez_zz_xxx_0[j] - pc_z[j] * tez_zz_xxx_1[j] + fl1_fx * tez_z_xxx_0[j] - fl1_fx * tez_z_xxx_1[j] + ta_zz_xxx_1[j];

                    tex_zzz_xxy_0[j] = pa_z[j] * tex_zz_xxy_0[j] - pc_z[j] * tex_zz_xxy_1[j] + fl1_fx * tex_z_xxy_0[j] - fl1_fx * tex_z_xxy_1[j];

                    tey_zzz_xxy_0[j] = pa_z[j] * tey_zz_xxy_0[j] - pc_z[j] * tey_zz_xxy_1[j] + fl1_fx * tey_z_xxy_0[j] - fl1_fx * tey_z_xxy_1[j];

                    tez_zzz_xxy_0[j] = pa_z[j] * tez_zz_xxy_0[j] - pc_z[j] * tez_zz_xxy_1[j] + fl1_fx * tez_z_xxy_0[j] - fl1_fx * tez_z_xxy_1[j] + ta_zz_xxy_1[j];

                    tex_zzz_xxz_0[j] = pa_z[j] * tex_zz_xxz_0[j] - pc_z[j] * tex_zz_xxz_1[j] + fl1_fx * tex_z_xxz_0[j] - fl1_fx * tex_z_xxz_1[j] + 0.5 * fl1_fx * tex_zz_xx_0[j] - 0.5 * fl1_fx * tex_zz_xx_1[j];

                    tey_zzz_xxz_0[j] = pa_z[j] * tey_zz_xxz_0[j] - pc_z[j] * tey_zz_xxz_1[j] + fl1_fx * tey_z_xxz_0[j] - fl1_fx * tey_z_xxz_1[j] + 0.5 * fl1_fx * tey_zz_xx_0[j] - 0.5 * fl1_fx * tey_zz_xx_1[j];

                    tez_zzz_xxz_0[j] = pa_z[j] * tez_zz_xxz_0[j] - pc_z[j] * tez_zz_xxz_1[j] + fl1_fx * tez_z_xxz_0[j] - fl1_fx * tez_z_xxz_1[j] + 0.5 * fl1_fx * tez_zz_xx_0[j] - 0.5 * fl1_fx * tez_zz_xx_1[j] + ta_zz_xxz_1[j];

                    tex_zzz_xyy_0[j] = pa_z[j] * tex_zz_xyy_0[j] - pc_z[j] * tex_zz_xyy_1[j] + fl1_fx * tex_z_xyy_0[j] - fl1_fx * tex_z_xyy_1[j];

                    tey_zzz_xyy_0[j] = pa_z[j] * tey_zz_xyy_0[j] - pc_z[j] * tey_zz_xyy_1[j] + fl1_fx * tey_z_xyy_0[j] - fl1_fx * tey_z_xyy_1[j];

                    tez_zzz_xyy_0[j] = pa_z[j] * tez_zz_xyy_0[j] - pc_z[j] * tez_zz_xyy_1[j] + fl1_fx * tez_z_xyy_0[j] - fl1_fx * tez_z_xyy_1[j] + ta_zz_xyy_1[j];

                    tex_zzz_xyz_0[j] = pa_z[j] * tex_zz_xyz_0[j] - pc_z[j] * tex_zz_xyz_1[j] + fl1_fx * tex_z_xyz_0[j] - fl1_fx * tex_z_xyz_1[j] + 0.5 * fl1_fx * tex_zz_xy_0[j] - 0.5 * fl1_fx * tex_zz_xy_1[j];

                    tey_zzz_xyz_0[j] = pa_z[j] * tey_zz_xyz_0[j] - pc_z[j] * tey_zz_xyz_1[j] + fl1_fx * tey_z_xyz_0[j] - fl1_fx * tey_z_xyz_1[j] + 0.5 * fl1_fx * tey_zz_xy_0[j] - 0.5 * fl1_fx * tey_zz_xy_1[j];

                    tez_zzz_xyz_0[j] = pa_z[j] * tez_zz_xyz_0[j] - pc_z[j] * tez_zz_xyz_1[j] + fl1_fx * tez_z_xyz_0[j] - fl1_fx * tez_z_xyz_1[j] + 0.5 * fl1_fx * tez_zz_xy_0[j] - 0.5 * fl1_fx * tez_zz_xy_1[j] + ta_zz_xyz_1[j];

                    tex_zzz_xzz_0[j] = pa_z[j] * tex_zz_xzz_0[j] - pc_z[j] * tex_zz_xzz_1[j] + fl1_fx * tex_z_xzz_0[j] - fl1_fx * tex_z_xzz_1[j] + fl1_fx * tex_zz_xz_0[j] - fl1_fx * tex_zz_xz_1[j];

                    tey_zzz_xzz_0[j] = pa_z[j] * tey_zz_xzz_0[j] - pc_z[j] * tey_zz_xzz_1[j] + fl1_fx * tey_z_xzz_0[j] - fl1_fx * tey_z_xzz_1[j] + fl1_fx * tey_zz_xz_0[j] - fl1_fx * tey_zz_xz_1[j];

                    tez_zzz_xzz_0[j] = pa_z[j] * tez_zz_xzz_0[j] - pc_z[j] * tez_zz_xzz_1[j] + fl1_fx * tez_z_xzz_0[j] - fl1_fx * tez_z_xzz_1[j] + fl1_fx * tez_zz_xz_0[j] - fl1_fx * tez_zz_xz_1[j] + ta_zz_xzz_1[j];

                    tex_zzz_yyy_0[j] = pa_z[j] * tex_zz_yyy_0[j] - pc_z[j] * tex_zz_yyy_1[j] + fl1_fx * tex_z_yyy_0[j] - fl1_fx * tex_z_yyy_1[j];

                    tey_zzz_yyy_0[j] = pa_z[j] * tey_zz_yyy_0[j] - pc_z[j] * tey_zz_yyy_1[j] + fl1_fx * tey_z_yyy_0[j] - fl1_fx * tey_z_yyy_1[j];

                    tez_zzz_yyy_0[j] = pa_z[j] * tez_zz_yyy_0[j] - pc_z[j] * tez_zz_yyy_1[j] + fl1_fx * tez_z_yyy_0[j] - fl1_fx * tez_z_yyy_1[j] + ta_zz_yyy_1[j];

                    tex_zzz_yyz_0[j] = pa_z[j] * tex_zz_yyz_0[j] - pc_z[j] * tex_zz_yyz_1[j] + fl1_fx * tex_z_yyz_0[j] - fl1_fx * tex_z_yyz_1[j] + 0.5 * fl1_fx * tex_zz_yy_0[j] - 0.5 * fl1_fx * tex_zz_yy_1[j];

                    tey_zzz_yyz_0[j] = pa_z[j] * tey_zz_yyz_0[j] - pc_z[j] * tey_zz_yyz_1[j] + fl1_fx * tey_z_yyz_0[j] - fl1_fx * tey_z_yyz_1[j] + 0.5 * fl1_fx * tey_zz_yy_0[j] - 0.5 * fl1_fx * tey_zz_yy_1[j];

                    tez_zzz_yyz_0[j] = pa_z[j] * tez_zz_yyz_0[j] - pc_z[j] * tez_zz_yyz_1[j] + fl1_fx * tez_z_yyz_0[j] - fl1_fx * tez_z_yyz_1[j] + 0.5 * fl1_fx * tez_zz_yy_0[j] - 0.5 * fl1_fx * tez_zz_yy_1[j] + ta_zz_yyz_1[j];

                    tex_zzz_yzz_0[j] = pa_z[j] * tex_zz_yzz_0[j] - pc_z[j] * tex_zz_yzz_1[j] + fl1_fx * tex_z_yzz_0[j] - fl1_fx * tex_z_yzz_1[j] + fl1_fx * tex_zz_yz_0[j] - fl1_fx * tex_zz_yz_1[j];

                    tey_zzz_yzz_0[j] = pa_z[j] * tey_zz_yzz_0[j] - pc_z[j] * tey_zz_yzz_1[j] + fl1_fx * tey_z_yzz_0[j] - fl1_fx * tey_z_yzz_1[j] + fl1_fx * tey_zz_yz_0[j] - fl1_fx * tey_zz_yz_1[j];

                    tez_zzz_yzz_0[j] = pa_z[j] * tez_zz_yzz_0[j] - pc_z[j] * tez_zz_yzz_1[j] + fl1_fx * tez_z_yzz_0[j] - fl1_fx * tez_z_yzz_1[j] + fl1_fx * tez_zz_yz_0[j] - fl1_fx * tez_zz_yz_1[j] + ta_zz_yzz_1[j];

                    tex_zzz_zzz_0[j] = pa_z[j] * tex_zz_zzz_0[j] - pc_z[j] * tex_zz_zzz_1[j] + fl1_fx * tex_z_zzz_0[j] - fl1_fx * tex_z_zzz_1[j] + 1.5 * fl1_fx * tex_zz_zz_0[j] - 1.5 * fl1_fx * tex_zz_zz_1[j];

                    tey_zzz_zzz_0[j] = pa_z[j] * tey_zz_zzz_0[j] - pc_z[j] * tey_zz_zzz_1[j] + fl1_fx * tey_z_zzz_0[j] - fl1_fx * tey_z_zzz_1[j] + 1.5 * fl1_fx * tey_zz_zz_0[j] - 1.5 * fl1_fx * tey_zz_zz_1[j];

                    tez_zzz_zzz_0[j] = pa_z[j] * tez_zz_zzz_0[j] - pc_z[j] * tez_zz_zzz_1[j] + fl1_fx * tez_z_zzz_0[j] - fl1_fx * tez_z_zzz_1[j] + 1.5 * fl1_fx * tez_zz_zz_0[j] - 1.5 * fl1_fx * tez_zz_zz_1[j] + ta_zz_zzz_1[j];
                }

                idx++;
            }
        }
    }


} // efieldrecfunc namespace

