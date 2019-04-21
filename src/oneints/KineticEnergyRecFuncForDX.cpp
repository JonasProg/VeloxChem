//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "KineticEnergyRecFuncForDX.hpp"

namespace kinrecfunc { // kinrecfunc namespace

    void
    compKineticEnergyForDD(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        kinrecfunc::compKineticEnergyForDD_0_12(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDD_12_24(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDD_24_36(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compKineticEnergyForDD_0_12(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto)
    {
        // Batch of Integrals (0,12)

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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(9 * idx + 3);

            auto pa_xy = paDistances.data(9 * idx + 4);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xx_xx = primBuffer.data(36 * idx);

            auto t_xx_xy = primBuffer.data(36 * idx + 1);

            auto t_xx_xz = primBuffer.data(36 * idx + 2);

            auto t_xx_yy = primBuffer.data(36 * idx + 3);

            auto t_xx_yz = primBuffer.data(36 * idx + 4);

            auto t_xx_zz = primBuffer.data(36 * idx + 5);

            auto t_xy_xx = primBuffer.data(36 * idx + 6);

            auto t_xy_xy = primBuffer.data(36 * idx + 7);

            auto t_xy_xz = primBuffer.data(36 * idx + 8);

            auto t_xy_yy = primBuffer.data(36 * idx + 9);

            auto t_xy_yz = primBuffer.data(36 * idx + 10);

            auto t_xy_zz = primBuffer.data(36 * idx + 11);

            // Batch of Integrals (0,12)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xy, pa_y, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, \
                                     pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xx_xx, t_xx_xy, t_xx_xz, t_xx_yy, t_xx_yz, \
                                     t_xx_zz, t_xy_xx, t_xy_xy, t_xy_xz, t_xy_yy, t_xy_yz, t_xy_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xx_xx[j] = fl_s_0_0 * (0.75 * fl2_fx + 0.5 * pa_xx[j] * fl1_fx + 2.0 * pa_x[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pb_xx[j] + pa_xx[j] * pb_xx[j]);

                t_xx_xx[j] += fl_r_0_0 * (3.0 * fl2_fx * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_xx[j] * fl1_fz * fl1_fgb + 3.0 * pa_xx[j] * fl1_fz * fl1_fx + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_x[j] - fl1_fz * fl1_fga * pb_xx[j] + 3.0 * fl1_fz * fl1_fx * pb_xx[j] + 8.0 * pa_xx[j] * fl1_fz * pb_xx[j]);

                t_xx_xy[j] = fl_s_0_0 * (pa_x[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pb_xy[j] + pa_xx[j] * pb_xy[j]);

                t_xx_xy[j] += fl_r_0_0 * (6.0 * pa_x[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pb_xy[j] + 3.0 * fl1_fz * fl1_fx * pb_xy[j] + 8.0 * pa_xx[j] * fl1_fz * pb_xy[j]);

                t_xx_xz[j] = fl_s_0_0 * (pa_x[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pb_xz[j] + pa_xx[j] * pb_xz[j]);

                t_xx_xz[j] += fl_r_0_0 * (6.0 * pa_x[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pb_xz[j] + 3.0 * fl1_fz * fl1_fx * pb_xz[j] + 8.0 * pa_xx[j] * fl1_fz * pb_xz[j]);

                t_xx_yy[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_xx[j] * fl1_fx + 0.5 * fl1_fx * pb_yy[j] + pa_xx[j] * pb_yy[j]);

                t_xx_yy[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_xx[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_xx[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_yy[j] + 3.0 * fl1_fz * fl1_fx * pb_yy[j] + 8.0 * pa_xx[j] * fl1_fz * pb_yy[j]);

                t_xx_yz[j] = fl_s_0_0 * (0.5 * fl1_fx * pb_yz[j] + pa_xx[j] * pb_yz[j]);

                t_xx_yz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pb_yz[j] + 3.0 * fl1_fz * fl1_fx * pb_yz[j] + 8.0 * pa_xx[j] * fl1_fz * pb_yz[j]);

                t_xx_zz[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_xx[j] * fl1_fx + 0.5 * fl1_fx * pb_zz[j] + pa_xx[j] * pb_zz[j]);

                t_xx_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_xx[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_xx[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_zz[j] + 3.0 * fl1_fz * fl1_fx * pb_zz[j] + 8.0 * pa_xx[j] * fl1_fz * pb_zz[j]);

                t_xy_xx[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl1_fx + fl1_fx * pa_y[j] * pb_x[j] + pa_xy[j] * pb_xx[j]);

                t_xy_xx[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fz * fl1_fgb + 3.0 * pa_xy[j] * fl1_fz * fl1_fx + 6.0 * fl1_fx * fl1_fz * pa_y[j] * pb_x[j] + 8.0 * pa_xy[j] * fl1_fz * pb_xx[j]);

                t_xy_xy[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_x[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_y[j] * pb_y[j] + pa_xy[j] * pb_xy[j]);

                t_xy_xy[j] += fl_r_0_0 * (fl2_fx * fl1_fz + 3.0 * pa_x[j] * fl1_fz * fl1_fx * pb_x[j] + 3.0 * fl1_fx * fl1_fz * pa_y[j] * pb_y[j] + 8.0 * pa_xy[j] * fl1_fz * pb_xy[j]);

                t_xy_xz[j] = fl_s_0_0 * (0.5 * fl1_fx * pa_y[j] * pb_z[j] + pa_xy[j] * pb_xz[j]);

                t_xy_xz[j] += fl_r_0_0 * (3.0 * fl1_fx * fl1_fz * pa_y[j] * pb_z[j] + 8.0 * pa_xy[j] * fl1_fz * pb_xz[j]);

                t_xy_yy[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl1_fx + pa_x[j] * fl1_fx * pb_y[j] + pa_xy[j] * pb_yy[j]);

                t_xy_yy[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fz * fl1_fgb + 3.0 * pa_xy[j] * fl1_fz * fl1_fx + 6.0 * pa_x[j] * fl1_fz * fl1_fx * pb_y[j] + 8.0 * pa_xy[j] * fl1_fz * pb_yy[j]);

                t_xy_yz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl1_fx * pb_z[j] + pa_xy[j] * pb_yz[j]);

                t_xy_yz[j] += fl_r_0_0 * (3.0 * pa_x[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_xy[j] * fl1_fz * pb_yz[j]);

                t_xy_zz[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl1_fx + pa_xy[j] * pb_zz[j]);

                t_xy_zz[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fz * fl1_fgb + 3.0 * pa_xy[j] * fl1_fz * fl1_fx + 8.0 * pa_xy[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDD_12_24(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
                                 const CGtoBlock&           braGtoBlock,
                                 const CGtoBlock&           ketGtoBlock,
                                 const int32_t              iContrGto)
    {
        // Batch of Integrals (12,24)

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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(9 * idx + 5);

            auto pa_yy = paDistances.data(9 * idx + 6);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xz_xx = primBuffer.data(36 * idx + 12);

            auto t_xz_xy = primBuffer.data(36 * idx + 13);

            auto t_xz_xz = primBuffer.data(36 * idx + 14);

            auto t_xz_yy = primBuffer.data(36 * idx + 15);

            auto t_xz_yz = primBuffer.data(36 * idx + 16);

            auto t_xz_zz = primBuffer.data(36 * idx + 17);

            auto t_yy_xx = primBuffer.data(36 * idx + 18);

            auto t_yy_xy = primBuffer.data(36 * idx + 19);

            auto t_yy_xz = primBuffer.data(36 * idx + 20);

            auto t_yy_yy = primBuffer.data(36 * idx + 21);

            auto t_yy_yz = primBuffer.data(36 * idx + 22);

            auto t_yy_zz = primBuffer.data(36 * idx + 23);

            // Batch of Integrals (12,24)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_y, pa_yy, pa_z, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, \
                                     pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xz_xx, t_xz_xy, t_xz_xz, t_xz_yy, t_xz_yz, \
                                     t_xz_zz, t_yy_xx, t_yy_xy, t_yy_xz, t_yy_yy, t_yy_yz, t_yy_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xz_xx[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl1_fx + fl1_fx * pa_z[j] * pb_x[j] + pa_xz[j] * pb_xx[j]);

                t_xz_xx[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fz * fl1_fgb + 3.0 * pa_xz[j] * fl1_fz * fl1_fx + 6.0 * fl1_fx * fl1_fz * pa_z[j] * pb_x[j] + 8.0 * pa_xz[j] * fl1_fz * pb_xx[j]);

                t_xz_xy[j] = fl_s_0_0 * (0.5 * fl1_fx * pa_z[j] * pb_y[j] + pa_xz[j] * pb_xy[j]);

                t_xz_xy[j] += fl_r_0_0 * (3.0 * fl1_fx * fl1_fz * pa_z[j] * pb_y[j] + 8.0 * pa_xz[j] * fl1_fz * pb_xy[j]);

                t_xz_xz[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_x[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_z[j] * pb_z[j] + pa_xz[j] * pb_xz[j]);

                t_xz_xz[j] += fl_r_0_0 * (fl2_fx * fl1_fz + 3.0 * pa_x[j] * fl1_fz * fl1_fx * pb_x[j] + 3.0 * fl1_fx * fl1_fz * pa_z[j] * pb_z[j] + 8.0 * pa_xz[j] * fl1_fz * pb_xz[j]);

                t_xz_yy[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl1_fx + pa_xz[j] * pb_yy[j]);

                t_xz_yy[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fz * fl1_fgb + 3.0 * pa_xz[j] * fl1_fz * fl1_fx + 8.0 * pa_xz[j] * fl1_fz * pb_yy[j]);

                t_xz_yz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl1_fx * pb_y[j] + pa_xz[j] * pb_yz[j]);

                t_xz_yz[j] += fl_r_0_0 * (3.0 * pa_x[j] * fl1_fz * fl1_fx * pb_y[j] + 8.0 * pa_xz[j] * fl1_fz * pb_yz[j]);

                t_xz_zz[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl1_fx + pa_x[j] * fl1_fx * pb_z[j] + pa_xz[j] * pb_zz[j]);

                t_xz_zz[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fz * fl1_fgb + 3.0 * pa_xz[j] * fl1_fz * fl1_fx + 6.0 * pa_x[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_xz[j] * fl1_fz * pb_zz[j]);

                t_yy_xx[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_yy[j] * fl1_fx + 0.5 * fl1_fx * pb_xx[j] + pa_yy[j] * pb_xx[j]);

                t_yy_xx[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_yy[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_yy[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_xx[j] + 3.0 * fl1_fz * fl1_fx * pb_xx[j] + 8.0 * pa_yy[j] * fl1_fz * pb_xx[j]);

                t_yy_xy[j] = fl_s_0_0 * (pa_y[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pb_xy[j] + pa_yy[j] * pb_xy[j]);

                t_yy_xy[j] += fl_r_0_0 * (6.0 * pa_y[j] * fl1_fz * fl1_fx * pb_x[j] - fl1_fz * fl1_fga * pb_xy[j] + 3.0 * fl1_fz * fl1_fx * pb_xy[j] + 8.0 * pa_yy[j] * fl1_fz * pb_xy[j]);

                t_yy_xz[j] = fl_s_0_0 * (0.5 * fl1_fx * pb_xz[j] + pa_yy[j] * pb_xz[j]);

                t_yy_xz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pb_xz[j] + 3.0 * fl1_fz * fl1_fx * pb_xz[j] + 8.0 * pa_yy[j] * fl1_fz * pb_xz[j]);

                t_yy_yy[j] = fl_s_0_0 * (0.75 * fl2_fx + 0.5 * pa_yy[j] * fl1_fx + 2.0 * pa_y[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pb_yy[j] + pa_yy[j] * pb_yy[j]);

                t_yy_yy[j] += fl_r_0_0 * (3.0 * fl2_fx * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_yy[j] * fl1_fz * fl1_fgb + 3.0 * pa_yy[j] * fl1_fz * fl1_fx + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pb_yy[j] + 3.0 * fl1_fz * fl1_fx * pb_yy[j] + 8.0 * pa_yy[j] * fl1_fz * pb_yy[j]);

                t_yy_yz[j] = fl_s_0_0 * (pa_y[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pb_yz[j] + pa_yy[j] * pb_yz[j]);

                t_yy_yz[j] += fl_r_0_0 * (6.0 * pa_y[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pb_yz[j] + 3.0 * fl1_fz * fl1_fx * pb_yz[j] + 8.0 * pa_yy[j] * fl1_fz * pb_yz[j]);

                t_yy_zz[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_yy[j] * fl1_fx + 0.5 * fl1_fx * pb_zz[j] + pa_yy[j] * pb_zz[j]);

                t_yy_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_yy[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_yy[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_zz[j] + 3.0 * fl1_fz * fl1_fx * pb_zz[j] + 8.0 * pa_yy[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDD_24_36(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
                                 const CGtoBlock&           braGtoBlock,
                                 const CGtoBlock&           ketGtoBlock,
                                 const int32_t              iContrGto)
    {
        // Batch of Integrals (24,36)

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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(9 * idx + 7);

            auto pa_zz = paDistances.data(9 * idx + 8);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yz_xx = primBuffer.data(36 * idx + 24);

            auto t_yz_xy = primBuffer.data(36 * idx + 25);

            auto t_yz_xz = primBuffer.data(36 * idx + 26);

            auto t_yz_yy = primBuffer.data(36 * idx + 27);

            auto t_yz_yz = primBuffer.data(36 * idx + 28);

            auto t_yz_zz = primBuffer.data(36 * idx + 29);

            auto t_zz_xx = primBuffer.data(36 * idx + 30);

            auto t_zz_xy = primBuffer.data(36 * idx + 31);

            auto t_zz_xz = primBuffer.data(36 * idx + 32);

            auto t_zz_yy = primBuffer.data(36 * idx + 33);

            auto t_zz_yz = primBuffer.data(36 * idx + 34);

            auto t_zz_zz = primBuffer.data(36 * idx + 35);

            // Batch of Integrals (24,36)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_z, pa_zz, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, \
                                     pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yz_xx, t_yz_xy, t_yz_xz, t_yz_yy, t_yz_yz, \
                                     t_yz_zz, t_zz_xx, t_zz_xy, t_zz_xz, t_zz_yy, t_zz_yz, t_zz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_yz_xx[j] = fl_s_0_0 * (0.5 * pa_yz[j] * fl1_fx + pa_yz[j] * pb_xx[j]);

                t_yz_xx[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fz * fl1_fgb + 3.0 * pa_yz[j] * fl1_fz * fl1_fx + 8.0 * pa_yz[j] * fl1_fz * pb_xx[j]);

                t_yz_xy[j] = fl_s_0_0 * (0.5 * fl1_fx * pa_z[j] * pb_x[j] + pa_yz[j] * pb_xy[j]);

                t_yz_xy[j] += fl_r_0_0 * (3.0 * fl1_fx * fl1_fz * pa_z[j] * pb_x[j] + 8.0 * pa_yz[j] * fl1_fz * pb_xy[j]);

                t_yz_xz[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl1_fx * pb_x[j] + pa_yz[j] * pb_xz[j]);

                t_yz_xz[j] += fl_r_0_0 * (3.0 * pa_y[j] * fl1_fz * fl1_fx * pb_x[j] + 8.0 * pa_yz[j] * fl1_fz * pb_xz[j]);

                t_yz_yy[j] = fl_s_0_0 * (0.5 * pa_yz[j] * fl1_fx + fl1_fx * pa_z[j] * pb_y[j] + pa_yz[j] * pb_yy[j]);

                t_yz_yy[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fz * fl1_fgb + 3.0 * pa_yz[j] * fl1_fz * fl1_fx + 6.0 * fl1_fx * fl1_fz * pa_z[j] * pb_y[j] + 8.0 * pa_yz[j] * fl1_fz * pb_yy[j]);

                t_yz_yz[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_y[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_z[j] * pb_z[j] + pa_yz[j] * pb_yz[j]);

                t_yz_yz[j] += fl_r_0_0 * (fl2_fx * fl1_fz + 3.0 * pa_y[j] * fl1_fz * fl1_fx * pb_y[j] + 3.0 * fl1_fx * fl1_fz * pa_z[j] * pb_z[j] + 8.0 * pa_yz[j] * fl1_fz * pb_yz[j]);

                t_yz_zz[j] = fl_s_0_0 * (0.5 * pa_yz[j] * fl1_fx + pa_y[j] * fl1_fx * pb_z[j] + pa_yz[j] * pb_zz[j]);

                t_yz_zz[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fz * fl1_fgb + 3.0 * pa_yz[j] * fl1_fz * fl1_fx + 6.0 * pa_y[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_yz[j] * fl1_fz * pb_zz[j]);

                t_zz_xx[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_zz[j] * fl1_fx + 0.5 * fl1_fx * pb_xx[j] + pa_zz[j] * pb_xx[j]);

                t_zz_xx[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_zz[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_zz[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_xx[j] + 3.0 * fl1_fz * fl1_fx * pb_xx[j] + 8.0 * pa_zz[j] * fl1_fz * pb_xx[j]);

                t_zz_xy[j] = fl_s_0_0 * (0.5 * fl1_fx * pb_xy[j] + pa_zz[j] * pb_xy[j]);

                t_zz_xy[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pb_xy[j] + 3.0 * fl1_fz * fl1_fx * pb_xy[j] + 8.0 * pa_zz[j] * fl1_fz * pb_xy[j]);

                t_zz_xz[j] = fl_s_0_0 * (pa_z[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pb_xz[j] + pa_zz[j] * pb_xz[j]);

                t_zz_xz[j] += fl_r_0_0 * (6.0 * pa_z[j] * fl1_fz * fl1_fx * pb_x[j] - fl1_fz * fl1_fga * pb_xz[j] + 3.0 * fl1_fz * fl1_fx * pb_xz[j] + 8.0 * pa_zz[j] * fl1_fz * pb_xz[j]);

                t_zz_yy[j] = fl_s_0_0 * (0.25 * fl2_fx + 0.5 * pa_zz[j] * fl1_fx + 0.5 * fl1_fx * pb_yy[j] + pa_zz[j] * pb_yy[j]);

                t_zz_yy[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_zz[j] * fl1_fz * fl1_fgb + fl1_fz * fl2_fx + 3.0 * pa_zz[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pb_yy[j] + 3.0 * fl1_fz * fl1_fx * pb_yy[j] + 8.0 * pa_zz[j] * fl1_fz * pb_yy[j]);

                t_zz_yz[j] = fl_s_0_0 * (pa_z[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pb_yz[j] + pa_zz[j] * pb_yz[j]);

                t_zz_yz[j] += fl_r_0_0 * (6.0 * pa_z[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pb_yz[j] + 3.0 * fl1_fz * fl1_fx * pb_yz[j] + 8.0 * pa_zz[j] * fl1_fz * pb_yz[j]);

                t_zz_zz[j] = fl_s_0_0 * (0.75 * fl2_fx + 0.5 * pa_zz[j] * fl1_fx + 2.0 * pa_z[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pb_zz[j] + pa_zz[j] * pb_zz[j]);

                t_zz_zz[j] += fl_r_0_0 * (3.0 * fl2_fx * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * fl1_fx - pa_zz[j] * fl1_fz * fl1_fgb + 3.0 * pa_zz[j] * fl1_fz * fl1_fx + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pb_zz[j] + 3.0 * fl1_fz * fl1_fx * pb_zz[j] + 8.0 * pa_zz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        kinrecfunc::compKineticEnergyForDF_0_10(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDF_10_20(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDF_20_30(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDF_30_40(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDF_40_50(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDF_50_60(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compKineticEnergyForDF_0_10(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(9 * idx + 3);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xx_xxx = primBuffer.data(60 * idx);

            auto t_xx_xxy = primBuffer.data(60 * idx + 1);

            auto t_xx_xxz = primBuffer.data(60 * idx + 2);

            auto t_xx_xyy = primBuffer.data(60 * idx + 3);

            auto t_xx_xyz = primBuffer.data(60 * idx + 4);

            auto t_xx_xzz = primBuffer.data(60 * idx + 5);

            auto t_xx_yyy = primBuffer.data(60 * idx + 6);

            auto t_xx_yyz = primBuffer.data(60 * idx + 7);

            auto t_xx_yzz = primBuffer.data(60 * idx + 8);

            auto t_xx_zzz = primBuffer.data(60 * idx + 9);

            // Batch of Integrals (0,10)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_xx_xxx, t_xx_xxy, t_xx_xxz, t_xx_xyy, t_xx_xyz, t_xx_xzz, \
                                     t_xx_yyy, t_xx_yyz, t_xx_yzz, t_xx_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xx_xxx[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl2_fx + 2.25 * fl2_fx * pb_x[j] + 1.5 * pa_xx[j] * pb_x[j] * fl1_fx + 3.0 * pa_x[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pb_xxx[j] + pa_xx[j] * pb_xxx[j]);

                t_xx_xxx[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 9.0 * pa_x[j] * fl1_fz * fl2_fx + 13.5 * fl2_fx * fl1_fz * pb_x[j] - 1.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - 3.0 * pa_xx[j] * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_xx[j] * fl1_fz * pb_x[j] * fl1_fx + 24.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] - fl1_fz * fl1_fga * pb_xxx[j] + 4.0 * fl1_fz * fl1_fx * pb_xxx[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xxx[j]);

                t_xx_xxy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 0.5 * pa_xx[j] * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pb_xxy[j] + pa_xx[j] * pb_xxy[j]);

                t_xx_xxy[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_y[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_y[j] - pa_xx[j] * fl1_fz * fl1_fgb * pb_y[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_y[j] + 16.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] - fl1_fz * fl1_fga * pb_xxy[j] + 4.0 * fl1_fz * fl1_fx * pb_xxy[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xxy[j]);

                t_xx_xxz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pb_z[j] + 2.0 * pa_x[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pb_xxz[j] + pa_xx[j] * pb_xxz[j]);

                t_xx_xxz[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_z[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_xx[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_z[j] + 16.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] - fl1_fz * fl1_fga * pb_xxz[j] + 4.0 * fl1_fz * fl1_fx * pb_xxz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xxz[j]);

                t_xx_xyy[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx + 0.25 * fl2_fx * pb_x[j] + 0.5 * pa_xx[j] * pb_x[j] * fl1_fx + pa_x[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pb_xyy[j] + pa_xx[j] * pb_xyy[j]);

                t_xx_xyy[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_x[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_xx[j] * pb_x[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_x[j] + 4.0 * pa_xx[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] - fl1_fz * fl1_fga * pb_xyy[j] + 4.0 * fl1_fz * fl1_fx * pb_xyy[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xyy[j]);

                t_xx_xyz[j] = fl_s_0_0 * (pa_x[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pb_xyz[j] + pa_xx[j] * pb_xyz[j]);

                t_xx_xyz[j] += fl_r_0_0 * (8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] - fl1_fz * fl1_fga * pb_xyz[j] + 4.0 * fl1_fz * fl1_fx * pb_xyz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xyz[j]);

                t_xx_xzz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx + 0.25 * fl2_fx * pb_x[j] + 0.5 * pa_xx[j] * pb_x[j] * fl1_fx + pa_x[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pb_xzz[j] + pa_xx[j] * pb_xzz[j]);

                t_xx_xzz[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_x[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_xx[j] * pb_x[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_x[j] + 4.0 * pa_xx[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] - fl1_fz * fl1_fga * pb_xzz[j] + 4.0 * fl1_fz * fl1_fx * pb_xzz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_xzz[j]);

                t_xx_yyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 1.5 * pa_xx[j] * pb_y[j] * fl1_fx + 0.5 * fl1_fx * pb_yyy[j] + pa_xx[j] * pb_yyy[j]);

                t_xx_yyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - 3.0 * pa_xx[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_y[j] + 12.0 * pa_xx[j] * fl1_fz * pb_y[j] * fl1_fx - fl1_fz * fl1_fga * pb_yyy[j] + 4.0 * fl1_fz * fl1_fx * pb_yyy[j] + 10.0 * pa_xx[j] * fl1_fz * pb_yyy[j]);

                t_xx_yyz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pb_yyz[j] + pa_xx[j] * pb_yyz[j]);

                t_xx_yyz[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_xx[j] * fl1_fz * fl1_fgb * pb_z[j] + 1.5 * fl1_fz * fl2_fx * pb_z[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pb_yyz[j] + 4.0 * fl1_fz * fl1_fx * pb_yyz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_yyz[j]);

                t_xx_yzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_y[j] + 0.5 * pa_xx[j] * pb_y[j] * fl1_fx + 0.5 * fl1_fx * pb_yzz[j] + pa_xx[j] * pb_yzz[j]);

                t_xx_yzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - pa_xx[j] * pb_y[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_y[j] + 4.0 * pa_xx[j] * fl1_fz * pb_y[j] * fl1_fx - fl1_fz * fl1_fga * pb_yzz[j] + 4.0 * fl1_fz * fl1_fx * pb_yzz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_yzz[j]);

                t_xx_zzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 1.5 * pa_xx[j] * pb_z[j] * fl1_fx + 0.5 * fl1_fx * pb_zzz[j] + pa_xx[j] * pb_zzz[j]);

                t_xx_zzz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_z[j] * fl1_fx - 3.0 * pa_xx[j] * pb_z[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_z[j] + 12.0 * pa_xx[j] * fl1_fz * pb_z[j] * fl1_fx - fl1_fz * fl1_fga * pb_zzz[j] + 4.0 * fl1_fz * fl1_fx * pb_zzz[j] + 10.0 * pa_xx[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF_10_20(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(9 * idx + 4);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xy_xxx = primBuffer.data(60 * idx + 10);

            auto t_xy_xxy = primBuffer.data(60 * idx + 11);

            auto t_xy_xxz = primBuffer.data(60 * idx + 12);

            auto t_xy_xyy = primBuffer.data(60 * idx + 13);

            auto t_xy_xyz = primBuffer.data(60 * idx + 14);

            auto t_xy_xzz = primBuffer.data(60 * idx + 15);

            auto t_xy_yyy = primBuffer.data(60 * idx + 16);

            auto t_xy_yyz = primBuffer.data(60 * idx + 17);

            auto t_xy_yzz = primBuffer.data(60 * idx + 18);

            auto t_xy_zzz = primBuffer.data(60 * idx + 19);

            // Batch of Integrals (10,20)

            #pragma omp simd aligned(fgb, fx, fz, pa_x, pa_xy, pa_y, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_xy_xxx, t_xy_xxy, t_xy_xxz, t_xy_xyy, t_xy_xyz, t_xy_xzz, \
                                     t_xy_yyy, t_xy_yyz, t_xy_yzz, t_xy_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xy_xxx[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] + 1.5 * pa_xy[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_y[j] * pb_xx[j] + pa_xy[j] * pb_xxx[j]);

                t_xy_xxx[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb + 4.5 * fl2_fx * fl1_fz * pa_y[j] - 3.0 * pa_xy[j] * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_xy[j] * fl1_fz * pb_x[j] * fl1_fx + 12.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xx[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xxx[j]);

                t_xy_xxy[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * fl2_fx * pb_x[j] + 0.5 * pa_xy[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_y[j] * pb_xy[j] + pa_xy[j] * pb_xxy[j]);

                t_xy_xxy[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_x[j] - pa_xy[j] * fl1_fz * fl1_fgb * pb_y[j] + 4.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_y[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] + 8.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xy[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xxy[j]);

                t_xy_xxz[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl1_fx * pb_z[j] + fl1_fx * pa_y[j] * pb_xz[j] + pa_xy[j] * pb_xxz[j]);

                t_xy_xxz[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xz[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xxz[j]);

                t_xy_xyy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] + 0.5 * fl2_fx * pb_y[j] + 0.5 * pa_xy[j] * pb_x[j] * fl1_fx + pa_x[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_y[j] * pb_yy[j] + pa_xy[j] * pb_xyy[j]);

                t_xy_xyy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_y[j] + 3.0 * fl2_fx * fl1_fz * pb_y[j] - pa_xy[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_xy[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yy[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xyy[j]);

                t_xy_xyz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yz[j] + pa_xy[j] * pb_xyz[j]);

                t_xy_xyz[j] += fl_r_0_0 * (1.5 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yz[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xyz[j]);

                t_xy_xzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] + 0.5 * pa_xy[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_y[j] * pb_zz[j] + pa_xy[j] * pb_xzz[j]);

                t_xy_xzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_y[j] - pa_xy[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_xy[j] * fl1_fz * pb_x[j] * fl1_fx + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_zz[j] + 10.0 * pa_xy[j] * fl1_fz * pb_xzz[j]);

                t_xy_yyy[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 1.5 * pa_xy[j] * pb_y[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yy[j] + pa_xy[j] * pb_yyy[j]);

                t_xy_yyy[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 4.5 * pa_x[j] * fl1_fz * fl2_fx - 3.0 * pa_xy[j] * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_xy[j] * fl1_fz * pb_y[j] * fl1_fx + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_xy[j] * fl1_fz * pb_yyy[j]);

                t_xy_yyz[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl1_fx * pb_z[j] + pa_x[j] * fl1_fx * pb_yz[j] + pa_xy[j] * pb_yyz[j]);

                t_xy_yyz[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_xy[j] * fl1_fz * pb_yyz[j]);

                t_xy_yzz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * pa_xy[j] * pb_y[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_zz[j] + pa_xy[j] * pb_yzz[j]);

                t_xy_yzz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx - pa_xy[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.0 * pa_xy[j] * fl1_fz * pb_y[j] * fl1_fx + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_xy[j] * fl1_fz * pb_yzz[j]);

                t_xy_zzz[j] = fl_s_0_0 * (1.5 * pa_xy[j] * pb_z[j] * fl1_fx + pa_xy[j] * pb_zzz[j]);

                t_xy_zzz[j] += fl_r_0_0 * (-3.0 * pa_xy[j] * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_xy[j] * fl1_fz * pb_z[j] * fl1_fx + 10.0 * pa_xy[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF_20_30(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(9 * idx + 5);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xz_xxx = primBuffer.data(60 * idx + 20);

            auto t_xz_xxy = primBuffer.data(60 * idx + 21);

            auto t_xz_xxz = primBuffer.data(60 * idx + 22);

            auto t_xz_xyy = primBuffer.data(60 * idx + 23);

            auto t_xz_xyz = primBuffer.data(60 * idx + 24);

            auto t_xz_xzz = primBuffer.data(60 * idx + 25);

            auto t_xz_yyy = primBuffer.data(60 * idx + 26);

            auto t_xz_yyz = primBuffer.data(60 * idx + 27);

            auto t_xz_yzz = primBuffer.data(60 * idx + 28);

            auto t_xz_zzz = primBuffer.data(60 * idx + 29);

            // Batch of Integrals (20,30)

            #pragma omp simd aligned(fgb, fx, fz, pa_x, pa_xz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_xz_xxx, t_xz_xxy, t_xz_xxz, t_xz_xyy, t_xz_xyz, t_xz_xzz, \
                                     t_xz_yyy, t_xz_yyz, t_xz_yzz, t_xz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xz_xxx[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] + 1.5 * pa_xz[j] * pb_x[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_xx[j] + pa_xz[j] * pb_xxx[j]);

                t_xz_xxx[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 4.5 * fl2_fx * fl1_fz * pa_z[j] - 3.0 * pa_xz[j] * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_xz[j] * fl1_fz * pb_x[j] * fl1_fx + 12.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xx[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xxx[j]);

                t_xz_xxy[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl1_fx * pb_y[j] + fl1_fx * pa_z[j] * pb_xy[j] + pa_xz[j] * pb_xxy[j]);

                t_xz_xxy[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fz * fl1_fgb * pb_y[j] + 4.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_y[j] + 8.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xy[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xxy[j]);

                t_xz_xxz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * fl2_fx * pb_x[j] + 0.5 * pa_xz[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] + fl1_fx * pa_z[j] * pb_xz[j] + pa_xz[j] * pb_xxz[j]);

                t_xz_xxz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_x[j] - pa_xz[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_z[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] + 8.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xz[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xxz[j]);

                t_xz_xyy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * pa_xz[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_yy[j] + pa_xz[j] * pb_xyy[j]);

                t_xz_xyy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] - pa_xz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_xz[j] * fl1_fz * pb_x[j] * fl1_fx + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yy[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xyy[j]);

                t_xz_xyz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_z[j] * pb_yz[j] + pa_xz[j] * pb_xyz[j]);

                t_xz_xyz[j] += fl_r_0_0 * (1.5 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yz[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xyz[j]);

                t_xz_xzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * fl2_fx * pb_z[j] + 0.5 * pa_xz[j] * pb_x[j] * fl1_fx + pa_x[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zz[j] + pa_xz[j] * pb_xzz[j]);

                t_xz_xzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 3.0 * fl2_fx * fl1_fz * pb_z[j] - pa_xz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_xz[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zz[j] + 10.0 * pa_xz[j] * fl1_fz * pb_xzz[j]);

                t_xz_yyy[j] = fl_s_0_0 * (1.5 * pa_xz[j] * pb_y[j] * fl1_fx + pa_xz[j] * pb_yyy[j]);

                t_xz_yyy[j] += fl_r_0_0 * (-3.0 * pa_xz[j] * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_xz[j] * fl1_fz * pb_y[j] * fl1_fx + 10.0 * pa_xz[j] * fl1_fz * pb_yyy[j]);

                t_xz_yyz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * pa_xz[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_yy[j] + pa_xz[j] * pb_yyz[j]);

                t_xz_yyz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx - pa_xz[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_z[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_xz[j] * fl1_fz * pb_yyz[j]);

                t_xz_yzz[j] = fl_s_0_0 * (0.5 * pa_xz[j] * pb_y[j] * fl1_fx + pa_x[j] * fl1_fx * pb_yz[j] + pa_xz[j] * pb_yzz[j]);

                t_xz_yzz[j] += fl_r_0_0 * (-pa_xz[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.0 * pa_xz[j] * fl1_fz * pb_y[j] * fl1_fx + 8.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_xz[j] * fl1_fz * pb_yzz[j]);

                t_xz_zzz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 1.5 * pa_xz[j] * pb_z[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_zz[j] + pa_xz[j] * pb_zzz[j]);

                t_xz_zzz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb + 4.5 * pa_x[j] * fl1_fz * fl2_fx - 3.0 * pa_xz[j] * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_xz[j] * fl1_fz * pb_z[j] * fl1_fx + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_xz[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF_30_40(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(9 * idx + 6);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yy_xxx = primBuffer.data(60 * idx + 30);

            auto t_yy_xxy = primBuffer.data(60 * idx + 31);

            auto t_yy_xxz = primBuffer.data(60 * idx + 32);

            auto t_yy_xyy = primBuffer.data(60 * idx + 33);

            auto t_yy_xyz = primBuffer.data(60 * idx + 34);

            auto t_yy_xzz = primBuffer.data(60 * idx + 35);

            auto t_yy_yyy = primBuffer.data(60 * idx + 36);

            auto t_yy_yyz = primBuffer.data(60 * idx + 37);

            auto t_yy_yzz = primBuffer.data(60 * idx + 38);

            auto t_yy_zzz = primBuffer.data(60 * idx + 39);

            // Batch of Integrals (30,40)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_yy_xxx, t_yy_xxy, t_yy_xxz, t_yy_xyy, t_yy_xyz, t_yy_xzz, \
                                     t_yy_yyy, t_yy_yyz, t_yy_yzz, t_yy_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_yy_xxx[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 1.5 * pa_yy[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pb_xxx[j] + pa_yy[j] * pb_xxx[j]);

                t_yy_xxx[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - 3.0 * pa_yy[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_x[j] + 12.0 * pa_yy[j] * fl1_fz * pb_x[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxx[j] + 4.0 * fl1_fz * fl1_fx * pb_xxx[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xxx[j]);

                t_yy_xxy[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx + 0.25 * fl2_fx * pb_y[j] + 0.5 * pa_yy[j] * fl1_fx * pb_y[j] + pa_y[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pb_xxy[j] + pa_yy[j] * pb_xxy[j]);

                t_yy_xxy[j] += fl_r_0_0 * (-pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_y[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_y[j] - pa_yy[j] * fl1_fz * fl1_fgb * pb_y[j] + 1.5 * fl1_fz * fl2_fx * pb_y[j] + 4.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_y[j] + 8.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xx[j] - fl1_fz * fl1_fga * pb_xxy[j] + 4.0 * fl1_fz * fl1_fx * pb_xxy[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xxy[j]);

                t_yy_xxz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pb_xxz[j] + pa_yy[j] * pb_xxz[j]);

                t_yy_xxz[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_yy[j] * fl1_fz * fl1_fgb * pb_z[j] + 1.5 * fl1_fz * fl2_fx * pb_z[j] + 4.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pb_xxz[j] + 4.0 * fl1_fz * fl1_fx * pb_xxz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xxz[j]);

                t_yy_xyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 0.5 * pa_yy[j] * pb_x[j] * fl1_fx + 2.0 * pa_y[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pb_xyy[j] + pa_yy[j] * pb_xyy[j]);

                t_yy_xyy[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_x[j] - 0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_yy[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_yy[j] * fl1_fz * pb_x[j] * fl1_fx + 16.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xy[j] - fl1_fz * fl1_fga * pb_xyy[j] + 4.0 * fl1_fz * fl1_fx * pb_xyy[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xyy[j]);

                t_yy_xyz[j] = fl_s_0_0 * (pa_y[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pb_xyz[j] + pa_yy[j] * pb_xyz[j]);

                t_yy_xyz[j] += fl_r_0_0 * (8.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xz[j] - fl1_fz * fl1_fga * pb_xyz[j] + 4.0 * fl1_fz * fl1_fx * pb_xyz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xyz[j]);

                t_yy_xzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_x[j] + 0.5 * pa_yy[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pb_xzz[j] + pa_yy[j] * pb_xzz[j]);

                t_yy_xzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_yy[j] * pb_x[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_x[j] + 4.0 * pa_yy[j] * fl1_fz * pb_x[j] * fl1_fx - fl1_fz * fl1_fga * pb_xzz[j] + 4.0 * fl1_fz * fl1_fx * pb_xzz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_xzz[j]);

                t_yy_yyy[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl2_fx + 2.25 * fl2_fx * pb_y[j] + 1.5 * pa_yy[j] * pb_y[j] * fl1_fx + 3.0 * pa_y[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pb_yyy[j] + pa_yy[j] * pb_yyy[j]);

                t_yy_yyy[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 9.0 * pa_y[j] * fl1_fz * fl2_fx + 13.5 * fl2_fx * fl1_fz * pb_y[j] - 1.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - 3.0 * pa_yy[j] * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_yy[j] * fl1_fz * pb_y[j] * fl1_fx + 24.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yy[j] - fl1_fz * fl1_fga * pb_yyy[j] + 4.0 * fl1_fz * fl1_fx * pb_yyy[j] + 10.0 * pa_yy[j] * fl1_fz * pb_yyy[j]);

                t_yy_yyz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 0.5 * pa_yy[j] * fl1_fx * pb_z[j] + 2.0 * pa_y[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pb_yyz[j] + pa_yy[j] * pb_yyz[j]);

                t_yy_yyz[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_z[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_yy[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_z[j] + 16.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yz[j] - fl1_fz * fl1_fga * pb_yyz[j] + 4.0 * fl1_fz * fl1_fx * pb_yyz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_yyz[j]);

                t_yy_yzz[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx + 0.25 * fl2_fx * pb_y[j] + 0.5 * pa_yy[j] * pb_y[j] * fl1_fx + pa_y[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pb_yzz[j] + pa_yy[j] * pb_yzz[j]);

                t_yy_yzz[j] += fl_r_0_0 * (-pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_y[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - pa_yy[j] * pb_y[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_y[j] + 4.0 * pa_yy[j] * fl1_fz * pb_y[j] * fl1_fx + 8.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zz[j] - fl1_fz * fl1_fga * pb_yzz[j] + 4.0 * fl1_fz * fl1_fx * pb_yzz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_yzz[j]);

                t_yy_zzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 1.5 * pa_yy[j] * pb_z[j] * fl1_fx + 0.5 * fl1_fx * pb_zzz[j] + pa_yy[j] * pb_zzz[j]);

                t_yy_zzz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_z[j] * fl1_fx - 3.0 * pa_yy[j] * pb_z[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_z[j] + 12.0 * pa_yy[j] * fl1_fz * pb_z[j] * fl1_fx - fl1_fz * fl1_fga * pb_zzz[j] + 4.0 * fl1_fz * fl1_fx * pb_zzz[j] + 10.0 * pa_yy[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF_40_50(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(9 * idx + 7);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yz_xxx = primBuffer.data(60 * idx + 40);

            auto t_yz_xxy = primBuffer.data(60 * idx + 41);

            auto t_yz_xxz = primBuffer.data(60 * idx + 42);

            auto t_yz_xyy = primBuffer.data(60 * idx + 43);

            auto t_yz_xyz = primBuffer.data(60 * idx + 44);

            auto t_yz_xzz = primBuffer.data(60 * idx + 45);

            auto t_yz_yyy = primBuffer.data(60 * idx + 46);

            auto t_yz_yyz = primBuffer.data(60 * idx + 47);

            auto t_yz_yzz = primBuffer.data(60 * idx + 48);

            auto t_yz_zzz = primBuffer.data(60 * idx + 49);

            // Batch of Integrals (40,50)

            #pragma omp simd aligned(fgb, fx, fz, pa_y, pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_yz_xxx, t_yz_xxy, t_yz_xxz, t_yz_xyy, t_yz_xyz, t_yz_xzz, \
                                     t_yz_yyy, t_yz_yyz, t_yz_yzz, t_yz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_yz_xxx[j] = fl_s_0_0 * (1.5 * pa_yz[j] * pb_x[j] * fl1_fx + pa_yz[j] * pb_xxx[j]);

                t_yz_xxx[j] += fl_r_0_0 * (-3.0 * pa_yz[j] * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_yz[j] * fl1_fz * pb_x[j] * fl1_fx + 10.0 * pa_yz[j] * fl1_fz * pb_xxx[j]);

                t_yz_xxy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * pa_yz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] + pa_yz[j] * pb_xxy[j]);

                t_yz_xxy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] - pa_yz[j] * fl1_fz * fl1_fgb * pb_y[j] + 4.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_y[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xx[j] + 10.0 * pa_yz[j] * fl1_fz * pb_xxy[j]);

                t_yz_xxz[j] = fl_s_0_0 * (0.25 * pa_y[j] * fl2_fx + 0.5 * pa_yz[j] * fl1_fx * pb_z[j] + 0.5 * pa_y[j] * fl1_fx * pb_xx[j] + pa_yz[j] * pb_xxz[j]);

                t_yz_xxz[j] += fl_r_0_0 * (-0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_y[j] * fl1_fz * fl2_fx - pa_yz[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_z[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_yz[j] * fl1_fz * pb_xxz[j]);

                t_yz_xyy[j] = fl_s_0_0 * (0.5 * pa_yz[j] * pb_x[j] * fl1_fx + fl1_fx * pa_z[j] * pb_xy[j] + pa_yz[j] * pb_xyy[j]);

                t_yz_xyy[j] += fl_r_0_0 * (-pa_yz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_yz[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xy[j] + 10.0 * pa_yz[j] * fl1_fz * pb_xyy[j]);

                t_yz_xyz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_x[j] + 0.5 * pa_y[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_z[j] * pb_xz[j] + pa_yz[j] * pb_xyz[j]);

                t_yz_xyz[j] += fl_r_0_0 * (1.5 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xz[j] + 10.0 * pa_yz[j] * fl1_fz * pb_xyz[j]);

                t_yz_xzz[j] = fl_s_0_0 * (0.5 * pa_yz[j] * pb_x[j] * fl1_fx + pa_y[j] * fl1_fx * pb_xz[j] + pa_yz[j] * pb_xzz[j]);

                t_yz_xzz[j] += fl_r_0_0 * (-pa_yz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_yz[j] * fl1_fz * pb_x[j] * fl1_fx + 8.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_yz[j] * fl1_fz * pb_xzz[j]);

                t_yz_yyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] + 1.5 * pa_yz[j] * pb_y[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_yy[j] + pa_yz[j] * pb_yyy[j]);

                t_yz_yyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 4.5 * fl2_fx * fl1_fz * pa_z[j] - 3.0 * pa_yz[j] * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_yz[j] * fl1_fz * pb_y[j] * fl1_fx + 12.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yy[j] + 10.0 * pa_yz[j] * fl1_fz * pb_yyy[j]);

                t_yz_yyz[j] = fl_s_0_0 * (0.25 * pa_y[j] * fl2_fx + 0.5 * fl2_fx * pb_y[j] + 0.5 * pa_yz[j] * fl1_fx * pb_z[j] + 0.5 * pa_y[j] * fl1_fx * pb_yy[j] + fl1_fx * pa_z[j] * pb_yz[j] + pa_yz[j] * pb_yyz[j]);

                t_yz_yyz[j] += fl_r_0_0 * (-0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 1.5 * pa_y[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_y[j] - pa_yz[j] * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_z[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yy[j] + 8.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yz[j] + 10.0 * pa_yz[j] * fl1_fz * pb_yyz[j]);

                t_yz_yzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * fl2_fx * pb_z[j] + 0.5 * pa_yz[j] * pb_y[j] * fl1_fx + pa_y[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zz[j] + pa_yz[j] * pb_yzz[j]);

                t_yz_yzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 3.0 * fl2_fx * fl1_fz * pb_z[j] - pa_yz[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.0 * pa_yz[j] * fl1_fz * pb_y[j] * fl1_fx + 8.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zz[j] + 10.0 * pa_yz[j] * fl1_fz * pb_yzz[j]);

                t_yz_zzz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx + 1.5 * pa_yz[j] * pb_z[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_zz[j] + pa_yz[j] * pb_zzz[j]);

                t_yz_zzz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb + 4.5 * pa_y[j] * fl1_fz * fl2_fx - 3.0 * pa_yz[j] * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_yz[j] * fl1_fz * pb_z[j] * fl1_fx + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_yz[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDF_50_60(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_zz = paDistances.data(9 * idx + 8);

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

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_zz_xxx = primBuffer.data(60 * idx + 50);

            auto t_zz_xxy = primBuffer.data(60 * idx + 51);

            auto t_zz_xxz = primBuffer.data(60 * idx + 52);

            auto t_zz_xyy = primBuffer.data(60 * idx + 53);

            auto t_zz_xyz = primBuffer.data(60 * idx + 54);

            auto t_zz_xzz = primBuffer.data(60 * idx + 55);

            auto t_zz_yyy = primBuffer.data(60 * idx + 56);

            auto t_zz_yyz = primBuffer.data(60 * idx + 57);

            auto t_zz_yzz = primBuffer.data(60 * idx + 58);

            auto t_zz_zzz = primBuffer.data(60 * idx + 59);

            // Batch of Integrals (50,60)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_z, pa_zz, pb_x, pb_xx, pb_xxx, pb_xxy, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_xzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, \
                                     r_0_0, s_0_0, t_zz_xxx, t_zz_xxy, t_zz_xxz, t_zz_xyy, t_zz_xyz, t_zz_xzz, \
                                     t_zz_yyy, t_zz_yyz, t_zz_yzz, t_zz_zzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_zz_xxx[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 1.5 * pa_zz[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pb_xxx[j] + pa_zz[j] * pb_xxx[j]);

                t_zz_xxx[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - 3.0 * pa_zz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_x[j] + 12.0 * pa_zz[j] * fl1_fz * pb_x[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxx[j] + 4.0 * fl1_fz * fl1_fx * pb_xxx[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xxx[j]);

                t_zz_xxy[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_y[j] + 0.5 * pa_zz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pb_xxy[j] + pa_zz[j] * pb_xxy[j]);

                t_zz_xxy[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_y[j] - pa_zz[j] * fl1_fz * fl1_fgb * pb_y[j] + 1.5 * fl1_fz * fl2_fx * pb_y[j] + 4.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pb_xxy[j] + 4.0 * fl1_fz * fl1_fx * pb_xxy[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xxy[j]);

                t_zz_xxz[j] = fl_s_0_0 * (0.5 * pa_z[j] * fl2_fx + 0.25 * fl2_fx * pb_z[j] + 0.5 * pa_zz[j] * fl1_fx * pb_z[j] + pa_z[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pb_xxz[j] + pa_zz[j] * pb_xxz[j]);

                t_zz_xxz[j] += fl_r_0_0 * (-pa_z[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_z[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_zz[j] * fl1_fz * fl1_fgb * pb_z[j] + 1.5 * fl1_fz * fl2_fx * pb_z[j] + 4.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xx[j] - fl1_fz * fl1_fga * pb_xxz[j] + 4.0 * fl1_fz * fl1_fx * pb_xxz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xxz[j]);

                t_zz_xyy[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_x[j] + 0.5 * pa_zz[j] * pb_x[j] * fl1_fx + 0.5 * fl1_fx * pb_xyy[j] + pa_zz[j] * pb_xyy[j]);

                t_zz_xyy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_zz[j] * pb_x[j] * fl1_fz * fl1_fgb + 1.5 * fl1_fz * fl2_fx * pb_x[j] + 4.0 * pa_zz[j] * fl1_fz * pb_x[j] * fl1_fx - fl1_fz * fl1_fga * pb_xyy[j] + 4.0 * fl1_fz * fl1_fx * pb_xyy[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xyy[j]);

                t_zz_xyz[j] = fl_s_0_0 * (pa_z[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pb_xyz[j] + pa_zz[j] * pb_xyz[j]);

                t_zz_xyz[j] += fl_r_0_0 * (8.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xy[j] - fl1_fz * fl1_fga * pb_xyz[j] + 4.0 * fl1_fz * fl1_fx * pb_xyz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xyz[j]);

                t_zz_xzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 0.5 * pa_zz[j] * pb_x[j] * fl1_fx + 2.0 * pa_z[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pb_xzz[j] + pa_zz[j] * pb_xzz[j]);

                t_zz_xzz[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_x[j] - 0.5 * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_x[j] * fl1_fx - pa_zz[j] * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_zz[j] * fl1_fz * pb_x[j] * fl1_fx + 16.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xz[j] - fl1_fz * fl1_fga * pb_xzz[j] + 4.0 * fl1_fz * fl1_fx * pb_xzz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_xzz[j]);

                t_zz_yyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 1.5 * pa_zz[j] * pb_y[j] * fl1_fx + 0.5 * fl1_fx * pb_yyy[j] + pa_zz[j] * pb_yyy[j]);

                t_zz_yyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - 3.0 * pa_zz[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.5 * fl1_fz * fl2_fx * pb_y[j] + 12.0 * pa_zz[j] * fl1_fz * pb_y[j] * fl1_fx - fl1_fz * fl1_fga * pb_yyy[j] + 4.0 * fl1_fz * fl1_fx * pb_yyy[j] + 10.0 * pa_zz[j] * fl1_fz * pb_yyy[j]);

                t_zz_yyz[j] = fl_s_0_0 * (0.5 * pa_z[j] * fl2_fx + 0.25 * fl2_fx * pb_z[j] + 0.5 * pa_zz[j] * fl1_fx * pb_z[j] + pa_z[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pb_yyz[j] + pa_zz[j] * pb_yyz[j]);

                t_zz_yyz[j] += fl_r_0_0 * (-pa_z[j] * fl1_fx * fl1_fz * fl1_fgb + 3.0 * pa_z[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_zz[j] * fl1_fz * fl1_fgb * pb_z[j] + 1.5 * fl1_fz * fl2_fx * pb_z[j] + 4.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_z[j] + 8.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yy[j] - fl1_fz * fl1_fga * pb_yyz[j] + 4.0 * fl1_fz * fl1_fx * pb_yyz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_yyz[j]);

                t_zz_yzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 0.5 * pa_zz[j] * pb_y[j] * fl1_fx + 2.0 * pa_z[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pb_yzz[j] + pa_zz[j] * pb_yzz[j]);

                t_zz_yzz[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pb_y[j] - 0.5 * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_y[j] * fl1_fx - pa_zz[j] * pb_y[j] * fl1_fz * fl1_fgb + 4.0 * pa_zz[j] * fl1_fz * pb_y[j] * fl1_fx + 16.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yz[j] - fl1_fz * fl1_fga * pb_yzz[j] + 4.0 * fl1_fz * fl1_fx * pb_yzz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_yzz[j]);

                t_zz_zzz[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl2_fx + 2.25 * fl2_fx * pb_z[j] + 1.5 * pa_zz[j] * pb_z[j] * fl1_fx + 3.0 * pa_z[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pb_zzz[j] + pa_zz[j] * pb_zzz[j]);

                t_zz_zzz[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb + 9.0 * pa_z[j] * fl1_fz * fl2_fx + 13.5 * fl2_fx * fl1_fz * pb_z[j] - 1.5 * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_z[j] * fl1_fx - 3.0 * pa_zz[j] * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_zz[j] * fl1_fz * pb_z[j] * fl1_fx + 24.0 * pa_z[j] * fl1_fz * fl1_fx * pb_zz[j] - fl1_fz * fl1_fga * pb_zzz[j] + 4.0 * fl1_fz * fl1_fx * pb_zzz[j] + 10.0 * pa_zz[j] * fl1_fz * pb_zzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        kinrecfunc::compKineticEnergyForFD_0_10(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForFD_10_20(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForFD_20_30(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForFD_30_40(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForFD_40_50(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForFD_50_60(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compKineticEnergyForFD_0_10(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(19 * idx + 3);

            auto pa_xy = paDistances.data(19 * idx + 4);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxx = paDistances.data(19 * idx + 9);

            auto pa_xxy = paDistances.data(19 * idx + 10);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxx_xx = primBuffer.data(60 * idx);

            auto t_xxx_xy = primBuffer.data(60 * idx + 1);

            auto t_xxx_xz = primBuffer.data(60 * idx + 2);

            auto t_xxx_yy = primBuffer.data(60 * idx + 3);

            auto t_xxx_yz = primBuffer.data(60 * idx + 4);

            auto t_xxx_zz = primBuffer.data(60 * idx + 5);

            auto t_xxy_xx = primBuffer.data(60 * idx + 6);

            auto t_xxy_xy = primBuffer.data(60 * idx + 7);

            auto t_xxy_xz = primBuffer.data(60 * idx + 8);

            auto t_xxy_yy = primBuffer.data(60 * idx + 9);

            // Batch of Integrals (0,10)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxy, pa_xy, pa_y, pb_x, pb_xx, pb_xy, pb_xz, \
                                     pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xxx_xx, t_xxx_xy, t_xxx_xz, \
                                     t_xxx_yy, t_xxx_yz, t_xxx_zz, t_xxy_xx, t_xxy_xy, t_xxy_xz, t_xxy_yy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xxx_xx[j] = fl_s_0_0 * (2.25 * pa_x[j] * fl2_fx + 1.5 * fl2_fx * pb_x[j] + 0.5 * pa_xxx[j] * fl1_fx + 3.0 * pa_xx[j] * fl1_fx * pb_x[j] + 1.5 * pa_x[j] * fl1_fx * pb_xx[j] + pa_xxx[j] * pb_xx[j]);

                t_xxx_xx[j] += fl_r_0_0 * (13.5 * pa_x[j] * fl2_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - pa_xxx[j] * fl1_fz * fl1_fgb + 9.0 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_xxx[j] * fl1_fz * fl1_fx + 24.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_xx[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_xx[j]);

                t_xxx_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 1.5 * pa_xx[j] * fl1_fx * pb_y[j] + 1.5 * pa_x[j] * fl1_fx * pb_xy[j] + pa_xxx[j] * pb_xy[j]);

                t_xxx_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 4.5 * fl2_fx * fl1_fz * pb_y[j] + 12.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_xy[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_xy[j]);

                t_xxx_xz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 1.5 * pa_xx[j] * fl1_fx * pb_z[j] + 1.5 * pa_x[j] * fl1_fx * pb_xz[j] + pa_xxx[j] * pb_xz[j]);

                t_xxx_xz[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 4.5 * fl2_fx * fl1_fz * pb_z[j] + 12.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_xz[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_xz[j]);

                t_xxx_yy[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 0.5 * pa_xxx[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yy[j] + pa_xxx[j] * pb_yy[j]);

                t_xxx_yy[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xxx[j] * fl1_fz * fl1_fgb + 4.5 * pa_x[j] * fl1_fz * fl2_fx + 4.0 * pa_xxx[j] * fl1_fz * fl1_fx - 3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_yy[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_yy[j]);

                t_xxx_yz[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl1_fx * pb_yz[j] + pa_xxx[j] * pb_yz[j]);

                t_xxx_yz[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_yz[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_yz[j]);

                t_xxx_zz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 0.5 * pa_xxx[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_zz[j] + pa_xxx[j] * pb_zz[j]);

                t_xxx_zz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xxx[j] * fl1_fz * fl1_fgb + 4.5 * pa_x[j] * fl1_fz * fl2_fx + 4.0 * pa_xxx[j] * fl1_fz * fl1_fx - 3.0 * pa_x[j] * fl1_fz * fl1_fga * pb_zz[j] + 12.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_xxx[j] * fl1_fz * pb_zz[j]);

                t_xxy_xx[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] + 0.5 * pa_xxy[j] * fl1_fx + 2.0 * pa_xy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_y[j] * pb_xx[j] + pa_xxy[j] * pb_xx[j]);

                t_xxy_xx[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pa_y[j] - 0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx - pa_xxy[j] * fl1_fz * fl1_fgb + 4.0 * pa_xxy[j] * fl1_fz * fl1_fx + 16.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fz * fl1_fga * pa_y[j] * pb_xx[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xx[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_xx[j]);

                t_xxy_xy[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx + 0.25 * fl2_fx * pb_x[j] + 0.5 * pa_xx[j] * fl1_fx * pb_x[j] + pa_xy[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_y[j] * pb_xy[j] + pa_xxy[j] * pb_xy[j]);

                t_xxy_xy[j] += fl_r_0_0 * (3.0 * pa_x[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_x[j] + 1.5 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_x[j] + 8.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fz * fl1_fga * pa_y[j] * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xy[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_xy[j]);

                t_xxy_xz[j] = fl_s_0_0 * (pa_xy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_y[j] * pb_xz[j] + pa_xxy[j] * pb_xz[j]);

                t_xxy_xz[j] += fl_r_0_0 * (8.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fz * fl1_fga * pa_y[j] * pb_xz[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xz[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_xz[j]);

                t_xxy_yy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] + 0.5 * fl2_fx * pb_y[j] + 0.5 * pa_xxy[j] * fl1_fx + pa_xx[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_y[j] * pb_yy[j] + pa_xxy[j] * pb_yy[j]);

                t_xxy_yy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx - fl1_fz * fl1_fga * fl1_fx * pb_y[j] - pa_xxy[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_y[j] + 3.0 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_xxy[j] * fl1_fz * fl1_fx + 8.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pa_y[j] * pb_yy[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yy[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_yy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD_10_20(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(19 * idx + 3);

            auto pa_xy = paDistances.data(19 * idx + 4);

            auto pa_xz = paDistances.data(19 * idx + 5);

            auto pa_yy = paDistances.data(19 * idx + 6);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxy = paDistances.data(19 * idx + 10);

            auto pa_xxz = paDistances.data(19 * idx + 11);

            auto pa_xyy = paDistances.data(19 * idx + 12);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxy_yz = primBuffer.data(60 * idx + 10);

            auto t_xxy_zz = primBuffer.data(60 * idx + 11);

            auto t_xxz_xx = primBuffer.data(60 * idx + 12);

            auto t_xxz_xy = primBuffer.data(60 * idx + 13);

            auto t_xxz_xz = primBuffer.data(60 * idx + 14);

            auto t_xxz_yy = primBuffer.data(60 * idx + 15);

            auto t_xxz_yz = primBuffer.data(60 * idx + 16);

            auto t_xxz_zz = primBuffer.data(60 * idx + 17);

            auto t_xyy_xx = primBuffer.data(60 * idx + 18);

            auto t_xyy_xy = primBuffer.data(60 * idx + 19);

            // Batch of Integrals (10,20)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxz, pa_xy, pa_xyy, pa_xz, pa_y, pa_yy, pa_z, \
                                     pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xxy_yz, \
                                     t_xxy_zz, t_xxz_xx, t_xxz_xy, t_xxz_xz, t_xxz_yy, t_xxz_yz, t_xxz_zz, t_xyy_xx, \
                                     t_xyy_xy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xxy_yz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_z[j] + 0.5 * pa_xx[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_y[j] * pb_yz[j] + pa_xxy[j] * pb_yz[j]);

                t_xxy_yz[j] += fl_r_0_0 * (-0.5 * fl1_fz * fl1_fga * fl1_fx * pb_z[j] + 1.5 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pa_y[j] * pb_yz[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yz[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_yz[j]);

                t_xxy_zz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] + 0.5 * pa_xxy[j] * fl1_fx + 0.5 * fl1_fx * pa_y[j] * pb_zz[j] + pa_xxy[j] * pb_zz[j]);

                t_xxy_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx - pa_xxy[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_y[j] + 4.0 * pa_xxy[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pa_y[j] * pb_zz[j] + 4.0 * fl1_fx * fl1_fz * pa_y[j] * pb_zz[j] + 10.0 * pa_xxy[j] * fl1_fz * pb_zz[j]);

                t_xxz_xx[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] + 0.5 * pa_xxz[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] + pa_xxz[j] * pb_xx[j]);

                t_xxz_xx[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pa_z[j] - 0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - pa_xxz[j] * fl1_fz * fl1_fgb + 4.0 * pa_xxz[j] * fl1_fz * fl1_fx + 16.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fz * fl1_fga * pa_z[j] * pb_xx[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xx[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_xx[j]);

                t_xxz_xy[j] = fl_s_0_0 * (pa_xz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_z[j] * pb_xy[j] + pa_xxz[j] * pb_xy[j]);

                t_xxz_xy[j] += fl_r_0_0 * (8.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fz * fl1_fga * pa_z[j] * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xy[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_xy[j]);

                t_xxz_xz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx + 0.25 * fl2_fx * pb_x[j] + 0.5 * pa_xx[j] * fl1_fx * pb_x[j] + pa_xz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_z[j] * pb_xz[j] + pa_xxz[j] * pb_xz[j]);

                t_xxz_xz[j] += fl_r_0_0 * (3.0 * pa_x[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_x[j] + 1.5 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_x[j] + 8.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * pb_xz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xz[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_xz[j]);

                t_xxz_yy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * pa_xxz[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_yy[j] + pa_xxz[j] * pb_yy[j]);

                t_xxz_yy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - pa_xxz[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 4.0 * pa_xxz[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pa_z[j] * pb_yy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yy[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_yy[j]);

                t_xxz_yz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_y[j] + 0.5 * pa_xx[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_z[j] * pb_yz[j] + pa_xxz[j] * pb_yz[j]);

                t_xxz_yz[j] += fl_r_0_0 * (-0.5 * fl1_fz * fl1_fga * fl1_fx * pb_y[j] + 1.5 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fz * fl1_fga * pa_z[j] * pb_yz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yz[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_yz[j]);

                t_xxz_zz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * fl2_fx * pb_z[j] + 0.5 * pa_xxz[j] * fl1_fx + pa_xx[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_z[j] * pb_zz[j] + pa_xxz[j] * pb_zz[j]);

                t_xxz_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_xxz[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 3.0 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * pa_xxz[j] * fl1_fz * fl1_fx + 8.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * pb_zz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zz[j] + 10.0 * pa_xxz[j] * fl1_fz * pb_zz[j]);

                t_xyy_xx[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * fl2_fx * pb_x[j] + 0.5 * pa_xyy[j] * fl1_fx + fl1_fx * pa_yy[j] * pb_x[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] + pa_xyy[j] * pb_xx[j]);

                t_xyy_xx[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_x[j] - pa_xyy[j] * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_xyy[j] * fl1_fz * fl1_fx + 8.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_x[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xx[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_xx[j]);

                t_xyy_xy[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_y[j] + 0.25 * fl2_fx * pb_y[j] + pa_xy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yy[j] * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xy[j] + pa_xyy[j] * pb_xy[j]);

                t_xyy_xy[j] += fl_r_0_0 * (3.0 * fl2_fx * pa_y[j] * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 1.5 * fl2_fx * fl1_fz * pb_y[j] + 8.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_x[j] + 4.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_y[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xy[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_xy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD_20_30(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(19 * idx + 4);

            auto pa_xz = paDistances.data(19 * idx + 5);

            auto pa_yy = paDistances.data(19 * idx + 6);

            auto pa_yz = paDistances.data(19 * idx + 7);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xyy = paDistances.data(19 * idx + 12);

            auto pa_xyz = paDistances.data(19 * idx + 13);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xyy_xz = primBuffer.data(60 * idx + 20);

            auto t_xyy_yy = primBuffer.data(60 * idx + 21);

            auto t_xyy_yz = primBuffer.data(60 * idx + 22);

            auto t_xyy_zz = primBuffer.data(60 * idx + 23);

            auto t_xyz_xx = primBuffer.data(60 * idx + 24);

            auto t_xyz_xy = primBuffer.data(60 * idx + 25);

            auto t_xyz_xz = primBuffer.data(60 * idx + 26);

            auto t_xyz_yy = primBuffer.data(60 * idx + 27);

            auto t_xyz_yz = primBuffer.data(60 * idx + 28);

            auto t_xyz_zz = primBuffer.data(60 * idx + 29);

            // Batch of Integrals (20,30)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyz, pa_xz, pa_y, pa_yy, pa_yz, pa_z, pb_x, \
                                     pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xyy_xz, t_xyy_yy, \
                                     t_xyy_yz, t_xyy_zz, t_xyz_xx, t_xyz_xy, t_xyz_xz, t_xyz_yy, t_xyz_yz, t_xyz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xyy_xz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_z[j] + 0.5 * fl1_fx * pa_yy[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xz[j] + pa_xyy[j] * pb_xz[j]);

                t_xyy_xz[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 1.5 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_z[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_xz[j]);

                t_xyy_yy[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 0.5 * pa_xyy[j] * fl1_fx + 2.0 * pa_xy[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_yy[j] + pa_xyy[j] * pb_yy[j]);

                t_xyy_yy[j] += fl_r_0_0 * (4.5 * pa_x[j] * fl2_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xyy[j] * fl1_fz * fl1_fgb + 4.0 * pa_xyy[j] * fl1_fz * fl1_fx + 16.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_y[j] - pa_x[j] * fl1_fz * fl1_fga * pb_yy[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_yy[j]);

                t_xyy_yz[j] = fl_s_0_0 * (pa_xy[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_yz[j] + pa_xyy[j] * pb_yz[j]);

                t_xyy_yz[j] += fl_r_0_0 * (8.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_z[j] - pa_x[j] * fl1_fz * fl1_fga * pb_yz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_yz[j]);

                t_xyy_zz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * pa_xyy[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_zz[j] + pa_xyy[j] * pb_zz[j]);

                t_xyy_zz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xyy[j] * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 4.0 * pa_xyy[j] * fl1_fz * fl1_fx - pa_x[j] * fl1_fz * fl1_fga * pb_zz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_xyy[j] * fl1_fz * pb_zz[j]);

                t_xyz_xx[j] = fl_s_0_0 * (0.5 * pa_xyz[j] * fl1_fx + fl1_fx * pa_yz[j] * pb_x[j] + pa_xyz[j] * pb_xx[j]);

                t_xyz_xx[j] += fl_r_0_0 * (-pa_xyz[j] * fl1_fz * fl1_fgb + 4.0 * pa_xyz[j] * fl1_fz * fl1_fx + 8.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_x[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_xx[j]);

                t_xyz_xy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * pa_xz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yz[j] * pb_y[j] + pa_xyz[j] * pb_xy[j]);

                t_xyz_xy[j] += fl_r_0_0 * (1.5 * fl2_fx * fl1_fz * pa_z[j] + 4.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_x[j] + 4.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_y[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_xy[j]);

                t_xyz_xz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] + 0.5 * pa_xy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yz[j] * pb_z[j] + pa_xyz[j] * pb_xz[j]);

                t_xyz_xz[j] += fl_r_0_0 * (1.5 * fl2_fx * pa_y[j] * fl1_fz + 4.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_x[j] + 4.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_z[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_xz[j]);

                t_xyz_yy[j] = fl_s_0_0 * (0.5 * pa_xyz[j] * fl1_fx + pa_xz[j] * fl1_fx * pb_y[j] + pa_xyz[j] * pb_yy[j]);

                t_xyz_yy[j] += fl_r_0_0 * (-pa_xyz[j] * fl1_fz * fl1_fgb + 4.0 * pa_xyz[j] * fl1_fz * fl1_fx + 8.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_y[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_yy[j]);

                t_xyz_yz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * pa_xy[j] * fl1_fx * pb_y[j] + 0.5 * pa_xz[j] * fl1_fx * pb_z[j] + pa_xyz[j] * pb_yz[j]);

                t_xyz_yz[j] += fl_r_0_0 * (1.5 * pa_x[j] * fl2_fx * fl1_fz + 4.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_y[j] + 4.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_z[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_yz[j]);

                t_xyz_zz[j] = fl_s_0_0 * (0.5 * pa_xyz[j] * fl1_fx + pa_xy[j] * fl1_fx * pb_z[j] + pa_xyz[j] * pb_zz[j]);

                t_xyz_zz[j] += fl_r_0_0 * (-pa_xyz[j] * fl1_fz * fl1_fgb + 4.0 * pa_xyz[j] * fl1_fz * fl1_fx + 8.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_z[j] + 10.0 * pa_xyz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD_30_40(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(19 * idx);

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(19 * idx + 5);

            auto pa_yy = paDistances.data(19 * idx + 6);

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xzz = paDistances.data(19 * idx + 14);

            auto pa_yyy = paDistances.data(19 * idx + 15);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xzz_xx = primBuffer.data(60 * idx + 30);

            auto t_xzz_xy = primBuffer.data(60 * idx + 31);

            auto t_xzz_xz = primBuffer.data(60 * idx + 32);

            auto t_xzz_yy = primBuffer.data(60 * idx + 33);

            auto t_xzz_yz = primBuffer.data(60 * idx + 34);

            auto t_xzz_zz = primBuffer.data(60 * idx + 35);

            auto t_yyy_xx = primBuffer.data(60 * idx + 36);

            auto t_yyy_xy = primBuffer.data(60 * idx + 37);

            auto t_yyy_xz = primBuffer.data(60 * idx + 38);

            auto t_yyy_yy = primBuffer.data(60 * idx + 39);

            // Batch of Integrals (30,40)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_xzz, pa_y, pa_yy, pa_yyy, pa_z, pa_zz, pb_x, pb_xx, \
                                     pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xzz_xx, t_xzz_xy, \
                                     t_xzz_xz, t_xzz_yy, t_xzz_yz, t_xzz_zz, t_yyy_xx, t_yyy_xy, t_yyy_xz, t_yyy_yy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_xzz_xx[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * fl2_fx * pb_x[j] + 0.5 * pa_xzz[j] * fl1_fx + fl1_fx * pa_zz[j] * pb_x[j] + 0.5 * pa_x[j] * fl1_fx * pb_xx[j] + pa_xzz[j] * pb_xx[j]);

                t_xzz_xx[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_x[j] - pa_xzz[j] * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_xzz[j] * fl1_fz * fl1_fx + 8.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_x[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xx[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_xx[j]);

                t_xzz_xy[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_y[j] + 0.5 * fl1_fx * pa_zz[j] * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_xy[j] + pa_xzz[j] * pb_xy[j]);

                t_xzz_xy[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 1.5 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_y[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xy[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_xy[j]);

                t_xzz_xz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_z[j] + 0.25 * fl2_fx * pb_z[j] + pa_xz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_zz[j] * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_xz[j] + pa_xzz[j] * pb_xz[j]);

                t_xzz_xz[j] += fl_r_0_0 * (3.0 * fl2_fx * pa_z[j] * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 1.5 * fl2_fx * fl1_fz * pb_z[j] + 8.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_x[j] + 4.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_z[j] - pa_x[j] * fl1_fz * fl1_fga * pb_xz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_xz[j]);

                t_xzz_yy[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx + 0.5 * pa_xzz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_yy[j] + pa_xzz[j] * pb_yy[j]);

                t_xzz_yy[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xzz[j] * fl1_fz * fl1_fgb + 1.5 * pa_x[j] * fl1_fz * fl2_fx + 4.0 * pa_xzz[j] * fl1_fz * fl1_fx - pa_x[j] * fl1_fz * fl1_fga * pb_yy[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_yy[j]);

                t_xzz_yz[j] = fl_s_0_0 * (pa_xz[j] * fl1_fx * pb_y[j] + 0.5 * pa_x[j] * fl1_fx * pb_yz[j] + pa_xzz[j] * pb_yz[j]);

                t_xzz_yz[j] += fl_r_0_0 * (8.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_y[j] - pa_x[j] * fl1_fz * fl1_fga * pb_yz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_yz[j]);

                t_xzz_zz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx + 0.5 * pa_xzz[j] * fl1_fx + 2.0 * pa_xz[j] * fl1_fx * pb_z[j] + 0.5 * pa_x[j] * fl1_fx * pb_zz[j] + pa_xzz[j] * pb_zz[j]);

                t_xzz_zz[j] += fl_r_0_0 * (4.5 * pa_x[j] * fl2_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx - pa_xzz[j] * fl1_fz * fl1_fgb + 4.0 * pa_xzz[j] * fl1_fz * fl1_fx + 16.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_z[j] - pa_x[j] * fl1_fz * fl1_fga * pb_zz[j] + 4.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_xzz[j] * fl1_fz * pb_zz[j]);

                t_yyy_xx[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx + 0.5 * pa_yyy[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_xx[j] + pa_yyy[j] * pb_xx[j]);

                t_yyy_xx[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - pa_yyy[j] * fl1_fz * fl1_fgb + 4.5 * pa_y[j] * fl1_fz * fl2_fx + 4.0 * pa_yyy[j] * fl1_fz * fl1_fx - 3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_xx[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_xx[j]);

                t_yyy_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 1.5 * pa_yy[j] * fl1_fx * pb_x[j] + 1.5 * pa_y[j] * fl1_fx * pb_xy[j] + pa_yyy[j] * pb_xy[j]);

                t_yyy_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 4.5 * fl2_fx * fl1_fz * pb_x[j] + 12.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_xy[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_xy[j]);

                t_yyy_xz[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl1_fx * pb_xz[j] + pa_yyy[j] * pb_xz[j]);

                t_yyy_xz[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_xz[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_xz[j]);

                t_yyy_yy[j] = fl_s_0_0 * (2.25 * pa_y[j] * fl2_fx + 1.5 * fl2_fx * pb_y[j] + 0.5 * pa_yyy[j] * fl1_fx + 3.0 * pa_yy[j] * fl1_fx * pb_y[j] + 1.5 * pa_y[j] * fl1_fx * pb_yy[j] + pa_yyy[j] * pb_yy[j]);

                t_yyy_yy[j] += fl_r_0_0 * (13.5 * pa_y[j] * fl2_fx * fl1_fz - 1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - pa_yyy[j] * fl1_fz * fl1_fgb + 9.0 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_yyy[j] * fl1_fz * fl1_fx + 24.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_yy[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_yy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD_40_50(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(19 * idx + 6);

            auto pa_yz = paDistances.data(19 * idx + 7);

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yyy = paDistances.data(19 * idx + 15);

            auto pa_yyz = paDistances.data(19 * idx + 16);

            auto pa_yzz = paDistances.data(19 * idx + 17);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yyy_yz = primBuffer.data(60 * idx + 40);

            auto t_yyy_zz = primBuffer.data(60 * idx + 41);

            auto t_yyz_xx = primBuffer.data(60 * idx + 42);

            auto t_yyz_xy = primBuffer.data(60 * idx + 43);

            auto t_yyz_xz = primBuffer.data(60 * idx + 44);

            auto t_yyz_yy = primBuffer.data(60 * idx + 45);

            auto t_yyz_yz = primBuffer.data(60 * idx + 46);

            auto t_yyz_zz = primBuffer.data(60 * idx + 47);

            auto t_yzz_xx = primBuffer.data(60 * idx + 48);

            auto t_yzz_xy = primBuffer.data(60 * idx + 49);

            // Batch of Integrals (40,50)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyz, pa_yz, pa_yzz, pa_z, pa_zz, pb_x, pb_xx, \
                                     pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yyy_yz, t_yyy_zz, \
                                     t_yyz_xx, t_yyz_xy, t_yyz_xz, t_yyz_yy, t_yyz_yz, t_yyz_zz, t_yzz_xx, t_yzz_xy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_yyy_yz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_z[j] + 1.5 * pa_yy[j] * fl1_fx * pb_z[j] + 1.5 * pa_y[j] * fl1_fx * pb_yz[j] + pa_yyy[j] * pb_yz[j]);

                t_yyy_yz[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 4.5 * fl2_fx * fl1_fz * pb_z[j] + 12.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_yz[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_yz[j]);

                t_yyy_zz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx + 0.5 * pa_yyy[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_zz[j] + pa_yyy[j] * pb_zz[j]);

                t_yyy_zz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - pa_yyy[j] * fl1_fz * fl1_fgb + 4.5 * pa_y[j] * fl1_fz * fl2_fx + 4.0 * pa_yyy[j] * fl1_fz * fl1_fx - 3.0 * pa_y[j] * fl1_fz * fl1_fga * pb_zz[j] + 12.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_yyy[j] * fl1_fz * pb_zz[j]);

                t_yyz_xx[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * pa_yyz[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_xx[j] + pa_yyz[j] * pb_xx[j]);

                t_yyz_xx[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - pa_yyz[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 4.0 * pa_yyz[j] * fl1_fz * fl1_fx - fl1_fz * fl1_fga * pa_z[j] * pb_xx[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xx[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_xx[j]);

                t_yyz_xy[j] = fl_s_0_0 * (pa_yz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_z[j] * pb_xy[j] + pa_yyz[j] * pb_xy[j]);

                t_yyz_xy[j] += fl_r_0_0 * (8.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fz * fl1_fga * pa_z[j] * pb_xy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xy[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_xy[j]);

                t_yyz_xz[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_x[j] + 0.5 * pa_yy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_z[j] * pb_xz[j] + pa_yyz[j] * pb_xz[j]);

                t_yyz_xz[j] += fl_r_0_0 * (-0.5 * fl1_fz * fl1_fga * fl1_fx * pb_x[j] + 1.5 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_x[j] - fl1_fz * fl1_fga * pa_z[j] * pb_xz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xz[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_xz[j]);

                t_yyz_yy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] + 0.5 * pa_yyz[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_z[j] * pb_yy[j] + pa_yyz[j] * pb_yy[j]);

                t_yyz_yy[j] += fl_r_0_0 * (4.5 * fl2_fx * fl1_fz * pa_z[j] - 0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - pa_yyz[j] * fl1_fz * fl1_fgb + 4.0 * pa_yyz[j] * fl1_fz * fl1_fx + 16.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fz * fl1_fga * pa_z[j] * pb_yy[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yy[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_yy[j]);

                t_yyz_yz[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx + 0.25 * fl2_fx * pb_y[j] + 0.5 * pa_yy[j] * fl1_fx * pb_y[j] + pa_yz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_z[j] * pb_yz[j] + pa_yyz[j] * pb_yz[j]);

                t_yyz_yz[j] += fl_r_0_0 * (3.0 * pa_y[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_y[j] + 1.5 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_y[j] + 8.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * pb_yz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yz[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_yz[j]);

                t_yyz_zz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] + 0.5 * fl2_fx * pb_z[j] + 0.5 * pa_yyz[j] * fl1_fx + pa_yy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_z[j] * pb_zz[j] + pa_yyz[j] * pb_zz[j]);

                t_yyz_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx - fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_yyz[j] * fl1_fz * fl1_fgb + 1.5 * fl2_fx * fl1_fz * pa_z[j] + 3.0 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * pa_yyz[j] * fl1_fz * fl1_fx + 8.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * pb_zz[j] + 4.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zz[j] + 10.0 * pa_yyz[j] * fl1_fz * pb_zz[j]);

                t_yzz_xx[j] = fl_s_0_0 * (0.25 * pa_y[j] * fl2_fx + 0.5 * pa_yzz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pb_xx[j] + pa_yzz[j] * pb_xx[j]);

                t_yzz_xx[j] += fl_r_0_0 * (-0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - pa_yzz[j] * fl1_fz * fl1_fgb + 1.5 * pa_y[j] * fl1_fz * fl2_fx + 4.0 * pa_yzz[j] * fl1_fz * fl1_fx - pa_y[j] * fl1_fz * fl1_fga * pb_xx[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_xx[j]);

                t_yzz_xy[j] = fl_s_0_0 * (0.25 * fl2_fx * pb_x[j] + 0.5 * fl1_fx * pa_zz[j] * pb_x[j] + 0.5 * pa_y[j] * fl1_fx * pb_xy[j] + pa_yzz[j] * pb_xy[j]);

                t_yzz_xy[j] += fl_r_0_0 * (-0.5 * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 1.5 * fl2_fx * fl1_fz * pb_x[j] + 4.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_x[j] - pa_y[j] * fl1_fz * fl1_fga * pb_xy[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_xy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForFD_50_60(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(19 * idx + 1);

            auto pa_z = paDistances.data(19 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(19 * idx + 7);

            auto pa_zz = paDistances.data(19 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yzz = paDistances.data(19 * idx + 17);

            auto pa_zzz = paDistances.data(19 * idx + 18);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yzz_xz = primBuffer.data(60 * idx + 50);

            auto t_yzz_yy = primBuffer.data(60 * idx + 51);

            auto t_yzz_yz = primBuffer.data(60 * idx + 52);

            auto t_yzz_zz = primBuffer.data(60 * idx + 53);

            auto t_zzz_xx = primBuffer.data(60 * idx + 54);

            auto t_zzz_xy = primBuffer.data(60 * idx + 55);

            auto t_zzz_xz = primBuffer.data(60 * idx + 56);

            auto t_zzz_yy = primBuffer.data(60 * idx + 57);

            auto t_zzz_yz = primBuffer.data(60 * idx + 58);

            auto t_zzz_zz = primBuffer.data(60 * idx + 59);

            // Batch of Integrals (50,60)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_yzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, pb_xy, pb_xz, \
                                     pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yzz_xz, t_yzz_yy, t_yzz_yz, \
                                     t_yzz_zz, t_zzz_xx, t_zzz_xy, t_zzz_xz, t_zzz_yy, t_zzz_yz, t_zzz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                t_yzz_xz[j] = fl_s_0_0 * (pa_yz[j] * fl1_fx * pb_x[j] + 0.5 * pa_y[j] * fl1_fx * pb_xz[j] + pa_yzz[j] * pb_xz[j]);

                t_yzz_xz[j] += fl_r_0_0 * (8.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_x[j] - pa_y[j] * fl1_fz * fl1_fga * pb_xz[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_xz[j]);

                t_yzz_yy[j] = fl_s_0_0 * (0.25 * pa_y[j] * fl2_fx + 0.5 * fl2_fx * pb_y[j] + 0.5 * pa_yzz[j] * fl1_fx + fl1_fx * pa_zz[j] * pb_y[j] + 0.5 * pa_y[j] * fl1_fx * pb_yy[j] + pa_yzz[j] * pb_yy[j]);

                t_yzz_yy[j] += fl_r_0_0 * (-0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_y[j] - pa_yzz[j] * fl1_fz * fl1_fgb + 1.5 * pa_y[j] * fl1_fz * fl2_fx + 3.0 * fl2_fx * fl1_fz * pb_y[j] + 4.0 * pa_yzz[j] * fl1_fz * fl1_fx + 8.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_y[j] - pa_y[j] * fl1_fz * fl1_fga * pb_yy[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_yy[j]);

                t_yzz_yz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_z[j] + 0.25 * fl2_fx * pb_z[j] + pa_yz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_zz[j] * pb_z[j] + 0.5 * pa_y[j] * fl1_fx * pb_yz[j] + pa_yzz[j] * pb_yz[j]);

                t_yzz_yz[j] += fl_r_0_0 * (3.0 * fl2_fx * pa_z[j] * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 1.5 * fl2_fx * fl1_fz * pb_z[j] + 8.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_y[j] + 4.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_z[j] - pa_y[j] * fl1_fz * fl1_fga * pb_yz[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_yz[j]);

                t_yzz_zz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx + 0.5 * pa_yzz[j] * fl1_fx + 2.0 * pa_yz[j] * fl1_fx * pb_z[j] + 0.5 * pa_y[j] * fl1_fx * pb_zz[j] + pa_yzz[j] * pb_zz[j]);

                t_yzz_zz[j] += fl_r_0_0 * (4.5 * pa_y[j] * fl2_fx * fl1_fz - 0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx - pa_yzz[j] * fl1_fz * fl1_fgb + 4.0 * pa_yzz[j] * fl1_fz * fl1_fx + 16.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_z[j] - pa_y[j] * fl1_fz * fl1_fga * pb_zz[j] + 4.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_yzz[j] * fl1_fz * pb_zz[j]);

                t_zzz_xx[j] = fl_s_0_0 * (0.75 * pa_z[j] * fl2_fx + 0.5 * pa_zzz[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_xx[j] + pa_zzz[j] * pb_xx[j]);

                t_zzz_xx[j] += fl_r_0_0 * (-1.5 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_z[j] * fl1_fz * fl1_fga * fl1_fx - pa_zzz[j] * fl1_fz * fl1_fgb + 4.5 * pa_z[j] * fl1_fz * fl2_fx + 4.0 * pa_zzz[j] * fl1_fz * fl1_fx - 3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_xx[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xx[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_xx[j]);

                t_zzz_xy[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl1_fx * pb_xy[j] + pa_zzz[j] * pb_xy[j]);

                t_zzz_xy[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_xy[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xy[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_xy[j]);

                t_zzz_xz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_x[j] + 1.5 * pa_zz[j] * fl1_fx * pb_x[j] + 1.5 * pa_z[j] * fl1_fx * pb_xz[j] + pa_zzz[j] * pb_xz[j]);

                t_zzz_xz[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 4.5 * fl2_fx * fl1_fz * pb_x[j] + 12.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_xz[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xz[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_xz[j]);

                t_zzz_yy[j] = fl_s_0_0 * (0.75 * pa_z[j] * fl2_fx + 0.5 * pa_zzz[j] * fl1_fx + 1.5 * pa_z[j] * fl1_fx * pb_yy[j] + pa_zzz[j] * pb_yy[j]);

                t_zzz_yy[j] += fl_r_0_0 * (-1.5 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_z[j] * fl1_fz * fl1_fga * fl1_fx - pa_zzz[j] * fl1_fz * fl1_fgb + 4.5 * pa_z[j] * fl1_fz * fl2_fx + 4.0 * pa_zzz[j] * fl1_fz * fl1_fx - 3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_yy[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_yy[j]);

                t_zzz_yz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_y[j] + 1.5 * pa_zz[j] * fl1_fx * pb_y[j] + 1.5 * pa_z[j] * fl1_fx * pb_yz[j] + pa_zzz[j] * pb_yz[j]);

                t_zzz_yz[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 4.5 * fl2_fx * fl1_fz * pb_y[j] + 12.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_yz[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_yz[j]);

                t_zzz_zz[j] = fl_s_0_0 * (2.25 * pa_z[j] * fl2_fx + 1.5 * fl2_fx * pb_z[j] + 0.5 * pa_zzz[j] * fl1_fx + 3.0 * pa_zz[j] * fl1_fx * pb_z[j] + 1.5 * pa_z[j] * fl1_fx * pb_zz[j] + pa_zzz[j] * pb_zz[j]);

                t_zzz_zz[j] += fl_r_0_0 * (13.5 * pa_z[j] * fl2_fx * fl1_fz - 1.5 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_z[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - pa_zzz[j] * fl1_fz * fl1_fgb + 9.0 * fl2_fx * fl1_fz * pb_z[j] + 4.0 * pa_zzz[j] * fl1_fz * fl1_fx + 24.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_z[j] * fl1_fz * fl1_fga * pb_zz[j] + 12.0 * pa_z[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_zzz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        kinrecfunc::compKineticEnergyForDG_0_10(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_10_20(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_20_30(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_30_40(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_40_50(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_50_60(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_60_70(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_70_80(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForDG_80_90(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compKineticEnergyForDG_0_10(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(9 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xx_xxxx = primBuffer.data(90 * idx);

            auto t_xx_xxxy = primBuffer.data(90 * idx + 1);

            auto t_xx_xxxz = primBuffer.data(90 * idx + 2);

            auto t_xx_xxyy = primBuffer.data(90 * idx + 3);

            auto t_xx_xxyz = primBuffer.data(90 * idx + 4);

            auto t_xx_xxzz = primBuffer.data(90 * idx + 5);

            auto t_xx_xyyy = primBuffer.data(90 * idx + 6);

            auto t_xx_xyyz = primBuffer.data(90 * idx + 7);

            auto t_xx_xyzz = primBuffer.data(90 * idx + 8);

            auto t_xx_xzzz = primBuffer.data(90 * idx + 9);

            // Batch of Integrals (0,10)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, \
                                     pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xx_xxxx, t_xx_xxxy, t_xx_xxxz, t_xx_xxyy, t_xx_xxyz, \
                                     t_xx_xxzz, t_xx_xyyy, t_xx_xyyz, t_xx_xyzz, t_xx_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xx_xxxx[j] = fl_s_0_0 * (1.875 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 6.0 * pa_x[j] * fl2_fx * pb_x[j] + 4.5 * fl2_fx * pb_xx[j] + 3.0 * pa_xx[j] * pb_xx[j] * fl1_fx + 4.0 * pa_x[j] * fl1_fx * pb_xxx[j] + 0.5 * fl1_fx * pb_xxxx[j] + pa_xx[j] * pb_xxxx[j]);

                t_xx_xxxx[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fgb + 11.25 * fl3_fx * fl1_fz - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 12.0 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * pa_xx[j] * fl1_fz * fl2_fx + 48.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 36.0 * fl2_fx * fl1_fz * pb_xx[j] - 3.0 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 6.0 * pa_xx[j] * pb_xx[j] * fl1_fz * fl1_fgb + 30.0 * pa_xx[j] * fl1_fz * pb_xx[j] * fl1_fx + 40.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxx[j] - fl1_fz * fl1_fga * pb_xxxx[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxx[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxxx[j]);

                t_xx_xxxy[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl2_fx * pb_y[j] + 2.25 * fl2_fx * pb_xy[j] + 1.5 * pa_xx[j] * pb_xy[j] * fl1_fx + 3.0 * pa_x[j] * fl1_fx * pb_xxy[j] + 0.5 * fl1_fx * pb_xxxy[j] + pa_xx[j] * pb_xxxy[j]);

                t_xx_xxxy[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] + 12.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] + 18.0 * fl2_fx * fl1_fz * pb_xy[j] - 1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_xx[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_xx[j] * fl1_fz * pb_xy[j] * fl1_fx + 30.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxy[j] - fl1_fz * fl1_fga * pb_xxxy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxy[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxxy[j]);

                t_xx_xxxz[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl2_fx * pb_z[j] + 2.25 * fl2_fx * pb_xz[j] + 1.5 * pa_xx[j] * pb_xz[j] * fl1_fx + 3.0 * pa_x[j] * fl1_fx * pb_xxz[j] + 0.5 * fl1_fx * pb_xxxz[j] + pa_xx[j] * pb_xxxz[j]);

                t_xx_xxxz[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 12.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] + 18.0 * fl2_fx * fl1_fz * pb_xz[j] - 1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_xx[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xx[j] * fl1_fz * pb_xz[j] * fl1_fx + 30.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxz[j] - fl1_fz * fl1_fga * pb_xxxz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxxz[j]);

                t_xx_xxyy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_yy[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xx[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 2.0 * pa_x[j] * fl1_fx * pb_xyy[j] + 0.5 * fl1_fx * pb_xxyy[j] + pa_xx[j] * pb_xxyy[j]);

                t_xx_xxyy[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 8.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yy[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yy[j] - pa_xx[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xx[j] * fl1_fz * fl1_fgb * pb_yy[j] + 2.0 * fl1_fz * fl2_fx * pb_xx[j] + 5.0 * pa_xx[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yy[j] + 20.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyy[j] - fl1_fz * fl1_fga * pb_xxyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyy[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxyy[j]);

                t_xx_xxyz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_yz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yz[j] + 2.0 * pa_x[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pb_xxyz[j] + pa_xx[j] * pb_xxyz[j]);

                t_xx_xxyz[j] += fl_r_0_0 * (6.0 * fl2_fx * fl1_fz * pb_yz[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yz[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yz[j] - pa_xx[j] * fl1_fz * fl1_fgb * pb_yz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yz[j] + 20.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyz[j] - fl1_fz * fl1_fga * pb_xxyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxyz[j]);

                t_xx_xxzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_zz[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xx[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 2.0 * pa_x[j] * fl1_fx * pb_xzz[j] + 0.5 * fl1_fx * pb_xxzz[j] + pa_xx[j] * pb_xxzz[j]);

                t_xx_xxzz[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 8.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_xx[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xx[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_xx[j] + 5.0 * pa_xx[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_zz[j] + 20.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xzz[j] - fl1_fz * fl1_fga * pb_xxzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xxzz[j]);

                t_xx_xyyy[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_xx[j] * pb_xy[j] * fl1_fx + pa_x[j] * fl1_fx * pb_yyy[j] + 0.5 * fl1_fx * pb_xyyy[j] + pa_xx[j] * pb_xyyy[j]);

                t_xx_xyyy[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - 1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_xx[j] * pb_xy[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xy[j] + 15.0 * pa_xx[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyy[j] - fl1_fz * fl1_fga * pb_xyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyy[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xyyy[j]);

                t_xx_xyyz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_xx[j] * pb_xz[j] * fl1_fx + pa_x[j] * fl1_fx * pb_yyz[j] + 0.5 * fl1_fx * pb_xyyz[j] + pa_xx[j] * pb_xyyz[j]);

                t_xx_xyyz[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - 0.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - pa_xx[j] * pb_xz[j] * fl1_fz * fl1_fgb + 2.0 * fl1_fz * fl2_fx * pb_xz[j] + 5.0 * pa_xx[j] * fl1_fz * pb_xz[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyz[j] - fl1_fz * fl1_fga * pb_xyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xyyz[j]);

                t_xx_xyzz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_xx[j] * pb_xy[j] * fl1_fx + pa_x[j] * fl1_fx * pb_yzz[j] + 0.5 * fl1_fx * pb_xyzz[j] + pa_xx[j] * pb_xyzz[j]);

                t_xx_xyzz[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - 0.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - pa_xx[j] * pb_xy[j] * fl1_fz * fl1_fgb + 2.0 * fl1_fz * fl2_fx * pb_xy[j] + 5.0 * pa_xx[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yzz[j] - fl1_fz * fl1_fga * pb_xyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xyzz[j]);

                t_xx_xzzz[j] = fl_s_0_0 * (1.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_xx[j] * pb_xz[j] * fl1_fx + pa_x[j] * fl1_fx * pb_zzz[j] + 0.5 * fl1_fx * pb_xzzz[j] + pa_xx[j] * pb_xzzz[j]);

                t_xx_xzzz[j] += fl_r_0_0 * (-3.0 * pa_x[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - 1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_xx[j] * pb_xz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xz[j] + 15.0 * pa_xx[j] * fl1_fz * pb_xz[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zzz[j] - fl1_fz * fl1_fga * pb_xzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xzzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_xzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_10_20(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(9 * idx + 3);

            auto pa_xy = paDistances.data(9 * idx + 4);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xx_yyyy = primBuffer.data(90 * idx + 10);

            auto t_xx_yyyz = primBuffer.data(90 * idx + 11);

            auto t_xx_yyzz = primBuffer.data(90 * idx + 12);

            auto t_xx_yzzz = primBuffer.data(90 * idx + 13);

            auto t_xx_zzzz = primBuffer.data(90 * idx + 14);

            auto t_xy_xxxx = primBuffer.data(90 * idx + 15);

            auto t_xy_xxxy = primBuffer.data(90 * idx + 16);

            auto t_xy_xxxz = primBuffer.data(90 * idx + 17);

            auto t_xy_xxyy = primBuffer.data(90 * idx + 18);

            auto t_xy_xxyz = primBuffer.data(90 * idx + 19);

            // Batch of Integrals (10,20)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xy, pa_y, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, \
                                     pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, \
                                     pb_yyyy, pb_yyyz, pb_yyzz, pb_yz, pb_yzzz, pb_z, pb_zz, pb_zzzz, r_0_0, s_0_0, \
                                     t_xx_yyyy, t_xx_yyyz, t_xx_yyzz, t_xx_yzzz, t_xx_zzzz, t_xy_xxxx, t_xy_xxxy, \
                                     t_xy_xxxz, t_xy_xxyy, t_xy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xx_yyyy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 1.5 * fl2_fx * pb_yy[j] + 3.0 * pa_xx[j] * pb_yy[j] * fl1_fx + 0.5 * fl1_fx * pb_yyyy[j] + pa_xx[j] * pb_yyyy[j]);

                t_xx_yyyy[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_xx[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 6.0 * pa_xx[j] * pb_yy[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_yy[j] + 30.0 * pa_xx[j] * fl1_fz * pb_yy[j] * fl1_fx - fl1_fz * fl1_fga * pb_yyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyy[j] + 12.0 * pa_xx[j] * fl1_fz * pb_yyyy[j]);

                t_xx_yyyz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_xx[j] * pb_yz[j] * fl1_fx + 0.5 * fl1_fx * pb_yyyz[j] + pa_xx[j] * pb_yyyz[j]);

                t_xx_yyyz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_xx[j] * pb_yz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_yz[j] + 15.0 * pa_xx[j] * fl1_fz * pb_yz[j] * fl1_fx - fl1_fz * fl1_fga * pb_yyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_yyyz[j]);

                t_xx_yyzz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pb_yy[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xx[j] * pb_yy[j] * fl1_fx + 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pb_yyzz[j] + pa_xx[j] * pb_yyzz[j]);

                t_xx_yyzz[j] += fl_r_0_0 * (-0.5 * fl2_fx * fl1_fz * fl1_fgb - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb + 0.75 * fl1_fz * fl3_fx + 2.0 * pa_xx[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_xx[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_xx[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_yy[j] + 2.0 * fl1_fz * fl2_fx * pb_zz[j] + 5.0 * pa_xx[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_zz[j] - fl1_fz * fl1_fga * pb_yyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_yyzz[j]);

                t_xx_yzzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_xx[j] * pb_yz[j] * fl1_fx + 0.5 * fl1_fx * pb_yzzz[j] + pa_xx[j] * pb_yzzz[j]);

                t_xx_yzzz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_xx[j] * pb_yz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_yz[j] + 15.0 * pa_xx[j] * fl1_fz * pb_yz[j] * fl1_fx - fl1_fz * fl1_fga * pb_yzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yzzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_yzzz[j]);

                t_xx_zzzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 1.5 * fl2_fx * pb_zz[j] + 3.0 * pa_xx[j] * pb_zz[j] * fl1_fx + 0.5 * fl1_fx * pb_zzzz[j] + pa_xx[j] * pb_zzzz[j]);

                t_xx_zzzz[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_xx[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_zz[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_zz[j] * fl1_fx - 6.0 * pa_xx[j] * pb_zz[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_zz[j] + 30.0 * pa_xx[j] * fl1_fz * pb_zz[j] * fl1_fx - fl1_fz * fl1_fga * pb_zzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_zzzz[j] + 12.0 * pa_xx[j] * fl1_fz * pb_zzzz[j]);

                t_xy_xxxx[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 3.0 * fl2_fx * pa_y[j] * pb_x[j] + 3.0 * pa_xy[j] * pb_xx[j] * fl1_fx + 2.0 * fl1_fx * pa_y[j] * pb_xxx[j] + pa_xy[j] * pb_xxxx[j]);

                t_xy_xxxx[j] += fl_r_0_0 * (-3.0 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * fl1_fx * pa_y[j] * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl1_fz * fl2_fx + 24.0 * fl2_fx * fl1_fz * pa_y[j] * pb_x[j] - 6.0 * pa_xy[j] * pb_xx[j] * fl1_fz * fl1_fgb + 30.0 * pa_xy[j] * fl1_fz * pb_xx[j] * fl1_fx + 20.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xxx[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxxx[j]);

                t_xy_xxxy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xy[j] * pb_xy[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] + 1.5 * fl1_fx * pa_y[j] * pb_xxy[j] + pa_xy[j] * pb_xxxy[j]);

                t_xy_xxxy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb * pb_y[j] + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] - 3.0 * pa_xy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_xy[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxx[j] + 15.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xxy[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxxy[j]);

                t_xy_xxxz[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 1.5 * pa_xy[j] * pb_xz[j] * fl1_fx + 1.5 * fl1_fx * pa_y[j] * pb_xxz[j] + pa_xy[j] * pb_xxxz[j]);

                t_xy_xxxz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_z[j] - 3.0 * pa_xy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_xz[j] * fl1_fx + 15.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xxz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxxz[j]);

                t_xy_xxyy[j] = fl_s_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + fl2_fx * pb_xy[j] + 0.5 * pa_xy[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xy[j] * fl1_fx * pb_yy[j] + pa_x[j] * fl1_fx * pb_xxy[j] + fl1_fx * pa_y[j] * pb_xyy[j] + pa_xy[j] * pb_xxyy[j]);

                t_xy_xxyy[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] - fl1_fx * pa_y[j] * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xy[j] * fl1_fz * fl2_fx + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] + 4.0 * fl2_fx * fl1_fz * pa_y[j] * pb_x[j] + 8.0 * fl2_fx * fl1_fz * pb_xy[j] - pa_xy[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xy[j] * fl1_fz * fl1_fgb * pb_yy[j] + 5.0 * pa_xy[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxy[j] + 10.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xyy[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxyy[j]);

                t_xy_xxyz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_xy[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxz[j] + fl1_fx * pa_y[j] * pb_xyz[j] + pa_xy[j] * pb_xxyz[j]);

                t_xy_xxyz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] + 4.0 * fl2_fx * fl1_fz * pb_xz[j] - pa_xy[j] * fl1_fz * fl1_fgb * pb_yz[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxz[j] + 10.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xyz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxyz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_20_30(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(9 * idx + 4);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xy_xxzz = primBuffer.data(90 * idx + 20);

            auto t_xy_xyyy = primBuffer.data(90 * idx + 21);

            auto t_xy_xyyz = primBuffer.data(90 * idx + 22);

            auto t_xy_xyzz = primBuffer.data(90 * idx + 23);

            auto t_xy_xzzz = primBuffer.data(90 * idx + 24);

            auto t_xy_yyyy = primBuffer.data(90 * idx + 25);

            auto t_xy_yyyz = primBuffer.data(90 * idx + 26);

            auto t_xy_yyzz = primBuffer.data(90 * idx + 27);

            auto t_xy_yzzz = primBuffer.data(90 * idx + 28);

            auto t_xy_zzzz = primBuffer.data(90 * idx + 29);

            // Batch of Integrals (20,30)

            #pragma omp simd aligned(fgb, fx, fz, pa_x, pa_xy, pa_y, pb_x, pb_xx, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, \
                                     pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyyy, pb_yyyz, \
                                     pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, s_0_0, \
                                     t_xy_xxzz, t_xy_xyyy, t_xy_xyyz, t_xy_xyzz, t_xy_xzzz, t_xy_yyyy, t_xy_yyyz, \
                                     t_xy_yyzz, t_xy_yzzz, t_xy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xy_xxzz[j] = fl_s_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xy[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xy[j] * fl1_fx * pb_zz[j] + fl1_fx * pa_y[j] * pb_xzz[j] + pa_xy[j] * pb_xxzz[j]);

                t_xy_xxzz[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - fl1_fx * pa_y[j] * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xy[j] * fl1_fz * fl2_fx + 4.0 * fl2_fx * fl1_fz * pa_y[j] * pb_x[j] - pa_xy[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xy[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_xy[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * fl1_fx * fl1_fz * pa_y[j] * pb_xzz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xxzz[j]);

                t_xy_xyyy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_xy[j] * pb_xy[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_xyy[j] + 0.5 * fl1_fx * pa_y[j] * pb_yyy[j] + pa_xy[j] * pb_xyyy[j]);

                t_xy_xyyy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_y[j] * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] - 3.0 * pa_xy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_xy[j] * fl1_fx + 15.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyy[j] + 5.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yyy[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xyyy[j]);

                t_xy_xyyz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xy[j] * pb_xz[j] * fl1_fx + pa_x[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yyz[j] + pa_xy[j] * pb_xyyz[j]);

                t_xy_xyyz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * fl2_fx * fl1_fz * pa_y[j] * pb_z[j] + 4.0 * fl2_fx * fl1_fz * pb_yz[j] - pa_xy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 5.0 * pa_xy[j] * fl1_fz * pb_xz[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyz[j] + 5.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yyz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xyyz[j]);

                t_xy_xyzz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xy[j] * pb_xy[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_xzz[j] + 0.5 * fl1_fx * pa_y[j] * pb_yzz[j] + pa_xy[j] * pb_xyzz[j]);

                t_xy_xyzz[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * pa_y[j] * pb_y[j] * fl1_fz * fl1_fgb + 2.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 2.0 * fl2_fx * fl1_fz * pa_y[j] * pb_y[j] + 2.0 * fl2_fx * fl1_fz * pb_zz[j] - pa_xy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 5.0 * pa_xy[j] * fl1_fz * pb_xy[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xzz[j] + 5.0 * fl1_fx * fl1_fz * pa_y[j] * pb_yzz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xyzz[j]);

                t_xy_xzzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 1.5 * pa_xy[j] * pb_xz[j] * fl1_fx + 0.5 * fl1_fx * pa_y[j] * pb_zzz[j] + pa_xy[j] * pb_xzzz[j]);

                t_xy_xzzz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_y[j] * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_z[j] - 3.0 * pa_xy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_xz[j] * fl1_fx + 5.0 * fl1_fx * fl1_fz * pa_y[j] * pb_zzz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_xzzz[j]);

                t_xy_yyyy[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 3.0 * pa_x[j] * fl2_fx * pb_y[j] + 3.0 * pa_xy[j] * pb_yy[j] * fl1_fx + 2.0 * pa_x[j] * fl1_fx * pb_yyy[j] + pa_xy[j] * pb_yyyy[j]);

                t_xy_yyyy[j] += fl_r_0_0 * (-3.0 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl1_fz * fl2_fx + 24.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - 6.0 * pa_xy[j] * pb_yy[j] * fl1_fz * fl1_fgb + 30.0 * pa_xy[j] * fl1_fz * pb_yy[j] * fl1_fx + 20.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyy[j] + 12.0 * pa_xy[j] * fl1_fz * pb_yyyy[j]);

                t_xy_yyyz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xy[j] * pb_yz[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yyz[j] + pa_xy[j] * pb_yyyz[j]);

                t_xy_yyyz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - 3.0 * pa_xy[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_yz[j] * fl1_fx + 15.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_yyyz[j]);

                t_xy_yyzz[j] = fl_s_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xy[j] * pb_yy[j] * fl1_fx + 0.5 * pa_xy[j] * fl1_fx * pb_zz[j] + pa_x[j] * fl1_fx * pb_yzz[j] + pa_xy[j] * pb_yyzz[j]);

                t_xy_yyzz[j] += fl_r_0_0 * (-pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 2.0 * pa_xy[j] * fl1_fz * fl2_fx + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - pa_xy[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_xy[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_xy[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yzz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_yyzz[j]);

                t_xy_yzzz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xy[j] * pb_yz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_zzz[j] + pa_xy[j] * pb_yzzz[j]);

                t_xy_yzzz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - 3.0 * pa_xy[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xy[j] * fl1_fz * pb_yz[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zzz[j] + 12.0 * pa_xy[j] * fl1_fz * pb_yzzz[j]);

                t_xy_zzzz[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 3.0 * pa_xy[j] * pb_zz[j] * fl1_fx + pa_xy[j] * pb_zzzz[j]);

                t_xy_zzzz[j] += fl_r_0_0 * (-3.0 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl1_fz * fl2_fx - 6.0 * pa_xy[j] * pb_zz[j] * fl1_fz * fl1_fgb + 30.0 * pa_xy[j] * fl1_fz * pb_zz[j] * fl1_fx + 12.0 * pa_xy[j] * fl1_fz * pb_zzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_30_40(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(9 * idx + 5);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xz_xxxx = primBuffer.data(90 * idx + 30);

            auto t_xz_xxxy = primBuffer.data(90 * idx + 31);

            auto t_xz_xxxz = primBuffer.data(90 * idx + 32);

            auto t_xz_xxyy = primBuffer.data(90 * idx + 33);

            auto t_xz_xxyz = primBuffer.data(90 * idx + 34);

            auto t_xz_xxzz = primBuffer.data(90 * idx + 35);

            auto t_xz_xyyy = primBuffer.data(90 * idx + 36);

            auto t_xz_xyyz = primBuffer.data(90 * idx + 37);

            auto t_xz_xyzz = primBuffer.data(90 * idx + 38);

            auto t_xz_xzzz = primBuffer.data(90 * idx + 39);

            // Batch of Integrals (30,40)

            #pragma omp simd aligned(fgb, fx, fz, pa_x, pa_xz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, \
                                     pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xz_xxxx, t_xz_xxxy, t_xz_xxxz, t_xz_xxyy, t_xz_xxyz, \
                                     t_xz_xxzz, t_xz_xyyy, t_xz_xyyz, t_xz_xyzz, t_xz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xz_xxxx[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 3.0 * fl2_fx * pa_z[j] * pb_x[j] + 3.0 * pa_xz[j] * pb_xx[j] * fl1_fx + 2.0 * fl1_fx * pa_z[j] * pb_xxx[j] + pa_xz[j] * pb_xxxx[j]);

                t_xz_xxxx[j] += fl_r_0_0 * (-3.0 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl1_fz * fl2_fx + 24.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] - 6.0 * pa_xz[j] * pb_xx[j] * fl1_fz * fl1_fgb + 30.0 * pa_xz[j] * fl1_fz * pb_xx[j] * fl1_fx + 20.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxx[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxxx[j]);

                t_xz_xxxy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_xz[j] * pb_xy[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_xxy[j] + pa_xz[j] * pb_xxxy[j]);

                t_xz_xxxy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] - 3.0 * pa_xz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_xy[j] * fl1_fx + 15.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxy[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxxy[j]);

                t_xz_xxxz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_xx[j] + 1.5 * pa_xz[j] * pb_xz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_xxx[j] + 1.5 * fl1_fx * pa_z[j] * pb_xxz[j] + pa_xz[j] * pb_xxxz[j]);

                t_xz_xxxz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_z[j] + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] - 3.0 * pa_xz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_xz[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxx[j] + 15.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxxz[j]);

                t_xz_xxyy[j] = fl_s_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xz[j] * fl1_fx * pb_yy[j] + fl1_fx * pa_z[j] * pb_xyy[j] + pa_xz[j] * pb_xxyy[j]);

                t_xz_xxyy[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xz[j] * fl1_fz * fl2_fx + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] - pa_xz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xz[j] * fl1_fz * fl1_fgb * pb_yy[j] + 5.0 * pa_xz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xyy[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxyy[j]);

                t_xz_xxyz[j] = fl_s_0_0 * (0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_xz[j] * fl1_fx * pb_yz[j] + 0.5 * pa_x[j] * fl1_fx * pb_xxy[j] + fl1_fx * pa_z[j] * pb_xyz[j] + pa_xz[j] * pb_xxyz[j]);

                t_xz_xxyz[j] += fl_r_0_0 * (-0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] + 2.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] + 4.0 * fl2_fx * fl1_fz * pb_xy[j] - pa_xz[j] * fl1_fz * fl1_fgb * pb_yz[j] + 5.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxy[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xyz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxyz[j]);

                t_xz_xxzz[j] = fl_s_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + fl2_fx * pb_xz[j] + 0.5 * pa_xz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_x[j] * fl1_fx * pb_xxz[j] + fl1_fx * pa_z[j] * pb_xzz[j] + pa_xz[j] * pb_xxzz[j]);

                t_xz_xxzz[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_xz[j] * fl1_fz * fl2_fx + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 8.0 * fl2_fx * fl1_fz * pb_xz[j] - pa_xz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_xz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_xz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xxz[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xzz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xxzz[j]);

                t_xz_xyyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_xz[j] * pb_xy[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_yyy[j] + pa_xz[j] * pb_xyyy[j]);

                t_xz_xyyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] - 3.0 * pa_xz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_xy[j] * fl1_fx + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yyy[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xyyy[j]);

                t_xz_xyyz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xz[j] * pb_xz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_xyy[j] + 0.5 * fl1_fx * pa_z[j] * pb_yyz[j] + pa_xz[j] * pb_xyyz[j]);

                t_xz_xyyz[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 2.0 * fl2_fx * fl1_fz * pb_yy[j] - pa_xz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 5.0 * pa_xz[j] * fl1_fz * pb_xz[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyy[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yyz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xyyz[j]);

                t_xz_xyzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl2_fx * pb_yz[j] + 0.5 * pa_xz[j] * pb_xy[j] * fl1_fx + pa_x[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pa_z[j] * pb_yzz[j] + pa_xz[j] * pb_xyzz[j]);

                t_xz_xyzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * pb_y[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 4.0 * fl2_fx * fl1_fz * pb_yz[j] - pa_xz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 5.0 * pa_xz[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xyz[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yzz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xyzz[j]);

                t_xz_xzzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_xz[j] * pb_xz[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_xzz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] + pa_xz[j] * pb_xzzz[j]);

                t_xz_xzzz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_z[j] * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] - 3.0 * pa_xz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_xz[j] * fl1_fx + 15.0 * pa_x[j] * fl1_fz * fl1_fx * pb_xzz[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zzz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_xzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_40_50(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(9 * idx);

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xz = paDistances.data(9 * idx + 5);

            auto pa_yy = paDistances.data(9 * idx + 6);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xz_yyyy = primBuffer.data(90 * idx + 40);

            auto t_xz_yyyz = primBuffer.data(90 * idx + 41);

            auto t_xz_yyzz = primBuffer.data(90 * idx + 42);

            auto t_xz_yzzz = primBuffer.data(90 * idx + 43);

            auto t_xz_zzzz = primBuffer.data(90 * idx + 44);

            auto t_yy_xxxx = primBuffer.data(90 * idx + 45);

            auto t_yy_xxxy = primBuffer.data(90 * idx + 46);

            auto t_yy_xxxz = primBuffer.data(90 * idx + 47);

            auto t_yy_xxyy = primBuffer.data(90 * idx + 48);

            auto t_yy_xxyz = primBuffer.data(90 * idx + 49);

            // Batch of Integrals (40,50)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_y, pa_yy, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, \
                                     pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xz, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xz_yyyy, t_xz_yyyz, t_xz_yyzz, t_xz_yzzz, t_xz_zzzz, t_yy_xxxx, \
                                     t_yy_xxxy, t_yy_xxxz, t_yy_xxyy, t_yy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xz_yyyy[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 3.0 * pa_xz[j] * pb_yy[j] * fl1_fx + pa_xz[j] * pb_yyyy[j]);

                t_xz_yyyy[j] += fl_r_0_0 * (-3.0 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl1_fz * fl2_fx - 6.0 * pa_xz[j] * pb_yy[j] * fl1_fz * fl1_fgb + 30.0 * pa_xz[j] * fl1_fz * pb_yy[j] * fl1_fx + 12.0 * pa_xz[j] * fl1_fz * pb_yyyy[j]);

                t_xz_yyyz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xz[j] * pb_yz[j] * fl1_fx + 0.5 * pa_x[j] * fl1_fx * pb_yyy[j] + pa_xz[j] * pb_yyyz[j]);

                t_xz_yyyz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - 3.0 * pa_xz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_yz[j] * fl1_fx + 5.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyy[j] + 12.0 * pa_xz[j] * fl1_fz * pb_yyyz[j]);

                t_xz_yyzz[j] = fl_s_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xz[j] * pb_yy[j] * fl1_fx + 0.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_x[j] * fl1_fx * pb_yyz[j] + pa_xz[j] * pb_yyzz[j]);

                t_xz_yyzz[j] += fl_r_0_0 * (-pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - pa_x[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_xz[j] * fl1_fz * fl2_fx + 4.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - pa_xz[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_xz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_xz[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yyz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_yyzz[j]);

                t_xz_yzzz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xz[j] * pb_yz[j] * fl1_fx + 1.5 * pa_x[j] * fl1_fx * pb_yzz[j] + pa_xz[j] * pb_yzzz[j]);

                t_xz_yzzz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_x[j] * fl1_fz * fl2_fx * pb_y[j] - 3.0 * pa_xz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_xz[j] * fl1_fz * pb_yz[j] * fl1_fx + 15.0 * pa_x[j] * fl1_fz * fl1_fx * pb_yzz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_yzzz[j]);

                t_xz_zzzz[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 3.0 * pa_x[j] * fl2_fx * pb_z[j] + 3.0 * pa_xz[j] * pb_zz[j] * fl1_fx + 2.0 * pa_x[j] * fl1_fx * pb_zzz[j] + pa_xz[j] * pb_zzzz[j]);

                t_xz_zzzz[j] += fl_r_0_0 * (-3.0 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * pa_x[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl1_fz * fl2_fx + 24.0 * pa_x[j] * fl1_fz * fl2_fx * pb_z[j] - 6.0 * pa_xz[j] * pb_zz[j] * fl1_fz * fl1_fgb + 30.0 * pa_xz[j] * fl1_fz * pb_zz[j] * fl1_fx + 20.0 * pa_x[j] * fl1_fz * fl1_fx * pb_zzz[j] + 12.0 * pa_xz[j] * fl1_fz * pb_zzzz[j]);

                t_yy_xxxx[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 1.5 * fl2_fx * pb_xx[j] + 3.0 * pa_yy[j] * pb_xx[j] * fl1_fx + 0.5 * fl1_fx * pb_xxxx[j] + pa_yy[j] * pb_xxxx[j]);

                t_yy_xxxx[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_yy[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 6.0 * pa_yy[j] * pb_xx[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_xx[j] + 30.0 * pa_yy[j] * fl1_fz * pb_xx[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxxx[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxx[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxxx[j]);

                t_yy_xxxy[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_yy[j] * pb_xy[j] * fl1_fx + pa_y[j] * fl1_fx * pb_xxx[j] + 0.5 * fl1_fx * pb_xxxy[j] + pa_yy[j] * pb_xxxy[j]);

                t_yy_xxxy[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] - 1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_yy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xy[j] + 15.0 * pa_yy[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxx[j] - fl1_fz * fl1_fga * pb_xxxy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxy[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxxy[j]);

                t_yy_xxxz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_yy[j] * pb_xz[j] * fl1_fx + 0.5 * fl1_fx * pb_xxxz[j] + pa_yy[j] * pb_xxxz[j]);

                t_yy_xxxz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_yy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xz[j] + 15.0 * pa_yy[j] * fl1_fz * pb_xz[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxxz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxxz[j]);

                t_yy_xxyy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_xx[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_yy[j] * pb_xx[j] * fl1_fx + 0.5 * pa_yy[j] * fl1_fx * pb_yy[j] + 2.0 * pa_y[j] * fl1_fx * pb_xxy[j] + 0.5 * fl1_fx * pb_xxyy[j] + pa_yy[j] * pb_xxyy[j]);

                t_yy_xxyy[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] + 2.0 * pa_yy[j] * fl1_fz * fl2_fx + 8.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yy[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yy[j] - pa_yy[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_yy[j] * fl1_fz * fl1_fgb * pb_yy[j] + 2.0 * fl1_fz * fl2_fx * pb_yy[j] + 5.0 * pa_yy[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yy[j] + 20.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxy[j] - fl1_fz * fl1_fga * pb_xxyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyy[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxyy[j]);

                t_yy_xxyz[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.25 * fl2_fx * pb_yz[j] + 0.5 * pa_yy[j] * fl1_fx * pb_yz[j] + pa_y[j] * fl1_fx * pb_xxz[j] + 0.5 * fl1_fx * pb_xxyz[j] + pa_yy[j] * pb_xxyz[j]);

                t_yy_xxyz[j] += fl_r_0_0 * (-pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 4.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yz[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yz[j] - pa_yy[j] * fl1_fz * fl1_fgb * pb_yz[j] + 2.0 * fl1_fz * fl2_fx * pb_yz[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxz[j] - fl1_fz * fl1_fga * pb_xxyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxyz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_50_60(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(9 * idx + 6);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yy_xxzz = primBuffer.data(90 * idx + 50);

            auto t_yy_xyyy = primBuffer.data(90 * idx + 51);

            auto t_yy_xyyz = primBuffer.data(90 * idx + 52);

            auto t_yy_xyzz = primBuffer.data(90 * idx + 53);

            auto t_yy_xzzz = primBuffer.data(90 * idx + 54);

            auto t_yy_yyyy = primBuffer.data(90 * idx + 55);

            auto t_yy_yyyz = primBuffer.data(90 * idx + 56);

            auto t_yy_yyzz = primBuffer.data(90 * idx + 57);

            auto t_yy_yzzz = primBuffer.data(90 * idx + 58);

            auto t_yy_zzzz = primBuffer.data(90 * idx + 59);

            // Batch of Integrals (50,60)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pb_x, pb_xx, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, \
                                     pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyyy, pb_yyyz, pb_yyz, \
                                     pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, s_0_0, t_yy_xxzz, \
                                     t_yy_xyyy, t_yy_xyyz, t_yy_xyzz, t_yy_xzzz, t_yy_yyyy, t_yy_yyyz, t_yy_yyzz, \
                                     t_yy_yzzz, t_yy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yy_xxzz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + 0.25 * fl2_fx * pb_xx[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_yy[j] * pb_xx[j] * fl1_fx + 0.5 * pa_yy[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pb_xxzz[j] + pa_yy[j] * pb_xxzz[j]);

                t_yy_xxzz[j] += fl_r_0_0 * (-0.5 * fl2_fx * fl1_fz * fl1_fgb - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb + 0.75 * fl1_fz * fl3_fx + 2.0 * pa_yy[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_yy[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_yy[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_xx[j] + 2.0 * fl1_fz * fl2_fx * pb_zz[j] + 5.0 * pa_yy[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_zz[j] - fl1_fz * fl1_fga * pb_xxzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xxzz[j]);

                t_yy_xyyy[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl2_fx * pb_x[j] + 2.25 * fl2_fx * pb_xy[j] + 1.5 * pa_yy[j] * pb_xy[j] * fl1_fx + 3.0 * pa_y[j] * fl1_fx * pb_xyy[j] + 0.5 * fl1_fx * pb_xyyy[j] + pa_yy[j] * pb_xyyy[j]);

                t_yy_xyyy[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] + 18.0 * fl2_fx * fl1_fz * pb_xy[j] - 1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_yy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_yy[j] * fl1_fz * pb_xy[j] * fl1_fx + 30.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xyy[j] - fl1_fz * fl1_fga * pb_xyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyy[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xyyy[j]);

                t_yy_xyyz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xz[j] + 0.5 * pa_yy[j] * pb_xz[j] * fl1_fx + 2.0 * pa_y[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pb_xyyz[j] + pa_yy[j] * pb_xyyz[j]);

                t_yy_xyyz[j] += fl_r_0_0 * (6.0 * fl2_fx * fl1_fz * pb_xz[j] - 0.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - pa_yy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 5.0 * pa_yy[j] * fl1_fz * pb_xz[j] * fl1_fx + 20.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xyz[j] - fl1_fz * fl1_fga * pb_xyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xyyz[j]);

                t_yy_xyzz[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_yy[j] * pb_xy[j] * fl1_fx + pa_y[j] * fl1_fx * pb_xzz[j] + 0.5 * fl1_fx * pb_xyzz[j] + pa_yy[j] * pb_xyzz[j]);

                t_yy_xyzz[j] += fl_r_0_0 * (-pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] - 0.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - pa_yy[j] * pb_xy[j] * fl1_fz * fl1_fgb + 2.0 * fl1_fz * fl2_fx * pb_xy[j] + 5.0 * pa_yy[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xzz[j] - fl1_fz * fl1_fga * pb_xyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xyzz[j]);

                t_yy_xzzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_yy[j] * pb_xz[j] * fl1_fx + 0.5 * fl1_fx * pb_xzzz[j] + pa_yy[j] * pb_xzzz[j]);

                t_yy_xzzz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_yy[j] * pb_xz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xz[j] + 15.0 * pa_yy[j] * fl1_fz * pb_xz[j] * fl1_fx - fl1_fz * fl1_fga * pb_xzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xzzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_xzzz[j]);

                t_yy_yyyy[j] = fl_s_0_0 * (1.875 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 6.0 * pa_y[j] * fl2_fx * pb_y[j] + 4.5 * fl2_fx * pb_yy[j] + 3.0 * pa_yy[j] * pb_yy[j] * fl1_fx + 4.0 * pa_y[j] * fl1_fx * pb_yyy[j] + 0.5 * fl1_fx * pb_yyyy[j] + pa_yy[j] * pb_yyyy[j]);

                t_yy_yyyy[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fgb + 11.25 * fl3_fx * fl1_fz - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 12.0 * pa_y[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_yy[j] * fl1_fz * fl2_fx + 48.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 36.0 * fl2_fx * fl1_fz * pb_yy[j] - 3.0 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 6.0 * pa_yy[j] * pb_yy[j] * fl1_fz * fl1_fgb + 30.0 * pa_yy[j] * fl1_fz * pb_yy[j] * fl1_fx + 40.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yyy[j] - fl1_fz * fl1_fga * pb_yyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyy[j] + 12.0 * pa_yy[j] * fl1_fz * pb_yyyy[j]);

                t_yy_yyyz[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl2_fx * pb_z[j] + 2.25 * fl2_fx * pb_yz[j] + 1.5 * pa_yy[j] * pb_yz[j] * fl1_fx + 3.0 * pa_y[j] * fl1_fx * pb_yyz[j] + 0.5 * fl1_fx * pb_yyyz[j] + pa_yy[j] * pb_yyyz[j]);

                t_yy_yyyz[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 12.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] + 18.0 * fl2_fx * fl1_fz * pb_yz[j] - 1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_yy[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_yy[j] * fl1_fz * pb_yz[j] * fl1_fx + 30.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yyz[j] - fl1_fz * fl1_fga * pb_yyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_yyyz[j]);

                t_yy_yyzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_zz[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_yy[j] * pb_yy[j] * fl1_fx + 0.5 * pa_yy[j] * fl1_fx * pb_zz[j] + 2.0 * pa_y[j] * fl1_fx * pb_yzz[j] + 0.5 * fl1_fx * pb_yyzz[j] + pa_yy[j] * pb_yyzz[j]);

                t_yy_yyzz[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_y[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 2.0 * pa_yy[j] * fl1_fz * fl2_fx + 8.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] - 0.5 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_yy[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_yy[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_yy[j] + 5.0 * pa_yy[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_zz[j] + 20.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yzz[j] - fl1_fz * fl1_fga * pb_yyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_yyzz[j]);

                t_yy_yzzz[j] = fl_s_0_0 * (1.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_yy[j] * pb_yz[j] * fl1_fx + pa_y[j] * fl1_fx * pb_zzz[j] + 0.5 * fl1_fx * pb_yzzz[j] + pa_yy[j] * pb_yzzz[j]);

                t_yy_yzzz[j] += fl_r_0_0 * (-3.0 * pa_y[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 12.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] - 1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_yy[j] * pb_yz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_yz[j] + 15.0 * pa_yy[j] * fl1_fz * pb_yz[j] * fl1_fx + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zzz[j] - fl1_fz * fl1_fga * pb_yzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yzzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_yzzz[j]);

                t_yy_zzzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 1.5 * fl2_fx * pb_zz[j] + 3.0 * pa_yy[j] * pb_zz[j] * fl1_fx + 0.5 * fl1_fx * pb_zzzz[j] + pa_yy[j] * pb_zzzz[j]);

                t_yy_zzzz[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_yy[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_zz[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_zz[j] * fl1_fx - 6.0 * pa_yy[j] * pb_zz[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_zz[j] + 30.0 * pa_yy[j] * fl1_fz * pb_zz[j] * fl1_fx - fl1_fz * fl1_fga * pb_zzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_zzzz[j] + 12.0 * pa_yy[j] * fl1_fz * pb_zzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_60_70(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(9 * idx + 7);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yz_xxxx = primBuffer.data(90 * idx + 60);

            auto t_yz_xxxy = primBuffer.data(90 * idx + 61);

            auto t_yz_xxxz = primBuffer.data(90 * idx + 62);

            auto t_yz_xxyy = primBuffer.data(90 * idx + 63);

            auto t_yz_xxyz = primBuffer.data(90 * idx + 64);

            auto t_yz_xxzz = primBuffer.data(90 * idx + 65);

            auto t_yz_xyyy = primBuffer.data(90 * idx + 66);

            auto t_yz_xyyz = primBuffer.data(90 * idx + 67);

            auto t_yz_xyzz = primBuffer.data(90 * idx + 68);

            auto t_yz_xzzz = primBuffer.data(90 * idx + 69);

            // Batch of Integrals (60,70)

            #pragma omp simd aligned(fgb, fx, fz, pa_y, pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, \
                                     pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yz_xxxx, \
                                     t_yz_xxxy, t_yz_xxxz, t_yz_xxyy, t_yz_xxyz, t_yz_xxzz, t_yz_xyyy, t_yz_xyyz, \
                                     t_yz_xyzz, t_yz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yz_xxxx[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 3.0 * pa_yz[j] * pb_xx[j] * fl1_fx + pa_yz[j] * pb_xxxx[j]);

                t_yz_xxxx[j] += fl_r_0_0 * (-3.0 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl1_fz * fl2_fx - 6.0 * pa_yz[j] * pb_xx[j] * fl1_fz * fl1_fgb + 30.0 * pa_yz[j] * fl1_fz * pb_xx[j] * fl1_fx + 12.0 * pa_yz[j] * fl1_fz * pb_xxxx[j]);

                t_yz_xxxy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_yz[j] * pb_xy[j] * fl1_fx + 0.5 * fl1_fx * pa_z[j] * pb_xxx[j] + pa_yz[j] * pb_xxxy[j]);

                t_yz_xxxy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] - 3.0 * pa_yz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_xy[j] * fl1_fx + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxx[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xxxy[j]);

                t_yz_xxxz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pa_yz[j] * pb_xz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pb_xxx[j] + pa_yz[j] * pb_xxxz[j]);

                t_yz_xxxz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] - 3.0 * pa_yz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_xz[j] * fl1_fx + 5.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxx[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xxxz[j]);

                t_yz_xxyy[j] = fl_s_0_0 * (0.25 * pa_yz[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_yz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_yz[j] * fl1_fx * pb_yy[j] + fl1_fx * pa_z[j] * pb_xxy[j] + pa_yz[j] * pb_xxyy[j]);

                t_yz_xxyy[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_y[j] + 2.0 * pa_yz[j] * fl1_fz * fl2_fx + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] - pa_yz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_yz[j] * fl1_fz * fl1_fgb * pb_yy[j] + 5.0 * pa_yz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_yy[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxy[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xxyy[j]);

                t_yz_xxyz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_y[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yz[j] * fl1_fx * pb_yz[j] + 0.5 * pa_y[j] * fl1_fx * pb_xxy[j] + 0.5 * fl1_fx * pa_z[j] * pb_xxz[j] + pa_yz[j] * pb_xxyz[j]);

                t_yz_xxyz[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] - 0.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 2.0 * fl2_fx * fl1_fz * pb_xx[j] - pa_yz[j] * fl1_fz * fl1_fgb * pb_yz[j] + 5.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxy[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xxz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xxyz[j]);

                t_yz_xxzz[j] = fl_s_0_0 * (0.25 * pa_yz[j] * fl2_fx + 0.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_yz[j] * fl1_fx * pb_zz[j] + pa_y[j] * fl1_fx * pb_xxz[j] + pa_yz[j] * pb_xxzz[j]);

                t_yz_xxzz[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_yz[j] * fl1_fz * fl2_fx + 4.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] - pa_yz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_yz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_yz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xxz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xxzz[j]);

                t_yz_xyyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_yz[j] * pb_xy[j] * fl1_fx + 1.5 * fl1_fx * pa_z[j] * pb_xyy[j] + pa_yz[j] * pb_xyyy[j]);

                t_yz_xyyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] - 3.0 * pa_yz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_xy[j] * fl1_fx + 15.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xyy[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xyyy[j]);

                t_yz_xyyz[j] = fl_s_0_0 * (0.25 * pa_y[j] * fl2_fx * pb_x[j] + 0.5 * fl2_fx * pb_xy[j] + 0.5 * pa_yz[j] * pb_xz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pb_xyy[j] + fl1_fx * pa_z[j] * pb_xyz[j] + pa_yz[j] * pb_xyyz[j]);

                t_yz_xyyz[j] += fl_r_0_0 * (-0.5 * pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] + 4.0 * fl2_fx * fl1_fz * pb_xy[j] - pa_yz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 5.0 * pa_yz[j] * fl1_fz * pb_xz[j] * fl1_fx + 5.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xyy[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xyz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xyyz[j]);

                t_yz_xyzz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl2_fx * pb_xz[j] + 0.5 * pa_yz[j] * pb_xy[j] * fl1_fx + pa_y[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pa_z[j] * pb_xzz[j] + pa_yz[j] * pb_xyzz[j]);

                t_yz_xyzz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_z[j] * pb_x[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 4.0 * fl2_fx * fl1_fz * pb_xz[j] - pa_yz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 5.0 * pa_yz[j] * fl1_fz * pb_xy[j] * fl1_fx + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xyz[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_xzz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xyzz[j]);

                t_yz_xzzz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pa_yz[j] * pb_xz[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_xzz[j] + pa_yz[j] * pb_xzzz[j]);

                t_yz_xzzz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 6.0 * pa_y[j] * fl1_fz * fl2_fx * pb_x[j] - 3.0 * pa_yz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_xz[j] * fl1_fx + 15.0 * pa_y[j] * fl1_fz * fl1_fx * pb_xzz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_xzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_70_80(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(9 * idx + 1);

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(9 * idx + 7);

            auto pa_zz = paDistances.data(9 * idx + 8);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxx = pbDistances.data(34 * idx + 9);

            auto pb_xxy = pbDistances.data(34 * idx + 10);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxxx = pbDistances.data(34 * idx + 19);

            auto pb_xxxy = pbDistances.data(34 * idx + 20);

            auto pb_xxxz = pbDistances.data(34 * idx + 21);

            auto pb_xxyy = pbDistances.data(34 * idx + 22);

            auto pb_xxyz = pbDistances.data(34 * idx + 23);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yz_yyyy = primBuffer.data(90 * idx + 70);

            auto t_yz_yyyz = primBuffer.data(90 * idx + 71);

            auto t_yz_yyzz = primBuffer.data(90 * idx + 72);

            auto t_yz_yzzz = primBuffer.data(90 * idx + 73);

            auto t_yz_zzzz = primBuffer.data(90 * idx + 74);

            auto t_zz_xxxx = primBuffer.data(90 * idx + 75);

            auto t_zz_xxxy = primBuffer.data(90 * idx + 76);

            auto t_zz_xxxz = primBuffer.data(90 * idx + 77);

            auto t_zz_xxyy = primBuffer.data(90 * idx + 78);

            auto t_zz_xxyz = primBuffer.data(90 * idx + 79);

            // Batch of Integrals (70,80)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_z, pa_zz, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, \
                                     pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xy, pb_xz, pb_y, pb_yy, pb_yyy, pb_yyyy, pb_yyyz, \
                                     pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, s_0_0, \
                                     t_yz_yyyy, t_yz_yyyz, t_yz_yyzz, t_yz_yzzz, t_yz_zzzz, t_zz_xxxx, t_zz_xxxy, \
                                     t_zz_xxxz, t_zz_xxyy, t_zz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yz_yyyy[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 3.0 * fl2_fx * pa_z[j] * pb_y[j] + 3.0 * pa_yz[j] * pb_yy[j] * fl1_fx + 2.0 * fl1_fx * pa_z[j] * pb_yyy[j] + pa_yz[j] * pb_yyyy[j]);

                t_yz_yyyy[j] += fl_r_0_0 * (-3.0 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * fl1_fx * pa_z[j] * pb_y[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl1_fz * fl2_fx + 24.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] - 6.0 * pa_yz[j] * pb_yy[j] * fl1_fz * fl1_fgb + 30.0 * pa_yz[j] * fl1_fz * pb_yy[j] * fl1_fx + 20.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yyy[j] + 12.0 * pa_yz[j] * fl1_fz * pb_yyyy[j]);

                t_yz_yyyz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_yy[j] + 1.5 * pa_yz[j] * pb_yz[j] * fl1_fx + 0.5 * pa_y[j] * fl1_fx * pb_yyy[j] + 1.5 * fl1_fx * pa_z[j] * pb_yyz[j] + pa_yz[j] * pb_yyyz[j]);

                t_yz_yyyz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_y[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fgb * pb_z[j] + 6.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] - 3.0 * pa_yz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_yz[j] * fl1_fx + 5.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yyy[j] + 15.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yyz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_yyyz[j]);

                t_yz_yyzz[j] = fl_s_0_0 * (0.25 * pa_yz[j] * fl2_fx + 0.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + fl2_fx * pb_yz[j] + 0.5 * pa_yz[j] * pb_yy[j] * fl1_fx + 0.5 * pa_yz[j] * fl1_fx * pb_zz[j] + pa_y[j] * fl1_fx * pb_yyz[j] + fl1_fx * pa_z[j] * pb_yzz[j] + pa_yz[j] * pb_yyzz[j]);

                t_yz_yyzz[j] += fl_r_0_0 * (-pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - pa_y[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] - fl1_fx * pa_z[j] * pb_y[j] * fl1_fz * fl1_fgb + 2.0 * pa_yz[j] * fl1_fz * fl2_fx + 4.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 8.0 * fl2_fx * fl1_fz * pb_yz[j] - pa_yz[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_yz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 5.0 * pa_yz[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_zz[j] + 10.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yyz[j] + 10.0 * fl1_fx * fl1_fz * pa_z[j] * pb_yzz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_yyzz[j]);

                t_yz_yzzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 1.5 * pa_yz[j] * pb_yz[j] * fl1_fx + 1.5 * pa_y[j] * fl1_fx * pb_yzz[j] + 0.5 * fl1_fx * pa_z[j] * pb_zzz[j] + pa_yz[j] * pb_yzzz[j]);

                t_yz_yzzz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 1.5 * pa_y[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fx * pa_z[j] * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_y[j] * fl1_fz * fl2_fx * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] - 3.0 * pa_yz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_yz[j] * fl1_fz * pb_yz[j] * fl1_fx + 15.0 * pa_y[j] * fl1_fz * fl1_fx * pb_yzz[j] + 5.0 * fl1_fx * fl1_fz * pa_z[j] * pb_zzz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_yzzz[j]);

                t_yz_zzzz[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 3.0 * pa_y[j] * fl2_fx * pb_z[j] + 3.0 * pa_yz[j] * pb_zz[j] * fl1_fx + 2.0 * pa_y[j] * fl1_fx * pb_zzz[j] + pa_yz[j] * pb_zzzz[j]);

                t_yz_zzzz[j] += fl_r_0_0 * (-3.0 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 6.0 * pa_y[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl1_fz * fl2_fx + 24.0 * pa_y[j] * fl1_fz * fl2_fx * pb_z[j] - 6.0 * pa_yz[j] * pb_zz[j] * fl1_fz * fl1_fgb + 30.0 * pa_yz[j] * fl1_fz * pb_zz[j] * fl1_fx + 20.0 * pa_y[j] * fl1_fz * fl1_fx * pb_zzz[j] + 12.0 * pa_yz[j] * fl1_fz * pb_zzzz[j]);

                t_zz_xxxx[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 1.5 * fl2_fx * pb_xx[j] + 3.0 * pa_zz[j] * pb_xx[j] * fl1_fx + 0.5 * fl1_fx * pb_xxxx[j] + pa_zz[j] * pb_xxxx[j]);

                t_zz_xxxx[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_zz[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 6.0 * pa_zz[j] * pb_xx[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_xx[j] + 30.0 * pa_zz[j] * fl1_fz * pb_xx[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxxx[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxx[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxxx[j]);

                t_zz_xxxy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_zz[j] * pb_xy[j] * fl1_fx + 0.5 * fl1_fx * pb_xxxy[j] + pa_zz[j] * pb_xxxy[j]);

                t_zz_xxxy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_zz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xy[j] + 15.0 * pa_zz[j] * fl1_fz * pb_xy[j] * fl1_fx - fl1_fz * fl1_fga * pb_xxxy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxy[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxxy[j]);

                t_zz_xxxz[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pb_xz[j] + 1.5 * pa_zz[j] * pb_xz[j] * fl1_fx + pa_z[j] * fl1_fx * pb_xxx[j] + 0.5 * fl1_fx * pb_xxxz[j] + pa_zz[j] * pb_xxxz[j]);

                t_zz_xxxz[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_z[j] * fl1_fz * fl2_fx * pb_x[j] - 1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_zz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xz[j] + 15.0 * pa_zz[j] * fl1_fz * pb_xz[j] * fl1_fx + 10.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xxx[j] - fl1_fz * fl1_fga * pb_xxxz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxxz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxxz[j]);

                t_zz_xxyy[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_zz[j] * fl2_fx + 0.25 * fl2_fx * pb_xx[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_zz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_zz[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pb_xxyy[j] + pa_zz[j] * pb_xxyy[j]);

                t_zz_xxyy[j] += fl_r_0_0 * (-0.5 * fl2_fx * fl1_fz * fl1_fgb - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb + 0.75 * fl1_fz * fl3_fx + 2.0 * pa_zz[j] * fl1_fz * fl2_fx - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yy[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yy[j] - pa_zz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_zz[j] * fl1_fz * fl1_fgb * pb_yy[j] + 2.0 * fl1_fz * fl2_fx * pb_xx[j] + 2.0 * fl1_fz * fl2_fx * pb_yy[j] + 5.0 * pa_zz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_yy[j] - fl1_fz * fl1_fga * pb_xxyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyy[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxyy[j]);

                t_zz_xxyz[j] = fl_s_0_0 * (0.5 * pa_z[j] * fl2_fx * pb_y[j] + 0.25 * fl2_fx * pb_yz[j] + 0.5 * pa_zz[j] * fl1_fx * pb_yz[j] + pa_z[j] * fl1_fx * pb_xxy[j] + 0.5 * fl1_fx * pb_xxyz[j] + pa_zz[j] * pb_xxyz[j]);

                t_zz_xxyz[j] += fl_r_0_0 * (-pa_z[j] * fl1_fx * fl1_fz * fl1_fgb * pb_y[j] + 4.0 * pa_z[j] * fl1_fz * fl2_fx * pb_y[j] - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_yz[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_yz[j] - pa_zz[j] * fl1_fz * fl1_fgb * pb_yz[j] + 2.0 * fl1_fz * fl2_fx * pb_yz[j] + 5.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_yz[j] + 10.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xxy[j] - fl1_fz * fl1_fga * pb_xxyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxyz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxyz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForDG_80_90(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_z = paDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_zz = paDistances.data(9 * idx + 8);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(34 * idx);

            auto pb_y = pbDistances.data(34 * idx + 1);

            auto pb_z = pbDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(34 * idx + 3);

            auto pb_xy = pbDistances.data(34 * idx + 4);

            auto pb_xz = pbDistances.data(34 * idx + 5);

            auto pb_yy = pbDistances.data(34 * idx + 6);

            auto pb_yz = pbDistances.data(34 * idx + 7);

            auto pb_zz = pbDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PB)

            auto pb_xxz = pbDistances.data(34 * idx + 11);

            auto pb_xyy = pbDistances.data(34 * idx + 12);

            auto pb_xyz = pbDistances.data(34 * idx + 13);

            auto pb_xzz = pbDistances.data(34 * idx + 14);

            auto pb_yyy = pbDistances.data(34 * idx + 15);

            auto pb_yyz = pbDistances.data(34 * idx + 16);

            auto pb_yzz = pbDistances.data(34 * idx + 17);

            auto pb_zzz = pbDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PB)

            auto pb_xxzz = pbDistances.data(34 * idx + 24);

            auto pb_xyyy = pbDistances.data(34 * idx + 25);

            auto pb_xyyz = pbDistances.data(34 * idx + 26);

            auto pb_xyzz = pbDistances.data(34 * idx + 27);

            auto pb_xzzz = pbDistances.data(34 * idx + 28);

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_zz_xxzz = primBuffer.data(90 * idx + 80);

            auto t_zz_xyyy = primBuffer.data(90 * idx + 81);

            auto t_zz_xyyz = primBuffer.data(90 * idx + 82);

            auto t_zz_xyzz = primBuffer.data(90 * idx + 83);

            auto t_zz_xzzz = primBuffer.data(90 * idx + 84);

            auto t_zz_yyyy = primBuffer.data(90 * idx + 85);

            auto t_zz_yyyz = primBuffer.data(90 * idx + 86);

            auto t_zz_yyzz = primBuffer.data(90 * idx + 87);

            auto t_zz_yzzz = primBuffer.data(90 * idx + 88);

            auto t_zz_zzzz = primBuffer.data(90 * idx + 89);

            // Batch of Integrals (80,90)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_z, pa_zz, pb_x, pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, \
                                     pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyyy, pb_yyyz, \
                                     pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, s_0_0, \
                                     t_zz_xxzz, t_zz_xyyy, t_zz_xyyz, t_zz_xyzz, t_zz_xzzz, t_zz_yyyy, t_zz_yyyz, \
                                     t_zz_yyzz, t_zz_yzzz, t_zz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_zz_xxzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_zz[j] * fl2_fx + pa_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_xx[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_zz[j] * pb_xx[j] * fl1_fx + 0.5 * pa_zz[j] * fl1_fx * pb_zz[j] + 2.0 * pa_z[j] * fl1_fx * pb_xxz[j] + 0.5 * fl1_fx * pb_xxzz[j] + pa_zz[j] * pb_xxzz[j]);

                t_zz_xxzz[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_zz[j] * fl1_fz * fl2_fx + 8.0 * pa_z[j] * fl1_fz * fl2_fx * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] - 0.5 * fl1_fx * pb_xx[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_xx[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_zz[j] * pb_xx[j] * fl1_fz * fl1_fgb - pa_zz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_zz[j] + 5.0 * pa_zz[j] * fl1_fz * pb_xx[j] * fl1_fx + 5.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_zz[j] + 20.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xxz[j] - fl1_fz * fl1_fga * pb_xxzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xxzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xxzz[j]);

                t_zz_xyyy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xy[j] + 1.5 * pa_zz[j] * pb_xy[j] * fl1_fx + 0.5 * fl1_fx * pb_xyyy[j] + pa_zz[j] * pb_xyyy[j]);

                t_zz_xyyy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - 3.0 * pa_zz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_xy[j] + 15.0 * pa_zz[j] * fl1_fz * pb_xy[j] * fl1_fx - fl1_fz * fl1_fga * pb_xyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyy[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xyyy[j]);

                t_zz_xyyz[j] = fl_s_0_0 * (0.5 * pa_z[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_zz[j] * pb_xz[j] * fl1_fx + pa_z[j] * fl1_fx * pb_xyy[j] + 0.5 * fl1_fx * pb_xyyz[j] + pa_zz[j] * pb_xyyz[j]);

                t_zz_xyyz[j] += fl_r_0_0 * (-pa_z[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 4.0 * pa_z[j] * fl1_fz * fl2_fx * pb_x[j] - 0.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - pa_zz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 2.0 * fl1_fz * fl2_fx * pb_xz[j] + 5.0 * pa_zz[j] * fl1_fz * pb_xz[j] * fl1_fx + 10.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xyy[j] - fl1_fz * fl1_fga * pb_xyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyyz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xyyz[j]);

                t_zz_xyzz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xy[j] + 0.5 * pa_zz[j] * pb_xy[j] * fl1_fx + 2.0 * pa_z[j] * fl1_fx * pb_xyz[j] + 0.5 * fl1_fx * pb_xyzz[j] + pa_zz[j] * pb_xyzz[j]);

                t_zz_xyzz[j] += fl_r_0_0 * (6.0 * fl2_fx * fl1_fz * pb_xy[j] - 0.5 * fl1_fx * pb_xy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pb_xy[j] * fl1_fx - pa_zz[j] * pb_xy[j] * fl1_fz * fl1_fgb + 5.0 * pa_zz[j] * fl1_fz * pb_xy[j] * fl1_fx + 20.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xyz[j] - fl1_fz * fl1_fga * pb_xyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xyzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xyzz[j]);

                t_zz_xzzz[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl2_fx * pb_x[j] + 2.25 * fl2_fx * pb_xz[j] + 1.5 * pa_zz[j] * pb_xz[j] * fl1_fx + 3.0 * pa_z[j] * fl1_fx * pb_xzz[j] + 0.5 * fl1_fx * pb_xzzz[j] + pa_zz[j] * pb_xzzz[j]);

                t_zz_xzzz[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fx * pb_x[j] * fl1_fz * fl1_fgb + 12.0 * pa_z[j] * fl1_fz * fl2_fx * pb_x[j] + 18.0 * fl2_fx * fl1_fz * pb_xz[j] - 1.5 * fl1_fx * pb_xz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_xz[j] * fl1_fx - 3.0 * pa_zz[j] * pb_xz[j] * fl1_fz * fl1_fgb + 15.0 * pa_zz[j] * fl1_fz * pb_xz[j] * fl1_fx + 30.0 * pa_z[j] * fl1_fz * fl1_fx * pb_xzz[j] - fl1_fz * fl1_fga * pb_xzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_xzzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_xzzz[j]);

                t_zz_yyyy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 1.5 * fl2_fx * pb_yy[j] + 3.0 * pa_zz[j] * pb_yy[j] * fl1_fx + 0.5 * fl1_fx * pb_yyyy[j] + pa_zz[j] * pb_yyyy[j]);

                t_zz_yyyy[j] += fl_r_0_0 * (-1.5 * fl2_fx * fl1_fz * fl1_fgb - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb + 2.25 * fl1_fz * fl3_fx + 6.0 * pa_zz[j] * fl1_fz * fl2_fx - 3.0 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 6.0 * pa_zz[j] * pb_yy[j] * fl1_fz * fl1_fgb + 12.0 * fl1_fz * fl2_fx * pb_yy[j] + 30.0 * pa_zz[j] * fl1_fz * pb_yy[j] * fl1_fx - fl1_fz * fl1_fga * pb_yyyy[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyy[j] + 12.0 * pa_zz[j] * fl1_fz * pb_yyyy[j]);

                t_zz_yyyz[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pb_yz[j] + 1.5 * pa_zz[j] * pb_yz[j] * fl1_fx + pa_z[j] * fl1_fx * pb_yyy[j] + 0.5 * fl1_fx * pb_yyyz[j] + pa_zz[j] * pb_yyyz[j]);

                t_zz_yyyz[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_z[j] * fl1_fz * fl2_fx * pb_y[j] - 1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_zz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 6.0 * fl1_fz * fl2_fx * pb_yz[j] + 15.0 * pa_zz[j] * fl1_fz * pb_yz[j] * fl1_fx + 10.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yyy[j] - fl1_fz * fl1_fga * pb_yyyz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyyz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_yyyz[j]);

                t_zz_yyzz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.25 * pa_zz[j] * fl2_fx + pa_z[j] * fl2_fx * pb_z[j] + 0.75 * fl2_fx * pb_yy[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_zz[j] * pb_yy[j] * fl1_fx + 0.5 * pa_zz[j] * fl1_fx * pb_zz[j] + 2.0 * pa_z[j] * fl1_fx * pb_yyz[j] + 0.5 * fl1_fx * pb_yyzz[j] + pa_zz[j] * pb_yyzz[j]);

                t_zz_yyzz[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fgb + 2.25 * fl3_fx * fl1_fz - 0.25 * fl1_fz * fl1_fga * fl2_fx - pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 2.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fgb * pb_z[j] + 2.0 * pa_zz[j] * fl1_fz * fl2_fx + 8.0 * pa_z[j] * fl1_fz * fl2_fx * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] - 0.5 * fl1_fx * pb_yy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fx * fl1_fz * fl1_fgb * pb_zz[j] - 0.5 * fl1_fz * fl1_fga * pb_yy[j] * fl1_fx - 0.5 * fl1_fz * fl1_fga * fl1_fx * pb_zz[j] - pa_zz[j] * pb_yy[j] * fl1_fz * fl1_fgb - pa_zz[j] * fl1_fz * fl1_fgb * pb_zz[j] + 2.0 * fl1_fz * fl2_fx * pb_zz[j] + 5.0 * pa_zz[j] * fl1_fz * pb_yy[j] * fl1_fx + 5.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_zz[j] + 20.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yyz[j] - fl1_fz * fl1_fga * pb_yyzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yyzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_yyzz[j]);

                t_zz_yzzz[j] = fl_s_0_0 * (1.5 * pa_z[j] * fl2_fx * pb_y[j] + 2.25 * fl2_fx * pb_yz[j] + 1.5 * pa_zz[j] * pb_yz[j] * fl1_fx + 3.0 * pa_z[j] * fl1_fx * pb_yzz[j] + 0.5 * fl1_fx * pb_yzzz[j] + pa_zz[j] * pb_yzzz[j]);

                t_zz_yzzz[j] += fl_r_0_0 * (-3.0 * pa_z[j] * fl1_fx * pb_y[j] * fl1_fz * fl1_fgb + 12.0 * pa_z[j] * fl1_fz * fl2_fx * pb_y[j] + 18.0 * fl2_fx * fl1_fz * pb_yz[j] - 1.5 * fl1_fx * pb_yz[j] * fl1_fz * fl1_fgb - 1.5 * fl1_fz * fl1_fga * pb_yz[j] * fl1_fx - 3.0 * pa_zz[j] * pb_yz[j] * fl1_fz * fl1_fgb + 15.0 * pa_zz[j] * fl1_fz * pb_yz[j] * fl1_fx + 30.0 * pa_z[j] * fl1_fz * fl1_fx * pb_yzz[j] - fl1_fz * fl1_fga * pb_yzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_yzzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_yzzz[j]);

                t_zz_zzzz[j] = fl_s_0_0 * (1.875 * fl3_fx + 0.75 * pa_zz[j] * fl2_fx + 6.0 * pa_z[j] * fl2_fx * pb_z[j] + 4.5 * fl2_fx * pb_zz[j] + 3.0 * pa_zz[j] * pb_zz[j] * fl1_fx + 4.0 * pa_z[j] * fl1_fx * pb_zzz[j] + 0.5 * fl1_fx * pb_zzzz[j] + pa_zz[j] * pb_zzzz[j]);

                t_zz_zzzz[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fgb + 11.25 * fl3_fx * fl1_fz - 0.75 * fl1_fz * fl1_fga * fl2_fx - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 12.0 * pa_z[j] * fl1_fx * pb_z[j] * fl1_fz * fl1_fgb + 6.0 * pa_zz[j] * fl1_fz * fl2_fx + 48.0 * pa_z[j] * fl1_fz * fl2_fx * pb_z[j] + 36.0 * fl2_fx * fl1_fz * pb_zz[j] - 3.0 * fl1_fx * pb_zz[j] * fl1_fz * fl1_fgb - 3.0 * fl1_fz * fl1_fga * pb_zz[j] * fl1_fx - 6.0 * pa_zz[j] * pb_zz[j] * fl1_fz * fl1_fgb + 30.0 * pa_zz[j] * fl1_fz * pb_zz[j] * fl1_fx + 40.0 * pa_z[j] * fl1_fz * fl1_fx * pb_zzz[j] - fl1_fz * fl1_fga * pb_zzzz[j] + 5.0 * fl1_fz * fl1_fx * pb_zzzz[j] + 12.0 * pa_zz[j] * fl1_fz * pb_zzzz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
        kinrecfunc::compKineticEnergyForGD_0_10(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_10_20(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_20_30(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_30_40(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_40_50(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_50_60(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_60_70(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_70_80(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 

        kinrecfunc::compKineticEnergyForGD_80_90(primBuffer, auxBuffer, osFactors, paDistances, pbDistances, 
                                                 braGtoBlock, ketGtoBlock, iContrGto); 
    }

    void
    compKineticEnergyForGD_0_10(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(34 * idx + 3);

            auto pa_xy = paDistances.data(34 * idx + 4);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxx = paDistances.data(34 * idx + 9);

            auto pa_xxy = paDistances.data(34 * idx + 10);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xxxx = paDistances.data(34 * idx + 19);

            auto pa_xxxy = paDistances.data(34 * idx + 20);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxxx_xx = primBuffer.data(90 * idx);

            auto t_xxxx_xy = primBuffer.data(90 * idx + 1);

            auto t_xxxx_xz = primBuffer.data(90 * idx + 2);

            auto t_xxxx_yy = primBuffer.data(90 * idx + 3);

            auto t_xxxx_yz = primBuffer.data(90 * idx + 4);

            auto t_xxxx_zz = primBuffer.data(90 * idx + 5);

            auto t_xxxy_xx = primBuffer.data(90 * idx + 6);

            auto t_xxxy_xy = primBuffer.data(90 * idx + 7);

            auto t_xxxy_xz = primBuffer.data(90 * idx + 8);

            auto t_xxxy_yy = primBuffer.data(90 * idx + 9);

            // Batch of Integrals (0,10)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxx, pa_xxxy, pa_xxy, pa_xy, pa_y, pb_x, \
                                     pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xxxx_xx, \
                                     t_xxxx_xy, t_xxxx_xz, t_xxxx_yy, t_xxxx_yz, t_xxxx_zz, t_xxxy_xx, t_xxxy_xy, \
                                     t_xxxy_xz, t_xxxy_yy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxxx_xx[j] = fl_s_0_0 * (1.875 * fl3_fx + 4.5 * pa_xx[j] * fl2_fx + 6.0 * pa_x[j] * fl2_fx * pb_x[j] + 0.5 * pa_xxxx[j] * fl1_fx + 4.0 * pa_xxx[j] * fl1_fx * pb_x[j] + 0.75 * fl2_fx * pb_xx[j] + 3.0 * pa_xx[j] * fl1_fx * pb_xx[j] + pa_xxxx[j] * pb_xx[j]);

                t_xxxx_xx[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fga + 11.25 * fl3_fx * fl1_fz + 36.0 * pa_xx[j] * fl2_fx * fl1_fz - 0.75 * fl2_fx * fl1_fz * fl1_fgb - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 12.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - pa_xxxx[j] * fl1_fz * fl1_fgb + 48.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 5.0 * pa_xxxx[j] * fl1_fz * fl1_fx + 40.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_xx[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_xx[j]);

                t_xxxx_xy[j] = fl_s_0_0 * (3.0 * pa_x[j] * fl2_fx * pb_y[j] + 2.0 * pa_xxx[j] * fl1_fx * pb_y[j] + 0.75 * fl2_fx * pb_xy[j] + 3.0 * pa_xx[j] * fl1_fx * pb_xy[j] + pa_xxxx[j] * pb_xy[j]);

                t_xxxx_xy[j] += fl_r_0_0 * (-6.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 24.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 20.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_xy[j] + 6.0 * fl2_fx * fl1_fz * pb_xy[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_xy[j]);

                t_xxxx_xz[j] = fl_s_0_0 * (3.0 * pa_x[j] * fl2_fx * pb_z[j] + 2.0 * pa_xxx[j] * fl1_fx * pb_z[j] + 0.75 * fl2_fx * pb_xz[j] + 3.0 * pa_xx[j] * fl1_fx * pb_xz[j] + pa_xxxx[j] * pb_xz[j]);

                t_xxxx_xz[j] += fl_r_0_0 * (-6.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 24.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 20.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_xz[j] + 6.0 * fl2_fx * fl1_fz * pb_xz[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_xz[j]);

                t_xxxx_yy[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_xx[j] * fl2_fx + 0.5 * pa_xxxx[j] * fl1_fx + 0.75 * fl2_fx * pb_yy[j] + 3.0 * pa_xx[j] * fl1_fx * pb_yy[j] + pa_xxxx[j] * pb_yy[j]);

                t_xxxx_yy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_xxxx[j] * fl1_fz * fl1_fgb + 12.0 * pa_xx[j] * fl1_fz * fl2_fx + 5.0 * pa_xxxx[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_yy[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_yy[j]);

                t_xxxx_yz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_yz[j] + 3.0 * pa_xx[j] * fl1_fx * pb_yz[j] + pa_xxxx[j] * pb_yz[j]);

                t_xxxx_yz[j] += fl_r_0_0 * (-3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_yz[j] + 6.0 * fl2_fx * fl1_fz * pb_yz[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_yz[j]);

                t_xxxx_zz[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_xx[j] * fl2_fx + 0.5 * pa_xxxx[j] * fl1_fx + 0.75 * fl2_fx * pb_zz[j] + 3.0 * pa_xx[j] * fl1_fx * pb_zz[j] + pa_xxxx[j] * pb_zz[j]);

                t_xxxx_zz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_xxxx[j] * fl1_fz * fl1_fgb + 12.0 * pa_xx[j] * fl1_fz * fl2_fx + 5.0 * pa_xxxx[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - 6.0 * pa_xx[j] * fl1_fz * fl1_fga * pb_zz[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] + 30.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_xxxx[j] * fl1_fz * pb_zz[j]);

                t_xxxy_xx[j] = fl_s_0_0 * (2.25 * pa_xy[j] * fl2_fx + 1.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xxxy[j] * fl1_fx + 3.0 * pa_xxy[j] * fl1_fx * pb_x[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xx[j] + pa_xxxy[j] * pb_xx[j]);

                t_xxxy_xx[j] += fl_r_0_0 * (18.0 * pa_xy[j] * fl2_fx * fl1_fz - 1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pa_y[j] * pb_x[j] - pa_xxxy[j] * fl1_fz * fl1_fgb + 12.0 * fl2_fx * fl1_fz * pa_y[j] * pb_x[j] + 5.0 * pa_xxxy[j] * fl1_fz * fl1_fx + 30.0 * pa_xxy[j] * fl1_fx * fl1_fz * pb_x[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_xx[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_xx[j]);

                t_xxxy_xy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_x[j] + 1.5 * pa_xxy[j] * fl1_fx * pb_y[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xy[j] + pa_xxxy[j] * pb_xy[j]);

                t_xxxy_xy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_xx[j] * fl2_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_x[j] - 1.5 * fl1_fx * fl1_fz * fl1_fga * pa_y[j] * pb_y[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_y[j] + 5.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_x[j] + 15.0 * pa_xxy[j] * fl1_fx * fl1_fz * pb_y[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_xy[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_xy[j]);

                t_xxxy_xz[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 1.5 * pa_xxy[j] * fl1_fx * pb_z[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xz[j] + pa_xxxy[j] * pb_xz[j]);

                t_xxxy_xz[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pa_y[j] * pb_z[j] + 6.0 * fl2_fx * fl1_fz * pa_y[j] * pb_z[j] + 15.0 * pa_xxy[j] * fl1_fx * fl1_fz * pb_z[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_xz[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_xz[j]);

                t_xxxy_yy[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xxxy[j] * fl1_fx + pa_xxx[j] * fl1_fx * pb_y[j] + 1.5 * pa_xy[j] * fl1_fx * pb_yy[j] + pa_xxxy[j] * pb_yy[j]);

                t_xxxy_yy[j] += fl_r_0_0 * (-1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_y[j] - pa_xxxy[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl2_fx * fl1_fz + 12.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_xxxy[j] * fl1_fz * fl1_fx + 10.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_yy[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_yy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_10_20(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(34 * idx + 3);

            auto pa_xy = paDistances.data(34 * idx + 4);

            auto pa_xz = paDistances.data(34 * idx + 5);

            auto pa_yy = paDistances.data(34 * idx + 6);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxx = paDistances.data(34 * idx + 9);

            auto pa_xxy = paDistances.data(34 * idx + 10);

            auto pa_xxz = paDistances.data(34 * idx + 11);

            auto pa_xyy = paDistances.data(34 * idx + 12);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xxxy = paDistances.data(34 * idx + 20);

            auto pa_xxxz = paDistances.data(34 * idx + 21);

            auto pa_xxyy = paDistances.data(34 * idx + 22);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxxy_yz = primBuffer.data(90 * idx + 10);

            auto t_xxxy_zz = primBuffer.data(90 * idx + 11);

            auto t_xxxz_xx = primBuffer.data(90 * idx + 12);

            auto t_xxxz_xy = primBuffer.data(90 * idx + 13);

            auto t_xxxz_xz = primBuffer.data(90 * idx + 14);

            auto t_xxxz_yy = primBuffer.data(90 * idx + 15);

            auto t_xxxz_yz = primBuffer.data(90 * idx + 16);

            auto t_xxxz_zz = primBuffer.data(90 * idx + 17);

            auto t_xxyy_xx = primBuffer.data(90 * idx + 18);

            auto t_xxyy_xy = primBuffer.data(90 * idx + 19);

            // Batch of Integrals (10,20)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxy, pa_xxxz, pa_xxy, pa_xxyy, pa_xxz, \
                                     pa_xy, pa_xyy, pa_xz, pa_y, pa_yy, pa_z, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, \
                                     pb_z, pb_zz, r_0_0, s_0_0, t_xxxy_yz, t_xxxy_zz, t_xxxz_xx, t_xxxz_xy, t_xxxz_xz, \
                                     t_xxxz_yy, t_xxxz_yz, t_xxxz_zz, t_xxyy_xx, t_xxyy_xy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxxy_yz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pa_xy[j] * fl1_fx * pb_yz[j] + pa_xxxy[j] * pb_yz[j]);

                t_xxxy_yz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_z[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_yz[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_yz[j]);

                t_xxxy_zz[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 0.5 * pa_xxxy[j] * fl1_fx + 1.5 * pa_xy[j] * fl1_fx * pb_zz[j] + pa_xxxy[j] * pb_zz[j]);

                t_xxxy_zz[j] += fl_r_0_0 * (-1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - pa_xxxy[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl2_fx * fl1_fz + 5.0 * pa_xxxy[j] * fl1_fz * fl1_fx - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_xy[j] * fl1_fx * fl1_fz * pb_zz[j] + 12.0 * pa_xxxy[j] * fl1_fz * pb_zz[j]);

                t_xxxz_xx[j] = fl_s_0_0 * (2.25 * pa_xz[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xxxz[j] * fl1_fx + 3.0 * pa_xxz[j] * fl1_fx * pb_x[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xx[j] + pa_xxxz[j] * pb_xx[j]);

                t_xxxz_xx[j] += fl_r_0_0 * (18.0 * pa_xz[j] * fl2_fx * fl1_fz - 1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_x[j] - pa_xxxz[j] * fl1_fz * fl1_fgb + 12.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 5.0 * pa_xxxz[j] * fl1_fz * fl1_fx + 30.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_x[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xx[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_xx[j]);

                t_xxxz_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 1.5 * pa_xxz[j] * fl1_fx * pb_y[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xy[j] + pa_xxxz[j] * pb_xy[j]);

                t_xxxz_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 15.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_y[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xy[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_xy[j]);

                t_xxxz_xz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_x[j] + 1.5 * pa_xxz[j] * fl1_fx * pb_z[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xz[j] + pa_xxxz[j] * pb_xz[j]);

                t_xxxz_xz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_xx[j] * fl2_fx * fl1_fz - 1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_x[j] - 1.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_z[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 5.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_x[j] + 15.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_z[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xz[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_xz[j]);

                t_xxxz_yy[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 0.5 * pa_xxxz[j] * fl1_fx + 1.5 * pa_xz[j] * fl1_fx * pb_yy[j] + pa_xxxz[j] * pb_yy[j]);

                t_xxxz_yy[j] += fl_r_0_0 * (-1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - pa_xxxz[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl2_fx * fl1_fz + 5.0 * pa_xxxz[j] * fl1_fz * fl1_fx - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_yy[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_yy[j]);

                t_xxxz_yz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xxx[j] * fl1_fx * pb_y[j] + 1.5 * pa_xz[j] * fl1_fx * pb_yz[j] + pa_xxxz[j] * pb_yz[j]);

                t_xxxz_yz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_y[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_yz[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_yz[j]);

                t_xxxz_zz[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 1.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xxxz[j] * fl1_fx + pa_xxx[j] * fl1_fx * pb_z[j] + 1.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_xxxz[j] * pb_zz[j]);

                t_xxxz_zz[j] += fl_r_0_0 * (-1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_xxxz[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl2_fx * fl1_fz + 12.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_xxxz[j] * fl1_fz * fl1_fx + 10.0 * pa_xxx[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_zz[j] + 12.0 * pa_xxxz[j] * fl1_fz * pb_zz[j]);

                t_xxyy_xx[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_yy[j] + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.5 * pa_xxyy[j] * fl1_fx + 2.0 * pa_xyy[j] * fl1_fx * pb_x[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_yy[j] * pb_xx[j] + pa_xxyy[j] * pb_xx[j]);

                t_xxyy_xx[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_yy[j] * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 2.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - 0.5 * fl1_fx * pa_yy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_yy[j] * fl1_fx - pa_xxyy[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 8.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 5.0 * pa_xxyy[j] * fl1_fz * fl1_fx + 20.0 * pa_xyy[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xx[j] + 2.0 * fl2_fx * fl1_fz * pb_xx[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_xx[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xx[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_xx[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_xx[j]);

                t_xxyy_xy[j] = fl_s_0_0 * (pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + pa_xxy[j] * fl1_fx * pb_x[j] + pa_xyy[j] * fl1_fx * pb_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_yy[j] * pb_xy[j] + pa_xxyy[j] * pb_xy[j]);

                t_xxyy_xy[j] += fl_r_0_0 * (8.0 * pa_xy[j] * fl2_fx * fl1_fz - pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_x[j] + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 4.0 * fl2_fx * pa_y[j] * fl1_fz * pb_x[j] + 10.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_x[j] + 10.0 * pa_xyy[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xy[j] + 2.0 * fl2_fx * fl1_fz * pb_xy[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_xy[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xy[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_xy[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_xy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_20_30(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(34 * idx + 3);

            auto pa_xy = paDistances.data(34 * idx + 4);

            auto pa_xz = paDistances.data(34 * idx + 5);

            auto pa_yy = paDistances.data(34 * idx + 6);

            auto pa_yz = paDistances.data(34 * idx + 7);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxy = paDistances.data(34 * idx + 10);

            auto pa_xxz = paDistances.data(34 * idx + 11);

            auto pa_xyy = paDistances.data(34 * idx + 12);

            auto pa_xyz = paDistances.data(34 * idx + 13);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xxyy = paDistances.data(34 * idx + 22);

            auto pa_xxyz = paDistances.data(34 * idx + 23);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxyy_xz = primBuffer.data(90 * idx + 20);

            auto t_xxyy_yy = primBuffer.data(90 * idx + 21);

            auto t_xxyy_yz = primBuffer.data(90 * idx + 22);

            auto t_xxyy_zz = primBuffer.data(90 * idx + 23);

            auto t_xxyz_xx = primBuffer.data(90 * idx + 24);

            auto t_xxyz_xy = primBuffer.data(90 * idx + 25);

            auto t_xxyz_xz = primBuffer.data(90 * idx + 26);

            auto t_xxyz_yy = primBuffer.data(90 * idx + 27);

            auto t_xxyz_yz = primBuffer.data(90 * idx + 28);

            auto t_xxyz_zz = primBuffer.data(90 * idx + 29);

            // Batch of Integrals (20,30)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxyy, pa_xxyz, pa_xxz, pa_xy, pa_xyy, \
                                     pa_xyz, pa_xz, pa_y, pa_yy, pa_yz, pa_z, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, \
                                     pb_zz, r_0_0, s_0_0, t_xxyy_xz, t_xxyy_yy, t_xxyy_yz, t_xxyy_zz, t_xxyz_xx, \
                                     t_xxyz_xy, t_xxyz_xz, t_xxyz_yy, t_xxyz_yz, t_xxyz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxyy_xz[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_z[j] + pa_xyy[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_yy[j] * pb_xz[j] + pa_xxyy[j] * pb_xz[j]);

                t_xxyy_xz[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 10.0 * pa_xyy[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xz[j] + 2.0 * fl2_fx * fl1_fz * pb_xz[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_xz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xz[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_xz[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_xz[j]);

                t_xxyy_yy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_yy[j] + fl2_fx * pa_y[j] * pb_y[j] + 0.5 * pa_xxyy[j] * fl1_fx + 2.0 * pa_xxy[j] * fl1_fx * pb_y[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_yy[j] * pb_yy[j] + pa_xxyy[j] * pb_yy[j]);

                t_xxyy_yy[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * fl2_fx + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_xx[j] * fl2_fx * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_yy[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_yy[j] * fl1_fx - 2.0 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_y[j] - pa_xxyy[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * pa_yy[j] * fl1_fz + 8.0 * fl2_fx * pa_y[j] * fl1_fz * pb_y[j] + 5.0 * pa_xxyy[j] * fl1_fz * fl1_fx + 20.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_yy[j] + 2.0 * fl2_fx * fl1_fz * pb_yy[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_yy[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yy[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_yy[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_yy[j]);

                t_xxyy_yz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_y[j] * pb_z[j] + pa_xxy[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_yz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_yy[j] * pb_yz[j] + pa_xxyy[j] * pb_yz[j]);

                t_xxyy_yz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_z[j] + 4.0 * fl2_fx * pa_y[j] * fl1_fz * pb_z[j] + 10.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_yz[j] + 2.0 * fl2_fx * fl1_fz * pb_yz[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_yz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_yz[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_yz[j]);

                t_xxyy_zz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_yy[j] + 0.5 * pa_xxyy[j] * fl1_fx + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_yy[j] * pb_zz[j] + pa_xxyy[j] * pb_zz[j]);

                t_xxyy_zz[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * fl2_fx * fl1_fz * fl1_fga - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_yy[j] * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * pa_yy[j] * fl1_fx - pa_xxyy[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 2.0 * fl2_fx * pa_yy[j] * fl1_fz + 5.0 * pa_xxyy[j] * fl1_fz * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_zz[j] + 2.0 * fl2_fx * fl1_fz * pb_zz[j] - fl1_fz * fl1_fga * pa_yy[j] * pb_zz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_zz[j] + 5.0 * fl1_fx * pa_yy[j] * fl1_fz * pb_zz[j] + 12.0 * pa_xxyy[j] * fl1_fz * pb_zz[j]);

                t_xxyz_xx[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_yz[j] + 0.5 * pa_xxyz[j] * fl1_fx + 2.0 * pa_xyz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yz[j] * pb_xx[j] + pa_xxyz[j] * pb_xx[j]);

                t_xxyz_xx[j] += fl_r_0_0 * (6.0 * fl2_fx * pa_yz[j] * fl1_fz - 0.5 * fl1_fx * pa_yz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_yz[j] * fl1_fx - pa_xxyz[j] * fl1_fz * fl1_fgb + 5.0 * pa_xxyz[j] * fl1_fz * fl1_fx + 20.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_xx[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_xx[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_xx[j]);

                t_xxyz_xy[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl2_fx + 0.25 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xxz[j] * fl1_fx * pb_x[j] + pa_xyz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_yz[j] * pb_xy[j] + pa_xxyz[j] * pb_xy[j]);

                t_xxyz_xy[j] += fl_r_0_0 * (4.0 * pa_xz[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * fl1_fx * pa_z[j] * pb_x[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 5.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_x[j] + 10.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_xy[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_xy[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_xy[j]);

                t_xxyz_xz[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl2_fx + 0.25 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xxy[j] * fl1_fx * pb_x[j] + pa_xyz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_yz[j] * pb_xz[j] + pa_xxyz[j] * pb_xz[j]);

                t_xxyz_xz[j] += fl_r_0_0 * (4.0 * pa_xy[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_x[j] + 2.0 * fl2_fx * pa_y[j] * fl1_fz * pb_x[j] + 5.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_x[j] + 10.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_xz[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_xz[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_xz[j]);

                t_xxyz_yy[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_xxyz[j] * fl1_fx + pa_xxz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_yz[j] * pb_yy[j] + pa_xxyz[j] * pb_yy[j]);

                t_xxyz_yy[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_yz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_yz[j] * fl1_fx - fl1_fz * fl1_fga * fl1_fx * pa_z[j] * pb_y[j] - pa_xxyz[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * pa_yz[j] * fl1_fz + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 5.0 * pa_xxyz[j] * fl1_fz * fl1_fx + 10.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_yy[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_yy[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_yy[j]);

                t_xxyz_yz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xxy[j] * fl1_fx * pb_y[j] + 0.5 * pa_xxz[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_yz[j] * pb_yz[j] + pa_xxyz[j] * pb_yz[j]);

                t_xxyz_yz[j] += fl_r_0_0 * (-0.25 * fl1_fz * fl1_fga * fl2_fx + 0.75 * fl3_fx * fl1_fz + 2.0 * pa_xx[j] * fl2_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_y[j] - 0.5 * fl1_fz * fl1_fga * fl1_fx * pa_z[j] * pb_z[j] + 2.0 * fl2_fx * pa_y[j] * fl1_fz * pb_y[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 5.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_y[j] + 5.0 * pa_xxz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_yz[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_yz[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_yz[j]);

                t_xxyz_zz[j] = fl_s_0_0 * (0.25 * fl2_fx * pa_yz[j] + 0.5 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * pa_xxyz[j] * fl1_fx + pa_xxy[j] * fl1_fx * pb_z[j] + 0.5 * fl1_fx * pa_yz[j] * pb_zz[j] + pa_xxyz[j] * pb_zz[j]);

                t_xxyz_zz[j] += fl_r_0_0 * (-0.5 * fl1_fx * pa_yz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_yz[j] * fl1_fx - fl1_fz * fl1_fga * pa_y[j] * fl1_fx * pb_z[j] - pa_xxyz[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * pa_yz[j] * fl1_fz + 4.0 * fl2_fx * pa_y[j] * fl1_fz * pb_z[j] + 5.0 * pa_xxyz[j] * fl1_fz * fl1_fx + 10.0 * pa_xxy[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fz * fl1_fga * pa_yz[j] * pb_zz[j] + 5.0 * fl1_fx * pa_yz[j] * fl1_fz * pb_zz[j] + 12.0 * pa_xxyz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_30_40(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xx = paDistances.data(34 * idx + 3);

            auto pa_xy = paDistances.data(34 * idx + 4);

            auto pa_xz = paDistances.data(34 * idx + 5);

            auto pa_yy = paDistances.data(34 * idx + 6);

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxz = paDistances.data(34 * idx + 11);

            auto pa_xyy = paDistances.data(34 * idx + 12);

            auto pa_xzz = paDistances.data(34 * idx + 14);

            auto pa_yyy = paDistances.data(34 * idx + 15);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xxzz = paDistances.data(34 * idx + 24);

            auto pa_xyyy = paDistances.data(34 * idx + 25);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxzz_xx = primBuffer.data(90 * idx + 30);

            auto t_xxzz_xy = primBuffer.data(90 * idx + 31);

            auto t_xxzz_xz = primBuffer.data(90 * idx + 32);

            auto t_xxzz_yy = primBuffer.data(90 * idx + 33);

            auto t_xxzz_yz = primBuffer.data(90 * idx + 34);

            auto t_xxzz_zz = primBuffer.data(90 * idx + 35);

            auto t_xyyy_xx = primBuffer.data(90 * idx + 36);

            auto t_xyyy_xy = primBuffer.data(90 * idx + 37);

            auto t_xyyy_xz = primBuffer.data(90 * idx + 38);

            auto t_xyyy_yy = primBuffer.data(90 * idx + 39);

            // Batch of Integrals (30,40)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxz, pa_xxzz, pa_xy, pa_xyy, pa_xyyy, pa_xz, \
                                     pa_xzz, pa_y, pa_yy, pa_yyy, pa_z, pa_zz, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, \
                                     pb_z, pb_zz, r_0_0, s_0_0, t_xxzz_xx, t_xxzz_xy, t_xxzz_xz, t_xxzz_yy, t_xxzz_yz, \
                                     t_xxzz_zz, t_xyyy_xx, t_xyyy_xy, t_xyyy_xz, t_xyyy_yy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xxzz_xx[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.25 * pa_xx[j] * fl2_fx + pa_x[j] * fl2_fx * pb_x[j] + 0.5 * pa_xxzz[j] * fl1_fx + 2.0 * pa_xzz[j] * fl1_fx * pb_x[j] + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xx[j] + pa_xxzz[j] * pb_xx[j]);

                t_xxzz_xx[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_zz[j] * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 2.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - pa_xxzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 8.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 5.0 * pa_xxzz[j] * fl1_fz * fl1_fx + 20.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xx[j] + 2.0 * fl2_fx * fl1_fz * pb_xx[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xx[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xx[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xx[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_xx[j]);

                t_xxzz_xy[j] = fl_s_0_0 * (0.5 * pa_x[j] * fl2_fx * pb_y[j] + pa_xzz[j] * fl1_fx * pb_y[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xy[j] + pa_xxzz[j] * pb_xy[j]);

                t_xxzz_xy[j] += fl_r_0_0 * (-pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 10.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xy[j] + 2.0 * fl2_fx * fl1_fz * pb_xy[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xy[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xy[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xy[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_xy[j]);

                t_xxzz_xz[j] = fl_s_0_0 * (pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + pa_xxz[j] * fl1_fx * pb_x[j] + pa_xzz[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xz[j] + pa_xxzz[j] * pb_xz[j]);

                t_xxzz_xz[j] += fl_r_0_0 * (8.0 * pa_xz[j] * fl2_fx * fl1_fz - pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_x[j] + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 4.0 * fl2_fx * pa_z[j] * fl1_fz * pb_x[j] + 10.0 * pa_xxz[j] * fl1_fz * fl1_fx * pb_x[j] + 10.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_xz[j] + 2.0 * fl2_fx * fl1_fz * pb_xz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_xz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xz[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_xz[j]);

                t_xxzz_yy[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_zz[j] + 0.5 * pa_xxzz[j] * fl1_fx + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_yy[j] + pa_xxzz[j] * pb_yy[j]);

                t_xxzz_yy[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * fl2_fx * fl1_fz * fl1_fga - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - pa_xxzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xx[j] * fl1_fz * fl2_fx + 2.0 * fl2_fx * pa_zz[j] * fl1_fz + 5.0 * pa_xxzz[j] * fl1_fz * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_yy[j] + 2.0 * fl2_fx * fl1_fz * pb_yy[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_yy[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yy[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_yy[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_yy[j]);

                t_xxzz_yz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_z[j] * pb_y[j] + pa_xxz[j] * fl1_fx * pb_y[j] + 0.25 * fl2_fx * pb_yz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_yz[j] + pa_xxzz[j] * pb_yz[j]);

                t_xxzz_yz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_y[j] + 4.0 * fl2_fx * pa_z[j] * fl1_fz * pb_y[j] + 10.0 * pa_xxz[j] * fl1_fz * fl1_fx * pb_y[j] - fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_yz[j] + 2.0 * fl2_fx * fl1_fz * pb_yz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_yz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_yz[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_yz[j]);

                t_xxzz_zz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_xx[j] * fl2_fx + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xxzz[j] * fl1_fx + 2.0 * pa_xxz[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_xx[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] + pa_xxzz[j] * pb_zz[j]);

                t_xxzz_zz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * fl2_fx + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_xx[j] * fl2_fx * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xx[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - 2.0 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_z[j] - pa_xxzz[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * pa_zz[j] * fl1_fz + 8.0 * fl2_fx * pa_z[j] * fl1_fz * pb_z[j] + 5.0 * pa_xxzz[j] * fl1_fz * fl1_fx + 20.0 * pa_xxz[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - pa_xx[j] * fl1_fz * fl1_fga * pb_zz[j] + 2.0 * fl2_fx * fl1_fz * pb_zz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_zz[j] + 5.0 * pa_xx[j] * fl1_fz * fl1_fx * pb_zz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_zz[j] + 12.0 * pa_xxzz[j] * fl1_fz * pb_zz[j]);

                t_xyyy_xx[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 1.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xyyy[j] * fl1_fx + fl1_fx * pa_yyy[j] * pb_x[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xx[j] + pa_xyyy[j] * pb_xx[j]);

                t_xyyy_xx[j] += fl_r_0_0 * (-1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_x[j] - pa_xyyy[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl1_fz * fl2_fx + 12.0 * fl2_fx * pa_y[j] * fl1_fz * pb_x[j] + 5.0 * pa_xyyy[j] * fl1_fz * fl1_fx + 10.0 * fl1_fx * pa_yyy[j] * fl1_fz * pb_x[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_xx[j]);

                t_xyyy_xy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_yy[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_y[j] * pb_y[j] + 1.5 * pa_xyy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yyy[j] * pb_y[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xy[j] + pa_xyyy[j] * pb_xy[j]);

                t_xyyy_xy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_yy[j] * fl1_fz - 1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - 1.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_y[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 6.0 * fl2_fx * pa_y[j] * fl1_fz * pb_y[j] + 15.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_x[j] + 5.0 * fl1_fx * pa_yyy[j] * fl1_fz * pb_y[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_xy[j]);

                t_xyyy_xz[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_y[j] * pb_z[j] + 0.5 * fl1_fx * pa_yyy[j] * pb_z[j] + 1.5 * pa_xy[j] * fl1_fx * pb_xz[j] + pa_xyyy[j] * pb_xz[j]);

                t_xyyy_xz[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_z[j] + 6.0 * fl2_fx * pa_y[j] * fl1_fz * pb_z[j] + 5.0 * fl1_fx * pa_yyy[j] * fl1_fz * pb_z[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_xz[j]);

                t_xyyy_yy[j] = fl_s_0_0 * (2.25 * pa_xy[j] * fl2_fx + 1.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyyy[j] * fl1_fx + 3.0 * pa_xyy[j] * fl1_fx * pb_y[j] + 1.5 * pa_xy[j] * fl1_fx * pb_yy[j] + pa_xyyy[j] * pb_yy[j]);

                t_xyyy_yy[j] += fl_r_0_0 * (18.0 * pa_xy[j] * fl2_fx * fl1_fz - 1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - pa_xyyy[j] * fl1_fz * fl1_fgb + 12.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_xyyy[j] * fl1_fz * fl1_fx + 30.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_yy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_40_50(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(34 * idx + 4);

            auto pa_xz = paDistances.data(34 * idx + 5);

            auto pa_yy = paDistances.data(34 * idx + 6);

            auto pa_yz = paDistances.data(34 * idx + 7);

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xyy = paDistances.data(34 * idx + 12);

            auto pa_xyz = paDistances.data(34 * idx + 13);

            auto pa_xzz = paDistances.data(34 * idx + 14);

            auto pa_yyz = paDistances.data(34 * idx + 16);

            auto pa_yzz = paDistances.data(34 * idx + 17);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xyyy = paDistances.data(34 * idx + 25);

            auto pa_xyyz = paDistances.data(34 * idx + 26);

            auto pa_xyzz = paDistances.data(34 * idx + 27);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xyyy_yz = primBuffer.data(90 * idx + 40);

            auto t_xyyy_zz = primBuffer.data(90 * idx + 41);

            auto t_xyyz_xx = primBuffer.data(90 * idx + 42);

            auto t_xyyz_xy = primBuffer.data(90 * idx + 43);

            auto t_xyyz_xz = primBuffer.data(90 * idx + 44);

            auto t_xyyz_yy = primBuffer.data(90 * idx + 45);

            auto t_xyyz_yz = primBuffer.data(90 * idx + 46);

            auto t_xyyz_zz = primBuffer.data(90 * idx + 47);

            auto t_xyzz_xx = primBuffer.data(90 * idx + 48);

            auto t_xyzz_xy = primBuffer.data(90 * idx + 49);

            // Batch of Integrals (40,50)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyy, pa_xyyz, pa_xyz, pa_xyzz, pa_xz, \
                                     pa_xzz, pa_y, pa_yy, pa_yyz, pa_yz, pa_yzz, pa_z, pa_zz, pb_x, pb_xx, pb_xy, pb_xz, pb_y, \
                                     pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_xyyy_yz, t_xyyy_zz, t_xyyz_xx, t_xyyz_xy, \
                                     t_xyyz_xz, t_xyyz_yy, t_xyyz_yz, t_xyyz_zz, t_xyzz_xx, t_xyzz_xy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xyyy_yz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_z[j] + 1.5 * pa_xyy[j] * fl1_fx * pb_z[j] + 1.5 * pa_xy[j] * fl1_fx * pb_yz[j] + pa_xyyy[j] * pb_yz[j]);

                t_xyyy_yz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 15.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_yz[j]);

                t_xyyy_zz[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 0.5 * pa_xyyy[j] * fl1_fx + 1.5 * pa_xy[j] * fl1_fx * pb_zz[j] + pa_xyyy[j] * pb_zz[j]);

                t_xyyy_zz[j] += fl_r_0_0 * (-1.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - pa_xyyy[j] * fl1_fz * fl1_fgb + 6.0 * pa_xy[j] * fl1_fz * fl2_fx + 5.0 * pa_xyyy[j] * fl1_fz * fl1_fx - 3.0 * pa_xy[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_xyyy[j] * fl1_fz * pb_zz[j]);

                t_xyyz_xx[j] = fl_s_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xyyz[j] * fl1_fx + fl1_fx * pa_yyz[j] * pb_x[j] + 0.5 * pa_xz[j] * fl1_fx * pb_xx[j] + pa_xyyz[j] * pb_xx[j]);

                t_xyyz_xx[j] += fl_r_0_0 * (-0.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_x[j] - pa_xyyz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xz[j] * fl2_fx * fl1_fz + 4.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 5.0 * pa_xyyz[j] * fl1_fz * fl1_fx + 10.0 * fl1_fx * pa_yyz[j] * fl1_fz * pb_x[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_xx[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xx[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_xx[j]);

                t_xyyz_xy[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_yz[j] + 0.25 * fl2_fx * pa_z[j] * pb_y[j] + pa_xyz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yyz[j] * pb_y[j] + 0.5 * pa_xz[j] * fl1_fx * pb_xy[j] + pa_xyyz[j] * pb_xy[j]);

                t_xyyz_xy[j] += fl_r_0_0 * (4.0 * fl2_fx * pa_yz[j] * fl1_fz - 0.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_y[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 10.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_x[j] + 5.0 * fl1_fx * pa_yyz[j] * fl1_fz * pb_y[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_xy[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xy[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_xy[j]);

                t_xyyz_xz[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * fl2_fx * pa_yy[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_xyy[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yyz[j] * pb_z[j] + 0.5 * pa_xz[j] * fl1_fx * pb_xz[j] + pa_xyyz[j] * pb_xz[j]);

                t_xyyz_xz[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fga + 0.75 * fl3_fx * fl1_fz + 2.0 * fl2_fx * pa_yy[j] * fl1_fz - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_x[j] - 0.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_z[j] + 2.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 2.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 5.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_x[j] + 5.0 * fl1_fx * pa_yyz[j] * fl1_fz * pb_z[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_xz[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_xz[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_xz[j]);

                t_xyyz_yy[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 0.5 * pa_xyyz[j] * fl1_fx + 2.0 * pa_xyz[j] * fl1_fx * pb_y[j] + 0.5 * pa_xz[j] * fl1_fx * pb_yy[j] + pa_xyyz[j] * pb_yy[j]);

                t_xyyz_yy[j] += fl_r_0_0 * (6.0 * pa_xz[j] * fl2_fx * fl1_fz - 0.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - pa_xyyz[j] * fl1_fz * fl1_fgb + 5.0 * pa_xyyz[j] * fl1_fz * fl1_fx + 20.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_y[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_yy[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_yy[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_yy[j]);

                t_xyyz_yz[j] = fl_s_0_0 * (0.5 * pa_xy[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyy[j] * fl1_fx * pb_y[j] + pa_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xz[j] * fl1_fx * pb_yz[j] + pa_xyyz[j] * pb_yz[j]);

                t_xyyz_yz[j] += fl_r_0_0 * (4.0 * pa_xy[j] * fl2_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_y[j] + 2.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_y[j] + 10.0 * pa_xyz[j] * fl1_fx * fl1_fz * pb_z[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_yz[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_yz[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_yz[j]);

                t_xyyz_zz[j] = fl_s_0_0 * (0.25 * pa_xz[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xyyz[j] * fl1_fx + pa_xyy[j] * fl1_fx * pb_z[j] + 0.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_xyyz[j] * pb_zz[j]);

                t_xyyz_zz[j] += fl_r_0_0 * (-0.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - pa_x[j] * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_xyyz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xz[j] * fl2_fx * fl1_fz + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_xyyz[j] * fl1_fz * fl1_fx + 10.0 * pa_xyy[j] * fl1_fz * fl1_fx * pb_z[j] - pa_xz[j] * fl1_fz * fl1_fga * pb_zz[j] + 5.0 * pa_xz[j] * fl1_fx * fl1_fz * pb_zz[j] + 12.0 * pa_xyyz[j] * fl1_fz * pb_zz[j]);

                t_xyzz_xx[j] = fl_s_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * fl2_fx * pa_y[j] * pb_x[j] + 0.5 * pa_xyzz[j] * fl1_fx + fl1_fx * pa_yzz[j] * pb_x[j] + 0.5 * pa_xy[j] * fl1_fx * pb_xx[j] + pa_xyzz[j] * pb_xx[j]);

                t_xyzz_xx[j] += fl_r_0_0 * (-0.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_x[j] - pa_xyzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xy[j] * fl1_fz * fl2_fx + 4.0 * fl2_fx * pa_y[j] * fl1_fz * pb_x[j] + 5.0 * pa_xyzz[j] * fl1_fz * fl1_fx + 10.0 * fl1_fx * pa_yzz[j] * fl1_fz * pb_x[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_xx[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_xx[j]);

                t_xyzz_xy[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * fl2_fx * pa_zz[j] + 0.25 * pa_x[j] * fl2_fx * pb_x[j] + 0.25 * fl2_fx * pa_y[j] * pb_y[j] + 0.5 * pa_xzz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yzz[j] * pb_y[j] + 0.5 * pa_xy[j] * fl1_fx * pb_xy[j] + pa_xyzz[j] * pb_xy[j]);

                t_xyzz_xy[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fga + 0.75 * fl3_fx * fl1_fz + 2.0 * fl2_fx * pa_zz[j] * fl1_fz - 0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - 0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_y[j] + 2.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 2.0 * fl2_fx * pa_y[j] * fl1_fz * pb_y[j] + 5.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_x[j] + 5.0 * fl1_fx * pa_yzz[j] * fl1_fz * pb_y[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_xy[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_xy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_50_60(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_x = paDistances.data(34 * idx);

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_xy = paDistances.data(34 * idx + 4);

            auto pa_xz = paDistances.data(34 * idx + 5);

            auto pa_yz = paDistances.data(34 * idx + 7);

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xyz = paDistances.data(34 * idx + 13);

            auto pa_xzz = paDistances.data(34 * idx + 14);

            auto pa_yzz = paDistances.data(34 * idx + 17);

            auto pa_zzz = paDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xyzz = paDistances.data(34 * idx + 27);

            auto pa_xzzz = paDistances.data(34 * idx + 28);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xyzz_xz = primBuffer.data(90 * idx + 50);

            auto t_xyzz_yy = primBuffer.data(90 * idx + 51);

            auto t_xyzz_yz = primBuffer.data(90 * idx + 52);

            auto t_xyzz_zz = primBuffer.data(90 * idx + 53);

            auto t_xzzz_xx = primBuffer.data(90 * idx + 54);

            auto t_xzzz_xy = primBuffer.data(90 * idx + 55);

            auto t_xzzz_xz = primBuffer.data(90 * idx + 56);

            auto t_xzzz_yy = primBuffer.data(90 * idx + 57);

            auto t_xzzz_yz = primBuffer.data(90 * idx + 58);

            auto t_xzzz_zz = primBuffer.data(90 * idx + 59);

            // Batch of Integrals (50,60)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyz, pa_xyzz, pa_xz, pa_xzz, pa_xzzz, pa_y, pa_yz, \
                                     pa_yzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, \
                                     r_0_0, s_0_0, t_xyzz_xz, t_xyzz_yy, t_xyzz_yz, t_xyzz_zz, t_xzzz_xx, t_xzzz_xy, \
                                     t_xzzz_xz, t_xzzz_yy, t_xzzz_yz, t_xzzz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_xyzz_xz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_yz[j] + 0.25 * fl2_fx * pa_y[j] * pb_z[j] + pa_xyz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_yzz[j] * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_xz[j] + pa_xyzz[j] * pb_xz[j]);

                t_xyzz_xz[j] += fl_r_0_0 * (4.0 * fl2_fx * pa_yz[j] * fl1_fz - 0.5 * fl1_fx * pa_y[j] * fl1_fz * fl1_fga * pb_z[j] + 2.0 * fl2_fx * pa_y[j] * fl1_fz * pb_z[j] + 10.0 * pa_xyz[j] * fl1_fz * fl1_fx * pb_x[j] + 5.0 * fl1_fx * pa_yzz[j] * fl1_fz * pb_z[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_xz[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_xz[j]);

                t_xyzz_yy[j] = fl_s_0_0 * (0.25 * pa_xy[j] * fl2_fx + 0.5 * pa_x[j] * fl2_fx * pb_y[j] + 0.5 * pa_xyzz[j] * fl1_fx + pa_xzz[j] * fl1_fx * pb_y[j] + 0.5 * pa_xy[j] * fl1_fx * pb_yy[j] + pa_xyzz[j] * pb_yy[j]);

                t_xyzz_yy[j] += fl_r_0_0 * (-0.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - pa_xyzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_xy[j] * fl1_fz * fl2_fx + 4.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_xyzz[j] * fl1_fz * fl1_fx + 10.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_y[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_yy[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_yy[j]);

                t_xyzz_yz[j] = fl_s_0_0 * (0.5 * pa_xz[j] * fl2_fx + 0.25 * pa_x[j] * fl2_fx * pb_z[j] + pa_xyz[j] * fl1_fx * pb_y[j] + 0.5 * pa_xzz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_yz[j] + pa_xyzz[j] * pb_yz[j]);

                t_xyzz_yz[j] += fl_r_0_0 * (4.0 * pa_xz[j] * fl2_fx * fl1_fz - 0.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 2.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 10.0 * pa_xyz[j] * fl1_fz * fl1_fx * pb_y[j] + 5.0 * pa_xzz[j] * fl1_fx * fl1_fz * pb_z[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_yz[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_yz[j]);

                t_xyzz_zz[j] = fl_s_0_0 * (0.75 * pa_xy[j] * fl2_fx + 0.5 * pa_xyzz[j] * fl1_fx + 2.0 * pa_xyz[j] * fl1_fx * pb_z[j] + 0.5 * pa_xy[j] * fl1_fx * pb_zz[j] + pa_xyzz[j] * pb_zz[j]);

                t_xyzz_zz[j] += fl_r_0_0 * (6.0 * pa_xy[j] * fl2_fx * fl1_fz - 0.5 * pa_xy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_xy[j] * fl1_fz * fl1_fga * fl1_fx - pa_xyzz[j] * fl1_fz * fl1_fgb + 5.0 * pa_xyzz[j] * fl1_fz * fl1_fx + 20.0 * pa_xyz[j] * fl1_fz * fl1_fx * pb_z[j] - pa_xy[j] * fl1_fz * fl1_fga * pb_zz[j] + 5.0 * pa_xy[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_xyzz[j] * fl1_fz * pb_zz[j]);

                t_xzzz_xx[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * pa_xzzz[j] * fl1_fx + fl1_fx * pa_zzz[j] * pb_x[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xx[j] + pa_xzzz[j] * pb_xx[j]);

                t_xzzz_xx[j] += fl_r_0_0 * (-1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_x[j] - pa_xzzz[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl1_fz * fl2_fx + 12.0 * fl2_fx * pa_z[j] * fl1_fz * pb_x[j] + 5.0 * pa_xzzz[j] * fl1_fz * fl1_fx + 10.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_x[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_xx[j]);

                t_xzzz_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * fl1_fx * pa_zzz[j] * pb_y[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xy[j] + pa_xzzz[j] * pb_xy[j]);

                t_xzzz_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_y[j] + 6.0 * fl2_fx * pa_z[j] * fl1_fz * pb_y[j] + 5.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_y[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_xy[j]);

                t_xzzz_xz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.75 * pa_x[j] * fl2_fx * pb_x[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 1.5 * pa_xzz[j] * fl1_fx * pb_x[j] + 0.5 * fl1_fx * pa_zzz[j] * pb_z[j] + 1.5 * pa_xz[j] * fl1_fx * pb_xz[j] + pa_xzzz[j] * pb_xz[j]);

                t_xzzz_xz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_zz[j] * fl1_fz - 1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] - 1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_z[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_x[j] + 6.0 * fl2_fx * pa_z[j] * fl1_fz * pb_z[j] + 15.0 * pa_xzz[j] * fl1_fz * fl1_fx * pb_x[j] + 5.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_z[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_xz[j]);

                t_xzzz_yy[j] = fl_s_0_0 * (0.75 * pa_xz[j] * fl2_fx + 0.5 * pa_xzzz[j] * fl1_fx + 1.5 * pa_xz[j] * fl1_fx * pb_yy[j] + pa_xzzz[j] * pb_yy[j]);

                t_xzzz_yy[j] += fl_r_0_0 * (-1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - pa_xzzz[j] * fl1_fz * fl1_fgb + 6.0 * pa_xz[j] * fl1_fz * fl2_fx + 5.0 * pa_xzzz[j] * fl1_fz * fl1_fx - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_yy[j]);

                t_xzzz_yz[j] = fl_s_0_0 * (0.75 * pa_x[j] * fl2_fx * pb_y[j] + 1.5 * pa_xzz[j] * fl1_fx * pb_y[j] + 1.5 * pa_xz[j] * fl1_fx * pb_yz[j] + pa_xzzz[j] * pb_yz[j]);

                t_xzzz_yz[j] += fl_r_0_0 * (-1.5 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 6.0 * pa_x[j] * fl2_fx * fl1_fz * pb_y[j] + 15.0 * pa_xzz[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_yz[j]);

                t_xzzz_zz[j] = fl_s_0_0 * (2.25 * pa_xz[j] * fl2_fx + 1.5 * pa_x[j] * fl2_fx * pb_z[j] + 0.5 * pa_xzzz[j] * fl1_fx + 3.0 * pa_xzz[j] * fl1_fx * pb_z[j] + 1.5 * pa_xz[j] * fl1_fx * pb_zz[j] + pa_xzzz[j] * pb_zz[j]);

                t_xzzz_zz[j] += fl_r_0_0 * (18.0 * pa_xz[j] * fl2_fx * fl1_fz - 1.5 * pa_xz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_xz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_x[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - pa_xzzz[j] * fl1_fz * fl1_fgb + 12.0 * pa_x[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_xzzz[j] * fl1_fz * fl1_fx + 30.0 * pa_xzz[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_xz[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_xz[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_xzzz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_60_70(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(34 * idx + 6);

            auto pa_yz = paDistances.data(34 * idx + 7);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yyy = paDistances.data(34 * idx + 15);

            auto pa_yyz = paDistances.data(34 * idx + 16);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_yyyy = paDistances.data(34 * idx + 29);

            auto pa_yyyz = paDistances.data(34 * idx + 30);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yyyy_xx = primBuffer.data(90 * idx + 60);

            auto t_yyyy_xy = primBuffer.data(90 * idx + 61);

            auto t_yyyy_xz = primBuffer.data(90 * idx + 62);

            auto t_yyyy_yy = primBuffer.data(90 * idx + 63);

            auto t_yyyy_yz = primBuffer.data(90 * idx + 64);

            auto t_yyyy_zz = primBuffer.data(90 * idx + 65);

            auto t_yyyz_xx = primBuffer.data(90 * idx + 66);

            auto t_yyyz_xy = primBuffer.data(90 * idx + 67);

            auto t_yyyz_xz = primBuffer.data(90 * idx + 68);

            auto t_yyyz_yy = primBuffer.data(90 * idx + 69);

            // Batch of Integrals (60,70)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyy, pa_yyyz, pa_yyz, pa_yz, pa_z, pb_x, \
                                     pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yyyy_xx, \
                                     t_yyyy_xy, t_yyyy_xz, t_yyyy_yy, t_yyyy_yz, t_yyyy_zz, t_yyyz_xx, t_yyyz_xy, \
                                     t_yyyz_xz, t_yyyz_yy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yyyy_xx[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_yy[j] * fl2_fx + 0.5 * pa_yyyy[j] * fl1_fx + 0.75 * fl2_fx * pb_xx[j] + 3.0 * pa_yy[j] * fl1_fx * pb_xx[j] + pa_yyyy[j] * pb_xx[j]);

                t_yyyy_xx[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_yyyy[j] * fl1_fz * fl1_fgb + 12.0 * pa_yy[j] * fl1_fz * fl2_fx + 5.0 * pa_yyyy[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_xx[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_xx[j]);

                t_yyyy_xy[j] = fl_s_0_0 * (3.0 * pa_y[j] * fl2_fx * pb_x[j] + 2.0 * pa_yyy[j] * fl1_fx * pb_x[j] + 0.75 * fl2_fx * pb_xy[j] + 3.0 * pa_yy[j] * fl1_fx * pb_xy[j] + pa_yyyy[j] * pb_xy[j]);

                t_yyyy_xy[j] += fl_r_0_0 * (-6.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 24.0 * pa_y[j] * fl2_fx * fl1_fz * pb_x[j] + 20.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_xy[j] + 6.0 * fl2_fx * fl1_fz * pb_xy[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_xy[j]);

                t_yyyy_xz[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xz[j] + 3.0 * pa_yy[j] * fl1_fx * pb_xz[j] + pa_yyyy[j] * pb_xz[j]);

                t_yyyy_xz[j] += fl_r_0_0 * (-3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_xz[j] + 6.0 * fl2_fx * fl1_fz * pb_xz[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_xz[j]);

                t_yyyy_yy[j] = fl_s_0_0 * (1.875 * fl3_fx + 4.5 * pa_yy[j] * fl2_fx + 6.0 * pa_y[j] * fl2_fx * pb_y[j] + 0.5 * pa_yyyy[j] * fl1_fx + 4.0 * pa_yyy[j] * fl1_fx * pb_y[j] + 0.75 * fl2_fx * pb_yy[j] + 3.0 * pa_yy[j] * fl1_fx * pb_yy[j] + pa_yyyy[j] * pb_yy[j]);

                t_yyyy_yy[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fga + 11.25 * fl3_fx * fl1_fz + 36.0 * pa_yy[j] * fl2_fx * fl1_fz - 0.75 * fl2_fx * fl1_fz * fl1_fgb - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx - 12.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - pa_yyyy[j] * fl1_fz * fl1_fgb + 48.0 * pa_y[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_yyyy[j] * fl1_fz * fl1_fx + 40.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_yy[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_yy[j]);

                t_yyyy_yz[j] = fl_s_0_0 * (3.0 * pa_y[j] * fl2_fx * pb_z[j] + 2.0 * pa_yyy[j] * fl1_fx * pb_z[j] + 0.75 * fl2_fx * pb_yz[j] + 3.0 * pa_yy[j] * fl1_fx * pb_yz[j] + pa_yyyy[j] * pb_yz[j]);

                t_yyyy_yz[j] += fl_r_0_0 * (-6.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] + 24.0 * pa_y[j] * fl2_fx * fl1_fz * pb_z[j] + 20.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_yz[j] + 6.0 * fl2_fx * fl1_fz * pb_yz[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_yz[j]);

                t_yyyy_zz[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_yy[j] * fl2_fx + 0.5 * pa_yyyy[j] * fl1_fx + 0.75 * fl2_fx * pb_zz[j] + 3.0 * pa_yy[j] * fl1_fx * pb_zz[j] + pa_yyyy[j] * pb_zz[j]);

                t_yyyy_zz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_yyyy[j] * fl1_fz * fl1_fgb + 12.0 * pa_yy[j] * fl1_fz * fl2_fx + 5.0 * pa_yyyy[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - 6.0 * pa_yy[j] * fl1_fz * fl1_fga * pb_zz[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] + 30.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_yyyy[j] * fl1_fz * pb_zz[j]);

                t_yyyz_xx[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 0.5 * pa_yyyz[j] * fl1_fx + 1.5 * pa_yz[j] * fl1_fx * pb_xx[j] + pa_yyyz[j] * pb_xx[j]);

                t_yyyz_xx[j] += fl_r_0_0 * (-1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - pa_yyyz[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl2_fx * fl1_fz + 5.0 * pa_yyyz[j] * fl1_fz * fl1_fx - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_xx[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_xx[j]);

                t_yyyz_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 1.5 * pa_yyz[j] * fl1_fx * pb_x[j] + 1.5 * pa_yz[j] * fl1_fx * pb_xy[j] + pa_yyyz[j] * pb_xy[j]);

                t_yyyz_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_x[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_x[j] + 15.0 * pa_yyz[j] * fl1_fx * fl1_fz * pb_x[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_xy[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_xy[j]);

                t_yyyz_xz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 0.5 * pa_yyy[j] * fl1_fx * pb_x[j] + 1.5 * pa_yz[j] * fl1_fx * pb_xz[j] + pa_yyyz[j] * pb_xz[j]);

                t_yyyz_xz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx * pb_x[j] + 6.0 * pa_y[j] * fl2_fx * fl1_fz * pb_x[j] + 5.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_xz[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_xz[j]);

                t_yyyz_yy[j] = fl_s_0_0 * (2.25 * pa_yz[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_yyyz[j] * fl1_fx + 3.0 * pa_yyz[j] * fl1_fx * pb_y[j] + 1.5 * pa_yz[j] * fl1_fx * pb_yy[j] + pa_yyyz[j] * pb_yy[j]);

                t_yyyz_yy[j] += fl_r_0_0 * (18.0 * pa_yz[j] * fl2_fx * fl1_fz - 1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_y[j] - pa_yyyz[j] * fl1_fz * fl1_fgb + 12.0 * fl2_fx * fl1_fz * pa_z[j] * pb_y[j] + 5.0 * pa_yyyz[j] * fl1_fz * fl1_fx + 30.0 * pa_yyz[j] * fl1_fx * fl1_fz * pb_y[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_yy[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_yy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_70_80(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yy = paDistances.data(34 * idx + 6);

            auto pa_yz = paDistances.data(34 * idx + 7);

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yyy = paDistances.data(34 * idx + 15);

            auto pa_yyz = paDistances.data(34 * idx + 16);

            auto pa_yzz = paDistances.data(34 * idx + 17);

            auto pa_zzz = paDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_yyyz = paDistances.data(34 * idx + 30);

            auto pa_yyzz = paDistances.data(34 * idx + 31);

            auto pa_yzzz = paDistances.data(34 * idx + 32);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yyyz_yz = primBuffer.data(90 * idx + 70);

            auto t_yyyz_zz = primBuffer.data(90 * idx + 71);

            auto t_yyzz_xx = primBuffer.data(90 * idx + 72);

            auto t_yyzz_xy = primBuffer.data(90 * idx + 73);

            auto t_yyzz_xz = primBuffer.data(90 * idx + 74);

            auto t_yyzz_yy = primBuffer.data(90 * idx + 75);

            auto t_yyzz_yz = primBuffer.data(90 * idx + 76);

            auto t_yyzz_zz = primBuffer.data(90 * idx + 77);

            auto t_yzzz_xx = primBuffer.data(90 * idx + 78);

            auto t_yzzz_xy = primBuffer.data(90 * idx + 79);

            // Batch of Integrals (70,80)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyz, pa_yyz, pa_yyzz, pa_yz, pa_yzz, \
                                     pa_yzzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, \
                                     r_0_0, s_0_0, t_yyyz_yz, t_yyyz_zz, t_yyzz_xx, t_yyzz_xy, t_yyzz_xz, t_yyzz_yy, \
                                     t_yyzz_yz, t_yyzz_zz, t_yzzz_xx, t_yzzz_xy: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yyyz_yz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_yyy[j] * fl1_fx * pb_y[j] + 1.5 * pa_yyz[j] * fl1_fx * pb_z[j] + 1.5 * pa_yz[j] * fl1_fx * pb_yz[j] + pa_yyyz[j] * pb_yz[j]);

                t_yyyz_yz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_yy[j] * fl2_fx * fl1_fz - 1.5 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx * pb_y[j] - 1.5 * fl1_fx * fl1_fz * fl1_fga * pa_z[j] * pb_z[j] + 6.0 * pa_y[j] * fl2_fx * fl1_fz * pb_y[j] + 6.0 * fl2_fx * fl1_fz * pa_z[j] * pb_z[j] + 5.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_y[j] + 15.0 * pa_yyz[j] * fl1_fx * fl1_fz * pb_z[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_yz[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_yz[j]);

                t_yyyz_zz[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 1.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yyyz[j] * fl1_fx + pa_yyy[j] * fl1_fx * pb_z[j] + 1.5 * pa_yz[j] * fl1_fx * pb_zz[j] + pa_yyyz[j] * pb_zz[j]);

                t_yyyz_zz[j] += fl_r_0_0 * (-1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_y[j] * fl1_fz * fl1_fga * fl1_fx * pb_z[j] - pa_yyyz[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl2_fx * fl1_fz + 12.0 * pa_y[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_yyyz[j] * fl1_fz * fl1_fx + 10.0 * pa_yyy[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_yz[j] * fl1_fx * fl1_fz * pb_zz[j] + 12.0 * pa_yyyz[j] * fl1_fz * pb_zz[j]);

                t_yyzz_xx[j] = fl_s_0_0 * (0.125 * fl3_fx + 0.25 * pa_yy[j] * fl2_fx + 0.25 * fl2_fx * pa_zz[j] + 0.5 * pa_yyzz[j] * fl1_fx + 0.25 * fl2_fx * pb_xx[j] + 0.5 * pa_yy[j] * fl1_fx * pb_xx[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xx[j] + pa_yyzz[j] * pb_xx[j]);

                t_yyzz_xx[j] += fl_r_0_0 * (-0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * fl2_fx * fl1_fz * fl1_fga - 0.5 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb + 0.75 * fl3_fx * fl1_fz - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - pa_yyzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_yy[j] * fl1_fz * fl2_fx + 2.0 * fl2_fx * pa_zz[j] * fl1_fz + 5.0 * pa_yyzz[j] * fl1_fz * fl1_fx - fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_xx[j] + 2.0 * fl2_fx * fl1_fz * pb_xx[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xx[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xx[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xx[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_xx[j]);

                t_yyzz_xy[j] = fl_s_0_0 * (0.5 * pa_y[j] * fl2_fx * pb_x[j] + pa_yzz[j] * fl1_fx * pb_x[j] + 0.25 * fl2_fx * pb_xy[j] + 0.5 * pa_yy[j] * fl1_fx * pb_xy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xy[j] + pa_yyzz[j] * pb_xy[j]);

                t_yyzz_xy[j] += fl_r_0_0 * (-pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 4.0 * pa_y[j] * fl2_fx * fl1_fz * pb_x[j] + 10.0 * pa_yzz[j] * fl1_fx * fl1_fz * pb_x[j] - fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_xy[j] + 2.0 * fl2_fx * fl1_fz * pb_xy[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xy[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xy[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xy[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_xy[j]);

                t_yyzz_xz[j] = fl_s_0_0 * (0.5 * fl2_fx * pa_z[j] * pb_x[j] + pa_yyz[j] * fl1_fx * pb_x[j] + 0.25 * fl2_fx * pb_xz[j] + 0.5 * pa_yy[j] * fl1_fx * pb_xz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_xz[j] + pa_yyzz[j] * pb_xz[j]);

                t_yyzz_xz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_x[j] + 4.0 * fl2_fx * pa_z[j] * fl1_fz * pb_x[j] + 10.0 * pa_yyz[j] * fl1_fz * fl1_fx * pb_x[j] - fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_xz[j] + 2.0 * fl2_fx * fl1_fz * pb_xz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_xz[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_xz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_xz[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_xz[j]);

                t_yyzz_yy[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.25 * pa_yy[j] * fl2_fx + pa_y[j] * fl2_fx * pb_y[j] + 0.5 * pa_yyzz[j] * fl1_fx + 2.0 * pa_yzz[j] * fl1_fx * pb_y[j] + 0.25 * fl2_fx * pb_yy[j] + 0.5 * pa_yy[j] * fl1_fx * pb_yy[j] + 0.5 * fl1_fx * pa_zz[j] * pb_yy[j] + pa_yyzz[j] * pb_yy[j]);

                t_yyzz_yy[j] += fl_r_0_0 * (-fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_zz[j] * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx - 2.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - pa_yyzz[j] * fl1_fz * fl1_fgb + 2.0 * pa_yy[j] * fl1_fz * fl2_fx + 8.0 * pa_y[j] * fl2_fx * fl1_fz * pb_y[j] + 5.0 * pa_yyzz[j] * fl1_fz * fl1_fx + 20.0 * pa_yzz[j] * fl1_fx * fl1_fz * pb_y[j] - fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_yy[j] + 2.0 * fl2_fx * fl1_fz * pb_yy[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_yy[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yy[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_yy[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_yy[j]);

                t_yyzz_yz[j] = fl_s_0_0 * (pa_yz[j] * fl2_fx + 0.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * fl2_fx * pa_z[j] * pb_y[j] + pa_yyz[j] * fl1_fx * pb_y[j] + pa_yzz[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_yz[j] + 0.5 * pa_yy[j] * fl1_fx * pb_yz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_yz[j] + pa_yyzz[j] * pb_yz[j]);

                t_yyzz_yz[j] += fl_r_0_0 * (8.0 * pa_yz[j] * fl2_fx * fl1_fz - pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_y[j] + 4.0 * pa_y[j] * fl2_fx * fl1_fz * pb_z[j] + 4.0 * fl2_fx * pa_z[j] * fl1_fz * pb_y[j] + 10.0 * pa_yyz[j] * fl1_fz * fl1_fx * pb_y[j] + 10.0 * pa_yzz[j] * fl1_fx * fl1_fz * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_yz[j] + 2.0 * fl2_fx * fl1_fz * pb_yz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_yz[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_yz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_yz[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_yz[j]);

                t_yyzz_zz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * pa_yy[j] * fl2_fx + 0.25 * fl2_fx * pa_zz[j] + fl2_fx * pa_z[j] * pb_z[j] + 0.5 * pa_yyzz[j] * fl1_fx + 2.0 * pa_yyz[j] * fl1_fx * pb_z[j] + 0.25 * fl2_fx * pb_zz[j] + 0.5 * pa_yy[j] * fl1_fx * pb_zz[j] + 0.5 * fl1_fx * pa_zz[j] * pb_zz[j] + pa_yyzz[j] * pb_zz[j]);

                t_yyzz_zz[j] += fl_r_0_0 * (-fl1_fz * fl1_fga * fl2_fx + 2.25 * fl3_fx * fl1_fz + 6.0 * pa_yy[j] * fl2_fx * fl1_fz - 0.25 * fl2_fx * fl1_fz * fl1_fgb - 0.5 * pa_yy[j] * fl1_fx * fl1_fz * fl1_fgb - 0.5 * pa_yy[j] * fl1_fz * fl1_fga * fl1_fx - 0.5 * fl1_fx * pa_zz[j] * fl1_fz * fl1_fgb - 0.5 * fl1_fz * fl1_fga * pa_zz[j] * fl1_fx - 2.0 * fl1_fz * fl1_fga * pa_z[j] * fl1_fx * pb_z[j] - pa_yyzz[j] * fl1_fz * fl1_fgb + 2.0 * fl2_fx * pa_zz[j] * fl1_fz + 8.0 * fl2_fx * pa_z[j] * fl1_fz * pb_z[j] + 5.0 * pa_yyzz[j] * fl1_fz * fl1_fx + 20.0 * pa_yyz[j] * fl1_fz * fl1_fx * pb_z[j] - fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - pa_yy[j] * fl1_fz * fl1_fga * pb_zz[j] + 2.0 * fl2_fx * fl1_fz * pb_zz[j] - fl1_fz * fl1_fga * pa_zz[j] * pb_zz[j] + 5.0 * pa_yy[j] * fl1_fz * fl1_fx * pb_zz[j] + 5.0 * fl1_fx * pa_zz[j] * fl1_fz * pb_zz[j] + 12.0 * pa_yyzz[j] * fl1_fz * pb_zz[j]);

                t_yzzz_xx[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 0.5 * pa_yzzz[j] * fl1_fx + 1.5 * pa_yz[j] * fl1_fx * pb_xx[j] + pa_yzzz[j] * pb_xx[j]);

                t_yzzz_xx[j] += fl_r_0_0 * (-1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - pa_yzzz[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl1_fz * fl2_fx + 5.0 * pa_yzzz[j] * fl1_fz * fl1_fx - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xx[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_xx[j]);

                t_yzzz_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pa_z[j] * pb_x[j] + 0.5 * fl1_fx * pa_zzz[j] * pb_x[j] + 1.5 * pa_yz[j] * fl1_fx * pb_xy[j] + pa_yzzz[j] * pb_xy[j]);

                t_yzzz_xy[j] += fl_r_0_0 * (-1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_x[j] + 6.0 * fl2_fx * pa_z[j] * fl1_fz * pb_x[j] + 5.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_x[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xy[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_xy[j]);
            }

            idx++;
        }
    }

    void
    compKineticEnergyForGD_80_90(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
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

            auto fx = osFactors.data(4 * idx);

            auto fz = osFactors.data(4 * idx + 1);

            auto fga = osFactors.data(4 * idx + 2);

            auto fgb = osFactors.data(4 * idx + 3);

            // set up pointers to 1-th order tensor of distance R(PA)

            auto pa_y = paDistances.data(34 * idx + 1);

            auto pa_z = paDistances.data(34 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PA)

            auto pa_yz = paDistances.data(34 * idx + 7);

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_yzz = paDistances.data(34 * idx + 17);

            auto pa_zzz = paDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_yzzz = paDistances.data(34 * idx + 32);

            auto pa_zzzz = paDistances.data(34 * idx + 33);

            // set up pointers to 1-th order tensor of distance R(PB)

            auto pb_x = pbDistances.data(9 * idx);

            auto pb_y = pbDistances.data(9 * idx + 1);

            auto pb_z = pbDistances.data(9 * idx + 2);

            // set up pointers to 2-th order tensor of distance R(PB)

            auto pb_xx = pbDistances.data(9 * idx + 3);

            auto pb_xy = pbDistances.data(9 * idx + 4);

            auto pb_xz = pbDistances.data(9 * idx + 5);

            auto pb_yy = pbDistances.data(9 * idx + 6);

            auto pb_yz = pbDistances.data(9 * idx + 7);

            auto pb_zz = pbDistances.data(9 * idx + 8);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_yzzz_xz = primBuffer.data(90 * idx + 80);

            auto t_yzzz_yy = primBuffer.data(90 * idx + 81);

            auto t_yzzz_yz = primBuffer.data(90 * idx + 82);

            auto t_yzzz_zz = primBuffer.data(90 * idx + 83);

            auto t_zzzz_xx = primBuffer.data(90 * idx + 84);

            auto t_zzzz_xy = primBuffer.data(90 * idx + 85);

            auto t_zzzz_xz = primBuffer.data(90 * idx + 86);

            auto t_zzzz_yy = primBuffer.data(90 * idx + 87);

            auto t_zzzz_yz = primBuffer.data(90 * idx + 88);

            auto t_zzzz_zz = primBuffer.data(90 * idx + 89);

            // Batch of Integrals (80,90)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_yzz, pa_yzzz, pa_z, pa_zz, pa_zzz, pa_zzzz, pb_x, \
                                     pb_xx, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, pb_z, pb_zz, r_0_0, s_0_0, t_yzzz_xz, \
                                     t_yzzz_yy, t_yzzz_yz, t_yzzz_zz, t_zzzz_xx, t_zzzz_xy, t_zzzz_xz, t_zzzz_yy, \
                                     t_zzzz_yz, t_zzzz_zz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                double fl_r_0_0 = r_0_0[j];

                double fl_s_0_0 = s_0_0[j];

                double fl1_fga = fga[j];

                double fl1_fgb = fgb[j];

                double fl1_fx = fx[j];

                double fl1_fz = fz[j];

                double fl2_fx = fx[j] * fx[j];

                double fl3_fx = fx[j] * fx[j] * fx[j];

                t_yzzz_xz[j] = fl_s_0_0 * (0.75 * pa_y[j] * fl2_fx * pb_x[j] + 1.5 * pa_yzz[j] * fl1_fx * pb_x[j] + 1.5 * pa_yz[j] * fl1_fx * pb_xz[j] + pa_yzzz[j] * pb_xz[j]);

                t_yzzz_xz[j] += fl_r_0_0 * (-1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 6.0 * pa_y[j] * fl2_fx * fl1_fz * pb_x[j] + 15.0 * pa_yzz[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_xz[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_xz[j]);

                t_yzzz_yy[j] = fl_s_0_0 * (0.75 * pa_yz[j] * fl2_fx + 1.5 * fl2_fx * pa_z[j] * pb_y[j] + 0.5 * pa_yzzz[j] * fl1_fx + fl1_fx * pa_zzz[j] * pb_y[j] + 1.5 * pa_yz[j] * fl1_fx * pb_yy[j] + pa_yzzz[j] * pb_yy[j]);

                t_yzzz_yy[j] += fl_r_0_0 * (-1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_y[j] - pa_yzzz[j] * fl1_fz * fl1_fgb + 6.0 * pa_yz[j] * fl1_fz * fl2_fx + 12.0 * fl2_fx * pa_z[j] * fl1_fz * pb_y[j] + 5.0 * pa_yzzz[j] * fl1_fz * fl1_fx + 10.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_y[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_yy[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_yy[j]);

                t_yzzz_yz[j] = fl_s_0_0 * (0.375 * fl3_fx + 0.75 * fl2_fx * pa_zz[j] + 0.75 * pa_y[j] * fl2_fx * pb_y[j] + 0.75 * fl2_fx * pa_z[j] * pb_z[j] + 1.5 * pa_yzz[j] * fl1_fx * pb_y[j] + 0.5 * fl1_fx * pa_zzz[j] * pb_z[j] + 1.5 * pa_yz[j] * fl1_fx * pb_yz[j] + pa_yzzz[j] * pb_yz[j]);

                t_yzzz_yz[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fga + 2.25 * fl3_fx * fl1_fz + 6.0 * fl2_fx * pa_zz[j] * fl1_fz - 1.5 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] - 1.5 * fl1_fx * pa_z[j] * fl1_fz * fl1_fga * pb_z[j] + 6.0 * pa_y[j] * fl2_fx * fl1_fz * pb_y[j] + 6.0 * fl2_fx * pa_z[j] * fl1_fz * pb_z[j] + 15.0 * pa_yzz[j] * fl1_fz * fl1_fx * pb_y[j] + 5.0 * fl1_fx * pa_zzz[j] * fl1_fz * pb_z[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_yz[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_yz[j]);

                t_yzzz_zz[j] = fl_s_0_0 * (2.25 * pa_yz[j] * fl2_fx + 1.5 * pa_y[j] * fl2_fx * pb_z[j] + 0.5 * pa_yzzz[j] * fl1_fx + 3.0 * pa_yzz[j] * fl1_fx * pb_z[j] + 1.5 * pa_yz[j] * fl1_fx * pb_zz[j] + pa_yzzz[j] * pb_zz[j]);

                t_yzzz_zz[j] += fl_r_0_0 * (18.0 * pa_yz[j] * fl2_fx * fl1_fz - 1.5 * pa_yz[j] * fl1_fx * fl1_fz * fl1_fgb - 1.5 * pa_yz[j] * fl1_fz * fl1_fga * fl1_fx - 3.0 * pa_y[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - pa_yzzz[j] * fl1_fz * fl1_fgb + 12.0 * pa_y[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_yzzz[j] * fl1_fz * fl1_fx + 30.0 * pa_yzz[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * pa_yz[j] * fl1_fz * fl1_fga * pb_zz[j] + 15.0 * pa_yz[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_yzzz[j] * fl1_fz * pb_zz[j]);

                t_zzzz_xx[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_zz[j] * fl2_fx + 0.5 * pa_zzzz[j] * fl1_fx + 0.75 * fl2_fx * pb_xx[j] + 3.0 * pa_zz[j] * fl1_fx * pb_xx[j] + pa_zzzz[j] * pb_xx[j]);

                t_zzzz_xx[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_zz[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_zzzz[j] * fl1_fz * fl1_fgb + 12.0 * pa_zz[j] * fl1_fz * fl2_fx + 5.0 * pa_zzzz[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xx[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_xx[j] + 6.0 * fl2_fx * fl1_fz * pb_xx[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_xx[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_xx[j]);

                t_zzzz_xy[j] = fl_s_0_0 * (0.75 * fl2_fx * pb_xy[j] + 3.0 * pa_zz[j] * fl1_fx * pb_xy[j] + pa_zzzz[j] * pb_xy[j]);

                t_zzzz_xy[j] += fl_r_0_0 * (-3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xy[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_xy[j] + 6.0 * fl2_fx * fl1_fz * pb_xy[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_xy[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_xy[j]);

                t_zzzz_xz[j] = fl_s_0_0 * (3.0 * pa_z[j] * fl2_fx * pb_x[j] + 2.0 * pa_zzz[j] * fl1_fx * pb_x[j] + 0.75 * fl2_fx * pb_xz[j] + 3.0 * pa_zz[j] * fl1_fx * pb_xz[j] + pa_zzzz[j] * pb_xz[j]);

                t_zzzz_xz[j] += fl_r_0_0 * (-6.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fga * pb_x[j] + 24.0 * pa_z[j] * fl2_fx * fl1_fz * pb_x[j] + 20.0 * pa_zzz[j] * fl1_fz * fl1_fx * pb_x[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_xz[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_xz[j] + 6.0 * fl2_fx * fl1_fz * pb_xz[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_xz[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_xz[j]);

                t_zzzz_yy[j] = fl_s_0_0 * (0.375 * fl3_fx + 1.5 * pa_zz[j] * fl2_fx + 0.5 * pa_zzzz[j] * fl1_fx + 0.75 * fl2_fx * pb_yy[j] + 3.0 * pa_zz[j] * fl1_fx * pb_yy[j] + pa_zzzz[j] * pb_yy[j]);

                t_zzzz_yy[j] += fl_r_0_0 * (-0.75 * fl2_fx * fl1_fz * fl1_fgb - 1.5 * fl2_fx * fl1_fz * fl1_fga - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_zz[j] * fl1_fz * fl1_fga * fl1_fx + 2.25 * fl3_fx * fl1_fz - pa_zzzz[j] * fl1_fz * fl1_fgb + 12.0 * pa_zz[j] * fl1_fz * fl2_fx + 5.0 * pa_zzzz[j] * fl1_fz * fl1_fx - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yy[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_yy[j] + 6.0 * fl2_fx * fl1_fz * pb_yy[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_yy[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_yy[j]);

                t_zzzz_yz[j] = fl_s_0_0 * (3.0 * pa_z[j] * fl2_fx * pb_y[j] + 2.0 * pa_zzz[j] * fl1_fx * pb_y[j] + 0.75 * fl2_fx * pb_yz[j] + 3.0 * pa_zz[j] * fl1_fx * pb_yz[j] + pa_zzzz[j] * pb_yz[j]);

                t_zzzz_yz[j] += fl_r_0_0 * (-6.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fga * pb_y[j] + 24.0 * pa_z[j] * fl2_fx * fl1_fz * pb_y[j] + 20.0 * pa_zzz[j] * fl1_fz * fl1_fx * pb_y[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_yz[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_yz[j] + 6.0 * fl2_fx * fl1_fz * pb_yz[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_yz[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_yz[j]);

                t_zzzz_zz[j] = fl_s_0_0 * (1.875 * fl3_fx + 4.5 * pa_zz[j] * fl2_fx + 6.0 * pa_z[j] * fl2_fx * pb_z[j] + 0.5 * pa_zzzz[j] * fl1_fx + 4.0 * pa_zzz[j] * fl1_fx * pb_z[j] + 0.75 * fl2_fx * pb_zz[j] + 3.0 * pa_zz[j] * fl1_fx * pb_zz[j] + pa_zzzz[j] * pb_zz[j]);

                t_zzzz_zz[j] += fl_r_0_0 * (-4.5 * fl2_fx * fl1_fz * fl1_fga + 11.25 * fl3_fx * fl1_fz + 36.0 * pa_zz[j] * fl2_fx * fl1_fz - 0.75 * fl2_fx * fl1_fz * fl1_fgb - 3.0 * pa_zz[j] * fl1_fx * fl1_fz * fl1_fgb - 3.0 * pa_zz[j] * fl1_fz * fl1_fga * fl1_fx - 12.0 * pa_z[j] * fl1_fx * fl1_fz * fl1_fga * pb_z[j] - pa_zzzz[j] * fl1_fz * fl1_fgb + 48.0 * pa_z[j] * fl2_fx * fl1_fz * pb_z[j] + 5.0 * pa_zzzz[j] * fl1_fz * fl1_fx + 40.0 * pa_zzz[j] * fl1_fz * fl1_fx * pb_z[j] - 3.0 * fl1_fx * fl1_fz * fl1_fga * pb_zz[j] - 6.0 * pa_zz[j] * fl1_fz * fl1_fga * pb_zz[j] + 6.0 * fl2_fx * fl1_fz * pb_zz[j] + 30.0 * pa_zz[j] * fl1_fz * fl1_fx * pb_zz[j] + 12.0 * pa_zzzz[j] * fl1_fz * pb_zz[j]);
            }

            idx++;
        }
    }


} // kinrecfunc namespace

