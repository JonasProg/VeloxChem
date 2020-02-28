//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "ElectronRepulsionRecFuncForIF.hpp"

namespace erirecfunc { // erirecfunc namespace

    void
    compElectronRepulsionForSISF(      CMemBlock2D<double>* primBuffer,
                                 const CRecursionMap&       recursionMap,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& wpDistances,
                                 const CGtoPairsBlock&      braGtoPairsBlock,
                                 const CGtoPairsBlock&      ketGtoPairsBlock,
                                 const int32_t              nKetPrimPairs,
                                 const int32_t              iContrPair)
    {
        erirecfunc::compElectronRepulsionForSISF_0_94(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      wpDistances, 
                                                      braGtoPairsBlock,
                                                      ketGtoPairsBlock,
                                                      nKetPrimPairs,
                                                      iContrPair); 

        erirecfunc::compElectronRepulsionForSISF_94_187(primBuffer,
                                                        recursionMap,
                                                        osFactors,
                                                        wpDistances, 
                                                        braGtoPairsBlock,
                                                        ketGtoPairsBlock,
                                                        nKetPrimPairs,
                                                        iContrPair); 

        erirecfunc::compElectronRepulsionForSISF_187_280(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 
    }

    void
    compElectronRepulsionForSISF_0_94(      CMemBlock2D<double>* primBuffer,
                                      const CRecursionMap&       recursionMap,
                                      const CMemBlock2D<double>& osFactors,
                                      const CMemBlock2D<double>& wpDistances,
                                      const CGtoPairsBlock&      braGtoPairsBlock,
                                      const CGtoPairsBlock&      ketGtoPairsBlock,
                                      const int32_t              nKetPrimPairs,
                                      const int32_t              iContrPair)
    {
        // Batch of Integrals (0,94)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_2_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {2, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrPair]; i < epos[iContrPair]; i++)
            {
                // set up pointers to Obara-Saika factors

                double fx = b_fx[i];

                auto fza = osFactors.data(4 * idx + 2);

                auto fxn = osFactors.data(4 * idx);

                // set up distances R(PB) = P - B

                auto pb_x = r_pb_x[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tg_xxxxx_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx); 

                auto tg_xxxxx_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 1); 

                auto tg_xxxxx_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 2); 

                auto tg_xxxxx_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 3); 

                auto tg_xxxxx_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 4); 

                auto tg_xxxxx_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 5); 

                auto tg_xxxxx_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 6); 

                auto tg_xxxxx_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 7); 

                auto tg_xxxxx_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 8); 

                auto tg_xxxxx_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 9); 

                auto tg_xxxxy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 10); 

                auto tg_xxxxy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 11); 

                auto tg_xxxxy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 12); 

                auto tg_xxxxy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 13); 

                auto tg_xxxxy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 14); 

                auto tg_xxxxy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 15); 

                auto tg_xxxxy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 16); 

                auto tg_xxxxy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 17); 

                auto tg_xxxxy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 18); 

                auto tg_xxxxy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 19); 

                auto tg_xxxxz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 20); 

                auto tg_xxxxz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 21); 

                auto tg_xxxxz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 22); 

                auto tg_xxxxz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 23); 

                auto tg_xxxxz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 24); 

                auto tg_xxxxz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 25); 

                auto tg_xxxxz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 26); 

                auto tg_xxxxz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 27); 

                auto tg_xxxxz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 28); 

                auto tg_xxxxz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 29); 

                auto tg_xxxyy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 30); 

                auto tg_xxxyy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 31); 

                auto tg_xxxyy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 32); 

                auto tg_xxxyy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 33); 

                auto tg_xxxyy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 34); 

                auto tg_xxxyy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 35); 

                auto tg_xxxyy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 36); 

                auto tg_xxxyy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 37); 

                auto tg_xxxyy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 38); 

                auto tg_xxxyy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 39); 

                auto tg_xxxyz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 40); 

                auto tg_xxxyz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 41); 

                auto tg_xxxyz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 42); 

                auto tg_xxxyz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 43); 

                auto tg_xxxyz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 44); 

                auto tg_xxxyz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 45); 

                auto tg_xxxyz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 46); 

                auto tg_xxxyz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 47); 

                auto tg_xxxyz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 48); 

                auto tg_xxxyz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 49); 

                auto tg_xxxzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 50); 

                auto tg_xxxzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 51); 

                auto tg_xxxzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 52); 

                auto tg_xxxzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 53); 

                auto tg_xxxzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 54); 

                auto tg_xxxzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 55); 

                auto tg_xxxzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 56); 

                auto tg_xxxzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 57); 

                auto tg_xxxzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 58); 

                auto tg_xxxzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 59); 

                auto tg_xxyyy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 60); 

                auto tg_xxyyy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 61); 

                auto tg_xxyyy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 62); 

                auto tg_xxyyy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 63); 

                auto tg_xxyyy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 64); 

                auto tg_xxyyy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 65); 

                auto tg_xxyyy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 66); 

                auto tg_xxyyy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 67); 

                auto tg_xxyyy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 68); 

                auto tg_xxyyy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 69); 

                auto tg_xxyyz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 70); 

                auto tg_xxyyz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 71); 

                auto tg_xxyyz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 72); 

                auto tg_xxyyz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 73); 

                auto tg_xxyyz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 74); 

                auto tg_xxyyz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 75); 

                auto tg_xxyyz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 76); 

                auto tg_xxyyz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 77); 

                auto tg_xxyyz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 78); 

                auto tg_xxyyz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 79); 

                auto tg_xxyzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 80); 

                auto tg_xxyzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 81); 

                auto tg_xxyzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 82); 

                auto tg_xxyzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 83); 

                auto tg_xxyzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 84); 

                auto tg_xxyzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 85); 

                auto tg_xxyzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 86); 

                auto tg_xxyzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 87); 

                auto tg_xxyzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 88); 

                auto tg_xxyzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 89); 

                auto tg_xxzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 90); 

                auto tg_xxzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 91); 

                auto tg_xxzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 92); 

                auto tg_xxzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 93); 

                auto tg_xxxxx_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx); 

                auto tg_xxxxx_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 1); 

                auto tg_xxxxx_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 2); 

                auto tg_xxxxx_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 3); 

                auto tg_xxxxx_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 4); 

                auto tg_xxxxx_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 5); 

                auto tg_xxxxx_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 6); 

                auto tg_xxxxx_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 7); 

                auto tg_xxxxx_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 8); 

                auto tg_xxxxx_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 9); 

                auto tg_xxxxy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 10); 

                auto tg_xxxxy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 11); 

                auto tg_xxxxy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 12); 

                auto tg_xxxxy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 13); 

                auto tg_xxxxy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 14); 

                auto tg_xxxxy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 15); 

                auto tg_xxxxy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 16); 

                auto tg_xxxxy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 17); 

                auto tg_xxxxy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 18); 

                auto tg_xxxxy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 19); 

                auto tg_xxxxz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 20); 

                auto tg_xxxxz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 21); 

                auto tg_xxxxz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 22); 

                auto tg_xxxxz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 23); 

                auto tg_xxxxz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 24); 

                auto tg_xxxxz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 25); 

                auto tg_xxxxz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 26); 

                auto tg_xxxxz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 27); 

                auto tg_xxxxz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 28); 

                auto tg_xxxxz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 29); 

                auto tg_xxxyy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 30); 

                auto tg_xxxyy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 31); 

                auto tg_xxxyy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 32); 

                auto tg_xxxyy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 33); 

                auto tg_xxxyy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 34); 

                auto tg_xxxyy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 35); 

                auto tg_xxxyy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 36); 

                auto tg_xxxyy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 37); 

                auto tg_xxxyy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 38); 

                auto tg_xxxyy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 39); 

                auto tg_xxxyz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 40); 

                auto tg_xxxyz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 41); 

                auto tg_xxxyz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 42); 

                auto tg_xxxyz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 43); 

                auto tg_xxxyz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 44); 

                auto tg_xxxyz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 45); 

                auto tg_xxxyz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 46); 

                auto tg_xxxyz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 47); 

                auto tg_xxxyz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 48); 

                auto tg_xxxyz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 49); 

                auto tg_xxxzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 50); 

                auto tg_xxxzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 51); 

                auto tg_xxxzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 52); 

                auto tg_xxxzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 53); 

                auto tg_xxxzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 54); 

                auto tg_xxxzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 55); 

                auto tg_xxxzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 56); 

                auto tg_xxxzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 57); 

                auto tg_xxxzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 58); 

                auto tg_xxxzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 59); 

                auto tg_xxyyy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 60); 

                auto tg_xxyyy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 61); 

                auto tg_xxyyy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 62); 

                auto tg_xxyyy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 63); 

                auto tg_xxyyy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 64); 

                auto tg_xxyyy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 65); 

                auto tg_xxyyy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 66); 

                auto tg_xxyyy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 67); 

                auto tg_xxyyy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 68); 

                auto tg_xxyyy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 69); 

                auto tg_xxyyz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 70); 

                auto tg_xxyyz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 71); 

                auto tg_xxyyz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 72); 

                auto tg_xxyyz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 73); 

                auto tg_xxyyz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 74); 

                auto tg_xxyyz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 75); 

                auto tg_xxyyz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 76); 

                auto tg_xxyyz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 77); 

                auto tg_xxyyz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 78); 

                auto tg_xxyyz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 79); 

                auto tg_xxyzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 80); 

                auto tg_xxyzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 81); 

                auto tg_xxyzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 82); 

                auto tg_xxyzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 83); 

                auto tg_xxyzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 84); 

                auto tg_xxyzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 85); 

                auto tg_xxyzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 86); 

                auto tg_xxyzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 87); 

                auto tg_xxyzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 88); 

                auto tg_xxyzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 89); 

                auto tg_xxzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 90); 

                auto tg_xxzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 91); 

                auto tg_xxzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 92); 

                auto tg_xxzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 93); 

                auto tg_xxxx_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx); 

                auto tg_xxxx_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 1); 

                auto tg_xxxx_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 2); 

                auto tg_xxxx_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 3); 

                auto tg_xxxx_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 4); 

                auto tg_xxxx_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 5); 

                auto tg_xxxx_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 6); 

                auto tg_xxxx_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 7); 

                auto tg_xxxx_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 8); 

                auto tg_xxxx_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 9); 

                auto tg_xxxy_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 10); 

                auto tg_xxxy_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 11); 

                auto tg_xxxy_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 12); 

                auto tg_xxxy_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 13); 

                auto tg_xxxy_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 14); 

                auto tg_xxxy_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 15); 

                auto tg_xxxy_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 16); 

                auto tg_xxxy_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 17); 

                auto tg_xxxy_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 18); 

                auto tg_xxxy_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 19); 

                auto tg_xxxz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 20); 

                auto tg_xxxz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 21); 

                auto tg_xxxz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 22); 

                auto tg_xxxz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 23); 

                auto tg_xxxz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 24); 

                auto tg_xxxz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 25); 

                auto tg_xxxz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 26); 

                auto tg_xxxz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 27); 

                auto tg_xxxz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 28); 

                auto tg_xxxz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 29); 

                auto tg_xxyy_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 30); 

                auto tg_xxyy_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 31); 

                auto tg_xxyy_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 32); 

                auto tg_xxyy_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 33); 

                auto tg_xxyy_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 34); 

                auto tg_xxyy_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 35); 

                auto tg_xxyy_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 36); 

                auto tg_xxyy_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 37); 

                auto tg_xxyy_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 38); 

                auto tg_xxyy_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 39); 

                auto tg_xxyz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 40); 

                auto tg_xxyz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 41); 

                auto tg_xxyz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 42); 

                auto tg_xxyz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 43); 

                auto tg_xxyz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 44); 

                auto tg_xxyz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 45); 

                auto tg_xxyz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 46); 

                auto tg_xxyz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 47); 

                auto tg_xxyz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 48); 

                auto tg_xxyz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 49); 

                auto tg_xxzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 50); 

                auto tg_xxzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 51); 

                auto tg_xxzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 52); 

                auto tg_xxzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 53); 

                auto tg_xxzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 54); 

                auto tg_xxzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 55); 

                auto tg_xxzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 56); 

                auto tg_xxzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 57); 

                auto tg_xxzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 58); 

                auto tg_xxzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 59); 

                auto tg_xyyy_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 60); 

                auto tg_xyyy_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 61); 

                auto tg_xyyy_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 62); 

                auto tg_xyyy_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 63); 

                auto tg_xyyy_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 64); 

                auto tg_xyyy_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 65); 

                auto tg_xyyy_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 66); 

                auto tg_xyyy_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 67); 

                auto tg_xyyy_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 68); 

                auto tg_xyyy_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 69); 

                auto tg_xyyz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 70); 

                auto tg_xyyz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 71); 

                auto tg_xyyz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 72); 

                auto tg_xyyz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 73); 

                auto tg_xyyz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 74); 

                auto tg_xyyz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 75); 

                auto tg_xyyz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 76); 

                auto tg_xyyz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 77); 

                auto tg_xyyz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 78); 

                auto tg_xyyz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 79); 

                auto tg_xyzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 80); 

                auto tg_xyzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 81); 

                auto tg_xyzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 82); 

                auto tg_xyzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 83); 

                auto tg_xyzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 84); 

                auto tg_xyzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 85); 

                auto tg_xyzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 86); 

                auto tg_xyzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 87); 

                auto tg_xyzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 88); 

                auto tg_xyzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 89); 

                auto tg_xzzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 90); 

                auto tg_xzzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 91); 

                auto tg_xzzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 92); 

                auto tg_xzzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 93); 

                auto tg_xxxx_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx); 

                auto tg_xxxx_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 1); 

                auto tg_xxxx_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 2); 

                auto tg_xxxx_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 3); 

                auto tg_xxxx_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 4); 

                auto tg_xxxx_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 5); 

                auto tg_xxxx_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 6); 

                auto tg_xxxx_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 7); 

                auto tg_xxxx_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 8); 

                auto tg_xxxx_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 9); 

                auto tg_xxxy_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 10); 

                auto tg_xxxy_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 11); 

                auto tg_xxxy_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 12); 

                auto tg_xxxy_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 13); 

                auto tg_xxxy_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 14); 

                auto tg_xxxy_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 15); 

                auto tg_xxxy_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 16); 

                auto tg_xxxy_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 17); 

                auto tg_xxxy_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 18); 

                auto tg_xxxy_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 19); 

                auto tg_xxxz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 20); 

                auto tg_xxxz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 21); 

                auto tg_xxxz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 22); 

                auto tg_xxxz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 23); 

                auto tg_xxxz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 24); 

                auto tg_xxxz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 25); 

                auto tg_xxxz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 26); 

                auto tg_xxxz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 27); 

                auto tg_xxxz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 28); 

                auto tg_xxxz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 29); 

                auto tg_xxyy_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 30); 

                auto tg_xxyy_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 31); 

                auto tg_xxyy_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 32); 

                auto tg_xxyy_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 33); 

                auto tg_xxyy_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 34); 

                auto tg_xxyy_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 35); 

                auto tg_xxyy_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 36); 

                auto tg_xxyy_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 37); 

                auto tg_xxyy_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 38); 

                auto tg_xxyy_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 39); 

                auto tg_xxyz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 40); 

                auto tg_xxyz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 41); 

                auto tg_xxyz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 42); 

                auto tg_xxyz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 43); 

                auto tg_xxyz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 44); 

                auto tg_xxyz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 45); 

                auto tg_xxyz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 46); 

                auto tg_xxyz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 47); 

                auto tg_xxyz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 48); 

                auto tg_xxyz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 49); 

                auto tg_xxzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 50); 

                auto tg_xxzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 51); 

                auto tg_xxzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 52); 

                auto tg_xxzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 53); 

                auto tg_xxzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 54); 

                auto tg_xxzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 55); 

                auto tg_xxzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 56); 

                auto tg_xxzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 57); 

                auto tg_xxzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 58); 

                auto tg_xxzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 59); 

                auto tg_xyyy_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 60); 

                auto tg_xyyy_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 61); 

                auto tg_xyyy_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 62); 

                auto tg_xyyy_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 63); 

                auto tg_xyyy_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 64); 

                auto tg_xyyy_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 65); 

                auto tg_xyyy_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 66); 

                auto tg_xyyy_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 67); 

                auto tg_xyyy_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 68); 

                auto tg_xyyy_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 69); 

                auto tg_xyyz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 70); 

                auto tg_xyyz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 71); 

                auto tg_xyyz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 72); 

                auto tg_xyyz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 73); 

                auto tg_xyyz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 74); 

                auto tg_xyyz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 75); 

                auto tg_xyyz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 76); 

                auto tg_xyyz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 77); 

                auto tg_xyyz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 78); 

                auto tg_xyyz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 79); 

                auto tg_xyzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 80); 

                auto tg_xyzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 81); 

                auto tg_xyzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 82); 

                auto tg_xyzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 83); 

                auto tg_xyzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 84); 

                auto tg_xyzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 85); 

                auto tg_xyzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 86); 

                auto tg_xyzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 87); 

                auto tg_xyzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 88); 

                auto tg_xyzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 89); 

                auto tg_xzzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 90); 

                auto tg_xzzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 91); 

                auto tg_xzzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 92); 

                auto tg_xzzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 93); 

                auto tg_xxxxx_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx); 

                auto tg_xxxxx_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 1); 

                auto tg_xxxxx_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 2); 

                auto tg_xxxxx_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 3); 

                auto tg_xxxxx_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 4); 

                auto tg_xxxxx_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 5); 

                auto tg_xxxxy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 6); 

                auto tg_xxxxy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 7); 

                auto tg_xxxxy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 8); 

                auto tg_xxxxy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 9); 

                auto tg_xxxxy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 10); 

                auto tg_xxxxy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 11); 

                auto tg_xxxxz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 12); 

                auto tg_xxxxz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 13); 

                auto tg_xxxxz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 14); 

                auto tg_xxxxz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 15); 

                auto tg_xxxxz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 16); 

                auto tg_xxxxz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 17); 

                auto tg_xxxyy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 18); 

                auto tg_xxxyy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 19); 

                auto tg_xxxyy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 20); 

                auto tg_xxxyy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 21); 

                auto tg_xxxyy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 22); 

                auto tg_xxxyy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 23); 

                auto tg_xxxyz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 24); 

                auto tg_xxxyz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 25); 

                auto tg_xxxyz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 26); 

                auto tg_xxxyz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 27); 

                auto tg_xxxyz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 28); 

                auto tg_xxxyz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 29); 

                auto tg_xxxzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 30); 

                auto tg_xxxzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 31); 

                auto tg_xxxzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 32); 

                auto tg_xxxzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 33); 

                auto tg_xxxzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 34); 

                auto tg_xxxzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 35); 

                auto tg_xxyyy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 36); 

                auto tg_xxyyy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 37); 

                auto tg_xxyyy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 38); 

                auto tg_xxyyy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 39); 

                auto tg_xxyyy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 40); 

                auto tg_xxyyy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 41); 

                auto tg_xxyyz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 42); 

                auto tg_xxyyz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 43); 

                auto tg_xxyyz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 44); 

                auto tg_xxyyz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 45); 

                auto tg_xxyyz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 46); 

                auto tg_xxyyz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 47); 

                auto tg_xxyzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 48); 

                auto tg_xxyzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 49); 

                auto tg_xxyzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 50); 

                auto tg_xxyzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 51); 

                auto tg_xxyzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 52); 

                auto tg_xxyzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 53); 

                auto tg_xxzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 54); 

                auto tg_xxzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 55); 

                auto tg_xxzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 56); 

                auto tg_xxzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 57); 

                // set up pointers to integrals

                auto tg_xxxxxx_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx); 

                auto tg_xxxxxx_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 1); 

                auto tg_xxxxxx_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 2); 

                auto tg_xxxxxx_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 3); 

                auto tg_xxxxxx_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 4); 

                auto tg_xxxxxx_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 5); 

                auto tg_xxxxxx_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 6); 

                auto tg_xxxxxx_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 7); 

                auto tg_xxxxxx_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 8); 

                auto tg_xxxxxx_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 9); 

                auto tg_xxxxxy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 10); 

                auto tg_xxxxxy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 11); 

                auto tg_xxxxxy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 12); 

                auto tg_xxxxxy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 13); 

                auto tg_xxxxxy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 14); 

                auto tg_xxxxxy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 15); 

                auto tg_xxxxxy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 16); 

                auto tg_xxxxxy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 17); 

                auto tg_xxxxxy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 18); 

                auto tg_xxxxxy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 19); 

                auto tg_xxxxxz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 20); 

                auto tg_xxxxxz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 21); 

                auto tg_xxxxxz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 22); 

                auto tg_xxxxxz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 23); 

                auto tg_xxxxxz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 24); 

                auto tg_xxxxxz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 25); 

                auto tg_xxxxxz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 26); 

                auto tg_xxxxxz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 27); 

                auto tg_xxxxxz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 28); 

                auto tg_xxxxxz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 29); 

                auto tg_xxxxyy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 30); 

                auto tg_xxxxyy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 31); 

                auto tg_xxxxyy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 32); 

                auto tg_xxxxyy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 33); 

                auto tg_xxxxyy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 34); 

                auto tg_xxxxyy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 35); 

                auto tg_xxxxyy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 36); 

                auto tg_xxxxyy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 37); 

                auto tg_xxxxyy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 38); 

                auto tg_xxxxyy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 39); 

                auto tg_xxxxyz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 40); 

                auto tg_xxxxyz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 41); 

                auto tg_xxxxyz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 42); 

                auto tg_xxxxyz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 43); 

                auto tg_xxxxyz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 44); 

                auto tg_xxxxyz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 45); 

                auto tg_xxxxyz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 46); 

                auto tg_xxxxyz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 47); 

                auto tg_xxxxyz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 48); 

                auto tg_xxxxyz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 49); 

                auto tg_xxxxzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 50); 

                auto tg_xxxxzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 51); 

                auto tg_xxxxzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 52); 

                auto tg_xxxxzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 53); 

                auto tg_xxxxzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 54); 

                auto tg_xxxxzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 55); 

                auto tg_xxxxzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 56); 

                auto tg_xxxxzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 57); 

                auto tg_xxxxzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 58); 

                auto tg_xxxxzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 59); 

                auto tg_xxxyyy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 60); 

                auto tg_xxxyyy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 61); 

                auto tg_xxxyyy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 62); 

                auto tg_xxxyyy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 63); 

                auto tg_xxxyyy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 64); 

                auto tg_xxxyyy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 65); 

                auto tg_xxxyyy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 66); 

                auto tg_xxxyyy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 67); 

                auto tg_xxxyyy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 68); 

                auto tg_xxxyyy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 69); 

                auto tg_xxxyyz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 70); 

                auto tg_xxxyyz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 71); 

                auto tg_xxxyyz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 72); 

                auto tg_xxxyyz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 73); 

                auto tg_xxxyyz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 74); 

                auto tg_xxxyyz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 75); 

                auto tg_xxxyyz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 76); 

                auto tg_xxxyyz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 77); 

                auto tg_xxxyyz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 78); 

                auto tg_xxxyyz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 79); 

                auto tg_xxxyzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 80); 

                auto tg_xxxyzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 81); 

                auto tg_xxxyzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 82); 

                auto tg_xxxyzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 83); 

                auto tg_xxxyzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 84); 

                auto tg_xxxyzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 85); 

                auto tg_xxxyzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 86); 

                auto tg_xxxyzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 87); 

                auto tg_xxxyzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 88); 

                auto tg_xxxyzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 89); 

                auto tg_xxxzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 90); 

                auto tg_xxxzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 91); 

                auto tg_xxxzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 92); 

                auto tg_xxxzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 93); 

                // Batch of Integrals (0,94)

                #pragma omp simd aligned(fxn, fza, tg_xxxx_xxx_0, tg_xxxx_xxx_1, tg_xxxx_xxy_0, tg_xxxx_xxy_1, \
                                         tg_xxxx_xxz_0, tg_xxxx_xxz_1, tg_xxxx_xyy_0, tg_xxxx_xyy_1, tg_xxxx_xyz_0, \
                                         tg_xxxx_xyz_1, tg_xxxx_xzz_0, tg_xxxx_xzz_1, tg_xxxx_yyy_0, tg_xxxx_yyy_1, \
                                         tg_xxxx_yyz_0, tg_xxxx_yyz_1, tg_xxxx_yzz_0, tg_xxxx_yzz_1, tg_xxxx_zzz_0, \
                                         tg_xxxx_zzz_1, tg_xxxxx_xx_1, tg_xxxxx_xxx_0, tg_xxxxx_xxx_1, tg_xxxxx_xxy_0, \
                                         tg_xxxxx_xxy_1, tg_xxxxx_xxz_0, tg_xxxxx_xxz_1, tg_xxxxx_xy_1, tg_xxxxx_xyy_0, \
                                         tg_xxxxx_xyy_1, tg_xxxxx_xyz_0, tg_xxxxx_xyz_1, tg_xxxxx_xz_1, tg_xxxxx_xzz_0, \
                                         tg_xxxxx_xzz_1, tg_xxxxx_yy_1, tg_xxxxx_yyy_0, tg_xxxxx_yyy_1, tg_xxxxx_yyz_0, \
                                         tg_xxxxx_yyz_1, tg_xxxxx_yz_1, tg_xxxxx_yzz_0, tg_xxxxx_yzz_1, tg_xxxxx_zz_1, \
                                         tg_xxxxx_zzz_0, tg_xxxxx_zzz_1, tg_xxxxxx_xxx_0, tg_xxxxxx_xxy_0, tg_xxxxxx_xxz_0, \
                                         tg_xxxxxx_xyy_0, tg_xxxxxx_xyz_0, tg_xxxxxx_xzz_0, tg_xxxxxx_yyy_0, tg_xxxxxx_yyz_0, \
                                         tg_xxxxxx_yzz_0, tg_xxxxxx_zzz_0, tg_xxxxxy_xxx_0, tg_xxxxxy_xxy_0, tg_xxxxxy_xxz_0, \
                                         tg_xxxxxy_xyy_0, tg_xxxxxy_xyz_0, tg_xxxxxy_xzz_0, tg_xxxxxy_yyy_0, tg_xxxxxy_yyz_0, \
                                         tg_xxxxxy_yzz_0, tg_xxxxxy_zzz_0, tg_xxxxxz_xxx_0, tg_xxxxxz_xxy_0, tg_xxxxxz_xxz_0, \
                                         tg_xxxxxz_xyy_0, tg_xxxxxz_xyz_0, tg_xxxxxz_xzz_0, tg_xxxxxz_yyy_0, tg_xxxxxz_yyz_0, \
                                         tg_xxxxxz_yzz_0, tg_xxxxxz_zzz_0, tg_xxxxy_xx_1, tg_xxxxy_xxx_0, tg_xxxxy_xxx_1, \
                                         tg_xxxxy_xxy_0, tg_xxxxy_xxy_1, tg_xxxxy_xxz_0, tg_xxxxy_xxz_1, tg_xxxxy_xy_1, \
                                         tg_xxxxy_xyy_0, tg_xxxxy_xyy_1, tg_xxxxy_xyz_0, tg_xxxxy_xyz_1, tg_xxxxy_xz_1, \
                                         tg_xxxxy_xzz_0, tg_xxxxy_xzz_1, tg_xxxxy_yy_1, tg_xxxxy_yyy_0, tg_xxxxy_yyy_1, \
                                         tg_xxxxy_yyz_0, tg_xxxxy_yyz_1, tg_xxxxy_yz_1, tg_xxxxy_yzz_0, tg_xxxxy_yzz_1, \
                                         tg_xxxxy_zz_1, tg_xxxxy_zzz_0, tg_xxxxy_zzz_1, tg_xxxxyy_xxx_0, tg_xxxxyy_xxy_0, \
                                         tg_xxxxyy_xxz_0, tg_xxxxyy_xyy_0, tg_xxxxyy_xyz_0, tg_xxxxyy_xzz_0, tg_xxxxyy_yyy_0, \
                                         tg_xxxxyy_yyz_0, tg_xxxxyy_yzz_0, tg_xxxxyy_zzz_0, tg_xxxxyz_xxx_0, tg_xxxxyz_xxy_0, \
                                         tg_xxxxyz_xxz_0, tg_xxxxyz_xyy_0, tg_xxxxyz_xyz_0, tg_xxxxyz_xzz_0, tg_xxxxyz_yyy_0, \
                                         tg_xxxxyz_yyz_0, tg_xxxxyz_yzz_0, tg_xxxxyz_zzz_0, tg_xxxxz_xx_1, tg_xxxxz_xxx_0, \
                                         tg_xxxxz_xxx_1, tg_xxxxz_xxy_0, tg_xxxxz_xxy_1, tg_xxxxz_xxz_0, tg_xxxxz_xxz_1, \
                                         tg_xxxxz_xy_1, tg_xxxxz_xyy_0, tg_xxxxz_xyy_1, tg_xxxxz_xyz_0, tg_xxxxz_xyz_1, \
                                         tg_xxxxz_xz_1, tg_xxxxz_xzz_0, tg_xxxxz_xzz_1, tg_xxxxz_yy_1, tg_xxxxz_yyy_0, \
                                         tg_xxxxz_yyy_1, tg_xxxxz_yyz_0, tg_xxxxz_yyz_1, tg_xxxxz_yz_1, tg_xxxxz_yzz_0, \
                                         tg_xxxxz_yzz_1, tg_xxxxz_zz_1, tg_xxxxz_zzz_0, tg_xxxxz_zzz_1, tg_xxxxzz_xxx_0, \
                                         tg_xxxxzz_xxy_0, tg_xxxxzz_xxz_0, tg_xxxxzz_xyy_0, tg_xxxxzz_xyz_0, tg_xxxxzz_xzz_0, \
                                         tg_xxxxzz_yyy_0, tg_xxxxzz_yyz_0, tg_xxxxzz_yzz_0, tg_xxxxzz_zzz_0, tg_xxxy_xxx_0, \
                                         tg_xxxy_xxx_1, tg_xxxy_xxy_0, tg_xxxy_xxy_1, tg_xxxy_xxz_0, tg_xxxy_xxz_1, \
                                         tg_xxxy_xyy_0, tg_xxxy_xyy_1, tg_xxxy_xyz_0, tg_xxxy_xyz_1, tg_xxxy_xzz_0, \
                                         tg_xxxy_xzz_1, tg_xxxy_yyy_0, tg_xxxy_yyy_1, tg_xxxy_yyz_0, tg_xxxy_yyz_1, \
                                         tg_xxxy_yzz_0, tg_xxxy_yzz_1, tg_xxxy_zzz_0, tg_xxxy_zzz_1, tg_xxxyy_xx_1, \
                                         tg_xxxyy_xxx_0, tg_xxxyy_xxx_1, tg_xxxyy_xxy_0, tg_xxxyy_xxy_1, tg_xxxyy_xxz_0, \
                                         tg_xxxyy_xxz_1, tg_xxxyy_xy_1, tg_xxxyy_xyy_0, tg_xxxyy_xyy_1, tg_xxxyy_xyz_0, \
                                         tg_xxxyy_xyz_1, tg_xxxyy_xz_1, tg_xxxyy_xzz_0, tg_xxxyy_xzz_1, tg_xxxyy_yy_1, \
                                         tg_xxxyy_yyy_0, tg_xxxyy_yyy_1, tg_xxxyy_yyz_0, tg_xxxyy_yyz_1, tg_xxxyy_yz_1, \
                                         tg_xxxyy_yzz_0, tg_xxxyy_yzz_1, tg_xxxyy_zz_1, tg_xxxyy_zzz_0, tg_xxxyy_zzz_1, \
                                         tg_xxxyyy_xxx_0, tg_xxxyyy_xxy_0, tg_xxxyyy_xxz_0, tg_xxxyyy_xyy_0, tg_xxxyyy_xyz_0, \
                                         tg_xxxyyy_xzz_0, tg_xxxyyy_yyy_0, tg_xxxyyy_yyz_0, tg_xxxyyy_yzz_0, tg_xxxyyy_zzz_0, \
                                         tg_xxxyyz_xxx_0, tg_xxxyyz_xxy_0, tg_xxxyyz_xxz_0, tg_xxxyyz_xyy_0, tg_xxxyyz_xyz_0, \
                                         tg_xxxyyz_xzz_0, tg_xxxyyz_yyy_0, tg_xxxyyz_yyz_0, tg_xxxyyz_yzz_0, tg_xxxyyz_zzz_0, \
                                         tg_xxxyz_xx_1, tg_xxxyz_xxx_0, tg_xxxyz_xxx_1, tg_xxxyz_xxy_0, tg_xxxyz_xxy_1, \
                                         tg_xxxyz_xxz_0, tg_xxxyz_xxz_1, tg_xxxyz_xy_1, tg_xxxyz_xyy_0, tg_xxxyz_xyy_1, \
                                         tg_xxxyz_xyz_0, tg_xxxyz_xyz_1, tg_xxxyz_xz_1, tg_xxxyz_xzz_0, tg_xxxyz_xzz_1, \
                                         tg_xxxyz_yy_1, tg_xxxyz_yyy_0, tg_xxxyz_yyy_1, tg_xxxyz_yyz_0, tg_xxxyz_yyz_1, \
                                         tg_xxxyz_yz_1, tg_xxxyz_yzz_0, tg_xxxyz_yzz_1, tg_xxxyz_zz_1, tg_xxxyz_zzz_0, \
                                         tg_xxxyz_zzz_1, tg_xxxyzz_xxx_0, tg_xxxyzz_xxy_0, tg_xxxyzz_xxz_0, tg_xxxyzz_xyy_0, \
                                         tg_xxxyzz_xyz_0, tg_xxxyzz_xzz_0, tg_xxxyzz_yyy_0, tg_xxxyzz_yyz_0, tg_xxxyzz_yzz_0, \
                                         tg_xxxyzz_zzz_0, tg_xxxz_xxx_0, tg_xxxz_xxx_1, tg_xxxz_xxy_0, tg_xxxz_xxy_1, \
                                         tg_xxxz_xxz_0, tg_xxxz_xxz_1, tg_xxxz_xyy_0, tg_xxxz_xyy_1, tg_xxxz_xyz_0, \
                                         tg_xxxz_xyz_1, tg_xxxz_xzz_0, tg_xxxz_xzz_1, tg_xxxz_yyy_0, tg_xxxz_yyy_1, \
                                         tg_xxxz_yyz_0, tg_xxxz_yyz_1, tg_xxxz_yzz_0, tg_xxxz_yzz_1, tg_xxxz_zzz_0, \
                                         tg_xxxz_zzz_1, tg_xxxzz_xx_1, tg_xxxzz_xxx_0, tg_xxxzz_xxx_1, tg_xxxzz_xxy_0, \
                                         tg_xxxzz_xxy_1, tg_xxxzz_xxz_0, tg_xxxzz_xxz_1, tg_xxxzz_xy_1, tg_xxxzz_xyy_0, \
                                         tg_xxxzz_xyy_1, tg_xxxzz_xyz_0, tg_xxxzz_xyz_1, tg_xxxzz_xz_1, tg_xxxzz_xzz_0, \
                                         tg_xxxzz_xzz_1, tg_xxxzz_yy_1, tg_xxxzz_yyy_0, tg_xxxzz_yyy_1, tg_xxxzz_yyz_0, \
                                         tg_xxxzz_yyz_1, tg_xxxzz_yz_1, tg_xxxzz_yzz_0, tg_xxxzz_yzz_1, tg_xxxzz_zz_1, \
                                         tg_xxxzz_zzz_0, tg_xxxzz_zzz_1, tg_xxxzzz_xxx_0, tg_xxxzzz_xxy_0, tg_xxxzzz_xxz_0, \
                                         tg_xxxzzz_xyy_0, tg_xxyy_xxx_0, tg_xxyy_xxx_1, tg_xxyy_xxy_0, tg_xxyy_xxy_1, \
                                         tg_xxyy_xxz_0, tg_xxyy_xxz_1, tg_xxyy_xyy_0, tg_xxyy_xyy_1, tg_xxyy_xyz_0, \
                                         tg_xxyy_xyz_1, tg_xxyy_xzz_0, tg_xxyy_xzz_1, tg_xxyy_yyy_0, tg_xxyy_yyy_1, \
                                         tg_xxyy_yyz_0, tg_xxyy_yyz_1, tg_xxyy_yzz_0, tg_xxyy_yzz_1, tg_xxyy_zzz_0, \
                                         tg_xxyy_zzz_1, tg_xxyyy_xx_1, tg_xxyyy_xxx_0, tg_xxyyy_xxx_1, tg_xxyyy_xxy_0, \
                                         tg_xxyyy_xxy_1, tg_xxyyy_xxz_0, tg_xxyyy_xxz_1, tg_xxyyy_xy_1, tg_xxyyy_xyy_0, \
                                         tg_xxyyy_xyy_1, tg_xxyyy_xyz_0, tg_xxyyy_xyz_1, tg_xxyyy_xz_1, tg_xxyyy_xzz_0, \
                                         tg_xxyyy_xzz_1, tg_xxyyy_yy_1, tg_xxyyy_yyy_0, tg_xxyyy_yyy_1, tg_xxyyy_yyz_0, \
                                         tg_xxyyy_yyz_1, tg_xxyyy_yz_1, tg_xxyyy_yzz_0, tg_xxyyy_yzz_1, tg_xxyyy_zz_1, \
                                         tg_xxyyy_zzz_0, tg_xxyyy_zzz_1, tg_xxyyz_xx_1, tg_xxyyz_xxx_0, tg_xxyyz_xxx_1, \
                                         tg_xxyyz_xxy_0, tg_xxyyz_xxy_1, tg_xxyyz_xxz_0, tg_xxyyz_xxz_1, tg_xxyyz_xy_1, \
                                         tg_xxyyz_xyy_0, tg_xxyyz_xyy_1, tg_xxyyz_xyz_0, tg_xxyyz_xyz_1, tg_xxyyz_xz_1, \
                                         tg_xxyyz_xzz_0, tg_xxyyz_xzz_1, tg_xxyyz_yy_1, tg_xxyyz_yyy_0, tg_xxyyz_yyy_1, \
                                         tg_xxyyz_yyz_0, tg_xxyyz_yyz_1, tg_xxyyz_yz_1, tg_xxyyz_yzz_0, tg_xxyyz_yzz_1, \
                                         tg_xxyyz_zz_1, tg_xxyyz_zzz_0, tg_xxyyz_zzz_1, tg_xxyz_xxx_0, tg_xxyz_xxx_1, \
                                         tg_xxyz_xxy_0, tg_xxyz_xxy_1, tg_xxyz_xxz_0, tg_xxyz_xxz_1, tg_xxyz_xyy_0, \
                                         tg_xxyz_xyy_1, tg_xxyz_xyz_0, tg_xxyz_xyz_1, tg_xxyz_xzz_0, tg_xxyz_xzz_1, \
                                         tg_xxyz_yyy_0, tg_xxyz_yyy_1, tg_xxyz_yyz_0, tg_xxyz_yyz_1, tg_xxyz_yzz_0, \
                                         tg_xxyz_yzz_1, tg_xxyz_zzz_0, tg_xxyz_zzz_1, tg_xxyzz_xx_1, tg_xxyzz_xxx_0, \
                                         tg_xxyzz_xxx_1, tg_xxyzz_xxy_0, tg_xxyzz_xxy_1, tg_xxyzz_xxz_0, tg_xxyzz_xxz_1, \
                                         tg_xxyzz_xy_1, tg_xxyzz_xyy_0, tg_xxyzz_xyy_1, tg_xxyzz_xyz_0, tg_xxyzz_xyz_1, \
                                         tg_xxyzz_xz_1, tg_xxyzz_xzz_0, tg_xxyzz_xzz_1, tg_xxyzz_yy_1, tg_xxyzz_yyy_0, \
                                         tg_xxyzz_yyy_1, tg_xxyzz_yyz_0, tg_xxyzz_yyz_1, tg_xxyzz_yz_1, tg_xxyzz_yzz_0, \
                                         tg_xxyzz_yzz_1, tg_xxyzz_zz_1, tg_xxyzz_zzz_0, tg_xxyzz_zzz_1, tg_xxzz_xxx_0, \
                                         tg_xxzz_xxx_1, tg_xxzz_xxy_0, tg_xxzz_xxy_1, tg_xxzz_xxz_0, tg_xxzz_xxz_1, \
                                         tg_xxzz_xyy_0, tg_xxzz_xyy_1, tg_xxzz_xyz_0, tg_xxzz_xyz_1, tg_xxzz_xzz_0, \
                                         tg_xxzz_xzz_1, tg_xxzz_yyy_0, tg_xxzz_yyy_1, tg_xxzz_yyz_0, tg_xxzz_yyz_1, \
                                         tg_xxzz_yzz_0, tg_xxzz_yzz_1, tg_xxzz_zzz_0, tg_xxzz_zzz_1, tg_xxzzz_xx_1, \
                                         tg_xxzzz_xxx_0, tg_xxzzz_xxx_1, tg_xxzzz_xxy_0, tg_xxzzz_xxy_1, tg_xxzzz_xxz_0, \
                                         tg_xxzzz_xxz_1, tg_xxzzz_xy_1, tg_xxzzz_xyy_0, tg_xxzzz_xyy_1, tg_xxzzz_xz_1, \
                                         tg_xxzzz_yy_1, tg_xyyy_xxx_0, tg_xyyy_xxx_1, tg_xyyy_xxy_0, tg_xyyy_xxy_1, \
                                         tg_xyyy_xxz_0, tg_xyyy_xxz_1, tg_xyyy_xyy_0, tg_xyyy_xyy_1, tg_xyyy_xyz_0, \
                                         tg_xyyy_xyz_1, tg_xyyy_xzz_0, tg_xyyy_xzz_1, tg_xyyy_yyy_0, tg_xyyy_yyy_1, \
                                         tg_xyyy_yyz_0, tg_xyyy_yyz_1, tg_xyyy_yzz_0, tg_xyyy_yzz_1, tg_xyyy_zzz_0, \
                                         tg_xyyy_zzz_1, tg_xyyz_xxx_0, tg_xyyz_xxx_1, tg_xyyz_xxy_0, tg_xyyz_xxy_1, \
                                         tg_xyyz_xxz_0, tg_xyyz_xxz_1, tg_xyyz_xyy_0, tg_xyyz_xyy_1, tg_xyyz_xyz_0, \
                                         tg_xyyz_xyz_1, tg_xyyz_xzz_0, tg_xyyz_xzz_1, tg_xyyz_yyy_0, tg_xyyz_yyy_1, \
                                         tg_xyyz_yyz_0, tg_xyyz_yyz_1, tg_xyyz_yzz_0, tg_xyyz_yzz_1, tg_xyyz_zzz_0, \
                                         tg_xyyz_zzz_1, tg_xyzz_xxx_0, tg_xyzz_xxx_1, tg_xyzz_xxy_0, tg_xyzz_xxy_1, \
                                         tg_xyzz_xxz_0, tg_xyzz_xxz_1, tg_xyzz_xyy_0, tg_xyzz_xyy_1, tg_xyzz_xyz_0, \
                                         tg_xyzz_xyz_1, tg_xyzz_xzz_0, tg_xyzz_xzz_1, tg_xyzz_yyy_0, tg_xyzz_yyy_1, \
                                         tg_xyzz_yyz_0, tg_xyzz_yyz_1, tg_xyzz_yzz_0, tg_xyzz_yzz_1, tg_xyzz_zzz_0, \
                                         tg_xyzz_zzz_1, tg_xzzz_xxx_0, tg_xzzz_xxx_1, tg_xzzz_xxy_0, tg_xzzz_xxy_1, \
                                         tg_xzzz_xxz_0, tg_xzzz_xxz_1, tg_xzzz_xyy_0, tg_xzzz_xyy_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxxxx_xxx_0[j] = pb_x * tg_xxxxx_xxx_0[j] + fr * tg_xxxxx_xxx_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxx_0[j] - tg_xxxx_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xx_1[j];

                    tg_xxxxxx_xxy_0[j] = pb_x * tg_xxxxx_xxy_0[j] + fr * tg_xxxxx_xxy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxy_0[j] - tg_xxxx_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xy_1[j];

                    tg_xxxxxx_xxz_0[j] = pb_x * tg_xxxxx_xxz_0[j] + fr * tg_xxxxx_xxz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxz_0[j] - tg_xxxx_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xz_1[j];

                    tg_xxxxxx_xyy_0[j] = pb_x * tg_xxxxx_xyy_0[j] + fr * tg_xxxxx_xyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyy_0[j] - tg_xxxx_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yy_1[j];

                    tg_xxxxxx_xyz_0[j] = pb_x * tg_xxxxx_xyz_0[j] + fr * tg_xxxxx_xyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyz_0[j] - tg_xxxx_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yz_1[j];

                    tg_xxxxxx_xzz_0[j] = pb_x * tg_xxxxx_xzz_0[j] + fr * tg_xxxxx_xzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xzz_0[j] - tg_xxxx_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_zz_1[j];

                    tg_xxxxxx_yyy_0[j] = pb_x * tg_xxxxx_yyy_0[j] + fr * tg_xxxxx_yyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyy_0[j] - tg_xxxx_yyy_1[j] * fl1_fza);

                    tg_xxxxxx_yyz_0[j] = pb_x * tg_xxxxx_yyz_0[j] + fr * tg_xxxxx_yyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyz_0[j] - tg_xxxx_yyz_1[j] * fl1_fza);

                    tg_xxxxxx_yzz_0[j] = pb_x * tg_xxxxx_yzz_0[j] + fr * tg_xxxxx_yzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yzz_0[j] - tg_xxxx_yzz_1[j] * fl1_fza);

                    tg_xxxxxx_zzz_0[j] = pb_x * tg_xxxxx_zzz_0[j] + fr * tg_xxxxx_zzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_zzz_0[j] - tg_xxxx_zzz_1[j] * fl1_fza);

                    tg_xxxxxy_xxx_0[j] = pb_x * tg_xxxxy_xxx_0[j] + fr * tg_xxxxy_xxx_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxx_0[j] - tg_xxxy_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xx_1[j];

                    tg_xxxxxy_xxy_0[j] = pb_x * tg_xxxxy_xxy_0[j] + fr * tg_xxxxy_xxy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxy_0[j] - tg_xxxy_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xy_1[j];

                    tg_xxxxxy_xxz_0[j] = pb_x * tg_xxxxy_xxz_0[j] + fr * tg_xxxxy_xxz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxz_0[j] - tg_xxxy_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xz_1[j];

                    tg_xxxxxy_xyy_0[j] = pb_x * tg_xxxxy_xyy_0[j] + fr * tg_xxxxy_xyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyy_0[j] - tg_xxxy_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yy_1[j];

                    tg_xxxxxy_xyz_0[j] = pb_x * tg_xxxxy_xyz_0[j] + fr * tg_xxxxy_xyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyz_0[j] - tg_xxxy_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yz_1[j];

                    tg_xxxxxy_xzz_0[j] = pb_x * tg_xxxxy_xzz_0[j] + fr * tg_xxxxy_xzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xzz_0[j] - tg_xxxy_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_zz_1[j];

                    tg_xxxxxy_yyy_0[j] = pb_x * tg_xxxxy_yyy_0[j] + fr * tg_xxxxy_yyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyy_0[j] - tg_xxxy_yyy_1[j] * fl1_fza);

                    tg_xxxxxy_yyz_0[j] = pb_x * tg_xxxxy_yyz_0[j] + fr * tg_xxxxy_yyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyz_0[j] - tg_xxxy_yyz_1[j] * fl1_fza);

                    tg_xxxxxy_yzz_0[j] = pb_x * tg_xxxxy_yzz_0[j] + fr * tg_xxxxy_yzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yzz_0[j] - tg_xxxy_yzz_1[j] * fl1_fza);

                    tg_xxxxxy_zzz_0[j] = pb_x * tg_xxxxy_zzz_0[j] + fr * tg_xxxxy_zzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_zzz_0[j] - tg_xxxy_zzz_1[j] * fl1_fza);

                    tg_xxxxxz_xxx_0[j] = pb_x * tg_xxxxz_xxx_0[j] + fr * tg_xxxxz_xxx_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxx_0[j] - tg_xxxz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xx_1[j];

                    tg_xxxxxz_xxy_0[j] = pb_x * tg_xxxxz_xxy_0[j] + fr * tg_xxxxz_xxy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxy_0[j] - tg_xxxz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xy_1[j];

                    tg_xxxxxz_xxz_0[j] = pb_x * tg_xxxxz_xxz_0[j] + fr * tg_xxxxz_xxz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxz_0[j] - tg_xxxz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xz_1[j];

                    tg_xxxxxz_xyy_0[j] = pb_x * tg_xxxxz_xyy_0[j] + fr * tg_xxxxz_xyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyy_0[j] - tg_xxxz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yy_1[j];

                    tg_xxxxxz_xyz_0[j] = pb_x * tg_xxxxz_xyz_0[j] + fr * tg_xxxxz_xyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyz_0[j] - tg_xxxz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yz_1[j];

                    tg_xxxxxz_xzz_0[j] = pb_x * tg_xxxxz_xzz_0[j] + fr * tg_xxxxz_xzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xzz_0[j] - tg_xxxz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_zz_1[j];

                    tg_xxxxxz_yyy_0[j] = pb_x * tg_xxxxz_yyy_0[j] + fr * tg_xxxxz_yyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyy_0[j] - tg_xxxz_yyy_1[j] * fl1_fza);

                    tg_xxxxxz_yyz_0[j] = pb_x * tg_xxxxz_yyz_0[j] + fr * tg_xxxxz_yyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyz_0[j] - tg_xxxz_yyz_1[j] * fl1_fza);

                    tg_xxxxxz_yzz_0[j] = pb_x * tg_xxxxz_yzz_0[j] + fr * tg_xxxxz_yzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yzz_0[j] - tg_xxxz_yzz_1[j] * fl1_fza);

                    tg_xxxxxz_zzz_0[j] = pb_x * tg_xxxxz_zzz_0[j] + fr * tg_xxxxz_zzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_zzz_0[j] - tg_xxxz_zzz_1[j] * fl1_fza);

                    tg_xxxxyy_xxx_0[j] = pb_x * tg_xxxyy_xxx_0[j] + fr * tg_xxxyy_xxx_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxx_0[j] - tg_xxyy_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xx_1[j];

                    tg_xxxxyy_xxy_0[j] = pb_x * tg_xxxyy_xxy_0[j] + fr * tg_xxxyy_xxy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxy_0[j] - tg_xxyy_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xy_1[j];

                    tg_xxxxyy_xxz_0[j] = pb_x * tg_xxxyy_xxz_0[j] + fr * tg_xxxyy_xxz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxz_0[j] - tg_xxyy_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xz_1[j];

                    tg_xxxxyy_xyy_0[j] = pb_x * tg_xxxyy_xyy_0[j] + fr * tg_xxxyy_xyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyy_0[j] - tg_xxyy_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yy_1[j];

                    tg_xxxxyy_xyz_0[j] = pb_x * tg_xxxyy_xyz_0[j] + fr * tg_xxxyy_xyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyz_0[j] - tg_xxyy_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yz_1[j];

                    tg_xxxxyy_xzz_0[j] = pb_x * tg_xxxyy_xzz_0[j] + fr * tg_xxxyy_xzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xzz_0[j] - tg_xxyy_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_zz_1[j];

                    tg_xxxxyy_yyy_0[j] = pb_x * tg_xxxyy_yyy_0[j] + fr * tg_xxxyy_yyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyy_0[j] - tg_xxyy_yyy_1[j] * fl1_fza);

                    tg_xxxxyy_yyz_0[j] = pb_x * tg_xxxyy_yyz_0[j] + fr * tg_xxxyy_yyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyz_0[j] - tg_xxyy_yyz_1[j] * fl1_fza);

                    tg_xxxxyy_yzz_0[j] = pb_x * tg_xxxyy_yzz_0[j] + fr * tg_xxxyy_yzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yzz_0[j] - tg_xxyy_yzz_1[j] * fl1_fza);

                    tg_xxxxyy_zzz_0[j] = pb_x * tg_xxxyy_zzz_0[j] + fr * tg_xxxyy_zzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_zzz_0[j] - tg_xxyy_zzz_1[j] * fl1_fza);

                    tg_xxxxyz_xxx_0[j] = pb_x * tg_xxxyz_xxx_0[j] + fr * tg_xxxyz_xxx_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxx_0[j] - tg_xxyz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xx_1[j];

                    tg_xxxxyz_xxy_0[j] = pb_x * tg_xxxyz_xxy_0[j] + fr * tg_xxxyz_xxy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxy_0[j] - tg_xxyz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xy_1[j];

                    tg_xxxxyz_xxz_0[j] = pb_x * tg_xxxyz_xxz_0[j] + fr * tg_xxxyz_xxz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxz_0[j] - tg_xxyz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xz_1[j];

                    tg_xxxxyz_xyy_0[j] = pb_x * tg_xxxyz_xyy_0[j] + fr * tg_xxxyz_xyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyy_0[j] - tg_xxyz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yy_1[j];

                    tg_xxxxyz_xyz_0[j] = pb_x * tg_xxxyz_xyz_0[j] + fr * tg_xxxyz_xyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyz_0[j] - tg_xxyz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yz_1[j];

                    tg_xxxxyz_xzz_0[j] = pb_x * tg_xxxyz_xzz_0[j] + fr * tg_xxxyz_xzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xzz_0[j] - tg_xxyz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_zz_1[j];

                    tg_xxxxyz_yyy_0[j] = pb_x * tg_xxxyz_yyy_0[j] + fr * tg_xxxyz_yyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyy_0[j] - tg_xxyz_yyy_1[j] * fl1_fza);

                    tg_xxxxyz_yyz_0[j] = pb_x * tg_xxxyz_yyz_0[j] + fr * tg_xxxyz_yyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyz_0[j] - tg_xxyz_yyz_1[j] * fl1_fza);

                    tg_xxxxyz_yzz_0[j] = pb_x * tg_xxxyz_yzz_0[j] + fr * tg_xxxyz_yzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yzz_0[j] - tg_xxyz_yzz_1[j] * fl1_fza);

                    tg_xxxxyz_zzz_0[j] = pb_x * tg_xxxyz_zzz_0[j] + fr * tg_xxxyz_zzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_zzz_0[j] - tg_xxyz_zzz_1[j] * fl1_fza);

                    tg_xxxxzz_xxx_0[j] = pb_x * tg_xxxzz_xxx_0[j] + fr * tg_xxxzz_xxx_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxx_0[j] - tg_xxzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xx_1[j];

                    tg_xxxxzz_xxy_0[j] = pb_x * tg_xxxzz_xxy_0[j] + fr * tg_xxxzz_xxy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxy_0[j] - tg_xxzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xy_1[j];

                    tg_xxxxzz_xxz_0[j] = pb_x * tg_xxxzz_xxz_0[j] + fr * tg_xxxzz_xxz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxz_0[j] - tg_xxzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xz_1[j];

                    tg_xxxxzz_xyy_0[j] = pb_x * tg_xxxzz_xyy_0[j] + fr * tg_xxxzz_xyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyy_0[j] - tg_xxzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yy_1[j];

                    tg_xxxxzz_xyz_0[j] = pb_x * tg_xxxzz_xyz_0[j] + fr * tg_xxxzz_xyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyz_0[j] - tg_xxzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yz_1[j];

                    tg_xxxxzz_xzz_0[j] = pb_x * tg_xxxzz_xzz_0[j] + fr * tg_xxxzz_xzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xzz_0[j] - tg_xxzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_zz_1[j];

                    tg_xxxxzz_yyy_0[j] = pb_x * tg_xxxzz_yyy_0[j] + fr * tg_xxxzz_yyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyy_0[j] - tg_xxzz_yyy_1[j] * fl1_fza);

                    tg_xxxxzz_yyz_0[j] = pb_x * tg_xxxzz_yyz_0[j] + fr * tg_xxxzz_yyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyz_0[j] - tg_xxzz_yyz_1[j] * fl1_fza);

                    tg_xxxxzz_yzz_0[j] = pb_x * tg_xxxzz_yzz_0[j] + fr * tg_xxxzz_yzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yzz_0[j] - tg_xxzz_yzz_1[j] * fl1_fza);

                    tg_xxxxzz_zzz_0[j] = pb_x * tg_xxxzz_zzz_0[j] + fr * tg_xxxzz_zzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_zzz_0[j] - tg_xxzz_zzz_1[j] * fl1_fza);

                    tg_xxxyyy_xxx_0[j] = pb_x * tg_xxyyy_xxx_0[j] + fr * tg_xxyyy_xxx_1[j] + fl1_fx * (tg_xyyy_xxx_0[j] - tg_xyyy_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xx_1[j];

                    tg_xxxyyy_xxy_0[j] = pb_x * tg_xxyyy_xxy_0[j] + fr * tg_xxyyy_xxy_1[j] + fl1_fx * (tg_xyyy_xxy_0[j] - tg_xyyy_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xy_1[j];

                    tg_xxxyyy_xxz_0[j] = pb_x * tg_xxyyy_xxz_0[j] + fr * tg_xxyyy_xxz_1[j] + fl1_fx * (tg_xyyy_xxz_0[j] - tg_xyyy_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xz_1[j];

                    tg_xxxyyy_xyy_0[j] = pb_x * tg_xxyyy_xyy_0[j] + fr * tg_xxyyy_xyy_1[j] + fl1_fx * (tg_xyyy_xyy_0[j] - tg_xyyy_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yy_1[j];

                    tg_xxxyyy_xyz_0[j] = pb_x * tg_xxyyy_xyz_0[j] + fr * tg_xxyyy_xyz_1[j] + fl1_fx * (tg_xyyy_xyz_0[j] - tg_xyyy_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yz_1[j];

                    tg_xxxyyy_xzz_0[j] = pb_x * tg_xxyyy_xzz_0[j] + fr * tg_xxyyy_xzz_1[j] + fl1_fx * (tg_xyyy_xzz_0[j] - tg_xyyy_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_zz_1[j];

                    tg_xxxyyy_yyy_0[j] = pb_x * tg_xxyyy_yyy_0[j] + fr * tg_xxyyy_yyy_1[j] + fl1_fx * (tg_xyyy_yyy_0[j] - tg_xyyy_yyy_1[j] * fl1_fza);

                    tg_xxxyyy_yyz_0[j] = pb_x * tg_xxyyy_yyz_0[j] + fr * tg_xxyyy_yyz_1[j] + fl1_fx * (tg_xyyy_yyz_0[j] - tg_xyyy_yyz_1[j] * fl1_fza);

                    tg_xxxyyy_yzz_0[j] = pb_x * tg_xxyyy_yzz_0[j] + fr * tg_xxyyy_yzz_1[j] + fl1_fx * (tg_xyyy_yzz_0[j] - tg_xyyy_yzz_1[j] * fl1_fza);

                    tg_xxxyyy_zzz_0[j] = pb_x * tg_xxyyy_zzz_0[j] + fr * tg_xxyyy_zzz_1[j] + fl1_fx * (tg_xyyy_zzz_0[j] - tg_xyyy_zzz_1[j] * fl1_fza);

                    tg_xxxyyz_xxx_0[j] = pb_x * tg_xxyyz_xxx_0[j] + fr * tg_xxyyz_xxx_1[j] + fl1_fx * (tg_xyyz_xxx_0[j] - tg_xyyz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xx_1[j];

                    tg_xxxyyz_xxy_0[j] = pb_x * tg_xxyyz_xxy_0[j] + fr * tg_xxyyz_xxy_1[j] + fl1_fx * (tg_xyyz_xxy_0[j] - tg_xyyz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xy_1[j];

                    tg_xxxyyz_xxz_0[j] = pb_x * tg_xxyyz_xxz_0[j] + fr * tg_xxyyz_xxz_1[j] + fl1_fx * (tg_xyyz_xxz_0[j] - tg_xyyz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xz_1[j];

                    tg_xxxyyz_xyy_0[j] = pb_x * tg_xxyyz_xyy_0[j] + fr * tg_xxyyz_xyy_1[j] + fl1_fx * (tg_xyyz_xyy_0[j] - tg_xyyz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yy_1[j];

                    tg_xxxyyz_xyz_0[j] = pb_x * tg_xxyyz_xyz_0[j] + fr * tg_xxyyz_xyz_1[j] + fl1_fx * (tg_xyyz_xyz_0[j] - tg_xyyz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yz_1[j];

                    tg_xxxyyz_xzz_0[j] = pb_x * tg_xxyyz_xzz_0[j] + fr * tg_xxyyz_xzz_1[j] + fl1_fx * (tg_xyyz_xzz_0[j] - tg_xyyz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_zz_1[j];

                    tg_xxxyyz_yyy_0[j] = pb_x * tg_xxyyz_yyy_0[j] + fr * tg_xxyyz_yyy_1[j] + fl1_fx * (tg_xyyz_yyy_0[j] - tg_xyyz_yyy_1[j] * fl1_fza);

                    tg_xxxyyz_yyz_0[j] = pb_x * tg_xxyyz_yyz_0[j] + fr * tg_xxyyz_yyz_1[j] + fl1_fx * (tg_xyyz_yyz_0[j] - tg_xyyz_yyz_1[j] * fl1_fza);

                    tg_xxxyyz_yzz_0[j] = pb_x * tg_xxyyz_yzz_0[j] + fr * tg_xxyyz_yzz_1[j] + fl1_fx * (tg_xyyz_yzz_0[j] - tg_xyyz_yzz_1[j] * fl1_fza);

                    tg_xxxyyz_zzz_0[j] = pb_x * tg_xxyyz_zzz_0[j] + fr * tg_xxyyz_zzz_1[j] + fl1_fx * (tg_xyyz_zzz_0[j] - tg_xyyz_zzz_1[j] * fl1_fza);

                    tg_xxxyzz_xxx_0[j] = pb_x * tg_xxyzz_xxx_0[j] + fr * tg_xxyzz_xxx_1[j] + fl1_fx * (tg_xyzz_xxx_0[j] - tg_xyzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xx_1[j];

                    tg_xxxyzz_xxy_0[j] = pb_x * tg_xxyzz_xxy_0[j] + fr * tg_xxyzz_xxy_1[j] + fl1_fx * (tg_xyzz_xxy_0[j] - tg_xyzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xy_1[j];

                    tg_xxxyzz_xxz_0[j] = pb_x * tg_xxyzz_xxz_0[j] + fr * tg_xxyzz_xxz_1[j] + fl1_fx * (tg_xyzz_xxz_0[j] - tg_xyzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xz_1[j];

                    tg_xxxyzz_xyy_0[j] = pb_x * tg_xxyzz_xyy_0[j] + fr * tg_xxyzz_xyy_1[j] + fl1_fx * (tg_xyzz_xyy_0[j] - tg_xyzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yy_1[j];

                    tg_xxxyzz_xyz_0[j] = pb_x * tg_xxyzz_xyz_0[j] + fr * tg_xxyzz_xyz_1[j] + fl1_fx * (tg_xyzz_xyz_0[j] - tg_xyzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yz_1[j];

                    tg_xxxyzz_xzz_0[j] = pb_x * tg_xxyzz_xzz_0[j] + fr * tg_xxyzz_xzz_1[j] + fl1_fx * (tg_xyzz_xzz_0[j] - tg_xyzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_zz_1[j];

                    tg_xxxyzz_yyy_0[j] = pb_x * tg_xxyzz_yyy_0[j] + fr * tg_xxyzz_yyy_1[j] + fl1_fx * (tg_xyzz_yyy_0[j] - tg_xyzz_yyy_1[j] * fl1_fza);

                    tg_xxxyzz_yyz_0[j] = pb_x * tg_xxyzz_yyz_0[j] + fr * tg_xxyzz_yyz_1[j] + fl1_fx * (tg_xyzz_yyz_0[j] - tg_xyzz_yyz_1[j] * fl1_fza);

                    tg_xxxyzz_yzz_0[j] = pb_x * tg_xxyzz_yzz_0[j] + fr * tg_xxyzz_yzz_1[j] + fl1_fx * (tg_xyzz_yzz_0[j] - tg_xyzz_yzz_1[j] * fl1_fza);

                    tg_xxxyzz_zzz_0[j] = pb_x * tg_xxyzz_zzz_0[j] + fr * tg_xxyzz_zzz_1[j] + fl1_fx * (tg_xyzz_zzz_0[j] - tg_xyzz_zzz_1[j] * fl1_fza);

                    tg_xxxzzz_xxx_0[j] = pb_x * tg_xxzzz_xxx_0[j] + fr * tg_xxzzz_xxx_1[j] + fl1_fx * (tg_xzzz_xxx_0[j] - tg_xzzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xx_1[j];

                    tg_xxxzzz_xxy_0[j] = pb_x * tg_xxzzz_xxy_0[j] + fr * tg_xxzzz_xxy_1[j] + fl1_fx * (tg_xzzz_xxy_0[j] - tg_xzzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xy_1[j];

                    tg_xxxzzz_xxz_0[j] = pb_x * tg_xxzzz_xxz_0[j] + fr * tg_xxzzz_xxz_1[j] + fl1_fx * (tg_xzzz_xxz_0[j] - tg_xzzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xz_1[j];

                    tg_xxxzzz_xyy_0[j] = pb_x * tg_xxzzz_xyy_0[j] + fr * tg_xxzzz_xyy_1[j] + fl1_fx * (tg_xzzz_xyy_0[j] - tg_xzzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISF_94_187(      CMemBlock2D<double>* primBuffer,
                                        const CRecursionMap&       recursionMap,
                                        const CMemBlock2D<double>& osFactors,
                                        const CMemBlock2D<double>& wpDistances,
                                        const CGtoPairsBlock&      braGtoPairsBlock,
                                        const CGtoPairsBlock&      ketGtoPairsBlock,
                                        const int32_t              nKetPrimPairs,
                                        const int32_t              iContrPair)
    {
        // Batch of Integrals (94,187)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_2_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {2, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrPair]; i < epos[iContrPair]; i++)
            {
                // set up pointers to Obara-Saika factors

                double fx = b_fx[i];

                auto fza = osFactors.data(4 * idx + 2);

                auto fxn = osFactors.data(4 * idx);

                // set up distances R(PB) = P - B

                auto pb_x = r_pb_x[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tg_xxzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 94); 

                auto tg_xxzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 95); 

                auto tg_xxzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 96); 

                auto tg_xxzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 97); 

                auto tg_xxzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 98); 

                auto tg_xxzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 99); 

                auto tg_xyyyy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 100); 

                auto tg_xyyyy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 101); 

                auto tg_xyyyy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 102); 

                auto tg_xyyyy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 103); 

                auto tg_xyyyy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 104); 

                auto tg_xyyyy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 105); 

                auto tg_xyyyy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 106); 

                auto tg_xyyyy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 107); 

                auto tg_xyyyy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 108); 

                auto tg_xyyyy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 109); 

                auto tg_xyyyz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 110); 

                auto tg_xyyyz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 111); 

                auto tg_xyyyz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 112); 

                auto tg_xyyyz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 113); 

                auto tg_xyyyz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 114); 

                auto tg_xyyyz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 115); 

                auto tg_xyyyz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 116); 

                auto tg_xyyyz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 117); 

                auto tg_xyyyz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 118); 

                auto tg_xyyyz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 119); 

                auto tg_xyyzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 120); 

                auto tg_xyyzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 121); 

                auto tg_xyyzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 122); 

                auto tg_xyyzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 123); 

                auto tg_xyyzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 124); 

                auto tg_xyyzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 125); 

                auto tg_xyyzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 126); 

                auto tg_xyyzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 127); 

                auto tg_xyyzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 128); 

                auto tg_xyyzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 129); 

                auto tg_xyzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 130); 

                auto tg_xyzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 131); 

                auto tg_xyzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 132); 

                auto tg_xyzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 133); 

                auto tg_xyzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 134); 

                auto tg_xyzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 135); 

                auto tg_xyzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 136); 

                auto tg_xyzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 137); 

                auto tg_xyzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 138); 

                auto tg_xyzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 139); 

                auto tg_xzzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 140); 

                auto tg_xzzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 141); 

                auto tg_xzzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 142); 

                auto tg_xzzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 143); 

                auto tg_xzzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 144); 

                auto tg_xzzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 145); 

                auto tg_xzzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 146); 

                auto tg_xzzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 147); 

                auto tg_xzzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 148); 

                auto tg_xzzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 149); 

                auto tg_yyyyy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 150); 

                auto tg_yyyyy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 151); 

                auto tg_yyyyy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 152); 

                auto tg_yyyyy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 153); 

                auto tg_yyyyy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 154); 

                auto tg_yyyyy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 155); 

                auto tg_yyyyy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 156); 

                auto tg_yyyyy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 157); 

                auto tg_yyyyy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 158); 

                auto tg_yyyyy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 159); 

                auto tg_yyyyz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 160); 

                auto tg_yyyyz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 161); 

                auto tg_yyyyz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 162); 

                auto tg_yyyyz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 163); 

                auto tg_yyyyz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 164); 

                auto tg_yyyyz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 165); 

                auto tg_yyyyz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 166); 

                auto tg_yyyyz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 167); 

                auto tg_yyyyz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 168); 

                auto tg_yyyyz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 169); 

                auto tg_yyyzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 170); 

                auto tg_yyyzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 171); 

                auto tg_yyyzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 172); 

                auto tg_yyyzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 173); 

                auto tg_yyyzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 174); 

                auto tg_yyyzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 175); 

                auto tg_yyyzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 176); 

                auto tg_yyyzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 177); 

                auto tg_yyyzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 178); 

                auto tg_yyyzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 179); 

                auto tg_yyzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 180); 

                auto tg_yyzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 181); 

                auto tg_yyzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 182); 

                auto tg_yyzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 183); 

                auto tg_yyzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 184); 

                auto tg_yyzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 185); 

                auto tg_yyzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 186); 

                auto tg_xxzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 94); 

                auto tg_xxzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 95); 

                auto tg_xxzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 96); 

                auto tg_xxzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 97); 

                auto tg_xxzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 98); 

                auto tg_xxzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 99); 

                auto tg_xyyyy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 100); 

                auto tg_xyyyy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 101); 

                auto tg_xyyyy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 102); 

                auto tg_xyyyy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 103); 

                auto tg_xyyyy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 104); 

                auto tg_xyyyy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 105); 

                auto tg_xyyyy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 106); 

                auto tg_xyyyy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 107); 

                auto tg_xyyyy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 108); 

                auto tg_xyyyy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 109); 

                auto tg_xyyyz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 110); 

                auto tg_xyyyz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 111); 

                auto tg_xyyyz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 112); 

                auto tg_xyyyz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 113); 

                auto tg_xyyyz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 114); 

                auto tg_xyyyz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 115); 

                auto tg_xyyyz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 116); 

                auto tg_xyyyz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 117); 

                auto tg_xyyyz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 118); 

                auto tg_xyyyz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 119); 

                auto tg_xyyzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 120); 

                auto tg_xyyzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 121); 

                auto tg_xyyzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 122); 

                auto tg_xyyzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 123); 

                auto tg_xyyzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 124); 

                auto tg_xyyzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 125); 

                auto tg_xyyzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 126); 

                auto tg_xyyzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 127); 

                auto tg_xyyzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 128); 

                auto tg_xyyzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 129); 

                auto tg_xyzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 130); 

                auto tg_xyzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 131); 

                auto tg_xyzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 132); 

                auto tg_xyzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 133); 

                auto tg_xyzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 134); 

                auto tg_xyzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 135); 

                auto tg_xyzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 136); 

                auto tg_xyzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 137); 

                auto tg_xyzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 138); 

                auto tg_xyzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 139); 

                auto tg_xzzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 140); 

                auto tg_xzzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 141); 

                auto tg_xzzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 142); 

                auto tg_xzzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 143); 

                auto tg_xzzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 144); 

                auto tg_xzzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 145); 

                auto tg_xzzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 146); 

                auto tg_xzzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 147); 

                auto tg_xzzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 148); 

                auto tg_xzzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 149); 

                auto tg_yyyyy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 150); 

                auto tg_yyyyy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 151); 

                auto tg_yyyyy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 152); 

                auto tg_yyyyy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 153); 

                auto tg_yyyyy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 154); 

                auto tg_yyyyy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 155); 

                auto tg_yyyyy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 156); 

                auto tg_yyyyy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 157); 

                auto tg_yyyyy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 158); 

                auto tg_yyyyy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 159); 

                auto tg_yyyyz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 160); 

                auto tg_yyyyz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 161); 

                auto tg_yyyyz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 162); 

                auto tg_yyyyz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 163); 

                auto tg_yyyyz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 164); 

                auto tg_yyyyz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 165); 

                auto tg_yyyyz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 166); 

                auto tg_yyyyz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 167); 

                auto tg_yyyyz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 168); 

                auto tg_yyyyz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 169); 

                auto tg_yyyzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 170); 

                auto tg_yyyzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 171); 

                auto tg_yyyzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 172); 

                auto tg_yyyzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 173); 

                auto tg_yyyzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 174); 

                auto tg_yyyzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 175); 

                auto tg_yyyzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 176); 

                auto tg_yyyzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 177); 

                auto tg_yyyzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 178); 

                auto tg_yyyzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 179); 

                auto tg_yyzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 180); 

                auto tg_yyzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 181); 

                auto tg_yyzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 182); 

                auto tg_yyzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 183); 

                auto tg_yyzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 184); 

                auto tg_yyzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 185); 

                auto tg_yyzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 186); 

                auto tg_xzzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 94); 

                auto tg_xzzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 95); 

                auto tg_xzzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 96); 

                auto tg_xzzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 97); 

                auto tg_xzzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 98); 

                auto tg_xzzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 99); 

                auto tg_yyyy_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 100); 

                auto tg_yyyy_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 101); 

                auto tg_yyyy_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 102); 

                auto tg_yyyy_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 103); 

                auto tg_yyyy_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 104); 

                auto tg_yyyy_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 105); 

                auto tg_yyyy_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 106); 

                auto tg_yyyy_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 107); 

                auto tg_yyyy_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 108); 

                auto tg_yyyy_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 109); 

                auto tg_yyyz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 110); 

                auto tg_yyyz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 111); 

                auto tg_yyyz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 112); 

                auto tg_yyyz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 113); 

                auto tg_yyyz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 114); 

                auto tg_yyyz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 115); 

                auto tg_yyyz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 116); 

                auto tg_yyyz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 117); 

                auto tg_yyyz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 118); 

                auto tg_yyyz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 119); 

                auto tg_yyzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 120); 

                auto tg_yyzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 121); 

                auto tg_yyzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 122); 

                auto tg_yyzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 123); 

                auto tg_yyzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 124); 

                auto tg_yyzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 125); 

                auto tg_yyzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 126); 

                auto tg_yyzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 127); 

                auto tg_yyzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 128); 

                auto tg_yyzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 129); 

                auto tg_yzzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 130); 

                auto tg_yzzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 131); 

                auto tg_yzzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 132); 

                auto tg_yzzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 133); 

                auto tg_yzzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 134); 

                auto tg_yzzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 135); 

                auto tg_yzzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 136); 

                auto tg_yzzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 137); 

                auto tg_yzzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 138); 

                auto tg_yzzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 139); 

                auto tg_zzzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 140); 

                auto tg_zzzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 141); 

                auto tg_zzzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 142); 

                auto tg_zzzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 143); 

                auto tg_zzzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 144); 

                auto tg_zzzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 145); 

                auto tg_zzzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 146); 

                auto tg_zzzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 147); 

                auto tg_zzzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 148); 

                auto tg_zzzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 149); 

                auto tg_xzzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 94); 

                auto tg_xzzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 95); 

                auto tg_xzzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 96); 

                auto tg_xzzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 97); 

                auto tg_xzzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 98); 

                auto tg_xzzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 99); 

                auto tg_yyyy_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 100); 

                auto tg_yyyy_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 101); 

                auto tg_yyyy_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 102); 

                auto tg_yyyy_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 103); 

                auto tg_yyyy_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 104); 

                auto tg_yyyy_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 105); 

                auto tg_yyyy_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 106); 

                auto tg_yyyy_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 107); 

                auto tg_yyyy_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 108); 

                auto tg_yyyy_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 109); 

                auto tg_yyyz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 110); 

                auto tg_yyyz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 111); 

                auto tg_yyyz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 112); 

                auto tg_yyyz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 113); 

                auto tg_yyyz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 114); 

                auto tg_yyyz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 115); 

                auto tg_yyyz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 116); 

                auto tg_yyyz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 117); 

                auto tg_yyyz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 118); 

                auto tg_yyyz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 119); 

                auto tg_yyzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 120); 

                auto tg_yyzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 121); 

                auto tg_yyzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 122); 

                auto tg_yyzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 123); 

                auto tg_yyzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 124); 

                auto tg_yyzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 125); 

                auto tg_yyzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 126); 

                auto tg_yyzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 127); 

                auto tg_yyzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 128); 

                auto tg_yyzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 129); 

                auto tg_yzzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 130); 

                auto tg_yzzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 131); 

                auto tg_yzzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 132); 

                auto tg_yzzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 133); 

                auto tg_yzzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 134); 

                auto tg_yzzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 135); 

                auto tg_yzzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 136); 

                auto tg_yzzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 137); 

                auto tg_yzzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 138); 

                auto tg_yzzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 139); 

                auto tg_zzzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 140); 

                auto tg_zzzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 141); 

                auto tg_zzzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 142); 

                auto tg_zzzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 143); 

                auto tg_zzzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 144); 

                auto tg_zzzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 145); 

                auto tg_zzzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 146); 

                auto tg_zzzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 147); 

                auto tg_zzzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 148); 

                auto tg_zzzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 149); 

                auto tg_xxzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 58); 

                auto tg_xxzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 59); 

                auto tg_xyyyy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 60); 

                auto tg_xyyyy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 61); 

                auto tg_xyyyy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 62); 

                auto tg_xyyyy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 63); 

                auto tg_xyyyy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 64); 

                auto tg_xyyyy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 65); 

                auto tg_xyyyz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 66); 

                auto tg_xyyyz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 67); 

                auto tg_xyyyz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 68); 

                auto tg_xyyyz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 69); 

                auto tg_xyyyz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 70); 

                auto tg_xyyyz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 71); 

                auto tg_xyyzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 72); 

                auto tg_xyyzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 73); 

                auto tg_xyyzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 74); 

                auto tg_xyyzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 75); 

                auto tg_xyyzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 76); 

                auto tg_xyyzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 77); 

                auto tg_xyzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 78); 

                auto tg_xyzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 79); 

                auto tg_xyzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 80); 

                auto tg_xyzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 81); 

                auto tg_xyzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 82); 

                auto tg_xyzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 83); 

                auto tg_xzzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 84); 

                auto tg_xzzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 85); 

                auto tg_xzzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 86); 

                auto tg_xzzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 87); 

                auto tg_xzzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 88); 

                auto tg_xzzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 89); 

                auto tg_yyyyy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 90); 

                auto tg_yyyyy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 91); 

                auto tg_yyyyy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 92); 

                auto tg_yyyyy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 93); 

                auto tg_yyyyy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 94); 

                auto tg_yyyyy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 95); 

                auto tg_yyyyz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 96); 

                auto tg_yyyyz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 97); 

                auto tg_yyyyz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 98); 

                auto tg_yyyyz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 99); 

                auto tg_yyyyz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 100); 

                auto tg_yyyyz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 101); 

                auto tg_yyyzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 102); 

                auto tg_yyyzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 103); 

                auto tg_yyyzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 104); 

                auto tg_yyyzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 105); 

                auto tg_yyyzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 106); 

                auto tg_yyyzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 107); 

                auto tg_yyzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 108); 

                auto tg_yyzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 109); 

                auto tg_yyzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 110); 

                auto tg_yyzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 111); 

                auto tg_yyzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 112); 

                auto tg_yyzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 113); 

                // set up pointers to integrals

                auto tg_xxxzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 94); 

                auto tg_xxxzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 95); 

                auto tg_xxxzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 96); 

                auto tg_xxxzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 97); 

                auto tg_xxxzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 98); 

                auto tg_xxxzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 99); 

                auto tg_xxyyyy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 100); 

                auto tg_xxyyyy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 101); 

                auto tg_xxyyyy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 102); 

                auto tg_xxyyyy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 103); 

                auto tg_xxyyyy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 104); 

                auto tg_xxyyyy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 105); 

                auto tg_xxyyyy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 106); 

                auto tg_xxyyyy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 107); 

                auto tg_xxyyyy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 108); 

                auto tg_xxyyyy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 109); 

                auto tg_xxyyyz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 110); 

                auto tg_xxyyyz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 111); 

                auto tg_xxyyyz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 112); 

                auto tg_xxyyyz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 113); 

                auto tg_xxyyyz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 114); 

                auto tg_xxyyyz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 115); 

                auto tg_xxyyyz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 116); 

                auto tg_xxyyyz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 117); 

                auto tg_xxyyyz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 118); 

                auto tg_xxyyyz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 119); 

                auto tg_xxyyzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 120); 

                auto tg_xxyyzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 121); 

                auto tg_xxyyzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 122); 

                auto tg_xxyyzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 123); 

                auto tg_xxyyzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 124); 

                auto tg_xxyyzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 125); 

                auto tg_xxyyzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 126); 

                auto tg_xxyyzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 127); 

                auto tg_xxyyzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 128); 

                auto tg_xxyyzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 129); 

                auto tg_xxyzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 130); 

                auto tg_xxyzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 131); 

                auto tg_xxyzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 132); 

                auto tg_xxyzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 133); 

                auto tg_xxyzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 134); 

                auto tg_xxyzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 135); 

                auto tg_xxyzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 136); 

                auto tg_xxyzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 137); 

                auto tg_xxyzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 138); 

                auto tg_xxyzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 139); 

                auto tg_xxzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 140); 

                auto tg_xxzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 141); 

                auto tg_xxzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 142); 

                auto tg_xxzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 143); 

                auto tg_xxzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 144); 

                auto tg_xxzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 145); 

                auto tg_xxzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 146); 

                auto tg_xxzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 147); 

                auto tg_xxzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 148); 

                auto tg_xxzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 149); 

                auto tg_xyyyyy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 150); 

                auto tg_xyyyyy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 151); 

                auto tg_xyyyyy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 152); 

                auto tg_xyyyyy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 153); 

                auto tg_xyyyyy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 154); 

                auto tg_xyyyyy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 155); 

                auto tg_xyyyyy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 156); 

                auto tg_xyyyyy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 157); 

                auto tg_xyyyyy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 158); 

                auto tg_xyyyyy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 159); 

                auto tg_xyyyyz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 160); 

                auto tg_xyyyyz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 161); 

                auto tg_xyyyyz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 162); 

                auto tg_xyyyyz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 163); 

                auto tg_xyyyyz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 164); 

                auto tg_xyyyyz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 165); 

                auto tg_xyyyyz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 166); 

                auto tg_xyyyyz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 167); 

                auto tg_xyyyyz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 168); 

                auto tg_xyyyyz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 169); 

                auto tg_xyyyzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 170); 

                auto tg_xyyyzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 171); 

                auto tg_xyyyzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 172); 

                auto tg_xyyyzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 173); 

                auto tg_xyyyzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 174); 

                auto tg_xyyyzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 175); 

                auto tg_xyyyzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 176); 

                auto tg_xyyyzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 177); 

                auto tg_xyyyzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 178); 

                auto tg_xyyyzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 179); 

                auto tg_xyyzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 180); 

                auto tg_xyyzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 181); 

                auto tg_xyyzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 182); 

                auto tg_xyyzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 183); 

                auto tg_xyyzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 184); 

                auto tg_xyyzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 185); 

                auto tg_xyyzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 186); 

                // Batch of Integrals (94,187)

                #pragma omp simd aligned(fxn, fza, tg_xxxzzz_xyz_0, tg_xxxzzz_xzz_0, tg_xxxzzz_yyy_0, \
                                         tg_xxxzzz_yyz_0, tg_xxxzzz_yzz_0, tg_xxxzzz_zzz_0, tg_xxyyyy_xxx_0, tg_xxyyyy_xxy_0, \
                                         tg_xxyyyy_xxz_0, tg_xxyyyy_xyy_0, tg_xxyyyy_xyz_0, tg_xxyyyy_xzz_0, tg_xxyyyy_yyy_0, \
                                         tg_xxyyyy_yyz_0, tg_xxyyyy_yzz_0, tg_xxyyyy_zzz_0, tg_xxyyyz_xxx_0, tg_xxyyyz_xxy_0, \
                                         tg_xxyyyz_xxz_0, tg_xxyyyz_xyy_0, tg_xxyyyz_xyz_0, tg_xxyyyz_xzz_0, tg_xxyyyz_yyy_0, \
                                         tg_xxyyyz_yyz_0, tg_xxyyyz_yzz_0, tg_xxyyyz_zzz_0, tg_xxyyzz_xxx_0, tg_xxyyzz_xxy_0, \
                                         tg_xxyyzz_xxz_0, tg_xxyyzz_xyy_0, tg_xxyyzz_xyz_0, tg_xxyyzz_xzz_0, tg_xxyyzz_yyy_0, \
                                         tg_xxyyzz_yyz_0, tg_xxyyzz_yzz_0, tg_xxyyzz_zzz_0, tg_xxyzzz_xxx_0, tg_xxyzzz_xxy_0, \
                                         tg_xxyzzz_xxz_0, tg_xxyzzz_xyy_0, tg_xxyzzz_xyz_0, tg_xxyzzz_xzz_0, tg_xxyzzz_yyy_0, \
                                         tg_xxyzzz_yyz_0, tg_xxyzzz_yzz_0, tg_xxyzzz_zzz_0, tg_xxzzz_xyz_0, tg_xxzzz_xyz_1, \
                                         tg_xxzzz_xzz_0, tg_xxzzz_xzz_1, tg_xxzzz_yyy_0, tg_xxzzz_yyy_1, tg_xxzzz_yyz_0, \
                                         tg_xxzzz_yyz_1, tg_xxzzz_yz_1, tg_xxzzz_yzz_0, tg_xxzzz_yzz_1, tg_xxzzz_zz_1, \
                                         tg_xxzzz_zzz_0, tg_xxzzz_zzz_1, tg_xxzzzz_xxx_0, tg_xxzzzz_xxy_0, tg_xxzzzz_xxz_0, \
                                         tg_xxzzzz_xyy_0, tg_xxzzzz_xyz_0, tg_xxzzzz_xzz_0, tg_xxzzzz_yyy_0, tg_xxzzzz_yyz_0, \
                                         tg_xxzzzz_yzz_0, tg_xxzzzz_zzz_0, tg_xyyyy_xx_1, tg_xyyyy_xxx_0, tg_xyyyy_xxx_1, \
                                         tg_xyyyy_xxy_0, tg_xyyyy_xxy_1, tg_xyyyy_xxz_0, tg_xyyyy_xxz_1, tg_xyyyy_xy_1, \
                                         tg_xyyyy_xyy_0, tg_xyyyy_xyy_1, tg_xyyyy_xyz_0, tg_xyyyy_xyz_1, tg_xyyyy_xz_1, \
                                         tg_xyyyy_xzz_0, tg_xyyyy_xzz_1, tg_xyyyy_yy_1, tg_xyyyy_yyy_0, tg_xyyyy_yyy_1, \
                                         tg_xyyyy_yyz_0, tg_xyyyy_yyz_1, tg_xyyyy_yz_1, tg_xyyyy_yzz_0, tg_xyyyy_yzz_1, \
                                         tg_xyyyy_zz_1, tg_xyyyy_zzz_0, tg_xyyyy_zzz_1, tg_xyyyyy_xxx_0, tg_xyyyyy_xxy_0, \
                                         tg_xyyyyy_xxz_0, tg_xyyyyy_xyy_0, tg_xyyyyy_xyz_0, tg_xyyyyy_xzz_0, tg_xyyyyy_yyy_0, \
                                         tg_xyyyyy_yyz_0, tg_xyyyyy_yzz_0, tg_xyyyyy_zzz_0, tg_xyyyyz_xxx_0, tg_xyyyyz_xxy_0, \
                                         tg_xyyyyz_xxz_0, tg_xyyyyz_xyy_0, tg_xyyyyz_xyz_0, tg_xyyyyz_xzz_0, tg_xyyyyz_yyy_0, \
                                         tg_xyyyyz_yyz_0, tg_xyyyyz_yzz_0, tg_xyyyyz_zzz_0, tg_xyyyz_xx_1, tg_xyyyz_xxx_0, \
                                         tg_xyyyz_xxx_1, tg_xyyyz_xxy_0, tg_xyyyz_xxy_1, tg_xyyyz_xxz_0, tg_xyyyz_xxz_1, \
                                         tg_xyyyz_xy_1, tg_xyyyz_xyy_0, tg_xyyyz_xyy_1, tg_xyyyz_xyz_0, tg_xyyyz_xyz_1, \
                                         tg_xyyyz_xz_1, tg_xyyyz_xzz_0, tg_xyyyz_xzz_1, tg_xyyyz_yy_1, tg_xyyyz_yyy_0, \
                                         tg_xyyyz_yyy_1, tg_xyyyz_yyz_0, tg_xyyyz_yyz_1, tg_xyyyz_yz_1, tg_xyyyz_yzz_0, \
                                         tg_xyyyz_yzz_1, tg_xyyyz_zz_1, tg_xyyyz_zzz_0, tg_xyyyz_zzz_1, tg_xyyyzz_xxx_0, \
                                         tg_xyyyzz_xxy_0, tg_xyyyzz_xxz_0, tg_xyyyzz_xyy_0, tg_xyyyzz_xyz_0, tg_xyyyzz_xzz_0, \
                                         tg_xyyyzz_yyy_0, tg_xyyyzz_yyz_0, tg_xyyyzz_yzz_0, tg_xyyyzz_zzz_0, tg_xyyzz_xx_1, \
                                         tg_xyyzz_xxx_0, tg_xyyzz_xxx_1, tg_xyyzz_xxy_0, tg_xyyzz_xxy_1, tg_xyyzz_xxz_0, \
                                         tg_xyyzz_xxz_1, tg_xyyzz_xy_1, tg_xyyzz_xyy_0, tg_xyyzz_xyy_1, tg_xyyzz_xyz_0, \
                                         tg_xyyzz_xyz_1, tg_xyyzz_xz_1, tg_xyyzz_xzz_0, tg_xyyzz_xzz_1, tg_xyyzz_yy_1, \
                                         tg_xyyzz_yyy_0, tg_xyyzz_yyy_1, tg_xyyzz_yyz_0, tg_xyyzz_yyz_1, tg_xyyzz_yz_1, \
                                         tg_xyyzz_yzz_0, tg_xyyzz_yzz_1, tg_xyyzz_zz_1, tg_xyyzz_zzz_0, tg_xyyzz_zzz_1, \
                                         tg_xyyzzz_xxx_0, tg_xyyzzz_xxy_0, tg_xyyzzz_xxz_0, tg_xyyzzz_xyy_0, tg_xyyzzz_xyz_0, \
                                         tg_xyyzzz_xzz_0, tg_xyyzzz_yyy_0, tg_xyzzz_xx_1, tg_xyzzz_xxx_0, tg_xyzzz_xxx_1, \
                                         tg_xyzzz_xxy_0, tg_xyzzz_xxy_1, tg_xyzzz_xxz_0, tg_xyzzz_xxz_1, tg_xyzzz_xy_1, \
                                         tg_xyzzz_xyy_0, tg_xyzzz_xyy_1, tg_xyzzz_xyz_0, tg_xyzzz_xyz_1, tg_xyzzz_xz_1, \
                                         tg_xyzzz_xzz_0, tg_xyzzz_xzz_1, tg_xyzzz_yy_1, tg_xyzzz_yyy_0, tg_xyzzz_yyy_1, \
                                         tg_xyzzz_yyz_0, tg_xyzzz_yyz_1, tg_xyzzz_yz_1, tg_xyzzz_yzz_0, tg_xyzzz_yzz_1, \
                                         tg_xyzzz_zz_1, tg_xyzzz_zzz_0, tg_xyzzz_zzz_1, tg_xzzz_xyz_0, tg_xzzz_xyz_1, \
                                         tg_xzzz_xzz_0, tg_xzzz_xzz_1, tg_xzzz_yyy_0, tg_xzzz_yyy_1, tg_xzzz_yyz_0, \
                                         tg_xzzz_yyz_1, tg_xzzz_yzz_0, tg_xzzz_yzz_1, tg_xzzz_zzz_0, tg_xzzz_zzz_1, \
                                         tg_xzzzz_xx_1, tg_xzzzz_xxx_0, tg_xzzzz_xxx_1, tg_xzzzz_xxy_0, tg_xzzzz_xxy_1, \
                                         tg_xzzzz_xxz_0, tg_xzzzz_xxz_1, tg_xzzzz_xy_1, tg_xzzzz_xyy_0, tg_xzzzz_xyy_1, \
                                         tg_xzzzz_xyz_0, tg_xzzzz_xyz_1, tg_xzzzz_xz_1, tg_xzzzz_xzz_0, tg_xzzzz_xzz_1, \
                                         tg_xzzzz_yy_1, tg_xzzzz_yyy_0, tg_xzzzz_yyy_1, tg_xzzzz_yyz_0, tg_xzzzz_yyz_1, \
                                         tg_xzzzz_yz_1, tg_xzzzz_yzz_0, tg_xzzzz_yzz_1, tg_xzzzz_zz_1, tg_xzzzz_zzz_0, \
                                         tg_xzzzz_zzz_1, tg_yyyy_xxx_0, tg_yyyy_xxx_1, tg_yyyy_xxy_0, tg_yyyy_xxy_1, \
                                         tg_yyyy_xxz_0, tg_yyyy_xxz_1, tg_yyyy_xyy_0, tg_yyyy_xyy_1, tg_yyyy_xyz_0, \
                                         tg_yyyy_xyz_1, tg_yyyy_xzz_0, tg_yyyy_xzz_1, tg_yyyy_yyy_0, tg_yyyy_yyy_1, \
                                         tg_yyyy_yyz_0, tg_yyyy_yyz_1, tg_yyyy_yzz_0, tg_yyyy_yzz_1, tg_yyyy_zzz_0, \
                                         tg_yyyy_zzz_1, tg_yyyyy_xx_1, tg_yyyyy_xxx_0, tg_yyyyy_xxx_1, tg_yyyyy_xxy_0, \
                                         tg_yyyyy_xxy_1, tg_yyyyy_xxz_0, tg_yyyyy_xxz_1, tg_yyyyy_xy_1, tg_yyyyy_xyy_0, \
                                         tg_yyyyy_xyy_1, tg_yyyyy_xyz_0, tg_yyyyy_xyz_1, tg_yyyyy_xz_1, tg_yyyyy_xzz_0, \
                                         tg_yyyyy_xzz_1, tg_yyyyy_yy_1, tg_yyyyy_yyy_0, tg_yyyyy_yyy_1, tg_yyyyy_yyz_0, \
                                         tg_yyyyy_yyz_1, tg_yyyyy_yz_1, tg_yyyyy_yzz_0, tg_yyyyy_yzz_1, tg_yyyyy_zz_1, \
                                         tg_yyyyy_zzz_0, tg_yyyyy_zzz_1, tg_yyyyz_xx_1, tg_yyyyz_xxx_0, tg_yyyyz_xxx_1, \
                                         tg_yyyyz_xxy_0, tg_yyyyz_xxy_1, tg_yyyyz_xxz_0, tg_yyyyz_xxz_1, tg_yyyyz_xy_1, \
                                         tg_yyyyz_xyy_0, tg_yyyyz_xyy_1, tg_yyyyz_xyz_0, tg_yyyyz_xyz_1, tg_yyyyz_xz_1, \
                                         tg_yyyyz_xzz_0, tg_yyyyz_xzz_1, tg_yyyyz_yy_1, tg_yyyyz_yyy_0, tg_yyyyz_yyy_1, \
                                         tg_yyyyz_yyz_0, tg_yyyyz_yyz_1, tg_yyyyz_yz_1, tg_yyyyz_yzz_0, tg_yyyyz_yzz_1, \
                                         tg_yyyyz_zz_1, tg_yyyyz_zzz_0, tg_yyyyz_zzz_1, tg_yyyz_xxx_0, tg_yyyz_xxx_1, \
                                         tg_yyyz_xxy_0, tg_yyyz_xxy_1, tg_yyyz_xxz_0, tg_yyyz_xxz_1, tg_yyyz_xyy_0, \
                                         tg_yyyz_xyy_1, tg_yyyz_xyz_0, tg_yyyz_xyz_1, tg_yyyz_xzz_0, tg_yyyz_xzz_1, \
                                         tg_yyyz_yyy_0, tg_yyyz_yyy_1, tg_yyyz_yyz_0, tg_yyyz_yyz_1, tg_yyyz_yzz_0, \
                                         tg_yyyz_yzz_1, tg_yyyz_zzz_0, tg_yyyz_zzz_1, tg_yyyzz_xx_1, tg_yyyzz_xxx_0, \
                                         tg_yyyzz_xxx_1, tg_yyyzz_xxy_0, tg_yyyzz_xxy_1, tg_yyyzz_xxz_0, tg_yyyzz_xxz_1, \
                                         tg_yyyzz_xy_1, tg_yyyzz_xyy_0, tg_yyyzz_xyy_1, tg_yyyzz_xyz_0, tg_yyyzz_xyz_1, \
                                         tg_yyyzz_xz_1, tg_yyyzz_xzz_0, tg_yyyzz_xzz_1, tg_yyyzz_yy_1, tg_yyyzz_yyy_0, \
                                         tg_yyyzz_yyy_1, tg_yyyzz_yyz_0, tg_yyyzz_yyz_1, tg_yyyzz_yz_1, tg_yyyzz_yzz_0, \
                                         tg_yyyzz_yzz_1, tg_yyyzz_zz_1, tg_yyyzz_zzz_0, tg_yyyzz_zzz_1, tg_yyzz_xxx_0, \
                                         tg_yyzz_xxx_1, tg_yyzz_xxy_0, tg_yyzz_xxy_1, tg_yyzz_xxz_0, tg_yyzz_xxz_1, \
                                         tg_yyzz_xyy_0, tg_yyzz_xyy_1, tg_yyzz_xyz_0, tg_yyzz_xyz_1, tg_yyzz_xzz_0, \
                                         tg_yyzz_xzz_1, tg_yyzz_yyy_0, tg_yyzz_yyy_1, tg_yyzz_yyz_0, tg_yyzz_yyz_1, \
                                         tg_yyzz_yzz_0, tg_yyzz_yzz_1, tg_yyzz_zzz_0, tg_yyzz_zzz_1, tg_yyzzz_xx_1, \
                                         tg_yyzzz_xxx_0, tg_yyzzz_xxx_1, tg_yyzzz_xxy_0, tg_yyzzz_xxy_1, tg_yyzzz_xxz_0, \
                                         tg_yyzzz_xxz_1, tg_yyzzz_xy_1, tg_yyzzz_xyy_0, tg_yyzzz_xyy_1, tg_yyzzz_xyz_0, \
                                         tg_yyzzz_xyz_1, tg_yyzzz_xz_1, tg_yyzzz_xzz_0, tg_yyzzz_xzz_1, tg_yyzzz_yy_1, \
                                         tg_yyzzz_yyy_0, tg_yyzzz_yyy_1, tg_yyzzz_yz_1, tg_yyzzz_zz_1, tg_yzzz_xxx_0, \
                                         tg_yzzz_xxx_1, tg_yzzz_xxy_0, tg_yzzz_xxy_1, tg_yzzz_xxz_0, tg_yzzz_xxz_1, \
                                         tg_yzzz_xyy_0, tg_yzzz_xyy_1, tg_yzzz_xyz_0, tg_yzzz_xyz_1, tg_yzzz_xzz_0, \
                                         tg_yzzz_xzz_1, tg_yzzz_yyy_0, tg_yzzz_yyy_1, tg_yzzz_yyz_0, tg_yzzz_yyz_1, \
                                         tg_yzzz_yzz_0, tg_yzzz_yzz_1, tg_yzzz_zzz_0, tg_yzzz_zzz_1, tg_zzzz_xxx_0, \
                                         tg_zzzz_xxx_1, tg_zzzz_xxy_0, tg_zzzz_xxy_1, tg_zzzz_xxz_0, tg_zzzz_xxz_1, \
                                         tg_zzzz_xyy_0, tg_zzzz_xyy_1, tg_zzzz_xyz_0, tg_zzzz_xyz_1, tg_zzzz_xzz_0, \
                                         tg_zzzz_xzz_1, tg_zzzz_yyy_0, tg_zzzz_yyy_1, tg_zzzz_yyz_0, tg_zzzz_yyz_1, \
                                         tg_zzzz_yzz_0, tg_zzzz_yzz_1, tg_zzzz_zzz_0, tg_zzzz_zzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxzzz_xyz_0[j] = pb_x * tg_xxzzz_xyz_0[j] + fr * tg_xxzzz_xyz_1[j] + fl1_fx * (tg_xzzz_xyz_0[j] - tg_xzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yz_1[j];

                    tg_xxxzzz_xzz_0[j] = pb_x * tg_xxzzz_xzz_0[j] + fr * tg_xxzzz_xzz_1[j] + fl1_fx * (tg_xzzz_xzz_0[j] - tg_xzzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_zz_1[j];

                    tg_xxxzzz_yyy_0[j] = pb_x * tg_xxzzz_yyy_0[j] + fr * tg_xxzzz_yyy_1[j] + fl1_fx * (tg_xzzz_yyy_0[j] - tg_xzzz_yyy_1[j] * fl1_fza);

                    tg_xxxzzz_yyz_0[j] = pb_x * tg_xxzzz_yyz_0[j] + fr * tg_xxzzz_yyz_1[j] + fl1_fx * (tg_xzzz_yyz_0[j] - tg_xzzz_yyz_1[j] * fl1_fza);

                    tg_xxxzzz_yzz_0[j] = pb_x * tg_xxzzz_yzz_0[j] + fr * tg_xxzzz_yzz_1[j] + fl1_fx * (tg_xzzz_yzz_0[j] - tg_xzzz_yzz_1[j] * fl1_fza);

                    tg_xxxzzz_zzz_0[j] = pb_x * tg_xxzzz_zzz_0[j] + fr * tg_xxzzz_zzz_1[j] + fl1_fx * (tg_xzzz_zzz_0[j] - tg_xzzz_zzz_1[j] * fl1_fza);

                    tg_xxyyyy_xxx_0[j] = pb_x * tg_xyyyy_xxx_0[j] + fr * tg_xyyyy_xxx_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxx_0[j] - tg_yyyy_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xx_1[j];

                    tg_xxyyyy_xxy_0[j] = pb_x * tg_xyyyy_xxy_0[j] + fr * tg_xyyyy_xxy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxy_0[j] - tg_yyyy_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xy_1[j];

                    tg_xxyyyy_xxz_0[j] = pb_x * tg_xyyyy_xxz_0[j] + fr * tg_xyyyy_xxz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxz_0[j] - tg_yyyy_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xz_1[j];

                    tg_xxyyyy_xyy_0[j] = pb_x * tg_xyyyy_xyy_0[j] + fr * tg_xyyyy_xyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyy_0[j] - tg_yyyy_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yy_1[j];

                    tg_xxyyyy_xyz_0[j] = pb_x * tg_xyyyy_xyz_0[j] + fr * tg_xyyyy_xyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyz_0[j] - tg_yyyy_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yz_1[j];

                    tg_xxyyyy_xzz_0[j] = pb_x * tg_xyyyy_xzz_0[j] + fr * tg_xyyyy_xzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xzz_0[j] - tg_yyyy_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_zz_1[j];

                    tg_xxyyyy_yyy_0[j] = pb_x * tg_xyyyy_yyy_0[j] + fr * tg_xyyyy_yyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyy_0[j] - tg_yyyy_yyy_1[j] * fl1_fza);

                    tg_xxyyyy_yyz_0[j] = pb_x * tg_xyyyy_yyz_0[j] + fr * tg_xyyyy_yyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyz_0[j] - tg_yyyy_yyz_1[j] * fl1_fza);

                    tg_xxyyyy_yzz_0[j] = pb_x * tg_xyyyy_yzz_0[j] + fr * tg_xyyyy_yzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yzz_0[j] - tg_yyyy_yzz_1[j] * fl1_fza);

                    tg_xxyyyy_zzz_0[j] = pb_x * tg_xyyyy_zzz_0[j] + fr * tg_xyyyy_zzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_zzz_0[j] - tg_yyyy_zzz_1[j] * fl1_fza);

                    tg_xxyyyz_xxx_0[j] = pb_x * tg_xyyyz_xxx_0[j] + fr * tg_xyyyz_xxx_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxx_0[j] - tg_yyyz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xx_1[j];

                    tg_xxyyyz_xxy_0[j] = pb_x * tg_xyyyz_xxy_0[j] + fr * tg_xyyyz_xxy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxy_0[j] - tg_yyyz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xy_1[j];

                    tg_xxyyyz_xxz_0[j] = pb_x * tg_xyyyz_xxz_0[j] + fr * tg_xyyyz_xxz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxz_0[j] - tg_yyyz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xz_1[j];

                    tg_xxyyyz_xyy_0[j] = pb_x * tg_xyyyz_xyy_0[j] + fr * tg_xyyyz_xyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyy_0[j] - tg_yyyz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yy_1[j];

                    tg_xxyyyz_xyz_0[j] = pb_x * tg_xyyyz_xyz_0[j] + fr * tg_xyyyz_xyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyz_0[j] - tg_yyyz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yz_1[j];

                    tg_xxyyyz_xzz_0[j] = pb_x * tg_xyyyz_xzz_0[j] + fr * tg_xyyyz_xzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xzz_0[j] - tg_yyyz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_zz_1[j];

                    tg_xxyyyz_yyy_0[j] = pb_x * tg_xyyyz_yyy_0[j] + fr * tg_xyyyz_yyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyy_0[j] - tg_yyyz_yyy_1[j] * fl1_fza);

                    tg_xxyyyz_yyz_0[j] = pb_x * tg_xyyyz_yyz_0[j] + fr * tg_xyyyz_yyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyz_0[j] - tg_yyyz_yyz_1[j] * fl1_fza);

                    tg_xxyyyz_yzz_0[j] = pb_x * tg_xyyyz_yzz_0[j] + fr * tg_xyyyz_yzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yzz_0[j] - tg_yyyz_yzz_1[j] * fl1_fza);

                    tg_xxyyyz_zzz_0[j] = pb_x * tg_xyyyz_zzz_0[j] + fr * tg_xyyyz_zzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_zzz_0[j] - tg_yyyz_zzz_1[j] * fl1_fza);

                    tg_xxyyzz_xxx_0[j] = pb_x * tg_xyyzz_xxx_0[j] + fr * tg_xyyzz_xxx_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxx_0[j] - tg_yyzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xx_1[j];

                    tg_xxyyzz_xxy_0[j] = pb_x * tg_xyyzz_xxy_0[j] + fr * tg_xyyzz_xxy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxy_0[j] - tg_yyzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xy_1[j];

                    tg_xxyyzz_xxz_0[j] = pb_x * tg_xyyzz_xxz_0[j] + fr * tg_xyyzz_xxz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxz_0[j] - tg_yyzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xz_1[j];

                    tg_xxyyzz_xyy_0[j] = pb_x * tg_xyyzz_xyy_0[j] + fr * tg_xyyzz_xyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyy_0[j] - tg_yyzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yy_1[j];

                    tg_xxyyzz_xyz_0[j] = pb_x * tg_xyyzz_xyz_0[j] + fr * tg_xyyzz_xyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyz_0[j] - tg_yyzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yz_1[j];

                    tg_xxyyzz_xzz_0[j] = pb_x * tg_xyyzz_xzz_0[j] + fr * tg_xyyzz_xzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xzz_0[j] - tg_yyzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_zz_1[j];

                    tg_xxyyzz_yyy_0[j] = pb_x * tg_xyyzz_yyy_0[j] + fr * tg_xyyzz_yyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyy_0[j] - tg_yyzz_yyy_1[j] * fl1_fza);

                    tg_xxyyzz_yyz_0[j] = pb_x * tg_xyyzz_yyz_0[j] + fr * tg_xyyzz_yyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyz_0[j] - tg_yyzz_yyz_1[j] * fl1_fza);

                    tg_xxyyzz_yzz_0[j] = pb_x * tg_xyyzz_yzz_0[j] + fr * tg_xyyzz_yzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yzz_0[j] - tg_yyzz_yzz_1[j] * fl1_fza);

                    tg_xxyyzz_zzz_0[j] = pb_x * tg_xyyzz_zzz_0[j] + fr * tg_xyyzz_zzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_zzz_0[j] - tg_yyzz_zzz_1[j] * fl1_fza);

                    tg_xxyzzz_xxx_0[j] = pb_x * tg_xyzzz_xxx_0[j] + fr * tg_xyzzz_xxx_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxx_0[j] - tg_yzzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xx_1[j];

                    tg_xxyzzz_xxy_0[j] = pb_x * tg_xyzzz_xxy_0[j] + fr * tg_xyzzz_xxy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxy_0[j] - tg_yzzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xy_1[j];

                    tg_xxyzzz_xxz_0[j] = pb_x * tg_xyzzz_xxz_0[j] + fr * tg_xyzzz_xxz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxz_0[j] - tg_yzzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xz_1[j];

                    tg_xxyzzz_xyy_0[j] = pb_x * tg_xyzzz_xyy_0[j] + fr * tg_xyzzz_xyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyy_0[j] - tg_yzzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yy_1[j];

                    tg_xxyzzz_xyz_0[j] = pb_x * tg_xyzzz_xyz_0[j] + fr * tg_xyzzz_xyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyz_0[j] - tg_yzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yz_1[j];

                    tg_xxyzzz_xzz_0[j] = pb_x * tg_xyzzz_xzz_0[j] + fr * tg_xyzzz_xzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xzz_0[j] - tg_yzzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_zz_1[j];

                    tg_xxyzzz_yyy_0[j] = pb_x * tg_xyzzz_yyy_0[j] + fr * tg_xyzzz_yyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyy_0[j] - tg_yzzz_yyy_1[j] * fl1_fza);

                    tg_xxyzzz_yyz_0[j] = pb_x * tg_xyzzz_yyz_0[j] + fr * tg_xyzzz_yyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyz_0[j] - tg_yzzz_yyz_1[j] * fl1_fza);

                    tg_xxyzzz_yzz_0[j] = pb_x * tg_xyzzz_yzz_0[j] + fr * tg_xyzzz_yzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yzz_0[j] - tg_yzzz_yzz_1[j] * fl1_fza);

                    tg_xxyzzz_zzz_0[j] = pb_x * tg_xyzzz_zzz_0[j] + fr * tg_xyzzz_zzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_zzz_0[j] - tg_yzzz_zzz_1[j] * fl1_fza);

                    tg_xxzzzz_xxx_0[j] = pb_x * tg_xzzzz_xxx_0[j] + fr * tg_xzzzz_xxx_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxx_0[j] - tg_zzzz_xxx_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xx_1[j];

                    tg_xxzzzz_xxy_0[j] = pb_x * tg_xzzzz_xxy_0[j] + fr * tg_xzzzz_xxy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxy_0[j] - tg_zzzz_xxy_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xy_1[j];

                    tg_xxzzzz_xxz_0[j] = pb_x * tg_xzzzz_xxz_0[j] + fr * tg_xzzzz_xxz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxz_0[j] - tg_zzzz_xxz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xz_1[j];

                    tg_xxzzzz_xyy_0[j] = pb_x * tg_xzzzz_xyy_0[j] + fr * tg_xzzzz_xyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyy_0[j] - tg_zzzz_xyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yy_1[j];

                    tg_xxzzzz_xyz_0[j] = pb_x * tg_xzzzz_xyz_0[j] + fr * tg_xzzzz_xyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyz_0[j] - tg_zzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yz_1[j];

                    tg_xxzzzz_xzz_0[j] = pb_x * tg_xzzzz_xzz_0[j] + fr * tg_xzzzz_xzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xzz_0[j] - tg_zzzz_xzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_zz_1[j];

                    tg_xxzzzz_yyy_0[j] = pb_x * tg_xzzzz_yyy_0[j] + fr * tg_xzzzz_yyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyy_0[j] - tg_zzzz_yyy_1[j] * fl1_fza);

                    tg_xxzzzz_yyz_0[j] = pb_x * tg_xzzzz_yyz_0[j] + fr * tg_xzzzz_yyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyz_0[j] - tg_zzzz_yyz_1[j] * fl1_fza);

                    tg_xxzzzz_yzz_0[j] = pb_x * tg_xzzzz_yzz_0[j] + fr * tg_xzzzz_yzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yzz_0[j] - tg_zzzz_yzz_1[j] * fl1_fza);

                    tg_xxzzzz_zzz_0[j] = pb_x * tg_xzzzz_zzz_0[j] + fr * tg_xzzzz_zzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_zzz_0[j] - tg_zzzz_zzz_1[j] * fl1_fza);

                    tg_xyyyyy_xxx_0[j] = pb_x * tg_yyyyy_xxx_0[j] + fr * tg_yyyyy_xxx_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xx_1[j];

                    tg_xyyyyy_xxy_0[j] = pb_x * tg_yyyyy_xxy_0[j] + fr * tg_yyyyy_xxy_1[j] + fl1_fxn * tg_yyyyy_xy_1[j];

                    tg_xyyyyy_xxz_0[j] = pb_x * tg_yyyyy_xxz_0[j] + fr * tg_yyyyy_xxz_1[j] + fl1_fxn * tg_yyyyy_xz_1[j];

                    tg_xyyyyy_xyy_0[j] = pb_x * tg_yyyyy_xyy_0[j] + fr * tg_yyyyy_xyy_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yy_1[j];

                    tg_xyyyyy_xyz_0[j] = pb_x * tg_yyyyy_xyz_0[j] + fr * tg_yyyyy_xyz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yz_1[j];

                    tg_xyyyyy_xzz_0[j] = pb_x * tg_yyyyy_xzz_0[j] + fr * tg_yyyyy_xzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_zz_1[j];

                    tg_xyyyyy_yyy_0[j] = pb_x * tg_yyyyy_yyy_0[j] + fr * tg_yyyyy_yyy_1[j];

                    tg_xyyyyy_yyz_0[j] = pb_x * tg_yyyyy_yyz_0[j] + fr * tg_yyyyy_yyz_1[j];

                    tg_xyyyyy_yzz_0[j] = pb_x * tg_yyyyy_yzz_0[j] + fr * tg_yyyyy_yzz_1[j];

                    tg_xyyyyy_zzz_0[j] = pb_x * tg_yyyyy_zzz_0[j] + fr * tg_yyyyy_zzz_1[j];

                    tg_xyyyyz_xxx_0[j] = pb_x * tg_yyyyz_xxx_0[j] + fr * tg_yyyyz_xxx_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xx_1[j];

                    tg_xyyyyz_xxy_0[j] = pb_x * tg_yyyyz_xxy_0[j] + fr * tg_yyyyz_xxy_1[j] + fl1_fxn * tg_yyyyz_xy_1[j];

                    tg_xyyyyz_xxz_0[j] = pb_x * tg_yyyyz_xxz_0[j] + fr * tg_yyyyz_xxz_1[j] + fl1_fxn * tg_yyyyz_xz_1[j];

                    tg_xyyyyz_xyy_0[j] = pb_x * tg_yyyyz_xyy_0[j] + fr * tg_yyyyz_xyy_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yy_1[j];

                    tg_xyyyyz_xyz_0[j] = pb_x * tg_yyyyz_xyz_0[j] + fr * tg_yyyyz_xyz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yz_1[j];

                    tg_xyyyyz_xzz_0[j] = pb_x * tg_yyyyz_xzz_0[j] + fr * tg_yyyyz_xzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_zz_1[j];

                    tg_xyyyyz_yyy_0[j] = pb_x * tg_yyyyz_yyy_0[j] + fr * tg_yyyyz_yyy_1[j];

                    tg_xyyyyz_yyz_0[j] = pb_x * tg_yyyyz_yyz_0[j] + fr * tg_yyyyz_yyz_1[j];

                    tg_xyyyyz_yzz_0[j] = pb_x * tg_yyyyz_yzz_0[j] + fr * tg_yyyyz_yzz_1[j];

                    tg_xyyyyz_zzz_0[j] = pb_x * tg_yyyyz_zzz_0[j] + fr * tg_yyyyz_zzz_1[j];

                    tg_xyyyzz_xxx_0[j] = pb_x * tg_yyyzz_xxx_0[j] + fr * tg_yyyzz_xxx_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xx_1[j];

                    tg_xyyyzz_xxy_0[j] = pb_x * tg_yyyzz_xxy_0[j] + fr * tg_yyyzz_xxy_1[j] + fl1_fxn * tg_yyyzz_xy_1[j];

                    tg_xyyyzz_xxz_0[j] = pb_x * tg_yyyzz_xxz_0[j] + fr * tg_yyyzz_xxz_1[j] + fl1_fxn * tg_yyyzz_xz_1[j];

                    tg_xyyyzz_xyy_0[j] = pb_x * tg_yyyzz_xyy_0[j] + fr * tg_yyyzz_xyy_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yy_1[j];

                    tg_xyyyzz_xyz_0[j] = pb_x * tg_yyyzz_xyz_0[j] + fr * tg_yyyzz_xyz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yz_1[j];

                    tg_xyyyzz_xzz_0[j] = pb_x * tg_yyyzz_xzz_0[j] + fr * tg_yyyzz_xzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_zz_1[j];

                    tg_xyyyzz_yyy_0[j] = pb_x * tg_yyyzz_yyy_0[j] + fr * tg_yyyzz_yyy_1[j];

                    tg_xyyyzz_yyz_0[j] = pb_x * tg_yyyzz_yyz_0[j] + fr * tg_yyyzz_yyz_1[j];

                    tg_xyyyzz_yzz_0[j] = pb_x * tg_yyyzz_yzz_0[j] + fr * tg_yyyzz_yzz_1[j];

                    tg_xyyyzz_zzz_0[j] = pb_x * tg_yyyzz_zzz_0[j] + fr * tg_yyyzz_zzz_1[j];

                    tg_xyyzzz_xxx_0[j] = pb_x * tg_yyzzz_xxx_0[j] + fr * tg_yyzzz_xxx_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xx_1[j];

                    tg_xyyzzz_xxy_0[j] = pb_x * tg_yyzzz_xxy_0[j] + fr * tg_yyzzz_xxy_1[j] + fl1_fxn * tg_yyzzz_xy_1[j];

                    tg_xyyzzz_xxz_0[j] = pb_x * tg_yyzzz_xxz_0[j] + fr * tg_yyzzz_xxz_1[j] + fl1_fxn * tg_yyzzz_xz_1[j];

                    tg_xyyzzz_xyy_0[j] = pb_x * tg_yyzzz_xyy_0[j] + fr * tg_yyzzz_xyy_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yy_1[j];

                    tg_xyyzzz_xyz_0[j] = pb_x * tg_yyzzz_xyz_0[j] + fr * tg_yyzzz_xyz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yz_1[j];

                    tg_xyyzzz_xzz_0[j] = pb_x * tg_yyzzz_xzz_0[j] + fr * tg_yyzzz_xzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_zz_1[j];

                    tg_xyyzzz_yyy_0[j] = pb_x * tg_yyzzz_yyy_0[j] + fr * tg_yyzzz_yyy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISF_187_280(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (187,280)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        auto r_pb_y = braGtoPairsBlock.getDistancesPBY();

        auto r_pb_z = braGtoPairsBlock.getDistancesPBZ();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {3, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_3_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_2_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {2, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_3_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_3_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {3, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrPair]; i < epos[iContrPair]; i++)
            {
                // set up pointers to Obara-Saika factors

                double fx = b_fx[i];

                auto fza = osFactors.data(4 * idx + 2);

                auto fxn = osFactors.data(4 * idx);

                // set up distances R(PB) = P - B

                auto pb_x = r_pb_x[i];

                auto pb_y = r_pb_y[i];

                auto pb_z = r_pb_z[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                auto wp_y = wpDistances.data(3 * idx + 1);

                auto wp_z = wpDistances.data(3 * idx + 2);

                // set up pointers to auxilary integrals

                auto tg_yyyyy_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 150); 

                auto tg_yyyyy_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 151); 

                auto tg_yyyyy_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 152); 

                auto tg_yyyyy_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 153); 

                auto tg_yyyyy_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 154); 

                auto tg_yyyyy_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 155); 

                auto tg_yyyyy_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 156); 

                auto tg_yyyyy_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 157); 

                auto tg_yyyyy_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 158); 

                auto tg_yyyyy_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 159); 

                auto tg_yyyyz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 160); 

                auto tg_yyyyz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 161); 

                auto tg_yyyyz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 162); 

                auto tg_yyyyz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 163); 

                auto tg_yyyyz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 164); 

                auto tg_yyyyz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 165); 

                auto tg_yyyyz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 166); 

                auto tg_yyyyz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 167); 

                auto tg_yyyyz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 168); 

                auto tg_yyyyz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 169); 

                auto tg_yyyzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 170); 

                auto tg_yyyzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 171); 

                auto tg_yyyzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 172); 

                auto tg_yyyzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 173); 

                auto tg_yyyzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 174); 

                auto tg_yyyzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 175); 

                auto tg_yyyzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 176); 

                auto tg_yyyzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 177); 

                auto tg_yyyzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 178); 

                auto tg_yyyzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 179); 

                auto tg_yyzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 180); 

                auto tg_yyzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 181); 

                auto tg_yyzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 182); 

                auto tg_yyzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 183); 

                auto tg_yyzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 184); 

                auto tg_yyzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 185); 

                auto tg_yyzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 186); 

                auto tg_yyzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 187); 

                auto tg_yyzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 188); 

                auto tg_yyzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 189); 

                auto tg_yzzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 190); 

                auto tg_yzzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 191); 

                auto tg_yzzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 192); 

                auto tg_yzzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 193); 

                auto tg_yzzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 194); 

                auto tg_yzzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 195); 

                auto tg_yzzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 196); 

                auto tg_yzzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 197); 

                auto tg_yzzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 198); 

                auto tg_yzzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 199); 

                auto tg_zzzzz_xxx_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 200); 

                auto tg_zzzzz_xxy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 201); 

                auto tg_zzzzz_xxz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 202); 

                auto tg_zzzzz_xyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 203); 

                auto tg_zzzzz_xyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 204); 

                auto tg_zzzzz_xzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 205); 

                auto tg_zzzzz_yyy_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 206); 

                auto tg_zzzzz_yyz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 207); 

                auto tg_zzzzz_yzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 208); 

                auto tg_zzzzz_zzz_0 = primBuffer[pidx_g_5_3_m0].data(210 * idx + 209); 

                auto tg_yyyyy_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 150); 

                auto tg_yyyyy_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 151); 

                auto tg_yyyyy_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 152); 

                auto tg_yyyyy_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 153); 

                auto tg_yyyyy_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 154); 

                auto tg_yyyyy_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 155); 

                auto tg_yyyyy_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 156); 

                auto tg_yyyyy_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 157); 

                auto tg_yyyyy_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 158); 

                auto tg_yyyyy_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 159); 

                auto tg_yyyyz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 160); 

                auto tg_yyyyz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 161); 

                auto tg_yyyyz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 162); 

                auto tg_yyyyz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 163); 

                auto tg_yyyyz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 164); 

                auto tg_yyyyz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 165); 

                auto tg_yyyyz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 166); 

                auto tg_yyyyz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 167); 

                auto tg_yyyyz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 168); 

                auto tg_yyyyz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 169); 

                auto tg_yyyzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 170); 

                auto tg_yyyzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 171); 

                auto tg_yyyzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 172); 

                auto tg_yyyzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 173); 

                auto tg_yyyzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 174); 

                auto tg_yyyzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 175); 

                auto tg_yyyzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 176); 

                auto tg_yyyzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 177); 

                auto tg_yyyzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 178); 

                auto tg_yyyzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 179); 

                auto tg_yyzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 180); 

                auto tg_yyzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 181); 

                auto tg_yyzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 182); 

                auto tg_yyzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 183); 

                auto tg_yyzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 184); 

                auto tg_yyzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 185); 

                auto tg_yyzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 186); 

                auto tg_yyzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 187); 

                auto tg_yyzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 188); 

                auto tg_yyzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 189); 

                auto tg_yzzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 190); 

                auto tg_yzzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 191); 

                auto tg_yzzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 192); 

                auto tg_yzzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 193); 

                auto tg_yzzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 194); 

                auto tg_yzzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 195); 

                auto tg_yzzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 196); 

                auto tg_yzzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 197); 

                auto tg_yzzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 198); 

                auto tg_yzzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 199); 

                auto tg_zzzzz_xxx_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 200); 

                auto tg_zzzzz_xxy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 201); 

                auto tg_zzzzz_xxz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 202); 

                auto tg_zzzzz_xyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 203); 

                auto tg_zzzzz_xyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 204); 

                auto tg_zzzzz_xzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 205); 

                auto tg_zzzzz_yyy_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 206); 

                auto tg_zzzzz_yyz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 207); 

                auto tg_zzzzz_yzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 208); 

                auto tg_zzzzz_zzz_1 = primBuffer[pidx_g_5_3_m1].data(210 * idx + 209); 

                auto tg_yyyy_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 100); 

                auto tg_yyyy_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 101); 

                auto tg_yyyy_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 102); 

                auto tg_yyyy_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 103); 

                auto tg_yyyy_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 104); 

                auto tg_yyyy_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 105); 

                auto tg_yyyy_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 106); 

                auto tg_yyyy_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 107); 

                auto tg_yyyy_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 108); 

                auto tg_yyyy_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 109); 

                auto tg_yyyz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 110); 

                auto tg_yyyz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 111); 

                auto tg_yyyz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 112); 

                auto tg_yyyz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 113); 

                auto tg_yyyz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 114); 

                auto tg_yyyz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 115); 

                auto tg_yyyz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 116); 

                auto tg_yyyz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 117); 

                auto tg_yyyz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 118); 

                auto tg_yyyz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 119); 

                auto tg_yyzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 120); 

                auto tg_yyzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 121); 

                auto tg_yyzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 122); 

                auto tg_yyzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 123); 

                auto tg_yyzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 124); 

                auto tg_yyzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 125); 

                auto tg_yyzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 126); 

                auto tg_yyzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 127); 

                auto tg_yyzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 128); 

                auto tg_yyzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 129); 

                auto tg_yzzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 130); 

                auto tg_yzzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 131); 

                auto tg_yzzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 132); 

                auto tg_yzzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 133); 

                auto tg_yzzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 134); 

                auto tg_yzzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 135); 

                auto tg_yzzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 136); 

                auto tg_yzzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 137); 

                auto tg_yzzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 138); 

                auto tg_yzzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 139); 

                auto tg_zzzz_xxx_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 140); 

                auto tg_zzzz_xxy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 141); 

                auto tg_zzzz_xxz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 142); 

                auto tg_zzzz_xyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 143); 

                auto tg_zzzz_xyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 144); 

                auto tg_zzzz_xzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 145); 

                auto tg_zzzz_yyy_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 146); 

                auto tg_zzzz_yyz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 147); 

                auto tg_zzzz_yzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 148); 

                auto tg_zzzz_zzz_0 = primBuffer[pidx_g_4_3_m0].data(150 * idx + 149); 

                auto tg_yyyy_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 100); 

                auto tg_yyyy_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 101); 

                auto tg_yyyy_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 102); 

                auto tg_yyyy_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 103); 

                auto tg_yyyy_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 104); 

                auto tg_yyyy_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 105); 

                auto tg_yyyy_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 106); 

                auto tg_yyyy_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 107); 

                auto tg_yyyy_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 108); 

                auto tg_yyyy_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 109); 

                auto tg_yyyz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 110); 

                auto tg_yyyz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 111); 

                auto tg_yyyz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 112); 

                auto tg_yyyz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 113); 

                auto tg_yyyz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 114); 

                auto tg_yyyz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 115); 

                auto tg_yyyz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 116); 

                auto tg_yyyz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 117); 

                auto tg_yyyz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 118); 

                auto tg_yyyz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 119); 

                auto tg_yyzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 120); 

                auto tg_yyzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 121); 

                auto tg_yyzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 122); 

                auto tg_yyzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 123); 

                auto tg_yyzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 124); 

                auto tg_yyzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 125); 

                auto tg_yyzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 126); 

                auto tg_yyzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 127); 

                auto tg_yyzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 128); 

                auto tg_yyzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 129); 

                auto tg_yzzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 130); 

                auto tg_yzzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 131); 

                auto tg_yzzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 132); 

                auto tg_yzzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 133); 

                auto tg_yzzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 134); 

                auto tg_yzzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 135); 

                auto tg_yzzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 136); 

                auto tg_yzzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 137); 

                auto tg_yzzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 138); 

                auto tg_yzzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 139); 

                auto tg_zzzz_xxx_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 140); 

                auto tg_zzzz_xxy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 141); 

                auto tg_zzzz_xxz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 142); 

                auto tg_zzzz_xyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 143); 

                auto tg_zzzz_xyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 144); 

                auto tg_zzzz_xzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 145); 

                auto tg_zzzz_yyy_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 146); 

                auto tg_zzzz_yyz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 147); 

                auto tg_zzzz_yzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 148); 

                auto tg_zzzz_zzz_1 = primBuffer[pidx_g_4_3_m1].data(150 * idx + 149); 

                auto tg_yyyyy_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 90); 

                auto tg_yyyyy_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 91); 

                auto tg_yyyyy_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 92); 

                auto tg_yyyyy_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 93); 

                auto tg_yyyyy_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 94); 

                auto tg_yyyyy_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 95); 

                auto tg_yyyyz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 96); 

                auto tg_yyyyz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 97); 

                auto tg_yyyyz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 98); 

                auto tg_yyyyz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 99); 

                auto tg_yyyyz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 100); 

                auto tg_yyyyz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 101); 

                auto tg_yyyzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 102); 

                auto tg_yyyzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 103); 

                auto tg_yyyzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 104); 

                auto tg_yyyzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 105); 

                auto tg_yyyzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 106); 

                auto tg_yyyzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 107); 

                auto tg_yyzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 108); 

                auto tg_yyzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 109); 

                auto tg_yyzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 110); 

                auto tg_yyzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 111); 

                auto tg_yyzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 112); 

                auto tg_yyzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 113); 

                auto tg_yzzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 114); 

                auto tg_yzzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 115); 

                auto tg_yzzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 116); 

                auto tg_yzzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 117); 

                auto tg_yzzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 118); 

                auto tg_yzzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 119); 

                auto tg_zzzzz_xx_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 120); 

                auto tg_zzzzz_xy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 121); 

                auto tg_zzzzz_xz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 122); 

                auto tg_zzzzz_yy_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 123); 

                auto tg_zzzzz_yz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 124); 

                auto tg_zzzzz_zz_1 = primBuffer[pidx_g_5_2_m1].data(126 * idx + 125); 

                // set up pointers to integrals

                auto tg_xyyzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 187); 

                auto tg_xyyzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 188); 

                auto tg_xyyzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 189); 

                auto tg_xyzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 190); 

                auto tg_xyzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 191); 

                auto tg_xyzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 192); 

                auto tg_xyzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 193); 

                auto tg_xyzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 194); 

                auto tg_xyzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 195); 

                auto tg_xyzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 196); 

                auto tg_xyzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 197); 

                auto tg_xyzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 198); 

                auto tg_xyzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 199); 

                auto tg_xzzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 200); 

                auto tg_xzzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 201); 

                auto tg_xzzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 202); 

                auto tg_xzzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 203); 

                auto tg_xzzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 204); 

                auto tg_xzzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 205); 

                auto tg_xzzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 206); 

                auto tg_xzzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 207); 

                auto tg_xzzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 208); 

                auto tg_xzzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 209); 

                auto tg_yyyyyy_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 210); 

                auto tg_yyyyyy_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 211); 

                auto tg_yyyyyy_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 212); 

                auto tg_yyyyyy_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 213); 

                auto tg_yyyyyy_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 214); 

                auto tg_yyyyyy_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 215); 

                auto tg_yyyyyy_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 216); 

                auto tg_yyyyyy_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 217); 

                auto tg_yyyyyy_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 218); 

                auto tg_yyyyyy_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 219); 

                auto tg_yyyyyz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 220); 

                auto tg_yyyyyz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 221); 

                auto tg_yyyyyz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 222); 

                auto tg_yyyyyz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 223); 

                auto tg_yyyyyz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 224); 

                auto tg_yyyyyz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 225); 

                auto tg_yyyyyz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 226); 

                auto tg_yyyyyz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 227); 

                auto tg_yyyyyz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 228); 

                auto tg_yyyyyz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 229); 

                auto tg_yyyyzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 230); 

                auto tg_yyyyzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 231); 

                auto tg_yyyyzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 232); 

                auto tg_yyyyzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 233); 

                auto tg_yyyyzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 234); 

                auto tg_yyyyzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 235); 

                auto tg_yyyyzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 236); 

                auto tg_yyyyzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 237); 

                auto tg_yyyyzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 238); 

                auto tg_yyyyzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 239); 

                auto tg_yyyzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 240); 

                auto tg_yyyzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 241); 

                auto tg_yyyzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 242); 

                auto tg_yyyzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 243); 

                auto tg_yyyzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 244); 

                auto tg_yyyzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 245); 

                auto tg_yyyzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 246); 

                auto tg_yyyzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 247); 

                auto tg_yyyzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 248); 

                auto tg_yyyzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 249); 

                auto tg_yyzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 250); 

                auto tg_yyzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 251); 

                auto tg_yyzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 252); 

                auto tg_yyzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 253); 

                auto tg_yyzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 254); 

                auto tg_yyzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 255); 

                auto tg_yyzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 256); 

                auto tg_yyzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 257); 

                auto tg_yyzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 258); 

                auto tg_yyzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 259); 

                auto tg_yzzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 260); 

                auto tg_yzzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 261); 

                auto tg_yzzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 262); 

                auto tg_yzzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 263); 

                auto tg_yzzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 264); 

                auto tg_yzzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 265); 

                auto tg_yzzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 266); 

                auto tg_yzzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 267); 

                auto tg_yzzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 268); 

                auto tg_yzzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 269); 

                auto tg_zzzzzz_xxx_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 270); 

                auto tg_zzzzzz_xxy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 271); 

                auto tg_zzzzzz_xxz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 272); 

                auto tg_zzzzzz_xyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 273); 

                auto tg_zzzzzz_xyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 274); 

                auto tg_zzzzzz_xzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 275); 

                auto tg_zzzzzz_yyy_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 276); 

                auto tg_zzzzzz_yyz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 277); 

                auto tg_zzzzzz_yzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 278); 

                auto tg_zzzzzz_zzz_0 = primBuffer[pidx_g_6_3_m0].data(280 * idx + 279); 

                // Batch of Integrals (187,280)

                #pragma omp simd aligned(fxn, fza, tg_xyyzzz_yyz_0, tg_xyyzzz_yzz_0, tg_xyyzzz_zzz_0, \
                                         tg_xyzzzz_xxx_0, tg_xyzzzz_xxy_0, tg_xyzzzz_xxz_0, tg_xyzzzz_xyy_0, tg_xyzzzz_xyz_0, \
                                         tg_xyzzzz_xzz_0, tg_xyzzzz_yyy_0, tg_xyzzzz_yyz_0, tg_xyzzzz_yzz_0, tg_xyzzzz_zzz_0, \
                                         tg_xzzzzz_xxx_0, tg_xzzzzz_xxy_0, tg_xzzzzz_xxz_0, tg_xzzzzz_xyy_0, tg_xzzzzz_xyz_0, \
                                         tg_xzzzzz_xzz_0, tg_xzzzzz_yyy_0, tg_xzzzzz_yyz_0, tg_xzzzzz_yzz_0, tg_xzzzzz_zzz_0, \
                                         tg_yyyy_xxx_0, tg_yyyy_xxx_1, tg_yyyy_xxy_0, tg_yyyy_xxy_1, tg_yyyy_xxz_0, \
                                         tg_yyyy_xxz_1, tg_yyyy_xyy_0, tg_yyyy_xyy_1, tg_yyyy_xyz_0, tg_yyyy_xyz_1, \
                                         tg_yyyy_xzz_0, tg_yyyy_xzz_1, tg_yyyy_yyy_0, tg_yyyy_yyy_1, tg_yyyy_yyz_0, \
                                         tg_yyyy_yyz_1, tg_yyyy_yzz_0, tg_yyyy_yzz_1, tg_yyyy_zzz_0, tg_yyyy_zzz_1, \
                                         tg_yyyyy_xx_1, tg_yyyyy_xxx_0, tg_yyyyy_xxx_1, tg_yyyyy_xxy_0, tg_yyyyy_xxy_1, \
                                         tg_yyyyy_xxz_0, tg_yyyyy_xxz_1, tg_yyyyy_xy_1, tg_yyyyy_xyy_0, tg_yyyyy_xyy_1, \
                                         tg_yyyyy_xyz_0, tg_yyyyy_xyz_1, tg_yyyyy_xz_1, tg_yyyyy_xzz_0, tg_yyyyy_xzz_1, \
                                         tg_yyyyy_yy_1, tg_yyyyy_yyy_0, tg_yyyyy_yyy_1, tg_yyyyy_yyz_0, tg_yyyyy_yyz_1, \
                                         tg_yyyyy_yz_1, tg_yyyyy_yzz_0, tg_yyyyy_yzz_1, tg_yyyyy_zz_1, tg_yyyyy_zzz_0, \
                                         tg_yyyyy_zzz_1, tg_yyyyyy_xxx_0, tg_yyyyyy_xxy_0, tg_yyyyyy_xxz_0, tg_yyyyyy_xyy_0, \
                                         tg_yyyyyy_xyz_0, tg_yyyyyy_xzz_0, tg_yyyyyy_yyy_0, tg_yyyyyy_yyz_0, tg_yyyyyy_yzz_0, \
                                         tg_yyyyyy_zzz_0, tg_yyyyyz_xxx_0, tg_yyyyyz_xxy_0, tg_yyyyyz_xxz_0, tg_yyyyyz_xyy_0, \
                                         tg_yyyyyz_xyz_0, tg_yyyyyz_xzz_0, tg_yyyyyz_yyy_0, tg_yyyyyz_yyz_0, tg_yyyyyz_yzz_0, \
                                         tg_yyyyyz_zzz_0, tg_yyyyz_xx_1, tg_yyyyz_xxx_0, tg_yyyyz_xxx_1, tg_yyyyz_xxy_0, \
                                         tg_yyyyz_xxy_1, tg_yyyyz_xxz_0, tg_yyyyz_xxz_1, tg_yyyyz_xy_1, tg_yyyyz_xyy_0, \
                                         tg_yyyyz_xyy_1, tg_yyyyz_xyz_0, tg_yyyyz_xyz_1, tg_yyyyz_xz_1, tg_yyyyz_xzz_0, \
                                         tg_yyyyz_xzz_1, tg_yyyyz_yy_1, tg_yyyyz_yyy_0, tg_yyyyz_yyy_1, tg_yyyyz_yyz_0, \
                                         tg_yyyyz_yyz_1, tg_yyyyz_yz_1, tg_yyyyz_yzz_0, tg_yyyyz_yzz_1, tg_yyyyz_zz_1, \
                                         tg_yyyyz_zzz_0, tg_yyyyz_zzz_1, tg_yyyyzz_xxx_0, tg_yyyyzz_xxy_0, tg_yyyyzz_xxz_0, \
                                         tg_yyyyzz_xyy_0, tg_yyyyzz_xyz_0, tg_yyyyzz_xzz_0, tg_yyyyzz_yyy_0, tg_yyyyzz_yyz_0, \
                                         tg_yyyyzz_yzz_0, tg_yyyyzz_zzz_0, tg_yyyz_xxx_0, tg_yyyz_xxx_1, tg_yyyz_xxy_0, \
                                         tg_yyyz_xxy_1, tg_yyyz_xxz_0, tg_yyyz_xxz_1, tg_yyyz_xyy_0, tg_yyyz_xyy_1, \
                                         tg_yyyz_xyz_0, tg_yyyz_xyz_1, tg_yyyz_xzz_0, tg_yyyz_xzz_1, tg_yyyz_yyy_0, \
                                         tg_yyyz_yyy_1, tg_yyyz_yyz_0, tg_yyyz_yyz_1, tg_yyyz_yzz_0, tg_yyyz_yzz_1, \
                                         tg_yyyz_zzz_0, tg_yyyz_zzz_1, tg_yyyzz_xx_1, tg_yyyzz_xxx_0, tg_yyyzz_xxx_1, \
                                         tg_yyyzz_xxy_0, tg_yyyzz_xxy_1, tg_yyyzz_xxz_0, tg_yyyzz_xxz_1, tg_yyyzz_xy_1, \
                                         tg_yyyzz_xyy_0, tg_yyyzz_xyy_1, tg_yyyzz_xyz_0, tg_yyyzz_xyz_1, tg_yyyzz_xz_1, \
                                         tg_yyyzz_xzz_0, tg_yyyzz_xzz_1, tg_yyyzz_yy_1, tg_yyyzz_yyy_0, tg_yyyzz_yyy_1, \
                                         tg_yyyzz_yyz_0, tg_yyyzz_yyz_1, tg_yyyzz_yz_1, tg_yyyzz_yzz_0, tg_yyyzz_yzz_1, \
                                         tg_yyyzz_zz_1, tg_yyyzz_zzz_0, tg_yyyzz_zzz_1, tg_yyyzzz_xxx_0, tg_yyyzzz_xxy_0, \
                                         tg_yyyzzz_xxz_0, tg_yyyzzz_xyy_0, tg_yyyzzz_xyz_0, tg_yyyzzz_xzz_0, tg_yyyzzz_yyy_0, \
                                         tg_yyyzzz_yyz_0, tg_yyyzzz_yzz_0, tg_yyyzzz_zzz_0, tg_yyzz_xxx_0, tg_yyzz_xxx_1, \
                                         tg_yyzz_xxy_0, tg_yyzz_xxy_1, tg_yyzz_xxz_0, tg_yyzz_xxz_1, tg_yyzz_xyy_0, \
                                         tg_yyzz_xyy_1, tg_yyzz_xyz_0, tg_yyzz_xyz_1, tg_yyzz_xzz_0, tg_yyzz_xzz_1, \
                                         tg_yyzz_yyy_0, tg_yyzz_yyy_1, tg_yyzz_yyz_0, tg_yyzz_yyz_1, tg_yyzz_yzz_0, \
                                         tg_yyzz_yzz_1, tg_yyzz_zzz_0, tg_yyzz_zzz_1, tg_yyzzz_xx_1, tg_yyzzz_xxx_0, \
                                         tg_yyzzz_xxx_1, tg_yyzzz_xxy_0, tg_yyzzz_xxy_1, tg_yyzzz_xxz_0, tg_yyzzz_xxz_1, \
                                         tg_yyzzz_xy_1, tg_yyzzz_xyy_0, tg_yyzzz_xyy_1, tg_yyzzz_xyz_0, tg_yyzzz_xyz_1, \
                                         tg_yyzzz_xz_1, tg_yyzzz_xzz_0, tg_yyzzz_xzz_1, tg_yyzzz_yy_1, tg_yyzzz_yyy_0, \
                                         tg_yyzzz_yyy_1, tg_yyzzz_yyz_0, tg_yyzzz_yyz_1, tg_yyzzz_yz_1, tg_yyzzz_yzz_0, \
                                         tg_yyzzz_yzz_1, tg_yyzzz_zz_1, tg_yyzzz_zzz_0, tg_yyzzz_zzz_1, tg_yyzzzz_xxx_0, \
                                         tg_yyzzzz_xxy_0, tg_yyzzzz_xxz_0, tg_yyzzzz_xyy_0, tg_yyzzzz_xyz_0, tg_yyzzzz_xzz_0, \
                                         tg_yyzzzz_yyy_0, tg_yyzzzz_yyz_0, tg_yyzzzz_yzz_0, tg_yyzzzz_zzz_0, tg_yzzz_xxx_0, \
                                         tg_yzzz_xxx_1, tg_yzzz_xxy_0, tg_yzzz_xxy_1, tg_yzzz_xxz_0, tg_yzzz_xxz_1, \
                                         tg_yzzz_xyy_0, tg_yzzz_xyy_1, tg_yzzz_xyz_0, tg_yzzz_xyz_1, tg_yzzz_xzz_0, \
                                         tg_yzzz_xzz_1, tg_yzzz_yyy_0, tg_yzzz_yyy_1, tg_yzzz_yyz_0, tg_yzzz_yyz_1, \
                                         tg_yzzz_yzz_0, tg_yzzz_yzz_1, tg_yzzz_zzz_0, tg_yzzz_zzz_1, tg_yzzzz_xx_1, \
                                         tg_yzzzz_xxx_0, tg_yzzzz_xxx_1, tg_yzzzz_xxy_0, tg_yzzzz_xxy_1, tg_yzzzz_xxz_0, \
                                         tg_yzzzz_xxz_1, tg_yzzzz_xy_1, tg_yzzzz_xyy_0, tg_yzzzz_xyy_1, tg_yzzzz_xyz_0, \
                                         tg_yzzzz_xyz_1, tg_yzzzz_xz_1, tg_yzzzz_xzz_0, tg_yzzzz_xzz_1, tg_yzzzz_yy_1, \
                                         tg_yzzzz_yyy_0, tg_yzzzz_yyy_1, tg_yzzzz_yyz_0, tg_yzzzz_yyz_1, tg_yzzzz_yz_1, \
                                         tg_yzzzz_yzz_0, tg_yzzzz_yzz_1, tg_yzzzz_zz_1, tg_yzzzz_zzz_0, tg_yzzzz_zzz_1, \
                                         tg_yzzzzz_xxx_0, tg_yzzzzz_xxy_0, tg_yzzzzz_xxz_0, tg_yzzzzz_xyy_0, tg_yzzzzz_xyz_0, \
                                         tg_yzzzzz_xzz_0, tg_yzzzzz_yyy_0, tg_yzzzzz_yyz_0, tg_yzzzzz_yzz_0, tg_yzzzzz_zzz_0, \
                                         tg_zzzz_xxx_0, tg_zzzz_xxx_1, tg_zzzz_xxy_0, tg_zzzz_xxy_1, tg_zzzz_xxz_0, \
                                         tg_zzzz_xxz_1, tg_zzzz_xyy_0, tg_zzzz_xyy_1, tg_zzzz_xyz_0, tg_zzzz_xyz_1, \
                                         tg_zzzz_xzz_0, tg_zzzz_xzz_1, tg_zzzz_yyy_0, tg_zzzz_yyy_1, tg_zzzz_yyz_0, \
                                         tg_zzzz_yyz_1, tg_zzzz_yzz_0, tg_zzzz_yzz_1, tg_zzzz_zzz_0, tg_zzzz_zzz_1, \
                                         tg_zzzzz_xx_1, tg_zzzzz_xxx_0, tg_zzzzz_xxx_1, tg_zzzzz_xxy_0, tg_zzzzz_xxy_1, \
                                         tg_zzzzz_xxz_0, tg_zzzzz_xxz_1, tg_zzzzz_xy_1, tg_zzzzz_xyy_0, tg_zzzzz_xyy_1, \
                                         tg_zzzzz_xyz_0, tg_zzzzz_xyz_1, tg_zzzzz_xz_1, tg_zzzzz_xzz_0, tg_zzzzz_xzz_1, \
                                         tg_zzzzz_yy_1, tg_zzzzz_yyy_0, tg_zzzzz_yyy_1, tg_zzzzz_yyz_0, tg_zzzzz_yyz_1, \
                                         tg_zzzzz_yz_1, tg_zzzzz_yzz_0, tg_zzzzz_yzz_1, tg_zzzzz_zz_1, tg_zzzzz_zzz_0, \
                                         tg_zzzzz_zzz_1, tg_zzzzzz_xxx_0, tg_zzzzzz_xxy_0, tg_zzzzzz_xxz_0, tg_zzzzzz_xyy_0, \
                                         tg_zzzzzz_xyz_0, tg_zzzzzz_xzz_0, tg_zzzzzz_yyy_0, tg_zzzzzz_yyz_0, tg_zzzzzz_yzz_0, \
                                         tg_zzzzzz_zzz_0, wp_x, wp_y, wp_z: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xyyzzz_yyz_0[j] = pb_x * tg_yyzzz_yyz_0[j] + fr * tg_yyzzz_yyz_1[j];

                    tg_xyyzzz_yzz_0[j] = pb_x * tg_yyzzz_yzz_0[j] + fr * tg_yyzzz_yzz_1[j];

                    tg_xyyzzz_zzz_0[j] = pb_x * tg_yyzzz_zzz_0[j] + fr * tg_yyzzz_zzz_1[j];

                    tg_xyzzzz_xxx_0[j] = pb_x * tg_yzzzz_xxx_0[j] + fr * tg_yzzzz_xxx_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xx_1[j];

                    tg_xyzzzz_xxy_0[j] = pb_x * tg_yzzzz_xxy_0[j] + fr * tg_yzzzz_xxy_1[j] + fl1_fxn * tg_yzzzz_xy_1[j];

                    tg_xyzzzz_xxz_0[j] = pb_x * tg_yzzzz_xxz_0[j] + fr * tg_yzzzz_xxz_1[j] + fl1_fxn * tg_yzzzz_xz_1[j];

                    tg_xyzzzz_xyy_0[j] = pb_x * tg_yzzzz_xyy_0[j] + fr * tg_yzzzz_xyy_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yy_1[j];

                    tg_xyzzzz_xyz_0[j] = pb_x * tg_yzzzz_xyz_0[j] + fr * tg_yzzzz_xyz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yz_1[j];

                    tg_xyzzzz_xzz_0[j] = pb_x * tg_yzzzz_xzz_0[j] + fr * tg_yzzzz_xzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_zz_1[j];

                    tg_xyzzzz_yyy_0[j] = pb_x * tg_yzzzz_yyy_0[j] + fr * tg_yzzzz_yyy_1[j];

                    tg_xyzzzz_yyz_0[j] = pb_x * tg_yzzzz_yyz_0[j] + fr * tg_yzzzz_yyz_1[j];

                    tg_xyzzzz_yzz_0[j] = pb_x * tg_yzzzz_yzz_0[j] + fr * tg_yzzzz_yzz_1[j];

                    tg_xyzzzz_zzz_0[j] = pb_x * tg_yzzzz_zzz_0[j] + fr * tg_yzzzz_zzz_1[j];

                    tg_xzzzzz_xxx_0[j] = pb_x * tg_zzzzz_xxx_0[j] + fr * tg_zzzzz_xxx_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xx_1[j];

                    tg_xzzzzz_xxy_0[j] = pb_x * tg_zzzzz_xxy_0[j] + fr * tg_zzzzz_xxy_1[j] + fl1_fxn * tg_zzzzz_xy_1[j];

                    tg_xzzzzz_xxz_0[j] = pb_x * tg_zzzzz_xxz_0[j] + fr * tg_zzzzz_xxz_1[j] + fl1_fxn * tg_zzzzz_xz_1[j];

                    tg_xzzzzz_xyy_0[j] = pb_x * tg_zzzzz_xyy_0[j] + fr * tg_zzzzz_xyy_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yy_1[j];

                    tg_xzzzzz_xyz_0[j] = pb_x * tg_zzzzz_xyz_0[j] + fr * tg_zzzzz_xyz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yz_1[j];

                    tg_xzzzzz_xzz_0[j] = pb_x * tg_zzzzz_xzz_0[j] + fr * tg_zzzzz_xzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_zz_1[j];

                    tg_xzzzzz_yyy_0[j] = pb_x * tg_zzzzz_yyy_0[j] + fr * tg_zzzzz_yyy_1[j];

                    tg_xzzzzz_yyz_0[j] = pb_x * tg_zzzzz_yyz_0[j] + fr * tg_zzzzz_yyz_1[j];

                    tg_xzzzzz_yzz_0[j] = pb_x * tg_zzzzz_yzz_0[j] + fr * tg_zzzzz_yzz_1[j];

                    tg_xzzzzz_zzz_0[j] = pb_x * tg_zzzzz_zzz_0[j] + fr * tg_zzzzz_zzz_1[j];

                    fr = wp_y[j]; 

                    tg_yyyyyy_xxx_0[j] = pb_y * tg_yyyyy_xxx_0[j] + fr * tg_yyyyy_xxx_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxx_0[j] - tg_yyyy_xxx_1[j] * fl1_fza);

                    tg_yyyyyy_xxy_0[j] = pb_y * tg_yyyyy_xxy_0[j] + fr * tg_yyyyy_xxy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxy_0[j] - tg_yyyy_xxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xx_1[j];

                    tg_yyyyyy_xxz_0[j] = pb_y * tg_yyyyy_xxz_0[j] + fr * tg_yyyyy_xxz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxz_0[j] - tg_yyyy_xxz_1[j] * fl1_fza);

                    tg_yyyyyy_xyy_0[j] = pb_y * tg_yyyyy_xyy_0[j] + fr * tg_yyyyy_xyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyy_0[j] - tg_yyyy_xyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xy_1[j];

                    tg_yyyyyy_xyz_0[j] = pb_y * tg_yyyyy_xyz_0[j] + fr * tg_yyyyy_xyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyz_0[j] - tg_yyyy_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xz_1[j];

                    tg_yyyyyy_xzz_0[j] = pb_y * tg_yyyyy_xzz_0[j] + fr * tg_yyyyy_xzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xzz_0[j] - tg_yyyy_xzz_1[j] * fl1_fza);

                    tg_yyyyyy_yyy_0[j] = pb_y * tg_yyyyy_yyy_0[j] + fr * tg_yyyyy_yyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyy_0[j] - tg_yyyy_yyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_yy_1[j];

                    tg_yyyyyy_yyz_0[j] = pb_y * tg_yyyyy_yyz_0[j] + fr * tg_yyyyy_yyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyz_0[j] - tg_yyyy_yyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_yz_1[j];

                    tg_yyyyyy_yzz_0[j] = pb_y * tg_yyyyy_yzz_0[j] + fr * tg_yyyyy_yzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yzz_0[j] - tg_yyyy_yzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_zz_1[j];

                    tg_yyyyyy_zzz_0[j] = pb_y * tg_yyyyy_zzz_0[j] + fr * tg_yyyyy_zzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_zzz_0[j] - tg_yyyy_zzz_1[j] * fl1_fza);

                    tg_yyyyyz_xxx_0[j] = pb_y * tg_yyyyz_xxx_0[j] + fr * tg_yyyyz_xxx_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxx_0[j] - tg_yyyz_xxx_1[j] * fl1_fza);

                    tg_yyyyyz_xxy_0[j] = pb_y * tg_yyyyz_xxy_0[j] + fr * tg_yyyyz_xxy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxy_0[j] - tg_yyyz_xxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xx_1[j];

                    tg_yyyyyz_xxz_0[j] = pb_y * tg_yyyyz_xxz_0[j] + fr * tg_yyyyz_xxz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxz_0[j] - tg_yyyz_xxz_1[j] * fl1_fza);

                    tg_yyyyyz_xyy_0[j] = pb_y * tg_yyyyz_xyy_0[j] + fr * tg_yyyyz_xyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyy_0[j] - tg_yyyz_xyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xy_1[j];

                    tg_yyyyyz_xyz_0[j] = pb_y * tg_yyyyz_xyz_0[j] + fr * tg_yyyyz_xyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyz_0[j] - tg_yyyz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xz_1[j];

                    tg_yyyyyz_xzz_0[j] = pb_y * tg_yyyyz_xzz_0[j] + fr * tg_yyyyz_xzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xzz_0[j] - tg_yyyz_xzz_1[j] * fl1_fza);

                    tg_yyyyyz_yyy_0[j] = pb_y * tg_yyyyz_yyy_0[j] + fr * tg_yyyyz_yyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyy_0[j] - tg_yyyz_yyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_yy_1[j];

                    tg_yyyyyz_yyz_0[j] = pb_y * tg_yyyyz_yyz_0[j] + fr * tg_yyyyz_yyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyz_0[j] - tg_yyyz_yyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_yz_1[j];

                    tg_yyyyyz_yzz_0[j] = pb_y * tg_yyyyz_yzz_0[j] + fr * tg_yyyyz_yzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yzz_0[j] - tg_yyyz_yzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_zz_1[j];

                    tg_yyyyyz_zzz_0[j] = pb_y * tg_yyyyz_zzz_0[j] + fr * tg_yyyyz_zzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_zzz_0[j] - tg_yyyz_zzz_1[j] * fl1_fza);

                    tg_yyyyzz_xxx_0[j] = pb_y * tg_yyyzz_xxx_0[j] + fr * tg_yyyzz_xxx_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxx_0[j] - tg_yyzz_xxx_1[j] * fl1_fza);

                    tg_yyyyzz_xxy_0[j] = pb_y * tg_yyyzz_xxy_0[j] + fr * tg_yyyzz_xxy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxy_0[j] - tg_yyzz_xxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xx_1[j];

                    tg_yyyyzz_xxz_0[j] = pb_y * tg_yyyzz_xxz_0[j] + fr * tg_yyyzz_xxz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxz_0[j] - tg_yyzz_xxz_1[j] * fl1_fza);

                    tg_yyyyzz_xyy_0[j] = pb_y * tg_yyyzz_xyy_0[j] + fr * tg_yyyzz_xyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyy_0[j] - tg_yyzz_xyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xy_1[j];

                    tg_yyyyzz_xyz_0[j] = pb_y * tg_yyyzz_xyz_0[j] + fr * tg_yyyzz_xyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyz_0[j] - tg_yyzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xz_1[j];

                    tg_yyyyzz_xzz_0[j] = pb_y * tg_yyyzz_xzz_0[j] + fr * tg_yyyzz_xzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xzz_0[j] - tg_yyzz_xzz_1[j] * fl1_fza);

                    tg_yyyyzz_yyy_0[j] = pb_y * tg_yyyzz_yyy_0[j] + fr * tg_yyyzz_yyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyy_0[j] - tg_yyzz_yyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_yy_1[j];

                    tg_yyyyzz_yyz_0[j] = pb_y * tg_yyyzz_yyz_0[j] + fr * tg_yyyzz_yyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyz_0[j] - tg_yyzz_yyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_yz_1[j];

                    tg_yyyyzz_yzz_0[j] = pb_y * tg_yyyzz_yzz_0[j] + fr * tg_yyyzz_yzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yzz_0[j] - tg_yyzz_yzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_zz_1[j];

                    tg_yyyyzz_zzz_0[j] = pb_y * tg_yyyzz_zzz_0[j] + fr * tg_yyyzz_zzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_zzz_0[j] - tg_yyzz_zzz_1[j] * fl1_fza);

                    tg_yyyzzz_xxx_0[j] = pb_y * tg_yyzzz_xxx_0[j] + fr * tg_yyzzz_xxx_1[j] + fl1_fx * (tg_yzzz_xxx_0[j] - tg_yzzz_xxx_1[j] * fl1_fza);

                    tg_yyyzzz_xxy_0[j] = pb_y * tg_yyzzz_xxy_0[j] + fr * tg_yyzzz_xxy_1[j] + fl1_fx * (tg_yzzz_xxy_0[j] - tg_yzzz_xxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xx_1[j];

                    tg_yyyzzz_xxz_0[j] = pb_y * tg_yyzzz_xxz_0[j] + fr * tg_yyzzz_xxz_1[j] + fl1_fx * (tg_yzzz_xxz_0[j] - tg_yzzz_xxz_1[j] * fl1_fza);

                    tg_yyyzzz_xyy_0[j] = pb_y * tg_yyzzz_xyy_0[j] + fr * tg_yyzzz_xyy_1[j] + fl1_fx * (tg_yzzz_xyy_0[j] - tg_yzzz_xyy_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xy_1[j];

                    tg_yyyzzz_xyz_0[j] = pb_y * tg_yyzzz_xyz_0[j] + fr * tg_yyzzz_xyz_1[j] + fl1_fx * (tg_yzzz_xyz_0[j] - tg_yzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xz_1[j];

                    tg_yyyzzz_xzz_0[j] = pb_y * tg_yyzzz_xzz_0[j] + fr * tg_yyzzz_xzz_1[j] + fl1_fx * (tg_yzzz_xzz_0[j] - tg_yzzz_xzz_1[j] * fl1_fza);

                    tg_yyyzzz_yyy_0[j] = pb_y * tg_yyzzz_yyy_0[j] + fr * tg_yyzzz_yyy_1[j] + fl1_fx * (tg_yzzz_yyy_0[j] - tg_yzzz_yyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_yy_1[j];

                    tg_yyyzzz_yyz_0[j] = pb_y * tg_yyzzz_yyz_0[j] + fr * tg_yyzzz_yyz_1[j] + fl1_fx * (tg_yzzz_yyz_0[j] - tg_yzzz_yyz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_yz_1[j];

                    tg_yyyzzz_yzz_0[j] = pb_y * tg_yyzzz_yzz_0[j] + fr * tg_yyzzz_yzz_1[j] + fl1_fx * (tg_yzzz_yzz_0[j] - tg_yzzz_yzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_zz_1[j];

                    tg_yyyzzz_zzz_0[j] = pb_y * tg_yyzzz_zzz_0[j] + fr * tg_yyzzz_zzz_1[j] + fl1_fx * (tg_yzzz_zzz_0[j] - tg_yzzz_zzz_1[j] * fl1_fza);

                    tg_yyzzzz_xxx_0[j] = pb_y * tg_yzzzz_xxx_0[j] + fr * tg_yzzzz_xxx_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxx_0[j] - tg_zzzz_xxx_1[j] * fl1_fza);

                    tg_yyzzzz_xxy_0[j] = pb_y * tg_yzzzz_xxy_0[j] + fr * tg_yzzzz_xxy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxy_0[j] - tg_zzzz_xxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xx_1[j];

                    tg_yyzzzz_xxz_0[j] = pb_y * tg_yzzzz_xxz_0[j] + fr * tg_yzzzz_xxz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxz_0[j] - tg_zzzz_xxz_1[j] * fl1_fza);

                    tg_yyzzzz_xyy_0[j] = pb_y * tg_yzzzz_xyy_0[j] + fr * tg_yzzzz_xyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyy_0[j] - tg_zzzz_xyy_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xy_1[j];

                    tg_yyzzzz_xyz_0[j] = pb_y * tg_yzzzz_xyz_0[j] + fr * tg_yzzzz_xyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyz_0[j] - tg_zzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xz_1[j];

                    tg_yyzzzz_xzz_0[j] = pb_y * tg_yzzzz_xzz_0[j] + fr * tg_yzzzz_xzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xzz_0[j] - tg_zzzz_xzz_1[j] * fl1_fza);

                    tg_yyzzzz_yyy_0[j] = pb_y * tg_yzzzz_yyy_0[j] + fr * tg_yzzzz_yyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyy_0[j] - tg_zzzz_yyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_yy_1[j];

                    tg_yyzzzz_yyz_0[j] = pb_y * tg_yzzzz_yyz_0[j] + fr * tg_yzzzz_yyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyz_0[j] - tg_zzzz_yyz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_yz_1[j];

                    tg_yyzzzz_yzz_0[j] = pb_y * tg_yzzzz_yzz_0[j] + fr * tg_yzzzz_yzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yzz_0[j] - tg_zzzz_yzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_zz_1[j];

                    tg_yyzzzz_zzz_0[j] = pb_y * tg_yzzzz_zzz_0[j] + fr * tg_yzzzz_zzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_zzz_0[j] - tg_zzzz_zzz_1[j] * fl1_fza);

                    tg_yzzzzz_xxx_0[j] = pb_y * tg_zzzzz_xxx_0[j] + fr * tg_zzzzz_xxx_1[j];

                    tg_yzzzzz_xxy_0[j] = pb_y * tg_zzzzz_xxy_0[j] + fr * tg_zzzzz_xxy_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xx_1[j];

                    tg_yzzzzz_xxz_0[j] = pb_y * tg_zzzzz_xxz_0[j] + fr * tg_zzzzz_xxz_1[j];

                    tg_yzzzzz_xyy_0[j] = pb_y * tg_zzzzz_xyy_0[j] + fr * tg_zzzzz_xyy_1[j] + fl1_fxn * tg_zzzzz_xy_1[j];

                    tg_yzzzzz_xyz_0[j] = pb_y * tg_zzzzz_xyz_0[j] + fr * tg_zzzzz_xyz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xz_1[j];

                    tg_yzzzzz_xzz_0[j] = pb_y * tg_zzzzz_xzz_0[j] + fr * tg_zzzzz_xzz_1[j];

                    tg_yzzzzz_yyy_0[j] = pb_y * tg_zzzzz_yyy_0[j] + fr * tg_zzzzz_yyy_1[j] + 1.5 * fl1_fxn * tg_zzzzz_yy_1[j];

                    tg_yzzzzz_yyz_0[j] = pb_y * tg_zzzzz_yyz_0[j] + fr * tg_zzzzz_yyz_1[j] + fl1_fxn * tg_zzzzz_yz_1[j];

                    tg_yzzzzz_yzz_0[j] = pb_y * tg_zzzzz_yzz_0[j] + fr * tg_zzzzz_yzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_zz_1[j];

                    tg_yzzzzz_zzz_0[j] = pb_y * tg_zzzzz_zzz_0[j] + fr * tg_zzzzz_zzz_1[j];

                    fr = wp_z[j]; 

                    tg_zzzzzz_xxx_0[j] = pb_z * tg_zzzzz_xxx_0[j] + fr * tg_zzzzz_xxx_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxx_0[j] - tg_zzzz_xxx_1[j] * fl1_fza);

                    tg_zzzzzz_xxy_0[j] = pb_z * tg_zzzzz_xxy_0[j] + fr * tg_zzzzz_xxy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxy_0[j] - tg_zzzz_xxy_1[j] * fl1_fza);

                    tg_zzzzzz_xxz_0[j] = pb_z * tg_zzzzz_xxz_0[j] + fr * tg_zzzzz_xxz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxz_0[j] - tg_zzzz_xxz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xx_1[j];

                    tg_zzzzzz_xyy_0[j] = pb_z * tg_zzzzz_xyy_0[j] + fr * tg_zzzzz_xyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyy_0[j] - tg_zzzz_xyy_1[j] * fl1_fza);

                    tg_zzzzzz_xyz_0[j] = pb_z * tg_zzzzz_xyz_0[j] + fr * tg_zzzzz_xyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyz_0[j] - tg_zzzz_xyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xy_1[j];

                    tg_zzzzzz_xzz_0[j] = pb_z * tg_zzzzz_xzz_0[j] + fr * tg_zzzzz_xzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xzz_0[j] - tg_zzzz_xzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xz_1[j];

                    tg_zzzzzz_yyy_0[j] = pb_z * tg_zzzzz_yyy_0[j] + fr * tg_zzzzz_yyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyy_0[j] - tg_zzzz_yyy_1[j] * fl1_fza);

                    tg_zzzzzz_yyz_0[j] = pb_z * tg_zzzzz_yyz_0[j] + fr * tg_zzzzz_yyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyz_0[j] - tg_zzzz_yyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_yy_1[j];

                    tg_zzzzzz_yzz_0[j] = pb_z * tg_zzzzz_yzz_0[j] + fr * tg_zzzzz_yzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yzz_0[j] - tg_zzzz_yzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_yz_1[j];

                    tg_zzzzzz_zzz_0[j] = pb_z * tg_zzzzz_zzz_0[j] + fr * tg_zzzzz_zzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_zzz_0[j] - tg_zzzz_zzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_zz_1[j];
                }

                idx++;
            }
        }
    }


} // erirecfunc namespace

