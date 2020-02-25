//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "ElectronRepulsionRecFuncForIK.hpp"

namespace erirecfunc { // erirecfunc namespace

    void
    compElectronRepulsionForSISK(      CMemBlock2D<double>* primBuffer,
                                 const CRecursionMap&       recursionMap,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& wpDistances,
                                 const CGtoPairsBlock&      braGtoPairsBlock,
                                 const CGtoPairsBlock&      ketGtoPairsBlock,
                                 const int32_t              nKetPrimPairs,
                                 const int32_t              iContrPair)
    {
        erirecfunc::compElectronRepulsionForSISK_0_92(primBuffer,
                                                      recursionMap,
                                                      osFactors,
                                                      wpDistances, 
                                                      braGtoPairsBlock,
                                                      ketGtoPairsBlock,
                                                      nKetPrimPairs,
                                                      iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_92_184(primBuffer,
                                                        recursionMap,
                                                        osFactors,
                                                        wpDistances, 
                                                        braGtoPairsBlock,
                                                        ketGtoPairsBlock,
                                                        nKetPrimPairs,
                                                        iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_184_276(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_276_368(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_368_460(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_460_552(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_552_644(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_644_735(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_735_826(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_826_917(primBuffer,
                                                         recursionMap,
                                                         osFactors,
                                                         wpDistances, 
                                                         braGtoPairsBlock,
                                                         ketGtoPairsBlock,
                                                         nKetPrimPairs,
                                                         iContrPair); 

        erirecfunc::compElectronRepulsionForSISK_917_1008(primBuffer,
                                                          recursionMap,
                                                          osFactors,
                                                          wpDistances, 
                                                          braGtoPairsBlock,
                                                          ketGtoPairsBlock,
                                                          nKetPrimPairs,
                                                          iContrPair); 
    }

    void
    compElectronRepulsionForSISK_0_92(      CMemBlock2D<double>* primBuffer,
                                      const CRecursionMap&       recursionMap,
                                      const CMemBlock2D<double>& osFactors,
                                      const CMemBlock2D<double>& wpDistances,
                                      const CGtoPairsBlock&      braGtoPairsBlock,
                                      const CGtoPairsBlock&      ketGtoPairsBlock,
                                      const int32_t              nKetPrimPairs,
                                      const int32_t              iContrPair)
    {
        // Batch of Integrals (0,92)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xxxxx_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx); 

                auto tg_xxxxx_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 1); 

                auto tg_xxxxx_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 2); 

                auto tg_xxxxx_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 3); 

                auto tg_xxxxx_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 4); 

                auto tg_xxxxx_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 5); 

                auto tg_xxxxx_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 6); 

                auto tg_xxxxx_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 7); 

                auto tg_xxxxx_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 8); 

                auto tg_xxxxx_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 9); 

                auto tg_xxxxx_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 10); 

                auto tg_xxxxx_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 11); 

                auto tg_xxxxx_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 12); 

                auto tg_xxxxx_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 13); 

                auto tg_xxxxx_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 14); 

                auto tg_xxxxx_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 15); 

                auto tg_xxxxx_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 16); 

                auto tg_xxxxx_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 17); 

                auto tg_xxxxx_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 18); 

                auto tg_xxxxx_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 19); 

                auto tg_xxxxx_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 20); 

                auto tg_xxxxx_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 21); 

                auto tg_xxxxx_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 22); 

                auto tg_xxxxx_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 23); 

                auto tg_xxxxx_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 24); 

                auto tg_xxxxx_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 25); 

                auto tg_xxxxx_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 26); 

                auto tg_xxxxx_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 27); 

                auto tg_xxxxx_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 28); 

                auto tg_xxxxx_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 29); 

                auto tg_xxxxx_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 30); 

                auto tg_xxxxx_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 31); 

                auto tg_xxxxx_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 32); 

                auto tg_xxxxx_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 33); 

                auto tg_xxxxx_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 34); 

                auto tg_xxxxx_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 35); 

                auto tg_xxxxy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 36); 

                auto tg_xxxxy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 37); 

                auto tg_xxxxy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 38); 

                auto tg_xxxxy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 39); 

                auto tg_xxxxy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 40); 

                auto tg_xxxxy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 41); 

                auto tg_xxxxy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 42); 

                auto tg_xxxxy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 43); 

                auto tg_xxxxy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 44); 

                auto tg_xxxxy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 45); 

                auto tg_xxxxy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 46); 

                auto tg_xxxxy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 47); 

                auto tg_xxxxy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 48); 

                auto tg_xxxxy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 49); 

                auto tg_xxxxy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 50); 

                auto tg_xxxxy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 51); 

                auto tg_xxxxy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 52); 

                auto tg_xxxxy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 53); 

                auto tg_xxxxy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 54); 

                auto tg_xxxxy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 55); 

                auto tg_xxxxy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 56); 

                auto tg_xxxxy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 57); 

                auto tg_xxxxy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 58); 

                auto tg_xxxxy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 59); 

                auto tg_xxxxy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 60); 

                auto tg_xxxxy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 61); 

                auto tg_xxxxy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 62); 

                auto tg_xxxxy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 63); 

                auto tg_xxxxy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 64); 

                auto tg_xxxxy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 65); 

                auto tg_xxxxy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 66); 

                auto tg_xxxxy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 67); 

                auto tg_xxxxy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 68); 

                auto tg_xxxxy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 69); 

                auto tg_xxxxy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 70); 

                auto tg_xxxxy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 71); 

                auto tg_xxxxz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 72); 

                auto tg_xxxxz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 73); 

                auto tg_xxxxz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 74); 

                auto tg_xxxxz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 75); 

                auto tg_xxxxz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 76); 

                auto tg_xxxxz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 77); 

                auto tg_xxxxz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 78); 

                auto tg_xxxxz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 79); 

                auto tg_xxxxz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 80); 

                auto tg_xxxxz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 81); 

                auto tg_xxxxz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 82); 

                auto tg_xxxxz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 83); 

                auto tg_xxxxz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 84); 

                auto tg_xxxxz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 85); 

                auto tg_xxxxz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 86); 

                auto tg_xxxxz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 87); 

                auto tg_xxxxz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 88); 

                auto tg_xxxxz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 89); 

                auto tg_xxxxz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 90); 

                auto tg_xxxxz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 91); 

                auto tg_xxxxx_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx); 

                auto tg_xxxxx_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 1); 

                auto tg_xxxxx_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 2); 

                auto tg_xxxxx_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 3); 

                auto tg_xxxxx_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 4); 

                auto tg_xxxxx_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 5); 

                auto tg_xxxxx_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 6); 

                auto tg_xxxxx_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 7); 

                auto tg_xxxxx_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 8); 

                auto tg_xxxxx_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 9); 

                auto tg_xxxxx_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 10); 

                auto tg_xxxxx_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 11); 

                auto tg_xxxxx_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 12); 

                auto tg_xxxxx_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 13); 

                auto tg_xxxxx_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 14); 

                auto tg_xxxxx_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 15); 

                auto tg_xxxxx_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 16); 

                auto tg_xxxxx_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 17); 

                auto tg_xxxxx_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 18); 

                auto tg_xxxxx_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 19); 

                auto tg_xxxxx_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 20); 

                auto tg_xxxxx_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 21); 

                auto tg_xxxxx_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 22); 

                auto tg_xxxxx_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 23); 

                auto tg_xxxxx_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 24); 

                auto tg_xxxxx_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 25); 

                auto tg_xxxxx_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 26); 

                auto tg_xxxxx_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 27); 

                auto tg_xxxxx_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 28); 

                auto tg_xxxxx_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 29); 

                auto tg_xxxxx_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 30); 

                auto tg_xxxxx_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 31); 

                auto tg_xxxxx_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 32); 

                auto tg_xxxxx_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 33); 

                auto tg_xxxxx_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 34); 

                auto tg_xxxxx_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 35); 

                auto tg_xxxxy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 36); 

                auto tg_xxxxy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 37); 

                auto tg_xxxxy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 38); 

                auto tg_xxxxy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 39); 

                auto tg_xxxxy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 40); 

                auto tg_xxxxy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 41); 

                auto tg_xxxxy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 42); 

                auto tg_xxxxy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 43); 

                auto tg_xxxxy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 44); 

                auto tg_xxxxy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 45); 

                auto tg_xxxxy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 46); 

                auto tg_xxxxy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 47); 

                auto tg_xxxxy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 48); 

                auto tg_xxxxy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 49); 

                auto tg_xxxxy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 50); 

                auto tg_xxxxy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 51); 

                auto tg_xxxxy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 52); 

                auto tg_xxxxy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 53); 

                auto tg_xxxxy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 54); 

                auto tg_xxxxy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 55); 

                auto tg_xxxxy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 56); 

                auto tg_xxxxy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 57); 

                auto tg_xxxxy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 58); 

                auto tg_xxxxy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 59); 

                auto tg_xxxxy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 60); 

                auto tg_xxxxy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 61); 

                auto tg_xxxxy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 62); 

                auto tg_xxxxy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 63); 

                auto tg_xxxxy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 64); 

                auto tg_xxxxy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 65); 

                auto tg_xxxxy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 66); 

                auto tg_xxxxy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 67); 

                auto tg_xxxxy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 68); 

                auto tg_xxxxy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 69); 

                auto tg_xxxxy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 70); 

                auto tg_xxxxy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 71); 

                auto tg_xxxxz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 72); 

                auto tg_xxxxz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 73); 

                auto tg_xxxxz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 74); 

                auto tg_xxxxz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 75); 

                auto tg_xxxxz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 76); 

                auto tg_xxxxz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 77); 

                auto tg_xxxxz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 78); 

                auto tg_xxxxz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 79); 

                auto tg_xxxxz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 80); 

                auto tg_xxxxz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 81); 

                auto tg_xxxxz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 82); 

                auto tg_xxxxz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 83); 

                auto tg_xxxxz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 84); 

                auto tg_xxxxz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 85); 

                auto tg_xxxxz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 86); 

                auto tg_xxxxz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 87); 

                auto tg_xxxxz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 88); 

                auto tg_xxxxz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 89); 

                auto tg_xxxxz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 90); 

                auto tg_xxxxz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 91); 

                auto tg_xxxx_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx); 

                auto tg_xxxx_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 1); 

                auto tg_xxxx_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 2); 

                auto tg_xxxx_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 3); 

                auto tg_xxxx_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 4); 

                auto tg_xxxx_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 5); 

                auto tg_xxxx_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 6); 

                auto tg_xxxx_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 7); 

                auto tg_xxxx_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 8); 

                auto tg_xxxx_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 9); 

                auto tg_xxxx_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 10); 

                auto tg_xxxx_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 11); 

                auto tg_xxxx_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 12); 

                auto tg_xxxx_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 13); 

                auto tg_xxxx_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 14); 

                auto tg_xxxx_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 15); 

                auto tg_xxxx_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 16); 

                auto tg_xxxx_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 17); 

                auto tg_xxxx_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 18); 

                auto tg_xxxx_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 19); 

                auto tg_xxxx_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 20); 

                auto tg_xxxx_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 21); 

                auto tg_xxxx_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 22); 

                auto tg_xxxx_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 23); 

                auto tg_xxxx_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 24); 

                auto tg_xxxx_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 25); 

                auto tg_xxxx_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 26); 

                auto tg_xxxx_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 27); 

                auto tg_xxxx_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 28); 

                auto tg_xxxx_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 29); 

                auto tg_xxxx_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 30); 

                auto tg_xxxx_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 31); 

                auto tg_xxxx_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 32); 

                auto tg_xxxx_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 33); 

                auto tg_xxxx_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 34); 

                auto tg_xxxx_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 35); 

                auto tg_xxxy_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 36); 

                auto tg_xxxy_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 37); 

                auto tg_xxxy_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 38); 

                auto tg_xxxy_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 39); 

                auto tg_xxxy_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 40); 

                auto tg_xxxy_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 41); 

                auto tg_xxxy_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 42); 

                auto tg_xxxy_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 43); 

                auto tg_xxxy_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 44); 

                auto tg_xxxy_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 45); 

                auto tg_xxxy_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 46); 

                auto tg_xxxy_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 47); 

                auto tg_xxxy_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 48); 

                auto tg_xxxy_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 49); 

                auto tg_xxxy_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 50); 

                auto tg_xxxy_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 51); 

                auto tg_xxxy_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 52); 

                auto tg_xxxy_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 53); 

                auto tg_xxxy_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 54); 

                auto tg_xxxy_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 55); 

                auto tg_xxxy_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 56); 

                auto tg_xxxy_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 57); 

                auto tg_xxxy_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 58); 

                auto tg_xxxy_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 59); 

                auto tg_xxxy_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 60); 

                auto tg_xxxy_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 61); 

                auto tg_xxxy_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 62); 

                auto tg_xxxy_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 63); 

                auto tg_xxxy_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 64); 

                auto tg_xxxy_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 65); 

                auto tg_xxxy_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 66); 

                auto tg_xxxy_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 67); 

                auto tg_xxxy_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 68); 

                auto tg_xxxy_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 69); 

                auto tg_xxxy_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 70); 

                auto tg_xxxy_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 71); 

                auto tg_xxxz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 72); 

                auto tg_xxxz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 73); 

                auto tg_xxxz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 74); 

                auto tg_xxxz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 75); 

                auto tg_xxxz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 76); 

                auto tg_xxxz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 77); 

                auto tg_xxxz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 78); 

                auto tg_xxxz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 79); 

                auto tg_xxxz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 80); 

                auto tg_xxxz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 81); 

                auto tg_xxxz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 82); 

                auto tg_xxxz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 83); 

                auto tg_xxxz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 84); 

                auto tg_xxxz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 85); 

                auto tg_xxxz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 86); 

                auto tg_xxxz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 87); 

                auto tg_xxxz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 88); 

                auto tg_xxxz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 89); 

                auto tg_xxxz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 90); 

                auto tg_xxxz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 91); 

                auto tg_xxxx_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx); 

                auto tg_xxxx_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 1); 

                auto tg_xxxx_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 2); 

                auto tg_xxxx_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 3); 

                auto tg_xxxx_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 4); 

                auto tg_xxxx_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 5); 

                auto tg_xxxx_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 6); 

                auto tg_xxxx_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 7); 

                auto tg_xxxx_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 8); 

                auto tg_xxxx_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 9); 

                auto tg_xxxx_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 10); 

                auto tg_xxxx_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 11); 

                auto tg_xxxx_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 12); 

                auto tg_xxxx_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 13); 

                auto tg_xxxx_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 14); 

                auto tg_xxxx_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 15); 

                auto tg_xxxx_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 16); 

                auto tg_xxxx_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 17); 

                auto tg_xxxx_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 18); 

                auto tg_xxxx_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 19); 

                auto tg_xxxx_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 20); 

                auto tg_xxxx_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 21); 

                auto tg_xxxx_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 22); 

                auto tg_xxxx_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 23); 

                auto tg_xxxx_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 24); 

                auto tg_xxxx_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 25); 

                auto tg_xxxx_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 26); 

                auto tg_xxxx_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 27); 

                auto tg_xxxx_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 28); 

                auto tg_xxxx_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 29); 

                auto tg_xxxx_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 30); 

                auto tg_xxxx_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 31); 

                auto tg_xxxx_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 32); 

                auto tg_xxxx_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 33); 

                auto tg_xxxx_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 34); 

                auto tg_xxxx_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 35); 

                auto tg_xxxy_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 36); 

                auto tg_xxxy_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 37); 

                auto tg_xxxy_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 38); 

                auto tg_xxxy_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 39); 

                auto tg_xxxy_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 40); 

                auto tg_xxxy_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 41); 

                auto tg_xxxy_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 42); 

                auto tg_xxxy_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 43); 

                auto tg_xxxy_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 44); 

                auto tg_xxxy_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 45); 

                auto tg_xxxy_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 46); 

                auto tg_xxxy_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 47); 

                auto tg_xxxy_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 48); 

                auto tg_xxxy_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 49); 

                auto tg_xxxy_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 50); 

                auto tg_xxxy_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 51); 

                auto tg_xxxy_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 52); 

                auto tg_xxxy_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 53); 

                auto tg_xxxy_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 54); 

                auto tg_xxxy_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 55); 

                auto tg_xxxy_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 56); 

                auto tg_xxxy_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 57); 

                auto tg_xxxy_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 58); 

                auto tg_xxxy_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 59); 

                auto tg_xxxy_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 60); 

                auto tg_xxxy_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 61); 

                auto tg_xxxy_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 62); 

                auto tg_xxxy_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 63); 

                auto tg_xxxy_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 64); 

                auto tg_xxxy_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 65); 

                auto tg_xxxy_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 66); 

                auto tg_xxxy_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 67); 

                auto tg_xxxy_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 68); 

                auto tg_xxxy_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 69); 

                auto tg_xxxy_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 70); 

                auto tg_xxxy_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 71); 

                auto tg_xxxz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 72); 

                auto tg_xxxz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 73); 

                auto tg_xxxz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 74); 

                auto tg_xxxz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 75); 

                auto tg_xxxz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 76); 

                auto tg_xxxz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 77); 

                auto tg_xxxz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 78); 

                auto tg_xxxz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 79); 

                auto tg_xxxz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 80); 

                auto tg_xxxz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 81); 

                auto tg_xxxz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 82); 

                auto tg_xxxz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 83); 

                auto tg_xxxz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 84); 

                auto tg_xxxz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 85); 

                auto tg_xxxz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 86); 

                auto tg_xxxz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 87); 

                auto tg_xxxz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 88); 

                auto tg_xxxz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 89); 

                auto tg_xxxz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 90); 

                auto tg_xxxz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 91); 

                auto tg_xxxxx_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx); 

                auto tg_xxxxx_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 1); 

                auto tg_xxxxx_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 2); 

                auto tg_xxxxx_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 3); 

                auto tg_xxxxx_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 4); 

                auto tg_xxxxx_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 5); 

                auto tg_xxxxx_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 6); 

                auto tg_xxxxx_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 7); 

                auto tg_xxxxx_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 8); 

                auto tg_xxxxx_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 9); 

                auto tg_xxxxx_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 10); 

                auto tg_xxxxx_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 11); 

                auto tg_xxxxx_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 12); 

                auto tg_xxxxx_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 13); 

                auto tg_xxxxx_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 14); 

                auto tg_xxxxx_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 15); 

                auto tg_xxxxx_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 16); 

                auto tg_xxxxx_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 17); 

                auto tg_xxxxx_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 18); 

                auto tg_xxxxx_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 19); 

                auto tg_xxxxx_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 20); 

                auto tg_xxxxx_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 21); 

                auto tg_xxxxx_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 22); 

                auto tg_xxxxx_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 23); 

                auto tg_xxxxx_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 24); 

                auto tg_xxxxx_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 25); 

                auto tg_xxxxx_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 26); 

                auto tg_xxxxx_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 27); 

                auto tg_xxxxy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 28); 

                auto tg_xxxxy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 29); 

                auto tg_xxxxy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 30); 

                auto tg_xxxxy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 31); 

                auto tg_xxxxy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 32); 

                auto tg_xxxxy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 33); 

                auto tg_xxxxy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 34); 

                auto tg_xxxxy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 35); 

                auto tg_xxxxy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 36); 

                auto tg_xxxxy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 37); 

                auto tg_xxxxy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 38); 

                auto tg_xxxxy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 39); 

                auto tg_xxxxy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 40); 

                auto tg_xxxxy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 41); 

                auto tg_xxxxy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 42); 

                auto tg_xxxxy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 43); 

                auto tg_xxxxy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 44); 

                auto tg_xxxxy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 45); 

                auto tg_xxxxy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 46); 

                auto tg_xxxxy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 47); 

                auto tg_xxxxy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 48); 

                auto tg_xxxxy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 49); 

                auto tg_xxxxy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 50); 

                auto tg_xxxxy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 51); 

                auto tg_xxxxy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 52); 

                auto tg_xxxxy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 53); 

                auto tg_xxxxy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 54); 

                auto tg_xxxxy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 55); 

                auto tg_xxxxz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 56); 

                auto tg_xxxxz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 57); 

                auto tg_xxxxz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 58); 

                auto tg_xxxxz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 59); 

                auto tg_xxxxz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 60); 

                auto tg_xxxxz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 61); 

                auto tg_xxxxz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 62); 

                auto tg_xxxxz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 63); 

                auto tg_xxxxz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 64); 

                auto tg_xxxxz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 65); 

                auto tg_xxxxz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 66); 

                auto tg_xxxxz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 67); 

                auto tg_xxxxz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 68); 

                auto tg_xxxxz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 69); 

                auto tg_xxxxz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 70); 

                auto tg_xxxxz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 71); 

                auto tg_xxxxz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 72); 

                auto tg_xxxxz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 73); 

                auto tg_xxxxz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 74); 

                auto tg_xxxxz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 75); 

                // set up pointers to integrals

                auto tg_xxxxxx_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx); 

                auto tg_xxxxxx_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1); 

                auto tg_xxxxxx_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 2); 

                auto tg_xxxxxx_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 3); 

                auto tg_xxxxxx_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 4); 

                auto tg_xxxxxx_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 5); 

                auto tg_xxxxxx_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 6); 

                auto tg_xxxxxx_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 7); 

                auto tg_xxxxxx_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 8); 

                auto tg_xxxxxx_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 9); 

                auto tg_xxxxxx_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 10); 

                auto tg_xxxxxx_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 11); 

                auto tg_xxxxxx_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 12); 

                auto tg_xxxxxx_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 13); 

                auto tg_xxxxxx_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 14); 

                auto tg_xxxxxx_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 15); 

                auto tg_xxxxxx_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 16); 

                auto tg_xxxxxx_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 17); 

                auto tg_xxxxxx_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 18); 

                auto tg_xxxxxx_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 19); 

                auto tg_xxxxxx_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 20); 

                auto tg_xxxxxx_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 21); 

                auto tg_xxxxxx_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 22); 

                auto tg_xxxxxx_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 23); 

                auto tg_xxxxxx_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 24); 

                auto tg_xxxxxx_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 25); 

                auto tg_xxxxxx_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 26); 

                auto tg_xxxxxx_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 27); 

                auto tg_xxxxxx_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 28); 

                auto tg_xxxxxx_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 29); 

                auto tg_xxxxxx_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 30); 

                auto tg_xxxxxx_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 31); 

                auto tg_xxxxxx_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 32); 

                auto tg_xxxxxx_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 33); 

                auto tg_xxxxxx_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 34); 

                auto tg_xxxxxx_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 35); 

                auto tg_xxxxxy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 36); 

                auto tg_xxxxxy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 37); 

                auto tg_xxxxxy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 38); 

                auto tg_xxxxxy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 39); 

                auto tg_xxxxxy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 40); 

                auto tg_xxxxxy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 41); 

                auto tg_xxxxxy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 42); 

                auto tg_xxxxxy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 43); 

                auto tg_xxxxxy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 44); 

                auto tg_xxxxxy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 45); 

                auto tg_xxxxxy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 46); 

                auto tg_xxxxxy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 47); 

                auto tg_xxxxxy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 48); 

                auto tg_xxxxxy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 49); 

                auto tg_xxxxxy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 50); 

                auto tg_xxxxxy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 51); 

                auto tg_xxxxxy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 52); 

                auto tg_xxxxxy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 53); 

                auto tg_xxxxxy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 54); 

                auto tg_xxxxxy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 55); 

                auto tg_xxxxxy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 56); 

                auto tg_xxxxxy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 57); 

                auto tg_xxxxxy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 58); 

                auto tg_xxxxxy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 59); 

                auto tg_xxxxxy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 60); 

                auto tg_xxxxxy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 61); 

                auto tg_xxxxxy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 62); 

                auto tg_xxxxxy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 63); 

                auto tg_xxxxxy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 64); 

                auto tg_xxxxxy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 65); 

                auto tg_xxxxxy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 66); 

                auto tg_xxxxxy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 67); 

                auto tg_xxxxxy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 68); 

                auto tg_xxxxxy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 69); 

                auto tg_xxxxxy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 70); 

                auto tg_xxxxxy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 71); 

                auto tg_xxxxxz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 72); 

                auto tg_xxxxxz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 73); 

                auto tg_xxxxxz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 74); 

                auto tg_xxxxxz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 75); 

                auto tg_xxxxxz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 76); 

                auto tg_xxxxxz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 77); 

                auto tg_xxxxxz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 78); 

                auto tg_xxxxxz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 79); 

                auto tg_xxxxxz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 80); 

                auto tg_xxxxxz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 81); 

                auto tg_xxxxxz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 82); 

                auto tg_xxxxxz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 83); 

                auto tg_xxxxxz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 84); 

                auto tg_xxxxxz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 85); 

                auto tg_xxxxxz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 86); 

                auto tg_xxxxxz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 87); 

                auto tg_xxxxxz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 88); 

                auto tg_xxxxxz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 89); 

                auto tg_xxxxxz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 90); 

                auto tg_xxxxxz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 91); 

                // Batch of Integrals (0,92)

                #pragma omp simd aligned(fxn, fza, tg_xxxx_xxxxxxx_0, tg_xxxx_xxxxxxx_1, tg_xxxx_xxxxxxy_0, \
                                         tg_xxxx_xxxxxxy_1, tg_xxxx_xxxxxxz_0, tg_xxxx_xxxxxxz_1, tg_xxxx_xxxxxyy_0, \
                                         tg_xxxx_xxxxxyy_1, tg_xxxx_xxxxxyz_0, tg_xxxx_xxxxxyz_1, tg_xxxx_xxxxxzz_0, \
                                         tg_xxxx_xxxxxzz_1, tg_xxxx_xxxxyyy_0, tg_xxxx_xxxxyyy_1, tg_xxxx_xxxxyyz_0, \
                                         tg_xxxx_xxxxyyz_1, tg_xxxx_xxxxyzz_0, tg_xxxx_xxxxyzz_1, tg_xxxx_xxxxzzz_0, \
                                         tg_xxxx_xxxxzzz_1, tg_xxxx_xxxyyyy_0, tg_xxxx_xxxyyyy_1, tg_xxxx_xxxyyyz_0, \
                                         tg_xxxx_xxxyyyz_1, tg_xxxx_xxxyyzz_0, tg_xxxx_xxxyyzz_1, tg_xxxx_xxxyzzz_0, \
                                         tg_xxxx_xxxyzzz_1, tg_xxxx_xxxzzzz_0, tg_xxxx_xxxzzzz_1, tg_xxxx_xxyyyyy_0, \
                                         tg_xxxx_xxyyyyy_1, tg_xxxx_xxyyyyz_0, tg_xxxx_xxyyyyz_1, tg_xxxx_xxyyyzz_0, \
                                         tg_xxxx_xxyyyzz_1, tg_xxxx_xxyyzzz_0, tg_xxxx_xxyyzzz_1, tg_xxxx_xxyzzzz_0, \
                                         tg_xxxx_xxyzzzz_1, tg_xxxx_xxzzzzz_0, tg_xxxx_xxzzzzz_1, tg_xxxx_xyyyyyy_0, \
                                         tg_xxxx_xyyyyyy_1, tg_xxxx_xyyyyyz_0, tg_xxxx_xyyyyyz_1, tg_xxxx_xyyyyzz_0, \
                                         tg_xxxx_xyyyyzz_1, tg_xxxx_xyyyzzz_0, tg_xxxx_xyyyzzz_1, tg_xxxx_xyyzzzz_0, \
                                         tg_xxxx_xyyzzzz_1, tg_xxxx_xyzzzzz_0, tg_xxxx_xyzzzzz_1, tg_xxxx_xzzzzzz_0, \
                                         tg_xxxx_xzzzzzz_1, tg_xxxx_yyyyyyy_0, tg_xxxx_yyyyyyy_1, tg_xxxx_yyyyyyz_0, \
                                         tg_xxxx_yyyyyyz_1, tg_xxxx_yyyyyzz_0, tg_xxxx_yyyyyzz_1, tg_xxxx_yyyyzzz_0, \
                                         tg_xxxx_yyyyzzz_1, tg_xxxx_yyyzzzz_0, tg_xxxx_yyyzzzz_1, tg_xxxx_yyzzzzz_0, \
                                         tg_xxxx_yyzzzzz_1, tg_xxxx_yzzzzzz_0, tg_xxxx_yzzzzzz_1, tg_xxxx_zzzzzzz_0, \
                                         tg_xxxx_zzzzzzz_1, tg_xxxxx_xxxxxx_1, tg_xxxxx_xxxxxxx_0, tg_xxxxx_xxxxxxx_1, \
                                         tg_xxxxx_xxxxxxy_0, tg_xxxxx_xxxxxxy_1, tg_xxxxx_xxxxxxz_0, tg_xxxxx_xxxxxxz_1, \
                                         tg_xxxxx_xxxxxy_1, tg_xxxxx_xxxxxyy_0, tg_xxxxx_xxxxxyy_1, tg_xxxxx_xxxxxyz_0, \
                                         tg_xxxxx_xxxxxyz_1, tg_xxxxx_xxxxxz_1, tg_xxxxx_xxxxxzz_0, tg_xxxxx_xxxxxzz_1, \
                                         tg_xxxxx_xxxxyy_1, tg_xxxxx_xxxxyyy_0, tg_xxxxx_xxxxyyy_1, tg_xxxxx_xxxxyyz_0, \
                                         tg_xxxxx_xxxxyyz_1, tg_xxxxx_xxxxyz_1, tg_xxxxx_xxxxyzz_0, tg_xxxxx_xxxxyzz_1, \
                                         tg_xxxxx_xxxxzz_1, tg_xxxxx_xxxxzzz_0, tg_xxxxx_xxxxzzz_1, tg_xxxxx_xxxyyy_1, \
                                         tg_xxxxx_xxxyyyy_0, tg_xxxxx_xxxyyyy_1, tg_xxxxx_xxxyyyz_0, tg_xxxxx_xxxyyyz_1, \
                                         tg_xxxxx_xxxyyz_1, tg_xxxxx_xxxyyzz_0, tg_xxxxx_xxxyyzz_1, tg_xxxxx_xxxyzz_1, \
                                         tg_xxxxx_xxxyzzz_0, tg_xxxxx_xxxyzzz_1, tg_xxxxx_xxxzzz_1, tg_xxxxx_xxxzzzz_0, \
                                         tg_xxxxx_xxxzzzz_1, tg_xxxxx_xxyyyy_1, tg_xxxxx_xxyyyyy_0, tg_xxxxx_xxyyyyy_1, \
                                         tg_xxxxx_xxyyyyz_0, tg_xxxxx_xxyyyyz_1, tg_xxxxx_xxyyyz_1, tg_xxxxx_xxyyyzz_0, \
                                         tg_xxxxx_xxyyyzz_1, tg_xxxxx_xxyyzz_1, tg_xxxxx_xxyyzzz_0, tg_xxxxx_xxyyzzz_1, \
                                         tg_xxxxx_xxyzzz_1, tg_xxxxx_xxyzzzz_0, tg_xxxxx_xxyzzzz_1, tg_xxxxx_xxzzzz_1, \
                                         tg_xxxxx_xxzzzzz_0, tg_xxxxx_xxzzzzz_1, tg_xxxxx_xyyyyy_1, tg_xxxxx_xyyyyyy_0, \
                                         tg_xxxxx_xyyyyyy_1, tg_xxxxx_xyyyyyz_0, tg_xxxxx_xyyyyyz_1, tg_xxxxx_xyyyyz_1, \
                                         tg_xxxxx_xyyyyzz_0, tg_xxxxx_xyyyyzz_1, tg_xxxxx_xyyyzz_1, tg_xxxxx_xyyyzzz_0, \
                                         tg_xxxxx_xyyyzzz_1, tg_xxxxx_xyyzzz_1, tg_xxxxx_xyyzzzz_0, tg_xxxxx_xyyzzzz_1, \
                                         tg_xxxxx_xyzzzz_1, tg_xxxxx_xyzzzzz_0, tg_xxxxx_xyzzzzz_1, tg_xxxxx_xzzzzz_1, \
                                         tg_xxxxx_xzzzzzz_0, tg_xxxxx_xzzzzzz_1, tg_xxxxx_yyyyyy_1, tg_xxxxx_yyyyyyy_0, \
                                         tg_xxxxx_yyyyyyy_1, tg_xxxxx_yyyyyyz_0, tg_xxxxx_yyyyyyz_1, tg_xxxxx_yyyyyz_1, \
                                         tg_xxxxx_yyyyyzz_0, tg_xxxxx_yyyyyzz_1, tg_xxxxx_yyyyzz_1, tg_xxxxx_yyyyzzz_0, \
                                         tg_xxxxx_yyyyzzz_1, tg_xxxxx_yyyzzz_1, tg_xxxxx_yyyzzzz_0, tg_xxxxx_yyyzzzz_1, \
                                         tg_xxxxx_yyzzzz_1, tg_xxxxx_yyzzzzz_0, tg_xxxxx_yyzzzzz_1, tg_xxxxx_yzzzzz_1, \
                                         tg_xxxxx_yzzzzzz_0, tg_xxxxx_yzzzzzz_1, tg_xxxxx_zzzzzz_1, tg_xxxxx_zzzzzzz_0, \
                                         tg_xxxxx_zzzzzzz_1, tg_xxxxxx_xxxxxxx_0, tg_xxxxxx_xxxxxxy_0, tg_xxxxxx_xxxxxxz_0, \
                                         tg_xxxxxx_xxxxxyy_0, tg_xxxxxx_xxxxxyz_0, tg_xxxxxx_xxxxxzz_0, tg_xxxxxx_xxxxyyy_0, \
                                         tg_xxxxxx_xxxxyyz_0, tg_xxxxxx_xxxxyzz_0, tg_xxxxxx_xxxxzzz_0, tg_xxxxxx_xxxyyyy_0, \
                                         tg_xxxxxx_xxxyyyz_0, tg_xxxxxx_xxxyyzz_0, tg_xxxxxx_xxxyzzz_0, tg_xxxxxx_xxxzzzz_0, \
                                         tg_xxxxxx_xxyyyyy_0, tg_xxxxxx_xxyyyyz_0, tg_xxxxxx_xxyyyzz_0, tg_xxxxxx_xxyyzzz_0, \
                                         tg_xxxxxx_xxyzzzz_0, tg_xxxxxx_xxzzzzz_0, tg_xxxxxx_xyyyyyy_0, tg_xxxxxx_xyyyyyz_0, \
                                         tg_xxxxxx_xyyyyzz_0, tg_xxxxxx_xyyyzzz_0, tg_xxxxxx_xyyzzzz_0, tg_xxxxxx_xyzzzzz_0, \
                                         tg_xxxxxx_xzzzzzz_0, tg_xxxxxx_yyyyyyy_0, tg_xxxxxx_yyyyyyz_0, tg_xxxxxx_yyyyyzz_0, \
                                         tg_xxxxxx_yyyyzzz_0, tg_xxxxxx_yyyzzzz_0, tg_xxxxxx_yyzzzzz_0, tg_xxxxxx_yzzzzzz_0, \
                                         tg_xxxxxx_zzzzzzz_0, tg_xxxxxy_xxxxxxx_0, tg_xxxxxy_xxxxxxy_0, tg_xxxxxy_xxxxxxz_0, \
                                         tg_xxxxxy_xxxxxyy_0, tg_xxxxxy_xxxxxyz_0, tg_xxxxxy_xxxxxzz_0, tg_xxxxxy_xxxxyyy_0, \
                                         tg_xxxxxy_xxxxyyz_0, tg_xxxxxy_xxxxyzz_0, tg_xxxxxy_xxxxzzz_0, tg_xxxxxy_xxxyyyy_0, \
                                         tg_xxxxxy_xxxyyyz_0, tg_xxxxxy_xxxyyzz_0, tg_xxxxxy_xxxyzzz_0, tg_xxxxxy_xxxzzzz_0, \
                                         tg_xxxxxy_xxyyyyy_0, tg_xxxxxy_xxyyyyz_0, tg_xxxxxy_xxyyyzz_0, tg_xxxxxy_xxyyzzz_0, \
                                         tg_xxxxxy_xxyzzzz_0, tg_xxxxxy_xxzzzzz_0, tg_xxxxxy_xyyyyyy_0, tg_xxxxxy_xyyyyyz_0, \
                                         tg_xxxxxy_xyyyyzz_0, tg_xxxxxy_xyyyzzz_0, tg_xxxxxy_xyyzzzz_0, tg_xxxxxy_xyzzzzz_0, \
                                         tg_xxxxxy_xzzzzzz_0, tg_xxxxxy_yyyyyyy_0, tg_xxxxxy_yyyyyyz_0, tg_xxxxxy_yyyyyzz_0, \
                                         tg_xxxxxy_yyyyzzz_0, tg_xxxxxy_yyyzzzz_0, tg_xxxxxy_yyzzzzz_0, tg_xxxxxy_yzzzzzz_0, \
                                         tg_xxxxxy_zzzzzzz_0, tg_xxxxxz_xxxxxxx_0, tg_xxxxxz_xxxxxxy_0, tg_xxxxxz_xxxxxxz_0, \
                                         tg_xxxxxz_xxxxxyy_0, tg_xxxxxz_xxxxxyz_0, tg_xxxxxz_xxxxxzz_0, tg_xxxxxz_xxxxyyy_0, \
                                         tg_xxxxxz_xxxxyyz_0, tg_xxxxxz_xxxxyzz_0, tg_xxxxxz_xxxxzzz_0, tg_xxxxxz_xxxyyyy_0, \
                                         tg_xxxxxz_xxxyyyz_0, tg_xxxxxz_xxxyyzz_0, tg_xxxxxz_xxxyzzz_0, tg_xxxxxz_xxxzzzz_0, \
                                         tg_xxxxxz_xxyyyyy_0, tg_xxxxxz_xxyyyyz_0, tg_xxxxxz_xxyyyzz_0, tg_xxxxxz_xxyyzzz_0, \
                                         tg_xxxxxz_xxyzzzz_0, tg_xxxxy_xxxxxx_1, tg_xxxxy_xxxxxxx_0, tg_xxxxy_xxxxxxx_1, \
                                         tg_xxxxy_xxxxxxy_0, tg_xxxxy_xxxxxxy_1, tg_xxxxy_xxxxxxz_0, tg_xxxxy_xxxxxxz_1, \
                                         tg_xxxxy_xxxxxy_1, tg_xxxxy_xxxxxyy_0, tg_xxxxy_xxxxxyy_1, tg_xxxxy_xxxxxyz_0, \
                                         tg_xxxxy_xxxxxyz_1, tg_xxxxy_xxxxxz_1, tg_xxxxy_xxxxxzz_0, tg_xxxxy_xxxxxzz_1, \
                                         tg_xxxxy_xxxxyy_1, tg_xxxxy_xxxxyyy_0, tg_xxxxy_xxxxyyy_1, tg_xxxxy_xxxxyyz_0, \
                                         tg_xxxxy_xxxxyyz_1, tg_xxxxy_xxxxyz_1, tg_xxxxy_xxxxyzz_0, tg_xxxxy_xxxxyzz_1, \
                                         tg_xxxxy_xxxxzz_1, tg_xxxxy_xxxxzzz_0, tg_xxxxy_xxxxzzz_1, tg_xxxxy_xxxyyy_1, \
                                         tg_xxxxy_xxxyyyy_0, tg_xxxxy_xxxyyyy_1, tg_xxxxy_xxxyyyz_0, tg_xxxxy_xxxyyyz_1, \
                                         tg_xxxxy_xxxyyz_1, tg_xxxxy_xxxyyzz_0, tg_xxxxy_xxxyyzz_1, tg_xxxxy_xxxyzz_1, \
                                         tg_xxxxy_xxxyzzz_0, tg_xxxxy_xxxyzzz_1, tg_xxxxy_xxxzzz_1, tg_xxxxy_xxxzzzz_0, \
                                         tg_xxxxy_xxxzzzz_1, tg_xxxxy_xxyyyy_1, tg_xxxxy_xxyyyyy_0, tg_xxxxy_xxyyyyy_1, \
                                         tg_xxxxy_xxyyyyz_0, tg_xxxxy_xxyyyyz_1, tg_xxxxy_xxyyyz_1, tg_xxxxy_xxyyyzz_0, \
                                         tg_xxxxy_xxyyyzz_1, tg_xxxxy_xxyyzz_1, tg_xxxxy_xxyyzzz_0, tg_xxxxy_xxyyzzz_1, \
                                         tg_xxxxy_xxyzzz_1, tg_xxxxy_xxyzzzz_0, tg_xxxxy_xxyzzzz_1, tg_xxxxy_xxzzzz_1, \
                                         tg_xxxxy_xxzzzzz_0, tg_xxxxy_xxzzzzz_1, tg_xxxxy_xyyyyy_1, tg_xxxxy_xyyyyyy_0, \
                                         tg_xxxxy_xyyyyyy_1, tg_xxxxy_xyyyyyz_0, tg_xxxxy_xyyyyyz_1, tg_xxxxy_xyyyyz_1, \
                                         tg_xxxxy_xyyyyzz_0, tg_xxxxy_xyyyyzz_1, tg_xxxxy_xyyyzz_1, tg_xxxxy_xyyyzzz_0, \
                                         tg_xxxxy_xyyyzzz_1, tg_xxxxy_xyyzzz_1, tg_xxxxy_xyyzzzz_0, tg_xxxxy_xyyzzzz_1, \
                                         tg_xxxxy_xyzzzz_1, tg_xxxxy_xyzzzzz_0, tg_xxxxy_xyzzzzz_1, tg_xxxxy_xzzzzz_1, \
                                         tg_xxxxy_xzzzzzz_0, tg_xxxxy_xzzzzzz_1, tg_xxxxy_yyyyyy_1, tg_xxxxy_yyyyyyy_0, \
                                         tg_xxxxy_yyyyyyy_1, tg_xxxxy_yyyyyyz_0, tg_xxxxy_yyyyyyz_1, tg_xxxxy_yyyyyz_1, \
                                         tg_xxxxy_yyyyyzz_0, tg_xxxxy_yyyyyzz_1, tg_xxxxy_yyyyzz_1, tg_xxxxy_yyyyzzz_0, \
                                         tg_xxxxy_yyyyzzz_1, tg_xxxxy_yyyzzz_1, tg_xxxxy_yyyzzzz_0, tg_xxxxy_yyyzzzz_1, \
                                         tg_xxxxy_yyzzzz_1, tg_xxxxy_yyzzzzz_0, tg_xxxxy_yyzzzzz_1, tg_xxxxy_yzzzzz_1, \
                                         tg_xxxxy_yzzzzzz_0, tg_xxxxy_yzzzzzz_1, tg_xxxxy_zzzzzz_1, tg_xxxxy_zzzzzzz_0, \
                                         tg_xxxxy_zzzzzzz_1, tg_xxxxz_xxxxxx_1, tg_xxxxz_xxxxxxx_0, tg_xxxxz_xxxxxxx_1, \
                                         tg_xxxxz_xxxxxxy_0, tg_xxxxz_xxxxxxy_1, tg_xxxxz_xxxxxxz_0, tg_xxxxz_xxxxxxz_1, \
                                         tg_xxxxz_xxxxxy_1, tg_xxxxz_xxxxxyy_0, tg_xxxxz_xxxxxyy_1, tg_xxxxz_xxxxxyz_0, \
                                         tg_xxxxz_xxxxxyz_1, tg_xxxxz_xxxxxz_1, tg_xxxxz_xxxxxzz_0, tg_xxxxz_xxxxxzz_1, \
                                         tg_xxxxz_xxxxyy_1, tg_xxxxz_xxxxyyy_0, tg_xxxxz_xxxxyyy_1, tg_xxxxz_xxxxyyz_0, \
                                         tg_xxxxz_xxxxyyz_1, tg_xxxxz_xxxxyz_1, tg_xxxxz_xxxxyzz_0, tg_xxxxz_xxxxyzz_1, \
                                         tg_xxxxz_xxxxzz_1, tg_xxxxz_xxxxzzz_0, tg_xxxxz_xxxxzzz_1, tg_xxxxz_xxxyyy_1, \
                                         tg_xxxxz_xxxyyyy_0, tg_xxxxz_xxxyyyy_1, tg_xxxxz_xxxyyyz_0, tg_xxxxz_xxxyyyz_1, \
                                         tg_xxxxz_xxxyyz_1, tg_xxxxz_xxxyyzz_0, tg_xxxxz_xxxyyzz_1, tg_xxxxz_xxxyzz_1, \
                                         tg_xxxxz_xxxyzzz_0, tg_xxxxz_xxxyzzz_1, tg_xxxxz_xxxzzz_1, tg_xxxxz_xxxzzzz_0, \
                                         tg_xxxxz_xxxzzzz_1, tg_xxxxz_xxyyyy_1, tg_xxxxz_xxyyyyy_0, tg_xxxxz_xxyyyyy_1, \
                                         tg_xxxxz_xxyyyyz_0, tg_xxxxz_xxyyyyz_1, tg_xxxxz_xxyyyz_1, tg_xxxxz_xxyyyzz_0, \
                                         tg_xxxxz_xxyyyzz_1, tg_xxxxz_xxyyzz_1, tg_xxxxz_xxyyzzz_0, tg_xxxxz_xxyyzzz_1, \
                                         tg_xxxxz_xxyzzz_1, tg_xxxxz_xxyzzzz_0, tg_xxxxz_xxyzzzz_1, tg_xxxxz_xxzzzz_1, \
                                         tg_xxxxz_xyyyyy_1, tg_xxxxz_xyyyyz_1, tg_xxxxz_xyyyzz_1, tg_xxxxz_xyyzzz_1, \
                                         tg_xxxxz_xyzzzz_1, tg_xxxy_xxxxxxx_0, tg_xxxy_xxxxxxx_1, tg_xxxy_xxxxxxy_0, \
                                         tg_xxxy_xxxxxxy_1, tg_xxxy_xxxxxxz_0, tg_xxxy_xxxxxxz_1, tg_xxxy_xxxxxyy_0, \
                                         tg_xxxy_xxxxxyy_1, tg_xxxy_xxxxxyz_0, tg_xxxy_xxxxxyz_1, tg_xxxy_xxxxxzz_0, \
                                         tg_xxxy_xxxxxzz_1, tg_xxxy_xxxxyyy_0, tg_xxxy_xxxxyyy_1, tg_xxxy_xxxxyyz_0, \
                                         tg_xxxy_xxxxyyz_1, tg_xxxy_xxxxyzz_0, tg_xxxy_xxxxyzz_1, tg_xxxy_xxxxzzz_0, \
                                         tg_xxxy_xxxxzzz_1, tg_xxxy_xxxyyyy_0, tg_xxxy_xxxyyyy_1, tg_xxxy_xxxyyyz_0, \
                                         tg_xxxy_xxxyyyz_1, tg_xxxy_xxxyyzz_0, tg_xxxy_xxxyyzz_1, tg_xxxy_xxxyzzz_0, \
                                         tg_xxxy_xxxyzzz_1, tg_xxxy_xxxzzzz_0, tg_xxxy_xxxzzzz_1, tg_xxxy_xxyyyyy_0, \
                                         tg_xxxy_xxyyyyy_1, tg_xxxy_xxyyyyz_0, tg_xxxy_xxyyyyz_1, tg_xxxy_xxyyyzz_0, \
                                         tg_xxxy_xxyyyzz_1, tg_xxxy_xxyyzzz_0, tg_xxxy_xxyyzzz_1, tg_xxxy_xxyzzzz_0, \
                                         tg_xxxy_xxyzzzz_1, tg_xxxy_xxzzzzz_0, tg_xxxy_xxzzzzz_1, tg_xxxy_xyyyyyy_0, \
                                         tg_xxxy_xyyyyyy_1, tg_xxxy_xyyyyyz_0, tg_xxxy_xyyyyyz_1, tg_xxxy_xyyyyzz_0, \
                                         tg_xxxy_xyyyyzz_1, tg_xxxy_xyyyzzz_0, tg_xxxy_xyyyzzz_1, tg_xxxy_xyyzzzz_0, \
                                         tg_xxxy_xyyzzzz_1, tg_xxxy_xyzzzzz_0, tg_xxxy_xyzzzzz_1, tg_xxxy_xzzzzzz_0, \
                                         tg_xxxy_xzzzzzz_1, tg_xxxy_yyyyyyy_0, tg_xxxy_yyyyyyy_1, tg_xxxy_yyyyyyz_0, \
                                         tg_xxxy_yyyyyyz_1, tg_xxxy_yyyyyzz_0, tg_xxxy_yyyyyzz_1, tg_xxxy_yyyyzzz_0, \
                                         tg_xxxy_yyyyzzz_1, tg_xxxy_yyyzzzz_0, tg_xxxy_yyyzzzz_1, tg_xxxy_yyzzzzz_0, \
                                         tg_xxxy_yyzzzzz_1, tg_xxxy_yzzzzzz_0, tg_xxxy_yzzzzzz_1, tg_xxxy_zzzzzzz_0, \
                                         tg_xxxy_zzzzzzz_1, tg_xxxz_xxxxxxx_0, tg_xxxz_xxxxxxx_1, tg_xxxz_xxxxxxy_0, \
                                         tg_xxxz_xxxxxxy_1, tg_xxxz_xxxxxxz_0, tg_xxxz_xxxxxxz_1, tg_xxxz_xxxxxyy_0, \
                                         tg_xxxz_xxxxxyy_1, tg_xxxz_xxxxxyz_0, tg_xxxz_xxxxxyz_1, tg_xxxz_xxxxxzz_0, \
                                         tg_xxxz_xxxxxzz_1, tg_xxxz_xxxxyyy_0, tg_xxxz_xxxxyyy_1, tg_xxxz_xxxxyyz_0, \
                                         tg_xxxz_xxxxyyz_1, tg_xxxz_xxxxyzz_0, tg_xxxz_xxxxyzz_1, tg_xxxz_xxxxzzz_0, \
                                         tg_xxxz_xxxxzzz_1, tg_xxxz_xxxyyyy_0, tg_xxxz_xxxyyyy_1, tg_xxxz_xxxyyyz_0, \
                                         tg_xxxz_xxxyyyz_1, tg_xxxz_xxxyyzz_0, tg_xxxz_xxxyyzz_1, tg_xxxz_xxxyzzz_0, \
                                         tg_xxxz_xxxyzzz_1, tg_xxxz_xxxzzzz_0, tg_xxxz_xxxzzzz_1, tg_xxxz_xxyyyyy_0, \
                                         tg_xxxz_xxyyyyy_1, tg_xxxz_xxyyyyz_0, tg_xxxz_xxyyyyz_1, tg_xxxz_xxyyyzz_0, \
                                         tg_xxxz_xxyyyzz_1, tg_xxxz_xxyyzzz_0, tg_xxxz_xxyyzzz_1, tg_xxxz_xxyzzzz_0, \
                                         tg_xxxz_xxyzzzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxxxx_xxxxxxx_0[j] = pb_x * tg_xxxxx_xxxxxxx_0[j] + fr * tg_xxxxx_xxxxxxx_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxxx_0[j] - tg_xxxx_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxxx_xxxxxx_1[j];

                    tg_xxxxxx_xxxxxxy_0[j] = pb_x * tg_xxxxx_xxxxxxy_0[j] + fr * tg_xxxxx_xxxxxxy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxxy_0[j] - tg_xxxx_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxx_xxxxxy_1[j];

                    tg_xxxxxx_xxxxxxz_0[j] = pb_x * tg_xxxxx_xxxxxxz_0[j] + fr * tg_xxxxx_xxxxxxz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxxz_0[j] - tg_xxxx_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxx_xxxxxz_1[j];

                    tg_xxxxxx_xxxxxyy_0[j] = pb_x * tg_xxxxx_xxxxxyy_0[j] + fr * tg_xxxxx_xxxxxyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxyy_0[j] - tg_xxxx_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxx_xxxxyy_1[j];

                    tg_xxxxxx_xxxxxyz_0[j] = pb_x * tg_xxxxx_xxxxxyz_0[j] + fr * tg_xxxxx_xxxxxyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxyz_0[j] - tg_xxxx_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxx_xxxxyz_1[j];

                    tg_xxxxxx_xxxxxzz_0[j] = pb_x * tg_xxxxx_xxxxxzz_0[j] + fr * tg_xxxxx_xxxxxzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxxzz_0[j] - tg_xxxx_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxx_xxxxzz_1[j];

                    tg_xxxxxx_xxxxyyy_0[j] = pb_x * tg_xxxxx_xxxxyyy_0[j] + fr * tg_xxxxx_xxxxyyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxyyy_0[j] - tg_xxxx_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxx_xxxyyy_1[j];

                    tg_xxxxxx_xxxxyyz_0[j] = pb_x * tg_xxxxx_xxxxyyz_0[j] + fr * tg_xxxxx_xxxxyyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxyyz_0[j] - tg_xxxx_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxx_xxxyyz_1[j];

                    tg_xxxxxx_xxxxyzz_0[j] = pb_x * tg_xxxxx_xxxxyzz_0[j] + fr * tg_xxxxx_xxxxyzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxyzz_0[j] - tg_xxxx_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxx_xxxyzz_1[j];

                    tg_xxxxxx_xxxxzzz_0[j] = pb_x * tg_xxxxx_xxxxzzz_0[j] + fr * tg_xxxxx_xxxxzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxxzzz_0[j] - tg_xxxx_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxx_xxxzzz_1[j];

                    tg_xxxxxx_xxxyyyy_0[j] = pb_x * tg_xxxxx_xxxyyyy_0[j] + fr * tg_xxxxx_xxxyyyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxyyyy_0[j] - tg_xxxx_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xxyyyy_1[j];

                    tg_xxxxxx_xxxyyyz_0[j] = pb_x * tg_xxxxx_xxxyyyz_0[j] + fr * tg_xxxxx_xxxyyyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxyyyz_0[j] - tg_xxxx_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xxyyyz_1[j];

                    tg_xxxxxx_xxxyyzz_0[j] = pb_x * tg_xxxxx_xxxyyzz_0[j] + fr * tg_xxxxx_xxxyyzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxyyzz_0[j] - tg_xxxx_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xxyyzz_1[j];

                    tg_xxxxxx_xxxyzzz_0[j] = pb_x * tg_xxxxx_xxxyzzz_0[j] + fr * tg_xxxxx_xxxyzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxyzzz_0[j] - tg_xxxx_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xxyzzz_1[j];

                    tg_xxxxxx_xxxzzzz_0[j] = pb_x * tg_xxxxx_xxxzzzz_0[j] + fr * tg_xxxxx_xxxzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxxzzzz_0[j] - tg_xxxx_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxx_xxzzzz_1[j];

                    tg_xxxxxx_xxyyyyy_0[j] = pb_x * tg_xxxxx_xxyyyyy_0[j] + fr * tg_xxxxx_xxyyyyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxyyyyy_0[j] - tg_xxxx_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xyyyyy_1[j];

                    tg_xxxxxx_xxyyyyz_0[j] = pb_x * tg_xxxxx_xxyyyyz_0[j] + fr * tg_xxxxx_xxyyyyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxyyyyz_0[j] - tg_xxxx_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xyyyyz_1[j];

                    tg_xxxxxx_xxyyyzz_0[j] = pb_x * tg_xxxxx_xxyyyzz_0[j] + fr * tg_xxxxx_xxyyyzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxyyyzz_0[j] - tg_xxxx_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xyyyzz_1[j];

                    tg_xxxxxx_xxyyzzz_0[j] = pb_x * tg_xxxxx_xxyyzzz_0[j] + fr * tg_xxxxx_xxyyzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxyyzzz_0[j] - tg_xxxx_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xyyzzz_1[j];

                    tg_xxxxxx_xxyzzzz_0[j] = pb_x * tg_xxxxx_xxyzzzz_0[j] + fr * tg_xxxxx_xxyzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxyzzzz_0[j] - tg_xxxx_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xyzzzz_1[j];

                    tg_xxxxxx_xxzzzzz_0[j] = pb_x * tg_xxxxx_xxzzzzz_0[j] + fr * tg_xxxxx_xxzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xxzzzzz_0[j] - tg_xxxx_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxx_xzzzzz_1[j];

                    tg_xxxxxx_xyyyyyy_0[j] = pb_x * tg_xxxxx_xyyyyyy_0[j] + fr * tg_xxxxx_xyyyyyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyyyyyy_0[j] - tg_xxxx_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yyyyyy_1[j];

                    tg_xxxxxx_xyyyyyz_0[j] = pb_x * tg_xxxxx_xyyyyyz_0[j] + fr * tg_xxxxx_xyyyyyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyyyyyz_0[j] - tg_xxxx_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yyyyyz_1[j];

                    tg_xxxxxx_xyyyyzz_0[j] = pb_x * tg_xxxxx_xyyyyzz_0[j] + fr * tg_xxxxx_xyyyyzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyyyyzz_0[j] - tg_xxxx_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yyyyzz_1[j];

                    tg_xxxxxx_xyyyzzz_0[j] = pb_x * tg_xxxxx_xyyyzzz_0[j] + fr * tg_xxxxx_xyyyzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyyyzzz_0[j] - tg_xxxx_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yyyzzz_1[j];

                    tg_xxxxxx_xyyzzzz_0[j] = pb_x * tg_xxxxx_xyyzzzz_0[j] + fr * tg_xxxxx_xyyzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyyzzzz_0[j] - tg_xxxx_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yyzzzz_1[j];

                    tg_xxxxxx_xyzzzzz_0[j] = pb_x * tg_xxxxx_xyzzzzz_0[j] + fr * tg_xxxxx_xyzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xyzzzzz_0[j] - tg_xxxx_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_yzzzzz_1[j];

                    tg_xxxxxx_xzzzzzz_0[j] = pb_x * tg_xxxxx_xzzzzzz_0[j] + fr * tg_xxxxx_xzzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_xzzzzzz_0[j] - tg_xxxx_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxx_zzzzzz_1[j];

                    tg_xxxxxx_yyyyyyy_0[j] = pb_x * tg_xxxxx_yyyyyyy_0[j] + fr * tg_xxxxx_yyyyyyy_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyyyyyy_0[j] - tg_xxxx_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxxx_yyyyyyz_0[j] = pb_x * tg_xxxxx_yyyyyyz_0[j] + fr * tg_xxxxx_yyyyyyz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyyyyyz_0[j] - tg_xxxx_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxxx_yyyyyzz_0[j] = pb_x * tg_xxxxx_yyyyyzz_0[j] + fr * tg_xxxxx_yyyyyzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyyyyzz_0[j] - tg_xxxx_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxxx_yyyyzzz_0[j] = pb_x * tg_xxxxx_yyyyzzz_0[j] + fr * tg_xxxxx_yyyyzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyyyzzz_0[j] - tg_xxxx_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxxx_yyyzzzz_0[j] = pb_x * tg_xxxxx_yyyzzzz_0[j] + fr * tg_xxxxx_yyyzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyyzzzz_0[j] - tg_xxxx_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxxx_yyzzzzz_0[j] = pb_x * tg_xxxxx_yyzzzzz_0[j] + fr * tg_xxxxx_yyzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yyzzzzz_0[j] - tg_xxxx_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxxx_yzzzzzz_0[j] = pb_x * tg_xxxxx_yzzzzzz_0[j] + fr * tg_xxxxx_yzzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_yzzzzzz_0[j] - tg_xxxx_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxxx_zzzzzzz_0[j] = pb_x * tg_xxxxx_zzzzzzz_0[j] + fr * tg_xxxxx_zzzzzzz_1[j] + 2.5 * fl1_fx * (tg_xxxx_zzzzzzz_0[j] - tg_xxxx_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxxxy_xxxxxxx_0[j] = pb_x * tg_xxxxy_xxxxxxx_0[j] + fr * tg_xxxxy_xxxxxxx_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxxx_0[j] - tg_xxxy_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxxy_xxxxxx_1[j];

                    tg_xxxxxy_xxxxxxy_0[j] = pb_x * tg_xxxxy_xxxxxxy_0[j] + fr * tg_xxxxy_xxxxxxy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxxy_0[j] - tg_xxxy_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxy_xxxxxy_1[j];

                    tg_xxxxxy_xxxxxxz_0[j] = pb_x * tg_xxxxy_xxxxxxz_0[j] + fr * tg_xxxxy_xxxxxxz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxxz_0[j] - tg_xxxy_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxy_xxxxxz_1[j];

                    tg_xxxxxy_xxxxxyy_0[j] = pb_x * tg_xxxxy_xxxxxyy_0[j] + fr * tg_xxxxy_xxxxxyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxyy_0[j] - tg_xxxy_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxy_xxxxyy_1[j];

                    tg_xxxxxy_xxxxxyz_0[j] = pb_x * tg_xxxxy_xxxxxyz_0[j] + fr * tg_xxxxy_xxxxxyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxyz_0[j] - tg_xxxy_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxy_xxxxyz_1[j];

                    tg_xxxxxy_xxxxxzz_0[j] = pb_x * tg_xxxxy_xxxxxzz_0[j] + fr * tg_xxxxy_xxxxxzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxxzz_0[j] - tg_xxxy_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxy_xxxxzz_1[j];

                    tg_xxxxxy_xxxxyyy_0[j] = pb_x * tg_xxxxy_xxxxyyy_0[j] + fr * tg_xxxxy_xxxxyyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxyyy_0[j] - tg_xxxy_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxy_xxxyyy_1[j];

                    tg_xxxxxy_xxxxyyz_0[j] = pb_x * tg_xxxxy_xxxxyyz_0[j] + fr * tg_xxxxy_xxxxyyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxyyz_0[j] - tg_xxxy_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxy_xxxyyz_1[j];

                    tg_xxxxxy_xxxxyzz_0[j] = pb_x * tg_xxxxy_xxxxyzz_0[j] + fr * tg_xxxxy_xxxxyzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxyzz_0[j] - tg_xxxy_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxy_xxxyzz_1[j];

                    tg_xxxxxy_xxxxzzz_0[j] = pb_x * tg_xxxxy_xxxxzzz_0[j] + fr * tg_xxxxy_xxxxzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxxzzz_0[j] - tg_xxxy_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxy_xxxzzz_1[j];

                    tg_xxxxxy_xxxyyyy_0[j] = pb_x * tg_xxxxy_xxxyyyy_0[j] + fr * tg_xxxxy_xxxyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxyyyy_0[j] - tg_xxxy_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xxyyyy_1[j];

                    tg_xxxxxy_xxxyyyz_0[j] = pb_x * tg_xxxxy_xxxyyyz_0[j] + fr * tg_xxxxy_xxxyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxyyyz_0[j] - tg_xxxy_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xxyyyz_1[j];

                    tg_xxxxxy_xxxyyzz_0[j] = pb_x * tg_xxxxy_xxxyyzz_0[j] + fr * tg_xxxxy_xxxyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxyyzz_0[j] - tg_xxxy_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xxyyzz_1[j];

                    tg_xxxxxy_xxxyzzz_0[j] = pb_x * tg_xxxxy_xxxyzzz_0[j] + fr * tg_xxxxy_xxxyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxyzzz_0[j] - tg_xxxy_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xxyzzz_1[j];

                    tg_xxxxxy_xxxzzzz_0[j] = pb_x * tg_xxxxy_xxxzzzz_0[j] + fr * tg_xxxxy_xxxzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxxzzzz_0[j] - tg_xxxy_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxy_xxzzzz_1[j];

                    tg_xxxxxy_xxyyyyy_0[j] = pb_x * tg_xxxxy_xxyyyyy_0[j] + fr * tg_xxxxy_xxyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxyyyyy_0[j] - tg_xxxy_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xyyyyy_1[j];

                    tg_xxxxxy_xxyyyyz_0[j] = pb_x * tg_xxxxy_xxyyyyz_0[j] + fr * tg_xxxxy_xxyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxyyyyz_0[j] - tg_xxxy_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xyyyyz_1[j];

                    tg_xxxxxy_xxyyyzz_0[j] = pb_x * tg_xxxxy_xxyyyzz_0[j] + fr * tg_xxxxy_xxyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxyyyzz_0[j] - tg_xxxy_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xyyyzz_1[j];

                    tg_xxxxxy_xxyyzzz_0[j] = pb_x * tg_xxxxy_xxyyzzz_0[j] + fr * tg_xxxxy_xxyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxyyzzz_0[j] - tg_xxxy_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xyyzzz_1[j];

                    tg_xxxxxy_xxyzzzz_0[j] = pb_x * tg_xxxxy_xxyzzzz_0[j] + fr * tg_xxxxy_xxyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxyzzzz_0[j] - tg_xxxy_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xyzzzz_1[j];

                    tg_xxxxxy_xxzzzzz_0[j] = pb_x * tg_xxxxy_xxzzzzz_0[j] + fr * tg_xxxxy_xxzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xxzzzzz_0[j] - tg_xxxy_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxy_xzzzzz_1[j];

                    tg_xxxxxy_xyyyyyy_0[j] = pb_x * tg_xxxxy_xyyyyyy_0[j] + fr * tg_xxxxy_xyyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyyyyyy_0[j] - tg_xxxy_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yyyyyy_1[j];

                    tg_xxxxxy_xyyyyyz_0[j] = pb_x * tg_xxxxy_xyyyyyz_0[j] + fr * tg_xxxxy_xyyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyyyyyz_0[j] - tg_xxxy_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yyyyyz_1[j];

                    tg_xxxxxy_xyyyyzz_0[j] = pb_x * tg_xxxxy_xyyyyzz_0[j] + fr * tg_xxxxy_xyyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyyyyzz_0[j] - tg_xxxy_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yyyyzz_1[j];

                    tg_xxxxxy_xyyyzzz_0[j] = pb_x * tg_xxxxy_xyyyzzz_0[j] + fr * tg_xxxxy_xyyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyyyzzz_0[j] - tg_xxxy_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yyyzzz_1[j];

                    tg_xxxxxy_xyyzzzz_0[j] = pb_x * tg_xxxxy_xyyzzzz_0[j] + fr * tg_xxxxy_xyyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyyzzzz_0[j] - tg_xxxy_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yyzzzz_1[j];

                    tg_xxxxxy_xyzzzzz_0[j] = pb_x * tg_xxxxy_xyzzzzz_0[j] + fr * tg_xxxxy_xyzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xyzzzzz_0[j] - tg_xxxy_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_yzzzzz_1[j];

                    tg_xxxxxy_xzzzzzz_0[j] = pb_x * tg_xxxxy_xzzzzzz_0[j] + fr * tg_xxxxy_xzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_xzzzzzz_0[j] - tg_xxxy_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxy_zzzzzz_1[j];

                    tg_xxxxxy_yyyyyyy_0[j] = pb_x * tg_xxxxy_yyyyyyy_0[j] + fr * tg_xxxxy_yyyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyyyyyy_0[j] - tg_xxxy_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxxy_yyyyyyz_0[j] = pb_x * tg_xxxxy_yyyyyyz_0[j] + fr * tg_xxxxy_yyyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyyyyyz_0[j] - tg_xxxy_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxxy_yyyyyzz_0[j] = pb_x * tg_xxxxy_yyyyyzz_0[j] + fr * tg_xxxxy_yyyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyyyyzz_0[j] - tg_xxxy_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxxy_yyyyzzz_0[j] = pb_x * tg_xxxxy_yyyyzzz_0[j] + fr * tg_xxxxy_yyyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyyyzzz_0[j] - tg_xxxy_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxxy_yyyzzzz_0[j] = pb_x * tg_xxxxy_yyyzzzz_0[j] + fr * tg_xxxxy_yyyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyyzzzz_0[j] - tg_xxxy_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxxy_yyzzzzz_0[j] = pb_x * tg_xxxxy_yyzzzzz_0[j] + fr * tg_xxxxy_yyzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yyzzzzz_0[j] - tg_xxxy_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxxy_yzzzzzz_0[j] = pb_x * tg_xxxxy_yzzzzzz_0[j] + fr * tg_xxxxy_yzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_yzzzzzz_0[j] - tg_xxxy_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxxy_zzzzzzz_0[j] = pb_x * tg_xxxxy_zzzzzzz_0[j] + fr * tg_xxxxy_zzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxy_zzzzzzz_0[j] - tg_xxxy_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxxxz_xxxxxxx_0[j] = pb_x * tg_xxxxz_xxxxxxx_0[j] + fr * tg_xxxxz_xxxxxxx_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxxx_0[j] - tg_xxxz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxxz_xxxxxx_1[j];

                    tg_xxxxxz_xxxxxxy_0[j] = pb_x * tg_xxxxz_xxxxxxy_0[j] + fr * tg_xxxxz_xxxxxxy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxxy_0[j] - tg_xxxz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxz_xxxxxy_1[j];

                    tg_xxxxxz_xxxxxxz_0[j] = pb_x * tg_xxxxz_xxxxxxz_0[j] + fr * tg_xxxxz_xxxxxxz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxxz_0[j] - tg_xxxz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxxz_xxxxxz_1[j];

                    tg_xxxxxz_xxxxxyy_0[j] = pb_x * tg_xxxxz_xxxxxyy_0[j] + fr * tg_xxxxz_xxxxxyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxyy_0[j] - tg_xxxz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxz_xxxxyy_1[j];

                    tg_xxxxxz_xxxxxyz_0[j] = pb_x * tg_xxxxz_xxxxxyz_0[j] + fr * tg_xxxxz_xxxxxyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxyz_0[j] - tg_xxxz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxz_xxxxyz_1[j];

                    tg_xxxxxz_xxxxxzz_0[j] = pb_x * tg_xxxxz_xxxxxzz_0[j] + fr * tg_xxxxz_xxxxxzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxxzz_0[j] - tg_xxxz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxxz_xxxxzz_1[j];

                    tg_xxxxxz_xxxxyyy_0[j] = pb_x * tg_xxxxz_xxxxyyy_0[j] + fr * tg_xxxxz_xxxxyyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxyyy_0[j] - tg_xxxz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxz_xxxyyy_1[j];

                    tg_xxxxxz_xxxxyyz_0[j] = pb_x * tg_xxxxz_xxxxyyz_0[j] + fr * tg_xxxxz_xxxxyyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxyyz_0[j] - tg_xxxz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxz_xxxyyz_1[j];

                    tg_xxxxxz_xxxxyzz_0[j] = pb_x * tg_xxxxz_xxxxyzz_0[j] + fr * tg_xxxxz_xxxxyzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxyzz_0[j] - tg_xxxz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxz_xxxyzz_1[j];

                    tg_xxxxxz_xxxxzzz_0[j] = pb_x * tg_xxxxz_xxxxzzz_0[j] + fr * tg_xxxxz_xxxxzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxxzzz_0[j] - tg_xxxz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxxz_xxxzzz_1[j];

                    tg_xxxxxz_xxxyyyy_0[j] = pb_x * tg_xxxxz_xxxyyyy_0[j] + fr * tg_xxxxz_xxxyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxyyyy_0[j] - tg_xxxz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xxyyyy_1[j];

                    tg_xxxxxz_xxxyyyz_0[j] = pb_x * tg_xxxxz_xxxyyyz_0[j] + fr * tg_xxxxz_xxxyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxyyyz_0[j] - tg_xxxz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xxyyyz_1[j];

                    tg_xxxxxz_xxxyyzz_0[j] = pb_x * tg_xxxxz_xxxyyzz_0[j] + fr * tg_xxxxz_xxxyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxyyzz_0[j] - tg_xxxz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xxyyzz_1[j];

                    tg_xxxxxz_xxxyzzz_0[j] = pb_x * tg_xxxxz_xxxyzzz_0[j] + fr * tg_xxxxz_xxxyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxyzzz_0[j] - tg_xxxz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xxyzzz_1[j];

                    tg_xxxxxz_xxxzzzz_0[j] = pb_x * tg_xxxxz_xxxzzzz_0[j] + fr * tg_xxxxz_xxxzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxxzzzz_0[j] - tg_xxxz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxxz_xxzzzz_1[j];

                    tg_xxxxxz_xxyyyyy_0[j] = pb_x * tg_xxxxz_xxyyyyy_0[j] + fr * tg_xxxxz_xxyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxyyyyy_0[j] - tg_xxxz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xyyyyy_1[j];

                    tg_xxxxxz_xxyyyyz_0[j] = pb_x * tg_xxxxz_xxyyyyz_0[j] + fr * tg_xxxxz_xxyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxyyyyz_0[j] - tg_xxxz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xyyyyz_1[j];

                    tg_xxxxxz_xxyyyzz_0[j] = pb_x * tg_xxxxz_xxyyyzz_0[j] + fr * tg_xxxxz_xxyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxyyyzz_0[j] - tg_xxxz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xyyyzz_1[j];

                    tg_xxxxxz_xxyyzzz_0[j] = pb_x * tg_xxxxz_xxyyzzz_0[j] + fr * tg_xxxxz_xxyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxyyzzz_0[j] - tg_xxxz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xyyzzz_1[j];

                    tg_xxxxxz_xxyzzzz_0[j] = pb_x * tg_xxxxz_xxyzzzz_0[j] + fr * tg_xxxxz_xxyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxyzzzz_0[j] - tg_xxxz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xyzzzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_92_184(      CMemBlock2D<double>* primBuffer,
                                        const CRecursionMap&       recursionMap,
                                        const CMemBlock2D<double>& osFactors,
                                        const CMemBlock2D<double>& wpDistances,
                                        const CGtoPairsBlock&      braGtoPairsBlock,
                                        const CGtoPairsBlock&      ketGtoPairsBlock,
                                        const int32_t              nKetPrimPairs,
                                        const int32_t              iContrPair)
    {
        // Batch of Integrals (92,184)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xxxxz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 92); 

                auto tg_xxxxz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 93); 

                auto tg_xxxxz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 94); 

                auto tg_xxxxz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 95); 

                auto tg_xxxxz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 96); 

                auto tg_xxxxz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 97); 

                auto tg_xxxxz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 98); 

                auto tg_xxxxz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 99); 

                auto tg_xxxxz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 100); 

                auto tg_xxxxz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 101); 

                auto tg_xxxxz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 102); 

                auto tg_xxxxz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 103); 

                auto tg_xxxxz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 104); 

                auto tg_xxxxz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 105); 

                auto tg_xxxxz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 106); 

                auto tg_xxxxz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 107); 

                auto tg_xxxyy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 108); 

                auto tg_xxxyy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 109); 

                auto tg_xxxyy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 110); 

                auto tg_xxxyy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 111); 

                auto tg_xxxyy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 112); 

                auto tg_xxxyy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 113); 

                auto tg_xxxyy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 114); 

                auto tg_xxxyy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 115); 

                auto tg_xxxyy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 116); 

                auto tg_xxxyy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 117); 

                auto tg_xxxyy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 118); 

                auto tg_xxxyy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 119); 

                auto tg_xxxyy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 120); 

                auto tg_xxxyy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 121); 

                auto tg_xxxyy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 122); 

                auto tg_xxxyy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 123); 

                auto tg_xxxyy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 124); 

                auto tg_xxxyy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 125); 

                auto tg_xxxyy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 126); 

                auto tg_xxxyy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 127); 

                auto tg_xxxyy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 128); 

                auto tg_xxxyy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 129); 

                auto tg_xxxyy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 130); 

                auto tg_xxxyy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 131); 

                auto tg_xxxyy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 132); 

                auto tg_xxxyy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 133); 

                auto tg_xxxyy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 134); 

                auto tg_xxxyy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 135); 

                auto tg_xxxyy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 136); 

                auto tg_xxxyy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 137); 

                auto tg_xxxyy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 138); 

                auto tg_xxxyy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 139); 

                auto tg_xxxyy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 140); 

                auto tg_xxxyy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 141); 

                auto tg_xxxyy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 142); 

                auto tg_xxxyy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 143); 

                auto tg_xxxyz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 144); 

                auto tg_xxxyz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 145); 

                auto tg_xxxyz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 146); 

                auto tg_xxxyz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 147); 

                auto tg_xxxyz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 148); 

                auto tg_xxxyz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 149); 

                auto tg_xxxyz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 150); 

                auto tg_xxxyz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 151); 

                auto tg_xxxyz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 152); 

                auto tg_xxxyz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 153); 

                auto tg_xxxyz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 154); 

                auto tg_xxxyz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 155); 

                auto tg_xxxyz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 156); 

                auto tg_xxxyz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 157); 

                auto tg_xxxyz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 158); 

                auto tg_xxxyz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 159); 

                auto tg_xxxyz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 160); 

                auto tg_xxxyz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 161); 

                auto tg_xxxyz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 162); 

                auto tg_xxxyz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 163); 

                auto tg_xxxyz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 164); 

                auto tg_xxxyz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 165); 

                auto tg_xxxyz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 166); 

                auto tg_xxxyz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 167); 

                auto tg_xxxyz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 168); 

                auto tg_xxxyz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 169); 

                auto tg_xxxyz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 170); 

                auto tg_xxxyz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 171); 

                auto tg_xxxyz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 172); 

                auto tg_xxxyz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 173); 

                auto tg_xxxyz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 174); 

                auto tg_xxxyz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 175); 

                auto tg_xxxyz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 176); 

                auto tg_xxxyz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 177); 

                auto tg_xxxyz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 178); 

                auto tg_xxxyz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 179); 

                auto tg_xxxzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 180); 

                auto tg_xxxzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 181); 

                auto tg_xxxzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 182); 

                auto tg_xxxzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 183); 

                auto tg_xxxxz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 92); 

                auto tg_xxxxz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 93); 

                auto tg_xxxxz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 94); 

                auto tg_xxxxz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 95); 

                auto tg_xxxxz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 96); 

                auto tg_xxxxz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 97); 

                auto tg_xxxxz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 98); 

                auto tg_xxxxz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 99); 

                auto tg_xxxxz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 100); 

                auto tg_xxxxz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 101); 

                auto tg_xxxxz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 102); 

                auto tg_xxxxz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 103); 

                auto tg_xxxxz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 104); 

                auto tg_xxxxz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 105); 

                auto tg_xxxxz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 106); 

                auto tg_xxxxz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 107); 

                auto tg_xxxyy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 108); 

                auto tg_xxxyy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 109); 

                auto tg_xxxyy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 110); 

                auto tg_xxxyy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 111); 

                auto tg_xxxyy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 112); 

                auto tg_xxxyy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 113); 

                auto tg_xxxyy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 114); 

                auto tg_xxxyy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 115); 

                auto tg_xxxyy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 116); 

                auto tg_xxxyy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 117); 

                auto tg_xxxyy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 118); 

                auto tg_xxxyy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 119); 

                auto tg_xxxyy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 120); 

                auto tg_xxxyy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 121); 

                auto tg_xxxyy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 122); 

                auto tg_xxxyy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 123); 

                auto tg_xxxyy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 124); 

                auto tg_xxxyy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 125); 

                auto tg_xxxyy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 126); 

                auto tg_xxxyy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 127); 

                auto tg_xxxyy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 128); 

                auto tg_xxxyy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 129); 

                auto tg_xxxyy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 130); 

                auto tg_xxxyy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 131); 

                auto tg_xxxyy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 132); 

                auto tg_xxxyy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 133); 

                auto tg_xxxyy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 134); 

                auto tg_xxxyy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 135); 

                auto tg_xxxyy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 136); 

                auto tg_xxxyy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 137); 

                auto tg_xxxyy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 138); 

                auto tg_xxxyy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 139); 

                auto tg_xxxyy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 140); 

                auto tg_xxxyy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 141); 

                auto tg_xxxyy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 142); 

                auto tg_xxxyy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 143); 

                auto tg_xxxyz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 144); 

                auto tg_xxxyz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 145); 

                auto tg_xxxyz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 146); 

                auto tg_xxxyz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 147); 

                auto tg_xxxyz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 148); 

                auto tg_xxxyz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 149); 

                auto tg_xxxyz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 150); 

                auto tg_xxxyz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 151); 

                auto tg_xxxyz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 152); 

                auto tg_xxxyz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 153); 

                auto tg_xxxyz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 154); 

                auto tg_xxxyz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 155); 

                auto tg_xxxyz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 156); 

                auto tg_xxxyz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 157); 

                auto tg_xxxyz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 158); 

                auto tg_xxxyz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 159); 

                auto tg_xxxyz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 160); 

                auto tg_xxxyz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 161); 

                auto tg_xxxyz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 162); 

                auto tg_xxxyz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 163); 

                auto tg_xxxyz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 164); 

                auto tg_xxxyz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 165); 

                auto tg_xxxyz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 166); 

                auto tg_xxxyz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 167); 

                auto tg_xxxyz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 168); 

                auto tg_xxxyz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 169); 

                auto tg_xxxyz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 170); 

                auto tg_xxxyz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 171); 

                auto tg_xxxyz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 172); 

                auto tg_xxxyz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 173); 

                auto tg_xxxyz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 174); 

                auto tg_xxxyz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 175); 

                auto tg_xxxyz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 176); 

                auto tg_xxxyz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 177); 

                auto tg_xxxyz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 178); 

                auto tg_xxxyz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 179); 

                auto tg_xxxzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 180); 

                auto tg_xxxzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 181); 

                auto tg_xxxzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 182); 

                auto tg_xxxzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 183); 

                auto tg_xxxz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 92); 

                auto tg_xxxz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 93); 

                auto tg_xxxz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 94); 

                auto tg_xxxz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 95); 

                auto tg_xxxz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 96); 

                auto tg_xxxz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 97); 

                auto tg_xxxz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 98); 

                auto tg_xxxz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 99); 

                auto tg_xxxz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 100); 

                auto tg_xxxz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 101); 

                auto tg_xxxz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 102); 

                auto tg_xxxz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 103); 

                auto tg_xxxz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 104); 

                auto tg_xxxz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 105); 

                auto tg_xxxz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 106); 

                auto tg_xxxz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 107); 

                auto tg_xxyy_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 108); 

                auto tg_xxyy_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 109); 

                auto tg_xxyy_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 110); 

                auto tg_xxyy_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 111); 

                auto tg_xxyy_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 112); 

                auto tg_xxyy_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 113); 

                auto tg_xxyy_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 114); 

                auto tg_xxyy_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 115); 

                auto tg_xxyy_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 116); 

                auto tg_xxyy_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 117); 

                auto tg_xxyy_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 118); 

                auto tg_xxyy_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 119); 

                auto tg_xxyy_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 120); 

                auto tg_xxyy_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 121); 

                auto tg_xxyy_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 122); 

                auto tg_xxyy_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 123); 

                auto tg_xxyy_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 124); 

                auto tg_xxyy_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 125); 

                auto tg_xxyy_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 126); 

                auto tg_xxyy_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 127); 

                auto tg_xxyy_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 128); 

                auto tg_xxyy_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 129); 

                auto tg_xxyy_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 130); 

                auto tg_xxyy_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 131); 

                auto tg_xxyy_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 132); 

                auto tg_xxyy_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 133); 

                auto tg_xxyy_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 134); 

                auto tg_xxyy_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 135); 

                auto tg_xxyy_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 136); 

                auto tg_xxyy_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 137); 

                auto tg_xxyy_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 138); 

                auto tg_xxyy_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 139); 

                auto tg_xxyy_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 140); 

                auto tg_xxyy_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 141); 

                auto tg_xxyy_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 142); 

                auto tg_xxyy_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 143); 

                auto tg_xxyz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 144); 

                auto tg_xxyz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 145); 

                auto tg_xxyz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 146); 

                auto tg_xxyz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 147); 

                auto tg_xxyz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 148); 

                auto tg_xxyz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 149); 

                auto tg_xxyz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 150); 

                auto tg_xxyz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 151); 

                auto tg_xxyz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 152); 

                auto tg_xxyz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 153); 

                auto tg_xxyz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 154); 

                auto tg_xxyz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 155); 

                auto tg_xxyz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 156); 

                auto tg_xxyz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 157); 

                auto tg_xxyz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 158); 

                auto tg_xxyz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 159); 

                auto tg_xxyz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 160); 

                auto tg_xxyz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 161); 

                auto tg_xxyz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 162); 

                auto tg_xxyz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 163); 

                auto tg_xxyz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 164); 

                auto tg_xxyz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 165); 

                auto tg_xxyz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 166); 

                auto tg_xxyz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 167); 

                auto tg_xxyz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 168); 

                auto tg_xxyz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 169); 

                auto tg_xxyz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 170); 

                auto tg_xxyz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 171); 

                auto tg_xxyz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 172); 

                auto tg_xxyz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 173); 

                auto tg_xxyz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 174); 

                auto tg_xxyz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 175); 

                auto tg_xxyz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 176); 

                auto tg_xxyz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 177); 

                auto tg_xxyz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 178); 

                auto tg_xxyz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 179); 

                auto tg_xxzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 180); 

                auto tg_xxzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 181); 

                auto tg_xxzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 182); 

                auto tg_xxzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 183); 

                auto tg_xxxz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 92); 

                auto tg_xxxz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 93); 

                auto tg_xxxz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 94); 

                auto tg_xxxz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 95); 

                auto tg_xxxz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 96); 

                auto tg_xxxz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 97); 

                auto tg_xxxz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 98); 

                auto tg_xxxz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 99); 

                auto tg_xxxz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 100); 

                auto tg_xxxz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 101); 

                auto tg_xxxz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 102); 

                auto tg_xxxz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 103); 

                auto tg_xxxz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 104); 

                auto tg_xxxz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 105); 

                auto tg_xxxz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 106); 

                auto tg_xxxz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 107); 

                auto tg_xxyy_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 108); 

                auto tg_xxyy_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 109); 

                auto tg_xxyy_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 110); 

                auto tg_xxyy_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 111); 

                auto tg_xxyy_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 112); 

                auto tg_xxyy_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 113); 

                auto tg_xxyy_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 114); 

                auto tg_xxyy_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 115); 

                auto tg_xxyy_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 116); 

                auto tg_xxyy_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 117); 

                auto tg_xxyy_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 118); 

                auto tg_xxyy_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 119); 

                auto tg_xxyy_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 120); 

                auto tg_xxyy_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 121); 

                auto tg_xxyy_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 122); 

                auto tg_xxyy_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 123); 

                auto tg_xxyy_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 124); 

                auto tg_xxyy_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 125); 

                auto tg_xxyy_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 126); 

                auto tg_xxyy_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 127); 

                auto tg_xxyy_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 128); 

                auto tg_xxyy_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 129); 

                auto tg_xxyy_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 130); 

                auto tg_xxyy_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 131); 

                auto tg_xxyy_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 132); 

                auto tg_xxyy_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 133); 

                auto tg_xxyy_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 134); 

                auto tg_xxyy_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 135); 

                auto tg_xxyy_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 136); 

                auto tg_xxyy_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 137); 

                auto tg_xxyy_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 138); 

                auto tg_xxyy_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 139); 

                auto tg_xxyy_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 140); 

                auto tg_xxyy_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 141); 

                auto tg_xxyy_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 142); 

                auto tg_xxyy_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 143); 

                auto tg_xxyz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 144); 

                auto tg_xxyz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 145); 

                auto tg_xxyz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 146); 

                auto tg_xxyz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 147); 

                auto tg_xxyz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 148); 

                auto tg_xxyz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 149); 

                auto tg_xxyz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 150); 

                auto tg_xxyz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 151); 

                auto tg_xxyz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 152); 

                auto tg_xxyz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 153); 

                auto tg_xxyz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 154); 

                auto tg_xxyz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 155); 

                auto tg_xxyz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 156); 

                auto tg_xxyz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 157); 

                auto tg_xxyz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 158); 

                auto tg_xxyz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 159); 

                auto tg_xxyz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 160); 

                auto tg_xxyz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 161); 

                auto tg_xxyz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 162); 

                auto tg_xxyz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 163); 

                auto tg_xxyz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 164); 

                auto tg_xxyz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 165); 

                auto tg_xxyz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 166); 

                auto tg_xxyz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 167); 

                auto tg_xxyz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 168); 

                auto tg_xxyz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 169); 

                auto tg_xxyz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 170); 

                auto tg_xxyz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 171); 

                auto tg_xxyz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 172); 

                auto tg_xxyz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 173); 

                auto tg_xxyz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 174); 

                auto tg_xxyz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 175); 

                auto tg_xxyz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 176); 

                auto tg_xxyz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 177); 

                auto tg_xxyz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 178); 

                auto tg_xxyz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 179); 

                auto tg_xxzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 180); 

                auto tg_xxzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 181); 

                auto tg_xxzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 182); 

                auto tg_xxzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 183); 

                auto tg_xxxxz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 76); 

                auto tg_xxxxz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 77); 

                auto tg_xxxxz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 78); 

                auto tg_xxxxz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 79); 

                auto tg_xxxxz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 80); 

                auto tg_xxxxz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 81); 

                auto tg_xxxxz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 82); 

                auto tg_xxxxz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 83); 

                auto tg_xxxyy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 84); 

                auto tg_xxxyy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 85); 

                auto tg_xxxyy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 86); 

                auto tg_xxxyy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 87); 

                auto tg_xxxyy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 88); 

                auto tg_xxxyy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 89); 

                auto tg_xxxyy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 90); 

                auto tg_xxxyy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 91); 

                auto tg_xxxyy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 92); 

                auto tg_xxxyy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 93); 

                auto tg_xxxyy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 94); 

                auto tg_xxxyy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 95); 

                auto tg_xxxyy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 96); 

                auto tg_xxxyy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 97); 

                auto tg_xxxyy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 98); 

                auto tg_xxxyy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 99); 

                auto tg_xxxyy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 100); 

                auto tg_xxxyy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 101); 

                auto tg_xxxyy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 102); 

                auto tg_xxxyy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 103); 

                auto tg_xxxyy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 104); 

                auto tg_xxxyy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 105); 

                auto tg_xxxyy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 106); 

                auto tg_xxxyy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 107); 

                auto tg_xxxyy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 108); 

                auto tg_xxxyy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 109); 

                auto tg_xxxyy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 110); 

                auto tg_xxxyy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 111); 

                auto tg_xxxyz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 112); 

                auto tg_xxxyz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 113); 

                auto tg_xxxyz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 114); 

                auto tg_xxxyz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 115); 

                auto tg_xxxyz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 116); 

                auto tg_xxxyz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 117); 

                auto tg_xxxyz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 118); 

                auto tg_xxxyz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 119); 

                auto tg_xxxyz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 120); 

                auto tg_xxxyz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 121); 

                auto tg_xxxyz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 122); 

                auto tg_xxxyz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 123); 

                auto tg_xxxyz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 124); 

                auto tg_xxxyz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 125); 

                auto tg_xxxyz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 126); 

                auto tg_xxxyz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 127); 

                auto tg_xxxyz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 128); 

                auto tg_xxxyz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 129); 

                auto tg_xxxyz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 130); 

                auto tg_xxxyz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 131); 

                auto tg_xxxyz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 132); 

                auto tg_xxxyz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 133); 

                auto tg_xxxyz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 134); 

                auto tg_xxxyz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 135); 

                auto tg_xxxyz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 136); 

                auto tg_xxxyz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 137); 

                auto tg_xxxyz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 138); 

                auto tg_xxxyz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 139); 

                auto tg_xxxzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 140); 

                auto tg_xxxzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 141); 

                auto tg_xxxzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 142); 

                auto tg_xxxzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 143); 

                // set up pointers to integrals

                auto tg_xxxxxz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 92); 

                auto tg_xxxxxz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 93); 

                auto tg_xxxxxz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 94); 

                auto tg_xxxxxz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 95); 

                auto tg_xxxxxz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 96); 

                auto tg_xxxxxz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 97); 

                auto tg_xxxxxz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 98); 

                auto tg_xxxxxz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 99); 

                auto tg_xxxxxz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 100); 

                auto tg_xxxxxz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 101); 

                auto tg_xxxxxz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 102); 

                auto tg_xxxxxz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 103); 

                auto tg_xxxxxz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 104); 

                auto tg_xxxxxz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 105); 

                auto tg_xxxxxz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 106); 

                auto tg_xxxxxz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 107); 

                auto tg_xxxxyy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 108); 

                auto tg_xxxxyy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 109); 

                auto tg_xxxxyy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 110); 

                auto tg_xxxxyy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 111); 

                auto tg_xxxxyy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 112); 

                auto tg_xxxxyy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 113); 

                auto tg_xxxxyy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 114); 

                auto tg_xxxxyy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 115); 

                auto tg_xxxxyy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 116); 

                auto tg_xxxxyy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 117); 

                auto tg_xxxxyy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 118); 

                auto tg_xxxxyy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 119); 

                auto tg_xxxxyy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 120); 

                auto tg_xxxxyy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 121); 

                auto tg_xxxxyy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 122); 

                auto tg_xxxxyy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 123); 

                auto tg_xxxxyy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 124); 

                auto tg_xxxxyy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 125); 

                auto tg_xxxxyy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 126); 

                auto tg_xxxxyy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 127); 

                auto tg_xxxxyy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 128); 

                auto tg_xxxxyy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 129); 

                auto tg_xxxxyy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 130); 

                auto tg_xxxxyy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 131); 

                auto tg_xxxxyy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 132); 

                auto tg_xxxxyy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 133); 

                auto tg_xxxxyy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 134); 

                auto tg_xxxxyy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 135); 

                auto tg_xxxxyy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 136); 

                auto tg_xxxxyy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 137); 

                auto tg_xxxxyy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 138); 

                auto tg_xxxxyy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 139); 

                auto tg_xxxxyy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 140); 

                auto tg_xxxxyy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 141); 

                auto tg_xxxxyy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 142); 

                auto tg_xxxxyy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 143); 

                auto tg_xxxxyz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 144); 

                auto tg_xxxxyz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 145); 

                auto tg_xxxxyz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 146); 

                auto tg_xxxxyz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 147); 

                auto tg_xxxxyz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 148); 

                auto tg_xxxxyz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 149); 

                auto tg_xxxxyz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 150); 

                auto tg_xxxxyz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 151); 

                auto tg_xxxxyz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 152); 

                auto tg_xxxxyz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 153); 

                auto tg_xxxxyz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 154); 

                auto tg_xxxxyz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 155); 

                auto tg_xxxxyz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 156); 

                auto tg_xxxxyz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 157); 

                auto tg_xxxxyz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 158); 

                auto tg_xxxxyz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 159); 

                auto tg_xxxxyz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 160); 

                auto tg_xxxxyz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 161); 

                auto tg_xxxxyz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 162); 

                auto tg_xxxxyz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 163); 

                auto tg_xxxxyz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 164); 

                auto tg_xxxxyz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 165); 

                auto tg_xxxxyz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 166); 

                auto tg_xxxxyz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 167); 

                auto tg_xxxxyz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 168); 

                auto tg_xxxxyz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 169); 

                auto tg_xxxxyz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 170); 

                auto tg_xxxxyz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 171); 

                auto tg_xxxxyz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 172); 

                auto tg_xxxxyz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 173); 

                auto tg_xxxxyz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 174); 

                auto tg_xxxxyz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 175); 

                auto tg_xxxxyz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 176); 

                auto tg_xxxxyz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 177); 

                auto tg_xxxxyz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 178); 

                auto tg_xxxxyz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 179); 

                auto tg_xxxxzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 180); 

                auto tg_xxxxzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 181); 

                auto tg_xxxxzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 182); 

                auto tg_xxxxzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 183); 

                // Batch of Integrals (92,184)

                #pragma omp simd aligned(fxn, fza, tg_xxxxxz_xxzzzzz_0, tg_xxxxxz_xyyyyyy_0, \
                                         tg_xxxxxz_xyyyyyz_0, tg_xxxxxz_xyyyyzz_0, tg_xxxxxz_xyyyzzz_0, tg_xxxxxz_xyyzzzz_0, \
                                         tg_xxxxxz_xyzzzzz_0, tg_xxxxxz_xzzzzzz_0, tg_xxxxxz_yyyyyyy_0, tg_xxxxxz_yyyyyyz_0, \
                                         tg_xxxxxz_yyyyyzz_0, tg_xxxxxz_yyyyzzz_0, tg_xxxxxz_yyyzzzz_0, tg_xxxxxz_yyzzzzz_0, \
                                         tg_xxxxxz_yzzzzzz_0, tg_xxxxxz_zzzzzzz_0, tg_xxxxyy_xxxxxxx_0, tg_xxxxyy_xxxxxxy_0, \
                                         tg_xxxxyy_xxxxxxz_0, tg_xxxxyy_xxxxxyy_0, tg_xxxxyy_xxxxxyz_0, tg_xxxxyy_xxxxxzz_0, \
                                         tg_xxxxyy_xxxxyyy_0, tg_xxxxyy_xxxxyyz_0, tg_xxxxyy_xxxxyzz_0, tg_xxxxyy_xxxxzzz_0, \
                                         tg_xxxxyy_xxxyyyy_0, tg_xxxxyy_xxxyyyz_0, tg_xxxxyy_xxxyyzz_0, tg_xxxxyy_xxxyzzz_0, \
                                         tg_xxxxyy_xxxzzzz_0, tg_xxxxyy_xxyyyyy_0, tg_xxxxyy_xxyyyyz_0, tg_xxxxyy_xxyyyzz_0, \
                                         tg_xxxxyy_xxyyzzz_0, tg_xxxxyy_xxyzzzz_0, tg_xxxxyy_xxzzzzz_0, tg_xxxxyy_xyyyyyy_0, \
                                         tg_xxxxyy_xyyyyyz_0, tg_xxxxyy_xyyyyzz_0, tg_xxxxyy_xyyyzzz_0, tg_xxxxyy_xyyzzzz_0, \
                                         tg_xxxxyy_xyzzzzz_0, tg_xxxxyy_xzzzzzz_0, tg_xxxxyy_yyyyyyy_0, tg_xxxxyy_yyyyyyz_0, \
                                         tg_xxxxyy_yyyyyzz_0, tg_xxxxyy_yyyyzzz_0, tg_xxxxyy_yyyzzzz_0, tg_xxxxyy_yyzzzzz_0, \
                                         tg_xxxxyy_yzzzzzz_0, tg_xxxxyy_zzzzzzz_0, tg_xxxxyz_xxxxxxx_0, tg_xxxxyz_xxxxxxy_0, \
                                         tg_xxxxyz_xxxxxxz_0, tg_xxxxyz_xxxxxyy_0, tg_xxxxyz_xxxxxyz_0, tg_xxxxyz_xxxxxzz_0, \
                                         tg_xxxxyz_xxxxyyy_0, tg_xxxxyz_xxxxyyz_0, tg_xxxxyz_xxxxyzz_0, tg_xxxxyz_xxxxzzz_0, \
                                         tg_xxxxyz_xxxyyyy_0, tg_xxxxyz_xxxyyyz_0, tg_xxxxyz_xxxyyzz_0, tg_xxxxyz_xxxyzzz_0, \
                                         tg_xxxxyz_xxxzzzz_0, tg_xxxxyz_xxyyyyy_0, tg_xxxxyz_xxyyyyz_0, tg_xxxxyz_xxyyyzz_0, \
                                         tg_xxxxyz_xxyyzzz_0, tg_xxxxyz_xxyzzzz_0, tg_xxxxyz_xxzzzzz_0, tg_xxxxyz_xyyyyyy_0, \
                                         tg_xxxxyz_xyyyyyz_0, tg_xxxxyz_xyyyyzz_0, tg_xxxxyz_xyyyzzz_0, tg_xxxxyz_xyyzzzz_0, \
                                         tg_xxxxyz_xyzzzzz_0, tg_xxxxyz_xzzzzzz_0, tg_xxxxyz_yyyyyyy_0, tg_xxxxyz_yyyyyyz_0, \
                                         tg_xxxxyz_yyyyyzz_0, tg_xxxxyz_yyyyzzz_0, tg_xxxxyz_yyyzzzz_0, tg_xxxxyz_yyzzzzz_0, \
                                         tg_xxxxyz_yzzzzzz_0, tg_xxxxyz_zzzzzzz_0, tg_xxxxz_xxzzzzz_0, tg_xxxxz_xxzzzzz_1, \
                                         tg_xxxxz_xyyyyyy_0, tg_xxxxz_xyyyyyy_1, tg_xxxxz_xyyyyyz_0, tg_xxxxz_xyyyyyz_1, \
                                         tg_xxxxz_xyyyyzz_0, tg_xxxxz_xyyyyzz_1, tg_xxxxz_xyyyzzz_0, tg_xxxxz_xyyyzzz_1, \
                                         tg_xxxxz_xyyzzzz_0, tg_xxxxz_xyyzzzz_1, tg_xxxxz_xyzzzzz_0, tg_xxxxz_xyzzzzz_1, \
                                         tg_xxxxz_xzzzzz_1, tg_xxxxz_xzzzzzz_0, tg_xxxxz_xzzzzzz_1, tg_xxxxz_yyyyyy_1, \
                                         tg_xxxxz_yyyyyyy_0, tg_xxxxz_yyyyyyy_1, tg_xxxxz_yyyyyyz_0, tg_xxxxz_yyyyyyz_1, \
                                         tg_xxxxz_yyyyyz_1, tg_xxxxz_yyyyyzz_0, tg_xxxxz_yyyyyzz_1, tg_xxxxz_yyyyzz_1, \
                                         tg_xxxxz_yyyyzzz_0, tg_xxxxz_yyyyzzz_1, tg_xxxxz_yyyzzz_1, tg_xxxxz_yyyzzzz_0, \
                                         tg_xxxxz_yyyzzzz_1, tg_xxxxz_yyzzzz_1, tg_xxxxz_yyzzzzz_0, tg_xxxxz_yyzzzzz_1, \
                                         tg_xxxxz_yzzzzz_1, tg_xxxxz_yzzzzzz_0, tg_xxxxz_yzzzzzz_1, tg_xxxxz_zzzzzz_1, \
                                         tg_xxxxz_zzzzzzz_0, tg_xxxxz_zzzzzzz_1, tg_xxxxzz_xxxxxxx_0, tg_xxxxzz_xxxxxxy_0, \
                                         tg_xxxxzz_xxxxxxz_0, tg_xxxxzz_xxxxxyy_0, tg_xxxyy_xxxxxx_1, tg_xxxyy_xxxxxxx_0, \
                                         tg_xxxyy_xxxxxxx_1, tg_xxxyy_xxxxxxy_0, tg_xxxyy_xxxxxxy_1, tg_xxxyy_xxxxxxz_0, \
                                         tg_xxxyy_xxxxxxz_1, tg_xxxyy_xxxxxy_1, tg_xxxyy_xxxxxyy_0, tg_xxxyy_xxxxxyy_1, \
                                         tg_xxxyy_xxxxxyz_0, tg_xxxyy_xxxxxyz_1, tg_xxxyy_xxxxxz_1, tg_xxxyy_xxxxxzz_0, \
                                         tg_xxxyy_xxxxxzz_1, tg_xxxyy_xxxxyy_1, tg_xxxyy_xxxxyyy_0, tg_xxxyy_xxxxyyy_1, \
                                         tg_xxxyy_xxxxyyz_0, tg_xxxyy_xxxxyyz_1, tg_xxxyy_xxxxyz_1, tg_xxxyy_xxxxyzz_0, \
                                         tg_xxxyy_xxxxyzz_1, tg_xxxyy_xxxxzz_1, tg_xxxyy_xxxxzzz_0, tg_xxxyy_xxxxzzz_1, \
                                         tg_xxxyy_xxxyyy_1, tg_xxxyy_xxxyyyy_0, tg_xxxyy_xxxyyyy_1, tg_xxxyy_xxxyyyz_0, \
                                         tg_xxxyy_xxxyyyz_1, tg_xxxyy_xxxyyz_1, tg_xxxyy_xxxyyzz_0, tg_xxxyy_xxxyyzz_1, \
                                         tg_xxxyy_xxxyzz_1, tg_xxxyy_xxxyzzz_0, tg_xxxyy_xxxyzzz_1, tg_xxxyy_xxxzzz_1, \
                                         tg_xxxyy_xxxzzzz_0, tg_xxxyy_xxxzzzz_1, tg_xxxyy_xxyyyy_1, tg_xxxyy_xxyyyyy_0, \
                                         tg_xxxyy_xxyyyyy_1, tg_xxxyy_xxyyyyz_0, tg_xxxyy_xxyyyyz_1, tg_xxxyy_xxyyyz_1, \
                                         tg_xxxyy_xxyyyzz_0, tg_xxxyy_xxyyyzz_1, tg_xxxyy_xxyyzz_1, tg_xxxyy_xxyyzzz_0, \
                                         tg_xxxyy_xxyyzzz_1, tg_xxxyy_xxyzzz_1, tg_xxxyy_xxyzzzz_0, tg_xxxyy_xxyzzzz_1, \
                                         tg_xxxyy_xxzzzz_1, tg_xxxyy_xxzzzzz_0, tg_xxxyy_xxzzzzz_1, tg_xxxyy_xyyyyy_1, \
                                         tg_xxxyy_xyyyyyy_0, tg_xxxyy_xyyyyyy_1, tg_xxxyy_xyyyyyz_0, tg_xxxyy_xyyyyyz_1, \
                                         tg_xxxyy_xyyyyz_1, tg_xxxyy_xyyyyzz_0, tg_xxxyy_xyyyyzz_1, tg_xxxyy_xyyyzz_1, \
                                         tg_xxxyy_xyyyzzz_0, tg_xxxyy_xyyyzzz_1, tg_xxxyy_xyyzzz_1, tg_xxxyy_xyyzzzz_0, \
                                         tg_xxxyy_xyyzzzz_1, tg_xxxyy_xyzzzz_1, tg_xxxyy_xyzzzzz_0, tg_xxxyy_xyzzzzz_1, \
                                         tg_xxxyy_xzzzzz_1, tg_xxxyy_xzzzzzz_0, tg_xxxyy_xzzzzzz_1, tg_xxxyy_yyyyyy_1, \
                                         tg_xxxyy_yyyyyyy_0, tg_xxxyy_yyyyyyy_1, tg_xxxyy_yyyyyyz_0, tg_xxxyy_yyyyyyz_1, \
                                         tg_xxxyy_yyyyyz_1, tg_xxxyy_yyyyyzz_0, tg_xxxyy_yyyyyzz_1, tg_xxxyy_yyyyzz_1, \
                                         tg_xxxyy_yyyyzzz_0, tg_xxxyy_yyyyzzz_1, tg_xxxyy_yyyzzz_1, tg_xxxyy_yyyzzzz_0, \
                                         tg_xxxyy_yyyzzzz_1, tg_xxxyy_yyzzzz_1, tg_xxxyy_yyzzzzz_0, tg_xxxyy_yyzzzzz_1, \
                                         tg_xxxyy_yzzzzz_1, tg_xxxyy_yzzzzzz_0, tg_xxxyy_yzzzzzz_1, tg_xxxyy_zzzzzz_1, \
                                         tg_xxxyy_zzzzzzz_0, tg_xxxyy_zzzzzzz_1, tg_xxxyz_xxxxxx_1, tg_xxxyz_xxxxxxx_0, \
                                         tg_xxxyz_xxxxxxx_1, tg_xxxyz_xxxxxxy_0, tg_xxxyz_xxxxxxy_1, tg_xxxyz_xxxxxxz_0, \
                                         tg_xxxyz_xxxxxxz_1, tg_xxxyz_xxxxxy_1, tg_xxxyz_xxxxxyy_0, tg_xxxyz_xxxxxyy_1, \
                                         tg_xxxyz_xxxxxyz_0, tg_xxxyz_xxxxxyz_1, tg_xxxyz_xxxxxz_1, tg_xxxyz_xxxxxzz_0, \
                                         tg_xxxyz_xxxxxzz_1, tg_xxxyz_xxxxyy_1, tg_xxxyz_xxxxyyy_0, tg_xxxyz_xxxxyyy_1, \
                                         tg_xxxyz_xxxxyyz_0, tg_xxxyz_xxxxyyz_1, tg_xxxyz_xxxxyz_1, tg_xxxyz_xxxxyzz_0, \
                                         tg_xxxyz_xxxxyzz_1, tg_xxxyz_xxxxzz_1, tg_xxxyz_xxxxzzz_0, tg_xxxyz_xxxxzzz_1, \
                                         tg_xxxyz_xxxyyy_1, tg_xxxyz_xxxyyyy_0, tg_xxxyz_xxxyyyy_1, tg_xxxyz_xxxyyyz_0, \
                                         tg_xxxyz_xxxyyyz_1, tg_xxxyz_xxxyyz_1, tg_xxxyz_xxxyyzz_0, tg_xxxyz_xxxyyzz_1, \
                                         tg_xxxyz_xxxyzz_1, tg_xxxyz_xxxyzzz_0, tg_xxxyz_xxxyzzz_1, tg_xxxyz_xxxzzz_1, \
                                         tg_xxxyz_xxxzzzz_0, tg_xxxyz_xxxzzzz_1, tg_xxxyz_xxyyyy_1, tg_xxxyz_xxyyyyy_0, \
                                         tg_xxxyz_xxyyyyy_1, tg_xxxyz_xxyyyyz_0, tg_xxxyz_xxyyyyz_1, tg_xxxyz_xxyyyz_1, \
                                         tg_xxxyz_xxyyyzz_0, tg_xxxyz_xxyyyzz_1, tg_xxxyz_xxyyzz_1, tg_xxxyz_xxyyzzz_0, \
                                         tg_xxxyz_xxyyzzz_1, tg_xxxyz_xxyzzz_1, tg_xxxyz_xxyzzzz_0, tg_xxxyz_xxyzzzz_1, \
                                         tg_xxxyz_xxzzzz_1, tg_xxxyz_xxzzzzz_0, tg_xxxyz_xxzzzzz_1, tg_xxxyz_xyyyyy_1, \
                                         tg_xxxyz_xyyyyyy_0, tg_xxxyz_xyyyyyy_1, tg_xxxyz_xyyyyyz_0, tg_xxxyz_xyyyyyz_1, \
                                         tg_xxxyz_xyyyyz_1, tg_xxxyz_xyyyyzz_0, tg_xxxyz_xyyyyzz_1, tg_xxxyz_xyyyzz_1, \
                                         tg_xxxyz_xyyyzzz_0, tg_xxxyz_xyyyzzz_1, tg_xxxyz_xyyzzz_1, tg_xxxyz_xyyzzzz_0, \
                                         tg_xxxyz_xyyzzzz_1, tg_xxxyz_xyzzzz_1, tg_xxxyz_xyzzzzz_0, tg_xxxyz_xyzzzzz_1, \
                                         tg_xxxyz_xzzzzz_1, tg_xxxyz_xzzzzzz_0, tg_xxxyz_xzzzzzz_1, tg_xxxyz_yyyyyy_1, \
                                         tg_xxxyz_yyyyyyy_0, tg_xxxyz_yyyyyyy_1, tg_xxxyz_yyyyyyz_0, tg_xxxyz_yyyyyyz_1, \
                                         tg_xxxyz_yyyyyz_1, tg_xxxyz_yyyyyzz_0, tg_xxxyz_yyyyyzz_1, tg_xxxyz_yyyyzz_1, \
                                         tg_xxxyz_yyyyzzz_0, tg_xxxyz_yyyyzzz_1, tg_xxxyz_yyyzzz_1, tg_xxxyz_yyyzzzz_0, \
                                         tg_xxxyz_yyyzzzz_1, tg_xxxyz_yyzzzz_1, tg_xxxyz_yyzzzzz_0, tg_xxxyz_yyzzzzz_1, \
                                         tg_xxxyz_yzzzzz_1, tg_xxxyz_yzzzzzz_0, tg_xxxyz_yzzzzzz_1, tg_xxxyz_zzzzzz_1, \
                                         tg_xxxyz_zzzzzzz_0, tg_xxxyz_zzzzzzz_1, tg_xxxz_xxzzzzz_0, tg_xxxz_xxzzzzz_1, \
                                         tg_xxxz_xyyyyyy_0, tg_xxxz_xyyyyyy_1, tg_xxxz_xyyyyyz_0, tg_xxxz_xyyyyyz_1, \
                                         tg_xxxz_xyyyyzz_0, tg_xxxz_xyyyyzz_1, tg_xxxz_xyyyzzz_0, tg_xxxz_xyyyzzz_1, \
                                         tg_xxxz_xyyzzzz_0, tg_xxxz_xyyzzzz_1, tg_xxxz_xyzzzzz_0, tg_xxxz_xyzzzzz_1, \
                                         tg_xxxz_xzzzzzz_0, tg_xxxz_xzzzzzz_1, tg_xxxz_yyyyyyy_0, tg_xxxz_yyyyyyy_1, \
                                         tg_xxxz_yyyyyyz_0, tg_xxxz_yyyyyyz_1, tg_xxxz_yyyyyzz_0, tg_xxxz_yyyyyzz_1, \
                                         tg_xxxz_yyyyzzz_0, tg_xxxz_yyyyzzz_1, tg_xxxz_yyyzzzz_0, tg_xxxz_yyyzzzz_1, \
                                         tg_xxxz_yyzzzzz_0, tg_xxxz_yyzzzzz_1, tg_xxxz_yzzzzzz_0, tg_xxxz_yzzzzzz_1, \
                                         tg_xxxz_zzzzzzz_0, tg_xxxz_zzzzzzz_1, tg_xxxzz_xxxxxx_1, tg_xxxzz_xxxxxxx_0, \
                                         tg_xxxzz_xxxxxxx_1, tg_xxxzz_xxxxxxy_0, tg_xxxzz_xxxxxxy_1, tg_xxxzz_xxxxxxz_0, \
                                         tg_xxxzz_xxxxxxz_1, tg_xxxzz_xxxxxy_1, tg_xxxzz_xxxxxyy_0, tg_xxxzz_xxxxxyy_1, \
                                         tg_xxxzz_xxxxxz_1, tg_xxxzz_xxxxyy_1, tg_xxyy_xxxxxxx_0, tg_xxyy_xxxxxxx_1, \
                                         tg_xxyy_xxxxxxy_0, tg_xxyy_xxxxxxy_1, tg_xxyy_xxxxxxz_0, tg_xxyy_xxxxxxz_1, \
                                         tg_xxyy_xxxxxyy_0, tg_xxyy_xxxxxyy_1, tg_xxyy_xxxxxyz_0, tg_xxyy_xxxxxyz_1, \
                                         tg_xxyy_xxxxxzz_0, tg_xxyy_xxxxxzz_1, tg_xxyy_xxxxyyy_0, tg_xxyy_xxxxyyy_1, \
                                         tg_xxyy_xxxxyyz_0, tg_xxyy_xxxxyyz_1, tg_xxyy_xxxxyzz_0, tg_xxyy_xxxxyzz_1, \
                                         tg_xxyy_xxxxzzz_0, tg_xxyy_xxxxzzz_1, tg_xxyy_xxxyyyy_0, tg_xxyy_xxxyyyy_1, \
                                         tg_xxyy_xxxyyyz_0, tg_xxyy_xxxyyyz_1, tg_xxyy_xxxyyzz_0, tg_xxyy_xxxyyzz_1, \
                                         tg_xxyy_xxxyzzz_0, tg_xxyy_xxxyzzz_1, tg_xxyy_xxxzzzz_0, tg_xxyy_xxxzzzz_1, \
                                         tg_xxyy_xxyyyyy_0, tg_xxyy_xxyyyyy_1, tg_xxyy_xxyyyyz_0, tg_xxyy_xxyyyyz_1, \
                                         tg_xxyy_xxyyyzz_0, tg_xxyy_xxyyyzz_1, tg_xxyy_xxyyzzz_0, tg_xxyy_xxyyzzz_1, \
                                         tg_xxyy_xxyzzzz_0, tg_xxyy_xxyzzzz_1, tg_xxyy_xxzzzzz_0, tg_xxyy_xxzzzzz_1, \
                                         tg_xxyy_xyyyyyy_0, tg_xxyy_xyyyyyy_1, tg_xxyy_xyyyyyz_0, tg_xxyy_xyyyyyz_1, \
                                         tg_xxyy_xyyyyzz_0, tg_xxyy_xyyyyzz_1, tg_xxyy_xyyyzzz_0, tg_xxyy_xyyyzzz_1, \
                                         tg_xxyy_xyyzzzz_0, tg_xxyy_xyyzzzz_1, tg_xxyy_xyzzzzz_0, tg_xxyy_xyzzzzz_1, \
                                         tg_xxyy_xzzzzzz_0, tg_xxyy_xzzzzzz_1, tg_xxyy_yyyyyyy_0, tg_xxyy_yyyyyyy_1, \
                                         tg_xxyy_yyyyyyz_0, tg_xxyy_yyyyyyz_1, tg_xxyy_yyyyyzz_0, tg_xxyy_yyyyyzz_1, \
                                         tg_xxyy_yyyyzzz_0, tg_xxyy_yyyyzzz_1, tg_xxyy_yyyzzzz_0, tg_xxyy_yyyzzzz_1, \
                                         tg_xxyy_yyzzzzz_0, tg_xxyy_yyzzzzz_1, tg_xxyy_yzzzzzz_0, tg_xxyy_yzzzzzz_1, \
                                         tg_xxyy_zzzzzzz_0, tg_xxyy_zzzzzzz_1, tg_xxyz_xxxxxxx_0, tg_xxyz_xxxxxxx_1, \
                                         tg_xxyz_xxxxxxy_0, tg_xxyz_xxxxxxy_1, tg_xxyz_xxxxxxz_0, tg_xxyz_xxxxxxz_1, \
                                         tg_xxyz_xxxxxyy_0, tg_xxyz_xxxxxyy_1, tg_xxyz_xxxxxyz_0, tg_xxyz_xxxxxyz_1, \
                                         tg_xxyz_xxxxxzz_0, tg_xxyz_xxxxxzz_1, tg_xxyz_xxxxyyy_0, tg_xxyz_xxxxyyy_1, \
                                         tg_xxyz_xxxxyyz_0, tg_xxyz_xxxxyyz_1, tg_xxyz_xxxxyzz_0, tg_xxyz_xxxxyzz_1, \
                                         tg_xxyz_xxxxzzz_0, tg_xxyz_xxxxzzz_1, tg_xxyz_xxxyyyy_0, tg_xxyz_xxxyyyy_1, \
                                         tg_xxyz_xxxyyyz_0, tg_xxyz_xxxyyyz_1, tg_xxyz_xxxyyzz_0, tg_xxyz_xxxyyzz_1, \
                                         tg_xxyz_xxxyzzz_0, tg_xxyz_xxxyzzz_1, tg_xxyz_xxxzzzz_0, tg_xxyz_xxxzzzz_1, \
                                         tg_xxyz_xxyyyyy_0, tg_xxyz_xxyyyyy_1, tg_xxyz_xxyyyyz_0, tg_xxyz_xxyyyyz_1, \
                                         tg_xxyz_xxyyyzz_0, tg_xxyz_xxyyyzz_1, tg_xxyz_xxyyzzz_0, tg_xxyz_xxyyzzz_1, \
                                         tg_xxyz_xxyzzzz_0, tg_xxyz_xxyzzzz_1, tg_xxyz_xxzzzzz_0, tg_xxyz_xxzzzzz_1, \
                                         tg_xxyz_xyyyyyy_0, tg_xxyz_xyyyyyy_1, tg_xxyz_xyyyyyz_0, tg_xxyz_xyyyyyz_1, \
                                         tg_xxyz_xyyyyzz_0, tg_xxyz_xyyyyzz_1, tg_xxyz_xyyyzzz_0, tg_xxyz_xyyyzzz_1, \
                                         tg_xxyz_xyyzzzz_0, tg_xxyz_xyyzzzz_1, tg_xxyz_xyzzzzz_0, tg_xxyz_xyzzzzz_1, \
                                         tg_xxyz_xzzzzzz_0, tg_xxyz_xzzzzzz_1, tg_xxyz_yyyyyyy_0, tg_xxyz_yyyyyyy_1, \
                                         tg_xxyz_yyyyyyz_0, tg_xxyz_yyyyyyz_1, tg_xxyz_yyyyyzz_0, tg_xxyz_yyyyyzz_1, \
                                         tg_xxyz_yyyyzzz_0, tg_xxyz_yyyyzzz_1, tg_xxyz_yyyzzzz_0, tg_xxyz_yyyzzzz_1, \
                                         tg_xxyz_yyzzzzz_0, tg_xxyz_yyzzzzz_1, tg_xxyz_yzzzzzz_0, tg_xxyz_yzzzzzz_1, \
                                         tg_xxyz_zzzzzzz_0, tg_xxyz_zzzzzzz_1, tg_xxzz_xxxxxxx_0, tg_xxzz_xxxxxxx_1, \
                                         tg_xxzz_xxxxxxy_0, tg_xxzz_xxxxxxy_1, tg_xxzz_xxxxxxz_0, tg_xxzz_xxxxxxz_1, \
                                         tg_xxzz_xxxxxyy_0, tg_xxzz_xxxxxyy_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxxxz_xxzzzzz_0[j] = pb_x * tg_xxxxz_xxzzzzz_0[j] + fr * tg_xxxxz_xxzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xxzzzzz_0[j] - tg_xxxz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxxz_xzzzzz_1[j];

                    tg_xxxxxz_xyyyyyy_0[j] = pb_x * tg_xxxxz_xyyyyyy_0[j] + fr * tg_xxxxz_xyyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyyyyyy_0[j] - tg_xxxz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yyyyyy_1[j];

                    tg_xxxxxz_xyyyyyz_0[j] = pb_x * tg_xxxxz_xyyyyyz_0[j] + fr * tg_xxxxz_xyyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyyyyyz_0[j] - tg_xxxz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yyyyyz_1[j];

                    tg_xxxxxz_xyyyyzz_0[j] = pb_x * tg_xxxxz_xyyyyzz_0[j] + fr * tg_xxxxz_xyyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyyyyzz_0[j] - tg_xxxz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yyyyzz_1[j];

                    tg_xxxxxz_xyyyzzz_0[j] = pb_x * tg_xxxxz_xyyyzzz_0[j] + fr * tg_xxxxz_xyyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyyyzzz_0[j] - tg_xxxz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yyyzzz_1[j];

                    tg_xxxxxz_xyyzzzz_0[j] = pb_x * tg_xxxxz_xyyzzzz_0[j] + fr * tg_xxxxz_xyyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyyzzzz_0[j] - tg_xxxz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yyzzzz_1[j];

                    tg_xxxxxz_xyzzzzz_0[j] = pb_x * tg_xxxxz_xyzzzzz_0[j] + fr * tg_xxxxz_xyzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xyzzzzz_0[j] - tg_xxxz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_yzzzzz_1[j];

                    tg_xxxxxz_xzzzzzz_0[j] = pb_x * tg_xxxxz_xzzzzzz_0[j] + fr * tg_xxxxz_xzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_xzzzzzz_0[j] - tg_xxxz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxxz_zzzzzz_1[j];

                    tg_xxxxxz_yyyyyyy_0[j] = pb_x * tg_xxxxz_yyyyyyy_0[j] + fr * tg_xxxxz_yyyyyyy_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyyyyyy_0[j] - tg_xxxz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxxz_yyyyyyz_0[j] = pb_x * tg_xxxxz_yyyyyyz_0[j] + fr * tg_xxxxz_yyyyyyz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyyyyyz_0[j] - tg_xxxz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxxz_yyyyyzz_0[j] = pb_x * tg_xxxxz_yyyyyzz_0[j] + fr * tg_xxxxz_yyyyyzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyyyyzz_0[j] - tg_xxxz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxxz_yyyyzzz_0[j] = pb_x * tg_xxxxz_yyyyzzz_0[j] + fr * tg_xxxxz_yyyyzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyyyzzz_0[j] - tg_xxxz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxxz_yyyzzzz_0[j] = pb_x * tg_xxxxz_yyyzzzz_0[j] + fr * tg_xxxxz_yyyzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyyzzzz_0[j] - tg_xxxz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxxz_yyzzzzz_0[j] = pb_x * tg_xxxxz_yyzzzzz_0[j] + fr * tg_xxxxz_yyzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yyzzzzz_0[j] - tg_xxxz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxxz_yzzzzzz_0[j] = pb_x * tg_xxxxz_yzzzzzz_0[j] + fr * tg_xxxxz_yzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_yzzzzzz_0[j] - tg_xxxz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxxz_zzzzzzz_0[j] = pb_x * tg_xxxxz_zzzzzzz_0[j] + fr * tg_xxxxz_zzzzzzz_1[j] + 2.0 * fl1_fx * (tg_xxxz_zzzzzzz_0[j] - tg_xxxz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxxyy_xxxxxxx_0[j] = pb_x * tg_xxxyy_xxxxxxx_0[j] + fr * tg_xxxyy_xxxxxxx_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxxx_0[j] - tg_xxyy_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxyy_xxxxxx_1[j];

                    tg_xxxxyy_xxxxxxy_0[j] = pb_x * tg_xxxyy_xxxxxxy_0[j] + fr * tg_xxxyy_xxxxxxy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxxy_0[j] - tg_xxyy_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxyy_xxxxxy_1[j];

                    tg_xxxxyy_xxxxxxz_0[j] = pb_x * tg_xxxyy_xxxxxxz_0[j] + fr * tg_xxxyy_xxxxxxz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxxz_0[j] - tg_xxyy_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxyy_xxxxxz_1[j];

                    tg_xxxxyy_xxxxxyy_0[j] = pb_x * tg_xxxyy_xxxxxyy_0[j] + fr * tg_xxxyy_xxxxxyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxyy_0[j] - tg_xxyy_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyy_xxxxyy_1[j];

                    tg_xxxxyy_xxxxxyz_0[j] = pb_x * tg_xxxyy_xxxxxyz_0[j] + fr * tg_xxxyy_xxxxxyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxyz_0[j] - tg_xxyy_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyy_xxxxyz_1[j];

                    tg_xxxxyy_xxxxxzz_0[j] = pb_x * tg_xxxyy_xxxxxzz_0[j] + fr * tg_xxxyy_xxxxxzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxxzz_0[j] - tg_xxyy_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyy_xxxxzz_1[j];

                    tg_xxxxyy_xxxxyyy_0[j] = pb_x * tg_xxxyy_xxxxyyy_0[j] + fr * tg_xxxyy_xxxxyyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxyyy_0[j] - tg_xxyy_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyy_xxxyyy_1[j];

                    tg_xxxxyy_xxxxyyz_0[j] = pb_x * tg_xxxyy_xxxxyyz_0[j] + fr * tg_xxxyy_xxxxyyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxyyz_0[j] - tg_xxyy_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyy_xxxyyz_1[j];

                    tg_xxxxyy_xxxxyzz_0[j] = pb_x * tg_xxxyy_xxxxyzz_0[j] + fr * tg_xxxyy_xxxxyzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxyzz_0[j] - tg_xxyy_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyy_xxxyzz_1[j];

                    tg_xxxxyy_xxxxzzz_0[j] = pb_x * tg_xxxyy_xxxxzzz_0[j] + fr * tg_xxxyy_xxxxzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxxzzz_0[j] - tg_xxyy_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyy_xxxzzz_1[j];

                    tg_xxxxyy_xxxyyyy_0[j] = pb_x * tg_xxxyy_xxxyyyy_0[j] + fr * tg_xxxyy_xxxyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxyyyy_0[j] - tg_xxyy_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xxyyyy_1[j];

                    tg_xxxxyy_xxxyyyz_0[j] = pb_x * tg_xxxyy_xxxyyyz_0[j] + fr * tg_xxxyy_xxxyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxyyyz_0[j] - tg_xxyy_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xxyyyz_1[j];

                    tg_xxxxyy_xxxyyzz_0[j] = pb_x * tg_xxxyy_xxxyyzz_0[j] + fr * tg_xxxyy_xxxyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxyyzz_0[j] - tg_xxyy_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xxyyzz_1[j];

                    tg_xxxxyy_xxxyzzz_0[j] = pb_x * tg_xxxyy_xxxyzzz_0[j] + fr * tg_xxxyy_xxxyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxyzzz_0[j] - tg_xxyy_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xxyzzz_1[j];

                    tg_xxxxyy_xxxzzzz_0[j] = pb_x * tg_xxxyy_xxxzzzz_0[j] + fr * tg_xxxyy_xxxzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxxzzzz_0[j] - tg_xxyy_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyy_xxzzzz_1[j];

                    tg_xxxxyy_xxyyyyy_0[j] = pb_x * tg_xxxyy_xxyyyyy_0[j] + fr * tg_xxxyy_xxyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxyyyyy_0[j] - tg_xxyy_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xyyyyy_1[j];

                    tg_xxxxyy_xxyyyyz_0[j] = pb_x * tg_xxxyy_xxyyyyz_0[j] + fr * tg_xxxyy_xxyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxyyyyz_0[j] - tg_xxyy_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xyyyyz_1[j];

                    tg_xxxxyy_xxyyyzz_0[j] = pb_x * tg_xxxyy_xxyyyzz_0[j] + fr * tg_xxxyy_xxyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxyyyzz_0[j] - tg_xxyy_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xyyyzz_1[j];

                    tg_xxxxyy_xxyyzzz_0[j] = pb_x * tg_xxxyy_xxyyzzz_0[j] + fr * tg_xxxyy_xxyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxyyzzz_0[j] - tg_xxyy_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xyyzzz_1[j];

                    tg_xxxxyy_xxyzzzz_0[j] = pb_x * tg_xxxyy_xxyzzzz_0[j] + fr * tg_xxxyy_xxyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxyzzzz_0[j] - tg_xxyy_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xyzzzz_1[j];

                    tg_xxxxyy_xxzzzzz_0[j] = pb_x * tg_xxxyy_xxzzzzz_0[j] + fr * tg_xxxyy_xxzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xxzzzzz_0[j] - tg_xxyy_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyy_xzzzzz_1[j];

                    tg_xxxxyy_xyyyyyy_0[j] = pb_x * tg_xxxyy_xyyyyyy_0[j] + fr * tg_xxxyy_xyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyyyyyy_0[j] - tg_xxyy_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yyyyyy_1[j];

                    tg_xxxxyy_xyyyyyz_0[j] = pb_x * tg_xxxyy_xyyyyyz_0[j] + fr * tg_xxxyy_xyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyyyyyz_0[j] - tg_xxyy_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yyyyyz_1[j];

                    tg_xxxxyy_xyyyyzz_0[j] = pb_x * tg_xxxyy_xyyyyzz_0[j] + fr * tg_xxxyy_xyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyyyyzz_0[j] - tg_xxyy_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yyyyzz_1[j];

                    tg_xxxxyy_xyyyzzz_0[j] = pb_x * tg_xxxyy_xyyyzzz_0[j] + fr * tg_xxxyy_xyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyyyzzz_0[j] - tg_xxyy_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yyyzzz_1[j];

                    tg_xxxxyy_xyyzzzz_0[j] = pb_x * tg_xxxyy_xyyzzzz_0[j] + fr * tg_xxxyy_xyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyyzzzz_0[j] - tg_xxyy_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yyzzzz_1[j];

                    tg_xxxxyy_xyzzzzz_0[j] = pb_x * tg_xxxyy_xyzzzzz_0[j] + fr * tg_xxxyy_xyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xyzzzzz_0[j] - tg_xxyy_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_yzzzzz_1[j];

                    tg_xxxxyy_xzzzzzz_0[j] = pb_x * tg_xxxyy_xzzzzzz_0[j] + fr * tg_xxxyy_xzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_xzzzzzz_0[j] - tg_xxyy_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyy_zzzzzz_1[j];

                    tg_xxxxyy_yyyyyyy_0[j] = pb_x * tg_xxxyy_yyyyyyy_0[j] + fr * tg_xxxyy_yyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyyyyyy_0[j] - tg_xxyy_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxyy_yyyyyyz_0[j] = pb_x * tg_xxxyy_yyyyyyz_0[j] + fr * tg_xxxyy_yyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyyyyyz_0[j] - tg_xxyy_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxyy_yyyyyzz_0[j] = pb_x * tg_xxxyy_yyyyyzz_0[j] + fr * tg_xxxyy_yyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyyyyzz_0[j] - tg_xxyy_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxyy_yyyyzzz_0[j] = pb_x * tg_xxxyy_yyyyzzz_0[j] + fr * tg_xxxyy_yyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyyyzzz_0[j] - tg_xxyy_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxyy_yyyzzzz_0[j] = pb_x * tg_xxxyy_yyyzzzz_0[j] + fr * tg_xxxyy_yyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyyzzzz_0[j] - tg_xxyy_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxyy_yyzzzzz_0[j] = pb_x * tg_xxxyy_yyzzzzz_0[j] + fr * tg_xxxyy_yyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yyzzzzz_0[j] - tg_xxyy_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxyy_yzzzzzz_0[j] = pb_x * tg_xxxyy_yzzzzzz_0[j] + fr * tg_xxxyy_yzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_yzzzzzz_0[j] - tg_xxyy_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxyy_zzzzzzz_0[j] = pb_x * tg_xxxyy_zzzzzzz_0[j] + fr * tg_xxxyy_zzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyy_zzzzzzz_0[j] - tg_xxyy_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxxyz_xxxxxxx_0[j] = pb_x * tg_xxxyz_xxxxxxx_0[j] + fr * tg_xxxyz_xxxxxxx_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxxx_0[j] - tg_xxyz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxyz_xxxxxx_1[j];

                    tg_xxxxyz_xxxxxxy_0[j] = pb_x * tg_xxxyz_xxxxxxy_0[j] + fr * tg_xxxyz_xxxxxxy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxxy_0[j] - tg_xxyz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxyz_xxxxxy_1[j];

                    tg_xxxxyz_xxxxxxz_0[j] = pb_x * tg_xxxyz_xxxxxxz_0[j] + fr * tg_xxxyz_xxxxxxz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxxz_0[j] - tg_xxyz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxyz_xxxxxz_1[j];

                    tg_xxxxyz_xxxxxyy_0[j] = pb_x * tg_xxxyz_xxxxxyy_0[j] + fr * tg_xxxyz_xxxxxyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxyy_0[j] - tg_xxyz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyz_xxxxyy_1[j];

                    tg_xxxxyz_xxxxxyz_0[j] = pb_x * tg_xxxyz_xxxxxyz_0[j] + fr * tg_xxxyz_xxxxxyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxyz_0[j] - tg_xxyz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyz_xxxxyz_1[j];

                    tg_xxxxyz_xxxxxzz_0[j] = pb_x * tg_xxxyz_xxxxxzz_0[j] + fr * tg_xxxyz_xxxxxzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxxzz_0[j] - tg_xxyz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxyz_xxxxzz_1[j];

                    tg_xxxxyz_xxxxyyy_0[j] = pb_x * tg_xxxyz_xxxxyyy_0[j] + fr * tg_xxxyz_xxxxyyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxyyy_0[j] - tg_xxyz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyz_xxxyyy_1[j];

                    tg_xxxxyz_xxxxyyz_0[j] = pb_x * tg_xxxyz_xxxxyyz_0[j] + fr * tg_xxxyz_xxxxyyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxyyz_0[j] - tg_xxyz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyz_xxxyyz_1[j];

                    tg_xxxxyz_xxxxyzz_0[j] = pb_x * tg_xxxyz_xxxxyzz_0[j] + fr * tg_xxxyz_xxxxyzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxyzz_0[j] - tg_xxyz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyz_xxxyzz_1[j];

                    tg_xxxxyz_xxxxzzz_0[j] = pb_x * tg_xxxyz_xxxxzzz_0[j] + fr * tg_xxxyz_xxxxzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxxzzz_0[j] - tg_xxyz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxyz_xxxzzz_1[j];

                    tg_xxxxyz_xxxyyyy_0[j] = pb_x * tg_xxxyz_xxxyyyy_0[j] + fr * tg_xxxyz_xxxyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxyyyy_0[j] - tg_xxyz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xxyyyy_1[j];

                    tg_xxxxyz_xxxyyyz_0[j] = pb_x * tg_xxxyz_xxxyyyz_0[j] + fr * tg_xxxyz_xxxyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxyyyz_0[j] - tg_xxyz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xxyyyz_1[j];

                    tg_xxxxyz_xxxyyzz_0[j] = pb_x * tg_xxxyz_xxxyyzz_0[j] + fr * tg_xxxyz_xxxyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxyyzz_0[j] - tg_xxyz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xxyyzz_1[j];

                    tg_xxxxyz_xxxyzzz_0[j] = pb_x * tg_xxxyz_xxxyzzz_0[j] + fr * tg_xxxyz_xxxyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxyzzz_0[j] - tg_xxyz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xxyzzz_1[j];

                    tg_xxxxyz_xxxzzzz_0[j] = pb_x * tg_xxxyz_xxxzzzz_0[j] + fr * tg_xxxyz_xxxzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxxzzzz_0[j] - tg_xxyz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxyz_xxzzzz_1[j];

                    tg_xxxxyz_xxyyyyy_0[j] = pb_x * tg_xxxyz_xxyyyyy_0[j] + fr * tg_xxxyz_xxyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxyyyyy_0[j] - tg_xxyz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xyyyyy_1[j];

                    tg_xxxxyz_xxyyyyz_0[j] = pb_x * tg_xxxyz_xxyyyyz_0[j] + fr * tg_xxxyz_xxyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxyyyyz_0[j] - tg_xxyz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xyyyyz_1[j];

                    tg_xxxxyz_xxyyyzz_0[j] = pb_x * tg_xxxyz_xxyyyzz_0[j] + fr * tg_xxxyz_xxyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxyyyzz_0[j] - tg_xxyz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xyyyzz_1[j];

                    tg_xxxxyz_xxyyzzz_0[j] = pb_x * tg_xxxyz_xxyyzzz_0[j] + fr * tg_xxxyz_xxyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxyyzzz_0[j] - tg_xxyz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xyyzzz_1[j];

                    tg_xxxxyz_xxyzzzz_0[j] = pb_x * tg_xxxyz_xxyzzzz_0[j] + fr * tg_xxxyz_xxyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxyzzzz_0[j] - tg_xxyz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xyzzzz_1[j];

                    tg_xxxxyz_xxzzzzz_0[j] = pb_x * tg_xxxyz_xxzzzzz_0[j] + fr * tg_xxxyz_xxzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xxzzzzz_0[j] - tg_xxyz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxyz_xzzzzz_1[j];

                    tg_xxxxyz_xyyyyyy_0[j] = pb_x * tg_xxxyz_xyyyyyy_0[j] + fr * tg_xxxyz_xyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyyyyyy_0[j] - tg_xxyz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yyyyyy_1[j];

                    tg_xxxxyz_xyyyyyz_0[j] = pb_x * tg_xxxyz_xyyyyyz_0[j] + fr * tg_xxxyz_xyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyyyyyz_0[j] - tg_xxyz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yyyyyz_1[j];

                    tg_xxxxyz_xyyyyzz_0[j] = pb_x * tg_xxxyz_xyyyyzz_0[j] + fr * tg_xxxyz_xyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyyyyzz_0[j] - tg_xxyz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yyyyzz_1[j];

                    tg_xxxxyz_xyyyzzz_0[j] = pb_x * tg_xxxyz_xyyyzzz_0[j] + fr * tg_xxxyz_xyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyyyzzz_0[j] - tg_xxyz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yyyzzz_1[j];

                    tg_xxxxyz_xyyzzzz_0[j] = pb_x * tg_xxxyz_xyyzzzz_0[j] + fr * tg_xxxyz_xyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyyzzzz_0[j] - tg_xxyz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yyzzzz_1[j];

                    tg_xxxxyz_xyzzzzz_0[j] = pb_x * tg_xxxyz_xyzzzzz_0[j] + fr * tg_xxxyz_xyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xyzzzzz_0[j] - tg_xxyz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_yzzzzz_1[j];

                    tg_xxxxyz_xzzzzzz_0[j] = pb_x * tg_xxxyz_xzzzzzz_0[j] + fr * tg_xxxyz_xzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_xzzzzzz_0[j] - tg_xxyz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxyz_zzzzzz_1[j];

                    tg_xxxxyz_yyyyyyy_0[j] = pb_x * tg_xxxyz_yyyyyyy_0[j] + fr * tg_xxxyz_yyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyyyyyy_0[j] - tg_xxyz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxyz_yyyyyyz_0[j] = pb_x * tg_xxxyz_yyyyyyz_0[j] + fr * tg_xxxyz_yyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyyyyyz_0[j] - tg_xxyz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxyz_yyyyyzz_0[j] = pb_x * tg_xxxyz_yyyyyzz_0[j] + fr * tg_xxxyz_yyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyyyyzz_0[j] - tg_xxyz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxyz_yyyyzzz_0[j] = pb_x * tg_xxxyz_yyyyzzz_0[j] + fr * tg_xxxyz_yyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyyyzzz_0[j] - tg_xxyz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxyz_yyyzzzz_0[j] = pb_x * tg_xxxyz_yyyzzzz_0[j] + fr * tg_xxxyz_yyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyyzzzz_0[j] - tg_xxyz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxyz_yyzzzzz_0[j] = pb_x * tg_xxxyz_yyzzzzz_0[j] + fr * tg_xxxyz_yyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yyzzzzz_0[j] - tg_xxyz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxyz_yzzzzzz_0[j] = pb_x * tg_xxxyz_yzzzzzz_0[j] + fr * tg_xxxyz_yzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_yzzzzzz_0[j] - tg_xxyz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxyz_zzzzzzz_0[j] = pb_x * tg_xxxyz_zzzzzzz_0[j] + fr * tg_xxxyz_zzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxyz_zzzzzzz_0[j] - tg_xxyz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxxzz_xxxxxxx_0[j] = pb_x * tg_xxxzz_xxxxxxx_0[j] + fr * tg_xxxzz_xxxxxxx_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxxx_0[j] - tg_xxzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxxzz_xxxxxx_1[j];

                    tg_xxxxzz_xxxxxxy_0[j] = pb_x * tg_xxxzz_xxxxxxy_0[j] + fr * tg_xxxzz_xxxxxxy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxxy_0[j] - tg_xxzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxzz_xxxxxy_1[j];

                    tg_xxxxzz_xxxxxxz_0[j] = pb_x * tg_xxxzz_xxxxxxz_0[j] + fr * tg_xxxzz_xxxxxxz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxxz_0[j] - tg_xxzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxxzz_xxxxxz_1[j];

                    tg_xxxxzz_xxxxxyy_0[j] = pb_x * tg_xxxzz_xxxxxyy_0[j] + fr * tg_xxxzz_xxxxxyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxyy_0[j] - tg_xxzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxzz_xxxxyy_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_184_276(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (184,276)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xxxzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 184); 

                auto tg_xxxzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 185); 

                auto tg_xxxzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 186); 

                auto tg_xxxzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 187); 

                auto tg_xxxzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 188); 

                auto tg_xxxzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 189); 

                auto tg_xxxzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 190); 

                auto tg_xxxzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 191); 

                auto tg_xxxzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 192); 

                auto tg_xxxzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 193); 

                auto tg_xxxzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 194); 

                auto tg_xxxzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 195); 

                auto tg_xxxzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 196); 

                auto tg_xxxzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 197); 

                auto tg_xxxzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 198); 

                auto tg_xxxzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 199); 

                auto tg_xxxzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 200); 

                auto tg_xxxzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 201); 

                auto tg_xxxzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 202); 

                auto tg_xxxzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 203); 

                auto tg_xxxzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 204); 

                auto tg_xxxzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 205); 

                auto tg_xxxzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 206); 

                auto tg_xxxzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 207); 

                auto tg_xxxzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 208); 

                auto tg_xxxzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 209); 

                auto tg_xxxzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 210); 

                auto tg_xxxzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 211); 

                auto tg_xxxzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 212); 

                auto tg_xxxzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 213); 

                auto tg_xxxzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 214); 

                auto tg_xxxzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 215); 

                auto tg_xxyyy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 216); 

                auto tg_xxyyy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 217); 

                auto tg_xxyyy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 218); 

                auto tg_xxyyy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 219); 

                auto tg_xxyyy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 220); 

                auto tg_xxyyy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 221); 

                auto tg_xxyyy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 222); 

                auto tg_xxyyy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 223); 

                auto tg_xxyyy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 224); 

                auto tg_xxyyy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 225); 

                auto tg_xxyyy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 226); 

                auto tg_xxyyy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 227); 

                auto tg_xxyyy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 228); 

                auto tg_xxyyy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 229); 

                auto tg_xxyyy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 230); 

                auto tg_xxyyy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 231); 

                auto tg_xxyyy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 232); 

                auto tg_xxyyy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 233); 

                auto tg_xxyyy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 234); 

                auto tg_xxyyy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 235); 

                auto tg_xxyyy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 236); 

                auto tg_xxyyy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 237); 

                auto tg_xxyyy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 238); 

                auto tg_xxyyy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 239); 

                auto tg_xxyyy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 240); 

                auto tg_xxyyy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 241); 

                auto tg_xxyyy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 242); 

                auto tg_xxyyy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 243); 

                auto tg_xxyyy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 244); 

                auto tg_xxyyy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 245); 

                auto tg_xxyyy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 246); 

                auto tg_xxyyy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 247); 

                auto tg_xxyyy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 248); 

                auto tg_xxyyy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 249); 

                auto tg_xxyyy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 250); 

                auto tg_xxyyy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 251); 

                auto tg_xxyyz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 252); 

                auto tg_xxyyz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 253); 

                auto tg_xxyyz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 254); 

                auto tg_xxyyz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 255); 

                auto tg_xxyyz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 256); 

                auto tg_xxyyz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 257); 

                auto tg_xxyyz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 258); 

                auto tg_xxyyz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 259); 

                auto tg_xxyyz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 260); 

                auto tg_xxyyz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 261); 

                auto tg_xxyyz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 262); 

                auto tg_xxyyz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 263); 

                auto tg_xxyyz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 264); 

                auto tg_xxyyz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 265); 

                auto tg_xxyyz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 266); 

                auto tg_xxyyz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 267); 

                auto tg_xxyyz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 268); 

                auto tg_xxyyz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 269); 

                auto tg_xxyyz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 270); 

                auto tg_xxyyz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 271); 

                auto tg_xxyyz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 272); 

                auto tg_xxyyz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 273); 

                auto tg_xxyyz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 274); 

                auto tg_xxyyz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 275); 

                auto tg_xxxzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 184); 

                auto tg_xxxzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 185); 

                auto tg_xxxzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 186); 

                auto tg_xxxzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 187); 

                auto tg_xxxzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 188); 

                auto tg_xxxzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 189); 

                auto tg_xxxzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 190); 

                auto tg_xxxzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 191); 

                auto tg_xxxzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 192); 

                auto tg_xxxzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 193); 

                auto tg_xxxzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 194); 

                auto tg_xxxzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 195); 

                auto tg_xxxzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 196); 

                auto tg_xxxzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 197); 

                auto tg_xxxzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 198); 

                auto tg_xxxzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 199); 

                auto tg_xxxzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 200); 

                auto tg_xxxzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 201); 

                auto tg_xxxzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 202); 

                auto tg_xxxzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 203); 

                auto tg_xxxzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 204); 

                auto tg_xxxzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 205); 

                auto tg_xxxzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 206); 

                auto tg_xxxzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 207); 

                auto tg_xxxzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 208); 

                auto tg_xxxzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 209); 

                auto tg_xxxzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 210); 

                auto tg_xxxzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 211); 

                auto tg_xxxzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 212); 

                auto tg_xxxzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 213); 

                auto tg_xxxzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 214); 

                auto tg_xxxzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 215); 

                auto tg_xxyyy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 216); 

                auto tg_xxyyy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 217); 

                auto tg_xxyyy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 218); 

                auto tg_xxyyy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 219); 

                auto tg_xxyyy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 220); 

                auto tg_xxyyy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 221); 

                auto tg_xxyyy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 222); 

                auto tg_xxyyy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 223); 

                auto tg_xxyyy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 224); 

                auto tg_xxyyy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 225); 

                auto tg_xxyyy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 226); 

                auto tg_xxyyy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 227); 

                auto tg_xxyyy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 228); 

                auto tg_xxyyy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 229); 

                auto tg_xxyyy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 230); 

                auto tg_xxyyy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 231); 

                auto tg_xxyyy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 232); 

                auto tg_xxyyy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 233); 

                auto tg_xxyyy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 234); 

                auto tg_xxyyy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 235); 

                auto tg_xxyyy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 236); 

                auto tg_xxyyy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 237); 

                auto tg_xxyyy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 238); 

                auto tg_xxyyy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 239); 

                auto tg_xxyyy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 240); 

                auto tg_xxyyy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 241); 

                auto tg_xxyyy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 242); 

                auto tg_xxyyy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 243); 

                auto tg_xxyyy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 244); 

                auto tg_xxyyy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 245); 

                auto tg_xxyyy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 246); 

                auto tg_xxyyy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 247); 

                auto tg_xxyyy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 248); 

                auto tg_xxyyy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 249); 

                auto tg_xxyyy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 250); 

                auto tg_xxyyy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 251); 

                auto tg_xxyyz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 252); 

                auto tg_xxyyz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 253); 

                auto tg_xxyyz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 254); 

                auto tg_xxyyz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 255); 

                auto tg_xxyyz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 256); 

                auto tg_xxyyz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 257); 

                auto tg_xxyyz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 258); 

                auto tg_xxyyz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 259); 

                auto tg_xxyyz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 260); 

                auto tg_xxyyz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 261); 

                auto tg_xxyyz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 262); 

                auto tg_xxyyz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 263); 

                auto tg_xxyyz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 264); 

                auto tg_xxyyz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 265); 

                auto tg_xxyyz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 266); 

                auto tg_xxyyz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 267); 

                auto tg_xxyyz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 268); 

                auto tg_xxyyz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 269); 

                auto tg_xxyyz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 270); 

                auto tg_xxyyz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 271); 

                auto tg_xxyyz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 272); 

                auto tg_xxyyz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 273); 

                auto tg_xxyyz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 274); 

                auto tg_xxyyz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 275); 

                auto tg_xxzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 184); 

                auto tg_xxzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 185); 

                auto tg_xxzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 186); 

                auto tg_xxzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 187); 

                auto tg_xxzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 188); 

                auto tg_xxzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 189); 

                auto tg_xxzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 190); 

                auto tg_xxzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 191); 

                auto tg_xxzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 192); 

                auto tg_xxzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 193); 

                auto tg_xxzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 194); 

                auto tg_xxzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 195); 

                auto tg_xxzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 196); 

                auto tg_xxzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 197); 

                auto tg_xxzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 198); 

                auto tg_xxzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 199); 

                auto tg_xxzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 200); 

                auto tg_xxzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 201); 

                auto tg_xxzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 202); 

                auto tg_xxzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 203); 

                auto tg_xxzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 204); 

                auto tg_xxzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 205); 

                auto tg_xxzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 206); 

                auto tg_xxzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 207); 

                auto tg_xxzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 208); 

                auto tg_xxzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 209); 

                auto tg_xxzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 210); 

                auto tg_xxzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 211); 

                auto tg_xxzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 212); 

                auto tg_xxzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 213); 

                auto tg_xxzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 214); 

                auto tg_xxzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 215); 

                auto tg_xyyy_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 216); 

                auto tg_xyyy_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 217); 

                auto tg_xyyy_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 218); 

                auto tg_xyyy_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 219); 

                auto tg_xyyy_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 220); 

                auto tg_xyyy_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 221); 

                auto tg_xyyy_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 222); 

                auto tg_xyyy_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 223); 

                auto tg_xyyy_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 224); 

                auto tg_xyyy_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 225); 

                auto tg_xyyy_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 226); 

                auto tg_xyyy_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 227); 

                auto tg_xyyy_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 228); 

                auto tg_xyyy_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 229); 

                auto tg_xyyy_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 230); 

                auto tg_xyyy_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 231); 

                auto tg_xyyy_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 232); 

                auto tg_xyyy_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 233); 

                auto tg_xyyy_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 234); 

                auto tg_xyyy_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 235); 

                auto tg_xyyy_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 236); 

                auto tg_xyyy_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 237); 

                auto tg_xyyy_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 238); 

                auto tg_xyyy_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 239); 

                auto tg_xyyy_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 240); 

                auto tg_xyyy_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 241); 

                auto tg_xyyy_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 242); 

                auto tg_xyyy_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 243); 

                auto tg_xyyy_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 244); 

                auto tg_xyyy_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 245); 

                auto tg_xyyy_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 246); 

                auto tg_xyyy_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 247); 

                auto tg_xyyy_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 248); 

                auto tg_xyyy_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 249); 

                auto tg_xyyy_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 250); 

                auto tg_xyyy_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 251); 

                auto tg_xyyz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 252); 

                auto tg_xyyz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 253); 

                auto tg_xyyz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 254); 

                auto tg_xyyz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 255); 

                auto tg_xyyz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 256); 

                auto tg_xyyz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 257); 

                auto tg_xyyz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 258); 

                auto tg_xyyz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 259); 

                auto tg_xyyz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 260); 

                auto tg_xyyz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 261); 

                auto tg_xyyz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 262); 

                auto tg_xyyz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 263); 

                auto tg_xyyz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 264); 

                auto tg_xyyz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 265); 

                auto tg_xyyz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 266); 

                auto tg_xyyz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 267); 

                auto tg_xyyz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 268); 

                auto tg_xyyz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 269); 

                auto tg_xyyz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 270); 

                auto tg_xyyz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 271); 

                auto tg_xyyz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 272); 

                auto tg_xyyz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 273); 

                auto tg_xyyz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 274); 

                auto tg_xyyz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 275); 

                auto tg_xxzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 184); 

                auto tg_xxzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 185); 

                auto tg_xxzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 186); 

                auto tg_xxzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 187); 

                auto tg_xxzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 188); 

                auto tg_xxzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 189); 

                auto tg_xxzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 190); 

                auto tg_xxzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 191); 

                auto tg_xxzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 192); 

                auto tg_xxzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 193); 

                auto tg_xxzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 194); 

                auto tg_xxzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 195); 

                auto tg_xxzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 196); 

                auto tg_xxzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 197); 

                auto tg_xxzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 198); 

                auto tg_xxzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 199); 

                auto tg_xxzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 200); 

                auto tg_xxzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 201); 

                auto tg_xxzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 202); 

                auto tg_xxzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 203); 

                auto tg_xxzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 204); 

                auto tg_xxzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 205); 

                auto tg_xxzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 206); 

                auto tg_xxzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 207); 

                auto tg_xxzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 208); 

                auto tg_xxzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 209); 

                auto tg_xxzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 210); 

                auto tg_xxzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 211); 

                auto tg_xxzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 212); 

                auto tg_xxzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 213); 

                auto tg_xxzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 214); 

                auto tg_xxzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 215); 

                auto tg_xyyy_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 216); 

                auto tg_xyyy_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 217); 

                auto tg_xyyy_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 218); 

                auto tg_xyyy_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 219); 

                auto tg_xyyy_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 220); 

                auto tg_xyyy_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 221); 

                auto tg_xyyy_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 222); 

                auto tg_xyyy_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 223); 

                auto tg_xyyy_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 224); 

                auto tg_xyyy_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 225); 

                auto tg_xyyy_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 226); 

                auto tg_xyyy_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 227); 

                auto tg_xyyy_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 228); 

                auto tg_xyyy_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 229); 

                auto tg_xyyy_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 230); 

                auto tg_xyyy_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 231); 

                auto tg_xyyy_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 232); 

                auto tg_xyyy_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 233); 

                auto tg_xyyy_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 234); 

                auto tg_xyyy_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 235); 

                auto tg_xyyy_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 236); 

                auto tg_xyyy_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 237); 

                auto tg_xyyy_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 238); 

                auto tg_xyyy_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 239); 

                auto tg_xyyy_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 240); 

                auto tg_xyyy_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 241); 

                auto tg_xyyy_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 242); 

                auto tg_xyyy_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 243); 

                auto tg_xyyy_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 244); 

                auto tg_xyyy_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 245); 

                auto tg_xyyy_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 246); 

                auto tg_xyyy_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 247); 

                auto tg_xyyy_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 248); 

                auto tg_xyyy_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 249); 

                auto tg_xyyy_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 250); 

                auto tg_xyyy_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 251); 

                auto tg_xyyz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 252); 

                auto tg_xyyz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 253); 

                auto tg_xyyz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 254); 

                auto tg_xyyz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 255); 

                auto tg_xyyz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 256); 

                auto tg_xyyz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 257); 

                auto tg_xyyz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 258); 

                auto tg_xyyz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 259); 

                auto tg_xyyz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 260); 

                auto tg_xyyz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 261); 

                auto tg_xyyz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 262); 

                auto tg_xyyz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 263); 

                auto tg_xyyz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 264); 

                auto tg_xyyz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 265); 

                auto tg_xyyz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 266); 

                auto tg_xyyz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 267); 

                auto tg_xyyz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 268); 

                auto tg_xyyz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 269); 

                auto tg_xyyz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 270); 

                auto tg_xyyz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 271); 

                auto tg_xyyz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 272); 

                auto tg_xyyz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 273); 

                auto tg_xyyz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 274); 

                auto tg_xyyz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 275); 

                auto tg_xxxzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 144); 

                auto tg_xxxzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 145); 

                auto tg_xxxzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 146); 

                auto tg_xxxzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 147); 

                auto tg_xxxzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 148); 

                auto tg_xxxzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 149); 

                auto tg_xxxzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 150); 

                auto tg_xxxzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 151); 

                auto tg_xxxzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 152); 

                auto tg_xxxzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 153); 

                auto tg_xxxzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 154); 

                auto tg_xxxzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 155); 

                auto tg_xxxzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 156); 

                auto tg_xxxzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 157); 

                auto tg_xxxzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 158); 

                auto tg_xxxzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 159); 

                auto tg_xxxzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 160); 

                auto tg_xxxzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 161); 

                auto tg_xxxzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 162); 

                auto tg_xxxzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 163); 

                auto tg_xxxzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 164); 

                auto tg_xxxzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 165); 

                auto tg_xxxzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 166); 

                auto tg_xxxzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 167); 

                auto tg_xxyyy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 168); 

                auto tg_xxyyy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 169); 

                auto tg_xxyyy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 170); 

                auto tg_xxyyy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 171); 

                auto tg_xxyyy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 172); 

                auto tg_xxyyy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 173); 

                auto tg_xxyyy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 174); 

                auto tg_xxyyy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 175); 

                auto tg_xxyyy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 176); 

                auto tg_xxyyy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 177); 

                auto tg_xxyyy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 178); 

                auto tg_xxyyy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 179); 

                auto tg_xxyyy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 180); 

                auto tg_xxyyy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 181); 

                auto tg_xxyyy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 182); 

                auto tg_xxyyy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 183); 

                auto tg_xxyyy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 184); 

                auto tg_xxyyy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 185); 

                auto tg_xxyyy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 186); 

                auto tg_xxyyy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 187); 

                auto tg_xxyyy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 188); 

                auto tg_xxyyy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 189); 

                auto tg_xxyyy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 190); 

                auto tg_xxyyy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 191); 

                auto tg_xxyyy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 192); 

                auto tg_xxyyy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 193); 

                auto tg_xxyyy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 194); 

                auto tg_xxyyy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 195); 

                auto tg_xxyyz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 196); 

                auto tg_xxyyz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 197); 

                auto tg_xxyyz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 198); 

                auto tg_xxyyz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 199); 

                auto tg_xxyyz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 200); 

                auto tg_xxyyz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 201); 

                auto tg_xxyyz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 202); 

                auto tg_xxyyz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 203); 

                auto tg_xxyyz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 204); 

                auto tg_xxyyz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 205); 

                auto tg_xxyyz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 206); 

                auto tg_xxyyz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 207); 

                auto tg_xxyyz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 208); 

                auto tg_xxyyz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 209); 

                auto tg_xxyyz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 210); 

                auto tg_xxyyz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 211); 

                auto tg_xxyyz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 212); 

                auto tg_xxyyz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 213); 

                auto tg_xxyyz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 214); 

                auto tg_xxyyz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 215); 

                auto tg_xxyyz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 216); 

                auto tg_xxyyz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 217); 

                auto tg_xxyyz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 218); 

                auto tg_xxyyz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 219); 

                // set up pointers to integrals

                auto tg_xxxxzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 184); 

                auto tg_xxxxzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 185); 

                auto tg_xxxxzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 186); 

                auto tg_xxxxzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 187); 

                auto tg_xxxxzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 188); 

                auto tg_xxxxzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 189); 

                auto tg_xxxxzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 190); 

                auto tg_xxxxzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 191); 

                auto tg_xxxxzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 192); 

                auto tg_xxxxzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 193); 

                auto tg_xxxxzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 194); 

                auto tg_xxxxzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 195); 

                auto tg_xxxxzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 196); 

                auto tg_xxxxzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 197); 

                auto tg_xxxxzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 198); 

                auto tg_xxxxzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 199); 

                auto tg_xxxxzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 200); 

                auto tg_xxxxzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 201); 

                auto tg_xxxxzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 202); 

                auto tg_xxxxzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 203); 

                auto tg_xxxxzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 204); 

                auto tg_xxxxzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 205); 

                auto tg_xxxxzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 206); 

                auto tg_xxxxzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 207); 

                auto tg_xxxxzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 208); 

                auto tg_xxxxzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 209); 

                auto tg_xxxxzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 210); 

                auto tg_xxxxzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 211); 

                auto tg_xxxxzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 212); 

                auto tg_xxxxzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 213); 

                auto tg_xxxxzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 214); 

                auto tg_xxxxzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 215); 

                auto tg_xxxyyy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 216); 

                auto tg_xxxyyy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 217); 

                auto tg_xxxyyy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 218); 

                auto tg_xxxyyy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 219); 

                auto tg_xxxyyy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 220); 

                auto tg_xxxyyy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 221); 

                auto tg_xxxyyy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 222); 

                auto tg_xxxyyy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 223); 

                auto tg_xxxyyy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 224); 

                auto tg_xxxyyy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 225); 

                auto tg_xxxyyy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 226); 

                auto tg_xxxyyy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 227); 

                auto tg_xxxyyy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 228); 

                auto tg_xxxyyy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 229); 

                auto tg_xxxyyy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 230); 

                auto tg_xxxyyy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 231); 

                auto tg_xxxyyy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 232); 

                auto tg_xxxyyy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 233); 

                auto tg_xxxyyy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 234); 

                auto tg_xxxyyy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 235); 

                auto tg_xxxyyy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 236); 

                auto tg_xxxyyy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 237); 

                auto tg_xxxyyy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 238); 

                auto tg_xxxyyy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 239); 

                auto tg_xxxyyy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 240); 

                auto tg_xxxyyy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 241); 

                auto tg_xxxyyy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 242); 

                auto tg_xxxyyy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 243); 

                auto tg_xxxyyy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 244); 

                auto tg_xxxyyy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 245); 

                auto tg_xxxyyy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 246); 

                auto tg_xxxyyy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 247); 

                auto tg_xxxyyy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 248); 

                auto tg_xxxyyy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 249); 

                auto tg_xxxyyy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 250); 

                auto tg_xxxyyy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 251); 

                auto tg_xxxyyz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 252); 

                auto tg_xxxyyz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 253); 

                auto tg_xxxyyz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 254); 

                auto tg_xxxyyz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 255); 

                auto tg_xxxyyz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 256); 

                auto tg_xxxyyz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 257); 

                auto tg_xxxyyz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 258); 

                auto tg_xxxyyz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 259); 

                auto tg_xxxyyz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 260); 

                auto tg_xxxyyz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 261); 

                auto tg_xxxyyz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 262); 

                auto tg_xxxyyz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 263); 

                auto tg_xxxyyz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 264); 

                auto tg_xxxyyz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 265); 

                auto tg_xxxyyz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 266); 

                auto tg_xxxyyz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 267); 

                auto tg_xxxyyz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 268); 

                auto tg_xxxyyz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 269); 

                auto tg_xxxyyz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 270); 

                auto tg_xxxyyz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 271); 

                auto tg_xxxyyz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 272); 

                auto tg_xxxyyz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 273); 

                auto tg_xxxyyz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 274); 

                auto tg_xxxyyz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 275); 

                // Batch of Integrals (184,276)

                #pragma omp simd aligned(fxn, fza, tg_xxxxzz_xxxxxyz_0, tg_xxxxzz_xxxxxzz_0, \
                                         tg_xxxxzz_xxxxyyy_0, tg_xxxxzz_xxxxyyz_0, tg_xxxxzz_xxxxyzz_0, tg_xxxxzz_xxxxzzz_0, \
                                         tg_xxxxzz_xxxyyyy_0, tg_xxxxzz_xxxyyyz_0, tg_xxxxzz_xxxyyzz_0, tg_xxxxzz_xxxyzzz_0, \
                                         tg_xxxxzz_xxxzzzz_0, tg_xxxxzz_xxyyyyy_0, tg_xxxxzz_xxyyyyz_0, tg_xxxxzz_xxyyyzz_0, \
                                         tg_xxxxzz_xxyyzzz_0, tg_xxxxzz_xxyzzzz_0, tg_xxxxzz_xxzzzzz_0, tg_xxxxzz_xyyyyyy_0, \
                                         tg_xxxxzz_xyyyyyz_0, tg_xxxxzz_xyyyyzz_0, tg_xxxxzz_xyyyzzz_0, tg_xxxxzz_xyyzzzz_0, \
                                         tg_xxxxzz_xyzzzzz_0, tg_xxxxzz_xzzzzzz_0, tg_xxxxzz_yyyyyyy_0, tg_xxxxzz_yyyyyyz_0, \
                                         tg_xxxxzz_yyyyyzz_0, tg_xxxxzz_yyyyzzz_0, tg_xxxxzz_yyyzzzz_0, tg_xxxxzz_yyzzzzz_0, \
                                         tg_xxxxzz_yzzzzzz_0, tg_xxxxzz_zzzzzzz_0, tg_xxxyyy_xxxxxxx_0, tg_xxxyyy_xxxxxxy_0, \
                                         tg_xxxyyy_xxxxxxz_0, tg_xxxyyy_xxxxxyy_0, tg_xxxyyy_xxxxxyz_0, tg_xxxyyy_xxxxxzz_0, \
                                         tg_xxxyyy_xxxxyyy_0, tg_xxxyyy_xxxxyyz_0, tg_xxxyyy_xxxxyzz_0, tg_xxxyyy_xxxxzzz_0, \
                                         tg_xxxyyy_xxxyyyy_0, tg_xxxyyy_xxxyyyz_0, tg_xxxyyy_xxxyyzz_0, tg_xxxyyy_xxxyzzz_0, \
                                         tg_xxxyyy_xxxzzzz_0, tg_xxxyyy_xxyyyyy_0, tg_xxxyyy_xxyyyyz_0, tg_xxxyyy_xxyyyzz_0, \
                                         tg_xxxyyy_xxyyzzz_0, tg_xxxyyy_xxyzzzz_0, tg_xxxyyy_xxzzzzz_0, tg_xxxyyy_xyyyyyy_0, \
                                         tg_xxxyyy_xyyyyyz_0, tg_xxxyyy_xyyyyzz_0, tg_xxxyyy_xyyyzzz_0, tg_xxxyyy_xyyzzzz_0, \
                                         tg_xxxyyy_xyzzzzz_0, tg_xxxyyy_xzzzzzz_0, tg_xxxyyy_yyyyyyy_0, tg_xxxyyy_yyyyyyz_0, \
                                         tg_xxxyyy_yyyyyzz_0, tg_xxxyyy_yyyyzzz_0, tg_xxxyyy_yyyzzzz_0, tg_xxxyyy_yyzzzzz_0, \
                                         tg_xxxyyy_yzzzzzz_0, tg_xxxyyy_zzzzzzz_0, tg_xxxyyz_xxxxxxx_0, tg_xxxyyz_xxxxxxy_0, \
                                         tg_xxxyyz_xxxxxxz_0, tg_xxxyyz_xxxxxyy_0, tg_xxxyyz_xxxxxyz_0, tg_xxxyyz_xxxxxzz_0, \
                                         tg_xxxyyz_xxxxyyy_0, tg_xxxyyz_xxxxyyz_0, tg_xxxyyz_xxxxyzz_0, tg_xxxyyz_xxxxzzz_0, \
                                         tg_xxxyyz_xxxyyyy_0, tg_xxxyyz_xxxyyyz_0, tg_xxxyyz_xxxyyzz_0, tg_xxxyyz_xxxyzzz_0, \
                                         tg_xxxyyz_xxxzzzz_0, tg_xxxyyz_xxyyyyy_0, tg_xxxyyz_xxyyyyz_0, tg_xxxyyz_xxyyyzz_0, \
                                         tg_xxxyyz_xxyyzzz_0, tg_xxxyyz_xxyzzzz_0, tg_xxxyyz_xxzzzzz_0, tg_xxxyyz_xyyyyyy_0, \
                                         tg_xxxyyz_xyyyyyz_0, tg_xxxyyz_xyyyyzz_0, tg_xxxzz_xxxxxyz_0, tg_xxxzz_xxxxxyz_1, \
                                         tg_xxxzz_xxxxxzz_0, tg_xxxzz_xxxxxzz_1, tg_xxxzz_xxxxyyy_0, tg_xxxzz_xxxxyyy_1, \
                                         tg_xxxzz_xxxxyyz_0, tg_xxxzz_xxxxyyz_1, tg_xxxzz_xxxxyz_1, tg_xxxzz_xxxxyzz_0, \
                                         tg_xxxzz_xxxxyzz_1, tg_xxxzz_xxxxzz_1, tg_xxxzz_xxxxzzz_0, tg_xxxzz_xxxxzzz_1, \
                                         tg_xxxzz_xxxyyy_1, tg_xxxzz_xxxyyyy_0, tg_xxxzz_xxxyyyy_1, tg_xxxzz_xxxyyyz_0, \
                                         tg_xxxzz_xxxyyyz_1, tg_xxxzz_xxxyyz_1, tg_xxxzz_xxxyyzz_0, tg_xxxzz_xxxyyzz_1, \
                                         tg_xxxzz_xxxyzz_1, tg_xxxzz_xxxyzzz_0, tg_xxxzz_xxxyzzz_1, tg_xxxzz_xxxzzz_1, \
                                         tg_xxxzz_xxxzzzz_0, tg_xxxzz_xxxzzzz_1, tg_xxxzz_xxyyyy_1, tg_xxxzz_xxyyyyy_0, \
                                         tg_xxxzz_xxyyyyy_1, tg_xxxzz_xxyyyyz_0, tg_xxxzz_xxyyyyz_1, tg_xxxzz_xxyyyz_1, \
                                         tg_xxxzz_xxyyyzz_0, tg_xxxzz_xxyyyzz_1, tg_xxxzz_xxyyzz_1, tg_xxxzz_xxyyzzz_0, \
                                         tg_xxxzz_xxyyzzz_1, tg_xxxzz_xxyzzz_1, tg_xxxzz_xxyzzzz_0, tg_xxxzz_xxyzzzz_1, \
                                         tg_xxxzz_xxzzzz_1, tg_xxxzz_xxzzzzz_0, tg_xxxzz_xxzzzzz_1, tg_xxxzz_xyyyyy_1, \
                                         tg_xxxzz_xyyyyyy_0, tg_xxxzz_xyyyyyy_1, tg_xxxzz_xyyyyyz_0, tg_xxxzz_xyyyyyz_1, \
                                         tg_xxxzz_xyyyyz_1, tg_xxxzz_xyyyyzz_0, tg_xxxzz_xyyyyzz_1, tg_xxxzz_xyyyzz_1, \
                                         tg_xxxzz_xyyyzzz_0, tg_xxxzz_xyyyzzz_1, tg_xxxzz_xyyzzz_1, tg_xxxzz_xyyzzzz_0, \
                                         tg_xxxzz_xyyzzzz_1, tg_xxxzz_xyzzzz_1, tg_xxxzz_xyzzzzz_0, tg_xxxzz_xyzzzzz_1, \
                                         tg_xxxzz_xzzzzz_1, tg_xxxzz_xzzzzzz_0, tg_xxxzz_xzzzzzz_1, tg_xxxzz_yyyyyy_1, \
                                         tg_xxxzz_yyyyyyy_0, tg_xxxzz_yyyyyyy_1, tg_xxxzz_yyyyyyz_0, tg_xxxzz_yyyyyyz_1, \
                                         tg_xxxzz_yyyyyz_1, tg_xxxzz_yyyyyzz_0, tg_xxxzz_yyyyyzz_1, tg_xxxzz_yyyyzz_1, \
                                         tg_xxxzz_yyyyzzz_0, tg_xxxzz_yyyyzzz_1, tg_xxxzz_yyyzzz_1, tg_xxxzz_yyyzzzz_0, \
                                         tg_xxxzz_yyyzzzz_1, tg_xxxzz_yyzzzz_1, tg_xxxzz_yyzzzzz_0, tg_xxxzz_yyzzzzz_1, \
                                         tg_xxxzz_yzzzzz_1, tg_xxxzz_yzzzzzz_0, tg_xxxzz_yzzzzzz_1, tg_xxxzz_zzzzzz_1, \
                                         tg_xxxzz_zzzzzzz_0, tg_xxxzz_zzzzzzz_1, tg_xxyyy_xxxxxx_1, tg_xxyyy_xxxxxxx_0, \
                                         tg_xxyyy_xxxxxxx_1, tg_xxyyy_xxxxxxy_0, tg_xxyyy_xxxxxxy_1, tg_xxyyy_xxxxxxz_0, \
                                         tg_xxyyy_xxxxxxz_1, tg_xxyyy_xxxxxy_1, tg_xxyyy_xxxxxyy_0, tg_xxyyy_xxxxxyy_1, \
                                         tg_xxyyy_xxxxxyz_0, tg_xxyyy_xxxxxyz_1, tg_xxyyy_xxxxxz_1, tg_xxyyy_xxxxxzz_0, \
                                         tg_xxyyy_xxxxxzz_1, tg_xxyyy_xxxxyy_1, tg_xxyyy_xxxxyyy_0, tg_xxyyy_xxxxyyy_1, \
                                         tg_xxyyy_xxxxyyz_0, tg_xxyyy_xxxxyyz_1, tg_xxyyy_xxxxyz_1, tg_xxyyy_xxxxyzz_0, \
                                         tg_xxyyy_xxxxyzz_1, tg_xxyyy_xxxxzz_1, tg_xxyyy_xxxxzzz_0, tg_xxyyy_xxxxzzz_1, \
                                         tg_xxyyy_xxxyyy_1, tg_xxyyy_xxxyyyy_0, tg_xxyyy_xxxyyyy_1, tg_xxyyy_xxxyyyz_0, \
                                         tg_xxyyy_xxxyyyz_1, tg_xxyyy_xxxyyz_1, tg_xxyyy_xxxyyzz_0, tg_xxyyy_xxxyyzz_1, \
                                         tg_xxyyy_xxxyzz_1, tg_xxyyy_xxxyzzz_0, tg_xxyyy_xxxyzzz_1, tg_xxyyy_xxxzzz_1, \
                                         tg_xxyyy_xxxzzzz_0, tg_xxyyy_xxxzzzz_1, tg_xxyyy_xxyyyy_1, tg_xxyyy_xxyyyyy_0, \
                                         tg_xxyyy_xxyyyyy_1, tg_xxyyy_xxyyyyz_0, tg_xxyyy_xxyyyyz_1, tg_xxyyy_xxyyyz_1, \
                                         tg_xxyyy_xxyyyzz_0, tg_xxyyy_xxyyyzz_1, tg_xxyyy_xxyyzz_1, tg_xxyyy_xxyyzzz_0, \
                                         tg_xxyyy_xxyyzzz_1, tg_xxyyy_xxyzzz_1, tg_xxyyy_xxyzzzz_0, tg_xxyyy_xxyzzzz_1, \
                                         tg_xxyyy_xxzzzz_1, tg_xxyyy_xxzzzzz_0, tg_xxyyy_xxzzzzz_1, tg_xxyyy_xyyyyy_1, \
                                         tg_xxyyy_xyyyyyy_0, tg_xxyyy_xyyyyyy_1, tg_xxyyy_xyyyyyz_0, tg_xxyyy_xyyyyyz_1, \
                                         tg_xxyyy_xyyyyz_1, tg_xxyyy_xyyyyzz_0, tg_xxyyy_xyyyyzz_1, tg_xxyyy_xyyyzz_1, \
                                         tg_xxyyy_xyyyzzz_0, tg_xxyyy_xyyyzzz_1, tg_xxyyy_xyyzzz_1, tg_xxyyy_xyyzzzz_0, \
                                         tg_xxyyy_xyyzzzz_1, tg_xxyyy_xyzzzz_1, tg_xxyyy_xyzzzzz_0, tg_xxyyy_xyzzzzz_1, \
                                         tg_xxyyy_xzzzzz_1, tg_xxyyy_xzzzzzz_0, tg_xxyyy_xzzzzzz_1, tg_xxyyy_yyyyyy_1, \
                                         tg_xxyyy_yyyyyyy_0, tg_xxyyy_yyyyyyy_1, tg_xxyyy_yyyyyyz_0, tg_xxyyy_yyyyyyz_1, \
                                         tg_xxyyy_yyyyyz_1, tg_xxyyy_yyyyyzz_0, tg_xxyyy_yyyyyzz_1, tg_xxyyy_yyyyzz_1, \
                                         tg_xxyyy_yyyyzzz_0, tg_xxyyy_yyyyzzz_1, tg_xxyyy_yyyzzz_1, tg_xxyyy_yyyzzzz_0, \
                                         tg_xxyyy_yyyzzzz_1, tg_xxyyy_yyzzzz_1, tg_xxyyy_yyzzzzz_0, tg_xxyyy_yyzzzzz_1, \
                                         tg_xxyyy_yzzzzz_1, tg_xxyyy_yzzzzzz_0, tg_xxyyy_yzzzzzz_1, tg_xxyyy_zzzzzz_1, \
                                         tg_xxyyy_zzzzzzz_0, tg_xxyyy_zzzzzzz_1, tg_xxyyz_xxxxxx_1, tg_xxyyz_xxxxxxx_0, \
                                         tg_xxyyz_xxxxxxx_1, tg_xxyyz_xxxxxxy_0, tg_xxyyz_xxxxxxy_1, tg_xxyyz_xxxxxxz_0, \
                                         tg_xxyyz_xxxxxxz_1, tg_xxyyz_xxxxxy_1, tg_xxyyz_xxxxxyy_0, tg_xxyyz_xxxxxyy_1, \
                                         tg_xxyyz_xxxxxyz_0, tg_xxyyz_xxxxxyz_1, tg_xxyyz_xxxxxz_1, tg_xxyyz_xxxxxzz_0, \
                                         tg_xxyyz_xxxxxzz_1, tg_xxyyz_xxxxyy_1, tg_xxyyz_xxxxyyy_0, tg_xxyyz_xxxxyyy_1, \
                                         tg_xxyyz_xxxxyyz_0, tg_xxyyz_xxxxyyz_1, tg_xxyyz_xxxxyz_1, tg_xxyyz_xxxxyzz_0, \
                                         tg_xxyyz_xxxxyzz_1, tg_xxyyz_xxxxzz_1, tg_xxyyz_xxxxzzz_0, tg_xxyyz_xxxxzzz_1, \
                                         tg_xxyyz_xxxyyy_1, tg_xxyyz_xxxyyyy_0, tg_xxyyz_xxxyyyy_1, tg_xxyyz_xxxyyyz_0, \
                                         tg_xxyyz_xxxyyyz_1, tg_xxyyz_xxxyyz_1, tg_xxyyz_xxxyyzz_0, tg_xxyyz_xxxyyzz_1, \
                                         tg_xxyyz_xxxyzz_1, tg_xxyyz_xxxyzzz_0, tg_xxyyz_xxxyzzz_1, tg_xxyyz_xxxzzz_1, \
                                         tg_xxyyz_xxxzzzz_0, tg_xxyyz_xxxzzzz_1, tg_xxyyz_xxyyyy_1, tg_xxyyz_xxyyyyy_0, \
                                         tg_xxyyz_xxyyyyy_1, tg_xxyyz_xxyyyyz_0, tg_xxyyz_xxyyyyz_1, tg_xxyyz_xxyyyz_1, \
                                         tg_xxyyz_xxyyyzz_0, tg_xxyyz_xxyyyzz_1, tg_xxyyz_xxyyzz_1, tg_xxyyz_xxyyzzz_0, \
                                         tg_xxyyz_xxyyzzz_1, tg_xxyyz_xxyzzz_1, tg_xxyyz_xxyzzzz_0, tg_xxyyz_xxyzzzz_1, \
                                         tg_xxyyz_xxzzzz_1, tg_xxyyz_xxzzzzz_0, tg_xxyyz_xxzzzzz_1, tg_xxyyz_xyyyyy_1, \
                                         tg_xxyyz_xyyyyyy_0, tg_xxyyz_xyyyyyy_1, tg_xxyyz_xyyyyyz_0, tg_xxyyz_xyyyyyz_1, \
                                         tg_xxyyz_xyyyyz_1, tg_xxyyz_xyyyyzz_0, tg_xxyyz_xyyyyzz_1, tg_xxyyz_xyyyzz_1, \
                                         tg_xxyyz_xyyzzz_1, tg_xxyyz_xyzzzz_1, tg_xxyyz_xzzzzz_1, tg_xxyyz_yyyyyy_1, \
                                         tg_xxyyz_yyyyyz_1, tg_xxyyz_yyyyzz_1, tg_xxzz_xxxxxyz_0, tg_xxzz_xxxxxyz_1, \
                                         tg_xxzz_xxxxxzz_0, tg_xxzz_xxxxxzz_1, tg_xxzz_xxxxyyy_0, tg_xxzz_xxxxyyy_1, \
                                         tg_xxzz_xxxxyyz_0, tg_xxzz_xxxxyyz_1, tg_xxzz_xxxxyzz_0, tg_xxzz_xxxxyzz_1, \
                                         tg_xxzz_xxxxzzz_0, tg_xxzz_xxxxzzz_1, tg_xxzz_xxxyyyy_0, tg_xxzz_xxxyyyy_1, \
                                         tg_xxzz_xxxyyyz_0, tg_xxzz_xxxyyyz_1, tg_xxzz_xxxyyzz_0, tg_xxzz_xxxyyzz_1, \
                                         tg_xxzz_xxxyzzz_0, tg_xxzz_xxxyzzz_1, tg_xxzz_xxxzzzz_0, tg_xxzz_xxxzzzz_1, \
                                         tg_xxzz_xxyyyyy_0, tg_xxzz_xxyyyyy_1, tg_xxzz_xxyyyyz_0, tg_xxzz_xxyyyyz_1, \
                                         tg_xxzz_xxyyyzz_0, tg_xxzz_xxyyyzz_1, tg_xxzz_xxyyzzz_0, tg_xxzz_xxyyzzz_1, \
                                         tg_xxzz_xxyzzzz_0, tg_xxzz_xxyzzzz_1, tg_xxzz_xxzzzzz_0, tg_xxzz_xxzzzzz_1, \
                                         tg_xxzz_xyyyyyy_0, tg_xxzz_xyyyyyy_1, tg_xxzz_xyyyyyz_0, tg_xxzz_xyyyyyz_1, \
                                         tg_xxzz_xyyyyzz_0, tg_xxzz_xyyyyzz_1, tg_xxzz_xyyyzzz_0, tg_xxzz_xyyyzzz_1, \
                                         tg_xxzz_xyyzzzz_0, tg_xxzz_xyyzzzz_1, tg_xxzz_xyzzzzz_0, tg_xxzz_xyzzzzz_1, \
                                         tg_xxzz_xzzzzzz_0, tg_xxzz_xzzzzzz_1, tg_xxzz_yyyyyyy_0, tg_xxzz_yyyyyyy_1, \
                                         tg_xxzz_yyyyyyz_0, tg_xxzz_yyyyyyz_1, tg_xxzz_yyyyyzz_0, tg_xxzz_yyyyyzz_1, \
                                         tg_xxzz_yyyyzzz_0, tg_xxzz_yyyyzzz_1, tg_xxzz_yyyzzzz_0, tg_xxzz_yyyzzzz_1, \
                                         tg_xxzz_yyzzzzz_0, tg_xxzz_yyzzzzz_1, tg_xxzz_yzzzzzz_0, tg_xxzz_yzzzzzz_1, \
                                         tg_xxzz_zzzzzzz_0, tg_xxzz_zzzzzzz_1, tg_xyyy_xxxxxxx_0, tg_xyyy_xxxxxxx_1, \
                                         tg_xyyy_xxxxxxy_0, tg_xyyy_xxxxxxy_1, tg_xyyy_xxxxxxz_0, tg_xyyy_xxxxxxz_1, \
                                         tg_xyyy_xxxxxyy_0, tg_xyyy_xxxxxyy_1, tg_xyyy_xxxxxyz_0, tg_xyyy_xxxxxyz_1, \
                                         tg_xyyy_xxxxxzz_0, tg_xyyy_xxxxxzz_1, tg_xyyy_xxxxyyy_0, tg_xyyy_xxxxyyy_1, \
                                         tg_xyyy_xxxxyyz_0, tg_xyyy_xxxxyyz_1, tg_xyyy_xxxxyzz_0, tg_xyyy_xxxxyzz_1, \
                                         tg_xyyy_xxxxzzz_0, tg_xyyy_xxxxzzz_1, tg_xyyy_xxxyyyy_0, tg_xyyy_xxxyyyy_1, \
                                         tg_xyyy_xxxyyyz_0, tg_xyyy_xxxyyyz_1, tg_xyyy_xxxyyzz_0, tg_xyyy_xxxyyzz_1, \
                                         tg_xyyy_xxxyzzz_0, tg_xyyy_xxxyzzz_1, tg_xyyy_xxxzzzz_0, tg_xyyy_xxxzzzz_1, \
                                         tg_xyyy_xxyyyyy_0, tg_xyyy_xxyyyyy_1, tg_xyyy_xxyyyyz_0, tg_xyyy_xxyyyyz_1, \
                                         tg_xyyy_xxyyyzz_0, tg_xyyy_xxyyyzz_1, tg_xyyy_xxyyzzz_0, tg_xyyy_xxyyzzz_1, \
                                         tg_xyyy_xxyzzzz_0, tg_xyyy_xxyzzzz_1, tg_xyyy_xxzzzzz_0, tg_xyyy_xxzzzzz_1, \
                                         tg_xyyy_xyyyyyy_0, tg_xyyy_xyyyyyy_1, tg_xyyy_xyyyyyz_0, tg_xyyy_xyyyyyz_1, \
                                         tg_xyyy_xyyyyzz_0, tg_xyyy_xyyyyzz_1, tg_xyyy_xyyyzzz_0, tg_xyyy_xyyyzzz_1, \
                                         tg_xyyy_xyyzzzz_0, tg_xyyy_xyyzzzz_1, tg_xyyy_xyzzzzz_0, tg_xyyy_xyzzzzz_1, \
                                         tg_xyyy_xzzzzzz_0, tg_xyyy_xzzzzzz_1, tg_xyyy_yyyyyyy_0, tg_xyyy_yyyyyyy_1, \
                                         tg_xyyy_yyyyyyz_0, tg_xyyy_yyyyyyz_1, tg_xyyy_yyyyyzz_0, tg_xyyy_yyyyyzz_1, \
                                         tg_xyyy_yyyyzzz_0, tg_xyyy_yyyyzzz_1, tg_xyyy_yyyzzzz_0, tg_xyyy_yyyzzzz_1, \
                                         tg_xyyy_yyzzzzz_0, tg_xyyy_yyzzzzz_1, tg_xyyy_yzzzzzz_0, tg_xyyy_yzzzzzz_1, \
                                         tg_xyyy_zzzzzzz_0, tg_xyyy_zzzzzzz_1, tg_xyyz_xxxxxxx_0, tg_xyyz_xxxxxxx_1, \
                                         tg_xyyz_xxxxxxy_0, tg_xyyz_xxxxxxy_1, tg_xyyz_xxxxxxz_0, tg_xyyz_xxxxxxz_1, \
                                         tg_xyyz_xxxxxyy_0, tg_xyyz_xxxxxyy_1, tg_xyyz_xxxxxyz_0, tg_xyyz_xxxxxyz_1, \
                                         tg_xyyz_xxxxxzz_0, tg_xyyz_xxxxxzz_1, tg_xyyz_xxxxyyy_0, tg_xyyz_xxxxyyy_1, \
                                         tg_xyyz_xxxxyyz_0, tg_xyyz_xxxxyyz_1, tg_xyyz_xxxxyzz_0, tg_xyyz_xxxxyzz_1, \
                                         tg_xyyz_xxxxzzz_0, tg_xyyz_xxxxzzz_1, tg_xyyz_xxxyyyy_0, tg_xyyz_xxxyyyy_1, \
                                         tg_xyyz_xxxyyyz_0, tg_xyyz_xxxyyyz_1, tg_xyyz_xxxyyzz_0, tg_xyyz_xxxyyzz_1, \
                                         tg_xyyz_xxxyzzz_0, tg_xyyz_xxxyzzz_1, tg_xyyz_xxxzzzz_0, tg_xyyz_xxxzzzz_1, \
                                         tg_xyyz_xxyyyyy_0, tg_xyyz_xxyyyyy_1, tg_xyyz_xxyyyyz_0, tg_xyyz_xxyyyyz_1, \
                                         tg_xyyz_xxyyyzz_0, tg_xyyz_xxyyyzz_1, tg_xyyz_xxyyzzz_0, tg_xyyz_xxyyzzz_1, \
                                         tg_xyyz_xxyzzzz_0, tg_xyyz_xxyzzzz_1, tg_xyyz_xxzzzzz_0, tg_xyyz_xxzzzzz_1, \
                                         tg_xyyz_xyyyyyy_0, tg_xyyz_xyyyyyy_1, tg_xyyz_xyyyyyz_0, tg_xyyz_xyyyyyz_1, \
                                         tg_xyyz_xyyyyzz_0, tg_xyyz_xyyyyzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxxzz_xxxxxyz_0[j] = pb_x * tg_xxxzz_xxxxxyz_0[j] + fr * tg_xxxzz_xxxxxyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxyz_0[j] - tg_xxzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxzz_xxxxyz_1[j];

                    tg_xxxxzz_xxxxxzz_0[j] = pb_x * tg_xxxzz_xxxxxzz_0[j] + fr * tg_xxxzz_xxxxxzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxxzz_0[j] - tg_xxzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxxzz_xxxxzz_1[j];

                    tg_xxxxzz_xxxxyyy_0[j] = pb_x * tg_xxxzz_xxxxyyy_0[j] + fr * tg_xxxzz_xxxxyyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxyyy_0[j] - tg_xxzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxzz_xxxyyy_1[j];

                    tg_xxxxzz_xxxxyyz_0[j] = pb_x * tg_xxxzz_xxxxyyz_0[j] + fr * tg_xxxzz_xxxxyyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxyyz_0[j] - tg_xxzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxzz_xxxyyz_1[j];

                    tg_xxxxzz_xxxxyzz_0[j] = pb_x * tg_xxxzz_xxxxyzz_0[j] + fr * tg_xxxzz_xxxxyzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxyzz_0[j] - tg_xxzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxzz_xxxyzz_1[j];

                    tg_xxxxzz_xxxxzzz_0[j] = pb_x * tg_xxxzz_xxxxzzz_0[j] + fr * tg_xxxzz_xxxxzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxxzzz_0[j] - tg_xxzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxxzz_xxxzzz_1[j];

                    tg_xxxxzz_xxxyyyy_0[j] = pb_x * tg_xxxzz_xxxyyyy_0[j] + fr * tg_xxxzz_xxxyyyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxyyyy_0[j] - tg_xxzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xxyyyy_1[j];

                    tg_xxxxzz_xxxyyyz_0[j] = pb_x * tg_xxxzz_xxxyyyz_0[j] + fr * tg_xxxzz_xxxyyyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxyyyz_0[j] - tg_xxzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xxyyyz_1[j];

                    tg_xxxxzz_xxxyyzz_0[j] = pb_x * tg_xxxzz_xxxyyzz_0[j] + fr * tg_xxxzz_xxxyyzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxyyzz_0[j] - tg_xxzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xxyyzz_1[j];

                    tg_xxxxzz_xxxyzzz_0[j] = pb_x * tg_xxxzz_xxxyzzz_0[j] + fr * tg_xxxzz_xxxyzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxyzzz_0[j] - tg_xxzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xxyzzz_1[j];

                    tg_xxxxzz_xxxzzzz_0[j] = pb_x * tg_xxxzz_xxxzzzz_0[j] + fr * tg_xxxzz_xxxzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxxzzzz_0[j] - tg_xxzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxxzz_xxzzzz_1[j];

                    tg_xxxxzz_xxyyyyy_0[j] = pb_x * tg_xxxzz_xxyyyyy_0[j] + fr * tg_xxxzz_xxyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxyyyyy_0[j] - tg_xxzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xyyyyy_1[j];

                    tg_xxxxzz_xxyyyyz_0[j] = pb_x * tg_xxxzz_xxyyyyz_0[j] + fr * tg_xxxzz_xxyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxyyyyz_0[j] - tg_xxzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xyyyyz_1[j];

                    tg_xxxxzz_xxyyyzz_0[j] = pb_x * tg_xxxzz_xxyyyzz_0[j] + fr * tg_xxxzz_xxyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxyyyzz_0[j] - tg_xxzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xyyyzz_1[j];

                    tg_xxxxzz_xxyyzzz_0[j] = pb_x * tg_xxxzz_xxyyzzz_0[j] + fr * tg_xxxzz_xxyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxyyzzz_0[j] - tg_xxzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xyyzzz_1[j];

                    tg_xxxxzz_xxyzzzz_0[j] = pb_x * tg_xxxzz_xxyzzzz_0[j] + fr * tg_xxxzz_xxyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxyzzzz_0[j] - tg_xxzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xyzzzz_1[j];

                    tg_xxxxzz_xxzzzzz_0[j] = pb_x * tg_xxxzz_xxzzzzz_0[j] + fr * tg_xxxzz_xxzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xxzzzzz_0[j] - tg_xxzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxxzz_xzzzzz_1[j];

                    tg_xxxxzz_xyyyyyy_0[j] = pb_x * tg_xxxzz_xyyyyyy_0[j] + fr * tg_xxxzz_xyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyyyyyy_0[j] - tg_xxzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yyyyyy_1[j];

                    tg_xxxxzz_xyyyyyz_0[j] = pb_x * tg_xxxzz_xyyyyyz_0[j] + fr * tg_xxxzz_xyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyyyyyz_0[j] - tg_xxzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yyyyyz_1[j];

                    tg_xxxxzz_xyyyyzz_0[j] = pb_x * tg_xxxzz_xyyyyzz_0[j] + fr * tg_xxxzz_xyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyyyyzz_0[j] - tg_xxzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yyyyzz_1[j];

                    tg_xxxxzz_xyyyzzz_0[j] = pb_x * tg_xxxzz_xyyyzzz_0[j] + fr * tg_xxxzz_xyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyyyzzz_0[j] - tg_xxzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yyyzzz_1[j];

                    tg_xxxxzz_xyyzzzz_0[j] = pb_x * tg_xxxzz_xyyzzzz_0[j] + fr * tg_xxxzz_xyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyyzzzz_0[j] - tg_xxzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yyzzzz_1[j];

                    tg_xxxxzz_xyzzzzz_0[j] = pb_x * tg_xxxzz_xyzzzzz_0[j] + fr * tg_xxxzz_xyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xyzzzzz_0[j] - tg_xxzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_yzzzzz_1[j];

                    tg_xxxxzz_xzzzzzz_0[j] = pb_x * tg_xxxzz_xzzzzzz_0[j] + fr * tg_xxxzz_xzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_xzzzzzz_0[j] - tg_xxzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxxzz_zzzzzz_1[j];

                    tg_xxxxzz_yyyyyyy_0[j] = pb_x * tg_xxxzz_yyyyyyy_0[j] + fr * tg_xxxzz_yyyyyyy_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyyyyyy_0[j] - tg_xxzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxxzz_yyyyyyz_0[j] = pb_x * tg_xxxzz_yyyyyyz_0[j] + fr * tg_xxxzz_yyyyyyz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyyyyyz_0[j] - tg_xxzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxxzz_yyyyyzz_0[j] = pb_x * tg_xxxzz_yyyyyzz_0[j] + fr * tg_xxxzz_yyyyyzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyyyyzz_0[j] - tg_xxzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxxzz_yyyyzzz_0[j] = pb_x * tg_xxxzz_yyyyzzz_0[j] + fr * tg_xxxzz_yyyyzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyyyzzz_0[j] - tg_xxzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxxzz_yyyzzzz_0[j] = pb_x * tg_xxxzz_yyyzzzz_0[j] + fr * tg_xxxzz_yyyzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyyzzzz_0[j] - tg_xxzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxxzz_yyzzzzz_0[j] = pb_x * tg_xxxzz_yyzzzzz_0[j] + fr * tg_xxxzz_yyzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yyzzzzz_0[j] - tg_xxzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxxzz_yzzzzzz_0[j] = pb_x * tg_xxxzz_yzzzzzz_0[j] + fr * tg_xxxzz_yzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_yzzzzzz_0[j] - tg_xxzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxxzz_zzzzzzz_0[j] = pb_x * tg_xxxzz_zzzzzzz_0[j] + fr * tg_xxxzz_zzzzzzz_1[j] + 1.5 * fl1_fx * (tg_xxzz_zzzzzzz_0[j] - tg_xxzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxyyy_xxxxxxx_0[j] = pb_x * tg_xxyyy_xxxxxxx_0[j] + fr * tg_xxyyy_xxxxxxx_1[j] + fl1_fx * (tg_xyyy_xxxxxxx_0[j] - tg_xyyy_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxyyy_xxxxxx_1[j];

                    tg_xxxyyy_xxxxxxy_0[j] = pb_x * tg_xxyyy_xxxxxxy_0[j] + fr * tg_xxyyy_xxxxxxy_1[j] + fl1_fx * (tg_xyyy_xxxxxxy_0[j] - tg_xyyy_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyyy_xxxxxy_1[j];

                    tg_xxxyyy_xxxxxxz_0[j] = pb_x * tg_xxyyy_xxxxxxz_0[j] + fr * tg_xxyyy_xxxxxxz_1[j] + fl1_fx * (tg_xyyy_xxxxxxz_0[j] - tg_xyyy_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyyy_xxxxxz_1[j];

                    tg_xxxyyy_xxxxxyy_0[j] = pb_x * tg_xxyyy_xxxxxyy_0[j] + fr * tg_xxyyy_xxxxxyy_1[j] + fl1_fx * (tg_xyyy_xxxxxyy_0[j] - tg_xyyy_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyy_xxxxyy_1[j];

                    tg_xxxyyy_xxxxxyz_0[j] = pb_x * tg_xxyyy_xxxxxyz_0[j] + fr * tg_xxyyy_xxxxxyz_1[j] + fl1_fx * (tg_xyyy_xxxxxyz_0[j] - tg_xyyy_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyy_xxxxyz_1[j];

                    tg_xxxyyy_xxxxxzz_0[j] = pb_x * tg_xxyyy_xxxxxzz_0[j] + fr * tg_xxyyy_xxxxxzz_1[j] + fl1_fx * (tg_xyyy_xxxxxzz_0[j] - tg_xyyy_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyy_xxxxzz_1[j];

                    tg_xxxyyy_xxxxyyy_0[j] = pb_x * tg_xxyyy_xxxxyyy_0[j] + fr * tg_xxyyy_xxxxyyy_1[j] + fl1_fx * (tg_xyyy_xxxxyyy_0[j] - tg_xyyy_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyy_xxxyyy_1[j];

                    tg_xxxyyy_xxxxyyz_0[j] = pb_x * tg_xxyyy_xxxxyyz_0[j] + fr * tg_xxyyy_xxxxyyz_1[j] + fl1_fx * (tg_xyyy_xxxxyyz_0[j] - tg_xyyy_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyy_xxxyyz_1[j];

                    tg_xxxyyy_xxxxyzz_0[j] = pb_x * tg_xxyyy_xxxxyzz_0[j] + fr * tg_xxyyy_xxxxyzz_1[j] + fl1_fx * (tg_xyyy_xxxxyzz_0[j] - tg_xyyy_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyy_xxxyzz_1[j];

                    tg_xxxyyy_xxxxzzz_0[j] = pb_x * tg_xxyyy_xxxxzzz_0[j] + fr * tg_xxyyy_xxxxzzz_1[j] + fl1_fx * (tg_xyyy_xxxxzzz_0[j] - tg_xyyy_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyy_xxxzzz_1[j];

                    tg_xxxyyy_xxxyyyy_0[j] = pb_x * tg_xxyyy_xxxyyyy_0[j] + fr * tg_xxyyy_xxxyyyy_1[j] + fl1_fx * (tg_xyyy_xxxyyyy_0[j] - tg_xyyy_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xxyyyy_1[j];

                    tg_xxxyyy_xxxyyyz_0[j] = pb_x * tg_xxyyy_xxxyyyz_0[j] + fr * tg_xxyyy_xxxyyyz_1[j] + fl1_fx * (tg_xyyy_xxxyyyz_0[j] - tg_xyyy_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xxyyyz_1[j];

                    tg_xxxyyy_xxxyyzz_0[j] = pb_x * tg_xxyyy_xxxyyzz_0[j] + fr * tg_xxyyy_xxxyyzz_1[j] + fl1_fx * (tg_xyyy_xxxyyzz_0[j] - tg_xyyy_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xxyyzz_1[j];

                    tg_xxxyyy_xxxyzzz_0[j] = pb_x * tg_xxyyy_xxxyzzz_0[j] + fr * tg_xxyyy_xxxyzzz_1[j] + fl1_fx * (tg_xyyy_xxxyzzz_0[j] - tg_xyyy_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xxyzzz_1[j];

                    tg_xxxyyy_xxxzzzz_0[j] = pb_x * tg_xxyyy_xxxzzzz_0[j] + fr * tg_xxyyy_xxxzzzz_1[j] + fl1_fx * (tg_xyyy_xxxzzzz_0[j] - tg_xyyy_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyy_xxzzzz_1[j];

                    tg_xxxyyy_xxyyyyy_0[j] = pb_x * tg_xxyyy_xxyyyyy_0[j] + fr * tg_xxyyy_xxyyyyy_1[j] + fl1_fx * (tg_xyyy_xxyyyyy_0[j] - tg_xyyy_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xyyyyy_1[j];

                    tg_xxxyyy_xxyyyyz_0[j] = pb_x * tg_xxyyy_xxyyyyz_0[j] + fr * tg_xxyyy_xxyyyyz_1[j] + fl1_fx * (tg_xyyy_xxyyyyz_0[j] - tg_xyyy_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xyyyyz_1[j];

                    tg_xxxyyy_xxyyyzz_0[j] = pb_x * tg_xxyyy_xxyyyzz_0[j] + fr * tg_xxyyy_xxyyyzz_1[j] + fl1_fx * (tg_xyyy_xxyyyzz_0[j] - tg_xyyy_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xyyyzz_1[j];

                    tg_xxxyyy_xxyyzzz_0[j] = pb_x * tg_xxyyy_xxyyzzz_0[j] + fr * tg_xxyyy_xxyyzzz_1[j] + fl1_fx * (tg_xyyy_xxyyzzz_0[j] - tg_xyyy_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xyyzzz_1[j];

                    tg_xxxyyy_xxyzzzz_0[j] = pb_x * tg_xxyyy_xxyzzzz_0[j] + fr * tg_xxyyy_xxyzzzz_1[j] + fl1_fx * (tg_xyyy_xxyzzzz_0[j] - tg_xyyy_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xyzzzz_1[j];

                    tg_xxxyyy_xxzzzzz_0[j] = pb_x * tg_xxyyy_xxzzzzz_0[j] + fr * tg_xxyyy_xxzzzzz_1[j] + fl1_fx * (tg_xyyy_xxzzzzz_0[j] - tg_xyyy_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyy_xzzzzz_1[j];

                    tg_xxxyyy_xyyyyyy_0[j] = pb_x * tg_xxyyy_xyyyyyy_0[j] + fr * tg_xxyyy_xyyyyyy_1[j] + fl1_fx * (tg_xyyy_xyyyyyy_0[j] - tg_xyyy_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yyyyyy_1[j];

                    tg_xxxyyy_xyyyyyz_0[j] = pb_x * tg_xxyyy_xyyyyyz_0[j] + fr * tg_xxyyy_xyyyyyz_1[j] + fl1_fx * (tg_xyyy_xyyyyyz_0[j] - tg_xyyy_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yyyyyz_1[j];

                    tg_xxxyyy_xyyyyzz_0[j] = pb_x * tg_xxyyy_xyyyyzz_0[j] + fr * tg_xxyyy_xyyyyzz_1[j] + fl1_fx * (tg_xyyy_xyyyyzz_0[j] - tg_xyyy_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yyyyzz_1[j];

                    tg_xxxyyy_xyyyzzz_0[j] = pb_x * tg_xxyyy_xyyyzzz_0[j] + fr * tg_xxyyy_xyyyzzz_1[j] + fl1_fx * (tg_xyyy_xyyyzzz_0[j] - tg_xyyy_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yyyzzz_1[j];

                    tg_xxxyyy_xyyzzzz_0[j] = pb_x * tg_xxyyy_xyyzzzz_0[j] + fr * tg_xxyyy_xyyzzzz_1[j] + fl1_fx * (tg_xyyy_xyyzzzz_0[j] - tg_xyyy_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yyzzzz_1[j];

                    tg_xxxyyy_xyzzzzz_0[j] = pb_x * tg_xxyyy_xyzzzzz_0[j] + fr * tg_xxyyy_xyzzzzz_1[j] + fl1_fx * (tg_xyyy_xyzzzzz_0[j] - tg_xyyy_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_yzzzzz_1[j];

                    tg_xxxyyy_xzzzzzz_0[j] = pb_x * tg_xxyyy_xzzzzzz_0[j] + fr * tg_xxyyy_xzzzzzz_1[j] + fl1_fx * (tg_xyyy_xzzzzzz_0[j] - tg_xyyy_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyy_zzzzzz_1[j];

                    tg_xxxyyy_yyyyyyy_0[j] = pb_x * tg_xxyyy_yyyyyyy_0[j] + fr * tg_xxyyy_yyyyyyy_1[j] + fl1_fx * (tg_xyyy_yyyyyyy_0[j] - tg_xyyy_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxyyy_yyyyyyz_0[j] = pb_x * tg_xxyyy_yyyyyyz_0[j] + fr * tg_xxyyy_yyyyyyz_1[j] + fl1_fx * (tg_xyyy_yyyyyyz_0[j] - tg_xyyy_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxyyy_yyyyyzz_0[j] = pb_x * tg_xxyyy_yyyyyzz_0[j] + fr * tg_xxyyy_yyyyyzz_1[j] + fl1_fx * (tg_xyyy_yyyyyzz_0[j] - tg_xyyy_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxyyy_yyyyzzz_0[j] = pb_x * tg_xxyyy_yyyyzzz_0[j] + fr * tg_xxyyy_yyyyzzz_1[j] + fl1_fx * (tg_xyyy_yyyyzzz_0[j] - tg_xyyy_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxyyy_yyyzzzz_0[j] = pb_x * tg_xxyyy_yyyzzzz_0[j] + fr * tg_xxyyy_yyyzzzz_1[j] + fl1_fx * (tg_xyyy_yyyzzzz_0[j] - tg_xyyy_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxyyy_yyzzzzz_0[j] = pb_x * tg_xxyyy_yyzzzzz_0[j] + fr * tg_xxyyy_yyzzzzz_1[j] + fl1_fx * (tg_xyyy_yyzzzzz_0[j] - tg_xyyy_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxyyy_yzzzzzz_0[j] = pb_x * tg_xxyyy_yzzzzzz_0[j] + fr * tg_xxyyy_yzzzzzz_1[j] + fl1_fx * (tg_xyyy_yzzzzzz_0[j] - tg_xyyy_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxyyy_zzzzzzz_0[j] = pb_x * tg_xxyyy_zzzzzzz_0[j] + fr * tg_xxyyy_zzzzzzz_1[j] + fl1_fx * (tg_xyyy_zzzzzzz_0[j] - tg_xyyy_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxyyz_xxxxxxx_0[j] = pb_x * tg_xxyyz_xxxxxxx_0[j] + fr * tg_xxyyz_xxxxxxx_1[j] + fl1_fx * (tg_xyyz_xxxxxxx_0[j] - tg_xyyz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxyyz_xxxxxx_1[j];

                    tg_xxxyyz_xxxxxxy_0[j] = pb_x * tg_xxyyz_xxxxxxy_0[j] + fr * tg_xxyyz_xxxxxxy_1[j] + fl1_fx * (tg_xyyz_xxxxxxy_0[j] - tg_xyyz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyyz_xxxxxy_1[j];

                    tg_xxxyyz_xxxxxxz_0[j] = pb_x * tg_xxyyz_xxxxxxz_0[j] + fr * tg_xxyyz_xxxxxxz_1[j] + fl1_fx * (tg_xyyz_xxxxxxz_0[j] - tg_xyyz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyyz_xxxxxz_1[j];

                    tg_xxxyyz_xxxxxyy_0[j] = pb_x * tg_xxyyz_xxxxxyy_0[j] + fr * tg_xxyyz_xxxxxyy_1[j] + fl1_fx * (tg_xyyz_xxxxxyy_0[j] - tg_xyyz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyz_xxxxyy_1[j];

                    tg_xxxyyz_xxxxxyz_0[j] = pb_x * tg_xxyyz_xxxxxyz_0[j] + fr * tg_xxyyz_xxxxxyz_1[j] + fl1_fx * (tg_xyyz_xxxxxyz_0[j] - tg_xyyz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyz_xxxxyz_1[j];

                    tg_xxxyyz_xxxxxzz_0[j] = pb_x * tg_xxyyz_xxxxxzz_0[j] + fr * tg_xxyyz_xxxxxzz_1[j] + fl1_fx * (tg_xyyz_xxxxxzz_0[j] - tg_xyyz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyyz_xxxxzz_1[j];

                    tg_xxxyyz_xxxxyyy_0[j] = pb_x * tg_xxyyz_xxxxyyy_0[j] + fr * tg_xxyyz_xxxxyyy_1[j] + fl1_fx * (tg_xyyz_xxxxyyy_0[j] - tg_xyyz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyz_xxxyyy_1[j];

                    tg_xxxyyz_xxxxyyz_0[j] = pb_x * tg_xxyyz_xxxxyyz_0[j] + fr * tg_xxyyz_xxxxyyz_1[j] + fl1_fx * (tg_xyyz_xxxxyyz_0[j] - tg_xyyz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyz_xxxyyz_1[j];

                    tg_xxxyyz_xxxxyzz_0[j] = pb_x * tg_xxyyz_xxxxyzz_0[j] + fr * tg_xxyyz_xxxxyzz_1[j] + fl1_fx * (tg_xyyz_xxxxyzz_0[j] - tg_xyyz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyz_xxxyzz_1[j];

                    tg_xxxyyz_xxxxzzz_0[j] = pb_x * tg_xxyyz_xxxxzzz_0[j] + fr * tg_xxyyz_xxxxzzz_1[j] + fl1_fx * (tg_xyyz_xxxxzzz_0[j] - tg_xyyz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyyz_xxxzzz_1[j];

                    tg_xxxyyz_xxxyyyy_0[j] = pb_x * tg_xxyyz_xxxyyyy_0[j] + fr * tg_xxyyz_xxxyyyy_1[j] + fl1_fx * (tg_xyyz_xxxyyyy_0[j] - tg_xyyz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xxyyyy_1[j];

                    tg_xxxyyz_xxxyyyz_0[j] = pb_x * tg_xxyyz_xxxyyyz_0[j] + fr * tg_xxyyz_xxxyyyz_1[j] + fl1_fx * (tg_xyyz_xxxyyyz_0[j] - tg_xyyz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xxyyyz_1[j];

                    tg_xxxyyz_xxxyyzz_0[j] = pb_x * tg_xxyyz_xxxyyzz_0[j] + fr * tg_xxyyz_xxxyyzz_1[j] + fl1_fx * (tg_xyyz_xxxyyzz_0[j] - tg_xyyz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xxyyzz_1[j];

                    tg_xxxyyz_xxxyzzz_0[j] = pb_x * tg_xxyyz_xxxyzzz_0[j] + fr * tg_xxyyz_xxxyzzz_1[j] + fl1_fx * (tg_xyyz_xxxyzzz_0[j] - tg_xyyz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xxyzzz_1[j];

                    tg_xxxyyz_xxxzzzz_0[j] = pb_x * tg_xxyyz_xxxzzzz_0[j] + fr * tg_xxyyz_xxxzzzz_1[j] + fl1_fx * (tg_xyyz_xxxzzzz_0[j] - tg_xyyz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyyz_xxzzzz_1[j];

                    tg_xxxyyz_xxyyyyy_0[j] = pb_x * tg_xxyyz_xxyyyyy_0[j] + fr * tg_xxyyz_xxyyyyy_1[j] + fl1_fx * (tg_xyyz_xxyyyyy_0[j] - tg_xyyz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xyyyyy_1[j];

                    tg_xxxyyz_xxyyyyz_0[j] = pb_x * tg_xxyyz_xxyyyyz_0[j] + fr * tg_xxyyz_xxyyyyz_1[j] + fl1_fx * (tg_xyyz_xxyyyyz_0[j] - tg_xyyz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xyyyyz_1[j];

                    tg_xxxyyz_xxyyyzz_0[j] = pb_x * tg_xxyyz_xxyyyzz_0[j] + fr * tg_xxyyz_xxyyyzz_1[j] + fl1_fx * (tg_xyyz_xxyyyzz_0[j] - tg_xyyz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xyyyzz_1[j];

                    tg_xxxyyz_xxyyzzz_0[j] = pb_x * tg_xxyyz_xxyyzzz_0[j] + fr * tg_xxyyz_xxyyzzz_1[j] + fl1_fx * (tg_xyyz_xxyyzzz_0[j] - tg_xyyz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xyyzzz_1[j];

                    tg_xxxyyz_xxyzzzz_0[j] = pb_x * tg_xxyyz_xxyzzzz_0[j] + fr * tg_xxyyz_xxyzzzz_1[j] + fl1_fx * (tg_xyyz_xxyzzzz_0[j] - tg_xyyz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xyzzzz_1[j];

                    tg_xxxyyz_xxzzzzz_0[j] = pb_x * tg_xxyyz_xxzzzzz_0[j] + fr * tg_xxyyz_xxzzzzz_1[j] + fl1_fx * (tg_xyyz_xxzzzzz_0[j] - tg_xyyz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyyz_xzzzzz_1[j];

                    tg_xxxyyz_xyyyyyy_0[j] = pb_x * tg_xxyyz_xyyyyyy_0[j] + fr * tg_xxyyz_xyyyyyy_1[j] + fl1_fx * (tg_xyyz_xyyyyyy_0[j] - tg_xyyz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yyyyyy_1[j];

                    tg_xxxyyz_xyyyyyz_0[j] = pb_x * tg_xxyyz_xyyyyyz_0[j] + fr * tg_xxyyz_xyyyyyz_1[j] + fl1_fx * (tg_xyyz_xyyyyyz_0[j] - tg_xyyz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yyyyyz_1[j];

                    tg_xxxyyz_xyyyyzz_0[j] = pb_x * tg_xxyyz_xyyyyzz_0[j] + fr * tg_xxyyz_xyyyyzz_1[j] + fl1_fx * (tg_xyyz_xyyyyzz_0[j] - tg_xyyz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yyyyzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_276_368(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (276,368)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xxyyz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 276); 

                auto tg_xxyyz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 277); 

                auto tg_xxyyz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 278); 

                auto tg_xxyyz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 279); 

                auto tg_xxyyz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 280); 

                auto tg_xxyyz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 281); 

                auto tg_xxyyz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 282); 

                auto tg_xxyyz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 283); 

                auto tg_xxyyz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 284); 

                auto tg_xxyyz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 285); 

                auto tg_xxyyz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 286); 

                auto tg_xxyyz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 287); 

                auto tg_xxyzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 288); 

                auto tg_xxyzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 289); 

                auto tg_xxyzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 290); 

                auto tg_xxyzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 291); 

                auto tg_xxyzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 292); 

                auto tg_xxyzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 293); 

                auto tg_xxyzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 294); 

                auto tg_xxyzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 295); 

                auto tg_xxyzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 296); 

                auto tg_xxyzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 297); 

                auto tg_xxyzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 298); 

                auto tg_xxyzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 299); 

                auto tg_xxyzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 300); 

                auto tg_xxyzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 301); 

                auto tg_xxyzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 302); 

                auto tg_xxyzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 303); 

                auto tg_xxyzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 304); 

                auto tg_xxyzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 305); 

                auto tg_xxyzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 306); 

                auto tg_xxyzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 307); 

                auto tg_xxyzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 308); 

                auto tg_xxyzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 309); 

                auto tg_xxyzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 310); 

                auto tg_xxyzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 311); 

                auto tg_xxyzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 312); 

                auto tg_xxyzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 313); 

                auto tg_xxyzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 314); 

                auto tg_xxyzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 315); 

                auto tg_xxyzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 316); 

                auto tg_xxyzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 317); 

                auto tg_xxyzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 318); 

                auto tg_xxyzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 319); 

                auto tg_xxyzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 320); 

                auto tg_xxyzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 321); 

                auto tg_xxyzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 322); 

                auto tg_xxyzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 323); 

                auto tg_xxzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 324); 

                auto tg_xxzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 325); 

                auto tg_xxzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 326); 

                auto tg_xxzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 327); 

                auto tg_xxzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 328); 

                auto tg_xxzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 329); 

                auto tg_xxzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 330); 

                auto tg_xxzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 331); 

                auto tg_xxzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 332); 

                auto tg_xxzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 333); 

                auto tg_xxzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 334); 

                auto tg_xxzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 335); 

                auto tg_xxzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 336); 

                auto tg_xxzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 337); 

                auto tg_xxzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 338); 

                auto tg_xxzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 339); 

                auto tg_xxzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 340); 

                auto tg_xxzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 341); 

                auto tg_xxzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 342); 

                auto tg_xxzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 343); 

                auto tg_xxzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 344); 

                auto tg_xxzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 345); 

                auto tg_xxzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 346); 

                auto tg_xxzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 347); 

                auto tg_xxzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 348); 

                auto tg_xxzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 349); 

                auto tg_xxzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 350); 

                auto tg_xxzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 351); 

                auto tg_xxzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 352); 

                auto tg_xxzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 353); 

                auto tg_xxzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 354); 

                auto tg_xxzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 355); 

                auto tg_xxzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 356); 

                auto tg_xxzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 357); 

                auto tg_xxzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 358); 

                auto tg_xxzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 359); 

                auto tg_xyyyy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 360); 

                auto tg_xyyyy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 361); 

                auto tg_xyyyy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 362); 

                auto tg_xyyyy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 363); 

                auto tg_xyyyy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 364); 

                auto tg_xyyyy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 365); 

                auto tg_xyyyy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 366); 

                auto tg_xyyyy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 367); 

                auto tg_xxyyz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 276); 

                auto tg_xxyyz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 277); 

                auto tg_xxyyz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 278); 

                auto tg_xxyyz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 279); 

                auto tg_xxyyz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 280); 

                auto tg_xxyyz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 281); 

                auto tg_xxyyz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 282); 

                auto tg_xxyyz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 283); 

                auto tg_xxyyz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 284); 

                auto tg_xxyyz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 285); 

                auto tg_xxyyz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 286); 

                auto tg_xxyyz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 287); 

                auto tg_xxyzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 288); 

                auto tg_xxyzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 289); 

                auto tg_xxyzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 290); 

                auto tg_xxyzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 291); 

                auto tg_xxyzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 292); 

                auto tg_xxyzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 293); 

                auto tg_xxyzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 294); 

                auto tg_xxyzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 295); 

                auto tg_xxyzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 296); 

                auto tg_xxyzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 297); 

                auto tg_xxyzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 298); 

                auto tg_xxyzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 299); 

                auto tg_xxyzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 300); 

                auto tg_xxyzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 301); 

                auto tg_xxyzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 302); 

                auto tg_xxyzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 303); 

                auto tg_xxyzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 304); 

                auto tg_xxyzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 305); 

                auto tg_xxyzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 306); 

                auto tg_xxyzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 307); 

                auto tg_xxyzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 308); 

                auto tg_xxyzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 309); 

                auto tg_xxyzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 310); 

                auto tg_xxyzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 311); 

                auto tg_xxyzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 312); 

                auto tg_xxyzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 313); 

                auto tg_xxyzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 314); 

                auto tg_xxyzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 315); 

                auto tg_xxyzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 316); 

                auto tg_xxyzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 317); 

                auto tg_xxyzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 318); 

                auto tg_xxyzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 319); 

                auto tg_xxyzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 320); 

                auto tg_xxyzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 321); 

                auto tg_xxyzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 322); 

                auto tg_xxyzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 323); 

                auto tg_xxzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 324); 

                auto tg_xxzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 325); 

                auto tg_xxzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 326); 

                auto tg_xxzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 327); 

                auto tg_xxzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 328); 

                auto tg_xxzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 329); 

                auto tg_xxzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 330); 

                auto tg_xxzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 331); 

                auto tg_xxzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 332); 

                auto tg_xxzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 333); 

                auto tg_xxzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 334); 

                auto tg_xxzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 335); 

                auto tg_xxzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 336); 

                auto tg_xxzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 337); 

                auto tg_xxzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 338); 

                auto tg_xxzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 339); 

                auto tg_xxzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 340); 

                auto tg_xxzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 341); 

                auto tg_xxzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 342); 

                auto tg_xxzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 343); 

                auto tg_xxzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 344); 

                auto tg_xxzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 345); 

                auto tg_xxzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 346); 

                auto tg_xxzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 347); 

                auto tg_xxzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 348); 

                auto tg_xxzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 349); 

                auto tg_xxzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 350); 

                auto tg_xxzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 351); 

                auto tg_xxzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 352); 

                auto tg_xxzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 353); 

                auto tg_xxzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 354); 

                auto tg_xxzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 355); 

                auto tg_xxzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 356); 

                auto tg_xxzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 357); 

                auto tg_xxzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 358); 

                auto tg_xxzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 359); 

                auto tg_xyyyy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 360); 

                auto tg_xyyyy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 361); 

                auto tg_xyyyy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 362); 

                auto tg_xyyyy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 363); 

                auto tg_xyyyy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 364); 

                auto tg_xyyyy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 365); 

                auto tg_xyyyy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 366); 

                auto tg_xyyyy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 367); 

                auto tg_xyyz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 276); 

                auto tg_xyyz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 277); 

                auto tg_xyyz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 278); 

                auto tg_xyyz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 279); 

                auto tg_xyyz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 280); 

                auto tg_xyyz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 281); 

                auto tg_xyyz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 282); 

                auto tg_xyyz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 283); 

                auto tg_xyyz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 284); 

                auto tg_xyyz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 285); 

                auto tg_xyyz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 286); 

                auto tg_xyyz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 287); 

                auto tg_xyzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 288); 

                auto tg_xyzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 289); 

                auto tg_xyzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 290); 

                auto tg_xyzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 291); 

                auto tg_xyzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 292); 

                auto tg_xyzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 293); 

                auto tg_xyzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 294); 

                auto tg_xyzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 295); 

                auto tg_xyzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 296); 

                auto tg_xyzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 297); 

                auto tg_xyzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 298); 

                auto tg_xyzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 299); 

                auto tg_xyzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 300); 

                auto tg_xyzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 301); 

                auto tg_xyzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 302); 

                auto tg_xyzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 303); 

                auto tg_xyzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 304); 

                auto tg_xyzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 305); 

                auto tg_xyzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 306); 

                auto tg_xyzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 307); 

                auto tg_xyzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 308); 

                auto tg_xyzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 309); 

                auto tg_xyzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 310); 

                auto tg_xyzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 311); 

                auto tg_xyzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 312); 

                auto tg_xyzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 313); 

                auto tg_xyzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 314); 

                auto tg_xyzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 315); 

                auto tg_xyzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 316); 

                auto tg_xyzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 317); 

                auto tg_xyzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 318); 

                auto tg_xyzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 319); 

                auto tg_xyzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 320); 

                auto tg_xyzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 321); 

                auto tg_xyzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 322); 

                auto tg_xyzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 323); 

                auto tg_xzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 324); 

                auto tg_xzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 325); 

                auto tg_xzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 326); 

                auto tg_xzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 327); 

                auto tg_xzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 328); 

                auto tg_xzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 329); 

                auto tg_xzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 330); 

                auto tg_xzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 331); 

                auto tg_xzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 332); 

                auto tg_xzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 333); 

                auto tg_xzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 334); 

                auto tg_xzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 335); 

                auto tg_xzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 336); 

                auto tg_xzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 337); 

                auto tg_xzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 338); 

                auto tg_xzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 339); 

                auto tg_xzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 340); 

                auto tg_xzzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 341); 

                auto tg_xzzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 342); 

                auto tg_xzzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 343); 

                auto tg_xzzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 344); 

                auto tg_xzzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 345); 

                auto tg_xzzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 346); 

                auto tg_xzzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 347); 

                auto tg_xzzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 348); 

                auto tg_xzzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 349); 

                auto tg_xzzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 350); 

                auto tg_xzzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 351); 

                auto tg_xzzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 352); 

                auto tg_xzzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 353); 

                auto tg_xzzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 354); 

                auto tg_xzzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 355); 

                auto tg_xzzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 356); 

                auto tg_xzzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 357); 

                auto tg_xzzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 358); 

                auto tg_xzzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 359); 

                auto tg_yyyy_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 360); 

                auto tg_yyyy_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 361); 

                auto tg_yyyy_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 362); 

                auto tg_yyyy_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 363); 

                auto tg_yyyy_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 364); 

                auto tg_yyyy_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 365); 

                auto tg_yyyy_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 366); 

                auto tg_yyyy_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 367); 

                auto tg_xyyz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 276); 

                auto tg_xyyz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 277); 

                auto tg_xyyz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 278); 

                auto tg_xyyz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 279); 

                auto tg_xyyz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 280); 

                auto tg_xyyz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 281); 

                auto tg_xyyz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 282); 

                auto tg_xyyz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 283); 

                auto tg_xyyz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 284); 

                auto tg_xyyz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 285); 

                auto tg_xyyz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 286); 

                auto tg_xyyz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 287); 

                auto tg_xyzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 288); 

                auto tg_xyzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 289); 

                auto tg_xyzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 290); 

                auto tg_xyzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 291); 

                auto tg_xyzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 292); 

                auto tg_xyzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 293); 

                auto tg_xyzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 294); 

                auto tg_xyzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 295); 

                auto tg_xyzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 296); 

                auto tg_xyzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 297); 

                auto tg_xyzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 298); 

                auto tg_xyzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 299); 

                auto tg_xyzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 300); 

                auto tg_xyzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 301); 

                auto tg_xyzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 302); 

                auto tg_xyzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 303); 

                auto tg_xyzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 304); 

                auto tg_xyzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 305); 

                auto tg_xyzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 306); 

                auto tg_xyzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 307); 

                auto tg_xyzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 308); 

                auto tg_xyzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 309); 

                auto tg_xyzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 310); 

                auto tg_xyzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 311); 

                auto tg_xyzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 312); 

                auto tg_xyzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 313); 

                auto tg_xyzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 314); 

                auto tg_xyzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 315); 

                auto tg_xyzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 316); 

                auto tg_xyzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 317); 

                auto tg_xyzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 318); 

                auto tg_xyzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 319); 

                auto tg_xyzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 320); 

                auto tg_xyzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 321); 

                auto tg_xyzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 322); 

                auto tg_xyzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 323); 

                auto tg_xzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 324); 

                auto tg_xzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 325); 

                auto tg_xzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 326); 

                auto tg_xzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 327); 

                auto tg_xzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 328); 

                auto tg_xzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 329); 

                auto tg_xzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 330); 

                auto tg_xzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 331); 

                auto tg_xzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 332); 

                auto tg_xzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 333); 

                auto tg_xzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 334); 

                auto tg_xzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 335); 

                auto tg_xzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 336); 

                auto tg_xzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 337); 

                auto tg_xzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 338); 

                auto tg_xzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 339); 

                auto tg_xzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 340); 

                auto tg_xzzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 341); 

                auto tg_xzzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 342); 

                auto tg_xzzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 343); 

                auto tg_xzzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 344); 

                auto tg_xzzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 345); 

                auto tg_xzzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 346); 

                auto tg_xzzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 347); 

                auto tg_xzzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 348); 

                auto tg_xzzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 349); 

                auto tg_xzzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 350); 

                auto tg_xzzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 351); 

                auto tg_xzzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 352); 

                auto tg_xzzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 353); 

                auto tg_xzzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 354); 

                auto tg_xzzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 355); 

                auto tg_xzzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 356); 

                auto tg_xzzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 357); 

                auto tg_xzzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 358); 

                auto tg_xzzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 359); 

                auto tg_yyyy_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 360); 

                auto tg_yyyy_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 361); 

                auto tg_yyyy_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 362); 

                auto tg_yyyy_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 363); 

                auto tg_yyyy_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 364); 

                auto tg_yyyy_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 365); 

                auto tg_yyyy_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 366); 

                auto tg_yyyy_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 367); 

                auto tg_xxyyz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 220); 

                auto tg_xxyyz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 221); 

                auto tg_xxyyz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 222); 

                auto tg_xxyyz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 223); 

                auto tg_xxyzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 224); 

                auto tg_xxyzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 225); 

                auto tg_xxyzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 226); 

                auto tg_xxyzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 227); 

                auto tg_xxyzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 228); 

                auto tg_xxyzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 229); 

                auto tg_xxyzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 230); 

                auto tg_xxyzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 231); 

                auto tg_xxyzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 232); 

                auto tg_xxyzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 233); 

                auto tg_xxyzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 234); 

                auto tg_xxyzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 235); 

                auto tg_xxyzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 236); 

                auto tg_xxyzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 237); 

                auto tg_xxyzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 238); 

                auto tg_xxyzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 239); 

                auto tg_xxyzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 240); 

                auto tg_xxyzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 241); 

                auto tg_xxyzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 242); 

                auto tg_xxyzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 243); 

                auto tg_xxyzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 244); 

                auto tg_xxyzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 245); 

                auto tg_xxyzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 246); 

                auto tg_xxyzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 247); 

                auto tg_xxyzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 248); 

                auto tg_xxyzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 249); 

                auto tg_xxyzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 250); 

                auto tg_xxyzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 251); 

                auto tg_xxzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 252); 

                auto tg_xxzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 253); 

                auto tg_xxzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 254); 

                auto tg_xxzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 255); 

                auto tg_xxzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 256); 

                auto tg_xxzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 257); 

                auto tg_xxzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 258); 

                auto tg_xxzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 259); 

                auto tg_xxzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 260); 

                auto tg_xxzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 261); 

                auto tg_xxzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 262); 

                auto tg_xxzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 263); 

                auto tg_xxzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 264); 

                auto tg_xxzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 265); 

                auto tg_xxzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 266); 

                auto tg_xxzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 267); 

                auto tg_xxzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 268); 

                auto tg_xxzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 269); 

                auto tg_xxzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 270); 

                auto tg_xxzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 271); 

                auto tg_xxzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 272); 

                auto tg_xxzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 273); 

                auto tg_xxzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 274); 

                auto tg_xxzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 275); 

                auto tg_xxzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 276); 

                auto tg_xxzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 277); 

                auto tg_xxzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 278); 

                auto tg_xxzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 279); 

                auto tg_xyyyy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 280); 

                auto tg_xyyyy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 281); 

                auto tg_xyyyy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 282); 

                auto tg_xyyyy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 283); 

                auto tg_xyyyy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 284); 

                auto tg_xyyyy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 285); 

                auto tg_xyyyy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 286); 

                auto tg_xyyyy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 287); 

                // set up pointers to integrals

                auto tg_xxxyyz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 276); 

                auto tg_xxxyyz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 277); 

                auto tg_xxxyyz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 278); 

                auto tg_xxxyyz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 279); 

                auto tg_xxxyyz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 280); 

                auto tg_xxxyyz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 281); 

                auto tg_xxxyyz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 282); 

                auto tg_xxxyyz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 283); 

                auto tg_xxxyyz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 284); 

                auto tg_xxxyyz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 285); 

                auto tg_xxxyyz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 286); 

                auto tg_xxxyyz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 287); 

                auto tg_xxxyzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 288); 

                auto tg_xxxyzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 289); 

                auto tg_xxxyzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 290); 

                auto tg_xxxyzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 291); 

                auto tg_xxxyzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 292); 

                auto tg_xxxyzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 293); 

                auto tg_xxxyzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 294); 

                auto tg_xxxyzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 295); 

                auto tg_xxxyzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 296); 

                auto tg_xxxyzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 297); 

                auto tg_xxxyzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 298); 

                auto tg_xxxyzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 299); 

                auto tg_xxxyzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 300); 

                auto tg_xxxyzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 301); 

                auto tg_xxxyzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 302); 

                auto tg_xxxyzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 303); 

                auto tg_xxxyzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 304); 

                auto tg_xxxyzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 305); 

                auto tg_xxxyzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 306); 

                auto tg_xxxyzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 307); 

                auto tg_xxxyzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 308); 

                auto tg_xxxyzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 309); 

                auto tg_xxxyzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 310); 

                auto tg_xxxyzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 311); 

                auto tg_xxxyzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 312); 

                auto tg_xxxyzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 313); 

                auto tg_xxxyzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 314); 

                auto tg_xxxyzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 315); 

                auto tg_xxxyzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 316); 

                auto tg_xxxyzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 317); 

                auto tg_xxxyzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 318); 

                auto tg_xxxyzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 319); 

                auto tg_xxxyzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 320); 

                auto tg_xxxyzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 321); 

                auto tg_xxxyzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 322); 

                auto tg_xxxyzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 323); 

                auto tg_xxxzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 324); 

                auto tg_xxxzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 325); 

                auto tg_xxxzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 326); 

                auto tg_xxxzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 327); 

                auto tg_xxxzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 328); 

                auto tg_xxxzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 329); 

                auto tg_xxxzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 330); 

                auto tg_xxxzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 331); 

                auto tg_xxxzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 332); 

                auto tg_xxxzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 333); 

                auto tg_xxxzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 334); 

                auto tg_xxxzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 335); 

                auto tg_xxxzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 336); 

                auto tg_xxxzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 337); 

                auto tg_xxxzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 338); 

                auto tg_xxxzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 339); 

                auto tg_xxxzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 340); 

                auto tg_xxxzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 341); 

                auto tg_xxxzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 342); 

                auto tg_xxxzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 343); 

                auto tg_xxxzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 344); 

                auto tg_xxxzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 345); 

                auto tg_xxxzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 346); 

                auto tg_xxxzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 347); 

                auto tg_xxxzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 348); 

                auto tg_xxxzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 349); 

                auto tg_xxxzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 350); 

                auto tg_xxxzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 351); 

                auto tg_xxxzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 352); 

                auto tg_xxxzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 353); 

                auto tg_xxxzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 354); 

                auto tg_xxxzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 355); 

                auto tg_xxxzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 356); 

                auto tg_xxxzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 357); 

                auto tg_xxxzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 358); 

                auto tg_xxxzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 359); 

                auto tg_xxyyyy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 360); 

                auto tg_xxyyyy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 361); 

                auto tg_xxyyyy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 362); 

                auto tg_xxyyyy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 363); 

                auto tg_xxyyyy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 364); 

                auto tg_xxyyyy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 365); 

                auto tg_xxyyyy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 366); 

                auto tg_xxyyyy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 367); 

                // Batch of Integrals (276,368)

                #pragma omp simd aligned(fxn, fza, tg_xxxyyz_xyyyzzz_0, tg_xxxyyz_xyyzzzz_0, \
                                         tg_xxxyyz_xyzzzzz_0, tg_xxxyyz_xzzzzzz_0, tg_xxxyyz_yyyyyyy_0, tg_xxxyyz_yyyyyyz_0, \
                                         tg_xxxyyz_yyyyyzz_0, tg_xxxyyz_yyyyzzz_0, tg_xxxyyz_yyyzzzz_0, tg_xxxyyz_yyzzzzz_0, \
                                         tg_xxxyyz_yzzzzzz_0, tg_xxxyyz_zzzzzzz_0, tg_xxxyzz_xxxxxxx_0, tg_xxxyzz_xxxxxxy_0, \
                                         tg_xxxyzz_xxxxxxz_0, tg_xxxyzz_xxxxxyy_0, tg_xxxyzz_xxxxxyz_0, tg_xxxyzz_xxxxxzz_0, \
                                         tg_xxxyzz_xxxxyyy_0, tg_xxxyzz_xxxxyyz_0, tg_xxxyzz_xxxxyzz_0, tg_xxxyzz_xxxxzzz_0, \
                                         tg_xxxyzz_xxxyyyy_0, tg_xxxyzz_xxxyyyz_0, tg_xxxyzz_xxxyyzz_0, tg_xxxyzz_xxxyzzz_0, \
                                         tg_xxxyzz_xxxzzzz_0, tg_xxxyzz_xxyyyyy_0, tg_xxxyzz_xxyyyyz_0, tg_xxxyzz_xxyyyzz_0, \
                                         tg_xxxyzz_xxyyzzz_0, tg_xxxyzz_xxyzzzz_0, tg_xxxyzz_xxzzzzz_0, tg_xxxyzz_xyyyyyy_0, \
                                         tg_xxxyzz_xyyyyyz_0, tg_xxxyzz_xyyyyzz_0, tg_xxxyzz_xyyyzzz_0, tg_xxxyzz_xyyzzzz_0, \
                                         tg_xxxyzz_xyzzzzz_0, tg_xxxyzz_xzzzzzz_0, tg_xxxyzz_yyyyyyy_0, tg_xxxyzz_yyyyyyz_0, \
                                         tg_xxxyzz_yyyyyzz_0, tg_xxxyzz_yyyyzzz_0, tg_xxxyzz_yyyzzzz_0, tg_xxxyzz_yyzzzzz_0, \
                                         tg_xxxyzz_yzzzzzz_0, tg_xxxyzz_zzzzzzz_0, tg_xxxzzz_xxxxxxx_0, tg_xxxzzz_xxxxxxy_0, \
                                         tg_xxxzzz_xxxxxxz_0, tg_xxxzzz_xxxxxyy_0, tg_xxxzzz_xxxxxyz_0, tg_xxxzzz_xxxxxzz_0, \
                                         tg_xxxzzz_xxxxyyy_0, tg_xxxzzz_xxxxyyz_0, tg_xxxzzz_xxxxyzz_0, tg_xxxzzz_xxxxzzz_0, \
                                         tg_xxxzzz_xxxyyyy_0, tg_xxxzzz_xxxyyyz_0, tg_xxxzzz_xxxyyzz_0, tg_xxxzzz_xxxyzzz_0, \
                                         tg_xxxzzz_xxxzzzz_0, tg_xxxzzz_xxyyyyy_0, tg_xxxzzz_xxyyyyz_0, tg_xxxzzz_xxyyyzz_0, \
                                         tg_xxxzzz_xxyyzzz_0, tg_xxxzzz_xxyzzzz_0, tg_xxxzzz_xxzzzzz_0, tg_xxxzzz_xyyyyyy_0, \
                                         tg_xxxzzz_xyyyyyz_0, tg_xxxzzz_xyyyyzz_0, tg_xxxzzz_xyyyzzz_0, tg_xxxzzz_xyyzzzz_0, \
                                         tg_xxxzzz_xyzzzzz_0, tg_xxxzzz_xzzzzzz_0, tg_xxxzzz_yyyyyyy_0, tg_xxxzzz_yyyyyyz_0, \
                                         tg_xxxzzz_yyyyyzz_0, tg_xxxzzz_yyyyzzz_0, tg_xxxzzz_yyyzzzz_0, tg_xxxzzz_yyzzzzz_0, \
                                         tg_xxxzzz_yzzzzzz_0, tg_xxxzzz_zzzzzzz_0, tg_xxyyyy_xxxxxxx_0, tg_xxyyyy_xxxxxxy_0, \
                                         tg_xxyyyy_xxxxxxz_0, tg_xxyyyy_xxxxxyy_0, tg_xxyyyy_xxxxxyz_0, tg_xxyyyy_xxxxxzz_0, \
                                         tg_xxyyyy_xxxxyyy_0, tg_xxyyyy_xxxxyyz_0, tg_xxyyz_xyyyzzz_0, tg_xxyyz_xyyyzzz_1, \
                                         tg_xxyyz_xyyzzzz_0, tg_xxyyz_xyyzzzz_1, tg_xxyyz_xyzzzzz_0, tg_xxyyz_xyzzzzz_1, \
                                         tg_xxyyz_xzzzzzz_0, tg_xxyyz_xzzzzzz_1, tg_xxyyz_yyyyyyy_0, tg_xxyyz_yyyyyyy_1, \
                                         tg_xxyyz_yyyyyyz_0, tg_xxyyz_yyyyyyz_1, tg_xxyyz_yyyyyzz_0, tg_xxyyz_yyyyyzz_1, \
                                         tg_xxyyz_yyyyzzz_0, tg_xxyyz_yyyyzzz_1, tg_xxyyz_yyyzzz_1, tg_xxyyz_yyyzzzz_0, \
                                         tg_xxyyz_yyyzzzz_1, tg_xxyyz_yyzzzz_1, tg_xxyyz_yyzzzzz_0, tg_xxyyz_yyzzzzz_1, \
                                         tg_xxyyz_yzzzzz_1, tg_xxyyz_yzzzzzz_0, tg_xxyyz_yzzzzzz_1, tg_xxyyz_zzzzzz_1, \
                                         tg_xxyyz_zzzzzzz_0, tg_xxyyz_zzzzzzz_1, tg_xxyzz_xxxxxx_1, tg_xxyzz_xxxxxxx_0, \
                                         tg_xxyzz_xxxxxxx_1, tg_xxyzz_xxxxxxy_0, tg_xxyzz_xxxxxxy_1, tg_xxyzz_xxxxxxz_0, \
                                         tg_xxyzz_xxxxxxz_1, tg_xxyzz_xxxxxy_1, tg_xxyzz_xxxxxyy_0, tg_xxyzz_xxxxxyy_1, \
                                         tg_xxyzz_xxxxxyz_0, tg_xxyzz_xxxxxyz_1, tg_xxyzz_xxxxxz_1, tg_xxyzz_xxxxxzz_0, \
                                         tg_xxyzz_xxxxxzz_1, tg_xxyzz_xxxxyy_1, tg_xxyzz_xxxxyyy_0, tg_xxyzz_xxxxyyy_1, \
                                         tg_xxyzz_xxxxyyz_0, tg_xxyzz_xxxxyyz_1, tg_xxyzz_xxxxyz_1, tg_xxyzz_xxxxyzz_0, \
                                         tg_xxyzz_xxxxyzz_1, tg_xxyzz_xxxxzz_1, tg_xxyzz_xxxxzzz_0, tg_xxyzz_xxxxzzz_1, \
                                         tg_xxyzz_xxxyyy_1, tg_xxyzz_xxxyyyy_0, tg_xxyzz_xxxyyyy_1, tg_xxyzz_xxxyyyz_0, \
                                         tg_xxyzz_xxxyyyz_1, tg_xxyzz_xxxyyz_1, tg_xxyzz_xxxyyzz_0, tg_xxyzz_xxxyyzz_1, \
                                         tg_xxyzz_xxxyzz_1, tg_xxyzz_xxxyzzz_0, tg_xxyzz_xxxyzzz_1, tg_xxyzz_xxxzzz_1, \
                                         tg_xxyzz_xxxzzzz_0, tg_xxyzz_xxxzzzz_1, tg_xxyzz_xxyyyy_1, tg_xxyzz_xxyyyyy_0, \
                                         tg_xxyzz_xxyyyyy_1, tg_xxyzz_xxyyyyz_0, tg_xxyzz_xxyyyyz_1, tg_xxyzz_xxyyyz_1, \
                                         tg_xxyzz_xxyyyzz_0, tg_xxyzz_xxyyyzz_1, tg_xxyzz_xxyyzz_1, tg_xxyzz_xxyyzzz_0, \
                                         tg_xxyzz_xxyyzzz_1, tg_xxyzz_xxyzzz_1, tg_xxyzz_xxyzzzz_0, tg_xxyzz_xxyzzzz_1, \
                                         tg_xxyzz_xxzzzz_1, tg_xxyzz_xxzzzzz_0, tg_xxyzz_xxzzzzz_1, tg_xxyzz_xyyyyy_1, \
                                         tg_xxyzz_xyyyyyy_0, tg_xxyzz_xyyyyyy_1, tg_xxyzz_xyyyyyz_0, tg_xxyzz_xyyyyyz_1, \
                                         tg_xxyzz_xyyyyz_1, tg_xxyzz_xyyyyzz_0, tg_xxyzz_xyyyyzz_1, tg_xxyzz_xyyyzz_1, \
                                         tg_xxyzz_xyyyzzz_0, tg_xxyzz_xyyyzzz_1, tg_xxyzz_xyyzzz_1, tg_xxyzz_xyyzzzz_0, \
                                         tg_xxyzz_xyyzzzz_1, tg_xxyzz_xyzzzz_1, tg_xxyzz_xyzzzzz_0, tg_xxyzz_xyzzzzz_1, \
                                         tg_xxyzz_xzzzzz_1, tg_xxyzz_xzzzzzz_0, tg_xxyzz_xzzzzzz_1, tg_xxyzz_yyyyyy_1, \
                                         tg_xxyzz_yyyyyyy_0, tg_xxyzz_yyyyyyy_1, tg_xxyzz_yyyyyyz_0, tg_xxyzz_yyyyyyz_1, \
                                         tg_xxyzz_yyyyyz_1, tg_xxyzz_yyyyyzz_0, tg_xxyzz_yyyyyzz_1, tg_xxyzz_yyyyzz_1, \
                                         tg_xxyzz_yyyyzzz_0, tg_xxyzz_yyyyzzz_1, tg_xxyzz_yyyzzz_1, tg_xxyzz_yyyzzzz_0, \
                                         tg_xxyzz_yyyzzzz_1, tg_xxyzz_yyzzzz_1, tg_xxyzz_yyzzzzz_0, tg_xxyzz_yyzzzzz_1, \
                                         tg_xxyzz_yzzzzz_1, tg_xxyzz_yzzzzzz_0, tg_xxyzz_yzzzzzz_1, tg_xxyzz_zzzzzz_1, \
                                         tg_xxyzz_zzzzzzz_0, tg_xxyzz_zzzzzzz_1, tg_xxzzz_xxxxxx_1, tg_xxzzz_xxxxxxx_0, \
                                         tg_xxzzz_xxxxxxx_1, tg_xxzzz_xxxxxxy_0, tg_xxzzz_xxxxxxy_1, tg_xxzzz_xxxxxxz_0, \
                                         tg_xxzzz_xxxxxxz_1, tg_xxzzz_xxxxxy_1, tg_xxzzz_xxxxxyy_0, tg_xxzzz_xxxxxyy_1, \
                                         tg_xxzzz_xxxxxyz_0, tg_xxzzz_xxxxxyz_1, tg_xxzzz_xxxxxz_1, tg_xxzzz_xxxxxzz_0, \
                                         tg_xxzzz_xxxxxzz_1, tg_xxzzz_xxxxyy_1, tg_xxzzz_xxxxyyy_0, tg_xxzzz_xxxxyyy_1, \
                                         tg_xxzzz_xxxxyyz_0, tg_xxzzz_xxxxyyz_1, tg_xxzzz_xxxxyz_1, tg_xxzzz_xxxxyzz_0, \
                                         tg_xxzzz_xxxxyzz_1, tg_xxzzz_xxxxzz_1, tg_xxzzz_xxxxzzz_0, tg_xxzzz_xxxxzzz_1, \
                                         tg_xxzzz_xxxyyy_1, tg_xxzzz_xxxyyyy_0, tg_xxzzz_xxxyyyy_1, tg_xxzzz_xxxyyyz_0, \
                                         tg_xxzzz_xxxyyyz_1, tg_xxzzz_xxxyyz_1, tg_xxzzz_xxxyyzz_0, tg_xxzzz_xxxyyzz_1, \
                                         tg_xxzzz_xxxyzz_1, tg_xxzzz_xxxyzzz_0, tg_xxzzz_xxxyzzz_1, tg_xxzzz_xxxzzz_1, \
                                         tg_xxzzz_xxxzzzz_0, tg_xxzzz_xxxzzzz_1, tg_xxzzz_xxyyyy_1, tg_xxzzz_xxyyyyy_0, \
                                         tg_xxzzz_xxyyyyy_1, tg_xxzzz_xxyyyyz_0, tg_xxzzz_xxyyyyz_1, tg_xxzzz_xxyyyz_1, \
                                         tg_xxzzz_xxyyyzz_0, tg_xxzzz_xxyyyzz_1, tg_xxzzz_xxyyzz_1, tg_xxzzz_xxyyzzz_0, \
                                         tg_xxzzz_xxyyzzz_1, tg_xxzzz_xxyzzz_1, tg_xxzzz_xxyzzzz_0, tg_xxzzz_xxyzzzz_1, \
                                         tg_xxzzz_xxzzzz_1, tg_xxzzz_xxzzzzz_0, tg_xxzzz_xxzzzzz_1, tg_xxzzz_xyyyyy_1, \
                                         tg_xxzzz_xyyyyyy_0, tg_xxzzz_xyyyyyy_1, tg_xxzzz_xyyyyyz_0, tg_xxzzz_xyyyyyz_1, \
                                         tg_xxzzz_xyyyyz_1, tg_xxzzz_xyyyyzz_0, tg_xxzzz_xyyyyzz_1, tg_xxzzz_xyyyzz_1, \
                                         tg_xxzzz_xyyyzzz_0, tg_xxzzz_xyyyzzz_1, tg_xxzzz_xyyzzz_1, tg_xxzzz_xyyzzzz_0, \
                                         tg_xxzzz_xyyzzzz_1, tg_xxzzz_xyzzzz_1, tg_xxzzz_xyzzzzz_0, tg_xxzzz_xyzzzzz_1, \
                                         tg_xxzzz_xzzzzz_1, tg_xxzzz_xzzzzzz_0, tg_xxzzz_xzzzzzz_1, tg_xxzzz_yyyyyy_1, \
                                         tg_xxzzz_yyyyyyy_0, tg_xxzzz_yyyyyyy_1, tg_xxzzz_yyyyyyz_0, tg_xxzzz_yyyyyyz_1, \
                                         tg_xxzzz_yyyyyz_1, tg_xxzzz_yyyyyzz_0, tg_xxzzz_yyyyyzz_1, tg_xxzzz_yyyyzz_1, \
                                         tg_xxzzz_yyyyzzz_0, tg_xxzzz_yyyyzzz_1, tg_xxzzz_yyyzzz_1, tg_xxzzz_yyyzzzz_0, \
                                         tg_xxzzz_yyyzzzz_1, tg_xxzzz_yyzzzz_1, tg_xxzzz_yyzzzzz_0, tg_xxzzz_yyzzzzz_1, \
                                         tg_xxzzz_yzzzzz_1, tg_xxzzz_yzzzzzz_0, tg_xxzzz_yzzzzzz_1, tg_xxzzz_zzzzzz_1, \
                                         tg_xxzzz_zzzzzzz_0, tg_xxzzz_zzzzzzz_1, tg_xyyyy_xxxxxx_1, tg_xyyyy_xxxxxxx_0, \
                                         tg_xyyyy_xxxxxxx_1, tg_xyyyy_xxxxxxy_0, tg_xyyyy_xxxxxxy_1, tg_xyyyy_xxxxxxz_0, \
                                         tg_xyyyy_xxxxxxz_1, tg_xyyyy_xxxxxy_1, tg_xyyyy_xxxxxyy_0, tg_xyyyy_xxxxxyy_1, \
                                         tg_xyyyy_xxxxxyz_0, tg_xyyyy_xxxxxyz_1, tg_xyyyy_xxxxxz_1, tg_xyyyy_xxxxxzz_0, \
                                         tg_xyyyy_xxxxxzz_1, tg_xyyyy_xxxxyy_1, tg_xyyyy_xxxxyyy_0, tg_xyyyy_xxxxyyy_1, \
                                         tg_xyyyy_xxxxyyz_0, tg_xyyyy_xxxxyyz_1, tg_xyyyy_xxxxyz_1, tg_xyyyy_xxxxzz_1, \
                                         tg_xyyyy_xxxyyy_1, tg_xyyyy_xxxyyz_1, tg_xyyz_xyyyzzz_0, tg_xyyz_xyyyzzz_1, \
                                         tg_xyyz_xyyzzzz_0, tg_xyyz_xyyzzzz_1, tg_xyyz_xyzzzzz_0, tg_xyyz_xyzzzzz_1, \
                                         tg_xyyz_xzzzzzz_0, tg_xyyz_xzzzzzz_1, tg_xyyz_yyyyyyy_0, tg_xyyz_yyyyyyy_1, \
                                         tg_xyyz_yyyyyyz_0, tg_xyyz_yyyyyyz_1, tg_xyyz_yyyyyzz_0, tg_xyyz_yyyyyzz_1, \
                                         tg_xyyz_yyyyzzz_0, tg_xyyz_yyyyzzz_1, tg_xyyz_yyyzzzz_0, tg_xyyz_yyyzzzz_1, \
                                         tg_xyyz_yyzzzzz_0, tg_xyyz_yyzzzzz_1, tg_xyyz_yzzzzzz_0, tg_xyyz_yzzzzzz_1, \
                                         tg_xyyz_zzzzzzz_0, tg_xyyz_zzzzzzz_1, tg_xyzz_xxxxxxx_0, tg_xyzz_xxxxxxx_1, \
                                         tg_xyzz_xxxxxxy_0, tg_xyzz_xxxxxxy_1, tg_xyzz_xxxxxxz_0, tg_xyzz_xxxxxxz_1, \
                                         tg_xyzz_xxxxxyy_0, tg_xyzz_xxxxxyy_1, tg_xyzz_xxxxxyz_0, tg_xyzz_xxxxxyz_1, \
                                         tg_xyzz_xxxxxzz_0, tg_xyzz_xxxxxzz_1, tg_xyzz_xxxxyyy_0, tg_xyzz_xxxxyyy_1, \
                                         tg_xyzz_xxxxyyz_0, tg_xyzz_xxxxyyz_1, tg_xyzz_xxxxyzz_0, tg_xyzz_xxxxyzz_1, \
                                         tg_xyzz_xxxxzzz_0, tg_xyzz_xxxxzzz_1, tg_xyzz_xxxyyyy_0, tg_xyzz_xxxyyyy_1, \
                                         tg_xyzz_xxxyyyz_0, tg_xyzz_xxxyyyz_1, tg_xyzz_xxxyyzz_0, tg_xyzz_xxxyyzz_1, \
                                         tg_xyzz_xxxyzzz_0, tg_xyzz_xxxyzzz_1, tg_xyzz_xxxzzzz_0, tg_xyzz_xxxzzzz_1, \
                                         tg_xyzz_xxyyyyy_0, tg_xyzz_xxyyyyy_1, tg_xyzz_xxyyyyz_0, tg_xyzz_xxyyyyz_1, \
                                         tg_xyzz_xxyyyzz_0, tg_xyzz_xxyyyzz_1, tg_xyzz_xxyyzzz_0, tg_xyzz_xxyyzzz_1, \
                                         tg_xyzz_xxyzzzz_0, tg_xyzz_xxyzzzz_1, tg_xyzz_xxzzzzz_0, tg_xyzz_xxzzzzz_1, \
                                         tg_xyzz_xyyyyyy_0, tg_xyzz_xyyyyyy_1, tg_xyzz_xyyyyyz_0, tg_xyzz_xyyyyyz_1, \
                                         tg_xyzz_xyyyyzz_0, tg_xyzz_xyyyyzz_1, tg_xyzz_xyyyzzz_0, tg_xyzz_xyyyzzz_1, \
                                         tg_xyzz_xyyzzzz_0, tg_xyzz_xyyzzzz_1, tg_xyzz_xyzzzzz_0, tg_xyzz_xyzzzzz_1, \
                                         tg_xyzz_xzzzzzz_0, tg_xyzz_xzzzzzz_1, tg_xyzz_yyyyyyy_0, tg_xyzz_yyyyyyy_1, \
                                         tg_xyzz_yyyyyyz_0, tg_xyzz_yyyyyyz_1, tg_xyzz_yyyyyzz_0, tg_xyzz_yyyyyzz_1, \
                                         tg_xyzz_yyyyzzz_0, tg_xyzz_yyyyzzz_1, tg_xyzz_yyyzzzz_0, tg_xyzz_yyyzzzz_1, \
                                         tg_xyzz_yyzzzzz_0, tg_xyzz_yyzzzzz_1, tg_xyzz_yzzzzzz_0, tg_xyzz_yzzzzzz_1, \
                                         tg_xyzz_zzzzzzz_0, tg_xyzz_zzzzzzz_1, tg_xzzz_xxxxxxx_0, tg_xzzz_xxxxxxx_1, \
                                         tg_xzzz_xxxxxxy_0, tg_xzzz_xxxxxxy_1, tg_xzzz_xxxxxxz_0, tg_xzzz_xxxxxxz_1, \
                                         tg_xzzz_xxxxxyy_0, tg_xzzz_xxxxxyy_1, tg_xzzz_xxxxxyz_0, tg_xzzz_xxxxxyz_1, \
                                         tg_xzzz_xxxxxzz_0, tg_xzzz_xxxxxzz_1, tg_xzzz_xxxxyyy_0, tg_xzzz_xxxxyyy_1, \
                                         tg_xzzz_xxxxyyz_0, tg_xzzz_xxxxyyz_1, tg_xzzz_xxxxyzz_0, tg_xzzz_xxxxyzz_1, \
                                         tg_xzzz_xxxxzzz_0, tg_xzzz_xxxxzzz_1, tg_xzzz_xxxyyyy_0, tg_xzzz_xxxyyyy_1, \
                                         tg_xzzz_xxxyyyz_0, tg_xzzz_xxxyyyz_1, tg_xzzz_xxxyyzz_0, tg_xzzz_xxxyyzz_1, \
                                         tg_xzzz_xxxyzzz_0, tg_xzzz_xxxyzzz_1, tg_xzzz_xxxzzzz_0, tg_xzzz_xxxzzzz_1, \
                                         tg_xzzz_xxyyyyy_0, tg_xzzz_xxyyyyy_1, tg_xzzz_xxyyyyz_0, tg_xzzz_xxyyyyz_1, \
                                         tg_xzzz_xxyyyzz_0, tg_xzzz_xxyyyzz_1, tg_xzzz_xxyyzzz_0, tg_xzzz_xxyyzzz_1, \
                                         tg_xzzz_xxyzzzz_0, tg_xzzz_xxyzzzz_1, tg_xzzz_xxzzzzz_0, tg_xzzz_xxzzzzz_1, \
                                         tg_xzzz_xyyyyyy_0, tg_xzzz_xyyyyyy_1, tg_xzzz_xyyyyyz_0, tg_xzzz_xyyyyyz_1, \
                                         tg_xzzz_xyyyyzz_0, tg_xzzz_xyyyyzz_1, tg_xzzz_xyyyzzz_0, tg_xzzz_xyyyzzz_1, \
                                         tg_xzzz_xyyzzzz_0, tg_xzzz_xyyzzzz_1, tg_xzzz_xyzzzzz_0, tg_xzzz_xyzzzzz_1, \
                                         tg_xzzz_xzzzzzz_0, tg_xzzz_xzzzzzz_1, tg_xzzz_yyyyyyy_0, tg_xzzz_yyyyyyy_1, \
                                         tg_xzzz_yyyyyyz_0, tg_xzzz_yyyyyyz_1, tg_xzzz_yyyyyzz_0, tg_xzzz_yyyyyzz_1, \
                                         tg_xzzz_yyyyzzz_0, tg_xzzz_yyyyzzz_1, tg_xzzz_yyyzzzz_0, tg_xzzz_yyyzzzz_1, \
                                         tg_xzzz_yyzzzzz_0, tg_xzzz_yyzzzzz_1, tg_xzzz_yzzzzzz_0, tg_xzzz_yzzzzzz_1, \
                                         tg_xzzz_zzzzzzz_0, tg_xzzz_zzzzzzz_1, tg_yyyy_xxxxxxx_0, tg_yyyy_xxxxxxx_1, \
                                         tg_yyyy_xxxxxxy_0, tg_yyyy_xxxxxxy_1, tg_yyyy_xxxxxxz_0, tg_yyyy_xxxxxxz_1, \
                                         tg_yyyy_xxxxxyy_0, tg_yyyy_xxxxxyy_1, tg_yyyy_xxxxxyz_0, tg_yyyy_xxxxxyz_1, \
                                         tg_yyyy_xxxxxzz_0, tg_yyyy_xxxxxzz_1, tg_yyyy_xxxxyyy_0, tg_yyyy_xxxxyyy_1, \
                                         tg_yyyy_xxxxyyz_0, tg_yyyy_xxxxyyz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxxyyz_xyyyzzz_0[j] = pb_x * tg_xxyyz_xyyyzzz_0[j] + fr * tg_xxyyz_xyyyzzz_1[j] + fl1_fx * (tg_xyyz_xyyyzzz_0[j] - tg_xyyz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yyyzzz_1[j];

                    tg_xxxyyz_xyyzzzz_0[j] = pb_x * tg_xxyyz_xyyzzzz_0[j] + fr * tg_xxyyz_xyyzzzz_1[j] + fl1_fx * (tg_xyyz_xyyzzzz_0[j] - tg_xyyz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yyzzzz_1[j];

                    tg_xxxyyz_xyzzzzz_0[j] = pb_x * tg_xxyyz_xyzzzzz_0[j] + fr * tg_xxyyz_xyzzzzz_1[j] + fl1_fx * (tg_xyyz_xyzzzzz_0[j] - tg_xyyz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_yzzzzz_1[j];

                    tg_xxxyyz_xzzzzzz_0[j] = pb_x * tg_xxyyz_xzzzzzz_0[j] + fr * tg_xxyyz_xzzzzzz_1[j] + fl1_fx * (tg_xyyz_xzzzzzz_0[j] - tg_xyyz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyyz_zzzzzz_1[j];

                    tg_xxxyyz_yyyyyyy_0[j] = pb_x * tg_xxyyz_yyyyyyy_0[j] + fr * tg_xxyyz_yyyyyyy_1[j] + fl1_fx * (tg_xyyz_yyyyyyy_0[j] - tg_xyyz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxyyz_yyyyyyz_0[j] = pb_x * tg_xxyyz_yyyyyyz_0[j] + fr * tg_xxyyz_yyyyyyz_1[j] + fl1_fx * (tg_xyyz_yyyyyyz_0[j] - tg_xyyz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxyyz_yyyyyzz_0[j] = pb_x * tg_xxyyz_yyyyyzz_0[j] + fr * tg_xxyyz_yyyyyzz_1[j] + fl1_fx * (tg_xyyz_yyyyyzz_0[j] - tg_xyyz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxyyz_yyyyzzz_0[j] = pb_x * tg_xxyyz_yyyyzzz_0[j] + fr * tg_xxyyz_yyyyzzz_1[j] + fl1_fx * (tg_xyyz_yyyyzzz_0[j] - tg_xyyz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxyyz_yyyzzzz_0[j] = pb_x * tg_xxyyz_yyyzzzz_0[j] + fr * tg_xxyyz_yyyzzzz_1[j] + fl1_fx * (tg_xyyz_yyyzzzz_0[j] - tg_xyyz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxyyz_yyzzzzz_0[j] = pb_x * tg_xxyyz_yyzzzzz_0[j] + fr * tg_xxyyz_yyzzzzz_1[j] + fl1_fx * (tg_xyyz_yyzzzzz_0[j] - tg_xyyz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxyyz_yzzzzzz_0[j] = pb_x * tg_xxyyz_yzzzzzz_0[j] + fr * tg_xxyyz_yzzzzzz_1[j] + fl1_fx * (tg_xyyz_yzzzzzz_0[j] - tg_xyyz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxyyz_zzzzzzz_0[j] = pb_x * tg_xxyyz_zzzzzzz_0[j] + fr * tg_xxyyz_zzzzzzz_1[j] + fl1_fx * (tg_xyyz_zzzzzzz_0[j] - tg_xyyz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxyzz_xxxxxxx_0[j] = pb_x * tg_xxyzz_xxxxxxx_0[j] + fr * tg_xxyzz_xxxxxxx_1[j] + fl1_fx * (tg_xyzz_xxxxxxx_0[j] - tg_xyzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxyzz_xxxxxx_1[j];

                    tg_xxxyzz_xxxxxxy_0[j] = pb_x * tg_xxyzz_xxxxxxy_0[j] + fr * tg_xxyzz_xxxxxxy_1[j] + fl1_fx * (tg_xyzz_xxxxxxy_0[j] - tg_xyzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyzz_xxxxxy_1[j];

                    tg_xxxyzz_xxxxxxz_0[j] = pb_x * tg_xxyzz_xxxxxxz_0[j] + fr * tg_xxyzz_xxxxxxz_1[j] + fl1_fx * (tg_xyzz_xxxxxxz_0[j] - tg_xyzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxyzz_xxxxxz_1[j];

                    tg_xxxyzz_xxxxxyy_0[j] = pb_x * tg_xxyzz_xxxxxyy_0[j] + fr * tg_xxyzz_xxxxxyy_1[j] + fl1_fx * (tg_xyzz_xxxxxyy_0[j] - tg_xyzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyzz_xxxxyy_1[j];

                    tg_xxxyzz_xxxxxyz_0[j] = pb_x * tg_xxyzz_xxxxxyz_0[j] + fr * tg_xxyzz_xxxxxyz_1[j] + fl1_fx * (tg_xyzz_xxxxxyz_0[j] - tg_xyzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyzz_xxxxyz_1[j];

                    tg_xxxyzz_xxxxxzz_0[j] = pb_x * tg_xxyzz_xxxxxzz_0[j] + fr * tg_xxyzz_xxxxxzz_1[j] + fl1_fx * (tg_xyzz_xxxxxzz_0[j] - tg_xyzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxyzz_xxxxzz_1[j];

                    tg_xxxyzz_xxxxyyy_0[j] = pb_x * tg_xxyzz_xxxxyyy_0[j] + fr * tg_xxyzz_xxxxyyy_1[j] + fl1_fx * (tg_xyzz_xxxxyyy_0[j] - tg_xyzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyzz_xxxyyy_1[j];

                    tg_xxxyzz_xxxxyyz_0[j] = pb_x * tg_xxyzz_xxxxyyz_0[j] + fr * tg_xxyzz_xxxxyyz_1[j] + fl1_fx * (tg_xyzz_xxxxyyz_0[j] - tg_xyzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyzz_xxxyyz_1[j];

                    tg_xxxyzz_xxxxyzz_0[j] = pb_x * tg_xxyzz_xxxxyzz_0[j] + fr * tg_xxyzz_xxxxyzz_1[j] + fl1_fx * (tg_xyzz_xxxxyzz_0[j] - tg_xyzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyzz_xxxyzz_1[j];

                    tg_xxxyzz_xxxxzzz_0[j] = pb_x * tg_xxyzz_xxxxzzz_0[j] + fr * tg_xxyzz_xxxxzzz_1[j] + fl1_fx * (tg_xyzz_xxxxzzz_0[j] - tg_xyzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxyzz_xxxzzz_1[j];

                    tg_xxxyzz_xxxyyyy_0[j] = pb_x * tg_xxyzz_xxxyyyy_0[j] + fr * tg_xxyzz_xxxyyyy_1[j] + fl1_fx * (tg_xyzz_xxxyyyy_0[j] - tg_xyzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xxyyyy_1[j];

                    tg_xxxyzz_xxxyyyz_0[j] = pb_x * tg_xxyzz_xxxyyyz_0[j] + fr * tg_xxyzz_xxxyyyz_1[j] + fl1_fx * (tg_xyzz_xxxyyyz_0[j] - tg_xyzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xxyyyz_1[j];

                    tg_xxxyzz_xxxyyzz_0[j] = pb_x * tg_xxyzz_xxxyyzz_0[j] + fr * tg_xxyzz_xxxyyzz_1[j] + fl1_fx * (tg_xyzz_xxxyyzz_0[j] - tg_xyzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xxyyzz_1[j];

                    tg_xxxyzz_xxxyzzz_0[j] = pb_x * tg_xxyzz_xxxyzzz_0[j] + fr * tg_xxyzz_xxxyzzz_1[j] + fl1_fx * (tg_xyzz_xxxyzzz_0[j] - tg_xyzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xxyzzz_1[j];

                    tg_xxxyzz_xxxzzzz_0[j] = pb_x * tg_xxyzz_xxxzzzz_0[j] + fr * tg_xxyzz_xxxzzzz_1[j] + fl1_fx * (tg_xyzz_xxxzzzz_0[j] - tg_xyzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxyzz_xxzzzz_1[j];

                    tg_xxxyzz_xxyyyyy_0[j] = pb_x * tg_xxyzz_xxyyyyy_0[j] + fr * tg_xxyzz_xxyyyyy_1[j] + fl1_fx * (tg_xyzz_xxyyyyy_0[j] - tg_xyzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xyyyyy_1[j];

                    tg_xxxyzz_xxyyyyz_0[j] = pb_x * tg_xxyzz_xxyyyyz_0[j] + fr * tg_xxyzz_xxyyyyz_1[j] + fl1_fx * (tg_xyzz_xxyyyyz_0[j] - tg_xyzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xyyyyz_1[j];

                    tg_xxxyzz_xxyyyzz_0[j] = pb_x * tg_xxyzz_xxyyyzz_0[j] + fr * tg_xxyzz_xxyyyzz_1[j] + fl1_fx * (tg_xyzz_xxyyyzz_0[j] - tg_xyzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xyyyzz_1[j];

                    tg_xxxyzz_xxyyzzz_0[j] = pb_x * tg_xxyzz_xxyyzzz_0[j] + fr * tg_xxyzz_xxyyzzz_1[j] + fl1_fx * (tg_xyzz_xxyyzzz_0[j] - tg_xyzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xyyzzz_1[j];

                    tg_xxxyzz_xxyzzzz_0[j] = pb_x * tg_xxyzz_xxyzzzz_0[j] + fr * tg_xxyzz_xxyzzzz_1[j] + fl1_fx * (tg_xyzz_xxyzzzz_0[j] - tg_xyzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xyzzzz_1[j];

                    tg_xxxyzz_xxzzzzz_0[j] = pb_x * tg_xxyzz_xxzzzzz_0[j] + fr * tg_xxyzz_xxzzzzz_1[j] + fl1_fx * (tg_xyzz_xxzzzzz_0[j] - tg_xyzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxyzz_xzzzzz_1[j];

                    tg_xxxyzz_xyyyyyy_0[j] = pb_x * tg_xxyzz_xyyyyyy_0[j] + fr * tg_xxyzz_xyyyyyy_1[j] + fl1_fx * (tg_xyzz_xyyyyyy_0[j] - tg_xyzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yyyyyy_1[j];

                    tg_xxxyzz_xyyyyyz_0[j] = pb_x * tg_xxyzz_xyyyyyz_0[j] + fr * tg_xxyzz_xyyyyyz_1[j] + fl1_fx * (tg_xyzz_xyyyyyz_0[j] - tg_xyzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yyyyyz_1[j];

                    tg_xxxyzz_xyyyyzz_0[j] = pb_x * tg_xxyzz_xyyyyzz_0[j] + fr * tg_xxyzz_xyyyyzz_1[j] + fl1_fx * (tg_xyzz_xyyyyzz_0[j] - tg_xyzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yyyyzz_1[j];

                    tg_xxxyzz_xyyyzzz_0[j] = pb_x * tg_xxyzz_xyyyzzz_0[j] + fr * tg_xxyzz_xyyyzzz_1[j] + fl1_fx * (tg_xyzz_xyyyzzz_0[j] - tg_xyzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yyyzzz_1[j];

                    tg_xxxyzz_xyyzzzz_0[j] = pb_x * tg_xxyzz_xyyzzzz_0[j] + fr * tg_xxyzz_xyyzzzz_1[j] + fl1_fx * (tg_xyzz_xyyzzzz_0[j] - tg_xyzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yyzzzz_1[j];

                    tg_xxxyzz_xyzzzzz_0[j] = pb_x * tg_xxyzz_xyzzzzz_0[j] + fr * tg_xxyzz_xyzzzzz_1[j] + fl1_fx * (tg_xyzz_xyzzzzz_0[j] - tg_xyzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_yzzzzz_1[j];

                    tg_xxxyzz_xzzzzzz_0[j] = pb_x * tg_xxyzz_xzzzzzz_0[j] + fr * tg_xxyzz_xzzzzzz_1[j] + fl1_fx * (tg_xyzz_xzzzzzz_0[j] - tg_xyzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxyzz_zzzzzz_1[j];

                    tg_xxxyzz_yyyyyyy_0[j] = pb_x * tg_xxyzz_yyyyyyy_0[j] + fr * tg_xxyzz_yyyyyyy_1[j] + fl1_fx * (tg_xyzz_yyyyyyy_0[j] - tg_xyzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxyzz_yyyyyyz_0[j] = pb_x * tg_xxyzz_yyyyyyz_0[j] + fr * tg_xxyzz_yyyyyyz_1[j] + fl1_fx * (tg_xyzz_yyyyyyz_0[j] - tg_xyzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxyzz_yyyyyzz_0[j] = pb_x * tg_xxyzz_yyyyyzz_0[j] + fr * tg_xxyzz_yyyyyzz_1[j] + fl1_fx * (tg_xyzz_yyyyyzz_0[j] - tg_xyzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxyzz_yyyyzzz_0[j] = pb_x * tg_xxyzz_yyyyzzz_0[j] + fr * tg_xxyzz_yyyyzzz_1[j] + fl1_fx * (tg_xyzz_yyyyzzz_0[j] - tg_xyzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxyzz_yyyzzzz_0[j] = pb_x * tg_xxyzz_yyyzzzz_0[j] + fr * tg_xxyzz_yyyzzzz_1[j] + fl1_fx * (tg_xyzz_yyyzzzz_0[j] - tg_xyzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxyzz_yyzzzzz_0[j] = pb_x * tg_xxyzz_yyzzzzz_0[j] + fr * tg_xxyzz_yyzzzzz_1[j] + fl1_fx * (tg_xyzz_yyzzzzz_0[j] - tg_xyzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxyzz_yzzzzzz_0[j] = pb_x * tg_xxyzz_yzzzzzz_0[j] + fr * tg_xxyzz_yzzzzzz_1[j] + fl1_fx * (tg_xyzz_yzzzzzz_0[j] - tg_xyzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxyzz_zzzzzzz_0[j] = pb_x * tg_xxyzz_zzzzzzz_0[j] + fr * tg_xxyzz_zzzzzzz_1[j] + fl1_fx * (tg_xyzz_zzzzzzz_0[j] - tg_xyzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxxzzz_xxxxxxx_0[j] = pb_x * tg_xxzzz_xxxxxxx_0[j] + fr * tg_xxzzz_xxxxxxx_1[j] + fl1_fx * (tg_xzzz_xxxxxxx_0[j] - tg_xzzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xxzzz_xxxxxx_1[j];

                    tg_xxxzzz_xxxxxxy_0[j] = pb_x * tg_xxzzz_xxxxxxy_0[j] + fr * tg_xxzzz_xxxxxxy_1[j] + fl1_fx * (tg_xzzz_xxxxxxy_0[j] - tg_xzzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxzzz_xxxxxy_1[j];

                    tg_xxxzzz_xxxxxxz_0[j] = pb_x * tg_xxzzz_xxxxxxz_0[j] + fr * tg_xxzzz_xxxxxxz_1[j] + fl1_fx * (tg_xzzz_xxxxxxz_0[j] - tg_xzzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xxzzz_xxxxxz_1[j];

                    tg_xxxzzz_xxxxxyy_0[j] = pb_x * tg_xxzzz_xxxxxyy_0[j] + fr * tg_xxzzz_xxxxxyy_1[j] + fl1_fx * (tg_xzzz_xxxxxyy_0[j] - tg_xzzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxzzz_xxxxyy_1[j];

                    tg_xxxzzz_xxxxxyz_0[j] = pb_x * tg_xxzzz_xxxxxyz_0[j] + fr * tg_xxzzz_xxxxxyz_1[j] + fl1_fx * (tg_xzzz_xxxxxyz_0[j] - tg_xzzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxzzz_xxxxyz_1[j];

                    tg_xxxzzz_xxxxxzz_0[j] = pb_x * tg_xxzzz_xxxxxzz_0[j] + fr * tg_xxzzz_xxxxxzz_1[j] + fl1_fx * (tg_xzzz_xxxxxzz_0[j] - tg_xzzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xxzzz_xxxxzz_1[j];

                    tg_xxxzzz_xxxxyyy_0[j] = pb_x * tg_xxzzz_xxxxyyy_0[j] + fr * tg_xxzzz_xxxxyyy_1[j] + fl1_fx * (tg_xzzz_xxxxyyy_0[j] - tg_xzzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxzzz_xxxyyy_1[j];

                    tg_xxxzzz_xxxxyyz_0[j] = pb_x * tg_xxzzz_xxxxyyz_0[j] + fr * tg_xxzzz_xxxxyyz_1[j] + fl1_fx * (tg_xzzz_xxxxyyz_0[j] - tg_xzzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxzzz_xxxyyz_1[j];

                    tg_xxxzzz_xxxxyzz_0[j] = pb_x * tg_xxzzz_xxxxyzz_0[j] + fr * tg_xxzzz_xxxxyzz_1[j] + fl1_fx * (tg_xzzz_xxxxyzz_0[j] - tg_xzzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxzzz_xxxyzz_1[j];

                    tg_xxxzzz_xxxxzzz_0[j] = pb_x * tg_xxzzz_xxxxzzz_0[j] + fr * tg_xxzzz_xxxxzzz_1[j] + fl1_fx * (tg_xzzz_xxxxzzz_0[j] - tg_xzzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xxzzz_xxxzzz_1[j];

                    tg_xxxzzz_xxxyyyy_0[j] = pb_x * tg_xxzzz_xxxyyyy_0[j] + fr * tg_xxzzz_xxxyyyy_1[j] + fl1_fx * (tg_xzzz_xxxyyyy_0[j] - tg_xzzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xxyyyy_1[j];

                    tg_xxxzzz_xxxyyyz_0[j] = pb_x * tg_xxzzz_xxxyyyz_0[j] + fr * tg_xxzzz_xxxyyyz_1[j] + fl1_fx * (tg_xzzz_xxxyyyz_0[j] - tg_xzzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xxyyyz_1[j];

                    tg_xxxzzz_xxxyyzz_0[j] = pb_x * tg_xxzzz_xxxyyzz_0[j] + fr * tg_xxzzz_xxxyyzz_1[j] + fl1_fx * (tg_xzzz_xxxyyzz_0[j] - tg_xzzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xxyyzz_1[j];

                    tg_xxxzzz_xxxyzzz_0[j] = pb_x * tg_xxzzz_xxxyzzz_0[j] + fr * tg_xxzzz_xxxyzzz_1[j] + fl1_fx * (tg_xzzz_xxxyzzz_0[j] - tg_xzzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xxyzzz_1[j];

                    tg_xxxzzz_xxxzzzz_0[j] = pb_x * tg_xxzzz_xxxzzzz_0[j] + fr * tg_xxzzz_xxxzzzz_1[j] + fl1_fx * (tg_xzzz_xxxzzzz_0[j] - tg_xzzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xxzzz_xxzzzz_1[j];

                    tg_xxxzzz_xxyyyyy_0[j] = pb_x * tg_xxzzz_xxyyyyy_0[j] + fr * tg_xxzzz_xxyyyyy_1[j] + fl1_fx * (tg_xzzz_xxyyyyy_0[j] - tg_xzzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xyyyyy_1[j];

                    tg_xxxzzz_xxyyyyz_0[j] = pb_x * tg_xxzzz_xxyyyyz_0[j] + fr * tg_xxzzz_xxyyyyz_1[j] + fl1_fx * (tg_xzzz_xxyyyyz_0[j] - tg_xzzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xyyyyz_1[j];

                    tg_xxxzzz_xxyyyzz_0[j] = pb_x * tg_xxzzz_xxyyyzz_0[j] + fr * tg_xxzzz_xxyyyzz_1[j] + fl1_fx * (tg_xzzz_xxyyyzz_0[j] - tg_xzzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xyyyzz_1[j];

                    tg_xxxzzz_xxyyzzz_0[j] = pb_x * tg_xxzzz_xxyyzzz_0[j] + fr * tg_xxzzz_xxyyzzz_1[j] + fl1_fx * (tg_xzzz_xxyyzzz_0[j] - tg_xzzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xyyzzz_1[j];

                    tg_xxxzzz_xxyzzzz_0[j] = pb_x * tg_xxzzz_xxyzzzz_0[j] + fr * tg_xxzzz_xxyzzzz_1[j] + fl1_fx * (tg_xzzz_xxyzzzz_0[j] - tg_xzzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xyzzzz_1[j];

                    tg_xxxzzz_xxzzzzz_0[j] = pb_x * tg_xxzzz_xxzzzzz_0[j] + fr * tg_xxzzz_xxzzzzz_1[j] + fl1_fx * (tg_xzzz_xxzzzzz_0[j] - tg_xzzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xxzzz_xzzzzz_1[j];

                    tg_xxxzzz_xyyyyyy_0[j] = pb_x * tg_xxzzz_xyyyyyy_0[j] + fr * tg_xxzzz_xyyyyyy_1[j] + fl1_fx * (tg_xzzz_xyyyyyy_0[j] - tg_xzzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yyyyyy_1[j];

                    tg_xxxzzz_xyyyyyz_0[j] = pb_x * tg_xxzzz_xyyyyyz_0[j] + fr * tg_xxzzz_xyyyyyz_1[j] + fl1_fx * (tg_xzzz_xyyyyyz_0[j] - tg_xzzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yyyyyz_1[j];

                    tg_xxxzzz_xyyyyzz_0[j] = pb_x * tg_xxzzz_xyyyyzz_0[j] + fr * tg_xxzzz_xyyyyzz_1[j] + fl1_fx * (tg_xzzz_xyyyyzz_0[j] - tg_xzzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yyyyzz_1[j];

                    tg_xxxzzz_xyyyzzz_0[j] = pb_x * tg_xxzzz_xyyyzzz_0[j] + fr * tg_xxzzz_xyyyzzz_1[j] + fl1_fx * (tg_xzzz_xyyyzzz_0[j] - tg_xzzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yyyzzz_1[j];

                    tg_xxxzzz_xyyzzzz_0[j] = pb_x * tg_xxzzz_xyyzzzz_0[j] + fr * tg_xxzzz_xyyzzzz_1[j] + fl1_fx * (tg_xzzz_xyyzzzz_0[j] - tg_xzzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yyzzzz_1[j];

                    tg_xxxzzz_xyzzzzz_0[j] = pb_x * tg_xxzzz_xyzzzzz_0[j] + fr * tg_xxzzz_xyzzzzz_1[j] + fl1_fx * (tg_xzzz_xyzzzzz_0[j] - tg_xzzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_yzzzzz_1[j];

                    tg_xxxzzz_xzzzzzz_0[j] = pb_x * tg_xxzzz_xzzzzzz_0[j] + fr * tg_xxzzz_xzzzzzz_1[j] + fl1_fx * (tg_xzzz_xzzzzzz_0[j] - tg_xzzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xxzzz_zzzzzz_1[j];

                    tg_xxxzzz_yyyyyyy_0[j] = pb_x * tg_xxzzz_yyyyyyy_0[j] + fr * tg_xxzzz_yyyyyyy_1[j] + fl1_fx * (tg_xzzz_yyyyyyy_0[j] - tg_xzzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxxzzz_yyyyyyz_0[j] = pb_x * tg_xxzzz_yyyyyyz_0[j] + fr * tg_xxzzz_yyyyyyz_1[j] + fl1_fx * (tg_xzzz_yyyyyyz_0[j] - tg_xzzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxxzzz_yyyyyzz_0[j] = pb_x * tg_xxzzz_yyyyyzz_0[j] + fr * tg_xxzzz_yyyyyzz_1[j] + fl1_fx * (tg_xzzz_yyyyyzz_0[j] - tg_xzzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxxzzz_yyyyzzz_0[j] = pb_x * tg_xxzzz_yyyyzzz_0[j] + fr * tg_xxzzz_yyyyzzz_1[j] + fl1_fx * (tg_xzzz_yyyyzzz_0[j] - tg_xzzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxxzzz_yyyzzzz_0[j] = pb_x * tg_xxzzz_yyyzzzz_0[j] + fr * tg_xxzzz_yyyzzzz_1[j] + fl1_fx * (tg_xzzz_yyyzzzz_0[j] - tg_xzzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxxzzz_yyzzzzz_0[j] = pb_x * tg_xxzzz_yyzzzzz_0[j] + fr * tg_xxzzz_yyzzzzz_1[j] + fl1_fx * (tg_xzzz_yyzzzzz_0[j] - tg_xzzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxxzzz_yzzzzzz_0[j] = pb_x * tg_xxzzz_yzzzzzz_0[j] + fr * tg_xxzzz_yzzzzzz_1[j] + fl1_fx * (tg_xzzz_yzzzzzz_0[j] - tg_xzzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxxzzz_zzzzzzz_0[j] = pb_x * tg_xxzzz_zzzzzzz_0[j] + fr * tg_xxzzz_zzzzzzz_1[j] + fl1_fx * (tg_xzzz_zzzzzzz_0[j] - tg_xzzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxyyyy_xxxxxxx_0[j] = pb_x * tg_xyyyy_xxxxxxx_0[j] + fr * tg_xyyyy_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxxx_0[j] - tg_yyyy_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xyyyy_xxxxxx_1[j];

                    tg_xxyyyy_xxxxxxy_0[j] = pb_x * tg_xyyyy_xxxxxxy_0[j] + fr * tg_xyyyy_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxxy_0[j] - tg_yyyy_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyyy_xxxxxy_1[j];

                    tg_xxyyyy_xxxxxxz_0[j] = pb_x * tg_xyyyy_xxxxxxz_0[j] + fr * tg_xyyyy_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxxz_0[j] - tg_yyyy_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyyy_xxxxxz_1[j];

                    tg_xxyyyy_xxxxxyy_0[j] = pb_x * tg_xyyyy_xxxxxyy_0[j] + fr * tg_xyyyy_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxyy_0[j] - tg_yyyy_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyy_xxxxyy_1[j];

                    tg_xxyyyy_xxxxxyz_0[j] = pb_x * tg_xyyyy_xxxxxyz_0[j] + fr * tg_xyyyy_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxyz_0[j] - tg_yyyy_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyy_xxxxyz_1[j];

                    tg_xxyyyy_xxxxxzz_0[j] = pb_x * tg_xyyyy_xxxxxzz_0[j] + fr * tg_xyyyy_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxxzz_0[j] - tg_yyyy_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyy_xxxxzz_1[j];

                    tg_xxyyyy_xxxxyyy_0[j] = pb_x * tg_xyyyy_xxxxyyy_0[j] + fr * tg_xyyyy_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxyyy_0[j] - tg_yyyy_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyy_xxxyyy_1[j];

                    tg_xxyyyy_xxxxyyz_0[j] = pb_x * tg_xyyyy_xxxxyyz_0[j] + fr * tg_xyyyy_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxyyz_0[j] - tg_yyyy_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyy_xxxyyz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_368_460(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (368,460)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xyyyy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 368); 

                auto tg_xyyyy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 369); 

                auto tg_xyyyy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 370); 

                auto tg_xyyyy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 371); 

                auto tg_xyyyy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 372); 

                auto tg_xyyyy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 373); 

                auto tg_xyyyy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 374); 

                auto tg_xyyyy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 375); 

                auto tg_xyyyy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 376); 

                auto tg_xyyyy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 377); 

                auto tg_xyyyy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 378); 

                auto tg_xyyyy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 379); 

                auto tg_xyyyy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 380); 

                auto tg_xyyyy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 381); 

                auto tg_xyyyy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 382); 

                auto tg_xyyyy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 383); 

                auto tg_xyyyy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 384); 

                auto tg_xyyyy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 385); 

                auto tg_xyyyy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 386); 

                auto tg_xyyyy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 387); 

                auto tg_xyyyy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 388); 

                auto tg_xyyyy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 389); 

                auto tg_xyyyy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 390); 

                auto tg_xyyyy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 391); 

                auto tg_xyyyy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 392); 

                auto tg_xyyyy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 393); 

                auto tg_xyyyy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 394); 

                auto tg_xyyyy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 395); 

                auto tg_xyyyz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 396); 

                auto tg_xyyyz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 397); 

                auto tg_xyyyz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 398); 

                auto tg_xyyyz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 399); 

                auto tg_xyyyz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 400); 

                auto tg_xyyyz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 401); 

                auto tg_xyyyz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 402); 

                auto tg_xyyyz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 403); 

                auto tg_xyyyz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 404); 

                auto tg_xyyyz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 405); 

                auto tg_xyyyz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 406); 

                auto tg_xyyyz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 407); 

                auto tg_xyyyz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 408); 

                auto tg_xyyyz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 409); 

                auto tg_xyyyz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 410); 

                auto tg_xyyyz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 411); 

                auto tg_xyyyz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 412); 

                auto tg_xyyyz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 413); 

                auto tg_xyyyz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 414); 

                auto tg_xyyyz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 415); 

                auto tg_xyyyz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 416); 

                auto tg_xyyyz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 417); 

                auto tg_xyyyz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 418); 

                auto tg_xyyyz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 419); 

                auto tg_xyyyz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 420); 

                auto tg_xyyyz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 421); 

                auto tg_xyyyz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 422); 

                auto tg_xyyyz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 423); 

                auto tg_xyyyz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 424); 

                auto tg_xyyyz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 425); 

                auto tg_xyyyz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 426); 

                auto tg_xyyyz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 427); 

                auto tg_xyyyz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 428); 

                auto tg_xyyyz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 429); 

                auto tg_xyyyz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 430); 

                auto tg_xyyyz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 431); 

                auto tg_xyyzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 432); 

                auto tg_xyyzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 433); 

                auto tg_xyyzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 434); 

                auto tg_xyyzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 435); 

                auto tg_xyyzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 436); 

                auto tg_xyyzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 437); 

                auto tg_xyyzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 438); 

                auto tg_xyyzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 439); 

                auto tg_xyyzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 440); 

                auto tg_xyyzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 441); 

                auto tg_xyyzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 442); 

                auto tg_xyyzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 443); 

                auto tg_xyyzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 444); 

                auto tg_xyyzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 445); 

                auto tg_xyyzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 446); 

                auto tg_xyyzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 447); 

                auto tg_xyyzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 448); 

                auto tg_xyyzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 449); 

                auto tg_xyyzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 450); 

                auto tg_xyyzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 451); 

                auto tg_xyyzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 452); 

                auto tg_xyyzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 453); 

                auto tg_xyyzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 454); 

                auto tg_xyyzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 455); 

                auto tg_xyyzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 456); 

                auto tg_xyyzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 457); 

                auto tg_xyyzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 458); 

                auto tg_xyyzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 459); 

                auto tg_xyyyy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 368); 

                auto tg_xyyyy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 369); 

                auto tg_xyyyy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 370); 

                auto tg_xyyyy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 371); 

                auto tg_xyyyy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 372); 

                auto tg_xyyyy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 373); 

                auto tg_xyyyy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 374); 

                auto tg_xyyyy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 375); 

                auto tg_xyyyy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 376); 

                auto tg_xyyyy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 377); 

                auto tg_xyyyy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 378); 

                auto tg_xyyyy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 379); 

                auto tg_xyyyy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 380); 

                auto tg_xyyyy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 381); 

                auto tg_xyyyy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 382); 

                auto tg_xyyyy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 383); 

                auto tg_xyyyy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 384); 

                auto tg_xyyyy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 385); 

                auto tg_xyyyy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 386); 

                auto tg_xyyyy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 387); 

                auto tg_xyyyy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 388); 

                auto tg_xyyyy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 389); 

                auto tg_xyyyy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 390); 

                auto tg_xyyyy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 391); 

                auto tg_xyyyy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 392); 

                auto tg_xyyyy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 393); 

                auto tg_xyyyy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 394); 

                auto tg_xyyyy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 395); 

                auto tg_xyyyz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 396); 

                auto tg_xyyyz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 397); 

                auto tg_xyyyz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 398); 

                auto tg_xyyyz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 399); 

                auto tg_xyyyz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 400); 

                auto tg_xyyyz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 401); 

                auto tg_xyyyz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 402); 

                auto tg_xyyyz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 403); 

                auto tg_xyyyz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 404); 

                auto tg_xyyyz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 405); 

                auto tg_xyyyz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 406); 

                auto tg_xyyyz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 407); 

                auto tg_xyyyz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 408); 

                auto tg_xyyyz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 409); 

                auto tg_xyyyz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 410); 

                auto tg_xyyyz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 411); 

                auto tg_xyyyz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 412); 

                auto tg_xyyyz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 413); 

                auto tg_xyyyz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 414); 

                auto tg_xyyyz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 415); 

                auto tg_xyyyz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 416); 

                auto tg_xyyyz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 417); 

                auto tg_xyyyz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 418); 

                auto tg_xyyyz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 419); 

                auto tg_xyyyz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 420); 

                auto tg_xyyyz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 421); 

                auto tg_xyyyz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 422); 

                auto tg_xyyyz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 423); 

                auto tg_xyyyz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 424); 

                auto tg_xyyyz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 425); 

                auto tg_xyyyz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 426); 

                auto tg_xyyyz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 427); 

                auto tg_xyyyz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 428); 

                auto tg_xyyyz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 429); 

                auto tg_xyyyz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 430); 

                auto tg_xyyyz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 431); 

                auto tg_xyyzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 432); 

                auto tg_xyyzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 433); 

                auto tg_xyyzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 434); 

                auto tg_xyyzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 435); 

                auto tg_xyyzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 436); 

                auto tg_xyyzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 437); 

                auto tg_xyyzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 438); 

                auto tg_xyyzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 439); 

                auto tg_xyyzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 440); 

                auto tg_xyyzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 441); 

                auto tg_xyyzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 442); 

                auto tg_xyyzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 443); 

                auto tg_xyyzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 444); 

                auto tg_xyyzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 445); 

                auto tg_xyyzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 446); 

                auto tg_xyyzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 447); 

                auto tg_xyyzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 448); 

                auto tg_xyyzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 449); 

                auto tg_xyyzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 450); 

                auto tg_xyyzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 451); 

                auto tg_xyyzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 452); 

                auto tg_xyyzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 453); 

                auto tg_xyyzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 454); 

                auto tg_xyyzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 455); 

                auto tg_xyyzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 456); 

                auto tg_xyyzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 457); 

                auto tg_xyyzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 458); 

                auto tg_xyyzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 459); 

                auto tg_yyyy_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 368); 

                auto tg_yyyy_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 369); 

                auto tg_yyyy_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 370); 

                auto tg_yyyy_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 371); 

                auto tg_yyyy_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 372); 

                auto tg_yyyy_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 373); 

                auto tg_yyyy_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 374); 

                auto tg_yyyy_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 375); 

                auto tg_yyyy_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 376); 

                auto tg_yyyy_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 377); 

                auto tg_yyyy_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 378); 

                auto tg_yyyy_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 379); 

                auto tg_yyyy_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 380); 

                auto tg_yyyy_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 381); 

                auto tg_yyyy_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 382); 

                auto tg_yyyy_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 383); 

                auto tg_yyyy_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 384); 

                auto tg_yyyy_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 385); 

                auto tg_yyyy_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 386); 

                auto tg_yyyy_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 387); 

                auto tg_yyyy_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 388); 

                auto tg_yyyy_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 389); 

                auto tg_yyyy_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 390); 

                auto tg_yyyy_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 391); 

                auto tg_yyyy_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 392); 

                auto tg_yyyy_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 393); 

                auto tg_yyyy_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 394); 

                auto tg_yyyy_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 395); 

                auto tg_yyyz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 396); 

                auto tg_yyyz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 397); 

                auto tg_yyyz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 398); 

                auto tg_yyyz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 399); 

                auto tg_yyyz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 400); 

                auto tg_yyyz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 401); 

                auto tg_yyyz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 402); 

                auto tg_yyyz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 403); 

                auto tg_yyyz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 404); 

                auto tg_yyyz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 405); 

                auto tg_yyyz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 406); 

                auto tg_yyyz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 407); 

                auto tg_yyyz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 408); 

                auto tg_yyyz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 409); 

                auto tg_yyyz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 410); 

                auto tg_yyyz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 411); 

                auto tg_yyyz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 412); 

                auto tg_yyyz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 413); 

                auto tg_yyyz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 414); 

                auto tg_yyyz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 415); 

                auto tg_yyyz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 416); 

                auto tg_yyyz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 417); 

                auto tg_yyyz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 418); 

                auto tg_yyyz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 419); 

                auto tg_yyyz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 420); 

                auto tg_yyyz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 421); 

                auto tg_yyyz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 422); 

                auto tg_yyyz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 423); 

                auto tg_yyyz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 424); 

                auto tg_yyyz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 425); 

                auto tg_yyyz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 426); 

                auto tg_yyyz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 427); 

                auto tg_yyyz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 428); 

                auto tg_yyyz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 429); 

                auto tg_yyyz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 430); 

                auto tg_yyyz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 431); 

                auto tg_yyzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 432); 

                auto tg_yyzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 433); 

                auto tg_yyzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 434); 

                auto tg_yyzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 435); 

                auto tg_yyzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 436); 

                auto tg_yyzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 437); 

                auto tg_yyzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 438); 

                auto tg_yyzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 439); 

                auto tg_yyzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 440); 

                auto tg_yyzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 441); 

                auto tg_yyzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 442); 

                auto tg_yyzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 443); 

                auto tg_yyzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 444); 

                auto tg_yyzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 445); 

                auto tg_yyzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 446); 

                auto tg_yyzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 447); 

                auto tg_yyzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 448); 

                auto tg_yyzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 449); 

                auto tg_yyzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 450); 

                auto tg_yyzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 451); 

                auto tg_yyzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 452); 

                auto tg_yyzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 453); 

                auto tg_yyzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 454); 

                auto tg_yyzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 455); 

                auto tg_yyzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 456); 

                auto tg_yyzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 457); 

                auto tg_yyzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 458); 

                auto tg_yyzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 459); 

                auto tg_yyyy_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 368); 

                auto tg_yyyy_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 369); 

                auto tg_yyyy_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 370); 

                auto tg_yyyy_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 371); 

                auto tg_yyyy_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 372); 

                auto tg_yyyy_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 373); 

                auto tg_yyyy_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 374); 

                auto tg_yyyy_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 375); 

                auto tg_yyyy_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 376); 

                auto tg_yyyy_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 377); 

                auto tg_yyyy_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 378); 

                auto tg_yyyy_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 379); 

                auto tg_yyyy_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 380); 

                auto tg_yyyy_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 381); 

                auto tg_yyyy_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 382); 

                auto tg_yyyy_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 383); 

                auto tg_yyyy_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 384); 

                auto tg_yyyy_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 385); 

                auto tg_yyyy_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 386); 

                auto tg_yyyy_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 387); 

                auto tg_yyyy_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 388); 

                auto tg_yyyy_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 389); 

                auto tg_yyyy_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 390); 

                auto tg_yyyy_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 391); 

                auto tg_yyyy_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 392); 

                auto tg_yyyy_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 393); 

                auto tg_yyyy_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 394); 

                auto tg_yyyy_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 395); 

                auto tg_yyyz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 396); 

                auto tg_yyyz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 397); 

                auto tg_yyyz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 398); 

                auto tg_yyyz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 399); 

                auto tg_yyyz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 400); 

                auto tg_yyyz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 401); 

                auto tg_yyyz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 402); 

                auto tg_yyyz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 403); 

                auto tg_yyyz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 404); 

                auto tg_yyyz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 405); 

                auto tg_yyyz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 406); 

                auto tg_yyyz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 407); 

                auto tg_yyyz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 408); 

                auto tg_yyyz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 409); 

                auto tg_yyyz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 410); 

                auto tg_yyyz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 411); 

                auto tg_yyyz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 412); 

                auto tg_yyyz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 413); 

                auto tg_yyyz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 414); 

                auto tg_yyyz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 415); 

                auto tg_yyyz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 416); 

                auto tg_yyyz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 417); 

                auto tg_yyyz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 418); 

                auto tg_yyyz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 419); 

                auto tg_yyyz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 420); 

                auto tg_yyyz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 421); 

                auto tg_yyyz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 422); 

                auto tg_yyyz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 423); 

                auto tg_yyyz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 424); 

                auto tg_yyyz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 425); 

                auto tg_yyyz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 426); 

                auto tg_yyyz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 427); 

                auto tg_yyyz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 428); 

                auto tg_yyyz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 429); 

                auto tg_yyyz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 430); 

                auto tg_yyyz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 431); 

                auto tg_yyzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 432); 

                auto tg_yyzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 433); 

                auto tg_yyzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 434); 

                auto tg_yyzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 435); 

                auto tg_yyzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 436); 

                auto tg_yyzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 437); 

                auto tg_yyzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 438); 

                auto tg_yyzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 439); 

                auto tg_yyzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 440); 

                auto tg_yyzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 441); 

                auto tg_yyzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 442); 

                auto tg_yyzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 443); 

                auto tg_yyzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 444); 

                auto tg_yyzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 445); 

                auto tg_yyzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 446); 

                auto tg_yyzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 447); 

                auto tg_yyzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 448); 

                auto tg_yyzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 449); 

                auto tg_yyzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 450); 

                auto tg_yyzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 451); 

                auto tg_yyzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 452); 

                auto tg_yyzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 453); 

                auto tg_yyzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 454); 

                auto tg_yyzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 455); 

                auto tg_yyzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 456); 

                auto tg_yyzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 457); 

                auto tg_yyzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 458); 

                auto tg_yyzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 459); 

                auto tg_xyyyy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 288); 

                auto tg_xyyyy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 289); 

                auto tg_xyyyy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 290); 

                auto tg_xyyyy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 291); 

                auto tg_xyyyy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 292); 

                auto tg_xyyyy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 293); 

                auto tg_xyyyy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 294); 

                auto tg_xyyyy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 295); 

                auto tg_xyyyy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 296); 

                auto tg_xyyyy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 297); 

                auto tg_xyyyy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 298); 

                auto tg_xyyyy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 299); 

                auto tg_xyyyy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 300); 

                auto tg_xyyyy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 301); 

                auto tg_xyyyy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 302); 

                auto tg_xyyyy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 303); 

                auto tg_xyyyy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 304); 

                auto tg_xyyyy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 305); 

                auto tg_xyyyy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 306); 

                auto tg_xyyyy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 307); 

                auto tg_xyyyz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 308); 

                auto tg_xyyyz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 309); 

                auto tg_xyyyz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 310); 

                auto tg_xyyyz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 311); 

                auto tg_xyyyz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 312); 

                auto tg_xyyyz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 313); 

                auto tg_xyyyz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 314); 

                auto tg_xyyyz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 315); 

                auto tg_xyyyz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 316); 

                auto tg_xyyyz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 317); 

                auto tg_xyyyz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 318); 

                auto tg_xyyyz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 319); 

                auto tg_xyyyz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 320); 

                auto tg_xyyyz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 321); 

                auto tg_xyyyz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 322); 

                auto tg_xyyyz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 323); 

                auto tg_xyyyz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 324); 

                auto tg_xyyyz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 325); 

                auto tg_xyyyz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 326); 

                auto tg_xyyyz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 327); 

                auto tg_xyyyz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 328); 

                auto tg_xyyyz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 329); 

                auto tg_xyyyz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 330); 

                auto tg_xyyyz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 331); 

                auto tg_xyyyz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 332); 

                auto tg_xyyyz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 333); 

                auto tg_xyyyz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 334); 

                auto tg_xyyyz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 335); 

                auto tg_xyyzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 336); 

                auto tg_xyyzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 337); 

                auto tg_xyyzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 338); 

                auto tg_xyyzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 339); 

                auto tg_xyyzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 340); 

                auto tg_xyyzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 341); 

                auto tg_xyyzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 342); 

                auto tg_xyyzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 343); 

                auto tg_xyyzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 344); 

                auto tg_xyyzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 345); 

                auto tg_xyyzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 346); 

                auto tg_xyyzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 347); 

                auto tg_xyyzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 348); 

                auto tg_xyyzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 349); 

                auto tg_xyyzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 350); 

                auto tg_xyyzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 351); 

                auto tg_xyyzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 352); 

                auto tg_xyyzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 353); 

                auto tg_xyyzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 354); 

                auto tg_xyyzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 355); 

                auto tg_xyyzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 356); 

                auto tg_xyyzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 357); 

                auto tg_xyyzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 358); 

                auto tg_xyyzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 359); 

                auto tg_xyyzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 360); 

                auto tg_xyyzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 361); 

                auto tg_xyyzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 362); 

                auto tg_xyyzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 363); 

                // set up pointers to integrals

                auto tg_xxyyyy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 368); 

                auto tg_xxyyyy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 369); 

                auto tg_xxyyyy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 370); 

                auto tg_xxyyyy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 371); 

                auto tg_xxyyyy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 372); 

                auto tg_xxyyyy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 373); 

                auto tg_xxyyyy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 374); 

                auto tg_xxyyyy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 375); 

                auto tg_xxyyyy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 376); 

                auto tg_xxyyyy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 377); 

                auto tg_xxyyyy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 378); 

                auto tg_xxyyyy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 379); 

                auto tg_xxyyyy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 380); 

                auto tg_xxyyyy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 381); 

                auto tg_xxyyyy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 382); 

                auto tg_xxyyyy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 383); 

                auto tg_xxyyyy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 384); 

                auto tg_xxyyyy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 385); 

                auto tg_xxyyyy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 386); 

                auto tg_xxyyyy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 387); 

                auto tg_xxyyyy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 388); 

                auto tg_xxyyyy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 389); 

                auto tg_xxyyyy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 390); 

                auto tg_xxyyyy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 391); 

                auto tg_xxyyyy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 392); 

                auto tg_xxyyyy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 393); 

                auto tg_xxyyyy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 394); 

                auto tg_xxyyyy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 395); 

                auto tg_xxyyyz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 396); 

                auto tg_xxyyyz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 397); 

                auto tg_xxyyyz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 398); 

                auto tg_xxyyyz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 399); 

                auto tg_xxyyyz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 400); 

                auto tg_xxyyyz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 401); 

                auto tg_xxyyyz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 402); 

                auto tg_xxyyyz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 403); 

                auto tg_xxyyyz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 404); 

                auto tg_xxyyyz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 405); 

                auto tg_xxyyyz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 406); 

                auto tg_xxyyyz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 407); 

                auto tg_xxyyyz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 408); 

                auto tg_xxyyyz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 409); 

                auto tg_xxyyyz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 410); 

                auto tg_xxyyyz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 411); 

                auto tg_xxyyyz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 412); 

                auto tg_xxyyyz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 413); 

                auto tg_xxyyyz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 414); 

                auto tg_xxyyyz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 415); 

                auto tg_xxyyyz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 416); 

                auto tg_xxyyyz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 417); 

                auto tg_xxyyyz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 418); 

                auto tg_xxyyyz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 419); 

                auto tg_xxyyyz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 420); 

                auto tg_xxyyyz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 421); 

                auto tg_xxyyyz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 422); 

                auto tg_xxyyyz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 423); 

                auto tg_xxyyyz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 424); 

                auto tg_xxyyyz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 425); 

                auto tg_xxyyyz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 426); 

                auto tg_xxyyyz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 427); 

                auto tg_xxyyyz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 428); 

                auto tg_xxyyyz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 429); 

                auto tg_xxyyyz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 430); 

                auto tg_xxyyyz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 431); 

                auto tg_xxyyzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 432); 

                auto tg_xxyyzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 433); 

                auto tg_xxyyzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 434); 

                auto tg_xxyyzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 435); 

                auto tg_xxyyzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 436); 

                auto tg_xxyyzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 437); 

                auto tg_xxyyzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 438); 

                auto tg_xxyyzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 439); 

                auto tg_xxyyzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 440); 

                auto tg_xxyyzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 441); 

                auto tg_xxyyzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 442); 

                auto tg_xxyyzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 443); 

                auto tg_xxyyzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 444); 

                auto tg_xxyyzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 445); 

                auto tg_xxyyzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 446); 

                auto tg_xxyyzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 447); 

                auto tg_xxyyzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 448); 

                auto tg_xxyyzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 449); 

                auto tg_xxyyzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 450); 

                auto tg_xxyyzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 451); 

                auto tg_xxyyzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 452); 

                auto tg_xxyyzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 453); 

                auto tg_xxyyzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 454); 

                auto tg_xxyyzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 455); 

                auto tg_xxyyzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 456); 

                auto tg_xxyyzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 457); 

                auto tg_xxyyzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 458); 

                auto tg_xxyyzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 459); 

                // Batch of Integrals (368,460)

                #pragma omp simd aligned(fxn, fza, tg_xxyyyy_xxxxyzz_0, tg_xxyyyy_xxxxzzz_0, \
                                         tg_xxyyyy_xxxyyyy_0, tg_xxyyyy_xxxyyyz_0, tg_xxyyyy_xxxyyzz_0, tg_xxyyyy_xxxyzzz_0, \
                                         tg_xxyyyy_xxxzzzz_0, tg_xxyyyy_xxyyyyy_0, tg_xxyyyy_xxyyyyz_0, tg_xxyyyy_xxyyyzz_0, \
                                         tg_xxyyyy_xxyyzzz_0, tg_xxyyyy_xxyzzzz_0, tg_xxyyyy_xxzzzzz_0, tg_xxyyyy_xyyyyyy_0, \
                                         tg_xxyyyy_xyyyyyz_0, tg_xxyyyy_xyyyyzz_0, tg_xxyyyy_xyyyzzz_0, tg_xxyyyy_xyyzzzz_0, \
                                         tg_xxyyyy_xyzzzzz_0, tg_xxyyyy_xzzzzzz_0, tg_xxyyyy_yyyyyyy_0, tg_xxyyyy_yyyyyyz_0, \
                                         tg_xxyyyy_yyyyyzz_0, tg_xxyyyy_yyyyzzz_0, tg_xxyyyy_yyyzzzz_0, tg_xxyyyy_yyzzzzz_0, \
                                         tg_xxyyyy_yzzzzzz_0, tg_xxyyyy_zzzzzzz_0, tg_xxyyyz_xxxxxxx_0, tg_xxyyyz_xxxxxxy_0, \
                                         tg_xxyyyz_xxxxxxz_0, tg_xxyyyz_xxxxxyy_0, tg_xxyyyz_xxxxxyz_0, tg_xxyyyz_xxxxxzz_0, \
                                         tg_xxyyyz_xxxxyyy_0, tg_xxyyyz_xxxxyyz_0, tg_xxyyyz_xxxxyzz_0, tg_xxyyyz_xxxxzzz_0, \
                                         tg_xxyyyz_xxxyyyy_0, tg_xxyyyz_xxxyyyz_0, tg_xxyyyz_xxxyyzz_0, tg_xxyyyz_xxxyzzz_0, \
                                         tg_xxyyyz_xxxzzzz_0, tg_xxyyyz_xxyyyyy_0, tg_xxyyyz_xxyyyyz_0, tg_xxyyyz_xxyyyzz_0, \
                                         tg_xxyyyz_xxyyzzz_0, tg_xxyyyz_xxyzzzz_0, tg_xxyyyz_xxzzzzz_0, tg_xxyyyz_xyyyyyy_0, \
                                         tg_xxyyyz_xyyyyyz_0, tg_xxyyyz_xyyyyzz_0, tg_xxyyyz_xyyyzzz_0, tg_xxyyyz_xyyzzzz_0, \
                                         tg_xxyyyz_xyzzzzz_0, tg_xxyyyz_xzzzzzz_0, tg_xxyyyz_yyyyyyy_0, tg_xxyyyz_yyyyyyz_0, \
                                         tg_xxyyyz_yyyyyzz_0, tg_xxyyyz_yyyyzzz_0, tg_xxyyyz_yyyzzzz_0, tg_xxyyyz_yyzzzzz_0, \
                                         tg_xxyyyz_yzzzzzz_0, tg_xxyyyz_zzzzzzz_0, tg_xxyyzz_xxxxxxx_0, tg_xxyyzz_xxxxxxy_0, \
                                         tg_xxyyzz_xxxxxxz_0, tg_xxyyzz_xxxxxyy_0, tg_xxyyzz_xxxxxyz_0, tg_xxyyzz_xxxxxzz_0, \
                                         tg_xxyyzz_xxxxyyy_0, tg_xxyyzz_xxxxyyz_0, tg_xxyyzz_xxxxyzz_0, tg_xxyyzz_xxxxzzz_0, \
                                         tg_xxyyzz_xxxyyyy_0, tg_xxyyzz_xxxyyyz_0, tg_xxyyzz_xxxyyzz_0, tg_xxyyzz_xxxyzzz_0, \
                                         tg_xxyyzz_xxxzzzz_0, tg_xxyyzz_xxyyyyy_0, tg_xxyyzz_xxyyyyz_0, tg_xxyyzz_xxyyyzz_0, \
                                         tg_xxyyzz_xxyyzzz_0, tg_xxyyzz_xxyzzzz_0, tg_xxyyzz_xxzzzzz_0, tg_xxyyzz_xyyyyyy_0, \
                                         tg_xxyyzz_xyyyyyz_0, tg_xxyyzz_xyyyyzz_0, tg_xxyyzz_xyyyzzz_0, tg_xxyyzz_xyyzzzz_0, \
                                         tg_xxyyzz_xyzzzzz_0, tg_xxyyzz_xzzzzzz_0, tg_xyyyy_xxxxyzz_0, tg_xyyyy_xxxxyzz_1, \
                                         tg_xyyyy_xxxxzzz_0, tg_xyyyy_xxxxzzz_1, tg_xyyyy_xxxyyyy_0, tg_xyyyy_xxxyyyy_1, \
                                         tg_xyyyy_xxxyyyz_0, tg_xyyyy_xxxyyyz_1, tg_xyyyy_xxxyyzz_0, tg_xyyyy_xxxyyzz_1, \
                                         tg_xyyyy_xxxyzz_1, tg_xyyyy_xxxyzzz_0, tg_xyyyy_xxxyzzz_1, tg_xyyyy_xxxzzz_1, \
                                         tg_xyyyy_xxxzzzz_0, tg_xyyyy_xxxzzzz_1, tg_xyyyy_xxyyyy_1, tg_xyyyy_xxyyyyy_0, \
                                         tg_xyyyy_xxyyyyy_1, tg_xyyyy_xxyyyyz_0, tg_xyyyy_xxyyyyz_1, tg_xyyyy_xxyyyz_1, \
                                         tg_xyyyy_xxyyyzz_0, tg_xyyyy_xxyyyzz_1, tg_xyyyy_xxyyzz_1, tg_xyyyy_xxyyzzz_0, \
                                         tg_xyyyy_xxyyzzz_1, tg_xyyyy_xxyzzz_1, tg_xyyyy_xxyzzzz_0, tg_xyyyy_xxyzzzz_1, \
                                         tg_xyyyy_xxzzzz_1, tg_xyyyy_xxzzzzz_0, tg_xyyyy_xxzzzzz_1, tg_xyyyy_xyyyyy_1, \
                                         tg_xyyyy_xyyyyyy_0, tg_xyyyy_xyyyyyy_1, tg_xyyyy_xyyyyyz_0, tg_xyyyy_xyyyyyz_1, \
                                         tg_xyyyy_xyyyyz_1, tg_xyyyy_xyyyyzz_0, tg_xyyyy_xyyyyzz_1, tg_xyyyy_xyyyzz_1, \
                                         tg_xyyyy_xyyyzzz_0, tg_xyyyy_xyyyzzz_1, tg_xyyyy_xyyzzz_1, tg_xyyyy_xyyzzzz_0, \
                                         tg_xyyyy_xyyzzzz_1, tg_xyyyy_xyzzzz_1, tg_xyyyy_xyzzzzz_0, tg_xyyyy_xyzzzzz_1, \
                                         tg_xyyyy_xzzzzz_1, tg_xyyyy_xzzzzzz_0, tg_xyyyy_xzzzzzz_1, tg_xyyyy_yyyyyy_1, \
                                         tg_xyyyy_yyyyyyy_0, tg_xyyyy_yyyyyyy_1, tg_xyyyy_yyyyyyz_0, tg_xyyyy_yyyyyyz_1, \
                                         tg_xyyyy_yyyyyz_1, tg_xyyyy_yyyyyzz_0, tg_xyyyy_yyyyyzz_1, tg_xyyyy_yyyyzz_1, \
                                         tg_xyyyy_yyyyzzz_0, tg_xyyyy_yyyyzzz_1, tg_xyyyy_yyyzzz_1, tg_xyyyy_yyyzzzz_0, \
                                         tg_xyyyy_yyyzzzz_1, tg_xyyyy_yyzzzz_1, tg_xyyyy_yyzzzzz_0, tg_xyyyy_yyzzzzz_1, \
                                         tg_xyyyy_yzzzzz_1, tg_xyyyy_yzzzzzz_0, tg_xyyyy_yzzzzzz_1, tg_xyyyy_zzzzzz_1, \
                                         tg_xyyyy_zzzzzzz_0, tg_xyyyy_zzzzzzz_1, tg_xyyyz_xxxxxx_1, tg_xyyyz_xxxxxxx_0, \
                                         tg_xyyyz_xxxxxxx_1, tg_xyyyz_xxxxxxy_0, tg_xyyyz_xxxxxxy_1, tg_xyyyz_xxxxxxz_0, \
                                         tg_xyyyz_xxxxxxz_1, tg_xyyyz_xxxxxy_1, tg_xyyyz_xxxxxyy_0, tg_xyyyz_xxxxxyy_1, \
                                         tg_xyyyz_xxxxxyz_0, tg_xyyyz_xxxxxyz_1, tg_xyyyz_xxxxxz_1, tg_xyyyz_xxxxxzz_0, \
                                         tg_xyyyz_xxxxxzz_1, tg_xyyyz_xxxxyy_1, tg_xyyyz_xxxxyyy_0, tg_xyyyz_xxxxyyy_1, \
                                         tg_xyyyz_xxxxyyz_0, tg_xyyyz_xxxxyyz_1, tg_xyyyz_xxxxyz_1, tg_xyyyz_xxxxyzz_0, \
                                         tg_xyyyz_xxxxyzz_1, tg_xyyyz_xxxxzz_1, tg_xyyyz_xxxxzzz_0, tg_xyyyz_xxxxzzz_1, \
                                         tg_xyyyz_xxxyyy_1, tg_xyyyz_xxxyyyy_0, tg_xyyyz_xxxyyyy_1, tg_xyyyz_xxxyyyz_0, \
                                         tg_xyyyz_xxxyyyz_1, tg_xyyyz_xxxyyz_1, tg_xyyyz_xxxyyzz_0, tg_xyyyz_xxxyyzz_1, \
                                         tg_xyyyz_xxxyzz_1, tg_xyyyz_xxxyzzz_0, tg_xyyyz_xxxyzzz_1, tg_xyyyz_xxxzzz_1, \
                                         tg_xyyyz_xxxzzzz_0, tg_xyyyz_xxxzzzz_1, tg_xyyyz_xxyyyy_1, tg_xyyyz_xxyyyyy_0, \
                                         tg_xyyyz_xxyyyyy_1, tg_xyyyz_xxyyyyz_0, tg_xyyyz_xxyyyyz_1, tg_xyyyz_xxyyyz_1, \
                                         tg_xyyyz_xxyyyzz_0, tg_xyyyz_xxyyyzz_1, tg_xyyyz_xxyyzz_1, tg_xyyyz_xxyyzzz_0, \
                                         tg_xyyyz_xxyyzzz_1, tg_xyyyz_xxyzzz_1, tg_xyyyz_xxyzzzz_0, tg_xyyyz_xxyzzzz_1, \
                                         tg_xyyyz_xxzzzz_1, tg_xyyyz_xxzzzzz_0, tg_xyyyz_xxzzzzz_1, tg_xyyyz_xyyyyy_1, \
                                         tg_xyyyz_xyyyyyy_0, tg_xyyyz_xyyyyyy_1, tg_xyyyz_xyyyyyz_0, tg_xyyyz_xyyyyyz_1, \
                                         tg_xyyyz_xyyyyz_1, tg_xyyyz_xyyyyzz_0, tg_xyyyz_xyyyyzz_1, tg_xyyyz_xyyyzz_1, \
                                         tg_xyyyz_xyyyzzz_0, tg_xyyyz_xyyyzzz_1, tg_xyyyz_xyyzzz_1, tg_xyyyz_xyyzzzz_0, \
                                         tg_xyyyz_xyyzzzz_1, tg_xyyyz_xyzzzz_1, tg_xyyyz_xyzzzzz_0, tg_xyyyz_xyzzzzz_1, \
                                         tg_xyyyz_xzzzzz_1, tg_xyyyz_xzzzzzz_0, tg_xyyyz_xzzzzzz_1, tg_xyyyz_yyyyyy_1, \
                                         tg_xyyyz_yyyyyyy_0, tg_xyyyz_yyyyyyy_1, tg_xyyyz_yyyyyyz_0, tg_xyyyz_yyyyyyz_1, \
                                         tg_xyyyz_yyyyyz_1, tg_xyyyz_yyyyyzz_0, tg_xyyyz_yyyyyzz_1, tg_xyyyz_yyyyzz_1, \
                                         tg_xyyyz_yyyyzzz_0, tg_xyyyz_yyyyzzz_1, tg_xyyyz_yyyzzz_1, tg_xyyyz_yyyzzzz_0, \
                                         tg_xyyyz_yyyzzzz_1, tg_xyyyz_yyzzzz_1, tg_xyyyz_yyzzzzz_0, tg_xyyyz_yyzzzzz_1, \
                                         tg_xyyyz_yzzzzz_1, tg_xyyyz_yzzzzzz_0, tg_xyyyz_yzzzzzz_1, tg_xyyyz_zzzzzz_1, \
                                         tg_xyyyz_zzzzzzz_0, tg_xyyyz_zzzzzzz_1, tg_xyyzz_xxxxxx_1, tg_xyyzz_xxxxxxx_0, \
                                         tg_xyyzz_xxxxxxx_1, tg_xyyzz_xxxxxxy_0, tg_xyyzz_xxxxxxy_1, tg_xyyzz_xxxxxxz_0, \
                                         tg_xyyzz_xxxxxxz_1, tg_xyyzz_xxxxxy_1, tg_xyyzz_xxxxxyy_0, tg_xyyzz_xxxxxyy_1, \
                                         tg_xyyzz_xxxxxyz_0, tg_xyyzz_xxxxxyz_1, tg_xyyzz_xxxxxz_1, tg_xyyzz_xxxxxzz_0, \
                                         tg_xyyzz_xxxxxzz_1, tg_xyyzz_xxxxyy_1, tg_xyyzz_xxxxyyy_0, tg_xyyzz_xxxxyyy_1, \
                                         tg_xyyzz_xxxxyyz_0, tg_xyyzz_xxxxyyz_1, tg_xyyzz_xxxxyz_1, tg_xyyzz_xxxxyzz_0, \
                                         tg_xyyzz_xxxxyzz_1, tg_xyyzz_xxxxzz_1, tg_xyyzz_xxxxzzz_0, tg_xyyzz_xxxxzzz_1, \
                                         tg_xyyzz_xxxyyy_1, tg_xyyzz_xxxyyyy_0, tg_xyyzz_xxxyyyy_1, tg_xyyzz_xxxyyyz_0, \
                                         tg_xyyzz_xxxyyyz_1, tg_xyyzz_xxxyyz_1, tg_xyyzz_xxxyyzz_0, tg_xyyzz_xxxyyzz_1, \
                                         tg_xyyzz_xxxyzz_1, tg_xyyzz_xxxyzzz_0, tg_xyyzz_xxxyzzz_1, tg_xyyzz_xxxzzz_1, \
                                         tg_xyyzz_xxxzzzz_0, tg_xyyzz_xxxzzzz_1, tg_xyyzz_xxyyyy_1, tg_xyyzz_xxyyyyy_0, \
                                         tg_xyyzz_xxyyyyy_1, tg_xyyzz_xxyyyyz_0, tg_xyyzz_xxyyyyz_1, tg_xyyzz_xxyyyz_1, \
                                         tg_xyyzz_xxyyyzz_0, tg_xyyzz_xxyyyzz_1, tg_xyyzz_xxyyzz_1, tg_xyyzz_xxyyzzz_0, \
                                         tg_xyyzz_xxyyzzz_1, tg_xyyzz_xxyzzz_1, tg_xyyzz_xxyzzzz_0, tg_xyyzz_xxyzzzz_1, \
                                         tg_xyyzz_xxzzzz_1, tg_xyyzz_xxzzzzz_0, tg_xyyzz_xxzzzzz_1, tg_xyyzz_xyyyyy_1, \
                                         tg_xyyzz_xyyyyyy_0, tg_xyyzz_xyyyyyy_1, tg_xyyzz_xyyyyyz_0, tg_xyyzz_xyyyyyz_1, \
                                         tg_xyyzz_xyyyyz_1, tg_xyyzz_xyyyyzz_0, tg_xyyzz_xyyyyzz_1, tg_xyyzz_xyyyzz_1, \
                                         tg_xyyzz_xyyyzzz_0, tg_xyyzz_xyyyzzz_1, tg_xyyzz_xyyzzz_1, tg_xyyzz_xyyzzzz_0, \
                                         tg_xyyzz_xyyzzzz_1, tg_xyyzz_xyzzzz_1, tg_xyyzz_xyzzzzz_0, tg_xyyzz_xyzzzzz_1, \
                                         tg_xyyzz_xzzzzz_1, tg_xyyzz_xzzzzzz_0, tg_xyyzz_xzzzzzz_1, tg_xyyzz_yyyyyy_1, \
                                         tg_xyyzz_yyyyyz_1, tg_xyyzz_yyyyzz_1, tg_xyyzz_yyyzzz_1, tg_xyyzz_yyzzzz_1, \
                                         tg_xyyzz_yzzzzz_1, tg_xyyzz_zzzzzz_1, tg_yyyy_xxxxyzz_0, tg_yyyy_xxxxyzz_1, \
                                         tg_yyyy_xxxxzzz_0, tg_yyyy_xxxxzzz_1, tg_yyyy_xxxyyyy_0, tg_yyyy_xxxyyyy_1, \
                                         tg_yyyy_xxxyyyz_0, tg_yyyy_xxxyyyz_1, tg_yyyy_xxxyyzz_0, tg_yyyy_xxxyyzz_1, \
                                         tg_yyyy_xxxyzzz_0, tg_yyyy_xxxyzzz_1, tg_yyyy_xxxzzzz_0, tg_yyyy_xxxzzzz_1, \
                                         tg_yyyy_xxyyyyy_0, tg_yyyy_xxyyyyy_1, tg_yyyy_xxyyyyz_0, tg_yyyy_xxyyyyz_1, \
                                         tg_yyyy_xxyyyzz_0, tg_yyyy_xxyyyzz_1, tg_yyyy_xxyyzzz_0, tg_yyyy_xxyyzzz_1, \
                                         tg_yyyy_xxyzzzz_0, tg_yyyy_xxyzzzz_1, tg_yyyy_xxzzzzz_0, tg_yyyy_xxzzzzz_1, \
                                         tg_yyyy_xyyyyyy_0, tg_yyyy_xyyyyyy_1, tg_yyyy_xyyyyyz_0, tg_yyyy_xyyyyyz_1, \
                                         tg_yyyy_xyyyyzz_0, tg_yyyy_xyyyyzz_1, tg_yyyy_xyyyzzz_0, tg_yyyy_xyyyzzz_1, \
                                         tg_yyyy_xyyzzzz_0, tg_yyyy_xyyzzzz_1, tg_yyyy_xyzzzzz_0, tg_yyyy_xyzzzzz_1, \
                                         tg_yyyy_xzzzzzz_0, tg_yyyy_xzzzzzz_1, tg_yyyy_yyyyyyy_0, tg_yyyy_yyyyyyy_1, \
                                         tg_yyyy_yyyyyyz_0, tg_yyyy_yyyyyyz_1, tg_yyyy_yyyyyzz_0, tg_yyyy_yyyyyzz_1, \
                                         tg_yyyy_yyyyzzz_0, tg_yyyy_yyyyzzz_1, tg_yyyy_yyyzzzz_0, tg_yyyy_yyyzzzz_1, \
                                         tg_yyyy_yyzzzzz_0, tg_yyyy_yyzzzzz_1, tg_yyyy_yzzzzzz_0, tg_yyyy_yzzzzzz_1, \
                                         tg_yyyy_zzzzzzz_0, tg_yyyy_zzzzzzz_1, tg_yyyz_xxxxxxx_0, tg_yyyz_xxxxxxx_1, \
                                         tg_yyyz_xxxxxxy_0, tg_yyyz_xxxxxxy_1, tg_yyyz_xxxxxxz_0, tg_yyyz_xxxxxxz_1, \
                                         tg_yyyz_xxxxxyy_0, tg_yyyz_xxxxxyy_1, tg_yyyz_xxxxxyz_0, tg_yyyz_xxxxxyz_1, \
                                         tg_yyyz_xxxxxzz_0, tg_yyyz_xxxxxzz_1, tg_yyyz_xxxxyyy_0, tg_yyyz_xxxxyyy_1, \
                                         tg_yyyz_xxxxyyz_0, tg_yyyz_xxxxyyz_1, tg_yyyz_xxxxyzz_0, tg_yyyz_xxxxyzz_1, \
                                         tg_yyyz_xxxxzzz_0, tg_yyyz_xxxxzzz_1, tg_yyyz_xxxyyyy_0, tg_yyyz_xxxyyyy_1, \
                                         tg_yyyz_xxxyyyz_0, tg_yyyz_xxxyyyz_1, tg_yyyz_xxxyyzz_0, tg_yyyz_xxxyyzz_1, \
                                         tg_yyyz_xxxyzzz_0, tg_yyyz_xxxyzzz_1, tg_yyyz_xxxzzzz_0, tg_yyyz_xxxzzzz_1, \
                                         tg_yyyz_xxyyyyy_0, tg_yyyz_xxyyyyy_1, tg_yyyz_xxyyyyz_0, tg_yyyz_xxyyyyz_1, \
                                         tg_yyyz_xxyyyzz_0, tg_yyyz_xxyyyzz_1, tg_yyyz_xxyyzzz_0, tg_yyyz_xxyyzzz_1, \
                                         tg_yyyz_xxyzzzz_0, tg_yyyz_xxyzzzz_1, tg_yyyz_xxzzzzz_0, tg_yyyz_xxzzzzz_1, \
                                         tg_yyyz_xyyyyyy_0, tg_yyyz_xyyyyyy_1, tg_yyyz_xyyyyyz_0, tg_yyyz_xyyyyyz_1, \
                                         tg_yyyz_xyyyyzz_0, tg_yyyz_xyyyyzz_1, tg_yyyz_xyyyzzz_0, tg_yyyz_xyyyzzz_1, \
                                         tg_yyyz_xyyzzzz_0, tg_yyyz_xyyzzzz_1, tg_yyyz_xyzzzzz_0, tg_yyyz_xyzzzzz_1, \
                                         tg_yyyz_xzzzzzz_0, tg_yyyz_xzzzzzz_1, tg_yyyz_yyyyyyy_0, tg_yyyz_yyyyyyy_1, \
                                         tg_yyyz_yyyyyyz_0, tg_yyyz_yyyyyyz_1, tg_yyyz_yyyyyzz_0, tg_yyyz_yyyyyzz_1, \
                                         tg_yyyz_yyyyzzz_0, tg_yyyz_yyyyzzz_1, tg_yyyz_yyyzzzz_0, tg_yyyz_yyyzzzz_1, \
                                         tg_yyyz_yyzzzzz_0, tg_yyyz_yyzzzzz_1, tg_yyyz_yzzzzzz_0, tg_yyyz_yzzzzzz_1, \
                                         tg_yyyz_zzzzzzz_0, tg_yyyz_zzzzzzz_1, tg_yyzz_xxxxxxx_0, tg_yyzz_xxxxxxx_1, \
                                         tg_yyzz_xxxxxxy_0, tg_yyzz_xxxxxxy_1, tg_yyzz_xxxxxxz_0, tg_yyzz_xxxxxxz_1, \
                                         tg_yyzz_xxxxxyy_0, tg_yyzz_xxxxxyy_1, tg_yyzz_xxxxxyz_0, tg_yyzz_xxxxxyz_1, \
                                         tg_yyzz_xxxxxzz_0, tg_yyzz_xxxxxzz_1, tg_yyzz_xxxxyyy_0, tg_yyzz_xxxxyyy_1, \
                                         tg_yyzz_xxxxyyz_0, tg_yyzz_xxxxyyz_1, tg_yyzz_xxxxyzz_0, tg_yyzz_xxxxyzz_1, \
                                         tg_yyzz_xxxxzzz_0, tg_yyzz_xxxxzzz_1, tg_yyzz_xxxyyyy_0, tg_yyzz_xxxyyyy_1, \
                                         tg_yyzz_xxxyyyz_0, tg_yyzz_xxxyyyz_1, tg_yyzz_xxxyyzz_0, tg_yyzz_xxxyyzz_1, \
                                         tg_yyzz_xxxyzzz_0, tg_yyzz_xxxyzzz_1, tg_yyzz_xxxzzzz_0, tg_yyzz_xxxzzzz_1, \
                                         tg_yyzz_xxyyyyy_0, tg_yyzz_xxyyyyy_1, tg_yyzz_xxyyyyz_0, tg_yyzz_xxyyyyz_1, \
                                         tg_yyzz_xxyyyzz_0, tg_yyzz_xxyyyzz_1, tg_yyzz_xxyyzzz_0, tg_yyzz_xxyyzzz_1, \
                                         tg_yyzz_xxyzzzz_0, tg_yyzz_xxyzzzz_1, tg_yyzz_xxzzzzz_0, tg_yyzz_xxzzzzz_1, \
                                         tg_yyzz_xyyyyyy_0, tg_yyzz_xyyyyyy_1, tg_yyzz_xyyyyyz_0, tg_yyzz_xyyyyyz_1, \
                                         tg_yyzz_xyyyyzz_0, tg_yyzz_xyyyyzz_1, tg_yyzz_xyyyzzz_0, tg_yyzz_xyyyzzz_1, \
                                         tg_yyzz_xyyzzzz_0, tg_yyzz_xyyzzzz_1, tg_yyzz_xyzzzzz_0, tg_yyzz_xyzzzzz_1, \
                                         tg_yyzz_xzzzzzz_0, tg_yyzz_xzzzzzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxyyyy_xxxxyzz_0[j] = pb_x * tg_xyyyy_xxxxyzz_0[j] + fr * tg_xyyyy_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxyzz_0[j] - tg_yyyy_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyy_xxxyzz_1[j];

                    tg_xxyyyy_xxxxzzz_0[j] = pb_x * tg_xyyyy_xxxxzzz_0[j] + fr * tg_xyyyy_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxxzzz_0[j] - tg_yyyy_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyy_xxxzzz_1[j];

                    tg_xxyyyy_xxxyyyy_0[j] = pb_x * tg_xyyyy_xxxyyyy_0[j] + fr * tg_xyyyy_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxyyyy_0[j] - tg_yyyy_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xxyyyy_1[j];

                    tg_xxyyyy_xxxyyyz_0[j] = pb_x * tg_xyyyy_xxxyyyz_0[j] + fr * tg_xyyyy_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxyyyz_0[j] - tg_yyyy_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xxyyyz_1[j];

                    tg_xxyyyy_xxxyyzz_0[j] = pb_x * tg_xyyyy_xxxyyzz_0[j] + fr * tg_xyyyy_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxyyzz_0[j] - tg_yyyy_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xxyyzz_1[j];

                    tg_xxyyyy_xxxyzzz_0[j] = pb_x * tg_xyyyy_xxxyzzz_0[j] + fr * tg_xyyyy_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxyzzz_0[j] - tg_yyyy_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xxyzzz_1[j];

                    tg_xxyyyy_xxxzzzz_0[j] = pb_x * tg_xyyyy_xxxzzzz_0[j] + fr * tg_xyyyy_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxxzzzz_0[j] - tg_yyyy_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyy_xxzzzz_1[j];

                    tg_xxyyyy_xxyyyyy_0[j] = pb_x * tg_xyyyy_xxyyyyy_0[j] + fr * tg_xyyyy_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxyyyyy_0[j] - tg_yyyy_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xyyyyy_1[j];

                    tg_xxyyyy_xxyyyyz_0[j] = pb_x * tg_xyyyy_xxyyyyz_0[j] + fr * tg_xyyyy_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxyyyyz_0[j] - tg_yyyy_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xyyyyz_1[j];

                    tg_xxyyyy_xxyyyzz_0[j] = pb_x * tg_xyyyy_xxyyyzz_0[j] + fr * tg_xyyyy_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxyyyzz_0[j] - tg_yyyy_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xyyyzz_1[j];

                    tg_xxyyyy_xxyyzzz_0[j] = pb_x * tg_xyyyy_xxyyzzz_0[j] + fr * tg_xyyyy_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxyyzzz_0[j] - tg_yyyy_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xyyzzz_1[j];

                    tg_xxyyyy_xxyzzzz_0[j] = pb_x * tg_xyyyy_xxyzzzz_0[j] + fr * tg_xyyyy_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxyzzzz_0[j] - tg_yyyy_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xyzzzz_1[j];

                    tg_xxyyyy_xxzzzzz_0[j] = pb_x * tg_xyyyy_xxzzzzz_0[j] + fr * tg_xyyyy_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xxzzzzz_0[j] - tg_yyyy_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyy_xzzzzz_1[j];

                    tg_xxyyyy_xyyyyyy_0[j] = pb_x * tg_xyyyy_xyyyyyy_0[j] + fr * tg_xyyyy_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyyyyyy_0[j] - tg_yyyy_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yyyyyy_1[j];

                    tg_xxyyyy_xyyyyyz_0[j] = pb_x * tg_xyyyy_xyyyyyz_0[j] + fr * tg_xyyyy_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyyyyyz_0[j] - tg_yyyy_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yyyyyz_1[j];

                    tg_xxyyyy_xyyyyzz_0[j] = pb_x * tg_xyyyy_xyyyyzz_0[j] + fr * tg_xyyyy_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyyyyzz_0[j] - tg_yyyy_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yyyyzz_1[j];

                    tg_xxyyyy_xyyyzzz_0[j] = pb_x * tg_xyyyy_xyyyzzz_0[j] + fr * tg_xyyyy_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyyyzzz_0[j] - tg_yyyy_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yyyzzz_1[j];

                    tg_xxyyyy_xyyzzzz_0[j] = pb_x * tg_xyyyy_xyyzzzz_0[j] + fr * tg_xyyyy_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyyzzzz_0[j] - tg_yyyy_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yyzzzz_1[j];

                    tg_xxyyyy_xyzzzzz_0[j] = pb_x * tg_xyyyy_xyzzzzz_0[j] + fr * tg_xyyyy_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xyzzzzz_0[j] - tg_yyyy_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_yzzzzz_1[j];

                    tg_xxyyyy_xzzzzzz_0[j] = pb_x * tg_xyyyy_xzzzzzz_0[j] + fr * tg_xyyyy_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_xzzzzzz_0[j] - tg_yyyy_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyy_zzzzzz_1[j];

                    tg_xxyyyy_yyyyyyy_0[j] = pb_x * tg_xyyyy_yyyyyyy_0[j] + fr * tg_xyyyy_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyyyyyy_0[j] - tg_yyyy_yyyyyyy_1[j] * fl1_fza);

                    tg_xxyyyy_yyyyyyz_0[j] = pb_x * tg_xyyyy_yyyyyyz_0[j] + fr * tg_xyyyy_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyyyyyz_0[j] - tg_yyyy_yyyyyyz_1[j] * fl1_fza);

                    tg_xxyyyy_yyyyyzz_0[j] = pb_x * tg_xyyyy_yyyyyzz_0[j] + fr * tg_xyyyy_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyyyyzz_0[j] - tg_yyyy_yyyyyzz_1[j] * fl1_fza);

                    tg_xxyyyy_yyyyzzz_0[j] = pb_x * tg_xyyyy_yyyyzzz_0[j] + fr * tg_xyyyy_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyyyzzz_0[j] - tg_yyyy_yyyyzzz_1[j] * fl1_fza);

                    tg_xxyyyy_yyyzzzz_0[j] = pb_x * tg_xyyyy_yyyzzzz_0[j] + fr * tg_xyyyy_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyyzzzz_0[j] - tg_yyyy_yyyzzzz_1[j] * fl1_fza);

                    tg_xxyyyy_yyzzzzz_0[j] = pb_x * tg_xyyyy_yyzzzzz_0[j] + fr * tg_xyyyy_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yyzzzzz_0[j] - tg_yyyy_yyzzzzz_1[j] * fl1_fza);

                    tg_xxyyyy_yzzzzzz_0[j] = pb_x * tg_xyyyy_yzzzzzz_0[j] + fr * tg_xyyyy_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_yzzzzzz_0[j] - tg_yyyy_yzzzzzz_1[j] * fl1_fza);

                    tg_xxyyyy_zzzzzzz_0[j] = pb_x * tg_xyyyy_zzzzzzz_0[j] + fr * tg_xyyyy_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyy_zzzzzzz_0[j] - tg_yyyy_zzzzzzz_1[j] * fl1_fza);

                    tg_xxyyyz_xxxxxxx_0[j] = pb_x * tg_xyyyz_xxxxxxx_0[j] + fr * tg_xyyyz_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxxx_0[j] - tg_yyyz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xyyyz_xxxxxx_1[j];

                    tg_xxyyyz_xxxxxxy_0[j] = pb_x * tg_xyyyz_xxxxxxy_0[j] + fr * tg_xyyyz_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxxy_0[j] - tg_yyyz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyyz_xxxxxy_1[j];

                    tg_xxyyyz_xxxxxxz_0[j] = pb_x * tg_xyyyz_xxxxxxz_0[j] + fr * tg_xyyyz_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxxz_0[j] - tg_yyyz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyyz_xxxxxz_1[j];

                    tg_xxyyyz_xxxxxyy_0[j] = pb_x * tg_xyyyz_xxxxxyy_0[j] + fr * tg_xyyyz_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxyy_0[j] - tg_yyyz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyz_xxxxyy_1[j];

                    tg_xxyyyz_xxxxxyz_0[j] = pb_x * tg_xyyyz_xxxxxyz_0[j] + fr * tg_xyyyz_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxyz_0[j] - tg_yyyz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyz_xxxxyz_1[j];

                    tg_xxyyyz_xxxxxzz_0[j] = pb_x * tg_xyyyz_xxxxxzz_0[j] + fr * tg_xyyyz_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxxzz_0[j] - tg_yyyz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyyz_xxxxzz_1[j];

                    tg_xxyyyz_xxxxyyy_0[j] = pb_x * tg_xyyyz_xxxxyyy_0[j] + fr * tg_xyyyz_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxyyy_0[j] - tg_yyyz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyz_xxxyyy_1[j];

                    tg_xxyyyz_xxxxyyz_0[j] = pb_x * tg_xyyyz_xxxxyyz_0[j] + fr * tg_xyyyz_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxyyz_0[j] - tg_yyyz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyz_xxxyyz_1[j];

                    tg_xxyyyz_xxxxyzz_0[j] = pb_x * tg_xyyyz_xxxxyzz_0[j] + fr * tg_xyyyz_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxyzz_0[j] - tg_yyyz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyz_xxxyzz_1[j];

                    tg_xxyyyz_xxxxzzz_0[j] = pb_x * tg_xyyyz_xxxxzzz_0[j] + fr * tg_xyyyz_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxxzzz_0[j] - tg_yyyz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyyz_xxxzzz_1[j];

                    tg_xxyyyz_xxxyyyy_0[j] = pb_x * tg_xyyyz_xxxyyyy_0[j] + fr * tg_xyyyz_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxyyyy_0[j] - tg_yyyz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xxyyyy_1[j];

                    tg_xxyyyz_xxxyyyz_0[j] = pb_x * tg_xyyyz_xxxyyyz_0[j] + fr * tg_xyyyz_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxyyyz_0[j] - tg_yyyz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xxyyyz_1[j];

                    tg_xxyyyz_xxxyyzz_0[j] = pb_x * tg_xyyyz_xxxyyzz_0[j] + fr * tg_xyyyz_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxyyzz_0[j] - tg_yyyz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xxyyzz_1[j];

                    tg_xxyyyz_xxxyzzz_0[j] = pb_x * tg_xyyyz_xxxyzzz_0[j] + fr * tg_xyyyz_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxyzzz_0[j] - tg_yyyz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xxyzzz_1[j];

                    tg_xxyyyz_xxxzzzz_0[j] = pb_x * tg_xyyyz_xxxzzzz_0[j] + fr * tg_xyyyz_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxxzzzz_0[j] - tg_yyyz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyyz_xxzzzz_1[j];

                    tg_xxyyyz_xxyyyyy_0[j] = pb_x * tg_xyyyz_xxyyyyy_0[j] + fr * tg_xyyyz_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxyyyyy_0[j] - tg_yyyz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xyyyyy_1[j];

                    tg_xxyyyz_xxyyyyz_0[j] = pb_x * tg_xyyyz_xxyyyyz_0[j] + fr * tg_xyyyz_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxyyyyz_0[j] - tg_yyyz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xyyyyz_1[j];

                    tg_xxyyyz_xxyyyzz_0[j] = pb_x * tg_xyyyz_xxyyyzz_0[j] + fr * tg_xyyyz_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxyyyzz_0[j] - tg_yyyz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xyyyzz_1[j];

                    tg_xxyyyz_xxyyzzz_0[j] = pb_x * tg_xyyyz_xxyyzzz_0[j] + fr * tg_xyyyz_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxyyzzz_0[j] - tg_yyyz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xyyzzz_1[j];

                    tg_xxyyyz_xxyzzzz_0[j] = pb_x * tg_xyyyz_xxyzzzz_0[j] + fr * tg_xyyyz_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxyzzzz_0[j] - tg_yyyz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xyzzzz_1[j];

                    tg_xxyyyz_xxzzzzz_0[j] = pb_x * tg_xyyyz_xxzzzzz_0[j] + fr * tg_xyyyz_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xxzzzzz_0[j] - tg_yyyz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyyz_xzzzzz_1[j];

                    tg_xxyyyz_xyyyyyy_0[j] = pb_x * tg_xyyyz_xyyyyyy_0[j] + fr * tg_xyyyz_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyyyyyy_0[j] - tg_yyyz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yyyyyy_1[j];

                    tg_xxyyyz_xyyyyyz_0[j] = pb_x * tg_xyyyz_xyyyyyz_0[j] + fr * tg_xyyyz_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyyyyyz_0[j] - tg_yyyz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yyyyyz_1[j];

                    tg_xxyyyz_xyyyyzz_0[j] = pb_x * tg_xyyyz_xyyyyzz_0[j] + fr * tg_xyyyz_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyyyyzz_0[j] - tg_yyyz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yyyyzz_1[j];

                    tg_xxyyyz_xyyyzzz_0[j] = pb_x * tg_xyyyz_xyyyzzz_0[j] + fr * tg_xyyyz_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyyyzzz_0[j] - tg_yyyz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yyyzzz_1[j];

                    tg_xxyyyz_xyyzzzz_0[j] = pb_x * tg_xyyyz_xyyzzzz_0[j] + fr * tg_xyyyz_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyyzzzz_0[j] - tg_yyyz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yyzzzz_1[j];

                    tg_xxyyyz_xyzzzzz_0[j] = pb_x * tg_xyyyz_xyzzzzz_0[j] + fr * tg_xyyyz_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xyzzzzz_0[j] - tg_yyyz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_yzzzzz_1[j];

                    tg_xxyyyz_xzzzzzz_0[j] = pb_x * tg_xyyyz_xzzzzzz_0[j] + fr * tg_xyyyz_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_xzzzzzz_0[j] - tg_yyyz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyyz_zzzzzz_1[j];

                    tg_xxyyyz_yyyyyyy_0[j] = pb_x * tg_xyyyz_yyyyyyy_0[j] + fr * tg_xyyyz_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyyyyyy_0[j] - tg_yyyz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxyyyz_yyyyyyz_0[j] = pb_x * tg_xyyyz_yyyyyyz_0[j] + fr * tg_xyyyz_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyyyyyz_0[j] - tg_yyyz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxyyyz_yyyyyzz_0[j] = pb_x * tg_xyyyz_yyyyyzz_0[j] + fr * tg_xyyyz_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyyyyzz_0[j] - tg_yyyz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxyyyz_yyyyzzz_0[j] = pb_x * tg_xyyyz_yyyyzzz_0[j] + fr * tg_xyyyz_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyyyzzz_0[j] - tg_yyyz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxyyyz_yyyzzzz_0[j] = pb_x * tg_xyyyz_yyyzzzz_0[j] + fr * tg_xyyyz_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyyzzzz_0[j] - tg_yyyz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxyyyz_yyzzzzz_0[j] = pb_x * tg_xyyyz_yyzzzzz_0[j] + fr * tg_xyyyz_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yyzzzzz_0[j] - tg_yyyz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxyyyz_yzzzzzz_0[j] = pb_x * tg_xyyyz_yzzzzzz_0[j] + fr * tg_xyyyz_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_yzzzzzz_0[j] - tg_yyyz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxyyyz_zzzzzzz_0[j] = pb_x * tg_xyyyz_zzzzzzz_0[j] + fr * tg_xyyyz_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyyz_zzzzzzz_0[j] - tg_yyyz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxyyzz_xxxxxxx_0[j] = pb_x * tg_xyyzz_xxxxxxx_0[j] + fr * tg_xyyzz_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxxx_0[j] - tg_yyzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xyyzz_xxxxxx_1[j];

                    tg_xxyyzz_xxxxxxy_0[j] = pb_x * tg_xyyzz_xxxxxxy_0[j] + fr * tg_xyyzz_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxxy_0[j] - tg_yyzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyzz_xxxxxy_1[j];

                    tg_xxyyzz_xxxxxxz_0[j] = pb_x * tg_xyyzz_xxxxxxz_0[j] + fr * tg_xyyzz_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxxz_0[j] - tg_yyzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyyzz_xxxxxz_1[j];

                    tg_xxyyzz_xxxxxyy_0[j] = pb_x * tg_xyyzz_xxxxxyy_0[j] + fr * tg_xyyzz_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxyy_0[j] - tg_yyzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyzz_xxxxyy_1[j];

                    tg_xxyyzz_xxxxxyz_0[j] = pb_x * tg_xyyzz_xxxxxyz_0[j] + fr * tg_xyyzz_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxyz_0[j] - tg_yyzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyzz_xxxxyz_1[j];

                    tg_xxyyzz_xxxxxzz_0[j] = pb_x * tg_xyyzz_xxxxxzz_0[j] + fr * tg_xyyzz_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxxzz_0[j] - tg_yyzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyyzz_xxxxzz_1[j];

                    tg_xxyyzz_xxxxyyy_0[j] = pb_x * tg_xyyzz_xxxxyyy_0[j] + fr * tg_xyyzz_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxyyy_0[j] - tg_yyzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyzz_xxxyyy_1[j];

                    tg_xxyyzz_xxxxyyz_0[j] = pb_x * tg_xyyzz_xxxxyyz_0[j] + fr * tg_xyyzz_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxyyz_0[j] - tg_yyzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyzz_xxxyyz_1[j];

                    tg_xxyyzz_xxxxyzz_0[j] = pb_x * tg_xyyzz_xxxxyzz_0[j] + fr * tg_xyyzz_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxyzz_0[j] - tg_yyzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyzz_xxxyzz_1[j];

                    tg_xxyyzz_xxxxzzz_0[j] = pb_x * tg_xyyzz_xxxxzzz_0[j] + fr * tg_xyyzz_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxxzzz_0[j] - tg_yyzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyyzz_xxxzzz_1[j];

                    tg_xxyyzz_xxxyyyy_0[j] = pb_x * tg_xyyzz_xxxyyyy_0[j] + fr * tg_xyyzz_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxyyyy_0[j] - tg_yyzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xxyyyy_1[j];

                    tg_xxyyzz_xxxyyyz_0[j] = pb_x * tg_xyyzz_xxxyyyz_0[j] + fr * tg_xyyzz_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxyyyz_0[j] - tg_yyzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xxyyyz_1[j];

                    tg_xxyyzz_xxxyyzz_0[j] = pb_x * tg_xyyzz_xxxyyzz_0[j] + fr * tg_xyyzz_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxyyzz_0[j] - tg_yyzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xxyyzz_1[j];

                    tg_xxyyzz_xxxyzzz_0[j] = pb_x * tg_xyyzz_xxxyzzz_0[j] + fr * tg_xyyzz_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxyzzz_0[j] - tg_yyzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xxyzzz_1[j];

                    tg_xxyyzz_xxxzzzz_0[j] = pb_x * tg_xyyzz_xxxzzzz_0[j] + fr * tg_xyyzz_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxxzzzz_0[j] - tg_yyzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyyzz_xxzzzz_1[j];

                    tg_xxyyzz_xxyyyyy_0[j] = pb_x * tg_xyyzz_xxyyyyy_0[j] + fr * tg_xyyzz_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxyyyyy_0[j] - tg_yyzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xyyyyy_1[j];

                    tg_xxyyzz_xxyyyyz_0[j] = pb_x * tg_xyyzz_xxyyyyz_0[j] + fr * tg_xyyzz_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxyyyyz_0[j] - tg_yyzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xyyyyz_1[j];

                    tg_xxyyzz_xxyyyzz_0[j] = pb_x * tg_xyyzz_xxyyyzz_0[j] + fr * tg_xyyzz_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxyyyzz_0[j] - tg_yyzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xyyyzz_1[j];

                    tg_xxyyzz_xxyyzzz_0[j] = pb_x * tg_xyyzz_xxyyzzz_0[j] + fr * tg_xyyzz_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxyyzzz_0[j] - tg_yyzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xyyzzz_1[j];

                    tg_xxyyzz_xxyzzzz_0[j] = pb_x * tg_xyyzz_xxyzzzz_0[j] + fr * tg_xyyzz_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxyzzzz_0[j] - tg_yyzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xyzzzz_1[j];

                    tg_xxyyzz_xxzzzzz_0[j] = pb_x * tg_xyyzz_xxzzzzz_0[j] + fr * tg_xyyzz_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xxzzzzz_0[j] - tg_yyzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyyzz_xzzzzz_1[j];

                    tg_xxyyzz_xyyyyyy_0[j] = pb_x * tg_xyyzz_xyyyyyy_0[j] + fr * tg_xyyzz_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyyyyyy_0[j] - tg_yyzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yyyyyy_1[j];

                    tg_xxyyzz_xyyyyyz_0[j] = pb_x * tg_xyyzz_xyyyyyz_0[j] + fr * tg_xyyzz_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyyyyyz_0[j] - tg_yyzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yyyyyz_1[j];

                    tg_xxyyzz_xyyyyzz_0[j] = pb_x * tg_xyyzz_xyyyyzz_0[j] + fr * tg_xyyzz_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyyyyzz_0[j] - tg_yyzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yyyyzz_1[j];

                    tg_xxyyzz_xyyyzzz_0[j] = pb_x * tg_xyyzz_xyyyzzz_0[j] + fr * tg_xyyzz_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyyyzzz_0[j] - tg_yyzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yyyzzz_1[j];

                    tg_xxyyzz_xyyzzzz_0[j] = pb_x * tg_xyyzz_xyyzzzz_0[j] + fr * tg_xyyzz_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyyzzzz_0[j] - tg_yyzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yyzzzz_1[j];

                    tg_xxyyzz_xyzzzzz_0[j] = pb_x * tg_xyyzz_xyzzzzz_0[j] + fr * tg_xyyzz_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xyzzzzz_0[j] - tg_yyzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_yzzzzz_1[j];

                    tg_xxyyzz_xzzzzzz_0[j] = pb_x * tg_xyyzz_xzzzzzz_0[j] + fr * tg_xyyzz_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_xzzzzzz_0[j] - tg_yyzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyyzz_zzzzzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_460_552(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (460,552)

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
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto tg_xyyzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 460); 

                auto tg_xyyzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 461); 

                auto tg_xyyzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 462); 

                auto tg_xyyzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 463); 

                auto tg_xyyzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 464); 

                auto tg_xyyzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 465); 

                auto tg_xyyzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 466); 

                auto tg_xyyzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 467); 

                auto tg_xyzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 468); 

                auto tg_xyzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 469); 

                auto tg_xyzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 470); 

                auto tg_xyzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 471); 

                auto tg_xyzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 472); 

                auto tg_xyzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 473); 

                auto tg_xyzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 474); 

                auto tg_xyzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 475); 

                auto tg_xyzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 476); 

                auto tg_xyzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 477); 

                auto tg_xyzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 478); 

                auto tg_xyzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 479); 

                auto tg_xyzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 480); 

                auto tg_xyzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 481); 

                auto tg_xyzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 482); 

                auto tg_xyzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 483); 

                auto tg_xyzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 484); 

                auto tg_xyzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 485); 

                auto tg_xyzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 486); 

                auto tg_xyzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 487); 

                auto tg_xyzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 488); 

                auto tg_xyzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 489); 

                auto tg_xyzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 490); 

                auto tg_xyzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 491); 

                auto tg_xyzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 492); 

                auto tg_xyzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 493); 

                auto tg_xyzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 494); 

                auto tg_xyzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 495); 

                auto tg_xyzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 496); 

                auto tg_xyzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 497); 

                auto tg_xyzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 498); 

                auto tg_xyzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 499); 

                auto tg_xyzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 500); 

                auto tg_xyzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 501); 

                auto tg_xyzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 502); 

                auto tg_xyzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 503); 

                auto tg_xzzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 504); 

                auto tg_xzzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 505); 

                auto tg_xzzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 506); 

                auto tg_xzzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 507); 

                auto tg_xzzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 508); 

                auto tg_xzzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 509); 

                auto tg_xzzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 510); 

                auto tg_xzzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 511); 

                auto tg_xzzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 512); 

                auto tg_xzzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 513); 

                auto tg_xzzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 514); 

                auto tg_xzzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 515); 

                auto tg_xzzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 516); 

                auto tg_xzzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 517); 

                auto tg_xzzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 518); 

                auto tg_xzzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 519); 

                auto tg_xzzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 520); 

                auto tg_xzzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 521); 

                auto tg_xzzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 522); 

                auto tg_xzzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 523); 

                auto tg_xzzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 524); 

                auto tg_xzzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 525); 

                auto tg_xzzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 526); 

                auto tg_xzzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 527); 

                auto tg_xzzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 528); 

                auto tg_xzzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 529); 

                auto tg_xzzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 530); 

                auto tg_xzzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 531); 

                auto tg_xzzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 532); 

                auto tg_xzzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 533); 

                auto tg_xzzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 534); 

                auto tg_xzzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 535); 

                auto tg_xzzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 536); 

                auto tg_xzzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 537); 

                auto tg_xzzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 538); 

                auto tg_xzzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 539); 

                auto tg_yyyyy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 540); 

                auto tg_yyyyy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 541); 

                auto tg_yyyyy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 542); 

                auto tg_yyyyy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 543); 

                auto tg_yyyyy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 544); 

                auto tg_yyyyy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 545); 

                auto tg_yyyyy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 546); 

                auto tg_yyyyy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 547); 

                auto tg_yyyyy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 548); 

                auto tg_yyyyy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 549); 

                auto tg_yyyyy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 550); 

                auto tg_yyyyy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 551); 

                auto tg_xyyzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 460); 

                auto tg_xyyzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 461); 

                auto tg_xyyzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 462); 

                auto tg_xyyzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 463); 

                auto tg_xyyzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 464); 

                auto tg_xyyzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 465); 

                auto tg_xyyzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 466); 

                auto tg_xyyzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 467); 

                auto tg_xyzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 468); 

                auto tg_xyzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 469); 

                auto tg_xyzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 470); 

                auto tg_xyzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 471); 

                auto tg_xyzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 472); 

                auto tg_xyzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 473); 

                auto tg_xyzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 474); 

                auto tg_xyzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 475); 

                auto tg_xyzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 476); 

                auto tg_xyzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 477); 

                auto tg_xyzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 478); 

                auto tg_xyzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 479); 

                auto tg_xyzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 480); 

                auto tg_xyzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 481); 

                auto tg_xyzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 482); 

                auto tg_xyzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 483); 

                auto tg_xyzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 484); 

                auto tg_xyzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 485); 

                auto tg_xyzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 486); 

                auto tg_xyzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 487); 

                auto tg_xyzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 488); 

                auto tg_xyzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 489); 

                auto tg_xyzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 490); 

                auto tg_xyzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 491); 

                auto tg_xyzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 492); 

                auto tg_xyzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 493); 

                auto tg_xyzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 494); 

                auto tg_xyzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 495); 

                auto tg_xyzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 496); 

                auto tg_xyzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 497); 

                auto tg_xyzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 498); 

                auto tg_xyzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 499); 

                auto tg_xyzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 500); 

                auto tg_xyzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 501); 

                auto tg_xyzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 502); 

                auto tg_xyzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 503); 

                auto tg_xzzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 504); 

                auto tg_xzzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 505); 

                auto tg_xzzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 506); 

                auto tg_xzzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 507); 

                auto tg_xzzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 508); 

                auto tg_xzzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 509); 

                auto tg_xzzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 510); 

                auto tg_xzzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 511); 

                auto tg_xzzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 512); 

                auto tg_xzzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 513); 

                auto tg_xzzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 514); 

                auto tg_xzzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 515); 

                auto tg_xzzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 516); 

                auto tg_xzzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 517); 

                auto tg_xzzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 518); 

                auto tg_xzzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 519); 

                auto tg_xzzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 520); 

                auto tg_xzzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 521); 

                auto tg_xzzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 522); 

                auto tg_xzzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 523); 

                auto tg_xzzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 524); 

                auto tg_xzzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 525); 

                auto tg_xzzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 526); 

                auto tg_xzzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 527); 

                auto tg_xzzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 528); 

                auto tg_xzzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 529); 

                auto tg_xzzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 530); 

                auto tg_xzzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 531); 

                auto tg_xzzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 532); 

                auto tg_xzzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 533); 

                auto tg_xzzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 534); 

                auto tg_xzzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 535); 

                auto tg_xzzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 536); 

                auto tg_xzzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 537); 

                auto tg_xzzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 538); 

                auto tg_xzzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 539); 

                auto tg_yyyyy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 540); 

                auto tg_yyyyy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 541); 

                auto tg_yyyyy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 542); 

                auto tg_yyyyy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 543); 

                auto tg_yyyyy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 544); 

                auto tg_yyyyy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 545); 

                auto tg_yyyyy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 546); 

                auto tg_yyyyy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 547); 

                auto tg_yyyyy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 548); 

                auto tg_yyyyy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 549); 

                auto tg_yyyyy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 550); 

                auto tg_yyyyy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 551); 

                auto tg_yyzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 460); 

                auto tg_yyzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 461); 

                auto tg_yyzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 462); 

                auto tg_yyzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 463); 

                auto tg_yyzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 464); 

                auto tg_yyzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 465); 

                auto tg_yyzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 466); 

                auto tg_yyzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 467); 

                auto tg_yzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 468); 

                auto tg_yzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 469); 

                auto tg_yzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 470); 

                auto tg_yzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 471); 

                auto tg_yzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 472); 

                auto tg_yzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 473); 

                auto tg_yzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 474); 

                auto tg_yzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 475); 

                auto tg_yzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 476); 

                auto tg_yzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 477); 

                auto tg_yzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 478); 

                auto tg_yzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 479); 

                auto tg_yzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 480); 

                auto tg_yzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 481); 

                auto tg_yzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 482); 

                auto tg_yzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 483); 

                auto tg_yzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 484); 

                auto tg_yzzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 485); 

                auto tg_yzzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 486); 

                auto tg_yzzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 487); 

                auto tg_yzzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 488); 

                auto tg_yzzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 489); 

                auto tg_yzzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 490); 

                auto tg_yzzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 491); 

                auto tg_yzzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 492); 

                auto tg_yzzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 493); 

                auto tg_yzzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 494); 

                auto tg_yzzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 495); 

                auto tg_yzzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 496); 

                auto tg_yzzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 497); 

                auto tg_yzzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 498); 

                auto tg_yzzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 499); 

                auto tg_yzzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 500); 

                auto tg_yzzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 501); 

                auto tg_yzzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 502); 

                auto tg_yzzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 503); 

                auto tg_zzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 520); 

                auto tg_zzzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 521); 

                auto tg_zzzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 522); 

                auto tg_zzzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 523); 

                auto tg_zzzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 524); 

                auto tg_zzzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 525); 

                auto tg_zzzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 526); 

                auto tg_zzzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 527); 

                auto tg_zzzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 528); 

                auto tg_zzzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 529); 

                auto tg_zzzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 530); 

                auto tg_zzzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 531); 

                auto tg_zzzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 532); 

                auto tg_zzzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 533); 

                auto tg_zzzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 534); 

                auto tg_zzzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 535); 

                auto tg_zzzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 536); 

                auto tg_zzzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 537); 

                auto tg_zzzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 538); 

                auto tg_zzzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 539); 

                auto tg_yyzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 460); 

                auto tg_yyzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 461); 

                auto tg_yyzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 462); 

                auto tg_yyzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 463); 

                auto tg_yyzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 464); 

                auto tg_yyzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 465); 

                auto tg_yyzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 466); 

                auto tg_yyzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 467); 

                auto tg_yzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 468); 

                auto tg_yzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 469); 

                auto tg_yzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 470); 

                auto tg_yzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 471); 

                auto tg_yzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 472); 

                auto tg_yzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 473); 

                auto tg_yzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 474); 

                auto tg_yzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 475); 

                auto tg_yzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 476); 

                auto tg_yzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 477); 

                auto tg_yzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 478); 

                auto tg_yzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 479); 

                auto tg_yzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 480); 

                auto tg_yzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 481); 

                auto tg_yzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 482); 

                auto tg_yzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 483); 

                auto tg_yzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 484); 

                auto tg_yzzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 485); 

                auto tg_yzzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 486); 

                auto tg_yzzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 487); 

                auto tg_yzzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 488); 

                auto tg_yzzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 489); 

                auto tg_yzzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 490); 

                auto tg_yzzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 491); 

                auto tg_yzzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 492); 

                auto tg_yzzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 493); 

                auto tg_yzzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 494); 

                auto tg_yzzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 495); 

                auto tg_yzzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 496); 

                auto tg_yzzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 497); 

                auto tg_yzzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 498); 

                auto tg_yzzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 499); 

                auto tg_yzzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 500); 

                auto tg_yzzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 501); 

                auto tg_yzzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 502); 

                auto tg_yzzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 503); 

                auto tg_zzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 520); 

                auto tg_zzzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 521); 

                auto tg_zzzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 522); 

                auto tg_zzzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 523); 

                auto tg_zzzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 524); 

                auto tg_zzzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 525); 

                auto tg_zzzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 526); 

                auto tg_zzzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 527); 

                auto tg_zzzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 528); 

                auto tg_zzzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 529); 

                auto tg_zzzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 530); 

                auto tg_zzzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 531); 

                auto tg_zzzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 532); 

                auto tg_zzzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 533); 

                auto tg_zzzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 534); 

                auto tg_zzzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 535); 

                auto tg_zzzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 536); 

                auto tg_zzzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 537); 

                auto tg_zzzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 538); 

                auto tg_zzzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 539); 

                auto tg_xyzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 364); 

                auto tg_xyzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 365); 

                auto tg_xyzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 366); 

                auto tg_xyzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 367); 

                auto tg_xyzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 368); 

                auto tg_xyzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 369); 

                auto tg_xyzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 370); 

                auto tg_xyzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 371); 

                auto tg_xyzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 372); 

                auto tg_xyzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 373); 

                auto tg_xyzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 374); 

                auto tg_xyzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 375); 

                auto tg_xyzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 376); 

                auto tg_xyzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 377); 

                auto tg_xyzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 378); 

                auto tg_xyzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 379); 

                auto tg_xyzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 380); 

                auto tg_xyzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 381); 

                auto tg_xyzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 382); 

                auto tg_xyzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 383); 

                auto tg_xyzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 384); 

                auto tg_xyzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 385); 

                auto tg_xyzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 386); 

                auto tg_xyzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 387); 

                auto tg_xyzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 388); 

                auto tg_xyzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 389); 

                auto tg_xyzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 390); 

                auto tg_xyzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 391); 

                auto tg_xzzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 392); 

                auto tg_xzzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 393); 

                auto tg_xzzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 394); 

                auto tg_xzzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 395); 

                auto tg_xzzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 396); 

                auto tg_xzzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 397); 

                auto tg_xzzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 398); 

                auto tg_xzzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 399); 

                auto tg_xzzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 400); 

                auto tg_xzzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 401); 

                auto tg_xzzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 402); 

                auto tg_xzzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 403); 

                auto tg_xzzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 404); 

                auto tg_xzzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 405); 

                auto tg_xzzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 406); 

                auto tg_xzzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 407); 

                auto tg_xzzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 408); 

                auto tg_xzzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 409); 

                auto tg_xzzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 410); 

                auto tg_xzzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 411); 

                auto tg_xzzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 412); 

                auto tg_xzzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 413); 

                auto tg_xzzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 414); 

                auto tg_xzzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 415); 

                auto tg_xzzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 416); 

                auto tg_xzzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 417); 

                auto tg_xzzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 418); 

                auto tg_xzzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 419); 

                auto tg_yyyyy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 420); 

                auto tg_yyyyy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 421); 

                auto tg_yyyyy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 422); 

                auto tg_yyyyy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 423); 

                auto tg_yyyyy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 424); 

                auto tg_yyyyy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 425); 

                auto tg_yyyyy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 426); 

                auto tg_yyyyy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 427); 

                auto tg_yyyyy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 428); 

                auto tg_yyyyy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 429); 

                auto tg_yyyyy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 430); 

                auto tg_yyyyy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 431); 

                // set up pointers to integrals

                auto tg_xxyyzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 460); 

                auto tg_xxyyzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 461); 

                auto tg_xxyyzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 462); 

                auto tg_xxyyzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 463); 

                auto tg_xxyyzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 464); 

                auto tg_xxyyzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 465); 

                auto tg_xxyyzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 466); 

                auto tg_xxyyzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 467); 

                auto tg_xxyzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 468); 

                auto tg_xxyzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 469); 

                auto tg_xxyzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 470); 

                auto tg_xxyzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 471); 

                auto tg_xxyzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 472); 

                auto tg_xxyzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 473); 

                auto tg_xxyzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 474); 

                auto tg_xxyzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 475); 

                auto tg_xxyzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 476); 

                auto tg_xxyzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 477); 

                auto tg_xxyzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 478); 

                auto tg_xxyzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 479); 

                auto tg_xxyzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 480); 

                auto tg_xxyzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 481); 

                auto tg_xxyzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 482); 

                auto tg_xxyzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 483); 

                auto tg_xxyzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 484); 

                auto tg_xxyzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 485); 

                auto tg_xxyzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 486); 

                auto tg_xxyzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 487); 

                auto tg_xxyzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 488); 

                auto tg_xxyzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 489); 

                auto tg_xxyzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 490); 

                auto tg_xxyzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 491); 

                auto tg_xxyzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 492); 

                auto tg_xxyzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 493); 

                auto tg_xxyzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 494); 

                auto tg_xxyzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 495); 

                auto tg_xxyzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 496); 

                auto tg_xxyzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 497); 

                auto tg_xxyzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 498); 

                auto tg_xxyzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 499); 

                auto tg_xxyzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 500); 

                auto tg_xxyzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 501); 

                auto tg_xxyzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 502); 

                auto tg_xxyzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 503); 

                auto tg_xxzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 504); 

                auto tg_xxzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 505); 

                auto tg_xxzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 506); 

                auto tg_xxzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 507); 

                auto tg_xxzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 508); 

                auto tg_xxzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 509); 

                auto tg_xxzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 510); 

                auto tg_xxzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 511); 

                auto tg_xxzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 512); 

                auto tg_xxzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 513); 

                auto tg_xxzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 514); 

                auto tg_xxzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 515); 

                auto tg_xxzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 516); 

                auto tg_xxzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 517); 

                auto tg_xxzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 518); 

                auto tg_xxzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 519); 

                auto tg_xxzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 520); 

                auto tg_xxzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 521); 

                auto tg_xxzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 522); 

                auto tg_xxzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 523); 

                auto tg_xxzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 524); 

                auto tg_xxzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 525); 

                auto tg_xxzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 526); 

                auto tg_xxzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 527); 

                auto tg_xxzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 528); 

                auto tg_xxzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 529); 

                auto tg_xxzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 530); 

                auto tg_xxzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 531); 

                auto tg_xxzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 532); 

                auto tg_xxzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 533); 

                auto tg_xxzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 534); 

                auto tg_xxzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 535); 

                auto tg_xxzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 536); 

                auto tg_xxzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 537); 

                auto tg_xxzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 538); 

                auto tg_xxzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 539); 

                auto tg_xyyyyy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 540); 

                auto tg_xyyyyy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 541); 

                auto tg_xyyyyy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 542); 

                auto tg_xyyyyy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 543); 

                auto tg_xyyyyy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 544); 

                auto tg_xyyyyy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 545); 

                auto tg_xyyyyy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 546); 

                auto tg_xyyyyy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 547); 

                auto tg_xyyyyy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 548); 

                auto tg_xyyyyy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 549); 

                auto tg_xyyyyy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 550); 

                auto tg_xyyyyy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 551); 

                // Batch of Integrals (460,552)

                #pragma omp simd aligned(fxn, fza, tg_xxyyzz_yyyyyyy_0, tg_xxyyzz_yyyyyyz_0, \
                                         tg_xxyyzz_yyyyyzz_0, tg_xxyyzz_yyyyzzz_0, tg_xxyyzz_yyyzzzz_0, tg_xxyyzz_yyzzzzz_0, \
                                         tg_xxyyzz_yzzzzzz_0, tg_xxyyzz_zzzzzzz_0, tg_xxyzzz_xxxxxxx_0, tg_xxyzzz_xxxxxxy_0, \
                                         tg_xxyzzz_xxxxxxz_0, tg_xxyzzz_xxxxxyy_0, tg_xxyzzz_xxxxxyz_0, tg_xxyzzz_xxxxxzz_0, \
                                         tg_xxyzzz_xxxxyyy_0, tg_xxyzzz_xxxxyyz_0, tg_xxyzzz_xxxxyzz_0, tg_xxyzzz_xxxxzzz_0, \
                                         tg_xxyzzz_xxxyyyy_0, tg_xxyzzz_xxxyyyz_0, tg_xxyzzz_xxxyyzz_0, tg_xxyzzz_xxxyzzz_0, \
                                         tg_xxyzzz_xxxzzzz_0, tg_xxyzzz_xxyyyyy_0, tg_xxyzzz_xxyyyyz_0, tg_xxyzzz_xxyyyzz_0, \
                                         tg_xxyzzz_xxyyzzz_0, tg_xxyzzz_xxyzzzz_0, tg_xxyzzz_xxzzzzz_0, tg_xxyzzz_xyyyyyy_0, \
                                         tg_xxyzzz_xyyyyyz_0, tg_xxyzzz_xyyyyzz_0, tg_xxyzzz_xyyyzzz_0, tg_xxyzzz_xyyzzzz_0, \
                                         tg_xxyzzz_xyzzzzz_0, tg_xxyzzz_xzzzzzz_0, tg_xxyzzz_yyyyyyy_0, tg_xxyzzz_yyyyyyz_0, \
                                         tg_xxyzzz_yyyyyzz_0, tg_xxyzzz_yyyyzzz_0, tg_xxyzzz_yyyzzzz_0, tg_xxyzzz_yyzzzzz_0, \
                                         tg_xxyzzz_yzzzzzz_0, tg_xxyzzz_zzzzzzz_0, tg_xxzzzz_xxxxxxx_0, tg_xxzzzz_xxxxxxy_0, \
                                         tg_xxzzzz_xxxxxxz_0, tg_xxzzzz_xxxxxyy_0, tg_xxzzzz_xxxxxyz_0, tg_xxzzzz_xxxxxzz_0, \
                                         tg_xxzzzz_xxxxyyy_0, tg_xxzzzz_xxxxyyz_0, tg_xxzzzz_xxxxyzz_0, tg_xxzzzz_xxxxzzz_0, \
                                         tg_xxzzzz_xxxyyyy_0, tg_xxzzzz_xxxyyyz_0, tg_xxzzzz_xxxyyzz_0, tg_xxzzzz_xxxyzzz_0, \
                                         tg_xxzzzz_xxxzzzz_0, tg_xxzzzz_xxyyyyy_0, tg_xxzzzz_xxyyyyz_0, tg_xxzzzz_xxyyyzz_0, \
                                         tg_xxzzzz_xxyyzzz_0, tg_xxzzzz_xxyzzzz_0, tg_xxzzzz_xxzzzzz_0, tg_xxzzzz_xyyyyyy_0, \
                                         tg_xxzzzz_xyyyyyz_0, tg_xxzzzz_xyyyyzz_0, tg_xxzzzz_xyyyzzz_0, tg_xxzzzz_xyyzzzz_0, \
                                         tg_xxzzzz_xyzzzzz_0, tg_xxzzzz_xzzzzzz_0, tg_xxzzzz_yyyyyyy_0, tg_xxzzzz_yyyyyyz_0, \
                                         tg_xxzzzz_yyyyyzz_0, tg_xxzzzz_yyyyzzz_0, tg_xxzzzz_yyyzzzz_0, tg_xxzzzz_yyzzzzz_0, \
                                         tg_xxzzzz_yzzzzzz_0, tg_xxzzzz_zzzzzzz_0, tg_xyyyyy_xxxxxxx_0, tg_xyyyyy_xxxxxxy_0, \
                                         tg_xyyyyy_xxxxxxz_0, tg_xyyyyy_xxxxxyy_0, tg_xyyyyy_xxxxxyz_0, tg_xyyyyy_xxxxxzz_0, \
                                         tg_xyyyyy_xxxxyyy_0, tg_xyyyyy_xxxxyyz_0, tg_xyyyyy_xxxxyzz_0, tg_xyyyyy_xxxxzzz_0, \
                                         tg_xyyyyy_xxxyyyy_0, tg_xyyyyy_xxxyyyz_0, tg_xyyzz_yyyyyyy_0, tg_xyyzz_yyyyyyy_1, \
                                         tg_xyyzz_yyyyyyz_0, tg_xyyzz_yyyyyyz_1, tg_xyyzz_yyyyyzz_0, tg_xyyzz_yyyyyzz_1, \
                                         tg_xyyzz_yyyyzzz_0, tg_xyyzz_yyyyzzz_1, tg_xyyzz_yyyzzzz_0, tg_xyyzz_yyyzzzz_1, \
                                         tg_xyyzz_yyzzzzz_0, tg_xyyzz_yyzzzzz_1, tg_xyyzz_yzzzzzz_0, tg_xyyzz_yzzzzzz_1, \
                                         tg_xyyzz_zzzzzzz_0, tg_xyyzz_zzzzzzz_1, tg_xyzzz_xxxxxx_1, tg_xyzzz_xxxxxxx_0, \
                                         tg_xyzzz_xxxxxxx_1, tg_xyzzz_xxxxxxy_0, tg_xyzzz_xxxxxxy_1, tg_xyzzz_xxxxxxz_0, \
                                         tg_xyzzz_xxxxxxz_1, tg_xyzzz_xxxxxy_1, tg_xyzzz_xxxxxyy_0, tg_xyzzz_xxxxxyy_1, \
                                         tg_xyzzz_xxxxxyz_0, tg_xyzzz_xxxxxyz_1, tg_xyzzz_xxxxxz_1, tg_xyzzz_xxxxxzz_0, \
                                         tg_xyzzz_xxxxxzz_1, tg_xyzzz_xxxxyy_1, tg_xyzzz_xxxxyyy_0, tg_xyzzz_xxxxyyy_1, \
                                         tg_xyzzz_xxxxyyz_0, tg_xyzzz_xxxxyyz_1, tg_xyzzz_xxxxyz_1, tg_xyzzz_xxxxyzz_0, \
                                         tg_xyzzz_xxxxyzz_1, tg_xyzzz_xxxxzz_1, tg_xyzzz_xxxxzzz_0, tg_xyzzz_xxxxzzz_1, \
                                         tg_xyzzz_xxxyyy_1, tg_xyzzz_xxxyyyy_0, tg_xyzzz_xxxyyyy_1, tg_xyzzz_xxxyyyz_0, \
                                         tg_xyzzz_xxxyyyz_1, tg_xyzzz_xxxyyz_1, tg_xyzzz_xxxyyzz_0, tg_xyzzz_xxxyyzz_1, \
                                         tg_xyzzz_xxxyzz_1, tg_xyzzz_xxxyzzz_0, tg_xyzzz_xxxyzzz_1, tg_xyzzz_xxxzzz_1, \
                                         tg_xyzzz_xxxzzzz_0, tg_xyzzz_xxxzzzz_1, tg_xyzzz_xxyyyy_1, tg_xyzzz_xxyyyyy_0, \
                                         tg_xyzzz_xxyyyyy_1, tg_xyzzz_xxyyyyz_0, tg_xyzzz_xxyyyyz_1, tg_xyzzz_xxyyyz_1, \
                                         tg_xyzzz_xxyyyzz_0, tg_xyzzz_xxyyyzz_1, tg_xyzzz_xxyyzz_1, tg_xyzzz_xxyyzzz_0, \
                                         tg_xyzzz_xxyyzzz_1, tg_xyzzz_xxyzzz_1, tg_xyzzz_xxyzzzz_0, tg_xyzzz_xxyzzzz_1, \
                                         tg_xyzzz_xxzzzz_1, tg_xyzzz_xxzzzzz_0, tg_xyzzz_xxzzzzz_1, tg_xyzzz_xyyyyy_1, \
                                         tg_xyzzz_xyyyyyy_0, tg_xyzzz_xyyyyyy_1, tg_xyzzz_xyyyyyz_0, tg_xyzzz_xyyyyyz_1, \
                                         tg_xyzzz_xyyyyz_1, tg_xyzzz_xyyyyzz_0, tg_xyzzz_xyyyyzz_1, tg_xyzzz_xyyyzz_1, \
                                         tg_xyzzz_xyyyzzz_0, tg_xyzzz_xyyyzzz_1, tg_xyzzz_xyyzzz_1, tg_xyzzz_xyyzzzz_0, \
                                         tg_xyzzz_xyyzzzz_1, tg_xyzzz_xyzzzz_1, tg_xyzzz_xyzzzzz_0, tg_xyzzz_xyzzzzz_1, \
                                         tg_xyzzz_xzzzzz_1, tg_xyzzz_xzzzzzz_0, tg_xyzzz_xzzzzzz_1, tg_xyzzz_yyyyyy_1, \
                                         tg_xyzzz_yyyyyyy_0, tg_xyzzz_yyyyyyy_1, tg_xyzzz_yyyyyyz_0, tg_xyzzz_yyyyyyz_1, \
                                         tg_xyzzz_yyyyyz_1, tg_xyzzz_yyyyyzz_0, tg_xyzzz_yyyyyzz_1, tg_xyzzz_yyyyzz_1, \
                                         tg_xyzzz_yyyyzzz_0, tg_xyzzz_yyyyzzz_1, tg_xyzzz_yyyzzz_1, tg_xyzzz_yyyzzzz_0, \
                                         tg_xyzzz_yyyzzzz_1, tg_xyzzz_yyzzzz_1, tg_xyzzz_yyzzzzz_0, tg_xyzzz_yyzzzzz_1, \
                                         tg_xyzzz_yzzzzz_1, tg_xyzzz_yzzzzzz_0, tg_xyzzz_yzzzzzz_1, tg_xyzzz_zzzzzz_1, \
                                         tg_xyzzz_zzzzzzz_0, tg_xyzzz_zzzzzzz_1, tg_xzzzz_xxxxxx_1, tg_xzzzz_xxxxxxx_0, \
                                         tg_xzzzz_xxxxxxx_1, tg_xzzzz_xxxxxxy_0, tg_xzzzz_xxxxxxy_1, tg_xzzzz_xxxxxxz_0, \
                                         tg_xzzzz_xxxxxxz_1, tg_xzzzz_xxxxxy_1, tg_xzzzz_xxxxxyy_0, tg_xzzzz_xxxxxyy_1, \
                                         tg_xzzzz_xxxxxyz_0, tg_xzzzz_xxxxxyz_1, tg_xzzzz_xxxxxz_1, tg_xzzzz_xxxxxzz_0, \
                                         tg_xzzzz_xxxxxzz_1, tg_xzzzz_xxxxyy_1, tg_xzzzz_xxxxyyy_0, tg_xzzzz_xxxxyyy_1, \
                                         tg_xzzzz_xxxxyyz_0, tg_xzzzz_xxxxyyz_1, tg_xzzzz_xxxxyz_1, tg_xzzzz_xxxxyzz_0, \
                                         tg_xzzzz_xxxxyzz_1, tg_xzzzz_xxxxzz_1, tg_xzzzz_xxxxzzz_0, tg_xzzzz_xxxxzzz_1, \
                                         tg_xzzzz_xxxyyy_1, tg_xzzzz_xxxyyyy_0, tg_xzzzz_xxxyyyy_1, tg_xzzzz_xxxyyyz_0, \
                                         tg_xzzzz_xxxyyyz_1, tg_xzzzz_xxxyyz_1, tg_xzzzz_xxxyyzz_0, tg_xzzzz_xxxyyzz_1, \
                                         tg_xzzzz_xxxyzz_1, tg_xzzzz_xxxyzzz_0, tg_xzzzz_xxxyzzz_1, tg_xzzzz_xxxzzz_1, \
                                         tg_xzzzz_xxxzzzz_0, tg_xzzzz_xxxzzzz_1, tg_xzzzz_xxyyyy_1, tg_xzzzz_xxyyyyy_0, \
                                         tg_xzzzz_xxyyyyy_1, tg_xzzzz_xxyyyyz_0, tg_xzzzz_xxyyyyz_1, tg_xzzzz_xxyyyz_1, \
                                         tg_xzzzz_xxyyyzz_0, tg_xzzzz_xxyyyzz_1, tg_xzzzz_xxyyzz_1, tg_xzzzz_xxyyzzz_0, \
                                         tg_xzzzz_xxyyzzz_1, tg_xzzzz_xxyzzz_1, tg_xzzzz_xxyzzzz_0, tg_xzzzz_xxyzzzz_1, \
                                         tg_xzzzz_xxzzzz_1, tg_xzzzz_xxzzzzz_0, tg_xzzzz_xxzzzzz_1, tg_xzzzz_xyyyyy_1, \
                                         tg_xzzzz_xyyyyyy_0, tg_xzzzz_xyyyyyy_1, tg_xzzzz_xyyyyyz_0, tg_xzzzz_xyyyyyz_1, \
                                         tg_xzzzz_xyyyyz_1, tg_xzzzz_xyyyyzz_0, tg_xzzzz_xyyyyzz_1, tg_xzzzz_xyyyzz_1, \
                                         tg_xzzzz_xyyyzzz_0, tg_xzzzz_xyyyzzz_1, tg_xzzzz_xyyzzz_1, tg_xzzzz_xyyzzzz_0, \
                                         tg_xzzzz_xyyzzzz_1, tg_xzzzz_xyzzzz_1, tg_xzzzz_xyzzzzz_0, tg_xzzzz_xyzzzzz_1, \
                                         tg_xzzzz_xzzzzz_1, tg_xzzzz_xzzzzzz_0, tg_xzzzz_xzzzzzz_1, tg_xzzzz_yyyyyy_1, \
                                         tg_xzzzz_yyyyyyy_0, tg_xzzzz_yyyyyyy_1, tg_xzzzz_yyyyyyz_0, tg_xzzzz_yyyyyyz_1, \
                                         tg_xzzzz_yyyyyz_1, tg_xzzzz_yyyyyzz_0, tg_xzzzz_yyyyyzz_1, tg_xzzzz_yyyyzz_1, \
                                         tg_xzzzz_yyyyzzz_0, tg_xzzzz_yyyyzzz_1, tg_xzzzz_yyyzzz_1, tg_xzzzz_yyyzzzz_0, \
                                         tg_xzzzz_yyyzzzz_1, tg_xzzzz_yyzzzz_1, tg_xzzzz_yyzzzzz_0, tg_xzzzz_yyzzzzz_1, \
                                         tg_xzzzz_yzzzzz_1, tg_xzzzz_yzzzzzz_0, tg_xzzzz_yzzzzzz_1, tg_xzzzz_zzzzzz_1, \
                                         tg_xzzzz_zzzzzzz_0, tg_xzzzz_zzzzzzz_1, tg_yyyyy_xxxxxx_1, tg_yyyyy_xxxxxxx_0, \
                                         tg_yyyyy_xxxxxxx_1, tg_yyyyy_xxxxxxy_0, tg_yyyyy_xxxxxxy_1, tg_yyyyy_xxxxxxz_0, \
                                         tg_yyyyy_xxxxxxz_1, tg_yyyyy_xxxxxy_1, tg_yyyyy_xxxxxyy_0, tg_yyyyy_xxxxxyy_1, \
                                         tg_yyyyy_xxxxxyz_0, tg_yyyyy_xxxxxyz_1, tg_yyyyy_xxxxxz_1, tg_yyyyy_xxxxxzz_0, \
                                         tg_yyyyy_xxxxxzz_1, tg_yyyyy_xxxxyy_1, tg_yyyyy_xxxxyyy_0, tg_yyyyy_xxxxyyy_1, \
                                         tg_yyyyy_xxxxyyz_0, tg_yyyyy_xxxxyyz_1, tg_yyyyy_xxxxyz_1, tg_yyyyy_xxxxyzz_0, \
                                         tg_yyyyy_xxxxyzz_1, tg_yyyyy_xxxxzz_1, tg_yyyyy_xxxxzzz_0, tg_yyyyy_xxxxzzz_1, \
                                         tg_yyyyy_xxxyyy_1, tg_yyyyy_xxxyyyy_0, tg_yyyyy_xxxyyyy_1, tg_yyyyy_xxxyyyz_0, \
                                         tg_yyyyy_xxxyyyz_1, tg_yyyyy_xxxyyz_1, tg_yyyyy_xxxyzz_1, tg_yyyyy_xxxzzz_1, \
                                         tg_yyyyy_xxyyyy_1, tg_yyyyy_xxyyyz_1, tg_yyzz_yyyyyyy_0, tg_yyzz_yyyyyyy_1, \
                                         tg_yyzz_yyyyyyz_0, tg_yyzz_yyyyyyz_1, tg_yyzz_yyyyyzz_0, tg_yyzz_yyyyyzz_1, \
                                         tg_yyzz_yyyyzzz_0, tg_yyzz_yyyyzzz_1, tg_yyzz_yyyzzzz_0, tg_yyzz_yyyzzzz_1, \
                                         tg_yyzz_yyzzzzz_0, tg_yyzz_yyzzzzz_1, tg_yyzz_yzzzzzz_0, tg_yyzz_yzzzzzz_1, \
                                         tg_yyzz_zzzzzzz_0, tg_yyzz_zzzzzzz_1, tg_yzzz_xxxxxxx_0, tg_yzzz_xxxxxxx_1, \
                                         tg_yzzz_xxxxxxy_0, tg_yzzz_xxxxxxy_1, tg_yzzz_xxxxxxz_0, tg_yzzz_xxxxxxz_1, \
                                         tg_yzzz_xxxxxyy_0, tg_yzzz_xxxxxyy_1, tg_yzzz_xxxxxyz_0, tg_yzzz_xxxxxyz_1, \
                                         tg_yzzz_xxxxxzz_0, tg_yzzz_xxxxxzz_1, tg_yzzz_xxxxyyy_0, tg_yzzz_xxxxyyy_1, \
                                         tg_yzzz_xxxxyyz_0, tg_yzzz_xxxxyyz_1, tg_yzzz_xxxxyzz_0, tg_yzzz_xxxxyzz_1, \
                                         tg_yzzz_xxxxzzz_0, tg_yzzz_xxxxzzz_1, tg_yzzz_xxxyyyy_0, tg_yzzz_xxxyyyy_1, \
                                         tg_yzzz_xxxyyyz_0, tg_yzzz_xxxyyyz_1, tg_yzzz_xxxyyzz_0, tg_yzzz_xxxyyzz_1, \
                                         tg_yzzz_xxxyzzz_0, tg_yzzz_xxxyzzz_1, tg_yzzz_xxxzzzz_0, tg_yzzz_xxxzzzz_1, \
                                         tg_yzzz_xxyyyyy_0, tg_yzzz_xxyyyyy_1, tg_yzzz_xxyyyyz_0, tg_yzzz_xxyyyyz_1, \
                                         tg_yzzz_xxyyyzz_0, tg_yzzz_xxyyyzz_1, tg_yzzz_xxyyzzz_0, tg_yzzz_xxyyzzz_1, \
                                         tg_yzzz_xxyzzzz_0, tg_yzzz_xxyzzzz_1, tg_yzzz_xxzzzzz_0, tg_yzzz_xxzzzzz_1, \
                                         tg_yzzz_xyyyyyy_0, tg_yzzz_xyyyyyy_1, tg_yzzz_xyyyyyz_0, tg_yzzz_xyyyyyz_1, \
                                         tg_yzzz_xyyyyzz_0, tg_yzzz_xyyyyzz_1, tg_yzzz_xyyyzzz_0, tg_yzzz_xyyyzzz_1, \
                                         tg_yzzz_xyyzzzz_0, tg_yzzz_xyyzzzz_1, tg_yzzz_xyzzzzz_0, tg_yzzz_xyzzzzz_1, \
                                         tg_yzzz_xzzzzzz_0, tg_yzzz_xzzzzzz_1, tg_yzzz_yyyyyyy_0, tg_yzzz_yyyyyyy_1, \
                                         tg_yzzz_yyyyyyz_0, tg_yzzz_yyyyyyz_1, tg_yzzz_yyyyyzz_0, tg_yzzz_yyyyyzz_1, \
                                         tg_yzzz_yyyyzzz_0, tg_yzzz_yyyyzzz_1, tg_yzzz_yyyzzzz_0, tg_yzzz_yyyzzzz_1, \
                                         tg_yzzz_yyzzzzz_0, tg_yzzz_yyzzzzz_1, tg_yzzz_yzzzzzz_0, tg_yzzz_yzzzzzz_1, \
                                         tg_yzzz_zzzzzzz_0, tg_yzzz_zzzzzzz_1, tg_zzzz_xxxxxxx_0, tg_zzzz_xxxxxxx_1, \
                                         tg_zzzz_xxxxxxy_0, tg_zzzz_xxxxxxy_1, tg_zzzz_xxxxxxz_0, tg_zzzz_xxxxxxz_1, \
                                         tg_zzzz_xxxxxyy_0, tg_zzzz_xxxxxyy_1, tg_zzzz_xxxxxyz_0, tg_zzzz_xxxxxyz_1, \
                                         tg_zzzz_xxxxxzz_0, tg_zzzz_xxxxxzz_1, tg_zzzz_xxxxyyy_0, tg_zzzz_xxxxyyy_1, \
                                         tg_zzzz_xxxxyyz_0, tg_zzzz_xxxxyyz_1, tg_zzzz_xxxxyzz_0, tg_zzzz_xxxxyzz_1, \
                                         tg_zzzz_xxxxzzz_0, tg_zzzz_xxxxzzz_1, tg_zzzz_xxxyyyy_0, tg_zzzz_xxxyyyy_1, \
                                         tg_zzzz_xxxyyyz_0, tg_zzzz_xxxyyyz_1, tg_zzzz_xxxyyzz_0, tg_zzzz_xxxyyzz_1, \
                                         tg_zzzz_xxxyzzz_0, tg_zzzz_xxxyzzz_1, tg_zzzz_xxxzzzz_0, tg_zzzz_xxxzzzz_1, \
                                         tg_zzzz_xxyyyyy_0, tg_zzzz_xxyyyyy_1, tg_zzzz_xxyyyyz_0, tg_zzzz_xxyyyyz_1, \
                                         tg_zzzz_xxyyyzz_0, tg_zzzz_xxyyyzz_1, tg_zzzz_xxyyzzz_0, tg_zzzz_xxyyzzz_1, \
                                         tg_zzzz_xxyzzzz_0, tg_zzzz_xxyzzzz_1, tg_zzzz_xxzzzzz_0, tg_zzzz_xxzzzzz_1, \
                                         tg_zzzz_xyyyyyy_0, tg_zzzz_xyyyyyy_1, tg_zzzz_xyyyyyz_0, tg_zzzz_xyyyyyz_1, \
                                         tg_zzzz_xyyyyzz_0, tg_zzzz_xyyyyzz_1, tg_zzzz_xyyyzzz_0, tg_zzzz_xyyyzzz_1, \
                                         tg_zzzz_xyyzzzz_0, tg_zzzz_xyyzzzz_1, tg_zzzz_xyzzzzz_0, tg_zzzz_xyzzzzz_1, \
                                         tg_zzzz_xzzzzzz_0, tg_zzzz_xzzzzzz_1, tg_zzzz_yyyyyyy_0, tg_zzzz_yyyyyyy_1, \
                                         tg_zzzz_yyyyyyz_0, tg_zzzz_yyyyyyz_1, tg_zzzz_yyyyyzz_0, tg_zzzz_yyyyyzz_1, \
                                         tg_zzzz_yyyyzzz_0, tg_zzzz_yyyyzzz_1, tg_zzzz_yyyzzzz_0, tg_zzzz_yyyzzzz_1, \
                                         tg_zzzz_yyzzzzz_0, tg_zzzz_yyzzzzz_1, tg_zzzz_yzzzzzz_0, tg_zzzz_yzzzzzz_1, \
                                         tg_zzzz_zzzzzzz_0, tg_zzzz_zzzzzzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xxyyzz_yyyyyyy_0[j] = pb_x * tg_xyyzz_yyyyyyy_0[j] + fr * tg_xyyzz_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyyyyyy_0[j] - tg_yyzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxyyzz_yyyyyyz_0[j] = pb_x * tg_xyyzz_yyyyyyz_0[j] + fr * tg_xyyzz_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyyyyyz_0[j] - tg_yyzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxyyzz_yyyyyzz_0[j] = pb_x * tg_xyyzz_yyyyyzz_0[j] + fr * tg_xyyzz_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyyyyzz_0[j] - tg_yyzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxyyzz_yyyyzzz_0[j] = pb_x * tg_xyyzz_yyyyzzz_0[j] + fr * tg_xyyzz_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyyyzzz_0[j] - tg_yyzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxyyzz_yyyzzzz_0[j] = pb_x * tg_xyyzz_yyyzzzz_0[j] + fr * tg_xyyzz_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyyzzzz_0[j] - tg_yyzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxyyzz_yyzzzzz_0[j] = pb_x * tg_xyyzz_yyzzzzz_0[j] + fr * tg_xyyzz_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yyzzzzz_0[j] - tg_yyzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxyyzz_yzzzzzz_0[j] = pb_x * tg_xyyzz_yzzzzzz_0[j] + fr * tg_xyyzz_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_yzzzzzz_0[j] - tg_yyzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxyyzz_zzzzzzz_0[j] = pb_x * tg_xyyzz_zzzzzzz_0[j] + fr * tg_xyyzz_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yyzz_zzzzzzz_0[j] - tg_yyzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxyzzz_xxxxxxx_0[j] = pb_x * tg_xyzzz_xxxxxxx_0[j] + fr * tg_xyzzz_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxxx_0[j] - tg_yzzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xyzzz_xxxxxx_1[j];

                    tg_xxyzzz_xxxxxxy_0[j] = pb_x * tg_xyzzz_xxxxxxy_0[j] + fr * tg_xyzzz_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxxy_0[j] - tg_yzzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyzzz_xxxxxy_1[j];

                    tg_xxyzzz_xxxxxxz_0[j] = pb_x * tg_xyzzz_xxxxxxz_0[j] + fr * tg_xyzzz_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxxz_0[j] - tg_yzzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xyzzz_xxxxxz_1[j];

                    tg_xxyzzz_xxxxxyy_0[j] = pb_x * tg_xyzzz_xxxxxyy_0[j] + fr * tg_xyzzz_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxyy_0[j] - tg_yzzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyzzz_xxxxyy_1[j];

                    tg_xxyzzz_xxxxxyz_0[j] = pb_x * tg_xyzzz_xxxxxyz_0[j] + fr * tg_xyzzz_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxyz_0[j] - tg_yzzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyzzz_xxxxyz_1[j];

                    tg_xxyzzz_xxxxxzz_0[j] = pb_x * tg_xyzzz_xxxxxzz_0[j] + fr * tg_xyzzz_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxxzz_0[j] - tg_yzzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xyzzz_xxxxzz_1[j];

                    tg_xxyzzz_xxxxyyy_0[j] = pb_x * tg_xyzzz_xxxxyyy_0[j] + fr * tg_xyzzz_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxyyy_0[j] - tg_yzzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyzzz_xxxyyy_1[j];

                    tg_xxyzzz_xxxxyyz_0[j] = pb_x * tg_xyzzz_xxxxyyz_0[j] + fr * tg_xyzzz_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxyyz_0[j] - tg_yzzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyzzz_xxxyyz_1[j];

                    tg_xxyzzz_xxxxyzz_0[j] = pb_x * tg_xyzzz_xxxxyzz_0[j] + fr * tg_xyzzz_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxyzz_0[j] - tg_yzzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyzzz_xxxyzz_1[j];

                    tg_xxyzzz_xxxxzzz_0[j] = pb_x * tg_xyzzz_xxxxzzz_0[j] + fr * tg_xyzzz_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxxzzz_0[j] - tg_yzzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xyzzz_xxxzzz_1[j];

                    tg_xxyzzz_xxxyyyy_0[j] = pb_x * tg_xyzzz_xxxyyyy_0[j] + fr * tg_xyzzz_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxyyyy_0[j] - tg_yzzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xxyyyy_1[j];

                    tg_xxyzzz_xxxyyyz_0[j] = pb_x * tg_xyzzz_xxxyyyz_0[j] + fr * tg_xyzzz_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxyyyz_0[j] - tg_yzzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xxyyyz_1[j];

                    tg_xxyzzz_xxxyyzz_0[j] = pb_x * tg_xyzzz_xxxyyzz_0[j] + fr * tg_xyzzz_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxyyzz_0[j] - tg_yzzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xxyyzz_1[j];

                    tg_xxyzzz_xxxyzzz_0[j] = pb_x * tg_xyzzz_xxxyzzz_0[j] + fr * tg_xyzzz_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxyzzz_0[j] - tg_yzzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xxyzzz_1[j];

                    tg_xxyzzz_xxxzzzz_0[j] = pb_x * tg_xyzzz_xxxzzzz_0[j] + fr * tg_xyzzz_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxxzzzz_0[j] - tg_yzzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xyzzz_xxzzzz_1[j];

                    tg_xxyzzz_xxyyyyy_0[j] = pb_x * tg_xyzzz_xxyyyyy_0[j] + fr * tg_xyzzz_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxyyyyy_0[j] - tg_yzzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xyyyyy_1[j];

                    tg_xxyzzz_xxyyyyz_0[j] = pb_x * tg_xyzzz_xxyyyyz_0[j] + fr * tg_xyzzz_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxyyyyz_0[j] - tg_yzzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xyyyyz_1[j];

                    tg_xxyzzz_xxyyyzz_0[j] = pb_x * tg_xyzzz_xxyyyzz_0[j] + fr * tg_xyzzz_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxyyyzz_0[j] - tg_yzzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xyyyzz_1[j];

                    tg_xxyzzz_xxyyzzz_0[j] = pb_x * tg_xyzzz_xxyyzzz_0[j] + fr * tg_xyzzz_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxyyzzz_0[j] - tg_yzzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xyyzzz_1[j];

                    tg_xxyzzz_xxyzzzz_0[j] = pb_x * tg_xyzzz_xxyzzzz_0[j] + fr * tg_xyzzz_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxyzzzz_0[j] - tg_yzzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xyzzzz_1[j];

                    tg_xxyzzz_xxzzzzz_0[j] = pb_x * tg_xyzzz_xxzzzzz_0[j] + fr * tg_xyzzz_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xxzzzzz_0[j] - tg_yzzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xyzzz_xzzzzz_1[j];

                    tg_xxyzzz_xyyyyyy_0[j] = pb_x * tg_xyzzz_xyyyyyy_0[j] + fr * tg_xyzzz_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyyyyyy_0[j] - tg_yzzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yyyyyy_1[j];

                    tg_xxyzzz_xyyyyyz_0[j] = pb_x * tg_xyzzz_xyyyyyz_0[j] + fr * tg_xyzzz_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyyyyyz_0[j] - tg_yzzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yyyyyz_1[j];

                    tg_xxyzzz_xyyyyzz_0[j] = pb_x * tg_xyzzz_xyyyyzz_0[j] + fr * tg_xyzzz_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyyyyzz_0[j] - tg_yzzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yyyyzz_1[j];

                    tg_xxyzzz_xyyyzzz_0[j] = pb_x * tg_xyzzz_xyyyzzz_0[j] + fr * tg_xyzzz_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyyyzzz_0[j] - tg_yzzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yyyzzz_1[j];

                    tg_xxyzzz_xyyzzzz_0[j] = pb_x * tg_xyzzz_xyyzzzz_0[j] + fr * tg_xyzzz_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyyzzzz_0[j] - tg_yzzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yyzzzz_1[j];

                    tg_xxyzzz_xyzzzzz_0[j] = pb_x * tg_xyzzz_xyzzzzz_0[j] + fr * tg_xyzzz_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xyzzzzz_0[j] - tg_yzzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_yzzzzz_1[j];

                    tg_xxyzzz_xzzzzzz_0[j] = pb_x * tg_xyzzz_xzzzzzz_0[j] + fr * tg_xyzzz_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_xzzzzzz_0[j] - tg_yzzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xyzzz_zzzzzz_1[j];

                    tg_xxyzzz_yyyyyyy_0[j] = pb_x * tg_xyzzz_yyyyyyy_0[j] + fr * tg_xyzzz_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyyyyyy_0[j] - tg_yzzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxyzzz_yyyyyyz_0[j] = pb_x * tg_xyzzz_yyyyyyz_0[j] + fr * tg_xyzzz_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyyyyyz_0[j] - tg_yzzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxyzzz_yyyyyzz_0[j] = pb_x * tg_xyzzz_yyyyyzz_0[j] + fr * tg_xyzzz_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyyyyzz_0[j] - tg_yzzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxyzzz_yyyyzzz_0[j] = pb_x * tg_xyzzz_yyyyzzz_0[j] + fr * tg_xyzzz_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyyyzzz_0[j] - tg_yzzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxyzzz_yyyzzzz_0[j] = pb_x * tg_xyzzz_yyyzzzz_0[j] + fr * tg_xyzzz_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyyzzzz_0[j] - tg_yzzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxyzzz_yyzzzzz_0[j] = pb_x * tg_xyzzz_yyzzzzz_0[j] + fr * tg_xyzzz_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yyzzzzz_0[j] - tg_yzzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxyzzz_yzzzzzz_0[j] = pb_x * tg_xyzzz_yzzzzzz_0[j] + fr * tg_xyzzz_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_yzzzzzz_0[j] - tg_yzzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxyzzz_zzzzzzz_0[j] = pb_x * tg_xyzzz_zzzzzzz_0[j] + fr * tg_xyzzz_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_yzzz_zzzzzzz_0[j] - tg_yzzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xxzzzz_xxxxxxx_0[j] = pb_x * tg_xzzzz_xxxxxxx_0[j] + fr * tg_xzzzz_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxx_0[j] - tg_zzzz_xxxxxxx_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_xzzzz_xxxxxx_1[j];

                    tg_xxzzzz_xxxxxxy_0[j] = pb_x * tg_xzzzz_xxxxxxy_0[j] + fr * tg_xzzzz_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxy_0[j] - tg_zzzz_xxxxxxy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xzzzz_xxxxxy_1[j];

                    tg_xxzzzz_xxxxxxz_0[j] = pb_x * tg_xzzzz_xxxxxxz_0[j] + fr * tg_xzzzz_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxz_0[j] - tg_zzzz_xxxxxxz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_xzzzz_xxxxxz_1[j];

                    tg_xxzzzz_xxxxxyy_0[j] = pb_x * tg_xzzzz_xxxxxyy_0[j] + fr * tg_xzzzz_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxyy_0[j] - tg_zzzz_xxxxxyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xzzzz_xxxxyy_1[j];

                    tg_xxzzzz_xxxxxyz_0[j] = pb_x * tg_xzzzz_xxxxxyz_0[j] + fr * tg_xzzzz_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxyz_0[j] - tg_zzzz_xxxxxyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xzzzz_xxxxyz_1[j];

                    tg_xxzzzz_xxxxxzz_0[j] = pb_x * tg_xzzzz_xxxxxzz_0[j] + fr * tg_xzzzz_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxzz_0[j] - tg_zzzz_xxxxxzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_xzzzz_xxxxzz_1[j];

                    tg_xxzzzz_xxxxyyy_0[j] = pb_x * tg_xzzzz_xxxxyyy_0[j] + fr * tg_xzzzz_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyyy_0[j] - tg_zzzz_xxxxyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xzzzz_xxxyyy_1[j];

                    tg_xxzzzz_xxxxyyz_0[j] = pb_x * tg_xzzzz_xxxxyyz_0[j] + fr * tg_xzzzz_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyyz_0[j] - tg_zzzz_xxxxyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xzzzz_xxxyyz_1[j];

                    tg_xxzzzz_xxxxyzz_0[j] = pb_x * tg_xzzzz_xxxxyzz_0[j] + fr * tg_xzzzz_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyzz_0[j] - tg_zzzz_xxxxyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xzzzz_xxxyzz_1[j];

                    tg_xxzzzz_xxxxzzz_0[j] = pb_x * tg_xzzzz_xxxxzzz_0[j] + fr * tg_xzzzz_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxzzz_0[j] - tg_zzzz_xxxxzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_xzzzz_xxxzzz_1[j];

                    tg_xxzzzz_xxxyyyy_0[j] = pb_x * tg_xzzzz_xxxyyyy_0[j] + fr * tg_xzzzz_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyyy_0[j] - tg_zzzz_xxxyyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xxyyyy_1[j];

                    tg_xxzzzz_xxxyyyz_0[j] = pb_x * tg_xzzzz_xxxyyyz_0[j] + fr * tg_xzzzz_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyyz_0[j] - tg_zzzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xxyyyz_1[j];

                    tg_xxzzzz_xxxyyzz_0[j] = pb_x * tg_xzzzz_xxxyyzz_0[j] + fr * tg_xzzzz_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyzz_0[j] - tg_zzzz_xxxyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xxyyzz_1[j];

                    tg_xxzzzz_xxxyzzz_0[j] = pb_x * tg_xzzzz_xxxyzzz_0[j] + fr * tg_xzzzz_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyzzz_0[j] - tg_zzzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xxyzzz_1[j];

                    tg_xxzzzz_xxxzzzz_0[j] = pb_x * tg_xzzzz_xxxzzzz_0[j] + fr * tg_xzzzz_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxzzzz_0[j] - tg_zzzz_xxxzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_xzzzz_xxzzzz_1[j];

                    tg_xxzzzz_xxyyyyy_0[j] = pb_x * tg_xzzzz_xxyyyyy_0[j] + fr * tg_xzzzz_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyyy_0[j] - tg_zzzz_xxyyyyy_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xyyyyy_1[j];

                    tg_xxzzzz_xxyyyyz_0[j] = pb_x * tg_xzzzz_xxyyyyz_0[j] + fr * tg_xzzzz_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyyz_0[j] - tg_zzzz_xxyyyyz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xyyyyz_1[j];

                    tg_xxzzzz_xxyyyzz_0[j] = pb_x * tg_xzzzz_xxyyyzz_0[j] + fr * tg_xzzzz_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyzz_0[j] - tg_zzzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xyyyzz_1[j];

                    tg_xxzzzz_xxyyzzz_0[j] = pb_x * tg_xzzzz_xxyyzzz_0[j] + fr * tg_xzzzz_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyzzz_0[j] - tg_zzzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xyyzzz_1[j];

                    tg_xxzzzz_xxyzzzz_0[j] = pb_x * tg_xzzzz_xxyzzzz_0[j] + fr * tg_xzzzz_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyzzzz_0[j] - tg_zzzz_xxyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xyzzzz_1[j];

                    tg_xxzzzz_xxzzzzz_0[j] = pb_x * tg_xzzzz_xxzzzzz_0[j] + fr * tg_xzzzz_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxzzzzz_0[j] - tg_zzzz_xxzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_xzzzz_xzzzzz_1[j];

                    tg_xxzzzz_xyyyyyy_0[j] = pb_x * tg_xzzzz_xyyyyyy_0[j] + fr * tg_xzzzz_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyyy_0[j] - tg_zzzz_xyyyyyy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yyyyyy_1[j];

                    tg_xxzzzz_xyyyyyz_0[j] = pb_x * tg_xzzzz_xyyyyyz_0[j] + fr * tg_xzzzz_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyyz_0[j] - tg_zzzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yyyyyz_1[j];

                    tg_xxzzzz_xyyyyzz_0[j] = pb_x * tg_xzzzz_xyyyyzz_0[j] + fr * tg_xzzzz_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyzz_0[j] - tg_zzzz_xyyyyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yyyyzz_1[j];

                    tg_xxzzzz_xyyyzzz_0[j] = pb_x * tg_xzzzz_xyyyzzz_0[j] + fr * tg_xzzzz_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyzzz_0[j] - tg_zzzz_xyyyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yyyzzz_1[j];

                    tg_xxzzzz_xyyzzzz_0[j] = pb_x * tg_xzzzz_xyyzzzz_0[j] + fr * tg_xzzzz_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyzzzz_0[j] - tg_zzzz_xyyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yyzzzz_1[j];

                    tg_xxzzzz_xyzzzzz_0[j] = pb_x * tg_xzzzz_xyzzzzz_0[j] + fr * tg_xzzzz_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyzzzzz_0[j] - tg_zzzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_yzzzzz_1[j];

                    tg_xxzzzz_xzzzzzz_0[j] = pb_x * tg_xzzzz_xzzzzzz_0[j] + fr * tg_xzzzz_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xzzzzzz_0[j] - tg_zzzz_xzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_xzzzz_zzzzzz_1[j];

                    tg_xxzzzz_yyyyyyy_0[j] = pb_x * tg_xzzzz_yyyyyyy_0[j] + fr * tg_xzzzz_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyyy_0[j] - tg_zzzz_yyyyyyy_1[j] * fl1_fza);

                    tg_xxzzzz_yyyyyyz_0[j] = pb_x * tg_xzzzz_yyyyyyz_0[j] + fr * tg_xzzzz_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyyz_0[j] - tg_zzzz_yyyyyyz_1[j] * fl1_fza);

                    tg_xxzzzz_yyyyyzz_0[j] = pb_x * tg_xzzzz_yyyyyzz_0[j] + fr * tg_xzzzz_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyzz_0[j] - tg_zzzz_yyyyyzz_1[j] * fl1_fza);

                    tg_xxzzzz_yyyyzzz_0[j] = pb_x * tg_xzzzz_yyyyzzz_0[j] + fr * tg_xzzzz_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyzzz_0[j] - tg_zzzz_yyyyzzz_1[j] * fl1_fza);

                    tg_xxzzzz_yyyzzzz_0[j] = pb_x * tg_xzzzz_yyyzzzz_0[j] + fr * tg_xzzzz_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyzzzz_0[j] - tg_zzzz_yyyzzzz_1[j] * fl1_fza);

                    tg_xxzzzz_yyzzzzz_0[j] = pb_x * tg_xzzzz_yyzzzzz_0[j] + fr * tg_xzzzz_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyzzzzz_0[j] - tg_zzzz_yyzzzzz_1[j] * fl1_fza);

                    tg_xxzzzz_yzzzzzz_0[j] = pb_x * tg_xzzzz_yzzzzzz_0[j] + fr * tg_xzzzz_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yzzzzzz_0[j] - tg_zzzz_yzzzzzz_1[j] * fl1_fza);

                    tg_xxzzzz_zzzzzzz_0[j] = pb_x * tg_xzzzz_zzzzzzz_0[j] + fr * tg_xzzzz_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_zzzzzzz_0[j] - tg_zzzz_zzzzzzz_1[j] * fl1_fza);

                    tg_xyyyyy_xxxxxxx_0[j] = pb_x * tg_yyyyy_xxxxxxx_0[j] + fr * tg_yyyyy_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_yyyyy_xxxxxx_1[j];

                    tg_xyyyyy_xxxxxxy_0[j] = pb_x * tg_yyyyy_xxxxxxy_0[j] + fr * tg_yyyyy_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_yyyyy_xxxxxy_1[j];

                    tg_xyyyyy_xxxxxxz_0[j] = pb_x * tg_yyyyy_xxxxxxz_0[j] + fr * tg_yyyyy_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_yyyyy_xxxxxz_1[j];

                    tg_xyyyyy_xxxxxyy_0[j] = pb_x * tg_yyyyy_xxxxxyy_0[j] + fr * tg_yyyyy_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_yyyyy_xxxxyy_1[j];

                    tg_xyyyyy_xxxxxyz_0[j] = pb_x * tg_yyyyy_xxxxxyz_0[j] + fr * tg_yyyyy_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_yyyyy_xxxxyz_1[j];

                    tg_xyyyyy_xxxxxzz_0[j] = pb_x * tg_yyyyy_xxxxxzz_0[j] + fr * tg_yyyyy_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_yyyyy_xxxxzz_1[j];

                    tg_xyyyyy_xxxxyyy_0[j] = pb_x * tg_yyyyy_xxxxyyy_0[j] + fr * tg_yyyyy_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_yyyyy_xxxyyy_1[j];

                    tg_xyyyyy_xxxxyyz_0[j] = pb_x * tg_yyyyy_xxxxyyz_0[j] + fr * tg_yyyyy_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_yyyyy_xxxyyz_1[j];

                    tg_xyyyyy_xxxxyzz_0[j] = pb_x * tg_yyyyy_xxxxyzz_0[j] + fr * tg_yyyyy_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_yyyyy_xxxyzz_1[j];

                    tg_xyyyyy_xxxxzzz_0[j] = pb_x * tg_yyyyy_xxxxzzz_0[j] + fr * tg_yyyyy_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_yyyyy_xxxzzz_1[j];

                    tg_xyyyyy_xxxyyyy_0[j] = pb_x * tg_yyyyy_xxxyyyy_0[j] + fr * tg_yyyyy_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xxyyyy_1[j];

                    tg_xyyyyy_xxxyyyz_0[j] = pb_x * tg_yyyyy_xxxyyyz_0[j] + fr * tg_yyyyy_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xxyyyz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_552_644(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (552,644)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        // set up pointers to common Obara-Saika factors

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrPair]; i < epos[iContrPair]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fxn = osFactors.data(4 * idx);

                // set up distances R(PB) = P - B

                auto pb_x = r_pb_x[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tg_yyyyy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 552); 

                auto tg_yyyyy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 553); 

                auto tg_yyyyy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 554); 

                auto tg_yyyyy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 555); 

                auto tg_yyyyy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 556); 

                auto tg_yyyyy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 557); 

                auto tg_yyyyy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 558); 

                auto tg_yyyyy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 559); 

                auto tg_yyyyy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 560); 

                auto tg_yyyyy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 561); 

                auto tg_yyyyy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 562); 

                auto tg_yyyyy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 563); 

                auto tg_yyyyy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 564); 

                auto tg_yyyyy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 565); 

                auto tg_yyyyy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 566); 

                auto tg_yyyyy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 567); 

                auto tg_yyyyy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 568); 

                auto tg_yyyyy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 569); 

                auto tg_yyyyy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 570); 

                auto tg_yyyyy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 571); 

                auto tg_yyyyy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 572); 

                auto tg_yyyyy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 573); 

                auto tg_yyyyy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 574); 

                auto tg_yyyyy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 575); 

                auto tg_yyyyz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 576); 

                auto tg_yyyyz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 577); 

                auto tg_yyyyz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 578); 

                auto tg_yyyyz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 579); 

                auto tg_yyyyz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 580); 

                auto tg_yyyyz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 581); 

                auto tg_yyyyz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 582); 

                auto tg_yyyyz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 583); 

                auto tg_yyyyz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 584); 

                auto tg_yyyyz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 585); 

                auto tg_yyyyz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 586); 

                auto tg_yyyyz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 587); 

                auto tg_yyyyz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 588); 

                auto tg_yyyyz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 589); 

                auto tg_yyyyz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 590); 

                auto tg_yyyyz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 591); 

                auto tg_yyyyz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 592); 

                auto tg_yyyyz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 593); 

                auto tg_yyyyz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 594); 

                auto tg_yyyyz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 595); 

                auto tg_yyyyz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 596); 

                auto tg_yyyyz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 597); 

                auto tg_yyyyz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 598); 

                auto tg_yyyyz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 599); 

                auto tg_yyyyz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 600); 

                auto tg_yyyyz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 601); 

                auto tg_yyyyz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 602); 

                auto tg_yyyyz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 603); 

                auto tg_yyyyz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 604); 

                auto tg_yyyyz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 605); 

                auto tg_yyyyz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 606); 

                auto tg_yyyyz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 607); 

                auto tg_yyyyz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 608); 

                auto tg_yyyyz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 609); 

                auto tg_yyyyz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 610); 

                auto tg_yyyyz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 611); 

                auto tg_yyyzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 612); 

                auto tg_yyyzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 613); 

                auto tg_yyyzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 614); 

                auto tg_yyyzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 615); 

                auto tg_yyyzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 616); 

                auto tg_yyyzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 617); 

                auto tg_yyyzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 618); 

                auto tg_yyyzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 619); 

                auto tg_yyyzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 620); 

                auto tg_yyyzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 621); 

                auto tg_yyyzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 622); 

                auto tg_yyyzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 623); 

                auto tg_yyyzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 624); 

                auto tg_yyyzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 625); 

                auto tg_yyyzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 626); 

                auto tg_yyyzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 627); 

                auto tg_yyyzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 628); 

                auto tg_yyyzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 629); 

                auto tg_yyyzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 630); 

                auto tg_yyyzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 631); 

                auto tg_yyyzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 632); 

                auto tg_yyyzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 633); 

                auto tg_yyyzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 634); 

                auto tg_yyyzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 635); 

                auto tg_yyyzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 636); 

                auto tg_yyyzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 637); 

                auto tg_yyyzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 638); 

                auto tg_yyyzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 639); 

                auto tg_yyyzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 640); 

                auto tg_yyyzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 641); 

                auto tg_yyyzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 642); 

                auto tg_yyyzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 643); 

                auto tg_yyyyy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 552); 

                auto tg_yyyyy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 553); 

                auto tg_yyyyy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 554); 

                auto tg_yyyyy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 555); 

                auto tg_yyyyy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 556); 

                auto tg_yyyyy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 557); 

                auto tg_yyyyy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 558); 

                auto tg_yyyyy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 559); 

                auto tg_yyyyy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 560); 

                auto tg_yyyyy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 561); 

                auto tg_yyyyy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 562); 

                auto tg_yyyyy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 563); 

                auto tg_yyyyy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 564); 

                auto tg_yyyyy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 565); 

                auto tg_yyyyy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 566); 

                auto tg_yyyyy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 567); 

                auto tg_yyyyy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 568); 

                auto tg_yyyyy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 569); 

                auto tg_yyyyy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 570); 

                auto tg_yyyyy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 571); 

                auto tg_yyyyy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 572); 

                auto tg_yyyyy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 573); 

                auto tg_yyyyy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 574); 

                auto tg_yyyyy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 575); 

                auto tg_yyyyz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 576); 

                auto tg_yyyyz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 577); 

                auto tg_yyyyz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 578); 

                auto tg_yyyyz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 579); 

                auto tg_yyyyz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 580); 

                auto tg_yyyyz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 581); 

                auto tg_yyyyz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 582); 

                auto tg_yyyyz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 583); 

                auto tg_yyyyz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 584); 

                auto tg_yyyyz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 585); 

                auto tg_yyyyz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 586); 

                auto tg_yyyyz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 587); 

                auto tg_yyyyz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 588); 

                auto tg_yyyyz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 589); 

                auto tg_yyyyz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 590); 

                auto tg_yyyyz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 591); 

                auto tg_yyyyz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 592); 

                auto tg_yyyyz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 593); 

                auto tg_yyyyz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 594); 

                auto tg_yyyyz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 595); 

                auto tg_yyyyz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 596); 

                auto tg_yyyyz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 597); 

                auto tg_yyyyz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 598); 

                auto tg_yyyyz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 599); 

                auto tg_yyyyz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 600); 

                auto tg_yyyyz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 601); 

                auto tg_yyyyz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 602); 

                auto tg_yyyyz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 603); 

                auto tg_yyyyz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 604); 

                auto tg_yyyyz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 605); 

                auto tg_yyyyz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 606); 

                auto tg_yyyyz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 607); 

                auto tg_yyyyz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 608); 

                auto tg_yyyyz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 609); 

                auto tg_yyyyz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 610); 

                auto tg_yyyyz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 611); 

                auto tg_yyyzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 612); 

                auto tg_yyyzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 613); 

                auto tg_yyyzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 614); 

                auto tg_yyyzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 615); 

                auto tg_yyyzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 616); 

                auto tg_yyyzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 617); 

                auto tg_yyyzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 618); 

                auto tg_yyyzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 619); 

                auto tg_yyyzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 620); 

                auto tg_yyyzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 621); 

                auto tg_yyyzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 622); 

                auto tg_yyyzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 623); 

                auto tg_yyyzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 624); 

                auto tg_yyyzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 625); 

                auto tg_yyyzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 626); 

                auto tg_yyyzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 627); 

                auto tg_yyyzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 628); 

                auto tg_yyyzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 629); 

                auto tg_yyyzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 630); 

                auto tg_yyyzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 631); 

                auto tg_yyyzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 632); 

                auto tg_yyyzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 633); 

                auto tg_yyyzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 634); 

                auto tg_yyyzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 635); 

                auto tg_yyyzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 636); 

                auto tg_yyyzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 637); 

                auto tg_yyyzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 638); 

                auto tg_yyyzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 639); 

                auto tg_yyyzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 640); 

                auto tg_yyyzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 641); 

                auto tg_yyyzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 642); 

                auto tg_yyyzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 643); 

                auto tg_yyyyy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 432); 

                auto tg_yyyyy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 433); 

                auto tg_yyyyy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 434); 

                auto tg_yyyyy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 435); 

                auto tg_yyyyy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 436); 

                auto tg_yyyyy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 437); 

                auto tg_yyyyy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 438); 

                auto tg_yyyyy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 439); 

                auto tg_yyyyy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 440); 

                auto tg_yyyyy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 441); 

                auto tg_yyyyy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 442); 

                auto tg_yyyyy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 443); 

                auto tg_yyyyy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 444); 

                auto tg_yyyyy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 445); 

                auto tg_yyyyy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 446); 

                auto tg_yyyyy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 447); 

                auto tg_yyyyz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 448); 

                auto tg_yyyyz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 449); 

                auto tg_yyyyz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 450); 

                auto tg_yyyyz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 451); 

                auto tg_yyyyz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 452); 

                auto tg_yyyyz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 453); 

                auto tg_yyyyz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 454); 

                auto tg_yyyyz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 455); 

                auto tg_yyyyz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 456); 

                auto tg_yyyyz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 457); 

                auto tg_yyyyz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 458); 

                auto tg_yyyyz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 459); 

                auto tg_yyyyz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 460); 

                auto tg_yyyyz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 461); 

                auto tg_yyyyz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 462); 

                auto tg_yyyyz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 463); 

                auto tg_yyyyz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 464); 

                auto tg_yyyyz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 465); 

                auto tg_yyyyz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 466); 

                auto tg_yyyyz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 467); 

                auto tg_yyyyz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 468); 

                auto tg_yyyyz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 469); 

                auto tg_yyyyz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 470); 

                auto tg_yyyyz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 471); 

                auto tg_yyyyz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 472); 

                auto tg_yyyyz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 473); 

                auto tg_yyyyz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 474); 

                auto tg_yyyyz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 475); 

                auto tg_yyyzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 476); 

                auto tg_yyyzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 477); 

                auto tg_yyyzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 478); 

                auto tg_yyyzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 479); 

                auto tg_yyyzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 480); 

                auto tg_yyyzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 481); 

                auto tg_yyyzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 482); 

                auto tg_yyyzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 483); 

                auto tg_yyyzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 484); 

                auto tg_yyyzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 485); 

                auto tg_yyyzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 486); 

                auto tg_yyyzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 487); 

                auto tg_yyyzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 488); 

                auto tg_yyyzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 489); 

                auto tg_yyyzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 490); 

                auto tg_yyyzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 491); 

                auto tg_yyyzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 492); 

                auto tg_yyyzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 493); 

                auto tg_yyyzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 494); 

                auto tg_yyyzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 495); 

                auto tg_yyyzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 496); 

                auto tg_yyyzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 497); 

                auto tg_yyyzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 498); 

                auto tg_yyyzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 499); 

                auto tg_yyyzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 500); 

                auto tg_yyyzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 501); 

                auto tg_yyyzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 502); 

                auto tg_yyyzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 503); 

                // set up pointers to integrals

                auto tg_xyyyyy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 552); 

                auto tg_xyyyyy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 553); 

                auto tg_xyyyyy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 554); 

                auto tg_xyyyyy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 555); 

                auto tg_xyyyyy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 556); 

                auto tg_xyyyyy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 557); 

                auto tg_xyyyyy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 558); 

                auto tg_xyyyyy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 559); 

                auto tg_xyyyyy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 560); 

                auto tg_xyyyyy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 561); 

                auto tg_xyyyyy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 562); 

                auto tg_xyyyyy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 563); 

                auto tg_xyyyyy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 564); 

                auto tg_xyyyyy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 565); 

                auto tg_xyyyyy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 566); 

                auto tg_xyyyyy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 567); 

                auto tg_xyyyyy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 568); 

                auto tg_xyyyyy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 569); 

                auto tg_xyyyyy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 570); 

                auto tg_xyyyyy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 571); 

                auto tg_xyyyyy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 572); 

                auto tg_xyyyyy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 573); 

                auto tg_xyyyyy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 574); 

                auto tg_xyyyyy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 575); 

                auto tg_xyyyyz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 576); 

                auto tg_xyyyyz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 577); 

                auto tg_xyyyyz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 578); 

                auto tg_xyyyyz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 579); 

                auto tg_xyyyyz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 580); 

                auto tg_xyyyyz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 581); 

                auto tg_xyyyyz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 582); 

                auto tg_xyyyyz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 583); 

                auto tg_xyyyyz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 584); 

                auto tg_xyyyyz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 585); 

                auto tg_xyyyyz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 586); 

                auto tg_xyyyyz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 587); 

                auto tg_xyyyyz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 588); 

                auto tg_xyyyyz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 589); 

                auto tg_xyyyyz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 590); 

                auto tg_xyyyyz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 591); 

                auto tg_xyyyyz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 592); 

                auto tg_xyyyyz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 593); 

                auto tg_xyyyyz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 594); 

                auto tg_xyyyyz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 595); 

                auto tg_xyyyyz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 596); 

                auto tg_xyyyyz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 597); 

                auto tg_xyyyyz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 598); 

                auto tg_xyyyyz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 599); 

                auto tg_xyyyyz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 600); 

                auto tg_xyyyyz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 601); 

                auto tg_xyyyyz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 602); 

                auto tg_xyyyyz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 603); 

                auto tg_xyyyyz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 604); 

                auto tg_xyyyyz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 605); 

                auto tg_xyyyyz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 606); 

                auto tg_xyyyyz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 607); 

                auto tg_xyyyyz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 608); 

                auto tg_xyyyyz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 609); 

                auto tg_xyyyyz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 610); 

                auto tg_xyyyyz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 611); 

                auto tg_xyyyzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 612); 

                auto tg_xyyyzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 613); 

                auto tg_xyyyzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 614); 

                auto tg_xyyyzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 615); 

                auto tg_xyyyzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 616); 

                auto tg_xyyyzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 617); 

                auto tg_xyyyzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 618); 

                auto tg_xyyyzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 619); 

                auto tg_xyyyzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 620); 

                auto tg_xyyyzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 621); 

                auto tg_xyyyzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 622); 

                auto tg_xyyyzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 623); 

                auto tg_xyyyzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 624); 

                auto tg_xyyyzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 625); 

                auto tg_xyyyzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 626); 

                auto tg_xyyyzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 627); 

                auto tg_xyyyzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 628); 

                auto tg_xyyyzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 629); 

                auto tg_xyyyzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 630); 

                auto tg_xyyyzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 631); 

                auto tg_xyyyzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 632); 

                auto tg_xyyyzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 633); 

                auto tg_xyyyzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 634); 

                auto tg_xyyyzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 635); 

                auto tg_xyyyzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 636); 

                auto tg_xyyyzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 637); 

                auto tg_xyyyzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 638); 

                auto tg_xyyyzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 639); 

                auto tg_xyyyzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 640); 

                auto tg_xyyyzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 641); 

                auto tg_xyyyzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 642); 

                auto tg_xyyyzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 643); 

                // Batch of Integrals (552,644)

                #pragma omp simd aligned(fxn, tg_xyyyyy_xxxyyzz_0, tg_xyyyyy_xxxyzzz_0, tg_xyyyyy_xxxzzzz_0, \
                                         tg_xyyyyy_xxyyyyy_0, tg_xyyyyy_xxyyyyz_0, tg_xyyyyy_xxyyyzz_0, tg_xyyyyy_xxyyzzz_0, \
                                         tg_xyyyyy_xxyzzzz_0, tg_xyyyyy_xxzzzzz_0, tg_xyyyyy_xyyyyyy_0, tg_xyyyyy_xyyyyyz_0, \
                                         tg_xyyyyy_xyyyyzz_0, tg_xyyyyy_xyyyzzz_0, tg_xyyyyy_xyyzzzz_0, tg_xyyyyy_xyzzzzz_0, \
                                         tg_xyyyyy_xzzzzzz_0, tg_xyyyyy_yyyyyyy_0, tg_xyyyyy_yyyyyyz_0, tg_xyyyyy_yyyyyzz_0, \
                                         tg_xyyyyy_yyyyzzz_0, tg_xyyyyy_yyyzzzz_0, tg_xyyyyy_yyzzzzz_0, tg_xyyyyy_yzzzzzz_0, \
                                         tg_xyyyyy_zzzzzzz_0, tg_xyyyyz_xxxxxxx_0, tg_xyyyyz_xxxxxxy_0, tg_xyyyyz_xxxxxxz_0, \
                                         tg_xyyyyz_xxxxxyy_0, tg_xyyyyz_xxxxxyz_0, tg_xyyyyz_xxxxxzz_0, tg_xyyyyz_xxxxyyy_0, \
                                         tg_xyyyyz_xxxxyyz_0, tg_xyyyyz_xxxxyzz_0, tg_xyyyyz_xxxxzzz_0, tg_xyyyyz_xxxyyyy_0, \
                                         tg_xyyyyz_xxxyyyz_0, tg_xyyyyz_xxxyyzz_0, tg_xyyyyz_xxxyzzz_0, tg_xyyyyz_xxxzzzz_0, \
                                         tg_xyyyyz_xxyyyyy_0, tg_xyyyyz_xxyyyyz_0, tg_xyyyyz_xxyyyzz_0, tg_xyyyyz_xxyyzzz_0, \
                                         tg_xyyyyz_xxyzzzz_0, tg_xyyyyz_xxzzzzz_0, tg_xyyyyz_xyyyyyy_0, tg_xyyyyz_xyyyyyz_0, \
                                         tg_xyyyyz_xyyyyzz_0, tg_xyyyyz_xyyyzzz_0, tg_xyyyyz_xyyzzzz_0, tg_xyyyyz_xyzzzzz_0, \
                                         tg_xyyyyz_xzzzzzz_0, tg_xyyyyz_yyyyyyy_0, tg_xyyyyz_yyyyyyz_0, tg_xyyyyz_yyyyyzz_0, \
                                         tg_xyyyyz_yyyyzzz_0, tg_xyyyyz_yyyzzzz_0, tg_xyyyyz_yyzzzzz_0, tg_xyyyyz_yzzzzzz_0, \
                                         tg_xyyyyz_zzzzzzz_0, tg_xyyyzz_xxxxxxx_0, tg_xyyyzz_xxxxxxy_0, tg_xyyyzz_xxxxxxz_0, \
                                         tg_xyyyzz_xxxxxyy_0, tg_xyyyzz_xxxxxyz_0, tg_xyyyzz_xxxxxzz_0, tg_xyyyzz_xxxxyyy_0, \
                                         tg_xyyyzz_xxxxyyz_0, tg_xyyyzz_xxxxyzz_0, tg_xyyyzz_xxxxzzz_0, tg_xyyyzz_xxxyyyy_0, \
                                         tg_xyyyzz_xxxyyyz_0, tg_xyyyzz_xxxyyzz_0, tg_xyyyzz_xxxyzzz_0, tg_xyyyzz_xxxzzzz_0, \
                                         tg_xyyyzz_xxyyyyy_0, tg_xyyyzz_xxyyyyz_0, tg_xyyyzz_xxyyyzz_0, tg_xyyyzz_xxyyzzz_0, \
                                         tg_xyyyzz_xxyzzzz_0, tg_xyyyzz_xxzzzzz_0, tg_xyyyzz_xyyyyyy_0, tg_xyyyzz_xyyyyyz_0, \
                                         tg_xyyyzz_xyyyyzz_0, tg_xyyyzz_xyyyzzz_0, tg_xyyyzz_xyyzzzz_0, tg_xyyyzz_xyzzzzz_0, \
                                         tg_xyyyzz_xzzzzzz_0, tg_xyyyzz_yyyyyyy_0, tg_xyyyzz_yyyyyyz_0, tg_xyyyzz_yyyyyzz_0, \
                                         tg_xyyyzz_yyyyzzz_0, tg_yyyyy_xxxyyzz_0, tg_yyyyy_xxxyyzz_1, tg_yyyyy_xxxyzzz_0, \
                                         tg_yyyyy_xxxyzzz_1, tg_yyyyy_xxxzzzz_0, tg_yyyyy_xxxzzzz_1, tg_yyyyy_xxyyyyy_0, \
                                         tg_yyyyy_xxyyyyy_1, tg_yyyyy_xxyyyyz_0, tg_yyyyy_xxyyyyz_1, tg_yyyyy_xxyyyzz_0, \
                                         tg_yyyyy_xxyyyzz_1, tg_yyyyy_xxyyzz_1, tg_yyyyy_xxyyzzz_0, tg_yyyyy_xxyyzzz_1, \
                                         tg_yyyyy_xxyzzz_1, tg_yyyyy_xxyzzzz_0, tg_yyyyy_xxyzzzz_1, tg_yyyyy_xxzzzz_1, \
                                         tg_yyyyy_xxzzzzz_0, tg_yyyyy_xxzzzzz_1, tg_yyyyy_xyyyyy_1, tg_yyyyy_xyyyyyy_0, \
                                         tg_yyyyy_xyyyyyy_1, tg_yyyyy_xyyyyyz_0, tg_yyyyy_xyyyyyz_1, tg_yyyyy_xyyyyz_1, \
                                         tg_yyyyy_xyyyyzz_0, tg_yyyyy_xyyyyzz_1, tg_yyyyy_xyyyzz_1, tg_yyyyy_xyyyzzz_0, \
                                         tg_yyyyy_xyyyzzz_1, tg_yyyyy_xyyzzz_1, tg_yyyyy_xyyzzzz_0, tg_yyyyy_xyyzzzz_1, \
                                         tg_yyyyy_xyzzzz_1, tg_yyyyy_xyzzzzz_0, tg_yyyyy_xyzzzzz_1, tg_yyyyy_xzzzzz_1, \
                                         tg_yyyyy_xzzzzzz_0, tg_yyyyy_xzzzzzz_1, tg_yyyyy_yyyyyy_1, tg_yyyyy_yyyyyyy_0, \
                                         tg_yyyyy_yyyyyyy_1, tg_yyyyy_yyyyyyz_0, tg_yyyyy_yyyyyyz_1, tg_yyyyy_yyyyyz_1, \
                                         tg_yyyyy_yyyyyzz_0, tg_yyyyy_yyyyyzz_1, tg_yyyyy_yyyyzz_1, tg_yyyyy_yyyyzzz_0, \
                                         tg_yyyyy_yyyyzzz_1, tg_yyyyy_yyyzzz_1, tg_yyyyy_yyyzzzz_0, tg_yyyyy_yyyzzzz_1, \
                                         tg_yyyyy_yyzzzz_1, tg_yyyyy_yyzzzzz_0, tg_yyyyy_yyzzzzz_1, tg_yyyyy_yzzzzz_1, \
                                         tg_yyyyy_yzzzzzz_0, tg_yyyyy_yzzzzzz_1, tg_yyyyy_zzzzzz_1, tg_yyyyy_zzzzzzz_0, \
                                         tg_yyyyy_zzzzzzz_1, tg_yyyyz_xxxxxx_1, tg_yyyyz_xxxxxxx_0, tg_yyyyz_xxxxxxx_1, \
                                         tg_yyyyz_xxxxxxy_0, tg_yyyyz_xxxxxxy_1, tg_yyyyz_xxxxxxz_0, tg_yyyyz_xxxxxxz_1, \
                                         tg_yyyyz_xxxxxy_1, tg_yyyyz_xxxxxyy_0, tg_yyyyz_xxxxxyy_1, tg_yyyyz_xxxxxyz_0, \
                                         tg_yyyyz_xxxxxyz_1, tg_yyyyz_xxxxxz_1, tg_yyyyz_xxxxxzz_0, tg_yyyyz_xxxxxzz_1, \
                                         tg_yyyyz_xxxxyy_1, tg_yyyyz_xxxxyyy_0, tg_yyyyz_xxxxyyy_1, tg_yyyyz_xxxxyyz_0, \
                                         tg_yyyyz_xxxxyyz_1, tg_yyyyz_xxxxyz_1, tg_yyyyz_xxxxyzz_0, tg_yyyyz_xxxxyzz_1, \
                                         tg_yyyyz_xxxxzz_1, tg_yyyyz_xxxxzzz_0, tg_yyyyz_xxxxzzz_1, tg_yyyyz_xxxyyy_1, \
                                         tg_yyyyz_xxxyyyy_0, tg_yyyyz_xxxyyyy_1, tg_yyyyz_xxxyyyz_0, tg_yyyyz_xxxyyyz_1, \
                                         tg_yyyyz_xxxyyz_1, tg_yyyyz_xxxyyzz_0, tg_yyyyz_xxxyyzz_1, tg_yyyyz_xxxyzz_1, \
                                         tg_yyyyz_xxxyzzz_0, tg_yyyyz_xxxyzzz_1, tg_yyyyz_xxxzzz_1, tg_yyyyz_xxxzzzz_0, \
                                         tg_yyyyz_xxxzzzz_1, tg_yyyyz_xxyyyy_1, tg_yyyyz_xxyyyyy_0, tg_yyyyz_xxyyyyy_1, \
                                         tg_yyyyz_xxyyyyz_0, tg_yyyyz_xxyyyyz_1, tg_yyyyz_xxyyyz_1, tg_yyyyz_xxyyyzz_0, \
                                         tg_yyyyz_xxyyyzz_1, tg_yyyyz_xxyyzz_1, tg_yyyyz_xxyyzzz_0, tg_yyyyz_xxyyzzz_1, \
                                         tg_yyyyz_xxyzzz_1, tg_yyyyz_xxyzzzz_0, tg_yyyyz_xxyzzzz_1, tg_yyyyz_xxzzzz_1, \
                                         tg_yyyyz_xxzzzzz_0, tg_yyyyz_xxzzzzz_1, tg_yyyyz_xyyyyy_1, tg_yyyyz_xyyyyyy_0, \
                                         tg_yyyyz_xyyyyyy_1, tg_yyyyz_xyyyyyz_0, tg_yyyyz_xyyyyyz_1, tg_yyyyz_xyyyyz_1, \
                                         tg_yyyyz_xyyyyzz_0, tg_yyyyz_xyyyyzz_1, tg_yyyyz_xyyyzz_1, tg_yyyyz_xyyyzzz_0, \
                                         tg_yyyyz_xyyyzzz_1, tg_yyyyz_xyyzzz_1, tg_yyyyz_xyyzzzz_0, tg_yyyyz_xyyzzzz_1, \
                                         tg_yyyyz_xyzzzz_1, tg_yyyyz_xyzzzzz_0, tg_yyyyz_xyzzzzz_1, tg_yyyyz_xzzzzz_1, \
                                         tg_yyyyz_xzzzzzz_0, tg_yyyyz_xzzzzzz_1, tg_yyyyz_yyyyyy_1, tg_yyyyz_yyyyyyy_0, \
                                         tg_yyyyz_yyyyyyy_1, tg_yyyyz_yyyyyyz_0, tg_yyyyz_yyyyyyz_1, tg_yyyyz_yyyyyz_1, \
                                         tg_yyyyz_yyyyyzz_0, tg_yyyyz_yyyyyzz_1, tg_yyyyz_yyyyzz_1, tg_yyyyz_yyyyzzz_0, \
                                         tg_yyyyz_yyyyzzz_1, tg_yyyyz_yyyzzz_1, tg_yyyyz_yyyzzzz_0, tg_yyyyz_yyyzzzz_1, \
                                         tg_yyyyz_yyzzzz_1, tg_yyyyz_yyzzzzz_0, tg_yyyyz_yyzzzzz_1, tg_yyyyz_yzzzzz_1, \
                                         tg_yyyyz_yzzzzzz_0, tg_yyyyz_yzzzzzz_1, tg_yyyyz_zzzzzz_1, tg_yyyyz_zzzzzzz_0, \
                                         tg_yyyyz_zzzzzzz_1, tg_yyyzz_xxxxxx_1, tg_yyyzz_xxxxxxx_0, tg_yyyzz_xxxxxxx_1, \
                                         tg_yyyzz_xxxxxxy_0, tg_yyyzz_xxxxxxy_1, tg_yyyzz_xxxxxxz_0, tg_yyyzz_xxxxxxz_1, \
                                         tg_yyyzz_xxxxxy_1, tg_yyyzz_xxxxxyy_0, tg_yyyzz_xxxxxyy_1, tg_yyyzz_xxxxxyz_0, \
                                         tg_yyyzz_xxxxxyz_1, tg_yyyzz_xxxxxz_1, tg_yyyzz_xxxxxzz_0, tg_yyyzz_xxxxxzz_1, \
                                         tg_yyyzz_xxxxyy_1, tg_yyyzz_xxxxyyy_0, tg_yyyzz_xxxxyyy_1, tg_yyyzz_xxxxyyz_0, \
                                         tg_yyyzz_xxxxyyz_1, tg_yyyzz_xxxxyz_1, tg_yyyzz_xxxxyzz_0, tg_yyyzz_xxxxyzz_1, \
                                         tg_yyyzz_xxxxzz_1, tg_yyyzz_xxxxzzz_0, tg_yyyzz_xxxxzzz_1, tg_yyyzz_xxxyyy_1, \
                                         tg_yyyzz_xxxyyyy_0, tg_yyyzz_xxxyyyy_1, tg_yyyzz_xxxyyyz_0, tg_yyyzz_xxxyyyz_1, \
                                         tg_yyyzz_xxxyyz_1, tg_yyyzz_xxxyyzz_0, tg_yyyzz_xxxyyzz_1, tg_yyyzz_xxxyzz_1, \
                                         tg_yyyzz_xxxyzzz_0, tg_yyyzz_xxxyzzz_1, tg_yyyzz_xxxzzz_1, tg_yyyzz_xxxzzzz_0, \
                                         tg_yyyzz_xxxzzzz_1, tg_yyyzz_xxyyyy_1, tg_yyyzz_xxyyyyy_0, tg_yyyzz_xxyyyyy_1, \
                                         tg_yyyzz_xxyyyyz_0, tg_yyyzz_xxyyyyz_1, tg_yyyzz_xxyyyz_1, tg_yyyzz_xxyyyzz_0, \
                                         tg_yyyzz_xxyyyzz_1, tg_yyyzz_xxyyzz_1, tg_yyyzz_xxyyzzz_0, tg_yyyzz_xxyyzzz_1, \
                                         tg_yyyzz_xxyzzz_1, tg_yyyzz_xxyzzzz_0, tg_yyyzz_xxyzzzz_1, tg_yyyzz_xxzzzz_1, \
                                         tg_yyyzz_xxzzzzz_0, tg_yyyzz_xxzzzzz_1, tg_yyyzz_xyyyyy_1, tg_yyyzz_xyyyyyy_0, \
                                         tg_yyyzz_xyyyyyy_1, tg_yyyzz_xyyyyyz_0, tg_yyyzz_xyyyyyz_1, tg_yyyzz_xyyyyz_1, \
                                         tg_yyyzz_xyyyyzz_0, tg_yyyzz_xyyyyzz_1, tg_yyyzz_xyyyzz_1, tg_yyyzz_xyyyzzz_0, \
                                         tg_yyyzz_xyyyzzz_1, tg_yyyzz_xyyzzz_1, tg_yyyzz_xyyzzzz_0, tg_yyyzz_xyyzzzz_1, \
                                         tg_yyyzz_xyzzzz_1, tg_yyyzz_xyzzzzz_0, tg_yyyzz_xyzzzzz_1, tg_yyyzz_xzzzzz_1, \
                                         tg_yyyzz_xzzzzzz_0, tg_yyyzz_xzzzzzz_1, tg_yyyzz_yyyyyy_1, tg_yyyzz_yyyyyyy_0, \
                                         tg_yyyzz_yyyyyyy_1, tg_yyyzz_yyyyyyz_0, tg_yyyzz_yyyyyyz_1, tg_yyyzz_yyyyyz_1, \
                                         tg_yyyzz_yyyyyzz_0, tg_yyyzz_yyyyyzz_1, tg_yyyzz_yyyyzz_1, tg_yyyzz_yyyyzzz_0, \
                                         tg_yyyzz_yyyyzzz_1, tg_yyyzz_yyyzzz_1, tg_yyyzz_yyzzzz_1, tg_yyyzz_yzzzzz_1, \
                                         tg_yyyzz_zzzzzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fxn = fxn[j];

                    double fr = wp_x[j]; 

                    tg_xyyyyy_xxxyyzz_0[j] = pb_x * tg_yyyyy_xxxyyzz_0[j] + fr * tg_yyyyy_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xxyyzz_1[j];

                    tg_xyyyyy_xxxyzzz_0[j] = pb_x * tg_yyyyy_xxxyzzz_0[j] + fr * tg_yyyyy_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xxyzzz_1[j];

                    tg_xyyyyy_xxxzzzz_0[j] = pb_x * tg_yyyyy_xxxzzzz_0[j] + fr * tg_yyyyy_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_yyyyy_xxzzzz_1[j];

                    tg_xyyyyy_xxyyyyy_0[j] = pb_x * tg_yyyyy_xxyyyyy_0[j] + fr * tg_yyyyy_xxyyyyy_1[j] + fl1_fxn * tg_yyyyy_xyyyyy_1[j];

                    tg_xyyyyy_xxyyyyz_0[j] = pb_x * tg_yyyyy_xxyyyyz_0[j] + fr * tg_yyyyy_xxyyyyz_1[j] + fl1_fxn * tg_yyyyy_xyyyyz_1[j];

                    tg_xyyyyy_xxyyyzz_0[j] = pb_x * tg_yyyyy_xxyyyzz_0[j] + fr * tg_yyyyy_xxyyyzz_1[j] + fl1_fxn * tg_yyyyy_xyyyzz_1[j];

                    tg_xyyyyy_xxyyzzz_0[j] = pb_x * tg_yyyyy_xxyyzzz_0[j] + fr * tg_yyyyy_xxyyzzz_1[j] + fl1_fxn * tg_yyyyy_xyyzzz_1[j];

                    tg_xyyyyy_xxyzzzz_0[j] = pb_x * tg_yyyyy_xxyzzzz_0[j] + fr * tg_yyyyy_xxyzzzz_1[j] + fl1_fxn * tg_yyyyy_xyzzzz_1[j];

                    tg_xyyyyy_xxzzzzz_0[j] = pb_x * tg_yyyyy_xxzzzzz_0[j] + fr * tg_yyyyy_xxzzzzz_1[j] + fl1_fxn * tg_yyyyy_xzzzzz_1[j];

                    tg_xyyyyy_xyyyyyy_0[j] = pb_x * tg_yyyyy_xyyyyyy_0[j] + fr * tg_yyyyy_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yyyyyy_1[j];

                    tg_xyyyyy_xyyyyyz_0[j] = pb_x * tg_yyyyy_xyyyyyz_0[j] + fr * tg_yyyyy_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yyyyyz_1[j];

                    tg_xyyyyy_xyyyyzz_0[j] = pb_x * tg_yyyyy_xyyyyzz_0[j] + fr * tg_yyyyy_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yyyyzz_1[j];

                    tg_xyyyyy_xyyyzzz_0[j] = pb_x * tg_yyyyy_xyyyzzz_0[j] + fr * tg_yyyyy_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yyyzzz_1[j];

                    tg_xyyyyy_xyyzzzz_0[j] = pb_x * tg_yyyyy_xyyzzzz_0[j] + fr * tg_yyyyy_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yyzzzz_1[j];

                    tg_xyyyyy_xyzzzzz_0[j] = pb_x * tg_yyyyy_xyzzzzz_0[j] + fr * tg_yyyyy_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_yzzzzz_1[j];

                    tg_xyyyyy_xzzzzzz_0[j] = pb_x * tg_yyyyy_xzzzzzz_0[j] + fr * tg_yyyyy_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyy_zzzzzz_1[j];

                    tg_xyyyyy_yyyyyyy_0[j] = pb_x * tg_yyyyy_yyyyyyy_0[j] + fr * tg_yyyyy_yyyyyyy_1[j];

                    tg_xyyyyy_yyyyyyz_0[j] = pb_x * tg_yyyyy_yyyyyyz_0[j] + fr * tg_yyyyy_yyyyyyz_1[j];

                    tg_xyyyyy_yyyyyzz_0[j] = pb_x * tg_yyyyy_yyyyyzz_0[j] + fr * tg_yyyyy_yyyyyzz_1[j];

                    tg_xyyyyy_yyyyzzz_0[j] = pb_x * tg_yyyyy_yyyyzzz_0[j] + fr * tg_yyyyy_yyyyzzz_1[j];

                    tg_xyyyyy_yyyzzzz_0[j] = pb_x * tg_yyyyy_yyyzzzz_0[j] + fr * tg_yyyyy_yyyzzzz_1[j];

                    tg_xyyyyy_yyzzzzz_0[j] = pb_x * tg_yyyyy_yyzzzzz_0[j] + fr * tg_yyyyy_yyzzzzz_1[j];

                    tg_xyyyyy_yzzzzzz_0[j] = pb_x * tg_yyyyy_yzzzzzz_0[j] + fr * tg_yyyyy_yzzzzzz_1[j];

                    tg_xyyyyy_zzzzzzz_0[j] = pb_x * tg_yyyyy_zzzzzzz_0[j] + fr * tg_yyyyy_zzzzzzz_1[j];

                    tg_xyyyyz_xxxxxxx_0[j] = pb_x * tg_yyyyz_xxxxxxx_0[j] + fr * tg_yyyyz_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_yyyyz_xxxxxx_1[j];

                    tg_xyyyyz_xxxxxxy_0[j] = pb_x * tg_yyyyz_xxxxxxy_0[j] + fr * tg_yyyyz_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_yyyyz_xxxxxy_1[j];

                    tg_xyyyyz_xxxxxxz_0[j] = pb_x * tg_yyyyz_xxxxxxz_0[j] + fr * tg_yyyyz_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_yyyyz_xxxxxz_1[j];

                    tg_xyyyyz_xxxxxyy_0[j] = pb_x * tg_yyyyz_xxxxxyy_0[j] + fr * tg_yyyyz_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_yyyyz_xxxxyy_1[j];

                    tg_xyyyyz_xxxxxyz_0[j] = pb_x * tg_yyyyz_xxxxxyz_0[j] + fr * tg_yyyyz_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_yyyyz_xxxxyz_1[j];

                    tg_xyyyyz_xxxxxzz_0[j] = pb_x * tg_yyyyz_xxxxxzz_0[j] + fr * tg_yyyyz_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_yyyyz_xxxxzz_1[j];

                    tg_xyyyyz_xxxxyyy_0[j] = pb_x * tg_yyyyz_xxxxyyy_0[j] + fr * tg_yyyyz_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_yyyyz_xxxyyy_1[j];

                    tg_xyyyyz_xxxxyyz_0[j] = pb_x * tg_yyyyz_xxxxyyz_0[j] + fr * tg_yyyyz_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_yyyyz_xxxyyz_1[j];

                    tg_xyyyyz_xxxxyzz_0[j] = pb_x * tg_yyyyz_xxxxyzz_0[j] + fr * tg_yyyyz_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_yyyyz_xxxyzz_1[j];

                    tg_xyyyyz_xxxxzzz_0[j] = pb_x * tg_yyyyz_xxxxzzz_0[j] + fr * tg_yyyyz_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_yyyyz_xxxzzz_1[j];

                    tg_xyyyyz_xxxyyyy_0[j] = pb_x * tg_yyyyz_xxxyyyy_0[j] + fr * tg_yyyyz_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xxyyyy_1[j];

                    tg_xyyyyz_xxxyyyz_0[j] = pb_x * tg_yyyyz_xxxyyyz_0[j] + fr * tg_yyyyz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xxyyyz_1[j];

                    tg_xyyyyz_xxxyyzz_0[j] = pb_x * tg_yyyyz_xxxyyzz_0[j] + fr * tg_yyyyz_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xxyyzz_1[j];

                    tg_xyyyyz_xxxyzzz_0[j] = pb_x * tg_yyyyz_xxxyzzz_0[j] + fr * tg_yyyyz_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xxyzzz_1[j];

                    tg_xyyyyz_xxxzzzz_0[j] = pb_x * tg_yyyyz_xxxzzzz_0[j] + fr * tg_yyyyz_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_yyyyz_xxzzzz_1[j];

                    tg_xyyyyz_xxyyyyy_0[j] = pb_x * tg_yyyyz_xxyyyyy_0[j] + fr * tg_yyyyz_xxyyyyy_1[j] + fl1_fxn * tg_yyyyz_xyyyyy_1[j];

                    tg_xyyyyz_xxyyyyz_0[j] = pb_x * tg_yyyyz_xxyyyyz_0[j] + fr * tg_yyyyz_xxyyyyz_1[j] + fl1_fxn * tg_yyyyz_xyyyyz_1[j];

                    tg_xyyyyz_xxyyyzz_0[j] = pb_x * tg_yyyyz_xxyyyzz_0[j] + fr * tg_yyyyz_xxyyyzz_1[j] + fl1_fxn * tg_yyyyz_xyyyzz_1[j];

                    tg_xyyyyz_xxyyzzz_0[j] = pb_x * tg_yyyyz_xxyyzzz_0[j] + fr * tg_yyyyz_xxyyzzz_1[j] + fl1_fxn * tg_yyyyz_xyyzzz_1[j];

                    tg_xyyyyz_xxyzzzz_0[j] = pb_x * tg_yyyyz_xxyzzzz_0[j] + fr * tg_yyyyz_xxyzzzz_1[j] + fl1_fxn * tg_yyyyz_xyzzzz_1[j];

                    tg_xyyyyz_xxzzzzz_0[j] = pb_x * tg_yyyyz_xxzzzzz_0[j] + fr * tg_yyyyz_xxzzzzz_1[j] + fl1_fxn * tg_yyyyz_xzzzzz_1[j];

                    tg_xyyyyz_xyyyyyy_0[j] = pb_x * tg_yyyyz_xyyyyyy_0[j] + fr * tg_yyyyz_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yyyyyy_1[j];

                    tg_xyyyyz_xyyyyyz_0[j] = pb_x * tg_yyyyz_xyyyyyz_0[j] + fr * tg_yyyyz_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yyyyyz_1[j];

                    tg_xyyyyz_xyyyyzz_0[j] = pb_x * tg_yyyyz_xyyyyzz_0[j] + fr * tg_yyyyz_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yyyyzz_1[j];

                    tg_xyyyyz_xyyyzzz_0[j] = pb_x * tg_yyyyz_xyyyzzz_0[j] + fr * tg_yyyyz_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yyyzzz_1[j];

                    tg_xyyyyz_xyyzzzz_0[j] = pb_x * tg_yyyyz_xyyzzzz_0[j] + fr * tg_yyyyz_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yyzzzz_1[j];

                    tg_xyyyyz_xyzzzzz_0[j] = pb_x * tg_yyyyz_xyzzzzz_0[j] + fr * tg_yyyyz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_yzzzzz_1[j];

                    tg_xyyyyz_xzzzzzz_0[j] = pb_x * tg_yyyyz_xzzzzzz_0[j] + fr * tg_yyyyz_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyyz_zzzzzz_1[j];

                    tg_xyyyyz_yyyyyyy_0[j] = pb_x * tg_yyyyz_yyyyyyy_0[j] + fr * tg_yyyyz_yyyyyyy_1[j];

                    tg_xyyyyz_yyyyyyz_0[j] = pb_x * tg_yyyyz_yyyyyyz_0[j] + fr * tg_yyyyz_yyyyyyz_1[j];

                    tg_xyyyyz_yyyyyzz_0[j] = pb_x * tg_yyyyz_yyyyyzz_0[j] + fr * tg_yyyyz_yyyyyzz_1[j];

                    tg_xyyyyz_yyyyzzz_0[j] = pb_x * tg_yyyyz_yyyyzzz_0[j] + fr * tg_yyyyz_yyyyzzz_1[j];

                    tg_xyyyyz_yyyzzzz_0[j] = pb_x * tg_yyyyz_yyyzzzz_0[j] + fr * tg_yyyyz_yyyzzzz_1[j];

                    tg_xyyyyz_yyzzzzz_0[j] = pb_x * tg_yyyyz_yyzzzzz_0[j] + fr * tg_yyyyz_yyzzzzz_1[j];

                    tg_xyyyyz_yzzzzzz_0[j] = pb_x * tg_yyyyz_yzzzzzz_0[j] + fr * tg_yyyyz_yzzzzzz_1[j];

                    tg_xyyyyz_zzzzzzz_0[j] = pb_x * tg_yyyyz_zzzzzzz_0[j] + fr * tg_yyyyz_zzzzzzz_1[j];

                    tg_xyyyzz_xxxxxxx_0[j] = pb_x * tg_yyyzz_xxxxxxx_0[j] + fr * tg_yyyzz_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_yyyzz_xxxxxx_1[j];

                    tg_xyyyzz_xxxxxxy_0[j] = pb_x * tg_yyyzz_xxxxxxy_0[j] + fr * tg_yyyzz_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_yyyzz_xxxxxy_1[j];

                    tg_xyyyzz_xxxxxxz_0[j] = pb_x * tg_yyyzz_xxxxxxz_0[j] + fr * tg_yyyzz_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_yyyzz_xxxxxz_1[j];

                    tg_xyyyzz_xxxxxyy_0[j] = pb_x * tg_yyyzz_xxxxxyy_0[j] + fr * tg_yyyzz_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_yyyzz_xxxxyy_1[j];

                    tg_xyyyzz_xxxxxyz_0[j] = pb_x * tg_yyyzz_xxxxxyz_0[j] + fr * tg_yyyzz_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_yyyzz_xxxxyz_1[j];

                    tg_xyyyzz_xxxxxzz_0[j] = pb_x * tg_yyyzz_xxxxxzz_0[j] + fr * tg_yyyzz_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_yyyzz_xxxxzz_1[j];

                    tg_xyyyzz_xxxxyyy_0[j] = pb_x * tg_yyyzz_xxxxyyy_0[j] + fr * tg_yyyzz_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_yyyzz_xxxyyy_1[j];

                    tg_xyyyzz_xxxxyyz_0[j] = pb_x * tg_yyyzz_xxxxyyz_0[j] + fr * tg_yyyzz_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_yyyzz_xxxyyz_1[j];

                    tg_xyyyzz_xxxxyzz_0[j] = pb_x * tg_yyyzz_xxxxyzz_0[j] + fr * tg_yyyzz_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_yyyzz_xxxyzz_1[j];

                    tg_xyyyzz_xxxxzzz_0[j] = pb_x * tg_yyyzz_xxxxzzz_0[j] + fr * tg_yyyzz_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_yyyzz_xxxzzz_1[j];

                    tg_xyyyzz_xxxyyyy_0[j] = pb_x * tg_yyyzz_xxxyyyy_0[j] + fr * tg_yyyzz_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xxyyyy_1[j];

                    tg_xyyyzz_xxxyyyz_0[j] = pb_x * tg_yyyzz_xxxyyyz_0[j] + fr * tg_yyyzz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xxyyyz_1[j];

                    tg_xyyyzz_xxxyyzz_0[j] = pb_x * tg_yyyzz_xxxyyzz_0[j] + fr * tg_yyyzz_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xxyyzz_1[j];

                    tg_xyyyzz_xxxyzzz_0[j] = pb_x * tg_yyyzz_xxxyzzz_0[j] + fr * tg_yyyzz_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xxyzzz_1[j];

                    tg_xyyyzz_xxxzzzz_0[j] = pb_x * tg_yyyzz_xxxzzzz_0[j] + fr * tg_yyyzz_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_yyyzz_xxzzzz_1[j];

                    tg_xyyyzz_xxyyyyy_0[j] = pb_x * tg_yyyzz_xxyyyyy_0[j] + fr * tg_yyyzz_xxyyyyy_1[j] + fl1_fxn * tg_yyyzz_xyyyyy_1[j];

                    tg_xyyyzz_xxyyyyz_0[j] = pb_x * tg_yyyzz_xxyyyyz_0[j] + fr * tg_yyyzz_xxyyyyz_1[j] + fl1_fxn * tg_yyyzz_xyyyyz_1[j];

                    tg_xyyyzz_xxyyyzz_0[j] = pb_x * tg_yyyzz_xxyyyzz_0[j] + fr * tg_yyyzz_xxyyyzz_1[j] + fl1_fxn * tg_yyyzz_xyyyzz_1[j];

                    tg_xyyyzz_xxyyzzz_0[j] = pb_x * tg_yyyzz_xxyyzzz_0[j] + fr * tg_yyyzz_xxyyzzz_1[j] + fl1_fxn * tg_yyyzz_xyyzzz_1[j];

                    tg_xyyyzz_xxyzzzz_0[j] = pb_x * tg_yyyzz_xxyzzzz_0[j] + fr * tg_yyyzz_xxyzzzz_1[j] + fl1_fxn * tg_yyyzz_xyzzzz_1[j];

                    tg_xyyyzz_xxzzzzz_0[j] = pb_x * tg_yyyzz_xxzzzzz_0[j] + fr * tg_yyyzz_xxzzzzz_1[j] + fl1_fxn * tg_yyyzz_xzzzzz_1[j];

                    tg_xyyyzz_xyyyyyy_0[j] = pb_x * tg_yyyzz_xyyyyyy_0[j] + fr * tg_yyyzz_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yyyyyy_1[j];

                    tg_xyyyzz_xyyyyyz_0[j] = pb_x * tg_yyyzz_xyyyyyz_0[j] + fr * tg_yyyzz_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yyyyyz_1[j];

                    tg_xyyyzz_xyyyyzz_0[j] = pb_x * tg_yyyzz_xyyyyzz_0[j] + fr * tg_yyyzz_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yyyyzz_1[j];

                    tg_xyyyzz_xyyyzzz_0[j] = pb_x * tg_yyyzz_xyyyzzz_0[j] + fr * tg_yyyzz_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yyyzzz_1[j];

                    tg_xyyyzz_xyyzzzz_0[j] = pb_x * tg_yyyzz_xyyzzzz_0[j] + fr * tg_yyyzz_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yyzzzz_1[j];

                    tg_xyyyzz_xyzzzzz_0[j] = pb_x * tg_yyyzz_xyzzzzz_0[j] + fr * tg_yyyzz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_yzzzzz_1[j];

                    tg_xyyyzz_xzzzzzz_0[j] = pb_x * tg_yyyzz_xzzzzzz_0[j] + fr * tg_yyyzz_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyyzz_zzzzzz_1[j];

                    tg_xyyyzz_yyyyyyy_0[j] = pb_x * tg_yyyzz_yyyyyyy_0[j] + fr * tg_yyyzz_yyyyyyy_1[j];

                    tg_xyyyzz_yyyyyyz_0[j] = pb_x * tg_yyyzz_yyyyyyz_0[j] + fr * tg_yyyzz_yyyyyyz_1[j];

                    tg_xyyyzz_yyyyyzz_0[j] = pb_x * tg_yyyzz_yyyyyzz_0[j] + fr * tg_yyyzz_yyyyyzz_1[j];

                    tg_xyyyzz_yyyyzzz_0[j] = pb_x * tg_yyyzz_yyyyzzz_0[j] + fr * tg_yyyzz_yyyyzzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_644_735(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (644,735)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        // set up pointers to common Obara-Saika factors

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            // loop over contracted GTO on bra side

            int32_t idx = 0;

            for (int32_t i = spos[iContrPair]; i < epos[iContrPair]; i++)
            {
                // set up pointers to Obara-Saika factors

                auto fxn = osFactors.data(4 * idx);

                // set up distances R(PB) = P - B

                auto pb_x = r_pb_x[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                // set up pointers to auxilary integrals

                auto tg_yyyzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 644); 

                auto tg_yyyzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 645); 

                auto tg_yyyzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 646); 

                auto tg_yyyzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 647); 

                auto tg_yyzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 648); 

                auto tg_yyzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 649); 

                auto tg_yyzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 650); 

                auto tg_yyzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 651); 

                auto tg_yyzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 652); 

                auto tg_yyzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 653); 

                auto tg_yyzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 654); 

                auto tg_yyzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 655); 

                auto tg_yyzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 656); 

                auto tg_yyzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 657); 

                auto tg_yyzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 658); 

                auto tg_yyzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 659); 

                auto tg_yyzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 660); 

                auto tg_yyzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 661); 

                auto tg_yyzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 662); 

                auto tg_yyzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 663); 

                auto tg_yyzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 664); 

                auto tg_yyzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 665); 

                auto tg_yyzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 666); 

                auto tg_yyzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 667); 

                auto tg_yyzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 668); 

                auto tg_yyzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 669); 

                auto tg_yyzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 670); 

                auto tg_yyzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 671); 

                auto tg_yyzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 672); 

                auto tg_yyzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 673); 

                auto tg_yyzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 674); 

                auto tg_yyzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 675); 

                auto tg_yyzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 676); 

                auto tg_yyzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 677); 

                auto tg_yyzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 678); 

                auto tg_yyzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 679); 

                auto tg_yyzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 680); 

                auto tg_yyzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 681); 

                auto tg_yyzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 682); 

                auto tg_yyzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 683); 

                auto tg_yzzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 684); 

                auto tg_yzzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 685); 

                auto tg_yzzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 686); 

                auto tg_yzzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 687); 

                auto tg_yzzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 688); 

                auto tg_yzzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 689); 

                auto tg_yzzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 690); 

                auto tg_yzzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 691); 

                auto tg_yzzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 692); 

                auto tg_yzzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 693); 

                auto tg_yzzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 694); 

                auto tg_yzzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 695); 

                auto tg_yzzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 696); 

                auto tg_yzzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 697); 

                auto tg_yzzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 698); 

                auto tg_yzzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 699); 

                auto tg_yzzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 700); 

                auto tg_yzzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 701); 

                auto tg_yzzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 702); 

                auto tg_yzzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 703); 

                auto tg_yzzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 704); 

                auto tg_yzzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 705); 

                auto tg_yzzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 706); 

                auto tg_yzzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 707); 

                auto tg_yzzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 708); 

                auto tg_yzzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 709); 

                auto tg_yzzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 710); 

                auto tg_yzzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 711); 

                auto tg_yzzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 712); 

                auto tg_yzzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 713); 

                auto tg_yzzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 714); 

                auto tg_yzzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 715); 

                auto tg_yzzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 716); 

                auto tg_yzzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 717); 

                auto tg_yzzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 718); 

                auto tg_yzzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 719); 

                auto tg_zzzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 720); 

                auto tg_zzzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 721); 

                auto tg_zzzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 722); 

                auto tg_zzzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 723); 

                auto tg_zzzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 724); 

                auto tg_zzzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 725); 

                auto tg_zzzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 726); 

                auto tg_zzzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 727); 

                auto tg_zzzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 728); 

                auto tg_zzzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 729); 

                auto tg_zzzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 730); 

                auto tg_zzzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 731); 

                auto tg_zzzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 732); 

                auto tg_zzzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 733); 

                auto tg_zzzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 734); 

                auto tg_yyyzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 644); 

                auto tg_yyyzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 645); 

                auto tg_yyyzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 646); 

                auto tg_yyyzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 647); 

                auto tg_yyzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 648); 

                auto tg_yyzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 649); 

                auto tg_yyzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 650); 

                auto tg_yyzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 651); 

                auto tg_yyzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 652); 

                auto tg_yyzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 653); 

                auto tg_yyzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 654); 

                auto tg_yyzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 655); 

                auto tg_yyzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 656); 

                auto tg_yyzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 657); 

                auto tg_yyzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 658); 

                auto tg_yyzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 659); 

                auto tg_yyzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 660); 

                auto tg_yyzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 661); 

                auto tg_yyzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 662); 

                auto tg_yyzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 663); 

                auto tg_yyzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 664); 

                auto tg_yyzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 665); 

                auto tg_yyzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 666); 

                auto tg_yyzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 667); 

                auto tg_yyzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 668); 

                auto tg_yyzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 669); 

                auto tg_yyzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 670); 

                auto tg_yyzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 671); 

                auto tg_yyzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 672); 

                auto tg_yyzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 673); 

                auto tg_yyzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 674); 

                auto tg_yyzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 675); 

                auto tg_yyzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 676); 

                auto tg_yyzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 677); 

                auto tg_yyzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 678); 

                auto tg_yyzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 679); 

                auto tg_yyzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 680); 

                auto tg_yyzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 681); 

                auto tg_yyzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 682); 

                auto tg_yyzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 683); 

                auto tg_yzzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 684); 

                auto tg_yzzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 685); 

                auto tg_yzzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 686); 

                auto tg_yzzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 687); 

                auto tg_yzzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 688); 

                auto tg_yzzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 689); 

                auto tg_yzzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 690); 

                auto tg_yzzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 691); 

                auto tg_yzzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 692); 

                auto tg_yzzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 693); 

                auto tg_yzzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 694); 

                auto tg_yzzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 695); 

                auto tg_yzzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 696); 

                auto tg_yzzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 697); 

                auto tg_yzzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 698); 

                auto tg_yzzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 699); 

                auto tg_yzzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 700); 

                auto tg_yzzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 701); 

                auto tg_yzzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 702); 

                auto tg_yzzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 703); 

                auto tg_yzzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 704); 

                auto tg_yzzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 705); 

                auto tg_yzzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 706); 

                auto tg_yzzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 707); 

                auto tg_yzzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 708); 

                auto tg_yzzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 709); 

                auto tg_yzzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 710); 

                auto tg_yzzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 711); 

                auto tg_yzzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 712); 

                auto tg_yzzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 713); 

                auto tg_yzzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 714); 

                auto tg_yzzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 715); 

                auto tg_yzzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 716); 

                auto tg_yzzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 717); 

                auto tg_yzzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 718); 

                auto tg_yzzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 719); 

                auto tg_zzzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 720); 

                auto tg_zzzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 721); 

                auto tg_zzzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 722); 

                auto tg_zzzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 723); 

                auto tg_zzzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 724); 

                auto tg_zzzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 725); 

                auto tg_zzzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 726); 

                auto tg_zzzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 727); 

                auto tg_zzzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 728); 

                auto tg_zzzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 729); 

                auto tg_zzzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 730); 

                auto tg_zzzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 731); 

                auto tg_zzzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 732); 

                auto tg_zzzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 733); 

                auto tg_zzzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 734); 

                auto tg_yyzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 504); 

                auto tg_yyzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 505); 

                auto tg_yyzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 506); 

                auto tg_yyzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 507); 

                auto tg_yyzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 508); 

                auto tg_yyzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 509); 

                auto tg_yyzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 510); 

                auto tg_yyzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 511); 

                auto tg_yyzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 512); 

                auto tg_yyzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 513); 

                auto tg_yyzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 514); 

                auto tg_yyzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 515); 

                auto tg_yyzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 516); 

                auto tg_yyzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 517); 

                auto tg_yyzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 518); 

                auto tg_yyzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 519); 

                auto tg_yyzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 520); 

                auto tg_yyzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 521); 

                auto tg_yyzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 522); 

                auto tg_yyzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 523); 

                auto tg_yyzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 524); 

                auto tg_yyzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 525); 

                auto tg_yyzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 526); 

                auto tg_yyzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 527); 

                auto tg_yyzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 528); 

                auto tg_yyzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 529); 

                auto tg_yyzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 530); 

                auto tg_yyzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 531); 

                auto tg_yzzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 532); 

                auto tg_yzzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 533); 

                auto tg_yzzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 534); 

                auto tg_yzzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 535); 

                auto tg_yzzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 536); 

                auto tg_yzzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 537); 

                auto tg_yzzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 538); 

                auto tg_yzzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 539); 

                auto tg_yzzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 540); 

                auto tg_yzzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 541); 

                auto tg_yzzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 542); 

                auto tg_yzzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 543); 

                auto tg_yzzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 544); 

                auto tg_yzzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 545); 

                auto tg_yzzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 546); 

                auto tg_yzzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 547); 

                auto tg_yzzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 548); 

                auto tg_yzzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 549); 

                auto tg_yzzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 550); 

                auto tg_yzzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 551); 

                auto tg_yzzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 552); 

                auto tg_yzzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 553); 

                auto tg_yzzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 554); 

                auto tg_yzzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 555); 

                auto tg_yzzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 556); 

                auto tg_yzzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 557); 

                auto tg_yzzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 558); 

                auto tg_yzzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 559); 

                auto tg_zzzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 560); 

                auto tg_zzzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 561); 

                auto tg_zzzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 562); 

                auto tg_zzzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 563); 

                auto tg_zzzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 564); 

                auto tg_zzzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 565); 

                auto tg_zzzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 566); 

                auto tg_zzzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 567); 

                auto tg_zzzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 568); 

                auto tg_zzzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 569); 

                auto tg_zzzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 570); 

                auto tg_zzzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 571); 

                auto tg_zzzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 572); 

                auto tg_zzzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 573); 

                auto tg_zzzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 574); 

                // set up pointers to integrals

                auto tg_xyyyzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 644); 

                auto tg_xyyyzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 645); 

                auto tg_xyyyzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 646); 

                auto tg_xyyyzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 647); 

                auto tg_xyyzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 648); 

                auto tg_xyyzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 649); 

                auto tg_xyyzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 650); 

                auto tg_xyyzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 651); 

                auto tg_xyyzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 652); 

                auto tg_xyyzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 653); 

                auto tg_xyyzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 654); 

                auto tg_xyyzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 655); 

                auto tg_xyyzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 656); 

                auto tg_xyyzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 657); 

                auto tg_xyyzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 658); 

                auto tg_xyyzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 659); 

                auto tg_xyyzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 660); 

                auto tg_xyyzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 661); 

                auto tg_xyyzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 662); 

                auto tg_xyyzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 663); 

                auto tg_xyyzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 664); 

                auto tg_xyyzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 665); 

                auto tg_xyyzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 666); 

                auto tg_xyyzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 667); 

                auto tg_xyyzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 668); 

                auto tg_xyyzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 669); 

                auto tg_xyyzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 670); 

                auto tg_xyyzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 671); 

                auto tg_xyyzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 672); 

                auto tg_xyyzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 673); 

                auto tg_xyyzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 674); 

                auto tg_xyyzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 675); 

                auto tg_xyyzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 676); 

                auto tg_xyyzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 677); 

                auto tg_xyyzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 678); 

                auto tg_xyyzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 679); 

                auto tg_xyyzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 680); 

                auto tg_xyyzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 681); 

                auto tg_xyyzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 682); 

                auto tg_xyyzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 683); 

                auto tg_xyzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 684); 

                auto tg_xyzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 685); 

                auto tg_xyzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 686); 

                auto tg_xyzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 687); 

                auto tg_xyzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 688); 

                auto tg_xyzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 689); 

                auto tg_xyzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 690); 

                auto tg_xyzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 691); 

                auto tg_xyzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 692); 

                auto tg_xyzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 693); 

                auto tg_xyzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 694); 

                auto tg_xyzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 695); 

                auto tg_xyzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 696); 

                auto tg_xyzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 697); 

                auto tg_xyzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 698); 

                auto tg_xyzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 699); 

                auto tg_xyzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 700); 

                auto tg_xyzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 701); 

                auto tg_xyzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 702); 

                auto tg_xyzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 703); 

                auto tg_xyzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 704); 

                auto tg_xyzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 705); 

                auto tg_xyzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 706); 

                auto tg_xyzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 707); 

                auto tg_xyzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 708); 

                auto tg_xyzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 709); 

                auto tg_xyzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 710); 

                auto tg_xyzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 711); 

                auto tg_xyzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 712); 

                auto tg_xyzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 713); 

                auto tg_xyzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 714); 

                auto tg_xyzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 715); 

                auto tg_xyzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 716); 

                auto tg_xyzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 717); 

                auto tg_xyzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 718); 

                auto tg_xyzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 719); 

                auto tg_xzzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 720); 

                auto tg_xzzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 721); 

                auto tg_xzzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 722); 

                auto tg_xzzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 723); 

                auto tg_xzzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 724); 

                auto tg_xzzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 725); 

                auto tg_xzzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 726); 

                auto tg_xzzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 727); 

                auto tg_xzzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 728); 

                auto tg_xzzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 729); 

                auto tg_xzzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 730); 

                auto tg_xzzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 731); 

                auto tg_xzzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 732); 

                auto tg_xzzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 733); 

                auto tg_xzzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 734); 

                // Batch of Integrals (644,735)

                #pragma omp simd aligned(fxn, tg_xyyyzz_yyyzzzz_0, tg_xyyyzz_yyzzzzz_0, tg_xyyyzz_yzzzzzz_0, \
                                         tg_xyyyzz_zzzzzzz_0, tg_xyyzzz_xxxxxxx_0, tg_xyyzzz_xxxxxxy_0, tg_xyyzzz_xxxxxxz_0, \
                                         tg_xyyzzz_xxxxxyy_0, tg_xyyzzz_xxxxxyz_0, tg_xyyzzz_xxxxxzz_0, tg_xyyzzz_xxxxyyy_0, \
                                         tg_xyyzzz_xxxxyyz_0, tg_xyyzzz_xxxxyzz_0, tg_xyyzzz_xxxxzzz_0, tg_xyyzzz_xxxyyyy_0, \
                                         tg_xyyzzz_xxxyyyz_0, tg_xyyzzz_xxxyyzz_0, tg_xyyzzz_xxxyzzz_0, tg_xyyzzz_xxxzzzz_0, \
                                         tg_xyyzzz_xxyyyyy_0, tg_xyyzzz_xxyyyyz_0, tg_xyyzzz_xxyyyzz_0, tg_xyyzzz_xxyyzzz_0, \
                                         tg_xyyzzz_xxyzzzz_0, tg_xyyzzz_xxzzzzz_0, tg_xyyzzz_xyyyyyy_0, tg_xyyzzz_xyyyyyz_0, \
                                         tg_xyyzzz_xyyyyzz_0, tg_xyyzzz_xyyyzzz_0, tg_xyyzzz_xyyzzzz_0, tg_xyyzzz_xyzzzzz_0, \
                                         tg_xyyzzz_xzzzzzz_0, tg_xyyzzz_yyyyyyy_0, tg_xyyzzz_yyyyyyz_0, tg_xyyzzz_yyyyyzz_0, \
                                         tg_xyyzzz_yyyyzzz_0, tg_xyyzzz_yyyzzzz_0, tg_xyyzzz_yyzzzzz_0, tg_xyyzzz_yzzzzzz_0, \
                                         tg_xyyzzz_zzzzzzz_0, tg_xyzzzz_xxxxxxx_0, tg_xyzzzz_xxxxxxy_0, tg_xyzzzz_xxxxxxz_0, \
                                         tg_xyzzzz_xxxxxyy_0, tg_xyzzzz_xxxxxyz_0, tg_xyzzzz_xxxxxzz_0, tg_xyzzzz_xxxxyyy_0, \
                                         tg_xyzzzz_xxxxyyz_0, tg_xyzzzz_xxxxyzz_0, tg_xyzzzz_xxxxzzz_0, tg_xyzzzz_xxxyyyy_0, \
                                         tg_xyzzzz_xxxyyyz_0, tg_xyzzzz_xxxyyzz_0, tg_xyzzzz_xxxyzzz_0, tg_xyzzzz_xxxzzzz_0, \
                                         tg_xyzzzz_xxyyyyy_0, tg_xyzzzz_xxyyyyz_0, tg_xyzzzz_xxyyyzz_0, tg_xyzzzz_xxyyzzz_0, \
                                         tg_xyzzzz_xxyzzzz_0, tg_xyzzzz_xxzzzzz_0, tg_xyzzzz_xyyyyyy_0, tg_xyzzzz_xyyyyyz_0, \
                                         tg_xyzzzz_xyyyyzz_0, tg_xyzzzz_xyyyzzz_0, tg_xyzzzz_xyyzzzz_0, tg_xyzzzz_xyzzzzz_0, \
                                         tg_xyzzzz_xzzzzzz_0, tg_xyzzzz_yyyyyyy_0, tg_xyzzzz_yyyyyyz_0, tg_xyzzzz_yyyyyzz_0, \
                                         tg_xyzzzz_yyyyzzz_0, tg_xyzzzz_yyyzzzz_0, tg_xyzzzz_yyzzzzz_0, tg_xyzzzz_yzzzzzz_0, \
                                         tg_xyzzzz_zzzzzzz_0, tg_xzzzzz_xxxxxxx_0, tg_xzzzzz_xxxxxxy_0, tg_xzzzzz_xxxxxxz_0, \
                                         tg_xzzzzz_xxxxxyy_0, tg_xzzzzz_xxxxxyz_0, tg_xzzzzz_xxxxxzz_0, tg_xzzzzz_xxxxyyy_0, \
                                         tg_xzzzzz_xxxxyyz_0, tg_xzzzzz_xxxxyzz_0, tg_xzzzzz_xxxxzzz_0, tg_xzzzzz_xxxyyyy_0, \
                                         tg_xzzzzz_xxxyyyz_0, tg_xzzzzz_xxxyyzz_0, tg_xzzzzz_xxxyzzz_0, tg_xzzzzz_xxxzzzz_0, \
                                         tg_yyyzz_yyyzzzz_0, tg_yyyzz_yyyzzzz_1, tg_yyyzz_yyzzzzz_0, tg_yyyzz_yyzzzzz_1, \
                                         tg_yyyzz_yzzzzzz_0, tg_yyyzz_yzzzzzz_1, tg_yyyzz_zzzzzzz_0, tg_yyyzz_zzzzzzz_1, \
                                         tg_yyzzz_xxxxxx_1, tg_yyzzz_xxxxxxx_0, tg_yyzzz_xxxxxxx_1, tg_yyzzz_xxxxxxy_0, \
                                         tg_yyzzz_xxxxxxy_1, tg_yyzzz_xxxxxxz_0, tg_yyzzz_xxxxxxz_1, tg_yyzzz_xxxxxy_1, \
                                         tg_yyzzz_xxxxxyy_0, tg_yyzzz_xxxxxyy_1, tg_yyzzz_xxxxxyz_0, tg_yyzzz_xxxxxyz_1, \
                                         tg_yyzzz_xxxxxz_1, tg_yyzzz_xxxxxzz_0, tg_yyzzz_xxxxxzz_1, tg_yyzzz_xxxxyy_1, \
                                         tg_yyzzz_xxxxyyy_0, tg_yyzzz_xxxxyyy_1, tg_yyzzz_xxxxyyz_0, tg_yyzzz_xxxxyyz_1, \
                                         tg_yyzzz_xxxxyz_1, tg_yyzzz_xxxxyzz_0, tg_yyzzz_xxxxyzz_1, tg_yyzzz_xxxxzz_1, \
                                         tg_yyzzz_xxxxzzz_0, tg_yyzzz_xxxxzzz_1, tg_yyzzz_xxxyyy_1, tg_yyzzz_xxxyyyy_0, \
                                         tg_yyzzz_xxxyyyy_1, tg_yyzzz_xxxyyyz_0, tg_yyzzz_xxxyyyz_1, tg_yyzzz_xxxyyz_1, \
                                         tg_yyzzz_xxxyyzz_0, tg_yyzzz_xxxyyzz_1, tg_yyzzz_xxxyzz_1, tg_yyzzz_xxxyzzz_0, \
                                         tg_yyzzz_xxxyzzz_1, tg_yyzzz_xxxzzz_1, tg_yyzzz_xxxzzzz_0, tg_yyzzz_xxxzzzz_1, \
                                         tg_yyzzz_xxyyyy_1, tg_yyzzz_xxyyyyy_0, tg_yyzzz_xxyyyyy_1, tg_yyzzz_xxyyyyz_0, \
                                         tg_yyzzz_xxyyyyz_1, tg_yyzzz_xxyyyz_1, tg_yyzzz_xxyyyzz_0, tg_yyzzz_xxyyyzz_1, \
                                         tg_yyzzz_xxyyzz_1, tg_yyzzz_xxyyzzz_0, tg_yyzzz_xxyyzzz_1, tg_yyzzz_xxyzzz_1, \
                                         tg_yyzzz_xxyzzzz_0, tg_yyzzz_xxyzzzz_1, tg_yyzzz_xxzzzz_1, tg_yyzzz_xxzzzzz_0, \
                                         tg_yyzzz_xxzzzzz_1, tg_yyzzz_xyyyyy_1, tg_yyzzz_xyyyyyy_0, tg_yyzzz_xyyyyyy_1, \
                                         tg_yyzzz_xyyyyyz_0, tg_yyzzz_xyyyyyz_1, tg_yyzzz_xyyyyz_1, tg_yyzzz_xyyyyzz_0, \
                                         tg_yyzzz_xyyyyzz_1, tg_yyzzz_xyyyzz_1, tg_yyzzz_xyyyzzz_0, tg_yyzzz_xyyyzzz_1, \
                                         tg_yyzzz_xyyzzz_1, tg_yyzzz_xyyzzzz_0, tg_yyzzz_xyyzzzz_1, tg_yyzzz_xyzzzz_1, \
                                         tg_yyzzz_xyzzzzz_0, tg_yyzzz_xyzzzzz_1, tg_yyzzz_xzzzzz_1, tg_yyzzz_xzzzzzz_0, \
                                         tg_yyzzz_xzzzzzz_1, tg_yyzzz_yyyyyy_1, tg_yyzzz_yyyyyyy_0, tg_yyzzz_yyyyyyy_1, \
                                         tg_yyzzz_yyyyyyz_0, tg_yyzzz_yyyyyyz_1, tg_yyzzz_yyyyyz_1, tg_yyzzz_yyyyyzz_0, \
                                         tg_yyzzz_yyyyyzz_1, tg_yyzzz_yyyyzz_1, tg_yyzzz_yyyyzzz_0, tg_yyzzz_yyyyzzz_1, \
                                         tg_yyzzz_yyyzzz_1, tg_yyzzz_yyyzzzz_0, tg_yyzzz_yyyzzzz_1, tg_yyzzz_yyzzzz_1, \
                                         tg_yyzzz_yyzzzzz_0, tg_yyzzz_yyzzzzz_1, tg_yyzzz_yzzzzz_1, tg_yyzzz_yzzzzzz_0, \
                                         tg_yyzzz_yzzzzzz_1, tg_yyzzz_zzzzzz_1, tg_yyzzz_zzzzzzz_0, tg_yyzzz_zzzzzzz_1, \
                                         tg_yzzzz_xxxxxx_1, tg_yzzzz_xxxxxxx_0, tg_yzzzz_xxxxxxx_1, tg_yzzzz_xxxxxxy_0, \
                                         tg_yzzzz_xxxxxxy_1, tg_yzzzz_xxxxxxz_0, tg_yzzzz_xxxxxxz_1, tg_yzzzz_xxxxxy_1, \
                                         tg_yzzzz_xxxxxyy_0, tg_yzzzz_xxxxxyy_1, tg_yzzzz_xxxxxyz_0, tg_yzzzz_xxxxxyz_1, \
                                         tg_yzzzz_xxxxxz_1, tg_yzzzz_xxxxxzz_0, tg_yzzzz_xxxxxzz_1, tg_yzzzz_xxxxyy_1, \
                                         tg_yzzzz_xxxxyyy_0, tg_yzzzz_xxxxyyy_1, tg_yzzzz_xxxxyyz_0, tg_yzzzz_xxxxyyz_1, \
                                         tg_yzzzz_xxxxyz_1, tg_yzzzz_xxxxyzz_0, tg_yzzzz_xxxxyzz_1, tg_yzzzz_xxxxzz_1, \
                                         tg_yzzzz_xxxxzzz_0, tg_yzzzz_xxxxzzz_1, tg_yzzzz_xxxyyy_1, tg_yzzzz_xxxyyyy_0, \
                                         tg_yzzzz_xxxyyyy_1, tg_yzzzz_xxxyyyz_0, tg_yzzzz_xxxyyyz_1, tg_yzzzz_xxxyyz_1, \
                                         tg_yzzzz_xxxyyzz_0, tg_yzzzz_xxxyyzz_1, tg_yzzzz_xxxyzz_1, tg_yzzzz_xxxyzzz_0, \
                                         tg_yzzzz_xxxyzzz_1, tg_yzzzz_xxxzzz_1, tg_yzzzz_xxxzzzz_0, tg_yzzzz_xxxzzzz_1, \
                                         tg_yzzzz_xxyyyy_1, tg_yzzzz_xxyyyyy_0, tg_yzzzz_xxyyyyy_1, tg_yzzzz_xxyyyyz_0, \
                                         tg_yzzzz_xxyyyyz_1, tg_yzzzz_xxyyyz_1, tg_yzzzz_xxyyyzz_0, tg_yzzzz_xxyyyzz_1, \
                                         tg_yzzzz_xxyyzz_1, tg_yzzzz_xxyyzzz_0, tg_yzzzz_xxyyzzz_1, tg_yzzzz_xxyzzz_1, \
                                         tg_yzzzz_xxyzzzz_0, tg_yzzzz_xxyzzzz_1, tg_yzzzz_xxzzzz_1, tg_yzzzz_xxzzzzz_0, \
                                         tg_yzzzz_xxzzzzz_1, tg_yzzzz_xyyyyy_1, tg_yzzzz_xyyyyyy_0, tg_yzzzz_xyyyyyy_1, \
                                         tg_yzzzz_xyyyyyz_0, tg_yzzzz_xyyyyyz_1, tg_yzzzz_xyyyyz_1, tg_yzzzz_xyyyyzz_0, \
                                         tg_yzzzz_xyyyyzz_1, tg_yzzzz_xyyyzz_1, tg_yzzzz_xyyyzzz_0, tg_yzzzz_xyyyzzz_1, \
                                         tg_yzzzz_xyyzzz_1, tg_yzzzz_xyyzzzz_0, tg_yzzzz_xyyzzzz_1, tg_yzzzz_xyzzzz_1, \
                                         tg_yzzzz_xyzzzzz_0, tg_yzzzz_xyzzzzz_1, tg_yzzzz_xzzzzz_1, tg_yzzzz_xzzzzzz_0, \
                                         tg_yzzzz_xzzzzzz_1, tg_yzzzz_yyyyyy_1, tg_yzzzz_yyyyyyy_0, tg_yzzzz_yyyyyyy_1, \
                                         tg_yzzzz_yyyyyyz_0, tg_yzzzz_yyyyyyz_1, tg_yzzzz_yyyyyz_1, tg_yzzzz_yyyyyzz_0, \
                                         tg_yzzzz_yyyyyzz_1, tg_yzzzz_yyyyzz_1, tg_yzzzz_yyyyzzz_0, tg_yzzzz_yyyyzzz_1, \
                                         tg_yzzzz_yyyzzz_1, tg_yzzzz_yyyzzzz_0, tg_yzzzz_yyyzzzz_1, tg_yzzzz_yyzzzz_1, \
                                         tg_yzzzz_yyzzzzz_0, tg_yzzzz_yyzzzzz_1, tg_yzzzz_yzzzzz_1, tg_yzzzz_yzzzzzz_0, \
                                         tg_yzzzz_yzzzzzz_1, tg_yzzzz_zzzzzz_1, tg_yzzzz_zzzzzzz_0, tg_yzzzz_zzzzzzz_1, \
                                         tg_zzzzz_xxxxxx_1, tg_zzzzz_xxxxxxx_0, tg_zzzzz_xxxxxxx_1, tg_zzzzz_xxxxxxy_0, \
                                         tg_zzzzz_xxxxxxy_1, tg_zzzzz_xxxxxxz_0, tg_zzzzz_xxxxxxz_1, tg_zzzzz_xxxxxy_1, \
                                         tg_zzzzz_xxxxxyy_0, tg_zzzzz_xxxxxyy_1, tg_zzzzz_xxxxxyz_0, tg_zzzzz_xxxxxyz_1, \
                                         tg_zzzzz_xxxxxz_1, tg_zzzzz_xxxxxzz_0, tg_zzzzz_xxxxxzz_1, tg_zzzzz_xxxxyy_1, \
                                         tg_zzzzz_xxxxyyy_0, tg_zzzzz_xxxxyyy_1, tg_zzzzz_xxxxyyz_0, tg_zzzzz_xxxxyyz_1, \
                                         tg_zzzzz_xxxxyz_1, tg_zzzzz_xxxxyzz_0, tg_zzzzz_xxxxyzz_1, tg_zzzzz_xxxxzz_1, \
                                         tg_zzzzz_xxxxzzz_0, tg_zzzzz_xxxxzzz_1, tg_zzzzz_xxxyyy_1, tg_zzzzz_xxxyyyy_0, \
                                         tg_zzzzz_xxxyyyy_1, tg_zzzzz_xxxyyyz_0, tg_zzzzz_xxxyyyz_1, tg_zzzzz_xxxyyz_1, \
                                         tg_zzzzz_xxxyyzz_0, tg_zzzzz_xxxyyzz_1, tg_zzzzz_xxxyzz_1, tg_zzzzz_xxxyzzz_0, \
                                         tg_zzzzz_xxxyzzz_1, tg_zzzzz_xxxzzz_1, tg_zzzzz_xxxzzzz_0, tg_zzzzz_xxxzzzz_1, \
                                         tg_zzzzz_xxyyyy_1, tg_zzzzz_xxyyyz_1, tg_zzzzz_xxyyzz_1, tg_zzzzz_xxyzzz_1, \
                                         tg_zzzzz_xxzzzz_1, wp_x: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fxn = fxn[j];

                    double fr = wp_x[j]; 

                    tg_xyyyzz_yyyzzzz_0[j] = pb_x * tg_yyyzz_yyyzzzz_0[j] + fr * tg_yyyzz_yyyzzzz_1[j];

                    tg_xyyyzz_yyzzzzz_0[j] = pb_x * tg_yyyzz_yyzzzzz_0[j] + fr * tg_yyyzz_yyzzzzz_1[j];

                    tg_xyyyzz_yzzzzzz_0[j] = pb_x * tg_yyyzz_yzzzzzz_0[j] + fr * tg_yyyzz_yzzzzzz_1[j];

                    tg_xyyyzz_zzzzzzz_0[j] = pb_x * tg_yyyzz_zzzzzzz_0[j] + fr * tg_yyyzz_zzzzzzz_1[j];

                    tg_xyyzzz_xxxxxxx_0[j] = pb_x * tg_yyzzz_xxxxxxx_0[j] + fr * tg_yyzzz_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_yyzzz_xxxxxx_1[j];

                    tg_xyyzzz_xxxxxxy_0[j] = pb_x * tg_yyzzz_xxxxxxy_0[j] + fr * tg_yyzzz_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_yyzzz_xxxxxy_1[j];

                    tg_xyyzzz_xxxxxxz_0[j] = pb_x * tg_yyzzz_xxxxxxz_0[j] + fr * tg_yyzzz_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_yyzzz_xxxxxz_1[j];

                    tg_xyyzzz_xxxxxyy_0[j] = pb_x * tg_yyzzz_xxxxxyy_0[j] + fr * tg_yyzzz_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_yyzzz_xxxxyy_1[j];

                    tg_xyyzzz_xxxxxyz_0[j] = pb_x * tg_yyzzz_xxxxxyz_0[j] + fr * tg_yyzzz_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_yyzzz_xxxxyz_1[j];

                    tg_xyyzzz_xxxxxzz_0[j] = pb_x * tg_yyzzz_xxxxxzz_0[j] + fr * tg_yyzzz_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_yyzzz_xxxxzz_1[j];

                    tg_xyyzzz_xxxxyyy_0[j] = pb_x * tg_yyzzz_xxxxyyy_0[j] + fr * tg_yyzzz_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_yyzzz_xxxyyy_1[j];

                    tg_xyyzzz_xxxxyyz_0[j] = pb_x * tg_yyzzz_xxxxyyz_0[j] + fr * tg_yyzzz_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_yyzzz_xxxyyz_1[j];

                    tg_xyyzzz_xxxxyzz_0[j] = pb_x * tg_yyzzz_xxxxyzz_0[j] + fr * tg_yyzzz_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_yyzzz_xxxyzz_1[j];

                    tg_xyyzzz_xxxxzzz_0[j] = pb_x * tg_yyzzz_xxxxzzz_0[j] + fr * tg_yyzzz_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_yyzzz_xxxzzz_1[j];

                    tg_xyyzzz_xxxyyyy_0[j] = pb_x * tg_yyzzz_xxxyyyy_0[j] + fr * tg_yyzzz_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xxyyyy_1[j];

                    tg_xyyzzz_xxxyyyz_0[j] = pb_x * tg_yyzzz_xxxyyyz_0[j] + fr * tg_yyzzz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xxyyyz_1[j];

                    tg_xyyzzz_xxxyyzz_0[j] = pb_x * tg_yyzzz_xxxyyzz_0[j] + fr * tg_yyzzz_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xxyyzz_1[j];

                    tg_xyyzzz_xxxyzzz_0[j] = pb_x * tg_yyzzz_xxxyzzz_0[j] + fr * tg_yyzzz_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xxyzzz_1[j];

                    tg_xyyzzz_xxxzzzz_0[j] = pb_x * tg_yyzzz_xxxzzzz_0[j] + fr * tg_yyzzz_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_yyzzz_xxzzzz_1[j];

                    tg_xyyzzz_xxyyyyy_0[j] = pb_x * tg_yyzzz_xxyyyyy_0[j] + fr * tg_yyzzz_xxyyyyy_1[j] + fl1_fxn * tg_yyzzz_xyyyyy_1[j];

                    tg_xyyzzz_xxyyyyz_0[j] = pb_x * tg_yyzzz_xxyyyyz_0[j] + fr * tg_yyzzz_xxyyyyz_1[j] + fl1_fxn * tg_yyzzz_xyyyyz_1[j];

                    tg_xyyzzz_xxyyyzz_0[j] = pb_x * tg_yyzzz_xxyyyzz_0[j] + fr * tg_yyzzz_xxyyyzz_1[j] + fl1_fxn * tg_yyzzz_xyyyzz_1[j];

                    tg_xyyzzz_xxyyzzz_0[j] = pb_x * tg_yyzzz_xxyyzzz_0[j] + fr * tg_yyzzz_xxyyzzz_1[j] + fl1_fxn * tg_yyzzz_xyyzzz_1[j];

                    tg_xyyzzz_xxyzzzz_0[j] = pb_x * tg_yyzzz_xxyzzzz_0[j] + fr * tg_yyzzz_xxyzzzz_1[j] + fl1_fxn * tg_yyzzz_xyzzzz_1[j];

                    tg_xyyzzz_xxzzzzz_0[j] = pb_x * tg_yyzzz_xxzzzzz_0[j] + fr * tg_yyzzz_xxzzzzz_1[j] + fl1_fxn * tg_yyzzz_xzzzzz_1[j];

                    tg_xyyzzz_xyyyyyy_0[j] = pb_x * tg_yyzzz_xyyyyyy_0[j] + fr * tg_yyzzz_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yyyyyy_1[j];

                    tg_xyyzzz_xyyyyyz_0[j] = pb_x * tg_yyzzz_xyyyyyz_0[j] + fr * tg_yyzzz_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yyyyyz_1[j];

                    tg_xyyzzz_xyyyyzz_0[j] = pb_x * tg_yyzzz_xyyyyzz_0[j] + fr * tg_yyzzz_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yyyyzz_1[j];

                    tg_xyyzzz_xyyyzzz_0[j] = pb_x * tg_yyzzz_xyyyzzz_0[j] + fr * tg_yyzzz_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yyyzzz_1[j];

                    tg_xyyzzz_xyyzzzz_0[j] = pb_x * tg_yyzzz_xyyzzzz_0[j] + fr * tg_yyzzz_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yyzzzz_1[j];

                    tg_xyyzzz_xyzzzzz_0[j] = pb_x * tg_yyzzz_xyzzzzz_0[j] + fr * tg_yyzzz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_yzzzzz_1[j];

                    tg_xyyzzz_xzzzzzz_0[j] = pb_x * tg_yyzzz_xzzzzzz_0[j] + fr * tg_yyzzz_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_yyzzz_zzzzzz_1[j];

                    tg_xyyzzz_yyyyyyy_0[j] = pb_x * tg_yyzzz_yyyyyyy_0[j] + fr * tg_yyzzz_yyyyyyy_1[j];

                    tg_xyyzzz_yyyyyyz_0[j] = pb_x * tg_yyzzz_yyyyyyz_0[j] + fr * tg_yyzzz_yyyyyyz_1[j];

                    tg_xyyzzz_yyyyyzz_0[j] = pb_x * tg_yyzzz_yyyyyzz_0[j] + fr * tg_yyzzz_yyyyyzz_1[j];

                    tg_xyyzzz_yyyyzzz_0[j] = pb_x * tg_yyzzz_yyyyzzz_0[j] + fr * tg_yyzzz_yyyyzzz_1[j];

                    tg_xyyzzz_yyyzzzz_0[j] = pb_x * tg_yyzzz_yyyzzzz_0[j] + fr * tg_yyzzz_yyyzzzz_1[j];

                    tg_xyyzzz_yyzzzzz_0[j] = pb_x * tg_yyzzz_yyzzzzz_0[j] + fr * tg_yyzzz_yyzzzzz_1[j];

                    tg_xyyzzz_yzzzzzz_0[j] = pb_x * tg_yyzzz_yzzzzzz_0[j] + fr * tg_yyzzz_yzzzzzz_1[j];

                    tg_xyyzzz_zzzzzzz_0[j] = pb_x * tg_yyzzz_zzzzzzz_0[j] + fr * tg_yyzzz_zzzzzzz_1[j];

                    tg_xyzzzz_xxxxxxx_0[j] = pb_x * tg_yzzzz_xxxxxxx_0[j] + fr * tg_yzzzz_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_yzzzz_xxxxxx_1[j];

                    tg_xyzzzz_xxxxxxy_0[j] = pb_x * tg_yzzzz_xxxxxxy_0[j] + fr * tg_yzzzz_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_yzzzz_xxxxxy_1[j];

                    tg_xyzzzz_xxxxxxz_0[j] = pb_x * tg_yzzzz_xxxxxxz_0[j] + fr * tg_yzzzz_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_yzzzz_xxxxxz_1[j];

                    tg_xyzzzz_xxxxxyy_0[j] = pb_x * tg_yzzzz_xxxxxyy_0[j] + fr * tg_yzzzz_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_yzzzz_xxxxyy_1[j];

                    tg_xyzzzz_xxxxxyz_0[j] = pb_x * tg_yzzzz_xxxxxyz_0[j] + fr * tg_yzzzz_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_yzzzz_xxxxyz_1[j];

                    tg_xyzzzz_xxxxxzz_0[j] = pb_x * tg_yzzzz_xxxxxzz_0[j] + fr * tg_yzzzz_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_yzzzz_xxxxzz_1[j];

                    tg_xyzzzz_xxxxyyy_0[j] = pb_x * tg_yzzzz_xxxxyyy_0[j] + fr * tg_yzzzz_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_yzzzz_xxxyyy_1[j];

                    tg_xyzzzz_xxxxyyz_0[j] = pb_x * tg_yzzzz_xxxxyyz_0[j] + fr * tg_yzzzz_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_yzzzz_xxxyyz_1[j];

                    tg_xyzzzz_xxxxyzz_0[j] = pb_x * tg_yzzzz_xxxxyzz_0[j] + fr * tg_yzzzz_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_yzzzz_xxxyzz_1[j];

                    tg_xyzzzz_xxxxzzz_0[j] = pb_x * tg_yzzzz_xxxxzzz_0[j] + fr * tg_yzzzz_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_yzzzz_xxxzzz_1[j];

                    tg_xyzzzz_xxxyyyy_0[j] = pb_x * tg_yzzzz_xxxyyyy_0[j] + fr * tg_yzzzz_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xxyyyy_1[j];

                    tg_xyzzzz_xxxyyyz_0[j] = pb_x * tg_yzzzz_xxxyyyz_0[j] + fr * tg_yzzzz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xxyyyz_1[j];

                    tg_xyzzzz_xxxyyzz_0[j] = pb_x * tg_yzzzz_xxxyyzz_0[j] + fr * tg_yzzzz_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xxyyzz_1[j];

                    tg_xyzzzz_xxxyzzz_0[j] = pb_x * tg_yzzzz_xxxyzzz_0[j] + fr * tg_yzzzz_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xxyzzz_1[j];

                    tg_xyzzzz_xxxzzzz_0[j] = pb_x * tg_yzzzz_xxxzzzz_0[j] + fr * tg_yzzzz_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_yzzzz_xxzzzz_1[j];

                    tg_xyzzzz_xxyyyyy_0[j] = pb_x * tg_yzzzz_xxyyyyy_0[j] + fr * tg_yzzzz_xxyyyyy_1[j] + fl1_fxn * tg_yzzzz_xyyyyy_1[j];

                    tg_xyzzzz_xxyyyyz_0[j] = pb_x * tg_yzzzz_xxyyyyz_0[j] + fr * tg_yzzzz_xxyyyyz_1[j] + fl1_fxn * tg_yzzzz_xyyyyz_1[j];

                    tg_xyzzzz_xxyyyzz_0[j] = pb_x * tg_yzzzz_xxyyyzz_0[j] + fr * tg_yzzzz_xxyyyzz_1[j] + fl1_fxn * tg_yzzzz_xyyyzz_1[j];

                    tg_xyzzzz_xxyyzzz_0[j] = pb_x * tg_yzzzz_xxyyzzz_0[j] + fr * tg_yzzzz_xxyyzzz_1[j] + fl1_fxn * tg_yzzzz_xyyzzz_1[j];

                    tg_xyzzzz_xxyzzzz_0[j] = pb_x * tg_yzzzz_xxyzzzz_0[j] + fr * tg_yzzzz_xxyzzzz_1[j] + fl1_fxn * tg_yzzzz_xyzzzz_1[j];

                    tg_xyzzzz_xxzzzzz_0[j] = pb_x * tg_yzzzz_xxzzzzz_0[j] + fr * tg_yzzzz_xxzzzzz_1[j] + fl1_fxn * tg_yzzzz_xzzzzz_1[j];

                    tg_xyzzzz_xyyyyyy_0[j] = pb_x * tg_yzzzz_xyyyyyy_0[j] + fr * tg_yzzzz_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yyyyyy_1[j];

                    tg_xyzzzz_xyyyyyz_0[j] = pb_x * tg_yzzzz_xyyyyyz_0[j] + fr * tg_yzzzz_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yyyyyz_1[j];

                    tg_xyzzzz_xyyyyzz_0[j] = pb_x * tg_yzzzz_xyyyyzz_0[j] + fr * tg_yzzzz_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yyyyzz_1[j];

                    tg_xyzzzz_xyyyzzz_0[j] = pb_x * tg_yzzzz_xyyyzzz_0[j] + fr * tg_yzzzz_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yyyzzz_1[j];

                    tg_xyzzzz_xyyzzzz_0[j] = pb_x * tg_yzzzz_xyyzzzz_0[j] + fr * tg_yzzzz_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yyzzzz_1[j];

                    tg_xyzzzz_xyzzzzz_0[j] = pb_x * tg_yzzzz_xyzzzzz_0[j] + fr * tg_yzzzz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_yzzzzz_1[j];

                    tg_xyzzzz_xzzzzzz_0[j] = pb_x * tg_yzzzz_xzzzzzz_0[j] + fr * tg_yzzzz_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_yzzzz_zzzzzz_1[j];

                    tg_xyzzzz_yyyyyyy_0[j] = pb_x * tg_yzzzz_yyyyyyy_0[j] + fr * tg_yzzzz_yyyyyyy_1[j];

                    tg_xyzzzz_yyyyyyz_0[j] = pb_x * tg_yzzzz_yyyyyyz_0[j] + fr * tg_yzzzz_yyyyyyz_1[j];

                    tg_xyzzzz_yyyyyzz_0[j] = pb_x * tg_yzzzz_yyyyyzz_0[j] + fr * tg_yzzzz_yyyyyzz_1[j];

                    tg_xyzzzz_yyyyzzz_0[j] = pb_x * tg_yzzzz_yyyyzzz_0[j] + fr * tg_yzzzz_yyyyzzz_1[j];

                    tg_xyzzzz_yyyzzzz_0[j] = pb_x * tg_yzzzz_yyyzzzz_0[j] + fr * tg_yzzzz_yyyzzzz_1[j];

                    tg_xyzzzz_yyzzzzz_0[j] = pb_x * tg_yzzzz_yyzzzzz_0[j] + fr * tg_yzzzz_yyzzzzz_1[j];

                    tg_xyzzzz_yzzzzzz_0[j] = pb_x * tg_yzzzz_yzzzzzz_0[j] + fr * tg_yzzzz_yzzzzzz_1[j];

                    tg_xyzzzz_zzzzzzz_0[j] = pb_x * tg_yzzzz_zzzzzzz_0[j] + fr * tg_yzzzz_zzzzzzz_1[j];

                    tg_xzzzzz_xxxxxxx_0[j] = pb_x * tg_zzzzz_xxxxxxx_0[j] + fr * tg_zzzzz_xxxxxxx_1[j] + 3.5 * fl1_fxn * tg_zzzzz_xxxxxx_1[j];

                    tg_xzzzzz_xxxxxxy_0[j] = pb_x * tg_zzzzz_xxxxxxy_0[j] + fr * tg_zzzzz_xxxxxxy_1[j] + 3.0 * fl1_fxn * tg_zzzzz_xxxxxy_1[j];

                    tg_xzzzzz_xxxxxxz_0[j] = pb_x * tg_zzzzz_xxxxxxz_0[j] + fr * tg_zzzzz_xxxxxxz_1[j] + 3.0 * fl1_fxn * tg_zzzzz_xxxxxz_1[j];

                    tg_xzzzzz_xxxxxyy_0[j] = pb_x * tg_zzzzz_xxxxxyy_0[j] + fr * tg_zzzzz_xxxxxyy_1[j] + 2.5 * fl1_fxn * tg_zzzzz_xxxxyy_1[j];

                    tg_xzzzzz_xxxxxyz_0[j] = pb_x * tg_zzzzz_xxxxxyz_0[j] + fr * tg_zzzzz_xxxxxyz_1[j] + 2.5 * fl1_fxn * tg_zzzzz_xxxxyz_1[j];

                    tg_xzzzzz_xxxxxzz_0[j] = pb_x * tg_zzzzz_xxxxxzz_0[j] + fr * tg_zzzzz_xxxxxzz_1[j] + 2.5 * fl1_fxn * tg_zzzzz_xxxxzz_1[j];

                    tg_xzzzzz_xxxxyyy_0[j] = pb_x * tg_zzzzz_xxxxyyy_0[j] + fr * tg_zzzzz_xxxxyyy_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxxyyy_1[j];

                    tg_xzzzzz_xxxxyyz_0[j] = pb_x * tg_zzzzz_xxxxyyz_0[j] + fr * tg_zzzzz_xxxxyyz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxxyyz_1[j];

                    tg_xzzzzz_xxxxyzz_0[j] = pb_x * tg_zzzzz_xxxxyzz_0[j] + fr * tg_zzzzz_xxxxyzz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxxyzz_1[j];

                    tg_xzzzzz_xxxxzzz_0[j] = pb_x * tg_zzzzz_xxxxzzz_0[j] + fr * tg_zzzzz_xxxxzzz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxxzzz_1[j];

                    tg_xzzzzz_xxxyyyy_0[j] = pb_x * tg_zzzzz_xxxyyyy_0[j] + fr * tg_zzzzz_xxxyyyy_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxyyyy_1[j];

                    tg_xzzzzz_xxxyyyz_0[j] = pb_x * tg_zzzzz_xxxyyyz_0[j] + fr * tg_zzzzz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxyyyz_1[j];

                    tg_xzzzzz_xxxyyzz_0[j] = pb_x * tg_zzzzz_xxxyyzz_0[j] + fr * tg_zzzzz_xxxyyzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxyyzz_1[j];

                    tg_xzzzzz_xxxyzzz_0[j] = pb_x * tg_zzzzz_xxxyzzz_0[j] + fr * tg_zzzzz_xxxyzzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxyzzz_1[j];

                    tg_xzzzzz_xxxzzzz_0[j] = pb_x * tg_zzzzz_xxxzzzz_0[j] + fr * tg_zzzzz_xxxzzzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxzzzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_735_826(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (735,826)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_x = braGtoPairsBlock.getDistancesPBX();

        auto r_pb_y = braGtoPairsBlock.getDistancesPBY();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
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

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_x = wpDistances.data(3 * idx);

                auto wp_y = wpDistances.data(3 * idx + 1);

                // set up pointers to auxilary integrals

                auto tg_yyyyy_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 540); 

                auto tg_yyyyy_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 541); 

                auto tg_yyyyy_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 542); 

                auto tg_yyyyy_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 543); 

                auto tg_yyyyy_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 544); 

                auto tg_yyyyy_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 545); 

                auto tg_yyyyy_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 546); 

                auto tg_yyyyy_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 547); 

                auto tg_yyyyy_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 548); 

                auto tg_yyyyy_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 549); 

                auto tg_yyyyy_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 550); 

                auto tg_yyyyy_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 551); 

                auto tg_yyyyy_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 552); 

                auto tg_yyyyy_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 553); 

                auto tg_yyyyy_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 554); 

                auto tg_yyyyy_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 555); 

                auto tg_yyyyy_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 556); 

                auto tg_yyyyy_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 557); 

                auto tg_yyyyy_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 558); 

                auto tg_yyyyy_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 559); 

                auto tg_yyyyy_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 560); 

                auto tg_yyyyy_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 561); 

                auto tg_yyyyy_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 562); 

                auto tg_yyyyy_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 563); 

                auto tg_yyyyy_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 564); 

                auto tg_yyyyy_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 565); 

                auto tg_yyyyy_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 566); 

                auto tg_yyyyy_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 567); 

                auto tg_yyyyy_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 568); 

                auto tg_yyyyy_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 569); 

                auto tg_yyyyy_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 570); 

                auto tg_yyyyy_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 571); 

                auto tg_yyyyy_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 572); 

                auto tg_yyyyy_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 573); 

                auto tg_yyyyy_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 574); 

                auto tg_yyyyy_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 575); 

                auto tg_yyyyz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 576); 

                auto tg_yyyyz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 577); 

                auto tg_yyyyz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 578); 

                auto tg_yyyyz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 579); 

                auto tg_yyyyz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 580); 

                auto tg_yyyyz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 581); 

                auto tg_yyyyz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 582); 

                auto tg_yyyyz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 583); 

                auto tg_yyyyz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 584); 

                auto tg_yyyyz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 585); 

                auto tg_yyyyz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 586); 

                auto tg_yyyyz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 587); 

                auto tg_yyyyz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 588); 

                auto tg_yyyyz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 589); 

                auto tg_yyyyz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 590); 

                auto tg_yyyyz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 591); 

                auto tg_yyyyz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 592); 

                auto tg_yyyyz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 593); 

                auto tg_yyyyz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 594); 

                auto tg_yyyyz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 595); 

                auto tg_yyyyz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 596); 

                auto tg_yyyyz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 597); 

                auto tg_yyyyz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 598); 

                auto tg_yyyyz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 599); 

                auto tg_yyyyz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 600); 

                auto tg_yyyyz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 601); 

                auto tg_yyyyz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 602); 

                auto tg_yyyyz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 603); 

                auto tg_yyyyz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 604); 

                auto tg_yyyyz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 605); 

                auto tg_yyyyz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 606); 

                auto tg_yyyyz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 607); 

                auto tg_yyyyz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 608); 

                auto tg_yyyyz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 609); 

                auto tg_zzzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 735); 

                auto tg_zzzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 736); 

                auto tg_zzzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 737); 

                auto tg_zzzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 738); 

                auto tg_zzzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 739); 

                auto tg_zzzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 740); 

                auto tg_zzzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 741); 

                auto tg_zzzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 742); 

                auto tg_zzzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 743); 

                auto tg_zzzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 744); 

                auto tg_zzzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 745); 

                auto tg_zzzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 746); 

                auto tg_zzzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 747); 

                auto tg_zzzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 748); 

                auto tg_zzzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 749); 

                auto tg_zzzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 750); 

                auto tg_zzzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 751); 

                auto tg_zzzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 752); 

                auto tg_zzzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 753); 

                auto tg_zzzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 754); 

                auto tg_zzzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 755); 

                auto tg_yyyyy_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 540); 

                auto tg_yyyyy_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 541); 

                auto tg_yyyyy_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 542); 

                auto tg_yyyyy_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 543); 

                auto tg_yyyyy_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 544); 

                auto tg_yyyyy_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 545); 

                auto tg_yyyyy_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 546); 

                auto tg_yyyyy_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 547); 

                auto tg_yyyyy_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 548); 

                auto tg_yyyyy_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 549); 

                auto tg_yyyyy_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 550); 

                auto tg_yyyyy_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 551); 

                auto tg_yyyyy_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 552); 

                auto tg_yyyyy_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 553); 

                auto tg_yyyyy_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 554); 

                auto tg_yyyyy_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 555); 

                auto tg_yyyyy_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 556); 

                auto tg_yyyyy_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 557); 

                auto tg_yyyyy_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 558); 

                auto tg_yyyyy_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 559); 

                auto tg_yyyyy_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 560); 

                auto tg_yyyyy_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 561); 

                auto tg_yyyyy_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 562); 

                auto tg_yyyyy_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 563); 

                auto tg_yyyyy_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 564); 

                auto tg_yyyyy_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 565); 

                auto tg_yyyyy_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 566); 

                auto tg_yyyyy_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 567); 

                auto tg_yyyyy_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 568); 

                auto tg_yyyyy_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 569); 

                auto tg_yyyyy_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 570); 

                auto tg_yyyyy_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 571); 

                auto tg_yyyyy_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 572); 

                auto tg_yyyyy_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 573); 

                auto tg_yyyyy_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 574); 

                auto tg_yyyyy_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 575); 

                auto tg_yyyyz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 576); 

                auto tg_yyyyz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 577); 

                auto tg_yyyyz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 578); 

                auto tg_yyyyz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 579); 

                auto tg_yyyyz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 580); 

                auto tg_yyyyz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 581); 

                auto tg_yyyyz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 582); 

                auto tg_yyyyz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 583); 

                auto tg_yyyyz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 584); 

                auto tg_yyyyz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 585); 

                auto tg_yyyyz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 586); 

                auto tg_yyyyz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 587); 

                auto tg_yyyyz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 588); 

                auto tg_yyyyz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 589); 

                auto tg_yyyyz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 590); 

                auto tg_yyyyz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 591); 

                auto tg_yyyyz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 592); 

                auto tg_yyyyz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 593); 

                auto tg_yyyyz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 594); 

                auto tg_yyyyz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 595); 

                auto tg_yyyyz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 596); 

                auto tg_yyyyz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 597); 

                auto tg_yyyyz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 598); 

                auto tg_yyyyz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 599); 

                auto tg_yyyyz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 600); 

                auto tg_yyyyz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 601); 

                auto tg_yyyyz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 602); 

                auto tg_yyyyz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 603); 

                auto tg_yyyyz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 604); 

                auto tg_yyyyz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 605); 

                auto tg_yyyyz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 606); 

                auto tg_yyyyz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 607); 

                auto tg_yyyyz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 608); 

                auto tg_yyyyz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 609); 

                auto tg_zzzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 735); 

                auto tg_zzzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 736); 

                auto tg_zzzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 737); 

                auto tg_zzzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 738); 

                auto tg_zzzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 739); 

                auto tg_zzzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 740); 

                auto tg_zzzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 741); 

                auto tg_zzzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 742); 

                auto tg_zzzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 743); 

                auto tg_zzzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 744); 

                auto tg_zzzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 745); 

                auto tg_zzzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 746); 

                auto tg_zzzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 747); 

                auto tg_zzzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 748); 

                auto tg_zzzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 749); 

                auto tg_zzzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 750); 

                auto tg_zzzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 751); 

                auto tg_zzzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 752); 

                auto tg_zzzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 753); 

                auto tg_zzzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 754); 

                auto tg_zzzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 755); 

                auto tg_yyyy_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 360); 

                auto tg_yyyy_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 361); 

                auto tg_yyyy_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 362); 

                auto tg_yyyy_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 363); 

                auto tg_yyyy_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 364); 

                auto tg_yyyy_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 365); 

                auto tg_yyyy_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 366); 

                auto tg_yyyy_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 367); 

                auto tg_yyyy_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 368); 

                auto tg_yyyy_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 369); 

                auto tg_yyyy_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 370); 

                auto tg_yyyy_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 371); 

                auto tg_yyyy_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 372); 

                auto tg_yyyy_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 373); 

                auto tg_yyyy_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 374); 

                auto tg_yyyy_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 375); 

                auto tg_yyyy_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 376); 

                auto tg_yyyy_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 377); 

                auto tg_yyyy_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 378); 

                auto tg_yyyy_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 379); 

                auto tg_yyyy_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 380); 

                auto tg_yyyy_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 381); 

                auto tg_yyyy_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 382); 

                auto tg_yyyy_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 383); 

                auto tg_yyyy_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 384); 

                auto tg_yyyy_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 385); 

                auto tg_yyyy_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 386); 

                auto tg_yyyy_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 387); 

                auto tg_yyyy_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 388); 

                auto tg_yyyy_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 389); 

                auto tg_yyyy_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 390); 

                auto tg_yyyy_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 391); 

                auto tg_yyyy_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 392); 

                auto tg_yyyy_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 393); 

                auto tg_yyyy_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 394); 

                auto tg_yyyy_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 395); 

                auto tg_yyyz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 396); 

                auto tg_yyyz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 397); 

                auto tg_yyyz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 398); 

                auto tg_yyyz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 399); 

                auto tg_yyyz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 400); 

                auto tg_yyyz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 401); 

                auto tg_yyyz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 402); 

                auto tg_yyyz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 403); 

                auto tg_yyyz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 404); 

                auto tg_yyyz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 405); 

                auto tg_yyyz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 406); 

                auto tg_yyyz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 407); 

                auto tg_yyyz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 408); 

                auto tg_yyyz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 409); 

                auto tg_yyyz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 410); 

                auto tg_yyyz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 411); 

                auto tg_yyyz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 412); 

                auto tg_yyyz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 413); 

                auto tg_yyyz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 414); 

                auto tg_yyyz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 415); 

                auto tg_yyyz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 416); 

                auto tg_yyyz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 417); 

                auto tg_yyyz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 418); 

                auto tg_yyyz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 419); 

                auto tg_yyyz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 420); 

                auto tg_yyyz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 421); 

                auto tg_yyyz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 422); 

                auto tg_yyyz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 423); 

                auto tg_yyyz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 424); 

                auto tg_yyyz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 425); 

                auto tg_yyyz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 426); 

                auto tg_yyyz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 427); 

                auto tg_yyyz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 428); 

                auto tg_yyyz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 429); 

                auto tg_yyyy_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 360); 

                auto tg_yyyy_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 361); 

                auto tg_yyyy_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 362); 

                auto tg_yyyy_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 363); 

                auto tg_yyyy_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 364); 

                auto tg_yyyy_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 365); 

                auto tg_yyyy_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 366); 

                auto tg_yyyy_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 367); 

                auto tg_yyyy_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 368); 

                auto tg_yyyy_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 369); 

                auto tg_yyyy_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 370); 

                auto tg_yyyy_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 371); 

                auto tg_yyyy_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 372); 

                auto tg_yyyy_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 373); 

                auto tg_yyyy_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 374); 

                auto tg_yyyy_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 375); 

                auto tg_yyyy_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 376); 

                auto tg_yyyy_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 377); 

                auto tg_yyyy_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 378); 

                auto tg_yyyy_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 379); 

                auto tg_yyyy_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 380); 

                auto tg_yyyy_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 381); 

                auto tg_yyyy_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 382); 

                auto tg_yyyy_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 383); 

                auto tg_yyyy_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 384); 

                auto tg_yyyy_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 385); 

                auto tg_yyyy_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 386); 

                auto tg_yyyy_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 387); 

                auto tg_yyyy_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 388); 

                auto tg_yyyy_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 389); 

                auto tg_yyyy_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 390); 

                auto tg_yyyy_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 391); 

                auto tg_yyyy_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 392); 

                auto tg_yyyy_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 393); 

                auto tg_yyyy_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 394); 

                auto tg_yyyy_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 395); 

                auto tg_yyyz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 396); 

                auto tg_yyyz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 397); 

                auto tg_yyyz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 398); 

                auto tg_yyyz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 399); 

                auto tg_yyyz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 400); 

                auto tg_yyyz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 401); 

                auto tg_yyyz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 402); 

                auto tg_yyyz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 403); 

                auto tg_yyyz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 404); 

                auto tg_yyyz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 405); 

                auto tg_yyyz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 406); 

                auto tg_yyyz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 407); 

                auto tg_yyyz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 408); 

                auto tg_yyyz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 409); 

                auto tg_yyyz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 410); 

                auto tg_yyyz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 411); 

                auto tg_yyyz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 412); 

                auto tg_yyyz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 413); 

                auto tg_yyyz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 414); 

                auto tg_yyyz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 415); 

                auto tg_yyyz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 416); 

                auto tg_yyyz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 417); 

                auto tg_yyyz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 418); 

                auto tg_yyyz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 419); 

                auto tg_yyyz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 420); 

                auto tg_yyyz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 421); 

                auto tg_yyyz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 422); 

                auto tg_yyyz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 423); 

                auto tg_yyyz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 424); 

                auto tg_yyyz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 425); 

                auto tg_yyyz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 426); 

                auto tg_yyyz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 427); 

                auto tg_yyyz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 428); 

                auto tg_yyyz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 429); 

                auto tg_yyyyy_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 420); 

                auto tg_yyyyy_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 421); 

                auto tg_yyyyy_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 422); 

                auto tg_yyyyy_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 423); 

                auto tg_yyyyy_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 424); 

                auto tg_yyyyy_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 425); 

                auto tg_yyyyy_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 426); 

                auto tg_yyyyy_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 427); 

                auto tg_yyyyy_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 428); 

                auto tg_yyyyy_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 429); 

                auto tg_yyyyy_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 430); 

                auto tg_yyyyy_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 431); 

                auto tg_yyyyy_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 432); 

                auto tg_yyyyy_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 433); 

                auto tg_yyyyy_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 434); 

                auto tg_yyyyy_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 435); 

                auto tg_yyyyy_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 436); 

                auto tg_yyyyy_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 437); 

                auto tg_yyyyy_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 438); 

                auto tg_yyyyy_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 439); 

                auto tg_yyyyy_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 440); 

                auto tg_yyyyy_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 441); 

                auto tg_yyyyy_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 442); 

                auto tg_yyyyy_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 443); 

                auto tg_yyyyy_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 444); 

                auto tg_yyyyy_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 445); 

                auto tg_yyyyy_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 446); 

                auto tg_yyyyy_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 447); 

                auto tg_yyyyz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 448); 

                auto tg_yyyyz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 449); 

                auto tg_yyyyz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 450); 

                auto tg_yyyyz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 451); 

                auto tg_yyyyz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 452); 

                auto tg_yyyyz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 453); 

                auto tg_yyyyz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 454); 

                auto tg_yyyyz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 455); 

                auto tg_yyyyz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 456); 

                auto tg_yyyyz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 457); 

                auto tg_yyyyz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 458); 

                auto tg_yyyyz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 459); 

                auto tg_yyyyz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 460); 

                auto tg_yyyyz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 461); 

                auto tg_yyyyz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 462); 

                auto tg_yyyyz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 463); 

                auto tg_yyyyz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 464); 

                auto tg_yyyyz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 465); 

                auto tg_yyyyz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 466); 

                auto tg_yyyyz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 467); 

                auto tg_yyyyz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 468); 

                auto tg_yyyyz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 469); 

                auto tg_yyyyz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 470); 

                auto tg_yyyyz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 471); 

                auto tg_yyyyz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 472); 

                auto tg_yyyyz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 473); 

                auto tg_yyyyz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 474); 

                auto tg_zzzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 575); 

                auto tg_zzzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 576); 

                auto tg_zzzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 577); 

                auto tg_zzzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 578); 

                auto tg_zzzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 579); 

                auto tg_zzzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 580); 

                auto tg_zzzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 581); 

                auto tg_zzzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 582); 

                auto tg_zzzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 583); 

                auto tg_zzzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 584); 

                auto tg_zzzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 585); 

                auto tg_zzzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 586); 

                auto tg_zzzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 587); 

                // set up pointers to integrals

                auto tg_xzzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 735); 

                auto tg_xzzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 736); 

                auto tg_xzzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 737); 

                auto tg_xzzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 738); 

                auto tg_xzzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 739); 

                auto tg_xzzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 740); 

                auto tg_xzzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 741); 

                auto tg_xzzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 742); 

                auto tg_xzzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 743); 

                auto tg_xzzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 744); 

                auto tg_xzzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 745); 

                auto tg_xzzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 746); 

                auto tg_xzzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 747); 

                auto tg_xzzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 748); 

                auto tg_xzzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 749); 

                auto tg_xzzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 750); 

                auto tg_xzzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 751); 

                auto tg_xzzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 752); 

                auto tg_xzzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 753); 

                auto tg_xzzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 754); 

                auto tg_xzzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 755); 

                auto tg_yyyyyy_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 756); 

                auto tg_yyyyyy_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 757); 

                auto tg_yyyyyy_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 758); 

                auto tg_yyyyyy_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 759); 

                auto tg_yyyyyy_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 760); 

                auto tg_yyyyyy_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 761); 

                auto tg_yyyyyy_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 762); 

                auto tg_yyyyyy_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 763); 

                auto tg_yyyyyy_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 764); 

                auto tg_yyyyyy_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 765); 

                auto tg_yyyyyy_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 766); 

                auto tg_yyyyyy_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 767); 

                auto tg_yyyyyy_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 768); 

                auto tg_yyyyyy_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 769); 

                auto tg_yyyyyy_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 770); 

                auto tg_yyyyyy_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 771); 

                auto tg_yyyyyy_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 772); 

                auto tg_yyyyyy_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 773); 

                auto tg_yyyyyy_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 774); 

                auto tg_yyyyyy_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 775); 

                auto tg_yyyyyy_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 776); 

                auto tg_yyyyyy_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 777); 

                auto tg_yyyyyy_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 778); 

                auto tg_yyyyyy_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 779); 

                auto tg_yyyyyy_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 780); 

                auto tg_yyyyyy_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 781); 

                auto tg_yyyyyy_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 782); 

                auto tg_yyyyyy_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 783); 

                auto tg_yyyyyy_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 784); 

                auto tg_yyyyyy_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 785); 

                auto tg_yyyyyy_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 786); 

                auto tg_yyyyyy_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 787); 

                auto tg_yyyyyy_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 788); 

                auto tg_yyyyyy_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 789); 

                auto tg_yyyyyy_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 790); 

                auto tg_yyyyyy_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 791); 

                auto tg_yyyyyz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 792); 

                auto tg_yyyyyz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 793); 

                auto tg_yyyyyz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 794); 

                auto tg_yyyyyz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 795); 

                auto tg_yyyyyz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 796); 

                auto tg_yyyyyz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 797); 

                auto tg_yyyyyz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 798); 

                auto tg_yyyyyz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 799); 

                auto tg_yyyyyz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 800); 

                auto tg_yyyyyz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 801); 

                auto tg_yyyyyz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 802); 

                auto tg_yyyyyz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 803); 

                auto tg_yyyyyz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 804); 

                auto tg_yyyyyz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 805); 

                auto tg_yyyyyz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 806); 

                auto tg_yyyyyz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 807); 

                auto tg_yyyyyz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 808); 

                auto tg_yyyyyz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 809); 

                auto tg_yyyyyz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 810); 

                auto tg_yyyyyz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 811); 

                auto tg_yyyyyz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 812); 

                auto tg_yyyyyz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 813); 

                auto tg_yyyyyz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 814); 

                auto tg_yyyyyz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 815); 

                auto tg_yyyyyz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 816); 

                auto tg_yyyyyz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 817); 

                auto tg_yyyyyz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 818); 

                auto tg_yyyyyz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 819); 

                auto tg_yyyyyz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 820); 

                auto tg_yyyyyz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 821); 

                auto tg_yyyyyz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 822); 

                auto tg_yyyyyz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 823); 

                auto tg_yyyyyz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 824); 

                auto tg_yyyyyz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 825); 

                // Batch of Integrals (735,826)

                #pragma omp simd aligned(fxn, fza, tg_xzzzzz_xxyyyyy_0, tg_xzzzzz_xxyyyyz_0, \
                                         tg_xzzzzz_xxyyyzz_0, tg_xzzzzz_xxyyzzz_0, tg_xzzzzz_xxyzzzz_0, tg_xzzzzz_xxzzzzz_0, \
                                         tg_xzzzzz_xyyyyyy_0, tg_xzzzzz_xyyyyyz_0, tg_xzzzzz_xyyyyzz_0, tg_xzzzzz_xyyyzzz_0, \
                                         tg_xzzzzz_xyyzzzz_0, tg_xzzzzz_xyzzzzz_0, tg_xzzzzz_xzzzzzz_0, tg_xzzzzz_yyyyyyy_0, \
                                         tg_xzzzzz_yyyyyyz_0, tg_xzzzzz_yyyyyzz_0, tg_xzzzzz_yyyyzzz_0, tg_xzzzzz_yyyzzzz_0, \
                                         tg_xzzzzz_yyzzzzz_0, tg_xzzzzz_yzzzzzz_0, tg_xzzzzz_zzzzzzz_0, tg_yyyy_xxxxxxx_0, \
                                         tg_yyyy_xxxxxxx_1, tg_yyyy_xxxxxxy_0, tg_yyyy_xxxxxxy_1, tg_yyyy_xxxxxxz_0, \
                                         tg_yyyy_xxxxxxz_1, tg_yyyy_xxxxxyy_0, tg_yyyy_xxxxxyy_1, tg_yyyy_xxxxxyz_0, \
                                         tg_yyyy_xxxxxyz_1, tg_yyyy_xxxxxzz_0, tg_yyyy_xxxxxzz_1, tg_yyyy_xxxxyyy_0, \
                                         tg_yyyy_xxxxyyy_1, tg_yyyy_xxxxyyz_0, tg_yyyy_xxxxyyz_1, tg_yyyy_xxxxyzz_0, \
                                         tg_yyyy_xxxxyzz_1, tg_yyyy_xxxxzzz_0, tg_yyyy_xxxxzzz_1, tg_yyyy_xxxyyyy_0, \
                                         tg_yyyy_xxxyyyy_1, tg_yyyy_xxxyyyz_0, tg_yyyy_xxxyyyz_1, tg_yyyy_xxxyyzz_0, \
                                         tg_yyyy_xxxyyzz_1, tg_yyyy_xxxyzzz_0, tg_yyyy_xxxyzzz_1, tg_yyyy_xxxzzzz_0, \
                                         tg_yyyy_xxxzzzz_1, tg_yyyy_xxyyyyy_0, tg_yyyy_xxyyyyy_1, tg_yyyy_xxyyyyz_0, \
                                         tg_yyyy_xxyyyyz_1, tg_yyyy_xxyyyzz_0, tg_yyyy_xxyyyzz_1, tg_yyyy_xxyyzzz_0, \
                                         tg_yyyy_xxyyzzz_1, tg_yyyy_xxyzzzz_0, tg_yyyy_xxyzzzz_1, tg_yyyy_xxzzzzz_0, \
                                         tg_yyyy_xxzzzzz_1, tg_yyyy_xyyyyyy_0, tg_yyyy_xyyyyyy_1, tg_yyyy_xyyyyyz_0, \
                                         tg_yyyy_xyyyyyz_1, tg_yyyy_xyyyyzz_0, tg_yyyy_xyyyyzz_1, tg_yyyy_xyyyzzz_0, \
                                         tg_yyyy_xyyyzzz_1, tg_yyyy_xyyzzzz_0, tg_yyyy_xyyzzzz_1, tg_yyyy_xyzzzzz_0, \
                                         tg_yyyy_xyzzzzz_1, tg_yyyy_xzzzzzz_0, tg_yyyy_xzzzzzz_1, tg_yyyy_yyyyyyy_0, \
                                         tg_yyyy_yyyyyyy_1, tg_yyyy_yyyyyyz_0, tg_yyyy_yyyyyyz_1, tg_yyyy_yyyyyzz_0, \
                                         tg_yyyy_yyyyyzz_1, tg_yyyy_yyyyzzz_0, tg_yyyy_yyyyzzz_1, tg_yyyy_yyyzzzz_0, \
                                         tg_yyyy_yyyzzzz_1, tg_yyyy_yyzzzzz_0, tg_yyyy_yyzzzzz_1, tg_yyyy_yzzzzzz_0, \
                                         tg_yyyy_yzzzzzz_1, tg_yyyy_zzzzzzz_0, tg_yyyy_zzzzzzz_1, tg_yyyyy_xxxxxx_1, \
                                         tg_yyyyy_xxxxxxx_0, tg_yyyyy_xxxxxxx_1, tg_yyyyy_xxxxxxy_0, tg_yyyyy_xxxxxxy_1, \
                                         tg_yyyyy_xxxxxxz_0, tg_yyyyy_xxxxxxz_1, tg_yyyyy_xxxxxy_1, tg_yyyyy_xxxxxyy_0, \
                                         tg_yyyyy_xxxxxyy_1, tg_yyyyy_xxxxxyz_0, tg_yyyyy_xxxxxyz_1, tg_yyyyy_xxxxxz_1, \
                                         tg_yyyyy_xxxxxzz_0, tg_yyyyy_xxxxxzz_1, tg_yyyyy_xxxxyy_1, tg_yyyyy_xxxxyyy_0, \
                                         tg_yyyyy_xxxxyyy_1, tg_yyyyy_xxxxyyz_0, tg_yyyyy_xxxxyyz_1, tg_yyyyy_xxxxyz_1, \
                                         tg_yyyyy_xxxxyzz_0, tg_yyyyy_xxxxyzz_1, tg_yyyyy_xxxxzz_1, tg_yyyyy_xxxxzzz_0, \
                                         tg_yyyyy_xxxxzzz_1, tg_yyyyy_xxxyyy_1, tg_yyyyy_xxxyyyy_0, tg_yyyyy_xxxyyyy_1, \
                                         tg_yyyyy_xxxyyyz_0, tg_yyyyy_xxxyyyz_1, tg_yyyyy_xxxyyz_1, tg_yyyyy_xxxyyzz_0, \
                                         tg_yyyyy_xxxyyzz_1, tg_yyyyy_xxxyzz_1, tg_yyyyy_xxxyzzz_0, tg_yyyyy_xxxyzzz_1, \
                                         tg_yyyyy_xxxzzz_1, tg_yyyyy_xxxzzzz_0, tg_yyyyy_xxxzzzz_1, tg_yyyyy_xxyyyy_1, \
                                         tg_yyyyy_xxyyyyy_0, tg_yyyyy_xxyyyyy_1, tg_yyyyy_xxyyyyz_0, tg_yyyyy_xxyyyyz_1, \
                                         tg_yyyyy_xxyyyz_1, tg_yyyyy_xxyyyzz_0, tg_yyyyy_xxyyyzz_1, tg_yyyyy_xxyyzz_1, \
                                         tg_yyyyy_xxyyzzz_0, tg_yyyyy_xxyyzzz_1, tg_yyyyy_xxyzzz_1, tg_yyyyy_xxyzzzz_0, \
                                         tg_yyyyy_xxyzzzz_1, tg_yyyyy_xxzzzz_1, tg_yyyyy_xxzzzzz_0, tg_yyyyy_xxzzzzz_1, \
                                         tg_yyyyy_xyyyyy_1, tg_yyyyy_xyyyyyy_0, tg_yyyyy_xyyyyyy_1, tg_yyyyy_xyyyyyz_0, \
                                         tg_yyyyy_xyyyyyz_1, tg_yyyyy_xyyyyz_1, tg_yyyyy_xyyyyzz_0, tg_yyyyy_xyyyyzz_1, \
                                         tg_yyyyy_xyyyzz_1, tg_yyyyy_xyyyzzz_0, tg_yyyyy_xyyyzzz_1, tg_yyyyy_xyyzzz_1, \
                                         tg_yyyyy_xyyzzzz_0, tg_yyyyy_xyyzzzz_1, tg_yyyyy_xyzzzz_1, tg_yyyyy_xyzzzzz_0, \
                                         tg_yyyyy_xyzzzzz_1, tg_yyyyy_xzzzzz_1, tg_yyyyy_xzzzzzz_0, tg_yyyyy_xzzzzzz_1, \
                                         tg_yyyyy_yyyyyy_1, tg_yyyyy_yyyyyyy_0, tg_yyyyy_yyyyyyy_1, tg_yyyyy_yyyyyyz_0, \
                                         tg_yyyyy_yyyyyyz_1, tg_yyyyy_yyyyyz_1, tg_yyyyy_yyyyyzz_0, tg_yyyyy_yyyyyzz_1, \
                                         tg_yyyyy_yyyyzz_1, tg_yyyyy_yyyyzzz_0, tg_yyyyy_yyyyzzz_1, tg_yyyyy_yyyzzz_1, \
                                         tg_yyyyy_yyyzzzz_0, tg_yyyyy_yyyzzzz_1, tg_yyyyy_yyzzzz_1, tg_yyyyy_yyzzzzz_0, \
                                         tg_yyyyy_yyzzzzz_1, tg_yyyyy_yzzzzz_1, tg_yyyyy_yzzzzzz_0, tg_yyyyy_yzzzzzz_1, \
                                         tg_yyyyy_zzzzzz_1, tg_yyyyy_zzzzzzz_0, tg_yyyyy_zzzzzzz_1, tg_yyyyyy_xxxxxxx_0, \
                                         tg_yyyyyy_xxxxxxy_0, tg_yyyyyy_xxxxxxz_0, tg_yyyyyy_xxxxxyy_0, tg_yyyyyy_xxxxxyz_0, \
                                         tg_yyyyyy_xxxxxzz_0, tg_yyyyyy_xxxxyyy_0, tg_yyyyyy_xxxxyyz_0, tg_yyyyyy_xxxxyzz_0, \
                                         tg_yyyyyy_xxxxzzz_0, tg_yyyyyy_xxxyyyy_0, tg_yyyyyy_xxxyyyz_0, tg_yyyyyy_xxxyyzz_0, \
                                         tg_yyyyyy_xxxyzzz_0, tg_yyyyyy_xxxzzzz_0, tg_yyyyyy_xxyyyyy_0, tg_yyyyyy_xxyyyyz_0, \
                                         tg_yyyyyy_xxyyyzz_0, tg_yyyyyy_xxyyzzz_0, tg_yyyyyy_xxyzzzz_0, tg_yyyyyy_xxzzzzz_0, \
                                         tg_yyyyyy_xyyyyyy_0, tg_yyyyyy_xyyyyyz_0, tg_yyyyyy_xyyyyzz_0, tg_yyyyyy_xyyyzzz_0, \
                                         tg_yyyyyy_xyyzzzz_0, tg_yyyyyy_xyzzzzz_0, tg_yyyyyy_xzzzzzz_0, tg_yyyyyy_yyyyyyy_0, \
                                         tg_yyyyyy_yyyyyyz_0, tg_yyyyyy_yyyyyzz_0, tg_yyyyyy_yyyyzzz_0, tg_yyyyyy_yyyzzzz_0, \
                                         tg_yyyyyy_yyzzzzz_0, tg_yyyyyy_yzzzzzz_0, tg_yyyyyy_zzzzzzz_0, tg_yyyyyz_xxxxxxx_0, \
                                         tg_yyyyyz_xxxxxxy_0, tg_yyyyyz_xxxxxxz_0, tg_yyyyyz_xxxxxyy_0, tg_yyyyyz_xxxxxyz_0, \
                                         tg_yyyyyz_xxxxxzz_0, tg_yyyyyz_xxxxyyy_0, tg_yyyyyz_xxxxyyz_0, tg_yyyyyz_xxxxyzz_0, \
                                         tg_yyyyyz_xxxxzzz_0, tg_yyyyyz_xxxyyyy_0, tg_yyyyyz_xxxyyyz_0, tg_yyyyyz_xxxyyzz_0, \
                                         tg_yyyyyz_xxxyzzz_0, tg_yyyyyz_xxxzzzz_0, tg_yyyyyz_xxyyyyy_0, tg_yyyyyz_xxyyyyz_0, \
                                         tg_yyyyyz_xxyyyzz_0, tg_yyyyyz_xxyyzzz_0, tg_yyyyyz_xxyzzzz_0, tg_yyyyyz_xxzzzzz_0, \
                                         tg_yyyyyz_xyyyyyy_0, tg_yyyyyz_xyyyyyz_0, tg_yyyyyz_xyyyyzz_0, tg_yyyyyz_xyyyzzz_0, \
                                         tg_yyyyyz_xyyzzzz_0, tg_yyyyyz_xyzzzzz_0, tg_yyyyyz_xzzzzzz_0, tg_yyyyyz_yyyyyyy_0, \
                                         tg_yyyyyz_yyyyyyz_0, tg_yyyyyz_yyyyyzz_0, tg_yyyyyz_yyyyzzz_0, tg_yyyyyz_yyyzzzz_0, \
                                         tg_yyyyyz_yyzzzzz_0, tg_yyyyz_xxxxxx_1, tg_yyyyz_xxxxxxx_0, tg_yyyyz_xxxxxxx_1, \
                                         tg_yyyyz_xxxxxxy_0, tg_yyyyz_xxxxxxy_1, tg_yyyyz_xxxxxxz_0, tg_yyyyz_xxxxxxz_1, \
                                         tg_yyyyz_xxxxxy_1, tg_yyyyz_xxxxxyy_0, tg_yyyyz_xxxxxyy_1, tg_yyyyz_xxxxxyz_0, \
                                         tg_yyyyz_xxxxxyz_1, tg_yyyyz_xxxxxz_1, tg_yyyyz_xxxxxzz_0, tg_yyyyz_xxxxxzz_1, \
                                         tg_yyyyz_xxxxyy_1, tg_yyyyz_xxxxyyy_0, tg_yyyyz_xxxxyyy_1, tg_yyyyz_xxxxyyz_0, \
                                         tg_yyyyz_xxxxyyz_1, tg_yyyyz_xxxxyz_1, tg_yyyyz_xxxxyzz_0, tg_yyyyz_xxxxyzz_1, \
                                         tg_yyyyz_xxxxzz_1, tg_yyyyz_xxxxzzz_0, tg_yyyyz_xxxxzzz_1, tg_yyyyz_xxxyyy_1, \
                                         tg_yyyyz_xxxyyyy_0, tg_yyyyz_xxxyyyy_1, tg_yyyyz_xxxyyyz_0, tg_yyyyz_xxxyyyz_1, \
                                         tg_yyyyz_xxxyyz_1, tg_yyyyz_xxxyyzz_0, tg_yyyyz_xxxyyzz_1, tg_yyyyz_xxxyzz_1, \
                                         tg_yyyyz_xxxyzzz_0, tg_yyyyz_xxxyzzz_1, tg_yyyyz_xxxzzz_1, tg_yyyyz_xxxzzzz_0, \
                                         tg_yyyyz_xxxzzzz_1, tg_yyyyz_xxyyyy_1, tg_yyyyz_xxyyyyy_0, tg_yyyyz_xxyyyyy_1, \
                                         tg_yyyyz_xxyyyyz_0, tg_yyyyz_xxyyyyz_1, tg_yyyyz_xxyyyz_1, tg_yyyyz_xxyyyzz_0, \
                                         tg_yyyyz_xxyyyzz_1, tg_yyyyz_xxyyzz_1, tg_yyyyz_xxyyzzz_0, tg_yyyyz_xxyyzzz_1, \
                                         tg_yyyyz_xxyzzz_1, tg_yyyyz_xxyzzzz_0, tg_yyyyz_xxyzzzz_1, tg_yyyyz_xxzzzz_1, \
                                         tg_yyyyz_xxzzzzz_0, tg_yyyyz_xxzzzzz_1, tg_yyyyz_xyyyyy_1, tg_yyyyz_xyyyyyy_0, \
                                         tg_yyyyz_xyyyyyy_1, tg_yyyyz_xyyyyyz_0, tg_yyyyz_xyyyyyz_1, tg_yyyyz_xyyyyz_1, \
                                         tg_yyyyz_xyyyyzz_0, tg_yyyyz_xyyyyzz_1, tg_yyyyz_xyyyzz_1, tg_yyyyz_xyyyzzz_0, \
                                         tg_yyyyz_xyyyzzz_1, tg_yyyyz_xyyzzz_1, tg_yyyyz_xyyzzzz_0, tg_yyyyz_xyyzzzz_1, \
                                         tg_yyyyz_xyzzzz_1, tg_yyyyz_xyzzzzz_0, tg_yyyyz_xyzzzzz_1, tg_yyyyz_xzzzzz_1, \
                                         tg_yyyyz_xzzzzzz_0, tg_yyyyz_xzzzzzz_1, tg_yyyyz_yyyyyy_1, tg_yyyyz_yyyyyyy_0, \
                                         tg_yyyyz_yyyyyyy_1, tg_yyyyz_yyyyyyz_0, tg_yyyyz_yyyyyyz_1, tg_yyyyz_yyyyyz_1, \
                                         tg_yyyyz_yyyyyzz_0, tg_yyyyz_yyyyyzz_1, tg_yyyyz_yyyyzz_1, tg_yyyyz_yyyyzzz_0, \
                                         tg_yyyyz_yyyyzzz_1, tg_yyyyz_yyyzzz_1, tg_yyyyz_yyyzzzz_0, tg_yyyyz_yyyzzzz_1, \
                                         tg_yyyyz_yyzzzz_1, tg_yyyyz_yyzzzzz_0, tg_yyyyz_yyzzzzz_1, tg_yyyyz_yzzzzz_1, \
                                         tg_yyyz_xxxxxxx_0, tg_yyyz_xxxxxxx_1, tg_yyyz_xxxxxxy_0, tg_yyyz_xxxxxxy_1, \
                                         tg_yyyz_xxxxxxz_0, tg_yyyz_xxxxxxz_1, tg_yyyz_xxxxxyy_0, tg_yyyz_xxxxxyy_1, \
                                         tg_yyyz_xxxxxyz_0, tg_yyyz_xxxxxyz_1, tg_yyyz_xxxxxzz_0, tg_yyyz_xxxxxzz_1, \
                                         tg_yyyz_xxxxyyy_0, tg_yyyz_xxxxyyy_1, tg_yyyz_xxxxyyz_0, tg_yyyz_xxxxyyz_1, \
                                         tg_yyyz_xxxxyzz_0, tg_yyyz_xxxxyzz_1, tg_yyyz_xxxxzzz_0, tg_yyyz_xxxxzzz_1, \
                                         tg_yyyz_xxxyyyy_0, tg_yyyz_xxxyyyy_1, tg_yyyz_xxxyyyz_0, tg_yyyz_xxxyyyz_1, \
                                         tg_yyyz_xxxyyzz_0, tg_yyyz_xxxyyzz_1, tg_yyyz_xxxyzzz_0, tg_yyyz_xxxyzzz_1, \
                                         tg_yyyz_xxxzzzz_0, tg_yyyz_xxxzzzz_1, tg_yyyz_xxyyyyy_0, tg_yyyz_xxyyyyy_1, \
                                         tg_yyyz_xxyyyyz_0, tg_yyyz_xxyyyyz_1, tg_yyyz_xxyyyzz_0, tg_yyyz_xxyyyzz_1, \
                                         tg_yyyz_xxyyzzz_0, tg_yyyz_xxyyzzz_1, tg_yyyz_xxyzzzz_0, tg_yyyz_xxyzzzz_1, \
                                         tg_yyyz_xxzzzzz_0, tg_yyyz_xxzzzzz_1, tg_yyyz_xyyyyyy_0, tg_yyyz_xyyyyyy_1, \
                                         tg_yyyz_xyyyyyz_0, tg_yyyz_xyyyyyz_1, tg_yyyz_xyyyyzz_0, tg_yyyz_xyyyyzz_1, \
                                         tg_yyyz_xyyyzzz_0, tg_yyyz_xyyyzzz_1, tg_yyyz_xyyzzzz_0, tg_yyyz_xyyzzzz_1, \
                                         tg_yyyz_xyzzzzz_0, tg_yyyz_xyzzzzz_1, tg_yyyz_xzzzzzz_0, tg_yyyz_xzzzzzz_1, \
                                         tg_yyyz_yyyyyyy_0, tg_yyyz_yyyyyyy_1, tg_yyyz_yyyyyyz_0, tg_yyyz_yyyyyyz_1, \
                                         tg_yyyz_yyyyyzz_0, tg_yyyz_yyyyyzz_1, tg_yyyz_yyyyzzz_0, tg_yyyz_yyyyzzz_1, \
                                         tg_yyyz_yyyzzzz_0, tg_yyyz_yyyzzzz_1, tg_yyyz_yyzzzzz_0, tg_yyyz_yyzzzzz_1, \
                                         tg_zzzzz_xxyyyyy_0, tg_zzzzz_xxyyyyy_1, tg_zzzzz_xxyyyyz_0, tg_zzzzz_xxyyyyz_1, \
                                         tg_zzzzz_xxyyyzz_0, tg_zzzzz_xxyyyzz_1, tg_zzzzz_xxyyzzz_0, tg_zzzzz_xxyyzzz_1, \
                                         tg_zzzzz_xxyzzzz_0, tg_zzzzz_xxyzzzz_1, tg_zzzzz_xxzzzzz_0, tg_zzzzz_xxzzzzz_1, \
                                         tg_zzzzz_xyyyyy_1, tg_zzzzz_xyyyyyy_0, tg_zzzzz_xyyyyyy_1, tg_zzzzz_xyyyyyz_0, \
                                         tg_zzzzz_xyyyyyz_1, tg_zzzzz_xyyyyz_1, tg_zzzzz_xyyyyzz_0, tg_zzzzz_xyyyyzz_1, \
                                         tg_zzzzz_xyyyzz_1, tg_zzzzz_xyyyzzz_0, tg_zzzzz_xyyyzzz_1, tg_zzzzz_xyyzzz_1, \
                                         tg_zzzzz_xyyzzzz_0, tg_zzzzz_xyyzzzz_1, tg_zzzzz_xyzzzz_1, tg_zzzzz_xyzzzzz_0, \
                                         tg_zzzzz_xyzzzzz_1, tg_zzzzz_xzzzzz_1, tg_zzzzz_xzzzzzz_0, tg_zzzzz_xzzzzzz_1, \
                                         tg_zzzzz_yyyyyy_1, tg_zzzzz_yyyyyyy_0, tg_zzzzz_yyyyyyy_1, tg_zzzzz_yyyyyyz_0, \
                                         tg_zzzzz_yyyyyyz_1, tg_zzzzz_yyyyyz_1, tg_zzzzz_yyyyyzz_0, tg_zzzzz_yyyyyzz_1, \
                                         tg_zzzzz_yyyyzz_1, tg_zzzzz_yyyyzzz_0, tg_zzzzz_yyyyzzz_1, tg_zzzzz_yyyzzz_1, \
                                         tg_zzzzz_yyyzzzz_0, tg_zzzzz_yyyzzzz_1, tg_zzzzz_yyzzzz_1, tg_zzzzz_yyzzzzz_0, \
                                         tg_zzzzz_yyzzzzz_1, tg_zzzzz_yzzzzz_1, tg_zzzzz_yzzzzzz_0, tg_zzzzz_yzzzzzz_1, \
                                         tg_zzzzz_zzzzzz_1, tg_zzzzz_zzzzzzz_0, tg_zzzzz_zzzzzzz_1, wp_x, wp_y: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_x[j]; 

                    tg_xzzzzz_xxyyyyy_0[j] = pb_x * tg_zzzzz_xxyyyyy_0[j] + fr * tg_zzzzz_xxyyyyy_1[j] + fl1_fxn * tg_zzzzz_xyyyyy_1[j];

                    tg_xzzzzz_xxyyyyz_0[j] = pb_x * tg_zzzzz_xxyyyyz_0[j] + fr * tg_zzzzz_xxyyyyz_1[j] + fl1_fxn * tg_zzzzz_xyyyyz_1[j];

                    tg_xzzzzz_xxyyyzz_0[j] = pb_x * tg_zzzzz_xxyyyzz_0[j] + fr * tg_zzzzz_xxyyyzz_1[j] + fl1_fxn * tg_zzzzz_xyyyzz_1[j];

                    tg_xzzzzz_xxyyzzz_0[j] = pb_x * tg_zzzzz_xxyyzzz_0[j] + fr * tg_zzzzz_xxyyzzz_1[j] + fl1_fxn * tg_zzzzz_xyyzzz_1[j];

                    tg_xzzzzz_xxyzzzz_0[j] = pb_x * tg_zzzzz_xxyzzzz_0[j] + fr * tg_zzzzz_xxyzzzz_1[j] + fl1_fxn * tg_zzzzz_xyzzzz_1[j];

                    tg_xzzzzz_xxzzzzz_0[j] = pb_x * tg_zzzzz_xxzzzzz_0[j] + fr * tg_zzzzz_xxzzzzz_1[j] + fl1_fxn * tg_zzzzz_xzzzzz_1[j];

                    tg_xzzzzz_xyyyyyy_0[j] = pb_x * tg_zzzzz_xyyyyyy_0[j] + fr * tg_zzzzz_xyyyyyy_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yyyyyy_1[j];

                    tg_xzzzzz_xyyyyyz_0[j] = pb_x * tg_zzzzz_xyyyyyz_0[j] + fr * tg_zzzzz_xyyyyyz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yyyyyz_1[j];

                    tg_xzzzzz_xyyyyzz_0[j] = pb_x * tg_zzzzz_xyyyyzz_0[j] + fr * tg_zzzzz_xyyyyzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yyyyzz_1[j];

                    tg_xzzzzz_xyyyzzz_0[j] = pb_x * tg_zzzzz_xyyyzzz_0[j] + fr * tg_zzzzz_xyyyzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yyyzzz_1[j];

                    tg_xzzzzz_xyyzzzz_0[j] = pb_x * tg_zzzzz_xyyzzzz_0[j] + fr * tg_zzzzz_xyyzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yyzzzz_1[j];

                    tg_xzzzzz_xyzzzzz_0[j] = pb_x * tg_zzzzz_xyzzzzz_0[j] + fr * tg_zzzzz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_yzzzzz_1[j];

                    tg_xzzzzz_xzzzzzz_0[j] = pb_x * tg_zzzzz_xzzzzzz_0[j] + fr * tg_zzzzz_xzzzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_zzzzzz_1[j];

                    tg_xzzzzz_yyyyyyy_0[j] = pb_x * tg_zzzzz_yyyyyyy_0[j] + fr * tg_zzzzz_yyyyyyy_1[j];

                    tg_xzzzzz_yyyyyyz_0[j] = pb_x * tg_zzzzz_yyyyyyz_0[j] + fr * tg_zzzzz_yyyyyyz_1[j];

                    tg_xzzzzz_yyyyyzz_0[j] = pb_x * tg_zzzzz_yyyyyzz_0[j] + fr * tg_zzzzz_yyyyyzz_1[j];

                    tg_xzzzzz_yyyyzzz_0[j] = pb_x * tg_zzzzz_yyyyzzz_0[j] + fr * tg_zzzzz_yyyyzzz_1[j];

                    tg_xzzzzz_yyyzzzz_0[j] = pb_x * tg_zzzzz_yyyzzzz_0[j] + fr * tg_zzzzz_yyyzzzz_1[j];

                    tg_xzzzzz_yyzzzzz_0[j] = pb_x * tg_zzzzz_yyzzzzz_0[j] + fr * tg_zzzzz_yyzzzzz_1[j];

                    tg_xzzzzz_yzzzzzz_0[j] = pb_x * tg_zzzzz_yzzzzzz_0[j] + fr * tg_zzzzz_yzzzzzz_1[j];

                    tg_xzzzzz_zzzzzzz_0[j] = pb_x * tg_zzzzz_zzzzzzz_0[j] + fr * tg_zzzzz_zzzzzzz_1[j];

                    fr = wp_y[j]; 

                    tg_yyyyyy_xxxxxxx_0[j] = pb_y * tg_yyyyy_xxxxxxx_0[j] + fr * tg_yyyyy_xxxxxxx_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxxx_0[j] - tg_yyyy_xxxxxxx_1[j] * fl1_fza);

                    tg_yyyyyy_xxxxxxy_0[j] = pb_y * tg_yyyyy_xxxxxxy_0[j] + fr * tg_yyyyy_xxxxxxy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxxy_0[j] - tg_yyyy_xxxxxxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xxxxxx_1[j];

                    tg_yyyyyy_xxxxxxz_0[j] = pb_y * tg_yyyyy_xxxxxxz_0[j] + fr * tg_yyyyy_xxxxxxz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxxz_0[j] - tg_yyyy_xxxxxxz_1[j] * fl1_fza);

                    tg_yyyyyy_xxxxxyy_0[j] = pb_y * tg_yyyyy_xxxxxyy_0[j] + fr * tg_yyyyy_xxxxxyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxyy_0[j] - tg_yyyy_xxxxxyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xxxxxy_1[j];

                    tg_yyyyyy_xxxxxyz_0[j] = pb_y * tg_yyyyy_xxxxxyz_0[j] + fr * tg_yyyyy_xxxxxyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxyz_0[j] - tg_yyyy_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xxxxxz_1[j];

                    tg_yyyyyy_xxxxxzz_0[j] = pb_y * tg_yyyyy_xxxxxzz_0[j] + fr * tg_yyyyy_xxxxxzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxxzz_0[j] - tg_yyyy_xxxxxzz_1[j] * fl1_fza);

                    tg_yyyyyy_xxxxyyy_0[j] = pb_y * tg_yyyyy_xxxxyyy_0[j] + fr * tg_yyyyy_xxxxyyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxyyy_0[j] - tg_yyyy_xxxxyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_xxxxyy_1[j];

                    tg_yyyyyy_xxxxyyz_0[j] = pb_y * tg_yyyyy_xxxxyyz_0[j] + fr * tg_yyyyy_xxxxyyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxyyz_0[j] - tg_yyyy_xxxxyyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xxxxyz_1[j];

                    tg_yyyyyy_xxxxyzz_0[j] = pb_y * tg_yyyyy_xxxxyzz_0[j] + fr * tg_yyyyy_xxxxyzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxyzz_0[j] - tg_yyyy_xxxxyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xxxxzz_1[j];

                    tg_yyyyyy_xxxxzzz_0[j] = pb_y * tg_yyyyy_xxxxzzz_0[j] + fr * tg_yyyyy_xxxxzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxxzzz_0[j] - tg_yyyy_xxxxzzz_1[j] * fl1_fza);

                    tg_yyyyyy_xxxyyyy_0[j] = pb_y * tg_yyyyy_xxxyyyy_0[j] + fr * tg_yyyyy_xxxyyyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxyyyy_0[j] - tg_yyyy_xxxyyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyy_xxxyyy_1[j];

                    tg_yyyyyy_xxxyyyz_0[j] = pb_y * tg_yyyyy_xxxyyyz_0[j] + fr * tg_yyyyy_xxxyyyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxyyyz_0[j] - tg_yyyy_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_xxxyyz_1[j];

                    tg_yyyyyy_xxxyyzz_0[j] = pb_y * tg_yyyyy_xxxyyzz_0[j] + fr * tg_yyyyy_xxxyyzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxyyzz_0[j] - tg_yyyy_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xxxyzz_1[j];

                    tg_yyyyyy_xxxyzzz_0[j] = pb_y * tg_yyyyy_xxxyzzz_0[j] + fr * tg_yyyyy_xxxyzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxyzzz_0[j] - tg_yyyy_xxxyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xxxzzz_1[j];

                    tg_yyyyyy_xxxzzzz_0[j] = pb_y * tg_yyyyy_xxxzzzz_0[j] + fr * tg_yyyyy_xxxzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxxzzzz_0[j] - tg_yyyy_xxxzzzz_1[j] * fl1_fza);

                    tg_yyyyyy_xxyyyyy_0[j] = pb_y * tg_yyyyy_xxyyyyy_0[j] + fr * tg_yyyyy_xxyyyyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxyyyyy_0[j] - tg_yyyy_xxyyyyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyy_xxyyyy_1[j];

                    tg_yyyyyy_xxyyyyz_0[j] = pb_y * tg_yyyyy_xxyyyyz_0[j] + fr * tg_yyyyy_xxyyyyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxyyyyz_0[j] - tg_yyyy_xxyyyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyy_xxyyyz_1[j];

                    tg_yyyyyy_xxyyyzz_0[j] = pb_y * tg_yyyyy_xxyyyzz_0[j] + fr * tg_yyyyy_xxyyyzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxyyyzz_0[j] - tg_yyyy_xxyyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_xxyyzz_1[j];

                    tg_yyyyyy_xxyyzzz_0[j] = pb_y * tg_yyyyy_xxyyzzz_0[j] + fr * tg_yyyyy_xxyyzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxyyzzz_0[j] - tg_yyyy_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xxyzzz_1[j];

                    tg_yyyyyy_xxyzzzz_0[j] = pb_y * tg_yyyyy_xxyzzzz_0[j] + fr * tg_yyyyy_xxyzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxyzzzz_0[j] - tg_yyyy_xxyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xxzzzz_1[j];

                    tg_yyyyyy_xxzzzzz_0[j] = pb_y * tg_yyyyy_xxzzzzz_0[j] + fr * tg_yyyyy_xxzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xxzzzzz_0[j] - tg_yyyy_xxzzzzz_1[j] * fl1_fza);

                    tg_yyyyyy_xyyyyyy_0[j] = pb_y * tg_yyyyy_xyyyyyy_0[j] + fr * tg_yyyyy_xyyyyyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyyyyyy_0[j] - tg_yyyy_xyyyyyy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyyy_xyyyyy_1[j];

                    tg_yyyyyy_xyyyyyz_0[j] = pb_y * tg_yyyyy_xyyyyyz_0[j] + fr * tg_yyyyy_xyyyyyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyyyyyz_0[j] - tg_yyyy_xyyyyyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyy_xyyyyz_1[j];

                    tg_yyyyyy_xyyyyzz_0[j] = pb_y * tg_yyyyy_xyyyyzz_0[j] + fr * tg_yyyyy_xyyyyzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyyyyzz_0[j] - tg_yyyy_xyyyyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyy_xyyyzz_1[j];

                    tg_yyyyyy_xyyyzzz_0[j] = pb_y * tg_yyyyy_xyyyzzz_0[j] + fr * tg_yyyyy_xyyyzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyyyzzz_0[j] - tg_yyyy_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_xyyzzz_1[j];

                    tg_yyyyyy_xyyzzzz_0[j] = pb_y * tg_yyyyy_xyyzzzz_0[j] + fr * tg_yyyyy_xyyzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyyzzzz_0[j] - tg_yyyy_xyyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_xyzzzz_1[j];

                    tg_yyyyyy_xyzzzzz_0[j] = pb_y * tg_yyyyy_xyzzzzz_0[j] + fr * tg_yyyyy_xyzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xyzzzzz_0[j] - tg_yyyy_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_xzzzzz_1[j];

                    tg_yyyyyy_xzzzzzz_0[j] = pb_y * tg_yyyyy_xzzzzzz_0[j] + fr * tg_yyyyy_xzzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_xzzzzzz_0[j] - tg_yyyy_xzzzzzz_1[j] * fl1_fza);

                    tg_yyyyyy_yyyyyyy_0[j] = pb_y * tg_yyyyy_yyyyyyy_0[j] + fr * tg_yyyyy_yyyyyyy_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyyyyyy_0[j] - tg_yyyy_yyyyyyy_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_yyyyy_yyyyyy_1[j];

                    tg_yyyyyy_yyyyyyz_0[j] = pb_y * tg_yyyyy_yyyyyyz_0[j] + fr * tg_yyyyy_yyyyyyz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyyyyyz_0[j] - tg_yyyy_yyyyyyz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyyy_yyyyyz_1[j];

                    tg_yyyyyy_yyyyyzz_0[j] = pb_y * tg_yyyyy_yyyyyzz_0[j] + fr * tg_yyyyy_yyyyyzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyyyyzz_0[j] - tg_yyyy_yyyyyzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyy_yyyyzz_1[j];

                    tg_yyyyyy_yyyyzzz_0[j] = pb_y * tg_yyyyy_yyyyzzz_0[j] + fr * tg_yyyyy_yyyyzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyyyzzz_0[j] - tg_yyyy_yyyyzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyy_yyyzzz_1[j];

                    tg_yyyyyy_yyyzzzz_0[j] = pb_y * tg_yyyyy_yyyzzzz_0[j] + fr * tg_yyyyy_yyyzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyyzzzz_0[j] - tg_yyyy_yyyzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyy_yyzzzz_1[j];

                    tg_yyyyyy_yyzzzzz_0[j] = pb_y * tg_yyyyy_yyzzzzz_0[j] + fr * tg_yyyyy_yyzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yyzzzzz_0[j] - tg_yyyy_yyzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyy_yzzzzz_1[j];

                    tg_yyyyyy_yzzzzzz_0[j] = pb_y * tg_yyyyy_yzzzzzz_0[j] + fr * tg_yyyyy_yzzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_yzzzzzz_0[j] - tg_yyyy_yzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyy_zzzzzz_1[j];

                    tg_yyyyyy_zzzzzzz_0[j] = pb_y * tg_yyyyy_zzzzzzz_0[j] + fr * tg_yyyyy_zzzzzzz_1[j] + 2.5 * fl1_fx * (tg_yyyy_zzzzzzz_0[j] - tg_yyyy_zzzzzzz_1[j] * fl1_fza);

                    tg_yyyyyz_xxxxxxx_0[j] = pb_y * tg_yyyyz_xxxxxxx_0[j] + fr * tg_yyyyz_xxxxxxx_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxxx_0[j] - tg_yyyz_xxxxxxx_1[j] * fl1_fza);

                    tg_yyyyyz_xxxxxxy_0[j] = pb_y * tg_yyyyz_xxxxxxy_0[j] + fr * tg_yyyyz_xxxxxxy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxxy_0[j] - tg_yyyz_xxxxxxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xxxxxx_1[j];

                    tg_yyyyyz_xxxxxxz_0[j] = pb_y * tg_yyyyz_xxxxxxz_0[j] + fr * tg_yyyyz_xxxxxxz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxxz_0[j] - tg_yyyz_xxxxxxz_1[j] * fl1_fza);

                    tg_yyyyyz_xxxxxyy_0[j] = pb_y * tg_yyyyz_xxxxxyy_0[j] + fr * tg_yyyyz_xxxxxyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxyy_0[j] - tg_yyyz_xxxxxyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xxxxxy_1[j];

                    tg_yyyyyz_xxxxxyz_0[j] = pb_y * tg_yyyyz_xxxxxyz_0[j] + fr * tg_yyyyz_xxxxxyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxyz_0[j] - tg_yyyz_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xxxxxz_1[j];

                    tg_yyyyyz_xxxxxzz_0[j] = pb_y * tg_yyyyz_xxxxxzz_0[j] + fr * tg_yyyyz_xxxxxzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxxzz_0[j] - tg_yyyz_xxxxxzz_1[j] * fl1_fza);

                    tg_yyyyyz_xxxxyyy_0[j] = pb_y * tg_yyyyz_xxxxyyy_0[j] + fr * tg_yyyyz_xxxxyyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxyyy_0[j] - tg_yyyz_xxxxyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_xxxxyy_1[j];

                    tg_yyyyyz_xxxxyyz_0[j] = pb_y * tg_yyyyz_xxxxyyz_0[j] + fr * tg_yyyyz_xxxxyyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxyyz_0[j] - tg_yyyz_xxxxyyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xxxxyz_1[j];

                    tg_yyyyyz_xxxxyzz_0[j] = pb_y * tg_yyyyz_xxxxyzz_0[j] + fr * tg_yyyyz_xxxxyzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxyzz_0[j] - tg_yyyz_xxxxyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xxxxzz_1[j];

                    tg_yyyyyz_xxxxzzz_0[j] = pb_y * tg_yyyyz_xxxxzzz_0[j] + fr * tg_yyyyz_xxxxzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxxzzz_0[j] - tg_yyyz_xxxxzzz_1[j] * fl1_fza);

                    tg_yyyyyz_xxxyyyy_0[j] = pb_y * tg_yyyyz_xxxyyyy_0[j] + fr * tg_yyyyz_xxxyyyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxyyyy_0[j] - tg_yyyz_xxxyyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyz_xxxyyy_1[j];

                    tg_yyyyyz_xxxyyyz_0[j] = pb_y * tg_yyyyz_xxxyyyz_0[j] + fr * tg_yyyyz_xxxyyyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxyyyz_0[j] - tg_yyyz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_xxxyyz_1[j];

                    tg_yyyyyz_xxxyyzz_0[j] = pb_y * tg_yyyyz_xxxyyzz_0[j] + fr * tg_yyyyz_xxxyyzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxyyzz_0[j] - tg_yyyz_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xxxyzz_1[j];

                    tg_yyyyyz_xxxyzzz_0[j] = pb_y * tg_yyyyz_xxxyzzz_0[j] + fr * tg_yyyyz_xxxyzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxyzzz_0[j] - tg_yyyz_xxxyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xxxzzz_1[j];

                    tg_yyyyyz_xxxzzzz_0[j] = pb_y * tg_yyyyz_xxxzzzz_0[j] + fr * tg_yyyyz_xxxzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxxzzzz_0[j] - tg_yyyz_xxxzzzz_1[j] * fl1_fza);

                    tg_yyyyyz_xxyyyyy_0[j] = pb_y * tg_yyyyz_xxyyyyy_0[j] + fr * tg_yyyyz_xxyyyyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxyyyyy_0[j] - tg_yyyz_xxyyyyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyz_xxyyyy_1[j];

                    tg_yyyyyz_xxyyyyz_0[j] = pb_y * tg_yyyyz_xxyyyyz_0[j] + fr * tg_yyyyz_xxyyyyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxyyyyz_0[j] - tg_yyyz_xxyyyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyz_xxyyyz_1[j];

                    tg_yyyyyz_xxyyyzz_0[j] = pb_y * tg_yyyyz_xxyyyzz_0[j] + fr * tg_yyyyz_xxyyyzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxyyyzz_0[j] - tg_yyyz_xxyyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_xxyyzz_1[j];

                    tg_yyyyyz_xxyyzzz_0[j] = pb_y * tg_yyyyz_xxyyzzz_0[j] + fr * tg_yyyyz_xxyyzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxyyzzz_0[j] - tg_yyyz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xxyzzz_1[j];

                    tg_yyyyyz_xxyzzzz_0[j] = pb_y * tg_yyyyz_xxyzzzz_0[j] + fr * tg_yyyyz_xxyzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxyzzzz_0[j] - tg_yyyz_xxyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xxzzzz_1[j];

                    tg_yyyyyz_xxzzzzz_0[j] = pb_y * tg_yyyyz_xxzzzzz_0[j] + fr * tg_yyyyz_xxzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xxzzzzz_0[j] - tg_yyyz_xxzzzzz_1[j] * fl1_fza);

                    tg_yyyyyz_xyyyyyy_0[j] = pb_y * tg_yyyyz_xyyyyyy_0[j] + fr * tg_yyyyz_xyyyyyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyyyyyy_0[j] - tg_yyyz_xyyyyyy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyyz_xyyyyy_1[j];

                    tg_yyyyyz_xyyyyyz_0[j] = pb_y * tg_yyyyz_xyyyyyz_0[j] + fr * tg_yyyyz_xyyyyyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyyyyyz_0[j] - tg_yyyz_xyyyyyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyz_xyyyyz_1[j];

                    tg_yyyyyz_xyyyyzz_0[j] = pb_y * tg_yyyyz_xyyyyzz_0[j] + fr * tg_yyyyz_xyyyyzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyyyyzz_0[j] - tg_yyyz_xyyyyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyz_xyyyzz_1[j];

                    tg_yyyyyz_xyyyzzz_0[j] = pb_y * tg_yyyyz_xyyyzzz_0[j] + fr * tg_yyyyz_xyyyzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyyyzzz_0[j] - tg_yyyz_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_xyyzzz_1[j];

                    tg_yyyyyz_xyyzzzz_0[j] = pb_y * tg_yyyyz_xyyzzzz_0[j] + fr * tg_yyyyz_xyyzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyyzzzz_0[j] - tg_yyyz_xyyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_xyzzzz_1[j];

                    tg_yyyyyz_xyzzzzz_0[j] = pb_y * tg_yyyyz_xyzzzzz_0[j] + fr * tg_yyyyz_xyzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xyzzzzz_0[j] - tg_yyyz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_xzzzzz_1[j];

                    tg_yyyyyz_xzzzzzz_0[j] = pb_y * tg_yyyyz_xzzzzzz_0[j] + fr * tg_yyyyz_xzzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_xzzzzzz_0[j] - tg_yyyz_xzzzzzz_1[j] * fl1_fza);

                    tg_yyyyyz_yyyyyyy_0[j] = pb_y * tg_yyyyz_yyyyyyy_0[j] + fr * tg_yyyyz_yyyyyyy_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyyyyyy_0[j] - tg_yyyz_yyyyyyy_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_yyyyz_yyyyyy_1[j];

                    tg_yyyyyz_yyyyyyz_0[j] = pb_y * tg_yyyyz_yyyyyyz_0[j] + fr * tg_yyyyz_yyyyyyz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyyyyyz_0[j] - tg_yyyz_yyyyyyz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyyz_yyyyyz_1[j];

                    tg_yyyyyz_yyyyyzz_0[j] = pb_y * tg_yyyyz_yyyyyzz_0[j] + fr * tg_yyyyz_yyyyyzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyyyyzz_0[j] - tg_yyyz_yyyyyzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyyz_yyyyzz_1[j];

                    tg_yyyyyz_yyyyzzz_0[j] = pb_y * tg_yyyyz_yyyyzzz_0[j] + fr * tg_yyyyz_yyyyzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyyyzzz_0[j] - tg_yyyz_yyyyzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyyz_yyyzzz_1[j];

                    tg_yyyyyz_yyyzzzz_0[j] = pb_y * tg_yyyyz_yyyzzzz_0[j] + fr * tg_yyyyz_yyyzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyyzzzz_0[j] - tg_yyyz_yyyzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyyz_yyzzzz_1[j];

                    tg_yyyyyz_yyzzzzz_0[j] = pb_y * tg_yyyyz_yyzzzzz_0[j] + fr * tg_yyyyz_yyzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yyzzzzz_0[j] - tg_yyyz_yyzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyyz_yzzzzz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_826_917(      CMemBlock2D<double>* primBuffer,
                                         const CRecursionMap&       recursionMap,
                                         const CMemBlock2D<double>& osFactors,
                                         const CMemBlock2D<double>& wpDistances,
                                         const CGtoPairsBlock&      braGtoPairsBlock,
                                         const CGtoPairsBlock&      ketGtoPairsBlock,
                                         const int32_t              nKetPrimPairs,
                                         const int32_t              iContrPair)
    {
        // Batch of Integrals (826,917)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_y = braGtoPairsBlock.getDistancesPBY();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto pb_y = r_pb_y[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_y = wpDistances.data(3 * idx + 1);

                // set up pointers to auxilary integrals

                auto tg_yyyyz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 610); 

                auto tg_yyyyz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 611); 

                auto tg_yyyzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 612); 

                auto tg_yyyzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 613); 

                auto tg_yyyzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 614); 

                auto tg_yyyzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 615); 

                auto tg_yyyzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 616); 

                auto tg_yyyzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 617); 

                auto tg_yyyzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 618); 

                auto tg_yyyzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 619); 

                auto tg_yyyzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 620); 

                auto tg_yyyzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 621); 

                auto tg_yyyzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 622); 

                auto tg_yyyzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 623); 

                auto tg_yyyzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 624); 

                auto tg_yyyzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 625); 

                auto tg_yyyzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 626); 

                auto tg_yyyzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 627); 

                auto tg_yyyzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 628); 

                auto tg_yyyzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 629); 

                auto tg_yyyzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 630); 

                auto tg_yyyzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 631); 

                auto tg_yyyzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 632); 

                auto tg_yyyzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 633); 

                auto tg_yyyzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 634); 

                auto tg_yyyzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 635); 

                auto tg_yyyzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 636); 

                auto tg_yyyzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 637); 

                auto tg_yyyzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 638); 

                auto tg_yyyzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 639); 

                auto tg_yyyzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 640); 

                auto tg_yyyzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 641); 

                auto tg_yyyzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 642); 

                auto tg_yyyzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 643); 

                auto tg_yyyzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 644); 

                auto tg_yyyzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 645); 

                auto tg_yyyzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 646); 

                auto tg_yyyzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 647); 

                auto tg_yyzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 648); 

                auto tg_yyzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 649); 

                auto tg_yyzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 650); 

                auto tg_yyzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 651); 

                auto tg_yyzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 652); 

                auto tg_yyzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 653); 

                auto tg_yyzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 654); 

                auto tg_yyzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 655); 

                auto tg_yyzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 656); 

                auto tg_yyzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 657); 

                auto tg_yyzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 658); 

                auto tg_yyzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 659); 

                auto tg_yyzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 660); 

                auto tg_yyzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 661); 

                auto tg_yyzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 662); 

                auto tg_yyzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 663); 

                auto tg_yyzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 664); 

                auto tg_yyzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 665); 

                auto tg_yyzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 666); 

                auto tg_yyzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 667); 

                auto tg_yyzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 668); 

                auto tg_yyzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 669); 

                auto tg_yyzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 670); 

                auto tg_yyzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 671); 

                auto tg_yyzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 672); 

                auto tg_yyzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 673); 

                auto tg_yyzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 674); 

                auto tg_yyzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 675); 

                auto tg_yyzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 676); 

                auto tg_yyzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 677); 

                auto tg_yyzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 678); 

                auto tg_yyzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 679); 

                auto tg_yyzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 680); 

                auto tg_yyzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 681); 

                auto tg_yyzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 682); 

                auto tg_yyzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 683); 

                auto tg_yzzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 684); 

                auto tg_yzzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 685); 

                auto tg_yzzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 686); 

                auto tg_yzzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 687); 

                auto tg_yzzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 688); 

                auto tg_yzzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 689); 

                auto tg_yzzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 690); 

                auto tg_yzzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 691); 

                auto tg_yzzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 692); 

                auto tg_yzzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 693); 

                auto tg_yzzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 694); 

                auto tg_yzzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 695); 

                auto tg_yzzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 696); 

                auto tg_yzzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 697); 

                auto tg_yzzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 698); 

                auto tg_yzzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 699); 

                auto tg_yzzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 700); 

                auto tg_yyyyz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 610); 

                auto tg_yyyyz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 611); 

                auto tg_yyyzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 612); 

                auto tg_yyyzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 613); 

                auto tg_yyyzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 614); 

                auto tg_yyyzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 615); 

                auto tg_yyyzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 616); 

                auto tg_yyyzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 617); 

                auto tg_yyyzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 618); 

                auto tg_yyyzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 619); 

                auto tg_yyyzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 620); 

                auto tg_yyyzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 621); 

                auto tg_yyyzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 622); 

                auto tg_yyyzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 623); 

                auto tg_yyyzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 624); 

                auto tg_yyyzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 625); 

                auto tg_yyyzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 626); 

                auto tg_yyyzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 627); 

                auto tg_yyyzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 628); 

                auto tg_yyyzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 629); 

                auto tg_yyyzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 630); 

                auto tg_yyyzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 631); 

                auto tg_yyyzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 632); 

                auto tg_yyyzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 633); 

                auto tg_yyyzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 634); 

                auto tg_yyyzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 635); 

                auto tg_yyyzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 636); 

                auto tg_yyyzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 637); 

                auto tg_yyyzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 638); 

                auto tg_yyyzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 639); 

                auto tg_yyyzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 640); 

                auto tg_yyyzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 641); 

                auto tg_yyyzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 642); 

                auto tg_yyyzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 643); 

                auto tg_yyyzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 644); 

                auto tg_yyyzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 645); 

                auto tg_yyyzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 646); 

                auto tg_yyyzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 647); 

                auto tg_yyzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 648); 

                auto tg_yyzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 649); 

                auto tg_yyzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 650); 

                auto tg_yyzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 651); 

                auto tg_yyzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 652); 

                auto tg_yyzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 653); 

                auto tg_yyzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 654); 

                auto tg_yyzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 655); 

                auto tg_yyzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 656); 

                auto tg_yyzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 657); 

                auto tg_yyzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 658); 

                auto tg_yyzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 659); 

                auto tg_yyzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 660); 

                auto tg_yyzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 661); 

                auto tg_yyzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 662); 

                auto tg_yyzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 663); 

                auto tg_yyzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 664); 

                auto tg_yyzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 665); 

                auto tg_yyzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 666); 

                auto tg_yyzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 667); 

                auto tg_yyzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 668); 

                auto tg_yyzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 669); 

                auto tg_yyzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 670); 

                auto tg_yyzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 671); 

                auto tg_yyzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 672); 

                auto tg_yyzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 673); 

                auto tg_yyzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 674); 

                auto tg_yyzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 675); 

                auto tg_yyzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 676); 

                auto tg_yyzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 677); 

                auto tg_yyzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 678); 

                auto tg_yyzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 679); 

                auto tg_yyzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 680); 

                auto tg_yyzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 681); 

                auto tg_yyzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 682); 

                auto tg_yyzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 683); 

                auto tg_yzzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 684); 

                auto tg_yzzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 685); 

                auto tg_yzzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 686); 

                auto tg_yzzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 687); 

                auto tg_yzzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 688); 

                auto tg_yzzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 689); 

                auto tg_yzzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 690); 

                auto tg_yzzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 691); 

                auto tg_yzzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 692); 

                auto tg_yzzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 693); 

                auto tg_yzzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 694); 

                auto tg_yzzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 695); 

                auto tg_yzzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 696); 

                auto tg_yzzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 697); 

                auto tg_yzzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 698); 

                auto tg_yzzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 699); 

                auto tg_yzzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 700); 

                auto tg_yyyz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 430); 

                auto tg_yyyz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 431); 

                auto tg_yyzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 432); 

                auto tg_yyzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 433); 

                auto tg_yyzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 434); 

                auto tg_yyzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 435); 

                auto tg_yyzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 436); 

                auto tg_yyzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 437); 

                auto tg_yyzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 438); 

                auto tg_yyzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 439); 

                auto tg_yyzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 440); 

                auto tg_yyzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 441); 

                auto tg_yyzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 442); 

                auto tg_yyzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 443); 

                auto tg_yyzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 444); 

                auto tg_yyzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 445); 

                auto tg_yyzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 446); 

                auto tg_yyzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 447); 

                auto tg_yyzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 448); 

                auto tg_yyzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 449); 

                auto tg_yyzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 450); 

                auto tg_yyzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 451); 

                auto tg_yyzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 452); 

                auto tg_yyzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 453); 

                auto tg_yyzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 454); 

                auto tg_yyzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 455); 

                auto tg_yyzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 456); 

                auto tg_yyzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 457); 

                auto tg_yyzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 458); 

                auto tg_yyzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 459); 

                auto tg_yyzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 460); 

                auto tg_yyzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 461); 

                auto tg_yyzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 462); 

                auto tg_yyzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 463); 

                auto tg_yyzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 464); 

                auto tg_yyzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 465); 

                auto tg_yyzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 466); 

                auto tg_yyzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 467); 

                auto tg_yzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 468); 

                auto tg_yzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 469); 

                auto tg_yzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 470); 

                auto tg_yzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 471); 

                auto tg_yzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 472); 

                auto tg_yzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 473); 

                auto tg_yzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 474); 

                auto tg_yzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 475); 

                auto tg_yzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 476); 

                auto tg_yzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 477); 

                auto tg_yzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 478); 

                auto tg_yzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 479); 

                auto tg_yzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 480); 

                auto tg_yzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 481); 

                auto tg_yzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 482); 

                auto tg_yzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 483); 

                auto tg_yzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 484); 

                auto tg_yzzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 485); 

                auto tg_yzzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 486); 

                auto tg_yzzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 487); 

                auto tg_yzzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 488); 

                auto tg_yzzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 489); 

                auto tg_yzzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 490); 

                auto tg_yzzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 491); 

                auto tg_yzzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 492); 

                auto tg_yzzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 493); 

                auto tg_yzzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 494); 

                auto tg_yzzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 495); 

                auto tg_yzzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 496); 

                auto tg_yzzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 497); 

                auto tg_yzzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 498); 

                auto tg_yzzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 499); 

                auto tg_yzzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 500); 

                auto tg_yzzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 501); 

                auto tg_yzzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 502); 

                auto tg_yzzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 503); 

                auto tg_zzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 520); 

                auto tg_yyyz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 430); 

                auto tg_yyyz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 431); 

                auto tg_yyzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 432); 

                auto tg_yyzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 433); 

                auto tg_yyzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 434); 

                auto tg_yyzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 435); 

                auto tg_yyzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 436); 

                auto tg_yyzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 437); 

                auto tg_yyzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 438); 

                auto tg_yyzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 439); 

                auto tg_yyzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 440); 

                auto tg_yyzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 441); 

                auto tg_yyzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 442); 

                auto tg_yyzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 443); 

                auto tg_yyzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 444); 

                auto tg_yyzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 445); 

                auto tg_yyzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 446); 

                auto tg_yyzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 447); 

                auto tg_yyzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 448); 

                auto tg_yyzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 449); 

                auto tg_yyzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 450); 

                auto tg_yyzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 451); 

                auto tg_yyzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 452); 

                auto tg_yyzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 453); 

                auto tg_yyzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 454); 

                auto tg_yyzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 455); 

                auto tg_yyzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 456); 

                auto tg_yyzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 457); 

                auto tg_yyzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 458); 

                auto tg_yyzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 459); 

                auto tg_yyzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 460); 

                auto tg_yyzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 461); 

                auto tg_yyzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 462); 

                auto tg_yyzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 463); 

                auto tg_yyzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 464); 

                auto tg_yyzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 465); 

                auto tg_yyzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 466); 

                auto tg_yyzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 467); 

                auto tg_yzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 468); 

                auto tg_yzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 469); 

                auto tg_yzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 470); 

                auto tg_yzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 471); 

                auto tg_yzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 472); 

                auto tg_yzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 473); 

                auto tg_yzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 474); 

                auto tg_yzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 475); 

                auto tg_yzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 476); 

                auto tg_yzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 477); 

                auto tg_yzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 478); 

                auto tg_yzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 479); 

                auto tg_yzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 480); 

                auto tg_yzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 481); 

                auto tg_yzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 482); 

                auto tg_yzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 483); 

                auto tg_yzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 484); 

                auto tg_yzzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 485); 

                auto tg_yzzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 486); 

                auto tg_yzzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 487); 

                auto tg_yzzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 488); 

                auto tg_yzzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 489); 

                auto tg_yzzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 490); 

                auto tg_yzzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 491); 

                auto tg_yzzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 492); 

                auto tg_yzzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 493); 

                auto tg_yzzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 494); 

                auto tg_yzzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 495); 

                auto tg_yzzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 496); 

                auto tg_yzzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 497); 

                auto tg_yzzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 498); 

                auto tg_yzzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 499); 

                auto tg_yzzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 500); 

                auto tg_yzzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 501); 

                auto tg_yzzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 502); 

                auto tg_yzzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 503); 

                auto tg_zzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 520); 

                auto tg_yyyyz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 475); 

                auto tg_yyyzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 476); 

                auto tg_yyyzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 477); 

                auto tg_yyyzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 478); 

                auto tg_yyyzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 479); 

                auto tg_yyyzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 480); 

                auto tg_yyyzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 481); 

                auto tg_yyyzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 482); 

                auto tg_yyyzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 483); 

                auto tg_yyyzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 484); 

                auto tg_yyyzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 485); 

                auto tg_yyyzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 486); 

                auto tg_yyyzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 487); 

                auto tg_yyyzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 488); 

                auto tg_yyyzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 489); 

                auto tg_yyyzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 490); 

                auto tg_yyyzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 491); 

                auto tg_yyyzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 492); 

                auto tg_yyyzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 493); 

                auto tg_yyyzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 494); 

                auto tg_yyyzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 495); 

                auto tg_yyyzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 496); 

                auto tg_yyyzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 497); 

                auto tg_yyyzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 498); 

                auto tg_yyyzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 499); 

                auto tg_yyyzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 500); 

                auto tg_yyyzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 501); 

                auto tg_yyyzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 502); 

                auto tg_yyyzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 503); 

                auto tg_yyzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 504); 

                auto tg_yyzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 505); 

                auto tg_yyzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 506); 

                auto tg_yyzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 507); 

                auto tg_yyzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 508); 

                auto tg_yyzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 509); 

                auto tg_yyzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 510); 

                auto tg_yyzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 511); 

                auto tg_yyzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 512); 

                auto tg_yyzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 513); 

                auto tg_yyzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 514); 

                auto tg_yyzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 515); 

                auto tg_yyzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 516); 

                auto tg_yyzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 517); 

                auto tg_yyzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 518); 

                auto tg_yyzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 519); 

                auto tg_yyzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 520); 

                auto tg_yyzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 521); 

                auto tg_yyzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 522); 

                auto tg_yyzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 523); 

                auto tg_yyzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 524); 

                auto tg_yyzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 525); 

                auto tg_yyzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 526); 

                auto tg_yyzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 527); 

                auto tg_yyzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 528); 

                auto tg_yyzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 529); 

                auto tg_yyzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 530); 

                auto tg_yyzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 531); 

                auto tg_yzzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 532); 

                auto tg_yzzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 533); 

                auto tg_yzzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 534); 

                auto tg_yzzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 535); 

                auto tg_yzzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 536); 

                auto tg_yzzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 537); 

                auto tg_yzzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 538); 

                auto tg_yzzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 539); 

                auto tg_yzzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 540); 

                auto tg_yzzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 541); 

                auto tg_yzzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 542); 

                auto tg_yzzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 543); 

                // set up pointers to integrals

                auto tg_yyyyyz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 826); 

                auto tg_yyyyyz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 827); 

                auto tg_yyyyzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 828); 

                auto tg_yyyyzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 829); 

                auto tg_yyyyzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 830); 

                auto tg_yyyyzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 831); 

                auto tg_yyyyzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 832); 

                auto tg_yyyyzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 833); 

                auto tg_yyyyzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 834); 

                auto tg_yyyyzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 835); 

                auto tg_yyyyzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 836); 

                auto tg_yyyyzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 837); 

                auto tg_yyyyzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 838); 

                auto tg_yyyyzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 839); 

                auto tg_yyyyzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 840); 

                auto tg_yyyyzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 841); 

                auto tg_yyyyzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 842); 

                auto tg_yyyyzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 843); 

                auto tg_yyyyzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 844); 

                auto tg_yyyyzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 845); 

                auto tg_yyyyzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 846); 

                auto tg_yyyyzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 847); 

                auto tg_yyyyzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 848); 

                auto tg_yyyyzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 849); 

                auto tg_yyyyzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 850); 

                auto tg_yyyyzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 851); 

                auto tg_yyyyzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 852); 

                auto tg_yyyyzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 853); 

                auto tg_yyyyzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 854); 

                auto tg_yyyyzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 855); 

                auto tg_yyyyzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 856); 

                auto tg_yyyyzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 857); 

                auto tg_yyyyzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 858); 

                auto tg_yyyyzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 859); 

                auto tg_yyyyzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 860); 

                auto tg_yyyyzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 861); 

                auto tg_yyyyzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 862); 

                auto tg_yyyyzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 863); 

                auto tg_yyyzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 864); 

                auto tg_yyyzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 865); 

                auto tg_yyyzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 866); 

                auto tg_yyyzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 867); 

                auto tg_yyyzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 868); 

                auto tg_yyyzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 869); 

                auto tg_yyyzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 870); 

                auto tg_yyyzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 871); 

                auto tg_yyyzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 872); 

                auto tg_yyyzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 873); 

                auto tg_yyyzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 874); 

                auto tg_yyyzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 875); 

                auto tg_yyyzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 876); 

                auto tg_yyyzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 877); 

                auto tg_yyyzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 878); 

                auto tg_yyyzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 879); 

                auto tg_yyyzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 880); 

                auto tg_yyyzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 881); 

                auto tg_yyyzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 882); 

                auto tg_yyyzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 883); 

                auto tg_yyyzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 884); 

                auto tg_yyyzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 885); 

                auto tg_yyyzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 886); 

                auto tg_yyyzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 887); 

                auto tg_yyyzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 888); 

                auto tg_yyyzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 889); 

                auto tg_yyyzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 890); 

                auto tg_yyyzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 891); 

                auto tg_yyyzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 892); 

                auto tg_yyyzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 893); 

                auto tg_yyyzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 894); 

                auto tg_yyyzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 895); 

                auto tg_yyyzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 896); 

                auto tg_yyyzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 897); 

                auto tg_yyyzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 898); 

                auto tg_yyyzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 899); 

                auto tg_yyzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 900); 

                auto tg_yyzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 901); 

                auto tg_yyzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 902); 

                auto tg_yyzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 903); 

                auto tg_yyzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 904); 

                auto tg_yyzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 905); 

                auto tg_yyzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 906); 

                auto tg_yyzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 907); 

                auto tg_yyzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 908); 

                auto tg_yyzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 909); 

                auto tg_yyzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 910); 

                auto tg_yyzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 911); 

                auto tg_yyzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 912); 

                auto tg_yyzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 913); 

                auto tg_yyzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 914); 

                auto tg_yyzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 915); 

                auto tg_yyzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 916); 

                // Batch of Integrals (826,917)

                #pragma omp simd aligned(fxn, fza, tg_yyyyyz_yzzzzzz_0, tg_yyyyyz_zzzzzzz_0, \
                                         tg_yyyyz_yzzzzzz_0, tg_yyyyz_yzzzzzz_1, tg_yyyyz_zzzzzz_1, tg_yyyyz_zzzzzzz_0, \
                                         tg_yyyyz_zzzzzzz_1, tg_yyyyzz_xxxxxxx_0, tg_yyyyzz_xxxxxxy_0, tg_yyyyzz_xxxxxxz_0, \
                                         tg_yyyyzz_xxxxxyy_0, tg_yyyyzz_xxxxxyz_0, tg_yyyyzz_xxxxxzz_0, tg_yyyyzz_xxxxyyy_0, \
                                         tg_yyyyzz_xxxxyyz_0, tg_yyyyzz_xxxxyzz_0, tg_yyyyzz_xxxxzzz_0, tg_yyyyzz_xxxyyyy_0, \
                                         tg_yyyyzz_xxxyyyz_0, tg_yyyyzz_xxxyyzz_0, tg_yyyyzz_xxxyzzz_0, tg_yyyyzz_xxxzzzz_0, \
                                         tg_yyyyzz_xxyyyyy_0, tg_yyyyzz_xxyyyyz_0, tg_yyyyzz_xxyyyzz_0, tg_yyyyzz_xxyyzzz_0, \
                                         tg_yyyyzz_xxyzzzz_0, tg_yyyyzz_xxzzzzz_0, tg_yyyyzz_xyyyyyy_0, tg_yyyyzz_xyyyyyz_0, \
                                         tg_yyyyzz_xyyyyzz_0, tg_yyyyzz_xyyyzzz_0, tg_yyyyzz_xyyzzzz_0, tg_yyyyzz_xyzzzzz_0, \
                                         tg_yyyyzz_xzzzzzz_0, tg_yyyyzz_yyyyyyy_0, tg_yyyyzz_yyyyyyz_0, tg_yyyyzz_yyyyyzz_0, \
                                         tg_yyyyzz_yyyyzzz_0, tg_yyyyzz_yyyzzzz_0, tg_yyyyzz_yyzzzzz_0, tg_yyyyzz_yzzzzzz_0, \
                                         tg_yyyyzz_zzzzzzz_0, tg_yyyz_yzzzzzz_0, tg_yyyz_yzzzzzz_1, tg_yyyz_zzzzzzz_0, \
                                         tg_yyyz_zzzzzzz_1, tg_yyyzz_xxxxxx_1, tg_yyyzz_xxxxxxx_0, tg_yyyzz_xxxxxxx_1, \
                                         tg_yyyzz_xxxxxxy_0, tg_yyyzz_xxxxxxy_1, tg_yyyzz_xxxxxxz_0, tg_yyyzz_xxxxxxz_1, \
                                         tg_yyyzz_xxxxxy_1, tg_yyyzz_xxxxxyy_0, tg_yyyzz_xxxxxyy_1, tg_yyyzz_xxxxxyz_0, \
                                         tg_yyyzz_xxxxxyz_1, tg_yyyzz_xxxxxz_1, tg_yyyzz_xxxxxzz_0, tg_yyyzz_xxxxxzz_1, \
                                         tg_yyyzz_xxxxyy_1, tg_yyyzz_xxxxyyy_0, tg_yyyzz_xxxxyyy_1, tg_yyyzz_xxxxyyz_0, \
                                         tg_yyyzz_xxxxyyz_1, tg_yyyzz_xxxxyz_1, tg_yyyzz_xxxxyzz_0, tg_yyyzz_xxxxyzz_1, \
                                         tg_yyyzz_xxxxzz_1, tg_yyyzz_xxxxzzz_0, tg_yyyzz_xxxxzzz_1, tg_yyyzz_xxxyyy_1, \
                                         tg_yyyzz_xxxyyyy_0, tg_yyyzz_xxxyyyy_1, tg_yyyzz_xxxyyyz_0, tg_yyyzz_xxxyyyz_1, \
                                         tg_yyyzz_xxxyyz_1, tg_yyyzz_xxxyyzz_0, tg_yyyzz_xxxyyzz_1, tg_yyyzz_xxxyzz_1, \
                                         tg_yyyzz_xxxyzzz_0, tg_yyyzz_xxxyzzz_1, tg_yyyzz_xxxzzz_1, tg_yyyzz_xxxzzzz_0, \
                                         tg_yyyzz_xxxzzzz_1, tg_yyyzz_xxyyyy_1, tg_yyyzz_xxyyyyy_0, tg_yyyzz_xxyyyyy_1, \
                                         tg_yyyzz_xxyyyyz_0, tg_yyyzz_xxyyyyz_1, tg_yyyzz_xxyyyz_1, tg_yyyzz_xxyyyzz_0, \
                                         tg_yyyzz_xxyyyzz_1, tg_yyyzz_xxyyzz_1, tg_yyyzz_xxyyzzz_0, tg_yyyzz_xxyyzzz_1, \
                                         tg_yyyzz_xxyzzz_1, tg_yyyzz_xxyzzzz_0, tg_yyyzz_xxyzzzz_1, tg_yyyzz_xxzzzz_1, \
                                         tg_yyyzz_xxzzzzz_0, tg_yyyzz_xxzzzzz_1, tg_yyyzz_xyyyyy_1, tg_yyyzz_xyyyyyy_0, \
                                         tg_yyyzz_xyyyyyy_1, tg_yyyzz_xyyyyyz_0, tg_yyyzz_xyyyyyz_1, tg_yyyzz_xyyyyz_1, \
                                         tg_yyyzz_xyyyyzz_0, tg_yyyzz_xyyyyzz_1, tg_yyyzz_xyyyzz_1, tg_yyyzz_xyyyzzz_0, \
                                         tg_yyyzz_xyyyzzz_1, tg_yyyzz_xyyzzz_1, tg_yyyzz_xyyzzzz_0, tg_yyyzz_xyyzzzz_1, \
                                         tg_yyyzz_xyzzzz_1, tg_yyyzz_xyzzzzz_0, tg_yyyzz_xyzzzzz_1, tg_yyyzz_xzzzzz_1, \
                                         tg_yyyzz_xzzzzzz_0, tg_yyyzz_xzzzzzz_1, tg_yyyzz_yyyyyy_1, tg_yyyzz_yyyyyyy_0, \
                                         tg_yyyzz_yyyyyyy_1, tg_yyyzz_yyyyyyz_0, tg_yyyzz_yyyyyyz_1, tg_yyyzz_yyyyyz_1, \
                                         tg_yyyzz_yyyyyzz_0, tg_yyyzz_yyyyyzz_1, tg_yyyzz_yyyyzz_1, tg_yyyzz_yyyyzzz_0, \
                                         tg_yyyzz_yyyyzzz_1, tg_yyyzz_yyyzzz_1, tg_yyyzz_yyyzzzz_0, tg_yyyzz_yyyzzzz_1, \
                                         tg_yyyzz_yyzzzz_1, tg_yyyzz_yyzzzzz_0, tg_yyyzz_yyzzzzz_1, tg_yyyzz_yzzzzz_1, \
                                         tg_yyyzz_yzzzzzz_0, tg_yyyzz_yzzzzzz_1, tg_yyyzz_zzzzzz_1, tg_yyyzz_zzzzzzz_0, \
                                         tg_yyyzz_zzzzzzz_1, tg_yyyzzz_xxxxxxx_0, tg_yyyzzz_xxxxxxy_0, tg_yyyzzz_xxxxxxz_0, \
                                         tg_yyyzzz_xxxxxyy_0, tg_yyyzzz_xxxxxyz_0, tg_yyyzzz_xxxxxzz_0, tg_yyyzzz_xxxxyyy_0, \
                                         tg_yyyzzz_xxxxyyz_0, tg_yyyzzz_xxxxyzz_0, tg_yyyzzz_xxxxzzz_0, tg_yyyzzz_xxxyyyy_0, \
                                         tg_yyyzzz_xxxyyyz_0, tg_yyyzzz_xxxyyzz_0, tg_yyyzzz_xxxyzzz_0, tg_yyyzzz_xxxzzzz_0, \
                                         tg_yyyzzz_xxyyyyy_0, tg_yyyzzz_xxyyyyz_0, tg_yyyzzz_xxyyyzz_0, tg_yyyzzz_xxyyzzz_0, \
                                         tg_yyyzzz_xxyzzzz_0, tg_yyyzzz_xxzzzzz_0, tg_yyyzzz_xyyyyyy_0, tg_yyyzzz_xyyyyyz_0, \
                                         tg_yyyzzz_xyyyyzz_0, tg_yyyzzz_xyyyzzz_0, tg_yyyzzz_xyyzzzz_0, tg_yyyzzz_xyzzzzz_0, \
                                         tg_yyyzzz_xzzzzzz_0, tg_yyyzzz_yyyyyyy_0, tg_yyyzzz_yyyyyyz_0, tg_yyyzzz_yyyyyzz_0, \
                                         tg_yyyzzz_yyyyzzz_0, tg_yyyzzz_yyyzzzz_0, tg_yyyzzz_yyzzzzz_0, tg_yyyzzz_yzzzzzz_0, \
                                         tg_yyyzzz_zzzzzzz_0, tg_yyzz_xxxxxxx_0, tg_yyzz_xxxxxxx_1, tg_yyzz_xxxxxxy_0, \
                                         tg_yyzz_xxxxxxy_1, tg_yyzz_xxxxxxz_0, tg_yyzz_xxxxxxz_1, tg_yyzz_xxxxxyy_0, \
                                         tg_yyzz_xxxxxyy_1, tg_yyzz_xxxxxyz_0, tg_yyzz_xxxxxyz_1, tg_yyzz_xxxxxzz_0, \
                                         tg_yyzz_xxxxxzz_1, tg_yyzz_xxxxyyy_0, tg_yyzz_xxxxyyy_1, tg_yyzz_xxxxyyz_0, \
                                         tg_yyzz_xxxxyyz_1, tg_yyzz_xxxxyzz_0, tg_yyzz_xxxxyzz_1, tg_yyzz_xxxxzzz_0, \
                                         tg_yyzz_xxxxzzz_1, tg_yyzz_xxxyyyy_0, tg_yyzz_xxxyyyy_1, tg_yyzz_xxxyyyz_0, \
                                         tg_yyzz_xxxyyyz_1, tg_yyzz_xxxyyzz_0, tg_yyzz_xxxyyzz_1, tg_yyzz_xxxyzzz_0, \
                                         tg_yyzz_xxxyzzz_1, tg_yyzz_xxxzzzz_0, tg_yyzz_xxxzzzz_1, tg_yyzz_xxyyyyy_0, \
                                         tg_yyzz_xxyyyyy_1, tg_yyzz_xxyyyyz_0, tg_yyzz_xxyyyyz_1, tg_yyzz_xxyyyzz_0, \
                                         tg_yyzz_xxyyyzz_1, tg_yyzz_xxyyzzz_0, tg_yyzz_xxyyzzz_1, tg_yyzz_xxyzzzz_0, \
                                         tg_yyzz_xxyzzzz_1, tg_yyzz_xxzzzzz_0, tg_yyzz_xxzzzzz_1, tg_yyzz_xyyyyyy_0, \
                                         tg_yyzz_xyyyyyy_1, tg_yyzz_xyyyyyz_0, tg_yyzz_xyyyyyz_1, tg_yyzz_xyyyyzz_0, \
                                         tg_yyzz_xyyyyzz_1, tg_yyzz_xyyyzzz_0, tg_yyzz_xyyyzzz_1, tg_yyzz_xyyzzzz_0, \
                                         tg_yyzz_xyyzzzz_1, tg_yyzz_xyzzzzz_0, tg_yyzz_xyzzzzz_1, tg_yyzz_xzzzzzz_0, \
                                         tg_yyzz_xzzzzzz_1, tg_yyzz_yyyyyyy_0, tg_yyzz_yyyyyyy_1, tg_yyzz_yyyyyyz_0, \
                                         tg_yyzz_yyyyyyz_1, tg_yyzz_yyyyyzz_0, tg_yyzz_yyyyyzz_1, tg_yyzz_yyyyzzz_0, \
                                         tg_yyzz_yyyyzzz_1, tg_yyzz_yyyzzzz_0, tg_yyzz_yyyzzzz_1, tg_yyzz_yyzzzzz_0, \
                                         tg_yyzz_yyzzzzz_1, tg_yyzz_yzzzzzz_0, tg_yyzz_yzzzzzz_1, tg_yyzz_zzzzzzz_0, \
                                         tg_yyzz_zzzzzzz_1, tg_yyzzz_xxxxxx_1, tg_yyzzz_xxxxxxx_0, tg_yyzzz_xxxxxxx_1, \
                                         tg_yyzzz_xxxxxxy_0, tg_yyzzz_xxxxxxy_1, tg_yyzzz_xxxxxxz_0, tg_yyzzz_xxxxxxz_1, \
                                         tg_yyzzz_xxxxxy_1, tg_yyzzz_xxxxxyy_0, tg_yyzzz_xxxxxyy_1, tg_yyzzz_xxxxxyz_0, \
                                         tg_yyzzz_xxxxxyz_1, tg_yyzzz_xxxxxz_1, tg_yyzzz_xxxxxzz_0, tg_yyzzz_xxxxxzz_1, \
                                         tg_yyzzz_xxxxyy_1, tg_yyzzz_xxxxyyy_0, tg_yyzzz_xxxxyyy_1, tg_yyzzz_xxxxyyz_0, \
                                         tg_yyzzz_xxxxyyz_1, tg_yyzzz_xxxxyz_1, tg_yyzzz_xxxxyzz_0, tg_yyzzz_xxxxyzz_1, \
                                         tg_yyzzz_xxxxzz_1, tg_yyzzz_xxxxzzz_0, tg_yyzzz_xxxxzzz_1, tg_yyzzz_xxxyyy_1, \
                                         tg_yyzzz_xxxyyyy_0, tg_yyzzz_xxxyyyy_1, tg_yyzzz_xxxyyyz_0, tg_yyzzz_xxxyyyz_1, \
                                         tg_yyzzz_xxxyyz_1, tg_yyzzz_xxxyyzz_0, tg_yyzzz_xxxyyzz_1, tg_yyzzz_xxxyzz_1, \
                                         tg_yyzzz_xxxyzzz_0, tg_yyzzz_xxxyzzz_1, tg_yyzzz_xxxzzz_1, tg_yyzzz_xxxzzzz_0, \
                                         tg_yyzzz_xxxzzzz_1, tg_yyzzz_xxyyyy_1, tg_yyzzz_xxyyyyy_0, tg_yyzzz_xxyyyyy_1, \
                                         tg_yyzzz_xxyyyyz_0, tg_yyzzz_xxyyyyz_1, tg_yyzzz_xxyyyz_1, tg_yyzzz_xxyyyzz_0, \
                                         tg_yyzzz_xxyyyzz_1, tg_yyzzz_xxyyzz_1, tg_yyzzz_xxyyzzz_0, tg_yyzzz_xxyyzzz_1, \
                                         tg_yyzzz_xxyzzz_1, tg_yyzzz_xxyzzzz_0, tg_yyzzz_xxyzzzz_1, tg_yyzzz_xxzzzz_1, \
                                         tg_yyzzz_xxzzzzz_0, tg_yyzzz_xxzzzzz_1, tg_yyzzz_xyyyyy_1, tg_yyzzz_xyyyyyy_0, \
                                         tg_yyzzz_xyyyyyy_1, tg_yyzzz_xyyyyyz_0, tg_yyzzz_xyyyyyz_1, tg_yyzzz_xyyyyz_1, \
                                         tg_yyzzz_xyyyyzz_0, tg_yyzzz_xyyyyzz_1, tg_yyzzz_xyyyzz_1, tg_yyzzz_xyyyzzz_0, \
                                         tg_yyzzz_xyyyzzz_1, tg_yyzzz_xyyzzz_1, tg_yyzzz_xyyzzzz_0, tg_yyzzz_xyyzzzz_1, \
                                         tg_yyzzz_xyzzzz_1, tg_yyzzz_xyzzzzz_0, tg_yyzzz_xyzzzzz_1, tg_yyzzz_xzzzzz_1, \
                                         tg_yyzzz_xzzzzzz_0, tg_yyzzz_xzzzzzz_1, tg_yyzzz_yyyyyy_1, tg_yyzzz_yyyyyyy_0, \
                                         tg_yyzzz_yyyyyyy_1, tg_yyzzz_yyyyyyz_0, tg_yyzzz_yyyyyyz_1, tg_yyzzz_yyyyyz_1, \
                                         tg_yyzzz_yyyyyzz_0, tg_yyzzz_yyyyyzz_1, tg_yyzzz_yyyyzz_1, tg_yyzzz_yyyyzzz_0, \
                                         tg_yyzzz_yyyyzzz_1, tg_yyzzz_yyyzzz_1, tg_yyzzz_yyyzzzz_0, tg_yyzzz_yyyzzzz_1, \
                                         tg_yyzzz_yyzzzz_1, tg_yyzzz_yyzzzzz_0, tg_yyzzz_yyzzzzz_1, tg_yyzzz_yzzzzz_1, \
                                         tg_yyzzz_yzzzzzz_0, tg_yyzzz_yzzzzzz_1, tg_yyzzz_zzzzzz_1, tg_yyzzz_zzzzzzz_0, \
                                         tg_yyzzz_zzzzzzz_1, tg_yyzzzz_xxxxxxx_0, tg_yyzzzz_xxxxxxy_0, tg_yyzzzz_xxxxxxz_0, \
                                         tg_yyzzzz_xxxxxyy_0, tg_yyzzzz_xxxxxyz_0, tg_yyzzzz_xxxxxzz_0, tg_yyzzzz_xxxxyyy_0, \
                                         tg_yyzzzz_xxxxyyz_0, tg_yyzzzz_xxxxyzz_0, tg_yyzzzz_xxxxzzz_0, tg_yyzzzz_xxxyyyy_0, \
                                         tg_yyzzzz_xxxyyyz_0, tg_yyzzzz_xxxyyzz_0, tg_yyzzzz_xxxyzzz_0, tg_yyzzzz_xxxzzzz_0, \
                                         tg_yyzzzz_xxyyyyy_0, tg_yyzzzz_xxyyyyz_0, tg_yzzz_xxxxxxx_0, tg_yzzz_xxxxxxx_1, \
                                         tg_yzzz_xxxxxxy_0, tg_yzzz_xxxxxxy_1, tg_yzzz_xxxxxxz_0, tg_yzzz_xxxxxxz_1, \
                                         tg_yzzz_xxxxxyy_0, tg_yzzz_xxxxxyy_1, tg_yzzz_xxxxxyz_0, tg_yzzz_xxxxxyz_1, \
                                         tg_yzzz_xxxxxzz_0, tg_yzzz_xxxxxzz_1, tg_yzzz_xxxxyyy_0, tg_yzzz_xxxxyyy_1, \
                                         tg_yzzz_xxxxyyz_0, tg_yzzz_xxxxyyz_1, tg_yzzz_xxxxyzz_0, tg_yzzz_xxxxyzz_1, \
                                         tg_yzzz_xxxxzzz_0, tg_yzzz_xxxxzzz_1, tg_yzzz_xxxyyyy_0, tg_yzzz_xxxyyyy_1, \
                                         tg_yzzz_xxxyyyz_0, tg_yzzz_xxxyyyz_1, tg_yzzz_xxxyyzz_0, tg_yzzz_xxxyyzz_1, \
                                         tg_yzzz_xxxyzzz_0, tg_yzzz_xxxyzzz_1, tg_yzzz_xxxzzzz_0, tg_yzzz_xxxzzzz_1, \
                                         tg_yzzz_xxyyyyy_0, tg_yzzz_xxyyyyy_1, tg_yzzz_xxyyyyz_0, tg_yzzz_xxyyyyz_1, \
                                         tg_yzzz_xxyyyzz_0, tg_yzzz_xxyyyzz_1, tg_yzzz_xxyyzzz_0, tg_yzzz_xxyyzzz_1, \
                                         tg_yzzz_xxyzzzz_0, tg_yzzz_xxyzzzz_1, tg_yzzz_xxzzzzz_0, tg_yzzz_xxzzzzz_1, \
                                         tg_yzzz_xyyyyyy_0, tg_yzzz_xyyyyyy_1, tg_yzzz_xyyyyyz_0, tg_yzzz_xyyyyyz_1, \
                                         tg_yzzz_xyyyyzz_0, tg_yzzz_xyyyyzz_1, tg_yzzz_xyyyzzz_0, tg_yzzz_xyyyzzz_1, \
                                         tg_yzzz_xyyzzzz_0, tg_yzzz_xyyzzzz_1, tg_yzzz_xyzzzzz_0, tg_yzzz_xyzzzzz_1, \
                                         tg_yzzz_xzzzzzz_0, tg_yzzz_xzzzzzz_1, tg_yzzz_yyyyyyy_0, tg_yzzz_yyyyyyy_1, \
                                         tg_yzzz_yyyyyyz_0, tg_yzzz_yyyyyyz_1, tg_yzzz_yyyyyzz_0, tg_yzzz_yyyyyzz_1, \
                                         tg_yzzz_yyyyzzz_0, tg_yzzz_yyyyzzz_1, tg_yzzz_yyyzzzz_0, tg_yzzz_yyyzzzz_1, \
                                         tg_yzzz_yyzzzzz_0, tg_yzzz_yyzzzzz_1, tg_yzzz_yzzzzzz_0, tg_yzzz_yzzzzzz_1, \
                                         tg_yzzz_zzzzzzz_0, tg_yzzz_zzzzzzz_1, tg_yzzzz_xxxxxx_1, tg_yzzzz_xxxxxxx_0, \
                                         tg_yzzzz_xxxxxxx_1, tg_yzzzz_xxxxxxy_0, tg_yzzzz_xxxxxxy_1, tg_yzzzz_xxxxxxz_0, \
                                         tg_yzzzz_xxxxxxz_1, tg_yzzzz_xxxxxy_1, tg_yzzzz_xxxxxyy_0, tg_yzzzz_xxxxxyy_1, \
                                         tg_yzzzz_xxxxxyz_0, tg_yzzzz_xxxxxyz_1, tg_yzzzz_xxxxxz_1, tg_yzzzz_xxxxxzz_0, \
                                         tg_yzzzz_xxxxxzz_1, tg_yzzzz_xxxxyy_1, tg_yzzzz_xxxxyyy_0, tg_yzzzz_xxxxyyy_1, \
                                         tg_yzzzz_xxxxyyz_0, tg_yzzzz_xxxxyyz_1, tg_yzzzz_xxxxyz_1, tg_yzzzz_xxxxyzz_0, \
                                         tg_yzzzz_xxxxyzz_1, tg_yzzzz_xxxxzz_1, tg_yzzzz_xxxxzzz_0, tg_yzzzz_xxxxzzz_1, \
                                         tg_yzzzz_xxxyyy_1, tg_yzzzz_xxxyyyy_0, tg_yzzzz_xxxyyyy_1, tg_yzzzz_xxxyyyz_0, \
                                         tg_yzzzz_xxxyyyz_1, tg_yzzzz_xxxyyz_1, tg_yzzzz_xxxyyzz_0, tg_yzzzz_xxxyyzz_1, \
                                         tg_yzzzz_xxxyzz_1, tg_yzzzz_xxxyzzz_0, tg_yzzzz_xxxyzzz_1, tg_yzzzz_xxxzzz_1, \
                                         tg_yzzzz_xxxzzzz_0, tg_yzzzz_xxxzzzz_1, tg_yzzzz_xxyyyy_1, tg_yzzzz_xxyyyyy_0, \
                                         tg_yzzzz_xxyyyyy_1, tg_yzzzz_xxyyyyz_0, tg_yzzzz_xxyyyyz_1, tg_yzzzz_xxyyyz_1, \
                                         tg_zzzz_xxxxxxx_0, tg_zzzz_xxxxxxx_1, tg_zzzz_xxxxxxy_0, tg_zzzz_xxxxxxy_1, \
                                         tg_zzzz_xxxxxxz_0, tg_zzzz_xxxxxxz_1, tg_zzzz_xxxxxyy_0, tg_zzzz_xxxxxyy_1, \
                                         tg_zzzz_xxxxxyz_0, tg_zzzz_xxxxxyz_1, tg_zzzz_xxxxxzz_0, tg_zzzz_xxxxxzz_1, \
                                         tg_zzzz_xxxxyyy_0, tg_zzzz_xxxxyyy_1, tg_zzzz_xxxxyyz_0, tg_zzzz_xxxxyyz_1, \
                                         tg_zzzz_xxxxyzz_0, tg_zzzz_xxxxyzz_1, tg_zzzz_xxxxzzz_0, tg_zzzz_xxxxzzz_1, \
                                         tg_zzzz_xxxyyyy_0, tg_zzzz_xxxyyyy_1, tg_zzzz_xxxyyyz_0, tg_zzzz_xxxyyyz_1, \
                                         tg_zzzz_xxxyyzz_0, tg_zzzz_xxxyyzz_1, tg_zzzz_xxxyzzz_0, tg_zzzz_xxxyzzz_1, \
                                         tg_zzzz_xxxzzzz_0, tg_zzzz_xxxzzzz_1, tg_zzzz_xxyyyyy_0, tg_zzzz_xxyyyyy_1, \
                                         tg_zzzz_xxyyyyz_0, tg_zzzz_xxyyyyz_1, wp_y: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_y[j]; 

                    tg_yyyyyz_yzzzzzz_0[j] = pb_y * tg_yyyyz_yzzzzzz_0[j] + fr * tg_yyyyz_yzzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_yzzzzzz_0[j] - tg_yyyz_yzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyyz_zzzzzz_1[j];

                    tg_yyyyyz_zzzzzzz_0[j] = pb_y * tg_yyyyz_zzzzzzz_0[j] + fr * tg_yyyyz_zzzzzzz_1[j] + 2.0 * fl1_fx * (tg_yyyz_zzzzzzz_0[j] - tg_yyyz_zzzzzzz_1[j] * fl1_fza);

                    tg_yyyyzz_xxxxxxx_0[j] = pb_y * tg_yyyzz_xxxxxxx_0[j] + fr * tg_yyyzz_xxxxxxx_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxxx_0[j] - tg_yyzz_xxxxxxx_1[j] * fl1_fza);

                    tg_yyyyzz_xxxxxxy_0[j] = pb_y * tg_yyyzz_xxxxxxy_0[j] + fr * tg_yyyzz_xxxxxxy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxxy_0[j] - tg_yyzz_xxxxxxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xxxxxx_1[j];

                    tg_yyyyzz_xxxxxxz_0[j] = pb_y * tg_yyyzz_xxxxxxz_0[j] + fr * tg_yyyzz_xxxxxxz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxxz_0[j] - tg_yyzz_xxxxxxz_1[j] * fl1_fza);

                    tg_yyyyzz_xxxxxyy_0[j] = pb_y * tg_yyyzz_xxxxxyy_0[j] + fr * tg_yyyzz_xxxxxyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxyy_0[j] - tg_yyzz_xxxxxyy_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xxxxxy_1[j];

                    tg_yyyyzz_xxxxxyz_0[j] = pb_y * tg_yyyzz_xxxxxyz_0[j] + fr * tg_yyyzz_xxxxxyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxyz_0[j] - tg_yyzz_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xxxxxz_1[j];

                    tg_yyyyzz_xxxxxzz_0[j] = pb_y * tg_yyyzz_xxxxxzz_0[j] + fr * tg_yyyzz_xxxxxzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxxzz_0[j] - tg_yyzz_xxxxxzz_1[j] * fl1_fza);

                    tg_yyyyzz_xxxxyyy_0[j] = pb_y * tg_yyyzz_xxxxyyy_0[j] + fr * tg_yyyzz_xxxxyyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxyyy_0[j] - tg_yyzz_xxxxyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_xxxxyy_1[j];

                    tg_yyyyzz_xxxxyyz_0[j] = pb_y * tg_yyyzz_xxxxyyz_0[j] + fr * tg_yyyzz_xxxxyyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxyyz_0[j] - tg_yyzz_xxxxyyz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xxxxyz_1[j];

                    tg_yyyyzz_xxxxyzz_0[j] = pb_y * tg_yyyzz_xxxxyzz_0[j] + fr * tg_yyyzz_xxxxyzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxyzz_0[j] - tg_yyzz_xxxxyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xxxxzz_1[j];

                    tg_yyyyzz_xxxxzzz_0[j] = pb_y * tg_yyyzz_xxxxzzz_0[j] + fr * tg_yyyzz_xxxxzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxxzzz_0[j] - tg_yyzz_xxxxzzz_1[j] * fl1_fza);

                    tg_yyyyzz_xxxyyyy_0[j] = pb_y * tg_yyyzz_xxxyyyy_0[j] + fr * tg_yyyzz_xxxyyyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxyyyy_0[j] - tg_yyzz_xxxyyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyzz_xxxyyy_1[j];

                    tg_yyyyzz_xxxyyyz_0[j] = pb_y * tg_yyyzz_xxxyyyz_0[j] + fr * tg_yyyzz_xxxyyyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxyyyz_0[j] - tg_yyzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_xxxyyz_1[j];

                    tg_yyyyzz_xxxyyzz_0[j] = pb_y * tg_yyyzz_xxxyyzz_0[j] + fr * tg_yyyzz_xxxyyzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxyyzz_0[j] - tg_yyzz_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xxxyzz_1[j];

                    tg_yyyyzz_xxxyzzz_0[j] = pb_y * tg_yyyzz_xxxyzzz_0[j] + fr * tg_yyyzz_xxxyzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxyzzz_0[j] - tg_yyzz_xxxyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xxxzzz_1[j];

                    tg_yyyyzz_xxxzzzz_0[j] = pb_y * tg_yyyzz_xxxzzzz_0[j] + fr * tg_yyyzz_xxxzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxxzzzz_0[j] - tg_yyzz_xxxzzzz_1[j] * fl1_fza);

                    tg_yyyyzz_xxyyyyy_0[j] = pb_y * tg_yyyzz_xxyyyyy_0[j] + fr * tg_yyyzz_xxyyyyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxyyyyy_0[j] - tg_yyzz_xxyyyyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyzz_xxyyyy_1[j];

                    tg_yyyyzz_xxyyyyz_0[j] = pb_y * tg_yyyzz_xxyyyyz_0[j] + fr * tg_yyyzz_xxyyyyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxyyyyz_0[j] - tg_yyzz_xxyyyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyzz_xxyyyz_1[j];

                    tg_yyyyzz_xxyyyzz_0[j] = pb_y * tg_yyyzz_xxyyyzz_0[j] + fr * tg_yyyzz_xxyyyzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxyyyzz_0[j] - tg_yyzz_xxyyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_xxyyzz_1[j];

                    tg_yyyyzz_xxyyzzz_0[j] = pb_y * tg_yyyzz_xxyyzzz_0[j] + fr * tg_yyyzz_xxyyzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxyyzzz_0[j] - tg_yyzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xxyzzz_1[j];

                    tg_yyyyzz_xxyzzzz_0[j] = pb_y * tg_yyyzz_xxyzzzz_0[j] + fr * tg_yyyzz_xxyzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxyzzzz_0[j] - tg_yyzz_xxyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xxzzzz_1[j];

                    tg_yyyyzz_xxzzzzz_0[j] = pb_y * tg_yyyzz_xxzzzzz_0[j] + fr * tg_yyyzz_xxzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xxzzzzz_0[j] - tg_yyzz_xxzzzzz_1[j] * fl1_fza);

                    tg_yyyyzz_xyyyyyy_0[j] = pb_y * tg_yyyzz_xyyyyyy_0[j] + fr * tg_yyyzz_xyyyyyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyyyyyy_0[j] - tg_yyzz_xyyyyyy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyzz_xyyyyy_1[j];

                    tg_yyyyzz_xyyyyyz_0[j] = pb_y * tg_yyyzz_xyyyyyz_0[j] + fr * tg_yyyzz_xyyyyyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyyyyyz_0[j] - tg_yyzz_xyyyyyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyzz_xyyyyz_1[j];

                    tg_yyyyzz_xyyyyzz_0[j] = pb_y * tg_yyyzz_xyyyyzz_0[j] + fr * tg_yyyzz_xyyyyzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyyyyzz_0[j] - tg_yyzz_xyyyyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyzz_xyyyzz_1[j];

                    tg_yyyyzz_xyyyzzz_0[j] = pb_y * tg_yyyzz_xyyyzzz_0[j] + fr * tg_yyyzz_xyyyzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyyyzzz_0[j] - tg_yyzz_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_xyyzzz_1[j];

                    tg_yyyyzz_xyyzzzz_0[j] = pb_y * tg_yyyzz_xyyzzzz_0[j] + fr * tg_yyyzz_xyyzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyyzzzz_0[j] - tg_yyzz_xyyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_xyzzzz_1[j];

                    tg_yyyyzz_xyzzzzz_0[j] = pb_y * tg_yyyzz_xyzzzzz_0[j] + fr * tg_yyyzz_xyzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xyzzzzz_0[j] - tg_yyzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_xzzzzz_1[j];

                    tg_yyyyzz_xzzzzzz_0[j] = pb_y * tg_yyyzz_xzzzzzz_0[j] + fr * tg_yyyzz_xzzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_xzzzzzz_0[j] - tg_yyzz_xzzzzzz_1[j] * fl1_fza);

                    tg_yyyyzz_yyyyyyy_0[j] = pb_y * tg_yyyzz_yyyyyyy_0[j] + fr * tg_yyyzz_yyyyyyy_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyyyyyy_0[j] - tg_yyzz_yyyyyyy_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_yyyzz_yyyyyy_1[j];

                    tg_yyyyzz_yyyyyyz_0[j] = pb_y * tg_yyyzz_yyyyyyz_0[j] + fr * tg_yyyzz_yyyyyyz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyyyyyz_0[j] - tg_yyzz_yyyyyyz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyyzz_yyyyyz_1[j];

                    tg_yyyyzz_yyyyyzz_0[j] = pb_y * tg_yyyzz_yyyyyzz_0[j] + fr * tg_yyyzz_yyyyyzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyyyyzz_0[j] - tg_yyzz_yyyyyzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyyzz_yyyyzz_1[j];

                    tg_yyyyzz_yyyyzzz_0[j] = pb_y * tg_yyyzz_yyyyzzz_0[j] + fr * tg_yyyzz_yyyyzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyyyzzz_0[j] - tg_yyzz_yyyyzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyyzz_yyyzzz_1[j];

                    tg_yyyyzz_yyyzzzz_0[j] = pb_y * tg_yyyzz_yyyzzzz_0[j] + fr * tg_yyyzz_yyyzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyyzzzz_0[j] - tg_yyzz_yyyzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyyzz_yyzzzz_1[j];

                    tg_yyyyzz_yyzzzzz_0[j] = pb_y * tg_yyyzz_yyzzzzz_0[j] + fr * tg_yyyzz_yyzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yyzzzzz_0[j] - tg_yyzz_yyzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyyzz_yzzzzz_1[j];

                    tg_yyyyzz_yzzzzzz_0[j] = pb_y * tg_yyyzz_yzzzzzz_0[j] + fr * tg_yyyzz_yzzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_yzzzzzz_0[j] - tg_yyzz_yzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyyzz_zzzzzz_1[j];

                    tg_yyyyzz_zzzzzzz_0[j] = pb_y * tg_yyyzz_zzzzzzz_0[j] + fr * tg_yyyzz_zzzzzzz_1[j] + 1.5 * fl1_fx * (tg_yyzz_zzzzzzz_0[j] - tg_yyzz_zzzzzzz_1[j] * fl1_fza);

                    tg_yyyzzz_xxxxxxx_0[j] = pb_y * tg_yyzzz_xxxxxxx_0[j] + fr * tg_yyzzz_xxxxxxx_1[j] + fl1_fx * (tg_yzzz_xxxxxxx_0[j] - tg_yzzz_xxxxxxx_1[j] * fl1_fza);

                    tg_yyyzzz_xxxxxxy_0[j] = pb_y * tg_yyzzz_xxxxxxy_0[j] + fr * tg_yyzzz_xxxxxxy_1[j] + fl1_fx * (tg_yzzz_xxxxxxy_0[j] - tg_yzzz_xxxxxxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xxxxxx_1[j];

                    tg_yyyzzz_xxxxxxz_0[j] = pb_y * tg_yyzzz_xxxxxxz_0[j] + fr * tg_yyzzz_xxxxxxz_1[j] + fl1_fx * (tg_yzzz_xxxxxxz_0[j] - tg_yzzz_xxxxxxz_1[j] * fl1_fza);

                    tg_yyyzzz_xxxxxyy_0[j] = pb_y * tg_yyzzz_xxxxxyy_0[j] + fr * tg_yyzzz_xxxxxyy_1[j] + fl1_fx * (tg_yzzz_xxxxxyy_0[j] - tg_yzzz_xxxxxyy_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xxxxxy_1[j];

                    tg_yyyzzz_xxxxxyz_0[j] = pb_y * tg_yyzzz_xxxxxyz_0[j] + fr * tg_yyzzz_xxxxxyz_1[j] + fl1_fx * (tg_yzzz_xxxxxyz_0[j] - tg_yzzz_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xxxxxz_1[j];

                    tg_yyyzzz_xxxxxzz_0[j] = pb_y * tg_yyzzz_xxxxxzz_0[j] + fr * tg_yyzzz_xxxxxzz_1[j] + fl1_fx * (tg_yzzz_xxxxxzz_0[j] - tg_yzzz_xxxxxzz_1[j] * fl1_fza);

                    tg_yyyzzz_xxxxyyy_0[j] = pb_y * tg_yyzzz_xxxxyyy_0[j] + fr * tg_yyzzz_xxxxyyy_1[j] + fl1_fx * (tg_yzzz_xxxxyyy_0[j] - tg_yzzz_xxxxyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_xxxxyy_1[j];

                    tg_yyyzzz_xxxxyyz_0[j] = pb_y * tg_yyzzz_xxxxyyz_0[j] + fr * tg_yyzzz_xxxxyyz_1[j] + fl1_fx * (tg_yzzz_xxxxyyz_0[j] - tg_yzzz_xxxxyyz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xxxxyz_1[j];

                    tg_yyyzzz_xxxxyzz_0[j] = pb_y * tg_yyzzz_xxxxyzz_0[j] + fr * tg_yyzzz_xxxxyzz_1[j] + fl1_fx * (tg_yzzz_xxxxyzz_0[j] - tg_yzzz_xxxxyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xxxxzz_1[j];

                    tg_yyyzzz_xxxxzzz_0[j] = pb_y * tg_yyzzz_xxxxzzz_0[j] + fr * tg_yyzzz_xxxxzzz_1[j] + fl1_fx * (tg_yzzz_xxxxzzz_0[j] - tg_yzzz_xxxxzzz_1[j] * fl1_fza);

                    tg_yyyzzz_xxxyyyy_0[j] = pb_y * tg_yyzzz_xxxyyyy_0[j] + fr * tg_yyzzz_xxxyyyy_1[j] + fl1_fx * (tg_yzzz_xxxyyyy_0[j] - tg_yzzz_xxxyyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyzzz_xxxyyy_1[j];

                    tg_yyyzzz_xxxyyyz_0[j] = pb_y * tg_yyzzz_xxxyyyz_0[j] + fr * tg_yyzzz_xxxyyyz_1[j] + fl1_fx * (tg_yzzz_xxxyyyz_0[j] - tg_yzzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_xxxyyz_1[j];

                    tg_yyyzzz_xxxyyzz_0[j] = pb_y * tg_yyzzz_xxxyyzz_0[j] + fr * tg_yyzzz_xxxyyzz_1[j] + fl1_fx * (tg_yzzz_xxxyyzz_0[j] - tg_yzzz_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xxxyzz_1[j];

                    tg_yyyzzz_xxxyzzz_0[j] = pb_y * tg_yyzzz_xxxyzzz_0[j] + fr * tg_yyzzz_xxxyzzz_1[j] + fl1_fx * (tg_yzzz_xxxyzzz_0[j] - tg_yzzz_xxxyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xxxzzz_1[j];

                    tg_yyyzzz_xxxzzzz_0[j] = pb_y * tg_yyzzz_xxxzzzz_0[j] + fr * tg_yyzzz_xxxzzzz_1[j] + fl1_fx * (tg_yzzz_xxxzzzz_0[j] - tg_yzzz_xxxzzzz_1[j] * fl1_fza);

                    tg_yyyzzz_xxyyyyy_0[j] = pb_y * tg_yyzzz_xxyyyyy_0[j] + fr * tg_yyzzz_xxyyyyy_1[j] + fl1_fx * (tg_yzzz_xxyyyyy_0[j] - tg_yzzz_xxyyyyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyzzz_xxyyyy_1[j];

                    tg_yyyzzz_xxyyyyz_0[j] = pb_y * tg_yyzzz_xxyyyyz_0[j] + fr * tg_yyzzz_xxyyyyz_1[j] + fl1_fx * (tg_yzzz_xxyyyyz_0[j] - tg_yzzz_xxyyyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyzzz_xxyyyz_1[j];

                    tg_yyyzzz_xxyyyzz_0[j] = pb_y * tg_yyzzz_xxyyyzz_0[j] + fr * tg_yyzzz_xxyyyzz_1[j] + fl1_fx * (tg_yzzz_xxyyyzz_0[j] - tg_yzzz_xxyyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_xxyyzz_1[j];

                    tg_yyyzzz_xxyyzzz_0[j] = pb_y * tg_yyzzz_xxyyzzz_0[j] + fr * tg_yyzzz_xxyyzzz_1[j] + fl1_fx * (tg_yzzz_xxyyzzz_0[j] - tg_yzzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xxyzzz_1[j];

                    tg_yyyzzz_xxyzzzz_0[j] = pb_y * tg_yyzzz_xxyzzzz_0[j] + fr * tg_yyzzz_xxyzzzz_1[j] + fl1_fx * (tg_yzzz_xxyzzzz_0[j] - tg_yzzz_xxyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xxzzzz_1[j];

                    tg_yyyzzz_xxzzzzz_0[j] = pb_y * tg_yyzzz_xxzzzzz_0[j] + fr * tg_yyzzz_xxzzzzz_1[j] + fl1_fx * (tg_yzzz_xxzzzzz_0[j] - tg_yzzz_xxzzzzz_1[j] * fl1_fza);

                    tg_yyyzzz_xyyyyyy_0[j] = pb_y * tg_yyzzz_xyyyyyy_0[j] + fr * tg_yyzzz_xyyyyyy_1[j] + fl1_fx * (tg_yzzz_xyyyyyy_0[j] - tg_yzzz_xyyyyyy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyzzz_xyyyyy_1[j];

                    tg_yyyzzz_xyyyyyz_0[j] = pb_y * tg_yyzzz_xyyyyyz_0[j] + fr * tg_yyzzz_xyyyyyz_1[j] + fl1_fx * (tg_yzzz_xyyyyyz_0[j] - tg_yzzz_xyyyyyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyzzz_xyyyyz_1[j];

                    tg_yyyzzz_xyyyyzz_0[j] = pb_y * tg_yyzzz_xyyyyzz_0[j] + fr * tg_yyzzz_xyyyyzz_1[j] + fl1_fx * (tg_yzzz_xyyyyzz_0[j] - tg_yzzz_xyyyyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyzzz_xyyyzz_1[j];

                    tg_yyyzzz_xyyyzzz_0[j] = pb_y * tg_yyzzz_xyyyzzz_0[j] + fr * tg_yyzzz_xyyyzzz_1[j] + fl1_fx * (tg_yzzz_xyyyzzz_0[j] - tg_yzzz_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_xyyzzz_1[j];

                    tg_yyyzzz_xyyzzzz_0[j] = pb_y * tg_yyzzz_xyyzzzz_0[j] + fr * tg_yyzzz_xyyzzzz_1[j] + fl1_fx * (tg_yzzz_xyyzzzz_0[j] - tg_yzzz_xyyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_xyzzzz_1[j];

                    tg_yyyzzz_xyzzzzz_0[j] = pb_y * tg_yyzzz_xyzzzzz_0[j] + fr * tg_yyzzz_xyzzzzz_1[j] + fl1_fx * (tg_yzzz_xyzzzzz_0[j] - tg_yzzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_xzzzzz_1[j];

                    tg_yyyzzz_xzzzzzz_0[j] = pb_y * tg_yyzzz_xzzzzzz_0[j] + fr * tg_yyzzz_xzzzzzz_1[j] + fl1_fx * (tg_yzzz_xzzzzzz_0[j] - tg_yzzz_xzzzzzz_1[j] * fl1_fza);

                    tg_yyyzzz_yyyyyyy_0[j] = pb_y * tg_yyzzz_yyyyyyy_0[j] + fr * tg_yyzzz_yyyyyyy_1[j] + fl1_fx * (tg_yzzz_yyyyyyy_0[j] - tg_yzzz_yyyyyyy_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_yyzzz_yyyyyy_1[j];

                    tg_yyyzzz_yyyyyyz_0[j] = pb_y * tg_yyzzz_yyyyyyz_0[j] + fr * tg_yyzzz_yyyyyyz_1[j] + fl1_fx * (tg_yzzz_yyyyyyz_0[j] - tg_yzzz_yyyyyyz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yyzzz_yyyyyz_1[j];

                    tg_yyyzzz_yyyyyzz_0[j] = pb_y * tg_yyzzz_yyyyyzz_0[j] + fr * tg_yyzzz_yyyyyzz_1[j] + fl1_fx * (tg_yzzz_yyyyyzz_0[j] - tg_yzzz_yyyyyzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yyzzz_yyyyzz_1[j];

                    tg_yyyzzz_yyyyzzz_0[j] = pb_y * tg_yyzzz_yyyyzzz_0[j] + fr * tg_yyzzz_yyyyzzz_1[j] + fl1_fx * (tg_yzzz_yyyyzzz_0[j] - tg_yzzz_yyyyzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yyzzz_yyyzzz_1[j];

                    tg_yyyzzz_yyyzzzz_0[j] = pb_y * tg_yyzzz_yyyzzzz_0[j] + fr * tg_yyzzz_yyyzzzz_1[j] + fl1_fx * (tg_yzzz_yyyzzzz_0[j] - tg_yzzz_yyyzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yyzzz_yyzzzz_1[j];

                    tg_yyyzzz_yyzzzzz_0[j] = pb_y * tg_yyzzz_yyzzzzz_0[j] + fr * tg_yyzzz_yyzzzzz_1[j] + fl1_fx * (tg_yzzz_yyzzzzz_0[j] - tg_yzzz_yyzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yyzzz_yzzzzz_1[j];

                    tg_yyyzzz_yzzzzzz_0[j] = pb_y * tg_yyzzz_yzzzzzz_0[j] + fr * tg_yyzzz_yzzzzzz_1[j] + fl1_fx * (tg_yzzz_yzzzzzz_0[j] - tg_yzzz_yzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yyzzz_zzzzzz_1[j];

                    tg_yyyzzz_zzzzzzz_0[j] = pb_y * tg_yyzzz_zzzzzzz_0[j] + fr * tg_yyzzz_zzzzzzz_1[j] + fl1_fx * (tg_yzzz_zzzzzzz_0[j] - tg_yzzz_zzzzzzz_1[j] * fl1_fza);

                    tg_yyzzzz_xxxxxxx_0[j] = pb_y * tg_yzzzz_xxxxxxx_0[j] + fr * tg_yzzzz_xxxxxxx_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxx_0[j] - tg_zzzz_xxxxxxx_1[j] * fl1_fza);

                    tg_yyzzzz_xxxxxxy_0[j] = pb_y * tg_yzzzz_xxxxxxy_0[j] + fr * tg_yzzzz_xxxxxxy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxy_0[j] - tg_zzzz_xxxxxxy_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xxxxxx_1[j];

                    tg_yyzzzz_xxxxxxz_0[j] = pb_y * tg_yzzzz_xxxxxxz_0[j] + fr * tg_yzzzz_xxxxxxz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxxz_0[j] - tg_zzzz_xxxxxxz_1[j] * fl1_fza);

                    tg_yyzzzz_xxxxxyy_0[j] = pb_y * tg_yzzzz_xxxxxyy_0[j] + fr * tg_yzzzz_xxxxxyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxyy_0[j] - tg_zzzz_xxxxxyy_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xxxxxy_1[j];

                    tg_yyzzzz_xxxxxyz_0[j] = pb_y * tg_yzzzz_xxxxxyz_0[j] + fr * tg_yzzzz_xxxxxyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxyz_0[j] - tg_zzzz_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xxxxxz_1[j];

                    tg_yyzzzz_xxxxxzz_0[j] = pb_y * tg_yzzzz_xxxxxzz_0[j] + fr * tg_yzzzz_xxxxxzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxxzz_0[j] - tg_zzzz_xxxxxzz_1[j] * fl1_fza);

                    tg_yyzzzz_xxxxyyy_0[j] = pb_y * tg_yzzzz_xxxxyyy_0[j] + fr * tg_yzzzz_xxxxyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyyy_0[j] - tg_zzzz_xxxxyyy_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_xxxxyy_1[j];

                    tg_yyzzzz_xxxxyyz_0[j] = pb_y * tg_yzzzz_xxxxyyz_0[j] + fr * tg_yzzzz_xxxxyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyyz_0[j] - tg_zzzz_xxxxyyz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xxxxyz_1[j];

                    tg_yyzzzz_xxxxyzz_0[j] = pb_y * tg_yzzzz_xxxxyzz_0[j] + fr * tg_yzzzz_xxxxyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxyzz_0[j] - tg_zzzz_xxxxyzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xxxxzz_1[j];

                    tg_yyzzzz_xxxxzzz_0[j] = pb_y * tg_yzzzz_xxxxzzz_0[j] + fr * tg_yzzzz_xxxxzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxxzzz_0[j] - tg_zzzz_xxxxzzz_1[j] * fl1_fza);

                    tg_yyzzzz_xxxyyyy_0[j] = pb_y * tg_yzzzz_xxxyyyy_0[j] + fr * tg_yzzzz_xxxyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyyy_0[j] - tg_zzzz_xxxyyyy_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yzzzz_xxxyyy_1[j];

                    tg_yyzzzz_xxxyyyz_0[j] = pb_y * tg_yzzzz_xxxyyyz_0[j] + fr * tg_yzzzz_xxxyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyyz_0[j] - tg_zzzz_xxxyyyz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_xxxyyz_1[j];

                    tg_yyzzzz_xxxyyzz_0[j] = pb_y * tg_yzzzz_xxxyyzz_0[j] + fr * tg_yzzzz_xxxyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyyzz_0[j] - tg_zzzz_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xxxyzz_1[j];

                    tg_yyzzzz_xxxyzzz_0[j] = pb_y * tg_yzzzz_xxxyzzz_0[j] + fr * tg_yzzzz_xxxyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxyzzz_0[j] - tg_zzzz_xxxyzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xxxzzz_1[j];

                    tg_yyzzzz_xxxzzzz_0[j] = pb_y * tg_yzzzz_xxxzzzz_0[j] + fr * tg_yzzzz_xxxzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxxzzzz_0[j] - tg_zzzz_xxxzzzz_1[j] * fl1_fza);

                    tg_yyzzzz_xxyyyyy_0[j] = pb_y * tg_yzzzz_xxyyyyy_0[j] + fr * tg_yzzzz_xxyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyyy_0[j] - tg_zzzz_xxyyyyy_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yzzzz_xxyyyy_1[j];

                    tg_yyzzzz_xxyyyyz_0[j] = pb_y * tg_yzzzz_xxyyyyz_0[j] + fr * tg_yzzzz_xxyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyyz_0[j] - tg_zzzz_xxyyyyz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yzzzz_xxyyyz_1[j];
                }

                idx++;
            }
        }
    }

    void
    compElectronRepulsionForSISK_917_1008(      CMemBlock2D<double>* primBuffer,
                                          const CRecursionMap&       recursionMap,
                                          const CMemBlock2D<double>& osFactors,
                                          const CMemBlock2D<double>& wpDistances,
                                          const CGtoPairsBlock&      braGtoPairsBlock,
                                          const CGtoPairsBlock&      ketGtoPairsBlock,
                                          const int32_t              nKetPrimPairs,
                                          const int32_t              iContrPair)
    {
        // Batch of Integrals (917,1008)

        // set up pointers to primitives data on bra side

        auto spos = braGtoPairsBlock.getStartPositions();

        auto epos = braGtoPairsBlock.getEndPositions();

        // set up pointers to tensor of distance R(PB) = P - B

        auto r_pb_y = braGtoPairsBlock.getDistancesPBY();

        auto r_pb_z = braGtoPairsBlock.getDistancesPBZ();

        // set up pointers to common Obara-Saika factors

        auto b_fx = braGtoPairsBlock.getFactorsOneOverXi();

        // set up maximum order of integral

        auto mord = recursionMap.getMaxOrder({"Electron Repulsion"},
                                             {6, -1, -1, -1},
                                             {7, -1, -1, -1},
                                             1, 1);

        for (int32_t iord = 0; iord <= mord; iord++)
        {
            // set up index of integral

            auto pidx_g_6_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {6, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            // check if integral is needed in recursion expansion

            if (pidx_g_6_7_m0 == -1) continue;

            // set up indexes of auxilary integral

            auto pidx_g_5_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_5_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_4_7_m0 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord));

            auto pidx_g_4_7_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {4, -1, -1, -1}, {7, -1, -1, -1}, 
                                                                   1, 1, iord + 1));

            auto pidx_g_5_6_m1 = recursionMap.index(CRecursionTerm({"Electron Repulsion"}, 0, true, 
                                                                   {5, -1, -1, -1}, {6, -1, -1, -1}, 
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

                auto pb_y = r_pb_y[i];

                auto pb_z = r_pb_z[i];

                // set up pointers to tensors product of distances R(WP) = W - P

                auto wp_y = wpDistances.data(3 * idx + 1);

                auto wp_z = wpDistances.data(3 * idx + 2);

                // set up pointers to auxilary integrals

                auto tg_yzzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 701); 

                auto tg_yzzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 702); 

                auto tg_yzzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 703); 

                auto tg_yzzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 704); 

                auto tg_yzzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 705); 

                auto tg_yzzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 706); 

                auto tg_yzzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 707); 

                auto tg_yzzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 708); 

                auto tg_yzzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 709); 

                auto tg_yzzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 710); 

                auto tg_yzzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 711); 

                auto tg_yzzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 712); 

                auto tg_yzzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 713); 

                auto tg_yzzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 714); 

                auto tg_yzzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 715); 

                auto tg_yzzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 716); 

                auto tg_yzzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 717); 

                auto tg_yzzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 718); 

                auto tg_yzzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 719); 

                auto tg_zzzzz_xxxxxxx_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 720); 

                auto tg_zzzzz_xxxxxxy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 721); 

                auto tg_zzzzz_xxxxxxz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 722); 

                auto tg_zzzzz_xxxxxyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 723); 

                auto tg_zzzzz_xxxxxyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 724); 

                auto tg_zzzzz_xxxxxzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 725); 

                auto tg_zzzzz_xxxxyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 726); 

                auto tg_zzzzz_xxxxyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 727); 

                auto tg_zzzzz_xxxxyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 728); 

                auto tg_zzzzz_xxxxzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 729); 

                auto tg_zzzzz_xxxyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 730); 

                auto tg_zzzzz_xxxyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 731); 

                auto tg_zzzzz_xxxyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 732); 

                auto tg_zzzzz_xxxyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 733); 

                auto tg_zzzzz_xxxzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 734); 

                auto tg_zzzzz_xxyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 735); 

                auto tg_zzzzz_xxyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 736); 

                auto tg_zzzzz_xxyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 737); 

                auto tg_zzzzz_xxyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 738); 

                auto tg_zzzzz_xxyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 739); 

                auto tg_zzzzz_xxzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 740); 

                auto tg_zzzzz_xyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 741); 

                auto tg_zzzzz_xyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 742); 

                auto tg_zzzzz_xyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 743); 

                auto tg_zzzzz_xyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 744); 

                auto tg_zzzzz_xyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 745); 

                auto tg_zzzzz_xyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 746); 

                auto tg_zzzzz_xzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 747); 

                auto tg_zzzzz_yyyyyyy_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 748); 

                auto tg_zzzzz_yyyyyyz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 749); 

                auto tg_zzzzz_yyyyyzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 750); 

                auto tg_zzzzz_yyyyzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 751); 

                auto tg_zzzzz_yyyzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 752); 

                auto tg_zzzzz_yyzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 753); 

                auto tg_zzzzz_yzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 754); 

                auto tg_zzzzz_zzzzzzz_0 = primBuffer[pidx_g_5_7_m0].data(756 * idx + 755); 

                auto tg_yzzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 701); 

                auto tg_yzzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 702); 

                auto tg_yzzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 703); 

                auto tg_yzzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 704); 

                auto tg_yzzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 705); 

                auto tg_yzzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 706); 

                auto tg_yzzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 707); 

                auto tg_yzzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 708); 

                auto tg_yzzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 709); 

                auto tg_yzzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 710); 

                auto tg_yzzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 711); 

                auto tg_yzzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 712); 

                auto tg_yzzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 713); 

                auto tg_yzzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 714); 

                auto tg_yzzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 715); 

                auto tg_yzzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 716); 

                auto tg_yzzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 717); 

                auto tg_yzzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 718); 

                auto tg_yzzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 719); 

                auto tg_zzzzz_xxxxxxx_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 720); 

                auto tg_zzzzz_xxxxxxy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 721); 

                auto tg_zzzzz_xxxxxxz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 722); 

                auto tg_zzzzz_xxxxxyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 723); 

                auto tg_zzzzz_xxxxxyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 724); 

                auto tg_zzzzz_xxxxxzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 725); 

                auto tg_zzzzz_xxxxyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 726); 

                auto tg_zzzzz_xxxxyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 727); 

                auto tg_zzzzz_xxxxyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 728); 

                auto tg_zzzzz_xxxxzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 729); 

                auto tg_zzzzz_xxxyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 730); 

                auto tg_zzzzz_xxxyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 731); 

                auto tg_zzzzz_xxxyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 732); 

                auto tg_zzzzz_xxxyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 733); 

                auto tg_zzzzz_xxxzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 734); 

                auto tg_zzzzz_xxyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 735); 

                auto tg_zzzzz_xxyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 736); 

                auto tg_zzzzz_xxyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 737); 

                auto tg_zzzzz_xxyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 738); 

                auto tg_zzzzz_xxyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 739); 

                auto tg_zzzzz_xxzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 740); 

                auto tg_zzzzz_xyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 741); 

                auto tg_zzzzz_xyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 742); 

                auto tg_zzzzz_xyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 743); 

                auto tg_zzzzz_xyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 744); 

                auto tg_zzzzz_xyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 745); 

                auto tg_zzzzz_xyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 746); 

                auto tg_zzzzz_xzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 747); 

                auto tg_zzzzz_yyyyyyy_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 748); 

                auto tg_zzzzz_yyyyyyz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 749); 

                auto tg_zzzzz_yyyyyzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 750); 

                auto tg_zzzzz_yyyyzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 751); 

                auto tg_zzzzz_yyyzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 752); 

                auto tg_zzzzz_yyzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 753); 

                auto tg_zzzzz_yzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 754); 

                auto tg_zzzzz_zzzzzzz_1 = primBuffer[pidx_g_5_7_m1].data(756 * idx + 755); 

                auto tg_zzzz_xxxxxxx_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 520); 

                auto tg_zzzz_xxyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 521); 

                auto tg_zzzz_xxyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 522); 

                auto tg_zzzz_xxyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 523); 

                auto tg_zzzz_xxzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 524); 

                auto tg_zzzz_xyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 525); 

                auto tg_zzzz_xyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 526); 

                auto tg_zzzz_xyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 527); 

                auto tg_zzzz_xyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 528); 

                auto tg_zzzz_xyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 529); 

                auto tg_zzzz_xyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 530); 

                auto tg_zzzz_xzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 531); 

                auto tg_zzzz_yyyyyyy_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 532); 

                auto tg_zzzz_yyyyyyz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 533); 

                auto tg_zzzz_yyyyyzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 534); 

                auto tg_zzzz_yyyyzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 535); 

                auto tg_zzzz_yyyzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 536); 

                auto tg_zzzz_yyzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 537); 

                auto tg_zzzz_yzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 538); 

                auto tg_zzzz_zzzzzzz_0 = primBuffer[pidx_g_4_7_m0].data(540 * idx + 539); 

                auto tg_zzzz_xxxxxxx_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 504); 

                auto tg_zzzz_xxxxxxy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 505); 

                auto tg_zzzz_xxxxxxz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 506); 

                auto tg_zzzz_xxxxxyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 507); 

                auto tg_zzzz_xxxxxyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 508); 

                auto tg_zzzz_xxxxxzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 509); 

                auto tg_zzzz_xxxxyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 510); 

                auto tg_zzzz_xxxxyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 511); 

                auto tg_zzzz_xxxxyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 512); 

                auto tg_zzzz_xxxxzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 513); 

                auto tg_zzzz_xxxyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 514); 

                auto tg_zzzz_xxxyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 515); 

                auto tg_zzzz_xxxyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 516); 

                auto tg_zzzz_xxxyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 517); 

                auto tg_zzzz_xxxzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 518); 

                auto tg_zzzz_xxyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 519); 

                auto tg_zzzz_xxyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 520); 

                auto tg_zzzz_xxyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 521); 

                auto tg_zzzz_xxyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 522); 

                auto tg_zzzz_xxyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 523); 

                auto tg_zzzz_xxzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 524); 

                auto tg_zzzz_xyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 525); 

                auto tg_zzzz_xyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 526); 

                auto tg_zzzz_xyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 527); 

                auto tg_zzzz_xyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 528); 

                auto tg_zzzz_xyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 529); 

                auto tg_zzzz_xyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 530); 

                auto tg_zzzz_xzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 531); 

                auto tg_zzzz_yyyyyyy_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 532); 

                auto tg_zzzz_yyyyyyz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 533); 

                auto tg_zzzz_yyyyyzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 534); 

                auto tg_zzzz_yyyyzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 535); 

                auto tg_zzzz_yyyzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 536); 

                auto tg_zzzz_yyzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 537); 

                auto tg_zzzz_yzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 538); 

                auto tg_zzzz_zzzzzzz_1 = primBuffer[pidx_g_4_7_m1].data(540 * idx + 539); 

                auto tg_yzzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 544); 

                auto tg_yzzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 545); 

                auto tg_yzzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 546); 

                auto tg_yzzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 547); 

                auto tg_yzzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 548); 

                auto tg_yzzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 549); 

                auto tg_yzzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 550); 

                auto tg_yzzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 551); 

                auto tg_yzzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 552); 

                auto tg_yzzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 553); 

                auto tg_yzzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 554); 

                auto tg_yzzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 555); 

                auto tg_yzzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 556); 

                auto tg_yzzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 557); 

                auto tg_yzzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 558); 

                auto tg_yzzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 559); 

                auto tg_zzzzz_xxxxxx_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 560); 

                auto tg_zzzzz_xxxxxy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 561); 

                auto tg_zzzzz_xxxxxz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 562); 

                auto tg_zzzzz_xxxxyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 563); 

                auto tg_zzzzz_xxxxyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 564); 

                auto tg_zzzzz_xxxxzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 565); 

                auto tg_zzzzz_xxxyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 566); 

                auto tg_zzzzz_xxxyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 567); 

                auto tg_zzzzz_xxxyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 568); 

                auto tg_zzzzz_xxxzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 569); 

                auto tg_zzzzz_xxyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 570); 

                auto tg_zzzzz_xxyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 571); 

                auto tg_zzzzz_xxyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 572); 

                auto tg_zzzzz_xxyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 573); 

                auto tg_zzzzz_xxzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 574); 

                auto tg_zzzzz_xyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 575); 

                auto tg_zzzzz_xyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 576); 

                auto tg_zzzzz_xyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 577); 

                auto tg_zzzzz_xyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 578); 

                auto tg_zzzzz_xyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 579); 

                auto tg_zzzzz_xzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 580); 

                auto tg_zzzzz_yyyyyy_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 581); 

                auto tg_zzzzz_yyyyyz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 582); 

                auto tg_zzzzz_yyyyzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 583); 

                auto tg_zzzzz_yyyzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 584); 

                auto tg_zzzzz_yyzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 585); 

                auto tg_zzzzz_yzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 586); 

                auto tg_zzzzz_zzzzzz_1 = primBuffer[pidx_g_5_6_m1].data(588 * idx + 587); 

                // set up pointers to integrals

                auto tg_yyzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 917); 

                auto tg_yyzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 918); 

                auto tg_yyzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 919); 

                auto tg_yyzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 920); 

                auto tg_yyzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 921); 

                auto tg_yyzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 922); 

                auto tg_yyzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 923); 

                auto tg_yyzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 924); 

                auto tg_yyzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 925); 

                auto tg_yyzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 926); 

                auto tg_yyzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 927); 

                auto tg_yyzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 928); 

                auto tg_yyzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 929); 

                auto tg_yyzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 930); 

                auto tg_yyzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 931); 

                auto tg_yyzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 932); 

                auto tg_yyzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 933); 

                auto tg_yyzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 934); 

                auto tg_yyzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 935); 

                auto tg_yzzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 936); 

                auto tg_yzzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 937); 

                auto tg_yzzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 938); 

                auto tg_yzzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 939); 

                auto tg_yzzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 940); 

                auto tg_yzzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 941); 

                auto tg_yzzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 942); 

                auto tg_yzzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 943); 

                auto tg_yzzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 944); 

                auto tg_yzzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 945); 

                auto tg_yzzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 946); 

                auto tg_yzzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 947); 

                auto tg_yzzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 948); 

                auto tg_yzzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 949); 

                auto tg_yzzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 950); 

                auto tg_yzzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 951); 

                auto tg_yzzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 952); 

                auto tg_yzzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 953); 

                auto tg_yzzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 954); 

                auto tg_yzzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 955); 

                auto tg_yzzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 956); 

                auto tg_yzzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 957); 

                auto tg_yzzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 958); 

                auto tg_yzzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 959); 

                auto tg_yzzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 960); 

                auto tg_yzzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 961); 

                auto tg_yzzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 962); 

                auto tg_yzzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 963); 

                auto tg_yzzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 964); 

                auto tg_yzzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 965); 

                auto tg_yzzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 966); 

                auto tg_yzzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 967); 

                auto tg_yzzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 968); 

                auto tg_yzzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 969); 

                auto tg_yzzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 970); 

                auto tg_yzzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 971); 

                auto tg_zzzzzz_xxxxxxx_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 972); 

                auto tg_zzzzzz_xxxxxxy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 973); 

                auto tg_zzzzzz_xxxxxxz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 974); 

                auto tg_zzzzzz_xxxxxyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 975); 

                auto tg_zzzzzz_xxxxxyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 976); 

                auto tg_zzzzzz_xxxxxzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 977); 

                auto tg_zzzzzz_xxxxyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 978); 

                auto tg_zzzzzz_xxxxyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 979); 

                auto tg_zzzzzz_xxxxyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 980); 

                auto tg_zzzzzz_xxxxzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 981); 

                auto tg_zzzzzz_xxxyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 982); 

                auto tg_zzzzzz_xxxyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 983); 

                auto tg_zzzzzz_xxxyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 984); 

                auto tg_zzzzzz_xxxyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 985); 

                auto tg_zzzzzz_xxxzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 986); 

                auto tg_zzzzzz_xxyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 987); 

                auto tg_zzzzzz_xxyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 988); 

                auto tg_zzzzzz_xxyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 989); 

                auto tg_zzzzzz_xxyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 990); 

                auto tg_zzzzzz_xxyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 991); 

                auto tg_zzzzzz_xxzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 992); 

                auto tg_zzzzzz_xyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 993); 

                auto tg_zzzzzz_xyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 994); 

                auto tg_zzzzzz_xyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 995); 

                auto tg_zzzzzz_xyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 996); 

                auto tg_zzzzzz_xyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 997); 

                auto tg_zzzzzz_xyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 998); 

                auto tg_zzzzzz_xzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 999); 

                auto tg_zzzzzz_yyyyyyy_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1000); 

                auto tg_zzzzzz_yyyyyyz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1001); 

                auto tg_zzzzzz_yyyyyzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1002); 

                auto tg_zzzzzz_yyyyzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1003); 

                auto tg_zzzzzz_yyyzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1004); 

                auto tg_zzzzzz_yyzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1005); 

                auto tg_zzzzzz_yzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1006); 

                auto tg_zzzzzz_zzzzzzz_0 = primBuffer[pidx_g_6_7_m0].data(1008 * idx + 1007); 

                // Batch of Integrals (917,1008)

                #pragma omp simd aligned(fxn, fza, tg_yyzzzz_xxyyyzz_0, tg_yyzzzz_xxyyzzz_0, \
                                         tg_yyzzzz_xxyzzzz_0, tg_yyzzzz_xxzzzzz_0, tg_yyzzzz_xyyyyyy_0, tg_yyzzzz_xyyyyyz_0, \
                                         tg_yyzzzz_xyyyyzz_0, tg_yyzzzz_xyyyzzz_0, tg_yyzzzz_xyyzzzz_0, tg_yyzzzz_xyzzzzz_0, \
                                         tg_yyzzzz_xzzzzzz_0, tg_yyzzzz_yyyyyyy_0, tg_yyzzzz_yyyyyyz_0, tg_yyzzzz_yyyyyzz_0, \
                                         tg_yyzzzz_yyyyzzz_0, tg_yyzzzz_yyyzzzz_0, tg_yyzzzz_yyzzzzz_0, tg_yyzzzz_yzzzzzz_0, \
                                         tg_yyzzzz_zzzzzzz_0, tg_yzzzz_xxyyyzz_0, tg_yzzzz_xxyyyzz_1, tg_yzzzz_xxyyzz_1, \
                                         tg_yzzzz_xxyyzzz_0, tg_yzzzz_xxyyzzz_1, tg_yzzzz_xxyzzz_1, tg_yzzzz_xxyzzzz_0, \
                                         tg_yzzzz_xxyzzzz_1, tg_yzzzz_xxzzzz_1, tg_yzzzz_xxzzzzz_0, tg_yzzzz_xxzzzzz_1, \
                                         tg_yzzzz_xyyyyy_1, tg_yzzzz_xyyyyyy_0, tg_yzzzz_xyyyyyy_1, tg_yzzzz_xyyyyyz_0, \
                                         tg_yzzzz_xyyyyyz_1, tg_yzzzz_xyyyyz_1, tg_yzzzz_xyyyyzz_0, tg_yzzzz_xyyyyzz_1, \
                                         tg_yzzzz_xyyyzz_1, tg_yzzzz_xyyyzzz_0, tg_yzzzz_xyyyzzz_1, tg_yzzzz_xyyzzz_1, \
                                         tg_yzzzz_xyyzzzz_0, tg_yzzzz_xyyzzzz_1, tg_yzzzz_xyzzzz_1, tg_yzzzz_xyzzzzz_0, \
                                         tg_yzzzz_xyzzzzz_1, tg_yzzzz_xzzzzz_1, tg_yzzzz_xzzzzzz_0, tg_yzzzz_xzzzzzz_1, \
                                         tg_yzzzz_yyyyyy_1, tg_yzzzz_yyyyyyy_0, tg_yzzzz_yyyyyyy_1, tg_yzzzz_yyyyyyz_0, \
                                         tg_yzzzz_yyyyyyz_1, tg_yzzzz_yyyyyz_1, tg_yzzzz_yyyyyzz_0, tg_yzzzz_yyyyyzz_1, \
                                         tg_yzzzz_yyyyzz_1, tg_yzzzz_yyyyzzz_0, tg_yzzzz_yyyyzzz_1, tg_yzzzz_yyyzzz_1, \
                                         tg_yzzzz_yyyzzzz_0, tg_yzzzz_yyyzzzz_1, tg_yzzzz_yyzzzz_1, tg_yzzzz_yyzzzzz_0, \
                                         tg_yzzzz_yyzzzzz_1, tg_yzzzz_yzzzzz_1, tg_yzzzz_yzzzzzz_0, tg_yzzzz_yzzzzzz_1, \
                                         tg_yzzzz_zzzzzz_1, tg_yzzzz_zzzzzzz_0, tg_yzzzz_zzzzzzz_1, tg_yzzzzz_xxxxxxx_0, \
                                         tg_yzzzzz_xxxxxxy_0, tg_yzzzzz_xxxxxxz_0, tg_yzzzzz_xxxxxyy_0, tg_yzzzzz_xxxxxyz_0, \
                                         tg_yzzzzz_xxxxxzz_0, tg_yzzzzz_xxxxyyy_0, tg_yzzzzz_xxxxyyz_0, tg_yzzzzz_xxxxyzz_0, \
                                         tg_yzzzzz_xxxxzzz_0, tg_yzzzzz_xxxyyyy_0, tg_yzzzzz_xxxyyyz_0, tg_yzzzzz_xxxyyzz_0, \
                                         tg_yzzzzz_xxxyzzz_0, tg_yzzzzz_xxxzzzz_0, tg_yzzzzz_xxyyyyy_0, tg_yzzzzz_xxyyyyz_0, \
                                         tg_yzzzzz_xxyyyzz_0, tg_yzzzzz_xxyyzzz_0, tg_yzzzzz_xxyzzzz_0, tg_yzzzzz_xxzzzzz_0, \
                                         tg_yzzzzz_xyyyyyy_0, tg_yzzzzz_xyyyyyz_0, tg_yzzzzz_xyyyyzz_0, tg_yzzzzz_xyyyzzz_0, \
                                         tg_yzzzzz_xyyzzzz_0, tg_yzzzzz_xyzzzzz_0, tg_yzzzzz_xzzzzzz_0, tg_yzzzzz_yyyyyyy_0, \
                                         tg_yzzzzz_yyyyyyz_0, tg_yzzzzz_yyyyyzz_0, tg_yzzzzz_yyyyzzz_0, tg_yzzzzz_yyyzzzz_0, \
                                         tg_yzzzzz_yyzzzzz_0, tg_yzzzzz_yzzzzzz_0, tg_yzzzzz_zzzzzzz_0, tg_zzzz_xxxxxxx_0, \
                                         tg_zzzz_xxxxxxx_1, tg_zzzz_xxxxxxy_0, tg_zzzz_xxxxxxy_1, tg_zzzz_xxxxxxz_0, \
                                         tg_zzzz_xxxxxxz_1, tg_zzzz_xxxxxyy_0, tg_zzzz_xxxxxyy_1, tg_zzzz_xxxxxyz_0, \
                                         tg_zzzz_xxxxxyz_1, tg_zzzz_xxxxxzz_0, tg_zzzz_xxxxxzz_1, tg_zzzz_xxxxyyy_0, \
                                         tg_zzzz_xxxxyyy_1, tg_zzzz_xxxxyyz_0, tg_zzzz_xxxxyyz_1, tg_zzzz_xxxxyzz_0, \
                                         tg_zzzz_xxxxyzz_1, tg_zzzz_xxxxzzz_0, tg_zzzz_xxxxzzz_1, tg_zzzz_xxxyyyy_0, \
                                         tg_zzzz_xxxyyyy_1, tg_zzzz_xxxyyyz_0, tg_zzzz_xxxyyyz_1, tg_zzzz_xxxyyzz_0, \
                                         tg_zzzz_xxxyyzz_1, tg_zzzz_xxxyzzz_0, tg_zzzz_xxxyzzz_1, tg_zzzz_xxxzzzz_0, \
                                         tg_zzzz_xxxzzzz_1, tg_zzzz_xxyyyyy_0, tg_zzzz_xxyyyyy_1, tg_zzzz_xxyyyyz_0, \
                                         tg_zzzz_xxyyyyz_1, tg_zzzz_xxyyyzz_0, tg_zzzz_xxyyyzz_1, tg_zzzz_xxyyzzz_0, \
                                         tg_zzzz_xxyyzzz_1, tg_zzzz_xxyzzzz_0, tg_zzzz_xxyzzzz_1, tg_zzzz_xxzzzzz_0, \
                                         tg_zzzz_xxzzzzz_1, tg_zzzz_xyyyyyy_0, tg_zzzz_xyyyyyy_1, tg_zzzz_xyyyyyz_0, \
                                         tg_zzzz_xyyyyyz_1, tg_zzzz_xyyyyzz_0, tg_zzzz_xyyyyzz_1, tg_zzzz_xyyyzzz_0, \
                                         tg_zzzz_xyyyzzz_1, tg_zzzz_xyyzzzz_0, tg_zzzz_xyyzzzz_1, tg_zzzz_xyzzzzz_0, \
                                         tg_zzzz_xyzzzzz_1, tg_zzzz_xzzzzzz_0, tg_zzzz_xzzzzzz_1, tg_zzzz_yyyyyyy_0, \
                                         tg_zzzz_yyyyyyy_1, tg_zzzz_yyyyyyz_0, tg_zzzz_yyyyyyz_1, tg_zzzz_yyyyyzz_0, \
                                         tg_zzzz_yyyyyzz_1, tg_zzzz_yyyyzzz_0, tg_zzzz_yyyyzzz_1, tg_zzzz_yyyzzzz_0, \
                                         tg_zzzz_yyyzzzz_1, tg_zzzz_yyzzzzz_0, tg_zzzz_yyzzzzz_1, tg_zzzz_yzzzzzz_0, \
                                         tg_zzzz_yzzzzzz_1, tg_zzzz_zzzzzzz_0, tg_zzzz_zzzzzzz_1, tg_zzzzz_xxxxxx_1, \
                                         tg_zzzzz_xxxxxxx_0, tg_zzzzz_xxxxxxx_1, tg_zzzzz_xxxxxxy_0, tg_zzzzz_xxxxxxy_1, \
                                         tg_zzzzz_xxxxxxz_0, tg_zzzzz_xxxxxxz_1, tg_zzzzz_xxxxxy_1, tg_zzzzz_xxxxxyy_0, \
                                         tg_zzzzz_xxxxxyy_1, tg_zzzzz_xxxxxyz_0, tg_zzzzz_xxxxxyz_1, tg_zzzzz_xxxxxz_1, \
                                         tg_zzzzz_xxxxxzz_0, tg_zzzzz_xxxxxzz_1, tg_zzzzz_xxxxyy_1, tg_zzzzz_xxxxyyy_0, \
                                         tg_zzzzz_xxxxyyy_1, tg_zzzzz_xxxxyyz_0, tg_zzzzz_xxxxyyz_1, tg_zzzzz_xxxxyz_1, \
                                         tg_zzzzz_xxxxyzz_0, tg_zzzzz_xxxxyzz_1, tg_zzzzz_xxxxzz_1, tg_zzzzz_xxxxzzz_0, \
                                         tg_zzzzz_xxxxzzz_1, tg_zzzzz_xxxyyy_1, tg_zzzzz_xxxyyyy_0, tg_zzzzz_xxxyyyy_1, \
                                         tg_zzzzz_xxxyyyz_0, tg_zzzzz_xxxyyyz_1, tg_zzzzz_xxxyyz_1, tg_zzzzz_xxxyyzz_0, \
                                         tg_zzzzz_xxxyyzz_1, tg_zzzzz_xxxyzz_1, tg_zzzzz_xxxyzzz_0, tg_zzzzz_xxxyzzz_1, \
                                         tg_zzzzz_xxxzzz_1, tg_zzzzz_xxxzzzz_0, tg_zzzzz_xxxzzzz_1, tg_zzzzz_xxyyyy_1, \
                                         tg_zzzzz_xxyyyyy_0, tg_zzzzz_xxyyyyy_1, tg_zzzzz_xxyyyyz_0, tg_zzzzz_xxyyyyz_1, \
                                         tg_zzzzz_xxyyyz_1, tg_zzzzz_xxyyyzz_0, tg_zzzzz_xxyyyzz_1, tg_zzzzz_xxyyzz_1, \
                                         tg_zzzzz_xxyyzzz_0, tg_zzzzz_xxyyzzz_1, tg_zzzzz_xxyzzz_1, tg_zzzzz_xxyzzzz_0, \
                                         tg_zzzzz_xxyzzzz_1, tg_zzzzz_xxzzzz_1, tg_zzzzz_xxzzzzz_0, tg_zzzzz_xxzzzzz_1, \
                                         tg_zzzzz_xyyyyy_1, tg_zzzzz_xyyyyyy_0, tg_zzzzz_xyyyyyy_1, tg_zzzzz_xyyyyyz_0, \
                                         tg_zzzzz_xyyyyyz_1, tg_zzzzz_xyyyyz_1, tg_zzzzz_xyyyyzz_0, tg_zzzzz_xyyyyzz_1, \
                                         tg_zzzzz_xyyyzz_1, tg_zzzzz_xyyyzzz_0, tg_zzzzz_xyyyzzz_1, tg_zzzzz_xyyzzz_1, \
                                         tg_zzzzz_xyyzzzz_0, tg_zzzzz_xyyzzzz_1, tg_zzzzz_xyzzzz_1, tg_zzzzz_xyzzzzz_0, \
                                         tg_zzzzz_xyzzzzz_1, tg_zzzzz_xzzzzz_1, tg_zzzzz_xzzzzzz_0, tg_zzzzz_xzzzzzz_1, \
                                         tg_zzzzz_yyyyyy_1, tg_zzzzz_yyyyyyy_0, tg_zzzzz_yyyyyyy_1, tg_zzzzz_yyyyyyz_0, \
                                         tg_zzzzz_yyyyyyz_1, tg_zzzzz_yyyyyz_1, tg_zzzzz_yyyyyzz_0, tg_zzzzz_yyyyyzz_1, \
                                         tg_zzzzz_yyyyzz_1, tg_zzzzz_yyyyzzz_0, tg_zzzzz_yyyyzzz_1, tg_zzzzz_yyyzzz_1, \
                                         tg_zzzzz_yyyzzzz_0, tg_zzzzz_yyyzzzz_1, tg_zzzzz_yyzzzz_1, tg_zzzzz_yyzzzzz_0, \
                                         tg_zzzzz_yyzzzzz_1, tg_zzzzz_yzzzzz_1, tg_zzzzz_yzzzzzz_0, tg_zzzzz_yzzzzzz_1, \
                                         tg_zzzzz_zzzzzz_1, tg_zzzzz_zzzzzzz_0, tg_zzzzz_zzzzzzz_1, tg_zzzzzz_xxxxxxx_0, \
                                         tg_zzzzzz_xxxxxxy_0, tg_zzzzzz_xxxxxxz_0, tg_zzzzzz_xxxxxyy_0, tg_zzzzzz_xxxxxyz_0, \
                                         tg_zzzzzz_xxxxxzz_0, tg_zzzzzz_xxxxyyy_0, tg_zzzzzz_xxxxyyz_0, tg_zzzzzz_xxxxyzz_0, \
                                         tg_zzzzzz_xxxxzzz_0, tg_zzzzzz_xxxyyyy_0, tg_zzzzzz_xxxyyyz_0, tg_zzzzzz_xxxyyzz_0, \
                                         tg_zzzzzz_xxxyzzz_0, tg_zzzzzz_xxxzzzz_0, tg_zzzzzz_xxyyyyy_0, tg_zzzzzz_xxyyyyz_0, \
                                         tg_zzzzzz_xxyyyzz_0, tg_zzzzzz_xxyyzzz_0, tg_zzzzzz_xxyzzzz_0, tg_zzzzzz_xxzzzzz_0, \
                                         tg_zzzzzz_xyyyyyy_0, tg_zzzzzz_xyyyyyz_0, tg_zzzzzz_xyyyyzz_0, tg_zzzzzz_xyyyzzz_0, \
                                         tg_zzzzzz_xyyzzzz_0, tg_zzzzzz_xyzzzzz_0, tg_zzzzzz_xzzzzzz_0, tg_zzzzzz_yyyyyyy_0, \
                                         tg_zzzzzz_yyyyyyz_0, tg_zzzzzz_yyyyyzz_0, tg_zzzzzz_yyyyzzz_0, tg_zzzzzz_yyyzzzz_0, \
                                         tg_zzzzzz_yyzzzzz_0, tg_zzzzzz_yzzzzzz_0, tg_zzzzzz_zzzzzzz_0, wp_y, wp_z: VLX_ALIGN)
                for (int32_t j = 0; j < nKetPrimPairs; j++)
                {
                    double fl1_fx = fx;

                    double fl1_fxn = fxn[j];

                    double fl1_fza = fza[j];

                    double fr = wp_y[j]; 

                    tg_yyzzzz_xxyyyzz_0[j] = pb_y * tg_yzzzz_xxyyyzz_0[j] + fr * tg_yzzzz_xxyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyyzz_0[j] - tg_zzzz_xxyyyzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_xxyyzz_1[j];

                    tg_yyzzzz_xxyyzzz_0[j] = pb_y * tg_yzzzz_xxyyzzz_0[j] + fr * tg_yzzzz_xxyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyyzzz_0[j] - tg_zzzz_xxyyzzz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xxyzzz_1[j];

                    tg_yyzzzz_xxyzzzz_0[j] = pb_y * tg_yzzzz_xxyzzzz_0[j] + fr * tg_yzzzz_xxyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxyzzzz_0[j] - tg_zzzz_xxyzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xxzzzz_1[j];

                    tg_yyzzzz_xxzzzzz_0[j] = pb_y * tg_yzzzz_xxzzzzz_0[j] + fr * tg_yzzzz_xxzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xxzzzzz_0[j] - tg_zzzz_xxzzzzz_1[j] * fl1_fza);

                    tg_yyzzzz_xyyyyyy_0[j] = pb_y * tg_yzzzz_xyyyyyy_0[j] + fr * tg_yzzzz_xyyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyyy_0[j] - tg_zzzz_xyyyyyy_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yzzzz_xyyyyy_1[j];

                    tg_yyzzzz_xyyyyyz_0[j] = pb_y * tg_yzzzz_xyyyyyz_0[j] + fr * tg_yzzzz_xyyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyyz_0[j] - tg_zzzz_xyyyyyz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yzzzz_xyyyyz_1[j];

                    tg_yyzzzz_xyyyyzz_0[j] = pb_y * tg_yzzzz_xyyyyzz_0[j] + fr * tg_yzzzz_xyyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyyzz_0[j] - tg_zzzz_xyyyyzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yzzzz_xyyyzz_1[j];

                    tg_yyzzzz_xyyyzzz_0[j] = pb_y * tg_yzzzz_xyyyzzz_0[j] + fr * tg_yzzzz_xyyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyyzzz_0[j] - tg_zzzz_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_xyyzzz_1[j];

                    tg_yyzzzz_xyyzzzz_0[j] = pb_y * tg_yzzzz_xyyzzzz_0[j] + fr * tg_yzzzz_xyyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyyzzzz_0[j] - tg_zzzz_xyyzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_xyzzzz_1[j];

                    tg_yyzzzz_xyzzzzz_0[j] = pb_y * tg_yzzzz_xyzzzzz_0[j] + fr * tg_yzzzz_xyzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xyzzzzz_0[j] - tg_zzzz_xyzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_xzzzzz_1[j];

                    tg_yyzzzz_xzzzzzz_0[j] = pb_y * tg_yzzzz_xzzzzzz_0[j] + fr * tg_yzzzz_xzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_xzzzzzz_0[j] - tg_zzzz_xzzzzzz_1[j] * fl1_fza);

                    tg_yyzzzz_yyyyyyy_0[j] = pb_y * tg_yzzzz_yyyyyyy_0[j] + fr * tg_yzzzz_yyyyyyy_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyyy_0[j] - tg_zzzz_yyyyyyy_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_yzzzz_yyyyyy_1[j];

                    tg_yyzzzz_yyyyyyz_0[j] = pb_y * tg_yzzzz_yyyyyyz_0[j] + fr * tg_yzzzz_yyyyyyz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyyz_0[j] - tg_zzzz_yyyyyyz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_yzzzz_yyyyyz_1[j];

                    tg_yyzzzz_yyyyyzz_0[j] = pb_y * tg_yzzzz_yyyyyzz_0[j] + fr * tg_yzzzz_yyyyyzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyyzz_0[j] - tg_zzzz_yyyyyzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_yzzzz_yyyyzz_1[j];

                    tg_yyzzzz_yyyyzzz_0[j] = pb_y * tg_yzzzz_yyyyzzz_0[j] + fr * tg_yzzzz_yyyyzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyyzzz_0[j] - tg_zzzz_yyyyzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_yzzzz_yyyzzz_1[j];

                    tg_yyzzzz_yyyzzzz_0[j] = pb_y * tg_yzzzz_yyyzzzz_0[j] + fr * tg_yzzzz_yyyzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyyzzzz_0[j] - tg_zzzz_yyyzzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_yzzzz_yyzzzz_1[j];

                    tg_yyzzzz_yyzzzzz_0[j] = pb_y * tg_yzzzz_yyzzzzz_0[j] + fr * tg_yzzzz_yyzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yyzzzzz_0[j] - tg_zzzz_yyzzzzz_1[j] * fl1_fza) + fl1_fxn * tg_yzzzz_yzzzzz_1[j];

                    tg_yyzzzz_yzzzzzz_0[j] = pb_y * tg_yzzzz_yzzzzzz_0[j] + fr * tg_yzzzz_yzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_yzzzzzz_0[j] - tg_zzzz_yzzzzzz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_yzzzz_zzzzzz_1[j];

                    tg_yyzzzz_zzzzzzz_0[j] = pb_y * tg_yzzzz_zzzzzzz_0[j] + fr * tg_yzzzz_zzzzzzz_1[j] + 0.5 * fl1_fx * (tg_zzzz_zzzzzzz_0[j] - tg_zzzz_zzzzzzz_1[j] * fl1_fza);

                    tg_yzzzzz_xxxxxxx_0[j] = pb_y * tg_zzzzz_xxxxxxx_0[j] + fr * tg_zzzzz_xxxxxxx_1[j];

                    tg_yzzzzz_xxxxxxy_0[j] = pb_y * tg_zzzzz_xxxxxxy_0[j] + fr * tg_zzzzz_xxxxxxy_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xxxxxx_1[j];

                    tg_yzzzzz_xxxxxxz_0[j] = pb_y * tg_zzzzz_xxxxxxz_0[j] + fr * tg_zzzzz_xxxxxxz_1[j];

                    tg_yzzzzz_xxxxxyy_0[j] = pb_y * tg_zzzzz_xxxxxyy_0[j] + fr * tg_zzzzz_xxxxxyy_1[j] + fl1_fxn * tg_zzzzz_xxxxxy_1[j];

                    tg_yzzzzz_xxxxxyz_0[j] = pb_y * tg_zzzzz_xxxxxyz_0[j] + fr * tg_zzzzz_xxxxxyz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xxxxxz_1[j];

                    tg_yzzzzz_xxxxxzz_0[j] = pb_y * tg_zzzzz_xxxxxzz_0[j] + fr * tg_zzzzz_xxxxxzz_1[j];

                    tg_yzzzzz_xxxxyyy_0[j] = pb_y * tg_zzzzz_xxxxyyy_0[j] + fr * tg_zzzzz_xxxxyyy_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxxxyy_1[j];

                    tg_yzzzzz_xxxxyyz_0[j] = pb_y * tg_zzzzz_xxxxyyz_0[j] + fr * tg_zzzzz_xxxxyyz_1[j] + fl1_fxn * tg_zzzzz_xxxxyz_1[j];

                    tg_yzzzzz_xxxxyzz_0[j] = pb_y * tg_zzzzz_xxxxyzz_0[j] + fr * tg_zzzzz_xxxxyzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xxxxzz_1[j];

                    tg_yzzzzz_xxxxzzz_0[j] = pb_y * tg_zzzzz_xxxxzzz_0[j] + fr * tg_zzzzz_xxxxzzz_1[j];

                    tg_yzzzzz_xxxyyyy_0[j] = pb_y * tg_zzzzz_xxxyyyy_0[j] + fr * tg_zzzzz_xxxyyyy_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxxyyy_1[j];

                    tg_yzzzzz_xxxyyyz_0[j] = pb_y * tg_zzzzz_xxxyyyz_0[j] + fr * tg_zzzzz_xxxyyyz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxxyyz_1[j];

                    tg_yzzzzz_xxxyyzz_0[j] = pb_y * tg_zzzzz_xxxyyzz_0[j] + fr * tg_zzzzz_xxxyyzz_1[j] + fl1_fxn * tg_zzzzz_xxxyzz_1[j];

                    tg_yzzzzz_xxxyzzz_0[j] = pb_y * tg_zzzzz_xxxyzzz_0[j] + fr * tg_zzzzz_xxxyzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xxxzzz_1[j];

                    tg_yzzzzz_xxxzzzz_0[j] = pb_y * tg_zzzzz_xxxzzzz_0[j] + fr * tg_zzzzz_xxxzzzz_1[j];

                    tg_yzzzzz_xxyyyyy_0[j] = pb_y * tg_zzzzz_xxyyyyy_0[j] + fr * tg_zzzzz_xxyyyyy_1[j] + 2.5 * fl1_fxn * tg_zzzzz_xxyyyy_1[j];

                    tg_yzzzzz_xxyyyyz_0[j] = pb_y * tg_zzzzz_xxyyyyz_0[j] + fr * tg_zzzzz_xxyyyyz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xxyyyz_1[j];

                    tg_yzzzzz_xxyyyzz_0[j] = pb_y * tg_zzzzz_xxyyyzz_0[j] + fr * tg_zzzzz_xxyyyzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xxyyzz_1[j];

                    tg_yzzzzz_xxyyzzz_0[j] = pb_y * tg_zzzzz_xxyyzzz_0[j] + fr * tg_zzzzz_xxyyzzz_1[j] + fl1_fxn * tg_zzzzz_xxyzzz_1[j];

                    tg_yzzzzz_xxyzzzz_0[j] = pb_y * tg_zzzzz_xxyzzzz_0[j] + fr * tg_zzzzz_xxyzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xxzzzz_1[j];

                    tg_yzzzzz_xxzzzzz_0[j] = pb_y * tg_zzzzz_xxzzzzz_0[j] + fr * tg_zzzzz_xxzzzzz_1[j];

                    tg_yzzzzz_xyyyyyy_0[j] = pb_y * tg_zzzzz_xyyyyyy_0[j] + fr * tg_zzzzz_xyyyyyy_1[j] + 3.0 * fl1_fxn * tg_zzzzz_xyyyyy_1[j];

                    tg_yzzzzz_xyyyyyz_0[j] = pb_y * tg_zzzzz_xyyyyyz_0[j] + fr * tg_zzzzz_xyyyyyz_1[j] + 2.5 * fl1_fxn * tg_zzzzz_xyyyyz_1[j];

                    tg_yzzzzz_xyyyyzz_0[j] = pb_y * tg_zzzzz_xyyyyzz_0[j] + fr * tg_zzzzz_xyyyyzz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_xyyyzz_1[j];

                    tg_yzzzzz_xyyyzzz_0[j] = pb_y * tg_zzzzz_xyyyzzz_0[j] + fr * tg_zzzzz_xyyyzzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_xyyzzz_1[j];

                    tg_yzzzzz_xyyzzzz_0[j] = pb_y * tg_zzzzz_xyyzzzz_0[j] + fr * tg_zzzzz_xyyzzzz_1[j] + fl1_fxn * tg_zzzzz_xyzzzz_1[j];

                    tg_yzzzzz_xyzzzzz_0[j] = pb_y * tg_zzzzz_xyzzzzz_0[j] + fr * tg_zzzzz_xyzzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_xzzzzz_1[j];

                    tg_yzzzzz_xzzzzzz_0[j] = pb_y * tg_zzzzz_xzzzzzz_0[j] + fr * tg_zzzzz_xzzzzzz_1[j];

                    tg_yzzzzz_yyyyyyy_0[j] = pb_y * tg_zzzzz_yyyyyyy_0[j] + fr * tg_zzzzz_yyyyyyy_1[j] + 3.5 * fl1_fxn * tg_zzzzz_yyyyyy_1[j];

                    tg_yzzzzz_yyyyyyz_0[j] = pb_y * tg_zzzzz_yyyyyyz_0[j] + fr * tg_zzzzz_yyyyyyz_1[j] + 3.0 * fl1_fxn * tg_zzzzz_yyyyyz_1[j];

                    tg_yzzzzz_yyyyyzz_0[j] = pb_y * tg_zzzzz_yyyyyzz_0[j] + fr * tg_zzzzz_yyyyyzz_1[j] + 2.5 * fl1_fxn * tg_zzzzz_yyyyzz_1[j];

                    tg_yzzzzz_yyyyzzz_0[j] = pb_y * tg_zzzzz_yyyyzzz_0[j] + fr * tg_zzzzz_yyyyzzz_1[j] + 2.0 * fl1_fxn * tg_zzzzz_yyyzzz_1[j];

                    tg_yzzzzz_yyyzzzz_0[j] = pb_y * tg_zzzzz_yyyzzzz_0[j] + fr * tg_zzzzz_yyyzzzz_1[j] + 1.5 * fl1_fxn * tg_zzzzz_yyzzzz_1[j];

                    tg_yzzzzz_yyzzzzz_0[j] = pb_y * tg_zzzzz_yyzzzzz_0[j] + fr * tg_zzzzz_yyzzzzz_1[j] + fl1_fxn * tg_zzzzz_yzzzzz_1[j];

                    tg_yzzzzz_yzzzzzz_0[j] = pb_y * tg_zzzzz_yzzzzzz_0[j] + fr * tg_zzzzz_yzzzzzz_1[j] + 0.5 * fl1_fxn * tg_zzzzz_zzzzzz_1[j];

                    tg_yzzzzz_zzzzzzz_0[j] = pb_y * tg_zzzzz_zzzzzzz_0[j] + fr * tg_zzzzz_zzzzzzz_1[j];

                    fr = wp_z[j]; 

                    tg_zzzzzz_xxxxxxx_0[j] = pb_z * tg_zzzzz_xxxxxxx_0[j] + fr * tg_zzzzz_xxxxxxx_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxxx_0[j] - tg_zzzz_xxxxxxx_1[j] * fl1_fza);

                    tg_zzzzzz_xxxxxxy_0[j] = pb_z * tg_zzzzz_xxxxxxy_0[j] + fr * tg_zzzzz_xxxxxxy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxxy_0[j] - tg_zzzz_xxxxxxy_1[j] * fl1_fza);

                    tg_zzzzzz_xxxxxxz_0[j] = pb_z * tg_zzzzz_xxxxxxz_0[j] + fr * tg_zzzzz_xxxxxxz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxxz_0[j] - tg_zzzz_xxxxxxz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xxxxxx_1[j];

                    tg_zzzzzz_xxxxxyy_0[j] = pb_z * tg_zzzzz_xxxxxyy_0[j] + fr * tg_zzzzz_xxxxxyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxyy_0[j] - tg_zzzz_xxxxxyy_1[j] * fl1_fza);

                    tg_zzzzzz_xxxxxyz_0[j] = pb_z * tg_zzzzz_xxxxxyz_0[j] + fr * tg_zzzzz_xxxxxyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxyz_0[j] - tg_zzzz_xxxxxyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xxxxxy_1[j];

                    tg_zzzzzz_xxxxxzz_0[j] = pb_z * tg_zzzzz_xxxxxzz_0[j] + fr * tg_zzzzz_xxxxxzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxxzz_0[j] - tg_zzzz_xxxxxzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xxxxxz_1[j];

                    tg_zzzzzz_xxxxyyy_0[j] = pb_z * tg_zzzzz_xxxxyyy_0[j] + fr * tg_zzzzz_xxxxyyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxyyy_0[j] - tg_zzzz_xxxxyyy_1[j] * fl1_fza);

                    tg_zzzzzz_xxxxyyz_0[j] = pb_z * tg_zzzzz_xxxxyyz_0[j] + fr * tg_zzzzz_xxxxyyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxyyz_0[j] - tg_zzzz_xxxxyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xxxxyy_1[j];

                    tg_zzzzzz_xxxxyzz_0[j] = pb_z * tg_zzzzz_xxxxyzz_0[j] + fr * tg_zzzzz_xxxxyzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxyzz_0[j] - tg_zzzz_xxxxyzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xxxxyz_1[j];

                    tg_zzzzzz_xxxxzzz_0[j] = pb_z * tg_zzzzz_xxxxzzz_0[j] + fr * tg_zzzzz_xxxxzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxxzzz_0[j] - tg_zzzz_xxxxzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_xxxxzz_1[j];

                    tg_zzzzzz_xxxyyyy_0[j] = pb_z * tg_zzzzz_xxxyyyy_0[j] + fr * tg_zzzzz_xxxyyyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxyyyy_0[j] - tg_zzzz_xxxyyyy_1[j] * fl1_fza);

                    tg_zzzzzz_xxxyyyz_0[j] = pb_z * tg_zzzzz_xxxyyyz_0[j] + fr * tg_zzzzz_xxxyyyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxyyyz_0[j] - tg_zzzz_xxxyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xxxyyy_1[j];

                    tg_zzzzzz_xxxyyzz_0[j] = pb_z * tg_zzzzz_xxxyyzz_0[j] + fr * tg_zzzzz_xxxyyzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxyyzz_0[j] - tg_zzzz_xxxyyzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xxxyyz_1[j];

                    tg_zzzzzz_xxxyzzz_0[j] = pb_z * tg_zzzzz_xxxyzzz_0[j] + fr * tg_zzzzz_xxxyzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxyzzz_0[j] - tg_zzzz_xxxyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_xxxyzz_1[j];

                    tg_zzzzzz_xxxzzzz_0[j] = pb_z * tg_zzzzz_xxxzzzz_0[j] + fr * tg_zzzzz_xxxzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxxzzzz_0[j] - tg_zzzz_xxxzzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_zzzzz_xxxzzz_1[j];

                    tg_zzzzzz_xxyyyyy_0[j] = pb_z * tg_zzzzz_xxyyyyy_0[j] + fr * tg_zzzzz_xxyyyyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxyyyyy_0[j] - tg_zzzz_xxyyyyy_1[j] * fl1_fza);

                    tg_zzzzzz_xxyyyyz_0[j] = pb_z * tg_zzzzz_xxyyyyz_0[j] + fr * tg_zzzzz_xxyyyyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxyyyyz_0[j] - tg_zzzz_xxyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xxyyyy_1[j];

                    tg_zzzzzz_xxyyyzz_0[j] = pb_z * tg_zzzzz_xxyyyzz_0[j] + fr * tg_zzzzz_xxyyyzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxyyyzz_0[j] - tg_zzzz_xxyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xxyyyz_1[j];

                    tg_zzzzzz_xxyyzzz_0[j] = pb_z * tg_zzzzz_xxyyzzz_0[j] + fr * tg_zzzzz_xxyyzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxyyzzz_0[j] - tg_zzzz_xxyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_xxyyzz_1[j];

                    tg_zzzzzz_xxyzzzz_0[j] = pb_z * tg_zzzzz_xxyzzzz_0[j] + fr * tg_zzzzz_xxyzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxyzzzz_0[j] - tg_zzzz_xxyzzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_zzzzz_xxyzzz_1[j];

                    tg_zzzzzz_xxzzzzz_0[j] = pb_z * tg_zzzzz_xxzzzzz_0[j] + fr * tg_zzzzz_xxzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xxzzzzz_0[j] - tg_zzzz_xxzzzzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_zzzzz_xxzzzz_1[j];

                    tg_zzzzzz_xyyyyyy_0[j] = pb_z * tg_zzzzz_xyyyyyy_0[j] + fr * tg_zzzzz_xyyyyyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyyyyyy_0[j] - tg_zzzz_xyyyyyy_1[j] * fl1_fza);

                    tg_zzzzzz_xyyyyyz_0[j] = pb_z * tg_zzzzz_xyyyyyz_0[j] + fr * tg_zzzzz_xyyyyyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyyyyyz_0[j] - tg_zzzz_xyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_xyyyyy_1[j];

                    tg_zzzzzz_xyyyyzz_0[j] = pb_z * tg_zzzzz_xyyyyzz_0[j] + fr * tg_zzzzz_xyyyyzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyyyyzz_0[j] - tg_zzzz_xyyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_xyyyyz_1[j];

                    tg_zzzzzz_xyyyzzz_0[j] = pb_z * tg_zzzzz_xyyyzzz_0[j] + fr * tg_zzzzz_xyyyzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyyyzzz_0[j] - tg_zzzz_xyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_xyyyzz_1[j];

                    tg_zzzzzz_xyyzzzz_0[j] = pb_z * tg_zzzzz_xyyzzzz_0[j] + fr * tg_zzzzz_xyyzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyyzzzz_0[j] - tg_zzzz_xyyzzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_zzzzz_xyyzzz_1[j];

                    tg_zzzzzz_xyzzzzz_0[j] = pb_z * tg_zzzzz_xyzzzzz_0[j] + fr * tg_zzzzz_xyzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xyzzzzz_0[j] - tg_zzzz_xyzzzzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_zzzzz_xyzzzz_1[j];

                    tg_zzzzzz_xzzzzzz_0[j] = pb_z * tg_zzzzz_xzzzzzz_0[j] + fr * tg_zzzzz_xzzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_xzzzzzz_0[j] - tg_zzzz_xzzzzzz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_zzzzz_xzzzzz_1[j];

                    tg_zzzzzz_yyyyyyy_0[j] = pb_z * tg_zzzzz_yyyyyyy_0[j] + fr * tg_zzzzz_yyyyyyy_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyyyyyy_0[j] - tg_zzzz_yyyyyyy_1[j] * fl1_fza);

                    tg_zzzzzz_yyyyyyz_0[j] = pb_z * tg_zzzzz_yyyyyyz_0[j] + fr * tg_zzzzz_yyyyyyz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyyyyyz_0[j] - tg_zzzz_yyyyyyz_1[j] * fl1_fza) + 0.5 * fl1_fxn * tg_zzzzz_yyyyyy_1[j];

                    tg_zzzzzz_yyyyyzz_0[j] = pb_z * tg_zzzzz_yyyyyzz_0[j] + fr * tg_zzzzz_yyyyyzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyyyyzz_0[j] - tg_zzzz_yyyyyzz_1[j] * fl1_fza) + fl1_fxn * tg_zzzzz_yyyyyz_1[j];

                    tg_zzzzzz_yyyyzzz_0[j] = pb_z * tg_zzzzz_yyyyzzz_0[j] + fr * tg_zzzzz_yyyyzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyyyzzz_0[j] - tg_zzzz_yyyyzzz_1[j] * fl1_fza) + 1.5 * fl1_fxn * tg_zzzzz_yyyyzz_1[j];

                    tg_zzzzzz_yyyzzzz_0[j] = pb_z * tg_zzzzz_yyyzzzz_0[j] + fr * tg_zzzzz_yyyzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyyzzzz_0[j] - tg_zzzz_yyyzzzz_1[j] * fl1_fza) + 2.0 * fl1_fxn * tg_zzzzz_yyyzzz_1[j];

                    tg_zzzzzz_yyzzzzz_0[j] = pb_z * tg_zzzzz_yyzzzzz_0[j] + fr * tg_zzzzz_yyzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yyzzzzz_0[j] - tg_zzzz_yyzzzzz_1[j] * fl1_fza) + 2.5 * fl1_fxn * tg_zzzzz_yyzzzz_1[j];

                    tg_zzzzzz_yzzzzzz_0[j] = pb_z * tg_zzzzz_yzzzzzz_0[j] + fr * tg_zzzzz_yzzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_yzzzzzz_0[j] - tg_zzzz_yzzzzzz_1[j] * fl1_fza) + 3.0 * fl1_fxn * tg_zzzzz_yzzzzz_1[j];

                    tg_zzzzzz_zzzzzzz_0[j] = pb_z * tg_zzzzz_zzzzzzz_0[j] + fr * tg_zzzzz_zzzzzzz_1[j] + 2.5 * fl1_fx * (tg_zzzz_zzzzzzz_0[j] - tg_zzzz_zzzzzzz_1[j] * fl1_fza) + 3.5 * fl1_fxn * tg_zzzzz_zzzzzz_1[j];
                }

                idx++;
            }
        }
    }


} // erirecfunc namespace

