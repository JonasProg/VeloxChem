//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "NuclearPotentialRecFuncForFF.hpp"

namespace npotrecfunc { // npotrecfunc namespace

    void
    compNuclearPotentialForFF(      CMemBlock2D<double>& primBuffer,
                              const CMemBlock2D<double>& auxBuffer,
                              const CMemBlock2D<double>& osFactors,
                              const CMemBlock2D<double>& paDistances,
                              const CMemBlock2D<double>& pbDistances,
                              const CMemBlock2D<double>& pcDistances,
                              const CGtoBlock&           braGtoBlock,
                              const CGtoBlock&           ketGtoBlock,
                              const int32_t              iContrGto)
    {
        npotrecfunc::compNuclearPotentialForFF_0_10(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                    braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_10_20(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_20_30(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_30_40(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_40_50(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_50_60(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_60_70(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_70_80(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_80_90(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                     braGtoBlock, ketGtoBlock, iContrGto); 

        npotrecfunc::compNuclearPotentialForFF_90_100(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, pcDistances, 
                                                      braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compNuclearPotentialForFF_0_10(      CMemBlock2D<double>& primBuffer,
                                   const CMemBlock2D<double>& auxBuffer,
                                   const CMemBlock2D<double>& osFactors,
                                   const CMemBlock2D<double>& paDistances,
                                   const CMemBlock2D<double>& pbDistances,
                                   const CMemBlock2D<double>& pcDistances,
                                   const CGtoBlock&           braGtoBlock,
                                   const CGtoBlock&           ketGtoBlock,
                                   const int32_t              iContrGto)
    {
        // Batch of Integrals (0,10)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(19 * idx + 3);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxx = paDistances.data(19 * idx + 9);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxx = pcDistances.data(83 * idx + 34);

            auto pc_xxxxy = pcDistances.data(83 * idx + 35);

            auto pc_xxxxz = pcDistances.data(83 * idx + 36);

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxxx = pcDistances.data(83 * idx + 55);

            auto pc_xxxxxy = pcDistances.data(83 * idx + 56);

            auto pc_xxxxxz = pcDistances.data(83 * idx + 57);

            auto pc_xxxxyy = pcDistances.data(83 * idx + 58);

            auto pc_xxxxyz = pcDistances.data(83 * idx + 59);

            auto pc_xxxxzz = pcDistances.data(83 * idx + 60);

            auto pc_xxxyyy = pcDistances.data(83 * idx + 61);

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxxzzz = pcDistances.data(83 * idx + 64);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xxx_xxx = primBuffer.data(100 * idx);

            auto t_xxx_xxy = primBuffer.data(100 * idx + 1);

            auto t_xxx_xxz = primBuffer.data(100 * idx + 2);

            auto t_xxx_xyy = primBuffer.data(100 * idx + 3);

            auto t_xxx_xyz = primBuffer.data(100 * idx + 4);

            auto t_xxx_xzz = primBuffer.data(100 * idx + 5);

            auto t_xxx_yyy = primBuffer.data(100 * idx + 6);

            auto t_xxx_yyz = primBuffer.data(100 * idx + 7);

            auto t_xxx_yzz = primBuffer.data(100 * idx + 8);

            auto t_xxx_zzz = primBuffer.data(100 * idx + 9);

            // Batch of Integrals (0,10)

            #pragma omp simd aligned(fx, pa_x, pa_xx, pa_xxx, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxx, pc_xxxxxx, pc_xxxxxy, pc_xxxxxz, \
                                     pc_xxxxy, pc_xxxxyy, pc_xxxxyz, pc_xxxxz, pc_xxxxzz, pc_xxxy, pc_xxxyy, pc_xxxyyy, \
                                     pc_xxxyyz, pc_xxxyz, pc_xxxyzz, pc_xxxz, pc_xxxzz, pc_xxxzzz, pc_xxy, pc_xxyy, \
                                     pc_xxyyy, pc_xxyyz, pc_xxyz, pc_xxyzz, pc_xxz, pc_xxzz, pc_xxzzz, pc_xy, pc_xyy, \
                                     pc_xyyy, pc_xyyz, pc_xyz, pc_xyzz, pc_xz, pc_xzz, pc_xzzz, pc_y, pc_yy, pc_yyy, pc_yyz, \
                                     pc_yz, pc_yzz, pc_z, pc_zz, pc_zzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, \
                                     s_0_0_5, s_0_0_6, t_xxx_xxx, t_xxx_xxy, t_xxx_xxz, t_xxx_xyy, t_xxx_xyz, \
                                     t_xxx_xzz, t_xxx_yyy, t_xxx_yyz, t_xxx_yzz, t_xxx_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxx_xxx[j] = fl_s_0_0_0 * (1.875 * fl3_fx + 2.25 * pa_xx[j] * fl2_fx + 6.75 * pa_x[j] * fl2_fx * pb_x[j] + 2.25 * fl2_fx * pb_xx[j] + 1.5 * pa_xxx[j] * pb_x[j] * fl1_fx + 4.5 * pa_xx[j] * fl1_fx * pb_xx[j] + 1.5 * pa_x[j] * fl1_fx * pb_xxx[j] + pa_xxx[j] * pb_xxx[j]);

                t_xxx_xxx[j] += fl_s_0_0_1 * (-5.625 * fl3_fx - 4.5 * pa_xx[j] * fl2_fx - 11.25 * pa_x[j] * pc_x[j] * fl2_fx - 13.5 * pa_x[j] * fl2_fx * pb_x[j] - 11.25 * pc_x[j] * fl2_fx * pb_x[j] - 4.5 * fl2_fx * pb_xx[j] - 1.5 * pa_xxx[j] * pb_x[j] * fl1_fx - 1.5 * pa_xxx[j] * pc_x[j] * fl1_fx - 13.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx - 4.5 * pa_xx[j] * fl1_fx * pb_xx[j] - 13.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] - 1.5 * pa_x[j] * fl1_fx * pb_xxx[j] - 1.5 * pc_x[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_xxx[j] * pb_xx[j] * pc_x[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xxx[j]);

                t_xxx_xxx[j] += fl_s_0_0_2 * (5.625 * fl3_fx + 2.25 * pa_xx[j] * fl2_fx + 22.5 * pa_x[j] * pc_x[j] * fl2_fx + 6.75 * pa_x[j] * fl2_fx * pb_x[j] + 11.25 * pc_xx[j] * fl2_fx + 22.5 * pc_x[j] * fl2_fx * pb_x[j] + 2.25 * fl2_fx * pb_xx[j] + 1.5 * pa_xxx[j] * pc_x[j] * fl1_fx + 13.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx + 9.0 * pa_xx[j] * pc_xx[j] * fl1_fx + 27.0 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx + 13.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] + 9.0 * pc_xx[j] * fl1_fx * pb_xx[j] + 1.5 * pc_x[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_xxx[j] * pb_x[j] * pc_xx[j] + 9.0 * pa_xx[j] * pc_xx[j] * pb_xx[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xxx[j]);

                t_xxx_xxx[j] += fl_s_0_0_3 * (-1.875 * fl3_fx - 11.25 * pa_x[j] * pc_x[j] * fl2_fx - 22.5 * pc_xx[j] * fl2_fx - 11.25 * pc_x[j] * fl2_fx * pb_x[j] - 9.0 * pa_xx[j] * pc_xx[j] * fl1_fx - 27.0 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx - 15.0 * pa_x[j] * pc_xxx[j] * fl1_fx - 15.0 * pc_xxx[j] * pb_x[j] * fl1_fx - 9.0 * pc_xx[j] * fl1_fx * pb_xx[j] - pa_xxx[j] * pc_xxx[j] - 9.0 * pa_xx[j] * pc_xxx[j] * pb_x[j] - 9.0 * pa_x[j] * pc_xxx[j] * pb_xx[j] - pc_xxx[j] * pb_xxx[j]);

                t_xxx_xxx[j] += fl_s_0_0_4 * (11.25 * pc_xx[j] * fl2_fx + 15.0 * pa_x[j] * pc_xxx[j] * fl1_fx + 15.0 * pc_xxx[j] * pb_x[j] * fl1_fx + 7.5 * pc_xxxx[j] * fl1_fx + 3.0 * pa_xx[j] * pc_xxxx[j] + 9.0 * pa_x[j] * pc_xxxx[j] * pb_x[j] + 3.0 * pc_xxxx[j] * pb_xx[j]);

                t_xxx_xxx[j] += fl_s_0_0_5 * (-7.5 * pc_xxxx[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxxx[j] - 3.0 * pc_xxxxx[j] * pb_x[j]);

                t_xxx_xxx[j] += fl_s_0_0_6 * pc_xxxxxx[j];

                t_xxx_xxy[j] = fl_s_0_0_0 * (2.25 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_y[j] + 3.0 * pa_xx[j] * fl1_fx * pb_xy[j] + 1.5 * pa_x[j] * fl1_fx * pb_xxy[j] + pa_xxx[j] * pb_xxy[j]);

                t_xxx_xxy[j] += fl_s_0_0_1 * (-2.25 * pa_x[j] * fl2_fx * pc_y[j] - 4.5 * pa_x[j] * fl2_fx * pb_y[j] - 3.75 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pb_x[j] * pc_y[j] - 3.0 * fl2_fx * pb_xy[j] - 0.5 * pa_xxx[j] * fl1_fx * pc_y[j] - 0.5 * pa_xxx[j] * fl1_fx * pb_y[j] - 4.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_y[j] - 3.0 * pa_xx[j] * fl1_fx * pb_x[j] * pc_y[j] - 3.0 * pa_xx[j] * fl1_fx * pb_xy[j] - 9.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] - 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_y[j] - 1.5 * pa_x[j] * fl1_fx * pb_xxy[j] - 1.5 * pc_x[j] * fl1_fx * pb_xxy[j] - pa_xxx[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xxx[j] * pb_xy[j] * pc_x[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xxy[j]);

                t_xxx_xxy[j] += fl_s_0_0_2 * (4.5 * pa_x[j] * fl2_fx * pc_y[j] + 2.25 * pa_x[j] * fl2_fx * pb_y[j] + 3.75 * pc_xy[j] * fl2_fx + 7.5 * pc_x[j] * fl2_fx * pb_y[j] + 3.0 * fl2_fx * pb_x[j] * pc_y[j] + 1.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xxx[j] * fl1_fx * pc_y[j] + 4.5 * pa_xx[j] * pc_xy[j] * fl1_fx + 4.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_y[j] + 3.0 * pa_xx[j] * fl1_fx * pb_x[j] * pc_y[j] + 9.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] + 9.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] + 9.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] + 6.0 * pc_xx[j] * fl1_fx * pb_xy[j] + 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_y[j] + 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] + 1.5 * pc_x[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_xxx[j] * pb_x[j] * pc_xy[j] + pa_xxx[j] * pc_xx[j] * pb_y[j] + 3.0 * pa_xx[j] * pc_xy[j] * pb_xx[j] + 6.0 * pa_xx[j] * pc_xx[j] * pb_xy[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xxy[j]);

                t_xxx_xxy[j] += fl_s_0_0_3 * (-2.25 * pa_x[j] * fl2_fx * pc_y[j] - 7.5 * pc_xy[j] * fl2_fx - 3.75 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pb_x[j] * pc_y[j] - 4.5 * pa_xx[j] * pc_xy[j] * fl1_fx - 9.0 * pa_x[j] * pc_xxy[j] * fl1_fx - 9.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] - 9.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] - 5.0 * pc_xxx[j] * fl1_fx * pb_y[j] - 6.0 * pc_xxy[j] * fl1_fx * pb_x[j] - 6.0 * pc_xx[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] - pa_xxx[j] * pc_xxy[j] - 6.0 * pa_xx[j] * pc_xxy[j] * pb_x[j] - 3.0 * pa_xx[j] * pc_xxx[j] * pb_y[j] - 3.0 * pa_x[j] * pc_xxy[j] * pb_xx[j] - 6.0 * pa_x[j] * pc_xxx[j] * pb_xy[j] - pc_xxx[j] * pb_xxy[j]);

                t_xxx_xxy[j] += fl_s_0_0_4 * (3.75 * pc_xy[j] * fl2_fx + 9.0 * pa_x[j] * pc_xxy[j] * fl1_fx + 5.0 * pc_xxxy[j] * fl1_fx + 5.0 * pc_xxx[j] * fl1_fx * pb_y[j] + 6.0 * pc_xxy[j] * fl1_fx * pb_x[j] + 3.0 * pa_xx[j] * pc_xxxy[j] + 6.0 * pa_x[j] * pc_xxxy[j] * pb_x[j] + 3.0 * pa_x[j] * pc_xxxx[j] * pb_y[j] + pc_xxxy[j] * pb_xx[j] + 2.0 * pc_xxxx[j] * pb_xy[j]);

                t_xxx_xxy[j] += fl_s_0_0_5 * (-5.0 * pc_xxxy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxxy[j] - 2.0 * pc_xxxxy[j] * pb_x[j] - pc_xxxxx[j] * pb_y[j]);

                t_xxx_xxy[j] += fl_s_0_0_6 * pc_xxxxxy[j];

                t_xxx_xxz[j] = fl_s_0_0_0 * (2.25 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_z[j] + 3.0 * pa_xx[j] * fl1_fx * pb_xz[j] + 1.5 * pa_x[j] * fl1_fx * pb_xxz[j] + pa_xxx[j] * pb_xxz[j]);

                t_xxx_xxz[j] += fl_s_0_0_1 * (-2.25 * pa_x[j] * fl2_fx * pc_z[j] - 4.5 * pa_x[j] * fl2_fx * pb_z[j] - 3.75 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_x[j] * pc_z[j] - 3.0 * fl2_fx * pb_xz[j] - 0.5 * pa_xxx[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxx[j] * fl1_fx * pb_z[j] - 4.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_z[j] - 3.0 * pa_xx[j] * fl1_fx * pb_x[j] * pc_z[j] - 3.0 * pa_xx[j] * fl1_fx * pb_xz[j] - 9.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] - 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_z[j] - 1.5 * pa_x[j] * fl1_fx * pb_xxz[j] - 1.5 * pc_x[j] * fl1_fx * pb_xxz[j] - pa_xxx[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xxx[j] * pb_xz[j] * pc_x[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xxz[j]);

                t_xxx_xxz[j] += fl_s_0_0_2 * (4.5 * pa_x[j] * fl2_fx * pc_z[j] + 2.25 * pa_x[j] * fl2_fx * pb_z[j] + 3.75 * pc_xz[j] * fl2_fx + 7.5 * pc_x[j] * fl2_fx * pb_z[j] + 3.0 * fl2_fx * pb_x[j] * pc_z[j] + 1.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xxx[j] * fl1_fx * pc_z[j] + 4.5 * pa_xx[j] * pc_xz[j] * fl1_fx + 4.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_z[j] + 3.0 * pa_xx[j] * fl1_fx * pb_x[j] * pc_z[j] + 9.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] + 9.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] + 9.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] + 6.0 * pc_xx[j] * fl1_fx * pb_xz[j] + 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_z[j] + 1.5 * pc_xz[j] * fl1_fx * pb_xx[j] + 1.5 * pc_x[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_xxx[j] * pb_x[j] * pc_xz[j] + pa_xxx[j] * pc_xx[j] * pb_z[j] + 3.0 * pa_xx[j] * pc_xz[j] * pb_xx[j] + 6.0 * pa_xx[j] * pc_xx[j] * pb_xz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xxz[j]);

                t_xxx_xxz[j] += fl_s_0_0_3 * (-2.25 * pa_x[j] * fl2_fx * pc_z[j] - 7.5 * pc_xz[j] * fl2_fx - 3.75 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_x[j] * pc_z[j] - 4.5 * pa_xx[j] * pc_xz[j] * fl1_fx - 9.0 * pa_x[j] * pc_xxz[j] * fl1_fx - 9.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] - 9.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] - 5.0 * pc_xxx[j] * fl1_fx * pb_z[j] - 6.0 * pc_xxz[j] * fl1_fx * pb_x[j] - 6.0 * pc_xx[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xz[j] * fl1_fx * pb_xx[j] - pa_xxx[j] * pc_xxz[j] - 6.0 * pa_xx[j] * pc_xxz[j] * pb_x[j] - 3.0 * pa_xx[j] * pc_xxx[j] * pb_z[j] - 3.0 * pa_x[j] * pc_xxz[j] * pb_xx[j] - 6.0 * pa_x[j] * pc_xxx[j] * pb_xz[j] - pc_xxx[j] * pb_xxz[j]);

                t_xxx_xxz[j] += fl_s_0_0_4 * (3.75 * pc_xz[j] * fl2_fx + 9.0 * pa_x[j] * pc_xxz[j] * fl1_fx + 5.0 * pc_xxxz[j] * fl1_fx + 5.0 * pc_xxx[j] * fl1_fx * pb_z[j] + 6.0 * pc_xxz[j] * fl1_fx * pb_x[j] + 3.0 * pa_xx[j] * pc_xxxz[j] + 6.0 * pa_x[j] * pc_xxxz[j] * pb_x[j] + 3.0 * pa_x[j] * pc_xxxx[j] * pb_z[j] + pc_xxxz[j] * pb_xx[j] + 2.0 * pc_xxxx[j] * pb_xz[j]);

                t_xxx_xxz[j] += fl_s_0_0_5 * (-5.0 * pc_xxxz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxxz[j] - 2.0 * pc_xxxxz[j] * pb_x[j] - pc_xxxxx[j] * pb_z[j]);

                t_xxx_xxz[j] += fl_s_0_0_6 * pc_xxxxxz[j];

                t_xxx_xyy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_yy[j] + 0.5 * pa_xxx[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 1.5 * pa_x[j] * fl1_fx * pb_xyy[j] + pa_xxx[j] * pb_xyy[j]);

                t_xxx_xyy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_xx[j] * fl2_fx - 2.25 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pb_y[j] * pc_y[j] - 1.5 * fl2_fx * pb_yy[j] - 0.5 * pa_xxx[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxx[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx - 3.0 * pa_xx[j] * fl1_fx * pb_y[j] * pc_y[j] - 1.5 * pa_xx[j] * fl1_fx * pb_yy[j] - 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] - 3.0 * pa_x[j] * fl1_fx * pb_xy[j] * pc_y[j] - 1.5 * pa_x[j] * fl1_fx * pb_xyy[j] - 1.5 * pc_x[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_xxx[j] * pb_xy[j] * pc_y[j] - pa_xxx[j] * pc_x[j] * pb_yy[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xyy[j]);

                t_xxx_xyy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 4.5 * pa_x[j] * pc_x[j] * fl2_fx + 1.5 * pc_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pc_yy[j] + 3.0 * fl2_fx * pb_y[j] * pc_y[j] + 0.75 * fl2_fx * pb_yy[j] + 0.5 * pa_xxx[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xx[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pc_yy[j] + 3.0 * pa_xx[j] * fl1_fx * pb_y[j] * pc_y[j] + 1.5 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx + 9.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] + 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] + 3.0 * pc_xx[j] * fl1_fx * pb_yy[j] + 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yy[j] + 3.0 * pa_x[j] * fl1_fx * pb_xy[j] * pc_y[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] + 1.5 * pc_x[j] * fl1_fx * pb_xyy[j] + pa_xxx[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xxx[j] * pc_xy[j] * pb_y[j] + 6.0 * pa_xx[j] * pc_xy[j] * pb_xy[j] + 3.0 * pa_xx[j] * pc_xx[j] * pb_yy[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xyy[j]);

                t_xxx_xyy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_x[j] * pc_x[j] * fl2_fx - 3.0 * pc_xx[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_yy[j] - 1.5 * fl2_fx * pb_y[j] * pc_y[j] - 1.5 * pa_xx[j] * pc_xx[j] * fl1_fx - 1.5 * pa_xx[j] * fl1_fx * pc_yy[j] - 1.5 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xxx[j] * fl1_fx - 4.5 * pa_x[j] * pc_xyy[j] * fl1_fx - 9.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xxx[j] * pb_x[j] * fl1_fx - 6.0 * pc_xxy[j] * fl1_fx * pb_y[j] - 3.0 * pc_xx[j] * fl1_fx * pb_yy[j] - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yy[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] - pa_xxx[j] * pc_xyy[j] - 3.0 * pa_xx[j] * pc_xyy[j] * pb_x[j] - 6.0 * pa_xx[j] * pc_xxy[j] * pb_y[j] - 6.0 * pa_x[j] * pc_xxy[j] * pb_xy[j] - 3.0 * pa_x[j] * pc_xxx[j] * pb_yy[j] - pc_xxx[j] * pb_xyy[j]);

                t_xxx_xyy[j] += fl_s_0_0_4 * (1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pc_yy[j] + 1.5 * pa_x[j] * pc_xxx[j] * fl1_fx + 4.5 * pa_x[j] * pc_xyy[j] * fl1_fx + 0.5 * pc_xxx[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxxx[j] * fl1_fx + 3.0 * pc_xxyy[j] * fl1_fx + 6.0 * pc_xxy[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyy[j] * fl1_fx * pb_x[j] + 3.0 * pa_xx[j] * pc_xxyy[j] + 3.0 * pa_x[j] * pc_xxyy[j] * pb_x[j] + 6.0 * pa_x[j] * pc_xxxy[j] * pb_y[j] + 2.0 * pc_xxxy[j] * pb_xy[j] + pc_xxxx[j] * pb_yy[j]);

                t_xxx_xyy[j] += fl_s_0_0_5 * (-0.5 * pc_xxxx[j] * fl1_fx - 3.0 * pc_xxyy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxyy[j] - pc_xxxyy[j] * pb_x[j] - 2.0 * pc_xxxxy[j] * pb_y[j]);

                t_xxx_xyy[j] += fl_s_0_0_6 * pc_xxxxyy[j];

                t_xxx_xyz[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_xx[j] * fl1_fx * pb_yz[j] + 1.5 * pa_x[j] * fl1_fx * pb_xyz[j] + pa_xxx[j] * pb_xyz[j]);

                t_xxx_xyz[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pb_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * fl2_fx * pb_yz[j] - 1.5 * pa_xx[j] * fl1_fx * pb_y[j] * pc_z[j] - 1.5 * pa_xx[j] * fl1_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xx[j] * fl1_fx * pb_yz[j] - 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] - 1.5 * pa_x[j] * fl1_fx * pb_xy[j] * pc_z[j] - 1.5 * pa_x[j] * fl1_fx * pb_xz[j] * pc_y[j] - 1.5 * pa_x[j] * fl1_fx * pb_xyz[j] - 1.5 * pc_x[j] * fl1_fx * pb_xyz[j] - pa_xxx[j] * pb_xy[j] * pc_z[j] - pa_xxx[j] * pb_xz[j] * pc_y[j] - pa_xxx[j] * pc_x[j] * pb_yz[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xyz[j]);

                t_xxx_xyz[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pb_y[j] * pc_z[j] + 1.5 * fl2_fx * pc_y[j] * pb_z[j] + 0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_xx[j] * fl1_fx * pc_yz[j] + 1.5 * pa_xx[j] * fl1_fx * pb_y[j] * pc_z[j] + 1.5 * pa_xx[j] * fl1_fx * pc_y[j] * pb_z[j] + 4.5 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] + 4.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] + 3.0 * pc_xx[j] * fl1_fx * pb_yz[j] + 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yz[j] + 1.5 * pa_x[j] * fl1_fx * pb_xy[j] * pc_z[j] + 1.5 * pa_x[j] * fl1_fx * pb_xz[j] * pc_y[j] + 1.5 * pc_xz[j] * fl1_fx * pb_xy[j] + 1.5 * pc_xy[j] * fl1_fx * pb_xz[j] + 1.5 * pc_x[j] * fl1_fx * pb_xyz[j] + pa_xxx[j] * pb_x[j] * pc_yz[j] + pa_xxx[j] * pc_xz[j] * pb_y[j] + pa_xxx[j] * pc_xy[j] * pb_z[j] + 3.0 * pa_xx[j] * pc_xz[j] * pb_xy[j] + 3.0 * pa_xx[j] * pc_xy[j] * pb_xz[j] + 3.0 * pa_xx[j] * pc_xx[j] * pb_yz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xyz[j]);

                t_xxx_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pb_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xx[j] * fl1_fx * pc_yz[j] - 4.5 * pa_x[j] * pc_xyz[j] * fl1_fx - 4.5 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] - 4.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - 3.0 * pc_xxz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xxy[j] * fl1_fx * pb_z[j] - 3.0 * pc_xx[j] * fl1_fx * pb_yz[j] - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yz[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xz[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xy[j] * fl1_fx * pb_xz[j] - pa_xxx[j] * pc_xyz[j] - 3.0 * pa_xx[j] * pc_xyz[j] * pb_x[j] - 3.0 * pa_xx[j] * pc_xxz[j] * pb_y[j] - 3.0 * pa_xx[j] * pc_xxy[j] * pb_z[j] - 3.0 * pa_x[j] * pc_xxz[j] * pb_xy[j] - 3.0 * pa_x[j] * pc_xxy[j] * pb_xz[j] - 3.0 * pa_x[j] * pc_xxx[j] * pb_yz[j] - pc_xxx[j] * pb_xyz[j]);

                t_xxx_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 4.5 * pa_x[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xxz[j] * fl1_fx * pb_y[j] + 3.0 * pc_xxy[j] * fl1_fx * pb_z[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] + 3.0 * pa_xx[j] * pc_xxyz[j] + 3.0 * pa_x[j] * pc_xxyz[j] * pb_x[j] + 3.0 * pa_x[j] * pc_xxxz[j] * pb_y[j] + 3.0 * pa_x[j] * pc_xxxy[j] * pb_z[j] + pc_xxxz[j] * pb_xy[j] + pc_xxxy[j] * pb_xz[j] + pc_xxxx[j] * pb_yz[j]);

                t_xxx_xyz[j] += fl_s_0_0_5 * (-3.0 * pc_xxyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxyz[j] - pc_xxxyz[j] * pb_x[j] - pc_xxxxz[j] * pb_y[j] - pc_xxxxy[j] * pb_z[j]);

                t_xxx_xyz[j] += fl_s_0_0_6 * pc_xxxxyz[j];

                t_xxx_xzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_zz[j] + 0.5 * pa_xxx[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 1.5 * pa_x[j] * fl1_fx * pb_xzz[j] + pa_xxx[j] * pb_xzz[j]);

                t_xxx_xzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_xx[j] * fl2_fx - 2.25 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pb_z[j] * pc_z[j] - 1.5 * fl2_fx * pb_zz[j] - 0.5 * pa_xxx[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxx[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx - 3.0 * pa_xx[j] * fl1_fx * pb_z[j] * pc_z[j] - 1.5 * pa_xx[j] * fl1_fx * pb_zz[j] - 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] - 3.0 * pa_x[j] * fl1_fx * pb_xz[j] * pc_z[j] - 1.5 * pa_x[j] * fl1_fx * pb_xzz[j] - 1.5 * pc_x[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_xxx[j] * pb_xz[j] * pc_z[j] - pa_xxx[j] * pc_x[j] * pb_zz[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_xzz[j]);

                t_xxx_xzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 4.5 * pa_x[j] * pc_x[j] * fl2_fx + 1.5 * pc_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pc_zz[j] + 3.0 * fl2_fx * pb_z[j] * pc_z[j] + 0.75 * fl2_fx * pb_zz[j] + 0.5 * pa_xxx[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_x[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xx[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pc_zz[j] + 3.0 * pa_xx[j] * fl1_fx * pb_z[j] * pc_z[j] + 1.5 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx + 9.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] + 4.5 * pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] + 3.0 * pc_xx[j] * fl1_fx * pb_zz[j] + 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_zz[j] + 3.0 * pa_x[j] * fl1_fx * pb_xz[j] * pc_z[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] + 1.5 * pc_x[j] * fl1_fx * pb_xzz[j] + pa_xxx[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xxx[j] * pc_xz[j] * pb_z[j] + 6.0 * pa_xx[j] * pc_xz[j] * pb_xz[j] + 3.0 * pa_xx[j] * pc_xx[j] * pb_zz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_xzz[j]);

                t_xxx_xzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_x[j] * pc_x[j] * fl2_fx - 3.0 * pc_xx[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pb_z[j] * pc_z[j] - 1.5 * pa_xx[j] * pc_xx[j] * fl1_fx - 1.5 * pa_xx[j] * fl1_fx * pc_zz[j] - 1.5 * pa_x[j] * pc_xx[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xxx[j] * fl1_fx - 4.5 * pa_x[j] * pc_xzz[j] * fl1_fx - 9.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xxx[j] * pb_x[j] * fl1_fx - 6.0 * pc_xxz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xx[j] * fl1_fx * pb_zz[j] - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_zz[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] - pa_xxx[j] * pc_xzz[j] - 3.0 * pa_xx[j] * pc_xzz[j] * pb_x[j] - 6.0 * pa_xx[j] * pc_xxz[j] * pb_z[j] - 6.0 * pa_x[j] * pc_xxz[j] * pb_xz[j] - 3.0 * pa_x[j] * pc_xxx[j] * pb_zz[j] - pc_xxx[j] * pb_xzz[j]);

                t_xxx_xzz[j] += fl_s_0_0_4 * (1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pc_zz[j] + 1.5 * pa_x[j] * pc_xxx[j] * fl1_fx + 4.5 * pa_x[j] * pc_xzz[j] * fl1_fx + 0.5 * pc_xxx[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxxx[j] * fl1_fx + 3.0 * pc_xxzz[j] * fl1_fx + 6.0 * pc_xxz[j] * fl1_fx * pb_z[j] + 1.5 * pc_xzz[j] * fl1_fx * pb_x[j] + 3.0 * pa_xx[j] * pc_xxzz[j] + 3.0 * pa_x[j] * pc_xxzz[j] * pb_x[j] + 6.0 * pa_x[j] * pc_xxxz[j] * pb_z[j] + 2.0 * pc_xxxz[j] * pb_xz[j] + pc_xxxx[j] * pb_zz[j]);

                t_xxx_xzz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxx[j] * fl1_fx - 3.0 * pc_xxzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxxzz[j] - pc_xxxzz[j] * pb_x[j] - 2.0 * pc_xxxxz[j] * pb_z[j]);

                t_xxx_xzz[j] += fl_s_0_0_6 * pc_xxxxzz[j];

                t_xxx_yyy[j] = fl_s_0_0_0 * (2.25 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xxx[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yyy[j] + pa_xxx[j] * pb_yyy[j]);

                t_xxx_yyy[j] += fl_s_0_0_1 * (-4.5 * pa_x[j] * fl2_fx * pb_y[j] - 2.25 * pa_x[j] * fl2_fx * pc_y[j] - 2.25 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * pa_xxx[j] * pb_y[j] * fl1_fx - 1.5 * pa_xxx[j] * pc_y[j] * fl1_fx - 4.5 * pa_xx[j] * pc_x[j] * pb_y[j] * fl1_fx - 4.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_y[j] - 1.5 * pa_x[j] * fl1_fx * pb_yyy[j] - 1.5 * pc_x[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_xxx[j] * pb_yy[j] * pc_y[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_yyy[j]);

                t_xxx_yyy[j] += fl_s_0_0_2 * (4.5 * pa_x[j] * fl2_fx * pc_y[j] + 2.25 * pa_x[j] * fl2_fx * pb_y[j] + 4.5 * pc_x[j] * fl2_fx * pb_y[j] + 2.25 * pc_xy[j] * fl2_fx + 1.5 * pa_xxx[j] * pc_y[j] * fl1_fx + 4.5 * pa_xx[j] * pc_x[j] * pb_y[j] * fl1_fx + 4.5 * pa_xx[j] * pc_xy[j] * fl1_fx + 4.5 * pa_x[j] * pc_xx[j] * pb_y[j] * fl1_fx + 4.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_yy[j] + 4.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_y[j] + 4.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 1.5 * pc_x[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_xxx[j] * pb_y[j] * pc_yy[j] + 9.0 * pa_xx[j] * pc_xy[j] * pb_yy[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_yyy[j]);

                t_xxx_yyy[j] += fl_s_0_0_3 * (-2.25 * pa_x[j] * fl2_fx * pc_y[j] - 4.5 * pc_xy[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_y[j] - 4.5 * pa_xx[j] * pc_xy[j] * fl1_fx - 4.5 * pa_x[j] * pc_xx[j] * pb_y[j] * fl1_fx - 4.5 * pa_x[j] * pc_xxy[j] * fl1_fx - 1.5 * pc_xxx[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pc_yyy[j] - 4.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_yy[j] - 4.5 * pc_xyy[j] * fl1_fx * pb_y[j] - 4.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pa_xxx[j] * pc_yyy[j] - 9.0 * pa_xx[j] * pc_xyy[j] * pb_y[j] - 9.0 * pa_x[j] * pc_xxy[j] * pb_yy[j] - pc_xxx[j] * pb_yyy[j]);

                t_xxx_yyy[j] += fl_s_0_0_4 * (2.25 * pc_xy[j] * fl2_fx + 4.5 * pa_x[j] * pc_xxy[j] * fl1_fx + 1.5 * pc_xxx[j] * pb_y[j] * fl1_fx + 1.5 * pc_xxxy[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pc_yyy[j] + 1.5 * pc_xyyy[j] * fl1_fx + 4.5 * pc_xyy[j] * fl1_fx * pb_y[j] + 3.0 * pa_xx[j] * pc_xyyy[j] + 9.0 * pa_x[j] * pc_xxyy[j] * pb_y[j] + 3.0 * pc_xxxy[j] * pb_yy[j]);

                t_xxx_yyy[j] += fl_s_0_0_5 * (-1.5 * pc_xxxy[j] * fl1_fx - 1.5 * pc_xyyy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxyyy[j] - 3.0 * pc_xxxyy[j] * pb_y[j]);

                t_xxx_yyy[j] += fl_s_0_0_6 * pc_xxxyyy[j];

                t_xxx_yyz[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * fl1_fx * pb_yyz[j] + pa_xxx[j] * pb_yyz[j]);

                t_xxx_yyz[j] += fl_s_0_0_1 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * pa_xxx[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxx[j] * fl1_fx * pb_z[j] - 1.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_z[j] - 1.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_z[j] - 3.0 * pa_x[j] * fl1_fx * pb_yz[j] * pc_y[j] - 1.5 * pa_x[j] * fl1_fx * pb_yyz[j] - 1.5 * pc_x[j] * fl1_fx * pb_yyz[j] - pa_xxx[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xxx[j] * pb_yz[j] * pc_y[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_yyz[j]);

                t_xxx_yyz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.75 * pa_x[j] * fl2_fx * pb_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xxx[j] * fl1_fx * pc_z[j] + 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx + 1.5 * pa_xx[j] * pc_x[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * fl1_fx * pb_y[j] * pc_yz[j] + 1.5 * pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] + 1.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_z[j] + 3.0 * pa_x[j] * fl1_fx * pb_yz[j] * pc_y[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 3.0 * pc_xy[j] * fl1_fx * pb_yz[j] + 1.5 * pc_x[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_xxx[j] * pb_y[j] * pc_yz[j] + pa_xxx[j] * pc_yy[j] * pb_z[j] + 3.0 * pa_xx[j] * pc_xz[j] * pb_yy[j] + 6.0 * pa_xx[j] * pc_xy[j] * pb_yz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_yyz[j]);

                t_xxx_yyz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx - 1.5 * pa_x[j] * pc_xxz[j] * fl1_fx - 1.5 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] - 1.5 * pa_x[j] * fl1_fx * pc_yyz[j] - 3.0 * pa_x[j] * fl1_fx * pb_y[j] * pc_yz[j] - 1.5 * pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] - 3.0 * pc_xy[j] * fl1_fx * pb_yz[j] - pa_xxx[j] * pc_yyz[j] - 6.0 * pa_xx[j] * pc_xyz[j] * pb_y[j] - 3.0 * pa_xx[j] * pc_xyy[j] * pb_z[j] - 3.0 * pa_x[j] * pc_xxz[j] * pb_yy[j] - 6.0 * pa_x[j] * pc_xxy[j] * pb_yz[j] - pc_xxx[j] * pb_yyz[j]);

                t_xxx_yyz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_x[j] * pc_xxz[j] * fl1_fx + 0.5 * pc_xxxz[j] * fl1_fx + 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * fl1_fx * pc_yyz[j] + 1.5 * pc_xyyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] + 3.0 * pa_xx[j] * pc_xyyz[j] + 6.0 * pa_x[j] * pc_xxyz[j] * pb_y[j] + 3.0 * pa_x[j] * pc_xxyy[j] * pb_z[j] + pc_xxxz[j] * pb_yy[j] + 2.0 * pc_xxxy[j] * pb_yz[j]);

                t_xxx_yyz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxz[j] * fl1_fx - 1.5 * pc_xyyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxyyz[j] - 2.0 * pc_xxxyz[j] * pb_y[j] - pc_xxxyy[j] * pb_z[j]);

                t_xxx_yyz[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_xxx_yzz[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xxx[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yzz[j] + pa_xxx[j] * pb_yzz[j]);

                t_xxx_yzz[j] += fl_s_0_0_1 * (-1.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pa_x[j] * fl2_fx * pc_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * pa_xxx[j] * pb_y[j] * fl1_fx - 0.5 * pa_xxx[j] * pc_y[j] * fl1_fx - 1.5 * pa_xx[j] * pc_x[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * fl1_fx * pb_yz[j] * pc_z[j] - 1.5 * pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] - 1.5 * pa_x[j] * fl1_fx * pb_yzz[j] - 1.5 * pc_x[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_xxx[j] * pb_yz[j] * pc_z[j] - pa_xxx[j] * pc_y[j] * pb_zz[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_yzz[j]);

                t_xxx_yzz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_y[j] + 0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_xxx[j] * pc_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_x[j] * pb_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx + 1.5 * pa_x[j] * pc_xx[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_zz[j] + 3.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] + 3.0 * pa_x[j] * fl1_fx * pb_yz[j] * pc_z[j] + 1.5 * pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] + 3.0 * pc_xz[j] * fl1_fx * pb_yz[j] + 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * fl1_fx * pb_yzz[j] + pa_xxx[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xxx[j] * pc_yz[j] * pb_z[j] + 6.0 * pa_xx[j] * pc_xz[j] * pb_yz[j] + 3.0 * pa_xx[j] * pc_xy[j] * pb_zz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_yzz[j]);

                t_xxx_yzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx - 1.5 * pa_x[j] * pc_xx[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * pc_xxy[j] * fl1_fx - 0.5 * pc_xxx[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pc_yzz[j] - 1.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_zz[j] - 3.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pb_yz[j] - 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] - pa_xxx[j] * pc_yzz[j] - 3.0 * pa_xx[j] * pc_xzz[j] * pb_y[j] - 6.0 * pa_xx[j] * pc_xyz[j] * pb_z[j] - 6.0 * pa_x[j] * pc_xxz[j] * pb_yz[j] - 3.0 * pa_x[j] * pc_xxy[j] * pb_zz[j] - pc_xxx[j] * pb_yzz[j]);

                t_xxx_yzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_xxy[j] * fl1_fx + 0.5 * pc_xxx[j] * pb_y[j] * fl1_fx + 0.5 * pc_xxxy[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pc_yzz[j] + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 3.0 * pa_xx[j] * pc_xyzz[j] + 3.0 * pa_x[j] * pc_xxzz[j] * pb_y[j] + 6.0 * pa_x[j] * pc_xxyz[j] * pb_z[j] + 2.0 * pc_xxxz[j] * pb_yz[j] + pc_xxxy[j] * pb_zz[j]);

                t_xxx_yzz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxyzz[j] - pc_xxxzz[j] * pb_y[j] - 2.0 * pc_xxxyz[j] * pb_z[j]);

                t_xxx_yzz[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_xxx_zzz[j] = fl_s_0_0_0 * (2.25 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xxx[j] * pb_z[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_zzz[j] + pa_xxx[j] * pb_zzz[j]);

                t_xxx_zzz[j] += fl_s_0_0_1 * (-4.5 * pa_x[j] * fl2_fx * pb_z[j] - 2.25 * pa_x[j] * fl2_fx * pc_z[j] - 2.25 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * pa_xxx[j] * pb_z[j] * fl1_fx - 1.5 * pa_xxx[j] * pc_z[j] * fl1_fx - 4.5 * pa_xx[j] * pc_x[j] * pb_z[j] * fl1_fx - 4.5 * pa_x[j] * fl1_fx * pb_zz[j] * pc_z[j] - 1.5 * pa_x[j] * fl1_fx * pb_zzz[j] - 1.5 * pc_x[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_xxx[j] * pb_zz[j] * pc_z[j] - 3.0 * pa_xx[j] * pc_x[j] * pb_zzz[j]);

                t_xxx_zzz[j] += fl_s_0_0_2 * (4.5 * pa_x[j] * fl2_fx * pc_z[j] + 2.25 * pa_x[j] * fl2_fx * pb_z[j] + 4.5 * pc_x[j] * fl2_fx * pb_z[j] + 2.25 * pc_xz[j] * fl2_fx + 1.5 * pa_xxx[j] * pc_z[j] * fl1_fx + 4.5 * pa_xx[j] * pc_x[j] * pb_z[j] * fl1_fx + 4.5 * pa_xx[j] * pc_xz[j] * fl1_fx + 4.5 * pa_x[j] * pc_xx[j] * pb_z[j] * fl1_fx + 4.5 * pa_x[j] * fl1_fx * pb_z[j] * pc_zz[j] + 4.5 * pa_x[j] * fl1_fx * pb_zz[j] * pc_z[j] + 4.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_xxx[j] * pb_z[j] * pc_zz[j] + 9.0 * pa_xx[j] * pc_xz[j] * pb_zz[j] + 3.0 * pa_x[j] * pc_xx[j] * pb_zzz[j]);

                t_xxx_zzz[j] += fl_s_0_0_3 * (-2.25 * pa_x[j] * fl2_fx * pc_z[j] - 4.5 * pc_xz[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_z[j] - 4.5 * pa_xx[j] * pc_xz[j] * fl1_fx - 4.5 * pa_x[j] * pc_xx[j] * pb_z[j] * fl1_fx - 4.5 * pa_x[j] * pc_xxz[j] * fl1_fx - 1.5 * pc_xxx[j] * pb_z[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pc_zzz[j] - 4.5 * pa_x[j] * fl1_fx * pb_z[j] * pc_zz[j] - 4.5 * pc_xzz[j] * fl1_fx * pb_z[j] - 4.5 * pc_xz[j] * fl1_fx * pb_zz[j] - pa_xxx[j] * pc_zzz[j] - 9.0 * pa_xx[j] * pc_xzz[j] * pb_z[j] - 9.0 * pa_x[j] * pc_xxz[j] * pb_zz[j] - pc_xxx[j] * pb_zzz[j]);

                t_xxx_zzz[j] += fl_s_0_0_4 * (2.25 * pc_xz[j] * fl2_fx + 4.5 * pa_x[j] * pc_xxz[j] * fl1_fx + 1.5 * pc_xxx[j] * pb_z[j] * fl1_fx + 1.5 * pc_xxxz[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pc_zzz[j] + 1.5 * pc_xzzz[j] * fl1_fx + 4.5 * pc_xzz[j] * fl1_fx * pb_z[j] + 3.0 * pa_xx[j] * pc_xzzz[j] + 9.0 * pa_x[j] * pc_xxzz[j] * pb_z[j] + 3.0 * pc_xxxz[j] * pb_zz[j]);

                t_xxx_zzz[j] += fl_s_0_0_5 * (-1.5 * pc_xxxz[j] * fl1_fx - 1.5 * pc_xzzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxzzz[j] - 3.0 * pc_xxxzz[j] * pb_z[j]);

                t_xxx_zzz[j] += fl_s_0_0_6 * pc_xxxzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_10_20(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (10,20)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(19 * idx + 3);

            auto pa_xy = paDistances.data(19 * idx + 4);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxy = paDistances.data(19 * idx + 10);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxx = pcDistances.data(83 * idx + 34);

            auto pc_xxxxy = pcDistances.data(83 * idx + 35);

            auto pc_xxxxz = pcDistances.data(83 * idx + 36);

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyyy = pcDistances.data(83 * idx + 44);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxxy = pcDistances.data(83 * idx + 56);

            auto pc_xxxxyy = pcDistances.data(83 * idx + 58);

            auto pc_xxxxyz = pcDistances.data(83 * idx + 59);

            auto pc_xxxyyy = pcDistances.data(83 * idx + 61);

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxyyyy = pcDistances.data(83 * idx + 65);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xxy_xxx = primBuffer.data(100 * idx + 10);

            auto t_xxy_xxy = primBuffer.data(100 * idx + 11);

            auto t_xxy_xxz = primBuffer.data(100 * idx + 12);

            auto t_xxy_xyy = primBuffer.data(100 * idx + 13);

            auto t_xxy_xyz = primBuffer.data(100 * idx + 14);

            auto t_xxy_xzz = primBuffer.data(100 * idx + 15);

            auto t_xxy_yyy = primBuffer.data(100 * idx + 16);

            auto t_xxy_yyz = primBuffer.data(100 * idx + 17);

            auto t_xxy_yzz = primBuffer.data(100 * idx + 18);

            auto t_xxy_zzz = primBuffer.data(100 * idx + 19);

            // Batch of Integrals (10,20)

            #pragma omp simd aligned(fx, pa_x, pa_xx, pa_xxy, pa_xy, pa_y, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxx, pc_xxxxxy, pc_xxxxy, pc_xxxxyy, \
                                     pc_xxxxyz, pc_xxxxz, pc_xxxy, pc_xxxyy, pc_xxxyyy, pc_xxxyyz, pc_xxxyz, pc_xxxyzz, \
                                     pc_xxxz, pc_xxxzz, pc_xxy, pc_xxyy, pc_xxyyy, pc_xxyyyy, pc_xxyyyz, pc_xxyyz, \
                                     pc_xxyyzz, pc_xxyz, pc_xxyzz, pc_xxyzzz, pc_xxz, pc_xxzz, pc_xxzzz, pc_xy, pc_xyy, \
                                     pc_xyyy, pc_xyyyy, pc_xyyyz, pc_xyyz, pc_xyyzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xz, \
                                     pc_xzz, pc_xzzz, pc_y, pc_yy, pc_yyy, pc_yyyy, pc_yyyz, pc_yyz, pc_yyzz, pc_yz, pc_yzz, \
                                     pc_yzzz, pc_z, pc_zz, pc_zzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, s_0_0_5, \
                                     s_0_0_6, t_xxy_xxx, t_xxy_xxy, t_xxy_xxz, t_xxy_xyy, t_xxy_xyz, t_xxy_xzz, \
                                     t_xxy_yyy, t_xxy_yyz, t_xxy_yzz, t_xxy_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxy_xxx[j] = fl_s_0_0_0 * (1.5 * pa_xy[j] * fl2_fx + 2.25 * fl2_fx * pa_y[j] * pb_x[j] + 1.5 * pa_xxy[j] * pb_x[j] * fl1_fx + 3.0 * pa_xy[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_y[j] * pb_xxx[j] + pa_xxy[j] * pb_xxx[j]);

                t_xxy_xxx[j] += fl_s_0_0_1 * (-3.0 * pa_xy[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pc_y[j] - 3.75 * pc_x[j] * fl2_fx * pa_y[j] - 2.25 * fl2_fx * pc_y[j] * pb_x[j] - 4.5 * fl2_fx * pa_y[j] * pb_x[j] - 1.5 * pa_xxy[j] * pb_x[j] * fl1_fx - 1.5 * pa_xxy[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx - 9.0 * pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xx[j] - 3.0 * pa_xy[j] * fl1_fx * pb_xx[j] - 4.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_xx[j] - 0.5 * fl1_fx * pc_y[j] * pb_xxx[j] - 0.5 * fl1_fx * pa_y[j] * pb_xxx[j] - 3.0 * pa_xxy[j] * pb_xx[j] * pc_x[j] - pa_xx[j] * pc_y[j] * pb_xxx[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xxx[j]);

                t_xxy_xxx[j] += fl_s_0_0_2 * (3.0 * pa_x[j] * fl2_fx * pc_y[j] + 1.5 * pa_xy[j] * fl2_fx + 7.5 * pc_x[j] * fl2_fx * pa_y[j] + 3.75 * pc_xy[j] * fl2_fx + 4.5 * fl2_fx * pc_y[j] * pb_x[j] + 2.25 * fl2_fx * pa_y[j] * pb_x[j] + 1.5 * pa_xxy[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx + 9.0 * pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx + 6.0 * pa_xy[j] * pc_xx[j] * fl1_fx + 9.0 * pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx + 3.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xx[j] + 9.0 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx + 4.5 * pc_xy[j] * fl1_fx * pb_xx[j] + 4.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_xx[j] + 0.5 * fl1_fx * pc_y[j] * pb_xxx[j] + 3.0 * pa_xxy[j] * pb_x[j] * pc_xx[j] + 3.0 * pa_xx[j] * pc_xy[j] * pb_xx[j] + 6.0 * pa_xy[j] * pc_xx[j] * pb_xx[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xxx[j] + pc_xx[j] * pa_y[j] * pb_xxx[j]);

                t_xxy_xxx[j] += fl_s_0_0_3 * (-1.5 * pa_x[j] * fl2_fx * pc_y[j] - 7.5 * pc_xy[j] * fl2_fx - 3.75 * pc_x[j] * fl2_fx * pa_y[j] - 2.25 * fl2_fx * pc_y[j] * pb_x[j] - 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx - 6.0 * pa_xy[j] * pc_xx[j] * fl1_fx - 9.0 * pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx - 6.0 * pa_x[j] * pc_xxy[j] * fl1_fx - 9.0 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx - 5.0 * pc_xxx[j] * pa_y[j] * fl1_fx - 9.0 * pc_xxy[j] * pb_x[j] * fl1_fx - 4.5 * pc_xy[j] * fl1_fx * pb_xx[j] - pa_xxy[j] * pc_xxx[j] - 3.0 * pa_xx[j] * pc_xxy[j] * pb_x[j] - 6.0 * pa_xy[j] * pc_xxx[j] * pb_x[j] - 6.0 * pa_x[j] * pc_xxy[j] * pb_xx[j] - 3.0 * pc_xxx[j] * pa_y[j] * pb_xx[j] - pc_xxy[j] * pb_xxx[j]);

                t_xxy_xxx[j] += fl_s_0_0_4 * (3.75 * pc_xy[j] * fl2_fx + 6.0 * pa_x[j] * pc_xxy[j] * fl1_fx + 5.0 * pc_xxx[j] * pa_y[j] * fl1_fx + 9.0 * pc_xxy[j] * pb_x[j] * fl1_fx + 5.0 * pc_xxxy[j] * fl1_fx + pa_xx[j] * pc_xxxy[j] + 2.0 * pa_xy[j] * pc_xxxx[j] + 6.0 * pa_x[j] * pc_xxxy[j] * pb_x[j] + 3.0 * pc_xxxx[j] * pa_y[j] * pb_x[j] + 3.0 * pc_xxxy[j] * pb_xx[j]);

                t_xxy_xxx[j] += fl_s_0_0_5 * (-5.0 * pc_xxxy[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxxy[j] - pc_xxxxx[j] * pa_y[j] - 3.0 * pc_xxxxy[j] * pb_x[j]);

                t_xxy_xxx[j] += fl_s_0_0_6 * pc_xxxxxy[j];

                t_xxy_xxy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xxy[j] * fl1_fx * pb_y[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] + 2.0 * pa_xy[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_y[j] * pb_xxy[j] + pa_xxy[j] * pb_xxy[j]);

                t_xxy_xxy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.5 * pa_xx[j] * fl2_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 2.0 * pa_x[j] * fl2_fx * pb_x[j] - 1.5 * pc_x[j] * fl2_fx * pb_x[j] - 0.75 * fl2_fx * pa_y[j] * pc_y[j] - 0.75 * fl2_fx * pc_y[j] * pb_y[j] - 1.5 * fl2_fx * pa_y[j] * pb_y[j] - 0.5 * fl2_fx * pb_xx[j] - 0.5 * pa_xxy[j] * fl1_fx * pc_y[j] - 0.5 * pa_xxy[j] * fl1_fx * pb_y[j] - 0.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_y[j] - pa_xx[j] * fl1_fx * pb_x[j] * pc_x[j] - 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] - 3.0 * pa_xy[j] * pc_x[j] * fl1_fx * pb_y[j] - pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] - 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_y[j] - 2.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xy[j] - 2.0 * pa_xy[j] * fl1_fx * pb_xy[j] - 3.0 * pc_x[j] * fl1_fx * pa_y[j] * pb_xy[j] - 0.5 * fl1_fx * pa_y[j] * pb_xx[j] * pc_y[j] - 0.5 * fl1_fx * pc_y[j] * pb_xxy[j] - 0.5 * fl1_fx * pa_y[j] * pb_xxy[j] - pa_xxy[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xxy[j] * pb_xy[j] * pc_x[j] - pa_xx[j] * pc_y[j] * pb_xxy[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xxy[j]);

                t_xxy_xxy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 3.0 * pa_x[j] * pc_x[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_xx[j] * fl2_fx + 3.0 * pc_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pc_yy[j] + 1.5 * fl2_fx * pa_y[j] * pc_y[j] + 1.5 * fl2_fx * pc_y[j] * pb_y[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xxy[j] * fl1_fx * pc_y[j] + 0.5 * pa_xx[j] * pc_yy[j] * fl1_fx + 0.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_y[j] + 0.5 * pa_xx[j] * fl1_fx * pc_xx[j] + pa_xx[j] * fl1_fx * pb_x[j] * pc_x[j] + 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx + 3.0 * pa_xy[j] * pc_x[j] * fl1_fx * pb_y[j] + 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_x[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] + 2.0 * pa_x[j] * fl1_fx * pc_yy[j] * pb_x[j] + 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_y[j] + 2.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xy[j] + 3.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] + 0.5 * pc_xx[j] * fl1_fx * pb_xx[j] + 3.0 * pc_xy[j] * fl1_fx * pa_y[j] * pb_x[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] + 3.0 * pc_x[j] * fl1_fx * pa_y[j] * pb_xy[j] + 0.5 * fl1_fx * pc_yy[j] * pb_xx[j] + 0.5 * fl1_fx * pa_y[j] * pb_xx[j] * pc_y[j] + 0.5 * fl1_fx * pc_y[j] * pb_xxy[j] + 2.0 * pa_xxy[j] * pb_x[j] * pc_xy[j] + pa_xxy[j] * pc_xx[j] * pb_y[j] + pa_xx[j] * pc_yy[j] * pb_xx[j] + 2.0 * pa_xx[j] * pc_xy[j] * pb_xy[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_xx[j] + 4.0 * pa_xy[j] * pc_xx[j] * pb_xy[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xxy[j] + pc_xx[j] * pa_y[j] * pb_xxy[j]);

                t_xxy_xxy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 3.0 * pc_xx[j] * fl2_fx - 1.5 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_yy[j] - 0.75 * fl2_fx * pa_y[j] * pc_y[j] - 0.75 * fl2_fx * pc_y[j] * pb_y[j] - 0.5 * pa_xx[j] * pc_yy[j] * fl1_fx - 0.5 * pa_xx[j] * fl1_fx * pc_xx[j] - 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] - pa_x[j] * pc_xxx[j] * fl1_fx - 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_x[j] - 2.0 * pa_x[j] * fl1_fx * pc_yy[j] * pb_x[j] - 3.0 * pc_xxy[j] * pa_y[j] * fl1_fx - 3.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] - 3.0 * pc_xxy[j] * fl1_fx * pb_y[j] - pc_xxx[j] * fl1_fx * pb_x[j] - 0.5 * pc_xx[j] * fl1_fx * pb_xx[j] - 3.0 * pc_xyy[j] * fl1_fx * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pa_y[j] * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pc_yy[j] * pb_xx[j] - pa_xxy[j] * pc_xxy[j] - 2.0 * pa_xx[j] * pc_xyy[j] * pb_x[j] - pa_xx[j] * pc_xxy[j] * pb_y[j] - 4.0 * pa_xy[j] * pc_xxy[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xxx[j] * pb_y[j] - 2.0 * pa_x[j] * pc_xyy[j] * pb_xx[j] - 4.0 * pa_x[j] * pc_xxy[j] * pb_xy[j] - pc_xxy[j] * pa_y[j] * pb_xx[j] - 2.0 * pc_xxx[j] * pa_y[j] * pb_xy[j] - pc_xxy[j] * pb_xxy[j]);

                t_xxy_xxy[j] += fl_s_0_0_4 * (1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pc_yy[j] + 3.0 * pa_x[j] * pc_xyy[j] * fl1_fx + pa_x[j] * pc_xxx[j] * fl1_fx + 3.0 * pc_xxy[j] * pa_y[j] * fl1_fx + 3.0 * pc_xxyy[j] * fl1_fx + 3.0 * pc_xxy[j] * fl1_fx * pb_y[j] + 0.5 * pc_xxxx[j] * fl1_fx + pc_xxx[j] * fl1_fx * pb_x[j] + 3.0 * pc_xyy[j] * fl1_fx * pb_x[j] + pa_xx[j] * pc_xxyy[j] + 2.0 * pa_xy[j] * pc_xxxy[j] + 4.0 * pa_x[j] * pc_xxyy[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxxy[j] * pb_y[j] + 2.0 * pc_xxxy[j] * pa_y[j] * pb_x[j] + pc_xxxx[j] * pa_y[j] * pb_y[j] + pc_xxyy[j] * pb_xx[j] + 2.0 * pc_xxxy[j] * pb_xy[j]);

                t_xxy_xxy[j] += fl_s_0_0_5 * (-3.0 * pc_xxyy[j] * fl1_fx - 0.5 * pc_xxxx[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxyy[j] - pc_xxxxy[j] * pa_y[j] - 2.0 * pc_xxxyy[j] * pb_x[j] - pc_xxxxy[j] * pb_y[j]);

                t_xxy_xxy[j] += fl_s_0_0_6 * pc_xxxxyy[j];

                t_xxy_xxz[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * pa_xxy[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_y[j] * pb_xxz[j] + pa_xxy[j] * pb_xxz[j]);

                t_xxy_xxz[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * fl2_fx * pa_y[j] * pb_z[j] - 0.5 * pa_xxy[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxy[j] * fl1_fx * pb_z[j] - 0.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_z[j] - 3.0 * pa_xy[j] * pc_x[j] * fl1_fx * pb_z[j] - 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_z[j] - 2.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xz[j] - 2.0 * pa_xy[j] * fl1_fx * pb_xz[j] - 3.0 * pc_x[j] * fl1_fx * pa_y[j] * pb_xz[j] - 0.5 * fl1_fx * pa_y[j] * pb_xx[j] * pc_z[j] - 0.5 * fl1_fx * pc_y[j] * pb_xxz[j] - 0.5 * fl1_fx * pa_y[j] * pb_xxz[j] - pa_xxy[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xxy[j] * pb_xz[j] * pc_x[j] - pa_xx[j] * pc_y[j] * pb_xxz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xxz[j]);

                t_xxy_xxz[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pa_y[j] * pc_z[j] + 1.5 * fl2_fx * pc_y[j] * pb_z[j] + 0.75 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * pa_xxy[j] * fl1_fx * pc_z[j] + 0.5 * pa_xx[j] * pc_yz[j] * fl1_fx + 0.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_z[j] + 3.0 * pa_xy[j] * pc_xz[j] * fl1_fx + 3.0 * pa_xy[j] * pc_x[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_x[j] + 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_z[j] + 2.0 * pa_x[j] * fl1_fx * pc_y[j] * pb_xz[j] + 3.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] + 3.0 * pc_xz[j] * fl1_fx * pa_y[j] * pb_x[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xz[j] + 3.0 * pc_x[j] * fl1_fx * pa_y[j] * pb_xz[j] + 0.5 * fl1_fx * pc_yz[j] * pb_xx[j] + 0.5 * fl1_fx * pa_y[j] * pb_xx[j] * pc_z[j] + 0.5 * fl1_fx * pc_y[j] * pb_xxz[j] + 2.0 * pa_xxy[j] * pb_x[j] * pc_xz[j] + pa_xxy[j] * pc_xx[j] * pb_z[j] + pa_xx[j] * pc_yz[j] * pb_xx[j] + 2.0 * pa_xx[j] * pc_xy[j] * pb_xz[j] + 2.0 * pa_xy[j] * pc_xz[j] * pb_xx[j] + 4.0 * pa_xy[j] * pc_xx[j] * pb_xz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xxz[j] + pc_xx[j] * pa_y[j] * pb_xxz[j]);

                t_xxy_xxz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 0.5 * pa_xx[j] * pc_yz[j] * fl1_fx - 3.0 * pa_xy[j] * pc_xz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_x[j] - 3.0 * pc_xxz[j] * pa_y[j] * fl1_fx - 3.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] - 3.0 * pc_xxy[j] * fl1_fx * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xz[j] * fl1_fx * pa_y[j] * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pc_yz[j] * pb_xx[j] - pa_xxy[j] * pc_xxz[j] - 2.0 * pa_xx[j] * pc_xyz[j] * pb_x[j] - pa_xx[j] * pc_xxy[j] * pb_z[j] - 4.0 * pa_xy[j] * pc_xxz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xxx[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xx[j] - 4.0 * pa_x[j] * pc_xxy[j] * pb_xz[j] - pc_xxz[j] * pa_y[j] * pb_xx[j] - 2.0 * pc_xxx[j] * pa_y[j] * pb_xz[j] - pc_xxy[j] * pb_xxz[j]);

                t_xxy_xxz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xxz[j] * pa_y[j] * fl1_fx + 3.0 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xxy[j] * fl1_fx * pb_z[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + pa_xx[j] * pc_xxyz[j] + 2.0 * pa_xy[j] * pc_xxxz[j] + 4.0 * pa_x[j] * pc_xxyz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxxy[j] * pb_z[j] + 2.0 * pc_xxxz[j] * pa_y[j] * pb_x[j] + pc_xxxx[j] * pa_y[j] * pb_z[j] + pc_xxyz[j] * pb_xx[j] + 2.0 * pc_xxxy[j] * pb_xz[j]);

                t_xxy_xxz[j] += fl_s_0_0_5 * (-3.0 * pc_xxyz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxyz[j] - pc_xxxxz[j] * pa_y[j] - 2.0 * pc_xxxyz[j] * pb_x[j] - pc_xxxxy[j] * pb_z[j]);

                t_xxy_xxz[j] += fl_s_0_0_6 * pc_xxxxyz[j];

                t_xxy_xyy[j] = fl_s_0_0_0 * (0.5 * pa_xy[j] * fl2_fx + pa_x[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xxy[j] * pb_x[j] * fl1_fx + pa_xx[j] * fl1_fx * pb_xy[j] + pa_xy[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_y[j] * pb_xyy[j] + pa_xxy[j] * pb_xyy[j]);

                t_xxy_xyy[j] += fl_s_0_0_1 * (-pa_xy[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pc_y[j] - 2.0 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pc_x[j] * fl2_fx * pa_y[j] - 1.5 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pa_y[j] * pb_x[j] - 0.75 * fl2_fx * pc_y[j] * pb_x[j] - fl2_fx * pb_xy[j] - 0.5 * pa_xxy[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxy[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx - pa_xx[j] * fl1_fx * pc_x[j] * pb_y[j] - pa_xx[j] * fl1_fx * pb_xy[j] - pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx - 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] - 2.0 * pa_xy[j] * fl1_fx * pb_y[j] * pc_y[j] - pa_x[j] * fl1_fx * pc_y[j] * pb_yy[j] - pa_xy[j] * fl1_fx * pb_yy[j] - 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_yy[j] - fl1_fx * pa_y[j] * pb_xy[j] * pc_y[j] - 0.5 * fl1_fx * pc_y[j] * pb_xyy[j] - 0.5 * fl1_fx * pa_y[j] * pb_xyy[j] - 2.0 * pa_xxy[j] * pb_xy[j] * pc_y[j] - pa_xxy[j] * pc_x[j] * pb_yy[j] - pa_xx[j] * pc_y[j] * pb_xyy[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xyy[j]);

                t_xxy_xyy[j] += fl_s_0_0_2 * (3.0 * pa_x[j] * fl2_fx * pc_y[j] + 0.5 * pa_xy[j] * fl2_fx + pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pc_x[j] * fl2_fx * pa_y[j] + 2.25 * pc_xy[j] * fl2_fx + 3.0 * pc_x[j] * fl2_fx * pb_y[j] + 1.5 * fl2_fx * pc_y[j] * pb_x[j] + 0.25 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xxy[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx + pa_xx[j] * fl1_fx * pc_x[j] * pb_y[j] + pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx + pa_xy[j] * pc_xx[j] * fl1_fx + 3.0 * pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx + 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] + pa_xy[j] * fl1_fx * pc_yy[j] + 2.0 * pa_x[j] * fl1_fx * pc_yy[j] * pb_y[j] + 2.0 * pa_xy[j] * fl1_fx * pb_y[j] * pc_y[j] + pa_x[j] * fl1_fx * pc_y[j] * pb_yy[j] + 0.5 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx + pc_xx[j] * fl1_fx * pb_xy[j] + 3.0 * pc_xy[j] * fl1_fx * pa_y[j] * pb_y[j] + 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_yy[j] + 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_yy[j] + fl1_fx * pc_yy[j] * pb_xy[j] + fl1_fx * pa_y[j] * pb_xy[j] * pc_y[j] + 0.5 * fl1_fx * pc_y[j] * pb_xyy[j] + pa_xxy[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xxy[j] * pc_xy[j] * pb_y[j] + 2.0 * pa_xx[j] * pc_yy[j] * pb_xy[j] + pa_xx[j] * pc_xy[j] * pb_yy[j] + 4.0 * pa_xy[j] * pc_xy[j] * pb_xy[j] + 2.0 * pa_xy[j] * pc_xx[j] * pb_yy[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xyy[j] + pc_xx[j] * pa_y[j] * pb_xyy[j]);

                t_xxy_xyy[j] += fl_s_0_0_3 * (-1.5 * pa_x[j] * fl2_fx * pc_y[j] - 4.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_y[j] - 1.5 * pc_x[j] * fl2_fx * pb_y[j] - 0.75 * fl2_fx * pc_y[j] * pb_x[j] - 1.5 * pa_xx[j] * pc_xy[j] * fl1_fx - pa_xy[j] * pc_xx[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxy[j] * fl1_fx - 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] - pa_x[j] * fl1_fx * pc_yyy[j] - pa_xy[j] * fl1_fx * pc_yy[j] - 2.0 * pa_x[j] * fl1_fx * pc_yy[j] * pb_y[j] - 0.5 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx - 1.5 * pc_xxy[j] * pb_x[j] * fl1_fx - pc_xxx[j] * fl1_fx * pb_y[j] - pc_xx[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xyy[j] * fl1_fx * pa_y[j] - 3.0 * pc_xyy[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pa_y[j] * pb_y[j] - 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] - 0.5 * fl1_fx * pc_yyy[j] * pb_x[j] - 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_yy[j] - fl1_fx * pc_yy[j] * pb_xy[j] - pa_xxy[j] * pc_xyy[j] - pa_xx[j] * pc_yyy[j] * pb_x[j] - 2.0 * pa_xx[j] * pc_xyy[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_xyy[j] * pb_x[j] - 4.0 * pa_xy[j] * pc_xxy[j] * pb_y[j] - 4.0 * pa_x[j] * pc_xyy[j] * pb_xy[j] - 2.0 * pa_x[j] * pc_xxy[j] * pb_yy[j] - 2.0 * pc_xxy[j] * pa_y[j] * pb_xy[j] - pc_xxx[j] * pa_y[j] * pb_yy[j] - pc_xxy[j] * pb_xyy[j]);

                t_xxy_xyy[j] += fl_s_0_0_4 * (2.25 * pc_xy[j] * fl2_fx + 3.0 * pa_x[j] * pc_xxy[j] * fl1_fx + pa_x[j] * fl1_fx * pc_yyy[j] + 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx + 1.5 * pc_xxy[j] * pb_x[j] * fl1_fx + 1.5 * pc_xxxy[j] * fl1_fx + pc_xxx[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyyy[j] * fl1_fx + 1.5 * pc_xyy[j] * fl1_fx * pa_y[j] + 3.0 * pc_xyy[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyy[j] * pb_x[j] + pa_xx[j] * pc_xyyy[j] + 2.0 * pa_xy[j] * pc_xxyy[j] + 2.0 * pa_x[j] * pc_xyyy[j] * pb_x[j] + 4.0 * pa_x[j] * pc_xxyy[j] * pb_y[j] + pc_xxyy[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxxy[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xxyy[j] * pb_xy[j] + pc_xxxy[j] * pb_yy[j]);

                t_xxy_xyy[j] += fl_s_0_0_5 * (-1.5 * pc_xxxy[j] * fl1_fx - 1.5 * pc_xyyy[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxyyy[j] - pc_xxxyy[j] * pa_y[j] - pc_xxyyy[j] * pb_x[j] - 2.0 * pc_xxxyy[j] * pb_y[j]);

                t_xxy_xyy[j] += fl_s_0_0_6 * pc_xxxyyy[j];

                t_xxy_xyz[j] = fl_s_0_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xz[j] + pa_xy[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_y[j] * pb_xyz[j] + pa_xxy[j] * pb_xyz[j]);

                t_xxy_xyz[j] += fl_s_0_0_1 * (-0.5 * pa_x[j] * fl2_fx * pc_z[j] - pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.25 * fl2_fx * pb_x[j] * pc_z[j] - 0.5 * fl2_fx * pb_xz[j] - 0.5 * pa_xx[j] * fl1_fx * pb_x[j] * pc_z[j] - 0.5 * pa_xx[j] * fl1_fx * pc_x[j] * pb_z[j] - 0.5 * pa_xx[j] * fl1_fx * pb_xz[j] - pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] - pa_xy[j] * fl1_fx * pb_y[j] * pc_z[j] - pa_xy[j] * fl1_fx * pc_y[j] * pb_z[j] - pa_x[j] * fl1_fx * pc_y[j] * pb_yz[j] - pa_xy[j] * fl1_fx * pb_yz[j] - 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_yz[j] - 0.5 * fl1_fx * pa_y[j] * pb_xy[j] * pc_z[j] - 0.5 * fl1_fx * pa_y[j] * pb_xz[j] * pc_y[j] - 0.5 * fl1_fx * pc_y[j] * pb_xyz[j] - 0.5 * fl1_fx * pa_y[j] * pb_xyz[j] - pa_xxy[j] * pb_xy[j] * pc_z[j] - pa_xxy[j] * pb_xz[j] * pc_y[j] - pa_xxy[j] * pc_x[j] * pb_yz[j] - pa_xx[j] * pc_y[j] * pb_xyz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xyz[j]);

                t_xxy_xyz[j] += fl_s_0_0_2 * (pa_x[j] * fl2_fx * pc_z[j] + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_x[j] * pc_z[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_xx[j] * fl1_fx * pc_xz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_x[j] * pc_z[j] + 0.5 * pa_xx[j] * fl1_fx * pc_x[j] * pb_z[j] + pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] + pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] + pa_xy[j] * fl1_fx * pc_yz[j] + pa_x[j] * fl1_fx * pc_yz[j] * pb_y[j] + pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] + pa_xy[j] * fl1_fx * pb_y[j] * pc_z[j] + pa_xy[j] * fl1_fx * pc_y[j] * pb_z[j] + pa_x[j] * fl1_fx * pc_y[j] * pb_yz[j] + 0.5 * pc_xx[j] * fl1_fx * pb_xz[j] + 1.5 * pc_xz[j] * fl1_fx * pa_y[j] * pb_y[j] + 1.5 * pc_xy[j] * fl1_fx * pa_y[j] * pb_z[j] + 1.5 * pc_xy[j] * fl1_fx * pb_yz[j] + 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_yz[j] + 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_yz[j] + 0.5 * fl1_fx * pc_yz[j] * pb_xy[j] + 0.5 * fl1_fx * pc_yy[j] * pb_xz[j] + 0.5 * fl1_fx * pa_y[j] * pb_xy[j] * pc_z[j] + 0.5 * fl1_fx * pa_y[j] * pb_xz[j] * pc_y[j] + 0.5 * fl1_fx * pc_y[j] * pb_xyz[j] + pa_xxy[j] * pb_x[j] * pc_yz[j] + pa_xxy[j] * pc_xz[j] * pb_y[j] + pa_xxy[j] * pc_xy[j] * pb_z[j] + pa_xx[j] * pc_yz[j] * pb_xy[j] + pa_xx[j] * pc_yy[j] * pb_xz[j] + pa_xx[j] * pc_xy[j] * pb_yz[j] + 2.0 * pa_xy[j] * pc_xz[j] * pb_xy[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_xz[j] + 2.0 * pa_xy[j] * pc_xx[j] * pb_yz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xyz[j] + pc_xx[j] * pa_y[j] * pb_xyz[j]);

                t_xxy_xyz[j] += fl_s_0_0_3 * (-0.5 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.25 * fl2_fx * pb_x[j] * pc_z[j] - 0.5 * pa_xx[j] * fl1_fx * pc_xz[j] - pa_x[j] * pc_xxz[j] * fl1_fx - pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] - pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] - pa_x[j] * fl1_fx * pc_yyz[j] - pa_xy[j] * fl1_fx * pc_yz[j] - pa_x[j] * fl1_fx * pc_yz[j] * pb_y[j] - pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] - 0.5 * pc_xxz[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xyz[j] * fl1_fx * pa_y[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pa_y[j] * pb_y[j] - 1.5 * pc_xy[j] * fl1_fx * pa_y[j] * pb_z[j] - 1.5 * pc_xy[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pc_yyz[j] * pb_x[j] - 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_yz[j] - 0.5 * fl1_fx * pc_yz[j] * pb_xy[j] - 0.5 * fl1_fx * pc_yy[j] * pb_xz[j] - pa_xxy[j] * pc_xyz[j] - pa_xx[j] * pc_yyz[j] * pb_x[j] - pa_xx[j] * pc_xyz[j] * pb_y[j] - pa_xx[j] * pc_xyy[j] * pb_z[j] - 2.0 * pa_xy[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xxz[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_xxy[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xy[j] - 2.0 * pa_x[j] * pc_xyy[j] * pb_xz[j] - 2.0 * pa_x[j] * pc_xxy[j] * pb_yz[j] - pc_xxz[j] * pa_y[j] * pb_xy[j] - pc_xxy[j] * pa_y[j] * pb_xz[j] - pc_xxx[j] * pa_y[j] * pb_yz[j] - pc_xxy[j] * pb_xyz[j]);

                t_xxy_xyz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + pa_x[j] * pc_xxz[j] * fl1_fx + pa_x[j] * fl1_fx * pc_yyz[j] + 0.5 * pc_xxxz[j] * fl1_fx + 0.5 * pc_xxz[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pa_y[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yyz[j] * pb_x[j] + pa_xx[j] * pc_xyyz[j] + 2.0 * pa_xy[j] * pc_xxyz[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxyz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_xxyy[j] * pb_z[j] + pc_xxyz[j] * pa_y[j] * pb_x[j] + pc_xxxz[j] * pa_y[j] * pb_y[j] + pc_xxxy[j] * pa_y[j] * pb_z[j] + pc_xxyz[j] * pb_xy[j] + pc_xxyy[j] * pb_xz[j] + pc_xxxy[j] * pb_yz[j]);

                t_xxy_xyz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxz[j] * fl1_fx - 1.5 * pc_xyyz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxyyz[j] - pc_xxxyz[j] * pa_y[j] - pc_xxyyz[j] * pb_x[j] - pc_xxxyz[j] * pb_y[j] - pc_xxxyy[j] * pb_z[j]);

                t_xxy_xyz[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_xxy_xzz[j] = fl_s_0_0_0 * (0.5 * pa_xy[j] * fl2_fx + 0.25 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xxy[j] * pb_x[j] * fl1_fx + pa_xy[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_y[j] * pb_xzz[j] + pa_xxy[j] * pb_xzz[j]);

                t_xxy_xzz[j] += fl_s_0_0_1 * (-pa_xy[j] * fl2_fx - 0.5 * pa_x[j] * fl2_fx * pc_y[j] - 0.75 * pc_x[j] * fl2_fx * pa_y[j] - 0.5 * fl2_fx * pa_y[j] * pb_x[j] - 0.25 * fl2_fx * pc_y[j] * pb_x[j] - 0.5 * pa_xxy[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxy[j] * pc_x[j] * fl1_fx - 0.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx - pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx - 2.0 * pa_xy[j] * fl1_fx * pb_z[j] * pc_z[j] - pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] - pa_xy[j] * fl1_fx * pb_zz[j] - 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_zz[j] - fl1_fx * pa_y[j] * pb_xz[j] * pc_z[j] - 0.5 * fl1_fx * pc_y[j] * pb_xzz[j] - 0.5 * fl1_fx * pa_y[j] * pb_xzz[j] - 2.0 * pa_xxy[j] * pb_xz[j] * pc_z[j] - pa_xxy[j] * pc_x[j] * pb_zz[j] - pa_xx[j] * pc_y[j] * pb_xzz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_xzz[j]);

                t_xxy_xzz[j] += fl_s_0_0_2 * (pa_x[j] * fl2_fx * pc_y[j] + 0.5 * pa_xy[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pa_y[j] + 0.75 * pc_xy[j] * fl2_fx + 0.5 * fl2_fx * pc_y[j] * pb_x[j] + 0.25 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xxy[j] * pc_x[j] * fl1_fx + 0.5 * pa_xx[j] * pc_y[j] * pb_x[j] * fl1_fx + 0.5 * pa_xx[j] * pc_xy[j] * fl1_fx + pa_xy[j] * pc_x[j] * pb_x[j] * fl1_fx + pa_xy[j] * pc_xx[j] * fl1_fx + pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx + pa_xy[j] * fl1_fx * pc_zz[j] + 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] + 2.0 * pa_xy[j] * fl1_fx * pb_z[j] * pc_z[j] + pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] + 0.5 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx + 3.0 * pc_xz[j] * fl1_fx * pa_y[j] * pb_z[j] + 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * fl1_fx * pa_y[j] * pb_zz[j] + 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_zz[j] + fl1_fx * pc_yz[j] * pb_xz[j] + fl1_fx * pa_y[j] * pb_xz[j] * pc_z[j] + 0.5 * fl1_fx * pc_y[j] * pb_xzz[j] + pa_xxy[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xxy[j] * pc_xz[j] * pb_z[j] + 2.0 * pa_xx[j] * pc_yz[j] * pb_xz[j] + pa_xx[j] * pc_xy[j] * pb_zz[j] + 4.0 * pa_xy[j] * pc_xz[j] * pb_xz[j] + 2.0 * pa_xy[j] * pc_xx[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_xzz[j] + pc_xx[j] * pa_y[j] * pb_xzz[j]);

                t_xxy_xzz[j] += fl_s_0_0_3 * (-0.5 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_x[j] - 0.5 * pa_xx[j] * pc_xy[j] * fl1_fx - pa_xy[j] * pc_xx[j] * fl1_fx - pa_x[j] * pc_xy[j] * pb_x[j] * fl1_fx - pa_x[j] * pc_xxy[j] * fl1_fx - pa_x[j] * fl1_fx * pc_yzz[j] - pa_xy[j] * fl1_fx * pc_zz[j] - 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] - 0.5 * pc_xx[j] * pa_y[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx - 0.5 * pc_xxy[j] * pb_x[j] * fl1_fx - 1.5 * pc_xzz[j] * fl1_fx * pa_y[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pa_y[j] * pb_z[j] - 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pc_yzz[j] * pb_x[j] - 0.5 * fl1_fx * pa_y[j] * pb_x[j] * pc_zz[j] - fl1_fx * pc_yz[j] * pb_xz[j] - pa_xxy[j] * pc_xzz[j] - pa_xx[j] * pc_yzz[j] * pb_x[j] - 2.0 * pa_xx[j] * pc_xyz[j] * pb_z[j] - 2.0 * pa_xy[j] * pc_xzz[j] * pb_x[j] - 4.0 * pa_xy[j] * pc_xxz[j] * pb_z[j] - 4.0 * pa_x[j] * pc_xyz[j] * pb_xz[j] - 2.0 * pa_x[j] * pc_xxy[j] * pb_zz[j] - 2.0 * pc_xxz[j] * pa_y[j] * pb_xz[j] - pc_xxx[j] * pa_y[j] * pb_zz[j] - pc_xxy[j] * pb_xzz[j]);

                t_xxy_xzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + pa_x[j] * pc_xxy[j] * fl1_fx + pa_x[j] * fl1_fx * pc_yzz[j] + 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx + 0.5 * pc_xxy[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxxy[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pa_y[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yzz[j] * pb_x[j] + pa_xx[j] * pc_xyzz[j] + 2.0 * pa_xy[j] * pc_xxzz[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_x[j] + 4.0 * pa_x[j] * pc_xxyz[j] * pb_z[j] + pc_xxzz[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxxz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xxyz[j] * pb_xz[j] + pc_xxxy[j] * pb_zz[j]);

                t_xxy_xzz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxyzz[j] - pc_xxxzz[j] * pa_y[j] - pc_xxyzz[j] * pb_x[j] - 2.0 * pc_xxxyz[j] * pb_z[j]);

                t_xxy_xzz[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_xxy_yyy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_xxy[j] * pb_y[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_y[j] * pb_yyy[j] + pa_xxy[j] * pb_yyy[j]);

                t_xxy_yyy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_xx[j] * fl2_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * fl2_fx * pa_y[j] * pb_y[j] - 0.75 * fl2_fx * pa_y[j] * pc_y[j] - 2.25 * fl2_fx * pc_y[j] * pb_y[j] - 1.5 * fl2_fx * pb_yy[j] - 1.5 * pa_xxy[j] * pb_y[j] * fl1_fx - 1.5 * pa_xxy[j] * pc_y[j] * fl1_fx - 4.5 * pa_xx[j] * pc_y[j] * pb_y[j] * fl1_fx - 1.5 * pa_xx[j] * fl1_fx * pb_yy[j] - 3.0 * pa_xy[j] * pc_x[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] - 1.5 * fl1_fx * pa_y[j] * pb_yy[j] * pc_y[j] - 0.5 * fl1_fx * pc_y[j] * pb_yyy[j] - 0.5 * fl1_fx * pa_y[j] * pb_yyy[j] - 3.0 * pa_xxy[j] * pb_yy[j] * pc_y[j] - pa_xx[j] * pc_y[j] * pb_yyy[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_yyy[j]);

                t_xxy_yyy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 3.0 * pa_x[j] * pc_x[j] * fl2_fx + 0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pa_y[j] * pc_y[j] + 4.5 * fl2_fx * pc_y[j] * pb_y[j] + 1.5 * fl2_fx * pc_yy[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_xxy[j] * pc_y[j] * fl1_fx + 4.5 * pa_xx[j] * pc_y[j] * pb_y[j] * fl1_fx + 3.0 * pa_xx[j] * pc_yy[j] * fl1_fx + 3.0 * pa_xy[j] * pc_x[j] * pb_y[j] * fl1_fx + 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx + 9.0 * pa_x[j] * pc_xy[j] * pb_y[j] * fl1_fx + 3.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] + 1.5 * pc_xx[j] * pa_y[j] * pb_y[j] * fl1_fx + 1.5 * pc_xx[j] * fl1_fx * pb_yy[j] + 1.5 * fl1_fx * pa_y[j] * pb_y[j] * pc_yy[j] + 1.5 * fl1_fx * pc_yy[j] * pb_yy[j] + 1.5 * fl1_fx * pa_y[j] * pb_yy[j] * pc_y[j] + 0.5 * fl1_fx * pc_y[j] * pb_yyy[j] + 3.0 * pa_xxy[j] * pb_y[j] * pc_yy[j] + 3.0 * pa_xx[j] * pc_yy[j] * pb_yy[j] + 6.0 * pa_xy[j] * pc_xy[j] * pb_yy[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_yyy[j] + pc_xx[j] * pa_y[j] * pb_yyy[j]);

                t_xxy_yyy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * pc_xx[j] * fl2_fx - 3.0 * fl2_fx * pc_yy[j] - 0.75 * fl2_fx * pa_y[j] * pc_y[j] - 2.25 * fl2_fx * pc_y[j] * pb_y[j] - 3.0 * pa_xx[j] * pc_yy[j] * fl1_fx - 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx - 9.0 * pa_x[j] * pc_xy[j] * pb_y[j] * fl1_fx - 6.0 * pa_x[j] * pc_xyy[j] * fl1_fx - 1.5 * pc_xx[j] * pa_y[j] * pb_y[j] * fl1_fx - 1.5 * pc_xxy[j] * pa_y[j] * fl1_fx - 4.5 * pc_xxy[j] * pb_y[j] * fl1_fx - 1.5 * pc_xx[j] * fl1_fx * pb_yy[j] - 0.5 * fl1_fx * pa_y[j] * pc_yyy[j] - 1.5 * fl1_fx * pc_yyy[j] * pb_y[j] - 1.5 * fl1_fx * pa_y[j] * pb_y[j] * pc_yy[j] - 1.5 * fl1_fx * pc_yy[j] * pb_yy[j] - pa_xxy[j] * pc_yyy[j] - 3.0 * pa_xx[j] * pc_yyy[j] * pb_y[j] - 6.0 * pa_xy[j] * pc_xyy[j] * pb_y[j] - 6.0 * pa_x[j] * pc_xyy[j] * pb_yy[j] - 3.0 * pc_xxy[j] * pa_y[j] * pb_yy[j] - pc_xxy[j] * pb_yyy[j]);

                t_xxy_yyy[j] += fl_s_0_0_4 * (0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pc_yy[j] + 6.0 * pa_x[j] * pc_xyy[j] * fl1_fx + 1.5 * pc_xxy[j] * pa_y[j] * fl1_fx + 4.5 * pc_xxy[j] * pb_y[j] * fl1_fx + 3.0 * pc_xxyy[j] * fl1_fx + 0.5 * fl1_fx * pc_yyyy[j] + 0.5 * fl1_fx * pa_y[j] * pc_yyy[j] + 1.5 * fl1_fx * pc_yyy[j] * pb_y[j] + pa_xx[j] * pc_yyyy[j] + 2.0 * pa_xy[j] * pc_xyyy[j] + 6.0 * pa_x[j] * pc_xyyy[j] * pb_y[j] + 3.0 * pc_xxyy[j] * pa_y[j] * pb_y[j] + 3.0 * pc_xxyy[j] * pb_yy[j]);

                t_xxy_yyy[j] += fl_s_0_0_5 * (-3.0 * pc_xxyy[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyy[j] - 2.0 * pa_x[j] * pc_xyyyy[j] - pc_xxyyy[j] * pa_y[j] - 3.0 * pc_xxyyy[j] * pb_y[j]);

                t_xxy_yyy[j] += fl_s_0_0_6 * pc_xxyyyy[j];

                t_xxy_yyz[j] = fl_s_0_0_0 * (0.25 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xxy[j] * fl1_fx * pb_z[j] + pa_xx[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yyz[j] + pa_xxy[j] * pb_yyz[j]);

                t_xxy_yyz[j] += fl_s_0_0_1 * (-0.25 * fl2_fx * pa_y[j] * pc_z[j] - 0.5 * fl2_fx * pa_y[j] * pb_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 0.5 * fl2_fx * pb_y[j] * pc_z[j] - fl2_fx * pb_yz[j] - 0.5 * pa_xxy[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxy[j] * fl1_fx * pb_z[j] - 1.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_z[j] - pa_xx[j] * fl1_fx * pb_y[j] * pc_z[j] - pa_xx[j] * fl1_fx * pb_yz[j] - pa_xy[j] * pc_x[j] * fl1_fx * pb_z[j] - 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pa_y[j] * pb_yy[j] * pc_z[j] - fl1_fx * pa_y[j] * pb_yz[j] * pc_y[j] - 0.5 * fl1_fx * pc_y[j] * pb_yyz[j] - 0.5 * fl1_fx * pa_y[j] * pb_yyz[j] - pa_xxy[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xxy[j] * pb_yz[j] * pc_y[j] - pa_xx[j] * pc_y[j] * pb_yyz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_yyz[j]);

                t_xxy_yyz[j] += fl_s_0_0_2 * (0.5 * fl2_fx * pa_y[j] * pc_z[j] + 0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pc_y[j] * pb_z[j] + fl2_fx * pb_y[j] * pc_z[j] + 0.25 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xxy[j] * fl1_fx * pc_z[j] + 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx + 1.5 * pa_xx[j] * pc_y[j] * fl1_fx * pb_z[j] + pa_xx[j] * fl1_fx * pb_y[j] * pc_z[j] + pa_xy[j] * pc_xz[j] * fl1_fx + pa_xy[j] * pc_x[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] + 0.5 * pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_xx[j] * fl1_fx * pb_yz[j] + fl1_fx * pa_y[j] * pb_y[j] * pc_yz[j] + 0.5 * fl1_fx * pa_y[j] * pc_yy[j] * pb_z[j] + 0.5 * fl1_fx * pc_yz[j] * pb_yy[j] + fl1_fx * pc_yy[j] * pb_yz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yy[j] * pc_z[j] + fl1_fx * pa_y[j] * pb_yz[j] * pc_y[j] + 0.5 * fl1_fx * pc_y[j] * pb_yyz[j] + 2.0 * pa_xxy[j] * pb_y[j] * pc_yz[j] + pa_xxy[j] * pc_yy[j] * pb_z[j] + pa_xx[j] * pc_yz[j] * pb_yy[j] + 2.0 * pa_xx[j] * pc_yy[j] * pb_yz[j] + 2.0 * pa_xy[j] * pc_xz[j] * pb_yy[j] + 4.0 * pa_xy[j] * pc_xy[j] * pb_yz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_yyz[j] + pc_xx[j] * pa_y[j] * pb_yyz[j]);

                t_xxy_yyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.25 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 0.5 * fl2_fx * pb_y[j] * pc_z[j] - 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx - pa_xy[j] * pc_xz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - 2.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] - 0.5 * pc_xxz[j] * pa_y[j] * fl1_fx - 0.5 * pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] - 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] - pc_xxz[j] * fl1_fx * pb_y[j] - pc_xx[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pa_y[j] * pc_yyz[j] - fl1_fx * pc_yyz[j] * pb_y[j] - 0.5 * fl1_fx * pc_yyy[j] * pb_z[j] - fl1_fx * pa_y[j] * pb_y[j] * pc_yz[j] - 0.5 * fl1_fx * pa_y[j] * pc_yy[j] * pb_z[j] - 0.5 * fl1_fx * pc_yz[j] * pb_yy[j] - fl1_fx * pc_yy[j] * pb_yz[j] - pa_xxy[j] * pc_yyz[j] - 2.0 * pa_xx[j] * pc_yyz[j] * pb_y[j] - pa_xx[j] * pc_yyy[j] * pb_z[j] - 4.0 * pa_xy[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_xyy[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_yy[j] - 4.0 * pa_x[j] * pc_xyy[j] * pb_yz[j] - pc_xxz[j] * pa_y[j] * pb_yy[j] - 2.0 * pc_xxy[j] * pa_y[j] * pb_yz[j] - pc_xxy[j] * pb_yyz[j]);

                t_xxy_yyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 0.5 * pc_xxz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] + pc_xxz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyyz[j] + 0.5 * fl1_fx * pa_y[j] * pc_yyz[j] + fl1_fx * pc_yyz[j] * pb_y[j] + 0.5 * fl1_fx * pc_yyy[j] * pb_z[j] + pa_xx[j] * pc_yyyz[j] + 2.0 * pa_xy[j] * pc_xyyz[j] + 4.0 * pa_x[j] * pc_xyyz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_xyyy[j] * pb_z[j] + 2.0 * pc_xxyz[j] * pa_y[j] * pb_y[j] + pc_xxyy[j] * pa_y[j] * pb_z[j] + pc_xxyz[j] * pb_yy[j] + 2.0 * pc_xxyy[j] * pb_yz[j]);

                t_xxy_yyz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyz[j] - 2.0 * pa_x[j] * pc_xyyyz[j] - pc_xxyyz[j] * pa_y[j] - 2.0 * pc_xxyyz[j] * pb_y[j] - pc_xxyyy[j] * pb_z[j]);

                t_xxy_yyz[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_xxy_yzz[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xxy[j] * pb_y[j] * fl1_fx + 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yzz[j] + pa_xxy[j] * pb_yzz[j]);

                t_xxy_yzz[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * pa_xx[j] * fl2_fx - 0.5 * pa_x[j] * pc_x[j] * fl2_fx - 0.5 * fl2_fx * pa_y[j] * pb_y[j] - 0.25 * fl2_fx * pa_y[j] * pc_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_y[j] - 0.5 * fl2_fx * pb_z[j] * pc_z[j] - 0.5 * fl2_fx * pb_zz[j] - 0.5 * pa_xxy[j] * pb_y[j] * fl1_fx - 0.5 * pa_xxy[j] * pc_y[j] * fl1_fx - 0.5 * pa_xx[j] * pc_y[j] * pb_y[j] * fl1_fx - pa_xx[j] * fl1_fx * pb_z[j] * pc_z[j] - 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] - pa_xy[j] * pc_x[j] * pb_y[j] * fl1_fx - pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] - fl1_fx * pa_y[j] * pb_yz[j] * pc_z[j] - 0.5 * fl1_fx * pa_y[j] * pc_y[j] * pb_zz[j] - 0.5 * fl1_fx * pc_y[j] * pb_yzz[j] - 0.5 * fl1_fx * pa_y[j] * pb_yzz[j] - 2.0 * pa_xxy[j] * pb_yz[j] * pc_z[j] - pa_xxy[j] * pc_y[j] * pb_zz[j] - pa_xx[j] * pc_y[j] * pb_yzz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_yzz[j]);

                t_xxy_yzz[j] += fl_s_0_0_2 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * pc_x[j] * fl2_fx + 0.25 * pc_xx[j] * fl2_fx + 0.5 * fl2_fx * pa_y[j] * pc_y[j] + 0.5 * fl2_fx * pc_y[j] * pb_y[j] + 0.25 * fl2_fx * pc_yy[j] + 0.25 * fl2_fx * pc_zz[j] + fl2_fx * pb_z[j] * pc_z[j] + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xxy[j] * pc_y[j] * fl1_fx + 0.5 * pa_xx[j] * pc_y[j] * pb_y[j] * fl1_fx + 0.5 * pa_xx[j] * pc_yy[j] * fl1_fx + 0.5 * pa_xx[j] * fl1_fx * pc_zz[j] + pa_xx[j] * fl1_fx * pb_z[j] * pc_z[j] + pa_xy[j] * pc_x[j] * pb_y[j] * fl1_fx + pa_xy[j] * pc_xy[j] * fl1_fx + pa_x[j] * pc_xy[j] * pb_y[j] * fl1_fx + 2.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] + 0.5 * pc_xx[j] * pa_y[j] * pb_y[j] * fl1_fx + 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_y[j] * pb_y[j] * pc_zz[j] + fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] + fl1_fx * pc_yz[j] * pb_yz[j] + 0.5 * fl1_fx * pc_yy[j] * pb_zz[j] + fl1_fx * pa_y[j] * pb_yz[j] * pc_z[j] + 0.5 * fl1_fx * pa_y[j] * pc_y[j] * pb_zz[j] + 0.5 * fl1_fx * pc_y[j] * pb_yzz[j] + pa_xxy[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xxy[j] * pc_yz[j] * pb_z[j] + 2.0 * pa_xx[j] * pc_yz[j] * pb_yz[j] + pa_xx[j] * pc_yy[j] * pb_zz[j] + 4.0 * pa_xy[j] * pc_xz[j] * pb_yz[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_yzz[j] + pc_xx[j] * pa_y[j] * pb_yzz[j]);

                t_xxy_yzz[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * pa_x[j] * pc_x[j] * fl2_fx - 0.5 * pc_xx[j] * fl2_fx - 0.5 * fl2_fx * pc_yy[j] - 0.5 * fl2_fx * pc_zz[j] - 0.25 * fl2_fx * pa_y[j] * pc_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_y[j] - 0.5 * fl2_fx * pb_z[j] * pc_z[j] - 0.5 * pa_xx[j] * pc_yy[j] * fl1_fx - 0.5 * pa_xx[j] * fl1_fx * pc_zz[j] - pa_xy[j] * pc_xy[j] * fl1_fx - pa_x[j] * pc_xy[j] * pb_y[j] * fl1_fx - pa_x[j] * pc_xyy[j] * fl1_fx - pa_x[j] * pc_xzz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * pa_y[j] * pb_y[j] * fl1_fx - 0.5 * pc_xxy[j] * pa_y[j] * fl1_fx - 0.5 * pc_xxy[j] * pb_y[j] * fl1_fx - pc_xxz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pa_y[j] * pc_yzz[j] - 0.5 * fl1_fx * pc_yzz[j] * pb_y[j] - fl1_fx * pc_yyz[j] * pb_z[j] - 0.5 * fl1_fx * pa_y[j] * pb_y[j] * pc_zz[j] - fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] - fl1_fx * pc_yz[j] * pb_yz[j] - 0.5 * fl1_fx * pc_yy[j] * pb_zz[j] - pa_xxy[j] * pc_yzz[j] - pa_xx[j] * pc_yzz[j] * pb_y[j] - 2.0 * pa_xx[j] * pc_yyz[j] * pb_z[j] - 2.0 * pa_xy[j] * pc_xzz[j] * pb_y[j] - 4.0 * pa_xy[j] * pc_xyz[j] * pb_z[j] - 4.0 * pa_x[j] * pc_xyz[j] * pb_yz[j] - 2.0 * pa_x[j] * pc_xyy[j] * pb_zz[j] - 2.0 * pc_xxz[j] * pa_y[j] * pb_yz[j] - pc_xxy[j] * pa_y[j] * pb_zz[j] - pc_xxy[j] * pb_yzz[j]);

                t_xxy_yzz[j] += fl_s_0_0_4 * (0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_yy[j] + 0.25 * fl2_fx * pc_zz[j] + pa_x[j] * pc_xyy[j] * fl1_fx + pa_x[j] * pc_xzz[j] * fl1_fx + 0.5 * pc_xxy[j] * pa_y[j] * fl1_fx + 0.5 * pc_xxy[j] * pb_y[j] * fl1_fx + 0.5 * pc_xxyy[j] * fl1_fx + 0.5 * pc_xxzz[j] * fl1_fx + pc_xxz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yyzz[j] + 0.5 * fl1_fx * pa_y[j] * pc_yzz[j] + 0.5 * fl1_fx * pc_yzz[j] * pb_y[j] + fl1_fx * pc_yyz[j] * pb_z[j] + pa_xx[j] * pc_yyzz[j] + 2.0 * pa_xy[j] * pc_xyzz[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_y[j] + 4.0 * pa_x[j] * pc_xyyz[j] * pb_z[j] + pc_xxzz[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xxyz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xxyz[j] * pb_yz[j] + pc_xxyy[j] * pb_zz[j]);

                t_xxy_yzz[j] += fl_s_0_0_5 * (-0.5 * pc_xxyy[j] * fl1_fx - 0.5 * pc_xxzz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyzz[j] - 2.0 * pa_x[j] * pc_xyyzz[j] - pc_xxyzz[j] * pa_y[j] - pc_xxyzz[j] * pb_y[j] - 2.0 * pc_xxyyz[j] * pb_z[j]);

                t_xxy_yzz[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_xxy_zzz[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 1.5 * pa_xxy[j] * pb_z[j] * fl1_fx + 0.5 * fl1_fx * pa_y[j] * pb_zzz[j] + pa_xxy[j] * pb_zzz[j]);

                t_xxy_zzz[j] += fl_s_0_0_1 * (-1.5 * fl2_fx * pa_y[j] * pb_z[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xxy[j] * pb_z[j] * fl1_fx - 1.5 * pa_xxy[j] * pc_z[j] * fl1_fx - 1.5 * pa_xx[j] * pc_y[j] * pb_z[j] * fl1_fx - 3.0 * pa_xy[j] * pc_x[j] * pb_z[j] * fl1_fx - 1.5 * fl1_fx * pa_y[j] * pb_zz[j] * pc_z[j] - 0.5 * fl1_fx * pc_y[j] * pb_zzz[j] - 0.5 * fl1_fx * pa_y[j] * pb_zzz[j] - 3.0 * pa_xxy[j] * pb_zz[j] * pc_z[j] - pa_xx[j] * pc_y[j] * pb_zzz[j] - 2.0 * pa_xy[j] * pc_x[j] * pb_zzz[j]);

                t_xxy_zzz[j] += fl_s_0_0_2 * (1.5 * fl2_fx * pa_y[j] * pc_z[j] + 1.5 * fl2_fx * pc_y[j] * pb_z[j] + 0.75 * fl2_fx * pc_yz[j] + 0.75 * fl2_fx * pa_y[j] * pb_z[j] + 1.5 * pa_xxy[j] * pc_z[j] * fl1_fx + 1.5 * pa_xx[j] * pc_y[j] * pb_z[j] * fl1_fx + 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx + 3.0 * pa_xy[j] * pc_x[j] * pb_z[j] * fl1_fx + 3.0 * pa_xy[j] * pc_xz[j] * fl1_fx + 3.0 * pa_x[j] * pc_xy[j] * pb_z[j] * fl1_fx + 1.5 * pc_xx[j] * pa_y[j] * pb_z[j] * fl1_fx + 1.5 * fl1_fx * pa_y[j] * pb_z[j] * pc_zz[j] + 1.5 * fl1_fx * pc_yz[j] * pb_zz[j] + 1.5 * fl1_fx * pa_y[j] * pb_zz[j] * pc_z[j] + 0.5 * fl1_fx * pc_y[j] * pb_zzz[j] + 3.0 * pa_xxy[j] * pb_z[j] * pc_zz[j] + 3.0 * pa_xx[j] * pc_yz[j] * pb_zz[j] + 6.0 * pa_xy[j] * pc_xz[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xy[j] * pb_zzz[j] + pc_xx[j] * pa_y[j] * pb_zzz[j]);

                t_xxy_zzz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx - 3.0 * pa_xy[j] * pc_xz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * pb_z[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 1.5 * pc_xx[j] * pa_y[j] * pb_z[j] * fl1_fx - 1.5 * pc_xxz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xxy[j] * pb_z[j] * fl1_fx - 0.5 * fl1_fx * pa_y[j] * pc_zzz[j] - 1.5 * fl1_fx * pc_yzz[j] * pb_z[j] - 1.5 * fl1_fx * pa_y[j] * pb_z[j] * pc_zz[j] - 1.5 * fl1_fx * pc_yz[j] * pb_zz[j] - pa_xxy[j] * pc_zzz[j] - 3.0 * pa_xx[j] * pc_yzz[j] * pb_z[j] - 6.0 * pa_xy[j] * pc_xzz[j] * pb_z[j] - 6.0 * pa_x[j] * pc_xyz[j] * pb_zz[j] - 3.0 * pc_xxz[j] * pa_y[j] * pb_zz[j] - pc_xxy[j] * pb_zzz[j]);

                t_xxy_zzz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 1.5 * pc_xxz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xxy[j] * pb_z[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + 0.5 * fl1_fx * pc_yzzz[j] + 0.5 * fl1_fx * pa_y[j] * pc_zzz[j] + 1.5 * fl1_fx * pc_yzz[j] * pb_z[j] + pa_xx[j] * pc_yzzz[j] + 2.0 * pa_xy[j] * pc_xzzz[j] + 6.0 * pa_x[j] * pc_xyzz[j] * pb_z[j] + 3.0 * pc_xxzz[j] * pa_y[j] * pb_z[j] + 3.0 * pc_xxyz[j] * pb_zz[j]);

                t_xxy_zzz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yzzz[j] - 2.0 * pa_x[j] * pc_xyzzz[j] - pc_xxzzz[j] * pa_y[j] - 3.0 * pc_xxyzz[j] * pb_z[j]);

                t_xxy_zzz[j] += fl_s_0_0_6 * pc_xxyzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_20_30(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (20,30)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(19 * idx + 3);

            auto pa_xz = paDistances.data(19 * idx + 5);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxz = paDistances.data(19 * idx + 11);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxx = pcDistances.data(83 * idx + 34);

            auto pc_xxxxy = pcDistances.data(83 * idx + 35);

            auto pc_xxxxz = pcDistances.data(83 * idx + 36);

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_xzzzz = pcDistances.data(83 * idx + 48);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxxz = pcDistances.data(83 * idx + 57);

            auto pc_xxxxyz = pcDistances.data(83 * idx + 59);

            auto pc_xxxxzz = pcDistances.data(83 * idx + 60);

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxxzzz = pcDistances.data(83 * idx + 64);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            auto pc_xxzzzz = pcDistances.data(83 * idx + 69);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xxz_xxx = primBuffer.data(100 * idx + 20);

            auto t_xxz_xxy = primBuffer.data(100 * idx + 21);

            auto t_xxz_xxz = primBuffer.data(100 * idx + 22);

            auto t_xxz_xyy = primBuffer.data(100 * idx + 23);

            auto t_xxz_xyz = primBuffer.data(100 * idx + 24);

            auto t_xxz_xzz = primBuffer.data(100 * idx + 25);

            auto t_xxz_yyy = primBuffer.data(100 * idx + 26);

            auto t_xxz_yyz = primBuffer.data(100 * idx + 27);

            auto t_xxz_yzz = primBuffer.data(100 * idx + 28);

            auto t_xxz_zzz = primBuffer.data(100 * idx + 29);

            // Batch of Integrals (20,30)

            #pragma omp simd aligned(fx, pa_x, pa_xx, pa_xxz, pa_xz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxx, pc_xxxxxz, pc_xxxxy, pc_xxxxyz, \
                                     pc_xxxxz, pc_xxxxzz, pc_xxxy, pc_xxxyy, pc_xxxyyz, pc_xxxyz, pc_xxxyzz, pc_xxxz, \
                                     pc_xxxzz, pc_xxxzzz, pc_xxy, pc_xxyy, pc_xxyyy, pc_xxyyyz, pc_xxyyz, pc_xxyyzz, \
                                     pc_xxyz, pc_xxyzz, pc_xxyzzz, pc_xxz, pc_xxzz, pc_xxzzz, pc_xxzzzz, pc_xy, pc_xyy, \
                                     pc_xyyy, pc_xyyyz, pc_xyyz, pc_xyyzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xz, pc_xzz, \
                                     pc_xzzz, pc_xzzzz, pc_y, pc_yy, pc_yyy, pc_yyyz, pc_yyz, pc_yyzz, pc_yz, pc_yzz, \
                                     pc_yzzz, pc_z, pc_zz, pc_zzz, pc_zzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, \
                                     s_0_0_5, s_0_0_6, t_xxz_xxx, t_xxz_xxy, t_xxz_xxz, t_xxz_xyy, t_xxz_xyz, \
                                     t_xxz_xzz, t_xxz_yyy, t_xxz_yyz, t_xxz_yzz, t_xxz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxz_xxx[j] = fl_s_0_0_0 * (1.5 * pa_xz[j] * fl2_fx + 2.25 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_xxz[j] * pb_x[j] * fl1_fx + 3.0 * pa_xz[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxx[j] + pa_xxz[j] * pb_xxx[j]);

                t_xxz_xxx[j] += fl_s_0_0_1 * (-3.0 * pa_xz[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pc_z[j] - 3.75 * pc_x[j] * fl2_fx * pa_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_x[j] - 4.5 * fl2_fx * pa_z[j] * pb_x[j] - 1.5 * pa_xxz[j] * pb_x[j] * fl1_fx - 1.5 * pa_xxz[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx - 9.0 * pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xx[j] - 3.0 * pa_xz[j] * fl1_fx * pb_xx[j] - 4.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xx[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxx[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxx[j] - 3.0 * pa_xxz[j] * pb_xx[j] * pc_x[j] - pa_xx[j] * pc_z[j] * pb_xxx[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xxx[j]);

                t_xxz_xxx[j] += fl_s_0_0_2 * (3.0 * pa_x[j] * fl2_fx * pc_z[j] + 1.5 * pa_xz[j] * fl2_fx + 7.5 * pc_x[j] * fl2_fx * pa_z[j] + 3.75 * pc_xz[j] * fl2_fx + 4.5 * fl2_fx * pc_z[j] * pb_x[j] + 2.25 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_xxz[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx + 9.0 * pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx + 6.0 * pa_xz[j] * pc_xx[j] * fl1_fx + 9.0 * pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx + 3.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xx[j] + 9.0 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx + 4.5 * pc_xz[j] * fl1_fx * pb_xx[j] + 4.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xx[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxx[j] + 3.0 * pa_xxz[j] * pb_x[j] * pc_xx[j] + 3.0 * pa_xx[j] * pc_xz[j] * pb_xx[j] + 6.0 * pa_xz[j] * pc_xx[j] * pb_xx[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xxx[j] + pc_xx[j] * pa_z[j] * pb_xxx[j]);

                t_xxz_xxx[j] += fl_s_0_0_3 * (-1.5 * pa_x[j] * fl2_fx * pc_z[j] - 7.5 * pc_xz[j] * fl2_fx - 3.75 * pc_x[j] * fl2_fx * pa_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_x[j] - 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx - 6.0 * pa_xz[j] * pc_xx[j] * fl1_fx - 9.0 * pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx - 6.0 * pa_x[j] * pc_xxz[j] * fl1_fx - 9.0 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx - 5.0 * pc_xxx[j] * pa_z[j] * fl1_fx - 9.0 * pc_xxz[j] * pb_x[j] * fl1_fx - 4.5 * pc_xz[j] * fl1_fx * pb_xx[j] - pa_xxz[j] * pc_xxx[j] - 3.0 * pa_xx[j] * pc_xxz[j] * pb_x[j] - 6.0 * pa_xz[j] * pc_xxx[j] * pb_x[j] - 6.0 * pa_x[j] * pc_xxz[j] * pb_xx[j] - 3.0 * pc_xxx[j] * pa_z[j] * pb_xx[j] - pc_xxz[j] * pb_xxx[j]);

                t_xxz_xxx[j] += fl_s_0_0_4 * (3.75 * pc_xz[j] * fl2_fx + 6.0 * pa_x[j] * pc_xxz[j] * fl1_fx + 5.0 * pc_xxx[j] * pa_z[j] * fl1_fx + 9.0 * pc_xxz[j] * pb_x[j] * fl1_fx + 5.0 * pc_xxxz[j] * fl1_fx + pa_xx[j] * pc_xxxz[j] + 2.0 * pa_xz[j] * pc_xxxx[j] + 6.0 * pa_x[j] * pc_xxxz[j] * pb_x[j] + 3.0 * pc_xxxx[j] * pa_z[j] * pb_x[j] + 3.0 * pc_xxxz[j] * pb_xx[j]);

                t_xxz_xxx[j] += fl_s_0_0_5 * (-5.0 * pc_xxxz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxxz[j] - pc_xxxxx[j] * pa_z[j] - 3.0 * pc_xxxxz[j] * pb_x[j]);

                t_xxz_xxx[j] += fl_s_0_0_6 * pc_xxxxxz[j];

                t_xxz_xxy[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_xxz[j] * fl1_fx * pb_y[j] + 2.0 * pa_xz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxy[j] + pa_xxz[j] * pb_xxy[j]);

                t_xxz_xxy[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 1.5 * fl2_fx * pa_z[j] * pb_y[j] - 0.5 * pa_xxz[j] * fl1_fx * pc_y[j] - 0.5 * pa_xxz[j] * fl1_fx * pb_y[j] - 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_y[j] - 3.0 * pa_xz[j] * pc_x[j] * fl1_fx * pb_y[j] - 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_y[j] - 2.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xy[j] - 2.0 * pa_xz[j] * fl1_fx * pb_xy[j] - 3.0 * pc_x[j] * fl1_fx * pa_z[j] * pb_xy[j] - 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_y[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxy[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxy[j] - pa_xxz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xxz[j] * pb_xy[j] * pc_x[j] - pa_xx[j] * pc_z[j] * pb_xxy[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xxy[j]);

                t_xxz_xxy[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pa_z[j] * pc_y[j] + 1.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_xxz[j] * fl1_fx * pc_y[j] + 0.5 * pa_xx[j] * pc_yz[j] * fl1_fx + 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_y[j] + 3.0 * pa_xz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_xz[j] * pc_x[j] * fl1_fx * pb_y[j] + 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_x[j] + 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_y[j] + 2.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xy[j] + 3.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_y[j] + 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_x[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xy[j] + 3.0 * pc_x[j] * fl1_fx * pa_z[j] * pb_xy[j] + 0.5 * fl1_fx * pc_yz[j] * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_y[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxy[j] + 2.0 * pa_xxz[j] * pb_x[j] * pc_xy[j] + pa_xxz[j] * pc_xx[j] * pb_y[j] + pa_xx[j] * pc_yz[j] * pb_xx[j] + 2.0 * pa_xx[j] * pc_xz[j] * pb_xy[j] + 2.0 * pa_xz[j] * pc_xy[j] * pb_xx[j] + 4.0 * pa_xz[j] * pc_xx[j] * pb_xy[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xxy[j] + pc_xx[j] * pa_z[j] * pb_xxy[j]);

                t_xxz_xxy[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * pa_xx[j] * pc_yz[j] * fl1_fx - 3.0 * pa_xz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] - 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_x[j] - 3.0 * pc_xxy[j] * pa_z[j] * fl1_fx - 3.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_y[j] - 3.0 * pc_xxz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_x[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pc_yz[j] * pb_xx[j] - pa_xxz[j] * pc_xxy[j] - 2.0 * pa_xx[j] * pc_xyz[j] * pb_x[j] - pa_xx[j] * pc_xxz[j] * pb_y[j] - 4.0 * pa_xz[j] * pc_xxy[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xxx[j] * pb_y[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xx[j] - 4.0 * pa_x[j] * pc_xxz[j] * pb_xy[j] - pc_xxy[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xxx[j] * pa_z[j] * pb_xy[j] - pc_xxz[j] * pb_xxy[j]);

                t_xxz_xxy[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xxy[j] * pa_z[j] * fl1_fx + 3.0 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xxz[j] * fl1_fx * pb_y[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + pa_xx[j] * pc_xxyz[j] + 2.0 * pa_xz[j] * pc_xxxy[j] + 4.0 * pa_x[j] * pc_xxyz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxxz[j] * pb_y[j] + 2.0 * pc_xxxy[j] * pa_z[j] * pb_x[j] + pc_xxxx[j] * pa_z[j] * pb_y[j] + pc_xxyz[j] * pb_xx[j] + 2.0 * pc_xxxz[j] * pb_xy[j]);

                t_xxz_xxy[j] += fl_s_0_0_5 * (-3.0 * pc_xxyz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxyz[j] - pc_xxxxy[j] * pa_z[j] - 2.0 * pc_xxxyz[j] * pb_x[j] - pc_xxxxz[j] * pb_y[j]);

                t_xxz_xxy[j] += fl_s_0_0_6 * pc_xxxxyz[j];

                t_xxz_xxz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xxz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] + 2.0 * pa_xz[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxz[j] + pa_xxz[j] * pb_xxz[j]);

                t_xxz_xxz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.5 * pa_xx[j] * fl2_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 2.0 * pa_x[j] * fl2_fx * pb_x[j] - 1.5 * pc_x[j] * fl2_fx * pb_x[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_z[j] - 1.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_xx[j] - 0.5 * pa_xxz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxz[j] * fl1_fx * pb_z[j] - 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_xx[j] * fl1_fx * pb_x[j] * pc_x[j] - 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] - 3.0 * pa_xz[j] * pc_x[j] * fl1_fx * pb_z[j] - pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] - 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_z[j] - 2.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xz[j] - 2.0 * pa_xz[j] * fl1_fx * pb_xz[j] - 3.0 * pc_x[j] * fl1_fx * pa_z[j] * pb_xz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxz[j] - pa_xxz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xxz[j] * pb_xz[j] * pc_x[j] - pa_xx[j] * pc_z[j] * pb_xxz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xxz[j]);

                t_xxz_xxz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 3.0 * pa_x[j] * pc_x[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_xx[j] * fl2_fx + 3.0 * pc_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pc_zz[j] + 1.5 * fl2_fx * pa_z[j] * pc_z[j] + 1.5 * fl2_fx * pc_z[j] * pb_z[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xxz[j] * fl1_fx * pc_z[j] + 0.5 * pa_xx[j] * pc_zz[j] * fl1_fx + 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pc_xx[j] + pa_xx[j] * fl1_fx * pb_x[j] * pc_x[j] + 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx + 3.0 * pa_xz[j] * pc_x[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_x[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_xx[j] + 2.0 * pa_x[j] * fl1_fx * pc_zz[j] * pb_x[j] + 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_z[j] + 2.0 * pa_x[j] * fl1_fx * pc_z[j] * pb_xz[j] + 3.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_xx[j] * fl1_fx * pb_xx[j] + 3.0 * pc_xz[j] * fl1_fx * pa_z[j] * pb_x[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] + 3.0 * pc_x[j] * fl1_fx * pa_z[j] * pb_xz[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxz[j] + 2.0 * pa_xxz[j] * pb_x[j] * pc_xz[j] + pa_xxz[j] * pc_xx[j] * pb_z[j] + pa_xx[j] * pc_zz[j] * pb_xx[j] + 2.0 * pa_xx[j] * pc_xz[j] * pb_xz[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_xx[j] + 4.0 * pa_xz[j] * pc_xx[j] * pb_xz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xxz[j] + pc_xx[j] * pa_z[j] * pb_xxz[j]);

                t_xxz_xxz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 3.0 * pc_xx[j] * fl2_fx - 1.5 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_zz[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * pa_xx[j] * pc_zz[j] * fl1_fx - 0.5 * pa_xx[j] * fl1_fx * pc_xx[j] - 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] - pa_x[j] * pc_xxx[j] * fl1_fx - 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_x[j] - 2.0 * pa_x[j] * fl1_fx * pc_zz[j] * pb_x[j] - 3.0 * pc_xxz[j] * pa_z[j] * fl1_fx - 3.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_xxz[j] * fl1_fx * pb_z[j] - pc_xxx[j] * fl1_fx * pb_x[j] - 0.5 * pc_xx[j] * fl1_fx * pb_xx[j] - 3.0 * pc_xzz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xz[j] * fl1_fx * pa_z[j] * pb_x[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] - pa_xxz[j] * pc_xxz[j] - 2.0 * pa_xx[j] * pc_xzz[j] * pb_x[j] - pa_xx[j] * pc_xxz[j] * pb_z[j] - 4.0 * pa_xz[j] * pc_xxz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xxx[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xzz[j] * pb_xx[j] - 4.0 * pa_x[j] * pc_xxz[j] * pb_xz[j] - pc_xxz[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xxx[j] * pa_z[j] * pb_xz[j] - pc_xxz[j] * pb_xxz[j]);

                t_xxz_xxz[j] += fl_s_0_0_4 * (1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pc_zz[j] + 3.0 * pa_x[j] * pc_xzz[j] * fl1_fx + pa_x[j] * pc_xxx[j] * fl1_fx + 3.0 * pc_xxz[j] * pa_z[j] * fl1_fx + 3.0 * pc_xxzz[j] * fl1_fx + 3.0 * pc_xxz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xxxx[j] * fl1_fx + pc_xxx[j] * fl1_fx * pb_x[j] + 3.0 * pc_xzz[j] * fl1_fx * pb_x[j] + pa_xx[j] * pc_xxzz[j] + 2.0 * pa_xz[j] * pc_xxxz[j] + 4.0 * pa_x[j] * pc_xxzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxxz[j] * pb_z[j] + 2.0 * pc_xxxz[j] * pa_z[j] * pb_x[j] + pc_xxxx[j] * pa_z[j] * pb_z[j] + pc_xxzz[j] * pb_xx[j] + 2.0 * pc_xxxz[j] * pb_xz[j]);

                t_xxz_xxz[j] += fl_s_0_0_5 * (-3.0 * pc_xxzz[j] * fl1_fx - 0.5 * pc_xxxx[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxxzz[j] - pc_xxxxz[j] * pa_z[j] - 2.0 * pc_xxxzz[j] * pb_x[j] - pc_xxxxz[j] * pb_z[j]);

                t_xxz_xxz[j] += fl_s_0_0_6 * pc_xxxxzz[j];

                t_xxz_xyy[j] = fl_s_0_0_0 * (0.5 * pa_xz[j] * fl2_fx + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xxz[j] * pb_x[j] * fl1_fx + pa_xz[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pb_xyy[j] + pa_xxz[j] * pb_xyy[j]);

                t_xxz_xyy[j] += fl_s_0_0_1 * (-pa_xz[j] * fl2_fx - 0.5 * pa_x[j] * fl2_fx * pc_z[j] - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_x[j] - 0.25 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * pa_xxz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxz[j] * pc_x[j] * fl1_fx - 0.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx - pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx - 2.0 * pa_xz[j] * fl1_fx * pb_y[j] * pc_y[j] - pa_x[j] * fl1_fx * pc_z[j] * pb_yy[j] - pa_xz[j] * fl1_fx * pb_yy[j] - 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yy[j] - fl1_fx * pa_z[j] * pb_xy[j] * pc_y[j] - 0.5 * fl1_fx * pc_z[j] * pb_xyy[j] - 0.5 * fl1_fx * pa_z[j] * pb_xyy[j] - 2.0 * pa_xxz[j] * pb_xy[j] * pc_y[j] - pa_xxz[j] * pc_x[j] * pb_yy[j] - pa_xx[j] * pc_z[j] * pb_xyy[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xyy[j]);

                t_xxz_xyy[j] += fl_s_0_0_2 * (pa_x[j] * fl2_fx * pc_z[j] + 0.5 * pa_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pa_z[j] + 0.75 * pc_xz[j] * fl2_fx + 0.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xxz[j] * pc_x[j] * fl1_fx + 0.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx + 0.5 * pa_xx[j] * pc_xz[j] * fl1_fx + pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx + pa_xz[j] * pc_xx[j] * fl1_fx + pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx + pa_xz[j] * fl1_fx * pc_yy[j] + 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_y[j] + 2.0 * pa_xz[j] * fl1_fx * pb_y[j] * pc_y[j] + pa_x[j] * fl1_fx * pc_z[j] * pb_yy[j] + 0.5 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx + 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_y[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_yy[j] + fl1_fx * pc_yz[j] * pb_xy[j] + fl1_fx * pa_z[j] * pb_xy[j] * pc_y[j] + 0.5 * fl1_fx * pc_z[j] * pb_xyy[j] + pa_xxz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xxz[j] * pc_xy[j] * pb_y[j] + 2.0 * pa_xx[j] * pc_yz[j] * pb_xy[j] + pa_xx[j] * pc_xz[j] * pb_yy[j] + 4.0 * pa_xz[j] * pc_xy[j] * pb_xy[j] + 2.0 * pa_xz[j] * pc_xx[j] * pb_yy[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xyy[j] + pc_xx[j] * pa_z[j] * pb_xyy[j]);

                t_xxz_xyy[j] += fl_s_0_0_3 * (-0.5 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * pa_xx[j] * pc_xz[j] * fl1_fx - pa_xz[j] * pc_xx[j] * fl1_fx - pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx - pa_x[j] * pc_xxz[j] * fl1_fx - pa_x[j] * fl1_fx * pc_yyz[j] - pa_xz[j] * fl1_fx * pc_yy[j] - 2.0 * pa_x[j] * fl1_fx * pc_yz[j] * pb_y[j] - 0.5 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxx[j] * pa_z[j] * fl1_fx - 0.5 * pc_xxz[j] * pb_x[j] * fl1_fx - 1.5 * pc_xyy[j] * fl1_fx * pa_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_y[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] - 0.5 * fl1_fx * pc_yyz[j] * pb_x[j] - 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_yy[j] - fl1_fx * pc_yz[j] * pb_xy[j] - pa_xxz[j] * pc_xyy[j] - pa_xx[j] * pc_yyz[j] * pb_x[j] - 2.0 * pa_xx[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_xyy[j] * pb_x[j] - 4.0 * pa_xz[j] * pc_xxy[j] * pb_y[j] - 4.0 * pa_x[j] * pc_xyz[j] * pb_xy[j] - 2.0 * pa_x[j] * pc_xxz[j] * pb_yy[j] - 2.0 * pc_xxy[j] * pa_z[j] * pb_xy[j] - pc_xxx[j] * pa_z[j] * pb_yy[j] - pc_xxz[j] * pb_xyy[j]);

                t_xxz_xyy[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + pa_x[j] * pc_xxz[j] * fl1_fx + pa_x[j] * fl1_fx * pc_yyz[j] + 0.5 * pc_xxx[j] * pa_z[j] * fl1_fx + 0.5 * pc_xxz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxxz[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_xyy[j] * fl1_fx * pa_z[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyz[j] * pb_x[j] + pa_xx[j] * pc_xyyz[j] + 2.0 * pa_xz[j] * pc_xxyy[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_x[j] + 4.0 * pa_x[j] * pc_xxyz[j] * pb_y[j] + pc_xxyy[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxxy[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xxyz[j] * pb_xy[j] + pc_xxxz[j] * pb_yy[j]);

                t_xxz_xyy[j] += fl_s_0_0_5 * (-0.5 * pc_xxxz[j] * fl1_fx - 1.5 * pc_xyyz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxyyz[j] - pc_xxxyy[j] * pa_z[j] - pc_xxyyz[j] * pb_x[j] - 2.0 * pc_xxxyz[j] * pb_y[j]);

                t_xxz_xyy[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_xxz_xyz[j] = fl_s_0_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xy[j] + pa_xz[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xyz[j] + pa_xxz[j] * pb_xyz[j]);

                t_xxz_xyz[j] += fl_s_0_0_1 * (-0.5 * pa_x[j] * fl2_fx * pc_y[j] - pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.25 * fl2_fx * pb_x[j] * pc_y[j] - 0.5 * fl2_fx * pb_xy[j] - 0.5 * pa_xx[j] * fl1_fx * pb_x[j] * pc_y[j] - 0.5 * pa_xx[j] * fl1_fx * pc_x[j] * pb_y[j] - 0.5 * pa_xx[j] * fl1_fx * pb_xy[j] - pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] - pa_xz[j] * fl1_fx * pb_y[j] * pc_z[j] - pa_xz[j] * fl1_fx * pc_y[j] * pb_z[j] - pa_x[j] * fl1_fx * pc_z[j] * pb_yz[j] - pa_xz[j] * fl1_fx * pb_yz[j] - 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xy[j] * pc_z[j] - 0.5 * fl1_fx * pa_z[j] * pb_xz[j] * pc_y[j] - 0.5 * fl1_fx * pc_z[j] * pb_xyz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xyz[j] - pa_xxz[j] * pb_xy[j] * pc_z[j] - pa_xxz[j] * pb_xz[j] * pc_y[j] - pa_xxz[j] * pc_x[j] * pb_yz[j] - pa_xx[j] * pc_z[j] * pb_xyz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xyz[j]);

                t_xxz_xyz[j] += fl_s_0_0_2 * (pa_x[j] * fl2_fx * pc_y[j] + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pb_x[j] * pc_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_xx[j] * fl1_fx * pc_xy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_x[j] * pc_y[j] + 0.5 * pa_xx[j] * fl1_fx * pc_x[j] * pb_y[j] + pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] + pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_xy[j] + pa_xz[j] * fl1_fx * pc_yz[j] + pa_x[j] * fl1_fx * pc_zz[j] * pb_y[j] + pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] + pa_xz[j] * fl1_fx * pb_y[j] * pc_z[j] + pa_xz[j] * fl1_fx * pc_y[j] * pb_z[j] + pa_x[j] * fl1_fx * pc_z[j] * pb_yz[j] + 0.5 * pc_xx[j] * fl1_fx * pb_xy[j] + 1.5 * pc_xz[j] * fl1_fx * pa_z[j] * pb_y[j] + 1.5 * pc_xy[j] * fl1_fx * pa_z[j] * pb_z[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yz[j] + 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_yz[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xy[j] + 0.5 * fl1_fx * pc_yz[j] * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xy[j] * pc_z[j] + 0.5 * fl1_fx * pa_z[j] * pb_xz[j] * pc_y[j] + 0.5 * fl1_fx * pc_z[j] * pb_xyz[j] + pa_xxz[j] * pb_x[j] * pc_yz[j] + pa_xxz[j] * pc_xz[j] * pb_y[j] + pa_xxz[j] * pc_xy[j] * pb_z[j] + pa_xx[j] * pc_zz[j] * pb_xy[j] + pa_xx[j] * pc_yz[j] * pb_xz[j] + pa_xx[j] * pc_xz[j] * pb_yz[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_xy[j] + 2.0 * pa_xz[j] * pc_xy[j] * pb_xz[j] + 2.0 * pa_xz[j] * pc_xx[j] * pb_yz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xyz[j] + pc_xx[j] * pa_z[j] * pb_xyz[j]);

                t_xxz_xyz[j] += fl_s_0_0_3 * (-0.5 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.25 * fl2_fx * pb_x[j] * pc_y[j] - 0.5 * pa_xx[j] * fl1_fx * pc_xy[j] - pa_x[j] * pc_xxy[j] * fl1_fx - pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] - pa_x[j] * pc_xx[j] * fl1_fx * pb_y[j] - pa_x[j] * fl1_fx * pc_yzz[j] - pa_xz[j] * fl1_fx * pc_yz[j] - pa_x[j] * fl1_fx * pc_zz[j] * pb_y[j] - pa_x[j] * fl1_fx * pc_yz[j] * pb_z[j] - 0.5 * pc_xxy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] - 0.5 * pc_xx[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xyz[j] * fl1_fx * pa_z[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pa_z[j] * pb_y[j] - 1.5 * pc_xy[j] * fl1_fx * pa_z[j] * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pc_yzz[j] * pb_x[j] - 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_yz[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xy[j] - 0.5 * fl1_fx * pc_yz[j] * pb_xz[j] - pa_xxz[j] * pc_xyz[j] - pa_xx[j] * pc_yzz[j] * pb_x[j] - pa_xx[j] * pc_xzz[j] * pb_y[j] - pa_xx[j] * pc_xyz[j] * pb_z[j] - 2.0 * pa_xz[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xxz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_xxy[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xzz[j] * pb_xy[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xz[j] - 2.0 * pa_x[j] * pc_xxz[j] * pb_yz[j] - pc_xxz[j] * pa_z[j] * pb_xy[j] - pc_xxy[j] * pa_z[j] * pb_xz[j] - pc_xxx[j] * pa_z[j] * pb_yz[j] - pc_xxz[j] * pb_xyz[j]);

                t_xxz_xyz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + pa_x[j] * pc_xxy[j] * fl1_fx + pa_x[j] * fl1_fx * pc_yzz[j] + 0.5 * pc_xxxy[j] * fl1_fx + 0.5 * pc_xxy[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pa_z[j] + 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yzz[j] * pb_x[j] + pa_xx[j] * pc_xyzz[j] + 2.0 * pa_xz[j] * pc_xxyz[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xxzz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_xxyz[j] * pb_z[j] + pc_xxyz[j] * pa_z[j] * pb_x[j] + pc_xxxz[j] * pa_z[j] * pb_y[j] + pc_xxxy[j] * pa_z[j] * pb_z[j] + pc_xxzz[j] * pb_xy[j] + pc_xxyz[j] * pb_xz[j] + pc_xxxz[j] * pb_yz[j]);

                t_xxz_xyz[j] += fl_s_0_0_5 * (-0.5 * pc_xxxy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxyzz[j] - pc_xxxyz[j] * pa_z[j] - pc_xxyzz[j] * pb_x[j] - pc_xxxzz[j] * pb_y[j] - pc_xxxyz[j] * pb_z[j]);

                t_xxz_xyz[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_xxz_xzz[j] = fl_s_0_0_0 * (0.5 * pa_xz[j] * fl2_fx + pa_x[j] * fl2_fx * pb_z[j] + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xxz[j] * pb_x[j] * fl1_fx + pa_xx[j] * fl1_fx * pb_xz[j] + pa_xz[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xzz[j] + pa_xxz[j] * pb_xzz[j]);

                t_xxz_xzz[j] += fl_s_0_0_1 * (-pa_xz[j] * fl2_fx - 1.5 * pa_x[j] * fl2_fx * pc_z[j] - 2.0 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 1.5 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - fl2_fx * pb_xz[j] - 0.5 * pa_xxz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xxz[j] * pc_x[j] * fl1_fx - 1.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx - pa_xx[j] * fl1_fx * pc_x[j] * pb_z[j] - pa_xx[j] * fl1_fx * pb_xz[j] - pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx - 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] - 2.0 * pa_xz[j] * fl1_fx * pb_z[j] * pc_z[j] - pa_x[j] * fl1_fx * pc_z[j] * pb_zz[j] - pa_xz[j] * fl1_fx * pb_zz[j] - 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_zz[j] - fl1_fx * pa_z[j] * pb_xz[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_xzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xzz[j] - 2.0 * pa_xxz[j] * pb_xz[j] * pc_z[j] - pa_xxz[j] * pc_x[j] * pb_zz[j] - pa_xx[j] * pc_z[j] * pb_xzz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_xzz[j]);

                t_xxz_xzz[j] += fl_s_0_0_2 * (3.0 * pa_x[j] * fl2_fx * pc_z[j] + 0.5 * pa_xz[j] * fl2_fx + pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pc_x[j] * fl2_fx * pa_z[j] + 2.25 * pc_xz[j] * fl2_fx + 3.0 * pc_x[j] * fl2_fx * pb_z[j] + 1.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xxz[j] * pc_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx + pa_xx[j] * fl1_fx * pc_x[j] * pb_z[j] + pa_xz[j] * pc_x[j] * pb_x[j] * fl1_fx + pa_xz[j] * pc_xx[j] * fl1_fx + 3.0 * pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx + 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_xz[j] + pa_xz[j] * fl1_fx * pc_zz[j] + 2.0 * pa_x[j] * fl1_fx * pc_zz[j] * pb_z[j] + 2.0 * pa_xz[j] * fl1_fx * pb_z[j] * pc_z[j] + pa_x[j] * fl1_fx * pc_z[j] * pb_zz[j] + 0.5 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx + pc_xx[j] * fl1_fx * pb_xz[j] + 3.0 * pc_xz[j] * fl1_fx * pa_z[j] * pb_z[j] + 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_zz[j] + fl1_fx * pc_zz[j] * pb_xz[j] + fl1_fx * pa_z[j] * pb_xz[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_xzz[j] + pa_xxz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xxz[j] * pc_xz[j] * pb_z[j] + 2.0 * pa_xx[j] * pc_zz[j] * pb_xz[j] + pa_xx[j] * pc_xz[j] * pb_zz[j] + 4.0 * pa_xz[j] * pc_xz[j] * pb_xz[j] + 2.0 * pa_xz[j] * pc_xx[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_xzz[j] + pc_xx[j] * pa_z[j] * pb_xzz[j]);

                t_xxz_xzz[j] += fl_s_0_0_3 * (-1.5 * pa_x[j] * fl2_fx * pc_z[j] - 4.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 1.5 * pc_x[j] * fl2_fx * pb_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 1.5 * pa_xx[j] * pc_xz[j] * fl1_fx - pa_xz[j] * pc_xx[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * pc_xxz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xx[j] * fl1_fx * pb_z[j] - pa_x[j] * fl1_fx * pc_zzz[j] - pa_xz[j] * fl1_fx * pc_zz[j] - 2.0 * pa_x[j] * fl1_fx * pc_zz[j] * pb_z[j] - 0.5 * pc_xx[j] * pa_z[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxx[j] * pa_z[j] * fl1_fx - 1.5 * pc_xxz[j] * pb_x[j] * fl1_fx - pc_xxx[j] * fl1_fx * pb_z[j] - pc_xx[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xzz[j] * fl1_fx * pa_z[j] - 3.0 * pc_xzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pa_z[j] * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] - 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_zz[j] - fl1_fx * pc_zz[j] * pb_xz[j] - pa_xxz[j] * pc_xzz[j] - pa_xx[j] * pc_zzz[j] * pb_x[j] - 2.0 * pa_xx[j] * pc_xzz[j] * pb_z[j] - 2.0 * pa_xz[j] * pc_xzz[j] * pb_x[j] - 4.0 * pa_xz[j] * pc_xxz[j] * pb_z[j] - 4.0 * pa_x[j] * pc_xzz[j] * pb_xz[j] - 2.0 * pa_x[j] * pc_xxz[j] * pb_zz[j] - 2.0 * pc_xxz[j] * pa_z[j] * pb_xz[j] - pc_xxx[j] * pa_z[j] * pb_zz[j] - pc_xxz[j] * pb_xzz[j]);

                t_xxz_xzz[j] += fl_s_0_0_4 * (2.25 * pc_xz[j] * fl2_fx + 3.0 * pa_x[j] * pc_xxz[j] * fl1_fx + pa_x[j] * fl1_fx * pc_zzz[j] + 0.5 * pc_xxx[j] * pa_z[j] * fl1_fx + 1.5 * pc_xxz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xxxz[j] * fl1_fx + pc_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pc_xzzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pa_z[j] + 3.0 * pc_xzz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] + pa_xx[j] * pc_xzzz[j] + 2.0 * pa_xz[j] * pc_xxzz[j] + 2.0 * pa_x[j] * pc_xzzz[j] * pb_x[j] + 4.0 * pa_x[j] * pc_xxzz[j] * pb_z[j] + pc_xxzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxxz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xxzz[j] * pb_xz[j] + pc_xxxz[j] * pb_zz[j]);

                t_xxz_xzz[j] += fl_s_0_0_5 * (-1.5 * pc_xxxz[j] * fl1_fx - 1.5 * pc_xzzz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xxzzz[j] - pc_xxxzz[j] * pa_z[j] - pc_xxzzz[j] * pb_x[j] - 2.0 * pc_xxxzz[j] * pb_z[j]);

                t_xxz_xzz[j] += fl_s_0_0_6 * pc_xxxzzz[j];

                t_xxz_yyy[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_xxz[j] * pb_y[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_yyy[j] + pa_xxz[j] * pb_yyy[j]);

                t_xxz_yyy[j] += fl_s_0_0_1 * (-1.5 * fl2_fx * pa_z[j] * pb_y[j] - 0.75 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 1.5 * pa_xxz[j] * pb_y[j] * fl1_fx - 1.5 * pa_xxz[j] * pc_y[j] * fl1_fx - 1.5 * pa_xx[j] * pc_z[j] * pb_y[j] * fl1_fx - 3.0 * pa_xz[j] * pc_x[j] * pb_y[j] * fl1_fx - 1.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_y[j] - 0.5 * fl1_fx * pc_z[j] * pb_yyy[j] - 0.5 * fl1_fx * pa_z[j] * pb_yyy[j] - 3.0 * pa_xxz[j] * pb_yy[j] * pc_y[j] - pa_xx[j] * pc_z[j] * pb_yyy[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_yyy[j]);

                t_xxz_yyy[j] += fl_s_0_0_2 * (1.5 * fl2_fx * pa_z[j] * pc_y[j] + 1.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.75 * fl2_fx * pc_yz[j] + 0.75 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_xxz[j] * pc_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx + 3.0 * pa_xz[j] * pc_x[j] * pb_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_x[j] * pc_xz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xx[j] * pa_z[j] * pb_y[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_yy[j] + 1.5 * fl1_fx * pc_yz[j] * pb_yy[j] + 1.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_y[j] + 0.5 * fl1_fx * pc_z[j] * pb_yyy[j] + 3.0 * pa_xxz[j] * pb_y[j] * pc_yy[j] + 3.0 * pa_xx[j] * pc_yz[j] * pb_yy[j] + 6.0 * pa_xz[j] * pc_xy[j] * pb_yy[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_yyy[j] + pc_xx[j] * pa_z[j] * pb_yyy[j]);

                t_xxz_yyy[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx - 3.0 * pa_xz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 1.5 * pc_xx[j] * pa_z[j] * pb_y[j] * fl1_fx - 1.5 * pc_xxy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xxz[j] * pb_y[j] * fl1_fx - 0.5 * fl1_fx * pa_z[j] * pc_yyy[j] - 1.5 * fl1_fx * pc_yyz[j] * pb_y[j] - 1.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_yy[j] - 1.5 * fl1_fx * pc_yz[j] * pb_yy[j] - pa_xxz[j] * pc_yyy[j] - 3.0 * pa_xx[j] * pc_yyz[j] * pb_y[j] - 6.0 * pa_xz[j] * pc_xyy[j] * pb_y[j] - 6.0 * pa_x[j] * pc_xyz[j] * pb_yy[j] - 3.0 * pc_xxy[j] * pa_z[j] * pb_yy[j] - pc_xxz[j] * pb_yyy[j]);

                t_xxz_yyy[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 1.5 * pc_xxy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xxz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + 0.5 * fl1_fx * pc_yyyz[j] + 0.5 * fl1_fx * pa_z[j] * pc_yyy[j] + 1.5 * fl1_fx * pc_yyz[j] * pb_y[j] + pa_xx[j] * pc_yyyz[j] + 2.0 * pa_xz[j] * pc_xyyy[j] + 6.0 * pa_x[j] * pc_xyyz[j] * pb_y[j] + 3.0 * pc_xxyy[j] * pa_z[j] * pb_y[j] + 3.0 * pc_xxyz[j] * pb_yy[j]);

                t_xxz_yyy[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyz[j] - 2.0 * pa_x[j] * pc_xyyyz[j] - pc_xxyyy[j] * pa_z[j] - 3.0 * pc_xxyyz[j] * pb_y[j]);

                t_xxz_yyy[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_xxz_yyz[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xxz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pb_yyz[j] + pa_xxz[j] * pb_yyz[j]);

                t_xxz_yyz[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * pa_xx[j] * fl2_fx - 0.5 * pa_x[j] * pc_x[j] * fl2_fx - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_y[j] * pc_y[j] - 0.5 * fl2_fx * pb_yy[j] - 0.5 * pa_xxz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xxz[j] * fl1_fx * pb_z[j] - 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_xx[j] * fl1_fx * pb_y[j] * pc_y[j] - 0.5 * pa_xx[j] * fl1_fx * pb_yy[j] - pa_xz[j] * pc_x[j] * fl1_fx * pb_z[j] - pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] - 0.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_z[j] - fl1_fx * pa_z[j] * pb_yz[j] * pc_y[j] - 0.5 * fl1_fx * pc_z[j] * pb_yyz[j] - 0.5 * fl1_fx * pa_z[j] * pb_yyz[j] - pa_xxz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xxz[j] * pb_yz[j] * pc_y[j] - pa_xx[j] * pc_z[j] * pb_yyz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_yyz[j]);

                t_xxz_yyz[j] += fl_s_0_0_2 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * pc_x[j] * fl2_fx + 0.25 * pc_xx[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pc_z[j] + 0.25 * fl2_fx * pc_zz[j] + 0.5 * fl2_fx * pc_z[j] * pb_z[j] + 0.25 * fl2_fx * pc_yy[j] + fl2_fx * pb_y[j] * pc_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xxz[j] * fl1_fx * pc_z[j] + 0.5 * pa_xx[j] * pc_zz[j] * fl1_fx + 0.5 * pa_xx[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pc_yy[j] + pa_xx[j] * fl1_fx * pb_y[j] * pc_y[j] + pa_xz[j] * pc_xz[j] * fl1_fx + pa_xz[j] * pc_x[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] + pa_x[j] * pc_x[j] * fl1_fx * pb_yy[j] + 0.5 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] + fl1_fx * pa_z[j] * pb_y[j] * pc_yz[j] + 0.5 * fl1_fx * pa_z[j] * pc_yy[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] + fl1_fx * pc_yz[j] * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_z[j] + fl1_fx * pa_z[j] * pb_yz[j] * pc_y[j] + 0.5 * fl1_fx * pc_z[j] * pb_yyz[j] + 2.0 * pa_xxz[j] * pb_y[j] * pc_yz[j] + pa_xxz[j] * pc_yy[j] * pb_z[j] + pa_xx[j] * pc_zz[j] * pb_yy[j] + 2.0 * pa_xx[j] * pc_yz[j] * pb_yz[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_yy[j] + 4.0 * pa_xz[j] * pc_xy[j] * pb_yz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_yyz[j] + pc_xx[j] * pa_z[j] * pb_yyz[j]);

                t_xxz_yyz[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * pa_x[j] * pc_x[j] * fl2_fx - 0.5 * pc_xx[j] * fl2_fx - 0.5 * fl2_fx * pc_zz[j] - 0.5 * fl2_fx * pc_yy[j] - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_y[j] * pc_y[j] - 0.5 * pa_xx[j] * pc_zz[j] * fl1_fx - 0.5 * pa_xx[j] * fl1_fx * pc_yy[j] - pa_xz[j] * pc_xz[j] * fl1_fx - pa_x[j] * pc_xzz[j] * fl1_fx - pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] - pa_x[j] * pc_xyy[j] * fl1_fx - 2.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xxz[j] * pa_z[j] * fl1_fx - 0.5 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] - 0.5 * pc_xxz[j] * fl1_fx * pb_z[j] - pc_xxy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] - 0.5 * fl1_fx * pa_z[j] * pc_yyz[j] - fl1_fx * pc_yzz[j] * pb_y[j] - 0.5 * fl1_fx * pc_yyz[j] * pb_z[j] - fl1_fx * pa_z[j] * pb_y[j] * pc_yz[j] - 0.5 * fl1_fx * pa_z[j] * pc_yy[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] - fl1_fx * pc_yz[j] * pb_yz[j] - pa_xxz[j] * pc_yyz[j] - 2.0 * pa_xx[j] * pc_yzz[j] * pb_y[j] - pa_xx[j] * pc_yyz[j] * pb_z[j] - 4.0 * pa_xz[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_xyy[j] * pb_z[j] - 2.0 * pa_x[j] * pc_xzz[j] * pb_yy[j] - 4.0 * pa_x[j] * pc_xyz[j] * pb_yz[j] - pc_xxz[j] * pa_z[j] * pb_yy[j] - 2.0 * pc_xxy[j] * pa_z[j] * pb_yz[j] - pc_xxz[j] * pb_yyz[j]);

                t_xxz_yyz[j] += fl_s_0_0_4 * (0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_zz[j] + 0.25 * fl2_fx * pc_yy[j] + pa_x[j] * pc_xzz[j] * fl1_fx + pa_x[j] * pc_xyy[j] * fl1_fx + 0.5 * pc_xxz[j] * pa_z[j] * fl1_fx + 0.5 * pc_xxzz[j] * fl1_fx + 0.5 * pc_xxz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xxyy[j] * fl1_fx + pc_xxy[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_yyz[j] + fl1_fx * pc_yzz[j] * pb_y[j] + 0.5 * fl1_fx * pc_yyz[j] * pb_z[j] + pa_xx[j] * pc_yyzz[j] + 2.0 * pa_xz[j] * pc_xyyz[j] + 4.0 * pa_x[j] * pc_xyzz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_z[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_y[j] + pc_xxyy[j] * pa_z[j] * pb_z[j] + pc_xxzz[j] * pb_yy[j] + 2.0 * pc_xxyz[j] * pb_yz[j]);

                t_xxz_yyz[j] += fl_s_0_0_5 * (-0.5 * pc_xxzz[j] * fl1_fx - 0.5 * pc_xxyy[j] * fl1_fx - 0.5 * fl1_fx * pc_yyzz[j] - 2.0 * pa_x[j] * pc_xyyzz[j] - pc_xxyyz[j] * pa_z[j] - 2.0 * pc_xxyzz[j] * pb_y[j] - pc_xxyyz[j] * pb_z[j]);

                t_xxz_yyz[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_xxz_yzz[j] = fl_s_0_0_0 * (0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xxz[j] * pb_y[j] * fl1_fx + pa_xx[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_yzz[j] + pa_xxz[j] * pb_yzz[j]);

                t_xxz_yzz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_z[j] * pb_y[j] - 0.25 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * fl2_fx * pc_y[j] * pb_z[j] - fl2_fx * pb_yz[j] - 0.5 * pa_xxz[j] * pb_y[j] * fl1_fx - 0.5 * pa_xxz[j] * pc_y[j] * fl1_fx - 1.5 * pa_xx[j] * pc_z[j] * pb_y[j] * fl1_fx - pa_xx[j] * fl1_fx * pc_y[j] * pb_z[j] - pa_xx[j] * fl1_fx * pb_yz[j] - pa_xz[j] * pc_x[j] * pb_y[j] * fl1_fx - 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] - fl1_fx * pa_z[j] * pb_yz[j] * pc_z[j] - 0.5 * fl1_fx * pa_z[j] * pc_y[j] * pb_zz[j] - 0.5 * fl1_fx * pc_z[j] * pb_yzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_yzz[j] - 2.0 * pa_xxz[j] * pb_yz[j] * pc_z[j] - pa_xxz[j] * pc_y[j] * pb_zz[j] - pa_xx[j] * pc_z[j] * pb_yzz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_yzz[j]);

                t_xxz_yzz[j] += fl_s_0_0_2 * (0.5 * fl2_fx * pa_z[j] * pc_y[j] + 1.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.75 * fl2_fx * pc_yz[j] + fl2_fx * pc_y[j] * pb_z[j] + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xxz[j] * pc_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx + pa_xx[j] * fl1_fx * pc_y[j] * pb_z[j] + pa_xz[j] * pc_x[j] * pb_y[j] * fl1_fx + pa_xz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_x[j] * pc_xz[j] * pb_y[j] * fl1_fx + 2.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_yz[j] + 0.5 * pc_xx[j] * pa_z[j] * pb_y[j] * fl1_fx + pc_xx[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_zz[j] + fl1_fx * pa_z[j] * pc_yz[j] * pb_z[j] + fl1_fx * pc_zz[j] * pb_yz[j] + 0.5 * fl1_fx * pc_yz[j] * pb_zz[j] + fl1_fx * pa_z[j] * pb_yz[j] * pc_z[j] + 0.5 * fl1_fx * pa_z[j] * pc_y[j] * pb_zz[j] + 0.5 * fl1_fx * pc_z[j] * pb_yzz[j] + pa_xxz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xxz[j] * pc_yz[j] * pb_z[j] + 2.0 * pa_xx[j] * pc_zz[j] * pb_yz[j] + pa_xx[j] * pc_yz[j] * pb_zz[j] + 4.0 * pa_xz[j] * pc_xz[j] * pb_yz[j] + 2.0 * pa_xz[j] * pc_xy[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_yzz[j] + pc_xx[j] * pa_z[j] * pb_yzz[j]);

                t_xxz_yzz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.25 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xx[j] * pc_yz[j] * fl1_fx - pa_xz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx - 2.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * pa_z[j] * pb_y[j] * fl1_fx - 0.5 * pc_xxy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xxz[j] * pb_y[j] * fl1_fx - pc_xxy[j] * fl1_fx * pb_z[j] - pc_xx[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pa_z[j] * pc_yzz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] - fl1_fx * pc_yzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_zz[j] - fl1_fx * pa_z[j] * pc_yz[j] * pb_z[j] - fl1_fx * pc_zz[j] * pb_yz[j] - 0.5 * fl1_fx * pc_yz[j] * pb_zz[j] - pa_xxz[j] * pc_yzz[j] - pa_xx[j] * pc_zzz[j] * pb_y[j] - 2.0 * pa_xx[j] * pc_yzz[j] * pb_z[j] - 2.0 * pa_xz[j] * pc_xzz[j] * pb_y[j] - 4.0 * pa_xz[j] * pc_xyz[j] * pb_z[j] - 4.0 * pa_x[j] * pc_xzz[j] * pb_yz[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_zz[j] - 2.0 * pc_xxz[j] * pa_z[j] * pb_yz[j] - pc_xxy[j] * pa_z[j] * pb_zz[j] - pc_xxz[j] * pb_yzz[j]);

                t_xxz_yzz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 3.0 * pa_x[j] * pc_xyz[j] * fl1_fx + 0.5 * pc_xxy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xxz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + pc_xxy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yzzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_yzz[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] + fl1_fx * pc_yzz[j] * pb_z[j] + pa_xx[j] * pc_yzzz[j] + 2.0 * pa_xz[j] * pc_xyzz[j] + 2.0 * pa_x[j] * pc_xzzz[j] * pb_y[j] + 4.0 * pa_x[j] * pc_xyzz[j] * pb_z[j] + pc_xxzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xxzz[j] * pb_yz[j] + pc_xxyz[j] * pb_zz[j]);

                t_xxz_yzz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yzzz[j] - 2.0 * pa_x[j] * pc_xyzzz[j] - pc_xxyzz[j] * pa_z[j] - pc_xxzzz[j] * pb_y[j] - 2.0 * pc_xxyzz[j] * pb_z[j]);

                t_xxz_yzz[j] += fl_s_0_0_6 * pc_xxyzzz[j];

                t_xxz_zzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_xxz[j] * pb_z[j] * fl1_fx + 1.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] + pa_xxz[j] * pb_zzz[j]);

                t_xxz_zzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_xx[j] * fl2_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_z[j] - 1.5 * fl2_fx * pb_zz[j] - 1.5 * pa_xxz[j] * pb_z[j] * fl1_fx - 1.5 * pa_xxz[j] * pc_z[j] * fl1_fx - 4.5 * pa_xx[j] * pc_z[j] * pb_z[j] * fl1_fx - 1.5 * pa_xx[j] * fl1_fx * pb_zz[j] - 3.0 * pa_xz[j] * pc_x[j] * pb_z[j] * fl1_fx - 3.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] - 1.5 * fl1_fx * pa_z[j] * pb_zz[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_zzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] - 3.0 * pa_xxz[j] * pb_zz[j] * pc_z[j] - pa_xx[j] * pc_z[j] * pb_zzz[j] - 2.0 * pa_xz[j] * pc_x[j] * pb_zzz[j]);

                t_xxz_zzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 3.0 * pa_x[j] * pc_x[j] * fl2_fx + 0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pc_z[j] + 4.5 * fl2_fx * pc_z[j] * pb_z[j] + 1.5 * fl2_fx * pc_zz[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_xxz[j] * pc_z[j] * fl1_fx + 4.5 * pa_xx[j] * pc_z[j] * pb_z[j] * fl1_fx + 3.0 * pa_xx[j] * pc_zz[j] * fl1_fx + 3.0 * pa_xz[j] * pc_x[j] * pb_z[j] * fl1_fx + 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx + 9.0 * pa_x[j] * pc_xz[j] * pb_z[j] * fl1_fx + 3.0 * pa_x[j] * pc_x[j] * fl1_fx * pb_zz[j] + 1.5 * pc_xx[j] * pa_z[j] * pb_z[j] * fl1_fx + 1.5 * pc_xx[j] * fl1_fx * pb_zz[j] + 1.5 * fl1_fx * pa_z[j] * pb_z[j] * pc_zz[j] + 1.5 * fl1_fx * pc_zz[j] * pb_zz[j] + 1.5 * fl1_fx * pa_z[j] * pb_zz[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_zzz[j] + 3.0 * pa_xxz[j] * pb_z[j] * pc_zz[j] + 3.0 * pa_xx[j] * pc_zz[j] * pb_zz[j] + 6.0 * pa_xz[j] * pc_xz[j] * pb_zz[j] + 2.0 * pa_x[j] * pc_xz[j] * pb_zzz[j] + pc_xx[j] * pa_z[j] * pb_zzz[j]);

                t_xxz_zzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_x[j] * pc_x[j] * fl2_fx - 1.5 * pc_xx[j] * fl2_fx - 3.0 * fl2_fx * pc_zz[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_z[j] - 3.0 * pa_xx[j] * pc_zz[j] * fl1_fx - 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx - 9.0 * pa_x[j] * pc_xz[j] * pb_z[j] * fl1_fx - 6.0 * pa_x[j] * pc_xzz[j] * fl1_fx - 1.5 * pc_xx[j] * pa_z[j] * pb_z[j] * fl1_fx - 1.5 * pc_xxz[j] * pa_z[j] * fl1_fx - 4.5 * pc_xxz[j] * pb_z[j] * fl1_fx - 1.5 * pc_xx[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pa_z[j] * pc_zzz[j] - 1.5 * fl1_fx * pc_zzz[j] * pb_z[j] - 1.5 * fl1_fx * pa_z[j] * pb_z[j] * pc_zz[j] - 1.5 * fl1_fx * pc_zz[j] * pb_zz[j] - pa_xxz[j] * pc_zzz[j] - 3.0 * pa_xx[j] * pc_zzz[j] * pb_z[j] - 6.0 * pa_xz[j] * pc_xzz[j] * pb_z[j] - 6.0 * pa_x[j] * pc_xzz[j] * pb_zz[j] - 3.0 * pc_xxz[j] * pa_z[j] * pb_zz[j] - pc_xxz[j] * pb_zzz[j]);

                t_xxz_zzz[j] += fl_s_0_0_4 * (0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pc_zz[j] + 6.0 * pa_x[j] * pc_xzz[j] * fl1_fx + 1.5 * pc_xxz[j] * pa_z[j] * fl1_fx + 4.5 * pc_xxz[j] * pb_z[j] * fl1_fx + 3.0 * pc_xxzz[j] * fl1_fx + 0.5 * fl1_fx * pc_zzzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_zzz[j] + 1.5 * fl1_fx * pc_zzz[j] * pb_z[j] + pa_xx[j] * pc_zzzz[j] + 2.0 * pa_xz[j] * pc_xzzz[j] + 6.0 * pa_x[j] * pc_xzzz[j] * pb_z[j] + 3.0 * pc_xxzz[j] * pa_z[j] * pb_z[j] + 3.0 * pc_xxzz[j] * pb_zz[j]);

                t_xxz_zzz[j] += fl_s_0_0_5 * (-3.0 * pc_xxzz[j] * fl1_fx - 0.5 * fl1_fx * pc_zzzz[j] - 2.0 * pa_x[j] * pc_xzzzz[j] - pc_xxzzz[j] * pa_z[j] - 3.0 * pc_xxzzz[j] * pb_z[j]);

                t_xxz_zzz[j] += fl_s_0_0_6 * pc_xxzzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_30_40(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (30,40)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(19 * idx + 4);

            auto pa_yy = paDistances.data(19 * idx + 6);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xyy = paDistances.data(19 * idx + 12);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxy = pcDistances.data(83 * idx + 35);

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xyyyy = pcDistances.data(83 * idx + 44);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_yyyyy = pcDistances.data(83 * idx + 49);

            auto pc_yyyyz = pcDistances.data(83 * idx + 50);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxyy = pcDistances.data(83 * idx + 58);

            auto pc_xxxyyy = pcDistances.data(83 * idx + 61);

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxyyyy = pcDistances.data(83 * idx + 65);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xyyyyy = pcDistances.data(83 * idx + 70);

            auto pc_xyyyyz = pcDistances.data(83 * idx + 71);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xyy_xxx = primBuffer.data(100 * idx + 30);

            auto t_xyy_xxy = primBuffer.data(100 * idx + 31);

            auto t_xyy_xxz = primBuffer.data(100 * idx + 32);

            auto t_xyy_xyy = primBuffer.data(100 * idx + 33);

            auto t_xyy_xyz = primBuffer.data(100 * idx + 34);

            auto t_xyy_xzz = primBuffer.data(100 * idx + 35);

            auto t_xyy_yyy = primBuffer.data(100 * idx + 36);

            auto t_xyy_yyz = primBuffer.data(100 * idx + 37);

            auto t_xyy_yzz = primBuffer.data(100 * idx + 38);

            auto t_xyy_zzz = primBuffer.data(100 * idx + 39);

            // Batch of Integrals (30,40)

            #pragma omp simd aligned(fx, pa_x, pa_xy, pa_xyy, pa_y, pa_yy, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxy, pc_xxxxyy, pc_xxxy, pc_xxxyy, \
                                     pc_xxxyyy, pc_xxxyyz, pc_xxxyz, pc_xxxz, pc_xxy, pc_xxyy, pc_xxyyy, pc_xxyyyy, \
                                     pc_xxyyyz, pc_xxyyz, pc_xxyyzz, pc_xxyz, pc_xxyzz, pc_xxz, pc_xxzz, pc_xy, pc_xyy, \
                                     pc_xyyy, pc_xyyyy, pc_xyyyyy, pc_xyyyyz, pc_xyyyz, pc_xyyyzz, pc_xyyz, pc_xyyzz, \
                                     pc_xyyzzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xz, pc_xzz, pc_xzzz, pc_y, pc_yy, pc_yyy, \
                                     pc_yyyy, pc_yyyyy, pc_yyyyz, pc_yyyz, pc_yyyzz, pc_yyz, pc_yyzz, pc_yyzzz, pc_yz, \
                                     pc_yzz, pc_yzzz, pc_z, pc_zz, pc_zzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, \
                                     s_0_0_5, s_0_0_6, t_xyy_xxx, t_xyy_xxy, t_xyy_xxz, t_xyy_xyy, t_xyy_xyz, \
                                     t_xyy_xzz, t_xyy_yyy, t_xyy_yyz, t_xyy_yzz, t_xyy_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xyy_xxx[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_yy[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xyy[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_yy[j] * pb_xx[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] + pa_xyy[j] * pb_xxx[j]);

                t_xyy_xxx[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * fl2_fx * pa_yy[j] - 1.5 * fl2_fx * pa_y[j] * pc_y[j] - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 2.25 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pb_xx[j] - 1.5 * pa_xyy[j] * pb_x[j] * fl1_fx - 1.5 * pa_xyy[j] * pc_x[j] * fl1_fx - 3.0 * pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx - 4.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx - 3.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xx[j] - 1.5 * fl1_fx * pa_yy[j] * pb_xx[j] - 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_xyy[j] * pb_xx[j] * pc_x[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xxx[j] - pc_x[j] * pa_yy[j] * pb_xxx[j]);

                t_xyy_xxx[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 3.0 * fl2_fx * pa_y[j] * pc_y[j] + 0.75 * fl2_fx * pc_yy[j] + 0.75 * fl2_fx * pa_yy[j] + 1.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 4.5 * pc_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xyy[j] * pc_x[j] * fl1_fx + 3.0 * pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx + 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx + 4.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx + 3.0 * pc_xx[j] * pa_yy[j] * fl1_fx + 9.0 * pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pc_yy[j] * pb_xx[j] + 3.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xx[j] + 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_xx[j] + 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_x[j] + 1.5 * pc_xx[j] * fl1_fx * pb_xx[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_xyy[j] * pb_x[j] * pc_xx[j] + 6.0 * pa_xy[j] * pc_xy[j] * pb_xx[j] + pa_x[j] * pc_yy[j] * pb_xxx[j] + 3.0 * pc_xx[j] * pa_yy[j] * pb_xx[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xxx[j]);

                t_xyy_xxx[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * fl2_fx * pc_yy[j] - 1.5 * fl2_fx * pa_y[j] * pc_y[j] - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 3.0 * pc_xx[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_x[j] - 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xyy[j] * fl1_fx - 3.0 * pc_xx[j] * pa_yy[j] * fl1_fx - 9.0 * pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx - 6.0 * pc_xxy[j] * pa_y[j] * fl1_fx - 4.5 * pc_xyy[j] * pb_x[j] * fl1_fx - 1.5 * fl1_fx * pc_yy[j] * pb_xx[j] - 0.5 * pa_x[j] * fl1_fx * pc_xxx[j] - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_xx[j] - 1.5 * pc_xxx[j] * fl1_fx * pb_x[j] - 1.5 * pc_xx[j] * fl1_fx * pb_xx[j] - pa_xyy[j] * pc_xxx[j] - 6.0 * pa_xy[j] * pc_xxy[j] * pb_x[j] - 3.0 * pa_x[j] * pc_xyy[j] * pb_xx[j] - 3.0 * pc_xxx[j] * pa_yy[j] * pb_x[j] - 6.0 * pc_xxy[j] * pa_y[j] * pb_xx[j] - pc_xyy[j] * pb_xxx[j]);

                t_xyy_xxx[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yy[j] + 1.5 * pc_xx[j] * fl2_fx + 1.5 * pa_x[j] * pc_xyy[j] * fl1_fx + 6.0 * pc_xxy[j] * pa_y[j] * fl1_fx + 4.5 * pc_xyy[j] * pb_x[j] * fl1_fx + 3.0 * pc_xxyy[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_xxx[j] + 0.5 * pc_xxxx[j] * fl1_fx + 1.5 * pc_xxx[j] * fl1_fx * pb_x[j] + 2.0 * pa_xy[j] * pc_xxxy[j] + 3.0 * pa_x[j] * pc_xxyy[j] * pb_x[j] + pc_xxxx[j] * pa_yy[j] + 6.0 * pc_xxxy[j] * pa_y[j] * pb_x[j] + 3.0 * pc_xxyy[j] * pb_xx[j]);

                t_xyy_xxx[j] += fl_s_0_0_5 * (-3.0 * pc_xxyy[j] * fl1_fx - 0.5 * pc_xxxx[j] * fl1_fx - pa_x[j] * pc_xxxyy[j] - 2.0 * pc_xxxxy[j] * pa_y[j] - 3.0 * pc_xxxyy[j] * pb_x[j]);

                t_xyy_xxx[j] += fl_s_0_0_6 * pc_xxxxyy[j];

                t_xyy_xxy[j] = fl_s_0_0_0 * (0.5 * pa_xy[j] * fl2_fx + fl2_fx * pa_y[j] * pb_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xyy[j] * fl1_fx * pb_y[j] + pa_xy[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_yy[j] * pb_xy[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxy[j] + pa_xyy[j] * pb_xxy[j]);

                t_xyy_xxy[j] += fl_s_0_0_1 * (-pa_xy[j] * fl2_fx - 0.75 * pa_x[j] * pc_y[j] * fl2_fx - 1.5 * pc_x[j] * pa_y[j] * fl2_fx - 2.0 * fl2_fx * pa_y[j] * pb_x[j] - 1.5 * fl2_fx * pc_y[j] * pb_x[j] - 0.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - fl2_fx * pb_xy[j] - 0.5 * pa_xyy[j] * fl1_fx * pc_y[j] - 0.5 * pa_xyy[j] * fl1_fx * pb_y[j] - pa_xy[j] * pc_y[j] * fl1_fx * pb_y[j] - 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_x[j] - pa_xy[j] * fl1_fx * pb_xx[j] - 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xx[j] - 1.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_y[j] - pc_x[j] * pa_y[j] * fl1_fx * pb_xx[j] - fl1_fx * pa_yy[j] * pb_x[j] * pc_y[j] - 2.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xy[j] - fl1_fx * pa_yy[j] * pb_xy[j] - pa_x[j] * fl1_fx * pb_xy[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxy[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxy[j] - pa_xyy[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xyy[j] * pb_xy[j] * pc_x[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xxy[j] - pc_x[j] * pa_yy[j] * pb_xxy[j]);

                t_xyy_xxy[j] += fl_s_0_0_2 * (0.5 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_y[j] * fl2_fx + 3.0 * pc_x[j] * pa_y[j] * fl2_fx + 2.25 * pc_xy[j] * fl2_fx + 3.0 * fl2_fx * pc_y[j] * pb_x[j] + fl2_fx * pa_y[j] * pb_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xyy[j] * fl1_fx * pc_y[j] + pa_xy[j] * pc_yy[j] * fl1_fx + pa_xy[j] * pc_y[j] * fl1_fx * pb_y[j] + pa_xy[j] * fl1_fx * pc_xx[j] + 2.0 * pa_xy[j] * fl1_fx * pb_x[j] * pc_x[j] + 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_y[j] + 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] + 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xy[j] * pa_yy[j] * fl1_fx + 1.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_y[j] + 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_y[j] + 2.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_x[j] + pc_x[j] * pa_y[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] + 2.0 * fl1_fx * pa_y[j] * pc_yy[j] * pb_x[j] + fl1_fx * pc_yy[j] * pb_xy[j] + fl1_fx * pa_yy[j] * pb_x[j] * pc_y[j] + 2.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xy[j] + 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_y[j] + pa_x[j] * fl1_fx * pb_xy[j] * pc_x[j] + pc_xx[j] * fl1_fx * pb_xy[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_xyy[j] * pb_x[j] * pc_xy[j] + pa_xyy[j] * pc_xx[j] * pb_y[j] + 2.0 * pa_xy[j] * pc_yy[j] * pb_xx[j] + 4.0 * pa_xy[j] * pc_xy[j] * pb_xy[j] + pa_x[j] * pc_yy[j] * pb_xxy[j] + pc_xy[j] * pa_yy[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_yy[j] * pb_xy[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xxy[j]);

                t_xyy_xxy[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_y[j] * fl2_fx - 1.5 * pc_x[j] * pa_y[j] * fl2_fx - 4.5 * pc_xy[j] * fl2_fx - 1.5 * fl2_fx * pc_y[j] * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - pa_xy[j] * pc_yy[j] * fl1_fx - pa_xy[j] * fl1_fx * pc_xx[j] - 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx - 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_y[j] - 1.5 * pa_x[j] * pc_xxy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] - 1.5 * pc_xy[j] * pa_yy[j] * fl1_fx - 3.0 * pc_xyy[j] * pa_y[j] * fl1_fx - 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_y[j] - pc_xxx[j] * pa_y[j] * fl1_fx - 2.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_x[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_y[j] - 3.0 * pc_xxy[j] * fl1_fx * pb_x[j] - 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] - fl1_fx * pc_yyy[j] * pb_x[j] - 2.0 * fl1_fx * pa_y[j] * pc_yy[j] * pb_x[j] - fl1_fx * pc_yy[j] * pb_xy[j] - 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_y[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] - pc_xx[j] * fl1_fx * pb_xy[j] - pa_xyy[j] * pc_xxy[j] - 4.0 * pa_xy[j] * pc_xyy[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xxy[j] * pb_y[j] - pa_x[j] * pc_yyy[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xyy[j] * pb_xy[j] - 2.0 * pc_xxy[j] * pa_yy[j] * pb_x[j] - pc_xxx[j] * pa_yy[j] * pb_y[j] - 2.0 * pc_xyy[j] * pa_y[j] * pb_xx[j] - 4.0 * pc_xxy[j] * pa_y[j] * pb_xy[j] - pc_xyy[j] * pb_xxy[j]);

                t_xyy_xxy[j] += fl_s_0_0_4 * (2.25 * pc_xy[j] * fl2_fx + 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx + 1.5 * pa_x[j] * pc_xxy[j] * fl1_fx + 3.0 * pc_xyy[j] * pa_y[j] * fl1_fx + pc_xxx[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyyy[j] * fl1_fx + 1.5 * pc_xyy[j] * fl1_fx * pb_y[j] + 1.5 * pc_xxxy[j] * fl1_fx + 3.0 * pc_xxy[j] * fl1_fx * pb_x[j] + fl1_fx * pc_yyy[j] * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] + 2.0 * pa_xy[j] * pc_xxyy[j] + 2.0 * pa_x[j] * pc_xyyy[j] * pb_x[j] + pa_x[j] * pc_xxyy[j] * pb_y[j] + pc_xxxy[j] * pa_yy[j] + 4.0 * pc_xxyy[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxxy[j] * pa_y[j] * pb_y[j] + pc_xyyy[j] * pb_xx[j] + 2.0 * pc_xxyy[j] * pb_xy[j]);

                t_xyy_xxy[j] += fl_s_0_0_5 * (-1.5 * pc_xyyy[j] * fl1_fx - 1.5 * pc_xxxy[j] * fl1_fx - pa_x[j] * pc_xxyyy[j] - 2.0 * pc_xxxyy[j] * pa_y[j] - 2.0 * pc_xxyyy[j] * pb_x[j] - pc_xxxyy[j] * pb_y[j]);

                t_xyy_xxy[j] += fl_s_0_0_6 * pc_xxxyyy[j];

                t_xyy_xxz[j] = fl_s_0_0_0 * (0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xyy[j] * fl1_fx * pb_z[j] + fl1_fx * pa_yy[j] * pb_xz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxz[j] + pa_xyy[j] * pb_xxz[j]);

                t_xyy_xxz[j] += fl_s_0_0_1 * (-0.25 * pa_x[j] * fl2_fx * pc_z[j] - 0.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * fl2_fx * pb_x[j] * pc_z[j] - fl2_fx * pb_xz[j] - 0.5 * pa_xyy[j] * fl1_fx * pc_z[j] - 0.5 * pa_xyy[j] * fl1_fx * pb_z[j] - pa_xy[j] * pc_y[j] * fl1_fx * pb_z[j] - 1.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_z[j] - fl1_fx * pa_yy[j] * pb_x[j] * pc_z[j] - 2.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xz[j] - fl1_fx * pa_yy[j] * pb_xz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_z[j] - pa_x[j] * fl1_fx * pb_xz[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxz[j] - pa_xyy[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xyy[j] * pb_xz[j] * pc_x[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xxz[j] - pc_x[j] * pa_yy[j] * pb_xxz[j]);

                t_xyy_xxz[j] += fl_s_0_0_2 * (0.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + fl2_fx * pb_x[j] * pc_z[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xyy[j] * fl1_fx * pc_z[j] + pa_xy[j] * pc_yz[j] * fl1_fx + pa_xy[j] * pc_y[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] + 1.5 * pc_xz[j] * pa_yy[j] * fl1_fx + 1.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_z[j] + 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] + 2.0 * fl1_fx * pa_y[j] * pc_yz[j] * pb_x[j] + fl1_fx * pc_yy[j] * pb_xz[j] + fl1_fx * pa_yy[j] * pb_x[j] * pc_z[j] + 2.0 * fl1_fx * pa_y[j] * pc_y[j] * pb_xz[j] + pa_x[j] * fl1_fx * pb_x[j] * pc_xz[j] + 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_z[j] + pa_x[j] * fl1_fx * pb_xz[j] * pc_x[j] + 0.5 * pc_xz[j] * fl1_fx * pb_xx[j] + pc_xx[j] * fl1_fx * pb_xz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_xyy[j] * pb_x[j] * pc_xz[j] + pa_xyy[j] * pc_xx[j] * pb_z[j] + 2.0 * pa_xy[j] * pc_yz[j] * pb_xx[j] + 4.0 * pa_xy[j] * pc_xy[j] * pb_xz[j] + pa_x[j] * pc_yy[j] * pb_xxz[j] + pc_xz[j] * pa_yy[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_yy[j] * pb_xz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xxz[j]);

                t_xyy_xxz[j] += fl_s_0_0_3 * (-0.25 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * fl2_fx * pb_x[j] * pc_z[j] - pa_xy[j] * pc_yz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yyz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] - 1.5 * pc_xz[j] * pa_yy[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx - 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] - fl1_fx * pc_yyz[j] * pb_x[j] - 2.0 * fl1_fx * pa_y[j] * pc_yz[j] * pb_x[j] - fl1_fx * pc_yy[j] * pb_xz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xxz[j] - pa_x[j] * fl1_fx * pb_x[j] * pc_xz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_z[j] - pc_xxz[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] - 0.5 * pc_xz[j] * fl1_fx * pb_xx[j] - pc_xx[j] * fl1_fx * pb_xz[j] - pa_xyy[j] * pc_xxz[j] - 4.0 * pa_xy[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xxy[j] * pb_z[j] - pa_x[j] * pc_yyz[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xyy[j] * pb_xz[j] - 2.0 * pc_xxz[j] * pa_yy[j] * pb_x[j] - pc_xxx[j] * pa_yy[j] * pb_z[j] - 2.0 * pc_xyz[j] * pa_y[j] * pb_xx[j] - 4.0 * pc_xxy[j] * pa_y[j] * pb_xz[j] - pc_xyy[j] * pb_xxz[j]);

                t_xyy_xxz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 0.5 * pa_x[j] * pc_yyz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_xyy[j] * fl1_fx * pb_z[j] + fl1_fx * pc_yyz[j] * pb_x[j] + 0.5 * pa_x[j] * fl1_fx * pc_xxz[j] + 0.5 * pc_xxxz[j] * fl1_fx + pc_xxz[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * pc_xxyz[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_x[j] + pa_x[j] * pc_xxyy[j] * pb_z[j] + pc_xxxz[j] * pa_yy[j] + 4.0 * pc_xxyz[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxxy[j] * pa_y[j] * pb_z[j] + pc_xyyz[j] * pb_xx[j] + 2.0 * pc_xxyy[j] * pb_xz[j]);

                t_xyy_xxz[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * pc_xxxz[j] * fl1_fx - pa_x[j] * pc_xxyyz[j] - 2.0 * pc_xxxyz[j] * pa_y[j] - 2.0 * pc_xxyyz[j] * pb_x[j] - pc_xxxyy[j] * pb_z[j]);

                t_xyy_xxz[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_xyy_xyy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_yy[j] + fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xyy[j] * pb_x[j] * fl1_fx + 2.0 * pa_xy[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_yy[j] * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pb_xyy[j] + pa_xyy[j] * pb_xyy[j]);

                t_xyy_xyy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pa_yy[j] - 1.5 * fl2_fx * pa_y[j] * pc_y[j] - 2.0 * fl2_fx * pa_y[j] * pb_y[j] - 1.5 * fl2_fx * pc_y[j] * pb_y[j] - 0.5 * fl2_fx * pb_yy[j] - 0.5 * pa_xyy[j] * pb_x[j] * fl1_fx - 0.5 * pa_xyy[j] * pc_x[j] * fl1_fx - 3.0 * pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx - 2.0 * pa_xy[j] * fl1_fx * pc_x[j] * pb_y[j] - 2.0 * pa_xy[j] * fl1_fx * pb_xy[j] - 3.0 * pa_x[j] * pc_y[j] * fl1_fx * pb_xy[j] - 0.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx - 2.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_xy[j] - fl1_fx * pa_yy[j] * pb_y[j] * pc_y[j] - fl1_fx * pa_y[j] * pc_y[j] * pb_yy[j] - 0.5 * fl1_fx * pa_yy[j] * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pb_xyy[j] - 0.5 * pc_x[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_xyy[j] * pb_xy[j] * pc_y[j] - pa_xyy[j] * pc_x[j] * pb_yy[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xyy[j] - pc_x[j] * pa_yy[j] * pb_xyy[j]);

                t_xyy_xyy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 1.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * pc_xx[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_x[j] + 3.0 * fl2_fx * pa_y[j] * pc_y[j] + 1.5 * fl2_fx * pc_yy[j] + 3.0 * fl2_fx * pc_y[j] * pb_y[j] + 0.25 * fl2_fx * pa_yy[j] + fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xyy[j] * pc_x[j] * fl1_fx + 3.0 * pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx + 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx + 2.0 * pa_xy[j] * fl1_fx * pc_x[j] * pb_y[j] + 3.0 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx + 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] + 3.0 * pa_x[j] * pc_y[j] * fl1_fx * pb_xy[j] + 0.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_yy[j] * fl1_fx + 3.0 * pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx + 2.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] + 2.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_xy[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_yy[j] * pc_yy[j] + 2.0 * fl1_fx * pa_y[j] * pc_yy[j] * pb_y[j] + 0.5 * fl1_fx * pc_yy[j] * pb_yy[j] + fl1_fx * pa_yy[j] * pb_y[j] * pc_y[j] + fl1_fx * pa_y[j] * pc_y[j] * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yy[j] + 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] + 0.5 * pc_x[j] * fl1_fx * pb_xyy[j] + pa_xyy[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xyy[j] * pc_xy[j] * pb_y[j] + 4.0 * pa_xy[j] * pc_yy[j] * pb_xy[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_yy[j] + pa_x[j] * pc_yy[j] * pb_xyy[j] + 2.0 * pc_xy[j] * pa_yy[j] * pb_xy[j] + pc_xx[j] * pa_yy[j] * pb_yy[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xyy[j]);

                t_xyy_xyy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 1.5 * pc_xx[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 3.0 * fl2_fx * pc_yy[j] - 1.5 * fl2_fx * pa_y[j] * pc_y[j] - 1.5 * fl2_fx * pc_y[j] * pb_y[j] - 3.0 * pa_xy[j] * pc_xy[j] * fl1_fx - 3.0 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * pc_xyy[j] * fl1_fx - 3.0 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xx[j] * pa_yy[j] * fl1_fx - 3.0 * pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxy[j] * pa_y[j] * fl1_fx - 2.0 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] - 3.0 * pc_xyy[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxy[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] - fl1_fx * pa_y[j] * pc_yyy[j] - fl1_fx * pc_yyy[j] * pb_y[j] - 0.5 * fl1_fx * pa_yy[j] * pc_yy[j] - 2.0 * fl1_fx * pa_y[j] * pc_yy[j] * pb_y[j] - 0.5 * fl1_fx * pc_yy[j] * pb_yy[j] - 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] - pa_xyy[j] * pc_xyy[j] - 2.0 * pa_xy[j] * pc_yyy[j] * pb_x[j] - 4.0 * pa_xy[j] * pc_xyy[j] * pb_y[j] - 2.0 * pa_x[j] * pc_yyy[j] * pb_xy[j] - pa_x[j] * pc_xyy[j] * pb_yy[j] - pc_xyy[j] * pa_yy[j] * pb_x[j] - 2.0 * pc_xxy[j] * pa_yy[j] * pb_y[j] - 4.0 * pc_xyy[j] * pa_y[j] * pb_xy[j] - 2.0 * pc_xxy[j] * pa_y[j] * pb_yy[j] - pc_xyy[j] * pb_xyy[j]);

                t_xyy_xyy[j] += fl_s_0_0_4 * (0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pc_yy[j] + 3.0 * pa_x[j] * pc_xyy[j] * fl1_fx + 3.0 * pc_xxy[j] * pa_y[j] * fl1_fx + 3.0 * pc_xyy[j] * pb_x[j] * fl1_fx + 3.0 * pc_xxyy[j] * fl1_fx + 3.0 * pc_xxy[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyyy[j] + fl1_fx * pa_y[j] * pc_yyy[j] + fl1_fx * pc_yyy[j] * pb_y[j] + 2.0 * pa_xy[j] * pc_xyyy[j] + pa_x[j] * pc_yyyy[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xyyy[j] * pb_y[j] + pc_xxyy[j] * pa_yy[j] + 2.0 * pc_xyyy[j] * pa_y[j] * pb_x[j] + 4.0 * pc_xxyy[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xyyy[j] * pb_xy[j] + pc_xxyy[j] * pb_yy[j]);

                t_xyy_xyy[j] += fl_s_0_0_5 * (-3.0 * pc_xxyy[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyy[j] - pa_x[j] * pc_xyyyy[j] - 2.0 * pc_xxyyy[j] * pa_y[j] - pc_xyyyy[j] * pb_x[j] - 2.0 * pc_xxyyy[j] * pb_y[j]);

                t_xyy_xyy[j] += fl_s_0_0_6 * pc_xxyyyy[j];

                t_xyy_xyz[j] = fl_s_0_0_0 * (0.5 * fl2_fx * pa_y[j] * pb_z[j] + 0.25 * fl2_fx * pb_yz[j] + pa_xy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yy[j] * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xyz[j] + pa_xyy[j] * pb_xyz[j]);

                t_xyy_xyz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_y[j] * pc_z[j] - fl2_fx * pa_y[j] * pb_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 0.25 * fl2_fx * pb_y[j] * pc_z[j] - 0.5 * fl2_fx * pb_yz[j] - pa_xy[j] * fl1_fx * pb_x[j] * pc_z[j] - pa_xy[j] * fl1_fx * pc_x[j] * pb_z[j] - pa_xy[j] * fl1_fx * pb_xz[j] - 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xz[j] - pc_x[j] * pa_y[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pa_yy[j] * pb_y[j] * pc_z[j] - 0.5 * fl1_fx * pa_yy[j] * pc_y[j] * pb_z[j] - fl1_fx * pa_y[j] * pc_y[j] * pb_yz[j] - 0.5 * fl1_fx * pa_yy[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xy[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xyz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xyz[j] - pa_xyy[j] * pb_xy[j] * pc_z[j] - pa_xyy[j] * pb_xz[j] * pc_y[j] - pa_xyy[j] * pc_x[j] * pb_yz[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xyz[j] - pc_x[j] * pa_yy[j] * pb_xyz[j]);

                t_xyy_xyz[j] += fl_s_0_0_2 * (fl2_fx * pa_y[j] * pc_z[j] + 0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pc_y[j] * pb_z[j] + 0.5 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * fl2_fx * pb_y[j] * pc_z[j] + 0.25 * fl2_fx * pb_yz[j] + pa_xy[j] * fl1_fx * pc_xz[j] + pa_xy[j] * fl1_fx * pb_x[j] * pc_z[j] + pa_xy[j] * fl1_fx * pc_x[j] * pb_z[j] + 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_x[j] + 1.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xz[j] + pc_xz[j] * pa_y[j] * fl1_fx * pb_x[j] + pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_x[j] * pa_y[j] * fl1_fx * pb_xz[j] + 1.5 * pc_xy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yy[j] * pc_yz[j] + fl1_fx * pa_y[j] * pc_yz[j] * pb_y[j] + fl1_fx * pa_y[j] * pc_yy[j] * pb_z[j] + 0.5 * fl1_fx * pc_yy[j] * pb_yz[j] + 0.5 * fl1_fx * pa_yy[j] * pb_y[j] * pc_z[j] + 0.5 * fl1_fx * pa_yy[j] * pc_y[j] * pb_z[j] + fl1_fx * pa_y[j] * pc_y[j] * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pc_xz[j] * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xy[j] * pc_z[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yz[j] + 0.5 * pc_xz[j] * fl1_fx * pb_xy[j] + 0.5 * pc_xx[j] * fl1_fx * pb_yz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xyz[j] + pa_xyy[j] * pb_x[j] * pc_yz[j] + pa_xyy[j] * pc_xz[j] * pb_y[j] + pa_xyy[j] * pc_xy[j] * pb_z[j] + 2.0 * pa_xy[j] * pc_yz[j] * pb_xy[j] + 2.0 * pa_xy[j] * pc_yy[j] * pb_xz[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_yz[j] + pa_x[j] * pc_yy[j] * pb_xyz[j] + pc_xz[j] * pa_yy[j] * pb_xy[j] + pc_xy[j] * pa_yy[j] * pb_xz[j] + pc_xx[j] * pa_yy[j] * pb_yz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xyz[j]);

                t_xyy_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.5 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pb_z[j] - 0.25 * fl2_fx * pb_y[j] * pc_z[j] - pa_xy[j] * fl1_fx * pc_xz[j] - 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_x[j] - 1.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - pc_xxz[j] * pa_y[j] * fl1_fx - pc_xz[j] * pa_y[j] * fl1_fx * pb_x[j] - pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] - 1.5 * pc_xy[j] * fl1_fx * pb_xz[j] - fl1_fx * pa_y[j] * pc_yyz[j] - 0.5 * fl1_fx * pc_yyz[j] * pb_y[j] - 0.5 * fl1_fx * pc_yyy[j] * pb_z[j] - 0.5 * fl1_fx * pa_yy[j] * pc_yz[j] - fl1_fx * pa_y[j] * pc_yz[j] * pb_y[j] - fl1_fx * pa_y[j] * pc_yy[j] * pb_z[j] - 0.5 * fl1_fx * pc_yy[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xz[j] * pb_y[j] - 0.5 * pc_xxz[j] * fl1_fx * pb_y[j] - 0.5 * pc_xz[j] * fl1_fx * pb_xy[j] - 0.5 * pc_xx[j] * fl1_fx * pb_yz[j] - pa_xyy[j] * pc_xyz[j] - 2.0 * pa_xy[j] * pc_yyz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_xyy[j] * pb_z[j] - pa_x[j] * pc_yyz[j] * pb_xy[j] - pa_x[j] * pc_yyy[j] * pb_xz[j] - pa_x[j] * pc_xyy[j] * pb_yz[j] - pc_xyz[j] * pa_yy[j] * pb_x[j] - pc_xxz[j] * pa_yy[j] * pb_y[j] - pc_xxy[j] * pa_yy[j] * pb_z[j] - 2.0 * pc_xyz[j] * pa_y[j] * pb_xy[j] - 2.0 * pc_xyy[j] * pa_y[j] * pb_xz[j] - 2.0 * pc_xxy[j] * pa_y[j] * pb_yz[j] - pc_xyy[j] * pb_xyz[j]);

                t_xyy_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx + pc_xxz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yyyz[j] + fl1_fx * pa_y[j] * pc_yyz[j] + 0.5 * fl1_fx * pc_yyz[j] * pb_y[j] + 0.5 * fl1_fx * pc_yyy[j] * pb_z[j] + 0.5 * pc_xxz[j] * fl1_fx * pb_y[j] + 2.0 * pa_xy[j] * pc_xyyz[j] + pa_x[j] * pc_yyyz[j] * pb_x[j] + pa_x[j] * pc_xyyz[j] * pb_y[j] + pa_x[j] * pc_xyyy[j] * pb_z[j] + pc_xxyz[j] * pa_yy[j] + 2.0 * pc_xyyz[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxyz[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xxyy[j] * pa_y[j] * pb_z[j] + pc_xyyz[j] * pb_xy[j] + pc_xyyy[j] * pb_xz[j] + pc_xxyy[j] * pb_yz[j]);

                t_xyy_xyz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyz[j] - pa_x[j] * pc_xyyyz[j] - 2.0 * pc_xxyyz[j] * pa_y[j] - pc_xyyyz[j] * pb_x[j] - pc_xxyyz[j] * pb_y[j] - pc_xxyyy[j] * pb_z[j]);

                t_xyy_xyz[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_xyy_xzz[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * fl2_fx * pa_yy[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xyy[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_yy[j] * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xzz[j] + pa_xyy[j] * pb_xzz[j]);

                t_xyy_xzz[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * fl2_fx * pa_yy[j] - 0.5 * fl2_fx * pa_y[j] * pc_y[j] - 0.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pb_z[j] * pc_z[j] - 0.5 * fl2_fx * pb_zz[j] - 0.5 * pa_xyy[j] * pb_x[j] * fl1_fx - 0.5 * pa_xyy[j] * pc_x[j] * fl1_fx - pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx - 0.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx - fl1_fx * pa_yy[j] * pb_z[j] * pc_z[j] - fl1_fx * pa_y[j] * pc_y[j] * pb_zz[j] - 0.5 * fl1_fx * pa_yy[j] * pb_zz[j] - pa_x[j] * fl1_fx * pb_xz[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_xyy[j] * pb_xz[j] * pc_z[j] - pa_xyy[j] * pc_x[j] * pb_zz[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_xzz[j] - pc_x[j] * pa_yy[j] * pb_xzz[j]);

                t_xyy_xzz[j] += fl_s_0_0_2 * (0.375 * fl3_fx + fl2_fx * pa_y[j] * pc_y[j] + 0.25 * fl2_fx * pc_yy[j] + 0.25 * fl2_fx * pa_yy[j] + 0.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.5 * pc_x[j] * fl2_fx * pb_x[j] + 0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_zz[j] + fl2_fx * pb_z[j] * pc_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xyy[j] * pc_x[j] * fl1_fx + pa_xy[j] * pc_y[j] * pb_x[j] * fl1_fx + pa_xy[j] * pc_xy[j] * fl1_fx + 0.5 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx + 0.5 * pc_x[j] * pa_yy[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_yy[j] * fl1_fx + pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_yy[j] * pc_zz[j] + 2.0 * fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] + 0.5 * fl1_fx * pc_yy[j] * pb_zz[j] + fl1_fx * pa_yy[j] * pb_z[j] * pc_z[j] + fl1_fx * pa_y[j] * pc_y[j] * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_zz[j] + pa_x[j] * fl1_fx * pc_xz[j] * pb_z[j] + pa_x[j] * fl1_fx * pb_xz[j] * pc_z[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_zz[j] + pc_xz[j] * fl1_fx * pb_xz[j] + 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xzz[j] + pa_xyy[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xyy[j] * pc_xz[j] * pb_z[j] + 4.0 * pa_xy[j] * pc_yz[j] * pb_xz[j] + 2.0 * pa_xy[j] * pc_xy[j] * pb_zz[j] + pa_x[j] * pc_yy[j] * pb_xzz[j] + 2.0 * pc_xz[j] * pa_yy[j] * pb_xz[j] + pc_xx[j] * pa_yy[j] * pb_zz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_xzz[j]);

                t_xyy_xzz[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * fl2_fx * pc_yy[j] - 0.5 * fl2_fx * pa_y[j] * pc_y[j] - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.5 * pc_xx[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pc_zz[j] - 0.5 * fl2_fx * pb_z[j] * pc_z[j] - pa_xy[j] * pc_xy[j] * fl1_fx - 0.5 * pa_x[j] * pc_yy[j] * pb_x[j] * fl1_fx - 0.5 * pa_x[j] * pc_xyy[j] * fl1_fx - 0.5 * pc_xx[j] * pa_yy[j] * fl1_fx - pc_xy[j] * pa_y[j] * pb_x[j] * fl1_fx - pc_xxy[j] * pa_y[j] * fl1_fx - 0.5 * pc_xyy[j] * pb_x[j] * fl1_fx - fl1_fx * pa_y[j] * pc_yzz[j] - fl1_fx * pc_yyz[j] * pb_z[j] - 0.5 * fl1_fx * pa_yy[j] * pc_zz[j] - 2.0 * fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] - 0.5 * fl1_fx * pc_yy[j] * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xzz[j] - 0.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_zz[j] - pa_x[j] * fl1_fx * pc_xz[j] * pb_z[j] - 0.5 * pc_xzz[j] * fl1_fx * pb_x[j] - pc_xxz[j] * fl1_fx * pb_z[j] - pc_xz[j] * fl1_fx * pb_xz[j] - 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] - pa_xyy[j] * pc_xzz[j] - 2.0 * pa_xy[j] * pc_yzz[j] * pb_x[j] - 4.0 * pa_xy[j] * pc_xyz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_yyz[j] * pb_xz[j] - pa_x[j] * pc_xyy[j] * pb_zz[j] - pc_xzz[j] * pa_yy[j] * pb_x[j] - 2.0 * pc_xxz[j] * pa_yy[j] * pb_z[j] - 4.0 * pc_xyz[j] * pa_y[j] * pb_xz[j] - 2.0 * pc_xxy[j] * pa_y[j] * pb_zz[j] - pc_xyy[j] * pb_xzz[j]);

                t_xyy_xzz[j] += fl_s_0_0_4 * (0.25 * fl2_fx * pc_yy[j] + 0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_zz[j] + 0.5 * pa_x[j] * pc_xyy[j] * fl1_fx + pc_xxy[j] * pa_y[j] * fl1_fx + 0.5 * pc_xyy[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxyy[j] * fl1_fx + 0.5 * fl1_fx * pc_yyzz[j] + fl1_fx * pa_y[j] * pc_yzz[j] + fl1_fx * pc_yyz[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pc_xzz[j] + 0.5 * pc_xxzz[j] * fl1_fx + 0.5 * pc_xzz[j] * fl1_fx * pb_x[j] + pc_xxz[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * pc_xyzz[j] + pa_x[j] * pc_yyzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_z[j] + pc_xxzz[j] * pa_yy[j] + 2.0 * pc_xyzz[j] * pa_y[j] * pb_x[j] + 4.0 * pc_xxyz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xyyz[j] * pb_xz[j] + pc_xxyy[j] * pb_zz[j]);

                t_xyy_xzz[j] += fl_s_0_0_5 * (-0.5 * pc_xxyy[j] * fl1_fx - 0.5 * fl1_fx * pc_yyzz[j] - 0.5 * pc_xxzz[j] * fl1_fx - pa_x[j] * pc_xyyzz[j] - 2.0 * pc_xxyzz[j] * pa_y[j] - pc_xyyzz[j] * pb_x[j] - 2.0 * pc_xxyyz[j] * pb_z[j]);

                t_xyy_xzz[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_xyy_yyy[j] = fl_s_0_0_0 * (1.5 * pa_xy[j] * fl2_fx + 2.25 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xyy[j] * pb_y[j] * fl1_fx + 3.0 * pa_xy[j] * fl1_fx * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pb_yyy[j] + pa_xyy[j] * pb_yyy[j]);

                t_xyy_yyy[j] += fl_s_0_0_1 * (-3.0 * pa_xy[j] * fl2_fx - 3.75 * pa_x[j] * pc_y[j] * fl2_fx - 4.5 * pa_x[j] * fl2_fx * pb_y[j] - 1.5 * pc_x[j] * pa_y[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * pa_xyy[j] * pb_y[j] * fl1_fx - 1.5 * pa_xyy[j] * pc_y[j] * fl1_fx - 9.0 * pa_xy[j] * pc_y[j] * pb_y[j] * fl1_fx - 3.0 * pa_xy[j] * fl1_fx * pb_yy[j] - 4.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_yy[j] - 1.5 * pc_x[j] * pa_yy[j] * pb_y[j] * fl1_fx - 3.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pb_yyy[j] - 0.5 * pc_x[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_xyy[j] * pb_yy[j] * pc_y[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_yyy[j] - pc_x[j] * pa_yy[j] * pb_yyy[j]);

                t_xyy_yyy[j] += fl_s_0_0_2 * (1.5 * pa_xy[j] * fl2_fx + 7.5 * pa_x[j] * pc_y[j] * fl2_fx + 2.25 * pa_x[j] * fl2_fx * pb_y[j] + 3.0 * pc_x[j] * pa_y[j] * fl2_fx + 3.75 * pc_xy[j] * fl2_fx + 4.5 * pc_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xyy[j] * pc_y[j] * fl1_fx + 9.0 * pa_xy[j] * pc_y[j] * pb_y[j] * fl1_fx + 6.0 * pa_xy[j] * pc_yy[j] * fl1_fx + 9.0 * pa_x[j] * pc_yy[j] * pb_y[j] * fl1_fx + 4.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_yy[j] + 1.5 * pc_x[j] * pa_yy[j] * pb_y[j] * fl1_fx + 1.5 * pc_xy[j] * pa_yy[j] * fl1_fx + 9.0 * pc_xy[j] * pa_y[j] * pb_y[j] * fl1_fx + 3.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_yy[j] + 4.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 0.5 * pc_x[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_xyy[j] * pb_y[j] * pc_yy[j] + 6.0 * pa_xy[j] * pc_yy[j] * pb_yy[j] + pa_x[j] * pc_yy[j] * pb_yyy[j] + 3.0 * pc_xy[j] * pa_yy[j] * pb_yy[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_yyy[j]);

                t_xyy_yyy[j] += fl_s_0_0_3 * (-3.75 * pa_x[j] * pc_y[j] * fl2_fx - 1.5 * pc_x[j] * pa_y[j] * fl2_fx - 7.5 * pc_xy[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_y[j] - 6.0 * pa_xy[j] * pc_yy[j] * fl1_fx - 9.0 * pa_x[j] * pc_yy[j] * pb_y[j] * fl1_fx - 5.0 * pa_x[j] * pc_yyy[j] * fl1_fx - 1.5 * pc_xy[j] * pa_yy[j] * fl1_fx - 9.0 * pc_xy[j] * pa_y[j] * pb_y[j] * fl1_fx - 6.0 * pc_xyy[j] * pa_y[j] * fl1_fx - 9.0 * pc_xyy[j] * pb_y[j] * fl1_fx - 4.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pa_xyy[j] * pc_yyy[j] - 6.0 * pa_xy[j] * pc_yyy[j] * pb_y[j] - 3.0 * pa_x[j] * pc_yyy[j] * pb_yy[j] - 3.0 * pc_xyy[j] * pa_yy[j] * pb_y[j] - 6.0 * pc_xyy[j] * pa_y[j] * pb_yy[j] - pc_xyy[j] * pb_yyy[j]);

                t_xyy_yyy[j] += fl_s_0_0_4 * (3.75 * pc_xy[j] * fl2_fx + 5.0 * pa_x[j] * pc_yyy[j] * fl1_fx + 6.0 * pc_xyy[j] * pa_y[j] * fl1_fx + 9.0 * pc_xyy[j] * pb_y[j] * fl1_fx + 5.0 * pc_xyyy[j] * fl1_fx + 2.0 * pa_xy[j] * pc_yyyy[j] + 3.0 * pa_x[j] * pc_yyyy[j] * pb_y[j] + pc_xyyy[j] * pa_yy[j] + 6.0 * pc_xyyy[j] * pa_y[j] * pb_y[j] + 3.0 * pc_xyyy[j] * pb_yy[j]);

                t_xyy_yyy[j] += fl_s_0_0_5 * (-5.0 * pc_xyyy[j] * fl1_fx - pa_x[j] * pc_yyyyy[j] - 2.0 * pc_xyyyy[j] * pa_y[j] - 3.0 * pc_xyyyy[j] * pb_y[j]);

                t_xyy_yyy[j] += fl_s_0_0_6 * pc_xyyyyy[j];

                t_xyy_yyz[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xyy[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_yyz[j] + pa_xyy[j] * pb_yyz[j]);

                t_xyy_yyz[j] += fl_s_0_0_1 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * pa_xyy[j] * fl1_fx * pc_z[j] - 0.5 * pa_xyy[j] * fl1_fx * pb_z[j] - 3.0 * pa_xy[j] * pc_y[j] * fl1_fx * pb_z[j] - 2.0 * pa_xy[j] * fl1_fx * pb_y[j] * pc_z[j] - 2.0 * pa_xy[j] * fl1_fx * pb_yz[j] - 3.0 * pa_x[j] * pc_y[j] * fl1_fx * pb_yz[j] - 0.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_z[j] - 2.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pb_yyz[j] - 0.5 * pc_x[j] * fl1_fx * pb_yyz[j] - pa_xyy[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xyy[j] * pb_yz[j] * pc_y[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_yyz[j] - pc_x[j] * pa_yy[j] * pb_yyz[j]);

                t_xyy_yyz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.75 * pa_x[j] * fl2_fx * pb_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xyy[j] * fl1_fx * pc_z[j] + 3.0 * pa_xy[j] * pc_yz[j] * fl1_fx + 3.0 * pa_xy[j] * pc_y[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * fl1_fx * pb_y[j] * pc_z[j] + 3.0 * pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] + 3.0 * pa_x[j] * pc_y[j] * fl1_fx * pb_yz[j] + 0.5 * pc_xz[j] * pa_yy[j] * fl1_fx + 0.5 * pc_x[j] * pa_yy[j] * fl1_fx * pb_z[j] + 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] + 2.0 * pc_xz[j] * pa_y[j] * fl1_fx * pb_y[j] + 2.0 * pc_x[j] * pa_y[j] * fl1_fx * pb_yz[j] + 3.0 * pc_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_z[j] + 0.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 0.5 * pc_x[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_xyy[j] * pb_y[j] * pc_yz[j] + pa_xyy[j] * pc_yy[j] * pb_z[j] + 2.0 * pa_xy[j] * pc_yz[j] * pb_yy[j] + 4.0 * pa_xy[j] * pc_yy[j] * pb_yz[j] + pa_x[j] * pc_yy[j] * pb_yyz[j] + pc_xz[j] * pa_yy[j] * pb_yy[j] + 2.0 * pc_xy[j] * pa_yy[j] * pb_yz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_yyz[j]);

                t_xyy_yyz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 3.0 * pa_xy[j] * pc_yz[j] * fl1_fx - 3.0 * pa_x[j] * pc_yyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] - 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] - 0.5 * pc_xz[j] * pa_yy[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx - 3.0 * pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] - 2.0 * pc_xz[j] * pa_y[j] * fl1_fx * pb_y[j] - 3.0 * pc_xyy[j] * fl1_fx * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pb_yz[j] - 0.5 * pc_xz[j] * fl1_fx * pb_yy[j] - pa_xyy[j] * pc_yyz[j] - 4.0 * pa_xy[j] * pc_yyz[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_yyy[j] * pb_z[j] - pa_x[j] * pc_yyz[j] * pb_yy[j] - 2.0 * pa_x[j] * pc_yyy[j] * pb_yz[j] - 2.0 * pc_xyz[j] * pa_yy[j] * pb_y[j] - pc_xyy[j] * pa_yy[j] * pb_z[j] - 2.0 * pc_xyz[j] * pa_y[j] * pb_yy[j] - 4.0 * pc_xyy[j] * pa_y[j] * pb_yz[j] - pc_xyy[j] * pb_yyz[j]);

                t_xyy_yyz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 3.0 * pa_x[j] * pc_yyz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx + 3.0 * pc_xyyz[j] * fl1_fx + 3.0 * pc_xyy[j] * fl1_fx * pb_z[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + 2.0 * pa_xy[j] * pc_yyyz[j] + 2.0 * pa_x[j] * pc_yyyz[j] * pb_y[j] + pa_x[j] * pc_yyyy[j] * pb_z[j] + pc_xyyz[j] * pa_yy[j] + 4.0 * pc_xyyz[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xyyy[j] * pa_y[j] * pb_z[j] + pc_xyyz[j] * pb_yy[j] + 2.0 * pc_xyyy[j] * pb_yz[j]);

                t_xyy_yyz[j] += fl_s_0_0_5 * (-3.0 * pc_xyyz[j] * fl1_fx - pa_x[j] * pc_yyyyz[j] - 2.0 * pc_xyyyz[j] * pa_y[j] - 2.0 * pc_xyyyz[j] * pb_y[j] - pc_xyyyy[j] * pb_z[j]);

                t_xyy_yyz[j] += fl_s_0_0_6 * pc_xyyyyz[j];

                t_xyy_yzz[j] = fl_s_0_0_0 * (0.5 * pa_xy[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyy[j] * pb_y[j] * fl1_fx + pa_xy[j] * fl1_fx * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_yzz[j] + pa_xyy[j] * pb_yzz[j]);

                t_xyy_yzz[j] += fl_s_0_0_1 * (-pa_xy[j] * fl2_fx - 0.75 * pa_x[j] * pc_y[j] * fl2_fx - 0.5 * pc_x[j] * pa_y[j] * fl2_fx - 0.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.25 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * pa_xyy[j] * pb_y[j] * fl1_fx - 0.5 * pa_xyy[j] * pc_y[j] * fl1_fx - pa_xy[j] * pc_y[j] * pb_y[j] * fl1_fx - 2.0 * pa_xy[j] * fl1_fx * pb_z[j] * pc_z[j] - pa_xy[j] * fl1_fx * pb_zz[j] - 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_zz[j] - 0.5 * pc_x[j] * pa_yy[j] * pb_y[j] * fl1_fx - pc_x[j] * pa_y[j] * fl1_fx * pb_zz[j] - pa_x[j] * fl1_fx * pb_yz[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pb_yzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_xyy[j] * pb_yz[j] * pc_z[j] - pa_xyy[j] * pc_y[j] * pb_zz[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_yzz[j] - pc_x[j] * pa_yy[j] * pb_yzz[j]);

                t_xyy_yzz[j] += fl_s_0_0_2 * (0.5 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_y[j] * fl2_fx + pc_x[j] * pa_y[j] * fl2_fx + 0.75 * pc_xy[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyy[j] * pc_y[j] * fl1_fx + pa_xy[j] * pc_y[j] * pb_y[j] * fl1_fx + pa_xy[j] * pc_yy[j] * fl1_fx + pa_xy[j] * fl1_fx * pc_zz[j] + 2.0 * pa_xy[j] * fl1_fx * pb_z[j] * pc_z[j] + 0.5 * pa_x[j] * pc_yy[j] * pb_y[j] * fl1_fx + 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * pa_yy[j] * pb_y[j] * fl1_fx + 0.5 * pc_xy[j] * pa_yy[j] * fl1_fx + pc_xy[j] * pa_y[j] * pb_y[j] * fl1_fx + 2.0 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_x[j] * pa_y[j] * fl1_fx * pb_zz[j] + 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_zz[j] + pa_x[j] * fl1_fx * pb_yz[j] * pc_z[j] + pc_xz[j] * fl1_fx * pb_yz[j] + 0.5 * pc_x[j] * fl1_fx * pb_yzz[j] + pa_xyy[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xyy[j] * pc_yz[j] * pb_z[j] + 4.0 * pa_xy[j] * pc_yz[j] * pb_yz[j] + 2.0 * pa_xy[j] * pc_yy[j] * pb_zz[j] + pa_x[j] * pc_yy[j] * pb_yzz[j] + 2.0 * pc_xz[j] * pa_yy[j] * pb_yz[j] + pc_xy[j] * pa_yy[j] * pb_zz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_yzz[j]);

                t_xyy_yzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_y[j] * fl2_fx - 0.5 * pc_x[j] * pa_y[j] * fl2_fx - 1.5 * pc_xy[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pb_y[j] - pa_xy[j] * pc_yy[j] * fl1_fx - pa_xy[j] * fl1_fx * pc_zz[j] - 0.5 * pa_x[j] * pc_yy[j] * pb_y[j] * fl1_fx - 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * pa_yy[j] * fl1_fx - pc_xy[j] * pa_y[j] * pb_y[j] * fl1_fx - pc_xyy[j] * pa_y[j] * fl1_fx - pc_xzz[j] * pa_y[j] * fl1_fx - 2.0 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] - 0.5 * pc_xyy[j] * pb_y[j] * fl1_fx - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_zz[j] - 0.5 * pc_xzz[j] * fl1_fx * pb_y[j] - pc_xz[j] * fl1_fx * pb_yz[j] - pa_xyy[j] * pc_yzz[j] - 2.0 * pa_xy[j] * pc_yzz[j] * pb_y[j] - 4.0 * pa_xy[j] * pc_yyz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_yyz[j] * pb_yz[j] - pa_x[j] * pc_yyy[j] * pb_zz[j] - pc_xzz[j] * pa_yy[j] * pb_y[j] - 2.0 * pc_xyz[j] * pa_yy[j] * pb_z[j] - 4.0 * pc_xyz[j] * pa_y[j] * pb_yz[j] - 2.0 * pc_xyy[j] * pa_y[j] * pb_zz[j] - pc_xyy[j] * pb_yzz[j]);

                t_xyy_yzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx + pc_xyy[j] * pa_y[j] * fl1_fx + pc_xzz[j] * pa_y[j] * fl1_fx + 0.5 * pc_xyy[j] * pb_y[j] * fl1_fx + 0.5 * pc_xyyy[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xzz[j] * fl1_fx * pb_y[j] + 2.0 * pa_xy[j] * pc_yyzz[j] + pa_x[j] * pc_yyzz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_yyyz[j] * pb_z[j] + pc_xyzz[j] * pa_yy[j] + 2.0 * pc_xyzz[j] * pa_y[j] * pb_y[j] + 4.0 * pc_xyyz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xyyz[j] * pb_yz[j] + pc_xyyy[j] * pb_zz[j]);

                t_xyy_yzz[j] += fl_s_0_0_5 * (-0.5 * pc_xyyy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - pa_x[j] * pc_yyyzz[j] - 2.0 * pc_xyyzz[j] * pa_y[j] - pc_xyyzz[j] * pb_y[j] - 2.0 * pc_xyyyz[j] * pb_z[j]);

                t_xyy_yzz[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_xyy_zzz[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xyy[j] * pb_z[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_zzz[j] + pa_xyy[j] * pb_zzz[j]);

                t_xyy_zzz[j] += fl_s_0_0_1 * (-1.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pa_x[j] * fl2_fx * pc_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * pa_xyy[j] * pb_z[j] * fl1_fx - 1.5 * pa_xyy[j] * pc_z[j] * fl1_fx - 3.0 * pa_xy[j] * pc_y[j] * pb_z[j] * fl1_fx - 1.5 * pc_x[j] * pa_yy[j] * pb_z[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pb_zz[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pb_zzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_xyy[j] * pb_zz[j] * pc_z[j] - 2.0 * pa_xy[j] * pc_y[j] * pb_zzz[j] - pc_x[j] * pa_yy[j] * pb_zzz[j]);

                t_xyy_zzz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.75 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_xyy[j] * pc_z[j] * fl1_fx + 3.0 * pa_xy[j] * pc_y[j] * pb_z[j] * fl1_fx + 3.0 * pa_xy[j] * pc_yz[j] * fl1_fx + 1.5 * pa_x[j] * pc_yy[j] * pb_z[j] * fl1_fx + 1.5 * pc_x[j] * pa_yy[j] * pb_z[j] * fl1_fx + 1.5 * pc_xz[j] * pa_yy[j] * fl1_fx + 3.0 * pc_xy[j] * pa_y[j] * pb_z[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_z[j] * pc_zz[j] + 1.5 * pa_x[j] * fl1_fx * pb_zz[j] * pc_z[j] + 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_xyy[j] * pb_z[j] * pc_zz[j] + 6.0 * pa_xy[j] * pc_yz[j] * pb_zz[j] + pa_x[j] * pc_yy[j] * pb_zzz[j] + 3.0 * pc_xz[j] * pa_yy[j] * pb_zz[j] + 2.0 * pc_xy[j] * pa_y[j] * pb_zzz[j]);

                t_xyy_zzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - 3.0 * pa_xy[j] * pc_yz[j] * fl1_fx - 1.5 * pa_x[j] * pc_yy[j] * pb_z[j] * fl1_fx - 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_yy[j] * fl1_fx - 3.0 * pc_xy[j] * pa_y[j] * pb_z[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xyy[j] * pb_z[j] * fl1_fx - 0.5 * pa_x[j] * fl1_fx * pc_zzz[j] - 1.5 * pa_x[j] * fl1_fx * pb_z[j] * pc_zz[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_z[j] - 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] - pa_xyy[j] * pc_zzz[j] - 6.0 * pa_xy[j] * pc_yzz[j] * pb_z[j] - 3.0 * pa_x[j] * pc_yyz[j] * pb_zz[j] - 3.0 * pc_xzz[j] * pa_yy[j] * pb_z[j] - 6.0 * pc_xyz[j] * pa_y[j] * pb_zz[j] - pc_xyy[j] * pb_zzz[j]);

                t_xyy_zzz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyy[j] * pb_z[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_zzz[j] + 0.5 * pc_xzzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pb_z[j] + 2.0 * pa_xy[j] * pc_yzzz[j] + 3.0 * pa_x[j] * pc_yyzz[j] * pb_z[j] + pc_xzzz[j] * pa_yy[j] + 6.0 * pc_xyzz[j] * pa_y[j] * pb_z[j] + 3.0 * pc_xyyz[j] * pb_zz[j]);

                t_xyy_zzz[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * pc_xzzz[j] * fl1_fx - pa_x[j] * pc_yyzzz[j] - 2.0 * pc_xyzzz[j] * pa_y[j] - 3.0 * pc_xyyzz[j] * pb_z[j]);

                t_xyy_zzz[j] += fl_s_0_0_6 * pc_xyyzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_40_50(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (40,50)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(19 * idx + 4);

            auto pa_xz = paDistances.data(19 * idx + 5);

            auto pa_yz = paDistances.data(19 * idx + 7);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xyz = paDistances.data(19 * idx + 13);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxy = pcDistances.data(83 * idx + 35);

            auto pc_xxxxz = pcDistances.data(83 * idx + 36);

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyyy = pcDistances.data(83 * idx + 44);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_xzzzz = pcDistances.data(83 * idx + 48);

            auto pc_yyyyz = pcDistances.data(83 * idx + 50);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            auto pc_yzzzz = pcDistances.data(83 * idx + 53);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxyz = pcDistances.data(83 * idx + 59);

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            auto pc_xyyyyz = pcDistances.data(83 * idx + 71);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            auto pc_xyzzzz = pcDistances.data(83 * idx + 74);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xyz_xxx = primBuffer.data(100 * idx + 40);

            auto t_xyz_xxy = primBuffer.data(100 * idx + 41);

            auto t_xyz_xxz = primBuffer.data(100 * idx + 42);

            auto t_xyz_xyy = primBuffer.data(100 * idx + 43);

            auto t_xyz_xyz = primBuffer.data(100 * idx + 44);

            auto t_xyz_xzz = primBuffer.data(100 * idx + 45);

            auto t_xyz_yyy = primBuffer.data(100 * idx + 46);

            auto t_xyz_yyz = primBuffer.data(100 * idx + 47);

            auto t_xyz_yzz = primBuffer.data(100 * idx + 48);

            auto t_xyz_zzz = primBuffer.data(100 * idx + 49);

            // Batch of Integrals (40,50)

            #pragma omp simd aligned(fx, pa_x, pa_xy, pa_xyz, pa_xz, pa_y, pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxy, \
                                     pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, \
                                     pb_z, pb_zz, pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxy, pc_xxxxyz, pc_xxxxz, \
                                     pc_xxxy, pc_xxxyy, pc_xxxyyz, pc_xxxyz, pc_xxxyzz, pc_xxxz, pc_xxxzz, pc_xxy, \
                                     pc_xxyy, pc_xxyyy, pc_xxyyyz, pc_xxyyz, pc_xxyyzz, pc_xxyz, pc_xxyzz, pc_xxyzzz, \
                                     pc_xxz, pc_xxzz, pc_xxzzz, pc_xy, pc_xyy, pc_xyyy, pc_xyyyy, pc_xyyyyz, pc_xyyyz, \
                                     pc_xyyyzz, pc_xyyz, pc_xyyzz, pc_xyyzzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xyzzzz, pc_xz, \
                                     pc_xzz, pc_xzzz, pc_xzzzz, pc_y, pc_yy, pc_yyy, pc_yyyy, pc_yyyyz, pc_yyyz, pc_yyyzz, \
                                     pc_yyz, pc_yyzz, pc_yyzzz, pc_yz, pc_yzz, pc_yzzz, pc_yzzzz, pc_z, pc_zz, pc_zzz, \
                                     pc_zzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, s_0_0_5, s_0_0_6, t_xyz_xxx, \
                                     t_xyz_xxy, t_xyz_xxz, t_xyz_xyy, t_xyz_xyz, t_xyz_xzz, t_xyz_yyy, t_xyz_yyz, \
                                     t_xyz_yzz, t_xyz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xyz_xxx[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_yz[j] + 1.5 * pa_xyz[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_yz[j] * pb_xx[j] + pa_xyz[j] * pb_xxx[j]);

                t_xyz_xxx[j] += fl_s_0_0_1 * (-1.5 * fl2_fx * pa_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pa_z[j] - 1.5 * pa_xyz[j] * pb_x[j] * fl1_fx - 1.5 * pa_xyz[j] * pc_x[j] * fl1_fx - 1.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx - 1.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx - 4.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx - 1.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_xx[j] - 1.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_xx[j] - 1.5 * fl1_fx * pa_yz[j] * pb_xx[j] - 3.0 * pa_xyz[j] * pb_xx[j] * pc_x[j] - pa_xy[j] * pc_z[j] * pb_xxx[j] - pa_xz[j] * pc_y[j] * pb_xxx[j] - pc_x[j] * pa_yz[j] * pb_xxx[j]);

                t_xyz_xxx[j] += fl_s_0_0_2 * (1.5 * fl2_fx * pa_y[j] * pc_z[j] + 1.5 * fl2_fx * pc_y[j] * pa_z[j] + 0.75 * fl2_fx * pc_yz[j] + 0.75 * fl2_fx * pa_yz[j] + 1.5 * pa_xyz[j] * pc_x[j] * fl1_fx + 1.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_xy[j] * pc_xz[j] * fl1_fx + 1.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx + 1.5 * pa_xz[j] * pc_xy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx + 4.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xx[j] * pa_yz[j] * fl1_fx + 4.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx + 4.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pc_yz[j] * pb_xx[j] + 1.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_xx[j] + 1.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_xx[j] + 3.0 * pa_xyz[j] * pb_x[j] * pc_xx[j] + 3.0 * pa_xy[j] * pc_xz[j] * pb_xx[j] + 3.0 * pa_xz[j] * pc_xy[j] * pb_xx[j] + pa_x[j] * pc_yz[j] * pb_xxx[j] + 3.0 * pc_xx[j] * pa_yz[j] * pb_xx[j] + pc_xz[j] * pa_y[j] * pb_xxx[j] + pc_xy[j] * pa_z[j] * pb_xxx[j]);

                t_xyz_xxx[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pa_z[j] - 1.5 * pa_xy[j] * pc_xz[j] * fl1_fx - 1.5 * pa_xz[j] * pc_xy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx - 3.0 * pc_xx[j] * pa_yz[j] * fl1_fx - 4.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxz[j] * pa_y[j] * fl1_fx - 4.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxy[j] * pa_z[j] * fl1_fx - 4.5 * pc_xyz[j] * pb_x[j] * fl1_fx - 1.5 * fl1_fx * pc_yz[j] * pb_xx[j] - pa_xyz[j] * pc_xxx[j] - 3.0 * pa_xy[j] * pc_xxz[j] * pb_x[j] - 3.0 * pa_xz[j] * pc_xxy[j] * pb_x[j] - 3.0 * pa_x[j] * pc_xyz[j] * pb_xx[j] - 3.0 * pc_xxx[j] * pa_yz[j] * pb_x[j] - 3.0 * pc_xxz[j] * pa_y[j] * pb_xx[j] - 3.0 * pc_xxy[j] * pa_z[j] * pb_xx[j] - pc_xyz[j] * pb_xxx[j]);

                t_xyz_xxx[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xxz[j] * pa_y[j] * fl1_fx + 3.0 * pc_xxy[j] * pa_z[j] * fl1_fx + 4.5 * pc_xyz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xxyz[j] * fl1_fx + pa_xy[j] * pc_xxxz[j] + pa_xz[j] * pc_xxxy[j] + 3.0 * pa_x[j] * pc_xxyz[j] * pb_x[j] + pc_xxxx[j] * pa_yz[j] + 3.0 * pc_xxxz[j] * pa_y[j] * pb_x[j] + 3.0 * pc_xxxy[j] * pa_z[j] * pb_x[j] + 3.0 * pc_xxyz[j] * pb_xx[j]);

                t_xyz_xxx[j] += fl_s_0_0_5 * (-3.0 * pc_xxyz[j] * fl1_fx - pa_x[j] * pc_xxxyz[j] - pc_xxxxz[j] * pa_y[j] - pc_xxxxy[j] * pa_z[j] - 3.0 * pc_xxxyz[j] * pb_x[j]);

                t_xyz_xxx[j] += fl_s_0_0_6 * pc_xxxxyz[j];

                t_xyz_xxy[j] = fl_s_0_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xyz[j] * fl1_fx * pb_y[j] + 0.5 * pa_xz[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_yz[j] * pb_xy[j] + pa_xyz[j] * pb_xxy[j]);

                t_xyz_xxy[j] += fl_s_0_0_1 * (-0.5 * pa_xz[j] * fl2_fx - 0.25 * pa_x[j] * fl2_fx * pc_z[j] - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 0.5 * fl2_fx * pc_z[j] * pb_x[j] - fl2_fx * pa_z[j] * pb_x[j] - 0.5 * pa_xyz[j] * fl1_fx * pc_y[j] - 0.5 * pa_xyz[j] * fl1_fx * pb_y[j] - 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_y[j] - 0.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_y[j] - pa_xz[j] * fl1_fx * pb_x[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_xx[j] - 0.5 * pa_xz[j] * fl1_fx * pb_xx[j] - 1.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_y[j] - 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xx[j] - fl1_fx * pa_yz[j] * pb_x[j] * pc_y[j] - fl1_fx * pa_y[j] * pc_z[j] * pb_xy[j] - fl1_fx * pc_y[j] * pa_z[j] * pb_xy[j] - fl1_fx * pa_yz[j] * pb_xy[j] - pa_xyz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xyz[j] * pb_xy[j] * pc_x[j] - pa_xy[j] * pc_z[j] * pb_xxy[j] - pa_xz[j] * pc_y[j] * pb_xxy[j] - pc_x[j] * pa_yz[j] * pb_xxy[j]);

                t_xyz_xxy[j] += fl_s_0_0_2 * (0.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.25 * pa_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pa_z[j] + 0.75 * pc_xz[j] * fl2_fx + fl2_fx * pc_z[j] * pb_x[j] + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xyz[j] * fl1_fx * pc_y[j] + 0.5 * pa_xy[j] * pc_yz[j] * fl1_fx + 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_y[j] + 0.5 * pa_xz[j] * pc_yy[j] * fl1_fx + 0.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] + 0.5 * pa_xz[j] * fl1_fx * pc_xx[j] + pa_x[j] * fl1_fx * pc_xz[j] * pb_x[j] + pa_xz[j] * fl1_fx * pb_x[j] * pc_x[j] + 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_xx[j] + 1.5 * pc_xy[j] * pa_yz[j] * fl1_fx + 1.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_y[j] + 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] + pc_xx[j] * fl1_fx * pa_z[j] * pb_x[j] + 0.5 * pc_xz[j] * fl1_fx * pb_xx[j] + 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xx[j] + fl1_fx * pa_y[j] * pc_yz[j] * pb_x[j] + fl1_fx * pc_yy[j] * pa_z[j] * pb_x[j] + fl1_fx * pc_yz[j] * pb_xy[j] + fl1_fx * pa_yz[j] * pb_x[j] * pc_y[j] + fl1_fx * pa_y[j] * pc_z[j] * pb_xy[j] + fl1_fx * pc_y[j] * pa_z[j] * pb_xy[j] + 2.0 * pa_xyz[j] * pb_x[j] * pc_xy[j] + pa_xyz[j] * pc_xx[j] * pb_y[j] + pa_xy[j] * pc_yz[j] * pb_xx[j] + 2.0 * pa_xy[j] * pc_xz[j] * pb_xy[j] + pa_xz[j] * pc_yy[j] * pb_xx[j] + 2.0 * pa_xz[j] * pc_xy[j] * pb_xy[j] + pa_x[j] * pc_yz[j] * pb_xxy[j] + pc_xy[j] * pa_yz[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_yz[j] * pb_xy[j] + pc_xz[j] * pa_y[j] * pb_xxy[j] + pc_xy[j] * pa_z[j] * pb_xxy[j]);

                t_xyz_xxy[j] += fl_s_0_0_3 * (-0.25 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 0.5 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * pa_xy[j] * pc_yz[j] * fl1_fx - 0.5 * pa_xz[j] * pc_yy[j] * fl1_fx - 0.5 * pa_x[j] * pc_yyz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] - 0.5 * pa_x[j] * fl1_fx * pc_xxz[j] - 0.5 * pa_xz[j] * fl1_fx * pc_xx[j] - pa_x[j] * fl1_fx * pc_xz[j] * pb_x[j] - 1.5 * pc_xy[j] * pa_yz[j] * fl1_fx - 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] - 0.5 * pc_xxx[j] * fl1_fx * pa_z[j] - pc_xxz[j] * fl1_fx * pb_x[j] - pc_xx[j] * fl1_fx * pa_z[j] * pb_x[j] - 0.5 * pc_xz[j] * fl1_fx * pb_xx[j] - fl1_fx * pc_yyz[j] * pb_x[j] - fl1_fx * pa_y[j] * pc_yz[j] * pb_x[j] - fl1_fx * pc_yy[j] * pa_z[j] * pb_x[j] - fl1_fx * pc_yz[j] * pb_xy[j] - pa_xyz[j] * pc_xxy[j] - 2.0 * pa_xy[j] * pc_xyz[j] * pb_x[j] - pa_xy[j] * pc_xxz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_xyy[j] * pb_x[j] - pa_xz[j] * pc_xxy[j] * pb_y[j] - pa_x[j] * pc_yyz[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xy[j] - 2.0 * pc_xxy[j] * pa_yz[j] * pb_x[j] - pc_xxx[j] * pa_yz[j] * pb_y[j] - pc_xyz[j] * pa_y[j] * pb_xx[j] - 2.0 * pc_xxz[j] * pa_y[j] * pb_xy[j] - pc_xyy[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xxy[j] * pa_z[j] * pb_xy[j] - pc_xyz[j] * pb_xxy[j]);

                t_xyz_xxy[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 0.5 * pa_x[j] * pc_yyz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_xxz[j] + 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] + 0.5 * pc_xxxz[j] * fl1_fx + 0.5 * pc_xxx[j] * fl1_fx * pa_z[j] + pc_xxz[j] * fl1_fx * pb_x[j] + fl1_fx * pc_yyz[j] * pb_x[j] + pa_xy[j] * pc_xxyz[j] + pa_xz[j] * pc_xxyy[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_x[j] + pa_x[j] * pc_xxyz[j] * pb_y[j] + pc_xxxy[j] * pa_yz[j] + 2.0 * pc_xxyz[j] * pa_y[j] * pb_x[j] + pc_xxxz[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xxyy[j] * pa_z[j] * pb_x[j] + pc_xxxy[j] * pa_z[j] * pb_y[j] + pc_xyyz[j] * pb_xx[j] + 2.0 * pc_xxyz[j] * pb_xy[j]);

                t_xyz_xxy[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * pc_xxxz[j] * fl1_fx - pa_x[j] * pc_xxyyz[j] - pc_xxxyz[j] * pa_y[j] - pc_xxxyy[j] * pa_z[j] - 2.0 * pc_xxyyz[j] * pb_x[j] - pc_xxxyz[j] * pb_y[j]);

                t_xyz_xxy[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_xyz_xxz[j] = fl_s_0_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_yz[j] * pb_xz[j] + pa_xyz[j] * pb_xxz[j]);

                t_xyz_xxz[j] += fl_s_0_0_1 * (-0.5 * pa_xy[j] * fl2_fx - 0.25 * pa_x[j] * pc_y[j] * fl2_fx - 0.75 * pc_x[j] * pa_y[j] * fl2_fx - fl2_fx * pa_y[j] * pb_x[j] - 0.5 * fl2_fx * pc_y[j] * pb_x[j] - 0.5 * pa_xyz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xyz[j] * fl1_fx * pb_z[j] - 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_xy[j] * fl1_fx * pb_x[j] * pc_x[j] - 0.5 * pa_xy[j] * fl1_fx * pb_xx[j] - 0.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_z[j] - 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xx[j] - 1.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_xx[j] - fl1_fx * pa_yz[j] * pb_x[j] * pc_z[j] - fl1_fx * pa_y[j] * pc_z[j] * pb_xz[j] - fl1_fx * pc_y[j] * pa_z[j] * pb_xz[j] - fl1_fx * pa_yz[j] * pb_xz[j] - pa_xyz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xyz[j] * pb_xz[j] * pc_x[j] - pa_xy[j] * pc_z[j] * pb_xxz[j] - pa_xz[j] * pc_y[j] * pb_xxz[j] - pc_x[j] * pa_yz[j] * pb_xxz[j]);

                t_xyz_xxz[j] += fl_s_0_0_2 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * pc_y[j] * fl2_fx + 1.5 * pc_x[j] * pa_y[j] * fl2_fx + 0.75 * pc_xy[j] * fl2_fx + fl2_fx * pc_y[j] * pb_x[j] + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xyz[j] * fl1_fx * pc_z[j] + 0.5 * pa_xy[j] * pc_zz[j] * fl1_fx + 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pc_xx[j] + pa_xy[j] * fl1_fx * pb_x[j] * pc_x[j] + 0.5 * pa_xz[j] * pc_yz[j] * fl1_fx + 0.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] + 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xz[j] * pa_yz[j] * fl1_fx + 1.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_z[j] + 1.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_xx[j] * pa_y[j] * fl1_fx * pb_x[j] + 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_xy[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_y[j] * pc_zz[j] * pb_x[j] + fl1_fx * pc_yz[j] * pa_z[j] * pb_x[j] + fl1_fx * pc_yz[j] * pb_xz[j] + fl1_fx * pa_yz[j] * pb_x[j] * pc_z[j] + fl1_fx * pa_y[j] * pc_z[j] * pb_xz[j] + fl1_fx * pc_y[j] * pa_z[j] * pb_xz[j] + 2.0 * pa_xyz[j] * pb_x[j] * pc_xz[j] + pa_xyz[j] * pc_xx[j] * pb_z[j] + pa_xy[j] * pc_zz[j] * pb_xx[j] + 2.0 * pa_xy[j] * pc_xz[j] * pb_xz[j] + pa_xz[j] * pc_yz[j] * pb_xx[j] + 2.0 * pa_xz[j] * pc_xy[j] * pb_xz[j] + pa_x[j] * pc_yz[j] * pb_xxz[j] + pc_xz[j] * pa_yz[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_yz[j] * pb_xz[j] + pc_xz[j] * pa_y[j] * pb_xxz[j] + pc_xy[j] * pa_z[j] * pb_xxz[j]);

                t_xyz_xxz[j] += fl_s_0_0_3 * (-0.25 * pa_x[j] * pc_y[j] * fl2_fx - 0.75 * pc_x[j] * pa_y[j] * fl2_fx - 1.5 * pc_xy[j] * fl2_fx - 0.5 * fl2_fx * pc_y[j] * pb_x[j] - 0.5 * pa_xy[j] * pc_zz[j] * fl1_fx - 0.5 * pa_xy[j] * fl1_fx * pc_xx[j] - 0.5 * pa_xz[j] * pc_yz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yzz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pa_x[j] * pc_xxy[j] * fl1_fx - pa_x[j] * pc_xy[j] * fl1_fx * pb_x[j] - 1.5 * pc_xz[j] * pa_yz[j] * fl1_fx - 1.5 * pc_xzz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] - 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx - pc_xx[j] * pa_y[j] * fl1_fx * pb_x[j] - 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx - 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] - pc_xxy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xy[j] * fl1_fx * pb_xx[j] - fl1_fx * pc_yzz[j] * pb_x[j] - fl1_fx * pa_y[j] * pc_zz[j] * pb_x[j] - fl1_fx * pc_yz[j] * pa_z[j] * pb_x[j] - fl1_fx * pc_yz[j] * pb_xz[j] - pa_xyz[j] * pc_xxz[j] - 2.0 * pa_xy[j] * pc_xzz[j] * pb_x[j] - pa_xy[j] * pc_xxz[j] * pb_z[j] - 2.0 * pa_xz[j] * pc_xyz[j] * pb_x[j] - pa_xz[j] * pc_xxy[j] * pb_z[j] - pa_x[j] * pc_yzz[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xyz[j] * pb_xz[j] - 2.0 * pc_xxz[j] * pa_yz[j] * pb_x[j] - pc_xxx[j] * pa_yz[j] * pb_z[j] - pc_xzz[j] * pa_y[j] * pb_xx[j] - 2.0 * pc_xxz[j] * pa_y[j] * pb_xz[j] - pc_xyz[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xxy[j] * pa_z[j] * pb_xz[j] - pc_xyz[j] * pb_xxz[j]);

                t_xyz_xxz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_x[j] * pc_yzz[j] * fl1_fx + 0.5 * pa_x[j] * pc_xxy[j] * fl1_fx + 1.5 * pc_xzz[j] * pa_y[j] * fl1_fx + 0.5 * pc_xxx[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xxxy[j] * fl1_fx + pc_xxy[j] * fl1_fx * pb_x[j] + fl1_fx * pc_yzz[j] * pb_x[j] + pa_xy[j] * pc_xxzz[j] + pa_xz[j] * pc_xxyz[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_x[j] + pa_x[j] * pc_xxyz[j] * pb_z[j] + pc_xxxz[j] * pa_yz[j] + 2.0 * pc_xxzz[j] * pa_y[j] * pb_x[j] + pc_xxxz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_x[j] + pc_xxxy[j] * pa_z[j] * pb_z[j] + pc_xyzz[j] * pb_xx[j] + 2.0 * pc_xxyz[j] * pb_xz[j]);

                t_xyz_xxz[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xxxy[j] * fl1_fx - pa_x[j] * pc_xxyzz[j] - pc_xxxzz[j] * pa_y[j] - pc_xxxyz[j] * pa_z[j] - 2.0 * pc_xxyzz[j] * pb_x[j] - pc_xxxyz[j] * pb_z[j]);

                t_xyz_xxz[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_xyz_xyy[j] = fl_s_0_0_0 * (0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_xyz[j] * pb_x[j] * fl1_fx + pa_xz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_yz[j] * pb_yy[j] + pa_xyz[j] * pb_xyy[j]);

                t_xyz_xyy[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_yz[j] - 0.25 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pa_z[j] - 0.5 * fl2_fx * pc_z[j] * pb_y[j] - fl2_fx * pa_z[j] * pb_y[j] - 0.5 * pa_xyz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xyz[j] * pc_x[j] * fl1_fx - 0.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx - 1.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx - pa_xz[j] * fl1_fx * pc_x[j] * pb_y[j] - pa_x[j] * fl1_fx * pc_z[j] * pb_xy[j] - pa_xz[j] * fl1_fx * pb_xy[j] - 0.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx - pc_x[j] * fl1_fx * pa_z[j] * pb_xy[j] - fl1_fx * pa_yz[j] * pb_y[j] * pc_y[j] - 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_yy[j] - 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_yy[j] - 0.5 * fl1_fx * pa_yz[j] * pb_yy[j] - 2.0 * pa_xyz[j] * pb_xy[j] * pc_y[j] - pa_xyz[j] * pc_x[j] * pb_yy[j] - pa_xy[j] * pc_z[j] * pb_xyy[j] - pa_xz[j] * pc_y[j] * pb_xyy[j] - pc_x[j] * pa_yz[j] * pb_xyy[j]);

                t_xyz_xyy[j] += fl_s_0_0_2 * (0.5 * fl2_fx * pa_y[j] * pc_z[j] + 1.5 * fl2_fx * pc_y[j] * pa_z[j] + 0.75 * fl2_fx * pc_yz[j] + fl2_fx * pc_z[j] * pb_y[j] + 0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_xyz[j] * pc_x[j] * fl1_fx + 0.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx + 0.5 * pa_xy[j] * pc_xz[j] * fl1_fx + 1.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx + 1.5 * pa_xz[j] * pc_xy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx + pa_x[j] * fl1_fx * pc_xz[j] * pb_y[j] + pa_xz[j] * fl1_fx * pc_x[j] * pb_y[j] + pa_x[j] * fl1_fx * pc_z[j] * pb_xy[j] + 0.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_yz[j] * fl1_fx + 0.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx + 1.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx + pc_xx[j] * fl1_fx * pa_z[j] * pb_y[j] + pc_xz[j] * fl1_fx * pb_xy[j] + pc_x[j] * fl1_fx * pa_z[j] * pb_xy[j] + 0.5 * fl1_fx * pa_yz[j] * pc_yy[j] + fl1_fx * pa_y[j] * pc_yz[j] * pb_y[j] + fl1_fx * pc_yy[j] * pa_z[j] * pb_y[j] + 0.5 * fl1_fx * pc_yz[j] * pb_yy[j] + fl1_fx * pa_yz[j] * pb_y[j] * pc_y[j] + 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_yy[j] + 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_yy[j] + pa_xyz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xyz[j] * pc_xy[j] * pb_y[j] + 2.0 * pa_xy[j] * pc_yz[j] * pb_xy[j] + pa_xy[j] * pc_xz[j] * pb_yy[j] + 2.0 * pa_xz[j] * pc_yy[j] * pb_xy[j] + pa_xz[j] * pc_xy[j] * pb_yy[j] + pa_x[j] * pc_yz[j] * pb_xyy[j] + 2.0 * pc_xy[j] * pa_yz[j] * pb_xy[j] + pc_xx[j] * pa_yz[j] * pb_yy[j] + pc_xz[j] * pa_y[j] * pb_xyy[j] + pc_xy[j] * pa_z[j] * pb_xyy[j]);

                t_xyz_xyy[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.25 * fl2_fx * pa_y[j] * pc_z[j] - 0.75 * fl2_fx * pc_y[j] * pa_z[j] - 0.5 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * pa_xy[j] * pc_xz[j] * fl1_fx - 1.5 * pa_xz[j] * pc_xy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx - pa_x[j] * fl1_fx * pc_xz[j] * pb_y[j] - 0.5 * pc_xx[j] * pa_yz[j] * fl1_fx - 0.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx - 1.5 * pc_xxy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xyz[j] * pb_x[j] * fl1_fx - pc_xxz[j] * fl1_fx * pb_y[j] - pc_xx[j] * fl1_fx * pa_z[j] * pb_y[j] - pc_xz[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pa_y[j] * pc_yyz[j] - 0.5 * fl1_fx * pc_yyy[j] * pa_z[j] - fl1_fx * pc_yyz[j] * pb_y[j] - 0.5 * fl1_fx * pa_yz[j] * pc_yy[j] - fl1_fx * pa_y[j] * pc_yz[j] * pb_y[j] - fl1_fx * pc_yy[j] * pa_z[j] * pb_y[j] - 0.5 * fl1_fx * pc_yz[j] * pb_yy[j] - pa_xyz[j] * pc_xyy[j] - pa_xy[j] * pc_yyz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xyz[j] * pb_y[j] - pa_xz[j] * pc_yyy[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xyy[j] * pb_y[j] - 2.0 * pa_x[j] * pc_yyz[j] * pb_xy[j] - pa_x[j] * pc_xyz[j] * pb_yy[j] - pc_xyy[j] * pa_yz[j] * pb_x[j] - 2.0 * pc_xxy[j] * pa_yz[j] * pb_y[j] - 2.0 * pc_xyz[j] * pa_y[j] * pb_xy[j] - pc_xxz[j] * pa_y[j] * pb_yy[j] - 2.0 * pc_xyy[j] * pa_z[j] * pb_xy[j] - pc_xxy[j] * pa_z[j] * pb_yy[j] - pc_xyz[j] * pb_xyy[j]);

                t_xyz_xyy[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx + 0.5 * pc_xxz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xxy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + pc_xxz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yyyz[j] + 0.5 * fl1_fx * pa_y[j] * pc_yyz[j] + 0.5 * fl1_fx * pc_yyy[j] * pa_z[j] + fl1_fx * pc_yyz[j] * pb_y[j] + pa_xy[j] * pc_xyyz[j] + pa_xz[j] * pc_xyyy[j] + pa_x[j] * pc_yyyz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xyyz[j] * pb_y[j] + pc_xxyy[j] * pa_yz[j] + pc_xyyz[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxyz[j] * pa_y[j] * pb_y[j] + pc_xyyy[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxyy[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xyyz[j] * pb_xy[j] + pc_xxyz[j] * pb_yy[j]);

                t_xyz_xyy[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyyz[j] - pa_x[j] * pc_xyyyz[j] - pc_xxyyz[j] * pa_y[j] - pc_xxyyy[j] * pa_z[j] - pc_xyyyz[j] * pb_x[j] - 2.0 * pc_xxyyz[j] * pb_y[j]);

                t_xyz_xyy[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_xyz_xyz[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_xy[j] + 0.5 * pa_xz[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yz[j] * pb_yz[j] + pa_xyz[j] * pb_xyz[j]);

                t_xyz_xyz[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.25 * fl2_fx * pa_y[j] * pc_y[j] - 0.5 * fl2_fx * pa_y[j] * pb_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_y[j] - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.5 * pa_xy[j] * fl1_fx * pb_x[j] * pc_y[j] - 0.5 * pa_xy[j] * fl1_fx * pc_x[j] * pb_y[j] - 0.5 * pa_xy[j] * fl1_fx * pb_xy[j] - 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xy[j] - 0.5 * pa_xz[j] * fl1_fx * pb_x[j] * pc_z[j] - 0.5 * pa_xz[j] * fl1_fx * pc_x[j] * pb_z[j] - 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_xz[j] - 0.5 * pa_xz[j] * fl1_fx * pb_xz[j] - 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_xy[j] - 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xz[j] - 0.5 * fl1_fx * pa_yz[j] * pb_y[j] * pc_z[j] - 0.5 * fl1_fx * pa_yz[j] * pc_y[j] * pb_z[j] - 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_yz[j] - 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_yz[j] - 0.5 * fl1_fx * pa_yz[j] * pb_yz[j] - pa_xyz[j] * pb_xy[j] * pc_z[j] - pa_xyz[j] * pb_xz[j] * pc_y[j] - pa_xyz[j] * pc_x[j] * pb_yz[j] - pa_xy[j] * pc_z[j] * pb_xyz[j] - pa_xz[j] * pc_y[j] * pb_xyz[j] - pc_x[j] * pa_yz[j] * pb_xyz[j]);

                t_xyz_xyz[j] += fl_s_0_0_2 * (0.375 * fl3_fx + 0.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * pc_xx[j] * fl2_fx + 0.5 * pc_x[j] * fl2_fx * pb_x[j] + 0.5 * fl2_fx * pa_y[j] * pc_y[j] + 0.25 * fl2_fx * pc_yy[j] + 0.5 * fl2_fx * pc_y[j] * pb_y[j] + 0.25 * fl2_fx * pc_zz[j] + 0.5 * fl2_fx * pa_z[j] * pc_z[j] + 0.5 * fl2_fx * pc_z[j] * pb_z[j] + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pc_xy[j] + 0.5 * pa_xy[j] * fl1_fx * pb_x[j] * pc_y[j] + 0.5 * pa_xy[j] * fl1_fx * pc_x[j] * pb_y[j] + 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_x[j] + 0.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_xy[j] + 0.5 * pa_xz[j] * fl1_fx * pc_xz[j] + 0.5 * pa_x[j] * fl1_fx * pc_zz[j] * pb_x[j] + 0.5 * pa_x[j] * fl1_fx * pc_xz[j] * pb_z[j] + 0.5 * pa_xz[j] * fl1_fx * pb_x[j] * pc_z[j] + 0.5 * pa_xz[j] * fl1_fx * pc_x[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_xz[j] + 0.5 * pc_xy[j] * pa_y[j] * fl1_fx * pb_x[j] + 0.5 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] + 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_xy[j] + 0.5 * pc_xy[j] * fl1_fx * pb_xy[j] + 0.5 * pc_xz[j] * fl1_fx * pa_z[j] * pb_x[j] + 0.5 * pc_xx[j] * fl1_fx * pa_z[j] * pb_z[j] + 0.5 * pc_xz[j] * fl1_fx * pb_xz[j] + 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_xz[j] + 0.5 * fl1_fx * pa_yz[j] * pc_yz[j] + 0.5 * fl1_fx * pa_y[j] * pc_zz[j] * pb_y[j] + 0.5 * fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] + 0.5 * fl1_fx * pc_yz[j] * pa_z[j] * pb_y[j] + 0.5 * fl1_fx * pc_yy[j] * pa_z[j] * pb_z[j] + 0.5 * fl1_fx * pc_yz[j] * pb_yz[j] + 0.5 * fl1_fx * pa_yz[j] * pb_y[j] * pc_z[j] + 0.5 * fl1_fx * pa_yz[j] * pc_y[j] * pb_z[j] + 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_yz[j] + 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_yz[j] + pa_xyz[j] * pb_x[j] * pc_yz[j] + pa_xyz[j] * pc_xz[j] * pb_y[j] + pa_xyz[j] * pc_xy[j] * pb_z[j] + pa_xy[j] * pc_zz[j] * pb_xy[j] + pa_xy[j] * pc_yz[j] * pb_xz[j] + pa_xy[j] * pc_xz[j] * pb_yz[j] + pa_xz[j] * pc_yz[j] * pb_xy[j] + pa_xz[j] * pc_yy[j] * pb_xz[j] + pa_xz[j] * pc_xy[j] * pb_yz[j] + pa_x[j] * pc_yz[j] * pb_xyz[j] + pc_xz[j] * pa_yz[j] * pb_xy[j] + pc_xy[j] * pa_yz[j] * pb_xz[j] + pc_xx[j] * pa_yz[j] * pb_yz[j] + pc_xz[j] * pa_y[j] * pb_xyz[j] + pc_xy[j] * pa_z[j] * pb_xyz[j]);

                t_xyz_xyz[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.5 * pc_xx[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pc_yy[j] - 0.5 * fl2_fx * pc_zz[j] - 0.25 * fl2_fx * pa_y[j] * pc_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_y[j] - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * pa_xy[j] * fl1_fx * pc_xy[j] - 0.5 * pa_x[j] * pc_xyy[j] * fl1_fx - 0.5 * pa_x[j] * pc_yy[j] * fl1_fx * pb_x[j] - 0.5 * pa_x[j] * pc_xy[j] * fl1_fx * pb_y[j] - 0.5 * pa_x[j] * fl1_fx * pc_xzz[j] - 0.5 * pa_xz[j] * fl1_fx * pc_xz[j] - 0.5 * pa_x[j] * fl1_fx * pc_zz[j] * pb_x[j] - 0.5 * pa_x[j] * fl1_fx * pc_xz[j] * pb_z[j] - 0.5 * pc_xxy[j] * pa_y[j] * fl1_fx - 0.5 * pc_xy[j] * pa_y[j] * fl1_fx * pb_x[j] - 0.5 * pc_xx[j] * pa_y[j] * fl1_fx * pb_y[j] - 0.5 * pc_xyy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xy[j] * fl1_fx * pb_xy[j] - 0.5 * pc_xxz[j] * fl1_fx * pa_z[j] - 0.5 * pc_xzz[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xz[j] * fl1_fx * pa_z[j] * pb_x[j] - 0.5 * pc_xx[j] * fl1_fx * pa_z[j] * pb_z[j] - 0.5 * pc_xz[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pa_y[j] * pc_yzz[j] - 0.5 * fl1_fx * pc_yyz[j] * pa_z[j] - 0.5 * fl1_fx * pc_yzz[j] * pb_y[j] - 0.5 * fl1_fx * pc_yyz[j] * pb_z[j] - 0.5 * fl1_fx * pa_yz[j] * pc_yz[j] - 0.5 * fl1_fx * pa_y[j] * pc_zz[j] * pb_y[j] - 0.5 * fl1_fx * pa_y[j] * pc_yz[j] * pb_z[j] - 0.5 * fl1_fx * pc_yz[j] * pa_z[j] * pb_y[j] - 0.5 * fl1_fx * pc_yy[j] * pa_z[j] * pb_z[j] - 0.5 * fl1_fx * pc_yz[j] * pb_yz[j] - pa_xyz[j] * pc_xyz[j] - pa_xy[j] * pc_yzz[j] * pb_x[j] - pa_xy[j] * pc_xzz[j] * pb_y[j] - pa_xy[j] * pc_xyz[j] * pb_z[j] - pa_xz[j] * pc_yyz[j] * pb_x[j] - pa_xz[j] * pc_xyz[j] * pb_y[j] - pa_xz[j] * pc_xyy[j] * pb_z[j] - pa_x[j] * pc_yzz[j] * pb_xy[j] - pa_x[j] * pc_yyz[j] * pb_xz[j] - pa_x[j] * pc_xyz[j] * pb_yz[j] - pc_xyz[j] * pa_yz[j] * pb_x[j] - pc_xxz[j] * pa_yz[j] * pb_y[j] - pc_xxy[j] * pa_yz[j] * pb_z[j] - pc_xzz[j] * pa_y[j] * pb_xy[j] - pc_xyz[j] * pa_y[j] * pb_xz[j] - pc_xxz[j] * pa_y[j] * pb_yz[j] - pc_xyz[j] * pa_z[j] * pb_xy[j] - pc_xyy[j] * pa_z[j] * pb_xz[j] - pc_xxy[j] * pa_z[j] * pb_yz[j] - pc_xyz[j] * pb_xyz[j]);

                t_xyz_xyz[j] += fl_s_0_0_4 * (0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_yy[j] + 0.25 * fl2_fx * pc_zz[j] + 0.5 * pa_x[j] * pc_xyy[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_xzz[j] + 0.5 * pc_xxy[j] * pa_y[j] * fl1_fx + 0.5 * pc_xxyy[j] * fl1_fx + 0.5 * pc_xyy[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxy[j] * fl1_fx * pb_y[j] + 0.5 * pc_xxzz[j] * fl1_fx + 0.5 * pc_xxz[j] * fl1_fx * pa_z[j] + 0.5 * pc_xzz[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yyzz[j] + 0.5 * fl1_fx * pa_y[j] * pc_yzz[j] + 0.5 * fl1_fx * pc_yyz[j] * pa_z[j] + 0.5 * fl1_fx * pc_yzz[j] * pb_y[j] + 0.5 * fl1_fx * pc_yyz[j] * pb_z[j] + pa_xy[j] * pc_xyzz[j] + pa_xz[j] * pc_xyyz[j] + pa_x[j] * pc_yyzz[j] * pb_x[j] + pa_x[j] * pc_xyzz[j] * pb_y[j] + pa_x[j] * pc_xyyz[j] * pb_z[j] + pc_xxyz[j] * pa_yz[j] + pc_xyzz[j] * pa_y[j] * pb_x[j] + pc_xxzz[j] * pa_y[j] * pb_y[j] + pc_xxyz[j] * pa_y[j] * pb_z[j] + pc_xyyz[j] * pa_z[j] * pb_x[j] + pc_xxyz[j] * pa_z[j] * pb_y[j] + pc_xxyy[j] * pa_z[j] * pb_z[j] + pc_xyzz[j] * pb_xy[j] + pc_xyyz[j] * pb_xz[j] + pc_xxyz[j] * pb_yz[j]);

                t_xyz_xyz[j] += fl_s_0_0_5 * (-0.5 * pc_xxyy[j] * fl1_fx - 0.5 * pc_xxzz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyzz[j] - pa_x[j] * pc_xyyzz[j] - pc_xxyzz[j] * pa_y[j] - pc_xxyyz[j] * pa_z[j] - pc_xyyzz[j] * pb_x[j] - pc_xxyzz[j] * pb_y[j] - pc_xxyyz[j] * pb_z[j]);

                t_xyz_xyz[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_xyz_xzz[j] = fl_s_0_0_0 * (0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * pa_xyz[j] * pb_x[j] * fl1_fx + pa_xy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yz[j] * pb_zz[j] + pa_xyz[j] * pb_xzz[j]);

                t_xyz_xzz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - fl2_fx * pa_y[j] * pb_z[j] - 0.25 * fl2_fx * pc_y[j] * pa_z[j] - 0.5 * fl2_fx * pc_y[j] * pb_z[j] - 0.5 * pa_xyz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xyz[j] * pc_x[j] * fl1_fx - 1.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx - pa_xy[j] * fl1_fx * pc_x[j] * pb_z[j] - pa_xy[j] * fl1_fx * pb_xz[j] - 0.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx - pa_x[j] * pc_y[j] * fl1_fx * pb_xz[j] - 0.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx - pc_x[j] * pa_y[j] * fl1_fx * pb_xz[j] - fl1_fx * pa_yz[j] * pb_z[j] * pc_z[j] - 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_zz[j] - 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_zz[j] - 0.5 * fl1_fx * pa_yz[j] * pb_zz[j] - 2.0 * pa_xyz[j] * pb_xz[j] * pc_z[j] - pa_xyz[j] * pc_x[j] * pb_zz[j] - pa_xy[j] * pc_z[j] * pb_xzz[j] - pa_xz[j] * pc_y[j] * pb_xzz[j] - pc_x[j] * pa_yz[j] * pb_xzz[j]);

                t_xyz_xzz[j] += fl_s_0_0_2 * (1.5 * fl2_fx * pa_y[j] * pc_z[j] + 0.5 * fl2_fx * pc_y[j] * pa_z[j] + 0.75 * fl2_fx * pc_yz[j] + fl2_fx * pc_y[j] * pb_z[j] + 0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * pa_xyz[j] * pc_x[j] * fl1_fx + 1.5 * pa_xy[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_xy[j] * pc_xz[j] * fl1_fx + pa_xy[j] * fl1_fx * pc_x[j] * pb_z[j] + 0.5 * pa_xz[j] * pc_y[j] * pb_x[j] * fl1_fx + 0.5 * pa_xz[j] * pc_xy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx + pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_y[j] * fl1_fx * pb_xz[j] + 0.5 * pc_x[j] * pa_yz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_yz[j] * fl1_fx + 1.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx + pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_x[j] * pa_y[j] * fl1_fx * pb_xz[j] + 0.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx + pc_xy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yz[j] * pc_zz[j] + fl1_fx * pa_y[j] * pc_zz[j] * pb_z[j] + fl1_fx * pc_yz[j] * pa_z[j] * pb_z[j] + 0.5 * fl1_fx * pc_yz[j] * pb_zz[j] + fl1_fx * pa_yz[j] * pb_z[j] * pc_z[j] + 0.5 * fl1_fx * pa_y[j] * pc_z[j] * pb_zz[j] + 0.5 * fl1_fx * pc_y[j] * pa_z[j] * pb_zz[j] + pa_xyz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xyz[j] * pc_xz[j] * pb_z[j] + 2.0 * pa_xy[j] * pc_zz[j] * pb_xz[j] + pa_xy[j] * pc_xz[j] * pb_zz[j] + 2.0 * pa_xz[j] * pc_yz[j] * pb_xz[j] + pa_xz[j] * pc_xy[j] * pb_zz[j] + pa_x[j] * pc_yz[j] * pb_xzz[j] + 2.0 * pc_xz[j] * pa_yz[j] * pb_xz[j] + pc_xx[j] * pa_yz[j] * pb_zz[j] + pc_xz[j] * pa_y[j] * pb_xzz[j] + pc_xy[j] * pa_z[j] * pb_xzz[j]);

                t_xyz_xzz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.75 * fl2_fx * pa_y[j] * pc_z[j] - 0.25 * fl2_fx * pc_y[j] * pa_z[j] - 0.5 * fl2_fx * pc_y[j] * pb_z[j] - 1.5 * pa_xy[j] * pc_xz[j] * fl1_fx - 0.5 * pa_xz[j] * pc_xy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx - pa_x[j] * pc_xy[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * pa_yz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_y[j] * pb_x[j] * fl1_fx - 1.5 * pc_xxz[j] * pa_y[j] * fl1_fx - pc_xx[j] * pa_y[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * pa_z[j] * pb_x[j] * fl1_fx - 0.5 * pc_xxy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xyz[j] * pb_x[j] * fl1_fx - pc_xxy[j] * fl1_fx * pb_z[j] - pc_xy[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pa_y[j] * pc_zzz[j] - 0.5 * fl1_fx * pc_yzz[j] * pa_z[j] - fl1_fx * pc_yzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_yz[j] * pc_zz[j] - fl1_fx * pa_y[j] * pc_zz[j] * pb_z[j] - fl1_fx * pc_yz[j] * pa_z[j] * pb_z[j] - 0.5 * fl1_fx * pc_yz[j] * pb_zz[j] - pa_xyz[j] * pc_xzz[j] - pa_xy[j] * pc_zzz[j] * pb_x[j] - 2.0 * pa_xy[j] * pc_xzz[j] * pb_z[j] - pa_xz[j] * pc_yzz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xyz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_yzz[j] * pb_xz[j] - pa_x[j] * pc_xyz[j] * pb_zz[j] - pc_xzz[j] * pa_yz[j] * pb_x[j] - 2.0 * pc_xxz[j] * pa_yz[j] * pb_z[j] - 2.0 * pc_xzz[j] * pa_y[j] * pb_xz[j] - pc_xxz[j] * pa_y[j] * pb_zz[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_xz[j] - pc_xxy[j] * pa_z[j] * pb_zz[j] - pc_xyz[j] * pb_xzz[j]);

                t_xyz_xzz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx + 1.5 * pc_xxz[j] * pa_y[j] * fl1_fx + 0.5 * pc_xxy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + pc_xxy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_yzzz[j] + 0.5 * fl1_fx * pa_y[j] * pc_zzz[j] + 0.5 * fl1_fx * pc_yzz[j] * pa_z[j] + fl1_fx * pc_yzz[j] * pb_z[j] + pa_xy[j] * pc_xzzz[j] + pa_xz[j] * pc_xyzz[j] + pa_x[j] * pc_yzzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_z[j] + pc_xxzz[j] * pa_yz[j] + pc_xzzz[j] * pa_y[j] * pb_x[j] + 2.0 * pc_xxzz[j] * pa_y[j] * pb_z[j] + pc_xyzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xyzz[j] * pb_xz[j] + pc_xxyz[j] * pb_zz[j]);

                t_xyz_xzz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yzzz[j] - pa_x[j] * pc_xyzzz[j] - pc_xxzzz[j] * pa_y[j] - pc_xxyzz[j] * pa_z[j] - pc_xyzzz[j] * pb_x[j] - 2.0 * pc_xxyzz[j] * pb_z[j]);

                t_xyz_xzz[j] += fl_s_0_0_6 * pc_xxyzzz[j];

                t_xyz_yyy[j] = fl_s_0_0_0 * (0.75 * pa_xz[j] * fl2_fx + 1.5 * pa_xyz[j] * pb_y[j] * fl1_fx + 1.5 * pa_xz[j] * fl1_fx * pb_yy[j] + pa_xyz[j] * pb_yyy[j]);

                t_xyz_yyy[j] += fl_s_0_0_1 * (-1.5 * pa_xz[j] * fl2_fx - 0.75 * pa_x[j] * fl2_fx * pc_z[j] - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 1.5 * pa_xyz[j] * pb_y[j] * fl1_fx - 1.5 * pa_xyz[j] * pc_y[j] * fl1_fx - 1.5 * pa_xy[j] * pc_z[j] * pb_y[j] * fl1_fx - 4.5 * pa_xz[j] * pc_y[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_yy[j] - 1.5 * pa_xz[j] * fl1_fx * pb_yy[j] - 1.5 * pc_x[j] * pa_yz[j] * pb_y[j] * fl1_fx - 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yy[j] - 3.0 * pa_xyz[j] * pb_yy[j] * pc_y[j] - pa_xy[j] * pc_z[j] * pb_yyy[j] - pa_xz[j] * pc_y[j] * pb_yyy[j] - pc_x[j] * pa_yz[j] * pb_yyy[j]);

                t_xyz_yyy[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.75 * pa_xz[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pa_z[j] + 0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_xyz[j] * pc_y[j] * fl1_fx + 1.5 * pa_xy[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_xy[j] * pc_yz[j] * fl1_fx + 4.5 * pa_xz[j] * pc_y[j] * pb_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_yy[j] * fl1_fx + 4.5 * pa_x[j] * pc_yz[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_yy[j] + 1.5 * pc_x[j] * pa_yz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xy[j] * pa_yz[j] * fl1_fx + 1.5 * pc_xz[j] * pa_y[j] * pb_y[j] * fl1_fx + 4.5 * pc_xy[j] * pa_z[j] * pb_y[j] * fl1_fx + 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 1.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_yy[j] + 3.0 * pa_xyz[j] * pb_y[j] * pc_yy[j] + 3.0 * pa_xy[j] * pc_yz[j] * pb_yy[j] + 3.0 * pa_xz[j] * pc_yy[j] * pb_yy[j] + pa_x[j] * pc_yz[j] * pb_yyy[j] + 3.0 * pc_xy[j] * pa_yz[j] * pb_yy[j] + pc_xz[j] * pa_y[j] * pb_yyy[j] + pc_xy[j] * pa_z[j] * pb_yyy[j]);

                t_xyz_yyy[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pa_z[j] - 1.5 * pa_xy[j] * pc_yz[j] * fl1_fx - 3.0 * pa_xz[j] * pc_yy[j] * fl1_fx - 4.5 * pa_x[j] * pc_yz[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * pc_yyz[j] * fl1_fx - 1.5 * pc_xy[j] * pa_yz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_y[j] * pb_y[j] * fl1_fx - 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx - 4.5 * pc_xy[j] * pa_z[j] * pb_y[j] * fl1_fx - 3.0 * pc_xyy[j] * pa_z[j] * fl1_fx - 4.5 * pc_xyz[j] * pb_y[j] * fl1_fx - 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] - pa_xyz[j] * pc_yyy[j] - 3.0 * pa_xy[j] * pc_yyz[j] * pb_y[j] - 3.0 * pa_xz[j] * pc_yyy[j] * pb_y[j] - 3.0 * pa_x[j] * pc_yyz[j] * pb_yy[j] - 3.0 * pc_xyy[j] * pa_yz[j] * pb_y[j] - 3.0 * pc_xyz[j] * pa_y[j] * pb_yy[j] - 3.0 * pc_xyy[j] * pa_z[j] * pb_yy[j] - pc_xyz[j] * pb_yyy[j]);

                t_xyz_yyy[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 3.0 * pa_x[j] * pc_yyz[j] * fl1_fx + 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx + 3.0 * pc_xyy[j] * pa_z[j] * fl1_fx + 4.5 * pc_xyz[j] * pb_y[j] * fl1_fx + 3.0 * pc_xyyz[j] * fl1_fx + pa_xy[j] * pc_yyyz[j] + pa_xz[j] * pc_yyyy[j] + 3.0 * pa_x[j] * pc_yyyz[j] * pb_y[j] + pc_xyyy[j] * pa_yz[j] + 3.0 * pc_xyyz[j] * pa_y[j] * pb_y[j] + 3.0 * pc_xyyy[j] * pa_z[j] * pb_y[j] + 3.0 * pc_xyyz[j] * pb_yy[j]);

                t_xyz_yyy[j] += fl_s_0_0_5 * (-3.0 * pc_xyyz[j] * fl1_fx - pa_x[j] * pc_yyyyz[j] - pc_xyyyz[j] * pa_y[j] - pc_xyyyy[j] * pa_z[j] - 3.0 * pc_xyyyz[j] * pb_y[j]);

                t_xyz_yyy[j] += fl_s_0_0_6 * pc_xyyyyz[j];

                t_xyz_yyz[j] = fl_s_0_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_yy[j] + pa_xz[j] * fl1_fx * pb_yz[j] + pa_xyz[j] * pb_yyz[j]);

                t_xyz_yyz[j] += fl_s_0_0_1 * (-0.5 * pa_xy[j] * fl2_fx - 0.75 * pa_x[j] * pc_y[j] * fl2_fx - pa_x[j] * fl2_fx * pb_y[j] - 0.25 * pc_x[j] * pa_y[j] * fl2_fx - 0.5 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * pa_xyz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xyz[j] * fl1_fx * pb_z[j] - 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_xy[j] * fl1_fx * pb_y[j] * pc_y[j] - 0.5 * pa_xy[j] * fl1_fx * pb_yy[j] - 1.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_z[j] - 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_yy[j] - pa_xz[j] * fl1_fx * pb_y[j] * pc_z[j] - pa_x[j] * fl1_fx * pc_z[j] * pb_yz[j] - pa_xz[j] * fl1_fx * pb_yz[j] - 0.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_yy[j] - pc_x[j] * fl1_fx * pa_z[j] * pb_yz[j] - pa_xyz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xyz[j] * pb_yz[j] * pc_y[j] - pa_xy[j] * pc_z[j] * pb_yyz[j] - pa_xz[j] * pc_y[j] * pb_yyz[j] - pc_x[j] * pa_yz[j] * pb_yyz[j]);

                t_xyz_yyz[j] += fl_s_0_0_2 * (0.25 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_y[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pc_x[j] * pa_y[j] * fl2_fx + 0.75 * pc_xy[j] * fl2_fx + pc_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyz[j] * fl1_fx * pc_z[j] + 0.5 * pa_xy[j] * pc_zz[j] * fl1_fx + 0.5 * pa_xy[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pc_yy[j] + pa_xy[j] * fl1_fx * pb_y[j] * pc_y[j] + 1.5 * pa_xz[j] * pc_yz[j] * fl1_fx + 1.5 * pa_xz[j] * pc_y[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_yy[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_yy[j] + pa_x[j] * fl1_fx * pc_zz[j] * pb_y[j] + pa_xz[j] * fl1_fx * pb_y[j] * pc_z[j] + pa_x[j] * fl1_fx * pc_z[j] * pb_yz[j] + 0.5 * pc_xz[j] * pa_yz[j] * fl1_fx + 0.5 * pc_x[j] * pa_yz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_xy[j] * pa_y[j] * fl1_fx * pb_y[j] + 0.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_yy[j] + 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_xy[j] * fl1_fx * pb_yy[j] + pc_xz[j] * fl1_fx * pa_z[j] * pb_y[j] + pc_xz[j] * fl1_fx * pb_yz[j] + pc_x[j] * fl1_fx * pa_z[j] * pb_yz[j] + 2.0 * pa_xyz[j] * pb_y[j] * pc_yz[j] + pa_xyz[j] * pc_yy[j] * pb_z[j] + pa_xy[j] * pc_zz[j] * pb_yy[j] + 2.0 * pa_xy[j] * pc_yz[j] * pb_yz[j] + pa_xz[j] * pc_yz[j] * pb_yy[j] + 2.0 * pa_xz[j] * pc_yy[j] * pb_yz[j] + pa_x[j] * pc_yz[j] * pb_yyz[j] + pc_xz[j] * pa_yz[j] * pb_yy[j] + 2.0 * pc_xy[j] * pa_yz[j] * pb_yz[j] + pc_xz[j] * pa_y[j] * pb_yyz[j] + pc_xy[j] * pa_z[j] * pb_yyz[j]);

                t_xyz_yyz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_y[j] * fl2_fx - 0.25 * pc_x[j] * pa_y[j] * fl2_fx - 1.5 * pc_xy[j] * fl2_fx - 0.5 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * pa_xy[j] * pc_zz[j] * fl1_fx - 0.5 * pa_xy[j] * fl1_fx * pc_yy[j] - 1.5 * pa_xz[j] * pc_yz[j] * fl1_fx - 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx - pa_x[j] * pc_yy[j] * fl1_fx * pb_y[j] - pa_x[j] * fl1_fx * pc_zz[j] * pb_y[j] - 0.5 * pc_xz[j] * pa_yz[j] * fl1_fx - 0.5 * pc_xzz[j] * pa_y[j] * fl1_fx - 0.5 * pc_xz[j] * pa_y[j] * fl1_fx * pb_z[j] - 0.5 * pc_xyy[j] * pa_y[j] * fl1_fx - pc_xy[j] * pa_y[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx - 1.5 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] - pc_xyy[j] * fl1_fx * pb_y[j] - 0.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pc_xzz[j] * fl1_fx * pb_y[j] - pc_xz[j] * fl1_fx * pa_z[j] * pb_y[j] - pc_xz[j] * fl1_fx * pb_yz[j] - pa_xyz[j] * pc_yyz[j] - 2.0 * pa_xy[j] * pc_yzz[j] * pb_y[j] - pa_xy[j] * pc_yyz[j] * pb_z[j] - 2.0 * pa_xz[j] * pc_yyz[j] * pb_y[j] - pa_xz[j] * pc_yyy[j] * pb_z[j] - pa_x[j] * pc_yzz[j] * pb_yy[j] - 2.0 * pa_x[j] * pc_yyz[j] * pb_yz[j] - 2.0 * pc_xyz[j] * pa_yz[j] * pb_y[j] - pc_xyy[j] * pa_yz[j] * pb_z[j] - pc_xzz[j] * pa_y[j] * pb_yy[j] - 2.0 * pc_xyz[j] * pa_y[j] * pb_yz[j] - pc_xyz[j] * pa_z[j] * pb_yy[j] - 2.0 * pc_xyy[j] * pa_z[j] * pb_yz[j] - pc_xyz[j] * pb_yyz[j]);

                t_xyz_yyz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx + 0.5 * pa_x[j] * pc_yyy[j] * fl1_fx + 0.5 * pc_xzz[j] * pa_y[j] * fl1_fx + 0.5 * pc_xyy[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xyyy[j] * fl1_fx + pc_xyy[j] * fl1_fx * pb_y[j] + pc_xzz[j] * fl1_fx * pb_y[j] + pa_xy[j] * pc_yyzz[j] + pa_xz[j] * pc_yyyz[j] + 2.0 * pa_x[j] * pc_yyzz[j] * pb_y[j] + pa_x[j] * pc_yyyz[j] * pb_z[j] + pc_xyyz[j] * pa_yz[j] + 2.0 * pc_xyzz[j] * pa_y[j] * pb_y[j] + pc_xyyz[j] * pa_y[j] * pb_z[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_y[j] + pc_xyyy[j] * pa_z[j] * pb_z[j] + pc_xyzz[j] * pb_yy[j] + 2.0 * pc_xyyz[j] * pb_yz[j]);

                t_xyz_yyz[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xyyy[j] * fl1_fx - pa_x[j] * pc_yyyzz[j] - pc_xyyzz[j] * pa_y[j] - pc_xyyyz[j] * pa_z[j] - 2.0 * pc_xyyzz[j] * pb_y[j] - pc_xyyyz[j] * pb_z[j]);

                t_xyz_yyz[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_xyz_yzz[j] = fl_s_0_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xyz[j] * pb_y[j] * fl1_fx + pa_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_xyz[j] * pb_yzz[j]);

                t_xyz_yzz[j] += fl_s_0_0_1 * (-0.5 * pa_xz[j] * fl2_fx - 0.75 * pa_x[j] * fl2_fx * pc_z[j] - pa_x[j] * fl2_fx * pb_z[j] - 0.25 * pc_x[j] * fl2_fx * pa_z[j] - 0.5 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * pa_xyz[j] * pb_y[j] * fl1_fx - 0.5 * pa_xyz[j] * pc_y[j] * fl1_fx - 1.5 * pa_xy[j] * pc_z[j] * pb_y[j] * fl1_fx - pa_xy[j] * fl1_fx * pc_y[j] * pb_z[j] - pa_xy[j] * fl1_fx * pb_yz[j] - 0.5 * pa_xz[j] * pc_y[j] * pb_y[j] * fl1_fx - pa_x[j] * pc_y[j] * fl1_fx * pb_yz[j] - pa_xz[j] * fl1_fx * pb_z[j] * pc_z[j] - 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_zz[j] - 0.5 * pa_xz[j] * fl1_fx * pb_zz[j] - 0.5 * pc_x[j] * pa_yz[j] * pb_y[j] * fl1_fx - pc_x[j] * pa_y[j] * fl1_fx * pb_yz[j] - 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_zz[j] - 2.0 * pa_xyz[j] * pb_yz[j] * pc_z[j] - pa_xyz[j] * pc_y[j] * pb_zz[j] - pa_xy[j] * pc_z[j] * pb_yzz[j] - pa_xz[j] * pc_y[j] * pb_yzz[j] - pc_x[j] * pa_yz[j] * pb_yzz[j]);

                t_xyz_yzz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_z[j] + 0.25 * pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pc_x[j] * fl2_fx * pa_z[j] + 0.75 * pc_xz[j] * fl2_fx + pc_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xyz[j] * pc_y[j] * fl1_fx + 1.5 * pa_xy[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_xy[j] * pc_yz[j] * fl1_fx + pa_xy[j] * fl1_fx * pc_y[j] * pb_z[j] + 0.5 * pa_xz[j] * pc_y[j] * pb_y[j] * fl1_fx + 0.5 * pa_xz[j] * pc_yy[j] * fl1_fx + 1.5 * pa_x[j] * pc_yz[j] * pb_y[j] * fl1_fx + pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] + pa_x[j] * pc_y[j] * fl1_fx * pb_yz[j] + 0.5 * pa_xz[j] * fl1_fx * pc_zz[j] + pa_x[j] * fl1_fx * pc_zz[j] * pb_z[j] + pa_xz[j] * fl1_fx * pb_z[j] * pc_z[j] + 0.5 * pa_x[j] * fl1_fx * pc_z[j] * pb_zz[j] + 0.5 * pc_x[j] * pa_yz[j] * pb_y[j] * fl1_fx + 0.5 * pc_xy[j] * pa_yz[j] * fl1_fx + 1.5 * pc_xz[j] * pa_y[j] * pb_y[j] * fl1_fx + pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] + pc_x[j] * pa_y[j] * fl1_fx * pb_yz[j] + 0.5 * pc_xy[j] * pa_z[j] * pb_y[j] * fl1_fx + pc_xy[j] * fl1_fx * pb_yz[j] + pc_xz[j] * fl1_fx * pa_z[j] * pb_z[j] + 0.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pa_z[j] * pb_zz[j] + pa_xyz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xyz[j] * pc_yz[j] * pb_z[j] + 2.0 * pa_xy[j] * pc_zz[j] * pb_yz[j] + pa_xy[j] * pc_yz[j] * pb_zz[j] + 2.0 * pa_xz[j] * pc_yz[j] * pb_yz[j] + pa_xz[j] * pc_yy[j] * pb_zz[j] + pa_x[j] * pc_yz[j] * pb_yzz[j] + 2.0 * pc_xz[j] * pa_yz[j] * pb_yz[j] + pc_xy[j] * pa_yz[j] * pb_zz[j] + pc_xz[j] * pa_y[j] * pb_yzz[j] + pc_xy[j] * pa_z[j] * pb_yzz[j]);

                t_xyz_yzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_z[j] - 1.5 * pc_xz[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pa_z[j] - 0.5 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * pa_xy[j] * pc_yz[j] * fl1_fx - 0.5 * pa_xz[j] * pc_yy[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx - pa_x[j] * pc_yy[j] * fl1_fx * pb_z[j] - 0.5 * pa_x[j] * fl1_fx * pc_zzz[j] - 0.5 * pa_xz[j] * fl1_fx * pc_zz[j] - pa_x[j] * fl1_fx * pc_zz[j] * pb_z[j] - 0.5 * pc_xy[j] * pa_yz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_y[j] * pb_y[j] * fl1_fx - 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx - pc_xy[j] * pa_y[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * pa_z[j] * pb_y[j] * fl1_fx - 0.5 * pc_xyy[j] * pa_z[j] * fl1_fx - 1.5 * pc_xyz[j] * pb_y[j] * fl1_fx - pc_xyy[j] * fl1_fx * pb_z[j] - pc_xy[j] * fl1_fx * pb_yz[j] - 0.5 * pc_xzz[j] * fl1_fx * pa_z[j] - pc_xzz[j] * fl1_fx * pb_z[j] - pc_xz[j] * fl1_fx * pa_z[j] * pb_z[j] - 0.5 * pc_xz[j] * fl1_fx * pb_zz[j] - pa_xyz[j] * pc_yzz[j] - pa_xy[j] * pc_zzz[j] * pb_y[j] - 2.0 * pa_xy[j] * pc_yzz[j] * pb_z[j] - pa_xz[j] * pc_yzz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_yyz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_yzz[j] * pb_yz[j] - pa_x[j] * pc_yyz[j] * pb_zz[j] - pc_xzz[j] * pa_yz[j] * pb_y[j] - 2.0 * pc_xyz[j] * pa_yz[j] * pb_z[j] - 2.0 * pc_xzz[j] * pa_y[j] * pb_yz[j] - pc_xyz[j] * pa_y[j] * pb_zz[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_yz[j] - pc_xyy[j] * pa_z[j] * pb_zz[j] - pc_xyz[j] * pb_yzz[j]);

                t_xyz_yzz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_zzz[j] + 1.5 * pc_xyz[j] * pa_y[j] * fl1_fx + 0.5 * pc_xyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + pc_xyy[j] * fl1_fx * pb_z[j] + 0.5 * pc_xzzz[j] * fl1_fx + 0.5 * pc_xzz[j] * fl1_fx * pa_z[j] + pc_xzz[j] * fl1_fx * pb_z[j] + pa_xy[j] * pc_yzzz[j] + pa_xz[j] * pc_yyzz[j] + pa_x[j] * pc_yzzz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_yyzz[j] * pb_z[j] + pc_xyzz[j] * pa_yz[j] + pc_xzzz[j] * pa_y[j] * pb_y[j] + 2.0 * pc_xyzz[j] * pa_y[j] * pb_z[j] + pc_xyzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xyzz[j] * pb_yz[j] + pc_xyyz[j] * pb_zz[j]);

                t_xyz_yzz[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * pc_xzzz[j] * fl1_fx - pa_x[j] * pc_yyzzz[j] - pc_xyzzz[j] * pa_y[j] - pc_xyyzz[j] * pa_z[j] - pc_xyzzz[j] * pb_y[j] - 2.0 * pc_xyyzz[j] * pb_z[j]);

                t_xyz_yzz[j] += fl_s_0_0_6 * pc_xyyzzz[j];

                t_xyz_zzz[j] = fl_s_0_0_0 * (0.75 * pa_xy[j] * fl2_fx + 1.5 * pa_xyz[j] * pb_z[j] * fl1_fx + 1.5 * pa_xy[j] * fl1_fx * pb_zz[j] + pa_xyz[j] * pb_zzz[j]);

                t_xyz_zzz[j] += fl_s_0_0_1 * (-1.5 * pa_xy[j] * fl2_fx - 0.75 * pa_x[j] * pc_y[j] * fl2_fx - 0.75 * pc_x[j] * pa_y[j] * fl2_fx - 1.5 * pa_xyz[j] * pb_z[j] * fl1_fx - 1.5 * pa_xyz[j] * pc_z[j] * fl1_fx - 4.5 * pa_xy[j] * pc_z[j] * pb_z[j] * fl1_fx - 1.5 * pa_xy[j] * fl1_fx * pb_zz[j] - 1.5 * pa_xz[j] * pc_y[j] * pb_z[j] * fl1_fx - 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_zz[j] - 1.5 * pc_x[j] * pa_yz[j] * pb_z[j] * fl1_fx - 1.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_zz[j] - 3.0 * pa_xyz[j] * pb_zz[j] * pc_z[j] - pa_xy[j] * pc_z[j] * pb_zzz[j] - pa_xz[j] * pc_y[j] * pb_zzz[j] - pc_x[j] * pa_yz[j] * pb_zzz[j]);

                t_xyz_zzz[j] += fl_s_0_0_2 * (0.75 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_y[j] * fl2_fx + 1.5 * pc_x[j] * pa_y[j] * fl2_fx + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_xyz[j] * pc_z[j] * fl1_fx + 4.5 * pa_xy[j] * pc_z[j] * pb_z[j] * fl1_fx + 3.0 * pa_xy[j] * pc_zz[j] * fl1_fx + 1.5 * pa_xz[j] * pc_y[j] * pb_z[j] * fl1_fx + 1.5 * pa_xz[j] * pc_yz[j] * fl1_fx + 4.5 * pa_x[j] * pc_yz[j] * pb_z[j] * fl1_fx + 1.5 * pa_x[j] * pc_y[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * pa_yz[j] * pb_z[j] * fl1_fx + 1.5 * pc_xz[j] * pa_yz[j] * fl1_fx + 4.5 * pc_xz[j] * pa_y[j] * pb_z[j] * fl1_fx + 1.5 * pc_x[j] * pa_y[j] * fl1_fx * pb_zz[j] + 1.5 * pc_xy[j] * pa_z[j] * pb_z[j] * fl1_fx + 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 3.0 * pa_xyz[j] * pb_z[j] * pc_zz[j] + 3.0 * pa_xy[j] * pc_zz[j] * pb_zz[j] + 3.0 * pa_xz[j] * pc_yz[j] * pb_zz[j] + pa_x[j] * pc_yz[j] * pb_zzz[j] + 3.0 * pc_xz[j] * pa_yz[j] * pb_zz[j] + pc_xz[j] * pa_y[j] * pb_zzz[j] + pc_xy[j] * pa_z[j] * pb_zzz[j]);

                t_xyz_zzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_y[j] * fl2_fx - 0.75 * pc_x[j] * pa_y[j] * fl2_fx - 1.5 * pc_xy[j] * fl2_fx - 3.0 * pa_xy[j] * pc_zz[j] * fl1_fx - 1.5 * pa_xz[j] * pc_yz[j] * fl1_fx - 4.5 * pa_x[j] * pc_yz[j] * pb_z[j] * fl1_fx - 3.0 * pa_x[j] * pc_yzz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_yz[j] * fl1_fx - 4.5 * pc_xz[j] * pa_y[j] * pb_z[j] * fl1_fx - 3.0 * pc_xzz[j] * pa_y[j] * fl1_fx - 1.5 * pc_xy[j] * pa_z[j] * pb_z[j] * fl1_fx - 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx - 4.5 * pc_xyz[j] * pb_z[j] * fl1_fx - 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] - pa_xyz[j] * pc_zzz[j] - 3.0 * pa_xy[j] * pc_zzz[j] * pb_z[j] - 3.0 * pa_xz[j] * pc_yzz[j] * pb_z[j] - 3.0 * pa_x[j] * pc_yzz[j] * pb_zz[j] - 3.0 * pc_xzz[j] * pa_yz[j] * pb_z[j] - 3.0 * pc_xzz[j] * pa_y[j] * pb_zz[j] - 3.0 * pc_xyz[j] * pa_z[j] * pb_zz[j] - pc_xyz[j] * pb_zzz[j]);

                t_xyz_zzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 3.0 * pa_x[j] * pc_yzz[j] * fl1_fx + 3.0 * pc_xzz[j] * pa_y[j] * fl1_fx + 1.5 * pc_xyz[j] * pa_z[j] * fl1_fx + 4.5 * pc_xyz[j] * pb_z[j] * fl1_fx + 3.0 * pc_xyzz[j] * fl1_fx + pa_xy[j] * pc_zzzz[j] + pa_xz[j] * pc_yzzz[j] + 3.0 * pa_x[j] * pc_yzzz[j] * pb_z[j] + pc_xzzz[j] * pa_yz[j] + 3.0 * pc_xzzz[j] * pa_y[j] * pb_z[j] + 3.0 * pc_xyzz[j] * pa_z[j] * pb_z[j] + 3.0 * pc_xyzz[j] * pb_zz[j]);

                t_xyz_zzz[j] += fl_s_0_0_5 * (-3.0 * pc_xyzz[j] * fl1_fx - pa_x[j] * pc_yzzzz[j] - pc_xzzzz[j] * pa_y[j] - pc_xyzzz[j] * pa_z[j] - 3.0 * pc_xyzzz[j] * pb_z[j]);

                t_xyz_zzz[j] += fl_s_0_0_6 * pc_xyzzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_50_60(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (50,60)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(19 * idx + 5);

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xzz = paDistances.data(19 * idx + 14);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxx = pcDistances.data(83 * idx + 19);

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxxz = pcDistances.data(83 * idx + 36);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_xzzzz = pcDistances.data(83 * idx + 48);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            auto pc_yzzzz = pcDistances.data(83 * idx + 53);

            auto pc_zzzzz = pcDistances.data(83 * idx + 54);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxxzz = pcDistances.data(83 * idx + 60);

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxxzzz = pcDistances.data(83 * idx + 64);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            auto pc_xxzzzz = pcDistances.data(83 * idx + 69);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            auto pc_xyzzzz = pcDistances.data(83 * idx + 74);

            auto pc_xzzzzz = pcDistances.data(83 * idx + 75);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_xzz_xxx = primBuffer.data(100 * idx + 50);

            auto t_xzz_xxy = primBuffer.data(100 * idx + 51);

            auto t_xzz_xxz = primBuffer.data(100 * idx + 52);

            auto t_xzz_xyy = primBuffer.data(100 * idx + 53);

            auto t_xzz_xyz = primBuffer.data(100 * idx + 54);

            auto t_xzz_xzz = primBuffer.data(100 * idx + 55);

            auto t_xzz_yyy = primBuffer.data(100 * idx + 56);

            auto t_xzz_yyz = primBuffer.data(100 * idx + 57);

            auto t_xzz_yzz = primBuffer.data(100 * idx + 58);

            auto t_xzz_zzz = primBuffer.data(100 * idx + 59);

            // Batch of Integrals (50,60)

            #pragma omp simd aligned(fx, pa_x, pa_xz, pa_xzz, pa_z, pa_zz, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxx, pc_xxxxz, pc_xxxxzz, pc_xxxy, pc_xxxyz, \
                                     pc_xxxyzz, pc_xxxz, pc_xxxzz, pc_xxxzzz, pc_xxy, pc_xxyy, pc_xxyyz, pc_xxyyzz, \
                                     pc_xxyz, pc_xxyzz, pc_xxyzzz, pc_xxz, pc_xxzz, pc_xxzzz, pc_xxzzzz, pc_xy, pc_xyy, \
                                     pc_xyyy, pc_xyyyz, pc_xyyyzz, pc_xyyz, pc_xyyzz, pc_xyyzzz, pc_xyz, pc_xyzz, \
                                     pc_xyzzz, pc_xyzzzz, pc_xz, pc_xzz, pc_xzzz, pc_xzzzz, pc_xzzzzz, pc_y, pc_yy, pc_yyy, \
                                     pc_yyyz, pc_yyyzz, pc_yyz, pc_yyzz, pc_yyzzz, pc_yz, pc_yzz, pc_yzzz, pc_yzzzz, pc_z, \
                                     pc_zz, pc_zzz, pc_zzzz, pc_zzzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, \
                                     s_0_0_5, s_0_0_6, t_xzz_xxx, t_xzz_xxy, t_xzz_xxz, t_xzz_xyy, t_xzz_xyz, \
                                     t_xzz_xzz, t_xzz_yyy, t_xzz_yyz, t_xzz_yzz, t_xzz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xzz_xxx[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xzz[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_zz[j] * pb_xx[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] + pa_xzz[j] * pb_xxx[j]);

                t_xzz_xxx[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * fl2_fx * pa_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 2.25 * pc_x[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pb_xx[j] - 1.5 * pa_xzz[j] * pb_x[j] * fl1_fx - 1.5 * pa_xzz[j] * pc_x[j] * fl1_fx - 3.0 * pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx - 4.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx - 3.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xx[j] - 1.5 * fl1_fx * pa_zz[j] * pb_xx[j] - 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_xzz[j] * pb_xx[j] * pc_x[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xxx[j] - pc_x[j] * pa_zz[j] * pb_xxx[j]);

                t_xzz_xxx[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 3.0 * fl2_fx * pa_z[j] * pc_z[j] + 0.75 * fl2_fx * pc_zz[j] + 0.75 * fl2_fx * pa_zz[j] + 1.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 4.5 * pc_x[j] * fl2_fx * pb_x[j] + 1.5 * pc_xx[j] * fl2_fx + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xzz[j] * pc_x[j] * fl1_fx + 3.0 * pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx + 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx + 1.5 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx + 4.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xx[j] * pa_zz[j] * fl1_fx + 9.0 * pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pc_zz[j] * pb_xx[j] + 3.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xx[j] + 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_xx[j] + 1.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_x[j] + 1.5 * pc_xx[j] * fl1_fx * pb_xx[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_xzz[j] * pb_x[j] * pc_xx[j] + 6.0 * pa_xz[j] * pc_xz[j] * pb_xx[j] + pa_x[j] * pc_zz[j] * pb_xxx[j] + 3.0 * pc_xx[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xxx[j]);

                t_xzz_xxx[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 3.0 * pc_xx[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_x[j] - 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx - 1.5 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx - 1.5 * pa_x[j] * pc_xzz[j] * fl1_fx - 3.0 * pc_xx[j] * pa_zz[j] * fl1_fx - 9.0 * pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx - 6.0 * pc_xxz[j] * pa_z[j] * fl1_fx - 4.5 * pc_xzz[j] * pb_x[j] * fl1_fx - 1.5 * fl1_fx * pc_zz[j] * pb_xx[j] - 0.5 * pa_x[j] * fl1_fx * pc_xxx[j] - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_xx[j] - 1.5 * pc_xxx[j] * fl1_fx * pb_x[j] - 1.5 * pc_xx[j] * fl1_fx * pb_xx[j] - pa_xzz[j] * pc_xxx[j] - 6.0 * pa_xz[j] * pc_xxz[j] * pb_x[j] - 3.0 * pa_x[j] * pc_xzz[j] * pb_xx[j] - 3.0 * pc_xxx[j] * pa_zz[j] * pb_x[j] - 6.0 * pc_xxz[j] * pa_z[j] * pb_xx[j] - pc_xzz[j] * pb_xxx[j]);

                t_xzz_xxx[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_zz[j] + 1.5 * pc_xx[j] * fl2_fx + 1.5 * pa_x[j] * pc_xzz[j] * fl1_fx + 6.0 * pc_xxz[j] * pa_z[j] * fl1_fx + 4.5 * pc_xzz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xxzz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_xxx[j] + 0.5 * pc_xxxx[j] * fl1_fx + 1.5 * pc_xxx[j] * fl1_fx * pb_x[j] + 2.0 * pa_xz[j] * pc_xxxz[j] + 3.0 * pa_x[j] * pc_xxzz[j] * pb_x[j] + pc_xxxx[j] * pa_zz[j] + 6.0 * pc_xxxz[j] * pa_z[j] * pb_x[j] + 3.0 * pc_xxzz[j] * pb_xx[j]);

                t_xzz_xxx[j] += fl_s_0_0_5 * (-3.0 * pc_xxzz[j] * fl1_fx - 0.5 * pc_xxxx[j] * fl1_fx - pa_x[j] * pc_xxxzz[j] - 2.0 * pc_xxxxz[j] * pa_z[j] - 3.0 * pc_xxxzz[j] * pb_x[j]);

                t_xzz_xxx[j] += fl_s_0_0_6 * pc_xxxxzz[j];

                t_xzz_xxy[j] = fl_s_0_0_0 * (0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xzz[j] * fl1_fx * pb_y[j] + fl1_fx * pa_zz[j] * pb_xy[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxy[j] + pa_xzz[j] * pb_xxy[j]);

                t_xzz_xxy[j] += fl_s_0_0_1 * (-0.25 * pa_x[j] * fl2_fx * pc_y[j] - 0.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pb_x[j] * pc_y[j] - fl2_fx * pb_xy[j] - 0.5 * pa_xzz[j] * fl1_fx * pc_y[j] - 0.5 * pa_xzz[j] * fl1_fx * pb_y[j] - pa_xz[j] * pc_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_y[j] - fl1_fx * pa_zz[j] * pb_x[j] * pc_y[j] - 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xy[j] - fl1_fx * pa_zz[j] * pb_xy[j] - 0.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_y[j] - pa_x[j] * fl1_fx * pb_xy[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxy[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxy[j] - pa_xzz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_xzz[j] * pb_xy[j] * pc_x[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xxy[j] - pc_x[j] * pa_zz[j] * pb_xxy[j]);

                t_xzz_xxy[j] += fl_s_0_0_2 * (0.5 * pa_x[j] * fl2_fx * pc_y[j] + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + fl2_fx * pb_x[j] * pc_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xzz[j] * fl1_fx * pc_y[j] + pa_xz[j] * pc_yz[j] * fl1_fx + pa_xz[j] * pc_z[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 1.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_y[j] + 3.0 * pc_xz[j] * pa_z[j] * fl1_fx * pb_y[j] + 2.0 * fl1_fx * pa_z[j] * pc_yz[j] * pb_x[j] + fl1_fx * pc_zz[j] * pb_xy[j] + fl1_fx * pa_zz[j] * pb_x[j] * pc_y[j] + 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xy[j] + pa_x[j] * fl1_fx * pb_x[j] * pc_xy[j] + 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] * pc_y[j] + pa_x[j] * fl1_fx * pb_xy[j] * pc_x[j] + 0.5 * pc_xy[j] * fl1_fx * pb_xx[j] + pc_xx[j] * fl1_fx * pb_xy[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_xzz[j] * pb_x[j] * pc_xy[j] + pa_xzz[j] * pc_xx[j] * pb_y[j] + 2.0 * pa_xz[j] * pc_yz[j] * pb_xx[j] + 4.0 * pa_xz[j] * pc_xz[j] * pb_xy[j] + pa_x[j] * pc_zz[j] * pb_xxy[j] + pc_xy[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_zz[j] * pb_xy[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xxy[j]);

                t_xzz_xxy[j] += fl_s_0_0_3 * (-0.25 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pb_x[j] * pc_y[j] - pa_xz[j] * pc_yz[j] * fl1_fx - 0.5 * pa_x[j] * pc_yzz[j] * fl1_fx - 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 3.0 * pc_xz[j] * pa_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] - fl1_fx * pc_yzz[j] * pb_x[j] - 2.0 * fl1_fx * pa_z[j] * pc_yz[j] * pb_x[j] - fl1_fx * pc_zz[j] * pb_xy[j] - 0.5 * pa_x[j] * fl1_fx * pc_xxy[j] - pa_x[j] * fl1_fx * pb_x[j] * pc_xy[j] - 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_y[j] - pc_xxy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] - 0.5 * pc_xy[j] * fl1_fx * pb_xx[j] - pc_xx[j] * fl1_fx * pb_xy[j] - pa_xzz[j] * pc_xxy[j] - 4.0 * pa_xz[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xxz[j] * pb_y[j] - pa_x[j] * pc_yzz[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xzz[j] * pb_xy[j] - 2.0 * pc_xxy[j] * pa_zz[j] * pb_x[j] - pc_xxx[j] * pa_zz[j] * pb_y[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_xx[j] - 4.0 * pc_xxz[j] * pa_z[j] * pb_xy[j] - pc_xzz[j] * pb_xxy[j]);

                t_xzz_xxy[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_x[j] * pc_yzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pb_y[j] + fl1_fx * pc_yzz[j] * pb_x[j] + 0.5 * pa_x[j] * fl1_fx * pc_xxy[j] + 0.5 * pc_xxxy[j] * fl1_fx + pc_xxy[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_y[j] + 2.0 * pa_xz[j] * pc_xxyz[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_x[j] + pa_x[j] * pc_xxzz[j] * pb_y[j] + pc_xxxy[j] * pa_zz[j] + 4.0 * pc_xxyz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxxz[j] * pa_z[j] * pb_y[j] + pc_xyzz[j] * pb_xx[j] + 2.0 * pc_xxzz[j] * pb_xy[j]);

                t_xzz_xxy[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xxxy[j] * fl1_fx - pa_x[j] * pc_xxyzz[j] - 2.0 * pc_xxxyz[j] * pa_z[j] - 2.0 * pc_xxyzz[j] * pb_x[j] - pc_xxxzz[j] * pb_y[j]);

                t_xzz_xxy[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_xzz_xxz[j] = fl_s_0_0_0 * (0.5 * pa_xz[j] * fl2_fx + fl2_fx * pa_z[j] * pb_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xzz[j] * fl1_fx * pb_z[j] + pa_xz[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_zz[j] * pb_xz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxz[j] + pa_xzz[j] * pb_xxz[j]);

                t_xzz_xxz[j] += fl_s_0_0_1 * (-pa_xz[j] * fl2_fx - 0.75 * pa_x[j] * pc_z[j] * fl2_fx - 1.5 * pc_x[j] * pa_z[j] * fl2_fx - 2.0 * fl2_fx * pa_z[j] * pb_x[j] - 1.5 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - fl2_fx * pb_xz[j] - 0.5 * pa_xzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xzz[j] * fl1_fx * pb_z[j] - pa_xz[j] * pc_z[j] * fl1_fx * pb_z[j] - 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_x[j] - pa_xz[j] * fl1_fx * pb_xx[j] - 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_xx[j] - 1.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_z[j] - pc_x[j] * pa_z[j] * fl1_fx * pb_xx[j] - fl1_fx * pa_zz[j] * pb_x[j] * pc_z[j] - 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xz[j] - fl1_fx * pa_zz[j] * pb_xz[j] - pa_x[j] * fl1_fx * pb_xz[j] * pc_x[j] - 0.5 * pa_x[j] * fl1_fx * pb_xxz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xxz[j] - pa_xzz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_xzz[j] * pb_xz[j] * pc_x[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xxz[j] - pc_x[j] * pa_zz[j] * pb_xxz[j]);

                t_xzz_xxz[j] += fl_s_0_0_2 * (0.5 * pa_xz[j] * fl2_fx + 1.5 * pa_x[j] * pc_z[j] * fl2_fx + 3.0 * pc_x[j] * pa_z[j] * fl2_fx + 2.25 * pc_xz[j] * fl2_fx + 3.0 * fl2_fx * pc_z[j] * pb_x[j] + fl2_fx * pa_z[j] * pb_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xzz[j] * fl1_fx * pc_z[j] + pa_xz[j] * pc_zz[j] * fl1_fx + pa_xz[j] * pc_z[j] * fl1_fx * pb_z[j] + pa_xz[j] * fl1_fx * pc_xx[j] + 2.0 * pa_xz[j] * fl1_fx * pb_x[j] * pc_x[j] + 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] + 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xz[j] * pa_zz[j] * fl1_fx + 1.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_z[j] + 3.0 * pc_xz[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_x[j] + pc_x[j] * pa_z[j] * fl1_fx * pb_xx[j] + 1.5 * pc_xz[j] * fl1_fx * pb_xx[j] + 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_x[j] + fl1_fx * pc_zz[j] * pb_xz[j] + fl1_fx * pa_zz[j] * pb_x[j] * pc_z[j] + 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xz[j] + 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_z[j] + pa_x[j] * fl1_fx * pb_xz[j] * pc_x[j] + pc_xx[j] * fl1_fx * pb_xz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_xzz[j] * pb_x[j] * pc_xz[j] + pa_xzz[j] * pc_xx[j] * pb_z[j] + 2.0 * pa_xz[j] * pc_zz[j] * pb_xx[j] + 4.0 * pa_xz[j] * pc_xz[j] * pb_xz[j] + pa_x[j] * pc_zz[j] * pb_xxz[j] + pc_xz[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_xx[j] * pa_zz[j] * pb_xz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xxz[j]);

                t_xzz_xxz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_z[j] * fl2_fx - 1.5 * pc_x[j] * pa_z[j] * fl2_fx - 4.5 * pc_xz[j] * fl2_fx - 1.5 * fl2_fx * pc_z[j] * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_z[j] - pa_xz[j] * pc_zz[j] * fl1_fx - pa_xz[j] * fl1_fx * pc_xx[j] - 0.5 * pa_x[j] * pc_zzz[j] * fl1_fx - 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_z[j] - 1.5 * pa_x[j] * pc_xxz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xz[j] * pa_zz[j] * fl1_fx - 3.0 * pc_xzz[j] * pa_z[j] * fl1_fx - 3.0 * pc_xz[j] * pa_z[j] * fl1_fx * pb_z[j] - pc_xxx[j] * pa_z[j] * fl1_fx - 2.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_x[j] - 1.5 * pc_xzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xxz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xz[j] * fl1_fx * pb_xx[j] - fl1_fx * pc_zzz[j] * pb_x[j] - 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_x[j] - fl1_fx * pc_zz[j] * pb_xz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xx[j] * pb_z[j] - 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] - pc_xx[j] * fl1_fx * pb_xz[j] - pa_xzz[j] * pc_xxz[j] - 4.0 * pa_xz[j] * pc_xzz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xxz[j] * pb_z[j] - pa_x[j] * pc_zzz[j] * pb_xx[j] - 2.0 * pa_x[j] * pc_xzz[j] * pb_xz[j] - 2.0 * pc_xxz[j] * pa_zz[j] * pb_x[j] - pc_xxx[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_xzz[j] * pa_z[j] * pb_xx[j] - 4.0 * pc_xxz[j] * pa_z[j] * pb_xz[j] - pc_xzz[j] * pb_xxz[j]);

                t_xzz_xxz[j] += fl_s_0_0_4 * (2.25 * pc_xz[j] * fl2_fx + 0.5 * pa_x[j] * pc_zzz[j] * fl1_fx + 1.5 * pa_x[j] * pc_xxz[j] * fl1_fx + 3.0 * pc_xzz[j] * pa_z[j] * fl1_fx + pc_xxx[j] * pa_z[j] * fl1_fx + 1.5 * pc_xzzz[j] * fl1_fx + 1.5 * pc_xzz[j] * fl1_fx * pb_z[j] + 1.5 * pc_xxxz[j] * fl1_fx + 3.0 * pc_xxz[j] * fl1_fx * pb_x[j] + fl1_fx * pc_zzz[j] * pb_x[j] + 0.5 * pc_xxx[j] * fl1_fx * pb_z[j] + 2.0 * pa_xz[j] * pc_xxzz[j] + 2.0 * pa_x[j] * pc_xzzz[j] * pb_x[j] + pa_x[j] * pc_xxzz[j] * pb_z[j] + pc_xxxz[j] * pa_zz[j] + 4.0 * pc_xxzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxxz[j] * pa_z[j] * pb_z[j] + pc_xzzz[j] * pb_xx[j] + 2.0 * pc_xxzz[j] * pb_xz[j]);

                t_xzz_xxz[j] += fl_s_0_0_5 * (-1.5 * pc_xzzz[j] * fl1_fx - 1.5 * pc_xxxz[j] * fl1_fx - pa_x[j] * pc_xxzzz[j] - 2.0 * pc_xxxzz[j] * pa_z[j] - 2.0 * pc_xxzzz[j] * pb_x[j] - pc_xxxzz[j] * pb_z[j]);

                t_xzz_xxz[j] += fl_s_0_0_6 * pc_xxxzzz[j];

                t_xzz_xyy[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * fl2_fx * pa_zz[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xzz[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_zz[j] * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pb_xyy[j] + pa_xzz[j] * pb_xyy[j]);

                t_xzz_xyy[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * fl2_fx * pa_zz[j] - 0.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pb_y[j] * pc_y[j] - 0.5 * fl2_fx * pb_yy[j] - 0.5 * pa_xzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xzz[j] * pc_x[j] * fl1_fx - pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx - 0.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx - fl1_fx * pa_zz[j] * pb_y[j] * pc_y[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_yy[j] - 0.5 * fl1_fx * pa_zz[j] * pb_yy[j] - pa_x[j] * fl1_fx * pb_xy[j] * pc_y[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pb_xyy[j] - 0.5 * pc_x[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_xzz[j] * pb_xy[j] * pc_y[j] - pa_xzz[j] * pc_x[j] * pb_yy[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xyy[j] - pc_x[j] * pa_zz[j] * pb_xyy[j]);

                t_xzz_xyy[j] += fl_s_0_0_2 * (0.375 * fl3_fx + fl2_fx * pa_z[j] * pc_z[j] + 0.25 * fl2_fx * pc_zz[j] + 0.25 * fl2_fx * pa_zz[j] + 0.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.5 * pc_x[j] * fl2_fx * pb_x[j] + 0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_yy[j] + fl2_fx * pb_y[j] * pc_y[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xzz[j] * pc_x[j] * fl1_fx + pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx + pa_xz[j] * pc_xz[j] * fl1_fx + 0.5 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx + 0.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_zz[j] * fl1_fx + pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_zz[j] * pc_yy[j] + 2.0 * fl1_fx * pa_z[j] * pc_yz[j] * pb_y[j] + 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] + fl1_fx * pa_zz[j] * pb_y[j] * pc_y[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yy[j] + pa_x[j] * fl1_fx * pc_xy[j] * pb_y[j] + pa_x[j] * fl1_fx * pb_xy[j] * pc_y[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yy[j] + pc_xy[j] * fl1_fx * pb_xy[j] + 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] + 0.5 * pc_x[j] * fl1_fx * pb_xyy[j] + pa_xzz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_xzz[j] * pc_xy[j] * pb_y[j] + 4.0 * pa_xz[j] * pc_yz[j] * pb_xy[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_yy[j] + pa_x[j] * pc_zz[j] * pb_xyy[j] + 2.0 * pc_xy[j] * pa_zz[j] * pb_xy[j] + pc_xx[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xyy[j]);

                t_xzz_xyy[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * fl2_fx * pc_zz[j] - 0.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * pa_x[j] * fl2_fx * pc_x[j] - 0.5 * pc_xx[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pc_yy[j] - 0.5 * fl2_fx * pb_y[j] * pc_y[j] - pa_xz[j] * pc_xz[j] * fl1_fx - 0.5 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx - 0.5 * pa_x[j] * pc_xzz[j] * fl1_fx - 0.5 * pc_xx[j] * pa_zz[j] * fl1_fx - pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx - pc_xxz[j] * pa_z[j] * fl1_fx - 0.5 * pc_xzz[j] * pb_x[j] * fl1_fx - fl1_fx * pa_z[j] * pc_yyz[j] - fl1_fx * pc_yzz[j] * pb_y[j] - 0.5 * fl1_fx * pa_zz[j] * pc_yy[j] - 2.0 * fl1_fx * pa_z[j] * pc_yz[j] * pb_y[j] - 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pc_xyy[j] - 0.5 * pa_x[j] * fl1_fx * pb_x[j] * pc_yy[j] - pa_x[j] * fl1_fx * pc_xy[j] * pb_y[j] - 0.5 * pc_xyy[j] * fl1_fx * pb_x[j] - pc_xxy[j] * fl1_fx * pb_y[j] - pc_xy[j] * fl1_fx * pb_xy[j] - 0.5 * pc_xx[j] * fl1_fx * pb_yy[j] - pa_xzz[j] * pc_xyy[j] - 2.0 * pa_xz[j] * pc_yyz[j] * pb_x[j] - 4.0 * pa_xz[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_x[j] * pc_yzz[j] * pb_xy[j] - pa_x[j] * pc_xzz[j] * pb_yy[j] - pc_xyy[j] * pa_zz[j] * pb_x[j] - 2.0 * pc_xxy[j] * pa_zz[j] * pb_y[j] - 4.0 * pc_xyz[j] * pa_z[j] * pb_xy[j] - 2.0 * pc_xxz[j] * pa_z[j] * pb_yy[j] - pc_xzz[j] * pb_xyy[j]);

                t_xzz_xyy[j] += fl_s_0_0_4 * (0.25 * fl2_fx * pc_zz[j] + 0.25 * pc_xx[j] * fl2_fx + 0.25 * fl2_fx * pc_yy[j] + 0.5 * pa_x[j] * pc_xzz[j] * fl1_fx + pc_xxz[j] * pa_z[j] * fl1_fx + 0.5 * pc_xzz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xxzz[j] * fl1_fx + 0.5 * fl1_fx * pc_yyzz[j] + fl1_fx * pa_z[j] * pc_yyz[j] + fl1_fx * pc_yzz[j] * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pc_xyy[j] + 0.5 * pc_xxyy[j] * fl1_fx + 0.5 * pc_xyy[j] * fl1_fx * pb_x[j] + pc_xxy[j] * fl1_fx * pb_y[j] + 2.0 * pa_xz[j] * pc_xyyz[j] + pa_x[j] * pc_yyzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xyzz[j] * pb_y[j] + pc_xxyy[j] * pa_zz[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_x[j] + 4.0 * pc_xxyz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xyzz[j] * pb_xy[j] + pc_xxzz[j] * pb_yy[j]);

                t_xzz_xyy[j] += fl_s_0_0_5 * (-0.5 * pc_xxzz[j] * fl1_fx - 0.5 * fl1_fx * pc_yyzz[j] - 0.5 * pc_xxyy[j] * fl1_fx - pa_x[j] * pc_xyyzz[j] - 2.0 * pc_xxyyz[j] * pa_z[j] - pc_xyyzz[j] * pb_x[j] - 2.0 * pc_xxyzz[j] * pb_y[j]);

                t_xzz_xyy[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_xzz_xyz[j] = fl_s_0_0_0 * (0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.25 * fl2_fx * pb_yz[j] + pa_xz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xyz[j] + pa_xzz[j] * pb_xyz[j]);

                t_xzz_xyz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_z[j] * pc_y[j] - fl2_fx * pa_z[j] * pb_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_z[j] - 0.5 * fl2_fx * pb_yz[j] - pa_xz[j] * fl1_fx * pb_x[j] * pc_y[j] - pa_xz[j] * fl1_fx * pc_x[j] * pb_y[j] - pa_xz[j] * fl1_fx * pb_xy[j] - 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_xy[j] - pc_x[j] * pa_z[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pa_zz[j] * pb_y[j] * pc_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_y[j] * pb_z[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_yz[j] - 0.5 * fl1_fx * pa_zz[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xz[j] * pc_y[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xyz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xyz[j] - pa_xzz[j] * pb_xy[j] * pc_z[j] - pa_xzz[j] * pb_xz[j] * pc_y[j] - pa_xzz[j] * pc_x[j] * pb_yz[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xyz[j] - pc_x[j] * pa_zz[j] * pb_xyz[j]);

                t_xzz_xyz[j] += fl_s_0_0_2 * (fl2_fx * pa_z[j] * pc_y[j] + 0.75 * fl2_fx * pc_yz[j] + 1.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pc_y[j] * pb_z[j] + 0.25 * fl2_fx * pb_yz[j] + pa_xz[j] * fl1_fx * pc_xy[j] + pa_xz[j] * fl1_fx * pb_x[j] * pc_y[j] + pa_xz[j] * fl1_fx * pc_x[j] * pb_y[j] + 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_x[j] + 1.5 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] + 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_xy[j] + pc_xy[j] * pa_z[j] * fl1_fx * pb_x[j] + pc_xx[j] * pa_z[j] * fl1_fx * pb_y[j] + pc_x[j] * pa_z[j] * fl1_fx * pb_xy[j] + 1.5 * pc_xz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pc_yz[j] + fl1_fx * pa_z[j] * pc_zz[j] * pb_y[j] + fl1_fx * pa_z[j] * pc_yz[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_yz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_y[j] * pc_z[j] + 0.5 * fl1_fx * pa_zz[j] * pc_y[j] * pb_z[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pc_xy[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xz[j] * pc_y[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_yz[j] + 0.5 * pc_xy[j] * fl1_fx * pb_xz[j] + 0.5 * pc_xx[j] * fl1_fx * pb_yz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xyz[j] + pa_xzz[j] * pb_x[j] * pc_yz[j] + pa_xzz[j] * pc_xz[j] * pb_y[j] + pa_xzz[j] * pc_xy[j] * pb_z[j] + 2.0 * pa_xz[j] * pc_zz[j] * pb_xy[j] + 2.0 * pa_xz[j] * pc_yz[j] * pb_xz[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_yz[j] + pa_x[j] * pc_zz[j] * pb_xyz[j] + pc_xz[j] * pa_zz[j] * pb_xy[j] + pc_xy[j] * pa_zz[j] * pb_xz[j] + pc_xx[j] * pa_zz[j] * pb_yz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xyz[j]);

                t_xzz_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_yz[j] - 0.5 * fl2_fx * pa_z[j] * pc_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 0.25 * fl2_fx * pc_y[j] * pb_z[j] - pa_xz[j] * fl1_fx * pc_xy[j] - 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx - 1.5 * pa_x[j] * pc_yz[j] * fl1_fx * pb_x[j] - 1.5 * pa_x[j] * pc_xz[j] * fl1_fx * pb_y[j] - pc_xxy[j] * pa_z[j] * fl1_fx - pc_xy[j] * pa_z[j] * fl1_fx * pb_x[j] - pc_xx[j] * pa_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xxz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xz[j] * fl1_fx * pb_xy[j] - fl1_fx * pa_z[j] * pc_yzz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] - 0.5 * fl1_fx * pc_yzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_yz[j] - fl1_fx * pa_z[j] * pc_zz[j] * pb_y[j] - fl1_fx * pa_z[j] * pc_yz[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pc_xy[j] * pb_z[j] - 0.5 * pc_xxy[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * fl1_fx * pb_xz[j] - 0.5 * pc_xx[j] * fl1_fx * pb_yz[j] - pa_xzz[j] * pc_xyz[j] - 2.0 * pa_xz[j] * pc_yzz[j] * pb_x[j] - 2.0 * pa_xz[j] * pc_xzz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_xyz[j] * pb_z[j] - pa_x[j] * pc_zzz[j] * pb_xy[j] - pa_x[j] * pc_yzz[j] * pb_xz[j] - pa_x[j] * pc_xzz[j] * pb_yz[j] - pc_xyz[j] * pa_zz[j] * pb_x[j] - pc_xxz[j] * pa_zz[j] * pb_y[j] - pc_xxy[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_xzz[j] * pa_z[j] * pb_xy[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_xz[j] - 2.0 * pc_xxz[j] * pa_z[j] * pb_yz[j] - pc_xzz[j] * pb_xyz[j]);

                t_xzz_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_yz[j] + 1.5 * pa_x[j] * pc_xyz[j] * fl1_fx + pc_xxy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xxyz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_yzzz[j] + fl1_fx * pa_z[j] * pc_yzz[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] + 0.5 * fl1_fx * pc_yzz[j] * pb_z[j] + 0.5 * pc_xxy[j] * fl1_fx * pb_z[j] + 2.0 * pa_xz[j] * pc_xyzz[j] + pa_x[j] * pc_yzzz[j] * pb_x[j] + pa_x[j] * pc_xzzz[j] * pb_y[j] + pa_x[j] * pc_xyzz[j] * pb_z[j] + pc_xxyz[j] * pa_zz[j] + 2.0 * pc_xyzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_z[j] + pc_xzzz[j] * pb_xy[j] + pc_xyzz[j] * pb_xz[j] + pc_xxzz[j] * pb_yz[j]);

                t_xzz_xyz[j] += fl_s_0_0_5 * (-1.5 * pc_xxyz[j] * fl1_fx - 0.5 * fl1_fx * pc_yzzz[j] - pa_x[j] * pc_xyzzz[j] - 2.0 * pc_xxyzz[j] * pa_z[j] - pc_xyzzz[j] * pb_x[j] - pc_xxzzz[j] * pb_y[j] - pc_xxyzz[j] * pb_z[j]);

                t_xzz_xyz[j] += fl_s_0_0_6 * pc_xxyzzz[j];

                t_xzz_xzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xzz[j] * pb_x[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xzz[j] + pa_xzz[j] * pb_xzz[j]);

                t_xzz_xzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 1.5 * pa_x[j] * fl2_fx * pb_x[j] - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pa_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 2.0 * fl2_fx * pa_z[j] * pb_z[j] - 1.5 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_zz[j] - 0.5 * pa_xzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_xzz[j] * pc_x[j] * fl1_fx - 3.0 * pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx - 2.0 * pa_xz[j] * fl1_fx * pc_x[j] * pb_z[j] - 2.0 * pa_xz[j] * fl1_fx * pb_xz[j] - 3.0 * pa_x[j] * pc_z[j] * fl1_fx * pb_xz[j] - 0.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx - 2.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_xz[j] - fl1_fx * pa_zz[j] * pb_z[j] * pc_z[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_zz[j] - 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pb_xzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_xzz[j] * pb_xz[j] * pc_z[j] - pa_xzz[j] * pc_x[j] * pb_zz[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_xzz[j] - pc_x[j] * pa_zz[j] * pb_xzz[j]);

                t_xzz_xzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 1.5 * pa_x[j] * fl2_fx * pc_x[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * pc_xx[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_x[j] + 3.0 * fl2_fx * pa_z[j] * pc_z[j] + 1.5 * fl2_fx * pc_zz[j] + 3.0 * fl2_fx * pc_z[j] * pb_z[j] + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xzz[j] * pc_x[j] * fl1_fx + 3.0 * pa_xz[j] * pc_z[j] * pb_x[j] * fl1_fx + 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pc_x[j] * pb_z[j] + 3.0 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx + 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_z[j] * fl1_fx * pb_xz[j] + 0.5 * pc_x[j] * pa_zz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xx[j] * pa_zz[j] * fl1_fx + 3.0 * pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx + 2.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_xz[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_zz[j] * pc_zz[j] + 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_zz[j] + fl1_fx * pa_zz[j] * pb_z[j] * pc_z[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pc_x[j] * pb_zz[j] + 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pb_xzz[j] + pa_xzz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_xzz[j] * pc_xz[j] * pb_z[j] + 4.0 * pa_xz[j] * pc_zz[j] * pb_xz[j] + 2.0 * pa_xz[j] * pc_xz[j] * pb_zz[j] + pa_x[j] * pc_zz[j] * pb_xzz[j] + 2.0 * pc_xz[j] * pa_zz[j] * pb_xz[j] + pc_xx[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_xzz[j]);

                t_xzz_xzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 0.75 * pa_x[j] * fl2_fx * pc_x[j] - 1.5 * pc_xx[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_x[j] - 3.0 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 1.5 * fl2_fx * pc_z[j] * pb_z[j] - 3.0 * pa_xz[j] * pc_xz[j] * fl1_fx - 3.0 * pa_x[j] * pc_zz[j] * pb_x[j] * fl1_fx - 3.0 * pa_x[j] * pc_xzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_xz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xx[j] * pa_zz[j] * fl1_fx - 3.0 * pc_xz[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxz[j] * pa_z[j] * fl1_fx - 2.0 * pc_xx[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_xzz[j] * pb_x[j] * fl1_fx - 3.0 * pc_xxz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] - fl1_fx * pa_z[j] * pc_zzz[j] - fl1_fx * pc_zzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_zz[j] - 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_zz[j] - 0.5 * pc_xx[j] * fl1_fx * pb_zz[j] - pa_xzz[j] * pc_xzz[j] - 2.0 * pa_xz[j] * pc_zzz[j] * pb_x[j] - 4.0 * pa_xz[j] * pc_xzz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_zzz[j] * pb_xz[j] - pa_x[j] * pc_xzz[j] * pb_zz[j] - pc_xzz[j] * pa_zz[j] * pb_x[j] - 2.0 * pc_xxz[j] * pa_zz[j] * pb_z[j] - 4.0 * pc_xzz[j] * pa_z[j] * pb_xz[j] - 2.0 * pc_xxz[j] * pa_z[j] * pb_zz[j] - pc_xzz[j] * pb_xzz[j]);

                t_xzz_xzz[j] += fl_s_0_0_4 * (0.75 * pc_xx[j] * fl2_fx + 1.5 * fl2_fx * pc_zz[j] + 3.0 * pa_x[j] * pc_xzz[j] * fl1_fx + 3.0 * pc_xxz[j] * pa_z[j] * fl1_fx + 3.0 * pc_xzz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xxzz[j] * fl1_fx + 3.0 * pc_xxz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_zzzz[j] + fl1_fx * pa_z[j] * pc_zzz[j] + fl1_fx * pc_zzz[j] * pb_z[j] + 2.0 * pa_xz[j] * pc_xzzz[j] + pa_x[j] * pc_zzzz[j] * pb_x[j] + 2.0 * pa_x[j] * pc_xzzz[j] * pb_z[j] + pc_xxzz[j] * pa_zz[j] + 2.0 * pc_xzzz[j] * pa_z[j] * pb_x[j] + 4.0 * pc_xxzz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xzzz[j] * pb_xz[j] + pc_xxzz[j] * pb_zz[j]);

                t_xzz_xzz[j] += fl_s_0_0_5 * (-3.0 * pc_xxzz[j] * fl1_fx - 0.5 * fl1_fx * pc_zzzz[j] - pa_x[j] * pc_xzzzz[j] - 2.0 * pc_xxzzz[j] * pa_z[j] - pc_xzzzz[j] * pb_x[j] - 2.0 * pc_xxzzz[j] * pb_z[j]);

                t_xzz_xzz[j] += fl_s_0_0_6 * pc_xxzzzz[j];

                t_xzz_yyy[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xzz[j] * pb_y[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_yyy[j] + pa_xzz[j] * pb_yyy[j]);

                t_xzz_yyy[j] += fl_s_0_0_1 * (-1.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pa_x[j] * fl2_fx * pc_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 1.5 * pa_xzz[j] * pb_y[j] * fl1_fx - 1.5 * pa_xzz[j] * pc_y[j] * fl1_fx - 3.0 * pa_xz[j] * pc_z[j] * pb_y[j] * fl1_fx - 1.5 * pc_x[j] * pa_zz[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_y[j] - 0.5 * pa_x[j] * fl1_fx * pb_yyy[j] - 0.5 * pc_x[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_xzz[j] * pb_yy[j] * pc_y[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_yyy[j] - pc_x[j] * pa_zz[j] * pb_yyy[j]);

                t_xzz_yyy[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_y[j] + 0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_xzz[j] * pc_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_z[j] * pb_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_yz[j] * fl1_fx + 1.5 * pa_x[j] * pc_zz[j] * pb_y[j] * fl1_fx + 1.5 * pc_x[j] * pa_zz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_xz[j] * pa_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_yy[j] + 1.5 * pa_x[j] * fl1_fx * pb_yy[j] * pc_y[j] + 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 0.5 * pc_x[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_xzz[j] * pb_y[j] * pc_yy[j] + 6.0 * pa_xz[j] * pc_yz[j] * pb_yy[j] + pa_x[j] * pc_zz[j] * pb_yyy[j] + 3.0 * pc_xy[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_yyy[j]);

                t_xzz_yyy[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 3.0 * pa_xz[j] * pc_yz[j] * fl1_fx - 1.5 * pa_x[j] * pc_zz[j] * pb_y[j] * fl1_fx - 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx - 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_xz[j] * pa_z[j] * pb_y[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 1.5 * pc_xzz[j] * pb_y[j] * fl1_fx - 0.5 * pa_x[j] * fl1_fx * pc_yyy[j] - 1.5 * pa_x[j] * fl1_fx * pb_y[j] * pc_yy[j] - 1.5 * pc_xyy[j] * fl1_fx * pb_y[j] - 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pa_xzz[j] * pc_yyy[j] - 6.0 * pa_xz[j] * pc_yyz[j] * pb_y[j] - 3.0 * pa_x[j] * pc_yzz[j] * pb_yy[j] - 3.0 * pc_xyy[j] * pa_zz[j] * pb_y[j] - 6.0 * pc_xyz[j] * pa_z[j] * pb_yy[j] - pc_xzz[j] * pb_yyy[j]);

                t_xzz_yyy[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_x[j] * pc_yzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_xzz[j] * pb_y[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pc_yyy[j] + 0.5 * pc_xyyy[j] * fl1_fx + 1.5 * pc_xyy[j] * fl1_fx * pb_y[j] + 2.0 * pa_xz[j] * pc_yyyz[j] + 3.0 * pa_x[j] * pc_yyzz[j] * pb_y[j] + pc_xyyy[j] * pa_zz[j] + 6.0 * pc_xyyz[j] * pa_z[j] * pb_y[j] + 3.0 * pc_xyzz[j] * pb_yy[j]);

                t_xzz_yyy[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xyyy[j] * fl1_fx - pa_x[j] * pc_yyyzz[j] - 2.0 * pc_xyyyz[j] * pa_z[j] - 3.0 * pc_xyyzz[j] * pb_y[j]);

                t_xzz_yyy[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_xzz_yyz[j] = fl_s_0_0_0 * (0.5 * pa_xz[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xzz[j] * fl1_fx * pb_z[j] + pa_xz[j] * fl1_fx * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pb_yyz[j] + pa_xzz[j] * pb_yyz[j]);

                t_xzz_yyz[j] += fl_s_0_0_1 * (-pa_xz[j] * fl2_fx - 0.75 * pa_x[j] * pc_z[j] * fl2_fx - 0.5 * pc_x[j] * pa_z[j] * fl2_fx - 0.5 * pa_x[j] * fl2_fx * pb_z[j] - 0.25 * pc_x[j] * fl2_fx * pb_z[j] - 0.5 * pa_xzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_xzz[j] * fl1_fx * pb_z[j] - pa_xz[j] * pc_z[j] * fl1_fx * pb_z[j] - 2.0 * pa_xz[j] * fl1_fx * pb_y[j] * pc_y[j] - pa_xz[j] * fl1_fx * pb_yy[j] - 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_yy[j] - 0.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_z[j] - pc_x[j] * pa_z[j] * fl1_fx * pb_yy[j] - pa_x[j] * fl1_fx * pb_yz[j] * pc_y[j] - 0.5 * pa_x[j] * fl1_fx * pb_yyz[j] - 0.5 * pc_x[j] * fl1_fx * pb_yyz[j] - pa_xzz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_xzz[j] * pb_yz[j] * pc_y[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_yyz[j] - pc_x[j] * pa_zz[j] * pb_yyz[j]);

                t_xzz_yyz[j] += fl_s_0_0_2 * (0.5 * pa_xz[j] * fl2_fx + 1.5 * pa_x[j] * pc_z[j] * fl2_fx + pc_x[j] * pa_z[j] * fl2_fx + 0.75 * pc_xz[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pc_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xzz[j] * fl1_fx * pc_z[j] + pa_xz[j] * pc_zz[j] * fl1_fx + pa_xz[j] * pc_z[j] * fl1_fx * pb_z[j] + pa_xz[j] * fl1_fx * pc_yy[j] + 2.0 * pa_xz[j] * fl1_fx * pb_y[j] * pc_y[j] + 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] + 1.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_yy[j] + 0.5 * pc_xz[j] * pa_zz[j] * fl1_fx + 0.5 * pc_x[j] * pa_zz[j] * fl1_fx * pb_z[j] + pc_xz[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] + pc_x[j] * pa_z[j] * fl1_fx * pb_yy[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 0.5 * pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] + pa_x[j] * fl1_fx * pb_yz[j] * pc_y[j] + pc_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pc_x[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_xzz[j] * pb_y[j] * pc_yz[j] + pa_xzz[j] * pc_yy[j] * pb_z[j] + 2.0 * pa_xz[j] * pc_zz[j] * pb_yy[j] + 4.0 * pa_xz[j] * pc_yz[j] * pb_yz[j] + pa_x[j] * pc_zz[j] * pb_yyz[j] + pc_xz[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_xy[j] * pa_zz[j] * pb_yz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_yyz[j]);

                t_xzz_yyz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * pc_z[j] * fl2_fx - 0.5 * pc_x[j] * pa_z[j] * fl2_fx - 1.5 * pc_xz[j] * fl2_fx - 0.25 * pc_x[j] * fl2_fx * pb_z[j] - pa_xz[j] * pc_zz[j] * fl1_fx - pa_xz[j] * fl1_fx * pc_yy[j] - 0.5 * pa_x[j] * pc_zzz[j] * fl1_fx - 0.5 * pa_x[j] * pc_zz[j] * fl1_fx * pb_z[j] - 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx - 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_y[j] - 0.5 * pc_xz[j] * pa_zz[j] * fl1_fx - pc_xzz[j] * pa_z[j] * fl1_fx - pc_xz[j] * pa_z[j] * fl1_fx * pb_z[j] - pc_xyy[j] * pa_z[j] * fl1_fx - 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] - 0.5 * pc_xzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] - 0.5 * pa_x[j] * fl1_fx * pc_yy[j] * pb_z[j] - 0.5 * pc_xyy[j] * fl1_fx * pb_z[j] - pc_xy[j] * fl1_fx * pb_yz[j] - pa_xzz[j] * pc_yyz[j] - 4.0 * pa_xz[j] * pc_yzz[j] * pb_y[j] - 2.0 * pa_xz[j] * pc_yyz[j] * pb_z[j] - pa_x[j] * pc_zzz[j] * pb_yy[j] - 2.0 * pa_x[j] * pc_yzz[j] * pb_yz[j] - 2.0 * pc_xyz[j] * pa_zz[j] * pb_y[j] - pc_xyy[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_xzz[j] * pa_z[j] * pb_yy[j] - 4.0 * pc_xyz[j] * pa_z[j] * pb_yz[j] - pc_xzz[j] * pb_yyz[j]);

                t_xzz_yyz[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 0.5 * pa_x[j] * pc_zzz[j] * fl1_fx + 1.5 * pa_x[j] * pc_yyz[j] * fl1_fx + pc_xzz[j] * pa_z[j] * fl1_fx + pc_xyy[j] * pa_z[j] * fl1_fx + 0.5 * pc_xzzz[j] * fl1_fx + 0.5 * pc_xzz[j] * fl1_fx * pb_z[j] + 1.5 * pc_xyyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + 0.5 * pc_xyy[j] * fl1_fx * pb_z[j] + 2.0 * pa_xz[j] * pc_yyzz[j] + 2.0 * pa_x[j] * pc_yzzz[j] * pb_y[j] + pa_x[j] * pc_yyzz[j] * pb_z[j] + pc_xyyz[j] * pa_zz[j] + 4.0 * pc_xyzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_z[j] + pc_xzzz[j] * pb_yy[j] + 2.0 * pc_xyzz[j] * pb_yz[j]);

                t_xzz_yyz[j] += fl_s_0_0_5 * (-0.5 * pc_xzzz[j] * fl1_fx - 1.5 * pc_xyyz[j] * fl1_fx - pa_x[j] * pc_yyzzz[j] - 2.0 * pc_xyyzz[j] * pa_z[j] - 2.0 * pc_xyzzz[j] * pb_y[j] - pc_xyyzz[j] * pb_z[j]);

                t_xzz_yyz[j] += fl_s_0_0_6 * pc_xyyzzz[j];

                t_xzz_yzz[j] = fl_s_0_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xzz[j] * pb_y[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_yzz[j] + pa_xzz[j] * pb_yzz[j]);

                t_xzz_yzz[j] += fl_s_0_0_1 * (-0.75 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pa_x[j] * fl2_fx * pb_y[j] - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 0.5 * pa_xzz[j] * pb_y[j] * fl1_fx - 0.5 * pa_xzz[j] * pc_y[j] * fl1_fx - 3.0 * pa_xz[j] * pc_z[j] * pb_y[j] * fl1_fx - 2.0 * pa_xz[j] * fl1_fx * pc_y[j] * pb_z[j] - 2.0 * pa_xz[j] * fl1_fx * pb_yz[j] - 3.0 * pa_x[j] * pc_z[j] * fl1_fx * pb_yz[j] - 0.5 * pc_x[j] * pa_zz[j] * pb_y[j] * fl1_fx - 2.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_yz[j] - 0.5 * pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pb_yzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_xzz[j] * pb_yz[j] * pc_z[j] - pa_xzz[j] * pc_y[j] * pb_zz[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_yzz[j] - pc_x[j] * pa_zz[j] * pb_yzz[j]);

                t_xzz_yzz[j] += fl_s_0_0_2 * (1.5 * pa_x[j] * fl2_fx * pc_y[j] + 0.75 * pa_x[j] * fl2_fx * pb_y[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pc_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xzz[j] * pc_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_z[j] * pb_y[j] * fl1_fx + 3.0 * pa_xz[j] * pc_yz[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pc_y[j] * pb_z[j] + 3.0 * pa_x[j] * pc_zz[j] * pb_y[j] * fl1_fx + 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] + 3.0 * pa_x[j] * pc_z[j] * fl1_fx * pb_yz[j] + 0.5 * pc_x[j] * pa_zz[j] * pb_y[j] * fl1_fx + 0.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_xz[j] * pa_z[j] * pb_y[j] * fl1_fx + 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_yz[j] + 3.0 * pc_xz[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pc_y[j] * pb_zz[j] + 0.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pb_yzz[j] + pa_xzz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_xzz[j] * pc_yz[j] * pb_z[j] + 4.0 * pa_xz[j] * pc_zz[j] * pb_yz[j] + 2.0 * pa_xz[j] * pc_yz[j] * pb_zz[j] + pa_x[j] * pc_zz[j] * pb_yzz[j] + 2.0 * pc_xz[j] * pa_zz[j] * pb_yz[j] + pc_xy[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_yzz[j]);

                t_xzz_yzz[j] += fl_s_0_0_3 * (-0.75 * pa_x[j] * fl2_fx * pc_y[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_x[j] * fl2_fx * pb_y[j] - 3.0 * pa_xz[j] * pc_yz[j] * fl1_fx - 3.0 * pa_x[j] * pc_zz[j] * pb_y[j] * fl1_fx - 3.0 * pa_x[j] * pc_yzz[j] * fl1_fx - 3.0 * pa_x[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_xz[j] * pa_z[j] * pb_y[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_xzz[j] * pb_y[j] * fl1_fx - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pb_yz[j] - 0.5 * pc_xy[j] * fl1_fx * pb_zz[j] - pa_xzz[j] * pc_yzz[j] - 2.0 * pa_xz[j] * pc_zzz[j] * pb_y[j] - 4.0 * pa_xz[j] * pc_yzz[j] * pb_z[j] - 2.0 * pa_x[j] * pc_zzz[j] * pb_yz[j] - pa_x[j] * pc_yzz[j] * pb_zz[j] - pc_xzz[j] * pa_zz[j] * pb_y[j] - 2.0 * pc_xyz[j] * pa_zz[j] * pb_z[j] - 4.0 * pc_xzz[j] * pa_z[j] * pb_yz[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_zz[j] - pc_xzz[j] * pb_yzz[j]);

                t_xzz_yzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 3.0 * pa_x[j] * pc_yzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 3.0 * pc_xzz[j] * pb_y[j] * fl1_fx + 3.0 * pc_xyzz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 2.0 * pa_xz[j] * pc_yzzz[j] + pa_x[j] * pc_zzzz[j] * pb_y[j] + 2.0 * pa_x[j] * pc_yzzz[j] * pb_z[j] + pc_xyzz[j] * pa_zz[j] + 2.0 * pc_xzzz[j] * pa_z[j] * pb_y[j] + 4.0 * pc_xyzz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_xzzz[j] * pb_yz[j] + pc_xyzz[j] * pb_zz[j]);

                t_xzz_yzz[j] += fl_s_0_0_5 * (-3.0 * pc_xyzz[j] * fl1_fx - pa_x[j] * pc_yzzzz[j] - 2.0 * pc_xyzzz[j] * pa_z[j] - pc_xzzzz[j] * pb_y[j] - 2.0 * pc_xyzzz[j] * pb_z[j]);

                t_xzz_yzz[j] += fl_s_0_0_6 * pc_xyzzzz[j];

                t_xzz_zzz[j] = fl_s_0_0_0 * (1.5 * pa_xz[j] * fl2_fx + 2.25 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xzz[j] * pb_z[j] * fl1_fx + 3.0 * pa_xz[j] * fl1_fx * pb_zz[j] + 0.5 * pa_x[j] * fl1_fx * pb_zzz[j] + pa_xzz[j] * pb_zzz[j]);

                t_xzz_zzz[j] += fl_s_0_0_1 * (-3.0 * pa_xz[j] * fl2_fx - 3.75 * pa_x[j] * pc_z[j] * fl2_fx - 4.5 * pa_x[j] * fl2_fx * pb_z[j] - 1.5 * pc_x[j] * pa_z[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_z[j] - 1.5 * pa_xzz[j] * pb_z[j] * fl1_fx - 1.5 * pa_xzz[j] * pc_z[j] * fl1_fx - 9.0 * pa_xz[j] * pc_z[j] * pb_z[j] * fl1_fx - 3.0 * pa_xz[j] * fl1_fx * pb_zz[j] - 4.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_zz[j] - 1.5 * pc_x[j] * pa_zz[j] * pb_z[j] * fl1_fx - 3.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_zz[j] - 0.5 * pa_x[j] * fl1_fx * pb_zzz[j] - 0.5 * pc_x[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_xzz[j] * pb_zz[j] * pc_z[j] - 2.0 * pa_xz[j] * pc_z[j] * pb_zzz[j] - pc_x[j] * pa_zz[j] * pb_zzz[j]);

                t_xzz_zzz[j] += fl_s_0_0_2 * (1.5 * pa_xz[j] * fl2_fx + 7.5 * pa_x[j] * pc_z[j] * fl2_fx + 2.25 * pa_x[j] * fl2_fx * pb_z[j] + 3.0 * pc_x[j] * pa_z[j] * fl2_fx + 3.75 * pc_xz[j] * fl2_fx + 4.5 * pc_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xzz[j] * pc_z[j] * fl1_fx + 9.0 * pa_xz[j] * pc_z[j] * pb_z[j] * fl1_fx + 6.0 * pa_xz[j] * pc_zz[j] * fl1_fx + 9.0 * pa_x[j] * pc_zz[j] * pb_z[j] * fl1_fx + 4.5 * pa_x[j] * pc_z[j] * fl1_fx * pb_zz[j] + 1.5 * pc_x[j] * pa_zz[j] * pb_z[j] * fl1_fx + 1.5 * pc_xz[j] * pa_zz[j] * fl1_fx + 9.0 * pc_xz[j] * pa_z[j] * pb_z[j] * fl1_fx + 3.0 * pc_x[j] * pa_z[j] * fl1_fx * pb_zz[j] + 4.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 0.5 * pc_x[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_xzz[j] * pb_z[j] * pc_zz[j] + 6.0 * pa_xz[j] * pc_zz[j] * pb_zz[j] + pa_x[j] * pc_zz[j] * pb_zzz[j] + 3.0 * pc_xz[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_xz[j] * pa_z[j] * pb_zzz[j]);

                t_xzz_zzz[j] += fl_s_0_0_3 * (-3.75 * pa_x[j] * pc_z[j] * fl2_fx - 1.5 * pc_x[j] * pa_z[j] * fl2_fx - 7.5 * pc_xz[j] * fl2_fx - 2.25 * pc_x[j] * fl2_fx * pb_z[j] - 6.0 * pa_xz[j] * pc_zz[j] * fl1_fx - 9.0 * pa_x[j] * pc_zz[j] * pb_z[j] * fl1_fx - 5.0 * pa_x[j] * pc_zzz[j] * fl1_fx - 1.5 * pc_xz[j] * pa_zz[j] * fl1_fx - 9.0 * pc_xz[j] * pa_z[j] * pb_z[j] * fl1_fx - 6.0 * pc_xzz[j] * pa_z[j] * fl1_fx - 9.0 * pc_xzz[j] * pb_z[j] * fl1_fx - 4.5 * pc_xz[j] * fl1_fx * pb_zz[j] - pa_xzz[j] * pc_zzz[j] - 6.0 * pa_xz[j] * pc_zzz[j] * pb_z[j] - 3.0 * pa_x[j] * pc_zzz[j] * pb_zz[j] - 3.0 * pc_xzz[j] * pa_zz[j] * pb_z[j] - 6.0 * pc_xzz[j] * pa_z[j] * pb_zz[j] - pc_xzz[j] * pb_zzz[j]);

                t_xzz_zzz[j] += fl_s_0_0_4 * (3.75 * pc_xz[j] * fl2_fx + 5.0 * pa_x[j] * pc_zzz[j] * fl1_fx + 6.0 * pc_xzz[j] * pa_z[j] * fl1_fx + 9.0 * pc_xzz[j] * pb_z[j] * fl1_fx + 5.0 * pc_xzzz[j] * fl1_fx + 2.0 * pa_xz[j] * pc_zzzz[j] + 3.0 * pa_x[j] * pc_zzzz[j] * pb_z[j] + pc_xzzz[j] * pa_zz[j] + 6.0 * pc_xzzz[j] * pa_z[j] * pb_z[j] + 3.0 * pc_xzzz[j] * pb_zz[j]);

                t_xzz_zzz[j] += fl_s_0_0_5 * (-5.0 * pc_xzzz[j] * fl1_fx - pa_x[j] * pc_zzzzz[j] - 2.0 * pc_xzzzz[j] * pa_z[j] - 3.0 * pc_xzzzz[j] * pb_z[j]);

                t_xzz_zzz[j] += fl_s_0_0_6 * pc_xzzzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_60_70(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (60,70)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(19 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(19 * idx + 6);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yyy = paDistances.data(19 * idx + 15);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xyyyy = pcDistances.data(83 * idx + 44);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_yyyyy = pcDistances.data(83 * idx + 49);

            auto pc_yyyyz = pcDistances.data(83 * idx + 50);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxyyy = pcDistances.data(83 * idx + 61);

            auto pc_xxyyyy = pcDistances.data(83 * idx + 65);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xyyyyy = pcDistances.data(83 * idx + 70);

            auto pc_xyyyyz = pcDistances.data(83 * idx + 71);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_yyyyyy = pcDistances.data(83 * idx + 76);

            auto pc_yyyyyz = pcDistances.data(83 * idx + 77);

            auto pc_yyyyzz = pcDistances.data(83 * idx + 78);

            auto pc_yyyzzz = pcDistances.data(83 * idx + 79);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_yyy_xxx = primBuffer.data(100 * idx + 60);

            auto t_yyy_xxy = primBuffer.data(100 * idx + 61);

            auto t_yyy_xxz = primBuffer.data(100 * idx + 62);

            auto t_yyy_xyy = primBuffer.data(100 * idx + 63);

            auto t_yyy_xyz = primBuffer.data(100 * idx + 64);

            auto t_yyy_xzz = primBuffer.data(100 * idx + 65);

            auto t_yyy_yyy = primBuffer.data(100 * idx + 66);

            auto t_yyy_yyz = primBuffer.data(100 * idx + 67);

            auto t_yyy_yzz = primBuffer.data(100 * idx + 68);

            auto t_yyy_zzz = primBuffer.data(100 * idx + 69);

            // Batch of Integrals (60,70)

            #pragma omp simd aligned(fx, pa_y, pa_yy, pa_yyy, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     pc_x, pc_xx, pc_xxx, pc_xxxy, pc_xxxyy, pc_xxxyyy, pc_xxy, pc_xxyy, pc_xxyyy, \
                                     pc_xxyyyy, pc_xxyyyz, pc_xxyyz, pc_xxyz, pc_xxz, pc_xy, pc_xyy, pc_xyyy, pc_xyyyy, \
                                     pc_xyyyyy, pc_xyyyyz, pc_xyyyz, pc_xyyyzz, pc_xyyz, pc_xyyzz, pc_xyz, pc_xyzz, pc_xz, \
                                     pc_xzz, pc_y, pc_yy, pc_yyy, pc_yyyy, pc_yyyyy, pc_yyyyyy, pc_yyyyyz, pc_yyyyz, \
                                     pc_yyyyzz, pc_yyyz, pc_yyyzz, pc_yyyzzz, pc_yyz, pc_yyzz, pc_yyzzz, pc_yz, pc_yzz, \
                                     pc_yzzz, pc_z, pc_zz, pc_zzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, s_0_0_5, \
                                     s_0_0_6, t_yyy_xxx, t_yyy_xxy, t_yyy_xxz, t_yyy_xyy, t_yyy_xyz, t_yyy_xzz, \
                                     t_yyy_yyy, t_yyy_yyz, t_yyy_yzz, t_yyy_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yyy_xxx[j] = fl_s_0_0_0 * (2.25 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pa_yyy[j] * pb_x[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_xxx[j] + pa_yyy[j] * pb_xxx[j]);

                t_yyy_xxx[j] += fl_s_0_0_1 * (-4.5 * pa_y[j] * fl2_fx * pb_x[j] - 2.25 * pa_y[j] * fl2_fx * pc_x[j] - 2.25 * pc_y[j] * fl2_fx * pb_x[j] - 1.5 * pa_yyy[j] * pb_x[j] * fl1_fx - 1.5 * pa_yyy[j] * pc_x[j] * fl1_fx - 4.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx - 4.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_x[j] - 1.5 * pa_y[j] * fl1_fx * pb_xxx[j] - 1.5 * pc_y[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_yyy[j] * pb_xx[j] * pc_x[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xxx[j]);

                t_yyy_xxx[j] += fl_s_0_0_2 * (4.5 * pa_y[j] * fl2_fx * pc_x[j] + 2.25 * pa_y[j] * fl2_fx * pb_x[j] + 4.5 * pc_y[j] * fl2_fx * pb_x[j] + 2.25 * pc_xy[j] * fl2_fx + 1.5 * pa_yyy[j] * pc_x[j] * fl1_fx + 4.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx + 4.5 * pa_yy[j] * pc_xy[j] * fl1_fx + 4.5 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx + 4.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_xx[j] + 4.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_x[j] + 4.5 * pc_xy[j] * fl1_fx * pb_xx[j] + 1.5 * pc_y[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_yyy[j] * pb_x[j] * pc_xx[j] + 9.0 * pa_yy[j] * pc_xy[j] * pb_xx[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xxx[j]);

                t_yyy_xxx[j] += fl_s_0_0_3 * (-2.25 * pa_y[j] * fl2_fx * pc_x[j] - 4.5 * pc_xy[j] * fl2_fx - 2.25 * pc_y[j] * fl2_fx * pb_x[j] - 4.5 * pa_yy[j] * pc_xy[j] * fl1_fx - 4.5 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx - 4.5 * pa_y[j] * pc_xyy[j] * fl1_fx - 1.5 * pc_yyy[j] * pb_x[j] * fl1_fx - 1.5 * pa_y[j] * fl1_fx * pc_xxx[j] - 4.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_xx[j] - 4.5 * pc_xxy[j] * fl1_fx * pb_x[j] - 4.5 * pc_xy[j] * fl1_fx * pb_xx[j] - pa_yyy[j] * pc_xxx[j] - 9.0 * pa_yy[j] * pc_xxy[j] * pb_x[j] - 9.0 * pa_y[j] * pc_xyy[j] * pb_xx[j] - pc_yyy[j] * pb_xxx[j]);

                t_yyy_xxx[j] += fl_s_0_0_4 * (2.25 * pc_xy[j] * fl2_fx + 4.5 * pa_y[j] * pc_xyy[j] * fl1_fx + 1.5 * pc_yyy[j] * pb_x[j] * fl1_fx + 1.5 * pc_xyyy[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pc_xxx[j] + 1.5 * pc_xxxy[j] * fl1_fx + 4.5 * pc_xxy[j] * fl1_fx * pb_x[j] + 3.0 * pa_yy[j] * pc_xxxy[j] + 9.0 * pa_y[j] * pc_xxyy[j] * pb_x[j] + 3.0 * pc_xyyy[j] * pb_xx[j]);

                t_yyy_xxx[j] += fl_s_0_0_5 * (-1.5 * pc_xyyy[j] * fl1_fx - 1.5 * pc_xxxy[j] * fl1_fx - 3.0 * pa_y[j] * pc_xxxyy[j] - 3.0 * pc_xxyyy[j] * pb_x[j]);

                t_yyy_xxx[j] += fl_s_0_0_6 * pc_xxxyyy[j];

                t_yyy_xxy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_xx[j] + 0.5 * pa_yyy[j] * fl1_fx * pb_y[j] + 1.5 * pa_yy[j] * fl1_fx * pb_xx[j] + 1.5 * pa_y[j] * fl1_fx * pb_xxy[j] + pa_yyy[j] * pb_xxy[j]);

                t_yyy_xxy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_yy[j] * fl2_fx - 2.25 * pa_y[j] * pc_y[j] * fl2_fx - 1.5 * pa_y[j] * fl2_fx * pb_y[j] - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pb_x[j] * pc_x[j] - 1.5 * fl2_fx * pb_xx[j] - 0.5 * pa_yyy[j] * fl1_fx * pc_y[j] - 0.5 * pa_yyy[j] * fl1_fx * pb_y[j] - 1.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_y[j] - 3.0 * pa_yy[j] * fl1_fx * pb_x[j] * pc_x[j] - 1.5 * pa_yy[j] * fl1_fx * pb_xx[j] - 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_xx[j] - 3.0 * pa_y[j] * fl1_fx * pb_xy[j] * pc_x[j] - 1.5 * pa_y[j] * fl1_fx * pb_xxy[j] - 1.5 * pc_y[j] * fl1_fx * pb_xxy[j] - pa_yyy[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_yyy[j] * pb_xy[j] * pc_x[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xxy[j]);

                t_yyy_xxy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 4.5 * pa_y[j] * pc_y[j] * fl2_fx + 1.5 * pc_yy[j] * fl2_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 1.5 * pc_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pc_xx[j] + 3.0 * fl2_fx * pb_x[j] * pc_x[j] + 0.75 * fl2_fx * pb_xx[j] + 0.5 * pa_yyy[j] * fl1_fx * pc_y[j] + 1.5 * pa_yy[j] * pc_yy[j] * fl1_fx + 1.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_y[j] + 1.5 * pa_yy[j] * fl1_fx * pc_xx[j] + 3.0 * pa_yy[j] * fl1_fx * pb_x[j] * pc_x[j] + 1.5 * pa_y[j] * pc_yy[j] * fl1_fx * pb_y[j] + 9.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_x[j] + 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_xx[j] + 3.0 * pc_yy[j] * fl1_fx * pb_xx[j] + 1.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_y[j] + 3.0 * pa_y[j] * fl1_fx * pb_xy[j] * pc_x[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] + 1.5 * pc_y[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_yyy[j] * pb_x[j] * pc_xy[j] + pa_yyy[j] * pc_xx[j] * pb_y[j] + 3.0 * pa_yy[j] * pc_yy[j] * pb_xx[j] + 6.0 * pa_yy[j] * pc_xy[j] * pb_xy[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xxy[j]);

                t_yyy_xxy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_y[j] * pc_y[j] * fl2_fx - 3.0 * pc_yy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pc_xx[j] - 1.5 * fl2_fx * pb_x[j] * pc_x[j] - 1.5 * pa_yy[j] * pc_yy[j] * fl1_fx - 1.5 * pa_yy[j] * fl1_fx * pc_xx[j] - 1.5 * pa_y[j] * pc_yyy[j] * fl1_fx - 1.5 * pa_y[j] * pc_yy[j] * fl1_fx * pb_y[j] - 4.5 * pa_y[j] * pc_xxy[j] * fl1_fx - 9.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_x[j] - 0.5 * pc_yyy[j] * fl1_fx * pb_y[j] - 6.0 * pc_xyy[j] * fl1_fx * pb_x[j] - 3.0 * pc_yy[j] * fl1_fx * pb_xx[j] - 1.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_y[j] - 1.5 * pc_xxy[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xy[j] - pa_yyy[j] * pc_xxy[j] - 6.0 * pa_yy[j] * pc_xyy[j] * pb_x[j] - 3.0 * pa_yy[j] * pc_xxy[j] * pb_y[j] - 3.0 * pa_y[j] * pc_yyy[j] * pb_xx[j] - 6.0 * pa_y[j] * pc_xyy[j] * pb_xy[j] - pc_yyy[j] * pb_xxy[j]);

                t_yyy_xxy[j] += fl_s_0_0_4 * (1.5 * pc_yy[j] * fl2_fx + 0.75 * fl2_fx * pc_xx[j] + 1.5 * pa_y[j] * pc_yyy[j] * fl1_fx + 4.5 * pa_y[j] * pc_xxy[j] * fl1_fx + 0.5 * pc_yyyy[j] * fl1_fx + 0.5 * pc_yyy[j] * fl1_fx * pb_y[j] + 3.0 * pc_xxyy[j] * fl1_fx + 6.0 * pc_xyy[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxy[j] * fl1_fx * pb_y[j] + 3.0 * pa_yy[j] * pc_xxyy[j] + 6.0 * pa_y[j] * pc_xyyy[j] * pb_x[j] + 3.0 * pa_y[j] * pc_xxyy[j] * pb_y[j] + pc_yyyy[j] * pb_xx[j] + 2.0 * pc_xyyy[j] * pb_xy[j]);

                t_yyy_xxy[j] += fl_s_0_0_5 * (-0.5 * pc_yyyy[j] * fl1_fx - 3.0 * pc_xxyy[j] * fl1_fx - 3.0 * pa_y[j] * pc_xxyyy[j] - 2.0 * pc_xyyyy[j] * pb_x[j] - pc_xxyyy[j] * pb_y[j]);

                t_yyy_xxy[j] += fl_s_0_0_6 * pc_xxyyyy[j];

                t_yyy_xxz[j] = fl_s_0_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yyy[j] * fl1_fx * pb_z[j] + 1.5 * pa_y[j] * fl1_fx * pb_xxz[j] + pa_yyy[j] * pb_xxz[j]);

                t_yyy_xxz[j] += fl_s_0_0_1 * (-0.75 * pa_y[j] * fl2_fx * pc_z[j] - 1.5 * pa_y[j] * fl2_fx * pb_z[j] - 0.75 * pc_y[j] * fl2_fx * pb_z[j] - 0.5 * pa_yyy[j] * fl1_fx * pc_z[j] - 0.5 * pa_yyy[j] * fl1_fx * pb_z[j] - 1.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_z[j] - 1.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_z[j] - 3.0 * pa_y[j] * fl1_fx * pb_xz[j] * pc_x[j] - 1.5 * pa_y[j] * fl1_fx * pb_xxz[j] - 1.5 * pc_y[j] * fl1_fx * pb_xxz[j] - pa_yyy[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_yyy[j] * pb_xz[j] * pc_x[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xxz[j]);

                t_yyy_xxz[j] += fl_s_0_0_2 * (1.5 * pa_y[j] * fl2_fx * pc_z[j] + 0.75 * pa_y[j] * fl2_fx * pb_z[j] + 0.75 * pc_yz[j] * fl2_fx + 1.5 * pc_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yyy[j] * fl1_fx * pc_z[j] + 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx + 1.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_z[j] + 1.5 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * fl1_fx * pb_x[j] * pc_xz[j] + 1.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_z[j] + 1.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_z[j] + 3.0 * pa_y[j] * fl1_fx * pb_xz[j] * pc_x[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] + 3.0 * pc_xy[j] * fl1_fx * pb_xz[j] + 1.5 * pc_y[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_yyy[j] * pb_x[j] * pc_xz[j] + pa_yyy[j] * pc_xx[j] * pb_z[j] + 3.0 * pa_yy[j] * pc_yz[j] * pb_xx[j] + 6.0 * pa_yy[j] * pc_xy[j] * pb_xz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xxz[j]);

                t_yyy_xxz[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * fl2_fx * pc_z[j] - 1.5 * pc_yz[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_z[j] - 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx - 1.5 * pa_y[j] * pc_yyz[j] * fl1_fx - 1.5 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] - 0.5 * pc_yyy[j] * fl1_fx * pb_z[j] - 1.5 * pa_y[j] * fl1_fx * pc_xxz[j] - 3.0 * pa_y[j] * fl1_fx * pb_x[j] * pc_xz[j] - 1.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] - 3.0 * pc_xy[j] * fl1_fx * pb_xz[j] - pa_yyy[j] * pc_xxz[j] - 6.0 * pa_yy[j] * pc_xyz[j] * pb_x[j] - 3.0 * pa_yy[j] * pc_xxy[j] * pb_z[j] - 3.0 * pa_y[j] * pc_yyz[j] * pb_xx[j] - 6.0 * pa_y[j] * pc_xyy[j] * pb_xz[j] - pc_yyy[j] * pb_xxz[j]);

                t_yyy_xxz[j] += fl_s_0_0_4 * (0.75 * pc_yz[j] * fl2_fx + 1.5 * pa_y[j] * pc_yyz[j] * fl1_fx + 0.5 * pc_yyyz[j] * fl1_fx + 0.5 * pc_yyy[j] * fl1_fx * pb_z[j] + 1.5 * pa_y[j] * fl1_fx * pc_xxz[j] + 1.5 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxy[j] * fl1_fx * pb_z[j] + 3.0 * pa_yy[j] * pc_xxyz[j] + 6.0 * pa_y[j] * pc_xyyz[j] * pb_x[j] + 3.0 * pa_y[j] * pc_xxyy[j] * pb_z[j] + pc_yyyz[j] * pb_xx[j] + 2.0 * pc_xyyy[j] * pb_xz[j]);

                t_yyy_xxz[j] += fl_s_0_0_5 * (-0.5 * pc_yyyz[j] * fl1_fx - 1.5 * pc_xxyz[j] * fl1_fx - 3.0 * pa_y[j] * pc_xxyyz[j] - 2.0 * pc_xyyyz[j] * pb_x[j] - pc_xxyyy[j] * pb_z[j]);

                t_yyy_xxz[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_yyy_xyy[j] = fl_s_0_0_0 * (2.25 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * fl2_fx * pb_xy[j] + 0.5 * pa_yyy[j] * pb_x[j] * fl1_fx + 3.0 * pa_yy[j] * fl1_fx * pb_xy[j] + 1.5 * pa_y[j] * fl1_fx * pb_xyy[j] + pa_yyy[j] * pb_xyy[j]);

                t_yyy_xyy[j] += fl_s_0_0_1 * (-2.25 * pa_y[j] * fl2_fx * pc_x[j] - 4.5 * pa_y[j] * fl2_fx * pb_x[j] - 3.75 * pc_y[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_x[j] * pb_y[j] - 3.0 * fl2_fx * pb_xy[j] - 0.5 * pa_yyy[j] * pb_x[j] * fl1_fx - 0.5 * pa_yyy[j] * pc_x[j] * fl1_fx - 4.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx - 3.0 * pa_yy[j] * fl1_fx * pc_x[j] * pb_y[j] - 3.0 * pa_yy[j] * fl1_fx * pb_xy[j] - 9.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_xy[j] - 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yy[j] - 1.5 * pa_y[j] * fl1_fx * pb_xyy[j] - 1.5 * pc_y[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_yyy[j] * pb_xy[j] * pc_y[j] - pa_yyy[j] * pc_x[j] * pb_yy[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xyy[j]);

                t_yyy_xyy[j] += fl_s_0_0_2 * (4.5 * pa_y[j] * fl2_fx * pc_x[j] + 2.25 * pa_y[j] * fl2_fx * pb_x[j] + 3.75 * pc_xy[j] * fl2_fx + 7.5 * pc_y[j] * fl2_fx * pb_x[j] + 3.0 * fl2_fx * pc_x[j] * pb_y[j] + 1.5 * fl2_fx * pb_xy[j] + 0.5 * pa_yyy[j] * pc_x[j] * fl1_fx + 4.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx + 4.5 * pa_yy[j] * pc_xy[j] * fl1_fx + 3.0 * pa_yy[j] * fl1_fx * pc_x[j] * pb_y[j] + 9.0 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx + 9.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_y[j] + 9.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_xy[j] + 6.0 * pc_yy[j] * fl1_fx * pb_xy[j] + 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yy[j] + 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 1.5 * pc_y[j] * fl1_fx * pb_xyy[j] + pa_yyy[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_yyy[j] * pc_xy[j] * pb_y[j] + 6.0 * pa_yy[j] * pc_yy[j] * pb_xy[j] + 3.0 * pa_yy[j] * pc_xy[j] * pb_yy[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xyy[j]);

                t_yyy_xyy[j] += fl_s_0_0_3 * (-2.25 * pa_y[j] * fl2_fx * pc_x[j] - 7.5 * pc_xy[j] * fl2_fx - 3.75 * pc_y[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_x[j] * pb_y[j] - 4.5 * pa_yy[j] * pc_xy[j] * fl1_fx - 9.0 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx - 9.0 * pa_y[j] * pc_xyy[j] * fl1_fx - 9.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_y[j] - 5.0 * pc_yyy[j] * pb_x[j] * fl1_fx - 6.0 * pc_xyy[j] * fl1_fx * pb_y[j] - 6.0 * pc_yy[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pa_yyy[j] * pc_xyy[j] - 3.0 * pa_yy[j] * pc_yyy[j] * pb_x[j] - 6.0 * pa_yy[j] * pc_xyy[j] * pb_y[j] - 6.0 * pa_y[j] * pc_yyy[j] * pb_xy[j] - 3.0 * pa_y[j] * pc_xyy[j] * pb_yy[j] - pc_yyy[j] * pb_xyy[j]);

                t_yyy_xyy[j] += fl_s_0_0_4 * (3.75 * pc_xy[j] * fl2_fx + 9.0 * pa_y[j] * pc_xyy[j] * fl1_fx + 5.0 * pc_yyy[j] * pb_x[j] * fl1_fx + 5.0 * pc_xyyy[j] * fl1_fx + 6.0 * pc_xyy[j] * fl1_fx * pb_y[j] + 3.0 * pa_yy[j] * pc_xyyy[j] + 3.0 * pa_y[j] * pc_yyyy[j] * pb_x[j] + 6.0 * pa_y[j] * pc_xyyy[j] * pb_y[j] + 2.0 * pc_yyyy[j] * pb_xy[j] + pc_xyyy[j] * pb_yy[j]);

                t_yyy_xyy[j] += fl_s_0_0_5 * (-5.0 * pc_xyyy[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyyyy[j] - pc_yyyyy[j] * pb_x[j] - 2.0 * pc_xyyyy[j] * pb_y[j]);

                t_yyy_xyy[j] += fl_s_0_0_6 * pc_xyyyyy[j];

                t_yyy_xyz[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_yy[j] * fl1_fx * pb_xz[j] + 1.5 * pa_y[j] * fl1_fx * pb_xyz[j] + pa_yyy[j] * pb_xyz[j]);

                t_yyy_xyz[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pb_x[j] * pc_z[j] - 0.75 * fl2_fx * pc_x[j] * pb_z[j] - 1.5 * fl2_fx * pb_xz[j] - 1.5 * pa_yy[j] * fl1_fx * pb_x[j] * pc_z[j] - 1.5 * pa_yy[j] * fl1_fx * pc_x[j] * pb_z[j] - 1.5 * pa_yy[j] * fl1_fx * pb_xz[j] - 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_xz[j] - 1.5 * pa_y[j] * fl1_fx * pb_xy[j] * pc_z[j] - 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yz[j] - 1.5 * pa_y[j] * fl1_fx * pb_xyz[j] - 1.5 * pc_y[j] * fl1_fx * pb_xyz[j] - pa_yyy[j] * pb_xy[j] * pc_z[j] - pa_yyy[j] * pb_xz[j] * pc_y[j] - pa_yyy[j] * pc_x[j] * pb_yz[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xyz[j]);

                t_yyy_xyz[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_xz[j] + 1.5 * fl2_fx * pb_x[j] * pc_z[j] + 1.5 * fl2_fx * pc_x[j] * pb_z[j] + 0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_yy[j] * fl1_fx * pc_xz[j] + 1.5 * pa_yy[j] * fl1_fx * pb_x[j] * pc_z[j] + 1.5 * pa_yy[j] * fl1_fx * pc_x[j] * pb_z[j] + 4.5 * pa_y[j] * pc_yz[j] * fl1_fx * pb_x[j] + 4.5 * pa_y[j] * pc_xy[j] * fl1_fx * pb_z[j] + 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_xz[j] + 3.0 * pc_yy[j] * fl1_fx * pb_xz[j] + 1.5 * pa_y[j] * fl1_fx * pc_xz[j] * pb_y[j] + 1.5 * pa_y[j] * fl1_fx * pb_xy[j] * pc_z[j] + 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yz[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xy[j] + 1.5 * pc_xy[j] * fl1_fx * pb_yz[j] + 1.5 * pc_y[j] * fl1_fx * pb_xyz[j] + pa_yyy[j] * pb_x[j] * pc_yz[j] + pa_yyy[j] * pc_xz[j] * pb_y[j] + pa_yyy[j] * pc_xy[j] * pb_z[j] + 3.0 * pa_yy[j] * pc_yz[j] * pb_xy[j] + 3.0 * pa_yy[j] * pc_yy[j] * pb_xz[j] + 3.0 * pa_yy[j] * pc_xy[j] * pb_yz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xyz[j]);

                t_yyy_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xz[j] - 0.75 * fl2_fx * pb_x[j] * pc_z[j] - 0.75 * fl2_fx * pc_x[j] * pb_z[j] - 1.5 * pa_yy[j] * fl1_fx * pc_xz[j] - 4.5 * pa_y[j] * pc_xyz[j] * fl1_fx - 4.5 * pa_y[j] * pc_yz[j] * fl1_fx * pb_x[j] - 4.5 * pa_y[j] * pc_xy[j] * fl1_fx * pb_z[j] - 3.0 * pc_yyz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xyy[j] * fl1_fx * pb_z[j] - 3.0 * pc_yy[j] * fl1_fx * pb_xz[j] - 1.5 * pa_y[j] * fl1_fx * pc_xz[j] * pb_y[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xy[j] * fl1_fx * pb_yz[j] - pa_yyy[j] * pc_xyz[j] - 3.0 * pa_yy[j] * pc_yyz[j] * pb_x[j] - 3.0 * pa_yy[j] * pc_xyz[j] * pb_y[j] - 3.0 * pa_yy[j] * pc_xyy[j] * pb_z[j] - 3.0 * pa_y[j] * pc_yyz[j] * pb_xy[j] - 3.0 * pa_y[j] * pc_yyy[j] * pb_xz[j] - 3.0 * pa_y[j] * pc_xyy[j] * pb_yz[j] - pc_yyy[j] * pb_xyz[j]);

                t_yyy_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xz[j] + 4.5 * pa_y[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xyyz[j] * fl1_fx + 3.0 * pc_yyz[j] * fl1_fx * pb_x[j] + 3.0 * pc_xyy[j] * fl1_fx * pb_z[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] + 3.0 * pa_yy[j] * pc_xyyz[j] + 3.0 * pa_y[j] * pc_yyyz[j] * pb_x[j] + 3.0 * pa_y[j] * pc_xyyz[j] * pb_y[j] + 3.0 * pa_y[j] * pc_xyyy[j] * pb_z[j] + pc_yyyz[j] * pb_xy[j] + pc_yyyy[j] * pb_xz[j] + pc_xyyy[j] * pb_yz[j]);

                t_yyy_xyz[j] += fl_s_0_0_5 * (-3.0 * pc_xyyz[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyyyz[j] - pc_yyyyz[j] * pb_x[j] - pc_xyyyz[j] * pb_y[j] - pc_xyyyy[j] * pb_z[j]);

                t_yyy_xyz[j] += fl_s_0_0_6 * pc_xyyyyz[j];

                t_yyy_xzz[j] = fl_s_0_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 0.5 * pa_yyy[j] * pb_x[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_xzz[j] + pa_yyy[j] * pb_xzz[j]);

                t_yyy_xzz[j] += fl_s_0_0_1 * (-1.5 * pa_y[j] * fl2_fx * pb_x[j] - 0.75 * pa_y[j] * fl2_fx * pc_x[j] - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.5 * pa_yyy[j] * pb_x[j] * fl1_fx - 0.5 * pa_yyy[j] * pc_x[j] * fl1_fx - 1.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx - 3.0 * pa_y[j] * fl1_fx * pb_xz[j] * pc_z[j] - 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_zz[j] - 1.5 * pa_y[j] * fl1_fx * pb_xzz[j] - 1.5 * pc_y[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_yyy[j] * pb_xz[j] * pc_z[j] - pa_yyy[j] * pc_x[j] * pb_zz[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_xzz[j]);

                t_yyy_xzz[j] += fl_s_0_0_2 * (1.5 * pa_y[j] * fl2_fx * pc_x[j] + 0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pc_y[j] * fl2_fx * pb_x[j] + 0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_yyy[j] * pc_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_y[j] * pb_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_xy[j] * fl1_fx + 1.5 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_zz[j] + 3.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_z[j] + 3.0 * pa_y[j] * fl1_fx * pb_xz[j] * pc_z[j] + 1.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_zz[j] + 3.0 * pc_yz[j] * fl1_fx * pb_xz[j] + 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 1.5 * pc_y[j] * fl1_fx * pb_xzz[j] + pa_yyy[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_yyy[j] * pc_xz[j] * pb_z[j] + 6.0 * pa_yy[j] * pc_yz[j] * pb_xz[j] + 3.0 * pa_yy[j] * pc_xy[j] * pb_zz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_xzz[j]);

                t_yyy_xzz[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 1.5 * pa_yy[j] * pc_xy[j] * fl1_fx - 1.5 * pa_y[j] * pc_yy[j] * pb_x[j] * fl1_fx - 1.5 * pa_y[j] * pc_xyy[j] * fl1_fx - 0.5 * pc_yyy[j] * pb_x[j] * fl1_fx - 1.5 * pa_y[j] * fl1_fx * pc_xzz[j] - 1.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_zz[j] - 3.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_z[j] - 1.5 * pc_yzz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yz[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xy[j] * fl1_fx * pb_zz[j] - pa_yyy[j] * pc_xzz[j] - 3.0 * pa_yy[j] * pc_yzz[j] * pb_x[j] - 6.0 * pa_yy[j] * pc_xyz[j] * pb_z[j] - 6.0 * pa_y[j] * pc_yyz[j] * pb_xz[j] - 3.0 * pa_y[j] * pc_xyy[j] * pb_zz[j] - pc_yyy[j] * pb_xzz[j]);

                t_yyy_xzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_y[j] * pc_xyy[j] * fl1_fx + 0.5 * pc_yyy[j] * pb_x[j] * fl1_fx + 0.5 * pc_xyyy[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pc_xzz[j] + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_yzz[j] * fl1_fx * pb_x[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 3.0 * pa_yy[j] * pc_xyzz[j] + 3.0 * pa_y[j] * pc_yyzz[j] * pb_x[j] + 6.0 * pa_y[j] * pc_xyyz[j] * pb_z[j] + 2.0 * pc_yyyz[j] * pb_xz[j] + pc_xyyy[j] * pb_zz[j]);

                t_yyy_xzz[j] += fl_s_0_0_5 * (-0.5 * pc_xyyy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyyzz[j] - pc_yyyzz[j] * pb_x[j] - 2.0 * pc_xyyyz[j] * pb_z[j]);

                t_yyy_xzz[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_yyy_yyy[j] = fl_s_0_0_0 * (1.875 * fl3_fx + 2.25 * pa_yy[j] * fl2_fx + 6.75 * pa_y[j] * fl2_fx * pb_y[j] + 2.25 * fl2_fx * pb_yy[j] + 1.5 * pa_yyy[j] * pb_y[j] * fl1_fx + 4.5 * pa_yy[j] * fl1_fx * pb_yy[j] + 1.5 * pa_y[j] * fl1_fx * pb_yyy[j] + pa_yyy[j] * pb_yyy[j]);

                t_yyy_yyy[j] += fl_s_0_0_1 * (-5.625 * fl3_fx - 4.5 * pa_yy[j] * fl2_fx - 11.25 * pa_y[j] * pc_y[j] * fl2_fx - 13.5 * pa_y[j] * fl2_fx * pb_y[j] - 11.25 * pc_y[j] * fl2_fx * pb_y[j] - 4.5 * fl2_fx * pb_yy[j] - 1.5 * pa_yyy[j] * pb_y[j] * fl1_fx - 1.5 * pa_yyy[j] * pc_y[j] * fl1_fx - 13.5 * pa_yy[j] * pc_y[j] * pb_y[j] * fl1_fx - 4.5 * pa_yy[j] * fl1_fx * pb_yy[j] - 13.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_yy[j] - 1.5 * pa_y[j] * fl1_fx * pb_yyy[j] - 1.5 * pc_y[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_yyy[j] * pb_yy[j] * pc_y[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_yyy[j]);

                t_yyy_yyy[j] += fl_s_0_0_2 * (5.625 * fl3_fx + 2.25 * pa_yy[j] * fl2_fx + 22.5 * pa_y[j] * pc_y[j] * fl2_fx + 6.75 * pa_y[j] * fl2_fx * pb_y[j] + 11.25 * pc_yy[j] * fl2_fx + 22.5 * pc_y[j] * fl2_fx * pb_y[j] + 2.25 * fl2_fx * pb_yy[j] + 1.5 * pa_yyy[j] * pc_y[j] * fl1_fx + 13.5 * pa_yy[j] * pc_y[j] * pb_y[j] * fl1_fx + 9.0 * pa_yy[j] * pc_yy[j] * fl1_fx + 27.0 * pa_y[j] * pc_yy[j] * pb_y[j] * fl1_fx + 13.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_yy[j] + 9.0 * pc_yy[j] * fl1_fx * pb_yy[j] + 1.5 * pc_y[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_yyy[j] * pb_y[j] * pc_yy[j] + 9.0 * pa_yy[j] * pc_yy[j] * pb_yy[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_yyy[j]);

                t_yyy_yyy[j] += fl_s_0_0_3 * (-1.875 * fl3_fx - 11.25 * pa_y[j] * pc_y[j] * fl2_fx - 22.5 * pc_yy[j] * fl2_fx - 11.25 * pc_y[j] * fl2_fx * pb_y[j] - 9.0 * pa_yy[j] * pc_yy[j] * fl1_fx - 27.0 * pa_y[j] * pc_yy[j] * pb_y[j] * fl1_fx - 15.0 * pa_y[j] * pc_yyy[j] * fl1_fx - 15.0 * pc_yyy[j] * pb_y[j] * fl1_fx - 9.0 * pc_yy[j] * fl1_fx * pb_yy[j] - pa_yyy[j] * pc_yyy[j] - 9.0 * pa_yy[j] * pc_yyy[j] * pb_y[j] - 9.0 * pa_y[j] * pc_yyy[j] * pb_yy[j] - pc_yyy[j] * pb_yyy[j]);

                t_yyy_yyy[j] += fl_s_0_0_4 * (11.25 * pc_yy[j] * fl2_fx + 15.0 * pa_y[j] * pc_yyy[j] * fl1_fx + 15.0 * pc_yyy[j] * pb_y[j] * fl1_fx + 7.5 * pc_yyyy[j] * fl1_fx + 3.0 * pa_yy[j] * pc_yyyy[j] + 9.0 * pa_y[j] * pc_yyyy[j] * pb_y[j] + 3.0 * pc_yyyy[j] * pb_yy[j]);

                t_yyy_yyy[j] += fl_s_0_0_5 * (-7.5 * pc_yyyy[j] * fl1_fx - 3.0 * pa_y[j] * pc_yyyyy[j] - 3.0 * pc_yyyyy[j] * pb_y[j]);

                t_yyy_yyy[j] += fl_s_0_0_6 * pc_yyyyyy[j];

                t_yyy_yyz[j] = fl_s_0_0_0 * (2.25 * pa_y[j] * fl2_fx * pb_z[j] + 1.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yyy[j] * fl1_fx * pb_z[j] + 3.0 * pa_yy[j] * fl1_fx * pb_yz[j] + 1.5 * pa_y[j] * fl1_fx * pb_yyz[j] + pa_yyy[j] * pb_yyz[j]);

                t_yyy_yyz[j] += fl_s_0_0_1 * (-2.25 * pa_y[j] * fl2_fx * pc_z[j] - 4.5 * pa_y[j] * fl2_fx * pb_z[j] - 3.75 * pc_y[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_y[j] * pc_z[j] - 3.0 * fl2_fx * pb_yz[j] - 0.5 * pa_yyy[j] * fl1_fx * pc_z[j] - 0.5 * pa_yyy[j] * fl1_fx * pb_z[j] - 4.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_z[j] - 3.0 * pa_yy[j] * fl1_fx * pb_y[j] * pc_z[j] - 3.0 * pa_yy[j] * fl1_fx * pb_yz[j] - 9.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_yz[j] - 1.5 * pa_y[j] * fl1_fx * pb_yy[j] * pc_z[j] - 1.5 * pa_y[j] * fl1_fx * pb_yyz[j] - 1.5 * pc_y[j] * fl1_fx * pb_yyz[j] - pa_yyy[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_yyy[j] * pb_yz[j] * pc_y[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_yyz[j]);

                t_yyy_yyz[j] += fl_s_0_0_2 * (4.5 * pa_y[j] * fl2_fx * pc_z[j] + 2.25 * pa_y[j] * fl2_fx * pb_z[j] + 3.75 * pc_yz[j] * fl2_fx + 7.5 * pc_y[j] * fl2_fx * pb_z[j] + 3.0 * fl2_fx * pb_y[j] * pc_z[j] + 1.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yyy[j] * fl1_fx * pc_z[j] + 4.5 * pa_yy[j] * pc_yz[j] * fl1_fx + 4.5 * pa_yy[j] * pc_y[j] * fl1_fx * pb_z[j] + 3.0 * pa_yy[j] * fl1_fx * pb_y[j] * pc_z[j] + 9.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] + 9.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] + 9.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_yz[j] + 6.0 * pc_yy[j] * fl1_fx * pb_yz[j] + 1.5 * pa_y[j] * fl1_fx * pb_yy[j] * pc_z[j] + 1.5 * pc_yz[j] * fl1_fx * pb_yy[j] + 1.5 * pc_y[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_yyy[j] * pb_y[j] * pc_yz[j] + pa_yyy[j] * pc_yy[j] * pb_z[j] + 3.0 * pa_yy[j] * pc_yz[j] * pb_yy[j] + 6.0 * pa_yy[j] * pc_yy[j] * pb_yz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_yyz[j]);

                t_yyy_yyz[j] += fl_s_0_0_3 * (-2.25 * pa_y[j] * fl2_fx * pc_z[j] - 7.5 * pc_yz[j] * fl2_fx - 3.75 * pc_y[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_y[j] * pc_z[j] - 4.5 * pa_yy[j] * pc_yz[j] * fl1_fx - 9.0 * pa_y[j] * pc_yyz[j] * fl1_fx - 9.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] - 9.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] - 5.0 * pc_yyy[j] * fl1_fx * pb_z[j] - 6.0 * pc_yyz[j] * fl1_fx * pb_y[j] - 6.0 * pc_yy[j] * fl1_fx * pb_yz[j] - 1.5 * pc_yz[j] * fl1_fx * pb_yy[j] - pa_yyy[j] * pc_yyz[j] - 6.0 * pa_yy[j] * pc_yyz[j] * pb_y[j] - 3.0 * pa_yy[j] * pc_yyy[j] * pb_z[j] - 3.0 * pa_y[j] * pc_yyz[j] * pb_yy[j] - 6.0 * pa_y[j] * pc_yyy[j] * pb_yz[j] - pc_yyy[j] * pb_yyz[j]);

                t_yyy_yyz[j] += fl_s_0_0_4 * (3.75 * pc_yz[j] * fl2_fx + 9.0 * pa_y[j] * pc_yyz[j] * fl1_fx + 5.0 * pc_yyyz[j] * fl1_fx + 5.0 * pc_yyy[j] * fl1_fx * pb_z[j] + 6.0 * pc_yyz[j] * fl1_fx * pb_y[j] + 3.0 * pa_yy[j] * pc_yyyz[j] + 6.0 * pa_y[j] * pc_yyyz[j] * pb_y[j] + 3.0 * pa_y[j] * pc_yyyy[j] * pb_z[j] + pc_yyyz[j] * pb_yy[j] + 2.0 * pc_yyyy[j] * pb_yz[j]);

                t_yyy_yyz[j] += fl_s_0_0_5 * (-5.0 * pc_yyyz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yyyyz[j] - 2.0 * pc_yyyyz[j] * pb_y[j] - pc_yyyyy[j] * pb_z[j]);

                t_yyy_yyz[j] += fl_s_0_0_6 * pc_yyyyyz[j];

                t_yyy_yzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_zz[j] + 0.5 * pa_yyy[j] * pb_y[j] * fl1_fx + 1.5 * pa_yy[j] * fl1_fx * pb_zz[j] + 1.5 * pa_y[j] * fl1_fx * pb_yzz[j] + pa_yyy[j] * pb_yzz[j]);

                t_yyy_yzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_yy[j] * fl2_fx - 2.25 * pa_y[j] * pc_y[j] * fl2_fx - 1.5 * pa_y[j] * fl2_fx * pb_y[j] - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pb_z[j] * pc_z[j] - 1.5 * fl2_fx * pb_zz[j] - 0.5 * pa_yyy[j] * pb_y[j] * fl1_fx - 0.5 * pa_yyy[j] * pc_y[j] * fl1_fx - 1.5 * pa_yy[j] * pc_y[j] * pb_y[j] * fl1_fx - 3.0 * pa_yy[j] * fl1_fx * pb_z[j] * pc_z[j] - 1.5 * pa_yy[j] * fl1_fx * pb_zz[j] - 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_zz[j] - 3.0 * pa_y[j] * fl1_fx * pb_yz[j] * pc_z[j] - 1.5 * pa_y[j] * fl1_fx * pb_yzz[j] - 1.5 * pc_y[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_yyy[j] * pb_yz[j] * pc_z[j] - pa_yyy[j] * pc_y[j] * pb_zz[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_yzz[j]);

                t_yyy_yzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 4.5 * pa_y[j] * pc_y[j] * fl2_fx + 1.5 * pc_yy[j] * fl2_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 1.5 * pc_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pc_zz[j] + 3.0 * fl2_fx * pb_z[j] * pc_z[j] + 0.75 * fl2_fx * pb_zz[j] + 0.5 * pa_yyy[j] * pc_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_y[j] * pb_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_yy[j] * fl1_fx + 1.5 * pa_yy[j] * fl1_fx * pc_zz[j] + 3.0 * pa_yy[j] * fl1_fx * pb_z[j] * pc_z[j] + 1.5 * pa_y[j] * pc_yy[j] * pb_y[j] * fl1_fx + 9.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] + 4.5 * pa_y[j] * pc_y[j] * fl1_fx * pb_zz[j] + 3.0 * pc_yy[j] * fl1_fx * pb_zz[j] + 1.5 * pa_y[j] * fl1_fx * pb_y[j] * pc_zz[j] + 3.0 * pa_y[j] * fl1_fx * pb_yz[j] * pc_z[j] + 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] + 1.5 * pc_y[j] * fl1_fx * pb_yzz[j] + pa_yyy[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_yyy[j] * pc_yz[j] * pb_z[j] + 6.0 * pa_yy[j] * pc_yz[j] * pb_yz[j] + 3.0 * pa_yy[j] * pc_yy[j] * pb_zz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_yzz[j]);

                t_yyy_yzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_y[j] * pc_y[j] * fl2_fx - 3.0 * pc_yy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pb_z[j] * pc_z[j] - 1.5 * pa_yy[j] * pc_yy[j] * fl1_fx - 1.5 * pa_yy[j] * fl1_fx * pc_zz[j] - 1.5 * pa_y[j] * pc_yy[j] * pb_y[j] * fl1_fx - 1.5 * pa_y[j] * pc_yyy[j] * fl1_fx - 4.5 * pa_y[j] * pc_yzz[j] * fl1_fx - 9.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_yyy[j] * pb_y[j] * fl1_fx - 6.0 * pc_yyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yy[j] * fl1_fx * pb_zz[j] - 1.5 * pa_y[j] * fl1_fx * pb_y[j] * pc_zz[j] - 1.5 * pc_yzz[j] * fl1_fx * pb_y[j] - 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] - pa_yyy[j] * pc_yzz[j] - 3.0 * pa_yy[j] * pc_yzz[j] * pb_y[j] - 6.0 * pa_yy[j] * pc_yyz[j] * pb_z[j] - 6.0 * pa_y[j] * pc_yyz[j] * pb_yz[j] - 3.0 * pa_y[j] * pc_yyy[j] * pb_zz[j] - pc_yyy[j] * pb_yzz[j]);

                t_yyy_yzz[j] += fl_s_0_0_4 * (1.5 * pc_yy[j] * fl2_fx + 0.75 * fl2_fx * pc_zz[j] + 1.5 * pa_y[j] * pc_yyy[j] * fl1_fx + 4.5 * pa_y[j] * pc_yzz[j] * fl1_fx + 0.5 * pc_yyy[j] * pb_y[j] * fl1_fx + 0.5 * pc_yyyy[j] * fl1_fx + 3.0 * pc_yyzz[j] * fl1_fx + 6.0 * pc_yyz[j] * fl1_fx * pb_z[j] + 1.5 * pc_yzz[j] * fl1_fx * pb_y[j] + 3.0 * pa_yy[j] * pc_yyzz[j] + 3.0 * pa_y[j] * pc_yyzz[j] * pb_y[j] + 6.0 * pa_y[j] * pc_yyyz[j] * pb_z[j] + 2.0 * pc_yyyz[j] * pb_yz[j] + pc_yyyy[j] * pb_zz[j]);

                t_yyy_yzz[j] += fl_s_0_0_5 * (-0.5 * pc_yyyy[j] * fl1_fx - 3.0 * pc_yyzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yyyzz[j] - pc_yyyzz[j] * pb_y[j] - 2.0 * pc_yyyyz[j] * pb_z[j]);

                t_yyy_yzz[j] += fl_s_0_0_6 * pc_yyyyzz[j];

                t_yyy_zzz[j] = fl_s_0_0_0 * (2.25 * pa_y[j] * fl2_fx * pb_z[j] + 1.5 * pa_yyy[j] * pb_z[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_zzz[j] + pa_yyy[j] * pb_zzz[j]);

                t_yyy_zzz[j] += fl_s_0_0_1 * (-4.5 * pa_y[j] * fl2_fx * pb_z[j] - 2.25 * pa_y[j] * fl2_fx * pc_z[j] - 2.25 * pc_y[j] * fl2_fx * pb_z[j] - 1.5 * pa_yyy[j] * pb_z[j] * fl1_fx - 1.5 * pa_yyy[j] * pc_z[j] * fl1_fx - 4.5 * pa_yy[j] * pc_y[j] * pb_z[j] * fl1_fx - 4.5 * pa_y[j] * fl1_fx * pb_zz[j] * pc_z[j] - 1.5 * pa_y[j] * fl1_fx * pb_zzz[j] - 1.5 * pc_y[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_yyy[j] * pb_zz[j] * pc_z[j] - 3.0 * pa_yy[j] * pc_y[j] * pb_zzz[j]);

                t_yyy_zzz[j] += fl_s_0_0_2 * (4.5 * pa_y[j] * fl2_fx * pc_z[j] + 2.25 * pa_y[j] * fl2_fx * pb_z[j] + 4.5 * pc_y[j] * fl2_fx * pb_z[j] + 2.25 * pc_yz[j] * fl2_fx + 1.5 * pa_yyy[j] * pc_z[j] * fl1_fx + 4.5 * pa_yy[j] * pc_y[j] * pb_z[j] * fl1_fx + 4.5 * pa_yy[j] * pc_yz[j] * fl1_fx + 4.5 * pa_y[j] * pc_yy[j] * pb_z[j] * fl1_fx + 4.5 * pa_y[j] * fl1_fx * pb_z[j] * pc_zz[j] + 4.5 * pa_y[j] * fl1_fx * pb_zz[j] * pc_z[j] + 4.5 * pc_yz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_y[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_yyy[j] * pb_z[j] * pc_zz[j] + 9.0 * pa_yy[j] * pc_yz[j] * pb_zz[j] + 3.0 * pa_y[j] * pc_yy[j] * pb_zzz[j]);

                t_yyy_zzz[j] += fl_s_0_0_3 * (-2.25 * pa_y[j] * fl2_fx * pc_z[j] - 4.5 * pc_yz[j] * fl2_fx - 2.25 * pc_y[j] * fl2_fx * pb_z[j] - 4.5 * pa_yy[j] * pc_yz[j] * fl1_fx - 4.5 * pa_y[j] * pc_yy[j] * pb_z[j] * fl1_fx - 4.5 * pa_y[j] * pc_yyz[j] * fl1_fx - 1.5 * pc_yyy[j] * pb_z[j] * fl1_fx - 1.5 * pa_y[j] * fl1_fx * pc_zzz[j] - 4.5 * pa_y[j] * fl1_fx * pb_z[j] * pc_zz[j] - 4.5 * pc_yzz[j] * fl1_fx * pb_z[j] - 4.5 * pc_yz[j] * fl1_fx * pb_zz[j] - pa_yyy[j] * pc_zzz[j] - 9.0 * pa_yy[j] * pc_yzz[j] * pb_z[j] - 9.0 * pa_y[j] * pc_yyz[j] * pb_zz[j] - pc_yyy[j] * pb_zzz[j]);

                t_yyy_zzz[j] += fl_s_0_0_4 * (2.25 * pc_yz[j] * fl2_fx + 4.5 * pa_y[j] * pc_yyz[j] * fl1_fx + 1.5 * pc_yyy[j] * pb_z[j] * fl1_fx + 1.5 * pc_yyyz[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pc_zzz[j] + 1.5 * pc_yzzz[j] * fl1_fx + 4.5 * pc_yzz[j] * fl1_fx * pb_z[j] + 3.0 * pa_yy[j] * pc_yzzz[j] + 9.0 * pa_y[j] * pc_yyzz[j] * pb_z[j] + 3.0 * pc_yyyz[j] * pb_zz[j]);

                t_yyy_zzz[j] += fl_s_0_0_5 * (-1.5 * pc_yyyz[j] * fl1_fx - 1.5 * pc_yzzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yyzzz[j] - 3.0 * pc_yyyzz[j] * pb_z[j]);

                t_yyy_zzz[j] += fl_s_0_0_6 * pc_yyyzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_70_80(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (70,80)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(19 * idx + 6);

            auto pa_yz = paDistances.data(19 * idx + 7);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yyz = paDistances.data(19 * idx + 16);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxyy = pcDistances.data(83 * idx + 37);

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxyyy = pcDistances.data(83 * idx + 40);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xyyyy = pcDistances.data(83 * idx + 44);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_yyyyy = pcDistances.data(83 * idx + 49);

            auto pc_yyyyz = pcDistances.data(83 * idx + 50);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            auto pc_yzzzz = pcDistances.data(83 * idx + 53);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxyyz = pcDistances.data(83 * idx + 62);

            auto pc_xxyyyz = pcDistances.data(83 * idx + 66);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xyyyyz = pcDistances.data(83 * idx + 71);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            auto pc_yyyyyz = pcDistances.data(83 * idx + 77);

            auto pc_yyyyzz = pcDistances.data(83 * idx + 78);

            auto pc_yyyzzz = pcDistances.data(83 * idx + 79);

            auto pc_yyzzzz = pcDistances.data(83 * idx + 80);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_yyz_xxx = primBuffer.data(100 * idx + 70);

            auto t_yyz_xxy = primBuffer.data(100 * idx + 71);

            auto t_yyz_xxz = primBuffer.data(100 * idx + 72);

            auto t_yyz_xyy = primBuffer.data(100 * idx + 73);

            auto t_yyz_xyz = primBuffer.data(100 * idx + 74);

            auto t_yyz_xzz = primBuffer.data(100 * idx + 75);

            auto t_yyz_yyy = primBuffer.data(100 * idx + 76);

            auto t_yyz_yyz = primBuffer.data(100 * idx + 77);

            auto t_yyz_yzz = primBuffer.data(100 * idx + 78);

            auto t_yyz_zzz = primBuffer.data(100 * idx + 79);

            // Batch of Integrals (70,80)

            #pragma omp simd aligned(fx, pa_y, pa_yy, pa_yyz, pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxy, pc_xxxyy, pc_xxxyyz, pc_xxxyz, pc_xxxz, pc_xxy, \
                                     pc_xxyy, pc_xxyyy, pc_xxyyyz, pc_xxyyz, pc_xxyyzz, pc_xxyz, pc_xxyzz, pc_xxz, \
                                     pc_xxzz, pc_xy, pc_xyy, pc_xyyy, pc_xyyyy, pc_xyyyyz, pc_xyyyz, pc_xyyyzz, pc_xyyz, \
                                     pc_xyyzz, pc_xyyzzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xz, pc_xzz, pc_xzzz, pc_y, pc_yy, \
                                     pc_yyy, pc_yyyy, pc_yyyyy, pc_yyyyyz, pc_yyyyz, pc_yyyyzz, pc_yyyz, pc_yyyzz, \
                                     pc_yyyzzz, pc_yyz, pc_yyzz, pc_yyzzz, pc_yyzzzz, pc_yz, pc_yzz, pc_yzzz, pc_yzzzz, pc_z, \
                                     pc_zz, pc_zzz, pc_zzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, s_0_0_5, \
                                     s_0_0_6, t_yyz_xxx, t_yyz_xxy, t_yyz_xxz, t_yyz_xyy, t_yyz_xyz, t_yyz_xzz, \
                                     t_yyz_yyy, t_yyz_yyz, t_yyz_yzz, t_yyz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yyz_xxx[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_yyz[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_xxx[j] + pa_yyz[j] * pb_xxx[j]);

                t_yyz_xxx[j] += fl_s_0_0_1 * (-1.5 * fl2_fx * pa_z[j] * pb_x[j] - 0.75 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 1.5 * pa_yyz[j] * pb_x[j] * fl1_fx - 1.5 * pa_yyz[j] * pc_x[j] * fl1_fx - 1.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx - 3.0 * pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx - 1.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_x[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxx[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxx[j] - 3.0 * pa_yyz[j] * pb_xx[j] * pc_x[j] - pa_yy[j] * pc_z[j] * pb_xxx[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xxx[j]);

                t_yyz_xxx[j] += fl_s_0_0_2 * (1.5 * fl2_fx * pa_z[j] * pc_x[j] + 1.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.75 * fl2_fx * pc_xz[j] + 0.75 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_yyz[j] * pc_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_xz[j] * fl1_fx + 3.0 * pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx + 1.5 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_xx[j] + 1.5 * fl1_fx * pc_xz[j] * pb_xx[j] + 1.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_x[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxx[j] + 3.0 * pa_yyz[j] * pb_x[j] * pc_xx[j] + 3.0 * pa_yy[j] * pc_xz[j] * pb_xx[j] + 6.0 * pa_yz[j] * pc_xy[j] * pb_xx[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xxx[j] + pc_yy[j] * pa_z[j] * pb_xxx[j]);

                t_yyz_xxx[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xz[j] - 0.75 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 1.5 * pa_yy[j] * pc_xz[j] * fl1_fx - 3.0 * pa_yz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx - 1.5 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx - 1.5 * pc_xyy[j] * pa_z[j] * fl1_fx - 1.5 * pc_yyz[j] * pb_x[j] * fl1_fx - 0.5 * fl1_fx * pa_z[j] * pc_xxx[j] - 1.5 * fl1_fx * pc_xxz[j] * pb_x[j] - 1.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_xx[j] - 1.5 * fl1_fx * pc_xz[j] * pb_xx[j] - pa_yyz[j] * pc_xxx[j] - 3.0 * pa_yy[j] * pc_xxz[j] * pb_x[j] - 6.0 * pa_yz[j] * pc_xxy[j] * pb_x[j] - 6.0 * pa_y[j] * pc_xyz[j] * pb_xx[j] - 3.0 * pc_xyy[j] * pa_z[j] * pb_xx[j] - pc_yyz[j] * pb_xxx[j]);

                t_yyz_xxx[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xz[j] + 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx + 1.5 * pc_xyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_yyz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 0.5 * fl1_fx * pc_xxxz[j] + 0.5 * fl1_fx * pa_z[j] * pc_xxx[j] + 1.5 * fl1_fx * pc_xxz[j] * pb_x[j] + pa_yy[j] * pc_xxxz[j] + 2.0 * pa_yz[j] * pc_xxxy[j] + 6.0 * pa_y[j] * pc_xxyz[j] * pb_x[j] + 3.0 * pc_xxyy[j] * pa_z[j] * pb_x[j] + 3.0 * pc_xyyz[j] * pb_xx[j]);

                t_yyz_xxx[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * fl1_fx * pc_xxxz[j] - 2.0 * pa_y[j] * pc_xxxyz[j] - pc_xxxyy[j] * pa_z[j] - 3.0 * pc_xxyyz[j] * pb_x[j]);

                t_yyz_xxx[j] += fl_s_0_0_6 * pc_xxxyyz[j];

                t_yyz_xxy[j] = fl_s_0_0_0 * (0.5 * pa_yz[j] * fl2_fx + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_yyz[j] * fl1_fx * pb_y[j] + pa_yz[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxy[j] + pa_yyz[j] * pb_xxy[j]);

                t_yyz_xxy[j] += fl_s_0_0_1 * (-pa_yz[j] * fl2_fx - 0.5 * pa_y[j] * fl2_fx * pc_z[j] - 0.75 * pc_y[j] * fl2_fx * pa_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_y[j] - 0.25 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * pa_yyz[j] * fl1_fx * pc_y[j] - 0.5 * pa_yyz[j] * fl1_fx * pb_y[j] - 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_y[j] - pa_yz[j] * pc_y[j] * fl1_fx * pb_y[j] - 2.0 * pa_yz[j] * fl1_fx * pb_x[j] * pc_x[j] - pa_y[j] * fl1_fx * pc_z[j] * pb_xx[j] - pa_yz[j] * fl1_fx * pb_xx[j] - 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_xx[j] - fl1_fx * pa_z[j] * pb_xy[j] * pc_x[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxy[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxy[j] - pa_yyz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_yyz[j] * pb_xy[j] * pc_x[j] - pa_yy[j] * pc_z[j] * pb_xxy[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xxy[j]);

                t_yyz_xxy[j] += fl_s_0_0_2 * (pa_y[j] * fl2_fx * pc_z[j] + 0.5 * pa_yz[j] * fl2_fx + 1.5 * pc_y[j] * fl2_fx * pa_z[j] + 0.75 * pc_yz[j] * fl2_fx + 0.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_yyz[j] * fl1_fx * pc_y[j] + 0.5 * pa_yy[j] * pc_yz[j] * fl1_fx + 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_y[j] + pa_yz[j] * pc_yy[j] * fl1_fx + pa_yz[j] * pc_y[j] * fl1_fx * pb_y[j] + pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] + pa_yz[j] * fl1_fx * pc_xx[j] + 2.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_x[j] + 2.0 * pa_yz[j] * fl1_fx * pb_x[j] * pc_x[j] + pa_y[j] * fl1_fx * pc_z[j] * pb_xx[j] + 0.5 * pc_yy[j] * pa_z[j] * fl1_fx * pb_y[j] + 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_x[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] + 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pc_xx[j] * pb_y[j] + fl1_fx * pc_xz[j] * pb_xy[j] + fl1_fx * pa_z[j] * pb_xy[j] * pc_x[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxy[j] + 2.0 * pa_yyz[j] * pb_x[j] * pc_xy[j] + pa_yyz[j] * pc_xx[j] * pb_y[j] + pa_yy[j] * pc_yz[j] * pb_xx[j] + 2.0 * pa_yy[j] * pc_xz[j] * pb_xy[j] + 2.0 * pa_yz[j] * pc_yy[j] * pb_xx[j] + 4.0 * pa_yz[j] * pc_xy[j] * pb_xy[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xxy[j] + pc_yy[j] * pa_z[j] * pb_xxy[j]);

                t_yyz_xxy[j] += fl_s_0_0_3 * (-0.5 * pa_y[j] * fl2_fx * pc_z[j] - 1.5 * pc_yz[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pa_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * pa_yy[j] * pc_yz[j] * fl1_fx - pa_yz[j] * pc_yy[j] * fl1_fx - pa_y[j] * pc_yyz[j] * fl1_fx - pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] - pa_y[j] * fl1_fx * pc_xxz[j] - pa_yz[j] * fl1_fx * pc_xx[j] - 2.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_x[j] - 0.5 * pc_yyy[j] * pa_z[j] * fl1_fx - 0.5 * pc_yy[j] * pa_z[j] * fl1_fx * pb_y[j] - 0.5 * pc_yyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_xxy[j] * fl1_fx * pa_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_x[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] - 0.5 * fl1_fx * pc_xxz[j] * pb_y[j] - 0.5 * fl1_fx * pa_z[j] * pc_xx[j] * pb_y[j] - fl1_fx * pc_xz[j] * pb_xy[j] - pa_yyz[j] * pc_xxy[j] - 2.0 * pa_yy[j] * pc_xyz[j] * pb_x[j] - pa_yy[j] * pc_xxz[j] * pb_y[j] - 4.0 * pa_yz[j] * pc_xyy[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xxy[j] * pb_y[j] - 2.0 * pa_y[j] * pc_yyz[j] * pb_xx[j] - 4.0 * pa_y[j] * pc_xyz[j] * pb_xy[j] - pc_yyy[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xyy[j] * pa_z[j] * pb_xy[j] - pc_yyz[j] * pb_xxy[j]);

                t_yyz_xxy[j] += fl_s_0_0_4 * (0.75 * pc_yz[j] * fl2_fx + pa_y[j] * pc_yyz[j] * fl1_fx + pa_y[j] * fl1_fx * pc_xxz[j] + 0.5 * pc_yyy[j] * pa_z[j] * fl1_fx + 0.5 * pc_yyyz[j] * fl1_fx + 0.5 * pc_yyz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xxyz[j] * fl1_fx + 1.5 * pc_xxy[j] * fl1_fx * pa_z[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pc_xxz[j] * pb_y[j] + pa_yy[j] * pc_xxyz[j] + 2.0 * pa_yz[j] * pc_xxyy[j] + 4.0 * pa_y[j] * pc_xyyz[j] * pb_x[j] + 2.0 * pa_y[j] * pc_xxyz[j] * pb_y[j] + 2.0 * pc_xyyy[j] * pa_z[j] * pb_x[j] + pc_xxyy[j] * pa_z[j] * pb_y[j] + pc_yyyz[j] * pb_xx[j] + 2.0 * pc_xyyz[j] * pb_xy[j]);

                t_yyz_xxy[j] += fl_s_0_0_5 * (-0.5 * pc_yyyz[j] * fl1_fx - 1.5 * pc_xxyz[j] * fl1_fx - 2.0 * pa_y[j] * pc_xxyyz[j] - pc_xxyyy[j] * pa_z[j] - 2.0 * pc_xyyyz[j] * pb_x[j] - pc_xxyyz[j] * pb_y[j]);

                t_yyz_xxy[j] += fl_s_0_0_6 * pc_xxyyyz[j];

                t_yyz_xxz[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxz[j] + pa_yyz[j] * pb_xxz[j]);

                t_yyz_xxz[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * pa_yy[j] * fl2_fx - 0.5 * pa_y[j] * pc_y[j] * fl2_fx - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_x[j] * pc_x[j] - 0.5 * fl2_fx * pb_xx[j] - 0.5 * pa_yyz[j] * fl1_fx * pc_z[j] - 0.5 * pa_yyz[j] * fl1_fx * pb_z[j] - 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_yy[j] * fl1_fx * pb_x[j] * pc_x[j] - 0.5 * pa_yy[j] * fl1_fx * pb_xx[j] - pa_yz[j] * pc_y[j] * fl1_fx * pb_z[j] - pa_y[j] * pc_y[j] * fl1_fx * pb_xx[j] - 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_z[j] - fl1_fx * pa_z[j] * pb_xz[j] * pc_x[j] - 0.5 * fl1_fx * pc_z[j] * pb_xxz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xxz[j] - pa_yyz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_yyz[j] * pb_xz[j] * pc_x[j] - pa_yy[j] * pc_z[j] * pb_xxz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xxz[j]);

                t_yyz_xxz[j] += fl_s_0_0_2 * (0.375 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + pa_y[j] * pc_y[j] * fl2_fx + 0.25 * pc_yy[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pc_z[j] + 0.25 * fl2_fx * pc_zz[j] + 0.5 * fl2_fx * pc_z[j] * pb_z[j] + 0.25 * fl2_fx * pc_xx[j] + fl2_fx * pb_x[j] * pc_x[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yyz[j] * fl1_fx * pc_z[j] + 0.5 * pa_yy[j] * pc_zz[j] * fl1_fx + 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pc_xx[j] + pa_yy[j] * fl1_fx * pb_x[j] * pc_x[j] + pa_yz[j] * pc_yz[j] * fl1_fx + pa_yz[j] * pc_y[j] * fl1_fx * pb_z[j] + pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] + 2.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_x[j] + pa_y[j] * pc_y[j] * fl1_fx * pb_xx[j] + 0.5 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_yy[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_z[j] * pb_x[j] * pc_xz[j] + 0.5 * fl1_fx * pa_z[j] * pc_xx[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] + fl1_fx * pc_xz[j] * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] * pc_z[j] + fl1_fx * pa_z[j] * pb_xz[j] * pc_x[j] + 0.5 * fl1_fx * pc_z[j] * pb_xxz[j] + 2.0 * pa_yyz[j] * pb_x[j] * pc_xz[j] + pa_yyz[j] * pc_xx[j] * pb_z[j] + pa_yy[j] * pc_zz[j] * pb_xx[j] + 2.0 * pa_yy[j] * pc_xz[j] * pb_xz[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_xx[j] + 4.0 * pa_yz[j] * pc_xy[j] * pb_xz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xxz[j] + pc_yy[j] * pa_z[j] * pb_xxz[j]);

                t_yyz_xxz[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * pa_y[j] * pc_y[j] * fl2_fx - 0.5 * pc_yy[j] * fl2_fx - 0.5 * fl2_fx * pc_zz[j] - 0.5 * fl2_fx * pc_xx[j] - 0.25 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_x[j] * pc_x[j] - 0.5 * pa_yy[j] * pc_zz[j] * fl1_fx - 0.5 * pa_yy[j] * fl1_fx * pc_xx[j] - pa_yz[j] * pc_yz[j] * fl1_fx - pa_y[j] * pc_yzz[j] * fl1_fx - pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] - pa_y[j] * pc_xxy[j] * fl1_fx - 2.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_x[j] - 0.5 * pc_yyz[j] * pa_z[j] * fl1_fx - 0.5 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] - 0.5 * pc_yyz[j] * fl1_fx * pb_z[j] - pc_xyy[j] * fl1_fx * pb_x[j] - 0.5 * pc_yy[j] * fl1_fx * pb_xx[j] - 0.5 * fl1_fx * pa_z[j] * pc_xxz[j] - fl1_fx * pc_xzz[j] * pb_x[j] - 0.5 * fl1_fx * pc_xxz[j] * pb_z[j] - fl1_fx * pa_z[j] * pb_x[j] * pc_xz[j] - 0.5 * fl1_fx * pa_z[j] * pc_xx[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] - fl1_fx * pc_xz[j] * pb_xz[j] - pa_yyz[j] * pc_xxz[j] - 2.0 * pa_yy[j] * pc_xzz[j] * pb_x[j] - pa_yy[j] * pc_xxz[j] * pb_z[j] - 4.0 * pa_yz[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xxy[j] * pb_z[j] - 2.0 * pa_y[j] * pc_yzz[j] * pb_xx[j] - 4.0 * pa_y[j] * pc_xyz[j] * pb_xz[j] - pc_yyz[j] * pa_z[j] * pb_xx[j] - 2.0 * pc_xyy[j] * pa_z[j] * pb_xz[j] - pc_yyz[j] * pb_xxz[j]);

                t_yyz_xxz[j] += fl_s_0_0_4 * (0.25 * pc_yy[j] * fl2_fx + 0.25 * fl2_fx * pc_zz[j] + 0.25 * fl2_fx * pc_xx[j] + pa_y[j] * pc_yzz[j] * fl1_fx + pa_y[j] * pc_xxy[j] * fl1_fx + 0.5 * pc_yyz[j] * pa_z[j] * fl1_fx + 0.5 * pc_yyzz[j] * fl1_fx + 0.5 * pc_yyz[j] * fl1_fx * pb_z[j] + 0.5 * pc_xxyy[j] * fl1_fx + pc_xyy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pc_xxzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_xxz[j] + fl1_fx * pc_xzz[j] * pb_x[j] + 0.5 * fl1_fx * pc_xxz[j] * pb_z[j] + pa_yy[j] * pc_xxzz[j] + 2.0 * pa_yz[j] * pc_xxyz[j] + 4.0 * pa_y[j] * pc_xyzz[j] * pb_x[j] + 2.0 * pa_y[j] * pc_xxyz[j] * pb_z[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_x[j] + pc_xxyy[j] * pa_z[j] * pb_z[j] + pc_yyzz[j] * pb_xx[j] + 2.0 * pc_xyyz[j] * pb_xz[j]);

                t_yyz_xxz[j] += fl_s_0_0_5 * (-0.5 * pc_yyzz[j] * fl1_fx - 0.5 * pc_xxyy[j] * fl1_fx - 0.5 * fl1_fx * pc_xxzz[j] - 2.0 * pa_y[j] * pc_xxyzz[j] - pc_xxyyz[j] * pa_z[j] - 2.0 * pc_xyyzz[j] * pb_x[j] - pc_xxyyz[j] * pb_z[j]);

                t_yyz_xxz[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_yyz_xyy[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_yyz[j] * pb_x[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_z[j] * pb_xyy[j] + pa_yyz[j] * pb_xyy[j]);

                t_yyz_xyy[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 1.5 * fl2_fx * pa_z[j] * pb_x[j] - 0.5 * pa_yyz[j] * pb_x[j] * fl1_fx - 0.5 * pa_yyz[j] * pc_x[j] * fl1_fx - 0.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx - 3.0 * pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx - 2.0 * pa_yz[j] * fl1_fx * pc_x[j] * pb_y[j] - 2.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_xy[j] - 2.0 * pa_yz[j] * fl1_fx * pb_xy[j] - 3.0 * pc_y[j] * fl1_fx * pa_z[j] * pb_xy[j] - 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_yy[j] - 0.5 * fl1_fx * pc_z[j] * pb_xyy[j] - 0.5 * fl1_fx * pa_z[j] * pb_xyy[j] - 2.0 * pa_yyz[j] * pb_xy[j] * pc_y[j] - pa_yyz[j] * pc_x[j] * pb_yy[j] - pa_yy[j] * pc_z[j] * pb_xyy[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xyy[j]);

                t_yyz_xyy[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_xz[j] + 1.5 * fl2_fx * pa_z[j] * pc_x[j] + 1.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_yyz[j] * pc_x[j] * fl1_fx + 0.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx + 0.5 * pa_yy[j] * pc_xz[j] * fl1_fx + 3.0 * pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx + 2.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_y[j] + 2.0 * pa_yz[j] * fl1_fx * pc_x[j] * pb_y[j] + 2.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_xy[j] + 3.0 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx + 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_y[j] + 3.0 * pc_yz[j] * fl1_fx * pb_xy[j] + 3.0 * pc_y[j] * fl1_fx * pa_z[j] * pb_xy[j] + 0.5 * fl1_fx * pc_xz[j] * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_yy[j] + 0.5 * fl1_fx * pc_z[j] * pb_xyy[j] + pa_yyz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_yyz[j] * pc_xy[j] * pb_y[j] + 2.0 * pa_yy[j] * pc_yz[j] * pb_xy[j] + pa_yy[j] * pc_xz[j] * pb_yy[j] + 4.0 * pa_yz[j] * pc_yy[j] * pb_xy[j] + 2.0 * pa_yz[j] * pc_xy[j] * pb_yy[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xyy[j] + pc_yy[j] * pa_z[j] * pb_xyy[j]);

                t_yyz_xyy[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xz[j] - 0.75 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * pa_yy[j] * pc_xz[j] * fl1_fx - 3.0 * pa_yz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx - 2.0 * pa_y[j] * fl1_fx * pc_xz[j] * pb_y[j] - 3.0 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyy[j] * pa_z[j] * fl1_fx - 3.0 * pc_yyz[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 3.0 * pc_xy[j] * fl1_fx * pa_z[j] * pb_y[j] - 3.0 * pc_yz[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pc_xz[j] * pb_yy[j] - pa_yyz[j] * pc_xyy[j] - pa_yy[j] * pc_yyz[j] * pb_x[j] - 2.0 * pa_yy[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_yz[j] * pc_yyy[j] * pb_x[j] - 4.0 * pa_yz[j] * pc_xyy[j] * pb_y[j] - 4.0 * pa_y[j] * pc_yyz[j] * pb_xy[j] - 2.0 * pa_y[j] * pc_xyz[j] * pb_yy[j] - 2.0 * pc_yyy[j] * pa_z[j] * pb_xy[j] - pc_xyy[j] * pa_z[j] * pb_yy[j] - pc_yyz[j] * pb_xyy[j]);

                t_yyz_xyy[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xz[j] + 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xyy[j] * pa_z[j] * fl1_fx + 3.0 * pc_yyz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xyyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + pa_yy[j] * pc_xyyz[j] + 2.0 * pa_yz[j] * pc_xyyy[j] + 2.0 * pa_y[j] * pc_yyyz[j] * pb_x[j] + 4.0 * pa_y[j] * pc_xyyz[j] * pb_y[j] + pc_yyyy[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xyyy[j] * pa_z[j] * pb_y[j] + 2.0 * pc_yyyz[j] * pb_xy[j] + pc_xyyz[j] * pb_yy[j]);

                t_yyz_xyy[j] += fl_s_0_0_5 * (-3.0 * pc_xyyz[j] * fl1_fx - 2.0 * pa_y[j] * pc_xyyyz[j] - pc_xyyyy[j] * pa_z[j] - pc_yyyyz[j] * pb_x[j] - 2.0 * pc_xyyyz[j] * pb_y[j]);

                t_yyz_xyy[j] += fl_s_0_0_6 * pc_xyyyyz[j];

                t_yyz_xyz[j] = fl_s_0_0_0 * (0.5 * pa_y[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_yy[j] * fl1_fx * pb_xy[j] + pa_yz[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xyz[j] + pa_yyz[j] * pb_xyz[j]);

                t_yyz_xyz[j] += fl_s_0_0_1 * (-0.5 * pa_y[j] * fl2_fx * pc_x[j] - pa_y[j] * fl2_fx * pb_x[j] - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.25 * fl2_fx * pc_x[j] * pb_y[j] - 0.5 * fl2_fx * pb_xy[j] - 0.5 * pa_yy[j] * fl1_fx * pb_x[j] * pc_y[j] - 0.5 * pa_yy[j] * fl1_fx * pc_x[j] * pb_y[j] - 0.5 * pa_yy[j] * fl1_fx * pb_xy[j] - pa_y[j] * pc_y[j] * fl1_fx * pb_xy[j] - pa_yz[j] * fl1_fx * pb_x[j] * pc_z[j] - pa_yz[j] * fl1_fx * pc_x[j] * pb_z[j] - pa_y[j] * fl1_fx * pc_z[j] * pb_xz[j] - pa_yz[j] * fl1_fx * pb_xz[j] - 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_xz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xy[j] * pc_z[j] - 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_yz[j] - 0.5 * fl1_fx * pc_z[j] * pb_xyz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xyz[j] - pa_yyz[j] * pb_xy[j] * pc_z[j] - pa_yyz[j] * pb_xz[j] * pc_y[j] - pa_yyz[j] * pc_x[j] * pb_yz[j] - pa_yy[j] * pc_z[j] * pb_xyz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xyz[j]);

                t_yyz_xyz[j] += fl_s_0_0_2 * (pa_y[j] * fl2_fx * pc_x[j] + 0.5 * pa_y[j] * fl2_fx * pb_x[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pc_y[j] * fl2_fx * pb_x[j] + 0.5 * fl2_fx * pc_x[j] * pb_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_yy[j] * fl1_fx * pc_xy[j] + 0.5 * pa_yy[j] * fl1_fx * pb_x[j] * pc_y[j] + 0.5 * pa_yy[j] * fl1_fx * pc_x[j] * pb_y[j] + pa_y[j] * pc_yy[j] * fl1_fx * pb_x[j] + pa_y[j] * pc_xy[j] * fl1_fx * pb_y[j] + pa_y[j] * pc_y[j] * fl1_fx * pb_xy[j] + pa_yz[j] * fl1_fx * pc_xz[j] + pa_y[j] * fl1_fx * pc_zz[j] * pb_x[j] + pa_y[j] * fl1_fx * pc_xz[j] * pb_z[j] + pa_yz[j] * fl1_fx * pb_x[j] * pc_z[j] + pa_yz[j] * fl1_fx * pc_x[j] * pb_z[j] + pa_y[j] * fl1_fx * pc_z[j] * pb_xz[j] + 0.5 * pc_yy[j] * fl1_fx * pb_xy[j] + 1.5 * pc_yz[j] * fl1_fx * pa_z[j] * pb_x[j] + 1.5 * pc_xy[j] * fl1_fx * pa_z[j] * pb_z[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xz[j] + 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pc_xz[j] * pb_y[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xy[j] + 0.5 * fl1_fx * pc_xz[j] * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xy[j] * pc_z[j] + 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_yz[j] + 0.5 * fl1_fx * pc_z[j] * pb_xyz[j] + pa_yyz[j] * pb_x[j] * pc_yz[j] + pa_yyz[j] * pc_xz[j] * pb_y[j] + pa_yyz[j] * pc_xy[j] * pb_z[j] + pa_yy[j] * pc_zz[j] * pb_xy[j] + pa_yy[j] * pc_yz[j] * pb_xz[j] + pa_yy[j] * pc_xz[j] * pb_yz[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_xy[j] + 2.0 * pa_yz[j] * pc_yy[j] * pb_xz[j] + 2.0 * pa_yz[j] * pc_xy[j] * pb_yz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xyz[j] + pc_yy[j] * pa_z[j] * pb_xyz[j]);

                t_yyz_xyz[j] += fl_s_0_0_3 * (-0.5 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.25 * fl2_fx * pc_x[j] * pb_y[j] - 0.5 * pa_yy[j] * fl1_fx * pc_xy[j] - pa_y[j] * pc_xyy[j] * fl1_fx - pa_y[j] * pc_yy[j] * fl1_fx * pb_x[j] - pa_y[j] * pc_xy[j] * fl1_fx * pb_y[j] - pa_y[j] * fl1_fx * pc_xzz[j] - pa_yz[j] * fl1_fx * pc_xz[j] - pa_y[j] * fl1_fx * pc_zz[j] * pb_x[j] - pa_y[j] * fl1_fx * pc_xz[j] * pb_z[j] - 0.5 * pc_yyy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xyy[j] * fl1_fx * pb_y[j] - 0.5 * pc_yy[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xyz[j] * fl1_fx * pa_z[j] - 1.5 * pc_yzz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] - 1.5 * pc_yz[j] * fl1_fx * pa_z[j] * pb_x[j] - 1.5 * pc_xy[j] * fl1_fx * pa_z[j] * pb_z[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pc_xzz[j] * pb_y[j] - 0.5 * fl1_fx * pa_z[j] * pc_xz[j] * pb_y[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xy[j] - 0.5 * fl1_fx * pc_xz[j] * pb_yz[j] - pa_yyz[j] * pc_xyz[j] - pa_yy[j] * pc_yzz[j] * pb_x[j] - pa_yy[j] * pc_xzz[j] * pb_y[j] - pa_yy[j] * pc_xyz[j] * pb_z[j] - 2.0 * pa_yz[j] * pc_yyz[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_yz[j] * pc_xyy[j] * pb_z[j] - 2.0 * pa_y[j] * pc_yzz[j] * pb_xy[j] - 2.0 * pa_y[j] * pc_yyz[j] * pb_xz[j] - 2.0 * pa_y[j] * pc_xyz[j] * pb_yz[j] - pc_yyz[j] * pa_z[j] * pb_xy[j] - pc_yyy[j] * pa_z[j] * pb_xz[j] - pc_xyy[j] * pa_z[j] * pb_yz[j] - pc_yyz[j] * pb_xyz[j]);

                t_yyz_xyz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + pa_y[j] * pc_xyy[j] * fl1_fx + pa_y[j] * fl1_fx * pc_xzz[j] + 0.5 * pc_xyyy[j] * fl1_fx + 0.5 * pc_yyy[j] * fl1_fx * pb_x[j] + 0.5 * pc_xyy[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyzz[j] * fl1_fx + 1.5 * pc_xyz[j] * fl1_fx * pa_z[j] + 1.5 * pc_yzz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_xzz[j] * pb_y[j] + pa_yy[j] * pc_xyzz[j] + 2.0 * pa_yz[j] * pc_xyyz[j] + 2.0 * pa_y[j] * pc_yyzz[j] * pb_x[j] + 2.0 * pa_y[j] * pc_xyzz[j] * pb_y[j] + 2.0 * pa_y[j] * pc_xyyz[j] * pb_z[j] + pc_yyyz[j] * pa_z[j] * pb_x[j] + pc_xyyz[j] * pa_z[j] * pb_y[j] + pc_xyyy[j] * pa_z[j] * pb_z[j] + pc_yyzz[j] * pb_xy[j] + pc_yyyz[j] * pb_xz[j] + pc_xyyz[j] * pb_yz[j]);

                t_yyz_xyz[j] += fl_s_0_0_5 * (-0.5 * pc_xyyy[j] * fl1_fx - 1.5 * pc_xyzz[j] * fl1_fx - 2.0 * pa_y[j] * pc_xyyzz[j] - pc_xyyyz[j] * pa_z[j] - pc_yyyzz[j] * pb_x[j] - pc_xyyzz[j] * pb_y[j] - pc_xyyyz[j] * pb_z[j]);

                t_yyz_xyz[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_yyz_xzz[j] = fl_s_0_0_0 * (0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_yyz[j] * pb_x[j] * fl1_fx + pa_yy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xzz[j] + pa_yyz[j] * pb_xzz[j]);

                t_yyz_xzz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_z[j] * pb_x[j] - 0.25 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * fl2_fx * pc_x[j] * pb_z[j] - fl2_fx * pb_xz[j] - 0.5 * pa_yyz[j] * pb_x[j] * fl1_fx - 0.5 * pa_yyz[j] * pc_x[j] * fl1_fx - 1.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx - pa_yy[j] * fl1_fx * pc_x[j] * pb_z[j] - pa_yy[j] * fl1_fx * pb_xz[j] - pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx - 2.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_xz[j] - fl1_fx * pa_z[j] * pb_xz[j] * pc_z[j] - 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_zz[j] - 0.5 * fl1_fx * pc_z[j] * pb_xzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_xzz[j] - 2.0 * pa_yyz[j] * pb_xz[j] * pc_z[j] - pa_yyz[j] * pc_x[j] * pb_zz[j] - pa_yy[j] * pc_z[j] * pb_xzz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_xzz[j]);

                t_yyz_xzz[j] += fl_s_0_0_2 * (0.5 * fl2_fx * pa_z[j] * pc_x[j] + 1.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.75 * fl2_fx * pc_xz[j] + fl2_fx * pc_x[j] * pb_z[j] + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_yyz[j] * pc_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_yy[j] * pc_xz[j] * fl1_fx + pa_yy[j] * fl1_fx * pc_x[j] * pb_z[j] + pa_yz[j] * pc_y[j] * pb_x[j] * fl1_fx + pa_yz[j] * pc_xy[j] * fl1_fx + 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx + 2.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_z[j] + 2.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_xz[j] + 0.5 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx + pc_yy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_zz[j] + fl1_fx * pa_z[j] * pc_xz[j] * pb_z[j] + fl1_fx * pc_zz[j] * pb_xz[j] + 0.5 * fl1_fx * pc_xz[j] * pb_zz[j] + fl1_fx * pa_z[j] * pb_xz[j] * pc_z[j] + 0.5 * fl1_fx * pa_z[j] * pc_x[j] * pb_zz[j] + 0.5 * fl1_fx * pc_z[j] * pb_xzz[j] + pa_yyz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_yyz[j] * pc_xz[j] * pb_z[j] + 2.0 * pa_yy[j] * pc_zz[j] * pb_xz[j] + pa_yy[j] * pc_xz[j] * pb_zz[j] + 4.0 * pa_yz[j] * pc_yz[j] * pb_xz[j] + 2.0 * pa_yz[j] * pc_xy[j] * pb_zz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_xzz[j] + pc_yy[j] * pa_z[j] * pb_xzz[j]);

                t_yyz_xzz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xz[j] - 0.25 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 0.5 * fl2_fx * pc_x[j] * pb_z[j] - 1.5 * pa_yy[j] * pc_xz[j] * fl1_fx - pa_yz[j] * pc_xy[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * pb_x[j] * fl1_fx - 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx - 2.0 * pa_y[j] * pc_xy[j] * fl1_fx * pb_z[j] - 0.5 * pc_yy[j] * pa_z[j] * pb_x[j] * fl1_fx - 0.5 * pc_xyy[j] * pa_z[j] * fl1_fx - 1.5 * pc_yyz[j] * pb_x[j] * fl1_fx - pc_xyy[j] * fl1_fx * pb_z[j] - pc_yy[j] * fl1_fx * pb_xz[j] - 0.5 * fl1_fx * pa_z[j] * pc_xzz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] - fl1_fx * pc_xzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_z[j] * pb_x[j] * pc_zz[j] - fl1_fx * pa_z[j] * pc_xz[j] * pb_z[j] - fl1_fx * pc_zz[j] * pb_xz[j] - 0.5 * fl1_fx * pc_xz[j] * pb_zz[j] - pa_yyz[j] * pc_xzz[j] - pa_yy[j] * pc_zzz[j] * pb_x[j] - 2.0 * pa_yy[j] * pc_xzz[j] * pb_z[j] - 2.0 * pa_yz[j] * pc_yzz[j] * pb_x[j] - 4.0 * pa_yz[j] * pc_xyz[j] * pb_z[j] - 4.0 * pa_y[j] * pc_yzz[j] * pb_xz[j] - 2.0 * pa_y[j] * pc_xyz[j] * pb_zz[j] - 2.0 * pc_yyz[j] * pa_z[j] * pb_xz[j] - pc_xyy[j] * pa_z[j] * pb_zz[j] - pc_yyz[j] * pb_xzz[j]);

                t_yyz_xzz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xz[j] + 3.0 * pa_y[j] * pc_xyz[j] * fl1_fx + 0.5 * pc_xyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_yyz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + pc_xyy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_xzzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_xzz[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] + fl1_fx * pc_xzz[j] * pb_z[j] + pa_yy[j] * pc_xzzz[j] + 2.0 * pa_yz[j] * pc_xyzz[j] + 2.0 * pa_y[j] * pc_yzzz[j] * pb_x[j] + 4.0 * pa_y[j] * pc_xyzz[j] * pb_z[j] + pc_yyzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_yyzz[j] * pb_xz[j] + pc_xyyz[j] * pb_zz[j]);

                t_yyz_xzz[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * fl1_fx * pc_xzzz[j] - 2.0 * pa_y[j] * pc_xyzzz[j] - pc_xyyzz[j] * pa_z[j] - pc_yyzzz[j] * pb_x[j] - 2.0 * pc_xyyzz[j] * pb_z[j]);

                t_yyz_xzz[j] += fl_s_0_0_6 * pc_xyyzzz[j];

                t_yyz_yyy[j] = fl_s_0_0_0 * (1.5 * pa_yz[j] * fl2_fx + 2.25 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_yyz[j] * pb_y[j] * fl1_fx + 3.0 * pa_yz[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pb_yyy[j] + pa_yyz[j] * pb_yyy[j]);

                t_yyz_yyy[j] += fl_s_0_0_1 * (-3.0 * pa_yz[j] * fl2_fx - 1.5 * pa_y[j] * fl2_fx * pc_z[j] - 3.75 * pc_y[j] * fl2_fx * pa_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_y[j] - 4.5 * fl2_fx * pa_z[j] * pb_y[j] - 1.5 * pa_yyz[j] * pb_y[j] * fl1_fx - 1.5 * pa_yyz[j] * pc_y[j] * fl1_fx - 1.5 * pa_yy[j] * pc_z[j] * pb_y[j] * fl1_fx - 9.0 * pa_yz[j] * pc_y[j] * pb_y[j] * fl1_fx - 3.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_yy[j] - 3.0 * pa_yz[j] * fl1_fx * pb_yy[j] - 4.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_yy[j] - 0.5 * fl1_fx * pc_z[j] * pb_yyy[j] - 0.5 * fl1_fx * pa_z[j] * pb_yyy[j] - 3.0 * pa_yyz[j] * pb_yy[j] * pc_y[j] - pa_yy[j] * pc_z[j] * pb_yyy[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_yyy[j]);

                t_yyz_yyy[j] += fl_s_0_0_2 * (3.0 * pa_y[j] * fl2_fx * pc_z[j] + 1.5 * pa_yz[j] * fl2_fx + 7.5 * pc_y[j] * fl2_fx * pa_z[j] + 3.75 * pc_yz[j] * fl2_fx + 4.5 * fl2_fx * pc_z[j] * pb_y[j] + 2.25 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_yyz[j] * pc_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx + 9.0 * pa_yz[j] * pc_y[j] * pb_y[j] * fl1_fx + 6.0 * pa_yz[j] * pc_yy[j] * fl1_fx + 9.0 * pa_y[j] * pc_yz[j] * pb_y[j] * fl1_fx + 3.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_yy[j] + 9.0 * pc_yy[j] * pa_z[j] * pb_y[j] * fl1_fx + 4.5 * pc_yz[j] * fl1_fx * pb_yy[j] + 4.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_yy[j] + 0.5 * fl1_fx * pc_z[j] * pb_yyy[j] + 3.0 * pa_yyz[j] * pb_y[j] * pc_yy[j] + 3.0 * pa_yy[j] * pc_yz[j] * pb_yy[j] + 6.0 * pa_yz[j] * pc_yy[j] * pb_yy[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_yyy[j] + pc_yy[j] * pa_z[j] * pb_yyy[j]);

                t_yyz_yyy[j] += fl_s_0_0_3 * (-1.5 * pa_y[j] * fl2_fx * pc_z[j] - 7.5 * pc_yz[j] * fl2_fx - 3.75 * pc_y[j] * fl2_fx * pa_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_y[j] - 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx - 6.0 * pa_yz[j] * pc_yy[j] * fl1_fx - 9.0 * pa_y[j] * pc_yz[j] * pb_y[j] * fl1_fx - 6.0 * pa_y[j] * pc_yyz[j] * fl1_fx - 9.0 * pc_yy[j] * pa_z[j] * pb_y[j] * fl1_fx - 5.0 * pc_yyy[j] * pa_z[j] * fl1_fx - 9.0 * pc_yyz[j] * pb_y[j] * fl1_fx - 4.5 * pc_yz[j] * fl1_fx * pb_yy[j] - pa_yyz[j] * pc_yyy[j] - 3.0 * pa_yy[j] * pc_yyz[j] * pb_y[j] - 6.0 * pa_yz[j] * pc_yyy[j] * pb_y[j] - 6.0 * pa_y[j] * pc_yyz[j] * pb_yy[j] - 3.0 * pc_yyy[j] * pa_z[j] * pb_yy[j] - pc_yyz[j] * pb_yyy[j]);

                t_yyz_yyy[j] += fl_s_0_0_4 * (3.75 * pc_yz[j] * fl2_fx + 6.0 * pa_y[j] * pc_yyz[j] * fl1_fx + 5.0 * pc_yyy[j] * pa_z[j] * fl1_fx + 9.0 * pc_yyz[j] * pb_y[j] * fl1_fx + 5.0 * pc_yyyz[j] * fl1_fx + pa_yy[j] * pc_yyyz[j] + 2.0 * pa_yz[j] * pc_yyyy[j] + 6.0 * pa_y[j] * pc_yyyz[j] * pb_y[j] + 3.0 * pc_yyyy[j] * pa_z[j] * pb_y[j] + 3.0 * pc_yyyz[j] * pb_yy[j]);

                t_yyz_yyy[j] += fl_s_0_0_5 * (-5.0 * pc_yyyz[j] * fl1_fx - 2.0 * pa_y[j] * pc_yyyyz[j] - pc_yyyyy[j] * pa_z[j] - 3.0 * pc_yyyyz[j] * pb_y[j]);

                t_yyz_yyy[j] += fl_s_0_0_6 * pc_yyyyyz[j];

                t_yyz_yyz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_yyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pb_yy[j] + 2.0 * pa_yz[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_yyz[j] + pa_yyz[j] * pb_yyz[j]);

                t_yyz_yyz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.5 * pa_yy[j] * fl2_fx - 1.5 * pa_y[j] * pc_y[j] * fl2_fx - 2.0 * pa_y[j] * fl2_fx * pb_y[j] - 1.5 * pc_y[j] * fl2_fx * pb_y[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_z[j] - 1.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_yy[j] - 0.5 * pa_yyz[j] * fl1_fx * pc_z[j] - 0.5 * pa_yyz[j] * fl1_fx * pb_z[j] - 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_z[j] - pa_yy[j] * fl1_fx * pb_y[j] * pc_y[j] - 0.5 * pa_yy[j] * fl1_fx * pb_yy[j] - 3.0 * pa_yz[j] * pc_y[j] * fl1_fx * pb_z[j] - pa_y[j] * pc_y[j] * fl1_fx * pb_yy[j] - 2.0 * pa_yz[j] * fl1_fx * pb_y[j] * pc_z[j] - 2.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_yz[j] - 2.0 * pa_yz[j] * fl1_fx * pb_yz[j] - 3.0 * pc_y[j] * fl1_fx * pa_z[j] * pb_yz[j] - 0.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_yyz[j] - 0.5 * fl1_fx * pa_z[j] * pb_yyz[j] - pa_yyz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_yyz[j] * pb_yz[j] * pc_y[j] - pa_yy[j] * pc_z[j] * pb_yyz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_yyz[j]);

                t_yyz_yyz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + 3.0 * pa_y[j] * pc_y[j] * fl2_fx + pa_y[j] * fl2_fx * pb_y[j] + 1.5 * pc_yy[j] * fl2_fx + 3.0 * pc_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pc_zz[j] + 1.5 * fl2_fx * pa_z[j] * pc_z[j] + 1.5 * fl2_fx * pc_z[j] * pb_z[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_yyz[j] * fl1_fx * pc_z[j] + 0.5 * pa_yy[j] * pc_zz[j] * fl1_fx + 0.5 * pa_yy[j] * pc_z[j] * fl1_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pc_yy[j] + pa_yy[j] * fl1_fx * pb_y[j] * pc_y[j] + 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx + 3.0 * pa_yz[j] * pc_y[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] + 2.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_y[j] + pa_y[j] * pc_y[j] * fl1_fx * pb_yy[j] + 2.0 * pa_y[j] * fl1_fx * pc_zz[j] * pb_y[j] + 2.0 * pa_yz[j] * fl1_fx * pb_y[j] * pc_z[j] + 2.0 * pa_y[j] * fl1_fx * pc_z[j] * pb_yz[j] + 3.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * pc_yy[j] * fl1_fx * pb_yy[j] + 3.0 * pc_yz[j] * fl1_fx * pa_z[j] * pb_y[j] + 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] + 3.0 * pc_y[j] * fl1_fx * pa_z[j] * pb_yz[j] + 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] + 0.5 * fl1_fx * pa_z[j] * pb_yy[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_yyz[j] + 2.0 * pa_yyz[j] * pb_y[j] * pc_yz[j] + pa_yyz[j] * pc_yy[j] * pb_z[j] + pa_yy[j] * pc_zz[j] * pb_yy[j] + 2.0 * pa_yy[j] * pc_yz[j] * pb_yz[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_yy[j] + 4.0 * pa_yz[j] * pc_yy[j] * pb_yz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_yyz[j] + pc_yy[j] * pa_z[j] * pb_yyz[j]);

                t_yyz_yyz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_y[j] * pc_y[j] * fl2_fx - 3.0 * pc_yy[j] * fl2_fx - 1.5 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pc_zz[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * pa_yy[j] * pc_zz[j] * fl1_fx - 0.5 * pa_yy[j] * fl1_fx * pc_yy[j] - 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] - pa_y[j] * pc_yyy[j] * fl1_fx - 2.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_y[j] - 2.0 * pa_y[j] * fl1_fx * pc_zz[j] * pb_y[j] - 3.0 * pc_yyz[j] * pa_z[j] * fl1_fx - 3.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_yyz[j] * fl1_fx * pb_z[j] - pc_yyy[j] * fl1_fx * pb_y[j] - 0.5 * pc_yy[j] * fl1_fx * pb_yy[j] - 3.0 * pc_yzz[j] * fl1_fx * pb_y[j] - 3.0 * pc_yz[j] * fl1_fx * pa_z[j] * pb_y[j] - 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] - 0.5 * fl1_fx * pc_zz[j] * pb_yy[j] - pa_yyz[j] * pc_yyz[j] - 2.0 * pa_yy[j] * pc_yzz[j] * pb_y[j] - pa_yy[j] * pc_yyz[j] * pb_z[j] - 4.0 * pa_yz[j] * pc_yyz[j] * pb_y[j] - 2.0 * pa_yz[j] * pc_yyy[j] * pb_z[j] - 2.0 * pa_y[j] * pc_yzz[j] * pb_yy[j] - 4.0 * pa_y[j] * pc_yyz[j] * pb_yz[j] - pc_yyz[j] * pa_z[j] * pb_yy[j] - 2.0 * pc_yyy[j] * pa_z[j] * pb_yz[j] - pc_yyz[j] * pb_yyz[j]);

                t_yyz_yyz[j] += fl_s_0_0_4 * (1.5 * pc_yy[j] * fl2_fx + 0.75 * fl2_fx * pc_zz[j] + 3.0 * pa_y[j] * pc_yzz[j] * fl1_fx + pa_y[j] * pc_yyy[j] * fl1_fx + 3.0 * pc_yyz[j] * pa_z[j] * fl1_fx + 3.0 * pc_yyzz[j] * fl1_fx + 3.0 * pc_yyz[j] * fl1_fx * pb_z[j] + 0.5 * pc_yyyy[j] * fl1_fx + pc_yyy[j] * fl1_fx * pb_y[j] + 3.0 * pc_yzz[j] * fl1_fx * pb_y[j] + pa_yy[j] * pc_yyzz[j] + 2.0 * pa_yz[j] * pc_yyyz[j] + 4.0 * pa_y[j] * pc_yyzz[j] * pb_y[j] + 2.0 * pa_y[j] * pc_yyyz[j] * pb_z[j] + 2.0 * pc_yyyz[j] * pa_z[j] * pb_y[j] + pc_yyyy[j] * pa_z[j] * pb_z[j] + pc_yyzz[j] * pb_yy[j] + 2.0 * pc_yyyz[j] * pb_yz[j]);

                t_yyz_yyz[j] += fl_s_0_0_5 * (-3.0 * pc_yyzz[j] * fl1_fx - 0.5 * pc_yyyy[j] * fl1_fx - 2.0 * pa_y[j] * pc_yyyzz[j] - pc_yyyyz[j] * pa_z[j] - 2.0 * pc_yyyzz[j] * pb_y[j] - pc_yyyyz[j] * pb_z[j]);

                t_yyz_yyz[j] += fl_s_0_0_6 * pc_yyyyzz[j];

                t_yyz_yzz[j] = fl_s_0_0_0 * (0.5 * pa_yz[j] * fl2_fx + pa_y[j] * fl2_fx * pb_z[j] + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yyz[j] * pb_y[j] * fl1_fx + pa_yy[j] * fl1_fx * pb_yz[j] + pa_yz[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_yzz[j] + pa_yyz[j] * pb_yzz[j]);

                t_yyz_yzz[j] += fl_s_0_0_1 * (-pa_yz[j] * fl2_fx - 1.5 * pa_y[j] * fl2_fx * pc_z[j] - 2.0 * pa_y[j] * fl2_fx * pb_z[j] - 0.75 * pc_y[j] * fl2_fx * pa_z[j] - 1.5 * pc_y[j] * fl2_fx * pb_z[j] - 0.5 * fl2_fx * pa_z[j] * pb_y[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - fl2_fx * pb_yz[j] - 0.5 * pa_yyz[j] * pb_y[j] * fl1_fx - 0.5 * pa_yyz[j] * pc_y[j] * fl1_fx - 1.5 * pa_yy[j] * pc_z[j] * pb_y[j] * fl1_fx - pa_yy[j] * fl1_fx * pc_y[j] * pb_z[j] - pa_yy[j] * fl1_fx * pb_yz[j] - pa_yz[j] * pc_y[j] * pb_y[j] * fl1_fx - 2.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_yz[j] - 2.0 * pa_yz[j] * fl1_fx * pb_z[j] * pc_z[j] - pa_y[j] * fl1_fx * pc_z[j] * pb_zz[j] - pa_yz[j] * fl1_fx * pb_zz[j] - 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_zz[j] - fl1_fx * pa_z[j] * pb_yz[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_yzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_yzz[j] - 2.0 * pa_yyz[j] * pb_yz[j] * pc_z[j] - pa_yyz[j] * pc_y[j] * pb_zz[j] - pa_yy[j] * pc_z[j] * pb_yzz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_yzz[j]);

                t_yyz_yzz[j] += fl_s_0_0_2 * (3.0 * pa_y[j] * fl2_fx * pc_z[j] + 0.5 * pa_yz[j] * fl2_fx + pa_y[j] * fl2_fx * pb_z[j] + 1.5 * pc_y[j] * fl2_fx * pa_z[j] + 2.25 * pc_yz[j] * fl2_fx + 3.0 * pc_y[j] * fl2_fx * pb_z[j] + 1.5 * fl2_fx * pc_z[j] * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yyz[j] * pc_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_z[j] * pb_y[j] * fl1_fx + 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx + pa_yy[j] * fl1_fx * pc_y[j] * pb_z[j] + pa_yz[j] * pc_y[j] * pb_y[j] * fl1_fx + pa_yz[j] * pc_yy[j] * fl1_fx + 3.0 * pa_y[j] * pc_yz[j] * pb_y[j] * fl1_fx + 2.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] + 2.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_yz[j] + pa_yz[j] * fl1_fx * pc_zz[j] + 2.0 * pa_y[j] * fl1_fx * pc_zz[j] * pb_z[j] + 2.0 * pa_yz[j] * fl1_fx * pb_z[j] * pc_z[j] + pa_y[j] * fl1_fx * pc_z[j] * pb_zz[j] + 0.5 * pc_yy[j] * pa_z[j] * pb_y[j] * fl1_fx + pc_yy[j] * fl1_fx * pb_yz[j] + 3.0 * pc_yz[j] * fl1_fx * pa_z[j] * pb_z[j] + 1.5 * pc_yz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_y[j] * fl1_fx * pa_z[j] * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_zz[j] + fl1_fx * pc_zz[j] * pb_yz[j] + fl1_fx * pa_z[j] * pb_yz[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_yzz[j] + pa_yyz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_yyz[j] * pc_yz[j] * pb_z[j] + 2.0 * pa_yy[j] * pc_zz[j] * pb_yz[j] + pa_yy[j] * pc_yz[j] * pb_zz[j] + 4.0 * pa_yz[j] * pc_yz[j] * pb_yz[j] + 2.0 * pa_yz[j] * pc_yy[j] * pb_zz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_yzz[j] + pc_yy[j] * pa_z[j] * pb_yzz[j]);

                t_yyz_yzz[j] += fl_s_0_0_3 * (-1.5 * pa_y[j] * fl2_fx * pc_z[j] - 4.5 * pc_yz[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pa_z[j] - 1.5 * pc_y[j] * fl2_fx * pb_z[j] - 0.75 * fl2_fx * pc_z[j] * pb_y[j] - 1.5 * pa_yy[j] * pc_yz[j] * fl1_fx - pa_yz[j] * pc_yy[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * pb_y[j] * fl1_fx - 3.0 * pa_y[j] * pc_yyz[j] * fl1_fx - 2.0 * pa_y[j] * pc_yy[j] * fl1_fx * pb_z[j] - pa_y[j] * fl1_fx * pc_zzz[j] - pa_yz[j] * fl1_fx * pc_zz[j] - 2.0 * pa_y[j] * fl1_fx * pc_zz[j] * pb_z[j] - 0.5 * pc_yy[j] * pa_z[j] * pb_y[j] * fl1_fx - 0.5 * pc_yyy[j] * pa_z[j] * fl1_fx - 1.5 * pc_yyz[j] * pb_y[j] * fl1_fx - pc_yyy[j] * fl1_fx * pb_z[j] - pc_yy[j] * fl1_fx * pb_yz[j] - 1.5 * pc_yzz[j] * fl1_fx * pa_z[j] - 3.0 * pc_yzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yz[j] * fl1_fx * pa_z[j] * pb_z[j] - 1.5 * pc_yz[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] - 0.5 * fl1_fx * pa_z[j] * pb_y[j] * pc_zz[j] - fl1_fx * pc_zz[j] * pb_yz[j] - pa_yyz[j] * pc_yzz[j] - pa_yy[j] * pc_zzz[j] * pb_y[j] - 2.0 * pa_yy[j] * pc_yzz[j] * pb_z[j] - 2.0 * pa_yz[j] * pc_yzz[j] * pb_y[j] - 4.0 * pa_yz[j] * pc_yyz[j] * pb_z[j] - 4.0 * pa_y[j] * pc_yzz[j] * pb_yz[j] - 2.0 * pa_y[j] * pc_yyz[j] * pb_zz[j] - 2.0 * pc_yyz[j] * pa_z[j] * pb_yz[j] - pc_yyy[j] * pa_z[j] * pb_zz[j] - pc_yyz[j] * pb_yzz[j]);

                t_yyz_yzz[j] += fl_s_0_0_4 * (2.25 * pc_yz[j] * fl2_fx + 3.0 * pa_y[j] * pc_yyz[j] * fl1_fx + pa_y[j] * fl1_fx * pc_zzz[j] + 0.5 * pc_yyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_yyz[j] * pb_y[j] * fl1_fx + 1.5 * pc_yyyz[j] * fl1_fx + pc_yyy[j] * fl1_fx * pb_z[j] + 1.5 * pc_yzzz[j] * fl1_fx + 1.5 * pc_yzz[j] * fl1_fx * pa_z[j] + 3.0 * pc_yzz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_y[j] + pa_yy[j] * pc_yzzz[j] + 2.0 * pa_yz[j] * pc_yyzz[j] + 2.0 * pa_y[j] * pc_yzzz[j] * pb_y[j] + 4.0 * pa_y[j] * pc_yyzz[j] * pb_z[j] + pc_yyzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_yyyz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_yyzz[j] * pb_yz[j] + pc_yyyz[j] * pb_zz[j]);

                t_yyz_yzz[j] += fl_s_0_0_5 * (-1.5 * pc_yyyz[j] * fl1_fx - 1.5 * pc_yzzz[j] * fl1_fx - 2.0 * pa_y[j] * pc_yyzzz[j] - pc_yyyzz[j] * pa_z[j] - pc_yyzzz[j] * pb_y[j] - 2.0 * pc_yyyzz[j] * pb_z[j]);

                t_yyz_yzz[j] += fl_s_0_0_6 * pc_yyyzzz[j];

                t_yyz_zzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_yyz[j] * pb_z[j] * fl1_fx + 1.5 * pa_yy[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] + pa_yyz[j] * pb_zzz[j]);

                t_yyz_zzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_yy[j] * fl2_fx - 1.5 * pa_y[j] * pc_y[j] * fl2_fx - 1.5 * fl2_fx * pa_z[j] * pb_z[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_z[j] - 1.5 * fl2_fx * pb_zz[j] - 1.5 * pa_yyz[j] * pb_z[j] * fl1_fx - 1.5 * pa_yyz[j] * pc_z[j] * fl1_fx - 4.5 * pa_yy[j] * pc_z[j] * pb_z[j] * fl1_fx - 1.5 * pa_yy[j] * fl1_fx * pb_zz[j] - 3.0 * pa_yz[j] * pc_y[j] * pb_z[j] * fl1_fx - 3.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_zz[j] - 1.5 * fl1_fx * pa_z[j] * pb_zz[j] * pc_z[j] - 0.5 * fl1_fx * pc_z[j] * pb_zzz[j] - 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] - 3.0 * pa_yyz[j] * pb_zz[j] * pc_z[j] - pa_yy[j] * pc_z[j] * pb_zzz[j] - 2.0 * pa_yz[j] * pc_y[j] * pb_zzz[j]);

                t_yyz_zzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 3.0 * pa_y[j] * pc_y[j] * fl2_fx + 0.75 * pc_yy[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pc_z[j] + 4.5 * fl2_fx * pc_z[j] * pb_z[j] + 1.5 * fl2_fx * pc_zz[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_yyz[j] * pc_z[j] * fl1_fx + 4.5 * pa_yy[j] * pc_z[j] * pb_z[j] * fl1_fx + 3.0 * pa_yy[j] * pc_zz[j] * fl1_fx + 3.0 * pa_yz[j] * pc_y[j] * pb_z[j] * fl1_fx + 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx + 9.0 * pa_y[j] * pc_yz[j] * pb_z[j] * fl1_fx + 3.0 * pa_y[j] * pc_y[j] * fl1_fx * pb_zz[j] + 1.5 * pc_yy[j] * pa_z[j] * pb_z[j] * fl1_fx + 1.5 * pc_yy[j] * fl1_fx * pb_zz[j] + 1.5 * fl1_fx * pa_z[j] * pb_z[j] * pc_zz[j] + 1.5 * fl1_fx * pc_zz[j] * pb_zz[j] + 1.5 * fl1_fx * pa_z[j] * pb_zz[j] * pc_z[j] + 0.5 * fl1_fx * pc_z[j] * pb_zzz[j] + 3.0 * pa_yyz[j] * pb_z[j] * pc_zz[j] + 3.0 * pa_yy[j] * pc_zz[j] * pb_zz[j] + 6.0 * pa_yz[j] * pc_yz[j] * pb_zz[j] + 2.0 * pa_y[j] * pc_yz[j] * pb_zzz[j] + pc_yy[j] * pa_z[j] * pb_zzz[j]);

                t_yyz_zzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * pa_y[j] * pc_y[j] * fl2_fx - 1.5 * pc_yy[j] * fl2_fx - 3.0 * fl2_fx * pc_zz[j] - 0.75 * fl2_fx * pa_z[j] * pc_z[j] - 2.25 * fl2_fx * pc_z[j] * pb_z[j] - 3.0 * pa_yy[j] * pc_zz[j] * fl1_fx - 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx - 9.0 * pa_y[j] * pc_yz[j] * pb_z[j] * fl1_fx - 6.0 * pa_y[j] * pc_yzz[j] * fl1_fx - 1.5 * pc_yy[j] * pa_z[j] * pb_z[j] * fl1_fx - 1.5 * pc_yyz[j] * pa_z[j] * fl1_fx - 4.5 * pc_yyz[j] * pb_z[j] * fl1_fx - 1.5 * pc_yy[j] * fl1_fx * pb_zz[j] - 0.5 * fl1_fx * pa_z[j] * pc_zzz[j] - 1.5 * fl1_fx * pc_zzz[j] * pb_z[j] - 1.5 * fl1_fx * pa_z[j] * pb_z[j] * pc_zz[j] - 1.5 * fl1_fx * pc_zz[j] * pb_zz[j] - pa_yyz[j] * pc_zzz[j] - 3.0 * pa_yy[j] * pc_zzz[j] * pb_z[j] - 6.0 * pa_yz[j] * pc_yzz[j] * pb_z[j] - 6.0 * pa_y[j] * pc_yzz[j] * pb_zz[j] - 3.0 * pc_yyz[j] * pa_z[j] * pb_zz[j] - pc_yyz[j] * pb_zzz[j]);

                t_yyz_zzz[j] += fl_s_0_0_4 * (0.75 * pc_yy[j] * fl2_fx + 1.5 * fl2_fx * pc_zz[j] + 6.0 * pa_y[j] * pc_yzz[j] * fl1_fx + 1.5 * pc_yyz[j] * pa_z[j] * fl1_fx + 4.5 * pc_yyz[j] * pb_z[j] * fl1_fx + 3.0 * pc_yyzz[j] * fl1_fx + 0.5 * fl1_fx * pc_zzzz[j] + 0.5 * fl1_fx * pa_z[j] * pc_zzz[j] + 1.5 * fl1_fx * pc_zzz[j] * pb_z[j] + pa_yy[j] * pc_zzzz[j] + 2.0 * pa_yz[j] * pc_yzzz[j] + 6.0 * pa_y[j] * pc_yzzz[j] * pb_z[j] + 3.0 * pc_yyzz[j] * pa_z[j] * pb_z[j] + 3.0 * pc_yyzz[j] * pb_zz[j]);

                t_yyz_zzz[j] += fl_s_0_0_5 * (-3.0 * pc_yyzz[j] * fl1_fx - 0.5 * fl1_fx * pc_zzzz[j] - 2.0 * pa_y[j] * pc_yzzzz[j] - pc_yyzzz[j] * pa_z[j] - 3.0 * pc_yyzzz[j] * pb_z[j]);

                t_yyz_zzz[j] += fl_s_0_0_6 * pc_yyzzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_80_90(      CMemBlock2D<double>& primBuffer,
                                    const CMemBlock2D<double>& auxBuffer,
                                    const CMemBlock2D<double>& osFactors,
                                    const CMemBlock2D<double>& paDistances,
                                    const CMemBlock2D<double>& pbDistances,
                                    const CMemBlock2D<double>& pcDistances,
                                    const CGtoBlock&           braGtoBlock,
                                    const CGtoBlock&           ketGtoBlock,
                                    const int32_t              iContrGto)
    {
        // Batch of Integrals (80,90)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(19 * idx + 7);

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yzz = paDistances.data(19 * idx + 17);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxy = pcDistances.data(83 * idx + 20);

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyy = pcDistances.data(83 * idx + 22);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyy = pcDistances.data(83 * idx + 25);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyy = pcDistances.data(83 * idx + 29);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxyz = pcDistances.data(83 * idx + 38);

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyyz = pcDistances.data(83 * idx + 41);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyyz = pcDistances.data(83 * idx + 45);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_xzzzz = pcDistances.data(83 * idx + 48);

            auto pc_yyyyz = pcDistances.data(83 * idx + 50);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            auto pc_yzzzz = pcDistances.data(83 * idx + 53);

            auto pc_zzzzz = pcDistances.data(83 * idx + 54);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxyzz = pcDistances.data(83 * idx + 63);

            auto pc_xxyyzz = pcDistances.data(83 * idx + 67);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            auto pc_xyyyzz = pcDistances.data(83 * idx + 72);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            auto pc_xyzzzz = pcDistances.data(83 * idx + 74);

            auto pc_yyyyzz = pcDistances.data(83 * idx + 78);

            auto pc_yyyzzz = pcDistances.data(83 * idx + 79);

            auto pc_yyzzzz = pcDistances.data(83 * idx + 80);

            auto pc_yzzzzz = pcDistances.data(83 * idx + 81);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_yzz_xxx = primBuffer.data(100 * idx + 80);

            auto t_yzz_xxy = primBuffer.data(100 * idx + 81);

            auto t_yzz_xxz = primBuffer.data(100 * idx + 82);

            auto t_yzz_xyy = primBuffer.data(100 * idx + 83);

            auto t_yzz_xyz = primBuffer.data(100 * idx + 84);

            auto t_yzz_xzz = primBuffer.data(100 * idx + 85);

            auto t_yzz_yyy = primBuffer.data(100 * idx + 86);

            auto t_yzz_yyz = primBuffer.data(100 * idx + 87);

            auto t_yzz_yzz = primBuffer.data(100 * idx + 88);

            auto t_yzz_zzz = primBuffer.data(100 * idx + 89);

            // Batch of Integrals (80,90)

            #pragma omp simd aligned(fx, pa_y, pa_yz, pa_yzz, pa_z, pa_zz, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, pc_x, pc_xx, pc_xxx, pc_xxxy, pc_xxxyz, pc_xxxyzz, pc_xxxz, pc_xxxzz, pc_xxy, \
                                     pc_xxyy, pc_xxyyz, pc_xxyyzz, pc_xxyz, pc_xxyzz, pc_xxyzzz, pc_xxz, pc_xxzz, \
                                     pc_xxzzz, pc_xy, pc_xyy, pc_xyyy, pc_xyyyz, pc_xyyyzz, pc_xyyz, pc_xyyzz, pc_xyyzzz, \
                                     pc_xyz, pc_xyzz, pc_xyzzz, pc_xyzzzz, pc_xz, pc_xzz, pc_xzzz, pc_xzzzz, pc_y, pc_yy, \
                                     pc_yyy, pc_yyyy, pc_yyyyz, pc_yyyyzz, pc_yyyz, pc_yyyzz, pc_yyyzzz, pc_yyz, \
                                     pc_yyzz, pc_yyzzz, pc_yyzzzz, pc_yz, pc_yzz, pc_yzzz, pc_yzzzz, pc_yzzzzz, pc_z, \
                                     pc_zz, pc_zzz, pc_zzzz, pc_zzzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, \
                                     s_0_0_5, s_0_0_6, t_yzz_xxx, t_yzz_xxy, t_yzz_xxz, t_yzz_xyy, t_yzz_xyz, \
                                     t_yzz_xzz, t_yzz_yyy, t_yzz_yyz, t_yzz_yzz, t_yzz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yzz_xxx[j] = fl_s_0_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pa_yzz[j] * pb_x[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pb_xxx[j] + pa_yzz[j] * pb_xxx[j]);

                t_yzz_xxx[j] += fl_s_0_0_1 * (-1.5 * pa_y[j] * fl2_fx * pb_x[j] - 0.75 * pa_y[j] * fl2_fx * pc_x[j] - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 1.5 * pa_yzz[j] * pb_x[j] * fl1_fx - 1.5 * pa_yzz[j] * pc_x[j] * fl1_fx - 3.0 * pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx - 1.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx - 1.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_x[j] - 0.5 * pa_y[j] * fl1_fx * pb_xxx[j] - 0.5 * pc_y[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_yzz[j] * pb_xx[j] * pc_x[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xxx[j] - pc_y[j] * pa_zz[j] * pb_xxx[j]);

                t_yzz_xxx[j] += fl_s_0_0_2 * (1.5 * pa_y[j] * fl2_fx * pc_x[j] + 0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pc_y[j] * fl2_fx * pb_x[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_yzz[j] * pc_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_xz[j] * fl1_fx + 1.5 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx + 1.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_xx[j] + 1.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_x[j] + 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] + 0.5 * pc_y[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_yzz[j] * pb_x[j] * pc_xx[j] + 6.0 * pa_yz[j] * pc_xz[j] * pb_xx[j] + pa_y[j] * pc_zz[j] * pb_xxx[j] + 3.0 * pc_xy[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xxx[j]);

                t_yzz_xxx[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 3.0 * pa_yz[j] * pc_xz[j] * fl1_fx - 1.5 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx - 1.5 * pa_y[j] * pc_xzz[j] * fl1_fx - 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 1.5 * pc_yzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_y[j] * fl1_fx * pc_xxx[j] - 1.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_xx[j] - 1.5 * pc_xxy[j] * fl1_fx * pb_x[j] - 1.5 * pc_xy[j] * fl1_fx * pb_xx[j] - pa_yzz[j] * pc_xxx[j] - 6.0 * pa_yz[j] * pc_xxz[j] * pb_x[j] - 3.0 * pa_y[j] * pc_xzz[j] * pb_xx[j] - 3.0 * pc_xxy[j] * pa_zz[j] * pb_x[j] - 6.0 * pc_xyz[j] * pa_z[j] * pb_xx[j] - pc_yzz[j] * pb_xxx[j]);

                t_yzz_xxx[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 1.5 * pa_y[j] * pc_xzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_yzz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pc_xxx[j] + 0.5 * pc_xxxy[j] * fl1_fx + 1.5 * pc_xxy[j] * fl1_fx * pb_x[j] + 2.0 * pa_yz[j] * pc_xxxz[j] + 3.0 * pa_y[j] * pc_xxzz[j] * pb_x[j] + pc_xxxy[j] * pa_zz[j] + 6.0 * pc_xxyz[j] * pa_z[j] * pb_x[j] + 3.0 * pc_xyzz[j] * pb_xx[j]);

                t_yzz_xxx[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xxxy[j] * fl1_fx - pa_y[j] * pc_xxxzz[j] - 2.0 * pc_xxxyz[j] * pa_z[j] - 3.0 * pc_xxyzz[j] * pb_x[j]);

                t_yzz_xxx[j] += fl_s_0_0_6 * pc_xxxyzz[j];

                t_yzz_xxy[j] = fl_s_0_0_0 * (0.125 * fl3_fx + 0.25 * fl2_fx * pa_zz[j] + 0.25 * pa_y[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yzz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xx[j] + 0.5 * pa_y[j] * fl1_fx * pb_xxy[j] + pa_yzz[j] * pb_xxy[j]);

                t_yzz_xxy[j] += fl_s_0_0_1 * (-0.375 * fl3_fx - 0.5 * fl2_fx * pa_zz[j] - 0.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * pa_y[j] * fl2_fx * pc_y[j] - 0.5 * pa_y[j] * fl2_fx * pb_y[j] - 0.25 * pc_y[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pb_x[j] * pc_x[j] - 0.5 * fl2_fx * pb_xx[j] - 0.5 * pa_yzz[j] * fl1_fx * pc_y[j] - 0.5 * pa_yzz[j] * fl1_fx * pb_y[j] - pa_yz[j] * pc_z[j] * fl1_fx * pb_y[j] - 0.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_y[j] - fl1_fx * pa_zz[j] * pb_x[j] * pc_x[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_xx[j] - 0.5 * fl1_fx * pa_zz[j] * pb_xx[j] - 0.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_y[j] - pa_y[j] * fl1_fx * pb_xy[j] * pc_x[j] - 0.5 * pa_y[j] * fl1_fx * pb_xxy[j] - 0.5 * pc_y[j] * fl1_fx * pb_xxy[j] - pa_yzz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_yzz[j] * pb_xy[j] * pc_x[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xxy[j] - pc_y[j] * pa_zz[j] * pb_xxy[j]);

                t_yzz_xxy[j] += fl_s_0_0_2 * (0.375 * fl3_fx + fl2_fx * pa_z[j] * pc_z[j] + 0.25 * fl2_fx * pc_zz[j] + 0.25 * fl2_fx * pa_zz[j] + 0.5 * pa_y[j] * fl2_fx * pc_y[j] + 0.25 * pa_y[j] * fl2_fx * pb_y[j] + 0.25 * pc_yy[j] * fl2_fx + 0.5 * pc_y[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pc_xx[j] + fl2_fx * pb_x[j] * pc_x[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yzz[j] * fl1_fx * pc_y[j] + pa_yz[j] * pc_yz[j] * fl1_fx + pa_yz[j] * pc_z[j] * fl1_fx * pb_y[j] + 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_y[j] + 0.5 * pc_yy[j] * pa_zz[j] * fl1_fx + 0.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_y[j] + pc_yz[j] * pa_z[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_zz[j] * pc_xx[j] + 2.0 * fl1_fx * pa_z[j] * pc_xz[j] * pb_x[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] + fl1_fx * pa_zz[j] * pb_x[j] * pc_x[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_xx[j] + pa_y[j] * fl1_fx * pb_x[j] * pc_xy[j] + 0.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_y[j] + 0.5 * pa_y[j] * fl1_fx * pb_xx[j] * pc_y[j] + pa_y[j] * fl1_fx * pb_xy[j] * pc_x[j] + 0.5 * pc_yy[j] * fl1_fx * pb_xx[j] + pc_xy[j] * fl1_fx * pb_xy[j] + 0.5 * pc_y[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_yzz[j] * pb_x[j] * pc_xy[j] + pa_yzz[j] * pc_xx[j] * pb_y[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_xx[j] + 4.0 * pa_yz[j] * pc_xz[j] * pb_xy[j] + pa_y[j] * pc_zz[j] * pb_xxy[j] + pc_yy[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_xy[j] * pa_zz[j] * pb_xy[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xxy[j]);

                t_yzz_xxy[j] += fl_s_0_0_3 * (-0.125 * fl3_fx - 0.5 * fl2_fx * pc_zz[j] - 0.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.25 * pa_y[j] * fl2_fx * pc_y[j] - 0.5 * pc_yy[j] * fl2_fx - 0.25 * pc_y[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pc_xx[j] - 0.5 * fl2_fx * pb_x[j] * pc_x[j] - pa_yz[j] * pc_yz[j] * fl1_fx - 0.5 * pa_y[j] * pc_yzz[j] * fl1_fx - 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_y[j] - 0.5 * pc_yy[j] * pa_zz[j] * fl1_fx - pc_yyz[j] * pa_z[j] * fl1_fx - pc_yz[j] * pa_z[j] * fl1_fx * pb_y[j] - 0.5 * pc_yzz[j] * fl1_fx * pb_y[j] - fl1_fx * pa_z[j] * pc_xxz[j] - fl1_fx * pc_xzz[j] * pb_x[j] - 0.5 * fl1_fx * pa_zz[j] * pc_xx[j] - 2.0 * fl1_fx * pa_z[j] * pc_xz[j] * pb_x[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xx[j] - 0.5 * pa_y[j] * fl1_fx * pc_xxy[j] - pa_y[j] * fl1_fx * pb_x[j] * pc_xy[j] - 0.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_y[j] - pc_xyy[j] * fl1_fx * pb_x[j] - 0.5 * pc_xxy[j] * fl1_fx * pb_y[j] - 0.5 * pc_yy[j] * fl1_fx * pb_xx[j] - pc_xy[j] * fl1_fx * pb_xy[j] - pa_yzz[j] * pc_xxy[j] - 4.0 * pa_yz[j] * pc_xyz[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xxz[j] * pb_y[j] - pa_y[j] * pc_yzz[j] * pb_xx[j] - 2.0 * pa_y[j] * pc_xzz[j] * pb_xy[j] - 2.0 * pc_xyy[j] * pa_zz[j] * pb_x[j] - pc_xxy[j] * pa_zz[j] * pb_y[j] - 2.0 * pc_yyz[j] * pa_z[j] * pb_xx[j] - 4.0 * pc_xyz[j] * pa_z[j] * pb_xy[j] - pc_yzz[j] * pb_xxy[j]);

                t_yzz_xxy[j] += fl_s_0_0_4 * (0.25 * fl2_fx * pc_zz[j] + 0.25 * pc_yy[j] * fl2_fx + 0.25 * fl2_fx * pc_xx[j] + 0.5 * pa_y[j] * pc_yzz[j] * fl1_fx + pc_yyz[j] * pa_z[j] * fl1_fx + 0.5 * pc_yyzz[j] * fl1_fx + 0.5 * pc_yzz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_xxzz[j] + fl1_fx * pa_z[j] * pc_xxz[j] + fl1_fx * pc_xzz[j] * pb_x[j] + 0.5 * pa_y[j] * fl1_fx * pc_xxy[j] + 0.5 * pc_xxyy[j] * fl1_fx + pc_xyy[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxy[j] * fl1_fx * pb_y[j] + 2.0 * pa_yz[j] * pc_xxyz[j] + 2.0 * pa_y[j] * pc_xyzz[j] * pb_x[j] + pa_y[j] * pc_xxzz[j] * pb_y[j] + pc_xxyy[j] * pa_zz[j] + 4.0 * pc_xyyz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_y[j] + pc_yyzz[j] * pb_xx[j] + 2.0 * pc_xyzz[j] * pb_xy[j]);

                t_yzz_xxy[j] += fl_s_0_0_5 * (-0.5 * pc_yyzz[j] * fl1_fx - 0.5 * fl1_fx * pc_xxzz[j] - 0.5 * pc_xxyy[j] * fl1_fx - pa_y[j] * pc_xxyzz[j] - 2.0 * pc_xxyyz[j] * pa_z[j] - 2.0 * pc_xyyzz[j] * pb_x[j] - pc_xxyzz[j] * pb_y[j]);

                t_yzz_xxy[j] += fl_s_0_0_6 * pc_xxyyzz[j];

                t_yzz_xxz[j] = fl_s_0_0_0 * (0.5 * pa_yz[j] * fl2_fx + 0.25 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yzz[j] * fl1_fx * pb_z[j] + pa_yz[j] * fl1_fx * pb_xx[j] + 0.5 * pa_y[j] * fl1_fx * pb_xxz[j] + pa_yzz[j] * pb_xxz[j]);

                t_yzz_xxz[j] += fl_s_0_0_1 * (-pa_yz[j] * fl2_fx - 0.75 * pa_y[j] * pc_z[j] * fl2_fx - 0.5 * pc_y[j] * pa_z[j] * fl2_fx - 0.5 * pa_y[j] * fl2_fx * pb_z[j] - 0.25 * pc_y[j] * fl2_fx * pb_z[j] - 0.5 * pa_yzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_yzz[j] * fl1_fx * pb_z[j] - pa_yz[j] * pc_z[j] * fl1_fx * pb_z[j] - 2.0 * pa_yz[j] * fl1_fx * pb_x[j] * pc_x[j] - pa_yz[j] * fl1_fx * pb_xx[j] - 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_xx[j] - 0.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_z[j] - pc_y[j] * pa_z[j] * fl1_fx * pb_xx[j] - pa_y[j] * fl1_fx * pb_xz[j] * pc_x[j] - 0.5 * pa_y[j] * fl1_fx * pb_xxz[j] - 0.5 * pc_y[j] * fl1_fx * pb_xxz[j] - pa_yzz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_yzz[j] * pb_xz[j] * pc_x[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xxz[j] - pc_y[j] * pa_zz[j] * pb_xxz[j]);

                t_yzz_xxz[j] += fl_s_0_0_2 * (0.5 * pa_yz[j] * fl2_fx + 1.5 * pa_y[j] * pc_z[j] * fl2_fx + pc_y[j] * pa_z[j] * fl2_fx + 0.75 * pc_yz[j] * fl2_fx + 0.25 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pc_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yzz[j] * fl1_fx * pc_z[j] + pa_yz[j] * pc_zz[j] * fl1_fx + pa_yz[j] * pc_z[j] * fl1_fx * pb_z[j] + pa_yz[j] * fl1_fx * pc_xx[j] + 2.0 * pa_yz[j] * fl1_fx * pb_x[j] * pc_x[j] + 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * pc_xz[j] * fl1_fx * pb_x[j] + 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_xx[j] + 0.5 * pc_yz[j] * pa_zz[j] * fl1_fx + 0.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_z[j] + pc_yz[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_x[j] + pc_y[j] * pa_z[j] * fl1_fx * pb_xx[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] + 0.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_z[j] + pa_y[j] * fl1_fx * pb_xz[j] * pc_x[j] + pc_xy[j] * fl1_fx * pb_xz[j] + 0.5 * pc_y[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_yzz[j] * pb_x[j] * pc_xz[j] + pa_yzz[j] * pc_xx[j] * pb_z[j] + 2.0 * pa_yz[j] * pc_zz[j] * pb_xx[j] + 4.0 * pa_yz[j] * pc_xz[j] * pb_xz[j] + pa_y[j] * pc_zz[j] * pb_xxz[j] + pc_yz[j] * pa_zz[j] * pb_xx[j] + 2.0 * pc_xy[j] * pa_zz[j] * pb_xz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xxz[j]);

                t_yzz_xxz[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * pc_z[j] * fl2_fx - 0.5 * pc_y[j] * pa_z[j] * fl2_fx - 1.5 * pc_yz[j] * fl2_fx - 0.25 * pc_y[j] * fl2_fx * pb_z[j] - pa_yz[j] * pc_zz[j] * fl1_fx - pa_yz[j] * fl1_fx * pc_xx[j] - 0.5 * pa_y[j] * pc_zzz[j] * fl1_fx - 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_z[j] - 1.5 * pa_y[j] * pc_xxz[j] * fl1_fx - 3.0 * pa_y[j] * pc_xz[j] * fl1_fx * pb_x[j] - 0.5 * pc_yz[j] * pa_zz[j] * fl1_fx - pc_yzz[j] * pa_z[j] * fl1_fx - pc_yz[j] * pa_z[j] * fl1_fx * pb_z[j] - pc_xxy[j] * pa_z[j] * fl1_fx - 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_x[j] - 0.5 * pc_yzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] - 0.5 * pa_y[j] * fl1_fx * pc_xx[j] * pb_z[j] - 0.5 * pc_xxy[j] * fl1_fx * pb_z[j] - pc_xy[j] * fl1_fx * pb_xz[j] - pa_yzz[j] * pc_xxz[j] - 4.0 * pa_yz[j] * pc_xzz[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xxz[j] * pb_z[j] - pa_y[j] * pc_zzz[j] * pb_xx[j] - 2.0 * pa_y[j] * pc_xzz[j] * pb_xz[j] - 2.0 * pc_xyz[j] * pa_zz[j] * pb_x[j] - pc_xxy[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_yzz[j] * pa_z[j] * pb_xx[j] - 4.0 * pc_xyz[j] * pa_z[j] * pb_xz[j] - pc_yzz[j] * pb_xxz[j]);

                t_yzz_xxz[j] += fl_s_0_0_4 * (0.75 * pc_yz[j] * fl2_fx + 0.5 * pa_y[j] * pc_zzz[j] * fl1_fx + 1.5 * pa_y[j] * pc_xxz[j] * fl1_fx + pc_yzz[j] * pa_z[j] * fl1_fx + pc_xxy[j] * pa_z[j] * fl1_fx + 0.5 * pc_yzzz[j] * fl1_fx + 0.5 * pc_yzz[j] * fl1_fx * pb_z[j] + 1.5 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + 0.5 * pc_xxy[j] * fl1_fx * pb_z[j] + 2.0 * pa_yz[j] * pc_xxzz[j] + 2.0 * pa_y[j] * pc_xzzz[j] * pb_x[j] + pa_y[j] * pc_xxzz[j] * pb_z[j] + pc_xxyz[j] * pa_zz[j] + 4.0 * pc_xyzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xxyz[j] * pa_z[j] * pb_z[j] + pc_yzzz[j] * pb_xx[j] + 2.0 * pc_xyzz[j] * pb_xz[j]);

                t_yzz_xxz[j] += fl_s_0_0_5 * (-0.5 * pc_yzzz[j] * fl1_fx - 1.5 * pc_xxyz[j] * fl1_fx - pa_y[j] * pc_xxzzz[j] - 2.0 * pc_xxyzz[j] * pa_z[j] - 2.0 * pc_xyzzz[j] * pb_x[j] - pc_xxyzz[j] * pb_z[j]);

                t_yzz_xxz[j] += fl_s_0_0_6 * pc_xxyzzz[j];

                t_yzz_xyy[j] = fl_s_0_0_0 * (0.25 * pa_y[j] * fl2_fx * pb_x[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_yzz[j] * pb_x[j] * fl1_fx + fl1_fx * pa_zz[j] * pb_xy[j] + 0.5 * pa_y[j] * fl1_fx * pb_xyy[j] + pa_yzz[j] * pb_xyy[j]);

                t_yzz_xyy[j] += fl_s_0_0_1 * (-0.5 * pa_y[j] * fl2_fx * pb_x[j] - 0.25 * pa_y[j] * fl2_fx * pc_x[j] - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pc_x[j] * pb_y[j] - fl2_fx * pb_xy[j] - 0.5 * pa_yzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_yzz[j] * pc_x[j] * fl1_fx - pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx - 1.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx - fl1_fx * pa_zz[j] * pc_x[j] * pb_y[j] - 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xy[j] - fl1_fx * pa_zz[j] * pb_xy[j] - pa_y[j] * fl1_fx * pb_xy[j] * pc_y[j] - 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yy[j] - 0.5 * pa_y[j] * fl1_fx * pb_xyy[j] - 0.5 * pc_y[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_yzz[j] * pb_xy[j] * pc_y[j] - pa_yzz[j] * pc_x[j] * pb_yy[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xyy[j] - pc_y[j] * pa_zz[j] * pb_xyy[j]);

                t_yzz_xyy[j] += fl_s_0_0_2 * (0.5 * pa_y[j] * fl2_fx * pc_x[j] + 0.25 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pc_y[j] * fl2_fx * pb_x[j] + 0.75 * pc_xy[j] * fl2_fx + fl2_fx * pc_x[j] * pb_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_yzz[j] * pc_x[j] * fl1_fx + pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx + pa_yz[j] * pc_xz[j] * fl1_fx + 0.5 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx + 1.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx + 2.0 * fl1_fx * pa_z[j] * pc_xz[j] * pb_y[j] + fl1_fx * pc_zz[j] * pb_xy[j] + fl1_fx * pa_zz[j] * pc_x[j] * pb_y[j] + 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_xy[j] + 0.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_yy[j] + pa_y[j] * fl1_fx * pc_xy[j] * pb_y[j] + pa_y[j] * fl1_fx * pb_xy[j] * pc_y[j] + 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yy[j] + pc_yy[j] * fl1_fx * pb_xy[j] + 0.5 * pc_xy[j] * fl1_fx * pb_yy[j] + 0.5 * pc_y[j] * fl1_fx * pb_xyy[j] + pa_yzz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_yzz[j] * pc_xy[j] * pb_y[j] + 4.0 * pa_yz[j] * pc_yz[j] * pb_xy[j] + 2.0 * pa_yz[j] * pc_xz[j] * pb_yy[j] + pa_y[j] * pc_zz[j] * pb_xyy[j] + 2.0 * pc_yy[j] * pa_zz[j] * pb_xy[j] + pc_xy[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xyy[j]);

                t_yzz_xyy[j] += fl_s_0_0_3 * (-0.25 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.5 * fl2_fx * pc_x[j] * pb_y[j] - pa_yz[j] * pc_xz[j] * fl1_fx - 0.5 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx - 0.5 * pa_y[j] * pc_xzz[j] * fl1_fx - 1.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 1.5 * pc_yzz[j] * pb_x[j] * fl1_fx - fl1_fx * pc_xzz[j] * pb_y[j] - 2.0 * fl1_fx * pa_z[j] * pc_xz[j] * pb_y[j] - fl1_fx * pc_zz[j] * pb_xy[j] - 0.5 * pa_y[j] * fl1_fx * pc_xyy[j] - 0.5 * pa_y[j] * fl1_fx * pb_x[j] * pc_yy[j] - pa_y[j] * fl1_fx * pc_xy[j] * pb_y[j] - 0.5 * pc_yyy[j] * fl1_fx * pb_x[j] - pc_xyy[j] * fl1_fx * pb_y[j] - pc_yy[j] * fl1_fx * pb_xy[j] - 0.5 * pc_xy[j] * fl1_fx * pb_yy[j] - pa_yzz[j] * pc_xyy[j] - 2.0 * pa_yz[j] * pc_yyz[j] * pb_x[j] - 4.0 * pa_yz[j] * pc_xyz[j] * pb_y[j] - 2.0 * pa_y[j] * pc_yzz[j] * pb_xy[j] - pa_y[j] * pc_xzz[j] * pb_yy[j] - pc_yyy[j] * pa_zz[j] * pb_x[j] - 2.0 * pc_xyy[j] * pa_zz[j] * pb_y[j] - 4.0 * pc_yyz[j] * pa_z[j] * pb_xy[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_yy[j] - pc_yzz[j] * pb_xyy[j]);

                t_yzz_xyy[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 0.5 * pa_y[j] * pc_xzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 1.5 * pc_yzz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xyzz[j] * fl1_fx + fl1_fx * pc_xzz[j] * pb_y[j] + 0.5 * pa_y[j] * fl1_fx * pc_xyy[j] + 0.5 * pc_xyyy[j] * fl1_fx + 0.5 * pc_yyy[j] * fl1_fx * pb_x[j] + pc_xyy[j] * fl1_fx * pb_y[j] + 2.0 * pa_yz[j] * pc_xyyz[j] + pa_y[j] * pc_yyzz[j] * pb_x[j] + 2.0 * pa_y[j] * pc_xyzz[j] * pb_y[j] + pc_xyyy[j] * pa_zz[j] + 2.0 * pc_yyyz[j] * pa_z[j] * pb_x[j] + 4.0 * pc_xyyz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_yyzz[j] * pb_xy[j] + pc_xyzz[j] * pb_yy[j]);

                t_yzz_xyy[j] += fl_s_0_0_5 * (-1.5 * pc_xyzz[j] * fl1_fx - 0.5 * pc_xyyy[j] * fl1_fx - pa_y[j] * pc_xyyzz[j] - 2.0 * pc_xyyyz[j] * pa_z[j] - pc_yyyzz[j] * pb_x[j] - 2.0 * pc_xyyzz[j] * pb_y[j]);

                t_yzz_xyy[j] += fl_s_0_0_6 * pc_xyyyzz[j];

                t_yzz_xyz[j] = fl_s_0_0_0 * (0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.25 * fl2_fx * pb_xz[j] + pa_yz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xz[j] + 0.5 * pa_y[j] * fl1_fx * pb_xyz[j] + pa_yzz[j] * pb_xyz[j]);

                t_yzz_xyz[j] += fl_s_0_0_1 * (-0.5 * fl2_fx * pa_z[j] * pc_x[j] - fl2_fx * pa_z[j] * pb_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 0.25 * fl2_fx * pc_x[j] * pb_z[j] - 0.5 * fl2_fx * pb_xz[j] - pa_yz[j] * fl1_fx * pb_x[j] * pc_y[j] - pa_yz[j] * fl1_fx * pc_x[j] * pb_y[j] - pa_yz[j] * fl1_fx * pb_xy[j] - 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_xy[j] - pc_y[j] * pa_z[j] * fl1_fx * pb_xy[j] - 0.5 * fl1_fx * pa_zz[j] * pb_x[j] * pc_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_x[j] * pb_z[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_xz[j] - 0.5 * fl1_fx * pa_zz[j] * pb_xz[j] - 0.5 * pa_y[j] * fl1_fx * pb_xz[j] * pc_y[j] - 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yz[j] - 0.5 * pa_y[j] * fl1_fx * pb_xyz[j] - 0.5 * pc_y[j] * fl1_fx * pb_xyz[j] - pa_yzz[j] * pb_xy[j] * pc_z[j] - pa_yzz[j] * pb_xz[j] * pc_y[j] - pa_yzz[j] * pc_x[j] * pb_yz[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xyz[j] - pc_y[j] * pa_zz[j] * pb_xyz[j]);

                t_yzz_xyz[j] += fl_s_0_0_2 * (fl2_fx * pa_z[j] * pc_x[j] + 0.75 * fl2_fx * pc_xz[j] + 1.5 * fl2_fx * pc_z[j] * pb_x[j] + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pc_x[j] * pb_z[j] + 0.25 * fl2_fx * pb_xz[j] + pa_yz[j] * fl1_fx * pc_xy[j] + pa_yz[j] * fl1_fx * pb_x[j] * pc_y[j] + pa_yz[j] * fl1_fx * pc_x[j] * pb_y[j] + 1.5 * pa_y[j] * pc_yz[j] * fl1_fx * pb_x[j] + 1.5 * pa_y[j] * pc_xz[j] * fl1_fx * pb_y[j] + 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_xy[j] + pc_yy[j] * pa_z[j] * fl1_fx * pb_x[j] + pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] + pc_y[j] * pa_z[j] * fl1_fx * pb_xy[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pc_xz[j] + fl1_fx * pa_z[j] * pc_zz[j] * pb_x[j] + fl1_fx * pa_z[j] * pc_xz[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_xz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_x[j] * pc_z[j] + 0.5 * fl1_fx * pa_zz[j] * pc_x[j] * pb_z[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_xz[j] + 0.5 * pa_y[j] * fl1_fx * pc_xy[j] * pb_z[j] + 0.5 * pa_y[j] * fl1_fx * pb_xz[j] * pc_y[j] + 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_yz[j] + 0.5 * pc_yy[j] * fl1_fx * pb_xz[j] + 0.5 * pc_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pc_y[j] * fl1_fx * pb_xyz[j] + pa_yzz[j] * pb_x[j] * pc_yz[j] + pa_yzz[j] * pc_xz[j] * pb_y[j] + pa_yzz[j] * pc_xy[j] * pb_z[j] + 2.0 * pa_yz[j] * pc_zz[j] * pb_xy[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_xz[j] + 2.0 * pa_yz[j] * pc_xz[j] * pb_yz[j] + pa_y[j] * pc_zz[j] * pb_xyz[j] + pc_yz[j] * pa_zz[j] * pb_xy[j] + pc_yy[j] * pa_zz[j] * pb_xz[j] + pc_xy[j] * pa_zz[j] * pb_yz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xyz[j]);

                t_yzz_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xz[j] - 0.5 * fl2_fx * pa_z[j] * pc_x[j] - 0.75 * fl2_fx * pc_z[j] * pb_x[j] - 0.25 * fl2_fx * pc_x[j] * pb_z[j] - pa_yz[j] * fl1_fx * pc_xy[j] - 1.5 * pa_y[j] * pc_xyz[j] * fl1_fx - 1.5 * pa_y[j] * pc_yz[j] * fl1_fx * pb_x[j] - 1.5 * pa_y[j] * pc_xz[j] * fl1_fx * pb_y[j] - pc_xyy[j] * pa_z[j] * fl1_fx - pc_yy[j] * pa_z[j] * fl1_fx * pb_x[j] - pc_xy[j] * pa_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_yyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xy[j] - fl1_fx * pa_z[j] * pc_xzz[j] - 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] - 0.5 * fl1_fx * pc_xzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_xz[j] - fl1_fx * pa_z[j] * pc_zz[j] * pb_x[j] - fl1_fx * pa_z[j] * pc_xz[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_xz[j] - 0.5 * pa_y[j] * fl1_fx * pc_xy[j] * pb_z[j] - 0.5 * pc_xyy[j] * fl1_fx * pb_z[j] - 0.5 * pc_yy[j] * fl1_fx * pb_xz[j] - 0.5 * pc_xy[j] * fl1_fx * pb_yz[j] - pa_yzz[j] * pc_xyz[j] - 2.0 * pa_yz[j] * pc_yzz[j] * pb_x[j] - 2.0 * pa_yz[j] * pc_xzz[j] * pb_y[j] - 2.0 * pa_yz[j] * pc_xyz[j] * pb_z[j] - pa_y[j] * pc_zzz[j] * pb_xy[j] - pa_y[j] * pc_yzz[j] * pb_xz[j] - pa_y[j] * pc_xzz[j] * pb_yz[j] - pc_yyz[j] * pa_zz[j] * pb_x[j] - pc_xyz[j] * pa_zz[j] * pb_y[j] - pc_xyy[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_yzz[j] * pa_z[j] * pb_xy[j] - 2.0 * pc_yyz[j] * pa_z[j] * pb_xz[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_yz[j] - pc_yzz[j] * pb_xyz[j]);

                t_yzz_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xz[j] + 1.5 * pa_y[j] * pc_xyz[j] * fl1_fx + pc_xyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_yyz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pc_xzzz[j] + fl1_fx * pa_z[j] * pc_xzz[j] + 0.5 * fl1_fx * pc_zzz[j] * pb_x[j] + 0.5 * fl1_fx * pc_xzz[j] * pb_z[j] + 0.5 * pc_xyy[j] * fl1_fx * pb_z[j] + 2.0 * pa_yz[j] * pc_xyzz[j] + pa_y[j] * pc_yzzz[j] * pb_x[j] + pa_y[j] * pc_xzzz[j] * pb_y[j] + pa_y[j] * pc_xyzz[j] * pb_z[j] + pc_xyyz[j] * pa_zz[j] + 2.0 * pc_yyzz[j] * pa_z[j] * pb_x[j] + 2.0 * pc_xyzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_xyyz[j] * pa_z[j] * pb_z[j] + pc_yzzz[j] * pb_xy[j] + pc_yyzz[j] * pb_xz[j] + pc_xyzz[j] * pb_yz[j]);

                t_yzz_xyz[j] += fl_s_0_0_5 * (-1.5 * pc_xyyz[j] * fl1_fx - 0.5 * fl1_fx * pc_xzzz[j] - pa_y[j] * pc_xyzzz[j] - 2.0 * pc_xyyzz[j] * pa_z[j] - pc_yyzzz[j] * pb_x[j] - pc_xyzzz[j] * pb_y[j] - pc_xyyzz[j] * pb_z[j]);

                t_yzz_xyz[j] += fl_s_0_0_6 * pc_xyyzzz[j];

                t_yzz_xzz[j] = fl_s_0_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 0.5 * pa_yzz[j] * pb_x[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pb_xz[j] + 0.5 * pa_y[j] * fl1_fx * pb_xzz[j] + pa_yzz[j] * pb_xzz[j]);

                t_yzz_xzz[j] += fl_s_0_0_1 * (-0.75 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pa_y[j] * fl2_fx * pb_x[j] - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 0.5 * pa_yzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_yzz[j] * pc_x[j] * fl1_fx - 3.0 * pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx - 2.0 * pa_yz[j] * fl1_fx * pc_x[j] * pb_z[j] - 2.0 * pa_yz[j] * fl1_fx * pb_xz[j] - 3.0 * pa_y[j] * pc_z[j] * fl1_fx * pb_xz[j] - 0.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx - 2.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_xz[j] - 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_zz[j] - 0.5 * pa_y[j] * fl1_fx * pb_xzz[j] - 0.5 * pc_y[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_yzz[j] * pb_xz[j] * pc_z[j] - pa_yzz[j] * pc_x[j] * pb_zz[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_xzz[j] - pc_y[j] * pa_zz[j] * pb_xzz[j]);

                t_yzz_xzz[j] += fl_s_0_0_2 * (1.5 * pa_y[j] * fl2_fx * pc_x[j] + 0.75 * pa_y[j] * fl2_fx * pb_x[j] + 0.75 * pc_xy[j] * fl2_fx + 1.5 * pc_y[j] * fl2_fx * pb_x[j] + 0.5 * pa_yzz[j] * pc_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_z[j] * pb_x[j] * fl1_fx + 3.0 * pa_yz[j] * pc_xz[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pc_x[j] * pb_z[j] + 3.0 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx + 3.0 * pa_y[j] * pc_xz[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * pc_z[j] * fl1_fx * pb_xz[j] + 0.5 * pc_y[j] * pa_zz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx + 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_xz[j] + 3.0 * pc_yz[j] * fl1_fx * pb_xz[j] + 0.5 * pa_y[j] * fl1_fx * pc_x[j] * pb_zz[j] + 0.5 * pc_xy[j] * fl1_fx * pb_zz[j] + 0.5 * pc_y[j] * fl1_fx * pb_xzz[j] + pa_yzz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_yzz[j] * pc_xz[j] * pb_z[j] + 4.0 * pa_yz[j] * pc_zz[j] * pb_xz[j] + 2.0 * pa_yz[j] * pc_xz[j] * pb_zz[j] + pa_y[j] * pc_zz[j] * pb_xzz[j] + 2.0 * pc_yz[j] * pa_zz[j] * pb_xz[j] + pc_xy[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_xzz[j]);

                t_yzz_xzz[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * fl2_fx * pc_x[j] - 1.5 * pc_xy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_x[j] - 3.0 * pa_yz[j] * pc_xz[j] * fl1_fx - 3.0 * pa_y[j] * pc_zz[j] * pb_x[j] * fl1_fx - 3.0 * pa_y[j] * pc_xzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_xz[j] * fl1_fx * pb_z[j] - 0.5 * pc_xy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_yz[j] * pa_z[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx - 2.0 * pc_xy[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_yzz[j] * pb_x[j] * fl1_fx - 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yz[j] * fl1_fx * pb_xz[j] - 0.5 * pc_xy[j] * fl1_fx * pb_zz[j] - pa_yzz[j] * pc_xzz[j] - 2.0 * pa_yz[j] * pc_zzz[j] * pb_x[j] - 4.0 * pa_yz[j] * pc_xzz[j] * pb_z[j] - 2.0 * pa_y[j] * pc_zzz[j] * pb_xz[j] - pa_y[j] * pc_xzz[j] * pb_zz[j] - pc_yzz[j] * pa_zz[j] * pb_x[j] - 2.0 * pc_xyz[j] * pa_zz[j] * pb_z[j] - 4.0 * pc_yzz[j] * pa_z[j] * pb_xz[j] - 2.0 * pc_xyz[j] * pa_z[j] * pb_zz[j] - pc_yzz[j] * pb_xzz[j]);

                t_yzz_xzz[j] += fl_s_0_0_4 * (0.75 * pc_xy[j] * fl2_fx + 3.0 * pa_y[j] * pc_xzz[j] * fl1_fx + 3.0 * pc_xyz[j] * pa_z[j] * fl1_fx + 3.0 * pc_yzz[j] * pb_x[j] * fl1_fx + 3.0 * pc_xyzz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_z[j] + 2.0 * pa_yz[j] * pc_xzzz[j] + pa_y[j] * pc_zzzz[j] * pb_x[j] + 2.0 * pa_y[j] * pc_xzzz[j] * pb_z[j] + pc_xyzz[j] * pa_zz[j] + 2.0 * pc_yzzz[j] * pa_z[j] * pb_x[j] + 4.0 * pc_xyzz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_yzzz[j] * pb_xz[j] + pc_xyzz[j] * pb_zz[j]);

                t_yzz_xzz[j] += fl_s_0_0_5 * (-3.0 * pc_xyzz[j] * fl1_fx - pa_y[j] * pc_xzzzz[j] - 2.0 * pc_xyzzz[j] * pa_z[j] - pc_yzzzz[j] * pb_x[j] - 2.0 * pc_xyzzz[j] * pb_z[j]);

                t_yzz_xzz[j] += fl_s_0_0_6 * pc_xyzzzz[j];

                t_yzz_yyy[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_yzz[j] * pb_y[j] * fl1_fx + 1.5 * fl1_fx * pa_zz[j] * pb_yy[j] + 0.5 * pa_y[j] * fl1_fx * pb_yyy[j] + pa_yzz[j] * pb_yyy[j]);

                t_yzz_yyy[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * fl2_fx * pa_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 1.5 * pa_y[j] * fl2_fx * pb_y[j] - 0.75 * pa_y[j] * fl2_fx * pc_y[j] - 2.25 * pc_y[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pb_yy[j] - 1.5 * pa_yzz[j] * pb_y[j] * fl1_fx - 1.5 * pa_yzz[j] * pc_y[j] * fl1_fx - 3.0 * pa_yz[j] * pc_z[j] * pb_y[j] * fl1_fx - 4.5 * pc_y[j] * pa_zz[j] * pb_y[j] * fl1_fx - 3.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_yy[j] - 1.5 * fl1_fx * pa_zz[j] * pb_yy[j] - 1.5 * pa_y[j] * fl1_fx * pb_yy[j] * pc_y[j] - 0.5 * pa_y[j] * fl1_fx * pb_yyy[j] - 0.5 * pc_y[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_yzz[j] * pb_yy[j] * pc_y[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_yyy[j] - pc_y[j] * pa_zz[j] * pb_yyy[j]);

                t_yzz_yyy[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 3.0 * fl2_fx * pa_z[j] * pc_z[j] + 0.75 * fl2_fx * pc_zz[j] + 0.75 * fl2_fx * pa_zz[j] + 1.5 * pa_y[j] * fl2_fx * pc_y[j] + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 4.5 * pc_y[j] * fl2_fx * pb_y[j] + 1.5 * pc_yy[j] * fl2_fx + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_yzz[j] * pc_y[j] * fl1_fx + 3.0 * pa_yz[j] * pc_z[j] * pb_y[j] * fl1_fx + 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx + 1.5 * pa_y[j] * pc_zz[j] * pb_y[j] * fl1_fx + 4.5 * pc_y[j] * pa_zz[j] * pb_y[j] * fl1_fx + 3.0 * pc_yy[j] * pa_zz[j] * fl1_fx + 9.0 * pc_yz[j] * pa_z[j] * pb_y[j] * fl1_fx + 1.5 * fl1_fx * pc_zz[j] * pb_yy[j] + 3.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_yy[j] + 1.5 * pa_y[j] * fl1_fx * pb_y[j] * pc_yy[j] + 1.5 * pa_y[j] * fl1_fx * pb_yy[j] * pc_y[j] + 1.5 * pc_yy[j] * fl1_fx * pb_yy[j] + 0.5 * pc_y[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_yzz[j] * pb_y[j] * pc_yy[j] + 6.0 * pa_yz[j] * pc_yz[j] * pb_yy[j] + pa_y[j] * pc_zz[j] * pb_yyy[j] + 3.0 * pc_yy[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_yyy[j]);

                t_yzz_yyy[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 1.5 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 0.75 * pa_y[j] * fl2_fx * pc_y[j] - 3.0 * pc_yy[j] * fl2_fx - 2.25 * pc_y[j] * fl2_fx * pb_y[j] - 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx - 1.5 * pa_y[j] * pc_zz[j] * pb_y[j] * fl1_fx - 1.5 * pa_y[j] * pc_yzz[j] * fl1_fx - 3.0 * pc_yy[j] * pa_zz[j] * fl1_fx - 9.0 * pc_yz[j] * pa_z[j] * pb_y[j] * fl1_fx - 6.0 * pc_yyz[j] * pa_z[j] * fl1_fx - 4.5 * pc_yzz[j] * pb_y[j] * fl1_fx - 1.5 * fl1_fx * pc_zz[j] * pb_yy[j] - 0.5 * pa_y[j] * fl1_fx * pc_yyy[j] - 1.5 * pa_y[j] * fl1_fx * pb_y[j] * pc_yy[j] - 1.5 * pc_yyy[j] * fl1_fx * pb_y[j] - 1.5 * pc_yy[j] * fl1_fx * pb_yy[j] - pa_yzz[j] * pc_yyy[j] - 6.0 * pa_yz[j] * pc_yyz[j] * pb_y[j] - 3.0 * pa_y[j] * pc_yzz[j] * pb_yy[j] - 3.0 * pc_yyy[j] * pa_zz[j] * pb_y[j] - 6.0 * pc_yyz[j] * pa_z[j] * pb_yy[j] - pc_yzz[j] * pb_yyy[j]);

                t_yzz_yyy[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_zz[j] + 1.5 * pc_yy[j] * fl2_fx + 1.5 * pa_y[j] * pc_yzz[j] * fl1_fx + 6.0 * pc_yyz[j] * pa_z[j] * fl1_fx + 4.5 * pc_yzz[j] * pb_y[j] * fl1_fx + 3.0 * pc_yyzz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pc_yyy[j] + 0.5 * pc_yyyy[j] * fl1_fx + 1.5 * pc_yyy[j] * fl1_fx * pb_y[j] + 2.0 * pa_yz[j] * pc_yyyz[j] + 3.0 * pa_y[j] * pc_yyzz[j] * pb_y[j] + pc_yyyy[j] * pa_zz[j] + 6.0 * pc_yyyz[j] * pa_z[j] * pb_y[j] + 3.0 * pc_yyzz[j] * pb_yy[j]);

                t_yzz_yyy[j] += fl_s_0_0_5 * (-3.0 * pc_yyzz[j] * fl1_fx - 0.5 * pc_yyyy[j] * fl1_fx - pa_y[j] * pc_yyyzz[j] - 2.0 * pc_yyyyz[j] * pa_z[j] - 3.0 * pc_yyyzz[j] * pb_y[j]);

                t_yzz_yyy[j] += fl_s_0_0_6 * pc_yyyyzz[j];

                t_yzz_yyz[j] = fl_s_0_0_0 * (0.5 * pa_yz[j] * fl2_fx + fl2_fx * pa_z[j] * pb_y[j] + 0.25 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yzz[j] * fl1_fx * pb_z[j] + pa_yz[j] * fl1_fx * pb_yy[j] + fl1_fx * pa_zz[j] * pb_yz[j] + 0.5 * pa_y[j] * fl1_fx * pb_yyz[j] + pa_yzz[j] * pb_yyz[j]);

                t_yzz_yyz[j] += fl_s_0_0_1 * (-pa_yz[j] * fl2_fx - 0.75 * pa_y[j] * pc_z[j] * fl2_fx - 1.5 * pc_y[j] * pa_z[j] * fl2_fx - 2.0 * fl2_fx * pa_z[j] * pb_y[j] - 1.5 * fl2_fx * pc_z[j] * pb_y[j] - 0.5 * pa_y[j] * fl2_fx * pb_z[j] - 0.75 * pc_y[j] * fl2_fx * pb_z[j] - fl2_fx * pb_yz[j] - 0.5 * pa_yzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_yzz[j] * fl1_fx * pb_z[j] - pa_yz[j] * pc_z[j] * fl1_fx * pb_z[j] - 2.0 * pa_yz[j] * fl1_fx * pb_y[j] * pc_y[j] - pa_yz[j] * fl1_fx * pb_yy[j] - 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_yy[j] - 1.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_z[j] - pc_y[j] * pa_z[j] * fl1_fx * pb_yy[j] - fl1_fx * pa_zz[j] * pb_y[j] * pc_z[j] - 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_yz[j] - fl1_fx * pa_zz[j] * pb_yz[j] - pa_y[j] * fl1_fx * pb_yz[j] * pc_y[j] - 0.5 * pa_y[j] * fl1_fx * pb_yyz[j] - 0.5 * pc_y[j] * fl1_fx * pb_yyz[j] - pa_yzz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_yzz[j] * pb_yz[j] * pc_y[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_yyz[j] - pc_y[j] * pa_zz[j] * pb_yyz[j]);

                t_yzz_yyz[j] += fl_s_0_0_2 * (0.5 * pa_yz[j] * fl2_fx + 1.5 * pa_y[j] * pc_z[j] * fl2_fx + 3.0 * pc_y[j] * pa_z[j] * fl2_fx + 2.25 * pc_yz[j] * fl2_fx + 3.0 * fl2_fx * pc_z[j] * pb_y[j] + fl2_fx * pa_z[j] * pb_y[j] + 0.25 * pa_y[j] * fl2_fx * pb_z[j] + 1.5 * pc_y[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_yzz[j] * fl1_fx * pc_z[j] + pa_yz[j] * pc_zz[j] * fl1_fx + pa_yz[j] * pc_z[j] * fl1_fx * pb_z[j] + pa_yz[j] * fl1_fx * pc_yy[j] + 2.0 * pa_yz[j] * fl1_fx * pb_y[j] * pc_y[j] + 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] + 1.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_yy[j] + 1.5 * pc_yz[j] * pa_zz[j] * fl1_fx + 1.5 * pc_y[j] * pa_zz[j] * fl1_fx * pb_z[j] + 3.0 * pc_yz[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_y[j] + pc_y[j] * pa_z[j] * fl1_fx * pb_yy[j] + 1.5 * pc_yz[j] * fl1_fx * pb_yy[j] + 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_y[j] + fl1_fx * pc_zz[j] * pb_yz[j] + fl1_fx * pa_zz[j] * pb_y[j] * pc_z[j] + 2.0 * fl1_fx * pa_z[j] * pc_z[j] * pb_yz[j] + 0.5 * pa_y[j] * fl1_fx * pc_yy[j] * pb_z[j] + pa_y[j] * fl1_fx * pb_yz[j] * pc_y[j] + pc_yy[j] * fl1_fx * pb_yz[j] + 0.5 * pc_y[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_yzz[j] * pb_y[j] * pc_yz[j] + pa_yzz[j] * pc_yy[j] * pb_z[j] + 2.0 * pa_yz[j] * pc_zz[j] * pb_yy[j] + 4.0 * pa_yz[j] * pc_yz[j] * pb_yz[j] + pa_y[j] * pc_zz[j] * pb_yyz[j] + pc_yz[j] * pa_zz[j] * pb_yy[j] + 2.0 * pc_yy[j] * pa_zz[j] * pb_yz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_yyz[j]);

                t_yzz_yyz[j] += fl_s_0_0_3 * (-0.75 * pa_y[j] * pc_z[j] * fl2_fx - 1.5 * pc_y[j] * pa_z[j] * fl2_fx - 4.5 * pc_yz[j] * fl2_fx - 1.5 * fl2_fx * pc_z[j] * pb_y[j] - 0.75 * pc_y[j] * fl2_fx * pb_z[j] - pa_yz[j] * pc_zz[j] * fl1_fx - pa_yz[j] * fl1_fx * pc_yy[j] - 0.5 * pa_y[j] * pc_zzz[j] * fl1_fx - 0.5 * pa_y[j] * pc_zz[j] * fl1_fx * pb_z[j] - 1.5 * pa_y[j] * pc_yyz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_y[j] - 1.5 * pc_yz[j] * pa_zz[j] * fl1_fx - 3.0 * pc_yzz[j] * pa_z[j] * fl1_fx - 3.0 * pc_yz[j] * pa_z[j] * fl1_fx * pb_z[j] - pc_yyy[j] * pa_z[j] * fl1_fx - 2.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_y[j] - 1.5 * pc_yzz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yyz[j] * fl1_fx * pb_y[j] - 1.5 * pc_yz[j] * fl1_fx * pb_yy[j] - fl1_fx * pc_zzz[j] * pb_y[j] - 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_y[j] - fl1_fx * pc_zz[j] * pb_yz[j] - 0.5 * pa_y[j] * fl1_fx * pc_yy[j] * pb_z[j] - 0.5 * pc_yyy[j] * fl1_fx * pb_z[j] - pc_yy[j] * fl1_fx * pb_yz[j] - pa_yzz[j] * pc_yyz[j] - 4.0 * pa_yz[j] * pc_yzz[j] * pb_y[j] - 2.0 * pa_yz[j] * pc_yyz[j] * pb_z[j] - pa_y[j] * pc_zzz[j] * pb_yy[j] - 2.0 * pa_y[j] * pc_yzz[j] * pb_yz[j] - 2.0 * pc_yyz[j] * pa_zz[j] * pb_y[j] - pc_yyy[j] * pa_zz[j] * pb_z[j] - 2.0 * pc_yzz[j] * pa_z[j] * pb_yy[j] - 4.0 * pc_yyz[j] * pa_z[j] * pb_yz[j] - pc_yzz[j] * pb_yyz[j]);

                t_yzz_yyz[j] += fl_s_0_0_4 * (2.25 * pc_yz[j] * fl2_fx + 0.5 * pa_y[j] * pc_zzz[j] * fl1_fx + 1.5 * pa_y[j] * pc_yyz[j] * fl1_fx + 3.0 * pc_yzz[j] * pa_z[j] * fl1_fx + pc_yyy[j] * pa_z[j] * fl1_fx + 1.5 * pc_yzzz[j] * fl1_fx + 1.5 * pc_yzz[j] * fl1_fx * pb_z[j] + 1.5 * pc_yyyz[j] * fl1_fx + 3.0 * pc_yyz[j] * fl1_fx * pb_y[j] + fl1_fx * pc_zzz[j] * pb_y[j] + 0.5 * pc_yyy[j] * fl1_fx * pb_z[j] + 2.0 * pa_yz[j] * pc_yyzz[j] + 2.0 * pa_y[j] * pc_yzzz[j] * pb_y[j] + pa_y[j] * pc_yyzz[j] * pb_z[j] + pc_yyyz[j] * pa_zz[j] + 4.0 * pc_yyzz[j] * pa_z[j] * pb_y[j] + 2.0 * pc_yyyz[j] * pa_z[j] * pb_z[j] + pc_yzzz[j] * pb_yy[j] + 2.0 * pc_yyzz[j] * pb_yz[j]);

                t_yzz_yyz[j] += fl_s_0_0_5 * (-1.5 * pc_yzzz[j] * fl1_fx - 1.5 * pc_yyyz[j] * fl1_fx - pa_y[j] * pc_yyzzz[j] - 2.0 * pc_yyyzz[j] * pa_z[j] - 2.0 * pc_yyzzz[j] * pb_y[j] - pc_yyyzz[j] * pb_z[j]);

                t_yzz_yyz[j] += fl_s_0_0_6 * pc_yyyzzz[j];

                t_yzz_yzz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_yzz[j] * pb_y[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] + 0.5 * pa_y[j] * fl1_fx * pb_yzz[j] + pa_yzz[j] * pb_yzz[j]);

                t_yzz_yzz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 0.75 * pa_y[j] * fl2_fx * pc_y[j] - 1.5 * pa_y[j] * fl2_fx * pb_y[j] - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 0.5 * fl2_fx * pa_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 2.0 * fl2_fx * pa_z[j] * pb_z[j] - 1.5 * fl2_fx * pc_z[j] * pb_z[j] - 0.5 * fl2_fx * pb_zz[j] - 0.5 * pa_yzz[j] * pb_y[j] * fl1_fx - 0.5 * pa_yzz[j] * pc_y[j] * fl1_fx - 3.0 * pa_yz[j] * pc_z[j] * pb_y[j] * fl1_fx - 2.0 * pa_yz[j] * fl1_fx * pc_y[j] * pb_z[j] - 2.0 * pa_yz[j] * fl1_fx * pb_yz[j] - 3.0 * pa_y[j] * pc_z[j] * fl1_fx * pb_yz[j] - 0.5 * pc_y[j] * pa_zz[j] * pb_y[j] * fl1_fx - 2.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_yz[j] - fl1_fx * pa_zz[j] * pb_z[j] * pc_z[j] - fl1_fx * pa_z[j] * pc_z[j] * pb_zz[j] - 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] - 0.5 * pa_y[j] * fl1_fx * pc_y[j] * pb_zz[j] - 0.5 * pa_y[j] * fl1_fx * pb_yzz[j] - 0.5 * pc_y[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_yzz[j] * pb_yz[j] * pc_z[j] - pa_yzz[j] * pc_y[j] * pb_zz[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_yzz[j] - pc_y[j] * pa_zz[j] * pb_yzz[j]);

                t_yzz_yzz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 1.5 * pa_y[j] * fl2_fx * pc_y[j] + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * pc_yy[j] * fl2_fx + 1.5 * pc_y[j] * fl2_fx * pb_y[j] + 3.0 * fl2_fx * pa_z[j] * pc_z[j] + 1.5 * fl2_fx * pc_zz[j] + 3.0 * fl2_fx * pc_z[j] * pb_z[j] + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_yzz[j] * pc_y[j] * fl1_fx + 3.0 * pa_yz[j] * pc_z[j] * pb_y[j] * fl1_fx + 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pc_y[j] * pb_z[j] + 3.0 * pa_y[j] * pc_zz[j] * pb_y[j] * fl1_fx + 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] + 3.0 * pa_y[j] * pc_z[j] * fl1_fx * pb_yz[j] + 0.5 * pc_y[j] * pa_zz[j] * pb_y[j] * fl1_fx + 0.5 * pc_yy[j] * pa_zz[j] * fl1_fx + 3.0 * pc_yz[j] * pa_z[j] * pb_y[j] * fl1_fx + 2.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] + 2.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_yz[j] + 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_zz[j] * pc_zz[j] + 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_z[j] + 0.5 * fl1_fx * pc_zz[j] * pb_zz[j] + fl1_fx * pa_zz[j] * pb_z[j] * pc_z[j] + fl1_fx * pa_z[j] * pc_z[j] * pb_zz[j] + 0.5 * pa_y[j] * fl1_fx * pc_y[j] * pb_zz[j] + 0.5 * pc_yy[j] * fl1_fx * pb_zz[j] + 0.5 * pc_y[j] * fl1_fx * pb_yzz[j] + pa_yzz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_yzz[j] * pc_yz[j] * pb_z[j] + 4.0 * pa_yz[j] * pc_zz[j] * pb_yz[j] + 2.0 * pa_yz[j] * pc_yz[j] * pb_zz[j] + pa_y[j] * pc_zz[j] * pb_yzz[j] + 2.0 * pc_yz[j] * pa_zz[j] * pb_yz[j] + pc_yy[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_yzz[j]);

                t_yzz_yzz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 0.75 * pa_y[j] * fl2_fx * pc_y[j] - 1.5 * pc_yy[j] * fl2_fx - 0.75 * pc_y[j] * fl2_fx * pb_y[j] - 3.0 * fl2_fx * pc_zz[j] - 1.5 * fl2_fx * pa_z[j] * pc_z[j] - 1.5 * fl2_fx * pc_z[j] * pb_z[j] - 3.0 * pa_yz[j] * pc_yz[j] * fl1_fx - 3.0 * pa_y[j] * pc_zz[j] * pb_y[j] * fl1_fx - 3.0 * pa_y[j] * pc_yzz[j] * fl1_fx - 3.0 * pa_y[j] * pc_yz[j] * fl1_fx * pb_z[j] - 0.5 * pc_yy[j] * pa_zz[j] * fl1_fx - 3.0 * pc_yz[j] * pa_z[j] * pb_y[j] * fl1_fx - 3.0 * pc_yyz[j] * pa_z[j] * fl1_fx - 2.0 * pc_yy[j] * pa_z[j] * fl1_fx * pb_z[j] - 3.0 * pc_yzz[j] * pb_y[j] * fl1_fx - 3.0 * pc_yyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] - fl1_fx * pa_z[j] * pc_zzz[j] - fl1_fx * pc_zzz[j] * pb_z[j] - 0.5 * fl1_fx * pa_zz[j] * pc_zz[j] - 2.0 * fl1_fx * pa_z[j] * pc_zz[j] * pb_z[j] - 0.5 * fl1_fx * pc_zz[j] * pb_zz[j] - 0.5 * pc_yy[j] * fl1_fx * pb_zz[j] - pa_yzz[j] * pc_yzz[j] - 2.0 * pa_yz[j] * pc_zzz[j] * pb_y[j] - 4.0 * pa_yz[j] * pc_yzz[j] * pb_z[j] - 2.0 * pa_y[j] * pc_zzz[j] * pb_yz[j] - pa_y[j] * pc_yzz[j] * pb_zz[j] - pc_yzz[j] * pa_zz[j] * pb_y[j] - 2.0 * pc_yyz[j] * pa_zz[j] * pb_z[j] - 4.0 * pc_yzz[j] * pa_z[j] * pb_yz[j] - 2.0 * pc_yyz[j] * pa_z[j] * pb_zz[j] - pc_yzz[j] * pb_yzz[j]);

                t_yzz_yzz[j] += fl_s_0_0_4 * (0.75 * pc_yy[j] * fl2_fx + 1.5 * fl2_fx * pc_zz[j] + 3.0 * pa_y[j] * pc_yzz[j] * fl1_fx + 3.0 * pc_yyz[j] * pa_z[j] * fl1_fx + 3.0 * pc_yzz[j] * pb_y[j] * fl1_fx + 3.0 * pc_yyzz[j] * fl1_fx + 3.0 * pc_yyz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pc_zzzz[j] + fl1_fx * pa_z[j] * pc_zzz[j] + fl1_fx * pc_zzz[j] * pb_z[j] + 2.0 * pa_yz[j] * pc_yzzz[j] + pa_y[j] * pc_zzzz[j] * pb_y[j] + 2.0 * pa_y[j] * pc_yzzz[j] * pb_z[j] + pc_yyzz[j] * pa_zz[j] + 2.0 * pc_yzzz[j] * pa_z[j] * pb_y[j] + 4.0 * pc_yyzz[j] * pa_z[j] * pb_z[j] + 2.0 * pc_yzzz[j] * pb_yz[j] + pc_yyzz[j] * pb_zz[j]);

                t_yzz_yzz[j] += fl_s_0_0_5 * (-3.0 * pc_yyzz[j] * fl1_fx - 0.5 * fl1_fx * pc_zzzz[j] - pa_y[j] * pc_yzzzz[j] - 2.0 * pc_yyzzz[j] * pa_z[j] - pc_yzzzz[j] * pb_y[j] - 2.0 * pc_yyzzz[j] * pb_z[j]);

                t_yzz_yzz[j] += fl_s_0_0_6 * pc_yyzzzz[j];

                t_yzz_zzz[j] = fl_s_0_0_0 * (1.5 * pa_yz[j] * fl2_fx + 2.25 * pa_y[j] * fl2_fx * pb_z[j] + 1.5 * pa_yzz[j] * pb_z[j] * fl1_fx + 3.0 * pa_yz[j] * fl1_fx * pb_zz[j] + 0.5 * pa_y[j] * fl1_fx * pb_zzz[j] + pa_yzz[j] * pb_zzz[j]);

                t_yzz_zzz[j] += fl_s_0_0_1 * (-3.0 * pa_yz[j] * fl2_fx - 3.75 * pa_y[j] * pc_z[j] * fl2_fx - 4.5 * pa_y[j] * fl2_fx * pb_z[j] - 1.5 * pc_y[j] * pa_z[j] * fl2_fx - 2.25 * pc_y[j] * fl2_fx * pb_z[j] - 1.5 * pa_yzz[j] * pb_z[j] * fl1_fx - 1.5 * pa_yzz[j] * pc_z[j] * fl1_fx - 9.0 * pa_yz[j] * pc_z[j] * pb_z[j] * fl1_fx - 3.0 * pa_yz[j] * fl1_fx * pb_zz[j] - 4.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_zz[j] - 1.5 * pc_y[j] * pa_zz[j] * pb_z[j] * fl1_fx - 3.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_zz[j] - 0.5 * pa_y[j] * fl1_fx * pb_zzz[j] - 0.5 * pc_y[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_yzz[j] * pb_zz[j] * pc_z[j] - 2.0 * pa_yz[j] * pc_z[j] * pb_zzz[j] - pc_y[j] * pa_zz[j] * pb_zzz[j]);

                t_yzz_zzz[j] += fl_s_0_0_2 * (1.5 * pa_yz[j] * fl2_fx + 7.5 * pa_y[j] * pc_z[j] * fl2_fx + 2.25 * pa_y[j] * fl2_fx * pb_z[j] + 3.0 * pc_y[j] * pa_z[j] * fl2_fx + 3.75 * pc_yz[j] * fl2_fx + 4.5 * pc_y[j] * fl2_fx * pb_z[j] + 1.5 * pa_yzz[j] * pc_z[j] * fl1_fx + 9.0 * pa_yz[j] * pc_z[j] * pb_z[j] * fl1_fx + 6.0 * pa_yz[j] * pc_zz[j] * fl1_fx + 9.0 * pa_y[j] * pc_zz[j] * pb_z[j] * fl1_fx + 4.5 * pa_y[j] * pc_z[j] * fl1_fx * pb_zz[j] + 1.5 * pc_y[j] * pa_zz[j] * pb_z[j] * fl1_fx + 1.5 * pc_yz[j] * pa_zz[j] * fl1_fx + 9.0 * pc_yz[j] * pa_z[j] * pb_z[j] * fl1_fx + 3.0 * pc_y[j] * pa_z[j] * fl1_fx * pb_zz[j] + 4.5 * pc_yz[j] * fl1_fx * pb_zz[j] + 0.5 * pc_y[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_yzz[j] * pb_z[j] * pc_zz[j] + 6.0 * pa_yz[j] * pc_zz[j] * pb_zz[j] + pa_y[j] * pc_zz[j] * pb_zzz[j] + 3.0 * pc_yz[j] * pa_zz[j] * pb_zz[j] + 2.0 * pc_yz[j] * pa_z[j] * pb_zzz[j]);

                t_yzz_zzz[j] += fl_s_0_0_3 * (-3.75 * pa_y[j] * pc_z[j] * fl2_fx - 1.5 * pc_y[j] * pa_z[j] * fl2_fx - 7.5 * pc_yz[j] * fl2_fx - 2.25 * pc_y[j] * fl2_fx * pb_z[j] - 6.0 * pa_yz[j] * pc_zz[j] * fl1_fx - 9.0 * pa_y[j] * pc_zz[j] * pb_z[j] * fl1_fx - 5.0 * pa_y[j] * pc_zzz[j] * fl1_fx - 1.5 * pc_yz[j] * pa_zz[j] * fl1_fx - 9.0 * pc_yz[j] * pa_z[j] * pb_z[j] * fl1_fx - 6.0 * pc_yzz[j] * pa_z[j] * fl1_fx - 9.0 * pc_yzz[j] * pb_z[j] * fl1_fx - 4.5 * pc_yz[j] * fl1_fx * pb_zz[j] - pa_yzz[j] * pc_zzz[j] - 6.0 * pa_yz[j] * pc_zzz[j] * pb_z[j] - 3.0 * pa_y[j] * pc_zzz[j] * pb_zz[j] - 3.0 * pc_yzz[j] * pa_zz[j] * pb_z[j] - 6.0 * pc_yzz[j] * pa_z[j] * pb_zz[j] - pc_yzz[j] * pb_zzz[j]);

                t_yzz_zzz[j] += fl_s_0_0_4 * (3.75 * pc_yz[j] * fl2_fx + 5.0 * pa_y[j] * pc_zzz[j] * fl1_fx + 6.0 * pc_yzz[j] * pa_z[j] * fl1_fx + 9.0 * pc_yzz[j] * pb_z[j] * fl1_fx + 5.0 * pc_yzzz[j] * fl1_fx + 2.0 * pa_yz[j] * pc_zzzz[j] + 3.0 * pa_y[j] * pc_zzzz[j] * pb_z[j] + pc_yzzz[j] * pa_zz[j] + 6.0 * pc_yzzz[j] * pa_z[j] * pb_z[j] + 3.0 * pc_yzzz[j] * pb_zz[j]);

                t_yzz_zzz[j] += fl_s_0_0_5 * (-5.0 * pc_yzzz[j] * fl1_fx - pa_y[j] * pc_zzzzz[j] - 2.0 * pc_yzzzz[j] * pa_z[j] - 3.0 * pc_yzzzz[j] * pb_z[j]);

                t_yzz_zzz[j] += fl_s_0_0_6 * pc_yzzzzz[j];
            }

            idx++;
        }
    }

    void
    compNuclearPotentialForFF_90_100(      CMemBlock2D<double>& primBuffer,
                                     const CMemBlock2D<double>& auxBuffer,
                                     const CMemBlock2D<double>& osFactors,
                                     const CMemBlock2D<double>& paDistances,
                                     const CMemBlock2D<double>& pbDistances,
                                     const CMemBlock2D<double>& pcDistances,
                                     const CGtoBlock&           braGtoBlock,
                                     const CGtoBlock&           ketGtoBlock,
                                     const int32_t              iContrGto)
    {
        // Batch of Integrals (90,100)

        // set up pointers to primitives data on bra side

        auto spos = braGtoBlock.getStartPositions();

        auto epos = braGtoBlock.getEndPositions();

        // set up pointers to primitives data on ket side

        auto nprim = ketGtoBlock.getNumberOfPrimGtos();

        // loop over contracted GTO on bra side

        int32_t idx = 0;

        for (int32_t i = spos[iContrGto]; i < epos[iContrGto]; i++)
        {
            // set up pointers to Obara-Saika factors

            auto fx = osFactors.data(3 * idx);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_zzz = paDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(19 * idx);

            auto pb_y = pbDistances.data(19 * idx + 1);

            auto pb_z = pbDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(19 * idx + 3);

            auto pb_xy = pbDistances.data(19 * idx + 4);

            auto pb_xz = pbDistances.data(19 * idx + 5);

            auto pb_yy = pbDistances.data(19 * idx + 6);

            auto pb_yz = pbDistances.data(19 * idx + 7);

            auto pb_zz = pbDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(19 * idx + 9);

            auto pb_xxy = pbDistances.data(19 * idx + 10);

            auto pb_xxz = pbDistances.data(19 * idx + 11);

            auto pb_xyy = pbDistances.data(19 * idx + 12);

            auto pb_xyz = pbDistances.data(19 * idx + 13);

            auto pb_xzz = pbDistances.data(19 * idx + 14);

            auto pb_yyy = pbDistances.data(19 * idx + 15);

            auto pb_yyz = pbDistances.data(19 * idx + 16);

            auto pb_yzz = pbDistances.data(19 * idx + 17);

            auto pb_zzz = pbDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PC)

            auto pc_x = pcDistances.data(83 * idx);

            auto pc_y = pcDistances.data(83 * idx + 1);

            auto pc_z = pcDistances.data(83 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PC)

            auto pc_xx = pcDistances.data(83 * idx + 3);

            auto pc_xy = pcDistances.data(83 * idx + 4);

            auto pc_xz = pcDistances.data(83 * idx + 5);

            auto pc_yy = pcDistances.data(83 * idx + 6);

            auto pc_yz = pcDistances.data(83 * idx + 7);

            auto pc_zz = pcDistances.data(83 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PC)

            auto pc_xxx = pcDistances.data(83 * idx + 9);

            auto pc_xxy = pcDistances.data(83 * idx + 10);

            auto pc_xxz = pcDistances.data(83 * idx + 11);

            auto pc_xyy = pcDistances.data(83 * idx + 12);

            auto pc_xyz = pcDistances.data(83 * idx + 13);

            auto pc_xzz = pcDistances.data(83 * idx + 14);

            auto pc_yyy = pcDistances.data(83 * idx + 15);

            auto pc_yyz = pcDistances.data(83 * idx + 16);

            auto pc_yzz = pcDistances.data(83 * idx + 17);

            auto pc_zzz = pcDistances.data(83 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PC)

            auto pc_xxxz = pcDistances.data(83 * idx + 21);

            auto pc_xxyz = pcDistances.data(83 * idx + 23);

            auto pc_xxzz = pcDistances.data(83 * idx + 24);

            auto pc_xyyz = pcDistances.data(83 * idx + 26);

            auto pc_xyzz = pcDistances.data(83 * idx + 27);

            auto pc_xzzz = pcDistances.data(83 * idx + 28);

            auto pc_yyyz = pcDistances.data(83 * idx + 30);

            auto pc_yyzz = pcDistances.data(83 * idx + 31);

            auto pc_yzzz = pcDistances.data(83 * idx + 32);

            auto pc_zzzz = pcDistances.data(83 * idx + 33);

            // set up pointers to 5-th order tensor of distance R(PC)

            auto pc_xxxzz = pcDistances.data(83 * idx + 39);

            auto pc_xxyzz = pcDistances.data(83 * idx + 42);

            auto pc_xxzzz = pcDistances.data(83 * idx + 43);

            auto pc_xyyzz = pcDistances.data(83 * idx + 46);

            auto pc_xyzzz = pcDistances.data(83 * idx + 47);

            auto pc_xzzzz = pcDistances.data(83 * idx + 48);

            auto pc_yyyzz = pcDistances.data(83 * idx + 51);

            auto pc_yyzzz = pcDistances.data(83 * idx + 52);

            auto pc_yzzzz = pcDistances.data(83 * idx + 53);

            auto pc_zzzzz = pcDistances.data(83 * idx + 54);

            // set up pointers to 6-th order tensor of distance R(PC)

            auto pc_xxxzzz = pcDistances.data(83 * idx + 64);

            auto pc_xxyzzz = pcDistances.data(83 * idx + 68);

            auto pc_xxzzzz = pcDistances.data(83 * idx + 69);

            auto pc_xyyzzz = pcDistances.data(83 * idx + 73);

            auto pc_xyzzzz = pcDistances.data(83 * idx + 74);

            auto pc_xzzzzz = pcDistances.data(83 * idx + 75);

            auto pc_yyyzzz = pcDistances.data(83 * idx + 79);

            auto pc_yyzzzz = pcDistances.data(83 * idx + 80);

            auto pc_yzzzzz = pcDistances.data(83 * idx + 81);

            auto pc_zzzzzz = pcDistances.data(83 * idx + 82);

            // set up pointers to auxilary integrals

            auto s_0_0_0 = auxBuffer.data(7 * idx);

            auto s_0_0_1 = auxBuffer.data(7 * idx + 1);

            auto s_0_0_2 = auxBuffer.data(7 * idx + 2);

            auto s_0_0_3 = auxBuffer.data(7 * idx + 3);

            auto s_0_0_4 = auxBuffer.data(7 * idx + 4);

            auto s_0_0_5 = auxBuffer.data(7 * idx + 5);

            auto s_0_0_6 = auxBuffer.data(7 * idx + 6);

            // set up pointers to integrals

            auto t_zzz_xxx = primBuffer.data(100 * idx + 90);

            auto t_zzz_xxy = primBuffer.data(100 * idx + 91);

            auto t_zzz_xxz = primBuffer.data(100 * idx + 92);

            auto t_zzz_xyy = primBuffer.data(100 * idx + 93);

            auto t_zzz_xyz = primBuffer.data(100 * idx + 94);

            auto t_zzz_xzz = primBuffer.data(100 * idx + 95);

            auto t_zzz_yyy = primBuffer.data(100 * idx + 96);

            auto t_zzz_yyz = primBuffer.data(100 * idx + 97);

            auto t_zzz_yzz = primBuffer.data(100 * idx + 98);

            auto t_zzz_zzz = primBuffer.data(100 * idx + 99);

            // Batch of Integrals (90,100)

            #pragma omp simd aligned(fx, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     pc_x, pc_xx, pc_xxx, pc_xxxz, pc_xxxzz, pc_xxxzzz, pc_xxy, pc_xxyz, pc_xxyzz, \
                                     pc_xxyzzz, pc_xxz, pc_xxzz, pc_xxzzz, pc_xxzzzz, pc_xy, pc_xyy, pc_xyyz, pc_xyyzz, \
                                     pc_xyyzzz, pc_xyz, pc_xyzz, pc_xyzzz, pc_xyzzzz, pc_xz, pc_xzz, pc_xzzz, pc_xzzzz, \
                                     pc_xzzzzz, pc_y, pc_yy, pc_yyy, pc_yyyz, pc_yyyzz, pc_yyyzzz, pc_yyz, pc_yyzz, pc_yyzzz, \
                                     pc_yyzzzz, pc_yz, pc_yzz, pc_yzzz, pc_yzzzz, pc_yzzzzz, pc_z, pc_zz, pc_zzz, pc_zzzz, \
                                     pc_zzzzz, pc_zzzzzz, s_0_0_0, s_0_0_1, s_0_0_2, s_0_0_3, s_0_0_4, s_0_0_5, s_0_0_6, \
                                     t_zzz_xxx, t_zzz_xxy, t_zzz_xxz, t_zzz_xyy, t_zzz_xyz, t_zzz_xzz, t_zzz_yyy, \
                                     t_zzz_yyz, t_zzz_yzz, t_zzz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_s_0_0_0 = s_0_0_0[j];

                double fl_s_0_0_1 = s_0_0_1[j];

                double fl_s_0_0_2 = s_0_0_2[j];

                double fl_s_0_0_3 = s_0_0_3[j];

                double fl_s_0_0_4 = s_0_0_4[j];

                double fl_s_0_0_5 = s_0_0_5[j];

                double fl_s_0_0_6 = s_0_0_6[j];

                double fl1_fx = fx[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_zzz_xxx[j] = fl_s_0_0_0 * (2.25 * pa_z[j] * fl2_fx * pb_x[j] + 1.5 * pa_zzz[j] * pb_x[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_xxx[j] + pa_zzz[j] * pb_xxx[j]);

                t_zzz_xxx[j] += fl_s_0_0_1 * (-4.5 * pa_z[j] * fl2_fx * pb_x[j] - 2.25 * pa_z[j] * fl2_fx * pc_x[j] - 2.25 * pc_z[j] * fl2_fx * pb_x[j] - 1.5 * pa_zzz[j] * pb_x[j] * fl1_fx - 1.5 * pa_zzz[j] * pc_x[j] * fl1_fx - 4.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx - 4.5 * pa_z[j] * fl1_fx * pb_xx[j] * pc_x[j] - 1.5 * pa_z[j] * fl1_fx * pb_xxx[j] - 1.5 * pc_z[j] * fl1_fx * pb_xxx[j] - 3.0 * pa_zzz[j] * pb_xx[j] * pc_x[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xxx[j]);

                t_zzz_xxx[j] += fl_s_0_0_2 * (4.5 * pa_z[j] * fl2_fx * pc_x[j] + 2.25 * pa_z[j] * fl2_fx * pb_x[j] + 4.5 * pc_z[j] * fl2_fx * pb_x[j] + 2.25 * pc_xz[j] * fl2_fx + 1.5 * pa_zzz[j] * pc_x[j] * fl1_fx + 4.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx + 4.5 * pa_zz[j] * pc_xz[j] * fl1_fx + 4.5 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx + 4.5 * pa_z[j] * fl1_fx * pb_x[j] * pc_xx[j] + 4.5 * pa_z[j] * fl1_fx * pb_xx[j] * pc_x[j] + 4.5 * pc_xz[j] * fl1_fx * pb_xx[j] + 1.5 * pc_z[j] * fl1_fx * pb_xxx[j] + 3.0 * pa_zzz[j] * pb_x[j] * pc_xx[j] + 9.0 * pa_zz[j] * pc_xz[j] * pb_xx[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xxx[j]);

                t_zzz_xxx[j] += fl_s_0_0_3 * (-2.25 * pa_z[j] * fl2_fx * pc_x[j] - 4.5 * pc_xz[j] * fl2_fx - 2.25 * pc_z[j] * fl2_fx * pb_x[j] - 4.5 * pa_zz[j] * pc_xz[j] * fl1_fx - 4.5 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx - 4.5 * pa_z[j] * pc_xzz[j] * fl1_fx - 1.5 * pc_zzz[j] * pb_x[j] * fl1_fx - 1.5 * pa_z[j] * fl1_fx * pc_xxx[j] - 4.5 * pa_z[j] * fl1_fx * pb_x[j] * pc_xx[j] - 4.5 * pc_xxz[j] * fl1_fx * pb_x[j] - 4.5 * pc_xz[j] * fl1_fx * pb_xx[j] - pa_zzz[j] * pc_xxx[j] - 9.0 * pa_zz[j] * pc_xxz[j] * pb_x[j] - 9.0 * pa_z[j] * pc_xzz[j] * pb_xx[j] - pc_zzz[j] * pb_xxx[j]);

                t_zzz_xxx[j] += fl_s_0_0_4 * (2.25 * pc_xz[j] * fl2_fx + 4.5 * pa_z[j] * pc_xzz[j] * fl1_fx + 1.5 * pc_zzz[j] * pb_x[j] * fl1_fx + 1.5 * pc_xzzz[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pc_xxx[j] + 1.5 * pc_xxxz[j] * fl1_fx + 4.5 * pc_xxz[j] * fl1_fx * pb_x[j] + 3.0 * pa_zz[j] * pc_xxxz[j] + 9.0 * pa_z[j] * pc_xxzz[j] * pb_x[j] + 3.0 * pc_xzzz[j] * pb_xx[j]);

                t_zzz_xxx[j] += fl_s_0_0_5 * (-1.5 * pc_xzzz[j] * fl1_fx - 1.5 * pc_xxxz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xxxzz[j] - 3.0 * pc_xxzzz[j] * pb_x[j]);

                t_zzz_xxx[j] += fl_s_0_0_6 * pc_xxxzzz[j];

                t_zzz_xxy[j] = fl_s_0_0_0 * (0.75 * pa_z[j] * fl2_fx * pb_y[j] + 0.5 * pa_zzz[j] * fl1_fx * pb_y[j] + 1.5 * pa_z[j] * fl1_fx * pb_xxy[j] + pa_zzz[j] * pb_xxy[j]);

                t_zzz_xxy[j] += fl_s_0_0_1 * (-0.75 * pa_z[j] * fl2_fx * pc_y[j] - 1.5 * pa_z[j] * fl2_fx * pb_y[j] - 0.75 * pc_z[j] * fl2_fx * pb_y[j] - 0.5 * pa_zzz[j] * fl1_fx * pc_y[j] - 0.5 * pa_zzz[j] * fl1_fx * pb_y[j] - 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_y[j] - 1.5 * pa_z[j] * fl1_fx * pb_xx[j] * pc_y[j] - 3.0 * pa_z[j] * fl1_fx * pb_xy[j] * pc_x[j] - 1.5 * pa_z[j] * fl1_fx * pb_xxy[j] - 1.5 * pc_z[j] * fl1_fx * pb_xxy[j] - pa_zzz[j] * pb_xx[j] * pc_y[j] - 2.0 * pa_zzz[j] * pb_xy[j] * pc_x[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xxy[j]);

                t_zzz_xxy[j] += fl_s_0_0_2 * (1.5 * pa_z[j] * fl2_fx * pc_y[j] + 0.75 * pa_z[j] * fl2_fx * pb_y[j] + 0.75 * pc_yz[j] * fl2_fx + 1.5 * pc_z[j] * fl2_fx * pb_y[j] + 0.5 * pa_zzz[j] * fl1_fx * pc_y[j] + 1.5 * pa_zz[j] * pc_yz[j] * fl1_fx + 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_y[j] + 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_y[j] + 3.0 * pa_z[j] * fl1_fx * pb_x[j] * pc_xy[j] + 1.5 * pa_z[j] * fl1_fx * pc_xx[j] * pb_y[j] + 1.5 * pa_z[j] * fl1_fx * pb_xx[j] * pc_y[j] + 3.0 * pa_z[j] * fl1_fx * pb_xy[j] * pc_x[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xy[j] + 1.5 * pc_z[j] * fl1_fx * pb_xxy[j] + 2.0 * pa_zzz[j] * pb_x[j] * pc_xy[j] + pa_zzz[j] * pc_xx[j] * pb_y[j] + 3.0 * pa_zz[j] * pc_yz[j] * pb_xx[j] + 6.0 * pa_zz[j] * pc_xz[j] * pb_xy[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xxy[j]);

                t_zzz_xxy[j] += fl_s_0_0_3 * (-0.75 * pa_z[j] * fl2_fx * pc_y[j] - 1.5 * pc_yz[j] * fl2_fx - 0.75 * pc_z[j] * fl2_fx * pb_y[j] - 1.5 * pa_zz[j] * pc_yz[j] * fl1_fx - 1.5 * pa_z[j] * pc_yzz[j] * fl1_fx - 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_y[j] - 0.5 * pc_zzz[j] * fl1_fx * pb_y[j] - 1.5 * pa_z[j] * fl1_fx * pc_xxy[j] - 3.0 * pa_z[j] * fl1_fx * pb_x[j] * pc_xy[j] - 1.5 * pa_z[j] * fl1_fx * pc_xx[j] * pb_y[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] - 1.5 * pc_xxz[j] * fl1_fx * pb_y[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xx[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xy[j] - pa_zzz[j] * pc_xxy[j] - 6.0 * pa_zz[j] * pc_xyz[j] * pb_x[j] - 3.0 * pa_zz[j] * pc_xxz[j] * pb_y[j] - 3.0 * pa_z[j] * pc_yzz[j] * pb_xx[j] - 6.0 * pa_z[j] * pc_xzz[j] * pb_xy[j] - pc_zzz[j] * pb_xxy[j]);

                t_zzz_xxy[j] += fl_s_0_0_4 * (0.75 * pc_yz[j] * fl2_fx + 1.5 * pa_z[j] * pc_yzz[j] * fl1_fx + 0.5 * pc_yzzz[j] * fl1_fx + 0.5 * pc_zzz[j] * fl1_fx * pb_y[j] + 1.5 * pa_z[j] * fl1_fx * pc_xxy[j] + 1.5 * pc_xxyz[j] * fl1_fx + 3.0 * pc_xyz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxz[j] * fl1_fx * pb_y[j] + 3.0 * pa_zz[j] * pc_xxyz[j] + 6.0 * pa_z[j] * pc_xyzz[j] * pb_x[j] + 3.0 * pa_z[j] * pc_xxzz[j] * pb_y[j] + pc_yzzz[j] * pb_xx[j] + 2.0 * pc_xzzz[j] * pb_xy[j]);

                t_zzz_xxy[j] += fl_s_0_0_5 * (-0.5 * pc_yzzz[j] * fl1_fx - 1.5 * pc_xxyz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xxyzz[j] - 2.0 * pc_xyzzz[j] * pb_x[j] - pc_xxzzz[j] * pb_y[j]);

                t_zzz_xxy[j] += fl_s_0_0_6 * pc_xxyzzz[j];

                t_zzz_xxz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 0.75 * pa_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_xx[j] + 0.5 * pa_zzz[j] * fl1_fx * pb_z[j] + 1.5 * pa_zz[j] * fl1_fx * pb_xx[j] + 1.5 * pa_z[j] * fl1_fx * pb_xxz[j] + pa_zzz[j] * pb_xxz[j]);

                t_zzz_xxz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_zz[j] * fl2_fx - 2.25 * pa_z[j] * pc_z[j] * fl2_fx - 1.5 * pa_z[j] * fl2_fx * pb_z[j] - 0.75 * pc_z[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_x[j] * pc_x[j] - 1.5 * fl2_fx * pb_xx[j] - 0.5 * pa_zzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_zzz[j] * fl1_fx * pb_z[j] - 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_z[j] - 3.0 * pa_zz[j] * fl1_fx * pb_x[j] * pc_x[j] - 1.5 * pa_zz[j] * fl1_fx * pb_xx[j] - 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_xx[j] - 3.0 * pa_z[j] * fl1_fx * pb_xz[j] * pc_x[j] - 1.5 * pa_z[j] * fl1_fx * pb_xxz[j] - 1.5 * pc_z[j] * fl1_fx * pb_xxz[j] - pa_zzz[j] * pb_xx[j] * pc_z[j] - 2.0 * pa_zzz[j] * pb_xz[j] * pc_x[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xxz[j]);

                t_zzz_xxz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 4.5 * pa_z[j] * pc_z[j] * fl2_fx + 1.5 * pc_zz[j] * fl2_fx + 0.75 * pa_z[j] * fl2_fx * pb_z[j] + 1.5 * pc_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pc_xx[j] + 3.0 * fl2_fx * pb_x[j] * pc_x[j] + 0.75 * fl2_fx * pb_xx[j] + 0.5 * pa_zzz[j] * fl1_fx * pc_z[j] + 1.5 * pa_zz[j] * pc_zz[j] * fl1_fx + 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_z[j] + 1.5 * pa_zz[j] * fl1_fx * pc_xx[j] + 3.0 * pa_zz[j] * fl1_fx * pb_x[j] * pc_x[j] + 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_z[j] + 9.0 * pa_z[j] * pc_xz[j] * fl1_fx * pb_x[j] + 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_xx[j] + 3.0 * pc_zz[j] * fl1_fx * pb_xx[j] + 1.5 * pa_z[j] * fl1_fx * pc_xx[j] * pb_z[j] + 3.0 * pa_z[j] * fl1_fx * pb_xz[j] * pc_x[j] + 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] + 1.5 * pc_z[j] * fl1_fx * pb_xxz[j] + 2.0 * pa_zzz[j] * pb_x[j] * pc_xz[j] + pa_zzz[j] * pc_xx[j] * pb_z[j] + 3.0 * pa_zz[j] * pc_zz[j] * pb_xx[j] + 6.0 * pa_zz[j] * pc_xz[j] * pb_xz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xxz[j]);

                t_zzz_xxz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_z[j] * pc_z[j] * fl2_fx - 3.0 * pc_zz[j] * fl2_fx - 0.75 * pc_z[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pc_xx[j] - 1.5 * fl2_fx * pb_x[j] * pc_x[j] - 1.5 * pa_zz[j] * pc_zz[j] * fl1_fx - 1.5 * pa_zz[j] * fl1_fx * pc_xx[j] - 1.5 * pa_z[j] * pc_zzz[j] * fl1_fx - 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_z[j] - 4.5 * pa_z[j] * pc_xxz[j] * fl1_fx - 9.0 * pa_z[j] * pc_xz[j] * fl1_fx * pb_x[j] - 0.5 * pc_zzz[j] * fl1_fx * pb_z[j] - 6.0 * pc_xzz[j] * fl1_fx * pb_x[j] - 3.0 * pc_zz[j] * fl1_fx * pb_xx[j] - 1.5 * pa_z[j] * fl1_fx * pc_xx[j] * pb_z[j] - 1.5 * pc_xxz[j] * fl1_fx * pb_z[j] - 3.0 * pc_xz[j] * fl1_fx * pb_xz[j] - pa_zzz[j] * pc_xxz[j] - 6.0 * pa_zz[j] * pc_xzz[j] * pb_x[j] - 3.0 * pa_zz[j] * pc_xxz[j] * pb_z[j] - 3.0 * pa_z[j] * pc_zzz[j] * pb_xx[j] - 6.0 * pa_z[j] * pc_xzz[j] * pb_xz[j] - pc_zzz[j] * pb_xxz[j]);

                t_zzz_xxz[j] += fl_s_0_0_4 * (1.5 * pc_zz[j] * fl2_fx + 0.75 * fl2_fx * pc_xx[j] + 1.5 * pa_z[j] * pc_zzz[j] * fl1_fx + 4.5 * pa_z[j] * pc_xxz[j] * fl1_fx + 0.5 * pc_zzzz[j] * fl1_fx + 0.5 * pc_zzz[j] * fl1_fx * pb_z[j] + 3.0 * pc_xxzz[j] * fl1_fx + 6.0 * pc_xzz[j] * fl1_fx * pb_x[j] + 1.5 * pc_xxz[j] * fl1_fx * pb_z[j] + 3.0 * pa_zz[j] * pc_xxzz[j] + 6.0 * pa_z[j] * pc_xzzz[j] * pb_x[j] + 3.0 * pa_z[j] * pc_xxzz[j] * pb_z[j] + pc_zzzz[j] * pb_xx[j] + 2.0 * pc_xzzz[j] * pb_xz[j]);

                t_zzz_xxz[j] += fl_s_0_0_5 * (-0.5 * pc_zzzz[j] * fl1_fx - 3.0 * pc_xxzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xxzzz[j] - 2.0 * pc_xzzzz[j] * pb_x[j] - pc_xxzzz[j] * pb_z[j]);

                t_zzz_xxz[j] += fl_s_0_0_6 * pc_xxzzzz[j];

                t_zzz_xyy[j] = fl_s_0_0_0 * (0.75 * pa_z[j] * fl2_fx * pb_x[j] + 0.5 * pa_zzz[j] * pb_x[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_xyy[j] + pa_zzz[j] * pb_xyy[j]);

                t_zzz_xyy[j] += fl_s_0_0_1 * (-1.5 * pa_z[j] * fl2_fx * pb_x[j] - 0.75 * pa_z[j] * fl2_fx * pc_x[j] - 0.75 * pc_z[j] * fl2_fx * pb_x[j] - 0.5 * pa_zzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_zzz[j] * pc_x[j] * fl1_fx - 1.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx - 3.0 * pa_z[j] * fl1_fx * pb_xy[j] * pc_y[j] - 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_yy[j] - 1.5 * pa_z[j] * fl1_fx * pb_xyy[j] - 1.5 * pc_z[j] * fl1_fx * pb_xyy[j] - 2.0 * pa_zzz[j] * pb_xy[j] * pc_y[j] - pa_zzz[j] * pc_x[j] * pb_yy[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xyy[j]);

                t_zzz_xyy[j] += fl_s_0_0_2 * (1.5 * pa_z[j] * fl2_fx * pc_x[j] + 0.75 * pa_z[j] * fl2_fx * pb_x[j] + 1.5 * pc_z[j] * fl2_fx * pb_x[j] + 0.75 * pc_xz[j] * fl2_fx + 0.5 * pa_zzz[j] * pc_x[j] * fl1_fx + 1.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx + 1.5 * pa_zz[j] * pc_xz[j] * fl1_fx + 1.5 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_x[j] * pc_yy[j] + 3.0 * pa_z[j] * fl1_fx * pc_xy[j] * pb_y[j] + 3.0 * pa_z[j] * fl1_fx * pb_xy[j] * pc_y[j] + 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_yy[j] + 3.0 * pc_yz[j] * fl1_fx * pb_xy[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] + 1.5 * pc_z[j] * fl1_fx * pb_xyy[j] + pa_zzz[j] * pb_x[j] * pc_yy[j] + 2.0 * pa_zzz[j] * pc_xy[j] * pb_y[j] + 6.0 * pa_zz[j] * pc_yz[j] * pb_xy[j] + 3.0 * pa_zz[j] * pc_xz[j] * pb_yy[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xyy[j]);

                t_zzz_xyy[j] += fl_s_0_0_3 * (-0.75 * pa_z[j] * fl2_fx * pc_x[j] - 1.5 * pc_xz[j] * fl2_fx - 0.75 * pc_z[j] * fl2_fx * pb_x[j] - 1.5 * pa_zz[j] * pc_xz[j] * fl1_fx - 1.5 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx - 1.5 * pa_z[j] * pc_xzz[j] * fl1_fx - 0.5 * pc_zzz[j] * pb_x[j] * fl1_fx - 1.5 * pa_z[j] * fl1_fx * pc_xyy[j] - 1.5 * pa_z[j] * fl1_fx * pb_x[j] * pc_yy[j] - 3.0 * pa_z[j] * fl1_fx * pc_xy[j] * pb_y[j] - 1.5 * pc_yyz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] - 3.0 * pc_yz[j] * fl1_fx * pb_xy[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yy[j] - pa_zzz[j] * pc_xyy[j] - 3.0 * pa_zz[j] * pc_yyz[j] * pb_x[j] - 6.0 * pa_zz[j] * pc_xyz[j] * pb_y[j] - 6.0 * pa_z[j] * pc_yzz[j] * pb_xy[j] - 3.0 * pa_z[j] * pc_xzz[j] * pb_yy[j] - pc_zzz[j] * pb_xyy[j]);

                t_zzz_xyy[j] += fl_s_0_0_4 * (0.75 * pc_xz[j] * fl2_fx + 1.5 * pa_z[j] * pc_xzz[j] * fl1_fx + 0.5 * pc_zzz[j] * pb_x[j] * fl1_fx + 0.5 * pc_xzzz[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pc_xyy[j] + 1.5 * pc_xyyz[j] * fl1_fx + 1.5 * pc_yyz[j] * fl1_fx * pb_x[j] + 3.0 * pc_xyz[j] * fl1_fx * pb_y[j] + 3.0 * pa_zz[j] * pc_xyyz[j] + 3.0 * pa_z[j] * pc_yyzz[j] * pb_x[j] + 6.0 * pa_z[j] * pc_xyzz[j] * pb_y[j] + 2.0 * pc_yzzz[j] * pb_xy[j] + pc_xzzz[j] * pb_yy[j]);

                t_zzz_xyy[j] += fl_s_0_0_5 * (-0.5 * pc_xzzz[j] * fl1_fx - 1.5 * pc_xyyz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xyyzz[j] - pc_yyzzz[j] * pb_x[j] - 2.0 * pc_xyzzz[j] * pb_y[j]);

                t_zzz_xyy[j] += fl_s_0_0_6 * pc_xyyzzz[j];

                t_zzz_xyz[j] = fl_s_0_0_0 * (0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_zz[j] * fl1_fx * pb_xy[j] + 1.5 * pa_z[j] * fl1_fx * pb_xyz[j] + pa_zzz[j] * pb_xyz[j]);

                t_zzz_xyz[j] += fl_s_0_0_1 * (-0.75 * fl2_fx * pb_x[j] * pc_y[j] - 0.75 * fl2_fx * pc_x[j] * pb_y[j] - 1.5 * fl2_fx * pb_xy[j] - 1.5 * pa_zz[j] * fl1_fx * pb_x[j] * pc_y[j] - 1.5 * pa_zz[j] * fl1_fx * pc_x[j] * pb_y[j] - 1.5 * pa_zz[j] * fl1_fx * pb_xy[j] - 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_xy[j] - 1.5 * pa_z[j] * fl1_fx * pb_xz[j] * pc_y[j] - 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_yz[j] - 1.5 * pa_z[j] * fl1_fx * pb_xyz[j] - 1.5 * pc_z[j] * fl1_fx * pb_xyz[j] - pa_zzz[j] * pb_xy[j] * pc_z[j] - pa_zzz[j] * pb_xz[j] * pc_y[j] - pa_zzz[j] * pc_x[j] * pb_yz[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xyz[j]);

                t_zzz_xyz[j] += fl_s_0_0_2 * (0.75 * fl2_fx * pc_xy[j] + 1.5 * fl2_fx * pb_x[j] * pc_y[j] + 1.5 * fl2_fx * pc_x[j] * pb_y[j] + 0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_zz[j] * fl1_fx * pc_xy[j] + 1.5 * pa_zz[j] * fl1_fx * pb_x[j] * pc_y[j] + 1.5 * pa_zz[j] * fl1_fx * pc_x[j] * pb_y[j] + 4.5 * pa_z[j] * pc_yz[j] * fl1_fx * pb_x[j] + 4.5 * pa_z[j] * pc_xz[j] * fl1_fx * pb_y[j] + 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_xy[j] + 3.0 * pc_zz[j] * fl1_fx * pb_xy[j] + 1.5 * pa_z[j] * fl1_fx * pc_xy[j] * pb_z[j] + 1.5 * pa_z[j] * fl1_fx * pb_xz[j] * pc_y[j] + 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_yz[j] + 1.5 * pc_yz[j] * fl1_fx * pb_xz[j] + 1.5 * pc_xz[j] * fl1_fx * pb_yz[j] + 1.5 * pc_z[j] * fl1_fx * pb_xyz[j] + pa_zzz[j] * pb_x[j] * pc_yz[j] + pa_zzz[j] * pc_xz[j] * pb_y[j] + pa_zzz[j] * pc_xy[j] * pb_z[j] + 3.0 * pa_zz[j] * pc_zz[j] * pb_xy[j] + 3.0 * pa_zz[j] * pc_yz[j] * pb_xz[j] + 3.0 * pa_zz[j] * pc_xz[j] * pb_yz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xyz[j]);

                t_zzz_xyz[j] += fl_s_0_0_3 * (-1.5 * fl2_fx * pc_xy[j] - 0.75 * fl2_fx * pb_x[j] * pc_y[j] - 0.75 * fl2_fx * pc_x[j] * pb_y[j] - 1.5 * pa_zz[j] * fl1_fx * pc_xy[j] - 4.5 * pa_z[j] * pc_xyz[j] * fl1_fx - 4.5 * pa_z[j] * pc_yz[j] * fl1_fx * pb_x[j] - 4.5 * pa_z[j] * pc_xz[j] * fl1_fx * pb_y[j] - 3.0 * pc_yzz[j] * fl1_fx * pb_x[j] - 3.0 * pc_xzz[j] * fl1_fx * pb_y[j] - 3.0 * pc_zz[j] * fl1_fx * pb_xy[j] - 1.5 * pa_z[j] * fl1_fx * pc_xy[j] * pb_z[j] - 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] - 1.5 * pc_yz[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xz[j] * fl1_fx * pb_yz[j] - pa_zzz[j] * pc_xyz[j] - 3.0 * pa_zz[j] * pc_yzz[j] * pb_x[j] - 3.0 * pa_zz[j] * pc_xzz[j] * pb_y[j] - 3.0 * pa_zz[j] * pc_xyz[j] * pb_z[j] - 3.0 * pa_z[j] * pc_zzz[j] * pb_xy[j] - 3.0 * pa_z[j] * pc_yzz[j] * pb_xz[j] - 3.0 * pa_z[j] * pc_xzz[j] * pb_yz[j] - pc_zzz[j] * pb_xyz[j]);

                t_zzz_xyz[j] += fl_s_0_0_4 * (0.75 * fl2_fx * pc_xy[j] + 4.5 * pa_z[j] * pc_xyz[j] * fl1_fx + 3.0 * pc_xyzz[j] * fl1_fx + 3.0 * pc_yzz[j] * fl1_fx * pb_x[j] + 3.0 * pc_xzz[j] * fl1_fx * pb_y[j] + 1.5 * pc_xyz[j] * fl1_fx * pb_z[j] + 3.0 * pa_zz[j] * pc_xyzz[j] + 3.0 * pa_z[j] * pc_yzzz[j] * pb_x[j] + 3.0 * pa_z[j] * pc_xzzz[j] * pb_y[j] + 3.0 * pa_z[j] * pc_xyzz[j] * pb_z[j] + pc_zzzz[j] * pb_xy[j] + pc_yzzz[j] * pb_xz[j] + pc_xzzz[j] * pb_yz[j]);

                t_zzz_xyz[j] += fl_s_0_0_5 * (-3.0 * pc_xyzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xyzzz[j] - pc_yzzzz[j] * pb_x[j] - pc_xzzzz[j] * pb_y[j] - pc_xyzzz[j] * pb_z[j]);

                t_zzz_xyz[j] += fl_s_0_0_6 * pc_xyzzzz[j];

                t_zzz_xzz[j] = fl_s_0_0_0 * (2.25 * pa_z[j] * fl2_fx * pb_x[j] + 1.5 * fl2_fx * pb_xz[j] + 0.5 * pa_zzz[j] * pb_x[j] * fl1_fx + 3.0 * pa_zz[j] * fl1_fx * pb_xz[j] + 1.5 * pa_z[j] * fl1_fx * pb_xzz[j] + pa_zzz[j] * pb_xzz[j]);

                t_zzz_xzz[j] += fl_s_0_0_1 * (-2.25 * pa_z[j] * fl2_fx * pc_x[j] - 4.5 * pa_z[j] * fl2_fx * pb_x[j] - 3.75 * pc_z[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_x[j] * pb_z[j] - 3.0 * fl2_fx * pb_xz[j] - 0.5 * pa_zzz[j] * pb_x[j] * fl1_fx - 0.5 * pa_zzz[j] * pc_x[j] * fl1_fx - 4.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx - 3.0 * pa_zz[j] * fl1_fx * pc_x[j] * pb_z[j] - 3.0 * pa_zz[j] * fl1_fx * pb_xz[j] - 9.0 * pa_z[j] * pc_z[j] * fl1_fx * pb_xz[j] - 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_zz[j] - 1.5 * pa_z[j] * fl1_fx * pb_xzz[j] - 1.5 * pc_z[j] * fl1_fx * pb_xzz[j] - 2.0 * pa_zzz[j] * pb_xz[j] * pc_z[j] - pa_zzz[j] * pc_x[j] * pb_zz[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_xzz[j]);

                t_zzz_xzz[j] += fl_s_0_0_2 * (4.5 * pa_z[j] * fl2_fx * pc_x[j] + 2.25 * pa_z[j] * fl2_fx * pb_x[j] + 3.75 * pc_xz[j] * fl2_fx + 7.5 * pc_z[j] * fl2_fx * pb_x[j] + 3.0 * fl2_fx * pc_x[j] * pb_z[j] + 1.5 * fl2_fx * pb_xz[j] + 0.5 * pa_zzz[j] * pc_x[j] * fl1_fx + 4.5 * pa_zz[j] * pc_z[j] * pb_x[j] * fl1_fx + 4.5 * pa_zz[j] * pc_xz[j] * fl1_fx + 3.0 * pa_zz[j] * fl1_fx * pc_x[j] * pb_z[j] + 9.0 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx + 9.0 * pa_z[j] * pc_xz[j] * fl1_fx * pb_z[j] + 9.0 * pa_z[j] * pc_z[j] * fl1_fx * pb_xz[j] + 6.0 * pc_zz[j] * fl1_fx * pb_xz[j] + 1.5 * pa_z[j] * fl1_fx * pc_x[j] * pb_zz[j] + 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_z[j] * fl1_fx * pb_xzz[j] + pa_zzz[j] * pb_x[j] * pc_zz[j] + 2.0 * pa_zzz[j] * pc_xz[j] * pb_z[j] + 6.0 * pa_zz[j] * pc_zz[j] * pb_xz[j] + 3.0 * pa_zz[j] * pc_xz[j] * pb_zz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_xzz[j]);

                t_zzz_xzz[j] += fl_s_0_0_3 * (-2.25 * pa_z[j] * fl2_fx * pc_x[j] - 7.5 * pc_xz[j] * fl2_fx - 3.75 * pc_z[j] * fl2_fx * pb_x[j] - 1.5 * fl2_fx * pc_x[j] * pb_z[j] - 4.5 * pa_zz[j] * pc_xz[j] * fl1_fx - 9.0 * pa_z[j] * pc_zz[j] * pb_x[j] * fl1_fx - 9.0 * pa_z[j] * pc_xzz[j] * fl1_fx - 9.0 * pa_z[j] * pc_xz[j] * fl1_fx * pb_z[j] - 5.0 * pc_zzz[j] * pb_x[j] * fl1_fx - 6.0 * pc_xzz[j] * fl1_fx * pb_z[j] - 6.0 * pc_zz[j] * fl1_fx * pb_xz[j] - 1.5 * pc_xz[j] * fl1_fx * pb_zz[j] - pa_zzz[j] * pc_xzz[j] - 3.0 * pa_zz[j] * pc_zzz[j] * pb_x[j] - 6.0 * pa_zz[j] * pc_xzz[j] * pb_z[j] - 6.0 * pa_z[j] * pc_zzz[j] * pb_xz[j] - 3.0 * pa_z[j] * pc_xzz[j] * pb_zz[j] - pc_zzz[j] * pb_xzz[j]);

                t_zzz_xzz[j] += fl_s_0_0_4 * (3.75 * pc_xz[j] * fl2_fx + 9.0 * pa_z[j] * pc_xzz[j] * fl1_fx + 5.0 * pc_zzz[j] * pb_x[j] * fl1_fx + 5.0 * pc_xzzz[j] * fl1_fx + 6.0 * pc_xzz[j] * fl1_fx * pb_z[j] + 3.0 * pa_zz[j] * pc_xzzz[j] + 3.0 * pa_z[j] * pc_zzzz[j] * pb_x[j] + 6.0 * pa_z[j] * pc_xzzz[j] * pb_z[j] + 2.0 * pc_zzzz[j] * pb_xz[j] + pc_xzzz[j] * pb_zz[j]);

                t_zzz_xzz[j] += fl_s_0_0_5 * (-5.0 * pc_xzzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_xzzzz[j] - pc_zzzzz[j] * pb_x[j] - 2.0 * pc_xzzzz[j] * pb_z[j]);

                t_zzz_xzz[j] += fl_s_0_0_6 * pc_xzzzzz[j];

                t_zzz_yyy[j] = fl_s_0_0_0 * (2.25 * pa_z[j] * fl2_fx * pb_y[j] + 1.5 * pa_zzz[j] * pb_y[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_yyy[j] + pa_zzz[j] * pb_yyy[j]);

                t_zzz_yyy[j] += fl_s_0_0_1 * (-4.5 * pa_z[j] * fl2_fx * pb_y[j] - 2.25 * pa_z[j] * fl2_fx * pc_y[j] - 2.25 * pc_z[j] * fl2_fx * pb_y[j] - 1.5 * pa_zzz[j] * pb_y[j] * fl1_fx - 1.5 * pa_zzz[j] * pc_y[j] * fl1_fx - 4.5 * pa_zz[j] * pc_z[j] * pb_y[j] * fl1_fx - 4.5 * pa_z[j] * fl1_fx * pb_yy[j] * pc_y[j] - 1.5 * pa_z[j] * fl1_fx * pb_yyy[j] - 1.5 * pc_z[j] * fl1_fx * pb_yyy[j] - 3.0 * pa_zzz[j] * pb_yy[j] * pc_y[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_yyy[j]);

                t_zzz_yyy[j] += fl_s_0_0_2 * (4.5 * pa_z[j] * fl2_fx * pc_y[j] + 2.25 * pa_z[j] * fl2_fx * pb_y[j] + 4.5 * pc_z[j] * fl2_fx * pb_y[j] + 2.25 * pc_yz[j] * fl2_fx + 1.5 * pa_zzz[j] * pc_y[j] * fl1_fx + 4.5 * pa_zz[j] * pc_z[j] * pb_y[j] * fl1_fx + 4.5 * pa_zz[j] * pc_yz[j] * fl1_fx + 4.5 * pa_z[j] * pc_zz[j] * pb_y[j] * fl1_fx + 4.5 * pa_z[j] * fl1_fx * pb_y[j] * pc_yy[j] + 4.5 * pa_z[j] * fl1_fx * pb_yy[j] * pc_y[j] + 4.5 * pc_yz[j] * fl1_fx * pb_yy[j] + 1.5 * pc_z[j] * fl1_fx * pb_yyy[j] + 3.0 * pa_zzz[j] * pb_y[j] * pc_yy[j] + 9.0 * pa_zz[j] * pc_yz[j] * pb_yy[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_yyy[j]);

                t_zzz_yyy[j] += fl_s_0_0_3 * (-2.25 * pa_z[j] * fl2_fx * pc_y[j] - 4.5 * pc_yz[j] * fl2_fx - 2.25 * pc_z[j] * fl2_fx * pb_y[j] - 4.5 * pa_zz[j] * pc_yz[j] * fl1_fx - 4.5 * pa_z[j] * pc_zz[j] * pb_y[j] * fl1_fx - 4.5 * pa_z[j] * pc_yzz[j] * fl1_fx - 1.5 * pc_zzz[j] * pb_y[j] * fl1_fx - 1.5 * pa_z[j] * fl1_fx * pc_yyy[j] - 4.5 * pa_z[j] * fl1_fx * pb_y[j] * pc_yy[j] - 4.5 * pc_yyz[j] * fl1_fx * pb_y[j] - 4.5 * pc_yz[j] * fl1_fx * pb_yy[j] - pa_zzz[j] * pc_yyy[j] - 9.0 * pa_zz[j] * pc_yyz[j] * pb_y[j] - 9.0 * pa_z[j] * pc_yzz[j] * pb_yy[j] - pc_zzz[j] * pb_yyy[j]);

                t_zzz_yyy[j] += fl_s_0_0_4 * (2.25 * pc_yz[j] * fl2_fx + 4.5 * pa_z[j] * pc_yzz[j] * fl1_fx + 1.5 * pc_zzz[j] * pb_y[j] * fl1_fx + 1.5 * pc_yzzz[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pc_yyy[j] + 1.5 * pc_yyyz[j] * fl1_fx + 4.5 * pc_yyz[j] * fl1_fx * pb_y[j] + 3.0 * pa_zz[j] * pc_yyyz[j] + 9.0 * pa_z[j] * pc_yyzz[j] * pb_y[j] + 3.0 * pc_yzzz[j] * pb_yy[j]);

                t_zzz_yyy[j] += fl_s_0_0_5 * (-1.5 * pc_yzzz[j] * fl1_fx - 1.5 * pc_yyyz[j] * fl1_fx - 3.0 * pa_z[j] * pc_yyyzz[j] - 3.0 * pc_yyzzz[j] * pb_y[j]);

                t_zzz_yyy[j] += fl_s_0_0_6 * pc_yyyzzz[j];

                t_zzz_yyz[j] = fl_s_0_0_0 * (0.375 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 0.75 * pa_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_yy[j] + 0.5 * pa_zzz[j] * fl1_fx * pb_z[j] + 1.5 * pa_zz[j] * fl1_fx * pb_yy[j] + 1.5 * pa_z[j] * fl1_fx * pb_yyz[j] + pa_zzz[j] * pb_yyz[j]);

                t_zzz_yyz[j] += fl_s_0_0_1 * (-1.125 * fl3_fx - 1.5 * pa_zz[j] * fl2_fx - 2.25 * pa_z[j] * pc_z[j] * fl2_fx - 1.5 * pa_z[j] * fl2_fx * pb_z[j] - 0.75 * pc_z[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pb_y[j] * pc_y[j] - 1.5 * fl2_fx * pb_yy[j] - 0.5 * pa_zzz[j] * fl1_fx * pc_z[j] - 0.5 * pa_zzz[j] * fl1_fx * pb_z[j] - 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_z[j] - 3.0 * pa_zz[j] * fl1_fx * pb_y[j] * pc_y[j] - 1.5 * pa_zz[j] * fl1_fx * pb_yy[j] - 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_yy[j] - 3.0 * pa_z[j] * fl1_fx * pb_yz[j] * pc_y[j] - 1.5 * pa_z[j] * fl1_fx * pb_yyz[j] - 1.5 * pc_z[j] * fl1_fx * pb_yyz[j] - pa_zzz[j] * pb_yy[j] * pc_z[j] - 2.0 * pa_zzz[j] * pb_yz[j] * pc_y[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_yyz[j]);

                t_zzz_yyz[j] += fl_s_0_0_2 * (1.125 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 4.5 * pa_z[j] * pc_z[j] * fl2_fx + 1.5 * pc_zz[j] * fl2_fx + 0.75 * pa_z[j] * fl2_fx * pb_z[j] + 1.5 * pc_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pc_yy[j] + 3.0 * fl2_fx * pb_y[j] * pc_y[j] + 0.75 * fl2_fx * pb_yy[j] + 0.5 * pa_zzz[j] * fl1_fx * pc_z[j] + 1.5 * pa_zz[j] * pc_zz[j] * fl1_fx + 1.5 * pa_zz[j] * pc_z[j] * fl1_fx * pb_z[j] + 1.5 * pa_zz[j] * fl1_fx * pc_yy[j] + 3.0 * pa_zz[j] * fl1_fx * pb_y[j] * pc_y[j] + 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_z[j] + 9.0 * pa_z[j] * pc_yz[j] * fl1_fx * pb_y[j] + 4.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_yy[j] + 3.0 * pc_zz[j] * fl1_fx * pb_yy[j] + 1.5 * pa_z[j] * fl1_fx * pc_yy[j] * pb_z[j] + 3.0 * pa_z[j] * fl1_fx * pb_yz[j] * pc_y[j] + 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] + 1.5 * pc_z[j] * fl1_fx * pb_yyz[j] + 2.0 * pa_zzz[j] * pb_y[j] * pc_yz[j] + pa_zzz[j] * pc_yy[j] * pb_z[j] + 3.0 * pa_zz[j] * pc_zz[j] * pb_yy[j] + 6.0 * pa_zz[j] * pc_yz[j] * pb_yz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_yyz[j]);

                t_zzz_yyz[j] += fl_s_0_0_3 * (-0.375 * fl3_fx - 2.25 * pa_z[j] * pc_z[j] * fl2_fx - 3.0 * pc_zz[j] * fl2_fx - 0.75 * pc_z[j] * fl2_fx * pb_z[j] - 1.5 * fl2_fx * pc_yy[j] - 1.5 * fl2_fx * pb_y[j] * pc_y[j] - 1.5 * pa_zz[j] * pc_zz[j] * fl1_fx - 1.5 * pa_zz[j] * fl1_fx * pc_yy[j] - 1.5 * pa_z[j] * pc_zzz[j] * fl1_fx - 1.5 * pa_z[j] * pc_zz[j] * fl1_fx * pb_z[j] - 4.5 * pa_z[j] * pc_yyz[j] * fl1_fx - 9.0 * pa_z[j] * pc_yz[j] * fl1_fx * pb_y[j] - 0.5 * pc_zzz[j] * fl1_fx * pb_z[j] - 6.0 * pc_yzz[j] * fl1_fx * pb_y[j] - 3.0 * pc_zz[j] * fl1_fx * pb_yy[j] - 1.5 * pa_z[j] * fl1_fx * pc_yy[j] * pb_z[j] - 1.5 * pc_yyz[j] * fl1_fx * pb_z[j] - 3.0 * pc_yz[j] * fl1_fx * pb_yz[j] - pa_zzz[j] * pc_yyz[j] - 6.0 * pa_zz[j] * pc_yzz[j] * pb_y[j] - 3.0 * pa_zz[j] * pc_yyz[j] * pb_z[j] - 3.0 * pa_z[j] * pc_zzz[j] * pb_yy[j] - 6.0 * pa_z[j] * pc_yzz[j] * pb_yz[j] - pc_zzz[j] * pb_yyz[j]);

                t_zzz_yyz[j] += fl_s_0_0_4 * (1.5 * pc_zz[j] * fl2_fx + 0.75 * fl2_fx * pc_yy[j] + 1.5 * pa_z[j] * pc_zzz[j] * fl1_fx + 4.5 * pa_z[j] * pc_yyz[j] * fl1_fx + 0.5 * pc_zzzz[j] * fl1_fx + 0.5 * pc_zzz[j] * fl1_fx * pb_z[j] + 3.0 * pc_yyzz[j] * fl1_fx + 6.0 * pc_yzz[j] * fl1_fx * pb_y[j] + 1.5 * pc_yyz[j] * fl1_fx * pb_z[j] + 3.0 * pa_zz[j] * pc_yyzz[j] + 6.0 * pa_z[j] * pc_yzzz[j] * pb_y[j] + 3.0 * pa_z[j] * pc_yyzz[j] * pb_z[j] + pc_zzzz[j] * pb_yy[j] + 2.0 * pc_yzzz[j] * pb_yz[j]);

                t_zzz_yyz[j] += fl_s_0_0_5 * (-0.5 * pc_zzzz[j] * fl1_fx - 3.0 * pc_yyzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_yyzzz[j] - 2.0 * pc_yzzzz[j] * pb_y[j] - pc_yyzzz[j] * pb_z[j]);

                t_zzz_yyz[j] += fl_s_0_0_6 * pc_yyzzzz[j];

                t_zzz_yzz[j] = fl_s_0_0_0 * (2.25 * pa_z[j] * fl2_fx * pb_y[j] + 1.5 * fl2_fx * pb_yz[j] + 0.5 * pa_zzz[j] * pb_y[j] * fl1_fx + 3.0 * pa_zz[j] * fl1_fx * pb_yz[j] + 1.5 * pa_z[j] * fl1_fx * pb_yzz[j] + pa_zzz[j] * pb_yzz[j]);

                t_zzz_yzz[j] += fl_s_0_0_1 * (-2.25 * pa_z[j] * fl2_fx * pc_y[j] - 4.5 * pa_z[j] * fl2_fx * pb_y[j] - 3.75 * pc_z[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pc_y[j] * pb_z[j] - 3.0 * fl2_fx * pb_yz[j] - 0.5 * pa_zzz[j] * pb_y[j] * fl1_fx - 0.5 * pa_zzz[j] * pc_y[j] * fl1_fx - 4.5 * pa_zz[j] * pc_z[j] * pb_y[j] * fl1_fx - 3.0 * pa_zz[j] * fl1_fx * pc_y[j] * pb_z[j] - 3.0 * pa_zz[j] * fl1_fx * pb_yz[j] - 9.0 * pa_z[j] * pc_z[j] * fl1_fx * pb_yz[j] - 1.5 * pa_z[j] * fl1_fx * pc_y[j] * pb_zz[j] - 1.5 * pa_z[j] * fl1_fx * pb_yzz[j] - 1.5 * pc_z[j] * fl1_fx * pb_yzz[j] - 2.0 * pa_zzz[j] * pb_yz[j] * pc_z[j] - pa_zzz[j] * pc_y[j] * pb_zz[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_yzz[j]);

                t_zzz_yzz[j] += fl_s_0_0_2 * (4.5 * pa_z[j] * fl2_fx * pc_y[j] + 2.25 * pa_z[j] * fl2_fx * pb_y[j] + 3.75 * pc_yz[j] * fl2_fx + 7.5 * pc_z[j] * fl2_fx * pb_y[j] + 3.0 * fl2_fx * pc_y[j] * pb_z[j] + 1.5 * fl2_fx * pb_yz[j] + 0.5 * pa_zzz[j] * pc_y[j] * fl1_fx + 4.5 * pa_zz[j] * pc_z[j] * pb_y[j] * fl1_fx + 4.5 * pa_zz[j] * pc_yz[j] * fl1_fx + 3.0 * pa_zz[j] * fl1_fx * pc_y[j] * pb_z[j] + 9.0 * pa_z[j] * pc_zz[j] * pb_y[j] * fl1_fx + 9.0 * pa_z[j] * pc_yz[j] * fl1_fx * pb_z[j] + 9.0 * pa_z[j] * pc_z[j] * fl1_fx * pb_yz[j] + 6.0 * pc_zz[j] * fl1_fx * pb_yz[j] + 1.5 * pa_z[j] * fl1_fx * pc_y[j] * pb_zz[j] + 1.5 * pc_yz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_z[j] * fl1_fx * pb_yzz[j] + pa_zzz[j] * pb_y[j] * pc_zz[j] + 2.0 * pa_zzz[j] * pc_yz[j] * pb_z[j] + 6.0 * pa_zz[j] * pc_zz[j] * pb_yz[j] + 3.0 * pa_zz[j] * pc_yz[j] * pb_zz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_yzz[j]);

                t_zzz_yzz[j] += fl_s_0_0_3 * (-2.25 * pa_z[j] * fl2_fx * pc_y[j] - 7.5 * pc_yz[j] * fl2_fx - 3.75 * pc_z[j] * fl2_fx * pb_y[j] - 1.5 * fl2_fx * pc_y[j] * pb_z[j] - 4.5 * pa_zz[j] * pc_yz[j] * fl1_fx - 9.0 * pa_z[j] * pc_zz[j] * pb_y[j] * fl1_fx - 9.0 * pa_z[j] * pc_yzz[j] * fl1_fx - 9.0 * pa_z[j] * pc_yz[j] * fl1_fx * pb_z[j] - 5.0 * pc_zzz[j] * pb_y[j] * fl1_fx - 6.0 * pc_yzz[j] * fl1_fx * pb_z[j] - 6.0 * pc_zz[j] * fl1_fx * pb_yz[j] - 1.5 * pc_yz[j] * fl1_fx * pb_zz[j] - pa_zzz[j] * pc_yzz[j] - 3.0 * pa_zz[j] * pc_zzz[j] * pb_y[j] - 6.0 * pa_zz[j] * pc_yzz[j] * pb_z[j] - 6.0 * pa_z[j] * pc_zzz[j] * pb_yz[j] - 3.0 * pa_z[j] * pc_yzz[j] * pb_zz[j] - pc_zzz[j] * pb_yzz[j]);

                t_zzz_yzz[j] += fl_s_0_0_4 * (3.75 * pc_yz[j] * fl2_fx + 9.0 * pa_z[j] * pc_yzz[j] * fl1_fx + 5.0 * pc_zzz[j] * pb_y[j] * fl1_fx + 5.0 * pc_yzzz[j] * fl1_fx + 6.0 * pc_yzz[j] * fl1_fx * pb_z[j] + 3.0 * pa_zz[j] * pc_yzzz[j] + 3.0 * pa_z[j] * pc_zzzz[j] * pb_y[j] + 6.0 * pa_z[j] * pc_yzzz[j] * pb_z[j] + 2.0 * pc_zzzz[j] * pb_yz[j] + pc_yzzz[j] * pb_zz[j]);

                t_zzz_yzz[j] += fl_s_0_0_5 * (-5.0 * pc_yzzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_yzzzz[j] - pc_zzzzz[j] * pb_y[j] - 2.0 * pc_yzzzz[j] * pb_z[j]);

                t_zzz_yzz[j] += fl_s_0_0_6 * pc_yzzzzz[j];

                t_zzz_zzz[j] = fl_s_0_0_0 * (1.875 * fl3_fx + 2.25 * pa_zz[j] * fl2_fx + 6.75 * pa_z[j] * fl2_fx * pb_z[j] + 2.25 * fl2_fx * pb_zz[j] + 1.5 * pa_zzz[j] * pb_z[j] * fl1_fx + 4.5 * pa_zz[j] * fl1_fx * pb_zz[j] + 1.5 * pa_z[j] * fl1_fx * pb_zzz[j] + pa_zzz[j] * pb_zzz[j]);

                t_zzz_zzz[j] += fl_s_0_0_1 * (-5.625 * fl3_fx - 4.5 * pa_zz[j] * fl2_fx - 11.25 * pa_z[j] * pc_z[j] * fl2_fx - 13.5 * pa_z[j] * fl2_fx * pb_z[j] - 11.25 * pc_z[j] * fl2_fx * pb_z[j] - 4.5 * fl2_fx * pb_zz[j] - 1.5 * pa_zzz[j] * pb_z[j] * fl1_fx - 1.5 * pa_zzz[j] * pc_z[j] * fl1_fx - 13.5 * pa_zz[j] * pc_z[j] * pb_z[j] * fl1_fx - 4.5 * pa_zz[j] * fl1_fx * pb_zz[j] - 13.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_zz[j] - 1.5 * pa_z[j] * fl1_fx * pb_zzz[j] - 1.5 * pc_z[j] * fl1_fx * pb_zzz[j] - 3.0 * pa_zzz[j] * pb_zz[j] * pc_z[j] - 3.0 * pa_zz[j] * pc_z[j] * pb_zzz[j]);

                t_zzz_zzz[j] += fl_s_0_0_2 * (5.625 * fl3_fx + 2.25 * pa_zz[j] * fl2_fx + 22.5 * pa_z[j] * pc_z[j] * fl2_fx + 6.75 * pa_z[j] * fl2_fx * pb_z[j] + 11.25 * pc_zz[j] * fl2_fx + 22.5 * pc_z[j] * fl2_fx * pb_z[j] + 2.25 * fl2_fx * pb_zz[j] + 1.5 * pa_zzz[j] * pc_z[j] * fl1_fx + 13.5 * pa_zz[j] * pc_z[j] * pb_z[j] * fl1_fx + 9.0 * pa_zz[j] * pc_zz[j] * fl1_fx + 27.0 * pa_z[j] * pc_zz[j] * pb_z[j] * fl1_fx + 13.5 * pa_z[j] * pc_z[j] * fl1_fx * pb_zz[j] + 9.0 * pc_zz[j] * fl1_fx * pb_zz[j] + 1.5 * pc_z[j] * fl1_fx * pb_zzz[j] + 3.0 * pa_zzz[j] * pb_z[j] * pc_zz[j] + 9.0 * pa_zz[j] * pc_zz[j] * pb_zz[j] + 3.0 * pa_z[j] * pc_zz[j] * pb_zzz[j]);

                t_zzz_zzz[j] += fl_s_0_0_3 * (-1.875 * fl3_fx - 11.25 * pa_z[j] * pc_z[j] * fl2_fx - 22.5 * pc_zz[j] * fl2_fx - 11.25 * pc_z[j] * fl2_fx * pb_z[j] - 9.0 * pa_zz[j] * pc_zz[j] * fl1_fx - 27.0 * pa_z[j] * pc_zz[j] * pb_z[j] * fl1_fx - 15.0 * pa_z[j] * pc_zzz[j] * fl1_fx - 15.0 * pc_zzz[j] * pb_z[j] * fl1_fx - 9.0 * pc_zz[j] * fl1_fx * pb_zz[j] - pa_zzz[j] * pc_zzz[j] - 9.0 * pa_zz[j] * pc_zzz[j] * pb_z[j] - 9.0 * pa_z[j] * pc_zzz[j] * pb_zz[j] - pc_zzz[j] * pb_zzz[j]);

                t_zzz_zzz[j] += fl_s_0_0_4 * (11.25 * pc_zz[j] * fl2_fx + 15.0 * pa_z[j] * pc_zzz[j] * fl1_fx + 15.0 * pc_zzz[j] * pb_z[j] * fl1_fx + 7.5 * pc_zzzz[j] * fl1_fx + 3.0 * pa_zz[j] * pc_zzzz[j] + 9.0 * pa_z[j] * pc_zzzz[j] * pb_z[j] + 3.0 * pc_zzzz[j] * pb_zz[j]);

                t_zzz_zzz[j] += fl_s_0_0_5 * (-7.5 * pc_zzzz[j] * fl1_fx - 3.0 * pa_z[j] * pc_zzzzz[j] - 3.0 * pc_zzzzz[j] * pb_z[j]);

                t_zzz_zzz[j] += fl_s_0_0_6 * pc_zzzzzz[j];
            }

            idx++;
        }
    }


} // npotrecfunc namespace

