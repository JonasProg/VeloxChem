//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "KineticEnergyRecFuncForGG.hpp"

namespace kinrecfunc { // kinrecfunc namespace

    void
    compKineticEnergyForGG(      CMemBlock2D<double>& primBuffer,
                           const CMemBlock2D<double>& auxBuffer,
                           const CMemBlock2D<double>& osFactors,
                           const CMemBlock2D<double>& paDistances,
                           const CMemBlock2D<double>& pbDistances,
                           const CGtoBlock&           braGtoBlock,
                           const CGtoBlock&           ketGtoBlock,
                           const int32_t              iContrGto)
    {
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

            auto pa_zz = paDistances.data(34 * idx + 8);

            // set up pointers to 3-th order tensor of distance R(PA)

            auto pa_xxx = paDistances.data(34 * idx + 9);

            auto pa_xxy = paDistances.data(34 * idx + 10);

            auto pa_xxz = paDistances.data(34 * idx + 11);

            auto pa_xyy = paDistances.data(34 * idx + 12);

            auto pa_xyz = paDistances.data(34 * idx + 13);

            auto pa_xzz = paDistances.data(34 * idx + 14);

            auto pa_yyy = paDistances.data(34 * idx + 15);

            auto pa_yyz = paDistances.data(34 * idx + 16);

            auto pa_yzz = paDistances.data(34 * idx + 17);

            auto pa_zzz = paDistances.data(34 * idx + 18);

            // set up pointers to 4-th order tensor of distance R(PA)

            auto pa_xxxx = paDistances.data(34 * idx + 19);

            auto pa_xxxy = paDistances.data(34 * idx + 20);

            auto pa_xxxz = paDistances.data(34 * idx + 21);

            auto pa_xxyy = paDistances.data(34 * idx + 22);

            auto pa_xxyz = paDistances.data(34 * idx + 23);

            auto pa_xxzz = paDistances.data(34 * idx + 24);

            auto pa_xyyy = paDistances.data(34 * idx + 25);

            auto pa_xyyz = paDistances.data(34 * idx + 26);

            auto pa_xyzz = paDistances.data(34 * idx + 27);

            auto pa_xzzz = paDistances.data(34 * idx + 28);

            auto pa_yyyy = paDistances.data(34 * idx + 29);

            auto pa_yyyz = paDistances.data(34 * idx + 30);

            auto pa_yyzz = paDistances.data(34 * idx + 31);

            auto pa_yzzz = paDistances.data(34 * idx + 32);

            auto pa_zzzz = paDistances.data(34 * idx + 33);

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

            auto pb_yyyy = pbDistances.data(34 * idx + 29);

            auto pb_yyyz = pbDistances.data(34 * idx + 30);

            auto pb_yyzz = pbDistances.data(34 * idx + 31);

            auto pb_yzzz = pbDistances.data(34 * idx + 32);

            auto pb_zzzz = pbDistances.data(34 * idx + 33);

            // set up pointers to auxilary integrals

            auto s_0_0 = auxBuffer.data(2 * idx);

            auto r_0_0 = auxBuffer.data(2 * idx + 1);

            // set up pointers to integrals

            auto t_xxxx_xxxx = primBuffer.data(225 * idx);

            auto t_xxxx_xxxy = primBuffer.data(225 * idx + 1);

            auto t_xxxx_xxxz = primBuffer.data(225 * idx + 2);

            auto t_xxxx_xxyy = primBuffer.data(225 * idx + 3);

            auto t_xxxx_xxyz = primBuffer.data(225 * idx + 4);

            auto t_xxxx_xxzz = primBuffer.data(225 * idx + 5);

            auto t_xxxx_xyyy = primBuffer.data(225 * idx + 6);

            auto t_xxxx_xyyz = primBuffer.data(225 * idx + 7);

            auto t_xxxx_xyzz = primBuffer.data(225 * idx + 8);

            auto t_xxxx_xzzz = primBuffer.data(225 * idx + 9);

            auto t_xxxx_yyyy = primBuffer.data(225 * idx + 10);

            auto t_xxxx_yyyz = primBuffer.data(225 * idx + 11);

            auto t_xxxx_yyzz = primBuffer.data(225 * idx + 12);

            auto t_xxxx_yzzz = primBuffer.data(225 * idx + 13);

            auto t_xxxx_zzzz = primBuffer.data(225 * idx + 14);

            auto t_xxxy_xxxx = primBuffer.data(225 * idx + 15);

            auto t_xxxy_xxxy = primBuffer.data(225 * idx + 16);

            auto t_xxxy_xxxz = primBuffer.data(225 * idx + 17);

            auto t_xxxy_xxyy = primBuffer.data(225 * idx + 18);

            auto t_xxxy_xxyz = primBuffer.data(225 * idx + 19);

            auto t_xxxy_xxzz = primBuffer.data(225 * idx + 20);

            auto t_xxxy_xyyy = primBuffer.data(225 * idx + 21);

            auto t_xxxy_xyyz = primBuffer.data(225 * idx + 22);

            auto t_xxxy_xyzz = primBuffer.data(225 * idx + 23);

            auto t_xxxy_xzzz = primBuffer.data(225 * idx + 24);

            auto t_xxxy_yyyy = primBuffer.data(225 * idx + 25);

            auto t_xxxy_yyyz = primBuffer.data(225 * idx + 26);

            auto t_xxxy_yyzz = primBuffer.data(225 * idx + 27);

            auto t_xxxy_yzzz = primBuffer.data(225 * idx + 28);

            auto t_xxxy_zzzz = primBuffer.data(225 * idx + 29);

            auto t_xxxz_xxxx = primBuffer.data(225 * idx + 30);

            auto t_xxxz_xxxy = primBuffer.data(225 * idx + 31);

            auto t_xxxz_xxxz = primBuffer.data(225 * idx + 32);

            auto t_xxxz_xxyy = primBuffer.data(225 * idx + 33);

            auto t_xxxz_xxyz = primBuffer.data(225 * idx + 34);

            auto t_xxxz_xxzz = primBuffer.data(225 * idx + 35);

            auto t_xxxz_xyyy = primBuffer.data(225 * idx + 36);

            auto t_xxxz_xyyz = primBuffer.data(225 * idx + 37);

            auto t_xxxz_xyzz = primBuffer.data(225 * idx + 38);

            auto t_xxxz_xzzz = primBuffer.data(225 * idx + 39);

            auto t_xxxz_yyyy = primBuffer.data(225 * idx + 40);

            auto t_xxxz_yyyz = primBuffer.data(225 * idx + 41);

            auto t_xxxz_yyzz = primBuffer.data(225 * idx + 42);

            auto t_xxxz_yzzz = primBuffer.data(225 * idx + 43);

            auto t_xxxz_zzzz = primBuffer.data(225 * idx + 44);

            auto t_xxyy_xxxx = primBuffer.data(225 * idx + 45);

            auto t_xxyy_xxxy = primBuffer.data(225 * idx + 46);

            auto t_xxyy_xxxz = primBuffer.data(225 * idx + 47);

            auto t_xxyy_xxyy = primBuffer.data(225 * idx + 48);

            auto t_xxyy_xxyz = primBuffer.data(225 * idx + 49);

            auto t_xxyy_xxzz = primBuffer.data(225 * idx + 50);

            auto t_xxyy_xyyy = primBuffer.data(225 * idx + 51);

            auto t_xxyy_xyyz = primBuffer.data(225 * idx + 52);

            auto t_xxyy_xyzz = primBuffer.data(225 * idx + 53);

            auto t_xxyy_xzzz = primBuffer.data(225 * idx + 54);

            auto t_xxyy_yyyy = primBuffer.data(225 * idx + 55);

            auto t_xxyy_yyyz = primBuffer.data(225 * idx + 56);

            auto t_xxyy_yyzz = primBuffer.data(225 * idx + 57);

            auto t_xxyy_yzzz = primBuffer.data(225 * idx + 58);

            auto t_xxyy_zzzz = primBuffer.data(225 * idx + 59);

            auto t_xxyz_xxxx = primBuffer.data(225 * idx + 60);

            auto t_xxyz_xxxy = primBuffer.data(225 * idx + 61);

            auto t_xxyz_xxxz = primBuffer.data(225 * idx + 62);

            auto t_xxyz_xxyy = primBuffer.data(225 * idx + 63);

            auto t_xxyz_xxyz = primBuffer.data(225 * idx + 64);

            auto t_xxyz_xxzz = primBuffer.data(225 * idx + 65);

            auto t_xxyz_xyyy = primBuffer.data(225 * idx + 66);

            auto t_xxyz_xyyz = primBuffer.data(225 * idx + 67);

            auto t_xxyz_xyzz = primBuffer.data(225 * idx + 68);

            auto t_xxyz_xzzz = primBuffer.data(225 * idx + 69);

            auto t_xxyz_yyyy = primBuffer.data(225 * idx + 70);

            auto t_xxyz_yyyz = primBuffer.data(225 * idx + 71);

            auto t_xxyz_yyzz = primBuffer.data(225 * idx + 72);

            auto t_xxyz_yzzz = primBuffer.data(225 * idx + 73);

            auto t_xxyz_zzzz = primBuffer.data(225 * idx + 74);

            auto t_xxzz_xxxx = primBuffer.data(225 * idx + 75);

            auto t_xxzz_xxxy = primBuffer.data(225 * idx + 76);

            auto t_xxzz_xxxz = primBuffer.data(225 * idx + 77);

            auto t_xxzz_xxyy = primBuffer.data(225 * idx + 78);

            auto t_xxzz_xxyz = primBuffer.data(225 * idx + 79);

            auto t_xxzz_xxzz = primBuffer.data(225 * idx + 80);

            auto t_xxzz_xyyy = primBuffer.data(225 * idx + 81);

            auto t_xxzz_xyyz = primBuffer.data(225 * idx + 82);

            auto t_xxzz_xyzz = primBuffer.data(225 * idx + 83);

            auto t_xxzz_xzzz = primBuffer.data(225 * idx + 84);

            auto t_xxzz_yyyy = primBuffer.data(225 * idx + 85);

            auto t_xxzz_yyyz = primBuffer.data(225 * idx + 86);

            auto t_xxzz_yyzz = primBuffer.data(225 * idx + 87);

            auto t_xxzz_yzzz = primBuffer.data(225 * idx + 88);

            auto t_xxzz_zzzz = primBuffer.data(225 * idx + 89);

            auto t_xyyy_xxxx = primBuffer.data(225 * idx + 90);

            auto t_xyyy_xxxy = primBuffer.data(225 * idx + 91);

            auto t_xyyy_xxxz = primBuffer.data(225 * idx + 92);

            auto t_xyyy_xxyy = primBuffer.data(225 * idx + 93);

            auto t_xyyy_xxyz = primBuffer.data(225 * idx + 94);

            auto t_xyyy_xxzz = primBuffer.data(225 * idx + 95);

            auto t_xyyy_xyyy = primBuffer.data(225 * idx + 96);

            auto t_xyyy_xyyz = primBuffer.data(225 * idx + 97);

            auto t_xyyy_xyzz = primBuffer.data(225 * idx + 98);

            auto t_xyyy_xzzz = primBuffer.data(225 * idx + 99);

            auto t_xyyy_yyyy = primBuffer.data(225 * idx + 100);

            auto t_xyyy_yyyz = primBuffer.data(225 * idx + 101);

            auto t_xyyy_yyzz = primBuffer.data(225 * idx + 102);

            auto t_xyyy_yzzz = primBuffer.data(225 * idx + 103);

            auto t_xyyy_zzzz = primBuffer.data(225 * idx + 104);

            auto t_xyyz_xxxx = primBuffer.data(225 * idx + 105);

            auto t_xyyz_xxxy = primBuffer.data(225 * idx + 106);

            auto t_xyyz_xxxz = primBuffer.data(225 * idx + 107);

            auto t_xyyz_xxyy = primBuffer.data(225 * idx + 108);

            auto t_xyyz_xxyz = primBuffer.data(225 * idx + 109);

            auto t_xyyz_xxzz = primBuffer.data(225 * idx + 110);

            auto t_xyyz_xyyy = primBuffer.data(225 * idx + 111);

            auto t_xyyz_xyyz = primBuffer.data(225 * idx + 112);

            auto t_xyyz_xyzz = primBuffer.data(225 * idx + 113);

            auto t_xyyz_xzzz = primBuffer.data(225 * idx + 114);

            auto t_xyyz_yyyy = primBuffer.data(225 * idx + 115);

            auto t_xyyz_yyyz = primBuffer.data(225 * idx + 116);

            auto t_xyyz_yyzz = primBuffer.data(225 * idx + 117);

            auto t_xyyz_yzzz = primBuffer.data(225 * idx + 118);

            auto t_xyyz_zzzz = primBuffer.data(225 * idx + 119);

            auto t_xyzz_xxxx = primBuffer.data(225 * idx + 120);

            auto t_xyzz_xxxy = primBuffer.data(225 * idx + 121);

            auto t_xyzz_xxxz = primBuffer.data(225 * idx + 122);

            auto t_xyzz_xxyy = primBuffer.data(225 * idx + 123);

            auto t_xyzz_xxyz = primBuffer.data(225 * idx + 124);

            auto t_xyzz_xxzz = primBuffer.data(225 * idx + 125);

            auto t_xyzz_xyyy = primBuffer.data(225 * idx + 126);

            auto t_xyzz_xyyz = primBuffer.data(225 * idx + 127);

            auto t_xyzz_xyzz = primBuffer.data(225 * idx + 128);

            auto t_xyzz_xzzz = primBuffer.data(225 * idx + 129);

            auto t_xyzz_yyyy = primBuffer.data(225 * idx + 130);

            auto t_xyzz_yyyz = primBuffer.data(225 * idx + 131);

            auto t_xyzz_yyzz = primBuffer.data(225 * idx + 132);

            auto t_xyzz_yzzz = primBuffer.data(225 * idx + 133);

            auto t_xyzz_zzzz = primBuffer.data(225 * idx + 134);

            auto t_xzzz_xxxx = primBuffer.data(225 * idx + 135);

            auto t_xzzz_xxxy = primBuffer.data(225 * idx + 136);

            auto t_xzzz_xxxz = primBuffer.data(225 * idx + 137);

            auto t_xzzz_xxyy = primBuffer.data(225 * idx + 138);

            auto t_xzzz_xxyz = primBuffer.data(225 * idx + 139);

            auto t_xzzz_xxzz = primBuffer.data(225 * idx + 140);

            auto t_xzzz_xyyy = primBuffer.data(225 * idx + 141);

            auto t_xzzz_xyyz = primBuffer.data(225 * idx + 142);

            auto t_xzzz_xyzz = primBuffer.data(225 * idx + 143);

            auto t_xzzz_xzzz = primBuffer.data(225 * idx + 144);

            auto t_xzzz_yyyy = primBuffer.data(225 * idx + 145);

            auto t_xzzz_yyyz = primBuffer.data(225 * idx + 146);

            auto t_xzzz_yyzz = primBuffer.data(225 * idx + 147);

            auto t_xzzz_yzzz = primBuffer.data(225 * idx + 148);

            auto t_xzzz_zzzz = primBuffer.data(225 * idx + 149);

            auto t_yyyy_xxxx = primBuffer.data(225 * idx + 150);

            auto t_yyyy_xxxy = primBuffer.data(225 * idx + 151);

            auto t_yyyy_xxxz = primBuffer.data(225 * idx + 152);

            auto t_yyyy_xxyy = primBuffer.data(225 * idx + 153);

            auto t_yyyy_xxyz = primBuffer.data(225 * idx + 154);

            auto t_yyyy_xxzz = primBuffer.data(225 * idx + 155);

            auto t_yyyy_xyyy = primBuffer.data(225 * idx + 156);

            auto t_yyyy_xyyz = primBuffer.data(225 * idx + 157);

            auto t_yyyy_xyzz = primBuffer.data(225 * idx + 158);

            auto t_yyyy_xzzz = primBuffer.data(225 * idx + 159);

            auto t_yyyy_yyyy = primBuffer.data(225 * idx + 160);

            auto t_yyyy_yyyz = primBuffer.data(225 * idx + 161);

            auto t_yyyy_yyzz = primBuffer.data(225 * idx + 162);

            auto t_yyyy_yzzz = primBuffer.data(225 * idx + 163);

            auto t_yyyy_zzzz = primBuffer.data(225 * idx + 164);

            auto t_yyyz_xxxx = primBuffer.data(225 * idx + 165);

            auto t_yyyz_xxxy = primBuffer.data(225 * idx + 166);

            auto t_yyyz_xxxz = primBuffer.data(225 * idx + 167);

            auto t_yyyz_xxyy = primBuffer.data(225 * idx + 168);

            auto t_yyyz_xxyz = primBuffer.data(225 * idx + 169);

            auto t_yyyz_xxzz = primBuffer.data(225 * idx + 170);

            auto t_yyyz_xyyy = primBuffer.data(225 * idx + 171);

            auto t_yyyz_xyyz = primBuffer.data(225 * idx + 172);

            auto t_yyyz_xyzz = primBuffer.data(225 * idx + 173);

            auto t_yyyz_xzzz = primBuffer.data(225 * idx + 174);

            auto t_yyyz_yyyy = primBuffer.data(225 * idx + 175);

            auto t_yyyz_yyyz = primBuffer.data(225 * idx + 176);

            auto t_yyyz_yyzz = primBuffer.data(225 * idx + 177);

            auto t_yyyz_yzzz = primBuffer.data(225 * idx + 178);

            auto t_yyyz_zzzz = primBuffer.data(225 * idx + 179);

            auto t_yyzz_xxxx = primBuffer.data(225 * idx + 180);

            auto t_yyzz_xxxy = primBuffer.data(225 * idx + 181);

            auto t_yyzz_xxxz = primBuffer.data(225 * idx + 182);

            auto t_yyzz_xxyy = primBuffer.data(225 * idx + 183);

            auto t_yyzz_xxyz = primBuffer.data(225 * idx + 184);

            auto t_yyzz_xxzz = primBuffer.data(225 * idx + 185);

            auto t_yyzz_xyyy = primBuffer.data(225 * idx + 186);

            auto t_yyzz_xyyz = primBuffer.data(225 * idx + 187);

            auto t_yyzz_xyzz = primBuffer.data(225 * idx + 188);

            auto t_yyzz_xzzz = primBuffer.data(225 * idx + 189);

            auto t_yyzz_yyyy = primBuffer.data(225 * idx + 190);

            auto t_yyzz_yyyz = primBuffer.data(225 * idx + 191);

            auto t_yyzz_yyzz = primBuffer.data(225 * idx + 192);

            auto t_yyzz_yzzz = primBuffer.data(225 * idx + 193);

            auto t_yyzz_zzzz = primBuffer.data(225 * idx + 194);

            auto t_yzzz_xxxx = primBuffer.data(225 * idx + 195);

            auto t_yzzz_xxxy = primBuffer.data(225 * idx + 196);

            auto t_yzzz_xxxz = primBuffer.data(225 * idx + 197);

            auto t_yzzz_xxyy = primBuffer.data(225 * idx + 198);

            auto t_yzzz_xxyz = primBuffer.data(225 * idx + 199);

            auto t_yzzz_xxzz = primBuffer.data(225 * idx + 200);

            auto t_yzzz_xyyy = primBuffer.data(225 * idx + 201);

            auto t_yzzz_xyyz = primBuffer.data(225 * idx + 202);

            auto t_yzzz_xyzz = primBuffer.data(225 * idx + 203);

            auto t_yzzz_xzzz = primBuffer.data(225 * idx + 204);

            auto t_yzzz_yyyy = primBuffer.data(225 * idx + 205);

            auto t_yzzz_yyyz = primBuffer.data(225 * idx + 206);

            auto t_yzzz_yyzz = primBuffer.data(225 * idx + 207);

            auto t_yzzz_yzzz = primBuffer.data(225 * idx + 208);

            auto t_yzzz_zzzz = primBuffer.data(225 * idx + 209);

            auto t_zzzz_xxxx = primBuffer.data(225 * idx + 210);

            auto t_zzzz_xxxy = primBuffer.data(225 * idx + 211);

            auto t_zzzz_xxxz = primBuffer.data(225 * idx + 212);

            auto t_zzzz_xxyy = primBuffer.data(225 * idx + 213);

            auto t_zzzz_xxyz = primBuffer.data(225 * idx + 214);

            auto t_zzzz_xxzz = primBuffer.data(225 * idx + 215);

            auto t_zzzz_xyyy = primBuffer.data(225 * idx + 216);

            auto t_zzzz_xyyz = primBuffer.data(225 * idx + 217);

            auto t_zzzz_xyzz = primBuffer.data(225 * idx + 218);

            auto t_zzzz_xzzz = primBuffer.data(225 * idx + 219);

            auto t_zzzz_yyyy = primBuffer.data(225 * idx + 220);

            auto t_zzzz_yyyz = primBuffer.data(225 * idx + 221);

            auto t_zzzz_yyzz = primBuffer.data(225 * idx + 222);

            auto t_zzzz_yzzz = primBuffer.data(225 * idx + 223);

            auto t_zzzz_zzzz = primBuffer.data(225 * idx + 224);

            // Batch of Integrals (0) = (0,5)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxx, pb_x, pb_xx, pb_xxx, pb_xxxx, \
                                     pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_y, \
                                     pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xxxx_xxxx, t_xxxx_xxxy, t_xxxx_xxxz, \
                                     t_xxxx_xxyy, t_xxxx_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxx_xxxx[j] = (6.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 11.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 30.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 11.25 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xxxx[j] * fx[j] * fx[j] + 

                                 12.0 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 12.0 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xxxx[j] * pb_xx[j] * fx[j] + 8.0 * pa_xxx[j] * fx[j] * pb_xxx[j] + 

                                 0.75 * fx[j] * fx[j] * pb_xxxx[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxxx[j] + pa_xxxx[j] * pb_xxxx[j]) * s_0_0[j] + (52.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 112.5 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 300.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 4.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 27.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 3.0 * pa_xxxx[j] * fx[j] * fz[j] * fgb[j] - 

                                 24.0 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 112.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] + 144.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 324.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 4.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 18.0 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 24.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 6.0 * pa_xxxx[j] * pb_xx[j] * fz[j] * fgb[j] + 

                                 144.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xxxx[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 112.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxx[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxxx[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxxx_xxxy[j] = (7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 13.5 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * pa_xxxx[j] * pb_xy[j] * fx[j] + 

                                 6.0 * pa_xxx[j] * fx[j] * pb_xxy[j] + 0.75 * fx[j] * fx[j] * pb_xxxy[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxxy[j] + 

                                 pa_xxxx[j] * pb_xxxy[j]) * s_0_0[j] + (75.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 6.0 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 162.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 18.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 3.0 * pa_xxxx[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 21.0 * pa_xxxx[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 84.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxy[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxxy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxy[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxxx_xxxz[j] = (7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 13.5 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * pa_xxxx[j] * pb_xz[j] * fx[j] + 

                                 6.0 * pa_xxx[j] * fx[j] * pb_xxz[j] + 0.75 * fx[j] * fx[j] * pb_xxxz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxxz[j] + 

                                 pa_xxxx[j] * pb_xxxz[j]) * s_0_0[j] + (75.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 6.0 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 162.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 18.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 3.0 * pa_xxxx[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 21.0 * pa_xxxx[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 84.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxxz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxxx_xxyy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_xxxx[j] * fx[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 0.5 * pa_xxxx[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxxx[j] * fx[j] * pb_yy[j] + 

                                 4.0 * pa_xxx[j] * fx[j] * pb_xyy[j] + 0.75 * fx[j] * fx[j] * pb_xxyy[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxyy[j] + 

                                 pa_xxxx[j] * pb_xxyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 pa_xxxx[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 30.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 3.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 54.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 12.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 pa_xxxx[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxx[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 72.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 7.0 * pa_xxxx[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxxx[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 56.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyy[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyy[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxxx_xxyz[j] = (1.875 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * pa_xxxx[j] * fx[j] * pb_yz[j] + 

                                 4.0 * pa_xxx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pb_xxyz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxyz[j] + 

                                 pa_xxxx[j] * pb_xxyz[j]) * s_0_0[j] + (-4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] + 

                                 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 54.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 3.0 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 12.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 pa_xxxx[j] * fz[j] * fgb[j] * pb_yz[j] + 72.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 7.0 * pa_xxxx[j] * fz[j] * fx[j] * pb_yz[j] + 56.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyz[j] - 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxyz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] + 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxxx[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (1) = (5,10)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxx, pb_x, pb_xx, pb_xxzz, pb_xy, pb_xyyy, \
                                     pb_xyyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yyy, pb_yyz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xxxx_xxzz, t_xxxx_xyyy, t_xxxx_xyyz, t_xxxx_xyzz, \
                                     t_xxxx_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxx_xxzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_xxxx[j] * fx[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 0.5 * pa_xxxx[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxxx[j] * fx[j] * pb_zz[j] + 

                                 4.0 * pa_xxx[j] * fx[j] * pb_xzz[j] + 0.75 * fx[j] * fx[j] * pb_xxzz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xxzz[j] + 

                                 pa_xxxx[j] * pb_xxzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 pa_xxxx[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 30.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 54.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 12.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 pa_xxxx[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxx[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 72.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 7.0 * pa_xxxx[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxxx[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 56.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxzz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xxzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxzz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxxx_xyyy[j] = (4.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xxxx[j] * pb_xy[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_yyy[j] + 0.75 * fx[j] * fx[j] * pb_xyyy[j] + 3.0 * pa_xx[j] * fx[j] * pb_xyyy[j] + 

                                 pa_xxxx[j] * pb_xyyy[j]) * s_0_0[j] + (-9.0 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 6.0 * pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 9.0 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 3.0 * pa_xxxx[j] * pb_xy[j] * fz[j] * fgb[j] + 54.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 21.0 * pa_xxxx[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyy[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyy[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxxx_xyyz[j] = (1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xxxx[j] * pb_xz[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_yyz[j] + 0.75 * fx[j] * fx[j] * pb_xyyz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xyyz[j] + 

                                 pa_xxxx[j] * pb_xyyz[j]) * s_0_0[j] + (-3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 2.0 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 12.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 pa_xxxx[j] * pb_xz[j] * fz[j] * fgb[j] + 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 7.0 * pa_xxxx[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xyyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxxx_xyzz[j] = (1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xxxx[j] * pb_xy[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_yzz[j] + 0.75 * fx[j] * fx[j] * pb_xyzz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xyzz[j] + 

                                 pa_xxxx[j] * pb_xyzz[j]) * s_0_0[j] + (-3.0 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 2.0 * pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 12.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 pa_xxxx[j] * pb_xy[j] * fz[j] * fgb[j] + 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 7.0 * pa_xxxx[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyzz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xyzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyzz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxxx_xzzz[j] = (4.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xxxx[j] * pb_xz[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_zzz[j] + 0.75 * fx[j] * fx[j] * pb_xzzz[j] + 3.0 * pa_xx[j] * fx[j] * pb_xzzz[j] + 

                                 pa_xxxx[j] * pb_xzzz[j]) * s_0_0[j] + (-9.0 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 6.0 * pa_xxx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 9.0 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 3.0 * pa_xxxx[j] * pb_xz[j] * fz[j] * fgb[j] + 54.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 21.0 * pa_xxxx[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xzzz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_xzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_xzzz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (2) = (10,15)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_xx, pa_xxxx, pb_yy, pb_yyyy, pb_yyyz, pb_yyzz, pb_yz, pb_yzzz, \
                                     pb_zz, pb_zzzz, r_0_0, s_0_0, t_xxxx_yyyy, t_xxxx_yyyz, t_xxxx_yyzz, \
                                     t_xxxx_yzzz, t_xxxx_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxx_yyyy[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_xxxx[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 9.0 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 3.0 * pa_xxxx[j] * pb_yy[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_yyyy[j] + 3.0 * pa_xx[j] * fx[j] * pb_yyyy[j] + 

                                 pa_xxxx[j] * pb_yyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_xxxx[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 18.0 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 6.0 * pa_xxxx[j] * pb_yy[j] * fz[j] * fgb[j] + 108.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 42.0 * pa_xxxx[j] * fz[j] * pb_yy[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyy[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_yyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxxx_yyyz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_xxxx[j] * pb_yz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_yyyz[j] + 

                                 3.0 * pa_xx[j] * fx[j] * pb_yyyz[j] + pa_xxxx[j] * pb_yyyz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 9.0 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 3.0 * pa_xxxx[j] * pb_yz[j] * fz[j] * fgb[j] + 54.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 21.0 * pa_xxxx[j] * fz[j] * pb_yz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_yyyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxxx_yyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_xxxx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 0.5 * pa_xxxx[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_xxxx[j] * fx[j] * pb_zz[j] + 0.75 * fx[j] * fx[j] * pb_yyzz[j] + 3.0 * pa_xx[j] * fx[j] * pb_yyzz[j] + 

                                 pa_xxxx[j] * pb_yyzz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 3.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] + 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - pa_xxxx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] - 

                                 0.75 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 pa_xxxx[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxxx[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 7.0 * pa_xxxx[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xxxx[j] * fz[j] * fx[j] * pb_zz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_yyzz[j] - 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] + 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxxx[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxxx_yzzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_xxxx[j] * pb_yz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_yzzz[j] + 

                                 3.0 * pa_xx[j] * fx[j] * pb_yzzz[j] + pa_xxxx[j] * pb_yzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 9.0 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 3.0 * pa_xxxx[j] * pb_yz[j] * fz[j] * fgb[j] + 54.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 21.0 * pa_xxxx[j] * fz[j] * pb_yz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yzzz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_yzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_yzzz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxxx_zzzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_xxxx[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 9.0 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_xxxx[j] * pb_zz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_zzzz[j] + 3.0 * pa_xx[j] * fx[j] * pb_zzzz[j] + 

                                 pa_xxxx[j] * pb_zzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_xxxx[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_xxxx[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 18.0 * pa_xx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xx[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 6.0 * pa_xxxx[j] * pb_zz[j] * fz[j] * fgb[j] + 108.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_xxxx[j] * fz[j] * pb_zz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_zzzz[j] - 

                                 6.0 * pa_xx[j] * fz[j] * fga[j] * pb_zzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] + 

                                 42.0 * pa_xx[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_xxxx[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (3) = (15,20)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxy, pa_xxy, pa_xy, pa_y, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xxxy_xxxx, t_xxxy_xxxy, \
                                     t_xxxy_xxxz, t_xxxy_xxyy, t_xxxy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxy_xxxx[j] = (5.625 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_xxxy[j] * fx[j] * fx[j] + 9.0 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 13.5 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * fx[j] * fx[j] * pa_y[j] * pb_xxx[j] + 3.0 * pa_xxxy[j] * pb_xx[j] * fx[j] + 

                                 6.0 * pa_xxy[j] * fx[j] * pb_xxx[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxxx[j] + pa_xxxy[j] * pb_xxxx[j]) * s_0_0[j] + (-13.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_x[j] - 

                                 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_x[j] - 3.0 * pa_xxxy[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 9.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 162.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 9.0 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 6.0 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xxx[j] - 6.0 * pa_xxxy[j] * pb_xx[j] * fz[j] * fgb[j] + 

                                 36.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xxx[j] + 42.0 * pa_xxxy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 84.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xxx[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxxx[j] + 16.0 * pa_xxxy[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxxy_xxxy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 3.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 6.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_xxy[j] + 1.5 * pa_xxxy[j] * pb_xy[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_xxx[j] + 

                                 4.5 * pa_xxy[j] * fx[j] * pb_xxy[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxxy[j] + pa_xxxy[j] * pb_xxxy[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 11.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 33.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_y[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_y[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 81.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxx[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xxy[j] - 

                                 3.0 * pa_xxxy[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 27.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xxy[j] + 21.0 * pa_xxxy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxx[j] + 63.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xxy[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxxy_xxxz[j] = (1.875 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 2.25 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 6.75 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_xxz[j] + 1.5 * pa_xxxy[j] * pb_xz[j] * fx[j] + 4.5 * pa_xxy[j] * fx[j] * pb_xxz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xxxz[j] + pa_xxxy[j] * pb_xxxz[j]) * s_0_0[j] + (18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_z[j] - 

                                 4.5 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 27.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 81.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 4.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xxz[j] - 

                                 3.0 * pa_xxxy[j] * pb_xz[j] * fz[j] * fgb[j] + 27.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xxz[j] + 

                                 21.0 * pa_xxxy[j] * fz[j] * pb_xz[j] * fx[j] + 63.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxxy_xxyy[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xxxy[j] * fx[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 3.0 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xyy[j] + 0.5 * pa_xxxy[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xxxy[j] * fx[j] * pb_yy[j] + pa_xxx[j] * fx[j] * pb_xxy[j] + 3.0 * pa_xxy[j] * fx[j] * pb_xyy[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xxyy[j] + pa_xxxy[j] * pb_xxyy[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_x[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 pa_xxxy[j] * fx[j] * fz[j] * fgb[j] - pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 3.0 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_x[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 18.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 36.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xyy[j] - 

                                 pa_xxxy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxy[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xyy[j] + 7.0 * pa_xxxy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xxxy[j] * fz[j] * fx[j] * pb_yy[j] + 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 42.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xyy[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxyy[j] + 16.0 * pa_xxxy[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxxy_xxyz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xyz[j] + 0.5 * pa_xxxy[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_xxx[j] * fx[j] * pb_xxz[j] + 3.0 * pa_xxy[j] * fx[j] * pb_xyz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxyz[j] + 

                                 pa_xxxy[j] * pb_xxyz[j]) * s_0_0[j] + (11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 0.5 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 18.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xyz[j] - 

                                 pa_xxxy[j] * fz[j] * fgb[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xyz[j] + 7.0 * pa_xxxy[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxz[j] + 42.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (4) = (20,25)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxy, pa_xxy, pa_xy, pa_y, pb_x, pb_xx, \
                                     pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, \
                                     pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, s_0_0, t_xxxy_xxzz, \
                                     t_xxxy_xyyy, t_xxxy_xyyz, t_xxxy_xyzz, t_xxxy_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxy_xxzz[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.25 * pa_xxxy[j] * fx[j] * fx[j] + 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xzz[j] + 0.5 * pa_xxxy[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxxy[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_xxy[j] * fx[j] * pb_xzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxzz[j] + pa_xxxy[j] * pb_xxzz[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_x[j] - 

                                 pa_xxxy[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_x[j] + 3.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_xzz[j] - pa_xxxy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 18.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_xzz[j] + 

                                 7.0 * pa_xxxy[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxxy[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_xxy[j] * fx[j] * fz[j] * pb_xzz[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xxzz[j] + 16.0 * pa_xxxy[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxxy_xyyy[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 2.25 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yyy[j] + 1.5 * pa_xxxy[j] * pb_xy[j] * fx[j] + 1.5 * pa_xxx[j] * fx[j] * pb_xyy[j] + 

                                 1.5 * pa_xxy[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyyy[j] + pa_xxxy[j] * pb_xyyy[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 1.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_y[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 4.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 4.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyy[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_yyy[j] - 3.0 * pa_xxxy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_yyy[j] + 21.0 * pa_xxxy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 21.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyy[j] + 21.0 * pa_xxy[j] * fx[j] * fz[j] * pb_yyy[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxxy_xyyz[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yyz[j] + 0.5 * pa_xxxy[j] * pb_xz[j] * fx[j] + 

                                 pa_xxx[j] * fx[j] * pb_xyz[j] + 1.5 * pa_xxy[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyyz[j] + 

                                 pa_xxxy[j] * pb_xyyz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 1.5 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_z[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 1.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_yyz[j] - pa_xxxy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_yyz[j] + 7.0 * pa_xxxy[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyz[j] + 21.0 * pa_xxy[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxxy_xyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yzz[j] + 0.5 * pa_xxxy[j] * pb_xy[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_xzz[j] + 

                                 1.5 * pa_xxy[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyzz[j] + pa_xxxy[j] * pb_xyzz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 0.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 1.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xzz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_yzz[j] - pa_xxxy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_yzz[j] + 7.0 * pa_xxxy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xzz[j] + 21.0 * pa_xxy[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxxy_xzzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 2.25 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_zzz[j] + 1.5 * pa_xxxy[j] * pb_xz[j] * fx[j] + 1.5 * pa_xxy[j] * fx[j] * pb_zzz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xzzz[j] + pa_xxxy[j] * pb_xzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_y[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_z[j] - 4.5 * pa_xxy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_z[j] + 27.0 * pa_xxy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_y[j] * pb_zzz[j] - 3.0 * pa_xxxy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pa_y[j] * pb_zzz[j] + 

                                 21.0 * pa_xxxy[j] * fz[j] * pb_xz[j] * fx[j] + 21.0 * pa_xxy[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (5) = (25,30)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xxx, pa_xxxy, pa_xy, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xxxy_yyyy, t_xxxy_yyyz, t_xxxy_yyzz, t_xxxy_yzzz, t_xxxy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxy_yyyy[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xxxy[j] * fx[j] * fx[j] + 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 4.5 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 3.0 * pa_xxxy[j] * pb_yy[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xy[j] * fx[j] * pb_yyyy[j] + pa_xxxy[j] * pb_yyyy[j]) * s_0_0[j] + (-4.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 9.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 3.0 * pa_xxxy[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 45.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 9.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 9.0 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 6.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyy[j] - 

                                 6.0 * pa_xxxy[j] * pb_yy[j] * fz[j] * fgb[j] + 54.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 42.0 * pa_xxxy[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyy[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_yyyy[j] + 16.0 * pa_xxxy[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxxy_yyyz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xxxy[j] * pb_yz[j] * fx[j] + 1.5 * pa_xxx[j] * fx[j] * pb_yyz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_yyyz[j] + pa_xxxy[j] * pb_yyyz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 1.5 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 4.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyz[j] - 3.0 * pa_xxxy[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 21.0 * pa_xxxy[j] * fz[j] * pb_yz[j] * fx[j] + 21.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxxy_yyzz[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * pa_xxxy[j] * fx[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xxxy[j] * pb_yy[j] * fx[j] + 0.5 * pa_xxxy[j] * fx[j] * pb_zz[j] + 

                                 pa_xxx[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_yyzz[j] + pa_xxxy[j] * pb_yyzz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - pa_xxxy[j] * fx[j] * fz[j] * fgb[j] - pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 3.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yzz[j] - pa_xxxy[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxxy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 7.0 * pa_xxxy[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 7.0 * pa_xxxy[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyzz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxxy_yzzz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xxxy[j] * pb_yz[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_zzz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_yzzz[j] + pa_xxxy[j] * pb_yzzz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 1.5 * pa_xxx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_zzz[j] - 3.0 * pa_xxxy[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 

                                 21.0 * pa_xxxy[j] * fz[j] * pb_yz[j] * fx[j] + 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_zzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xxxy[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxxy_zzzz[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xxxy[j] * fx[j] * fx[j] + 

                                 4.5 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_xxxy[j] * pb_zz[j] * fx[j] + 1.5 * pa_xy[j] * fx[j] * pb_zzzz[j] + 

                                 pa_xxxy[j] * pb_zzzz[j]) * s_0_0[j] + (-4.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_xxxy[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 9.0 * pa_xxxy[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_xy[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 6.0 * pa_xxxy[j] * pb_zz[j] * fz[j] * fgb[j] + 54.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 42.0 * pa_xxxy[j] * fz[j] * pb_zz[j] * fx[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_xy[j] * fx[j] * fz[j] * pb_zzzz[j] + 16.0 * pa_xxxy[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (6) = (30,35)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxz, pa_xxz, pa_xz, pa_z, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xxxz_xxxx, t_xxxz_xxxy, \
                                     t_xxxz_xxxz, t_xxxz_xxyy, t_xxxz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxz_xxxx[j] = (5.625 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_xxxz[j] * fx[j] * fx[j] + 9.0 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 13.5 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 3.0 * pa_xxxz[j] * pb_xx[j] * fx[j] + 

                                 6.0 * pa_xxz[j] * fx[j] * pb_xxx[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxxx[j] + pa_xxxz[j] * pb_xxxx[j]) * s_0_0[j] + (-13.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] - 

                                 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 3.0 * pa_xxxz[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 9.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 162.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 9.0 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 6.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxx[j] - 6.0 * pa_xxxz[j] * pb_xx[j] * fz[j] * fgb[j] + 

                                 36.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxx[j] + 42.0 * pa_xxxz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 84.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxx[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxx[j] + 16.0 * pa_xxxz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxxz_xxxy[j] = (1.875 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 2.25 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 6.75 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 1.5 * pa_xxxz[j] * pb_xy[j] * fx[j] + 4.5 * pa_xxz[j] * fx[j] * pb_xxy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xxxy[j] + pa_xxxz[j] * pb_xxxy[j]) * s_0_0[j] + (18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 

                                 4.5 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 27.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 81.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 4.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxy[j] - 

                                 3.0 * pa_xxxz[j] * pb_xy[j] * fz[j] * fgb[j] + 27.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxy[j] + 

                                 21.0 * pa_xxxz[j] * fz[j] * pb_xy[j] * fx[j] + 63.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxxz_xxxz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 3.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 6.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 1.5 * pa_xxxz[j] * pb_xz[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_xxx[j] + 

                                 4.5 * pa_xxz[j] * fx[j] * pb_xxz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxxz[j] + pa_xxxz[j] * pb_xxxz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 11.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 33.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 81.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxx[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxz[j] - 

                                 3.0 * pa_xxxz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 27.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxz[j] + 21.0 * pa_xxxz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxx[j] + 63.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxxz_xxyy[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.25 * pa_xxxz[j] * fx[j] * fx[j] + 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 0.5 * pa_xxxz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxxz[j] * fx[j] * pb_yy[j] + 

                                 3.0 * pa_xxz[j] * fx[j] * pb_xyy[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxyy[j] + pa_xxxz[j] * pb_xxyy[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 

                                 pa_xxxz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 3.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyy[j] - pa_xxxz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyy[j] + 

                                 7.0 * pa_xxxz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxxz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 42.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xyy[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxyy[j] + 16.0 * pa_xxxz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxxz_xxyz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_xxxz[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_xxx[j] * fx[j] * pb_xxy[j] + 3.0 * pa_xxz[j] * fx[j] * pb_xyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxyz[j] + 

                                 pa_xxxz[j] * pb_xxyz[j]) * s_0_0[j] + (11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 0.5 * pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 18.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyz[j] - 

                                 pa_xxxz[j] * fz[j] * fgb[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyz[j] + 7.0 * pa_xxxz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxy[j] + 42.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (7) = (35,40)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxx, pa_xxxz, pa_xxz, pa_xz, pa_z, pb_x, pb_xx, \
                                     pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, \
                                     pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, s_0_0, \
                                     t_xxxz_xxzz, t_xxxz_xyyy, t_xxxz_xyyz, t_xxxz_xyzz, t_xxxz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxz_xxzz[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xxxz[j] * fx[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 3.0 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_xxxz[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xxxz[j] * fx[j] * pb_zz[j] + pa_xxx[j] * fx[j] * pb_xxz[j] + 3.0 * pa_xxz[j] * fx[j] * pb_xzz[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xxzz[j] + pa_xxxz[j] * pb_xxzz[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 pa_xxxz[j] * fx[j] * fz[j] * fgb[j] - pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 3.0 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 18.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 36.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xzz[j] - 

                                 pa_xxxz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxxz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xzz[j] + 7.0 * pa_xxxz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xxxz[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xxz[j] + 

                                 42.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xzz[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxzz[j] + 16.0 * pa_xxxz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxxz_xyyy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 2.25 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 1.5 * pa_xxxz[j] * pb_xy[j] * fx[j] + 1.5 * pa_xxz[j] * fx[j] * pb_yyy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xyyy[j] + pa_xxxz[j] * pb_xyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 4.5 * pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 27.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyy[j] - 3.0 * pa_xxxz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyy[j] + 

                                 21.0 * pa_xxxz[j] * fz[j] * pb_xy[j] * fx[j] + 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yyy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxxz_xyyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 0.5 * pa_xxxz[j] * pb_xz[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_xyy[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xyyz[j] + pa_xxxz[j] * pb_xyyz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 0.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 3.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 1.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyy[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyz[j] - pa_xxxz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyz[j] + 7.0 * pa_xxxz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyy[j] + 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxxz_xyzz[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_xxxz[j] * pb_xy[j] * fx[j] + 

                                 pa_xxx[j] * fx[j] * pb_xyz[j] + 1.5 * pa_xxz[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xyzz[j] + 

                                 pa_xxxz[j] * pb_xyzz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 1.5 * pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 18.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 1.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yzz[j] - pa_xxxz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yzz[j] + 7.0 * pa_xxxz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xyz[j] + 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxxz_xzzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 2.25 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_xxxz[j] * pb_xz[j] * fx[j] + 1.5 * pa_xxx[j] * fx[j] * pb_xzz[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xzzz[j] + pa_xxxz[j] * pb_xzzz[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 1.5 * pa_xxx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xxz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 4.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 4.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xzz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_zzz[j] - 3.0 * pa_xxxz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_zzz[j] + 21.0 * pa_xxxz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_xxx[j] * fz[j] * fx[j] * pb_xzz[j] + 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (8) = (40,45)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xxx, pa_xxxz, pa_xz, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xxxz_yyyy, t_xxxz_yyyz, t_xxxz_yyzz, t_xxxz_yzzz, t_xxxz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxxz_yyyy[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xxxz[j] * fx[j] * fx[j] + 

                                 4.5 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * pa_xxxz[j] * pb_yy[j] * fx[j] + 1.5 * pa_xz[j] * fx[j] * pb_yyyy[j] + 

                                 pa_xxxz[j] * pb_yyyy[j]) * s_0_0[j] + (-4.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_xxxz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 9.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 6.0 * pa_xxxz[j] * pb_yy[j] * fz[j] * fgb[j] + 54.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 42.0 * pa_xxxz[j] * fz[j] * pb_yy[j] * fx[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyyy[j] + 16.0 * pa_xxxz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxxz_yyyz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xxxz[j] * pb_yz[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * pb_yyy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_yyyz[j] + pa_xxxz[j] * pb_yyyz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 1.5 * pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyy[j] - 3.0 * pa_xxxz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 

                                 21.0 * pa_xxxz[j] * fz[j] * pb_yz[j] * fx[j] + 7.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxxz_yyzz[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * pa_xxxz[j] * fx[j] * fx[j] + 0.5 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xxxz[j] * pb_yy[j] * fx[j] + 0.5 * pa_xxxz[j] * fx[j] * pb_zz[j] + 

                                 pa_xxx[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_yyzz[j] + pa_xxxz[j] * pb_yyzz[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - pa_xxxz[j] * fx[j] * fz[j] * fgb[j] - pa_xxx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 3.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyz[j] - pa_xxxz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxxz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 7.0 * pa_xxxz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 7.0 * pa_xxxz[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yyz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyzz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxxz_yzzz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xxx[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xxxz[j] * pb_yz[j] * fx[j] + 1.5 * pa_xxx[j] * fx[j] * pb_yzz[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_yzzz[j] + pa_xxxz[j] * pb_yzzz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 1.5 * pa_xxx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 9.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 4.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yzz[j] - 3.0 * pa_xxxz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 21.0 * pa_xxxz[j] * fz[j] * pb_yz[j] * fx[j] + 21.0 * pa_xxx[j] * fz[j] * fx[j] * pb_yzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xxxz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxxz_zzzz[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xxxz[j] * fx[j] * fx[j] + 3.0 * pa_xxx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 4.5 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_xxxz[j] * pb_zz[j] * fx[j] + 

                                 2.0 * pa_xxx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_zzzz[j] + pa_xxxz[j] * pb_zzzz[j]) * s_0_0[j] + (-4.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 9.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_xxxz[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_xxx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 45.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 9.0 * pa_xxxz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xxx[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 9.0 * pa_xz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 6.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_xxxz[j] * pb_zz[j] * fz[j] * fgb[j] + 54.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_xxxz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 28.0 * pa_xxx[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_xz[j] * fx[j] * fz[j] * pb_zzzz[j] + 16.0 * pa_xxxz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (9) = (45,50)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxyy, pa_xy, pa_xyy, pa_y, pa_yy, pb_x, \
                                     pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xxyy_xxxx, \
                                     t_xxyy_xxxy, t_xxyy_xxxz, t_xxyy_xxyy, t_xxyy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyy_xxxx[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xxyy[j] * fx[j] * fx[j] + 6.0 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 4.5 * fx[j] * fx[j] * pa_yy[j] * pb_xx[j] + 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.0 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xxyy[j] * pb_xx[j] * fx[j] + 4.0 * pa_xyy[j] * fx[j] * pb_xxx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxx[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxxx[j] + 0.5 * fx[j] * pa_yy[j] * pb_xxxx[j] + 

                                 pa_xxyy[j] * pb_xxxx[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 4.5 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 6.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.75 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xxyy[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 12.0 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 30.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 9.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 54.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xx[j] - 

                                 1.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 4.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 3.0 * fx[j] * pa_yy[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * fz[j] * fga[j] * pa_yy[j] * pb_xx[j] * fx[j] - 

                                 6.0 * pa_xxyy[j] * pb_xx[j] * fz[j] * fgb[j] + 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 24.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xxyy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 56.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xxx[j] - fx[j] * fz[j] * fga[j] * pb_xxxx[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxxx[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxx[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxxx[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxyy_xxxy[j] = (1.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 3.0 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_yy[j] * pb_xy[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xxx[j] + 1.5 * pa_xxyy[j] * pb_xy[j] * fx[j] + 

                                 pa_xxy[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xyy[j] * fx[j] * pb_xxy[j] + 0.25 * fx[j] * fx[j] * pb_xxxy[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_xxxy[j] + 0.5 * fx[j] * pa_yy[j] * pb_xxxy[j] + pa_xxyy[j] * pb_xxxy[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - 3.0 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 18.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 36.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 27.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xy[j] - 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 1.5 * fx[j] * pa_yy[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_xy[j] * fx[j] - fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxx[j] - 

                                 3.0 * pa_xxyy[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxx[j] + 

                                 42.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xxy[j] - fx[j] * fz[j] * fga[j] * pb_xxxy[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxxy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxxy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxy[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxyy_xxxz[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * fx[j] * fx[j] * pa_yy[j] * pb_xz[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * pa_xxyy[j] * pb_xz[j] * fx[j] + 3.0 * pa_xyy[j] * fx[j] * pb_xxz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxxz[j] + 0.5 * fx[j] * pa_yy[j] * pb_xxxz[j] + 

                                 pa_xxyy[j] * pb_xxxz[j]) * s_0_0[j] + (-1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 3.0 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 27.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xz[j] - 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 1.5 * fx[j] * pa_yy[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_xz[j] * fx[j] - 3.0 * pa_xxyy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_xz[j] * fx[j] + 42.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xxz[j] - fx[j] * fz[j] * fga[j] * pb_xxxz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxxz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxxz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxyy_xxyy[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.25 * pa_xxyy[j] * fx[j] * fx[j] + pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 4.0 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_yy[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_xx[j] + fx[j] * fx[j] * pa_y[j] * pb_xxy[j] + 0.5 * pa_xxyy[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xxyy[j] * fx[j] * pb_yy[j] + 2.0 * pa_xxy[j] * fx[j] * pb_xxy[j] + 2.0 * pa_xyy[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxyy[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxyy[j] + 0.5 * fx[j] * pa_yy[j] * pb_xxyy[j] + 

                                 pa_xxyy[j] * pb_xxyy[j]) * s_0_0[j] + (4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 15.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] - 

                                 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 0.25 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_xx[j] - pa_xxyy[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 2.0 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 3.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 12.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 48.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yy[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 0.5 * fx[j] * pa_yy[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * pa_yy[j] * fz[j] * fgb[j] * pb_yy[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yy[j] * fx[j] * pb_yy[j] - 2.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxy[j] - 

                                 pa_xxyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxyy[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xx[j] + 12.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxy[j] + 

                                 7.0 * pa_xxyy[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxyy[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 28.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxy[j] + 28.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xyy[j] - fx[j] * fz[j] * fga[j] * pb_xxyy[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxyy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyy[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxyy[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxyy_xxyz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.5 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.0 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_yz[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xxz[j] + 

                                 0.5 * pa_xxyy[j] * fx[j] * pb_yz[j] + pa_xxy[j] * fx[j] * pb_xxz[j] + 2.0 * pa_xyy[j] * fx[j] * pb_xyz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxyz[j] + 0.5 * fx[j] * pa_yy[j] * pb_xxyz[j] + 

                                 pa_xxyy[j] * pb_xxyz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] - 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 6.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 24.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yz[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 0.5 * fx[j] * pa_yy[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * fx[j] * pb_yz[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxz[j] - pa_xxyy[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxz[j] + 7.0 * pa_xxyy[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxz[j] + 28.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xyz[j] - fx[j] * fz[j] * fga[j] * pb_xxyz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (10) = (50,55)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxyy, pa_xy, pa_xyy, pa_y, pa_yy, pb_x, \
                                     pb_xx, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, \
                                     pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, s_0_0, \
                                     t_xxyy_xxzz, t_xxyy_xyyy, t_xxyy_xyyz, t_xxyy_xyzz, t_xxyy_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyy_xxzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_xxyy[j] * fx[j] * fx[j] + pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_zz[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_xx[j] + 0.5 * pa_xxyy[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxyy[j] * fx[j] * pb_zz[j] + 

                                 2.0 * pa_xyy[j] * fx[j] * pb_xzz[j] + 0.25 * fx[j] * fx[j] * pb_xxzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxzz[j] + 

                                 0.5 * fx[j] * pa_yy[j] * pb_xxzz[j] + pa_xxyy[j] * pb_xxzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 0.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 0.25 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 pa_xxyy[j] * fx[j] * fz[j] * fgb[j] + 1.25 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 2.0 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 5.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 3.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] + 

                                 12.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_zz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.5 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 0.5 * fx[j] * pa_yy[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yy[j] * fx[j] * pb_zz[j] - pa_xxyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xx[j] + 

                                 7.0 * pa_xxyy[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxyy[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xyy[j] * fx[j] * fz[j] * pb_xzz[j] - fx[j] * fz[j] * fga[j] * pb_xxzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xxzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxyy_xyyy[j] = (1.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 3.0 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_xy[j] + 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xyy[j] + 1.5 * pa_xxyy[j] * pb_xy[j] * fx[j] + 

                                 3.0 * pa_xxy[j] * fx[j] * pb_xyy[j] + pa_xyy[j] * fx[j] * pb_yyy[j] + 0.25 * fx[j] * fx[j] * pb_xyyy[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_xyyy[j] + 0.5 * fx[j] * pa_yy[j] * pb_xyyy[j] + pa_xxyy[j] * pb_xyyy[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - 

                                 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xy[j] - 3.0 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 36.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 1.5 * fx[j] * pa_yy[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_xy[j] * fx[j] - 3.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xyy[j] - 

                                 3.0 * pa_xxyy[j] * pb_xy[j] * fz[j] * fgb[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xy[j] + 18.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyy[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_xy[j] * fx[j] + 42.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xyy[j] + 

                                 14.0 * pa_xyy[j] * fx[j] * fz[j] * pb_yyy[j] - fx[j] * fz[j] * fga[j] * pb_xyyy[j] - pa_xx[j] * fz[j] * fga[j] * pb_xyyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] - fz[j] * fga[j] * pa_yy[j] * pb_xyyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyy[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxyy_xyyz[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.5 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 2.0 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_xz[j] + fx[j] * fx[j] * pa_y[j] * pb_xyz[j] + 

                                 0.5 * pa_xxyy[j] * pb_xz[j] * fx[j] + 2.0 * pa_xxy[j] * fx[j] * pb_xyz[j] + pa_xyy[j] * fx[j] * pb_yyz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xyyz[j] + 0.5 * fx[j] * pa_yy[j] * pb_xyyz[j] + 

                                 pa_xxyy[j] * pb_xyyz[j]) * s_0_0[j] + (7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 fz[j] * fga[j] * fx[j] * fx[j] * pb_xz[j] - pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 6.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 24.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 

                                 0.5 * fx[j] * pa_yy[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * pb_xz[j] * fx[j] - 

                                 2.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xyz[j] - pa_xxyy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xz[j] + 

                                 12.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyz[j] + 7.0 * pa_xxyy[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 28.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xyz[j] + 14.0 * pa_xyy[j] * fx[j] * fz[j] * pb_yyz[j] - fx[j] * fz[j] * fga[j] * pb_xyyz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xyyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xyyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxyy_xyzz[j] = (0.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 

                                 0.5 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 0.5 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_xy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xzz[j] + 0.5 * pa_xxyy[j] * pb_xy[j] * fx[j] + pa_xxy[j] * fx[j] * pb_xzz[j] + 

                                 pa_xyy[j] * fx[j] * pb_yzz[j] + 0.25 * fx[j] * fx[j] * pb_xyzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xyzz[j] + 

                                 0.5 * fx[j] * pa_yy[j] * pb_xyzz[j] + pa_xxyy[j] * pb_xyzz[j]) * s_0_0[j] + (-pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 5.0 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 0.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 2.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 6.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 6.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 12.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 0.5 * fx[j] * pa_yy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * pb_xy[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xzz[j] - pa_xxyy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xy[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xzz[j] + 

                                 7.0 * pa_xxyy[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xzz[j] + 

                                 14.0 * pa_xyy[j] * fx[j] * fz[j] * pb_yzz[j] - fx[j] * fz[j] * fga[j] * pb_xyzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_xyzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xyzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxyy_xzzz[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_xz[j] + 1.5 * pa_xxyy[j] * pb_xz[j] * fx[j] + pa_xyy[j] * fx[j] * pb_zzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xzzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xzzz[j] + 0.5 * fx[j] * pa_yy[j] * pb_xzzz[j] + 

                                 pa_xxyy[j] * pb_xzzz[j]) * s_0_0[j] + (-1.5 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * pa_xyy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 18.0 * pa_xyy[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 1.5 * fx[j] * pa_yy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_xz[j] * fx[j] - 

                                 3.0 * pa_xxyy[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xz[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_xz[j] * fx[j] + 14.0 * pa_xyy[j] * fx[j] * fz[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_xzzz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xzzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_xzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xzzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (11) = (55,60)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_xx, pa_xxy, pa_xxyy, pa_y, pa_yy, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xxyy_yyyy, t_xxyy_yyyz, t_xxyy_yyzz, t_xxyy_yzzz, t_xxyy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyy_yyyy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 3.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xxyy[j] * fx[j] * fx[j] + 6.0 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 1.5 * fx[j] * fx[j] * pa_yy[j] * pb_yy[j] + 

                                 2.0 * fx[j] * fx[j] * pa_y[j] * pb_yyy[j] + 3.0 * pa_xxyy[j] * pb_yy[j] * fx[j] + 4.0 * pa_xxy[j] * fx[j] * pb_yyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyyy[j] + 0.5 * pa_xx[j] * fx[j] * pb_yyyy[j] + 0.5 * fx[j] * pa_yy[j] * pb_yyyy[j] + 

                                 pa_xxyy[j] * pb_yyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 4.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] - 

                                 6.0 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 6.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - 6.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_yy[j] - 

                                 3.0 * pa_xxyy[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 30.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 9.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 54.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 1.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 3.0 * fx[j] * pa_yy[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_yy[j] * pb_yy[j] * fx[j] - 4.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yyy[j] - 

                                 6.0 * pa_xxyy[j] * pb_yy[j] * fz[j] * fgb[j] + 18.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yy[j] + 

                                 24.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyy[j] + 42.0 * pa_xxyy[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 56.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yyy[j] - fx[j] * fz[j] * fga[j] * pb_yyyy[j] - pa_xx[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] - fz[j] * fga[j] * pa_yy[j] * pb_yyyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyy[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_yyyy[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxyy_yyyz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_yz[j] + 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_yyz[j] + 1.5 * pa_xxyy[j] * pb_yz[j] * fx[j] + 3.0 * pa_xxy[j] * fx[j] * pb_yyz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_yyyz[j] + 0.5 * fx[j] * pa_yy[j] * pb_yyyz[j] + 

                                 pa_xxyy[j] * pb_yyyz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_yz[j] - 

                                 3.0 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 18.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_yy[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_yz[j] * fx[j] - 

                                 3.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yyz[j] - 3.0 * pa_xxyy[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yz[j] + 18.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyz[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_yz[j] * fx[j] + 42.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yyz[j] - fx[j] * fz[j] * fga[j] * pb_yyyz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_yyyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] - fz[j] * fga[j] * pa_yy[j] * pb_yyyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxyy_yyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 0.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_xxyy[j] * fx[j] * fx[j] + pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_yy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_zz[j] + fx[j] * fx[j] * pa_y[j] * pb_yzz[j] + 0.5 * pa_xxyy[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_xxyy[j] * fx[j] * pb_zz[j] + 2.0 * pa_xxy[j] * fx[j] * pb_yzz[j] + 0.25 * fx[j] * fx[j] * pb_yyzz[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_yyzz[j] + 0.5 * fx[j] * pa_yy[j] * pb_yyzz[j] + pa_xxyy[j] * pb_yyzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] - 

                                 fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.25 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_zz[j] - pa_xxyy[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 

                                 5.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.25 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 0.5 * fx[j] * pa_yy[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.5 * fz[j] * fga[j] * pa_yy[j] * pb_yy[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yy[j] * fx[j] * pb_zz[j] - 2.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yzz[j] - 

                                 pa_xxyy[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_zz[j] + 12.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yzz[j] + 

                                 7.0 * pa_xxyy[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xxyy[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yzz[j] - fx[j] * fz[j] * fga[j] * pb_yyzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_yyzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxyy_yzzz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 1.5 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_yz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_zzz[j] + 1.5 * pa_xxyy[j] * pb_yz[j] * fx[j] + pa_xxy[j] * fx[j] * pb_zzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yzzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_yzzz[j] + 0.5 * fx[j] * pa_yy[j] * pb_yzzz[j] + 

                                 pa_xxyy[j] * pb_yzzz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_y[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_xxy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 18.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_yy[j] * pb_yz[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yy[j] * pb_yz[j] * fx[j] - fz[j] * fga[j] * pa_y[j] * fx[j] * pb_zzz[j] - 

                                 3.0 * pa_xxyy[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yz[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_zzz[j] + 

                                 21.0 * pa_xxyy[j] * fz[j] * pb_yz[j] * fx[j] + 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_yzzz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_yzzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_yzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yzzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxyy_zzzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 0.75 * pa_xxyy[j] * fx[j] * fx[j] + 0.75 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 1.5 * fx[j] * fx[j] * pa_yy[j] * pb_zz[j] + 3.0 * pa_xxyy[j] * pb_zz[j] * fx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_zzzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_zzzz[j] + 0.5 * fx[j] * pa_yy[j] * pb_zzzz[j] + 

                                 pa_xxyy[j] * pb_zzzz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 1.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * fz[j] * fga[j] * pa_yy[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xxyy[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 9.0 * pa_xxyy[j] * fz[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 3.0 * fx[j] * pa_yy[j] * pb_zz[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 3.0 * fz[j] * fga[j] * pa_yy[j] * pb_zz[j] * fx[j] - 6.0 * pa_xxyy[j] * pb_zz[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 18.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_zz[j] + 

                                 42.0 * pa_xxyy[j] * fz[j] * pb_zz[j] * fx[j] - fx[j] * fz[j] * fga[j] * pb_zzzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] - fz[j] * fga[j] * pa_yy[j] * pb_zzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_zzzz[j] + 7.0 * fx[j] * pa_yy[j] * fz[j] * pb_zzzz[j] + 

                                 16.0 * pa_xxyy[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (12) = (60,65)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxyz, pa_xxz, pa_xy, pa_xyz, pa_xz, pa_y, \
                                     pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, \
                                     pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, \
                                     t_xxyz_xxxx, t_xxyz_xxxy, t_xxyz_xxxz, t_xxyz_xxyy, t_xxyz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyz_xxxx[j] = (1.875 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 0.75 * pa_xxyz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 4.5 * fx[j] * fx[j] * pa_yz[j] * pb_xx[j] + 3.0 * pa_xxyz[j] * pb_xx[j] * fx[j] + 

                                 4.0 * pa_xyz[j] * fx[j] * pb_xxx[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxxx[j] + pa_xxyz[j] * pb_xxxx[j]) * s_0_0[j] + (-4.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 18.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] - 0.75 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 72.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 54.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xx[j] - 3.0 * fx[j] * pa_yz[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_yz[j] * pb_xx[j] * fx[j] - 6.0 * pa_xxyz[j] * pb_xx[j] * fz[j] * fgb[j] + 

                                 42.0 * pa_xxyz[j] * fz[j] * pb_xx[j] * fx[j] + 56.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxx[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxxx[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxxx[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxyz_xxxy[j] = (0.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_yz[j] * pb_xy[j] + 0.25 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 1.5 * pa_xxyz[j] * pb_xy[j] * fx[j] + 

                                 0.5 * pa_xxz[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xyz[j] * fx[j] * pb_xxy[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxxy[j] + 

                                 pa_xxyz[j] * pb_xxxy[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] - 

                                 1.5 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 3.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 27.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xy[j] - 

                                 1.5 * fx[j] * pa_yz[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_xy[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xxx[j] - 3.0 * pa_xxyz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxx[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 7.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxy[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxxy[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxyz_xxxz[j] = (0.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_yz[j] * pb_xz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_xxx[j] + 1.5 * pa_xxyz[j] * pb_xz[j] * fx[j] + 

                                 0.5 * pa_xxy[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xyz[j] * fx[j] * pb_xxz[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxxz[j] + 

                                 pa_xxyz[j] * pb_xxxz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - 

                                 1.5 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 3.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 9.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 27.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xz[j] - 

                                 1.5 * fx[j] * pa_yz[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_xz[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxx[j] - 3.0 * pa_xxyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxx[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 7.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxx[j] + 42.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxxz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxyz_xxyy[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.25 * pa_xxyz[j] * fx[j] * fx[j] + 0.5 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 2.0 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_yy[j] + 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_xx[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 0.5 * pa_xxyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxyz[j] * fx[j] * pb_yy[j] + 

                                 pa_xxz[j] * fx[j] * pb_xxy[j] + 2.0 * pa_xyz[j] * fx[j] * pb_xyy[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxyy[j] + 

                                 pa_xxyz[j] * pb_xxyy[j]) * s_0_0[j] + (-fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] - 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 0.25 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] - pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 3.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 12.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 24.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yy[j] - 

                                 0.5 * fx[j] * pa_yz[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yz[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yz[j] * pb_xx[j] * fx[j] - 0.5 * fz[j] * fga[j] * pa_yz[j] * fx[j] * pb_yy[j] - 

                                 fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xxy[j] - pa_xxyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxyz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xx[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxy[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxyz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 14.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxy[j] + 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xyy[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxyy[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxyy[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxyz_xxyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.25 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_yz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_xxy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 0.5 * pa_xxyz[j] * fx[j] * pb_yz[j] + 0.5 * pa_xxy[j] * fx[j] * pb_xxy[j] + 

                                 0.5 * pa_xxz[j] * fx[j] * pb_xxz[j] + 2.0 * pa_xyz[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxyz[j] + 

                                 pa_xxyz[j] * pb_xxyz[j]) * s_0_0[j] + (1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.125 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 1.25 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 5.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] - 0.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.25 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] - 0.25 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xx[j] - 

                                 0.5 * pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.5 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 3.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 3.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 12.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 12.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yz[j] - 0.5 * fx[j] * pa_yz[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yz[j] * fx[j] * pb_yz[j] - 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxy[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xxz[j] - pa_xxyz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxz[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * fx[j] * pb_yz[j] + 7.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 7.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xxz[j] + 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xyz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxyz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (13) = (65,70)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxy, pa_xxyz, pa_xxz, pa_xy, pa_xyz, pa_xz, pa_y, \
                                     pa_yz, pa_z, pb_x, pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xxyz_xxzz, t_xxyz_xyyy, t_xxyz_xyyz, t_xxyz_xyzz, \
                                     t_xxyz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyz_xxzz[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 0.25 * pa_xxyz[j] * fx[j] * fx[j] + 0.5 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 2.0 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_zz[j] + 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_xx[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xxz[j] + 0.5 * pa_xxyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxyz[j] * fx[j] * pb_zz[j] + 

                                 pa_xxy[j] * fx[j] * pb_xxz[j] + 2.0 * pa_xyz[j] * fx[j] * pb_xzz[j] + 0.5 * fx[j] * pa_yz[j] * pb_xxzz[j] + 

                                 pa_xxyz[j] * pb_xxzz[j]) * s_0_0[j] + (-fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] - 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 3.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 12.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 24.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_zz[j] - 

                                 0.5 * fx[j] * pa_yz[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yz[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yz[j] * pb_xx[j] * fx[j] - 0.5 * fz[j] * fga[j] * pa_yz[j] * fx[j] * pb_zz[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xxz[j] - pa_xxyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xx[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxz[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxyz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xxz[j] + 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xzz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xxzz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxyz_xyyy[j] = (0.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_xy[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 1.5 * pa_xxyz[j] * pb_xy[j] * fx[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * pb_xyy[j] + pa_xyz[j] * fx[j] * pb_yyy[j] + 0.5 * fx[j] * pa_yz[j] * pb_xyyy[j] + 

                                 pa_xxyz[j] * pb_xyyy[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] - 1.5 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 

                                 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 1.5 * fx[j] * pa_yz[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_xy[j] * fx[j] - 1.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xyy[j] - 

                                 3.0 * pa_xxyz[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyy[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xyy[j] + 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yyy[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xyyy[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxyz_xyyz[j] = (0.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.5 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.5 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_xz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_y[j] * pb_xyy[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_xxyz[j] * pb_xz[j] * fx[j] + 

                                 0.5 * pa_xxy[j] * fx[j] * pb_xyy[j] + pa_xxz[j] * fx[j] * pb_xyz[j] + pa_xyz[j] * fx[j] * pb_yyz[j] + 

                                 0.5 * fx[j] * pa_yz[j] * pb_xyyz[j] + pa_xxyz[j] * pb_xyyz[j]) * s_0_0[j] + (-0.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 2.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 5.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.25 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 0.25 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xy[j] - 0.5 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 6.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 6.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 6.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 12.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 0.5 * fx[j] * pa_yz[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_yz[j] * pb_xz[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xyy[j] - fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xyz[j] - 

                                 pa_xxyz[j] * pb_xz[j] * fz[j] * fgb[j] + 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyy[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyz[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * pb_xz[j] * fx[j] + 7.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xyy[j] + 

                                 14.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xyz[j] + 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xyyz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxyz_xyzz[j] = (0.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.5 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_xy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xyz[j] + 0.25 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_xxyz[j] * pb_xy[j] * fx[j] + 

                                 pa_xxy[j] * fx[j] * pb_xyz[j] + 0.5 * pa_xxz[j] * fx[j] * pb_xzz[j] + pa_xyz[j] * fx[j] * pb_yzz[j] + 

                                 0.5 * fx[j] * pa_yz[j] * pb_xyzz[j] + pa_xxyz[j] * pb_xyzz[j]) * s_0_0[j] + (-0.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 2.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 5.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 0.25 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xz[j] - 0.5 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 6.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 6.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 12.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 6.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 0.5 * fx[j] * pa_yz[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_yz[j] * pb_xy[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xyz[j] - 0.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_xzz[j] - 

                                 pa_xxyz[j] * pb_xy[j] * fz[j] * fgb[j] + 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xy[j] + 

                                 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xzz[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xyz[j] + 

                                 7.0 * pa_xxz[j] * fx[j] * fz[j] * pb_xzz[j] + 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xyzz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxyz_xzzz[j] = (0.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_xzz[j] + 1.5 * pa_xxyz[j] * pb_xz[j] * fx[j] + 

                                 1.5 * pa_xxy[j] * fx[j] * pb_xzz[j] + pa_xyz[j] * fx[j] * pb_zzz[j] + 0.5 * fx[j] * pa_yz[j] * pb_xzzz[j] + 

                                 pa_xxyz[j] * pb_xzzz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.75 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_x[j] - 1.5 * pa_xxy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 

                                 9.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 1.5 * fx[j] * pa_yz[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_xz[j] * fx[j] - 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_xzz[j] - 

                                 3.0 * pa_xxyz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xzz[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_xxy[j] * fz[j] * fx[j] * pb_xzz[j] + 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_xzzz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (14) = (70,75)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_xx, pa_xxy, pa_xxyz, pa_xxz, pa_y, pa_yz, pa_z, pb_y, pb_yy, \
                                     pb_yyy, pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, \
                                     pb_zzzz, r_0_0, s_0_0, t_xxyz_yyyy, t_xxyz_yyyz, t_xxyz_yyzz, t_xxyz_yzzz, \
                                     t_xxyz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxyz_yyyy[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.75 * pa_xxyz[j] * fx[j] * fx[j] + 3.0 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_yy[j] + fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 3.0 * pa_xxyz[j] * pb_yy[j] * fx[j] + 

                                 2.0 * pa_xxz[j] * fx[j] * pb_yyy[j] + 0.5 * fx[j] * pa_yz[j] * pb_yyyy[j] + pa_xxyz[j] * pb_yyyy[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] - 

                                 3.0 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 

                                 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] - 3.0 * pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 9.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 3.0 * fx[j] * pa_yz[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_yz[j] * pb_yy[j] * fx[j] - 2.0 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_yyy[j] - 

                                 6.0 * pa_xxyz[j] * pb_yy[j] * fz[j] * fgb[j] + 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yy[j] + 

                                 12.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyy[j] + 42.0 * pa_xxyz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 28.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yyy[j] - fz[j] * fga[j] * pa_yz[j] * pb_yyyy[j] + 

                                 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_yyyy[j] + 16.0 * pa_xxyz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxyz_yyyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_yz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_yyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 1.5 * pa_xxyz[j] * pb_yz[j] * fx[j] + 0.5 * pa_xxy[j] * fx[j] * pb_yyy[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * pb_yyz[j] + 0.5 * fx[j] * pa_yz[j] * pb_yyyz[j] + pa_xxyz[j] * pb_yyyz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 0.75 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.75 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pb_yy[j] - 1.5 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 1.5 * fx[j] * pa_yz[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_yz[j] * fx[j] - 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yyy[j] - 

                                 1.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_yyz[j] - 3.0 * pa_xxyz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yz[j] + 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyz[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 7.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yyy[j] + 21.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_yyyz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxyz_yyzz[j] = (0.125 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_xxyz[j] * fx[j] * fx[j] + 0.5 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.5 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_yy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yz[j] * pb_zz[j] + 0.5 * fx[j] * fx[j] * pa_y[j] * pb_yyz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_xxyz[j] * pb_yy[j] * fx[j] + 0.5 * pa_xxyz[j] * fx[j] * pb_zz[j] + 

                                 pa_xxy[j] * fx[j] * pb_yyz[j] + pa_xxz[j] * fx[j] * pb_yzz[j] + 0.5 * fx[j] * pa_yz[j] * pb_yyzz[j] + 

                                 pa_xxyz[j] * pb_yyzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 0.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.25 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 0.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_yz[j] - pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 pa_xxy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 2.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 5.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 

                                 3.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 6.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 12.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 0.5 * fx[j] * pa_yz[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yz[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_yz[j] * pb_yy[j] * fx[j] - 0.5 * fz[j] * fga[j] * pa_yz[j] * fx[j] * pb_zz[j] - 

                                 fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yyz[j] - fz[j] * fga[j] * fx[j] * pa_z[j] * pb_yzz[j] - 

                                 pa_xxyz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yy[j] + 3.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_zz[j] + 

                                 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyz[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yzz[j] + 

                                 7.0 * pa_xxyz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xxyz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 14.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yyz[j] + 14.0 * pa_xxz[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_yyzz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxyz_yzzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xxy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yz[j] * pb_yz[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yzz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_xxyz[j] * pb_yz[j] * fx[j] + 1.5 * pa_xxy[j] * fx[j] * pb_yzz[j] + 

                                 0.5 * pa_xxz[j] * fx[j] * pb_zzz[j] + 0.5 * fx[j] * pa_yz[j] * pb_yzzz[j] + pa_xxyz[j] * pb_yzzz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 0.75 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 0.75 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_y[j] - 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fz[j] * fga[j] * fx[j] * fx[j] * pb_zz[j] - 1.5 * pa_xxy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xxz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 9.0 * pa_xxz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 1.5 * fx[j] * pa_yz[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_yz[j] * pb_yz[j] * fx[j] - 1.5 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_yzz[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * pa_z[j] * pb_zzz[j] - 3.0 * pa_xxyz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yz[j] + 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_zzz[j] + 21.0 * pa_xxyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 21.0 * pa_xxy[j] * fz[j] * fx[j] * pb_yzz[j] + 7.0 * pa_xxz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 fz[j] * fga[j] * pa_yz[j] * pb_yzzz[j] + 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xxyz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxyz_zzzz[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 0.75 * pa_xxyz[j] * fx[j] * fx[j] + 3.0 * pa_xxy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_zz[j] + fx[j] * fx[j] * pa_y[j] * pb_zzz[j] + 3.0 * pa_xxyz[j] * pb_zz[j] * fx[j] + 

                                 2.0 * pa_xxy[j] * fx[j] * pb_zzz[j] + 0.5 * fx[j] * pa_yz[j] * pb_zzzz[j] + pa_xxyz[j] * pb_zzzz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] - 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_yz[j] * fx[j] * fx[j] - 

                                 3.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_xxyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_xxy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 9.0 * pa_xxyz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xxy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * fx[j] * pa_yz[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_yz[j] * pb_zz[j] * fx[j] - 2.0 * fz[j] * fga[j] * pa_y[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_xxyz[j] * pb_zz[j] * fz[j] * fgb[j] + 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_zz[j] + 

                                 12.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_zzz[j] + 42.0 * pa_xxyz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 28.0 * pa_xxy[j] * fz[j] * fx[j] * pb_zzz[j] - fz[j] * fga[j] * pa_yz[j] * pb_zzzz[j] + 

                                 7.0 * fx[j] * pa_yz[j] * fz[j] * pb_zzzz[j] + 16.0 * pa_xxyz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (15) = (75,80)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxz, pa_xxzz, pa_xz, pa_xzz, pa_z, pa_zz, pb_x, \
                                     pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, \
                                     pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xxzz_xxxx, \
                                     t_xxzz_xxxy, t_xxzz_xxxz, t_xxzz_xxyy, t_xxzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxzz_xxxx[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xxzz[j] * fx[j] * fx[j] + 6.0 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 4.5 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.0 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xxzz[j] * pb_xx[j] * fx[j] + 4.0 * pa_xzz[j] * fx[j] * pb_xxx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxx[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxxx[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxx[j] + 

                                 pa_xxzz[j] * pb_xxxx[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 4.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 6.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xxzz[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 12.0 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 30.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 9.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 54.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] - 

                                 1.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 4.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 3.0 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 

                                 6.0 * pa_xxzz[j] * pb_xx[j] * fz[j] * fgb[j] + 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 24.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xxzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 56.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxx[j] - fx[j] * fz[j] * fga[j] * pb_xxxx[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxx[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxx[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxx[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xxzz_xxxy[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * pa_xxzz[j] * pb_xy[j] * fx[j] + 3.0 * pa_xzz[j] * fx[j] * pb_xxy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxy[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxxy[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxy[j] + 

                                 pa_xxzz[j] * pb_xxxy[j]) * s_0_0[j] + (-1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 3.0 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] - 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 1.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 3.0 * pa_xxzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_xy[j] * fx[j] + 42.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxy[j] - fx[j] * fz[j] * fga[j] * pb_xxxy[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxxy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xxzz_xxxz[j] = (1.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 3.0 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 1.5 * pa_xxzz[j] * pb_xz[j] * fx[j] + 

                                 pa_xxz[j] * fx[j] * pb_xxx[j] + 3.0 * pa_xzz[j] * fx[j] * pb_xxz[j] + 0.25 * fx[j] * fx[j] * pb_xxxz[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_xxxz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxz[j] + pa_xxzz[j] * pb_xxxz[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - 3.0 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 18.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 36.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] - 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 1.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxx[j] - 

                                 3.0 * pa_xxzz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_xz[j] * fx[j] + 14.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xxx[j] + 

                                 42.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxz[j] - fx[j] * fz[j] * fga[j] * pb_xxxz[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxxz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxxz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xxzz_xxyy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.125 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_xxzz[j] * fx[j] * fx[j] + pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 0.5 * pa_xxzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xxzz[j] * fx[j] * pb_yy[j] + 

                                 2.0 * pa_xzz[j] * fx[j] * pb_xyy[j] + 0.25 * fx[j] * fx[j] * pb_xxyy[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxyy[j] + 

                                 0.5 * fx[j] * pa_zz[j] * pb_xxyy[j] + pa_xxzz[j] * pb_xxyy[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 pa_xxzz[j] * fx[j] * fz[j] * fgb[j] + 1.25 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 2.0 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 5.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 3.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] + 

                                 12.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.5 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_yy[j] - pa_xxzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] + 

                                 7.0 * pa_xxzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxzz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 28.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xyy[j] - fx[j] * fz[j] * fga[j] * pb_xxyy[j] - pa_xx[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxyy[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xxzz_xxyz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.5 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.0 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 

                                 0.5 * pa_xxzz[j] * fx[j] * pb_yz[j] + pa_xxz[j] * fx[j] * pb_xxy[j] + 2.0 * pa_xzz[j] * fx[j] * pb_xyz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxyz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxyz[j] + 

                                 pa_xxzz[j] * pb_xxyz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] - 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 6.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 24.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_yz[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxy[j] - pa_xxzz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxy[j] + 7.0 * pa_xxzz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 14.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xxy[j] + 28.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xyz[j] - fx[j] * fz[j] * fga[j] * pb_xxyz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (16) = (80,85)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xx, pa_xxz, pa_xxzz, pa_xz, pa_xzz, pa_z, pa_zz, pb_x, \
                                     pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, \
                                     pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, \
                                     s_0_0, t_xxzz_xxzz, t_xxzz_xyyy, t_xxzz_xyyz, t_xxzz_xyzz, t_xxzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxzz_xxzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.25 * pa_xxzz[j] * fx[j] * fx[j] + pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 4.0 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 0.5 * pa_xxzz[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xxzz[j] * fx[j] * pb_zz[j] + 2.0 * pa_xxz[j] * fx[j] * pb_xxz[j] + 2.0 * pa_xzz[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xxzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxzz[j] + 

                                 pa_xxzz[j] * pb_xxzz[j]) * s_0_0[j] + (4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 15.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] - 

                                 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_xx[j] - pa_xxzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 2.0 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 12.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 48.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 0.5 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_zz[j] - 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxz[j] - 

                                 pa_xxzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xxzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] + 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxz[j] + 

                                 7.0 * pa_xxzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xxzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xxz[j] + 28.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xzz[j] - fx[j] * fz[j] * fga[j] * pb_xxzz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xxzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xxzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xxzz_xyyy[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 1.5 * pa_xxzz[j] * pb_xy[j] * fx[j] + pa_xzz[j] * fx[j] * pb_yyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyyy[j] + 0.5 * pa_xx[j] * fx[j] * pb_xyyy[j] + 0.5 * fx[j] * pa_zz[j] * pb_xyyy[j] + 

                                 pa_xxzz[j] * pb_xyyy[j]) * s_0_0[j] + (-1.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 18.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 1.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_xxzz[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yyy[j] - fx[j] * fz[j] * fga[j] * pb_xyyy[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xyyy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xxzz_xyyz[j] = (0.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.5 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 0.5 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 0.5 * pa_xxzz[j] * pb_xz[j] * fx[j] + pa_xxz[j] * fx[j] * pb_xyy[j] + 

                                 pa_xzz[j] * fx[j] * pb_yyz[j] + 0.25 * fx[j] * fx[j] * pb_xyyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xyyz[j] + 

                                 0.5 * fx[j] * pa_zz[j] * pb_xyyz[j] + pa_xxzz[j] * pb_xyyz[j]) * s_0_0[j] + (-pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 5.0 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 0.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 2.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 6.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 6.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 12.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 0.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xyy[j] - pa_xxzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyy[j] + 

                                 7.0 * pa_xxzz[j] * fz[j] * pb_xz[j] * fx[j] + 14.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xyy[j] + 

                                 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yyz[j] - fx[j] * fz[j] * fga[j] * pb_xyyz[j] - pa_xx[j] * fz[j] * fga[j] * pb_xyyz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xxzz_xyzz[j] = (0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.5 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 2.0 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 

                                 0.5 * pa_xxzz[j] * pb_xy[j] * fx[j] + 2.0 * pa_xxz[j] * fx[j] * pb_xyz[j] + pa_xzz[j] * fx[j] * pb_yzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_xyzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xyzz[j] + 

                                 pa_xxzz[j] * pb_xyzz[j]) * s_0_0[j] + (7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 fz[j] * fga[j] * fx[j] * fx[j] * pb_xy[j] - pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 6.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 24.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 

                                 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xyz[j] - pa_xxzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] + 

                                 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyz[j] + 7.0 * pa_xxzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xyz[j] + 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yzz[j] - fx[j] * fz[j] * fga[j] * pb_xyzz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_xyzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xyzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xxzz_xzzz[j] = (1.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 3.0 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 1.5 * pa_xxzz[j] * pb_xz[j] * fx[j] + 

                                 3.0 * pa_xxz[j] * fx[j] * pb_xzz[j] + pa_xzz[j] * fx[j] * pb_zzz[j] + 0.25 * fx[j] * fx[j] * pb_xzzz[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_xzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xzzz[j] + pa_xxzz[j] * pb_xzzz[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - 

                                 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xz[j] - 3.0 * pa_xxz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 36.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 1.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - 3.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xzz[j] - 

                                 3.0 * pa_xxzz[j] * pb_xz[j] * fz[j] * fgb[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] + 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xzz[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_xz[j] * fx[j] + 42.0 * pa_xxz[j] * fz[j] * fx[j] * pb_xzz[j] + 

                                 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_xzzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_xzzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_xzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (17) = (85,90)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_xx, pa_xxz, pa_xxzz, pa_z, pa_zz, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xxzz_yyyy, t_xxzz_yyyz, t_xxzz_yyzz, t_xxzz_yzzz, t_xxzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xxzz_yyyy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 0.75 * pa_xxzz[j] * fx[j] * fx[j] + 0.75 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 3.0 * pa_xxzz[j] * pb_yy[j] * fx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyyy[j] + 0.5 * pa_xx[j] * fx[j] * pb_yyyy[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyyy[j] + 

                                 pa_xxzz[j] * pb_yyyy[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 1.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xxzz[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_xx[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 9.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 3.0 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 3.0 * fx[j] * pa_zz[j] * pb_yy[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_yy[j] * fx[j] - 6.0 * pa_xxzz[j] * pb_yy[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] + 

                                 42.0 * pa_xxzz[j] * fz[j] * pb_yy[j] * fx[j] - fx[j] * fz[j] * fga[j] * pb_yyyy[j] - pa_xx[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyyy[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyyy[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xxzz_yyyz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 1.5 * pa_xxzz[j] * pb_yz[j] * fx[j] + pa_xxz[j] * fx[j] * pb_yyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyyz[j] + 0.5 * pa_xx[j] * fx[j] * pb_yyyz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyyz[j] + 

                                 pa_xxzz[j] * pb_yyyz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - 3.0 * pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 18.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_zz[j] * pb_yz[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_yz[j] * fx[j] - fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yyy[j] - 

                                 3.0 * pa_xxzz[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyy[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_yz[j] * fx[j] + 14.0 * pa_xxz[j] * fz[j] * fx[j] * pb_yyy[j] - fx[j] * fz[j] * fga[j] * pb_yyyz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_yyyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyyz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xxzz_yyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 0.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_xxzz[j] * fx[j] * fx[j] + pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xx[j] * fx[j] * fx[j] * pb_yy[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.25 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 0.5 * pa_xxzz[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_xxzz[j] * fx[j] * pb_zz[j] + 2.0 * pa_xxz[j] * fx[j] * pb_yyz[j] + 0.25 * fx[j] * fx[j] * pb_yyzz[j] + 

                                 0.5 * pa_xx[j] * fx[j] * pb_yyzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyzz[j] + pa_xxzz[j] * pb_yyzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.25 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] - 

                                 fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_yy[j] - pa_xxzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xxz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 

                                 5.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 3.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.25 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 0.5 * pa_xx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * pa_xx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xx[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 0.5 * pa_xx[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_yy[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_zz[j] - 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yyz[j] - 

                                 pa_xxzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xxzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xx[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] + 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_xxzz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xxzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xxz[j] * fz[j] * fx[j] * pb_yyz[j] - fx[j] * fz[j] * fga[j] * pb_yyzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yyzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xxzz_yzzz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_xxz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xx[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 1.5 * pa_xxzz[j] * pb_yz[j] * fx[j] + 3.0 * pa_xxz[j] * fx[j] * pb_yzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yzzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_yzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yzzz[j] + 

                                 pa_xxzz[j] * pb_yzzz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_yz[j] - 

                                 3.0 * pa_xxz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 18.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 27.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xx[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_zz[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_yz[j] * fx[j] - 

                                 3.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yzz[j] - 3.0 * pa_xxzz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] + 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yzz[j] + 

                                 21.0 * pa_xxzz[j] * fz[j] * pb_yz[j] * fx[j] + 42.0 * pa_xxz[j] * fz[j] * fx[j] * pb_yzz[j] - fx[j] * fz[j] * fga[j] * pb_yzzz[j] - 

                                 pa_xx[j] * fz[j] * fga[j] * pb_yzzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_yzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xxzz_zzzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * pa_xx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 3.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xxzz[j] * fx[j] * fx[j] + 6.0 * pa_xxz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 4.5 * pa_xx[j] * fx[j] * fx[j] * pb_zz[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 

                                 2.0 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 3.0 * pa_xxzz[j] * pb_zz[j] * fx[j] + 4.0 * pa_xxz[j] * fx[j] * pb_zzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_zzzz[j] + 0.5 * pa_xx[j] * fx[j] * pb_zzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_zzzz[j] + 

                                 pa_xxzz[j] * pb_zzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 4.5 * pa_xx[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * pa_xx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_xx[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] - 

                                 6.0 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 6.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - 6.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_xxzz[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_xxz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 30.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 9.0 * pa_xxzz[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_xxz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 54.0 * pa_xx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 3.0 * pa_xx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xx[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 3.0 * fx[j] * pa_zz[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_zz[j] * fx[j] - 4.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_xxzz[j] * pb_zz[j] * fz[j] * fgb[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] + 

                                 24.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_zzz[j] + 42.0 * pa_xxzz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 56.0 * pa_xxz[j] * fz[j] * fx[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_zzzz[j] - pa_xx[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_zzzz[j] + 

                                 7.0 * pa_xx[j] * fz[j] * fx[j] * pb_zzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_zzzz[j] + 

                                 16.0 * pa_xxzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (18) = (90,95)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyy, pa_y, pa_yy, pa_yyy, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xyyy_xxxx, t_xyyy_xxxy, \
                                     t_xyyy_xxxz, t_xyyy_xxyy, t_xyyy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyy_xxxx[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_xyyy[j] * fx[j] * fx[j] + 3.0 * fx[j] * fx[j] * pa_yyy[j] * pb_x[j] + 

                                 4.5 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * fx[j] * fx[j] * pa_y[j] * pb_xxx[j] + 3.0 * pa_xyyy[j] * pb_xx[j] * fx[j] + 

                                 2.0 * fx[j] * pa_yyy[j] * pb_xxx[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxxx[j] + pa_xyyy[j] * pb_xxxx[j]) * s_0_0[j] + (-4.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * pa_xyyy[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] - 6.0 * fx[j] * pa_yyy[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 45.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 9.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_x[j] - 9.0 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 6.0 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 6.0 * pa_xyyy[j] * pb_xx[j] * fz[j] * fgb[j] + 54.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xyyy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 28.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xxx[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_xyyy[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xyyy_xxxy[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 2.25 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyy[j] * pb_y[j] + 2.25 * fx[j] * fx[j] * pa_yy[j] * pb_xx[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_xxy[j] + 1.5 * pa_xyyy[j] * pb_xy[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * fx[j] * pa_yyy[j] * pb_xxy[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxxy[j] + pa_xyyy[j] * pb_xxxy[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_y[j] - 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 4.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_yyy[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 27.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_y[j] + 

                                 27.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xx[j] - 4.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 4.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxy[j] - 3.0 * pa_xyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 27.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxy[j] + 21.0 * pa_xyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxx[j] + 21.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xxy[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxy[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xyyy_xxxz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyy[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_xxz[j] + 1.5 * pa_xyyy[j] * pb_xz[j] * fx[j] + 1.5 * fx[j] * pa_yyy[j] * pb_xxz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xxxz[j] + pa_xyyy[j] * pb_xxxz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 1.5 * fx[j] * pa_yyy[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 9.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 4.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxz[j] - 3.0 * pa_xyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 27.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxz[j] + 

                                 21.0 * pa_xyyy[j] * fz[j] * pb_xz[j] * fx[j] + 21.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xyyy_xxyy[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xyyy[j] * fx[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 0.5 * fx[j] * fx[j] * pa_yyy[j] * pb_x[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yy[j] * pb_xy[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xyy[j] + 0.5 * pa_xyyy[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xyyy[j] * fx[j] * pb_yy[j] + 3.0 * pa_xyy[j] * fx[j] * pb_xxy[j] + fx[j] * pa_yyy[j] * pb_xyy[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xxyy[j] + pa_xyyy[j] * pb_xxyy[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] - 

                                 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 pa_xyyy[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - fx[j] * pa_yyy[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_x[j] + 36.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xy[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 3.0 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 pa_xyyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyyy[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 18.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyy[j] + 7.0 * pa_xyyy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xyyy[j] * fz[j] * fx[j] * pb_yy[j] + 42.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 14.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xyy[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxyy[j] + 16.0 * pa_xyyy[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xyyy_xxyz[j] = (0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * fx[j] * fx[j] * pa_yy[j] * pb_xz[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xyz[j] + 0.5 * pa_xyyy[j] * fx[j] * pb_yz[j] + 

                                 1.5 * pa_xyy[j] * fx[j] * pb_xxz[j] + fx[j] * pa_yyy[j] * pb_xyz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxyz[j] + 

                                 pa_xyyy[j] * pb_xxyz[j]) * s_0_0[j] + (-0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 1.5 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 18.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xz[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 

                                 3.0 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xyz[j] - pa_xyyy[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 18.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyz[j] + 7.0 * pa_xyyy[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxz[j] + 14.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxyz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (19) = (95,100)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyy, pa_y, pa_yy, pa_yyy, pb_x, pb_xx, \
                                     pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, \
                                     pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, s_0_0, t_xyyy_xxzz, \
                                     t_xyyy_xyyy, t_xyyy_xyyz, t_xyyy_xyzz, t_xyyy_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyy_xxzz[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.25 * pa_xyyy[j] * fx[j] * fx[j] + 0.5 * fx[j] * fx[j] * pa_yyy[j] * pb_x[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * pb_xzz[j] + 0.5 * pa_xyyy[j] * pb_xx[j] * fx[j] + 0.5 * pa_xyyy[j] * fx[j] * pb_zz[j] + 

                                 fx[j] * pa_yyy[j] * pb_xzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xxzz[j] + pa_xyyy[j] * pb_xxzz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - pa_xyyy[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] - fx[j] * pa_yyy[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 3.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_x[j] - 1.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 3.0 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 pa_xyyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 18.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xzz[j] + 7.0 * pa_xyyy[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xyyy[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * fx[j] * pa_yyy[j] * fz[j] * pb_xzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xxzz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxzz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xyyy_xyyy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.875 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 3.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 2.25 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 6.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyy[j] * pb_y[j] + 2.25 * fx[j] * fx[j] * pa_yy[j] * pb_yy[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yyy[j] + 1.5 * pa_xyyy[j] * pb_xy[j] * fx[j] + 

                                 4.5 * pa_xyy[j] * fx[j] * pb_xyy[j] + 0.5 * fx[j] * pa_yyy[j] * pb_yyy[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyyy[j] + 

                                 pa_xyyy[j] * pb_xyyy[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 18.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 33.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 4.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * pa_yyy[j] * pb_y[j] * fz[j] * fgb[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 27.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 81.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_y[j] + 27.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yy[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 4.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yyy[j] - 

                                 3.0 * pa_xyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyy[j] + 21.0 * pa_xyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 63.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xyy[j] + 7.0 * fx[j] * pa_yyy[j] * fz[j] * pb_yyy[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyyy[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xyyy_xyyz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yyy[j] * pb_z[j] + 1.5 * fx[j] * fx[j] * pa_yy[j] * pb_yz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yyz[j] + 0.5 * pa_xyyy[j] * pb_xz[j] * fx[j] + 

                                 3.0 * pa_xyy[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_yyy[j] * pb_yyz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyyz[j] + 

                                 pa_xyyy[j] * pb_xyyz[j]) * s_0_0[j] + (11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 0.5 * fx[j] * pa_yyy[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_z[j] + 18.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yyz[j] - 

                                 pa_xyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyz[j] + 7.0 * pa_xyyy[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 42.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xyz[j] + 7.0 * fx[j] * pa_yyy[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyyz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xyyy_xyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yyy[j] * pb_y[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_zz[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_yzz[j] + 0.5 * pa_xyyy[j] * pb_xy[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * pb_xzz[j] + 

                                 0.5 * fx[j] * pa_yyy[j] * pb_yzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_xyzz[j] + pa_xyyy[j] * pb_xyzz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 1.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 0.5 * fx[j] * pa_yyy[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 3.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_y[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_zz[j] - 1.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yzz[j] - pa_xyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yzz[j] + 7.0 * pa_xyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xzz[j] + 7.0 * fx[j] * pa_yyy[j] * fz[j] * pb_yzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyzz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xyyy_xzzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyy[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_zzz[j] + 1.5 * pa_xyyy[j] * pb_xz[j] * fx[j] + 0.5 * fx[j] * pa_yyy[j] * pb_zzz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_xzzz[j] + pa_xyyy[j] * pb_xzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_y[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 1.5 * fx[j] * pa_yyy[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 9.0 * fx[j] * fx[j] * pa_yyy[j] * fz[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_zzz[j] - 3.0 * pa_xyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_zzz[j] + 

                                 21.0 * pa_xyyy[j] * fz[j] * pb_xz[j] * fx[j] + 7.0 * fx[j] * pa_yyy[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_xzzz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (20) = (100,105)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyy, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xyyy_yyyy, t_xyyy_yyyz, t_xyyy_yyzz, t_xyyy_yzzz, t_xyyy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyy_yyyy[j] = (5.625 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xyyy[j] * fx[j] * fx[j] + 9.0 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 13.5 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 3.0 * pa_xyyy[j] * pb_yy[j] * fx[j] + 

                                 6.0 * pa_xyy[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xy[j] * fx[j] * pb_yyyy[j] + pa_xyyy[j] * pb_yyyy[j]) * s_0_0[j] + (-13.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * pa_xyyy[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 9.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 162.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 9.0 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 6.0 * pa_xyyy[j] * pb_yy[j] * fz[j] * fgb[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 42.0 * pa_xyyy[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 84.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yyy[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_xyyy[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xyyy_yyyz[j] = (1.875 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 6.75 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xyyy[j] * pb_yz[j] * fx[j] + 4.5 * pa_xyy[j] * fx[j] * pb_yyz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_yyyz[j] + pa_xyyy[j] * pb_yyyz[j]) * s_0_0[j] + (18.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 4.5 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 27.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 81.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 4.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 4.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 

                                 3.0 * pa_xyyy[j] * pb_yz[j] * fz[j] * fgb[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 21.0 * pa_xyyy[j] * fz[j] * pb_yz[j] * fx[j] + 63.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yyz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyyz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xyyy_yyzz[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * pa_xyyy[j] * fx[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xyyy[j] * pb_yy[j] * fx[j] + 0.5 * pa_xyyy[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_xyy[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xy[j] * fx[j] * pb_yyzz[j] + pa_xyyy[j] * pb_yyzz[j]) * s_0_0[j] + (-3.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 pa_xyyy[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 3.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - pa_xyyy[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xyyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 7.0 * pa_xyyy[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xyyy[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yzz[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyzz[j] + 16.0 * pa_xyyy[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xyyy_yzzz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xyyy[j] * pb_yz[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * pb_zzz[j] + 

                                 1.5 * pa_xy[j] * fx[j] * pb_yzzz[j] + pa_xyyy[j] * pb_yzzz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 4.5 * pa_xyy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 27.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 4.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 3.0 * pa_xyyy[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 

                                 21.0 * pa_xyyy[j] * fz[j] * pb_yz[j] * fx[j] + 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_zzz[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_yzzz[j] + 

                                 16.0 * pa_xyyy[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xyyy_zzzz[j] = (1.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xyyy[j] * fx[j] * fx[j] + 

                                 4.5 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_xyyy[j] * pb_zz[j] * fx[j] + 1.5 * pa_xy[j] * fx[j] * pb_zzzz[j] + 

                                 pa_xyyy[j] * pb_zzzz[j]) * s_0_0[j] + (-4.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_xyyy[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] + 9.0 * pa_xyyy[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_xy[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 9.0 * pa_xy[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 6.0 * pa_xyyy[j] * pb_zz[j] * fz[j] * fgb[j] + 54.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_xyyy[j] * fz[j] * pb_zz[j] * fx[j] - 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_xy[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_xyyy[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (21) = (105,110)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyz, pa_xyz, pa_xz, pa_y, pa_yy, pa_yyz, \
                                     pa_yz, pa_z, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, \
                                     pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, \
                                     t_xyyz_xxxx, t_xyyz_xxxy, t_xyyz_xxxz, t_xyyz_xxyy, t_xyyz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyz_xxxx[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_xyyz[j] * fx[j] * fx[j] + 3.0 * fx[j] * fx[j] * pa_yyz[j] * pb_x[j] + 

                                 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 3.0 * pa_xyyz[j] * pb_xx[j] * fx[j] + 

                                 2.0 * fx[j] * pa_yyz[j] * pb_xxx[j] + 0.5 * pa_xz[j] * fx[j] * pb_xxxx[j] + pa_xyyz[j] * pb_xxxx[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 3.0 * pa_xyyz[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 6.0 * fx[j] * pa_yyz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 9.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_x[j] - 3.0 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 2.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxx[j] - 

                                 6.0 * pa_xyyz[j] * pb_xx[j] * fz[j] * fgb[j] + 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 12.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxx[j] + 42.0 * pa_xyyz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 28.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xxx[j] - pa_xz[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxx[j] + 16.0 * pa_xyyz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xyyz_xxxy[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyz[j] * pb_y[j] + 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_xx[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 1.5 * pa_xyyz[j] * pb_xy[j] * fx[j] + 

                                 pa_xyz[j] * fx[j] * pb_xxx[j] + 1.5 * fx[j] * pa_yyz[j] * pb_xxy[j] + 0.5 * pa_xz[j] * fx[j] * pb_xxxy[j] + 

                                 pa_xyyz[j] * pb_xxxy[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 3.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * pa_yyz[j] * fz[j] * fgb[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 

                                 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_y[j] + 

                                 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xx[j] - 1.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxy[j] - 

                                 3.0 * pa_xyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxy[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxx[j] + 21.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xxy[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xxxy[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xyyz_xxxz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyz[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_xx[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 1.5 * pa_xyyz[j] * pb_xz[j] * fx[j] + 0.5 * pa_xyy[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * fx[j] * pa_yyz[j] * pb_xxz[j] + 0.5 * pa_xz[j] * fx[j] * pb_xxxz[j] + pa_xyyz[j] * pb_xxxz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_yyz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_z[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xx[j] - 1.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxx[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxz[j] - 3.0 * pa_xyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxz[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 7.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxx[j] + 21.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xxz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xxxz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xyyz_xxyy[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.25 * pa_xyyz[j] * fx[j] * fx[j] + pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 0.5 * fx[j] * fx[j] * pa_yyz[j] * pb_x[j] + 

                                 2.0 * fx[j] * fx[j] * pa_yz[j] * pb_xy[j] + 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 0.5 * pa_xyyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xyyz[j] * fx[j] * pb_yy[j] + 

                                 2.0 * pa_xyz[j] * fx[j] * pb_xxy[j] + fx[j] * pa_yyz[j] * pb_xyy[j] + 0.5 * pa_xz[j] * fx[j] * pb_xxyy[j] + 

                                 pa_xyyz[j] * pb_xxyy[j]) * s_0_0[j] + (-pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] - 

                                 0.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - pa_xyyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - fx[j] * pa_yyz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 6.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_x[j] + 

                                 24.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xy[j] - 0.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 0.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 0.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyy[j] - 

                                 pa_xyyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyyz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyy[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xyyz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxy[j] + 14.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xyy[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xxyy[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxyy[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xyyz_xxyz[j] = (0.25 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 0.5 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.5 * fx[j] * fx[j] * pa_yy[j] * pb_xy[j] + fx[j] * fx[j] * pa_yz[j] * pb_xz[j] + 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_xyyz[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_xyy[j] * fx[j] * pb_xxy[j] + pa_xyz[j] * fx[j] * pb_xxz[j] + fx[j] * pa_yyz[j] * pb_xyz[j] + 

                                 0.5 * pa_xz[j] * fx[j] * pb_xxyz[j] + pa_xyyz[j] * pb_xxyz[j]) * s_0_0[j] + (-0.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 2.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 5.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] - 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 0.5 * pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 6.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 6.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xy[j] + 12.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xz[j] - 

                                 0.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxy[j] - fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyz[j] - 

                                 pa_xyyz[j] * fz[j] * fgb[j] * pb_yz[j] + 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyz[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * fx[j] * pb_yz[j] + 7.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xxz[j] + 14.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xyz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xxyz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (22) = (110,115)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyz, pa_xyz, pa_xz, pa_y, pa_yy, pa_yyz, \
                                     pa_yz, pa_z, pb_x, pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xyyz_xxzz, t_xyyz_xyyy, t_xyyz_xyyz, t_xyyz_xyzz, \
                                     t_xyyz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyz_xxzz[j] = (0.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xyyz[j] * fx[j] * fx[j] + 0.5 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.5 * fx[j] * fx[j] * pa_yyz[j] * pb_x[j] + fx[j] * fx[j] * pa_yy[j] * pb_xz[j] + 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_xyyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xyyz[j] * fx[j] * pb_zz[j] + 

                                 pa_xyy[j] * fx[j] * pb_xxz[j] + fx[j] * pa_yyz[j] * pb_xzz[j] + 0.5 * pa_xz[j] * fx[j] * pb_xxzz[j] + 

                                 pa_xyyz[j] * pb_xxzz[j]) * s_0_0[j] + (-0.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 0.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - pa_xyyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 2.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - fx[j] * pa_yyz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 5.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 3.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_x[j] + 12.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_xz[j] - 

                                 0.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 0.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xxz[j] - fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xzz[j] - 

                                 pa_xyyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 6.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xzz[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xyyz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 14.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xxz[j] + 14.0 * fx[j] * pa_yyz[j] * fz[j] * pb_xzz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xxzz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xyyz_xyyy[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * fx[j] * fx[j] * pa_yyz[j] * pb_y[j] + 

                                 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_yy[j] + 0.25 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 1.5 * pa_xyyz[j] * pb_xy[j] * fx[j] + 

                                 3.0 * pa_xyz[j] * fx[j] * pb_xyy[j] + 0.5 * fx[j] * pa_yyz[j] * pb_yyy[j] + 0.5 * pa_xz[j] * fx[j] * pb_xyyy[j] + 

                                 pa_xyyz[j] * pb_xyyy[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fx[j] * pa_yyz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_y[j] + 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yy[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 0.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyy[j] - 3.0 * pa_xyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyy[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 42.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xyy[j] + 7.0 * fx[j] * pa_yyz[j] * fz[j] * pb_yyy[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xyyy[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xyyz_xyyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.125 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * fx[j] * fx[j] * pa_yyz[j] * pb_z[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yy[j] * pb_yy[j] + fx[j] * fx[j] * pa_yz[j] * pb_yz[j] + 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 0.5 * pa_xyyz[j] * pb_xz[j] * fx[j] + 0.5 * pa_xyy[j] * fx[j] * pb_xyy[j] + 

                                 2.0 * pa_xyz[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_yyz[j] * pb_yyz[j] + 0.5 * pa_xz[j] * fx[j] * pb_xyyz[j] + 

                                 pa_xyyz[j] * pb_xyyz[j]) * s_0_0[j] + (1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 0.25 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] + 5.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] - 0.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.25 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 0.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 0.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 0.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yyz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 3.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 12.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_z[j] + 3.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yy[j] + 

                                 12.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yz[j] - 0.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyy[j] - 

                                 0.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyz[j] - pa_xyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyz[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * pb_xz[j] * fx[j] + 7.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xyy[j] + 

                                 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xyz[j] + 7.0 * fx[j] * pa_yyz[j] * fz[j] * pb_yyz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xyyz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xyyz_xyzz[j] = (0.25 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 0.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yyz[j] * pb_y[j] + 0.5 * fx[j] * fx[j] * pa_yy[j] * pb_yz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_yz[j] * pb_zz[j] + 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.25 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_xyyz[j] * pb_xy[j] * fx[j] + 

                                 pa_xyy[j] * fx[j] * pb_xyz[j] + pa_xyz[j] * fx[j] * pb_xzz[j] + 0.5 * fx[j] * pa_yyz[j] * pb_yzz[j] + 

                                 0.5 * pa_xz[j] * fx[j] * pb_xyzz[j] + pa_xyyz[j] * pb_xyzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 5.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] - 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * pa_yyz[j] * pb_y[j] * fz[j] * fgb[j] + 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 6.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 12.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_y[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_yz[j] + 6.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_zz[j] - 

                                 0.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xyz[j] - 0.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yzz[j] - 

                                 pa_xyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yzz[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xyz[j] + 

                                 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_xzz[j] + 7.0 * fx[j] * pa_yyz[j] * fz[j] * pb_yzz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xyzz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xyyz_xzzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_yy[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yyz[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * pa_yy[j] * pb_zz[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_xyyz[j] * pb_xz[j] * fx[j] + 1.5 * pa_xyy[j] * fx[j] * pb_xzz[j] + 

                                 0.5 * fx[j] * pa_yyz[j] * pb_zzz[j] + 0.5 * pa_xz[j] * fx[j] * pb_xzzz[j] + pa_xyyz[j] * pb_xzzz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_yy[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_yy[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 1.5 * pa_xyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_yyz[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yyz[j] * fz[j] * pb_z[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yy[j] * fz[j] * pb_zz[j] - 1.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_xzz[j] - 

                                 0.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_zzz[j] - 3.0 * pa_xyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_zzz[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_xzz[j] + 7.0 * fx[j] * pa_yyz[j] * fz[j] * pb_zzz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_xzzz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (23) = (115,120)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyy, pa_xyyz, pa_xyz, pa_xz, pb_y, pb_yy, pb_yyy, \
                                     pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, \
                                     r_0_0, s_0_0, t_xyyz_yyyy, t_xyyz_yyyz, t_xyyz_yyzz, t_xyyz_yzzz, t_xyyz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyyz_yyyy[j] = (1.875 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xyyz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 4.5 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * pa_xyyz[j] * pb_yy[j] * fx[j] + 

                                 4.0 * pa_xyz[j] * fx[j] * pb_yyy[j] + 0.5 * pa_xz[j] * fx[j] * pb_yyyy[j] + pa_xyyz[j] * pb_yyyy[j]) * s_0_0[j] + (-4.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 18.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xyyz[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 72.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 54.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 3.0 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 6.0 * pa_xyyz[j] * pb_yy[j] * fz[j] * fgb[j] + 

                                 42.0 * pa_xyyz[j] * fz[j] * pb_yy[j] * fx[j] + 56.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yyy[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_yyyy[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyyy[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xyyz_yyyz[j] = (0.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xyyz[j] * pb_yz[j] * fx[j] + 

                                 0.5 * pa_xyy[j] * fx[j] * pb_yyy[j] + 3.0 * pa_xyz[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xz[j] * fx[j] * pb_yyyz[j] + 

                                 pa_xyyz[j] * pb_yyyz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 1.5 * pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 3.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyy[j] - 3.0 * pa_xyyz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 7.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yyy[j] + 42.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_yyyz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xyyz_yyzz[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * pa_xyyz[j] * fx[j] * fx[j] + 0.5 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 2.0 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xyyz[j] * pb_yy[j] * fx[j] + 0.5 * pa_xyyz[j] * fx[j] * pb_zz[j] + 

                                 pa_xyy[j] * fx[j] * pb_yyz[j] + 2.0 * pa_xyz[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xz[j] * fx[j] * pb_yyzz[j] + 

                                 pa_xyyz[j] * pb_yyzz[j]) * s_0_0[j] + (-pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 0.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - pa_xyyz[j] * fx[j] * fz[j] * fgb[j] - pa_xyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 3.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 12.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 24.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 0.5 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 0.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yyz[j] - pa_xyyz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xyyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_xyyz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xyyz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 14.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yyz[j] + 28.0 * pa_xyz[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_yyzz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xyyz_yzzz[j] = (0.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xyyz[j] * pb_yz[j] * fx[j] + 

                                 1.5 * pa_xyy[j] * fx[j] * pb_yzz[j] + pa_xyz[j] * fx[j] * pb_zzz[j] + 0.5 * pa_xz[j] * fx[j] * pb_yzzz[j] + 

                                 pa_xyyz[j] * pb_yzzz[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 1.5 * pa_xyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 9.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 18.0 * pa_xyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 1.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 1.5 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_yzz[j] - 

                                 3.0 * pa_xyyz[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 21.0 * pa_xyyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 21.0 * pa_xyy[j] * fz[j] * fx[j] * pb_yzz[j] + 14.0 * pa_xyz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 pa_xz[j] * fz[j] * fga[j] * pb_yzzz[j] + 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_xyyz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xyyz_zzzz[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xyyz[j] * fx[j] * fx[j] + 3.0 * pa_xyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_xyyz[j] * pb_zz[j] * fx[j] + 

                                 2.0 * pa_xyy[j] * fx[j] * pb_zzz[j] + 0.5 * pa_xz[j] * fx[j] * pb_zzzz[j] + pa_xyyz[j] * pb_zzzz[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 3.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_xyyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_xyy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 3.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 9.0 * pa_xyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_xz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 2.0 * pa_x[j] * fz[j] * fga[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_xyyz[j] * pb_zz[j] * fz[j] * fgb[j] + 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_xyyz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 28.0 * pa_xyy[j] * fz[j] * fx[j] * pb_zzz[j] - pa_xz[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 7.0 * pa_xz[j] * fx[j] * fz[j] * pb_zzzz[j] + 16.0 * pa_xyyz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (24) = (120,125)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyz, pa_xyzz, pa_xz, pa_xzz, pa_y, pa_yz, pa_yzz, \
                                     pa_z, pa_zz, pb_x, pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, \
                                     pb_xxyz, pb_xxz, pb_xy, pb_xyy, pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, \
                                     t_xyzz_xxxx, t_xyzz_xxxy, t_xyzz_xxxz, t_xyzz_xxyy, t_xyzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyzz_xxxx[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.75 * pa_xyzz[j] * fx[j] * fx[j] + 3.0 * fx[j] * fx[j] * pa_yzz[j] * pb_x[j] + 

                                 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + fx[j] * fx[j] * pa_y[j] * pb_xxx[j] + 3.0 * pa_xyzz[j] * pb_xx[j] * fx[j] + 

                                 2.0 * fx[j] * pa_yzz[j] * pb_xxx[j] + 0.5 * pa_xy[j] * fx[j] * pb_xxxx[j] + pa_xyzz[j] * pb_xxxx[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * pa_xyzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] - 6.0 * fx[j] * pa_yzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 9.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_x[j] - 3.0 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 2.0 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 6.0 * pa_xyzz[j] * pb_xx[j] * fz[j] * fgb[j] + 18.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 12.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xyzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 28.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xxx[j] - pa_xy[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_xyzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xyzz_xxxy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yzz[j] * pb_y[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_xxy[j] + 1.5 * pa_xyzz[j] * pb_xy[j] * fx[j] + 0.5 * pa_xzz[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * fx[j] * pa_yzz[j] * pb_xxy[j] + 0.5 * pa_xy[j] * fx[j] * pb_xxxy[j] + pa_xyzz[j] * pb_xxxy[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_y[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_yzz[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_y[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] - 1.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 0.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxy[j] - 3.0 * pa_xyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxy[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 7.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxx[j] + 21.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xxy[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xxxy[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxy[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xyzz_xxxz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yzz[j] * pb_z[j] + 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_xx[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_y[j] * pb_xxz[j] + 1.5 * pa_xyzz[j] * pb_xz[j] * fx[j] + 

                                 pa_xyz[j] * fx[j] * pb_xxx[j] + 1.5 * fx[j] * pa_yzz[j] * pb_xxz[j] + 0.5 * pa_xy[j] * fx[j] * pb_xxxz[j] + 

                                 pa_xyzz[j] * pb_xxxz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * pa_yzz[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_z[j] + 

                                 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xx[j] - 1.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xxz[j] - 

                                 3.0 * pa_xyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xxz[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 14.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xxx[j] + 21.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xxz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xxxz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxxz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xyzz_xxyy[j] = (0.125 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_xyzz[j] * fx[j] * fx[j] + 0.5 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.5 * fx[j] * fx[j] * pa_yzz[j] * pb_x[j] + fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 0.5 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xyy[j] + 0.5 * pa_xyzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xyzz[j] * fx[j] * pb_yy[j] + 

                                 pa_xzz[j] * fx[j] * pb_xxy[j] + fx[j] * pa_yzz[j] * pb_xyy[j] + 0.5 * pa_xy[j] * fx[j] * pb_xxyy[j] + 

                                 pa_xyzz[j] * pb_xxyy[j]) * s_0_0[j] + (-0.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 0.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - pa_xyzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.25 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] - pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 2.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - fx[j] * pa_yzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] + 5.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 3.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_x[j] + 12.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] - 

                                 0.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 0.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 pa_xyzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyy[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xyzz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxy[j] + 14.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xyy[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xxyy[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxyy[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xyzz_xxyz[j] = (0.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.25 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 0.5 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + fx[j] * fx[j] * pa_yz[j] * pb_xy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xyz[j] + 0.5 * pa_xyzz[j] * fx[j] * pb_yz[j] + 

                                 pa_xyz[j] * fx[j] * pb_xxy[j] + 0.5 * pa_xzz[j] * fx[j] * pb_xxz[j] + fx[j] * pa_yzz[j] * pb_xyz[j] + 

                                 0.5 * pa_xy[j] * fx[j] * pb_xxyz[j] + pa_xyzz[j] * pb_xxyz[j]) * s_0_0[j] + (-0.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 2.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 5.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] - 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.5 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 6.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 3.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 6.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 12.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xy[j] + 6.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] - 

                                 0.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 0.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 pa_xyzz[j] * fz[j] * fgb[j] * pb_yz[j] + 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xyz[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * fx[j] * pb_yz[j] + 14.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 7.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xxz[j] + 14.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xyz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xxyz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxyz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (25) = (125,130)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyz, pa_xyzz, pa_xz, pa_xzz, pa_y, pa_yz, pa_yzz, \
                                     pa_z, pa_zz, pb_x, pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, \
                                     pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, \
                                     pb_zzz, r_0_0, s_0_0, t_xyzz_xxzz, t_xyzz_xyyy, t_xyzz_xyyz, t_xyzz_xyzz, \
                                     t_xyzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyzz_xxzz[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_x[j] + 0.25 * pa_xyzz[j] * fx[j] * fx[j] + pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xx[j] + 0.5 * fx[j] * fx[j] * pa_yzz[j] * pb_x[j] + 

                                 2.0 * fx[j] * fx[j] * pa_yz[j] * pb_xz[j] + 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * pb_xzz[j] + 0.5 * pa_xyzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xyzz[j] * fx[j] * pb_zz[j] + 

                                 2.0 * pa_xyz[j] * fx[j] * pb_xxz[j] + fx[j] * pa_yzz[j] * pb_xzz[j] + 0.5 * pa_xy[j] * fx[j] * pb_xxzz[j] + 

                                 pa_xyzz[j] * pb_xxzz[j]) * s_0_0[j] + (-pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_x[j] - 

                                 0.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * fx[j] * fx[j] * pa_y[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_x[j] - pa_xyzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - fx[j] * pa_yzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 6.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_x[j] + 

                                 24.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_xz[j] - 0.5 * pa_xy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * pa_xy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 0.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - fx[j] * pa_y[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 pa_xyzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xyzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 6.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_xzz[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_xyzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xxz[j] + 14.0 * fx[j] * pa_yzz[j] * fz[j] * pb_xzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xxzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xxzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xyzz_xyyy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_yzz[j] * pb_y[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_y[j] * pb_yyy[j] + 1.5 * pa_xyzz[j] * pb_xy[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * pb_xyy[j] + 

                                 0.5 * fx[j] * pa_yzz[j] * pb_yyy[j] + 0.5 * pa_xy[j] * fx[j] * pb_xyyy[j] + pa_xyzz[j] * pb_xyyy[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 1.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_yzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_y[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] - 1.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 0.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yyy[j] - 3.0 * pa_xyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyy[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 21.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xyy[j] + 7.0 * fx[j] * pa_yzz[j] * fz[j] * pb_yyy[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xyyy[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyyy[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xyzz_xyyz[j] = (0.25 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 0.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 

                                 0.25 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_yzz[j] * pb_z[j] + 0.5 * fx[j] * fx[j] * pa_yz[j] * pb_yy[j] + 

                                 0.5 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_yyz[j] + 0.5 * pa_xyzz[j] * pb_xz[j] * fx[j] + 

                                 pa_xyz[j] * fx[j] * pb_xyy[j] + pa_xzz[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_yzz[j] * pb_yyz[j] + 

                                 0.5 * pa_xy[j] * fx[j] * pb_xyyz[j] + pa_xyzz[j] * pb_xyyz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 5.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] - 

                                 0.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * pa_yzz[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 6.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 12.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_z[j] + 

                                 6.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yy[j] + 6.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] - 

                                 0.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 0.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yyz[j] - 

                                 pa_xyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * pb_xz[j] * fx[j] + 14.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xyy[j] + 

                                 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xyz[j] + 7.0 * fx[j] * pa_yzz[j] * fz[j] * pb_yyz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xyyz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyyz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xyzz_xyzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_y[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 0.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.25 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * fx[j] * fx[j] * pa_yzz[j] * pb_y[j] + 

                                 fx[j] * fx[j] * pa_yz[j] * pb_yz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_yzz[j] + 0.5 * pa_xyzz[j] * pb_xy[j] * fx[j] + 

                                 2.0 * pa_xyz[j] * fx[j] * pb_xyz[j] + 0.5 * pa_xzz[j] * fx[j] * pb_xzz[j] + 0.5 * fx[j] * pa_yzz[j] * pb_yzz[j] + 

                                 0.5 * pa_xy[j] * fx[j] * pb_xyzz[j] + pa_xyzz[j] * pb_xyzz[j]) * s_0_0[j] + (1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_y[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 

                                 5.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] - 0.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 0.25 * fx[j] * fx[j] * pa_y[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.25 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_y[j] - 0.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 0.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_yzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 3.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 12.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_y[j] + 12.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_yz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] - 0.5 * pa_xy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 0.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 0.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_yzz[j] - pa_xyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_yzz[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * pb_xy[j] * fx[j] + 28.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xyz[j] + 

                                 7.0 * pa_xzz[j] * fx[j] * fz[j] * pb_xzz[j] + 7.0 * fx[j] * pa_yzz[j] * fz[j] * pb_yzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xyzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xyzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xyzz_xzzz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_yz[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pa_y[j] * pb_z[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_yzz[j] * pb_z[j] + 

                                 1.5 * fx[j] * fx[j] * pa_yz[j] * pb_zz[j] + 0.25 * fx[j] * fx[j] * pa_y[j] * pb_zzz[j] + 1.5 * pa_xyzz[j] * pb_xz[j] * fx[j] + 

                                 3.0 * pa_xyz[j] * fx[j] * pb_xzz[j] + 0.5 * fx[j] * pa_yzz[j] * pb_zzz[j] + 0.5 * pa_xy[j] * fx[j] * pb_xzzz[j] + 

                                 pa_xyzz[j] * pb_xzzz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_yz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_yz[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * pa_y[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_z[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 1.5 * fx[j] * pa_yzz[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_yzz[j] * fz[j] * pb_z[j] + 18.0 * fx[j] * fx[j] * pa_yz[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 0.5 * fx[j] * pa_y[j] * fz[j] * fga[j] * pb_zzz[j] - 3.0 * pa_xyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.0 * fx[j] * fx[j] * pa_y[j] * fz[j] * pb_zzz[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 42.0 * pa_xyz[j] * fz[j] * fx[j] * pb_xzz[j] + 7.0 * fx[j] * pa_yzz[j] * fz[j] * pb_zzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_xzzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_xzzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (26) = (130,135)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xy, pa_xyz, pa_xyzz, pa_xz, pa_xzz, pb_y, pb_yy, pb_yyy, \
                                     pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, \
                                     r_0_0, s_0_0, t_xyzz_yyyy, t_xyzz_yyyz, t_xyzz_yyzz, t_xyzz_yzzz, t_xyzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xyzz_yyyy[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.75 * pa_xyzz[j] * fx[j] * fx[j] + 3.0 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 3.0 * pa_xyzz[j] * pb_yy[j] * fx[j] + 

                                 2.0 * pa_xzz[j] * fx[j] * pb_yyy[j] + 0.5 * pa_xy[j] * fx[j] * pb_yyyy[j] + pa_xyzz[j] * pb_yyyy[j]) * s_0_0[j] + (-1.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * pa_xyzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fz[j] * fx[j] * fx[j] * fx[j] - 6.0 * pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 9.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 3.0 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 2.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 

                                 6.0 * pa_xyzz[j] * pb_yy[j] * fz[j] * fgb[j] + 18.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 12.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 42.0 * pa_xyzz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 28.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yyy[j] - pa_xy[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_xyzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xyzz_yyyz[j] = (0.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xyzz[j] * pb_yz[j] * fx[j] + 

                                 pa_xyz[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xzz[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xy[j] * fx[j] * pb_yyyz[j] + 

                                 pa_xyzz[j] * pb_yyyz[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 9.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 1.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 

                                 3.0 * pa_xyzz[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 14.0 * pa_xyz[j] * fz[j] * fx[j] * pb_yyy[j] + 21.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_yyyz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyyz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xyzz_yyzz[j] = (0.375 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.25 * pa_xyzz[j] * fx[j] * fx[j] + pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_xy[j] * fx[j] * fx[j] * pb_yy[j] + 0.5 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.0 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xyzz[j] * pb_yy[j] * fx[j] + 0.5 * pa_xyzz[j] * fx[j] * pb_zz[j] + 

                                 2.0 * pa_xyz[j] * fx[j] * pb_yyz[j] + pa_xzz[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xy[j] * fx[j] * pb_yyzz[j] + 

                                 pa_xyzz[j] * pb_yyzz[j]) * s_0_0[j] + (-pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 0.25 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - pa_xyzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_xyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 6.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 24.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 0.5 * pa_xy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_xy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * pa_xy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 0.5 * pa_xy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 

                                 pa_xyzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xyzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_xy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 6.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 7.0 * pa_xyzz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xyzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_xyz[j] * fz[j] * fx[j] * pb_yyz[j] + 14.0 * pa_xzz[j] * fx[j] * fz[j] * pb_yzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_yyzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_yyzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xyzz_yzzz[j] = (0.75 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 1.5 * pa_xyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xy[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xyzz[j] * pb_yz[j] * fx[j] + 

                                 3.0 * pa_xyz[j] * fx[j] * pb_yzz[j] + 0.5 * pa_xzz[j] * fx[j] * pb_zzz[j] + 0.5 * pa_xy[j] * fx[j] * pb_yzzz[j] + 

                                 pa_xyzz[j] * pb_yzzz[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 3.0 * pa_xyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 1.5 * pa_xzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 

                                 9.0 * pa_xzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 18.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_xy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_xy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 0.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 3.0 * pa_xyzz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 21.0 * pa_xyzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 42.0 * pa_xyz[j] * fz[j] * fx[j] * pb_yzz[j] + 7.0 * pa_xzz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_yzzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_yzzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xyzz_zzzz[j] = (1.875 * pa_xy[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xyzz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_xyz[j] * fx[j] * fx[j] * pb_z[j] + 4.5 * pa_xy[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_xyzz[j] * pb_zz[j] * fx[j] + 

                                 4.0 * pa_xyz[j] * fx[j] * pb_zzz[j] + 0.5 * pa_xy[j] * fx[j] * pb_zzzz[j] + pa_xyzz[j] * pb_zzzz[j]) * s_0_0[j] + (-4.5 * pa_xy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 18.75 * pa_xy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 3.0 * pa_xyzz[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_xyz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xyzz[j] * fz[j] * fx[j] * fx[j] + 72.0 * pa_xyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 54.0 * pa_xy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 3.0 * pa_xy[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_xy[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 6.0 * pa_xyzz[j] * pb_zz[j] * fz[j] * fgb[j] + 

                                 42.0 * pa_xyzz[j] * fz[j] * pb_zz[j] * fx[j] + 56.0 * pa_xyz[j] * fz[j] * fx[j] * pb_zzz[j] - 

                                 pa_xy[j] * fz[j] * fga[j] * pb_zzzz[j] + 7.0 * pa_xy[j] * fz[j] * fx[j] * pb_zzzz[j] + 

                                 16.0 * pa_xyzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (27) = (135,140)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_xzz, pa_xzzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xyy, \
                                     pb_xyz, pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_xzzz_xxxx, t_xzzz_xxxy, \
                                     t_xzzz_xxxz, t_xzzz_xxyy, t_xzzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xzzz_xxxx[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_xzzz[j] * fx[j] * fx[j] + 3.0 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 

                                 4.5 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 3.0 * pa_xzzz[j] * pb_xx[j] * fx[j] + 

                                 2.0 * fx[j] * pa_zzz[j] * pb_xxx[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxxx[j] + pa_xzzz[j] * pb_xxxx[j]) * s_0_0[j] + (-4.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * pa_xzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fz[j] * fx[j] * fx[j] * fx[j] - 6.0 * fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 45.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 9.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] - 9.0 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 6.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 6.0 * pa_xzzz[j] * pb_xx[j] * fz[j] * fgb[j] + 54.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxx[j] + 42.0 * pa_xzzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 28.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxx[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_xzzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_xzzz_xxxy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 1.5 * pa_xzzz[j] * pb_xy[j] * fx[j] + 1.5 * fx[j] * pa_zzz[j] * pb_xxy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xxxy[j] + pa_xzzz[j] * pb_xxxy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - 1.5 * fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 4.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxy[j] - 3.0 * pa_xzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 27.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxy[j] + 

                                 21.0 * pa_xzzz[j] * fz[j] * pb_xy[j] * fx[j] + 21.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxxy[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_xzzz_xxxz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 2.25 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 1.5 * pa_xzzz[j] * pb_xz[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * fx[j] * pa_zzz[j] * pb_xxz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxxz[j] + pa_xzzz[j] * pb_xxxz[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 4.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 1.5 * fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 27.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] - 4.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 

                                 4.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxz[j] - 3.0 * pa_xzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 27.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxz[j] + 21.0 * pa_xzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xxx[j] + 21.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxxz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_xzzz_xxyy[j] = (0.375 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.25 * pa_xzzz[j] * fx[j] * fx[j] + 0.5 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 0.5 * pa_xzzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_xzzz[j] * fx[j] * pb_yy[j] + 

                                 fx[j] * pa_zzz[j] * pb_xyy[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxyy[j] + pa_xzzz[j] * pb_xxyy[j]) * s_0_0[j] + (-1.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - pa_xzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_xz[j] * fz[j] * fx[j] * fx[j] * fx[j] - fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 3.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] - 1.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 pa_xzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xzzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyy[j] + 7.0 * pa_xzzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xzzz[j] * fz[j] * fx[j] * pb_yy[j] + 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xyy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxyy[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxyy[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_xzzz_xxyz[j] = (0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xxy[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_xzzz[j] * fx[j] * pb_yz[j] + 

                                 1.5 * pa_xzz[j] * fx[j] * pb_xxy[j] + fx[j] * pa_zzz[j] * pb_xyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xxyz[j] + 

                                 pa_xzzz[j] * pb_xxyz[j]) * s_0_0[j] + (-0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 1.5 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 

                                 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xyz[j] - pa_xzzz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyz[j] + 7.0 * pa_xzzz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 21.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xxy[j] + 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxyz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (28) = (140,145)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_xzz, pa_xzzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, \
                                     pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, \
                                     pb_xzzz, pb_y, pb_yy, pb_yyy, pb_yyz, pb_yz, pb_yzz, pb_z, pb_zz, pb_zzz, r_0_0, s_0_0, \
                                     t_xzzz_xxzz, t_xzzz_xyyy, t_xzzz_xyyz, t_xzzz_xyzz, t_xzzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xzzz_xxzz[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.25 * pa_xzzz[j] * fx[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xx[j] + 0.5 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xxz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_xzzz[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_xzzz[j] * fx[j] * pb_zz[j] + 3.0 * pa_xzz[j] * fx[j] * pb_xxz[j] + fx[j] * pa_zzz[j] * pb_xzz[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xxzz[j] + pa_xzzz[j] * pb_xxzz[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] - 

                                 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 pa_xzzz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 3.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] + 36.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 pa_xzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_xzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xzz[j] + 7.0 * pa_xzzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_xzzz[j] * fz[j] * fx[j] * pb_zz[j] + 42.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xxz[j] + 

                                 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xzz[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xxzz[j] + 16.0 * pa_xzzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_xzzz_xyyy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 1.5 * pa_xzzz[j] * pb_xy[j] * fx[j] + 0.5 * fx[j] * pa_zzz[j] * pb_yyy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_xyyy[j] + pa_xzzz[j] * pb_xyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - 1.5 * fx[j] * pa_zzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yyy[j] - 3.0 * pa_xzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyy[j] + 

                                 21.0 * pa_xzzz[j] * fz[j] * pb_xy[j] * fx[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yyy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xyyy[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_xzzz_xyyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 

                                 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_x[j] * fx[j] * fx[j] * pb_xyy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 0.5 * pa_xzzz[j] * pb_xz[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * pb_xyy[j] + 

                                 0.5 * fx[j] * pa_zzz[j] * pb_yyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xyyz[j] + pa_xzzz[j] * pb_xyyz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 1.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 0.5 * fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 3.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] - 1.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yyz[j] - pa_xzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyz[j] + 7.0 * pa_xzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xyy[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xyyz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_xzzz_xyzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_xzzz[j] * pb_xy[j] * fx[j] + 

                                 3.0 * pa_xzz[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_zzz[j] * pb_yzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xyzz[j] + 

                                 pa_xzzz[j] * pb_xyzz[j]) * s_0_0[j] + (11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 0.5 * fx[j] * pa_zzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yzz[j] - 

                                 pa_xzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yzz[j] + 7.0 * pa_xzzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 42.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xyz[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xyzz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_xzzz_xzzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.875 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 3.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 2.25 * pa_xzz[j] * fx[j] * fx[j] * pb_x[j] + 6.75 * pa_xz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_xzz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_xzzz[j] * pb_xz[j] * fx[j] + 

                                 4.5 * pa_xzz[j] * fx[j] * pb_xzz[j] + 0.5 * fx[j] * pa_zzz[j] * pb_zzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_xzzz[j] + 

                                 pa_xzzz[j] * pb_xzzz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 18.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 33.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 4.5 * pa_xzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * pa_zzz[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 27.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 81.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 4.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_zzz[j] - 

                                 3.0 * pa_xzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_zzz[j] + 21.0 * pa_xzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 63.0 * pa_xzz[j] * fz[j] * fx[j] * pb_xzz[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_xzzz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (29) = (145,150)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_x, pa_xz, pa_xzz, pa_xzzz, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_xzzz_yyyy, t_xzzz_yyyz, t_xzzz_yyzz, t_xzzz_yzzz, t_xzzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_xzzz_yyyy[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_xzzz[j] * fx[j] * fx[j] + 

                                 4.5 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * pa_xzzz[j] * pb_yy[j] * fx[j] + 1.5 * pa_xz[j] * fx[j] * pb_yyyy[j] + 

                                 pa_xzzz[j] * pb_yyyy[j]) * s_0_0[j] + (-4.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_xzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fz[j] * fx[j] * fx[j] * fx[j] + 9.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 6.0 * pa_xzzz[j] * pb_yy[j] * fz[j] * fgb[j] + 54.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 42.0 * pa_xzzz[j] * fz[j] * pb_yy[j] * fx[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_xzzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_xzzz_yyyz[j] = (1.125 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_xzzz[j] * pb_yz[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * pb_yyy[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_yyyz[j] + pa_xzzz[j] * pb_yyyz[j]) * s_0_0[j] + (-2.25 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 4.5 * pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 27.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 4.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 3.0 * pa_xzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 

                                 21.0 * pa_xzzz[j] * fz[j] * pb_yz[j] * fx[j] + 21.0 * pa_xzz[j] * fz[j] * fx[j] * pb_yyy[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_yyyz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_xzzz_yyzz[j] = (1.125 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * pa_xzzz[j] * fx[j] * fx[j] + 1.5 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_xz[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * pa_xzzz[j] * pb_yy[j] * fx[j] + 0.5 * pa_xzzz[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_xzz[j] * fx[j] * pb_yyz[j] + 1.5 * pa_xz[j] * fx[j] * pb_yyzz[j] + pa_xzzz[j] * pb_yyzz[j]) * s_0_0[j] + (-3.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 1.5 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 pa_xzzz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_xzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 3.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 27.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 1.5 * pa_xz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_xz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_xz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_xz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - pa_xzzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_xzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_xz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 18.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_xzzz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_xzzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_xzz[j] * fz[j] * fx[j] * pb_yyz[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_yyzz[j] + 16.0 * pa_xzzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_xzzz_yzzz[j] = (1.875 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_xzz[j] * fx[j] * fx[j] * pb_y[j] + 6.75 * pa_xz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_yzz[j] + 1.5 * pa_xzzz[j] * pb_yz[j] * fx[j] + 4.5 * pa_xzz[j] * fx[j] * pb_yzz[j] + 

                                 1.5 * pa_xz[j] * fx[j] * pb_yzzz[j] + pa_xzzz[j] * pb_yzzz[j]) * s_0_0[j] + (18.75 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 2.25 * pa_x[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 4.5 * pa_xzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 27.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 81.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 4.5 * pa_xz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_xz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 4.5 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 

                                 3.0 * pa_xzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 27.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 21.0 * pa_xzzz[j] * fz[j] * pb_yz[j] * fx[j] + 63.0 * pa_xzz[j] * fz[j] * fx[j] * pb_yzz[j] - 

                                 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_yzzz[j] + 

                                 16.0 * pa_xzzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_xzzz_zzzz[j] = (5.625 * pa_xz[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * pa_x[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_xzzz[j] * fx[j] * fx[j] + 9.0 * pa_xzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 13.5 * pa_xz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_x[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_xzzz[j] * pb_zz[j] * fx[j] + 

                                 6.0 * pa_xzz[j] * fx[j] * pb_zzz[j] + 1.5 * pa_xz[j] * fx[j] * pb_zzzz[j] + pa_xzzz[j] * pb_zzzz[j]) * s_0_0[j] + (-13.5 * pa_xz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_xz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * pa_x[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 2.25 * pa_xz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * pa_x[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * pa_xzzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_xzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 9.0 * pa_xzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_xzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 162.0 * pa_xz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 9.0 * pa_xz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 9.0 * pa_xz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 6.0 * pa_x[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 6.0 * pa_xzzz[j] * pb_zz[j] * fz[j] * fgb[j] + 

                                 36.0 * pa_x[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_xzzz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 84.0 * pa_xzz[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * pa_xz[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_xz[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_xzzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (30) = (150,155)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyy, pb_x, pb_xx, pb_xxx, pb_xxxx, \
                                     pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, \
                                     pb_z, r_0_0, s_0_0, t_yyyy_xxxx, t_yyyy_xxxy, t_yyyy_xxxz, t_yyyy_xxyy, \
                                     t_yyyy_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyy_xxxx[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_yyyy[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 9.0 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 3.0 * pa_yyyy[j] * pb_xx[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xxxx[j] + 3.0 * pa_yy[j] * fx[j] * pb_xxxx[j] + 

                                 pa_yyyy[j] * pb_xxxx[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_yyyy[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 18.0 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 6.0 * pa_yyyy[j] * pb_xx[j] * fz[j] * fgb[j] + 108.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 42.0 * pa_yyyy[j] * fz[j] * pb_xx[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxx[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxxx[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_yyyy_xxxy[j] = (4.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 3.0 * pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_xxx[j] + 1.5 * pa_yyyy[j] * pb_xy[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * pb_xxx[j] + 0.75 * fx[j] * fx[j] * pb_xxxy[j] + 3.0 * pa_yy[j] * fx[j] * pb_xxxy[j] + 

                                 pa_yyyy[j] * pb_xxxy[j]) * s_0_0[j] + (-9.0 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 6.0 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 36.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 9.0 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 6.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 3.0 * pa_yyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 54.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 21.0 * pa_yyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxy[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxxy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxy[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_yyyy_xxxz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_yyyy[j] * pb_xz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xxxz[j] + 

                                 3.0 * pa_yy[j] * fx[j] * pb_xxxz[j] + pa_yyyy[j] * pb_xxxz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 9.0 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 3.0 * pa_yyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 54.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 21.0 * pa_yyyy[j] * fz[j] * pb_xz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxxz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_yyyy_xxyy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_yyyy[j] * fx[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * pb_xxy[j] + 0.5 * pa_yyyy[j] * pb_xx[j] * fx[j] + 0.5 * pa_yyyy[j] * fx[j] * pb_yy[j] + 

                                 4.0 * pa_yyy[j] * fx[j] * pb_xxy[j] + 0.75 * fx[j] * fx[j] * pb_xxyy[j] + 3.0 * pa_yy[j] * fx[j] * pb_xxyy[j] + 

                                 pa_yyyy[j] * pb_xxyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 

                                 pa_yyyy[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 30.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 3.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 54.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 3.0 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 12.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 pa_yyyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyyy[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 72.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 7.0 * pa_yyyy[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yyyy[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 56.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyy[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxyy[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_yyyy_xxyz[j] = (1.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * pa_yyyy[j] * fx[j] * pb_yz[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * pb_xxz[j] + 0.75 * fx[j] * fx[j] * pb_xxyz[j] + 3.0 * pa_yy[j] * fx[j] * pb_xxyz[j] + 

                                 pa_yyyy[j] * pb_xxyz[j]) * s_0_0[j] + (-3.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 3.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 2.0 * pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 15.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 12.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 3.0 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 6.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 pa_yyyy[j] * fz[j] * fgb[j] * pb_yz[j] + 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 7.0 * pa_yyyy[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 28.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxyz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (31) = (155,160)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyy, pb_x, pb_xx, pb_xxzz, pb_xy, pb_xyy, \
                                     pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_zz, r_0_0, s_0_0, \
                                     t_yyyy_xxzz, t_yyyy_xyyy, t_yyyy_xyyz, t_yyyy_xyzz, t_yyyy_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyy_xxzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_yyyy[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 0.5 * pa_yyyy[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_yyyy[j] * fx[j] * pb_zz[j] + 0.75 * fx[j] * fx[j] * pb_xxzz[j] + 3.0 * pa_yy[j] * fx[j] * pb_xxzz[j] + 

                                 pa_yyyy[j] * pb_xxzz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 3.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] + 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - pa_yyyy[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 3.0 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 pa_yyyy[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 7.0 * pa_yyyy[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yyyy[j] * fz[j] * fx[j] * pb_zz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_xxzz[j] - 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] + 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxzz[j] + 

                                 16.0 * pa_yyyy[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_yyyy_xyyy[j] = (7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 13.5 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * pb_xyy[j] + 1.5 * pa_yyyy[j] * pb_xy[j] * fx[j] + 

                                 6.0 * pa_yyy[j] * fx[j] * pb_xyy[j] + 0.75 * fx[j] * fx[j] * pb_xyyy[j] + 3.0 * pa_yy[j] * fx[j] * pb_xyyy[j] + 

                                 pa_yyyy[j] * pb_xyyy[j]) * s_0_0[j] + (75.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 6.0 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 36.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 162.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 18.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 3.0 * pa_yyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 21.0 * pa_yyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 84.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyy[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyyy[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_yyyy_xyyz[j] = (1.875 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 6.0 * pa_y[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * pa_yyyy[j] * pb_xz[j] * fx[j] + 

                                 4.0 * pa_yyy[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pb_xyyz[j] + 3.0 * pa_yy[j] * fx[j] * pb_xyyz[j] + 

                                 pa_yyyy[j] * pb_xyyz[j]) * s_0_0[j] + (-4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] + 

                                 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 54.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 12.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 pa_yyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 72.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 7.0 * pa_yyyy[j] * fz[j] * pb_xz[j] * fx[j] + 56.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xyz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyz[j] - 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xyyz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] + 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyyz[j] + 

                                 16.0 * pa_yyyy[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_yyyy_xyzz[j] = (1.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_xzz[j] + 0.5 * pa_yyyy[j] * pb_xy[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * pb_xzz[j] + 0.75 * fx[j] * fx[j] * pb_xyzz[j] + 3.0 * pa_yy[j] * fx[j] * pb_xyzz[j] + 

                                 pa_yyyy[j] * pb_xyzz[j]) * s_0_0[j] + (-3.0 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 2.0 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 12.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 3.0 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 6.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 pa_yyyy[j] * pb_xy[j] * fz[j] * fgb[j] + 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 7.0 * pa_yyyy[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyzz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xyzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyzz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_yyyy_xzzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_yyyy[j] * pb_xz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xzzz[j] + 

                                 3.0 * pa_yy[j] * fx[j] * pb_xzzz[j] + pa_yyyy[j] * pb_xzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 9.0 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 3.0 * pa_yyyy[j] * pb_xz[j] * fz[j] * fgb[j] + 54.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 21.0 * pa_yyyy[j] * fz[j] * pb_xz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xzzz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_xzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_xzzz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (32) = (160,165)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyy, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_yyyy_yyyy, t_yyyy_yyyz, t_yyyy_yyzz, t_yyyy_yzzz, t_yyyy_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyy_yyyy[j] = (6.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 11.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 30.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 11.25 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_yyyy[j] * fx[j] * fx[j] + 

                                 12.0 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 12.0 * pa_y[j] * fx[j] * fx[j] * pb_yyy[j] + 3.0 * pa_yyyy[j] * pb_yy[j] * fx[j] + 8.0 * pa_yyy[j] * fx[j] * pb_yyy[j] + 

                                 0.75 * fx[j] * fx[j] * pb_yyyy[j] + 3.0 * pa_yy[j] * fx[j] * pb_yyyy[j] + pa_yyyy[j] * pb_yyyy[j]) * s_0_0[j] + (52.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 27.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 112.5 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 300.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 4.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 27.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 3.0 * pa_yyyy[j] * fx[j] * fz[j] * fgb[j] - 

                                 24.0 * pa_yyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 112.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] + 144.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 324.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 4.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_yy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 18.0 * pa_yy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 24.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 6.0 * pa_yyyy[j] * pb_yy[j] * fz[j] * fgb[j] + 

                                 144.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 42.0 * pa_yyyy[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 112.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyy[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_yyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_yyyy_yyyz[j] = (7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 13.5 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * pa_yyyy[j] * pb_yz[j] * fx[j] + 

                                 6.0 * pa_yyy[j] * fx[j] * pb_yyz[j] + 0.75 * fx[j] * fx[j] * pb_yyyz[j] + 3.0 * pa_yy[j] * fx[j] * pb_yyyz[j] + 

                                 pa_yyyy[j] * pb_yyyz[j]) * s_0_0[j] + (75.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 6.0 * pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 36.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 162.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 18.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 3.0 * pa_yyyy[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 21.0 * pa_yyyy[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 84.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yyz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_yyyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyyz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_yyyy_yyzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * pa_yyyy[j] * fx[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * pb_yzz[j] + 0.5 * pa_yyyy[j] * pb_yy[j] * fx[j] + 0.5 * pa_yyyy[j] * fx[j] * pb_zz[j] + 

                                 4.0 * pa_yyy[j] * fx[j] * pb_yzz[j] + 0.75 * fx[j] * fx[j] * pb_yyzz[j] + 3.0 * pa_yy[j] * fx[j] * pb_yyzz[j] + 

                                 pa_yyyy[j] * pb_yyzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 pa_yyyy[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_yyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 30.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 54.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.75 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 3.0 * pa_yy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 12.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 pa_yyyy[j] * pb_yy[j] * fz[j] * fgb[j] - pa_yyyy[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 72.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 7.0 * pa_yyyy[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_yyyy[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 56.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyzz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_yyzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyzz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_yyyy_yzzz[j] = (4.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 3.0 * pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_zzz[j] + 1.5 * pa_yyyy[j] * pb_yz[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * pb_zzz[j] + 0.75 * fx[j] * fx[j] * pb_yzzz[j] + 3.0 * pa_yy[j] * fx[j] * pb_yzzz[j] + 

                                 pa_yyyy[j] * pb_yzzz[j]) * s_0_0[j] + (-9.0 * pa_y[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 6.0 * pa_yyy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 36.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 9.0 * pa_yy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 9.0 * pa_yy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 6.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 3.0 * pa_yyyy[j] * pb_yz[j] * fz[j] * fgb[j] + 54.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 21.0 * pa_yyyy[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 28.0 * pa_yyy[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yzzz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_yzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_yzzz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_yyyy_zzzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_yyyy[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 9.0 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_yyyy[j] * pb_zz[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_zzzz[j] + 3.0 * pa_yy[j] * fx[j] * pb_zzzz[j] + 

                                 pa_yyyy[j] * pb_zzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_yyyy[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_yyyy[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 18.0 * pa_yy[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_yy[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 6.0 * pa_yyyy[j] * pb_zz[j] * fz[j] * fgb[j] + 108.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_yyyy[j] * fz[j] * pb_zz[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_zzzz[j] - 

                                 6.0 * pa_yy[j] * fz[j] * fga[j] * pb_zzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] + 

                                 42.0 * pa_yy[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_yyyy[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (33) = (165,170)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyz, pa_yyz, pa_yz, pa_z, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xz, \
                                     pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_yyyz_xxxx, t_yyyz_xxxy, t_yyyz_xxxz, \
                                     t_yyyz_xxyy, t_yyyz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyz_xxxx[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_yyyz[j] * fx[j] * fx[j] + 

                                 4.5 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_yyyz[j] * pb_xx[j] * fx[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxxx[j] + 

                                 pa_yyyz[j] * pb_xxxx[j]) * s_0_0[j] + (-4.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_yyyz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 9.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 6.0 * pa_yyyz[j] * pb_xx[j] * fz[j] * fgb[j] + 54.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 42.0 * pa_yyyz[j] * fz[j] * pb_xx[j] * fx[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxxx[j] + 16.0 * pa_yyyz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_yyyz_xxxy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 2.25 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 1.5 * pa_yyyz[j] * pb_xy[j] * fx[j] + 1.5 * pa_yyz[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xxxy[j] + pa_yyyz[j] * pb_xxxy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 4.5 * pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 27.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxx[j] - 3.0 * pa_yyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxx[j] + 

                                 21.0 * pa_yyyz[j] * fz[j] * pb_xy[j] * fx[j] + 21.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xxx[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_yyyz_xxxz[j] = (1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xxx[j] + 1.5 * pa_yyyz[j] * pb_xz[j] * fx[j] + 0.5 * pa_yyy[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xxxz[j] + pa_yyyz[j] * pb_xxxz[j]) * s_0_0[j] + (-2.25 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 1.5 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xxx[j] - 3.0 * pa_yyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_yyyz[j] * fz[j] * pb_xz[j] * fx[j] + 7.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxx[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_yyyz_xxyy[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.25 * pa_yyyz[j] * fx[j] * fx[j] + 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 0.5 * pa_yyyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_yyyz[j] * fx[j] * pb_yy[j] + 

                                 3.0 * pa_yyz[j] * fx[j] * pb_xxy[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxyy[j] + pa_yyyz[j] * pb_xxyy[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 

                                 pa_yyyz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 3.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxy[j] - pa_yyyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyyz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxy[j] + 

                                 7.0 * pa_yyyz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yyyz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 42.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xxy[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxyy[j] + 16.0 * pa_yyyz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_yyyz_xxyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xxy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 0.5 * pa_yyyz[j] * fx[j] * pb_yz[j] + 0.5 * pa_yyy[j] * fx[j] * pb_xxy[j] + 

                                 1.5 * pa_yyz[j] * fx[j] * pb_xxz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxyz[j] + pa_yyyz[j] * pb_xxyz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.75 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.5 * pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 1.5 * pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 3.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 3.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 9.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xxy[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xxz[j] - pa_yyyz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xxz[j] + 7.0 * pa_yyyz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 7.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxy[j] + 21.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (34) = (170,175)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyz, pa_yyz, pa_yz, pa_z, pb_x, pb_xx, \
                                     pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, \
                                     pb_xzzz, pb_z, pb_zz, r_0_0, s_0_0, t_yyyz_xxzz, t_yyyz_xyyy, t_yyyz_xyyz, \
                                     t_yyyz_xyzz, t_yyyz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyz_xxzz[j] = (0.375 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * pa_yyyz[j] * fx[j] * fx[j] + 0.5 * pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * pa_yyyz[j] * pb_xx[j] * fx[j] + 0.5 * pa_yyyz[j] * fx[j] * pb_zz[j] + 

                                 pa_yyy[j] * fx[j] * pb_xxz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxzz[j] + pa_yyyz[j] * pb_xxzz[j]) * s_0_0[j] + (-1.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - pa_yyyz[j] * fx[j] * fz[j] * fgb[j] - pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 3.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] + 6.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xxz[j] - pa_yyyz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 7.0 * pa_yyyz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_yyyz[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xxz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxzz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_yyyz_xyyy[j] = (1.875 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 2.25 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 6.75 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 1.5 * pa_yyyz[j] * pb_xy[j] * fx[j] + 4.5 * pa_yyz[j] * fx[j] * pb_xyy[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xyyy[j] + pa_yyyz[j] * pb_xyyy[j]) * s_0_0[j] + (18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 

                                 4.5 * pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 27.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 81.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 4.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyy[j] - 

                                 3.0 * pa_yyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 27.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyy[j] + 

                                 21.0 * pa_yyyz[j] * fz[j] * pb_xy[j] * fx[j] + 63.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xyy[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_yyyz_xyyz[j] = (1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.25 * pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xyy[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_yyyz[j] * pb_xz[j] * fx[j] + 

                                 0.5 * pa_yyy[j] * fx[j] * pb_xyy[j] + 3.0 * pa_yyz[j] * fx[j] * pb_xyz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xyyz[j] + 

                                 pa_yyyz[j] * pb_xyyz[j]) * s_0_0[j] + (11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 0.5 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 3.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 18.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xyz[j] - 

                                 pa_yyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xyz[j] + 7.0 * pa_yyyz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 7.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xyy[j] + 42.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_yyyz_xyzz[j] = (0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_yyyz[j] * pb_xy[j] * fx[j] + 

                                 pa_yyy[j] * fx[j] * pb_xyz[j] + 1.5 * pa_yyz[j] * fx[j] * pb_xzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xyzz[j] + 

                                 pa_yyyz[j] * pb_xyzz[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_x[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 1.5 * pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_x[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 9.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 18.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 1.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 3.0 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xyz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_xzz[j] - pa_yyyz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_xzz[j] + 7.0 * pa_yyyz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 14.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xyz[j] + 21.0 * pa_yyz[j] * fx[j] * fz[j] * pb_xzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_yyyz_xzzz[j] = (1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * pa_yyy[j] * fx[j] * fx[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_xzz[j] + 1.5 * pa_yyyz[j] * pb_xz[j] * fx[j] + 1.5 * pa_yyy[j] * fx[j] * pb_xzz[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xzzz[j] + pa_yyyz[j] * pb_xzzz[j]) * s_0_0[j] + (-2.25 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_x[j] - 1.5 * pa_yyy[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 9.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 4.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_xzz[j] - 3.0 * pa_yyyz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 27.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 21.0 * pa_yyyz[j] * fz[j] * pb_xz[j] * fx[j] + 21.0 * pa_yyy[j] * fz[j] * fx[j] * pb_xzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (35) = (175,180)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyy, pa_yyyz, pa_yyz, pa_yz, pa_z, pb_y, pb_yy, \
                                     pb_yyy, pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, \
                                     pb_zzzz, r_0_0, s_0_0, t_yyyz_yyyy, t_yyyz_yyyz, t_yyyz_yyzz, t_yyyz_yzzz, \
                                     t_yyyz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyyz_yyyy[j] = (5.625 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.75 * pa_yyyz[j] * fx[j] * fx[j] + 9.0 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 13.5 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 3.0 * pa_yyyz[j] * pb_yy[j] * fx[j] + 

                                 6.0 * pa_yyz[j] * fx[j] * pb_yyy[j] + 1.5 * pa_yz[j] * fx[j] * pb_yyyy[j] + pa_yyyz[j] * pb_yyyy[j]) * s_0_0[j] + (-13.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] - 

                                 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 3.0 * pa_yyyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_yyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 9.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 162.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 9.0 * pa_yz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 

                                 6.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyy[j] - 6.0 * pa_yyyz[j] * pb_yy[j] * fz[j] * fgb[j] + 

                                 36.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyy[j] + 42.0 * pa_yyyz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 84.0 * pa_yyz[j] * fx[j] * fz[j] * pb_yyy[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_yyyy[j] + 16.0 * pa_yyyz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_yyyz_yyyz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 3.375 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 6.75 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * pb_yyy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 1.5 * pa_yyyz[j] * pb_yz[j] * fx[j] + 0.5 * pa_yyy[j] * fx[j] * pb_yyy[j] + 

                                 4.5 * pa_yyz[j] * fx[j] * pb_yyz[j] + 1.5 * pa_yz[j] * fx[j] * pb_yyyz[j] + pa_yyyz[j] * pb_yyyz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 11.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 33.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 1.5 * pa_yyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 9.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 27.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 81.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_yyy[j] - 4.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yyz[j] - 

                                 3.0 * pa_yyyz[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 

                                 27.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yyz[j] + 21.0 * pa_yyyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 7.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yyy[j] + 63.0 * pa_yyz[j] * fx[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_yyyz_yyzz[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_yyyz[j] * fx[j] * fx[j] + 0.5 * pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 3.0 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_yyyz[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_yyyz[j] * fx[j] * pb_zz[j] + pa_yyy[j] * fx[j] * pb_yyz[j] + 3.0 * pa_yyz[j] * fx[j] * pb_yzz[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_yyzz[j] + pa_yyyz[j] * pb_yyzz[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_y[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 pa_yyyz[j] * fx[j] * fz[j] * fgb[j] - pa_yyy[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 3.0 * pa_yyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_y[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 3.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 18.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 36.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_yyz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_yzz[j] - 

                                 pa_yyyz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_yyyz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 18.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_yzz[j] + 7.0 * pa_yyyz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 7.0 * pa_yyyz[j] * fz[j] * fx[j] * pb_zz[j] + 14.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yyz[j] + 

                                 42.0 * pa_yyz[j] * fx[j] * fz[j] * pb_yzz[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_yyzz[j] + 16.0 * pa_yyyz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_yyyz_yzzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_yyy[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 2.25 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 2.25 * pa_y[j] * fx[j] * fx[j] * pb_yzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_yyyz[j] * pb_yz[j] * fx[j] + 1.5 * pa_yyy[j] * fx[j] * pb_yzz[j] + 

                                 1.5 * pa_yyz[j] * fx[j] * pb_zzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_yzzz[j] + pa_yyyz[j] * pb_yzzz[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 1.5 * pa_yyy[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yyz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 27.0 * pa_yyz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 27.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 4.5 * pa_yz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 4.5 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_yzz[j] - 

                                 1.5 * fx[j] * fz[j] * fga[j] * pa_z[j] * pb_zzz[j] - 3.0 * pa_yyyz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 27.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pa_z[j] * pb_zzz[j] + 21.0 * pa_yyyz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 21.0 * pa_yyy[j] * fz[j] * fx[j] * pb_yzz[j] + 21.0 * pa_yyz[j] * fx[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_yyyz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_yyyz_zzzz[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_yyyz[j] * fx[j] * fx[j] + 3.0 * pa_yyy[j] * fx[j] * fx[j] * pb_z[j] + 

                                 4.5 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_yyyz[j] * pb_zz[j] * fx[j] + 

                                 2.0 * pa_yyy[j] * fx[j] * pb_zzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_zzzz[j] + pa_yyyz[j] * pb_zzzz[j]) * s_0_0[j] + (-4.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 9.0 * pa_y[j] * fz[j] * fga[j] * fx[j] * fx[j] * pb_z[j] - 3.0 * pa_yyyz[j] * fx[j] * fz[j] * fgb[j] - 

                                 6.0 * pa_yyy[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 45.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 9.0 * pa_yyyz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * pa_yyy[j] * fz[j] * fx[j] * fx[j] * pb_z[j] - 9.0 * pa_yz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 6.0 * pa_y[j] * fz[j] * fga[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_yyyz[j] * pb_zz[j] * fz[j] * fgb[j] + 54.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_yyyz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 28.0 * pa_yyy[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_yz[j] * fx[j] * fz[j] * pb_zzzz[j] + 16.0 * pa_yyyz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (36) = (180,185)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyz, pa_yyzz, pa_yz, pa_yzz, pa_z, pa_zz, pb_x, \
                                     pb_xx, pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, \
                                     pb_xz, pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_yyzz_xxxx, t_yyzz_xxxy, \
                                     t_yyzz_xxxz, t_yyzz_xxyy, t_yyzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyzz_xxxx[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 0.75 * pa_yyzz[j] * fx[j] * fx[j] + 0.75 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 3.0 * pa_yyzz[j] * pb_xx[j] * fx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxx[j] + 0.5 * pa_yy[j] * fx[j] * pb_xxxx[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxx[j] + 

                                 pa_yyzz[j] * pb_xxxx[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 1.5 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 3.0 * pa_yyzz[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 9.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] - 

                                 1.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 

                                 3.0 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 3.0 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 6.0 * pa_yyzz[j] * pb_xx[j] * fz[j] * fgb[j] + 

                                 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] + 

                                 42.0 * pa_yyzz[j] * fz[j] * pb_xx[j] * fx[j] - fx[j] * fz[j] * fga[j] * pb_xxxx[j] - pa_yy[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxx[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxx[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxx[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_yyzz_xxxy[j] = (0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 0.5 * pa_y[j] * fx[j] * fx[j] * pb_xxx[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 1.5 * pa_yyzz[j] * pb_xy[j] * fx[j] + pa_yzz[j] * fx[j] * pb_xxx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxy[j] + 0.5 * pa_yy[j] * fx[j] * pb_xxxy[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxy[j] + 

                                 pa_yyzz[j] * pb_xxxy[j]) * s_0_0[j] + (-1.5 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 18.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 1.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_yyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 9.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_xy[j] * fx[j] + 14.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xxx[j] - fx[j] * fz[j] * fga[j] * pb_xxxy[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xxxy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxy[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxy[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_yyzz_xxxz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 1.5 * pa_yyzz[j] * pb_xz[j] * fx[j] + pa_yyz[j] * fx[j] * pb_xxx[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xxxz[j] + 0.5 * pa_yy[j] * fx[j] * pb_xxxz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxxz[j] + 

                                 pa_yyzz[j] * pb_xxxz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - 3.0 * pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 18.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxx[j] - 

                                 3.0 * pa_yyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 9.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_xz[j] * fx[j] + 14.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xxx[j] - fx[j] * fz[j] * fga[j] * pb_xxxz[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xxxz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxxz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxxz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxxz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_yyzz_xxyy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.125 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 0.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_yyzz[j] * fx[j] * fx[j] + pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + pa_y[j] * fx[j] * fx[j] * pb_xxy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 0.5 * pa_yyzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_yyzz[j] * fx[j] * pb_yy[j] + 

                                 2.0 * pa_yzz[j] * fx[j] * pb_xxy[j] + 0.25 * fx[j] * fx[j] * pb_xxyy[j] + 0.5 * pa_yy[j] * fx[j] * pb_xxyy[j] + 

                                 0.5 * fx[j] * pa_zz[j] * pb_xxyy[j] + pa_yyzz[j] * pb_xxyy[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.5 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.25 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 pa_yyzz[j] * fx[j] * fz[j] * fgb[j] + 1.25 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 2.0 * pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 5.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] + 

                                 12.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 0.5 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 0.5 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 0.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 2.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_yy[j] - pa_yyzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 12.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] + 

                                 7.0 * pa_yyzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yyzz[j] * fz[j] * fx[j] * pb_yy[j] + 

                                 28.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xxy[j] - fx[j] * fz[j] * fga[j] * pb_xxyy[j] - pa_yy[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxyy[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxyy[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_yyzz_xxyz[j] = (0.5 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 0.5 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 0.5 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.5 * pa_y[j] * fx[j] * fx[j] * pb_xxz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 0.5 * pa_yyzz[j] * fx[j] * pb_yz[j] + pa_yyz[j] * fx[j] * pb_xxy[j] + 

                                 pa_yzz[j] * fx[j] * pb_xxz[j] + 0.25 * fx[j] * fx[j] * pb_xxyz[j] + 0.5 * pa_yy[j] * fx[j] * pb_xxyz[j] + 

                                 0.5 * fx[j] * pa_zz[j] * pb_xxyz[j] + pa_yyzz[j] * pb_xxyz[j]) * s_0_0[j] + (-pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 5.0 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 0.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 0.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 0.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 2.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 2.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 6.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 6.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 12.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 0.5 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 0.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_yz[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxy[j] - pa_yyzz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxy[j] + 

                                 7.0 * pa_yyzz[j] * fz[j] * fx[j] * pb_yz[j] + 14.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xxy[j] + 

                                 14.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xxz[j] - fx[j] * fz[j] * fga[j] * pb_xxyz[j] - pa_yy[j] * fz[j] * fga[j] * pb_xxyz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxyz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxyz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (37) = (185,190)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyz, pa_yyzz, pa_yz, pa_yzz, pa_z, pa_zz, pb_x, \
                                     pb_xx, pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, \
                                     pb_xzz, pb_xzzz, pb_z, pb_zz, r_0_0, s_0_0, t_yyzz_xxzz, t_yyzz_xyyy, t_yyzz_xyyz, \
                                     t_yyzz_xyzz, t_yyzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyzz_xxzz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 0.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_yyzz[j] * fx[j] * fx[j] + pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xx[j] + 0.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 0.5 * pa_yyzz[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_yyzz[j] * fx[j] * pb_zz[j] + 2.0 * pa_yyz[j] * fx[j] * pb_xxz[j] + 0.25 * fx[j] * fx[j] * pb_xxzz[j] + 

                                 0.5 * pa_yy[j] * fx[j] * pb_xxzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xxzz[j] + pa_yyzz[j] * pb_xxzz[j]) * s_0_0[j] + (-0.5 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.5 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.25 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 0.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] - 

                                 fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_xx[j] - pa_yyzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 1.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 

                                 5.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 3.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 0.25 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 0.5 * pa_yy[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_yy[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 0.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xx[j] * fz[j] * fgb[j] - 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 1.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xx[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_zz[j] - 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xxz[j] - 

                                 pa_yyzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yyzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] + 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxz[j] + 

                                 7.0 * pa_yyzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yyzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xxz[j] - fx[j] * fz[j] * fga[j] * pb_xxzz[j] - pa_yy[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xxzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xxzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xxzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_yyzz_xyyy[j] = (0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_xyy[j] + 1.5 * pa_yyzz[j] * pb_xy[j] * fx[j] + 3.0 * pa_yzz[j] * fx[j] * pb_xyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyyy[j] + 0.5 * pa_yy[j] * fx[j] * pb_xyyy[j] + 0.5 * fx[j] * pa_zz[j] * pb_xyyy[j] + 

                                 pa_yyzz[j] * pb_xyyy[j]) * s_0_0[j] + (-1.5 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 3.0 * pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 18.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] - 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 1.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 3.0 * pa_yyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_xy[j] * fx[j] + 42.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xyy[j] - fx[j] * fz[j] * fga[j] * pb_xyyy[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xyyy[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyyy[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyyy[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_yyzz_xyyz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 0.5 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.0 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 

                                 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + pa_y[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 

                                 0.5 * pa_yyzz[j] * pb_xz[j] * fx[j] + pa_yyz[j] * fx[j] * pb_xyy[j] + 2.0 * pa_yzz[j] * fx[j] * pb_xyz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyyz[j] + 0.5 * pa_yy[j] * fx[j] * pb_xyyz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xyyz[j] + 

                                 pa_yyzz[j] * pb_xyyz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] - 

                                 0.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 0.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 6.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 24.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 2.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xyy[j] - pa_yyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 12.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyy[j] + 7.0 * pa_yyzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 14.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xyy[j] + 28.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xyz[j] - fx[j] * fz[j] * fga[j] * pb_xyyz[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xyyz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyyz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyyz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_yyzz_xyzz[j] = (0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.5 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 2.0 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.5 * pa_y[j] * fx[j] * fx[j] * pb_xzz[j] + 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 

                                 0.5 * pa_yyzz[j] * pb_xy[j] * fx[j] + 2.0 * pa_yyz[j] * fx[j] * pb_xyz[j] + pa_yzz[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xyzz[j] + 0.5 * pa_yy[j] * fx[j] * pb_xyzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xyzz[j] + 

                                 pa_yyzz[j] * pb_xyzz[j]) * s_0_0[j] + (7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 0.5 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 0.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 fz[j] * fga[j] * fx[j] * fx[j] * pb_xy[j] - pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 6.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 24.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * pa_yy[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 0.5 * pa_yy[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 0.5 * fx[j] * pa_zz[j] * pb_xy[j] * fz[j] * fgb[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_xy[j] * fx[j] - 

                                 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xyz[j] - pa_yyzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] + 

                                 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyz[j] + 7.0 * pa_yyzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 28.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xyz[j] + 14.0 * pa_yzz[j] * fx[j] * fz[j] * pb_xzz[j] - fx[j] * fz[j] * fga[j] * pb_xyzz[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xyzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xyzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xyzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xyzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_yyzz_xzzz[j] = (0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_yy[j] * fx[j] * fx[j] * pb_xz[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 1.5 * pa_yyzz[j] * pb_xz[j] * fx[j] + 3.0 * pa_yyz[j] * fx[j] * pb_xzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_xzzz[j] + 0.5 * pa_yy[j] * fx[j] * pb_xzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_xzzz[j] + 

                                 pa_yyzz[j] * pb_xzzz[j]) * s_0_0[j] + (-1.5 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_x[j] - 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_xz[j] - 

                                 3.0 * pa_yyz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 18.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 27.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * fx[j] * pa_zz[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_xz[j] * fx[j] - 

                                 3.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_xzz[j] - 3.0 * pa_yyzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] + 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xzz[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_xz[j] * fx[j] + 42.0 * pa_yyz[j] * fz[j] * fx[j] * pb_xzz[j] - fx[j] * fz[j] * fga[j] * pb_xzzz[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_xzzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_xzzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_xzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_xzzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (38) = (190,195)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yy, pa_yyz, pa_yyzz, pa_yz, pa_yzz, pa_z, pa_zz, pb_y, \
                                     pb_yy, pb_yyy, pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, \
                                     pb_zzz, pb_zzzz, r_0_0, s_0_0, t_yyzz_yyyy, t_yyzz_yyyz, t_yyzz_yyzz, \
                                     t_yyzz_yzzz, t_yyzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yyzz_yyyy[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.75 * pa_yyzz[j] * fx[j] * fx[j] + 6.0 * pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 4.5 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 1.5 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 2.0 * pa_y[j] * fx[j] * fx[j] * pb_yyy[j] + 3.0 * pa_yyzz[j] * pb_yy[j] * fx[j] + 4.0 * pa_yzz[j] * fx[j] * pb_yyy[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyyy[j] + 0.5 * pa_yy[j] * fx[j] * pb_yyyy[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyyy[j] + 

                                 pa_yyzz[j] * pb_yyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 4.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 1.5 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 6.0 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 6.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 3.0 * pa_yyzz[j] * fx[j] * fz[j] * fgb[j] + 3.75 * pa_yy[j] * fz[j] * fx[j] * fx[j] * fx[j] - 

                                 12.0 * pa_yzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 30.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 9.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 54.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] - 

                                 1.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 4.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 

                                 3.0 * fx[j] * pa_zz[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_yy[j] * fx[j] - 

                                 6.0 * pa_yyzz[j] * pb_yy[j] * fz[j] * fgb[j] + 18.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 24.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 42.0 * pa_yyzz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 56.0 * pa_yzz[j] * fx[j] * fz[j] * pb_yyy[j] - fx[j] * fz[j] * fga[j] * pb_yyyy[j] - pa_yy[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyyy[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyyy[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyyy[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_yyzz_yyyz[j] = (1.5 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + 3.0 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 1.5 * pa_yyzz[j] * pb_yz[j] * fx[j] + 

                                 pa_yyz[j] * fx[j] * pb_yyy[j] + 3.0 * pa_yzz[j] * fx[j] * pb_yyz[j] + 0.25 * fx[j] * fx[j] * pb_yyyz[j] + 

                                 0.5 * pa_yy[j] * fx[j] * pb_yyyz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyyz[j] + pa_yyzz[j] * pb_yyyz[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - 3.0 * pa_yyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 18.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 18.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 36.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] - 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 3.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 1.5 * fx[j] * pa_zz[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_yz[j] * fx[j] - fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yyy[j] - 

                                 3.0 * pa_yyzz[j] * pb_yz[j] * fz[j] * fgb[j] + 9.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 6.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyy[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_yz[j] * fx[j] + 14.0 * pa_yyz[j] * fz[j] * fx[j] * pb_yyy[j] + 

                                 42.0 * pa_yzz[j] * fx[j] * fz[j] * pb_yyz[j] - fx[j] * fz[j] * fga[j] * pb_yyyz[j] - pa_yy[j] * fz[j] * fga[j] * pb_yyyz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyyz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyyz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyyz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_yyzz_yyzz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 0.25 * pa_yyzz[j] * fx[j] * fx[j] + pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_yy[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 4.0 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 0.25 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + pa_y[j] * fx[j] * fx[j] * pb_yzz[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 0.5 * pa_yyzz[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_yyzz[j] * fx[j] * pb_zz[j] + 2.0 * pa_yyz[j] * fx[j] * pb_yyz[j] + 2.0 * pa_yzz[j] * fx[j] * pb_yzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_yyzz[j] + 0.5 * pa_yy[j] * fx[j] * pb_yyzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yyzz[j] + 

                                 pa_yyzz[j] * pb_yyzz[j]) * s_0_0[j] + (4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] - fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] + 15.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 15.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] - 

                                 0.25 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 0.25 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - fz[j] * fga[j] * fx[j] * fx[j] * pb_yy[j] - pa_yyzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.0 * pa_yyz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 2.0 * pa_yzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 3.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] + 12.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 9.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 12.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 48.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] - 

                                 0.25 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.25 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_yy[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 0.5 * pa_yy[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 0.5 * pa_yy[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 0.5 * pa_yy[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 2.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 0.5 * fx[j] * pa_zz[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.5 * fx[j] * pa_zz[j] * fz[j] * fgb[j] * pb_zz[j] - 0.5 * fz[j] * fga[j] * pa_zz[j] * pb_yy[j] * fx[j] - 

                                 0.5 * fz[j] * fga[j] * pa_zz[j] * fx[j] * pb_zz[j] - 2.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yyz[j] - 

                                 pa_yyzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_yyzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 3.0 * pa_yy[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 12.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] + 12.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_yyzz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_yyzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 28.0 * pa_yyz[j] * fz[j] * fx[j] * pb_yyz[j] + 28.0 * pa_yzz[j] * fx[j] * fz[j] * pb_yzz[j] - fx[j] * fz[j] * fga[j] * pb_yyzz[j] - 

                                 pa_yy[j] * fz[j] * fga[j] * pb_yyzz[j] + 3.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yyzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_yyzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yyzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_yyzz_yzzz[j] = (1.5 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_yyz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 2.25 * pa_yy[j] * fx[j] * fx[j] * pb_yz[j] + 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 3.0 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 0.5 * pa_y[j] * fx[j] * fx[j] * pb_zzz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 1.5 * pa_yyzz[j] * pb_yz[j] * fx[j] + 

                                 3.0 * pa_yyz[j] * fx[j] * pb_yzz[j] + pa_yzz[j] * fx[j] * pb_zzz[j] + 0.25 * fx[j] * fx[j] * pb_yzzz[j] + 

                                 0.5 * pa_yy[j] * fx[j] * pb_yzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_yzzz[j] + pa_yyzz[j] * pb_yzzz[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 1.5 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_y[j] - 

                                 3.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_yz[j] - 3.0 * pa_yyz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_yzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 18.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 27.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 18.0 * pa_yzz[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 

                                 36.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 0.75 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yy[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 1.5 * pa_yy[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 pa_y[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 1.5 * fx[j] * pa_zz[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 1.5 * fz[j] * fga[j] * pa_zz[j] * pb_yz[j] * fx[j] - 3.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_yzz[j] - 

                                 3.0 * pa_yyzz[j] * pb_yz[j] * fz[j] * fgb[j] + 6.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] + 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yzz[j] + 

                                 21.0 * pa_yyzz[j] * fz[j] * pb_yz[j] * fx[j] + 42.0 * pa_yyz[j] * fz[j] * fx[j] * pb_yzz[j] + 

                                 14.0 * pa_yzz[j] * fx[j] * fz[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_yzzz[j] - pa_yy[j] * fz[j] * fga[j] * pb_yzzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_yzzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_yzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_yzzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_yyzz_zzzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 1.875 * pa_yy[j] * fx[j] * fx[j] * fx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 3.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_yyzz[j] * fx[j] * fx[j] + 6.0 * pa_yyz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 4.5 * pa_yy[j] * fx[j] * fx[j] * pb_zz[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 

                                 2.0 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 3.0 * pa_yyzz[j] * pb_zz[j] * fx[j] + 4.0 * pa_yyz[j] * fx[j] * pb_zzz[j] + 

                                 0.25 * fx[j] * fx[j] * pb_zzzz[j] + 0.5 * pa_yy[j] * fx[j] * pb_zzzz[j] + 0.5 * fx[j] * pa_zz[j] * pb_zzzz[j] + 

                                 pa_yyzz[j] * pb_zzzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fz[j] * fga[j] * fx[j] * fx[j] * fx[j] - 4.5 * pa_yy[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 18.75 * pa_yy[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 0.75 * pa_yy[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] - 

                                 6.0 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 0.75 * fz[j] * fga[j] * pa_zz[j] * fx[j] * fx[j] - 

                                 6.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * fx[j] * pb_z[j] - 6.0 * fz[j] * fga[j] * fx[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_yyzz[j] * fx[j] * fz[j] * fgb[j] - 12.0 * pa_yyz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 30.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 

                                 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 9.0 * pa_yyzz[j] * fz[j] * fx[j] * fx[j] + 

                                 72.0 * pa_yyz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 54.0 * pa_yy[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 1.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 3.0 * pa_yy[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_yy[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 3.0 * fx[j] * pa_zz[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 3.0 * fz[j] * fga[j] * pa_zz[j] * pb_zz[j] * fx[j] - 4.0 * fz[j] * fga[j] * pa_z[j] * fx[j] * pb_zzz[j] - 

                                 6.0 * pa_yyzz[j] * pb_zz[j] * fz[j] * fgb[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] + 

                                 24.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_zzz[j] + 42.0 * pa_yyzz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 56.0 * pa_yyz[j] * fz[j] * fx[j] * pb_zzz[j] - fx[j] * fz[j] * fga[j] * pb_zzzz[j] - pa_yy[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 3.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] - fz[j] * fga[j] * pa_zz[j] * pb_zzzz[j] + 

                                 7.0 * pa_yy[j] * fz[j] * fx[j] * pb_zzzz[j] + 7.0 * fx[j] * pa_zz[j] * fz[j] * pb_zzzz[j] + 

                                 16.0 * pa_yyzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (39) = (195,200)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_yzz, pa_yzzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, \
                                     pb_xxx, pb_xxxx, pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xxz, pb_xy, pb_xz, \
                                     pb_y, pb_yy, pb_yz, pb_z, r_0_0, s_0_0, t_yzzz_xxxx, t_yzzz_xxxy, t_yzzz_xxxz, \
                                     t_yzzz_xxyy, t_yzzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yzzz_xxxx[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_yzzz[j] * fx[j] * fx[j] + 

                                 4.5 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 3.0 * pa_yzzz[j] * pb_xx[j] * fx[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxxx[j] + 

                                 pa_yzzz[j] * pb_xxxx[j]) * s_0_0[j] + (-4.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 3.0 * pa_yzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fz[j] * fx[j] * fx[j] * fx[j] + 9.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] - 

                                 9.0 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 6.0 * pa_yzzz[j] * pb_xx[j] * fz[j] * fgb[j] + 54.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 42.0 * pa_yzzz[j] * fz[j] * pb_xx[j] * fx[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxx[j] + 

                                 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_yzzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_yzzz_xxxy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxx[j] + 1.5 * pa_yzzz[j] * pb_xy[j] * fx[j] + 0.5 * fx[j] * pa_zzz[j] * pb_xxx[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xxxy[j] + pa_yzzz[j] * pb_xxxy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - 1.5 * fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxx[j] - 3.0 * pa_yzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_yzzz[j] * fz[j] * pb_xy[j] * fx[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxx[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxy[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxxy[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_yzzz_xxxz[j] = (1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xxx[j] + 1.5 * pa_yzzz[j] * pb_xz[j] * fx[j] + 1.5 * pa_yzz[j] * fx[j] * pb_xxx[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xxxz[j] + pa_yzzz[j] * pb_xxxz[j]) * s_0_0[j] + (-2.25 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 4.5 * pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 27.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 1.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] - 3.0 * pa_yzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 

                                 21.0 * pa_yzzz[j] * fz[j] * pb_xz[j] * fx[j] + 21.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xxx[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxxz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxxz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_yzzz_xxyy[j] = (0.375 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.25 * pa_yzzz[j] * fx[j] * fx[j] + 0.5 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 

                                 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xxy[j] + 0.5 * pa_yzzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_yzzz[j] * fx[j] * pb_yy[j] + 

                                 fx[j] * pa_zzz[j] * pb_xxy[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxyy[j] + pa_yzzz[j] * pb_xxyy[j]) * s_0_0[j] + (-1.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - pa_yzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 3.75 * pa_yz[j] * fz[j] * fx[j] * fx[j] * fx[j] - fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 3.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 6.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] - 1.5 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] - 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxy[j] - 

                                 pa_yzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yzzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxy[j] + 7.0 * pa_yzzz[j] * fz[j] * pb_xx[j] * fx[j] + 

                                 7.0 * pa_yzzz[j] * fz[j] * fx[j] * pb_yy[j] + 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxy[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxyy[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxyy[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_yzzz_xxyz[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 0.375 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 0.75 * fx[j] * fx[j] * pa_zz[j] * pb_xx[j] + 

                                 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xxy[j] + 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xxz[j] + 0.5 * pa_yzzz[j] * fx[j] * pb_yz[j] + 1.5 * pa_yzz[j] * fx[j] * pb_xxy[j] + 

                                 0.5 * fx[j] * pa_zzz[j] * pb_xxz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxyz[j] + pa_yzzz[j] * pb_xxyz[j]) * s_0_0[j] + (-0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.375 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 0.75 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 3.75 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 0.75 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 3.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 0.5 * fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 9.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 3.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xx[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 1.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] - 

                                 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xxz[j] - pa_yzzz[j] * fz[j] * fgb[j] * pb_yz[j] + 

                                 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xxz[j] + 7.0 * pa_yzzz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 21.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xxy[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xxz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxyz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxyz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (40) = (200,205)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_yzz, pa_yzzz, pa_z, pa_zz, pa_zzz, pb_x, pb_xx, \
                                     pb_xxz, pb_xxzz, pb_xy, pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, \
                                     pb_xzzz, pb_z, pb_zz, r_0_0, s_0_0, t_yzzz_xxzz, t_yzzz_xyyy, t_yzzz_xyyz, \
                                     t_yzzz_xyzz, t_yzzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yzzz_xxzz[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.25 * pa_yzzz[j] * fx[j] * fx[j] + 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xx[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * pa_yzzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_yzzz[j] * fx[j] * pb_zz[j] + 

                                 3.0 * pa_yzz[j] * fx[j] * pb_xxz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xxzz[j] + pa_yzzz[j] * pb_xxzz[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 pa_yzzz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 3.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] - pa_yzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_yzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 7.0 * pa_yzzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_yzzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 42.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xxz[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xxzz[j] + 

                                 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xxzz[j] + 16.0 * pa_yzzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_yzzz_xyyy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_xyy[j] + 1.5 * pa_yzzz[j] * pb_xy[j] * fx[j] + 1.5 * fx[j] * pa_zzz[j] * pb_xyy[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xyyy[j] + pa_yzzz[j] * pb_xyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - 1.5 * fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 4.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xyy[j] - 3.0 * pa_yzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 27.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyy[j] + 

                                 21.0 * pa_yzzz[j] * fz[j] * pb_xy[j] * fx[j] + 21.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xyy[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyyy[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xyyy[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_yzzz_xyyz[j] = (0.375 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 0.75 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_xy[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * pb_xyy[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_xyz[j] + 0.5 * pa_yzzz[j] * pb_xz[j] * fx[j] + 

                                 1.5 * pa_yzz[j] * fx[j] * pb_xyy[j] + fx[j] * pa_zzz[j] * pb_xyz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xyyz[j] + 

                                 pa_yzzz[j] * pb_xyyz[j]) * s_0_0[j] + (-0.75 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 0.75 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 

                                 1.5 * pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 3.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 9.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xy[j] - 1.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 1.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] - 

                                 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xyz[j] - pa_yzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xyz[j] + 7.0 * pa_yzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 21.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xyy[j] + 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xyz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyyz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xyyz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_yzzz_xyzz[j] = (1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_x[j] + 

                                 0.75 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 0.25 * fx[j] * fx[j] * pa_zzz[j] * pb_x[j] + 1.5 * fx[j] * fx[j] * pa_zz[j] * pb_xz[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_xzz[j] + 0.5 * pa_yzzz[j] * pb_xy[j] * fx[j] + 

                                 3.0 * pa_yzz[j] * fx[j] * pb_xyz[j] + 0.5 * fx[j] * pa_zzz[j] * pb_xzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_xyzz[j] + 

                                 pa_yzzz[j] * pb_xyzz[j]) * s_0_0[j] + (11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pa_z[j] * pb_x[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_x[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 0.5 * fx[j] * pa_zzz[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_x[j] + 18.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_xz[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 

                                 3.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 pa_yzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_xzz[j] + 7.0 * pa_yzzz[j] * fz[j] * pb_xy[j] * fx[j] + 

                                 42.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xyz[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_xzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xyzz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xyzz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_yzzz_xzzz[j] = (1.875 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 2.25 * pa_yzz[j] * fx[j] * fx[j] * pb_x[j] + 6.75 * pa_yz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_xzz[j] + 1.5 * pa_yzzz[j] * pb_xz[j] * fx[j] + 4.5 * pa_yzz[j] * fx[j] * pb_xzz[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_xzzz[j] + pa_yzzz[j] * pb_xzzz[j]) * s_0_0[j] + (18.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 2.25 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 4.5 * pa_yzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 27.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 81.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 4.5 * pa_yz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 4.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 

                                 3.0 * pa_yzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 27.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 

                                 21.0 * pa_yzzz[j] * fz[j] * pb_xz[j] * fx[j] + 63.0 * pa_yzz[j] * fz[j] * fx[j] * pb_xzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_xzzz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_xzzz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (41) = (205,210)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_y, pa_yz, pa_yzz, pa_yzzz, pa_z, pa_zz, pa_zzz, pb_y, pb_yy, \
                                     pb_yyy, pb_yyyy, pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, \
                                     pb_zzzz, r_0_0, s_0_0, t_yzzz_yyyy, t_yzzz_yyyz, t_yzzz_yyzz, t_yzzz_yzzz, \
                                     t_yzzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_yzzz_yyyy[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.75 * pa_yzzz[j] * fx[j] * fx[j] + 3.0 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 

                                 4.5 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 3.0 * fx[j] * fx[j] * pa_z[j] * pb_yyy[j] + 3.0 * pa_yzzz[j] * pb_yy[j] * fx[j] + 

                                 2.0 * fx[j] * pa_zzz[j] * pb_yyy[j] + 1.5 * pa_yz[j] * fx[j] * pb_yyyy[j] + pa_yzzz[j] * pb_yyyy[j]) * s_0_0[j] + (-4.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * pa_yzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fz[j] * fx[j] * fx[j] * fx[j] - 6.0 * fx[j] * pa_zzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 45.0 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] + 9.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 36.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] - 9.0 * pa_yz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 6.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yyy[j] - 

                                 6.0 * pa_yzzz[j] * pb_yy[j] * fz[j] * fgb[j] + 54.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 36.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyy[j] + 42.0 * pa_yzzz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 28.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yyy[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyyy[j] + 

                                 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_yzzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_yzzz_yyyz[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 1.125 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 

                                 1.125 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 2.25 * pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_yy[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * pb_yyy[j] + 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_yyz[j] + 1.5 * pa_yzzz[j] * pb_yz[j] * fx[j] + 1.5 * pa_yzz[j] * fx[j] * pb_yyy[j] + 

                                 1.5 * fx[j] * pa_zzz[j] * pb_yyz[j] + 1.5 * pa_yz[j] * fx[j] * pb_yyyz[j] + pa_yzzz[j] * pb_yyyz[j]) * s_0_0[j] + (-1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 2.25 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 

                                 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 11.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fgb[j] * pb_z[j] - 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 4.5 * pa_yzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 1.5 * fx[j] * pa_zzz[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 27.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 

                                 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yy[j] - 4.5 * pa_yz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 1.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] - 

                                 4.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yyz[j] - 3.0 * pa_yzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 27.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 

                                 27.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yyz[j] + 21.0 * pa_yzzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 21.0 * pa_yzz[j] * fz[j] * fx[j] * pb_yyy[j] + 21.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yyz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyyz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_yyyz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_yzzz_yyzz[j] = (1.125 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 2.25 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_y[j] + 0.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 

                                 1.5 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 0.25 * pa_yzzz[j] * fx[j] * fx[j] + 1.5 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 2.25 * pa_yz[j] * fx[j] * fx[j] * pb_yy[j] + 0.5 * fx[j] * fx[j] * pa_zzz[j] * pb_y[j] + 

                                 3.0 * fx[j] * fx[j] * pa_zz[j] * pb_yz[j] + 0.75 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * pb_yyz[j] + 1.5 * fx[j] * fx[j] * pa_z[j] * pb_yzz[j] + 0.5 * pa_yzzz[j] * pb_yy[j] * fx[j] + 

                                 0.5 * pa_yzzz[j] * fx[j] * pb_zz[j] + 3.0 * pa_yzz[j] * fx[j] * pb_yyz[j] + fx[j] * pa_zzz[j] * pb_yzz[j] + 

                                 1.5 * pa_yz[j] * fx[j] * pb_yyzz[j] + pa_yzzz[j] * pb_yyzz[j]) * s_0_0[j] + (-3.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 11.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_y[j] - 

                                 0.75 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 1.5 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 1.5 * fx[j] * fx[j] * pa_z[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_y[j] - 3.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 pa_yzzz[j] * fx[j] * fz[j] * fgb[j] - 3.0 * pa_yzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - fx[j] * pa_zzz[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 15.0 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 3.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 18.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 27.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 6.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_y[j] + 36.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_yz[j] - 

                                 1.5 * pa_yz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 1.5 * pa_yz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 1.5 * pa_yz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 1.5 * pa_yz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 3.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] - 3.0 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_yzz[j] - 

                                 pa_yzzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_yzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 9.0 * pa_yz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 18.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 18.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_yzz[j] + 7.0 * pa_yzzz[j] * fz[j] * pb_yy[j] * fx[j] + 

                                 7.0 * pa_yzzz[j] * fz[j] * fx[j] * pb_zz[j] + 42.0 * pa_yzz[j] * fz[j] * fx[j] * pb_yyz[j] + 

                                 14.0 * fx[j] * pa_zzz[j] * fz[j] * pb_yzz[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yyzz[j] + 

                                 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_yyzz[j] + 16.0 * pa_yzzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_yzzz_yzzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 

                                 1.875 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pa_zz[j] + 

                                 3.375 * fx[j] * fx[j] * fx[j] * pa_z[j] * pb_z[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 2.25 * pa_yzz[j] * fx[j] * fx[j] * pb_y[j] + 6.75 * pa_yz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 0.75 * fx[j] * fx[j] * pa_zzz[j] * pb_z[j] + 2.25 * fx[j] * fx[j] * pa_zz[j] * pb_zz[j] + 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_yzz[j] + 0.75 * fx[j] * fx[j] * pa_z[j] * pb_zzz[j] + 1.5 * pa_yzzz[j] * pb_yz[j] * fx[j] + 

                                 4.5 * pa_yzz[j] * fx[j] * pb_yzz[j] + 0.5 * fx[j] * pa_zzz[j] * pb_zzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_yzzz[j] + 

                                 pa_yzzz[j] * pb_yzzz[j]) * s_0_0[j] + (7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 1.125 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 2.25 * fx[j] * fx[j] * pa_zz[j] * fz[j] * fgb[j] + 18.75 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 

                                 11.25 * fx[j] * fx[j] * fx[j] * pa_zz[j] * fz[j] + 33.75 * fx[j] * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_z[j] - 

                                 2.25 * pa_y[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 2.25 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pa_z[j] * pb_z[j] * fz[j] * fgb[j] - 2.25 * fx[j] * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_z[j] - 

                                 2.25 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 4.5 * pa_yzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 1.5 * fx[j] * pa_zzz[j] * pb_z[j] * fz[j] * fgb[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 27.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 81.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_zzz[j] * fz[j] * pb_z[j] + 27.0 * fx[j] * fx[j] * pa_zz[j] * fz[j] * pb_zz[j] - 

                                 4.5 * pa_yz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * pa_yz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 4.5 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 1.5 * fx[j] * pa_z[j] * fz[j] * fga[j] * pb_zzz[j] - 

                                 3.0 * pa_yzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 27.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 

                                 9.0 * fx[j] * fx[j] * pa_z[j] * fz[j] * pb_zzz[j] + 21.0 * pa_yzzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 63.0 * pa_yzz[j] * fz[j] * fx[j] * pb_yzz[j] + 7.0 * fx[j] * pa_zzz[j] * fz[j] * pb_zzz[j] - 

                                 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_yzzz[j] + 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_yzzz[j] + 

                                 16.0 * pa_yzzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_yzzz_zzzz[j] = (5.625 * pa_yz[j] * fx[j] * fx[j] * fx[j] + 

                                 7.5 * pa_y[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 0.75 * pa_yzzz[j] * fx[j] * fx[j] + 9.0 * pa_yzz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 13.5 * pa_yz[j] * fx[j] * fx[j] * pb_zz[j] + 3.0 * pa_y[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_yzzz[j] * pb_zz[j] * fx[j] + 

                                 6.0 * pa_yzz[j] * fx[j] * pb_zzz[j] + 1.5 * pa_yz[j] * fx[j] * pb_zzzz[j] + pa_yzzz[j] * pb_zzzz[j]) * s_0_0[j] + (-13.5 * pa_yz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 56.25 * pa_yz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 75.0 * pa_y[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 

                                 2.25 * pa_yz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 9.0 * pa_y[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 3.0 * pa_yzzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_yzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 9.0 * pa_yzzz[j] * fz[j] * fx[j] * fx[j] + 

                                 108.0 * pa_yzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 162.0 * pa_yz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 9.0 * pa_yz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 9.0 * pa_yz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 6.0 * pa_y[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 6.0 * pa_yzzz[j] * pb_zz[j] * fz[j] * fgb[j] + 

                                 36.0 * pa_y[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_yzzz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 84.0 * pa_yzz[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * pa_yz[j] * fz[j] * fga[j] * pb_zzzz[j] + 

                                 21.0 * pa_yz[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_yzzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (42) = (210,215)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_z, pa_zz, pa_zzz, pa_zzzz, pb_x, pb_xx, pb_xxx, pb_xxxx, \
                                     pb_xxxy, pb_xxxz, pb_xxy, pb_xxyy, pb_xxyz, pb_xy, pb_xz, pb_y, pb_yy, pb_yz, r_0_0, \
                                     s_0_0, t_zzzz_xxxx, t_zzzz_xxxy, t_zzzz_xxxz, t_zzzz_xxyy, t_zzzz_xxyz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_zzzz_xxxx[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_zzzz[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 9.0 * pa_zz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 3.0 * pa_zzzz[j] * pb_xx[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xxxx[j] + 3.0 * pa_zz[j] * fx[j] * pb_xxxx[j] + 

                                 pa_zzzz[j] * pb_xxxx[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_zzzz[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_zz[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 18.0 * pa_zz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_zz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 

                                 6.0 * pa_zzzz[j] * pb_xx[j] * fz[j] * fgb[j] + 108.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 42.0 * pa_zzzz[j] * fz[j] * pb_xx[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxx[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxxx[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxx[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxxx[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xxxx[j]) * r_0_0[j];

                t_zzzz_xxxy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_zzzz[j] * pb_xy[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xxxy[j] + 

                                 3.0 * pa_zz[j] * fx[j] * pb_xxxy[j] + pa_zzzz[j] * pb_xxxy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 9.0 * pa_zz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 3.0 * pa_zzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 54.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 21.0 * pa_zzzz[j] * fz[j] * pb_xy[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxy[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxxy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxy[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxxy[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xxxy[j]) * r_0_0[j];

                t_zzzz_xxxz[j] = (4.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 3.0 * pa_zzz[j] * fx[j] * fx[j] * pb_x[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_z[j] * fx[j] * fx[j] * pb_xxx[j] + 1.5 * pa_zzzz[j] * pb_xz[j] * fx[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * pb_xxx[j] + 0.75 * fx[j] * fx[j] * pb_xxxz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xxxz[j] + 

                                 pa_zzzz[j] * pb_xxxz[j]) * s_0_0[j] + (-9.0 * pa_z[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 6.0 * pa_zzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 36.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 9.0 * pa_zz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 6.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xxx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 3.0 * pa_zzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 54.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 36.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xxx[j] + 21.0 * pa_zzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 28.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xxx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxxz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxxz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxxz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxxz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xxxz[j]) * r_0_0[j];

                t_zzzz_xxyy[j] = (0.1875 * fx[j] * fx[j] * fx[j] * fx[j] + 0.75 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.25 * pa_zzzz[j] * fx[j] * fx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_xx[j] + 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_yy[j] + 0.5 * pa_zzzz[j] * pb_xx[j] * fx[j] + 

                                 0.5 * pa_zzzz[j] * fx[j] * pb_yy[j] + 0.75 * fx[j] * fx[j] * pb_xxyy[j] + 3.0 * pa_zz[j] * fx[j] * pb_xxyy[j] + 

                                 pa_zzzz[j] * pb_xxyy[j]) * s_0_0[j] + (-0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 3.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 1.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] + 1.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - pa_zzzz[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * pa_zz[j] * fz[j] * fx[j] * fx[j] * fx[j] + 3.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 3.0 * pa_zz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_zz[j] * fx[j] * fz[j] * fgb[j] * pb_yy[j] - 

                                 3.0 * pa_zz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_zz[j] * fz[j] * fga[j] * fx[j] * pb_yy[j] + 

                                 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 pa_zzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_zzzz[j] * fz[j] * fgb[j] * pb_yy[j] + 

                                 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xx[j] + 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 7.0 * pa_zzzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_zzzz[j] * fz[j] * fx[j] * pb_yy[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyy[j] - 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxyy[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyy[j] + 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxyy[j] + 

                                 16.0 * pa_zzzz[j] * fz[j] * pb_xxyy[j]) * r_0_0[j];

                t_zzzz_xxyz[j] = (1.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 pa_zzz[j] * fx[j] * fx[j] * pb_y[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_z[j] * fx[j] * fx[j] * pb_xxy[j] + 0.5 * pa_zzzz[j] * fx[j] * pb_yz[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * pb_xxy[j] + 0.75 * fx[j] * fx[j] * pb_xxyz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xxyz[j] + 

                                 pa_zzzz[j] * pb_xxyz[j]) * s_0_0[j] + (-3.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] - 

                                 3.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 2.0 * pa_zzz[j] * fx[j] * fz[j] * fgb[j] * pb_y[j] + 

                                 15.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 12.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 3.0 * pa_zz[j] * fx[j] * fz[j] * fgb[j] * pb_yz[j] - 3.0 * pa_zz[j] * fz[j] * fga[j] * fx[j] * pb_yz[j] - 

                                 6.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xxy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 pa_zzzz[j] * fz[j] * fgb[j] * pb_yz[j] + 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 36.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xxy[j] + 7.0 * pa_zzzz[j] * fz[j] * fx[j] * pb_yz[j] + 

                                 28.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xxy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxyz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxyz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxyz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xxyz[j]) * r_0_0[j];
            }

            // Batch of Integrals (43) = (215,220)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_z, pa_zz, pa_zzz, pa_zzzz, pb_x, pb_xx, pb_xxz, pb_xxzz, pb_xy, \
                                     pb_xyy, pb_xyyy, pb_xyyz, pb_xyz, pb_xyzz, pb_xz, pb_xzz, pb_xzzz, pb_z, pb_zz, r_0_0, \
                                     s_0_0, t_zzzz_xxzz, t_zzzz_xyyy, t_zzzz_xyyz, t_zzzz_xyzz, t_zzzz_xzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_zzzz_xxzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_xx[j] + 0.25 * pa_zzzz[j] * fx[j] * fx[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * fx[j] * pb_z[j] + 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_xx[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 6.0 * pa_z[j] * fx[j] * fx[j] * pb_xxz[j] + 0.5 * pa_zzzz[j] * pb_xx[j] * fx[j] + 0.5 * pa_zzzz[j] * fx[j] * pb_zz[j] + 

                                 4.0 * pa_zzz[j] * fx[j] * pb_xxz[j] + 0.75 * fx[j] * fx[j] * pb_xxzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xxzz[j] + 

                                 pa_zzzz[j] * pb_xxzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_zz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 6.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xx[j] - 

                                 pa_zzzz[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_zzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 30.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] + 

                                 3.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 54.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_xx[j] - 0.75 * fx[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 3.0 * pa_zz[j] * fx[j] * pb_xx[j] * fz[j] * fgb[j] - 3.0 * pa_zz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_zz[j] * fz[j] * fga[j] * pb_xx[j] * fx[j] - 3.0 * pa_zz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 12.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xxz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 pa_zzzz[j] * pb_xx[j] * fz[j] * fgb[j] - pa_zzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 72.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xxz[j] + 

                                 7.0 * pa_zzzz[j] * fz[j] * pb_xx[j] * fx[j] + 7.0 * pa_zzzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 56.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xxz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xxzz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xxzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xxzz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xxzz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xxzz[j]) * r_0_0[j];

                t_zzzz_xyyy[j] = (1.125 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_xy[j] + 1.5 * pa_zzzz[j] * pb_xy[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_xyyy[j] + 

                                 3.0 * pa_zz[j] * fx[j] * pb_xyyy[j] + pa_zzzz[j] * pb_xyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] - 9.0 * pa_zz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 3.0 * pa_zzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 54.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 21.0 * pa_zzzz[j] * fz[j] * pb_xy[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyy[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyy[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xyyy[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xyyy[j]) * r_0_0[j];

                t_zzzz_xyyz[j] = (1.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 pa_zzz[j] * fx[j] * fx[j] * pb_x[j] + 0.375 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_z[j] * fx[j] * fx[j] * pb_xyy[j] + 0.5 * pa_zzzz[j] * pb_xz[j] * fx[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * pb_xyy[j] + 0.75 * fx[j] * fx[j] * pb_xyyz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xyyz[j] + 

                                 pa_zzzz[j] * pb_xyyz[j]) * s_0_0[j] + (-3.0 * pa_z[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 2.0 * pa_zzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 15.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] + 12.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 

                                 3.0 * pa_zz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 3.0 * pa_zz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 6.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xyy[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 

                                 pa_zzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_xz[j] + 

                                 36.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xyy[j] + 7.0 * pa_zzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 28.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xyyz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xyyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xyyz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xyyz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xyyz[j]) * r_0_0[j];

                t_zzzz_xyzz[j] = (1.875 * fx[j] * fx[j] * fx[j] * pb_xy[j] + 

                                 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_xy[j] + 6.0 * pa_z[j] * fx[j] * fx[j] * pb_xyz[j] + 0.5 * pa_zzzz[j] * pb_xy[j] * fx[j] + 

                                 4.0 * pa_zzz[j] * fx[j] * pb_xyz[j] + 0.75 * fx[j] * fx[j] * pb_xyzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xyzz[j] + 

                                 pa_zzzz[j] * pb_xyzz[j]) * s_0_0[j] + (-4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xy[j] + 

                                 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] + 54.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_xy[j] - 

                                 0.75 * fx[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 3.0 * pa_zz[j] * fx[j] * pb_xy[j] * fz[j] * fgb[j] - 

                                 3.0 * pa_zz[j] * fz[j] * fga[j] * pb_xy[j] * fx[j] - 12.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xyz[j] - 

                                 pa_zzzz[j] * pb_xy[j] * fz[j] * fgb[j] + 72.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xyz[j] + 

                                 7.0 * pa_zzzz[j] * fz[j] * pb_xy[j] * fx[j] + 56.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xyz[j] - 

                                 3.0 * fx[j] * fz[j] * fga[j] * pb_xyzz[j] - 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xyzz[j] + 

                                 9.0 * fx[j] * fx[j] * fz[j] * pb_xyzz[j] + 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xyzz[j] + 

                                 16.0 * pa_zzzz[j] * fz[j] * pb_xyzz[j]) * r_0_0[j];

                t_zzzz_xzzz[j] = (7.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_x[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_xz[j] + 3.0 * pa_zzz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 13.5 * pa_zz[j] * fx[j] * fx[j] * pb_xz[j] + 9.0 * pa_z[j] * fx[j] * fx[j] * pb_xzz[j] + 1.5 * pa_zzzz[j] * pb_xz[j] * fx[j] + 

                                 6.0 * pa_zzz[j] * fx[j] * pb_xzz[j] + 0.75 * fx[j] * fx[j] * pb_xzzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_xzzz[j] + 

                                 pa_zzzz[j] * pb_xzzz[j]) * s_0_0[j] + (75.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_x[j] - 

                                 9.0 * pa_z[j] * fx[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] - 9.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_x[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_xz[j] - 6.0 * pa_zzz[j] * fx[j] * pb_x[j] * fz[j] * fgb[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] + 36.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_x[j] + 

                                 162.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_xz[j] - 2.25 * fx[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_zz[j] * fx[j] * pb_xz[j] * fz[j] * fgb[j] - 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_xz[j] * fx[j] - 

                                 18.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_xzz[j] - 3.0 * pa_zzzz[j] * pb_xz[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_xzz[j] + 21.0 * pa_zzzz[j] * fz[j] * pb_xz[j] * fx[j] + 

                                 84.0 * pa_zzz[j] * fz[j] * fx[j] * pb_xzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_xzzz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_xzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_xzzz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_xzzz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_xzzz[j]) * r_0_0[j];
            }

            // Batch of Integrals (44) = (220,225)

            #pragma omp simd aligned(fga, fgb, fx, fz, pa_z, pa_zz, pa_zzz, pa_zzzz, pb_y, pb_yy, pb_yyy, pb_yyyy, \
                                     pb_yyyz, pb_yyz, pb_yyzz, pb_yz, pb_yzz, pb_yzzz, pb_z, pb_zz, pb_zzz, pb_zzzz, r_0_0, \
                                     s_0_0, t_zzzz_yyyy, t_zzzz_yyyz, t_zzzz_yyzz, t_zzzz_yzzz, t_zzzz_zzzz: VLX_ALIGN)
            for (int32_t j = 0; j < nprim; j++)
            {
                t_zzzz_yyyy[j] = (0.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 0.75 * pa_zzzz[j] * fx[j] * fx[j] + 2.25 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 9.0 * pa_zz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 3.0 * pa_zzzz[j] * pb_yy[j] * fx[j] + 0.75 * fx[j] * fx[j] * pb_yyyy[j] + 3.0 * pa_zz[j] * fx[j] * pb_yyyy[j] + 

                                 pa_zzzz[j] * pb_yyyy[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 9.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 4.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] + 4.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 3.0 * pa_zzzz[j] * fx[j] * fz[j] * fgb[j] + 22.5 * pa_zz[j] * fz[j] * fx[j] * fx[j] * fx[j] + 

                                 9.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] - 4.5 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 9.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 18.0 * pa_zz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_zz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] + 22.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 

                                 6.0 * pa_zzzz[j] * pb_yy[j] * fz[j] * fgb[j] + 108.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 42.0 * pa_zzzz[j] * fz[j] * pb_yy[j] * fx[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyy[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_yyyy[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyy[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_yyyy[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_yyyy[j]) * r_0_0[j];

                t_zzzz_yyyz[j] = (4.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 3.0 * pa_zzz[j] * fx[j] * fx[j] * pb_y[j] + 1.125 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_z[j] * fx[j] * fx[j] * pb_yyy[j] + 1.5 * pa_zzzz[j] * pb_yz[j] * fx[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * pb_yyy[j] + 0.75 * fx[j] * fx[j] * pb_yyyz[j] + 3.0 * pa_zz[j] * fx[j] * pb_yyyz[j] + 

                                 pa_zzzz[j] * pb_yyyz[j]) * s_0_0[j] + (-9.0 * pa_z[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 6.0 * pa_zzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 45.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] + 36.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] - 

                                 2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 

                                 9.0 * pa_zz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 6.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_yyy[j] + 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 

                                 3.0 * pa_zzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 54.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_yz[j] + 

                                 36.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_yyy[j] + 21.0 * pa_zzzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 28.0 * pa_zzz[j] * fz[j] * fx[j] * pb_yyy[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyyz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_yyyz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyyz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_yyyz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_yyyz[j]) * r_0_0[j];

                t_zzzz_yyzz[j] = (0.9375 * fx[j] * fx[j] * fx[j] * fx[j] + 2.25 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 3.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 1.875 * fx[j] * fx[j] * fx[j] * pb_yy[j] + 0.25 * pa_zzzz[j] * fx[j] * fx[j] + 

                                 2.0 * pa_zzz[j] * fx[j] * fx[j] * pb_z[j] + 4.5 * pa_zz[j] * fx[j] * fx[j] * pb_yy[j] + 

                                 0.375 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 1.5 * pa_zz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 6.0 * pa_z[j] * fx[j] * fx[j] * pb_yyz[j] + 0.5 * pa_zzzz[j] * pb_yy[j] * fx[j] + 0.5 * pa_zzzz[j] * fx[j] * pb_zz[j] + 

                                 4.0 * pa_zzz[j] * fx[j] * pb_yyz[j] + 0.75 * fx[j] * fx[j] * pb_yyzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_yyzz[j] + 

                                 pa_zzzz[j] * pb_yyzz[j]) * s_0_0[j] + (-2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 

                                 2.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 6.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 

                                 7.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] + 22.5 * pa_zz[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 1.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 6.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] - 

                                 6.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 4.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yy[j] - 

                                 pa_zzzz[j] * fx[j] * fz[j] * fgb[j] - 4.0 * pa_zzz[j] * fx[j] * fz[j] * fgb[j] * pb_z[j] + 

                                 30.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] + 18.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] + 

                                 3.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] + 24.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 54.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_yy[j] - 0.75 * fx[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 

                                 0.75 * fx[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 1.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 

                                 3.0 * pa_zz[j] * fx[j] * pb_yy[j] * fz[j] * fgb[j] - 3.0 * pa_zz[j] * fx[j] * fz[j] * fgb[j] * pb_zz[j] - 

                                 3.0 * pa_zz[j] * fz[j] * fga[j] * pb_yy[j] * fx[j] - 3.0 * pa_zz[j] * fz[j] * fga[j] * fx[j] * pb_zz[j] - 

                                 12.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_yyz[j] + 3.75 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 

                                 pa_zzzz[j] * pb_yy[j] * fz[j] * fgb[j] - pa_zzzz[j] * fz[j] * fgb[j] * pb_zz[j] + 

                                 18.0 * pa_zz[j] * fz[j] * fx[j] * fx[j] * pb_zz[j] + 72.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_yyz[j] + 

                                 7.0 * pa_zzzz[j] * fz[j] * pb_yy[j] * fx[j] + 7.0 * pa_zzzz[j] * fz[j] * fx[j] * pb_zz[j] + 

                                 56.0 * pa_zzz[j] * fz[j] * fx[j] * pb_yyz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yyzz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_yyzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yyzz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_yyzz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_yyzz[j]) * r_0_0[j];

                t_zzzz_yzzz[j] = (7.5 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_y[j] + 

                                 5.625 * fx[j] * fx[j] * fx[j] * pb_yz[j] + 3.0 * pa_zzz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 13.5 * pa_zz[j] * fx[j] * fx[j] * pb_yz[j] + 9.0 * pa_z[j] * fx[j] * fx[j] * pb_yzz[j] + 1.5 * pa_zzzz[j] * pb_yz[j] * fx[j] + 

                                 6.0 * pa_zzz[j] * fx[j] * pb_yzz[j] + 0.75 * fx[j] * fx[j] * pb_yzzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_yzzz[j] + 

                                 pa_zzzz[j] * pb_yzzz[j]) * s_0_0[j] + (75.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_y[j] - 

                                 9.0 * pa_z[j] * fx[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] - 9.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_y[j] - 

                                 13.5 * fx[j] * fx[j] * fz[j] * fga[j] * pb_yz[j] - 6.0 * pa_zzz[j] * fx[j] * pb_y[j] * fz[j] * fgb[j] + 

                                 56.25 * fx[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] + 36.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_y[j] + 

                                 162.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_yz[j] - 2.25 * fx[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 

                                 9.0 * pa_zz[j] * fx[j] * pb_yz[j] * fz[j] * fgb[j] - 9.0 * pa_zz[j] * fz[j] * fga[j] * pb_yz[j] * fx[j] - 

                                 18.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_yzz[j] - 3.0 * pa_zzzz[j] * pb_yz[j] * fz[j] * fgb[j] + 

                                 108.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_yzz[j] + 21.0 * pa_zzzz[j] * fz[j] * pb_yz[j] * fx[j] + 

                                 84.0 * pa_zzz[j] * fz[j] * fx[j] * pb_yzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_yzzz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_yzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_yzzz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_yzzz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_yzzz[j]) * r_0_0[j];

                t_zzzz_zzzz[j] = (6.5625 * fx[j] * fx[j] * fx[j] * fx[j] + 11.25 * pa_zz[j] * fx[j] * fx[j] * fx[j] + 

                                 30.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * pb_z[j] + 11.25 * fx[j] * fx[j] * fx[j] * pb_zz[j] + 0.75 * pa_zzzz[j] * fx[j] * fx[j] + 

                                 12.0 * pa_zzz[j] * fx[j] * fx[j] * pb_z[j] + 27.0 * pa_zz[j] * fx[j] * fx[j] * pb_zz[j] + 

                                 12.0 * pa_z[j] * fx[j] * fx[j] * pb_zzz[j] + 3.0 * pa_zzzz[j] * pb_zz[j] * fx[j] + 8.0 * pa_zzz[j] * fx[j] * pb_zzz[j] + 

                                 0.75 * fx[j] * fx[j] * pb_zzzz[j] + 3.0 * pa_zz[j] * fx[j] * pb_zzzz[j] + pa_zzzz[j] * pb_zzzz[j]) * s_0_0[j] + (52.5 * fx[j] * fx[j] * fx[j] * fx[j] * fz[j] - 

                                 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fgb[j] - 11.25 * fx[j] * fx[j] * fx[j] * fz[j] * fga[j] - 

                                 27.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * fgb[j] + 112.5 * pa_zz[j] * fx[j] * fx[j] * fx[j] * fz[j] + 

                                 300.0 * pa_z[j] * fx[j] * fx[j] * fx[j] * fz[j] * pb_z[j] - 4.5 * pa_zz[j] * fz[j] * fga[j] * fx[j] * fx[j] - 

                                 36.0 * pa_z[j] * fx[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] - 36.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * fga[j] * pb_z[j] - 

                                 27.0 * fx[j] * fx[j] * fz[j] * fga[j] * pb_zz[j] - 3.0 * pa_zzzz[j] * fx[j] * fz[j] * fgb[j] - 

                                 24.0 * pa_zzz[j] * fx[j] * pb_z[j] * fz[j] * fgb[j] + 112.5 * fx[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] + 

                                 9.0 * pa_zzzz[j] * fz[j] * fx[j] * fx[j] + 144.0 * pa_zzz[j] * fz[j] * fx[j] * fx[j] * pb_z[j] + 

                                 324.0 * pa_zz[j] * fx[j] * fx[j] * fz[j] * pb_zz[j] - 4.5 * fx[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 

                                 18.0 * pa_zz[j] * fx[j] * pb_zz[j] * fz[j] * fgb[j] - 18.0 * pa_zz[j] * fz[j] * fga[j] * pb_zz[j] * fx[j] - 

                                 24.0 * pa_z[j] * fx[j] * fz[j] * fga[j] * pb_zzz[j] - 6.0 * pa_zzzz[j] * pb_zz[j] * fz[j] * fgb[j] + 

                                 144.0 * pa_z[j] * fx[j] * fx[j] * fz[j] * pb_zzz[j] + 42.0 * pa_zzzz[j] * fz[j] * pb_zz[j] * fx[j] + 

                                 112.0 * pa_zzz[j] * fz[j] * fx[j] * pb_zzz[j] - 3.0 * fx[j] * fz[j] * fga[j] * pb_zzzz[j] - 

                                 6.0 * pa_zz[j] * fz[j] * fga[j] * pb_zzzz[j] + 9.0 * fx[j] * fx[j] * fz[j] * pb_zzzz[j] + 

                                 42.0 * pa_zz[j] * fz[j] * fx[j] * pb_zzzz[j] + 16.0 * pa_zzzz[j] * fz[j] * pb_zzzz[j]) * r_0_0[j];
            }

            idx++;
        }
    }


} // kinrecfunc namespace

