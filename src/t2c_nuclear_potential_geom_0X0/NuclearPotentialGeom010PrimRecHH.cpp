#include "NuclearPotentialGeom010PrimRecHH.hpp"

namespace npotrec { // npotrec namespace

auto
comp_prim_nuclear_potential_geom_010_hh(CSimdArray<double>& pbuffer, 
                                        const size_t idx_npot_geom_010_0_hh,
                                        const size_t idx_npot_geom_010_0_fh,
                                        const size_t idx_npot_geom_010_1_fh,
                                        const size_t idx_npot_geom_010_0_gg,
                                        const size_t idx_npot_geom_010_1_gg,
                                        const size_t idx_npot_1_gh,
                                        const size_t idx_npot_geom_010_0_gh,
                                        const size_t idx_npot_geom_010_1_gh,
                                        const CSimdArray<double>& factors,
                                        const size_t idx_rpa,
                                        const size_t idx_rpc,
                                        const double a_exp) -> void
{
    const auto nelems = pbuffer.number_of_active_elements();

    // Set up exponents

    auto b_exps = factors.data(0);

    // Set up R(PA) distances

    auto pa_x = factors.data(idx_rpa);

    auto pa_y = factors.data(idx_rpa + 1);

    auto pa_z = factors.data(idx_rpa + 2);

    // Set up R(PC) distances

    auto pc_x = factors.data(idx_rpc);

    auto pc_y = factors.data(idx_rpc + 1);

    auto pc_z = factors.data(idx_rpc + 2);

    // Set up components of auxiliary buffer : FH

    auto ta1_x_xxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh);

    auto ta1_x_xxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 1);

    auto ta1_x_xxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 2);

    auto ta1_x_xxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 3);

    auto ta1_x_xxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 4);

    auto ta1_x_xxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 5);

    auto ta1_x_xxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 6);

    auto ta1_x_xxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 7);

    auto ta1_x_xxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 8);

    auto ta1_x_xxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 9);

    auto ta1_x_xxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 10);

    auto ta1_x_xxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 11);

    auto ta1_x_xxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 12);

    auto ta1_x_xxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 13);

    auto ta1_x_xxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 14);

    auto ta1_x_xxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 15);

    auto ta1_x_xxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 16);

    auto ta1_x_xxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 17);

    auto ta1_x_xxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 18);

    auto ta1_x_xxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 19);

    auto ta1_x_xxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 20);

    auto ta1_x_xxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 21);

    auto ta1_x_xxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 22);

    auto ta1_x_xxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 23);

    auto ta1_x_xxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 24);

    auto ta1_x_xxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 25);

    auto ta1_x_xxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 26);

    auto ta1_x_xxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 27);

    auto ta1_x_xxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 28);

    auto ta1_x_xxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 29);

    auto ta1_x_xxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 30);

    auto ta1_x_xxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 31);

    auto ta1_x_xxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 32);

    auto ta1_x_xxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 33);

    auto ta1_x_xxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 34);

    auto ta1_x_xxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 35);

    auto ta1_x_xxy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 41);

    auto ta1_x_xxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 42);

    auto ta1_x_xxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 43);

    auto ta1_x_xxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 44);

    auto ta1_x_xxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 45);

    auto ta1_x_xxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 46);

    auto ta1_x_xxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 47);

    auto ta1_x_xxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 48);

    auto ta1_x_xxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 49);

    auto ta1_x_xxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 50);

    auto ta1_x_xxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 51);

    auto ta1_x_xxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 52);

    auto ta1_x_xxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 53);

    auto ta1_x_xxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 54);

    auto ta1_x_xxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 55);

    auto ta1_x_xxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 56);

    auto ta1_x_xxz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 57);

    auto ta1_x_xxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 62);

    auto ta1_x_xyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 63);

    auto ta1_x_xyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 64);

    auto ta1_x_xyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 65);

    auto ta1_x_xyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 66);

    auto ta1_x_xyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 68);

    auto ta1_x_xyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 69);

    auto ta1_x_xyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 72);

    auto ta1_x_xyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 73);

    auto ta1_x_xyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 77);

    auto ta1_x_xyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 78);

    auto ta1_x_xyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 79);

    auto ta1_x_xyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 80);

    auto ta1_x_xyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 81);

    auto ta1_x_xyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 82);

    auto ta1_x_xyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 86);

    auto ta1_x_xyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 89);

    auto ta1_x_xyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 93);

    auto ta1_x_xyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 98);

    auto ta1_x_xzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 105);

    auto ta1_x_xzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 106);

    auto ta1_x_xzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 107);

    auto ta1_x_xzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 108);

    auto ta1_x_xzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 110);

    auto ta1_x_xzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 111);

    auto ta1_x_xzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 114);

    auto ta1_x_xzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 115);

    auto ta1_x_xzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 119);

    auto ta1_x_xzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 121);

    auto ta1_x_xzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 122);

    auto ta1_x_xzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 123);

    auto ta1_x_xzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 124);

    auto ta1_x_xzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 125);

    auto ta1_x_yyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 126);

    auto ta1_x_yyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 127);

    auto ta1_x_yyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 128);

    auto ta1_x_yyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 129);

    auto ta1_x_yyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 130);

    auto ta1_x_yyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 131);

    auto ta1_x_yyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 132);

    auto ta1_x_yyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 133);

    auto ta1_x_yyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 134);

    auto ta1_x_yyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 135);

    auto ta1_x_yyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 136);

    auto ta1_x_yyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 137);

    auto ta1_x_yyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 138);

    auto ta1_x_yyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 139);

    auto ta1_x_yyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 140);

    auto ta1_x_yyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 141);

    auto ta1_x_yyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 142);

    auto ta1_x_yyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 143);

    auto ta1_x_yyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 144);

    auto ta1_x_yyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 145);

    auto ta1_x_yyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 146);

    auto ta1_x_yyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 148);

    auto ta1_x_yyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 149);

    auto ta1_x_yyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 150);

    auto ta1_x_yyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 152);

    auto ta1_x_yyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 153);

    auto ta1_x_yyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 156);

    auto ta1_x_yyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 157);

    auto ta1_x_yyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 161);

    auto ta1_x_yyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 162);

    auto ta1_x_yyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 167);

    auto ta1_x_yzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 168);

    auto ta1_x_yzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 170);

    auto ta1_x_yzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 172);

    auto ta1_x_yzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 173);

    auto ta1_x_yzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 175);

    auto ta1_x_yzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 176);

    auto ta1_x_yzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 177);

    auto ta1_x_yzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 179);

    auto ta1_x_yzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 180);

    auto ta1_x_yzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 181);

    auto ta1_x_yzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 182);

    auto ta1_x_yzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 184);

    auto ta1_x_yzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 185);

    auto ta1_x_yzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 186);

    auto ta1_x_yzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 187);

    auto ta1_x_yzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 188);

    auto ta1_x_zzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 189);

    auto ta1_x_zzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 190);

    auto ta1_x_zzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 191);

    auto ta1_x_zzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 192);

    auto ta1_x_zzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 193);

    auto ta1_x_zzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 194);

    auto ta1_x_zzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 195);

    auto ta1_x_zzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 196);

    auto ta1_x_zzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 197);

    auto ta1_x_zzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 198);

    auto ta1_x_zzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 199);

    auto ta1_x_zzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 200);

    auto ta1_x_zzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 201);

    auto ta1_x_zzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 202);

    auto ta1_x_zzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 203);

    auto ta1_x_zzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 204);

    auto ta1_x_zzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 205);

    auto ta1_x_zzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 206);

    auto ta1_x_zzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 207);

    auto ta1_x_zzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 208);

    auto ta1_x_zzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 209);

    auto ta1_y_xxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 210);

    auto ta1_y_xxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 211);

    auto ta1_y_xxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 212);

    auto ta1_y_xxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 213);

    auto ta1_y_xxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 214);

    auto ta1_y_xxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 215);

    auto ta1_y_xxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 216);

    auto ta1_y_xxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 217);

    auto ta1_y_xxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 218);

    auto ta1_y_xxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 219);

    auto ta1_y_xxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 220);

    auto ta1_y_xxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 221);

    auto ta1_y_xxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 222);

    auto ta1_y_xxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 223);

    auto ta1_y_xxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 224);

    auto ta1_y_xxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 225);

    auto ta1_y_xxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 226);

    auto ta1_y_xxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 227);

    auto ta1_y_xxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 228);

    auto ta1_y_xxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 229);

    auto ta1_y_xxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 230);

    auto ta1_y_xxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 231);

    auto ta1_y_xxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 232);

    auto ta1_y_xxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 233);

    auto ta1_y_xxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 234);

    auto ta1_y_xxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 236);

    auto ta1_y_xxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 237);

    auto ta1_y_xxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 240);

    auto ta1_y_xxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 241);

    auto ta1_y_xxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 245);

    auto ta1_y_xxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 246);

    auto ta1_y_xxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 247);

    auto ta1_y_xxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 248);

    auto ta1_y_xxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 249);

    auto ta1_y_xxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 250);

    auto ta1_y_xxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 252);

    auto ta1_y_xxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 253);

    auto ta1_y_xxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 255);

    auto ta1_y_xxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 258);

    auto ta1_y_xxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 262);

    auto ta1_y_xxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 268);

    auto ta1_y_xxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 269);

    auto ta1_y_xxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 270);

    auto ta1_y_xxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 271);

    auto ta1_y_xxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 272);

    auto ta1_y_xyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 274);

    auto ta1_y_xyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 276);

    auto ta1_y_xyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 277);

    auto ta1_y_xyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 279);

    auto ta1_y_xyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 280);

    auto ta1_y_xyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 281);

    auto ta1_y_xyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 283);

    auto ta1_y_xyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 284);

    auto ta1_y_xyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 285);

    auto ta1_y_xyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 286);

    auto ta1_y_xyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 288);

    auto ta1_y_xyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 289);

    auto ta1_y_xyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 290);

    auto ta1_y_xyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 291);

    auto ta1_y_xyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 292);

    auto ta1_y_xyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 293);

    auto ta1_y_xyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 310);

    auto ta1_y_xyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 311);

    auto ta1_y_xyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 312);

    auto ta1_y_xyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 313);

    auto ta1_y_xzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 317);

    auto ta1_y_xzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 319);

    auto ta1_y_xzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 320);

    auto ta1_y_xzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 322);

    auto ta1_y_xzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 323);

    auto ta1_y_xzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 324);

    auto ta1_y_xzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 326);

    auto ta1_y_xzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 327);

    auto ta1_y_xzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 328);

    auto ta1_y_xzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 329);

    auto ta1_y_xzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 330);

    auto ta1_y_xzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 331);

    auto ta1_y_xzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 332);

    auto ta1_y_xzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 333);

    auto ta1_y_xzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 334);

    auto ta1_y_xzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 335);

    auto ta1_y_yyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 336);

    auto ta1_y_yyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 337);

    auto ta1_y_yyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 338);

    auto ta1_y_yyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 339);

    auto ta1_y_yyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 340);

    auto ta1_y_yyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 341);

    auto ta1_y_yyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 342);

    auto ta1_y_yyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 343);

    auto ta1_y_yyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 344);

    auto ta1_y_yyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 345);

    auto ta1_y_yyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 346);

    auto ta1_y_yyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 347);

    auto ta1_y_yyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 348);

    auto ta1_y_yyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 349);

    auto ta1_y_yyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 350);

    auto ta1_y_yyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 351);

    auto ta1_y_yyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 352);

    auto ta1_y_yyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 353);

    auto ta1_y_yyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 354);

    auto ta1_y_yyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 355);

    auto ta1_y_yyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 356);

    auto ta1_y_yyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 357);

    auto ta1_y_yyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 358);

    auto ta1_y_yyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 360);

    auto ta1_y_yyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 361);

    auto ta1_y_yyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 363);

    auto ta1_y_yyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 364);

    auto ta1_y_yyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 365);

    auto ta1_y_yyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 367);

    auto ta1_y_yyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 368);

    auto ta1_y_yyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 369);

    auto ta1_y_yyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 370);

    auto ta1_y_yyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 372);

    auto ta1_y_yyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 373);

    auto ta1_y_yyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 374);

    auto ta1_y_yyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 375);

    auto ta1_y_yyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 376);

    auto ta1_y_yyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 377);

    auto ta1_y_yzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 379);

    auto ta1_y_yzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 380);

    auto ta1_y_yzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 381);

    auto ta1_y_yzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 383);

    auto ta1_y_yzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 384);

    auto ta1_y_yzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 387);

    auto ta1_y_yzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 388);

    auto ta1_y_yzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 392);

    auto ta1_y_yzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 393);

    auto ta1_y_yzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 394);

    auto ta1_y_yzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 395);

    auto ta1_y_yzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 396);

    auto ta1_y_yzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 397);

    auto ta1_y_yzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 398);

    auto ta1_y_zzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 399);

    auto ta1_y_zzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 400);

    auto ta1_y_zzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 401);

    auto ta1_y_zzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 402);

    auto ta1_y_zzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 403);

    auto ta1_y_zzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 404);

    auto ta1_y_zzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 405);

    auto ta1_y_zzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 406);

    auto ta1_y_zzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 407);

    auto ta1_y_zzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 408);

    auto ta1_y_zzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 409);

    auto ta1_y_zzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 410);

    auto ta1_y_zzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 411);

    auto ta1_y_zzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 412);

    auto ta1_y_zzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 413);

    auto ta1_y_zzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 414);

    auto ta1_y_zzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 415);

    auto ta1_y_zzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 416);

    auto ta1_y_zzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 417);

    auto ta1_y_zzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 418);

    auto ta1_y_zzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 419);

    auto ta1_z_xxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 420);

    auto ta1_z_xxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 421);

    auto ta1_z_xxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 422);

    auto ta1_z_xxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 423);

    auto ta1_z_xxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 424);

    auto ta1_z_xxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 425);

    auto ta1_z_xxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 426);

    auto ta1_z_xxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 427);

    auto ta1_z_xxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 428);

    auto ta1_z_xxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 429);

    auto ta1_z_xxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 430);

    auto ta1_z_xxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 431);

    auto ta1_z_xxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 432);

    auto ta1_z_xxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 433);

    auto ta1_z_xxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 434);

    auto ta1_z_xxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 435);

    auto ta1_z_xxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 436);

    auto ta1_z_xxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 437);

    auto ta1_z_xxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 438);

    auto ta1_z_xxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 439);

    auto ta1_z_xxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 440);

    auto ta1_z_xxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 441);

    auto ta1_z_xxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 443);

    auto ta1_z_xxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 446);

    auto ta1_z_xxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 450);

    auto ta1_z_xxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 455);

    auto ta1_z_xxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 456);

    auto ta1_z_xxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 457);

    auto ta1_z_xxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 458);

    auto ta1_z_xxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 459);

    auto ta1_z_xxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 460);

    auto ta1_z_xxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 462);

    auto ta1_z_xxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 463);

    auto ta1_z_xxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 464);

    auto ta1_z_xxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 465);

    auto ta1_z_xxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 467);

    auto ta1_z_xxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 468);

    auto ta1_z_xxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 471);

    auto ta1_z_xxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 472);

    auto ta1_z_xxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 476);

    auto ta1_z_xxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 478);

    auto ta1_z_xxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 479);

    auto ta1_z_xxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 480);

    auto ta1_z_xxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 481);

    auto ta1_z_xxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 482);

    auto ta1_z_xyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 484);

    auto ta1_z_xyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 486);

    auto ta1_z_xyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 487);

    auto ta1_z_xyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 489);

    auto ta1_z_xyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 490);

    auto ta1_z_xyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 491);

    auto ta1_z_xyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 493);

    auto ta1_z_xyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 494);

    auto ta1_z_xyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 495);

    auto ta1_z_xyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 496);

    auto ta1_z_xyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 498);

    auto ta1_z_xyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 499);

    auto ta1_z_xyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 500);

    auto ta1_z_xyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 501);

    auto ta1_z_xyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 502);

    auto ta1_z_xyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 503);

    auto ta1_z_xyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 520);

    auto ta1_z_xyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 521);

    auto ta1_z_xyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 522);

    auto ta1_z_xyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 523);

    auto ta1_z_xzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 527);

    auto ta1_z_xzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 529);

    auto ta1_z_xzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 530);

    auto ta1_z_xzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 532);

    auto ta1_z_xzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 533);

    auto ta1_z_xzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 534);

    auto ta1_z_xzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 536);

    auto ta1_z_xzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 537);

    auto ta1_z_xzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 538);

    auto ta1_z_xzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 539);

    auto ta1_z_xzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 540);

    auto ta1_z_xzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 541);

    auto ta1_z_xzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 542);

    auto ta1_z_xzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 543);

    auto ta1_z_xzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 544);

    auto ta1_z_xzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 545);

    auto ta1_z_yyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 546);

    auto ta1_z_yyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 547);

    auto ta1_z_yyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 548);

    auto ta1_z_yyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 549);

    auto ta1_z_yyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 550);

    auto ta1_z_yyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 551);

    auto ta1_z_yyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 552);

    auto ta1_z_yyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 553);

    auto ta1_z_yyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 554);

    auto ta1_z_yyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 555);

    auto ta1_z_yyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 556);

    auto ta1_z_yyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 557);

    auto ta1_z_yyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 558);

    auto ta1_z_yyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 559);

    auto ta1_z_yyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 560);

    auto ta1_z_yyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 561);

    auto ta1_z_yyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 562);

    auto ta1_z_yyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 563);

    auto ta1_z_yyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 564);

    auto ta1_z_yyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 565);

    auto ta1_z_yyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 566);

    auto ta1_z_yyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 568);

    auto ta1_z_yyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 569);

    auto ta1_z_yyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 570);

    auto ta1_z_yyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 572);

    auto ta1_z_yyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 573);

    auto ta1_z_yyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 576);

    auto ta1_z_yyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 577);

    auto ta1_z_yyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 581);

    auto ta1_z_yyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 582);

    auto ta1_z_yyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 583);

    auto ta1_z_yyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 584);

    auto ta1_z_yyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 585);

    auto ta1_z_yyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 586);

    auto ta1_z_yyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 587);

    auto ta1_z_yzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 588);

    auto ta1_z_yzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 590);

    auto ta1_z_yzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 592);

    auto ta1_z_yzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 593);

    auto ta1_z_yzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 595);

    auto ta1_z_yzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 596);

    auto ta1_z_yzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 597);

    auto ta1_z_yzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 599);

    auto ta1_z_yzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 600);

    auto ta1_z_yzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 601);

    auto ta1_z_yzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 602);

    auto ta1_z_yzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 603);

    auto ta1_z_yzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 604);

    auto ta1_z_yzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 605);

    auto ta1_z_yzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 606);

    auto ta1_z_yzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 607);

    auto ta1_z_yzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 608);

    auto ta1_z_zzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_fh + 609);

    auto ta1_z_zzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 610);

    auto ta1_z_zzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 611);

    auto ta1_z_zzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 612);

    auto ta1_z_zzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 613);

    auto ta1_z_zzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 614);

    auto ta1_z_zzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 615);

    auto ta1_z_zzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 616);

    auto ta1_z_zzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 617);

    auto ta1_z_zzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 618);

    auto ta1_z_zzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 619);

    auto ta1_z_zzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 620);

    auto ta1_z_zzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 621);

    auto ta1_z_zzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 622);

    auto ta1_z_zzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 623);

    auto ta1_z_zzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_fh + 624);

    auto ta1_z_zzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 625);

    auto ta1_z_zzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 626);

    auto ta1_z_zzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 627);

    auto ta1_z_zzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 628);

    auto ta1_z_zzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_fh + 629);

    // Set up components of auxiliary buffer : FH

    auto ta1_x_xxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh);

    auto ta1_x_xxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 1);

    auto ta1_x_xxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 2);

    auto ta1_x_xxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 3);

    auto ta1_x_xxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 4);

    auto ta1_x_xxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 5);

    auto ta1_x_xxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 6);

    auto ta1_x_xxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 7);

    auto ta1_x_xxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 8);

    auto ta1_x_xxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 9);

    auto ta1_x_xxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 10);

    auto ta1_x_xxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 11);

    auto ta1_x_xxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 12);

    auto ta1_x_xxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 13);

    auto ta1_x_xxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 14);

    auto ta1_x_xxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 15);

    auto ta1_x_xxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 16);

    auto ta1_x_xxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 17);

    auto ta1_x_xxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 18);

    auto ta1_x_xxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 19);

    auto ta1_x_xxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 20);

    auto ta1_x_xxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 21);

    auto ta1_x_xxy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 22);

    auto ta1_x_xxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 23);

    auto ta1_x_xxy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 24);

    auto ta1_x_xxy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 25);

    auto ta1_x_xxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 26);

    auto ta1_x_xxy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 27);

    auto ta1_x_xxy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 28);

    auto ta1_x_xxy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 29);

    auto ta1_x_xxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 30);

    auto ta1_x_xxy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 31);

    auto ta1_x_xxy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 32);

    auto ta1_x_xxy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 33);

    auto ta1_x_xxy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 34);

    auto ta1_x_xxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 35);

    auto ta1_x_xxy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 41);

    auto ta1_x_xxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 42);

    auto ta1_x_xxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 43);

    auto ta1_x_xxz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 44);

    auto ta1_x_xxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 45);

    auto ta1_x_xxz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 46);

    auto ta1_x_xxz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 47);

    auto ta1_x_xxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 48);

    auto ta1_x_xxz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 49);

    auto ta1_x_xxz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 50);

    auto ta1_x_xxz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 51);

    auto ta1_x_xxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 52);

    auto ta1_x_xxz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 53);

    auto ta1_x_xxz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 54);

    auto ta1_x_xxz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 55);

    auto ta1_x_xxz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 56);

    auto ta1_x_xxz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 57);

    auto ta1_x_xxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 62);

    auto ta1_x_xyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 63);

    auto ta1_x_xyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 64);

    auto ta1_x_xyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 65);

    auto ta1_x_xyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 66);

    auto ta1_x_xyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 68);

    auto ta1_x_xyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 69);

    auto ta1_x_xyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 72);

    auto ta1_x_xyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 73);

    auto ta1_x_xyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 77);

    auto ta1_x_xyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 78);

    auto ta1_x_xyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 79);

    auto ta1_x_xyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 80);

    auto ta1_x_xyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 81);

    auto ta1_x_xyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 82);

    auto ta1_x_xyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 86);

    auto ta1_x_xyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 89);

    auto ta1_x_xyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 93);

    auto ta1_x_xyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 98);

    auto ta1_x_xzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 105);

    auto ta1_x_xzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 106);

    auto ta1_x_xzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 107);

    auto ta1_x_xzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 108);

    auto ta1_x_xzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 110);

    auto ta1_x_xzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 111);

    auto ta1_x_xzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 114);

    auto ta1_x_xzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 115);

    auto ta1_x_xzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 119);

    auto ta1_x_xzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 121);

    auto ta1_x_xzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 122);

    auto ta1_x_xzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 123);

    auto ta1_x_xzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 124);

    auto ta1_x_xzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 125);

    auto ta1_x_yyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 126);

    auto ta1_x_yyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 127);

    auto ta1_x_yyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 128);

    auto ta1_x_yyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 129);

    auto ta1_x_yyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 130);

    auto ta1_x_yyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 131);

    auto ta1_x_yyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 132);

    auto ta1_x_yyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 133);

    auto ta1_x_yyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 134);

    auto ta1_x_yyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 135);

    auto ta1_x_yyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 136);

    auto ta1_x_yyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 137);

    auto ta1_x_yyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 138);

    auto ta1_x_yyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 139);

    auto ta1_x_yyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 140);

    auto ta1_x_yyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 141);

    auto ta1_x_yyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 142);

    auto ta1_x_yyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 143);

    auto ta1_x_yyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 144);

    auto ta1_x_yyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 145);

    auto ta1_x_yyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 146);

    auto ta1_x_yyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 148);

    auto ta1_x_yyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 149);

    auto ta1_x_yyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 150);

    auto ta1_x_yyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 152);

    auto ta1_x_yyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 153);

    auto ta1_x_yyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 156);

    auto ta1_x_yyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 157);

    auto ta1_x_yyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 161);

    auto ta1_x_yyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 162);

    auto ta1_x_yyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 167);

    auto ta1_x_yzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 168);

    auto ta1_x_yzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 170);

    auto ta1_x_yzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 172);

    auto ta1_x_yzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 173);

    auto ta1_x_yzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 175);

    auto ta1_x_yzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 176);

    auto ta1_x_yzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 177);

    auto ta1_x_yzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 179);

    auto ta1_x_yzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 180);

    auto ta1_x_yzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 181);

    auto ta1_x_yzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 182);

    auto ta1_x_yzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 184);

    auto ta1_x_yzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 185);

    auto ta1_x_yzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 186);

    auto ta1_x_yzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 187);

    auto ta1_x_yzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 188);

    auto ta1_x_zzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 189);

    auto ta1_x_zzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 190);

    auto ta1_x_zzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 191);

    auto ta1_x_zzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 192);

    auto ta1_x_zzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 193);

    auto ta1_x_zzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 194);

    auto ta1_x_zzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 195);

    auto ta1_x_zzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 196);

    auto ta1_x_zzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 197);

    auto ta1_x_zzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 198);

    auto ta1_x_zzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 199);

    auto ta1_x_zzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 200);

    auto ta1_x_zzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 201);

    auto ta1_x_zzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 202);

    auto ta1_x_zzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 203);

    auto ta1_x_zzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 204);

    auto ta1_x_zzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 205);

    auto ta1_x_zzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 206);

    auto ta1_x_zzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 207);

    auto ta1_x_zzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 208);

    auto ta1_x_zzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 209);

    auto ta1_y_xxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 210);

    auto ta1_y_xxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 211);

    auto ta1_y_xxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 212);

    auto ta1_y_xxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 213);

    auto ta1_y_xxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 214);

    auto ta1_y_xxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 215);

    auto ta1_y_xxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 216);

    auto ta1_y_xxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 217);

    auto ta1_y_xxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 218);

    auto ta1_y_xxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 219);

    auto ta1_y_xxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 220);

    auto ta1_y_xxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 221);

    auto ta1_y_xxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 222);

    auto ta1_y_xxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 223);

    auto ta1_y_xxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 224);

    auto ta1_y_xxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 225);

    auto ta1_y_xxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 226);

    auto ta1_y_xxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 227);

    auto ta1_y_xxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 228);

    auto ta1_y_xxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 229);

    auto ta1_y_xxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 230);

    auto ta1_y_xxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 231);

    auto ta1_y_xxy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 232);

    auto ta1_y_xxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 233);

    auto ta1_y_xxy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 234);

    auto ta1_y_xxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 236);

    auto ta1_y_xxy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 237);

    auto ta1_y_xxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 240);

    auto ta1_y_xxy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 241);

    auto ta1_y_xxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 245);

    auto ta1_y_xxy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 246);

    auto ta1_y_xxy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 247);

    auto ta1_y_xxy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 248);

    auto ta1_y_xxy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 249);

    auto ta1_y_xxy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 250);

    auto ta1_y_xxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 252);

    auto ta1_y_xxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 253);

    auto ta1_y_xxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 255);

    auto ta1_y_xxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 258);

    auto ta1_y_xxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 262);

    auto ta1_y_xxz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 268);

    auto ta1_y_xxz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 269);

    auto ta1_y_xxz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 270);

    auto ta1_y_xxz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 271);

    auto ta1_y_xxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 272);

    auto ta1_y_xyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 274);

    auto ta1_y_xyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 276);

    auto ta1_y_xyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 277);

    auto ta1_y_xyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 279);

    auto ta1_y_xyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 280);

    auto ta1_y_xyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 281);

    auto ta1_y_xyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 283);

    auto ta1_y_xyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 284);

    auto ta1_y_xyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 285);

    auto ta1_y_xyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 286);

    auto ta1_y_xyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 288);

    auto ta1_y_xyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 289);

    auto ta1_y_xyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 290);

    auto ta1_y_xyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 291);

    auto ta1_y_xyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 292);

    auto ta1_y_xyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 293);

    auto ta1_y_xyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 310);

    auto ta1_y_xyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 311);

    auto ta1_y_xyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 312);

    auto ta1_y_xyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 313);

    auto ta1_y_xzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 317);

    auto ta1_y_xzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 319);

    auto ta1_y_xzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 320);

    auto ta1_y_xzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 322);

    auto ta1_y_xzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 323);

    auto ta1_y_xzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 324);

    auto ta1_y_xzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 326);

    auto ta1_y_xzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 327);

    auto ta1_y_xzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 328);

    auto ta1_y_xzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 329);

    auto ta1_y_xzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 330);

    auto ta1_y_xzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 331);

    auto ta1_y_xzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 332);

    auto ta1_y_xzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 333);

    auto ta1_y_xzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 334);

    auto ta1_y_xzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 335);

    auto ta1_y_yyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 336);

    auto ta1_y_yyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 337);

    auto ta1_y_yyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 338);

    auto ta1_y_yyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 339);

    auto ta1_y_yyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 340);

    auto ta1_y_yyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 341);

    auto ta1_y_yyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 342);

    auto ta1_y_yyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 343);

    auto ta1_y_yyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 344);

    auto ta1_y_yyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 345);

    auto ta1_y_yyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 346);

    auto ta1_y_yyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 347);

    auto ta1_y_yyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 348);

    auto ta1_y_yyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 349);

    auto ta1_y_yyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 350);

    auto ta1_y_yyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 351);

    auto ta1_y_yyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 352);

    auto ta1_y_yyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 353);

    auto ta1_y_yyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 354);

    auto ta1_y_yyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 355);

    auto ta1_y_yyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 356);

    auto ta1_y_yyz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 357);

    auto ta1_y_yyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 358);

    auto ta1_y_yyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 360);

    auto ta1_y_yyz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 361);

    auto ta1_y_yyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 363);

    auto ta1_y_yyz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 364);

    auto ta1_y_yyz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 365);

    auto ta1_y_yyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 367);

    auto ta1_y_yyz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 368);

    auto ta1_y_yyz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 369);

    auto ta1_y_yyz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 370);

    auto ta1_y_yyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 372);

    auto ta1_y_yyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 373);

    auto ta1_y_yyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 374);

    auto ta1_y_yyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 375);

    auto ta1_y_yyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 376);

    auto ta1_y_yyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 377);

    auto ta1_y_yzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 379);

    auto ta1_y_yzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 380);

    auto ta1_y_yzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 381);

    auto ta1_y_yzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 383);

    auto ta1_y_yzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 384);

    auto ta1_y_yzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 387);

    auto ta1_y_yzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 388);

    auto ta1_y_yzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 392);

    auto ta1_y_yzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 393);

    auto ta1_y_yzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 394);

    auto ta1_y_yzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 395);

    auto ta1_y_yzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 396);

    auto ta1_y_yzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 397);

    auto ta1_y_yzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 398);

    auto ta1_y_zzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 399);

    auto ta1_y_zzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 400);

    auto ta1_y_zzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 401);

    auto ta1_y_zzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 402);

    auto ta1_y_zzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 403);

    auto ta1_y_zzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 404);

    auto ta1_y_zzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 405);

    auto ta1_y_zzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 406);

    auto ta1_y_zzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 407);

    auto ta1_y_zzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 408);

    auto ta1_y_zzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 409);

    auto ta1_y_zzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 410);

    auto ta1_y_zzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 411);

    auto ta1_y_zzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 412);

    auto ta1_y_zzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 413);

    auto ta1_y_zzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 414);

    auto ta1_y_zzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 415);

    auto ta1_y_zzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 416);

    auto ta1_y_zzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 417);

    auto ta1_y_zzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 418);

    auto ta1_y_zzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 419);

    auto ta1_z_xxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 420);

    auto ta1_z_xxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 421);

    auto ta1_z_xxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 422);

    auto ta1_z_xxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 423);

    auto ta1_z_xxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 424);

    auto ta1_z_xxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 425);

    auto ta1_z_xxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 426);

    auto ta1_z_xxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 427);

    auto ta1_z_xxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 428);

    auto ta1_z_xxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 429);

    auto ta1_z_xxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 430);

    auto ta1_z_xxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 431);

    auto ta1_z_xxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 432);

    auto ta1_z_xxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 433);

    auto ta1_z_xxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 434);

    auto ta1_z_xxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 435);

    auto ta1_z_xxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 436);

    auto ta1_z_xxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 437);

    auto ta1_z_xxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 438);

    auto ta1_z_xxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 439);

    auto ta1_z_xxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 440);

    auto ta1_z_xxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 441);

    auto ta1_z_xxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 443);

    auto ta1_z_xxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 446);

    auto ta1_z_xxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 450);

    auto ta1_z_xxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 455);

    auto ta1_z_xxy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 456);

    auto ta1_z_xxy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 457);

    auto ta1_z_xxy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 458);

    auto ta1_z_xxy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 459);

    auto ta1_z_xxy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 460);

    auto ta1_z_xxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 462);

    auto ta1_z_xxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 463);

    auto ta1_z_xxz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 464);

    auto ta1_z_xxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 465);

    auto ta1_z_xxz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 467);

    auto ta1_z_xxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 468);

    auto ta1_z_xxz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 471);

    auto ta1_z_xxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 472);

    auto ta1_z_xxz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 476);

    auto ta1_z_xxz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 478);

    auto ta1_z_xxz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 479);

    auto ta1_z_xxz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 480);

    auto ta1_z_xxz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 481);

    auto ta1_z_xxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 482);

    auto ta1_z_xyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 484);

    auto ta1_z_xyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 486);

    auto ta1_z_xyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 487);

    auto ta1_z_xyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 489);

    auto ta1_z_xyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 490);

    auto ta1_z_xyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 491);

    auto ta1_z_xyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 493);

    auto ta1_z_xyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 494);

    auto ta1_z_xyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 495);

    auto ta1_z_xyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 496);

    auto ta1_z_xyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 498);

    auto ta1_z_xyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 499);

    auto ta1_z_xyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 500);

    auto ta1_z_xyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 501);

    auto ta1_z_xyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 502);

    auto ta1_z_xyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 503);

    auto ta1_z_xyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 520);

    auto ta1_z_xyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 521);

    auto ta1_z_xyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 522);

    auto ta1_z_xyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 523);

    auto ta1_z_xzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 527);

    auto ta1_z_xzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 529);

    auto ta1_z_xzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 530);

    auto ta1_z_xzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 532);

    auto ta1_z_xzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 533);

    auto ta1_z_xzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 534);

    auto ta1_z_xzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 536);

    auto ta1_z_xzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 537);

    auto ta1_z_xzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 538);

    auto ta1_z_xzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 539);

    auto ta1_z_xzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 540);

    auto ta1_z_xzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 541);

    auto ta1_z_xzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 542);

    auto ta1_z_xzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 543);

    auto ta1_z_xzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 544);

    auto ta1_z_xzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 545);

    auto ta1_z_yyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 546);

    auto ta1_z_yyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 547);

    auto ta1_z_yyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 548);

    auto ta1_z_yyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 549);

    auto ta1_z_yyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 550);

    auto ta1_z_yyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 551);

    auto ta1_z_yyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 552);

    auto ta1_z_yyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 553);

    auto ta1_z_yyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 554);

    auto ta1_z_yyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 555);

    auto ta1_z_yyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 556);

    auto ta1_z_yyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 557);

    auto ta1_z_yyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 558);

    auto ta1_z_yyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 559);

    auto ta1_z_yyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 560);

    auto ta1_z_yyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 561);

    auto ta1_z_yyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 562);

    auto ta1_z_yyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 563);

    auto ta1_z_yyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 564);

    auto ta1_z_yyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 565);

    auto ta1_z_yyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 566);

    auto ta1_z_yyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 568);

    auto ta1_z_yyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 569);

    auto ta1_z_yyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 570);

    auto ta1_z_yyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 572);

    auto ta1_z_yyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 573);

    auto ta1_z_yyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 576);

    auto ta1_z_yyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 577);

    auto ta1_z_yyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 581);

    auto ta1_z_yyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 582);

    auto ta1_z_yyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 583);

    auto ta1_z_yyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 584);

    auto ta1_z_yyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 585);

    auto ta1_z_yyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 586);

    auto ta1_z_yyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 587);

    auto ta1_z_yzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 588);

    auto ta1_z_yzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 590);

    auto ta1_z_yzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 592);

    auto ta1_z_yzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 593);

    auto ta1_z_yzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 595);

    auto ta1_z_yzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 596);

    auto ta1_z_yzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 597);

    auto ta1_z_yzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 599);

    auto ta1_z_yzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 600);

    auto ta1_z_yzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 601);

    auto ta1_z_yzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 602);

    auto ta1_z_yzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 603);

    auto ta1_z_yzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 604);

    auto ta1_z_yzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 605);

    auto ta1_z_yzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 606);

    auto ta1_z_yzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 607);

    auto ta1_z_yzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 608);

    auto ta1_z_zzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_fh + 609);

    auto ta1_z_zzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 610);

    auto ta1_z_zzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 611);

    auto ta1_z_zzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 612);

    auto ta1_z_zzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 613);

    auto ta1_z_zzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 614);

    auto ta1_z_zzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 615);

    auto ta1_z_zzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 616);

    auto ta1_z_zzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 617);

    auto ta1_z_zzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 618);

    auto ta1_z_zzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 619);

    auto ta1_z_zzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 620);

    auto ta1_z_zzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 621);

    auto ta1_z_zzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 622);

    auto ta1_z_zzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 623);

    auto ta1_z_zzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_fh + 624);

    auto ta1_z_zzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 625);

    auto ta1_z_zzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 626);

    auto ta1_z_zzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 627);

    auto ta1_z_zzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 628);

    auto ta1_z_zzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_fh + 629);

    // Set up components of auxiliary buffer : GG

    auto ta1_x_xxxx_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg);

    auto ta1_x_xxxx_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 1);

    auto ta1_x_xxxx_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 2);

    auto ta1_x_xxxx_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 3);

    auto ta1_x_xxxx_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 4);

    auto ta1_x_xxxx_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 5);

    auto ta1_x_xxxx_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 6);

    auto ta1_x_xxxx_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 7);

    auto ta1_x_xxxx_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 8);

    auto ta1_x_xxxx_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 9);

    auto ta1_x_xxxx_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 10);

    auto ta1_x_xxxx_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 11);

    auto ta1_x_xxxx_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 12);

    auto ta1_x_xxxx_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 13);

    auto ta1_x_xxxx_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 14);

    auto ta1_x_xxxy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 15);

    auto ta1_x_xxxy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 16);

    auto ta1_x_xxxy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 17);

    auto ta1_x_xxxy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 18);

    auto ta1_x_xxxy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 19);

    auto ta1_x_xxxy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 20);

    auto ta1_x_xxxy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 21);

    auto ta1_x_xxxy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 22);

    auto ta1_x_xxxy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 23);

    auto ta1_x_xxxy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 24);

    auto ta1_x_xxxz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 30);

    auto ta1_x_xxxz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 31);

    auto ta1_x_xxxz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 32);

    auto ta1_x_xxxz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 33);

    auto ta1_x_xxxz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 34);

    auto ta1_x_xxxz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 35);

    auto ta1_x_xxxz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 36);

    auto ta1_x_xxxz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 37);

    auto ta1_x_xxxz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 38);

    auto ta1_x_xxxz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 39);

    auto ta1_x_xxxz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 41);

    auto ta1_x_xxxz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 42);

    auto ta1_x_xxxz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 43);

    auto ta1_x_xxxz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 44);

    auto ta1_x_xxyy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 45);

    auto ta1_x_xxyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 46);

    auto ta1_x_xxyy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 47);

    auto ta1_x_xxyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 48);

    auto ta1_x_xxyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 49);

    auto ta1_x_xxyy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 50);

    auto ta1_x_xxyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 51);

    auto ta1_x_xxyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 52);

    auto ta1_x_xxyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 53);

    auto ta1_x_xxyy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 54);

    auto ta1_x_xxyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 55);

    auto ta1_x_xxyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 56);

    auto ta1_x_xxyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 57);

    auto ta1_x_xxyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 58);

    auto ta1_x_xxzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 75);

    auto ta1_x_xxzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 76);

    auto ta1_x_xxzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 77);

    auto ta1_x_xxzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 78);

    auto ta1_x_xxzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 79);

    auto ta1_x_xxzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 80);

    auto ta1_x_xxzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 81);

    auto ta1_x_xxzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 82);

    auto ta1_x_xxzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 83);

    auto ta1_x_xxzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 84);

    auto ta1_x_xxzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 85);

    auto ta1_x_xxzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 86);

    auto ta1_x_xxzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 87);

    auto ta1_x_xxzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 88);

    auto ta1_x_xxzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 89);

    auto ta1_x_xyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 91);

    auto ta1_x_xyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 93);

    auto ta1_x_xyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 94);

    auto ta1_x_xyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 96);

    auto ta1_x_xyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 97);

    auto ta1_x_xyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 98);

    auto ta1_x_xzzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 135);

    auto ta1_x_xzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 136);

    auto ta1_x_xzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 137);

    auto ta1_x_xzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 138);

    auto ta1_x_xzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 139);

    auto ta1_x_xzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 140);

    auto ta1_x_xzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 141);

    auto ta1_x_xzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 142);

    auto ta1_x_xzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 143);

    auto ta1_x_xzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 144);

    auto ta1_x_yyyy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 150);

    auto ta1_x_yyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 151);

    auto ta1_x_yyyy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 152);

    auto ta1_x_yyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 153);

    auto ta1_x_yyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 154);

    auto ta1_x_yyyy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 155);

    auto ta1_x_yyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 156);

    auto ta1_x_yyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 157);

    auto ta1_x_yyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 158);

    auto ta1_x_yyyy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 159);

    auto ta1_x_yyyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 160);

    auto ta1_x_yyyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 161);

    auto ta1_x_yyyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 162);

    auto ta1_x_yyyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 163);

    auto ta1_x_yyyy_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 164);

    auto ta1_x_yyzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 182);

    auto ta1_x_yyzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 184);

    auto ta1_x_yyzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 185);

    auto ta1_x_yyzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 187);

    auto ta1_x_yyzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 188);

    auto ta1_x_yyzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 189);

    auto ta1_x_yyzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 191);

    auto ta1_x_yyzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 192);

    auto ta1_x_yyzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 193);

    auto ta1_x_yyzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 194);

    auto ta1_x_yzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 197);

    auto ta1_x_yzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 199);

    auto ta1_x_yzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 200);

    auto ta1_x_yzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 202);

    auto ta1_x_yzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 203);

    auto ta1_x_yzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 204);

    auto ta1_x_yzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 206);

    auto ta1_x_yzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 207);

    auto ta1_x_yzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 208);

    auto ta1_x_yzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 209);

    auto ta1_x_zzzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 210);

    auto ta1_x_zzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 211);

    auto ta1_x_zzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 212);

    auto ta1_x_zzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 213);

    auto ta1_x_zzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 214);

    auto ta1_x_zzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 215);

    auto ta1_x_zzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 216);

    auto ta1_x_zzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 217);

    auto ta1_x_zzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 218);

    auto ta1_x_zzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 219);

    auto ta1_x_zzzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 220);

    auto ta1_x_zzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 221);

    auto ta1_x_zzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 222);

    auto ta1_x_zzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 223);

    auto ta1_x_zzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 224);

    auto ta1_y_xxxx_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 225);

    auto ta1_y_xxxx_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 226);

    auto ta1_y_xxxx_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 227);

    auto ta1_y_xxxx_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 228);

    auto ta1_y_xxxx_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 229);

    auto ta1_y_xxxx_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 230);

    auto ta1_y_xxxx_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 231);

    auto ta1_y_xxxx_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 232);

    auto ta1_y_xxxx_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 233);

    auto ta1_y_xxxx_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 234);

    auto ta1_y_xxxx_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 235);

    auto ta1_y_xxxx_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 236);

    auto ta1_y_xxxx_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 237);

    auto ta1_y_xxxx_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 238);

    auto ta1_y_xxxx_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 239);

    auto ta1_y_xxxy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 241);

    auto ta1_y_xxxy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 243);

    auto ta1_y_xxxy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 244);

    auto ta1_y_xxxy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 246);

    auto ta1_y_xxxy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 247);

    auto ta1_y_xxxy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 248);

    auto ta1_y_xxyy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 270);

    auto ta1_y_xxyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 271);

    auto ta1_y_xxyy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 272);

    auto ta1_y_xxyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 273);

    auto ta1_y_xxyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 274);

    auto ta1_y_xxyy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 275);

    auto ta1_y_xxyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 276);

    auto ta1_y_xxyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 277);

    auto ta1_y_xxyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 278);

    auto ta1_y_xxyy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 279);

    auto ta1_y_xxyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 280);

    auto ta1_y_xxyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 281);

    auto ta1_y_xxyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 282);

    auto ta1_y_xxyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 283);

    auto ta1_y_xxzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 302);

    auto ta1_y_xxzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 304);

    auto ta1_y_xxzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 305);

    auto ta1_y_xxzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 307);

    auto ta1_y_xxzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 308);

    auto ta1_y_xxzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 309);

    auto ta1_y_xxzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 311);

    auto ta1_y_xxzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 312);

    auto ta1_y_xxzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 313);

    auto ta1_y_xxzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 314);

    auto ta1_y_xyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 316);

    auto ta1_y_xyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 318);

    auto ta1_y_xyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 319);

    auto ta1_y_xyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 321);

    auto ta1_y_xyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 322);

    auto ta1_y_xyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 323);

    auto ta1_y_xyyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 325);

    auto ta1_y_xyyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 326);

    auto ta1_y_xyyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 327);

    auto ta1_y_xyyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 328);

    auto ta1_y_xzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 362);

    auto ta1_y_xzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 364);

    auto ta1_y_xzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 365);

    auto ta1_y_xzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 367);

    auto ta1_y_xzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 368);

    auto ta1_y_xzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 369);

    auto ta1_y_xzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 371);

    auto ta1_y_xzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 372);

    auto ta1_y_xzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 373);

    auto ta1_y_xzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 374);

    auto ta1_y_yyyy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 375);

    auto ta1_y_yyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 376);

    auto ta1_y_yyyy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 377);

    auto ta1_y_yyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 378);

    auto ta1_y_yyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 379);

    auto ta1_y_yyyy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 380);

    auto ta1_y_yyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 381);

    auto ta1_y_yyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 382);

    auto ta1_y_yyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 383);

    auto ta1_y_yyyy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 384);

    auto ta1_y_yyyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 385);

    auto ta1_y_yyyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 386);

    auto ta1_y_yyyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 387);

    auto ta1_y_yyyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 388);

    auto ta1_y_yyyy_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 389);

    auto ta1_y_yyyz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 391);

    auto ta1_y_yyyz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 392);

    auto ta1_y_yyyz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 393);

    auto ta1_y_yyyz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 394);

    auto ta1_y_yyyz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 395);

    auto ta1_y_yyyz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 396);

    auto ta1_y_yyyz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 397);

    auto ta1_y_yyyz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 398);

    auto ta1_y_yyyz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 399);

    auto ta1_y_yyyz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 400);

    auto ta1_y_yyyz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 401);

    auto ta1_y_yyyz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 402);

    auto ta1_y_yyyz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 403);

    auto ta1_y_yyyz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 404);

    auto ta1_y_yyzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 405);

    auto ta1_y_yyzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 406);

    auto ta1_y_yyzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 407);

    auto ta1_y_yyzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 408);

    auto ta1_y_yyzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 409);

    auto ta1_y_yyzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 410);

    auto ta1_y_yyzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 411);

    auto ta1_y_yyzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 412);

    auto ta1_y_yyzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 413);

    auto ta1_y_yyzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 414);

    auto ta1_y_yyzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 415);

    auto ta1_y_yyzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 416);

    auto ta1_y_yyzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 417);

    auto ta1_y_yyzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 418);

    auto ta1_y_yyzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 419);

    auto ta1_y_yzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 421);

    auto ta1_y_yzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 423);

    auto ta1_y_yzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 424);

    auto ta1_y_yzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 426);

    auto ta1_y_yzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 427);

    auto ta1_y_yzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 428);

    auto ta1_y_yzzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 430);

    auto ta1_y_yzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 431);

    auto ta1_y_yzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 432);

    auto ta1_y_yzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 433);

    auto ta1_y_zzzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 435);

    auto ta1_y_zzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 436);

    auto ta1_y_zzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 437);

    auto ta1_y_zzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 438);

    auto ta1_y_zzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 439);

    auto ta1_y_zzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 440);

    auto ta1_y_zzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 441);

    auto ta1_y_zzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 442);

    auto ta1_y_zzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 443);

    auto ta1_y_zzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 444);

    auto ta1_y_zzzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 445);

    auto ta1_y_zzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 446);

    auto ta1_y_zzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 447);

    auto ta1_y_zzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 448);

    auto ta1_y_zzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 449);

    auto ta1_z_xxxx_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 450);

    auto ta1_z_xxxx_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 451);

    auto ta1_z_xxxx_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 452);

    auto ta1_z_xxxx_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 453);

    auto ta1_z_xxxx_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 454);

    auto ta1_z_xxxx_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 455);

    auto ta1_z_xxxx_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 456);

    auto ta1_z_xxxx_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 457);

    auto ta1_z_xxxx_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 458);

    auto ta1_z_xxxx_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 459);

    auto ta1_z_xxxx_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 460);

    auto ta1_z_xxxx_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 461);

    auto ta1_z_xxxx_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 462);

    auto ta1_z_xxxx_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 463);

    auto ta1_z_xxxx_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 464);

    auto ta1_z_xxxz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 482);

    auto ta1_z_xxxz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 484);

    auto ta1_z_xxxz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 485);

    auto ta1_z_xxxz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 487);

    auto ta1_z_xxxz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 488);

    auto ta1_z_xxxz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 489);

    auto ta1_z_xxyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 496);

    auto ta1_z_xxyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 498);

    auto ta1_z_xxyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 499);

    auto ta1_z_xxyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 501);

    auto ta1_z_xxyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 502);

    auto ta1_z_xxyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 503);

    auto ta1_z_xxyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 505);

    auto ta1_z_xxyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 506);

    auto ta1_z_xxyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 507);

    auto ta1_z_xxyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 508);

    auto ta1_z_xxzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 525);

    auto ta1_z_xxzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 526);

    auto ta1_z_xxzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 527);

    auto ta1_z_xxzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 528);

    auto ta1_z_xxzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 529);

    auto ta1_z_xxzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 530);

    auto ta1_z_xxzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 531);

    auto ta1_z_xxzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 532);

    auto ta1_z_xxzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 533);

    auto ta1_z_xxzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 534);

    auto ta1_z_xxzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 536);

    auto ta1_z_xxzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 537);

    auto ta1_z_xxzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 538);

    auto ta1_z_xxzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 539);

    auto ta1_z_xyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 541);

    auto ta1_z_xyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 543);

    auto ta1_z_xyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 544);

    auto ta1_z_xyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 546);

    auto ta1_z_xyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 547);

    auto ta1_z_xyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 548);

    auto ta1_z_xyyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 550);

    auto ta1_z_xyyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 551);

    auto ta1_z_xyyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 552);

    auto ta1_z_xyyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 553);

    auto ta1_z_xzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 587);

    auto ta1_z_xzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 589);

    auto ta1_z_xzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 590);

    auto ta1_z_xzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 592);

    auto ta1_z_xzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 593);

    auto ta1_z_xzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 594);

    auto ta1_z_xzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 596);

    auto ta1_z_xzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 597);

    auto ta1_z_xzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 598);

    auto ta1_z_xzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 599);

    auto ta1_z_yyyy_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 600);

    auto ta1_z_yyyy_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 601);

    auto ta1_z_yyyy_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 602);

    auto ta1_z_yyyy_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 603);

    auto ta1_z_yyyy_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 604);

    auto ta1_z_yyyy_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 605);

    auto ta1_z_yyyy_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 606);

    auto ta1_z_yyyy_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 607);

    auto ta1_z_yyyy_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 608);

    auto ta1_z_yyyy_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 609);

    auto ta1_z_yyyy_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 610);

    auto ta1_z_yyyy_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 611);

    auto ta1_z_yyyy_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 612);

    auto ta1_z_yyyy_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 613);

    auto ta1_z_yyyy_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 614);

    auto ta1_z_yyyz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 617);

    auto ta1_z_yyyz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 619);

    auto ta1_z_yyyz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 620);

    auto ta1_z_yyyz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 622);

    auto ta1_z_yyyz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 623);

    auto ta1_z_yyyz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 624);

    auto ta1_z_yyyz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 626);

    auto ta1_z_yyyz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 627);

    auto ta1_z_yyyz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 628);

    auto ta1_z_yyyz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 629);

    auto ta1_z_yyzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 630);

    auto ta1_z_yyzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 631);

    auto ta1_z_yyzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 632);

    auto ta1_z_yyzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 633);

    auto ta1_z_yyzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 634);

    auto ta1_z_yyzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 635);

    auto ta1_z_yyzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 636);

    auto ta1_z_yyzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 637);

    auto ta1_z_yyzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 638);

    auto ta1_z_yyzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 639);

    auto ta1_z_yyzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 640);

    auto ta1_z_yyzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 641);

    auto ta1_z_yyzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 642);

    auto ta1_z_yyzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 643);

    auto ta1_z_yyzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 644);

    auto ta1_z_yzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 646);

    auto ta1_z_yzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 647);

    auto ta1_z_yzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 648);

    auto ta1_z_yzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 649);

    auto ta1_z_yzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 650);

    auto ta1_z_yzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 651);

    auto ta1_z_yzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 652);

    auto ta1_z_yzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 653);

    auto ta1_z_yzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 654);

    auto ta1_z_yzzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 655);

    auto ta1_z_yzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 656);

    auto ta1_z_yzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 657);

    auto ta1_z_yzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 658);

    auto ta1_z_yzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 659);

    auto ta1_z_zzzz_xxxx_0 = pbuffer.data(idx_npot_geom_010_0_gg + 660);

    auto ta1_z_zzzz_xxxy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 661);

    auto ta1_z_zzzz_xxxz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 662);

    auto ta1_z_zzzz_xxyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 663);

    auto ta1_z_zzzz_xxyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 664);

    auto ta1_z_zzzz_xxzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 665);

    auto ta1_z_zzzz_xyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 666);

    auto ta1_z_zzzz_xyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 667);

    auto ta1_z_zzzz_xyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 668);

    auto ta1_z_zzzz_xzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 669);

    auto ta1_z_zzzz_yyyy_0 = pbuffer.data(idx_npot_geom_010_0_gg + 670);

    auto ta1_z_zzzz_yyyz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 671);

    auto ta1_z_zzzz_yyzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 672);

    auto ta1_z_zzzz_yzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 673);

    auto ta1_z_zzzz_zzzz_0 = pbuffer.data(idx_npot_geom_010_0_gg + 674);

    // Set up components of auxiliary buffer : GG

    auto ta1_x_xxxx_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg);

    auto ta1_x_xxxx_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 1);

    auto ta1_x_xxxx_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 2);

    auto ta1_x_xxxx_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 3);

    auto ta1_x_xxxx_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 4);

    auto ta1_x_xxxx_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 5);

    auto ta1_x_xxxx_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 6);

    auto ta1_x_xxxx_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 7);

    auto ta1_x_xxxx_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 8);

    auto ta1_x_xxxx_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 9);

    auto ta1_x_xxxx_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 10);

    auto ta1_x_xxxx_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 11);

    auto ta1_x_xxxx_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 12);

    auto ta1_x_xxxx_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 13);

    auto ta1_x_xxxx_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 14);

    auto ta1_x_xxxy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 15);

    auto ta1_x_xxxy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 16);

    auto ta1_x_xxxy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 17);

    auto ta1_x_xxxy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 18);

    auto ta1_x_xxxy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 19);

    auto ta1_x_xxxy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 20);

    auto ta1_x_xxxy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 21);

    auto ta1_x_xxxy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 22);

    auto ta1_x_xxxy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 23);

    auto ta1_x_xxxy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 24);

    auto ta1_x_xxxz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 30);

    auto ta1_x_xxxz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 31);

    auto ta1_x_xxxz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 32);

    auto ta1_x_xxxz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 33);

    auto ta1_x_xxxz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 34);

    auto ta1_x_xxxz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 35);

    auto ta1_x_xxxz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 36);

    auto ta1_x_xxxz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 37);

    auto ta1_x_xxxz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 38);

    auto ta1_x_xxxz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 39);

    auto ta1_x_xxxz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 41);

    auto ta1_x_xxxz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 42);

    auto ta1_x_xxxz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 43);

    auto ta1_x_xxxz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 44);

    auto ta1_x_xxyy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 45);

    auto ta1_x_xxyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 46);

    auto ta1_x_xxyy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 47);

    auto ta1_x_xxyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 48);

    auto ta1_x_xxyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 49);

    auto ta1_x_xxyy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 50);

    auto ta1_x_xxyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 51);

    auto ta1_x_xxyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 52);

    auto ta1_x_xxyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 53);

    auto ta1_x_xxyy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 54);

    auto ta1_x_xxyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 55);

    auto ta1_x_xxyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 56);

    auto ta1_x_xxyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 57);

    auto ta1_x_xxyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 58);

    auto ta1_x_xxzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 75);

    auto ta1_x_xxzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 76);

    auto ta1_x_xxzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 77);

    auto ta1_x_xxzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 78);

    auto ta1_x_xxzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 79);

    auto ta1_x_xxzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 80);

    auto ta1_x_xxzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 81);

    auto ta1_x_xxzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 82);

    auto ta1_x_xxzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 83);

    auto ta1_x_xxzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 84);

    auto ta1_x_xxzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 85);

    auto ta1_x_xxzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 86);

    auto ta1_x_xxzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 87);

    auto ta1_x_xxzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 88);

    auto ta1_x_xxzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 89);

    auto ta1_x_xyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 91);

    auto ta1_x_xyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 93);

    auto ta1_x_xyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 94);

    auto ta1_x_xyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 96);

    auto ta1_x_xyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 97);

    auto ta1_x_xyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 98);

    auto ta1_x_xzzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 135);

    auto ta1_x_xzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 136);

    auto ta1_x_xzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 137);

    auto ta1_x_xzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 138);

    auto ta1_x_xzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 139);

    auto ta1_x_xzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 140);

    auto ta1_x_xzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 141);

    auto ta1_x_xzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 142);

    auto ta1_x_xzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 143);

    auto ta1_x_xzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 144);

    auto ta1_x_yyyy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 150);

    auto ta1_x_yyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 151);

    auto ta1_x_yyyy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 152);

    auto ta1_x_yyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 153);

    auto ta1_x_yyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 154);

    auto ta1_x_yyyy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 155);

    auto ta1_x_yyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 156);

    auto ta1_x_yyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 157);

    auto ta1_x_yyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 158);

    auto ta1_x_yyyy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 159);

    auto ta1_x_yyyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 160);

    auto ta1_x_yyyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 161);

    auto ta1_x_yyyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 162);

    auto ta1_x_yyyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 163);

    auto ta1_x_yyyy_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 164);

    auto ta1_x_yyzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 182);

    auto ta1_x_yyzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 184);

    auto ta1_x_yyzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 185);

    auto ta1_x_yyzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 187);

    auto ta1_x_yyzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 188);

    auto ta1_x_yyzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 189);

    auto ta1_x_yyzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 191);

    auto ta1_x_yyzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 192);

    auto ta1_x_yyzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 193);

    auto ta1_x_yyzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 194);

    auto ta1_x_yzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 197);

    auto ta1_x_yzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 199);

    auto ta1_x_yzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 200);

    auto ta1_x_yzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 202);

    auto ta1_x_yzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 203);

    auto ta1_x_yzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 204);

    auto ta1_x_yzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 206);

    auto ta1_x_yzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 207);

    auto ta1_x_yzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 208);

    auto ta1_x_yzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 209);

    auto ta1_x_zzzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 210);

    auto ta1_x_zzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 211);

    auto ta1_x_zzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 212);

    auto ta1_x_zzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 213);

    auto ta1_x_zzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 214);

    auto ta1_x_zzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 215);

    auto ta1_x_zzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 216);

    auto ta1_x_zzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 217);

    auto ta1_x_zzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 218);

    auto ta1_x_zzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 219);

    auto ta1_x_zzzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 220);

    auto ta1_x_zzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 221);

    auto ta1_x_zzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 222);

    auto ta1_x_zzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 223);

    auto ta1_x_zzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 224);

    auto ta1_y_xxxx_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 225);

    auto ta1_y_xxxx_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 226);

    auto ta1_y_xxxx_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 227);

    auto ta1_y_xxxx_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 228);

    auto ta1_y_xxxx_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 229);

    auto ta1_y_xxxx_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 230);

    auto ta1_y_xxxx_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 231);

    auto ta1_y_xxxx_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 232);

    auto ta1_y_xxxx_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 233);

    auto ta1_y_xxxx_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 234);

    auto ta1_y_xxxx_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 235);

    auto ta1_y_xxxx_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 236);

    auto ta1_y_xxxx_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 237);

    auto ta1_y_xxxx_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 238);

    auto ta1_y_xxxx_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 239);

    auto ta1_y_xxxy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 241);

    auto ta1_y_xxxy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 243);

    auto ta1_y_xxxy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 244);

    auto ta1_y_xxxy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 246);

    auto ta1_y_xxxy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 247);

    auto ta1_y_xxxy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 248);

    auto ta1_y_xxyy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 270);

    auto ta1_y_xxyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 271);

    auto ta1_y_xxyy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 272);

    auto ta1_y_xxyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 273);

    auto ta1_y_xxyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 274);

    auto ta1_y_xxyy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 275);

    auto ta1_y_xxyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 276);

    auto ta1_y_xxyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 277);

    auto ta1_y_xxyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 278);

    auto ta1_y_xxyy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 279);

    auto ta1_y_xxyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 280);

    auto ta1_y_xxyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 281);

    auto ta1_y_xxyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 282);

    auto ta1_y_xxyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 283);

    auto ta1_y_xxzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 302);

    auto ta1_y_xxzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 304);

    auto ta1_y_xxzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 305);

    auto ta1_y_xxzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 307);

    auto ta1_y_xxzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 308);

    auto ta1_y_xxzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 309);

    auto ta1_y_xxzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 311);

    auto ta1_y_xxzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 312);

    auto ta1_y_xxzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 313);

    auto ta1_y_xxzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 314);

    auto ta1_y_xyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 316);

    auto ta1_y_xyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 318);

    auto ta1_y_xyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 319);

    auto ta1_y_xyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 321);

    auto ta1_y_xyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 322);

    auto ta1_y_xyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 323);

    auto ta1_y_xyyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 325);

    auto ta1_y_xyyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 326);

    auto ta1_y_xyyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 327);

    auto ta1_y_xyyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 328);

    auto ta1_y_xzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 362);

    auto ta1_y_xzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 364);

    auto ta1_y_xzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 365);

    auto ta1_y_xzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 367);

    auto ta1_y_xzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 368);

    auto ta1_y_xzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 369);

    auto ta1_y_xzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 371);

    auto ta1_y_xzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 372);

    auto ta1_y_xzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 373);

    auto ta1_y_xzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 374);

    auto ta1_y_yyyy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 375);

    auto ta1_y_yyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 376);

    auto ta1_y_yyyy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 377);

    auto ta1_y_yyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 378);

    auto ta1_y_yyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 379);

    auto ta1_y_yyyy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 380);

    auto ta1_y_yyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 381);

    auto ta1_y_yyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 382);

    auto ta1_y_yyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 383);

    auto ta1_y_yyyy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 384);

    auto ta1_y_yyyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 385);

    auto ta1_y_yyyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 386);

    auto ta1_y_yyyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 387);

    auto ta1_y_yyyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 388);

    auto ta1_y_yyyy_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 389);

    auto ta1_y_yyyz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 391);

    auto ta1_y_yyyz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 392);

    auto ta1_y_yyyz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 393);

    auto ta1_y_yyyz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 394);

    auto ta1_y_yyyz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 395);

    auto ta1_y_yyyz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 396);

    auto ta1_y_yyyz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 397);

    auto ta1_y_yyyz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 398);

    auto ta1_y_yyyz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 399);

    auto ta1_y_yyyz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 400);

    auto ta1_y_yyyz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 401);

    auto ta1_y_yyyz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 402);

    auto ta1_y_yyyz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 403);

    auto ta1_y_yyyz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 404);

    auto ta1_y_yyzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 405);

    auto ta1_y_yyzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 406);

    auto ta1_y_yyzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 407);

    auto ta1_y_yyzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 408);

    auto ta1_y_yyzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 409);

    auto ta1_y_yyzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 410);

    auto ta1_y_yyzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 411);

    auto ta1_y_yyzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 412);

    auto ta1_y_yyzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 413);

    auto ta1_y_yyzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 414);

    auto ta1_y_yyzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 415);

    auto ta1_y_yyzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 416);

    auto ta1_y_yyzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 417);

    auto ta1_y_yyzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 418);

    auto ta1_y_yyzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 419);

    auto ta1_y_yzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 421);

    auto ta1_y_yzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 423);

    auto ta1_y_yzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 424);

    auto ta1_y_yzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 426);

    auto ta1_y_yzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 427);

    auto ta1_y_yzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 428);

    auto ta1_y_yzzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 430);

    auto ta1_y_yzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 431);

    auto ta1_y_yzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 432);

    auto ta1_y_yzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 433);

    auto ta1_y_zzzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 435);

    auto ta1_y_zzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 436);

    auto ta1_y_zzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 437);

    auto ta1_y_zzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 438);

    auto ta1_y_zzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 439);

    auto ta1_y_zzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 440);

    auto ta1_y_zzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 441);

    auto ta1_y_zzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 442);

    auto ta1_y_zzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 443);

    auto ta1_y_zzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 444);

    auto ta1_y_zzzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 445);

    auto ta1_y_zzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 446);

    auto ta1_y_zzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 447);

    auto ta1_y_zzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 448);

    auto ta1_y_zzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 449);

    auto ta1_z_xxxx_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 450);

    auto ta1_z_xxxx_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 451);

    auto ta1_z_xxxx_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 452);

    auto ta1_z_xxxx_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 453);

    auto ta1_z_xxxx_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 454);

    auto ta1_z_xxxx_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 455);

    auto ta1_z_xxxx_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 456);

    auto ta1_z_xxxx_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 457);

    auto ta1_z_xxxx_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 458);

    auto ta1_z_xxxx_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 459);

    auto ta1_z_xxxx_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 460);

    auto ta1_z_xxxx_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 461);

    auto ta1_z_xxxx_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 462);

    auto ta1_z_xxxx_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 463);

    auto ta1_z_xxxx_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 464);

    auto ta1_z_xxxz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 482);

    auto ta1_z_xxxz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 484);

    auto ta1_z_xxxz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 485);

    auto ta1_z_xxxz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 487);

    auto ta1_z_xxxz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 488);

    auto ta1_z_xxxz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 489);

    auto ta1_z_xxyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 496);

    auto ta1_z_xxyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 498);

    auto ta1_z_xxyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 499);

    auto ta1_z_xxyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 501);

    auto ta1_z_xxyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 502);

    auto ta1_z_xxyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 503);

    auto ta1_z_xxyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 505);

    auto ta1_z_xxyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 506);

    auto ta1_z_xxyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 507);

    auto ta1_z_xxyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 508);

    auto ta1_z_xxzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 525);

    auto ta1_z_xxzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 526);

    auto ta1_z_xxzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 527);

    auto ta1_z_xxzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 528);

    auto ta1_z_xxzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 529);

    auto ta1_z_xxzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 530);

    auto ta1_z_xxzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 531);

    auto ta1_z_xxzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 532);

    auto ta1_z_xxzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 533);

    auto ta1_z_xxzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 534);

    auto ta1_z_xxzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 536);

    auto ta1_z_xxzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 537);

    auto ta1_z_xxzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 538);

    auto ta1_z_xxzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 539);

    auto ta1_z_xyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 541);

    auto ta1_z_xyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 543);

    auto ta1_z_xyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 544);

    auto ta1_z_xyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 546);

    auto ta1_z_xyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 547);

    auto ta1_z_xyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 548);

    auto ta1_z_xyyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 550);

    auto ta1_z_xyyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 551);

    auto ta1_z_xyyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 552);

    auto ta1_z_xyyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 553);

    auto ta1_z_xzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 587);

    auto ta1_z_xzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 589);

    auto ta1_z_xzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 590);

    auto ta1_z_xzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 592);

    auto ta1_z_xzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 593);

    auto ta1_z_xzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 594);

    auto ta1_z_xzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 596);

    auto ta1_z_xzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 597);

    auto ta1_z_xzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 598);

    auto ta1_z_xzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 599);

    auto ta1_z_yyyy_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 600);

    auto ta1_z_yyyy_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 601);

    auto ta1_z_yyyy_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 602);

    auto ta1_z_yyyy_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 603);

    auto ta1_z_yyyy_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 604);

    auto ta1_z_yyyy_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 605);

    auto ta1_z_yyyy_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 606);

    auto ta1_z_yyyy_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 607);

    auto ta1_z_yyyy_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 608);

    auto ta1_z_yyyy_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 609);

    auto ta1_z_yyyy_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 610);

    auto ta1_z_yyyy_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 611);

    auto ta1_z_yyyy_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 612);

    auto ta1_z_yyyy_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 613);

    auto ta1_z_yyyy_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 614);

    auto ta1_z_yyyz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 617);

    auto ta1_z_yyyz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 619);

    auto ta1_z_yyyz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 620);

    auto ta1_z_yyyz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 622);

    auto ta1_z_yyyz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 623);

    auto ta1_z_yyyz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 624);

    auto ta1_z_yyyz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 626);

    auto ta1_z_yyyz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 627);

    auto ta1_z_yyyz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 628);

    auto ta1_z_yyyz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 629);

    auto ta1_z_yyzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 630);

    auto ta1_z_yyzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 631);

    auto ta1_z_yyzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 632);

    auto ta1_z_yyzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 633);

    auto ta1_z_yyzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 634);

    auto ta1_z_yyzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 635);

    auto ta1_z_yyzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 636);

    auto ta1_z_yyzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 637);

    auto ta1_z_yyzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 638);

    auto ta1_z_yyzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 639);

    auto ta1_z_yyzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 640);

    auto ta1_z_yyzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 641);

    auto ta1_z_yyzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 642);

    auto ta1_z_yyzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 643);

    auto ta1_z_yyzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 644);

    auto ta1_z_yzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 646);

    auto ta1_z_yzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 647);

    auto ta1_z_yzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 648);

    auto ta1_z_yzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 649);

    auto ta1_z_yzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 650);

    auto ta1_z_yzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 651);

    auto ta1_z_yzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 652);

    auto ta1_z_yzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 653);

    auto ta1_z_yzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 654);

    auto ta1_z_yzzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 655);

    auto ta1_z_yzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 656);

    auto ta1_z_yzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 657);

    auto ta1_z_yzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 658);

    auto ta1_z_yzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 659);

    auto ta1_z_zzzz_xxxx_1 = pbuffer.data(idx_npot_geom_010_1_gg + 660);

    auto ta1_z_zzzz_xxxy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 661);

    auto ta1_z_zzzz_xxxz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 662);

    auto ta1_z_zzzz_xxyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 663);

    auto ta1_z_zzzz_xxyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 664);

    auto ta1_z_zzzz_xxzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 665);

    auto ta1_z_zzzz_xyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 666);

    auto ta1_z_zzzz_xyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 667);

    auto ta1_z_zzzz_xyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 668);

    auto ta1_z_zzzz_xzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 669);

    auto ta1_z_zzzz_yyyy_1 = pbuffer.data(idx_npot_geom_010_1_gg + 670);

    auto ta1_z_zzzz_yyyz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 671);

    auto ta1_z_zzzz_yyzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 672);

    auto ta1_z_zzzz_yzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 673);

    auto ta1_z_zzzz_zzzz_1 = pbuffer.data(idx_npot_geom_010_1_gg + 674);

    // Set up components of auxiliary buffer : GH

    auto ta_xxxx_xxxxx_1 = pbuffer.data(idx_npot_1_gh);

    auto ta_xxxx_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 1);

    auto ta_xxxx_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 2);

    auto ta_xxxx_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 3);

    auto ta_xxxx_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 4);

    auto ta_xxxx_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 5);

    auto ta_xxxx_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 6);

    auto ta_xxxx_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 7);

    auto ta_xxxx_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 8);

    auto ta_xxxx_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 9);

    auto ta_xxxx_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 10);

    auto ta_xxxx_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 11);

    auto ta_xxxx_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 12);

    auto ta_xxxx_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 13);

    auto ta_xxxx_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 14);

    auto ta_xxxx_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 15);

    auto ta_xxxx_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 16);

    auto ta_xxxx_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 17);

    auto ta_xxxx_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 18);

    auto ta_xxxx_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 19);

    auto ta_xxxx_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 20);

    auto ta_xxxy_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 21);

    auto ta_xxxy_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 22);

    auto ta_xxxy_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 23);

    auto ta_xxxy_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 24);

    auto ta_xxxy_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 26);

    auto ta_xxxy_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 27);

    auto ta_xxxy_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 30);

    auto ta_xxxy_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 31);

    auto ta_xxxy_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 35);

    auto ta_xxxy_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 36);

    auto ta_xxxz_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 42);

    auto ta_xxxz_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 43);

    auto ta_xxxz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 44);

    auto ta_xxxz_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 45);

    auto ta_xxxz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 47);

    auto ta_xxxz_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 48);

    auto ta_xxxz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 51);

    auto ta_xxxz_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 52);

    auto ta_xxxz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 56);

    auto ta_xxxz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 62);

    auto ta_xxyy_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 63);

    auto ta_xxyy_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 64);

    auto ta_xxyy_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 65);

    auto ta_xxyy_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 66);

    auto ta_xxyy_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 67);

    auto ta_xxyy_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 68);

    auto ta_xxyy_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 69);

    auto ta_xxyy_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 70);

    auto ta_xxyy_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 71);

    auto ta_xxyy_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 72);

    auto ta_xxyy_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 73);

    auto ta_xxyy_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 74);

    auto ta_xxyy_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 75);

    auto ta_xxyy_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 76);

    auto ta_xxyy_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 77);

    auto ta_xxyy_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 78);

    auto ta_xxyy_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 79);

    auto ta_xxyy_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 80);

    auto ta_xxyy_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 81);

    auto ta_xxyy_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 82);

    auto ta_xxzz_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 105);

    auto ta_xxzz_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 106);

    auto ta_xxzz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 107);

    auto ta_xxzz_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 108);

    auto ta_xxzz_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 109);

    auto ta_xxzz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 110);

    auto ta_xxzz_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 111);

    auto ta_xxzz_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 112);

    auto ta_xxzz_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 113);

    auto ta_xxzz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 114);

    auto ta_xxzz_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 115);

    auto ta_xxzz_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 116);

    auto ta_xxzz_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 117);

    auto ta_xxzz_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 118);

    auto ta_xxzz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 119);

    auto ta_xxzz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 121);

    auto ta_xxzz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 122);

    auto ta_xxzz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 123);

    auto ta_xxzz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 124);

    auto ta_xxzz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 125);

    auto ta_xyyy_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 126);

    auto ta_xyyy_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 127);

    auto ta_xyyy_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 129);

    auto ta_xyyy_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 132);

    auto ta_xyyy_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 136);

    auto ta_xyyy_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 141);

    auto ta_xyyy_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 142);

    auto ta_xyyy_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 143);

    auto ta_xyyy_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 144);

    auto ta_xyyy_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 145);

    auto ta_xzzz_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 189);

    auto ta_xzzz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 191);

    auto ta_xzzz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 194);

    auto ta_xzzz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 198);

    auto ta_xzzz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 203);

    auto ta_xzzz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 205);

    auto ta_xzzz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 206);

    auto ta_xzzz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 207);

    auto ta_xzzz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 208);

    auto ta_xzzz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 209);

    auto ta_yyyy_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 210);

    auto ta_yyyy_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 211);

    auto ta_yyyy_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 212);

    auto ta_yyyy_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 213);

    auto ta_yyyy_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 214);

    auto ta_yyyy_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 215);

    auto ta_yyyy_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 216);

    auto ta_yyyy_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 217);

    auto ta_yyyy_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 218);

    auto ta_yyyy_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 219);

    auto ta_yyyy_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 220);

    auto ta_yyyy_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 221);

    auto ta_yyyy_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 222);

    auto ta_yyyy_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 223);

    auto ta_yyyy_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 224);

    auto ta_yyyy_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 225);

    auto ta_yyyy_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 226);

    auto ta_yyyy_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 227);

    auto ta_yyyy_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 228);

    auto ta_yyyy_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 229);

    auto ta_yyyy_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 230);

    auto ta_yyyz_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 232);

    auto ta_yyyz_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 234);

    auto ta_yyyz_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 237);

    auto ta_yyyz_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 241);

    auto ta_yyyz_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 246);

    auto ta_yyyz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 247);

    auto ta_yyyz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 248);

    auto ta_yyyz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 249);

    auto ta_yyyz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 250);

    auto ta_yyyz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 251);

    auto ta_yyzz_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 253);

    auto ta_yyzz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 254);

    auto ta_yyzz_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 255);

    auto ta_yyzz_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 256);

    auto ta_yyzz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 257);

    auto ta_yyzz_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 258);

    auto ta_yyzz_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 259);

    auto ta_yyzz_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 260);

    auto ta_yyzz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 261);

    auto ta_yyzz_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 262);

    auto ta_yyzz_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 263);

    auto ta_yyzz_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 264);

    auto ta_yyzz_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 265);

    auto ta_yyzz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 266);

    auto ta_yyzz_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 267);

    auto ta_yyzz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 268);

    auto ta_yyzz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 269);

    auto ta_yyzz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 270);

    auto ta_yyzz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 271);

    auto ta_yyzz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 272);

    auto ta_yzzz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 275);

    auto ta_yzzz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 278);

    auto ta_yzzz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 282);

    auto ta_yzzz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 287);

    auto ta_yzzz_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 288);

    auto ta_yzzz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 289);

    auto ta_yzzz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 290);

    auto ta_yzzz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 291);

    auto ta_yzzz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 292);

    auto ta_yzzz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 293);

    auto ta_zzzz_xxxxx_1 = pbuffer.data(idx_npot_1_gh + 294);

    auto ta_zzzz_xxxxy_1 = pbuffer.data(idx_npot_1_gh + 295);

    auto ta_zzzz_xxxxz_1 = pbuffer.data(idx_npot_1_gh + 296);

    auto ta_zzzz_xxxyy_1 = pbuffer.data(idx_npot_1_gh + 297);

    auto ta_zzzz_xxxyz_1 = pbuffer.data(idx_npot_1_gh + 298);

    auto ta_zzzz_xxxzz_1 = pbuffer.data(idx_npot_1_gh + 299);

    auto ta_zzzz_xxyyy_1 = pbuffer.data(idx_npot_1_gh + 300);

    auto ta_zzzz_xxyyz_1 = pbuffer.data(idx_npot_1_gh + 301);

    auto ta_zzzz_xxyzz_1 = pbuffer.data(idx_npot_1_gh + 302);

    auto ta_zzzz_xxzzz_1 = pbuffer.data(idx_npot_1_gh + 303);

    auto ta_zzzz_xyyyy_1 = pbuffer.data(idx_npot_1_gh + 304);

    auto ta_zzzz_xyyyz_1 = pbuffer.data(idx_npot_1_gh + 305);

    auto ta_zzzz_xyyzz_1 = pbuffer.data(idx_npot_1_gh + 306);

    auto ta_zzzz_xyzzz_1 = pbuffer.data(idx_npot_1_gh + 307);

    auto ta_zzzz_xzzzz_1 = pbuffer.data(idx_npot_1_gh + 308);

    auto ta_zzzz_yyyyy_1 = pbuffer.data(idx_npot_1_gh + 309);

    auto ta_zzzz_yyyyz_1 = pbuffer.data(idx_npot_1_gh + 310);

    auto ta_zzzz_yyyzz_1 = pbuffer.data(idx_npot_1_gh + 311);

    auto ta_zzzz_yyzzz_1 = pbuffer.data(idx_npot_1_gh + 312);

    auto ta_zzzz_yzzzz_1 = pbuffer.data(idx_npot_1_gh + 313);

    auto ta_zzzz_zzzzz_1 = pbuffer.data(idx_npot_1_gh + 314);

    // Set up components of auxiliary buffer : GH

    auto ta1_x_xxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh);

    auto ta1_x_xxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 1);

    auto ta1_x_xxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 2);

    auto ta1_x_xxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 3);

    auto ta1_x_xxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 4);

    auto ta1_x_xxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 5);

    auto ta1_x_xxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 6);

    auto ta1_x_xxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 7);

    auto ta1_x_xxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 8);

    auto ta1_x_xxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 9);

    auto ta1_x_xxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 10);

    auto ta1_x_xxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 11);

    auto ta1_x_xxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 12);

    auto ta1_x_xxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 13);

    auto ta1_x_xxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 14);

    auto ta1_x_xxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 15);

    auto ta1_x_xxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 16);

    auto ta1_x_xxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 17);

    auto ta1_x_xxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 18);

    auto ta1_x_xxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 19);

    auto ta1_x_xxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 20);

    auto ta1_x_xxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 21);

    auto ta1_x_xxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 22);

    auto ta1_x_xxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 23);

    auto ta1_x_xxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 24);

    auto ta1_x_xxxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 25);

    auto ta1_x_xxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 26);

    auto ta1_x_xxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 27);

    auto ta1_x_xxxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 28);

    auto ta1_x_xxxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 29);

    auto ta1_x_xxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 30);

    auto ta1_x_xxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 31);

    auto ta1_x_xxxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 32);

    auto ta1_x_xxxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 33);

    auto ta1_x_xxxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 34);

    auto ta1_x_xxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 35);

    auto ta1_x_xxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 36);

    auto ta1_x_xxxy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 41);

    auto ta1_x_xxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 42);

    auto ta1_x_xxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 43);

    auto ta1_x_xxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 44);

    auto ta1_x_xxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 45);

    auto ta1_x_xxxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 46);

    auto ta1_x_xxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 47);

    auto ta1_x_xxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 48);

    auto ta1_x_xxxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 49);

    auto ta1_x_xxxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 50);

    auto ta1_x_xxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 51);

    auto ta1_x_xxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 52);

    auto ta1_x_xxxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 53);

    auto ta1_x_xxxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 54);

    auto ta1_x_xxxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 55);

    auto ta1_x_xxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 56);

    auto ta1_x_xxxz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 57);

    auto ta1_x_xxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 58);

    auto ta1_x_xxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 59);

    auto ta1_x_xxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 60);

    auto ta1_x_xxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 61);

    auto ta1_x_xxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 62);

    auto ta1_x_xxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 63);

    auto ta1_x_xxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 64);

    auto ta1_x_xxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 65);

    auto ta1_x_xxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 66);

    auto ta1_x_xxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 67);

    auto ta1_x_xxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 68);

    auto ta1_x_xxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 69);

    auto ta1_x_xxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 70);

    auto ta1_x_xxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 71);

    auto ta1_x_xxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 72);

    auto ta1_x_xxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 73);

    auto ta1_x_xxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 74);

    auto ta1_x_xxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 75);

    auto ta1_x_xxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 76);

    auto ta1_x_xxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 77);

    auto ta1_x_xxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 78);

    auto ta1_x_xxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 79);

    auto ta1_x_xxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 80);

    auto ta1_x_xxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 81);

    auto ta1_x_xxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 82);

    auto ta1_x_xxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 83);

    auto ta1_x_xxyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 86);

    auto ta1_x_xxyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 89);

    auto ta1_x_xxyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 93);

    auto ta1_x_xxyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 98);

    auto ta1_x_xxyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 104);

    auto ta1_x_xxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 105);

    auto ta1_x_xxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 106);

    auto ta1_x_xxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 107);

    auto ta1_x_xxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 108);

    auto ta1_x_xxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 109);

    auto ta1_x_xxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 110);

    auto ta1_x_xxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 111);

    auto ta1_x_xxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 112);

    auto ta1_x_xxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 113);

    auto ta1_x_xxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 114);

    auto ta1_x_xxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 115);

    auto ta1_x_xxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 116);

    auto ta1_x_xxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 117);

    auto ta1_x_xxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 118);

    auto ta1_x_xxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 119);

    auto ta1_x_xxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 120);

    auto ta1_x_xxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 121);

    auto ta1_x_xxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 122);

    auto ta1_x_xxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 123);

    auto ta1_x_xxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 124);

    auto ta1_x_xxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 125);

    auto ta1_x_xyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 126);

    auto ta1_x_xyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 127);

    auto ta1_x_xyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 128);

    auto ta1_x_xyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 129);

    auto ta1_x_xyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 130);

    auto ta1_x_xyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 131);

    auto ta1_x_xyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 132);

    auto ta1_x_xyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 133);

    auto ta1_x_xyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 134);

    auto ta1_x_xyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 135);

    auto ta1_x_xyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 136);

    auto ta1_x_xyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 137);

    auto ta1_x_xyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 138);

    auto ta1_x_xyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 139);

    auto ta1_x_xyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 140);

    auto ta1_x_xyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 141);

    auto ta1_x_xyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 142);

    auto ta1_x_xyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 143);

    auto ta1_x_xyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 144);

    auto ta1_x_xyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 145);

    auto ta1_x_xyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 148);

    auto ta1_x_xyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 149);

    auto ta1_x_xyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 150);

    auto ta1_x_xyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 152);

    auto ta1_x_xyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 153);

    auto ta1_x_xyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 156);

    auto ta1_x_xyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 157);

    auto ta1_x_xyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 161);

    auto ta1_x_xyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 168);

    auto ta1_x_xyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 170);

    auto ta1_x_xyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 173);

    auto ta1_x_xyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 177);

    auto ta1_x_xyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 182);

    auto ta1_x_xzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 189);

    auto ta1_x_xzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 190);

    auto ta1_x_xzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 191);

    auto ta1_x_xzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 192);

    auto ta1_x_xzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 193);

    auto ta1_x_xzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 194);

    auto ta1_x_xzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 195);

    auto ta1_x_xzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 196);

    auto ta1_x_xzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 197);

    auto ta1_x_xzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 198);

    auto ta1_x_xzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 199);

    auto ta1_x_xzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 200);

    auto ta1_x_xzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 201);

    auto ta1_x_xzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 202);

    auto ta1_x_xzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 203);

    auto ta1_x_xzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 205);

    auto ta1_x_xzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 206);

    auto ta1_x_xzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 207);

    auto ta1_x_xzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 208);

    auto ta1_x_xzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 209);

    auto ta1_x_yyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 210);

    auto ta1_x_yyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 211);

    auto ta1_x_yyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 212);

    auto ta1_x_yyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 213);

    auto ta1_x_yyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 214);

    auto ta1_x_yyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 215);

    auto ta1_x_yyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 216);

    auto ta1_x_yyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 217);

    auto ta1_x_yyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 218);

    auto ta1_x_yyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 219);

    auto ta1_x_yyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 220);

    auto ta1_x_yyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 221);

    auto ta1_x_yyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 222);

    auto ta1_x_yyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 223);

    auto ta1_x_yyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 224);

    auto ta1_x_yyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 225);

    auto ta1_x_yyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 226);

    auto ta1_x_yyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 227);

    auto ta1_x_yyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 228);

    auto ta1_x_yyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 229);

    auto ta1_x_yyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 230);

    auto ta1_x_yyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 232);

    auto ta1_x_yyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 233);

    auto ta1_x_yyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 234);

    auto ta1_x_yyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 236);

    auto ta1_x_yyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 237);

    auto ta1_x_yyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 240);

    auto ta1_x_yyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 241);

    auto ta1_x_yyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 245);

    auto ta1_x_yyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 246);

    auto ta1_x_yyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 247);

    auto ta1_x_yyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 248);

    auto ta1_x_yyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 249);

    auto ta1_x_yyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 250);

    auto ta1_x_yyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 251);

    auto ta1_x_yyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 252);

    auto ta1_x_yyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 253);

    auto ta1_x_yyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 254);

    auto ta1_x_yyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 255);

    auto ta1_x_yyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 256);

    auto ta1_x_yyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 257);

    auto ta1_x_yyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 258);

    auto ta1_x_yyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 259);

    auto ta1_x_yyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 260);

    auto ta1_x_yyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 261);

    auto ta1_x_yyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 262);

    auto ta1_x_yyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 263);

    auto ta1_x_yyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 264);

    auto ta1_x_yyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 265);

    auto ta1_x_yyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 266);

    auto ta1_x_yyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 267);

    auto ta1_x_yyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 268);

    auto ta1_x_yyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 269);

    auto ta1_x_yyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 270);

    auto ta1_x_yyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 271);

    auto ta1_x_yyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 272);

    auto ta1_x_yzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 273);

    auto ta1_x_yzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 275);

    auto ta1_x_yzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 277);

    auto ta1_x_yzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 278);

    auto ta1_x_yzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 280);

    auto ta1_x_yzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 281);

    auto ta1_x_yzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 282);

    auto ta1_x_yzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 284);

    auto ta1_x_yzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 285);

    auto ta1_x_yzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 286);

    auto ta1_x_yzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 287);

    auto ta1_x_yzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 288);

    auto ta1_x_yzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 289);

    auto ta1_x_yzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 290);

    auto ta1_x_yzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 291);

    auto ta1_x_yzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 292);

    auto ta1_x_yzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 293);

    auto ta1_x_zzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 294);

    auto ta1_x_zzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 295);

    auto ta1_x_zzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 296);

    auto ta1_x_zzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 297);

    auto ta1_x_zzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 298);

    auto ta1_x_zzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 299);

    auto ta1_x_zzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 300);

    auto ta1_x_zzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 301);

    auto ta1_x_zzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 302);

    auto ta1_x_zzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 303);

    auto ta1_x_zzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 304);

    auto ta1_x_zzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 305);

    auto ta1_x_zzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 306);

    auto ta1_x_zzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 307);

    auto ta1_x_zzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 308);

    auto ta1_x_zzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 309);

    auto ta1_x_zzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 310);

    auto ta1_x_zzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 311);

    auto ta1_x_zzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 312);

    auto ta1_x_zzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 313);

    auto ta1_x_zzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 314);

    auto ta1_y_xxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 315);

    auto ta1_y_xxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 316);

    auto ta1_y_xxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 317);

    auto ta1_y_xxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 318);

    auto ta1_y_xxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 319);

    auto ta1_y_xxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 320);

    auto ta1_y_xxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 321);

    auto ta1_y_xxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 322);

    auto ta1_y_xxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 323);

    auto ta1_y_xxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 324);

    auto ta1_y_xxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 325);

    auto ta1_y_xxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 326);

    auto ta1_y_xxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 327);

    auto ta1_y_xxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 328);

    auto ta1_y_xxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 329);

    auto ta1_y_xxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 330);

    auto ta1_y_xxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 331);

    auto ta1_y_xxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 332);

    auto ta1_y_xxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 333);

    auto ta1_y_xxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 334);

    auto ta1_y_xxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 335);

    auto ta1_y_xxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 336);

    auto ta1_y_xxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 337);

    auto ta1_y_xxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 338);

    auto ta1_y_xxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 339);

    auto ta1_y_xxxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 340);

    auto ta1_y_xxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 341);

    auto ta1_y_xxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 342);

    auto ta1_y_xxxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 343);

    auto ta1_y_xxxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 344);

    auto ta1_y_xxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 345);

    auto ta1_y_xxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 346);

    auto ta1_y_xxxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 347);

    auto ta1_y_xxxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 348);

    auto ta1_y_xxxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 349);

    auto ta1_y_xxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 350);

    auto ta1_y_xxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 351);

    auto ta1_y_xxxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 352);

    auto ta1_y_xxxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 353);

    auto ta1_y_xxxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 354);

    auto ta1_y_xxxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 355);

    auto ta1_y_xxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 357);

    auto ta1_y_xxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 358);

    auto ta1_y_xxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 359);

    auto ta1_y_xxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 360);

    auto ta1_y_xxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 362);

    auto ta1_y_xxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 363);

    auto ta1_y_xxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 366);

    auto ta1_y_xxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 367);

    auto ta1_y_xxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 371);

    auto ta1_y_xxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 373);

    auto ta1_y_xxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 374);

    auto ta1_y_xxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 375);

    auto ta1_y_xxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 376);

    auto ta1_y_xxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 377);

    auto ta1_y_xxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 378);

    auto ta1_y_xxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 379);

    auto ta1_y_xxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 380);

    auto ta1_y_xxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 381);

    auto ta1_y_xxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 382);

    auto ta1_y_xxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 383);

    auto ta1_y_xxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 384);

    auto ta1_y_xxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 385);

    auto ta1_y_xxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 386);

    auto ta1_y_xxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 387);

    auto ta1_y_xxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 388);

    auto ta1_y_xxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 389);

    auto ta1_y_xxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 390);

    auto ta1_y_xxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 391);

    auto ta1_y_xxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 392);

    auto ta1_y_xxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 393);

    auto ta1_y_xxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 394);

    auto ta1_y_xxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 395);

    auto ta1_y_xxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 396);

    auto ta1_y_xxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 397);

    auto ta1_y_xxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 398);

    auto ta1_y_xxyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 400);

    auto ta1_y_xxyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 402);

    auto ta1_y_xxyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 405);

    auto ta1_y_xxyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 409);

    auto ta1_y_xxyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 415);

    auto ta1_y_xxyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 416);

    auto ta1_y_xxyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 417);

    auto ta1_y_xxyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 418);

    auto ta1_y_xxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 420);

    auto ta1_y_xxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 421);

    auto ta1_y_xxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 422);

    auto ta1_y_xxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 423);

    auto ta1_y_xxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 424);

    auto ta1_y_xxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 425);

    auto ta1_y_xxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 426);

    auto ta1_y_xxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 427);

    auto ta1_y_xxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 428);

    auto ta1_y_xxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 429);

    auto ta1_y_xxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 430);

    auto ta1_y_xxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 431);

    auto ta1_y_xxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 432);

    auto ta1_y_xxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 433);

    auto ta1_y_xxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 434);

    auto ta1_y_xxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 435);

    auto ta1_y_xxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 436);

    auto ta1_y_xxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 437);

    auto ta1_y_xxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 438);

    auto ta1_y_xxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 439);

    auto ta1_y_xxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 440);

    auto ta1_y_xyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 441);

    auto ta1_y_xyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 442);

    auto ta1_y_xyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 444);

    auto ta1_y_xyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 445);

    auto ta1_y_xyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 447);

    auto ta1_y_xyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 448);

    auto ta1_y_xyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 449);

    auto ta1_y_xyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 451);

    auto ta1_y_xyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 452);

    auto ta1_y_xyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 453);

    auto ta1_y_xyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 454);

    auto ta1_y_xyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 456);

    auto ta1_y_xyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 457);

    auto ta1_y_xyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 458);

    auto ta1_y_xyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 459);

    auto ta1_y_xyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 460);

    auto ta1_y_xyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 461);

    auto ta1_y_xyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 478);

    auto ta1_y_xyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 479);

    auto ta1_y_xyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 480);

    auto ta1_y_xyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 481);

    auto ta1_y_xyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 482);

    auto ta1_y_xyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 498);

    auto ta1_y_xyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 499);

    auto ta1_y_xyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 500);

    auto ta1_y_xyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 501);

    auto ta1_y_xyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 502);

    auto ta1_y_xzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 504);

    auto ta1_y_xzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 506);

    auto ta1_y_xzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 508);

    auto ta1_y_xzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 509);

    auto ta1_y_xzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 511);

    auto ta1_y_xzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 512);

    auto ta1_y_xzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 513);

    auto ta1_y_xzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 515);

    auto ta1_y_xzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 516);

    auto ta1_y_xzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 517);

    auto ta1_y_xzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 518);

    auto ta1_y_xzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 519);

    auto ta1_y_xzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 520);

    auto ta1_y_xzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 521);

    auto ta1_y_xzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 522);

    auto ta1_y_xzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 523);

    auto ta1_y_xzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 524);

    auto ta1_y_yyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 525);

    auto ta1_y_yyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 526);

    auto ta1_y_yyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 527);

    auto ta1_y_yyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 528);

    auto ta1_y_yyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 529);

    auto ta1_y_yyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 530);

    auto ta1_y_yyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 531);

    auto ta1_y_yyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 532);

    auto ta1_y_yyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 533);

    auto ta1_y_yyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 534);

    auto ta1_y_yyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 535);

    auto ta1_y_yyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 536);

    auto ta1_y_yyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 537);

    auto ta1_y_yyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 538);

    auto ta1_y_yyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 539);

    auto ta1_y_yyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 540);

    auto ta1_y_yyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 541);

    auto ta1_y_yyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 542);

    auto ta1_y_yyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 543);

    auto ta1_y_yyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 544);

    auto ta1_y_yyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 545);

    auto ta1_y_yyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 546);

    auto ta1_y_yyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 547);

    auto ta1_y_yyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 548);

    auto ta1_y_yyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 549);

    auto ta1_y_yyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 550);

    auto ta1_y_yyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 551);

    auto ta1_y_yyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 552);

    auto ta1_y_yyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 553);

    auto ta1_y_yyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 554);

    auto ta1_y_yyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 555);

    auto ta1_y_yyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 556);

    auto ta1_y_yyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 557);

    auto ta1_y_yyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 558);

    auto ta1_y_yyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 559);

    auto ta1_y_yyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 560);

    auto ta1_y_yyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 561);

    auto ta1_y_yyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 562);

    auto ta1_y_yyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 563);

    auto ta1_y_yyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 564);

    auto ta1_y_yyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 565);

    auto ta1_y_yyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 566);

    auto ta1_y_yyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 567);

    auto ta1_y_yyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 568);

    auto ta1_y_yyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 569);

    auto ta1_y_yyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 570);

    auto ta1_y_yyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 571);

    auto ta1_y_yyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 572);

    auto ta1_y_yyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 573);

    auto ta1_y_yyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 574);

    auto ta1_y_yyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 575);

    auto ta1_y_yyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 576);

    auto ta1_y_yyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 577);

    auto ta1_y_yyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 578);

    auto ta1_y_yyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 579);

    auto ta1_y_yyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 580);

    auto ta1_y_yyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 581);

    auto ta1_y_yyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 582);

    auto ta1_y_yyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 583);

    auto ta1_y_yyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 584);

    auto ta1_y_yyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 585);

    auto ta1_y_yyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 586);

    auto ta1_y_yyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 587);

    auto ta1_y_yzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 589);

    auto ta1_y_yzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 590);

    auto ta1_y_yzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 591);

    auto ta1_y_yzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 592);

    auto ta1_y_yzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 593);

    auto ta1_y_yzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 594);

    auto ta1_y_yzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 595);

    auto ta1_y_yzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 596);

    auto ta1_y_yzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 597);

    auto ta1_y_yzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 598);

    auto ta1_y_yzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 599);

    auto ta1_y_yzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 600);

    auto ta1_y_yzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 601);

    auto ta1_y_yzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 602);

    auto ta1_y_yzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 603);

    auto ta1_y_yzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 604);

    auto ta1_y_yzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 605);

    auto ta1_y_yzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 606);

    auto ta1_y_yzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 607);

    auto ta1_y_yzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 608);

    auto ta1_y_zzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 609);

    auto ta1_y_zzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 610);

    auto ta1_y_zzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 611);

    auto ta1_y_zzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 612);

    auto ta1_y_zzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 613);

    auto ta1_y_zzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 614);

    auto ta1_y_zzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 615);

    auto ta1_y_zzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 616);

    auto ta1_y_zzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 617);

    auto ta1_y_zzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 618);

    auto ta1_y_zzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 619);

    auto ta1_y_zzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 620);

    auto ta1_y_zzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 621);

    auto ta1_y_zzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 622);

    auto ta1_y_zzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 623);

    auto ta1_y_zzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 624);

    auto ta1_y_zzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 625);

    auto ta1_y_zzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 626);

    auto ta1_y_zzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 627);

    auto ta1_y_zzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 628);

    auto ta1_y_zzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 629);

    auto ta1_z_xxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 630);

    auto ta1_z_xxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 631);

    auto ta1_z_xxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 632);

    auto ta1_z_xxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 633);

    auto ta1_z_xxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 634);

    auto ta1_z_xxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 635);

    auto ta1_z_xxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 636);

    auto ta1_z_xxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 637);

    auto ta1_z_xxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 638);

    auto ta1_z_xxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 639);

    auto ta1_z_xxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 640);

    auto ta1_z_xxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 641);

    auto ta1_z_xxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 642);

    auto ta1_z_xxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 643);

    auto ta1_z_xxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 644);

    auto ta1_z_xxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 645);

    auto ta1_z_xxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 646);

    auto ta1_z_xxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 647);

    auto ta1_z_xxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 648);

    auto ta1_z_xxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 649);

    auto ta1_z_xxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 650);

    auto ta1_z_xxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 651);

    auto ta1_z_xxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 652);

    auto ta1_z_xxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 653);

    auto ta1_z_xxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 654);

    auto ta1_z_xxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 656);

    auto ta1_z_xxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 657);

    auto ta1_z_xxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 660);

    auto ta1_z_xxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 661);

    auto ta1_z_xxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 665);

    auto ta1_z_xxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 666);

    auto ta1_z_xxxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 667);

    auto ta1_z_xxxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 668);

    auto ta1_z_xxxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 669);

    auto ta1_z_xxxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 670);

    auto ta1_z_xxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 672);

    auto ta1_z_xxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 673);

    auto ta1_z_xxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 674);

    auto ta1_z_xxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 675);

    auto ta1_z_xxxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 676);

    auto ta1_z_xxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 677);

    auto ta1_z_xxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 678);

    auto ta1_z_xxxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 679);

    auto ta1_z_xxxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 680);

    auto ta1_z_xxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 681);

    auto ta1_z_xxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 682);

    auto ta1_z_xxxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 683);

    auto ta1_z_xxxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 684);

    auto ta1_z_xxxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 685);

    auto ta1_z_xxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 686);

    auto ta1_z_xxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 688);

    auto ta1_z_xxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 689);

    auto ta1_z_xxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 690);

    auto ta1_z_xxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 691);

    auto ta1_z_xxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 692);

    auto ta1_z_xxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 693);

    auto ta1_z_xxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 694);

    auto ta1_z_xxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 695);

    auto ta1_z_xxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 696);

    auto ta1_z_xxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 697);

    auto ta1_z_xxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 698);

    auto ta1_z_xxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 699);

    auto ta1_z_xxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 700);

    auto ta1_z_xxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 701);

    auto ta1_z_xxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 702);

    auto ta1_z_xxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 703);

    auto ta1_z_xxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 704);

    auto ta1_z_xxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 705);

    auto ta1_z_xxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 706);

    auto ta1_z_xxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 707);

    auto ta1_z_xxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 708);

    auto ta1_z_xxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 709);

    auto ta1_z_xxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 710);

    auto ta1_z_xxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 711);

    auto ta1_z_xxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 712);

    auto ta1_z_xxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 713);

    auto ta1_z_xxyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 716);

    auto ta1_z_xxyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 719);

    auto ta1_z_xxyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 723);

    auto ta1_z_xxyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 728);

    auto ta1_z_xxyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 730);

    auto ta1_z_xxyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 731);

    auto ta1_z_xxyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 732);

    auto ta1_z_xxyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 733);

    auto ta1_z_xxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 735);

    auto ta1_z_xxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 736);

    auto ta1_z_xxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 737);

    auto ta1_z_xxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 738);

    auto ta1_z_xxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 739);

    auto ta1_z_xxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 740);

    auto ta1_z_xxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 741);

    auto ta1_z_xxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 742);

    auto ta1_z_xxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 743);

    auto ta1_z_xxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 744);

    auto ta1_z_xxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 745);

    auto ta1_z_xxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 746);

    auto ta1_z_xxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 747);

    auto ta1_z_xxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 748);

    auto ta1_z_xxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 749);

    auto ta1_z_xxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 750);

    auto ta1_z_xxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 751);

    auto ta1_z_xxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 752);

    auto ta1_z_xxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 753);

    auto ta1_z_xxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 754);

    auto ta1_z_xxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 755);

    auto ta1_z_xyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 756);

    auto ta1_z_xyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 757);

    auto ta1_z_xyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 759);

    auto ta1_z_xyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 760);

    auto ta1_z_xyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 762);

    auto ta1_z_xyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 763);

    auto ta1_z_xyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 764);

    auto ta1_z_xyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 766);

    auto ta1_z_xyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 767);

    auto ta1_z_xyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 768);

    auto ta1_z_xyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 769);

    auto ta1_z_xyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 771);

    auto ta1_z_xyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 772);

    auto ta1_z_xyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 773);

    auto ta1_z_xyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 774);

    auto ta1_z_xyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 775);

    auto ta1_z_xyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 776);

    auto ta1_z_xyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 793);

    auto ta1_z_xyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 794);

    auto ta1_z_xyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 795);

    auto ta1_z_xyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 796);

    auto ta1_z_xyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 797);

    auto ta1_z_xyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 813);

    auto ta1_z_xyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 814);

    auto ta1_z_xyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 815);

    auto ta1_z_xyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 816);

    auto ta1_z_xyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 817);

    auto ta1_z_xzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 819);

    auto ta1_z_xzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 821);

    auto ta1_z_xzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 823);

    auto ta1_z_xzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 824);

    auto ta1_z_xzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 826);

    auto ta1_z_xzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 827);

    auto ta1_z_xzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 828);

    auto ta1_z_xzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 830);

    auto ta1_z_xzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 831);

    auto ta1_z_xzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 832);

    auto ta1_z_xzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 833);

    auto ta1_z_xzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 834);

    auto ta1_z_xzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 835);

    auto ta1_z_xzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 836);

    auto ta1_z_xzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 837);

    auto ta1_z_xzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 838);

    auto ta1_z_xzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 839);

    auto ta1_z_yyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 840);

    auto ta1_z_yyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 841);

    auto ta1_z_yyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 842);

    auto ta1_z_yyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 843);

    auto ta1_z_yyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 844);

    auto ta1_z_yyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 845);

    auto ta1_z_yyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 846);

    auto ta1_z_yyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 847);

    auto ta1_z_yyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 848);

    auto ta1_z_yyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 849);

    auto ta1_z_yyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 850);

    auto ta1_z_yyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 851);

    auto ta1_z_yyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 852);

    auto ta1_z_yyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 853);

    auto ta1_z_yyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 854);

    auto ta1_z_yyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 855);

    auto ta1_z_yyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 856);

    auto ta1_z_yyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 857);

    auto ta1_z_yyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 858);

    auto ta1_z_yyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 859);

    auto ta1_z_yyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 860);

    auto ta1_z_yyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 862);

    auto ta1_z_yyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 863);

    auto ta1_z_yyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 864);

    auto ta1_z_yyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 865);

    auto ta1_z_yyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 866);

    auto ta1_z_yyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 867);

    auto ta1_z_yyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 868);

    auto ta1_z_yyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 869);

    auto ta1_z_yyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 870);

    auto ta1_z_yyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 871);

    auto ta1_z_yyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 872);

    auto ta1_z_yyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 873);

    auto ta1_z_yyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 874);

    auto ta1_z_yyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 875);

    auto ta1_z_yyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 876);

    auto ta1_z_yyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 877);

    auto ta1_z_yyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 878);

    auto ta1_z_yyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 879);

    auto ta1_z_yyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 880);

    auto ta1_z_yyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 881);

    auto ta1_z_yyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 882);

    auto ta1_z_yyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 883);

    auto ta1_z_yyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 884);

    auto ta1_z_yyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 885);

    auto ta1_z_yyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 886);

    auto ta1_z_yyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 887);

    auto ta1_z_yyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 888);

    auto ta1_z_yyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 889);

    auto ta1_z_yyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 890);

    auto ta1_z_yyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 891);

    auto ta1_z_yyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 892);

    auto ta1_z_yyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 893);

    auto ta1_z_yyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 894);

    auto ta1_z_yyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 895);

    auto ta1_z_yyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 896);

    auto ta1_z_yyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 897);

    auto ta1_z_yyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 898);

    auto ta1_z_yyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 899);

    auto ta1_z_yyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 900);

    auto ta1_z_yyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 901);

    auto ta1_z_yyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 902);

    auto ta1_z_yzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 903);

    auto ta1_z_yzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 904);

    auto ta1_z_yzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 905);

    auto ta1_z_yzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 906);

    auto ta1_z_yzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 907);

    auto ta1_z_yzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 908);

    auto ta1_z_yzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 909);

    auto ta1_z_yzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 910);

    auto ta1_z_yzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 911);

    auto ta1_z_yzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 912);

    auto ta1_z_yzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 913);

    auto ta1_z_yzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 914);

    auto ta1_z_yzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 915);

    auto ta1_z_yzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 916);

    auto ta1_z_yzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 917);

    auto ta1_z_yzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 918);

    auto ta1_z_yzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 919);

    auto ta1_z_yzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 920);

    auto ta1_z_yzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 921);

    auto ta1_z_yzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 922);

    auto ta1_z_yzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 923);

    auto ta1_z_zzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_gh + 924);

    auto ta1_z_zzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 925);

    auto ta1_z_zzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 926);

    auto ta1_z_zzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 927);

    auto ta1_z_zzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 928);

    auto ta1_z_zzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 929);

    auto ta1_z_zzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 930);

    auto ta1_z_zzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 931);

    auto ta1_z_zzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 932);

    auto ta1_z_zzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 933);

    auto ta1_z_zzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 934);

    auto ta1_z_zzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 935);

    auto ta1_z_zzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 936);

    auto ta1_z_zzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 937);

    auto ta1_z_zzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 938);

    auto ta1_z_zzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_gh + 939);

    auto ta1_z_zzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 940);

    auto ta1_z_zzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 941);

    auto ta1_z_zzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 942);

    auto ta1_z_zzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 943);

    auto ta1_z_zzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_gh + 944);

    // Set up components of auxiliary buffer : GH

    auto ta1_x_xxxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh);

    auto ta1_x_xxxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 1);

    auto ta1_x_xxxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 2);

    auto ta1_x_xxxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 3);

    auto ta1_x_xxxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 4);

    auto ta1_x_xxxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 5);

    auto ta1_x_xxxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 6);

    auto ta1_x_xxxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 7);

    auto ta1_x_xxxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 8);

    auto ta1_x_xxxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 9);

    auto ta1_x_xxxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 10);

    auto ta1_x_xxxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 11);

    auto ta1_x_xxxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 12);

    auto ta1_x_xxxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 13);

    auto ta1_x_xxxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 14);

    auto ta1_x_xxxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 15);

    auto ta1_x_xxxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 16);

    auto ta1_x_xxxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 17);

    auto ta1_x_xxxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 18);

    auto ta1_x_xxxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 19);

    auto ta1_x_xxxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 20);

    auto ta1_x_xxxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 21);

    auto ta1_x_xxxy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 22);

    auto ta1_x_xxxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 23);

    auto ta1_x_xxxy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 24);

    auto ta1_x_xxxy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 25);

    auto ta1_x_xxxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 26);

    auto ta1_x_xxxy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 27);

    auto ta1_x_xxxy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 28);

    auto ta1_x_xxxy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 29);

    auto ta1_x_xxxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 30);

    auto ta1_x_xxxy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 31);

    auto ta1_x_xxxy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 32);

    auto ta1_x_xxxy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 33);

    auto ta1_x_xxxy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 34);

    auto ta1_x_xxxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 35);

    auto ta1_x_xxxy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 36);

    auto ta1_x_xxxy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 41);

    auto ta1_x_xxxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 42);

    auto ta1_x_xxxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 43);

    auto ta1_x_xxxz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 44);

    auto ta1_x_xxxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 45);

    auto ta1_x_xxxz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 46);

    auto ta1_x_xxxz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 47);

    auto ta1_x_xxxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 48);

    auto ta1_x_xxxz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 49);

    auto ta1_x_xxxz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 50);

    auto ta1_x_xxxz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 51);

    auto ta1_x_xxxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 52);

    auto ta1_x_xxxz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 53);

    auto ta1_x_xxxz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 54);

    auto ta1_x_xxxz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 55);

    auto ta1_x_xxxz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 56);

    auto ta1_x_xxxz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 57);

    auto ta1_x_xxxz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 58);

    auto ta1_x_xxxz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 59);

    auto ta1_x_xxxz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 60);

    auto ta1_x_xxxz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 61);

    auto ta1_x_xxxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 62);

    auto ta1_x_xxyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 63);

    auto ta1_x_xxyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 64);

    auto ta1_x_xxyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 65);

    auto ta1_x_xxyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 66);

    auto ta1_x_xxyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 67);

    auto ta1_x_xxyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 68);

    auto ta1_x_xxyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 69);

    auto ta1_x_xxyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 70);

    auto ta1_x_xxyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 71);

    auto ta1_x_xxyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 72);

    auto ta1_x_xxyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 73);

    auto ta1_x_xxyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 74);

    auto ta1_x_xxyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 75);

    auto ta1_x_xxyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 76);

    auto ta1_x_xxyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 77);

    auto ta1_x_xxyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 78);

    auto ta1_x_xxyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 79);

    auto ta1_x_xxyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 80);

    auto ta1_x_xxyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 81);

    auto ta1_x_xxyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 82);

    auto ta1_x_xxyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 83);

    auto ta1_x_xxyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 86);

    auto ta1_x_xxyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 89);

    auto ta1_x_xxyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 93);

    auto ta1_x_xxyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 98);

    auto ta1_x_xxyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 104);

    auto ta1_x_xxzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 105);

    auto ta1_x_xxzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 106);

    auto ta1_x_xxzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 107);

    auto ta1_x_xxzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 108);

    auto ta1_x_xxzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 109);

    auto ta1_x_xxzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 110);

    auto ta1_x_xxzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 111);

    auto ta1_x_xxzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 112);

    auto ta1_x_xxzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 113);

    auto ta1_x_xxzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 114);

    auto ta1_x_xxzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 115);

    auto ta1_x_xxzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 116);

    auto ta1_x_xxzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 117);

    auto ta1_x_xxzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 118);

    auto ta1_x_xxzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 119);

    auto ta1_x_xxzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 120);

    auto ta1_x_xxzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 121);

    auto ta1_x_xxzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 122);

    auto ta1_x_xxzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 123);

    auto ta1_x_xxzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 124);

    auto ta1_x_xxzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 125);

    auto ta1_x_xyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 126);

    auto ta1_x_xyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 127);

    auto ta1_x_xyyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 128);

    auto ta1_x_xyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 129);

    auto ta1_x_xyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 130);

    auto ta1_x_xyyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 131);

    auto ta1_x_xyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 132);

    auto ta1_x_xyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 133);

    auto ta1_x_xyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 134);

    auto ta1_x_xyyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 135);

    auto ta1_x_xyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 136);

    auto ta1_x_xyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 137);

    auto ta1_x_xyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 138);

    auto ta1_x_xyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 139);

    auto ta1_x_xyyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 140);

    auto ta1_x_xyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 141);

    auto ta1_x_xyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 142);

    auto ta1_x_xyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 143);

    auto ta1_x_xyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 144);

    auto ta1_x_xyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 145);

    auto ta1_x_xyyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 148);

    auto ta1_x_xyyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 149);

    auto ta1_x_xyyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 150);

    auto ta1_x_xyyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 152);

    auto ta1_x_xyyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 153);

    auto ta1_x_xyyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 156);

    auto ta1_x_xyyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 157);

    auto ta1_x_xyyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 161);

    auto ta1_x_xyzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 168);

    auto ta1_x_xyzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 170);

    auto ta1_x_xyzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 173);

    auto ta1_x_xyzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 177);

    auto ta1_x_xyzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 182);

    auto ta1_x_xzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 189);

    auto ta1_x_xzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 190);

    auto ta1_x_xzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 191);

    auto ta1_x_xzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 192);

    auto ta1_x_xzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 193);

    auto ta1_x_xzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 194);

    auto ta1_x_xzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 195);

    auto ta1_x_xzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 196);

    auto ta1_x_xzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 197);

    auto ta1_x_xzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 198);

    auto ta1_x_xzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 199);

    auto ta1_x_xzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 200);

    auto ta1_x_xzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 201);

    auto ta1_x_xzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 202);

    auto ta1_x_xzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 203);

    auto ta1_x_xzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 205);

    auto ta1_x_xzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 206);

    auto ta1_x_xzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 207);

    auto ta1_x_xzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 208);

    auto ta1_x_xzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 209);

    auto ta1_x_yyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 210);

    auto ta1_x_yyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 211);

    auto ta1_x_yyyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 212);

    auto ta1_x_yyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 213);

    auto ta1_x_yyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 214);

    auto ta1_x_yyyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 215);

    auto ta1_x_yyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 216);

    auto ta1_x_yyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 217);

    auto ta1_x_yyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 218);

    auto ta1_x_yyyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 219);

    auto ta1_x_yyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 220);

    auto ta1_x_yyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 221);

    auto ta1_x_yyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 222);

    auto ta1_x_yyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 223);

    auto ta1_x_yyyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 224);

    auto ta1_x_yyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 225);

    auto ta1_x_yyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 226);

    auto ta1_x_yyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 227);

    auto ta1_x_yyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 228);

    auto ta1_x_yyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 229);

    auto ta1_x_yyyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 230);

    auto ta1_x_yyyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 232);

    auto ta1_x_yyyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 233);

    auto ta1_x_yyyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 234);

    auto ta1_x_yyyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 236);

    auto ta1_x_yyyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 237);

    auto ta1_x_yyyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 240);

    auto ta1_x_yyyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 241);

    auto ta1_x_yyyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 245);

    auto ta1_x_yyyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 246);

    auto ta1_x_yyyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 247);

    auto ta1_x_yyyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 248);

    auto ta1_x_yyyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 249);

    auto ta1_x_yyyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 250);

    auto ta1_x_yyyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 251);

    auto ta1_x_yyzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 252);

    auto ta1_x_yyzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 253);

    auto ta1_x_yyzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 254);

    auto ta1_x_yyzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 255);

    auto ta1_x_yyzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 256);

    auto ta1_x_yyzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 257);

    auto ta1_x_yyzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 258);

    auto ta1_x_yyzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 259);

    auto ta1_x_yyzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 260);

    auto ta1_x_yyzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 261);

    auto ta1_x_yyzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 262);

    auto ta1_x_yyzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 263);

    auto ta1_x_yyzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 264);

    auto ta1_x_yyzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 265);

    auto ta1_x_yyzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 266);

    auto ta1_x_yyzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 267);

    auto ta1_x_yyzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 268);

    auto ta1_x_yyzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 269);

    auto ta1_x_yyzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 270);

    auto ta1_x_yyzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 271);

    auto ta1_x_yyzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 272);

    auto ta1_x_yzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 273);

    auto ta1_x_yzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 275);

    auto ta1_x_yzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 277);

    auto ta1_x_yzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 278);

    auto ta1_x_yzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 280);

    auto ta1_x_yzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 281);

    auto ta1_x_yzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 282);

    auto ta1_x_yzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 284);

    auto ta1_x_yzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 285);

    auto ta1_x_yzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 286);

    auto ta1_x_yzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 287);

    auto ta1_x_yzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 288);

    auto ta1_x_yzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 289);

    auto ta1_x_yzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 290);

    auto ta1_x_yzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 291);

    auto ta1_x_yzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 292);

    auto ta1_x_yzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 293);

    auto ta1_x_zzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 294);

    auto ta1_x_zzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 295);

    auto ta1_x_zzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 296);

    auto ta1_x_zzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 297);

    auto ta1_x_zzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 298);

    auto ta1_x_zzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 299);

    auto ta1_x_zzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 300);

    auto ta1_x_zzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 301);

    auto ta1_x_zzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 302);

    auto ta1_x_zzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 303);

    auto ta1_x_zzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 304);

    auto ta1_x_zzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 305);

    auto ta1_x_zzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 306);

    auto ta1_x_zzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 307);

    auto ta1_x_zzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 308);

    auto ta1_x_zzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 309);

    auto ta1_x_zzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 310);

    auto ta1_x_zzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 311);

    auto ta1_x_zzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 312);

    auto ta1_x_zzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 313);

    auto ta1_x_zzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 314);

    auto ta1_y_xxxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 315);

    auto ta1_y_xxxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 316);

    auto ta1_y_xxxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 317);

    auto ta1_y_xxxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 318);

    auto ta1_y_xxxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 319);

    auto ta1_y_xxxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 320);

    auto ta1_y_xxxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 321);

    auto ta1_y_xxxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 322);

    auto ta1_y_xxxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 323);

    auto ta1_y_xxxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 324);

    auto ta1_y_xxxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 325);

    auto ta1_y_xxxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 326);

    auto ta1_y_xxxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 327);

    auto ta1_y_xxxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 328);

    auto ta1_y_xxxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 329);

    auto ta1_y_xxxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 330);

    auto ta1_y_xxxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 331);

    auto ta1_y_xxxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 332);

    auto ta1_y_xxxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 333);

    auto ta1_y_xxxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 334);

    auto ta1_y_xxxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 335);

    auto ta1_y_xxxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 336);

    auto ta1_y_xxxy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 337);

    auto ta1_y_xxxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 338);

    auto ta1_y_xxxy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 339);

    auto ta1_y_xxxy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 340);

    auto ta1_y_xxxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 341);

    auto ta1_y_xxxy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 342);

    auto ta1_y_xxxy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 343);

    auto ta1_y_xxxy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 344);

    auto ta1_y_xxxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 345);

    auto ta1_y_xxxy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 346);

    auto ta1_y_xxxy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 347);

    auto ta1_y_xxxy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 348);

    auto ta1_y_xxxy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 349);

    auto ta1_y_xxxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 350);

    auto ta1_y_xxxy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 351);

    auto ta1_y_xxxy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 352);

    auto ta1_y_xxxy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 353);

    auto ta1_y_xxxy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 354);

    auto ta1_y_xxxy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 355);

    auto ta1_y_xxxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 357);

    auto ta1_y_xxxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 358);

    auto ta1_y_xxxz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 359);

    auto ta1_y_xxxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 360);

    auto ta1_y_xxxz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 362);

    auto ta1_y_xxxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 363);

    auto ta1_y_xxxz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 366);

    auto ta1_y_xxxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 367);

    auto ta1_y_xxxz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 371);

    auto ta1_y_xxxz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 373);

    auto ta1_y_xxxz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 374);

    auto ta1_y_xxxz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 375);

    auto ta1_y_xxxz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 376);

    auto ta1_y_xxxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 377);

    auto ta1_y_xxyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 378);

    auto ta1_y_xxyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 379);

    auto ta1_y_xxyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 380);

    auto ta1_y_xxyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 381);

    auto ta1_y_xxyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 382);

    auto ta1_y_xxyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 383);

    auto ta1_y_xxyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 384);

    auto ta1_y_xxyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 385);

    auto ta1_y_xxyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 386);

    auto ta1_y_xxyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 387);

    auto ta1_y_xxyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 388);

    auto ta1_y_xxyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 389);

    auto ta1_y_xxyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 390);

    auto ta1_y_xxyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 391);

    auto ta1_y_xxyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 392);

    auto ta1_y_xxyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 393);

    auto ta1_y_xxyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 394);

    auto ta1_y_xxyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 395);

    auto ta1_y_xxyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 396);

    auto ta1_y_xxyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 397);

    auto ta1_y_xxyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 398);

    auto ta1_y_xxyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 400);

    auto ta1_y_xxyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 402);

    auto ta1_y_xxyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 405);

    auto ta1_y_xxyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 409);

    auto ta1_y_xxyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 415);

    auto ta1_y_xxyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 416);

    auto ta1_y_xxyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 417);

    auto ta1_y_xxyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 418);

    auto ta1_y_xxzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 420);

    auto ta1_y_xxzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 421);

    auto ta1_y_xxzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 422);

    auto ta1_y_xxzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 423);

    auto ta1_y_xxzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 424);

    auto ta1_y_xxzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 425);

    auto ta1_y_xxzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 426);

    auto ta1_y_xxzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 427);

    auto ta1_y_xxzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 428);

    auto ta1_y_xxzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 429);

    auto ta1_y_xxzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 430);

    auto ta1_y_xxzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 431);

    auto ta1_y_xxzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 432);

    auto ta1_y_xxzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 433);

    auto ta1_y_xxzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 434);

    auto ta1_y_xxzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 435);

    auto ta1_y_xxzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 436);

    auto ta1_y_xxzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 437);

    auto ta1_y_xxzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 438);

    auto ta1_y_xxzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 439);

    auto ta1_y_xxzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 440);

    auto ta1_y_xyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 441);

    auto ta1_y_xyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 442);

    auto ta1_y_xyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 444);

    auto ta1_y_xyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 445);

    auto ta1_y_xyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 447);

    auto ta1_y_xyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 448);

    auto ta1_y_xyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 449);

    auto ta1_y_xyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 451);

    auto ta1_y_xyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 452);

    auto ta1_y_xyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 453);

    auto ta1_y_xyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 454);

    auto ta1_y_xyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 456);

    auto ta1_y_xyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 457);

    auto ta1_y_xyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 458);

    auto ta1_y_xyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 459);

    auto ta1_y_xyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 460);

    auto ta1_y_xyyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 461);

    auto ta1_y_xyyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 478);

    auto ta1_y_xyyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 479);

    auto ta1_y_xyyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 480);

    auto ta1_y_xyyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 481);

    auto ta1_y_xyyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 482);

    auto ta1_y_xyzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 498);

    auto ta1_y_xyzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 499);

    auto ta1_y_xyzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 500);

    auto ta1_y_xyzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 501);

    auto ta1_y_xyzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 502);

    auto ta1_y_xzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 504);

    auto ta1_y_xzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 506);

    auto ta1_y_xzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 508);

    auto ta1_y_xzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 509);

    auto ta1_y_xzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 511);

    auto ta1_y_xzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 512);

    auto ta1_y_xzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 513);

    auto ta1_y_xzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 515);

    auto ta1_y_xzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 516);

    auto ta1_y_xzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 517);

    auto ta1_y_xzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 518);

    auto ta1_y_xzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 519);

    auto ta1_y_xzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 520);

    auto ta1_y_xzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 521);

    auto ta1_y_xzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 522);

    auto ta1_y_xzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 523);

    auto ta1_y_xzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 524);

    auto ta1_y_yyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 525);

    auto ta1_y_yyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 526);

    auto ta1_y_yyyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 527);

    auto ta1_y_yyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 528);

    auto ta1_y_yyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 529);

    auto ta1_y_yyyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 530);

    auto ta1_y_yyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 531);

    auto ta1_y_yyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 532);

    auto ta1_y_yyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 533);

    auto ta1_y_yyyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 534);

    auto ta1_y_yyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 535);

    auto ta1_y_yyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 536);

    auto ta1_y_yyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 537);

    auto ta1_y_yyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 538);

    auto ta1_y_yyyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 539);

    auto ta1_y_yyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 540);

    auto ta1_y_yyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 541);

    auto ta1_y_yyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 542);

    auto ta1_y_yyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 543);

    auto ta1_y_yyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 544);

    auto ta1_y_yyyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 545);

    auto ta1_y_yyyz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 546);

    auto ta1_y_yyyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 547);

    auto ta1_y_yyyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 548);

    auto ta1_y_yyyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 549);

    auto ta1_y_yyyz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 550);

    auto ta1_y_yyyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 551);

    auto ta1_y_yyyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 552);

    auto ta1_y_yyyz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 553);

    auto ta1_y_yyyz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 554);

    auto ta1_y_yyyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 555);

    auto ta1_y_yyyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 556);

    auto ta1_y_yyyz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 557);

    auto ta1_y_yyyz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 558);

    auto ta1_y_yyyz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 559);

    auto ta1_y_yyyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 560);

    auto ta1_y_yyyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 561);

    auto ta1_y_yyyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 562);

    auto ta1_y_yyyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 563);

    auto ta1_y_yyyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 564);

    auto ta1_y_yyyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 565);

    auto ta1_y_yyyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 566);

    auto ta1_y_yyzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 567);

    auto ta1_y_yyzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 568);

    auto ta1_y_yyzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 569);

    auto ta1_y_yyzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 570);

    auto ta1_y_yyzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 571);

    auto ta1_y_yyzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 572);

    auto ta1_y_yyzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 573);

    auto ta1_y_yyzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 574);

    auto ta1_y_yyzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 575);

    auto ta1_y_yyzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 576);

    auto ta1_y_yyzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 577);

    auto ta1_y_yyzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 578);

    auto ta1_y_yyzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 579);

    auto ta1_y_yyzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 580);

    auto ta1_y_yyzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 581);

    auto ta1_y_yyzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 582);

    auto ta1_y_yyzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 583);

    auto ta1_y_yyzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 584);

    auto ta1_y_yyzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 585);

    auto ta1_y_yyzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 586);

    auto ta1_y_yyzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 587);

    auto ta1_y_yzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 589);

    auto ta1_y_yzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 590);

    auto ta1_y_yzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 591);

    auto ta1_y_yzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 592);

    auto ta1_y_yzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 593);

    auto ta1_y_yzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 594);

    auto ta1_y_yzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 595);

    auto ta1_y_yzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 596);

    auto ta1_y_yzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 597);

    auto ta1_y_yzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 598);

    auto ta1_y_yzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 599);

    auto ta1_y_yzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 600);

    auto ta1_y_yzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 601);

    auto ta1_y_yzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 602);

    auto ta1_y_yzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 603);

    auto ta1_y_yzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 604);

    auto ta1_y_yzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 605);

    auto ta1_y_yzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 606);

    auto ta1_y_yzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 607);

    auto ta1_y_yzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 608);

    auto ta1_y_zzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 609);

    auto ta1_y_zzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 610);

    auto ta1_y_zzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 611);

    auto ta1_y_zzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 612);

    auto ta1_y_zzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 613);

    auto ta1_y_zzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 614);

    auto ta1_y_zzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 615);

    auto ta1_y_zzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 616);

    auto ta1_y_zzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 617);

    auto ta1_y_zzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 618);

    auto ta1_y_zzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 619);

    auto ta1_y_zzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 620);

    auto ta1_y_zzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 621);

    auto ta1_y_zzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 622);

    auto ta1_y_zzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 623);

    auto ta1_y_zzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 624);

    auto ta1_y_zzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 625);

    auto ta1_y_zzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 626);

    auto ta1_y_zzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 627);

    auto ta1_y_zzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 628);

    auto ta1_y_zzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 629);

    auto ta1_z_xxxx_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 630);

    auto ta1_z_xxxx_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 631);

    auto ta1_z_xxxx_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 632);

    auto ta1_z_xxxx_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 633);

    auto ta1_z_xxxx_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 634);

    auto ta1_z_xxxx_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 635);

    auto ta1_z_xxxx_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 636);

    auto ta1_z_xxxx_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 637);

    auto ta1_z_xxxx_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 638);

    auto ta1_z_xxxx_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 639);

    auto ta1_z_xxxx_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 640);

    auto ta1_z_xxxx_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 641);

    auto ta1_z_xxxx_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 642);

    auto ta1_z_xxxx_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 643);

    auto ta1_z_xxxx_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 644);

    auto ta1_z_xxxx_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 645);

    auto ta1_z_xxxx_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 646);

    auto ta1_z_xxxx_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 647);

    auto ta1_z_xxxx_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 648);

    auto ta1_z_xxxx_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 649);

    auto ta1_z_xxxx_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 650);

    auto ta1_z_xxxy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 651);

    auto ta1_z_xxxy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 652);

    auto ta1_z_xxxy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 653);

    auto ta1_z_xxxy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 654);

    auto ta1_z_xxxy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 656);

    auto ta1_z_xxxy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 657);

    auto ta1_z_xxxy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 660);

    auto ta1_z_xxxy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 661);

    auto ta1_z_xxxy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 665);

    auto ta1_z_xxxy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 666);

    auto ta1_z_xxxy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 667);

    auto ta1_z_xxxy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 668);

    auto ta1_z_xxxy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 669);

    auto ta1_z_xxxy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 670);

    auto ta1_z_xxxz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 672);

    auto ta1_z_xxxz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 673);

    auto ta1_z_xxxz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 674);

    auto ta1_z_xxxz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 675);

    auto ta1_z_xxxz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 676);

    auto ta1_z_xxxz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 677);

    auto ta1_z_xxxz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 678);

    auto ta1_z_xxxz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 679);

    auto ta1_z_xxxz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 680);

    auto ta1_z_xxxz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 681);

    auto ta1_z_xxxz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 682);

    auto ta1_z_xxxz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 683);

    auto ta1_z_xxxz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 684);

    auto ta1_z_xxxz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 685);

    auto ta1_z_xxxz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 686);

    auto ta1_z_xxxz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 688);

    auto ta1_z_xxxz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 689);

    auto ta1_z_xxxz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 690);

    auto ta1_z_xxxz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 691);

    auto ta1_z_xxxz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 692);

    auto ta1_z_xxyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 693);

    auto ta1_z_xxyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 694);

    auto ta1_z_xxyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 695);

    auto ta1_z_xxyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 696);

    auto ta1_z_xxyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 697);

    auto ta1_z_xxyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 698);

    auto ta1_z_xxyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 699);

    auto ta1_z_xxyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 700);

    auto ta1_z_xxyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 701);

    auto ta1_z_xxyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 702);

    auto ta1_z_xxyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 703);

    auto ta1_z_xxyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 704);

    auto ta1_z_xxyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 705);

    auto ta1_z_xxyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 706);

    auto ta1_z_xxyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 707);

    auto ta1_z_xxyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 708);

    auto ta1_z_xxyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 709);

    auto ta1_z_xxyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 710);

    auto ta1_z_xxyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 711);

    auto ta1_z_xxyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 712);

    auto ta1_z_xxyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 713);

    auto ta1_z_xxyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 716);

    auto ta1_z_xxyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 719);

    auto ta1_z_xxyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 723);

    auto ta1_z_xxyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 728);

    auto ta1_z_xxyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 730);

    auto ta1_z_xxyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 731);

    auto ta1_z_xxyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 732);

    auto ta1_z_xxyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 733);

    auto ta1_z_xxzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 735);

    auto ta1_z_xxzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 736);

    auto ta1_z_xxzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 737);

    auto ta1_z_xxzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 738);

    auto ta1_z_xxzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 739);

    auto ta1_z_xxzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 740);

    auto ta1_z_xxzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 741);

    auto ta1_z_xxzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 742);

    auto ta1_z_xxzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 743);

    auto ta1_z_xxzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 744);

    auto ta1_z_xxzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 745);

    auto ta1_z_xxzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 746);

    auto ta1_z_xxzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 747);

    auto ta1_z_xxzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 748);

    auto ta1_z_xxzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 749);

    auto ta1_z_xxzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 750);

    auto ta1_z_xxzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 751);

    auto ta1_z_xxzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 752);

    auto ta1_z_xxzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 753);

    auto ta1_z_xxzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 754);

    auto ta1_z_xxzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 755);

    auto ta1_z_xyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 756);

    auto ta1_z_xyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 757);

    auto ta1_z_xyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 759);

    auto ta1_z_xyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 760);

    auto ta1_z_xyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 762);

    auto ta1_z_xyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 763);

    auto ta1_z_xyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 764);

    auto ta1_z_xyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 766);

    auto ta1_z_xyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 767);

    auto ta1_z_xyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 768);

    auto ta1_z_xyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 769);

    auto ta1_z_xyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 771);

    auto ta1_z_xyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 772);

    auto ta1_z_xyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 773);

    auto ta1_z_xyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 774);

    auto ta1_z_xyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 775);

    auto ta1_z_xyyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 776);

    auto ta1_z_xyyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 793);

    auto ta1_z_xyyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 794);

    auto ta1_z_xyyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 795);

    auto ta1_z_xyyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 796);

    auto ta1_z_xyyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 797);

    auto ta1_z_xyzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 813);

    auto ta1_z_xyzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 814);

    auto ta1_z_xyzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 815);

    auto ta1_z_xyzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 816);

    auto ta1_z_xyzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 817);

    auto ta1_z_xzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 819);

    auto ta1_z_xzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 821);

    auto ta1_z_xzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 823);

    auto ta1_z_xzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 824);

    auto ta1_z_xzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 826);

    auto ta1_z_xzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 827);

    auto ta1_z_xzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 828);

    auto ta1_z_xzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 830);

    auto ta1_z_xzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 831);

    auto ta1_z_xzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 832);

    auto ta1_z_xzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 833);

    auto ta1_z_xzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 834);

    auto ta1_z_xzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 835);

    auto ta1_z_xzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 836);

    auto ta1_z_xzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 837);

    auto ta1_z_xzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 838);

    auto ta1_z_xzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 839);

    auto ta1_z_yyyy_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 840);

    auto ta1_z_yyyy_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 841);

    auto ta1_z_yyyy_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 842);

    auto ta1_z_yyyy_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 843);

    auto ta1_z_yyyy_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 844);

    auto ta1_z_yyyy_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 845);

    auto ta1_z_yyyy_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 846);

    auto ta1_z_yyyy_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 847);

    auto ta1_z_yyyy_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 848);

    auto ta1_z_yyyy_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 849);

    auto ta1_z_yyyy_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 850);

    auto ta1_z_yyyy_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 851);

    auto ta1_z_yyyy_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 852);

    auto ta1_z_yyyy_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 853);

    auto ta1_z_yyyy_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 854);

    auto ta1_z_yyyy_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 855);

    auto ta1_z_yyyy_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 856);

    auto ta1_z_yyyy_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 857);

    auto ta1_z_yyyy_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 858);

    auto ta1_z_yyyy_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 859);

    auto ta1_z_yyyy_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 860);

    auto ta1_z_yyyz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 862);

    auto ta1_z_yyyz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 863);

    auto ta1_z_yyyz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 864);

    auto ta1_z_yyyz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 865);

    auto ta1_z_yyyz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 866);

    auto ta1_z_yyyz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 867);

    auto ta1_z_yyyz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 868);

    auto ta1_z_yyyz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 869);

    auto ta1_z_yyyz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 870);

    auto ta1_z_yyyz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 871);

    auto ta1_z_yyyz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 872);

    auto ta1_z_yyyz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 873);

    auto ta1_z_yyyz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 874);

    auto ta1_z_yyyz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 875);

    auto ta1_z_yyyz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 876);

    auto ta1_z_yyyz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 877);

    auto ta1_z_yyyz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 878);

    auto ta1_z_yyyz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 879);

    auto ta1_z_yyyz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 880);

    auto ta1_z_yyyz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 881);

    auto ta1_z_yyzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 882);

    auto ta1_z_yyzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 883);

    auto ta1_z_yyzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 884);

    auto ta1_z_yyzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 885);

    auto ta1_z_yyzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 886);

    auto ta1_z_yyzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 887);

    auto ta1_z_yyzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 888);

    auto ta1_z_yyzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 889);

    auto ta1_z_yyzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 890);

    auto ta1_z_yyzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 891);

    auto ta1_z_yyzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 892);

    auto ta1_z_yyzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 893);

    auto ta1_z_yyzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 894);

    auto ta1_z_yyzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 895);

    auto ta1_z_yyzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 896);

    auto ta1_z_yyzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 897);

    auto ta1_z_yyzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 898);

    auto ta1_z_yyzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 899);

    auto ta1_z_yyzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 900);

    auto ta1_z_yyzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 901);

    auto ta1_z_yyzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 902);

    auto ta1_z_yzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 903);

    auto ta1_z_yzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 904);

    auto ta1_z_yzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 905);

    auto ta1_z_yzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 906);

    auto ta1_z_yzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 907);

    auto ta1_z_yzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 908);

    auto ta1_z_yzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 909);

    auto ta1_z_yzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 910);

    auto ta1_z_yzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 911);

    auto ta1_z_yzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 912);

    auto ta1_z_yzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 913);

    auto ta1_z_yzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 914);

    auto ta1_z_yzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 915);

    auto ta1_z_yzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 916);

    auto ta1_z_yzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 917);

    auto ta1_z_yzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 918);

    auto ta1_z_yzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 919);

    auto ta1_z_yzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 920);

    auto ta1_z_yzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 921);

    auto ta1_z_yzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 922);

    auto ta1_z_yzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 923);

    auto ta1_z_zzzz_xxxxx_1 = pbuffer.data(idx_npot_geom_010_1_gh + 924);

    auto ta1_z_zzzz_xxxxy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 925);

    auto ta1_z_zzzz_xxxxz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 926);

    auto ta1_z_zzzz_xxxyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 927);

    auto ta1_z_zzzz_xxxyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 928);

    auto ta1_z_zzzz_xxxzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 929);

    auto ta1_z_zzzz_xxyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 930);

    auto ta1_z_zzzz_xxyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 931);

    auto ta1_z_zzzz_xxyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 932);

    auto ta1_z_zzzz_xxzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 933);

    auto ta1_z_zzzz_xyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 934);

    auto ta1_z_zzzz_xyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 935);

    auto ta1_z_zzzz_xyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 936);

    auto ta1_z_zzzz_xyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 937);

    auto ta1_z_zzzz_xzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 938);

    auto ta1_z_zzzz_yyyyy_1 = pbuffer.data(idx_npot_geom_010_1_gh + 939);

    auto ta1_z_zzzz_yyyyz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 940);

    auto ta1_z_zzzz_yyyzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 941);

    auto ta1_z_zzzz_yyzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 942);

    auto ta1_z_zzzz_yzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 943);

    auto ta1_z_zzzz_zzzzz_1 = pbuffer.data(idx_npot_geom_010_1_gh + 944);

    // Set up 0-21 components of targeted buffer : HH

    auto ta1_x_xxxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh);

    auto ta1_x_xxxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1);

    auto ta1_x_xxxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 2);

    auto ta1_x_xxxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 3);

    auto ta1_x_xxxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 4);

    auto ta1_x_xxxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 5);

    auto ta1_x_xxxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 6);

    auto ta1_x_xxxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 7);

    auto ta1_x_xxxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 8);

    auto ta1_x_xxxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 9);

    auto ta1_x_xxxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 10);

    auto ta1_x_xxxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 11);

    auto ta1_x_xxxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 12);

    auto ta1_x_xxxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 13);

    auto ta1_x_xxxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 14);

    auto ta1_x_xxxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 15);

    auto ta1_x_xxxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 16);

    auto ta1_x_xxxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 17);

    auto ta1_x_xxxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 18);

    auto ta1_x_xxxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 19);

    auto ta1_x_xxxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 20);

    #pragma omp simd aligned(pa_x, pc_x, ta1_x_xxx_xxxxx_0, ta1_x_xxx_xxxxx_1, ta1_x_xxx_xxxxy_0, ta1_x_xxx_xxxxy_1, ta1_x_xxx_xxxxz_0, ta1_x_xxx_xxxxz_1, ta1_x_xxx_xxxyy_0, ta1_x_xxx_xxxyy_1, ta1_x_xxx_xxxyz_0, ta1_x_xxx_xxxyz_1, ta1_x_xxx_xxxzz_0, ta1_x_xxx_xxxzz_1, ta1_x_xxx_xxyyy_0, ta1_x_xxx_xxyyy_1, ta1_x_xxx_xxyyz_0, ta1_x_xxx_xxyyz_1, ta1_x_xxx_xxyzz_0, ta1_x_xxx_xxyzz_1, ta1_x_xxx_xxzzz_0, ta1_x_xxx_xxzzz_1, ta1_x_xxx_xyyyy_0, ta1_x_xxx_xyyyy_1, ta1_x_xxx_xyyyz_0, ta1_x_xxx_xyyyz_1, ta1_x_xxx_xyyzz_0, ta1_x_xxx_xyyzz_1, ta1_x_xxx_xyzzz_0, ta1_x_xxx_xyzzz_1, ta1_x_xxx_xzzzz_0, ta1_x_xxx_xzzzz_1, ta1_x_xxx_yyyyy_0, ta1_x_xxx_yyyyy_1, ta1_x_xxx_yyyyz_0, ta1_x_xxx_yyyyz_1, ta1_x_xxx_yyyzz_0, ta1_x_xxx_yyyzz_1, ta1_x_xxx_yyzzz_0, ta1_x_xxx_yyzzz_1, ta1_x_xxx_yzzzz_0, ta1_x_xxx_yzzzz_1, ta1_x_xxx_zzzzz_0, ta1_x_xxx_zzzzz_1, ta1_x_xxxx_xxxx_0, ta1_x_xxxx_xxxx_1, ta1_x_xxxx_xxxxx_0, ta1_x_xxxx_xxxxx_1, ta1_x_xxxx_xxxxy_0, ta1_x_xxxx_xxxxy_1, ta1_x_xxxx_xxxxz_0, ta1_x_xxxx_xxxxz_1, ta1_x_xxxx_xxxy_0, ta1_x_xxxx_xxxy_1, ta1_x_xxxx_xxxyy_0, ta1_x_xxxx_xxxyy_1, ta1_x_xxxx_xxxyz_0, ta1_x_xxxx_xxxyz_1, ta1_x_xxxx_xxxz_0, ta1_x_xxxx_xxxz_1, ta1_x_xxxx_xxxzz_0, ta1_x_xxxx_xxxzz_1, ta1_x_xxxx_xxyy_0, ta1_x_xxxx_xxyy_1, ta1_x_xxxx_xxyyy_0, ta1_x_xxxx_xxyyy_1, ta1_x_xxxx_xxyyz_0, ta1_x_xxxx_xxyyz_1, ta1_x_xxxx_xxyz_0, ta1_x_xxxx_xxyz_1, ta1_x_xxxx_xxyzz_0, ta1_x_xxxx_xxyzz_1, ta1_x_xxxx_xxzz_0, ta1_x_xxxx_xxzz_1, ta1_x_xxxx_xxzzz_0, ta1_x_xxxx_xxzzz_1, ta1_x_xxxx_xyyy_0, ta1_x_xxxx_xyyy_1, ta1_x_xxxx_xyyyy_0, ta1_x_xxxx_xyyyy_1, ta1_x_xxxx_xyyyz_0, ta1_x_xxxx_xyyyz_1, ta1_x_xxxx_xyyz_0, ta1_x_xxxx_xyyz_1, ta1_x_xxxx_xyyzz_0, ta1_x_xxxx_xyyzz_1, ta1_x_xxxx_xyzz_0, ta1_x_xxxx_xyzz_1, ta1_x_xxxx_xyzzz_0, ta1_x_xxxx_xyzzz_1, ta1_x_xxxx_xzzz_0, ta1_x_xxxx_xzzz_1, ta1_x_xxxx_xzzzz_0, ta1_x_xxxx_xzzzz_1, ta1_x_xxxx_yyyy_0, ta1_x_xxxx_yyyy_1, ta1_x_xxxx_yyyyy_0, ta1_x_xxxx_yyyyy_1, ta1_x_xxxx_yyyyz_0, ta1_x_xxxx_yyyyz_1, ta1_x_xxxx_yyyz_0, ta1_x_xxxx_yyyz_1, ta1_x_xxxx_yyyzz_0, ta1_x_xxxx_yyyzz_1, ta1_x_xxxx_yyzz_0, ta1_x_xxxx_yyzz_1, ta1_x_xxxx_yyzzz_0, ta1_x_xxxx_yyzzz_1, ta1_x_xxxx_yzzz_0, ta1_x_xxxx_yzzz_1, ta1_x_xxxx_yzzzz_0, ta1_x_xxxx_yzzzz_1, ta1_x_xxxx_zzzz_0, ta1_x_xxxx_zzzz_1, ta1_x_xxxx_zzzzz_0, ta1_x_xxxx_zzzzz_1, ta1_x_xxxxx_xxxxx_0, ta1_x_xxxxx_xxxxy_0, ta1_x_xxxxx_xxxxz_0, ta1_x_xxxxx_xxxyy_0, ta1_x_xxxxx_xxxyz_0, ta1_x_xxxxx_xxxzz_0, ta1_x_xxxxx_xxyyy_0, ta1_x_xxxxx_xxyyz_0, ta1_x_xxxxx_xxyzz_0, ta1_x_xxxxx_xxzzz_0, ta1_x_xxxxx_xyyyy_0, ta1_x_xxxxx_xyyyz_0, ta1_x_xxxxx_xyyzz_0, ta1_x_xxxxx_xyzzz_0, ta1_x_xxxxx_xzzzz_0, ta1_x_xxxxx_yyyyy_0, ta1_x_xxxxx_yyyyz_0, ta1_x_xxxxx_yyyzz_0, ta1_x_xxxxx_yyzzz_0, ta1_x_xxxxx_yzzzz_0, ta1_x_xxxxx_zzzzz_0, ta_xxxx_xxxxx_1, ta_xxxx_xxxxy_1, ta_xxxx_xxxxz_1, ta_xxxx_xxxyy_1, ta_xxxx_xxxyz_1, ta_xxxx_xxxzz_1, ta_xxxx_xxyyy_1, ta_xxxx_xxyyz_1, ta_xxxx_xxyzz_1, ta_xxxx_xxzzz_1, ta_xxxx_xyyyy_1, ta_xxxx_xyyyz_1, ta_xxxx_xyyzz_1, ta_xxxx_xyzzz_1, ta_xxxx_xzzzz_1, ta_xxxx_yyyyy_1, ta_xxxx_yyyyz_1, ta_xxxx_yyyzz_1, ta_xxxx_yyzzz_1, ta_xxxx_yzzzz_1, ta_xxxx_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxxx_xxxxx_0[i] = 4.0 * ta1_x_xxx_xxxxx_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxxx_1[i] * fe_0 + 5.0 * ta1_x_xxxx_xxxx_0[i] * fe_0 - 5.0 * ta1_x_xxxx_xxxx_1[i] * fe_0 + ta_xxxx_xxxxx_1[i] + ta1_x_xxxx_xxxxx_0[i] * pa_x[i] - ta1_x_xxxx_xxxxx_1[i] * pc_x[i];

        ta1_x_xxxxx_xxxxy_0[i] = 4.0 * ta1_x_xxx_xxxxy_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxxy_1[i] * fe_0 + 4.0 * ta1_x_xxxx_xxxy_0[i] * fe_0 - 4.0 * ta1_x_xxxx_xxxy_1[i] * fe_0 + ta_xxxx_xxxxy_1[i] + ta1_x_xxxx_xxxxy_0[i] * pa_x[i] - ta1_x_xxxx_xxxxy_1[i] * pc_x[i];

        ta1_x_xxxxx_xxxxz_0[i] = 4.0 * ta1_x_xxx_xxxxz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxxz_1[i] * fe_0 + 4.0 * ta1_x_xxxx_xxxz_0[i] * fe_0 - 4.0 * ta1_x_xxxx_xxxz_1[i] * fe_0 + ta_xxxx_xxxxz_1[i] + ta1_x_xxxx_xxxxz_0[i] * pa_x[i] - ta1_x_xxxx_xxxxz_1[i] * pc_x[i];

        ta1_x_xxxxx_xxxyy_0[i] = 4.0 * ta1_x_xxx_xxxyy_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxyy_1[i] * fe_0 + 3.0 * ta1_x_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xxyy_1[i] * fe_0 + ta_xxxx_xxxyy_1[i] + ta1_x_xxxx_xxxyy_0[i] * pa_x[i] - ta1_x_xxxx_xxxyy_1[i] * pc_x[i];

        ta1_x_xxxxx_xxxyz_0[i] = 4.0 * ta1_x_xxx_xxxyz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxyz_1[i] * fe_0 + 3.0 * ta1_x_xxxx_xxyz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xxyz_1[i] * fe_0 + ta_xxxx_xxxyz_1[i] + ta1_x_xxxx_xxxyz_0[i] * pa_x[i] - ta1_x_xxxx_xxxyz_1[i] * pc_x[i];

        ta1_x_xxxxx_xxxzz_0[i] = 4.0 * ta1_x_xxx_xxxzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxxzz_1[i] * fe_0 + 3.0 * ta1_x_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xxzz_1[i] * fe_0 + ta_xxxx_xxxzz_1[i] + ta1_x_xxxx_xxxzz_0[i] * pa_x[i] - ta1_x_xxxx_xxxzz_1[i] * pc_x[i];

        ta1_x_xxxxx_xxyyy_0[i] = 4.0 * ta1_x_xxx_xxyyy_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxyyy_1[i] * fe_0 + 2.0 * ta1_x_xxxx_xyyy_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xyyy_1[i] * fe_0 + ta_xxxx_xxyyy_1[i] + ta1_x_xxxx_xxyyy_0[i] * pa_x[i] - ta1_x_xxxx_xxyyy_1[i] * pc_x[i];

        ta1_x_xxxxx_xxyyz_0[i] = 4.0 * ta1_x_xxx_xxyyz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xyyz_1[i] * fe_0 + ta_xxxx_xxyyz_1[i] + ta1_x_xxxx_xxyyz_0[i] * pa_x[i] - ta1_x_xxxx_xxyyz_1[i] * pc_x[i];

        ta1_x_xxxxx_xxyzz_0[i] = 4.0 * ta1_x_xxx_xxyzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxyzz_1[i] * fe_0 + 2.0 * ta1_x_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xyzz_1[i] * fe_0 + ta_xxxx_xxyzz_1[i] + ta1_x_xxxx_xxyzz_0[i] * pa_x[i] - ta1_x_xxxx_xxyzz_1[i] * pc_x[i];

        ta1_x_xxxxx_xxzzz_0[i] = 4.0 * ta1_x_xxx_xxzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xxzzz_1[i] * fe_0 + 2.0 * ta1_x_xxxx_xzzz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xzzz_1[i] * fe_0 + ta_xxxx_xxzzz_1[i] + ta1_x_xxxx_xxzzz_0[i] * pa_x[i] - ta1_x_xxxx_xxzzz_1[i] * pc_x[i];

        ta1_x_xxxxx_xyyyy_0[i] = 4.0 * ta1_x_xxx_xyyyy_0[i] * fe_0 - 4.0 * ta1_x_xxx_xyyyy_1[i] * fe_0 + ta1_x_xxxx_yyyy_0[i] * fe_0 - ta1_x_xxxx_yyyy_1[i] * fe_0 + ta_xxxx_xyyyy_1[i] + ta1_x_xxxx_xyyyy_0[i] * pa_x[i] - ta1_x_xxxx_xyyyy_1[i] * pc_x[i];

        ta1_x_xxxxx_xyyyz_0[i] = 4.0 * ta1_x_xxx_xyyyz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xyyyz_1[i] * fe_0 + ta1_x_xxxx_yyyz_0[i] * fe_0 - ta1_x_xxxx_yyyz_1[i] * fe_0 + ta_xxxx_xyyyz_1[i] + ta1_x_xxxx_xyyyz_0[i] * pa_x[i] - ta1_x_xxxx_xyyyz_1[i] * pc_x[i];

        ta1_x_xxxxx_xyyzz_0[i] = 4.0 * ta1_x_xxx_xyyzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xyyzz_1[i] * fe_0 + ta1_x_xxxx_yyzz_0[i] * fe_0 - ta1_x_xxxx_yyzz_1[i] * fe_0 + ta_xxxx_xyyzz_1[i] + ta1_x_xxxx_xyyzz_0[i] * pa_x[i] - ta1_x_xxxx_xyyzz_1[i] * pc_x[i];

        ta1_x_xxxxx_xyzzz_0[i] = 4.0 * ta1_x_xxx_xyzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xyzzz_1[i] * fe_0 + ta1_x_xxxx_yzzz_0[i] * fe_0 - ta1_x_xxxx_yzzz_1[i] * fe_0 + ta_xxxx_xyzzz_1[i] + ta1_x_xxxx_xyzzz_0[i] * pa_x[i] - ta1_x_xxxx_xyzzz_1[i] * pc_x[i];

        ta1_x_xxxxx_xzzzz_0[i] = 4.0 * ta1_x_xxx_xzzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_xzzzz_1[i] * fe_0 + ta1_x_xxxx_zzzz_0[i] * fe_0 - ta1_x_xxxx_zzzz_1[i] * fe_0 + ta_xxxx_xzzzz_1[i] + ta1_x_xxxx_xzzzz_0[i] * pa_x[i] - ta1_x_xxxx_xzzzz_1[i] * pc_x[i];

        ta1_x_xxxxx_yyyyy_0[i] = 4.0 * ta1_x_xxx_yyyyy_0[i] * fe_0 - 4.0 * ta1_x_xxx_yyyyy_1[i] * fe_0 + ta_xxxx_yyyyy_1[i] + ta1_x_xxxx_yyyyy_0[i] * pa_x[i] - ta1_x_xxxx_yyyyy_1[i] * pc_x[i];

        ta1_x_xxxxx_yyyyz_0[i] = 4.0 * ta1_x_xxx_yyyyz_0[i] * fe_0 - 4.0 * ta1_x_xxx_yyyyz_1[i] * fe_0 + ta_xxxx_yyyyz_1[i] + ta1_x_xxxx_yyyyz_0[i] * pa_x[i] - ta1_x_xxxx_yyyyz_1[i] * pc_x[i];

        ta1_x_xxxxx_yyyzz_0[i] = 4.0 * ta1_x_xxx_yyyzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_yyyzz_1[i] * fe_0 + ta_xxxx_yyyzz_1[i] + ta1_x_xxxx_yyyzz_0[i] * pa_x[i] - ta1_x_xxxx_yyyzz_1[i] * pc_x[i];

        ta1_x_xxxxx_yyzzz_0[i] = 4.0 * ta1_x_xxx_yyzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_yyzzz_1[i] * fe_0 + ta_xxxx_yyzzz_1[i] + ta1_x_xxxx_yyzzz_0[i] * pa_x[i] - ta1_x_xxxx_yyzzz_1[i] * pc_x[i];

        ta1_x_xxxxx_yzzzz_0[i] = 4.0 * ta1_x_xxx_yzzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_yzzzz_1[i] * fe_0 + ta_xxxx_yzzzz_1[i] + ta1_x_xxxx_yzzzz_0[i] * pa_x[i] - ta1_x_xxxx_yzzzz_1[i] * pc_x[i];

        ta1_x_xxxxx_zzzzz_0[i] = 4.0 * ta1_x_xxx_zzzzz_0[i] * fe_0 - 4.0 * ta1_x_xxx_zzzzz_1[i] * fe_0 + ta_xxxx_zzzzz_1[i] + ta1_x_xxxx_zzzzz_0[i] * pa_x[i] - ta1_x_xxxx_zzzzz_1[i] * pc_x[i];
    }

    // Set up 21-42 components of targeted buffer : HH

    auto ta1_x_xxxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 21);

    auto ta1_x_xxxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 22);

    auto ta1_x_xxxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 23);

    auto ta1_x_xxxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 24);

    auto ta1_x_xxxxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 25);

    auto ta1_x_xxxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 26);

    auto ta1_x_xxxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 27);

    auto ta1_x_xxxxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 28);

    auto ta1_x_xxxxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 29);

    auto ta1_x_xxxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 30);

    auto ta1_x_xxxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 31);

    auto ta1_x_xxxxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 32);

    auto ta1_x_xxxxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 33);

    auto ta1_x_xxxxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 34);

    auto ta1_x_xxxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 35);

    auto ta1_x_xxxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 36);

    auto ta1_x_xxxxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 37);

    auto ta1_x_xxxxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 38);

    auto ta1_x_xxxxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 39);

    auto ta1_x_xxxxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 40);

    auto ta1_x_xxxxy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 41);

    #pragma omp simd aligned(pa_y, pc_y, ta1_x_xxxx_xxxx_0, ta1_x_xxxx_xxxx_1, ta1_x_xxxx_xxxxx_0, ta1_x_xxxx_xxxxx_1, ta1_x_xxxx_xxxxy_0, ta1_x_xxxx_xxxxy_1, ta1_x_xxxx_xxxxz_0, ta1_x_xxxx_xxxxz_1, ta1_x_xxxx_xxxy_0, ta1_x_xxxx_xxxy_1, ta1_x_xxxx_xxxyy_0, ta1_x_xxxx_xxxyy_1, ta1_x_xxxx_xxxyz_0, ta1_x_xxxx_xxxyz_1, ta1_x_xxxx_xxxz_0, ta1_x_xxxx_xxxz_1, ta1_x_xxxx_xxxzz_0, ta1_x_xxxx_xxxzz_1, ta1_x_xxxx_xxyy_0, ta1_x_xxxx_xxyy_1, ta1_x_xxxx_xxyyy_0, ta1_x_xxxx_xxyyy_1, ta1_x_xxxx_xxyyz_0, ta1_x_xxxx_xxyyz_1, ta1_x_xxxx_xxyz_0, ta1_x_xxxx_xxyz_1, ta1_x_xxxx_xxyzz_0, ta1_x_xxxx_xxyzz_1, ta1_x_xxxx_xxzz_0, ta1_x_xxxx_xxzz_1, ta1_x_xxxx_xxzzz_0, ta1_x_xxxx_xxzzz_1, ta1_x_xxxx_xyyy_0, ta1_x_xxxx_xyyy_1, ta1_x_xxxx_xyyyy_0, ta1_x_xxxx_xyyyy_1, ta1_x_xxxx_xyyyz_0, ta1_x_xxxx_xyyyz_1, ta1_x_xxxx_xyyz_0, ta1_x_xxxx_xyyz_1, ta1_x_xxxx_xyyzz_0, ta1_x_xxxx_xyyzz_1, ta1_x_xxxx_xyzz_0, ta1_x_xxxx_xyzz_1, ta1_x_xxxx_xyzzz_0, ta1_x_xxxx_xyzzz_1, ta1_x_xxxx_xzzz_0, ta1_x_xxxx_xzzz_1, ta1_x_xxxx_xzzzz_0, ta1_x_xxxx_xzzzz_1, ta1_x_xxxx_yyyy_0, ta1_x_xxxx_yyyy_1, ta1_x_xxxx_yyyyy_0, ta1_x_xxxx_yyyyy_1, ta1_x_xxxx_yyyyz_0, ta1_x_xxxx_yyyyz_1, ta1_x_xxxx_yyyz_0, ta1_x_xxxx_yyyz_1, ta1_x_xxxx_yyyzz_0, ta1_x_xxxx_yyyzz_1, ta1_x_xxxx_yyzz_0, ta1_x_xxxx_yyzz_1, ta1_x_xxxx_yyzzz_0, ta1_x_xxxx_yyzzz_1, ta1_x_xxxx_yzzz_0, ta1_x_xxxx_yzzz_1, ta1_x_xxxx_yzzzz_0, ta1_x_xxxx_yzzzz_1, ta1_x_xxxx_zzzz_0, ta1_x_xxxx_zzzz_1, ta1_x_xxxx_zzzzz_0, ta1_x_xxxx_zzzzz_1, ta1_x_xxxxy_xxxxx_0, ta1_x_xxxxy_xxxxy_0, ta1_x_xxxxy_xxxxz_0, ta1_x_xxxxy_xxxyy_0, ta1_x_xxxxy_xxxyz_0, ta1_x_xxxxy_xxxzz_0, ta1_x_xxxxy_xxyyy_0, ta1_x_xxxxy_xxyyz_0, ta1_x_xxxxy_xxyzz_0, ta1_x_xxxxy_xxzzz_0, ta1_x_xxxxy_xyyyy_0, ta1_x_xxxxy_xyyyz_0, ta1_x_xxxxy_xyyzz_0, ta1_x_xxxxy_xyzzz_0, ta1_x_xxxxy_xzzzz_0, ta1_x_xxxxy_yyyyy_0, ta1_x_xxxxy_yyyyz_0, ta1_x_xxxxy_yyyzz_0, ta1_x_xxxxy_yyzzz_0, ta1_x_xxxxy_yzzzz_0, ta1_x_xxxxy_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxxy_xxxxx_0[i] = ta1_x_xxxx_xxxxx_0[i] * pa_y[i] - ta1_x_xxxx_xxxxx_1[i] * pc_y[i];

        ta1_x_xxxxy_xxxxy_0[i] = ta1_x_xxxx_xxxx_0[i] * fe_0 - ta1_x_xxxx_xxxx_1[i] * fe_0 + ta1_x_xxxx_xxxxy_0[i] * pa_y[i] - ta1_x_xxxx_xxxxy_1[i] * pc_y[i];

        ta1_x_xxxxy_xxxxz_0[i] = ta1_x_xxxx_xxxxz_0[i] * pa_y[i] - ta1_x_xxxx_xxxxz_1[i] * pc_y[i];

        ta1_x_xxxxy_xxxyy_0[i] = 2.0 * ta1_x_xxxx_xxxy_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xxxy_1[i] * fe_0 + ta1_x_xxxx_xxxyy_0[i] * pa_y[i] - ta1_x_xxxx_xxxyy_1[i] * pc_y[i];

        ta1_x_xxxxy_xxxyz_0[i] = ta1_x_xxxx_xxxz_0[i] * fe_0 - ta1_x_xxxx_xxxz_1[i] * fe_0 + ta1_x_xxxx_xxxyz_0[i] * pa_y[i] - ta1_x_xxxx_xxxyz_1[i] * pc_y[i];

        ta1_x_xxxxy_xxxzz_0[i] = ta1_x_xxxx_xxxzz_0[i] * pa_y[i] - ta1_x_xxxx_xxxzz_1[i] * pc_y[i];

        ta1_x_xxxxy_xxyyy_0[i] = 3.0 * ta1_x_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xxyy_1[i] * fe_0 + ta1_x_xxxx_xxyyy_0[i] * pa_y[i] - ta1_x_xxxx_xxyyy_1[i] * pc_y[i];

        ta1_x_xxxxy_xxyyz_0[i] = 2.0 * ta1_x_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xxyz_1[i] * fe_0 + ta1_x_xxxx_xxyyz_0[i] * pa_y[i] - ta1_x_xxxx_xxyyz_1[i] * pc_y[i];

        ta1_x_xxxxy_xxyzz_0[i] = ta1_x_xxxx_xxzz_0[i] * fe_0 - ta1_x_xxxx_xxzz_1[i] * fe_0 + ta1_x_xxxx_xxyzz_0[i] * pa_y[i] - ta1_x_xxxx_xxyzz_1[i] * pc_y[i];

        ta1_x_xxxxy_xxzzz_0[i] = ta1_x_xxxx_xxzzz_0[i] * pa_y[i] - ta1_x_xxxx_xxzzz_1[i] * pc_y[i];

        ta1_x_xxxxy_xyyyy_0[i] = 4.0 * ta1_x_xxxx_xyyy_0[i] * fe_0 - 4.0 * ta1_x_xxxx_xyyy_1[i] * fe_0 + ta1_x_xxxx_xyyyy_0[i] * pa_y[i] - ta1_x_xxxx_xyyyy_1[i] * pc_y[i];

        ta1_x_xxxxy_xyyyz_0[i] = 3.0 * ta1_x_xxxx_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xyyz_1[i] * fe_0 + ta1_x_xxxx_xyyyz_0[i] * pa_y[i] - ta1_x_xxxx_xyyyz_1[i] * pc_y[i];

        ta1_x_xxxxy_xyyzz_0[i] = 2.0 * ta1_x_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xyzz_1[i] * fe_0 + ta1_x_xxxx_xyyzz_0[i] * pa_y[i] - ta1_x_xxxx_xyyzz_1[i] * pc_y[i];

        ta1_x_xxxxy_xyzzz_0[i] = ta1_x_xxxx_xzzz_0[i] * fe_0 - ta1_x_xxxx_xzzz_1[i] * fe_0 + ta1_x_xxxx_xyzzz_0[i] * pa_y[i] - ta1_x_xxxx_xyzzz_1[i] * pc_y[i];

        ta1_x_xxxxy_xzzzz_0[i] = ta1_x_xxxx_xzzzz_0[i] * pa_y[i] - ta1_x_xxxx_xzzzz_1[i] * pc_y[i];

        ta1_x_xxxxy_yyyyy_0[i] = 5.0 * ta1_x_xxxx_yyyy_0[i] * fe_0 - 5.0 * ta1_x_xxxx_yyyy_1[i] * fe_0 + ta1_x_xxxx_yyyyy_0[i] * pa_y[i] - ta1_x_xxxx_yyyyy_1[i] * pc_y[i];

        ta1_x_xxxxy_yyyyz_0[i] = 4.0 * ta1_x_xxxx_yyyz_0[i] * fe_0 - 4.0 * ta1_x_xxxx_yyyz_1[i] * fe_0 + ta1_x_xxxx_yyyyz_0[i] * pa_y[i] - ta1_x_xxxx_yyyyz_1[i] * pc_y[i];

        ta1_x_xxxxy_yyyzz_0[i] = 3.0 * ta1_x_xxxx_yyzz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_yyzz_1[i] * fe_0 + ta1_x_xxxx_yyyzz_0[i] * pa_y[i] - ta1_x_xxxx_yyyzz_1[i] * pc_y[i];

        ta1_x_xxxxy_yyzzz_0[i] = 2.0 * ta1_x_xxxx_yzzz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_yzzz_1[i] * fe_0 + ta1_x_xxxx_yyzzz_0[i] * pa_y[i] - ta1_x_xxxx_yyzzz_1[i] * pc_y[i];

        ta1_x_xxxxy_yzzzz_0[i] = ta1_x_xxxx_zzzz_0[i] * fe_0 - ta1_x_xxxx_zzzz_1[i] * fe_0 + ta1_x_xxxx_yzzzz_0[i] * pa_y[i] - ta1_x_xxxx_yzzzz_1[i] * pc_y[i];

        ta1_x_xxxxy_zzzzz_0[i] = ta1_x_xxxx_zzzzz_0[i] * pa_y[i] - ta1_x_xxxx_zzzzz_1[i] * pc_y[i];
    }

    // Set up 42-63 components of targeted buffer : HH

    auto ta1_x_xxxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 42);

    auto ta1_x_xxxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 43);

    auto ta1_x_xxxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 44);

    auto ta1_x_xxxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 45);

    auto ta1_x_xxxxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 46);

    auto ta1_x_xxxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 47);

    auto ta1_x_xxxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 48);

    auto ta1_x_xxxxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 49);

    auto ta1_x_xxxxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 50);

    auto ta1_x_xxxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 51);

    auto ta1_x_xxxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 52);

    auto ta1_x_xxxxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 53);

    auto ta1_x_xxxxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 54);

    auto ta1_x_xxxxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 55);

    auto ta1_x_xxxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 56);

    auto ta1_x_xxxxz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 57);

    auto ta1_x_xxxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 58);

    auto ta1_x_xxxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 59);

    auto ta1_x_xxxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 60);

    auto ta1_x_xxxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 61);

    auto ta1_x_xxxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 62);

    #pragma omp simd aligned(pa_z, pc_z, ta1_x_xxxx_xxxx_0, ta1_x_xxxx_xxxx_1, ta1_x_xxxx_xxxxx_0, ta1_x_xxxx_xxxxx_1, ta1_x_xxxx_xxxxy_0, ta1_x_xxxx_xxxxy_1, ta1_x_xxxx_xxxxz_0, ta1_x_xxxx_xxxxz_1, ta1_x_xxxx_xxxy_0, ta1_x_xxxx_xxxy_1, ta1_x_xxxx_xxxyy_0, ta1_x_xxxx_xxxyy_1, ta1_x_xxxx_xxxyz_0, ta1_x_xxxx_xxxyz_1, ta1_x_xxxx_xxxz_0, ta1_x_xxxx_xxxz_1, ta1_x_xxxx_xxxzz_0, ta1_x_xxxx_xxxzz_1, ta1_x_xxxx_xxyy_0, ta1_x_xxxx_xxyy_1, ta1_x_xxxx_xxyyy_0, ta1_x_xxxx_xxyyy_1, ta1_x_xxxx_xxyyz_0, ta1_x_xxxx_xxyyz_1, ta1_x_xxxx_xxyz_0, ta1_x_xxxx_xxyz_1, ta1_x_xxxx_xxyzz_0, ta1_x_xxxx_xxyzz_1, ta1_x_xxxx_xxzz_0, ta1_x_xxxx_xxzz_1, ta1_x_xxxx_xxzzz_0, ta1_x_xxxx_xxzzz_1, ta1_x_xxxx_xyyy_0, ta1_x_xxxx_xyyy_1, ta1_x_xxxx_xyyyy_0, ta1_x_xxxx_xyyyy_1, ta1_x_xxxx_xyyyz_0, ta1_x_xxxx_xyyyz_1, ta1_x_xxxx_xyyz_0, ta1_x_xxxx_xyyz_1, ta1_x_xxxx_xyyzz_0, ta1_x_xxxx_xyyzz_1, ta1_x_xxxx_xyzz_0, ta1_x_xxxx_xyzz_1, ta1_x_xxxx_xyzzz_0, ta1_x_xxxx_xyzzz_1, ta1_x_xxxx_xzzz_0, ta1_x_xxxx_xzzz_1, ta1_x_xxxx_xzzzz_0, ta1_x_xxxx_xzzzz_1, ta1_x_xxxx_yyyy_0, ta1_x_xxxx_yyyy_1, ta1_x_xxxx_yyyyy_0, ta1_x_xxxx_yyyyy_1, ta1_x_xxxx_yyyyz_0, ta1_x_xxxx_yyyyz_1, ta1_x_xxxx_yyyz_0, ta1_x_xxxx_yyyz_1, ta1_x_xxxx_yyyzz_0, ta1_x_xxxx_yyyzz_1, ta1_x_xxxx_yyzz_0, ta1_x_xxxx_yyzz_1, ta1_x_xxxx_yyzzz_0, ta1_x_xxxx_yyzzz_1, ta1_x_xxxx_yzzz_0, ta1_x_xxxx_yzzz_1, ta1_x_xxxx_yzzzz_0, ta1_x_xxxx_yzzzz_1, ta1_x_xxxx_zzzz_0, ta1_x_xxxx_zzzz_1, ta1_x_xxxx_zzzzz_0, ta1_x_xxxx_zzzzz_1, ta1_x_xxxxz_xxxxx_0, ta1_x_xxxxz_xxxxy_0, ta1_x_xxxxz_xxxxz_0, ta1_x_xxxxz_xxxyy_0, ta1_x_xxxxz_xxxyz_0, ta1_x_xxxxz_xxxzz_0, ta1_x_xxxxz_xxyyy_0, ta1_x_xxxxz_xxyyz_0, ta1_x_xxxxz_xxyzz_0, ta1_x_xxxxz_xxzzz_0, ta1_x_xxxxz_xyyyy_0, ta1_x_xxxxz_xyyyz_0, ta1_x_xxxxz_xyyzz_0, ta1_x_xxxxz_xyzzz_0, ta1_x_xxxxz_xzzzz_0, ta1_x_xxxxz_yyyyy_0, ta1_x_xxxxz_yyyyz_0, ta1_x_xxxxz_yyyzz_0, ta1_x_xxxxz_yyzzz_0, ta1_x_xxxxz_yzzzz_0, ta1_x_xxxxz_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxxz_xxxxx_0[i] = ta1_x_xxxx_xxxxx_0[i] * pa_z[i] - ta1_x_xxxx_xxxxx_1[i] * pc_z[i];

        ta1_x_xxxxz_xxxxy_0[i] = ta1_x_xxxx_xxxxy_0[i] * pa_z[i] - ta1_x_xxxx_xxxxy_1[i] * pc_z[i];

        ta1_x_xxxxz_xxxxz_0[i] = ta1_x_xxxx_xxxx_0[i] * fe_0 - ta1_x_xxxx_xxxx_1[i] * fe_0 + ta1_x_xxxx_xxxxz_0[i] * pa_z[i] - ta1_x_xxxx_xxxxz_1[i] * pc_z[i];

        ta1_x_xxxxz_xxxyy_0[i] = ta1_x_xxxx_xxxyy_0[i] * pa_z[i] - ta1_x_xxxx_xxxyy_1[i] * pc_z[i];

        ta1_x_xxxxz_xxxyz_0[i] = ta1_x_xxxx_xxxy_0[i] * fe_0 - ta1_x_xxxx_xxxy_1[i] * fe_0 + ta1_x_xxxx_xxxyz_0[i] * pa_z[i] - ta1_x_xxxx_xxxyz_1[i] * pc_z[i];

        ta1_x_xxxxz_xxxzz_0[i] = 2.0 * ta1_x_xxxx_xxxz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xxxz_1[i] * fe_0 + ta1_x_xxxx_xxxzz_0[i] * pa_z[i] - ta1_x_xxxx_xxxzz_1[i] * pc_z[i];

        ta1_x_xxxxz_xxyyy_0[i] = ta1_x_xxxx_xxyyy_0[i] * pa_z[i] - ta1_x_xxxx_xxyyy_1[i] * pc_z[i];

        ta1_x_xxxxz_xxyyz_0[i] = ta1_x_xxxx_xxyy_0[i] * fe_0 - ta1_x_xxxx_xxyy_1[i] * fe_0 + ta1_x_xxxx_xxyyz_0[i] * pa_z[i] - ta1_x_xxxx_xxyyz_1[i] * pc_z[i];

        ta1_x_xxxxz_xxyzz_0[i] = 2.0 * ta1_x_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xxyz_1[i] * fe_0 + ta1_x_xxxx_xxyzz_0[i] * pa_z[i] - ta1_x_xxxx_xxyzz_1[i] * pc_z[i];

        ta1_x_xxxxz_xxzzz_0[i] = 3.0 * ta1_x_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xxzz_1[i] * fe_0 + ta1_x_xxxx_xxzzz_0[i] * pa_z[i] - ta1_x_xxxx_xxzzz_1[i] * pc_z[i];

        ta1_x_xxxxz_xyyyy_0[i] = ta1_x_xxxx_xyyyy_0[i] * pa_z[i] - ta1_x_xxxx_xyyyy_1[i] * pc_z[i];

        ta1_x_xxxxz_xyyyz_0[i] = ta1_x_xxxx_xyyy_0[i] * fe_0 - ta1_x_xxxx_xyyy_1[i] * fe_0 + ta1_x_xxxx_xyyyz_0[i] * pa_z[i] - ta1_x_xxxx_xyyyz_1[i] * pc_z[i];

        ta1_x_xxxxz_xyyzz_0[i] = 2.0 * ta1_x_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_xyyz_1[i] * fe_0 + ta1_x_xxxx_xyyzz_0[i] * pa_z[i] - ta1_x_xxxx_xyyzz_1[i] * pc_z[i];

        ta1_x_xxxxz_xyzzz_0[i] = 3.0 * ta1_x_xxxx_xyzz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_xyzz_1[i] * fe_0 + ta1_x_xxxx_xyzzz_0[i] * pa_z[i] - ta1_x_xxxx_xyzzz_1[i] * pc_z[i];

        ta1_x_xxxxz_xzzzz_0[i] = 4.0 * ta1_x_xxxx_xzzz_0[i] * fe_0 - 4.0 * ta1_x_xxxx_xzzz_1[i] * fe_0 + ta1_x_xxxx_xzzzz_0[i] * pa_z[i] - ta1_x_xxxx_xzzzz_1[i] * pc_z[i];

        ta1_x_xxxxz_yyyyy_0[i] = ta1_x_xxxx_yyyyy_0[i] * pa_z[i] - ta1_x_xxxx_yyyyy_1[i] * pc_z[i];

        ta1_x_xxxxz_yyyyz_0[i] = ta1_x_xxxx_yyyy_0[i] * fe_0 - ta1_x_xxxx_yyyy_1[i] * fe_0 + ta1_x_xxxx_yyyyz_0[i] * pa_z[i] - ta1_x_xxxx_yyyyz_1[i] * pc_z[i];

        ta1_x_xxxxz_yyyzz_0[i] = 2.0 * ta1_x_xxxx_yyyz_0[i] * fe_0 - 2.0 * ta1_x_xxxx_yyyz_1[i] * fe_0 + ta1_x_xxxx_yyyzz_0[i] * pa_z[i] - ta1_x_xxxx_yyyzz_1[i] * pc_z[i];

        ta1_x_xxxxz_yyzzz_0[i] = 3.0 * ta1_x_xxxx_yyzz_0[i] * fe_0 - 3.0 * ta1_x_xxxx_yyzz_1[i] * fe_0 + ta1_x_xxxx_yyzzz_0[i] * pa_z[i] - ta1_x_xxxx_yyzzz_1[i] * pc_z[i];

        ta1_x_xxxxz_yzzzz_0[i] = 4.0 * ta1_x_xxxx_yzzz_0[i] * fe_0 - 4.0 * ta1_x_xxxx_yzzz_1[i] * fe_0 + ta1_x_xxxx_yzzzz_0[i] * pa_z[i] - ta1_x_xxxx_yzzzz_1[i] * pc_z[i];

        ta1_x_xxxxz_zzzzz_0[i] = 5.0 * ta1_x_xxxx_zzzz_0[i] * fe_0 - 5.0 * ta1_x_xxxx_zzzz_1[i] * fe_0 + ta1_x_xxxx_zzzzz_0[i] * pa_z[i] - ta1_x_xxxx_zzzzz_1[i] * pc_z[i];
    }

    // Set up 63-84 components of targeted buffer : HH

    auto ta1_x_xxxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 63);

    auto ta1_x_xxxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 64);

    auto ta1_x_xxxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 65);

    auto ta1_x_xxxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 66);

    auto ta1_x_xxxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 67);

    auto ta1_x_xxxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 68);

    auto ta1_x_xxxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 69);

    auto ta1_x_xxxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 70);

    auto ta1_x_xxxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 71);

    auto ta1_x_xxxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 72);

    auto ta1_x_xxxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 73);

    auto ta1_x_xxxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 74);

    auto ta1_x_xxxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 75);

    auto ta1_x_xxxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 76);

    auto ta1_x_xxxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 77);

    auto ta1_x_xxxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 78);

    auto ta1_x_xxxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 79);

    auto ta1_x_xxxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 80);

    auto ta1_x_xxxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 81);

    auto ta1_x_xxxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 82);

    auto ta1_x_xxxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 83);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_x_xxx_xxxxx_0, ta1_x_xxx_xxxxx_1, ta1_x_xxx_xxxxy_0, ta1_x_xxx_xxxxy_1, ta1_x_xxx_xxxxz_0, ta1_x_xxx_xxxxz_1, ta1_x_xxx_xxxyy_0, ta1_x_xxx_xxxyy_1, ta1_x_xxx_xxxyz_0, ta1_x_xxx_xxxyz_1, ta1_x_xxx_xxxzz_0, ta1_x_xxx_xxxzz_1, ta1_x_xxx_xxyyy_0, ta1_x_xxx_xxyyy_1, ta1_x_xxx_xxyyz_0, ta1_x_xxx_xxyyz_1, ta1_x_xxx_xxyzz_0, ta1_x_xxx_xxyzz_1, ta1_x_xxx_xxzzz_0, ta1_x_xxx_xxzzz_1, ta1_x_xxx_xyyyy_0, ta1_x_xxx_xyyyy_1, ta1_x_xxx_xyyyz_0, ta1_x_xxx_xyyyz_1, ta1_x_xxx_xyyzz_0, ta1_x_xxx_xyyzz_1, ta1_x_xxx_xyzzz_0, ta1_x_xxx_xyzzz_1, ta1_x_xxx_xzzzz_0, ta1_x_xxx_xzzzz_1, ta1_x_xxx_zzzzz_0, ta1_x_xxx_zzzzz_1, ta1_x_xxxy_xxxx_0, ta1_x_xxxy_xxxx_1, ta1_x_xxxy_xxxxx_0, ta1_x_xxxy_xxxxx_1, ta1_x_xxxy_xxxxy_0, ta1_x_xxxy_xxxxy_1, ta1_x_xxxy_xxxxz_0, ta1_x_xxxy_xxxxz_1, ta1_x_xxxy_xxxy_0, ta1_x_xxxy_xxxy_1, ta1_x_xxxy_xxxyy_0, ta1_x_xxxy_xxxyy_1, ta1_x_xxxy_xxxyz_0, ta1_x_xxxy_xxxyz_1, ta1_x_xxxy_xxxz_0, ta1_x_xxxy_xxxz_1, ta1_x_xxxy_xxxzz_0, ta1_x_xxxy_xxxzz_1, ta1_x_xxxy_xxyy_0, ta1_x_xxxy_xxyy_1, ta1_x_xxxy_xxyyy_0, ta1_x_xxxy_xxyyy_1, ta1_x_xxxy_xxyyz_0, ta1_x_xxxy_xxyyz_1, ta1_x_xxxy_xxyz_0, ta1_x_xxxy_xxyz_1, ta1_x_xxxy_xxyzz_0, ta1_x_xxxy_xxyzz_1, ta1_x_xxxy_xxzz_0, ta1_x_xxxy_xxzz_1, ta1_x_xxxy_xxzzz_0, ta1_x_xxxy_xxzzz_1, ta1_x_xxxy_xyyy_0, ta1_x_xxxy_xyyy_1, ta1_x_xxxy_xyyyy_0, ta1_x_xxxy_xyyyy_1, ta1_x_xxxy_xyyyz_0, ta1_x_xxxy_xyyyz_1, ta1_x_xxxy_xyyz_0, ta1_x_xxxy_xyyz_1, ta1_x_xxxy_xyyzz_0, ta1_x_xxxy_xyyzz_1, ta1_x_xxxy_xyzz_0, ta1_x_xxxy_xyzz_1, ta1_x_xxxy_xyzzz_0, ta1_x_xxxy_xyzzz_1, ta1_x_xxxy_xzzz_0, ta1_x_xxxy_xzzz_1, ta1_x_xxxy_xzzzz_0, ta1_x_xxxy_xzzzz_1, ta1_x_xxxy_zzzzz_0, ta1_x_xxxy_zzzzz_1, ta1_x_xxxyy_xxxxx_0, ta1_x_xxxyy_xxxxy_0, ta1_x_xxxyy_xxxxz_0, ta1_x_xxxyy_xxxyy_0, ta1_x_xxxyy_xxxyz_0, ta1_x_xxxyy_xxxzz_0, ta1_x_xxxyy_xxyyy_0, ta1_x_xxxyy_xxyyz_0, ta1_x_xxxyy_xxyzz_0, ta1_x_xxxyy_xxzzz_0, ta1_x_xxxyy_xyyyy_0, ta1_x_xxxyy_xyyyz_0, ta1_x_xxxyy_xyyzz_0, ta1_x_xxxyy_xyzzz_0, ta1_x_xxxyy_xzzzz_0, ta1_x_xxxyy_yyyyy_0, ta1_x_xxxyy_yyyyz_0, ta1_x_xxxyy_yyyzz_0, ta1_x_xxxyy_yyzzz_0, ta1_x_xxxyy_yzzzz_0, ta1_x_xxxyy_zzzzz_0, ta1_x_xxyy_yyyyy_0, ta1_x_xxyy_yyyyy_1, ta1_x_xxyy_yyyyz_0, ta1_x_xxyy_yyyyz_1, ta1_x_xxyy_yyyzz_0, ta1_x_xxyy_yyyzz_1, ta1_x_xxyy_yyzzz_0, ta1_x_xxyy_yyzzz_1, ta1_x_xxyy_yzzzz_0, ta1_x_xxyy_yzzzz_1, ta1_x_xyy_yyyyy_0, ta1_x_xyy_yyyyy_1, ta1_x_xyy_yyyyz_0, ta1_x_xyy_yyyyz_1, ta1_x_xyy_yyyzz_0, ta1_x_xyy_yyyzz_1, ta1_x_xyy_yyzzz_0, ta1_x_xyy_yyzzz_1, ta1_x_xyy_yzzzz_0, ta1_x_xyy_yzzzz_1, ta_xxyy_yyyyy_1, ta_xxyy_yyyyz_1, ta_xxyy_yyyzz_1, ta_xxyy_yyzzz_1, ta_xxyy_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxyy_xxxxx_0[i] = ta1_x_xxx_xxxxx_0[i] * fe_0 - ta1_x_xxx_xxxxx_1[i] * fe_0 + ta1_x_xxxy_xxxxx_0[i] * pa_y[i] - ta1_x_xxxy_xxxxx_1[i] * pc_y[i];

        ta1_x_xxxyy_xxxxy_0[i] = ta1_x_xxx_xxxxy_0[i] * fe_0 - ta1_x_xxx_xxxxy_1[i] * fe_0 + ta1_x_xxxy_xxxx_0[i] * fe_0 - ta1_x_xxxy_xxxx_1[i] * fe_0 + ta1_x_xxxy_xxxxy_0[i] * pa_y[i] - ta1_x_xxxy_xxxxy_1[i] * pc_y[i];

        ta1_x_xxxyy_xxxxz_0[i] = ta1_x_xxx_xxxxz_0[i] * fe_0 - ta1_x_xxx_xxxxz_1[i] * fe_0 + ta1_x_xxxy_xxxxz_0[i] * pa_y[i] - ta1_x_xxxy_xxxxz_1[i] * pc_y[i];

        ta1_x_xxxyy_xxxyy_0[i] = ta1_x_xxx_xxxyy_0[i] * fe_0 - ta1_x_xxx_xxxyy_1[i] * fe_0 + 2.0 * ta1_x_xxxy_xxxy_0[i] * fe_0 - 2.0 * ta1_x_xxxy_xxxy_1[i] * fe_0 + ta1_x_xxxy_xxxyy_0[i] * pa_y[i] - ta1_x_xxxy_xxxyy_1[i] * pc_y[i];

        ta1_x_xxxyy_xxxyz_0[i] = ta1_x_xxx_xxxyz_0[i] * fe_0 - ta1_x_xxx_xxxyz_1[i] * fe_0 + ta1_x_xxxy_xxxz_0[i] * fe_0 - ta1_x_xxxy_xxxz_1[i] * fe_0 + ta1_x_xxxy_xxxyz_0[i] * pa_y[i] - ta1_x_xxxy_xxxyz_1[i] * pc_y[i];

        ta1_x_xxxyy_xxxzz_0[i] = ta1_x_xxx_xxxzz_0[i] * fe_0 - ta1_x_xxx_xxxzz_1[i] * fe_0 + ta1_x_xxxy_xxxzz_0[i] * pa_y[i] - ta1_x_xxxy_xxxzz_1[i] * pc_y[i];

        ta1_x_xxxyy_xxyyy_0[i] = ta1_x_xxx_xxyyy_0[i] * fe_0 - ta1_x_xxx_xxyyy_1[i] * fe_0 + 3.0 * ta1_x_xxxy_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xxxy_xxyy_1[i] * fe_0 + ta1_x_xxxy_xxyyy_0[i] * pa_y[i] - ta1_x_xxxy_xxyyy_1[i] * pc_y[i];

        ta1_x_xxxyy_xxyyz_0[i] = ta1_x_xxx_xxyyz_0[i] * fe_0 - ta1_x_xxx_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_xxxy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxxy_xxyz_1[i] * fe_0 + ta1_x_xxxy_xxyyz_0[i] * pa_y[i] - ta1_x_xxxy_xxyyz_1[i] * pc_y[i];

        ta1_x_xxxyy_xxyzz_0[i] = ta1_x_xxx_xxyzz_0[i] * fe_0 - ta1_x_xxx_xxyzz_1[i] * fe_0 + ta1_x_xxxy_xxzz_0[i] * fe_0 - ta1_x_xxxy_xxzz_1[i] * fe_0 + ta1_x_xxxy_xxyzz_0[i] * pa_y[i] - ta1_x_xxxy_xxyzz_1[i] * pc_y[i];

        ta1_x_xxxyy_xxzzz_0[i] = ta1_x_xxx_xxzzz_0[i] * fe_0 - ta1_x_xxx_xxzzz_1[i] * fe_0 + ta1_x_xxxy_xxzzz_0[i] * pa_y[i] - ta1_x_xxxy_xxzzz_1[i] * pc_y[i];

        ta1_x_xxxyy_xyyyy_0[i] = ta1_x_xxx_xyyyy_0[i] * fe_0 - ta1_x_xxx_xyyyy_1[i] * fe_0 + 4.0 * ta1_x_xxxy_xyyy_0[i] * fe_0 - 4.0 * ta1_x_xxxy_xyyy_1[i] * fe_0 + ta1_x_xxxy_xyyyy_0[i] * pa_y[i] - ta1_x_xxxy_xyyyy_1[i] * pc_y[i];

        ta1_x_xxxyy_xyyyz_0[i] = ta1_x_xxx_xyyyz_0[i] * fe_0 - ta1_x_xxx_xyyyz_1[i] * fe_0 + 3.0 * ta1_x_xxxy_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xxxy_xyyz_1[i] * fe_0 + ta1_x_xxxy_xyyyz_0[i] * pa_y[i] - ta1_x_xxxy_xyyyz_1[i] * pc_y[i];

        ta1_x_xxxyy_xyyzz_0[i] = ta1_x_xxx_xyyzz_0[i] * fe_0 - ta1_x_xxx_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_xxxy_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxxy_xyzz_1[i] * fe_0 + ta1_x_xxxy_xyyzz_0[i] * pa_y[i] - ta1_x_xxxy_xyyzz_1[i] * pc_y[i];

        ta1_x_xxxyy_xyzzz_0[i] = ta1_x_xxx_xyzzz_0[i] * fe_0 - ta1_x_xxx_xyzzz_1[i] * fe_0 + ta1_x_xxxy_xzzz_0[i] * fe_0 - ta1_x_xxxy_xzzz_1[i] * fe_0 + ta1_x_xxxy_xyzzz_0[i] * pa_y[i] - ta1_x_xxxy_xyzzz_1[i] * pc_y[i];

        ta1_x_xxxyy_xzzzz_0[i] = ta1_x_xxx_xzzzz_0[i] * fe_0 - ta1_x_xxx_xzzzz_1[i] * fe_0 + ta1_x_xxxy_xzzzz_0[i] * pa_y[i] - ta1_x_xxxy_xzzzz_1[i] * pc_y[i];

        ta1_x_xxxyy_yyyyy_0[i] = 2.0 * ta1_x_xyy_yyyyy_0[i] * fe_0 - 2.0 * ta1_x_xyy_yyyyy_1[i] * fe_0 + ta_xxyy_yyyyy_1[i] + ta1_x_xxyy_yyyyy_0[i] * pa_x[i] - ta1_x_xxyy_yyyyy_1[i] * pc_x[i];

        ta1_x_xxxyy_yyyyz_0[i] = 2.0 * ta1_x_xyy_yyyyz_0[i] * fe_0 - 2.0 * ta1_x_xyy_yyyyz_1[i] * fe_0 + ta_xxyy_yyyyz_1[i] + ta1_x_xxyy_yyyyz_0[i] * pa_x[i] - ta1_x_xxyy_yyyyz_1[i] * pc_x[i];

        ta1_x_xxxyy_yyyzz_0[i] = 2.0 * ta1_x_xyy_yyyzz_0[i] * fe_0 - 2.0 * ta1_x_xyy_yyyzz_1[i] * fe_0 + ta_xxyy_yyyzz_1[i] + ta1_x_xxyy_yyyzz_0[i] * pa_x[i] - ta1_x_xxyy_yyyzz_1[i] * pc_x[i];

        ta1_x_xxxyy_yyzzz_0[i] = 2.0 * ta1_x_xyy_yyzzz_0[i] * fe_0 - 2.0 * ta1_x_xyy_yyzzz_1[i] * fe_0 + ta_xxyy_yyzzz_1[i] + ta1_x_xxyy_yyzzz_0[i] * pa_x[i] - ta1_x_xxyy_yyzzz_1[i] * pc_x[i];

        ta1_x_xxxyy_yzzzz_0[i] = 2.0 * ta1_x_xyy_yzzzz_0[i] * fe_0 - 2.0 * ta1_x_xyy_yzzzz_1[i] * fe_0 + ta_xxyy_yzzzz_1[i] + ta1_x_xxyy_yzzzz_0[i] * pa_x[i] - ta1_x_xxyy_yzzzz_1[i] * pc_x[i];

        ta1_x_xxxyy_zzzzz_0[i] = ta1_x_xxx_zzzzz_0[i] * fe_0 - ta1_x_xxx_zzzzz_1[i] * fe_0 + ta1_x_xxxy_zzzzz_0[i] * pa_y[i] - ta1_x_xxxy_zzzzz_1[i] * pc_y[i];
    }

    // Set up 84-105 components of targeted buffer : HH

    auto ta1_x_xxxyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 84);

    auto ta1_x_xxxyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 85);

    auto ta1_x_xxxyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 86);

    auto ta1_x_xxxyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 87);

    auto ta1_x_xxxyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 88);

    auto ta1_x_xxxyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 89);

    auto ta1_x_xxxyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 90);

    auto ta1_x_xxxyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 91);

    auto ta1_x_xxxyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 92);

    auto ta1_x_xxxyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 93);

    auto ta1_x_xxxyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 94);

    auto ta1_x_xxxyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 95);

    auto ta1_x_xxxyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 96);

    auto ta1_x_xxxyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 97);

    auto ta1_x_xxxyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 98);

    auto ta1_x_xxxyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 99);

    auto ta1_x_xxxyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 100);

    auto ta1_x_xxxyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 101);

    auto ta1_x_xxxyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 102);

    auto ta1_x_xxxyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 103);

    auto ta1_x_xxxyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 104);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_x_xxxy_xxxxy_0, ta1_x_xxxy_xxxxy_1, ta1_x_xxxy_xxxyy_0, ta1_x_xxxy_xxxyy_1, ta1_x_xxxy_xxyyy_0, ta1_x_xxxy_xxyyy_1, ta1_x_xxxy_xyyyy_0, ta1_x_xxxy_xyyyy_1, ta1_x_xxxy_yyyyy_0, ta1_x_xxxy_yyyyy_1, ta1_x_xxxyz_xxxxx_0, ta1_x_xxxyz_xxxxy_0, ta1_x_xxxyz_xxxxz_0, ta1_x_xxxyz_xxxyy_0, ta1_x_xxxyz_xxxyz_0, ta1_x_xxxyz_xxxzz_0, ta1_x_xxxyz_xxyyy_0, ta1_x_xxxyz_xxyyz_0, ta1_x_xxxyz_xxyzz_0, ta1_x_xxxyz_xxzzz_0, ta1_x_xxxyz_xyyyy_0, ta1_x_xxxyz_xyyyz_0, ta1_x_xxxyz_xyyzz_0, ta1_x_xxxyz_xyzzz_0, ta1_x_xxxyz_xzzzz_0, ta1_x_xxxyz_yyyyy_0, ta1_x_xxxyz_yyyyz_0, ta1_x_xxxyz_yyyzz_0, ta1_x_xxxyz_yyzzz_0, ta1_x_xxxyz_yzzzz_0, ta1_x_xxxyz_zzzzz_0, ta1_x_xxxz_xxxxx_0, ta1_x_xxxz_xxxxx_1, ta1_x_xxxz_xxxxz_0, ta1_x_xxxz_xxxxz_1, ta1_x_xxxz_xxxyz_0, ta1_x_xxxz_xxxyz_1, ta1_x_xxxz_xxxz_0, ta1_x_xxxz_xxxz_1, ta1_x_xxxz_xxxzz_0, ta1_x_xxxz_xxxzz_1, ta1_x_xxxz_xxyyz_0, ta1_x_xxxz_xxyyz_1, ta1_x_xxxz_xxyz_0, ta1_x_xxxz_xxyz_1, ta1_x_xxxz_xxyzz_0, ta1_x_xxxz_xxyzz_1, ta1_x_xxxz_xxzz_0, ta1_x_xxxz_xxzz_1, ta1_x_xxxz_xxzzz_0, ta1_x_xxxz_xxzzz_1, ta1_x_xxxz_xyyyz_0, ta1_x_xxxz_xyyyz_1, ta1_x_xxxz_xyyz_0, ta1_x_xxxz_xyyz_1, ta1_x_xxxz_xyyzz_0, ta1_x_xxxz_xyyzz_1, ta1_x_xxxz_xyzz_0, ta1_x_xxxz_xyzz_1, ta1_x_xxxz_xyzzz_0, ta1_x_xxxz_xyzzz_1, ta1_x_xxxz_xzzz_0, ta1_x_xxxz_xzzz_1, ta1_x_xxxz_xzzzz_0, ta1_x_xxxz_xzzzz_1, ta1_x_xxxz_yyyyz_0, ta1_x_xxxz_yyyyz_1, ta1_x_xxxz_yyyz_0, ta1_x_xxxz_yyyz_1, ta1_x_xxxz_yyyzz_0, ta1_x_xxxz_yyyzz_1, ta1_x_xxxz_yyzz_0, ta1_x_xxxz_yyzz_1, ta1_x_xxxz_yyzzz_0, ta1_x_xxxz_yyzzz_1, ta1_x_xxxz_yzzz_0, ta1_x_xxxz_yzzz_1, ta1_x_xxxz_yzzzz_0, ta1_x_xxxz_yzzzz_1, ta1_x_xxxz_zzzz_0, ta1_x_xxxz_zzzz_1, ta1_x_xxxz_zzzzz_0, ta1_x_xxxz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxyz_xxxxx_0[i] = ta1_x_xxxz_xxxxx_0[i] * pa_y[i] - ta1_x_xxxz_xxxxx_1[i] * pc_y[i];

        ta1_x_xxxyz_xxxxy_0[i] = ta1_x_xxxy_xxxxy_0[i] * pa_z[i] - ta1_x_xxxy_xxxxy_1[i] * pc_z[i];

        ta1_x_xxxyz_xxxxz_0[i] = ta1_x_xxxz_xxxxz_0[i] * pa_y[i] - ta1_x_xxxz_xxxxz_1[i] * pc_y[i];

        ta1_x_xxxyz_xxxyy_0[i] = ta1_x_xxxy_xxxyy_0[i] * pa_z[i] - ta1_x_xxxy_xxxyy_1[i] * pc_z[i];

        ta1_x_xxxyz_xxxyz_0[i] = ta1_x_xxxz_xxxz_0[i] * fe_0 - ta1_x_xxxz_xxxz_1[i] * fe_0 + ta1_x_xxxz_xxxyz_0[i] * pa_y[i] - ta1_x_xxxz_xxxyz_1[i] * pc_y[i];

        ta1_x_xxxyz_xxxzz_0[i] = ta1_x_xxxz_xxxzz_0[i] * pa_y[i] - ta1_x_xxxz_xxxzz_1[i] * pc_y[i];

        ta1_x_xxxyz_xxyyy_0[i] = ta1_x_xxxy_xxyyy_0[i] * pa_z[i] - ta1_x_xxxy_xxyyy_1[i] * pc_z[i];

        ta1_x_xxxyz_xxyyz_0[i] = 2.0 * ta1_x_xxxz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_xxyz_1[i] * fe_0 + ta1_x_xxxz_xxyyz_0[i] * pa_y[i] - ta1_x_xxxz_xxyyz_1[i] * pc_y[i];

        ta1_x_xxxyz_xxyzz_0[i] = ta1_x_xxxz_xxzz_0[i] * fe_0 - ta1_x_xxxz_xxzz_1[i] * fe_0 + ta1_x_xxxz_xxyzz_0[i] * pa_y[i] - ta1_x_xxxz_xxyzz_1[i] * pc_y[i];

        ta1_x_xxxyz_xxzzz_0[i] = ta1_x_xxxz_xxzzz_0[i] * pa_y[i] - ta1_x_xxxz_xxzzz_1[i] * pc_y[i];

        ta1_x_xxxyz_xyyyy_0[i] = ta1_x_xxxy_xyyyy_0[i] * pa_z[i] - ta1_x_xxxy_xyyyy_1[i] * pc_z[i];

        ta1_x_xxxyz_xyyyz_0[i] = 3.0 * ta1_x_xxxz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xxxz_xyyz_1[i] * fe_0 + ta1_x_xxxz_xyyyz_0[i] * pa_y[i] - ta1_x_xxxz_xyyyz_1[i] * pc_y[i];

        ta1_x_xxxyz_xyyzz_0[i] = 2.0 * ta1_x_xxxz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_xyzz_1[i] * fe_0 + ta1_x_xxxz_xyyzz_0[i] * pa_y[i] - ta1_x_xxxz_xyyzz_1[i] * pc_y[i];

        ta1_x_xxxyz_xyzzz_0[i] = ta1_x_xxxz_xzzz_0[i] * fe_0 - ta1_x_xxxz_xzzz_1[i] * fe_0 + ta1_x_xxxz_xyzzz_0[i] * pa_y[i] - ta1_x_xxxz_xyzzz_1[i] * pc_y[i];

        ta1_x_xxxyz_xzzzz_0[i] = ta1_x_xxxz_xzzzz_0[i] * pa_y[i] - ta1_x_xxxz_xzzzz_1[i] * pc_y[i];

        ta1_x_xxxyz_yyyyy_0[i] = ta1_x_xxxy_yyyyy_0[i] * pa_z[i] - ta1_x_xxxy_yyyyy_1[i] * pc_z[i];

        ta1_x_xxxyz_yyyyz_0[i] = 4.0 * ta1_x_xxxz_yyyz_0[i] * fe_0 - 4.0 * ta1_x_xxxz_yyyz_1[i] * fe_0 + ta1_x_xxxz_yyyyz_0[i] * pa_y[i] - ta1_x_xxxz_yyyyz_1[i] * pc_y[i];

        ta1_x_xxxyz_yyyzz_0[i] = 3.0 * ta1_x_xxxz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_xxxz_yyzz_1[i] * fe_0 + ta1_x_xxxz_yyyzz_0[i] * pa_y[i] - ta1_x_xxxz_yyyzz_1[i] * pc_y[i];

        ta1_x_xxxyz_yyzzz_0[i] = 2.0 * ta1_x_xxxz_yzzz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_yzzz_1[i] * fe_0 + ta1_x_xxxz_yyzzz_0[i] * pa_y[i] - ta1_x_xxxz_yyzzz_1[i] * pc_y[i];

        ta1_x_xxxyz_yzzzz_0[i] = ta1_x_xxxz_zzzz_0[i] * fe_0 - ta1_x_xxxz_zzzz_1[i] * fe_0 + ta1_x_xxxz_yzzzz_0[i] * pa_y[i] - ta1_x_xxxz_yzzzz_1[i] * pc_y[i];

        ta1_x_xxxyz_zzzzz_0[i] = ta1_x_xxxz_zzzzz_0[i] * pa_y[i] - ta1_x_xxxz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 105-126 components of targeted buffer : HH

    auto ta1_x_xxxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 105);

    auto ta1_x_xxxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 106);

    auto ta1_x_xxxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 107);

    auto ta1_x_xxxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 108);

    auto ta1_x_xxxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 109);

    auto ta1_x_xxxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 110);

    auto ta1_x_xxxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 111);

    auto ta1_x_xxxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 112);

    auto ta1_x_xxxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 113);

    auto ta1_x_xxxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 114);

    auto ta1_x_xxxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 115);

    auto ta1_x_xxxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 116);

    auto ta1_x_xxxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 117);

    auto ta1_x_xxxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 118);

    auto ta1_x_xxxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 119);

    auto ta1_x_xxxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 120);

    auto ta1_x_xxxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 121);

    auto ta1_x_xxxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 122);

    auto ta1_x_xxxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 123);

    auto ta1_x_xxxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 124);

    auto ta1_x_xxxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 125);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_x_xxx_xxxxx_0, ta1_x_xxx_xxxxx_1, ta1_x_xxx_xxxxy_0, ta1_x_xxx_xxxxy_1, ta1_x_xxx_xxxxz_0, ta1_x_xxx_xxxxz_1, ta1_x_xxx_xxxyy_0, ta1_x_xxx_xxxyy_1, ta1_x_xxx_xxxyz_0, ta1_x_xxx_xxxyz_1, ta1_x_xxx_xxxzz_0, ta1_x_xxx_xxxzz_1, ta1_x_xxx_xxyyy_0, ta1_x_xxx_xxyyy_1, ta1_x_xxx_xxyyz_0, ta1_x_xxx_xxyyz_1, ta1_x_xxx_xxyzz_0, ta1_x_xxx_xxyzz_1, ta1_x_xxx_xxzzz_0, ta1_x_xxx_xxzzz_1, ta1_x_xxx_xyyyy_0, ta1_x_xxx_xyyyy_1, ta1_x_xxx_xyyyz_0, ta1_x_xxx_xyyyz_1, ta1_x_xxx_xyyzz_0, ta1_x_xxx_xyyzz_1, ta1_x_xxx_xyzzz_0, ta1_x_xxx_xyzzz_1, ta1_x_xxx_xzzzz_0, ta1_x_xxx_xzzzz_1, ta1_x_xxx_yyyyy_0, ta1_x_xxx_yyyyy_1, ta1_x_xxxz_xxxx_0, ta1_x_xxxz_xxxx_1, ta1_x_xxxz_xxxxx_0, ta1_x_xxxz_xxxxx_1, ta1_x_xxxz_xxxxy_0, ta1_x_xxxz_xxxxy_1, ta1_x_xxxz_xxxxz_0, ta1_x_xxxz_xxxxz_1, ta1_x_xxxz_xxxy_0, ta1_x_xxxz_xxxy_1, ta1_x_xxxz_xxxyy_0, ta1_x_xxxz_xxxyy_1, ta1_x_xxxz_xxxyz_0, ta1_x_xxxz_xxxyz_1, ta1_x_xxxz_xxxz_0, ta1_x_xxxz_xxxz_1, ta1_x_xxxz_xxxzz_0, ta1_x_xxxz_xxxzz_1, ta1_x_xxxz_xxyy_0, ta1_x_xxxz_xxyy_1, ta1_x_xxxz_xxyyy_0, ta1_x_xxxz_xxyyy_1, ta1_x_xxxz_xxyyz_0, ta1_x_xxxz_xxyyz_1, ta1_x_xxxz_xxyz_0, ta1_x_xxxz_xxyz_1, ta1_x_xxxz_xxyzz_0, ta1_x_xxxz_xxyzz_1, ta1_x_xxxz_xxzz_0, ta1_x_xxxz_xxzz_1, ta1_x_xxxz_xxzzz_0, ta1_x_xxxz_xxzzz_1, ta1_x_xxxz_xyyy_0, ta1_x_xxxz_xyyy_1, ta1_x_xxxz_xyyyy_0, ta1_x_xxxz_xyyyy_1, ta1_x_xxxz_xyyyz_0, ta1_x_xxxz_xyyyz_1, ta1_x_xxxz_xyyz_0, ta1_x_xxxz_xyyz_1, ta1_x_xxxz_xyyzz_0, ta1_x_xxxz_xyyzz_1, ta1_x_xxxz_xyzz_0, ta1_x_xxxz_xyzz_1, ta1_x_xxxz_xyzzz_0, ta1_x_xxxz_xyzzz_1, ta1_x_xxxz_xzzz_0, ta1_x_xxxz_xzzz_1, ta1_x_xxxz_xzzzz_0, ta1_x_xxxz_xzzzz_1, ta1_x_xxxz_yyyyy_0, ta1_x_xxxz_yyyyy_1, ta1_x_xxxzz_xxxxx_0, ta1_x_xxxzz_xxxxy_0, ta1_x_xxxzz_xxxxz_0, ta1_x_xxxzz_xxxyy_0, ta1_x_xxxzz_xxxyz_0, ta1_x_xxxzz_xxxzz_0, ta1_x_xxxzz_xxyyy_0, ta1_x_xxxzz_xxyyz_0, ta1_x_xxxzz_xxyzz_0, ta1_x_xxxzz_xxzzz_0, ta1_x_xxxzz_xyyyy_0, ta1_x_xxxzz_xyyyz_0, ta1_x_xxxzz_xyyzz_0, ta1_x_xxxzz_xyzzz_0, ta1_x_xxxzz_xzzzz_0, ta1_x_xxxzz_yyyyy_0, ta1_x_xxxzz_yyyyz_0, ta1_x_xxxzz_yyyzz_0, ta1_x_xxxzz_yyzzz_0, ta1_x_xxxzz_yzzzz_0, ta1_x_xxxzz_zzzzz_0, ta1_x_xxzz_yyyyz_0, ta1_x_xxzz_yyyyz_1, ta1_x_xxzz_yyyzz_0, ta1_x_xxzz_yyyzz_1, ta1_x_xxzz_yyzzz_0, ta1_x_xxzz_yyzzz_1, ta1_x_xxzz_yzzzz_0, ta1_x_xxzz_yzzzz_1, ta1_x_xxzz_zzzzz_0, ta1_x_xxzz_zzzzz_1, ta1_x_xzz_yyyyz_0, ta1_x_xzz_yyyyz_1, ta1_x_xzz_yyyzz_0, ta1_x_xzz_yyyzz_1, ta1_x_xzz_yyzzz_0, ta1_x_xzz_yyzzz_1, ta1_x_xzz_yzzzz_0, ta1_x_xzz_yzzzz_1, ta1_x_xzz_zzzzz_0, ta1_x_xzz_zzzzz_1, ta_xxzz_yyyyz_1, ta_xxzz_yyyzz_1, ta_xxzz_yyzzz_1, ta_xxzz_yzzzz_1, ta_xxzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxxzz_xxxxx_0[i] = ta1_x_xxx_xxxxx_0[i] * fe_0 - ta1_x_xxx_xxxxx_1[i] * fe_0 + ta1_x_xxxz_xxxxx_0[i] * pa_z[i] - ta1_x_xxxz_xxxxx_1[i] * pc_z[i];

        ta1_x_xxxzz_xxxxy_0[i] = ta1_x_xxx_xxxxy_0[i] * fe_0 - ta1_x_xxx_xxxxy_1[i] * fe_0 + ta1_x_xxxz_xxxxy_0[i] * pa_z[i] - ta1_x_xxxz_xxxxy_1[i] * pc_z[i];

        ta1_x_xxxzz_xxxxz_0[i] = ta1_x_xxx_xxxxz_0[i] * fe_0 - ta1_x_xxx_xxxxz_1[i] * fe_0 + ta1_x_xxxz_xxxx_0[i] * fe_0 - ta1_x_xxxz_xxxx_1[i] * fe_0 + ta1_x_xxxz_xxxxz_0[i] * pa_z[i] - ta1_x_xxxz_xxxxz_1[i] * pc_z[i];

        ta1_x_xxxzz_xxxyy_0[i] = ta1_x_xxx_xxxyy_0[i] * fe_0 - ta1_x_xxx_xxxyy_1[i] * fe_0 + ta1_x_xxxz_xxxyy_0[i] * pa_z[i] - ta1_x_xxxz_xxxyy_1[i] * pc_z[i];

        ta1_x_xxxzz_xxxyz_0[i] = ta1_x_xxx_xxxyz_0[i] * fe_0 - ta1_x_xxx_xxxyz_1[i] * fe_0 + ta1_x_xxxz_xxxy_0[i] * fe_0 - ta1_x_xxxz_xxxy_1[i] * fe_0 + ta1_x_xxxz_xxxyz_0[i] * pa_z[i] - ta1_x_xxxz_xxxyz_1[i] * pc_z[i];

        ta1_x_xxxzz_xxxzz_0[i] = ta1_x_xxx_xxxzz_0[i] * fe_0 - ta1_x_xxx_xxxzz_1[i] * fe_0 + 2.0 * ta1_x_xxxz_xxxz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_xxxz_1[i] * fe_0 + ta1_x_xxxz_xxxzz_0[i] * pa_z[i] - ta1_x_xxxz_xxxzz_1[i] * pc_z[i];

        ta1_x_xxxzz_xxyyy_0[i] = ta1_x_xxx_xxyyy_0[i] * fe_0 - ta1_x_xxx_xxyyy_1[i] * fe_0 + ta1_x_xxxz_xxyyy_0[i] * pa_z[i] - ta1_x_xxxz_xxyyy_1[i] * pc_z[i];

        ta1_x_xxxzz_xxyyz_0[i] = ta1_x_xxx_xxyyz_0[i] * fe_0 - ta1_x_xxx_xxyyz_1[i] * fe_0 + ta1_x_xxxz_xxyy_0[i] * fe_0 - ta1_x_xxxz_xxyy_1[i] * fe_0 + ta1_x_xxxz_xxyyz_0[i] * pa_z[i] - ta1_x_xxxz_xxyyz_1[i] * pc_z[i];

        ta1_x_xxxzz_xxyzz_0[i] = ta1_x_xxx_xxyzz_0[i] * fe_0 - ta1_x_xxx_xxyzz_1[i] * fe_0 + 2.0 * ta1_x_xxxz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_xxyz_1[i] * fe_0 + ta1_x_xxxz_xxyzz_0[i] * pa_z[i] - ta1_x_xxxz_xxyzz_1[i] * pc_z[i];

        ta1_x_xxxzz_xxzzz_0[i] = ta1_x_xxx_xxzzz_0[i] * fe_0 - ta1_x_xxx_xxzzz_1[i] * fe_0 + 3.0 * ta1_x_xxxz_xxzz_0[i] * fe_0 - 3.0 * ta1_x_xxxz_xxzz_1[i] * fe_0 + ta1_x_xxxz_xxzzz_0[i] * pa_z[i] - ta1_x_xxxz_xxzzz_1[i] * pc_z[i];

        ta1_x_xxxzz_xyyyy_0[i] = ta1_x_xxx_xyyyy_0[i] * fe_0 - ta1_x_xxx_xyyyy_1[i] * fe_0 + ta1_x_xxxz_xyyyy_0[i] * pa_z[i] - ta1_x_xxxz_xyyyy_1[i] * pc_z[i];

        ta1_x_xxxzz_xyyyz_0[i] = ta1_x_xxx_xyyyz_0[i] * fe_0 - ta1_x_xxx_xyyyz_1[i] * fe_0 + ta1_x_xxxz_xyyy_0[i] * fe_0 - ta1_x_xxxz_xyyy_1[i] * fe_0 + ta1_x_xxxz_xyyyz_0[i] * pa_z[i] - ta1_x_xxxz_xyyyz_1[i] * pc_z[i];

        ta1_x_xxxzz_xyyzz_0[i] = ta1_x_xxx_xyyzz_0[i] * fe_0 - ta1_x_xxx_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_xxxz_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xxxz_xyyz_1[i] * fe_0 + ta1_x_xxxz_xyyzz_0[i] * pa_z[i] - ta1_x_xxxz_xyyzz_1[i] * pc_z[i];

        ta1_x_xxxzz_xyzzz_0[i] = ta1_x_xxx_xyzzz_0[i] * fe_0 - ta1_x_xxx_xyzzz_1[i] * fe_0 + 3.0 * ta1_x_xxxz_xyzz_0[i] * fe_0 - 3.0 * ta1_x_xxxz_xyzz_1[i] * fe_0 + ta1_x_xxxz_xyzzz_0[i] * pa_z[i] - ta1_x_xxxz_xyzzz_1[i] * pc_z[i];

        ta1_x_xxxzz_xzzzz_0[i] = ta1_x_xxx_xzzzz_0[i] * fe_0 - ta1_x_xxx_xzzzz_1[i] * fe_0 + 4.0 * ta1_x_xxxz_xzzz_0[i] * fe_0 - 4.0 * ta1_x_xxxz_xzzz_1[i] * fe_0 + ta1_x_xxxz_xzzzz_0[i] * pa_z[i] - ta1_x_xxxz_xzzzz_1[i] * pc_z[i];

        ta1_x_xxxzz_yyyyy_0[i] = ta1_x_xxx_yyyyy_0[i] * fe_0 - ta1_x_xxx_yyyyy_1[i] * fe_0 + ta1_x_xxxz_yyyyy_0[i] * pa_z[i] - ta1_x_xxxz_yyyyy_1[i] * pc_z[i];

        ta1_x_xxxzz_yyyyz_0[i] = 2.0 * ta1_x_xzz_yyyyz_0[i] * fe_0 - 2.0 * ta1_x_xzz_yyyyz_1[i] * fe_0 + ta_xxzz_yyyyz_1[i] + ta1_x_xxzz_yyyyz_0[i] * pa_x[i] - ta1_x_xxzz_yyyyz_1[i] * pc_x[i];

        ta1_x_xxxzz_yyyzz_0[i] = 2.0 * ta1_x_xzz_yyyzz_0[i] * fe_0 - 2.0 * ta1_x_xzz_yyyzz_1[i] * fe_0 + ta_xxzz_yyyzz_1[i] + ta1_x_xxzz_yyyzz_0[i] * pa_x[i] - ta1_x_xxzz_yyyzz_1[i] * pc_x[i];

        ta1_x_xxxzz_yyzzz_0[i] = 2.0 * ta1_x_xzz_yyzzz_0[i] * fe_0 - 2.0 * ta1_x_xzz_yyzzz_1[i] * fe_0 + ta_xxzz_yyzzz_1[i] + ta1_x_xxzz_yyzzz_0[i] * pa_x[i] - ta1_x_xxzz_yyzzz_1[i] * pc_x[i];

        ta1_x_xxxzz_yzzzz_0[i] = 2.0 * ta1_x_xzz_yzzzz_0[i] * fe_0 - 2.0 * ta1_x_xzz_yzzzz_1[i] * fe_0 + ta_xxzz_yzzzz_1[i] + ta1_x_xxzz_yzzzz_0[i] * pa_x[i] - ta1_x_xxzz_yzzzz_1[i] * pc_x[i];

        ta1_x_xxxzz_zzzzz_0[i] = 2.0 * ta1_x_xzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_x_xzz_zzzzz_1[i] * fe_0 + ta_xxzz_zzzzz_1[i] + ta1_x_xxzz_zzzzz_0[i] * pa_x[i] - ta1_x_xxzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 126-147 components of targeted buffer : HH

    auto ta1_x_xxyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 126);

    auto ta1_x_xxyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 127);

    auto ta1_x_xxyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 128);

    auto ta1_x_xxyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 129);

    auto ta1_x_xxyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 130);

    auto ta1_x_xxyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 131);

    auto ta1_x_xxyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 132);

    auto ta1_x_xxyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 133);

    auto ta1_x_xxyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 134);

    auto ta1_x_xxyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 135);

    auto ta1_x_xxyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 136);

    auto ta1_x_xxyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 137);

    auto ta1_x_xxyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 138);

    auto ta1_x_xxyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 139);

    auto ta1_x_xxyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 140);

    auto ta1_x_xxyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 141);

    auto ta1_x_xxyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 142);

    auto ta1_x_xxyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 143);

    auto ta1_x_xxyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 144);

    auto ta1_x_xxyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 145);

    auto ta1_x_xxyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 146);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_x_xxy_xxxxx_0, ta1_x_xxy_xxxxx_1, ta1_x_xxy_xxxxy_0, ta1_x_xxy_xxxxy_1, ta1_x_xxy_xxxxz_0, ta1_x_xxy_xxxxz_1, ta1_x_xxy_xxxyy_0, ta1_x_xxy_xxxyy_1, ta1_x_xxy_xxxyz_0, ta1_x_xxy_xxxyz_1, ta1_x_xxy_xxxzz_0, ta1_x_xxy_xxxzz_1, ta1_x_xxy_xxyyy_0, ta1_x_xxy_xxyyy_1, ta1_x_xxy_xxyyz_0, ta1_x_xxy_xxyyz_1, ta1_x_xxy_xxyzz_0, ta1_x_xxy_xxyzz_1, ta1_x_xxy_xxzzz_0, ta1_x_xxy_xxzzz_1, ta1_x_xxy_xyyyy_0, ta1_x_xxy_xyyyy_1, ta1_x_xxy_xyyyz_0, ta1_x_xxy_xyyyz_1, ta1_x_xxy_xyyzz_0, ta1_x_xxy_xyyzz_1, ta1_x_xxy_xyzzz_0, ta1_x_xxy_xyzzz_1, ta1_x_xxy_xzzzz_0, ta1_x_xxy_xzzzz_1, ta1_x_xxy_zzzzz_0, ta1_x_xxy_zzzzz_1, ta1_x_xxyy_xxxx_0, ta1_x_xxyy_xxxx_1, ta1_x_xxyy_xxxxx_0, ta1_x_xxyy_xxxxx_1, ta1_x_xxyy_xxxxy_0, ta1_x_xxyy_xxxxy_1, ta1_x_xxyy_xxxxz_0, ta1_x_xxyy_xxxxz_1, ta1_x_xxyy_xxxy_0, ta1_x_xxyy_xxxy_1, ta1_x_xxyy_xxxyy_0, ta1_x_xxyy_xxxyy_1, ta1_x_xxyy_xxxyz_0, ta1_x_xxyy_xxxyz_1, ta1_x_xxyy_xxxz_0, ta1_x_xxyy_xxxz_1, ta1_x_xxyy_xxxzz_0, ta1_x_xxyy_xxxzz_1, ta1_x_xxyy_xxyy_0, ta1_x_xxyy_xxyy_1, ta1_x_xxyy_xxyyy_0, ta1_x_xxyy_xxyyy_1, ta1_x_xxyy_xxyyz_0, ta1_x_xxyy_xxyyz_1, ta1_x_xxyy_xxyz_0, ta1_x_xxyy_xxyz_1, ta1_x_xxyy_xxyzz_0, ta1_x_xxyy_xxyzz_1, ta1_x_xxyy_xxzz_0, ta1_x_xxyy_xxzz_1, ta1_x_xxyy_xxzzz_0, ta1_x_xxyy_xxzzz_1, ta1_x_xxyy_xyyy_0, ta1_x_xxyy_xyyy_1, ta1_x_xxyy_xyyyy_0, ta1_x_xxyy_xyyyy_1, ta1_x_xxyy_xyyyz_0, ta1_x_xxyy_xyyyz_1, ta1_x_xxyy_xyyz_0, ta1_x_xxyy_xyyz_1, ta1_x_xxyy_xyyzz_0, ta1_x_xxyy_xyyzz_1, ta1_x_xxyy_xyzz_0, ta1_x_xxyy_xyzz_1, ta1_x_xxyy_xyzzz_0, ta1_x_xxyy_xyzzz_1, ta1_x_xxyy_xzzz_0, ta1_x_xxyy_xzzz_1, ta1_x_xxyy_xzzzz_0, ta1_x_xxyy_xzzzz_1, ta1_x_xxyy_zzzzz_0, ta1_x_xxyy_zzzzz_1, ta1_x_xxyyy_xxxxx_0, ta1_x_xxyyy_xxxxy_0, ta1_x_xxyyy_xxxxz_0, ta1_x_xxyyy_xxxyy_0, ta1_x_xxyyy_xxxyz_0, ta1_x_xxyyy_xxxzz_0, ta1_x_xxyyy_xxyyy_0, ta1_x_xxyyy_xxyyz_0, ta1_x_xxyyy_xxyzz_0, ta1_x_xxyyy_xxzzz_0, ta1_x_xxyyy_xyyyy_0, ta1_x_xxyyy_xyyyz_0, ta1_x_xxyyy_xyyzz_0, ta1_x_xxyyy_xyzzz_0, ta1_x_xxyyy_xzzzz_0, ta1_x_xxyyy_yyyyy_0, ta1_x_xxyyy_yyyyz_0, ta1_x_xxyyy_yyyzz_0, ta1_x_xxyyy_yyzzz_0, ta1_x_xxyyy_yzzzz_0, ta1_x_xxyyy_zzzzz_0, ta1_x_xyyy_yyyyy_0, ta1_x_xyyy_yyyyy_1, ta1_x_xyyy_yyyyz_0, ta1_x_xyyy_yyyyz_1, ta1_x_xyyy_yyyzz_0, ta1_x_xyyy_yyyzz_1, ta1_x_xyyy_yyzzz_0, ta1_x_xyyy_yyzzz_1, ta1_x_xyyy_yzzzz_0, ta1_x_xyyy_yzzzz_1, ta1_x_yyy_yyyyy_0, ta1_x_yyy_yyyyy_1, ta1_x_yyy_yyyyz_0, ta1_x_yyy_yyyyz_1, ta1_x_yyy_yyyzz_0, ta1_x_yyy_yyyzz_1, ta1_x_yyy_yyzzz_0, ta1_x_yyy_yyzzz_1, ta1_x_yyy_yzzzz_0, ta1_x_yyy_yzzzz_1, ta_xyyy_yyyyy_1, ta_xyyy_yyyyz_1, ta_xyyy_yyyzz_1, ta_xyyy_yyzzz_1, ta_xyyy_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxyyy_xxxxx_0[i] = 2.0 * ta1_x_xxy_xxxxx_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxxx_1[i] * fe_0 + ta1_x_xxyy_xxxxx_0[i] * pa_y[i] - ta1_x_xxyy_xxxxx_1[i] * pc_y[i];

        ta1_x_xxyyy_xxxxy_0[i] = 2.0 * ta1_x_xxy_xxxxy_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxxy_1[i] * fe_0 + ta1_x_xxyy_xxxx_0[i] * fe_0 - ta1_x_xxyy_xxxx_1[i] * fe_0 + ta1_x_xxyy_xxxxy_0[i] * pa_y[i] - ta1_x_xxyy_xxxxy_1[i] * pc_y[i];

        ta1_x_xxyyy_xxxxz_0[i] = 2.0 * ta1_x_xxy_xxxxz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxxz_1[i] * fe_0 + ta1_x_xxyy_xxxxz_0[i] * pa_y[i] - ta1_x_xxyy_xxxxz_1[i] * pc_y[i];

        ta1_x_xxyyy_xxxyy_0[i] = 2.0 * ta1_x_xxy_xxxyy_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxyy_1[i] * fe_0 + 2.0 * ta1_x_xxyy_xxxy_0[i] * fe_0 - 2.0 * ta1_x_xxyy_xxxy_1[i] * fe_0 + ta1_x_xxyy_xxxyy_0[i] * pa_y[i] - ta1_x_xxyy_xxxyy_1[i] * pc_y[i];

        ta1_x_xxyyy_xxxyz_0[i] = 2.0 * ta1_x_xxy_xxxyz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxyz_1[i] * fe_0 + ta1_x_xxyy_xxxz_0[i] * fe_0 - ta1_x_xxyy_xxxz_1[i] * fe_0 + ta1_x_xxyy_xxxyz_0[i] * pa_y[i] - ta1_x_xxyy_xxxyz_1[i] * pc_y[i];

        ta1_x_xxyyy_xxxzz_0[i] = 2.0 * ta1_x_xxy_xxxzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxxzz_1[i] * fe_0 + ta1_x_xxyy_xxxzz_0[i] * pa_y[i] - ta1_x_xxyy_xxxzz_1[i] * pc_y[i];

        ta1_x_xxyyy_xxyyy_0[i] = 2.0 * ta1_x_xxy_xxyyy_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxyyy_1[i] * fe_0 + 3.0 * ta1_x_xxyy_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xxyy_xxyy_1[i] * fe_0 + ta1_x_xxyy_xxyyy_0[i] * pa_y[i] - ta1_x_xxyy_xxyyy_1[i] * pc_y[i];

        ta1_x_xxyyy_xxyyz_0[i] = 2.0 * ta1_x_xxy_xxyyz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_xxyy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxyy_xxyz_1[i] * fe_0 + ta1_x_xxyy_xxyyz_0[i] * pa_y[i] - ta1_x_xxyy_xxyyz_1[i] * pc_y[i];

        ta1_x_xxyyy_xxyzz_0[i] = 2.0 * ta1_x_xxy_xxyzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxyzz_1[i] * fe_0 + ta1_x_xxyy_xxzz_0[i] * fe_0 - ta1_x_xxyy_xxzz_1[i] * fe_0 + ta1_x_xxyy_xxyzz_0[i] * pa_y[i] - ta1_x_xxyy_xxyzz_1[i] * pc_y[i];

        ta1_x_xxyyy_xxzzz_0[i] = 2.0 * ta1_x_xxy_xxzzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xxzzz_1[i] * fe_0 + ta1_x_xxyy_xxzzz_0[i] * pa_y[i] - ta1_x_xxyy_xxzzz_1[i] * pc_y[i];

        ta1_x_xxyyy_xyyyy_0[i] = 2.0 * ta1_x_xxy_xyyyy_0[i] * fe_0 - 2.0 * ta1_x_xxy_xyyyy_1[i] * fe_0 + 4.0 * ta1_x_xxyy_xyyy_0[i] * fe_0 - 4.0 * ta1_x_xxyy_xyyy_1[i] * fe_0 + ta1_x_xxyy_xyyyy_0[i] * pa_y[i] - ta1_x_xxyy_xyyyy_1[i] * pc_y[i];

        ta1_x_xxyyy_xyyyz_0[i] = 2.0 * ta1_x_xxy_xyyyz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xyyyz_1[i] * fe_0 + 3.0 * ta1_x_xxyy_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xxyy_xyyz_1[i] * fe_0 + ta1_x_xxyy_xyyyz_0[i] * pa_y[i] - ta1_x_xxyy_xyyyz_1[i] * pc_y[i];

        ta1_x_xxyyy_xyyzz_0[i] = 2.0 * ta1_x_xxy_xyyzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_xxyy_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxyy_xyzz_1[i] * fe_0 + ta1_x_xxyy_xyyzz_0[i] * pa_y[i] - ta1_x_xxyy_xyyzz_1[i] * pc_y[i];

        ta1_x_xxyyy_xyzzz_0[i] = 2.0 * ta1_x_xxy_xyzzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xyzzz_1[i] * fe_0 + ta1_x_xxyy_xzzz_0[i] * fe_0 - ta1_x_xxyy_xzzz_1[i] * fe_0 + ta1_x_xxyy_xyzzz_0[i] * pa_y[i] - ta1_x_xxyy_xyzzz_1[i] * pc_y[i];

        ta1_x_xxyyy_xzzzz_0[i] = 2.0 * ta1_x_xxy_xzzzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_xzzzz_1[i] * fe_0 + ta1_x_xxyy_xzzzz_0[i] * pa_y[i] - ta1_x_xxyy_xzzzz_1[i] * pc_y[i];

        ta1_x_xxyyy_yyyyy_0[i] = ta1_x_yyy_yyyyy_0[i] * fe_0 - ta1_x_yyy_yyyyy_1[i] * fe_0 + ta_xyyy_yyyyy_1[i] + ta1_x_xyyy_yyyyy_0[i] * pa_x[i] - ta1_x_xyyy_yyyyy_1[i] * pc_x[i];

        ta1_x_xxyyy_yyyyz_0[i] = ta1_x_yyy_yyyyz_0[i] * fe_0 - ta1_x_yyy_yyyyz_1[i] * fe_0 + ta_xyyy_yyyyz_1[i] + ta1_x_xyyy_yyyyz_0[i] * pa_x[i] - ta1_x_xyyy_yyyyz_1[i] * pc_x[i];

        ta1_x_xxyyy_yyyzz_0[i] = ta1_x_yyy_yyyzz_0[i] * fe_0 - ta1_x_yyy_yyyzz_1[i] * fe_0 + ta_xyyy_yyyzz_1[i] + ta1_x_xyyy_yyyzz_0[i] * pa_x[i] - ta1_x_xyyy_yyyzz_1[i] * pc_x[i];

        ta1_x_xxyyy_yyzzz_0[i] = ta1_x_yyy_yyzzz_0[i] * fe_0 - ta1_x_yyy_yyzzz_1[i] * fe_0 + ta_xyyy_yyzzz_1[i] + ta1_x_xyyy_yyzzz_0[i] * pa_x[i] - ta1_x_xyyy_yyzzz_1[i] * pc_x[i];

        ta1_x_xxyyy_yzzzz_0[i] = ta1_x_yyy_yzzzz_0[i] * fe_0 - ta1_x_yyy_yzzzz_1[i] * fe_0 + ta_xyyy_yzzzz_1[i] + ta1_x_xyyy_yzzzz_0[i] * pa_x[i] - ta1_x_xyyy_yzzzz_1[i] * pc_x[i];

        ta1_x_xxyyy_zzzzz_0[i] = 2.0 * ta1_x_xxy_zzzzz_0[i] * fe_0 - 2.0 * ta1_x_xxy_zzzzz_1[i] * fe_0 + ta1_x_xxyy_zzzzz_0[i] * pa_y[i] - ta1_x_xxyy_zzzzz_1[i] * pc_y[i];
    }

    // Set up 147-168 components of targeted buffer : HH

    auto ta1_x_xxyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 147);

    auto ta1_x_xxyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 148);

    auto ta1_x_xxyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 149);

    auto ta1_x_xxyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 150);

    auto ta1_x_xxyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 151);

    auto ta1_x_xxyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 152);

    auto ta1_x_xxyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 153);

    auto ta1_x_xxyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 154);

    auto ta1_x_xxyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 155);

    auto ta1_x_xxyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 156);

    auto ta1_x_xxyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 157);

    auto ta1_x_xxyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 158);

    auto ta1_x_xxyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 159);

    auto ta1_x_xxyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 160);

    auto ta1_x_xxyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 161);

    auto ta1_x_xxyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 162);

    auto ta1_x_xxyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 163);

    auto ta1_x_xxyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 164);

    auto ta1_x_xxyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 165);

    auto ta1_x_xxyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 166);

    auto ta1_x_xxyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 167);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_x_xxyy_xxxxx_0, ta1_x_xxyy_xxxxx_1, ta1_x_xxyy_xxxxy_0, ta1_x_xxyy_xxxxy_1, ta1_x_xxyy_xxxy_0, ta1_x_xxyy_xxxy_1, ta1_x_xxyy_xxxyy_0, ta1_x_xxyy_xxxyy_1, ta1_x_xxyy_xxxyz_0, ta1_x_xxyy_xxxyz_1, ta1_x_xxyy_xxyy_0, ta1_x_xxyy_xxyy_1, ta1_x_xxyy_xxyyy_0, ta1_x_xxyy_xxyyy_1, ta1_x_xxyy_xxyyz_0, ta1_x_xxyy_xxyyz_1, ta1_x_xxyy_xxyz_0, ta1_x_xxyy_xxyz_1, ta1_x_xxyy_xxyzz_0, ta1_x_xxyy_xxyzz_1, ta1_x_xxyy_xyyy_0, ta1_x_xxyy_xyyy_1, ta1_x_xxyy_xyyyy_0, ta1_x_xxyy_xyyyy_1, ta1_x_xxyy_xyyyz_0, ta1_x_xxyy_xyyyz_1, ta1_x_xxyy_xyyz_0, ta1_x_xxyy_xyyz_1, ta1_x_xxyy_xyyzz_0, ta1_x_xxyy_xyyzz_1, ta1_x_xxyy_xyzz_0, ta1_x_xxyy_xyzz_1, ta1_x_xxyy_xyzzz_0, ta1_x_xxyy_xyzzz_1, ta1_x_xxyy_yyyy_0, ta1_x_xxyy_yyyy_1, ta1_x_xxyy_yyyyy_0, ta1_x_xxyy_yyyyy_1, ta1_x_xxyy_yyyyz_0, ta1_x_xxyy_yyyyz_1, ta1_x_xxyy_yyyz_0, ta1_x_xxyy_yyyz_1, ta1_x_xxyy_yyyzz_0, ta1_x_xxyy_yyyzz_1, ta1_x_xxyy_yyzz_0, ta1_x_xxyy_yyzz_1, ta1_x_xxyy_yyzzz_0, ta1_x_xxyy_yyzzz_1, ta1_x_xxyy_yzzz_0, ta1_x_xxyy_yzzz_1, ta1_x_xxyy_yzzzz_0, ta1_x_xxyy_yzzzz_1, ta1_x_xxyyz_xxxxx_0, ta1_x_xxyyz_xxxxy_0, ta1_x_xxyyz_xxxxz_0, ta1_x_xxyyz_xxxyy_0, ta1_x_xxyyz_xxxyz_0, ta1_x_xxyyz_xxxzz_0, ta1_x_xxyyz_xxyyy_0, ta1_x_xxyyz_xxyyz_0, ta1_x_xxyyz_xxyzz_0, ta1_x_xxyyz_xxzzz_0, ta1_x_xxyyz_xyyyy_0, ta1_x_xxyyz_xyyyz_0, ta1_x_xxyyz_xyyzz_0, ta1_x_xxyyz_xyzzz_0, ta1_x_xxyyz_xzzzz_0, ta1_x_xxyyz_yyyyy_0, ta1_x_xxyyz_yyyyz_0, ta1_x_xxyyz_yyyzz_0, ta1_x_xxyyz_yyzzz_0, ta1_x_xxyyz_yzzzz_0, ta1_x_xxyyz_zzzzz_0, ta1_x_xxyz_xxxxz_0, ta1_x_xxyz_xxxxz_1, ta1_x_xxyz_xxxzz_0, ta1_x_xxyz_xxxzz_1, ta1_x_xxyz_xxzzz_0, ta1_x_xxyz_xxzzz_1, ta1_x_xxyz_xzzzz_0, ta1_x_xxyz_xzzzz_1, ta1_x_xxyz_zzzzz_0, ta1_x_xxyz_zzzzz_1, ta1_x_xxz_xxxxz_0, ta1_x_xxz_xxxxz_1, ta1_x_xxz_xxxzz_0, ta1_x_xxz_xxxzz_1, ta1_x_xxz_xxzzz_0, ta1_x_xxz_xxzzz_1, ta1_x_xxz_xzzzz_0, ta1_x_xxz_xzzzz_1, ta1_x_xxz_zzzzz_0, ta1_x_xxz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxyyz_xxxxx_0[i] = ta1_x_xxyy_xxxxx_0[i] * pa_z[i] - ta1_x_xxyy_xxxxx_1[i] * pc_z[i];

        ta1_x_xxyyz_xxxxy_0[i] = ta1_x_xxyy_xxxxy_0[i] * pa_z[i] - ta1_x_xxyy_xxxxy_1[i] * pc_z[i];

        ta1_x_xxyyz_xxxxz_0[i] = ta1_x_xxz_xxxxz_0[i] * fe_0 - ta1_x_xxz_xxxxz_1[i] * fe_0 + ta1_x_xxyz_xxxxz_0[i] * pa_y[i] - ta1_x_xxyz_xxxxz_1[i] * pc_y[i];

        ta1_x_xxyyz_xxxyy_0[i] = ta1_x_xxyy_xxxyy_0[i] * pa_z[i] - ta1_x_xxyy_xxxyy_1[i] * pc_z[i];

        ta1_x_xxyyz_xxxyz_0[i] = ta1_x_xxyy_xxxy_0[i] * fe_0 - ta1_x_xxyy_xxxy_1[i] * fe_0 + ta1_x_xxyy_xxxyz_0[i] * pa_z[i] - ta1_x_xxyy_xxxyz_1[i] * pc_z[i];

        ta1_x_xxyyz_xxxzz_0[i] = ta1_x_xxz_xxxzz_0[i] * fe_0 - ta1_x_xxz_xxxzz_1[i] * fe_0 + ta1_x_xxyz_xxxzz_0[i] * pa_y[i] - ta1_x_xxyz_xxxzz_1[i] * pc_y[i];

        ta1_x_xxyyz_xxyyy_0[i] = ta1_x_xxyy_xxyyy_0[i] * pa_z[i] - ta1_x_xxyy_xxyyy_1[i] * pc_z[i];

        ta1_x_xxyyz_xxyyz_0[i] = ta1_x_xxyy_xxyy_0[i] * fe_0 - ta1_x_xxyy_xxyy_1[i] * fe_0 + ta1_x_xxyy_xxyyz_0[i] * pa_z[i] - ta1_x_xxyy_xxyyz_1[i] * pc_z[i];

        ta1_x_xxyyz_xxyzz_0[i] = 2.0 * ta1_x_xxyy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxyy_xxyz_1[i] * fe_0 + ta1_x_xxyy_xxyzz_0[i] * pa_z[i] - ta1_x_xxyy_xxyzz_1[i] * pc_z[i];

        ta1_x_xxyyz_xxzzz_0[i] = ta1_x_xxz_xxzzz_0[i] * fe_0 - ta1_x_xxz_xxzzz_1[i] * fe_0 + ta1_x_xxyz_xxzzz_0[i] * pa_y[i] - ta1_x_xxyz_xxzzz_1[i] * pc_y[i];

        ta1_x_xxyyz_xyyyy_0[i] = ta1_x_xxyy_xyyyy_0[i] * pa_z[i] - ta1_x_xxyy_xyyyy_1[i] * pc_z[i];

        ta1_x_xxyyz_xyyyz_0[i] = ta1_x_xxyy_xyyy_0[i] * fe_0 - ta1_x_xxyy_xyyy_1[i] * fe_0 + ta1_x_xxyy_xyyyz_0[i] * pa_z[i] - ta1_x_xxyy_xyyyz_1[i] * pc_z[i];

        ta1_x_xxyyz_xyyzz_0[i] = 2.0 * ta1_x_xxyy_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xxyy_xyyz_1[i] * fe_0 + ta1_x_xxyy_xyyzz_0[i] * pa_z[i] - ta1_x_xxyy_xyyzz_1[i] * pc_z[i];

        ta1_x_xxyyz_xyzzz_0[i] = 3.0 * ta1_x_xxyy_xyzz_0[i] * fe_0 - 3.0 * ta1_x_xxyy_xyzz_1[i] * fe_0 + ta1_x_xxyy_xyzzz_0[i] * pa_z[i] - ta1_x_xxyy_xyzzz_1[i] * pc_z[i];

        ta1_x_xxyyz_xzzzz_0[i] = ta1_x_xxz_xzzzz_0[i] * fe_0 - ta1_x_xxz_xzzzz_1[i] * fe_0 + ta1_x_xxyz_xzzzz_0[i] * pa_y[i] - ta1_x_xxyz_xzzzz_1[i] * pc_y[i];

        ta1_x_xxyyz_yyyyy_0[i] = ta1_x_xxyy_yyyyy_0[i] * pa_z[i] - ta1_x_xxyy_yyyyy_1[i] * pc_z[i];

        ta1_x_xxyyz_yyyyz_0[i] = ta1_x_xxyy_yyyy_0[i] * fe_0 - ta1_x_xxyy_yyyy_1[i] * fe_0 + ta1_x_xxyy_yyyyz_0[i] * pa_z[i] - ta1_x_xxyy_yyyyz_1[i] * pc_z[i];

        ta1_x_xxyyz_yyyzz_0[i] = 2.0 * ta1_x_xxyy_yyyz_0[i] * fe_0 - 2.0 * ta1_x_xxyy_yyyz_1[i] * fe_0 + ta1_x_xxyy_yyyzz_0[i] * pa_z[i] - ta1_x_xxyy_yyyzz_1[i] * pc_z[i];

        ta1_x_xxyyz_yyzzz_0[i] = 3.0 * ta1_x_xxyy_yyzz_0[i] * fe_0 - 3.0 * ta1_x_xxyy_yyzz_1[i] * fe_0 + ta1_x_xxyy_yyzzz_0[i] * pa_z[i] - ta1_x_xxyy_yyzzz_1[i] * pc_z[i];

        ta1_x_xxyyz_yzzzz_0[i] = 4.0 * ta1_x_xxyy_yzzz_0[i] * fe_0 - 4.0 * ta1_x_xxyy_yzzz_1[i] * fe_0 + ta1_x_xxyy_yzzzz_0[i] * pa_z[i] - ta1_x_xxyy_yzzzz_1[i] * pc_z[i];

        ta1_x_xxyyz_zzzzz_0[i] = ta1_x_xxz_zzzzz_0[i] * fe_0 - ta1_x_xxz_zzzzz_1[i] * fe_0 + ta1_x_xxyz_zzzzz_0[i] * pa_y[i] - ta1_x_xxyz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 168-189 components of targeted buffer : HH

    auto ta1_x_xxyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 168);

    auto ta1_x_xxyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 169);

    auto ta1_x_xxyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 170);

    auto ta1_x_xxyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 171);

    auto ta1_x_xxyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 172);

    auto ta1_x_xxyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 173);

    auto ta1_x_xxyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 174);

    auto ta1_x_xxyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 175);

    auto ta1_x_xxyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 176);

    auto ta1_x_xxyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 177);

    auto ta1_x_xxyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 178);

    auto ta1_x_xxyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 179);

    auto ta1_x_xxyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 180);

    auto ta1_x_xxyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 181);

    auto ta1_x_xxyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 182);

    auto ta1_x_xxyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 183);

    auto ta1_x_xxyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 184);

    auto ta1_x_xxyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 185);

    auto ta1_x_xxyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 186);

    auto ta1_x_xxyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 187);

    auto ta1_x_xxyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 188);

    #pragma omp simd aligned(pa_y, pc_y, ta1_x_xxyzz_xxxxx_0, ta1_x_xxyzz_xxxxy_0, ta1_x_xxyzz_xxxxz_0, ta1_x_xxyzz_xxxyy_0, ta1_x_xxyzz_xxxyz_0, ta1_x_xxyzz_xxxzz_0, ta1_x_xxyzz_xxyyy_0, ta1_x_xxyzz_xxyyz_0, ta1_x_xxyzz_xxyzz_0, ta1_x_xxyzz_xxzzz_0, ta1_x_xxyzz_xyyyy_0, ta1_x_xxyzz_xyyyz_0, ta1_x_xxyzz_xyyzz_0, ta1_x_xxyzz_xyzzz_0, ta1_x_xxyzz_xzzzz_0, ta1_x_xxyzz_yyyyy_0, ta1_x_xxyzz_yyyyz_0, ta1_x_xxyzz_yyyzz_0, ta1_x_xxyzz_yyzzz_0, ta1_x_xxyzz_yzzzz_0, ta1_x_xxyzz_zzzzz_0, ta1_x_xxzz_xxxx_0, ta1_x_xxzz_xxxx_1, ta1_x_xxzz_xxxxx_0, ta1_x_xxzz_xxxxx_1, ta1_x_xxzz_xxxxy_0, ta1_x_xxzz_xxxxy_1, ta1_x_xxzz_xxxxz_0, ta1_x_xxzz_xxxxz_1, ta1_x_xxzz_xxxy_0, ta1_x_xxzz_xxxy_1, ta1_x_xxzz_xxxyy_0, ta1_x_xxzz_xxxyy_1, ta1_x_xxzz_xxxyz_0, ta1_x_xxzz_xxxyz_1, ta1_x_xxzz_xxxz_0, ta1_x_xxzz_xxxz_1, ta1_x_xxzz_xxxzz_0, ta1_x_xxzz_xxxzz_1, ta1_x_xxzz_xxyy_0, ta1_x_xxzz_xxyy_1, ta1_x_xxzz_xxyyy_0, ta1_x_xxzz_xxyyy_1, ta1_x_xxzz_xxyyz_0, ta1_x_xxzz_xxyyz_1, ta1_x_xxzz_xxyz_0, ta1_x_xxzz_xxyz_1, ta1_x_xxzz_xxyzz_0, ta1_x_xxzz_xxyzz_1, ta1_x_xxzz_xxzz_0, ta1_x_xxzz_xxzz_1, ta1_x_xxzz_xxzzz_0, ta1_x_xxzz_xxzzz_1, ta1_x_xxzz_xyyy_0, ta1_x_xxzz_xyyy_1, ta1_x_xxzz_xyyyy_0, ta1_x_xxzz_xyyyy_1, ta1_x_xxzz_xyyyz_0, ta1_x_xxzz_xyyyz_1, ta1_x_xxzz_xyyz_0, ta1_x_xxzz_xyyz_1, ta1_x_xxzz_xyyzz_0, ta1_x_xxzz_xyyzz_1, ta1_x_xxzz_xyzz_0, ta1_x_xxzz_xyzz_1, ta1_x_xxzz_xyzzz_0, ta1_x_xxzz_xyzzz_1, ta1_x_xxzz_xzzz_0, ta1_x_xxzz_xzzz_1, ta1_x_xxzz_xzzzz_0, ta1_x_xxzz_xzzzz_1, ta1_x_xxzz_yyyy_0, ta1_x_xxzz_yyyy_1, ta1_x_xxzz_yyyyy_0, ta1_x_xxzz_yyyyy_1, ta1_x_xxzz_yyyyz_0, ta1_x_xxzz_yyyyz_1, ta1_x_xxzz_yyyz_0, ta1_x_xxzz_yyyz_1, ta1_x_xxzz_yyyzz_0, ta1_x_xxzz_yyyzz_1, ta1_x_xxzz_yyzz_0, ta1_x_xxzz_yyzz_1, ta1_x_xxzz_yyzzz_0, ta1_x_xxzz_yyzzz_1, ta1_x_xxzz_yzzz_0, ta1_x_xxzz_yzzz_1, ta1_x_xxzz_yzzzz_0, ta1_x_xxzz_yzzzz_1, ta1_x_xxzz_zzzz_0, ta1_x_xxzz_zzzz_1, ta1_x_xxzz_zzzzz_0, ta1_x_xxzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxyzz_xxxxx_0[i] = ta1_x_xxzz_xxxxx_0[i] * pa_y[i] - ta1_x_xxzz_xxxxx_1[i] * pc_y[i];

        ta1_x_xxyzz_xxxxy_0[i] = ta1_x_xxzz_xxxx_0[i] * fe_0 - ta1_x_xxzz_xxxx_1[i] * fe_0 + ta1_x_xxzz_xxxxy_0[i] * pa_y[i] - ta1_x_xxzz_xxxxy_1[i] * pc_y[i];

        ta1_x_xxyzz_xxxxz_0[i] = ta1_x_xxzz_xxxxz_0[i] * pa_y[i] - ta1_x_xxzz_xxxxz_1[i] * pc_y[i];

        ta1_x_xxyzz_xxxyy_0[i] = 2.0 * ta1_x_xxzz_xxxy_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xxxy_1[i] * fe_0 + ta1_x_xxzz_xxxyy_0[i] * pa_y[i] - ta1_x_xxzz_xxxyy_1[i] * pc_y[i];

        ta1_x_xxyzz_xxxyz_0[i] = ta1_x_xxzz_xxxz_0[i] * fe_0 - ta1_x_xxzz_xxxz_1[i] * fe_0 + ta1_x_xxzz_xxxyz_0[i] * pa_y[i] - ta1_x_xxzz_xxxyz_1[i] * pc_y[i];

        ta1_x_xxyzz_xxxzz_0[i] = ta1_x_xxzz_xxxzz_0[i] * pa_y[i] - ta1_x_xxzz_xxxzz_1[i] * pc_y[i];

        ta1_x_xxyzz_xxyyy_0[i] = 3.0 * ta1_x_xxzz_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xxzz_xxyy_1[i] * fe_0 + ta1_x_xxzz_xxyyy_0[i] * pa_y[i] - ta1_x_xxzz_xxyyy_1[i] * pc_y[i];

        ta1_x_xxyzz_xxyyz_0[i] = 2.0 * ta1_x_xxzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xxyz_1[i] * fe_0 + ta1_x_xxzz_xxyyz_0[i] * pa_y[i] - ta1_x_xxzz_xxyyz_1[i] * pc_y[i];

        ta1_x_xxyzz_xxyzz_0[i] = ta1_x_xxzz_xxzz_0[i] * fe_0 - ta1_x_xxzz_xxzz_1[i] * fe_0 + ta1_x_xxzz_xxyzz_0[i] * pa_y[i] - ta1_x_xxzz_xxyzz_1[i] * pc_y[i];

        ta1_x_xxyzz_xxzzz_0[i] = ta1_x_xxzz_xxzzz_0[i] * pa_y[i] - ta1_x_xxzz_xxzzz_1[i] * pc_y[i];

        ta1_x_xxyzz_xyyyy_0[i] = 4.0 * ta1_x_xxzz_xyyy_0[i] * fe_0 - 4.0 * ta1_x_xxzz_xyyy_1[i] * fe_0 + ta1_x_xxzz_xyyyy_0[i] * pa_y[i] - ta1_x_xxzz_xyyyy_1[i] * pc_y[i];

        ta1_x_xxyzz_xyyyz_0[i] = 3.0 * ta1_x_xxzz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xxzz_xyyz_1[i] * fe_0 + ta1_x_xxzz_xyyyz_0[i] * pa_y[i] - ta1_x_xxzz_xyyyz_1[i] * pc_y[i];

        ta1_x_xxyzz_xyyzz_0[i] = 2.0 * ta1_x_xxzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xyzz_1[i] * fe_0 + ta1_x_xxzz_xyyzz_0[i] * pa_y[i] - ta1_x_xxzz_xyyzz_1[i] * pc_y[i];

        ta1_x_xxyzz_xyzzz_0[i] = ta1_x_xxzz_xzzz_0[i] * fe_0 - ta1_x_xxzz_xzzz_1[i] * fe_0 + ta1_x_xxzz_xyzzz_0[i] * pa_y[i] - ta1_x_xxzz_xyzzz_1[i] * pc_y[i];

        ta1_x_xxyzz_xzzzz_0[i] = ta1_x_xxzz_xzzzz_0[i] * pa_y[i] - ta1_x_xxzz_xzzzz_1[i] * pc_y[i];

        ta1_x_xxyzz_yyyyy_0[i] = 5.0 * ta1_x_xxzz_yyyy_0[i] * fe_0 - 5.0 * ta1_x_xxzz_yyyy_1[i] * fe_0 + ta1_x_xxzz_yyyyy_0[i] * pa_y[i] - ta1_x_xxzz_yyyyy_1[i] * pc_y[i];

        ta1_x_xxyzz_yyyyz_0[i] = 4.0 * ta1_x_xxzz_yyyz_0[i] * fe_0 - 4.0 * ta1_x_xxzz_yyyz_1[i] * fe_0 + ta1_x_xxzz_yyyyz_0[i] * pa_y[i] - ta1_x_xxzz_yyyyz_1[i] * pc_y[i];

        ta1_x_xxyzz_yyyzz_0[i] = 3.0 * ta1_x_xxzz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_xxzz_yyzz_1[i] * fe_0 + ta1_x_xxzz_yyyzz_0[i] * pa_y[i] - ta1_x_xxzz_yyyzz_1[i] * pc_y[i];

        ta1_x_xxyzz_yyzzz_0[i] = 2.0 * ta1_x_xxzz_yzzz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_yzzz_1[i] * fe_0 + ta1_x_xxzz_yyzzz_0[i] * pa_y[i] - ta1_x_xxzz_yyzzz_1[i] * pc_y[i];

        ta1_x_xxyzz_yzzzz_0[i] = ta1_x_xxzz_zzzz_0[i] * fe_0 - ta1_x_xxzz_zzzz_1[i] * fe_0 + ta1_x_xxzz_yzzzz_0[i] * pa_y[i] - ta1_x_xxzz_yzzzz_1[i] * pc_y[i];

        ta1_x_xxyzz_zzzzz_0[i] = ta1_x_xxzz_zzzzz_0[i] * pa_y[i] - ta1_x_xxzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 189-210 components of targeted buffer : HH

    auto ta1_x_xxzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 189);

    auto ta1_x_xxzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 190);

    auto ta1_x_xxzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 191);

    auto ta1_x_xxzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 192);

    auto ta1_x_xxzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 193);

    auto ta1_x_xxzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 194);

    auto ta1_x_xxzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 195);

    auto ta1_x_xxzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 196);

    auto ta1_x_xxzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 197);

    auto ta1_x_xxzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 198);

    auto ta1_x_xxzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 199);

    auto ta1_x_xxzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 200);

    auto ta1_x_xxzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 201);

    auto ta1_x_xxzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 202);

    auto ta1_x_xxzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 203);

    auto ta1_x_xxzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 204);

    auto ta1_x_xxzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 205);

    auto ta1_x_xxzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 206);

    auto ta1_x_xxzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 207);

    auto ta1_x_xxzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 208);

    auto ta1_x_xxzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 209);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_x_xxz_xxxxx_0, ta1_x_xxz_xxxxx_1, ta1_x_xxz_xxxxy_0, ta1_x_xxz_xxxxy_1, ta1_x_xxz_xxxxz_0, ta1_x_xxz_xxxxz_1, ta1_x_xxz_xxxyy_0, ta1_x_xxz_xxxyy_1, ta1_x_xxz_xxxyz_0, ta1_x_xxz_xxxyz_1, ta1_x_xxz_xxxzz_0, ta1_x_xxz_xxxzz_1, ta1_x_xxz_xxyyy_0, ta1_x_xxz_xxyyy_1, ta1_x_xxz_xxyyz_0, ta1_x_xxz_xxyyz_1, ta1_x_xxz_xxyzz_0, ta1_x_xxz_xxyzz_1, ta1_x_xxz_xxzzz_0, ta1_x_xxz_xxzzz_1, ta1_x_xxz_xyyyy_0, ta1_x_xxz_xyyyy_1, ta1_x_xxz_xyyyz_0, ta1_x_xxz_xyyyz_1, ta1_x_xxz_xyyzz_0, ta1_x_xxz_xyyzz_1, ta1_x_xxz_xyzzz_0, ta1_x_xxz_xyzzz_1, ta1_x_xxz_xzzzz_0, ta1_x_xxz_xzzzz_1, ta1_x_xxz_yyyyy_0, ta1_x_xxz_yyyyy_1, ta1_x_xxzz_xxxx_0, ta1_x_xxzz_xxxx_1, ta1_x_xxzz_xxxxx_0, ta1_x_xxzz_xxxxx_1, ta1_x_xxzz_xxxxy_0, ta1_x_xxzz_xxxxy_1, ta1_x_xxzz_xxxxz_0, ta1_x_xxzz_xxxxz_1, ta1_x_xxzz_xxxy_0, ta1_x_xxzz_xxxy_1, ta1_x_xxzz_xxxyy_0, ta1_x_xxzz_xxxyy_1, ta1_x_xxzz_xxxyz_0, ta1_x_xxzz_xxxyz_1, ta1_x_xxzz_xxxz_0, ta1_x_xxzz_xxxz_1, ta1_x_xxzz_xxxzz_0, ta1_x_xxzz_xxxzz_1, ta1_x_xxzz_xxyy_0, ta1_x_xxzz_xxyy_1, ta1_x_xxzz_xxyyy_0, ta1_x_xxzz_xxyyy_1, ta1_x_xxzz_xxyyz_0, ta1_x_xxzz_xxyyz_1, ta1_x_xxzz_xxyz_0, ta1_x_xxzz_xxyz_1, ta1_x_xxzz_xxyzz_0, ta1_x_xxzz_xxyzz_1, ta1_x_xxzz_xxzz_0, ta1_x_xxzz_xxzz_1, ta1_x_xxzz_xxzzz_0, ta1_x_xxzz_xxzzz_1, ta1_x_xxzz_xyyy_0, ta1_x_xxzz_xyyy_1, ta1_x_xxzz_xyyyy_0, ta1_x_xxzz_xyyyy_1, ta1_x_xxzz_xyyyz_0, ta1_x_xxzz_xyyyz_1, ta1_x_xxzz_xyyz_0, ta1_x_xxzz_xyyz_1, ta1_x_xxzz_xyyzz_0, ta1_x_xxzz_xyyzz_1, ta1_x_xxzz_xyzz_0, ta1_x_xxzz_xyzz_1, ta1_x_xxzz_xyzzz_0, ta1_x_xxzz_xyzzz_1, ta1_x_xxzz_xzzz_0, ta1_x_xxzz_xzzz_1, ta1_x_xxzz_xzzzz_0, ta1_x_xxzz_xzzzz_1, ta1_x_xxzz_yyyyy_0, ta1_x_xxzz_yyyyy_1, ta1_x_xxzzz_xxxxx_0, ta1_x_xxzzz_xxxxy_0, ta1_x_xxzzz_xxxxz_0, ta1_x_xxzzz_xxxyy_0, ta1_x_xxzzz_xxxyz_0, ta1_x_xxzzz_xxxzz_0, ta1_x_xxzzz_xxyyy_0, ta1_x_xxzzz_xxyyz_0, ta1_x_xxzzz_xxyzz_0, ta1_x_xxzzz_xxzzz_0, ta1_x_xxzzz_xyyyy_0, ta1_x_xxzzz_xyyyz_0, ta1_x_xxzzz_xyyzz_0, ta1_x_xxzzz_xyzzz_0, ta1_x_xxzzz_xzzzz_0, ta1_x_xxzzz_yyyyy_0, ta1_x_xxzzz_yyyyz_0, ta1_x_xxzzz_yyyzz_0, ta1_x_xxzzz_yyzzz_0, ta1_x_xxzzz_yzzzz_0, ta1_x_xxzzz_zzzzz_0, ta1_x_xzzz_yyyyz_0, ta1_x_xzzz_yyyyz_1, ta1_x_xzzz_yyyzz_0, ta1_x_xzzz_yyyzz_1, ta1_x_xzzz_yyzzz_0, ta1_x_xzzz_yyzzz_1, ta1_x_xzzz_yzzzz_0, ta1_x_xzzz_yzzzz_1, ta1_x_xzzz_zzzzz_0, ta1_x_xzzz_zzzzz_1, ta1_x_zzz_yyyyz_0, ta1_x_zzz_yyyyz_1, ta1_x_zzz_yyyzz_0, ta1_x_zzz_yyyzz_1, ta1_x_zzz_yyzzz_0, ta1_x_zzz_yyzzz_1, ta1_x_zzz_yzzzz_0, ta1_x_zzz_yzzzz_1, ta1_x_zzz_zzzzz_0, ta1_x_zzz_zzzzz_1, ta_xzzz_yyyyz_1, ta_xzzz_yyyzz_1, ta_xzzz_yyzzz_1, ta_xzzz_yzzzz_1, ta_xzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xxzzz_xxxxx_0[i] = 2.0 * ta1_x_xxz_xxxxx_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxxx_1[i] * fe_0 + ta1_x_xxzz_xxxxx_0[i] * pa_z[i] - ta1_x_xxzz_xxxxx_1[i] * pc_z[i];

        ta1_x_xxzzz_xxxxy_0[i] = 2.0 * ta1_x_xxz_xxxxy_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxxy_1[i] * fe_0 + ta1_x_xxzz_xxxxy_0[i] * pa_z[i] - ta1_x_xxzz_xxxxy_1[i] * pc_z[i];

        ta1_x_xxzzz_xxxxz_0[i] = 2.0 * ta1_x_xxz_xxxxz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxxz_1[i] * fe_0 + ta1_x_xxzz_xxxx_0[i] * fe_0 - ta1_x_xxzz_xxxx_1[i] * fe_0 + ta1_x_xxzz_xxxxz_0[i] * pa_z[i] - ta1_x_xxzz_xxxxz_1[i] * pc_z[i];

        ta1_x_xxzzz_xxxyy_0[i] = 2.0 * ta1_x_xxz_xxxyy_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxyy_1[i] * fe_0 + ta1_x_xxzz_xxxyy_0[i] * pa_z[i] - ta1_x_xxzz_xxxyy_1[i] * pc_z[i];

        ta1_x_xxzzz_xxxyz_0[i] = 2.0 * ta1_x_xxz_xxxyz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxyz_1[i] * fe_0 + ta1_x_xxzz_xxxy_0[i] * fe_0 - ta1_x_xxzz_xxxy_1[i] * fe_0 + ta1_x_xxzz_xxxyz_0[i] * pa_z[i] - ta1_x_xxzz_xxxyz_1[i] * pc_z[i];

        ta1_x_xxzzz_xxxzz_0[i] = 2.0 * ta1_x_xxz_xxxzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxxzz_1[i] * fe_0 + 2.0 * ta1_x_xxzz_xxxz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xxxz_1[i] * fe_0 + ta1_x_xxzz_xxxzz_0[i] * pa_z[i] - ta1_x_xxzz_xxxzz_1[i] * pc_z[i];

        ta1_x_xxzzz_xxyyy_0[i] = 2.0 * ta1_x_xxz_xxyyy_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxyyy_1[i] * fe_0 + ta1_x_xxzz_xxyyy_0[i] * pa_z[i] - ta1_x_xxzz_xxyyy_1[i] * pc_z[i];

        ta1_x_xxzzz_xxyyz_0[i] = 2.0 * ta1_x_xxz_xxyyz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxyyz_1[i] * fe_0 + ta1_x_xxzz_xxyy_0[i] * fe_0 - ta1_x_xxzz_xxyy_1[i] * fe_0 + ta1_x_xxzz_xxyyz_0[i] * pa_z[i] - ta1_x_xxzz_xxyyz_1[i] * pc_z[i];

        ta1_x_xxzzz_xxyzz_0[i] = 2.0 * ta1_x_xxz_xxyzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxyzz_1[i] * fe_0 + 2.0 * ta1_x_xxzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xxyz_1[i] * fe_0 + ta1_x_xxzz_xxyzz_0[i] * pa_z[i] - ta1_x_xxzz_xxyzz_1[i] * pc_z[i];

        ta1_x_xxzzz_xxzzz_0[i] = 2.0 * ta1_x_xxz_xxzzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xxzzz_1[i] * fe_0 + 3.0 * ta1_x_xxzz_xxzz_0[i] * fe_0 - 3.0 * ta1_x_xxzz_xxzz_1[i] * fe_0 + ta1_x_xxzz_xxzzz_0[i] * pa_z[i] - ta1_x_xxzz_xxzzz_1[i] * pc_z[i];

        ta1_x_xxzzz_xyyyy_0[i] = 2.0 * ta1_x_xxz_xyyyy_0[i] * fe_0 - 2.0 * ta1_x_xxz_xyyyy_1[i] * fe_0 + ta1_x_xxzz_xyyyy_0[i] * pa_z[i] - ta1_x_xxzz_xyyyy_1[i] * pc_z[i];

        ta1_x_xxzzz_xyyyz_0[i] = 2.0 * ta1_x_xxz_xyyyz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xyyyz_1[i] * fe_0 + ta1_x_xxzz_xyyy_0[i] * fe_0 - ta1_x_xxzz_xyyy_1[i] * fe_0 + ta1_x_xxzz_xyyyz_0[i] * pa_z[i] - ta1_x_xxzz_xyyyz_1[i] * pc_z[i];

        ta1_x_xxzzz_xyyzz_0[i] = 2.0 * ta1_x_xxz_xyyzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_xxzz_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xxzz_xyyz_1[i] * fe_0 + ta1_x_xxzz_xyyzz_0[i] * pa_z[i] - ta1_x_xxzz_xyyzz_1[i] * pc_z[i];

        ta1_x_xxzzz_xyzzz_0[i] = 2.0 * ta1_x_xxz_xyzzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xyzzz_1[i] * fe_0 + 3.0 * ta1_x_xxzz_xyzz_0[i] * fe_0 - 3.0 * ta1_x_xxzz_xyzz_1[i] * fe_0 + ta1_x_xxzz_xyzzz_0[i] * pa_z[i] - ta1_x_xxzz_xyzzz_1[i] * pc_z[i];

        ta1_x_xxzzz_xzzzz_0[i] = 2.0 * ta1_x_xxz_xzzzz_0[i] * fe_0 - 2.0 * ta1_x_xxz_xzzzz_1[i] * fe_0 + 4.0 * ta1_x_xxzz_xzzz_0[i] * fe_0 - 4.0 * ta1_x_xxzz_xzzz_1[i] * fe_0 + ta1_x_xxzz_xzzzz_0[i] * pa_z[i] - ta1_x_xxzz_xzzzz_1[i] * pc_z[i];

        ta1_x_xxzzz_yyyyy_0[i] = 2.0 * ta1_x_xxz_yyyyy_0[i] * fe_0 - 2.0 * ta1_x_xxz_yyyyy_1[i] * fe_0 + ta1_x_xxzz_yyyyy_0[i] * pa_z[i] - ta1_x_xxzz_yyyyy_1[i] * pc_z[i];

        ta1_x_xxzzz_yyyyz_0[i] = ta1_x_zzz_yyyyz_0[i] * fe_0 - ta1_x_zzz_yyyyz_1[i] * fe_0 + ta_xzzz_yyyyz_1[i] + ta1_x_xzzz_yyyyz_0[i] * pa_x[i] - ta1_x_xzzz_yyyyz_1[i] * pc_x[i];

        ta1_x_xxzzz_yyyzz_0[i] = ta1_x_zzz_yyyzz_0[i] * fe_0 - ta1_x_zzz_yyyzz_1[i] * fe_0 + ta_xzzz_yyyzz_1[i] + ta1_x_xzzz_yyyzz_0[i] * pa_x[i] - ta1_x_xzzz_yyyzz_1[i] * pc_x[i];

        ta1_x_xxzzz_yyzzz_0[i] = ta1_x_zzz_yyzzz_0[i] * fe_0 - ta1_x_zzz_yyzzz_1[i] * fe_0 + ta_xzzz_yyzzz_1[i] + ta1_x_xzzz_yyzzz_0[i] * pa_x[i] - ta1_x_xzzz_yyzzz_1[i] * pc_x[i];

        ta1_x_xxzzz_yzzzz_0[i] = ta1_x_zzz_yzzzz_0[i] * fe_0 - ta1_x_zzz_yzzzz_1[i] * fe_0 + ta_xzzz_yzzzz_1[i] + ta1_x_xzzz_yzzzz_0[i] * pa_x[i] - ta1_x_xzzz_yzzzz_1[i] * pc_x[i];

        ta1_x_xxzzz_zzzzz_0[i] = ta1_x_zzz_zzzzz_0[i] * fe_0 - ta1_x_zzz_zzzzz_1[i] * fe_0 + ta_xzzz_zzzzz_1[i] + ta1_x_xzzz_zzzzz_0[i] * pa_x[i] - ta1_x_xzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 210-231 components of targeted buffer : HH

    auto ta1_x_xyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 210);

    auto ta1_x_xyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 211);

    auto ta1_x_xyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 212);

    auto ta1_x_xyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 213);

    auto ta1_x_xyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 214);

    auto ta1_x_xyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 215);

    auto ta1_x_xyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 216);

    auto ta1_x_xyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 217);

    auto ta1_x_xyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 218);

    auto ta1_x_xyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 219);

    auto ta1_x_xyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 220);

    auto ta1_x_xyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 221);

    auto ta1_x_xyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 222);

    auto ta1_x_xyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 223);

    auto ta1_x_xyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 224);

    auto ta1_x_xyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 225);

    auto ta1_x_xyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 226);

    auto ta1_x_xyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 227);

    auto ta1_x_xyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 228);

    auto ta1_x_xyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 229);

    auto ta1_x_xyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 230);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_x_xyy_xxxxx_0, ta1_x_xyy_xxxxx_1, ta1_x_xyy_xxxxz_0, ta1_x_xyy_xxxxz_1, ta1_x_xyy_xxxzz_0, ta1_x_xyy_xxxzz_1, ta1_x_xyy_xxzzz_0, ta1_x_xyy_xxzzz_1, ta1_x_xyy_xzzzz_0, ta1_x_xyy_xzzzz_1, ta1_x_xyyy_xxxxx_0, ta1_x_xyyy_xxxxx_1, ta1_x_xyyy_xxxxz_0, ta1_x_xyyy_xxxxz_1, ta1_x_xyyy_xxxzz_0, ta1_x_xyyy_xxxzz_1, ta1_x_xyyy_xxzzz_0, ta1_x_xyyy_xxzzz_1, ta1_x_xyyy_xzzzz_0, ta1_x_xyyy_xzzzz_1, ta1_x_xyyyy_xxxxx_0, ta1_x_xyyyy_xxxxy_0, ta1_x_xyyyy_xxxxz_0, ta1_x_xyyyy_xxxyy_0, ta1_x_xyyyy_xxxyz_0, ta1_x_xyyyy_xxxzz_0, ta1_x_xyyyy_xxyyy_0, ta1_x_xyyyy_xxyyz_0, ta1_x_xyyyy_xxyzz_0, ta1_x_xyyyy_xxzzz_0, ta1_x_xyyyy_xyyyy_0, ta1_x_xyyyy_xyyyz_0, ta1_x_xyyyy_xyyzz_0, ta1_x_xyyyy_xyzzz_0, ta1_x_xyyyy_xzzzz_0, ta1_x_xyyyy_yyyyy_0, ta1_x_xyyyy_yyyyz_0, ta1_x_xyyyy_yyyzz_0, ta1_x_xyyyy_yyzzz_0, ta1_x_xyyyy_yzzzz_0, ta1_x_xyyyy_zzzzz_0, ta1_x_yyyy_xxxxy_0, ta1_x_yyyy_xxxxy_1, ta1_x_yyyy_xxxy_0, ta1_x_yyyy_xxxy_1, ta1_x_yyyy_xxxyy_0, ta1_x_yyyy_xxxyy_1, ta1_x_yyyy_xxxyz_0, ta1_x_yyyy_xxxyz_1, ta1_x_yyyy_xxyy_0, ta1_x_yyyy_xxyy_1, ta1_x_yyyy_xxyyy_0, ta1_x_yyyy_xxyyy_1, ta1_x_yyyy_xxyyz_0, ta1_x_yyyy_xxyyz_1, ta1_x_yyyy_xxyz_0, ta1_x_yyyy_xxyz_1, ta1_x_yyyy_xxyzz_0, ta1_x_yyyy_xxyzz_1, ta1_x_yyyy_xyyy_0, ta1_x_yyyy_xyyy_1, ta1_x_yyyy_xyyyy_0, ta1_x_yyyy_xyyyy_1, ta1_x_yyyy_xyyyz_0, ta1_x_yyyy_xyyyz_1, ta1_x_yyyy_xyyz_0, ta1_x_yyyy_xyyz_1, ta1_x_yyyy_xyyzz_0, ta1_x_yyyy_xyyzz_1, ta1_x_yyyy_xyzz_0, ta1_x_yyyy_xyzz_1, ta1_x_yyyy_xyzzz_0, ta1_x_yyyy_xyzzz_1, ta1_x_yyyy_yyyy_0, ta1_x_yyyy_yyyy_1, ta1_x_yyyy_yyyyy_0, ta1_x_yyyy_yyyyy_1, ta1_x_yyyy_yyyyz_0, ta1_x_yyyy_yyyyz_1, ta1_x_yyyy_yyyz_0, ta1_x_yyyy_yyyz_1, ta1_x_yyyy_yyyzz_0, ta1_x_yyyy_yyyzz_1, ta1_x_yyyy_yyzz_0, ta1_x_yyyy_yyzz_1, ta1_x_yyyy_yyzzz_0, ta1_x_yyyy_yyzzz_1, ta1_x_yyyy_yzzz_0, ta1_x_yyyy_yzzz_1, ta1_x_yyyy_yzzzz_0, ta1_x_yyyy_yzzzz_1, ta1_x_yyyy_zzzzz_0, ta1_x_yyyy_zzzzz_1, ta_yyyy_xxxxy_1, ta_yyyy_xxxyy_1, ta_yyyy_xxxyz_1, ta_yyyy_xxyyy_1, ta_yyyy_xxyyz_1, ta_yyyy_xxyzz_1, ta_yyyy_xyyyy_1, ta_yyyy_xyyyz_1, ta_yyyy_xyyzz_1, ta_yyyy_xyzzz_1, ta_yyyy_yyyyy_1, ta_yyyy_yyyyz_1, ta_yyyy_yyyzz_1, ta_yyyy_yyzzz_1, ta_yyyy_yzzzz_1, ta_yyyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xyyyy_xxxxx_0[i] = 3.0 * ta1_x_xyy_xxxxx_0[i] * fe_0 - 3.0 * ta1_x_xyy_xxxxx_1[i] * fe_0 + ta1_x_xyyy_xxxxx_0[i] * pa_y[i] - ta1_x_xyyy_xxxxx_1[i] * pc_y[i];

        ta1_x_xyyyy_xxxxy_0[i] = 4.0 * ta1_x_yyyy_xxxy_0[i] * fe_0 - 4.0 * ta1_x_yyyy_xxxy_1[i] * fe_0 + ta_yyyy_xxxxy_1[i] + ta1_x_yyyy_xxxxy_0[i] * pa_x[i] - ta1_x_yyyy_xxxxy_1[i] * pc_x[i];

        ta1_x_xyyyy_xxxxz_0[i] = 3.0 * ta1_x_xyy_xxxxz_0[i] * fe_0 - 3.0 * ta1_x_xyy_xxxxz_1[i] * fe_0 + ta1_x_xyyy_xxxxz_0[i] * pa_y[i] - ta1_x_xyyy_xxxxz_1[i] * pc_y[i];

        ta1_x_xyyyy_xxxyy_0[i] = 3.0 * ta1_x_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_x_yyyy_xxyy_1[i] * fe_0 + ta_yyyy_xxxyy_1[i] + ta1_x_yyyy_xxxyy_0[i] * pa_x[i] - ta1_x_yyyy_xxxyy_1[i] * pc_x[i];

        ta1_x_xyyyy_xxxyz_0[i] = 3.0 * ta1_x_yyyy_xxyz_0[i] * fe_0 - 3.0 * ta1_x_yyyy_xxyz_1[i] * fe_0 + ta_yyyy_xxxyz_1[i] + ta1_x_yyyy_xxxyz_0[i] * pa_x[i] - ta1_x_yyyy_xxxyz_1[i] * pc_x[i];

        ta1_x_xyyyy_xxxzz_0[i] = 3.0 * ta1_x_xyy_xxxzz_0[i] * fe_0 - 3.0 * ta1_x_xyy_xxxzz_1[i] * fe_0 + ta1_x_xyyy_xxxzz_0[i] * pa_y[i] - ta1_x_xyyy_xxxzz_1[i] * pc_y[i];

        ta1_x_xyyyy_xxyyy_0[i] = 2.0 * ta1_x_yyyy_xyyy_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xyyy_1[i] * fe_0 + ta_yyyy_xxyyy_1[i] + ta1_x_yyyy_xxyyy_0[i] * pa_x[i] - ta1_x_yyyy_xxyyy_1[i] * pc_x[i];

        ta1_x_xyyyy_xxyyz_0[i] = 2.0 * ta1_x_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xyyz_1[i] * fe_0 + ta_yyyy_xxyyz_1[i] + ta1_x_yyyy_xxyyz_0[i] * pa_x[i] - ta1_x_yyyy_xxyyz_1[i] * pc_x[i];

        ta1_x_xyyyy_xxyzz_0[i] = 2.0 * ta1_x_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xyzz_1[i] * fe_0 + ta_yyyy_xxyzz_1[i] + ta1_x_yyyy_xxyzz_0[i] * pa_x[i] - ta1_x_yyyy_xxyzz_1[i] * pc_x[i];

        ta1_x_xyyyy_xxzzz_0[i] = 3.0 * ta1_x_xyy_xxzzz_0[i] * fe_0 - 3.0 * ta1_x_xyy_xxzzz_1[i] * fe_0 + ta1_x_xyyy_xxzzz_0[i] * pa_y[i] - ta1_x_xyyy_xxzzz_1[i] * pc_y[i];

        ta1_x_xyyyy_xyyyy_0[i] = ta1_x_yyyy_yyyy_0[i] * fe_0 - ta1_x_yyyy_yyyy_1[i] * fe_0 + ta_yyyy_xyyyy_1[i] + ta1_x_yyyy_xyyyy_0[i] * pa_x[i] - ta1_x_yyyy_xyyyy_1[i] * pc_x[i];

        ta1_x_xyyyy_xyyyz_0[i] = ta1_x_yyyy_yyyz_0[i] * fe_0 - ta1_x_yyyy_yyyz_1[i] * fe_0 + ta_yyyy_xyyyz_1[i] + ta1_x_yyyy_xyyyz_0[i] * pa_x[i] - ta1_x_yyyy_xyyyz_1[i] * pc_x[i];

        ta1_x_xyyyy_xyyzz_0[i] = ta1_x_yyyy_yyzz_0[i] * fe_0 - ta1_x_yyyy_yyzz_1[i] * fe_0 + ta_yyyy_xyyzz_1[i] + ta1_x_yyyy_xyyzz_0[i] * pa_x[i] - ta1_x_yyyy_xyyzz_1[i] * pc_x[i];

        ta1_x_xyyyy_xyzzz_0[i] = ta1_x_yyyy_yzzz_0[i] * fe_0 - ta1_x_yyyy_yzzz_1[i] * fe_0 + ta_yyyy_xyzzz_1[i] + ta1_x_yyyy_xyzzz_0[i] * pa_x[i] - ta1_x_yyyy_xyzzz_1[i] * pc_x[i];

        ta1_x_xyyyy_xzzzz_0[i] = 3.0 * ta1_x_xyy_xzzzz_0[i] * fe_0 - 3.0 * ta1_x_xyy_xzzzz_1[i] * fe_0 + ta1_x_xyyy_xzzzz_0[i] * pa_y[i] - ta1_x_xyyy_xzzzz_1[i] * pc_y[i];

        ta1_x_xyyyy_yyyyy_0[i] = ta_yyyy_yyyyy_1[i] + ta1_x_yyyy_yyyyy_0[i] * pa_x[i] - ta1_x_yyyy_yyyyy_1[i] * pc_x[i];

        ta1_x_xyyyy_yyyyz_0[i] = ta_yyyy_yyyyz_1[i] + ta1_x_yyyy_yyyyz_0[i] * pa_x[i] - ta1_x_yyyy_yyyyz_1[i] * pc_x[i];

        ta1_x_xyyyy_yyyzz_0[i] = ta_yyyy_yyyzz_1[i] + ta1_x_yyyy_yyyzz_0[i] * pa_x[i] - ta1_x_yyyy_yyyzz_1[i] * pc_x[i];

        ta1_x_xyyyy_yyzzz_0[i] = ta_yyyy_yyzzz_1[i] + ta1_x_yyyy_yyzzz_0[i] * pa_x[i] - ta1_x_yyyy_yyzzz_1[i] * pc_x[i];

        ta1_x_xyyyy_yzzzz_0[i] = ta_yyyy_yzzzz_1[i] + ta1_x_yyyy_yzzzz_0[i] * pa_x[i] - ta1_x_yyyy_yzzzz_1[i] * pc_x[i];

        ta1_x_xyyyy_zzzzz_0[i] = ta_yyyy_zzzzz_1[i] + ta1_x_yyyy_zzzzz_0[i] * pa_x[i] - ta1_x_yyyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 231-252 components of targeted buffer : HH

    auto ta1_x_xyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 231);

    auto ta1_x_xyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 232);

    auto ta1_x_xyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 233);

    auto ta1_x_xyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 234);

    auto ta1_x_xyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 235);

    auto ta1_x_xyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 236);

    auto ta1_x_xyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 237);

    auto ta1_x_xyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 238);

    auto ta1_x_xyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 239);

    auto ta1_x_xyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 240);

    auto ta1_x_xyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 241);

    auto ta1_x_xyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 242);

    auto ta1_x_xyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 243);

    auto ta1_x_xyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 244);

    auto ta1_x_xyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 245);

    auto ta1_x_xyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 246);

    auto ta1_x_xyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 247);

    auto ta1_x_xyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 248);

    auto ta1_x_xyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 249);

    auto ta1_x_xyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 250);

    auto ta1_x_xyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 251);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_x_xyyy_xxxxx_0, ta1_x_xyyy_xxxxx_1, ta1_x_xyyy_xxxxy_0, ta1_x_xyyy_xxxxy_1, ta1_x_xyyy_xxxy_0, ta1_x_xyyy_xxxy_1, ta1_x_xyyy_xxxyy_0, ta1_x_xyyy_xxxyy_1, ta1_x_xyyy_xxxyz_0, ta1_x_xyyy_xxxyz_1, ta1_x_xyyy_xxyy_0, ta1_x_xyyy_xxyy_1, ta1_x_xyyy_xxyyy_0, ta1_x_xyyy_xxyyy_1, ta1_x_xyyy_xxyyz_0, ta1_x_xyyy_xxyyz_1, ta1_x_xyyy_xxyz_0, ta1_x_xyyy_xxyz_1, ta1_x_xyyy_xxyzz_0, ta1_x_xyyy_xxyzz_1, ta1_x_xyyy_xyyy_0, ta1_x_xyyy_xyyy_1, ta1_x_xyyy_xyyyy_0, ta1_x_xyyy_xyyyy_1, ta1_x_xyyy_xyyyz_0, ta1_x_xyyy_xyyyz_1, ta1_x_xyyy_xyyz_0, ta1_x_xyyy_xyyz_1, ta1_x_xyyy_xyyzz_0, ta1_x_xyyy_xyyzz_1, ta1_x_xyyy_xyzz_0, ta1_x_xyyy_xyzz_1, ta1_x_xyyy_xyzzz_0, ta1_x_xyyy_xyzzz_1, ta1_x_xyyy_yyyyy_0, ta1_x_xyyy_yyyyy_1, ta1_x_xyyyz_xxxxx_0, ta1_x_xyyyz_xxxxy_0, ta1_x_xyyyz_xxxxz_0, ta1_x_xyyyz_xxxyy_0, ta1_x_xyyyz_xxxyz_0, ta1_x_xyyyz_xxxzz_0, ta1_x_xyyyz_xxyyy_0, ta1_x_xyyyz_xxyyz_0, ta1_x_xyyyz_xxyzz_0, ta1_x_xyyyz_xxzzz_0, ta1_x_xyyyz_xyyyy_0, ta1_x_xyyyz_xyyyz_0, ta1_x_xyyyz_xyyzz_0, ta1_x_xyyyz_xyzzz_0, ta1_x_xyyyz_xzzzz_0, ta1_x_xyyyz_yyyyy_0, ta1_x_xyyyz_yyyyz_0, ta1_x_xyyyz_yyyzz_0, ta1_x_xyyyz_yyzzz_0, ta1_x_xyyyz_yzzzz_0, ta1_x_xyyyz_zzzzz_0, ta1_x_xyyz_xxxxz_0, ta1_x_xyyz_xxxxz_1, ta1_x_xyyz_xxxzz_0, ta1_x_xyyz_xxxzz_1, ta1_x_xyyz_xxzzz_0, ta1_x_xyyz_xxzzz_1, ta1_x_xyyz_xzzzz_0, ta1_x_xyyz_xzzzz_1, ta1_x_xyz_xxxxz_0, ta1_x_xyz_xxxxz_1, ta1_x_xyz_xxxzz_0, ta1_x_xyz_xxxzz_1, ta1_x_xyz_xxzzz_0, ta1_x_xyz_xxzzz_1, ta1_x_xyz_xzzzz_0, ta1_x_xyz_xzzzz_1, ta1_x_yyyz_yyyyz_0, ta1_x_yyyz_yyyyz_1, ta1_x_yyyz_yyyzz_0, ta1_x_yyyz_yyyzz_1, ta1_x_yyyz_yyzzz_0, ta1_x_yyyz_yyzzz_1, ta1_x_yyyz_yzzzz_0, ta1_x_yyyz_yzzzz_1, ta1_x_yyyz_zzzzz_0, ta1_x_yyyz_zzzzz_1, ta_yyyz_yyyyz_1, ta_yyyz_yyyzz_1, ta_yyyz_yyzzz_1, ta_yyyz_yzzzz_1, ta_yyyz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xyyyz_xxxxx_0[i] = ta1_x_xyyy_xxxxx_0[i] * pa_z[i] - ta1_x_xyyy_xxxxx_1[i] * pc_z[i];

        ta1_x_xyyyz_xxxxy_0[i] = ta1_x_xyyy_xxxxy_0[i] * pa_z[i] - ta1_x_xyyy_xxxxy_1[i] * pc_z[i];

        ta1_x_xyyyz_xxxxz_0[i] = 2.0 * ta1_x_xyz_xxxxz_0[i] * fe_0 - 2.0 * ta1_x_xyz_xxxxz_1[i] * fe_0 + ta1_x_xyyz_xxxxz_0[i] * pa_y[i] - ta1_x_xyyz_xxxxz_1[i] * pc_y[i];

        ta1_x_xyyyz_xxxyy_0[i] = ta1_x_xyyy_xxxyy_0[i] * pa_z[i] - ta1_x_xyyy_xxxyy_1[i] * pc_z[i];

        ta1_x_xyyyz_xxxyz_0[i] = ta1_x_xyyy_xxxy_0[i] * fe_0 - ta1_x_xyyy_xxxy_1[i] * fe_0 + ta1_x_xyyy_xxxyz_0[i] * pa_z[i] - ta1_x_xyyy_xxxyz_1[i] * pc_z[i];

        ta1_x_xyyyz_xxxzz_0[i] = 2.0 * ta1_x_xyz_xxxzz_0[i] * fe_0 - 2.0 * ta1_x_xyz_xxxzz_1[i] * fe_0 + ta1_x_xyyz_xxxzz_0[i] * pa_y[i] - ta1_x_xyyz_xxxzz_1[i] * pc_y[i];

        ta1_x_xyyyz_xxyyy_0[i] = ta1_x_xyyy_xxyyy_0[i] * pa_z[i] - ta1_x_xyyy_xxyyy_1[i] * pc_z[i];

        ta1_x_xyyyz_xxyyz_0[i] = ta1_x_xyyy_xxyy_0[i] * fe_0 - ta1_x_xyyy_xxyy_1[i] * fe_0 + ta1_x_xyyy_xxyyz_0[i] * pa_z[i] - ta1_x_xyyy_xxyyz_1[i] * pc_z[i];

        ta1_x_xyyyz_xxyzz_0[i] = 2.0 * ta1_x_xyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xyyy_xxyz_1[i] * fe_0 + ta1_x_xyyy_xxyzz_0[i] * pa_z[i] - ta1_x_xyyy_xxyzz_1[i] * pc_z[i];

        ta1_x_xyyyz_xxzzz_0[i] = 2.0 * ta1_x_xyz_xxzzz_0[i] * fe_0 - 2.0 * ta1_x_xyz_xxzzz_1[i] * fe_0 + ta1_x_xyyz_xxzzz_0[i] * pa_y[i] - ta1_x_xyyz_xxzzz_1[i] * pc_y[i];

        ta1_x_xyyyz_xyyyy_0[i] = ta1_x_xyyy_xyyyy_0[i] * pa_z[i] - ta1_x_xyyy_xyyyy_1[i] * pc_z[i];

        ta1_x_xyyyz_xyyyz_0[i] = ta1_x_xyyy_xyyy_0[i] * fe_0 - ta1_x_xyyy_xyyy_1[i] * fe_0 + ta1_x_xyyy_xyyyz_0[i] * pa_z[i] - ta1_x_xyyy_xyyyz_1[i] * pc_z[i];

        ta1_x_xyyyz_xyyzz_0[i] = 2.0 * ta1_x_xyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_x_xyyy_xyyz_1[i] * fe_0 + ta1_x_xyyy_xyyzz_0[i] * pa_z[i] - ta1_x_xyyy_xyyzz_1[i] * pc_z[i];

        ta1_x_xyyyz_xyzzz_0[i] = 3.0 * ta1_x_xyyy_xyzz_0[i] * fe_0 - 3.0 * ta1_x_xyyy_xyzz_1[i] * fe_0 + ta1_x_xyyy_xyzzz_0[i] * pa_z[i] - ta1_x_xyyy_xyzzz_1[i] * pc_z[i];

        ta1_x_xyyyz_xzzzz_0[i] = 2.0 * ta1_x_xyz_xzzzz_0[i] * fe_0 - 2.0 * ta1_x_xyz_xzzzz_1[i] * fe_0 + ta1_x_xyyz_xzzzz_0[i] * pa_y[i] - ta1_x_xyyz_xzzzz_1[i] * pc_y[i];

        ta1_x_xyyyz_yyyyy_0[i] = ta1_x_xyyy_yyyyy_0[i] * pa_z[i] - ta1_x_xyyy_yyyyy_1[i] * pc_z[i];

        ta1_x_xyyyz_yyyyz_0[i] = ta_yyyz_yyyyz_1[i] + ta1_x_yyyz_yyyyz_0[i] * pa_x[i] - ta1_x_yyyz_yyyyz_1[i] * pc_x[i];

        ta1_x_xyyyz_yyyzz_0[i] = ta_yyyz_yyyzz_1[i] + ta1_x_yyyz_yyyzz_0[i] * pa_x[i] - ta1_x_yyyz_yyyzz_1[i] * pc_x[i];

        ta1_x_xyyyz_yyzzz_0[i] = ta_yyyz_yyzzz_1[i] + ta1_x_yyyz_yyzzz_0[i] * pa_x[i] - ta1_x_yyyz_yyzzz_1[i] * pc_x[i];

        ta1_x_xyyyz_yzzzz_0[i] = ta_yyyz_yzzzz_1[i] + ta1_x_yyyz_yzzzz_0[i] * pa_x[i] - ta1_x_yyyz_yzzzz_1[i] * pc_x[i];

        ta1_x_xyyyz_zzzzz_0[i] = ta_yyyz_zzzzz_1[i] + ta1_x_yyyz_zzzzz_0[i] * pa_x[i] - ta1_x_yyyz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 252-273 components of targeted buffer : HH

    auto ta1_x_xyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 252);

    auto ta1_x_xyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 253);

    auto ta1_x_xyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 254);

    auto ta1_x_xyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 255);

    auto ta1_x_xyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 256);

    auto ta1_x_xyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 257);

    auto ta1_x_xyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 258);

    auto ta1_x_xyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 259);

    auto ta1_x_xyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 260);

    auto ta1_x_xyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 261);

    auto ta1_x_xyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 262);

    auto ta1_x_xyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 263);

    auto ta1_x_xyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 264);

    auto ta1_x_xyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 265);

    auto ta1_x_xyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 266);

    auto ta1_x_xyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 267);

    auto ta1_x_xyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 268);

    auto ta1_x_xyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 269);

    auto ta1_x_xyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 270);

    auto ta1_x_xyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 271);

    auto ta1_x_xyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 272);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_x_xyy_xxxxy_0, ta1_x_xyy_xxxxy_1, ta1_x_xyy_xxxyy_0, ta1_x_xyy_xxxyy_1, ta1_x_xyy_xxyyy_0, ta1_x_xyy_xxyyy_1, ta1_x_xyy_xyyyy_0, ta1_x_xyy_xyyyy_1, ta1_x_xyyz_xxxxy_0, ta1_x_xyyz_xxxxy_1, ta1_x_xyyz_xxxyy_0, ta1_x_xyyz_xxxyy_1, ta1_x_xyyz_xxyyy_0, ta1_x_xyyz_xxyyy_1, ta1_x_xyyz_xyyyy_0, ta1_x_xyyz_xyyyy_1, ta1_x_xyyzz_xxxxx_0, ta1_x_xyyzz_xxxxy_0, ta1_x_xyyzz_xxxxz_0, ta1_x_xyyzz_xxxyy_0, ta1_x_xyyzz_xxxyz_0, ta1_x_xyyzz_xxxzz_0, ta1_x_xyyzz_xxyyy_0, ta1_x_xyyzz_xxyyz_0, ta1_x_xyyzz_xxyzz_0, ta1_x_xyyzz_xxzzz_0, ta1_x_xyyzz_xyyyy_0, ta1_x_xyyzz_xyyyz_0, ta1_x_xyyzz_xyyzz_0, ta1_x_xyyzz_xyzzz_0, ta1_x_xyyzz_xzzzz_0, ta1_x_xyyzz_yyyyy_0, ta1_x_xyyzz_yyyyz_0, ta1_x_xyyzz_yyyzz_0, ta1_x_xyyzz_yyzzz_0, ta1_x_xyyzz_yzzzz_0, ta1_x_xyyzz_zzzzz_0, ta1_x_xyzz_xxxxx_0, ta1_x_xyzz_xxxxx_1, ta1_x_xyzz_xxxxz_0, ta1_x_xyzz_xxxxz_1, ta1_x_xyzz_xxxzz_0, ta1_x_xyzz_xxxzz_1, ta1_x_xyzz_xxzzz_0, ta1_x_xyzz_xxzzz_1, ta1_x_xyzz_xzzzz_0, ta1_x_xyzz_xzzzz_1, ta1_x_xzz_xxxxx_0, ta1_x_xzz_xxxxx_1, ta1_x_xzz_xxxxz_0, ta1_x_xzz_xxxxz_1, ta1_x_xzz_xxxzz_0, ta1_x_xzz_xxxzz_1, ta1_x_xzz_xxzzz_0, ta1_x_xzz_xxzzz_1, ta1_x_xzz_xzzzz_0, ta1_x_xzz_xzzzz_1, ta1_x_yyzz_xxxyz_0, ta1_x_yyzz_xxxyz_1, ta1_x_yyzz_xxyyz_0, ta1_x_yyzz_xxyyz_1, ta1_x_yyzz_xxyz_0, ta1_x_yyzz_xxyz_1, ta1_x_yyzz_xxyzz_0, ta1_x_yyzz_xxyzz_1, ta1_x_yyzz_xyyyz_0, ta1_x_yyzz_xyyyz_1, ta1_x_yyzz_xyyz_0, ta1_x_yyzz_xyyz_1, ta1_x_yyzz_xyyzz_0, ta1_x_yyzz_xyyzz_1, ta1_x_yyzz_xyzz_0, ta1_x_yyzz_xyzz_1, ta1_x_yyzz_xyzzz_0, ta1_x_yyzz_xyzzz_1, ta1_x_yyzz_yyyyy_0, ta1_x_yyzz_yyyyy_1, ta1_x_yyzz_yyyyz_0, ta1_x_yyzz_yyyyz_1, ta1_x_yyzz_yyyz_0, ta1_x_yyzz_yyyz_1, ta1_x_yyzz_yyyzz_0, ta1_x_yyzz_yyyzz_1, ta1_x_yyzz_yyzz_0, ta1_x_yyzz_yyzz_1, ta1_x_yyzz_yyzzz_0, ta1_x_yyzz_yyzzz_1, ta1_x_yyzz_yzzz_0, ta1_x_yyzz_yzzz_1, ta1_x_yyzz_yzzzz_0, ta1_x_yyzz_yzzzz_1, ta1_x_yyzz_zzzzz_0, ta1_x_yyzz_zzzzz_1, ta_yyzz_xxxyz_1, ta_yyzz_xxyyz_1, ta_yyzz_xxyzz_1, ta_yyzz_xyyyz_1, ta_yyzz_xyyzz_1, ta_yyzz_xyzzz_1, ta_yyzz_yyyyy_1, ta_yyzz_yyyyz_1, ta_yyzz_yyyzz_1, ta_yyzz_yyzzz_1, ta_yyzz_yzzzz_1, ta_yyzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xyyzz_xxxxx_0[i] = ta1_x_xzz_xxxxx_0[i] * fe_0 - ta1_x_xzz_xxxxx_1[i] * fe_0 + ta1_x_xyzz_xxxxx_0[i] * pa_y[i] - ta1_x_xyzz_xxxxx_1[i] * pc_y[i];

        ta1_x_xyyzz_xxxxy_0[i] = ta1_x_xyy_xxxxy_0[i] * fe_0 - ta1_x_xyy_xxxxy_1[i] * fe_0 + ta1_x_xyyz_xxxxy_0[i] * pa_z[i] - ta1_x_xyyz_xxxxy_1[i] * pc_z[i];

        ta1_x_xyyzz_xxxxz_0[i] = ta1_x_xzz_xxxxz_0[i] * fe_0 - ta1_x_xzz_xxxxz_1[i] * fe_0 + ta1_x_xyzz_xxxxz_0[i] * pa_y[i] - ta1_x_xyzz_xxxxz_1[i] * pc_y[i];

        ta1_x_xyyzz_xxxyy_0[i] = ta1_x_xyy_xxxyy_0[i] * fe_0 - ta1_x_xyy_xxxyy_1[i] * fe_0 + ta1_x_xyyz_xxxyy_0[i] * pa_z[i] - ta1_x_xyyz_xxxyy_1[i] * pc_z[i];

        ta1_x_xyyzz_xxxyz_0[i] = 3.0 * ta1_x_yyzz_xxyz_0[i] * fe_0 - 3.0 * ta1_x_yyzz_xxyz_1[i] * fe_0 + ta_yyzz_xxxyz_1[i] + ta1_x_yyzz_xxxyz_0[i] * pa_x[i] - ta1_x_yyzz_xxxyz_1[i] * pc_x[i];

        ta1_x_xyyzz_xxxzz_0[i] = ta1_x_xzz_xxxzz_0[i] * fe_0 - ta1_x_xzz_xxxzz_1[i] * fe_0 + ta1_x_xyzz_xxxzz_0[i] * pa_y[i] - ta1_x_xyzz_xxxzz_1[i] * pc_y[i];

        ta1_x_xyyzz_xxyyy_0[i] = ta1_x_xyy_xxyyy_0[i] * fe_0 - ta1_x_xyy_xxyyy_1[i] * fe_0 + ta1_x_xyyz_xxyyy_0[i] * pa_z[i] - ta1_x_xyyz_xxyyy_1[i] * pc_z[i];

        ta1_x_xyyzz_xxyyz_0[i] = 2.0 * ta1_x_yyzz_xyyz_0[i] * fe_0 - 2.0 * ta1_x_yyzz_xyyz_1[i] * fe_0 + ta_yyzz_xxyyz_1[i] + ta1_x_yyzz_xxyyz_0[i] * pa_x[i] - ta1_x_yyzz_xxyyz_1[i] * pc_x[i];

        ta1_x_xyyzz_xxyzz_0[i] = 2.0 * ta1_x_yyzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_yyzz_xyzz_1[i] * fe_0 + ta_yyzz_xxyzz_1[i] + ta1_x_yyzz_xxyzz_0[i] * pa_x[i] - ta1_x_yyzz_xxyzz_1[i] * pc_x[i];

        ta1_x_xyyzz_xxzzz_0[i] = ta1_x_xzz_xxzzz_0[i] * fe_0 - ta1_x_xzz_xxzzz_1[i] * fe_0 + ta1_x_xyzz_xxzzz_0[i] * pa_y[i] - ta1_x_xyzz_xxzzz_1[i] * pc_y[i];

        ta1_x_xyyzz_xyyyy_0[i] = ta1_x_xyy_xyyyy_0[i] * fe_0 - ta1_x_xyy_xyyyy_1[i] * fe_0 + ta1_x_xyyz_xyyyy_0[i] * pa_z[i] - ta1_x_xyyz_xyyyy_1[i] * pc_z[i];

        ta1_x_xyyzz_xyyyz_0[i] = ta1_x_yyzz_yyyz_0[i] * fe_0 - ta1_x_yyzz_yyyz_1[i] * fe_0 + ta_yyzz_xyyyz_1[i] + ta1_x_yyzz_xyyyz_0[i] * pa_x[i] - ta1_x_yyzz_xyyyz_1[i] * pc_x[i];

        ta1_x_xyyzz_xyyzz_0[i] = ta1_x_yyzz_yyzz_0[i] * fe_0 - ta1_x_yyzz_yyzz_1[i] * fe_0 + ta_yyzz_xyyzz_1[i] + ta1_x_yyzz_xyyzz_0[i] * pa_x[i] - ta1_x_yyzz_xyyzz_1[i] * pc_x[i];

        ta1_x_xyyzz_xyzzz_0[i] = ta1_x_yyzz_yzzz_0[i] * fe_0 - ta1_x_yyzz_yzzz_1[i] * fe_0 + ta_yyzz_xyzzz_1[i] + ta1_x_yyzz_xyzzz_0[i] * pa_x[i] - ta1_x_yyzz_xyzzz_1[i] * pc_x[i];

        ta1_x_xyyzz_xzzzz_0[i] = ta1_x_xzz_xzzzz_0[i] * fe_0 - ta1_x_xzz_xzzzz_1[i] * fe_0 + ta1_x_xyzz_xzzzz_0[i] * pa_y[i] - ta1_x_xyzz_xzzzz_1[i] * pc_y[i];

        ta1_x_xyyzz_yyyyy_0[i] = ta_yyzz_yyyyy_1[i] + ta1_x_yyzz_yyyyy_0[i] * pa_x[i] - ta1_x_yyzz_yyyyy_1[i] * pc_x[i];

        ta1_x_xyyzz_yyyyz_0[i] = ta_yyzz_yyyyz_1[i] + ta1_x_yyzz_yyyyz_0[i] * pa_x[i] - ta1_x_yyzz_yyyyz_1[i] * pc_x[i];

        ta1_x_xyyzz_yyyzz_0[i] = ta_yyzz_yyyzz_1[i] + ta1_x_yyzz_yyyzz_0[i] * pa_x[i] - ta1_x_yyzz_yyyzz_1[i] * pc_x[i];

        ta1_x_xyyzz_yyzzz_0[i] = ta_yyzz_yyzzz_1[i] + ta1_x_yyzz_yyzzz_0[i] * pa_x[i] - ta1_x_yyzz_yyzzz_1[i] * pc_x[i];

        ta1_x_xyyzz_yzzzz_0[i] = ta_yyzz_yzzzz_1[i] + ta1_x_yyzz_yzzzz_0[i] * pa_x[i] - ta1_x_yyzz_yzzzz_1[i] * pc_x[i];

        ta1_x_xyyzz_zzzzz_0[i] = ta_yyzz_zzzzz_1[i] + ta1_x_yyzz_zzzzz_0[i] * pa_x[i] - ta1_x_yyzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 273-294 components of targeted buffer : HH

    auto ta1_x_xyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 273);

    auto ta1_x_xyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 274);

    auto ta1_x_xyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 275);

    auto ta1_x_xyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 276);

    auto ta1_x_xyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 277);

    auto ta1_x_xyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 278);

    auto ta1_x_xyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 279);

    auto ta1_x_xyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 280);

    auto ta1_x_xyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 281);

    auto ta1_x_xyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 282);

    auto ta1_x_xyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 283);

    auto ta1_x_xyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 284);

    auto ta1_x_xyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 285);

    auto ta1_x_xyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 286);

    auto ta1_x_xyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 287);

    auto ta1_x_xyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 288);

    auto ta1_x_xyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 289);

    auto ta1_x_xyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 290);

    auto ta1_x_xyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 291);

    auto ta1_x_xyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 292);

    auto ta1_x_xyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 293);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_x_xyzzz_xxxxx_0, ta1_x_xyzzz_xxxxy_0, ta1_x_xyzzz_xxxxz_0, ta1_x_xyzzz_xxxyy_0, ta1_x_xyzzz_xxxyz_0, ta1_x_xyzzz_xxxzz_0, ta1_x_xyzzz_xxyyy_0, ta1_x_xyzzz_xxyyz_0, ta1_x_xyzzz_xxyzz_0, ta1_x_xyzzz_xxzzz_0, ta1_x_xyzzz_xyyyy_0, ta1_x_xyzzz_xyyyz_0, ta1_x_xyzzz_xyyzz_0, ta1_x_xyzzz_xyzzz_0, ta1_x_xyzzz_xzzzz_0, ta1_x_xyzzz_yyyyy_0, ta1_x_xyzzz_yyyyz_0, ta1_x_xyzzz_yyyzz_0, ta1_x_xyzzz_yyzzz_0, ta1_x_xyzzz_yzzzz_0, ta1_x_xyzzz_zzzzz_0, ta1_x_xzzz_xxxx_0, ta1_x_xzzz_xxxx_1, ta1_x_xzzz_xxxxx_0, ta1_x_xzzz_xxxxx_1, ta1_x_xzzz_xxxxy_0, ta1_x_xzzz_xxxxy_1, ta1_x_xzzz_xxxxz_0, ta1_x_xzzz_xxxxz_1, ta1_x_xzzz_xxxy_0, ta1_x_xzzz_xxxy_1, ta1_x_xzzz_xxxyy_0, ta1_x_xzzz_xxxyy_1, ta1_x_xzzz_xxxyz_0, ta1_x_xzzz_xxxyz_1, ta1_x_xzzz_xxxz_0, ta1_x_xzzz_xxxz_1, ta1_x_xzzz_xxxzz_0, ta1_x_xzzz_xxxzz_1, ta1_x_xzzz_xxyy_0, ta1_x_xzzz_xxyy_1, ta1_x_xzzz_xxyyy_0, ta1_x_xzzz_xxyyy_1, ta1_x_xzzz_xxyyz_0, ta1_x_xzzz_xxyyz_1, ta1_x_xzzz_xxyz_0, ta1_x_xzzz_xxyz_1, ta1_x_xzzz_xxyzz_0, ta1_x_xzzz_xxyzz_1, ta1_x_xzzz_xxzz_0, ta1_x_xzzz_xxzz_1, ta1_x_xzzz_xxzzz_0, ta1_x_xzzz_xxzzz_1, ta1_x_xzzz_xyyy_0, ta1_x_xzzz_xyyy_1, ta1_x_xzzz_xyyyy_0, ta1_x_xzzz_xyyyy_1, ta1_x_xzzz_xyyyz_0, ta1_x_xzzz_xyyyz_1, ta1_x_xzzz_xyyz_0, ta1_x_xzzz_xyyz_1, ta1_x_xzzz_xyyzz_0, ta1_x_xzzz_xyyzz_1, ta1_x_xzzz_xyzz_0, ta1_x_xzzz_xyzz_1, ta1_x_xzzz_xyzzz_0, ta1_x_xzzz_xyzzz_1, ta1_x_xzzz_xzzz_0, ta1_x_xzzz_xzzz_1, ta1_x_xzzz_xzzzz_0, ta1_x_xzzz_xzzzz_1, ta1_x_xzzz_zzzzz_0, ta1_x_xzzz_zzzzz_1, ta1_x_yzzz_yyyyy_0, ta1_x_yzzz_yyyyy_1, ta1_x_yzzz_yyyyz_0, ta1_x_yzzz_yyyyz_1, ta1_x_yzzz_yyyzz_0, ta1_x_yzzz_yyyzz_1, ta1_x_yzzz_yyzzz_0, ta1_x_yzzz_yyzzz_1, ta1_x_yzzz_yzzzz_0, ta1_x_yzzz_yzzzz_1, ta_yzzz_yyyyy_1, ta_yzzz_yyyyz_1, ta_yzzz_yyyzz_1, ta_yzzz_yyzzz_1, ta_yzzz_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xyzzz_xxxxx_0[i] = ta1_x_xzzz_xxxxx_0[i] * pa_y[i] - ta1_x_xzzz_xxxxx_1[i] * pc_y[i];

        ta1_x_xyzzz_xxxxy_0[i] = ta1_x_xzzz_xxxx_0[i] * fe_0 - ta1_x_xzzz_xxxx_1[i] * fe_0 + ta1_x_xzzz_xxxxy_0[i] * pa_y[i] - ta1_x_xzzz_xxxxy_1[i] * pc_y[i];

        ta1_x_xyzzz_xxxxz_0[i] = ta1_x_xzzz_xxxxz_0[i] * pa_y[i] - ta1_x_xzzz_xxxxz_1[i] * pc_y[i];

        ta1_x_xyzzz_xxxyy_0[i] = 2.0 * ta1_x_xzzz_xxxy_0[i] * fe_0 - 2.0 * ta1_x_xzzz_xxxy_1[i] * fe_0 + ta1_x_xzzz_xxxyy_0[i] * pa_y[i] - ta1_x_xzzz_xxxyy_1[i] * pc_y[i];

        ta1_x_xyzzz_xxxyz_0[i] = ta1_x_xzzz_xxxz_0[i] * fe_0 - ta1_x_xzzz_xxxz_1[i] * fe_0 + ta1_x_xzzz_xxxyz_0[i] * pa_y[i] - ta1_x_xzzz_xxxyz_1[i] * pc_y[i];

        ta1_x_xyzzz_xxxzz_0[i] = ta1_x_xzzz_xxxzz_0[i] * pa_y[i] - ta1_x_xzzz_xxxzz_1[i] * pc_y[i];

        ta1_x_xyzzz_xxyyy_0[i] = 3.0 * ta1_x_xzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_x_xzzz_xxyy_1[i] * fe_0 + ta1_x_xzzz_xxyyy_0[i] * pa_y[i] - ta1_x_xzzz_xxyyy_1[i] * pc_y[i];

        ta1_x_xyzzz_xxyyz_0[i] = 2.0 * ta1_x_xzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_xzzz_xxyz_1[i] * fe_0 + ta1_x_xzzz_xxyyz_0[i] * pa_y[i] - ta1_x_xzzz_xxyyz_1[i] * pc_y[i];

        ta1_x_xyzzz_xxyzz_0[i] = ta1_x_xzzz_xxzz_0[i] * fe_0 - ta1_x_xzzz_xxzz_1[i] * fe_0 + ta1_x_xzzz_xxyzz_0[i] * pa_y[i] - ta1_x_xzzz_xxyzz_1[i] * pc_y[i];

        ta1_x_xyzzz_xxzzz_0[i] = ta1_x_xzzz_xxzzz_0[i] * pa_y[i] - ta1_x_xzzz_xxzzz_1[i] * pc_y[i];

        ta1_x_xyzzz_xyyyy_0[i] = 4.0 * ta1_x_xzzz_xyyy_0[i] * fe_0 - 4.0 * ta1_x_xzzz_xyyy_1[i] * fe_0 + ta1_x_xzzz_xyyyy_0[i] * pa_y[i] - ta1_x_xzzz_xyyyy_1[i] * pc_y[i];

        ta1_x_xyzzz_xyyyz_0[i] = 3.0 * ta1_x_xzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_xzzz_xyyz_1[i] * fe_0 + ta1_x_xzzz_xyyyz_0[i] * pa_y[i] - ta1_x_xzzz_xyyyz_1[i] * pc_y[i];

        ta1_x_xyzzz_xyyzz_0[i] = 2.0 * ta1_x_xzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_xzzz_xyzz_1[i] * fe_0 + ta1_x_xzzz_xyyzz_0[i] * pa_y[i] - ta1_x_xzzz_xyyzz_1[i] * pc_y[i];

        ta1_x_xyzzz_xyzzz_0[i] = ta1_x_xzzz_xzzz_0[i] * fe_0 - ta1_x_xzzz_xzzz_1[i] * fe_0 + ta1_x_xzzz_xyzzz_0[i] * pa_y[i] - ta1_x_xzzz_xyzzz_1[i] * pc_y[i];

        ta1_x_xyzzz_xzzzz_0[i] = ta1_x_xzzz_xzzzz_0[i] * pa_y[i] - ta1_x_xzzz_xzzzz_1[i] * pc_y[i];

        ta1_x_xyzzz_yyyyy_0[i] = ta_yzzz_yyyyy_1[i] + ta1_x_yzzz_yyyyy_0[i] * pa_x[i] - ta1_x_yzzz_yyyyy_1[i] * pc_x[i];

        ta1_x_xyzzz_yyyyz_0[i] = ta_yzzz_yyyyz_1[i] + ta1_x_yzzz_yyyyz_0[i] * pa_x[i] - ta1_x_yzzz_yyyyz_1[i] * pc_x[i];

        ta1_x_xyzzz_yyyzz_0[i] = ta_yzzz_yyyzz_1[i] + ta1_x_yzzz_yyyzz_0[i] * pa_x[i] - ta1_x_yzzz_yyyzz_1[i] * pc_x[i];

        ta1_x_xyzzz_yyzzz_0[i] = ta_yzzz_yyzzz_1[i] + ta1_x_yzzz_yyzzz_0[i] * pa_x[i] - ta1_x_yzzz_yyzzz_1[i] * pc_x[i];

        ta1_x_xyzzz_yzzzz_0[i] = ta_yzzz_yzzzz_1[i] + ta1_x_yzzz_yzzzz_0[i] * pa_x[i] - ta1_x_yzzz_yzzzz_1[i] * pc_x[i];

        ta1_x_xyzzz_zzzzz_0[i] = ta1_x_xzzz_zzzzz_0[i] * pa_y[i] - ta1_x_xzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 294-315 components of targeted buffer : HH

    auto ta1_x_xzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 294);

    auto ta1_x_xzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 295);

    auto ta1_x_xzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 296);

    auto ta1_x_xzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 297);

    auto ta1_x_xzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 298);

    auto ta1_x_xzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 299);

    auto ta1_x_xzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 300);

    auto ta1_x_xzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 301);

    auto ta1_x_xzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 302);

    auto ta1_x_xzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 303);

    auto ta1_x_xzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 304);

    auto ta1_x_xzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 305);

    auto ta1_x_xzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 306);

    auto ta1_x_xzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 307);

    auto ta1_x_xzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 308);

    auto ta1_x_xzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 309);

    auto ta1_x_xzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 310);

    auto ta1_x_xzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 311);

    auto ta1_x_xzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 312);

    auto ta1_x_xzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 313);

    auto ta1_x_xzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 314);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_x_xzz_xxxxx_0, ta1_x_xzz_xxxxx_1, ta1_x_xzz_xxxxy_0, ta1_x_xzz_xxxxy_1, ta1_x_xzz_xxxyy_0, ta1_x_xzz_xxxyy_1, ta1_x_xzz_xxyyy_0, ta1_x_xzz_xxyyy_1, ta1_x_xzz_xyyyy_0, ta1_x_xzz_xyyyy_1, ta1_x_xzzz_xxxxx_0, ta1_x_xzzz_xxxxx_1, ta1_x_xzzz_xxxxy_0, ta1_x_xzzz_xxxxy_1, ta1_x_xzzz_xxxyy_0, ta1_x_xzzz_xxxyy_1, ta1_x_xzzz_xxyyy_0, ta1_x_xzzz_xxyyy_1, ta1_x_xzzz_xyyyy_0, ta1_x_xzzz_xyyyy_1, ta1_x_xzzzz_xxxxx_0, ta1_x_xzzzz_xxxxy_0, ta1_x_xzzzz_xxxxz_0, ta1_x_xzzzz_xxxyy_0, ta1_x_xzzzz_xxxyz_0, ta1_x_xzzzz_xxxzz_0, ta1_x_xzzzz_xxyyy_0, ta1_x_xzzzz_xxyyz_0, ta1_x_xzzzz_xxyzz_0, ta1_x_xzzzz_xxzzz_0, ta1_x_xzzzz_xyyyy_0, ta1_x_xzzzz_xyyyz_0, ta1_x_xzzzz_xyyzz_0, ta1_x_xzzzz_xyzzz_0, ta1_x_xzzzz_xzzzz_0, ta1_x_xzzzz_yyyyy_0, ta1_x_xzzzz_yyyyz_0, ta1_x_xzzzz_yyyzz_0, ta1_x_xzzzz_yyzzz_0, ta1_x_xzzzz_yzzzz_0, ta1_x_xzzzz_zzzzz_0, ta1_x_zzzz_xxxxz_0, ta1_x_zzzz_xxxxz_1, ta1_x_zzzz_xxxyz_0, ta1_x_zzzz_xxxyz_1, ta1_x_zzzz_xxxz_0, ta1_x_zzzz_xxxz_1, ta1_x_zzzz_xxxzz_0, ta1_x_zzzz_xxxzz_1, ta1_x_zzzz_xxyyz_0, ta1_x_zzzz_xxyyz_1, ta1_x_zzzz_xxyz_0, ta1_x_zzzz_xxyz_1, ta1_x_zzzz_xxyzz_0, ta1_x_zzzz_xxyzz_1, ta1_x_zzzz_xxzz_0, ta1_x_zzzz_xxzz_1, ta1_x_zzzz_xxzzz_0, ta1_x_zzzz_xxzzz_1, ta1_x_zzzz_xyyyz_0, ta1_x_zzzz_xyyyz_1, ta1_x_zzzz_xyyz_0, ta1_x_zzzz_xyyz_1, ta1_x_zzzz_xyyzz_0, ta1_x_zzzz_xyyzz_1, ta1_x_zzzz_xyzz_0, ta1_x_zzzz_xyzz_1, ta1_x_zzzz_xyzzz_0, ta1_x_zzzz_xyzzz_1, ta1_x_zzzz_xzzz_0, ta1_x_zzzz_xzzz_1, ta1_x_zzzz_xzzzz_0, ta1_x_zzzz_xzzzz_1, ta1_x_zzzz_yyyyy_0, ta1_x_zzzz_yyyyy_1, ta1_x_zzzz_yyyyz_0, ta1_x_zzzz_yyyyz_1, ta1_x_zzzz_yyyz_0, ta1_x_zzzz_yyyz_1, ta1_x_zzzz_yyyzz_0, ta1_x_zzzz_yyyzz_1, ta1_x_zzzz_yyzz_0, ta1_x_zzzz_yyzz_1, ta1_x_zzzz_yyzzz_0, ta1_x_zzzz_yyzzz_1, ta1_x_zzzz_yzzz_0, ta1_x_zzzz_yzzz_1, ta1_x_zzzz_yzzzz_0, ta1_x_zzzz_yzzzz_1, ta1_x_zzzz_zzzz_0, ta1_x_zzzz_zzzz_1, ta1_x_zzzz_zzzzz_0, ta1_x_zzzz_zzzzz_1, ta_zzzz_xxxxz_1, ta_zzzz_xxxyz_1, ta_zzzz_xxxzz_1, ta_zzzz_xxyyz_1, ta_zzzz_xxyzz_1, ta_zzzz_xxzzz_1, ta_zzzz_xyyyz_1, ta_zzzz_xyyzz_1, ta_zzzz_xyzzz_1, ta_zzzz_xzzzz_1, ta_zzzz_yyyyy_1, ta_zzzz_yyyyz_1, ta_zzzz_yyyzz_1, ta_zzzz_yyzzz_1, ta_zzzz_yzzzz_1, ta_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_xzzzz_xxxxx_0[i] = 3.0 * ta1_x_xzz_xxxxx_0[i] * fe_0 - 3.0 * ta1_x_xzz_xxxxx_1[i] * fe_0 + ta1_x_xzzz_xxxxx_0[i] * pa_z[i] - ta1_x_xzzz_xxxxx_1[i] * pc_z[i];

        ta1_x_xzzzz_xxxxy_0[i] = 3.0 * ta1_x_xzz_xxxxy_0[i] * fe_0 - 3.0 * ta1_x_xzz_xxxxy_1[i] * fe_0 + ta1_x_xzzz_xxxxy_0[i] * pa_z[i] - ta1_x_xzzz_xxxxy_1[i] * pc_z[i];

        ta1_x_xzzzz_xxxxz_0[i] = 4.0 * ta1_x_zzzz_xxxz_0[i] * fe_0 - 4.0 * ta1_x_zzzz_xxxz_1[i] * fe_0 + ta_zzzz_xxxxz_1[i] + ta1_x_zzzz_xxxxz_0[i] * pa_x[i] - ta1_x_zzzz_xxxxz_1[i] * pc_x[i];

        ta1_x_xzzzz_xxxyy_0[i] = 3.0 * ta1_x_xzz_xxxyy_0[i] * fe_0 - 3.0 * ta1_x_xzz_xxxyy_1[i] * fe_0 + ta1_x_xzzz_xxxyy_0[i] * pa_z[i] - ta1_x_xzzz_xxxyy_1[i] * pc_z[i];

        ta1_x_xzzzz_xxxyz_0[i] = 3.0 * ta1_x_zzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xxyz_1[i] * fe_0 + ta_zzzz_xxxyz_1[i] + ta1_x_zzzz_xxxyz_0[i] * pa_x[i] - ta1_x_zzzz_xxxyz_1[i] * pc_x[i];

        ta1_x_xzzzz_xxxzz_0[i] = 3.0 * ta1_x_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xxzz_1[i] * fe_0 + ta_zzzz_xxxzz_1[i] + ta1_x_zzzz_xxxzz_0[i] * pa_x[i] - ta1_x_zzzz_xxxzz_1[i] * pc_x[i];

        ta1_x_xzzzz_xxyyy_0[i] = 3.0 * ta1_x_xzz_xxyyy_0[i] * fe_0 - 3.0 * ta1_x_xzz_xxyyy_1[i] * fe_0 + ta1_x_xzzz_xxyyy_0[i] * pa_z[i] - ta1_x_xzzz_xxyyy_1[i] * pc_z[i];

        ta1_x_xzzzz_xxyyz_0[i] = 2.0 * ta1_x_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xyyz_1[i] * fe_0 + ta_zzzz_xxyyz_1[i] + ta1_x_zzzz_xxyyz_0[i] * pa_x[i] - ta1_x_zzzz_xxyyz_1[i] * pc_x[i];

        ta1_x_xzzzz_xxyzz_0[i] = 2.0 * ta1_x_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xyzz_1[i] * fe_0 + ta_zzzz_xxyzz_1[i] + ta1_x_zzzz_xxyzz_0[i] * pa_x[i] - ta1_x_zzzz_xxyzz_1[i] * pc_x[i];

        ta1_x_xzzzz_xxzzz_0[i] = 2.0 * ta1_x_zzzz_xzzz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xzzz_1[i] * fe_0 + ta_zzzz_xxzzz_1[i] + ta1_x_zzzz_xxzzz_0[i] * pa_x[i] - ta1_x_zzzz_xxzzz_1[i] * pc_x[i];

        ta1_x_xzzzz_xyyyy_0[i] = 3.0 * ta1_x_xzz_xyyyy_0[i] * fe_0 - 3.0 * ta1_x_xzz_xyyyy_1[i] * fe_0 + ta1_x_xzzz_xyyyy_0[i] * pa_z[i] - ta1_x_xzzz_xyyyy_1[i] * pc_z[i];

        ta1_x_xzzzz_xyyyz_0[i] = ta1_x_zzzz_yyyz_0[i] * fe_0 - ta1_x_zzzz_yyyz_1[i] * fe_0 + ta_zzzz_xyyyz_1[i] + ta1_x_zzzz_xyyyz_0[i] * pa_x[i] - ta1_x_zzzz_xyyyz_1[i] * pc_x[i];

        ta1_x_xzzzz_xyyzz_0[i] = ta1_x_zzzz_yyzz_0[i] * fe_0 - ta1_x_zzzz_yyzz_1[i] * fe_0 + ta_zzzz_xyyzz_1[i] + ta1_x_zzzz_xyyzz_0[i] * pa_x[i] - ta1_x_zzzz_xyyzz_1[i] * pc_x[i];

        ta1_x_xzzzz_xyzzz_0[i] = ta1_x_zzzz_yzzz_0[i] * fe_0 - ta1_x_zzzz_yzzz_1[i] * fe_0 + ta_zzzz_xyzzz_1[i] + ta1_x_zzzz_xyzzz_0[i] * pa_x[i] - ta1_x_zzzz_xyzzz_1[i] * pc_x[i];

        ta1_x_xzzzz_xzzzz_0[i] = ta1_x_zzzz_zzzz_0[i] * fe_0 - ta1_x_zzzz_zzzz_1[i] * fe_0 + ta_zzzz_xzzzz_1[i] + ta1_x_zzzz_xzzzz_0[i] * pa_x[i] - ta1_x_zzzz_xzzzz_1[i] * pc_x[i];

        ta1_x_xzzzz_yyyyy_0[i] = ta_zzzz_yyyyy_1[i] + ta1_x_zzzz_yyyyy_0[i] * pa_x[i] - ta1_x_zzzz_yyyyy_1[i] * pc_x[i];

        ta1_x_xzzzz_yyyyz_0[i] = ta_zzzz_yyyyz_1[i] + ta1_x_zzzz_yyyyz_0[i] * pa_x[i] - ta1_x_zzzz_yyyyz_1[i] * pc_x[i];

        ta1_x_xzzzz_yyyzz_0[i] = ta_zzzz_yyyzz_1[i] + ta1_x_zzzz_yyyzz_0[i] * pa_x[i] - ta1_x_zzzz_yyyzz_1[i] * pc_x[i];

        ta1_x_xzzzz_yyzzz_0[i] = ta_zzzz_yyzzz_1[i] + ta1_x_zzzz_yyzzz_0[i] * pa_x[i] - ta1_x_zzzz_yyzzz_1[i] * pc_x[i];

        ta1_x_xzzzz_yzzzz_0[i] = ta_zzzz_yzzzz_1[i] + ta1_x_zzzz_yzzzz_0[i] * pa_x[i] - ta1_x_zzzz_yzzzz_1[i] * pc_x[i];

        ta1_x_xzzzz_zzzzz_0[i] = ta_zzzz_zzzzz_1[i] + ta1_x_zzzz_zzzzz_0[i] * pa_x[i] - ta1_x_zzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 315-336 components of targeted buffer : HH

    auto ta1_x_yyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 315);

    auto ta1_x_yyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 316);

    auto ta1_x_yyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 317);

    auto ta1_x_yyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 318);

    auto ta1_x_yyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 319);

    auto ta1_x_yyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 320);

    auto ta1_x_yyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 321);

    auto ta1_x_yyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 322);

    auto ta1_x_yyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 323);

    auto ta1_x_yyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 324);

    auto ta1_x_yyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 325);

    auto ta1_x_yyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 326);

    auto ta1_x_yyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 327);

    auto ta1_x_yyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 328);

    auto ta1_x_yyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 329);

    auto ta1_x_yyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 330);

    auto ta1_x_yyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 331);

    auto ta1_x_yyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 332);

    auto ta1_x_yyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 333);

    auto ta1_x_yyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 334);

    auto ta1_x_yyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 335);

    #pragma omp simd aligned(pa_y, pc_y, ta1_x_yyy_xxxxx_0, ta1_x_yyy_xxxxx_1, ta1_x_yyy_xxxxy_0, ta1_x_yyy_xxxxy_1, ta1_x_yyy_xxxxz_0, ta1_x_yyy_xxxxz_1, ta1_x_yyy_xxxyy_0, ta1_x_yyy_xxxyy_1, ta1_x_yyy_xxxyz_0, ta1_x_yyy_xxxyz_1, ta1_x_yyy_xxxzz_0, ta1_x_yyy_xxxzz_1, ta1_x_yyy_xxyyy_0, ta1_x_yyy_xxyyy_1, ta1_x_yyy_xxyyz_0, ta1_x_yyy_xxyyz_1, ta1_x_yyy_xxyzz_0, ta1_x_yyy_xxyzz_1, ta1_x_yyy_xxzzz_0, ta1_x_yyy_xxzzz_1, ta1_x_yyy_xyyyy_0, ta1_x_yyy_xyyyy_1, ta1_x_yyy_xyyyz_0, ta1_x_yyy_xyyyz_1, ta1_x_yyy_xyyzz_0, ta1_x_yyy_xyyzz_1, ta1_x_yyy_xyzzz_0, ta1_x_yyy_xyzzz_1, ta1_x_yyy_xzzzz_0, ta1_x_yyy_xzzzz_1, ta1_x_yyy_yyyyy_0, ta1_x_yyy_yyyyy_1, ta1_x_yyy_yyyyz_0, ta1_x_yyy_yyyyz_1, ta1_x_yyy_yyyzz_0, ta1_x_yyy_yyyzz_1, ta1_x_yyy_yyzzz_0, ta1_x_yyy_yyzzz_1, ta1_x_yyy_yzzzz_0, ta1_x_yyy_yzzzz_1, ta1_x_yyy_zzzzz_0, ta1_x_yyy_zzzzz_1, ta1_x_yyyy_xxxx_0, ta1_x_yyyy_xxxx_1, ta1_x_yyyy_xxxxx_0, ta1_x_yyyy_xxxxx_1, ta1_x_yyyy_xxxxy_0, ta1_x_yyyy_xxxxy_1, ta1_x_yyyy_xxxxz_0, ta1_x_yyyy_xxxxz_1, ta1_x_yyyy_xxxy_0, ta1_x_yyyy_xxxy_1, ta1_x_yyyy_xxxyy_0, ta1_x_yyyy_xxxyy_1, ta1_x_yyyy_xxxyz_0, ta1_x_yyyy_xxxyz_1, ta1_x_yyyy_xxxz_0, ta1_x_yyyy_xxxz_1, ta1_x_yyyy_xxxzz_0, ta1_x_yyyy_xxxzz_1, ta1_x_yyyy_xxyy_0, ta1_x_yyyy_xxyy_1, ta1_x_yyyy_xxyyy_0, ta1_x_yyyy_xxyyy_1, ta1_x_yyyy_xxyyz_0, ta1_x_yyyy_xxyyz_1, ta1_x_yyyy_xxyz_0, ta1_x_yyyy_xxyz_1, ta1_x_yyyy_xxyzz_0, ta1_x_yyyy_xxyzz_1, ta1_x_yyyy_xxzz_0, ta1_x_yyyy_xxzz_1, ta1_x_yyyy_xxzzz_0, ta1_x_yyyy_xxzzz_1, ta1_x_yyyy_xyyy_0, ta1_x_yyyy_xyyy_1, ta1_x_yyyy_xyyyy_0, ta1_x_yyyy_xyyyy_1, ta1_x_yyyy_xyyyz_0, ta1_x_yyyy_xyyyz_1, ta1_x_yyyy_xyyz_0, ta1_x_yyyy_xyyz_1, ta1_x_yyyy_xyyzz_0, ta1_x_yyyy_xyyzz_1, ta1_x_yyyy_xyzz_0, ta1_x_yyyy_xyzz_1, ta1_x_yyyy_xyzzz_0, ta1_x_yyyy_xyzzz_1, ta1_x_yyyy_xzzz_0, ta1_x_yyyy_xzzz_1, ta1_x_yyyy_xzzzz_0, ta1_x_yyyy_xzzzz_1, ta1_x_yyyy_yyyy_0, ta1_x_yyyy_yyyy_1, ta1_x_yyyy_yyyyy_0, ta1_x_yyyy_yyyyy_1, ta1_x_yyyy_yyyyz_0, ta1_x_yyyy_yyyyz_1, ta1_x_yyyy_yyyz_0, ta1_x_yyyy_yyyz_1, ta1_x_yyyy_yyyzz_0, ta1_x_yyyy_yyyzz_1, ta1_x_yyyy_yyzz_0, ta1_x_yyyy_yyzz_1, ta1_x_yyyy_yyzzz_0, ta1_x_yyyy_yyzzz_1, ta1_x_yyyy_yzzz_0, ta1_x_yyyy_yzzz_1, ta1_x_yyyy_yzzzz_0, ta1_x_yyyy_yzzzz_1, ta1_x_yyyy_zzzz_0, ta1_x_yyyy_zzzz_1, ta1_x_yyyy_zzzzz_0, ta1_x_yyyy_zzzzz_1, ta1_x_yyyyy_xxxxx_0, ta1_x_yyyyy_xxxxy_0, ta1_x_yyyyy_xxxxz_0, ta1_x_yyyyy_xxxyy_0, ta1_x_yyyyy_xxxyz_0, ta1_x_yyyyy_xxxzz_0, ta1_x_yyyyy_xxyyy_0, ta1_x_yyyyy_xxyyz_0, ta1_x_yyyyy_xxyzz_0, ta1_x_yyyyy_xxzzz_0, ta1_x_yyyyy_xyyyy_0, ta1_x_yyyyy_xyyyz_0, ta1_x_yyyyy_xyyzz_0, ta1_x_yyyyy_xyzzz_0, ta1_x_yyyyy_xzzzz_0, ta1_x_yyyyy_yyyyy_0, ta1_x_yyyyy_yyyyz_0, ta1_x_yyyyy_yyyzz_0, ta1_x_yyyyy_yyzzz_0, ta1_x_yyyyy_yzzzz_0, ta1_x_yyyyy_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_yyyyy_xxxxx_0[i] = 4.0 * ta1_x_yyy_xxxxx_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxxx_1[i] * fe_0 + ta1_x_yyyy_xxxxx_0[i] * pa_y[i] - ta1_x_yyyy_xxxxx_1[i] * pc_y[i];

        ta1_x_yyyyy_xxxxy_0[i] = 4.0 * ta1_x_yyy_xxxxy_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxxy_1[i] * fe_0 + ta1_x_yyyy_xxxx_0[i] * fe_0 - ta1_x_yyyy_xxxx_1[i] * fe_0 + ta1_x_yyyy_xxxxy_0[i] * pa_y[i] - ta1_x_yyyy_xxxxy_1[i] * pc_y[i];

        ta1_x_yyyyy_xxxxz_0[i] = 4.0 * ta1_x_yyy_xxxxz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxxz_1[i] * fe_0 + ta1_x_yyyy_xxxxz_0[i] * pa_y[i] - ta1_x_yyyy_xxxxz_1[i] * pc_y[i];

        ta1_x_yyyyy_xxxyy_0[i] = 4.0 * ta1_x_yyy_xxxyy_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxyy_1[i] * fe_0 + 2.0 * ta1_x_yyyy_xxxy_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xxxy_1[i] * fe_0 + ta1_x_yyyy_xxxyy_0[i] * pa_y[i] - ta1_x_yyyy_xxxyy_1[i] * pc_y[i];

        ta1_x_yyyyy_xxxyz_0[i] = 4.0 * ta1_x_yyy_xxxyz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxyz_1[i] * fe_0 + ta1_x_yyyy_xxxz_0[i] * fe_0 - ta1_x_yyyy_xxxz_1[i] * fe_0 + ta1_x_yyyy_xxxyz_0[i] * pa_y[i] - ta1_x_yyyy_xxxyz_1[i] * pc_y[i];

        ta1_x_yyyyy_xxxzz_0[i] = 4.0 * ta1_x_yyy_xxxzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxxzz_1[i] * fe_0 + ta1_x_yyyy_xxxzz_0[i] * pa_y[i] - ta1_x_yyyy_xxxzz_1[i] * pc_y[i];

        ta1_x_yyyyy_xxyyy_0[i] = 4.0 * ta1_x_yyy_xxyyy_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxyyy_1[i] * fe_0 + 3.0 * ta1_x_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_x_yyyy_xxyy_1[i] * fe_0 + ta1_x_yyyy_xxyyy_0[i] * pa_y[i] - ta1_x_yyyy_xxyyy_1[i] * pc_y[i];

        ta1_x_yyyyy_xxyyz_0[i] = 4.0 * ta1_x_yyy_xxyyz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xxyz_1[i] * fe_0 + ta1_x_yyyy_xxyyz_0[i] * pa_y[i] - ta1_x_yyyy_xxyyz_1[i] * pc_y[i];

        ta1_x_yyyyy_xxyzz_0[i] = 4.0 * ta1_x_yyy_xxyzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxyzz_1[i] * fe_0 + ta1_x_yyyy_xxzz_0[i] * fe_0 - ta1_x_yyyy_xxzz_1[i] * fe_0 + ta1_x_yyyy_xxyzz_0[i] * pa_y[i] - ta1_x_yyyy_xxyzz_1[i] * pc_y[i];

        ta1_x_yyyyy_xxzzz_0[i] = 4.0 * ta1_x_yyy_xxzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xxzzz_1[i] * fe_0 + ta1_x_yyyy_xxzzz_0[i] * pa_y[i] - ta1_x_yyyy_xxzzz_1[i] * pc_y[i];

        ta1_x_yyyyy_xyyyy_0[i] = 4.0 * ta1_x_yyy_xyyyy_0[i] * fe_0 - 4.0 * ta1_x_yyy_xyyyy_1[i] * fe_0 + 4.0 * ta1_x_yyyy_xyyy_0[i] * fe_0 - 4.0 * ta1_x_yyyy_xyyy_1[i] * fe_0 + ta1_x_yyyy_xyyyy_0[i] * pa_y[i] - ta1_x_yyyy_xyyyy_1[i] * pc_y[i];

        ta1_x_yyyyy_xyyyz_0[i] = 4.0 * ta1_x_yyy_xyyyz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xyyyz_1[i] * fe_0 + 3.0 * ta1_x_yyyy_xyyz_0[i] * fe_0 - 3.0 * ta1_x_yyyy_xyyz_1[i] * fe_0 + ta1_x_yyyy_xyyyz_0[i] * pa_y[i] - ta1_x_yyyy_xyyyz_1[i] * pc_y[i];

        ta1_x_yyyyy_xyyzz_0[i] = 4.0 * ta1_x_yyy_xyyzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xyzz_1[i] * fe_0 + ta1_x_yyyy_xyyzz_0[i] * pa_y[i] - ta1_x_yyyy_xyyzz_1[i] * pc_y[i];

        ta1_x_yyyyy_xyzzz_0[i] = 4.0 * ta1_x_yyy_xyzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xyzzz_1[i] * fe_0 + ta1_x_yyyy_xzzz_0[i] * fe_0 - ta1_x_yyyy_xzzz_1[i] * fe_0 + ta1_x_yyyy_xyzzz_0[i] * pa_y[i] - ta1_x_yyyy_xyzzz_1[i] * pc_y[i];

        ta1_x_yyyyy_xzzzz_0[i] = 4.0 * ta1_x_yyy_xzzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_xzzzz_1[i] * fe_0 + ta1_x_yyyy_xzzzz_0[i] * pa_y[i] - ta1_x_yyyy_xzzzz_1[i] * pc_y[i];

        ta1_x_yyyyy_yyyyy_0[i] = 4.0 * ta1_x_yyy_yyyyy_0[i] * fe_0 - 4.0 * ta1_x_yyy_yyyyy_1[i] * fe_0 + 5.0 * ta1_x_yyyy_yyyy_0[i] * fe_0 - 5.0 * ta1_x_yyyy_yyyy_1[i] * fe_0 + ta1_x_yyyy_yyyyy_0[i] * pa_y[i] - ta1_x_yyyy_yyyyy_1[i] * pc_y[i];

        ta1_x_yyyyy_yyyyz_0[i] = 4.0 * ta1_x_yyy_yyyyz_0[i] * fe_0 - 4.0 * ta1_x_yyy_yyyyz_1[i] * fe_0 + 4.0 * ta1_x_yyyy_yyyz_0[i] * fe_0 - 4.0 * ta1_x_yyyy_yyyz_1[i] * fe_0 + ta1_x_yyyy_yyyyz_0[i] * pa_y[i] - ta1_x_yyyy_yyyyz_1[i] * pc_y[i];

        ta1_x_yyyyy_yyyzz_0[i] = 4.0 * ta1_x_yyy_yyyzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_yyyzz_1[i] * fe_0 + 3.0 * ta1_x_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_x_yyyy_yyzz_1[i] * fe_0 + ta1_x_yyyy_yyyzz_0[i] * pa_y[i] - ta1_x_yyyy_yyyzz_1[i] * pc_y[i];

        ta1_x_yyyyy_yyzzz_0[i] = 4.0 * ta1_x_yyy_yyzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_yyzzz_1[i] * fe_0 + 2.0 * ta1_x_yyyy_yzzz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_yzzz_1[i] * fe_0 + ta1_x_yyyy_yyzzz_0[i] * pa_y[i] - ta1_x_yyyy_yyzzz_1[i] * pc_y[i];

        ta1_x_yyyyy_yzzzz_0[i] = 4.0 * ta1_x_yyy_yzzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_yzzzz_1[i] * fe_0 + ta1_x_yyyy_zzzz_0[i] * fe_0 - ta1_x_yyyy_zzzz_1[i] * fe_0 + ta1_x_yyyy_yzzzz_0[i] * pa_y[i] - ta1_x_yyyy_yzzzz_1[i] * pc_y[i];

        ta1_x_yyyyy_zzzzz_0[i] = 4.0 * ta1_x_yyy_zzzzz_0[i] * fe_0 - 4.0 * ta1_x_yyy_zzzzz_1[i] * fe_0 + ta1_x_yyyy_zzzzz_0[i] * pa_y[i] - ta1_x_yyyy_zzzzz_1[i] * pc_y[i];
    }

    // Set up 336-357 components of targeted buffer : HH

    auto ta1_x_yyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 336);

    auto ta1_x_yyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 337);

    auto ta1_x_yyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 338);

    auto ta1_x_yyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 339);

    auto ta1_x_yyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 340);

    auto ta1_x_yyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 341);

    auto ta1_x_yyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 342);

    auto ta1_x_yyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 343);

    auto ta1_x_yyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 344);

    auto ta1_x_yyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 345);

    auto ta1_x_yyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 346);

    auto ta1_x_yyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 347);

    auto ta1_x_yyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 348);

    auto ta1_x_yyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 349);

    auto ta1_x_yyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 350);

    auto ta1_x_yyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 351);

    auto ta1_x_yyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 352);

    auto ta1_x_yyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 353);

    auto ta1_x_yyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 354);

    auto ta1_x_yyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 355);

    auto ta1_x_yyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 356);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_x_yyyy_xxxxx_0, ta1_x_yyyy_xxxxx_1, ta1_x_yyyy_xxxxy_0, ta1_x_yyyy_xxxxy_1, ta1_x_yyyy_xxxy_0, ta1_x_yyyy_xxxy_1, ta1_x_yyyy_xxxyy_0, ta1_x_yyyy_xxxyy_1, ta1_x_yyyy_xxxyz_0, ta1_x_yyyy_xxxyz_1, ta1_x_yyyy_xxyy_0, ta1_x_yyyy_xxyy_1, ta1_x_yyyy_xxyyy_0, ta1_x_yyyy_xxyyy_1, ta1_x_yyyy_xxyyz_0, ta1_x_yyyy_xxyyz_1, ta1_x_yyyy_xxyz_0, ta1_x_yyyy_xxyz_1, ta1_x_yyyy_xxyzz_0, ta1_x_yyyy_xxyzz_1, ta1_x_yyyy_xyyy_0, ta1_x_yyyy_xyyy_1, ta1_x_yyyy_xyyyy_0, ta1_x_yyyy_xyyyy_1, ta1_x_yyyy_xyyyz_0, ta1_x_yyyy_xyyyz_1, ta1_x_yyyy_xyyz_0, ta1_x_yyyy_xyyz_1, ta1_x_yyyy_xyyzz_0, ta1_x_yyyy_xyyzz_1, ta1_x_yyyy_xyzz_0, ta1_x_yyyy_xyzz_1, ta1_x_yyyy_xyzzz_0, ta1_x_yyyy_xyzzz_1, ta1_x_yyyy_yyyy_0, ta1_x_yyyy_yyyy_1, ta1_x_yyyy_yyyyy_0, ta1_x_yyyy_yyyyy_1, ta1_x_yyyy_yyyyz_0, ta1_x_yyyy_yyyyz_1, ta1_x_yyyy_yyyz_0, ta1_x_yyyy_yyyz_1, ta1_x_yyyy_yyyzz_0, ta1_x_yyyy_yyyzz_1, ta1_x_yyyy_yyzz_0, ta1_x_yyyy_yyzz_1, ta1_x_yyyy_yyzzz_0, ta1_x_yyyy_yyzzz_1, ta1_x_yyyy_yzzz_0, ta1_x_yyyy_yzzz_1, ta1_x_yyyy_yzzzz_0, ta1_x_yyyy_yzzzz_1, ta1_x_yyyyz_xxxxx_0, ta1_x_yyyyz_xxxxy_0, ta1_x_yyyyz_xxxxz_0, ta1_x_yyyyz_xxxyy_0, ta1_x_yyyyz_xxxyz_0, ta1_x_yyyyz_xxxzz_0, ta1_x_yyyyz_xxyyy_0, ta1_x_yyyyz_xxyyz_0, ta1_x_yyyyz_xxyzz_0, ta1_x_yyyyz_xxzzz_0, ta1_x_yyyyz_xyyyy_0, ta1_x_yyyyz_xyyyz_0, ta1_x_yyyyz_xyyzz_0, ta1_x_yyyyz_xyzzz_0, ta1_x_yyyyz_xzzzz_0, ta1_x_yyyyz_yyyyy_0, ta1_x_yyyyz_yyyyz_0, ta1_x_yyyyz_yyyzz_0, ta1_x_yyyyz_yyzzz_0, ta1_x_yyyyz_yzzzz_0, ta1_x_yyyyz_zzzzz_0, ta1_x_yyyz_xxxxz_0, ta1_x_yyyz_xxxxz_1, ta1_x_yyyz_xxxzz_0, ta1_x_yyyz_xxxzz_1, ta1_x_yyyz_xxzzz_0, ta1_x_yyyz_xxzzz_1, ta1_x_yyyz_xzzzz_0, ta1_x_yyyz_xzzzz_1, ta1_x_yyyz_zzzzz_0, ta1_x_yyyz_zzzzz_1, ta1_x_yyz_xxxxz_0, ta1_x_yyz_xxxxz_1, ta1_x_yyz_xxxzz_0, ta1_x_yyz_xxxzz_1, ta1_x_yyz_xxzzz_0, ta1_x_yyz_xxzzz_1, ta1_x_yyz_xzzzz_0, ta1_x_yyz_xzzzz_1, ta1_x_yyz_zzzzz_0, ta1_x_yyz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_yyyyz_xxxxx_0[i] = ta1_x_yyyy_xxxxx_0[i] * pa_z[i] - ta1_x_yyyy_xxxxx_1[i] * pc_z[i];

        ta1_x_yyyyz_xxxxy_0[i] = ta1_x_yyyy_xxxxy_0[i] * pa_z[i] - ta1_x_yyyy_xxxxy_1[i] * pc_z[i];

        ta1_x_yyyyz_xxxxz_0[i] = 3.0 * ta1_x_yyz_xxxxz_0[i] * fe_0 - 3.0 * ta1_x_yyz_xxxxz_1[i] * fe_0 + ta1_x_yyyz_xxxxz_0[i] * pa_y[i] - ta1_x_yyyz_xxxxz_1[i] * pc_y[i];

        ta1_x_yyyyz_xxxyy_0[i] = ta1_x_yyyy_xxxyy_0[i] * pa_z[i] - ta1_x_yyyy_xxxyy_1[i] * pc_z[i];

        ta1_x_yyyyz_xxxyz_0[i] = ta1_x_yyyy_xxxy_0[i] * fe_0 - ta1_x_yyyy_xxxy_1[i] * fe_0 + ta1_x_yyyy_xxxyz_0[i] * pa_z[i] - ta1_x_yyyy_xxxyz_1[i] * pc_z[i];

        ta1_x_yyyyz_xxxzz_0[i] = 3.0 * ta1_x_yyz_xxxzz_0[i] * fe_0 - 3.0 * ta1_x_yyz_xxxzz_1[i] * fe_0 + ta1_x_yyyz_xxxzz_0[i] * pa_y[i] - ta1_x_yyyz_xxxzz_1[i] * pc_y[i];

        ta1_x_yyyyz_xxyyy_0[i] = ta1_x_yyyy_xxyyy_0[i] * pa_z[i] - ta1_x_yyyy_xxyyy_1[i] * pc_z[i];

        ta1_x_yyyyz_xxyyz_0[i] = ta1_x_yyyy_xxyy_0[i] * fe_0 - ta1_x_yyyy_xxyy_1[i] * fe_0 + ta1_x_yyyy_xxyyz_0[i] * pa_z[i] - ta1_x_yyyy_xxyyz_1[i] * pc_z[i];

        ta1_x_yyyyz_xxyzz_0[i] = 2.0 * ta1_x_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xxyz_1[i] * fe_0 + ta1_x_yyyy_xxyzz_0[i] * pa_z[i] - ta1_x_yyyy_xxyzz_1[i] * pc_z[i];

        ta1_x_yyyyz_xxzzz_0[i] = 3.0 * ta1_x_yyz_xxzzz_0[i] * fe_0 - 3.0 * ta1_x_yyz_xxzzz_1[i] * fe_0 + ta1_x_yyyz_xxzzz_0[i] * pa_y[i] - ta1_x_yyyz_xxzzz_1[i] * pc_y[i];

        ta1_x_yyyyz_xyyyy_0[i] = ta1_x_yyyy_xyyyy_0[i] * pa_z[i] - ta1_x_yyyy_xyyyy_1[i] * pc_z[i];

        ta1_x_yyyyz_xyyyz_0[i] = ta1_x_yyyy_xyyy_0[i] * fe_0 - ta1_x_yyyy_xyyy_1[i] * fe_0 + ta1_x_yyyy_xyyyz_0[i] * pa_z[i] - ta1_x_yyyy_xyyyz_1[i] * pc_z[i];

        ta1_x_yyyyz_xyyzz_0[i] = 2.0 * ta1_x_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_xyyz_1[i] * fe_0 + ta1_x_yyyy_xyyzz_0[i] * pa_z[i] - ta1_x_yyyy_xyyzz_1[i] * pc_z[i];

        ta1_x_yyyyz_xyzzz_0[i] = 3.0 * ta1_x_yyyy_xyzz_0[i] * fe_0 - 3.0 * ta1_x_yyyy_xyzz_1[i] * fe_0 + ta1_x_yyyy_xyzzz_0[i] * pa_z[i] - ta1_x_yyyy_xyzzz_1[i] * pc_z[i];

        ta1_x_yyyyz_xzzzz_0[i] = 3.0 * ta1_x_yyz_xzzzz_0[i] * fe_0 - 3.0 * ta1_x_yyz_xzzzz_1[i] * fe_0 + ta1_x_yyyz_xzzzz_0[i] * pa_y[i] - ta1_x_yyyz_xzzzz_1[i] * pc_y[i];

        ta1_x_yyyyz_yyyyy_0[i] = ta1_x_yyyy_yyyyy_0[i] * pa_z[i] - ta1_x_yyyy_yyyyy_1[i] * pc_z[i];

        ta1_x_yyyyz_yyyyz_0[i] = ta1_x_yyyy_yyyy_0[i] * fe_0 - ta1_x_yyyy_yyyy_1[i] * fe_0 + ta1_x_yyyy_yyyyz_0[i] * pa_z[i] - ta1_x_yyyy_yyyyz_1[i] * pc_z[i];

        ta1_x_yyyyz_yyyzz_0[i] = 2.0 * ta1_x_yyyy_yyyz_0[i] * fe_0 - 2.0 * ta1_x_yyyy_yyyz_1[i] * fe_0 + ta1_x_yyyy_yyyzz_0[i] * pa_z[i] - ta1_x_yyyy_yyyzz_1[i] * pc_z[i];

        ta1_x_yyyyz_yyzzz_0[i] = 3.0 * ta1_x_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_x_yyyy_yyzz_1[i] * fe_0 + ta1_x_yyyy_yyzzz_0[i] * pa_z[i] - ta1_x_yyyy_yyzzz_1[i] * pc_z[i];

        ta1_x_yyyyz_yzzzz_0[i] = 4.0 * ta1_x_yyyy_yzzz_0[i] * fe_0 - 4.0 * ta1_x_yyyy_yzzz_1[i] * fe_0 + ta1_x_yyyy_yzzzz_0[i] * pa_z[i] - ta1_x_yyyy_yzzzz_1[i] * pc_z[i];

        ta1_x_yyyyz_zzzzz_0[i] = 3.0 * ta1_x_yyz_zzzzz_0[i] * fe_0 - 3.0 * ta1_x_yyz_zzzzz_1[i] * fe_0 + ta1_x_yyyz_zzzzz_0[i] * pa_y[i] - ta1_x_yyyz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 357-378 components of targeted buffer : HH

    auto ta1_x_yyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 357);

    auto ta1_x_yyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 358);

    auto ta1_x_yyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 359);

    auto ta1_x_yyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 360);

    auto ta1_x_yyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 361);

    auto ta1_x_yyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 362);

    auto ta1_x_yyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 363);

    auto ta1_x_yyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 364);

    auto ta1_x_yyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 365);

    auto ta1_x_yyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 366);

    auto ta1_x_yyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 367);

    auto ta1_x_yyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 368);

    auto ta1_x_yyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 369);

    auto ta1_x_yyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 370);

    auto ta1_x_yyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 371);

    auto ta1_x_yyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 372);

    auto ta1_x_yyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 373);

    auto ta1_x_yyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 374);

    auto ta1_x_yyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 375);

    auto ta1_x_yyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 376);

    auto ta1_x_yyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 377);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_x_yyy_xxxxy_0, ta1_x_yyy_xxxxy_1, ta1_x_yyy_xxxyy_0, ta1_x_yyy_xxxyy_1, ta1_x_yyy_xxyyy_0, ta1_x_yyy_xxyyy_1, ta1_x_yyy_xyyyy_0, ta1_x_yyy_xyyyy_1, ta1_x_yyy_yyyyy_0, ta1_x_yyy_yyyyy_1, ta1_x_yyyz_xxxxy_0, ta1_x_yyyz_xxxxy_1, ta1_x_yyyz_xxxyy_0, ta1_x_yyyz_xxxyy_1, ta1_x_yyyz_xxyyy_0, ta1_x_yyyz_xxyyy_1, ta1_x_yyyz_xyyyy_0, ta1_x_yyyz_xyyyy_1, ta1_x_yyyz_yyyyy_0, ta1_x_yyyz_yyyyy_1, ta1_x_yyyzz_xxxxx_0, ta1_x_yyyzz_xxxxy_0, ta1_x_yyyzz_xxxxz_0, ta1_x_yyyzz_xxxyy_0, ta1_x_yyyzz_xxxyz_0, ta1_x_yyyzz_xxxzz_0, ta1_x_yyyzz_xxyyy_0, ta1_x_yyyzz_xxyyz_0, ta1_x_yyyzz_xxyzz_0, ta1_x_yyyzz_xxzzz_0, ta1_x_yyyzz_xyyyy_0, ta1_x_yyyzz_xyyyz_0, ta1_x_yyyzz_xyyzz_0, ta1_x_yyyzz_xyzzz_0, ta1_x_yyyzz_xzzzz_0, ta1_x_yyyzz_yyyyy_0, ta1_x_yyyzz_yyyyz_0, ta1_x_yyyzz_yyyzz_0, ta1_x_yyyzz_yyzzz_0, ta1_x_yyyzz_yzzzz_0, ta1_x_yyyzz_zzzzz_0, ta1_x_yyzz_xxxxx_0, ta1_x_yyzz_xxxxx_1, ta1_x_yyzz_xxxxz_0, ta1_x_yyzz_xxxxz_1, ta1_x_yyzz_xxxyz_0, ta1_x_yyzz_xxxyz_1, ta1_x_yyzz_xxxz_0, ta1_x_yyzz_xxxz_1, ta1_x_yyzz_xxxzz_0, ta1_x_yyzz_xxxzz_1, ta1_x_yyzz_xxyyz_0, ta1_x_yyzz_xxyyz_1, ta1_x_yyzz_xxyz_0, ta1_x_yyzz_xxyz_1, ta1_x_yyzz_xxyzz_0, ta1_x_yyzz_xxyzz_1, ta1_x_yyzz_xxzz_0, ta1_x_yyzz_xxzz_1, ta1_x_yyzz_xxzzz_0, ta1_x_yyzz_xxzzz_1, ta1_x_yyzz_xyyyz_0, ta1_x_yyzz_xyyyz_1, ta1_x_yyzz_xyyz_0, ta1_x_yyzz_xyyz_1, ta1_x_yyzz_xyyzz_0, ta1_x_yyzz_xyyzz_1, ta1_x_yyzz_xyzz_0, ta1_x_yyzz_xyzz_1, ta1_x_yyzz_xyzzz_0, ta1_x_yyzz_xyzzz_1, ta1_x_yyzz_xzzz_0, ta1_x_yyzz_xzzz_1, ta1_x_yyzz_xzzzz_0, ta1_x_yyzz_xzzzz_1, ta1_x_yyzz_yyyyz_0, ta1_x_yyzz_yyyyz_1, ta1_x_yyzz_yyyz_0, ta1_x_yyzz_yyyz_1, ta1_x_yyzz_yyyzz_0, ta1_x_yyzz_yyyzz_1, ta1_x_yyzz_yyzz_0, ta1_x_yyzz_yyzz_1, ta1_x_yyzz_yyzzz_0, ta1_x_yyzz_yyzzz_1, ta1_x_yyzz_yzzz_0, ta1_x_yyzz_yzzz_1, ta1_x_yyzz_yzzzz_0, ta1_x_yyzz_yzzzz_1, ta1_x_yyzz_zzzz_0, ta1_x_yyzz_zzzz_1, ta1_x_yyzz_zzzzz_0, ta1_x_yyzz_zzzzz_1, ta1_x_yzz_xxxxx_0, ta1_x_yzz_xxxxx_1, ta1_x_yzz_xxxxz_0, ta1_x_yzz_xxxxz_1, ta1_x_yzz_xxxyz_0, ta1_x_yzz_xxxyz_1, ta1_x_yzz_xxxzz_0, ta1_x_yzz_xxxzz_1, ta1_x_yzz_xxyyz_0, ta1_x_yzz_xxyyz_1, ta1_x_yzz_xxyzz_0, ta1_x_yzz_xxyzz_1, ta1_x_yzz_xxzzz_0, ta1_x_yzz_xxzzz_1, ta1_x_yzz_xyyyz_0, ta1_x_yzz_xyyyz_1, ta1_x_yzz_xyyzz_0, ta1_x_yzz_xyyzz_1, ta1_x_yzz_xyzzz_0, ta1_x_yzz_xyzzz_1, ta1_x_yzz_xzzzz_0, ta1_x_yzz_xzzzz_1, ta1_x_yzz_yyyyz_0, ta1_x_yzz_yyyyz_1, ta1_x_yzz_yyyzz_0, ta1_x_yzz_yyyzz_1, ta1_x_yzz_yyzzz_0, ta1_x_yzz_yyzzz_1, ta1_x_yzz_yzzzz_0, ta1_x_yzz_yzzzz_1, ta1_x_yzz_zzzzz_0, ta1_x_yzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_yyyzz_xxxxx_0[i] = 2.0 * ta1_x_yzz_xxxxx_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxxxx_1[i] * fe_0 + ta1_x_yyzz_xxxxx_0[i] * pa_y[i] - ta1_x_yyzz_xxxxx_1[i] * pc_y[i];

        ta1_x_yyyzz_xxxxy_0[i] = ta1_x_yyy_xxxxy_0[i] * fe_0 - ta1_x_yyy_xxxxy_1[i] * fe_0 + ta1_x_yyyz_xxxxy_0[i] * pa_z[i] - ta1_x_yyyz_xxxxy_1[i] * pc_z[i];

        ta1_x_yyyzz_xxxxz_0[i] = 2.0 * ta1_x_yzz_xxxxz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxxxz_1[i] * fe_0 + ta1_x_yyzz_xxxxz_0[i] * pa_y[i] - ta1_x_yyzz_xxxxz_1[i] * pc_y[i];

        ta1_x_yyyzz_xxxyy_0[i] = ta1_x_yyy_xxxyy_0[i] * fe_0 - ta1_x_yyy_xxxyy_1[i] * fe_0 + ta1_x_yyyz_xxxyy_0[i] * pa_z[i] - ta1_x_yyyz_xxxyy_1[i] * pc_z[i];

        ta1_x_yyyzz_xxxyz_0[i] = 2.0 * ta1_x_yzz_xxxyz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxxyz_1[i] * fe_0 + ta1_x_yyzz_xxxz_0[i] * fe_0 - ta1_x_yyzz_xxxz_1[i] * fe_0 + ta1_x_yyzz_xxxyz_0[i] * pa_y[i] - ta1_x_yyzz_xxxyz_1[i] * pc_y[i];

        ta1_x_yyyzz_xxxzz_0[i] = 2.0 * ta1_x_yzz_xxxzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxxzz_1[i] * fe_0 + ta1_x_yyzz_xxxzz_0[i] * pa_y[i] - ta1_x_yyzz_xxxzz_1[i] * pc_y[i];

        ta1_x_yyyzz_xxyyy_0[i] = ta1_x_yyy_xxyyy_0[i] * fe_0 - ta1_x_yyy_xxyyy_1[i] * fe_0 + ta1_x_yyyz_xxyyy_0[i] * pa_z[i] - ta1_x_yyyz_xxyyy_1[i] * pc_z[i];

        ta1_x_yyyzz_xxyyz_0[i] = 2.0 * ta1_x_yzz_xxyyz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_yyzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_yyzz_xxyz_1[i] * fe_0 + ta1_x_yyzz_xxyyz_0[i] * pa_y[i] - ta1_x_yyzz_xxyyz_1[i] * pc_y[i];

        ta1_x_yyyzz_xxyzz_0[i] = 2.0 * ta1_x_yzz_xxyzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxyzz_1[i] * fe_0 + ta1_x_yyzz_xxzz_0[i] * fe_0 - ta1_x_yyzz_xxzz_1[i] * fe_0 + ta1_x_yyzz_xxyzz_0[i] * pa_y[i] - ta1_x_yyzz_xxyzz_1[i] * pc_y[i];

        ta1_x_yyyzz_xxzzz_0[i] = 2.0 * ta1_x_yzz_xxzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xxzzz_1[i] * fe_0 + ta1_x_yyzz_xxzzz_0[i] * pa_y[i] - ta1_x_yyzz_xxzzz_1[i] * pc_y[i];

        ta1_x_yyyzz_xyyyy_0[i] = ta1_x_yyy_xyyyy_0[i] * fe_0 - ta1_x_yyy_xyyyy_1[i] * fe_0 + ta1_x_yyyz_xyyyy_0[i] * pa_z[i] - ta1_x_yyyz_xyyyy_1[i] * pc_z[i];

        ta1_x_yyyzz_xyyyz_0[i] = 2.0 * ta1_x_yzz_xyyyz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xyyyz_1[i] * fe_0 + 3.0 * ta1_x_yyzz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_yyzz_xyyz_1[i] * fe_0 + ta1_x_yyzz_xyyyz_0[i] * pa_y[i] - ta1_x_yyzz_xyyyz_1[i] * pc_y[i];

        ta1_x_yyyzz_xyyzz_0[i] = 2.0 * ta1_x_yzz_xyyzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_yyzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_yyzz_xyzz_1[i] * fe_0 + ta1_x_yyzz_xyyzz_0[i] * pa_y[i] - ta1_x_yyzz_xyyzz_1[i] * pc_y[i];

        ta1_x_yyyzz_xyzzz_0[i] = 2.0 * ta1_x_yzz_xyzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xyzzz_1[i] * fe_0 + ta1_x_yyzz_xzzz_0[i] * fe_0 - ta1_x_yyzz_xzzz_1[i] * fe_0 + ta1_x_yyzz_xyzzz_0[i] * pa_y[i] - ta1_x_yyzz_xyzzz_1[i] * pc_y[i];

        ta1_x_yyyzz_xzzzz_0[i] = 2.0 * ta1_x_yzz_xzzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_xzzzz_1[i] * fe_0 + ta1_x_yyzz_xzzzz_0[i] * pa_y[i] - ta1_x_yyzz_xzzzz_1[i] * pc_y[i];

        ta1_x_yyyzz_yyyyy_0[i] = ta1_x_yyy_yyyyy_0[i] * fe_0 - ta1_x_yyy_yyyyy_1[i] * fe_0 + ta1_x_yyyz_yyyyy_0[i] * pa_z[i] - ta1_x_yyyz_yyyyy_1[i] * pc_z[i];

        ta1_x_yyyzz_yyyyz_0[i] = 2.0 * ta1_x_yzz_yyyyz_0[i] * fe_0 - 2.0 * ta1_x_yzz_yyyyz_1[i] * fe_0 + 4.0 * ta1_x_yyzz_yyyz_0[i] * fe_0 - 4.0 * ta1_x_yyzz_yyyz_1[i] * fe_0 + ta1_x_yyzz_yyyyz_0[i] * pa_y[i] - ta1_x_yyzz_yyyyz_1[i] * pc_y[i];

        ta1_x_yyyzz_yyyzz_0[i] = 2.0 * ta1_x_yzz_yyyzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_yyyzz_1[i] * fe_0 + 3.0 * ta1_x_yyzz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_yyzz_yyzz_1[i] * fe_0 + ta1_x_yyzz_yyyzz_0[i] * pa_y[i] - ta1_x_yyzz_yyyzz_1[i] * pc_y[i];

        ta1_x_yyyzz_yyzzz_0[i] = 2.0 * ta1_x_yzz_yyzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_yyzzz_1[i] * fe_0 + 2.0 * ta1_x_yyzz_yzzz_0[i] * fe_0 - 2.0 * ta1_x_yyzz_yzzz_1[i] * fe_0 + ta1_x_yyzz_yyzzz_0[i] * pa_y[i] - ta1_x_yyzz_yyzzz_1[i] * pc_y[i];

        ta1_x_yyyzz_yzzzz_0[i] = 2.0 * ta1_x_yzz_yzzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_yzzzz_1[i] * fe_0 + ta1_x_yyzz_zzzz_0[i] * fe_0 - ta1_x_yyzz_zzzz_1[i] * fe_0 + ta1_x_yyzz_yzzzz_0[i] * pa_y[i] - ta1_x_yyzz_yzzzz_1[i] * pc_y[i];

        ta1_x_yyyzz_zzzzz_0[i] = 2.0 * ta1_x_yzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_x_yzz_zzzzz_1[i] * fe_0 + ta1_x_yyzz_zzzzz_0[i] * pa_y[i] - ta1_x_yyzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 378-399 components of targeted buffer : HH

    auto ta1_x_yyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 378);

    auto ta1_x_yyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 379);

    auto ta1_x_yyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 380);

    auto ta1_x_yyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 381);

    auto ta1_x_yyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 382);

    auto ta1_x_yyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 383);

    auto ta1_x_yyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 384);

    auto ta1_x_yyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 385);

    auto ta1_x_yyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 386);

    auto ta1_x_yyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 387);

    auto ta1_x_yyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 388);

    auto ta1_x_yyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 389);

    auto ta1_x_yyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 390);

    auto ta1_x_yyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 391);

    auto ta1_x_yyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 392);

    auto ta1_x_yyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 393);

    auto ta1_x_yyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 394);

    auto ta1_x_yyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 395);

    auto ta1_x_yyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 396);

    auto ta1_x_yyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 397);

    auto ta1_x_yyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 398);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_x_yyz_xxxxy_0, ta1_x_yyz_xxxxy_1, ta1_x_yyz_xxxyy_0, ta1_x_yyz_xxxyy_1, ta1_x_yyz_xxyyy_0, ta1_x_yyz_xxyyy_1, ta1_x_yyz_xyyyy_0, ta1_x_yyz_xyyyy_1, ta1_x_yyz_yyyyy_0, ta1_x_yyz_yyyyy_1, ta1_x_yyzz_xxxxy_0, ta1_x_yyzz_xxxxy_1, ta1_x_yyzz_xxxyy_0, ta1_x_yyzz_xxxyy_1, ta1_x_yyzz_xxyyy_0, ta1_x_yyzz_xxyyy_1, ta1_x_yyzz_xyyyy_0, ta1_x_yyzz_xyyyy_1, ta1_x_yyzz_yyyyy_0, ta1_x_yyzz_yyyyy_1, ta1_x_yyzzz_xxxxx_0, ta1_x_yyzzz_xxxxy_0, ta1_x_yyzzz_xxxxz_0, ta1_x_yyzzz_xxxyy_0, ta1_x_yyzzz_xxxyz_0, ta1_x_yyzzz_xxxzz_0, ta1_x_yyzzz_xxyyy_0, ta1_x_yyzzz_xxyyz_0, ta1_x_yyzzz_xxyzz_0, ta1_x_yyzzz_xxzzz_0, ta1_x_yyzzz_xyyyy_0, ta1_x_yyzzz_xyyyz_0, ta1_x_yyzzz_xyyzz_0, ta1_x_yyzzz_xyzzz_0, ta1_x_yyzzz_xzzzz_0, ta1_x_yyzzz_yyyyy_0, ta1_x_yyzzz_yyyyz_0, ta1_x_yyzzz_yyyzz_0, ta1_x_yyzzz_yyzzz_0, ta1_x_yyzzz_yzzzz_0, ta1_x_yyzzz_zzzzz_0, ta1_x_yzzz_xxxxx_0, ta1_x_yzzz_xxxxx_1, ta1_x_yzzz_xxxxz_0, ta1_x_yzzz_xxxxz_1, ta1_x_yzzz_xxxyz_0, ta1_x_yzzz_xxxyz_1, ta1_x_yzzz_xxxz_0, ta1_x_yzzz_xxxz_1, ta1_x_yzzz_xxxzz_0, ta1_x_yzzz_xxxzz_1, ta1_x_yzzz_xxyyz_0, ta1_x_yzzz_xxyyz_1, ta1_x_yzzz_xxyz_0, ta1_x_yzzz_xxyz_1, ta1_x_yzzz_xxyzz_0, ta1_x_yzzz_xxyzz_1, ta1_x_yzzz_xxzz_0, ta1_x_yzzz_xxzz_1, ta1_x_yzzz_xxzzz_0, ta1_x_yzzz_xxzzz_1, ta1_x_yzzz_xyyyz_0, ta1_x_yzzz_xyyyz_1, ta1_x_yzzz_xyyz_0, ta1_x_yzzz_xyyz_1, ta1_x_yzzz_xyyzz_0, ta1_x_yzzz_xyyzz_1, ta1_x_yzzz_xyzz_0, ta1_x_yzzz_xyzz_1, ta1_x_yzzz_xyzzz_0, ta1_x_yzzz_xyzzz_1, ta1_x_yzzz_xzzz_0, ta1_x_yzzz_xzzz_1, ta1_x_yzzz_xzzzz_0, ta1_x_yzzz_xzzzz_1, ta1_x_yzzz_yyyyz_0, ta1_x_yzzz_yyyyz_1, ta1_x_yzzz_yyyz_0, ta1_x_yzzz_yyyz_1, ta1_x_yzzz_yyyzz_0, ta1_x_yzzz_yyyzz_1, ta1_x_yzzz_yyzz_0, ta1_x_yzzz_yyzz_1, ta1_x_yzzz_yyzzz_0, ta1_x_yzzz_yyzzz_1, ta1_x_yzzz_yzzz_0, ta1_x_yzzz_yzzz_1, ta1_x_yzzz_yzzzz_0, ta1_x_yzzz_yzzzz_1, ta1_x_yzzz_zzzz_0, ta1_x_yzzz_zzzz_1, ta1_x_yzzz_zzzzz_0, ta1_x_yzzz_zzzzz_1, ta1_x_zzz_xxxxx_0, ta1_x_zzz_xxxxx_1, ta1_x_zzz_xxxxz_0, ta1_x_zzz_xxxxz_1, ta1_x_zzz_xxxyz_0, ta1_x_zzz_xxxyz_1, ta1_x_zzz_xxxzz_0, ta1_x_zzz_xxxzz_1, ta1_x_zzz_xxyyz_0, ta1_x_zzz_xxyyz_1, ta1_x_zzz_xxyzz_0, ta1_x_zzz_xxyzz_1, ta1_x_zzz_xxzzz_0, ta1_x_zzz_xxzzz_1, ta1_x_zzz_xyyyz_0, ta1_x_zzz_xyyyz_1, ta1_x_zzz_xyyzz_0, ta1_x_zzz_xyyzz_1, ta1_x_zzz_xyzzz_0, ta1_x_zzz_xyzzz_1, ta1_x_zzz_xzzzz_0, ta1_x_zzz_xzzzz_1, ta1_x_zzz_yyyyz_0, ta1_x_zzz_yyyyz_1, ta1_x_zzz_yyyzz_0, ta1_x_zzz_yyyzz_1, ta1_x_zzz_yyzzz_0, ta1_x_zzz_yyzzz_1, ta1_x_zzz_yzzzz_0, ta1_x_zzz_yzzzz_1, ta1_x_zzz_zzzzz_0, ta1_x_zzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_yyzzz_xxxxx_0[i] = ta1_x_zzz_xxxxx_0[i] * fe_0 - ta1_x_zzz_xxxxx_1[i] * fe_0 + ta1_x_yzzz_xxxxx_0[i] * pa_y[i] - ta1_x_yzzz_xxxxx_1[i] * pc_y[i];

        ta1_x_yyzzz_xxxxy_0[i] = 2.0 * ta1_x_yyz_xxxxy_0[i] * fe_0 - 2.0 * ta1_x_yyz_xxxxy_1[i] * fe_0 + ta1_x_yyzz_xxxxy_0[i] * pa_z[i] - ta1_x_yyzz_xxxxy_1[i] * pc_z[i];

        ta1_x_yyzzz_xxxxz_0[i] = ta1_x_zzz_xxxxz_0[i] * fe_0 - ta1_x_zzz_xxxxz_1[i] * fe_0 + ta1_x_yzzz_xxxxz_0[i] * pa_y[i] - ta1_x_yzzz_xxxxz_1[i] * pc_y[i];

        ta1_x_yyzzz_xxxyy_0[i] = 2.0 * ta1_x_yyz_xxxyy_0[i] * fe_0 - 2.0 * ta1_x_yyz_xxxyy_1[i] * fe_0 + ta1_x_yyzz_xxxyy_0[i] * pa_z[i] - ta1_x_yyzz_xxxyy_1[i] * pc_z[i];

        ta1_x_yyzzz_xxxyz_0[i] = ta1_x_zzz_xxxyz_0[i] * fe_0 - ta1_x_zzz_xxxyz_1[i] * fe_0 + ta1_x_yzzz_xxxz_0[i] * fe_0 - ta1_x_yzzz_xxxz_1[i] * fe_0 + ta1_x_yzzz_xxxyz_0[i] * pa_y[i] - ta1_x_yzzz_xxxyz_1[i] * pc_y[i];

        ta1_x_yyzzz_xxxzz_0[i] = ta1_x_zzz_xxxzz_0[i] * fe_0 - ta1_x_zzz_xxxzz_1[i] * fe_0 + ta1_x_yzzz_xxxzz_0[i] * pa_y[i] - ta1_x_yzzz_xxxzz_1[i] * pc_y[i];

        ta1_x_yyzzz_xxyyy_0[i] = 2.0 * ta1_x_yyz_xxyyy_0[i] * fe_0 - 2.0 * ta1_x_yyz_xxyyy_1[i] * fe_0 + ta1_x_yyzz_xxyyy_0[i] * pa_z[i] - ta1_x_yyzz_xxyyy_1[i] * pc_z[i];

        ta1_x_yyzzz_xxyyz_0[i] = ta1_x_zzz_xxyyz_0[i] * fe_0 - ta1_x_zzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_x_yzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_yzzz_xxyz_1[i] * fe_0 + ta1_x_yzzz_xxyyz_0[i] * pa_y[i] - ta1_x_yzzz_xxyyz_1[i] * pc_y[i];

        ta1_x_yyzzz_xxyzz_0[i] = ta1_x_zzz_xxyzz_0[i] * fe_0 - ta1_x_zzz_xxyzz_1[i] * fe_0 + ta1_x_yzzz_xxzz_0[i] * fe_0 - ta1_x_yzzz_xxzz_1[i] * fe_0 + ta1_x_yzzz_xxyzz_0[i] * pa_y[i] - ta1_x_yzzz_xxyzz_1[i] * pc_y[i];

        ta1_x_yyzzz_xxzzz_0[i] = ta1_x_zzz_xxzzz_0[i] * fe_0 - ta1_x_zzz_xxzzz_1[i] * fe_0 + ta1_x_yzzz_xxzzz_0[i] * pa_y[i] - ta1_x_yzzz_xxzzz_1[i] * pc_y[i];

        ta1_x_yyzzz_xyyyy_0[i] = 2.0 * ta1_x_yyz_xyyyy_0[i] * fe_0 - 2.0 * ta1_x_yyz_xyyyy_1[i] * fe_0 + ta1_x_yyzz_xyyyy_0[i] * pa_z[i] - ta1_x_yyzz_xyyyy_1[i] * pc_z[i];

        ta1_x_yyzzz_xyyyz_0[i] = ta1_x_zzz_xyyyz_0[i] * fe_0 - ta1_x_zzz_xyyyz_1[i] * fe_0 + 3.0 * ta1_x_yzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_yzzz_xyyz_1[i] * fe_0 + ta1_x_yzzz_xyyyz_0[i] * pa_y[i] - ta1_x_yzzz_xyyyz_1[i] * pc_y[i];

        ta1_x_yyzzz_xyyzz_0[i] = ta1_x_zzz_xyyzz_0[i] * fe_0 - ta1_x_zzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_yzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_yzzz_xyzz_1[i] * fe_0 + ta1_x_yzzz_xyyzz_0[i] * pa_y[i] - ta1_x_yzzz_xyyzz_1[i] * pc_y[i];

        ta1_x_yyzzz_xyzzz_0[i] = ta1_x_zzz_xyzzz_0[i] * fe_0 - ta1_x_zzz_xyzzz_1[i] * fe_0 + ta1_x_yzzz_xzzz_0[i] * fe_0 - ta1_x_yzzz_xzzz_1[i] * fe_0 + ta1_x_yzzz_xyzzz_0[i] * pa_y[i] - ta1_x_yzzz_xyzzz_1[i] * pc_y[i];

        ta1_x_yyzzz_xzzzz_0[i] = ta1_x_zzz_xzzzz_0[i] * fe_0 - ta1_x_zzz_xzzzz_1[i] * fe_0 + ta1_x_yzzz_xzzzz_0[i] * pa_y[i] - ta1_x_yzzz_xzzzz_1[i] * pc_y[i];

        ta1_x_yyzzz_yyyyy_0[i] = 2.0 * ta1_x_yyz_yyyyy_0[i] * fe_0 - 2.0 * ta1_x_yyz_yyyyy_1[i] * fe_0 + ta1_x_yyzz_yyyyy_0[i] * pa_z[i] - ta1_x_yyzz_yyyyy_1[i] * pc_z[i];

        ta1_x_yyzzz_yyyyz_0[i] = ta1_x_zzz_yyyyz_0[i] * fe_0 - ta1_x_zzz_yyyyz_1[i] * fe_0 + 4.0 * ta1_x_yzzz_yyyz_0[i] * fe_0 - 4.0 * ta1_x_yzzz_yyyz_1[i] * fe_0 + ta1_x_yzzz_yyyyz_0[i] * pa_y[i] - ta1_x_yzzz_yyyyz_1[i] * pc_y[i];

        ta1_x_yyzzz_yyyzz_0[i] = ta1_x_zzz_yyyzz_0[i] * fe_0 - ta1_x_zzz_yyyzz_1[i] * fe_0 + 3.0 * ta1_x_yzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_yzzz_yyzz_1[i] * fe_0 + ta1_x_yzzz_yyyzz_0[i] * pa_y[i] - ta1_x_yzzz_yyyzz_1[i] * pc_y[i];

        ta1_x_yyzzz_yyzzz_0[i] = ta1_x_zzz_yyzzz_0[i] * fe_0 - ta1_x_zzz_yyzzz_1[i] * fe_0 + 2.0 * ta1_x_yzzz_yzzz_0[i] * fe_0 - 2.0 * ta1_x_yzzz_yzzz_1[i] * fe_0 + ta1_x_yzzz_yyzzz_0[i] * pa_y[i] - ta1_x_yzzz_yyzzz_1[i] * pc_y[i];

        ta1_x_yyzzz_yzzzz_0[i] = ta1_x_zzz_yzzzz_0[i] * fe_0 - ta1_x_zzz_yzzzz_1[i] * fe_0 + ta1_x_yzzz_zzzz_0[i] * fe_0 - ta1_x_yzzz_zzzz_1[i] * fe_0 + ta1_x_yzzz_yzzzz_0[i] * pa_y[i] - ta1_x_yzzz_yzzzz_1[i] * pc_y[i];

        ta1_x_yyzzz_zzzzz_0[i] = ta1_x_zzz_zzzzz_0[i] * fe_0 - ta1_x_zzz_zzzzz_1[i] * fe_0 + ta1_x_yzzz_zzzzz_0[i] * pa_y[i] - ta1_x_yzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 399-420 components of targeted buffer : HH

    auto ta1_x_yzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 399);

    auto ta1_x_yzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 400);

    auto ta1_x_yzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 401);

    auto ta1_x_yzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 402);

    auto ta1_x_yzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 403);

    auto ta1_x_yzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 404);

    auto ta1_x_yzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 405);

    auto ta1_x_yzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 406);

    auto ta1_x_yzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 407);

    auto ta1_x_yzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 408);

    auto ta1_x_yzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 409);

    auto ta1_x_yzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 410);

    auto ta1_x_yzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 411);

    auto ta1_x_yzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 412);

    auto ta1_x_yzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 413);

    auto ta1_x_yzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 414);

    auto ta1_x_yzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 415);

    auto ta1_x_yzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 416);

    auto ta1_x_yzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 417);

    auto ta1_x_yzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 418);

    auto ta1_x_yzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 419);

    #pragma omp simd aligned(pa_y, pc_y, ta1_x_yzzzz_xxxxx_0, ta1_x_yzzzz_xxxxy_0, ta1_x_yzzzz_xxxxz_0, ta1_x_yzzzz_xxxyy_0, ta1_x_yzzzz_xxxyz_0, ta1_x_yzzzz_xxxzz_0, ta1_x_yzzzz_xxyyy_0, ta1_x_yzzzz_xxyyz_0, ta1_x_yzzzz_xxyzz_0, ta1_x_yzzzz_xxzzz_0, ta1_x_yzzzz_xyyyy_0, ta1_x_yzzzz_xyyyz_0, ta1_x_yzzzz_xyyzz_0, ta1_x_yzzzz_xyzzz_0, ta1_x_yzzzz_xzzzz_0, ta1_x_yzzzz_yyyyy_0, ta1_x_yzzzz_yyyyz_0, ta1_x_yzzzz_yyyzz_0, ta1_x_yzzzz_yyzzz_0, ta1_x_yzzzz_yzzzz_0, ta1_x_yzzzz_zzzzz_0, ta1_x_zzzz_xxxx_0, ta1_x_zzzz_xxxx_1, ta1_x_zzzz_xxxxx_0, ta1_x_zzzz_xxxxx_1, ta1_x_zzzz_xxxxy_0, ta1_x_zzzz_xxxxy_1, ta1_x_zzzz_xxxxz_0, ta1_x_zzzz_xxxxz_1, ta1_x_zzzz_xxxy_0, ta1_x_zzzz_xxxy_1, ta1_x_zzzz_xxxyy_0, ta1_x_zzzz_xxxyy_1, ta1_x_zzzz_xxxyz_0, ta1_x_zzzz_xxxyz_1, ta1_x_zzzz_xxxz_0, ta1_x_zzzz_xxxz_1, ta1_x_zzzz_xxxzz_0, ta1_x_zzzz_xxxzz_1, ta1_x_zzzz_xxyy_0, ta1_x_zzzz_xxyy_1, ta1_x_zzzz_xxyyy_0, ta1_x_zzzz_xxyyy_1, ta1_x_zzzz_xxyyz_0, ta1_x_zzzz_xxyyz_1, ta1_x_zzzz_xxyz_0, ta1_x_zzzz_xxyz_1, ta1_x_zzzz_xxyzz_0, ta1_x_zzzz_xxyzz_1, ta1_x_zzzz_xxzz_0, ta1_x_zzzz_xxzz_1, ta1_x_zzzz_xxzzz_0, ta1_x_zzzz_xxzzz_1, ta1_x_zzzz_xyyy_0, ta1_x_zzzz_xyyy_1, ta1_x_zzzz_xyyyy_0, ta1_x_zzzz_xyyyy_1, ta1_x_zzzz_xyyyz_0, ta1_x_zzzz_xyyyz_1, ta1_x_zzzz_xyyz_0, ta1_x_zzzz_xyyz_1, ta1_x_zzzz_xyyzz_0, ta1_x_zzzz_xyyzz_1, ta1_x_zzzz_xyzz_0, ta1_x_zzzz_xyzz_1, ta1_x_zzzz_xyzzz_0, ta1_x_zzzz_xyzzz_1, ta1_x_zzzz_xzzz_0, ta1_x_zzzz_xzzz_1, ta1_x_zzzz_xzzzz_0, ta1_x_zzzz_xzzzz_1, ta1_x_zzzz_yyyy_0, ta1_x_zzzz_yyyy_1, ta1_x_zzzz_yyyyy_0, ta1_x_zzzz_yyyyy_1, ta1_x_zzzz_yyyyz_0, ta1_x_zzzz_yyyyz_1, ta1_x_zzzz_yyyz_0, ta1_x_zzzz_yyyz_1, ta1_x_zzzz_yyyzz_0, ta1_x_zzzz_yyyzz_1, ta1_x_zzzz_yyzz_0, ta1_x_zzzz_yyzz_1, ta1_x_zzzz_yyzzz_0, ta1_x_zzzz_yyzzz_1, ta1_x_zzzz_yzzz_0, ta1_x_zzzz_yzzz_1, ta1_x_zzzz_yzzzz_0, ta1_x_zzzz_yzzzz_1, ta1_x_zzzz_zzzz_0, ta1_x_zzzz_zzzz_1, ta1_x_zzzz_zzzzz_0, ta1_x_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_yzzzz_xxxxx_0[i] = ta1_x_zzzz_xxxxx_0[i] * pa_y[i] - ta1_x_zzzz_xxxxx_1[i] * pc_y[i];

        ta1_x_yzzzz_xxxxy_0[i] = ta1_x_zzzz_xxxx_0[i] * fe_0 - ta1_x_zzzz_xxxx_1[i] * fe_0 + ta1_x_zzzz_xxxxy_0[i] * pa_y[i] - ta1_x_zzzz_xxxxy_1[i] * pc_y[i];

        ta1_x_yzzzz_xxxxz_0[i] = ta1_x_zzzz_xxxxz_0[i] * pa_y[i] - ta1_x_zzzz_xxxxz_1[i] * pc_y[i];

        ta1_x_yzzzz_xxxyy_0[i] = 2.0 * ta1_x_zzzz_xxxy_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xxxy_1[i] * fe_0 + ta1_x_zzzz_xxxyy_0[i] * pa_y[i] - ta1_x_zzzz_xxxyy_1[i] * pc_y[i];

        ta1_x_yzzzz_xxxyz_0[i] = ta1_x_zzzz_xxxz_0[i] * fe_0 - ta1_x_zzzz_xxxz_1[i] * fe_0 + ta1_x_zzzz_xxxyz_0[i] * pa_y[i] - ta1_x_zzzz_xxxyz_1[i] * pc_y[i];

        ta1_x_yzzzz_xxxzz_0[i] = ta1_x_zzzz_xxxzz_0[i] * pa_y[i] - ta1_x_zzzz_xxxzz_1[i] * pc_y[i];

        ta1_x_yzzzz_xxyyy_0[i] = 3.0 * ta1_x_zzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xxyy_1[i] * fe_0 + ta1_x_zzzz_xxyyy_0[i] * pa_y[i] - ta1_x_zzzz_xxyyy_1[i] * pc_y[i];

        ta1_x_yzzzz_xxyyz_0[i] = 2.0 * ta1_x_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xxyz_1[i] * fe_0 + ta1_x_zzzz_xxyyz_0[i] * pa_y[i] - ta1_x_zzzz_xxyyz_1[i] * pc_y[i];

        ta1_x_yzzzz_xxyzz_0[i] = ta1_x_zzzz_xxzz_0[i] * fe_0 - ta1_x_zzzz_xxzz_1[i] * fe_0 + ta1_x_zzzz_xxyzz_0[i] * pa_y[i] - ta1_x_zzzz_xxyzz_1[i] * pc_y[i];

        ta1_x_yzzzz_xxzzz_0[i] = ta1_x_zzzz_xxzzz_0[i] * pa_y[i] - ta1_x_zzzz_xxzzz_1[i] * pc_y[i];

        ta1_x_yzzzz_xyyyy_0[i] = 4.0 * ta1_x_zzzz_xyyy_0[i] * fe_0 - 4.0 * ta1_x_zzzz_xyyy_1[i] * fe_0 + ta1_x_zzzz_xyyyy_0[i] * pa_y[i] - ta1_x_zzzz_xyyyy_1[i] * pc_y[i];

        ta1_x_yzzzz_xyyyz_0[i] = 3.0 * ta1_x_zzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xyyz_1[i] * fe_0 + ta1_x_zzzz_xyyyz_0[i] * pa_y[i] - ta1_x_zzzz_xyyyz_1[i] * pc_y[i];

        ta1_x_yzzzz_xyyzz_0[i] = 2.0 * ta1_x_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xyzz_1[i] * fe_0 + ta1_x_zzzz_xyyzz_0[i] * pa_y[i] - ta1_x_zzzz_xyyzz_1[i] * pc_y[i];

        ta1_x_yzzzz_xyzzz_0[i] = ta1_x_zzzz_xzzz_0[i] * fe_0 - ta1_x_zzzz_xzzz_1[i] * fe_0 + ta1_x_zzzz_xyzzz_0[i] * pa_y[i] - ta1_x_zzzz_xyzzz_1[i] * pc_y[i];

        ta1_x_yzzzz_xzzzz_0[i] = ta1_x_zzzz_xzzzz_0[i] * pa_y[i] - ta1_x_zzzz_xzzzz_1[i] * pc_y[i];

        ta1_x_yzzzz_yyyyy_0[i] = 5.0 * ta1_x_zzzz_yyyy_0[i] * fe_0 - 5.0 * ta1_x_zzzz_yyyy_1[i] * fe_0 + ta1_x_zzzz_yyyyy_0[i] * pa_y[i] - ta1_x_zzzz_yyyyy_1[i] * pc_y[i];

        ta1_x_yzzzz_yyyyz_0[i] = 4.0 * ta1_x_zzzz_yyyz_0[i] * fe_0 - 4.0 * ta1_x_zzzz_yyyz_1[i] * fe_0 + ta1_x_zzzz_yyyyz_0[i] * pa_y[i] - ta1_x_zzzz_yyyyz_1[i] * pc_y[i];

        ta1_x_yzzzz_yyyzz_0[i] = 3.0 * ta1_x_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_yyzz_1[i] * fe_0 + ta1_x_zzzz_yyyzz_0[i] * pa_y[i] - ta1_x_zzzz_yyyzz_1[i] * pc_y[i];

        ta1_x_yzzzz_yyzzz_0[i] = 2.0 * ta1_x_zzzz_yzzz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_yzzz_1[i] * fe_0 + ta1_x_zzzz_yyzzz_0[i] * pa_y[i] - ta1_x_zzzz_yyzzz_1[i] * pc_y[i];

        ta1_x_yzzzz_yzzzz_0[i] = ta1_x_zzzz_zzzz_0[i] * fe_0 - ta1_x_zzzz_zzzz_1[i] * fe_0 + ta1_x_zzzz_yzzzz_0[i] * pa_y[i] - ta1_x_zzzz_yzzzz_1[i] * pc_y[i];

        ta1_x_yzzzz_zzzzz_0[i] = ta1_x_zzzz_zzzzz_0[i] * pa_y[i] - ta1_x_zzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 420-441 components of targeted buffer : HH

    auto ta1_x_zzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 420);

    auto ta1_x_zzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 421);

    auto ta1_x_zzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 422);

    auto ta1_x_zzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 423);

    auto ta1_x_zzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 424);

    auto ta1_x_zzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 425);

    auto ta1_x_zzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 426);

    auto ta1_x_zzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 427);

    auto ta1_x_zzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 428);

    auto ta1_x_zzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 429);

    auto ta1_x_zzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 430);

    auto ta1_x_zzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 431);

    auto ta1_x_zzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 432);

    auto ta1_x_zzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 433);

    auto ta1_x_zzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 434);

    auto ta1_x_zzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 435);

    auto ta1_x_zzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 436);

    auto ta1_x_zzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 437);

    auto ta1_x_zzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 438);

    auto ta1_x_zzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 439);

    auto ta1_x_zzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 440);

    #pragma omp simd aligned(pa_z, pc_z, ta1_x_zzz_xxxxx_0, ta1_x_zzz_xxxxx_1, ta1_x_zzz_xxxxy_0, ta1_x_zzz_xxxxy_1, ta1_x_zzz_xxxxz_0, ta1_x_zzz_xxxxz_1, ta1_x_zzz_xxxyy_0, ta1_x_zzz_xxxyy_1, ta1_x_zzz_xxxyz_0, ta1_x_zzz_xxxyz_1, ta1_x_zzz_xxxzz_0, ta1_x_zzz_xxxzz_1, ta1_x_zzz_xxyyy_0, ta1_x_zzz_xxyyy_1, ta1_x_zzz_xxyyz_0, ta1_x_zzz_xxyyz_1, ta1_x_zzz_xxyzz_0, ta1_x_zzz_xxyzz_1, ta1_x_zzz_xxzzz_0, ta1_x_zzz_xxzzz_1, ta1_x_zzz_xyyyy_0, ta1_x_zzz_xyyyy_1, ta1_x_zzz_xyyyz_0, ta1_x_zzz_xyyyz_1, ta1_x_zzz_xyyzz_0, ta1_x_zzz_xyyzz_1, ta1_x_zzz_xyzzz_0, ta1_x_zzz_xyzzz_1, ta1_x_zzz_xzzzz_0, ta1_x_zzz_xzzzz_1, ta1_x_zzz_yyyyy_0, ta1_x_zzz_yyyyy_1, ta1_x_zzz_yyyyz_0, ta1_x_zzz_yyyyz_1, ta1_x_zzz_yyyzz_0, ta1_x_zzz_yyyzz_1, ta1_x_zzz_yyzzz_0, ta1_x_zzz_yyzzz_1, ta1_x_zzz_yzzzz_0, ta1_x_zzz_yzzzz_1, ta1_x_zzz_zzzzz_0, ta1_x_zzz_zzzzz_1, ta1_x_zzzz_xxxx_0, ta1_x_zzzz_xxxx_1, ta1_x_zzzz_xxxxx_0, ta1_x_zzzz_xxxxx_1, ta1_x_zzzz_xxxxy_0, ta1_x_zzzz_xxxxy_1, ta1_x_zzzz_xxxxz_0, ta1_x_zzzz_xxxxz_1, ta1_x_zzzz_xxxy_0, ta1_x_zzzz_xxxy_1, ta1_x_zzzz_xxxyy_0, ta1_x_zzzz_xxxyy_1, ta1_x_zzzz_xxxyz_0, ta1_x_zzzz_xxxyz_1, ta1_x_zzzz_xxxz_0, ta1_x_zzzz_xxxz_1, ta1_x_zzzz_xxxzz_0, ta1_x_zzzz_xxxzz_1, ta1_x_zzzz_xxyy_0, ta1_x_zzzz_xxyy_1, ta1_x_zzzz_xxyyy_0, ta1_x_zzzz_xxyyy_1, ta1_x_zzzz_xxyyz_0, ta1_x_zzzz_xxyyz_1, ta1_x_zzzz_xxyz_0, ta1_x_zzzz_xxyz_1, ta1_x_zzzz_xxyzz_0, ta1_x_zzzz_xxyzz_1, ta1_x_zzzz_xxzz_0, ta1_x_zzzz_xxzz_1, ta1_x_zzzz_xxzzz_0, ta1_x_zzzz_xxzzz_1, ta1_x_zzzz_xyyy_0, ta1_x_zzzz_xyyy_1, ta1_x_zzzz_xyyyy_0, ta1_x_zzzz_xyyyy_1, ta1_x_zzzz_xyyyz_0, ta1_x_zzzz_xyyyz_1, ta1_x_zzzz_xyyz_0, ta1_x_zzzz_xyyz_1, ta1_x_zzzz_xyyzz_0, ta1_x_zzzz_xyyzz_1, ta1_x_zzzz_xyzz_0, ta1_x_zzzz_xyzz_1, ta1_x_zzzz_xyzzz_0, ta1_x_zzzz_xyzzz_1, ta1_x_zzzz_xzzz_0, ta1_x_zzzz_xzzz_1, ta1_x_zzzz_xzzzz_0, ta1_x_zzzz_xzzzz_1, ta1_x_zzzz_yyyy_0, ta1_x_zzzz_yyyy_1, ta1_x_zzzz_yyyyy_0, ta1_x_zzzz_yyyyy_1, ta1_x_zzzz_yyyyz_0, ta1_x_zzzz_yyyyz_1, ta1_x_zzzz_yyyz_0, ta1_x_zzzz_yyyz_1, ta1_x_zzzz_yyyzz_0, ta1_x_zzzz_yyyzz_1, ta1_x_zzzz_yyzz_0, ta1_x_zzzz_yyzz_1, ta1_x_zzzz_yyzzz_0, ta1_x_zzzz_yyzzz_1, ta1_x_zzzz_yzzz_0, ta1_x_zzzz_yzzz_1, ta1_x_zzzz_yzzzz_0, ta1_x_zzzz_yzzzz_1, ta1_x_zzzz_zzzz_0, ta1_x_zzzz_zzzz_1, ta1_x_zzzz_zzzzz_0, ta1_x_zzzz_zzzzz_1, ta1_x_zzzzz_xxxxx_0, ta1_x_zzzzz_xxxxy_0, ta1_x_zzzzz_xxxxz_0, ta1_x_zzzzz_xxxyy_0, ta1_x_zzzzz_xxxyz_0, ta1_x_zzzzz_xxxzz_0, ta1_x_zzzzz_xxyyy_0, ta1_x_zzzzz_xxyyz_0, ta1_x_zzzzz_xxyzz_0, ta1_x_zzzzz_xxzzz_0, ta1_x_zzzzz_xyyyy_0, ta1_x_zzzzz_xyyyz_0, ta1_x_zzzzz_xyyzz_0, ta1_x_zzzzz_xyzzz_0, ta1_x_zzzzz_xzzzz_0, ta1_x_zzzzz_yyyyy_0, ta1_x_zzzzz_yyyyz_0, ta1_x_zzzzz_yyyzz_0, ta1_x_zzzzz_yyzzz_0, ta1_x_zzzzz_yzzzz_0, ta1_x_zzzzz_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_x_zzzzz_xxxxx_0[i] = 4.0 * ta1_x_zzz_xxxxx_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxxx_1[i] * fe_0 + ta1_x_zzzz_xxxxx_0[i] * pa_z[i] - ta1_x_zzzz_xxxxx_1[i] * pc_z[i];

        ta1_x_zzzzz_xxxxy_0[i] = 4.0 * ta1_x_zzz_xxxxy_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxxy_1[i] * fe_0 + ta1_x_zzzz_xxxxy_0[i] * pa_z[i] - ta1_x_zzzz_xxxxy_1[i] * pc_z[i];

        ta1_x_zzzzz_xxxxz_0[i] = 4.0 * ta1_x_zzz_xxxxz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxxz_1[i] * fe_0 + ta1_x_zzzz_xxxx_0[i] * fe_0 - ta1_x_zzzz_xxxx_1[i] * fe_0 + ta1_x_zzzz_xxxxz_0[i] * pa_z[i] - ta1_x_zzzz_xxxxz_1[i] * pc_z[i];

        ta1_x_zzzzz_xxxyy_0[i] = 4.0 * ta1_x_zzz_xxxyy_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxyy_1[i] * fe_0 + ta1_x_zzzz_xxxyy_0[i] * pa_z[i] - ta1_x_zzzz_xxxyy_1[i] * pc_z[i];

        ta1_x_zzzzz_xxxyz_0[i] = 4.0 * ta1_x_zzz_xxxyz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxyz_1[i] * fe_0 + ta1_x_zzzz_xxxy_0[i] * fe_0 - ta1_x_zzzz_xxxy_1[i] * fe_0 + ta1_x_zzzz_xxxyz_0[i] * pa_z[i] - ta1_x_zzzz_xxxyz_1[i] * pc_z[i];

        ta1_x_zzzzz_xxxzz_0[i] = 4.0 * ta1_x_zzz_xxxzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxxzz_1[i] * fe_0 + 2.0 * ta1_x_zzzz_xxxz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xxxz_1[i] * fe_0 + ta1_x_zzzz_xxxzz_0[i] * pa_z[i] - ta1_x_zzzz_xxxzz_1[i] * pc_z[i];

        ta1_x_zzzzz_xxyyy_0[i] = 4.0 * ta1_x_zzz_xxyyy_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxyyy_1[i] * fe_0 + ta1_x_zzzz_xxyyy_0[i] * pa_z[i] - ta1_x_zzzz_xxyyy_1[i] * pc_z[i];

        ta1_x_zzzzz_xxyyz_0[i] = 4.0 * ta1_x_zzz_xxyyz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxyyz_1[i] * fe_0 + ta1_x_zzzz_xxyy_0[i] * fe_0 - ta1_x_zzzz_xxyy_1[i] * fe_0 + ta1_x_zzzz_xxyyz_0[i] * pa_z[i] - ta1_x_zzzz_xxyyz_1[i] * pc_z[i];

        ta1_x_zzzzz_xxyzz_0[i] = 4.0 * ta1_x_zzz_xxyzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_x_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xxyz_1[i] * fe_0 + ta1_x_zzzz_xxyzz_0[i] * pa_z[i] - ta1_x_zzzz_xxyzz_1[i] * pc_z[i];

        ta1_x_zzzzz_xxzzz_0[i] = 4.0 * ta1_x_zzz_xxzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xxzzz_1[i] * fe_0 + 3.0 * ta1_x_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xxzz_1[i] * fe_0 + ta1_x_zzzz_xxzzz_0[i] * pa_z[i] - ta1_x_zzzz_xxzzz_1[i] * pc_z[i];

        ta1_x_zzzzz_xyyyy_0[i] = 4.0 * ta1_x_zzz_xyyyy_0[i] * fe_0 - 4.0 * ta1_x_zzz_xyyyy_1[i] * fe_0 + ta1_x_zzzz_xyyyy_0[i] * pa_z[i] - ta1_x_zzzz_xyyyy_1[i] * pc_z[i];

        ta1_x_zzzzz_xyyyz_0[i] = 4.0 * ta1_x_zzz_xyyyz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xyyyz_1[i] * fe_0 + ta1_x_zzzz_xyyy_0[i] * fe_0 - ta1_x_zzzz_xyyy_1[i] * fe_0 + ta1_x_zzzz_xyyyz_0[i] * pa_z[i] - ta1_x_zzzz_xyyyz_1[i] * pc_z[i];

        ta1_x_zzzzz_xyyzz_0[i] = 4.0 * ta1_x_zzz_xyyzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_x_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_xyyz_1[i] * fe_0 + ta1_x_zzzz_xyyzz_0[i] * pa_z[i] - ta1_x_zzzz_xyyzz_1[i] * pc_z[i];

        ta1_x_zzzzz_xyzzz_0[i] = 4.0 * ta1_x_zzz_xyzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xyzzz_1[i] * fe_0 + 3.0 * ta1_x_zzzz_xyzz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_xyzz_1[i] * fe_0 + ta1_x_zzzz_xyzzz_0[i] * pa_z[i] - ta1_x_zzzz_xyzzz_1[i] * pc_z[i];

        ta1_x_zzzzz_xzzzz_0[i] = 4.0 * ta1_x_zzz_xzzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_xzzzz_1[i] * fe_0 + 4.0 * ta1_x_zzzz_xzzz_0[i] * fe_0 - 4.0 * ta1_x_zzzz_xzzz_1[i] * fe_0 + ta1_x_zzzz_xzzzz_0[i] * pa_z[i] - ta1_x_zzzz_xzzzz_1[i] * pc_z[i];

        ta1_x_zzzzz_yyyyy_0[i] = 4.0 * ta1_x_zzz_yyyyy_0[i] * fe_0 - 4.0 * ta1_x_zzz_yyyyy_1[i] * fe_0 + ta1_x_zzzz_yyyyy_0[i] * pa_z[i] - ta1_x_zzzz_yyyyy_1[i] * pc_z[i];

        ta1_x_zzzzz_yyyyz_0[i] = 4.0 * ta1_x_zzz_yyyyz_0[i] * fe_0 - 4.0 * ta1_x_zzz_yyyyz_1[i] * fe_0 + ta1_x_zzzz_yyyy_0[i] * fe_0 - ta1_x_zzzz_yyyy_1[i] * fe_0 + ta1_x_zzzz_yyyyz_0[i] * pa_z[i] - ta1_x_zzzz_yyyyz_1[i] * pc_z[i];

        ta1_x_zzzzz_yyyzz_0[i] = 4.0 * ta1_x_zzz_yyyzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_yyyzz_1[i] * fe_0 + 2.0 * ta1_x_zzzz_yyyz_0[i] * fe_0 - 2.0 * ta1_x_zzzz_yyyz_1[i] * fe_0 + ta1_x_zzzz_yyyzz_0[i] * pa_z[i] - ta1_x_zzzz_yyyzz_1[i] * pc_z[i];

        ta1_x_zzzzz_yyzzz_0[i] = 4.0 * ta1_x_zzz_yyzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_yyzzz_1[i] * fe_0 + 3.0 * ta1_x_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_x_zzzz_yyzz_1[i] * fe_0 + ta1_x_zzzz_yyzzz_0[i] * pa_z[i] - ta1_x_zzzz_yyzzz_1[i] * pc_z[i];

        ta1_x_zzzzz_yzzzz_0[i] = 4.0 * ta1_x_zzz_yzzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_yzzzz_1[i] * fe_0 + 4.0 * ta1_x_zzzz_yzzz_0[i] * fe_0 - 4.0 * ta1_x_zzzz_yzzz_1[i] * fe_0 + ta1_x_zzzz_yzzzz_0[i] * pa_z[i] - ta1_x_zzzz_yzzzz_1[i] * pc_z[i];

        ta1_x_zzzzz_zzzzz_0[i] = 4.0 * ta1_x_zzz_zzzzz_0[i] * fe_0 - 4.0 * ta1_x_zzz_zzzzz_1[i] * fe_0 + 5.0 * ta1_x_zzzz_zzzz_0[i] * fe_0 - 5.0 * ta1_x_zzzz_zzzz_1[i] * fe_0 + ta1_x_zzzz_zzzzz_0[i] * pa_z[i] - ta1_x_zzzz_zzzzz_1[i] * pc_z[i];
    }

    // Set up 441-462 components of targeted buffer : HH

    auto ta1_y_xxxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 441);

    auto ta1_y_xxxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 442);

    auto ta1_y_xxxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 443);

    auto ta1_y_xxxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 444);

    auto ta1_y_xxxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 445);

    auto ta1_y_xxxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 446);

    auto ta1_y_xxxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 447);

    auto ta1_y_xxxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 448);

    auto ta1_y_xxxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 449);

    auto ta1_y_xxxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 450);

    auto ta1_y_xxxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 451);

    auto ta1_y_xxxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 452);

    auto ta1_y_xxxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 453);

    auto ta1_y_xxxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 454);

    auto ta1_y_xxxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 455);

    auto ta1_y_xxxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 456);

    auto ta1_y_xxxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 457);

    auto ta1_y_xxxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 458);

    auto ta1_y_xxxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 459);

    auto ta1_y_xxxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 460);

    auto ta1_y_xxxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 461);

    #pragma omp simd aligned(pa_x, pc_x, ta1_y_xxx_xxxxx_0, ta1_y_xxx_xxxxx_1, ta1_y_xxx_xxxxy_0, ta1_y_xxx_xxxxy_1, ta1_y_xxx_xxxxz_0, ta1_y_xxx_xxxxz_1, ta1_y_xxx_xxxyy_0, ta1_y_xxx_xxxyy_1, ta1_y_xxx_xxxyz_0, ta1_y_xxx_xxxyz_1, ta1_y_xxx_xxxzz_0, ta1_y_xxx_xxxzz_1, ta1_y_xxx_xxyyy_0, ta1_y_xxx_xxyyy_1, ta1_y_xxx_xxyyz_0, ta1_y_xxx_xxyyz_1, ta1_y_xxx_xxyzz_0, ta1_y_xxx_xxyzz_1, ta1_y_xxx_xxzzz_0, ta1_y_xxx_xxzzz_1, ta1_y_xxx_xyyyy_0, ta1_y_xxx_xyyyy_1, ta1_y_xxx_xyyyz_0, ta1_y_xxx_xyyyz_1, ta1_y_xxx_xyyzz_0, ta1_y_xxx_xyyzz_1, ta1_y_xxx_xyzzz_0, ta1_y_xxx_xyzzz_1, ta1_y_xxx_xzzzz_0, ta1_y_xxx_xzzzz_1, ta1_y_xxx_yyyyy_0, ta1_y_xxx_yyyyy_1, ta1_y_xxx_yyyyz_0, ta1_y_xxx_yyyyz_1, ta1_y_xxx_yyyzz_0, ta1_y_xxx_yyyzz_1, ta1_y_xxx_yyzzz_0, ta1_y_xxx_yyzzz_1, ta1_y_xxx_yzzzz_0, ta1_y_xxx_yzzzz_1, ta1_y_xxx_zzzzz_0, ta1_y_xxx_zzzzz_1, ta1_y_xxxx_xxxx_0, ta1_y_xxxx_xxxx_1, ta1_y_xxxx_xxxxx_0, ta1_y_xxxx_xxxxx_1, ta1_y_xxxx_xxxxy_0, ta1_y_xxxx_xxxxy_1, ta1_y_xxxx_xxxxz_0, ta1_y_xxxx_xxxxz_1, ta1_y_xxxx_xxxy_0, ta1_y_xxxx_xxxy_1, ta1_y_xxxx_xxxyy_0, ta1_y_xxxx_xxxyy_1, ta1_y_xxxx_xxxyz_0, ta1_y_xxxx_xxxyz_1, ta1_y_xxxx_xxxz_0, ta1_y_xxxx_xxxz_1, ta1_y_xxxx_xxxzz_0, ta1_y_xxxx_xxxzz_1, ta1_y_xxxx_xxyy_0, ta1_y_xxxx_xxyy_1, ta1_y_xxxx_xxyyy_0, ta1_y_xxxx_xxyyy_1, ta1_y_xxxx_xxyyz_0, ta1_y_xxxx_xxyyz_1, ta1_y_xxxx_xxyz_0, ta1_y_xxxx_xxyz_1, ta1_y_xxxx_xxyzz_0, ta1_y_xxxx_xxyzz_1, ta1_y_xxxx_xxzz_0, ta1_y_xxxx_xxzz_1, ta1_y_xxxx_xxzzz_0, ta1_y_xxxx_xxzzz_1, ta1_y_xxxx_xyyy_0, ta1_y_xxxx_xyyy_1, ta1_y_xxxx_xyyyy_0, ta1_y_xxxx_xyyyy_1, ta1_y_xxxx_xyyyz_0, ta1_y_xxxx_xyyyz_1, ta1_y_xxxx_xyyz_0, ta1_y_xxxx_xyyz_1, ta1_y_xxxx_xyyzz_0, ta1_y_xxxx_xyyzz_1, ta1_y_xxxx_xyzz_0, ta1_y_xxxx_xyzz_1, ta1_y_xxxx_xyzzz_0, ta1_y_xxxx_xyzzz_1, ta1_y_xxxx_xzzz_0, ta1_y_xxxx_xzzz_1, ta1_y_xxxx_xzzzz_0, ta1_y_xxxx_xzzzz_1, ta1_y_xxxx_yyyy_0, ta1_y_xxxx_yyyy_1, ta1_y_xxxx_yyyyy_0, ta1_y_xxxx_yyyyy_1, ta1_y_xxxx_yyyyz_0, ta1_y_xxxx_yyyyz_1, ta1_y_xxxx_yyyz_0, ta1_y_xxxx_yyyz_1, ta1_y_xxxx_yyyzz_0, ta1_y_xxxx_yyyzz_1, ta1_y_xxxx_yyzz_0, ta1_y_xxxx_yyzz_1, ta1_y_xxxx_yyzzz_0, ta1_y_xxxx_yyzzz_1, ta1_y_xxxx_yzzz_0, ta1_y_xxxx_yzzz_1, ta1_y_xxxx_yzzzz_0, ta1_y_xxxx_yzzzz_1, ta1_y_xxxx_zzzz_0, ta1_y_xxxx_zzzz_1, ta1_y_xxxx_zzzzz_0, ta1_y_xxxx_zzzzz_1, ta1_y_xxxxx_xxxxx_0, ta1_y_xxxxx_xxxxy_0, ta1_y_xxxxx_xxxxz_0, ta1_y_xxxxx_xxxyy_0, ta1_y_xxxxx_xxxyz_0, ta1_y_xxxxx_xxxzz_0, ta1_y_xxxxx_xxyyy_0, ta1_y_xxxxx_xxyyz_0, ta1_y_xxxxx_xxyzz_0, ta1_y_xxxxx_xxzzz_0, ta1_y_xxxxx_xyyyy_0, ta1_y_xxxxx_xyyyz_0, ta1_y_xxxxx_xyyzz_0, ta1_y_xxxxx_xyzzz_0, ta1_y_xxxxx_xzzzz_0, ta1_y_xxxxx_yyyyy_0, ta1_y_xxxxx_yyyyz_0, ta1_y_xxxxx_yyyzz_0, ta1_y_xxxxx_yyzzz_0, ta1_y_xxxxx_yzzzz_0, ta1_y_xxxxx_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxxx_xxxxx_0[i] = 4.0 * ta1_y_xxx_xxxxx_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxxx_1[i] * fe_0 + 5.0 * ta1_y_xxxx_xxxx_0[i] * fe_0 - 5.0 * ta1_y_xxxx_xxxx_1[i] * fe_0 + ta1_y_xxxx_xxxxx_0[i] * pa_x[i] - ta1_y_xxxx_xxxxx_1[i] * pc_x[i];

        ta1_y_xxxxx_xxxxy_0[i] = 4.0 * ta1_y_xxx_xxxxy_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxxy_1[i] * fe_0 + 4.0 * ta1_y_xxxx_xxxy_0[i] * fe_0 - 4.0 * ta1_y_xxxx_xxxy_1[i] * fe_0 + ta1_y_xxxx_xxxxy_0[i] * pa_x[i] - ta1_y_xxxx_xxxxy_1[i] * pc_x[i];

        ta1_y_xxxxx_xxxxz_0[i] = 4.0 * ta1_y_xxx_xxxxz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxxz_1[i] * fe_0 + 4.0 * ta1_y_xxxx_xxxz_0[i] * fe_0 - 4.0 * ta1_y_xxxx_xxxz_1[i] * fe_0 + ta1_y_xxxx_xxxxz_0[i] * pa_x[i] - ta1_y_xxxx_xxxxz_1[i] * pc_x[i];

        ta1_y_xxxxx_xxxyy_0[i] = 4.0 * ta1_y_xxx_xxxyy_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxyy_1[i] * fe_0 + 3.0 * ta1_y_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xxyy_1[i] * fe_0 + ta1_y_xxxx_xxxyy_0[i] * pa_x[i] - ta1_y_xxxx_xxxyy_1[i] * pc_x[i];

        ta1_y_xxxxx_xxxyz_0[i] = 4.0 * ta1_y_xxx_xxxyz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxyz_1[i] * fe_0 + 3.0 * ta1_y_xxxx_xxyz_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xxyz_1[i] * fe_0 + ta1_y_xxxx_xxxyz_0[i] * pa_x[i] - ta1_y_xxxx_xxxyz_1[i] * pc_x[i];

        ta1_y_xxxxx_xxxzz_0[i] = 4.0 * ta1_y_xxx_xxxzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxxzz_1[i] * fe_0 + 3.0 * ta1_y_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xxzz_1[i] * fe_0 + ta1_y_xxxx_xxxzz_0[i] * pa_x[i] - ta1_y_xxxx_xxxzz_1[i] * pc_x[i];

        ta1_y_xxxxx_xxyyy_0[i] = 4.0 * ta1_y_xxx_xxyyy_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxyyy_1[i] * fe_0 + 2.0 * ta1_y_xxxx_xyyy_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xyyy_1[i] * fe_0 + ta1_y_xxxx_xxyyy_0[i] * pa_x[i] - ta1_y_xxxx_xxyyy_1[i] * pc_x[i];

        ta1_y_xxxxx_xxyyz_0[i] = 4.0 * ta1_y_xxx_xxyyz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xyyz_1[i] * fe_0 + ta1_y_xxxx_xxyyz_0[i] * pa_x[i] - ta1_y_xxxx_xxyyz_1[i] * pc_x[i];

        ta1_y_xxxxx_xxyzz_0[i] = 4.0 * ta1_y_xxx_xxyzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xyzz_1[i] * fe_0 + ta1_y_xxxx_xxyzz_0[i] * pa_x[i] - ta1_y_xxxx_xxyzz_1[i] * pc_x[i];

        ta1_y_xxxxx_xxzzz_0[i] = 4.0 * ta1_y_xxx_xxzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xxzzz_1[i] * fe_0 + 2.0 * ta1_y_xxxx_xzzz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xzzz_1[i] * fe_0 + ta1_y_xxxx_xxzzz_0[i] * pa_x[i] - ta1_y_xxxx_xxzzz_1[i] * pc_x[i];

        ta1_y_xxxxx_xyyyy_0[i] = 4.0 * ta1_y_xxx_xyyyy_0[i] * fe_0 - 4.0 * ta1_y_xxx_xyyyy_1[i] * fe_0 + ta1_y_xxxx_yyyy_0[i] * fe_0 - ta1_y_xxxx_yyyy_1[i] * fe_0 + ta1_y_xxxx_xyyyy_0[i] * pa_x[i] - ta1_y_xxxx_xyyyy_1[i] * pc_x[i];

        ta1_y_xxxxx_xyyyz_0[i] = 4.0 * ta1_y_xxx_xyyyz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xyyyz_1[i] * fe_0 + ta1_y_xxxx_yyyz_0[i] * fe_0 - ta1_y_xxxx_yyyz_1[i] * fe_0 + ta1_y_xxxx_xyyyz_0[i] * pa_x[i] - ta1_y_xxxx_xyyyz_1[i] * pc_x[i];

        ta1_y_xxxxx_xyyzz_0[i] = 4.0 * ta1_y_xxx_xyyzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xyyzz_1[i] * fe_0 + ta1_y_xxxx_yyzz_0[i] * fe_0 - ta1_y_xxxx_yyzz_1[i] * fe_0 + ta1_y_xxxx_xyyzz_0[i] * pa_x[i] - ta1_y_xxxx_xyyzz_1[i] * pc_x[i];

        ta1_y_xxxxx_xyzzz_0[i] = 4.0 * ta1_y_xxx_xyzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xyzzz_1[i] * fe_0 + ta1_y_xxxx_yzzz_0[i] * fe_0 - ta1_y_xxxx_yzzz_1[i] * fe_0 + ta1_y_xxxx_xyzzz_0[i] * pa_x[i] - ta1_y_xxxx_xyzzz_1[i] * pc_x[i];

        ta1_y_xxxxx_xzzzz_0[i] = 4.0 * ta1_y_xxx_xzzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_xzzzz_1[i] * fe_0 + ta1_y_xxxx_zzzz_0[i] * fe_0 - ta1_y_xxxx_zzzz_1[i] * fe_0 + ta1_y_xxxx_xzzzz_0[i] * pa_x[i] - ta1_y_xxxx_xzzzz_1[i] * pc_x[i];

        ta1_y_xxxxx_yyyyy_0[i] = 4.0 * ta1_y_xxx_yyyyy_0[i] * fe_0 - 4.0 * ta1_y_xxx_yyyyy_1[i] * fe_0 + ta1_y_xxxx_yyyyy_0[i] * pa_x[i] - ta1_y_xxxx_yyyyy_1[i] * pc_x[i];

        ta1_y_xxxxx_yyyyz_0[i] = 4.0 * ta1_y_xxx_yyyyz_0[i] * fe_0 - 4.0 * ta1_y_xxx_yyyyz_1[i] * fe_0 + ta1_y_xxxx_yyyyz_0[i] * pa_x[i] - ta1_y_xxxx_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxxx_yyyzz_0[i] = 4.0 * ta1_y_xxx_yyyzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_yyyzz_1[i] * fe_0 + ta1_y_xxxx_yyyzz_0[i] * pa_x[i] - ta1_y_xxxx_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxxx_yyzzz_0[i] = 4.0 * ta1_y_xxx_yyzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_yyzzz_1[i] * fe_0 + ta1_y_xxxx_yyzzz_0[i] * pa_x[i] - ta1_y_xxxx_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxxx_yzzzz_0[i] = 4.0 * ta1_y_xxx_yzzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_yzzzz_1[i] * fe_0 + ta1_y_xxxx_yzzzz_0[i] * pa_x[i] - ta1_y_xxxx_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxxx_zzzzz_0[i] = 4.0 * ta1_y_xxx_zzzzz_0[i] * fe_0 - 4.0 * ta1_y_xxx_zzzzz_1[i] * fe_0 + ta1_y_xxxx_zzzzz_0[i] * pa_x[i] - ta1_y_xxxx_zzzzz_1[i] * pc_x[i];
    }

    // Set up 462-483 components of targeted buffer : HH

    auto ta1_y_xxxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 462);

    auto ta1_y_xxxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 463);

    auto ta1_y_xxxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 464);

    auto ta1_y_xxxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 465);

    auto ta1_y_xxxxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 466);

    auto ta1_y_xxxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 467);

    auto ta1_y_xxxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 468);

    auto ta1_y_xxxxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 469);

    auto ta1_y_xxxxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 470);

    auto ta1_y_xxxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 471);

    auto ta1_y_xxxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 472);

    auto ta1_y_xxxxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 473);

    auto ta1_y_xxxxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 474);

    auto ta1_y_xxxxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 475);

    auto ta1_y_xxxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 476);

    auto ta1_y_xxxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 477);

    auto ta1_y_xxxxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 478);

    auto ta1_y_xxxxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 479);

    auto ta1_y_xxxxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 480);

    auto ta1_y_xxxxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 481);

    auto ta1_y_xxxxy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 482);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_y_xxxx_xxxx_0, ta1_y_xxxx_xxxx_1, ta1_y_xxxx_xxxxx_0, ta1_y_xxxx_xxxxx_1, ta1_y_xxxx_xxxxy_0, ta1_y_xxxx_xxxxy_1, ta1_y_xxxx_xxxxz_0, ta1_y_xxxx_xxxxz_1, ta1_y_xxxx_xxxy_0, ta1_y_xxxx_xxxy_1, ta1_y_xxxx_xxxyy_0, ta1_y_xxxx_xxxyy_1, ta1_y_xxxx_xxxyz_0, ta1_y_xxxx_xxxyz_1, ta1_y_xxxx_xxxz_0, ta1_y_xxxx_xxxz_1, ta1_y_xxxx_xxxzz_0, ta1_y_xxxx_xxxzz_1, ta1_y_xxxx_xxyy_0, ta1_y_xxxx_xxyy_1, ta1_y_xxxx_xxyyy_0, ta1_y_xxxx_xxyyy_1, ta1_y_xxxx_xxyyz_0, ta1_y_xxxx_xxyyz_1, ta1_y_xxxx_xxyz_0, ta1_y_xxxx_xxyz_1, ta1_y_xxxx_xxyzz_0, ta1_y_xxxx_xxyzz_1, ta1_y_xxxx_xxzz_0, ta1_y_xxxx_xxzz_1, ta1_y_xxxx_xxzzz_0, ta1_y_xxxx_xxzzz_1, ta1_y_xxxx_xyyy_0, ta1_y_xxxx_xyyy_1, ta1_y_xxxx_xyyyy_0, ta1_y_xxxx_xyyyy_1, ta1_y_xxxx_xyyyz_0, ta1_y_xxxx_xyyyz_1, ta1_y_xxxx_xyyz_0, ta1_y_xxxx_xyyz_1, ta1_y_xxxx_xyyzz_0, ta1_y_xxxx_xyyzz_1, ta1_y_xxxx_xyzz_0, ta1_y_xxxx_xyzz_1, ta1_y_xxxx_xyzzz_0, ta1_y_xxxx_xyzzz_1, ta1_y_xxxx_xzzz_0, ta1_y_xxxx_xzzz_1, ta1_y_xxxx_xzzzz_0, ta1_y_xxxx_xzzzz_1, ta1_y_xxxx_zzzzz_0, ta1_y_xxxx_zzzzz_1, ta1_y_xxxxy_xxxxx_0, ta1_y_xxxxy_xxxxy_0, ta1_y_xxxxy_xxxxz_0, ta1_y_xxxxy_xxxyy_0, ta1_y_xxxxy_xxxyz_0, ta1_y_xxxxy_xxxzz_0, ta1_y_xxxxy_xxyyy_0, ta1_y_xxxxy_xxyyz_0, ta1_y_xxxxy_xxyzz_0, ta1_y_xxxxy_xxzzz_0, ta1_y_xxxxy_xyyyy_0, ta1_y_xxxxy_xyyyz_0, ta1_y_xxxxy_xyyzz_0, ta1_y_xxxxy_xyzzz_0, ta1_y_xxxxy_xzzzz_0, ta1_y_xxxxy_yyyyy_0, ta1_y_xxxxy_yyyyz_0, ta1_y_xxxxy_yyyzz_0, ta1_y_xxxxy_yyzzz_0, ta1_y_xxxxy_yzzzz_0, ta1_y_xxxxy_zzzzz_0, ta1_y_xxxy_yyyyy_0, ta1_y_xxxy_yyyyy_1, ta1_y_xxxy_yyyyz_0, ta1_y_xxxy_yyyyz_1, ta1_y_xxxy_yyyzz_0, ta1_y_xxxy_yyyzz_1, ta1_y_xxxy_yyzzz_0, ta1_y_xxxy_yyzzz_1, ta1_y_xxxy_yzzzz_0, ta1_y_xxxy_yzzzz_1, ta1_y_xxy_yyyyy_0, ta1_y_xxy_yyyyy_1, ta1_y_xxy_yyyyz_0, ta1_y_xxy_yyyyz_1, ta1_y_xxy_yyyzz_0, ta1_y_xxy_yyyzz_1, ta1_y_xxy_yyzzz_0, ta1_y_xxy_yyzzz_1, ta1_y_xxy_yzzzz_0, ta1_y_xxy_yzzzz_1, ta_xxxx_xxxxx_1, ta_xxxx_xxxxy_1, ta_xxxx_xxxxz_1, ta_xxxx_xxxyy_1, ta_xxxx_xxxyz_1, ta_xxxx_xxxzz_1, ta_xxxx_xxyyy_1, ta_xxxx_xxyyz_1, ta_xxxx_xxyzz_1, ta_xxxx_xxzzz_1, ta_xxxx_xyyyy_1, ta_xxxx_xyyyz_1, ta_xxxx_xyyzz_1, ta_xxxx_xyzzz_1, ta_xxxx_xzzzz_1, ta_xxxx_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxxy_xxxxx_0[i] = ta_xxxx_xxxxx_1[i] + ta1_y_xxxx_xxxxx_0[i] * pa_y[i] - ta1_y_xxxx_xxxxx_1[i] * pc_y[i];

        ta1_y_xxxxy_xxxxy_0[i] = ta1_y_xxxx_xxxx_0[i] * fe_0 - ta1_y_xxxx_xxxx_1[i] * fe_0 + ta_xxxx_xxxxy_1[i] + ta1_y_xxxx_xxxxy_0[i] * pa_y[i] - ta1_y_xxxx_xxxxy_1[i] * pc_y[i];

        ta1_y_xxxxy_xxxxz_0[i] = ta_xxxx_xxxxz_1[i] + ta1_y_xxxx_xxxxz_0[i] * pa_y[i] - ta1_y_xxxx_xxxxz_1[i] * pc_y[i];

        ta1_y_xxxxy_xxxyy_0[i] = 2.0 * ta1_y_xxxx_xxxy_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xxxy_1[i] * fe_0 + ta_xxxx_xxxyy_1[i] + ta1_y_xxxx_xxxyy_0[i] * pa_y[i] - ta1_y_xxxx_xxxyy_1[i] * pc_y[i];

        ta1_y_xxxxy_xxxyz_0[i] = ta1_y_xxxx_xxxz_0[i] * fe_0 - ta1_y_xxxx_xxxz_1[i] * fe_0 + ta_xxxx_xxxyz_1[i] + ta1_y_xxxx_xxxyz_0[i] * pa_y[i] - ta1_y_xxxx_xxxyz_1[i] * pc_y[i];

        ta1_y_xxxxy_xxxzz_0[i] = ta_xxxx_xxxzz_1[i] + ta1_y_xxxx_xxxzz_0[i] * pa_y[i] - ta1_y_xxxx_xxxzz_1[i] * pc_y[i];

        ta1_y_xxxxy_xxyyy_0[i] = 3.0 * ta1_y_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xxyy_1[i] * fe_0 + ta_xxxx_xxyyy_1[i] + ta1_y_xxxx_xxyyy_0[i] * pa_y[i] - ta1_y_xxxx_xxyyy_1[i] * pc_y[i];

        ta1_y_xxxxy_xxyyz_0[i] = 2.0 * ta1_y_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xxyz_1[i] * fe_0 + ta_xxxx_xxyyz_1[i] + ta1_y_xxxx_xxyyz_0[i] * pa_y[i] - ta1_y_xxxx_xxyyz_1[i] * pc_y[i];

        ta1_y_xxxxy_xxyzz_0[i] = ta1_y_xxxx_xxzz_0[i] * fe_0 - ta1_y_xxxx_xxzz_1[i] * fe_0 + ta_xxxx_xxyzz_1[i] + ta1_y_xxxx_xxyzz_0[i] * pa_y[i] - ta1_y_xxxx_xxyzz_1[i] * pc_y[i];

        ta1_y_xxxxy_xxzzz_0[i] = ta_xxxx_xxzzz_1[i] + ta1_y_xxxx_xxzzz_0[i] * pa_y[i] - ta1_y_xxxx_xxzzz_1[i] * pc_y[i];

        ta1_y_xxxxy_xyyyy_0[i] = 4.0 * ta1_y_xxxx_xyyy_0[i] * fe_0 - 4.0 * ta1_y_xxxx_xyyy_1[i] * fe_0 + ta_xxxx_xyyyy_1[i] + ta1_y_xxxx_xyyyy_0[i] * pa_y[i] - ta1_y_xxxx_xyyyy_1[i] * pc_y[i];

        ta1_y_xxxxy_xyyyz_0[i] = 3.0 * ta1_y_xxxx_xyyz_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xyyz_1[i] * fe_0 + ta_xxxx_xyyyz_1[i] + ta1_y_xxxx_xyyyz_0[i] * pa_y[i] - ta1_y_xxxx_xyyyz_1[i] * pc_y[i];

        ta1_y_xxxxy_xyyzz_0[i] = 2.0 * ta1_y_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xyzz_1[i] * fe_0 + ta_xxxx_xyyzz_1[i] + ta1_y_xxxx_xyyzz_0[i] * pa_y[i] - ta1_y_xxxx_xyyzz_1[i] * pc_y[i];

        ta1_y_xxxxy_xyzzz_0[i] = ta1_y_xxxx_xzzz_0[i] * fe_0 - ta1_y_xxxx_xzzz_1[i] * fe_0 + ta_xxxx_xyzzz_1[i] + ta1_y_xxxx_xyzzz_0[i] * pa_y[i] - ta1_y_xxxx_xyzzz_1[i] * pc_y[i];

        ta1_y_xxxxy_xzzzz_0[i] = ta_xxxx_xzzzz_1[i] + ta1_y_xxxx_xzzzz_0[i] * pa_y[i] - ta1_y_xxxx_xzzzz_1[i] * pc_y[i];

        ta1_y_xxxxy_yyyyy_0[i] = 3.0 * ta1_y_xxy_yyyyy_0[i] * fe_0 - 3.0 * ta1_y_xxy_yyyyy_1[i] * fe_0 + ta1_y_xxxy_yyyyy_0[i] * pa_x[i] - ta1_y_xxxy_yyyyy_1[i] * pc_x[i];

        ta1_y_xxxxy_yyyyz_0[i] = 3.0 * ta1_y_xxy_yyyyz_0[i] * fe_0 - 3.0 * ta1_y_xxy_yyyyz_1[i] * fe_0 + ta1_y_xxxy_yyyyz_0[i] * pa_x[i] - ta1_y_xxxy_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxxy_yyyzz_0[i] = 3.0 * ta1_y_xxy_yyyzz_0[i] * fe_0 - 3.0 * ta1_y_xxy_yyyzz_1[i] * fe_0 + ta1_y_xxxy_yyyzz_0[i] * pa_x[i] - ta1_y_xxxy_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxxy_yyzzz_0[i] = 3.0 * ta1_y_xxy_yyzzz_0[i] * fe_0 - 3.0 * ta1_y_xxy_yyzzz_1[i] * fe_0 + ta1_y_xxxy_yyzzz_0[i] * pa_x[i] - ta1_y_xxxy_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxxy_yzzzz_0[i] = 3.0 * ta1_y_xxy_yzzzz_0[i] * fe_0 - 3.0 * ta1_y_xxy_yzzzz_1[i] * fe_0 + ta1_y_xxxy_yzzzz_0[i] * pa_x[i] - ta1_y_xxxy_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxxy_zzzzz_0[i] = ta_xxxx_zzzzz_1[i] + ta1_y_xxxx_zzzzz_0[i] * pa_y[i] - ta1_y_xxxx_zzzzz_1[i] * pc_y[i];
    }

    // Set up 483-504 components of targeted buffer : HH

    auto ta1_y_xxxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 483);

    auto ta1_y_xxxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 484);

    auto ta1_y_xxxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 485);

    auto ta1_y_xxxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 486);

    auto ta1_y_xxxxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 487);

    auto ta1_y_xxxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 488);

    auto ta1_y_xxxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 489);

    auto ta1_y_xxxxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 490);

    auto ta1_y_xxxxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 491);

    auto ta1_y_xxxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 492);

    auto ta1_y_xxxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 493);

    auto ta1_y_xxxxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 494);

    auto ta1_y_xxxxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 495);

    auto ta1_y_xxxxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 496);

    auto ta1_y_xxxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 497);

    auto ta1_y_xxxxz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 498);

    auto ta1_y_xxxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 499);

    auto ta1_y_xxxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 500);

    auto ta1_y_xxxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 501);

    auto ta1_y_xxxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 502);

    auto ta1_y_xxxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 503);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_y_xxxx_xxxx_0, ta1_y_xxxx_xxxx_1, ta1_y_xxxx_xxxxx_0, ta1_y_xxxx_xxxxx_1, ta1_y_xxxx_xxxxy_0, ta1_y_xxxx_xxxxy_1, ta1_y_xxxx_xxxxz_0, ta1_y_xxxx_xxxxz_1, ta1_y_xxxx_xxxy_0, ta1_y_xxxx_xxxy_1, ta1_y_xxxx_xxxyy_0, ta1_y_xxxx_xxxyy_1, ta1_y_xxxx_xxxyz_0, ta1_y_xxxx_xxxyz_1, ta1_y_xxxx_xxxz_0, ta1_y_xxxx_xxxz_1, ta1_y_xxxx_xxxzz_0, ta1_y_xxxx_xxxzz_1, ta1_y_xxxx_xxyy_0, ta1_y_xxxx_xxyy_1, ta1_y_xxxx_xxyyy_0, ta1_y_xxxx_xxyyy_1, ta1_y_xxxx_xxyyz_0, ta1_y_xxxx_xxyyz_1, ta1_y_xxxx_xxyz_0, ta1_y_xxxx_xxyz_1, ta1_y_xxxx_xxyzz_0, ta1_y_xxxx_xxyzz_1, ta1_y_xxxx_xxzz_0, ta1_y_xxxx_xxzz_1, ta1_y_xxxx_xxzzz_0, ta1_y_xxxx_xxzzz_1, ta1_y_xxxx_xyyy_0, ta1_y_xxxx_xyyy_1, ta1_y_xxxx_xyyyy_0, ta1_y_xxxx_xyyyy_1, ta1_y_xxxx_xyyyz_0, ta1_y_xxxx_xyyyz_1, ta1_y_xxxx_xyyz_0, ta1_y_xxxx_xyyz_1, ta1_y_xxxx_xyyzz_0, ta1_y_xxxx_xyyzz_1, ta1_y_xxxx_xyzz_0, ta1_y_xxxx_xyzz_1, ta1_y_xxxx_xyzzz_0, ta1_y_xxxx_xyzzz_1, ta1_y_xxxx_xzzz_0, ta1_y_xxxx_xzzz_1, ta1_y_xxxx_xzzzz_0, ta1_y_xxxx_xzzzz_1, ta1_y_xxxx_yyyyy_0, ta1_y_xxxx_yyyyy_1, ta1_y_xxxxz_xxxxx_0, ta1_y_xxxxz_xxxxy_0, ta1_y_xxxxz_xxxxz_0, ta1_y_xxxxz_xxxyy_0, ta1_y_xxxxz_xxxyz_0, ta1_y_xxxxz_xxxzz_0, ta1_y_xxxxz_xxyyy_0, ta1_y_xxxxz_xxyyz_0, ta1_y_xxxxz_xxyzz_0, ta1_y_xxxxz_xxzzz_0, ta1_y_xxxxz_xyyyy_0, ta1_y_xxxxz_xyyyz_0, ta1_y_xxxxz_xyyzz_0, ta1_y_xxxxz_xyzzz_0, ta1_y_xxxxz_xzzzz_0, ta1_y_xxxxz_yyyyy_0, ta1_y_xxxxz_yyyyz_0, ta1_y_xxxxz_yyyzz_0, ta1_y_xxxxz_yyzzz_0, ta1_y_xxxxz_yzzzz_0, ta1_y_xxxxz_zzzzz_0, ta1_y_xxxz_yyyyz_0, ta1_y_xxxz_yyyyz_1, ta1_y_xxxz_yyyzz_0, ta1_y_xxxz_yyyzz_1, ta1_y_xxxz_yyzzz_0, ta1_y_xxxz_yyzzz_1, ta1_y_xxxz_yzzzz_0, ta1_y_xxxz_yzzzz_1, ta1_y_xxxz_zzzzz_0, ta1_y_xxxz_zzzzz_1, ta1_y_xxz_yyyyz_0, ta1_y_xxz_yyyyz_1, ta1_y_xxz_yyyzz_0, ta1_y_xxz_yyyzz_1, ta1_y_xxz_yyzzz_0, ta1_y_xxz_yyzzz_1, ta1_y_xxz_yzzzz_0, ta1_y_xxz_yzzzz_1, ta1_y_xxz_zzzzz_0, ta1_y_xxz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxxz_xxxxx_0[i] = ta1_y_xxxx_xxxxx_0[i] * pa_z[i] - ta1_y_xxxx_xxxxx_1[i] * pc_z[i];

        ta1_y_xxxxz_xxxxy_0[i] = ta1_y_xxxx_xxxxy_0[i] * pa_z[i] - ta1_y_xxxx_xxxxy_1[i] * pc_z[i];

        ta1_y_xxxxz_xxxxz_0[i] = ta1_y_xxxx_xxxx_0[i] * fe_0 - ta1_y_xxxx_xxxx_1[i] * fe_0 + ta1_y_xxxx_xxxxz_0[i] * pa_z[i] - ta1_y_xxxx_xxxxz_1[i] * pc_z[i];

        ta1_y_xxxxz_xxxyy_0[i] = ta1_y_xxxx_xxxyy_0[i] * pa_z[i] - ta1_y_xxxx_xxxyy_1[i] * pc_z[i];

        ta1_y_xxxxz_xxxyz_0[i] = ta1_y_xxxx_xxxy_0[i] * fe_0 - ta1_y_xxxx_xxxy_1[i] * fe_0 + ta1_y_xxxx_xxxyz_0[i] * pa_z[i] - ta1_y_xxxx_xxxyz_1[i] * pc_z[i];

        ta1_y_xxxxz_xxxzz_0[i] = 2.0 * ta1_y_xxxx_xxxz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xxxz_1[i] * fe_0 + ta1_y_xxxx_xxxzz_0[i] * pa_z[i] - ta1_y_xxxx_xxxzz_1[i] * pc_z[i];

        ta1_y_xxxxz_xxyyy_0[i] = ta1_y_xxxx_xxyyy_0[i] * pa_z[i] - ta1_y_xxxx_xxyyy_1[i] * pc_z[i];

        ta1_y_xxxxz_xxyyz_0[i] = ta1_y_xxxx_xxyy_0[i] * fe_0 - ta1_y_xxxx_xxyy_1[i] * fe_0 + ta1_y_xxxx_xxyyz_0[i] * pa_z[i] - ta1_y_xxxx_xxyyz_1[i] * pc_z[i];

        ta1_y_xxxxz_xxyzz_0[i] = 2.0 * ta1_y_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xxyz_1[i] * fe_0 + ta1_y_xxxx_xxyzz_0[i] * pa_z[i] - ta1_y_xxxx_xxyzz_1[i] * pc_z[i];

        ta1_y_xxxxz_xxzzz_0[i] = 3.0 * ta1_y_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xxzz_1[i] * fe_0 + ta1_y_xxxx_xxzzz_0[i] * pa_z[i] - ta1_y_xxxx_xxzzz_1[i] * pc_z[i];

        ta1_y_xxxxz_xyyyy_0[i] = ta1_y_xxxx_xyyyy_0[i] * pa_z[i] - ta1_y_xxxx_xyyyy_1[i] * pc_z[i];

        ta1_y_xxxxz_xyyyz_0[i] = ta1_y_xxxx_xyyy_0[i] * fe_0 - ta1_y_xxxx_xyyy_1[i] * fe_0 + ta1_y_xxxx_xyyyz_0[i] * pa_z[i] - ta1_y_xxxx_xyyyz_1[i] * pc_z[i];

        ta1_y_xxxxz_xyyzz_0[i] = 2.0 * ta1_y_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxxx_xyyz_1[i] * fe_0 + ta1_y_xxxx_xyyzz_0[i] * pa_z[i] - ta1_y_xxxx_xyyzz_1[i] * pc_z[i];

        ta1_y_xxxxz_xyzzz_0[i] = 3.0 * ta1_y_xxxx_xyzz_0[i] * fe_0 - 3.0 * ta1_y_xxxx_xyzz_1[i] * fe_0 + ta1_y_xxxx_xyzzz_0[i] * pa_z[i] - ta1_y_xxxx_xyzzz_1[i] * pc_z[i];

        ta1_y_xxxxz_xzzzz_0[i] = 4.0 * ta1_y_xxxx_xzzz_0[i] * fe_0 - 4.0 * ta1_y_xxxx_xzzz_1[i] * fe_0 + ta1_y_xxxx_xzzzz_0[i] * pa_z[i] - ta1_y_xxxx_xzzzz_1[i] * pc_z[i];

        ta1_y_xxxxz_yyyyy_0[i] = ta1_y_xxxx_yyyyy_0[i] * pa_z[i] - ta1_y_xxxx_yyyyy_1[i] * pc_z[i];

        ta1_y_xxxxz_yyyyz_0[i] = 3.0 * ta1_y_xxz_yyyyz_0[i] * fe_0 - 3.0 * ta1_y_xxz_yyyyz_1[i] * fe_0 + ta1_y_xxxz_yyyyz_0[i] * pa_x[i] - ta1_y_xxxz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxxz_yyyzz_0[i] = 3.0 * ta1_y_xxz_yyyzz_0[i] * fe_0 - 3.0 * ta1_y_xxz_yyyzz_1[i] * fe_0 + ta1_y_xxxz_yyyzz_0[i] * pa_x[i] - ta1_y_xxxz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxxz_yyzzz_0[i] = 3.0 * ta1_y_xxz_yyzzz_0[i] * fe_0 - 3.0 * ta1_y_xxz_yyzzz_1[i] * fe_0 + ta1_y_xxxz_yyzzz_0[i] * pa_x[i] - ta1_y_xxxz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxxz_yzzzz_0[i] = 3.0 * ta1_y_xxz_yzzzz_0[i] * fe_0 - 3.0 * ta1_y_xxz_yzzzz_1[i] * fe_0 + ta1_y_xxxz_yzzzz_0[i] * pa_x[i] - ta1_y_xxxz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxxz_zzzzz_0[i] = 3.0 * ta1_y_xxz_zzzzz_0[i] * fe_0 - 3.0 * ta1_y_xxz_zzzzz_1[i] * fe_0 + ta1_y_xxxz_zzzzz_0[i] * pa_x[i] - ta1_y_xxxz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 504-525 components of targeted buffer : HH

    auto ta1_y_xxxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 504);

    auto ta1_y_xxxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 505);

    auto ta1_y_xxxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 506);

    auto ta1_y_xxxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 507);

    auto ta1_y_xxxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 508);

    auto ta1_y_xxxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 509);

    auto ta1_y_xxxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 510);

    auto ta1_y_xxxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 511);

    auto ta1_y_xxxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 512);

    auto ta1_y_xxxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 513);

    auto ta1_y_xxxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 514);

    auto ta1_y_xxxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 515);

    auto ta1_y_xxxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 516);

    auto ta1_y_xxxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 517);

    auto ta1_y_xxxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 518);

    auto ta1_y_xxxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 519);

    auto ta1_y_xxxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 520);

    auto ta1_y_xxxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 521);

    auto ta1_y_xxxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 522);

    auto ta1_y_xxxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 523);

    auto ta1_y_xxxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 524);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_y_xxx_xxxxx_0, ta1_y_xxx_xxxxx_1, ta1_y_xxx_xxxxz_0, ta1_y_xxx_xxxxz_1, ta1_y_xxx_xxxzz_0, ta1_y_xxx_xxxzz_1, ta1_y_xxx_xxzzz_0, ta1_y_xxx_xxzzz_1, ta1_y_xxx_xzzzz_0, ta1_y_xxx_xzzzz_1, ta1_y_xxxy_xxxxx_0, ta1_y_xxxy_xxxxx_1, ta1_y_xxxy_xxxxz_0, ta1_y_xxxy_xxxxz_1, ta1_y_xxxy_xxxzz_0, ta1_y_xxxy_xxxzz_1, ta1_y_xxxy_xxzzz_0, ta1_y_xxxy_xxzzz_1, ta1_y_xxxy_xzzzz_0, ta1_y_xxxy_xzzzz_1, ta1_y_xxxyy_xxxxx_0, ta1_y_xxxyy_xxxxy_0, ta1_y_xxxyy_xxxxz_0, ta1_y_xxxyy_xxxyy_0, ta1_y_xxxyy_xxxyz_0, ta1_y_xxxyy_xxxzz_0, ta1_y_xxxyy_xxyyy_0, ta1_y_xxxyy_xxyyz_0, ta1_y_xxxyy_xxyzz_0, ta1_y_xxxyy_xxzzz_0, ta1_y_xxxyy_xyyyy_0, ta1_y_xxxyy_xyyyz_0, ta1_y_xxxyy_xyyzz_0, ta1_y_xxxyy_xyzzz_0, ta1_y_xxxyy_xzzzz_0, ta1_y_xxxyy_yyyyy_0, ta1_y_xxxyy_yyyyz_0, ta1_y_xxxyy_yyyzz_0, ta1_y_xxxyy_yyzzz_0, ta1_y_xxxyy_yzzzz_0, ta1_y_xxxyy_zzzzz_0, ta1_y_xxyy_xxxxy_0, ta1_y_xxyy_xxxxy_1, ta1_y_xxyy_xxxy_0, ta1_y_xxyy_xxxy_1, ta1_y_xxyy_xxxyy_0, ta1_y_xxyy_xxxyy_1, ta1_y_xxyy_xxxyz_0, ta1_y_xxyy_xxxyz_1, ta1_y_xxyy_xxyy_0, ta1_y_xxyy_xxyy_1, ta1_y_xxyy_xxyyy_0, ta1_y_xxyy_xxyyy_1, ta1_y_xxyy_xxyyz_0, ta1_y_xxyy_xxyyz_1, ta1_y_xxyy_xxyz_0, ta1_y_xxyy_xxyz_1, ta1_y_xxyy_xxyzz_0, ta1_y_xxyy_xxyzz_1, ta1_y_xxyy_xyyy_0, ta1_y_xxyy_xyyy_1, ta1_y_xxyy_xyyyy_0, ta1_y_xxyy_xyyyy_1, ta1_y_xxyy_xyyyz_0, ta1_y_xxyy_xyyyz_1, ta1_y_xxyy_xyyz_0, ta1_y_xxyy_xyyz_1, ta1_y_xxyy_xyyzz_0, ta1_y_xxyy_xyyzz_1, ta1_y_xxyy_xyzz_0, ta1_y_xxyy_xyzz_1, ta1_y_xxyy_xyzzz_0, ta1_y_xxyy_xyzzz_1, ta1_y_xxyy_yyyy_0, ta1_y_xxyy_yyyy_1, ta1_y_xxyy_yyyyy_0, ta1_y_xxyy_yyyyy_1, ta1_y_xxyy_yyyyz_0, ta1_y_xxyy_yyyyz_1, ta1_y_xxyy_yyyz_0, ta1_y_xxyy_yyyz_1, ta1_y_xxyy_yyyzz_0, ta1_y_xxyy_yyyzz_1, ta1_y_xxyy_yyzz_0, ta1_y_xxyy_yyzz_1, ta1_y_xxyy_yyzzz_0, ta1_y_xxyy_yyzzz_1, ta1_y_xxyy_yzzz_0, ta1_y_xxyy_yzzz_1, ta1_y_xxyy_yzzzz_0, ta1_y_xxyy_yzzzz_1, ta1_y_xxyy_zzzzz_0, ta1_y_xxyy_zzzzz_1, ta1_y_xyy_xxxxy_0, ta1_y_xyy_xxxxy_1, ta1_y_xyy_xxxyy_0, ta1_y_xyy_xxxyy_1, ta1_y_xyy_xxxyz_0, ta1_y_xyy_xxxyz_1, ta1_y_xyy_xxyyy_0, ta1_y_xyy_xxyyy_1, ta1_y_xyy_xxyyz_0, ta1_y_xyy_xxyyz_1, ta1_y_xyy_xxyzz_0, ta1_y_xyy_xxyzz_1, ta1_y_xyy_xyyyy_0, ta1_y_xyy_xyyyy_1, ta1_y_xyy_xyyyz_0, ta1_y_xyy_xyyyz_1, ta1_y_xyy_xyyzz_0, ta1_y_xyy_xyyzz_1, ta1_y_xyy_xyzzz_0, ta1_y_xyy_xyzzz_1, ta1_y_xyy_yyyyy_0, ta1_y_xyy_yyyyy_1, ta1_y_xyy_yyyyz_0, ta1_y_xyy_yyyyz_1, ta1_y_xyy_yyyzz_0, ta1_y_xyy_yyyzz_1, ta1_y_xyy_yyzzz_0, ta1_y_xyy_yyzzz_1, ta1_y_xyy_yzzzz_0, ta1_y_xyy_yzzzz_1, ta1_y_xyy_zzzzz_0, ta1_y_xyy_zzzzz_1, ta_xxxy_xxxxx_1, ta_xxxy_xxxxz_1, ta_xxxy_xxxzz_1, ta_xxxy_xxzzz_1, ta_xxxy_xzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxyy_xxxxx_0[i] = ta1_y_xxx_xxxxx_0[i] * fe_0 - ta1_y_xxx_xxxxx_1[i] * fe_0 + ta_xxxy_xxxxx_1[i] + ta1_y_xxxy_xxxxx_0[i] * pa_y[i] - ta1_y_xxxy_xxxxx_1[i] * pc_y[i];

        ta1_y_xxxyy_xxxxy_0[i] = 2.0 * ta1_y_xyy_xxxxy_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxxxy_1[i] * fe_0 + 4.0 * ta1_y_xxyy_xxxy_0[i] * fe_0 - 4.0 * ta1_y_xxyy_xxxy_1[i] * fe_0 + ta1_y_xxyy_xxxxy_0[i] * pa_x[i] - ta1_y_xxyy_xxxxy_1[i] * pc_x[i];

        ta1_y_xxxyy_xxxxz_0[i] = ta1_y_xxx_xxxxz_0[i] * fe_0 - ta1_y_xxx_xxxxz_1[i] * fe_0 + ta_xxxy_xxxxz_1[i] + ta1_y_xxxy_xxxxz_0[i] * pa_y[i] - ta1_y_xxxy_xxxxz_1[i] * pc_y[i];

        ta1_y_xxxyy_xxxyy_0[i] = 2.0 * ta1_y_xyy_xxxyy_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxxyy_1[i] * fe_0 + 3.0 * ta1_y_xxyy_xxyy_0[i] * fe_0 - 3.0 * ta1_y_xxyy_xxyy_1[i] * fe_0 + ta1_y_xxyy_xxxyy_0[i] * pa_x[i] - ta1_y_xxyy_xxxyy_1[i] * pc_x[i];

        ta1_y_xxxyy_xxxyz_0[i] = 2.0 * ta1_y_xyy_xxxyz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxxyz_1[i] * fe_0 + 3.0 * ta1_y_xxyy_xxyz_0[i] * fe_0 - 3.0 * ta1_y_xxyy_xxyz_1[i] * fe_0 + ta1_y_xxyy_xxxyz_0[i] * pa_x[i] - ta1_y_xxyy_xxxyz_1[i] * pc_x[i];

        ta1_y_xxxyy_xxxzz_0[i] = ta1_y_xxx_xxxzz_0[i] * fe_0 - ta1_y_xxx_xxxzz_1[i] * fe_0 + ta_xxxy_xxxzz_1[i] + ta1_y_xxxy_xxxzz_0[i] * pa_y[i] - ta1_y_xxxy_xxxzz_1[i] * pc_y[i];

        ta1_y_xxxyy_xxyyy_0[i] = 2.0 * ta1_y_xyy_xxyyy_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxyyy_1[i] * fe_0 + 2.0 * ta1_y_xxyy_xyyy_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xyyy_1[i] * fe_0 + ta1_y_xxyy_xxyyy_0[i] * pa_x[i] - ta1_y_xxyy_xxyyy_1[i] * pc_x[i];

        ta1_y_xxxyy_xxyyz_0[i] = 2.0 * ta1_y_xyy_xxyyz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_xxyy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xyyz_1[i] * fe_0 + ta1_y_xxyy_xxyyz_0[i] * pa_x[i] - ta1_y_xxyy_xxyyz_1[i] * pc_x[i];

        ta1_y_xxxyy_xxyzz_0[i] = 2.0 * ta1_y_xyy_xxyzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_xxyy_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xyzz_1[i] * fe_0 + ta1_y_xxyy_xxyzz_0[i] * pa_x[i] - ta1_y_xxyy_xxyzz_1[i] * pc_x[i];

        ta1_y_xxxyy_xxzzz_0[i] = ta1_y_xxx_xxzzz_0[i] * fe_0 - ta1_y_xxx_xxzzz_1[i] * fe_0 + ta_xxxy_xxzzz_1[i] + ta1_y_xxxy_xxzzz_0[i] * pa_y[i] - ta1_y_xxxy_xxzzz_1[i] * pc_y[i];

        ta1_y_xxxyy_xyyyy_0[i] = 2.0 * ta1_y_xyy_xyyyy_0[i] * fe_0 - 2.0 * ta1_y_xyy_xyyyy_1[i] * fe_0 + ta1_y_xxyy_yyyy_0[i] * fe_0 - ta1_y_xxyy_yyyy_1[i] * fe_0 + ta1_y_xxyy_xyyyy_0[i] * pa_x[i] - ta1_y_xxyy_xyyyy_1[i] * pc_x[i];

        ta1_y_xxxyy_xyyyz_0[i] = 2.0 * ta1_y_xyy_xyyyz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xyyyz_1[i] * fe_0 + ta1_y_xxyy_yyyz_0[i] * fe_0 - ta1_y_xxyy_yyyz_1[i] * fe_0 + ta1_y_xxyy_xyyyz_0[i] * pa_x[i] - ta1_y_xxyy_xyyyz_1[i] * pc_x[i];

        ta1_y_xxxyy_xyyzz_0[i] = 2.0 * ta1_y_xyy_xyyzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xyyzz_1[i] * fe_0 + ta1_y_xxyy_yyzz_0[i] * fe_0 - ta1_y_xxyy_yyzz_1[i] * fe_0 + ta1_y_xxyy_xyyzz_0[i] * pa_x[i] - ta1_y_xxyy_xyyzz_1[i] * pc_x[i];

        ta1_y_xxxyy_xyzzz_0[i] = 2.0 * ta1_y_xyy_xyzzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_xyzzz_1[i] * fe_0 + ta1_y_xxyy_yzzz_0[i] * fe_0 - ta1_y_xxyy_yzzz_1[i] * fe_0 + ta1_y_xxyy_xyzzz_0[i] * pa_x[i] - ta1_y_xxyy_xyzzz_1[i] * pc_x[i];

        ta1_y_xxxyy_xzzzz_0[i] = ta1_y_xxx_xzzzz_0[i] * fe_0 - ta1_y_xxx_xzzzz_1[i] * fe_0 + ta_xxxy_xzzzz_1[i] + ta1_y_xxxy_xzzzz_0[i] * pa_y[i] - ta1_y_xxxy_xzzzz_1[i] * pc_y[i];

        ta1_y_xxxyy_yyyyy_0[i] = 2.0 * ta1_y_xyy_yyyyy_0[i] * fe_0 - 2.0 * ta1_y_xyy_yyyyy_1[i] * fe_0 + ta1_y_xxyy_yyyyy_0[i] * pa_x[i] - ta1_y_xxyy_yyyyy_1[i] * pc_x[i];

        ta1_y_xxxyy_yyyyz_0[i] = 2.0 * ta1_y_xyy_yyyyz_0[i] * fe_0 - 2.0 * ta1_y_xyy_yyyyz_1[i] * fe_0 + ta1_y_xxyy_yyyyz_0[i] * pa_x[i] - ta1_y_xxyy_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxyy_yyyzz_0[i] = 2.0 * ta1_y_xyy_yyyzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_yyyzz_1[i] * fe_0 + ta1_y_xxyy_yyyzz_0[i] * pa_x[i] - ta1_y_xxyy_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxyy_yyzzz_0[i] = 2.0 * ta1_y_xyy_yyzzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_yyzzz_1[i] * fe_0 + ta1_y_xxyy_yyzzz_0[i] * pa_x[i] - ta1_y_xxyy_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxyy_yzzzz_0[i] = 2.0 * ta1_y_xyy_yzzzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_yzzzz_1[i] * fe_0 + ta1_y_xxyy_yzzzz_0[i] * pa_x[i] - ta1_y_xxyy_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxyy_zzzzz_0[i] = 2.0 * ta1_y_xyy_zzzzz_0[i] * fe_0 - 2.0 * ta1_y_xyy_zzzzz_1[i] * fe_0 + ta1_y_xxyy_zzzzz_0[i] * pa_x[i] - ta1_y_xxyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 525-546 components of targeted buffer : HH

    auto ta1_y_xxxyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 525);

    auto ta1_y_xxxyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 526);

    auto ta1_y_xxxyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 527);

    auto ta1_y_xxxyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 528);

    auto ta1_y_xxxyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 529);

    auto ta1_y_xxxyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 530);

    auto ta1_y_xxxyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 531);

    auto ta1_y_xxxyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 532);

    auto ta1_y_xxxyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 533);

    auto ta1_y_xxxyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 534);

    auto ta1_y_xxxyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 535);

    auto ta1_y_xxxyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 536);

    auto ta1_y_xxxyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 537);

    auto ta1_y_xxxyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 538);

    auto ta1_y_xxxyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 539);

    auto ta1_y_xxxyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 540);

    auto ta1_y_xxxyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 541);

    auto ta1_y_xxxyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 542);

    auto ta1_y_xxxyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 543);

    auto ta1_y_xxxyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 544);

    auto ta1_y_xxxyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 545);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_y_xxxy_xxxxx_0, ta1_y_xxxy_xxxxx_1, ta1_y_xxxy_xxxxy_0, ta1_y_xxxy_xxxxy_1, ta1_y_xxxy_xxxy_0, ta1_y_xxxy_xxxy_1, ta1_y_xxxy_xxxyy_0, ta1_y_xxxy_xxxyy_1, ta1_y_xxxy_xxxyz_0, ta1_y_xxxy_xxxyz_1, ta1_y_xxxy_xxyy_0, ta1_y_xxxy_xxyy_1, ta1_y_xxxy_xxyyy_0, ta1_y_xxxy_xxyyy_1, ta1_y_xxxy_xxyyz_0, ta1_y_xxxy_xxyyz_1, ta1_y_xxxy_xxyz_0, ta1_y_xxxy_xxyz_1, ta1_y_xxxy_xxyzz_0, ta1_y_xxxy_xxyzz_1, ta1_y_xxxy_xyyy_0, ta1_y_xxxy_xyyy_1, ta1_y_xxxy_xyyyy_0, ta1_y_xxxy_xyyyy_1, ta1_y_xxxy_xyyyz_0, ta1_y_xxxy_xyyyz_1, ta1_y_xxxy_xyyz_0, ta1_y_xxxy_xyyz_1, ta1_y_xxxy_xyyzz_0, ta1_y_xxxy_xyyzz_1, ta1_y_xxxy_xyzz_0, ta1_y_xxxy_xyzz_1, ta1_y_xxxy_xyzzz_0, ta1_y_xxxy_xyzzz_1, ta1_y_xxxy_yyyyy_0, ta1_y_xxxy_yyyyy_1, ta1_y_xxxyz_xxxxx_0, ta1_y_xxxyz_xxxxy_0, ta1_y_xxxyz_xxxxz_0, ta1_y_xxxyz_xxxyy_0, ta1_y_xxxyz_xxxyz_0, ta1_y_xxxyz_xxxzz_0, ta1_y_xxxyz_xxyyy_0, ta1_y_xxxyz_xxyyz_0, ta1_y_xxxyz_xxyzz_0, ta1_y_xxxyz_xxzzz_0, ta1_y_xxxyz_xyyyy_0, ta1_y_xxxyz_xyyyz_0, ta1_y_xxxyz_xyyzz_0, ta1_y_xxxyz_xyzzz_0, ta1_y_xxxyz_xzzzz_0, ta1_y_xxxyz_yyyyy_0, ta1_y_xxxyz_yyyyz_0, ta1_y_xxxyz_yyyzz_0, ta1_y_xxxyz_yyzzz_0, ta1_y_xxxyz_yzzzz_0, ta1_y_xxxyz_zzzzz_0, ta1_y_xxxz_xxxxz_0, ta1_y_xxxz_xxxxz_1, ta1_y_xxxz_xxxzz_0, ta1_y_xxxz_xxxzz_1, ta1_y_xxxz_xxzzz_0, ta1_y_xxxz_xxzzz_1, ta1_y_xxxz_xzzzz_0, ta1_y_xxxz_xzzzz_1, ta1_y_xxxz_zzzzz_0, ta1_y_xxxz_zzzzz_1, ta1_y_xxyz_yyyyz_0, ta1_y_xxyz_yyyyz_1, ta1_y_xxyz_yyyzz_0, ta1_y_xxyz_yyyzz_1, ta1_y_xxyz_yyzzz_0, ta1_y_xxyz_yyzzz_1, ta1_y_xxyz_yzzzz_0, ta1_y_xxyz_yzzzz_1, ta1_y_xyz_yyyyz_0, ta1_y_xyz_yyyyz_1, ta1_y_xyz_yyyzz_0, ta1_y_xyz_yyyzz_1, ta1_y_xyz_yyzzz_0, ta1_y_xyz_yyzzz_1, ta1_y_xyz_yzzzz_0, ta1_y_xyz_yzzzz_1, ta_xxxz_xxxxz_1, ta_xxxz_xxxzz_1, ta_xxxz_xxzzz_1, ta_xxxz_xzzzz_1, ta_xxxz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxyz_xxxxx_0[i] = ta1_y_xxxy_xxxxx_0[i] * pa_z[i] - ta1_y_xxxy_xxxxx_1[i] * pc_z[i];

        ta1_y_xxxyz_xxxxy_0[i] = ta1_y_xxxy_xxxxy_0[i] * pa_z[i] - ta1_y_xxxy_xxxxy_1[i] * pc_z[i];

        ta1_y_xxxyz_xxxxz_0[i] = ta_xxxz_xxxxz_1[i] + ta1_y_xxxz_xxxxz_0[i] * pa_y[i] - ta1_y_xxxz_xxxxz_1[i] * pc_y[i];

        ta1_y_xxxyz_xxxyy_0[i] = ta1_y_xxxy_xxxyy_0[i] * pa_z[i] - ta1_y_xxxy_xxxyy_1[i] * pc_z[i];

        ta1_y_xxxyz_xxxyz_0[i] = ta1_y_xxxy_xxxy_0[i] * fe_0 - ta1_y_xxxy_xxxy_1[i] * fe_0 + ta1_y_xxxy_xxxyz_0[i] * pa_z[i] - ta1_y_xxxy_xxxyz_1[i] * pc_z[i];

        ta1_y_xxxyz_xxxzz_0[i] = ta_xxxz_xxxzz_1[i] + ta1_y_xxxz_xxxzz_0[i] * pa_y[i] - ta1_y_xxxz_xxxzz_1[i] * pc_y[i];

        ta1_y_xxxyz_xxyyy_0[i] = ta1_y_xxxy_xxyyy_0[i] * pa_z[i] - ta1_y_xxxy_xxyyy_1[i] * pc_z[i];

        ta1_y_xxxyz_xxyyz_0[i] = ta1_y_xxxy_xxyy_0[i] * fe_0 - ta1_y_xxxy_xxyy_1[i] * fe_0 + ta1_y_xxxy_xxyyz_0[i] * pa_z[i] - ta1_y_xxxy_xxyyz_1[i] * pc_z[i];

        ta1_y_xxxyz_xxyzz_0[i] = 2.0 * ta1_y_xxxy_xxyz_0[i] * fe_0 - 2.0 * ta1_y_xxxy_xxyz_1[i] * fe_0 + ta1_y_xxxy_xxyzz_0[i] * pa_z[i] - ta1_y_xxxy_xxyzz_1[i] * pc_z[i];

        ta1_y_xxxyz_xxzzz_0[i] = ta_xxxz_xxzzz_1[i] + ta1_y_xxxz_xxzzz_0[i] * pa_y[i] - ta1_y_xxxz_xxzzz_1[i] * pc_y[i];

        ta1_y_xxxyz_xyyyy_0[i] = ta1_y_xxxy_xyyyy_0[i] * pa_z[i] - ta1_y_xxxy_xyyyy_1[i] * pc_z[i];

        ta1_y_xxxyz_xyyyz_0[i] = ta1_y_xxxy_xyyy_0[i] * fe_0 - ta1_y_xxxy_xyyy_1[i] * fe_0 + ta1_y_xxxy_xyyyz_0[i] * pa_z[i] - ta1_y_xxxy_xyyyz_1[i] * pc_z[i];

        ta1_y_xxxyz_xyyzz_0[i] = 2.0 * ta1_y_xxxy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxxy_xyyz_1[i] * fe_0 + ta1_y_xxxy_xyyzz_0[i] * pa_z[i] - ta1_y_xxxy_xyyzz_1[i] * pc_z[i];

        ta1_y_xxxyz_xyzzz_0[i] = 3.0 * ta1_y_xxxy_xyzz_0[i] * fe_0 - 3.0 * ta1_y_xxxy_xyzz_1[i] * fe_0 + ta1_y_xxxy_xyzzz_0[i] * pa_z[i] - ta1_y_xxxy_xyzzz_1[i] * pc_z[i];

        ta1_y_xxxyz_xzzzz_0[i] = ta_xxxz_xzzzz_1[i] + ta1_y_xxxz_xzzzz_0[i] * pa_y[i] - ta1_y_xxxz_xzzzz_1[i] * pc_y[i];

        ta1_y_xxxyz_yyyyy_0[i] = ta1_y_xxxy_yyyyy_0[i] * pa_z[i] - ta1_y_xxxy_yyyyy_1[i] * pc_z[i];

        ta1_y_xxxyz_yyyyz_0[i] = 2.0 * ta1_y_xyz_yyyyz_0[i] * fe_0 - 2.0 * ta1_y_xyz_yyyyz_1[i] * fe_0 + ta1_y_xxyz_yyyyz_0[i] * pa_x[i] - ta1_y_xxyz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxyz_yyyzz_0[i] = 2.0 * ta1_y_xyz_yyyzz_0[i] * fe_0 - 2.0 * ta1_y_xyz_yyyzz_1[i] * fe_0 + ta1_y_xxyz_yyyzz_0[i] * pa_x[i] - ta1_y_xxyz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxyz_yyzzz_0[i] = 2.0 * ta1_y_xyz_yyzzz_0[i] * fe_0 - 2.0 * ta1_y_xyz_yyzzz_1[i] * fe_0 + ta1_y_xxyz_yyzzz_0[i] * pa_x[i] - ta1_y_xxyz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxyz_yzzzz_0[i] = 2.0 * ta1_y_xyz_yzzzz_0[i] * fe_0 - 2.0 * ta1_y_xyz_yzzzz_1[i] * fe_0 + ta1_y_xxyz_yzzzz_0[i] * pa_x[i] - ta1_y_xxyz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxyz_zzzzz_0[i] = ta_xxxz_zzzzz_1[i] + ta1_y_xxxz_zzzzz_0[i] * pa_y[i] - ta1_y_xxxz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 546-567 components of targeted buffer : HH

    auto ta1_y_xxxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 546);

    auto ta1_y_xxxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 547);

    auto ta1_y_xxxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 548);

    auto ta1_y_xxxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 549);

    auto ta1_y_xxxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 550);

    auto ta1_y_xxxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 551);

    auto ta1_y_xxxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 552);

    auto ta1_y_xxxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 553);

    auto ta1_y_xxxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 554);

    auto ta1_y_xxxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 555);

    auto ta1_y_xxxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 556);

    auto ta1_y_xxxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 557);

    auto ta1_y_xxxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 558);

    auto ta1_y_xxxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 559);

    auto ta1_y_xxxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 560);

    auto ta1_y_xxxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 561);

    auto ta1_y_xxxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 562);

    auto ta1_y_xxxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 563);

    auto ta1_y_xxxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 564);

    auto ta1_y_xxxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 565);

    auto ta1_y_xxxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 566);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_y_xxx_xxxxx_0, ta1_y_xxx_xxxxx_1, ta1_y_xxx_xxxxy_0, ta1_y_xxx_xxxxy_1, ta1_y_xxx_xxxyy_0, ta1_y_xxx_xxxyy_1, ta1_y_xxx_xxyyy_0, ta1_y_xxx_xxyyy_1, ta1_y_xxx_xyyyy_0, ta1_y_xxx_xyyyy_1, ta1_y_xxxz_xxxxx_0, ta1_y_xxxz_xxxxx_1, ta1_y_xxxz_xxxxy_0, ta1_y_xxxz_xxxxy_1, ta1_y_xxxz_xxxyy_0, ta1_y_xxxz_xxxyy_1, ta1_y_xxxz_xxyyy_0, ta1_y_xxxz_xxyyy_1, ta1_y_xxxz_xyyyy_0, ta1_y_xxxz_xyyyy_1, ta1_y_xxxzz_xxxxx_0, ta1_y_xxxzz_xxxxy_0, ta1_y_xxxzz_xxxxz_0, ta1_y_xxxzz_xxxyy_0, ta1_y_xxxzz_xxxyz_0, ta1_y_xxxzz_xxxzz_0, ta1_y_xxxzz_xxyyy_0, ta1_y_xxxzz_xxyyz_0, ta1_y_xxxzz_xxyzz_0, ta1_y_xxxzz_xxzzz_0, ta1_y_xxxzz_xyyyy_0, ta1_y_xxxzz_xyyyz_0, ta1_y_xxxzz_xyyzz_0, ta1_y_xxxzz_xyzzz_0, ta1_y_xxxzz_xzzzz_0, ta1_y_xxxzz_yyyyy_0, ta1_y_xxxzz_yyyyz_0, ta1_y_xxxzz_yyyzz_0, ta1_y_xxxzz_yyzzz_0, ta1_y_xxxzz_yzzzz_0, ta1_y_xxxzz_zzzzz_0, ta1_y_xxzz_xxxxz_0, ta1_y_xxzz_xxxxz_1, ta1_y_xxzz_xxxyz_0, ta1_y_xxzz_xxxyz_1, ta1_y_xxzz_xxxz_0, ta1_y_xxzz_xxxz_1, ta1_y_xxzz_xxxzz_0, ta1_y_xxzz_xxxzz_1, ta1_y_xxzz_xxyyz_0, ta1_y_xxzz_xxyyz_1, ta1_y_xxzz_xxyz_0, ta1_y_xxzz_xxyz_1, ta1_y_xxzz_xxyzz_0, ta1_y_xxzz_xxyzz_1, ta1_y_xxzz_xxzz_0, ta1_y_xxzz_xxzz_1, ta1_y_xxzz_xxzzz_0, ta1_y_xxzz_xxzzz_1, ta1_y_xxzz_xyyyz_0, ta1_y_xxzz_xyyyz_1, ta1_y_xxzz_xyyz_0, ta1_y_xxzz_xyyz_1, ta1_y_xxzz_xyyzz_0, ta1_y_xxzz_xyyzz_1, ta1_y_xxzz_xyzz_0, ta1_y_xxzz_xyzz_1, ta1_y_xxzz_xyzzz_0, ta1_y_xxzz_xyzzz_1, ta1_y_xxzz_xzzz_0, ta1_y_xxzz_xzzz_1, ta1_y_xxzz_xzzzz_0, ta1_y_xxzz_xzzzz_1, ta1_y_xxzz_yyyyy_0, ta1_y_xxzz_yyyyy_1, ta1_y_xxzz_yyyyz_0, ta1_y_xxzz_yyyyz_1, ta1_y_xxzz_yyyz_0, ta1_y_xxzz_yyyz_1, ta1_y_xxzz_yyyzz_0, ta1_y_xxzz_yyyzz_1, ta1_y_xxzz_yyzz_0, ta1_y_xxzz_yyzz_1, ta1_y_xxzz_yyzzz_0, ta1_y_xxzz_yyzzz_1, ta1_y_xxzz_yzzz_0, ta1_y_xxzz_yzzz_1, ta1_y_xxzz_yzzzz_0, ta1_y_xxzz_yzzzz_1, ta1_y_xxzz_zzzz_0, ta1_y_xxzz_zzzz_1, ta1_y_xxzz_zzzzz_0, ta1_y_xxzz_zzzzz_1, ta1_y_xzz_xxxxz_0, ta1_y_xzz_xxxxz_1, ta1_y_xzz_xxxyz_0, ta1_y_xzz_xxxyz_1, ta1_y_xzz_xxxzz_0, ta1_y_xzz_xxxzz_1, ta1_y_xzz_xxyyz_0, ta1_y_xzz_xxyyz_1, ta1_y_xzz_xxyzz_0, ta1_y_xzz_xxyzz_1, ta1_y_xzz_xxzzz_0, ta1_y_xzz_xxzzz_1, ta1_y_xzz_xyyyz_0, ta1_y_xzz_xyyyz_1, ta1_y_xzz_xyyzz_0, ta1_y_xzz_xyyzz_1, ta1_y_xzz_xyzzz_0, ta1_y_xzz_xyzzz_1, ta1_y_xzz_xzzzz_0, ta1_y_xzz_xzzzz_1, ta1_y_xzz_yyyyy_0, ta1_y_xzz_yyyyy_1, ta1_y_xzz_yyyyz_0, ta1_y_xzz_yyyyz_1, ta1_y_xzz_yyyzz_0, ta1_y_xzz_yyyzz_1, ta1_y_xzz_yyzzz_0, ta1_y_xzz_yyzzz_1, ta1_y_xzz_yzzzz_0, ta1_y_xzz_yzzzz_1, ta1_y_xzz_zzzzz_0, ta1_y_xzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxxzz_xxxxx_0[i] = ta1_y_xxx_xxxxx_0[i] * fe_0 - ta1_y_xxx_xxxxx_1[i] * fe_0 + ta1_y_xxxz_xxxxx_0[i] * pa_z[i] - ta1_y_xxxz_xxxxx_1[i] * pc_z[i];

        ta1_y_xxxzz_xxxxy_0[i] = ta1_y_xxx_xxxxy_0[i] * fe_0 - ta1_y_xxx_xxxxy_1[i] * fe_0 + ta1_y_xxxz_xxxxy_0[i] * pa_z[i] - ta1_y_xxxz_xxxxy_1[i] * pc_z[i];

        ta1_y_xxxzz_xxxxz_0[i] = 2.0 * ta1_y_xzz_xxxxz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxxxz_1[i] * fe_0 + 4.0 * ta1_y_xxzz_xxxz_0[i] * fe_0 - 4.0 * ta1_y_xxzz_xxxz_1[i] * fe_0 + ta1_y_xxzz_xxxxz_0[i] * pa_x[i] - ta1_y_xxzz_xxxxz_1[i] * pc_x[i];

        ta1_y_xxxzz_xxxyy_0[i] = ta1_y_xxx_xxxyy_0[i] * fe_0 - ta1_y_xxx_xxxyy_1[i] * fe_0 + ta1_y_xxxz_xxxyy_0[i] * pa_z[i] - ta1_y_xxxz_xxxyy_1[i] * pc_z[i];

        ta1_y_xxxzz_xxxyz_0[i] = 2.0 * ta1_y_xzz_xxxyz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxxyz_1[i] * fe_0 + 3.0 * ta1_y_xxzz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_xxzz_xxyz_1[i] * fe_0 + ta1_y_xxzz_xxxyz_0[i] * pa_x[i] - ta1_y_xxzz_xxxyz_1[i] * pc_x[i];

        ta1_y_xxxzz_xxxzz_0[i] = 2.0 * ta1_y_xzz_xxxzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxxzz_1[i] * fe_0 + 3.0 * ta1_y_xxzz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_xxzz_xxzz_1[i] * fe_0 + ta1_y_xxzz_xxxzz_0[i] * pa_x[i] - ta1_y_xxzz_xxxzz_1[i] * pc_x[i];

        ta1_y_xxxzz_xxyyy_0[i] = ta1_y_xxx_xxyyy_0[i] * fe_0 - ta1_y_xxx_xxyyy_1[i] * fe_0 + ta1_y_xxxz_xxyyy_0[i] * pa_z[i] - ta1_y_xxxz_xxyyy_1[i] * pc_z[i];

        ta1_y_xxxzz_xxyyz_0[i] = 2.0 * ta1_y_xzz_xxyyz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_xxzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxzz_xyyz_1[i] * fe_0 + ta1_y_xxzz_xxyyz_0[i] * pa_x[i] - ta1_y_xxzz_xxyyz_1[i] * pc_x[i];

        ta1_y_xxxzz_xxyzz_0[i] = 2.0 * ta1_y_xzz_xxyzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_xxzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xxzz_xyzz_1[i] * fe_0 + ta1_y_xxzz_xxyzz_0[i] * pa_x[i] - ta1_y_xxzz_xxyzz_1[i] * pc_x[i];

        ta1_y_xxxzz_xxzzz_0[i] = 2.0 * ta1_y_xzz_xxzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xxzzz_1[i] * fe_0 + 2.0 * ta1_y_xxzz_xzzz_0[i] * fe_0 - 2.0 * ta1_y_xxzz_xzzz_1[i] * fe_0 + ta1_y_xxzz_xxzzz_0[i] * pa_x[i] - ta1_y_xxzz_xxzzz_1[i] * pc_x[i];

        ta1_y_xxxzz_xyyyy_0[i] = ta1_y_xxx_xyyyy_0[i] * fe_0 - ta1_y_xxx_xyyyy_1[i] * fe_0 + ta1_y_xxxz_xyyyy_0[i] * pa_z[i] - ta1_y_xxxz_xyyyy_1[i] * pc_z[i];

        ta1_y_xxxzz_xyyyz_0[i] = 2.0 * ta1_y_xzz_xyyyz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xyyyz_1[i] * fe_0 + ta1_y_xxzz_yyyz_0[i] * fe_0 - ta1_y_xxzz_yyyz_1[i] * fe_0 + ta1_y_xxzz_xyyyz_0[i] * pa_x[i] - ta1_y_xxzz_xyyyz_1[i] * pc_x[i];

        ta1_y_xxxzz_xyyzz_0[i] = 2.0 * ta1_y_xzz_xyyzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xyyzz_1[i] * fe_0 + ta1_y_xxzz_yyzz_0[i] * fe_0 - ta1_y_xxzz_yyzz_1[i] * fe_0 + ta1_y_xxzz_xyyzz_0[i] * pa_x[i] - ta1_y_xxzz_xyyzz_1[i] * pc_x[i];

        ta1_y_xxxzz_xyzzz_0[i] = 2.0 * ta1_y_xzz_xyzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xyzzz_1[i] * fe_0 + ta1_y_xxzz_yzzz_0[i] * fe_0 - ta1_y_xxzz_yzzz_1[i] * fe_0 + ta1_y_xxzz_xyzzz_0[i] * pa_x[i] - ta1_y_xxzz_xyzzz_1[i] * pc_x[i];

        ta1_y_xxxzz_xzzzz_0[i] = 2.0 * ta1_y_xzz_xzzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_xzzzz_1[i] * fe_0 + ta1_y_xxzz_zzzz_0[i] * fe_0 - ta1_y_xxzz_zzzz_1[i] * fe_0 + ta1_y_xxzz_xzzzz_0[i] * pa_x[i] - ta1_y_xxzz_xzzzz_1[i] * pc_x[i];

        ta1_y_xxxzz_yyyyy_0[i] = 2.0 * ta1_y_xzz_yyyyy_0[i] * fe_0 - 2.0 * ta1_y_xzz_yyyyy_1[i] * fe_0 + ta1_y_xxzz_yyyyy_0[i] * pa_x[i] - ta1_y_xxzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xxxzz_yyyyz_0[i] = 2.0 * ta1_y_xzz_yyyyz_0[i] * fe_0 - 2.0 * ta1_y_xzz_yyyyz_1[i] * fe_0 + ta1_y_xxzz_yyyyz_0[i] * pa_x[i] - ta1_y_xxzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxxzz_yyyzz_0[i] = 2.0 * ta1_y_xzz_yyyzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_yyyzz_1[i] * fe_0 + ta1_y_xxzz_yyyzz_0[i] * pa_x[i] - ta1_y_xxzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxxzz_yyzzz_0[i] = 2.0 * ta1_y_xzz_yyzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_yyzzz_1[i] * fe_0 + ta1_y_xxzz_yyzzz_0[i] * pa_x[i] - ta1_y_xxzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxxzz_yzzzz_0[i] = 2.0 * ta1_y_xzz_yzzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_yzzzz_1[i] * fe_0 + ta1_y_xxzz_yzzzz_0[i] * pa_x[i] - ta1_y_xxzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxxzz_zzzzz_0[i] = 2.0 * ta1_y_xzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_y_xzz_zzzzz_1[i] * fe_0 + ta1_y_xxzz_zzzzz_0[i] * pa_x[i] - ta1_y_xxzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 567-588 components of targeted buffer : HH

    auto ta1_y_xxyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 567);

    auto ta1_y_xxyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 568);

    auto ta1_y_xxyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 569);

    auto ta1_y_xxyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 570);

    auto ta1_y_xxyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 571);

    auto ta1_y_xxyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 572);

    auto ta1_y_xxyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 573);

    auto ta1_y_xxyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 574);

    auto ta1_y_xxyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 575);

    auto ta1_y_xxyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 576);

    auto ta1_y_xxyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 577);

    auto ta1_y_xxyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 578);

    auto ta1_y_xxyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 579);

    auto ta1_y_xxyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 580);

    auto ta1_y_xxyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 581);

    auto ta1_y_xxyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 582);

    auto ta1_y_xxyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 583);

    auto ta1_y_xxyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 584);

    auto ta1_y_xxyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 585);

    auto ta1_y_xxyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 586);

    auto ta1_y_xxyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 587);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_y_xxy_xxxxx_0, ta1_y_xxy_xxxxx_1, ta1_y_xxy_xxxxz_0, ta1_y_xxy_xxxxz_1, ta1_y_xxy_xxxzz_0, ta1_y_xxy_xxxzz_1, ta1_y_xxy_xxzzz_0, ta1_y_xxy_xxzzz_1, ta1_y_xxy_xzzzz_0, ta1_y_xxy_xzzzz_1, ta1_y_xxyy_xxxxx_0, ta1_y_xxyy_xxxxx_1, ta1_y_xxyy_xxxxz_0, ta1_y_xxyy_xxxxz_1, ta1_y_xxyy_xxxzz_0, ta1_y_xxyy_xxxzz_1, ta1_y_xxyy_xxzzz_0, ta1_y_xxyy_xxzzz_1, ta1_y_xxyy_xzzzz_0, ta1_y_xxyy_xzzzz_1, ta1_y_xxyyy_xxxxx_0, ta1_y_xxyyy_xxxxy_0, ta1_y_xxyyy_xxxxz_0, ta1_y_xxyyy_xxxyy_0, ta1_y_xxyyy_xxxyz_0, ta1_y_xxyyy_xxxzz_0, ta1_y_xxyyy_xxyyy_0, ta1_y_xxyyy_xxyyz_0, ta1_y_xxyyy_xxyzz_0, ta1_y_xxyyy_xxzzz_0, ta1_y_xxyyy_xyyyy_0, ta1_y_xxyyy_xyyyz_0, ta1_y_xxyyy_xyyzz_0, ta1_y_xxyyy_xyzzz_0, ta1_y_xxyyy_xzzzz_0, ta1_y_xxyyy_yyyyy_0, ta1_y_xxyyy_yyyyz_0, ta1_y_xxyyy_yyyzz_0, ta1_y_xxyyy_yyzzz_0, ta1_y_xxyyy_yzzzz_0, ta1_y_xxyyy_zzzzz_0, ta1_y_xyyy_xxxxy_0, ta1_y_xyyy_xxxxy_1, ta1_y_xyyy_xxxy_0, ta1_y_xyyy_xxxy_1, ta1_y_xyyy_xxxyy_0, ta1_y_xyyy_xxxyy_1, ta1_y_xyyy_xxxyz_0, ta1_y_xyyy_xxxyz_1, ta1_y_xyyy_xxyy_0, ta1_y_xyyy_xxyy_1, ta1_y_xyyy_xxyyy_0, ta1_y_xyyy_xxyyy_1, ta1_y_xyyy_xxyyz_0, ta1_y_xyyy_xxyyz_1, ta1_y_xyyy_xxyz_0, ta1_y_xyyy_xxyz_1, ta1_y_xyyy_xxyzz_0, ta1_y_xyyy_xxyzz_1, ta1_y_xyyy_xyyy_0, ta1_y_xyyy_xyyy_1, ta1_y_xyyy_xyyyy_0, ta1_y_xyyy_xyyyy_1, ta1_y_xyyy_xyyyz_0, ta1_y_xyyy_xyyyz_1, ta1_y_xyyy_xyyz_0, ta1_y_xyyy_xyyz_1, ta1_y_xyyy_xyyzz_0, ta1_y_xyyy_xyyzz_1, ta1_y_xyyy_xyzz_0, ta1_y_xyyy_xyzz_1, ta1_y_xyyy_xyzzz_0, ta1_y_xyyy_xyzzz_1, ta1_y_xyyy_yyyy_0, ta1_y_xyyy_yyyy_1, ta1_y_xyyy_yyyyy_0, ta1_y_xyyy_yyyyy_1, ta1_y_xyyy_yyyyz_0, ta1_y_xyyy_yyyyz_1, ta1_y_xyyy_yyyz_0, ta1_y_xyyy_yyyz_1, ta1_y_xyyy_yyyzz_0, ta1_y_xyyy_yyyzz_1, ta1_y_xyyy_yyzz_0, ta1_y_xyyy_yyzz_1, ta1_y_xyyy_yyzzz_0, ta1_y_xyyy_yyzzz_1, ta1_y_xyyy_yzzz_0, ta1_y_xyyy_yzzz_1, ta1_y_xyyy_yzzzz_0, ta1_y_xyyy_yzzzz_1, ta1_y_xyyy_zzzzz_0, ta1_y_xyyy_zzzzz_1, ta1_y_yyy_xxxxy_0, ta1_y_yyy_xxxxy_1, ta1_y_yyy_xxxyy_0, ta1_y_yyy_xxxyy_1, ta1_y_yyy_xxxyz_0, ta1_y_yyy_xxxyz_1, ta1_y_yyy_xxyyy_0, ta1_y_yyy_xxyyy_1, ta1_y_yyy_xxyyz_0, ta1_y_yyy_xxyyz_1, ta1_y_yyy_xxyzz_0, ta1_y_yyy_xxyzz_1, ta1_y_yyy_xyyyy_0, ta1_y_yyy_xyyyy_1, ta1_y_yyy_xyyyz_0, ta1_y_yyy_xyyyz_1, ta1_y_yyy_xyyzz_0, ta1_y_yyy_xyyzz_1, ta1_y_yyy_xyzzz_0, ta1_y_yyy_xyzzz_1, ta1_y_yyy_yyyyy_0, ta1_y_yyy_yyyyy_1, ta1_y_yyy_yyyyz_0, ta1_y_yyy_yyyyz_1, ta1_y_yyy_yyyzz_0, ta1_y_yyy_yyyzz_1, ta1_y_yyy_yyzzz_0, ta1_y_yyy_yyzzz_1, ta1_y_yyy_yzzzz_0, ta1_y_yyy_yzzzz_1, ta1_y_yyy_zzzzz_0, ta1_y_yyy_zzzzz_1, ta_xxyy_xxxxx_1, ta_xxyy_xxxxz_1, ta_xxyy_xxxzz_1, ta_xxyy_xxzzz_1, ta_xxyy_xzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxyyy_xxxxx_0[i] = 2.0 * ta1_y_xxy_xxxxx_0[i] * fe_0 - 2.0 * ta1_y_xxy_xxxxx_1[i] * fe_0 + ta_xxyy_xxxxx_1[i] + ta1_y_xxyy_xxxxx_0[i] * pa_y[i] - ta1_y_xxyy_xxxxx_1[i] * pc_y[i];

        ta1_y_xxyyy_xxxxy_0[i] = ta1_y_yyy_xxxxy_0[i] * fe_0 - ta1_y_yyy_xxxxy_1[i] * fe_0 + 4.0 * ta1_y_xyyy_xxxy_0[i] * fe_0 - 4.0 * ta1_y_xyyy_xxxy_1[i] * fe_0 + ta1_y_xyyy_xxxxy_0[i] * pa_x[i] - ta1_y_xyyy_xxxxy_1[i] * pc_x[i];

        ta1_y_xxyyy_xxxxz_0[i] = 2.0 * ta1_y_xxy_xxxxz_0[i] * fe_0 - 2.0 * ta1_y_xxy_xxxxz_1[i] * fe_0 + ta_xxyy_xxxxz_1[i] + ta1_y_xxyy_xxxxz_0[i] * pa_y[i] - ta1_y_xxyy_xxxxz_1[i] * pc_y[i];

        ta1_y_xxyyy_xxxyy_0[i] = ta1_y_yyy_xxxyy_0[i] * fe_0 - ta1_y_yyy_xxxyy_1[i] * fe_0 + 3.0 * ta1_y_xyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_y_xyyy_xxyy_1[i] * fe_0 + ta1_y_xyyy_xxxyy_0[i] * pa_x[i] - ta1_y_xyyy_xxxyy_1[i] * pc_x[i];

        ta1_y_xxyyy_xxxyz_0[i] = ta1_y_yyy_xxxyz_0[i] * fe_0 - ta1_y_yyy_xxxyz_1[i] * fe_0 + 3.0 * ta1_y_xyyy_xxyz_0[i] * fe_0 - 3.0 * ta1_y_xyyy_xxyz_1[i] * fe_0 + ta1_y_xyyy_xxxyz_0[i] * pa_x[i] - ta1_y_xyyy_xxxyz_1[i] * pc_x[i];

        ta1_y_xxyyy_xxxzz_0[i] = 2.0 * ta1_y_xxy_xxxzz_0[i] * fe_0 - 2.0 * ta1_y_xxy_xxxzz_1[i] * fe_0 + ta_xxyy_xxxzz_1[i] + ta1_y_xxyy_xxxzz_0[i] * pa_y[i] - ta1_y_xxyy_xxxzz_1[i] * pc_y[i];

        ta1_y_xxyyy_xxyyy_0[i] = ta1_y_yyy_xxyyy_0[i] * fe_0 - ta1_y_yyy_xxyyy_1[i] * fe_0 + 2.0 * ta1_y_xyyy_xyyy_0[i] * fe_0 - 2.0 * ta1_y_xyyy_xyyy_1[i] * fe_0 + ta1_y_xyyy_xxyyy_0[i] * pa_x[i] - ta1_y_xyyy_xxyyy_1[i] * pc_x[i];

        ta1_y_xxyyy_xxyyz_0[i] = ta1_y_yyy_xxyyz_0[i] * fe_0 - ta1_y_yyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_xyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xyyy_xyyz_1[i] * fe_0 + ta1_y_xyyy_xxyyz_0[i] * pa_x[i] - ta1_y_xyyy_xxyyz_1[i] * pc_x[i];

        ta1_y_xxyyy_xxyzz_0[i] = ta1_y_yyy_xxyzz_0[i] * fe_0 - ta1_y_yyy_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_xyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xyyy_xyzz_1[i] * fe_0 + ta1_y_xyyy_xxyzz_0[i] * pa_x[i] - ta1_y_xyyy_xxyzz_1[i] * pc_x[i];

        ta1_y_xxyyy_xxzzz_0[i] = 2.0 * ta1_y_xxy_xxzzz_0[i] * fe_0 - 2.0 * ta1_y_xxy_xxzzz_1[i] * fe_0 + ta_xxyy_xxzzz_1[i] + ta1_y_xxyy_xxzzz_0[i] * pa_y[i] - ta1_y_xxyy_xxzzz_1[i] * pc_y[i];

        ta1_y_xxyyy_xyyyy_0[i] = ta1_y_yyy_xyyyy_0[i] * fe_0 - ta1_y_yyy_xyyyy_1[i] * fe_0 + ta1_y_xyyy_yyyy_0[i] * fe_0 - ta1_y_xyyy_yyyy_1[i] * fe_0 + ta1_y_xyyy_xyyyy_0[i] * pa_x[i] - ta1_y_xyyy_xyyyy_1[i] * pc_x[i];

        ta1_y_xxyyy_xyyyz_0[i] = ta1_y_yyy_xyyyz_0[i] * fe_0 - ta1_y_yyy_xyyyz_1[i] * fe_0 + ta1_y_xyyy_yyyz_0[i] * fe_0 - ta1_y_xyyy_yyyz_1[i] * fe_0 + ta1_y_xyyy_xyyyz_0[i] * pa_x[i] - ta1_y_xyyy_xyyyz_1[i] * pc_x[i];

        ta1_y_xxyyy_xyyzz_0[i] = ta1_y_yyy_xyyzz_0[i] * fe_0 - ta1_y_yyy_xyyzz_1[i] * fe_0 + ta1_y_xyyy_yyzz_0[i] * fe_0 - ta1_y_xyyy_yyzz_1[i] * fe_0 + ta1_y_xyyy_xyyzz_0[i] * pa_x[i] - ta1_y_xyyy_xyyzz_1[i] * pc_x[i];

        ta1_y_xxyyy_xyzzz_0[i] = ta1_y_yyy_xyzzz_0[i] * fe_0 - ta1_y_yyy_xyzzz_1[i] * fe_0 + ta1_y_xyyy_yzzz_0[i] * fe_0 - ta1_y_xyyy_yzzz_1[i] * fe_0 + ta1_y_xyyy_xyzzz_0[i] * pa_x[i] - ta1_y_xyyy_xyzzz_1[i] * pc_x[i];

        ta1_y_xxyyy_xzzzz_0[i] = 2.0 * ta1_y_xxy_xzzzz_0[i] * fe_0 - 2.0 * ta1_y_xxy_xzzzz_1[i] * fe_0 + ta_xxyy_xzzzz_1[i] + ta1_y_xxyy_xzzzz_0[i] * pa_y[i] - ta1_y_xxyy_xzzzz_1[i] * pc_y[i];

        ta1_y_xxyyy_yyyyy_0[i] = ta1_y_yyy_yyyyy_0[i] * fe_0 - ta1_y_yyy_yyyyy_1[i] * fe_0 + ta1_y_xyyy_yyyyy_0[i] * pa_x[i] - ta1_y_xyyy_yyyyy_1[i] * pc_x[i];

        ta1_y_xxyyy_yyyyz_0[i] = ta1_y_yyy_yyyyz_0[i] * fe_0 - ta1_y_yyy_yyyyz_1[i] * fe_0 + ta1_y_xyyy_yyyyz_0[i] * pa_x[i] - ta1_y_xyyy_yyyyz_1[i] * pc_x[i];

        ta1_y_xxyyy_yyyzz_0[i] = ta1_y_yyy_yyyzz_0[i] * fe_0 - ta1_y_yyy_yyyzz_1[i] * fe_0 + ta1_y_xyyy_yyyzz_0[i] * pa_x[i] - ta1_y_xyyy_yyyzz_1[i] * pc_x[i];

        ta1_y_xxyyy_yyzzz_0[i] = ta1_y_yyy_yyzzz_0[i] * fe_0 - ta1_y_yyy_yyzzz_1[i] * fe_0 + ta1_y_xyyy_yyzzz_0[i] * pa_x[i] - ta1_y_xyyy_yyzzz_1[i] * pc_x[i];

        ta1_y_xxyyy_yzzzz_0[i] = ta1_y_yyy_yzzzz_0[i] * fe_0 - ta1_y_yyy_yzzzz_1[i] * fe_0 + ta1_y_xyyy_yzzzz_0[i] * pa_x[i] - ta1_y_xyyy_yzzzz_1[i] * pc_x[i];

        ta1_y_xxyyy_zzzzz_0[i] = ta1_y_yyy_zzzzz_0[i] * fe_0 - ta1_y_yyy_zzzzz_1[i] * fe_0 + ta1_y_xyyy_zzzzz_0[i] * pa_x[i] - ta1_y_xyyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 588-609 components of targeted buffer : HH

    auto ta1_y_xxyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 588);

    auto ta1_y_xxyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 589);

    auto ta1_y_xxyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 590);

    auto ta1_y_xxyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 591);

    auto ta1_y_xxyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 592);

    auto ta1_y_xxyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 593);

    auto ta1_y_xxyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 594);

    auto ta1_y_xxyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 595);

    auto ta1_y_xxyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 596);

    auto ta1_y_xxyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 597);

    auto ta1_y_xxyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 598);

    auto ta1_y_xxyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 599);

    auto ta1_y_xxyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 600);

    auto ta1_y_xxyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 601);

    auto ta1_y_xxyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 602);

    auto ta1_y_xxyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 603);

    auto ta1_y_xxyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 604);

    auto ta1_y_xxyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 605);

    auto ta1_y_xxyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 606);

    auto ta1_y_xxyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 607);

    auto ta1_y_xxyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 608);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_y_xxyy_xxxx_0, ta1_y_xxyy_xxxx_1, ta1_y_xxyy_xxxxx_0, ta1_y_xxyy_xxxxx_1, ta1_y_xxyy_xxxxy_0, ta1_y_xxyy_xxxxy_1, ta1_y_xxyy_xxxxz_0, ta1_y_xxyy_xxxxz_1, ta1_y_xxyy_xxxy_0, ta1_y_xxyy_xxxy_1, ta1_y_xxyy_xxxyy_0, ta1_y_xxyy_xxxyy_1, ta1_y_xxyy_xxxyz_0, ta1_y_xxyy_xxxyz_1, ta1_y_xxyy_xxxz_0, ta1_y_xxyy_xxxz_1, ta1_y_xxyy_xxxzz_0, ta1_y_xxyy_xxxzz_1, ta1_y_xxyy_xxyy_0, ta1_y_xxyy_xxyy_1, ta1_y_xxyy_xxyyy_0, ta1_y_xxyy_xxyyy_1, ta1_y_xxyy_xxyyz_0, ta1_y_xxyy_xxyyz_1, ta1_y_xxyy_xxyz_0, ta1_y_xxyy_xxyz_1, ta1_y_xxyy_xxyzz_0, ta1_y_xxyy_xxyzz_1, ta1_y_xxyy_xxzz_0, ta1_y_xxyy_xxzz_1, ta1_y_xxyy_xxzzz_0, ta1_y_xxyy_xxzzz_1, ta1_y_xxyy_xyyy_0, ta1_y_xxyy_xyyy_1, ta1_y_xxyy_xyyyy_0, ta1_y_xxyy_xyyyy_1, ta1_y_xxyy_xyyyz_0, ta1_y_xxyy_xyyyz_1, ta1_y_xxyy_xyyz_0, ta1_y_xxyy_xyyz_1, ta1_y_xxyy_xyyzz_0, ta1_y_xxyy_xyyzz_1, ta1_y_xxyy_xyzz_0, ta1_y_xxyy_xyzz_1, ta1_y_xxyy_xyzzz_0, ta1_y_xxyy_xyzzz_1, ta1_y_xxyy_xzzz_0, ta1_y_xxyy_xzzz_1, ta1_y_xxyy_xzzzz_0, ta1_y_xxyy_xzzzz_1, ta1_y_xxyy_yyyyy_0, ta1_y_xxyy_yyyyy_1, ta1_y_xxyyz_xxxxx_0, ta1_y_xxyyz_xxxxy_0, ta1_y_xxyyz_xxxxz_0, ta1_y_xxyyz_xxxyy_0, ta1_y_xxyyz_xxxyz_0, ta1_y_xxyyz_xxxzz_0, ta1_y_xxyyz_xxyyy_0, ta1_y_xxyyz_xxyyz_0, ta1_y_xxyyz_xxyzz_0, ta1_y_xxyyz_xxzzz_0, ta1_y_xxyyz_xyyyy_0, ta1_y_xxyyz_xyyyz_0, ta1_y_xxyyz_xyyzz_0, ta1_y_xxyyz_xyzzz_0, ta1_y_xxyyz_xzzzz_0, ta1_y_xxyyz_yyyyy_0, ta1_y_xxyyz_yyyyz_0, ta1_y_xxyyz_yyyzz_0, ta1_y_xxyyz_yyzzz_0, ta1_y_xxyyz_yzzzz_0, ta1_y_xxyyz_zzzzz_0, ta1_y_xyyz_yyyyz_0, ta1_y_xyyz_yyyyz_1, ta1_y_xyyz_yyyzz_0, ta1_y_xyyz_yyyzz_1, ta1_y_xyyz_yyzzz_0, ta1_y_xyyz_yyzzz_1, ta1_y_xyyz_yzzzz_0, ta1_y_xyyz_yzzzz_1, ta1_y_xyyz_zzzzz_0, ta1_y_xyyz_zzzzz_1, ta1_y_yyz_yyyyz_0, ta1_y_yyz_yyyyz_1, ta1_y_yyz_yyyzz_0, ta1_y_yyz_yyyzz_1, ta1_y_yyz_yyzzz_0, ta1_y_yyz_yyzzz_1, ta1_y_yyz_yzzzz_0, ta1_y_yyz_yzzzz_1, ta1_y_yyz_zzzzz_0, ta1_y_yyz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxyyz_xxxxx_0[i] = ta1_y_xxyy_xxxxx_0[i] * pa_z[i] - ta1_y_xxyy_xxxxx_1[i] * pc_z[i];

        ta1_y_xxyyz_xxxxy_0[i] = ta1_y_xxyy_xxxxy_0[i] * pa_z[i] - ta1_y_xxyy_xxxxy_1[i] * pc_z[i];

        ta1_y_xxyyz_xxxxz_0[i] = ta1_y_xxyy_xxxx_0[i] * fe_0 - ta1_y_xxyy_xxxx_1[i] * fe_0 + ta1_y_xxyy_xxxxz_0[i] * pa_z[i] - ta1_y_xxyy_xxxxz_1[i] * pc_z[i];

        ta1_y_xxyyz_xxxyy_0[i] = ta1_y_xxyy_xxxyy_0[i] * pa_z[i] - ta1_y_xxyy_xxxyy_1[i] * pc_z[i];

        ta1_y_xxyyz_xxxyz_0[i] = ta1_y_xxyy_xxxy_0[i] * fe_0 - ta1_y_xxyy_xxxy_1[i] * fe_0 + ta1_y_xxyy_xxxyz_0[i] * pa_z[i] - ta1_y_xxyy_xxxyz_1[i] * pc_z[i];

        ta1_y_xxyyz_xxxzz_0[i] = 2.0 * ta1_y_xxyy_xxxz_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xxxz_1[i] * fe_0 + ta1_y_xxyy_xxxzz_0[i] * pa_z[i] - ta1_y_xxyy_xxxzz_1[i] * pc_z[i];

        ta1_y_xxyyz_xxyyy_0[i] = ta1_y_xxyy_xxyyy_0[i] * pa_z[i] - ta1_y_xxyy_xxyyy_1[i] * pc_z[i];

        ta1_y_xxyyz_xxyyz_0[i] = ta1_y_xxyy_xxyy_0[i] * fe_0 - ta1_y_xxyy_xxyy_1[i] * fe_0 + ta1_y_xxyy_xxyyz_0[i] * pa_z[i] - ta1_y_xxyy_xxyyz_1[i] * pc_z[i];

        ta1_y_xxyyz_xxyzz_0[i] = 2.0 * ta1_y_xxyy_xxyz_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xxyz_1[i] * fe_0 + ta1_y_xxyy_xxyzz_0[i] * pa_z[i] - ta1_y_xxyy_xxyzz_1[i] * pc_z[i];

        ta1_y_xxyyz_xxzzz_0[i] = 3.0 * ta1_y_xxyy_xxzz_0[i] * fe_0 - 3.0 * ta1_y_xxyy_xxzz_1[i] * fe_0 + ta1_y_xxyy_xxzzz_0[i] * pa_z[i] - ta1_y_xxyy_xxzzz_1[i] * pc_z[i];

        ta1_y_xxyyz_xyyyy_0[i] = ta1_y_xxyy_xyyyy_0[i] * pa_z[i] - ta1_y_xxyy_xyyyy_1[i] * pc_z[i];

        ta1_y_xxyyz_xyyyz_0[i] = ta1_y_xxyy_xyyy_0[i] * fe_0 - ta1_y_xxyy_xyyy_1[i] * fe_0 + ta1_y_xxyy_xyyyz_0[i] * pa_z[i] - ta1_y_xxyy_xyyyz_1[i] * pc_z[i];

        ta1_y_xxyyz_xyyzz_0[i] = 2.0 * ta1_y_xxyy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xxyy_xyyz_1[i] * fe_0 + ta1_y_xxyy_xyyzz_0[i] * pa_z[i] - ta1_y_xxyy_xyyzz_1[i] * pc_z[i];

        ta1_y_xxyyz_xyzzz_0[i] = 3.0 * ta1_y_xxyy_xyzz_0[i] * fe_0 - 3.0 * ta1_y_xxyy_xyzz_1[i] * fe_0 + ta1_y_xxyy_xyzzz_0[i] * pa_z[i] - ta1_y_xxyy_xyzzz_1[i] * pc_z[i];

        ta1_y_xxyyz_xzzzz_0[i] = 4.0 * ta1_y_xxyy_xzzz_0[i] * fe_0 - 4.0 * ta1_y_xxyy_xzzz_1[i] * fe_0 + ta1_y_xxyy_xzzzz_0[i] * pa_z[i] - ta1_y_xxyy_xzzzz_1[i] * pc_z[i];

        ta1_y_xxyyz_yyyyy_0[i] = ta1_y_xxyy_yyyyy_0[i] * pa_z[i] - ta1_y_xxyy_yyyyy_1[i] * pc_z[i];

        ta1_y_xxyyz_yyyyz_0[i] = ta1_y_yyz_yyyyz_0[i] * fe_0 - ta1_y_yyz_yyyyz_1[i] * fe_0 + ta1_y_xyyz_yyyyz_0[i] * pa_x[i] - ta1_y_xyyz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxyyz_yyyzz_0[i] = ta1_y_yyz_yyyzz_0[i] * fe_0 - ta1_y_yyz_yyyzz_1[i] * fe_0 + ta1_y_xyyz_yyyzz_0[i] * pa_x[i] - ta1_y_xyyz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxyyz_yyzzz_0[i] = ta1_y_yyz_yyzzz_0[i] * fe_0 - ta1_y_yyz_yyzzz_1[i] * fe_0 + ta1_y_xyyz_yyzzz_0[i] * pa_x[i] - ta1_y_xyyz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxyyz_yzzzz_0[i] = ta1_y_yyz_yzzzz_0[i] * fe_0 - ta1_y_yyz_yzzzz_1[i] * fe_0 + ta1_y_xyyz_yzzzz_0[i] * pa_x[i] - ta1_y_xyyz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxyyz_zzzzz_0[i] = ta1_y_yyz_zzzzz_0[i] * fe_0 - ta1_y_yyz_zzzzz_1[i] * fe_0 + ta1_y_xyyz_zzzzz_0[i] * pa_x[i] - ta1_y_xyyz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 609-630 components of targeted buffer : HH

    auto ta1_y_xxyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 609);

    auto ta1_y_xxyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 610);

    auto ta1_y_xxyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 611);

    auto ta1_y_xxyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 612);

    auto ta1_y_xxyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 613);

    auto ta1_y_xxyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 614);

    auto ta1_y_xxyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 615);

    auto ta1_y_xxyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 616);

    auto ta1_y_xxyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 617);

    auto ta1_y_xxyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 618);

    auto ta1_y_xxyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 619);

    auto ta1_y_xxyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 620);

    auto ta1_y_xxyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 621);

    auto ta1_y_xxyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 622);

    auto ta1_y_xxyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 623);

    auto ta1_y_xxyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 624);

    auto ta1_y_xxyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 625);

    auto ta1_y_xxyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 626);

    auto ta1_y_xxyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 627);

    auto ta1_y_xxyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 628);

    auto ta1_y_xxyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 629);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_y_xxy_xxxxy_0, ta1_y_xxy_xxxxy_1, ta1_y_xxy_xxxyy_0, ta1_y_xxy_xxxyy_1, ta1_y_xxy_xxyyy_0, ta1_y_xxy_xxyyy_1, ta1_y_xxy_xyyyy_0, ta1_y_xxy_xyyyy_1, ta1_y_xxyz_xxxxy_0, ta1_y_xxyz_xxxxy_1, ta1_y_xxyz_xxxyy_0, ta1_y_xxyz_xxxyy_1, ta1_y_xxyz_xxyyy_0, ta1_y_xxyz_xxyyy_1, ta1_y_xxyz_xyyyy_0, ta1_y_xxyz_xyyyy_1, ta1_y_xxyzz_xxxxx_0, ta1_y_xxyzz_xxxxy_0, ta1_y_xxyzz_xxxxz_0, ta1_y_xxyzz_xxxyy_0, ta1_y_xxyzz_xxxyz_0, ta1_y_xxyzz_xxxzz_0, ta1_y_xxyzz_xxyyy_0, ta1_y_xxyzz_xxyyz_0, ta1_y_xxyzz_xxyzz_0, ta1_y_xxyzz_xxzzz_0, ta1_y_xxyzz_xyyyy_0, ta1_y_xxyzz_xyyyz_0, ta1_y_xxyzz_xyyzz_0, ta1_y_xxyzz_xyzzz_0, ta1_y_xxyzz_xzzzz_0, ta1_y_xxyzz_yyyyy_0, ta1_y_xxyzz_yyyyz_0, ta1_y_xxyzz_yyyzz_0, ta1_y_xxyzz_yyzzz_0, ta1_y_xxyzz_yzzzz_0, ta1_y_xxyzz_zzzzz_0, ta1_y_xxzz_xxxxx_0, ta1_y_xxzz_xxxxx_1, ta1_y_xxzz_xxxxz_0, ta1_y_xxzz_xxxxz_1, ta1_y_xxzz_xxxyz_0, ta1_y_xxzz_xxxyz_1, ta1_y_xxzz_xxxz_0, ta1_y_xxzz_xxxz_1, ta1_y_xxzz_xxxzz_0, ta1_y_xxzz_xxxzz_1, ta1_y_xxzz_xxyyz_0, ta1_y_xxzz_xxyyz_1, ta1_y_xxzz_xxyz_0, ta1_y_xxzz_xxyz_1, ta1_y_xxzz_xxyzz_0, ta1_y_xxzz_xxyzz_1, ta1_y_xxzz_xxzz_0, ta1_y_xxzz_xxzz_1, ta1_y_xxzz_xxzzz_0, ta1_y_xxzz_xxzzz_1, ta1_y_xxzz_xyyyz_0, ta1_y_xxzz_xyyyz_1, ta1_y_xxzz_xyyz_0, ta1_y_xxzz_xyyz_1, ta1_y_xxzz_xyyzz_0, ta1_y_xxzz_xyyzz_1, ta1_y_xxzz_xyzz_0, ta1_y_xxzz_xyzz_1, ta1_y_xxzz_xyzzz_0, ta1_y_xxzz_xyzzz_1, ta1_y_xxzz_xzzz_0, ta1_y_xxzz_xzzz_1, ta1_y_xxzz_xzzzz_0, ta1_y_xxzz_xzzzz_1, ta1_y_xxzz_zzzzz_0, ta1_y_xxzz_zzzzz_1, ta1_y_xyzz_yyyyy_0, ta1_y_xyzz_yyyyy_1, ta1_y_xyzz_yyyyz_0, ta1_y_xyzz_yyyyz_1, ta1_y_xyzz_yyyzz_0, ta1_y_xyzz_yyyzz_1, ta1_y_xyzz_yyzzz_0, ta1_y_xyzz_yyzzz_1, ta1_y_xyzz_yzzzz_0, ta1_y_xyzz_yzzzz_1, ta1_y_yzz_yyyyy_0, ta1_y_yzz_yyyyy_1, ta1_y_yzz_yyyyz_0, ta1_y_yzz_yyyyz_1, ta1_y_yzz_yyyzz_0, ta1_y_yzz_yyyzz_1, ta1_y_yzz_yyzzz_0, ta1_y_yzz_yyzzz_1, ta1_y_yzz_yzzzz_0, ta1_y_yzz_yzzzz_1, ta_xxzz_xxxxx_1, ta_xxzz_xxxxz_1, ta_xxzz_xxxyz_1, ta_xxzz_xxxzz_1, ta_xxzz_xxyyz_1, ta_xxzz_xxyzz_1, ta_xxzz_xxzzz_1, ta_xxzz_xyyyz_1, ta_xxzz_xyyzz_1, ta_xxzz_xyzzz_1, ta_xxzz_xzzzz_1, ta_xxzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxyzz_xxxxx_0[i] = ta_xxzz_xxxxx_1[i] + ta1_y_xxzz_xxxxx_0[i] * pa_y[i] - ta1_y_xxzz_xxxxx_1[i] * pc_y[i];

        ta1_y_xxyzz_xxxxy_0[i] = ta1_y_xxy_xxxxy_0[i] * fe_0 - ta1_y_xxy_xxxxy_1[i] * fe_0 + ta1_y_xxyz_xxxxy_0[i] * pa_z[i] - ta1_y_xxyz_xxxxy_1[i] * pc_z[i];

        ta1_y_xxyzz_xxxxz_0[i] = ta_xxzz_xxxxz_1[i] + ta1_y_xxzz_xxxxz_0[i] * pa_y[i] - ta1_y_xxzz_xxxxz_1[i] * pc_y[i];

        ta1_y_xxyzz_xxxyy_0[i] = ta1_y_xxy_xxxyy_0[i] * fe_0 - ta1_y_xxy_xxxyy_1[i] * fe_0 + ta1_y_xxyz_xxxyy_0[i] * pa_z[i] - ta1_y_xxyz_xxxyy_1[i] * pc_z[i];

        ta1_y_xxyzz_xxxyz_0[i] = ta1_y_xxzz_xxxz_0[i] * fe_0 - ta1_y_xxzz_xxxz_1[i] * fe_0 + ta_xxzz_xxxyz_1[i] + ta1_y_xxzz_xxxyz_0[i] * pa_y[i] - ta1_y_xxzz_xxxyz_1[i] * pc_y[i];

        ta1_y_xxyzz_xxxzz_0[i] = ta_xxzz_xxxzz_1[i] + ta1_y_xxzz_xxxzz_0[i] * pa_y[i] - ta1_y_xxzz_xxxzz_1[i] * pc_y[i];

        ta1_y_xxyzz_xxyyy_0[i] = ta1_y_xxy_xxyyy_0[i] * fe_0 - ta1_y_xxy_xxyyy_1[i] * fe_0 + ta1_y_xxyz_xxyyy_0[i] * pa_z[i] - ta1_y_xxyz_xxyyy_1[i] * pc_z[i];

        ta1_y_xxyzz_xxyyz_0[i] = 2.0 * ta1_y_xxzz_xxyz_0[i] * fe_0 - 2.0 * ta1_y_xxzz_xxyz_1[i] * fe_0 + ta_xxzz_xxyyz_1[i] + ta1_y_xxzz_xxyyz_0[i] * pa_y[i] - ta1_y_xxzz_xxyyz_1[i] * pc_y[i];

        ta1_y_xxyzz_xxyzz_0[i] = ta1_y_xxzz_xxzz_0[i] * fe_0 - ta1_y_xxzz_xxzz_1[i] * fe_0 + ta_xxzz_xxyzz_1[i] + ta1_y_xxzz_xxyzz_0[i] * pa_y[i] - ta1_y_xxzz_xxyzz_1[i] * pc_y[i];

        ta1_y_xxyzz_xxzzz_0[i] = ta_xxzz_xxzzz_1[i] + ta1_y_xxzz_xxzzz_0[i] * pa_y[i] - ta1_y_xxzz_xxzzz_1[i] * pc_y[i];

        ta1_y_xxyzz_xyyyy_0[i] = ta1_y_xxy_xyyyy_0[i] * fe_0 - ta1_y_xxy_xyyyy_1[i] * fe_0 + ta1_y_xxyz_xyyyy_0[i] * pa_z[i] - ta1_y_xxyz_xyyyy_1[i] * pc_z[i];

        ta1_y_xxyzz_xyyyz_0[i] = 3.0 * ta1_y_xxzz_xyyz_0[i] * fe_0 - 3.0 * ta1_y_xxzz_xyyz_1[i] * fe_0 + ta_xxzz_xyyyz_1[i] + ta1_y_xxzz_xyyyz_0[i] * pa_y[i] - ta1_y_xxzz_xyyyz_1[i] * pc_y[i];

        ta1_y_xxyzz_xyyzz_0[i] = 2.0 * ta1_y_xxzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xxzz_xyzz_1[i] * fe_0 + ta_xxzz_xyyzz_1[i] + ta1_y_xxzz_xyyzz_0[i] * pa_y[i] - ta1_y_xxzz_xyyzz_1[i] * pc_y[i];

        ta1_y_xxyzz_xyzzz_0[i] = ta1_y_xxzz_xzzz_0[i] * fe_0 - ta1_y_xxzz_xzzz_1[i] * fe_0 + ta_xxzz_xyzzz_1[i] + ta1_y_xxzz_xyzzz_0[i] * pa_y[i] - ta1_y_xxzz_xyzzz_1[i] * pc_y[i];

        ta1_y_xxyzz_xzzzz_0[i] = ta_xxzz_xzzzz_1[i] + ta1_y_xxzz_xzzzz_0[i] * pa_y[i] - ta1_y_xxzz_xzzzz_1[i] * pc_y[i];

        ta1_y_xxyzz_yyyyy_0[i] = ta1_y_yzz_yyyyy_0[i] * fe_0 - ta1_y_yzz_yyyyy_1[i] * fe_0 + ta1_y_xyzz_yyyyy_0[i] * pa_x[i] - ta1_y_xyzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xxyzz_yyyyz_0[i] = ta1_y_yzz_yyyyz_0[i] * fe_0 - ta1_y_yzz_yyyyz_1[i] * fe_0 + ta1_y_xyzz_yyyyz_0[i] * pa_x[i] - ta1_y_xyzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxyzz_yyyzz_0[i] = ta1_y_yzz_yyyzz_0[i] * fe_0 - ta1_y_yzz_yyyzz_1[i] * fe_0 + ta1_y_xyzz_yyyzz_0[i] * pa_x[i] - ta1_y_xyzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxyzz_yyzzz_0[i] = ta1_y_yzz_yyzzz_0[i] * fe_0 - ta1_y_yzz_yyzzz_1[i] * fe_0 + ta1_y_xyzz_yyzzz_0[i] * pa_x[i] - ta1_y_xyzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxyzz_yzzzz_0[i] = ta1_y_yzz_yzzzz_0[i] * fe_0 - ta1_y_yzz_yzzzz_1[i] * fe_0 + ta1_y_xyzz_yzzzz_0[i] * pa_x[i] - ta1_y_xyzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxyzz_zzzzz_0[i] = ta_xxzz_zzzzz_1[i] + ta1_y_xxzz_zzzzz_0[i] * pa_y[i] - ta1_y_xxzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 630-651 components of targeted buffer : HH

    auto ta1_y_xxzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 630);

    auto ta1_y_xxzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 631);

    auto ta1_y_xxzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 632);

    auto ta1_y_xxzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 633);

    auto ta1_y_xxzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 634);

    auto ta1_y_xxzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 635);

    auto ta1_y_xxzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 636);

    auto ta1_y_xxzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 637);

    auto ta1_y_xxzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 638);

    auto ta1_y_xxzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 639);

    auto ta1_y_xxzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 640);

    auto ta1_y_xxzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 641);

    auto ta1_y_xxzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 642);

    auto ta1_y_xxzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 643);

    auto ta1_y_xxzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 644);

    auto ta1_y_xxzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 645);

    auto ta1_y_xxzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 646);

    auto ta1_y_xxzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 647);

    auto ta1_y_xxzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 648);

    auto ta1_y_xxzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 649);

    auto ta1_y_xxzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 650);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_y_xxz_xxxxx_0, ta1_y_xxz_xxxxx_1, ta1_y_xxz_xxxxy_0, ta1_y_xxz_xxxxy_1, ta1_y_xxz_xxxyy_0, ta1_y_xxz_xxxyy_1, ta1_y_xxz_xxyyy_0, ta1_y_xxz_xxyyy_1, ta1_y_xxz_xyyyy_0, ta1_y_xxz_xyyyy_1, ta1_y_xxzz_xxxxx_0, ta1_y_xxzz_xxxxx_1, ta1_y_xxzz_xxxxy_0, ta1_y_xxzz_xxxxy_1, ta1_y_xxzz_xxxyy_0, ta1_y_xxzz_xxxyy_1, ta1_y_xxzz_xxyyy_0, ta1_y_xxzz_xxyyy_1, ta1_y_xxzz_xyyyy_0, ta1_y_xxzz_xyyyy_1, ta1_y_xxzzz_xxxxx_0, ta1_y_xxzzz_xxxxy_0, ta1_y_xxzzz_xxxxz_0, ta1_y_xxzzz_xxxyy_0, ta1_y_xxzzz_xxxyz_0, ta1_y_xxzzz_xxxzz_0, ta1_y_xxzzz_xxyyy_0, ta1_y_xxzzz_xxyyz_0, ta1_y_xxzzz_xxyzz_0, ta1_y_xxzzz_xxzzz_0, ta1_y_xxzzz_xyyyy_0, ta1_y_xxzzz_xyyyz_0, ta1_y_xxzzz_xyyzz_0, ta1_y_xxzzz_xyzzz_0, ta1_y_xxzzz_xzzzz_0, ta1_y_xxzzz_yyyyy_0, ta1_y_xxzzz_yyyyz_0, ta1_y_xxzzz_yyyzz_0, ta1_y_xxzzz_yyzzz_0, ta1_y_xxzzz_yzzzz_0, ta1_y_xxzzz_zzzzz_0, ta1_y_xzzz_xxxxz_0, ta1_y_xzzz_xxxxz_1, ta1_y_xzzz_xxxyz_0, ta1_y_xzzz_xxxyz_1, ta1_y_xzzz_xxxz_0, ta1_y_xzzz_xxxz_1, ta1_y_xzzz_xxxzz_0, ta1_y_xzzz_xxxzz_1, ta1_y_xzzz_xxyyz_0, ta1_y_xzzz_xxyyz_1, ta1_y_xzzz_xxyz_0, ta1_y_xzzz_xxyz_1, ta1_y_xzzz_xxyzz_0, ta1_y_xzzz_xxyzz_1, ta1_y_xzzz_xxzz_0, ta1_y_xzzz_xxzz_1, ta1_y_xzzz_xxzzz_0, ta1_y_xzzz_xxzzz_1, ta1_y_xzzz_xyyyz_0, ta1_y_xzzz_xyyyz_1, ta1_y_xzzz_xyyz_0, ta1_y_xzzz_xyyz_1, ta1_y_xzzz_xyyzz_0, ta1_y_xzzz_xyyzz_1, ta1_y_xzzz_xyzz_0, ta1_y_xzzz_xyzz_1, ta1_y_xzzz_xyzzz_0, ta1_y_xzzz_xyzzz_1, ta1_y_xzzz_xzzz_0, ta1_y_xzzz_xzzz_1, ta1_y_xzzz_xzzzz_0, ta1_y_xzzz_xzzzz_1, ta1_y_xzzz_yyyyy_0, ta1_y_xzzz_yyyyy_1, ta1_y_xzzz_yyyyz_0, ta1_y_xzzz_yyyyz_1, ta1_y_xzzz_yyyz_0, ta1_y_xzzz_yyyz_1, ta1_y_xzzz_yyyzz_0, ta1_y_xzzz_yyyzz_1, ta1_y_xzzz_yyzz_0, ta1_y_xzzz_yyzz_1, ta1_y_xzzz_yyzzz_0, ta1_y_xzzz_yyzzz_1, ta1_y_xzzz_yzzz_0, ta1_y_xzzz_yzzz_1, ta1_y_xzzz_yzzzz_0, ta1_y_xzzz_yzzzz_1, ta1_y_xzzz_zzzz_0, ta1_y_xzzz_zzzz_1, ta1_y_xzzz_zzzzz_0, ta1_y_xzzz_zzzzz_1, ta1_y_zzz_xxxxz_0, ta1_y_zzz_xxxxz_1, ta1_y_zzz_xxxyz_0, ta1_y_zzz_xxxyz_1, ta1_y_zzz_xxxzz_0, ta1_y_zzz_xxxzz_1, ta1_y_zzz_xxyyz_0, ta1_y_zzz_xxyyz_1, ta1_y_zzz_xxyzz_0, ta1_y_zzz_xxyzz_1, ta1_y_zzz_xxzzz_0, ta1_y_zzz_xxzzz_1, ta1_y_zzz_xyyyz_0, ta1_y_zzz_xyyyz_1, ta1_y_zzz_xyyzz_0, ta1_y_zzz_xyyzz_1, ta1_y_zzz_xyzzz_0, ta1_y_zzz_xyzzz_1, ta1_y_zzz_xzzzz_0, ta1_y_zzz_xzzzz_1, ta1_y_zzz_yyyyy_0, ta1_y_zzz_yyyyy_1, ta1_y_zzz_yyyyz_0, ta1_y_zzz_yyyyz_1, ta1_y_zzz_yyyzz_0, ta1_y_zzz_yyyzz_1, ta1_y_zzz_yyzzz_0, ta1_y_zzz_yyzzz_1, ta1_y_zzz_yzzzz_0, ta1_y_zzz_yzzzz_1, ta1_y_zzz_zzzzz_0, ta1_y_zzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xxzzz_xxxxx_0[i] = 2.0 * ta1_y_xxz_xxxxx_0[i] * fe_0 - 2.0 * ta1_y_xxz_xxxxx_1[i] * fe_0 + ta1_y_xxzz_xxxxx_0[i] * pa_z[i] - ta1_y_xxzz_xxxxx_1[i] * pc_z[i];

        ta1_y_xxzzz_xxxxy_0[i] = 2.0 * ta1_y_xxz_xxxxy_0[i] * fe_0 - 2.0 * ta1_y_xxz_xxxxy_1[i] * fe_0 + ta1_y_xxzz_xxxxy_0[i] * pa_z[i] - ta1_y_xxzz_xxxxy_1[i] * pc_z[i];

        ta1_y_xxzzz_xxxxz_0[i] = ta1_y_zzz_xxxxz_0[i] * fe_0 - ta1_y_zzz_xxxxz_1[i] * fe_0 + 4.0 * ta1_y_xzzz_xxxz_0[i] * fe_0 - 4.0 * ta1_y_xzzz_xxxz_1[i] * fe_0 + ta1_y_xzzz_xxxxz_0[i] * pa_x[i] - ta1_y_xzzz_xxxxz_1[i] * pc_x[i];

        ta1_y_xxzzz_xxxyy_0[i] = 2.0 * ta1_y_xxz_xxxyy_0[i] * fe_0 - 2.0 * ta1_y_xxz_xxxyy_1[i] * fe_0 + ta1_y_xxzz_xxxyy_0[i] * pa_z[i] - ta1_y_xxzz_xxxyy_1[i] * pc_z[i];

        ta1_y_xxzzz_xxxyz_0[i] = ta1_y_zzz_xxxyz_0[i] * fe_0 - ta1_y_zzz_xxxyz_1[i] * fe_0 + 3.0 * ta1_y_xzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_xzzz_xxyz_1[i] * fe_0 + ta1_y_xzzz_xxxyz_0[i] * pa_x[i] - ta1_y_xzzz_xxxyz_1[i] * pc_x[i];

        ta1_y_xxzzz_xxxzz_0[i] = ta1_y_zzz_xxxzz_0[i] * fe_0 - ta1_y_zzz_xxxzz_1[i] * fe_0 + 3.0 * ta1_y_xzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_xzzz_xxzz_1[i] * fe_0 + ta1_y_xzzz_xxxzz_0[i] * pa_x[i] - ta1_y_xzzz_xxxzz_1[i] * pc_x[i];

        ta1_y_xxzzz_xxyyy_0[i] = 2.0 * ta1_y_xxz_xxyyy_0[i] * fe_0 - 2.0 * ta1_y_xxz_xxyyy_1[i] * fe_0 + ta1_y_xxzz_xxyyy_0[i] * pa_z[i] - ta1_y_xxzz_xxyyy_1[i] * pc_z[i];

        ta1_y_xxzzz_xxyyz_0[i] = ta1_y_zzz_xxyyz_0[i] * fe_0 - ta1_y_zzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_xzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_xzzz_xyyz_1[i] * fe_0 + ta1_y_xzzz_xxyyz_0[i] * pa_x[i] - ta1_y_xzzz_xxyyz_1[i] * pc_x[i];

        ta1_y_xxzzz_xxyzz_0[i] = ta1_y_zzz_xxyzz_0[i] * fe_0 - ta1_y_zzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_xzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_xzzz_xyzz_1[i] * fe_0 + ta1_y_xzzz_xxyzz_0[i] * pa_x[i] - ta1_y_xzzz_xxyzz_1[i] * pc_x[i];

        ta1_y_xxzzz_xxzzz_0[i] = ta1_y_zzz_xxzzz_0[i] * fe_0 - ta1_y_zzz_xxzzz_1[i] * fe_0 + 2.0 * ta1_y_xzzz_xzzz_0[i] * fe_0 - 2.0 * ta1_y_xzzz_xzzz_1[i] * fe_0 + ta1_y_xzzz_xxzzz_0[i] * pa_x[i] - ta1_y_xzzz_xxzzz_1[i] * pc_x[i];

        ta1_y_xxzzz_xyyyy_0[i] = 2.0 * ta1_y_xxz_xyyyy_0[i] * fe_0 - 2.0 * ta1_y_xxz_xyyyy_1[i] * fe_0 + ta1_y_xxzz_xyyyy_0[i] * pa_z[i] - ta1_y_xxzz_xyyyy_1[i] * pc_z[i];

        ta1_y_xxzzz_xyyyz_0[i] = ta1_y_zzz_xyyyz_0[i] * fe_0 - ta1_y_zzz_xyyyz_1[i] * fe_0 + ta1_y_xzzz_yyyz_0[i] * fe_0 - ta1_y_xzzz_yyyz_1[i] * fe_0 + ta1_y_xzzz_xyyyz_0[i] * pa_x[i] - ta1_y_xzzz_xyyyz_1[i] * pc_x[i];

        ta1_y_xxzzz_xyyzz_0[i] = ta1_y_zzz_xyyzz_0[i] * fe_0 - ta1_y_zzz_xyyzz_1[i] * fe_0 + ta1_y_xzzz_yyzz_0[i] * fe_0 - ta1_y_xzzz_yyzz_1[i] * fe_0 + ta1_y_xzzz_xyyzz_0[i] * pa_x[i] - ta1_y_xzzz_xyyzz_1[i] * pc_x[i];

        ta1_y_xxzzz_xyzzz_0[i] = ta1_y_zzz_xyzzz_0[i] * fe_0 - ta1_y_zzz_xyzzz_1[i] * fe_0 + ta1_y_xzzz_yzzz_0[i] * fe_0 - ta1_y_xzzz_yzzz_1[i] * fe_0 + ta1_y_xzzz_xyzzz_0[i] * pa_x[i] - ta1_y_xzzz_xyzzz_1[i] * pc_x[i];

        ta1_y_xxzzz_xzzzz_0[i] = ta1_y_zzz_xzzzz_0[i] * fe_0 - ta1_y_zzz_xzzzz_1[i] * fe_0 + ta1_y_xzzz_zzzz_0[i] * fe_0 - ta1_y_xzzz_zzzz_1[i] * fe_0 + ta1_y_xzzz_xzzzz_0[i] * pa_x[i] - ta1_y_xzzz_xzzzz_1[i] * pc_x[i];

        ta1_y_xxzzz_yyyyy_0[i] = ta1_y_zzz_yyyyy_0[i] * fe_0 - ta1_y_zzz_yyyyy_1[i] * fe_0 + ta1_y_xzzz_yyyyy_0[i] * pa_x[i] - ta1_y_xzzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xxzzz_yyyyz_0[i] = ta1_y_zzz_yyyyz_0[i] * fe_0 - ta1_y_zzz_yyyyz_1[i] * fe_0 + ta1_y_xzzz_yyyyz_0[i] * pa_x[i] - ta1_y_xzzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xxzzz_yyyzz_0[i] = ta1_y_zzz_yyyzz_0[i] * fe_0 - ta1_y_zzz_yyyzz_1[i] * fe_0 + ta1_y_xzzz_yyyzz_0[i] * pa_x[i] - ta1_y_xzzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xxzzz_yyzzz_0[i] = ta1_y_zzz_yyzzz_0[i] * fe_0 - ta1_y_zzz_yyzzz_1[i] * fe_0 + ta1_y_xzzz_yyzzz_0[i] * pa_x[i] - ta1_y_xzzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xxzzz_yzzzz_0[i] = ta1_y_zzz_yzzzz_0[i] * fe_0 - ta1_y_zzz_yzzzz_1[i] * fe_0 + ta1_y_xzzz_yzzzz_0[i] * pa_x[i] - ta1_y_xzzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xxzzz_zzzzz_0[i] = ta1_y_zzz_zzzzz_0[i] * fe_0 - ta1_y_zzz_zzzzz_1[i] * fe_0 + ta1_y_xzzz_zzzzz_0[i] * pa_x[i] - ta1_y_xzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 651-672 components of targeted buffer : HH

    auto ta1_y_xyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 651);

    auto ta1_y_xyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 652);

    auto ta1_y_xyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 653);

    auto ta1_y_xyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 654);

    auto ta1_y_xyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 655);

    auto ta1_y_xyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 656);

    auto ta1_y_xyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 657);

    auto ta1_y_xyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 658);

    auto ta1_y_xyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 659);

    auto ta1_y_xyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 660);

    auto ta1_y_xyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 661);

    auto ta1_y_xyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 662);

    auto ta1_y_xyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 663);

    auto ta1_y_xyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 664);

    auto ta1_y_xyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 665);

    auto ta1_y_xyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 666);

    auto ta1_y_xyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 667);

    auto ta1_y_xyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 668);

    auto ta1_y_xyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 669);

    auto ta1_y_xyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 670);

    auto ta1_y_xyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 671);

    #pragma omp simd aligned(pa_x, pc_x, ta1_y_xyyyy_xxxxx_0, ta1_y_xyyyy_xxxxy_0, ta1_y_xyyyy_xxxxz_0, ta1_y_xyyyy_xxxyy_0, ta1_y_xyyyy_xxxyz_0, ta1_y_xyyyy_xxxzz_0, ta1_y_xyyyy_xxyyy_0, ta1_y_xyyyy_xxyyz_0, ta1_y_xyyyy_xxyzz_0, ta1_y_xyyyy_xxzzz_0, ta1_y_xyyyy_xyyyy_0, ta1_y_xyyyy_xyyyz_0, ta1_y_xyyyy_xyyzz_0, ta1_y_xyyyy_xyzzz_0, ta1_y_xyyyy_xzzzz_0, ta1_y_xyyyy_yyyyy_0, ta1_y_xyyyy_yyyyz_0, ta1_y_xyyyy_yyyzz_0, ta1_y_xyyyy_yyzzz_0, ta1_y_xyyyy_yzzzz_0, ta1_y_xyyyy_zzzzz_0, ta1_y_yyyy_xxxx_0, ta1_y_yyyy_xxxx_1, ta1_y_yyyy_xxxxx_0, ta1_y_yyyy_xxxxx_1, ta1_y_yyyy_xxxxy_0, ta1_y_yyyy_xxxxy_1, ta1_y_yyyy_xxxxz_0, ta1_y_yyyy_xxxxz_1, ta1_y_yyyy_xxxy_0, ta1_y_yyyy_xxxy_1, ta1_y_yyyy_xxxyy_0, ta1_y_yyyy_xxxyy_1, ta1_y_yyyy_xxxyz_0, ta1_y_yyyy_xxxyz_1, ta1_y_yyyy_xxxz_0, ta1_y_yyyy_xxxz_1, ta1_y_yyyy_xxxzz_0, ta1_y_yyyy_xxxzz_1, ta1_y_yyyy_xxyy_0, ta1_y_yyyy_xxyy_1, ta1_y_yyyy_xxyyy_0, ta1_y_yyyy_xxyyy_1, ta1_y_yyyy_xxyyz_0, ta1_y_yyyy_xxyyz_1, ta1_y_yyyy_xxyz_0, ta1_y_yyyy_xxyz_1, ta1_y_yyyy_xxyzz_0, ta1_y_yyyy_xxyzz_1, ta1_y_yyyy_xxzz_0, ta1_y_yyyy_xxzz_1, ta1_y_yyyy_xxzzz_0, ta1_y_yyyy_xxzzz_1, ta1_y_yyyy_xyyy_0, ta1_y_yyyy_xyyy_1, ta1_y_yyyy_xyyyy_0, ta1_y_yyyy_xyyyy_1, ta1_y_yyyy_xyyyz_0, ta1_y_yyyy_xyyyz_1, ta1_y_yyyy_xyyz_0, ta1_y_yyyy_xyyz_1, ta1_y_yyyy_xyyzz_0, ta1_y_yyyy_xyyzz_1, ta1_y_yyyy_xyzz_0, ta1_y_yyyy_xyzz_1, ta1_y_yyyy_xyzzz_0, ta1_y_yyyy_xyzzz_1, ta1_y_yyyy_xzzz_0, ta1_y_yyyy_xzzz_1, ta1_y_yyyy_xzzzz_0, ta1_y_yyyy_xzzzz_1, ta1_y_yyyy_yyyy_0, ta1_y_yyyy_yyyy_1, ta1_y_yyyy_yyyyy_0, ta1_y_yyyy_yyyyy_1, ta1_y_yyyy_yyyyz_0, ta1_y_yyyy_yyyyz_1, ta1_y_yyyy_yyyz_0, ta1_y_yyyy_yyyz_1, ta1_y_yyyy_yyyzz_0, ta1_y_yyyy_yyyzz_1, ta1_y_yyyy_yyzz_0, ta1_y_yyyy_yyzz_1, ta1_y_yyyy_yyzzz_0, ta1_y_yyyy_yyzzz_1, ta1_y_yyyy_yzzz_0, ta1_y_yyyy_yzzz_1, ta1_y_yyyy_yzzzz_0, ta1_y_yyyy_yzzzz_1, ta1_y_yyyy_zzzz_0, ta1_y_yyyy_zzzz_1, ta1_y_yyyy_zzzzz_0, ta1_y_yyyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xyyyy_xxxxx_0[i] = 5.0 * ta1_y_yyyy_xxxx_0[i] * fe_0 - 5.0 * ta1_y_yyyy_xxxx_1[i] * fe_0 + ta1_y_yyyy_xxxxx_0[i] * pa_x[i] - ta1_y_yyyy_xxxxx_1[i] * pc_x[i];

        ta1_y_xyyyy_xxxxy_0[i] = 4.0 * ta1_y_yyyy_xxxy_0[i] * fe_0 - 4.0 * ta1_y_yyyy_xxxy_1[i] * fe_0 + ta1_y_yyyy_xxxxy_0[i] * pa_x[i] - ta1_y_yyyy_xxxxy_1[i] * pc_x[i];

        ta1_y_xyyyy_xxxxz_0[i] = 4.0 * ta1_y_yyyy_xxxz_0[i] * fe_0 - 4.0 * ta1_y_yyyy_xxxz_1[i] * fe_0 + ta1_y_yyyy_xxxxz_0[i] * pa_x[i] - ta1_y_yyyy_xxxxz_1[i] * pc_x[i];

        ta1_y_xyyyy_xxxyy_0[i] = 3.0 * ta1_y_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xxyy_1[i] * fe_0 + ta1_y_yyyy_xxxyy_0[i] * pa_x[i] - ta1_y_yyyy_xxxyy_1[i] * pc_x[i];

        ta1_y_xyyyy_xxxyz_0[i] = 3.0 * ta1_y_yyyy_xxyz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xxyz_1[i] * fe_0 + ta1_y_yyyy_xxxyz_0[i] * pa_x[i] - ta1_y_yyyy_xxxyz_1[i] * pc_x[i];

        ta1_y_xyyyy_xxxzz_0[i] = 3.0 * ta1_y_yyyy_xxzz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xxzz_1[i] * fe_0 + ta1_y_yyyy_xxxzz_0[i] * pa_x[i] - ta1_y_yyyy_xxxzz_1[i] * pc_x[i];

        ta1_y_xyyyy_xxyyy_0[i] = 2.0 * ta1_y_yyyy_xyyy_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xyyy_1[i] * fe_0 + ta1_y_yyyy_xxyyy_0[i] * pa_x[i] - ta1_y_yyyy_xxyyy_1[i] * pc_x[i];

        ta1_y_xyyyy_xxyyz_0[i] = 2.0 * ta1_y_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xyyz_1[i] * fe_0 + ta1_y_yyyy_xxyyz_0[i] * pa_x[i] - ta1_y_yyyy_xxyyz_1[i] * pc_x[i];

        ta1_y_xyyyy_xxyzz_0[i] = 2.0 * ta1_y_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xyzz_1[i] * fe_0 + ta1_y_yyyy_xxyzz_0[i] * pa_x[i] - ta1_y_yyyy_xxyzz_1[i] * pc_x[i];

        ta1_y_xyyyy_xxzzz_0[i] = 2.0 * ta1_y_yyyy_xzzz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xzzz_1[i] * fe_0 + ta1_y_yyyy_xxzzz_0[i] * pa_x[i] - ta1_y_yyyy_xxzzz_1[i] * pc_x[i];

        ta1_y_xyyyy_xyyyy_0[i] = ta1_y_yyyy_yyyy_0[i] * fe_0 - ta1_y_yyyy_yyyy_1[i] * fe_0 + ta1_y_yyyy_xyyyy_0[i] * pa_x[i] - ta1_y_yyyy_xyyyy_1[i] * pc_x[i];

        ta1_y_xyyyy_xyyyz_0[i] = ta1_y_yyyy_yyyz_0[i] * fe_0 - ta1_y_yyyy_yyyz_1[i] * fe_0 + ta1_y_yyyy_xyyyz_0[i] * pa_x[i] - ta1_y_yyyy_xyyyz_1[i] * pc_x[i];

        ta1_y_xyyyy_xyyzz_0[i] = ta1_y_yyyy_yyzz_0[i] * fe_0 - ta1_y_yyyy_yyzz_1[i] * fe_0 + ta1_y_yyyy_xyyzz_0[i] * pa_x[i] - ta1_y_yyyy_xyyzz_1[i] * pc_x[i];

        ta1_y_xyyyy_xyzzz_0[i] = ta1_y_yyyy_yzzz_0[i] * fe_0 - ta1_y_yyyy_yzzz_1[i] * fe_0 + ta1_y_yyyy_xyzzz_0[i] * pa_x[i] - ta1_y_yyyy_xyzzz_1[i] * pc_x[i];

        ta1_y_xyyyy_xzzzz_0[i] = ta1_y_yyyy_zzzz_0[i] * fe_0 - ta1_y_yyyy_zzzz_1[i] * fe_0 + ta1_y_yyyy_xzzzz_0[i] * pa_x[i] - ta1_y_yyyy_xzzzz_1[i] * pc_x[i];

        ta1_y_xyyyy_yyyyy_0[i] = ta1_y_yyyy_yyyyy_0[i] * pa_x[i] - ta1_y_yyyy_yyyyy_1[i] * pc_x[i];

        ta1_y_xyyyy_yyyyz_0[i] = ta1_y_yyyy_yyyyz_0[i] * pa_x[i] - ta1_y_yyyy_yyyyz_1[i] * pc_x[i];

        ta1_y_xyyyy_yyyzz_0[i] = ta1_y_yyyy_yyyzz_0[i] * pa_x[i] - ta1_y_yyyy_yyyzz_1[i] * pc_x[i];

        ta1_y_xyyyy_yyzzz_0[i] = ta1_y_yyyy_yyzzz_0[i] * pa_x[i] - ta1_y_yyyy_yyzzz_1[i] * pc_x[i];

        ta1_y_xyyyy_yzzzz_0[i] = ta1_y_yyyy_yzzzz_0[i] * pa_x[i] - ta1_y_yyyy_yzzzz_1[i] * pc_x[i];

        ta1_y_xyyyy_zzzzz_0[i] = ta1_y_yyyy_zzzzz_0[i] * pa_x[i] - ta1_y_yyyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 672-693 components of targeted buffer : HH

    auto ta1_y_xyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 672);

    auto ta1_y_xyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 673);

    auto ta1_y_xyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 674);

    auto ta1_y_xyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 675);

    auto ta1_y_xyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 676);

    auto ta1_y_xyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 677);

    auto ta1_y_xyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 678);

    auto ta1_y_xyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 679);

    auto ta1_y_xyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 680);

    auto ta1_y_xyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 681);

    auto ta1_y_xyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 682);

    auto ta1_y_xyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 683);

    auto ta1_y_xyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 684);

    auto ta1_y_xyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 685);

    auto ta1_y_xyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 686);

    auto ta1_y_xyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 687);

    auto ta1_y_xyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 688);

    auto ta1_y_xyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 689);

    auto ta1_y_xyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 690);

    auto ta1_y_xyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 691);

    auto ta1_y_xyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 692);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_y_xyyy_xxxxx_0, ta1_y_xyyy_xxxxx_1, ta1_y_xyyy_xxxxy_0, ta1_y_xyyy_xxxxy_1, ta1_y_xyyy_xxxyy_0, ta1_y_xyyy_xxxyy_1, ta1_y_xyyy_xxyyy_0, ta1_y_xyyy_xxyyy_1, ta1_y_xyyy_xyyyy_0, ta1_y_xyyy_xyyyy_1, ta1_y_xyyyz_xxxxx_0, ta1_y_xyyyz_xxxxy_0, ta1_y_xyyyz_xxxxz_0, ta1_y_xyyyz_xxxyy_0, ta1_y_xyyyz_xxxyz_0, ta1_y_xyyyz_xxxzz_0, ta1_y_xyyyz_xxyyy_0, ta1_y_xyyyz_xxyyz_0, ta1_y_xyyyz_xxyzz_0, ta1_y_xyyyz_xxzzz_0, ta1_y_xyyyz_xyyyy_0, ta1_y_xyyyz_xyyyz_0, ta1_y_xyyyz_xyyzz_0, ta1_y_xyyyz_xyzzz_0, ta1_y_xyyyz_xzzzz_0, ta1_y_xyyyz_yyyyy_0, ta1_y_xyyyz_yyyyz_0, ta1_y_xyyyz_yyyzz_0, ta1_y_xyyyz_yyzzz_0, ta1_y_xyyyz_yzzzz_0, ta1_y_xyyyz_zzzzz_0, ta1_y_yyyz_xxxxz_0, ta1_y_yyyz_xxxxz_1, ta1_y_yyyz_xxxyz_0, ta1_y_yyyz_xxxyz_1, ta1_y_yyyz_xxxz_0, ta1_y_yyyz_xxxz_1, ta1_y_yyyz_xxxzz_0, ta1_y_yyyz_xxxzz_1, ta1_y_yyyz_xxyyz_0, ta1_y_yyyz_xxyyz_1, ta1_y_yyyz_xxyz_0, ta1_y_yyyz_xxyz_1, ta1_y_yyyz_xxyzz_0, ta1_y_yyyz_xxyzz_1, ta1_y_yyyz_xxzz_0, ta1_y_yyyz_xxzz_1, ta1_y_yyyz_xxzzz_0, ta1_y_yyyz_xxzzz_1, ta1_y_yyyz_xyyyz_0, ta1_y_yyyz_xyyyz_1, ta1_y_yyyz_xyyz_0, ta1_y_yyyz_xyyz_1, ta1_y_yyyz_xyyzz_0, ta1_y_yyyz_xyyzz_1, ta1_y_yyyz_xyzz_0, ta1_y_yyyz_xyzz_1, ta1_y_yyyz_xyzzz_0, ta1_y_yyyz_xyzzz_1, ta1_y_yyyz_xzzz_0, ta1_y_yyyz_xzzz_1, ta1_y_yyyz_xzzzz_0, ta1_y_yyyz_xzzzz_1, ta1_y_yyyz_yyyyy_0, ta1_y_yyyz_yyyyy_1, ta1_y_yyyz_yyyyz_0, ta1_y_yyyz_yyyyz_1, ta1_y_yyyz_yyyz_0, ta1_y_yyyz_yyyz_1, ta1_y_yyyz_yyyzz_0, ta1_y_yyyz_yyyzz_1, ta1_y_yyyz_yyzz_0, ta1_y_yyyz_yyzz_1, ta1_y_yyyz_yyzzz_0, ta1_y_yyyz_yyzzz_1, ta1_y_yyyz_yzzz_0, ta1_y_yyyz_yzzz_1, ta1_y_yyyz_yzzzz_0, ta1_y_yyyz_yzzzz_1, ta1_y_yyyz_zzzz_0, ta1_y_yyyz_zzzz_1, ta1_y_yyyz_zzzzz_0, ta1_y_yyyz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xyyyz_xxxxx_0[i] = ta1_y_xyyy_xxxxx_0[i] * pa_z[i] - ta1_y_xyyy_xxxxx_1[i] * pc_z[i];

        ta1_y_xyyyz_xxxxy_0[i] = ta1_y_xyyy_xxxxy_0[i] * pa_z[i] - ta1_y_xyyy_xxxxy_1[i] * pc_z[i];

        ta1_y_xyyyz_xxxxz_0[i] = 4.0 * ta1_y_yyyz_xxxz_0[i] * fe_0 - 4.0 * ta1_y_yyyz_xxxz_1[i] * fe_0 + ta1_y_yyyz_xxxxz_0[i] * pa_x[i] - ta1_y_yyyz_xxxxz_1[i] * pc_x[i];

        ta1_y_xyyyz_xxxyy_0[i] = ta1_y_xyyy_xxxyy_0[i] * pa_z[i] - ta1_y_xyyy_xxxyy_1[i] * pc_z[i];

        ta1_y_xyyyz_xxxyz_0[i] = 3.0 * ta1_y_yyyz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_yyyz_xxyz_1[i] * fe_0 + ta1_y_yyyz_xxxyz_0[i] * pa_x[i] - ta1_y_yyyz_xxxyz_1[i] * pc_x[i];

        ta1_y_xyyyz_xxxzz_0[i] = 3.0 * ta1_y_yyyz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_yyyz_xxzz_1[i] * fe_0 + ta1_y_yyyz_xxxzz_0[i] * pa_x[i] - ta1_y_yyyz_xxxzz_1[i] * pc_x[i];

        ta1_y_xyyyz_xxyyy_0[i] = ta1_y_xyyy_xxyyy_0[i] * pa_z[i] - ta1_y_xyyy_xxyyy_1[i] * pc_z[i];

        ta1_y_xyyyz_xxyyz_0[i] = 2.0 * ta1_y_yyyz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_xyyz_1[i] * fe_0 + ta1_y_yyyz_xxyyz_0[i] * pa_x[i] - ta1_y_yyyz_xxyyz_1[i] * pc_x[i];

        ta1_y_xyyyz_xxyzz_0[i] = 2.0 * ta1_y_yyyz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_xyzz_1[i] * fe_0 + ta1_y_yyyz_xxyzz_0[i] * pa_x[i] - ta1_y_yyyz_xxyzz_1[i] * pc_x[i];

        ta1_y_xyyyz_xxzzz_0[i] = 2.0 * ta1_y_yyyz_xzzz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_xzzz_1[i] * fe_0 + ta1_y_yyyz_xxzzz_0[i] * pa_x[i] - ta1_y_yyyz_xxzzz_1[i] * pc_x[i];

        ta1_y_xyyyz_xyyyy_0[i] = ta1_y_xyyy_xyyyy_0[i] * pa_z[i] - ta1_y_xyyy_xyyyy_1[i] * pc_z[i];

        ta1_y_xyyyz_xyyyz_0[i] = ta1_y_yyyz_yyyz_0[i] * fe_0 - ta1_y_yyyz_yyyz_1[i] * fe_0 + ta1_y_yyyz_xyyyz_0[i] * pa_x[i] - ta1_y_yyyz_xyyyz_1[i] * pc_x[i];

        ta1_y_xyyyz_xyyzz_0[i] = ta1_y_yyyz_yyzz_0[i] * fe_0 - ta1_y_yyyz_yyzz_1[i] * fe_0 + ta1_y_yyyz_xyyzz_0[i] * pa_x[i] - ta1_y_yyyz_xyyzz_1[i] * pc_x[i];

        ta1_y_xyyyz_xyzzz_0[i] = ta1_y_yyyz_yzzz_0[i] * fe_0 - ta1_y_yyyz_yzzz_1[i] * fe_0 + ta1_y_yyyz_xyzzz_0[i] * pa_x[i] - ta1_y_yyyz_xyzzz_1[i] * pc_x[i];

        ta1_y_xyyyz_xzzzz_0[i] = ta1_y_yyyz_zzzz_0[i] * fe_0 - ta1_y_yyyz_zzzz_1[i] * fe_0 + ta1_y_yyyz_xzzzz_0[i] * pa_x[i] - ta1_y_yyyz_xzzzz_1[i] * pc_x[i];

        ta1_y_xyyyz_yyyyy_0[i] = ta1_y_yyyz_yyyyy_0[i] * pa_x[i] - ta1_y_yyyz_yyyyy_1[i] * pc_x[i];

        ta1_y_xyyyz_yyyyz_0[i] = ta1_y_yyyz_yyyyz_0[i] * pa_x[i] - ta1_y_yyyz_yyyyz_1[i] * pc_x[i];

        ta1_y_xyyyz_yyyzz_0[i] = ta1_y_yyyz_yyyzz_0[i] * pa_x[i] - ta1_y_yyyz_yyyzz_1[i] * pc_x[i];

        ta1_y_xyyyz_yyzzz_0[i] = ta1_y_yyyz_yyzzz_0[i] * pa_x[i] - ta1_y_yyyz_yyzzz_1[i] * pc_x[i];

        ta1_y_xyyyz_yzzzz_0[i] = ta1_y_yyyz_yzzzz_0[i] * pa_x[i] - ta1_y_yyyz_yzzzz_1[i] * pc_x[i];

        ta1_y_xyyyz_zzzzz_0[i] = ta1_y_yyyz_zzzzz_0[i] * pa_x[i] - ta1_y_yyyz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 693-714 components of targeted buffer : HH

    auto ta1_y_xyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 693);

    auto ta1_y_xyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 694);

    auto ta1_y_xyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 695);

    auto ta1_y_xyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 696);

    auto ta1_y_xyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 697);

    auto ta1_y_xyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 698);

    auto ta1_y_xyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 699);

    auto ta1_y_xyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 700);

    auto ta1_y_xyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 701);

    auto ta1_y_xyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 702);

    auto ta1_y_xyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 703);

    auto ta1_y_xyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 704);

    auto ta1_y_xyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 705);

    auto ta1_y_xyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 706);

    auto ta1_y_xyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 707);

    auto ta1_y_xyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 708);

    auto ta1_y_xyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 709);

    auto ta1_y_xyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 710);

    auto ta1_y_xyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 711);

    auto ta1_y_xyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 712);

    auto ta1_y_xyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 713);

    #pragma omp simd aligned(pa_x, pc_x, ta1_y_xyyzz_xxxxx_0, ta1_y_xyyzz_xxxxy_0, ta1_y_xyyzz_xxxxz_0, ta1_y_xyyzz_xxxyy_0, ta1_y_xyyzz_xxxyz_0, ta1_y_xyyzz_xxxzz_0, ta1_y_xyyzz_xxyyy_0, ta1_y_xyyzz_xxyyz_0, ta1_y_xyyzz_xxyzz_0, ta1_y_xyyzz_xxzzz_0, ta1_y_xyyzz_xyyyy_0, ta1_y_xyyzz_xyyyz_0, ta1_y_xyyzz_xyyzz_0, ta1_y_xyyzz_xyzzz_0, ta1_y_xyyzz_xzzzz_0, ta1_y_xyyzz_yyyyy_0, ta1_y_xyyzz_yyyyz_0, ta1_y_xyyzz_yyyzz_0, ta1_y_xyyzz_yyzzz_0, ta1_y_xyyzz_yzzzz_0, ta1_y_xyyzz_zzzzz_0, ta1_y_yyzz_xxxx_0, ta1_y_yyzz_xxxx_1, ta1_y_yyzz_xxxxx_0, ta1_y_yyzz_xxxxx_1, ta1_y_yyzz_xxxxy_0, ta1_y_yyzz_xxxxy_1, ta1_y_yyzz_xxxxz_0, ta1_y_yyzz_xxxxz_1, ta1_y_yyzz_xxxy_0, ta1_y_yyzz_xxxy_1, ta1_y_yyzz_xxxyy_0, ta1_y_yyzz_xxxyy_1, ta1_y_yyzz_xxxyz_0, ta1_y_yyzz_xxxyz_1, ta1_y_yyzz_xxxz_0, ta1_y_yyzz_xxxz_1, ta1_y_yyzz_xxxzz_0, ta1_y_yyzz_xxxzz_1, ta1_y_yyzz_xxyy_0, ta1_y_yyzz_xxyy_1, ta1_y_yyzz_xxyyy_0, ta1_y_yyzz_xxyyy_1, ta1_y_yyzz_xxyyz_0, ta1_y_yyzz_xxyyz_1, ta1_y_yyzz_xxyz_0, ta1_y_yyzz_xxyz_1, ta1_y_yyzz_xxyzz_0, ta1_y_yyzz_xxyzz_1, ta1_y_yyzz_xxzz_0, ta1_y_yyzz_xxzz_1, ta1_y_yyzz_xxzzz_0, ta1_y_yyzz_xxzzz_1, ta1_y_yyzz_xyyy_0, ta1_y_yyzz_xyyy_1, ta1_y_yyzz_xyyyy_0, ta1_y_yyzz_xyyyy_1, ta1_y_yyzz_xyyyz_0, ta1_y_yyzz_xyyyz_1, ta1_y_yyzz_xyyz_0, ta1_y_yyzz_xyyz_1, ta1_y_yyzz_xyyzz_0, ta1_y_yyzz_xyyzz_1, ta1_y_yyzz_xyzz_0, ta1_y_yyzz_xyzz_1, ta1_y_yyzz_xyzzz_0, ta1_y_yyzz_xyzzz_1, ta1_y_yyzz_xzzz_0, ta1_y_yyzz_xzzz_1, ta1_y_yyzz_xzzzz_0, ta1_y_yyzz_xzzzz_1, ta1_y_yyzz_yyyy_0, ta1_y_yyzz_yyyy_1, ta1_y_yyzz_yyyyy_0, ta1_y_yyzz_yyyyy_1, ta1_y_yyzz_yyyyz_0, ta1_y_yyzz_yyyyz_1, ta1_y_yyzz_yyyz_0, ta1_y_yyzz_yyyz_1, ta1_y_yyzz_yyyzz_0, ta1_y_yyzz_yyyzz_1, ta1_y_yyzz_yyzz_0, ta1_y_yyzz_yyzz_1, ta1_y_yyzz_yyzzz_0, ta1_y_yyzz_yyzzz_1, ta1_y_yyzz_yzzz_0, ta1_y_yyzz_yzzz_1, ta1_y_yyzz_yzzzz_0, ta1_y_yyzz_yzzzz_1, ta1_y_yyzz_zzzz_0, ta1_y_yyzz_zzzz_1, ta1_y_yyzz_zzzzz_0, ta1_y_yyzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xyyzz_xxxxx_0[i] = 5.0 * ta1_y_yyzz_xxxx_0[i] * fe_0 - 5.0 * ta1_y_yyzz_xxxx_1[i] * fe_0 + ta1_y_yyzz_xxxxx_0[i] * pa_x[i] - ta1_y_yyzz_xxxxx_1[i] * pc_x[i];

        ta1_y_xyyzz_xxxxy_0[i] = 4.0 * ta1_y_yyzz_xxxy_0[i] * fe_0 - 4.0 * ta1_y_yyzz_xxxy_1[i] * fe_0 + ta1_y_yyzz_xxxxy_0[i] * pa_x[i] - ta1_y_yyzz_xxxxy_1[i] * pc_x[i];

        ta1_y_xyyzz_xxxxz_0[i] = 4.0 * ta1_y_yyzz_xxxz_0[i] * fe_0 - 4.0 * ta1_y_yyzz_xxxz_1[i] * fe_0 + ta1_y_yyzz_xxxxz_0[i] * pa_x[i] - ta1_y_yyzz_xxxxz_1[i] * pc_x[i];

        ta1_y_xyyzz_xxxyy_0[i] = 3.0 * ta1_y_yyzz_xxyy_0[i] * fe_0 - 3.0 * ta1_y_yyzz_xxyy_1[i] * fe_0 + ta1_y_yyzz_xxxyy_0[i] * pa_x[i] - ta1_y_yyzz_xxxyy_1[i] * pc_x[i];

        ta1_y_xyyzz_xxxyz_0[i] = 3.0 * ta1_y_yyzz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_yyzz_xxyz_1[i] * fe_0 + ta1_y_yyzz_xxxyz_0[i] * pa_x[i] - ta1_y_yyzz_xxxyz_1[i] * pc_x[i];

        ta1_y_xyyzz_xxxzz_0[i] = 3.0 * ta1_y_yyzz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_yyzz_xxzz_1[i] * fe_0 + ta1_y_yyzz_xxxzz_0[i] * pa_x[i] - ta1_y_yyzz_xxxzz_1[i] * pc_x[i];

        ta1_y_xyyzz_xxyyy_0[i] = 2.0 * ta1_y_yyzz_xyyy_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xyyy_1[i] * fe_0 + ta1_y_yyzz_xxyyy_0[i] * pa_x[i] - ta1_y_yyzz_xxyyy_1[i] * pc_x[i];

        ta1_y_xyyzz_xxyyz_0[i] = 2.0 * ta1_y_yyzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xyyz_1[i] * fe_0 + ta1_y_yyzz_xxyyz_0[i] * pa_x[i] - ta1_y_yyzz_xxyyz_1[i] * pc_x[i];

        ta1_y_xyyzz_xxyzz_0[i] = 2.0 * ta1_y_yyzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xyzz_1[i] * fe_0 + ta1_y_yyzz_xxyzz_0[i] * pa_x[i] - ta1_y_yyzz_xxyzz_1[i] * pc_x[i];

        ta1_y_xyyzz_xxzzz_0[i] = 2.0 * ta1_y_yyzz_xzzz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xzzz_1[i] * fe_0 + ta1_y_yyzz_xxzzz_0[i] * pa_x[i] - ta1_y_yyzz_xxzzz_1[i] * pc_x[i];

        ta1_y_xyyzz_xyyyy_0[i] = ta1_y_yyzz_yyyy_0[i] * fe_0 - ta1_y_yyzz_yyyy_1[i] * fe_0 + ta1_y_yyzz_xyyyy_0[i] * pa_x[i] - ta1_y_yyzz_xyyyy_1[i] * pc_x[i];

        ta1_y_xyyzz_xyyyz_0[i] = ta1_y_yyzz_yyyz_0[i] * fe_0 - ta1_y_yyzz_yyyz_1[i] * fe_0 + ta1_y_yyzz_xyyyz_0[i] * pa_x[i] - ta1_y_yyzz_xyyyz_1[i] * pc_x[i];

        ta1_y_xyyzz_xyyzz_0[i] = ta1_y_yyzz_yyzz_0[i] * fe_0 - ta1_y_yyzz_yyzz_1[i] * fe_0 + ta1_y_yyzz_xyyzz_0[i] * pa_x[i] - ta1_y_yyzz_xyyzz_1[i] * pc_x[i];

        ta1_y_xyyzz_xyzzz_0[i] = ta1_y_yyzz_yzzz_0[i] * fe_0 - ta1_y_yyzz_yzzz_1[i] * fe_0 + ta1_y_yyzz_xyzzz_0[i] * pa_x[i] - ta1_y_yyzz_xyzzz_1[i] * pc_x[i];

        ta1_y_xyyzz_xzzzz_0[i] = ta1_y_yyzz_zzzz_0[i] * fe_0 - ta1_y_yyzz_zzzz_1[i] * fe_0 + ta1_y_yyzz_xzzzz_0[i] * pa_x[i] - ta1_y_yyzz_xzzzz_1[i] * pc_x[i];

        ta1_y_xyyzz_yyyyy_0[i] = ta1_y_yyzz_yyyyy_0[i] * pa_x[i] - ta1_y_yyzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xyyzz_yyyyz_0[i] = ta1_y_yyzz_yyyyz_0[i] * pa_x[i] - ta1_y_yyzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xyyzz_yyyzz_0[i] = ta1_y_yyzz_yyyzz_0[i] * pa_x[i] - ta1_y_yyzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xyyzz_yyzzz_0[i] = ta1_y_yyzz_yyzzz_0[i] * pa_x[i] - ta1_y_yyzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xyyzz_yzzzz_0[i] = ta1_y_yyzz_yzzzz_0[i] * pa_x[i] - ta1_y_yyzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xyyzz_zzzzz_0[i] = ta1_y_yyzz_zzzzz_0[i] * pa_x[i] - ta1_y_yyzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 714-735 components of targeted buffer : HH

    auto ta1_y_xyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 714);

    auto ta1_y_xyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 715);

    auto ta1_y_xyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 716);

    auto ta1_y_xyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 717);

    auto ta1_y_xyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 718);

    auto ta1_y_xyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 719);

    auto ta1_y_xyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 720);

    auto ta1_y_xyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 721);

    auto ta1_y_xyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 722);

    auto ta1_y_xyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 723);

    auto ta1_y_xyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 724);

    auto ta1_y_xyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 725);

    auto ta1_y_xyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 726);

    auto ta1_y_xyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 727);

    auto ta1_y_xyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 728);

    auto ta1_y_xyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 729);

    auto ta1_y_xyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 730);

    auto ta1_y_xyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 731);

    auto ta1_y_xyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 732);

    auto ta1_y_xyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 733);

    auto ta1_y_xyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 734);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_y_xyzzz_xxxxx_0, ta1_y_xyzzz_xxxxy_0, ta1_y_xyzzz_xxxxz_0, ta1_y_xyzzz_xxxyy_0, ta1_y_xyzzz_xxxyz_0, ta1_y_xyzzz_xxxzz_0, ta1_y_xyzzz_xxyyy_0, ta1_y_xyzzz_xxyyz_0, ta1_y_xyzzz_xxyzz_0, ta1_y_xyzzz_xxzzz_0, ta1_y_xyzzz_xyyyy_0, ta1_y_xyzzz_xyyyz_0, ta1_y_xyzzz_xyyzz_0, ta1_y_xyzzz_xyzzz_0, ta1_y_xyzzz_xzzzz_0, ta1_y_xyzzz_yyyyy_0, ta1_y_xyzzz_yyyyz_0, ta1_y_xyzzz_yyyzz_0, ta1_y_xyzzz_yyzzz_0, ta1_y_xyzzz_yzzzz_0, ta1_y_xyzzz_zzzzz_0, ta1_y_xzzz_xxxxx_0, ta1_y_xzzz_xxxxx_1, ta1_y_xzzz_xxxxz_0, ta1_y_xzzz_xxxxz_1, ta1_y_xzzz_xxxzz_0, ta1_y_xzzz_xxxzz_1, ta1_y_xzzz_xxzzz_0, ta1_y_xzzz_xxzzz_1, ta1_y_xzzz_xzzzz_0, ta1_y_xzzz_xzzzz_1, ta1_y_yzzz_xxxxy_0, ta1_y_yzzz_xxxxy_1, ta1_y_yzzz_xxxy_0, ta1_y_yzzz_xxxy_1, ta1_y_yzzz_xxxyy_0, ta1_y_yzzz_xxxyy_1, ta1_y_yzzz_xxxyz_0, ta1_y_yzzz_xxxyz_1, ta1_y_yzzz_xxyy_0, ta1_y_yzzz_xxyy_1, ta1_y_yzzz_xxyyy_0, ta1_y_yzzz_xxyyy_1, ta1_y_yzzz_xxyyz_0, ta1_y_yzzz_xxyyz_1, ta1_y_yzzz_xxyz_0, ta1_y_yzzz_xxyz_1, ta1_y_yzzz_xxyzz_0, ta1_y_yzzz_xxyzz_1, ta1_y_yzzz_xyyy_0, ta1_y_yzzz_xyyy_1, ta1_y_yzzz_xyyyy_0, ta1_y_yzzz_xyyyy_1, ta1_y_yzzz_xyyyz_0, ta1_y_yzzz_xyyyz_1, ta1_y_yzzz_xyyz_0, ta1_y_yzzz_xyyz_1, ta1_y_yzzz_xyyzz_0, ta1_y_yzzz_xyyzz_1, ta1_y_yzzz_xyzz_0, ta1_y_yzzz_xyzz_1, ta1_y_yzzz_xyzzz_0, ta1_y_yzzz_xyzzz_1, ta1_y_yzzz_yyyy_0, ta1_y_yzzz_yyyy_1, ta1_y_yzzz_yyyyy_0, ta1_y_yzzz_yyyyy_1, ta1_y_yzzz_yyyyz_0, ta1_y_yzzz_yyyyz_1, ta1_y_yzzz_yyyz_0, ta1_y_yzzz_yyyz_1, ta1_y_yzzz_yyyzz_0, ta1_y_yzzz_yyyzz_1, ta1_y_yzzz_yyzz_0, ta1_y_yzzz_yyzz_1, ta1_y_yzzz_yyzzz_0, ta1_y_yzzz_yyzzz_1, ta1_y_yzzz_yzzz_0, ta1_y_yzzz_yzzz_1, ta1_y_yzzz_yzzzz_0, ta1_y_yzzz_yzzzz_1, ta1_y_yzzz_zzzzz_0, ta1_y_yzzz_zzzzz_1, ta_xzzz_xxxxx_1, ta_xzzz_xxxxz_1, ta_xzzz_xxxzz_1, ta_xzzz_xxzzz_1, ta_xzzz_xzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xyzzz_xxxxx_0[i] = ta_xzzz_xxxxx_1[i] + ta1_y_xzzz_xxxxx_0[i] * pa_y[i] - ta1_y_xzzz_xxxxx_1[i] * pc_y[i];

        ta1_y_xyzzz_xxxxy_0[i] = 4.0 * ta1_y_yzzz_xxxy_0[i] * fe_0 - 4.0 * ta1_y_yzzz_xxxy_1[i] * fe_0 + ta1_y_yzzz_xxxxy_0[i] * pa_x[i] - ta1_y_yzzz_xxxxy_1[i] * pc_x[i];

        ta1_y_xyzzz_xxxxz_0[i] = ta_xzzz_xxxxz_1[i] + ta1_y_xzzz_xxxxz_0[i] * pa_y[i] - ta1_y_xzzz_xxxxz_1[i] * pc_y[i];

        ta1_y_xyzzz_xxxyy_0[i] = 3.0 * ta1_y_yzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_y_yzzz_xxyy_1[i] * fe_0 + ta1_y_yzzz_xxxyy_0[i] * pa_x[i] - ta1_y_yzzz_xxxyy_1[i] * pc_x[i];

        ta1_y_xyzzz_xxxyz_0[i] = 3.0 * ta1_y_yzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_yzzz_xxyz_1[i] * fe_0 + ta1_y_yzzz_xxxyz_0[i] * pa_x[i] - ta1_y_yzzz_xxxyz_1[i] * pc_x[i];

        ta1_y_xyzzz_xxxzz_0[i] = ta_xzzz_xxxzz_1[i] + ta1_y_xzzz_xxxzz_0[i] * pa_y[i] - ta1_y_xzzz_xxxzz_1[i] * pc_y[i];

        ta1_y_xyzzz_xxyyy_0[i] = 2.0 * ta1_y_yzzz_xyyy_0[i] * fe_0 - 2.0 * ta1_y_yzzz_xyyy_1[i] * fe_0 + ta1_y_yzzz_xxyyy_0[i] * pa_x[i] - ta1_y_yzzz_xxyyy_1[i] * pc_x[i];

        ta1_y_xyzzz_xxyyz_0[i] = 2.0 * ta1_y_yzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yzzz_xyyz_1[i] * fe_0 + ta1_y_yzzz_xxyyz_0[i] * pa_x[i] - ta1_y_yzzz_xxyyz_1[i] * pc_x[i];

        ta1_y_xyzzz_xxyzz_0[i] = 2.0 * ta1_y_yzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_yzzz_xyzz_1[i] * fe_0 + ta1_y_yzzz_xxyzz_0[i] * pa_x[i] - ta1_y_yzzz_xxyzz_1[i] * pc_x[i];

        ta1_y_xyzzz_xxzzz_0[i] = ta_xzzz_xxzzz_1[i] + ta1_y_xzzz_xxzzz_0[i] * pa_y[i] - ta1_y_xzzz_xxzzz_1[i] * pc_y[i];

        ta1_y_xyzzz_xyyyy_0[i] = ta1_y_yzzz_yyyy_0[i] * fe_0 - ta1_y_yzzz_yyyy_1[i] * fe_0 + ta1_y_yzzz_xyyyy_0[i] * pa_x[i] - ta1_y_yzzz_xyyyy_1[i] * pc_x[i];

        ta1_y_xyzzz_xyyyz_0[i] = ta1_y_yzzz_yyyz_0[i] * fe_0 - ta1_y_yzzz_yyyz_1[i] * fe_0 + ta1_y_yzzz_xyyyz_0[i] * pa_x[i] - ta1_y_yzzz_xyyyz_1[i] * pc_x[i];

        ta1_y_xyzzz_xyyzz_0[i] = ta1_y_yzzz_yyzz_0[i] * fe_0 - ta1_y_yzzz_yyzz_1[i] * fe_0 + ta1_y_yzzz_xyyzz_0[i] * pa_x[i] - ta1_y_yzzz_xyyzz_1[i] * pc_x[i];

        ta1_y_xyzzz_xyzzz_0[i] = ta1_y_yzzz_yzzz_0[i] * fe_0 - ta1_y_yzzz_yzzz_1[i] * fe_0 + ta1_y_yzzz_xyzzz_0[i] * pa_x[i] - ta1_y_yzzz_xyzzz_1[i] * pc_x[i];

        ta1_y_xyzzz_xzzzz_0[i] = ta_xzzz_xzzzz_1[i] + ta1_y_xzzz_xzzzz_0[i] * pa_y[i] - ta1_y_xzzz_xzzzz_1[i] * pc_y[i];

        ta1_y_xyzzz_yyyyy_0[i] = ta1_y_yzzz_yyyyy_0[i] * pa_x[i] - ta1_y_yzzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xyzzz_yyyyz_0[i] = ta1_y_yzzz_yyyyz_0[i] * pa_x[i] - ta1_y_yzzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xyzzz_yyyzz_0[i] = ta1_y_yzzz_yyyzz_0[i] * pa_x[i] - ta1_y_yzzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xyzzz_yyzzz_0[i] = ta1_y_yzzz_yyzzz_0[i] * pa_x[i] - ta1_y_yzzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xyzzz_yzzzz_0[i] = ta1_y_yzzz_yzzzz_0[i] * pa_x[i] - ta1_y_yzzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xyzzz_zzzzz_0[i] = ta1_y_yzzz_zzzzz_0[i] * pa_x[i] - ta1_y_yzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 735-756 components of targeted buffer : HH

    auto ta1_y_xzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 735);

    auto ta1_y_xzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 736);

    auto ta1_y_xzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 737);

    auto ta1_y_xzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 738);

    auto ta1_y_xzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 739);

    auto ta1_y_xzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 740);

    auto ta1_y_xzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 741);

    auto ta1_y_xzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 742);

    auto ta1_y_xzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 743);

    auto ta1_y_xzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 744);

    auto ta1_y_xzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 745);

    auto ta1_y_xzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 746);

    auto ta1_y_xzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 747);

    auto ta1_y_xzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 748);

    auto ta1_y_xzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 749);

    auto ta1_y_xzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 750);

    auto ta1_y_xzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 751);

    auto ta1_y_xzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 752);

    auto ta1_y_xzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 753);

    auto ta1_y_xzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 754);

    auto ta1_y_xzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 755);

    #pragma omp simd aligned(pa_x, pc_x, ta1_y_xzzzz_xxxxx_0, ta1_y_xzzzz_xxxxy_0, ta1_y_xzzzz_xxxxz_0, ta1_y_xzzzz_xxxyy_0, ta1_y_xzzzz_xxxyz_0, ta1_y_xzzzz_xxxzz_0, ta1_y_xzzzz_xxyyy_0, ta1_y_xzzzz_xxyyz_0, ta1_y_xzzzz_xxyzz_0, ta1_y_xzzzz_xxzzz_0, ta1_y_xzzzz_xyyyy_0, ta1_y_xzzzz_xyyyz_0, ta1_y_xzzzz_xyyzz_0, ta1_y_xzzzz_xyzzz_0, ta1_y_xzzzz_xzzzz_0, ta1_y_xzzzz_yyyyy_0, ta1_y_xzzzz_yyyyz_0, ta1_y_xzzzz_yyyzz_0, ta1_y_xzzzz_yyzzz_0, ta1_y_xzzzz_yzzzz_0, ta1_y_xzzzz_zzzzz_0, ta1_y_zzzz_xxxx_0, ta1_y_zzzz_xxxx_1, ta1_y_zzzz_xxxxx_0, ta1_y_zzzz_xxxxx_1, ta1_y_zzzz_xxxxy_0, ta1_y_zzzz_xxxxy_1, ta1_y_zzzz_xxxxz_0, ta1_y_zzzz_xxxxz_1, ta1_y_zzzz_xxxy_0, ta1_y_zzzz_xxxy_1, ta1_y_zzzz_xxxyy_0, ta1_y_zzzz_xxxyy_1, ta1_y_zzzz_xxxyz_0, ta1_y_zzzz_xxxyz_1, ta1_y_zzzz_xxxz_0, ta1_y_zzzz_xxxz_1, ta1_y_zzzz_xxxzz_0, ta1_y_zzzz_xxxzz_1, ta1_y_zzzz_xxyy_0, ta1_y_zzzz_xxyy_1, ta1_y_zzzz_xxyyy_0, ta1_y_zzzz_xxyyy_1, ta1_y_zzzz_xxyyz_0, ta1_y_zzzz_xxyyz_1, ta1_y_zzzz_xxyz_0, ta1_y_zzzz_xxyz_1, ta1_y_zzzz_xxyzz_0, ta1_y_zzzz_xxyzz_1, ta1_y_zzzz_xxzz_0, ta1_y_zzzz_xxzz_1, ta1_y_zzzz_xxzzz_0, ta1_y_zzzz_xxzzz_1, ta1_y_zzzz_xyyy_0, ta1_y_zzzz_xyyy_1, ta1_y_zzzz_xyyyy_0, ta1_y_zzzz_xyyyy_1, ta1_y_zzzz_xyyyz_0, ta1_y_zzzz_xyyyz_1, ta1_y_zzzz_xyyz_0, ta1_y_zzzz_xyyz_1, ta1_y_zzzz_xyyzz_0, ta1_y_zzzz_xyyzz_1, ta1_y_zzzz_xyzz_0, ta1_y_zzzz_xyzz_1, ta1_y_zzzz_xyzzz_0, ta1_y_zzzz_xyzzz_1, ta1_y_zzzz_xzzz_0, ta1_y_zzzz_xzzz_1, ta1_y_zzzz_xzzzz_0, ta1_y_zzzz_xzzzz_1, ta1_y_zzzz_yyyy_0, ta1_y_zzzz_yyyy_1, ta1_y_zzzz_yyyyy_0, ta1_y_zzzz_yyyyy_1, ta1_y_zzzz_yyyyz_0, ta1_y_zzzz_yyyyz_1, ta1_y_zzzz_yyyz_0, ta1_y_zzzz_yyyz_1, ta1_y_zzzz_yyyzz_0, ta1_y_zzzz_yyyzz_1, ta1_y_zzzz_yyzz_0, ta1_y_zzzz_yyzz_1, ta1_y_zzzz_yyzzz_0, ta1_y_zzzz_yyzzz_1, ta1_y_zzzz_yzzz_0, ta1_y_zzzz_yzzz_1, ta1_y_zzzz_yzzzz_0, ta1_y_zzzz_yzzzz_1, ta1_y_zzzz_zzzz_0, ta1_y_zzzz_zzzz_1, ta1_y_zzzz_zzzzz_0, ta1_y_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_xzzzz_xxxxx_0[i] = 5.0 * ta1_y_zzzz_xxxx_0[i] * fe_0 - 5.0 * ta1_y_zzzz_xxxx_1[i] * fe_0 + ta1_y_zzzz_xxxxx_0[i] * pa_x[i] - ta1_y_zzzz_xxxxx_1[i] * pc_x[i];

        ta1_y_xzzzz_xxxxy_0[i] = 4.0 * ta1_y_zzzz_xxxy_0[i] * fe_0 - 4.0 * ta1_y_zzzz_xxxy_1[i] * fe_0 + ta1_y_zzzz_xxxxy_0[i] * pa_x[i] - ta1_y_zzzz_xxxxy_1[i] * pc_x[i];

        ta1_y_xzzzz_xxxxz_0[i] = 4.0 * ta1_y_zzzz_xxxz_0[i] * fe_0 - 4.0 * ta1_y_zzzz_xxxz_1[i] * fe_0 + ta1_y_zzzz_xxxxz_0[i] * pa_x[i] - ta1_y_zzzz_xxxxz_1[i] * pc_x[i];

        ta1_y_xzzzz_xxxyy_0[i] = 3.0 * ta1_y_zzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xxyy_1[i] * fe_0 + ta1_y_zzzz_xxxyy_0[i] * pa_x[i] - ta1_y_zzzz_xxxyy_1[i] * pc_x[i];

        ta1_y_xzzzz_xxxyz_0[i] = 3.0 * ta1_y_zzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xxyz_1[i] * fe_0 + ta1_y_zzzz_xxxyz_0[i] * pa_x[i] - ta1_y_zzzz_xxxyz_1[i] * pc_x[i];

        ta1_y_xzzzz_xxxzz_0[i] = 3.0 * ta1_y_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xxzz_1[i] * fe_0 + ta1_y_zzzz_xxxzz_0[i] * pa_x[i] - ta1_y_zzzz_xxxzz_1[i] * pc_x[i];

        ta1_y_xzzzz_xxyyy_0[i] = 2.0 * ta1_y_zzzz_xyyy_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xyyy_1[i] * fe_0 + ta1_y_zzzz_xxyyy_0[i] * pa_x[i] - ta1_y_zzzz_xxyyy_1[i] * pc_x[i];

        ta1_y_xzzzz_xxyyz_0[i] = 2.0 * ta1_y_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xyyz_1[i] * fe_0 + ta1_y_zzzz_xxyyz_0[i] * pa_x[i] - ta1_y_zzzz_xxyyz_1[i] * pc_x[i];

        ta1_y_xzzzz_xxyzz_0[i] = 2.0 * ta1_y_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xyzz_1[i] * fe_0 + ta1_y_zzzz_xxyzz_0[i] * pa_x[i] - ta1_y_zzzz_xxyzz_1[i] * pc_x[i];

        ta1_y_xzzzz_xxzzz_0[i] = 2.0 * ta1_y_zzzz_xzzz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xzzz_1[i] * fe_0 + ta1_y_zzzz_xxzzz_0[i] * pa_x[i] - ta1_y_zzzz_xxzzz_1[i] * pc_x[i];

        ta1_y_xzzzz_xyyyy_0[i] = ta1_y_zzzz_yyyy_0[i] * fe_0 - ta1_y_zzzz_yyyy_1[i] * fe_0 + ta1_y_zzzz_xyyyy_0[i] * pa_x[i] - ta1_y_zzzz_xyyyy_1[i] * pc_x[i];

        ta1_y_xzzzz_xyyyz_0[i] = ta1_y_zzzz_yyyz_0[i] * fe_0 - ta1_y_zzzz_yyyz_1[i] * fe_0 + ta1_y_zzzz_xyyyz_0[i] * pa_x[i] - ta1_y_zzzz_xyyyz_1[i] * pc_x[i];

        ta1_y_xzzzz_xyyzz_0[i] = ta1_y_zzzz_yyzz_0[i] * fe_0 - ta1_y_zzzz_yyzz_1[i] * fe_0 + ta1_y_zzzz_xyyzz_0[i] * pa_x[i] - ta1_y_zzzz_xyyzz_1[i] * pc_x[i];

        ta1_y_xzzzz_xyzzz_0[i] = ta1_y_zzzz_yzzz_0[i] * fe_0 - ta1_y_zzzz_yzzz_1[i] * fe_0 + ta1_y_zzzz_xyzzz_0[i] * pa_x[i] - ta1_y_zzzz_xyzzz_1[i] * pc_x[i];

        ta1_y_xzzzz_xzzzz_0[i] = ta1_y_zzzz_zzzz_0[i] * fe_0 - ta1_y_zzzz_zzzz_1[i] * fe_0 + ta1_y_zzzz_xzzzz_0[i] * pa_x[i] - ta1_y_zzzz_xzzzz_1[i] * pc_x[i];

        ta1_y_xzzzz_yyyyy_0[i] = ta1_y_zzzz_yyyyy_0[i] * pa_x[i] - ta1_y_zzzz_yyyyy_1[i] * pc_x[i];

        ta1_y_xzzzz_yyyyz_0[i] = ta1_y_zzzz_yyyyz_0[i] * pa_x[i] - ta1_y_zzzz_yyyyz_1[i] * pc_x[i];

        ta1_y_xzzzz_yyyzz_0[i] = ta1_y_zzzz_yyyzz_0[i] * pa_x[i] - ta1_y_zzzz_yyyzz_1[i] * pc_x[i];

        ta1_y_xzzzz_yyzzz_0[i] = ta1_y_zzzz_yyzzz_0[i] * pa_x[i] - ta1_y_zzzz_yyzzz_1[i] * pc_x[i];

        ta1_y_xzzzz_yzzzz_0[i] = ta1_y_zzzz_yzzzz_0[i] * pa_x[i] - ta1_y_zzzz_yzzzz_1[i] * pc_x[i];

        ta1_y_xzzzz_zzzzz_0[i] = ta1_y_zzzz_zzzzz_0[i] * pa_x[i] - ta1_y_zzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 756-777 components of targeted buffer : HH

    auto ta1_y_yyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 756);

    auto ta1_y_yyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 757);

    auto ta1_y_yyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 758);

    auto ta1_y_yyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 759);

    auto ta1_y_yyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 760);

    auto ta1_y_yyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 761);

    auto ta1_y_yyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 762);

    auto ta1_y_yyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 763);

    auto ta1_y_yyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 764);

    auto ta1_y_yyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 765);

    auto ta1_y_yyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 766);

    auto ta1_y_yyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 767);

    auto ta1_y_yyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 768);

    auto ta1_y_yyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 769);

    auto ta1_y_yyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 770);

    auto ta1_y_yyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 771);

    auto ta1_y_yyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 772);

    auto ta1_y_yyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 773);

    auto ta1_y_yyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 774);

    auto ta1_y_yyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 775);

    auto ta1_y_yyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 776);

    #pragma omp simd aligned(pa_y, pc_y, ta1_y_yyy_xxxxx_0, ta1_y_yyy_xxxxx_1, ta1_y_yyy_xxxxy_0, ta1_y_yyy_xxxxy_1, ta1_y_yyy_xxxxz_0, ta1_y_yyy_xxxxz_1, ta1_y_yyy_xxxyy_0, ta1_y_yyy_xxxyy_1, ta1_y_yyy_xxxyz_0, ta1_y_yyy_xxxyz_1, ta1_y_yyy_xxxzz_0, ta1_y_yyy_xxxzz_1, ta1_y_yyy_xxyyy_0, ta1_y_yyy_xxyyy_1, ta1_y_yyy_xxyyz_0, ta1_y_yyy_xxyyz_1, ta1_y_yyy_xxyzz_0, ta1_y_yyy_xxyzz_1, ta1_y_yyy_xxzzz_0, ta1_y_yyy_xxzzz_1, ta1_y_yyy_xyyyy_0, ta1_y_yyy_xyyyy_1, ta1_y_yyy_xyyyz_0, ta1_y_yyy_xyyyz_1, ta1_y_yyy_xyyzz_0, ta1_y_yyy_xyyzz_1, ta1_y_yyy_xyzzz_0, ta1_y_yyy_xyzzz_1, ta1_y_yyy_xzzzz_0, ta1_y_yyy_xzzzz_1, ta1_y_yyy_yyyyy_0, ta1_y_yyy_yyyyy_1, ta1_y_yyy_yyyyz_0, ta1_y_yyy_yyyyz_1, ta1_y_yyy_yyyzz_0, ta1_y_yyy_yyyzz_1, ta1_y_yyy_yyzzz_0, ta1_y_yyy_yyzzz_1, ta1_y_yyy_yzzzz_0, ta1_y_yyy_yzzzz_1, ta1_y_yyy_zzzzz_0, ta1_y_yyy_zzzzz_1, ta1_y_yyyy_xxxx_0, ta1_y_yyyy_xxxx_1, ta1_y_yyyy_xxxxx_0, ta1_y_yyyy_xxxxx_1, ta1_y_yyyy_xxxxy_0, ta1_y_yyyy_xxxxy_1, ta1_y_yyyy_xxxxz_0, ta1_y_yyyy_xxxxz_1, ta1_y_yyyy_xxxy_0, ta1_y_yyyy_xxxy_1, ta1_y_yyyy_xxxyy_0, ta1_y_yyyy_xxxyy_1, ta1_y_yyyy_xxxyz_0, ta1_y_yyyy_xxxyz_1, ta1_y_yyyy_xxxz_0, ta1_y_yyyy_xxxz_1, ta1_y_yyyy_xxxzz_0, ta1_y_yyyy_xxxzz_1, ta1_y_yyyy_xxyy_0, ta1_y_yyyy_xxyy_1, ta1_y_yyyy_xxyyy_0, ta1_y_yyyy_xxyyy_1, ta1_y_yyyy_xxyyz_0, ta1_y_yyyy_xxyyz_1, ta1_y_yyyy_xxyz_0, ta1_y_yyyy_xxyz_1, ta1_y_yyyy_xxyzz_0, ta1_y_yyyy_xxyzz_1, ta1_y_yyyy_xxzz_0, ta1_y_yyyy_xxzz_1, ta1_y_yyyy_xxzzz_0, ta1_y_yyyy_xxzzz_1, ta1_y_yyyy_xyyy_0, ta1_y_yyyy_xyyy_1, ta1_y_yyyy_xyyyy_0, ta1_y_yyyy_xyyyy_1, ta1_y_yyyy_xyyyz_0, ta1_y_yyyy_xyyyz_1, ta1_y_yyyy_xyyz_0, ta1_y_yyyy_xyyz_1, ta1_y_yyyy_xyyzz_0, ta1_y_yyyy_xyyzz_1, ta1_y_yyyy_xyzz_0, ta1_y_yyyy_xyzz_1, ta1_y_yyyy_xyzzz_0, ta1_y_yyyy_xyzzz_1, ta1_y_yyyy_xzzz_0, ta1_y_yyyy_xzzz_1, ta1_y_yyyy_xzzzz_0, ta1_y_yyyy_xzzzz_1, ta1_y_yyyy_yyyy_0, ta1_y_yyyy_yyyy_1, ta1_y_yyyy_yyyyy_0, ta1_y_yyyy_yyyyy_1, ta1_y_yyyy_yyyyz_0, ta1_y_yyyy_yyyyz_1, ta1_y_yyyy_yyyz_0, ta1_y_yyyy_yyyz_1, ta1_y_yyyy_yyyzz_0, ta1_y_yyyy_yyyzz_1, ta1_y_yyyy_yyzz_0, ta1_y_yyyy_yyzz_1, ta1_y_yyyy_yyzzz_0, ta1_y_yyyy_yyzzz_1, ta1_y_yyyy_yzzz_0, ta1_y_yyyy_yzzz_1, ta1_y_yyyy_yzzzz_0, ta1_y_yyyy_yzzzz_1, ta1_y_yyyy_zzzz_0, ta1_y_yyyy_zzzz_1, ta1_y_yyyy_zzzzz_0, ta1_y_yyyy_zzzzz_1, ta1_y_yyyyy_xxxxx_0, ta1_y_yyyyy_xxxxy_0, ta1_y_yyyyy_xxxxz_0, ta1_y_yyyyy_xxxyy_0, ta1_y_yyyyy_xxxyz_0, ta1_y_yyyyy_xxxzz_0, ta1_y_yyyyy_xxyyy_0, ta1_y_yyyyy_xxyyz_0, ta1_y_yyyyy_xxyzz_0, ta1_y_yyyyy_xxzzz_0, ta1_y_yyyyy_xyyyy_0, ta1_y_yyyyy_xyyyz_0, ta1_y_yyyyy_xyyzz_0, ta1_y_yyyyy_xyzzz_0, ta1_y_yyyyy_xzzzz_0, ta1_y_yyyyy_yyyyy_0, ta1_y_yyyyy_yyyyz_0, ta1_y_yyyyy_yyyzz_0, ta1_y_yyyyy_yyzzz_0, ta1_y_yyyyy_yzzzz_0, ta1_y_yyyyy_zzzzz_0, ta_yyyy_xxxxx_1, ta_yyyy_xxxxy_1, ta_yyyy_xxxxz_1, ta_yyyy_xxxyy_1, ta_yyyy_xxxyz_1, ta_yyyy_xxxzz_1, ta_yyyy_xxyyy_1, ta_yyyy_xxyyz_1, ta_yyyy_xxyzz_1, ta_yyyy_xxzzz_1, ta_yyyy_xyyyy_1, ta_yyyy_xyyyz_1, ta_yyyy_xyyzz_1, ta_yyyy_xyzzz_1, ta_yyyy_xzzzz_1, ta_yyyy_yyyyy_1, ta_yyyy_yyyyz_1, ta_yyyy_yyyzz_1, ta_yyyy_yyzzz_1, ta_yyyy_yzzzz_1, ta_yyyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_yyyyy_xxxxx_0[i] = 4.0 * ta1_y_yyy_xxxxx_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxxx_1[i] * fe_0 + ta_yyyy_xxxxx_1[i] + ta1_y_yyyy_xxxxx_0[i] * pa_y[i] - ta1_y_yyyy_xxxxx_1[i] * pc_y[i];

        ta1_y_yyyyy_xxxxy_0[i] = 4.0 * ta1_y_yyy_xxxxy_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxxy_1[i] * fe_0 + ta1_y_yyyy_xxxx_0[i] * fe_0 - ta1_y_yyyy_xxxx_1[i] * fe_0 + ta_yyyy_xxxxy_1[i] + ta1_y_yyyy_xxxxy_0[i] * pa_y[i] - ta1_y_yyyy_xxxxy_1[i] * pc_y[i];

        ta1_y_yyyyy_xxxxz_0[i] = 4.0 * ta1_y_yyy_xxxxz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxxz_1[i] * fe_0 + ta_yyyy_xxxxz_1[i] + ta1_y_yyyy_xxxxz_0[i] * pa_y[i] - ta1_y_yyyy_xxxxz_1[i] * pc_y[i];

        ta1_y_yyyyy_xxxyy_0[i] = 4.0 * ta1_y_yyy_xxxyy_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxyy_1[i] * fe_0 + 2.0 * ta1_y_yyyy_xxxy_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xxxy_1[i] * fe_0 + ta_yyyy_xxxyy_1[i] + ta1_y_yyyy_xxxyy_0[i] * pa_y[i] - ta1_y_yyyy_xxxyy_1[i] * pc_y[i];

        ta1_y_yyyyy_xxxyz_0[i] = 4.0 * ta1_y_yyy_xxxyz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxyz_1[i] * fe_0 + ta1_y_yyyy_xxxz_0[i] * fe_0 - ta1_y_yyyy_xxxz_1[i] * fe_0 + ta_yyyy_xxxyz_1[i] + ta1_y_yyyy_xxxyz_0[i] * pa_y[i] - ta1_y_yyyy_xxxyz_1[i] * pc_y[i];

        ta1_y_yyyyy_xxxzz_0[i] = 4.0 * ta1_y_yyy_xxxzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxxzz_1[i] * fe_0 + ta_yyyy_xxxzz_1[i] + ta1_y_yyyy_xxxzz_0[i] * pa_y[i] - ta1_y_yyyy_xxxzz_1[i] * pc_y[i];

        ta1_y_yyyyy_xxyyy_0[i] = 4.0 * ta1_y_yyy_xxyyy_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxyyy_1[i] * fe_0 + 3.0 * ta1_y_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xxyy_1[i] * fe_0 + ta_yyyy_xxyyy_1[i] + ta1_y_yyyy_xxyyy_0[i] * pa_y[i] - ta1_y_yyyy_xxyyy_1[i] * pc_y[i];

        ta1_y_yyyyy_xxyyz_0[i] = 4.0 * ta1_y_yyy_xxyyz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_y_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xxyz_1[i] * fe_0 + ta_yyyy_xxyyz_1[i] + ta1_y_yyyy_xxyyz_0[i] * pa_y[i] - ta1_y_yyyy_xxyyz_1[i] * pc_y[i];

        ta1_y_yyyyy_xxyzz_0[i] = 4.0 * ta1_y_yyy_xxyzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxyzz_1[i] * fe_0 + ta1_y_yyyy_xxzz_0[i] * fe_0 - ta1_y_yyyy_xxzz_1[i] * fe_0 + ta_yyyy_xxyzz_1[i] + ta1_y_yyyy_xxyzz_0[i] * pa_y[i] - ta1_y_yyyy_xxyzz_1[i] * pc_y[i];

        ta1_y_yyyyy_xxzzz_0[i] = 4.0 * ta1_y_yyy_xxzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xxzzz_1[i] * fe_0 + ta_yyyy_xxzzz_1[i] + ta1_y_yyyy_xxzzz_0[i] * pa_y[i] - ta1_y_yyyy_xxzzz_1[i] * pc_y[i];

        ta1_y_yyyyy_xyyyy_0[i] = 4.0 * ta1_y_yyy_xyyyy_0[i] * fe_0 - 4.0 * ta1_y_yyy_xyyyy_1[i] * fe_0 + 4.0 * ta1_y_yyyy_xyyy_0[i] * fe_0 - 4.0 * ta1_y_yyyy_xyyy_1[i] * fe_0 + ta_yyyy_xyyyy_1[i] + ta1_y_yyyy_xyyyy_0[i] * pa_y[i] - ta1_y_yyyy_xyyyy_1[i] * pc_y[i];

        ta1_y_yyyyy_xyyyz_0[i] = 4.0 * ta1_y_yyy_xyyyz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xyyyz_1[i] * fe_0 + 3.0 * ta1_y_yyyy_xyyz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xyyz_1[i] * fe_0 + ta_yyyy_xyyyz_1[i] + ta1_y_yyyy_xyyyz_0[i] * pa_y[i] - ta1_y_yyyy_xyyyz_1[i] * pc_y[i];

        ta1_y_yyyyy_xyyzz_0[i] = 4.0 * ta1_y_yyy_xyyzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xyyzz_1[i] * fe_0 + 2.0 * ta1_y_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xyzz_1[i] * fe_0 + ta_yyyy_xyyzz_1[i] + ta1_y_yyyy_xyyzz_0[i] * pa_y[i] - ta1_y_yyyy_xyyzz_1[i] * pc_y[i];

        ta1_y_yyyyy_xyzzz_0[i] = 4.0 * ta1_y_yyy_xyzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xyzzz_1[i] * fe_0 + ta1_y_yyyy_xzzz_0[i] * fe_0 - ta1_y_yyyy_xzzz_1[i] * fe_0 + ta_yyyy_xyzzz_1[i] + ta1_y_yyyy_xyzzz_0[i] * pa_y[i] - ta1_y_yyyy_xyzzz_1[i] * pc_y[i];

        ta1_y_yyyyy_xzzzz_0[i] = 4.0 * ta1_y_yyy_xzzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_xzzzz_1[i] * fe_0 + ta_yyyy_xzzzz_1[i] + ta1_y_yyyy_xzzzz_0[i] * pa_y[i] - ta1_y_yyyy_xzzzz_1[i] * pc_y[i];

        ta1_y_yyyyy_yyyyy_0[i] = 4.0 * ta1_y_yyy_yyyyy_0[i] * fe_0 - 4.0 * ta1_y_yyy_yyyyy_1[i] * fe_0 + 5.0 * ta1_y_yyyy_yyyy_0[i] * fe_0 - 5.0 * ta1_y_yyyy_yyyy_1[i] * fe_0 + ta_yyyy_yyyyy_1[i] + ta1_y_yyyy_yyyyy_0[i] * pa_y[i] - ta1_y_yyyy_yyyyy_1[i] * pc_y[i];

        ta1_y_yyyyy_yyyyz_0[i] = 4.0 * ta1_y_yyy_yyyyz_0[i] * fe_0 - 4.0 * ta1_y_yyy_yyyyz_1[i] * fe_0 + 4.0 * ta1_y_yyyy_yyyz_0[i] * fe_0 - 4.0 * ta1_y_yyyy_yyyz_1[i] * fe_0 + ta_yyyy_yyyyz_1[i] + ta1_y_yyyy_yyyyz_0[i] * pa_y[i] - ta1_y_yyyy_yyyyz_1[i] * pc_y[i];

        ta1_y_yyyyy_yyyzz_0[i] = 4.0 * ta1_y_yyy_yyyzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_yyyzz_1[i] * fe_0 + 3.0 * ta1_y_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_yyzz_1[i] * fe_0 + ta_yyyy_yyyzz_1[i] + ta1_y_yyyy_yyyzz_0[i] * pa_y[i] - ta1_y_yyyy_yyyzz_1[i] * pc_y[i];

        ta1_y_yyyyy_yyzzz_0[i] = 4.0 * ta1_y_yyy_yyzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_yyzzz_1[i] * fe_0 + 2.0 * ta1_y_yyyy_yzzz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_yzzz_1[i] * fe_0 + ta_yyyy_yyzzz_1[i] + ta1_y_yyyy_yyzzz_0[i] * pa_y[i] - ta1_y_yyyy_yyzzz_1[i] * pc_y[i];

        ta1_y_yyyyy_yzzzz_0[i] = 4.0 * ta1_y_yyy_yzzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_yzzzz_1[i] * fe_0 + ta1_y_yyyy_zzzz_0[i] * fe_0 - ta1_y_yyyy_zzzz_1[i] * fe_0 + ta_yyyy_yzzzz_1[i] + ta1_y_yyyy_yzzzz_0[i] * pa_y[i] - ta1_y_yyyy_yzzzz_1[i] * pc_y[i];

        ta1_y_yyyyy_zzzzz_0[i] = 4.0 * ta1_y_yyy_zzzzz_0[i] * fe_0 - 4.0 * ta1_y_yyy_zzzzz_1[i] * fe_0 + ta_yyyy_zzzzz_1[i] + ta1_y_yyyy_zzzzz_0[i] * pa_y[i] - ta1_y_yyyy_zzzzz_1[i] * pc_y[i];
    }

    // Set up 777-798 components of targeted buffer : HH

    auto ta1_y_yyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 777);

    auto ta1_y_yyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 778);

    auto ta1_y_yyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 779);

    auto ta1_y_yyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 780);

    auto ta1_y_yyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 781);

    auto ta1_y_yyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 782);

    auto ta1_y_yyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 783);

    auto ta1_y_yyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 784);

    auto ta1_y_yyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 785);

    auto ta1_y_yyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 786);

    auto ta1_y_yyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 787);

    auto ta1_y_yyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 788);

    auto ta1_y_yyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 789);

    auto ta1_y_yyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 790);

    auto ta1_y_yyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 791);

    auto ta1_y_yyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 792);

    auto ta1_y_yyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 793);

    auto ta1_y_yyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 794);

    auto ta1_y_yyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 795);

    auto ta1_y_yyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 796);

    auto ta1_y_yyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 797);

    #pragma omp simd aligned(pa_z, pc_z, ta1_y_yyyy_xxxx_0, ta1_y_yyyy_xxxx_1, ta1_y_yyyy_xxxxx_0, ta1_y_yyyy_xxxxx_1, ta1_y_yyyy_xxxxy_0, ta1_y_yyyy_xxxxy_1, ta1_y_yyyy_xxxxz_0, ta1_y_yyyy_xxxxz_1, ta1_y_yyyy_xxxy_0, ta1_y_yyyy_xxxy_1, ta1_y_yyyy_xxxyy_0, ta1_y_yyyy_xxxyy_1, ta1_y_yyyy_xxxyz_0, ta1_y_yyyy_xxxyz_1, ta1_y_yyyy_xxxz_0, ta1_y_yyyy_xxxz_1, ta1_y_yyyy_xxxzz_0, ta1_y_yyyy_xxxzz_1, ta1_y_yyyy_xxyy_0, ta1_y_yyyy_xxyy_1, ta1_y_yyyy_xxyyy_0, ta1_y_yyyy_xxyyy_1, ta1_y_yyyy_xxyyz_0, ta1_y_yyyy_xxyyz_1, ta1_y_yyyy_xxyz_0, ta1_y_yyyy_xxyz_1, ta1_y_yyyy_xxyzz_0, ta1_y_yyyy_xxyzz_1, ta1_y_yyyy_xxzz_0, ta1_y_yyyy_xxzz_1, ta1_y_yyyy_xxzzz_0, ta1_y_yyyy_xxzzz_1, ta1_y_yyyy_xyyy_0, ta1_y_yyyy_xyyy_1, ta1_y_yyyy_xyyyy_0, ta1_y_yyyy_xyyyy_1, ta1_y_yyyy_xyyyz_0, ta1_y_yyyy_xyyyz_1, ta1_y_yyyy_xyyz_0, ta1_y_yyyy_xyyz_1, ta1_y_yyyy_xyyzz_0, ta1_y_yyyy_xyyzz_1, ta1_y_yyyy_xyzz_0, ta1_y_yyyy_xyzz_1, ta1_y_yyyy_xyzzz_0, ta1_y_yyyy_xyzzz_1, ta1_y_yyyy_xzzz_0, ta1_y_yyyy_xzzz_1, ta1_y_yyyy_xzzzz_0, ta1_y_yyyy_xzzzz_1, ta1_y_yyyy_yyyy_0, ta1_y_yyyy_yyyy_1, ta1_y_yyyy_yyyyy_0, ta1_y_yyyy_yyyyy_1, ta1_y_yyyy_yyyyz_0, ta1_y_yyyy_yyyyz_1, ta1_y_yyyy_yyyz_0, ta1_y_yyyy_yyyz_1, ta1_y_yyyy_yyyzz_0, ta1_y_yyyy_yyyzz_1, ta1_y_yyyy_yyzz_0, ta1_y_yyyy_yyzz_1, ta1_y_yyyy_yyzzz_0, ta1_y_yyyy_yyzzz_1, ta1_y_yyyy_yzzz_0, ta1_y_yyyy_yzzz_1, ta1_y_yyyy_yzzzz_0, ta1_y_yyyy_yzzzz_1, ta1_y_yyyy_zzzz_0, ta1_y_yyyy_zzzz_1, ta1_y_yyyy_zzzzz_0, ta1_y_yyyy_zzzzz_1, ta1_y_yyyyz_xxxxx_0, ta1_y_yyyyz_xxxxy_0, ta1_y_yyyyz_xxxxz_0, ta1_y_yyyyz_xxxyy_0, ta1_y_yyyyz_xxxyz_0, ta1_y_yyyyz_xxxzz_0, ta1_y_yyyyz_xxyyy_0, ta1_y_yyyyz_xxyyz_0, ta1_y_yyyyz_xxyzz_0, ta1_y_yyyyz_xxzzz_0, ta1_y_yyyyz_xyyyy_0, ta1_y_yyyyz_xyyyz_0, ta1_y_yyyyz_xyyzz_0, ta1_y_yyyyz_xyzzz_0, ta1_y_yyyyz_xzzzz_0, ta1_y_yyyyz_yyyyy_0, ta1_y_yyyyz_yyyyz_0, ta1_y_yyyyz_yyyzz_0, ta1_y_yyyyz_yyzzz_0, ta1_y_yyyyz_yzzzz_0, ta1_y_yyyyz_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_yyyyz_xxxxx_0[i] = ta1_y_yyyy_xxxxx_0[i] * pa_z[i] - ta1_y_yyyy_xxxxx_1[i] * pc_z[i];

        ta1_y_yyyyz_xxxxy_0[i] = ta1_y_yyyy_xxxxy_0[i] * pa_z[i] - ta1_y_yyyy_xxxxy_1[i] * pc_z[i];

        ta1_y_yyyyz_xxxxz_0[i] = ta1_y_yyyy_xxxx_0[i] * fe_0 - ta1_y_yyyy_xxxx_1[i] * fe_0 + ta1_y_yyyy_xxxxz_0[i] * pa_z[i] - ta1_y_yyyy_xxxxz_1[i] * pc_z[i];

        ta1_y_yyyyz_xxxyy_0[i] = ta1_y_yyyy_xxxyy_0[i] * pa_z[i] - ta1_y_yyyy_xxxyy_1[i] * pc_z[i];

        ta1_y_yyyyz_xxxyz_0[i] = ta1_y_yyyy_xxxy_0[i] * fe_0 - ta1_y_yyyy_xxxy_1[i] * fe_0 + ta1_y_yyyy_xxxyz_0[i] * pa_z[i] - ta1_y_yyyy_xxxyz_1[i] * pc_z[i];

        ta1_y_yyyyz_xxxzz_0[i] = 2.0 * ta1_y_yyyy_xxxz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xxxz_1[i] * fe_0 + ta1_y_yyyy_xxxzz_0[i] * pa_z[i] - ta1_y_yyyy_xxxzz_1[i] * pc_z[i];

        ta1_y_yyyyz_xxyyy_0[i] = ta1_y_yyyy_xxyyy_0[i] * pa_z[i] - ta1_y_yyyy_xxyyy_1[i] * pc_z[i];

        ta1_y_yyyyz_xxyyz_0[i] = ta1_y_yyyy_xxyy_0[i] * fe_0 - ta1_y_yyyy_xxyy_1[i] * fe_0 + ta1_y_yyyy_xxyyz_0[i] * pa_z[i] - ta1_y_yyyy_xxyyz_1[i] * pc_z[i];

        ta1_y_yyyyz_xxyzz_0[i] = 2.0 * ta1_y_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xxyz_1[i] * fe_0 + ta1_y_yyyy_xxyzz_0[i] * pa_z[i] - ta1_y_yyyy_xxyzz_1[i] * pc_z[i];

        ta1_y_yyyyz_xxzzz_0[i] = 3.0 * ta1_y_yyyy_xxzz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xxzz_1[i] * fe_0 + ta1_y_yyyy_xxzzz_0[i] * pa_z[i] - ta1_y_yyyy_xxzzz_1[i] * pc_z[i];

        ta1_y_yyyyz_xyyyy_0[i] = ta1_y_yyyy_xyyyy_0[i] * pa_z[i] - ta1_y_yyyy_xyyyy_1[i] * pc_z[i];

        ta1_y_yyyyz_xyyyz_0[i] = ta1_y_yyyy_xyyy_0[i] * fe_0 - ta1_y_yyyy_xyyy_1[i] * fe_0 + ta1_y_yyyy_xyyyz_0[i] * pa_z[i] - ta1_y_yyyy_xyyyz_1[i] * pc_z[i];

        ta1_y_yyyyz_xyyzz_0[i] = 2.0 * ta1_y_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_xyyz_1[i] * fe_0 + ta1_y_yyyy_xyyzz_0[i] * pa_z[i] - ta1_y_yyyy_xyyzz_1[i] * pc_z[i];

        ta1_y_yyyyz_xyzzz_0[i] = 3.0 * ta1_y_yyyy_xyzz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_xyzz_1[i] * fe_0 + ta1_y_yyyy_xyzzz_0[i] * pa_z[i] - ta1_y_yyyy_xyzzz_1[i] * pc_z[i];

        ta1_y_yyyyz_xzzzz_0[i] = 4.0 * ta1_y_yyyy_xzzz_0[i] * fe_0 - 4.0 * ta1_y_yyyy_xzzz_1[i] * fe_0 + ta1_y_yyyy_xzzzz_0[i] * pa_z[i] - ta1_y_yyyy_xzzzz_1[i] * pc_z[i];

        ta1_y_yyyyz_yyyyy_0[i] = ta1_y_yyyy_yyyyy_0[i] * pa_z[i] - ta1_y_yyyy_yyyyy_1[i] * pc_z[i];

        ta1_y_yyyyz_yyyyz_0[i] = ta1_y_yyyy_yyyy_0[i] * fe_0 - ta1_y_yyyy_yyyy_1[i] * fe_0 + ta1_y_yyyy_yyyyz_0[i] * pa_z[i] - ta1_y_yyyy_yyyyz_1[i] * pc_z[i];

        ta1_y_yyyyz_yyyzz_0[i] = 2.0 * ta1_y_yyyy_yyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyy_yyyz_1[i] * fe_0 + ta1_y_yyyy_yyyzz_0[i] * pa_z[i] - ta1_y_yyyy_yyyzz_1[i] * pc_z[i];

        ta1_y_yyyyz_yyzzz_0[i] = 3.0 * ta1_y_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_y_yyyy_yyzz_1[i] * fe_0 + ta1_y_yyyy_yyzzz_0[i] * pa_z[i] - ta1_y_yyyy_yyzzz_1[i] * pc_z[i];

        ta1_y_yyyyz_yzzzz_0[i] = 4.0 * ta1_y_yyyy_yzzz_0[i] * fe_0 - 4.0 * ta1_y_yyyy_yzzz_1[i] * fe_0 + ta1_y_yyyy_yzzzz_0[i] * pa_z[i] - ta1_y_yyyy_yzzzz_1[i] * pc_z[i];

        ta1_y_yyyyz_zzzzz_0[i] = 5.0 * ta1_y_yyyy_zzzz_0[i] * fe_0 - 5.0 * ta1_y_yyyy_zzzz_1[i] * fe_0 + ta1_y_yyyy_zzzzz_0[i] * pa_z[i] - ta1_y_yyyy_zzzzz_1[i] * pc_z[i];
    }

    // Set up 798-819 components of targeted buffer : HH

    auto ta1_y_yyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 798);

    auto ta1_y_yyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 799);

    auto ta1_y_yyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 800);

    auto ta1_y_yyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 801);

    auto ta1_y_yyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 802);

    auto ta1_y_yyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 803);

    auto ta1_y_yyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 804);

    auto ta1_y_yyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 805);

    auto ta1_y_yyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 806);

    auto ta1_y_yyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 807);

    auto ta1_y_yyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 808);

    auto ta1_y_yyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 809);

    auto ta1_y_yyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 810);

    auto ta1_y_yyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 811);

    auto ta1_y_yyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 812);

    auto ta1_y_yyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 813);

    auto ta1_y_yyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 814);

    auto ta1_y_yyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 815);

    auto ta1_y_yyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 816);

    auto ta1_y_yyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 817);

    auto ta1_y_yyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 818);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_y_yyy_xxxxx_0, ta1_y_yyy_xxxxx_1, ta1_y_yyy_xxxxy_0, ta1_y_yyy_xxxxy_1, ta1_y_yyy_xxxyy_0, ta1_y_yyy_xxxyy_1, ta1_y_yyy_xxxyz_0, ta1_y_yyy_xxxyz_1, ta1_y_yyy_xxyyy_0, ta1_y_yyy_xxyyy_1, ta1_y_yyy_xxyyz_0, ta1_y_yyy_xxyyz_1, ta1_y_yyy_xxyzz_0, ta1_y_yyy_xxyzz_1, ta1_y_yyy_xyyyy_0, ta1_y_yyy_xyyyy_1, ta1_y_yyy_xyyyz_0, ta1_y_yyy_xyyyz_1, ta1_y_yyy_xyyzz_0, ta1_y_yyy_xyyzz_1, ta1_y_yyy_xyzzz_0, ta1_y_yyy_xyzzz_1, ta1_y_yyy_yyyyy_0, ta1_y_yyy_yyyyy_1, ta1_y_yyy_yyyyz_0, ta1_y_yyy_yyyyz_1, ta1_y_yyy_yyyzz_0, ta1_y_yyy_yyyzz_1, ta1_y_yyy_yyzzz_0, ta1_y_yyy_yyzzz_1, ta1_y_yyy_yzzzz_0, ta1_y_yyy_yzzzz_1, ta1_y_yyyz_xxxxx_0, ta1_y_yyyz_xxxxx_1, ta1_y_yyyz_xxxxy_0, ta1_y_yyyz_xxxxy_1, ta1_y_yyyz_xxxy_0, ta1_y_yyyz_xxxy_1, ta1_y_yyyz_xxxyy_0, ta1_y_yyyz_xxxyy_1, ta1_y_yyyz_xxxyz_0, ta1_y_yyyz_xxxyz_1, ta1_y_yyyz_xxyy_0, ta1_y_yyyz_xxyy_1, ta1_y_yyyz_xxyyy_0, ta1_y_yyyz_xxyyy_1, ta1_y_yyyz_xxyyz_0, ta1_y_yyyz_xxyyz_1, ta1_y_yyyz_xxyz_0, ta1_y_yyyz_xxyz_1, ta1_y_yyyz_xxyzz_0, ta1_y_yyyz_xxyzz_1, ta1_y_yyyz_xyyy_0, ta1_y_yyyz_xyyy_1, ta1_y_yyyz_xyyyy_0, ta1_y_yyyz_xyyyy_1, ta1_y_yyyz_xyyyz_0, ta1_y_yyyz_xyyyz_1, ta1_y_yyyz_xyyz_0, ta1_y_yyyz_xyyz_1, ta1_y_yyyz_xyyzz_0, ta1_y_yyyz_xyyzz_1, ta1_y_yyyz_xyzz_0, ta1_y_yyyz_xyzz_1, ta1_y_yyyz_xyzzz_0, ta1_y_yyyz_xyzzz_1, ta1_y_yyyz_yyyy_0, ta1_y_yyyz_yyyy_1, ta1_y_yyyz_yyyyy_0, ta1_y_yyyz_yyyyy_1, ta1_y_yyyz_yyyyz_0, ta1_y_yyyz_yyyyz_1, ta1_y_yyyz_yyyz_0, ta1_y_yyyz_yyyz_1, ta1_y_yyyz_yyyzz_0, ta1_y_yyyz_yyyzz_1, ta1_y_yyyz_yyzz_0, ta1_y_yyyz_yyzz_1, ta1_y_yyyz_yyzzz_0, ta1_y_yyyz_yyzzz_1, ta1_y_yyyz_yzzz_0, ta1_y_yyyz_yzzz_1, ta1_y_yyyz_yzzzz_0, ta1_y_yyyz_yzzzz_1, ta1_y_yyyzz_xxxxx_0, ta1_y_yyyzz_xxxxy_0, ta1_y_yyyzz_xxxxz_0, ta1_y_yyyzz_xxxyy_0, ta1_y_yyyzz_xxxyz_0, ta1_y_yyyzz_xxxzz_0, ta1_y_yyyzz_xxyyy_0, ta1_y_yyyzz_xxyyz_0, ta1_y_yyyzz_xxyzz_0, ta1_y_yyyzz_xxzzz_0, ta1_y_yyyzz_xyyyy_0, ta1_y_yyyzz_xyyyz_0, ta1_y_yyyzz_xyyzz_0, ta1_y_yyyzz_xyzzz_0, ta1_y_yyyzz_xzzzz_0, ta1_y_yyyzz_yyyyy_0, ta1_y_yyyzz_yyyyz_0, ta1_y_yyyzz_yyyzz_0, ta1_y_yyyzz_yyzzz_0, ta1_y_yyyzz_yzzzz_0, ta1_y_yyyzz_zzzzz_0, ta1_y_yyzz_xxxxz_0, ta1_y_yyzz_xxxxz_1, ta1_y_yyzz_xxxzz_0, ta1_y_yyzz_xxxzz_1, ta1_y_yyzz_xxzzz_0, ta1_y_yyzz_xxzzz_1, ta1_y_yyzz_xzzzz_0, ta1_y_yyzz_xzzzz_1, ta1_y_yyzz_zzzzz_0, ta1_y_yyzz_zzzzz_1, ta1_y_yzz_xxxxz_0, ta1_y_yzz_xxxxz_1, ta1_y_yzz_xxxzz_0, ta1_y_yzz_xxxzz_1, ta1_y_yzz_xxzzz_0, ta1_y_yzz_xxzzz_1, ta1_y_yzz_xzzzz_0, ta1_y_yzz_xzzzz_1, ta1_y_yzz_zzzzz_0, ta1_y_yzz_zzzzz_1, ta_yyzz_xxxxz_1, ta_yyzz_xxxzz_1, ta_yyzz_xxzzz_1, ta_yyzz_xzzzz_1, ta_yyzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_yyyzz_xxxxx_0[i] = ta1_y_yyy_xxxxx_0[i] * fe_0 - ta1_y_yyy_xxxxx_1[i] * fe_0 + ta1_y_yyyz_xxxxx_0[i] * pa_z[i] - ta1_y_yyyz_xxxxx_1[i] * pc_z[i];

        ta1_y_yyyzz_xxxxy_0[i] = ta1_y_yyy_xxxxy_0[i] * fe_0 - ta1_y_yyy_xxxxy_1[i] * fe_0 + ta1_y_yyyz_xxxxy_0[i] * pa_z[i] - ta1_y_yyyz_xxxxy_1[i] * pc_z[i];

        ta1_y_yyyzz_xxxxz_0[i] = 2.0 * ta1_y_yzz_xxxxz_0[i] * fe_0 - 2.0 * ta1_y_yzz_xxxxz_1[i] * fe_0 + ta_yyzz_xxxxz_1[i] + ta1_y_yyzz_xxxxz_0[i] * pa_y[i] - ta1_y_yyzz_xxxxz_1[i] * pc_y[i];

        ta1_y_yyyzz_xxxyy_0[i] = ta1_y_yyy_xxxyy_0[i] * fe_0 - ta1_y_yyy_xxxyy_1[i] * fe_0 + ta1_y_yyyz_xxxyy_0[i] * pa_z[i] - ta1_y_yyyz_xxxyy_1[i] * pc_z[i];

        ta1_y_yyyzz_xxxyz_0[i] = ta1_y_yyy_xxxyz_0[i] * fe_0 - ta1_y_yyy_xxxyz_1[i] * fe_0 + ta1_y_yyyz_xxxy_0[i] * fe_0 - ta1_y_yyyz_xxxy_1[i] * fe_0 + ta1_y_yyyz_xxxyz_0[i] * pa_z[i] - ta1_y_yyyz_xxxyz_1[i] * pc_z[i];

        ta1_y_yyyzz_xxxzz_0[i] = 2.0 * ta1_y_yzz_xxxzz_0[i] * fe_0 - 2.0 * ta1_y_yzz_xxxzz_1[i] * fe_0 + ta_yyzz_xxxzz_1[i] + ta1_y_yyzz_xxxzz_0[i] * pa_y[i] - ta1_y_yyzz_xxxzz_1[i] * pc_y[i];

        ta1_y_yyyzz_xxyyy_0[i] = ta1_y_yyy_xxyyy_0[i] * fe_0 - ta1_y_yyy_xxyyy_1[i] * fe_0 + ta1_y_yyyz_xxyyy_0[i] * pa_z[i] - ta1_y_yyyz_xxyyy_1[i] * pc_z[i];

        ta1_y_yyyzz_xxyyz_0[i] = ta1_y_yyy_xxyyz_0[i] * fe_0 - ta1_y_yyy_xxyyz_1[i] * fe_0 + ta1_y_yyyz_xxyy_0[i] * fe_0 - ta1_y_yyyz_xxyy_1[i] * fe_0 + ta1_y_yyyz_xxyyz_0[i] * pa_z[i] - ta1_y_yyyz_xxyyz_1[i] * pc_z[i];

        ta1_y_yyyzz_xxyzz_0[i] = ta1_y_yyy_xxyzz_0[i] * fe_0 - ta1_y_yyy_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_yyyz_xxyz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_xxyz_1[i] * fe_0 + ta1_y_yyyz_xxyzz_0[i] * pa_z[i] - ta1_y_yyyz_xxyzz_1[i] * pc_z[i];

        ta1_y_yyyzz_xxzzz_0[i] = 2.0 * ta1_y_yzz_xxzzz_0[i] * fe_0 - 2.0 * ta1_y_yzz_xxzzz_1[i] * fe_0 + ta_yyzz_xxzzz_1[i] + ta1_y_yyzz_xxzzz_0[i] * pa_y[i] - ta1_y_yyzz_xxzzz_1[i] * pc_y[i];

        ta1_y_yyyzz_xyyyy_0[i] = ta1_y_yyy_xyyyy_0[i] * fe_0 - ta1_y_yyy_xyyyy_1[i] * fe_0 + ta1_y_yyyz_xyyyy_0[i] * pa_z[i] - ta1_y_yyyz_xyyyy_1[i] * pc_z[i];

        ta1_y_yyyzz_xyyyz_0[i] = ta1_y_yyy_xyyyz_0[i] * fe_0 - ta1_y_yyy_xyyyz_1[i] * fe_0 + ta1_y_yyyz_xyyy_0[i] * fe_0 - ta1_y_yyyz_xyyy_1[i] * fe_0 + ta1_y_yyyz_xyyyz_0[i] * pa_z[i] - ta1_y_yyyz_xyyyz_1[i] * pc_z[i];

        ta1_y_yyyzz_xyyzz_0[i] = ta1_y_yyy_xyyzz_0[i] * fe_0 - ta1_y_yyy_xyyzz_1[i] * fe_0 + 2.0 * ta1_y_yyyz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_xyyz_1[i] * fe_0 + ta1_y_yyyz_xyyzz_0[i] * pa_z[i] - ta1_y_yyyz_xyyzz_1[i] * pc_z[i];

        ta1_y_yyyzz_xyzzz_0[i] = ta1_y_yyy_xyzzz_0[i] * fe_0 - ta1_y_yyy_xyzzz_1[i] * fe_0 + 3.0 * ta1_y_yyyz_xyzz_0[i] * fe_0 - 3.0 * ta1_y_yyyz_xyzz_1[i] * fe_0 + ta1_y_yyyz_xyzzz_0[i] * pa_z[i] - ta1_y_yyyz_xyzzz_1[i] * pc_z[i];

        ta1_y_yyyzz_xzzzz_0[i] = 2.0 * ta1_y_yzz_xzzzz_0[i] * fe_0 - 2.0 * ta1_y_yzz_xzzzz_1[i] * fe_0 + ta_yyzz_xzzzz_1[i] + ta1_y_yyzz_xzzzz_0[i] * pa_y[i] - ta1_y_yyzz_xzzzz_1[i] * pc_y[i];

        ta1_y_yyyzz_yyyyy_0[i] = ta1_y_yyy_yyyyy_0[i] * fe_0 - ta1_y_yyy_yyyyy_1[i] * fe_0 + ta1_y_yyyz_yyyyy_0[i] * pa_z[i] - ta1_y_yyyz_yyyyy_1[i] * pc_z[i];

        ta1_y_yyyzz_yyyyz_0[i] = ta1_y_yyy_yyyyz_0[i] * fe_0 - ta1_y_yyy_yyyyz_1[i] * fe_0 + ta1_y_yyyz_yyyy_0[i] * fe_0 - ta1_y_yyyz_yyyy_1[i] * fe_0 + ta1_y_yyyz_yyyyz_0[i] * pa_z[i] - ta1_y_yyyz_yyyyz_1[i] * pc_z[i];

        ta1_y_yyyzz_yyyzz_0[i] = ta1_y_yyy_yyyzz_0[i] * fe_0 - ta1_y_yyy_yyyzz_1[i] * fe_0 + 2.0 * ta1_y_yyyz_yyyz_0[i] * fe_0 - 2.0 * ta1_y_yyyz_yyyz_1[i] * fe_0 + ta1_y_yyyz_yyyzz_0[i] * pa_z[i] - ta1_y_yyyz_yyyzz_1[i] * pc_z[i];

        ta1_y_yyyzz_yyzzz_0[i] = ta1_y_yyy_yyzzz_0[i] * fe_0 - ta1_y_yyy_yyzzz_1[i] * fe_0 + 3.0 * ta1_y_yyyz_yyzz_0[i] * fe_0 - 3.0 * ta1_y_yyyz_yyzz_1[i] * fe_0 + ta1_y_yyyz_yyzzz_0[i] * pa_z[i] - ta1_y_yyyz_yyzzz_1[i] * pc_z[i];

        ta1_y_yyyzz_yzzzz_0[i] = ta1_y_yyy_yzzzz_0[i] * fe_0 - ta1_y_yyy_yzzzz_1[i] * fe_0 + 4.0 * ta1_y_yyyz_yzzz_0[i] * fe_0 - 4.0 * ta1_y_yyyz_yzzz_1[i] * fe_0 + ta1_y_yyyz_yzzzz_0[i] * pa_z[i] - ta1_y_yyyz_yzzzz_1[i] * pc_z[i];

        ta1_y_yyyzz_zzzzz_0[i] = 2.0 * ta1_y_yzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_y_yzz_zzzzz_1[i] * fe_0 + ta_yyzz_zzzzz_1[i] + ta1_y_yyzz_zzzzz_0[i] * pa_y[i] - ta1_y_yyzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 819-840 components of targeted buffer : HH

    auto ta1_y_yyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 819);

    auto ta1_y_yyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 820);

    auto ta1_y_yyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 821);

    auto ta1_y_yyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 822);

    auto ta1_y_yyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 823);

    auto ta1_y_yyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 824);

    auto ta1_y_yyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 825);

    auto ta1_y_yyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 826);

    auto ta1_y_yyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 827);

    auto ta1_y_yyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 828);

    auto ta1_y_yyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 829);

    auto ta1_y_yyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 830);

    auto ta1_y_yyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 831);

    auto ta1_y_yyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 832);

    auto ta1_y_yyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 833);

    auto ta1_y_yyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 834);

    auto ta1_y_yyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 835);

    auto ta1_y_yyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 836);

    auto ta1_y_yyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 837);

    auto ta1_y_yyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 838);

    auto ta1_y_yyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 839);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_y_yyz_xxxxx_0, ta1_y_yyz_xxxxx_1, ta1_y_yyz_xxxxy_0, ta1_y_yyz_xxxxy_1, ta1_y_yyz_xxxyy_0, ta1_y_yyz_xxxyy_1, ta1_y_yyz_xxxyz_0, ta1_y_yyz_xxxyz_1, ta1_y_yyz_xxyyy_0, ta1_y_yyz_xxyyy_1, ta1_y_yyz_xxyyz_0, ta1_y_yyz_xxyyz_1, ta1_y_yyz_xxyzz_0, ta1_y_yyz_xxyzz_1, ta1_y_yyz_xyyyy_0, ta1_y_yyz_xyyyy_1, ta1_y_yyz_xyyyz_0, ta1_y_yyz_xyyyz_1, ta1_y_yyz_xyyzz_0, ta1_y_yyz_xyyzz_1, ta1_y_yyz_xyzzz_0, ta1_y_yyz_xyzzz_1, ta1_y_yyz_yyyyy_0, ta1_y_yyz_yyyyy_1, ta1_y_yyz_yyyyz_0, ta1_y_yyz_yyyyz_1, ta1_y_yyz_yyyzz_0, ta1_y_yyz_yyyzz_1, ta1_y_yyz_yyzzz_0, ta1_y_yyz_yyzzz_1, ta1_y_yyz_yzzzz_0, ta1_y_yyz_yzzzz_1, ta1_y_yyzz_xxxxx_0, ta1_y_yyzz_xxxxx_1, ta1_y_yyzz_xxxxy_0, ta1_y_yyzz_xxxxy_1, ta1_y_yyzz_xxxy_0, ta1_y_yyzz_xxxy_1, ta1_y_yyzz_xxxyy_0, ta1_y_yyzz_xxxyy_1, ta1_y_yyzz_xxxyz_0, ta1_y_yyzz_xxxyz_1, ta1_y_yyzz_xxyy_0, ta1_y_yyzz_xxyy_1, ta1_y_yyzz_xxyyy_0, ta1_y_yyzz_xxyyy_1, ta1_y_yyzz_xxyyz_0, ta1_y_yyzz_xxyyz_1, ta1_y_yyzz_xxyz_0, ta1_y_yyzz_xxyz_1, ta1_y_yyzz_xxyzz_0, ta1_y_yyzz_xxyzz_1, ta1_y_yyzz_xyyy_0, ta1_y_yyzz_xyyy_1, ta1_y_yyzz_xyyyy_0, ta1_y_yyzz_xyyyy_1, ta1_y_yyzz_xyyyz_0, ta1_y_yyzz_xyyyz_1, ta1_y_yyzz_xyyz_0, ta1_y_yyzz_xyyz_1, ta1_y_yyzz_xyyzz_0, ta1_y_yyzz_xyyzz_1, ta1_y_yyzz_xyzz_0, ta1_y_yyzz_xyzz_1, ta1_y_yyzz_xyzzz_0, ta1_y_yyzz_xyzzz_1, ta1_y_yyzz_yyyy_0, ta1_y_yyzz_yyyy_1, ta1_y_yyzz_yyyyy_0, ta1_y_yyzz_yyyyy_1, ta1_y_yyzz_yyyyz_0, ta1_y_yyzz_yyyyz_1, ta1_y_yyzz_yyyz_0, ta1_y_yyzz_yyyz_1, ta1_y_yyzz_yyyzz_0, ta1_y_yyzz_yyyzz_1, ta1_y_yyzz_yyzz_0, ta1_y_yyzz_yyzz_1, ta1_y_yyzz_yyzzz_0, ta1_y_yyzz_yyzzz_1, ta1_y_yyzz_yzzz_0, ta1_y_yyzz_yzzz_1, ta1_y_yyzz_yzzzz_0, ta1_y_yyzz_yzzzz_1, ta1_y_yyzzz_xxxxx_0, ta1_y_yyzzz_xxxxy_0, ta1_y_yyzzz_xxxxz_0, ta1_y_yyzzz_xxxyy_0, ta1_y_yyzzz_xxxyz_0, ta1_y_yyzzz_xxxzz_0, ta1_y_yyzzz_xxyyy_0, ta1_y_yyzzz_xxyyz_0, ta1_y_yyzzz_xxyzz_0, ta1_y_yyzzz_xxzzz_0, ta1_y_yyzzz_xyyyy_0, ta1_y_yyzzz_xyyyz_0, ta1_y_yyzzz_xyyzz_0, ta1_y_yyzzz_xyzzz_0, ta1_y_yyzzz_xzzzz_0, ta1_y_yyzzz_yyyyy_0, ta1_y_yyzzz_yyyyz_0, ta1_y_yyzzz_yyyzz_0, ta1_y_yyzzz_yyzzz_0, ta1_y_yyzzz_yzzzz_0, ta1_y_yyzzz_zzzzz_0, ta1_y_yzzz_xxxxz_0, ta1_y_yzzz_xxxxz_1, ta1_y_yzzz_xxxzz_0, ta1_y_yzzz_xxxzz_1, ta1_y_yzzz_xxzzz_0, ta1_y_yzzz_xxzzz_1, ta1_y_yzzz_xzzzz_0, ta1_y_yzzz_xzzzz_1, ta1_y_yzzz_zzzzz_0, ta1_y_yzzz_zzzzz_1, ta1_y_zzz_xxxxz_0, ta1_y_zzz_xxxxz_1, ta1_y_zzz_xxxzz_0, ta1_y_zzz_xxxzz_1, ta1_y_zzz_xxzzz_0, ta1_y_zzz_xxzzz_1, ta1_y_zzz_xzzzz_0, ta1_y_zzz_xzzzz_1, ta1_y_zzz_zzzzz_0, ta1_y_zzz_zzzzz_1, ta_yzzz_xxxxz_1, ta_yzzz_xxxzz_1, ta_yzzz_xxzzz_1, ta_yzzz_xzzzz_1, ta_yzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_yyzzz_xxxxx_0[i] = 2.0 * ta1_y_yyz_xxxxx_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxxxx_1[i] * fe_0 + ta1_y_yyzz_xxxxx_0[i] * pa_z[i] - ta1_y_yyzz_xxxxx_1[i] * pc_z[i];

        ta1_y_yyzzz_xxxxy_0[i] = 2.0 * ta1_y_yyz_xxxxy_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxxxy_1[i] * fe_0 + ta1_y_yyzz_xxxxy_0[i] * pa_z[i] - ta1_y_yyzz_xxxxy_1[i] * pc_z[i];

        ta1_y_yyzzz_xxxxz_0[i] = ta1_y_zzz_xxxxz_0[i] * fe_0 - ta1_y_zzz_xxxxz_1[i] * fe_0 + ta_yzzz_xxxxz_1[i] + ta1_y_yzzz_xxxxz_0[i] * pa_y[i] - ta1_y_yzzz_xxxxz_1[i] * pc_y[i];

        ta1_y_yyzzz_xxxyy_0[i] = 2.0 * ta1_y_yyz_xxxyy_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxxyy_1[i] * fe_0 + ta1_y_yyzz_xxxyy_0[i] * pa_z[i] - ta1_y_yyzz_xxxyy_1[i] * pc_z[i];

        ta1_y_yyzzz_xxxyz_0[i] = 2.0 * ta1_y_yyz_xxxyz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxxyz_1[i] * fe_0 + ta1_y_yyzz_xxxy_0[i] * fe_0 - ta1_y_yyzz_xxxy_1[i] * fe_0 + ta1_y_yyzz_xxxyz_0[i] * pa_z[i] - ta1_y_yyzz_xxxyz_1[i] * pc_z[i];

        ta1_y_yyzzz_xxxzz_0[i] = ta1_y_zzz_xxxzz_0[i] * fe_0 - ta1_y_zzz_xxxzz_1[i] * fe_0 + ta_yzzz_xxxzz_1[i] + ta1_y_yzzz_xxxzz_0[i] * pa_y[i] - ta1_y_yzzz_xxxzz_1[i] * pc_y[i];

        ta1_y_yyzzz_xxyyy_0[i] = 2.0 * ta1_y_yyz_xxyyy_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxyyy_1[i] * fe_0 + ta1_y_yyzz_xxyyy_0[i] * pa_z[i] - ta1_y_yyzz_xxyyy_1[i] * pc_z[i];

        ta1_y_yyzzz_xxyyz_0[i] = 2.0 * ta1_y_yyz_xxyyz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxyyz_1[i] * fe_0 + ta1_y_yyzz_xxyy_0[i] * fe_0 - ta1_y_yyzz_xxyy_1[i] * fe_0 + ta1_y_yyzz_xxyyz_0[i] * pa_z[i] - ta1_y_yyzz_xxyyz_1[i] * pc_z[i];

        ta1_y_yyzzz_xxyzz_0[i] = 2.0 * ta1_y_yyz_xxyzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_yyzz_xxyz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xxyz_1[i] * fe_0 + ta1_y_yyzz_xxyzz_0[i] * pa_z[i] - ta1_y_yyzz_xxyzz_1[i] * pc_z[i];

        ta1_y_yyzzz_xxzzz_0[i] = ta1_y_zzz_xxzzz_0[i] * fe_0 - ta1_y_zzz_xxzzz_1[i] * fe_0 + ta_yzzz_xxzzz_1[i] + ta1_y_yzzz_xxzzz_0[i] * pa_y[i] - ta1_y_yzzz_xxzzz_1[i] * pc_y[i];

        ta1_y_yyzzz_xyyyy_0[i] = 2.0 * ta1_y_yyz_xyyyy_0[i] * fe_0 - 2.0 * ta1_y_yyz_xyyyy_1[i] * fe_0 + ta1_y_yyzz_xyyyy_0[i] * pa_z[i] - ta1_y_yyzz_xyyyy_1[i] * pc_z[i];

        ta1_y_yyzzz_xyyyz_0[i] = 2.0 * ta1_y_yyz_xyyyz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xyyyz_1[i] * fe_0 + ta1_y_yyzz_xyyy_0[i] * fe_0 - ta1_y_yyzz_xyyy_1[i] * fe_0 + ta1_y_yyzz_xyyyz_0[i] * pa_z[i] - ta1_y_yyzz_xyyyz_1[i] * pc_z[i];

        ta1_y_yyzzz_xyyzz_0[i] = 2.0 * ta1_y_yyz_xyyzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xyyzz_1[i] * fe_0 + 2.0 * ta1_y_yyzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_xyyz_1[i] * fe_0 + ta1_y_yyzz_xyyzz_0[i] * pa_z[i] - ta1_y_yyzz_xyyzz_1[i] * pc_z[i];

        ta1_y_yyzzz_xyzzz_0[i] = 2.0 * ta1_y_yyz_xyzzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_xyzzz_1[i] * fe_0 + 3.0 * ta1_y_yyzz_xyzz_0[i] * fe_0 - 3.0 * ta1_y_yyzz_xyzz_1[i] * fe_0 + ta1_y_yyzz_xyzzz_0[i] * pa_z[i] - ta1_y_yyzz_xyzzz_1[i] * pc_z[i];

        ta1_y_yyzzz_xzzzz_0[i] = ta1_y_zzz_xzzzz_0[i] * fe_0 - ta1_y_zzz_xzzzz_1[i] * fe_0 + ta_yzzz_xzzzz_1[i] + ta1_y_yzzz_xzzzz_0[i] * pa_y[i] - ta1_y_yzzz_xzzzz_1[i] * pc_y[i];

        ta1_y_yyzzz_yyyyy_0[i] = 2.0 * ta1_y_yyz_yyyyy_0[i] * fe_0 - 2.0 * ta1_y_yyz_yyyyy_1[i] * fe_0 + ta1_y_yyzz_yyyyy_0[i] * pa_z[i] - ta1_y_yyzz_yyyyy_1[i] * pc_z[i];

        ta1_y_yyzzz_yyyyz_0[i] = 2.0 * ta1_y_yyz_yyyyz_0[i] * fe_0 - 2.0 * ta1_y_yyz_yyyyz_1[i] * fe_0 + ta1_y_yyzz_yyyy_0[i] * fe_0 - ta1_y_yyzz_yyyy_1[i] * fe_0 + ta1_y_yyzz_yyyyz_0[i] * pa_z[i] - ta1_y_yyzz_yyyyz_1[i] * pc_z[i];

        ta1_y_yyzzz_yyyzz_0[i] = 2.0 * ta1_y_yyz_yyyzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_yyyzz_1[i] * fe_0 + 2.0 * ta1_y_yyzz_yyyz_0[i] * fe_0 - 2.0 * ta1_y_yyzz_yyyz_1[i] * fe_0 + ta1_y_yyzz_yyyzz_0[i] * pa_z[i] - ta1_y_yyzz_yyyzz_1[i] * pc_z[i];

        ta1_y_yyzzz_yyzzz_0[i] = 2.0 * ta1_y_yyz_yyzzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_yyzzz_1[i] * fe_0 + 3.0 * ta1_y_yyzz_yyzz_0[i] * fe_0 - 3.0 * ta1_y_yyzz_yyzz_1[i] * fe_0 + ta1_y_yyzz_yyzzz_0[i] * pa_z[i] - ta1_y_yyzz_yyzzz_1[i] * pc_z[i];

        ta1_y_yyzzz_yzzzz_0[i] = 2.0 * ta1_y_yyz_yzzzz_0[i] * fe_0 - 2.0 * ta1_y_yyz_yzzzz_1[i] * fe_0 + 4.0 * ta1_y_yyzz_yzzz_0[i] * fe_0 - 4.0 * ta1_y_yyzz_yzzz_1[i] * fe_0 + ta1_y_yyzz_yzzzz_0[i] * pa_z[i] - ta1_y_yyzz_yzzzz_1[i] * pc_z[i];

        ta1_y_yyzzz_zzzzz_0[i] = ta1_y_zzz_zzzzz_0[i] * fe_0 - ta1_y_zzz_zzzzz_1[i] * fe_0 + ta_yzzz_zzzzz_1[i] + ta1_y_yzzz_zzzzz_0[i] * pa_y[i] - ta1_y_yzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 840-861 components of targeted buffer : HH

    auto ta1_y_yzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 840);

    auto ta1_y_yzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 841);

    auto ta1_y_yzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 842);

    auto ta1_y_yzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 843);

    auto ta1_y_yzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 844);

    auto ta1_y_yzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 845);

    auto ta1_y_yzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 846);

    auto ta1_y_yzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 847);

    auto ta1_y_yzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 848);

    auto ta1_y_yzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 849);

    auto ta1_y_yzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 850);

    auto ta1_y_yzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 851);

    auto ta1_y_yzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 852);

    auto ta1_y_yzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 853);

    auto ta1_y_yzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 854);

    auto ta1_y_yzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 855);

    auto ta1_y_yzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 856);

    auto ta1_y_yzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 857);

    auto ta1_y_yzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 858);

    auto ta1_y_yzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 859);

    auto ta1_y_yzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 860);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_y_yzz_xxxxy_0, ta1_y_yzz_xxxxy_1, ta1_y_yzz_xxxyy_0, ta1_y_yzz_xxxyy_1, ta1_y_yzz_xxyyy_0, ta1_y_yzz_xxyyy_1, ta1_y_yzz_xyyyy_0, ta1_y_yzz_xyyyy_1, ta1_y_yzz_yyyyy_0, ta1_y_yzz_yyyyy_1, ta1_y_yzzz_xxxxy_0, ta1_y_yzzz_xxxxy_1, ta1_y_yzzz_xxxyy_0, ta1_y_yzzz_xxxyy_1, ta1_y_yzzz_xxyyy_0, ta1_y_yzzz_xxyyy_1, ta1_y_yzzz_xyyyy_0, ta1_y_yzzz_xyyyy_1, ta1_y_yzzz_yyyyy_0, ta1_y_yzzz_yyyyy_1, ta1_y_yzzzz_xxxxx_0, ta1_y_yzzzz_xxxxy_0, ta1_y_yzzzz_xxxxz_0, ta1_y_yzzzz_xxxyy_0, ta1_y_yzzzz_xxxyz_0, ta1_y_yzzzz_xxxzz_0, ta1_y_yzzzz_xxyyy_0, ta1_y_yzzzz_xxyyz_0, ta1_y_yzzzz_xxyzz_0, ta1_y_yzzzz_xxzzz_0, ta1_y_yzzzz_xyyyy_0, ta1_y_yzzzz_xyyyz_0, ta1_y_yzzzz_xyyzz_0, ta1_y_yzzzz_xyzzz_0, ta1_y_yzzzz_xzzzz_0, ta1_y_yzzzz_yyyyy_0, ta1_y_yzzzz_yyyyz_0, ta1_y_yzzzz_yyyzz_0, ta1_y_yzzzz_yyzzz_0, ta1_y_yzzzz_yzzzz_0, ta1_y_yzzzz_zzzzz_0, ta1_y_zzzz_xxxxx_0, ta1_y_zzzz_xxxxx_1, ta1_y_zzzz_xxxxz_0, ta1_y_zzzz_xxxxz_1, ta1_y_zzzz_xxxyz_0, ta1_y_zzzz_xxxyz_1, ta1_y_zzzz_xxxz_0, ta1_y_zzzz_xxxz_1, ta1_y_zzzz_xxxzz_0, ta1_y_zzzz_xxxzz_1, ta1_y_zzzz_xxyyz_0, ta1_y_zzzz_xxyyz_1, ta1_y_zzzz_xxyz_0, ta1_y_zzzz_xxyz_1, ta1_y_zzzz_xxyzz_0, ta1_y_zzzz_xxyzz_1, ta1_y_zzzz_xxzz_0, ta1_y_zzzz_xxzz_1, ta1_y_zzzz_xxzzz_0, ta1_y_zzzz_xxzzz_1, ta1_y_zzzz_xyyyz_0, ta1_y_zzzz_xyyyz_1, ta1_y_zzzz_xyyz_0, ta1_y_zzzz_xyyz_1, ta1_y_zzzz_xyyzz_0, ta1_y_zzzz_xyyzz_1, ta1_y_zzzz_xyzz_0, ta1_y_zzzz_xyzz_1, ta1_y_zzzz_xyzzz_0, ta1_y_zzzz_xyzzz_1, ta1_y_zzzz_xzzz_0, ta1_y_zzzz_xzzz_1, ta1_y_zzzz_xzzzz_0, ta1_y_zzzz_xzzzz_1, ta1_y_zzzz_yyyyz_0, ta1_y_zzzz_yyyyz_1, ta1_y_zzzz_yyyz_0, ta1_y_zzzz_yyyz_1, ta1_y_zzzz_yyyzz_0, ta1_y_zzzz_yyyzz_1, ta1_y_zzzz_yyzz_0, ta1_y_zzzz_yyzz_1, ta1_y_zzzz_yyzzz_0, ta1_y_zzzz_yyzzz_1, ta1_y_zzzz_yzzz_0, ta1_y_zzzz_yzzz_1, ta1_y_zzzz_yzzzz_0, ta1_y_zzzz_yzzzz_1, ta1_y_zzzz_zzzz_0, ta1_y_zzzz_zzzz_1, ta1_y_zzzz_zzzzz_0, ta1_y_zzzz_zzzzz_1, ta_zzzz_xxxxx_1, ta_zzzz_xxxxz_1, ta_zzzz_xxxyz_1, ta_zzzz_xxxzz_1, ta_zzzz_xxyyz_1, ta_zzzz_xxyzz_1, ta_zzzz_xxzzz_1, ta_zzzz_xyyyz_1, ta_zzzz_xyyzz_1, ta_zzzz_xyzzz_1, ta_zzzz_xzzzz_1, ta_zzzz_yyyyz_1, ta_zzzz_yyyzz_1, ta_zzzz_yyzzz_1, ta_zzzz_yzzzz_1, ta_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_yzzzz_xxxxx_0[i] = ta_zzzz_xxxxx_1[i] + ta1_y_zzzz_xxxxx_0[i] * pa_y[i] - ta1_y_zzzz_xxxxx_1[i] * pc_y[i];

        ta1_y_yzzzz_xxxxy_0[i] = 3.0 * ta1_y_yzz_xxxxy_0[i] * fe_0 - 3.0 * ta1_y_yzz_xxxxy_1[i] * fe_0 + ta1_y_yzzz_xxxxy_0[i] * pa_z[i] - ta1_y_yzzz_xxxxy_1[i] * pc_z[i];

        ta1_y_yzzzz_xxxxz_0[i] = ta_zzzz_xxxxz_1[i] + ta1_y_zzzz_xxxxz_0[i] * pa_y[i] - ta1_y_zzzz_xxxxz_1[i] * pc_y[i];

        ta1_y_yzzzz_xxxyy_0[i] = 3.0 * ta1_y_yzz_xxxyy_0[i] * fe_0 - 3.0 * ta1_y_yzz_xxxyy_1[i] * fe_0 + ta1_y_yzzz_xxxyy_0[i] * pa_z[i] - ta1_y_yzzz_xxxyy_1[i] * pc_z[i];

        ta1_y_yzzzz_xxxyz_0[i] = ta1_y_zzzz_xxxz_0[i] * fe_0 - ta1_y_zzzz_xxxz_1[i] * fe_0 + ta_zzzz_xxxyz_1[i] + ta1_y_zzzz_xxxyz_0[i] * pa_y[i] - ta1_y_zzzz_xxxyz_1[i] * pc_y[i];

        ta1_y_yzzzz_xxxzz_0[i] = ta_zzzz_xxxzz_1[i] + ta1_y_zzzz_xxxzz_0[i] * pa_y[i] - ta1_y_zzzz_xxxzz_1[i] * pc_y[i];

        ta1_y_yzzzz_xxyyy_0[i] = 3.0 * ta1_y_yzz_xxyyy_0[i] * fe_0 - 3.0 * ta1_y_yzz_xxyyy_1[i] * fe_0 + ta1_y_yzzz_xxyyy_0[i] * pa_z[i] - ta1_y_yzzz_xxyyy_1[i] * pc_z[i];

        ta1_y_yzzzz_xxyyz_0[i] = 2.0 * ta1_y_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xxyz_1[i] * fe_0 + ta_zzzz_xxyyz_1[i] + ta1_y_zzzz_xxyyz_0[i] * pa_y[i] - ta1_y_zzzz_xxyyz_1[i] * pc_y[i];

        ta1_y_yzzzz_xxyzz_0[i] = ta1_y_zzzz_xxzz_0[i] * fe_0 - ta1_y_zzzz_xxzz_1[i] * fe_0 + ta_zzzz_xxyzz_1[i] + ta1_y_zzzz_xxyzz_0[i] * pa_y[i] - ta1_y_zzzz_xxyzz_1[i] * pc_y[i];

        ta1_y_yzzzz_xxzzz_0[i] = ta_zzzz_xxzzz_1[i] + ta1_y_zzzz_xxzzz_0[i] * pa_y[i] - ta1_y_zzzz_xxzzz_1[i] * pc_y[i];

        ta1_y_yzzzz_xyyyy_0[i] = 3.0 * ta1_y_yzz_xyyyy_0[i] * fe_0 - 3.0 * ta1_y_yzz_xyyyy_1[i] * fe_0 + ta1_y_yzzz_xyyyy_0[i] * pa_z[i] - ta1_y_yzzz_xyyyy_1[i] * pc_z[i];

        ta1_y_yzzzz_xyyyz_0[i] = 3.0 * ta1_y_zzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xyyz_1[i] * fe_0 + ta_zzzz_xyyyz_1[i] + ta1_y_zzzz_xyyyz_0[i] * pa_y[i] - ta1_y_zzzz_xyyyz_1[i] * pc_y[i];

        ta1_y_yzzzz_xyyzz_0[i] = 2.0 * ta1_y_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xyzz_1[i] * fe_0 + ta_zzzz_xyyzz_1[i] + ta1_y_zzzz_xyyzz_0[i] * pa_y[i] - ta1_y_zzzz_xyyzz_1[i] * pc_y[i];

        ta1_y_yzzzz_xyzzz_0[i] = ta1_y_zzzz_xzzz_0[i] * fe_0 - ta1_y_zzzz_xzzz_1[i] * fe_0 + ta_zzzz_xyzzz_1[i] + ta1_y_zzzz_xyzzz_0[i] * pa_y[i] - ta1_y_zzzz_xyzzz_1[i] * pc_y[i];

        ta1_y_yzzzz_xzzzz_0[i] = ta_zzzz_xzzzz_1[i] + ta1_y_zzzz_xzzzz_0[i] * pa_y[i] - ta1_y_zzzz_xzzzz_1[i] * pc_y[i];

        ta1_y_yzzzz_yyyyy_0[i] = 3.0 * ta1_y_yzz_yyyyy_0[i] * fe_0 - 3.0 * ta1_y_yzz_yyyyy_1[i] * fe_0 + ta1_y_yzzz_yyyyy_0[i] * pa_z[i] - ta1_y_yzzz_yyyyy_1[i] * pc_z[i];

        ta1_y_yzzzz_yyyyz_0[i] = 4.0 * ta1_y_zzzz_yyyz_0[i] * fe_0 - 4.0 * ta1_y_zzzz_yyyz_1[i] * fe_0 + ta_zzzz_yyyyz_1[i] + ta1_y_zzzz_yyyyz_0[i] * pa_y[i] - ta1_y_zzzz_yyyyz_1[i] * pc_y[i];

        ta1_y_yzzzz_yyyzz_0[i] = 3.0 * ta1_y_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_yyzz_1[i] * fe_0 + ta_zzzz_yyyzz_1[i] + ta1_y_zzzz_yyyzz_0[i] * pa_y[i] - ta1_y_zzzz_yyyzz_1[i] * pc_y[i];

        ta1_y_yzzzz_yyzzz_0[i] = 2.0 * ta1_y_zzzz_yzzz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_yzzz_1[i] * fe_0 + ta_zzzz_yyzzz_1[i] + ta1_y_zzzz_yyzzz_0[i] * pa_y[i] - ta1_y_zzzz_yyzzz_1[i] * pc_y[i];

        ta1_y_yzzzz_yzzzz_0[i] = ta1_y_zzzz_zzzz_0[i] * fe_0 - ta1_y_zzzz_zzzz_1[i] * fe_0 + ta_zzzz_yzzzz_1[i] + ta1_y_zzzz_yzzzz_0[i] * pa_y[i] - ta1_y_zzzz_yzzzz_1[i] * pc_y[i];

        ta1_y_yzzzz_zzzzz_0[i] = ta_zzzz_zzzzz_1[i] + ta1_y_zzzz_zzzzz_0[i] * pa_y[i] - ta1_y_zzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 861-882 components of targeted buffer : HH

    auto ta1_y_zzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 861);

    auto ta1_y_zzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 862);

    auto ta1_y_zzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 863);

    auto ta1_y_zzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 864);

    auto ta1_y_zzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 865);

    auto ta1_y_zzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 866);

    auto ta1_y_zzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 867);

    auto ta1_y_zzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 868);

    auto ta1_y_zzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 869);

    auto ta1_y_zzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 870);

    auto ta1_y_zzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 871);

    auto ta1_y_zzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 872);

    auto ta1_y_zzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 873);

    auto ta1_y_zzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 874);

    auto ta1_y_zzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 875);

    auto ta1_y_zzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 876);

    auto ta1_y_zzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 877);

    auto ta1_y_zzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 878);

    auto ta1_y_zzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 879);

    auto ta1_y_zzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 880);

    auto ta1_y_zzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 881);

    #pragma omp simd aligned(pa_z, pc_z, ta1_y_zzz_xxxxx_0, ta1_y_zzz_xxxxx_1, ta1_y_zzz_xxxxy_0, ta1_y_zzz_xxxxy_1, ta1_y_zzz_xxxxz_0, ta1_y_zzz_xxxxz_1, ta1_y_zzz_xxxyy_0, ta1_y_zzz_xxxyy_1, ta1_y_zzz_xxxyz_0, ta1_y_zzz_xxxyz_1, ta1_y_zzz_xxxzz_0, ta1_y_zzz_xxxzz_1, ta1_y_zzz_xxyyy_0, ta1_y_zzz_xxyyy_1, ta1_y_zzz_xxyyz_0, ta1_y_zzz_xxyyz_1, ta1_y_zzz_xxyzz_0, ta1_y_zzz_xxyzz_1, ta1_y_zzz_xxzzz_0, ta1_y_zzz_xxzzz_1, ta1_y_zzz_xyyyy_0, ta1_y_zzz_xyyyy_1, ta1_y_zzz_xyyyz_0, ta1_y_zzz_xyyyz_1, ta1_y_zzz_xyyzz_0, ta1_y_zzz_xyyzz_1, ta1_y_zzz_xyzzz_0, ta1_y_zzz_xyzzz_1, ta1_y_zzz_xzzzz_0, ta1_y_zzz_xzzzz_1, ta1_y_zzz_yyyyy_0, ta1_y_zzz_yyyyy_1, ta1_y_zzz_yyyyz_0, ta1_y_zzz_yyyyz_1, ta1_y_zzz_yyyzz_0, ta1_y_zzz_yyyzz_1, ta1_y_zzz_yyzzz_0, ta1_y_zzz_yyzzz_1, ta1_y_zzz_yzzzz_0, ta1_y_zzz_yzzzz_1, ta1_y_zzz_zzzzz_0, ta1_y_zzz_zzzzz_1, ta1_y_zzzz_xxxx_0, ta1_y_zzzz_xxxx_1, ta1_y_zzzz_xxxxx_0, ta1_y_zzzz_xxxxx_1, ta1_y_zzzz_xxxxy_0, ta1_y_zzzz_xxxxy_1, ta1_y_zzzz_xxxxz_0, ta1_y_zzzz_xxxxz_1, ta1_y_zzzz_xxxy_0, ta1_y_zzzz_xxxy_1, ta1_y_zzzz_xxxyy_0, ta1_y_zzzz_xxxyy_1, ta1_y_zzzz_xxxyz_0, ta1_y_zzzz_xxxyz_1, ta1_y_zzzz_xxxz_0, ta1_y_zzzz_xxxz_1, ta1_y_zzzz_xxxzz_0, ta1_y_zzzz_xxxzz_1, ta1_y_zzzz_xxyy_0, ta1_y_zzzz_xxyy_1, ta1_y_zzzz_xxyyy_0, ta1_y_zzzz_xxyyy_1, ta1_y_zzzz_xxyyz_0, ta1_y_zzzz_xxyyz_1, ta1_y_zzzz_xxyz_0, ta1_y_zzzz_xxyz_1, ta1_y_zzzz_xxyzz_0, ta1_y_zzzz_xxyzz_1, ta1_y_zzzz_xxzz_0, ta1_y_zzzz_xxzz_1, ta1_y_zzzz_xxzzz_0, ta1_y_zzzz_xxzzz_1, ta1_y_zzzz_xyyy_0, ta1_y_zzzz_xyyy_1, ta1_y_zzzz_xyyyy_0, ta1_y_zzzz_xyyyy_1, ta1_y_zzzz_xyyyz_0, ta1_y_zzzz_xyyyz_1, ta1_y_zzzz_xyyz_0, ta1_y_zzzz_xyyz_1, ta1_y_zzzz_xyyzz_0, ta1_y_zzzz_xyyzz_1, ta1_y_zzzz_xyzz_0, ta1_y_zzzz_xyzz_1, ta1_y_zzzz_xyzzz_0, ta1_y_zzzz_xyzzz_1, ta1_y_zzzz_xzzz_0, ta1_y_zzzz_xzzz_1, ta1_y_zzzz_xzzzz_0, ta1_y_zzzz_xzzzz_1, ta1_y_zzzz_yyyy_0, ta1_y_zzzz_yyyy_1, ta1_y_zzzz_yyyyy_0, ta1_y_zzzz_yyyyy_1, ta1_y_zzzz_yyyyz_0, ta1_y_zzzz_yyyyz_1, ta1_y_zzzz_yyyz_0, ta1_y_zzzz_yyyz_1, ta1_y_zzzz_yyyzz_0, ta1_y_zzzz_yyyzz_1, ta1_y_zzzz_yyzz_0, ta1_y_zzzz_yyzz_1, ta1_y_zzzz_yyzzz_0, ta1_y_zzzz_yyzzz_1, ta1_y_zzzz_yzzz_0, ta1_y_zzzz_yzzz_1, ta1_y_zzzz_yzzzz_0, ta1_y_zzzz_yzzzz_1, ta1_y_zzzz_zzzz_0, ta1_y_zzzz_zzzz_1, ta1_y_zzzz_zzzzz_0, ta1_y_zzzz_zzzzz_1, ta1_y_zzzzz_xxxxx_0, ta1_y_zzzzz_xxxxy_0, ta1_y_zzzzz_xxxxz_0, ta1_y_zzzzz_xxxyy_0, ta1_y_zzzzz_xxxyz_0, ta1_y_zzzzz_xxxzz_0, ta1_y_zzzzz_xxyyy_0, ta1_y_zzzzz_xxyyz_0, ta1_y_zzzzz_xxyzz_0, ta1_y_zzzzz_xxzzz_0, ta1_y_zzzzz_xyyyy_0, ta1_y_zzzzz_xyyyz_0, ta1_y_zzzzz_xyyzz_0, ta1_y_zzzzz_xyzzz_0, ta1_y_zzzzz_xzzzz_0, ta1_y_zzzzz_yyyyy_0, ta1_y_zzzzz_yyyyz_0, ta1_y_zzzzz_yyyzz_0, ta1_y_zzzzz_yyzzz_0, ta1_y_zzzzz_yzzzz_0, ta1_y_zzzzz_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_y_zzzzz_xxxxx_0[i] = 4.0 * ta1_y_zzz_xxxxx_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxxx_1[i] * fe_0 + ta1_y_zzzz_xxxxx_0[i] * pa_z[i] - ta1_y_zzzz_xxxxx_1[i] * pc_z[i];

        ta1_y_zzzzz_xxxxy_0[i] = 4.0 * ta1_y_zzz_xxxxy_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxxy_1[i] * fe_0 + ta1_y_zzzz_xxxxy_0[i] * pa_z[i] - ta1_y_zzzz_xxxxy_1[i] * pc_z[i];

        ta1_y_zzzzz_xxxxz_0[i] = 4.0 * ta1_y_zzz_xxxxz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxxz_1[i] * fe_0 + ta1_y_zzzz_xxxx_0[i] * fe_0 - ta1_y_zzzz_xxxx_1[i] * fe_0 + ta1_y_zzzz_xxxxz_0[i] * pa_z[i] - ta1_y_zzzz_xxxxz_1[i] * pc_z[i];

        ta1_y_zzzzz_xxxyy_0[i] = 4.0 * ta1_y_zzz_xxxyy_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxyy_1[i] * fe_0 + ta1_y_zzzz_xxxyy_0[i] * pa_z[i] - ta1_y_zzzz_xxxyy_1[i] * pc_z[i];

        ta1_y_zzzzz_xxxyz_0[i] = 4.0 * ta1_y_zzz_xxxyz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxyz_1[i] * fe_0 + ta1_y_zzzz_xxxy_0[i] * fe_0 - ta1_y_zzzz_xxxy_1[i] * fe_0 + ta1_y_zzzz_xxxyz_0[i] * pa_z[i] - ta1_y_zzzz_xxxyz_1[i] * pc_z[i];

        ta1_y_zzzzz_xxxzz_0[i] = 4.0 * ta1_y_zzz_xxxzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxxzz_1[i] * fe_0 + 2.0 * ta1_y_zzzz_xxxz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xxxz_1[i] * fe_0 + ta1_y_zzzz_xxxzz_0[i] * pa_z[i] - ta1_y_zzzz_xxxzz_1[i] * pc_z[i];

        ta1_y_zzzzz_xxyyy_0[i] = 4.0 * ta1_y_zzz_xxyyy_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxyyy_1[i] * fe_0 + ta1_y_zzzz_xxyyy_0[i] * pa_z[i] - ta1_y_zzzz_xxyyy_1[i] * pc_z[i];

        ta1_y_zzzzz_xxyyz_0[i] = 4.0 * ta1_y_zzz_xxyyz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxyyz_1[i] * fe_0 + ta1_y_zzzz_xxyy_0[i] * fe_0 - ta1_y_zzzz_xxyy_1[i] * fe_0 + ta1_y_zzzz_xxyyz_0[i] * pa_z[i] - ta1_y_zzzz_xxyyz_1[i] * pc_z[i];

        ta1_y_zzzzz_xxyzz_0[i] = 4.0 * ta1_y_zzz_xxyzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_y_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xxyz_1[i] * fe_0 + ta1_y_zzzz_xxyzz_0[i] * pa_z[i] - ta1_y_zzzz_xxyzz_1[i] * pc_z[i];

        ta1_y_zzzzz_xxzzz_0[i] = 4.0 * ta1_y_zzz_xxzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xxzzz_1[i] * fe_0 + 3.0 * ta1_y_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xxzz_1[i] * fe_0 + ta1_y_zzzz_xxzzz_0[i] * pa_z[i] - ta1_y_zzzz_xxzzz_1[i] * pc_z[i];

        ta1_y_zzzzz_xyyyy_0[i] = 4.0 * ta1_y_zzz_xyyyy_0[i] * fe_0 - 4.0 * ta1_y_zzz_xyyyy_1[i] * fe_0 + ta1_y_zzzz_xyyyy_0[i] * pa_z[i] - ta1_y_zzzz_xyyyy_1[i] * pc_z[i];

        ta1_y_zzzzz_xyyyz_0[i] = 4.0 * ta1_y_zzz_xyyyz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xyyyz_1[i] * fe_0 + ta1_y_zzzz_xyyy_0[i] * fe_0 - ta1_y_zzzz_xyyy_1[i] * fe_0 + ta1_y_zzzz_xyyyz_0[i] * pa_z[i] - ta1_y_zzzz_xyyyz_1[i] * pc_z[i];

        ta1_y_zzzzz_xyyzz_0[i] = 4.0 * ta1_y_zzz_xyyzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_y_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_xyyz_1[i] * fe_0 + ta1_y_zzzz_xyyzz_0[i] * pa_z[i] - ta1_y_zzzz_xyyzz_1[i] * pc_z[i];

        ta1_y_zzzzz_xyzzz_0[i] = 4.0 * ta1_y_zzz_xyzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xyzzz_1[i] * fe_0 + 3.0 * ta1_y_zzzz_xyzz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_xyzz_1[i] * fe_0 + ta1_y_zzzz_xyzzz_0[i] * pa_z[i] - ta1_y_zzzz_xyzzz_1[i] * pc_z[i];

        ta1_y_zzzzz_xzzzz_0[i] = 4.0 * ta1_y_zzz_xzzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_xzzzz_1[i] * fe_0 + 4.0 * ta1_y_zzzz_xzzz_0[i] * fe_0 - 4.0 * ta1_y_zzzz_xzzz_1[i] * fe_0 + ta1_y_zzzz_xzzzz_0[i] * pa_z[i] - ta1_y_zzzz_xzzzz_1[i] * pc_z[i];

        ta1_y_zzzzz_yyyyy_0[i] = 4.0 * ta1_y_zzz_yyyyy_0[i] * fe_0 - 4.0 * ta1_y_zzz_yyyyy_1[i] * fe_0 + ta1_y_zzzz_yyyyy_0[i] * pa_z[i] - ta1_y_zzzz_yyyyy_1[i] * pc_z[i];

        ta1_y_zzzzz_yyyyz_0[i] = 4.0 * ta1_y_zzz_yyyyz_0[i] * fe_0 - 4.0 * ta1_y_zzz_yyyyz_1[i] * fe_0 + ta1_y_zzzz_yyyy_0[i] * fe_0 - ta1_y_zzzz_yyyy_1[i] * fe_0 + ta1_y_zzzz_yyyyz_0[i] * pa_z[i] - ta1_y_zzzz_yyyyz_1[i] * pc_z[i];

        ta1_y_zzzzz_yyyzz_0[i] = 4.0 * ta1_y_zzz_yyyzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_yyyzz_1[i] * fe_0 + 2.0 * ta1_y_zzzz_yyyz_0[i] * fe_0 - 2.0 * ta1_y_zzzz_yyyz_1[i] * fe_0 + ta1_y_zzzz_yyyzz_0[i] * pa_z[i] - ta1_y_zzzz_yyyzz_1[i] * pc_z[i];

        ta1_y_zzzzz_yyzzz_0[i] = 4.0 * ta1_y_zzz_yyzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_yyzzz_1[i] * fe_0 + 3.0 * ta1_y_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_y_zzzz_yyzz_1[i] * fe_0 + ta1_y_zzzz_yyzzz_0[i] * pa_z[i] - ta1_y_zzzz_yyzzz_1[i] * pc_z[i];

        ta1_y_zzzzz_yzzzz_0[i] = 4.0 * ta1_y_zzz_yzzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_yzzzz_1[i] * fe_0 + 4.0 * ta1_y_zzzz_yzzz_0[i] * fe_0 - 4.0 * ta1_y_zzzz_yzzz_1[i] * fe_0 + ta1_y_zzzz_yzzzz_0[i] * pa_z[i] - ta1_y_zzzz_yzzzz_1[i] * pc_z[i];

        ta1_y_zzzzz_zzzzz_0[i] = 4.0 * ta1_y_zzz_zzzzz_0[i] * fe_0 - 4.0 * ta1_y_zzz_zzzzz_1[i] * fe_0 + 5.0 * ta1_y_zzzz_zzzz_0[i] * fe_0 - 5.0 * ta1_y_zzzz_zzzz_1[i] * fe_0 + ta1_y_zzzz_zzzzz_0[i] * pa_z[i] - ta1_y_zzzz_zzzzz_1[i] * pc_z[i];
    }

    // Set up 882-903 components of targeted buffer : HH

    auto ta1_z_xxxxx_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 882);

    auto ta1_z_xxxxx_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 883);

    auto ta1_z_xxxxx_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 884);

    auto ta1_z_xxxxx_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 885);

    auto ta1_z_xxxxx_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 886);

    auto ta1_z_xxxxx_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 887);

    auto ta1_z_xxxxx_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 888);

    auto ta1_z_xxxxx_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 889);

    auto ta1_z_xxxxx_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 890);

    auto ta1_z_xxxxx_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 891);

    auto ta1_z_xxxxx_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 892);

    auto ta1_z_xxxxx_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 893);

    auto ta1_z_xxxxx_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 894);

    auto ta1_z_xxxxx_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 895);

    auto ta1_z_xxxxx_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 896);

    auto ta1_z_xxxxx_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 897);

    auto ta1_z_xxxxx_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 898);

    auto ta1_z_xxxxx_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 899);

    auto ta1_z_xxxxx_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 900);

    auto ta1_z_xxxxx_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 901);

    auto ta1_z_xxxxx_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 902);

    #pragma omp simd aligned(pa_x, pc_x, ta1_z_xxx_xxxxx_0, ta1_z_xxx_xxxxx_1, ta1_z_xxx_xxxxy_0, ta1_z_xxx_xxxxy_1, ta1_z_xxx_xxxxz_0, ta1_z_xxx_xxxxz_1, ta1_z_xxx_xxxyy_0, ta1_z_xxx_xxxyy_1, ta1_z_xxx_xxxyz_0, ta1_z_xxx_xxxyz_1, ta1_z_xxx_xxxzz_0, ta1_z_xxx_xxxzz_1, ta1_z_xxx_xxyyy_0, ta1_z_xxx_xxyyy_1, ta1_z_xxx_xxyyz_0, ta1_z_xxx_xxyyz_1, ta1_z_xxx_xxyzz_0, ta1_z_xxx_xxyzz_1, ta1_z_xxx_xxzzz_0, ta1_z_xxx_xxzzz_1, ta1_z_xxx_xyyyy_0, ta1_z_xxx_xyyyy_1, ta1_z_xxx_xyyyz_0, ta1_z_xxx_xyyyz_1, ta1_z_xxx_xyyzz_0, ta1_z_xxx_xyyzz_1, ta1_z_xxx_xyzzz_0, ta1_z_xxx_xyzzz_1, ta1_z_xxx_xzzzz_0, ta1_z_xxx_xzzzz_1, ta1_z_xxx_yyyyy_0, ta1_z_xxx_yyyyy_1, ta1_z_xxx_yyyyz_0, ta1_z_xxx_yyyyz_1, ta1_z_xxx_yyyzz_0, ta1_z_xxx_yyyzz_1, ta1_z_xxx_yyzzz_0, ta1_z_xxx_yyzzz_1, ta1_z_xxx_yzzzz_0, ta1_z_xxx_yzzzz_1, ta1_z_xxx_zzzzz_0, ta1_z_xxx_zzzzz_1, ta1_z_xxxx_xxxx_0, ta1_z_xxxx_xxxx_1, ta1_z_xxxx_xxxxx_0, ta1_z_xxxx_xxxxx_1, ta1_z_xxxx_xxxxy_0, ta1_z_xxxx_xxxxy_1, ta1_z_xxxx_xxxxz_0, ta1_z_xxxx_xxxxz_1, ta1_z_xxxx_xxxy_0, ta1_z_xxxx_xxxy_1, ta1_z_xxxx_xxxyy_0, ta1_z_xxxx_xxxyy_1, ta1_z_xxxx_xxxyz_0, ta1_z_xxxx_xxxyz_1, ta1_z_xxxx_xxxz_0, ta1_z_xxxx_xxxz_1, ta1_z_xxxx_xxxzz_0, ta1_z_xxxx_xxxzz_1, ta1_z_xxxx_xxyy_0, ta1_z_xxxx_xxyy_1, ta1_z_xxxx_xxyyy_0, ta1_z_xxxx_xxyyy_1, ta1_z_xxxx_xxyyz_0, ta1_z_xxxx_xxyyz_1, ta1_z_xxxx_xxyz_0, ta1_z_xxxx_xxyz_1, ta1_z_xxxx_xxyzz_0, ta1_z_xxxx_xxyzz_1, ta1_z_xxxx_xxzz_0, ta1_z_xxxx_xxzz_1, ta1_z_xxxx_xxzzz_0, ta1_z_xxxx_xxzzz_1, ta1_z_xxxx_xyyy_0, ta1_z_xxxx_xyyy_1, ta1_z_xxxx_xyyyy_0, ta1_z_xxxx_xyyyy_1, ta1_z_xxxx_xyyyz_0, ta1_z_xxxx_xyyyz_1, ta1_z_xxxx_xyyz_0, ta1_z_xxxx_xyyz_1, ta1_z_xxxx_xyyzz_0, ta1_z_xxxx_xyyzz_1, ta1_z_xxxx_xyzz_0, ta1_z_xxxx_xyzz_1, ta1_z_xxxx_xyzzz_0, ta1_z_xxxx_xyzzz_1, ta1_z_xxxx_xzzz_0, ta1_z_xxxx_xzzz_1, ta1_z_xxxx_xzzzz_0, ta1_z_xxxx_xzzzz_1, ta1_z_xxxx_yyyy_0, ta1_z_xxxx_yyyy_1, ta1_z_xxxx_yyyyy_0, ta1_z_xxxx_yyyyy_1, ta1_z_xxxx_yyyyz_0, ta1_z_xxxx_yyyyz_1, ta1_z_xxxx_yyyz_0, ta1_z_xxxx_yyyz_1, ta1_z_xxxx_yyyzz_0, ta1_z_xxxx_yyyzz_1, ta1_z_xxxx_yyzz_0, ta1_z_xxxx_yyzz_1, ta1_z_xxxx_yyzzz_0, ta1_z_xxxx_yyzzz_1, ta1_z_xxxx_yzzz_0, ta1_z_xxxx_yzzz_1, ta1_z_xxxx_yzzzz_0, ta1_z_xxxx_yzzzz_1, ta1_z_xxxx_zzzz_0, ta1_z_xxxx_zzzz_1, ta1_z_xxxx_zzzzz_0, ta1_z_xxxx_zzzzz_1, ta1_z_xxxxx_xxxxx_0, ta1_z_xxxxx_xxxxy_0, ta1_z_xxxxx_xxxxz_0, ta1_z_xxxxx_xxxyy_0, ta1_z_xxxxx_xxxyz_0, ta1_z_xxxxx_xxxzz_0, ta1_z_xxxxx_xxyyy_0, ta1_z_xxxxx_xxyyz_0, ta1_z_xxxxx_xxyzz_0, ta1_z_xxxxx_xxzzz_0, ta1_z_xxxxx_xyyyy_0, ta1_z_xxxxx_xyyyz_0, ta1_z_xxxxx_xyyzz_0, ta1_z_xxxxx_xyzzz_0, ta1_z_xxxxx_xzzzz_0, ta1_z_xxxxx_yyyyy_0, ta1_z_xxxxx_yyyyz_0, ta1_z_xxxxx_yyyzz_0, ta1_z_xxxxx_yyzzz_0, ta1_z_xxxxx_yzzzz_0, ta1_z_xxxxx_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxxx_xxxxx_0[i] = 4.0 * ta1_z_xxx_xxxxx_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxxx_1[i] * fe_0 + 5.0 * ta1_z_xxxx_xxxx_0[i] * fe_0 - 5.0 * ta1_z_xxxx_xxxx_1[i] * fe_0 + ta1_z_xxxx_xxxxx_0[i] * pa_x[i] - ta1_z_xxxx_xxxxx_1[i] * pc_x[i];

        ta1_z_xxxxx_xxxxy_0[i] = 4.0 * ta1_z_xxx_xxxxy_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxxy_1[i] * fe_0 + 4.0 * ta1_z_xxxx_xxxy_0[i] * fe_0 - 4.0 * ta1_z_xxxx_xxxy_1[i] * fe_0 + ta1_z_xxxx_xxxxy_0[i] * pa_x[i] - ta1_z_xxxx_xxxxy_1[i] * pc_x[i];

        ta1_z_xxxxx_xxxxz_0[i] = 4.0 * ta1_z_xxx_xxxxz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxxz_1[i] * fe_0 + 4.0 * ta1_z_xxxx_xxxz_0[i] * fe_0 - 4.0 * ta1_z_xxxx_xxxz_1[i] * fe_0 + ta1_z_xxxx_xxxxz_0[i] * pa_x[i] - ta1_z_xxxx_xxxxz_1[i] * pc_x[i];

        ta1_z_xxxxx_xxxyy_0[i] = 4.0 * ta1_z_xxx_xxxyy_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxyy_1[i] * fe_0 + 3.0 * ta1_z_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xxyy_1[i] * fe_0 + ta1_z_xxxx_xxxyy_0[i] * pa_x[i] - ta1_z_xxxx_xxxyy_1[i] * pc_x[i];

        ta1_z_xxxxx_xxxyz_0[i] = 4.0 * ta1_z_xxx_xxxyz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxyz_1[i] * fe_0 + 3.0 * ta1_z_xxxx_xxyz_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xxyz_1[i] * fe_0 + ta1_z_xxxx_xxxyz_0[i] * pa_x[i] - ta1_z_xxxx_xxxyz_1[i] * pc_x[i];

        ta1_z_xxxxx_xxxzz_0[i] = 4.0 * ta1_z_xxx_xxxzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxxzz_1[i] * fe_0 + 3.0 * ta1_z_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xxzz_1[i] * fe_0 + ta1_z_xxxx_xxxzz_0[i] * pa_x[i] - ta1_z_xxxx_xxxzz_1[i] * pc_x[i];

        ta1_z_xxxxx_xxyyy_0[i] = 4.0 * ta1_z_xxx_xxyyy_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxyyy_1[i] * fe_0 + 2.0 * ta1_z_xxxx_xyyy_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xyyy_1[i] * fe_0 + ta1_z_xxxx_xxyyy_0[i] * pa_x[i] - ta1_z_xxxx_xxyyy_1[i] * pc_x[i];

        ta1_z_xxxxx_xxyyz_0[i] = 4.0 * ta1_z_xxx_xxyyz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xyyz_1[i] * fe_0 + ta1_z_xxxx_xxyyz_0[i] * pa_x[i] - ta1_z_xxxx_xxyyz_1[i] * pc_x[i];

        ta1_z_xxxxx_xxyzz_0[i] = 4.0 * ta1_z_xxx_xxyzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xyzz_1[i] * fe_0 + ta1_z_xxxx_xxyzz_0[i] * pa_x[i] - ta1_z_xxxx_xxyzz_1[i] * pc_x[i];

        ta1_z_xxxxx_xxzzz_0[i] = 4.0 * ta1_z_xxx_xxzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xxzzz_1[i] * fe_0 + 2.0 * ta1_z_xxxx_xzzz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xzzz_1[i] * fe_0 + ta1_z_xxxx_xxzzz_0[i] * pa_x[i] - ta1_z_xxxx_xxzzz_1[i] * pc_x[i];

        ta1_z_xxxxx_xyyyy_0[i] = 4.0 * ta1_z_xxx_xyyyy_0[i] * fe_0 - 4.0 * ta1_z_xxx_xyyyy_1[i] * fe_0 + ta1_z_xxxx_yyyy_0[i] * fe_0 - ta1_z_xxxx_yyyy_1[i] * fe_0 + ta1_z_xxxx_xyyyy_0[i] * pa_x[i] - ta1_z_xxxx_xyyyy_1[i] * pc_x[i];

        ta1_z_xxxxx_xyyyz_0[i] = 4.0 * ta1_z_xxx_xyyyz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xyyyz_1[i] * fe_0 + ta1_z_xxxx_yyyz_0[i] * fe_0 - ta1_z_xxxx_yyyz_1[i] * fe_0 + ta1_z_xxxx_xyyyz_0[i] * pa_x[i] - ta1_z_xxxx_xyyyz_1[i] * pc_x[i];

        ta1_z_xxxxx_xyyzz_0[i] = 4.0 * ta1_z_xxx_xyyzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xyyzz_1[i] * fe_0 + ta1_z_xxxx_yyzz_0[i] * fe_0 - ta1_z_xxxx_yyzz_1[i] * fe_0 + ta1_z_xxxx_xyyzz_0[i] * pa_x[i] - ta1_z_xxxx_xyyzz_1[i] * pc_x[i];

        ta1_z_xxxxx_xyzzz_0[i] = 4.0 * ta1_z_xxx_xyzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xyzzz_1[i] * fe_0 + ta1_z_xxxx_yzzz_0[i] * fe_0 - ta1_z_xxxx_yzzz_1[i] * fe_0 + ta1_z_xxxx_xyzzz_0[i] * pa_x[i] - ta1_z_xxxx_xyzzz_1[i] * pc_x[i];

        ta1_z_xxxxx_xzzzz_0[i] = 4.0 * ta1_z_xxx_xzzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_xzzzz_1[i] * fe_0 + ta1_z_xxxx_zzzz_0[i] * fe_0 - ta1_z_xxxx_zzzz_1[i] * fe_0 + ta1_z_xxxx_xzzzz_0[i] * pa_x[i] - ta1_z_xxxx_xzzzz_1[i] * pc_x[i];

        ta1_z_xxxxx_yyyyy_0[i] = 4.0 * ta1_z_xxx_yyyyy_0[i] * fe_0 - 4.0 * ta1_z_xxx_yyyyy_1[i] * fe_0 + ta1_z_xxxx_yyyyy_0[i] * pa_x[i] - ta1_z_xxxx_yyyyy_1[i] * pc_x[i];

        ta1_z_xxxxx_yyyyz_0[i] = 4.0 * ta1_z_xxx_yyyyz_0[i] * fe_0 - 4.0 * ta1_z_xxx_yyyyz_1[i] * fe_0 + ta1_z_xxxx_yyyyz_0[i] * pa_x[i] - ta1_z_xxxx_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxxx_yyyzz_0[i] = 4.0 * ta1_z_xxx_yyyzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_yyyzz_1[i] * fe_0 + ta1_z_xxxx_yyyzz_0[i] * pa_x[i] - ta1_z_xxxx_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxxx_yyzzz_0[i] = 4.0 * ta1_z_xxx_yyzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_yyzzz_1[i] * fe_0 + ta1_z_xxxx_yyzzz_0[i] * pa_x[i] - ta1_z_xxxx_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxxx_yzzzz_0[i] = 4.0 * ta1_z_xxx_yzzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_yzzzz_1[i] * fe_0 + ta1_z_xxxx_yzzzz_0[i] * pa_x[i] - ta1_z_xxxx_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxxx_zzzzz_0[i] = 4.0 * ta1_z_xxx_zzzzz_0[i] * fe_0 - 4.0 * ta1_z_xxx_zzzzz_1[i] * fe_0 + ta1_z_xxxx_zzzzz_0[i] * pa_x[i] - ta1_z_xxxx_zzzzz_1[i] * pc_x[i];
    }

    // Set up 903-924 components of targeted buffer : HH

    auto ta1_z_xxxxy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 903);

    auto ta1_z_xxxxy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 904);

    auto ta1_z_xxxxy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 905);

    auto ta1_z_xxxxy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 906);

    auto ta1_z_xxxxy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 907);

    auto ta1_z_xxxxy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 908);

    auto ta1_z_xxxxy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 909);

    auto ta1_z_xxxxy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 910);

    auto ta1_z_xxxxy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 911);

    auto ta1_z_xxxxy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 912);

    auto ta1_z_xxxxy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 913);

    auto ta1_z_xxxxy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 914);

    auto ta1_z_xxxxy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 915);

    auto ta1_z_xxxxy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 916);

    auto ta1_z_xxxxy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 917);

    auto ta1_z_xxxxy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 918);

    auto ta1_z_xxxxy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 919);

    auto ta1_z_xxxxy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 920);

    auto ta1_z_xxxxy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 921);

    auto ta1_z_xxxxy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 922);

    auto ta1_z_xxxxy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 923);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_z_xxxx_xxxx_0, ta1_z_xxxx_xxxx_1, ta1_z_xxxx_xxxxx_0, ta1_z_xxxx_xxxxx_1, ta1_z_xxxx_xxxxy_0, ta1_z_xxxx_xxxxy_1, ta1_z_xxxx_xxxxz_0, ta1_z_xxxx_xxxxz_1, ta1_z_xxxx_xxxy_0, ta1_z_xxxx_xxxy_1, ta1_z_xxxx_xxxyy_0, ta1_z_xxxx_xxxyy_1, ta1_z_xxxx_xxxyz_0, ta1_z_xxxx_xxxyz_1, ta1_z_xxxx_xxxz_0, ta1_z_xxxx_xxxz_1, ta1_z_xxxx_xxxzz_0, ta1_z_xxxx_xxxzz_1, ta1_z_xxxx_xxyy_0, ta1_z_xxxx_xxyy_1, ta1_z_xxxx_xxyyy_0, ta1_z_xxxx_xxyyy_1, ta1_z_xxxx_xxyyz_0, ta1_z_xxxx_xxyyz_1, ta1_z_xxxx_xxyz_0, ta1_z_xxxx_xxyz_1, ta1_z_xxxx_xxyzz_0, ta1_z_xxxx_xxyzz_1, ta1_z_xxxx_xxzz_0, ta1_z_xxxx_xxzz_1, ta1_z_xxxx_xxzzz_0, ta1_z_xxxx_xxzzz_1, ta1_z_xxxx_xyyy_0, ta1_z_xxxx_xyyy_1, ta1_z_xxxx_xyyyy_0, ta1_z_xxxx_xyyyy_1, ta1_z_xxxx_xyyyz_0, ta1_z_xxxx_xyyyz_1, ta1_z_xxxx_xyyz_0, ta1_z_xxxx_xyyz_1, ta1_z_xxxx_xyyzz_0, ta1_z_xxxx_xyyzz_1, ta1_z_xxxx_xyzz_0, ta1_z_xxxx_xyzz_1, ta1_z_xxxx_xyzzz_0, ta1_z_xxxx_xyzzz_1, ta1_z_xxxx_xzzz_0, ta1_z_xxxx_xzzz_1, ta1_z_xxxx_xzzzz_0, ta1_z_xxxx_xzzzz_1, ta1_z_xxxx_zzzzz_0, ta1_z_xxxx_zzzzz_1, ta1_z_xxxxy_xxxxx_0, ta1_z_xxxxy_xxxxy_0, ta1_z_xxxxy_xxxxz_0, ta1_z_xxxxy_xxxyy_0, ta1_z_xxxxy_xxxyz_0, ta1_z_xxxxy_xxxzz_0, ta1_z_xxxxy_xxyyy_0, ta1_z_xxxxy_xxyyz_0, ta1_z_xxxxy_xxyzz_0, ta1_z_xxxxy_xxzzz_0, ta1_z_xxxxy_xyyyy_0, ta1_z_xxxxy_xyyyz_0, ta1_z_xxxxy_xyyzz_0, ta1_z_xxxxy_xyzzz_0, ta1_z_xxxxy_xzzzz_0, ta1_z_xxxxy_yyyyy_0, ta1_z_xxxxy_yyyyz_0, ta1_z_xxxxy_yyyzz_0, ta1_z_xxxxy_yyzzz_0, ta1_z_xxxxy_yzzzz_0, ta1_z_xxxxy_zzzzz_0, ta1_z_xxxy_yyyyy_0, ta1_z_xxxy_yyyyy_1, ta1_z_xxxy_yyyyz_0, ta1_z_xxxy_yyyyz_1, ta1_z_xxxy_yyyzz_0, ta1_z_xxxy_yyyzz_1, ta1_z_xxxy_yyzzz_0, ta1_z_xxxy_yyzzz_1, ta1_z_xxxy_yzzzz_0, ta1_z_xxxy_yzzzz_1, ta1_z_xxy_yyyyy_0, ta1_z_xxy_yyyyy_1, ta1_z_xxy_yyyyz_0, ta1_z_xxy_yyyyz_1, ta1_z_xxy_yyyzz_0, ta1_z_xxy_yyyzz_1, ta1_z_xxy_yyzzz_0, ta1_z_xxy_yyzzz_1, ta1_z_xxy_yzzzz_0, ta1_z_xxy_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxxy_xxxxx_0[i] = ta1_z_xxxx_xxxxx_0[i] * pa_y[i] - ta1_z_xxxx_xxxxx_1[i] * pc_y[i];

        ta1_z_xxxxy_xxxxy_0[i] = ta1_z_xxxx_xxxx_0[i] * fe_0 - ta1_z_xxxx_xxxx_1[i] * fe_0 + ta1_z_xxxx_xxxxy_0[i] * pa_y[i] - ta1_z_xxxx_xxxxy_1[i] * pc_y[i];

        ta1_z_xxxxy_xxxxz_0[i] = ta1_z_xxxx_xxxxz_0[i] * pa_y[i] - ta1_z_xxxx_xxxxz_1[i] * pc_y[i];

        ta1_z_xxxxy_xxxyy_0[i] = 2.0 * ta1_z_xxxx_xxxy_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xxxy_1[i] * fe_0 + ta1_z_xxxx_xxxyy_0[i] * pa_y[i] - ta1_z_xxxx_xxxyy_1[i] * pc_y[i];

        ta1_z_xxxxy_xxxyz_0[i] = ta1_z_xxxx_xxxz_0[i] * fe_0 - ta1_z_xxxx_xxxz_1[i] * fe_0 + ta1_z_xxxx_xxxyz_0[i] * pa_y[i] - ta1_z_xxxx_xxxyz_1[i] * pc_y[i];

        ta1_z_xxxxy_xxxzz_0[i] = ta1_z_xxxx_xxxzz_0[i] * pa_y[i] - ta1_z_xxxx_xxxzz_1[i] * pc_y[i];

        ta1_z_xxxxy_xxyyy_0[i] = 3.0 * ta1_z_xxxx_xxyy_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xxyy_1[i] * fe_0 + ta1_z_xxxx_xxyyy_0[i] * pa_y[i] - ta1_z_xxxx_xxyyy_1[i] * pc_y[i];

        ta1_z_xxxxy_xxyyz_0[i] = 2.0 * ta1_z_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xxyz_1[i] * fe_0 + ta1_z_xxxx_xxyyz_0[i] * pa_y[i] - ta1_z_xxxx_xxyyz_1[i] * pc_y[i];

        ta1_z_xxxxy_xxyzz_0[i] = ta1_z_xxxx_xxzz_0[i] * fe_0 - ta1_z_xxxx_xxzz_1[i] * fe_0 + ta1_z_xxxx_xxyzz_0[i] * pa_y[i] - ta1_z_xxxx_xxyzz_1[i] * pc_y[i];

        ta1_z_xxxxy_xxzzz_0[i] = ta1_z_xxxx_xxzzz_0[i] * pa_y[i] - ta1_z_xxxx_xxzzz_1[i] * pc_y[i];

        ta1_z_xxxxy_xyyyy_0[i] = 4.0 * ta1_z_xxxx_xyyy_0[i] * fe_0 - 4.0 * ta1_z_xxxx_xyyy_1[i] * fe_0 + ta1_z_xxxx_xyyyy_0[i] * pa_y[i] - ta1_z_xxxx_xyyyy_1[i] * pc_y[i];

        ta1_z_xxxxy_xyyyz_0[i] = 3.0 * ta1_z_xxxx_xyyz_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xyyz_1[i] * fe_0 + ta1_z_xxxx_xyyyz_0[i] * pa_y[i] - ta1_z_xxxx_xyyyz_1[i] * pc_y[i];

        ta1_z_xxxxy_xyyzz_0[i] = 2.0 * ta1_z_xxxx_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xyzz_1[i] * fe_0 + ta1_z_xxxx_xyyzz_0[i] * pa_y[i] - ta1_z_xxxx_xyyzz_1[i] * pc_y[i];

        ta1_z_xxxxy_xyzzz_0[i] = ta1_z_xxxx_xzzz_0[i] * fe_0 - ta1_z_xxxx_xzzz_1[i] * fe_0 + ta1_z_xxxx_xyzzz_0[i] * pa_y[i] - ta1_z_xxxx_xyzzz_1[i] * pc_y[i];

        ta1_z_xxxxy_xzzzz_0[i] = ta1_z_xxxx_xzzzz_0[i] * pa_y[i] - ta1_z_xxxx_xzzzz_1[i] * pc_y[i];

        ta1_z_xxxxy_yyyyy_0[i] = 3.0 * ta1_z_xxy_yyyyy_0[i] * fe_0 - 3.0 * ta1_z_xxy_yyyyy_1[i] * fe_0 + ta1_z_xxxy_yyyyy_0[i] * pa_x[i] - ta1_z_xxxy_yyyyy_1[i] * pc_x[i];

        ta1_z_xxxxy_yyyyz_0[i] = 3.0 * ta1_z_xxy_yyyyz_0[i] * fe_0 - 3.0 * ta1_z_xxy_yyyyz_1[i] * fe_0 + ta1_z_xxxy_yyyyz_0[i] * pa_x[i] - ta1_z_xxxy_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxxy_yyyzz_0[i] = 3.0 * ta1_z_xxy_yyyzz_0[i] * fe_0 - 3.0 * ta1_z_xxy_yyyzz_1[i] * fe_0 + ta1_z_xxxy_yyyzz_0[i] * pa_x[i] - ta1_z_xxxy_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxxy_yyzzz_0[i] = 3.0 * ta1_z_xxy_yyzzz_0[i] * fe_0 - 3.0 * ta1_z_xxy_yyzzz_1[i] * fe_0 + ta1_z_xxxy_yyzzz_0[i] * pa_x[i] - ta1_z_xxxy_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxxy_yzzzz_0[i] = 3.0 * ta1_z_xxy_yzzzz_0[i] * fe_0 - 3.0 * ta1_z_xxy_yzzzz_1[i] * fe_0 + ta1_z_xxxy_yzzzz_0[i] * pa_x[i] - ta1_z_xxxy_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxxy_zzzzz_0[i] = ta1_z_xxxx_zzzzz_0[i] * pa_y[i] - ta1_z_xxxx_zzzzz_1[i] * pc_y[i];
    }

    // Set up 924-945 components of targeted buffer : HH

    auto ta1_z_xxxxz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 924);

    auto ta1_z_xxxxz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 925);

    auto ta1_z_xxxxz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 926);

    auto ta1_z_xxxxz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 927);

    auto ta1_z_xxxxz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 928);

    auto ta1_z_xxxxz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 929);

    auto ta1_z_xxxxz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 930);

    auto ta1_z_xxxxz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 931);

    auto ta1_z_xxxxz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 932);

    auto ta1_z_xxxxz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 933);

    auto ta1_z_xxxxz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 934);

    auto ta1_z_xxxxz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 935);

    auto ta1_z_xxxxz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 936);

    auto ta1_z_xxxxz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 937);

    auto ta1_z_xxxxz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 938);

    auto ta1_z_xxxxz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 939);

    auto ta1_z_xxxxz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 940);

    auto ta1_z_xxxxz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 941);

    auto ta1_z_xxxxz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 942);

    auto ta1_z_xxxxz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 943);

    auto ta1_z_xxxxz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 944);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_z_xxxx_xxxx_0, ta1_z_xxxx_xxxx_1, ta1_z_xxxx_xxxxx_0, ta1_z_xxxx_xxxxx_1, ta1_z_xxxx_xxxxy_0, ta1_z_xxxx_xxxxy_1, ta1_z_xxxx_xxxxz_0, ta1_z_xxxx_xxxxz_1, ta1_z_xxxx_xxxy_0, ta1_z_xxxx_xxxy_1, ta1_z_xxxx_xxxyy_0, ta1_z_xxxx_xxxyy_1, ta1_z_xxxx_xxxyz_0, ta1_z_xxxx_xxxyz_1, ta1_z_xxxx_xxxz_0, ta1_z_xxxx_xxxz_1, ta1_z_xxxx_xxxzz_0, ta1_z_xxxx_xxxzz_1, ta1_z_xxxx_xxyy_0, ta1_z_xxxx_xxyy_1, ta1_z_xxxx_xxyyy_0, ta1_z_xxxx_xxyyy_1, ta1_z_xxxx_xxyyz_0, ta1_z_xxxx_xxyyz_1, ta1_z_xxxx_xxyz_0, ta1_z_xxxx_xxyz_1, ta1_z_xxxx_xxyzz_0, ta1_z_xxxx_xxyzz_1, ta1_z_xxxx_xxzz_0, ta1_z_xxxx_xxzz_1, ta1_z_xxxx_xxzzz_0, ta1_z_xxxx_xxzzz_1, ta1_z_xxxx_xyyy_0, ta1_z_xxxx_xyyy_1, ta1_z_xxxx_xyyyy_0, ta1_z_xxxx_xyyyy_1, ta1_z_xxxx_xyyyz_0, ta1_z_xxxx_xyyyz_1, ta1_z_xxxx_xyyz_0, ta1_z_xxxx_xyyz_1, ta1_z_xxxx_xyyzz_0, ta1_z_xxxx_xyyzz_1, ta1_z_xxxx_xyzz_0, ta1_z_xxxx_xyzz_1, ta1_z_xxxx_xyzzz_0, ta1_z_xxxx_xyzzz_1, ta1_z_xxxx_xzzz_0, ta1_z_xxxx_xzzz_1, ta1_z_xxxx_xzzzz_0, ta1_z_xxxx_xzzzz_1, ta1_z_xxxx_yyyyy_0, ta1_z_xxxx_yyyyy_1, ta1_z_xxxxz_xxxxx_0, ta1_z_xxxxz_xxxxy_0, ta1_z_xxxxz_xxxxz_0, ta1_z_xxxxz_xxxyy_0, ta1_z_xxxxz_xxxyz_0, ta1_z_xxxxz_xxxzz_0, ta1_z_xxxxz_xxyyy_0, ta1_z_xxxxz_xxyyz_0, ta1_z_xxxxz_xxyzz_0, ta1_z_xxxxz_xxzzz_0, ta1_z_xxxxz_xyyyy_0, ta1_z_xxxxz_xyyyz_0, ta1_z_xxxxz_xyyzz_0, ta1_z_xxxxz_xyzzz_0, ta1_z_xxxxz_xzzzz_0, ta1_z_xxxxz_yyyyy_0, ta1_z_xxxxz_yyyyz_0, ta1_z_xxxxz_yyyzz_0, ta1_z_xxxxz_yyzzz_0, ta1_z_xxxxz_yzzzz_0, ta1_z_xxxxz_zzzzz_0, ta1_z_xxxz_yyyyz_0, ta1_z_xxxz_yyyyz_1, ta1_z_xxxz_yyyzz_0, ta1_z_xxxz_yyyzz_1, ta1_z_xxxz_yyzzz_0, ta1_z_xxxz_yyzzz_1, ta1_z_xxxz_yzzzz_0, ta1_z_xxxz_yzzzz_1, ta1_z_xxxz_zzzzz_0, ta1_z_xxxz_zzzzz_1, ta1_z_xxz_yyyyz_0, ta1_z_xxz_yyyyz_1, ta1_z_xxz_yyyzz_0, ta1_z_xxz_yyyzz_1, ta1_z_xxz_yyzzz_0, ta1_z_xxz_yyzzz_1, ta1_z_xxz_yzzzz_0, ta1_z_xxz_yzzzz_1, ta1_z_xxz_zzzzz_0, ta1_z_xxz_zzzzz_1, ta_xxxx_xxxxx_1, ta_xxxx_xxxxy_1, ta_xxxx_xxxxz_1, ta_xxxx_xxxyy_1, ta_xxxx_xxxyz_1, ta_xxxx_xxxzz_1, ta_xxxx_xxyyy_1, ta_xxxx_xxyyz_1, ta_xxxx_xxyzz_1, ta_xxxx_xxzzz_1, ta_xxxx_xyyyy_1, ta_xxxx_xyyyz_1, ta_xxxx_xyyzz_1, ta_xxxx_xyzzz_1, ta_xxxx_xzzzz_1, ta_xxxx_yyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxxz_xxxxx_0[i] = ta_xxxx_xxxxx_1[i] + ta1_z_xxxx_xxxxx_0[i] * pa_z[i] - ta1_z_xxxx_xxxxx_1[i] * pc_z[i];

        ta1_z_xxxxz_xxxxy_0[i] = ta_xxxx_xxxxy_1[i] + ta1_z_xxxx_xxxxy_0[i] * pa_z[i] - ta1_z_xxxx_xxxxy_1[i] * pc_z[i];

        ta1_z_xxxxz_xxxxz_0[i] = ta1_z_xxxx_xxxx_0[i] * fe_0 - ta1_z_xxxx_xxxx_1[i] * fe_0 + ta_xxxx_xxxxz_1[i] + ta1_z_xxxx_xxxxz_0[i] * pa_z[i] - ta1_z_xxxx_xxxxz_1[i] * pc_z[i];

        ta1_z_xxxxz_xxxyy_0[i] = ta_xxxx_xxxyy_1[i] + ta1_z_xxxx_xxxyy_0[i] * pa_z[i] - ta1_z_xxxx_xxxyy_1[i] * pc_z[i];

        ta1_z_xxxxz_xxxyz_0[i] = ta1_z_xxxx_xxxy_0[i] * fe_0 - ta1_z_xxxx_xxxy_1[i] * fe_0 + ta_xxxx_xxxyz_1[i] + ta1_z_xxxx_xxxyz_0[i] * pa_z[i] - ta1_z_xxxx_xxxyz_1[i] * pc_z[i];

        ta1_z_xxxxz_xxxzz_0[i] = 2.0 * ta1_z_xxxx_xxxz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xxxz_1[i] * fe_0 + ta_xxxx_xxxzz_1[i] + ta1_z_xxxx_xxxzz_0[i] * pa_z[i] - ta1_z_xxxx_xxxzz_1[i] * pc_z[i];

        ta1_z_xxxxz_xxyyy_0[i] = ta_xxxx_xxyyy_1[i] + ta1_z_xxxx_xxyyy_0[i] * pa_z[i] - ta1_z_xxxx_xxyyy_1[i] * pc_z[i];

        ta1_z_xxxxz_xxyyz_0[i] = ta1_z_xxxx_xxyy_0[i] * fe_0 - ta1_z_xxxx_xxyy_1[i] * fe_0 + ta_xxxx_xxyyz_1[i] + ta1_z_xxxx_xxyyz_0[i] * pa_z[i] - ta1_z_xxxx_xxyyz_1[i] * pc_z[i];

        ta1_z_xxxxz_xxyzz_0[i] = 2.0 * ta1_z_xxxx_xxyz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xxyz_1[i] * fe_0 + ta_xxxx_xxyzz_1[i] + ta1_z_xxxx_xxyzz_0[i] * pa_z[i] - ta1_z_xxxx_xxyzz_1[i] * pc_z[i];

        ta1_z_xxxxz_xxzzz_0[i] = 3.0 * ta1_z_xxxx_xxzz_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xxzz_1[i] * fe_0 + ta_xxxx_xxzzz_1[i] + ta1_z_xxxx_xxzzz_0[i] * pa_z[i] - ta1_z_xxxx_xxzzz_1[i] * pc_z[i];

        ta1_z_xxxxz_xyyyy_0[i] = ta_xxxx_xyyyy_1[i] + ta1_z_xxxx_xyyyy_0[i] * pa_z[i] - ta1_z_xxxx_xyyyy_1[i] * pc_z[i];

        ta1_z_xxxxz_xyyyz_0[i] = ta1_z_xxxx_xyyy_0[i] * fe_0 - ta1_z_xxxx_xyyy_1[i] * fe_0 + ta_xxxx_xyyyz_1[i] + ta1_z_xxxx_xyyyz_0[i] * pa_z[i] - ta1_z_xxxx_xyyyz_1[i] * pc_z[i];

        ta1_z_xxxxz_xyyzz_0[i] = 2.0 * ta1_z_xxxx_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xxxx_xyyz_1[i] * fe_0 + ta_xxxx_xyyzz_1[i] + ta1_z_xxxx_xyyzz_0[i] * pa_z[i] - ta1_z_xxxx_xyyzz_1[i] * pc_z[i];

        ta1_z_xxxxz_xyzzz_0[i] = 3.0 * ta1_z_xxxx_xyzz_0[i] * fe_0 - 3.0 * ta1_z_xxxx_xyzz_1[i] * fe_0 + ta_xxxx_xyzzz_1[i] + ta1_z_xxxx_xyzzz_0[i] * pa_z[i] - ta1_z_xxxx_xyzzz_1[i] * pc_z[i];

        ta1_z_xxxxz_xzzzz_0[i] = 4.0 * ta1_z_xxxx_xzzz_0[i] * fe_0 - 4.0 * ta1_z_xxxx_xzzz_1[i] * fe_0 + ta_xxxx_xzzzz_1[i] + ta1_z_xxxx_xzzzz_0[i] * pa_z[i] - ta1_z_xxxx_xzzzz_1[i] * pc_z[i];

        ta1_z_xxxxz_yyyyy_0[i] = ta_xxxx_yyyyy_1[i] + ta1_z_xxxx_yyyyy_0[i] * pa_z[i] - ta1_z_xxxx_yyyyy_1[i] * pc_z[i];

        ta1_z_xxxxz_yyyyz_0[i] = 3.0 * ta1_z_xxz_yyyyz_0[i] * fe_0 - 3.0 * ta1_z_xxz_yyyyz_1[i] * fe_0 + ta1_z_xxxz_yyyyz_0[i] * pa_x[i] - ta1_z_xxxz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxxz_yyyzz_0[i] = 3.0 * ta1_z_xxz_yyyzz_0[i] * fe_0 - 3.0 * ta1_z_xxz_yyyzz_1[i] * fe_0 + ta1_z_xxxz_yyyzz_0[i] * pa_x[i] - ta1_z_xxxz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxxz_yyzzz_0[i] = 3.0 * ta1_z_xxz_yyzzz_0[i] * fe_0 - 3.0 * ta1_z_xxz_yyzzz_1[i] * fe_0 + ta1_z_xxxz_yyzzz_0[i] * pa_x[i] - ta1_z_xxxz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxxz_yzzzz_0[i] = 3.0 * ta1_z_xxz_yzzzz_0[i] * fe_0 - 3.0 * ta1_z_xxz_yzzzz_1[i] * fe_0 + ta1_z_xxxz_yzzzz_0[i] * pa_x[i] - ta1_z_xxxz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxxz_zzzzz_0[i] = 3.0 * ta1_z_xxz_zzzzz_0[i] * fe_0 - 3.0 * ta1_z_xxz_zzzzz_1[i] * fe_0 + ta1_z_xxxz_zzzzz_0[i] * pa_x[i] - ta1_z_xxxz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 945-966 components of targeted buffer : HH

    auto ta1_z_xxxyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 945);

    auto ta1_z_xxxyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 946);

    auto ta1_z_xxxyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 947);

    auto ta1_z_xxxyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 948);

    auto ta1_z_xxxyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 949);

    auto ta1_z_xxxyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 950);

    auto ta1_z_xxxyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 951);

    auto ta1_z_xxxyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 952);

    auto ta1_z_xxxyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 953);

    auto ta1_z_xxxyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 954);

    auto ta1_z_xxxyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 955);

    auto ta1_z_xxxyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 956);

    auto ta1_z_xxxyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 957);

    auto ta1_z_xxxyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 958);

    auto ta1_z_xxxyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 959);

    auto ta1_z_xxxyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 960);

    auto ta1_z_xxxyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 961);

    auto ta1_z_xxxyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 962);

    auto ta1_z_xxxyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 963);

    auto ta1_z_xxxyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 964);

    auto ta1_z_xxxyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 965);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_z_xxx_xxxxx_0, ta1_z_xxx_xxxxx_1, ta1_z_xxx_xxxxz_0, ta1_z_xxx_xxxxz_1, ta1_z_xxx_xxxzz_0, ta1_z_xxx_xxxzz_1, ta1_z_xxx_xxzzz_0, ta1_z_xxx_xxzzz_1, ta1_z_xxx_xzzzz_0, ta1_z_xxx_xzzzz_1, ta1_z_xxxy_xxxxx_0, ta1_z_xxxy_xxxxx_1, ta1_z_xxxy_xxxxz_0, ta1_z_xxxy_xxxxz_1, ta1_z_xxxy_xxxzz_0, ta1_z_xxxy_xxxzz_1, ta1_z_xxxy_xxzzz_0, ta1_z_xxxy_xxzzz_1, ta1_z_xxxy_xzzzz_0, ta1_z_xxxy_xzzzz_1, ta1_z_xxxyy_xxxxx_0, ta1_z_xxxyy_xxxxy_0, ta1_z_xxxyy_xxxxz_0, ta1_z_xxxyy_xxxyy_0, ta1_z_xxxyy_xxxyz_0, ta1_z_xxxyy_xxxzz_0, ta1_z_xxxyy_xxyyy_0, ta1_z_xxxyy_xxyyz_0, ta1_z_xxxyy_xxyzz_0, ta1_z_xxxyy_xxzzz_0, ta1_z_xxxyy_xyyyy_0, ta1_z_xxxyy_xyyyz_0, ta1_z_xxxyy_xyyzz_0, ta1_z_xxxyy_xyzzz_0, ta1_z_xxxyy_xzzzz_0, ta1_z_xxxyy_yyyyy_0, ta1_z_xxxyy_yyyyz_0, ta1_z_xxxyy_yyyzz_0, ta1_z_xxxyy_yyzzz_0, ta1_z_xxxyy_yzzzz_0, ta1_z_xxxyy_zzzzz_0, ta1_z_xxyy_xxxxy_0, ta1_z_xxyy_xxxxy_1, ta1_z_xxyy_xxxy_0, ta1_z_xxyy_xxxy_1, ta1_z_xxyy_xxxyy_0, ta1_z_xxyy_xxxyy_1, ta1_z_xxyy_xxxyz_0, ta1_z_xxyy_xxxyz_1, ta1_z_xxyy_xxyy_0, ta1_z_xxyy_xxyy_1, ta1_z_xxyy_xxyyy_0, ta1_z_xxyy_xxyyy_1, ta1_z_xxyy_xxyyz_0, ta1_z_xxyy_xxyyz_1, ta1_z_xxyy_xxyz_0, ta1_z_xxyy_xxyz_1, ta1_z_xxyy_xxyzz_0, ta1_z_xxyy_xxyzz_1, ta1_z_xxyy_xyyy_0, ta1_z_xxyy_xyyy_1, ta1_z_xxyy_xyyyy_0, ta1_z_xxyy_xyyyy_1, ta1_z_xxyy_xyyyz_0, ta1_z_xxyy_xyyyz_1, ta1_z_xxyy_xyyz_0, ta1_z_xxyy_xyyz_1, ta1_z_xxyy_xyyzz_0, ta1_z_xxyy_xyyzz_1, ta1_z_xxyy_xyzz_0, ta1_z_xxyy_xyzz_1, ta1_z_xxyy_xyzzz_0, ta1_z_xxyy_xyzzz_1, ta1_z_xxyy_yyyy_0, ta1_z_xxyy_yyyy_1, ta1_z_xxyy_yyyyy_0, ta1_z_xxyy_yyyyy_1, ta1_z_xxyy_yyyyz_0, ta1_z_xxyy_yyyyz_1, ta1_z_xxyy_yyyz_0, ta1_z_xxyy_yyyz_1, ta1_z_xxyy_yyyzz_0, ta1_z_xxyy_yyyzz_1, ta1_z_xxyy_yyzz_0, ta1_z_xxyy_yyzz_1, ta1_z_xxyy_yyzzz_0, ta1_z_xxyy_yyzzz_1, ta1_z_xxyy_yzzz_0, ta1_z_xxyy_yzzz_1, ta1_z_xxyy_yzzzz_0, ta1_z_xxyy_yzzzz_1, ta1_z_xxyy_zzzzz_0, ta1_z_xxyy_zzzzz_1, ta1_z_xyy_xxxxy_0, ta1_z_xyy_xxxxy_1, ta1_z_xyy_xxxyy_0, ta1_z_xyy_xxxyy_1, ta1_z_xyy_xxxyz_0, ta1_z_xyy_xxxyz_1, ta1_z_xyy_xxyyy_0, ta1_z_xyy_xxyyy_1, ta1_z_xyy_xxyyz_0, ta1_z_xyy_xxyyz_1, ta1_z_xyy_xxyzz_0, ta1_z_xyy_xxyzz_1, ta1_z_xyy_xyyyy_0, ta1_z_xyy_xyyyy_1, ta1_z_xyy_xyyyz_0, ta1_z_xyy_xyyyz_1, ta1_z_xyy_xyyzz_0, ta1_z_xyy_xyyzz_1, ta1_z_xyy_xyzzz_0, ta1_z_xyy_xyzzz_1, ta1_z_xyy_yyyyy_0, ta1_z_xyy_yyyyy_1, ta1_z_xyy_yyyyz_0, ta1_z_xyy_yyyyz_1, ta1_z_xyy_yyyzz_0, ta1_z_xyy_yyyzz_1, ta1_z_xyy_yyzzz_0, ta1_z_xyy_yyzzz_1, ta1_z_xyy_yzzzz_0, ta1_z_xyy_yzzzz_1, ta1_z_xyy_zzzzz_0, ta1_z_xyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxyy_xxxxx_0[i] = ta1_z_xxx_xxxxx_0[i] * fe_0 - ta1_z_xxx_xxxxx_1[i] * fe_0 + ta1_z_xxxy_xxxxx_0[i] * pa_y[i] - ta1_z_xxxy_xxxxx_1[i] * pc_y[i];

        ta1_z_xxxyy_xxxxy_0[i] = 2.0 * ta1_z_xyy_xxxxy_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxxxy_1[i] * fe_0 + 4.0 * ta1_z_xxyy_xxxy_0[i] * fe_0 - 4.0 * ta1_z_xxyy_xxxy_1[i] * fe_0 + ta1_z_xxyy_xxxxy_0[i] * pa_x[i] - ta1_z_xxyy_xxxxy_1[i] * pc_x[i];

        ta1_z_xxxyy_xxxxz_0[i] = ta1_z_xxx_xxxxz_0[i] * fe_0 - ta1_z_xxx_xxxxz_1[i] * fe_0 + ta1_z_xxxy_xxxxz_0[i] * pa_y[i] - ta1_z_xxxy_xxxxz_1[i] * pc_y[i];

        ta1_z_xxxyy_xxxyy_0[i] = 2.0 * ta1_z_xyy_xxxyy_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxxyy_1[i] * fe_0 + 3.0 * ta1_z_xxyy_xxyy_0[i] * fe_0 - 3.0 * ta1_z_xxyy_xxyy_1[i] * fe_0 + ta1_z_xxyy_xxxyy_0[i] * pa_x[i] - ta1_z_xxyy_xxxyy_1[i] * pc_x[i];

        ta1_z_xxxyy_xxxyz_0[i] = 2.0 * ta1_z_xyy_xxxyz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxxyz_1[i] * fe_0 + 3.0 * ta1_z_xxyy_xxyz_0[i] * fe_0 - 3.0 * ta1_z_xxyy_xxyz_1[i] * fe_0 + ta1_z_xxyy_xxxyz_0[i] * pa_x[i] - ta1_z_xxyy_xxxyz_1[i] * pc_x[i];

        ta1_z_xxxyy_xxxzz_0[i] = ta1_z_xxx_xxxzz_0[i] * fe_0 - ta1_z_xxx_xxxzz_1[i] * fe_0 + ta1_z_xxxy_xxxzz_0[i] * pa_y[i] - ta1_z_xxxy_xxxzz_1[i] * pc_y[i];

        ta1_z_xxxyy_xxyyy_0[i] = 2.0 * ta1_z_xyy_xxyyy_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxyyy_1[i] * fe_0 + 2.0 * ta1_z_xxyy_xyyy_0[i] * fe_0 - 2.0 * ta1_z_xxyy_xyyy_1[i] * fe_0 + ta1_z_xxyy_xxyyy_0[i] * pa_x[i] - ta1_z_xxyy_xxyyy_1[i] * pc_x[i];

        ta1_z_xxxyy_xxyyz_0[i] = 2.0 * ta1_z_xyy_xxyyz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_xxyy_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xxyy_xyyz_1[i] * fe_0 + ta1_z_xxyy_xxyyz_0[i] * pa_x[i] - ta1_z_xxyy_xxyyz_1[i] * pc_x[i];

        ta1_z_xxxyy_xxyzz_0[i] = 2.0 * ta1_z_xyy_xxyzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_xxyy_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxyy_xyzz_1[i] * fe_0 + ta1_z_xxyy_xxyzz_0[i] * pa_x[i] - ta1_z_xxyy_xxyzz_1[i] * pc_x[i];

        ta1_z_xxxyy_xxzzz_0[i] = ta1_z_xxx_xxzzz_0[i] * fe_0 - ta1_z_xxx_xxzzz_1[i] * fe_0 + ta1_z_xxxy_xxzzz_0[i] * pa_y[i] - ta1_z_xxxy_xxzzz_1[i] * pc_y[i];

        ta1_z_xxxyy_xyyyy_0[i] = 2.0 * ta1_z_xyy_xyyyy_0[i] * fe_0 - 2.0 * ta1_z_xyy_xyyyy_1[i] * fe_0 + ta1_z_xxyy_yyyy_0[i] * fe_0 - ta1_z_xxyy_yyyy_1[i] * fe_0 + ta1_z_xxyy_xyyyy_0[i] * pa_x[i] - ta1_z_xxyy_xyyyy_1[i] * pc_x[i];

        ta1_z_xxxyy_xyyyz_0[i] = 2.0 * ta1_z_xyy_xyyyz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xyyyz_1[i] * fe_0 + ta1_z_xxyy_yyyz_0[i] * fe_0 - ta1_z_xxyy_yyyz_1[i] * fe_0 + ta1_z_xxyy_xyyyz_0[i] * pa_x[i] - ta1_z_xxyy_xyyyz_1[i] * pc_x[i];

        ta1_z_xxxyy_xyyzz_0[i] = 2.0 * ta1_z_xyy_xyyzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xyyzz_1[i] * fe_0 + ta1_z_xxyy_yyzz_0[i] * fe_0 - ta1_z_xxyy_yyzz_1[i] * fe_0 + ta1_z_xxyy_xyyzz_0[i] * pa_x[i] - ta1_z_xxyy_xyyzz_1[i] * pc_x[i];

        ta1_z_xxxyy_xyzzz_0[i] = 2.0 * ta1_z_xyy_xyzzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_xyzzz_1[i] * fe_0 + ta1_z_xxyy_yzzz_0[i] * fe_0 - ta1_z_xxyy_yzzz_1[i] * fe_0 + ta1_z_xxyy_xyzzz_0[i] * pa_x[i] - ta1_z_xxyy_xyzzz_1[i] * pc_x[i];

        ta1_z_xxxyy_xzzzz_0[i] = ta1_z_xxx_xzzzz_0[i] * fe_0 - ta1_z_xxx_xzzzz_1[i] * fe_0 + ta1_z_xxxy_xzzzz_0[i] * pa_y[i] - ta1_z_xxxy_xzzzz_1[i] * pc_y[i];

        ta1_z_xxxyy_yyyyy_0[i] = 2.0 * ta1_z_xyy_yyyyy_0[i] * fe_0 - 2.0 * ta1_z_xyy_yyyyy_1[i] * fe_0 + ta1_z_xxyy_yyyyy_0[i] * pa_x[i] - ta1_z_xxyy_yyyyy_1[i] * pc_x[i];

        ta1_z_xxxyy_yyyyz_0[i] = 2.0 * ta1_z_xyy_yyyyz_0[i] * fe_0 - 2.0 * ta1_z_xyy_yyyyz_1[i] * fe_0 + ta1_z_xxyy_yyyyz_0[i] * pa_x[i] - ta1_z_xxyy_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxyy_yyyzz_0[i] = 2.0 * ta1_z_xyy_yyyzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_yyyzz_1[i] * fe_0 + ta1_z_xxyy_yyyzz_0[i] * pa_x[i] - ta1_z_xxyy_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxyy_yyzzz_0[i] = 2.0 * ta1_z_xyy_yyzzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_yyzzz_1[i] * fe_0 + ta1_z_xxyy_yyzzz_0[i] * pa_x[i] - ta1_z_xxyy_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxyy_yzzzz_0[i] = 2.0 * ta1_z_xyy_yzzzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_yzzzz_1[i] * fe_0 + ta1_z_xxyy_yzzzz_0[i] * pa_x[i] - ta1_z_xxyy_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxyy_zzzzz_0[i] = 2.0 * ta1_z_xyy_zzzzz_0[i] * fe_0 - 2.0 * ta1_z_xyy_zzzzz_1[i] * fe_0 + ta1_z_xxyy_zzzzz_0[i] * pa_x[i] - ta1_z_xxyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 966-987 components of targeted buffer : HH

    auto ta1_z_xxxyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 966);

    auto ta1_z_xxxyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 967);

    auto ta1_z_xxxyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 968);

    auto ta1_z_xxxyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 969);

    auto ta1_z_xxxyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 970);

    auto ta1_z_xxxyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 971);

    auto ta1_z_xxxyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 972);

    auto ta1_z_xxxyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 973);

    auto ta1_z_xxxyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 974);

    auto ta1_z_xxxyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 975);

    auto ta1_z_xxxyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 976);

    auto ta1_z_xxxyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 977);

    auto ta1_z_xxxyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 978);

    auto ta1_z_xxxyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 979);

    auto ta1_z_xxxyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 980);

    auto ta1_z_xxxyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 981);

    auto ta1_z_xxxyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 982);

    auto ta1_z_xxxyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 983);

    auto ta1_z_xxxyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 984);

    auto ta1_z_xxxyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 985);

    auto ta1_z_xxxyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 986);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_z_xxxy_xxxxy_0, ta1_z_xxxy_xxxxy_1, ta1_z_xxxy_xxxyy_0, ta1_z_xxxy_xxxyy_1, ta1_z_xxxy_xxyyy_0, ta1_z_xxxy_xxyyy_1, ta1_z_xxxy_xyyyy_0, ta1_z_xxxy_xyyyy_1, ta1_z_xxxy_yyyyy_0, ta1_z_xxxy_yyyyy_1, ta1_z_xxxyz_xxxxx_0, ta1_z_xxxyz_xxxxy_0, ta1_z_xxxyz_xxxxz_0, ta1_z_xxxyz_xxxyy_0, ta1_z_xxxyz_xxxyz_0, ta1_z_xxxyz_xxxzz_0, ta1_z_xxxyz_xxyyy_0, ta1_z_xxxyz_xxyyz_0, ta1_z_xxxyz_xxyzz_0, ta1_z_xxxyz_xxzzz_0, ta1_z_xxxyz_xyyyy_0, ta1_z_xxxyz_xyyyz_0, ta1_z_xxxyz_xyyzz_0, ta1_z_xxxyz_xyzzz_0, ta1_z_xxxyz_xzzzz_0, ta1_z_xxxyz_yyyyy_0, ta1_z_xxxyz_yyyyz_0, ta1_z_xxxyz_yyyzz_0, ta1_z_xxxyz_yyzzz_0, ta1_z_xxxyz_yzzzz_0, ta1_z_xxxyz_zzzzz_0, ta1_z_xxxz_xxxxx_0, ta1_z_xxxz_xxxxx_1, ta1_z_xxxz_xxxxz_0, ta1_z_xxxz_xxxxz_1, ta1_z_xxxz_xxxyz_0, ta1_z_xxxz_xxxyz_1, ta1_z_xxxz_xxxz_0, ta1_z_xxxz_xxxz_1, ta1_z_xxxz_xxxzz_0, ta1_z_xxxz_xxxzz_1, ta1_z_xxxz_xxyyz_0, ta1_z_xxxz_xxyyz_1, ta1_z_xxxz_xxyz_0, ta1_z_xxxz_xxyz_1, ta1_z_xxxz_xxyzz_0, ta1_z_xxxz_xxyzz_1, ta1_z_xxxz_xxzz_0, ta1_z_xxxz_xxzz_1, ta1_z_xxxz_xxzzz_0, ta1_z_xxxz_xxzzz_1, ta1_z_xxxz_xyyyz_0, ta1_z_xxxz_xyyyz_1, ta1_z_xxxz_xyyz_0, ta1_z_xxxz_xyyz_1, ta1_z_xxxz_xyyzz_0, ta1_z_xxxz_xyyzz_1, ta1_z_xxxz_xyzz_0, ta1_z_xxxz_xyzz_1, ta1_z_xxxz_xyzzz_0, ta1_z_xxxz_xyzzz_1, ta1_z_xxxz_xzzz_0, ta1_z_xxxz_xzzz_1, ta1_z_xxxz_xzzzz_0, ta1_z_xxxz_xzzzz_1, ta1_z_xxxz_zzzzz_0, ta1_z_xxxz_zzzzz_1, ta1_z_xxyz_yyyyz_0, ta1_z_xxyz_yyyyz_1, ta1_z_xxyz_yyyzz_0, ta1_z_xxyz_yyyzz_1, ta1_z_xxyz_yyzzz_0, ta1_z_xxyz_yyzzz_1, ta1_z_xxyz_yzzzz_0, ta1_z_xxyz_yzzzz_1, ta1_z_xyz_yyyyz_0, ta1_z_xyz_yyyyz_1, ta1_z_xyz_yyyzz_0, ta1_z_xyz_yyyzz_1, ta1_z_xyz_yyzzz_0, ta1_z_xyz_yyzzz_1, ta1_z_xyz_yzzzz_0, ta1_z_xyz_yzzzz_1, ta_xxxy_xxxxy_1, ta_xxxy_xxxyy_1, ta_xxxy_xxyyy_1, ta_xxxy_xyyyy_1, ta_xxxy_yyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxyz_xxxxx_0[i] = ta1_z_xxxz_xxxxx_0[i] * pa_y[i] - ta1_z_xxxz_xxxxx_1[i] * pc_y[i];

        ta1_z_xxxyz_xxxxy_0[i] = ta_xxxy_xxxxy_1[i] + ta1_z_xxxy_xxxxy_0[i] * pa_z[i] - ta1_z_xxxy_xxxxy_1[i] * pc_z[i];

        ta1_z_xxxyz_xxxxz_0[i] = ta1_z_xxxz_xxxxz_0[i] * pa_y[i] - ta1_z_xxxz_xxxxz_1[i] * pc_y[i];

        ta1_z_xxxyz_xxxyy_0[i] = ta_xxxy_xxxyy_1[i] + ta1_z_xxxy_xxxyy_0[i] * pa_z[i] - ta1_z_xxxy_xxxyy_1[i] * pc_z[i];

        ta1_z_xxxyz_xxxyz_0[i] = ta1_z_xxxz_xxxz_0[i] * fe_0 - ta1_z_xxxz_xxxz_1[i] * fe_0 + ta1_z_xxxz_xxxyz_0[i] * pa_y[i] - ta1_z_xxxz_xxxyz_1[i] * pc_y[i];

        ta1_z_xxxyz_xxxzz_0[i] = ta1_z_xxxz_xxxzz_0[i] * pa_y[i] - ta1_z_xxxz_xxxzz_1[i] * pc_y[i];

        ta1_z_xxxyz_xxyyy_0[i] = ta_xxxy_xxyyy_1[i] + ta1_z_xxxy_xxyyy_0[i] * pa_z[i] - ta1_z_xxxy_xxyyy_1[i] * pc_z[i];

        ta1_z_xxxyz_xxyyz_0[i] = 2.0 * ta1_z_xxxz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_xxxz_xxyz_1[i] * fe_0 + ta1_z_xxxz_xxyyz_0[i] * pa_y[i] - ta1_z_xxxz_xxyyz_1[i] * pc_y[i];

        ta1_z_xxxyz_xxyzz_0[i] = ta1_z_xxxz_xxzz_0[i] * fe_0 - ta1_z_xxxz_xxzz_1[i] * fe_0 + ta1_z_xxxz_xxyzz_0[i] * pa_y[i] - ta1_z_xxxz_xxyzz_1[i] * pc_y[i];

        ta1_z_xxxyz_xxzzz_0[i] = ta1_z_xxxz_xxzzz_0[i] * pa_y[i] - ta1_z_xxxz_xxzzz_1[i] * pc_y[i];

        ta1_z_xxxyz_xyyyy_0[i] = ta_xxxy_xyyyy_1[i] + ta1_z_xxxy_xyyyy_0[i] * pa_z[i] - ta1_z_xxxy_xyyyy_1[i] * pc_z[i];

        ta1_z_xxxyz_xyyyz_0[i] = 3.0 * ta1_z_xxxz_xyyz_0[i] * fe_0 - 3.0 * ta1_z_xxxz_xyyz_1[i] * fe_0 + ta1_z_xxxz_xyyyz_0[i] * pa_y[i] - ta1_z_xxxz_xyyyz_1[i] * pc_y[i];

        ta1_z_xxxyz_xyyzz_0[i] = 2.0 * ta1_z_xxxz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxxz_xyzz_1[i] * fe_0 + ta1_z_xxxz_xyyzz_0[i] * pa_y[i] - ta1_z_xxxz_xyyzz_1[i] * pc_y[i];

        ta1_z_xxxyz_xyzzz_0[i] = ta1_z_xxxz_xzzz_0[i] * fe_0 - ta1_z_xxxz_xzzz_1[i] * fe_0 + ta1_z_xxxz_xyzzz_0[i] * pa_y[i] - ta1_z_xxxz_xyzzz_1[i] * pc_y[i];

        ta1_z_xxxyz_xzzzz_0[i] = ta1_z_xxxz_xzzzz_0[i] * pa_y[i] - ta1_z_xxxz_xzzzz_1[i] * pc_y[i];

        ta1_z_xxxyz_yyyyy_0[i] = ta_xxxy_yyyyy_1[i] + ta1_z_xxxy_yyyyy_0[i] * pa_z[i] - ta1_z_xxxy_yyyyy_1[i] * pc_z[i];

        ta1_z_xxxyz_yyyyz_0[i] = 2.0 * ta1_z_xyz_yyyyz_0[i] * fe_0 - 2.0 * ta1_z_xyz_yyyyz_1[i] * fe_0 + ta1_z_xxyz_yyyyz_0[i] * pa_x[i] - ta1_z_xxyz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxyz_yyyzz_0[i] = 2.0 * ta1_z_xyz_yyyzz_0[i] * fe_0 - 2.0 * ta1_z_xyz_yyyzz_1[i] * fe_0 + ta1_z_xxyz_yyyzz_0[i] * pa_x[i] - ta1_z_xxyz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxyz_yyzzz_0[i] = 2.0 * ta1_z_xyz_yyzzz_0[i] * fe_0 - 2.0 * ta1_z_xyz_yyzzz_1[i] * fe_0 + ta1_z_xxyz_yyzzz_0[i] * pa_x[i] - ta1_z_xxyz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxyz_yzzzz_0[i] = 2.0 * ta1_z_xyz_yzzzz_0[i] * fe_0 - 2.0 * ta1_z_xyz_yzzzz_1[i] * fe_0 + ta1_z_xxyz_yzzzz_0[i] * pa_x[i] - ta1_z_xxyz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxyz_zzzzz_0[i] = ta1_z_xxxz_zzzzz_0[i] * pa_y[i] - ta1_z_xxxz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 987-1008 components of targeted buffer : HH

    auto ta1_z_xxxzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 987);

    auto ta1_z_xxxzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 988);

    auto ta1_z_xxxzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 989);

    auto ta1_z_xxxzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 990);

    auto ta1_z_xxxzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 991);

    auto ta1_z_xxxzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 992);

    auto ta1_z_xxxzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 993);

    auto ta1_z_xxxzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 994);

    auto ta1_z_xxxzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 995);

    auto ta1_z_xxxzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 996);

    auto ta1_z_xxxzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 997);

    auto ta1_z_xxxzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 998);

    auto ta1_z_xxxzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 999);

    auto ta1_z_xxxzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1000);

    auto ta1_z_xxxzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1001);

    auto ta1_z_xxxzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1002);

    auto ta1_z_xxxzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1003);

    auto ta1_z_xxxzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1004);

    auto ta1_z_xxxzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1005);

    auto ta1_z_xxxzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1006);

    auto ta1_z_xxxzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1007);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_z_xxx_xxxxx_0, ta1_z_xxx_xxxxx_1, ta1_z_xxx_xxxxy_0, ta1_z_xxx_xxxxy_1, ta1_z_xxx_xxxyy_0, ta1_z_xxx_xxxyy_1, ta1_z_xxx_xxyyy_0, ta1_z_xxx_xxyyy_1, ta1_z_xxx_xyyyy_0, ta1_z_xxx_xyyyy_1, ta1_z_xxxz_xxxxx_0, ta1_z_xxxz_xxxxx_1, ta1_z_xxxz_xxxxy_0, ta1_z_xxxz_xxxxy_1, ta1_z_xxxz_xxxyy_0, ta1_z_xxxz_xxxyy_1, ta1_z_xxxz_xxyyy_0, ta1_z_xxxz_xxyyy_1, ta1_z_xxxz_xyyyy_0, ta1_z_xxxz_xyyyy_1, ta1_z_xxxzz_xxxxx_0, ta1_z_xxxzz_xxxxy_0, ta1_z_xxxzz_xxxxz_0, ta1_z_xxxzz_xxxyy_0, ta1_z_xxxzz_xxxyz_0, ta1_z_xxxzz_xxxzz_0, ta1_z_xxxzz_xxyyy_0, ta1_z_xxxzz_xxyyz_0, ta1_z_xxxzz_xxyzz_0, ta1_z_xxxzz_xxzzz_0, ta1_z_xxxzz_xyyyy_0, ta1_z_xxxzz_xyyyz_0, ta1_z_xxxzz_xyyzz_0, ta1_z_xxxzz_xyzzz_0, ta1_z_xxxzz_xzzzz_0, ta1_z_xxxzz_yyyyy_0, ta1_z_xxxzz_yyyyz_0, ta1_z_xxxzz_yyyzz_0, ta1_z_xxxzz_yyzzz_0, ta1_z_xxxzz_yzzzz_0, ta1_z_xxxzz_zzzzz_0, ta1_z_xxzz_xxxxz_0, ta1_z_xxzz_xxxxz_1, ta1_z_xxzz_xxxyz_0, ta1_z_xxzz_xxxyz_1, ta1_z_xxzz_xxxz_0, ta1_z_xxzz_xxxz_1, ta1_z_xxzz_xxxzz_0, ta1_z_xxzz_xxxzz_1, ta1_z_xxzz_xxyyz_0, ta1_z_xxzz_xxyyz_1, ta1_z_xxzz_xxyz_0, ta1_z_xxzz_xxyz_1, ta1_z_xxzz_xxyzz_0, ta1_z_xxzz_xxyzz_1, ta1_z_xxzz_xxzz_0, ta1_z_xxzz_xxzz_1, ta1_z_xxzz_xxzzz_0, ta1_z_xxzz_xxzzz_1, ta1_z_xxzz_xyyyz_0, ta1_z_xxzz_xyyyz_1, ta1_z_xxzz_xyyz_0, ta1_z_xxzz_xyyz_1, ta1_z_xxzz_xyyzz_0, ta1_z_xxzz_xyyzz_1, ta1_z_xxzz_xyzz_0, ta1_z_xxzz_xyzz_1, ta1_z_xxzz_xyzzz_0, ta1_z_xxzz_xyzzz_1, ta1_z_xxzz_xzzz_0, ta1_z_xxzz_xzzz_1, ta1_z_xxzz_xzzzz_0, ta1_z_xxzz_xzzzz_1, ta1_z_xxzz_yyyyy_0, ta1_z_xxzz_yyyyy_1, ta1_z_xxzz_yyyyz_0, ta1_z_xxzz_yyyyz_1, ta1_z_xxzz_yyyz_0, ta1_z_xxzz_yyyz_1, ta1_z_xxzz_yyyzz_0, ta1_z_xxzz_yyyzz_1, ta1_z_xxzz_yyzz_0, ta1_z_xxzz_yyzz_1, ta1_z_xxzz_yyzzz_0, ta1_z_xxzz_yyzzz_1, ta1_z_xxzz_yzzz_0, ta1_z_xxzz_yzzz_1, ta1_z_xxzz_yzzzz_0, ta1_z_xxzz_yzzzz_1, ta1_z_xxzz_zzzz_0, ta1_z_xxzz_zzzz_1, ta1_z_xxzz_zzzzz_0, ta1_z_xxzz_zzzzz_1, ta1_z_xzz_xxxxz_0, ta1_z_xzz_xxxxz_1, ta1_z_xzz_xxxyz_0, ta1_z_xzz_xxxyz_1, ta1_z_xzz_xxxzz_0, ta1_z_xzz_xxxzz_1, ta1_z_xzz_xxyyz_0, ta1_z_xzz_xxyyz_1, ta1_z_xzz_xxyzz_0, ta1_z_xzz_xxyzz_1, ta1_z_xzz_xxzzz_0, ta1_z_xzz_xxzzz_1, ta1_z_xzz_xyyyz_0, ta1_z_xzz_xyyyz_1, ta1_z_xzz_xyyzz_0, ta1_z_xzz_xyyzz_1, ta1_z_xzz_xyzzz_0, ta1_z_xzz_xyzzz_1, ta1_z_xzz_xzzzz_0, ta1_z_xzz_xzzzz_1, ta1_z_xzz_yyyyy_0, ta1_z_xzz_yyyyy_1, ta1_z_xzz_yyyyz_0, ta1_z_xzz_yyyyz_1, ta1_z_xzz_yyyzz_0, ta1_z_xzz_yyyzz_1, ta1_z_xzz_yyzzz_0, ta1_z_xzz_yyzzz_1, ta1_z_xzz_yzzzz_0, ta1_z_xzz_yzzzz_1, ta1_z_xzz_zzzzz_0, ta1_z_xzz_zzzzz_1, ta_xxxz_xxxxx_1, ta_xxxz_xxxxy_1, ta_xxxz_xxxyy_1, ta_xxxz_xxyyy_1, ta_xxxz_xyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxxzz_xxxxx_0[i] = ta1_z_xxx_xxxxx_0[i] * fe_0 - ta1_z_xxx_xxxxx_1[i] * fe_0 + ta_xxxz_xxxxx_1[i] + ta1_z_xxxz_xxxxx_0[i] * pa_z[i] - ta1_z_xxxz_xxxxx_1[i] * pc_z[i];

        ta1_z_xxxzz_xxxxy_0[i] = ta1_z_xxx_xxxxy_0[i] * fe_0 - ta1_z_xxx_xxxxy_1[i] * fe_0 + ta_xxxz_xxxxy_1[i] + ta1_z_xxxz_xxxxy_0[i] * pa_z[i] - ta1_z_xxxz_xxxxy_1[i] * pc_z[i];

        ta1_z_xxxzz_xxxxz_0[i] = 2.0 * ta1_z_xzz_xxxxz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxxxz_1[i] * fe_0 + 4.0 * ta1_z_xxzz_xxxz_0[i] * fe_0 - 4.0 * ta1_z_xxzz_xxxz_1[i] * fe_0 + ta1_z_xxzz_xxxxz_0[i] * pa_x[i] - ta1_z_xxzz_xxxxz_1[i] * pc_x[i];

        ta1_z_xxxzz_xxxyy_0[i] = ta1_z_xxx_xxxyy_0[i] * fe_0 - ta1_z_xxx_xxxyy_1[i] * fe_0 + ta_xxxz_xxxyy_1[i] + ta1_z_xxxz_xxxyy_0[i] * pa_z[i] - ta1_z_xxxz_xxxyy_1[i] * pc_z[i];

        ta1_z_xxxzz_xxxyz_0[i] = 2.0 * ta1_z_xzz_xxxyz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxxyz_1[i] * fe_0 + 3.0 * ta1_z_xxzz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_xxzz_xxyz_1[i] * fe_0 + ta1_z_xxzz_xxxyz_0[i] * pa_x[i] - ta1_z_xxzz_xxxyz_1[i] * pc_x[i];

        ta1_z_xxxzz_xxxzz_0[i] = 2.0 * ta1_z_xzz_xxxzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxxzz_1[i] * fe_0 + 3.0 * ta1_z_xxzz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_xxzz_xxzz_1[i] * fe_0 + ta1_z_xxzz_xxxzz_0[i] * pa_x[i] - ta1_z_xxzz_xxxzz_1[i] * pc_x[i];

        ta1_z_xxxzz_xxyyy_0[i] = ta1_z_xxx_xxyyy_0[i] * fe_0 - ta1_z_xxx_xxyyy_1[i] * fe_0 + ta_xxxz_xxyyy_1[i] + ta1_z_xxxz_xxyyy_0[i] * pa_z[i] - ta1_z_xxxz_xxyyy_1[i] * pc_z[i];

        ta1_z_xxxzz_xxyyz_0[i] = 2.0 * ta1_z_xzz_xxyyz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_xxzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xyyz_1[i] * fe_0 + ta1_z_xxzz_xxyyz_0[i] * pa_x[i] - ta1_z_xxzz_xxyyz_1[i] * pc_x[i];

        ta1_z_xxxzz_xxyzz_0[i] = 2.0 * ta1_z_xzz_xxyzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_xxzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xyzz_1[i] * fe_0 + ta1_z_xxzz_xxyzz_0[i] * pa_x[i] - ta1_z_xxzz_xxyzz_1[i] * pc_x[i];

        ta1_z_xxxzz_xxzzz_0[i] = 2.0 * ta1_z_xzz_xxzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xxzzz_1[i] * fe_0 + 2.0 * ta1_z_xxzz_xzzz_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xzzz_1[i] * fe_0 + ta1_z_xxzz_xxzzz_0[i] * pa_x[i] - ta1_z_xxzz_xxzzz_1[i] * pc_x[i];

        ta1_z_xxxzz_xyyyy_0[i] = ta1_z_xxx_xyyyy_0[i] * fe_0 - ta1_z_xxx_xyyyy_1[i] * fe_0 + ta_xxxz_xyyyy_1[i] + ta1_z_xxxz_xyyyy_0[i] * pa_z[i] - ta1_z_xxxz_xyyyy_1[i] * pc_z[i];

        ta1_z_xxxzz_xyyyz_0[i] = 2.0 * ta1_z_xzz_xyyyz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xyyyz_1[i] * fe_0 + ta1_z_xxzz_yyyz_0[i] * fe_0 - ta1_z_xxzz_yyyz_1[i] * fe_0 + ta1_z_xxzz_xyyyz_0[i] * pa_x[i] - ta1_z_xxzz_xyyyz_1[i] * pc_x[i];

        ta1_z_xxxzz_xyyzz_0[i] = 2.0 * ta1_z_xzz_xyyzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xyyzz_1[i] * fe_0 + ta1_z_xxzz_yyzz_0[i] * fe_0 - ta1_z_xxzz_yyzz_1[i] * fe_0 + ta1_z_xxzz_xyyzz_0[i] * pa_x[i] - ta1_z_xxzz_xyyzz_1[i] * pc_x[i];

        ta1_z_xxxzz_xyzzz_0[i] = 2.0 * ta1_z_xzz_xyzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xyzzz_1[i] * fe_0 + ta1_z_xxzz_yzzz_0[i] * fe_0 - ta1_z_xxzz_yzzz_1[i] * fe_0 + ta1_z_xxzz_xyzzz_0[i] * pa_x[i] - ta1_z_xxzz_xyzzz_1[i] * pc_x[i];

        ta1_z_xxxzz_xzzzz_0[i] = 2.0 * ta1_z_xzz_xzzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_xzzzz_1[i] * fe_0 + ta1_z_xxzz_zzzz_0[i] * fe_0 - ta1_z_xxzz_zzzz_1[i] * fe_0 + ta1_z_xxzz_xzzzz_0[i] * pa_x[i] - ta1_z_xxzz_xzzzz_1[i] * pc_x[i];

        ta1_z_xxxzz_yyyyy_0[i] = 2.0 * ta1_z_xzz_yyyyy_0[i] * fe_0 - 2.0 * ta1_z_xzz_yyyyy_1[i] * fe_0 + ta1_z_xxzz_yyyyy_0[i] * pa_x[i] - ta1_z_xxzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xxxzz_yyyyz_0[i] = 2.0 * ta1_z_xzz_yyyyz_0[i] * fe_0 - 2.0 * ta1_z_xzz_yyyyz_1[i] * fe_0 + ta1_z_xxzz_yyyyz_0[i] * pa_x[i] - ta1_z_xxzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxxzz_yyyzz_0[i] = 2.0 * ta1_z_xzz_yyyzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_yyyzz_1[i] * fe_0 + ta1_z_xxzz_yyyzz_0[i] * pa_x[i] - ta1_z_xxzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxxzz_yyzzz_0[i] = 2.0 * ta1_z_xzz_yyzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_yyzzz_1[i] * fe_0 + ta1_z_xxzz_yyzzz_0[i] * pa_x[i] - ta1_z_xxzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxxzz_yzzzz_0[i] = 2.0 * ta1_z_xzz_yzzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_yzzzz_1[i] * fe_0 + ta1_z_xxzz_yzzzz_0[i] * pa_x[i] - ta1_z_xxzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxxzz_zzzzz_0[i] = 2.0 * ta1_z_xzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_z_xzz_zzzzz_1[i] * fe_0 + ta1_z_xxzz_zzzzz_0[i] * pa_x[i] - ta1_z_xxzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1008-1029 components of targeted buffer : HH

    auto ta1_z_xxyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1008);

    auto ta1_z_xxyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1009);

    auto ta1_z_xxyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1010);

    auto ta1_z_xxyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1011);

    auto ta1_z_xxyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1012);

    auto ta1_z_xxyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1013);

    auto ta1_z_xxyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1014);

    auto ta1_z_xxyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1015);

    auto ta1_z_xxyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1016);

    auto ta1_z_xxyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1017);

    auto ta1_z_xxyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1018);

    auto ta1_z_xxyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1019);

    auto ta1_z_xxyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1020);

    auto ta1_z_xxyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1021);

    auto ta1_z_xxyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1022);

    auto ta1_z_xxyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1023);

    auto ta1_z_xxyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1024);

    auto ta1_z_xxyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1025);

    auto ta1_z_xxyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1026);

    auto ta1_z_xxyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1027);

    auto ta1_z_xxyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1028);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_z_xxy_xxxxx_0, ta1_z_xxy_xxxxx_1, ta1_z_xxy_xxxxz_0, ta1_z_xxy_xxxxz_1, ta1_z_xxy_xxxzz_0, ta1_z_xxy_xxxzz_1, ta1_z_xxy_xxzzz_0, ta1_z_xxy_xxzzz_1, ta1_z_xxy_xzzzz_0, ta1_z_xxy_xzzzz_1, ta1_z_xxyy_xxxxx_0, ta1_z_xxyy_xxxxx_1, ta1_z_xxyy_xxxxz_0, ta1_z_xxyy_xxxxz_1, ta1_z_xxyy_xxxzz_0, ta1_z_xxyy_xxxzz_1, ta1_z_xxyy_xxzzz_0, ta1_z_xxyy_xxzzz_1, ta1_z_xxyy_xzzzz_0, ta1_z_xxyy_xzzzz_1, ta1_z_xxyyy_xxxxx_0, ta1_z_xxyyy_xxxxy_0, ta1_z_xxyyy_xxxxz_0, ta1_z_xxyyy_xxxyy_0, ta1_z_xxyyy_xxxyz_0, ta1_z_xxyyy_xxxzz_0, ta1_z_xxyyy_xxyyy_0, ta1_z_xxyyy_xxyyz_0, ta1_z_xxyyy_xxyzz_0, ta1_z_xxyyy_xxzzz_0, ta1_z_xxyyy_xyyyy_0, ta1_z_xxyyy_xyyyz_0, ta1_z_xxyyy_xyyzz_0, ta1_z_xxyyy_xyzzz_0, ta1_z_xxyyy_xzzzz_0, ta1_z_xxyyy_yyyyy_0, ta1_z_xxyyy_yyyyz_0, ta1_z_xxyyy_yyyzz_0, ta1_z_xxyyy_yyzzz_0, ta1_z_xxyyy_yzzzz_0, ta1_z_xxyyy_zzzzz_0, ta1_z_xyyy_xxxxy_0, ta1_z_xyyy_xxxxy_1, ta1_z_xyyy_xxxy_0, ta1_z_xyyy_xxxy_1, ta1_z_xyyy_xxxyy_0, ta1_z_xyyy_xxxyy_1, ta1_z_xyyy_xxxyz_0, ta1_z_xyyy_xxxyz_1, ta1_z_xyyy_xxyy_0, ta1_z_xyyy_xxyy_1, ta1_z_xyyy_xxyyy_0, ta1_z_xyyy_xxyyy_1, ta1_z_xyyy_xxyyz_0, ta1_z_xyyy_xxyyz_1, ta1_z_xyyy_xxyz_0, ta1_z_xyyy_xxyz_1, ta1_z_xyyy_xxyzz_0, ta1_z_xyyy_xxyzz_1, ta1_z_xyyy_xyyy_0, ta1_z_xyyy_xyyy_1, ta1_z_xyyy_xyyyy_0, ta1_z_xyyy_xyyyy_1, ta1_z_xyyy_xyyyz_0, ta1_z_xyyy_xyyyz_1, ta1_z_xyyy_xyyz_0, ta1_z_xyyy_xyyz_1, ta1_z_xyyy_xyyzz_0, ta1_z_xyyy_xyyzz_1, ta1_z_xyyy_xyzz_0, ta1_z_xyyy_xyzz_1, ta1_z_xyyy_xyzzz_0, ta1_z_xyyy_xyzzz_1, ta1_z_xyyy_yyyy_0, ta1_z_xyyy_yyyy_1, ta1_z_xyyy_yyyyy_0, ta1_z_xyyy_yyyyy_1, ta1_z_xyyy_yyyyz_0, ta1_z_xyyy_yyyyz_1, ta1_z_xyyy_yyyz_0, ta1_z_xyyy_yyyz_1, ta1_z_xyyy_yyyzz_0, ta1_z_xyyy_yyyzz_1, ta1_z_xyyy_yyzz_0, ta1_z_xyyy_yyzz_1, ta1_z_xyyy_yyzzz_0, ta1_z_xyyy_yyzzz_1, ta1_z_xyyy_yzzz_0, ta1_z_xyyy_yzzz_1, ta1_z_xyyy_yzzzz_0, ta1_z_xyyy_yzzzz_1, ta1_z_xyyy_zzzzz_0, ta1_z_xyyy_zzzzz_1, ta1_z_yyy_xxxxy_0, ta1_z_yyy_xxxxy_1, ta1_z_yyy_xxxyy_0, ta1_z_yyy_xxxyy_1, ta1_z_yyy_xxxyz_0, ta1_z_yyy_xxxyz_1, ta1_z_yyy_xxyyy_0, ta1_z_yyy_xxyyy_1, ta1_z_yyy_xxyyz_0, ta1_z_yyy_xxyyz_1, ta1_z_yyy_xxyzz_0, ta1_z_yyy_xxyzz_1, ta1_z_yyy_xyyyy_0, ta1_z_yyy_xyyyy_1, ta1_z_yyy_xyyyz_0, ta1_z_yyy_xyyyz_1, ta1_z_yyy_xyyzz_0, ta1_z_yyy_xyyzz_1, ta1_z_yyy_xyzzz_0, ta1_z_yyy_xyzzz_1, ta1_z_yyy_yyyyy_0, ta1_z_yyy_yyyyy_1, ta1_z_yyy_yyyyz_0, ta1_z_yyy_yyyyz_1, ta1_z_yyy_yyyzz_0, ta1_z_yyy_yyyzz_1, ta1_z_yyy_yyzzz_0, ta1_z_yyy_yyzzz_1, ta1_z_yyy_yzzzz_0, ta1_z_yyy_yzzzz_1, ta1_z_yyy_zzzzz_0, ta1_z_yyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxyyy_xxxxx_0[i] = 2.0 * ta1_z_xxy_xxxxx_0[i] * fe_0 - 2.0 * ta1_z_xxy_xxxxx_1[i] * fe_0 + ta1_z_xxyy_xxxxx_0[i] * pa_y[i] - ta1_z_xxyy_xxxxx_1[i] * pc_y[i];

        ta1_z_xxyyy_xxxxy_0[i] = ta1_z_yyy_xxxxy_0[i] * fe_0 - ta1_z_yyy_xxxxy_1[i] * fe_0 + 4.0 * ta1_z_xyyy_xxxy_0[i] * fe_0 - 4.0 * ta1_z_xyyy_xxxy_1[i] * fe_0 + ta1_z_xyyy_xxxxy_0[i] * pa_x[i] - ta1_z_xyyy_xxxxy_1[i] * pc_x[i];

        ta1_z_xxyyy_xxxxz_0[i] = 2.0 * ta1_z_xxy_xxxxz_0[i] * fe_0 - 2.0 * ta1_z_xxy_xxxxz_1[i] * fe_0 + ta1_z_xxyy_xxxxz_0[i] * pa_y[i] - ta1_z_xxyy_xxxxz_1[i] * pc_y[i];

        ta1_z_xxyyy_xxxyy_0[i] = ta1_z_yyy_xxxyy_0[i] * fe_0 - ta1_z_yyy_xxxyy_1[i] * fe_0 + 3.0 * ta1_z_xyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_z_xyyy_xxyy_1[i] * fe_0 + ta1_z_xyyy_xxxyy_0[i] * pa_x[i] - ta1_z_xyyy_xxxyy_1[i] * pc_x[i];

        ta1_z_xxyyy_xxxyz_0[i] = ta1_z_yyy_xxxyz_0[i] * fe_0 - ta1_z_yyy_xxxyz_1[i] * fe_0 + 3.0 * ta1_z_xyyy_xxyz_0[i] * fe_0 - 3.0 * ta1_z_xyyy_xxyz_1[i] * fe_0 + ta1_z_xyyy_xxxyz_0[i] * pa_x[i] - ta1_z_xyyy_xxxyz_1[i] * pc_x[i];

        ta1_z_xxyyy_xxxzz_0[i] = 2.0 * ta1_z_xxy_xxxzz_0[i] * fe_0 - 2.0 * ta1_z_xxy_xxxzz_1[i] * fe_0 + ta1_z_xxyy_xxxzz_0[i] * pa_y[i] - ta1_z_xxyy_xxxzz_1[i] * pc_y[i];

        ta1_z_xxyyy_xxyyy_0[i] = ta1_z_yyy_xxyyy_0[i] * fe_0 - ta1_z_yyy_xxyyy_1[i] * fe_0 + 2.0 * ta1_z_xyyy_xyyy_0[i] * fe_0 - 2.0 * ta1_z_xyyy_xyyy_1[i] * fe_0 + ta1_z_xyyy_xxyyy_0[i] * pa_x[i] - ta1_z_xyyy_xxyyy_1[i] * pc_x[i];

        ta1_z_xxyyy_xxyyz_0[i] = ta1_z_yyy_xxyyz_0[i] * fe_0 - ta1_z_yyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_xyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xyyy_xyyz_1[i] * fe_0 + ta1_z_xyyy_xxyyz_0[i] * pa_x[i] - ta1_z_xyyy_xxyyz_1[i] * pc_x[i];

        ta1_z_xxyyy_xxyzz_0[i] = ta1_z_yyy_xxyzz_0[i] * fe_0 - ta1_z_yyy_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_xyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xyyy_xyzz_1[i] * fe_0 + ta1_z_xyyy_xxyzz_0[i] * pa_x[i] - ta1_z_xyyy_xxyzz_1[i] * pc_x[i];

        ta1_z_xxyyy_xxzzz_0[i] = 2.0 * ta1_z_xxy_xxzzz_0[i] * fe_0 - 2.0 * ta1_z_xxy_xxzzz_1[i] * fe_0 + ta1_z_xxyy_xxzzz_0[i] * pa_y[i] - ta1_z_xxyy_xxzzz_1[i] * pc_y[i];

        ta1_z_xxyyy_xyyyy_0[i] = ta1_z_yyy_xyyyy_0[i] * fe_0 - ta1_z_yyy_xyyyy_1[i] * fe_0 + ta1_z_xyyy_yyyy_0[i] * fe_0 - ta1_z_xyyy_yyyy_1[i] * fe_0 + ta1_z_xyyy_xyyyy_0[i] * pa_x[i] - ta1_z_xyyy_xyyyy_1[i] * pc_x[i];

        ta1_z_xxyyy_xyyyz_0[i] = ta1_z_yyy_xyyyz_0[i] * fe_0 - ta1_z_yyy_xyyyz_1[i] * fe_0 + ta1_z_xyyy_yyyz_0[i] * fe_0 - ta1_z_xyyy_yyyz_1[i] * fe_0 + ta1_z_xyyy_xyyyz_0[i] * pa_x[i] - ta1_z_xyyy_xyyyz_1[i] * pc_x[i];

        ta1_z_xxyyy_xyyzz_0[i] = ta1_z_yyy_xyyzz_0[i] * fe_0 - ta1_z_yyy_xyyzz_1[i] * fe_0 + ta1_z_xyyy_yyzz_0[i] * fe_0 - ta1_z_xyyy_yyzz_1[i] * fe_0 + ta1_z_xyyy_xyyzz_0[i] * pa_x[i] - ta1_z_xyyy_xyyzz_1[i] * pc_x[i];

        ta1_z_xxyyy_xyzzz_0[i] = ta1_z_yyy_xyzzz_0[i] * fe_0 - ta1_z_yyy_xyzzz_1[i] * fe_0 + ta1_z_xyyy_yzzz_0[i] * fe_0 - ta1_z_xyyy_yzzz_1[i] * fe_0 + ta1_z_xyyy_xyzzz_0[i] * pa_x[i] - ta1_z_xyyy_xyzzz_1[i] * pc_x[i];

        ta1_z_xxyyy_xzzzz_0[i] = 2.0 * ta1_z_xxy_xzzzz_0[i] * fe_0 - 2.0 * ta1_z_xxy_xzzzz_1[i] * fe_0 + ta1_z_xxyy_xzzzz_0[i] * pa_y[i] - ta1_z_xxyy_xzzzz_1[i] * pc_y[i];

        ta1_z_xxyyy_yyyyy_0[i] = ta1_z_yyy_yyyyy_0[i] * fe_0 - ta1_z_yyy_yyyyy_1[i] * fe_0 + ta1_z_xyyy_yyyyy_0[i] * pa_x[i] - ta1_z_xyyy_yyyyy_1[i] * pc_x[i];

        ta1_z_xxyyy_yyyyz_0[i] = ta1_z_yyy_yyyyz_0[i] * fe_0 - ta1_z_yyy_yyyyz_1[i] * fe_0 + ta1_z_xyyy_yyyyz_0[i] * pa_x[i] - ta1_z_xyyy_yyyyz_1[i] * pc_x[i];

        ta1_z_xxyyy_yyyzz_0[i] = ta1_z_yyy_yyyzz_0[i] * fe_0 - ta1_z_yyy_yyyzz_1[i] * fe_0 + ta1_z_xyyy_yyyzz_0[i] * pa_x[i] - ta1_z_xyyy_yyyzz_1[i] * pc_x[i];

        ta1_z_xxyyy_yyzzz_0[i] = ta1_z_yyy_yyzzz_0[i] * fe_0 - ta1_z_yyy_yyzzz_1[i] * fe_0 + ta1_z_xyyy_yyzzz_0[i] * pa_x[i] - ta1_z_xyyy_yyzzz_1[i] * pc_x[i];

        ta1_z_xxyyy_yzzzz_0[i] = ta1_z_yyy_yzzzz_0[i] * fe_0 - ta1_z_yyy_yzzzz_1[i] * fe_0 + ta1_z_xyyy_yzzzz_0[i] * pa_x[i] - ta1_z_xyyy_yzzzz_1[i] * pc_x[i];

        ta1_z_xxyyy_zzzzz_0[i] = ta1_z_yyy_zzzzz_0[i] * fe_0 - ta1_z_yyy_zzzzz_1[i] * fe_0 + ta1_z_xyyy_zzzzz_0[i] * pa_x[i] - ta1_z_xyyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1029-1050 components of targeted buffer : HH

    auto ta1_z_xxyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1029);

    auto ta1_z_xxyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1030);

    auto ta1_z_xxyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1031);

    auto ta1_z_xxyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1032);

    auto ta1_z_xxyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1033);

    auto ta1_z_xxyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1034);

    auto ta1_z_xxyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1035);

    auto ta1_z_xxyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1036);

    auto ta1_z_xxyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1037);

    auto ta1_z_xxyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1038);

    auto ta1_z_xxyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1039);

    auto ta1_z_xxyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1040);

    auto ta1_z_xxyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1041);

    auto ta1_z_xxyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1042);

    auto ta1_z_xxyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1043);

    auto ta1_z_xxyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1044);

    auto ta1_z_xxyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1045);

    auto ta1_z_xxyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1046);

    auto ta1_z_xxyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1047);

    auto ta1_z_xxyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1048);

    auto ta1_z_xxyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1049);

    #pragma omp simd aligned(pa_x, pa_y, pa_z, pc_x, pc_y, pc_z, ta1_z_xxyy_xxxxx_0, ta1_z_xxyy_xxxxx_1, ta1_z_xxyy_xxxxy_0, ta1_z_xxyy_xxxxy_1, ta1_z_xxyy_xxxy_0, ta1_z_xxyy_xxxy_1, ta1_z_xxyy_xxxyy_0, ta1_z_xxyy_xxxyy_1, ta1_z_xxyy_xxxyz_0, ta1_z_xxyy_xxxyz_1, ta1_z_xxyy_xxyy_0, ta1_z_xxyy_xxyy_1, ta1_z_xxyy_xxyyy_0, ta1_z_xxyy_xxyyy_1, ta1_z_xxyy_xxyyz_0, ta1_z_xxyy_xxyyz_1, ta1_z_xxyy_xxyz_0, ta1_z_xxyy_xxyz_1, ta1_z_xxyy_xxyzz_0, ta1_z_xxyy_xxyzz_1, ta1_z_xxyy_xyyy_0, ta1_z_xxyy_xyyy_1, ta1_z_xxyy_xyyyy_0, ta1_z_xxyy_xyyyy_1, ta1_z_xxyy_xyyyz_0, ta1_z_xxyy_xyyyz_1, ta1_z_xxyy_xyyz_0, ta1_z_xxyy_xyyz_1, ta1_z_xxyy_xyyzz_0, ta1_z_xxyy_xyyzz_1, ta1_z_xxyy_xyzz_0, ta1_z_xxyy_xyzz_1, ta1_z_xxyy_xyzzz_0, ta1_z_xxyy_xyzzz_1, ta1_z_xxyy_yyyyy_0, ta1_z_xxyy_yyyyy_1, ta1_z_xxyyz_xxxxx_0, ta1_z_xxyyz_xxxxy_0, ta1_z_xxyyz_xxxxz_0, ta1_z_xxyyz_xxxyy_0, ta1_z_xxyyz_xxxyz_0, ta1_z_xxyyz_xxxzz_0, ta1_z_xxyyz_xxyyy_0, ta1_z_xxyyz_xxyyz_0, ta1_z_xxyyz_xxyzz_0, ta1_z_xxyyz_xxzzz_0, ta1_z_xxyyz_xyyyy_0, ta1_z_xxyyz_xyyyz_0, ta1_z_xxyyz_xyyzz_0, ta1_z_xxyyz_xyzzz_0, ta1_z_xxyyz_xzzzz_0, ta1_z_xxyyz_yyyyy_0, ta1_z_xxyyz_yyyyz_0, ta1_z_xxyyz_yyyzz_0, ta1_z_xxyyz_yyzzz_0, ta1_z_xxyyz_yzzzz_0, ta1_z_xxyyz_zzzzz_0, ta1_z_xxyz_xxxxz_0, ta1_z_xxyz_xxxxz_1, ta1_z_xxyz_xxxzz_0, ta1_z_xxyz_xxxzz_1, ta1_z_xxyz_xxzzz_0, ta1_z_xxyz_xxzzz_1, ta1_z_xxyz_xzzzz_0, ta1_z_xxyz_xzzzz_1, ta1_z_xxz_xxxxz_0, ta1_z_xxz_xxxxz_1, ta1_z_xxz_xxxzz_0, ta1_z_xxz_xxxzz_1, ta1_z_xxz_xxzzz_0, ta1_z_xxz_xxzzz_1, ta1_z_xxz_xzzzz_0, ta1_z_xxz_xzzzz_1, ta1_z_xyyz_yyyyz_0, ta1_z_xyyz_yyyyz_1, ta1_z_xyyz_yyyzz_0, ta1_z_xyyz_yyyzz_1, ta1_z_xyyz_yyzzz_0, ta1_z_xyyz_yyzzz_1, ta1_z_xyyz_yzzzz_0, ta1_z_xyyz_yzzzz_1, ta1_z_xyyz_zzzzz_0, ta1_z_xyyz_zzzzz_1, ta1_z_yyz_yyyyz_0, ta1_z_yyz_yyyyz_1, ta1_z_yyz_yyyzz_0, ta1_z_yyz_yyyzz_1, ta1_z_yyz_yyzzz_0, ta1_z_yyz_yyzzz_1, ta1_z_yyz_yzzzz_0, ta1_z_yyz_yzzzz_1, ta1_z_yyz_zzzzz_0, ta1_z_yyz_zzzzz_1, ta_xxyy_xxxxx_1, ta_xxyy_xxxxy_1, ta_xxyy_xxxyy_1, ta_xxyy_xxxyz_1, ta_xxyy_xxyyy_1, ta_xxyy_xxyyz_1, ta_xxyy_xxyzz_1, ta_xxyy_xyyyy_1, ta_xxyy_xyyyz_1, ta_xxyy_xyyzz_1, ta_xxyy_xyzzz_1, ta_xxyy_yyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxyyz_xxxxx_0[i] = ta_xxyy_xxxxx_1[i] + ta1_z_xxyy_xxxxx_0[i] * pa_z[i] - ta1_z_xxyy_xxxxx_1[i] * pc_z[i];

        ta1_z_xxyyz_xxxxy_0[i] = ta_xxyy_xxxxy_1[i] + ta1_z_xxyy_xxxxy_0[i] * pa_z[i] - ta1_z_xxyy_xxxxy_1[i] * pc_z[i];

        ta1_z_xxyyz_xxxxz_0[i] = ta1_z_xxz_xxxxz_0[i] * fe_0 - ta1_z_xxz_xxxxz_1[i] * fe_0 + ta1_z_xxyz_xxxxz_0[i] * pa_y[i] - ta1_z_xxyz_xxxxz_1[i] * pc_y[i];

        ta1_z_xxyyz_xxxyy_0[i] = ta_xxyy_xxxyy_1[i] + ta1_z_xxyy_xxxyy_0[i] * pa_z[i] - ta1_z_xxyy_xxxyy_1[i] * pc_z[i];

        ta1_z_xxyyz_xxxyz_0[i] = ta1_z_xxyy_xxxy_0[i] * fe_0 - ta1_z_xxyy_xxxy_1[i] * fe_0 + ta_xxyy_xxxyz_1[i] + ta1_z_xxyy_xxxyz_0[i] * pa_z[i] - ta1_z_xxyy_xxxyz_1[i] * pc_z[i];

        ta1_z_xxyyz_xxxzz_0[i] = ta1_z_xxz_xxxzz_0[i] * fe_0 - ta1_z_xxz_xxxzz_1[i] * fe_0 + ta1_z_xxyz_xxxzz_0[i] * pa_y[i] - ta1_z_xxyz_xxxzz_1[i] * pc_y[i];

        ta1_z_xxyyz_xxyyy_0[i] = ta_xxyy_xxyyy_1[i] + ta1_z_xxyy_xxyyy_0[i] * pa_z[i] - ta1_z_xxyy_xxyyy_1[i] * pc_z[i];

        ta1_z_xxyyz_xxyyz_0[i] = ta1_z_xxyy_xxyy_0[i] * fe_0 - ta1_z_xxyy_xxyy_1[i] * fe_0 + ta_xxyy_xxyyz_1[i] + ta1_z_xxyy_xxyyz_0[i] * pa_z[i] - ta1_z_xxyy_xxyyz_1[i] * pc_z[i];

        ta1_z_xxyyz_xxyzz_0[i] = 2.0 * ta1_z_xxyy_xxyz_0[i] * fe_0 - 2.0 * ta1_z_xxyy_xxyz_1[i] * fe_0 + ta_xxyy_xxyzz_1[i] + ta1_z_xxyy_xxyzz_0[i] * pa_z[i] - ta1_z_xxyy_xxyzz_1[i] * pc_z[i];

        ta1_z_xxyyz_xxzzz_0[i] = ta1_z_xxz_xxzzz_0[i] * fe_0 - ta1_z_xxz_xxzzz_1[i] * fe_0 + ta1_z_xxyz_xxzzz_0[i] * pa_y[i] - ta1_z_xxyz_xxzzz_1[i] * pc_y[i];

        ta1_z_xxyyz_xyyyy_0[i] = ta_xxyy_xyyyy_1[i] + ta1_z_xxyy_xyyyy_0[i] * pa_z[i] - ta1_z_xxyy_xyyyy_1[i] * pc_z[i];

        ta1_z_xxyyz_xyyyz_0[i] = ta1_z_xxyy_xyyy_0[i] * fe_0 - ta1_z_xxyy_xyyy_1[i] * fe_0 + ta_xxyy_xyyyz_1[i] + ta1_z_xxyy_xyyyz_0[i] * pa_z[i] - ta1_z_xxyy_xyyyz_1[i] * pc_z[i];

        ta1_z_xxyyz_xyyzz_0[i] = 2.0 * ta1_z_xxyy_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xxyy_xyyz_1[i] * fe_0 + ta_xxyy_xyyzz_1[i] + ta1_z_xxyy_xyyzz_0[i] * pa_z[i] - ta1_z_xxyy_xyyzz_1[i] * pc_z[i];

        ta1_z_xxyyz_xyzzz_0[i] = 3.0 * ta1_z_xxyy_xyzz_0[i] * fe_0 - 3.0 * ta1_z_xxyy_xyzz_1[i] * fe_0 + ta_xxyy_xyzzz_1[i] + ta1_z_xxyy_xyzzz_0[i] * pa_z[i] - ta1_z_xxyy_xyzzz_1[i] * pc_z[i];

        ta1_z_xxyyz_xzzzz_0[i] = ta1_z_xxz_xzzzz_0[i] * fe_0 - ta1_z_xxz_xzzzz_1[i] * fe_0 + ta1_z_xxyz_xzzzz_0[i] * pa_y[i] - ta1_z_xxyz_xzzzz_1[i] * pc_y[i];

        ta1_z_xxyyz_yyyyy_0[i] = ta_xxyy_yyyyy_1[i] + ta1_z_xxyy_yyyyy_0[i] * pa_z[i] - ta1_z_xxyy_yyyyy_1[i] * pc_z[i];

        ta1_z_xxyyz_yyyyz_0[i] = ta1_z_yyz_yyyyz_0[i] * fe_0 - ta1_z_yyz_yyyyz_1[i] * fe_0 + ta1_z_xyyz_yyyyz_0[i] * pa_x[i] - ta1_z_xyyz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxyyz_yyyzz_0[i] = ta1_z_yyz_yyyzz_0[i] * fe_0 - ta1_z_yyz_yyyzz_1[i] * fe_0 + ta1_z_xyyz_yyyzz_0[i] * pa_x[i] - ta1_z_xyyz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxyyz_yyzzz_0[i] = ta1_z_yyz_yyzzz_0[i] * fe_0 - ta1_z_yyz_yyzzz_1[i] * fe_0 + ta1_z_xyyz_yyzzz_0[i] * pa_x[i] - ta1_z_xyyz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxyyz_yzzzz_0[i] = ta1_z_yyz_yzzzz_0[i] * fe_0 - ta1_z_yyz_yzzzz_1[i] * fe_0 + ta1_z_xyyz_yzzzz_0[i] * pa_x[i] - ta1_z_xyyz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxyyz_zzzzz_0[i] = ta1_z_yyz_zzzzz_0[i] * fe_0 - ta1_z_yyz_zzzzz_1[i] * fe_0 + ta1_z_xyyz_zzzzz_0[i] * pa_x[i] - ta1_z_xyyz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1050-1071 components of targeted buffer : HH

    auto ta1_z_xxyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1050);

    auto ta1_z_xxyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1051);

    auto ta1_z_xxyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1052);

    auto ta1_z_xxyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1053);

    auto ta1_z_xxyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1054);

    auto ta1_z_xxyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1055);

    auto ta1_z_xxyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1056);

    auto ta1_z_xxyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1057);

    auto ta1_z_xxyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1058);

    auto ta1_z_xxyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1059);

    auto ta1_z_xxyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1060);

    auto ta1_z_xxyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1061);

    auto ta1_z_xxyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1062);

    auto ta1_z_xxyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1063);

    auto ta1_z_xxyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1064);

    auto ta1_z_xxyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1065);

    auto ta1_z_xxyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1066);

    auto ta1_z_xxyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1067);

    auto ta1_z_xxyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1068);

    auto ta1_z_xxyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1069);

    auto ta1_z_xxyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1070);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_z_xxyzz_xxxxx_0, ta1_z_xxyzz_xxxxy_0, ta1_z_xxyzz_xxxxz_0, ta1_z_xxyzz_xxxyy_0, ta1_z_xxyzz_xxxyz_0, ta1_z_xxyzz_xxxzz_0, ta1_z_xxyzz_xxyyy_0, ta1_z_xxyzz_xxyyz_0, ta1_z_xxyzz_xxyzz_0, ta1_z_xxyzz_xxzzz_0, ta1_z_xxyzz_xyyyy_0, ta1_z_xxyzz_xyyyz_0, ta1_z_xxyzz_xyyzz_0, ta1_z_xxyzz_xyzzz_0, ta1_z_xxyzz_xzzzz_0, ta1_z_xxyzz_yyyyy_0, ta1_z_xxyzz_yyyyz_0, ta1_z_xxyzz_yyyzz_0, ta1_z_xxyzz_yyzzz_0, ta1_z_xxyzz_yzzzz_0, ta1_z_xxyzz_zzzzz_0, ta1_z_xxzz_xxxx_0, ta1_z_xxzz_xxxx_1, ta1_z_xxzz_xxxxx_0, ta1_z_xxzz_xxxxx_1, ta1_z_xxzz_xxxxy_0, ta1_z_xxzz_xxxxy_1, ta1_z_xxzz_xxxxz_0, ta1_z_xxzz_xxxxz_1, ta1_z_xxzz_xxxy_0, ta1_z_xxzz_xxxy_1, ta1_z_xxzz_xxxyy_0, ta1_z_xxzz_xxxyy_1, ta1_z_xxzz_xxxyz_0, ta1_z_xxzz_xxxyz_1, ta1_z_xxzz_xxxz_0, ta1_z_xxzz_xxxz_1, ta1_z_xxzz_xxxzz_0, ta1_z_xxzz_xxxzz_1, ta1_z_xxzz_xxyy_0, ta1_z_xxzz_xxyy_1, ta1_z_xxzz_xxyyy_0, ta1_z_xxzz_xxyyy_1, ta1_z_xxzz_xxyyz_0, ta1_z_xxzz_xxyyz_1, ta1_z_xxzz_xxyz_0, ta1_z_xxzz_xxyz_1, ta1_z_xxzz_xxyzz_0, ta1_z_xxzz_xxyzz_1, ta1_z_xxzz_xxzz_0, ta1_z_xxzz_xxzz_1, ta1_z_xxzz_xxzzz_0, ta1_z_xxzz_xxzzz_1, ta1_z_xxzz_xyyy_0, ta1_z_xxzz_xyyy_1, ta1_z_xxzz_xyyyy_0, ta1_z_xxzz_xyyyy_1, ta1_z_xxzz_xyyyz_0, ta1_z_xxzz_xyyyz_1, ta1_z_xxzz_xyyz_0, ta1_z_xxzz_xyyz_1, ta1_z_xxzz_xyyzz_0, ta1_z_xxzz_xyyzz_1, ta1_z_xxzz_xyzz_0, ta1_z_xxzz_xyzz_1, ta1_z_xxzz_xyzzz_0, ta1_z_xxzz_xyzzz_1, ta1_z_xxzz_xzzz_0, ta1_z_xxzz_xzzz_1, ta1_z_xxzz_xzzzz_0, ta1_z_xxzz_xzzzz_1, ta1_z_xxzz_zzzzz_0, ta1_z_xxzz_zzzzz_1, ta1_z_xyzz_yyyyy_0, ta1_z_xyzz_yyyyy_1, ta1_z_xyzz_yyyyz_0, ta1_z_xyzz_yyyyz_1, ta1_z_xyzz_yyyzz_0, ta1_z_xyzz_yyyzz_1, ta1_z_xyzz_yyzzz_0, ta1_z_xyzz_yyzzz_1, ta1_z_xyzz_yzzzz_0, ta1_z_xyzz_yzzzz_1, ta1_z_yzz_yyyyy_0, ta1_z_yzz_yyyyy_1, ta1_z_yzz_yyyyz_0, ta1_z_yzz_yyyyz_1, ta1_z_yzz_yyyzz_0, ta1_z_yzz_yyyzz_1, ta1_z_yzz_yyzzz_0, ta1_z_yzz_yyzzz_1, ta1_z_yzz_yzzzz_0, ta1_z_yzz_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxyzz_xxxxx_0[i] = ta1_z_xxzz_xxxxx_0[i] * pa_y[i] - ta1_z_xxzz_xxxxx_1[i] * pc_y[i];

        ta1_z_xxyzz_xxxxy_0[i] = ta1_z_xxzz_xxxx_0[i] * fe_0 - ta1_z_xxzz_xxxx_1[i] * fe_0 + ta1_z_xxzz_xxxxy_0[i] * pa_y[i] - ta1_z_xxzz_xxxxy_1[i] * pc_y[i];

        ta1_z_xxyzz_xxxxz_0[i] = ta1_z_xxzz_xxxxz_0[i] * pa_y[i] - ta1_z_xxzz_xxxxz_1[i] * pc_y[i];

        ta1_z_xxyzz_xxxyy_0[i] = 2.0 * ta1_z_xxzz_xxxy_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xxxy_1[i] * fe_0 + ta1_z_xxzz_xxxyy_0[i] * pa_y[i] - ta1_z_xxzz_xxxyy_1[i] * pc_y[i];

        ta1_z_xxyzz_xxxyz_0[i] = ta1_z_xxzz_xxxz_0[i] * fe_0 - ta1_z_xxzz_xxxz_1[i] * fe_0 + ta1_z_xxzz_xxxyz_0[i] * pa_y[i] - ta1_z_xxzz_xxxyz_1[i] * pc_y[i];

        ta1_z_xxyzz_xxxzz_0[i] = ta1_z_xxzz_xxxzz_0[i] * pa_y[i] - ta1_z_xxzz_xxxzz_1[i] * pc_y[i];

        ta1_z_xxyzz_xxyyy_0[i] = 3.0 * ta1_z_xxzz_xxyy_0[i] * fe_0 - 3.0 * ta1_z_xxzz_xxyy_1[i] * fe_0 + ta1_z_xxzz_xxyyy_0[i] * pa_y[i] - ta1_z_xxzz_xxyyy_1[i] * pc_y[i];

        ta1_z_xxyzz_xxyyz_0[i] = 2.0 * ta1_z_xxzz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xxyz_1[i] * fe_0 + ta1_z_xxzz_xxyyz_0[i] * pa_y[i] - ta1_z_xxzz_xxyyz_1[i] * pc_y[i];

        ta1_z_xxyzz_xxyzz_0[i] = ta1_z_xxzz_xxzz_0[i] * fe_0 - ta1_z_xxzz_xxzz_1[i] * fe_0 + ta1_z_xxzz_xxyzz_0[i] * pa_y[i] - ta1_z_xxzz_xxyzz_1[i] * pc_y[i];

        ta1_z_xxyzz_xxzzz_0[i] = ta1_z_xxzz_xxzzz_0[i] * pa_y[i] - ta1_z_xxzz_xxzzz_1[i] * pc_y[i];

        ta1_z_xxyzz_xyyyy_0[i] = 4.0 * ta1_z_xxzz_xyyy_0[i] * fe_0 - 4.0 * ta1_z_xxzz_xyyy_1[i] * fe_0 + ta1_z_xxzz_xyyyy_0[i] * pa_y[i] - ta1_z_xxzz_xyyyy_1[i] * pc_y[i];

        ta1_z_xxyzz_xyyyz_0[i] = 3.0 * ta1_z_xxzz_xyyz_0[i] * fe_0 - 3.0 * ta1_z_xxzz_xyyz_1[i] * fe_0 + ta1_z_xxzz_xyyyz_0[i] * pa_y[i] - ta1_z_xxzz_xyyyz_1[i] * pc_y[i];

        ta1_z_xxyzz_xyyzz_0[i] = 2.0 * ta1_z_xxzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xxzz_xyzz_1[i] * fe_0 + ta1_z_xxzz_xyyzz_0[i] * pa_y[i] - ta1_z_xxzz_xyyzz_1[i] * pc_y[i];

        ta1_z_xxyzz_xyzzz_0[i] = ta1_z_xxzz_xzzz_0[i] * fe_0 - ta1_z_xxzz_xzzz_1[i] * fe_0 + ta1_z_xxzz_xyzzz_0[i] * pa_y[i] - ta1_z_xxzz_xyzzz_1[i] * pc_y[i];

        ta1_z_xxyzz_xzzzz_0[i] = ta1_z_xxzz_xzzzz_0[i] * pa_y[i] - ta1_z_xxzz_xzzzz_1[i] * pc_y[i];

        ta1_z_xxyzz_yyyyy_0[i] = ta1_z_yzz_yyyyy_0[i] * fe_0 - ta1_z_yzz_yyyyy_1[i] * fe_0 + ta1_z_xyzz_yyyyy_0[i] * pa_x[i] - ta1_z_xyzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xxyzz_yyyyz_0[i] = ta1_z_yzz_yyyyz_0[i] * fe_0 - ta1_z_yzz_yyyyz_1[i] * fe_0 + ta1_z_xyzz_yyyyz_0[i] * pa_x[i] - ta1_z_xyzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxyzz_yyyzz_0[i] = ta1_z_yzz_yyyzz_0[i] * fe_0 - ta1_z_yzz_yyyzz_1[i] * fe_0 + ta1_z_xyzz_yyyzz_0[i] * pa_x[i] - ta1_z_xyzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxyzz_yyzzz_0[i] = ta1_z_yzz_yyzzz_0[i] * fe_0 - ta1_z_yzz_yyzzz_1[i] * fe_0 + ta1_z_xyzz_yyzzz_0[i] * pa_x[i] - ta1_z_xyzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxyzz_yzzzz_0[i] = ta1_z_yzz_yzzzz_0[i] * fe_0 - ta1_z_yzz_yzzzz_1[i] * fe_0 + ta1_z_xyzz_yzzzz_0[i] * pa_x[i] - ta1_z_xyzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxyzz_zzzzz_0[i] = ta1_z_xxzz_zzzzz_0[i] * pa_y[i] - ta1_z_xxzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1071-1092 components of targeted buffer : HH

    auto ta1_z_xxzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1071);

    auto ta1_z_xxzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1072);

    auto ta1_z_xxzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1073);

    auto ta1_z_xxzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1074);

    auto ta1_z_xxzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1075);

    auto ta1_z_xxzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1076);

    auto ta1_z_xxzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1077);

    auto ta1_z_xxzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1078);

    auto ta1_z_xxzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1079);

    auto ta1_z_xxzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1080);

    auto ta1_z_xxzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1081);

    auto ta1_z_xxzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1082);

    auto ta1_z_xxzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1083);

    auto ta1_z_xxzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1084);

    auto ta1_z_xxzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1085);

    auto ta1_z_xxzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1086);

    auto ta1_z_xxzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1087);

    auto ta1_z_xxzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1088);

    auto ta1_z_xxzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1089);

    auto ta1_z_xxzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1090);

    auto ta1_z_xxzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1091);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_z_xxz_xxxxx_0, ta1_z_xxz_xxxxx_1, ta1_z_xxz_xxxxy_0, ta1_z_xxz_xxxxy_1, ta1_z_xxz_xxxyy_0, ta1_z_xxz_xxxyy_1, ta1_z_xxz_xxyyy_0, ta1_z_xxz_xxyyy_1, ta1_z_xxz_xyyyy_0, ta1_z_xxz_xyyyy_1, ta1_z_xxzz_xxxxx_0, ta1_z_xxzz_xxxxx_1, ta1_z_xxzz_xxxxy_0, ta1_z_xxzz_xxxxy_1, ta1_z_xxzz_xxxyy_0, ta1_z_xxzz_xxxyy_1, ta1_z_xxzz_xxyyy_0, ta1_z_xxzz_xxyyy_1, ta1_z_xxzz_xyyyy_0, ta1_z_xxzz_xyyyy_1, ta1_z_xxzzz_xxxxx_0, ta1_z_xxzzz_xxxxy_0, ta1_z_xxzzz_xxxxz_0, ta1_z_xxzzz_xxxyy_0, ta1_z_xxzzz_xxxyz_0, ta1_z_xxzzz_xxxzz_0, ta1_z_xxzzz_xxyyy_0, ta1_z_xxzzz_xxyyz_0, ta1_z_xxzzz_xxyzz_0, ta1_z_xxzzz_xxzzz_0, ta1_z_xxzzz_xyyyy_0, ta1_z_xxzzz_xyyyz_0, ta1_z_xxzzz_xyyzz_0, ta1_z_xxzzz_xyzzz_0, ta1_z_xxzzz_xzzzz_0, ta1_z_xxzzz_yyyyy_0, ta1_z_xxzzz_yyyyz_0, ta1_z_xxzzz_yyyzz_0, ta1_z_xxzzz_yyzzz_0, ta1_z_xxzzz_yzzzz_0, ta1_z_xxzzz_zzzzz_0, ta1_z_xzzz_xxxxz_0, ta1_z_xzzz_xxxxz_1, ta1_z_xzzz_xxxyz_0, ta1_z_xzzz_xxxyz_1, ta1_z_xzzz_xxxz_0, ta1_z_xzzz_xxxz_1, ta1_z_xzzz_xxxzz_0, ta1_z_xzzz_xxxzz_1, ta1_z_xzzz_xxyyz_0, ta1_z_xzzz_xxyyz_1, ta1_z_xzzz_xxyz_0, ta1_z_xzzz_xxyz_1, ta1_z_xzzz_xxyzz_0, ta1_z_xzzz_xxyzz_1, ta1_z_xzzz_xxzz_0, ta1_z_xzzz_xxzz_1, ta1_z_xzzz_xxzzz_0, ta1_z_xzzz_xxzzz_1, ta1_z_xzzz_xyyyz_0, ta1_z_xzzz_xyyyz_1, ta1_z_xzzz_xyyz_0, ta1_z_xzzz_xyyz_1, ta1_z_xzzz_xyyzz_0, ta1_z_xzzz_xyyzz_1, ta1_z_xzzz_xyzz_0, ta1_z_xzzz_xyzz_1, ta1_z_xzzz_xyzzz_0, ta1_z_xzzz_xyzzz_1, ta1_z_xzzz_xzzz_0, ta1_z_xzzz_xzzz_1, ta1_z_xzzz_xzzzz_0, ta1_z_xzzz_xzzzz_1, ta1_z_xzzz_yyyyy_0, ta1_z_xzzz_yyyyy_1, ta1_z_xzzz_yyyyz_0, ta1_z_xzzz_yyyyz_1, ta1_z_xzzz_yyyz_0, ta1_z_xzzz_yyyz_1, ta1_z_xzzz_yyyzz_0, ta1_z_xzzz_yyyzz_1, ta1_z_xzzz_yyzz_0, ta1_z_xzzz_yyzz_1, ta1_z_xzzz_yyzzz_0, ta1_z_xzzz_yyzzz_1, ta1_z_xzzz_yzzz_0, ta1_z_xzzz_yzzz_1, ta1_z_xzzz_yzzzz_0, ta1_z_xzzz_yzzzz_1, ta1_z_xzzz_zzzz_0, ta1_z_xzzz_zzzz_1, ta1_z_xzzz_zzzzz_0, ta1_z_xzzz_zzzzz_1, ta1_z_zzz_xxxxz_0, ta1_z_zzz_xxxxz_1, ta1_z_zzz_xxxyz_0, ta1_z_zzz_xxxyz_1, ta1_z_zzz_xxxzz_0, ta1_z_zzz_xxxzz_1, ta1_z_zzz_xxyyz_0, ta1_z_zzz_xxyyz_1, ta1_z_zzz_xxyzz_0, ta1_z_zzz_xxyzz_1, ta1_z_zzz_xxzzz_0, ta1_z_zzz_xxzzz_1, ta1_z_zzz_xyyyz_0, ta1_z_zzz_xyyyz_1, ta1_z_zzz_xyyzz_0, ta1_z_zzz_xyyzz_1, ta1_z_zzz_xyzzz_0, ta1_z_zzz_xyzzz_1, ta1_z_zzz_xzzzz_0, ta1_z_zzz_xzzzz_1, ta1_z_zzz_yyyyy_0, ta1_z_zzz_yyyyy_1, ta1_z_zzz_yyyyz_0, ta1_z_zzz_yyyyz_1, ta1_z_zzz_yyyzz_0, ta1_z_zzz_yyyzz_1, ta1_z_zzz_yyzzz_0, ta1_z_zzz_yyzzz_1, ta1_z_zzz_yzzzz_0, ta1_z_zzz_yzzzz_1, ta1_z_zzz_zzzzz_0, ta1_z_zzz_zzzzz_1, ta_xxzz_xxxxx_1, ta_xxzz_xxxxy_1, ta_xxzz_xxxyy_1, ta_xxzz_xxyyy_1, ta_xxzz_xyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xxzzz_xxxxx_0[i] = 2.0 * ta1_z_xxz_xxxxx_0[i] * fe_0 - 2.0 * ta1_z_xxz_xxxxx_1[i] * fe_0 + ta_xxzz_xxxxx_1[i] + ta1_z_xxzz_xxxxx_0[i] * pa_z[i] - ta1_z_xxzz_xxxxx_1[i] * pc_z[i];

        ta1_z_xxzzz_xxxxy_0[i] = 2.0 * ta1_z_xxz_xxxxy_0[i] * fe_0 - 2.0 * ta1_z_xxz_xxxxy_1[i] * fe_0 + ta_xxzz_xxxxy_1[i] + ta1_z_xxzz_xxxxy_0[i] * pa_z[i] - ta1_z_xxzz_xxxxy_1[i] * pc_z[i];

        ta1_z_xxzzz_xxxxz_0[i] = ta1_z_zzz_xxxxz_0[i] * fe_0 - ta1_z_zzz_xxxxz_1[i] * fe_0 + 4.0 * ta1_z_xzzz_xxxz_0[i] * fe_0 - 4.0 * ta1_z_xzzz_xxxz_1[i] * fe_0 + ta1_z_xzzz_xxxxz_0[i] * pa_x[i] - ta1_z_xzzz_xxxxz_1[i] * pc_x[i];

        ta1_z_xxzzz_xxxyy_0[i] = 2.0 * ta1_z_xxz_xxxyy_0[i] * fe_0 - 2.0 * ta1_z_xxz_xxxyy_1[i] * fe_0 + ta_xxzz_xxxyy_1[i] + ta1_z_xxzz_xxxyy_0[i] * pa_z[i] - ta1_z_xxzz_xxxyy_1[i] * pc_z[i];

        ta1_z_xxzzz_xxxyz_0[i] = ta1_z_zzz_xxxyz_0[i] * fe_0 - ta1_z_zzz_xxxyz_1[i] * fe_0 + 3.0 * ta1_z_xzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_xzzz_xxyz_1[i] * fe_0 + ta1_z_xzzz_xxxyz_0[i] * pa_x[i] - ta1_z_xzzz_xxxyz_1[i] * pc_x[i];

        ta1_z_xxzzz_xxxzz_0[i] = ta1_z_zzz_xxxzz_0[i] * fe_0 - ta1_z_zzz_xxxzz_1[i] * fe_0 + 3.0 * ta1_z_xzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_xzzz_xxzz_1[i] * fe_0 + ta1_z_xzzz_xxxzz_0[i] * pa_x[i] - ta1_z_xzzz_xxxzz_1[i] * pc_x[i];

        ta1_z_xxzzz_xxyyy_0[i] = 2.0 * ta1_z_xxz_xxyyy_0[i] * fe_0 - 2.0 * ta1_z_xxz_xxyyy_1[i] * fe_0 + ta_xxzz_xxyyy_1[i] + ta1_z_xxzz_xxyyy_0[i] * pa_z[i] - ta1_z_xxzz_xxyyy_1[i] * pc_z[i];

        ta1_z_xxzzz_xxyyz_0[i] = ta1_z_zzz_xxyyz_0[i] * fe_0 - ta1_z_zzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_xzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_xzzz_xyyz_1[i] * fe_0 + ta1_z_xzzz_xxyyz_0[i] * pa_x[i] - ta1_z_xzzz_xxyyz_1[i] * pc_x[i];

        ta1_z_xxzzz_xxyzz_0[i] = ta1_z_zzz_xxyzz_0[i] * fe_0 - ta1_z_zzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_xzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_xzzz_xyzz_1[i] * fe_0 + ta1_z_xzzz_xxyzz_0[i] * pa_x[i] - ta1_z_xzzz_xxyzz_1[i] * pc_x[i];

        ta1_z_xxzzz_xxzzz_0[i] = ta1_z_zzz_xxzzz_0[i] * fe_0 - ta1_z_zzz_xxzzz_1[i] * fe_0 + 2.0 * ta1_z_xzzz_xzzz_0[i] * fe_0 - 2.0 * ta1_z_xzzz_xzzz_1[i] * fe_0 + ta1_z_xzzz_xxzzz_0[i] * pa_x[i] - ta1_z_xzzz_xxzzz_1[i] * pc_x[i];

        ta1_z_xxzzz_xyyyy_0[i] = 2.0 * ta1_z_xxz_xyyyy_0[i] * fe_0 - 2.0 * ta1_z_xxz_xyyyy_1[i] * fe_0 + ta_xxzz_xyyyy_1[i] + ta1_z_xxzz_xyyyy_0[i] * pa_z[i] - ta1_z_xxzz_xyyyy_1[i] * pc_z[i];

        ta1_z_xxzzz_xyyyz_0[i] = ta1_z_zzz_xyyyz_0[i] * fe_0 - ta1_z_zzz_xyyyz_1[i] * fe_0 + ta1_z_xzzz_yyyz_0[i] * fe_0 - ta1_z_xzzz_yyyz_1[i] * fe_0 + ta1_z_xzzz_xyyyz_0[i] * pa_x[i] - ta1_z_xzzz_xyyyz_1[i] * pc_x[i];

        ta1_z_xxzzz_xyyzz_0[i] = ta1_z_zzz_xyyzz_0[i] * fe_0 - ta1_z_zzz_xyyzz_1[i] * fe_0 + ta1_z_xzzz_yyzz_0[i] * fe_0 - ta1_z_xzzz_yyzz_1[i] * fe_0 + ta1_z_xzzz_xyyzz_0[i] * pa_x[i] - ta1_z_xzzz_xyyzz_1[i] * pc_x[i];

        ta1_z_xxzzz_xyzzz_0[i] = ta1_z_zzz_xyzzz_0[i] * fe_0 - ta1_z_zzz_xyzzz_1[i] * fe_0 + ta1_z_xzzz_yzzz_0[i] * fe_0 - ta1_z_xzzz_yzzz_1[i] * fe_0 + ta1_z_xzzz_xyzzz_0[i] * pa_x[i] - ta1_z_xzzz_xyzzz_1[i] * pc_x[i];

        ta1_z_xxzzz_xzzzz_0[i] = ta1_z_zzz_xzzzz_0[i] * fe_0 - ta1_z_zzz_xzzzz_1[i] * fe_0 + ta1_z_xzzz_zzzz_0[i] * fe_0 - ta1_z_xzzz_zzzz_1[i] * fe_0 + ta1_z_xzzz_xzzzz_0[i] * pa_x[i] - ta1_z_xzzz_xzzzz_1[i] * pc_x[i];

        ta1_z_xxzzz_yyyyy_0[i] = ta1_z_zzz_yyyyy_0[i] * fe_0 - ta1_z_zzz_yyyyy_1[i] * fe_0 + ta1_z_xzzz_yyyyy_0[i] * pa_x[i] - ta1_z_xzzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xxzzz_yyyyz_0[i] = ta1_z_zzz_yyyyz_0[i] * fe_0 - ta1_z_zzz_yyyyz_1[i] * fe_0 + ta1_z_xzzz_yyyyz_0[i] * pa_x[i] - ta1_z_xzzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xxzzz_yyyzz_0[i] = ta1_z_zzz_yyyzz_0[i] * fe_0 - ta1_z_zzz_yyyzz_1[i] * fe_0 + ta1_z_xzzz_yyyzz_0[i] * pa_x[i] - ta1_z_xzzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xxzzz_yyzzz_0[i] = ta1_z_zzz_yyzzz_0[i] * fe_0 - ta1_z_zzz_yyzzz_1[i] * fe_0 + ta1_z_xzzz_yyzzz_0[i] * pa_x[i] - ta1_z_xzzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xxzzz_yzzzz_0[i] = ta1_z_zzz_yzzzz_0[i] * fe_0 - ta1_z_zzz_yzzzz_1[i] * fe_0 + ta1_z_xzzz_yzzzz_0[i] * pa_x[i] - ta1_z_xzzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xxzzz_zzzzz_0[i] = ta1_z_zzz_zzzzz_0[i] * fe_0 - ta1_z_zzz_zzzzz_1[i] * fe_0 + ta1_z_xzzz_zzzzz_0[i] * pa_x[i] - ta1_z_xzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1092-1113 components of targeted buffer : HH

    auto ta1_z_xyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1092);

    auto ta1_z_xyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1093);

    auto ta1_z_xyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1094);

    auto ta1_z_xyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1095);

    auto ta1_z_xyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1096);

    auto ta1_z_xyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1097);

    auto ta1_z_xyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1098);

    auto ta1_z_xyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1099);

    auto ta1_z_xyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1100);

    auto ta1_z_xyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1101);

    auto ta1_z_xyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1102);

    auto ta1_z_xyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1103);

    auto ta1_z_xyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1104);

    auto ta1_z_xyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1105);

    auto ta1_z_xyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1106);

    auto ta1_z_xyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1107);

    auto ta1_z_xyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1108);

    auto ta1_z_xyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1109);

    auto ta1_z_xyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1110);

    auto ta1_z_xyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1111);

    auto ta1_z_xyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1112);

    #pragma omp simd aligned(pa_x, pc_x, ta1_z_xyyyy_xxxxx_0, ta1_z_xyyyy_xxxxy_0, ta1_z_xyyyy_xxxxz_0, ta1_z_xyyyy_xxxyy_0, ta1_z_xyyyy_xxxyz_0, ta1_z_xyyyy_xxxzz_0, ta1_z_xyyyy_xxyyy_0, ta1_z_xyyyy_xxyyz_0, ta1_z_xyyyy_xxyzz_0, ta1_z_xyyyy_xxzzz_0, ta1_z_xyyyy_xyyyy_0, ta1_z_xyyyy_xyyyz_0, ta1_z_xyyyy_xyyzz_0, ta1_z_xyyyy_xyzzz_0, ta1_z_xyyyy_xzzzz_0, ta1_z_xyyyy_yyyyy_0, ta1_z_xyyyy_yyyyz_0, ta1_z_xyyyy_yyyzz_0, ta1_z_xyyyy_yyzzz_0, ta1_z_xyyyy_yzzzz_0, ta1_z_xyyyy_zzzzz_0, ta1_z_yyyy_xxxx_0, ta1_z_yyyy_xxxx_1, ta1_z_yyyy_xxxxx_0, ta1_z_yyyy_xxxxx_1, ta1_z_yyyy_xxxxy_0, ta1_z_yyyy_xxxxy_1, ta1_z_yyyy_xxxxz_0, ta1_z_yyyy_xxxxz_1, ta1_z_yyyy_xxxy_0, ta1_z_yyyy_xxxy_1, ta1_z_yyyy_xxxyy_0, ta1_z_yyyy_xxxyy_1, ta1_z_yyyy_xxxyz_0, ta1_z_yyyy_xxxyz_1, ta1_z_yyyy_xxxz_0, ta1_z_yyyy_xxxz_1, ta1_z_yyyy_xxxzz_0, ta1_z_yyyy_xxxzz_1, ta1_z_yyyy_xxyy_0, ta1_z_yyyy_xxyy_1, ta1_z_yyyy_xxyyy_0, ta1_z_yyyy_xxyyy_1, ta1_z_yyyy_xxyyz_0, ta1_z_yyyy_xxyyz_1, ta1_z_yyyy_xxyz_0, ta1_z_yyyy_xxyz_1, ta1_z_yyyy_xxyzz_0, ta1_z_yyyy_xxyzz_1, ta1_z_yyyy_xxzz_0, ta1_z_yyyy_xxzz_1, ta1_z_yyyy_xxzzz_0, ta1_z_yyyy_xxzzz_1, ta1_z_yyyy_xyyy_0, ta1_z_yyyy_xyyy_1, ta1_z_yyyy_xyyyy_0, ta1_z_yyyy_xyyyy_1, ta1_z_yyyy_xyyyz_0, ta1_z_yyyy_xyyyz_1, ta1_z_yyyy_xyyz_0, ta1_z_yyyy_xyyz_1, ta1_z_yyyy_xyyzz_0, ta1_z_yyyy_xyyzz_1, ta1_z_yyyy_xyzz_0, ta1_z_yyyy_xyzz_1, ta1_z_yyyy_xyzzz_0, ta1_z_yyyy_xyzzz_1, ta1_z_yyyy_xzzz_0, ta1_z_yyyy_xzzz_1, ta1_z_yyyy_xzzzz_0, ta1_z_yyyy_xzzzz_1, ta1_z_yyyy_yyyy_0, ta1_z_yyyy_yyyy_1, ta1_z_yyyy_yyyyy_0, ta1_z_yyyy_yyyyy_1, ta1_z_yyyy_yyyyz_0, ta1_z_yyyy_yyyyz_1, ta1_z_yyyy_yyyz_0, ta1_z_yyyy_yyyz_1, ta1_z_yyyy_yyyzz_0, ta1_z_yyyy_yyyzz_1, ta1_z_yyyy_yyzz_0, ta1_z_yyyy_yyzz_1, ta1_z_yyyy_yyzzz_0, ta1_z_yyyy_yyzzz_1, ta1_z_yyyy_yzzz_0, ta1_z_yyyy_yzzz_1, ta1_z_yyyy_yzzzz_0, ta1_z_yyyy_yzzzz_1, ta1_z_yyyy_zzzz_0, ta1_z_yyyy_zzzz_1, ta1_z_yyyy_zzzzz_0, ta1_z_yyyy_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xyyyy_xxxxx_0[i] = 5.0 * ta1_z_yyyy_xxxx_0[i] * fe_0 - 5.0 * ta1_z_yyyy_xxxx_1[i] * fe_0 + ta1_z_yyyy_xxxxx_0[i] * pa_x[i] - ta1_z_yyyy_xxxxx_1[i] * pc_x[i];

        ta1_z_xyyyy_xxxxy_0[i] = 4.0 * ta1_z_yyyy_xxxy_0[i] * fe_0 - 4.0 * ta1_z_yyyy_xxxy_1[i] * fe_0 + ta1_z_yyyy_xxxxy_0[i] * pa_x[i] - ta1_z_yyyy_xxxxy_1[i] * pc_x[i];

        ta1_z_xyyyy_xxxxz_0[i] = 4.0 * ta1_z_yyyy_xxxz_0[i] * fe_0 - 4.0 * ta1_z_yyyy_xxxz_1[i] * fe_0 + ta1_z_yyyy_xxxxz_0[i] * pa_x[i] - ta1_z_yyyy_xxxxz_1[i] * pc_x[i];

        ta1_z_xyyyy_xxxyy_0[i] = 3.0 * ta1_z_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xxyy_1[i] * fe_0 + ta1_z_yyyy_xxxyy_0[i] * pa_x[i] - ta1_z_yyyy_xxxyy_1[i] * pc_x[i];

        ta1_z_xyyyy_xxxyz_0[i] = 3.0 * ta1_z_yyyy_xxyz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xxyz_1[i] * fe_0 + ta1_z_yyyy_xxxyz_0[i] * pa_x[i] - ta1_z_yyyy_xxxyz_1[i] * pc_x[i];

        ta1_z_xyyyy_xxxzz_0[i] = 3.0 * ta1_z_yyyy_xxzz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xxzz_1[i] * fe_0 + ta1_z_yyyy_xxxzz_0[i] * pa_x[i] - ta1_z_yyyy_xxxzz_1[i] * pc_x[i];

        ta1_z_xyyyy_xxyyy_0[i] = 2.0 * ta1_z_yyyy_xyyy_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xyyy_1[i] * fe_0 + ta1_z_yyyy_xxyyy_0[i] * pa_x[i] - ta1_z_yyyy_xxyyy_1[i] * pc_x[i];

        ta1_z_xyyyy_xxyyz_0[i] = 2.0 * ta1_z_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xyyz_1[i] * fe_0 + ta1_z_yyyy_xxyyz_0[i] * pa_x[i] - ta1_z_yyyy_xxyyz_1[i] * pc_x[i];

        ta1_z_xyyyy_xxyzz_0[i] = 2.0 * ta1_z_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xyzz_1[i] * fe_0 + ta1_z_yyyy_xxyzz_0[i] * pa_x[i] - ta1_z_yyyy_xxyzz_1[i] * pc_x[i];

        ta1_z_xyyyy_xxzzz_0[i] = 2.0 * ta1_z_yyyy_xzzz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xzzz_1[i] * fe_0 + ta1_z_yyyy_xxzzz_0[i] * pa_x[i] - ta1_z_yyyy_xxzzz_1[i] * pc_x[i];

        ta1_z_xyyyy_xyyyy_0[i] = ta1_z_yyyy_yyyy_0[i] * fe_0 - ta1_z_yyyy_yyyy_1[i] * fe_0 + ta1_z_yyyy_xyyyy_0[i] * pa_x[i] - ta1_z_yyyy_xyyyy_1[i] * pc_x[i];

        ta1_z_xyyyy_xyyyz_0[i] = ta1_z_yyyy_yyyz_0[i] * fe_0 - ta1_z_yyyy_yyyz_1[i] * fe_0 + ta1_z_yyyy_xyyyz_0[i] * pa_x[i] - ta1_z_yyyy_xyyyz_1[i] * pc_x[i];

        ta1_z_xyyyy_xyyzz_0[i] = ta1_z_yyyy_yyzz_0[i] * fe_0 - ta1_z_yyyy_yyzz_1[i] * fe_0 + ta1_z_yyyy_xyyzz_0[i] * pa_x[i] - ta1_z_yyyy_xyyzz_1[i] * pc_x[i];

        ta1_z_xyyyy_xyzzz_0[i] = ta1_z_yyyy_yzzz_0[i] * fe_0 - ta1_z_yyyy_yzzz_1[i] * fe_0 + ta1_z_yyyy_xyzzz_0[i] * pa_x[i] - ta1_z_yyyy_xyzzz_1[i] * pc_x[i];

        ta1_z_xyyyy_xzzzz_0[i] = ta1_z_yyyy_zzzz_0[i] * fe_0 - ta1_z_yyyy_zzzz_1[i] * fe_0 + ta1_z_yyyy_xzzzz_0[i] * pa_x[i] - ta1_z_yyyy_xzzzz_1[i] * pc_x[i];

        ta1_z_xyyyy_yyyyy_0[i] = ta1_z_yyyy_yyyyy_0[i] * pa_x[i] - ta1_z_yyyy_yyyyy_1[i] * pc_x[i];

        ta1_z_xyyyy_yyyyz_0[i] = ta1_z_yyyy_yyyyz_0[i] * pa_x[i] - ta1_z_yyyy_yyyyz_1[i] * pc_x[i];

        ta1_z_xyyyy_yyyzz_0[i] = ta1_z_yyyy_yyyzz_0[i] * pa_x[i] - ta1_z_yyyy_yyyzz_1[i] * pc_x[i];

        ta1_z_xyyyy_yyzzz_0[i] = ta1_z_yyyy_yyzzz_0[i] * pa_x[i] - ta1_z_yyyy_yyzzz_1[i] * pc_x[i];

        ta1_z_xyyyy_yzzzz_0[i] = ta1_z_yyyy_yzzzz_0[i] * pa_x[i] - ta1_z_yyyy_yzzzz_1[i] * pc_x[i];

        ta1_z_xyyyy_zzzzz_0[i] = ta1_z_yyyy_zzzzz_0[i] * pa_x[i] - ta1_z_yyyy_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1113-1134 components of targeted buffer : HH

    auto ta1_z_xyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1113);

    auto ta1_z_xyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1114);

    auto ta1_z_xyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1115);

    auto ta1_z_xyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1116);

    auto ta1_z_xyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1117);

    auto ta1_z_xyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1118);

    auto ta1_z_xyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1119);

    auto ta1_z_xyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1120);

    auto ta1_z_xyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1121);

    auto ta1_z_xyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1122);

    auto ta1_z_xyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1123);

    auto ta1_z_xyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1124);

    auto ta1_z_xyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1125);

    auto ta1_z_xyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1126);

    auto ta1_z_xyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1127);

    auto ta1_z_xyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1128);

    auto ta1_z_xyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1129);

    auto ta1_z_xyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1130);

    auto ta1_z_xyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1131);

    auto ta1_z_xyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1132);

    auto ta1_z_xyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1133);

    #pragma omp simd aligned(pa_x, pa_z, pc_x, pc_z, ta1_z_xyyy_xxxxx_0, ta1_z_xyyy_xxxxx_1, ta1_z_xyyy_xxxxy_0, ta1_z_xyyy_xxxxy_1, ta1_z_xyyy_xxxyy_0, ta1_z_xyyy_xxxyy_1, ta1_z_xyyy_xxyyy_0, ta1_z_xyyy_xxyyy_1, ta1_z_xyyy_xyyyy_0, ta1_z_xyyy_xyyyy_1, ta1_z_xyyyz_xxxxx_0, ta1_z_xyyyz_xxxxy_0, ta1_z_xyyyz_xxxxz_0, ta1_z_xyyyz_xxxyy_0, ta1_z_xyyyz_xxxyz_0, ta1_z_xyyyz_xxxzz_0, ta1_z_xyyyz_xxyyy_0, ta1_z_xyyyz_xxyyz_0, ta1_z_xyyyz_xxyzz_0, ta1_z_xyyyz_xxzzz_0, ta1_z_xyyyz_xyyyy_0, ta1_z_xyyyz_xyyyz_0, ta1_z_xyyyz_xyyzz_0, ta1_z_xyyyz_xyzzz_0, ta1_z_xyyyz_xzzzz_0, ta1_z_xyyyz_yyyyy_0, ta1_z_xyyyz_yyyyz_0, ta1_z_xyyyz_yyyzz_0, ta1_z_xyyyz_yyzzz_0, ta1_z_xyyyz_yzzzz_0, ta1_z_xyyyz_zzzzz_0, ta1_z_yyyz_xxxxz_0, ta1_z_yyyz_xxxxz_1, ta1_z_yyyz_xxxyz_0, ta1_z_yyyz_xxxyz_1, ta1_z_yyyz_xxxz_0, ta1_z_yyyz_xxxz_1, ta1_z_yyyz_xxxzz_0, ta1_z_yyyz_xxxzz_1, ta1_z_yyyz_xxyyz_0, ta1_z_yyyz_xxyyz_1, ta1_z_yyyz_xxyz_0, ta1_z_yyyz_xxyz_1, ta1_z_yyyz_xxyzz_0, ta1_z_yyyz_xxyzz_1, ta1_z_yyyz_xxzz_0, ta1_z_yyyz_xxzz_1, ta1_z_yyyz_xxzzz_0, ta1_z_yyyz_xxzzz_1, ta1_z_yyyz_xyyyz_0, ta1_z_yyyz_xyyyz_1, ta1_z_yyyz_xyyz_0, ta1_z_yyyz_xyyz_1, ta1_z_yyyz_xyyzz_0, ta1_z_yyyz_xyyzz_1, ta1_z_yyyz_xyzz_0, ta1_z_yyyz_xyzz_1, ta1_z_yyyz_xyzzz_0, ta1_z_yyyz_xyzzz_1, ta1_z_yyyz_xzzz_0, ta1_z_yyyz_xzzz_1, ta1_z_yyyz_xzzzz_0, ta1_z_yyyz_xzzzz_1, ta1_z_yyyz_yyyyy_0, ta1_z_yyyz_yyyyy_1, ta1_z_yyyz_yyyyz_0, ta1_z_yyyz_yyyyz_1, ta1_z_yyyz_yyyz_0, ta1_z_yyyz_yyyz_1, ta1_z_yyyz_yyyzz_0, ta1_z_yyyz_yyyzz_1, ta1_z_yyyz_yyzz_0, ta1_z_yyyz_yyzz_1, ta1_z_yyyz_yyzzz_0, ta1_z_yyyz_yyzzz_1, ta1_z_yyyz_yzzz_0, ta1_z_yyyz_yzzz_1, ta1_z_yyyz_yzzzz_0, ta1_z_yyyz_yzzzz_1, ta1_z_yyyz_zzzz_0, ta1_z_yyyz_zzzz_1, ta1_z_yyyz_zzzzz_0, ta1_z_yyyz_zzzzz_1, ta_xyyy_xxxxx_1, ta_xyyy_xxxxy_1, ta_xyyy_xxxyy_1, ta_xyyy_xxyyy_1, ta_xyyy_xyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xyyyz_xxxxx_0[i] = ta_xyyy_xxxxx_1[i] + ta1_z_xyyy_xxxxx_0[i] * pa_z[i] - ta1_z_xyyy_xxxxx_1[i] * pc_z[i];

        ta1_z_xyyyz_xxxxy_0[i] = ta_xyyy_xxxxy_1[i] + ta1_z_xyyy_xxxxy_0[i] * pa_z[i] - ta1_z_xyyy_xxxxy_1[i] * pc_z[i];

        ta1_z_xyyyz_xxxxz_0[i] = 4.0 * ta1_z_yyyz_xxxz_0[i] * fe_0 - 4.0 * ta1_z_yyyz_xxxz_1[i] * fe_0 + ta1_z_yyyz_xxxxz_0[i] * pa_x[i] - ta1_z_yyyz_xxxxz_1[i] * pc_x[i];

        ta1_z_xyyyz_xxxyy_0[i] = ta_xyyy_xxxyy_1[i] + ta1_z_xyyy_xxxyy_0[i] * pa_z[i] - ta1_z_xyyy_xxxyy_1[i] * pc_z[i];

        ta1_z_xyyyz_xxxyz_0[i] = 3.0 * ta1_z_yyyz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_yyyz_xxyz_1[i] * fe_0 + ta1_z_yyyz_xxxyz_0[i] * pa_x[i] - ta1_z_yyyz_xxxyz_1[i] * pc_x[i];

        ta1_z_xyyyz_xxxzz_0[i] = 3.0 * ta1_z_yyyz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_yyyz_xxzz_1[i] * fe_0 + ta1_z_yyyz_xxxzz_0[i] * pa_x[i] - ta1_z_yyyz_xxxzz_1[i] * pc_x[i];

        ta1_z_xyyyz_xxyyy_0[i] = ta_xyyy_xxyyy_1[i] + ta1_z_xyyy_xxyyy_0[i] * pa_z[i] - ta1_z_xyyy_xxyyy_1[i] * pc_z[i];

        ta1_z_xyyyz_xxyyz_0[i] = 2.0 * ta1_z_yyyz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_yyyz_xyyz_1[i] * fe_0 + ta1_z_yyyz_xxyyz_0[i] * pa_x[i] - ta1_z_yyyz_xxyyz_1[i] * pc_x[i];

        ta1_z_xyyyz_xxyzz_0[i] = 2.0 * ta1_z_yyyz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yyyz_xyzz_1[i] * fe_0 + ta1_z_yyyz_xxyzz_0[i] * pa_x[i] - ta1_z_yyyz_xxyzz_1[i] * pc_x[i];

        ta1_z_xyyyz_xxzzz_0[i] = 2.0 * ta1_z_yyyz_xzzz_0[i] * fe_0 - 2.0 * ta1_z_yyyz_xzzz_1[i] * fe_0 + ta1_z_yyyz_xxzzz_0[i] * pa_x[i] - ta1_z_yyyz_xxzzz_1[i] * pc_x[i];

        ta1_z_xyyyz_xyyyy_0[i] = ta_xyyy_xyyyy_1[i] + ta1_z_xyyy_xyyyy_0[i] * pa_z[i] - ta1_z_xyyy_xyyyy_1[i] * pc_z[i];

        ta1_z_xyyyz_xyyyz_0[i] = ta1_z_yyyz_yyyz_0[i] * fe_0 - ta1_z_yyyz_yyyz_1[i] * fe_0 + ta1_z_yyyz_xyyyz_0[i] * pa_x[i] - ta1_z_yyyz_xyyyz_1[i] * pc_x[i];

        ta1_z_xyyyz_xyyzz_0[i] = ta1_z_yyyz_yyzz_0[i] * fe_0 - ta1_z_yyyz_yyzz_1[i] * fe_0 + ta1_z_yyyz_xyyzz_0[i] * pa_x[i] - ta1_z_yyyz_xyyzz_1[i] * pc_x[i];

        ta1_z_xyyyz_xyzzz_0[i] = ta1_z_yyyz_yzzz_0[i] * fe_0 - ta1_z_yyyz_yzzz_1[i] * fe_0 + ta1_z_yyyz_xyzzz_0[i] * pa_x[i] - ta1_z_yyyz_xyzzz_1[i] * pc_x[i];

        ta1_z_xyyyz_xzzzz_0[i] = ta1_z_yyyz_zzzz_0[i] * fe_0 - ta1_z_yyyz_zzzz_1[i] * fe_0 + ta1_z_yyyz_xzzzz_0[i] * pa_x[i] - ta1_z_yyyz_xzzzz_1[i] * pc_x[i];

        ta1_z_xyyyz_yyyyy_0[i] = ta1_z_yyyz_yyyyy_0[i] * pa_x[i] - ta1_z_yyyz_yyyyy_1[i] * pc_x[i];

        ta1_z_xyyyz_yyyyz_0[i] = ta1_z_yyyz_yyyyz_0[i] * pa_x[i] - ta1_z_yyyz_yyyyz_1[i] * pc_x[i];

        ta1_z_xyyyz_yyyzz_0[i] = ta1_z_yyyz_yyyzz_0[i] * pa_x[i] - ta1_z_yyyz_yyyzz_1[i] * pc_x[i];

        ta1_z_xyyyz_yyzzz_0[i] = ta1_z_yyyz_yyzzz_0[i] * pa_x[i] - ta1_z_yyyz_yyzzz_1[i] * pc_x[i];

        ta1_z_xyyyz_yzzzz_0[i] = ta1_z_yyyz_yzzzz_0[i] * pa_x[i] - ta1_z_yyyz_yzzzz_1[i] * pc_x[i];

        ta1_z_xyyyz_zzzzz_0[i] = ta1_z_yyyz_zzzzz_0[i] * pa_x[i] - ta1_z_yyyz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1134-1155 components of targeted buffer : HH

    auto ta1_z_xyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1134);

    auto ta1_z_xyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1135);

    auto ta1_z_xyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1136);

    auto ta1_z_xyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1137);

    auto ta1_z_xyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1138);

    auto ta1_z_xyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1139);

    auto ta1_z_xyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1140);

    auto ta1_z_xyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1141);

    auto ta1_z_xyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1142);

    auto ta1_z_xyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1143);

    auto ta1_z_xyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1144);

    auto ta1_z_xyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1145);

    auto ta1_z_xyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1146);

    auto ta1_z_xyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1147);

    auto ta1_z_xyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1148);

    auto ta1_z_xyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1149);

    auto ta1_z_xyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1150);

    auto ta1_z_xyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1151);

    auto ta1_z_xyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1152);

    auto ta1_z_xyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1153);

    auto ta1_z_xyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1154);

    #pragma omp simd aligned(pa_x, pc_x, ta1_z_xyyzz_xxxxx_0, ta1_z_xyyzz_xxxxy_0, ta1_z_xyyzz_xxxxz_0, ta1_z_xyyzz_xxxyy_0, ta1_z_xyyzz_xxxyz_0, ta1_z_xyyzz_xxxzz_0, ta1_z_xyyzz_xxyyy_0, ta1_z_xyyzz_xxyyz_0, ta1_z_xyyzz_xxyzz_0, ta1_z_xyyzz_xxzzz_0, ta1_z_xyyzz_xyyyy_0, ta1_z_xyyzz_xyyyz_0, ta1_z_xyyzz_xyyzz_0, ta1_z_xyyzz_xyzzz_0, ta1_z_xyyzz_xzzzz_0, ta1_z_xyyzz_yyyyy_0, ta1_z_xyyzz_yyyyz_0, ta1_z_xyyzz_yyyzz_0, ta1_z_xyyzz_yyzzz_0, ta1_z_xyyzz_yzzzz_0, ta1_z_xyyzz_zzzzz_0, ta1_z_yyzz_xxxx_0, ta1_z_yyzz_xxxx_1, ta1_z_yyzz_xxxxx_0, ta1_z_yyzz_xxxxx_1, ta1_z_yyzz_xxxxy_0, ta1_z_yyzz_xxxxy_1, ta1_z_yyzz_xxxxz_0, ta1_z_yyzz_xxxxz_1, ta1_z_yyzz_xxxy_0, ta1_z_yyzz_xxxy_1, ta1_z_yyzz_xxxyy_0, ta1_z_yyzz_xxxyy_1, ta1_z_yyzz_xxxyz_0, ta1_z_yyzz_xxxyz_1, ta1_z_yyzz_xxxz_0, ta1_z_yyzz_xxxz_1, ta1_z_yyzz_xxxzz_0, ta1_z_yyzz_xxxzz_1, ta1_z_yyzz_xxyy_0, ta1_z_yyzz_xxyy_1, ta1_z_yyzz_xxyyy_0, ta1_z_yyzz_xxyyy_1, ta1_z_yyzz_xxyyz_0, ta1_z_yyzz_xxyyz_1, ta1_z_yyzz_xxyz_0, ta1_z_yyzz_xxyz_1, ta1_z_yyzz_xxyzz_0, ta1_z_yyzz_xxyzz_1, ta1_z_yyzz_xxzz_0, ta1_z_yyzz_xxzz_1, ta1_z_yyzz_xxzzz_0, ta1_z_yyzz_xxzzz_1, ta1_z_yyzz_xyyy_0, ta1_z_yyzz_xyyy_1, ta1_z_yyzz_xyyyy_0, ta1_z_yyzz_xyyyy_1, ta1_z_yyzz_xyyyz_0, ta1_z_yyzz_xyyyz_1, ta1_z_yyzz_xyyz_0, ta1_z_yyzz_xyyz_1, ta1_z_yyzz_xyyzz_0, ta1_z_yyzz_xyyzz_1, ta1_z_yyzz_xyzz_0, ta1_z_yyzz_xyzz_1, ta1_z_yyzz_xyzzz_0, ta1_z_yyzz_xyzzz_1, ta1_z_yyzz_xzzz_0, ta1_z_yyzz_xzzz_1, ta1_z_yyzz_xzzzz_0, ta1_z_yyzz_xzzzz_1, ta1_z_yyzz_yyyy_0, ta1_z_yyzz_yyyy_1, ta1_z_yyzz_yyyyy_0, ta1_z_yyzz_yyyyy_1, ta1_z_yyzz_yyyyz_0, ta1_z_yyzz_yyyyz_1, ta1_z_yyzz_yyyz_0, ta1_z_yyzz_yyyz_1, ta1_z_yyzz_yyyzz_0, ta1_z_yyzz_yyyzz_1, ta1_z_yyzz_yyzz_0, ta1_z_yyzz_yyzz_1, ta1_z_yyzz_yyzzz_0, ta1_z_yyzz_yyzzz_1, ta1_z_yyzz_yzzz_0, ta1_z_yyzz_yzzz_1, ta1_z_yyzz_yzzzz_0, ta1_z_yyzz_yzzzz_1, ta1_z_yyzz_zzzz_0, ta1_z_yyzz_zzzz_1, ta1_z_yyzz_zzzzz_0, ta1_z_yyzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xyyzz_xxxxx_0[i] = 5.0 * ta1_z_yyzz_xxxx_0[i] * fe_0 - 5.0 * ta1_z_yyzz_xxxx_1[i] * fe_0 + ta1_z_yyzz_xxxxx_0[i] * pa_x[i] - ta1_z_yyzz_xxxxx_1[i] * pc_x[i];

        ta1_z_xyyzz_xxxxy_0[i] = 4.0 * ta1_z_yyzz_xxxy_0[i] * fe_0 - 4.0 * ta1_z_yyzz_xxxy_1[i] * fe_0 + ta1_z_yyzz_xxxxy_0[i] * pa_x[i] - ta1_z_yyzz_xxxxy_1[i] * pc_x[i];

        ta1_z_xyyzz_xxxxz_0[i] = 4.0 * ta1_z_yyzz_xxxz_0[i] * fe_0 - 4.0 * ta1_z_yyzz_xxxz_1[i] * fe_0 + ta1_z_yyzz_xxxxz_0[i] * pa_x[i] - ta1_z_yyzz_xxxxz_1[i] * pc_x[i];

        ta1_z_xyyzz_xxxyy_0[i] = 3.0 * ta1_z_yyzz_xxyy_0[i] * fe_0 - 3.0 * ta1_z_yyzz_xxyy_1[i] * fe_0 + ta1_z_yyzz_xxxyy_0[i] * pa_x[i] - ta1_z_yyzz_xxxyy_1[i] * pc_x[i];

        ta1_z_xyyzz_xxxyz_0[i] = 3.0 * ta1_z_yyzz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_yyzz_xxyz_1[i] * fe_0 + ta1_z_yyzz_xxxyz_0[i] * pa_x[i] - ta1_z_yyzz_xxxyz_1[i] * pc_x[i];

        ta1_z_xyyzz_xxxzz_0[i] = 3.0 * ta1_z_yyzz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_yyzz_xxzz_1[i] * fe_0 + ta1_z_yyzz_xxxzz_0[i] * pa_x[i] - ta1_z_yyzz_xxxzz_1[i] * pc_x[i];

        ta1_z_xyyzz_xxyyy_0[i] = 2.0 * ta1_z_yyzz_xyyy_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xyyy_1[i] * fe_0 + ta1_z_yyzz_xxyyy_0[i] * pa_x[i] - ta1_z_yyzz_xxyyy_1[i] * pc_x[i];

        ta1_z_xyyzz_xxyyz_0[i] = 2.0 * ta1_z_yyzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xyyz_1[i] * fe_0 + ta1_z_yyzz_xxyyz_0[i] * pa_x[i] - ta1_z_yyzz_xxyyz_1[i] * pc_x[i];

        ta1_z_xyyzz_xxyzz_0[i] = 2.0 * ta1_z_yyzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xyzz_1[i] * fe_0 + ta1_z_yyzz_xxyzz_0[i] * pa_x[i] - ta1_z_yyzz_xxyzz_1[i] * pc_x[i];

        ta1_z_xyyzz_xxzzz_0[i] = 2.0 * ta1_z_yyzz_xzzz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xzzz_1[i] * fe_0 + ta1_z_yyzz_xxzzz_0[i] * pa_x[i] - ta1_z_yyzz_xxzzz_1[i] * pc_x[i];

        ta1_z_xyyzz_xyyyy_0[i] = ta1_z_yyzz_yyyy_0[i] * fe_0 - ta1_z_yyzz_yyyy_1[i] * fe_0 + ta1_z_yyzz_xyyyy_0[i] * pa_x[i] - ta1_z_yyzz_xyyyy_1[i] * pc_x[i];

        ta1_z_xyyzz_xyyyz_0[i] = ta1_z_yyzz_yyyz_0[i] * fe_0 - ta1_z_yyzz_yyyz_1[i] * fe_0 + ta1_z_yyzz_xyyyz_0[i] * pa_x[i] - ta1_z_yyzz_xyyyz_1[i] * pc_x[i];

        ta1_z_xyyzz_xyyzz_0[i] = ta1_z_yyzz_yyzz_0[i] * fe_0 - ta1_z_yyzz_yyzz_1[i] * fe_0 + ta1_z_yyzz_xyyzz_0[i] * pa_x[i] - ta1_z_yyzz_xyyzz_1[i] * pc_x[i];

        ta1_z_xyyzz_xyzzz_0[i] = ta1_z_yyzz_yzzz_0[i] * fe_0 - ta1_z_yyzz_yzzz_1[i] * fe_0 + ta1_z_yyzz_xyzzz_0[i] * pa_x[i] - ta1_z_yyzz_xyzzz_1[i] * pc_x[i];

        ta1_z_xyyzz_xzzzz_0[i] = ta1_z_yyzz_zzzz_0[i] * fe_0 - ta1_z_yyzz_zzzz_1[i] * fe_0 + ta1_z_yyzz_xzzzz_0[i] * pa_x[i] - ta1_z_yyzz_xzzzz_1[i] * pc_x[i];

        ta1_z_xyyzz_yyyyy_0[i] = ta1_z_yyzz_yyyyy_0[i] * pa_x[i] - ta1_z_yyzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xyyzz_yyyyz_0[i] = ta1_z_yyzz_yyyyz_0[i] * pa_x[i] - ta1_z_yyzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xyyzz_yyyzz_0[i] = ta1_z_yyzz_yyyzz_0[i] * pa_x[i] - ta1_z_yyzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xyyzz_yyzzz_0[i] = ta1_z_yyzz_yyzzz_0[i] * pa_x[i] - ta1_z_yyzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xyyzz_yzzzz_0[i] = ta1_z_yyzz_yzzzz_0[i] * pa_x[i] - ta1_z_yyzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xyyzz_zzzzz_0[i] = ta1_z_yyzz_zzzzz_0[i] * pa_x[i] - ta1_z_yyzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1155-1176 components of targeted buffer : HH

    auto ta1_z_xyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1155);

    auto ta1_z_xyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1156);

    auto ta1_z_xyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1157);

    auto ta1_z_xyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1158);

    auto ta1_z_xyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1159);

    auto ta1_z_xyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1160);

    auto ta1_z_xyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1161);

    auto ta1_z_xyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1162);

    auto ta1_z_xyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1163);

    auto ta1_z_xyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1164);

    auto ta1_z_xyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1165);

    auto ta1_z_xyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1166);

    auto ta1_z_xyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1167);

    auto ta1_z_xyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1168);

    auto ta1_z_xyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1169);

    auto ta1_z_xyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1170);

    auto ta1_z_xyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1171);

    auto ta1_z_xyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1172);

    auto ta1_z_xyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1173);

    auto ta1_z_xyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1174);

    auto ta1_z_xyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1175);

    #pragma omp simd aligned(pa_x, pa_y, pc_x, pc_y, ta1_z_xyzzz_xxxxx_0, ta1_z_xyzzz_xxxxy_0, ta1_z_xyzzz_xxxxz_0, ta1_z_xyzzz_xxxyy_0, ta1_z_xyzzz_xxxyz_0, ta1_z_xyzzz_xxxzz_0, ta1_z_xyzzz_xxyyy_0, ta1_z_xyzzz_xxyyz_0, ta1_z_xyzzz_xxyzz_0, ta1_z_xyzzz_xxzzz_0, ta1_z_xyzzz_xyyyy_0, ta1_z_xyzzz_xyyyz_0, ta1_z_xyzzz_xyyzz_0, ta1_z_xyzzz_xyzzz_0, ta1_z_xyzzz_xzzzz_0, ta1_z_xyzzz_yyyyy_0, ta1_z_xyzzz_yyyyz_0, ta1_z_xyzzz_yyyzz_0, ta1_z_xyzzz_yyzzz_0, ta1_z_xyzzz_yzzzz_0, ta1_z_xyzzz_zzzzz_0, ta1_z_xzzz_xxxxx_0, ta1_z_xzzz_xxxxx_1, ta1_z_xzzz_xxxxz_0, ta1_z_xzzz_xxxxz_1, ta1_z_xzzz_xxxzz_0, ta1_z_xzzz_xxxzz_1, ta1_z_xzzz_xxzzz_0, ta1_z_xzzz_xxzzz_1, ta1_z_xzzz_xzzzz_0, ta1_z_xzzz_xzzzz_1, ta1_z_yzzz_xxxxy_0, ta1_z_yzzz_xxxxy_1, ta1_z_yzzz_xxxy_0, ta1_z_yzzz_xxxy_1, ta1_z_yzzz_xxxyy_0, ta1_z_yzzz_xxxyy_1, ta1_z_yzzz_xxxyz_0, ta1_z_yzzz_xxxyz_1, ta1_z_yzzz_xxyy_0, ta1_z_yzzz_xxyy_1, ta1_z_yzzz_xxyyy_0, ta1_z_yzzz_xxyyy_1, ta1_z_yzzz_xxyyz_0, ta1_z_yzzz_xxyyz_1, ta1_z_yzzz_xxyz_0, ta1_z_yzzz_xxyz_1, ta1_z_yzzz_xxyzz_0, ta1_z_yzzz_xxyzz_1, ta1_z_yzzz_xyyy_0, ta1_z_yzzz_xyyy_1, ta1_z_yzzz_xyyyy_0, ta1_z_yzzz_xyyyy_1, ta1_z_yzzz_xyyyz_0, ta1_z_yzzz_xyyyz_1, ta1_z_yzzz_xyyz_0, ta1_z_yzzz_xyyz_1, ta1_z_yzzz_xyyzz_0, ta1_z_yzzz_xyyzz_1, ta1_z_yzzz_xyzz_0, ta1_z_yzzz_xyzz_1, ta1_z_yzzz_xyzzz_0, ta1_z_yzzz_xyzzz_1, ta1_z_yzzz_yyyy_0, ta1_z_yzzz_yyyy_1, ta1_z_yzzz_yyyyy_0, ta1_z_yzzz_yyyyy_1, ta1_z_yzzz_yyyyz_0, ta1_z_yzzz_yyyyz_1, ta1_z_yzzz_yyyz_0, ta1_z_yzzz_yyyz_1, ta1_z_yzzz_yyyzz_0, ta1_z_yzzz_yyyzz_1, ta1_z_yzzz_yyzz_0, ta1_z_yzzz_yyzz_1, ta1_z_yzzz_yyzzz_0, ta1_z_yzzz_yyzzz_1, ta1_z_yzzz_yzzz_0, ta1_z_yzzz_yzzz_1, ta1_z_yzzz_yzzzz_0, ta1_z_yzzz_yzzzz_1, ta1_z_yzzz_zzzzz_0, ta1_z_yzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xyzzz_xxxxx_0[i] = ta1_z_xzzz_xxxxx_0[i] * pa_y[i] - ta1_z_xzzz_xxxxx_1[i] * pc_y[i];

        ta1_z_xyzzz_xxxxy_0[i] = 4.0 * ta1_z_yzzz_xxxy_0[i] * fe_0 - 4.0 * ta1_z_yzzz_xxxy_1[i] * fe_0 + ta1_z_yzzz_xxxxy_0[i] * pa_x[i] - ta1_z_yzzz_xxxxy_1[i] * pc_x[i];

        ta1_z_xyzzz_xxxxz_0[i] = ta1_z_xzzz_xxxxz_0[i] * pa_y[i] - ta1_z_xzzz_xxxxz_1[i] * pc_y[i];

        ta1_z_xyzzz_xxxyy_0[i] = 3.0 * ta1_z_yzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_z_yzzz_xxyy_1[i] * fe_0 + ta1_z_yzzz_xxxyy_0[i] * pa_x[i] - ta1_z_yzzz_xxxyy_1[i] * pc_x[i];

        ta1_z_xyzzz_xxxyz_0[i] = 3.0 * ta1_z_yzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_yzzz_xxyz_1[i] * fe_0 + ta1_z_yzzz_xxxyz_0[i] * pa_x[i] - ta1_z_yzzz_xxxyz_1[i] * pc_x[i];

        ta1_z_xyzzz_xxxzz_0[i] = ta1_z_xzzz_xxxzz_0[i] * pa_y[i] - ta1_z_xzzz_xxxzz_1[i] * pc_y[i];

        ta1_z_xyzzz_xxyyy_0[i] = 2.0 * ta1_z_yzzz_xyyy_0[i] * fe_0 - 2.0 * ta1_z_yzzz_xyyy_1[i] * fe_0 + ta1_z_yzzz_xxyyy_0[i] * pa_x[i] - ta1_z_yzzz_xxyyy_1[i] * pc_x[i];

        ta1_z_xyzzz_xxyyz_0[i] = 2.0 * ta1_z_yzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_yzzz_xyyz_1[i] * fe_0 + ta1_z_yzzz_xxyyz_0[i] * pa_x[i] - ta1_z_yzzz_xxyyz_1[i] * pc_x[i];

        ta1_z_xyzzz_xxyzz_0[i] = 2.0 * ta1_z_yzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yzzz_xyzz_1[i] * fe_0 + ta1_z_yzzz_xxyzz_0[i] * pa_x[i] - ta1_z_yzzz_xxyzz_1[i] * pc_x[i];

        ta1_z_xyzzz_xxzzz_0[i] = ta1_z_xzzz_xxzzz_0[i] * pa_y[i] - ta1_z_xzzz_xxzzz_1[i] * pc_y[i];

        ta1_z_xyzzz_xyyyy_0[i] = ta1_z_yzzz_yyyy_0[i] * fe_0 - ta1_z_yzzz_yyyy_1[i] * fe_0 + ta1_z_yzzz_xyyyy_0[i] * pa_x[i] - ta1_z_yzzz_xyyyy_1[i] * pc_x[i];

        ta1_z_xyzzz_xyyyz_0[i] = ta1_z_yzzz_yyyz_0[i] * fe_0 - ta1_z_yzzz_yyyz_1[i] * fe_0 + ta1_z_yzzz_xyyyz_0[i] * pa_x[i] - ta1_z_yzzz_xyyyz_1[i] * pc_x[i];

        ta1_z_xyzzz_xyyzz_0[i] = ta1_z_yzzz_yyzz_0[i] * fe_0 - ta1_z_yzzz_yyzz_1[i] * fe_0 + ta1_z_yzzz_xyyzz_0[i] * pa_x[i] - ta1_z_yzzz_xyyzz_1[i] * pc_x[i];

        ta1_z_xyzzz_xyzzz_0[i] = ta1_z_yzzz_yzzz_0[i] * fe_0 - ta1_z_yzzz_yzzz_1[i] * fe_0 + ta1_z_yzzz_xyzzz_0[i] * pa_x[i] - ta1_z_yzzz_xyzzz_1[i] * pc_x[i];

        ta1_z_xyzzz_xzzzz_0[i] = ta1_z_xzzz_xzzzz_0[i] * pa_y[i] - ta1_z_xzzz_xzzzz_1[i] * pc_y[i];

        ta1_z_xyzzz_yyyyy_0[i] = ta1_z_yzzz_yyyyy_0[i] * pa_x[i] - ta1_z_yzzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xyzzz_yyyyz_0[i] = ta1_z_yzzz_yyyyz_0[i] * pa_x[i] - ta1_z_yzzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xyzzz_yyyzz_0[i] = ta1_z_yzzz_yyyzz_0[i] * pa_x[i] - ta1_z_yzzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xyzzz_yyzzz_0[i] = ta1_z_yzzz_yyzzz_0[i] * pa_x[i] - ta1_z_yzzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xyzzz_yzzzz_0[i] = ta1_z_yzzz_yzzzz_0[i] * pa_x[i] - ta1_z_yzzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xyzzz_zzzzz_0[i] = ta1_z_yzzz_zzzzz_0[i] * pa_x[i] - ta1_z_yzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1176-1197 components of targeted buffer : HH

    auto ta1_z_xzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1176);

    auto ta1_z_xzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1177);

    auto ta1_z_xzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1178);

    auto ta1_z_xzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1179);

    auto ta1_z_xzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1180);

    auto ta1_z_xzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1181);

    auto ta1_z_xzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1182);

    auto ta1_z_xzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1183);

    auto ta1_z_xzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1184);

    auto ta1_z_xzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1185);

    auto ta1_z_xzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1186);

    auto ta1_z_xzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1187);

    auto ta1_z_xzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1188);

    auto ta1_z_xzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1189);

    auto ta1_z_xzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1190);

    auto ta1_z_xzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1191);

    auto ta1_z_xzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1192);

    auto ta1_z_xzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1193);

    auto ta1_z_xzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1194);

    auto ta1_z_xzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1195);

    auto ta1_z_xzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1196);

    #pragma omp simd aligned(pa_x, pc_x, ta1_z_xzzzz_xxxxx_0, ta1_z_xzzzz_xxxxy_0, ta1_z_xzzzz_xxxxz_0, ta1_z_xzzzz_xxxyy_0, ta1_z_xzzzz_xxxyz_0, ta1_z_xzzzz_xxxzz_0, ta1_z_xzzzz_xxyyy_0, ta1_z_xzzzz_xxyyz_0, ta1_z_xzzzz_xxyzz_0, ta1_z_xzzzz_xxzzz_0, ta1_z_xzzzz_xyyyy_0, ta1_z_xzzzz_xyyyz_0, ta1_z_xzzzz_xyyzz_0, ta1_z_xzzzz_xyzzz_0, ta1_z_xzzzz_xzzzz_0, ta1_z_xzzzz_yyyyy_0, ta1_z_xzzzz_yyyyz_0, ta1_z_xzzzz_yyyzz_0, ta1_z_xzzzz_yyzzz_0, ta1_z_xzzzz_yzzzz_0, ta1_z_xzzzz_zzzzz_0, ta1_z_zzzz_xxxx_0, ta1_z_zzzz_xxxx_1, ta1_z_zzzz_xxxxx_0, ta1_z_zzzz_xxxxx_1, ta1_z_zzzz_xxxxy_0, ta1_z_zzzz_xxxxy_1, ta1_z_zzzz_xxxxz_0, ta1_z_zzzz_xxxxz_1, ta1_z_zzzz_xxxy_0, ta1_z_zzzz_xxxy_1, ta1_z_zzzz_xxxyy_0, ta1_z_zzzz_xxxyy_1, ta1_z_zzzz_xxxyz_0, ta1_z_zzzz_xxxyz_1, ta1_z_zzzz_xxxz_0, ta1_z_zzzz_xxxz_1, ta1_z_zzzz_xxxzz_0, ta1_z_zzzz_xxxzz_1, ta1_z_zzzz_xxyy_0, ta1_z_zzzz_xxyy_1, ta1_z_zzzz_xxyyy_0, ta1_z_zzzz_xxyyy_1, ta1_z_zzzz_xxyyz_0, ta1_z_zzzz_xxyyz_1, ta1_z_zzzz_xxyz_0, ta1_z_zzzz_xxyz_1, ta1_z_zzzz_xxyzz_0, ta1_z_zzzz_xxyzz_1, ta1_z_zzzz_xxzz_0, ta1_z_zzzz_xxzz_1, ta1_z_zzzz_xxzzz_0, ta1_z_zzzz_xxzzz_1, ta1_z_zzzz_xyyy_0, ta1_z_zzzz_xyyy_1, ta1_z_zzzz_xyyyy_0, ta1_z_zzzz_xyyyy_1, ta1_z_zzzz_xyyyz_0, ta1_z_zzzz_xyyyz_1, ta1_z_zzzz_xyyz_0, ta1_z_zzzz_xyyz_1, ta1_z_zzzz_xyyzz_0, ta1_z_zzzz_xyyzz_1, ta1_z_zzzz_xyzz_0, ta1_z_zzzz_xyzz_1, ta1_z_zzzz_xyzzz_0, ta1_z_zzzz_xyzzz_1, ta1_z_zzzz_xzzz_0, ta1_z_zzzz_xzzz_1, ta1_z_zzzz_xzzzz_0, ta1_z_zzzz_xzzzz_1, ta1_z_zzzz_yyyy_0, ta1_z_zzzz_yyyy_1, ta1_z_zzzz_yyyyy_0, ta1_z_zzzz_yyyyy_1, ta1_z_zzzz_yyyyz_0, ta1_z_zzzz_yyyyz_1, ta1_z_zzzz_yyyz_0, ta1_z_zzzz_yyyz_1, ta1_z_zzzz_yyyzz_0, ta1_z_zzzz_yyyzz_1, ta1_z_zzzz_yyzz_0, ta1_z_zzzz_yyzz_1, ta1_z_zzzz_yyzzz_0, ta1_z_zzzz_yyzzz_1, ta1_z_zzzz_yzzz_0, ta1_z_zzzz_yzzz_1, ta1_z_zzzz_yzzzz_0, ta1_z_zzzz_yzzzz_1, ta1_z_zzzz_zzzz_0, ta1_z_zzzz_zzzz_1, ta1_z_zzzz_zzzzz_0, ta1_z_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_xzzzz_xxxxx_0[i] = 5.0 * ta1_z_zzzz_xxxx_0[i] * fe_0 - 5.0 * ta1_z_zzzz_xxxx_1[i] * fe_0 + ta1_z_zzzz_xxxxx_0[i] * pa_x[i] - ta1_z_zzzz_xxxxx_1[i] * pc_x[i];

        ta1_z_xzzzz_xxxxy_0[i] = 4.0 * ta1_z_zzzz_xxxy_0[i] * fe_0 - 4.0 * ta1_z_zzzz_xxxy_1[i] * fe_0 + ta1_z_zzzz_xxxxy_0[i] * pa_x[i] - ta1_z_zzzz_xxxxy_1[i] * pc_x[i];

        ta1_z_xzzzz_xxxxz_0[i] = 4.0 * ta1_z_zzzz_xxxz_0[i] * fe_0 - 4.0 * ta1_z_zzzz_xxxz_1[i] * fe_0 + ta1_z_zzzz_xxxxz_0[i] * pa_x[i] - ta1_z_zzzz_xxxxz_1[i] * pc_x[i];

        ta1_z_xzzzz_xxxyy_0[i] = 3.0 * ta1_z_zzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xxyy_1[i] * fe_0 + ta1_z_zzzz_xxxyy_0[i] * pa_x[i] - ta1_z_zzzz_xxxyy_1[i] * pc_x[i];

        ta1_z_xzzzz_xxxyz_0[i] = 3.0 * ta1_z_zzzz_xxyz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xxyz_1[i] * fe_0 + ta1_z_zzzz_xxxyz_0[i] * pa_x[i] - ta1_z_zzzz_xxxyz_1[i] * pc_x[i];

        ta1_z_xzzzz_xxxzz_0[i] = 3.0 * ta1_z_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xxzz_1[i] * fe_0 + ta1_z_zzzz_xxxzz_0[i] * pa_x[i] - ta1_z_zzzz_xxxzz_1[i] * pc_x[i];

        ta1_z_xzzzz_xxyyy_0[i] = 2.0 * ta1_z_zzzz_xyyy_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xyyy_1[i] * fe_0 + ta1_z_zzzz_xxyyy_0[i] * pa_x[i] - ta1_z_zzzz_xxyyy_1[i] * pc_x[i];

        ta1_z_xzzzz_xxyyz_0[i] = 2.0 * ta1_z_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xyyz_1[i] * fe_0 + ta1_z_zzzz_xxyyz_0[i] * pa_x[i] - ta1_z_zzzz_xxyyz_1[i] * pc_x[i];

        ta1_z_xzzzz_xxyzz_0[i] = 2.0 * ta1_z_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xyzz_1[i] * fe_0 + ta1_z_zzzz_xxyzz_0[i] * pa_x[i] - ta1_z_zzzz_xxyzz_1[i] * pc_x[i];

        ta1_z_xzzzz_xxzzz_0[i] = 2.0 * ta1_z_zzzz_xzzz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xzzz_1[i] * fe_0 + ta1_z_zzzz_xxzzz_0[i] * pa_x[i] - ta1_z_zzzz_xxzzz_1[i] * pc_x[i];

        ta1_z_xzzzz_xyyyy_0[i] = ta1_z_zzzz_yyyy_0[i] * fe_0 - ta1_z_zzzz_yyyy_1[i] * fe_0 + ta1_z_zzzz_xyyyy_0[i] * pa_x[i] - ta1_z_zzzz_xyyyy_1[i] * pc_x[i];

        ta1_z_xzzzz_xyyyz_0[i] = ta1_z_zzzz_yyyz_0[i] * fe_0 - ta1_z_zzzz_yyyz_1[i] * fe_0 + ta1_z_zzzz_xyyyz_0[i] * pa_x[i] - ta1_z_zzzz_xyyyz_1[i] * pc_x[i];

        ta1_z_xzzzz_xyyzz_0[i] = ta1_z_zzzz_yyzz_0[i] * fe_0 - ta1_z_zzzz_yyzz_1[i] * fe_0 + ta1_z_zzzz_xyyzz_0[i] * pa_x[i] - ta1_z_zzzz_xyyzz_1[i] * pc_x[i];

        ta1_z_xzzzz_xyzzz_0[i] = ta1_z_zzzz_yzzz_0[i] * fe_0 - ta1_z_zzzz_yzzz_1[i] * fe_0 + ta1_z_zzzz_xyzzz_0[i] * pa_x[i] - ta1_z_zzzz_xyzzz_1[i] * pc_x[i];

        ta1_z_xzzzz_xzzzz_0[i] = ta1_z_zzzz_zzzz_0[i] * fe_0 - ta1_z_zzzz_zzzz_1[i] * fe_0 + ta1_z_zzzz_xzzzz_0[i] * pa_x[i] - ta1_z_zzzz_xzzzz_1[i] * pc_x[i];

        ta1_z_xzzzz_yyyyy_0[i] = ta1_z_zzzz_yyyyy_0[i] * pa_x[i] - ta1_z_zzzz_yyyyy_1[i] * pc_x[i];

        ta1_z_xzzzz_yyyyz_0[i] = ta1_z_zzzz_yyyyz_0[i] * pa_x[i] - ta1_z_zzzz_yyyyz_1[i] * pc_x[i];

        ta1_z_xzzzz_yyyzz_0[i] = ta1_z_zzzz_yyyzz_0[i] * pa_x[i] - ta1_z_zzzz_yyyzz_1[i] * pc_x[i];

        ta1_z_xzzzz_yyzzz_0[i] = ta1_z_zzzz_yyzzz_0[i] * pa_x[i] - ta1_z_zzzz_yyzzz_1[i] * pc_x[i];

        ta1_z_xzzzz_yzzzz_0[i] = ta1_z_zzzz_yzzzz_0[i] * pa_x[i] - ta1_z_zzzz_yzzzz_1[i] * pc_x[i];

        ta1_z_xzzzz_zzzzz_0[i] = ta1_z_zzzz_zzzzz_0[i] * pa_x[i] - ta1_z_zzzz_zzzzz_1[i] * pc_x[i];
    }

    // Set up 1197-1218 components of targeted buffer : HH

    auto ta1_z_yyyyy_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1197);

    auto ta1_z_yyyyy_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1198);

    auto ta1_z_yyyyy_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1199);

    auto ta1_z_yyyyy_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1200);

    auto ta1_z_yyyyy_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1201);

    auto ta1_z_yyyyy_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1202);

    auto ta1_z_yyyyy_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1203);

    auto ta1_z_yyyyy_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1204);

    auto ta1_z_yyyyy_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1205);

    auto ta1_z_yyyyy_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1206);

    auto ta1_z_yyyyy_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1207);

    auto ta1_z_yyyyy_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1208);

    auto ta1_z_yyyyy_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1209);

    auto ta1_z_yyyyy_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1210);

    auto ta1_z_yyyyy_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1211);

    auto ta1_z_yyyyy_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1212);

    auto ta1_z_yyyyy_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1213);

    auto ta1_z_yyyyy_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1214);

    auto ta1_z_yyyyy_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1215);

    auto ta1_z_yyyyy_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1216);

    auto ta1_z_yyyyy_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1217);

    #pragma omp simd aligned(pa_y, pc_y, ta1_z_yyy_xxxxx_0, ta1_z_yyy_xxxxx_1, ta1_z_yyy_xxxxy_0, ta1_z_yyy_xxxxy_1, ta1_z_yyy_xxxxz_0, ta1_z_yyy_xxxxz_1, ta1_z_yyy_xxxyy_0, ta1_z_yyy_xxxyy_1, ta1_z_yyy_xxxyz_0, ta1_z_yyy_xxxyz_1, ta1_z_yyy_xxxzz_0, ta1_z_yyy_xxxzz_1, ta1_z_yyy_xxyyy_0, ta1_z_yyy_xxyyy_1, ta1_z_yyy_xxyyz_0, ta1_z_yyy_xxyyz_1, ta1_z_yyy_xxyzz_0, ta1_z_yyy_xxyzz_1, ta1_z_yyy_xxzzz_0, ta1_z_yyy_xxzzz_1, ta1_z_yyy_xyyyy_0, ta1_z_yyy_xyyyy_1, ta1_z_yyy_xyyyz_0, ta1_z_yyy_xyyyz_1, ta1_z_yyy_xyyzz_0, ta1_z_yyy_xyyzz_1, ta1_z_yyy_xyzzz_0, ta1_z_yyy_xyzzz_1, ta1_z_yyy_xzzzz_0, ta1_z_yyy_xzzzz_1, ta1_z_yyy_yyyyy_0, ta1_z_yyy_yyyyy_1, ta1_z_yyy_yyyyz_0, ta1_z_yyy_yyyyz_1, ta1_z_yyy_yyyzz_0, ta1_z_yyy_yyyzz_1, ta1_z_yyy_yyzzz_0, ta1_z_yyy_yyzzz_1, ta1_z_yyy_yzzzz_0, ta1_z_yyy_yzzzz_1, ta1_z_yyy_zzzzz_0, ta1_z_yyy_zzzzz_1, ta1_z_yyyy_xxxx_0, ta1_z_yyyy_xxxx_1, ta1_z_yyyy_xxxxx_0, ta1_z_yyyy_xxxxx_1, ta1_z_yyyy_xxxxy_0, ta1_z_yyyy_xxxxy_1, ta1_z_yyyy_xxxxz_0, ta1_z_yyyy_xxxxz_1, ta1_z_yyyy_xxxy_0, ta1_z_yyyy_xxxy_1, ta1_z_yyyy_xxxyy_0, ta1_z_yyyy_xxxyy_1, ta1_z_yyyy_xxxyz_0, ta1_z_yyyy_xxxyz_1, ta1_z_yyyy_xxxz_0, ta1_z_yyyy_xxxz_1, ta1_z_yyyy_xxxzz_0, ta1_z_yyyy_xxxzz_1, ta1_z_yyyy_xxyy_0, ta1_z_yyyy_xxyy_1, ta1_z_yyyy_xxyyy_0, ta1_z_yyyy_xxyyy_1, ta1_z_yyyy_xxyyz_0, ta1_z_yyyy_xxyyz_1, ta1_z_yyyy_xxyz_0, ta1_z_yyyy_xxyz_1, ta1_z_yyyy_xxyzz_0, ta1_z_yyyy_xxyzz_1, ta1_z_yyyy_xxzz_0, ta1_z_yyyy_xxzz_1, ta1_z_yyyy_xxzzz_0, ta1_z_yyyy_xxzzz_1, ta1_z_yyyy_xyyy_0, ta1_z_yyyy_xyyy_1, ta1_z_yyyy_xyyyy_0, ta1_z_yyyy_xyyyy_1, ta1_z_yyyy_xyyyz_0, ta1_z_yyyy_xyyyz_1, ta1_z_yyyy_xyyz_0, ta1_z_yyyy_xyyz_1, ta1_z_yyyy_xyyzz_0, ta1_z_yyyy_xyyzz_1, ta1_z_yyyy_xyzz_0, ta1_z_yyyy_xyzz_1, ta1_z_yyyy_xyzzz_0, ta1_z_yyyy_xyzzz_1, ta1_z_yyyy_xzzz_0, ta1_z_yyyy_xzzz_1, ta1_z_yyyy_xzzzz_0, ta1_z_yyyy_xzzzz_1, ta1_z_yyyy_yyyy_0, ta1_z_yyyy_yyyy_1, ta1_z_yyyy_yyyyy_0, ta1_z_yyyy_yyyyy_1, ta1_z_yyyy_yyyyz_0, ta1_z_yyyy_yyyyz_1, ta1_z_yyyy_yyyz_0, ta1_z_yyyy_yyyz_1, ta1_z_yyyy_yyyzz_0, ta1_z_yyyy_yyyzz_1, ta1_z_yyyy_yyzz_0, ta1_z_yyyy_yyzz_1, ta1_z_yyyy_yyzzz_0, ta1_z_yyyy_yyzzz_1, ta1_z_yyyy_yzzz_0, ta1_z_yyyy_yzzz_1, ta1_z_yyyy_yzzzz_0, ta1_z_yyyy_yzzzz_1, ta1_z_yyyy_zzzz_0, ta1_z_yyyy_zzzz_1, ta1_z_yyyy_zzzzz_0, ta1_z_yyyy_zzzzz_1, ta1_z_yyyyy_xxxxx_0, ta1_z_yyyyy_xxxxy_0, ta1_z_yyyyy_xxxxz_0, ta1_z_yyyyy_xxxyy_0, ta1_z_yyyyy_xxxyz_0, ta1_z_yyyyy_xxxzz_0, ta1_z_yyyyy_xxyyy_0, ta1_z_yyyyy_xxyyz_0, ta1_z_yyyyy_xxyzz_0, ta1_z_yyyyy_xxzzz_0, ta1_z_yyyyy_xyyyy_0, ta1_z_yyyyy_xyyyz_0, ta1_z_yyyyy_xyyzz_0, ta1_z_yyyyy_xyzzz_0, ta1_z_yyyyy_xzzzz_0, ta1_z_yyyyy_yyyyy_0, ta1_z_yyyyy_yyyyz_0, ta1_z_yyyyy_yyyzz_0, ta1_z_yyyyy_yyzzz_0, ta1_z_yyyyy_yzzzz_0, ta1_z_yyyyy_zzzzz_0, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_yyyyy_xxxxx_0[i] = 4.0 * ta1_z_yyy_xxxxx_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxxx_1[i] * fe_0 + ta1_z_yyyy_xxxxx_0[i] * pa_y[i] - ta1_z_yyyy_xxxxx_1[i] * pc_y[i];

        ta1_z_yyyyy_xxxxy_0[i] = 4.0 * ta1_z_yyy_xxxxy_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxxy_1[i] * fe_0 + ta1_z_yyyy_xxxx_0[i] * fe_0 - ta1_z_yyyy_xxxx_1[i] * fe_0 + ta1_z_yyyy_xxxxy_0[i] * pa_y[i] - ta1_z_yyyy_xxxxy_1[i] * pc_y[i];

        ta1_z_yyyyy_xxxxz_0[i] = 4.0 * ta1_z_yyy_xxxxz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxxz_1[i] * fe_0 + ta1_z_yyyy_xxxxz_0[i] * pa_y[i] - ta1_z_yyyy_xxxxz_1[i] * pc_y[i];

        ta1_z_yyyyy_xxxyy_0[i] = 4.0 * ta1_z_yyy_xxxyy_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxyy_1[i] * fe_0 + 2.0 * ta1_z_yyyy_xxxy_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xxxy_1[i] * fe_0 + ta1_z_yyyy_xxxyy_0[i] * pa_y[i] - ta1_z_yyyy_xxxyy_1[i] * pc_y[i];

        ta1_z_yyyyy_xxxyz_0[i] = 4.0 * ta1_z_yyy_xxxyz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxyz_1[i] * fe_0 + ta1_z_yyyy_xxxz_0[i] * fe_0 - ta1_z_yyyy_xxxz_1[i] * fe_0 + ta1_z_yyyy_xxxyz_0[i] * pa_y[i] - ta1_z_yyyy_xxxyz_1[i] * pc_y[i];

        ta1_z_yyyyy_xxxzz_0[i] = 4.0 * ta1_z_yyy_xxxzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxxzz_1[i] * fe_0 + ta1_z_yyyy_xxxzz_0[i] * pa_y[i] - ta1_z_yyyy_xxxzz_1[i] * pc_y[i];

        ta1_z_yyyyy_xxyyy_0[i] = 4.0 * ta1_z_yyy_xxyyy_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxyyy_1[i] * fe_0 + 3.0 * ta1_z_yyyy_xxyy_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xxyy_1[i] * fe_0 + ta1_z_yyyy_xxyyy_0[i] * pa_y[i] - ta1_z_yyyy_xxyyy_1[i] * pc_y[i];

        ta1_z_yyyyy_xxyyz_0[i] = 4.0 * ta1_z_yyy_xxyyz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xxyz_1[i] * fe_0 + ta1_z_yyyy_xxyyz_0[i] * pa_y[i] - ta1_z_yyyy_xxyyz_1[i] * pc_y[i];

        ta1_z_yyyyy_xxyzz_0[i] = 4.0 * ta1_z_yyy_xxyzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxyzz_1[i] * fe_0 + ta1_z_yyyy_xxzz_0[i] * fe_0 - ta1_z_yyyy_xxzz_1[i] * fe_0 + ta1_z_yyyy_xxyzz_0[i] * pa_y[i] - ta1_z_yyyy_xxyzz_1[i] * pc_y[i];

        ta1_z_yyyyy_xxzzz_0[i] = 4.0 * ta1_z_yyy_xxzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xxzzz_1[i] * fe_0 + ta1_z_yyyy_xxzzz_0[i] * pa_y[i] - ta1_z_yyyy_xxzzz_1[i] * pc_y[i];

        ta1_z_yyyyy_xyyyy_0[i] = 4.0 * ta1_z_yyy_xyyyy_0[i] * fe_0 - 4.0 * ta1_z_yyy_xyyyy_1[i] * fe_0 + 4.0 * ta1_z_yyyy_xyyy_0[i] * fe_0 - 4.0 * ta1_z_yyyy_xyyy_1[i] * fe_0 + ta1_z_yyyy_xyyyy_0[i] * pa_y[i] - ta1_z_yyyy_xyyyy_1[i] * pc_y[i];

        ta1_z_yyyyy_xyyyz_0[i] = 4.0 * ta1_z_yyy_xyyyz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xyyyz_1[i] * fe_0 + 3.0 * ta1_z_yyyy_xyyz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xyyz_1[i] * fe_0 + ta1_z_yyyy_xyyyz_0[i] * pa_y[i] - ta1_z_yyyy_xyyyz_1[i] * pc_y[i];

        ta1_z_yyyyy_xyyzz_0[i] = 4.0 * ta1_z_yyy_xyyzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xyyzz_1[i] * fe_0 + 2.0 * ta1_z_yyyy_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xyzz_1[i] * fe_0 + ta1_z_yyyy_xyyzz_0[i] * pa_y[i] - ta1_z_yyyy_xyyzz_1[i] * pc_y[i];

        ta1_z_yyyyy_xyzzz_0[i] = 4.0 * ta1_z_yyy_xyzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xyzzz_1[i] * fe_0 + ta1_z_yyyy_xzzz_0[i] * fe_0 - ta1_z_yyyy_xzzz_1[i] * fe_0 + ta1_z_yyyy_xyzzz_0[i] * pa_y[i] - ta1_z_yyyy_xyzzz_1[i] * pc_y[i];

        ta1_z_yyyyy_xzzzz_0[i] = 4.0 * ta1_z_yyy_xzzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_xzzzz_1[i] * fe_0 + ta1_z_yyyy_xzzzz_0[i] * pa_y[i] - ta1_z_yyyy_xzzzz_1[i] * pc_y[i];

        ta1_z_yyyyy_yyyyy_0[i] = 4.0 * ta1_z_yyy_yyyyy_0[i] * fe_0 - 4.0 * ta1_z_yyy_yyyyy_1[i] * fe_0 + 5.0 * ta1_z_yyyy_yyyy_0[i] * fe_0 - 5.0 * ta1_z_yyyy_yyyy_1[i] * fe_0 + ta1_z_yyyy_yyyyy_0[i] * pa_y[i] - ta1_z_yyyy_yyyyy_1[i] * pc_y[i];

        ta1_z_yyyyy_yyyyz_0[i] = 4.0 * ta1_z_yyy_yyyyz_0[i] * fe_0 - 4.0 * ta1_z_yyy_yyyyz_1[i] * fe_0 + 4.0 * ta1_z_yyyy_yyyz_0[i] * fe_0 - 4.0 * ta1_z_yyyy_yyyz_1[i] * fe_0 + ta1_z_yyyy_yyyyz_0[i] * pa_y[i] - ta1_z_yyyy_yyyyz_1[i] * pc_y[i];

        ta1_z_yyyyy_yyyzz_0[i] = 4.0 * ta1_z_yyy_yyyzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_yyyzz_1[i] * fe_0 + 3.0 * ta1_z_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_yyzz_1[i] * fe_0 + ta1_z_yyyy_yyyzz_0[i] * pa_y[i] - ta1_z_yyyy_yyyzz_1[i] * pc_y[i];

        ta1_z_yyyyy_yyzzz_0[i] = 4.0 * ta1_z_yyy_yyzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_yyzzz_1[i] * fe_0 + 2.0 * ta1_z_yyyy_yzzz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_yzzz_1[i] * fe_0 + ta1_z_yyyy_yyzzz_0[i] * pa_y[i] - ta1_z_yyyy_yyzzz_1[i] * pc_y[i];

        ta1_z_yyyyy_yzzzz_0[i] = 4.0 * ta1_z_yyy_yzzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_yzzzz_1[i] * fe_0 + ta1_z_yyyy_zzzz_0[i] * fe_0 - ta1_z_yyyy_zzzz_1[i] * fe_0 + ta1_z_yyyy_yzzzz_0[i] * pa_y[i] - ta1_z_yyyy_yzzzz_1[i] * pc_y[i];

        ta1_z_yyyyy_zzzzz_0[i] = 4.0 * ta1_z_yyy_zzzzz_0[i] * fe_0 - 4.0 * ta1_z_yyy_zzzzz_1[i] * fe_0 + ta1_z_yyyy_zzzzz_0[i] * pa_y[i] - ta1_z_yyyy_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1218-1239 components of targeted buffer : HH

    auto ta1_z_yyyyz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1218);

    auto ta1_z_yyyyz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1219);

    auto ta1_z_yyyyz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1220);

    auto ta1_z_yyyyz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1221);

    auto ta1_z_yyyyz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1222);

    auto ta1_z_yyyyz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1223);

    auto ta1_z_yyyyz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1224);

    auto ta1_z_yyyyz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1225);

    auto ta1_z_yyyyz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1226);

    auto ta1_z_yyyyz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1227);

    auto ta1_z_yyyyz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1228);

    auto ta1_z_yyyyz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1229);

    auto ta1_z_yyyyz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1230);

    auto ta1_z_yyyyz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1231);

    auto ta1_z_yyyyz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1232);

    auto ta1_z_yyyyz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1233);

    auto ta1_z_yyyyz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1234);

    auto ta1_z_yyyyz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1235);

    auto ta1_z_yyyyz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1236);

    auto ta1_z_yyyyz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1237);

    auto ta1_z_yyyyz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1238);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_z_yyyy_xxxxx_0, ta1_z_yyyy_xxxxx_1, ta1_z_yyyy_xxxxy_0, ta1_z_yyyy_xxxxy_1, ta1_z_yyyy_xxxy_0, ta1_z_yyyy_xxxy_1, ta1_z_yyyy_xxxyy_0, ta1_z_yyyy_xxxyy_1, ta1_z_yyyy_xxxyz_0, ta1_z_yyyy_xxxyz_1, ta1_z_yyyy_xxyy_0, ta1_z_yyyy_xxyy_1, ta1_z_yyyy_xxyyy_0, ta1_z_yyyy_xxyyy_1, ta1_z_yyyy_xxyyz_0, ta1_z_yyyy_xxyyz_1, ta1_z_yyyy_xxyz_0, ta1_z_yyyy_xxyz_1, ta1_z_yyyy_xxyzz_0, ta1_z_yyyy_xxyzz_1, ta1_z_yyyy_xyyy_0, ta1_z_yyyy_xyyy_1, ta1_z_yyyy_xyyyy_0, ta1_z_yyyy_xyyyy_1, ta1_z_yyyy_xyyyz_0, ta1_z_yyyy_xyyyz_1, ta1_z_yyyy_xyyz_0, ta1_z_yyyy_xyyz_1, ta1_z_yyyy_xyyzz_0, ta1_z_yyyy_xyyzz_1, ta1_z_yyyy_xyzz_0, ta1_z_yyyy_xyzz_1, ta1_z_yyyy_xyzzz_0, ta1_z_yyyy_xyzzz_1, ta1_z_yyyy_yyyy_0, ta1_z_yyyy_yyyy_1, ta1_z_yyyy_yyyyy_0, ta1_z_yyyy_yyyyy_1, ta1_z_yyyy_yyyyz_0, ta1_z_yyyy_yyyyz_1, ta1_z_yyyy_yyyz_0, ta1_z_yyyy_yyyz_1, ta1_z_yyyy_yyyzz_0, ta1_z_yyyy_yyyzz_1, ta1_z_yyyy_yyzz_0, ta1_z_yyyy_yyzz_1, ta1_z_yyyy_yyzzz_0, ta1_z_yyyy_yyzzz_1, ta1_z_yyyy_yzzz_0, ta1_z_yyyy_yzzz_1, ta1_z_yyyy_yzzzz_0, ta1_z_yyyy_yzzzz_1, ta1_z_yyyyz_xxxxx_0, ta1_z_yyyyz_xxxxy_0, ta1_z_yyyyz_xxxxz_0, ta1_z_yyyyz_xxxyy_0, ta1_z_yyyyz_xxxyz_0, ta1_z_yyyyz_xxxzz_0, ta1_z_yyyyz_xxyyy_0, ta1_z_yyyyz_xxyyz_0, ta1_z_yyyyz_xxyzz_0, ta1_z_yyyyz_xxzzz_0, ta1_z_yyyyz_xyyyy_0, ta1_z_yyyyz_xyyyz_0, ta1_z_yyyyz_xyyzz_0, ta1_z_yyyyz_xyzzz_0, ta1_z_yyyyz_xzzzz_0, ta1_z_yyyyz_yyyyy_0, ta1_z_yyyyz_yyyyz_0, ta1_z_yyyyz_yyyzz_0, ta1_z_yyyyz_yyzzz_0, ta1_z_yyyyz_yzzzz_0, ta1_z_yyyyz_zzzzz_0, ta1_z_yyyz_xxxxz_0, ta1_z_yyyz_xxxxz_1, ta1_z_yyyz_xxxzz_0, ta1_z_yyyz_xxxzz_1, ta1_z_yyyz_xxzzz_0, ta1_z_yyyz_xxzzz_1, ta1_z_yyyz_xzzzz_0, ta1_z_yyyz_xzzzz_1, ta1_z_yyyz_zzzzz_0, ta1_z_yyyz_zzzzz_1, ta1_z_yyz_xxxxz_0, ta1_z_yyz_xxxxz_1, ta1_z_yyz_xxxzz_0, ta1_z_yyz_xxxzz_1, ta1_z_yyz_xxzzz_0, ta1_z_yyz_xxzzz_1, ta1_z_yyz_xzzzz_0, ta1_z_yyz_xzzzz_1, ta1_z_yyz_zzzzz_0, ta1_z_yyz_zzzzz_1, ta_yyyy_xxxxx_1, ta_yyyy_xxxxy_1, ta_yyyy_xxxyy_1, ta_yyyy_xxxyz_1, ta_yyyy_xxyyy_1, ta_yyyy_xxyyz_1, ta_yyyy_xxyzz_1, ta_yyyy_xyyyy_1, ta_yyyy_xyyyz_1, ta_yyyy_xyyzz_1, ta_yyyy_xyzzz_1, ta_yyyy_yyyyy_1, ta_yyyy_yyyyz_1, ta_yyyy_yyyzz_1, ta_yyyy_yyzzz_1, ta_yyyy_yzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_yyyyz_xxxxx_0[i] = ta_yyyy_xxxxx_1[i] + ta1_z_yyyy_xxxxx_0[i] * pa_z[i] - ta1_z_yyyy_xxxxx_1[i] * pc_z[i];

        ta1_z_yyyyz_xxxxy_0[i] = ta_yyyy_xxxxy_1[i] + ta1_z_yyyy_xxxxy_0[i] * pa_z[i] - ta1_z_yyyy_xxxxy_1[i] * pc_z[i];

        ta1_z_yyyyz_xxxxz_0[i] = 3.0 * ta1_z_yyz_xxxxz_0[i] * fe_0 - 3.0 * ta1_z_yyz_xxxxz_1[i] * fe_0 + ta1_z_yyyz_xxxxz_0[i] * pa_y[i] - ta1_z_yyyz_xxxxz_1[i] * pc_y[i];

        ta1_z_yyyyz_xxxyy_0[i] = ta_yyyy_xxxyy_1[i] + ta1_z_yyyy_xxxyy_0[i] * pa_z[i] - ta1_z_yyyy_xxxyy_1[i] * pc_z[i];

        ta1_z_yyyyz_xxxyz_0[i] = ta1_z_yyyy_xxxy_0[i] * fe_0 - ta1_z_yyyy_xxxy_1[i] * fe_0 + ta_yyyy_xxxyz_1[i] + ta1_z_yyyy_xxxyz_0[i] * pa_z[i] - ta1_z_yyyy_xxxyz_1[i] * pc_z[i];

        ta1_z_yyyyz_xxxzz_0[i] = 3.0 * ta1_z_yyz_xxxzz_0[i] * fe_0 - 3.0 * ta1_z_yyz_xxxzz_1[i] * fe_0 + ta1_z_yyyz_xxxzz_0[i] * pa_y[i] - ta1_z_yyyz_xxxzz_1[i] * pc_y[i];

        ta1_z_yyyyz_xxyyy_0[i] = ta_yyyy_xxyyy_1[i] + ta1_z_yyyy_xxyyy_0[i] * pa_z[i] - ta1_z_yyyy_xxyyy_1[i] * pc_z[i];

        ta1_z_yyyyz_xxyyz_0[i] = ta1_z_yyyy_xxyy_0[i] * fe_0 - ta1_z_yyyy_xxyy_1[i] * fe_0 + ta_yyyy_xxyyz_1[i] + ta1_z_yyyy_xxyyz_0[i] * pa_z[i] - ta1_z_yyyy_xxyyz_1[i] * pc_z[i];

        ta1_z_yyyyz_xxyzz_0[i] = 2.0 * ta1_z_yyyy_xxyz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xxyz_1[i] * fe_0 + ta_yyyy_xxyzz_1[i] + ta1_z_yyyy_xxyzz_0[i] * pa_z[i] - ta1_z_yyyy_xxyzz_1[i] * pc_z[i];

        ta1_z_yyyyz_xxzzz_0[i] = 3.0 * ta1_z_yyz_xxzzz_0[i] * fe_0 - 3.0 * ta1_z_yyz_xxzzz_1[i] * fe_0 + ta1_z_yyyz_xxzzz_0[i] * pa_y[i] - ta1_z_yyyz_xxzzz_1[i] * pc_y[i];

        ta1_z_yyyyz_xyyyy_0[i] = ta_yyyy_xyyyy_1[i] + ta1_z_yyyy_xyyyy_0[i] * pa_z[i] - ta1_z_yyyy_xyyyy_1[i] * pc_z[i];

        ta1_z_yyyyz_xyyyz_0[i] = ta1_z_yyyy_xyyy_0[i] * fe_0 - ta1_z_yyyy_xyyy_1[i] * fe_0 + ta_yyyy_xyyyz_1[i] + ta1_z_yyyy_xyyyz_0[i] * pa_z[i] - ta1_z_yyyy_xyyyz_1[i] * pc_z[i];

        ta1_z_yyyyz_xyyzz_0[i] = 2.0 * ta1_z_yyyy_xyyz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_xyyz_1[i] * fe_0 + ta_yyyy_xyyzz_1[i] + ta1_z_yyyy_xyyzz_0[i] * pa_z[i] - ta1_z_yyyy_xyyzz_1[i] * pc_z[i];

        ta1_z_yyyyz_xyzzz_0[i] = 3.0 * ta1_z_yyyy_xyzz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_xyzz_1[i] * fe_0 + ta_yyyy_xyzzz_1[i] + ta1_z_yyyy_xyzzz_0[i] * pa_z[i] - ta1_z_yyyy_xyzzz_1[i] * pc_z[i];

        ta1_z_yyyyz_xzzzz_0[i] = 3.0 * ta1_z_yyz_xzzzz_0[i] * fe_0 - 3.0 * ta1_z_yyz_xzzzz_1[i] * fe_0 + ta1_z_yyyz_xzzzz_0[i] * pa_y[i] - ta1_z_yyyz_xzzzz_1[i] * pc_y[i];

        ta1_z_yyyyz_yyyyy_0[i] = ta_yyyy_yyyyy_1[i] + ta1_z_yyyy_yyyyy_0[i] * pa_z[i] - ta1_z_yyyy_yyyyy_1[i] * pc_z[i];

        ta1_z_yyyyz_yyyyz_0[i] = ta1_z_yyyy_yyyy_0[i] * fe_0 - ta1_z_yyyy_yyyy_1[i] * fe_0 + ta_yyyy_yyyyz_1[i] + ta1_z_yyyy_yyyyz_0[i] * pa_z[i] - ta1_z_yyyy_yyyyz_1[i] * pc_z[i];

        ta1_z_yyyyz_yyyzz_0[i] = 2.0 * ta1_z_yyyy_yyyz_0[i] * fe_0 - 2.0 * ta1_z_yyyy_yyyz_1[i] * fe_0 + ta_yyyy_yyyzz_1[i] + ta1_z_yyyy_yyyzz_0[i] * pa_z[i] - ta1_z_yyyy_yyyzz_1[i] * pc_z[i];

        ta1_z_yyyyz_yyzzz_0[i] = 3.0 * ta1_z_yyyy_yyzz_0[i] * fe_0 - 3.0 * ta1_z_yyyy_yyzz_1[i] * fe_0 + ta_yyyy_yyzzz_1[i] + ta1_z_yyyy_yyzzz_0[i] * pa_z[i] - ta1_z_yyyy_yyzzz_1[i] * pc_z[i];

        ta1_z_yyyyz_yzzzz_0[i] = 4.0 * ta1_z_yyyy_yzzz_0[i] * fe_0 - 4.0 * ta1_z_yyyy_yzzz_1[i] * fe_0 + ta_yyyy_yzzzz_1[i] + ta1_z_yyyy_yzzzz_0[i] * pa_z[i] - ta1_z_yyyy_yzzzz_1[i] * pc_z[i];

        ta1_z_yyyyz_zzzzz_0[i] = 3.0 * ta1_z_yyz_zzzzz_0[i] * fe_0 - 3.0 * ta1_z_yyz_zzzzz_1[i] * fe_0 + ta1_z_yyyz_zzzzz_0[i] * pa_y[i] - ta1_z_yyyz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1239-1260 components of targeted buffer : HH

    auto ta1_z_yyyzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1239);

    auto ta1_z_yyyzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1240);

    auto ta1_z_yyyzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1241);

    auto ta1_z_yyyzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1242);

    auto ta1_z_yyyzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1243);

    auto ta1_z_yyyzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1244);

    auto ta1_z_yyyzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1245);

    auto ta1_z_yyyzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1246);

    auto ta1_z_yyyzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1247);

    auto ta1_z_yyyzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1248);

    auto ta1_z_yyyzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1249);

    auto ta1_z_yyyzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1250);

    auto ta1_z_yyyzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1251);

    auto ta1_z_yyyzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1252);

    auto ta1_z_yyyzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1253);

    auto ta1_z_yyyzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1254);

    auto ta1_z_yyyzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1255);

    auto ta1_z_yyyzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1256);

    auto ta1_z_yyyzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1257);

    auto ta1_z_yyyzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1258);

    auto ta1_z_yyyzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1259);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_z_yyy_xxxxy_0, ta1_z_yyy_xxxxy_1, ta1_z_yyy_xxxyy_0, ta1_z_yyy_xxxyy_1, ta1_z_yyy_xxyyy_0, ta1_z_yyy_xxyyy_1, ta1_z_yyy_xyyyy_0, ta1_z_yyy_xyyyy_1, ta1_z_yyy_yyyyy_0, ta1_z_yyy_yyyyy_1, ta1_z_yyyz_xxxxy_0, ta1_z_yyyz_xxxxy_1, ta1_z_yyyz_xxxyy_0, ta1_z_yyyz_xxxyy_1, ta1_z_yyyz_xxyyy_0, ta1_z_yyyz_xxyyy_1, ta1_z_yyyz_xyyyy_0, ta1_z_yyyz_xyyyy_1, ta1_z_yyyz_yyyyy_0, ta1_z_yyyz_yyyyy_1, ta1_z_yyyzz_xxxxx_0, ta1_z_yyyzz_xxxxy_0, ta1_z_yyyzz_xxxxz_0, ta1_z_yyyzz_xxxyy_0, ta1_z_yyyzz_xxxyz_0, ta1_z_yyyzz_xxxzz_0, ta1_z_yyyzz_xxyyy_0, ta1_z_yyyzz_xxyyz_0, ta1_z_yyyzz_xxyzz_0, ta1_z_yyyzz_xxzzz_0, ta1_z_yyyzz_xyyyy_0, ta1_z_yyyzz_xyyyz_0, ta1_z_yyyzz_xyyzz_0, ta1_z_yyyzz_xyzzz_0, ta1_z_yyyzz_xzzzz_0, ta1_z_yyyzz_yyyyy_0, ta1_z_yyyzz_yyyyz_0, ta1_z_yyyzz_yyyzz_0, ta1_z_yyyzz_yyzzz_0, ta1_z_yyyzz_yzzzz_0, ta1_z_yyyzz_zzzzz_0, ta1_z_yyzz_xxxxx_0, ta1_z_yyzz_xxxxx_1, ta1_z_yyzz_xxxxz_0, ta1_z_yyzz_xxxxz_1, ta1_z_yyzz_xxxyz_0, ta1_z_yyzz_xxxyz_1, ta1_z_yyzz_xxxz_0, ta1_z_yyzz_xxxz_1, ta1_z_yyzz_xxxzz_0, ta1_z_yyzz_xxxzz_1, ta1_z_yyzz_xxyyz_0, ta1_z_yyzz_xxyyz_1, ta1_z_yyzz_xxyz_0, ta1_z_yyzz_xxyz_1, ta1_z_yyzz_xxyzz_0, ta1_z_yyzz_xxyzz_1, ta1_z_yyzz_xxzz_0, ta1_z_yyzz_xxzz_1, ta1_z_yyzz_xxzzz_0, ta1_z_yyzz_xxzzz_1, ta1_z_yyzz_xyyyz_0, ta1_z_yyzz_xyyyz_1, ta1_z_yyzz_xyyz_0, ta1_z_yyzz_xyyz_1, ta1_z_yyzz_xyyzz_0, ta1_z_yyzz_xyyzz_1, ta1_z_yyzz_xyzz_0, ta1_z_yyzz_xyzz_1, ta1_z_yyzz_xyzzz_0, ta1_z_yyzz_xyzzz_1, ta1_z_yyzz_xzzz_0, ta1_z_yyzz_xzzz_1, ta1_z_yyzz_xzzzz_0, ta1_z_yyzz_xzzzz_1, ta1_z_yyzz_yyyyz_0, ta1_z_yyzz_yyyyz_1, ta1_z_yyzz_yyyz_0, ta1_z_yyzz_yyyz_1, ta1_z_yyzz_yyyzz_0, ta1_z_yyzz_yyyzz_1, ta1_z_yyzz_yyzz_0, ta1_z_yyzz_yyzz_1, ta1_z_yyzz_yyzzz_0, ta1_z_yyzz_yyzzz_1, ta1_z_yyzz_yzzz_0, ta1_z_yyzz_yzzz_1, ta1_z_yyzz_yzzzz_0, ta1_z_yyzz_yzzzz_1, ta1_z_yyzz_zzzz_0, ta1_z_yyzz_zzzz_1, ta1_z_yyzz_zzzzz_0, ta1_z_yyzz_zzzzz_1, ta1_z_yzz_xxxxx_0, ta1_z_yzz_xxxxx_1, ta1_z_yzz_xxxxz_0, ta1_z_yzz_xxxxz_1, ta1_z_yzz_xxxyz_0, ta1_z_yzz_xxxyz_1, ta1_z_yzz_xxxzz_0, ta1_z_yzz_xxxzz_1, ta1_z_yzz_xxyyz_0, ta1_z_yzz_xxyyz_1, ta1_z_yzz_xxyzz_0, ta1_z_yzz_xxyzz_1, ta1_z_yzz_xxzzz_0, ta1_z_yzz_xxzzz_1, ta1_z_yzz_xyyyz_0, ta1_z_yzz_xyyyz_1, ta1_z_yzz_xyyzz_0, ta1_z_yzz_xyyzz_1, ta1_z_yzz_xyzzz_0, ta1_z_yzz_xyzzz_1, ta1_z_yzz_xzzzz_0, ta1_z_yzz_xzzzz_1, ta1_z_yzz_yyyyz_0, ta1_z_yzz_yyyyz_1, ta1_z_yzz_yyyzz_0, ta1_z_yzz_yyyzz_1, ta1_z_yzz_yyzzz_0, ta1_z_yzz_yyzzz_1, ta1_z_yzz_yzzzz_0, ta1_z_yzz_yzzzz_1, ta1_z_yzz_zzzzz_0, ta1_z_yzz_zzzzz_1, ta_yyyz_xxxxy_1, ta_yyyz_xxxyy_1, ta_yyyz_xxyyy_1, ta_yyyz_xyyyy_1, ta_yyyz_yyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_yyyzz_xxxxx_0[i] = 2.0 * ta1_z_yzz_xxxxx_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxxxx_1[i] * fe_0 + ta1_z_yyzz_xxxxx_0[i] * pa_y[i] - ta1_z_yyzz_xxxxx_1[i] * pc_y[i];

        ta1_z_yyyzz_xxxxy_0[i] = ta1_z_yyy_xxxxy_0[i] * fe_0 - ta1_z_yyy_xxxxy_1[i] * fe_0 + ta_yyyz_xxxxy_1[i] + ta1_z_yyyz_xxxxy_0[i] * pa_z[i] - ta1_z_yyyz_xxxxy_1[i] * pc_z[i];

        ta1_z_yyyzz_xxxxz_0[i] = 2.0 * ta1_z_yzz_xxxxz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxxxz_1[i] * fe_0 + ta1_z_yyzz_xxxxz_0[i] * pa_y[i] - ta1_z_yyzz_xxxxz_1[i] * pc_y[i];

        ta1_z_yyyzz_xxxyy_0[i] = ta1_z_yyy_xxxyy_0[i] * fe_0 - ta1_z_yyy_xxxyy_1[i] * fe_0 + ta_yyyz_xxxyy_1[i] + ta1_z_yyyz_xxxyy_0[i] * pa_z[i] - ta1_z_yyyz_xxxyy_1[i] * pc_z[i];

        ta1_z_yyyzz_xxxyz_0[i] = 2.0 * ta1_z_yzz_xxxyz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxxyz_1[i] * fe_0 + ta1_z_yyzz_xxxz_0[i] * fe_0 - ta1_z_yyzz_xxxz_1[i] * fe_0 + ta1_z_yyzz_xxxyz_0[i] * pa_y[i] - ta1_z_yyzz_xxxyz_1[i] * pc_y[i];

        ta1_z_yyyzz_xxxzz_0[i] = 2.0 * ta1_z_yzz_xxxzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxxzz_1[i] * fe_0 + ta1_z_yyzz_xxxzz_0[i] * pa_y[i] - ta1_z_yyzz_xxxzz_1[i] * pc_y[i];

        ta1_z_yyyzz_xxyyy_0[i] = ta1_z_yyy_xxyyy_0[i] * fe_0 - ta1_z_yyy_xxyyy_1[i] * fe_0 + ta_yyyz_xxyyy_1[i] + ta1_z_yyyz_xxyyy_0[i] * pa_z[i] - ta1_z_yyyz_xxyyy_1[i] * pc_z[i];

        ta1_z_yyyzz_xxyyz_0[i] = 2.0 * ta1_z_yzz_xxyyz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_yyzz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xxyz_1[i] * fe_0 + ta1_z_yyzz_xxyyz_0[i] * pa_y[i] - ta1_z_yyzz_xxyyz_1[i] * pc_y[i];

        ta1_z_yyyzz_xxyzz_0[i] = 2.0 * ta1_z_yzz_xxyzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxyzz_1[i] * fe_0 + ta1_z_yyzz_xxzz_0[i] * fe_0 - ta1_z_yyzz_xxzz_1[i] * fe_0 + ta1_z_yyzz_xxyzz_0[i] * pa_y[i] - ta1_z_yyzz_xxyzz_1[i] * pc_y[i];

        ta1_z_yyyzz_xxzzz_0[i] = 2.0 * ta1_z_yzz_xxzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xxzzz_1[i] * fe_0 + ta1_z_yyzz_xxzzz_0[i] * pa_y[i] - ta1_z_yyzz_xxzzz_1[i] * pc_y[i];

        ta1_z_yyyzz_xyyyy_0[i] = ta1_z_yyy_xyyyy_0[i] * fe_0 - ta1_z_yyy_xyyyy_1[i] * fe_0 + ta_yyyz_xyyyy_1[i] + ta1_z_yyyz_xyyyy_0[i] * pa_z[i] - ta1_z_yyyz_xyyyy_1[i] * pc_z[i];

        ta1_z_yyyzz_xyyyz_0[i] = 2.0 * ta1_z_yzz_xyyyz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xyyyz_1[i] * fe_0 + 3.0 * ta1_z_yyzz_xyyz_0[i] * fe_0 - 3.0 * ta1_z_yyzz_xyyz_1[i] * fe_0 + ta1_z_yyzz_xyyyz_0[i] * pa_y[i] - ta1_z_yyzz_xyyyz_1[i] * pc_y[i];

        ta1_z_yyyzz_xyyzz_0[i] = 2.0 * ta1_z_yzz_xyyzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_z_yyzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_xyzz_1[i] * fe_0 + ta1_z_yyzz_xyyzz_0[i] * pa_y[i] - ta1_z_yyzz_xyyzz_1[i] * pc_y[i];

        ta1_z_yyyzz_xyzzz_0[i] = 2.0 * ta1_z_yzz_xyzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xyzzz_1[i] * fe_0 + ta1_z_yyzz_xzzz_0[i] * fe_0 - ta1_z_yyzz_xzzz_1[i] * fe_0 + ta1_z_yyzz_xyzzz_0[i] * pa_y[i] - ta1_z_yyzz_xyzzz_1[i] * pc_y[i];

        ta1_z_yyyzz_xzzzz_0[i] = 2.0 * ta1_z_yzz_xzzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_xzzzz_1[i] * fe_0 + ta1_z_yyzz_xzzzz_0[i] * pa_y[i] - ta1_z_yyzz_xzzzz_1[i] * pc_y[i];

        ta1_z_yyyzz_yyyyy_0[i] = ta1_z_yyy_yyyyy_0[i] * fe_0 - ta1_z_yyy_yyyyy_1[i] * fe_0 + ta_yyyz_yyyyy_1[i] + ta1_z_yyyz_yyyyy_0[i] * pa_z[i] - ta1_z_yyyz_yyyyy_1[i] * pc_z[i];

        ta1_z_yyyzz_yyyyz_0[i] = 2.0 * ta1_z_yzz_yyyyz_0[i] * fe_0 - 2.0 * ta1_z_yzz_yyyyz_1[i] * fe_0 + 4.0 * ta1_z_yyzz_yyyz_0[i] * fe_0 - 4.0 * ta1_z_yyzz_yyyz_1[i] * fe_0 + ta1_z_yyzz_yyyyz_0[i] * pa_y[i] - ta1_z_yyzz_yyyyz_1[i] * pc_y[i];

        ta1_z_yyyzz_yyyzz_0[i] = 2.0 * ta1_z_yzz_yyyzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_yyyzz_1[i] * fe_0 + 3.0 * ta1_z_yyzz_yyzz_0[i] * fe_0 - 3.0 * ta1_z_yyzz_yyzz_1[i] * fe_0 + ta1_z_yyzz_yyyzz_0[i] * pa_y[i] - ta1_z_yyzz_yyyzz_1[i] * pc_y[i];

        ta1_z_yyyzz_yyzzz_0[i] = 2.0 * ta1_z_yzz_yyzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_yyzzz_1[i] * fe_0 + 2.0 * ta1_z_yyzz_yzzz_0[i] * fe_0 - 2.0 * ta1_z_yyzz_yzzz_1[i] * fe_0 + ta1_z_yyzz_yyzzz_0[i] * pa_y[i] - ta1_z_yyzz_yyzzz_1[i] * pc_y[i];

        ta1_z_yyyzz_yzzzz_0[i] = 2.0 * ta1_z_yzz_yzzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_yzzzz_1[i] * fe_0 + ta1_z_yyzz_zzzz_0[i] * fe_0 - ta1_z_yyzz_zzzz_1[i] * fe_0 + ta1_z_yyzz_yzzzz_0[i] * pa_y[i] - ta1_z_yyzz_yzzzz_1[i] * pc_y[i];

        ta1_z_yyyzz_zzzzz_0[i] = 2.0 * ta1_z_yzz_zzzzz_0[i] * fe_0 - 2.0 * ta1_z_yzz_zzzzz_1[i] * fe_0 + ta1_z_yyzz_zzzzz_0[i] * pa_y[i] - ta1_z_yyzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1260-1281 components of targeted buffer : HH

    auto ta1_z_yyzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1260);

    auto ta1_z_yyzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1261);

    auto ta1_z_yyzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1262);

    auto ta1_z_yyzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1263);

    auto ta1_z_yyzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1264);

    auto ta1_z_yyzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1265);

    auto ta1_z_yyzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1266);

    auto ta1_z_yyzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1267);

    auto ta1_z_yyzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1268);

    auto ta1_z_yyzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1269);

    auto ta1_z_yyzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1270);

    auto ta1_z_yyzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1271);

    auto ta1_z_yyzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1272);

    auto ta1_z_yyzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1273);

    auto ta1_z_yyzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1274);

    auto ta1_z_yyzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1275);

    auto ta1_z_yyzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1276);

    auto ta1_z_yyzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1277);

    auto ta1_z_yyzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1278);

    auto ta1_z_yyzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1279);

    auto ta1_z_yyzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1280);

    #pragma omp simd aligned(pa_y, pa_z, pc_y, pc_z, ta1_z_yyz_xxxxy_0, ta1_z_yyz_xxxxy_1, ta1_z_yyz_xxxyy_0, ta1_z_yyz_xxxyy_1, ta1_z_yyz_xxyyy_0, ta1_z_yyz_xxyyy_1, ta1_z_yyz_xyyyy_0, ta1_z_yyz_xyyyy_1, ta1_z_yyz_yyyyy_0, ta1_z_yyz_yyyyy_1, ta1_z_yyzz_xxxxy_0, ta1_z_yyzz_xxxxy_1, ta1_z_yyzz_xxxyy_0, ta1_z_yyzz_xxxyy_1, ta1_z_yyzz_xxyyy_0, ta1_z_yyzz_xxyyy_1, ta1_z_yyzz_xyyyy_0, ta1_z_yyzz_xyyyy_1, ta1_z_yyzz_yyyyy_0, ta1_z_yyzz_yyyyy_1, ta1_z_yyzzz_xxxxx_0, ta1_z_yyzzz_xxxxy_0, ta1_z_yyzzz_xxxxz_0, ta1_z_yyzzz_xxxyy_0, ta1_z_yyzzz_xxxyz_0, ta1_z_yyzzz_xxxzz_0, ta1_z_yyzzz_xxyyy_0, ta1_z_yyzzz_xxyyz_0, ta1_z_yyzzz_xxyzz_0, ta1_z_yyzzz_xxzzz_0, ta1_z_yyzzz_xyyyy_0, ta1_z_yyzzz_xyyyz_0, ta1_z_yyzzz_xyyzz_0, ta1_z_yyzzz_xyzzz_0, ta1_z_yyzzz_xzzzz_0, ta1_z_yyzzz_yyyyy_0, ta1_z_yyzzz_yyyyz_0, ta1_z_yyzzz_yyyzz_0, ta1_z_yyzzz_yyzzz_0, ta1_z_yyzzz_yzzzz_0, ta1_z_yyzzz_zzzzz_0, ta1_z_yzzz_xxxxx_0, ta1_z_yzzz_xxxxx_1, ta1_z_yzzz_xxxxz_0, ta1_z_yzzz_xxxxz_1, ta1_z_yzzz_xxxyz_0, ta1_z_yzzz_xxxyz_1, ta1_z_yzzz_xxxz_0, ta1_z_yzzz_xxxz_1, ta1_z_yzzz_xxxzz_0, ta1_z_yzzz_xxxzz_1, ta1_z_yzzz_xxyyz_0, ta1_z_yzzz_xxyyz_1, ta1_z_yzzz_xxyz_0, ta1_z_yzzz_xxyz_1, ta1_z_yzzz_xxyzz_0, ta1_z_yzzz_xxyzz_1, ta1_z_yzzz_xxzz_0, ta1_z_yzzz_xxzz_1, ta1_z_yzzz_xxzzz_0, ta1_z_yzzz_xxzzz_1, ta1_z_yzzz_xyyyz_0, ta1_z_yzzz_xyyyz_1, ta1_z_yzzz_xyyz_0, ta1_z_yzzz_xyyz_1, ta1_z_yzzz_xyyzz_0, ta1_z_yzzz_xyyzz_1, ta1_z_yzzz_xyzz_0, ta1_z_yzzz_xyzz_1, ta1_z_yzzz_xyzzz_0, ta1_z_yzzz_xyzzz_1, ta1_z_yzzz_xzzz_0, ta1_z_yzzz_xzzz_1, ta1_z_yzzz_xzzzz_0, ta1_z_yzzz_xzzzz_1, ta1_z_yzzz_yyyyz_0, ta1_z_yzzz_yyyyz_1, ta1_z_yzzz_yyyz_0, ta1_z_yzzz_yyyz_1, ta1_z_yzzz_yyyzz_0, ta1_z_yzzz_yyyzz_1, ta1_z_yzzz_yyzz_0, ta1_z_yzzz_yyzz_1, ta1_z_yzzz_yyzzz_0, ta1_z_yzzz_yyzzz_1, ta1_z_yzzz_yzzz_0, ta1_z_yzzz_yzzz_1, ta1_z_yzzz_yzzzz_0, ta1_z_yzzz_yzzzz_1, ta1_z_yzzz_zzzz_0, ta1_z_yzzz_zzzz_1, ta1_z_yzzz_zzzzz_0, ta1_z_yzzz_zzzzz_1, ta1_z_zzz_xxxxx_0, ta1_z_zzz_xxxxx_1, ta1_z_zzz_xxxxz_0, ta1_z_zzz_xxxxz_1, ta1_z_zzz_xxxyz_0, ta1_z_zzz_xxxyz_1, ta1_z_zzz_xxxzz_0, ta1_z_zzz_xxxzz_1, ta1_z_zzz_xxyyz_0, ta1_z_zzz_xxyyz_1, ta1_z_zzz_xxyzz_0, ta1_z_zzz_xxyzz_1, ta1_z_zzz_xxzzz_0, ta1_z_zzz_xxzzz_1, ta1_z_zzz_xyyyz_0, ta1_z_zzz_xyyyz_1, ta1_z_zzz_xyyzz_0, ta1_z_zzz_xyyzz_1, ta1_z_zzz_xyzzz_0, ta1_z_zzz_xyzzz_1, ta1_z_zzz_xzzzz_0, ta1_z_zzz_xzzzz_1, ta1_z_zzz_yyyyz_0, ta1_z_zzz_yyyyz_1, ta1_z_zzz_yyyzz_0, ta1_z_zzz_yyyzz_1, ta1_z_zzz_yyzzz_0, ta1_z_zzz_yyzzz_1, ta1_z_zzz_yzzzz_0, ta1_z_zzz_yzzzz_1, ta1_z_zzz_zzzzz_0, ta1_z_zzz_zzzzz_1, ta_yyzz_xxxxy_1, ta_yyzz_xxxyy_1, ta_yyzz_xxyyy_1, ta_yyzz_xyyyy_1, ta_yyzz_yyyyy_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_yyzzz_xxxxx_0[i] = ta1_z_zzz_xxxxx_0[i] * fe_0 - ta1_z_zzz_xxxxx_1[i] * fe_0 + ta1_z_yzzz_xxxxx_0[i] * pa_y[i] - ta1_z_yzzz_xxxxx_1[i] * pc_y[i];

        ta1_z_yyzzz_xxxxy_0[i] = 2.0 * ta1_z_yyz_xxxxy_0[i] * fe_0 - 2.0 * ta1_z_yyz_xxxxy_1[i] * fe_0 + ta_yyzz_xxxxy_1[i] + ta1_z_yyzz_xxxxy_0[i] * pa_z[i] - ta1_z_yyzz_xxxxy_1[i] * pc_z[i];

        ta1_z_yyzzz_xxxxz_0[i] = ta1_z_zzz_xxxxz_0[i] * fe_0 - ta1_z_zzz_xxxxz_1[i] * fe_0 + ta1_z_yzzz_xxxxz_0[i] * pa_y[i] - ta1_z_yzzz_xxxxz_1[i] * pc_y[i];

        ta1_z_yyzzz_xxxyy_0[i] = 2.0 * ta1_z_yyz_xxxyy_0[i] * fe_0 - 2.0 * ta1_z_yyz_xxxyy_1[i] * fe_0 + ta_yyzz_xxxyy_1[i] + ta1_z_yyzz_xxxyy_0[i] * pa_z[i] - ta1_z_yyzz_xxxyy_1[i] * pc_z[i];

        ta1_z_yyzzz_xxxyz_0[i] = ta1_z_zzz_xxxyz_0[i] * fe_0 - ta1_z_zzz_xxxyz_1[i] * fe_0 + ta1_z_yzzz_xxxz_0[i] * fe_0 - ta1_z_yzzz_xxxz_1[i] * fe_0 + ta1_z_yzzz_xxxyz_0[i] * pa_y[i] - ta1_z_yzzz_xxxyz_1[i] * pc_y[i];

        ta1_z_yyzzz_xxxzz_0[i] = ta1_z_zzz_xxxzz_0[i] * fe_0 - ta1_z_zzz_xxxzz_1[i] * fe_0 + ta1_z_yzzz_xxxzz_0[i] * pa_y[i] - ta1_z_yzzz_xxxzz_1[i] * pc_y[i];

        ta1_z_yyzzz_xxyyy_0[i] = 2.0 * ta1_z_yyz_xxyyy_0[i] * fe_0 - 2.0 * ta1_z_yyz_xxyyy_1[i] * fe_0 + ta_yyzz_xxyyy_1[i] + ta1_z_yyzz_xxyyy_0[i] * pa_z[i] - ta1_z_yyzz_xxyyy_1[i] * pc_z[i];

        ta1_z_yyzzz_xxyyz_0[i] = ta1_z_zzz_xxyyz_0[i] * fe_0 - ta1_z_zzz_xxyyz_1[i] * fe_0 + 2.0 * ta1_z_yzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_yzzz_xxyz_1[i] * fe_0 + ta1_z_yzzz_xxyyz_0[i] * pa_y[i] - ta1_z_yzzz_xxyyz_1[i] * pc_y[i];

        ta1_z_yyzzz_xxyzz_0[i] = ta1_z_zzz_xxyzz_0[i] * fe_0 - ta1_z_zzz_xxyzz_1[i] * fe_0 + ta1_z_yzzz_xxzz_0[i] * fe_0 - ta1_z_yzzz_xxzz_1[i] * fe_0 + ta1_z_yzzz_xxyzz_0[i] * pa_y[i] - ta1_z_yzzz_xxyzz_1[i] * pc_y[i];

        ta1_z_yyzzz_xxzzz_0[i] = ta1_z_zzz_xxzzz_0[i] * fe_0 - ta1_z_zzz_xxzzz_1[i] * fe_0 + ta1_z_yzzz_xxzzz_0[i] * pa_y[i] - ta1_z_yzzz_xxzzz_1[i] * pc_y[i];

        ta1_z_yyzzz_xyyyy_0[i] = 2.0 * ta1_z_yyz_xyyyy_0[i] * fe_0 - 2.0 * ta1_z_yyz_xyyyy_1[i] * fe_0 + ta_yyzz_xyyyy_1[i] + ta1_z_yyzz_xyyyy_0[i] * pa_z[i] - ta1_z_yyzz_xyyyy_1[i] * pc_z[i];

        ta1_z_yyzzz_xyyyz_0[i] = ta1_z_zzz_xyyyz_0[i] * fe_0 - ta1_z_zzz_xyyyz_1[i] * fe_0 + 3.0 * ta1_z_yzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_z_yzzz_xyyz_1[i] * fe_0 + ta1_z_yzzz_xyyyz_0[i] * pa_y[i] - ta1_z_yzzz_xyyyz_1[i] * pc_y[i];

        ta1_z_yyzzz_xyyzz_0[i] = ta1_z_zzz_xyyzz_0[i] * fe_0 - ta1_z_zzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_z_yzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_yzzz_xyzz_1[i] * fe_0 + ta1_z_yzzz_xyyzz_0[i] * pa_y[i] - ta1_z_yzzz_xyyzz_1[i] * pc_y[i];

        ta1_z_yyzzz_xyzzz_0[i] = ta1_z_zzz_xyzzz_0[i] * fe_0 - ta1_z_zzz_xyzzz_1[i] * fe_0 + ta1_z_yzzz_xzzz_0[i] * fe_0 - ta1_z_yzzz_xzzz_1[i] * fe_0 + ta1_z_yzzz_xyzzz_0[i] * pa_y[i] - ta1_z_yzzz_xyzzz_1[i] * pc_y[i];

        ta1_z_yyzzz_xzzzz_0[i] = ta1_z_zzz_xzzzz_0[i] * fe_0 - ta1_z_zzz_xzzzz_1[i] * fe_0 + ta1_z_yzzz_xzzzz_0[i] * pa_y[i] - ta1_z_yzzz_xzzzz_1[i] * pc_y[i];

        ta1_z_yyzzz_yyyyy_0[i] = 2.0 * ta1_z_yyz_yyyyy_0[i] * fe_0 - 2.0 * ta1_z_yyz_yyyyy_1[i] * fe_0 + ta_yyzz_yyyyy_1[i] + ta1_z_yyzz_yyyyy_0[i] * pa_z[i] - ta1_z_yyzz_yyyyy_1[i] * pc_z[i];

        ta1_z_yyzzz_yyyyz_0[i] = ta1_z_zzz_yyyyz_0[i] * fe_0 - ta1_z_zzz_yyyyz_1[i] * fe_0 + 4.0 * ta1_z_yzzz_yyyz_0[i] * fe_0 - 4.0 * ta1_z_yzzz_yyyz_1[i] * fe_0 + ta1_z_yzzz_yyyyz_0[i] * pa_y[i] - ta1_z_yzzz_yyyyz_1[i] * pc_y[i];

        ta1_z_yyzzz_yyyzz_0[i] = ta1_z_zzz_yyyzz_0[i] * fe_0 - ta1_z_zzz_yyyzz_1[i] * fe_0 + 3.0 * ta1_z_yzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_z_yzzz_yyzz_1[i] * fe_0 + ta1_z_yzzz_yyyzz_0[i] * pa_y[i] - ta1_z_yzzz_yyyzz_1[i] * pc_y[i];

        ta1_z_yyzzz_yyzzz_0[i] = ta1_z_zzz_yyzzz_0[i] * fe_0 - ta1_z_zzz_yyzzz_1[i] * fe_0 + 2.0 * ta1_z_yzzz_yzzz_0[i] * fe_0 - 2.0 * ta1_z_yzzz_yzzz_1[i] * fe_0 + ta1_z_yzzz_yyzzz_0[i] * pa_y[i] - ta1_z_yzzz_yyzzz_1[i] * pc_y[i];

        ta1_z_yyzzz_yzzzz_0[i] = ta1_z_zzz_yzzzz_0[i] * fe_0 - ta1_z_zzz_yzzzz_1[i] * fe_0 + ta1_z_yzzz_zzzz_0[i] * fe_0 - ta1_z_yzzz_zzzz_1[i] * fe_0 + ta1_z_yzzz_yzzzz_0[i] * pa_y[i] - ta1_z_yzzz_yzzzz_1[i] * pc_y[i];

        ta1_z_yyzzz_zzzzz_0[i] = ta1_z_zzz_zzzzz_0[i] * fe_0 - ta1_z_zzz_zzzzz_1[i] * fe_0 + ta1_z_yzzz_zzzzz_0[i] * pa_y[i] - ta1_z_yzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1281-1302 components of targeted buffer : HH

    auto ta1_z_yzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1281);

    auto ta1_z_yzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1282);

    auto ta1_z_yzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1283);

    auto ta1_z_yzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1284);

    auto ta1_z_yzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1285);

    auto ta1_z_yzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1286);

    auto ta1_z_yzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1287);

    auto ta1_z_yzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1288);

    auto ta1_z_yzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1289);

    auto ta1_z_yzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1290);

    auto ta1_z_yzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1291);

    auto ta1_z_yzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1292);

    auto ta1_z_yzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1293);

    auto ta1_z_yzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1294);

    auto ta1_z_yzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1295);

    auto ta1_z_yzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1296);

    auto ta1_z_yzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1297);

    auto ta1_z_yzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1298);

    auto ta1_z_yzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1299);

    auto ta1_z_yzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1300);

    auto ta1_z_yzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1301);

    #pragma omp simd aligned(pa_y, pc_y, ta1_z_yzzzz_xxxxx_0, ta1_z_yzzzz_xxxxy_0, ta1_z_yzzzz_xxxxz_0, ta1_z_yzzzz_xxxyy_0, ta1_z_yzzzz_xxxyz_0, ta1_z_yzzzz_xxxzz_0, ta1_z_yzzzz_xxyyy_0, ta1_z_yzzzz_xxyyz_0, ta1_z_yzzzz_xxyzz_0, ta1_z_yzzzz_xxzzz_0, ta1_z_yzzzz_xyyyy_0, ta1_z_yzzzz_xyyyz_0, ta1_z_yzzzz_xyyzz_0, ta1_z_yzzzz_xyzzz_0, ta1_z_yzzzz_xzzzz_0, ta1_z_yzzzz_yyyyy_0, ta1_z_yzzzz_yyyyz_0, ta1_z_yzzzz_yyyzz_0, ta1_z_yzzzz_yyzzz_0, ta1_z_yzzzz_yzzzz_0, ta1_z_yzzzz_zzzzz_0, ta1_z_zzzz_xxxx_0, ta1_z_zzzz_xxxx_1, ta1_z_zzzz_xxxxx_0, ta1_z_zzzz_xxxxx_1, ta1_z_zzzz_xxxxy_0, ta1_z_zzzz_xxxxy_1, ta1_z_zzzz_xxxxz_0, ta1_z_zzzz_xxxxz_1, ta1_z_zzzz_xxxy_0, ta1_z_zzzz_xxxy_1, ta1_z_zzzz_xxxyy_0, ta1_z_zzzz_xxxyy_1, ta1_z_zzzz_xxxyz_0, ta1_z_zzzz_xxxyz_1, ta1_z_zzzz_xxxz_0, ta1_z_zzzz_xxxz_1, ta1_z_zzzz_xxxzz_0, ta1_z_zzzz_xxxzz_1, ta1_z_zzzz_xxyy_0, ta1_z_zzzz_xxyy_1, ta1_z_zzzz_xxyyy_0, ta1_z_zzzz_xxyyy_1, ta1_z_zzzz_xxyyz_0, ta1_z_zzzz_xxyyz_1, ta1_z_zzzz_xxyz_0, ta1_z_zzzz_xxyz_1, ta1_z_zzzz_xxyzz_0, ta1_z_zzzz_xxyzz_1, ta1_z_zzzz_xxzz_0, ta1_z_zzzz_xxzz_1, ta1_z_zzzz_xxzzz_0, ta1_z_zzzz_xxzzz_1, ta1_z_zzzz_xyyy_0, ta1_z_zzzz_xyyy_1, ta1_z_zzzz_xyyyy_0, ta1_z_zzzz_xyyyy_1, ta1_z_zzzz_xyyyz_0, ta1_z_zzzz_xyyyz_1, ta1_z_zzzz_xyyz_0, ta1_z_zzzz_xyyz_1, ta1_z_zzzz_xyyzz_0, ta1_z_zzzz_xyyzz_1, ta1_z_zzzz_xyzz_0, ta1_z_zzzz_xyzz_1, ta1_z_zzzz_xyzzz_0, ta1_z_zzzz_xyzzz_1, ta1_z_zzzz_xzzz_0, ta1_z_zzzz_xzzz_1, ta1_z_zzzz_xzzzz_0, ta1_z_zzzz_xzzzz_1, ta1_z_zzzz_yyyy_0, ta1_z_zzzz_yyyy_1, ta1_z_zzzz_yyyyy_0, ta1_z_zzzz_yyyyy_1, ta1_z_zzzz_yyyyz_0, ta1_z_zzzz_yyyyz_1, ta1_z_zzzz_yyyz_0, ta1_z_zzzz_yyyz_1, ta1_z_zzzz_yyyzz_0, ta1_z_zzzz_yyyzz_1, ta1_z_zzzz_yyzz_0, ta1_z_zzzz_yyzz_1, ta1_z_zzzz_yyzzz_0, ta1_z_zzzz_yyzzz_1, ta1_z_zzzz_yzzz_0, ta1_z_zzzz_yzzz_1, ta1_z_zzzz_yzzzz_0, ta1_z_zzzz_yzzzz_1, ta1_z_zzzz_zzzz_0, ta1_z_zzzz_zzzz_1, ta1_z_zzzz_zzzzz_0, ta1_z_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_yzzzz_xxxxx_0[i] = ta1_z_zzzz_xxxxx_0[i] * pa_y[i] - ta1_z_zzzz_xxxxx_1[i] * pc_y[i];

        ta1_z_yzzzz_xxxxy_0[i] = ta1_z_zzzz_xxxx_0[i] * fe_0 - ta1_z_zzzz_xxxx_1[i] * fe_0 + ta1_z_zzzz_xxxxy_0[i] * pa_y[i] - ta1_z_zzzz_xxxxy_1[i] * pc_y[i];

        ta1_z_yzzzz_xxxxz_0[i] = ta1_z_zzzz_xxxxz_0[i] * pa_y[i] - ta1_z_zzzz_xxxxz_1[i] * pc_y[i];

        ta1_z_yzzzz_xxxyy_0[i] = 2.0 * ta1_z_zzzz_xxxy_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xxxy_1[i] * fe_0 + ta1_z_zzzz_xxxyy_0[i] * pa_y[i] - ta1_z_zzzz_xxxyy_1[i] * pc_y[i];

        ta1_z_yzzzz_xxxyz_0[i] = ta1_z_zzzz_xxxz_0[i] * fe_0 - ta1_z_zzzz_xxxz_1[i] * fe_0 + ta1_z_zzzz_xxxyz_0[i] * pa_y[i] - ta1_z_zzzz_xxxyz_1[i] * pc_y[i];

        ta1_z_yzzzz_xxxzz_0[i] = ta1_z_zzzz_xxxzz_0[i] * pa_y[i] - ta1_z_zzzz_xxxzz_1[i] * pc_y[i];

        ta1_z_yzzzz_xxyyy_0[i] = 3.0 * ta1_z_zzzz_xxyy_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xxyy_1[i] * fe_0 + ta1_z_zzzz_xxyyy_0[i] * pa_y[i] - ta1_z_zzzz_xxyyy_1[i] * pc_y[i];

        ta1_z_yzzzz_xxyyz_0[i] = 2.0 * ta1_z_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xxyz_1[i] * fe_0 + ta1_z_zzzz_xxyyz_0[i] * pa_y[i] - ta1_z_zzzz_xxyyz_1[i] * pc_y[i];

        ta1_z_yzzzz_xxyzz_0[i] = ta1_z_zzzz_xxzz_0[i] * fe_0 - ta1_z_zzzz_xxzz_1[i] * fe_0 + ta1_z_zzzz_xxyzz_0[i] * pa_y[i] - ta1_z_zzzz_xxyzz_1[i] * pc_y[i];

        ta1_z_yzzzz_xxzzz_0[i] = ta1_z_zzzz_xxzzz_0[i] * pa_y[i] - ta1_z_zzzz_xxzzz_1[i] * pc_y[i];

        ta1_z_yzzzz_xyyyy_0[i] = 4.0 * ta1_z_zzzz_xyyy_0[i] * fe_0 - 4.0 * ta1_z_zzzz_xyyy_1[i] * fe_0 + ta1_z_zzzz_xyyyy_0[i] * pa_y[i] - ta1_z_zzzz_xyyyy_1[i] * pc_y[i];

        ta1_z_yzzzz_xyyyz_0[i] = 3.0 * ta1_z_zzzz_xyyz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xyyz_1[i] * fe_0 + ta1_z_zzzz_xyyyz_0[i] * pa_y[i] - ta1_z_zzzz_xyyyz_1[i] * pc_y[i];

        ta1_z_yzzzz_xyyzz_0[i] = 2.0 * ta1_z_zzzz_xyzz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xyzz_1[i] * fe_0 + ta1_z_zzzz_xyyzz_0[i] * pa_y[i] - ta1_z_zzzz_xyyzz_1[i] * pc_y[i];

        ta1_z_yzzzz_xyzzz_0[i] = ta1_z_zzzz_xzzz_0[i] * fe_0 - ta1_z_zzzz_xzzz_1[i] * fe_0 + ta1_z_zzzz_xyzzz_0[i] * pa_y[i] - ta1_z_zzzz_xyzzz_1[i] * pc_y[i];

        ta1_z_yzzzz_xzzzz_0[i] = ta1_z_zzzz_xzzzz_0[i] * pa_y[i] - ta1_z_zzzz_xzzzz_1[i] * pc_y[i];

        ta1_z_yzzzz_yyyyy_0[i] = 5.0 * ta1_z_zzzz_yyyy_0[i] * fe_0 - 5.0 * ta1_z_zzzz_yyyy_1[i] * fe_0 + ta1_z_zzzz_yyyyy_0[i] * pa_y[i] - ta1_z_zzzz_yyyyy_1[i] * pc_y[i];

        ta1_z_yzzzz_yyyyz_0[i] = 4.0 * ta1_z_zzzz_yyyz_0[i] * fe_0 - 4.0 * ta1_z_zzzz_yyyz_1[i] * fe_0 + ta1_z_zzzz_yyyyz_0[i] * pa_y[i] - ta1_z_zzzz_yyyyz_1[i] * pc_y[i];

        ta1_z_yzzzz_yyyzz_0[i] = 3.0 * ta1_z_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_yyzz_1[i] * fe_0 + ta1_z_zzzz_yyyzz_0[i] * pa_y[i] - ta1_z_zzzz_yyyzz_1[i] * pc_y[i];

        ta1_z_yzzzz_yyzzz_0[i] = 2.0 * ta1_z_zzzz_yzzz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_yzzz_1[i] * fe_0 + ta1_z_zzzz_yyzzz_0[i] * pa_y[i] - ta1_z_zzzz_yyzzz_1[i] * pc_y[i];

        ta1_z_yzzzz_yzzzz_0[i] = ta1_z_zzzz_zzzz_0[i] * fe_0 - ta1_z_zzzz_zzzz_1[i] * fe_0 + ta1_z_zzzz_yzzzz_0[i] * pa_y[i] - ta1_z_zzzz_yzzzz_1[i] * pc_y[i];

        ta1_z_yzzzz_zzzzz_0[i] = ta1_z_zzzz_zzzzz_0[i] * pa_y[i] - ta1_z_zzzz_zzzzz_1[i] * pc_y[i];
    }

    // Set up 1302-1323 components of targeted buffer : HH

    auto ta1_z_zzzzz_xxxxx_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1302);

    auto ta1_z_zzzzz_xxxxy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1303);

    auto ta1_z_zzzzz_xxxxz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1304);

    auto ta1_z_zzzzz_xxxyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1305);

    auto ta1_z_zzzzz_xxxyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1306);

    auto ta1_z_zzzzz_xxxzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1307);

    auto ta1_z_zzzzz_xxyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1308);

    auto ta1_z_zzzzz_xxyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1309);

    auto ta1_z_zzzzz_xxyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1310);

    auto ta1_z_zzzzz_xxzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1311);

    auto ta1_z_zzzzz_xyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1312);

    auto ta1_z_zzzzz_xyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1313);

    auto ta1_z_zzzzz_xyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1314);

    auto ta1_z_zzzzz_xyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1315);

    auto ta1_z_zzzzz_xzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1316);

    auto ta1_z_zzzzz_yyyyy_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1317);

    auto ta1_z_zzzzz_yyyyz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1318);

    auto ta1_z_zzzzz_yyyzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1319);

    auto ta1_z_zzzzz_yyzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1320);

    auto ta1_z_zzzzz_yzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1321);

    auto ta1_z_zzzzz_zzzzz_0 = pbuffer.data(idx_npot_geom_010_0_hh + 1322);

    #pragma omp simd aligned(pa_z, pc_z, ta1_z_zzz_xxxxx_0, ta1_z_zzz_xxxxx_1, ta1_z_zzz_xxxxy_0, ta1_z_zzz_xxxxy_1, ta1_z_zzz_xxxxz_0, ta1_z_zzz_xxxxz_1, ta1_z_zzz_xxxyy_0, ta1_z_zzz_xxxyy_1, ta1_z_zzz_xxxyz_0, ta1_z_zzz_xxxyz_1, ta1_z_zzz_xxxzz_0, ta1_z_zzz_xxxzz_1, ta1_z_zzz_xxyyy_0, ta1_z_zzz_xxyyy_1, ta1_z_zzz_xxyyz_0, ta1_z_zzz_xxyyz_1, ta1_z_zzz_xxyzz_0, ta1_z_zzz_xxyzz_1, ta1_z_zzz_xxzzz_0, ta1_z_zzz_xxzzz_1, ta1_z_zzz_xyyyy_0, ta1_z_zzz_xyyyy_1, ta1_z_zzz_xyyyz_0, ta1_z_zzz_xyyyz_1, ta1_z_zzz_xyyzz_0, ta1_z_zzz_xyyzz_1, ta1_z_zzz_xyzzz_0, ta1_z_zzz_xyzzz_1, ta1_z_zzz_xzzzz_0, ta1_z_zzz_xzzzz_1, ta1_z_zzz_yyyyy_0, ta1_z_zzz_yyyyy_1, ta1_z_zzz_yyyyz_0, ta1_z_zzz_yyyyz_1, ta1_z_zzz_yyyzz_0, ta1_z_zzz_yyyzz_1, ta1_z_zzz_yyzzz_0, ta1_z_zzz_yyzzz_1, ta1_z_zzz_yzzzz_0, ta1_z_zzz_yzzzz_1, ta1_z_zzz_zzzzz_0, ta1_z_zzz_zzzzz_1, ta1_z_zzzz_xxxx_0, ta1_z_zzzz_xxxx_1, ta1_z_zzzz_xxxxx_0, ta1_z_zzzz_xxxxx_1, ta1_z_zzzz_xxxxy_0, ta1_z_zzzz_xxxxy_1, ta1_z_zzzz_xxxxz_0, ta1_z_zzzz_xxxxz_1, ta1_z_zzzz_xxxy_0, ta1_z_zzzz_xxxy_1, ta1_z_zzzz_xxxyy_0, ta1_z_zzzz_xxxyy_1, ta1_z_zzzz_xxxyz_0, ta1_z_zzzz_xxxyz_1, ta1_z_zzzz_xxxz_0, ta1_z_zzzz_xxxz_1, ta1_z_zzzz_xxxzz_0, ta1_z_zzzz_xxxzz_1, ta1_z_zzzz_xxyy_0, ta1_z_zzzz_xxyy_1, ta1_z_zzzz_xxyyy_0, ta1_z_zzzz_xxyyy_1, ta1_z_zzzz_xxyyz_0, ta1_z_zzzz_xxyyz_1, ta1_z_zzzz_xxyz_0, ta1_z_zzzz_xxyz_1, ta1_z_zzzz_xxyzz_0, ta1_z_zzzz_xxyzz_1, ta1_z_zzzz_xxzz_0, ta1_z_zzzz_xxzz_1, ta1_z_zzzz_xxzzz_0, ta1_z_zzzz_xxzzz_1, ta1_z_zzzz_xyyy_0, ta1_z_zzzz_xyyy_1, ta1_z_zzzz_xyyyy_0, ta1_z_zzzz_xyyyy_1, ta1_z_zzzz_xyyyz_0, ta1_z_zzzz_xyyyz_1, ta1_z_zzzz_xyyz_0, ta1_z_zzzz_xyyz_1, ta1_z_zzzz_xyyzz_0, ta1_z_zzzz_xyyzz_1, ta1_z_zzzz_xyzz_0, ta1_z_zzzz_xyzz_1, ta1_z_zzzz_xyzzz_0, ta1_z_zzzz_xyzzz_1, ta1_z_zzzz_xzzz_0, ta1_z_zzzz_xzzz_1, ta1_z_zzzz_xzzzz_0, ta1_z_zzzz_xzzzz_1, ta1_z_zzzz_yyyy_0, ta1_z_zzzz_yyyy_1, ta1_z_zzzz_yyyyy_0, ta1_z_zzzz_yyyyy_1, ta1_z_zzzz_yyyyz_0, ta1_z_zzzz_yyyyz_1, ta1_z_zzzz_yyyz_0, ta1_z_zzzz_yyyz_1, ta1_z_zzzz_yyyzz_0, ta1_z_zzzz_yyyzz_1, ta1_z_zzzz_yyzz_0, ta1_z_zzzz_yyzz_1, ta1_z_zzzz_yyzzz_0, ta1_z_zzzz_yyzzz_1, ta1_z_zzzz_yzzz_0, ta1_z_zzzz_yzzz_1, ta1_z_zzzz_yzzzz_0, ta1_z_zzzz_yzzzz_1, ta1_z_zzzz_zzzz_0, ta1_z_zzzz_zzzz_1, ta1_z_zzzz_zzzzz_0, ta1_z_zzzz_zzzzz_1, ta1_z_zzzzz_xxxxx_0, ta1_z_zzzzz_xxxxy_0, ta1_z_zzzzz_xxxxz_0, ta1_z_zzzzz_xxxyy_0, ta1_z_zzzzz_xxxyz_0, ta1_z_zzzzz_xxxzz_0, ta1_z_zzzzz_xxyyy_0, ta1_z_zzzzz_xxyyz_0, ta1_z_zzzzz_xxyzz_0, ta1_z_zzzzz_xxzzz_0, ta1_z_zzzzz_xyyyy_0, ta1_z_zzzzz_xyyyz_0, ta1_z_zzzzz_xyyzz_0, ta1_z_zzzzz_xyzzz_0, ta1_z_zzzzz_xzzzz_0, ta1_z_zzzzz_yyyyy_0, ta1_z_zzzzz_yyyyz_0, ta1_z_zzzzz_yyyzz_0, ta1_z_zzzzz_yyzzz_0, ta1_z_zzzzz_yzzzz_0, ta1_z_zzzzz_zzzzz_0, ta_zzzz_xxxxx_1, ta_zzzz_xxxxy_1, ta_zzzz_xxxxz_1, ta_zzzz_xxxyy_1, ta_zzzz_xxxyz_1, ta_zzzz_xxxzz_1, ta_zzzz_xxyyy_1, ta_zzzz_xxyyz_1, ta_zzzz_xxyzz_1, ta_zzzz_xxzzz_1, ta_zzzz_xyyyy_1, ta_zzzz_xyyyz_1, ta_zzzz_xyyzz_1, ta_zzzz_xyzzz_1, ta_zzzz_xzzzz_1, ta_zzzz_yyyyy_1, ta_zzzz_yyyyz_1, ta_zzzz_yyyzz_1, ta_zzzz_yyzzz_1, ta_zzzz_yzzzz_1, ta_zzzz_zzzzz_1, b_exps : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fe_0 = 0.5 / (a_exp + b_exps[i]);

        ta1_z_zzzzz_xxxxx_0[i] = 4.0 * ta1_z_zzz_xxxxx_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxxx_1[i] * fe_0 + ta_zzzz_xxxxx_1[i] + ta1_z_zzzz_xxxxx_0[i] * pa_z[i] - ta1_z_zzzz_xxxxx_1[i] * pc_z[i];

        ta1_z_zzzzz_xxxxy_0[i] = 4.0 * ta1_z_zzz_xxxxy_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxxy_1[i] * fe_0 + ta_zzzz_xxxxy_1[i] + ta1_z_zzzz_xxxxy_0[i] * pa_z[i] - ta1_z_zzzz_xxxxy_1[i] * pc_z[i];

        ta1_z_zzzzz_xxxxz_0[i] = 4.0 * ta1_z_zzz_xxxxz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxxz_1[i] * fe_0 + ta1_z_zzzz_xxxx_0[i] * fe_0 - ta1_z_zzzz_xxxx_1[i] * fe_0 + ta_zzzz_xxxxz_1[i] + ta1_z_zzzz_xxxxz_0[i] * pa_z[i] - ta1_z_zzzz_xxxxz_1[i] * pc_z[i];

        ta1_z_zzzzz_xxxyy_0[i] = 4.0 * ta1_z_zzz_xxxyy_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxyy_1[i] * fe_0 + ta_zzzz_xxxyy_1[i] + ta1_z_zzzz_xxxyy_0[i] * pa_z[i] - ta1_z_zzzz_xxxyy_1[i] * pc_z[i];

        ta1_z_zzzzz_xxxyz_0[i] = 4.0 * ta1_z_zzz_xxxyz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxyz_1[i] * fe_0 + ta1_z_zzzz_xxxy_0[i] * fe_0 - ta1_z_zzzz_xxxy_1[i] * fe_0 + ta_zzzz_xxxyz_1[i] + ta1_z_zzzz_xxxyz_0[i] * pa_z[i] - ta1_z_zzzz_xxxyz_1[i] * pc_z[i];

        ta1_z_zzzzz_xxxzz_0[i] = 4.0 * ta1_z_zzz_xxxzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxxzz_1[i] * fe_0 + 2.0 * ta1_z_zzzz_xxxz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xxxz_1[i] * fe_0 + ta_zzzz_xxxzz_1[i] + ta1_z_zzzz_xxxzz_0[i] * pa_z[i] - ta1_z_zzzz_xxxzz_1[i] * pc_z[i];

        ta1_z_zzzzz_xxyyy_0[i] = 4.0 * ta1_z_zzz_xxyyy_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxyyy_1[i] * fe_0 + ta_zzzz_xxyyy_1[i] + ta1_z_zzzz_xxyyy_0[i] * pa_z[i] - ta1_z_zzzz_xxyyy_1[i] * pc_z[i];

        ta1_z_zzzzz_xxyyz_0[i] = 4.0 * ta1_z_zzz_xxyyz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxyyz_1[i] * fe_0 + ta1_z_zzzz_xxyy_0[i] * fe_0 - ta1_z_zzzz_xxyy_1[i] * fe_0 + ta_zzzz_xxyyz_1[i] + ta1_z_zzzz_xxyyz_0[i] * pa_z[i] - ta1_z_zzzz_xxyyz_1[i] * pc_z[i];

        ta1_z_zzzzz_xxyzz_0[i] = 4.0 * ta1_z_zzz_xxyzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxyzz_1[i] * fe_0 + 2.0 * ta1_z_zzzz_xxyz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xxyz_1[i] * fe_0 + ta_zzzz_xxyzz_1[i] + ta1_z_zzzz_xxyzz_0[i] * pa_z[i] - ta1_z_zzzz_xxyzz_1[i] * pc_z[i];

        ta1_z_zzzzz_xxzzz_0[i] = 4.0 * ta1_z_zzz_xxzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xxzzz_1[i] * fe_0 + 3.0 * ta1_z_zzzz_xxzz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xxzz_1[i] * fe_0 + ta_zzzz_xxzzz_1[i] + ta1_z_zzzz_xxzzz_0[i] * pa_z[i] - ta1_z_zzzz_xxzzz_1[i] * pc_z[i];

        ta1_z_zzzzz_xyyyy_0[i] = 4.0 * ta1_z_zzz_xyyyy_0[i] * fe_0 - 4.0 * ta1_z_zzz_xyyyy_1[i] * fe_0 + ta_zzzz_xyyyy_1[i] + ta1_z_zzzz_xyyyy_0[i] * pa_z[i] - ta1_z_zzzz_xyyyy_1[i] * pc_z[i];

        ta1_z_zzzzz_xyyyz_0[i] = 4.0 * ta1_z_zzz_xyyyz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xyyyz_1[i] * fe_0 + ta1_z_zzzz_xyyy_0[i] * fe_0 - ta1_z_zzzz_xyyy_1[i] * fe_0 + ta_zzzz_xyyyz_1[i] + ta1_z_zzzz_xyyyz_0[i] * pa_z[i] - ta1_z_zzzz_xyyyz_1[i] * pc_z[i];

        ta1_z_zzzzz_xyyzz_0[i] = 4.0 * ta1_z_zzz_xyyzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xyyzz_1[i] * fe_0 + 2.0 * ta1_z_zzzz_xyyz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_xyyz_1[i] * fe_0 + ta_zzzz_xyyzz_1[i] + ta1_z_zzzz_xyyzz_0[i] * pa_z[i] - ta1_z_zzzz_xyyzz_1[i] * pc_z[i];

        ta1_z_zzzzz_xyzzz_0[i] = 4.0 * ta1_z_zzz_xyzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xyzzz_1[i] * fe_0 + 3.0 * ta1_z_zzzz_xyzz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_xyzz_1[i] * fe_0 + ta_zzzz_xyzzz_1[i] + ta1_z_zzzz_xyzzz_0[i] * pa_z[i] - ta1_z_zzzz_xyzzz_1[i] * pc_z[i];

        ta1_z_zzzzz_xzzzz_0[i] = 4.0 * ta1_z_zzz_xzzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_xzzzz_1[i] * fe_0 + 4.0 * ta1_z_zzzz_xzzz_0[i] * fe_0 - 4.0 * ta1_z_zzzz_xzzz_1[i] * fe_0 + ta_zzzz_xzzzz_1[i] + ta1_z_zzzz_xzzzz_0[i] * pa_z[i] - ta1_z_zzzz_xzzzz_1[i] * pc_z[i];

        ta1_z_zzzzz_yyyyy_0[i] = 4.0 * ta1_z_zzz_yyyyy_0[i] * fe_0 - 4.0 * ta1_z_zzz_yyyyy_1[i] * fe_0 + ta_zzzz_yyyyy_1[i] + ta1_z_zzzz_yyyyy_0[i] * pa_z[i] - ta1_z_zzzz_yyyyy_1[i] * pc_z[i];

        ta1_z_zzzzz_yyyyz_0[i] = 4.0 * ta1_z_zzz_yyyyz_0[i] * fe_0 - 4.0 * ta1_z_zzz_yyyyz_1[i] * fe_0 + ta1_z_zzzz_yyyy_0[i] * fe_0 - ta1_z_zzzz_yyyy_1[i] * fe_0 + ta_zzzz_yyyyz_1[i] + ta1_z_zzzz_yyyyz_0[i] * pa_z[i] - ta1_z_zzzz_yyyyz_1[i] * pc_z[i];

        ta1_z_zzzzz_yyyzz_0[i] = 4.0 * ta1_z_zzz_yyyzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_yyyzz_1[i] * fe_0 + 2.0 * ta1_z_zzzz_yyyz_0[i] * fe_0 - 2.0 * ta1_z_zzzz_yyyz_1[i] * fe_0 + ta_zzzz_yyyzz_1[i] + ta1_z_zzzz_yyyzz_0[i] * pa_z[i] - ta1_z_zzzz_yyyzz_1[i] * pc_z[i];

        ta1_z_zzzzz_yyzzz_0[i] = 4.0 * ta1_z_zzz_yyzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_yyzzz_1[i] * fe_0 + 3.0 * ta1_z_zzzz_yyzz_0[i] * fe_0 - 3.0 * ta1_z_zzzz_yyzz_1[i] * fe_0 + ta_zzzz_yyzzz_1[i] + ta1_z_zzzz_yyzzz_0[i] * pa_z[i] - ta1_z_zzzz_yyzzz_1[i] * pc_z[i];

        ta1_z_zzzzz_yzzzz_0[i] = 4.0 * ta1_z_zzz_yzzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_yzzzz_1[i] * fe_0 + 4.0 * ta1_z_zzzz_yzzz_0[i] * fe_0 - 4.0 * ta1_z_zzzz_yzzz_1[i] * fe_0 + ta_zzzz_yzzzz_1[i] + ta1_z_zzzz_yzzzz_0[i] * pa_z[i] - ta1_z_zzzz_yzzzz_1[i] * pc_z[i];

        ta1_z_zzzzz_zzzzz_0[i] = 4.0 * ta1_z_zzz_zzzzz_0[i] * fe_0 - 4.0 * ta1_z_zzz_zzzzz_1[i] * fe_0 + 5.0 * ta1_z_zzzz_zzzz_0[i] * fe_0 - 5.0 * ta1_z_zzzz_zzzz_1[i] * fe_0 + ta_zzzz_zzzzz_1[i] + ta1_z_zzzz_zzzzz_0[i] * pa_z[i] - ta1_z_zzzz_zzzzz_1[i] * pc_z[i];
    }

}

} // npotrec namespace

