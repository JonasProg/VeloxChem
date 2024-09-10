#include "ElectronRepulsionPrimRecSKSL.hpp"

namespace erirec { // erirec namespace

auto
comp_prim_electron_repulsion_sksl(CSimdArray<double>& pbuffer,
                                  const size_t idx_eri_0_sksl,
                                  size_t idx_eri_0_shsl,
                                  size_t idx_eri_1_shsl,
                                  size_t idx_eri_1_sisk,
                                  size_t idx_eri_0_sisl,
                                  size_t idx_eri_1_sisl,
                                  CSimdArray<double>& factors,
                                  const size_t idx_wp,
                                  const TPoint<double>& r_pb,
                                  const double a_exp,
                                  const double b_exp) -> void
{
    const auto nelems = pbuffer.number_of_active_elements();

    // Set up exponents

    auto c_exps = factors.data(0);

    auto d_exps = factors.data(1);

    // Set up R(WP) distances

    auto wp_x = factors.data(idx_wp);

    auto wp_y = factors.data(idx_wp + 1);

    auto wp_z = factors.data(idx_wp + 2);

    // set up R(PB) distances

    const auto xyz = r_pb.coordinates();

    const auto pb_x = xyz[0];

    const auto pb_y = xyz[1];

    const auto pb_z = xyz[2];

    /// Set up components of auxilary buffer : SHSL

    auto g_0_xxxxx_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl);

    auto g_0_xxxxx_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 1);

    auto g_0_xxxxx_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 2);

    auto g_0_xxxxx_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 3);

    auto g_0_xxxxx_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 4);

    auto g_0_xxxxx_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 5);

    auto g_0_xxxxx_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 6);

    auto g_0_xxxxx_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 7);

    auto g_0_xxxxx_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 8);

    auto g_0_xxxxx_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 9);

    auto g_0_xxxxx_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 10);

    auto g_0_xxxxx_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 11);

    auto g_0_xxxxx_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 12);

    auto g_0_xxxxx_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 13);

    auto g_0_xxxxx_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 14);

    auto g_0_xxxxx_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 15);

    auto g_0_xxxxx_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 16);

    auto g_0_xxxxx_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 17);

    auto g_0_xxxxx_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 18);

    auto g_0_xxxxx_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 19);

    auto g_0_xxxxx_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 20);

    auto g_0_xxxxx_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 21);

    auto g_0_xxxxx_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 22);

    auto g_0_xxxxx_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 23);

    auto g_0_xxxxx_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 24);

    auto g_0_xxxxx_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 25);

    auto g_0_xxxxx_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 26);

    auto g_0_xxxxx_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 27);

    auto g_0_xxxxx_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 28);

    auto g_0_xxxxx_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 29);

    auto g_0_xxxxx_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 30);

    auto g_0_xxxxx_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 31);

    auto g_0_xxxxx_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 32);

    auto g_0_xxxxx_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 33);

    auto g_0_xxxxx_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 34);

    auto g_0_xxxxx_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 35);

    auto g_0_xxxxx_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 36);

    auto g_0_xxxxx_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 37);

    auto g_0_xxxxx_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 38);

    auto g_0_xxxxx_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 39);

    auto g_0_xxxxx_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 40);

    auto g_0_xxxxx_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 41);

    auto g_0_xxxxx_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 42);

    auto g_0_xxxxx_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 43);

    auto g_0_xxxxx_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 44);

    auto g_0_xxxxy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 45);

    auto g_0_xxxxy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 47);

    auto g_0_xxxxy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 50);

    auto g_0_xxxxy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 54);

    auto g_0_xxxxy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 59);

    auto g_0_xxxxy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 65);

    auto g_0_xxxxy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 72);

    auto g_0_xxxxy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 80);

    auto g_0_xxxxz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 90);

    auto g_0_xxxxz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 91);

    auto g_0_xxxxz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 93);

    auto g_0_xxxxz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 96);

    auto g_0_xxxxz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 100);

    auto g_0_xxxxz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 105);

    auto g_0_xxxxz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 111);

    auto g_0_xxxxz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 118);

    auto g_0_xxxyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 135);

    auto g_0_xxxyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 136);

    auto g_0_xxxyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 137);

    auto g_0_xxxyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 138);

    auto g_0_xxxyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 139);

    auto g_0_xxxyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 140);

    auto g_0_xxxyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 141);

    auto g_0_xxxyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 142);

    auto g_0_xxxyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 143);

    auto g_0_xxxyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 144);

    auto g_0_xxxyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 145);

    auto g_0_xxxyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 146);

    auto g_0_xxxyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 147);

    auto g_0_xxxyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 148);

    auto g_0_xxxyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 149);

    auto g_0_xxxyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 150);

    auto g_0_xxxyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 151);

    auto g_0_xxxyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 152);

    auto g_0_xxxyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 153);

    auto g_0_xxxyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 154);

    auto g_0_xxxyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 155);

    auto g_0_xxxyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 156);

    auto g_0_xxxyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 157);

    auto g_0_xxxyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 158);

    auto g_0_xxxyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 159);

    auto g_0_xxxyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 160);

    auto g_0_xxxyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 161);

    auto g_0_xxxyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 162);

    auto g_0_xxxyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 163);

    auto g_0_xxxyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 164);

    auto g_0_xxxyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 165);

    auto g_0_xxxyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 166);

    auto g_0_xxxyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 167);

    auto g_0_xxxyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 168);

    auto g_0_xxxyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 169);

    auto g_0_xxxyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 170);

    auto g_0_xxxyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 171);

    auto g_0_xxxyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 172);

    auto g_0_xxxyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 173);

    auto g_0_xxxyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 174);

    auto g_0_xxxyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 175);

    auto g_0_xxxyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 176);

    auto g_0_xxxyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 177);

    auto g_0_xxxyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 178);

    auto g_0_xxxyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 179);

    auto g_0_xxxzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 225);

    auto g_0_xxxzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 226);

    auto g_0_xxxzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 227);

    auto g_0_xxxzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 228);

    auto g_0_xxxzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 229);

    auto g_0_xxxzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 230);

    auto g_0_xxxzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 231);

    auto g_0_xxxzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 232);

    auto g_0_xxxzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 233);

    auto g_0_xxxzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 234);

    auto g_0_xxxzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 235);

    auto g_0_xxxzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 236);

    auto g_0_xxxzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 237);

    auto g_0_xxxzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 238);

    auto g_0_xxxzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 239);

    auto g_0_xxxzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 240);

    auto g_0_xxxzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 241);

    auto g_0_xxxzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 242);

    auto g_0_xxxzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 243);

    auto g_0_xxxzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 244);

    auto g_0_xxxzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 245);

    auto g_0_xxxzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 246);

    auto g_0_xxxzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 247);

    auto g_0_xxxzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 248);

    auto g_0_xxxzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 249);

    auto g_0_xxxzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 250);

    auto g_0_xxxzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 251);

    auto g_0_xxxzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 252);

    auto g_0_xxxzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 253);

    auto g_0_xxxzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 254);

    auto g_0_xxxzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 255);

    auto g_0_xxxzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 256);

    auto g_0_xxxzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 257);

    auto g_0_xxxzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 258);

    auto g_0_xxxzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 259);

    auto g_0_xxxzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 260);

    auto g_0_xxxzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 261);

    auto g_0_xxxzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 262);

    auto g_0_xxxzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 263);

    auto g_0_xxxzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 264);

    auto g_0_xxxzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 265);

    auto g_0_xxxzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 266);

    auto g_0_xxxzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 267);

    auto g_0_xxxzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 268);

    auto g_0_xxxzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 269);

    auto g_0_xxyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 270);

    auto g_0_xxyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 271);

    auto g_0_xxyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 272);

    auto g_0_xxyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 273);

    auto g_0_xxyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 274);

    auto g_0_xxyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 275);

    auto g_0_xxyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 276);

    auto g_0_xxyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 277);

    auto g_0_xxyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 278);

    auto g_0_xxyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 279);

    auto g_0_xxyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 280);

    auto g_0_xxyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 281);

    auto g_0_xxyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 282);

    auto g_0_xxyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 283);

    auto g_0_xxyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 284);

    auto g_0_xxyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 285);

    auto g_0_xxyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 286);

    auto g_0_xxyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 287);

    auto g_0_xxyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 288);

    auto g_0_xxyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 289);

    auto g_0_xxyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 290);

    auto g_0_xxyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 291);

    auto g_0_xxyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 292);

    auto g_0_xxyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 293);

    auto g_0_xxyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 294);

    auto g_0_xxyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 295);

    auto g_0_xxyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 296);

    auto g_0_xxyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 297);

    auto g_0_xxyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 298);

    auto g_0_xxyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 299);

    auto g_0_xxyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 300);

    auto g_0_xxyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 301);

    auto g_0_xxyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 302);

    auto g_0_xxyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 303);

    auto g_0_xxyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 304);

    auto g_0_xxyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 305);

    auto g_0_xxyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 306);

    auto g_0_xxyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 307);

    auto g_0_xxyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 308);

    auto g_0_xxyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 309);

    auto g_0_xxyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 310);

    auto g_0_xxyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 311);

    auto g_0_xxyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 312);

    auto g_0_xxyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 313);

    auto g_0_xxyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 314);

    auto g_0_xxyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 316);

    auto g_0_xxyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 318);

    auto g_0_xxyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 321);

    auto g_0_xxyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 325);

    auto g_0_xxyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 330);

    auto g_0_xxyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 336);

    auto g_0_xxyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 343);

    auto g_0_xxyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 360);

    auto g_0_xxyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 362);

    auto g_0_xxyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 365);

    auto g_0_xxyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 369);

    auto g_0_xxyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 374);

    auto g_0_xxyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 380);

    auto g_0_xxyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 387);

    auto g_0_xxyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 395);

    auto g_0_xxzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 405);

    auto g_0_xxzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 406);

    auto g_0_xxzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 407);

    auto g_0_xxzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 408);

    auto g_0_xxzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 409);

    auto g_0_xxzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 410);

    auto g_0_xxzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 411);

    auto g_0_xxzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 412);

    auto g_0_xxzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 413);

    auto g_0_xxzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 414);

    auto g_0_xxzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 415);

    auto g_0_xxzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 416);

    auto g_0_xxzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 417);

    auto g_0_xxzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 418);

    auto g_0_xxzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 419);

    auto g_0_xxzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 420);

    auto g_0_xxzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 421);

    auto g_0_xxzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 422);

    auto g_0_xxzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 423);

    auto g_0_xxzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 424);

    auto g_0_xxzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 425);

    auto g_0_xxzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 426);

    auto g_0_xxzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 427);

    auto g_0_xxzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 428);

    auto g_0_xxzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 429);

    auto g_0_xxzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 430);

    auto g_0_xxzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 431);

    auto g_0_xxzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 432);

    auto g_0_xxzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 433);

    auto g_0_xxzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 434);

    auto g_0_xxzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 435);

    auto g_0_xxzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 436);

    auto g_0_xxzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 437);

    auto g_0_xxzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 438);

    auto g_0_xxzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 439);

    auto g_0_xxzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 440);

    auto g_0_xxzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 441);

    auto g_0_xxzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 442);

    auto g_0_xxzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 443);

    auto g_0_xxzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 444);

    auto g_0_xxzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 445);

    auto g_0_xxzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 446);

    auto g_0_xxzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 447);

    auto g_0_xxzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 448);

    auto g_0_xxzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 449);

    auto g_0_xyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 451);

    auto g_0_xyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 453);

    auto g_0_xyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 454);

    auto g_0_xyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 456);

    auto g_0_xyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 457);

    auto g_0_xyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 458);

    auto g_0_xyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 460);

    auto g_0_xyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 461);

    auto g_0_xyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 462);

    auto g_0_xyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 463);

    auto g_0_xyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 465);

    auto g_0_xyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 466);

    auto g_0_xyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 467);

    auto g_0_xyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 468);

    auto g_0_xyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 469);

    auto g_0_xyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 471);

    auto g_0_xyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 472);

    auto g_0_xyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 473);

    auto g_0_xyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 474);

    auto g_0_xyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 475);

    auto g_0_xyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 476);

    auto g_0_xyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 478);

    auto g_0_xyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 479);

    auto g_0_xyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 480);

    auto g_0_xyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 481);

    auto g_0_xyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 482);

    auto g_0_xyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 483);

    auto g_0_xyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 484);

    auto g_0_xyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 486);

    auto g_0_xyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 487);

    auto g_0_xyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 488);

    auto g_0_xyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 489);

    auto g_0_xyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 490);

    auto g_0_xyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 491);

    auto g_0_xyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 492);

    auto g_0_xyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 493);

    auto g_0_xyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 494);

    auto g_0_xyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 544);

    auto g_0_xyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 547);

    auto g_0_xyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 548);

    auto g_0_xyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 551);

    auto g_0_xyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 552);

    auto g_0_xyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 553);

    auto g_0_xyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 556);

    auto g_0_xyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 557);

    auto g_0_xyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 558);

    auto g_0_xyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 559);

    auto g_0_xyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 562);

    auto g_0_xyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 563);

    auto g_0_xyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 564);

    auto g_0_xyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 565);

    auto g_0_xyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 566);

    auto g_0_xyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 569);

    auto g_0_xyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 570);

    auto g_0_xyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 571);

    auto g_0_xyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 572);

    auto g_0_xyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 573);

    auto g_0_xyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 574);

    auto g_0_xyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 576);

    auto g_0_xyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 577);

    auto g_0_xyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 578);

    auto g_0_xyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 579);

    auto g_0_xyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 580);

    auto g_0_xyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 581);

    auto g_0_xyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 582);

    auto g_0_xyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 583);

    auto g_0_xyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 584);

    auto g_0_xzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 632);

    auto g_0_xzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 634);

    auto g_0_xzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 635);

    auto g_0_xzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 637);

    auto g_0_xzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 638);

    auto g_0_xzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 639);

    auto g_0_xzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 641);

    auto g_0_xzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 642);

    auto g_0_xzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 643);

    auto g_0_xzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 644);

    auto g_0_xzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 646);

    auto g_0_xzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 647);

    auto g_0_xzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 648);

    auto g_0_xzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 649);

    auto g_0_xzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 650);

    auto g_0_xzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 652);

    auto g_0_xzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 653);

    auto g_0_xzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 654);

    auto g_0_xzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 655);

    auto g_0_xzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 656);

    auto g_0_xzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 657);

    auto g_0_xzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 659);

    auto g_0_xzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 660);

    auto g_0_xzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 661);

    auto g_0_xzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 662);

    auto g_0_xzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 663);

    auto g_0_xzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 664);

    auto g_0_xzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 665);

    auto g_0_xzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 666);

    auto g_0_xzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 667);

    auto g_0_xzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 668);

    auto g_0_xzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 669);

    auto g_0_xzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 670);

    auto g_0_xzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 671);

    auto g_0_xzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 672);

    auto g_0_xzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 673);

    auto g_0_xzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 674);

    auto g_0_yyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 675);

    auto g_0_yyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 676);

    auto g_0_yyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 677);

    auto g_0_yyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 678);

    auto g_0_yyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 679);

    auto g_0_yyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 680);

    auto g_0_yyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 681);

    auto g_0_yyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 682);

    auto g_0_yyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 683);

    auto g_0_yyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 684);

    auto g_0_yyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 685);

    auto g_0_yyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 686);

    auto g_0_yyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 687);

    auto g_0_yyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 688);

    auto g_0_yyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 689);

    auto g_0_yyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 690);

    auto g_0_yyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 691);

    auto g_0_yyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 692);

    auto g_0_yyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 693);

    auto g_0_yyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 694);

    auto g_0_yyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 695);

    auto g_0_yyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 696);

    auto g_0_yyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 697);

    auto g_0_yyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 698);

    auto g_0_yyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 699);

    auto g_0_yyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 700);

    auto g_0_yyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 701);

    auto g_0_yyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 702);

    auto g_0_yyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 703);

    auto g_0_yyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 704);

    auto g_0_yyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 705);

    auto g_0_yyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 706);

    auto g_0_yyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 707);

    auto g_0_yyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 708);

    auto g_0_yyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 709);

    auto g_0_yyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 710);

    auto g_0_yyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 711);

    auto g_0_yyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 712);

    auto g_0_yyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 713);

    auto g_0_yyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 714);

    auto g_0_yyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 715);

    auto g_0_yyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 716);

    auto g_0_yyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 717);

    auto g_0_yyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 718);

    auto g_0_yyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 719);

    auto g_0_yyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 721);

    auto g_0_yyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 723);

    auto g_0_yyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 726);

    auto g_0_yyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 730);

    auto g_0_yyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 735);

    auto g_0_yyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 741);

    auto g_0_yyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 748);

    auto g_0_yyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 756);

    auto g_0_yyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 765);

    auto g_0_yyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 766);

    auto g_0_yyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 767);

    auto g_0_yyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 768);

    auto g_0_yyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 769);

    auto g_0_yyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 770);

    auto g_0_yyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 771);

    auto g_0_yyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 772);

    auto g_0_yyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 773);

    auto g_0_yyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 774);

    auto g_0_yyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 775);

    auto g_0_yyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 776);

    auto g_0_yyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 777);

    auto g_0_yyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 778);

    auto g_0_yyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 779);

    auto g_0_yyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 780);

    auto g_0_yyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 781);

    auto g_0_yyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 782);

    auto g_0_yyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 783);

    auto g_0_yyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 784);

    auto g_0_yyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 785);

    auto g_0_yyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 786);

    auto g_0_yyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 787);

    auto g_0_yyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 788);

    auto g_0_yyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 789);

    auto g_0_yyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 790);

    auto g_0_yyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 791);

    auto g_0_yyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 792);

    auto g_0_yyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 793);

    auto g_0_yyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 794);

    auto g_0_yyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 795);

    auto g_0_yyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 796);

    auto g_0_yyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 797);

    auto g_0_yyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 798);

    auto g_0_yyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 799);

    auto g_0_yyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 800);

    auto g_0_yyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 801);

    auto g_0_yyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 802);

    auto g_0_yyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 803);

    auto g_0_yyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 804);

    auto g_0_yyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 805);

    auto g_0_yyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 806);

    auto g_0_yyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 807);

    auto g_0_yyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 808);

    auto g_0_yyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 809);

    auto g_0_yyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 810);

    auto g_0_yyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 811);

    auto g_0_yyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 812);

    auto g_0_yyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 813);

    auto g_0_yyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 814);

    auto g_0_yyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 815);

    auto g_0_yyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 816);

    auto g_0_yyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 817);

    auto g_0_yyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 818);

    auto g_0_yyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 819);

    auto g_0_yyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 820);

    auto g_0_yyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 821);

    auto g_0_yyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 822);

    auto g_0_yyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 823);

    auto g_0_yyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 824);

    auto g_0_yyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 825);

    auto g_0_yyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 826);

    auto g_0_yyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 827);

    auto g_0_yyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 828);

    auto g_0_yyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 829);

    auto g_0_yyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 830);

    auto g_0_yyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 831);

    auto g_0_yyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 832);

    auto g_0_yyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 833);

    auto g_0_yyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 834);

    auto g_0_yyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 835);

    auto g_0_yyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 836);

    auto g_0_yyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 837);

    auto g_0_yyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 838);

    auto g_0_yyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 839);

    auto g_0_yyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 840);

    auto g_0_yyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 841);

    auto g_0_yyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 842);

    auto g_0_yyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 843);

    auto g_0_yyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 844);

    auto g_0_yyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 845);

    auto g_0_yyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 846);

    auto g_0_yyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 847);

    auto g_0_yyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 848);

    auto g_0_yyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 849);

    auto g_0_yyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 850);

    auto g_0_yyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 851);

    auto g_0_yyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 852);

    auto g_0_yyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 853);

    auto g_0_yyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 854);

    auto g_0_yzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 855);

    auto g_0_yzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 857);

    auto g_0_yzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 859);

    auto g_0_yzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 860);

    auto g_0_yzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 862);

    auto g_0_yzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 863);

    auto g_0_yzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 864);

    auto g_0_yzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 866);

    auto g_0_yzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 867);

    auto g_0_yzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 868);

    auto g_0_yzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 869);

    auto g_0_yzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 871);

    auto g_0_yzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 872);

    auto g_0_yzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 873);

    auto g_0_yzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 874);

    auto g_0_yzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 875);

    auto g_0_yzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 877);

    auto g_0_yzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 878);

    auto g_0_yzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 879);

    auto g_0_yzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 880);

    auto g_0_yzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 881);

    auto g_0_yzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 882);

    auto g_0_yzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 884);

    auto g_0_yzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 885);

    auto g_0_yzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 886);

    auto g_0_yzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 887);

    auto g_0_yzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 888);

    auto g_0_yzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 889);

    auto g_0_yzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 890);

    auto g_0_yzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 892);

    auto g_0_yzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 893);

    auto g_0_yzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 894);

    auto g_0_yzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 895);

    auto g_0_yzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 896);

    auto g_0_yzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 897);

    auto g_0_yzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 898);

    auto g_0_yzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 899);

    auto g_0_zzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_shsl + 900);

    auto g_0_zzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_shsl + 901);

    auto g_0_zzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_shsl + 902);

    auto g_0_zzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_shsl + 903);

    auto g_0_zzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_shsl + 904);

    auto g_0_zzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_shsl + 905);

    auto g_0_zzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_shsl + 906);

    auto g_0_zzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_shsl + 907);

    auto g_0_zzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_shsl + 908);

    auto g_0_zzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_shsl + 909);

    auto g_0_zzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_shsl + 910);

    auto g_0_zzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_shsl + 911);

    auto g_0_zzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_shsl + 912);

    auto g_0_zzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_shsl + 913);

    auto g_0_zzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_shsl + 914);

    auto g_0_zzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 915);

    auto g_0_zzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 916);

    auto g_0_zzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 917);

    auto g_0_zzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 918);

    auto g_0_zzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 919);

    auto g_0_zzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 920);

    auto g_0_zzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 921);

    auto g_0_zzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 922);

    auto g_0_zzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 923);

    auto g_0_zzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 924);

    auto g_0_zzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 925);

    auto g_0_zzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 926);

    auto g_0_zzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 927);

    auto g_0_zzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 928);

    auto g_0_zzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 929);

    auto g_0_zzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 930);

    auto g_0_zzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 931);

    auto g_0_zzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 932);

    auto g_0_zzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 933);

    auto g_0_zzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 934);

    auto g_0_zzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 935);

    auto g_0_zzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_shsl + 936);

    auto g_0_zzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_shsl + 937);

    auto g_0_zzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_shsl + 938);

    auto g_0_zzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_shsl + 939);

    auto g_0_zzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_shsl + 940);

    auto g_0_zzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 941);

    auto g_0_zzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 942);

    auto g_0_zzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 943);

    auto g_0_zzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_shsl + 944);

    /// Set up components of auxilary buffer : SHSL

    auto g_0_xxxxx_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl);

    auto g_0_xxxxx_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 1);

    auto g_0_xxxxx_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 2);

    auto g_0_xxxxx_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 3);

    auto g_0_xxxxx_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 4);

    auto g_0_xxxxx_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 5);

    auto g_0_xxxxx_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 6);

    auto g_0_xxxxx_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 7);

    auto g_0_xxxxx_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 8);

    auto g_0_xxxxx_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 9);

    auto g_0_xxxxx_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 10);

    auto g_0_xxxxx_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 11);

    auto g_0_xxxxx_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 12);

    auto g_0_xxxxx_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 13);

    auto g_0_xxxxx_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 14);

    auto g_0_xxxxx_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 15);

    auto g_0_xxxxx_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 16);

    auto g_0_xxxxx_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 17);

    auto g_0_xxxxx_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 18);

    auto g_0_xxxxx_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 19);

    auto g_0_xxxxx_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 20);

    auto g_0_xxxxx_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 21);

    auto g_0_xxxxx_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 22);

    auto g_0_xxxxx_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 23);

    auto g_0_xxxxx_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 24);

    auto g_0_xxxxx_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 25);

    auto g_0_xxxxx_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 26);

    auto g_0_xxxxx_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 27);

    auto g_0_xxxxx_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 28);

    auto g_0_xxxxx_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 29);

    auto g_0_xxxxx_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 30);

    auto g_0_xxxxx_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 31);

    auto g_0_xxxxx_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 32);

    auto g_0_xxxxx_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 33);

    auto g_0_xxxxx_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 34);

    auto g_0_xxxxx_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 35);

    auto g_0_xxxxx_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 36);

    auto g_0_xxxxx_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 37);

    auto g_0_xxxxx_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 38);

    auto g_0_xxxxx_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 39);

    auto g_0_xxxxx_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 40);

    auto g_0_xxxxx_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 41);

    auto g_0_xxxxx_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 42);

    auto g_0_xxxxx_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 43);

    auto g_0_xxxxx_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 44);

    auto g_0_xxxxy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 45);

    auto g_0_xxxxy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 47);

    auto g_0_xxxxy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 50);

    auto g_0_xxxxy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 54);

    auto g_0_xxxxy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 59);

    auto g_0_xxxxy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 65);

    auto g_0_xxxxy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 72);

    auto g_0_xxxxy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 80);

    auto g_0_xxxxz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 90);

    auto g_0_xxxxz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 91);

    auto g_0_xxxxz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 93);

    auto g_0_xxxxz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 96);

    auto g_0_xxxxz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 100);

    auto g_0_xxxxz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 105);

    auto g_0_xxxxz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 111);

    auto g_0_xxxxz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 118);

    auto g_0_xxxyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 135);

    auto g_0_xxxyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 136);

    auto g_0_xxxyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 137);

    auto g_0_xxxyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 138);

    auto g_0_xxxyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 139);

    auto g_0_xxxyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 140);

    auto g_0_xxxyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 141);

    auto g_0_xxxyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 142);

    auto g_0_xxxyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 143);

    auto g_0_xxxyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 144);

    auto g_0_xxxyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 145);

    auto g_0_xxxyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 146);

    auto g_0_xxxyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 147);

    auto g_0_xxxyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 148);

    auto g_0_xxxyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 149);

    auto g_0_xxxyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 150);

    auto g_0_xxxyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 151);

    auto g_0_xxxyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 152);

    auto g_0_xxxyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 153);

    auto g_0_xxxyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 154);

    auto g_0_xxxyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 155);

    auto g_0_xxxyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 156);

    auto g_0_xxxyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 157);

    auto g_0_xxxyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 158);

    auto g_0_xxxyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 159);

    auto g_0_xxxyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 160);

    auto g_0_xxxyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 161);

    auto g_0_xxxyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 162);

    auto g_0_xxxyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 163);

    auto g_0_xxxyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 164);

    auto g_0_xxxyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 165);

    auto g_0_xxxyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 166);

    auto g_0_xxxyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 167);

    auto g_0_xxxyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 168);

    auto g_0_xxxyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 169);

    auto g_0_xxxyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 170);

    auto g_0_xxxyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 171);

    auto g_0_xxxyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 172);

    auto g_0_xxxyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 173);

    auto g_0_xxxyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 174);

    auto g_0_xxxyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 175);

    auto g_0_xxxyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 176);

    auto g_0_xxxyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 177);

    auto g_0_xxxyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 178);

    auto g_0_xxxyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 179);

    auto g_0_xxxzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 225);

    auto g_0_xxxzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 226);

    auto g_0_xxxzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 227);

    auto g_0_xxxzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 228);

    auto g_0_xxxzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 229);

    auto g_0_xxxzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 230);

    auto g_0_xxxzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 231);

    auto g_0_xxxzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 232);

    auto g_0_xxxzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 233);

    auto g_0_xxxzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 234);

    auto g_0_xxxzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 235);

    auto g_0_xxxzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 236);

    auto g_0_xxxzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 237);

    auto g_0_xxxzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 238);

    auto g_0_xxxzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 239);

    auto g_0_xxxzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 240);

    auto g_0_xxxzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 241);

    auto g_0_xxxzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 242);

    auto g_0_xxxzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 243);

    auto g_0_xxxzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 244);

    auto g_0_xxxzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 245);

    auto g_0_xxxzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 246);

    auto g_0_xxxzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 247);

    auto g_0_xxxzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 248);

    auto g_0_xxxzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 249);

    auto g_0_xxxzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 250);

    auto g_0_xxxzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 251);

    auto g_0_xxxzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 252);

    auto g_0_xxxzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 253);

    auto g_0_xxxzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 254);

    auto g_0_xxxzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 255);

    auto g_0_xxxzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 256);

    auto g_0_xxxzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 257);

    auto g_0_xxxzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 258);

    auto g_0_xxxzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 259);

    auto g_0_xxxzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 260);

    auto g_0_xxxzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 261);

    auto g_0_xxxzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 262);

    auto g_0_xxxzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 263);

    auto g_0_xxxzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 264);

    auto g_0_xxxzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 265);

    auto g_0_xxxzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 266);

    auto g_0_xxxzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 267);

    auto g_0_xxxzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 268);

    auto g_0_xxxzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 269);

    auto g_0_xxyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 270);

    auto g_0_xxyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 271);

    auto g_0_xxyyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 272);

    auto g_0_xxyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 273);

    auto g_0_xxyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 274);

    auto g_0_xxyyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 275);

    auto g_0_xxyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 276);

    auto g_0_xxyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 277);

    auto g_0_xxyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 278);

    auto g_0_xxyyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 279);

    auto g_0_xxyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 280);

    auto g_0_xxyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 281);

    auto g_0_xxyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 282);

    auto g_0_xxyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 283);

    auto g_0_xxyyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 284);

    auto g_0_xxyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 285);

    auto g_0_xxyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 286);

    auto g_0_xxyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 287);

    auto g_0_xxyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 288);

    auto g_0_xxyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 289);

    auto g_0_xxyyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 290);

    auto g_0_xxyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 291);

    auto g_0_xxyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 292);

    auto g_0_xxyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 293);

    auto g_0_xxyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 294);

    auto g_0_xxyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 295);

    auto g_0_xxyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 296);

    auto g_0_xxyyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 297);

    auto g_0_xxyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 298);

    auto g_0_xxyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 299);

    auto g_0_xxyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 300);

    auto g_0_xxyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 301);

    auto g_0_xxyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 302);

    auto g_0_xxyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 303);

    auto g_0_xxyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 304);

    auto g_0_xxyyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 305);

    auto g_0_xxyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 306);

    auto g_0_xxyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 307);

    auto g_0_xxyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 308);

    auto g_0_xxyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 309);

    auto g_0_xxyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 310);

    auto g_0_xxyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 311);

    auto g_0_xxyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 312);

    auto g_0_xxyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 313);

    auto g_0_xxyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 314);

    auto g_0_xxyyz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 316);

    auto g_0_xxyyz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 318);

    auto g_0_xxyyz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 321);

    auto g_0_xxyyz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 325);

    auto g_0_xxyyz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 330);

    auto g_0_xxyyz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 336);

    auto g_0_xxyyz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 343);

    auto g_0_xxyzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 360);

    auto g_0_xxyzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 362);

    auto g_0_xxyzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 365);

    auto g_0_xxyzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 369);

    auto g_0_xxyzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 374);

    auto g_0_xxyzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 380);

    auto g_0_xxyzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 387);

    auto g_0_xxyzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 395);

    auto g_0_xxzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 405);

    auto g_0_xxzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 406);

    auto g_0_xxzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 407);

    auto g_0_xxzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 408);

    auto g_0_xxzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 409);

    auto g_0_xxzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 410);

    auto g_0_xxzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 411);

    auto g_0_xxzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 412);

    auto g_0_xxzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 413);

    auto g_0_xxzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 414);

    auto g_0_xxzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 415);

    auto g_0_xxzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 416);

    auto g_0_xxzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 417);

    auto g_0_xxzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 418);

    auto g_0_xxzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 419);

    auto g_0_xxzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 420);

    auto g_0_xxzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 421);

    auto g_0_xxzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 422);

    auto g_0_xxzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 423);

    auto g_0_xxzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 424);

    auto g_0_xxzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 425);

    auto g_0_xxzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 426);

    auto g_0_xxzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 427);

    auto g_0_xxzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 428);

    auto g_0_xxzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 429);

    auto g_0_xxzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 430);

    auto g_0_xxzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 431);

    auto g_0_xxzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 432);

    auto g_0_xxzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 433);

    auto g_0_xxzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 434);

    auto g_0_xxzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 435);

    auto g_0_xxzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 436);

    auto g_0_xxzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 437);

    auto g_0_xxzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 438);

    auto g_0_xxzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 439);

    auto g_0_xxzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 440);

    auto g_0_xxzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 441);

    auto g_0_xxzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 442);

    auto g_0_xxzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 443);

    auto g_0_xxzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 444);

    auto g_0_xxzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 445);

    auto g_0_xxzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 446);

    auto g_0_xxzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 447);

    auto g_0_xxzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 448);

    auto g_0_xxzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 449);

    auto g_0_xyyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 451);

    auto g_0_xyyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 453);

    auto g_0_xyyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 454);

    auto g_0_xyyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 456);

    auto g_0_xyyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 457);

    auto g_0_xyyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 458);

    auto g_0_xyyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 460);

    auto g_0_xyyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 461);

    auto g_0_xyyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 462);

    auto g_0_xyyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 463);

    auto g_0_xyyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 465);

    auto g_0_xyyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 466);

    auto g_0_xyyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 467);

    auto g_0_xyyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 468);

    auto g_0_xyyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 469);

    auto g_0_xyyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 471);

    auto g_0_xyyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 472);

    auto g_0_xyyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 473);

    auto g_0_xyyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 474);

    auto g_0_xyyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 475);

    auto g_0_xyyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 476);

    auto g_0_xyyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 478);

    auto g_0_xyyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 479);

    auto g_0_xyyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 480);

    auto g_0_xyyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 481);

    auto g_0_xyyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 482);

    auto g_0_xyyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 483);

    auto g_0_xyyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 484);

    auto g_0_xyyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 486);

    auto g_0_xyyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 487);

    auto g_0_xyyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 488);

    auto g_0_xyyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 489);

    auto g_0_xyyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 490);

    auto g_0_xyyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 491);

    auto g_0_xyyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 492);

    auto g_0_xyyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 493);

    auto g_0_xyyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 494);

    auto g_0_xyyzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 544);

    auto g_0_xyyzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 547);

    auto g_0_xyyzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 548);

    auto g_0_xyyzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 551);

    auto g_0_xyyzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 552);

    auto g_0_xyyzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 553);

    auto g_0_xyyzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 556);

    auto g_0_xyyzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 557);

    auto g_0_xyyzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 558);

    auto g_0_xyyzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 559);

    auto g_0_xyyzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 562);

    auto g_0_xyyzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 563);

    auto g_0_xyyzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 564);

    auto g_0_xyyzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 565);

    auto g_0_xyyzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 566);

    auto g_0_xyyzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 569);

    auto g_0_xyyzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 570);

    auto g_0_xyyzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 571);

    auto g_0_xyyzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 572);

    auto g_0_xyyzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 573);

    auto g_0_xyyzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 574);

    auto g_0_xyyzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 576);

    auto g_0_xyyzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 577);

    auto g_0_xyyzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 578);

    auto g_0_xyyzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 579);

    auto g_0_xyyzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 580);

    auto g_0_xyyzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 581);

    auto g_0_xyyzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 582);

    auto g_0_xyyzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 583);

    auto g_0_xyyzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 584);

    auto g_0_xzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 632);

    auto g_0_xzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 634);

    auto g_0_xzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 635);

    auto g_0_xzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 637);

    auto g_0_xzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 638);

    auto g_0_xzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 639);

    auto g_0_xzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 641);

    auto g_0_xzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 642);

    auto g_0_xzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 643);

    auto g_0_xzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 644);

    auto g_0_xzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 646);

    auto g_0_xzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 647);

    auto g_0_xzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 648);

    auto g_0_xzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 649);

    auto g_0_xzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 650);

    auto g_0_xzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 652);

    auto g_0_xzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 653);

    auto g_0_xzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 654);

    auto g_0_xzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 655);

    auto g_0_xzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 656);

    auto g_0_xzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 657);

    auto g_0_xzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 659);

    auto g_0_xzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 660);

    auto g_0_xzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 661);

    auto g_0_xzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 662);

    auto g_0_xzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 663);

    auto g_0_xzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 664);

    auto g_0_xzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 665);

    auto g_0_xzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 666);

    auto g_0_xzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 667);

    auto g_0_xzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 668);

    auto g_0_xzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 669);

    auto g_0_xzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 670);

    auto g_0_xzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 671);

    auto g_0_xzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 672);

    auto g_0_xzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 673);

    auto g_0_xzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 674);

    auto g_0_yyyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 675);

    auto g_0_yyyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 676);

    auto g_0_yyyyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 677);

    auto g_0_yyyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 678);

    auto g_0_yyyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 679);

    auto g_0_yyyyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 680);

    auto g_0_yyyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 681);

    auto g_0_yyyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 682);

    auto g_0_yyyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 683);

    auto g_0_yyyyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 684);

    auto g_0_yyyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 685);

    auto g_0_yyyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 686);

    auto g_0_yyyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 687);

    auto g_0_yyyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 688);

    auto g_0_yyyyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 689);

    auto g_0_yyyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 690);

    auto g_0_yyyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 691);

    auto g_0_yyyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 692);

    auto g_0_yyyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 693);

    auto g_0_yyyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 694);

    auto g_0_yyyyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 695);

    auto g_0_yyyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 696);

    auto g_0_yyyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 697);

    auto g_0_yyyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 698);

    auto g_0_yyyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 699);

    auto g_0_yyyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 700);

    auto g_0_yyyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 701);

    auto g_0_yyyyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 702);

    auto g_0_yyyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 703);

    auto g_0_yyyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 704);

    auto g_0_yyyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 705);

    auto g_0_yyyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 706);

    auto g_0_yyyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 707);

    auto g_0_yyyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 708);

    auto g_0_yyyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 709);

    auto g_0_yyyyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 710);

    auto g_0_yyyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 711);

    auto g_0_yyyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 712);

    auto g_0_yyyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 713);

    auto g_0_yyyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 714);

    auto g_0_yyyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 715);

    auto g_0_yyyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 716);

    auto g_0_yyyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 717);

    auto g_0_yyyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 718);

    auto g_0_yyyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 719);

    auto g_0_yyyyz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 721);

    auto g_0_yyyyz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 723);

    auto g_0_yyyyz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 726);

    auto g_0_yyyyz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 730);

    auto g_0_yyyyz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 735);

    auto g_0_yyyyz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 741);

    auto g_0_yyyyz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 748);

    auto g_0_yyyyz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 756);

    auto g_0_yyyzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 765);

    auto g_0_yyyzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 766);

    auto g_0_yyyzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 767);

    auto g_0_yyyzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 768);

    auto g_0_yyyzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 769);

    auto g_0_yyyzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 770);

    auto g_0_yyyzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 771);

    auto g_0_yyyzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 772);

    auto g_0_yyyzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 773);

    auto g_0_yyyzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 774);

    auto g_0_yyyzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 775);

    auto g_0_yyyzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 776);

    auto g_0_yyyzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 777);

    auto g_0_yyyzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 778);

    auto g_0_yyyzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 779);

    auto g_0_yyyzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 780);

    auto g_0_yyyzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 781);

    auto g_0_yyyzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 782);

    auto g_0_yyyzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 783);

    auto g_0_yyyzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 784);

    auto g_0_yyyzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 785);

    auto g_0_yyyzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 786);

    auto g_0_yyyzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 787);

    auto g_0_yyyzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 788);

    auto g_0_yyyzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 789);

    auto g_0_yyyzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 790);

    auto g_0_yyyzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 791);

    auto g_0_yyyzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 792);

    auto g_0_yyyzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 793);

    auto g_0_yyyzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 794);

    auto g_0_yyyzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 795);

    auto g_0_yyyzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 796);

    auto g_0_yyyzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 797);

    auto g_0_yyyzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 798);

    auto g_0_yyyzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 799);

    auto g_0_yyyzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 800);

    auto g_0_yyyzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 801);

    auto g_0_yyyzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 802);

    auto g_0_yyyzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 803);

    auto g_0_yyyzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 804);

    auto g_0_yyyzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 805);

    auto g_0_yyyzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 806);

    auto g_0_yyyzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 807);

    auto g_0_yyyzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 808);

    auto g_0_yyyzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 809);

    auto g_0_yyzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 810);

    auto g_0_yyzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 811);

    auto g_0_yyzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 812);

    auto g_0_yyzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 813);

    auto g_0_yyzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 814);

    auto g_0_yyzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 815);

    auto g_0_yyzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 816);

    auto g_0_yyzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 817);

    auto g_0_yyzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 818);

    auto g_0_yyzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 819);

    auto g_0_yyzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 820);

    auto g_0_yyzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 821);

    auto g_0_yyzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 822);

    auto g_0_yyzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 823);

    auto g_0_yyzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 824);

    auto g_0_yyzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 825);

    auto g_0_yyzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 826);

    auto g_0_yyzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 827);

    auto g_0_yyzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 828);

    auto g_0_yyzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 829);

    auto g_0_yyzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 830);

    auto g_0_yyzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 831);

    auto g_0_yyzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 832);

    auto g_0_yyzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 833);

    auto g_0_yyzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 834);

    auto g_0_yyzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 835);

    auto g_0_yyzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 836);

    auto g_0_yyzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 837);

    auto g_0_yyzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 838);

    auto g_0_yyzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 839);

    auto g_0_yyzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 840);

    auto g_0_yyzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 841);

    auto g_0_yyzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 842);

    auto g_0_yyzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 843);

    auto g_0_yyzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 844);

    auto g_0_yyzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 845);

    auto g_0_yyzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 846);

    auto g_0_yyzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 847);

    auto g_0_yyzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 848);

    auto g_0_yyzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 849);

    auto g_0_yyzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 850);

    auto g_0_yyzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 851);

    auto g_0_yyzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 852);

    auto g_0_yyzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 853);

    auto g_0_yyzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 854);

    auto g_0_yzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 855);

    auto g_0_yzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 857);

    auto g_0_yzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 859);

    auto g_0_yzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 860);

    auto g_0_yzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 862);

    auto g_0_yzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 863);

    auto g_0_yzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 864);

    auto g_0_yzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 866);

    auto g_0_yzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 867);

    auto g_0_yzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 868);

    auto g_0_yzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 869);

    auto g_0_yzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 871);

    auto g_0_yzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 872);

    auto g_0_yzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 873);

    auto g_0_yzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 874);

    auto g_0_yzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 875);

    auto g_0_yzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 877);

    auto g_0_yzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 878);

    auto g_0_yzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 879);

    auto g_0_yzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 880);

    auto g_0_yzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 881);

    auto g_0_yzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 882);

    auto g_0_yzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 884);

    auto g_0_yzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 885);

    auto g_0_yzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 886);

    auto g_0_yzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 887);

    auto g_0_yzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 888);

    auto g_0_yzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 889);

    auto g_0_yzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 890);

    auto g_0_yzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 892);

    auto g_0_yzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 893);

    auto g_0_yzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 894);

    auto g_0_yzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 895);

    auto g_0_yzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 896);

    auto g_0_yzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 897);

    auto g_0_yzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 898);

    auto g_0_yzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 899);

    auto g_0_zzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_shsl + 900);

    auto g_0_zzzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_shsl + 901);

    auto g_0_zzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_shsl + 902);

    auto g_0_zzzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_shsl + 903);

    auto g_0_zzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_shsl + 904);

    auto g_0_zzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_shsl + 905);

    auto g_0_zzzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_shsl + 906);

    auto g_0_zzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_shsl + 907);

    auto g_0_zzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_shsl + 908);

    auto g_0_zzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_shsl + 909);

    auto g_0_zzzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_shsl + 910);

    auto g_0_zzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_shsl + 911);

    auto g_0_zzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_shsl + 912);

    auto g_0_zzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_shsl + 913);

    auto g_0_zzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_shsl + 914);

    auto g_0_zzzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 915);

    auto g_0_zzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 916);

    auto g_0_zzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 917);

    auto g_0_zzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 918);

    auto g_0_zzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 919);

    auto g_0_zzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 920);

    auto g_0_zzzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 921);

    auto g_0_zzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 922);

    auto g_0_zzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 923);

    auto g_0_zzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 924);

    auto g_0_zzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 925);

    auto g_0_zzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 926);

    auto g_0_zzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 927);

    auto g_0_zzzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 928);

    auto g_0_zzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 929);

    auto g_0_zzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 930);

    auto g_0_zzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 931);

    auto g_0_zzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 932);

    auto g_0_zzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 933);

    auto g_0_zzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 934);

    auto g_0_zzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 935);

    auto g_0_zzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_shsl + 936);

    auto g_0_zzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_shsl + 937);

    auto g_0_zzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_shsl + 938);

    auto g_0_zzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_shsl + 939);

    auto g_0_zzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_shsl + 940);

    auto g_0_zzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 941);

    auto g_0_zzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 942);

    auto g_0_zzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 943);

    auto g_0_zzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_shsl + 944);

    /// Set up components of auxilary buffer : SISK

    auto g_0_xxxxxx_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk);

    auto g_0_xxxxxx_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 1);

    auto g_0_xxxxxx_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 2);

    auto g_0_xxxxxx_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 3);

    auto g_0_xxxxxx_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 4);

    auto g_0_xxxxxx_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 5);

    auto g_0_xxxxxx_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 6);

    auto g_0_xxxxxx_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 7);

    auto g_0_xxxxxx_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 8);

    auto g_0_xxxxxx_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 9);

    auto g_0_xxxxxx_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 10);

    auto g_0_xxxxxx_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 11);

    auto g_0_xxxxxx_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 12);

    auto g_0_xxxxxx_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 13);

    auto g_0_xxxxxx_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 14);

    auto g_0_xxxxxx_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 15);

    auto g_0_xxxxxx_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 16);

    auto g_0_xxxxxx_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 17);

    auto g_0_xxxxxx_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 18);

    auto g_0_xxxxxx_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 19);

    auto g_0_xxxxxx_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 20);

    auto g_0_xxxxxx_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 21);

    auto g_0_xxxxxx_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 22);

    auto g_0_xxxxxx_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 23);

    auto g_0_xxxxxx_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 24);

    auto g_0_xxxxxx_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 25);

    auto g_0_xxxxxx_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 26);

    auto g_0_xxxxxx_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 27);

    auto g_0_xxxxxx_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 28);

    auto g_0_xxxxxx_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 29);

    auto g_0_xxxxxx_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 30);

    auto g_0_xxxxxx_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 31);

    auto g_0_xxxxxx_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 32);

    auto g_0_xxxxxx_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 33);

    auto g_0_xxxxxx_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 34);

    auto g_0_xxxxxx_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 35);

    auto g_0_xxxxxz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 74);

    auto g_0_xxxxxz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 76);

    auto g_0_xxxxxz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 77);

    auto g_0_xxxxxz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 79);

    auto g_0_xxxxxz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 80);

    auto g_0_xxxxxz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 81);

    auto g_0_xxxxxz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 83);

    auto g_0_xxxxxz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 84);

    auto g_0_xxxxxz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 85);

    auto g_0_xxxxxz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 86);

    auto g_0_xxxxxz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 88);

    auto g_0_xxxxxz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 89);

    auto g_0_xxxxxz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 90);

    auto g_0_xxxxxz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 91);

    auto g_0_xxxxxz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 92);

    auto g_0_xxxxxz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 94);

    auto g_0_xxxxxz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 95);

    auto g_0_xxxxxz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 96);

    auto g_0_xxxxxz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 97);

    auto g_0_xxxxxz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 98);

    auto g_0_xxxxxz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 99);

    auto g_0_xxxxxz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 101);

    auto g_0_xxxxxz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 102);

    auto g_0_xxxxxz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 103);

    auto g_0_xxxxxz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 104);

    auto g_0_xxxxxz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 105);

    auto g_0_xxxxxz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 106);

    auto g_0_xxxxxz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 107);

    auto g_0_xxxxyy_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 108);

    auto g_0_xxxxyy_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 109);

    auto g_0_xxxxyy_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 110);

    auto g_0_xxxxyy_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 111);

    auto g_0_xxxxyy_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 112);

    auto g_0_xxxxyy_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 113);

    auto g_0_xxxxyy_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 114);

    auto g_0_xxxxyy_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 115);

    auto g_0_xxxxyy_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 116);

    auto g_0_xxxxyy_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 117);

    auto g_0_xxxxyy_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 118);

    auto g_0_xxxxyy_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 119);

    auto g_0_xxxxyy_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 120);

    auto g_0_xxxxyy_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 121);

    auto g_0_xxxxyy_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 122);

    auto g_0_xxxxyy_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 123);

    auto g_0_xxxxyy_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 124);

    auto g_0_xxxxyy_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 125);

    auto g_0_xxxxyy_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 126);

    auto g_0_xxxxyy_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 127);

    auto g_0_xxxxyy_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 128);

    auto g_0_xxxxyy_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 129);

    auto g_0_xxxxyy_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 130);

    auto g_0_xxxxyy_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 131);

    auto g_0_xxxxyy_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 132);

    auto g_0_xxxxyy_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 133);

    auto g_0_xxxxyy_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 134);

    auto g_0_xxxxyy_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 135);

    auto g_0_xxxxyy_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 136);

    auto g_0_xxxxyy_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 137);

    auto g_0_xxxxyy_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 138);

    auto g_0_xxxxyy_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 139);

    auto g_0_xxxxyy_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 140);

    auto g_0_xxxxyy_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 141);

    auto g_0_xxxxyy_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 142);

    auto g_0_xxxxyy_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 143);

    auto g_0_xxxxzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 180);

    auto g_0_xxxxzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 181);

    auto g_0_xxxxzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 182);

    auto g_0_xxxxzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 183);

    auto g_0_xxxxzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 184);

    auto g_0_xxxxzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 185);

    auto g_0_xxxxzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 186);

    auto g_0_xxxxzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 187);

    auto g_0_xxxxzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 188);

    auto g_0_xxxxzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 189);

    auto g_0_xxxxzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 190);

    auto g_0_xxxxzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 191);

    auto g_0_xxxxzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 192);

    auto g_0_xxxxzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 193);

    auto g_0_xxxxzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 194);

    auto g_0_xxxxzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 195);

    auto g_0_xxxxzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 196);

    auto g_0_xxxxzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 197);

    auto g_0_xxxxzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 198);

    auto g_0_xxxxzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 199);

    auto g_0_xxxxzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 200);

    auto g_0_xxxxzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 201);

    auto g_0_xxxxzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 202);

    auto g_0_xxxxzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 203);

    auto g_0_xxxxzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 204);

    auto g_0_xxxxzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 205);

    auto g_0_xxxxzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 206);

    auto g_0_xxxxzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 207);

    auto g_0_xxxxzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 208);

    auto g_0_xxxxzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 209);

    auto g_0_xxxxzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 210);

    auto g_0_xxxxzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 211);

    auto g_0_xxxxzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 212);

    auto g_0_xxxxzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 213);

    auto g_0_xxxxzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 214);

    auto g_0_xxxxzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 215);

    auto g_0_xxxyyy_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 216);

    auto g_0_xxxyyy_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 217);

    auto g_0_xxxyyy_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 218);

    auto g_0_xxxyyy_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 219);

    auto g_0_xxxyyy_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 220);

    auto g_0_xxxyyy_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 221);

    auto g_0_xxxyyy_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 222);

    auto g_0_xxxyyy_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 223);

    auto g_0_xxxyyy_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 224);

    auto g_0_xxxyyy_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 225);

    auto g_0_xxxyyy_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 226);

    auto g_0_xxxyyy_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 227);

    auto g_0_xxxyyy_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 228);

    auto g_0_xxxyyy_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 229);

    auto g_0_xxxyyy_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 230);

    auto g_0_xxxyyy_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 231);

    auto g_0_xxxyyy_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 232);

    auto g_0_xxxyyy_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 233);

    auto g_0_xxxyyy_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 234);

    auto g_0_xxxyyy_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 235);

    auto g_0_xxxyyy_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 236);

    auto g_0_xxxyyy_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 237);

    auto g_0_xxxyyy_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 238);

    auto g_0_xxxyyy_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 239);

    auto g_0_xxxyyy_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 240);

    auto g_0_xxxyyy_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 241);

    auto g_0_xxxyyy_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 242);

    auto g_0_xxxyyy_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 243);

    auto g_0_xxxyyy_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 244);

    auto g_0_xxxyyy_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 245);

    auto g_0_xxxyyy_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 246);

    auto g_0_xxxyyy_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 247);

    auto g_0_xxxyyy_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 248);

    auto g_0_xxxyyy_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 249);

    auto g_0_xxxyyy_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 250);

    auto g_0_xxxyyy_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 251);

    auto g_0_xxxzzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 324);

    auto g_0_xxxzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 325);

    auto g_0_xxxzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 326);

    auto g_0_xxxzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 327);

    auto g_0_xxxzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 328);

    auto g_0_xxxzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 329);

    auto g_0_xxxzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 330);

    auto g_0_xxxzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 331);

    auto g_0_xxxzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 332);

    auto g_0_xxxzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 333);

    auto g_0_xxxzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 334);

    auto g_0_xxxzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 335);

    auto g_0_xxxzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 336);

    auto g_0_xxxzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 337);

    auto g_0_xxxzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 338);

    auto g_0_xxxzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 339);

    auto g_0_xxxzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 340);

    auto g_0_xxxzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 341);

    auto g_0_xxxzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 342);

    auto g_0_xxxzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 343);

    auto g_0_xxxzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 344);

    auto g_0_xxxzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 345);

    auto g_0_xxxzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 346);

    auto g_0_xxxzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 347);

    auto g_0_xxxzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 348);

    auto g_0_xxxzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 349);

    auto g_0_xxxzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 350);

    auto g_0_xxxzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 351);

    auto g_0_xxxzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 352);

    auto g_0_xxxzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 353);

    auto g_0_xxxzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 354);

    auto g_0_xxxzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 355);

    auto g_0_xxxzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 356);

    auto g_0_xxxzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 357);

    auto g_0_xxxzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 358);

    auto g_0_xxxzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 359);

    auto g_0_xxyyyy_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 360);

    auto g_0_xxyyyy_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 361);

    auto g_0_xxyyyy_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 362);

    auto g_0_xxyyyy_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 363);

    auto g_0_xxyyyy_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 364);

    auto g_0_xxyyyy_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 365);

    auto g_0_xxyyyy_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 366);

    auto g_0_xxyyyy_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 367);

    auto g_0_xxyyyy_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 368);

    auto g_0_xxyyyy_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 369);

    auto g_0_xxyyyy_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 370);

    auto g_0_xxyyyy_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 371);

    auto g_0_xxyyyy_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 372);

    auto g_0_xxyyyy_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 373);

    auto g_0_xxyyyy_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 374);

    auto g_0_xxyyyy_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 375);

    auto g_0_xxyyyy_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 376);

    auto g_0_xxyyyy_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 377);

    auto g_0_xxyyyy_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 378);

    auto g_0_xxyyyy_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 379);

    auto g_0_xxyyyy_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 380);

    auto g_0_xxyyyy_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 381);

    auto g_0_xxyyyy_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 382);

    auto g_0_xxyyyy_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 383);

    auto g_0_xxyyyy_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 384);

    auto g_0_xxyyyy_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 385);

    auto g_0_xxyyyy_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 386);

    auto g_0_xxyyyy_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 387);

    auto g_0_xxyyyy_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 388);

    auto g_0_xxyyyy_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 389);

    auto g_0_xxyyyy_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 390);

    auto g_0_xxyyyy_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 391);

    auto g_0_xxyyyy_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 392);

    auto g_0_xxyyyy_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 393);

    auto g_0_xxyyyy_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 394);

    auto g_0_xxyyyy_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 395);

    auto g_0_xxyyzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 436);

    auto g_0_xxyyzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 439);

    auto g_0_xxyyzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 440);

    auto g_0_xxyyzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 443);

    auto g_0_xxyyzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 444);

    auto g_0_xxyyzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 445);

    auto g_0_xxyyzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 448);

    auto g_0_xxyyzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 449);

    auto g_0_xxyyzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 450);

    auto g_0_xxyyzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 451);

    auto g_0_xxyyzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 454);

    auto g_0_xxyyzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 455);

    auto g_0_xxyyzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 456);

    auto g_0_xxyyzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 457);

    auto g_0_xxyyzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 458);

    auto g_0_xxyyzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 461);

    auto g_0_xxyyzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 462);

    auto g_0_xxyyzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 463);

    auto g_0_xxyyzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 464);

    auto g_0_xxyyzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 465);

    auto g_0_xxyyzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 466);

    auto g_0_xxzzzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 504);

    auto g_0_xxzzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 505);

    auto g_0_xxzzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 506);

    auto g_0_xxzzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 507);

    auto g_0_xxzzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 508);

    auto g_0_xxzzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 509);

    auto g_0_xxzzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 510);

    auto g_0_xxzzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 511);

    auto g_0_xxzzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 512);

    auto g_0_xxzzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 513);

    auto g_0_xxzzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 514);

    auto g_0_xxzzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 515);

    auto g_0_xxzzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 516);

    auto g_0_xxzzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 517);

    auto g_0_xxzzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 518);

    auto g_0_xxzzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 519);

    auto g_0_xxzzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 520);

    auto g_0_xxzzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 521);

    auto g_0_xxzzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 522);

    auto g_0_xxzzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 523);

    auto g_0_xxzzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 524);

    auto g_0_xxzzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 525);

    auto g_0_xxzzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 526);

    auto g_0_xxzzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 527);

    auto g_0_xxzzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 528);

    auto g_0_xxzzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 529);

    auto g_0_xxzzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 530);

    auto g_0_xxzzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 531);

    auto g_0_xxzzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 532);

    auto g_0_xxzzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 533);

    auto g_0_xxzzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 534);

    auto g_0_xxzzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 535);

    auto g_0_xxzzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 536);

    auto g_0_xxzzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 537);

    auto g_0_xxzzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 538);

    auto g_0_xxzzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 539);

    auto g_0_xyyyyy_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 541);

    auto g_0_xyyyyy_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 543);

    auto g_0_xyyyyy_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 544);

    auto g_0_xyyyyy_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 546);

    auto g_0_xyyyyy_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 547);

    auto g_0_xyyyyy_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 548);

    auto g_0_xyyyyy_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 550);

    auto g_0_xyyyyy_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 551);

    auto g_0_xyyyyy_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 552);

    auto g_0_xyyyyy_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 553);

    auto g_0_xyyyyy_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 555);

    auto g_0_xyyyyy_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 556);

    auto g_0_xyyyyy_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 557);

    auto g_0_xyyyyy_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 558);

    auto g_0_xyyyyy_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 559);

    auto g_0_xyyyyy_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 561);

    auto g_0_xyyyyy_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 562);

    auto g_0_xyyyyy_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 563);

    auto g_0_xyyyyy_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 564);

    auto g_0_xyyyyy_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 565);

    auto g_0_xyyyyy_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 566);

    auto g_0_xyyyyy_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 568);

    auto g_0_xyyyyy_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 569);

    auto g_0_xyyyyy_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 570);

    auto g_0_xyyyyy_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 571);

    auto g_0_xyyyyy_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 572);

    auto g_0_xyyyyy_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 573);

    auto g_0_xyyyyy_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 574);

    auto g_0_xyyyzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 616);

    auto g_0_xyyyzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 619);

    auto g_0_xyyyzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 620);

    auto g_0_xyyyzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 623);

    auto g_0_xyyyzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 624);

    auto g_0_xyyyzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 625);

    auto g_0_xyyyzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 628);

    auto g_0_xyyyzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 629);

    auto g_0_xyyyzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 630);

    auto g_0_xyyyzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 631);

    auto g_0_xyyyzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 634);

    auto g_0_xyyyzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 635);

    auto g_0_xyyyzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 636);

    auto g_0_xyyyzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 637);

    auto g_0_xyyyzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 638);

    auto g_0_xyyyzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 641);

    auto g_0_xyyyzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 642);

    auto g_0_xyyyzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 643);

    auto g_0_xyyyzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 644);

    auto g_0_xyyyzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 645);

    auto g_0_xyyyzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 646);

    auto g_0_xyyzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 652);

    auto g_0_xyyzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 655);

    auto g_0_xyyzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 656);

    auto g_0_xyyzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 659);

    auto g_0_xyyzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 660);

    auto g_0_xyyzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 661);

    auto g_0_xyyzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 664);

    auto g_0_xyyzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 665);

    auto g_0_xyyzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 666);

    auto g_0_xyyzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 667);

    auto g_0_xyyzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 670);

    auto g_0_xyyzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 671);

    auto g_0_xyyzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 672);

    auto g_0_xyyzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 673);

    auto g_0_xyyzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 674);

    auto g_0_xyyzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 677);

    auto g_0_xyyzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 678);

    auto g_0_xyyzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 679);

    auto g_0_xyyzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 680);

    auto g_0_xyyzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 681);

    auto g_0_xyyzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 682);

    auto g_0_xzzzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 722);

    auto g_0_xzzzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 724);

    auto g_0_xzzzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 725);

    auto g_0_xzzzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 727);

    auto g_0_xzzzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 728);

    auto g_0_xzzzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 729);

    auto g_0_xzzzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 731);

    auto g_0_xzzzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 732);

    auto g_0_xzzzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 733);

    auto g_0_xzzzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 734);

    auto g_0_xzzzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 736);

    auto g_0_xzzzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 737);

    auto g_0_xzzzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 738);

    auto g_0_xzzzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 739);

    auto g_0_xzzzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 740);

    auto g_0_xzzzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 742);

    auto g_0_xzzzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 743);

    auto g_0_xzzzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 744);

    auto g_0_xzzzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 745);

    auto g_0_xzzzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 746);

    auto g_0_xzzzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 747);

    auto g_0_xzzzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 749);

    auto g_0_xzzzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 750);

    auto g_0_xzzzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 751);

    auto g_0_xzzzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 752);

    auto g_0_xzzzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 753);

    auto g_0_xzzzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 754);

    auto g_0_xzzzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 755);

    auto g_0_yyyyyy_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 756);

    auto g_0_yyyyyy_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 757);

    auto g_0_yyyyyy_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 758);

    auto g_0_yyyyyy_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 759);

    auto g_0_yyyyyy_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 760);

    auto g_0_yyyyyy_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 761);

    auto g_0_yyyyyy_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 762);

    auto g_0_yyyyyy_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 763);

    auto g_0_yyyyyy_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 764);

    auto g_0_yyyyyy_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 765);

    auto g_0_yyyyyy_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 766);

    auto g_0_yyyyyy_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 767);

    auto g_0_yyyyyy_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 768);

    auto g_0_yyyyyy_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 769);

    auto g_0_yyyyyy_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 770);

    auto g_0_yyyyyy_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 771);

    auto g_0_yyyyyy_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 772);

    auto g_0_yyyyyy_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 773);

    auto g_0_yyyyyy_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 774);

    auto g_0_yyyyyy_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 775);

    auto g_0_yyyyyy_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 776);

    auto g_0_yyyyyy_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 777);

    auto g_0_yyyyyy_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 778);

    auto g_0_yyyyyy_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 779);

    auto g_0_yyyyyy_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 780);

    auto g_0_yyyyyy_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 781);

    auto g_0_yyyyyy_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 782);

    auto g_0_yyyyyy_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 783);

    auto g_0_yyyyyy_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 784);

    auto g_0_yyyyyy_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 785);

    auto g_0_yyyyyy_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 786);

    auto g_0_yyyyyy_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 787);

    auto g_0_yyyyyy_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 788);

    auto g_0_yyyyyy_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 789);

    auto g_0_yyyyyy_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 790);

    auto g_0_yyyyyy_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 791);

    auto g_0_yyyyyz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 794);

    auto g_0_yyyyyz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 796);

    auto g_0_yyyyyz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 797);

    auto g_0_yyyyyz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 799);

    auto g_0_yyyyyz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 800);

    auto g_0_yyyyyz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 801);

    auto g_0_yyyyyz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 803);

    auto g_0_yyyyyz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 804);

    auto g_0_yyyyyz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 805);

    auto g_0_yyyyyz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 806);

    auto g_0_yyyyyz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 808);

    auto g_0_yyyyyz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 809);

    auto g_0_yyyyyz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 810);

    auto g_0_yyyyyz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 811);

    auto g_0_yyyyyz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 812);

    auto g_0_yyyyyz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 814);

    auto g_0_yyyyyz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 815);

    auto g_0_yyyyyz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 816);

    auto g_0_yyyyyz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 817);

    auto g_0_yyyyyz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 818);

    auto g_0_yyyyyz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 819);

    auto g_0_yyyyyz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 821);

    auto g_0_yyyyyz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 822);

    auto g_0_yyyyyz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 823);

    auto g_0_yyyyyz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 824);

    auto g_0_yyyyyz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 825);

    auto g_0_yyyyyz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 826);

    auto g_0_yyyyyz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 827);

    auto g_0_yyyyzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 828);

    auto g_0_yyyyzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 829);

    auto g_0_yyyyzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 830);

    auto g_0_yyyyzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 831);

    auto g_0_yyyyzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 832);

    auto g_0_yyyyzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 833);

    auto g_0_yyyyzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 834);

    auto g_0_yyyyzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 835);

    auto g_0_yyyyzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 836);

    auto g_0_yyyyzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 837);

    auto g_0_yyyyzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 838);

    auto g_0_yyyyzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 839);

    auto g_0_yyyyzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 840);

    auto g_0_yyyyzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 841);

    auto g_0_yyyyzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 842);

    auto g_0_yyyyzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 843);

    auto g_0_yyyyzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 844);

    auto g_0_yyyyzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 845);

    auto g_0_yyyyzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 846);

    auto g_0_yyyyzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 847);

    auto g_0_yyyyzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 848);

    auto g_0_yyyyzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 849);

    auto g_0_yyyyzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 850);

    auto g_0_yyyyzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 851);

    auto g_0_yyyyzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 852);

    auto g_0_yyyyzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 853);

    auto g_0_yyyyzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 854);

    auto g_0_yyyyzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 855);

    auto g_0_yyyyzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 856);

    auto g_0_yyyyzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 857);

    auto g_0_yyyyzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 858);

    auto g_0_yyyyzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 859);

    auto g_0_yyyyzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 860);

    auto g_0_yyyyzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 861);

    auto g_0_yyyyzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 862);

    auto g_0_yyyyzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 863);

    auto g_0_yyyzzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 864);

    auto g_0_yyyzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 865);

    auto g_0_yyyzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 866);

    auto g_0_yyyzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 867);

    auto g_0_yyyzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 868);

    auto g_0_yyyzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 869);

    auto g_0_yyyzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 870);

    auto g_0_yyyzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 871);

    auto g_0_yyyzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 872);

    auto g_0_yyyzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 873);

    auto g_0_yyyzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 874);

    auto g_0_yyyzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 875);

    auto g_0_yyyzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 876);

    auto g_0_yyyzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 877);

    auto g_0_yyyzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 878);

    auto g_0_yyyzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 879);

    auto g_0_yyyzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 880);

    auto g_0_yyyzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 881);

    auto g_0_yyyzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 882);

    auto g_0_yyyzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 883);

    auto g_0_yyyzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 884);

    auto g_0_yyyzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 885);

    auto g_0_yyyzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 886);

    auto g_0_yyyzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 887);

    auto g_0_yyyzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 888);

    auto g_0_yyyzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 889);

    auto g_0_yyyzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 890);

    auto g_0_yyyzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 891);

    auto g_0_yyyzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 892);

    auto g_0_yyyzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 893);

    auto g_0_yyyzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 894);

    auto g_0_yyyzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 895);

    auto g_0_yyyzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 896);

    auto g_0_yyyzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 897);

    auto g_0_yyyzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 898);

    auto g_0_yyyzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 899);

    auto g_0_yyzzzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 900);

    auto g_0_yyzzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 901);

    auto g_0_yyzzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 902);

    auto g_0_yyzzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 903);

    auto g_0_yyzzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 904);

    auto g_0_yyzzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 905);

    auto g_0_yyzzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 906);

    auto g_0_yyzzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 907);

    auto g_0_yyzzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 908);

    auto g_0_yyzzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 909);

    auto g_0_yyzzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 910);

    auto g_0_yyzzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 911);

    auto g_0_yyzzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 912);

    auto g_0_yyzzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 913);

    auto g_0_yyzzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 914);

    auto g_0_yyzzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 915);

    auto g_0_yyzzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 916);

    auto g_0_yyzzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 917);

    auto g_0_yyzzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 918);

    auto g_0_yyzzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 919);

    auto g_0_yyzzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 920);

    auto g_0_yyzzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 921);

    auto g_0_yyzzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 922);

    auto g_0_yyzzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 923);

    auto g_0_yyzzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 924);

    auto g_0_yyzzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 925);

    auto g_0_yyzzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 926);

    auto g_0_yyzzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 927);

    auto g_0_yyzzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 928);

    auto g_0_yyzzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 929);

    auto g_0_yyzzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 930);

    auto g_0_yyzzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 931);

    auto g_0_yyzzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 932);

    auto g_0_yyzzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 933);

    auto g_0_yyzzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 934);

    auto g_0_yyzzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 935);

    auto g_0_yzzzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 937);

    auto g_0_yzzzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 938);

    auto g_0_yzzzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 939);

    auto g_0_yzzzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 940);

    auto g_0_yzzzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 941);

    auto g_0_yzzzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 942);

    auto g_0_yzzzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 943);

    auto g_0_yzzzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 944);

    auto g_0_yzzzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 945);

    auto g_0_yzzzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 946);

    auto g_0_yzzzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 947);

    auto g_0_yzzzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 948);

    auto g_0_yzzzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 949);

    auto g_0_yzzzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 950);

    auto g_0_yzzzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 951);

    auto g_0_yzzzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 952);

    auto g_0_yzzzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 953);

    auto g_0_yzzzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 954);

    auto g_0_yzzzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 955);

    auto g_0_yzzzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 956);

    auto g_0_yzzzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 957);

    auto g_0_yzzzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 958);

    auto g_0_yzzzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 959);

    auto g_0_yzzzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 960);

    auto g_0_yzzzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 961);

    auto g_0_yzzzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 962);

    auto g_0_yzzzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 963);

    auto g_0_yzzzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 964);

    auto g_0_yzzzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 965);

    auto g_0_yzzzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 966);

    auto g_0_yzzzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 967);

    auto g_0_yzzzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 968);

    auto g_0_yzzzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 969);

    auto g_0_yzzzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 970);

    auto g_0_yzzzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 971);

    auto g_0_zzzzzz_0_xxxxxxx_1 = pbuffer.data(idx_eri_1_sisk + 972);

    auto g_0_zzzzzz_0_xxxxxxy_1 = pbuffer.data(idx_eri_1_sisk + 973);

    auto g_0_zzzzzz_0_xxxxxxz_1 = pbuffer.data(idx_eri_1_sisk + 974);

    auto g_0_zzzzzz_0_xxxxxyy_1 = pbuffer.data(idx_eri_1_sisk + 975);

    auto g_0_zzzzzz_0_xxxxxyz_1 = pbuffer.data(idx_eri_1_sisk + 976);

    auto g_0_zzzzzz_0_xxxxxzz_1 = pbuffer.data(idx_eri_1_sisk + 977);

    auto g_0_zzzzzz_0_xxxxyyy_1 = pbuffer.data(idx_eri_1_sisk + 978);

    auto g_0_zzzzzz_0_xxxxyyz_1 = pbuffer.data(idx_eri_1_sisk + 979);

    auto g_0_zzzzzz_0_xxxxyzz_1 = pbuffer.data(idx_eri_1_sisk + 980);

    auto g_0_zzzzzz_0_xxxxzzz_1 = pbuffer.data(idx_eri_1_sisk + 981);

    auto g_0_zzzzzz_0_xxxyyyy_1 = pbuffer.data(idx_eri_1_sisk + 982);

    auto g_0_zzzzzz_0_xxxyyyz_1 = pbuffer.data(idx_eri_1_sisk + 983);

    auto g_0_zzzzzz_0_xxxyyzz_1 = pbuffer.data(idx_eri_1_sisk + 984);

    auto g_0_zzzzzz_0_xxxyzzz_1 = pbuffer.data(idx_eri_1_sisk + 985);

    auto g_0_zzzzzz_0_xxxzzzz_1 = pbuffer.data(idx_eri_1_sisk + 986);

    auto g_0_zzzzzz_0_xxyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 987);

    auto g_0_zzzzzz_0_xxyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 988);

    auto g_0_zzzzzz_0_xxyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 989);

    auto g_0_zzzzzz_0_xxyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 990);

    auto g_0_zzzzzz_0_xxyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 991);

    auto g_0_zzzzzz_0_xxzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 992);

    auto g_0_zzzzzz_0_xyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 993);

    auto g_0_zzzzzz_0_xyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 994);

    auto g_0_zzzzzz_0_xyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 995);

    auto g_0_zzzzzz_0_xyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 996);

    auto g_0_zzzzzz_0_xyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 997);

    auto g_0_zzzzzz_0_xyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 998);

    auto g_0_zzzzzz_0_xzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 999);

    auto g_0_zzzzzz_0_yyyyyyy_1 = pbuffer.data(idx_eri_1_sisk + 1000);

    auto g_0_zzzzzz_0_yyyyyyz_1 = pbuffer.data(idx_eri_1_sisk + 1001);

    auto g_0_zzzzzz_0_yyyyyzz_1 = pbuffer.data(idx_eri_1_sisk + 1002);

    auto g_0_zzzzzz_0_yyyyzzz_1 = pbuffer.data(idx_eri_1_sisk + 1003);

    auto g_0_zzzzzz_0_yyyzzzz_1 = pbuffer.data(idx_eri_1_sisk + 1004);

    auto g_0_zzzzzz_0_yyzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 1005);

    auto g_0_zzzzzz_0_yzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 1006);

    auto g_0_zzzzzz_0_zzzzzzz_1 = pbuffer.data(idx_eri_1_sisk + 1007);

    /// Set up components of auxilary buffer : SISL

    auto g_0_xxxxxx_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl);

    auto g_0_xxxxxx_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1);

    auto g_0_xxxxxx_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 2);

    auto g_0_xxxxxx_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 3);

    auto g_0_xxxxxx_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 4);

    auto g_0_xxxxxx_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 5);

    auto g_0_xxxxxx_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 6);

    auto g_0_xxxxxx_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 7);

    auto g_0_xxxxxx_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 8);

    auto g_0_xxxxxx_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 9);

    auto g_0_xxxxxx_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 10);

    auto g_0_xxxxxx_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 11);

    auto g_0_xxxxxx_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 12);

    auto g_0_xxxxxx_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 13);

    auto g_0_xxxxxx_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 14);

    auto g_0_xxxxxx_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 15);

    auto g_0_xxxxxx_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 16);

    auto g_0_xxxxxx_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 17);

    auto g_0_xxxxxx_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 18);

    auto g_0_xxxxxx_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 19);

    auto g_0_xxxxxx_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 20);

    auto g_0_xxxxxx_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 21);

    auto g_0_xxxxxx_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 22);

    auto g_0_xxxxxx_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 23);

    auto g_0_xxxxxx_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 24);

    auto g_0_xxxxxx_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 25);

    auto g_0_xxxxxx_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 26);

    auto g_0_xxxxxx_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 27);

    auto g_0_xxxxxx_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 28);

    auto g_0_xxxxxx_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 29);

    auto g_0_xxxxxx_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 30);

    auto g_0_xxxxxx_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 31);

    auto g_0_xxxxxx_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 32);

    auto g_0_xxxxxx_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 33);

    auto g_0_xxxxxx_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 34);

    auto g_0_xxxxxx_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 35);

    auto g_0_xxxxxx_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 36);

    auto g_0_xxxxxx_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 37);

    auto g_0_xxxxxx_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 38);

    auto g_0_xxxxxx_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 39);

    auto g_0_xxxxxx_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 40);

    auto g_0_xxxxxx_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 41);

    auto g_0_xxxxxx_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 42);

    auto g_0_xxxxxx_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 43);

    auto g_0_xxxxxx_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 44);

    auto g_0_xxxxxy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 45);

    auto g_0_xxxxxy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 46);

    auto g_0_xxxxxy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 47);

    auto g_0_xxxxxy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 48);

    auto g_0_xxxxxy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 50);

    auto g_0_xxxxxy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 51);

    auto g_0_xxxxxy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 54);

    auto g_0_xxxxxy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 55);

    auto g_0_xxxxxy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 59);

    auto g_0_xxxxxy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 60);

    auto g_0_xxxxxy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 65);

    auto g_0_xxxxxy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 66);

    auto g_0_xxxxxy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 72);

    auto g_0_xxxxxy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 73);

    auto g_0_xxxxxy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 80);

    auto g_0_xxxxxy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 81);

    auto g_0_xxxxxz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 90);

    auto g_0_xxxxxz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 91);

    auto g_0_xxxxxz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 92);

    auto g_0_xxxxxz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 93);

    auto g_0_xxxxxz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 94);

    auto g_0_xxxxxz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 95);

    auto g_0_xxxxxz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 96);

    auto g_0_xxxxxz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 97);

    auto g_0_xxxxxz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 98);

    auto g_0_xxxxxz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 99);

    auto g_0_xxxxxz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 100);

    auto g_0_xxxxxz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 101);

    auto g_0_xxxxxz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 102);

    auto g_0_xxxxxz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 103);

    auto g_0_xxxxxz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 104);

    auto g_0_xxxxxz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 105);

    auto g_0_xxxxxz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 106);

    auto g_0_xxxxxz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 107);

    auto g_0_xxxxxz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 108);

    auto g_0_xxxxxz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 109);

    auto g_0_xxxxxz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 110);

    auto g_0_xxxxxz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 111);

    auto g_0_xxxxxz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 112);

    auto g_0_xxxxxz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 113);

    auto g_0_xxxxxz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 114);

    auto g_0_xxxxxz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 115);

    auto g_0_xxxxxz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 116);

    auto g_0_xxxxxz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 117);

    auto g_0_xxxxxz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 118);

    auto g_0_xxxxxz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 119);

    auto g_0_xxxxxz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 120);

    auto g_0_xxxxxz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 121);

    auto g_0_xxxxxz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 122);

    auto g_0_xxxxxz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 123);

    auto g_0_xxxxxz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 124);

    auto g_0_xxxxxz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 125);

    auto g_0_xxxxxz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 127);

    auto g_0_xxxxxz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 128);

    auto g_0_xxxxxz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 129);

    auto g_0_xxxxxz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 130);

    auto g_0_xxxxxz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 131);

    auto g_0_xxxxxz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 132);

    auto g_0_xxxxxz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 133);

    auto g_0_xxxxxz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 134);

    auto g_0_xxxxyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 135);

    auto g_0_xxxxyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 136);

    auto g_0_xxxxyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 137);

    auto g_0_xxxxyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 138);

    auto g_0_xxxxyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 139);

    auto g_0_xxxxyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 140);

    auto g_0_xxxxyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 141);

    auto g_0_xxxxyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 142);

    auto g_0_xxxxyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 143);

    auto g_0_xxxxyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 144);

    auto g_0_xxxxyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 145);

    auto g_0_xxxxyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 146);

    auto g_0_xxxxyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 147);

    auto g_0_xxxxyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 148);

    auto g_0_xxxxyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 149);

    auto g_0_xxxxyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 150);

    auto g_0_xxxxyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 151);

    auto g_0_xxxxyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 152);

    auto g_0_xxxxyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 153);

    auto g_0_xxxxyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 154);

    auto g_0_xxxxyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 155);

    auto g_0_xxxxyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 156);

    auto g_0_xxxxyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 157);

    auto g_0_xxxxyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 158);

    auto g_0_xxxxyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 159);

    auto g_0_xxxxyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 160);

    auto g_0_xxxxyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 161);

    auto g_0_xxxxyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 162);

    auto g_0_xxxxyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 163);

    auto g_0_xxxxyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 164);

    auto g_0_xxxxyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 165);

    auto g_0_xxxxyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 166);

    auto g_0_xxxxyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 167);

    auto g_0_xxxxyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 168);

    auto g_0_xxxxyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 169);

    auto g_0_xxxxyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 170);

    auto g_0_xxxxyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 171);

    auto g_0_xxxxyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 172);

    auto g_0_xxxxyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 173);

    auto g_0_xxxxyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 174);

    auto g_0_xxxxyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 175);

    auto g_0_xxxxyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 176);

    auto g_0_xxxxyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 177);

    auto g_0_xxxxyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 178);

    auto g_0_xxxxyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 179);

    auto g_0_xxxxzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 225);

    auto g_0_xxxxzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 226);

    auto g_0_xxxxzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 227);

    auto g_0_xxxxzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 228);

    auto g_0_xxxxzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 229);

    auto g_0_xxxxzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 230);

    auto g_0_xxxxzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 231);

    auto g_0_xxxxzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 232);

    auto g_0_xxxxzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 233);

    auto g_0_xxxxzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 234);

    auto g_0_xxxxzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 235);

    auto g_0_xxxxzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 236);

    auto g_0_xxxxzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 237);

    auto g_0_xxxxzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 238);

    auto g_0_xxxxzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 239);

    auto g_0_xxxxzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 240);

    auto g_0_xxxxzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 241);

    auto g_0_xxxxzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 242);

    auto g_0_xxxxzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 243);

    auto g_0_xxxxzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 244);

    auto g_0_xxxxzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 245);

    auto g_0_xxxxzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 246);

    auto g_0_xxxxzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 247);

    auto g_0_xxxxzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 248);

    auto g_0_xxxxzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 249);

    auto g_0_xxxxzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 250);

    auto g_0_xxxxzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 251);

    auto g_0_xxxxzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 252);

    auto g_0_xxxxzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 253);

    auto g_0_xxxxzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 254);

    auto g_0_xxxxzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 255);

    auto g_0_xxxxzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 256);

    auto g_0_xxxxzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 257);

    auto g_0_xxxxzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 258);

    auto g_0_xxxxzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 259);

    auto g_0_xxxxzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 260);

    auto g_0_xxxxzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 261);

    auto g_0_xxxxzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 262);

    auto g_0_xxxxzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 263);

    auto g_0_xxxxzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 264);

    auto g_0_xxxxzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 265);

    auto g_0_xxxxzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 266);

    auto g_0_xxxxzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 267);

    auto g_0_xxxxzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 268);

    auto g_0_xxxxzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 269);

    auto g_0_xxxyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 270);

    auto g_0_xxxyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 271);

    auto g_0_xxxyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 272);

    auto g_0_xxxyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 273);

    auto g_0_xxxyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 274);

    auto g_0_xxxyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 275);

    auto g_0_xxxyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 276);

    auto g_0_xxxyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 277);

    auto g_0_xxxyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 278);

    auto g_0_xxxyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 279);

    auto g_0_xxxyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 280);

    auto g_0_xxxyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 281);

    auto g_0_xxxyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 282);

    auto g_0_xxxyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 283);

    auto g_0_xxxyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 284);

    auto g_0_xxxyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 285);

    auto g_0_xxxyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 286);

    auto g_0_xxxyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 287);

    auto g_0_xxxyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 288);

    auto g_0_xxxyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 289);

    auto g_0_xxxyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 290);

    auto g_0_xxxyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 291);

    auto g_0_xxxyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 292);

    auto g_0_xxxyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 293);

    auto g_0_xxxyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 294);

    auto g_0_xxxyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 295);

    auto g_0_xxxyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 296);

    auto g_0_xxxyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 297);

    auto g_0_xxxyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 298);

    auto g_0_xxxyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 299);

    auto g_0_xxxyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 300);

    auto g_0_xxxyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 301);

    auto g_0_xxxyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 302);

    auto g_0_xxxyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 303);

    auto g_0_xxxyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 304);

    auto g_0_xxxyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 305);

    auto g_0_xxxyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 306);

    auto g_0_xxxyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 307);

    auto g_0_xxxyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 308);

    auto g_0_xxxyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 309);

    auto g_0_xxxyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 310);

    auto g_0_xxxyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 311);

    auto g_0_xxxyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 312);

    auto g_0_xxxyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 313);

    auto g_0_xxxyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 314);

    auto g_0_xxxyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 316);

    auto g_0_xxxyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 318);

    auto g_0_xxxyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 321);

    auto g_0_xxxyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 325);

    auto g_0_xxxyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 330);

    auto g_0_xxxyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 336);

    auto g_0_xxxyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 343);

    auto g_0_xxxyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 360);

    auto g_0_xxxyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 362);

    auto g_0_xxxyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 365);

    auto g_0_xxxyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 369);

    auto g_0_xxxyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 374);

    auto g_0_xxxyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 380);

    auto g_0_xxxyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 387);

    auto g_0_xxxyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 395);

    auto g_0_xxxzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 405);

    auto g_0_xxxzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 406);

    auto g_0_xxxzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 407);

    auto g_0_xxxzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 408);

    auto g_0_xxxzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 409);

    auto g_0_xxxzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 410);

    auto g_0_xxxzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 411);

    auto g_0_xxxzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 412);

    auto g_0_xxxzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 413);

    auto g_0_xxxzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 414);

    auto g_0_xxxzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 415);

    auto g_0_xxxzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 416);

    auto g_0_xxxzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 417);

    auto g_0_xxxzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 418);

    auto g_0_xxxzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 419);

    auto g_0_xxxzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 420);

    auto g_0_xxxzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 421);

    auto g_0_xxxzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 422);

    auto g_0_xxxzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 423);

    auto g_0_xxxzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 424);

    auto g_0_xxxzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 425);

    auto g_0_xxxzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 426);

    auto g_0_xxxzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 427);

    auto g_0_xxxzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 428);

    auto g_0_xxxzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 429);

    auto g_0_xxxzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 430);

    auto g_0_xxxzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 431);

    auto g_0_xxxzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 432);

    auto g_0_xxxzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 433);

    auto g_0_xxxzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 434);

    auto g_0_xxxzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 435);

    auto g_0_xxxzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 436);

    auto g_0_xxxzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 437);

    auto g_0_xxxzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 438);

    auto g_0_xxxzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 439);

    auto g_0_xxxzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 440);

    auto g_0_xxxzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 441);

    auto g_0_xxxzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 442);

    auto g_0_xxxzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 443);

    auto g_0_xxxzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 444);

    auto g_0_xxxzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 445);

    auto g_0_xxxzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 446);

    auto g_0_xxxzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 447);

    auto g_0_xxxzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 448);

    auto g_0_xxxzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 449);

    auto g_0_xxyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 450);

    auto g_0_xxyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 451);

    auto g_0_xxyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 452);

    auto g_0_xxyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 453);

    auto g_0_xxyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 454);

    auto g_0_xxyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 455);

    auto g_0_xxyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 456);

    auto g_0_xxyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 457);

    auto g_0_xxyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 458);

    auto g_0_xxyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 459);

    auto g_0_xxyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 460);

    auto g_0_xxyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 461);

    auto g_0_xxyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 462);

    auto g_0_xxyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 463);

    auto g_0_xxyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 464);

    auto g_0_xxyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 465);

    auto g_0_xxyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 466);

    auto g_0_xxyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 467);

    auto g_0_xxyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 468);

    auto g_0_xxyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 469);

    auto g_0_xxyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 470);

    auto g_0_xxyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 471);

    auto g_0_xxyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 472);

    auto g_0_xxyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 473);

    auto g_0_xxyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 474);

    auto g_0_xxyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 475);

    auto g_0_xxyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 476);

    auto g_0_xxyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 477);

    auto g_0_xxyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 478);

    auto g_0_xxyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 479);

    auto g_0_xxyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 480);

    auto g_0_xxyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 481);

    auto g_0_xxyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 482);

    auto g_0_xxyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 483);

    auto g_0_xxyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 484);

    auto g_0_xxyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 485);

    auto g_0_xxyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 486);

    auto g_0_xxyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 487);

    auto g_0_xxyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 488);

    auto g_0_xxyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 489);

    auto g_0_xxyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 490);

    auto g_0_xxyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 491);

    auto g_0_xxyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 492);

    auto g_0_xxyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 493);

    auto g_0_xxyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 494);

    auto g_0_xxyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 496);

    auto g_0_xxyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 498);

    auto g_0_xxyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 501);

    auto g_0_xxyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 505);

    auto g_0_xxyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 510);

    auto g_0_xxyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 516);

    auto g_0_xxyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 523);

    auto g_0_xxyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 540);

    auto g_0_xxyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 541);

    auto g_0_xxyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 542);

    auto g_0_xxyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 543);

    auto g_0_xxyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 544);

    auto g_0_xxyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 545);

    auto g_0_xxyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 546);

    auto g_0_xxyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 547);

    auto g_0_xxyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 548);

    auto g_0_xxyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 549);

    auto g_0_xxyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 550);

    auto g_0_xxyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 551);

    auto g_0_xxyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 552);

    auto g_0_xxyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 553);

    auto g_0_xxyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 554);

    auto g_0_xxyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 555);

    auto g_0_xxyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 556);

    auto g_0_xxyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 557);

    auto g_0_xxyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 558);

    auto g_0_xxyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 559);

    auto g_0_xxyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 560);

    auto g_0_xxyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 561);

    auto g_0_xxyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 562);

    auto g_0_xxyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 563);

    auto g_0_xxyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 564);

    auto g_0_xxyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 565);

    auto g_0_xxyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 566);

    auto g_0_xxyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 567);

    auto g_0_xxyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 568);

    auto g_0_xxyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 569);

    auto g_0_xxyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 570);

    auto g_0_xxyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 571);

    auto g_0_xxyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 572);

    auto g_0_xxyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 573);

    auto g_0_xxyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 574);

    auto g_0_xxyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 575);

    auto g_0_xxyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 576);

    auto g_0_xxyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 577);

    auto g_0_xxyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 578);

    auto g_0_xxyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 579);

    auto g_0_xxyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 580);

    auto g_0_xxyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 581);

    auto g_0_xxyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 582);

    auto g_0_xxyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 583);

    auto g_0_xxyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 584);

    auto g_0_xxyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 585);

    auto g_0_xxyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 587);

    auto g_0_xxyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 590);

    auto g_0_xxyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 594);

    auto g_0_xxyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 599);

    auto g_0_xxyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 605);

    auto g_0_xxyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 612);

    auto g_0_xxyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 620);

    auto g_0_xxzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 630);

    auto g_0_xxzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 631);

    auto g_0_xxzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 632);

    auto g_0_xxzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 633);

    auto g_0_xxzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 634);

    auto g_0_xxzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 635);

    auto g_0_xxzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 636);

    auto g_0_xxzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 637);

    auto g_0_xxzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 638);

    auto g_0_xxzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 639);

    auto g_0_xxzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 640);

    auto g_0_xxzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 641);

    auto g_0_xxzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 642);

    auto g_0_xxzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 643);

    auto g_0_xxzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 644);

    auto g_0_xxzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 645);

    auto g_0_xxzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 646);

    auto g_0_xxzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 647);

    auto g_0_xxzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 648);

    auto g_0_xxzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 649);

    auto g_0_xxzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 650);

    auto g_0_xxzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 651);

    auto g_0_xxzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 652);

    auto g_0_xxzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 653);

    auto g_0_xxzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 654);

    auto g_0_xxzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 655);

    auto g_0_xxzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 656);

    auto g_0_xxzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 657);

    auto g_0_xxzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 658);

    auto g_0_xxzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 659);

    auto g_0_xxzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 660);

    auto g_0_xxzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 661);

    auto g_0_xxzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 662);

    auto g_0_xxzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 663);

    auto g_0_xxzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 664);

    auto g_0_xxzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 665);

    auto g_0_xxzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 666);

    auto g_0_xxzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 667);

    auto g_0_xxzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 668);

    auto g_0_xxzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 669);

    auto g_0_xxzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 670);

    auto g_0_xxzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 671);

    auto g_0_xxzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 672);

    auto g_0_xxzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 673);

    auto g_0_xxzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 674);

    auto g_0_xyyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 675);

    auto g_0_xyyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 676);

    auto g_0_xyyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 678);

    auto g_0_xyyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 679);

    auto g_0_xyyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 681);

    auto g_0_xyyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 682);

    auto g_0_xyyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 683);

    auto g_0_xyyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 685);

    auto g_0_xyyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 686);

    auto g_0_xyyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 687);

    auto g_0_xyyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 688);

    auto g_0_xyyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 690);

    auto g_0_xyyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 691);

    auto g_0_xyyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 692);

    auto g_0_xyyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 693);

    auto g_0_xyyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 694);

    auto g_0_xyyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 696);

    auto g_0_xyyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 697);

    auto g_0_xyyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 698);

    auto g_0_xyyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 699);

    auto g_0_xyyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 700);

    auto g_0_xyyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 701);

    auto g_0_xyyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 703);

    auto g_0_xyyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 704);

    auto g_0_xyyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 705);

    auto g_0_xyyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 706);

    auto g_0_xyyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 707);

    auto g_0_xyyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 708);

    auto g_0_xyyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 709);

    auto g_0_xyyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 711);

    auto g_0_xyyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 712);

    auto g_0_xyyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 713);

    auto g_0_xyyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 714);

    auto g_0_xyyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 715);

    auto g_0_xyyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 716);

    auto g_0_xyyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 717);

    auto g_0_xyyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 718);

    auto g_0_xyyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 719);

    auto g_0_xyyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 769);

    auto g_0_xyyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 772);

    auto g_0_xyyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 773);

    auto g_0_xyyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 776);

    auto g_0_xyyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 777);

    auto g_0_xyyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 778);

    auto g_0_xyyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 781);

    auto g_0_xyyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 782);

    auto g_0_xyyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 783);

    auto g_0_xyyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 784);

    auto g_0_xyyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 787);

    auto g_0_xyyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 788);

    auto g_0_xyyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 789);

    auto g_0_xyyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 790);

    auto g_0_xyyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 791);

    auto g_0_xyyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 794);

    auto g_0_xyyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 795);

    auto g_0_xyyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 796);

    auto g_0_xyyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 797);

    auto g_0_xyyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 798);

    auto g_0_xyyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 799);

    auto g_0_xyyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 801);

    auto g_0_xyyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 802);

    auto g_0_xyyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 803);

    auto g_0_xyyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 804);

    auto g_0_xyyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 805);

    auto g_0_xyyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 806);

    auto g_0_xyyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 807);

    auto g_0_xyyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 808);

    auto g_0_xyyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 809);

    auto g_0_xyyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 814);

    auto g_0_xyyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 817);

    auto g_0_xyyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 818);

    auto g_0_xyyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 821);

    auto g_0_xyyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 822);

    auto g_0_xyyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 823);

    auto g_0_xyyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 826);

    auto g_0_xyyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 827);

    auto g_0_xyyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 828);

    auto g_0_xyyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 829);

    auto g_0_xyyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 832);

    auto g_0_xyyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 833);

    auto g_0_xyyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 834);

    auto g_0_xyyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 835);

    auto g_0_xyyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 836);

    auto g_0_xyyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 839);

    auto g_0_xyyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 840);

    auto g_0_xyyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 841);

    auto g_0_xyyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 842);

    auto g_0_xyyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 843);

    auto g_0_xyyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 844);

    auto g_0_xyyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 846);

    auto g_0_xyyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 847);

    auto g_0_xyyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 848);

    auto g_0_xyyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 849);

    auto g_0_xyyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 850);

    auto g_0_xyyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 851);

    auto g_0_xyyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 852);

    auto g_0_xyyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 853);

    auto g_0_xyyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 854);

    auto g_0_xzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 900);

    auto g_0_xzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 902);

    auto g_0_xzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 904);

    auto g_0_xzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 905);

    auto g_0_xzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 907);

    auto g_0_xzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 908);

    auto g_0_xzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 909);

    auto g_0_xzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 911);

    auto g_0_xzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 912);

    auto g_0_xzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 913);

    auto g_0_xzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 914);

    auto g_0_xzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 916);

    auto g_0_xzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 917);

    auto g_0_xzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 918);

    auto g_0_xzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 919);

    auto g_0_xzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 920);

    auto g_0_xzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 922);

    auto g_0_xzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 923);

    auto g_0_xzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 924);

    auto g_0_xzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 925);

    auto g_0_xzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 926);

    auto g_0_xzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 927);

    auto g_0_xzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 929);

    auto g_0_xzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 930);

    auto g_0_xzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 931);

    auto g_0_xzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 932);

    auto g_0_xzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 933);

    auto g_0_xzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 934);

    auto g_0_xzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 935);

    auto g_0_xzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 936);

    auto g_0_xzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 937);

    auto g_0_xzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 938);

    auto g_0_xzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 939);

    auto g_0_xzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 940);

    auto g_0_xzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 941);

    auto g_0_xzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 942);

    auto g_0_xzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 943);

    auto g_0_xzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 944);

    auto g_0_yyyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 945);

    auto g_0_yyyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 946);

    auto g_0_yyyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 947);

    auto g_0_yyyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 948);

    auto g_0_yyyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 949);

    auto g_0_yyyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 950);

    auto g_0_yyyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 951);

    auto g_0_yyyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 952);

    auto g_0_yyyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 953);

    auto g_0_yyyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 954);

    auto g_0_yyyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 955);

    auto g_0_yyyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 956);

    auto g_0_yyyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 957);

    auto g_0_yyyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 958);

    auto g_0_yyyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 959);

    auto g_0_yyyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 960);

    auto g_0_yyyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 961);

    auto g_0_yyyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 962);

    auto g_0_yyyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 963);

    auto g_0_yyyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 964);

    auto g_0_yyyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 965);

    auto g_0_yyyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 966);

    auto g_0_yyyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 967);

    auto g_0_yyyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 968);

    auto g_0_yyyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 969);

    auto g_0_yyyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 970);

    auto g_0_yyyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 971);

    auto g_0_yyyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 972);

    auto g_0_yyyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 973);

    auto g_0_yyyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 974);

    auto g_0_yyyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 975);

    auto g_0_yyyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 976);

    auto g_0_yyyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 977);

    auto g_0_yyyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 978);

    auto g_0_yyyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 979);

    auto g_0_yyyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 980);

    auto g_0_yyyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 981);

    auto g_0_yyyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 982);

    auto g_0_yyyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 983);

    auto g_0_yyyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 984);

    auto g_0_yyyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 985);

    auto g_0_yyyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 986);

    auto g_0_yyyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 987);

    auto g_0_yyyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 988);

    auto g_0_yyyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 989);

    auto g_0_yyyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 991);

    auto g_0_yyyyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 992);

    auto g_0_yyyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 993);

    auto g_0_yyyyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 994);

    auto g_0_yyyyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 995);

    auto g_0_yyyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 996);

    auto g_0_yyyyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 997);

    auto g_0_yyyyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 998);

    auto g_0_yyyyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 999);

    auto g_0_yyyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1000);

    auto g_0_yyyyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1001);

    auto g_0_yyyyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1002);

    auto g_0_yyyyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1003);

    auto g_0_yyyyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1004);

    auto g_0_yyyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1005);

    auto g_0_yyyyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1006);

    auto g_0_yyyyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1007);

    auto g_0_yyyyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1008);

    auto g_0_yyyyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1009);

    auto g_0_yyyyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1010);

    auto g_0_yyyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1011);

    auto g_0_yyyyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1012);

    auto g_0_yyyyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1013);

    auto g_0_yyyyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1014);

    auto g_0_yyyyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1015);

    auto g_0_yyyyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1016);

    auto g_0_yyyyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1017);

    auto g_0_yyyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1018);

    auto g_0_yyyyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1019);

    auto g_0_yyyyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1020);

    auto g_0_yyyyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1021);

    auto g_0_yyyyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1022);

    auto g_0_yyyyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1023);

    auto g_0_yyyyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1024);

    auto g_0_yyyyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1025);

    auto g_0_yyyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1026);

    auto g_0_yyyyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1027);

    auto g_0_yyyyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1028);

    auto g_0_yyyyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1029);

    auto g_0_yyyyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1030);

    auto g_0_yyyyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1031);

    auto g_0_yyyyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1032);

    auto g_0_yyyyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1033);

    auto g_0_yyyyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1034);

    auto g_0_yyyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 1035);

    auto g_0_yyyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1036);

    auto g_0_yyyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 1037);

    auto g_0_yyyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 1038);

    auto g_0_yyyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 1039);

    auto g_0_yyyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 1040);

    auto g_0_yyyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 1041);

    auto g_0_yyyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 1042);

    auto g_0_yyyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 1043);

    auto g_0_yyyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 1044);

    auto g_0_yyyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1045);

    auto g_0_yyyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1046);

    auto g_0_yyyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1047);

    auto g_0_yyyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1048);

    auto g_0_yyyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1049);

    auto g_0_yyyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1050);

    auto g_0_yyyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1051);

    auto g_0_yyyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1052);

    auto g_0_yyyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1053);

    auto g_0_yyyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1054);

    auto g_0_yyyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1055);

    auto g_0_yyyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1056);

    auto g_0_yyyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1057);

    auto g_0_yyyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1058);

    auto g_0_yyyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1059);

    auto g_0_yyyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1060);

    auto g_0_yyyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1061);

    auto g_0_yyyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1062);

    auto g_0_yyyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1063);

    auto g_0_yyyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1064);

    auto g_0_yyyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1065);

    auto g_0_yyyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1066);

    auto g_0_yyyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1067);

    auto g_0_yyyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1068);

    auto g_0_yyyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1069);

    auto g_0_yyyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1070);

    auto g_0_yyyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1071);

    auto g_0_yyyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1072);

    auto g_0_yyyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1073);

    auto g_0_yyyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1074);

    auto g_0_yyyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1075);

    auto g_0_yyyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1076);

    auto g_0_yyyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1077);

    auto g_0_yyyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1078);

    auto g_0_yyyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1079);

    auto g_0_yyyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 1080);

    auto g_0_yyyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1081);

    auto g_0_yyyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 1082);

    auto g_0_yyyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 1083);

    auto g_0_yyyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 1084);

    auto g_0_yyyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 1085);

    auto g_0_yyyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 1086);

    auto g_0_yyyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 1087);

    auto g_0_yyyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 1088);

    auto g_0_yyyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 1089);

    auto g_0_yyyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1090);

    auto g_0_yyyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1091);

    auto g_0_yyyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1092);

    auto g_0_yyyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1093);

    auto g_0_yyyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1094);

    auto g_0_yyyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1095);

    auto g_0_yyyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1096);

    auto g_0_yyyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1097);

    auto g_0_yyyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1098);

    auto g_0_yyyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1099);

    auto g_0_yyyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1100);

    auto g_0_yyyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1101);

    auto g_0_yyyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1102);

    auto g_0_yyyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1103);

    auto g_0_yyyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1104);

    auto g_0_yyyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1105);

    auto g_0_yyyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1106);

    auto g_0_yyyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1107);

    auto g_0_yyyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1108);

    auto g_0_yyyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1109);

    auto g_0_yyyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1110);

    auto g_0_yyyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1111);

    auto g_0_yyyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1112);

    auto g_0_yyyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1113);

    auto g_0_yyyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1114);

    auto g_0_yyyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1115);

    auto g_0_yyyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1116);

    auto g_0_yyyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1117);

    auto g_0_yyyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1118);

    auto g_0_yyyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1119);

    auto g_0_yyyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1120);

    auto g_0_yyyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1121);

    auto g_0_yyyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1122);

    auto g_0_yyyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1123);

    auto g_0_yyyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1124);

    auto g_0_yyzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 1125);

    auto g_0_yyzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1126);

    auto g_0_yyzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 1127);

    auto g_0_yyzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 1128);

    auto g_0_yyzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 1129);

    auto g_0_yyzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 1130);

    auto g_0_yyzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 1131);

    auto g_0_yyzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 1132);

    auto g_0_yyzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 1133);

    auto g_0_yyzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 1134);

    auto g_0_yyzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1135);

    auto g_0_yyzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1136);

    auto g_0_yyzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1137);

    auto g_0_yyzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1138);

    auto g_0_yyzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1139);

    auto g_0_yyzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1140);

    auto g_0_yyzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1141);

    auto g_0_yyzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1142);

    auto g_0_yyzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1143);

    auto g_0_yyzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1144);

    auto g_0_yyzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1145);

    auto g_0_yyzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1146);

    auto g_0_yyzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1147);

    auto g_0_yyzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1148);

    auto g_0_yyzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1149);

    auto g_0_yyzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1150);

    auto g_0_yyzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1151);

    auto g_0_yyzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1152);

    auto g_0_yyzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1153);

    auto g_0_yyzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1154);

    auto g_0_yyzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1155);

    auto g_0_yyzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1156);

    auto g_0_yyzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1157);

    auto g_0_yyzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1158);

    auto g_0_yyzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1159);

    auto g_0_yyzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1160);

    auto g_0_yyzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1161);

    auto g_0_yyzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1162);

    auto g_0_yyzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1163);

    auto g_0_yyzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1164);

    auto g_0_yyzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1165);

    auto g_0_yyzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1166);

    auto g_0_yyzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1167);

    auto g_0_yyzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1168);

    auto g_0_yyzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1169);

    auto g_0_yzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 1170);

    auto g_0_yzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1171);

    auto g_0_yzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 1172);

    auto g_0_yzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 1173);

    auto g_0_yzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 1174);

    auto g_0_yzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 1175);

    auto g_0_yzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 1176);

    auto g_0_yzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 1177);

    auto g_0_yzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 1178);

    auto g_0_yzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 1179);

    auto g_0_yzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1180);

    auto g_0_yzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1181);

    auto g_0_yzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1182);

    auto g_0_yzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1183);

    auto g_0_yzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1184);

    auto g_0_yzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1185);

    auto g_0_yzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1186);

    auto g_0_yzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1187);

    auto g_0_yzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1188);

    auto g_0_yzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1189);

    auto g_0_yzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1190);

    auto g_0_yzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1191);

    auto g_0_yzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1192);

    auto g_0_yzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1193);

    auto g_0_yzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1194);

    auto g_0_yzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1195);

    auto g_0_yzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1196);

    auto g_0_yzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1197);

    auto g_0_yzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1198);

    auto g_0_yzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1199);

    auto g_0_yzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1200);

    auto g_0_yzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1201);

    auto g_0_yzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1202);

    auto g_0_yzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1203);

    auto g_0_yzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1204);

    auto g_0_yzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1205);

    auto g_0_yzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1206);

    auto g_0_yzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1207);

    auto g_0_yzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1208);

    auto g_0_yzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1209);

    auto g_0_yzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1210);

    auto g_0_yzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1211);

    auto g_0_yzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1212);

    auto g_0_yzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1213);

    auto g_0_yzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1214);

    auto g_0_zzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sisl + 1215);

    auto g_0_zzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sisl + 1216);

    auto g_0_zzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sisl + 1217);

    auto g_0_zzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sisl + 1218);

    auto g_0_zzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sisl + 1219);

    auto g_0_zzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sisl + 1220);

    auto g_0_zzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sisl + 1221);

    auto g_0_zzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sisl + 1222);

    auto g_0_zzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sisl + 1223);

    auto g_0_zzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sisl + 1224);

    auto g_0_zzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1225);

    auto g_0_zzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1226);

    auto g_0_zzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1227);

    auto g_0_zzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1228);

    auto g_0_zzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1229);

    auto g_0_zzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1230);

    auto g_0_zzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1231);

    auto g_0_zzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1232);

    auto g_0_zzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1233);

    auto g_0_zzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1234);

    auto g_0_zzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1235);

    auto g_0_zzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1236);

    auto g_0_zzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1237);

    auto g_0_zzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1238);

    auto g_0_zzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1239);

    auto g_0_zzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1240);

    auto g_0_zzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1241);

    auto g_0_zzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1242);

    auto g_0_zzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1243);

    auto g_0_zzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1244);

    auto g_0_zzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1245);

    auto g_0_zzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1246);

    auto g_0_zzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1247);

    auto g_0_zzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1248);

    auto g_0_zzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1249);

    auto g_0_zzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1250);

    auto g_0_zzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sisl + 1251);

    auto g_0_zzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sisl + 1252);

    auto g_0_zzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sisl + 1253);

    auto g_0_zzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sisl + 1254);

    auto g_0_zzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1255);

    auto g_0_zzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1256);

    auto g_0_zzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1257);

    auto g_0_zzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1258);

    auto g_0_zzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sisl + 1259);

    /// Set up components of auxilary buffer : SISL

    auto g_0_xxxxxx_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl);

    auto g_0_xxxxxx_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1);

    auto g_0_xxxxxx_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 2);

    auto g_0_xxxxxx_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 3);

    auto g_0_xxxxxx_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 4);

    auto g_0_xxxxxx_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 5);

    auto g_0_xxxxxx_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 6);

    auto g_0_xxxxxx_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 7);

    auto g_0_xxxxxx_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 8);

    auto g_0_xxxxxx_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 9);

    auto g_0_xxxxxx_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 10);

    auto g_0_xxxxxx_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 11);

    auto g_0_xxxxxx_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 12);

    auto g_0_xxxxxx_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 13);

    auto g_0_xxxxxx_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 14);

    auto g_0_xxxxxx_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 15);

    auto g_0_xxxxxx_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 16);

    auto g_0_xxxxxx_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 17);

    auto g_0_xxxxxx_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 18);

    auto g_0_xxxxxx_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 19);

    auto g_0_xxxxxx_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 20);

    auto g_0_xxxxxx_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 21);

    auto g_0_xxxxxx_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 22);

    auto g_0_xxxxxx_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 23);

    auto g_0_xxxxxx_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 24);

    auto g_0_xxxxxx_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 25);

    auto g_0_xxxxxx_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 26);

    auto g_0_xxxxxx_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 27);

    auto g_0_xxxxxx_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 28);

    auto g_0_xxxxxx_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 29);

    auto g_0_xxxxxx_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 30);

    auto g_0_xxxxxx_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 31);

    auto g_0_xxxxxx_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 32);

    auto g_0_xxxxxx_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 33);

    auto g_0_xxxxxx_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 34);

    auto g_0_xxxxxx_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 35);

    auto g_0_xxxxxx_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 36);

    auto g_0_xxxxxx_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 37);

    auto g_0_xxxxxx_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 38);

    auto g_0_xxxxxx_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 39);

    auto g_0_xxxxxx_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 40);

    auto g_0_xxxxxx_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 41);

    auto g_0_xxxxxx_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 42);

    auto g_0_xxxxxx_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 43);

    auto g_0_xxxxxx_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 44);

    auto g_0_xxxxxy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 45);

    auto g_0_xxxxxy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 46);

    auto g_0_xxxxxy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 47);

    auto g_0_xxxxxy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 48);

    auto g_0_xxxxxy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 50);

    auto g_0_xxxxxy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 51);

    auto g_0_xxxxxy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 54);

    auto g_0_xxxxxy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 55);

    auto g_0_xxxxxy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 59);

    auto g_0_xxxxxy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 60);

    auto g_0_xxxxxy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 65);

    auto g_0_xxxxxy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 66);

    auto g_0_xxxxxy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 72);

    auto g_0_xxxxxy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 73);

    auto g_0_xxxxxy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 80);

    auto g_0_xxxxxy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 81);

    auto g_0_xxxxxz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 90);

    auto g_0_xxxxxz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 91);

    auto g_0_xxxxxz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 92);

    auto g_0_xxxxxz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 93);

    auto g_0_xxxxxz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 94);

    auto g_0_xxxxxz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 95);

    auto g_0_xxxxxz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 96);

    auto g_0_xxxxxz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 97);

    auto g_0_xxxxxz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 98);

    auto g_0_xxxxxz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 99);

    auto g_0_xxxxxz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 100);

    auto g_0_xxxxxz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 101);

    auto g_0_xxxxxz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 102);

    auto g_0_xxxxxz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 103);

    auto g_0_xxxxxz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 104);

    auto g_0_xxxxxz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 105);

    auto g_0_xxxxxz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 106);

    auto g_0_xxxxxz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 107);

    auto g_0_xxxxxz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 108);

    auto g_0_xxxxxz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 109);

    auto g_0_xxxxxz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 110);

    auto g_0_xxxxxz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 111);

    auto g_0_xxxxxz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 112);

    auto g_0_xxxxxz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 113);

    auto g_0_xxxxxz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 114);

    auto g_0_xxxxxz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 115);

    auto g_0_xxxxxz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 116);

    auto g_0_xxxxxz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 117);

    auto g_0_xxxxxz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 118);

    auto g_0_xxxxxz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 119);

    auto g_0_xxxxxz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 120);

    auto g_0_xxxxxz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 121);

    auto g_0_xxxxxz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 122);

    auto g_0_xxxxxz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 123);

    auto g_0_xxxxxz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 124);

    auto g_0_xxxxxz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 125);

    auto g_0_xxxxxz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 127);

    auto g_0_xxxxxz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 128);

    auto g_0_xxxxxz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 129);

    auto g_0_xxxxxz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 130);

    auto g_0_xxxxxz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 131);

    auto g_0_xxxxxz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 132);

    auto g_0_xxxxxz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 133);

    auto g_0_xxxxxz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 134);

    auto g_0_xxxxyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 135);

    auto g_0_xxxxyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 136);

    auto g_0_xxxxyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 137);

    auto g_0_xxxxyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 138);

    auto g_0_xxxxyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 139);

    auto g_0_xxxxyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 140);

    auto g_0_xxxxyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 141);

    auto g_0_xxxxyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 142);

    auto g_0_xxxxyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 143);

    auto g_0_xxxxyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 144);

    auto g_0_xxxxyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 145);

    auto g_0_xxxxyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 146);

    auto g_0_xxxxyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 147);

    auto g_0_xxxxyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 148);

    auto g_0_xxxxyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 149);

    auto g_0_xxxxyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 150);

    auto g_0_xxxxyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 151);

    auto g_0_xxxxyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 152);

    auto g_0_xxxxyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 153);

    auto g_0_xxxxyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 154);

    auto g_0_xxxxyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 155);

    auto g_0_xxxxyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 156);

    auto g_0_xxxxyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 157);

    auto g_0_xxxxyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 158);

    auto g_0_xxxxyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 159);

    auto g_0_xxxxyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 160);

    auto g_0_xxxxyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 161);

    auto g_0_xxxxyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 162);

    auto g_0_xxxxyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 163);

    auto g_0_xxxxyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 164);

    auto g_0_xxxxyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 165);

    auto g_0_xxxxyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 166);

    auto g_0_xxxxyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 167);

    auto g_0_xxxxyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 168);

    auto g_0_xxxxyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 169);

    auto g_0_xxxxyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 170);

    auto g_0_xxxxyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 171);

    auto g_0_xxxxyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 172);

    auto g_0_xxxxyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 173);

    auto g_0_xxxxyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 174);

    auto g_0_xxxxyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 175);

    auto g_0_xxxxyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 176);

    auto g_0_xxxxyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 177);

    auto g_0_xxxxyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 178);

    auto g_0_xxxxyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 179);

    auto g_0_xxxxzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 225);

    auto g_0_xxxxzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 226);

    auto g_0_xxxxzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 227);

    auto g_0_xxxxzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 228);

    auto g_0_xxxxzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 229);

    auto g_0_xxxxzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 230);

    auto g_0_xxxxzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 231);

    auto g_0_xxxxzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 232);

    auto g_0_xxxxzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 233);

    auto g_0_xxxxzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 234);

    auto g_0_xxxxzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 235);

    auto g_0_xxxxzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 236);

    auto g_0_xxxxzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 237);

    auto g_0_xxxxzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 238);

    auto g_0_xxxxzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 239);

    auto g_0_xxxxzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 240);

    auto g_0_xxxxzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 241);

    auto g_0_xxxxzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 242);

    auto g_0_xxxxzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 243);

    auto g_0_xxxxzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 244);

    auto g_0_xxxxzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 245);

    auto g_0_xxxxzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 246);

    auto g_0_xxxxzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 247);

    auto g_0_xxxxzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 248);

    auto g_0_xxxxzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 249);

    auto g_0_xxxxzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 250);

    auto g_0_xxxxzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 251);

    auto g_0_xxxxzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 252);

    auto g_0_xxxxzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 253);

    auto g_0_xxxxzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 254);

    auto g_0_xxxxzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 255);

    auto g_0_xxxxzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 256);

    auto g_0_xxxxzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 257);

    auto g_0_xxxxzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 258);

    auto g_0_xxxxzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 259);

    auto g_0_xxxxzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 260);

    auto g_0_xxxxzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 261);

    auto g_0_xxxxzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 262);

    auto g_0_xxxxzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 263);

    auto g_0_xxxxzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 264);

    auto g_0_xxxxzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 265);

    auto g_0_xxxxzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 266);

    auto g_0_xxxxzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 267);

    auto g_0_xxxxzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 268);

    auto g_0_xxxxzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 269);

    auto g_0_xxxyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 270);

    auto g_0_xxxyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 271);

    auto g_0_xxxyyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 272);

    auto g_0_xxxyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 273);

    auto g_0_xxxyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 274);

    auto g_0_xxxyyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 275);

    auto g_0_xxxyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 276);

    auto g_0_xxxyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 277);

    auto g_0_xxxyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 278);

    auto g_0_xxxyyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 279);

    auto g_0_xxxyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 280);

    auto g_0_xxxyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 281);

    auto g_0_xxxyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 282);

    auto g_0_xxxyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 283);

    auto g_0_xxxyyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 284);

    auto g_0_xxxyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 285);

    auto g_0_xxxyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 286);

    auto g_0_xxxyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 287);

    auto g_0_xxxyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 288);

    auto g_0_xxxyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 289);

    auto g_0_xxxyyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 290);

    auto g_0_xxxyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 291);

    auto g_0_xxxyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 292);

    auto g_0_xxxyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 293);

    auto g_0_xxxyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 294);

    auto g_0_xxxyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 295);

    auto g_0_xxxyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 296);

    auto g_0_xxxyyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 297);

    auto g_0_xxxyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 298);

    auto g_0_xxxyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 299);

    auto g_0_xxxyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 300);

    auto g_0_xxxyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 301);

    auto g_0_xxxyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 302);

    auto g_0_xxxyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 303);

    auto g_0_xxxyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 304);

    auto g_0_xxxyyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 305);

    auto g_0_xxxyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 306);

    auto g_0_xxxyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 307);

    auto g_0_xxxyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 308);

    auto g_0_xxxyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 309);

    auto g_0_xxxyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 310);

    auto g_0_xxxyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 311);

    auto g_0_xxxyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 312);

    auto g_0_xxxyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 313);

    auto g_0_xxxyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 314);

    auto g_0_xxxyyz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 316);

    auto g_0_xxxyyz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 318);

    auto g_0_xxxyyz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 321);

    auto g_0_xxxyyz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 325);

    auto g_0_xxxyyz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 330);

    auto g_0_xxxyyz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 336);

    auto g_0_xxxyyz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 343);

    auto g_0_xxxyzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 360);

    auto g_0_xxxyzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 362);

    auto g_0_xxxyzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 365);

    auto g_0_xxxyzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 369);

    auto g_0_xxxyzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 374);

    auto g_0_xxxyzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 380);

    auto g_0_xxxyzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 387);

    auto g_0_xxxyzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 395);

    auto g_0_xxxzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 405);

    auto g_0_xxxzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 406);

    auto g_0_xxxzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 407);

    auto g_0_xxxzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 408);

    auto g_0_xxxzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 409);

    auto g_0_xxxzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 410);

    auto g_0_xxxzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 411);

    auto g_0_xxxzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 412);

    auto g_0_xxxzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 413);

    auto g_0_xxxzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 414);

    auto g_0_xxxzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 415);

    auto g_0_xxxzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 416);

    auto g_0_xxxzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 417);

    auto g_0_xxxzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 418);

    auto g_0_xxxzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 419);

    auto g_0_xxxzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 420);

    auto g_0_xxxzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 421);

    auto g_0_xxxzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 422);

    auto g_0_xxxzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 423);

    auto g_0_xxxzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 424);

    auto g_0_xxxzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 425);

    auto g_0_xxxzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 426);

    auto g_0_xxxzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 427);

    auto g_0_xxxzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 428);

    auto g_0_xxxzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 429);

    auto g_0_xxxzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 430);

    auto g_0_xxxzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 431);

    auto g_0_xxxzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 432);

    auto g_0_xxxzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 433);

    auto g_0_xxxzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 434);

    auto g_0_xxxzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 435);

    auto g_0_xxxzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 436);

    auto g_0_xxxzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 437);

    auto g_0_xxxzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 438);

    auto g_0_xxxzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 439);

    auto g_0_xxxzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 440);

    auto g_0_xxxzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 441);

    auto g_0_xxxzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 442);

    auto g_0_xxxzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 443);

    auto g_0_xxxzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 444);

    auto g_0_xxxzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 445);

    auto g_0_xxxzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 446);

    auto g_0_xxxzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 447);

    auto g_0_xxxzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 448);

    auto g_0_xxxzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 449);

    auto g_0_xxyyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 450);

    auto g_0_xxyyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 451);

    auto g_0_xxyyyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 452);

    auto g_0_xxyyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 453);

    auto g_0_xxyyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 454);

    auto g_0_xxyyyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 455);

    auto g_0_xxyyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 456);

    auto g_0_xxyyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 457);

    auto g_0_xxyyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 458);

    auto g_0_xxyyyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 459);

    auto g_0_xxyyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 460);

    auto g_0_xxyyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 461);

    auto g_0_xxyyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 462);

    auto g_0_xxyyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 463);

    auto g_0_xxyyyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 464);

    auto g_0_xxyyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 465);

    auto g_0_xxyyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 466);

    auto g_0_xxyyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 467);

    auto g_0_xxyyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 468);

    auto g_0_xxyyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 469);

    auto g_0_xxyyyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 470);

    auto g_0_xxyyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 471);

    auto g_0_xxyyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 472);

    auto g_0_xxyyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 473);

    auto g_0_xxyyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 474);

    auto g_0_xxyyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 475);

    auto g_0_xxyyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 476);

    auto g_0_xxyyyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 477);

    auto g_0_xxyyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 478);

    auto g_0_xxyyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 479);

    auto g_0_xxyyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 480);

    auto g_0_xxyyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 481);

    auto g_0_xxyyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 482);

    auto g_0_xxyyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 483);

    auto g_0_xxyyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 484);

    auto g_0_xxyyyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 485);

    auto g_0_xxyyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 486);

    auto g_0_xxyyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 487);

    auto g_0_xxyyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 488);

    auto g_0_xxyyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 489);

    auto g_0_xxyyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 490);

    auto g_0_xxyyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 491);

    auto g_0_xxyyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 492);

    auto g_0_xxyyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 493);

    auto g_0_xxyyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 494);

    auto g_0_xxyyyz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 496);

    auto g_0_xxyyyz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 498);

    auto g_0_xxyyyz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 501);

    auto g_0_xxyyyz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 505);

    auto g_0_xxyyyz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 510);

    auto g_0_xxyyyz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 516);

    auto g_0_xxyyyz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 523);

    auto g_0_xxyyzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 540);

    auto g_0_xxyyzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 541);

    auto g_0_xxyyzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 542);

    auto g_0_xxyyzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 543);

    auto g_0_xxyyzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 544);

    auto g_0_xxyyzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 545);

    auto g_0_xxyyzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 546);

    auto g_0_xxyyzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 547);

    auto g_0_xxyyzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 548);

    auto g_0_xxyyzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 549);

    auto g_0_xxyyzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 550);

    auto g_0_xxyyzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 551);

    auto g_0_xxyyzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 552);

    auto g_0_xxyyzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 553);

    auto g_0_xxyyzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 554);

    auto g_0_xxyyzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 555);

    auto g_0_xxyyzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 556);

    auto g_0_xxyyzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 557);

    auto g_0_xxyyzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 558);

    auto g_0_xxyyzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 559);

    auto g_0_xxyyzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 560);

    auto g_0_xxyyzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 561);

    auto g_0_xxyyzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 562);

    auto g_0_xxyyzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 563);

    auto g_0_xxyyzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 564);

    auto g_0_xxyyzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 565);

    auto g_0_xxyyzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 566);

    auto g_0_xxyyzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 567);

    auto g_0_xxyyzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 568);

    auto g_0_xxyyzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 569);

    auto g_0_xxyyzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 570);

    auto g_0_xxyyzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 571);

    auto g_0_xxyyzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 572);

    auto g_0_xxyyzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 573);

    auto g_0_xxyyzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 574);

    auto g_0_xxyyzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 575);

    auto g_0_xxyyzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 576);

    auto g_0_xxyyzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 577);

    auto g_0_xxyyzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 578);

    auto g_0_xxyyzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 579);

    auto g_0_xxyyzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 580);

    auto g_0_xxyyzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 581);

    auto g_0_xxyyzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 582);

    auto g_0_xxyyzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 583);

    auto g_0_xxyyzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 584);

    auto g_0_xxyzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 585);

    auto g_0_xxyzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 587);

    auto g_0_xxyzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 590);

    auto g_0_xxyzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 594);

    auto g_0_xxyzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 599);

    auto g_0_xxyzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 605);

    auto g_0_xxyzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 612);

    auto g_0_xxyzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 620);

    auto g_0_xxzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 630);

    auto g_0_xxzzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 631);

    auto g_0_xxzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 632);

    auto g_0_xxzzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 633);

    auto g_0_xxzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 634);

    auto g_0_xxzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 635);

    auto g_0_xxzzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 636);

    auto g_0_xxzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 637);

    auto g_0_xxzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 638);

    auto g_0_xxzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 639);

    auto g_0_xxzzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 640);

    auto g_0_xxzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 641);

    auto g_0_xxzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 642);

    auto g_0_xxzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 643);

    auto g_0_xxzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 644);

    auto g_0_xxzzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 645);

    auto g_0_xxzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 646);

    auto g_0_xxzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 647);

    auto g_0_xxzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 648);

    auto g_0_xxzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 649);

    auto g_0_xxzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 650);

    auto g_0_xxzzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 651);

    auto g_0_xxzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 652);

    auto g_0_xxzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 653);

    auto g_0_xxzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 654);

    auto g_0_xxzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 655);

    auto g_0_xxzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 656);

    auto g_0_xxzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 657);

    auto g_0_xxzzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 658);

    auto g_0_xxzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 659);

    auto g_0_xxzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 660);

    auto g_0_xxzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 661);

    auto g_0_xxzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 662);

    auto g_0_xxzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 663);

    auto g_0_xxzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 664);

    auto g_0_xxzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 665);

    auto g_0_xxzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 666);

    auto g_0_xxzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 667);

    auto g_0_xxzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 668);

    auto g_0_xxzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 669);

    auto g_0_xxzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 670);

    auto g_0_xxzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 671);

    auto g_0_xxzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 672);

    auto g_0_xxzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 673);

    auto g_0_xxzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 674);

    auto g_0_xyyyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 675);

    auto g_0_xyyyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 676);

    auto g_0_xyyyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 678);

    auto g_0_xyyyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 679);

    auto g_0_xyyyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 681);

    auto g_0_xyyyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 682);

    auto g_0_xyyyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 683);

    auto g_0_xyyyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 685);

    auto g_0_xyyyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 686);

    auto g_0_xyyyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 687);

    auto g_0_xyyyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 688);

    auto g_0_xyyyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 690);

    auto g_0_xyyyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 691);

    auto g_0_xyyyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 692);

    auto g_0_xyyyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 693);

    auto g_0_xyyyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 694);

    auto g_0_xyyyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 696);

    auto g_0_xyyyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 697);

    auto g_0_xyyyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 698);

    auto g_0_xyyyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 699);

    auto g_0_xyyyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 700);

    auto g_0_xyyyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 701);

    auto g_0_xyyyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 703);

    auto g_0_xyyyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 704);

    auto g_0_xyyyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 705);

    auto g_0_xyyyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 706);

    auto g_0_xyyyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 707);

    auto g_0_xyyyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 708);

    auto g_0_xyyyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 709);

    auto g_0_xyyyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 711);

    auto g_0_xyyyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 712);

    auto g_0_xyyyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 713);

    auto g_0_xyyyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 714);

    auto g_0_xyyyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 715);

    auto g_0_xyyyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 716);

    auto g_0_xyyyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 717);

    auto g_0_xyyyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 718);

    auto g_0_xyyyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 719);

    auto g_0_xyyyzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 769);

    auto g_0_xyyyzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 772);

    auto g_0_xyyyzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 773);

    auto g_0_xyyyzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 776);

    auto g_0_xyyyzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 777);

    auto g_0_xyyyzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 778);

    auto g_0_xyyyzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 781);

    auto g_0_xyyyzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 782);

    auto g_0_xyyyzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 783);

    auto g_0_xyyyzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 784);

    auto g_0_xyyyzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 787);

    auto g_0_xyyyzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 788);

    auto g_0_xyyyzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 789);

    auto g_0_xyyyzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 790);

    auto g_0_xyyyzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 791);

    auto g_0_xyyyzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 794);

    auto g_0_xyyyzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 795);

    auto g_0_xyyyzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 796);

    auto g_0_xyyyzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 797);

    auto g_0_xyyyzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 798);

    auto g_0_xyyyzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 799);

    auto g_0_xyyyzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 801);

    auto g_0_xyyyzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 802);

    auto g_0_xyyyzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 803);

    auto g_0_xyyyzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 804);

    auto g_0_xyyyzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 805);

    auto g_0_xyyyzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 806);

    auto g_0_xyyyzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 807);

    auto g_0_xyyyzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 808);

    auto g_0_xyyyzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 809);

    auto g_0_xyyzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 814);

    auto g_0_xyyzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 817);

    auto g_0_xyyzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 818);

    auto g_0_xyyzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 821);

    auto g_0_xyyzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 822);

    auto g_0_xyyzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 823);

    auto g_0_xyyzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 826);

    auto g_0_xyyzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 827);

    auto g_0_xyyzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 828);

    auto g_0_xyyzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 829);

    auto g_0_xyyzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 832);

    auto g_0_xyyzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 833);

    auto g_0_xyyzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 834);

    auto g_0_xyyzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 835);

    auto g_0_xyyzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 836);

    auto g_0_xyyzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 839);

    auto g_0_xyyzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 840);

    auto g_0_xyyzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 841);

    auto g_0_xyyzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 842);

    auto g_0_xyyzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 843);

    auto g_0_xyyzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 844);

    auto g_0_xyyzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 846);

    auto g_0_xyyzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 847);

    auto g_0_xyyzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 848);

    auto g_0_xyyzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 849);

    auto g_0_xyyzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 850);

    auto g_0_xyyzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 851);

    auto g_0_xyyzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 852);

    auto g_0_xyyzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 853);

    auto g_0_xyyzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 854);

    auto g_0_xzzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 900);

    auto g_0_xzzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 902);

    auto g_0_xzzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 904);

    auto g_0_xzzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 905);

    auto g_0_xzzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 907);

    auto g_0_xzzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 908);

    auto g_0_xzzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 909);

    auto g_0_xzzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 911);

    auto g_0_xzzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 912);

    auto g_0_xzzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 913);

    auto g_0_xzzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 914);

    auto g_0_xzzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 916);

    auto g_0_xzzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 917);

    auto g_0_xzzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 918);

    auto g_0_xzzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 919);

    auto g_0_xzzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 920);

    auto g_0_xzzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 922);

    auto g_0_xzzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 923);

    auto g_0_xzzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 924);

    auto g_0_xzzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 925);

    auto g_0_xzzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 926);

    auto g_0_xzzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 927);

    auto g_0_xzzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 929);

    auto g_0_xzzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 930);

    auto g_0_xzzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 931);

    auto g_0_xzzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 932);

    auto g_0_xzzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 933);

    auto g_0_xzzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 934);

    auto g_0_xzzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 935);

    auto g_0_xzzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 936);

    auto g_0_xzzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 937);

    auto g_0_xzzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 938);

    auto g_0_xzzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 939);

    auto g_0_xzzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 940);

    auto g_0_xzzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 941);

    auto g_0_xzzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 942);

    auto g_0_xzzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 943);

    auto g_0_xzzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 944);

    auto g_0_yyyyyy_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 945);

    auto g_0_yyyyyy_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 946);

    auto g_0_yyyyyy_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 947);

    auto g_0_yyyyyy_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 948);

    auto g_0_yyyyyy_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 949);

    auto g_0_yyyyyy_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 950);

    auto g_0_yyyyyy_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 951);

    auto g_0_yyyyyy_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 952);

    auto g_0_yyyyyy_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 953);

    auto g_0_yyyyyy_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 954);

    auto g_0_yyyyyy_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 955);

    auto g_0_yyyyyy_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 956);

    auto g_0_yyyyyy_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 957);

    auto g_0_yyyyyy_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 958);

    auto g_0_yyyyyy_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 959);

    auto g_0_yyyyyy_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 960);

    auto g_0_yyyyyy_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 961);

    auto g_0_yyyyyy_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 962);

    auto g_0_yyyyyy_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 963);

    auto g_0_yyyyyy_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 964);

    auto g_0_yyyyyy_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 965);

    auto g_0_yyyyyy_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 966);

    auto g_0_yyyyyy_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 967);

    auto g_0_yyyyyy_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 968);

    auto g_0_yyyyyy_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 969);

    auto g_0_yyyyyy_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 970);

    auto g_0_yyyyyy_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 971);

    auto g_0_yyyyyy_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 972);

    auto g_0_yyyyyy_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 973);

    auto g_0_yyyyyy_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 974);

    auto g_0_yyyyyy_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 975);

    auto g_0_yyyyyy_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 976);

    auto g_0_yyyyyy_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 977);

    auto g_0_yyyyyy_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 978);

    auto g_0_yyyyyy_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 979);

    auto g_0_yyyyyy_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 980);

    auto g_0_yyyyyy_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 981);

    auto g_0_yyyyyy_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 982);

    auto g_0_yyyyyy_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 983);

    auto g_0_yyyyyy_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 984);

    auto g_0_yyyyyy_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 985);

    auto g_0_yyyyyy_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 986);

    auto g_0_yyyyyy_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 987);

    auto g_0_yyyyyy_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 988);

    auto g_0_yyyyyy_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 989);

    auto g_0_yyyyyz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 991);

    auto g_0_yyyyyz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 992);

    auto g_0_yyyyyz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 993);

    auto g_0_yyyyyz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 994);

    auto g_0_yyyyyz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 995);

    auto g_0_yyyyyz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 996);

    auto g_0_yyyyyz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 997);

    auto g_0_yyyyyz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 998);

    auto g_0_yyyyyz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 999);

    auto g_0_yyyyyz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1000);

    auto g_0_yyyyyz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1001);

    auto g_0_yyyyyz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1002);

    auto g_0_yyyyyz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1003);

    auto g_0_yyyyyz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1004);

    auto g_0_yyyyyz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1005);

    auto g_0_yyyyyz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1006);

    auto g_0_yyyyyz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1007);

    auto g_0_yyyyyz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1008);

    auto g_0_yyyyyz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1009);

    auto g_0_yyyyyz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1010);

    auto g_0_yyyyyz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1011);

    auto g_0_yyyyyz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1012);

    auto g_0_yyyyyz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1013);

    auto g_0_yyyyyz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1014);

    auto g_0_yyyyyz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1015);

    auto g_0_yyyyyz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1016);

    auto g_0_yyyyyz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1017);

    auto g_0_yyyyyz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1018);

    auto g_0_yyyyyz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1019);

    auto g_0_yyyyyz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1020);

    auto g_0_yyyyyz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1021);

    auto g_0_yyyyyz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1022);

    auto g_0_yyyyyz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1023);

    auto g_0_yyyyyz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1024);

    auto g_0_yyyyyz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1025);

    auto g_0_yyyyyz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1026);

    auto g_0_yyyyyz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1027);

    auto g_0_yyyyyz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1028);

    auto g_0_yyyyyz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1029);

    auto g_0_yyyyyz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1030);

    auto g_0_yyyyyz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1031);

    auto g_0_yyyyyz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1032);

    auto g_0_yyyyyz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1033);

    auto g_0_yyyyyz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1034);

    auto g_0_yyyyzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 1035);

    auto g_0_yyyyzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1036);

    auto g_0_yyyyzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 1037);

    auto g_0_yyyyzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 1038);

    auto g_0_yyyyzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 1039);

    auto g_0_yyyyzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 1040);

    auto g_0_yyyyzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 1041);

    auto g_0_yyyyzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 1042);

    auto g_0_yyyyzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 1043);

    auto g_0_yyyyzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 1044);

    auto g_0_yyyyzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1045);

    auto g_0_yyyyzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1046);

    auto g_0_yyyyzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1047);

    auto g_0_yyyyzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1048);

    auto g_0_yyyyzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1049);

    auto g_0_yyyyzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1050);

    auto g_0_yyyyzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1051);

    auto g_0_yyyyzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1052);

    auto g_0_yyyyzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1053);

    auto g_0_yyyyzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1054);

    auto g_0_yyyyzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1055);

    auto g_0_yyyyzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1056);

    auto g_0_yyyyzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1057);

    auto g_0_yyyyzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1058);

    auto g_0_yyyyzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1059);

    auto g_0_yyyyzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1060);

    auto g_0_yyyyzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1061);

    auto g_0_yyyyzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1062);

    auto g_0_yyyyzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1063);

    auto g_0_yyyyzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1064);

    auto g_0_yyyyzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1065);

    auto g_0_yyyyzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1066);

    auto g_0_yyyyzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1067);

    auto g_0_yyyyzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1068);

    auto g_0_yyyyzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1069);

    auto g_0_yyyyzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1070);

    auto g_0_yyyyzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1071);

    auto g_0_yyyyzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1072);

    auto g_0_yyyyzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1073);

    auto g_0_yyyyzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1074);

    auto g_0_yyyyzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1075);

    auto g_0_yyyyzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1076);

    auto g_0_yyyyzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1077);

    auto g_0_yyyyzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1078);

    auto g_0_yyyyzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1079);

    auto g_0_yyyzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 1080);

    auto g_0_yyyzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1081);

    auto g_0_yyyzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 1082);

    auto g_0_yyyzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 1083);

    auto g_0_yyyzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 1084);

    auto g_0_yyyzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 1085);

    auto g_0_yyyzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 1086);

    auto g_0_yyyzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 1087);

    auto g_0_yyyzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 1088);

    auto g_0_yyyzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 1089);

    auto g_0_yyyzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1090);

    auto g_0_yyyzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1091);

    auto g_0_yyyzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1092);

    auto g_0_yyyzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1093);

    auto g_0_yyyzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1094);

    auto g_0_yyyzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1095);

    auto g_0_yyyzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1096);

    auto g_0_yyyzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1097);

    auto g_0_yyyzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1098);

    auto g_0_yyyzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1099);

    auto g_0_yyyzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1100);

    auto g_0_yyyzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1101);

    auto g_0_yyyzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1102);

    auto g_0_yyyzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1103);

    auto g_0_yyyzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1104);

    auto g_0_yyyzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1105);

    auto g_0_yyyzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1106);

    auto g_0_yyyzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1107);

    auto g_0_yyyzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1108);

    auto g_0_yyyzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1109);

    auto g_0_yyyzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1110);

    auto g_0_yyyzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1111);

    auto g_0_yyyzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1112);

    auto g_0_yyyzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1113);

    auto g_0_yyyzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1114);

    auto g_0_yyyzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1115);

    auto g_0_yyyzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1116);

    auto g_0_yyyzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1117);

    auto g_0_yyyzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1118);

    auto g_0_yyyzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1119);

    auto g_0_yyyzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1120);

    auto g_0_yyyzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1121);

    auto g_0_yyyzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1122);

    auto g_0_yyyzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1123);

    auto g_0_yyyzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1124);

    auto g_0_yyzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 1125);

    auto g_0_yyzzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1126);

    auto g_0_yyzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 1127);

    auto g_0_yyzzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 1128);

    auto g_0_yyzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 1129);

    auto g_0_yyzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 1130);

    auto g_0_yyzzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 1131);

    auto g_0_yyzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 1132);

    auto g_0_yyzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 1133);

    auto g_0_yyzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 1134);

    auto g_0_yyzzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1135);

    auto g_0_yyzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1136);

    auto g_0_yyzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1137);

    auto g_0_yyzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1138);

    auto g_0_yyzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1139);

    auto g_0_yyzzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1140);

    auto g_0_yyzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1141);

    auto g_0_yyzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1142);

    auto g_0_yyzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1143);

    auto g_0_yyzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1144);

    auto g_0_yyzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1145);

    auto g_0_yyzzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1146);

    auto g_0_yyzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1147);

    auto g_0_yyzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1148);

    auto g_0_yyzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1149);

    auto g_0_yyzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1150);

    auto g_0_yyzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1151);

    auto g_0_yyzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1152);

    auto g_0_yyzzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1153);

    auto g_0_yyzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1154);

    auto g_0_yyzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1155);

    auto g_0_yyzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1156);

    auto g_0_yyzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1157);

    auto g_0_yyzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1158);

    auto g_0_yyzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1159);

    auto g_0_yyzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1160);

    auto g_0_yyzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1161);

    auto g_0_yyzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1162);

    auto g_0_yyzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1163);

    auto g_0_yyzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1164);

    auto g_0_yyzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1165);

    auto g_0_yyzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1166);

    auto g_0_yyzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1167);

    auto g_0_yyzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1168);

    auto g_0_yyzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1169);

    auto g_0_yzzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 1170);

    auto g_0_yzzzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1171);

    auto g_0_yzzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 1172);

    auto g_0_yzzzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 1173);

    auto g_0_yzzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 1174);

    auto g_0_yzzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 1175);

    auto g_0_yzzzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 1176);

    auto g_0_yzzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 1177);

    auto g_0_yzzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 1178);

    auto g_0_yzzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 1179);

    auto g_0_yzzzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1180);

    auto g_0_yzzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1181);

    auto g_0_yzzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1182);

    auto g_0_yzzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1183);

    auto g_0_yzzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1184);

    auto g_0_yzzzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1185);

    auto g_0_yzzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1186);

    auto g_0_yzzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1187);

    auto g_0_yzzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1188);

    auto g_0_yzzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1189);

    auto g_0_yzzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1190);

    auto g_0_yzzzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1191);

    auto g_0_yzzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1192);

    auto g_0_yzzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1193);

    auto g_0_yzzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1194);

    auto g_0_yzzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1195);

    auto g_0_yzzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1196);

    auto g_0_yzzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1197);

    auto g_0_yzzzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1198);

    auto g_0_yzzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1199);

    auto g_0_yzzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1200);

    auto g_0_yzzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1201);

    auto g_0_yzzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1202);

    auto g_0_yzzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1203);

    auto g_0_yzzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1204);

    auto g_0_yzzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1205);

    auto g_0_yzzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1206);

    auto g_0_yzzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1207);

    auto g_0_yzzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1208);

    auto g_0_yzzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1209);

    auto g_0_yzzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1210);

    auto g_0_yzzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1211);

    auto g_0_yzzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1212);

    auto g_0_yzzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1213);

    auto g_0_yzzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1214);

    auto g_0_zzzzzz_0_xxxxxxxx_1 = pbuffer.data(idx_eri_1_sisl + 1215);

    auto g_0_zzzzzz_0_xxxxxxxy_1 = pbuffer.data(idx_eri_1_sisl + 1216);

    auto g_0_zzzzzz_0_xxxxxxxz_1 = pbuffer.data(idx_eri_1_sisl + 1217);

    auto g_0_zzzzzz_0_xxxxxxyy_1 = pbuffer.data(idx_eri_1_sisl + 1218);

    auto g_0_zzzzzz_0_xxxxxxyz_1 = pbuffer.data(idx_eri_1_sisl + 1219);

    auto g_0_zzzzzz_0_xxxxxxzz_1 = pbuffer.data(idx_eri_1_sisl + 1220);

    auto g_0_zzzzzz_0_xxxxxyyy_1 = pbuffer.data(idx_eri_1_sisl + 1221);

    auto g_0_zzzzzz_0_xxxxxyyz_1 = pbuffer.data(idx_eri_1_sisl + 1222);

    auto g_0_zzzzzz_0_xxxxxyzz_1 = pbuffer.data(idx_eri_1_sisl + 1223);

    auto g_0_zzzzzz_0_xxxxxzzz_1 = pbuffer.data(idx_eri_1_sisl + 1224);

    auto g_0_zzzzzz_0_xxxxyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1225);

    auto g_0_zzzzzz_0_xxxxyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1226);

    auto g_0_zzzzzz_0_xxxxyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1227);

    auto g_0_zzzzzz_0_xxxxyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1228);

    auto g_0_zzzzzz_0_xxxxzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1229);

    auto g_0_zzzzzz_0_xxxyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1230);

    auto g_0_zzzzzz_0_xxxyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1231);

    auto g_0_zzzzzz_0_xxxyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1232);

    auto g_0_zzzzzz_0_xxxyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1233);

    auto g_0_zzzzzz_0_xxxyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1234);

    auto g_0_zzzzzz_0_xxxzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1235);

    auto g_0_zzzzzz_0_xxyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1236);

    auto g_0_zzzzzz_0_xxyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1237);

    auto g_0_zzzzzz_0_xxyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1238);

    auto g_0_zzzzzz_0_xxyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1239);

    auto g_0_zzzzzz_0_xxyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1240);

    auto g_0_zzzzzz_0_xxyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1241);

    auto g_0_zzzzzz_0_xxzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1242);

    auto g_0_zzzzzz_0_xyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1243);

    auto g_0_zzzzzz_0_xyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1244);

    auto g_0_zzzzzz_0_xyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1245);

    auto g_0_zzzzzz_0_xyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1246);

    auto g_0_zzzzzz_0_xyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1247);

    auto g_0_zzzzzz_0_xyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1248);

    auto g_0_zzzzzz_0_xyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1249);

    auto g_0_zzzzzz_0_xzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1250);

    auto g_0_zzzzzz_0_yyyyyyyy_1 = pbuffer.data(idx_eri_1_sisl + 1251);

    auto g_0_zzzzzz_0_yyyyyyyz_1 = pbuffer.data(idx_eri_1_sisl + 1252);

    auto g_0_zzzzzz_0_yyyyyyzz_1 = pbuffer.data(idx_eri_1_sisl + 1253);

    auto g_0_zzzzzz_0_yyyyyzzz_1 = pbuffer.data(idx_eri_1_sisl + 1254);

    auto g_0_zzzzzz_0_yyyyzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1255);

    auto g_0_zzzzzz_0_yyyzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1256);

    auto g_0_zzzzzz_0_yyzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1257);

    auto g_0_zzzzzz_0_yzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1258);

    auto g_0_zzzzzz_0_zzzzzzzz_1 = pbuffer.data(idx_eri_1_sisl + 1259);

    /// Set up 0-45 components of targeted buffer : SKSL

    auto g_0_xxxxxxx_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl);

    auto g_0_xxxxxxx_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1);

    auto g_0_xxxxxxx_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 2);

    auto g_0_xxxxxxx_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 3);

    auto g_0_xxxxxxx_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 4);

    auto g_0_xxxxxxx_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 5);

    auto g_0_xxxxxxx_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 6);

    auto g_0_xxxxxxx_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 7);

    auto g_0_xxxxxxx_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 8);

    auto g_0_xxxxxxx_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 9);

    auto g_0_xxxxxxx_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 10);

    auto g_0_xxxxxxx_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 11);

    auto g_0_xxxxxxx_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 12);

    auto g_0_xxxxxxx_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 13);

    auto g_0_xxxxxxx_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 14);

    auto g_0_xxxxxxx_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 15);

    auto g_0_xxxxxxx_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 16);

    auto g_0_xxxxxxx_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 17);

    auto g_0_xxxxxxx_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 18);

    auto g_0_xxxxxxx_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 19);

    auto g_0_xxxxxxx_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 20);

    auto g_0_xxxxxxx_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 21);

    auto g_0_xxxxxxx_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 22);

    auto g_0_xxxxxxx_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 23);

    auto g_0_xxxxxxx_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 24);

    auto g_0_xxxxxxx_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 25);

    auto g_0_xxxxxxx_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 26);

    auto g_0_xxxxxxx_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 27);

    auto g_0_xxxxxxx_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 28);

    auto g_0_xxxxxxx_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 29);

    auto g_0_xxxxxxx_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 30);

    auto g_0_xxxxxxx_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 31);

    auto g_0_xxxxxxx_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 32);

    auto g_0_xxxxxxx_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 33);

    auto g_0_xxxxxxx_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 34);

    auto g_0_xxxxxxx_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 35);

    auto g_0_xxxxxxx_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 36);

    auto g_0_xxxxxxx_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 37);

    auto g_0_xxxxxxx_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 38);

    auto g_0_xxxxxxx_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 39);

    auto g_0_xxxxxxx_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 40);

    auto g_0_xxxxxxx_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 41);

    auto g_0_xxxxxxx_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 42);

    auto g_0_xxxxxxx_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 43);

    auto g_0_xxxxxxx_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 44);

    #pragma omp simd aligned(g_0_xxxxx_0_xxxxxxxx_0, g_0_xxxxx_0_xxxxxxxx_1, g_0_xxxxx_0_xxxxxxxy_0, g_0_xxxxx_0_xxxxxxxy_1, g_0_xxxxx_0_xxxxxxxz_0, g_0_xxxxx_0_xxxxxxxz_1, g_0_xxxxx_0_xxxxxxyy_0, g_0_xxxxx_0_xxxxxxyy_1, g_0_xxxxx_0_xxxxxxyz_0, g_0_xxxxx_0_xxxxxxyz_1, g_0_xxxxx_0_xxxxxxzz_0, g_0_xxxxx_0_xxxxxxzz_1, g_0_xxxxx_0_xxxxxyyy_0, g_0_xxxxx_0_xxxxxyyy_1, g_0_xxxxx_0_xxxxxyyz_0, g_0_xxxxx_0_xxxxxyyz_1, g_0_xxxxx_0_xxxxxyzz_0, g_0_xxxxx_0_xxxxxyzz_1, g_0_xxxxx_0_xxxxxzzz_0, g_0_xxxxx_0_xxxxxzzz_1, g_0_xxxxx_0_xxxxyyyy_0, g_0_xxxxx_0_xxxxyyyy_1, g_0_xxxxx_0_xxxxyyyz_0, g_0_xxxxx_0_xxxxyyyz_1, g_0_xxxxx_0_xxxxyyzz_0, g_0_xxxxx_0_xxxxyyzz_1, g_0_xxxxx_0_xxxxyzzz_0, g_0_xxxxx_0_xxxxyzzz_1, g_0_xxxxx_0_xxxxzzzz_0, g_0_xxxxx_0_xxxxzzzz_1, g_0_xxxxx_0_xxxyyyyy_0, g_0_xxxxx_0_xxxyyyyy_1, g_0_xxxxx_0_xxxyyyyz_0, g_0_xxxxx_0_xxxyyyyz_1, g_0_xxxxx_0_xxxyyyzz_0, g_0_xxxxx_0_xxxyyyzz_1, g_0_xxxxx_0_xxxyyzzz_0, g_0_xxxxx_0_xxxyyzzz_1, g_0_xxxxx_0_xxxyzzzz_0, g_0_xxxxx_0_xxxyzzzz_1, g_0_xxxxx_0_xxxzzzzz_0, g_0_xxxxx_0_xxxzzzzz_1, g_0_xxxxx_0_xxyyyyyy_0, g_0_xxxxx_0_xxyyyyyy_1, g_0_xxxxx_0_xxyyyyyz_0, g_0_xxxxx_0_xxyyyyyz_1, g_0_xxxxx_0_xxyyyyzz_0, g_0_xxxxx_0_xxyyyyzz_1, g_0_xxxxx_0_xxyyyzzz_0, g_0_xxxxx_0_xxyyyzzz_1, g_0_xxxxx_0_xxyyzzzz_0, g_0_xxxxx_0_xxyyzzzz_1, g_0_xxxxx_0_xxyzzzzz_0, g_0_xxxxx_0_xxyzzzzz_1, g_0_xxxxx_0_xxzzzzzz_0, g_0_xxxxx_0_xxzzzzzz_1, g_0_xxxxx_0_xyyyyyyy_0, g_0_xxxxx_0_xyyyyyyy_1, g_0_xxxxx_0_xyyyyyyz_0, g_0_xxxxx_0_xyyyyyyz_1, g_0_xxxxx_0_xyyyyyzz_0, g_0_xxxxx_0_xyyyyyzz_1, g_0_xxxxx_0_xyyyyzzz_0, g_0_xxxxx_0_xyyyyzzz_1, g_0_xxxxx_0_xyyyzzzz_0, g_0_xxxxx_0_xyyyzzzz_1, g_0_xxxxx_0_xyyzzzzz_0, g_0_xxxxx_0_xyyzzzzz_1, g_0_xxxxx_0_xyzzzzzz_0, g_0_xxxxx_0_xyzzzzzz_1, g_0_xxxxx_0_xzzzzzzz_0, g_0_xxxxx_0_xzzzzzzz_1, g_0_xxxxx_0_yyyyyyyy_0, g_0_xxxxx_0_yyyyyyyy_1, g_0_xxxxx_0_yyyyyyyz_0, g_0_xxxxx_0_yyyyyyyz_1, g_0_xxxxx_0_yyyyyyzz_0, g_0_xxxxx_0_yyyyyyzz_1, g_0_xxxxx_0_yyyyyzzz_0, g_0_xxxxx_0_yyyyyzzz_1, g_0_xxxxx_0_yyyyzzzz_0, g_0_xxxxx_0_yyyyzzzz_1, g_0_xxxxx_0_yyyzzzzz_0, g_0_xxxxx_0_yyyzzzzz_1, g_0_xxxxx_0_yyzzzzzz_0, g_0_xxxxx_0_yyzzzzzz_1, g_0_xxxxx_0_yzzzzzzz_0, g_0_xxxxx_0_yzzzzzzz_1, g_0_xxxxx_0_zzzzzzzz_0, g_0_xxxxx_0_zzzzzzzz_1, g_0_xxxxxx_0_xxxxxxx_1, g_0_xxxxxx_0_xxxxxxxx_0, g_0_xxxxxx_0_xxxxxxxx_1, g_0_xxxxxx_0_xxxxxxxy_0, g_0_xxxxxx_0_xxxxxxxy_1, g_0_xxxxxx_0_xxxxxxxz_0, g_0_xxxxxx_0_xxxxxxxz_1, g_0_xxxxxx_0_xxxxxxy_1, g_0_xxxxxx_0_xxxxxxyy_0, g_0_xxxxxx_0_xxxxxxyy_1, g_0_xxxxxx_0_xxxxxxyz_0, g_0_xxxxxx_0_xxxxxxyz_1, g_0_xxxxxx_0_xxxxxxz_1, g_0_xxxxxx_0_xxxxxxzz_0, g_0_xxxxxx_0_xxxxxxzz_1, g_0_xxxxxx_0_xxxxxyy_1, g_0_xxxxxx_0_xxxxxyyy_0, g_0_xxxxxx_0_xxxxxyyy_1, g_0_xxxxxx_0_xxxxxyyz_0, g_0_xxxxxx_0_xxxxxyyz_1, g_0_xxxxxx_0_xxxxxyz_1, g_0_xxxxxx_0_xxxxxyzz_0, g_0_xxxxxx_0_xxxxxyzz_1, g_0_xxxxxx_0_xxxxxzz_1, g_0_xxxxxx_0_xxxxxzzz_0, g_0_xxxxxx_0_xxxxxzzz_1, g_0_xxxxxx_0_xxxxyyy_1, g_0_xxxxxx_0_xxxxyyyy_0, g_0_xxxxxx_0_xxxxyyyy_1, g_0_xxxxxx_0_xxxxyyyz_0, g_0_xxxxxx_0_xxxxyyyz_1, g_0_xxxxxx_0_xxxxyyz_1, g_0_xxxxxx_0_xxxxyyzz_0, g_0_xxxxxx_0_xxxxyyzz_1, g_0_xxxxxx_0_xxxxyzz_1, g_0_xxxxxx_0_xxxxyzzz_0, g_0_xxxxxx_0_xxxxyzzz_1, g_0_xxxxxx_0_xxxxzzz_1, g_0_xxxxxx_0_xxxxzzzz_0, g_0_xxxxxx_0_xxxxzzzz_1, g_0_xxxxxx_0_xxxyyyy_1, g_0_xxxxxx_0_xxxyyyyy_0, g_0_xxxxxx_0_xxxyyyyy_1, g_0_xxxxxx_0_xxxyyyyz_0, g_0_xxxxxx_0_xxxyyyyz_1, g_0_xxxxxx_0_xxxyyyz_1, g_0_xxxxxx_0_xxxyyyzz_0, g_0_xxxxxx_0_xxxyyyzz_1, g_0_xxxxxx_0_xxxyyzz_1, g_0_xxxxxx_0_xxxyyzzz_0, g_0_xxxxxx_0_xxxyyzzz_1, g_0_xxxxxx_0_xxxyzzz_1, g_0_xxxxxx_0_xxxyzzzz_0, g_0_xxxxxx_0_xxxyzzzz_1, g_0_xxxxxx_0_xxxzzzz_1, g_0_xxxxxx_0_xxxzzzzz_0, g_0_xxxxxx_0_xxxzzzzz_1, g_0_xxxxxx_0_xxyyyyy_1, g_0_xxxxxx_0_xxyyyyyy_0, g_0_xxxxxx_0_xxyyyyyy_1, g_0_xxxxxx_0_xxyyyyyz_0, g_0_xxxxxx_0_xxyyyyyz_1, g_0_xxxxxx_0_xxyyyyz_1, g_0_xxxxxx_0_xxyyyyzz_0, g_0_xxxxxx_0_xxyyyyzz_1, g_0_xxxxxx_0_xxyyyzz_1, g_0_xxxxxx_0_xxyyyzzz_0, g_0_xxxxxx_0_xxyyyzzz_1, g_0_xxxxxx_0_xxyyzzz_1, g_0_xxxxxx_0_xxyyzzzz_0, g_0_xxxxxx_0_xxyyzzzz_1, g_0_xxxxxx_0_xxyzzzz_1, g_0_xxxxxx_0_xxyzzzzz_0, g_0_xxxxxx_0_xxyzzzzz_1, g_0_xxxxxx_0_xxzzzzz_1, g_0_xxxxxx_0_xxzzzzzz_0, g_0_xxxxxx_0_xxzzzzzz_1, g_0_xxxxxx_0_xyyyyyy_1, g_0_xxxxxx_0_xyyyyyyy_0, g_0_xxxxxx_0_xyyyyyyy_1, g_0_xxxxxx_0_xyyyyyyz_0, g_0_xxxxxx_0_xyyyyyyz_1, g_0_xxxxxx_0_xyyyyyz_1, g_0_xxxxxx_0_xyyyyyzz_0, g_0_xxxxxx_0_xyyyyyzz_1, g_0_xxxxxx_0_xyyyyzz_1, g_0_xxxxxx_0_xyyyyzzz_0, g_0_xxxxxx_0_xyyyyzzz_1, g_0_xxxxxx_0_xyyyzzz_1, g_0_xxxxxx_0_xyyyzzzz_0, g_0_xxxxxx_0_xyyyzzzz_1, g_0_xxxxxx_0_xyyzzzz_1, g_0_xxxxxx_0_xyyzzzzz_0, g_0_xxxxxx_0_xyyzzzzz_1, g_0_xxxxxx_0_xyzzzzz_1, g_0_xxxxxx_0_xyzzzzzz_0, g_0_xxxxxx_0_xyzzzzzz_1, g_0_xxxxxx_0_xzzzzzz_1, g_0_xxxxxx_0_xzzzzzzz_0, g_0_xxxxxx_0_xzzzzzzz_1, g_0_xxxxxx_0_yyyyyyy_1, g_0_xxxxxx_0_yyyyyyyy_0, g_0_xxxxxx_0_yyyyyyyy_1, g_0_xxxxxx_0_yyyyyyyz_0, g_0_xxxxxx_0_yyyyyyyz_1, g_0_xxxxxx_0_yyyyyyz_1, g_0_xxxxxx_0_yyyyyyzz_0, g_0_xxxxxx_0_yyyyyyzz_1, g_0_xxxxxx_0_yyyyyzz_1, g_0_xxxxxx_0_yyyyyzzz_0, g_0_xxxxxx_0_yyyyyzzz_1, g_0_xxxxxx_0_yyyyzzz_1, g_0_xxxxxx_0_yyyyzzzz_0, g_0_xxxxxx_0_yyyyzzzz_1, g_0_xxxxxx_0_yyyzzzz_1, g_0_xxxxxx_0_yyyzzzzz_0, g_0_xxxxxx_0_yyyzzzzz_1, g_0_xxxxxx_0_yyzzzzz_1, g_0_xxxxxx_0_yyzzzzzz_0, g_0_xxxxxx_0_yyzzzzzz_1, g_0_xxxxxx_0_yzzzzzz_1, g_0_xxxxxx_0_yzzzzzzz_0, g_0_xxxxxx_0_yzzzzzzz_1, g_0_xxxxxx_0_zzzzzzz_1, g_0_xxxxxx_0_zzzzzzzz_0, g_0_xxxxxx_0_zzzzzzzz_1, g_0_xxxxxxx_0_xxxxxxxx_0, g_0_xxxxxxx_0_xxxxxxxy_0, g_0_xxxxxxx_0_xxxxxxxz_0, g_0_xxxxxxx_0_xxxxxxyy_0, g_0_xxxxxxx_0_xxxxxxyz_0, g_0_xxxxxxx_0_xxxxxxzz_0, g_0_xxxxxxx_0_xxxxxyyy_0, g_0_xxxxxxx_0_xxxxxyyz_0, g_0_xxxxxxx_0_xxxxxyzz_0, g_0_xxxxxxx_0_xxxxxzzz_0, g_0_xxxxxxx_0_xxxxyyyy_0, g_0_xxxxxxx_0_xxxxyyyz_0, g_0_xxxxxxx_0_xxxxyyzz_0, g_0_xxxxxxx_0_xxxxyzzz_0, g_0_xxxxxxx_0_xxxxzzzz_0, g_0_xxxxxxx_0_xxxyyyyy_0, g_0_xxxxxxx_0_xxxyyyyz_0, g_0_xxxxxxx_0_xxxyyyzz_0, g_0_xxxxxxx_0_xxxyyzzz_0, g_0_xxxxxxx_0_xxxyzzzz_0, g_0_xxxxxxx_0_xxxzzzzz_0, g_0_xxxxxxx_0_xxyyyyyy_0, g_0_xxxxxxx_0_xxyyyyyz_0, g_0_xxxxxxx_0_xxyyyyzz_0, g_0_xxxxxxx_0_xxyyyzzz_0, g_0_xxxxxxx_0_xxyyzzzz_0, g_0_xxxxxxx_0_xxyzzzzz_0, g_0_xxxxxxx_0_xxzzzzzz_0, g_0_xxxxxxx_0_xyyyyyyy_0, g_0_xxxxxxx_0_xyyyyyyz_0, g_0_xxxxxxx_0_xyyyyyzz_0, g_0_xxxxxxx_0_xyyyyzzz_0, g_0_xxxxxxx_0_xyyyzzzz_0, g_0_xxxxxxx_0_xyyzzzzz_0, g_0_xxxxxxx_0_xyzzzzzz_0, g_0_xxxxxxx_0_xzzzzzzz_0, g_0_xxxxxxx_0_yyyyyyyy_0, g_0_xxxxxxx_0_yyyyyyyz_0, g_0_xxxxxxx_0_yyyyyyzz_0, g_0_xxxxxxx_0_yyyyyzzz_0, g_0_xxxxxxx_0_yyyyzzzz_0, g_0_xxxxxxx_0_yyyzzzzz_0, g_0_xxxxxxx_0_yyzzzzzz_0, g_0_xxxxxxx_0_yzzzzzzz_0, g_0_xxxxxxx_0_zzzzzzzz_0, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxxxxx_0_xxxxxxxx_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxxx_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxxx_1[i] * fti_ab_0 + 8.0 * g_0_xxxxxx_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxxx_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxxxy_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxxy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxxy_1[i] * fti_ab_0 + 7.0 * g_0_xxxxxx_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxxy_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxxxz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxxz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxxz_1[i] * fti_ab_0 + 7.0 * g_0_xxxxxx_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxxz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxxyy_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxyy_1[i] * fti_ab_0 + 6.0 * g_0_xxxxxx_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxyy_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxxyz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxxxxx_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxyz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxxzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxxzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxxzz_1[i] * fti_ab_0 + 6.0 * g_0_xxxxxx_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxyyy_0[i] = 6.0 * g_0_xxxxx_0_xxxxxyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxyyy_1[i] * fti_ab_0 + 5.0 * g_0_xxxxxx_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyyy_0[i] * pb_x + g_0_xxxxxx_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxyyz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxxx_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyyz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxyzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxxx_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxxzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxxzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxxzzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxxx_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxyyyy_0[i] = 6.0 * g_0_xxxxx_0_xxxxyyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_xxxxxx_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyyy_0[i] * pb_x + g_0_xxxxxx_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxyyyz_0[i] = 6.0 * g_0_xxxxx_0_xxxxyyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxxx_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyyz_0[i] * pb_x + g_0_xxxxxx_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxyyzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxyyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxxx_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxyzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxyzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxxx_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxxzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxxzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxxx_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxyyyyy_0[i] = 6.0 * g_0_xxxxx_0_xxxyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxyyyyy_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyyy_0[i] * pb_x + g_0_xxxxxx_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxyyyyz_0[i] = 6.0 * g_0_xxxxx_0_xxxyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyyz_0[i] * pb_x + g_0_xxxxxx_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxyyyzz_0[i] = 6.0 * g_0_xxxxx_0_xxxyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyzz_0[i] * pb_x + g_0_xxxxxx_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxyyzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxyzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxxzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxxzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxxzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxxx_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyyyyyy_0[i] = 6.0 * g_0_xxxxx_0_xxyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyyyyyy_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyyy_0[i] * pb_x + g_0_xxxxxx_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyyyyyz_0[i] = 6.0 * g_0_xxxxx_0_xxyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyyz_0[i] * pb_x + g_0_xxxxxx_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyyyyzz_0[i] = 6.0 * g_0_xxxxx_0_xxyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyzz_0[i] * pb_x + g_0_xxxxxx_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyyyzzz_0[i] = 6.0 * g_0_xxxxx_0_xxyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyzzz_0[i] * pb_x + g_0_xxxxxx_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyyzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxyzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xxzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xxzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xxzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxxx_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyyyyyy_0[i] = 6.0 * g_0_xxxxx_0_xyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyyy_0[i] * pb_x + g_0_xxxxxx_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyyyyyz_0[i] = 6.0 * g_0_xxxxx_0_xyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyyz_0[i] * pb_x + g_0_xxxxxx_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyyyyzz_0[i] = 6.0 * g_0_xxxxx_0_xyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyzz_0[i] * pb_x + g_0_xxxxxx_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyyyzzz_0[i] = 6.0 * g_0_xxxxx_0_xyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyzzz_0[i] * pb_x + g_0_xxxxxx_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyyzzzz_0[i] = 6.0 * g_0_xxxxx_0_xyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyzzzz_0[i] * pb_x + g_0_xxxxxx_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyyzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xyzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_xzzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_xzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xzzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyyyyyy_0[i] = 6.0 * g_0_xxxxx_0_yyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyyyy_0[i] * pb_x + g_0_xxxxxx_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyyyyyz_0[i] = 6.0 * g_0_xxxxx_0_yyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyyyz_0[i] * pb_x + g_0_xxxxxx_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyyyyzz_0[i] = 6.0 * g_0_xxxxx_0_yyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyyzz_0[i] * pb_x + g_0_xxxxxx_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyyyzzz_0[i] = 6.0 * g_0_xxxxx_0_yyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyyzzz_0[i] * pb_x + g_0_xxxxxx_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyyzzzz_0[i] = 6.0 * g_0_xxxxx_0_yyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyyzzzz_0[i] * pb_x + g_0_xxxxxx_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyyzzzzz_0[i] = 6.0 * g_0_xxxxx_0_yyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyyzzzzz_0[i] * pb_x + g_0_xxxxxx_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yyzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_yyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yyzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_yzzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_yzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_yzzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxxx_0_zzzzzzzz_0[i] = 6.0 * g_0_xxxxx_0_zzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_xxxxx_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxx_0_zzzzzzzz_0[i] * pb_x + g_0_xxxxxx_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 45-90 components of targeted buffer : SKSL

    auto g_0_xxxxxxy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 45);

    auto g_0_xxxxxxy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 46);

    auto g_0_xxxxxxy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 47);

    auto g_0_xxxxxxy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 48);

    auto g_0_xxxxxxy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 49);

    auto g_0_xxxxxxy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 50);

    auto g_0_xxxxxxy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 51);

    auto g_0_xxxxxxy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 52);

    auto g_0_xxxxxxy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 53);

    auto g_0_xxxxxxy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 54);

    auto g_0_xxxxxxy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 55);

    auto g_0_xxxxxxy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 56);

    auto g_0_xxxxxxy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 57);

    auto g_0_xxxxxxy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 58);

    auto g_0_xxxxxxy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 59);

    auto g_0_xxxxxxy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 60);

    auto g_0_xxxxxxy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 61);

    auto g_0_xxxxxxy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 62);

    auto g_0_xxxxxxy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 63);

    auto g_0_xxxxxxy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 64);

    auto g_0_xxxxxxy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 65);

    auto g_0_xxxxxxy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 66);

    auto g_0_xxxxxxy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 67);

    auto g_0_xxxxxxy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 68);

    auto g_0_xxxxxxy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 69);

    auto g_0_xxxxxxy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 70);

    auto g_0_xxxxxxy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 71);

    auto g_0_xxxxxxy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 72);

    auto g_0_xxxxxxy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 73);

    auto g_0_xxxxxxy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 74);

    auto g_0_xxxxxxy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 75);

    auto g_0_xxxxxxy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 76);

    auto g_0_xxxxxxy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 77);

    auto g_0_xxxxxxy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 78);

    auto g_0_xxxxxxy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 79);

    auto g_0_xxxxxxy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 80);

    auto g_0_xxxxxxy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 81);

    auto g_0_xxxxxxy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 82);

    auto g_0_xxxxxxy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 83);

    auto g_0_xxxxxxy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 84);

    auto g_0_xxxxxxy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 85);

    auto g_0_xxxxxxy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 86);

    auto g_0_xxxxxxy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 87);

    auto g_0_xxxxxxy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 88);

    auto g_0_xxxxxxy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 89);

    #pragma omp simd aligned(g_0_xxxxxx_0_xxxxxxx_1, g_0_xxxxxx_0_xxxxxxxx_0, g_0_xxxxxx_0_xxxxxxxx_1, g_0_xxxxxx_0_xxxxxxxy_0, g_0_xxxxxx_0_xxxxxxxy_1, g_0_xxxxxx_0_xxxxxxxz_0, g_0_xxxxxx_0_xxxxxxxz_1, g_0_xxxxxx_0_xxxxxxy_1, g_0_xxxxxx_0_xxxxxxyy_0, g_0_xxxxxx_0_xxxxxxyy_1, g_0_xxxxxx_0_xxxxxxyz_0, g_0_xxxxxx_0_xxxxxxyz_1, g_0_xxxxxx_0_xxxxxxz_1, g_0_xxxxxx_0_xxxxxxzz_0, g_0_xxxxxx_0_xxxxxxzz_1, g_0_xxxxxx_0_xxxxxyy_1, g_0_xxxxxx_0_xxxxxyyy_0, g_0_xxxxxx_0_xxxxxyyy_1, g_0_xxxxxx_0_xxxxxyyz_0, g_0_xxxxxx_0_xxxxxyyz_1, g_0_xxxxxx_0_xxxxxyz_1, g_0_xxxxxx_0_xxxxxyzz_0, g_0_xxxxxx_0_xxxxxyzz_1, g_0_xxxxxx_0_xxxxxzz_1, g_0_xxxxxx_0_xxxxxzzz_0, g_0_xxxxxx_0_xxxxxzzz_1, g_0_xxxxxx_0_xxxxyyy_1, g_0_xxxxxx_0_xxxxyyyy_0, g_0_xxxxxx_0_xxxxyyyy_1, g_0_xxxxxx_0_xxxxyyyz_0, g_0_xxxxxx_0_xxxxyyyz_1, g_0_xxxxxx_0_xxxxyyz_1, g_0_xxxxxx_0_xxxxyyzz_0, g_0_xxxxxx_0_xxxxyyzz_1, g_0_xxxxxx_0_xxxxyzz_1, g_0_xxxxxx_0_xxxxyzzz_0, g_0_xxxxxx_0_xxxxyzzz_1, g_0_xxxxxx_0_xxxxzzz_1, g_0_xxxxxx_0_xxxxzzzz_0, g_0_xxxxxx_0_xxxxzzzz_1, g_0_xxxxxx_0_xxxyyyy_1, g_0_xxxxxx_0_xxxyyyyy_0, g_0_xxxxxx_0_xxxyyyyy_1, g_0_xxxxxx_0_xxxyyyyz_0, g_0_xxxxxx_0_xxxyyyyz_1, g_0_xxxxxx_0_xxxyyyz_1, g_0_xxxxxx_0_xxxyyyzz_0, g_0_xxxxxx_0_xxxyyyzz_1, g_0_xxxxxx_0_xxxyyzz_1, g_0_xxxxxx_0_xxxyyzzz_0, g_0_xxxxxx_0_xxxyyzzz_1, g_0_xxxxxx_0_xxxyzzz_1, g_0_xxxxxx_0_xxxyzzzz_0, g_0_xxxxxx_0_xxxyzzzz_1, g_0_xxxxxx_0_xxxzzzz_1, g_0_xxxxxx_0_xxxzzzzz_0, g_0_xxxxxx_0_xxxzzzzz_1, g_0_xxxxxx_0_xxyyyyy_1, g_0_xxxxxx_0_xxyyyyyy_0, g_0_xxxxxx_0_xxyyyyyy_1, g_0_xxxxxx_0_xxyyyyyz_0, g_0_xxxxxx_0_xxyyyyyz_1, g_0_xxxxxx_0_xxyyyyz_1, g_0_xxxxxx_0_xxyyyyzz_0, g_0_xxxxxx_0_xxyyyyzz_1, g_0_xxxxxx_0_xxyyyzz_1, g_0_xxxxxx_0_xxyyyzzz_0, g_0_xxxxxx_0_xxyyyzzz_1, g_0_xxxxxx_0_xxyyzzz_1, g_0_xxxxxx_0_xxyyzzzz_0, g_0_xxxxxx_0_xxyyzzzz_1, g_0_xxxxxx_0_xxyzzzz_1, g_0_xxxxxx_0_xxyzzzzz_0, g_0_xxxxxx_0_xxyzzzzz_1, g_0_xxxxxx_0_xxzzzzz_1, g_0_xxxxxx_0_xxzzzzzz_0, g_0_xxxxxx_0_xxzzzzzz_1, g_0_xxxxxx_0_xyyyyyy_1, g_0_xxxxxx_0_xyyyyyyy_0, g_0_xxxxxx_0_xyyyyyyy_1, g_0_xxxxxx_0_xyyyyyyz_0, g_0_xxxxxx_0_xyyyyyyz_1, g_0_xxxxxx_0_xyyyyyz_1, g_0_xxxxxx_0_xyyyyyzz_0, g_0_xxxxxx_0_xyyyyyzz_1, g_0_xxxxxx_0_xyyyyzz_1, g_0_xxxxxx_0_xyyyyzzz_0, g_0_xxxxxx_0_xyyyyzzz_1, g_0_xxxxxx_0_xyyyzzz_1, g_0_xxxxxx_0_xyyyzzzz_0, g_0_xxxxxx_0_xyyyzzzz_1, g_0_xxxxxx_0_xyyzzzz_1, g_0_xxxxxx_0_xyyzzzzz_0, g_0_xxxxxx_0_xyyzzzzz_1, g_0_xxxxxx_0_xyzzzzz_1, g_0_xxxxxx_0_xyzzzzzz_0, g_0_xxxxxx_0_xyzzzzzz_1, g_0_xxxxxx_0_xzzzzzz_1, g_0_xxxxxx_0_xzzzzzzz_0, g_0_xxxxxx_0_xzzzzzzz_1, g_0_xxxxxx_0_yyyyyyy_1, g_0_xxxxxx_0_yyyyyyyy_0, g_0_xxxxxx_0_yyyyyyyy_1, g_0_xxxxxx_0_yyyyyyyz_0, g_0_xxxxxx_0_yyyyyyyz_1, g_0_xxxxxx_0_yyyyyyz_1, g_0_xxxxxx_0_yyyyyyzz_0, g_0_xxxxxx_0_yyyyyyzz_1, g_0_xxxxxx_0_yyyyyzz_1, g_0_xxxxxx_0_yyyyyzzz_0, g_0_xxxxxx_0_yyyyyzzz_1, g_0_xxxxxx_0_yyyyzzz_1, g_0_xxxxxx_0_yyyyzzzz_0, g_0_xxxxxx_0_yyyyzzzz_1, g_0_xxxxxx_0_yyyzzzz_1, g_0_xxxxxx_0_yyyzzzzz_0, g_0_xxxxxx_0_yyyzzzzz_1, g_0_xxxxxx_0_yyzzzzz_1, g_0_xxxxxx_0_yyzzzzzz_0, g_0_xxxxxx_0_yyzzzzzz_1, g_0_xxxxxx_0_yzzzzzz_1, g_0_xxxxxx_0_yzzzzzzz_0, g_0_xxxxxx_0_yzzzzzzz_1, g_0_xxxxxx_0_zzzzzzz_1, g_0_xxxxxx_0_zzzzzzzz_0, g_0_xxxxxx_0_zzzzzzzz_1, g_0_xxxxxxy_0_xxxxxxxx_0, g_0_xxxxxxy_0_xxxxxxxy_0, g_0_xxxxxxy_0_xxxxxxxz_0, g_0_xxxxxxy_0_xxxxxxyy_0, g_0_xxxxxxy_0_xxxxxxyz_0, g_0_xxxxxxy_0_xxxxxxzz_0, g_0_xxxxxxy_0_xxxxxyyy_0, g_0_xxxxxxy_0_xxxxxyyz_0, g_0_xxxxxxy_0_xxxxxyzz_0, g_0_xxxxxxy_0_xxxxxzzz_0, g_0_xxxxxxy_0_xxxxyyyy_0, g_0_xxxxxxy_0_xxxxyyyz_0, g_0_xxxxxxy_0_xxxxyyzz_0, g_0_xxxxxxy_0_xxxxyzzz_0, g_0_xxxxxxy_0_xxxxzzzz_0, g_0_xxxxxxy_0_xxxyyyyy_0, g_0_xxxxxxy_0_xxxyyyyz_0, g_0_xxxxxxy_0_xxxyyyzz_0, g_0_xxxxxxy_0_xxxyyzzz_0, g_0_xxxxxxy_0_xxxyzzzz_0, g_0_xxxxxxy_0_xxxzzzzz_0, g_0_xxxxxxy_0_xxyyyyyy_0, g_0_xxxxxxy_0_xxyyyyyz_0, g_0_xxxxxxy_0_xxyyyyzz_0, g_0_xxxxxxy_0_xxyyyzzz_0, g_0_xxxxxxy_0_xxyyzzzz_0, g_0_xxxxxxy_0_xxyzzzzz_0, g_0_xxxxxxy_0_xxzzzzzz_0, g_0_xxxxxxy_0_xyyyyyyy_0, g_0_xxxxxxy_0_xyyyyyyz_0, g_0_xxxxxxy_0_xyyyyyzz_0, g_0_xxxxxxy_0_xyyyyzzz_0, g_0_xxxxxxy_0_xyyyzzzz_0, g_0_xxxxxxy_0_xyyzzzzz_0, g_0_xxxxxxy_0_xyzzzzzz_0, g_0_xxxxxxy_0_xzzzzzzz_0, g_0_xxxxxxy_0_yyyyyyyy_0, g_0_xxxxxxy_0_yyyyyyyz_0, g_0_xxxxxxy_0_yyyyyyzz_0, g_0_xxxxxxy_0_yyyyyzzz_0, g_0_xxxxxxy_0_yyyyzzzz_0, g_0_xxxxxxy_0_yyyzzzzz_0, g_0_xxxxxxy_0_yyzzzzzz_0, g_0_xxxxxxy_0_yzzzzzzz_0, g_0_xxxxxxy_0_zzzzzzzz_0, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxxxxy_0_xxxxxxxx_0[i] = g_0_xxxxxx_0_xxxxxxxx_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxxxy_0[i] = g_0_xxxxxx_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxxy_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxxxz_0[i] = g_0_xxxxxx_0_xxxxxxxz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxxyy_0[i] = 2.0 * g_0_xxxxxx_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxyy_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxxyz_0[i] = g_0_xxxxxx_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxyz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxxzz_0[i] = g_0_xxxxxx_0_xxxxxxzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxyyy_0[i] = 3.0 * g_0_xxxxxx_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyyy_0[i] * pb_y + g_0_xxxxxx_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxyyz_0[i] = 2.0 * g_0_xxxxxx_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyyz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxyzz_0[i] = g_0_xxxxxx_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxxzzz_0[i] = g_0_xxxxxx_0_xxxxxzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxyyyy_0[i] = 4.0 * g_0_xxxxxx_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyyy_0[i] * pb_y + g_0_xxxxxx_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxyyyz_0[i] = 3.0 * g_0_xxxxxx_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyyz_0[i] * pb_y + g_0_xxxxxx_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxyzzz_0[i] = g_0_xxxxxx_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxxzzzz_0[i] = g_0_xxxxxx_0_xxxxzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxyyyyy_0[i] = 5.0 * g_0_xxxxxx_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyyy_0[i] * pb_y + g_0_xxxxxx_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxxxx_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyyz_0[i] * pb_y + g_0_xxxxxx_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxyyyzz_0[i] = 3.0 * g_0_xxxxxx_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyzz_0[i] * pb_y + g_0_xxxxxx_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxyyzzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxyzzzz_0[i] = g_0_xxxxxx_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxxzzzzz_0[i] = g_0_xxxxxx_0_xxxzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyyyyyy_0[i] = 6.0 * g_0_xxxxxx_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyyy_0[i] * pb_y + g_0_xxxxxx_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyyyyyz_0[i] = 5.0 * g_0_xxxxxx_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyyz_0[i] * pb_y + g_0_xxxxxx_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxxxx_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyzz_0[i] * pb_y + g_0_xxxxxx_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxxxx_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyzzz_0[i] * pb_y + g_0_xxxxxx_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyyzzzz_0[i] = 2.0 * g_0_xxxxxx_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxyzzzzz_0[i] = g_0_xxxxxx_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xxzzzzzz_0[i] = g_0_xxxxxx_0_xxzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyyyyyy_0[i] = 7.0 * g_0_xxxxxx_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyyy_0[i] * pb_y + g_0_xxxxxx_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyyyyyz_0[i] = 6.0 * g_0_xxxxxx_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyyz_0[i] * pb_y + g_0_xxxxxx_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyyyyzz_0[i] = 5.0 * g_0_xxxxxx_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyzz_0[i] * pb_y + g_0_xxxxxx_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxxxx_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyzzz_0[i] * pb_y + g_0_xxxxxx_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyyzzzz_0[i] = 3.0 * g_0_xxxxxx_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyzzzz_0[i] * pb_y + g_0_xxxxxx_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyyzzzzz_0[i] = 2.0 * g_0_xxxxxx_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xyzzzzzz_0[i] = g_0_xxxxxx_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_xzzzzzzz_0[i] = g_0_xxxxxx_0_xzzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyyyyyy_0[i] = 8.0 * g_0_xxxxxx_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyyyy_0[i] * pb_y + g_0_xxxxxx_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyyyyyz_0[i] = 7.0 * g_0_xxxxxx_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyyyz_0[i] * pb_y + g_0_xxxxxx_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyyyyzz_0[i] = 6.0 * g_0_xxxxxx_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyyzz_0[i] * pb_y + g_0_xxxxxx_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyyyzzz_0[i] = 5.0 * g_0_xxxxxx_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyzzz_0[i] * pb_y + g_0_xxxxxx_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxxxx_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyzzzz_0[i] * pb_y + g_0_xxxxxx_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyyzzzzz_0[i] = 3.0 * g_0_xxxxxx_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyzzzzz_0[i] * pb_y + g_0_xxxxxx_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yyzzzzzz_0[i] = 2.0 * g_0_xxxxxx_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_yzzzzzzz_0[i] = g_0_xxxxxx_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yzzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxxy_0_zzzzzzzz_0[i] = g_0_xxxxxx_0_zzzzzzzz_0[i] * pb_y + g_0_xxxxxx_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 90-135 components of targeted buffer : SKSL

    auto g_0_xxxxxxz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 90);

    auto g_0_xxxxxxz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 91);

    auto g_0_xxxxxxz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 92);

    auto g_0_xxxxxxz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 93);

    auto g_0_xxxxxxz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 94);

    auto g_0_xxxxxxz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 95);

    auto g_0_xxxxxxz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 96);

    auto g_0_xxxxxxz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 97);

    auto g_0_xxxxxxz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 98);

    auto g_0_xxxxxxz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 99);

    auto g_0_xxxxxxz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 100);

    auto g_0_xxxxxxz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 101);

    auto g_0_xxxxxxz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 102);

    auto g_0_xxxxxxz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 103);

    auto g_0_xxxxxxz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 104);

    auto g_0_xxxxxxz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 105);

    auto g_0_xxxxxxz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 106);

    auto g_0_xxxxxxz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 107);

    auto g_0_xxxxxxz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 108);

    auto g_0_xxxxxxz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 109);

    auto g_0_xxxxxxz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 110);

    auto g_0_xxxxxxz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 111);

    auto g_0_xxxxxxz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 112);

    auto g_0_xxxxxxz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 113);

    auto g_0_xxxxxxz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 114);

    auto g_0_xxxxxxz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 115);

    auto g_0_xxxxxxz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 116);

    auto g_0_xxxxxxz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 117);

    auto g_0_xxxxxxz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 118);

    auto g_0_xxxxxxz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 119);

    auto g_0_xxxxxxz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 120);

    auto g_0_xxxxxxz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 121);

    auto g_0_xxxxxxz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 122);

    auto g_0_xxxxxxz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 123);

    auto g_0_xxxxxxz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 124);

    auto g_0_xxxxxxz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 125);

    auto g_0_xxxxxxz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 126);

    auto g_0_xxxxxxz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 127);

    auto g_0_xxxxxxz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 128);

    auto g_0_xxxxxxz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 129);

    auto g_0_xxxxxxz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 130);

    auto g_0_xxxxxxz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 131);

    auto g_0_xxxxxxz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 132);

    auto g_0_xxxxxxz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 133);

    auto g_0_xxxxxxz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 134);

    #pragma omp simd aligned(g_0_xxxxxx_0_xxxxxxx_1, g_0_xxxxxx_0_xxxxxxxx_0, g_0_xxxxxx_0_xxxxxxxx_1, g_0_xxxxxx_0_xxxxxxxy_0, g_0_xxxxxx_0_xxxxxxxy_1, g_0_xxxxxx_0_xxxxxxxz_0, g_0_xxxxxx_0_xxxxxxxz_1, g_0_xxxxxx_0_xxxxxxy_1, g_0_xxxxxx_0_xxxxxxyy_0, g_0_xxxxxx_0_xxxxxxyy_1, g_0_xxxxxx_0_xxxxxxyz_0, g_0_xxxxxx_0_xxxxxxyz_1, g_0_xxxxxx_0_xxxxxxz_1, g_0_xxxxxx_0_xxxxxxzz_0, g_0_xxxxxx_0_xxxxxxzz_1, g_0_xxxxxx_0_xxxxxyy_1, g_0_xxxxxx_0_xxxxxyyy_0, g_0_xxxxxx_0_xxxxxyyy_1, g_0_xxxxxx_0_xxxxxyyz_0, g_0_xxxxxx_0_xxxxxyyz_1, g_0_xxxxxx_0_xxxxxyz_1, g_0_xxxxxx_0_xxxxxyzz_0, g_0_xxxxxx_0_xxxxxyzz_1, g_0_xxxxxx_0_xxxxxzz_1, g_0_xxxxxx_0_xxxxxzzz_0, g_0_xxxxxx_0_xxxxxzzz_1, g_0_xxxxxx_0_xxxxyyy_1, g_0_xxxxxx_0_xxxxyyyy_0, g_0_xxxxxx_0_xxxxyyyy_1, g_0_xxxxxx_0_xxxxyyyz_0, g_0_xxxxxx_0_xxxxyyyz_1, g_0_xxxxxx_0_xxxxyyz_1, g_0_xxxxxx_0_xxxxyyzz_0, g_0_xxxxxx_0_xxxxyyzz_1, g_0_xxxxxx_0_xxxxyzz_1, g_0_xxxxxx_0_xxxxyzzz_0, g_0_xxxxxx_0_xxxxyzzz_1, g_0_xxxxxx_0_xxxxzzz_1, g_0_xxxxxx_0_xxxxzzzz_0, g_0_xxxxxx_0_xxxxzzzz_1, g_0_xxxxxx_0_xxxyyyy_1, g_0_xxxxxx_0_xxxyyyyy_0, g_0_xxxxxx_0_xxxyyyyy_1, g_0_xxxxxx_0_xxxyyyyz_0, g_0_xxxxxx_0_xxxyyyyz_1, g_0_xxxxxx_0_xxxyyyz_1, g_0_xxxxxx_0_xxxyyyzz_0, g_0_xxxxxx_0_xxxyyyzz_1, g_0_xxxxxx_0_xxxyyzz_1, g_0_xxxxxx_0_xxxyyzzz_0, g_0_xxxxxx_0_xxxyyzzz_1, g_0_xxxxxx_0_xxxyzzz_1, g_0_xxxxxx_0_xxxyzzzz_0, g_0_xxxxxx_0_xxxyzzzz_1, g_0_xxxxxx_0_xxxzzzz_1, g_0_xxxxxx_0_xxxzzzzz_0, g_0_xxxxxx_0_xxxzzzzz_1, g_0_xxxxxx_0_xxyyyyy_1, g_0_xxxxxx_0_xxyyyyyy_0, g_0_xxxxxx_0_xxyyyyyy_1, g_0_xxxxxx_0_xxyyyyyz_0, g_0_xxxxxx_0_xxyyyyyz_1, g_0_xxxxxx_0_xxyyyyz_1, g_0_xxxxxx_0_xxyyyyzz_0, g_0_xxxxxx_0_xxyyyyzz_1, g_0_xxxxxx_0_xxyyyzz_1, g_0_xxxxxx_0_xxyyyzzz_0, g_0_xxxxxx_0_xxyyyzzz_1, g_0_xxxxxx_0_xxyyzzz_1, g_0_xxxxxx_0_xxyyzzzz_0, g_0_xxxxxx_0_xxyyzzzz_1, g_0_xxxxxx_0_xxyzzzz_1, g_0_xxxxxx_0_xxyzzzzz_0, g_0_xxxxxx_0_xxyzzzzz_1, g_0_xxxxxx_0_xxzzzzz_1, g_0_xxxxxx_0_xxzzzzzz_0, g_0_xxxxxx_0_xxzzzzzz_1, g_0_xxxxxx_0_xyyyyyy_1, g_0_xxxxxx_0_xyyyyyyy_0, g_0_xxxxxx_0_xyyyyyyy_1, g_0_xxxxxx_0_xyyyyyyz_0, g_0_xxxxxx_0_xyyyyyyz_1, g_0_xxxxxx_0_xyyyyyz_1, g_0_xxxxxx_0_xyyyyyzz_0, g_0_xxxxxx_0_xyyyyyzz_1, g_0_xxxxxx_0_xyyyyzz_1, g_0_xxxxxx_0_xyyyyzzz_0, g_0_xxxxxx_0_xyyyyzzz_1, g_0_xxxxxx_0_xyyyzzz_1, g_0_xxxxxx_0_xyyyzzzz_0, g_0_xxxxxx_0_xyyyzzzz_1, g_0_xxxxxx_0_xyyzzzz_1, g_0_xxxxxx_0_xyyzzzzz_0, g_0_xxxxxx_0_xyyzzzzz_1, g_0_xxxxxx_0_xyzzzzz_1, g_0_xxxxxx_0_xyzzzzzz_0, g_0_xxxxxx_0_xyzzzzzz_1, g_0_xxxxxx_0_xzzzzzz_1, g_0_xxxxxx_0_xzzzzzzz_0, g_0_xxxxxx_0_xzzzzzzz_1, g_0_xxxxxx_0_yyyyyyy_1, g_0_xxxxxx_0_yyyyyyyy_0, g_0_xxxxxx_0_yyyyyyyy_1, g_0_xxxxxx_0_yyyyyyyz_0, g_0_xxxxxx_0_yyyyyyyz_1, g_0_xxxxxx_0_yyyyyyz_1, g_0_xxxxxx_0_yyyyyyzz_0, g_0_xxxxxx_0_yyyyyyzz_1, g_0_xxxxxx_0_yyyyyzz_1, g_0_xxxxxx_0_yyyyyzzz_0, g_0_xxxxxx_0_yyyyyzzz_1, g_0_xxxxxx_0_yyyyzzz_1, g_0_xxxxxx_0_yyyyzzzz_0, g_0_xxxxxx_0_yyyyzzzz_1, g_0_xxxxxx_0_yyyzzzz_1, g_0_xxxxxx_0_yyyzzzzz_0, g_0_xxxxxx_0_yyyzzzzz_1, g_0_xxxxxx_0_yyzzzzz_1, g_0_xxxxxx_0_yyzzzzzz_0, g_0_xxxxxx_0_yyzzzzzz_1, g_0_xxxxxx_0_yzzzzzz_1, g_0_xxxxxx_0_yzzzzzzz_0, g_0_xxxxxx_0_yzzzzzzz_1, g_0_xxxxxx_0_zzzzzzz_1, g_0_xxxxxx_0_zzzzzzzz_0, g_0_xxxxxx_0_zzzzzzzz_1, g_0_xxxxxxz_0_xxxxxxxx_0, g_0_xxxxxxz_0_xxxxxxxy_0, g_0_xxxxxxz_0_xxxxxxxz_0, g_0_xxxxxxz_0_xxxxxxyy_0, g_0_xxxxxxz_0_xxxxxxyz_0, g_0_xxxxxxz_0_xxxxxxzz_0, g_0_xxxxxxz_0_xxxxxyyy_0, g_0_xxxxxxz_0_xxxxxyyz_0, g_0_xxxxxxz_0_xxxxxyzz_0, g_0_xxxxxxz_0_xxxxxzzz_0, g_0_xxxxxxz_0_xxxxyyyy_0, g_0_xxxxxxz_0_xxxxyyyz_0, g_0_xxxxxxz_0_xxxxyyzz_0, g_0_xxxxxxz_0_xxxxyzzz_0, g_0_xxxxxxz_0_xxxxzzzz_0, g_0_xxxxxxz_0_xxxyyyyy_0, g_0_xxxxxxz_0_xxxyyyyz_0, g_0_xxxxxxz_0_xxxyyyzz_0, g_0_xxxxxxz_0_xxxyyzzz_0, g_0_xxxxxxz_0_xxxyzzzz_0, g_0_xxxxxxz_0_xxxzzzzz_0, g_0_xxxxxxz_0_xxyyyyyy_0, g_0_xxxxxxz_0_xxyyyyyz_0, g_0_xxxxxxz_0_xxyyyyzz_0, g_0_xxxxxxz_0_xxyyyzzz_0, g_0_xxxxxxz_0_xxyyzzzz_0, g_0_xxxxxxz_0_xxyzzzzz_0, g_0_xxxxxxz_0_xxzzzzzz_0, g_0_xxxxxxz_0_xyyyyyyy_0, g_0_xxxxxxz_0_xyyyyyyz_0, g_0_xxxxxxz_0_xyyyyyzz_0, g_0_xxxxxxz_0_xyyyyzzz_0, g_0_xxxxxxz_0_xyyyzzzz_0, g_0_xxxxxxz_0_xyyzzzzz_0, g_0_xxxxxxz_0_xyzzzzzz_0, g_0_xxxxxxz_0_xzzzzzzz_0, g_0_xxxxxxz_0_yyyyyyyy_0, g_0_xxxxxxz_0_yyyyyyyz_0, g_0_xxxxxxz_0_yyyyyyzz_0, g_0_xxxxxxz_0_yyyyyzzz_0, g_0_xxxxxxz_0_yyyyzzzz_0, g_0_xxxxxxz_0_yyyzzzzz_0, g_0_xxxxxxz_0_yyzzzzzz_0, g_0_xxxxxxz_0_yzzzzzzz_0, g_0_xxxxxxz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxxxxz_0_xxxxxxxx_0[i] = g_0_xxxxxx_0_xxxxxxxx_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxxxy_0[i] = g_0_xxxxxx_0_xxxxxxxy_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxxxz_0[i] = g_0_xxxxxx_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxxz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxxyy_0[i] = g_0_xxxxxx_0_xxxxxxyy_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxxyz_0[i] = g_0_xxxxxx_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxyz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxxzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxxzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxyyy_0[i] = g_0_xxxxxx_0_xxxxxyyy_0[i] * pb_z + g_0_xxxxxx_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxyyz_0[i] = g_0_xxxxxx_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyyz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxyzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxyzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxxzzz_0[i] = 3.0 * g_0_xxxxxx_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxxzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxyyyy_0[i] = g_0_xxxxxx_0_xxxxyyyy_0[i] * pb_z + g_0_xxxxxx_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxyyyz_0[i] = g_0_xxxxxx_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyyz_0[i] * pb_z + g_0_xxxxxx_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyyzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxyzzz_0[i] = 3.0 * g_0_xxxxxx_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxyzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxxzzzz_0[i] = 4.0 * g_0_xxxxxx_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxxzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxyyyyy_0[i] = g_0_xxxxxx_0_xxxyyyyy_0[i] * pb_z + g_0_xxxxxx_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxyyyyz_0[i] = g_0_xxxxxx_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyyz_0[i] * pb_z + g_0_xxxxxx_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxyyyzz_0[i] = 2.0 * g_0_xxxxxx_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyyzz_0[i] * pb_z + g_0_xxxxxx_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxyyzzz_0[i] = 3.0 * g_0_xxxxxx_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyyzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxyzzzz_0[i] = 4.0 * g_0_xxxxxx_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxyzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxxzzzzz_0[i] = 5.0 * g_0_xxxxxx_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxxzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyyyyyy_0[i] = g_0_xxxxxx_0_xxyyyyyy_0[i] * pb_z + g_0_xxxxxx_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyyyyyz_0[i] = g_0_xxxxxx_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyyz_0[i] * pb_z + g_0_xxxxxx_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyyyyzz_0[i] = 2.0 * g_0_xxxxxx_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyyzz_0[i] * pb_z + g_0_xxxxxx_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxxxx_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyyzzz_0[i] * pb_z + g_0_xxxxxx_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyyzzzz_0[i] = 4.0 * g_0_xxxxxx_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyyzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxyzzzzz_0[i] = 5.0 * g_0_xxxxxx_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxyzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xxzzzzzz_0[i] = 6.0 * g_0_xxxxxx_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xxzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyyyyyy_0[i] = g_0_xxxxxx_0_xyyyyyyy_0[i] * pb_z + g_0_xxxxxx_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyyyyyz_0[i] = g_0_xxxxxx_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyyz_0[i] * pb_z + g_0_xxxxxx_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyyyyzz_0[i] = 2.0 * g_0_xxxxxx_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyyzz_0[i] * pb_z + g_0_xxxxxx_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyyyzzz_0[i] = 3.0 * g_0_xxxxxx_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyyzzz_0[i] * pb_z + g_0_xxxxxx_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyyzzzz_0[i] = 4.0 * g_0_xxxxxx_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyyzzzz_0[i] * pb_z + g_0_xxxxxx_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyyzzzzz_0[i] = 5.0 * g_0_xxxxxx_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyyzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xyzzzzzz_0[i] = 6.0 * g_0_xxxxxx_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xyzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_xzzzzzzz_0[i] = 7.0 * g_0_xxxxxx_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_xzzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyyyyyy_0[i] = g_0_xxxxxx_0_yyyyyyyy_0[i] * pb_z + g_0_xxxxxx_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyyyyyz_0[i] = g_0_xxxxxx_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyyyz_0[i] * pb_z + g_0_xxxxxx_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyyyyzz_0[i] = 2.0 * g_0_xxxxxx_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyyzz_0[i] * pb_z + g_0_xxxxxx_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyyyzzz_0[i] = 3.0 * g_0_xxxxxx_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyyzzz_0[i] * pb_z + g_0_xxxxxx_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxxxx_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyyzzzz_0[i] * pb_z + g_0_xxxxxx_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyyzzzzz_0[i] = 5.0 * g_0_xxxxxx_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyyzzzzz_0[i] * pb_z + g_0_xxxxxx_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yyzzzzzz_0[i] = 6.0 * g_0_xxxxxx_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yyzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_yzzzzzzz_0[i] = 7.0 * g_0_xxxxxx_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_yzzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_xxxxxxz_0_zzzzzzzz_0[i] = 8.0 * g_0_xxxxxx_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxx_0_zzzzzzzz_0[i] * pb_z + g_0_xxxxxx_0_zzzzzzzz_1[i] * wp_z[i];
    }

    /// Set up 135-180 components of targeted buffer : SKSL

    auto g_0_xxxxxyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 135);

    auto g_0_xxxxxyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 136);

    auto g_0_xxxxxyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 137);

    auto g_0_xxxxxyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 138);

    auto g_0_xxxxxyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 139);

    auto g_0_xxxxxyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 140);

    auto g_0_xxxxxyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 141);

    auto g_0_xxxxxyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 142);

    auto g_0_xxxxxyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 143);

    auto g_0_xxxxxyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 144);

    auto g_0_xxxxxyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 145);

    auto g_0_xxxxxyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 146);

    auto g_0_xxxxxyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 147);

    auto g_0_xxxxxyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 148);

    auto g_0_xxxxxyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 149);

    auto g_0_xxxxxyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 150);

    auto g_0_xxxxxyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 151);

    auto g_0_xxxxxyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 152);

    auto g_0_xxxxxyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 153);

    auto g_0_xxxxxyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 154);

    auto g_0_xxxxxyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 155);

    auto g_0_xxxxxyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 156);

    auto g_0_xxxxxyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 157);

    auto g_0_xxxxxyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 158);

    auto g_0_xxxxxyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 159);

    auto g_0_xxxxxyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 160);

    auto g_0_xxxxxyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 161);

    auto g_0_xxxxxyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 162);

    auto g_0_xxxxxyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 163);

    auto g_0_xxxxxyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 164);

    auto g_0_xxxxxyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 165);

    auto g_0_xxxxxyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 166);

    auto g_0_xxxxxyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 167);

    auto g_0_xxxxxyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 168);

    auto g_0_xxxxxyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 169);

    auto g_0_xxxxxyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 170);

    auto g_0_xxxxxyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 171);

    auto g_0_xxxxxyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 172);

    auto g_0_xxxxxyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 173);

    auto g_0_xxxxxyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 174);

    auto g_0_xxxxxyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 175);

    auto g_0_xxxxxyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 176);

    auto g_0_xxxxxyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 177);

    auto g_0_xxxxxyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 178);

    auto g_0_xxxxxyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 179);

    #pragma omp simd aligned(g_0_xxxxx_0_xxxxxxxx_0, g_0_xxxxx_0_xxxxxxxx_1, g_0_xxxxx_0_xxxxxxxz_0, g_0_xxxxx_0_xxxxxxxz_1, g_0_xxxxx_0_xxxxxxzz_0, g_0_xxxxx_0_xxxxxxzz_1, g_0_xxxxx_0_xxxxxzzz_0, g_0_xxxxx_0_xxxxxzzz_1, g_0_xxxxx_0_xxxxzzzz_0, g_0_xxxxx_0_xxxxzzzz_1, g_0_xxxxx_0_xxxzzzzz_0, g_0_xxxxx_0_xxxzzzzz_1, g_0_xxxxx_0_xxzzzzzz_0, g_0_xxxxx_0_xxzzzzzz_1, g_0_xxxxx_0_xzzzzzzz_0, g_0_xxxxx_0_xzzzzzzz_1, g_0_xxxxxy_0_xxxxxxxx_0, g_0_xxxxxy_0_xxxxxxxx_1, g_0_xxxxxy_0_xxxxxxxz_0, g_0_xxxxxy_0_xxxxxxxz_1, g_0_xxxxxy_0_xxxxxxzz_0, g_0_xxxxxy_0_xxxxxxzz_1, g_0_xxxxxy_0_xxxxxzzz_0, g_0_xxxxxy_0_xxxxxzzz_1, g_0_xxxxxy_0_xxxxzzzz_0, g_0_xxxxxy_0_xxxxzzzz_1, g_0_xxxxxy_0_xxxzzzzz_0, g_0_xxxxxy_0_xxxzzzzz_1, g_0_xxxxxy_0_xxzzzzzz_0, g_0_xxxxxy_0_xxzzzzzz_1, g_0_xxxxxy_0_xzzzzzzz_0, g_0_xxxxxy_0_xzzzzzzz_1, g_0_xxxxxyy_0_xxxxxxxx_0, g_0_xxxxxyy_0_xxxxxxxy_0, g_0_xxxxxyy_0_xxxxxxxz_0, g_0_xxxxxyy_0_xxxxxxyy_0, g_0_xxxxxyy_0_xxxxxxyz_0, g_0_xxxxxyy_0_xxxxxxzz_0, g_0_xxxxxyy_0_xxxxxyyy_0, g_0_xxxxxyy_0_xxxxxyyz_0, g_0_xxxxxyy_0_xxxxxyzz_0, g_0_xxxxxyy_0_xxxxxzzz_0, g_0_xxxxxyy_0_xxxxyyyy_0, g_0_xxxxxyy_0_xxxxyyyz_0, g_0_xxxxxyy_0_xxxxyyzz_0, g_0_xxxxxyy_0_xxxxyzzz_0, g_0_xxxxxyy_0_xxxxzzzz_0, g_0_xxxxxyy_0_xxxyyyyy_0, g_0_xxxxxyy_0_xxxyyyyz_0, g_0_xxxxxyy_0_xxxyyyzz_0, g_0_xxxxxyy_0_xxxyyzzz_0, g_0_xxxxxyy_0_xxxyzzzz_0, g_0_xxxxxyy_0_xxxzzzzz_0, g_0_xxxxxyy_0_xxyyyyyy_0, g_0_xxxxxyy_0_xxyyyyyz_0, g_0_xxxxxyy_0_xxyyyyzz_0, g_0_xxxxxyy_0_xxyyyzzz_0, g_0_xxxxxyy_0_xxyyzzzz_0, g_0_xxxxxyy_0_xxyzzzzz_0, g_0_xxxxxyy_0_xxzzzzzz_0, g_0_xxxxxyy_0_xyyyyyyy_0, g_0_xxxxxyy_0_xyyyyyyz_0, g_0_xxxxxyy_0_xyyyyyzz_0, g_0_xxxxxyy_0_xyyyyzzz_0, g_0_xxxxxyy_0_xyyyzzzz_0, g_0_xxxxxyy_0_xyyzzzzz_0, g_0_xxxxxyy_0_xyzzzzzz_0, g_0_xxxxxyy_0_xzzzzzzz_0, g_0_xxxxxyy_0_yyyyyyyy_0, g_0_xxxxxyy_0_yyyyyyyz_0, g_0_xxxxxyy_0_yyyyyyzz_0, g_0_xxxxxyy_0_yyyyyzzz_0, g_0_xxxxxyy_0_yyyyzzzz_0, g_0_xxxxxyy_0_yyyzzzzz_0, g_0_xxxxxyy_0_yyzzzzzz_0, g_0_xxxxxyy_0_yzzzzzzz_0, g_0_xxxxxyy_0_zzzzzzzz_0, g_0_xxxxyy_0_xxxxxxxy_0, g_0_xxxxyy_0_xxxxxxxy_1, g_0_xxxxyy_0_xxxxxxy_1, g_0_xxxxyy_0_xxxxxxyy_0, g_0_xxxxyy_0_xxxxxxyy_1, g_0_xxxxyy_0_xxxxxxyz_0, g_0_xxxxyy_0_xxxxxxyz_1, g_0_xxxxyy_0_xxxxxyy_1, g_0_xxxxyy_0_xxxxxyyy_0, g_0_xxxxyy_0_xxxxxyyy_1, g_0_xxxxyy_0_xxxxxyyz_0, g_0_xxxxyy_0_xxxxxyyz_1, g_0_xxxxyy_0_xxxxxyz_1, g_0_xxxxyy_0_xxxxxyzz_0, g_0_xxxxyy_0_xxxxxyzz_1, g_0_xxxxyy_0_xxxxyyy_1, g_0_xxxxyy_0_xxxxyyyy_0, g_0_xxxxyy_0_xxxxyyyy_1, g_0_xxxxyy_0_xxxxyyyz_0, g_0_xxxxyy_0_xxxxyyyz_1, g_0_xxxxyy_0_xxxxyyz_1, g_0_xxxxyy_0_xxxxyyzz_0, g_0_xxxxyy_0_xxxxyyzz_1, g_0_xxxxyy_0_xxxxyzz_1, g_0_xxxxyy_0_xxxxyzzz_0, g_0_xxxxyy_0_xxxxyzzz_1, g_0_xxxxyy_0_xxxyyyy_1, g_0_xxxxyy_0_xxxyyyyy_0, g_0_xxxxyy_0_xxxyyyyy_1, g_0_xxxxyy_0_xxxyyyyz_0, g_0_xxxxyy_0_xxxyyyyz_1, g_0_xxxxyy_0_xxxyyyz_1, g_0_xxxxyy_0_xxxyyyzz_0, g_0_xxxxyy_0_xxxyyyzz_1, g_0_xxxxyy_0_xxxyyzz_1, g_0_xxxxyy_0_xxxyyzzz_0, g_0_xxxxyy_0_xxxyyzzz_1, g_0_xxxxyy_0_xxxyzzz_1, g_0_xxxxyy_0_xxxyzzzz_0, g_0_xxxxyy_0_xxxyzzzz_1, g_0_xxxxyy_0_xxyyyyy_1, g_0_xxxxyy_0_xxyyyyyy_0, g_0_xxxxyy_0_xxyyyyyy_1, g_0_xxxxyy_0_xxyyyyyz_0, g_0_xxxxyy_0_xxyyyyyz_1, g_0_xxxxyy_0_xxyyyyz_1, g_0_xxxxyy_0_xxyyyyzz_0, g_0_xxxxyy_0_xxyyyyzz_1, g_0_xxxxyy_0_xxyyyzz_1, g_0_xxxxyy_0_xxyyyzzz_0, g_0_xxxxyy_0_xxyyyzzz_1, g_0_xxxxyy_0_xxyyzzz_1, g_0_xxxxyy_0_xxyyzzzz_0, g_0_xxxxyy_0_xxyyzzzz_1, g_0_xxxxyy_0_xxyzzzz_1, g_0_xxxxyy_0_xxyzzzzz_0, g_0_xxxxyy_0_xxyzzzzz_1, g_0_xxxxyy_0_xyyyyyy_1, g_0_xxxxyy_0_xyyyyyyy_0, g_0_xxxxyy_0_xyyyyyyy_1, g_0_xxxxyy_0_xyyyyyyz_0, g_0_xxxxyy_0_xyyyyyyz_1, g_0_xxxxyy_0_xyyyyyz_1, g_0_xxxxyy_0_xyyyyyzz_0, g_0_xxxxyy_0_xyyyyyzz_1, g_0_xxxxyy_0_xyyyyzz_1, g_0_xxxxyy_0_xyyyyzzz_0, g_0_xxxxyy_0_xyyyyzzz_1, g_0_xxxxyy_0_xyyyzzz_1, g_0_xxxxyy_0_xyyyzzzz_0, g_0_xxxxyy_0_xyyyzzzz_1, g_0_xxxxyy_0_xyyzzzz_1, g_0_xxxxyy_0_xyyzzzzz_0, g_0_xxxxyy_0_xyyzzzzz_1, g_0_xxxxyy_0_xyzzzzz_1, g_0_xxxxyy_0_xyzzzzzz_0, g_0_xxxxyy_0_xyzzzzzz_1, g_0_xxxxyy_0_yyyyyyy_1, g_0_xxxxyy_0_yyyyyyyy_0, g_0_xxxxyy_0_yyyyyyyy_1, g_0_xxxxyy_0_yyyyyyyz_0, g_0_xxxxyy_0_yyyyyyyz_1, g_0_xxxxyy_0_yyyyyyz_1, g_0_xxxxyy_0_yyyyyyzz_0, g_0_xxxxyy_0_yyyyyyzz_1, g_0_xxxxyy_0_yyyyyzz_1, g_0_xxxxyy_0_yyyyyzzz_0, g_0_xxxxyy_0_yyyyyzzz_1, g_0_xxxxyy_0_yyyyzzz_1, g_0_xxxxyy_0_yyyyzzzz_0, g_0_xxxxyy_0_yyyyzzzz_1, g_0_xxxxyy_0_yyyzzzz_1, g_0_xxxxyy_0_yyyzzzzz_0, g_0_xxxxyy_0_yyyzzzzz_1, g_0_xxxxyy_0_yyzzzzz_1, g_0_xxxxyy_0_yyzzzzzz_0, g_0_xxxxyy_0_yyzzzzzz_1, g_0_xxxxyy_0_yzzzzzz_1, g_0_xxxxyy_0_yzzzzzzz_0, g_0_xxxxyy_0_yzzzzzzz_1, g_0_xxxxyy_0_zzzzzzzz_0, g_0_xxxxyy_0_zzzzzzzz_1, g_0_xxxyy_0_xxxxxxxy_0, g_0_xxxyy_0_xxxxxxxy_1, g_0_xxxyy_0_xxxxxxyy_0, g_0_xxxyy_0_xxxxxxyy_1, g_0_xxxyy_0_xxxxxxyz_0, g_0_xxxyy_0_xxxxxxyz_1, g_0_xxxyy_0_xxxxxyyy_0, g_0_xxxyy_0_xxxxxyyy_1, g_0_xxxyy_0_xxxxxyyz_0, g_0_xxxyy_0_xxxxxyyz_1, g_0_xxxyy_0_xxxxxyzz_0, g_0_xxxyy_0_xxxxxyzz_1, g_0_xxxyy_0_xxxxyyyy_0, g_0_xxxyy_0_xxxxyyyy_1, g_0_xxxyy_0_xxxxyyyz_0, g_0_xxxyy_0_xxxxyyyz_1, g_0_xxxyy_0_xxxxyyzz_0, g_0_xxxyy_0_xxxxyyzz_1, g_0_xxxyy_0_xxxxyzzz_0, g_0_xxxyy_0_xxxxyzzz_1, g_0_xxxyy_0_xxxyyyyy_0, g_0_xxxyy_0_xxxyyyyy_1, g_0_xxxyy_0_xxxyyyyz_0, g_0_xxxyy_0_xxxyyyyz_1, g_0_xxxyy_0_xxxyyyzz_0, g_0_xxxyy_0_xxxyyyzz_1, g_0_xxxyy_0_xxxyyzzz_0, g_0_xxxyy_0_xxxyyzzz_1, g_0_xxxyy_0_xxxyzzzz_0, g_0_xxxyy_0_xxxyzzzz_1, g_0_xxxyy_0_xxyyyyyy_0, g_0_xxxyy_0_xxyyyyyy_1, g_0_xxxyy_0_xxyyyyyz_0, g_0_xxxyy_0_xxyyyyyz_1, g_0_xxxyy_0_xxyyyyzz_0, g_0_xxxyy_0_xxyyyyzz_1, g_0_xxxyy_0_xxyyyzzz_0, g_0_xxxyy_0_xxyyyzzz_1, g_0_xxxyy_0_xxyyzzzz_0, g_0_xxxyy_0_xxyyzzzz_1, g_0_xxxyy_0_xxyzzzzz_0, g_0_xxxyy_0_xxyzzzzz_1, g_0_xxxyy_0_xyyyyyyy_0, g_0_xxxyy_0_xyyyyyyy_1, g_0_xxxyy_0_xyyyyyyz_0, g_0_xxxyy_0_xyyyyyyz_1, g_0_xxxyy_0_xyyyyyzz_0, g_0_xxxyy_0_xyyyyyzz_1, g_0_xxxyy_0_xyyyyzzz_0, g_0_xxxyy_0_xyyyyzzz_1, g_0_xxxyy_0_xyyyzzzz_0, g_0_xxxyy_0_xyyyzzzz_1, g_0_xxxyy_0_xyyzzzzz_0, g_0_xxxyy_0_xyyzzzzz_1, g_0_xxxyy_0_xyzzzzzz_0, g_0_xxxyy_0_xyzzzzzz_1, g_0_xxxyy_0_yyyyyyyy_0, g_0_xxxyy_0_yyyyyyyy_1, g_0_xxxyy_0_yyyyyyyz_0, g_0_xxxyy_0_yyyyyyyz_1, g_0_xxxyy_0_yyyyyyzz_0, g_0_xxxyy_0_yyyyyyzz_1, g_0_xxxyy_0_yyyyyzzz_0, g_0_xxxyy_0_yyyyyzzz_1, g_0_xxxyy_0_yyyyzzzz_0, g_0_xxxyy_0_yyyyzzzz_1, g_0_xxxyy_0_yyyzzzzz_0, g_0_xxxyy_0_yyyzzzzz_1, g_0_xxxyy_0_yyzzzzzz_0, g_0_xxxyy_0_yyzzzzzz_1, g_0_xxxyy_0_yzzzzzzz_0, g_0_xxxyy_0_yzzzzzzz_1, g_0_xxxyy_0_zzzzzzzz_0, g_0_xxxyy_0_zzzzzzzz_1, wp_x, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxxxyy_0_xxxxxxxx_0[i] = g_0_xxxxx_0_xxxxxxxx_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxxxxxx_0[i] * pb_y + g_0_xxxxxy_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxxxxxxy_0[i] = 4.0 * g_0_xxxyy_0_xxxxxxxy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxxxy_1[i] * fti_ab_0 + 7.0 * g_0_xxxxyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxxy_0[i] * pb_x + g_0_xxxxyy_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxxxz_0[i] = g_0_xxxxx_0_xxxxxxxz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxxxxxz_0[i] * pb_y + g_0_xxxxxy_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxxxxxyy_0[i] = 4.0 * g_0_xxxyy_0_xxxxxxyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxxyy_1[i] * fti_ab_0 + 6.0 * g_0_xxxxyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxyy_0[i] * pb_x + g_0_xxxxyy_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxxyz_0[i] = 4.0 * g_0_xxxyy_0_xxxxxxyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxxxyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxyz_0[i] * pb_x + g_0_xxxxyy_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxxzz_0[i] = g_0_xxxxx_0_xxxxxxzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxxxxzz_0[i] * pb_y + g_0_xxxxxy_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxxxxyyy_0[i] = 4.0 * g_0_xxxyy_0_xxxxxyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxyyy_1[i] * fti_ab_0 + 5.0 * g_0_xxxxyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxyyy_0[i] * pb_x + g_0_xxxxyy_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxyyz_0[i] = 4.0 * g_0_xxxyy_0_xxxxxyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxyyz_0[i] * pb_x + g_0_xxxxyy_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxyzz_0[i] = 4.0 * g_0_xxxyy_0_xxxxxyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxyzz_0[i] * pb_x + g_0_xxxxyy_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxxzzz_0[i] = g_0_xxxxx_0_xxxxxzzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxxxzzz_0[i] * pb_y + g_0_xxxxxy_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxxxyyyy_0[i] = 4.0 * g_0_xxxyy_0_xxxxyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_xxxxyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyyyy_0[i] * pb_x + g_0_xxxxyy_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxyyyz_0[i] = 4.0 * g_0_xxxyy_0_xxxxyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyyyz_0[i] * pb_x + g_0_xxxxyy_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxyyzz_0[i] = 4.0 * g_0_xxxyy_0_xxxxyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyyzz_0[i] * pb_x + g_0_xxxxyy_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxyzzz_0[i] = 4.0 * g_0_xxxyy_0_xxxxyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyzzz_0[i] * pb_x + g_0_xxxxyy_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxxzzzz_0[i] = g_0_xxxxx_0_xxxxzzzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxxzzzz_0[i] * pb_y + g_0_xxxxxy_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxxyyyyy_0[i] = 4.0 * g_0_xxxyy_0_xxxyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxyyyyy_1[i] * fti_ab_0 + 3.0 * g_0_xxxxyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyyyy_0[i] * pb_x + g_0_xxxxyy_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxyy_0_xxxyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyyyz_0[i] * pb_x + g_0_xxxxyy_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxyyyzz_0[i] = 4.0 * g_0_xxxyy_0_xxxyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyyzz_0[i] * pb_x + g_0_xxxxyy_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxyyzzz_0[i] = 4.0 * g_0_xxxyy_0_xxxyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyzzz_0[i] * pb_x + g_0_xxxxyy_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxyzzzz_0[i] = 4.0 * g_0_xxxyy_0_xxxyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyzzzz_0[i] * pb_x + g_0_xxxxyy_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxxzzzzz_0[i] = g_0_xxxxx_0_xxxzzzzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxxzzzzz_0[i] * pb_y + g_0_xxxxxy_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xxyyyyyy_0[i] = 4.0 * g_0_xxxyy_0_xxyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyyyyyy_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyyyy_0[i] * pb_x + g_0_xxxxyy_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxyyyyyz_0[i] = 4.0 * g_0_xxxyy_0_xxyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyyyz_0[i] * pb_x + g_0_xxxxyy_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxyy_0_xxyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyyzz_0[i] * pb_x + g_0_xxxxyy_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxyyyzzz_0[i] = 4.0 * g_0_xxxyy_0_xxyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyzzz_0[i] * pb_x + g_0_xxxxyy_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxyyzzzz_0[i] = 4.0 * g_0_xxxyy_0_xxyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyzzzz_0[i] * pb_x + g_0_xxxxyy_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxyzzzzz_0[i] = 4.0 * g_0_xxxyy_0_xxyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyzzzzz_0[i] * pb_x + g_0_xxxxyy_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xxzzzzzz_0[i] = g_0_xxxxx_0_xxzzzzzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xxzzzzzz_0[i] * pb_y + g_0_xxxxxy_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_xyyyyyyy_0[i] = 4.0 * g_0_xxxyy_0_xyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyyyy_0[i] * pb_x + g_0_xxxxyy_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyyyyyyz_0[i] = 4.0 * g_0_xxxyy_0_xyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyyyz_0[i] * pb_x + g_0_xxxxyy_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyyyyyzz_0[i] = 4.0 * g_0_xxxyy_0_xyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyyzz_0[i] * pb_x + g_0_xxxxyy_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxyy_0_xyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyzzz_0[i] * pb_x + g_0_xxxxyy_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyyyzzzz_0[i] = 4.0 * g_0_xxxyy_0_xyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyzzzz_0[i] * pb_x + g_0_xxxxyy_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyyzzzzz_0[i] = 4.0 * g_0_xxxyy_0_xyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyzzzzz_0[i] * pb_x + g_0_xxxxyy_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xyzzzzzz_0[i] = 4.0 * g_0_xxxyy_0_xyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyzzzzzz_0[i] * pb_x + g_0_xxxxyy_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_xzzzzzzz_0[i] = g_0_xxxxx_0_xzzzzzzz_0[i] * fi_ab_0 - g_0_xxxxx_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxxy_0_xzzzzzzz_0[i] * pb_y + g_0_xxxxxy_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyy_0_yyyyyyyy_0[i] = 4.0 * g_0_xxxyy_0_yyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyyyy_0[i] * pb_x + g_0_xxxxyy_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyyyyyyz_0[i] = 4.0 * g_0_xxxyy_0_yyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyyyz_0[i] * pb_x + g_0_xxxxyy_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyyyyyzz_0[i] = 4.0 * g_0_xxxyy_0_yyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyyzz_0[i] * pb_x + g_0_xxxxyy_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyyyyzzz_0[i] = 4.0 * g_0_xxxyy_0_yyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyyzzz_0[i] * pb_x + g_0_xxxxyy_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxyy_0_yyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyyzzzz_0[i] * pb_x + g_0_xxxxyy_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyyzzzzz_0[i] = 4.0 * g_0_xxxyy_0_yyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyyzzzzz_0[i] * pb_x + g_0_xxxxyy_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yyzzzzzz_0[i] = 4.0 * g_0_xxxyy_0_yyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yyzzzzzz_0[i] * pb_x + g_0_xxxxyy_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_yzzzzzzz_0[i] = 4.0 * g_0_xxxyy_0_yzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_yzzzzzzz_0[i] * pb_x + g_0_xxxxyy_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxyy_0_zzzzzzzz_0[i] = 4.0 * g_0_xxxyy_0_zzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxyy_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_zzzzzzzz_0[i] * pb_x + g_0_xxxxyy_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 180-225 components of targeted buffer : SKSL

    auto g_0_xxxxxyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 180);

    auto g_0_xxxxxyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 181);

    auto g_0_xxxxxyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 182);

    auto g_0_xxxxxyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 183);

    auto g_0_xxxxxyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 184);

    auto g_0_xxxxxyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 185);

    auto g_0_xxxxxyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 186);

    auto g_0_xxxxxyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 187);

    auto g_0_xxxxxyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 188);

    auto g_0_xxxxxyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 189);

    auto g_0_xxxxxyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 190);

    auto g_0_xxxxxyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 191);

    auto g_0_xxxxxyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 192);

    auto g_0_xxxxxyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 193);

    auto g_0_xxxxxyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 194);

    auto g_0_xxxxxyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 195);

    auto g_0_xxxxxyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 196);

    auto g_0_xxxxxyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 197);

    auto g_0_xxxxxyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 198);

    auto g_0_xxxxxyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 199);

    auto g_0_xxxxxyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 200);

    auto g_0_xxxxxyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 201);

    auto g_0_xxxxxyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 202);

    auto g_0_xxxxxyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 203);

    auto g_0_xxxxxyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 204);

    auto g_0_xxxxxyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 205);

    auto g_0_xxxxxyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 206);

    auto g_0_xxxxxyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 207);

    auto g_0_xxxxxyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 208);

    auto g_0_xxxxxyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 209);

    auto g_0_xxxxxyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 210);

    auto g_0_xxxxxyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 211);

    auto g_0_xxxxxyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 212);

    auto g_0_xxxxxyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 213);

    auto g_0_xxxxxyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 214);

    auto g_0_xxxxxyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 215);

    auto g_0_xxxxxyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 216);

    auto g_0_xxxxxyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 217);

    auto g_0_xxxxxyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 218);

    auto g_0_xxxxxyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 219);

    auto g_0_xxxxxyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 220);

    auto g_0_xxxxxyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 221);

    auto g_0_xxxxxyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 222);

    auto g_0_xxxxxyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 223);

    auto g_0_xxxxxyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 224);

    #pragma omp simd aligned(g_0_xxxxxy_0_xxxxxxxy_0, g_0_xxxxxy_0_xxxxxxxy_1, g_0_xxxxxy_0_xxxxxxyy_0, g_0_xxxxxy_0_xxxxxxyy_1, g_0_xxxxxy_0_xxxxxyyy_0, g_0_xxxxxy_0_xxxxxyyy_1, g_0_xxxxxy_0_xxxxyyyy_0, g_0_xxxxxy_0_xxxxyyyy_1, g_0_xxxxxy_0_xxxyyyyy_0, g_0_xxxxxy_0_xxxyyyyy_1, g_0_xxxxxy_0_xxyyyyyy_0, g_0_xxxxxy_0_xxyyyyyy_1, g_0_xxxxxy_0_xyyyyyyy_0, g_0_xxxxxy_0_xyyyyyyy_1, g_0_xxxxxy_0_yyyyyyyy_0, g_0_xxxxxy_0_yyyyyyyy_1, g_0_xxxxxyz_0_xxxxxxxx_0, g_0_xxxxxyz_0_xxxxxxxy_0, g_0_xxxxxyz_0_xxxxxxxz_0, g_0_xxxxxyz_0_xxxxxxyy_0, g_0_xxxxxyz_0_xxxxxxyz_0, g_0_xxxxxyz_0_xxxxxxzz_0, g_0_xxxxxyz_0_xxxxxyyy_0, g_0_xxxxxyz_0_xxxxxyyz_0, g_0_xxxxxyz_0_xxxxxyzz_0, g_0_xxxxxyz_0_xxxxxzzz_0, g_0_xxxxxyz_0_xxxxyyyy_0, g_0_xxxxxyz_0_xxxxyyyz_0, g_0_xxxxxyz_0_xxxxyyzz_0, g_0_xxxxxyz_0_xxxxyzzz_0, g_0_xxxxxyz_0_xxxxzzzz_0, g_0_xxxxxyz_0_xxxyyyyy_0, g_0_xxxxxyz_0_xxxyyyyz_0, g_0_xxxxxyz_0_xxxyyyzz_0, g_0_xxxxxyz_0_xxxyyzzz_0, g_0_xxxxxyz_0_xxxyzzzz_0, g_0_xxxxxyz_0_xxxzzzzz_0, g_0_xxxxxyz_0_xxyyyyyy_0, g_0_xxxxxyz_0_xxyyyyyz_0, g_0_xxxxxyz_0_xxyyyyzz_0, g_0_xxxxxyz_0_xxyyyzzz_0, g_0_xxxxxyz_0_xxyyzzzz_0, g_0_xxxxxyz_0_xxyzzzzz_0, g_0_xxxxxyz_0_xxzzzzzz_0, g_0_xxxxxyz_0_xyyyyyyy_0, g_0_xxxxxyz_0_xyyyyyyz_0, g_0_xxxxxyz_0_xyyyyyzz_0, g_0_xxxxxyz_0_xyyyyzzz_0, g_0_xxxxxyz_0_xyyyzzzz_0, g_0_xxxxxyz_0_xyyzzzzz_0, g_0_xxxxxyz_0_xyzzzzzz_0, g_0_xxxxxyz_0_xzzzzzzz_0, g_0_xxxxxyz_0_yyyyyyyy_0, g_0_xxxxxyz_0_yyyyyyyz_0, g_0_xxxxxyz_0_yyyyyyzz_0, g_0_xxxxxyz_0_yyyyyzzz_0, g_0_xxxxxyz_0_yyyyzzzz_0, g_0_xxxxxyz_0_yyyzzzzz_0, g_0_xxxxxyz_0_yyzzzzzz_0, g_0_xxxxxyz_0_yzzzzzzz_0, g_0_xxxxxyz_0_zzzzzzzz_0, g_0_xxxxxz_0_xxxxxxxx_0, g_0_xxxxxz_0_xxxxxxxx_1, g_0_xxxxxz_0_xxxxxxxz_0, g_0_xxxxxz_0_xxxxxxxz_1, g_0_xxxxxz_0_xxxxxxyz_0, g_0_xxxxxz_0_xxxxxxyz_1, g_0_xxxxxz_0_xxxxxxz_1, g_0_xxxxxz_0_xxxxxxzz_0, g_0_xxxxxz_0_xxxxxxzz_1, g_0_xxxxxz_0_xxxxxyyz_0, g_0_xxxxxz_0_xxxxxyyz_1, g_0_xxxxxz_0_xxxxxyz_1, g_0_xxxxxz_0_xxxxxyzz_0, g_0_xxxxxz_0_xxxxxyzz_1, g_0_xxxxxz_0_xxxxxzz_1, g_0_xxxxxz_0_xxxxxzzz_0, g_0_xxxxxz_0_xxxxxzzz_1, g_0_xxxxxz_0_xxxxyyyz_0, g_0_xxxxxz_0_xxxxyyyz_1, g_0_xxxxxz_0_xxxxyyz_1, g_0_xxxxxz_0_xxxxyyzz_0, g_0_xxxxxz_0_xxxxyyzz_1, g_0_xxxxxz_0_xxxxyzz_1, g_0_xxxxxz_0_xxxxyzzz_0, g_0_xxxxxz_0_xxxxyzzz_1, g_0_xxxxxz_0_xxxxzzz_1, g_0_xxxxxz_0_xxxxzzzz_0, g_0_xxxxxz_0_xxxxzzzz_1, g_0_xxxxxz_0_xxxyyyyz_0, g_0_xxxxxz_0_xxxyyyyz_1, g_0_xxxxxz_0_xxxyyyz_1, g_0_xxxxxz_0_xxxyyyzz_0, g_0_xxxxxz_0_xxxyyyzz_1, g_0_xxxxxz_0_xxxyyzz_1, g_0_xxxxxz_0_xxxyyzzz_0, g_0_xxxxxz_0_xxxyyzzz_1, g_0_xxxxxz_0_xxxyzzz_1, g_0_xxxxxz_0_xxxyzzzz_0, g_0_xxxxxz_0_xxxyzzzz_1, g_0_xxxxxz_0_xxxzzzz_1, g_0_xxxxxz_0_xxxzzzzz_0, g_0_xxxxxz_0_xxxzzzzz_1, g_0_xxxxxz_0_xxyyyyyz_0, g_0_xxxxxz_0_xxyyyyyz_1, g_0_xxxxxz_0_xxyyyyz_1, g_0_xxxxxz_0_xxyyyyzz_0, g_0_xxxxxz_0_xxyyyyzz_1, g_0_xxxxxz_0_xxyyyzz_1, g_0_xxxxxz_0_xxyyyzzz_0, g_0_xxxxxz_0_xxyyyzzz_1, g_0_xxxxxz_0_xxyyzzz_1, g_0_xxxxxz_0_xxyyzzzz_0, g_0_xxxxxz_0_xxyyzzzz_1, g_0_xxxxxz_0_xxyzzzz_1, g_0_xxxxxz_0_xxyzzzzz_0, g_0_xxxxxz_0_xxyzzzzz_1, g_0_xxxxxz_0_xxzzzzz_1, g_0_xxxxxz_0_xxzzzzzz_0, g_0_xxxxxz_0_xxzzzzzz_1, g_0_xxxxxz_0_xyyyyyyz_0, g_0_xxxxxz_0_xyyyyyyz_1, g_0_xxxxxz_0_xyyyyyz_1, g_0_xxxxxz_0_xyyyyyzz_0, g_0_xxxxxz_0_xyyyyyzz_1, g_0_xxxxxz_0_xyyyyzz_1, g_0_xxxxxz_0_xyyyyzzz_0, g_0_xxxxxz_0_xyyyyzzz_1, g_0_xxxxxz_0_xyyyzzz_1, g_0_xxxxxz_0_xyyyzzzz_0, g_0_xxxxxz_0_xyyyzzzz_1, g_0_xxxxxz_0_xyyzzzz_1, g_0_xxxxxz_0_xyyzzzzz_0, g_0_xxxxxz_0_xyyzzzzz_1, g_0_xxxxxz_0_xyzzzzz_1, g_0_xxxxxz_0_xyzzzzzz_0, g_0_xxxxxz_0_xyzzzzzz_1, g_0_xxxxxz_0_xzzzzzz_1, g_0_xxxxxz_0_xzzzzzzz_0, g_0_xxxxxz_0_xzzzzzzz_1, g_0_xxxxxz_0_yyyyyyyz_0, g_0_xxxxxz_0_yyyyyyyz_1, g_0_xxxxxz_0_yyyyyyz_1, g_0_xxxxxz_0_yyyyyyzz_0, g_0_xxxxxz_0_yyyyyyzz_1, g_0_xxxxxz_0_yyyyyzz_1, g_0_xxxxxz_0_yyyyyzzz_0, g_0_xxxxxz_0_yyyyyzzz_1, g_0_xxxxxz_0_yyyyzzz_1, g_0_xxxxxz_0_yyyyzzzz_0, g_0_xxxxxz_0_yyyyzzzz_1, g_0_xxxxxz_0_yyyzzzz_1, g_0_xxxxxz_0_yyyzzzzz_0, g_0_xxxxxz_0_yyyzzzzz_1, g_0_xxxxxz_0_yyzzzzz_1, g_0_xxxxxz_0_yyzzzzzz_0, g_0_xxxxxz_0_yyzzzzzz_1, g_0_xxxxxz_0_yzzzzzz_1, g_0_xxxxxz_0_yzzzzzzz_0, g_0_xxxxxz_0_yzzzzzzz_1, g_0_xxxxxz_0_zzzzzzz_1, g_0_xxxxxz_0_zzzzzzzz_0, g_0_xxxxxz_0_zzzzzzzz_1, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxxxyz_0_xxxxxxxx_0[i] = g_0_xxxxxz_0_xxxxxxxx_0[i] * pb_y + g_0_xxxxxz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxxxy_0[i] = g_0_xxxxxy_0_xxxxxxxy_0[i] * pb_z + g_0_xxxxxy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxxxxxxz_0[i] = g_0_xxxxxz_0_xxxxxxxz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxxyy_0[i] = g_0_xxxxxy_0_xxxxxxyy_0[i] * pb_z + g_0_xxxxxy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxxxxxyz_0[i] = g_0_xxxxxz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxxxyz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxxzz_0[i] = g_0_xxxxxz_0_xxxxxxzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxyyy_0[i] = g_0_xxxxxy_0_xxxxxyyy_0[i] * pb_z + g_0_xxxxxy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxxxxyyz_0[i] = 2.0 * g_0_xxxxxz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxxyyz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxyzz_0[i] = g_0_xxxxxz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxxyzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxxzzz_0[i] = g_0_xxxxxz_0_xxxxxzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxyyyy_0[i] = g_0_xxxxxy_0_xxxxyyyy_0[i] * pb_z + g_0_xxxxxy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxxxyyyz_0[i] = 3.0 * g_0_xxxxxz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxyyyz_0[i] * pb_y + g_0_xxxxxz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxxxz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxyyzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxyzzz_0[i] = g_0_xxxxxz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxxyzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxxzzzz_0[i] = g_0_xxxxxz_0_xxxxzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxyyyyy_0[i] = g_0_xxxxxy_0_xxxyyyyy_0[i] * pb_z + g_0_xxxxxy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxxxz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxyyyyz_0[i] * pb_y + g_0_xxxxxz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxyyyzz_0[i] = 3.0 * g_0_xxxxxz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxyyyzz_0[i] * pb_y + g_0_xxxxxz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxyyzzz_0[i] = 2.0 * g_0_xxxxxz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxyyzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxyzzzz_0[i] = g_0_xxxxxz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxxyzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxxzzzzz_0[i] = g_0_xxxxxz_0_xxxzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxyyyyyy_0[i] = g_0_xxxxxy_0_xxyyyyyy_0[i] * pb_z + g_0_xxxxxy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xxyyyyyz_0[i] = 5.0 * g_0_xxxxxz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxyyyyyz_0[i] * pb_y + g_0_xxxxxz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxxxz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxyyyyzz_0[i] * pb_y + g_0_xxxxxz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxxxz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxyyyzzz_0[i] * pb_y + g_0_xxxxxz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxyyzzzz_0[i] = 2.0 * g_0_xxxxxz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxyyzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxyzzzzz_0[i] = g_0_xxxxxz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xxyzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xxzzzzzz_0[i] = g_0_xxxxxz_0_xxzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyyyyyyy_0[i] = g_0_xxxxxy_0_xyyyyyyy_0[i] * pb_z + g_0_xxxxxy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_xyyyyyyz_0[i] = 6.0 * g_0_xxxxxz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyyyyyyz_0[i] * pb_y + g_0_xxxxxz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyyyyyzz_0[i] = 5.0 * g_0_xxxxxz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyyyyyzz_0[i] * pb_y + g_0_xxxxxz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxxxz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyyyyzzz_0[i] * pb_y + g_0_xxxxxz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyyyzzzz_0[i] = 3.0 * g_0_xxxxxz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyyyzzzz_0[i] * pb_y + g_0_xxxxxz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyyzzzzz_0[i] = 2.0 * g_0_xxxxxz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyyzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xyzzzzzz_0[i] = g_0_xxxxxz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_xyzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_xzzzzzzz_0[i] = g_0_xxxxxz_0_xzzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyyyyyyy_0[i] = g_0_xxxxxy_0_yyyyyyyy_0[i] * pb_z + g_0_xxxxxy_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxyz_0_yyyyyyyz_0[i] = 7.0 * g_0_xxxxxz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyyyyyyz_0[i] * pb_y + g_0_xxxxxz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyyyyyzz_0[i] = 6.0 * g_0_xxxxxz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyyyyyzz_0[i] * pb_y + g_0_xxxxxz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyyyyzzz_0[i] = 5.0 * g_0_xxxxxz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyyyyzzz_0[i] * pb_y + g_0_xxxxxz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxxxz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyyyzzzz_0[i] * pb_y + g_0_xxxxxz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyyzzzzz_0[i] = 3.0 * g_0_xxxxxz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyyzzzzz_0[i] * pb_y + g_0_xxxxxz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yyzzzzzz_0[i] = 2.0 * g_0_xxxxxz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yyzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_yzzzzzzz_0[i] = g_0_xxxxxz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxxz_0_yzzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxxyz_0_zzzzzzzz_0[i] = g_0_xxxxxz_0_zzzzzzzz_0[i] * pb_y + g_0_xxxxxz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 225-270 components of targeted buffer : SKSL

    auto g_0_xxxxxzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 225);

    auto g_0_xxxxxzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 226);

    auto g_0_xxxxxzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 227);

    auto g_0_xxxxxzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 228);

    auto g_0_xxxxxzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 229);

    auto g_0_xxxxxzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 230);

    auto g_0_xxxxxzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 231);

    auto g_0_xxxxxzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 232);

    auto g_0_xxxxxzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 233);

    auto g_0_xxxxxzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 234);

    auto g_0_xxxxxzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 235);

    auto g_0_xxxxxzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 236);

    auto g_0_xxxxxzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 237);

    auto g_0_xxxxxzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 238);

    auto g_0_xxxxxzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 239);

    auto g_0_xxxxxzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 240);

    auto g_0_xxxxxzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 241);

    auto g_0_xxxxxzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 242);

    auto g_0_xxxxxzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 243);

    auto g_0_xxxxxzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 244);

    auto g_0_xxxxxzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 245);

    auto g_0_xxxxxzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 246);

    auto g_0_xxxxxzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 247);

    auto g_0_xxxxxzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 248);

    auto g_0_xxxxxzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 249);

    auto g_0_xxxxxzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 250);

    auto g_0_xxxxxzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 251);

    auto g_0_xxxxxzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 252);

    auto g_0_xxxxxzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 253);

    auto g_0_xxxxxzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 254);

    auto g_0_xxxxxzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 255);

    auto g_0_xxxxxzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 256);

    auto g_0_xxxxxzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 257);

    auto g_0_xxxxxzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 258);

    auto g_0_xxxxxzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 259);

    auto g_0_xxxxxzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 260);

    auto g_0_xxxxxzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 261);

    auto g_0_xxxxxzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 262);

    auto g_0_xxxxxzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 263);

    auto g_0_xxxxxzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 264);

    auto g_0_xxxxxzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 265);

    auto g_0_xxxxxzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 266);

    auto g_0_xxxxxzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 267);

    auto g_0_xxxxxzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 268);

    auto g_0_xxxxxzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 269);

    #pragma omp simd aligned(g_0_xxxxx_0_xxxxxxxx_0, g_0_xxxxx_0_xxxxxxxx_1, g_0_xxxxx_0_xxxxxxxy_0, g_0_xxxxx_0_xxxxxxxy_1, g_0_xxxxx_0_xxxxxxyy_0, g_0_xxxxx_0_xxxxxxyy_1, g_0_xxxxx_0_xxxxxyyy_0, g_0_xxxxx_0_xxxxxyyy_1, g_0_xxxxx_0_xxxxyyyy_0, g_0_xxxxx_0_xxxxyyyy_1, g_0_xxxxx_0_xxxyyyyy_0, g_0_xxxxx_0_xxxyyyyy_1, g_0_xxxxx_0_xxyyyyyy_0, g_0_xxxxx_0_xxyyyyyy_1, g_0_xxxxx_0_xyyyyyyy_0, g_0_xxxxx_0_xyyyyyyy_1, g_0_xxxxxz_0_xxxxxxxx_0, g_0_xxxxxz_0_xxxxxxxx_1, g_0_xxxxxz_0_xxxxxxxy_0, g_0_xxxxxz_0_xxxxxxxy_1, g_0_xxxxxz_0_xxxxxxyy_0, g_0_xxxxxz_0_xxxxxxyy_1, g_0_xxxxxz_0_xxxxxyyy_0, g_0_xxxxxz_0_xxxxxyyy_1, g_0_xxxxxz_0_xxxxyyyy_0, g_0_xxxxxz_0_xxxxyyyy_1, g_0_xxxxxz_0_xxxyyyyy_0, g_0_xxxxxz_0_xxxyyyyy_1, g_0_xxxxxz_0_xxyyyyyy_0, g_0_xxxxxz_0_xxyyyyyy_1, g_0_xxxxxz_0_xyyyyyyy_0, g_0_xxxxxz_0_xyyyyyyy_1, g_0_xxxxxzz_0_xxxxxxxx_0, g_0_xxxxxzz_0_xxxxxxxy_0, g_0_xxxxxzz_0_xxxxxxxz_0, g_0_xxxxxzz_0_xxxxxxyy_0, g_0_xxxxxzz_0_xxxxxxyz_0, g_0_xxxxxzz_0_xxxxxxzz_0, g_0_xxxxxzz_0_xxxxxyyy_0, g_0_xxxxxzz_0_xxxxxyyz_0, g_0_xxxxxzz_0_xxxxxyzz_0, g_0_xxxxxzz_0_xxxxxzzz_0, g_0_xxxxxzz_0_xxxxyyyy_0, g_0_xxxxxzz_0_xxxxyyyz_0, g_0_xxxxxzz_0_xxxxyyzz_0, g_0_xxxxxzz_0_xxxxyzzz_0, g_0_xxxxxzz_0_xxxxzzzz_0, g_0_xxxxxzz_0_xxxyyyyy_0, g_0_xxxxxzz_0_xxxyyyyz_0, g_0_xxxxxzz_0_xxxyyyzz_0, g_0_xxxxxzz_0_xxxyyzzz_0, g_0_xxxxxzz_0_xxxyzzzz_0, g_0_xxxxxzz_0_xxxzzzzz_0, g_0_xxxxxzz_0_xxyyyyyy_0, g_0_xxxxxzz_0_xxyyyyyz_0, g_0_xxxxxzz_0_xxyyyyzz_0, g_0_xxxxxzz_0_xxyyyzzz_0, g_0_xxxxxzz_0_xxyyzzzz_0, g_0_xxxxxzz_0_xxyzzzzz_0, g_0_xxxxxzz_0_xxzzzzzz_0, g_0_xxxxxzz_0_xyyyyyyy_0, g_0_xxxxxzz_0_xyyyyyyz_0, g_0_xxxxxzz_0_xyyyyyzz_0, g_0_xxxxxzz_0_xyyyyzzz_0, g_0_xxxxxzz_0_xyyyzzzz_0, g_0_xxxxxzz_0_xyyzzzzz_0, g_0_xxxxxzz_0_xyzzzzzz_0, g_0_xxxxxzz_0_xzzzzzzz_0, g_0_xxxxxzz_0_yyyyyyyy_0, g_0_xxxxxzz_0_yyyyyyyz_0, g_0_xxxxxzz_0_yyyyyyzz_0, g_0_xxxxxzz_0_yyyyyzzz_0, g_0_xxxxxzz_0_yyyyzzzz_0, g_0_xxxxxzz_0_yyyzzzzz_0, g_0_xxxxxzz_0_yyzzzzzz_0, g_0_xxxxxzz_0_yzzzzzzz_0, g_0_xxxxxzz_0_zzzzzzzz_0, g_0_xxxxzz_0_xxxxxxxz_0, g_0_xxxxzz_0_xxxxxxxz_1, g_0_xxxxzz_0_xxxxxxyz_0, g_0_xxxxzz_0_xxxxxxyz_1, g_0_xxxxzz_0_xxxxxxz_1, g_0_xxxxzz_0_xxxxxxzz_0, g_0_xxxxzz_0_xxxxxxzz_1, g_0_xxxxzz_0_xxxxxyyz_0, g_0_xxxxzz_0_xxxxxyyz_1, g_0_xxxxzz_0_xxxxxyz_1, g_0_xxxxzz_0_xxxxxyzz_0, g_0_xxxxzz_0_xxxxxyzz_1, g_0_xxxxzz_0_xxxxxzz_1, g_0_xxxxzz_0_xxxxxzzz_0, g_0_xxxxzz_0_xxxxxzzz_1, g_0_xxxxzz_0_xxxxyyyz_0, g_0_xxxxzz_0_xxxxyyyz_1, g_0_xxxxzz_0_xxxxyyz_1, g_0_xxxxzz_0_xxxxyyzz_0, g_0_xxxxzz_0_xxxxyyzz_1, g_0_xxxxzz_0_xxxxyzz_1, g_0_xxxxzz_0_xxxxyzzz_0, g_0_xxxxzz_0_xxxxyzzz_1, g_0_xxxxzz_0_xxxxzzz_1, g_0_xxxxzz_0_xxxxzzzz_0, g_0_xxxxzz_0_xxxxzzzz_1, g_0_xxxxzz_0_xxxyyyyz_0, g_0_xxxxzz_0_xxxyyyyz_1, g_0_xxxxzz_0_xxxyyyz_1, g_0_xxxxzz_0_xxxyyyzz_0, g_0_xxxxzz_0_xxxyyyzz_1, g_0_xxxxzz_0_xxxyyzz_1, g_0_xxxxzz_0_xxxyyzzz_0, g_0_xxxxzz_0_xxxyyzzz_1, g_0_xxxxzz_0_xxxyzzz_1, g_0_xxxxzz_0_xxxyzzzz_0, g_0_xxxxzz_0_xxxyzzzz_1, g_0_xxxxzz_0_xxxzzzz_1, g_0_xxxxzz_0_xxxzzzzz_0, g_0_xxxxzz_0_xxxzzzzz_1, g_0_xxxxzz_0_xxyyyyyz_0, g_0_xxxxzz_0_xxyyyyyz_1, g_0_xxxxzz_0_xxyyyyz_1, g_0_xxxxzz_0_xxyyyyzz_0, g_0_xxxxzz_0_xxyyyyzz_1, g_0_xxxxzz_0_xxyyyzz_1, g_0_xxxxzz_0_xxyyyzzz_0, g_0_xxxxzz_0_xxyyyzzz_1, g_0_xxxxzz_0_xxyyzzz_1, g_0_xxxxzz_0_xxyyzzzz_0, g_0_xxxxzz_0_xxyyzzzz_1, g_0_xxxxzz_0_xxyzzzz_1, g_0_xxxxzz_0_xxyzzzzz_0, g_0_xxxxzz_0_xxyzzzzz_1, g_0_xxxxzz_0_xxzzzzz_1, g_0_xxxxzz_0_xxzzzzzz_0, g_0_xxxxzz_0_xxzzzzzz_1, g_0_xxxxzz_0_xyyyyyyz_0, g_0_xxxxzz_0_xyyyyyyz_1, g_0_xxxxzz_0_xyyyyyz_1, g_0_xxxxzz_0_xyyyyyzz_0, g_0_xxxxzz_0_xyyyyyzz_1, g_0_xxxxzz_0_xyyyyzz_1, g_0_xxxxzz_0_xyyyyzzz_0, g_0_xxxxzz_0_xyyyyzzz_1, g_0_xxxxzz_0_xyyyzzz_1, g_0_xxxxzz_0_xyyyzzzz_0, g_0_xxxxzz_0_xyyyzzzz_1, g_0_xxxxzz_0_xyyzzzz_1, g_0_xxxxzz_0_xyyzzzzz_0, g_0_xxxxzz_0_xyyzzzzz_1, g_0_xxxxzz_0_xyzzzzz_1, g_0_xxxxzz_0_xyzzzzzz_0, g_0_xxxxzz_0_xyzzzzzz_1, g_0_xxxxzz_0_xzzzzzz_1, g_0_xxxxzz_0_xzzzzzzz_0, g_0_xxxxzz_0_xzzzzzzz_1, g_0_xxxxzz_0_yyyyyyyy_0, g_0_xxxxzz_0_yyyyyyyy_1, g_0_xxxxzz_0_yyyyyyyz_0, g_0_xxxxzz_0_yyyyyyyz_1, g_0_xxxxzz_0_yyyyyyz_1, g_0_xxxxzz_0_yyyyyyzz_0, g_0_xxxxzz_0_yyyyyyzz_1, g_0_xxxxzz_0_yyyyyzz_1, g_0_xxxxzz_0_yyyyyzzz_0, g_0_xxxxzz_0_yyyyyzzz_1, g_0_xxxxzz_0_yyyyzzz_1, g_0_xxxxzz_0_yyyyzzzz_0, g_0_xxxxzz_0_yyyyzzzz_1, g_0_xxxxzz_0_yyyzzzz_1, g_0_xxxxzz_0_yyyzzzzz_0, g_0_xxxxzz_0_yyyzzzzz_1, g_0_xxxxzz_0_yyzzzzz_1, g_0_xxxxzz_0_yyzzzzzz_0, g_0_xxxxzz_0_yyzzzzzz_1, g_0_xxxxzz_0_yzzzzzz_1, g_0_xxxxzz_0_yzzzzzzz_0, g_0_xxxxzz_0_yzzzzzzz_1, g_0_xxxxzz_0_zzzzzzz_1, g_0_xxxxzz_0_zzzzzzzz_0, g_0_xxxxzz_0_zzzzzzzz_1, g_0_xxxzz_0_xxxxxxxz_0, g_0_xxxzz_0_xxxxxxxz_1, g_0_xxxzz_0_xxxxxxyz_0, g_0_xxxzz_0_xxxxxxyz_1, g_0_xxxzz_0_xxxxxxzz_0, g_0_xxxzz_0_xxxxxxzz_1, g_0_xxxzz_0_xxxxxyyz_0, g_0_xxxzz_0_xxxxxyyz_1, g_0_xxxzz_0_xxxxxyzz_0, g_0_xxxzz_0_xxxxxyzz_1, g_0_xxxzz_0_xxxxxzzz_0, g_0_xxxzz_0_xxxxxzzz_1, g_0_xxxzz_0_xxxxyyyz_0, g_0_xxxzz_0_xxxxyyyz_1, g_0_xxxzz_0_xxxxyyzz_0, g_0_xxxzz_0_xxxxyyzz_1, g_0_xxxzz_0_xxxxyzzz_0, g_0_xxxzz_0_xxxxyzzz_1, g_0_xxxzz_0_xxxxzzzz_0, g_0_xxxzz_0_xxxxzzzz_1, g_0_xxxzz_0_xxxyyyyz_0, g_0_xxxzz_0_xxxyyyyz_1, g_0_xxxzz_0_xxxyyyzz_0, g_0_xxxzz_0_xxxyyyzz_1, g_0_xxxzz_0_xxxyyzzz_0, g_0_xxxzz_0_xxxyyzzz_1, g_0_xxxzz_0_xxxyzzzz_0, g_0_xxxzz_0_xxxyzzzz_1, g_0_xxxzz_0_xxxzzzzz_0, g_0_xxxzz_0_xxxzzzzz_1, g_0_xxxzz_0_xxyyyyyz_0, g_0_xxxzz_0_xxyyyyyz_1, g_0_xxxzz_0_xxyyyyzz_0, g_0_xxxzz_0_xxyyyyzz_1, g_0_xxxzz_0_xxyyyzzz_0, g_0_xxxzz_0_xxyyyzzz_1, g_0_xxxzz_0_xxyyzzzz_0, g_0_xxxzz_0_xxyyzzzz_1, g_0_xxxzz_0_xxyzzzzz_0, g_0_xxxzz_0_xxyzzzzz_1, g_0_xxxzz_0_xxzzzzzz_0, g_0_xxxzz_0_xxzzzzzz_1, g_0_xxxzz_0_xyyyyyyz_0, g_0_xxxzz_0_xyyyyyyz_1, g_0_xxxzz_0_xyyyyyzz_0, g_0_xxxzz_0_xyyyyyzz_1, g_0_xxxzz_0_xyyyyzzz_0, g_0_xxxzz_0_xyyyyzzz_1, g_0_xxxzz_0_xyyyzzzz_0, g_0_xxxzz_0_xyyyzzzz_1, g_0_xxxzz_0_xyyzzzzz_0, g_0_xxxzz_0_xyyzzzzz_1, g_0_xxxzz_0_xyzzzzzz_0, g_0_xxxzz_0_xyzzzzzz_1, g_0_xxxzz_0_xzzzzzzz_0, g_0_xxxzz_0_xzzzzzzz_1, g_0_xxxzz_0_yyyyyyyy_0, g_0_xxxzz_0_yyyyyyyy_1, g_0_xxxzz_0_yyyyyyyz_0, g_0_xxxzz_0_yyyyyyyz_1, g_0_xxxzz_0_yyyyyyzz_0, g_0_xxxzz_0_yyyyyyzz_1, g_0_xxxzz_0_yyyyyzzz_0, g_0_xxxzz_0_yyyyyzzz_1, g_0_xxxzz_0_yyyyzzzz_0, g_0_xxxzz_0_yyyyzzzz_1, g_0_xxxzz_0_yyyzzzzz_0, g_0_xxxzz_0_yyyzzzzz_1, g_0_xxxzz_0_yyzzzzzz_0, g_0_xxxzz_0_yyzzzzzz_1, g_0_xxxzz_0_yzzzzzzz_0, g_0_xxxzz_0_yzzzzzzz_1, g_0_xxxzz_0_zzzzzzzz_0, g_0_xxxzz_0_zzzzzzzz_1, wp_x, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxxxzz_0_xxxxxxxx_0[i] = g_0_xxxxx_0_xxxxxxxx_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxxxxxx_0[i] * pb_z + g_0_xxxxxz_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxxxxxy_0[i] = g_0_xxxxx_0_xxxxxxxy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxxxxxy_0[i] * pb_z + g_0_xxxxxz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxxxxxz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxxxz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxxxz_1[i] * fti_ab_0 + 7.0 * g_0_xxxxzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxxz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxxxyy_0[i] = g_0_xxxxx_0_xxxxxxyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxxxxyy_0[i] * pb_z + g_0_xxxxxz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxxxxyz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxxyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxxxzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxyz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxxxzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxxzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxxzz_1[i] * fti_ab_0 + 6.0 * g_0_xxxxzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxxyyy_0[i] = g_0_xxxxx_0_xxxxxyyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxxxyyy_0[i] * pb_z + g_0_xxxxxz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxxxyyz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxyyz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxxyzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxyzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxxzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxxzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxxzzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxxzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxyyyy_0[i] = g_0_xxxxx_0_xxxxyyyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxxyyyy_0[i] * pb_z + g_0_xxxxxz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxxyyyz_0[i] = 4.0 * g_0_xxxzz_0_xxxxyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyyyz_0[i] * pb_x + g_0_xxxxzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxyyzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyyzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxyzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxxzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxxzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxxzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxyyyyy_0[i] = g_0_xxxxx_0_xxxyyyyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxxyyyyy_0[i] * pb_z + g_0_xxxxxz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxzz_0_xxxyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyyyz_0[i] * pb_x + g_0_xxxxzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxyyyzz_0[i] = 4.0 * g_0_xxxzz_0_xxxyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyyzz_0[i] * pb_x + g_0_xxxxzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxyyzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxyzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxxzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxxzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxxzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxxzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxyyyyyy_0[i] = g_0_xxxxx_0_xxyyyyyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xxyyyyyy_0[i] * pb_z + g_0_xxxxxz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xxyyyyyz_0[i] = 4.0 * g_0_xxxzz_0_xxyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyyyz_0[i] * pb_x + g_0_xxxxzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxzz_0_xxyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyyzz_0[i] * pb_x + g_0_xxxxzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxyyyzzz_0[i] = 4.0 * g_0_xxxzz_0_xxyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyzzz_0[i] * pb_x + g_0_xxxxzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxyyzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxyzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xxzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xxzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xxzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxxzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyyyyyyy_0[i] = g_0_xxxxx_0_xyyyyyyy_0[i] * fi_ab_0 - g_0_xxxxx_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxxz_0_xyyyyyyy_0[i] * pb_z + g_0_xxxxxz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxxzz_0_xyyyyyyz_0[i] = 4.0 * g_0_xxxzz_0_xyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyyyz_0[i] * pb_x + g_0_xxxxzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyyyyyzz_0[i] = 4.0 * g_0_xxxzz_0_xyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyyzz_0[i] * pb_x + g_0_xxxxzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxzz_0_xyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyzzz_0[i] * pb_x + g_0_xxxxzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyyyzzzz_0[i] = 4.0 * g_0_xxxzz_0_xyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyzzzz_0[i] * pb_x + g_0_xxxxzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyyzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xyzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_xzzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_xzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xzzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyyyyyy_0[i] = 4.0 * g_0_xxxzz_0_yyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyyyy_0[i] * pb_x + g_0_xxxxzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyyyyyz_0[i] = 4.0 * g_0_xxxzz_0_yyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyyyz_0[i] * pb_x + g_0_xxxxzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyyyyzz_0[i] = 4.0 * g_0_xxxzz_0_yyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyyzz_0[i] * pb_x + g_0_xxxxzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyyyzzz_0[i] = 4.0 * g_0_xxxzz_0_yyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyyzzz_0[i] * pb_x + g_0_xxxxzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxzz_0_yyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyyzzzz_0[i] * pb_x + g_0_xxxxzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyyzzzzz_0[i] = 4.0 * g_0_xxxzz_0_yyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyyzzzzz_0[i] * pb_x + g_0_xxxxzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yyzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_yyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yyzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_yzzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_yzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_yzzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxxzz_0_zzzzzzzz_0[i] = 4.0 * g_0_xxxzz_0_zzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxxzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxzz_0_zzzzzzzz_0[i] * pb_x + g_0_xxxxzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 270-315 components of targeted buffer : SKSL

    auto g_0_xxxxyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 270);

    auto g_0_xxxxyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 271);

    auto g_0_xxxxyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 272);

    auto g_0_xxxxyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 273);

    auto g_0_xxxxyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 274);

    auto g_0_xxxxyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 275);

    auto g_0_xxxxyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 276);

    auto g_0_xxxxyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 277);

    auto g_0_xxxxyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 278);

    auto g_0_xxxxyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 279);

    auto g_0_xxxxyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 280);

    auto g_0_xxxxyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 281);

    auto g_0_xxxxyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 282);

    auto g_0_xxxxyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 283);

    auto g_0_xxxxyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 284);

    auto g_0_xxxxyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 285);

    auto g_0_xxxxyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 286);

    auto g_0_xxxxyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 287);

    auto g_0_xxxxyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 288);

    auto g_0_xxxxyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 289);

    auto g_0_xxxxyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 290);

    auto g_0_xxxxyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 291);

    auto g_0_xxxxyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 292);

    auto g_0_xxxxyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 293);

    auto g_0_xxxxyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 294);

    auto g_0_xxxxyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 295);

    auto g_0_xxxxyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 296);

    auto g_0_xxxxyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 297);

    auto g_0_xxxxyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 298);

    auto g_0_xxxxyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 299);

    auto g_0_xxxxyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 300);

    auto g_0_xxxxyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 301);

    auto g_0_xxxxyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 302);

    auto g_0_xxxxyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 303);

    auto g_0_xxxxyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 304);

    auto g_0_xxxxyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 305);

    auto g_0_xxxxyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 306);

    auto g_0_xxxxyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 307);

    auto g_0_xxxxyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 308);

    auto g_0_xxxxyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 309);

    auto g_0_xxxxyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 310);

    auto g_0_xxxxyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 311);

    auto g_0_xxxxyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 312);

    auto g_0_xxxxyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 313);

    auto g_0_xxxxyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 314);

    #pragma omp simd aligned(g_0_xxxxy_0_xxxxxxxx_0, g_0_xxxxy_0_xxxxxxxx_1, g_0_xxxxy_0_xxxxxxxz_0, g_0_xxxxy_0_xxxxxxxz_1, g_0_xxxxy_0_xxxxxxzz_0, g_0_xxxxy_0_xxxxxxzz_1, g_0_xxxxy_0_xxxxxzzz_0, g_0_xxxxy_0_xxxxxzzz_1, g_0_xxxxy_0_xxxxzzzz_0, g_0_xxxxy_0_xxxxzzzz_1, g_0_xxxxy_0_xxxzzzzz_0, g_0_xxxxy_0_xxxzzzzz_1, g_0_xxxxy_0_xxzzzzzz_0, g_0_xxxxy_0_xxzzzzzz_1, g_0_xxxxy_0_xzzzzzzz_0, g_0_xxxxy_0_xzzzzzzz_1, g_0_xxxxyy_0_xxxxxxxx_0, g_0_xxxxyy_0_xxxxxxxx_1, g_0_xxxxyy_0_xxxxxxxz_0, g_0_xxxxyy_0_xxxxxxxz_1, g_0_xxxxyy_0_xxxxxxzz_0, g_0_xxxxyy_0_xxxxxxzz_1, g_0_xxxxyy_0_xxxxxzzz_0, g_0_xxxxyy_0_xxxxxzzz_1, g_0_xxxxyy_0_xxxxzzzz_0, g_0_xxxxyy_0_xxxxzzzz_1, g_0_xxxxyy_0_xxxzzzzz_0, g_0_xxxxyy_0_xxxzzzzz_1, g_0_xxxxyy_0_xxzzzzzz_0, g_0_xxxxyy_0_xxzzzzzz_1, g_0_xxxxyy_0_xzzzzzzz_0, g_0_xxxxyy_0_xzzzzzzz_1, g_0_xxxxyyy_0_xxxxxxxx_0, g_0_xxxxyyy_0_xxxxxxxy_0, g_0_xxxxyyy_0_xxxxxxxz_0, g_0_xxxxyyy_0_xxxxxxyy_0, g_0_xxxxyyy_0_xxxxxxyz_0, g_0_xxxxyyy_0_xxxxxxzz_0, g_0_xxxxyyy_0_xxxxxyyy_0, g_0_xxxxyyy_0_xxxxxyyz_0, g_0_xxxxyyy_0_xxxxxyzz_0, g_0_xxxxyyy_0_xxxxxzzz_0, g_0_xxxxyyy_0_xxxxyyyy_0, g_0_xxxxyyy_0_xxxxyyyz_0, g_0_xxxxyyy_0_xxxxyyzz_0, g_0_xxxxyyy_0_xxxxyzzz_0, g_0_xxxxyyy_0_xxxxzzzz_0, g_0_xxxxyyy_0_xxxyyyyy_0, g_0_xxxxyyy_0_xxxyyyyz_0, g_0_xxxxyyy_0_xxxyyyzz_0, g_0_xxxxyyy_0_xxxyyzzz_0, g_0_xxxxyyy_0_xxxyzzzz_0, g_0_xxxxyyy_0_xxxzzzzz_0, g_0_xxxxyyy_0_xxyyyyyy_0, g_0_xxxxyyy_0_xxyyyyyz_0, g_0_xxxxyyy_0_xxyyyyzz_0, g_0_xxxxyyy_0_xxyyyzzz_0, g_0_xxxxyyy_0_xxyyzzzz_0, g_0_xxxxyyy_0_xxyzzzzz_0, g_0_xxxxyyy_0_xxzzzzzz_0, g_0_xxxxyyy_0_xyyyyyyy_0, g_0_xxxxyyy_0_xyyyyyyz_0, g_0_xxxxyyy_0_xyyyyyzz_0, g_0_xxxxyyy_0_xyyyyzzz_0, g_0_xxxxyyy_0_xyyyzzzz_0, g_0_xxxxyyy_0_xyyzzzzz_0, g_0_xxxxyyy_0_xyzzzzzz_0, g_0_xxxxyyy_0_xzzzzzzz_0, g_0_xxxxyyy_0_yyyyyyyy_0, g_0_xxxxyyy_0_yyyyyyyz_0, g_0_xxxxyyy_0_yyyyyyzz_0, g_0_xxxxyyy_0_yyyyyzzz_0, g_0_xxxxyyy_0_yyyyzzzz_0, g_0_xxxxyyy_0_yyyzzzzz_0, g_0_xxxxyyy_0_yyzzzzzz_0, g_0_xxxxyyy_0_yzzzzzzz_0, g_0_xxxxyyy_0_zzzzzzzz_0, g_0_xxxyyy_0_xxxxxxxy_0, g_0_xxxyyy_0_xxxxxxxy_1, g_0_xxxyyy_0_xxxxxxy_1, g_0_xxxyyy_0_xxxxxxyy_0, g_0_xxxyyy_0_xxxxxxyy_1, g_0_xxxyyy_0_xxxxxxyz_0, g_0_xxxyyy_0_xxxxxxyz_1, g_0_xxxyyy_0_xxxxxyy_1, g_0_xxxyyy_0_xxxxxyyy_0, g_0_xxxyyy_0_xxxxxyyy_1, g_0_xxxyyy_0_xxxxxyyz_0, g_0_xxxyyy_0_xxxxxyyz_1, g_0_xxxyyy_0_xxxxxyz_1, g_0_xxxyyy_0_xxxxxyzz_0, g_0_xxxyyy_0_xxxxxyzz_1, g_0_xxxyyy_0_xxxxyyy_1, g_0_xxxyyy_0_xxxxyyyy_0, g_0_xxxyyy_0_xxxxyyyy_1, g_0_xxxyyy_0_xxxxyyyz_0, g_0_xxxyyy_0_xxxxyyyz_1, g_0_xxxyyy_0_xxxxyyz_1, g_0_xxxyyy_0_xxxxyyzz_0, g_0_xxxyyy_0_xxxxyyzz_1, g_0_xxxyyy_0_xxxxyzz_1, g_0_xxxyyy_0_xxxxyzzz_0, g_0_xxxyyy_0_xxxxyzzz_1, g_0_xxxyyy_0_xxxyyyy_1, g_0_xxxyyy_0_xxxyyyyy_0, g_0_xxxyyy_0_xxxyyyyy_1, g_0_xxxyyy_0_xxxyyyyz_0, g_0_xxxyyy_0_xxxyyyyz_1, g_0_xxxyyy_0_xxxyyyz_1, g_0_xxxyyy_0_xxxyyyzz_0, g_0_xxxyyy_0_xxxyyyzz_1, g_0_xxxyyy_0_xxxyyzz_1, g_0_xxxyyy_0_xxxyyzzz_0, g_0_xxxyyy_0_xxxyyzzz_1, g_0_xxxyyy_0_xxxyzzz_1, g_0_xxxyyy_0_xxxyzzzz_0, g_0_xxxyyy_0_xxxyzzzz_1, g_0_xxxyyy_0_xxyyyyy_1, g_0_xxxyyy_0_xxyyyyyy_0, g_0_xxxyyy_0_xxyyyyyy_1, g_0_xxxyyy_0_xxyyyyyz_0, g_0_xxxyyy_0_xxyyyyyz_1, g_0_xxxyyy_0_xxyyyyz_1, g_0_xxxyyy_0_xxyyyyzz_0, g_0_xxxyyy_0_xxyyyyzz_1, g_0_xxxyyy_0_xxyyyzz_1, g_0_xxxyyy_0_xxyyyzzz_0, g_0_xxxyyy_0_xxyyyzzz_1, g_0_xxxyyy_0_xxyyzzz_1, g_0_xxxyyy_0_xxyyzzzz_0, g_0_xxxyyy_0_xxyyzzzz_1, g_0_xxxyyy_0_xxyzzzz_1, g_0_xxxyyy_0_xxyzzzzz_0, g_0_xxxyyy_0_xxyzzzzz_1, g_0_xxxyyy_0_xyyyyyy_1, g_0_xxxyyy_0_xyyyyyyy_0, g_0_xxxyyy_0_xyyyyyyy_1, g_0_xxxyyy_0_xyyyyyyz_0, g_0_xxxyyy_0_xyyyyyyz_1, g_0_xxxyyy_0_xyyyyyz_1, g_0_xxxyyy_0_xyyyyyzz_0, g_0_xxxyyy_0_xyyyyyzz_1, g_0_xxxyyy_0_xyyyyzz_1, g_0_xxxyyy_0_xyyyyzzz_0, g_0_xxxyyy_0_xyyyyzzz_1, g_0_xxxyyy_0_xyyyzzz_1, g_0_xxxyyy_0_xyyyzzzz_0, g_0_xxxyyy_0_xyyyzzzz_1, g_0_xxxyyy_0_xyyzzzz_1, g_0_xxxyyy_0_xyyzzzzz_0, g_0_xxxyyy_0_xyyzzzzz_1, g_0_xxxyyy_0_xyzzzzz_1, g_0_xxxyyy_0_xyzzzzzz_0, g_0_xxxyyy_0_xyzzzzzz_1, g_0_xxxyyy_0_yyyyyyy_1, g_0_xxxyyy_0_yyyyyyyy_0, g_0_xxxyyy_0_yyyyyyyy_1, g_0_xxxyyy_0_yyyyyyyz_0, g_0_xxxyyy_0_yyyyyyyz_1, g_0_xxxyyy_0_yyyyyyz_1, g_0_xxxyyy_0_yyyyyyzz_0, g_0_xxxyyy_0_yyyyyyzz_1, g_0_xxxyyy_0_yyyyyzz_1, g_0_xxxyyy_0_yyyyyzzz_0, g_0_xxxyyy_0_yyyyyzzz_1, g_0_xxxyyy_0_yyyyzzz_1, g_0_xxxyyy_0_yyyyzzzz_0, g_0_xxxyyy_0_yyyyzzzz_1, g_0_xxxyyy_0_yyyzzzz_1, g_0_xxxyyy_0_yyyzzzzz_0, g_0_xxxyyy_0_yyyzzzzz_1, g_0_xxxyyy_0_yyzzzzz_1, g_0_xxxyyy_0_yyzzzzzz_0, g_0_xxxyyy_0_yyzzzzzz_1, g_0_xxxyyy_0_yzzzzzz_1, g_0_xxxyyy_0_yzzzzzzz_0, g_0_xxxyyy_0_yzzzzzzz_1, g_0_xxxyyy_0_zzzzzzzz_0, g_0_xxxyyy_0_zzzzzzzz_1, g_0_xxyyy_0_xxxxxxxy_0, g_0_xxyyy_0_xxxxxxxy_1, g_0_xxyyy_0_xxxxxxyy_0, g_0_xxyyy_0_xxxxxxyy_1, g_0_xxyyy_0_xxxxxxyz_0, g_0_xxyyy_0_xxxxxxyz_1, g_0_xxyyy_0_xxxxxyyy_0, g_0_xxyyy_0_xxxxxyyy_1, g_0_xxyyy_0_xxxxxyyz_0, g_0_xxyyy_0_xxxxxyyz_1, g_0_xxyyy_0_xxxxxyzz_0, g_0_xxyyy_0_xxxxxyzz_1, g_0_xxyyy_0_xxxxyyyy_0, g_0_xxyyy_0_xxxxyyyy_1, g_0_xxyyy_0_xxxxyyyz_0, g_0_xxyyy_0_xxxxyyyz_1, g_0_xxyyy_0_xxxxyyzz_0, g_0_xxyyy_0_xxxxyyzz_1, g_0_xxyyy_0_xxxxyzzz_0, g_0_xxyyy_0_xxxxyzzz_1, g_0_xxyyy_0_xxxyyyyy_0, g_0_xxyyy_0_xxxyyyyy_1, g_0_xxyyy_0_xxxyyyyz_0, g_0_xxyyy_0_xxxyyyyz_1, g_0_xxyyy_0_xxxyyyzz_0, g_0_xxyyy_0_xxxyyyzz_1, g_0_xxyyy_0_xxxyyzzz_0, g_0_xxyyy_0_xxxyyzzz_1, g_0_xxyyy_0_xxxyzzzz_0, g_0_xxyyy_0_xxxyzzzz_1, g_0_xxyyy_0_xxyyyyyy_0, g_0_xxyyy_0_xxyyyyyy_1, g_0_xxyyy_0_xxyyyyyz_0, g_0_xxyyy_0_xxyyyyyz_1, g_0_xxyyy_0_xxyyyyzz_0, g_0_xxyyy_0_xxyyyyzz_1, g_0_xxyyy_0_xxyyyzzz_0, g_0_xxyyy_0_xxyyyzzz_1, g_0_xxyyy_0_xxyyzzzz_0, g_0_xxyyy_0_xxyyzzzz_1, g_0_xxyyy_0_xxyzzzzz_0, g_0_xxyyy_0_xxyzzzzz_1, g_0_xxyyy_0_xyyyyyyy_0, g_0_xxyyy_0_xyyyyyyy_1, g_0_xxyyy_0_xyyyyyyz_0, g_0_xxyyy_0_xyyyyyyz_1, g_0_xxyyy_0_xyyyyyzz_0, g_0_xxyyy_0_xyyyyyzz_1, g_0_xxyyy_0_xyyyyzzz_0, g_0_xxyyy_0_xyyyyzzz_1, g_0_xxyyy_0_xyyyzzzz_0, g_0_xxyyy_0_xyyyzzzz_1, g_0_xxyyy_0_xyyzzzzz_0, g_0_xxyyy_0_xyyzzzzz_1, g_0_xxyyy_0_xyzzzzzz_0, g_0_xxyyy_0_xyzzzzzz_1, g_0_xxyyy_0_yyyyyyyy_0, g_0_xxyyy_0_yyyyyyyy_1, g_0_xxyyy_0_yyyyyyyz_0, g_0_xxyyy_0_yyyyyyyz_1, g_0_xxyyy_0_yyyyyyzz_0, g_0_xxyyy_0_yyyyyyzz_1, g_0_xxyyy_0_yyyyyzzz_0, g_0_xxyyy_0_yyyyyzzz_1, g_0_xxyyy_0_yyyyzzzz_0, g_0_xxyyy_0_yyyyzzzz_1, g_0_xxyyy_0_yyyzzzzz_0, g_0_xxyyy_0_yyyzzzzz_1, g_0_xxyyy_0_yyzzzzzz_0, g_0_xxyyy_0_yyzzzzzz_1, g_0_xxyyy_0_yzzzzzzz_0, g_0_xxyyy_0_yzzzzzzz_1, g_0_xxyyy_0_zzzzzzzz_0, g_0_xxyyy_0_zzzzzzzz_1, wp_x, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxxyyy_0_xxxxxxxx_0[i] = 2.0 * g_0_xxxxy_0_xxxxxxxx_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxxxxxx_0[i] * pb_y + g_0_xxxxyy_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxxxxxxy_0[i] = 3.0 * g_0_xxyyy_0_xxxxxxxy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxxxy_1[i] * fti_ab_0 + 7.0 * g_0_xxxyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxxy_0[i] * pb_x + g_0_xxxyyy_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxxxz_0[i] = 2.0 * g_0_xxxxy_0_xxxxxxxz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxxxxxz_0[i] * pb_y + g_0_xxxxyy_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxxxxxyy_0[i] = 3.0 * g_0_xxyyy_0_xxxxxxyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxxyy_1[i] * fti_ab_0 + 6.0 * g_0_xxxyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxyy_0[i] * pb_x + g_0_xxxyyy_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxxyz_0[i] = 3.0 * g_0_xxyyy_0_xxxxxxyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxxyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxyz_0[i] * pb_x + g_0_xxxyyy_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxxzz_0[i] = 2.0 * g_0_xxxxy_0_xxxxxxzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxxxxzz_0[i] * pb_y + g_0_xxxxyy_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxxxxyyy_0[i] = 3.0 * g_0_xxyyy_0_xxxxxyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxyyy_1[i] * fti_ab_0 + 5.0 * g_0_xxxyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxyyy_0[i] * pb_x + g_0_xxxyyy_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxyyz_0[i] = 3.0 * g_0_xxyyy_0_xxxxxyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxxyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxyyz_0[i] * pb_x + g_0_xxxyyy_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxyzz_0[i] = 3.0 * g_0_xxyyy_0_xxxxxyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxyzz_0[i] * pb_x + g_0_xxxyyy_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxxzzz_0[i] = 2.0 * g_0_xxxxy_0_xxxxxzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxxxzzz_0[i] * pb_y + g_0_xxxxyy_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxxxyyyy_0[i] = 3.0 * g_0_xxyyy_0_xxxxyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_xxxyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyyyy_0[i] * pb_x + g_0_xxxyyy_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxyyyz_0[i] = 3.0 * g_0_xxyyy_0_xxxxyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxxyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyyyz_0[i] * pb_x + g_0_xxxyyy_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxyyzz_0[i] = 3.0 * g_0_xxyyy_0_xxxxyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyyzz_0[i] * pb_x + g_0_xxxyyy_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxyzzz_0[i] = 3.0 * g_0_xxyyy_0_xxxxyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyzzz_0[i] * pb_x + g_0_xxxyyy_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxxzzzz_0[i] = 2.0 * g_0_xxxxy_0_xxxxzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxxzzzz_0[i] * pb_y + g_0_xxxxyy_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxxyyyyy_0[i] = 3.0 * g_0_xxyyy_0_xxxyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxyyyyy_1[i] * fti_ab_0 + 3.0 * g_0_xxxyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyyyy_0[i] * pb_x + g_0_xxxyyy_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxyyyyz_0[i] = 3.0 * g_0_xxyyy_0_xxxyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxxyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyyyz_0[i] * pb_x + g_0_xxxyyy_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxyyyzz_0[i] = 3.0 * g_0_xxyyy_0_xxxyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyyzz_0[i] * pb_x + g_0_xxxyyy_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxyyzzz_0[i] = 3.0 * g_0_xxyyy_0_xxxyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyzzz_0[i] * pb_x + g_0_xxxyyy_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxyzzzz_0[i] = 3.0 * g_0_xxyyy_0_xxxyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyzzzz_0[i] * pb_x + g_0_xxxyyy_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxxzzzzz_0[i] = 2.0 * g_0_xxxxy_0_xxxzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxxzzzzz_0[i] * pb_y + g_0_xxxxyy_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xxyyyyyy_0[i] = 3.0 * g_0_xxyyy_0_xxyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyyyyyy_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyyyy_0[i] * pb_x + g_0_xxxyyy_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxyyyyyz_0[i] = 3.0 * g_0_xxyyy_0_xxyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyyyz_0[i] * pb_x + g_0_xxxyyy_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxyyyyzz_0[i] = 3.0 * g_0_xxyyy_0_xxyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyyzz_0[i] * pb_x + g_0_xxxyyy_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxyyyzzz_0[i] = 3.0 * g_0_xxyyy_0_xxyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyzzz_0[i] * pb_x + g_0_xxxyyy_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxyyzzzz_0[i] = 3.0 * g_0_xxyyy_0_xxyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyzzzz_0[i] * pb_x + g_0_xxxyyy_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxyzzzzz_0[i] = 3.0 * g_0_xxyyy_0_xxyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyzzzzz_0[i] * pb_x + g_0_xxxyyy_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xxzzzzzz_0[i] = 2.0 * g_0_xxxxy_0_xxzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xxzzzzzz_0[i] * pb_y + g_0_xxxxyy_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_xyyyyyyy_0[i] = 3.0 * g_0_xxyyy_0_xyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyyyy_0[i] * pb_x + g_0_xxxyyy_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyyyyyyz_0[i] = 3.0 * g_0_xxyyy_0_xyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyyyz_0[i] * pb_x + g_0_xxxyyy_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyyyyyzz_0[i] = 3.0 * g_0_xxyyy_0_xyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyyzz_0[i] * pb_x + g_0_xxxyyy_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyyyyzzz_0[i] = 3.0 * g_0_xxyyy_0_xyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyzzz_0[i] * pb_x + g_0_xxxyyy_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyyyzzzz_0[i] = 3.0 * g_0_xxyyy_0_xyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyzzzz_0[i] * pb_x + g_0_xxxyyy_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyyzzzzz_0[i] = 3.0 * g_0_xxyyy_0_xyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyzzzzz_0[i] * pb_x + g_0_xxxyyy_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xyzzzzzz_0[i] = 3.0 * g_0_xxyyy_0_xyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyzzzzzz_0[i] * pb_x + g_0_xxxyyy_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_xzzzzzzz_0[i] = 2.0 * g_0_xxxxy_0_xzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxxxy_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxxyy_0_xzzzzzzz_0[i] * pb_y + g_0_xxxxyy_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyyy_0_yyyyyyyy_0[i] = 3.0 * g_0_xxyyy_0_yyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyyyy_0[i] * pb_x + g_0_xxxyyy_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyyyyyyz_0[i] = 3.0 * g_0_xxyyy_0_yyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyyyz_0[i] * pb_x + g_0_xxxyyy_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyyyyyzz_0[i] = 3.0 * g_0_xxyyy_0_yyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyyzz_0[i] * pb_x + g_0_xxxyyy_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyyyyzzz_0[i] = 3.0 * g_0_xxyyy_0_yyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyyzzz_0[i] * pb_x + g_0_xxxyyy_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyyyzzzz_0[i] = 3.0 * g_0_xxyyy_0_yyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyyzzzz_0[i] * pb_x + g_0_xxxyyy_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyyzzzzz_0[i] = 3.0 * g_0_xxyyy_0_yyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyyzzzzz_0[i] * pb_x + g_0_xxxyyy_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yyzzzzzz_0[i] = 3.0 * g_0_xxyyy_0_yyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yyzzzzzz_0[i] * pb_x + g_0_xxxyyy_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_yzzzzzzz_0[i] = 3.0 * g_0_xxyyy_0_yzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_yzzzzzzz_0[i] * pb_x + g_0_xxxyyy_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxyyy_0_zzzzzzzz_0[i] = 3.0 * g_0_xxyyy_0_zzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxyyy_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_zzzzzzzz_0[i] * pb_x + g_0_xxxyyy_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 315-360 components of targeted buffer : SKSL

    auto g_0_xxxxyyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 315);

    auto g_0_xxxxyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 316);

    auto g_0_xxxxyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 317);

    auto g_0_xxxxyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 318);

    auto g_0_xxxxyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 319);

    auto g_0_xxxxyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 320);

    auto g_0_xxxxyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 321);

    auto g_0_xxxxyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 322);

    auto g_0_xxxxyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 323);

    auto g_0_xxxxyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 324);

    auto g_0_xxxxyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 325);

    auto g_0_xxxxyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 326);

    auto g_0_xxxxyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 327);

    auto g_0_xxxxyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 328);

    auto g_0_xxxxyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 329);

    auto g_0_xxxxyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 330);

    auto g_0_xxxxyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 331);

    auto g_0_xxxxyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 332);

    auto g_0_xxxxyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 333);

    auto g_0_xxxxyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 334);

    auto g_0_xxxxyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 335);

    auto g_0_xxxxyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 336);

    auto g_0_xxxxyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 337);

    auto g_0_xxxxyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 338);

    auto g_0_xxxxyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 339);

    auto g_0_xxxxyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 340);

    auto g_0_xxxxyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 341);

    auto g_0_xxxxyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 342);

    auto g_0_xxxxyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 343);

    auto g_0_xxxxyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 344);

    auto g_0_xxxxyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 345);

    auto g_0_xxxxyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 346);

    auto g_0_xxxxyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 347);

    auto g_0_xxxxyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 348);

    auto g_0_xxxxyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 349);

    auto g_0_xxxxyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 350);

    auto g_0_xxxxyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 351);

    auto g_0_xxxxyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 352);

    auto g_0_xxxxyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 353);

    auto g_0_xxxxyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 354);

    auto g_0_xxxxyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 355);

    auto g_0_xxxxyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 356);

    auto g_0_xxxxyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 357);

    auto g_0_xxxxyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 358);

    auto g_0_xxxxyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 359);

    #pragma omp simd aligned(g_0_xxxxyy_0_xxxxxxx_1, g_0_xxxxyy_0_xxxxxxxx_0, g_0_xxxxyy_0_xxxxxxxx_1, g_0_xxxxyy_0_xxxxxxxy_0, g_0_xxxxyy_0_xxxxxxxy_1, g_0_xxxxyy_0_xxxxxxxz_0, g_0_xxxxyy_0_xxxxxxxz_1, g_0_xxxxyy_0_xxxxxxy_1, g_0_xxxxyy_0_xxxxxxyy_0, g_0_xxxxyy_0_xxxxxxyy_1, g_0_xxxxyy_0_xxxxxxyz_0, g_0_xxxxyy_0_xxxxxxyz_1, g_0_xxxxyy_0_xxxxxxz_1, g_0_xxxxyy_0_xxxxxxzz_0, g_0_xxxxyy_0_xxxxxxzz_1, g_0_xxxxyy_0_xxxxxyy_1, g_0_xxxxyy_0_xxxxxyyy_0, g_0_xxxxyy_0_xxxxxyyy_1, g_0_xxxxyy_0_xxxxxyyz_0, g_0_xxxxyy_0_xxxxxyyz_1, g_0_xxxxyy_0_xxxxxyz_1, g_0_xxxxyy_0_xxxxxyzz_0, g_0_xxxxyy_0_xxxxxyzz_1, g_0_xxxxyy_0_xxxxxzz_1, g_0_xxxxyy_0_xxxxxzzz_0, g_0_xxxxyy_0_xxxxxzzz_1, g_0_xxxxyy_0_xxxxyyy_1, g_0_xxxxyy_0_xxxxyyyy_0, g_0_xxxxyy_0_xxxxyyyy_1, g_0_xxxxyy_0_xxxxyyyz_0, g_0_xxxxyy_0_xxxxyyyz_1, g_0_xxxxyy_0_xxxxyyz_1, g_0_xxxxyy_0_xxxxyyzz_0, g_0_xxxxyy_0_xxxxyyzz_1, g_0_xxxxyy_0_xxxxyzz_1, g_0_xxxxyy_0_xxxxyzzz_0, g_0_xxxxyy_0_xxxxyzzz_1, g_0_xxxxyy_0_xxxxzzz_1, g_0_xxxxyy_0_xxxxzzzz_0, g_0_xxxxyy_0_xxxxzzzz_1, g_0_xxxxyy_0_xxxyyyy_1, g_0_xxxxyy_0_xxxyyyyy_0, g_0_xxxxyy_0_xxxyyyyy_1, g_0_xxxxyy_0_xxxyyyyz_0, g_0_xxxxyy_0_xxxyyyyz_1, g_0_xxxxyy_0_xxxyyyz_1, g_0_xxxxyy_0_xxxyyyzz_0, g_0_xxxxyy_0_xxxyyyzz_1, g_0_xxxxyy_0_xxxyyzz_1, g_0_xxxxyy_0_xxxyyzzz_0, g_0_xxxxyy_0_xxxyyzzz_1, g_0_xxxxyy_0_xxxyzzz_1, g_0_xxxxyy_0_xxxyzzzz_0, g_0_xxxxyy_0_xxxyzzzz_1, g_0_xxxxyy_0_xxxzzzz_1, g_0_xxxxyy_0_xxxzzzzz_0, g_0_xxxxyy_0_xxxzzzzz_1, g_0_xxxxyy_0_xxyyyyy_1, g_0_xxxxyy_0_xxyyyyyy_0, g_0_xxxxyy_0_xxyyyyyy_1, g_0_xxxxyy_0_xxyyyyyz_0, g_0_xxxxyy_0_xxyyyyyz_1, g_0_xxxxyy_0_xxyyyyz_1, g_0_xxxxyy_0_xxyyyyzz_0, g_0_xxxxyy_0_xxyyyyzz_1, g_0_xxxxyy_0_xxyyyzz_1, g_0_xxxxyy_0_xxyyyzzz_0, g_0_xxxxyy_0_xxyyyzzz_1, g_0_xxxxyy_0_xxyyzzz_1, g_0_xxxxyy_0_xxyyzzzz_0, g_0_xxxxyy_0_xxyyzzzz_1, g_0_xxxxyy_0_xxyzzzz_1, g_0_xxxxyy_0_xxyzzzzz_0, g_0_xxxxyy_0_xxyzzzzz_1, g_0_xxxxyy_0_xxzzzzz_1, g_0_xxxxyy_0_xxzzzzzz_0, g_0_xxxxyy_0_xxzzzzzz_1, g_0_xxxxyy_0_xyyyyyy_1, g_0_xxxxyy_0_xyyyyyyy_0, g_0_xxxxyy_0_xyyyyyyy_1, g_0_xxxxyy_0_xyyyyyyz_0, g_0_xxxxyy_0_xyyyyyyz_1, g_0_xxxxyy_0_xyyyyyz_1, g_0_xxxxyy_0_xyyyyyzz_0, g_0_xxxxyy_0_xyyyyyzz_1, g_0_xxxxyy_0_xyyyyzz_1, g_0_xxxxyy_0_xyyyyzzz_0, g_0_xxxxyy_0_xyyyyzzz_1, g_0_xxxxyy_0_xyyyzzz_1, g_0_xxxxyy_0_xyyyzzzz_0, g_0_xxxxyy_0_xyyyzzzz_1, g_0_xxxxyy_0_xyyzzzz_1, g_0_xxxxyy_0_xyyzzzzz_0, g_0_xxxxyy_0_xyyzzzzz_1, g_0_xxxxyy_0_xyzzzzz_1, g_0_xxxxyy_0_xyzzzzzz_0, g_0_xxxxyy_0_xyzzzzzz_1, g_0_xxxxyy_0_xzzzzzz_1, g_0_xxxxyy_0_xzzzzzzz_0, g_0_xxxxyy_0_xzzzzzzz_1, g_0_xxxxyy_0_yyyyyyy_1, g_0_xxxxyy_0_yyyyyyyy_0, g_0_xxxxyy_0_yyyyyyyy_1, g_0_xxxxyy_0_yyyyyyyz_0, g_0_xxxxyy_0_yyyyyyyz_1, g_0_xxxxyy_0_yyyyyyz_1, g_0_xxxxyy_0_yyyyyyzz_0, g_0_xxxxyy_0_yyyyyyzz_1, g_0_xxxxyy_0_yyyyyzz_1, g_0_xxxxyy_0_yyyyyzzz_0, g_0_xxxxyy_0_yyyyyzzz_1, g_0_xxxxyy_0_yyyyzzz_1, g_0_xxxxyy_0_yyyyzzzz_0, g_0_xxxxyy_0_yyyyzzzz_1, g_0_xxxxyy_0_yyyzzzz_1, g_0_xxxxyy_0_yyyzzzzz_0, g_0_xxxxyy_0_yyyzzzzz_1, g_0_xxxxyy_0_yyzzzzz_1, g_0_xxxxyy_0_yyzzzzzz_0, g_0_xxxxyy_0_yyzzzzzz_1, g_0_xxxxyy_0_yzzzzzz_1, g_0_xxxxyy_0_yzzzzzzz_0, g_0_xxxxyy_0_yzzzzzzz_1, g_0_xxxxyy_0_zzzzzzz_1, g_0_xxxxyy_0_zzzzzzzz_0, g_0_xxxxyy_0_zzzzzzzz_1, g_0_xxxxyyz_0_xxxxxxxx_0, g_0_xxxxyyz_0_xxxxxxxy_0, g_0_xxxxyyz_0_xxxxxxxz_0, g_0_xxxxyyz_0_xxxxxxyy_0, g_0_xxxxyyz_0_xxxxxxyz_0, g_0_xxxxyyz_0_xxxxxxzz_0, g_0_xxxxyyz_0_xxxxxyyy_0, g_0_xxxxyyz_0_xxxxxyyz_0, g_0_xxxxyyz_0_xxxxxyzz_0, g_0_xxxxyyz_0_xxxxxzzz_0, g_0_xxxxyyz_0_xxxxyyyy_0, g_0_xxxxyyz_0_xxxxyyyz_0, g_0_xxxxyyz_0_xxxxyyzz_0, g_0_xxxxyyz_0_xxxxyzzz_0, g_0_xxxxyyz_0_xxxxzzzz_0, g_0_xxxxyyz_0_xxxyyyyy_0, g_0_xxxxyyz_0_xxxyyyyz_0, g_0_xxxxyyz_0_xxxyyyzz_0, g_0_xxxxyyz_0_xxxyyzzz_0, g_0_xxxxyyz_0_xxxyzzzz_0, g_0_xxxxyyz_0_xxxzzzzz_0, g_0_xxxxyyz_0_xxyyyyyy_0, g_0_xxxxyyz_0_xxyyyyyz_0, g_0_xxxxyyz_0_xxyyyyzz_0, g_0_xxxxyyz_0_xxyyyzzz_0, g_0_xxxxyyz_0_xxyyzzzz_0, g_0_xxxxyyz_0_xxyzzzzz_0, g_0_xxxxyyz_0_xxzzzzzz_0, g_0_xxxxyyz_0_xyyyyyyy_0, g_0_xxxxyyz_0_xyyyyyyz_0, g_0_xxxxyyz_0_xyyyyyzz_0, g_0_xxxxyyz_0_xyyyyzzz_0, g_0_xxxxyyz_0_xyyyzzzz_0, g_0_xxxxyyz_0_xyyzzzzz_0, g_0_xxxxyyz_0_xyzzzzzz_0, g_0_xxxxyyz_0_xzzzzzzz_0, g_0_xxxxyyz_0_yyyyyyyy_0, g_0_xxxxyyz_0_yyyyyyyz_0, g_0_xxxxyyz_0_yyyyyyzz_0, g_0_xxxxyyz_0_yyyyyzzz_0, g_0_xxxxyyz_0_yyyyzzzz_0, g_0_xxxxyyz_0_yyyzzzzz_0, g_0_xxxxyyz_0_yyzzzzzz_0, g_0_xxxxyyz_0_yzzzzzzz_0, g_0_xxxxyyz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxxyyz_0_xxxxxxxx_0[i] = g_0_xxxxyy_0_xxxxxxxx_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxxxy_0[i] = g_0_xxxxyy_0_xxxxxxxy_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxxxz_0[i] = g_0_xxxxyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxxz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxxyy_0[i] = g_0_xxxxyy_0_xxxxxxyy_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxxyz_0[i] = g_0_xxxxyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxyz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxxzz_0[i] = 2.0 * g_0_xxxxyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxxzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxyyy_0[i] = g_0_xxxxyy_0_xxxxxyyy_0[i] * pb_z + g_0_xxxxyy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxyyz_0[i] = g_0_xxxxyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxyyz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxyzz_0[i] = 2.0 * g_0_xxxxyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxyzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxxzzz_0[i] = 3.0 * g_0_xxxxyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxxzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxyyyy_0[i] = g_0_xxxxyy_0_xxxxyyyy_0[i] * pb_z + g_0_xxxxyy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxyyyz_0[i] = g_0_xxxxyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyyyz_0[i] * pb_z + g_0_xxxxyy_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxxyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyyzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxyzzz_0[i] = 3.0 * g_0_xxxxyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxyzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxxzzzz_0[i] = 4.0 * g_0_xxxxyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxxzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxyyyyy_0[i] = g_0_xxxxyy_0_xxxyyyyy_0[i] * pb_z + g_0_xxxxyy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxyyyyz_0[i] = g_0_xxxxyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyyyz_0[i] * pb_z + g_0_xxxxyy_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxyyyzz_0[i] = 2.0 * g_0_xxxxyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyyzz_0[i] * pb_z + g_0_xxxxyy_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxyyzzz_0[i] = 3.0 * g_0_xxxxyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyyzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxyzzzz_0[i] = 4.0 * g_0_xxxxyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxyzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxxzzzzz_0[i] = 5.0 * g_0_xxxxyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxxzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyyyyyy_0[i] = g_0_xxxxyy_0_xxyyyyyy_0[i] * pb_z + g_0_xxxxyy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyyyyyz_0[i] = g_0_xxxxyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyyyz_0[i] * pb_z + g_0_xxxxyy_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyyyyzz_0[i] = 2.0 * g_0_xxxxyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyyzz_0[i] * pb_z + g_0_xxxxyy_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxxyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyyzzz_0[i] * pb_z + g_0_xxxxyy_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyyzzzz_0[i] = 4.0 * g_0_xxxxyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyyzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxyzzzzz_0[i] = 5.0 * g_0_xxxxyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxyzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xxzzzzzz_0[i] = 6.0 * g_0_xxxxyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xxzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyyyyyy_0[i] = g_0_xxxxyy_0_xyyyyyyy_0[i] * pb_z + g_0_xxxxyy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyyyyyz_0[i] = g_0_xxxxyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyyyz_0[i] * pb_z + g_0_xxxxyy_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyyyyzz_0[i] = 2.0 * g_0_xxxxyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyyzz_0[i] * pb_z + g_0_xxxxyy_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyyyzzz_0[i] = 3.0 * g_0_xxxxyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyyzzz_0[i] * pb_z + g_0_xxxxyy_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyyzzzz_0[i] = 4.0 * g_0_xxxxyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyyzzzz_0[i] * pb_z + g_0_xxxxyy_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyyzzzzz_0[i] = 5.0 * g_0_xxxxyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyyzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xyzzzzzz_0[i] = 6.0 * g_0_xxxxyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xyzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_xzzzzzzz_0[i] = 7.0 * g_0_xxxxyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_xzzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyyyyyy_0[i] = g_0_xxxxyy_0_yyyyyyyy_0[i] * pb_z + g_0_xxxxyy_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyyyyyz_0[i] = g_0_xxxxyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyyyyyyz_0[i] * pb_z + g_0_xxxxyy_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyyyyzz_0[i] = 2.0 * g_0_xxxxyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyyyyyzz_0[i] * pb_z + g_0_xxxxyy_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyyyzzz_0[i] = 3.0 * g_0_xxxxyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyyyyzzz_0[i] * pb_z + g_0_xxxxyy_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxxyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyyyzzzz_0[i] * pb_z + g_0_xxxxyy_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyyzzzzz_0[i] = 5.0 * g_0_xxxxyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyyzzzzz_0[i] * pb_z + g_0_xxxxyy_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yyzzzzzz_0[i] = 6.0 * g_0_xxxxyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yyzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_yzzzzzzz_0[i] = 7.0 * g_0_xxxxyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_yzzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_xxxxyyz_0_zzzzzzzz_0[i] = 8.0 * g_0_xxxxyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxyy_0_zzzzzzzz_0[i] * pb_z + g_0_xxxxyy_0_zzzzzzzz_1[i] * wp_z[i];
    }

    /// Set up 360-405 components of targeted buffer : SKSL

    auto g_0_xxxxyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 360);

    auto g_0_xxxxyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 361);

    auto g_0_xxxxyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 362);

    auto g_0_xxxxyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 363);

    auto g_0_xxxxyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 364);

    auto g_0_xxxxyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 365);

    auto g_0_xxxxyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 366);

    auto g_0_xxxxyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 367);

    auto g_0_xxxxyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 368);

    auto g_0_xxxxyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 369);

    auto g_0_xxxxyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 370);

    auto g_0_xxxxyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 371);

    auto g_0_xxxxyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 372);

    auto g_0_xxxxyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 373);

    auto g_0_xxxxyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 374);

    auto g_0_xxxxyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 375);

    auto g_0_xxxxyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 376);

    auto g_0_xxxxyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 377);

    auto g_0_xxxxyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 378);

    auto g_0_xxxxyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 379);

    auto g_0_xxxxyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 380);

    auto g_0_xxxxyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 381);

    auto g_0_xxxxyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 382);

    auto g_0_xxxxyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 383);

    auto g_0_xxxxyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 384);

    auto g_0_xxxxyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 385);

    auto g_0_xxxxyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 386);

    auto g_0_xxxxyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 387);

    auto g_0_xxxxyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 388);

    auto g_0_xxxxyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 389);

    auto g_0_xxxxyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 390);

    auto g_0_xxxxyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 391);

    auto g_0_xxxxyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 392);

    auto g_0_xxxxyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 393);

    auto g_0_xxxxyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 394);

    auto g_0_xxxxyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 395);

    auto g_0_xxxxyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 396);

    auto g_0_xxxxyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 397);

    auto g_0_xxxxyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 398);

    auto g_0_xxxxyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 399);

    auto g_0_xxxxyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 400);

    auto g_0_xxxxyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 401);

    auto g_0_xxxxyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 402);

    auto g_0_xxxxyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 403);

    auto g_0_xxxxyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 404);

    #pragma omp simd aligned(g_0_xxxxyzz_0_xxxxxxxx_0, g_0_xxxxyzz_0_xxxxxxxy_0, g_0_xxxxyzz_0_xxxxxxxz_0, g_0_xxxxyzz_0_xxxxxxyy_0, g_0_xxxxyzz_0_xxxxxxyz_0, g_0_xxxxyzz_0_xxxxxxzz_0, g_0_xxxxyzz_0_xxxxxyyy_0, g_0_xxxxyzz_0_xxxxxyyz_0, g_0_xxxxyzz_0_xxxxxyzz_0, g_0_xxxxyzz_0_xxxxxzzz_0, g_0_xxxxyzz_0_xxxxyyyy_0, g_0_xxxxyzz_0_xxxxyyyz_0, g_0_xxxxyzz_0_xxxxyyzz_0, g_0_xxxxyzz_0_xxxxyzzz_0, g_0_xxxxyzz_0_xxxxzzzz_0, g_0_xxxxyzz_0_xxxyyyyy_0, g_0_xxxxyzz_0_xxxyyyyz_0, g_0_xxxxyzz_0_xxxyyyzz_0, g_0_xxxxyzz_0_xxxyyzzz_0, g_0_xxxxyzz_0_xxxyzzzz_0, g_0_xxxxyzz_0_xxxzzzzz_0, g_0_xxxxyzz_0_xxyyyyyy_0, g_0_xxxxyzz_0_xxyyyyyz_0, g_0_xxxxyzz_0_xxyyyyzz_0, g_0_xxxxyzz_0_xxyyyzzz_0, g_0_xxxxyzz_0_xxyyzzzz_0, g_0_xxxxyzz_0_xxyzzzzz_0, g_0_xxxxyzz_0_xxzzzzzz_0, g_0_xxxxyzz_0_xyyyyyyy_0, g_0_xxxxyzz_0_xyyyyyyz_0, g_0_xxxxyzz_0_xyyyyyzz_0, g_0_xxxxyzz_0_xyyyyzzz_0, g_0_xxxxyzz_0_xyyyzzzz_0, g_0_xxxxyzz_0_xyyzzzzz_0, g_0_xxxxyzz_0_xyzzzzzz_0, g_0_xxxxyzz_0_xzzzzzzz_0, g_0_xxxxyzz_0_yyyyyyyy_0, g_0_xxxxyzz_0_yyyyyyyz_0, g_0_xxxxyzz_0_yyyyyyzz_0, g_0_xxxxyzz_0_yyyyyzzz_0, g_0_xxxxyzz_0_yyyyzzzz_0, g_0_xxxxyzz_0_yyyzzzzz_0, g_0_xxxxyzz_0_yyzzzzzz_0, g_0_xxxxyzz_0_yzzzzzzz_0, g_0_xxxxyzz_0_zzzzzzzz_0, g_0_xxxxzz_0_xxxxxxx_1, g_0_xxxxzz_0_xxxxxxxx_0, g_0_xxxxzz_0_xxxxxxxx_1, g_0_xxxxzz_0_xxxxxxxy_0, g_0_xxxxzz_0_xxxxxxxy_1, g_0_xxxxzz_0_xxxxxxxz_0, g_0_xxxxzz_0_xxxxxxxz_1, g_0_xxxxzz_0_xxxxxxy_1, g_0_xxxxzz_0_xxxxxxyy_0, g_0_xxxxzz_0_xxxxxxyy_1, g_0_xxxxzz_0_xxxxxxyz_0, g_0_xxxxzz_0_xxxxxxyz_1, g_0_xxxxzz_0_xxxxxxz_1, g_0_xxxxzz_0_xxxxxxzz_0, g_0_xxxxzz_0_xxxxxxzz_1, g_0_xxxxzz_0_xxxxxyy_1, g_0_xxxxzz_0_xxxxxyyy_0, g_0_xxxxzz_0_xxxxxyyy_1, g_0_xxxxzz_0_xxxxxyyz_0, g_0_xxxxzz_0_xxxxxyyz_1, g_0_xxxxzz_0_xxxxxyz_1, g_0_xxxxzz_0_xxxxxyzz_0, g_0_xxxxzz_0_xxxxxyzz_1, g_0_xxxxzz_0_xxxxxzz_1, g_0_xxxxzz_0_xxxxxzzz_0, g_0_xxxxzz_0_xxxxxzzz_1, g_0_xxxxzz_0_xxxxyyy_1, g_0_xxxxzz_0_xxxxyyyy_0, g_0_xxxxzz_0_xxxxyyyy_1, g_0_xxxxzz_0_xxxxyyyz_0, g_0_xxxxzz_0_xxxxyyyz_1, g_0_xxxxzz_0_xxxxyyz_1, g_0_xxxxzz_0_xxxxyyzz_0, g_0_xxxxzz_0_xxxxyyzz_1, g_0_xxxxzz_0_xxxxyzz_1, g_0_xxxxzz_0_xxxxyzzz_0, g_0_xxxxzz_0_xxxxyzzz_1, g_0_xxxxzz_0_xxxxzzz_1, g_0_xxxxzz_0_xxxxzzzz_0, g_0_xxxxzz_0_xxxxzzzz_1, g_0_xxxxzz_0_xxxyyyy_1, g_0_xxxxzz_0_xxxyyyyy_0, g_0_xxxxzz_0_xxxyyyyy_1, g_0_xxxxzz_0_xxxyyyyz_0, g_0_xxxxzz_0_xxxyyyyz_1, g_0_xxxxzz_0_xxxyyyz_1, g_0_xxxxzz_0_xxxyyyzz_0, g_0_xxxxzz_0_xxxyyyzz_1, g_0_xxxxzz_0_xxxyyzz_1, g_0_xxxxzz_0_xxxyyzzz_0, g_0_xxxxzz_0_xxxyyzzz_1, g_0_xxxxzz_0_xxxyzzz_1, g_0_xxxxzz_0_xxxyzzzz_0, g_0_xxxxzz_0_xxxyzzzz_1, g_0_xxxxzz_0_xxxzzzz_1, g_0_xxxxzz_0_xxxzzzzz_0, g_0_xxxxzz_0_xxxzzzzz_1, g_0_xxxxzz_0_xxyyyyy_1, g_0_xxxxzz_0_xxyyyyyy_0, g_0_xxxxzz_0_xxyyyyyy_1, g_0_xxxxzz_0_xxyyyyyz_0, g_0_xxxxzz_0_xxyyyyyz_1, g_0_xxxxzz_0_xxyyyyz_1, g_0_xxxxzz_0_xxyyyyzz_0, g_0_xxxxzz_0_xxyyyyzz_1, g_0_xxxxzz_0_xxyyyzz_1, g_0_xxxxzz_0_xxyyyzzz_0, g_0_xxxxzz_0_xxyyyzzz_1, g_0_xxxxzz_0_xxyyzzz_1, g_0_xxxxzz_0_xxyyzzzz_0, g_0_xxxxzz_0_xxyyzzzz_1, g_0_xxxxzz_0_xxyzzzz_1, g_0_xxxxzz_0_xxyzzzzz_0, g_0_xxxxzz_0_xxyzzzzz_1, g_0_xxxxzz_0_xxzzzzz_1, g_0_xxxxzz_0_xxzzzzzz_0, g_0_xxxxzz_0_xxzzzzzz_1, g_0_xxxxzz_0_xyyyyyy_1, g_0_xxxxzz_0_xyyyyyyy_0, g_0_xxxxzz_0_xyyyyyyy_1, g_0_xxxxzz_0_xyyyyyyz_0, g_0_xxxxzz_0_xyyyyyyz_1, g_0_xxxxzz_0_xyyyyyz_1, g_0_xxxxzz_0_xyyyyyzz_0, g_0_xxxxzz_0_xyyyyyzz_1, g_0_xxxxzz_0_xyyyyzz_1, g_0_xxxxzz_0_xyyyyzzz_0, g_0_xxxxzz_0_xyyyyzzz_1, g_0_xxxxzz_0_xyyyzzz_1, g_0_xxxxzz_0_xyyyzzzz_0, g_0_xxxxzz_0_xyyyzzzz_1, g_0_xxxxzz_0_xyyzzzz_1, g_0_xxxxzz_0_xyyzzzzz_0, g_0_xxxxzz_0_xyyzzzzz_1, g_0_xxxxzz_0_xyzzzzz_1, g_0_xxxxzz_0_xyzzzzzz_0, g_0_xxxxzz_0_xyzzzzzz_1, g_0_xxxxzz_0_xzzzzzz_1, g_0_xxxxzz_0_xzzzzzzz_0, g_0_xxxxzz_0_xzzzzzzz_1, g_0_xxxxzz_0_yyyyyyy_1, g_0_xxxxzz_0_yyyyyyyy_0, g_0_xxxxzz_0_yyyyyyyy_1, g_0_xxxxzz_0_yyyyyyyz_0, g_0_xxxxzz_0_yyyyyyyz_1, g_0_xxxxzz_0_yyyyyyz_1, g_0_xxxxzz_0_yyyyyyzz_0, g_0_xxxxzz_0_yyyyyyzz_1, g_0_xxxxzz_0_yyyyyzz_1, g_0_xxxxzz_0_yyyyyzzz_0, g_0_xxxxzz_0_yyyyyzzz_1, g_0_xxxxzz_0_yyyyzzz_1, g_0_xxxxzz_0_yyyyzzzz_0, g_0_xxxxzz_0_yyyyzzzz_1, g_0_xxxxzz_0_yyyzzzz_1, g_0_xxxxzz_0_yyyzzzzz_0, g_0_xxxxzz_0_yyyzzzzz_1, g_0_xxxxzz_0_yyzzzzz_1, g_0_xxxxzz_0_yyzzzzzz_0, g_0_xxxxzz_0_yyzzzzzz_1, g_0_xxxxzz_0_yzzzzzz_1, g_0_xxxxzz_0_yzzzzzzz_0, g_0_xxxxzz_0_yzzzzzzz_1, g_0_xxxxzz_0_zzzzzzz_1, g_0_xxxxzz_0_zzzzzzzz_0, g_0_xxxxzz_0_zzzzzzzz_1, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxxyzz_0_xxxxxxxx_0[i] = g_0_xxxxzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxxxy_0[i] = g_0_xxxxzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxxy_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxxxz_0[i] = g_0_xxxxzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxxyy_0[i] = 2.0 * g_0_xxxxzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxyy_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxxyz_0[i] = g_0_xxxxzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxxyz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxxzz_0[i] = g_0_xxxxzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxyyy_0[i] = 3.0 * g_0_xxxxzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxyyy_0[i] * pb_y + g_0_xxxxzz_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxyyz_0[i] = 2.0 * g_0_xxxxzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxyyz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxyzz_0[i] = g_0_xxxxzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxxyzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxxzzz_0[i] = g_0_xxxxzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxyyyy_0[i] = 4.0 * g_0_xxxxzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyyyy_0[i] * pb_y + g_0_xxxxzz_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxyyyz_0[i] = 3.0 * g_0_xxxxzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyyyz_0[i] * pb_y + g_0_xxxxzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxxzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyyzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxyzzz_0[i] = g_0_xxxxzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxxyzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxxzzzz_0[i] = g_0_xxxxzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxyyyyy_0[i] = 5.0 * g_0_xxxxzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyyyy_0[i] * pb_y + g_0_xxxxzz_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxxzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyyyz_0[i] * pb_y + g_0_xxxxzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxyyyzz_0[i] = 3.0 * g_0_xxxxzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyyzz_0[i] * pb_y + g_0_xxxxzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxyyzzz_0[i] = 2.0 * g_0_xxxxzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyyzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxyzzzz_0[i] = g_0_xxxxzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxxyzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxxzzzzz_0[i] = g_0_xxxxzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyyyyyy_0[i] = 6.0 * g_0_xxxxzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyyyy_0[i] * pb_y + g_0_xxxxzz_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyyyyyz_0[i] = 5.0 * g_0_xxxxzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyyyz_0[i] * pb_y + g_0_xxxxzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxxzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyyzz_0[i] * pb_y + g_0_xxxxzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxxzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyyzzz_0[i] * pb_y + g_0_xxxxzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyyzzzz_0[i] = 2.0 * g_0_xxxxzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyyzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxyzzzzz_0[i] = g_0_xxxxzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xxyzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xxzzzzzz_0[i] = g_0_xxxxzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyyyyyy_0[i] = 7.0 * g_0_xxxxzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyyyy_0[i] * pb_y + g_0_xxxxzz_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyyyyyz_0[i] = 6.0 * g_0_xxxxzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyyyz_0[i] * pb_y + g_0_xxxxzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyyyyzz_0[i] = 5.0 * g_0_xxxxzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyyzz_0[i] * pb_y + g_0_xxxxzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxxzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyyzzz_0[i] * pb_y + g_0_xxxxzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyyzzzz_0[i] = 3.0 * g_0_xxxxzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyyzzzz_0[i] * pb_y + g_0_xxxxzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyyzzzzz_0[i] = 2.0 * g_0_xxxxzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyyzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xyzzzzzz_0[i] = g_0_xxxxzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_xyzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_xzzzzzzz_0[i] = g_0_xxxxzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyyyyyy_0[i] = 8.0 * g_0_xxxxzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyyyyyy_0[i] * pb_y + g_0_xxxxzz_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyyyyyz_0[i] = 7.0 * g_0_xxxxzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyyyyyz_0[i] * pb_y + g_0_xxxxzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyyyyzz_0[i] = 6.0 * g_0_xxxxzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyyyyzz_0[i] * pb_y + g_0_xxxxzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyyyzzz_0[i] = 5.0 * g_0_xxxxzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyyyzzz_0[i] * pb_y + g_0_xxxxzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxxzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyyzzzz_0[i] * pb_y + g_0_xxxxzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyyzzzzz_0[i] = 3.0 * g_0_xxxxzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyyzzzzz_0[i] * pb_y + g_0_xxxxzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yyzzzzzz_0[i] = 2.0 * g_0_xxxxzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yyzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_yzzzzzzz_0[i] = g_0_xxxxzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxxzz_0_yzzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_xxxxyzz_0_zzzzzzzz_0[i] = g_0_xxxxzz_0_zzzzzzzz_0[i] * pb_y + g_0_xxxxzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 405-450 components of targeted buffer : SKSL

    auto g_0_xxxxzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 405);

    auto g_0_xxxxzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 406);

    auto g_0_xxxxzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 407);

    auto g_0_xxxxzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 408);

    auto g_0_xxxxzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 409);

    auto g_0_xxxxzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 410);

    auto g_0_xxxxzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 411);

    auto g_0_xxxxzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 412);

    auto g_0_xxxxzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 413);

    auto g_0_xxxxzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 414);

    auto g_0_xxxxzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 415);

    auto g_0_xxxxzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 416);

    auto g_0_xxxxzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 417);

    auto g_0_xxxxzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 418);

    auto g_0_xxxxzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 419);

    auto g_0_xxxxzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 420);

    auto g_0_xxxxzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 421);

    auto g_0_xxxxzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 422);

    auto g_0_xxxxzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 423);

    auto g_0_xxxxzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 424);

    auto g_0_xxxxzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 425);

    auto g_0_xxxxzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 426);

    auto g_0_xxxxzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 427);

    auto g_0_xxxxzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 428);

    auto g_0_xxxxzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 429);

    auto g_0_xxxxzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 430);

    auto g_0_xxxxzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 431);

    auto g_0_xxxxzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 432);

    auto g_0_xxxxzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 433);

    auto g_0_xxxxzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 434);

    auto g_0_xxxxzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 435);

    auto g_0_xxxxzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 436);

    auto g_0_xxxxzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 437);

    auto g_0_xxxxzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 438);

    auto g_0_xxxxzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 439);

    auto g_0_xxxxzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 440);

    auto g_0_xxxxzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 441);

    auto g_0_xxxxzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 442);

    auto g_0_xxxxzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 443);

    auto g_0_xxxxzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 444);

    auto g_0_xxxxzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 445);

    auto g_0_xxxxzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 446);

    auto g_0_xxxxzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 447);

    auto g_0_xxxxzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 448);

    auto g_0_xxxxzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 449);

    #pragma omp simd aligned(g_0_xxxxz_0_xxxxxxxx_0, g_0_xxxxz_0_xxxxxxxx_1, g_0_xxxxz_0_xxxxxxxy_0, g_0_xxxxz_0_xxxxxxxy_1, g_0_xxxxz_0_xxxxxxyy_0, g_0_xxxxz_0_xxxxxxyy_1, g_0_xxxxz_0_xxxxxyyy_0, g_0_xxxxz_0_xxxxxyyy_1, g_0_xxxxz_0_xxxxyyyy_0, g_0_xxxxz_0_xxxxyyyy_1, g_0_xxxxz_0_xxxyyyyy_0, g_0_xxxxz_0_xxxyyyyy_1, g_0_xxxxz_0_xxyyyyyy_0, g_0_xxxxz_0_xxyyyyyy_1, g_0_xxxxz_0_xyyyyyyy_0, g_0_xxxxz_0_xyyyyyyy_1, g_0_xxxxzz_0_xxxxxxxx_0, g_0_xxxxzz_0_xxxxxxxx_1, g_0_xxxxzz_0_xxxxxxxy_0, g_0_xxxxzz_0_xxxxxxxy_1, g_0_xxxxzz_0_xxxxxxyy_0, g_0_xxxxzz_0_xxxxxxyy_1, g_0_xxxxzz_0_xxxxxyyy_0, g_0_xxxxzz_0_xxxxxyyy_1, g_0_xxxxzz_0_xxxxyyyy_0, g_0_xxxxzz_0_xxxxyyyy_1, g_0_xxxxzz_0_xxxyyyyy_0, g_0_xxxxzz_0_xxxyyyyy_1, g_0_xxxxzz_0_xxyyyyyy_0, g_0_xxxxzz_0_xxyyyyyy_1, g_0_xxxxzz_0_xyyyyyyy_0, g_0_xxxxzz_0_xyyyyyyy_1, g_0_xxxxzzz_0_xxxxxxxx_0, g_0_xxxxzzz_0_xxxxxxxy_0, g_0_xxxxzzz_0_xxxxxxxz_0, g_0_xxxxzzz_0_xxxxxxyy_0, g_0_xxxxzzz_0_xxxxxxyz_0, g_0_xxxxzzz_0_xxxxxxzz_0, g_0_xxxxzzz_0_xxxxxyyy_0, g_0_xxxxzzz_0_xxxxxyyz_0, g_0_xxxxzzz_0_xxxxxyzz_0, g_0_xxxxzzz_0_xxxxxzzz_0, g_0_xxxxzzz_0_xxxxyyyy_0, g_0_xxxxzzz_0_xxxxyyyz_0, g_0_xxxxzzz_0_xxxxyyzz_0, g_0_xxxxzzz_0_xxxxyzzz_0, g_0_xxxxzzz_0_xxxxzzzz_0, g_0_xxxxzzz_0_xxxyyyyy_0, g_0_xxxxzzz_0_xxxyyyyz_0, g_0_xxxxzzz_0_xxxyyyzz_0, g_0_xxxxzzz_0_xxxyyzzz_0, g_0_xxxxzzz_0_xxxyzzzz_0, g_0_xxxxzzz_0_xxxzzzzz_0, g_0_xxxxzzz_0_xxyyyyyy_0, g_0_xxxxzzz_0_xxyyyyyz_0, g_0_xxxxzzz_0_xxyyyyzz_0, g_0_xxxxzzz_0_xxyyyzzz_0, g_0_xxxxzzz_0_xxyyzzzz_0, g_0_xxxxzzz_0_xxyzzzzz_0, g_0_xxxxzzz_0_xxzzzzzz_0, g_0_xxxxzzz_0_xyyyyyyy_0, g_0_xxxxzzz_0_xyyyyyyz_0, g_0_xxxxzzz_0_xyyyyyzz_0, g_0_xxxxzzz_0_xyyyyzzz_0, g_0_xxxxzzz_0_xyyyzzzz_0, g_0_xxxxzzz_0_xyyzzzzz_0, g_0_xxxxzzz_0_xyzzzzzz_0, g_0_xxxxzzz_0_xzzzzzzz_0, g_0_xxxxzzz_0_yyyyyyyy_0, g_0_xxxxzzz_0_yyyyyyyz_0, g_0_xxxxzzz_0_yyyyyyzz_0, g_0_xxxxzzz_0_yyyyyzzz_0, g_0_xxxxzzz_0_yyyyzzzz_0, g_0_xxxxzzz_0_yyyzzzzz_0, g_0_xxxxzzz_0_yyzzzzzz_0, g_0_xxxxzzz_0_yzzzzzzz_0, g_0_xxxxzzz_0_zzzzzzzz_0, g_0_xxxzzz_0_xxxxxxxz_0, g_0_xxxzzz_0_xxxxxxxz_1, g_0_xxxzzz_0_xxxxxxyz_0, g_0_xxxzzz_0_xxxxxxyz_1, g_0_xxxzzz_0_xxxxxxz_1, g_0_xxxzzz_0_xxxxxxzz_0, g_0_xxxzzz_0_xxxxxxzz_1, g_0_xxxzzz_0_xxxxxyyz_0, g_0_xxxzzz_0_xxxxxyyz_1, g_0_xxxzzz_0_xxxxxyz_1, g_0_xxxzzz_0_xxxxxyzz_0, g_0_xxxzzz_0_xxxxxyzz_1, g_0_xxxzzz_0_xxxxxzz_1, g_0_xxxzzz_0_xxxxxzzz_0, g_0_xxxzzz_0_xxxxxzzz_1, g_0_xxxzzz_0_xxxxyyyz_0, g_0_xxxzzz_0_xxxxyyyz_1, g_0_xxxzzz_0_xxxxyyz_1, g_0_xxxzzz_0_xxxxyyzz_0, g_0_xxxzzz_0_xxxxyyzz_1, g_0_xxxzzz_0_xxxxyzz_1, g_0_xxxzzz_0_xxxxyzzz_0, g_0_xxxzzz_0_xxxxyzzz_1, g_0_xxxzzz_0_xxxxzzz_1, g_0_xxxzzz_0_xxxxzzzz_0, g_0_xxxzzz_0_xxxxzzzz_1, g_0_xxxzzz_0_xxxyyyyz_0, g_0_xxxzzz_0_xxxyyyyz_1, g_0_xxxzzz_0_xxxyyyz_1, g_0_xxxzzz_0_xxxyyyzz_0, g_0_xxxzzz_0_xxxyyyzz_1, g_0_xxxzzz_0_xxxyyzz_1, g_0_xxxzzz_0_xxxyyzzz_0, g_0_xxxzzz_0_xxxyyzzz_1, g_0_xxxzzz_0_xxxyzzz_1, g_0_xxxzzz_0_xxxyzzzz_0, g_0_xxxzzz_0_xxxyzzzz_1, g_0_xxxzzz_0_xxxzzzz_1, g_0_xxxzzz_0_xxxzzzzz_0, g_0_xxxzzz_0_xxxzzzzz_1, g_0_xxxzzz_0_xxyyyyyz_0, g_0_xxxzzz_0_xxyyyyyz_1, g_0_xxxzzz_0_xxyyyyz_1, g_0_xxxzzz_0_xxyyyyzz_0, g_0_xxxzzz_0_xxyyyyzz_1, g_0_xxxzzz_0_xxyyyzz_1, g_0_xxxzzz_0_xxyyyzzz_0, g_0_xxxzzz_0_xxyyyzzz_1, g_0_xxxzzz_0_xxyyzzz_1, g_0_xxxzzz_0_xxyyzzzz_0, g_0_xxxzzz_0_xxyyzzzz_1, g_0_xxxzzz_0_xxyzzzz_1, g_0_xxxzzz_0_xxyzzzzz_0, g_0_xxxzzz_0_xxyzzzzz_1, g_0_xxxzzz_0_xxzzzzz_1, g_0_xxxzzz_0_xxzzzzzz_0, g_0_xxxzzz_0_xxzzzzzz_1, g_0_xxxzzz_0_xyyyyyyz_0, g_0_xxxzzz_0_xyyyyyyz_1, g_0_xxxzzz_0_xyyyyyz_1, g_0_xxxzzz_0_xyyyyyzz_0, g_0_xxxzzz_0_xyyyyyzz_1, g_0_xxxzzz_0_xyyyyzz_1, g_0_xxxzzz_0_xyyyyzzz_0, g_0_xxxzzz_0_xyyyyzzz_1, g_0_xxxzzz_0_xyyyzzz_1, g_0_xxxzzz_0_xyyyzzzz_0, g_0_xxxzzz_0_xyyyzzzz_1, g_0_xxxzzz_0_xyyzzzz_1, g_0_xxxzzz_0_xyyzzzzz_0, g_0_xxxzzz_0_xyyzzzzz_1, g_0_xxxzzz_0_xyzzzzz_1, g_0_xxxzzz_0_xyzzzzzz_0, g_0_xxxzzz_0_xyzzzzzz_1, g_0_xxxzzz_0_xzzzzzz_1, g_0_xxxzzz_0_xzzzzzzz_0, g_0_xxxzzz_0_xzzzzzzz_1, g_0_xxxzzz_0_yyyyyyyy_0, g_0_xxxzzz_0_yyyyyyyy_1, g_0_xxxzzz_0_yyyyyyyz_0, g_0_xxxzzz_0_yyyyyyyz_1, g_0_xxxzzz_0_yyyyyyz_1, g_0_xxxzzz_0_yyyyyyzz_0, g_0_xxxzzz_0_yyyyyyzz_1, g_0_xxxzzz_0_yyyyyzz_1, g_0_xxxzzz_0_yyyyyzzz_0, g_0_xxxzzz_0_yyyyyzzz_1, g_0_xxxzzz_0_yyyyzzz_1, g_0_xxxzzz_0_yyyyzzzz_0, g_0_xxxzzz_0_yyyyzzzz_1, g_0_xxxzzz_0_yyyzzzz_1, g_0_xxxzzz_0_yyyzzzzz_0, g_0_xxxzzz_0_yyyzzzzz_1, g_0_xxxzzz_0_yyzzzzz_1, g_0_xxxzzz_0_yyzzzzzz_0, g_0_xxxzzz_0_yyzzzzzz_1, g_0_xxxzzz_0_yzzzzzz_1, g_0_xxxzzz_0_yzzzzzzz_0, g_0_xxxzzz_0_yzzzzzzz_1, g_0_xxxzzz_0_zzzzzzz_1, g_0_xxxzzz_0_zzzzzzzz_0, g_0_xxxzzz_0_zzzzzzzz_1, g_0_xxzzz_0_xxxxxxxz_0, g_0_xxzzz_0_xxxxxxxz_1, g_0_xxzzz_0_xxxxxxyz_0, g_0_xxzzz_0_xxxxxxyz_1, g_0_xxzzz_0_xxxxxxzz_0, g_0_xxzzz_0_xxxxxxzz_1, g_0_xxzzz_0_xxxxxyyz_0, g_0_xxzzz_0_xxxxxyyz_1, g_0_xxzzz_0_xxxxxyzz_0, g_0_xxzzz_0_xxxxxyzz_1, g_0_xxzzz_0_xxxxxzzz_0, g_0_xxzzz_0_xxxxxzzz_1, g_0_xxzzz_0_xxxxyyyz_0, g_0_xxzzz_0_xxxxyyyz_1, g_0_xxzzz_0_xxxxyyzz_0, g_0_xxzzz_0_xxxxyyzz_1, g_0_xxzzz_0_xxxxyzzz_0, g_0_xxzzz_0_xxxxyzzz_1, g_0_xxzzz_0_xxxxzzzz_0, g_0_xxzzz_0_xxxxzzzz_1, g_0_xxzzz_0_xxxyyyyz_0, g_0_xxzzz_0_xxxyyyyz_1, g_0_xxzzz_0_xxxyyyzz_0, g_0_xxzzz_0_xxxyyyzz_1, g_0_xxzzz_0_xxxyyzzz_0, g_0_xxzzz_0_xxxyyzzz_1, g_0_xxzzz_0_xxxyzzzz_0, g_0_xxzzz_0_xxxyzzzz_1, g_0_xxzzz_0_xxxzzzzz_0, g_0_xxzzz_0_xxxzzzzz_1, g_0_xxzzz_0_xxyyyyyz_0, g_0_xxzzz_0_xxyyyyyz_1, g_0_xxzzz_0_xxyyyyzz_0, g_0_xxzzz_0_xxyyyyzz_1, g_0_xxzzz_0_xxyyyzzz_0, g_0_xxzzz_0_xxyyyzzz_1, g_0_xxzzz_0_xxyyzzzz_0, g_0_xxzzz_0_xxyyzzzz_1, g_0_xxzzz_0_xxyzzzzz_0, g_0_xxzzz_0_xxyzzzzz_1, g_0_xxzzz_0_xxzzzzzz_0, g_0_xxzzz_0_xxzzzzzz_1, g_0_xxzzz_0_xyyyyyyz_0, g_0_xxzzz_0_xyyyyyyz_1, g_0_xxzzz_0_xyyyyyzz_0, g_0_xxzzz_0_xyyyyyzz_1, g_0_xxzzz_0_xyyyyzzz_0, g_0_xxzzz_0_xyyyyzzz_1, g_0_xxzzz_0_xyyyzzzz_0, g_0_xxzzz_0_xyyyzzzz_1, g_0_xxzzz_0_xyyzzzzz_0, g_0_xxzzz_0_xyyzzzzz_1, g_0_xxzzz_0_xyzzzzzz_0, g_0_xxzzz_0_xyzzzzzz_1, g_0_xxzzz_0_xzzzzzzz_0, g_0_xxzzz_0_xzzzzzzz_1, g_0_xxzzz_0_yyyyyyyy_0, g_0_xxzzz_0_yyyyyyyy_1, g_0_xxzzz_0_yyyyyyyz_0, g_0_xxzzz_0_yyyyyyyz_1, g_0_xxzzz_0_yyyyyyzz_0, g_0_xxzzz_0_yyyyyyzz_1, g_0_xxzzz_0_yyyyyzzz_0, g_0_xxzzz_0_yyyyyzzz_1, g_0_xxzzz_0_yyyyzzzz_0, g_0_xxzzz_0_yyyyzzzz_1, g_0_xxzzz_0_yyyzzzzz_0, g_0_xxzzz_0_yyyzzzzz_1, g_0_xxzzz_0_yyzzzzzz_0, g_0_xxzzz_0_yyzzzzzz_1, g_0_xxzzz_0_yzzzzzzz_0, g_0_xxzzz_0_yzzzzzzz_1, g_0_xxzzz_0_zzzzzzzz_0, g_0_xxzzz_0_zzzzzzzz_1, wp_x, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxxzzz_0_xxxxxxxx_0[i] = 2.0 * g_0_xxxxz_0_xxxxxxxx_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxxxxxx_0[i] * pb_z + g_0_xxxxzz_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxxxxxy_0[i] = 2.0 * g_0_xxxxz_0_xxxxxxxy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxxxxxy_0[i] * pb_z + g_0_xxxxzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxxxxxz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxxxz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxxxz_1[i] * fti_ab_0 + 7.0 * g_0_xxxzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxxz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_xxxxz_0_xxxxxxyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxxxxyy_0[i] * pb_z + g_0_xxxxzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxxxxyz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxxyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxxzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxyz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxxxzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxxzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxxzz_1[i] * fti_ab_0 + 6.0 * g_0_xxxzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxxyyy_0[i] = 2.0 * g_0_xxxxz_0_xxxxxyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxxxyyy_0[i] * pb_z + g_0_xxxxzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxxxyyz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxxzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxyyz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxxyzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxyzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxxzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxxzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxxzzz_1[i] * fti_ab_0 + 5.0 * g_0_xxxzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxyyyy_0[i] = 2.0 * g_0_xxxxz_0_xxxxyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxxyyyy_0[i] * pb_z + g_0_xxxxzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxxyyyz_0[i] = 3.0 * g_0_xxzzz_0_xxxxyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxxzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyyyz_0[i] * pb_x + g_0_xxxzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxyyzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyyzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxyzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxxzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxxzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxxzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxyyyyy_0[i] = 2.0 * g_0_xxxxz_0_xxxyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxxyyyyy_0[i] * pb_z + g_0_xxxxzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_xxzzz_0_xxxyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxxzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyyyz_0[i] * pb_x + g_0_xxxzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_xxzzz_0_xxxyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyyzz_0[i] * pb_x + g_0_xxxzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxxzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxxzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxxzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxxzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_xxxxz_0_xxyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xxyyyyyy_0[i] * pb_z + g_0_xxxxzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xxyyyyyz_0[i] = 3.0 * g_0_xxzzz_0_xxyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyyyz_0[i] * pb_x + g_0_xxxzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxyyyyzz_0[i] = 3.0 * g_0_xxzzz_0_xxyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyyzz_0[i] * pb_x + g_0_xxxzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxzzz_0_xxyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyzzz_0[i] * pb_x + g_0_xxxzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxyyzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxyzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xxzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xxzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xxzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxxzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyyyyyyy_0[i] = 2.0 * g_0_xxxxz_0_xyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxxxz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxxzz_0_xyyyyyyy_0[i] * pb_z + g_0_xxxxzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxxzzz_0_xyyyyyyz_0[i] = 3.0 * g_0_xxzzz_0_xyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyyyz_0[i] * pb_x + g_0_xxxzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyyyyyzz_0[i] = 3.0 * g_0_xxzzz_0_xyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyyzz_0[i] * pb_x + g_0_xxxzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyyyyzzz_0[i] = 3.0 * g_0_xxzzz_0_xyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyzzz_0[i] * pb_x + g_0_xxxzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyyyzzzz_0[i] = 3.0 * g_0_xxzzz_0_xyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyzzzz_0[i] * pb_x + g_0_xxxzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyyzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xyzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_xzzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_xzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xzzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyyyyyy_0[i] = 3.0 * g_0_xxzzz_0_yyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyyyy_0[i] * pb_x + g_0_xxxzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyyyyyz_0[i] = 3.0 * g_0_xxzzz_0_yyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyyyz_0[i] * pb_x + g_0_xxxzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyyyyzz_0[i] = 3.0 * g_0_xxzzz_0_yyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyyzz_0[i] * pb_x + g_0_xxxzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyyyzzz_0[i] = 3.0 * g_0_xxzzz_0_yyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyyzzz_0[i] * pb_x + g_0_xxxzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyyzzzz_0[i] = 3.0 * g_0_xxzzz_0_yyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyyzzzz_0[i] * pb_x + g_0_xxxzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyyzzzzz_0[i] = 3.0 * g_0_xxzzz_0_yyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyyzzzzz_0[i] * pb_x + g_0_xxxzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yyzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_yyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yyzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_yzzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_yzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_yzzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxxzzz_0_zzzzzzzz_0[i] = 3.0 * g_0_xxzzz_0_zzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxxzzz_0_zzzzzzzz_0[i] * pb_x + g_0_xxxzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 450-495 components of targeted buffer : SKSL

    auto g_0_xxxyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 450);

    auto g_0_xxxyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 451);

    auto g_0_xxxyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 452);

    auto g_0_xxxyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 453);

    auto g_0_xxxyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 454);

    auto g_0_xxxyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 455);

    auto g_0_xxxyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 456);

    auto g_0_xxxyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 457);

    auto g_0_xxxyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 458);

    auto g_0_xxxyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 459);

    auto g_0_xxxyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 460);

    auto g_0_xxxyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 461);

    auto g_0_xxxyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 462);

    auto g_0_xxxyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 463);

    auto g_0_xxxyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 464);

    auto g_0_xxxyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 465);

    auto g_0_xxxyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 466);

    auto g_0_xxxyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 467);

    auto g_0_xxxyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 468);

    auto g_0_xxxyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 469);

    auto g_0_xxxyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 470);

    auto g_0_xxxyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 471);

    auto g_0_xxxyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 472);

    auto g_0_xxxyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 473);

    auto g_0_xxxyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 474);

    auto g_0_xxxyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 475);

    auto g_0_xxxyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 476);

    auto g_0_xxxyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 477);

    auto g_0_xxxyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 478);

    auto g_0_xxxyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 479);

    auto g_0_xxxyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 480);

    auto g_0_xxxyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 481);

    auto g_0_xxxyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 482);

    auto g_0_xxxyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 483);

    auto g_0_xxxyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 484);

    auto g_0_xxxyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 485);

    auto g_0_xxxyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 486);

    auto g_0_xxxyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 487);

    auto g_0_xxxyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 488);

    auto g_0_xxxyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 489);

    auto g_0_xxxyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 490);

    auto g_0_xxxyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 491);

    auto g_0_xxxyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 492);

    auto g_0_xxxyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 493);

    auto g_0_xxxyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 494);

    #pragma omp simd aligned(g_0_xxxyy_0_xxxxxxxx_0, g_0_xxxyy_0_xxxxxxxx_1, g_0_xxxyy_0_xxxxxxxz_0, g_0_xxxyy_0_xxxxxxxz_1, g_0_xxxyy_0_xxxxxxzz_0, g_0_xxxyy_0_xxxxxxzz_1, g_0_xxxyy_0_xxxxxzzz_0, g_0_xxxyy_0_xxxxxzzz_1, g_0_xxxyy_0_xxxxzzzz_0, g_0_xxxyy_0_xxxxzzzz_1, g_0_xxxyy_0_xxxzzzzz_0, g_0_xxxyy_0_xxxzzzzz_1, g_0_xxxyy_0_xxzzzzzz_0, g_0_xxxyy_0_xxzzzzzz_1, g_0_xxxyy_0_xzzzzzzz_0, g_0_xxxyy_0_xzzzzzzz_1, g_0_xxxyyy_0_xxxxxxxx_0, g_0_xxxyyy_0_xxxxxxxx_1, g_0_xxxyyy_0_xxxxxxxz_0, g_0_xxxyyy_0_xxxxxxxz_1, g_0_xxxyyy_0_xxxxxxzz_0, g_0_xxxyyy_0_xxxxxxzz_1, g_0_xxxyyy_0_xxxxxzzz_0, g_0_xxxyyy_0_xxxxxzzz_1, g_0_xxxyyy_0_xxxxzzzz_0, g_0_xxxyyy_0_xxxxzzzz_1, g_0_xxxyyy_0_xxxzzzzz_0, g_0_xxxyyy_0_xxxzzzzz_1, g_0_xxxyyy_0_xxzzzzzz_0, g_0_xxxyyy_0_xxzzzzzz_1, g_0_xxxyyy_0_xzzzzzzz_0, g_0_xxxyyy_0_xzzzzzzz_1, g_0_xxxyyyy_0_xxxxxxxx_0, g_0_xxxyyyy_0_xxxxxxxy_0, g_0_xxxyyyy_0_xxxxxxxz_0, g_0_xxxyyyy_0_xxxxxxyy_0, g_0_xxxyyyy_0_xxxxxxyz_0, g_0_xxxyyyy_0_xxxxxxzz_0, g_0_xxxyyyy_0_xxxxxyyy_0, g_0_xxxyyyy_0_xxxxxyyz_0, g_0_xxxyyyy_0_xxxxxyzz_0, g_0_xxxyyyy_0_xxxxxzzz_0, g_0_xxxyyyy_0_xxxxyyyy_0, g_0_xxxyyyy_0_xxxxyyyz_0, g_0_xxxyyyy_0_xxxxyyzz_0, g_0_xxxyyyy_0_xxxxyzzz_0, g_0_xxxyyyy_0_xxxxzzzz_0, g_0_xxxyyyy_0_xxxyyyyy_0, g_0_xxxyyyy_0_xxxyyyyz_0, g_0_xxxyyyy_0_xxxyyyzz_0, g_0_xxxyyyy_0_xxxyyzzz_0, g_0_xxxyyyy_0_xxxyzzzz_0, g_0_xxxyyyy_0_xxxzzzzz_0, g_0_xxxyyyy_0_xxyyyyyy_0, g_0_xxxyyyy_0_xxyyyyyz_0, g_0_xxxyyyy_0_xxyyyyzz_0, g_0_xxxyyyy_0_xxyyyzzz_0, g_0_xxxyyyy_0_xxyyzzzz_0, g_0_xxxyyyy_0_xxyzzzzz_0, g_0_xxxyyyy_0_xxzzzzzz_0, g_0_xxxyyyy_0_xyyyyyyy_0, g_0_xxxyyyy_0_xyyyyyyz_0, g_0_xxxyyyy_0_xyyyyyzz_0, g_0_xxxyyyy_0_xyyyyzzz_0, g_0_xxxyyyy_0_xyyyzzzz_0, g_0_xxxyyyy_0_xyyzzzzz_0, g_0_xxxyyyy_0_xyzzzzzz_0, g_0_xxxyyyy_0_xzzzzzzz_0, g_0_xxxyyyy_0_yyyyyyyy_0, g_0_xxxyyyy_0_yyyyyyyz_0, g_0_xxxyyyy_0_yyyyyyzz_0, g_0_xxxyyyy_0_yyyyyzzz_0, g_0_xxxyyyy_0_yyyyzzzz_0, g_0_xxxyyyy_0_yyyzzzzz_0, g_0_xxxyyyy_0_yyzzzzzz_0, g_0_xxxyyyy_0_yzzzzzzz_0, g_0_xxxyyyy_0_zzzzzzzz_0, g_0_xxyyyy_0_xxxxxxxy_0, g_0_xxyyyy_0_xxxxxxxy_1, g_0_xxyyyy_0_xxxxxxy_1, g_0_xxyyyy_0_xxxxxxyy_0, g_0_xxyyyy_0_xxxxxxyy_1, g_0_xxyyyy_0_xxxxxxyz_0, g_0_xxyyyy_0_xxxxxxyz_1, g_0_xxyyyy_0_xxxxxyy_1, g_0_xxyyyy_0_xxxxxyyy_0, g_0_xxyyyy_0_xxxxxyyy_1, g_0_xxyyyy_0_xxxxxyyz_0, g_0_xxyyyy_0_xxxxxyyz_1, g_0_xxyyyy_0_xxxxxyz_1, g_0_xxyyyy_0_xxxxxyzz_0, g_0_xxyyyy_0_xxxxxyzz_1, g_0_xxyyyy_0_xxxxyyy_1, g_0_xxyyyy_0_xxxxyyyy_0, g_0_xxyyyy_0_xxxxyyyy_1, g_0_xxyyyy_0_xxxxyyyz_0, g_0_xxyyyy_0_xxxxyyyz_1, g_0_xxyyyy_0_xxxxyyz_1, g_0_xxyyyy_0_xxxxyyzz_0, g_0_xxyyyy_0_xxxxyyzz_1, g_0_xxyyyy_0_xxxxyzz_1, g_0_xxyyyy_0_xxxxyzzz_0, g_0_xxyyyy_0_xxxxyzzz_1, g_0_xxyyyy_0_xxxyyyy_1, g_0_xxyyyy_0_xxxyyyyy_0, g_0_xxyyyy_0_xxxyyyyy_1, g_0_xxyyyy_0_xxxyyyyz_0, g_0_xxyyyy_0_xxxyyyyz_1, g_0_xxyyyy_0_xxxyyyz_1, g_0_xxyyyy_0_xxxyyyzz_0, g_0_xxyyyy_0_xxxyyyzz_1, g_0_xxyyyy_0_xxxyyzz_1, g_0_xxyyyy_0_xxxyyzzz_0, g_0_xxyyyy_0_xxxyyzzz_1, g_0_xxyyyy_0_xxxyzzz_1, g_0_xxyyyy_0_xxxyzzzz_0, g_0_xxyyyy_0_xxxyzzzz_1, g_0_xxyyyy_0_xxyyyyy_1, g_0_xxyyyy_0_xxyyyyyy_0, g_0_xxyyyy_0_xxyyyyyy_1, g_0_xxyyyy_0_xxyyyyyz_0, g_0_xxyyyy_0_xxyyyyyz_1, g_0_xxyyyy_0_xxyyyyz_1, g_0_xxyyyy_0_xxyyyyzz_0, g_0_xxyyyy_0_xxyyyyzz_1, g_0_xxyyyy_0_xxyyyzz_1, g_0_xxyyyy_0_xxyyyzzz_0, g_0_xxyyyy_0_xxyyyzzz_1, g_0_xxyyyy_0_xxyyzzz_1, g_0_xxyyyy_0_xxyyzzzz_0, g_0_xxyyyy_0_xxyyzzzz_1, g_0_xxyyyy_0_xxyzzzz_1, g_0_xxyyyy_0_xxyzzzzz_0, g_0_xxyyyy_0_xxyzzzzz_1, g_0_xxyyyy_0_xyyyyyy_1, g_0_xxyyyy_0_xyyyyyyy_0, g_0_xxyyyy_0_xyyyyyyy_1, g_0_xxyyyy_0_xyyyyyyz_0, g_0_xxyyyy_0_xyyyyyyz_1, g_0_xxyyyy_0_xyyyyyz_1, g_0_xxyyyy_0_xyyyyyzz_0, g_0_xxyyyy_0_xyyyyyzz_1, g_0_xxyyyy_0_xyyyyzz_1, g_0_xxyyyy_0_xyyyyzzz_0, g_0_xxyyyy_0_xyyyyzzz_1, g_0_xxyyyy_0_xyyyzzz_1, g_0_xxyyyy_0_xyyyzzzz_0, g_0_xxyyyy_0_xyyyzzzz_1, g_0_xxyyyy_0_xyyzzzz_1, g_0_xxyyyy_0_xyyzzzzz_0, g_0_xxyyyy_0_xyyzzzzz_1, g_0_xxyyyy_0_xyzzzzz_1, g_0_xxyyyy_0_xyzzzzzz_0, g_0_xxyyyy_0_xyzzzzzz_1, g_0_xxyyyy_0_yyyyyyy_1, g_0_xxyyyy_0_yyyyyyyy_0, g_0_xxyyyy_0_yyyyyyyy_1, g_0_xxyyyy_0_yyyyyyyz_0, g_0_xxyyyy_0_yyyyyyyz_1, g_0_xxyyyy_0_yyyyyyz_1, g_0_xxyyyy_0_yyyyyyzz_0, g_0_xxyyyy_0_yyyyyyzz_1, g_0_xxyyyy_0_yyyyyzz_1, g_0_xxyyyy_0_yyyyyzzz_0, g_0_xxyyyy_0_yyyyyzzz_1, g_0_xxyyyy_0_yyyyzzz_1, g_0_xxyyyy_0_yyyyzzzz_0, g_0_xxyyyy_0_yyyyzzzz_1, g_0_xxyyyy_0_yyyzzzz_1, g_0_xxyyyy_0_yyyzzzzz_0, g_0_xxyyyy_0_yyyzzzzz_1, g_0_xxyyyy_0_yyzzzzz_1, g_0_xxyyyy_0_yyzzzzzz_0, g_0_xxyyyy_0_yyzzzzzz_1, g_0_xxyyyy_0_yzzzzzz_1, g_0_xxyyyy_0_yzzzzzzz_0, g_0_xxyyyy_0_yzzzzzzz_1, g_0_xxyyyy_0_zzzzzzzz_0, g_0_xxyyyy_0_zzzzzzzz_1, g_0_xyyyy_0_xxxxxxxy_0, g_0_xyyyy_0_xxxxxxxy_1, g_0_xyyyy_0_xxxxxxyy_0, g_0_xyyyy_0_xxxxxxyy_1, g_0_xyyyy_0_xxxxxxyz_0, g_0_xyyyy_0_xxxxxxyz_1, g_0_xyyyy_0_xxxxxyyy_0, g_0_xyyyy_0_xxxxxyyy_1, g_0_xyyyy_0_xxxxxyyz_0, g_0_xyyyy_0_xxxxxyyz_1, g_0_xyyyy_0_xxxxxyzz_0, g_0_xyyyy_0_xxxxxyzz_1, g_0_xyyyy_0_xxxxyyyy_0, g_0_xyyyy_0_xxxxyyyy_1, g_0_xyyyy_0_xxxxyyyz_0, g_0_xyyyy_0_xxxxyyyz_1, g_0_xyyyy_0_xxxxyyzz_0, g_0_xyyyy_0_xxxxyyzz_1, g_0_xyyyy_0_xxxxyzzz_0, g_0_xyyyy_0_xxxxyzzz_1, g_0_xyyyy_0_xxxyyyyy_0, g_0_xyyyy_0_xxxyyyyy_1, g_0_xyyyy_0_xxxyyyyz_0, g_0_xyyyy_0_xxxyyyyz_1, g_0_xyyyy_0_xxxyyyzz_0, g_0_xyyyy_0_xxxyyyzz_1, g_0_xyyyy_0_xxxyyzzz_0, g_0_xyyyy_0_xxxyyzzz_1, g_0_xyyyy_0_xxxyzzzz_0, g_0_xyyyy_0_xxxyzzzz_1, g_0_xyyyy_0_xxyyyyyy_0, g_0_xyyyy_0_xxyyyyyy_1, g_0_xyyyy_0_xxyyyyyz_0, g_0_xyyyy_0_xxyyyyyz_1, g_0_xyyyy_0_xxyyyyzz_0, g_0_xyyyy_0_xxyyyyzz_1, g_0_xyyyy_0_xxyyyzzz_0, g_0_xyyyy_0_xxyyyzzz_1, g_0_xyyyy_0_xxyyzzzz_0, g_0_xyyyy_0_xxyyzzzz_1, g_0_xyyyy_0_xxyzzzzz_0, g_0_xyyyy_0_xxyzzzzz_1, g_0_xyyyy_0_xyyyyyyy_0, g_0_xyyyy_0_xyyyyyyy_1, g_0_xyyyy_0_xyyyyyyz_0, g_0_xyyyy_0_xyyyyyyz_1, g_0_xyyyy_0_xyyyyyzz_0, g_0_xyyyy_0_xyyyyyzz_1, g_0_xyyyy_0_xyyyyzzz_0, g_0_xyyyy_0_xyyyyzzz_1, g_0_xyyyy_0_xyyyzzzz_0, g_0_xyyyy_0_xyyyzzzz_1, g_0_xyyyy_0_xyyzzzzz_0, g_0_xyyyy_0_xyyzzzzz_1, g_0_xyyyy_0_xyzzzzzz_0, g_0_xyyyy_0_xyzzzzzz_1, g_0_xyyyy_0_yyyyyyyy_0, g_0_xyyyy_0_yyyyyyyy_1, g_0_xyyyy_0_yyyyyyyz_0, g_0_xyyyy_0_yyyyyyyz_1, g_0_xyyyy_0_yyyyyyzz_0, g_0_xyyyy_0_yyyyyyzz_1, g_0_xyyyy_0_yyyyyzzz_0, g_0_xyyyy_0_yyyyyzzz_1, g_0_xyyyy_0_yyyyzzzz_0, g_0_xyyyy_0_yyyyzzzz_1, g_0_xyyyy_0_yyyzzzzz_0, g_0_xyyyy_0_yyyzzzzz_1, g_0_xyyyy_0_yyzzzzzz_0, g_0_xyyyy_0_yyzzzzzz_1, g_0_xyyyy_0_yzzzzzzz_0, g_0_xyyyy_0_yzzzzzzz_1, g_0_xyyyy_0_zzzzzzzz_0, g_0_xyyyy_0_zzzzzzzz_1, wp_x, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxyyyy_0_xxxxxxxx_0[i] = 3.0 * g_0_xxxyy_0_xxxxxxxx_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxxxxxx_0[i] * pb_y + g_0_xxxyyy_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxxxxxxy_0[i] = 2.0 * g_0_xyyyy_0_xxxxxxxy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxxxy_1[i] * fti_ab_0 + 7.0 * g_0_xxyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxxy_0[i] * pb_x + g_0_xxyyyy_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxxxz_0[i] = 3.0 * g_0_xxxyy_0_xxxxxxxz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxxxxxz_0[i] * pb_y + g_0_xxxyyy_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxxxxxyy_0[i] = 2.0 * g_0_xyyyy_0_xxxxxxyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxxyy_1[i] * fti_ab_0 + 6.0 * g_0_xxyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxyy_0[i] * pb_x + g_0_xxyyyy_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxxyz_0[i] = 2.0 * g_0_xyyyy_0_xxxxxxyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxyz_0[i] * pb_x + g_0_xxyyyy_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxxzz_0[i] = 3.0 * g_0_xxxyy_0_xxxxxxzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxxxxzz_0[i] * pb_y + g_0_xxxyyy_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxxxxyyy_0[i] = 2.0 * g_0_xyyyy_0_xxxxxyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxyyy_1[i] * fti_ab_0 + 5.0 * g_0_xxyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxyyy_0[i] * pb_x + g_0_xxyyyy_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxyyz_0[i] = 2.0 * g_0_xyyyy_0_xxxxxyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxyyz_0[i] * pb_x + g_0_xxyyyy_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxyzz_0[i] = 2.0 * g_0_xyyyy_0_xxxxxyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxyzz_0[i] * pb_x + g_0_xxyyyy_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxxzzz_0[i] = 3.0 * g_0_xxxyy_0_xxxxxzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxxxzzz_0[i] * pb_y + g_0_xxxyyy_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxxxyyyy_0[i] = 2.0 * g_0_xyyyy_0_xxxxyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_xxyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyyyy_0[i] * pb_x + g_0_xxyyyy_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxyyyz_0[i] = 2.0 * g_0_xyyyy_0_xxxxyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyyyz_0[i] * pb_x + g_0_xxyyyy_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxyyzz_0[i] = 2.0 * g_0_xyyyy_0_xxxxyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyyzz_0[i] * pb_x + g_0_xxyyyy_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxyzzz_0[i] = 2.0 * g_0_xyyyy_0_xxxxyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyzzz_0[i] * pb_x + g_0_xxyyyy_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxxzzzz_0[i] = 3.0 * g_0_xxxyy_0_xxxxzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxxzzzz_0[i] * pb_y + g_0_xxxyyy_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxxyyyyy_0[i] = 2.0 * g_0_xyyyy_0_xxxyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxyyyyy_1[i] * fti_ab_0 + 3.0 * g_0_xxyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyyyy_0[i] * pb_x + g_0_xxyyyy_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxyyyyz_0[i] = 2.0 * g_0_xyyyy_0_xxxyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyyyz_0[i] * pb_x + g_0_xxyyyy_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxyyyzz_0[i] = 2.0 * g_0_xyyyy_0_xxxyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyyzz_0[i] * pb_x + g_0_xxyyyy_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxyyzzz_0[i] = 2.0 * g_0_xyyyy_0_xxxyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyzzz_0[i] * pb_x + g_0_xxyyyy_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxyzzzz_0[i] = 2.0 * g_0_xyyyy_0_xxxyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyzzzz_0[i] * pb_x + g_0_xxyyyy_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxxzzzzz_0[i] = 3.0 * g_0_xxxyy_0_xxxzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxxzzzzz_0[i] * pb_y + g_0_xxxyyy_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xxyyyyyy_0[i] = 2.0 * g_0_xyyyy_0_xxyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyyyyyy_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyyyy_0[i] * pb_x + g_0_xxyyyy_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxyyyyyz_0[i] = 2.0 * g_0_xyyyy_0_xxyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyyyz_0[i] * pb_x + g_0_xxyyyy_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxyyyyzz_0[i] = 2.0 * g_0_xyyyy_0_xxyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyyzz_0[i] * pb_x + g_0_xxyyyy_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxyyyzzz_0[i] = 2.0 * g_0_xyyyy_0_xxyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyzzz_0[i] * pb_x + g_0_xxyyyy_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxyyzzzz_0[i] = 2.0 * g_0_xyyyy_0_xxyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyzzzz_0[i] * pb_x + g_0_xxyyyy_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxyzzzzz_0[i] = 2.0 * g_0_xyyyy_0_xxyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyzzzzz_0[i] * pb_x + g_0_xxyyyy_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xxzzzzzz_0[i] = 3.0 * g_0_xxxyy_0_xxzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xxzzzzzz_0[i] * pb_y + g_0_xxxyyy_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_xyyyyyyy_0[i] = 2.0 * g_0_xyyyy_0_xyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyyyy_0[i] * pb_x + g_0_xxyyyy_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyyyyyyz_0[i] = 2.0 * g_0_xyyyy_0_xyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyyyz_0[i] * pb_x + g_0_xxyyyy_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyyyyyzz_0[i] = 2.0 * g_0_xyyyy_0_xyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyyzz_0[i] * pb_x + g_0_xxyyyy_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyyyyzzz_0[i] = 2.0 * g_0_xyyyy_0_xyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyzzz_0[i] * pb_x + g_0_xxyyyy_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyyyzzzz_0[i] = 2.0 * g_0_xyyyy_0_xyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyzzzz_0[i] * pb_x + g_0_xxyyyy_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyyzzzzz_0[i] = 2.0 * g_0_xyyyy_0_xyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyzzzzz_0[i] * pb_x + g_0_xxyyyy_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xyzzzzzz_0[i] = 2.0 * g_0_xyyyy_0_xyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyzzzzzz_0[i] * pb_x + g_0_xxyyyy_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_xzzzzzzz_0[i] = 3.0 * g_0_xxxyy_0_xzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_xxxyy_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxyyy_0_xzzzzzzz_0[i] * pb_y + g_0_xxxyyy_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxyyyy_0_yyyyyyyy_0[i] = 2.0 * g_0_xyyyy_0_yyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyyyy_0[i] * pb_x + g_0_xxyyyy_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyyyyyyz_0[i] = 2.0 * g_0_xyyyy_0_yyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyyyz_0[i] * pb_x + g_0_xxyyyy_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyyyyyzz_0[i] = 2.0 * g_0_xyyyy_0_yyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyyzz_0[i] * pb_x + g_0_xxyyyy_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyyyyzzz_0[i] = 2.0 * g_0_xyyyy_0_yyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyyzzz_0[i] * pb_x + g_0_xxyyyy_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyyyzzzz_0[i] = 2.0 * g_0_xyyyy_0_yyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyyzzzz_0[i] * pb_x + g_0_xxyyyy_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyyzzzzz_0[i] = 2.0 * g_0_xyyyy_0_yyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyyzzzzz_0[i] * pb_x + g_0_xxyyyy_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yyzzzzzz_0[i] = 2.0 * g_0_xyyyy_0_yyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yyzzzzzz_0[i] * pb_x + g_0_xxyyyy_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_yzzzzzzz_0[i] = 2.0 * g_0_xyyyy_0_yzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_yzzzzzzz_0[i] * pb_x + g_0_xxyyyy_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyyy_0_zzzzzzzz_0[i] = 2.0 * g_0_xyyyy_0_zzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyyy_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_zzzzzzzz_0[i] * pb_x + g_0_xxyyyy_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 495-540 components of targeted buffer : SKSL

    auto g_0_xxxyyyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 495);

    auto g_0_xxxyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 496);

    auto g_0_xxxyyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 497);

    auto g_0_xxxyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 498);

    auto g_0_xxxyyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 499);

    auto g_0_xxxyyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 500);

    auto g_0_xxxyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 501);

    auto g_0_xxxyyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 502);

    auto g_0_xxxyyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 503);

    auto g_0_xxxyyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 504);

    auto g_0_xxxyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 505);

    auto g_0_xxxyyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 506);

    auto g_0_xxxyyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 507);

    auto g_0_xxxyyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 508);

    auto g_0_xxxyyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 509);

    auto g_0_xxxyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 510);

    auto g_0_xxxyyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 511);

    auto g_0_xxxyyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 512);

    auto g_0_xxxyyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 513);

    auto g_0_xxxyyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 514);

    auto g_0_xxxyyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 515);

    auto g_0_xxxyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 516);

    auto g_0_xxxyyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 517);

    auto g_0_xxxyyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 518);

    auto g_0_xxxyyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 519);

    auto g_0_xxxyyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 520);

    auto g_0_xxxyyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 521);

    auto g_0_xxxyyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 522);

    auto g_0_xxxyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 523);

    auto g_0_xxxyyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 524);

    auto g_0_xxxyyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 525);

    auto g_0_xxxyyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 526);

    auto g_0_xxxyyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 527);

    auto g_0_xxxyyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 528);

    auto g_0_xxxyyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 529);

    auto g_0_xxxyyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 530);

    auto g_0_xxxyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 531);

    auto g_0_xxxyyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 532);

    auto g_0_xxxyyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 533);

    auto g_0_xxxyyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 534);

    auto g_0_xxxyyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 535);

    auto g_0_xxxyyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 536);

    auto g_0_xxxyyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 537);

    auto g_0_xxxyyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 538);

    auto g_0_xxxyyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 539);

    #pragma omp simd aligned(g_0_xxxyyy_0_xxxxxxx_1, g_0_xxxyyy_0_xxxxxxxx_0, g_0_xxxyyy_0_xxxxxxxx_1, g_0_xxxyyy_0_xxxxxxxy_0, g_0_xxxyyy_0_xxxxxxxy_1, g_0_xxxyyy_0_xxxxxxxz_0, g_0_xxxyyy_0_xxxxxxxz_1, g_0_xxxyyy_0_xxxxxxy_1, g_0_xxxyyy_0_xxxxxxyy_0, g_0_xxxyyy_0_xxxxxxyy_1, g_0_xxxyyy_0_xxxxxxyz_0, g_0_xxxyyy_0_xxxxxxyz_1, g_0_xxxyyy_0_xxxxxxz_1, g_0_xxxyyy_0_xxxxxxzz_0, g_0_xxxyyy_0_xxxxxxzz_1, g_0_xxxyyy_0_xxxxxyy_1, g_0_xxxyyy_0_xxxxxyyy_0, g_0_xxxyyy_0_xxxxxyyy_1, g_0_xxxyyy_0_xxxxxyyz_0, g_0_xxxyyy_0_xxxxxyyz_1, g_0_xxxyyy_0_xxxxxyz_1, g_0_xxxyyy_0_xxxxxyzz_0, g_0_xxxyyy_0_xxxxxyzz_1, g_0_xxxyyy_0_xxxxxzz_1, g_0_xxxyyy_0_xxxxxzzz_0, g_0_xxxyyy_0_xxxxxzzz_1, g_0_xxxyyy_0_xxxxyyy_1, g_0_xxxyyy_0_xxxxyyyy_0, g_0_xxxyyy_0_xxxxyyyy_1, g_0_xxxyyy_0_xxxxyyyz_0, g_0_xxxyyy_0_xxxxyyyz_1, g_0_xxxyyy_0_xxxxyyz_1, g_0_xxxyyy_0_xxxxyyzz_0, g_0_xxxyyy_0_xxxxyyzz_1, g_0_xxxyyy_0_xxxxyzz_1, g_0_xxxyyy_0_xxxxyzzz_0, g_0_xxxyyy_0_xxxxyzzz_1, g_0_xxxyyy_0_xxxxzzz_1, g_0_xxxyyy_0_xxxxzzzz_0, g_0_xxxyyy_0_xxxxzzzz_1, g_0_xxxyyy_0_xxxyyyy_1, g_0_xxxyyy_0_xxxyyyyy_0, g_0_xxxyyy_0_xxxyyyyy_1, g_0_xxxyyy_0_xxxyyyyz_0, g_0_xxxyyy_0_xxxyyyyz_1, g_0_xxxyyy_0_xxxyyyz_1, g_0_xxxyyy_0_xxxyyyzz_0, g_0_xxxyyy_0_xxxyyyzz_1, g_0_xxxyyy_0_xxxyyzz_1, g_0_xxxyyy_0_xxxyyzzz_0, g_0_xxxyyy_0_xxxyyzzz_1, g_0_xxxyyy_0_xxxyzzz_1, g_0_xxxyyy_0_xxxyzzzz_0, g_0_xxxyyy_0_xxxyzzzz_1, g_0_xxxyyy_0_xxxzzzz_1, g_0_xxxyyy_0_xxxzzzzz_0, g_0_xxxyyy_0_xxxzzzzz_1, g_0_xxxyyy_0_xxyyyyy_1, g_0_xxxyyy_0_xxyyyyyy_0, g_0_xxxyyy_0_xxyyyyyy_1, g_0_xxxyyy_0_xxyyyyyz_0, g_0_xxxyyy_0_xxyyyyyz_1, g_0_xxxyyy_0_xxyyyyz_1, g_0_xxxyyy_0_xxyyyyzz_0, g_0_xxxyyy_0_xxyyyyzz_1, g_0_xxxyyy_0_xxyyyzz_1, g_0_xxxyyy_0_xxyyyzzz_0, g_0_xxxyyy_0_xxyyyzzz_1, g_0_xxxyyy_0_xxyyzzz_1, g_0_xxxyyy_0_xxyyzzzz_0, g_0_xxxyyy_0_xxyyzzzz_1, g_0_xxxyyy_0_xxyzzzz_1, g_0_xxxyyy_0_xxyzzzzz_0, g_0_xxxyyy_0_xxyzzzzz_1, g_0_xxxyyy_0_xxzzzzz_1, g_0_xxxyyy_0_xxzzzzzz_0, g_0_xxxyyy_0_xxzzzzzz_1, g_0_xxxyyy_0_xyyyyyy_1, g_0_xxxyyy_0_xyyyyyyy_0, g_0_xxxyyy_0_xyyyyyyy_1, g_0_xxxyyy_0_xyyyyyyz_0, g_0_xxxyyy_0_xyyyyyyz_1, g_0_xxxyyy_0_xyyyyyz_1, g_0_xxxyyy_0_xyyyyyzz_0, g_0_xxxyyy_0_xyyyyyzz_1, g_0_xxxyyy_0_xyyyyzz_1, g_0_xxxyyy_0_xyyyyzzz_0, g_0_xxxyyy_0_xyyyyzzz_1, g_0_xxxyyy_0_xyyyzzz_1, g_0_xxxyyy_0_xyyyzzzz_0, g_0_xxxyyy_0_xyyyzzzz_1, g_0_xxxyyy_0_xyyzzzz_1, g_0_xxxyyy_0_xyyzzzzz_0, g_0_xxxyyy_0_xyyzzzzz_1, g_0_xxxyyy_0_xyzzzzz_1, g_0_xxxyyy_0_xyzzzzzz_0, g_0_xxxyyy_0_xyzzzzzz_1, g_0_xxxyyy_0_xzzzzzz_1, g_0_xxxyyy_0_xzzzzzzz_0, g_0_xxxyyy_0_xzzzzzzz_1, g_0_xxxyyy_0_yyyyyyy_1, g_0_xxxyyy_0_yyyyyyyy_0, g_0_xxxyyy_0_yyyyyyyy_1, g_0_xxxyyy_0_yyyyyyyz_0, g_0_xxxyyy_0_yyyyyyyz_1, g_0_xxxyyy_0_yyyyyyz_1, g_0_xxxyyy_0_yyyyyyzz_0, g_0_xxxyyy_0_yyyyyyzz_1, g_0_xxxyyy_0_yyyyyzz_1, g_0_xxxyyy_0_yyyyyzzz_0, g_0_xxxyyy_0_yyyyyzzz_1, g_0_xxxyyy_0_yyyyzzz_1, g_0_xxxyyy_0_yyyyzzzz_0, g_0_xxxyyy_0_yyyyzzzz_1, g_0_xxxyyy_0_yyyzzzz_1, g_0_xxxyyy_0_yyyzzzzz_0, g_0_xxxyyy_0_yyyzzzzz_1, g_0_xxxyyy_0_yyzzzzz_1, g_0_xxxyyy_0_yyzzzzzz_0, g_0_xxxyyy_0_yyzzzzzz_1, g_0_xxxyyy_0_yzzzzzz_1, g_0_xxxyyy_0_yzzzzzzz_0, g_0_xxxyyy_0_yzzzzzzz_1, g_0_xxxyyy_0_zzzzzzz_1, g_0_xxxyyy_0_zzzzzzzz_0, g_0_xxxyyy_0_zzzzzzzz_1, g_0_xxxyyyz_0_xxxxxxxx_0, g_0_xxxyyyz_0_xxxxxxxy_0, g_0_xxxyyyz_0_xxxxxxxz_0, g_0_xxxyyyz_0_xxxxxxyy_0, g_0_xxxyyyz_0_xxxxxxyz_0, g_0_xxxyyyz_0_xxxxxxzz_0, g_0_xxxyyyz_0_xxxxxyyy_0, g_0_xxxyyyz_0_xxxxxyyz_0, g_0_xxxyyyz_0_xxxxxyzz_0, g_0_xxxyyyz_0_xxxxxzzz_0, g_0_xxxyyyz_0_xxxxyyyy_0, g_0_xxxyyyz_0_xxxxyyyz_0, g_0_xxxyyyz_0_xxxxyyzz_0, g_0_xxxyyyz_0_xxxxyzzz_0, g_0_xxxyyyz_0_xxxxzzzz_0, g_0_xxxyyyz_0_xxxyyyyy_0, g_0_xxxyyyz_0_xxxyyyyz_0, g_0_xxxyyyz_0_xxxyyyzz_0, g_0_xxxyyyz_0_xxxyyzzz_0, g_0_xxxyyyz_0_xxxyzzzz_0, g_0_xxxyyyz_0_xxxzzzzz_0, g_0_xxxyyyz_0_xxyyyyyy_0, g_0_xxxyyyz_0_xxyyyyyz_0, g_0_xxxyyyz_0_xxyyyyzz_0, g_0_xxxyyyz_0_xxyyyzzz_0, g_0_xxxyyyz_0_xxyyzzzz_0, g_0_xxxyyyz_0_xxyzzzzz_0, g_0_xxxyyyz_0_xxzzzzzz_0, g_0_xxxyyyz_0_xyyyyyyy_0, g_0_xxxyyyz_0_xyyyyyyz_0, g_0_xxxyyyz_0_xyyyyyzz_0, g_0_xxxyyyz_0_xyyyyzzz_0, g_0_xxxyyyz_0_xyyyzzzz_0, g_0_xxxyyyz_0_xyyzzzzz_0, g_0_xxxyyyz_0_xyzzzzzz_0, g_0_xxxyyyz_0_xzzzzzzz_0, g_0_xxxyyyz_0_yyyyyyyy_0, g_0_xxxyyyz_0_yyyyyyyz_0, g_0_xxxyyyz_0_yyyyyyzz_0, g_0_xxxyyyz_0_yyyyyzzz_0, g_0_xxxyyyz_0_yyyyzzzz_0, g_0_xxxyyyz_0_yyyzzzzz_0, g_0_xxxyyyz_0_yyzzzzzz_0, g_0_xxxyyyz_0_yzzzzzzz_0, g_0_xxxyyyz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxyyyz_0_xxxxxxxx_0[i] = g_0_xxxyyy_0_xxxxxxxx_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxxxy_0[i] = g_0_xxxyyy_0_xxxxxxxy_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxxxz_0[i] = g_0_xxxyyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxxz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxxyy_0[i] = g_0_xxxyyy_0_xxxxxxyy_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxxyz_0[i] = g_0_xxxyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxyz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxxzz_0[i] = 2.0 * g_0_xxxyyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxxzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxyyy_0[i] = g_0_xxxyyy_0_xxxxxyyy_0[i] * pb_z + g_0_xxxyyy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxyyz_0[i] = g_0_xxxyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxyyz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxyzz_0[i] = 2.0 * g_0_xxxyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxyzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxxzzz_0[i] = 3.0 * g_0_xxxyyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxxzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxyyyy_0[i] = g_0_xxxyyy_0_xxxxyyyy_0[i] * pb_z + g_0_xxxyyy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxyyyz_0[i] = g_0_xxxyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyyyz_0[i] * pb_z + g_0_xxxyyy_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyyzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxyzzz_0[i] = 3.0 * g_0_xxxyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxyzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxxzzzz_0[i] = 4.0 * g_0_xxxyyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxxzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxyyyyy_0[i] = g_0_xxxyyy_0_xxxyyyyy_0[i] * pb_z + g_0_xxxyyy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxyyyyz_0[i] = g_0_xxxyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyyyz_0[i] * pb_z + g_0_xxxyyy_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxyyyzz_0[i] = 2.0 * g_0_xxxyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyyzz_0[i] * pb_z + g_0_xxxyyy_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxyyzzz_0[i] = 3.0 * g_0_xxxyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyyzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxyzzzz_0[i] = 4.0 * g_0_xxxyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxyzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxxzzzzz_0[i] = 5.0 * g_0_xxxyyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxxzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyyyyyy_0[i] = g_0_xxxyyy_0_xxyyyyyy_0[i] * pb_z + g_0_xxxyyy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyyyyyz_0[i] = g_0_xxxyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyyyz_0[i] * pb_z + g_0_xxxyyy_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyyyyzz_0[i] = 2.0 * g_0_xxxyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyyzz_0[i] * pb_z + g_0_xxxyyy_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyyzzz_0[i] * pb_z + g_0_xxxyyy_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyyzzzz_0[i] = 4.0 * g_0_xxxyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyyzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxyzzzzz_0[i] = 5.0 * g_0_xxxyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxyzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xxzzzzzz_0[i] = 6.0 * g_0_xxxyyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xxzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyyyyyy_0[i] = g_0_xxxyyy_0_xyyyyyyy_0[i] * pb_z + g_0_xxxyyy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyyyyyz_0[i] = g_0_xxxyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyyyz_0[i] * pb_z + g_0_xxxyyy_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyyyyzz_0[i] = 2.0 * g_0_xxxyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyyzz_0[i] * pb_z + g_0_xxxyyy_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyyyzzz_0[i] = 3.0 * g_0_xxxyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyyzzz_0[i] * pb_z + g_0_xxxyyy_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyyzzzz_0[i] = 4.0 * g_0_xxxyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyyzzzz_0[i] * pb_z + g_0_xxxyyy_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyyzzzzz_0[i] = 5.0 * g_0_xxxyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyyzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xyzzzzzz_0[i] = 6.0 * g_0_xxxyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xyzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_xzzzzzzz_0[i] = 7.0 * g_0_xxxyyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_xzzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyyyyyy_0[i] = g_0_xxxyyy_0_yyyyyyyy_0[i] * pb_z + g_0_xxxyyy_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyyyyyz_0[i] = g_0_xxxyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyyyyyyz_0[i] * pb_z + g_0_xxxyyy_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyyyyzz_0[i] = 2.0 * g_0_xxxyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyyyyyzz_0[i] * pb_z + g_0_xxxyyy_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyyyzzz_0[i] = 3.0 * g_0_xxxyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyyyyzzz_0[i] * pb_z + g_0_xxxyyy_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyyyzzzz_0[i] * pb_z + g_0_xxxyyy_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyyzzzzz_0[i] = 5.0 * g_0_xxxyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyyzzzzz_0[i] * pb_z + g_0_xxxyyy_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yyzzzzzz_0[i] = 6.0 * g_0_xxxyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yyzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_yzzzzzzz_0[i] = 7.0 * g_0_xxxyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_yzzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_xxxyyyz_0_zzzzzzzz_0[i] = 8.0 * g_0_xxxyyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxyyy_0_zzzzzzzz_0[i] * pb_z + g_0_xxxyyy_0_zzzzzzzz_1[i] * wp_z[i];
    }

    /// Set up 540-585 components of targeted buffer : SKSL

    auto g_0_xxxyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 540);

    auto g_0_xxxyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 541);

    auto g_0_xxxyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 542);

    auto g_0_xxxyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 543);

    auto g_0_xxxyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 544);

    auto g_0_xxxyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 545);

    auto g_0_xxxyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 546);

    auto g_0_xxxyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 547);

    auto g_0_xxxyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 548);

    auto g_0_xxxyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 549);

    auto g_0_xxxyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 550);

    auto g_0_xxxyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 551);

    auto g_0_xxxyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 552);

    auto g_0_xxxyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 553);

    auto g_0_xxxyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 554);

    auto g_0_xxxyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 555);

    auto g_0_xxxyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 556);

    auto g_0_xxxyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 557);

    auto g_0_xxxyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 558);

    auto g_0_xxxyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 559);

    auto g_0_xxxyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 560);

    auto g_0_xxxyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 561);

    auto g_0_xxxyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 562);

    auto g_0_xxxyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 563);

    auto g_0_xxxyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 564);

    auto g_0_xxxyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 565);

    auto g_0_xxxyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 566);

    auto g_0_xxxyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 567);

    auto g_0_xxxyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 568);

    auto g_0_xxxyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 569);

    auto g_0_xxxyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 570);

    auto g_0_xxxyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 571);

    auto g_0_xxxyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 572);

    auto g_0_xxxyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 573);

    auto g_0_xxxyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 574);

    auto g_0_xxxyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 575);

    auto g_0_xxxyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 576);

    auto g_0_xxxyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 577);

    auto g_0_xxxyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 578);

    auto g_0_xxxyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 579);

    auto g_0_xxxyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 580);

    auto g_0_xxxyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 581);

    auto g_0_xxxyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 582);

    auto g_0_xxxyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 583);

    auto g_0_xxxyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 584);

    #pragma omp simd aligned(g_0_xxxyy_0_xxxxxxxy_0, g_0_xxxyy_0_xxxxxxxy_1, g_0_xxxyy_0_xxxxxxyy_0, g_0_xxxyy_0_xxxxxxyy_1, g_0_xxxyy_0_xxxxxyyy_0, g_0_xxxyy_0_xxxxxyyy_1, g_0_xxxyy_0_xxxxyyyy_0, g_0_xxxyy_0_xxxxyyyy_1, g_0_xxxyy_0_xxxyyyyy_0, g_0_xxxyy_0_xxxyyyyy_1, g_0_xxxyy_0_xxyyyyyy_0, g_0_xxxyy_0_xxyyyyyy_1, g_0_xxxyy_0_xyyyyyyy_0, g_0_xxxyy_0_xyyyyyyy_1, g_0_xxxyyz_0_xxxxxxxy_0, g_0_xxxyyz_0_xxxxxxxy_1, g_0_xxxyyz_0_xxxxxxyy_0, g_0_xxxyyz_0_xxxxxxyy_1, g_0_xxxyyz_0_xxxxxyyy_0, g_0_xxxyyz_0_xxxxxyyy_1, g_0_xxxyyz_0_xxxxyyyy_0, g_0_xxxyyz_0_xxxxyyyy_1, g_0_xxxyyz_0_xxxyyyyy_0, g_0_xxxyyz_0_xxxyyyyy_1, g_0_xxxyyz_0_xxyyyyyy_0, g_0_xxxyyz_0_xxyyyyyy_1, g_0_xxxyyz_0_xyyyyyyy_0, g_0_xxxyyz_0_xyyyyyyy_1, g_0_xxxyyzz_0_xxxxxxxx_0, g_0_xxxyyzz_0_xxxxxxxy_0, g_0_xxxyyzz_0_xxxxxxxz_0, g_0_xxxyyzz_0_xxxxxxyy_0, g_0_xxxyyzz_0_xxxxxxyz_0, g_0_xxxyyzz_0_xxxxxxzz_0, g_0_xxxyyzz_0_xxxxxyyy_0, g_0_xxxyyzz_0_xxxxxyyz_0, g_0_xxxyyzz_0_xxxxxyzz_0, g_0_xxxyyzz_0_xxxxxzzz_0, g_0_xxxyyzz_0_xxxxyyyy_0, g_0_xxxyyzz_0_xxxxyyyz_0, g_0_xxxyyzz_0_xxxxyyzz_0, g_0_xxxyyzz_0_xxxxyzzz_0, g_0_xxxyyzz_0_xxxxzzzz_0, g_0_xxxyyzz_0_xxxyyyyy_0, g_0_xxxyyzz_0_xxxyyyyz_0, g_0_xxxyyzz_0_xxxyyyzz_0, g_0_xxxyyzz_0_xxxyyzzz_0, g_0_xxxyyzz_0_xxxyzzzz_0, g_0_xxxyyzz_0_xxxzzzzz_0, g_0_xxxyyzz_0_xxyyyyyy_0, g_0_xxxyyzz_0_xxyyyyyz_0, g_0_xxxyyzz_0_xxyyyyzz_0, g_0_xxxyyzz_0_xxyyyzzz_0, g_0_xxxyyzz_0_xxyyzzzz_0, g_0_xxxyyzz_0_xxyzzzzz_0, g_0_xxxyyzz_0_xxzzzzzz_0, g_0_xxxyyzz_0_xyyyyyyy_0, g_0_xxxyyzz_0_xyyyyyyz_0, g_0_xxxyyzz_0_xyyyyyzz_0, g_0_xxxyyzz_0_xyyyyzzz_0, g_0_xxxyyzz_0_xyyyzzzz_0, g_0_xxxyyzz_0_xyyzzzzz_0, g_0_xxxyyzz_0_xyzzzzzz_0, g_0_xxxyyzz_0_xzzzzzzz_0, g_0_xxxyyzz_0_yyyyyyyy_0, g_0_xxxyyzz_0_yyyyyyyz_0, g_0_xxxyyzz_0_yyyyyyzz_0, g_0_xxxyyzz_0_yyyyyzzz_0, g_0_xxxyyzz_0_yyyyzzzz_0, g_0_xxxyyzz_0_yyyzzzzz_0, g_0_xxxyyzz_0_yyzzzzzz_0, g_0_xxxyyzz_0_yzzzzzzz_0, g_0_xxxyyzz_0_zzzzzzzz_0, g_0_xxxyzz_0_xxxxxxxx_0, g_0_xxxyzz_0_xxxxxxxx_1, g_0_xxxyzz_0_xxxxxxxz_0, g_0_xxxyzz_0_xxxxxxxz_1, g_0_xxxyzz_0_xxxxxxzz_0, g_0_xxxyzz_0_xxxxxxzz_1, g_0_xxxyzz_0_xxxxxzzz_0, g_0_xxxyzz_0_xxxxxzzz_1, g_0_xxxyzz_0_xxxxzzzz_0, g_0_xxxyzz_0_xxxxzzzz_1, g_0_xxxyzz_0_xxxzzzzz_0, g_0_xxxyzz_0_xxxzzzzz_1, g_0_xxxyzz_0_xxzzzzzz_0, g_0_xxxyzz_0_xxzzzzzz_1, g_0_xxxyzz_0_xzzzzzzz_0, g_0_xxxyzz_0_xzzzzzzz_1, g_0_xxxzz_0_xxxxxxxx_0, g_0_xxxzz_0_xxxxxxxx_1, g_0_xxxzz_0_xxxxxxxz_0, g_0_xxxzz_0_xxxxxxxz_1, g_0_xxxzz_0_xxxxxxzz_0, g_0_xxxzz_0_xxxxxxzz_1, g_0_xxxzz_0_xxxxxzzz_0, g_0_xxxzz_0_xxxxxzzz_1, g_0_xxxzz_0_xxxxzzzz_0, g_0_xxxzz_0_xxxxzzzz_1, g_0_xxxzz_0_xxxzzzzz_0, g_0_xxxzz_0_xxxzzzzz_1, g_0_xxxzz_0_xxzzzzzz_0, g_0_xxxzz_0_xxzzzzzz_1, g_0_xxxzz_0_xzzzzzzz_0, g_0_xxxzz_0_xzzzzzzz_1, g_0_xxyyzz_0_xxxxxxyz_0, g_0_xxyyzz_0_xxxxxxyz_1, g_0_xxyyzz_0_xxxxxyyz_0, g_0_xxyyzz_0_xxxxxyyz_1, g_0_xxyyzz_0_xxxxxyz_1, g_0_xxyyzz_0_xxxxxyzz_0, g_0_xxyyzz_0_xxxxxyzz_1, g_0_xxyyzz_0_xxxxyyyz_0, g_0_xxyyzz_0_xxxxyyyz_1, g_0_xxyyzz_0_xxxxyyz_1, g_0_xxyyzz_0_xxxxyyzz_0, g_0_xxyyzz_0_xxxxyyzz_1, g_0_xxyyzz_0_xxxxyzz_1, g_0_xxyyzz_0_xxxxyzzz_0, g_0_xxyyzz_0_xxxxyzzz_1, g_0_xxyyzz_0_xxxyyyyz_0, g_0_xxyyzz_0_xxxyyyyz_1, g_0_xxyyzz_0_xxxyyyz_1, g_0_xxyyzz_0_xxxyyyzz_0, g_0_xxyyzz_0_xxxyyyzz_1, g_0_xxyyzz_0_xxxyyzz_1, g_0_xxyyzz_0_xxxyyzzz_0, g_0_xxyyzz_0_xxxyyzzz_1, g_0_xxyyzz_0_xxxyzzz_1, g_0_xxyyzz_0_xxxyzzzz_0, g_0_xxyyzz_0_xxxyzzzz_1, g_0_xxyyzz_0_xxyyyyyz_0, g_0_xxyyzz_0_xxyyyyyz_1, g_0_xxyyzz_0_xxyyyyz_1, g_0_xxyyzz_0_xxyyyyzz_0, g_0_xxyyzz_0_xxyyyyzz_1, g_0_xxyyzz_0_xxyyyzz_1, g_0_xxyyzz_0_xxyyyzzz_0, g_0_xxyyzz_0_xxyyyzzz_1, g_0_xxyyzz_0_xxyyzzz_1, g_0_xxyyzz_0_xxyyzzzz_0, g_0_xxyyzz_0_xxyyzzzz_1, g_0_xxyyzz_0_xxyzzzz_1, g_0_xxyyzz_0_xxyzzzzz_0, g_0_xxyyzz_0_xxyzzzzz_1, g_0_xxyyzz_0_xyyyyyyz_0, g_0_xxyyzz_0_xyyyyyyz_1, g_0_xxyyzz_0_xyyyyyz_1, g_0_xxyyzz_0_xyyyyyzz_0, g_0_xxyyzz_0_xyyyyyzz_1, g_0_xxyyzz_0_xyyyyzz_1, g_0_xxyyzz_0_xyyyyzzz_0, g_0_xxyyzz_0_xyyyyzzz_1, g_0_xxyyzz_0_xyyyzzz_1, g_0_xxyyzz_0_xyyyzzzz_0, g_0_xxyyzz_0_xyyyzzzz_1, g_0_xxyyzz_0_xyyzzzz_1, g_0_xxyyzz_0_xyyzzzzz_0, g_0_xxyyzz_0_xyyzzzzz_1, g_0_xxyyzz_0_xyzzzzz_1, g_0_xxyyzz_0_xyzzzzzz_0, g_0_xxyyzz_0_xyzzzzzz_1, g_0_xxyyzz_0_yyyyyyyy_0, g_0_xxyyzz_0_yyyyyyyy_1, g_0_xxyyzz_0_yyyyyyyz_0, g_0_xxyyzz_0_yyyyyyyz_1, g_0_xxyyzz_0_yyyyyyz_1, g_0_xxyyzz_0_yyyyyyzz_0, g_0_xxyyzz_0_yyyyyyzz_1, g_0_xxyyzz_0_yyyyyzz_1, g_0_xxyyzz_0_yyyyyzzz_0, g_0_xxyyzz_0_yyyyyzzz_1, g_0_xxyyzz_0_yyyyzzz_1, g_0_xxyyzz_0_yyyyzzzz_0, g_0_xxyyzz_0_yyyyzzzz_1, g_0_xxyyzz_0_yyyzzzz_1, g_0_xxyyzz_0_yyyzzzzz_0, g_0_xxyyzz_0_yyyzzzzz_1, g_0_xxyyzz_0_yyzzzzz_1, g_0_xxyyzz_0_yyzzzzzz_0, g_0_xxyyzz_0_yyzzzzzz_1, g_0_xxyyzz_0_yzzzzzz_1, g_0_xxyyzz_0_yzzzzzzz_0, g_0_xxyyzz_0_yzzzzzzz_1, g_0_xxyyzz_0_zzzzzzzz_0, g_0_xxyyzz_0_zzzzzzzz_1, g_0_xyyzz_0_xxxxxxyz_0, g_0_xyyzz_0_xxxxxxyz_1, g_0_xyyzz_0_xxxxxyyz_0, g_0_xyyzz_0_xxxxxyyz_1, g_0_xyyzz_0_xxxxxyzz_0, g_0_xyyzz_0_xxxxxyzz_1, g_0_xyyzz_0_xxxxyyyz_0, g_0_xyyzz_0_xxxxyyyz_1, g_0_xyyzz_0_xxxxyyzz_0, g_0_xyyzz_0_xxxxyyzz_1, g_0_xyyzz_0_xxxxyzzz_0, g_0_xyyzz_0_xxxxyzzz_1, g_0_xyyzz_0_xxxyyyyz_0, g_0_xyyzz_0_xxxyyyyz_1, g_0_xyyzz_0_xxxyyyzz_0, g_0_xyyzz_0_xxxyyyzz_1, g_0_xyyzz_0_xxxyyzzz_0, g_0_xyyzz_0_xxxyyzzz_1, g_0_xyyzz_0_xxxyzzzz_0, g_0_xyyzz_0_xxxyzzzz_1, g_0_xyyzz_0_xxyyyyyz_0, g_0_xyyzz_0_xxyyyyyz_1, g_0_xyyzz_0_xxyyyyzz_0, g_0_xyyzz_0_xxyyyyzz_1, g_0_xyyzz_0_xxyyyzzz_0, g_0_xyyzz_0_xxyyyzzz_1, g_0_xyyzz_0_xxyyzzzz_0, g_0_xyyzz_0_xxyyzzzz_1, g_0_xyyzz_0_xxyzzzzz_0, g_0_xyyzz_0_xxyzzzzz_1, g_0_xyyzz_0_xyyyyyyz_0, g_0_xyyzz_0_xyyyyyyz_1, g_0_xyyzz_0_xyyyyyzz_0, g_0_xyyzz_0_xyyyyyzz_1, g_0_xyyzz_0_xyyyyzzz_0, g_0_xyyzz_0_xyyyyzzz_1, g_0_xyyzz_0_xyyyzzzz_0, g_0_xyyzz_0_xyyyzzzz_1, g_0_xyyzz_0_xyyzzzzz_0, g_0_xyyzz_0_xyyzzzzz_1, g_0_xyyzz_0_xyzzzzzz_0, g_0_xyyzz_0_xyzzzzzz_1, g_0_xyyzz_0_yyyyyyyy_0, g_0_xyyzz_0_yyyyyyyy_1, g_0_xyyzz_0_yyyyyyyz_0, g_0_xyyzz_0_yyyyyyyz_1, g_0_xyyzz_0_yyyyyyzz_0, g_0_xyyzz_0_yyyyyyzz_1, g_0_xyyzz_0_yyyyyzzz_0, g_0_xyyzz_0_yyyyyzzz_1, g_0_xyyzz_0_yyyyzzzz_0, g_0_xyyzz_0_yyyyzzzz_1, g_0_xyyzz_0_yyyzzzzz_0, g_0_xyyzz_0_yyyzzzzz_1, g_0_xyyzz_0_yyzzzzzz_0, g_0_xyyzz_0_yyzzzzzz_1, g_0_xyyzz_0_yzzzzzzz_0, g_0_xyyzz_0_yzzzzzzz_1, g_0_xyyzz_0_zzzzzzzz_0, g_0_xyyzz_0_zzzzzzzz_1, wp_x, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxyyzz_0_xxxxxxxx_0[i] = g_0_xxxzz_0_xxxxxxxx_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxxyzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxxxxxxy_0[i] = g_0_xxxyy_0_xxxxxxxy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxxxxxxy_0[i] * pb_z + g_0_xxxyyz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxxxxxxz_0[i] = g_0_xxxzz_0_xxxxxxxz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxxyzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxxxxxyy_0[i] = g_0_xxxyy_0_xxxxxxyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxxxxxyy_0[i] * pb_z + g_0_xxxyyz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxxxxxyz_0[i] = 2.0 * g_0_xyyzz_0_xxxxxxyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxyyzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxxxyz_0[i] * pb_x + g_0_xxyyzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxxxzz_0[i] = g_0_xxxzz_0_xxxxxxzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxxyzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxxxxyyy_0[i] = g_0_xxxyy_0_xxxxxyyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxxxxyyy_0[i] * pb_z + g_0_xxxyyz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxxxxyyz_0[i] = 2.0 * g_0_xyyzz_0_xxxxxyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxyyzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxxyyz_0[i] * pb_x + g_0_xxyyzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxxyzz_0[i] = 2.0 * g_0_xyyzz_0_xxxxxyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxyyzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxxyzz_0[i] * pb_x + g_0_xxyyzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxxzzz_0[i] = g_0_xxxzz_0_xxxxxzzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxxyzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxxxyyyy_0[i] = g_0_xxxyy_0_xxxxyyyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxxxyyyy_0[i] * pb_z + g_0_xxxyyz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxxxyyyz_0[i] = 2.0 * g_0_xyyzz_0_xxxxyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxyyyz_0[i] * pb_x + g_0_xxyyzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxyyzz_0[i] = 2.0 * g_0_xyyzz_0_xxxxyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxyyzz_0[i] * pb_x + g_0_xxyyzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxyzzz_0[i] = 2.0 * g_0_xyyzz_0_xxxxyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxyyzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxxyzzz_0[i] * pb_x + g_0_xxyyzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxxzzzz_0[i] = g_0_xxxzz_0_xxxxzzzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxxyzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxxyyyyy_0[i] = g_0_xxxyy_0_xxxyyyyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxxyyyyy_0[i] * pb_z + g_0_xxxyyz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxxyyyyz_0[i] = 2.0 * g_0_xyyzz_0_xxxyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxyyyyz_0[i] * pb_x + g_0_xxyyzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxyyyzz_0[i] = 2.0 * g_0_xyyzz_0_xxxyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxyyyzz_0[i] * pb_x + g_0_xxyyzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxyyzzz_0[i] = 2.0 * g_0_xyyzz_0_xxxyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxyyzzz_0[i] * pb_x + g_0_xxyyzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxyzzzz_0[i] = 2.0 * g_0_xyyzz_0_xxxyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxyyzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxxyzzzz_0[i] * pb_x + g_0_xxyyzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxxzzzzz_0[i] = g_0_xxxzz_0_xxxzzzzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxxyzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xxyyyyyy_0[i] = g_0_xxxyy_0_xxyyyyyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xxyyyyyy_0[i] * pb_z + g_0_xxxyyz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xxyyyyyz_0[i] = 2.0 * g_0_xyyzz_0_xxyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxyyyyyz_0[i] * pb_x + g_0_xxyyzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxyyyyzz_0[i] = 2.0 * g_0_xyyzz_0_xxyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxyyyyzz_0[i] * pb_x + g_0_xxyyzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxyyyzzz_0[i] = 2.0 * g_0_xyyzz_0_xxyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxyyyzzz_0[i] * pb_x + g_0_xxyyzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxyyzzzz_0[i] = 2.0 * g_0_xyyzz_0_xxyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxyyzzzz_0[i] * pb_x + g_0_xxyyzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxyzzzzz_0[i] = 2.0 * g_0_xyyzz_0_xxyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxyyzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xxyzzzzz_0[i] * pb_x + g_0_xxyyzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xxzzzzzz_0[i] = g_0_xxxzz_0_xxzzzzzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxxyzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_xyyyyyyy_0[i] = g_0_xxxyy_0_xyyyyyyy_0[i] * fi_ab_0 - g_0_xxxyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxyyz_0_xyyyyyyy_0[i] * pb_z + g_0_xxxyyz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxyyzz_0_xyyyyyyz_0[i] = 2.0 * g_0_xyyzz_0_xyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyyyyyyz_0[i] * pb_x + g_0_xxyyzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xyyyyyzz_0[i] = 2.0 * g_0_xyyzz_0_xyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyyyyyzz_0[i] * pb_x + g_0_xxyyzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xyyyyzzz_0[i] = 2.0 * g_0_xyyzz_0_xyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyyyyzzz_0[i] * pb_x + g_0_xxyyzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xyyyzzzz_0[i] = 2.0 * g_0_xyyzz_0_xyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyyyzzzz_0[i] * pb_x + g_0_xxyyzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xyyzzzzz_0[i] = 2.0 * g_0_xyyzz_0_xyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyyzzzzz_0[i] * pb_x + g_0_xxyyzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xyzzzzzz_0[i] = 2.0 * g_0_xyyzz_0_xyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxyyzz_0_xyzzzzzz_0[i] * pb_x + g_0_xxyyzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_xzzzzzzz_0[i] = g_0_xxxzz_0_xzzzzzzz_0[i] * fi_ab_0 - g_0_xxxzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxxyzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxxyzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxyyzz_0_yyyyyyyy_0[i] = 2.0 * g_0_xyyzz_0_yyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyyyy_0[i] * pb_x + g_0_xxyyzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyyyyyyz_0[i] = 2.0 * g_0_xyyzz_0_yyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyyyz_0[i] * pb_x + g_0_xxyyzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyyyyyzz_0[i] = 2.0 * g_0_xyyzz_0_yyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyyzz_0[i] * pb_x + g_0_xxyyzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyyyyzzz_0[i] = 2.0 * g_0_xyyzz_0_yyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyyzzz_0[i] * pb_x + g_0_xxyyzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyyyzzzz_0[i] = 2.0 * g_0_xyyzz_0_yyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyyzzzz_0[i] * pb_x + g_0_xxyyzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyyzzzzz_0[i] = 2.0 * g_0_xyyzz_0_yyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyyzzzzz_0[i] * pb_x + g_0_xxyyzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yyzzzzzz_0[i] = 2.0 * g_0_xyyzz_0_yyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yyzzzzzz_0[i] * pb_x + g_0_xxyyzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_yzzzzzzz_0[i] = 2.0 * g_0_xyyzz_0_yzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_yzzzzzzz_0[i] * pb_x + g_0_xxyyzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxyyzz_0_zzzzzzzz_0[i] = 2.0 * g_0_xyyzz_0_zzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xyyzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_zzzzzzzz_0[i] * pb_x + g_0_xxyyzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 585-630 components of targeted buffer : SKSL

    auto g_0_xxxyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 585);

    auto g_0_xxxyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 586);

    auto g_0_xxxyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 587);

    auto g_0_xxxyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 588);

    auto g_0_xxxyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 589);

    auto g_0_xxxyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 590);

    auto g_0_xxxyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 591);

    auto g_0_xxxyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 592);

    auto g_0_xxxyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 593);

    auto g_0_xxxyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 594);

    auto g_0_xxxyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 595);

    auto g_0_xxxyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 596);

    auto g_0_xxxyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 597);

    auto g_0_xxxyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 598);

    auto g_0_xxxyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 599);

    auto g_0_xxxyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 600);

    auto g_0_xxxyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 601);

    auto g_0_xxxyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 602);

    auto g_0_xxxyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 603);

    auto g_0_xxxyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 604);

    auto g_0_xxxyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 605);

    auto g_0_xxxyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 606);

    auto g_0_xxxyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 607);

    auto g_0_xxxyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 608);

    auto g_0_xxxyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 609);

    auto g_0_xxxyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 610);

    auto g_0_xxxyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 611);

    auto g_0_xxxyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 612);

    auto g_0_xxxyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 613);

    auto g_0_xxxyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 614);

    auto g_0_xxxyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 615);

    auto g_0_xxxyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 616);

    auto g_0_xxxyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 617);

    auto g_0_xxxyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 618);

    auto g_0_xxxyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 619);

    auto g_0_xxxyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 620);

    auto g_0_xxxyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 621);

    auto g_0_xxxyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 622);

    auto g_0_xxxyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 623);

    auto g_0_xxxyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 624);

    auto g_0_xxxyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 625);

    auto g_0_xxxyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 626);

    auto g_0_xxxyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 627);

    auto g_0_xxxyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 628);

    auto g_0_xxxyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 629);

    #pragma omp simd aligned(g_0_xxxyzzz_0_xxxxxxxx_0, g_0_xxxyzzz_0_xxxxxxxy_0, g_0_xxxyzzz_0_xxxxxxxz_0, g_0_xxxyzzz_0_xxxxxxyy_0, g_0_xxxyzzz_0_xxxxxxyz_0, g_0_xxxyzzz_0_xxxxxxzz_0, g_0_xxxyzzz_0_xxxxxyyy_0, g_0_xxxyzzz_0_xxxxxyyz_0, g_0_xxxyzzz_0_xxxxxyzz_0, g_0_xxxyzzz_0_xxxxxzzz_0, g_0_xxxyzzz_0_xxxxyyyy_0, g_0_xxxyzzz_0_xxxxyyyz_0, g_0_xxxyzzz_0_xxxxyyzz_0, g_0_xxxyzzz_0_xxxxyzzz_0, g_0_xxxyzzz_0_xxxxzzzz_0, g_0_xxxyzzz_0_xxxyyyyy_0, g_0_xxxyzzz_0_xxxyyyyz_0, g_0_xxxyzzz_0_xxxyyyzz_0, g_0_xxxyzzz_0_xxxyyzzz_0, g_0_xxxyzzz_0_xxxyzzzz_0, g_0_xxxyzzz_0_xxxzzzzz_0, g_0_xxxyzzz_0_xxyyyyyy_0, g_0_xxxyzzz_0_xxyyyyyz_0, g_0_xxxyzzz_0_xxyyyyzz_0, g_0_xxxyzzz_0_xxyyyzzz_0, g_0_xxxyzzz_0_xxyyzzzz_0, g_0_xxxyzzz_0_xxyzzzzz_0, g_0_xxxyzzz_0_xxzzzzzz_0, g_0_xxxyzzz_0_xyyyyyyy_0, g_0_xxxyzzz_0_xyyyyyyz_0, g_0_xxxyzzz_0_xyyyyyzz_0, g_0_xxxyzzz_0_xyyyyzzz_0, g_0_xxxyzzz_0_xyyyzzzz_0, g_0_xxxyzzz_0_xyyzzzzz_0, g_0_xxxyzzz_0_xyzzzzzz_0, g_0_xxxyzzz_0_xzzzzzzz_0, g_0_xxxyzzz_0_yyyyyyyy_0, g_0_xxxyzzz_0_yyyyyyyz_0, g_0_xxxyzzz_0_yyyyyyzz_0, g_0_xxxyzzz_0_yyyyyzzz_0, g_0_xxxyzzz_0_yyyyzzzz_0, g_0_xxxyzzz_0_yyyzzzzz_0, g_0_xxxyzzz_0_yyzzzzzz_0, g_0_xxxyzzz_0_yzzzzzzz_0, g_0_xxxyzzz_0_zzzzzzzz_0, g_0_xxxzzz_0_xxxxxxx_1, g_0_xxxzzz_0_xxxxxxxx_0, g_0_xxxzzz_0_xxxxxxxx_1, g_0_xxxzzz_0_xxxxxxxy_0, g_0_xxxzzz_0_xxxxxxxy_1, g_0_xxxzzz_0_xxxxxxxz_0, g_0_xxxzzz_0_xxxxxxxz_1, g_0_xxxzzz_0_xxxxxxy_1, g_0_xxxzzz_0_xxxxxxyy_0, g_0_xxxzzz_0_xxxxxxyy_1, g_0_xxxzzz_0_xxxxxxyz_0, g_0_xxxzzz_0_xxxxxxyz_1, g_0_xxxzzz_0_xxxxxxz_1, g_0_xxxzzz_0_xxxxxxzz_0, g_0_xxxzzz_0_xxxxxxzz_1, g_0_xxxzzz_0_xxxxxyy_1, g_0_xxxzzz_0_xxxxxyyy_0, g_0_xxxzzz_0_xxxxxyyy_1, g_0_xxxzzz_0_xxxxxyyz_0, g_0_xxxzzz_0_xxxxxyyz_1, g_0_xxxzzz_0_xxxxxyz_1, g_0_xxxzzz_0_xxxxxyzz_0, g_0_xxxzzz_0_xxxxxyzz_1, g_0_xxxzzz_0_xxxxxzz_1, g_0_xxxzzz_0_xxxxxzzz_0, g_0_xxxzzz_0_xxxxxzzz_1, g_0_xxxzzz_0_xxxxyyy_1, g_0_xxxzzz_0_xxxxyyyy_0, g_0_xxxzzz_0_xxxxyyyy_1, g_0_xxxzzz_0_xxxxyyyz_0, g_0_xxxzzz_0_xxxxyyyz_1, g_0_xxxzzz_0_xxxxyyz_1, g_0_xxxzzz_0_xxxxyyzz_0, g_0_xxxzzz_0_xxxxyyzz_1, g_0_xxxzzz_0_xxxxyzz_1, g_0_xxxzzz_0_xxxxyzzz_0, g_0_xxxzzz_0_xxxxyzzz_1, g_0_xxxzzz_0_xxxxzzz_1, g_0_xxxzzz_0_xxxxzzzz_0, g_0_xxxzzz_0_xxxxzzzz_1, g_0_xxxzzz_0_xxxyyyy_1, g_0_xxxzzz_0_xxxyyyyy_0, g_0_xxxzzz_0_xxxyyyyy_1, g_0_xxxzzz_0_xxxyyyyz_0, g_0_xxxzzz_0_xxxyyyyz_1, g_0_xxxzzz_0_xxxyyyz_1, g_0_xxxzzz_0_xxxyyyzz_0, g_0_xxxzzz_0_xxxyyyzz_1, g_0_xxxzzz_0_xxxyyzz_1, g_0_xxxzzz_0_xxxyyzzz_0, g_0_xxxzzz_0_xxxyyzzz_1, g_0_xxxzzz_0_xxxyzzz_1, g_0_xxxzzz_0_xxxyzzzz_0, g_0_xxxzzz_0_xxxyzzzz_1, g_0_xxxzzz_0_xxxzzzz_1, g_0_xxxzzz_0_xxxzzzzz_0, g_0_xxxzzz_0_xxxzzzzz_1, g_0_xxxzzz_0_xxyyyyy_1, g_0_xxxzzz_0_xxyyyyyy_0, g_0_xxxzzz_0_xxyyyyyy_1, g_0_xxxzzz_0_xxyyyyyz_0, g_0_xxxzzz_0_xxyyyyyz_1, g_0_xxxzzz_0_xxyyyyz_1, g_0_xxxzzz_0_xxyyyyzz_0, g_0_xxxzzz_0_xxyyyyzz_1, g_0_xxxzzz_0_xxyyyzz_1, g_0_xxxzzz_0_xxyyyzzz_0, g_0_xxxzzz_0_xxyyyzzz_1, g_0_xxxzzz_0_xxyyzzz_1, g_0_xxxzzz_0_xxyyzzzz_0, g_0_xxxzzz_0_xxyyzzzz_1, g_0_xxxzzz_0_xxyzzzz_1, g_0_xxxzzz_0_xxyzzzzz_0, g_0_xxxzzz_0_xxyzzzzz_1, g_0_xxxzzz_0_xxzzzzz_1, g_0_xxxzzz_0_xxzzzzzz_0, g_0_xxxzzz_0_xxzzzzzz_1, g_0_xxxzzz_0_xyyyyyy_1, g_0_xxxzzz_0_xyyyyyyy_0, g_0_xxxzzz_0_xyyyyyyy_1, g_0_xxxzzz_0_xyyyyyyz_0, g_0_xxxzzz_0_xyyyyyyz_1, g_0_xxxzzz_0_xyyyyyz_1, g_0_xxxzzz_0_xyyyyyzz_0, g_0_xxxzzz_0_xyyyyyzz_1, g_0_xxxzzz_0_xyyyyzz_1, g_0_xxxzzz_0_xyyyyzzz_0, g_0_xxxzzz_0_xyyyyzzz_1, g_0_xxxzzz_0_xyyyzzz_1, g_0_xxxzzz_0_xyyyzzzz_0, g_0_xxxzzz_0_xyyyzzzz_1, g_0_xxxzzz_0_xyyzzzz_1, g_0_xxxzzz_0_xyyzzzzz_0, g_0_xxxzzz_0_xyyzzzzz_1, g_0_xxxzzz_0_xyzzzzz_1, g_0_xxxzzz_0_xyzzzzzz_0, g_0_xxxzzz_0_xyzzzzzz_1, g_0_xxxzzz_0_xzzzzzz_1, g_0_xxxzzz_0_xzzzzzzz_0, g_0_xxxzzz_0_xzzzzzzz_1, g_0_xxxzzz_0_yyyyyyy_1, g_0_xxxzzz_0_yyyyyyyy_0, g_0_xxxzzz_0_yyyyyyyy_1, g_0_xxxzzz_0_yyyyyyyz_0, g_0_xxxzzz_0_yyyyyyyz_1, g_0_xxxzzz_0_yyyyyyz_1, g_0_xxxzzz_0_yyyyyyzz_0, g_0_xxxzzz_0_yyyyyyzz_1, g_0_xxxzzz_0_yyyyyzz_1, g_0_xxxzzz_0_yyyyyzzz_0, g_0_xxxzzz_0_yyyyyzzz_1, g_0_xxxzzz_0_yyyyzzz_1, g_0_xxxzzz_0_yyyyzzzz_0, g_0_xxxzzz_0_yyyyzzzz_1, g_0_xxxzzz_0_yyyzzzz_1, g_0_xxxzzz_0_yyyzzzzz_0, g_0_xxxzzz_0_yyyzzzzz_1, g_0_xxxzzz_0_yyzzzzz_1, g_0_xxxzzz_0_yyzzzzzz_0, g_0_xxxzzz_0_yyzzzzzz_1, g_0_xxxzzz_0_yzzzzzz_1, g_0_xxxzzz_0_yzzzzzzz_0, g_0_xxxzzz_0_yzzzzzzz_1, g_0_xxxzzz_0_zzzzzzz_1, g_0_xxxzzz_0_zzzzzzzz_0, g_0_xxxzzz_0_zzzzzzzz_1, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxxyzzz_0_xxxxxxxx_0[i] = g_0_xxxzzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxxxy_0[i] = g_0_xxxzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxxy_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxxxz_0[i] = g_0_xxxzzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_xxxzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxyy_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxxyz_0[i] = g_0_xxxzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxxyz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxxzz_0[i] = g_0_xxxzzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxyyy_0[i] = 3.0 * g_0_xxxzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxyyy_0[i] * pb_y + g_0_xxxzzz_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxyyz_0[i] = 2.0 * g_0_xxxzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxyyz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxyzz_0[i] = g_0_xxxzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxxyzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxxzzz_0[i] = g_0_xxxzzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_xxxzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyyyy_0[i] * pb_y + g_0_xxxzzz_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxyyyz_0[i] = 3.0 * g_0_xxxzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyyyz_0[i] * pb_y + g_0_xxxzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxxzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyyzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxyzzz_0[i] = g_0_xxxzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxxyzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxxzzzz_0[i] = g_0_xxxzzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxyyyyy_0[i] = 5.0 * g_0_xxxzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyyyy_0[i] * pb_y + g_0_xxxzzz_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxyyyyz_0[i] = 4.0 * g_0_xxxzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyyyz_0[i] * pb_y + g_0_xxxzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_xxxzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyyzz_0[i] * pb_y + g_0_xxxzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxyyzzz_0[i] = 2.0 * g_0_xxxzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyyzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxyzzzz_0[i] = g_0_xxxzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxxyzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxxzzzzz_0[i] = g_0_xxxzzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyyyyyy_0[i] = 6.0 * g_0_xxxzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyyyy_0[i] * pb_y + g_0_xxxzzz_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyyyyyz_0[i] = 5.0 * g_0_xxxzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyyyz_0[i] * pb_y + g_0_xxxzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyyyyzz_0[i] = 4.0 * g_0_xxxzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyyzz_0[i] * pb_y + g_0_xxxzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxxzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyyzzz_0[i] * pb_y + g_0_xxxzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_xxxzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyyzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxyzzzzz_0[i] = g_0_xxxzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xxyzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xxzzzzzz_0[i] = g_0_xxxzzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyyyyyy_0[i] = 7.0 * g_0_xxxzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyyyy_0[i] * pb_y + g_0_xxxzzz_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyyyyyz_0[i] = 6.0 * g_0_xxxzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyyyz_0[i] * pb_y + g_0_xxxzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyyyyzz_0[i] = 5.0 * g_0_xxxzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyyzz_0[i] * pb_y + g_0_xxxzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyyyzzz_0[i] = 4.0 * g_0_xxxzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyyzzz_0[i] * pb_y + g_0_xxxzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyyzzzz_0[i] = 3.0 * g_0_xxxzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyyzzzz_0[i] * pb_y + g_0_xxxzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyyzzzzz_0[i] = 2.0 * g_0_xxxzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyyzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xyzzzzzz_0[i] = g_0_xxxzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_xyzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_xzzzzzzz_0[i] = g_0_xxxzzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyyyyyy_0[i] = 8.0 * g_0_xxxzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyyyyyy_0[i] * pb_y + g_0_xxxzzz_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyyyyyz_0[i] = 7.0 * g_0_xxxzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyyyyyz_0[i] * pb_y + g_0_xxxzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyyyyzz_0[i] = 6.0 * g_0_xxxzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyyyyzz_0[i] * pb_y + g_0_xxxzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyyyzzz_0[i] = 5.0 * g_0_xxxzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyyyzzz_0[i] * pb_y + g_0_xxxzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxxzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyyzzzz_0[i] * pb_y + g_0_xxxzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyyzzzzz_0[i] = 3.0 * g_0_xxxzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyyzzzzz_0[i] * pb_y + g_0_xxxzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yyzzzzzz_0[i] = 2.0 * g_0_xxxzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yyzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_yzzzzzzz_0[i] = g_0_xxxzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxxzzz_0_yzzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_xxxyzzz_0_zzzzzzzz_0[i] = g_0_xxxzzz_0_zzzzzzzz_0[i] * pb_y + g_0_xxxzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 630-675 components of targeted buffer : SKSL

    auto g_0_xxxzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 630);

    auto g_0_xxxzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 631);

    auto g_0_xxxzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 632);

    auto g_0_xxxzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 633);

    auto g_0_xxxzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 634);

    auto g_0_xxxzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 635);

    auto g_0_xxxzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 636);

    auto g_0_xxxzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 637);

    auto g_0_xxxzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 638);

    auto g_0_xxxzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 639);

    auto g_0_xxxzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 640);

    auto g_0_xxxzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 641);

    auto g_0_xxxzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 642);

    auto g_0_xxxzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 643);

    auto g_0_xxxzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 644);

    auto g_0_xxxzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 645);

    auto g_0_xxxzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 646);

    auto g_0_xxxzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 647);

    auto g_0_xxxzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 648);

    auto g_0_xxxzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 649);

    auto g_0_xxxzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 650);

    auto g_0_xxxzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 651);

    auto g_0_xxxzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 652);

    auto g_0_xxxzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 653);

    auto g_0_xxxzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 654);

    auto g_0_xxxzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 655);

    auto g_0_xxxzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 656);

    auto g_0_xxxzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 657);

    auto g_0_xxxzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 658);

    auto g_0_xxxzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 659);

    auto g_0_xxxzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 660);

    auto g_0_xxxzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 661);

    auto g_0_xxxzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 662);

    auto g_0_xxxzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 663);

    auto g_0_xxxzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 664);

    auto g_0_xxxzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 665);

    auto g_0_xxxzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 666);

    auto g_0_xxxzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 667);

    auto g_0_xxxzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 668);

    auto g_0_xxxzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 669);

    auto g_0_xxxzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 670);

    auto g_0_xxxzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 671);

    auto g_0_xxxzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 672);

    auto g_0_xxxzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 673);

    auto g_0_xxxzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 674);

    #pragma omp simd aligned(g_0_xxxzz_0_xxxxxxxx_0, g_0_xxxzz_0_xxxxxxxx_1, g_0_xxxzz_0_xxxxxxxy_0, g_0_xxxzz_0_xxxxxxxy_1, g_0_xxxzz_0_xxxxxxyy_0, g_0_xxxzz_0_xxxxxxyy_1, g_0_xxxzz_0_xxxxxyyy_0, g_0_xxxzz_0_xxxxxyyy_1, g_0_xxxzz_0_xxxxyyyy_0, g_0_xxxzz_0_xxxxyyyy_1, g_0_xxxzz_0_xxxyyyyy_0, g_0_xxxzz_0_xxxyyyyy_1, g_0_xxxzz_0_xxyyyyyy_0, g_0_xxxzz_0_xxyyyyyy_1, g_0_xxxzz_0_xyyyyyyy_0, g_0_xxxzz_0_xyyyyyyy_1, g_0_xxxzzz_0_xxxxxxxx_0, g_0_xxxzzz_0_xxxxxxxx_1, g_0_xxxzzz_0_xxxxxxxy_0, g_0_xxxzzz_0_xxxxxxxy_1, g_0_xxxzzz_0_xxxxxxyy_0, g_0_xxxzzz_0_xxxxxxyy_1, g_0_xxxzzz_0_xxxxxyyy_0, g_0_xxxzzz_0_xxxxxyyy_1, g_0_xxxzzz_0_xxxxyyyy_0, g_0_xxxzzz_0_xxxxyyyy_1, g_0_xxxzzz_0_xxxyyyyy_0, g_0_xxxzzz_0_xxxyyyyy_1, g_0_xxxzzz_0_xxyyyyyy_0, g_0_xxxzzz_0_xxyyyyyy_1, g_0_xxxzzz_0_xyyyyyyy_0, g_0_xxxzzz_0_xyyyyyyy_1, g_0_xxxzzzz_0_xxxxxxxx_0, g_0_xxxzzzz_0_xxxxxxxy_0, g_0_xxxzzzz_0_xxxxxxxz_0, g_0_xxxzzzz_0_xxxxxxyy_0, g_0_xxxzzzz_0_xxxxxxyz_0, g_0_xxxzzzz_0_xxxxxxzz_0, g_0_xxxzzzz_0_xxxxxyyy_0, g_0_xxxzzzz_0_xxxxxyyz_0, g_0_xxxzzzz_0_xxxxxyzz_0, g_0_xxxzzzz_0_xxxxxzzz_0, g_0_xxxzzzz_0_xxxxyyyy_0, g_0_xxxzzzz_0_xxxxyyyz_0, g_0_xxxzzzz_0_xxxxyyzz_0, g_0_xxxzzzz_0_xxxxyzzz_0, g_0_xxxzzzz_0_xxxxzzzz_0, g_0_xxxzzzz_0_xxxyyyyy_0, g_0_xxxzzzz_0_xxxyyyyz_0, g_0_xxxzzzz_0_xxxyyyzz_0, g_0_xxxzzzz_0_xxxyyzzz_0, g_0_xxxzzzz_0_xxxyzzzz_0, g_0_xxxzzzz_0_xxxzzzzz_0, g_0_xxxzzzz_0_xxyyyyyy_0, g_0_xxxzzzz_0_xxyyyyyz_0, g_0_xxxzzzz_0_xxyyyyzz_0, g_0_xxxzzzz_0_xxyyyzzz_0, g_0_xxxzzzz_0_xxyyzzzz_0, g_0_xxxzzzz_0_xxyzzzzz_0, g_0_xxxzzzz_0_xxzzzzzz_0, g_0_xxxzzzz_0_xyyyyyyy_0, g_0_xxxzzzz_0_xyyyyyyz_0, g_0_xxxzzzz_0_xyyyyyzz_0, g_0_xxxzzzz_0_xyyyyzzz_0, g_0_xxxzzzz_0_xyyyzzzz_0, g_0_xxxzzzz_0_xyyzzzzz_0, g_0_xxxzzzz_0_xyzzzzzz_0, g_0_xxxzzzz_0_xzzzzzzz_0, g_0_xxxzzzz_0_yyyyyyyy_0, g_0_xxxzzzz_0_yyyyyyyz_0, g_0_xxxzzzz_0_yyyyyyzz_0, g_0_xxxzzzz_0_yyyyyzzz_0, g_0_xxxzzzz_0_yyyyzzzz_0, g_0_xxxzzzz_0_yyyzzzzz_0, g_0_xxxzzzz_0_yyzzzzzz_0, g_0_xxxzzzz_0_yzzzzzzz_0, g_0_xxxzzzz_0_zzzzzzzz_0, g_0_xxzzzz_0_xxxxxxxz_0, g_0_xxzzzz_0_xxxxxxxz_1, g_0_xxzzzz_0_xxxxxxyz_0, g_0_xxzzzz_0_xxxxxxyz_1, g_0_xxzzzz_0_xxxxxxz_1, g_0_xxzzzz_0_xxxxxxzz_0, g_0_xxzzzz_0_xxxxxxzz_1, g_0_xxzzzz_0_xxxxxyyz_0, g_0_xxzzzz_0_xxxxxyyz_1, g_0_xxzzzz_0_xxxxxyz_1, g_0_xxzzzz_0_xxxxxyzz_0, g_0_xxzzzz_0_xxxxxyzz_1, g_0_xxzzzz_0_xxxxxzz_1, g_0_xxzzzz_0_xxxxxzzz_0, g_0_xxzzzz_0_xxxxxzzz_1, g_0_xxzzzz_0_xxxxyyyz_0, g_0_xxzzzz_0_xxxxyyyz_1, g_0_xxzzzz_0_xxxxyyz_1, g_0_xxzzzz_0_xxxxyyzz_0, g_0_xxzzzz_0_xxxxyyzz_1, g_0_xxzzzz_0_xxxxyzz_1, g_0_xxzzzz_0_xxxxyzzz_0, g_0_xxzzzz_0_xxxxyzzz_1, g_0_xxzzzz_0_xxxxzzz_1, g_0_xxzzzz_0_xxxxzzzz_0, g_0_xxzzzz_0_xxxxzzzz_1, g_0_xxzzzz_0_xxxyyyyz_0, g_0_xxzzzz_0_xxxyyyyz_1, g_0_xxzzzz_0_xxxyyyz_1, g_0_xxzzzz_0_xxxyyyzz_0, g_0_xxzzzz_0_xxxyyyzz_1, g_0_xxzzzz_0_xxxyyzz_1, g_0_xxzzzz_0_xxxyyzzz_0, g_0_xxzzzz_0_xxxyyzzz_1, g_0_xxzzzz_0_xxxyzzz_1, g_0_xxzzzz_0_xxxyzzzz_0, g_0_xxzzzz_0_xxxyzzzz_1, g_0_xxzzzz_0_xxxzzzz_1, g_0_xxzzzz_0_xxxzzzzz_0, g_0_xxzzzz_0_xxxzzzzz_1, g_0_xxzzzz_0_xxyyyyyz_0, g_0_xxzzzz_0_xxyyyyyz_1, g_0_xxzzzz_0_xxyyyyz_1, g_0_xxzzzz_0_xxyyyyzz_0, g_0_xxzzzz_0_xxyyyyzz_1, g_0_xxzzzz_0_xxyyyzz_1, g_0_xxzzzz_0_xxyyyzzz_0, g_0_xxzzzz_0_xxyyyzzz_1, g_0_xxzzzz_0_xxyyzzz_1, g_0_xxzzzz_0_xxyyzzzz_0, g_0_xxzzzz_0_xxyyzzzz_1, g_0_xxzzzz_0_xxyzzzz_1, g_0_xxzzzz_0_xxyzzzzz_0, g_0_xxzzzz_0_xxyzzzzz_1, g_0_xxzzzz_0_xxzzzzz_1, g_0_xxzzzz_0_xxzzzzzz_0, g_0_xxzzzz_0_xxzzzzzz_1, g_0_xxzzzz_0_xyyyyyyz_0, g_0_xxzzzz_0_xyyyyyyz_1, g_0_xxzzzz_0_xyyyyyz_1, g_0_xxzzzz_0_xyyyyyzz_0, g_0_xxzzzz_0_xyyyyyzz_1, g_0_xxzzzz_0_xyyyyzz_1, g_0_xxzzzz_0_xyyyyzzz_0, g_0_xxzzzz_0_xyyyyzzz_1, g_0_xxzzzz_0_xyyyzzz_1, g_0_xxzzzz_0_xyyyzzzz_0, g_0_xxzzzz_0_xyyyzzzz_1, g_0_xxzzzz_0_xyyzzzz_1, g_0_xxzzzz_0_xyyzzzzz_0, g_0_xxzzzz_0_xyyzzzzz_1, g_0_xxzzzz_0_xyzzzzz_1, g_0_xxzzzz_0_xyzzzzzz_0, g_0_xxzzzz_0_xyzzzzzz_1, g_0_xxzzzz_0_xzzzzzz_1, g_0_xxzzzz_0_xzzzzzzz_0, g_0_xxzzzz_0_xzzzzzzz_1, g_0_xxzzzz_0_yyyyyyyy_0, g_0_xxzzzz_0_yyyyyyyy_1, g_0_xxzzzz_0_yyyyyyyz_0, g_0_xxzzzz_0_yyyyyyyz_1, g_0_xxzzzz_0_yyyyyyz_1, g_0_xxzzzz_0_yyyyyyzz_0, g_0_xxzzzz_0_yyyyyyzz_1, g_0_xxzzzz_0_yyyyyzz_1, g_0_xxzzzz_0_yyyyyzzz_0, g_0_xxzzzz_0_yyyyyzzz_1, g_0_xxzzzz_0_yyyyzzz_1, g_0_xxzzzz_0_yyyyzzzz_0, g_0_xxzzzz_0_yyyyzzzz_1, g_0_xxzzzz_0_yyyzzzz_1, g_0_xxzzzz_0_yyyzzzzz_0, g_0_xxzzzz_0_yyyzzzzz_1, g_0_xxzzzz_0_yyzzzzz_1, g_0_xxzzzz_0_yyzzzzzz_0, g_0_xxzzzz_0_yyzzzzzz_1, g_0_xxzzzz_0_yzzzzzz_1, g_0_xxzzzz_0_yzzzzzzz_0, g_0_xxzzzz_0_yzzzzzzz_1, g_0_xxzzzz_0_zzzzzzz_1, g_0_xxzzzz_0_zzzzzzzz_0, g_0_xxzzzz_0_zzzzzzzz_1, g_0_xzzzz_0_xxxxxxxz_0, g_0_xzzzz_0_xxxxxxxz_1, g_0_xzzzz_0_xxxxxxyz_0, g_0_xzzzz_0_xxxxxxyz_1, g_0_xzzzz_0_xxxxxxzz_0, g_0_xzzzz_0_xxxxxxzz_1, g_0_xzzzz_0_xxxxxyyz_0, g_0_xzzzz_0_xxxxxyyz_1, g_0_xzzzz_0_xxxxxyzz_0, g_0_xzzzz_0_xxxxxyzz_1, g_0_xzzzz_0_xxxxxzzz_0, g_0_xzzzz_0_xxxxxzzz_1, g_0_xzzzz_0_xxxxyyyz_0, g_0_xzzzz_0_xxxxyyyz_1, g_0_xzzzz_0_xxxxyyzz_0, g_0_xzzzz_0_xxxxyyzz_1, g_0_xzzzz_0_xxxxyzzz_0, g_0_xzzzz_0_xxxxyzzz_1, g_0_xzzzz_0_xxxxzzzz_0, g_0_xzzzz_0_xxxxzzzz_1, g_0_xzzzz_0_xxxyyyyz_0, g_0_xzzzz_0_xxxyyyyz_1, g_0_xzzzz_0_xxxyyyzz_0, g_0_xzzzz_0_xxxyyyzz_1, g_0_xzzzz_0_xxxyyzzz_0, g_0_xzzzz_0_xxxyyzzz_1, g_0_xzzzz_0_xxxyzzzz_0, g_0_xzzzz_0_xxxyzzzz_1, g_0_xzzzz_0_xxxzzzzz_0, g_0_xzzzz_0_xxxzzzzz_1, g_0_xzzzz_0_xxyyyyyz_0, g_0_xzzzz_0_xxyyyyyz_1, g_0_xzzzz_0_xxyyyyzz_0, g_0_xzzzz_0_xxyyyyzz_1, g_0_xzzzz_0_xxyyyzzz_0, g_0_xzzzz_0_xxyyyzzz_1, g_0_xzzzz_0_xxyyzzzz_0, g_0_xzzzz_0_xxyyzzzz_1, g_0_xzzzz_0_xxyzzzzz_0, g_0_xzzzz_0_xxyzzzzz_1, g_0_xzzzz_0_xxzzzzzz_0, g_0_xzzzz_0_xxzzzzzz_1, g_0_xzzzz_0_xyyyyyyz_0, g_0_xzzzz_0_xyyyyyyz_1, g_0_xzzzz_0_xyyyyyzz_0, g_0_xzzzz_0_xyyyyyzz_1, g_0_xzzzz_0_xyyyyzzz_0, g_0_xzzzz_0_xyyyyzzz_1, g_0_xzzzz_0_xyyyzzzz_0, g_0_xzzzz_0_xyyyzzzz_1, g_0_xzzzz_0_xyyzzzzz_0, g_0_xzzzz_0_xyyzzzzz_1, g_0_xzzzz_0_xyzzzzzz_0, g_0_xzzzz_0_xyzzzzzz_1, g_0_xzzzz_0_xzzzzzzz_0, g_0_xzzzz_0_xzzzzzzz_1, g_0_xzzzz_0_yyyyyyyy_0, g_0_xzzzz_0_yyyyyyyy_1, g_0_xzzzz_0_yyyyyyyz_0, g_0_xzzzz_0_yyyyyyyz_1, g_0_xzzzz_0_yyyyyyzz_0, g_0_xzzzz_0_yyyyyyzz_1, g_0_xzzzz_0_yyyyyzzz_0, g_0_xzzzz_0_yyyyyzzz_1, g_0_xzzzz_0_yyyyzzzz_0, g_0_xzzzz_0_yyyyzzzz_1, g_0_xzzzz_0_yyyzzzzz_0, g_0_xzzzz_0_yyyzzzzz_1, g_0_xzzzz_0_yyzzzzzz_0, g_0_xzzzz_0_yyzzzzzz_1, g_0_xzzzz_0_yzzzzzzz_0, g_0_xzzzz_0_yzzzzzzz_1, g_0_xzzzz_0_zzzzzzzz_0, g_0_xzzzz_0_zzzzzzzz_1, wp_x, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxxzzzz_0_xxxxxxxx_0[i] = 3.0 * g_0_xxxzz_0_xxxxxxxx_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxxxxxx_0[i] * pb_z + g_0_xxxzzz_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxxxxxy_0[i] = 3.0 * g_0_xxxzz_0_xxxxxxxy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxxxxxy_0[i] * pb_z + g_0_xxxzzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxxxxxz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxxxz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxxxz_1[i] * fti_ab_0 + 7.0 * g_0_xxzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxxz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxxxyy_0[i] = 3.0 * g_0_xxxzz_0_xxxxxxyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxxxxyy_0[i] * pb_z + g_0_xxxzzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxxxxyz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxxyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xxzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxyz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxxxzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxxzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxxzz_1[i] * fti_ab_0 + 6.0 * g_0_xxzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxxyyy_0[i] = 3.0 * g_0_xxxzz_0_xxxxxyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxxxyyy_0[i] * pb_z + g_0_xxxzzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxxxyyz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xxzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxyyz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxxyzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xxzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxyzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxxzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxxzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxxzzz_1[i] * fti_ab_0 + 5.0 * g_0_xxzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxyyyy_0[i] = 3.0 * g_0_xxxzz_0_xxxxyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxxyyyy_0[i] * pb_z + g_0_xxxzzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxxyyyz_0[i] = 2.0 * g_0_xzzzz_0_xxxxyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xxzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyyyz_0[i] * pb_x + g_0_xxzzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxyyzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xxzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyyzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxyzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxxzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxxzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_xxzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_xxxzz_0_xxxyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxxyyyyy_0[i] * pb_z + g_0_xxxzzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxxyyyyz_0[i] = 2.0 * g_0_xzzzz_0_xxxyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xxzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyyyz_0[i] * pb_x + g_0_xxzzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxyyyzz_0[i] = 2.0 * g_0_xzzzz_0_xxxyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xxzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyyzz_0[i] * pb_x + g_0_xxzzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxyyzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxyzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxxzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxxzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxxzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xxzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxyyyyyy_0[i] = 3.0 * g_0_xxxzz_0_xxyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xxyyyyyy_0[i] * pb_z + g_0_xxxzzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_xzzzz_0_xxyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyyyz_0[i] * pb_x + g_0_xxzzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_xzzzz_0_xxyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyyzz_0[i] * pb_x + g_0_xxzzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_xzzzz_0_xxyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyzzz_0[i] * pb_x + g_0_xxzzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xxzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xxzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xxzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xxzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyyyyyyy_0[i] = 3.0 * g_0_xxxzz_0_xyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_xxxzz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxxzzz_0_xyyyyyyy_0[i] * pb_z + g_0_xxxzzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxxzzzz_0_xyyyyyyz_0[i] = 2.0 * g_0_xzzzz_0_xyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyyyz_0[i] * pb_x + g_0_xxzzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyyyyyzz_0[i] = 2.0 * g_0_xzzzz_0_xyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyyzz_0[i] * pb_x + g_0_xxzzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyyyyzzz_0[i] = 2.0 * g_0_xzzzz_0_xyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyzzz_0[i] * pb_x + g_0_xxzzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyyyzzzz_0[i] = 2.0 * g_0_xzzzz_0_xyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyzzzz_0[i] * pb_x + g_0_xxzzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyyzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xyzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_xzzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_xzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xzzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyyyyyy_0[i] = 2.0 * g_0_xzzzz_0_yyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyyyy_0[i] * pb_x + g_0_xxzzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyyyyyz_0[i] = 2.0 * g_0_xzzzz_0_yyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyyyz_0[i] * pb_x + g_0_xxzzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyyyyzz_0[i] = 2.0 * g_0_xzzzz_0_yyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyyzz_0[i] * pb_x + g_0_xxzzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyyyzzz_0[i] = 2.0 * g_0_xzzzz_0_yyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyyzzz_0[i] * pb_x + g_0_xxzzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyyzzzz_0[i] = 2.0 * g_0_xzzzz_0_yyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyyzzzz_0[i] * pb_x + g_0_xxzzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyyzzzzz_0[i] = 2.0 * g_0_xzzzz_0_yyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyyzzzzz_0[i] * pb_x + g_0_xxzzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yyzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_yyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yyzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_yzzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_yzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_yzzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxxzzzz_0_zzzzzzzz_0[i] = 2.0 * g_0_xzzzz_0_zzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xzzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xxzzzz_0_zzzzzzzz_0[i] * pb_x + g_0_xxzzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 675-720 components of targeted buffer : SKSL

    auto g_0_xxyyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 675);

    auto g_0_xxyyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 676);

    auto g_0_xxyyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 677);

    auto g_0_xxyyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 678);

    auto g_0_xxyyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 679);

    auto g_0_xxyyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 680);

    auto g_0_xxyyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 681);

    auto g_0_xxyyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 682);

    auto g_0_xxyyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 683);

    auto g_0_xxyyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 684);

    auto g_0_xxyyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 685);

    auto g_0_xxyyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 686);

    auto g_0_xxyyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 687);

    auto g_0_xxyyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 688);

    auto g_0_xxyyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 689);

    auto g_0_xxyyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 690);

    auto g_0_xxyyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 691);

    auto g_0_xxyyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 692);

    auto g_0_xxyyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 693);

    auto g_0_xxyyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 694);

    auto g_0_xxyyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 695);

    auto g_0_xxyyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 696);

    auto g_0_xxyyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 697);

    auto g_0_xxyyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 698);

    auto g_0_xxyyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 699);

    auto g_0_xxyyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 700);

    auto g_0_xxyyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 701);

    auto g_0_xxyyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 702);

    auto g_0_xxyyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 703);

    auto g_0_xxyyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 704);

    auto g_0_xxyyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 705);

    auto g_0_xxyyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 706);

    auto g_0_xxyyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 707);

    auto g_0_xxyyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 708);

    auto g_0_xxyyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 709);

    auto g_0_xxyyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 710);

    auto g_0_xxyyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 711);

    auto g_0_xxyyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 712);

    auto g_0_xxyyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 713);

    auto g_0_xxyyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 714);

    auto g_0_xxyyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 715);

    auto g_0_xxyyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 716);

    auto g_0_xxyyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 717);

    auto g_0_xxyyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 718);

    auto g_0_xxyyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 719);

    #pragma omp simd aligned(g_0_xxyyy_0_xxxxxxxx_0, g_0_xxyyy_0_xxxxxxxx_1, g_0_xxyyy_0_xxxxxxxz_0, g_0_xxyyy_0_xxxxxxxz_1, g_0_xxyyy_0_xxxxxxzz_0, g_0_xxyyy_0_xxxxxxzz_1, g_0_xxyyy_0_xxxxxzzz_0, g_0_xxyyy_0_xxxxxzzz_1, g_0_xxyyy_0_xxxxzzzz_0, g_0_xxyyy_0_xxxxzzzz_1, g_0_xxyyy_0_xxxzzzzz_0, g_0_xxyyy_0_xxxzzzzz_1, g_0_xxyyy_0_xxzzzzzz_0, g_0_xxyyy_0_xxzzzzzz_1, g_0_xxyyy_0_xzzzzzzz_0, g_0_xxyyy_0_xzzzzzzz_1, g_0_xxyyyy_0_xxxxxxxx_0, g_0_xxyyyy_0_xxxxxxxx_1, g_0_xxyyyy_0_xxxxxxxz_0, g_0_xxyyyy_0_xxxxxxxz_1, g_0_xxyyyy_0_xxxxxxzz_0, g_0_xxyyyy_0_xxxxxxzz_1, g_0_xxyyyy_0_xxxxxzzz_0, g_0_xxyyyy_0_xxxxxzzz_1, g_0_xxyyyy_0_xxxxzzzz_0, g_0_xxyyyy_0_xxxxzzzz_1, g_0_xxyyyy_0_xxxzzzzz_0, g_0_xxyyyy_0_xxxzzzzz_1, g_0_xxyyyy_0_xxzzzzzz_0, g_0_xxyyyy_0_xxzzzzzz_1, g_0_xxyyyy_0_xzzzzzzz_0, g_0_xxyyyy_0_xzzzzzzz_1, g_0_xxyyyyy_0_xxxxxxxx_0, g_0_xxyyyyy_0_xxxxxxxy_0, g_0_xxyyyyy_0_xxxxxxxz_0, g_0_xxyyyyy_0_xxxxxxyy_0, g_0_xxyyyyy_0_xxxxxxyz_0, g_0_xxyyyyy_0_xxxxxxzz_0, g_0_xxyyyyy_0_xxxxxyyy_0, g_0_xxyyyyy_0_xxxxxyyz_0, g_0_xxyyyyy_0_xxxxxyzz_0, g_0_xxyyyyy_0_xxxxxzzz_0, g_0_xxyyyyy_0_xxxxyyyy_0, g_0_xxyyyyy_0_xxxxyyyz_0, g_0_xxyyyyy_0_xxxxyyzz_0, g_0_xxyyyyy_0_xxxxyzzz_0, g_0_xxyyyyy_0_xxxxzzzz_0, g_0_xxyyyyy_0_xxxyyyyy_0, g_0_xxyyyyy_0_xxxyyyyz_0, g_0_xxyyyyy_0_xxxyyyzz_0, g_0_xxyyyyy_0_xxxyyzzz_0, g_0_xxyyyyy_0_xxxyzzzz_0, g_0_xxyyyyy_0_xxxzzzzz_0, g_0_xxyyyyy_0_xxyyyyyy_0, g_0_xxyyyyy_0_xxyyyyyz_0, g_0_xxyyyyy_0_xxyyyyzz_0, g_0_xxyyyyy_0_xxyyyzzz_0, g_0_xxyyyyy_0_xxyyzzzz_0, g_0_xxyyyyy_0_xxyzzzzz_0, g_0_xxyyyyy_0_xxzzzzzz_0, g_0_xxyyyyy_0_xyyyyyyy_0, g_0_xxyyyyy_0_xyyyyyyz_0, g_0_xxyyyyy_0_xyyyyyzz_0, g_0_xxyyyyy_0_xyyyyzzz_0, g_0_xxyyyyy_0_xyyyzzzz_0, g_0_xxyyyyy_0_xyyzzzzz_0, g_0_xxyyyyy_0_xyzzzzzz_0, g_0_xxyyyyy_0_xzzzzzzz_0, g_0_xxyyyyy_0_yyyyyyyy_0, g_0_xxyyyyy_0_yyyyyyyz_0, g_0_xxyyyyy_0_yyyyyyzz_0, g_0_xxyyyyy_0_yyyyyzzz_0, g_0_xxyyyyy_0_yyyyzzzz_0, g_0_xxyyyyy_0_yyyzzzzz_0, g_0_xxyyyyy_0_yyzzzzzz_0, g_0_xxyyyyy_0_yzzzzzzz_0, g_0_xxyyyyy_0_zzzzzzzz_0, g_0_xyyyyy_0_xxxxxxxy_0, g_0_xyyyyy_0_xxxxxxxy_1, g_0_xyyyyy_0_xxxxxxy_1, g_0_xyyyyy_0_xxxxxxyy_0, g_0_xyyyyy_0_xxxxxxyy_1, g_0_xyyyyy_0_xxxxxxyz_0, g_0_xyyyyy_0_xxxxxxyz_1, g_0_xyyyyy_0_xxxxxyy_1, g_0_xyyyyy_0_xxxxxyyy_0, g_0_xyyyyy_0_xxxxxyyy_1, g_0_xyyyyy_0_xxxxxyyz_0, g_0_xyyyyy_0_xxxxxyyz_1, g_0_xyyyyy_0_xxxxxyz_1, g_0_xyyyyy_0_xxxxxyzz_0, g_0_xyyyyy_0_xxxxxyzz_1, g_0_xyyyyy_0_xxxxyyy_1, g_0_xyyyyy_0_xxxxyyyy_0, g_0_xyyyyy_0_xxxxyyyy_1, g_0_xyyyyy_0_xxxxyyyz_0, g_0_xyyyyy_0_xxxxyyyz_1, g_0_xyyyyy_0_xxxxyyz_1, g_0_xyyyyy_0_xxxxyyzz_0, g_0_xyyyyy_0_xxxxyyzz_1, g_0_xyyyyy_0_xxxxyzz_1, g_0_xyyyyy_0_xxxxyzzz_0, g_0_xyyyyy_0_xxxxyzzz_1, g_0_xyyyyy_0_xxxyyyy_1, g_0_xyyyyy_0_xxxyyyyy_0, g_0_xyyyyy_0_xxxyyyyy_1, g_0_xyyyyy_0_xxxyyyyz_0, g_0_xyyyyy_0_xxxyyyyz_1, g_0_xyyyyy_0_xxxyyyz_1, g_0_xyyyyy_0_xxxyyyzz_0, g_0_xyyyyy_0_xxxyyyzz_1, g_0_xyyyyy_0_xxxyyzz_1, g_0_xyyyyy_0_xxxyyzzz_0, g_0_xyyyyy_0_xxxyyzzz_1, g_0_xyyyyy_0_xxxyzzz_1, g_0_xyyyyy_0_xxxyzzzz_0, g_0_xyyyyy_0_xxxyzzzz_1, g_0_xyyyyy_0_xxyyyyy_1, g_0_xyyyyy_0_xxyyyyyy_0, g_0_xyyyyy_0_xxyyyyyy_1, g_0_xyyyyy_0_xxyyyyyz_0, g_0_xyyyyy_0_xxyyyyyz_1, g_0_xyyyyy_0_xxyyyyz_1, g_0_xyyyyy_0_xxyyyyzz_0, g_0_xyyyyy_0_xxyyyyzz_1, g_0_xyyyyy_0_xxyyyzz_1, g_0_xyyyyy_0_xxyyyzzz_0, g_0_xyyyyy_0_xxyyyzzz_1, g_0_xyyyyy_0_xxyyzzz_1, g_0_xyyyyy_0_xxyyzzzz_0, g_0_xyyyyy_0_xxyyzzzz_1, g_0_xyyyyy_0_xxyzzzz_1, g_0_xyyyyy_0_xxyzzzzz_0, g_0_xyyyyy_0_xxyzzzzz_1, g_0_xyyyyy_0_xyyyyyy_1, g_0_xyyyyy_0_xyyyyyyy_0, g_0_xyyyyy_0_xyyyyyyy_1, g_0_xyyyyy_0_xyyyyyyz_0, g_0_xyyyyy_0_xyyyyyyz_1, g_0_xyyyyy_0_xyyyyyz_1, g_0_xyyyyy_0_xyyyyyzz_0, g_0_xyyyyy_0_xyyyyyzz_1, g_0_xyyyyy_0_xyyyyzz_1, g_0_xyyyyy_0_xyyyyzzz_0, g_0_xyyyyy_0_xyyyyzzz_1, g_0_xyyyyy_0_xyyyzzz_1, g_0_xyyyyy_0_xyyyzzzz_0, g_0_xyyyyy_0_xyyyzzzz_1, g_0_xyyyyy_0_xyyzzzz_1, g_0_xyyyyy_0_xyyzzzzz_0, g_0_xyyyyy_0_xyyzzzzz_1, g_0_xyyyyy_0_xyzzzzz_1, g_0_xyyyyy_0_xyzzzzzz_0, g_0_xyyyyy_0_xyzzzzzz_1, g_0_xyyyyy_0_yyyyyyy_1, g_0_xyyyyy_0_yyyyyyyy_0, g_0_xyyyyy_0_yyyyyyyy_1, g_0_xyyyyy_0_yyyyyyyz_0, g_0_xyyyyy_0_yyyyyyyz_1, g_0_xyyyyy_0_yyyyyyz_1, g_0_xyyyyy_0_yyyyyyzz_0, g_0_xyyyyy_0_yyyyyyzz_1, g_0_xyyyyy_0_yyyyyzz_1, g_0_xyyyyy_0_yyyyyzzz_0, g_0_xyyyyy_0_yyyyyzzz_1, g_0_xyyyyy_0_yyyyzzz_1, g_0_xyyyyy_0_yyyyzzzz_0, g_0_xyyyyy_0_yyyyzzzz_1, g_0_xyyyyy_0_yyyzzzz_1, g_0_xyyyyy_0_yyyzzzzz_0, g_0_xyyyyy_0_yyyzzzzz_1, g_0_xyyyyy_0_yyzzzzz_1, g_0_xyyyyy_0_yyzzzzzz_0, g_0_xyyyyy_0_yyzzzzzz_1, g_0_xyyyyy_0_yzzzzzz_1, g_0_xyyyyy_0_yzzzzzzz_0, g_0_xyyyyy_0_yzzzzzzz_1, g_0_xyyyyy_0_zzzzzzzz_0, g_0_xyyyyy_0_zzzzzzzz_1, g_0_yyyyy_0_xxxxxxxy_0, g_0_yyyyy_0_xxxxxxxy_1, g_0_yyyyy_0_xxxxxxyy_0, g_0_yyyyy_0_xxxxxxyy_1, g_0_yyyyy_0_xxxxxxyz_0, g_0_yyyyy_0_xxxxxxyz_1, g_0_yyyyy_0_xxxxxyyy_0, g_0_yyyyy_0_xxxxxyyy_1, g_0_yyyyy_0_xxxxxyyz_0, g_0_yyyyy_0_xxxxxyyz_1, g_0_yyyyy_0_xxxxxyzz_0, g_0_yyyyy_0_xxxxxyzz_1, g_0_yyyyy_0_xxxxyyyy_0, g_0_yyyyy_0_xxxxyyyy_1, g_0_yyyyy_0_xxxxyyyz_0, g_0_yyyyy_0_xxxxyyyz_1, g_0_yyyyy_0_xxxxyyzz_0, g_0_yyyyy_0_xxxxyyzz_1, g_0_yyyyy_0_xxxxyzzz_0, g_0_yyyyy_0_xxxxyzzz_1, g_0_yyyyy_0_xxxyyyyy_0, g_0_yyyyy_0_xxxyyyyy_1, g_0_yyyyy_0_xxxyyyyz_0, g_0_yyyyy_0_xxxyyyyz_1, g_0_yyyyy_0_xxxyyyzz_0, g_0_yyyyy_0_xxxyyyzz_1, g_0_yyyyy_0_xxxyyzzz_0, g_0_yyyyy_0_xxxyyzzz_1, g_0_yyyyy_0_xxxyzzzz_0, g_0_yyyyy_0_xxxyzzzz_1, g_0_yyyyy_0_xxyyyyyy_0, g_0_yyyyy_0_xxyyyyyy_1, g_0_yyyyy_0_xxyyyyyz_0, g_0_yyyyy_0_xxyyyyyz_1, g_0_yyyyy_0_xxyyyyzz_0, g_0_yyyyy_0_xxyyyyzz_1, g_0_yyyyy_0_xxyyyzzz_0, g_0_yyyyy_0_xxyyyzzz_1, g_0_yyyyy_0_xxyyzzzz_0, g_0_yyyyy_0_xxyyzzzz_1, g_0_yyyyy_0_xxyzzzzz_0, g_0_yyyyy_0_xxyzzzzz_1, g_0_yyyyy_0_xyyyyyyy_0, g_0_yyyyy_0_xyyyyyyy_1, g_0_yyyyy_0_xyyyyyyz_0, g_0_yyyyy_0_xyyyyyyz_1, g_0_yyyyy_0_xyyyyyzz_0, g_0_yyyyy_0_xyyyyyzz_1, g_0_yyyyy_0_xyyyyzzz_0, g_0_yyyyy_0_xyyyyzzz_1, g_0_yyyyy_0_xyyyzzzz_0, g_0_yyyyy_0_xyyyzzzz_1, g_0_yyyyy_0_xyyzzzzz_0, g_0_yyyyy_0_xyyzzzzz_1, g_0_yyyyy_0_xyzzzzzz_0, g_0_yyyyy_0_xyzzzzzz_1, g_0_yyyyy_0_yyyyyyyy_0, g_0_yyyyy_0_yyyyyyyy_1, g_0_yyyyy_0_yyyyyyyz_0, g_0_yyyyy_0_yyyyyyyz_1, g_0_yyyyy_0_yyyyyyzz_0, g_0_yyyyy_0_yyyyyyzz_1, g_0_yyyyy_0_yyyyyzzz_0, g_0_yyyyy_0_yyyyyzzz_1, g_0_yyyyy_0_yyyyzzzz_0, g_0_yyyyy_0_yyyyzzzz_1, g_0_yyyyy_0_yyyzzzzz_0, g_0_yyyyy_0_yyyzzzzz_1, g_0_yyyyy_0_yyzzzzzz_0, g_0_yyyyy_0_yyzzzzzz_1, g_0_yyyyy_0_yzzzzzzz_0, g_0_yyyyy_0_yzzzzzzz_1, g_0_yyyyy_0_zzzzzzzz_0, g_0_yyyyy_0_zzzzzzzz_1, wp_x, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxyyyyy_0_xxxxxxxx_0[i] = 4.0 * g_0_xxyyy_0_xxxxxxxx_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxxxxxx_0[i] * pb_y + g_0_xxyyyy_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxxxxxxy_0[i] = g_0_yyyyy_0_xxxxxxxy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxxxy_1[i] * fti_ab_0 + 7.0 * g_0_xyyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxxxy_0[i] * pb_x + g_0_xyyyyy_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxxxz_0[i] = 4.0 * g_0_xxyyy_0_xxxxxxxz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxxxxxz_0[i] * pb_y + g_0_xxyyyy_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxxxxxyy_0[i] = g_0_yyyyy_0_xxxxxxyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxxyy_1[i] * fti_ab_0 + 6.0 * g_0_xyyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxxyy_0[i] * pb_x + g_0_xyyyyy_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxxyz_0[i] = g_0_yyyyy_0_xxxxxxyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xyyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxxyz_0[i] * pb_x + g_0_xyyyyy_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxxzz_0[i] = 4.0 * g_0_xxyyy_0_xxxxxxzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxxxxzz_0[i] * pb_y + g_0_xxyyyy_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxxxxyyy_0[i] = g_0_yyyyy_0_xxxxxyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxyyy_1[i] * fti_ab_0 + 5.0 * g_0_xyyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxyyy_0[i] * pb_x + g_0_xyyyyy_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxyyz_0[i] = g_0_yyyyy_0_xxxxxyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xyyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxyyz_0[i] * pb_x + g_0_xyyyyy_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxyzz_0[i] = g_0_yyyyy_0_xxxxxyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xyyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxxyzz_0[i] * pb_x + g_0_xyyyyy_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxxzzz_0[i] = 4.0 * g_0_xxyyy_0_xxxxxzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxxxzzz_0[i] * pb_y + g_0_xxyyyy_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxxxyyyy_0[i] = g_0_yyyyy_0_xxxxyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_xyyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxyyyy_0[i] * pb_x + g_0_xyyyyy_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxyyyz_0[i] = g_0_yyyyy_0_xxxxyyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxyyyz_0[i] * pb_x + g_0_xyyyyy_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxyyzz_0[i] = g_0_yyyyy_0_xxxxyyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxyyzz_0[i] * pb_x + g_0_xyyyyy_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxyzzz_0[i] = g_0_yyyyy_0_xxxxyzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxxyzzz_0[i] * pb_x + g_0_xyyyyy_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxxzzzz_0[i] = 4.0 * g_0_xxyyy_0_xxxxzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxxzzzz_0[i] * pb_y + g_0_xxyyyy_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxxyyyyy_0[i] = g_0_yyyyy_0_xxxyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyyyyy_1[i] * fti_ab_0 + 3.0 * g_0_xyyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxyyyyy_0[i] * pb_x + g_0_xyyyyy_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxyyyyz_0[i] = g_0_yyyyy_0_xxxyyyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxyyyyz_0[i] * pb_x + g_0_xyyyyy_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxyyyzz_0[i] = g_0_yyyyy_0_xxxyyyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxyyyzz_0[i] * pb_x + g_0_xyyyyy_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxyyzzz_0[i] = g_0_yyyyy_0_xxxyyzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxyyzzz_0[i] * pb_x + g_0_xyyyyy_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxyzzzz_0[i] = g_0_yyyyy_0_xxxyzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxxyzzzz_0[i] * pb_x + g_0_xyyyyy_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxxzzzzz_0[i] = 4.0 * g_0_xxyyy_0_xxxzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxxzzzzz_0[i] * pb_y + g_0_xxyyyy_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xxyyyyyy_0[i] = g_0_yyyyy_0_xxyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyyyyy_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyyyyyy_0[i] * pb_x + g_0_xyyyyy_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxyyyyyz_0[i] = g_0_yyyyy_0_xxyyyyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyyyyyz_0[i] * pb_x + g_0_xyyyyy_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxyyyyzz_0[i] = g_0_yyyyy_0_xxyyyyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyyyyzz_0[i] * pb_x + g_0_xyyyyy_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxyyyzzz_0[i] = g_0_yyyyy_0_xxyyyzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyyyzzz_0[i] * pb_x + g_0_xyyyyy_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxyyzzzz_0[i] = g_0_yyyyy_0_xxyyzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyyzzzz_0[i] * pb_x + g_0_xyyyyy_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxyzzzzz_0[i] = g_0_yyyyy_0_xxyzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xxyzzzzz_0[i] * pb_x + g_0_xyyyyy_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xxzzzzzz_0[i] = 4.0 * g_0_xxyyy_0_xxzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xxzzzzzz_0[i] * pb_y + g_0_xxyyyy_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_xyyyyyyy_0[i] = g_0_yyyyy_0_xyyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyyyyyy_0[i] * pb_x + g_0_xyyyyy_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyyyyyyz_0[i] = g_0_yyyyy_0_xyyyyyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyyyyyz_0[i] * pb_x + g_0_xyyyyy_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyyyyyzz_0[i] = g_0_yyyyy_0_xyyyyyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyyyyzz_0[i] * pb_x + g_0_xyyyyy_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyyyyzzz_0[i] = g_0_yyyyy_0_xyyyyzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyyyzzz_0[i] * pb_x + g_0_xyyyyy_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyyyzzzz_0[i] = g_0_yyyyy_0_xyyyzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyyzzzz_0[i] * pb_x + g_0_xyyyyy_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyyzzzzz_0[i] = g_0_yyyyy_0_xyyzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyyzzzzz_0[i] * pb_x + g_0_xyyyyy_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xyzzzzzz_0[i] = g_0_yyyyy_0_xyzzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xyyyyy_0_xyzzzzzz_0[i] * pb_x + g_0_xyyyyy_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_xzzzzzzz_0[i] = 4.0 * g_0_xxyyy_0_xzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_xxyyy_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyyy_0_xzzzzzzz_0[i] * pb_y + g_0_xxyyyy_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxyyyyy_0_yyyyyyyy_0[i] = g_0_yyyyy_0_yyyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyyyy_0[i] * pb_x + g_0_xyyyyy_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyyyyyyz_0[i] = g_0_yyyyy_0_yyyyyyyz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyyyz_0[i] * pb_x + g_0_xyyyyy_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyyyyyzz_0[i] = g_0_yyyyy_0_yyyyyyzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyyzz_0[i] * pb_x + g_0_xyyyyy_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyyyyzzz_0[i] = g_0_yyyyy_0_yyyyyzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyyzzz_0[i] * pb_x + g_0_xyyyyy_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyyyzzzz_0[i] = g_0_yyyyy_0_yyyyzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyyzzzz_0[i] * pb_x + g_0_xyyyyy_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyyzzzzz_0[i] = g_0_yyyyy_0_yyyzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyyzzzzz_0[i] * pb_x + g_0_xyyyyy_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yyzzzzzz_0[i] = g_0_yyyyy_0_yyzzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yyzzzzzz_0[i] * pb_x + g_0_xyyyyy_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_yzzzzzzz_0[i] = g_0_yyyyy_0_yzzzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_yzzzzzzz_0[i] * pb_x + g_0_xyyyyy_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyyy_0_zzzzzzzz_0[i] = g_0_yyyyy_0_zzzzzzzz_0[i] * fi_ab_0 - g_0_yyyyy_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xyyyyy_0_zzzzzzzz_0[i] * pb_x + g_0_xyyyyy_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 720-765 components of targeted buffer : SKSL

    auto g_0_xxyyyyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 720);

    auto g_0_xxyyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 721);

    auto g_0_xxyyyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 722);

    auto g_0_xxyyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 723);

    auto g_0_xxyyyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 724);

    auto g_0_xxyyyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 725);

    auto g_0_xxyyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 726);

    auto g_0_xxyyyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 727);

    auto g_0_xxyyyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 728);

    auto g_0_xxyyyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 729);

    auto g_0_xxyyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 730);

    auto g_0_xxyyyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 731);

    auto g_0_xxyyyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 732);

    auto g_0_xxyyyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 733);

    auto g_0_xxyyyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 734);

    auto g_0_xxyyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 735);

    auto g_0_xxyyyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 736);

    auto g_0_xxyyyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 737);

    auto g_0_xxyyyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 738);

    auto g_0_xxyyyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 739);

    auto g_0_xxyyyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 740);

    auto g_0_xxyyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 741);

    auto g_0_xxyyyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 742);

    auto g_0_xxyyyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 743);

    auto g_0_xxyyyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 744);

    auto g_0_xxyyyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 745);

    auto g_0_xxyyyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 746);

    auto g_0_xxyyyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 747);

    auto g_0_xxyyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 748);

    auto g_0_xxyyyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 749);

    auto g_0_xxyyyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 750);

    auto g_0_xxyyyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 751);

    auto g_0_xxyyyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 752);

    auto g_0_xxyyyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 753);

    auto g_0_xxyyyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 754);

    auto g_0_xxyyyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 755);

    auto g_0_xxyyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 756);

    auto g_0_xxyyyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 757);

    auto g_0_xxyyyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 758);

    auto g_0_xxyyyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 759);

    auto g_0_xxyyyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 760);

    auto g_0_xxyyyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 761);

    auto g_0_xxyyyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 762);

    auto g_0_xxyyyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 763);

    auto g_0_xxyyyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 764);

    #pragma omp simd aligned(g_0_xxyyyy_0_xxxxxxx_1, g_0_xxyyyy_0_xxxxxxxx_0, g_0_xxyyyy_0_xxxxxxxx_1, g_0_xxyyyy_0_xxxxxxxy_0, g_0_xxyyyy_0_xxxxxxxy_1, g_0_xxyyyy_0_xxxxxxxz_0, g_0_xxyyyy_0_xxxxxxxz_1, g_0_xxyyyy_0_xxxxxxy_1, g_0_xxyyyy_0_xxxxxxyy_0, g_0_xxyyyy_0_xxxxxxyy_1, g_0_xxyyyy_0_xxxxxxyz_0, g_0_xxyyyy_0_xxxxxxyz_1, g_0_xxyyyy_0_xxxxxxz_1, g_0_xxyyyy_0_xxxxxxzz_0, g_0_xxyyyy_0_xxxxxxzz_1, g_0_xxyyyy_0_xxxxxyy_1, g_0_xxyyyy_0_xxxxxyyy_0, g_0_xxyyyy_0_xxxxxyyy_1, g_0_xxyyyy_0_xxxxxyyz_0, g_0_xxyyyy_0_xxxxxyyz_1, g_0_xxyyyy_0_xxxxxyz_1, g_0_xxyyyy_0_xxxxxyzz_0, g_0_xxyyyy_0_xxxxxyzz_1, g_0_xxyyyy_0_xxxxxzz_1, g_0_xxyyyy_0_xxxxxzzz_0, g_0_xxyyyy_0_xxxxxzzz_1, g_0_xxyyyy_0_xxxxyyy_1, g_0_xxyyyy_0_xxxxyyyy_0, g_0_xxyyyy_0_xxxxyyyy_1, g_0_xxyyyy_0_xxxxyyyz_0, g_0_xxyyyy_0_xxxxyyyz_1, g_0_xxyyyy_0_xxxxyyz_1, g_0_xxyyyy_0_xxxxyyzz_0, g_0_xxyyyy_0_xxxxyyzz_1, g_0_xxyyyy_0_xxxxyzz_1, g_0_xxyyyy_0_xxxxyzzz_0, g_0_xxyyyy_0_xxxxyzzz_1, g_0_xxyyyy_0_xxxxzzz_1, g_0_xxyyyy_0_xxxxzzzz_0, g_0_xxyyyy_0_xxxxzzzz_1, g_0_xxyyyy_0_xxxyyyy_1, g_0_xxyyyy_0_xxxyyyyy_0, g_0_xxyyyy_0_xxxyyyyy_1, g_0_xxyyyy_0_xxxyyyyz_0, g_0_xxyyyy_0_xxxyyyyz_1, g_0_xxyyyy_0_xxxyyyz_1, g_0_xxyyyy_0_xxxyyyzz_0, g_0_xxyyyy_0_xxxyyyzz_1, g_0_xxyyyy_0_xxxyyzz_1, g_0_xxyyyy_0_xxxyyzzz_0, g_0_xxyyyy_0_xxxyyzzz_1, g_0_xxyyyy_0_xxxyzzz_1, g_0_xxyyyy_0_xxxyzzzz_0, g_0_xxyyyy_0_xxxyzzzz_1, g_0_xxyyyy_0_xxxzzzz_1, g_0_xxyyyy_0_xxxzzzzz_0, g_0_xxyyyy_0_xxxzzzzz_1, g_0_xxyyyy_0_xxyyyyy_1, g_0_xxyyyy_0_xxyyyyyy_0, g_0_xxyyyy_0_xxyyyyyy_1, g_0_xxyyyy_0_xxyyyyyz_0, g_0_xxyyyy_0_xxyyyyyz_1, g_0_xxyyyy_0_xxyyyyz_1, g_0_xxyyyy_0_xxyyyyzz_0, g_0_xxyyyy_0_xxyyyyzz_1, g_0_xxyyyy_0_xxyyyzz_1, g_0_xxyyyy_0_xxyyyzzz_0, g_0_xxyyyy_0_xxyyyzzz_1, g_0_xxyyyy_0_xxyyzzz_1, g_0_xxyyyy_0_xxyyzzzz_0, g_0_xxyyyy_0_xxyyzzzz_1, g_0_xxyyyy_0_xxyzzzz_1, g_0_xxyyyy_0_xxyzzzzz_0, g_0_xxyyyy_0_xxyzzzzz_1, g_0_xxyyyy_0_xxzzzzz_1, g_0_xxyyyy_0_xxzzzzzz_0, g_0_xxyyyy_0_xxzzzzzz_1, g_0_xxyyyy_0_xyyyyyy_1, g_0_xxyyyy_0_xyyyyyyy_0, g_0_xxyyyy_0_xyyyyyyy_1, g_0_xxyyyy_0_xyyyyyyz_0, g_0_xxyyyy_0_xyyyyyyz_1, g_0_xxyyyy_0_xyyyyyz_1, g_0_xxyyyy_0_xyyyyyzz_0, g_0_xxyyyy_0_xyyyyyzz_1, g_0_xxyyyy_0_xyyyyzz_1, g_0_xxyyyy_0_xyyyyzzz_0, g_0_xxyyyy_0_xyyyyzzz_1, g_0_xxyyyy_0_xyyyzzz_1, g_0_xxyyyy_0_xyyyzzzz_0, g_0_xxyyyy_0_xyyyzzzz_1, g_0_xxyyyy_0_xyyzzzz_1, g_0_xxyyyy_0_xyyzzzzz_0, g_0_xxyyyy_0_xyyzzzzz_1, g_0_xxyyyy_0_xyzzzzz_1, g_0_xxyyyy_0_xyzzzzzz_0, g_0_xxyyyy_0_xyzzzzzz_1, g_0_xxyyyy_0_xzzzzzz_1, g_0_xxyyyy_0_xzzzzzzz_0, g_0_xxyyyy_0_xzzzzzzz_1, g_0_xxyyyy_0_yyyyyyy_1, g_0_xxyyyy_0_yyyyyyyy_0, g_0_xxyyyy_0_yyyyyyyy_1, g_0_xxyyyy_0_yyyyyyyz_0, g_0_xxyyyy_0_yyyyyyyz_1, g_0_xxyyyy_0_yyyyyyz_1, g_0_xxyyyy_0_yyyyyyzz_0, g_0_xxyyyy_0_yyyyyyzz_1, g_0_xxyyyy_0_yyyyyzz_1, g_0_xxyyyy_0_yyyyyzzz_0, g_0_xxyyyy_0_yyyyyzzz_1, g_0_xxyyyy_0_yyyyzzz_1, g_0_xxyyyy_0_yyyyzzzz_0, g_0_xxyyyy_0_yyyyzzzz_1, g_0_xxyyyy_0_yyyzzzz_1, g_0_xxyyyy_0_yyyzzzzz_0, g_0_xxyyyy_0_yyyzzzzz_1, g_0_xxyyyy_0_yyzzzzz_1, g_0_xxyyyy_0_yyzzzzzz_0, g_0_xxyyyy_0_yyzzzzzz_1, g_0_xxyyyy_0_yzzzzzz_1, g_0_xxyyyy_0_yzzzzzzz_0, g_0_xxyyyy_0_yzzzzzzz_1, g_0_xxyyyy_0_zzzzzzz_1, g_0_xxyyyy_0_zzzzzzzz_0, g_0_xxyyyy_0_zzzzzzzz_1, g_0_xxyyyyz_0_xxxxxxxx_0, g_0_xxyyyyz_0_xxxxxxxy_0, g_0_xxyyyyz_0_xxxxxxxz_0, g_0_xxyyyyz_0_xxxxxxyy_0, g_0_xxyyyyz_0_xxxxxxyz_0, g_0_xxyyyyz_0_xxxxxxzz_0, g_0_xxyyyyz_0_xxxxxyyy_0, g_0_xxyyyyz_0_xxxxxyyz_0, g_0_xxyyyyz_0_xxxxxyzz_0, g_0_xxyyyyz_0_xxxxxzzz_0, g_0_xxyyyyz_0_xxxxyyyy_0, g_0_xxyyyyz_0_xxxxyyyz_0, g_0_xxyyyyz_0_xxxxyyzz_0, g_0_xxyyyyz_0_xxxxyzzz_0, g_0_xxyyyyz_0_xxxxzzzz_0, g_0_xxyyyyz_0_xxxyyyyy_0, g_0_xxyyyyz_0_xxxyyyyz_0, g_0_xxyyyyz_0_xxxyyyzz_0, g_0_xxyyyyz_0_xxxyyzzz_0, g_0_xxyyyyz_0_xxxyzzzz_0, g_0_xxyyyyz_0_xxxzzzzz_0, g_0_xxyyyyz_0_xxyyyyyy_0, g_0_xxyyyyz_0_xxyyyyyz_0, g_0_xxyyyyz_0_xxyyyyzz_0, g_0_xxyyyyz_0_xxyyyzzz_0, g_0_xxyyyyz_0_xxyyzzzz_0, g_0_xxyyyyz_0_xxyzzzzz_0, g_0_xxyyyyz_0_xxzzzzzz_0, g_0_xxyyyyz_0_xyyyyyyy_0, g_0_xxyyyyz_0_xyyyyyyz_0, g_0_xxyyyyz_0_xyyyyyzz_0, g_0_xxyyyyz_0_xyyyyzzz_0, g_0_xxyyyyz_0_xyyyzzzz_0, g_0_xxyyyyz_0_xyyzzzzz_0, g_0_xxyyyyz_0_xyzzzzzz_0, g_0_xxyyyyz_0_xzzzzzzz_0, g_0_xxyyyyz_0_yyyyyyyy_0, g_0_xxyyyyz_0_yyyyyyyz_0, g_0_xxyyyyz_0_yyyyyyzz_0, g_0_xxyyyyz_0_yyyyyzzz_0, g_0_xxyyyyz_0_yyyyzzzz_0, g_0_xxyyyyz_0_yyyzzzzz_0, g_0_xxyyyyz_0_yyzzzzzz_0, g_0_xxyyyyz_0_yzzzzzzz_0, g_0_xxyyyyz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxyyyyz_0_xxxxxxxx_0[i] = g_0_xxyyyy_0_xxxxxxxx_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxxxy_0[i] = g_0_xxyyyy_0_xxxxxxxy_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxxxz_0[i] = g_0_xxyyyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxxz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxxyy_0[i] = g_0_xxyyyy_0_xxxxxxyy_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxxyz_0[i] = g_0_xxyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxyz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxxzz_0[i] = 2.0 * g_0_xxyyyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxxzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxyyy_0[i] = g_0_xxyyyy_0_xxxxxyyy_0[i] * pb_z + g_0_xxyyyy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxyyz_0[i] = g_0_xxyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxyyz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxyzz_0[i] = 2.0 * g_0_xxyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxyzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxxzzz_0[i] = 3.0 * g_0_xxyyyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxxzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxyyyy_0[i] = g_0_xxyyyy_0_xxxxyyyy_0[i] * pb_z + g_0_xxyyyy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxyyyz_0[i] = g_0_xxyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyyyz_0[i] * pb_z + g_0_xxyyyy_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyyzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxyzzz_0[i] = 3.0 * g_0_xxyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxyzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxxzzzz_0[i] = 4.0 * g_0_xxyyyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxxzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxyyyyy_0[i] = g_0_xxyyyy_0_xxxyyyyy_0[i] * pb_z + g_0_xxyyyy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxyyyyz_0[i] = g_0_xxyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyyyz_0[i] * pb_z + g_0_xxyyyy_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxyyyzz_0[i] = 2.0 * g_0_xxyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyyzz_0[i] * pb_z + g_0_xxyyyy_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxyyzzz_0[i] = 3.0 * g_0_xxyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyyzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxyzzzz_0[i] = 4.0 * g_0_xxyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxyzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxxzzzzz_0[i] = 5.0 * g_0_xxyyyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxxzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyyyyyy_0[i] = g_0_xxyyyy_0_xxyyyyyy_0[i] * pb_z + g_0_xxyyyy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyyyyyz_0[i] = g_0_xxyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyyyz_0[i] * pb_z + g_0_xxyyyy_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyyyyzz_0[i] = 2.0 * g_0_xxyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyyzz_0[i] * pb_z + g_0_xxyyyy_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyyzzz_0[i] * pb_z + g_0_xxyyyy_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyyzzzz_0[i] = 4.0 * g_0_xxyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyyzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxyzzzzz_0[i] = 5.0 * g_0_xxyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxyzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xxzzzzzz_0[i] = 6.0 * g_0_xxyyyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xxzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyyyyyy_0[i] = g_0_xxyyyy_0_xyyyyyyy_0[i] * pb_z + g_0_xxyyyy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyyyyyz_0[i] = g_0_xxyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyyyz_0[i] * pb_z + g_0_xxyyyy_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyyyyzz_0[i] = 2.0 * g_0_xxyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyyzz_0[i] * pb_z + g_0_xxyyyy_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyyyzzz_0[i] = 3.0 * g_0_xxyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyyzzz_0[i] * pb_z + g_0_xxyyyy_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyyzzzz_0[i] = 4.0 * g_0_xxyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyyzzzz_0[i] * pb_z + g_0_xxyyyy_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyyzzzzz_0[i] = 5.0 * g_0_xxyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyyzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xyzzzzzz_0[i] = 6.0 * g_0_xxyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xyzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_xzzzzzzz_0[i] = 7.0 * g_0_xxyyyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_xzzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyyyyyy_0[i] = g_0_xxyyyy_0_yyyyyyyy_0[i] * pb_z + g_0_xxyyyy_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyyyyyz_0[i] = g_0_xxyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyyyyyyz_0[i] * pb_z + g_0_xxyyyy_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyyyyzz_0[i] = 2.0 * g_0_xxyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyyyyyzz_0[i] * pb_z + g_0_xxyyyy_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyyyzzz_0[i] = 3.0 * g_0_xxyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyyyyzzz_0[i] * pb_z + g_0_xxyyyy_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyyyzzzz_0[i] * pb_z + g_0_xxyyyy_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyyzzzzz_0[i] = 5.0 * g_0_xxyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyyzzzzz_0[i] * pb_z + g_0_xxyyyy_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yyzzzzzz_0[i] = 6.0 * g_0_xxyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yyzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_yzzzzzzz_0[i] = 7.0 * g_0_xxyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_yzzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_xxyyyyz_0_zzzzzzzz_0[i] = 8.0 * g_0_xxyyyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxyyyy_0_zzzzzzzz_0[i] * pb_z + g_0_xxyyyy_0_zzzzzzzz_1[i] * wp_z[i];
    }

    /// Set up 765-810 components of targeted buffer : SKSL

    auto g_0_xxyyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 765);

    auto g_0_xxyyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 766);

    auto g_0_xxyyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 767);

    auto g_0_xxyyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 768);

    auto g_0_xxyyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 769);

    auto g_0_xxyyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 770);

    auto g_0_xxyyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 771);

    auto g_0_xxyyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 772);

    auto g_0_xxyyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 773);

    auto g_0_xxyyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 774);

    auto g_0_xxyyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 775);

    auto g_0_xxyyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 776);

    auto g_0_xxyyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 777);

    auto g_0_xxyyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 778);

    auto g_0_xxyyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 779);

    auto g_0_xxyyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 780);

    auto g_0_xxyyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 781);

    auto g_0_xxyyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 782);

    auto g_0_xxyyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 783);

    auto g_0_xxyyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 784);

    auto g_0_xxyyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 785);

    auto g_0_xxyyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 786);

    auto g_0_xxyyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 787);

    auto g_0_xxyyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 788);

    auto g_0_xxyyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 789);

    auto g_0_xxyyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 790);

    auto g_0_xxyyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 791);

    auto g_0_xxyyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 792);

    auto g_0_xxyyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 793);

    auto g_0_xxyyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 794);

    auto g_0_xxyyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 795);

    auto g_0_xxyyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 796);

    auto g_0_xxyyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 797);

    auto g_0_xxyyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 798);

    auto g_0_xxyyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 799);

    auto g_0_xxyyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 800);

    auto g_0_xxyyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 801);

    auto g_0_xxyyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 802);

    auto g_0_xxyyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 803);

    auto g_0_xxyyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 804);

    auto g_0_xxyyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 805);

    auto g_0_xxyyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 806);

    auto g_0_xxyyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 807);

    auto g_0_xxyyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 808);

    auto g_0_xxyyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 809);

    #pragma omp simd aligned(g_0_xxyyy_0_xxxxxxxy_0, g_0_xxyyy_0_xxxxxxxy_1, g_0_xxyyy_0_xxxxxxyy_0, g_0_xxyyy_0_xxxxxxyy_1, g_0_xxyyy_0_xxxxxyyy_0, g_0_xxyyy_0_xxxxxyyy_1, g_0_xxyyy_0_xxxxyyyy_0, g_0_xxyyy_0_xxxxyyyy_1, g_0_xxyyy_0_xxxyyyyy_0, g_0_xxyyy_0_xxxyyyyy_1, g_0_xxyyy_0_xxyyyyyy_0, g_0_xxyyy_0_xxyyyyyy_1, g_0_xxyyy_0_xyyyyyyy_0, g_0_xxyyy_0_xyyyyyyy_1, g_0_xxyyyz_0_xxxxxxxy_0, g_0_xxyyyz_0_xxxxxxxy_1, g_0_xxyyyz_0_xxxxxxyy_0, g_0_xxyyyz_0_xxxxxxyy_1, g_0_xxyyyz_0_xxxxxyyy_0, g_0_xxyyyz_0_xxxxxyyy_1, g_0_xxyyyz_0_xxxxyyyy_0, g_0_xxyyyz_0_xxxxyyyy_1, g_0_xxyyyz_0_xxxyyyyy_0, g_0_xxyyyz_0_xxxyyyyy_1, g_0_xxyyyz_0_xxyyyyyy_0, g_0_xxyyyz_0_xxyyyyyy_1, g_0_xxyyyz_0_xyyyyyyy_0, g_0_xxyyyz_0_xyyyyyyy_1, g_0_xxyyyzz_0_xxxxxxxx_0, g_0_xxyyyzz_0_xxxxxxxy_0, g_0_xxyyyzz_0_xxxxxxxz_0, g_0_xxyyyzz_0_xxxxxxyy_0, g_0_xxyyyzz_0_xxxxxxyz_0, g_0_xxyyyzz_0_xxxxxxzz_0, g_0_xxyyyzz_0_xxxxxyyy_0, g_0_xxyyyzz_0_xxxxxyyz_0, g_0_xxyyyzz_0_xxxxxyzz_0, g_0_xxyyyzz_0_xxxxxzzz_0, g_0_xxyyyzz_0_xxxxyyyy_0, g_0_xxyyyzz_0_xxxxyyyz_0, g_0_xxyyyzz_0_xxxxyyzz_0, g_0_xxyyyzz_0_xxxxyzzz_0, g_0_xxyyyzz_0_xxxxzzzz_0, g_0_xxyyyzz_0_xxxyyyyy_0, g_0_xxyyyzz_0_xxxyyyyz_0, g_0_xxyyyzz_0_xxxyyyzz_0, g_0_xxyyyzz_0_xxxyyzzz_0, g_0_xxyyyzz_0_xxxyzzzz_0, g_0_xxyyyzz_0_xxxzzzzz_0, g_0_xxyyyzz_0_xxyyyyyy_0, g_0_xxyyyzz_0_xxyyyyyz_0, g_0_xxyyyzz_0_xxyyyyzz_0, g_0_xxyyyzz_0_xxyyyzzz_0, g_0_xxyyyzz_0_xxyyzzzz_0, g_0_xxyyyzz_0_xxyzzzzz_0, g_0_xxyyyzz_0_xxzzzzzz_0, g_0_xxyyyzz_0_xyyyyyyy_0, g_0_xxyyyzz_0_xyyyyyyz_0, g_0_xxyyyzz_0_xyyyyyzz_0, g_0_xxyyyzz_0_xyyyyzzz_0, g_0_xxyyyzz_0_xyyyzzzz_0, g_0_xxyyyzz_0_xyyzzzzz_0, g_0_xxyyyzz_0_xyzzzzzz_0, g_0_xxyyyzz_0_xzzzzzzz_0, g_0_xxyyyzz_0_yyyyyyyy_0, g_0_xxyyyzz_0_yyyyyyyz_0, g_0_xxyyyzz_0_yyyyyyzz_0, g_0_xxyyyzz_0_yyyyyzzz_0, g_0_xxyyyzz_0_yyyyzzzz_0, g_0_xxyyyzz_0_yyyzzzzz_0, g_0_xxyyyzz_0_yyzzzzzz_0, g_0_xxyyyzz_0_yzzzzzzz_0, g_0_xxyyyzz_0_zzzzzzzz_0, g_0_xxyyzz_0_xxxxxxxx_0, g_0_xxyyzz_0_xxxxxxxx_1, g_0_xxyyzz_0_xxxxxxxz_0, g_0_xxyyzz_0_xxxxxxxz_1, g_0_xxyyzz_0_xxxxxxzz_0, g_0_xxyyzz_0_xxxxxxzz_1, g_0_xxyyzz_0_xxxxxzzz_0, g_0_xxyyzz_0_xxxxxzzz_1, g_0_xxyyzz_0_xxxxzzzz_0, g_0_xxyyzz_0_xxxxzzzz_1, g_0_xxyyzz_0_xxxzzzzz_0, g_0_xxyyzz_0_xxxzzzzz_1, g_0_xxyyzz_0_xxzzzzzz_0, g_0_xxyyzz_0_xxzzzzzz_1, g_0_xxyyzz_0_xzzzzzzz_0, g_0_xxyyzz_0_xzzzzzzz_1, g_0_xxyzz_0_xxxxxxxx_0, g_0_xxyzz_0_xxxxxxxx_1, g_0_xxyzz_0_xxxxxxxz_0, g_0_xxyzz_0_xxxxxxxz_1, g_0_xxyzz_0_xxxxxxzz_0, g_0_xxyzz_0_xxxxxxzz_1, g_0_xxyzz_0_xxxxxzzz_0, g_0_xxyzz_0_xxxxxzzz_1, g_0_xxyzz_0_xxxxzzzz_0, g_0_xxyzz_0_xxxxzzzz_1, g_0_xxyzz_0_xxxzzzzz_0, g_0_xxyzz_0_xxxzzzzz_1, g_0_xxyzz_0_xxzzzzzz_0, g_0_xxyzz_0_xxzzzzzz_1, g_0_xxyzz_0_xzzzzzzz_0, g_0_xxyzz_0_xzzzzzzz_1, g_0_xyyyzz_0_xxxxxxyz_0, g_0_xyyyzz_0_xxxxxxyz_1, g_0_xyyyzz_0_xxxxxyyz_0, g_0_xyyyzz_0_xxxxxyyz_1, g_0_xyyyzz_0_xxxxxyz_1, g_0_xyyyzz_0_xxxxxyzz_0, g_0_xyyyzz_0_xxxxxyzz_1, g_0_xyyyzz_0_xxxxyyyz_0, g_0_xyyyzz_0_xxxxyyyz_1, g_0_xyyyzz_0_xxxxyyz_1, g_0_xyyyzz_0_xxxxyyzz_0, g_0_xyyyzz_0_xxxxyyzz_1, g_0_xyyyzz_0_xxxxyzz_1, g_0_xyyyzz_0_xxxxyzzz_0, g_0_xyyyzz_0_xxxxyzzz_1, g_0_xyyyzz_0_xxxyyyyz_0, g_0_xyyyzz_0_xxxyyyyz_1, g_0_xyyyzz_0_xxxyyyz_1, g_0_xyyyzz_0_xxxyyyzz_0, g_0_xyyyzz_0_xxxyyyzz_1, g_0_xyyyzz_0_xxxyyzz_1, g_0_xyyyzz_0_xxxyyzzz_0, g_0_xyyyzz_0_xxxyyzzz_1, g_0_xyyyzz_0_xxxyzzz_1, g_0_xyyyzz_0_xxxyzzzz_0, g_0_xyyyzz_0_xxxyzzzz_1, g_0_xyyyzz_0_xxyyyyyz_0, g_0_xyyyzz_0_xxyyyyyz_1, g_0_xyyyzz_0_xxyyyyz_1, g_0_xyyyzz_0_xxyyyyzz_0, g_0_xyyyzz_0_xxyyyyzz_1, g_0_xyyyzz_0_xxyyyzz_1, g_0_xyyyzz_0_xxyyyzzz_0, g_0_xyyyzz_0_xxyyyzzz_1, g_0_xyyyzz_0_xxyyzzz_1, g_0_xyyyzz_0_xxyyzzzz_0, g_0_xyyyzz_0_xxyyzzzz_1, g_0_xyyyzz_0_xxyzzzz_1, g_0_xyyyzz_0_xxyzzzzz_0, g_0_xyyyzz_0_xxyzzzzz_1, g_0_xyyyzz_0_xyyyyyyz_0, g_0_xyyyzz_0_xyyyyyyz_1, g_0_xyyyzz_0_xyyyyyz_1, g_0_xyyyzz_0_xyyyyyzz_0, g_0_xyyyzz_0_xyyyyyzz_1, g_0_xyyyzz_0_xyyyyzz_1, g_0_xyyyzz_0_xyyyyzzz_0, g_0_xyyyzz_0_xyyyyzzz_1, g_0_xyyyzz_0_xyyyzzz_1, g_0_xyyyzz_0_xyyyzzzz_0, g_0_xyyyzz_0_xyyyzzzz_1, g_0_xyyyzz_0_xyyzzzz_1, g_0_xyyyzz_0_xyyzzzzz_0, g_0_xyyyzz_0_xyyzzzzz_1, g_0_xyyyzz_0_xyzzzzz_1, g_0_xyyyzz_0_xyzzzzzz_0, g_0_xyyyzz_0_xyzzzzzz_1, g_0_xyyyzz_0_yyyyyyyy_0, g_0_xyyyzz_0_yyyyyyyy_1, g_0_xyyyzz_0_yyyyyyyz_0, g_0_xyyyzz_0_yyyyyyyz_1, g_0_xyyyzz_0_yyyyyyz_1, g_0_xyyyzz_0_yyyyyyzz_0, g_0_xyyyzz_0_yyyyyyzz_1, g_0_xyyyzz_0_yyyyyzz_1, g_0_xyyyzz_0_yyyyyzzz_0, g_0_xyyyzz_0_yyyyyzzz_1, g_0_xyyyzz_0_yyyyzzz_1, g_0_xyyyzz_0_yyyyzzzz_0, g_0_xyyyzz_0_yyyyzzzz_1, g_0_xyyyzz_0_yyyzzzz_1, g_0_xyyyzz_0_yyyzzzzz_0, g_0_xyyyzz_0_yyyzzzzz_1, g_0_xyyyzz_0_yyzzzzz_1, g_0_xyyyzz_0_yyzzzzzz_0, g_0_xyyyzz_0_yyzzzzzz_1, g_0_xyyyzz_0_yzzzzzz_1, g_0_xyyyzz_0_yzzzzzzz_0, g_0_xyyyzz_0_yzzzzzzz_1, g_0_xyyyzz_0_zzzzzzzz_0, g_0_xyyyzz_0_zzzzzzzz_1, g_0_yyyzz_0_xxxxxxyz_0, g_0_yyyzz_0_xxxxxxyz_1, g_0_yyyzz_0_xxxxxyyz_0, g_0_yyyzz_0_xxxxxyyz_1, g_0_yyyzz_0_xxxxxyzz_0, g_0_yyyzz_0_xxxxxyzz_1, g_0_yyyzz_0_xxxxyyyz_0, g_0_yyyzz_0_xxxxyyyz_1, g_0_yyyzz_0_xxxxyyzz_0, g_0_yyyzz_0_xxxxyyzz_1, g_0_yyyzz_0_xxxxyzzz_0, g_0_yyyzz_0_xxxxyzzz_1, g_0_yyyzz_0_xxxyyyyz_0, g_0_yyyzz_0_xxxyyyyz_1, g_0_yyyzz_0_xxxyyyzz_0, g_0_yyyzz_0_xxxyyyzz_1, g_0_yyyzz_0_xxxyyzzz_0, g_0_yyyzz_0_xxxyyzzz_1, g_0_yyyzz_0_xxxyzzzz_0, g_0_yyyzz_0_xxxyzzzz_1, g_0_yyyzz_0_xxyyyyyz_0, g_0_yyyzz_0_xxyyyyyz_1, g_0_yyyzz_0_xxyyyyzz_0, g_0_yyyzz_0_xxyyyyzz_1, g_0_yyyzz_0_xxyyyzzz_0, g_0_yyyzz_0_xxyyyzzz_1, g_0_yyyzz_0_xxyyzzzz_0, g_0_yyyzz_0_xxyyzzzz_1, g_0_yyyzz_0_xxyzzzzz_0, g_0_yyyzz_0_xxyzzzzz_1, g_0_yyyzz_0_xyyyyyyz_0, g_0_yyyzz_0_xyyyyyyz_1, g_0_yyyzz_0_xyyyyyzz_0, g_0_yyyzz_0_xyyyyyzz_1, g_0_yyyzz_0_xyyyyzzz_0, g_0_yyyzz_0_xyyyyzzz_1, g_0_yyyzz_0_xyyyzzzz_0, g_0_yyyzz_0_xyyyzzzz_1, g_0_yyyzz_0_xyyzzzzz_0, g_0_yyyzz_0_xyyzzzzz_1, g_0_yyyzz_0_xyzzzzzz_0, g_0_yyyzz_0_xyzzzzzz_1, g_0_yyyzz_0_yyyyyyyy_0, g_0_yyyzz_0_yyyyyyyy_1, g_0_yyyzz_0_yyyyyyyz_0, g_0_yyyzz_0_yyyyyyyz_1, g_0_yyyzz_0_yyyyyyzz_0, g_0_yyyzz_0_yyyyyyzz_1, g_0_yyyzz_0_yyyyyzzz_0, g_0_yyyzz_0_yyyyyzzz_1, g_0_yyyzz_0_yyyyzzzz_0, g_0_yyyzz_0_yyyyzzzz_1, g_0_yyyzz_0_yyyzzzzz_0, g_0_yyyzz_0_yyyzzzzz_1, g_0_yyyzz_0_yyzzzzzz_0, g_0_yyyzz_0_yyzzzzzz_1, g_0_yyyzz_0_yzzzzzzz_0, g_0_yyyzz_0_yzzzzzzz_1, g_0_yyyzz_0_zzzzzzzz_0, g_0_yyyzz_0_zzzzzzzz_1, wp_x, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxyyyzz_0_xxxxxxxx_0[i] = 2.0 * g_0_xxyzz_0_xxxxxxxx_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxyyzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxxxxxxy_0[i] = g_0_xxyyy_0_xxxxxxxy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxxxxxxy_0[i] * pb_z + g_0_xxyyyz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxxxxxxz_0[i] = 2.0 * g_0_xxyzz_0_xxxxxxxz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxyyzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxxxxxyy_0[i] = g_0_xxyyy_0_xxxxxxyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxxxxxyy_0[i] * pb_z + g_0_xxyyyz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxxxxxyz_0[i] = g_0_yyyzz_0_xxxxxxyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xyyyzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxxxyz_0[i] * pb_x + g_0_xyyyzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxxxzz_0[i] = 2.0 * g_0_xxyzz_0_xxxxxxzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxyyzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxxxxyyy_0[i] = g_0_xxyyy_0_xxxxxyyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxxxxyyy_0[i] * pb_z + g_0_xxyyyz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxxxxyyz_0[i] = g_0_yyyzz_0_xxxxxyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xyyyzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxxyyz_0[i] * pb_x + g_0_xyyyzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxxyzz_0[i] = g_0_yyyzz_0_xxxxxyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xyyyzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxxyzz_0[i] * pb_x + g_0_xyyyzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxxzzz_0[i] = 2.0 * g_0_xxyzz_0_xxxxxzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxyyzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxxxyyyy_0[i] = g_0_xxyyy_0_xxxxyyyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxxxyyyy_0[i] * pb_z + g_0_xxyyyz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxxxyyyz_0[i] = g_0_yyyzz_0_xxxxyyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxyyyz_0[i] * pb_x + g_0_xyyyzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxyyzz_0[i] = g_0_yyyzz_0_xxxxyyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxyyzz_0[i] * pb_x + g_0_xyyyzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxyzzz_0[i] = g_0_yyyzz_0_xxxxyzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyyzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxxyzzz_0[i] * pb_x + g_0_xyyyzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxxzzzz_0[i] = 2.0 * g_0_xxyzz_0_xxxxzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxyyzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxxyyyyy_0[i] = g_0_xxyyy_0_xxxyyyyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxxyyyyy_0[i] * pb_z + g_0_xxyyyz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxxyyyyz_0[i] = g_0_yyyzz_0_xxxyyyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxyyyyz_0[i] * pb_x + g_0_xyyyzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxyyyzz_0[i] = g_0_yyyzz_0_xxxyyyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxyyyzz_0[i] * pb_x + g_0_xyyyzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxyyzzz_0[i] = g_0_yyyzz_0_xxxyyzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxyyzzz_0[i] * pb_x + g_0_xyyyzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxyzzzz_0[i] = g_0_yyyzz_0_xxxyzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyyzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxxyzzzz_0[i] * pb_x + g_0_xyyyzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxxzzzzz_0[i] = 2.0 * g_0_xxyzz_0_xxxzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxyyzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xxyyyyyy_0[i] = g_0_xxyyy_0_xxyyyyyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xxyyyyyy_0[i] * pb_z + g_0_xxyyyz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xxyyyyyz_0[i] = g_0_yyyzz_0_xxyyyyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxyyyyyz_0[i] * pb_x + g_0_xyyyzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxyyyyzz_0[i] = g_0_yyyzz_0_xxyyyyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxyyyyzz_0[i] * pb_x + g_0_xyyyzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxyyyzzz_0[i] = g_0_yyyzz_0_xxyyyzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxyyyzzz_0[i] * pb_x + g_0_xyyyzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxyyzzzz_0[i] = g_0_yyyzz_0_xxyyzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxyyzzzz_0[i] * pb_x + g_0_xyyyzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxyzzzzz_0[i] = g_0_yyyzz_0_xxyzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyyzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xxyzzzzz_0[i] * pb_x + g_0_xyyyzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xxzzzzzz_0[i] = 2.0 * g_0_xxyzz_0_xxzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxyyzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_xyyyyyyy_0[i] = g_0_xxyyy_0_xyyyyyyy_0[i] * fi_ab_0 - g_0_xxyyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxyyyz_0_xyyyyyyy_0[i] * pb_z + g_0_xxyyyz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxyyyzz_0_xyyyyyyz_0[i] = g_0_yyyzz_0_xyyyyyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyyyyyyz_0[i] * pb_x + g_0_xyyyzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xyyyyyzz_0[i] = g_0_yyyzz_0_xyyyyyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyyyyyzz_0[i] * pb_x + g_0_xyyyzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xyyyyzzz_0[i] = g_0_yyyzz_0_xyyyyzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyyyyzzz_0[i] * pb_x + g_0_xyyyzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xyyyzzzz_0[i] = g_0_yyyzz_0_xyyyzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyyyzzzz_0[i] * pb_x + g_0_xyyyzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xyyzzzzz_0[i] = g_0_yyyzz_0_xyyzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyyzzzzz_0[i] * pb_x + g_0_xyyyzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xyzzzzzz_0[i] = g_0_yyyzz_0_xyzzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xyyyzz_0_xyzzzzzz_0[i] * pb_x + g_0_xyyyzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_xzzzzzzz_0[i] = 2.0 * g_0_xxyzz_0_xzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_xxyzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxyyzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxyyzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxyyyzz_0_yyyyyyyy_0[i] = g_0_yyyzz_0_yyyyyyyy_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyyyy_0[i] * pb_x + g_0_xyyyzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyyyyyyz_0[i] = g_0_yyyzz_0_yyyyyyyz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyyyz_0[i] * pb_x + g_0_xyyyzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyyyyyzz_0[i] = g_0_yyyzz_0_yyyyyyzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyyzz_0[i] * pb_x + g_0_xyyyzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyyyyzzz_0[i] = g_0_yyyzz_0_yyyyyzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyyzzz_0[i] * pb_x + g_0_xyyyzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyyyzzzz_0[i] = g_0_yyyzz_0_yyyyzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyyzzzz_0[i] * pb_x + g_0_xyyyzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyyzzzzz_0[i] = g_0_yyyzz_0_yyyzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyyzzzzz_0[i] * pb_x + g_0_xyyyzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yyzzzzzz_0[i] = g_0_yyyzz_0_yyzzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yyzzzzzz_0[i] * pb_x + g_0_xyyyzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_yzzzzzzz_0[i] = g_0_yyyzz_0_yzzzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_yzzzzzzz_0[i] * pb_x + g_0_xyyyzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxyyyzz_0_zzzzzzzz_0[i] = g_0_yyyzz_0_zzzzzzzz_0[i] * fi_ab_0 - g_0_yyyzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xyyyzz_0_zzzzzzzz_0[i] * pb_x + g_0_xyyyzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 810-855 components of targeted buffer : SKSL

    auto g_0_xxyyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 810);

    auto g_0_xxyyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 811);

    auto g_0_xxyyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 812);

    auto g_0_xxyyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 813);

    auto g_0_xxyyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 814);

    auto g_0_xxyyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 815);

    auto g_0_xxyyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 816);

    auto g_0_xxyyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 817);

    auto g_0_xxyyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 818);

    auto g_0_xxyyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 819);

    auto g_0_xxyyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 820);

    auto g_0_xxyyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 821);

    auto g_0_xxyyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 822);

    auto g_0_xxyyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 823);

    auto g_0_xxyyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 824);

    auto g_0_xxyyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 825);

    auto g_0_xxyyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 826);

    auto g_0_xxyyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 827);

    auto g_0_xxyyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 828);

    auto g_0_xxyyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 829);

    auto g_0_xxyyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 830);

    auto g_0_xxyyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 831);

    auto g_0_xxyyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 832);

    auto g_0_xxyyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 833);

    auto g_0_xxyyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 834);

    auto g_0_xxyyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 835);

    auto g_0_xxyyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 836);

    auto g_0_xxyyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 837);

    auto g_0_xxyyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 838);

    auto g_0_xxyyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 839);

    auto g_0_xxyyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 840);

    auto g_0_xxyyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 841);

    auto g_0_xxyyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 842);

    auto g_0_xxyyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 843);

    auto g_0_xxyyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 844);

    auto g_0_xxyyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 845);

    auto g_0_xxyyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 846);

    auto g_0_xxyyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 847);

    auto g_0_xxyyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 848);

    auto g_0_xxyyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 849);

    auto g_0_xxyyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 850);

    auto g_0_xxyyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 851);

    auto g_0_xxyyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 852);

    auto g_0_xxyyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 853);

    auto g_0_xxyyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 854);

    #pragma omp simd aligned(g_0_xxyyz_0_xxxxxxxy_0, g_0_xxyyz_0_xxxxxxxy_1, g_0_xxyyz_0_xxxxxxyy_0, g_0_xxyyz_0_xxxxxxyy_1, g_0_xxyyz_0_xxxxxyyy_0, g_0_xxyyz_0_xxxxxyyy_1, g_0_xxyyz_0_xxxxyyyy_0, g_0_xxyyz_0_xxxxyyyy_1, g_0_xxyyz_0_xxxyyyyy_0, g_0_xxyyz_0_xxxyyyyy_1, g_0_xxyyz_0_xxyyyyyy_0, g_0_xxyyz_0_xxyyyyyy_1, g_0_xxyyz_0_xyyyyyyy_0, g_0_xxyyz_0_xyyyyyyy_1, g_0_xxyyzz_0_xxxxxxxy_0, g_0_xxyyzz_0_xxxxxxxy_1, g_0_xxyyzz_0_xxxxxxyy_0, g_0_xxyyzz_0_xxxxxxyy_1, g_0_xxyyzz_0_xxxxxyyy_0, g_0_xxyyzz_0_xxxxxyyy_1, g_0_xxyyzz_0_xxxxyyyy_0, g_0_xxyyzz_0_xxxxyyyy_1, g_0_xxyyzz_0_xxxyyyyy_0, g_0_xxyyzz_0_xxxyyyyy_1, g_0_xxyyzz_0_xxyyyyyy_0, g_0_xxyyzz_0_xxyyyyyy_1, g_0_xxyyzz_0_xyyyyyyy_0, g_0_xxyyzz_0_xyyyyyyy_1, g_0_xxyyzzz_0_xxxxxxxx_0, g_0_xxyyzzz_0_xxxxxxxy_0, g_0_xxyyzzz_0_xxxxxxxz_0, g_0_xxyyzzz_0_xxxxxxyy_0, g_0_xxyyzzz_0_xxxxxxyz_0, g_0_xxyyzzz_0_xxxxxxzz_0, g_0_xxyyzzz_0_xxxxxyyy_0, g_0_xxyyzzz_0_xxxxxyyz_0, g_0_xxyyzzz_0_xxxxxyzz_0, g_0_xxyyzzz_0_xxxxxzzz_0, g_0_xxyyzzz_0_xxxxyyyy_0, g_0_xxyyzzz_0_xxxxyyyz_0, g_0_xxyyzzz_0_xxxxyyzz_0, g_0_xxyyzzz_0_xxxxyzzz_0, g_0_xxyyzzz_0_xxxxzzzz_0, g_0_xxyyzzz_0_xxxyyyyy_0, g_0_xxyyzzz_0_xxxyyyyz_0, g_0_xxyyzzz_0_xxxyyyzz_0, g_0_xxyyzzz_0_xxxyyzzz_0, g_0_xxyyzzz_0_xxxyzzzz_0, g_0_xxyyzzz_0_xxxzzzzz_0, g_0_xxyyzzz_0_xxyyyyyy_0, g_0_xxyyzzz_0_xxyyyyyz_0, g_0_xxyyzzz_0_xxyyyyzz_0, g_0_xxyyzzz_0_xxyyyzzz_0, g_0_xxyyzzz_0_xxyyzzzz_0, g_0_xxyyzzz_0_xxyzzzzz_0, g_0_xxyyzzz_0_xxzzzzzz_0, g_0_xxyyzzz_0_xyyyyyyy_0, g_0_xxyyzzz_0_xyyyyyyz_0, g_0_xxyyzzz_0_xyyyyyzz_0, g_0_xxyyzzz_0_xyyyyzzz_0, g_0_xxyyzzz_0_xyyyzzzz_0, g_0_xxyyzzz_0_xyyzzzzz_0, g_0_xxyyzzz_0_xyzzzzzz_0, g_0_xxyyzzz_0_xzzzzzzz_0, g_0_xxyyzzz_0_yyyyyyyy_0, g_0_xxyyzzz_0_yyyyyyyz_0, g_0_xxyyzzz_0_yyyyyyzz_0, g_0_xxyyzzz_0_yyyyyzzz_0, g_0_xxyyzzz_0_yyyyzzzz_0, g_0_xxyyzzz_0_yyyzzzzz_0, g_0_xxyyzzz_0_yyzzzzzz_0, g_0_xxyyzzz_0_yzzzzzzz_0, g_0_xxyyzzz_0_zzzzzzzz_0, g_0_xxyzzz_0_xxxxxxxx_0, g_0_xxyzzz_0_xxxxxxxx_1, g_0_xxyzzz_0_xxxxxxxz_0, g_0_xxyzzz_0_xxxxxxxz_1, g_0_xxyzzz_0_xxxxxxzz_0, g_0_xxyzzz_0_xxxxxxzz_1, g_0_xxyzzz_0_xxxxxzzz_0, g_0_xxyzzz_0_xxxxxzzz_1, g_0_xxyzzz_0_xxxxzzzz_0, g_0_xxyzzz_0_xxxxzzzz_1, g_0_xxyzzz_0_xxxzzzzz_0, g_0_xxyzzz_0_xxxzzzzz_1, g_0_xxyzzz_0_xxzzzzzz_0, g_0_xxyzzz_0_xxzzzzzz_1, g_0_xxyzzz_0_xzzzzzzz_0, g_0_xxyzzz_0_xzzzzzzz_1, g_0_xxzzz_0_xxxxxxxx_0, g_0_xxzzz_0_xxxxxxxx_1, g_0_xxzzz_0_xxxxxxxz_0, g_0_xxzzz_0_xxxxxxxz_1, g_0_xxzzz_0_xxxxxxzz_0, g_0_xxzzz_0_xxxxxxzz_1, g_0_xxzzz_0_xxxxxzzz_0, g_0_xxzzz_0_xxxxxzzz_1, g_0_xxzzz_0_xxxxzzzz_0, g_0_xxzzz_0_xxxxzzzz_1, g_0_xxzzz_0_xxxzzzzz_0, g_0_xxzzz_0_xxxzzzzz_1, g_0_xxzzz_0_xxzzzzzz_0, g_0_xxzzz_0_xxzzzzzz_1, g_0_xxzzz_0_xzzzzzzz_0, g_0_xxzzz_0_xzzzzzzz_1, g_0_xyyzzz_0_xxxxxxyz_0, g_0_xyyzzz_0_xxxxxxyz_1, g_0_xyyzzz_0_xxxxxyyz_0, g_0_xyyzzz_0_xxxxxyyz_1, g_0_xyyzzz_0_xxxxxyz_1, g_0_xyyzzz_0_xxxxxyzz_0, g_0_xyyzzz_0_xxxxxyzz_1, g_0_xyyzzz_0_xxxxyyyz_0, g_0_xyyzzz_0_xxxxyyyz_1, g_0_xyyzzz_0_xxxxyyz_1, g_0_xyyzzz_0_xxxxyyzz_0, g_0_xyyzzz_0_xxxxyyzz_1, g_0_xyyzzz_0_xxxxyzz_1, g_0_xyyzzz_0_xxxxyzzz_0, g_0_xyyzzz_0_xxxxyzzz_1, g_0_xyyzzz_0_xxxyyyyz_0, g_0_xyyzzz_0_xxxyyyyz_1, g_0_xyyzzz_0_xxxyyyz_1, g_0_xyyzzz_0_xxxyyyzz_0, g_0_xyyzzz_0_xxxyyyzz_1, g_0_xyyzzz_0_xxxyyzz_1, g_0_xyyzzz_0_xxxyyzzz_0, g_0_xyyzzz_0_xxxyyzzz_1, g_0_xyyzzz_0_xxxyzzz_1, g_0_xyyzzz_0_xxxyzzzz_0, g_0_xyyzzz_0_xxxyzzzz_1, g_0_xyyzzz_0_xxyyyyyz_0, g_0_xyyzzz_0_xxyyyyyz_1, g_0_xyyzzz_0_xxyyyyz_1, g_0_xyyzzz_0_xxyyyyzz_0, g_0_xyyzzz_0_xxyyyyzz_1, g_0_xyyzzz_0_xxyyyzz_1, g_0_xyyzzz_0_xxyyyzzz_0, g_0_xyyzzz_0_xxyyyzzz_1, g_0_xyyzzz_0_xxyyzzz_1, g_0_xyyzzz_0_xxyyzzzz_0, g_0_xyyzzz_0_xxyyzzzz_1, g_0_xyyzzz_0_xxyzzzz_1, g_0_xyyzzz_0_xxyzzzzz_0, g_0_xyyzzz_0_xxyzzzzz_1, g_0_xyyzzz_0_xyyyyyyz_0, g_0_xyyzzz_0_xyyyyyyz_1, g_0_xyyzzz_0_xyyyyyz_1, g_0_xyyzzz_0_xyyyyyzz_0, g_0_xyyzzz_0_xyyyyyzz_1, g_0_xyyzzz_0_xyyyyzz_1, g_0_xyyzzz_0_xyyyyzzz_0, g_0_xyyzzz_0_xyyyyzzz_1, g_0_xyyzzz_0_xyyyzzz_1, g_0_xyyzzz_0_xyyyzzzz_0, g_0_xyyzzz_0_xyyyzzzz_1, g_0_xyyzzz_0_xyyzzzz_1, g_0_xyyzzz_0_xyyzzzzz_0, g_0_xyyzzz_0_xyyzzzzz_1, g_0_xyyzzz_0_xyzzzzz_1, g_0_xyyzzz_0_xyzzzzzz_0, g_0_xyyzzz_0_xyzzzzzz_1, g_0_xyyzzz_0_yyyyyyyy_0, g_0_xyyzzz_0_yyyyyyyy_1, g_0_xyyzzz_0_yyyyyyyz_0, g_0_xyyzzz_0_yyyyyyyz_1, g_0_xyyzzz_0_yyyyyyz_1, g_0_xyyzzz_0_yyyyyyzz_0, g_0_xyyzzz_0_yyyyyyzz_1, g_0_xyyzzz_0_yyyyyzz_1, g_0_xyyzzz_0_yyyyyzzz_0, g_0_xyyzzz_0_yyyyyzzz_1, g_0_xyyzzz_0_yyyyzzz_1, g_0_xyyzzz_0_yyyyzzzz_0, g_0_xyyzzz_0_yyyyzzzz_1, g_0_xyyzzz_0_yyyzzzz_1, g_0_xyyzzz_0_yyyzzzzz_0, g_0_xyyzzz_0_yyyzzzzz_1, g_0_xyyzzz_0_yyzzzzz_1, g_0_xyyzzz_0_yyzzzzzz_0, g_0_xyyzzz_0_yyzzzzzz_1, g_0_xyyzzz_0_yzzzzzz_1, g_0_xyyzzz_0_yzzzzzzz_0, g_0_xyyzzz_0_yzzzzzzz_1, g_0_xyyzzz_0_zzzzzzzz_0, g_0_xyyzzz_0_zzzzzzzz_1, g_0_yyzzz_0_xxxxxxyz_0, g_0_yyzzz_0_xxxxxxyz_1, g_0_yyzzz_0_xxxxxyyz_0, g_0_yyzzz_0_xxxxxyyz_1, g_0_yyzzz_0_xxxxxyzz_0, g_0_yyzzz_0_xxxxxyzz_1, g_0_yyzzz_0_xxxxyyyz_0, g_0_yyzzz_0_xxxxyyyz_1, g_0_yyzzz_0_xxxxyyzz_0, g_0_yyzzz_0_xxxxyyzz_1, g_0_yyzzz_0_xxxxyzzz_0, g_0_yyzzz_0_xxxxyzzz_1, g_0_yyzzz_0_xxxyyyyz_0, g_0_yyzzz_0_xxxyyyyz_1, g_0_yyzzz_0_xxxyyyzz_0, g_0_yyzzz_0_xxxyyyzz_1, g_0_yyzzz_0_xxxyyzzz_0, g_0_yyzzz_0_xxxyyzzz_1, g_0_yyzzz_0_xxxyzzzz_0, g_0_yyzzz_0_xxxyzzzz_1, g_0_yyzzz_0_xxyyyyyz_0, g_0_yyzzz_0_xxyyyyyz_1, g_0_yyzzz_0_xxyyyyzz_0, g_0_yyzzz_0_xxyyyyzz_1, g_0_yyzzz_0_xxyyyzzz_0, g_0_yyzzz_0_xxyyyzzz_1, g_0_yyzzz_0_xxyyzzzz_0, g_0_yyzzz_0_xxyyzzzz_1, g_0_yyzzz_0_xxyzzzzz_0, g_0_yyzzz_0_xxyzzzzz_1, g_0_yyzzz_0_xyyyyyyz_0, g_0_yyzzz_0_xyyyyyyz_1, g_0_yyzzz_0_xyyyyyzz_0, g_0_yyzzz_0_xyyyyyzz_1, g_0_yyzzz_0_xyyyyzzz_0, g_0_yyzzz_0_xyyyyzzz_1, g_0_yyzzz_0_xyyyzzzz_0, g_0_yyzzz_0_xyyyzzzz_1, g_0_yyzzz_0_xyyzzzzz_0, g_0_yyzzz_0_xyyzzzzz_1, g_0_yyzzz_0_xyzzzzzz_0, g_0_yyzzz_0_xyzzzzzz_1, g_0_yyzzz_0_yyyyyyyy_0, g_0_yyzzz_0_yyyyyyyy_1, g_0_yyzzz_0_yyyyyyyz_0, g_0_yyzzz_0_yyyyyyyz_1, g_0_yyzzz_0_yyyyyyzz_0, g_0_yyzzz_0_yyyyyyzz_1, g_0_yyzzz_0_yyyyyzzz_0, g_0_yyzzz_0_yyyyyzzz_1, g_0_yyzzz_0_yyyyzzzz_0, g_0_yyzzz_0_yyyyzzzz_1, g_0_yyzzz_0_yyyzzzzz_0, g_0_yyzzz_0_yyyzzzzz_1, g_0_yyzzz_0_yyzzzzzz_0, g_0_yyzzz_0_yyzzzzzz_1, g_0_yyzzz_0_yzzzzzzz_0, g_0_yyzzz_0_yzzzzzzz_1, g_0_yyzzz_0_zzzzzzzz_0, g_0_yyzzz_0_zzzzzzzz_1, wp_x, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxyyzzz_0_xxxxxxxx_0[i] = g_0_xxzzz_0_xxxxxxxx_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxyzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxxxxxxy_0[i] = 2.0 * g_0_xxyyz_0_xxxxxxxy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxxxy_0[i] * pb_z + g_0_xxyyzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxxxxxxz_0[i] = g_0_xxzzz_0_xxxxxxxz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxyzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_xxyyz_0_xxxxxxyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxxyy_0[i] * pb_z + g_0_xxyyzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxxxxxyz_0[i] = g_0_yyzzz_0_xxxxxxyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xyyzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxxxyz_0[i] * pb_x + g_0_xyyzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxxxzz_0[i] = g_0_xxzzz_0_xxxxxxzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxyzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxxxxyyy_0[i] = 2.0 * g_0_xxyyz_0_xxxxxyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxxyyy_0[i] * pb_z + g_0_xxyyzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxxxxyyz_0[i] = g_0_yyzzz_0_xxxxxyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xyyzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxxyyz_0[i] * pb_x + g_0_xyyzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxxyzz_0[i] = g_0_yyzzz_0_xxxxxyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xyyzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxxyzz_0[i] * pb_x + g_0_xyyzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxxzzz_0[i] = g_0_xxzzz_0_xxxxxzzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxyzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxxxyyyy_0[i] = 2.0 * g_0_xxyyz_0_xxxxyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxxyyyy_0[i] * pb_z + g_0_xxyyzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxxxyyyz_0[i] = g_0_yyzzz_0_xxxxyyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xyyzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxyyyz_0[i] * pb_x + g_0_xyyzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxyyzz_0[i] = g_0_yyzzz_0_xxxxyyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxyyzz_0[i] * pb_x + g_0_xyyzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxyzzz_0[i] = g_0_yyzzz_0_xxxxyzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xyyzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxxyzzz_0[i] * pb_x + g_0_xyyzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxxzzzz_0[i] = g_0_xxzzz_0_xxxxzzzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxyzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxxyyyyy_0[i] = 2.0 * g_0_xxyyz_0_xxxyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxxyyyyy_0[i] * pb_z + g_0_xxyyzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxxyyyyz_0[i] = g_0_yyzzz_0_xxxyyyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xyyzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxyyyyz_0[i] * pb_x + g_0_xyyzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxyyyzz_0[i] = g_0_yyzzz_0_xxxyyyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxyyyzz_0[i] * pb_x + g_0_xyyzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxyyzzz_0[i] = g_0_yyzzz_0_xxxyyzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxyyzzz_0[i] * pb_x + g_0_xyyzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxyzzzz_0[i] = g_0_yyzzz_0_xxxyzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xyyzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxxyzzzz_0[i] * pb_x + g_0_xyyzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxxzzzzz_0[i] = g_0_xxzzz_0_xxxzzzzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxyzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_xxyyz_0_xxyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xxyyyyyy_0[i] * pb_z + g_0_xxyyzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xxyyyyyz_0[i] = g_0_yyzzz_0_xxyyyyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xyyzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxyyyyyz_0[i] * pb_x + g_0_xyyzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxyyyyzz_0[i] = g_0_yyzzz_0_xxyyyyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxyyyyzz_0[i] * pb_x + g_0_xyyzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxyyyzzz_0[i] = g_0_yyzzz_0_xxyyyzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxyyyzzz_0[i] * pb_x + g_0_xyyzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxyyzzzz_0[i] = g_0_yyzzz_0_xxyyzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxyyzzzz_0[i] * pb_x + g_0_xyyzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxyzzzzz_0[i] = g_0_yyzzz_0_xxyzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xyyzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xxyzzzzz_0[i] * pb_x + g_0_xyyzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xxzzzzzz_0[i] = g_0_xxzzz_0_xxzzzzzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxyzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_xyyyyyyy_0[i] = 2.0 * g_0_xxyyz_0_xyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_xxyyz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxyyzz_0_xyyyyyyy_0[i] * pb_z + g_0_xxyyzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxyyzzz_0_xyyyyyyz_0[i] = g_0_yyzzz_0_xyyyyyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyyyyyyz_0[i] * pb_x + g_0_xyyzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xyyyyyzz_0[i] = g_0_yyzzz_0_xyyyyyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyyyyyzz_0[i] * pb_x + g_0_xyyzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xyyyyzzz_0[i] = g_0_yyzzz_0_xyyyyzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyyyyzzz_0[i] * pb_x + g_0_xyyzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xyyyzzzz_0[i] = g_0_yyzzz_0_xyyyzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyyyzzzz_0[i] * pb_x + g_0_xyyzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xyyzzzzz_0[i] = g_0_yyzzz_0_xyyzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyyzzzzz_0[i] * pb_x + g_0_xyyzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xyzzzzzz_0[i] = g_0_yyzzz_0_xyzzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xyyzzz_0_xyzzzzzz_0[i] * pb_x + g_0_xyyzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_xzzzzzzz_0[i] = g_0_xxzzz_0_xzzzzzzz_0[i] * fi_ab_0 - g_0_xxzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xxyzzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxyzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxyyzzz_0_yyyyyyyy_0[i] = g_0_yyzzz_0_yyyyyyyy_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyyyy_0[i] * pb_x + g_0_xyyzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyyyyyyz_0[i] = g_0_yyzzz_0_yyyyyyyz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyyyz_0[i] * pb_x + g_0_xyyzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyyyyyzz_0[i] = g_0_yyzzz_0_yyyyyyzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyyzz_0[i] * pb_x + g_0_xyyzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyyyyzzz_0[i] = g_0_yyzzz_0_yyyyyzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyyzzz_0[i] * pb_x + g_0_xyyzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyyyzzzz_0[i] = g_0_yyzzz_0_yyyyzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyyzzzz_0[i] * pb_x + g_0_xyyzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyyzzzzz_0[i] = g_0_yyzzz_0_yyyzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyyzzzzz_0[i] * pb_x + g_0_xyyzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yyzzzzzz_0[i] = g_0_yyzzz_0_yyzzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yyzzzzzz_0[i] * pb_x + g_0_xyyzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_yzzzzzzz_0[i] = g_0_yyzzz_0_yzzzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_yzzzzzzz_0[i] * pb_x + g_0_xyyzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxyyzzz_0_zzzzzzzz_0[i] = g_0_yyzzz_0_zzzzzzzz_0[i] * fi_ab_0 - g_0_yyzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xyyzzz_0_zzzzzzzz_0[i] * pb_x + g_0_xyyzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 855-900 components of targeted buffer : SKSL

    auto g_0_xxyzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 855);

    auto g_0_xxyzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 856);

    auto g_0_xxyzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 857);

    auto g_0_xxyzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 858);

    auto g_0_xxyzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 859);

    auto g_0_xxyzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 860);

    auto g_0_xxyzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 861);

    auto g_0_xxyzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 862);

    auto g_0_xxyzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 863);

    auto g_0_xxyzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 864);

    auto g_0_xxyzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 865);

    auto g_0_xxyzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 866);

    auto g_0_xxyzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 867);

    auto g_0_xxyzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 868);

    auto g_0_xxyzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 869);

    auto g_0_xxyzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 870);

    auto g_0_xxyzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 871);

    auto g_0_xxyzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 872);

    auto g_0_xxyzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 873);

    auto g_0_xxyzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 874);

    auto g_0_xxyzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 875);

    auto g_0_xxyzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 876);

    auto g_0_xxyzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 877);

    auto g_0_xxyzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 878);

    auto g_0_xxyzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 879);

    auto g_0_xxyzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 880);

    auto g_0_xxyzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 881);

    auto g_0_xxyzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 882);

    auto g_0_xxyzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 883);

    auto g_0_xxyzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 884);

    auto g_0_xxyzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 885);

    auto g_0_xxyzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 886);

    auto g_0_xxyzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 887);

    auto g_0_xxyzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 888);

    auto g_0_xxyzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 889);

    auto g_0_xxyzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 890);

    auto g_0_xxyzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 891);

    auto g_0_xxyzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 892);

    auto g_0_xxyzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 893);

    auto g_0_xxyzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 894);

    auto g_0_xxyzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 895);

    auto g_0_xxyzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 896);

    auto g_0_xxyzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 897);

    auto g_0_xxyzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 898);

    auto g_0_xxyzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 899);

    #pragma omp simd aligned(g_0_xxyzzzz_0_xxxxxxxx_0, g_0_xxyzzzz_0_xxxxxxxy_0, g_0_xxyzzzz_0_xxxxxxxz_0, g_0_xxyzzzz_0_xxxxxxyy_0, g_0_xxyzzzz_0_xxxxxxyz_0, g_0_xxyzzzz_0_xxxxxxzz_0, g_0_xxyzzzz_0_xxxxxyyy_0, g_0_xxyzzzz_0_xxxxxyyz_0, g_0_xxyzzzz_0_xxxxxyzz_0, g_0_xxyzzzz_0_xxxxxzzz_0, g_0_xxyzzzz_0_xxxxyyyy_0, g_0_xxyzzzz_0_xxxxyyyz_0, g_0_xxyzzzz_0_xxxxyyzz_0, g_0_xxyzzzz_0_xxxxyzzz_0, g_0_xxyzzzz_0_xxxxzzzz_0, g_0_xxyzzzz_0_xxxyyyyy_0, g_0_xxyzzzz_0_xxxyyyyz_0, g_0_xxyzzzz_0_xxxyyyzz_0, g_0_xxyzzzz_0_xxxyyzzz_0, g_0_xxyzzzz_0_xxxyzzzz_0, g_0_xxyzzzz_0_xxxzzzzz_0, g_0_xxyzzzz_0_xxyyyyyy_0, g_0_xxyzzzz_0_xxyyyyyz_0, g_0_xxyzzzz_0_xxyyyyzz_0, g_0_xxyzzzz_0_xxyyyzzz_0, g_0_xxyzzzz_0_xxyyzzzz_0, g_0_xxyzzzz_0_xxyzzzzz_0, g_0_xxyzzzz_0_xxzzzzzz_0, g_0_xxyzzzz_0_xyyyyyyy_0, g_0_xxyzzzz_0_xyyyyyyz_0, g_0_xxyzzzz_0_xyyyyyzz_0, g_0_xxyzzzz_0_xyyyyzzz_0, g_0_xxyzzzz_0_xyyyzzzz_0, g_0_xxyzzzz_0_xyyzzzzz_0, g_0_xxyzzzz_0_xyzzzzzz_0, g_0_xxyzzzz_0_xzzzzzzz_0, g_0_xxyzzzz_0_yyyyyyyy_0, g_0_xxyzzzz_0_yyyyyyyz_0, g_0_xxyzzzz_0_yyyyyyzz_0, g_0_xxyzzzz_0_yyyyyzzz_0, g_0_xxyzzzz_0_yyyyzzzz_0, g_0_xxyzzzz_0_yyyzzzzz_0, g_0_xxyzzzz_0_yyzzzzzz_0, g_0_xxyzzzz_0_yzzzzzzz_0, g_0_xxyzzzz_0_zzzzzzzz_0, g_0_xxzzzz_0_xxxxxxx_1, g_0_xxzzzz_0_xxxxxxxx_0, g_0_xxzzzz_0_xxxxxxxx_1, g_0_xxzzzz_0_xxxxxxxy_0, g_0_xxzzzz_0_xxxxxxxy_1, g_0_xxzzzz_0_xxxxxxxz_0, g_0_xxzzzz_0_xxxxxxxz_1, g_0_xxzzzz_0_xxxxxxy_1, g_0_xxzzzz_0_xxxxxxyy_0, g_0_xxzzzz_0_xxxxxxyy_1, g_0_xxzzzz_0_xxxxxxyz_0, g_0_xxzzzz_0_xxxxxxyz_1, g_0_xxzzzz_0_xxxxxxz_1, g_0_xxzzzz_0_xxxxxxzz_0, g_0_xxzzzz_0_xxxxxxzz_1, g_0_xxzzzz_0_xxxxxyy_1, g_0_xxzzzz_0_xxxxxyyy_0, g_0_xxzzzz_0_xxxxxyyy_1, g_0_xxzzzz_0_xxxxxyyz_0, g_0_xxzzzz_0_xxxxxyyz_1, g_0_xxzzzz_0_xxxxxyz_1, g_0_xxzzzz_0_xxxxxyzz_0, g_0_xxzzzz_0_xxxxxyzz_1, g_0_xxzzzz_0_xxxxxzz_1, g_0_xxzzzz_0_xxxxxzzz_0, g_0_xxzzzz_0_xxxxxzzz_1, g_0_xxzzzz_0_xxxxyyy_1, g_0_xxzzzz_0_xxxxyyyy_0, g_0_xxzzzz_0_xxxxyyyy_1, g_0_xxzzzz_0_xxxxyyyz_0, g_0_xxzzzz_0_xxxxyyyz_1, g_0_xxzzzz_0_xxxxyyz_1, g_0_xxzzzz_0_xxxxyyzz_0, g_0_xxzzzz_0_xxxxyyzz_1, g_0_xxzzzz_0_xxxxyzz_1, g_0_xxzzzz_0_xxxxyzzz_0, g_0_xxzzzz_0_xxxxyzzz_1, g_0_xxzzzz_0_xxxxzzz_1, g_0_xxzzzz_0_xxxxzzzz_0, g_0_xxzzzz_0_xxxxzzzz_1, g_0_xxzzzz_0_xxxyyyy_1, g_0_xxzzzz_0_xxxyyyyy_0, g_0_xxzzzz_0_xxxyyyyy_1, g_0_xxzzzz_0_xxxyyyyz_0, g_0_xxzzzz_0_xxxyyyyz_1, g_0_xxzzzz_0_xxxyyyz_1, g_0_xxzzzz_0_xxxyyyzz_0, g_0_xxzzzz_0_xxxyyyzz_1, g_0_xxzzzz_0_xxxyyzz_1, g_0_xxzzzz_0_xxxyyzzz_0, g_0_xxzzzz_0_xxxyyzzz_1, g_0_xxzzzz_0_xxxyzzz_1, g_0_xxzzzz_0_xxxyzzzz_0, g_0_xxzzzz_0_xxxyzzzz_1, g_0_xxzzzz_0_xxxzzzz_1, g_0_xxzzzz_0_xxxzzzzz_0, g_0_xxzzzz_0_xxxzzzzz_1, g_0_xxzzzz_0_xxyyyyy_1, g_0_xxzzzz_0_xxyyyyyy_0, g_0_xxzzzz_0_xxyyyyyy_1, g_0_xxzzzz_0_xxyyyyyz_0, g_0_xxzzzz_0_xxyyyyyz_1, g_0_xxzzzz_0_xxyyyyz_1, g_0_xxzzzz_0_xxyyyyzz_0, g_0_xxzzzz_0_xxyyyyzz_1, g_0_xxzzzz_0_xxyyyzz_1, g_0_xxzzzz_0_xxyyyzzz_0, g_0_xxzzzz_0_xxyyyzzz_1, g_0_xxzzzz_0_xxyyzzz_1, g_0_xxzzzz_0_xxyyzzzz_0, g_0_xxzzzz_0_xxyyzzzz_1, g_0_xxzzzz_0_xxyzzzz_1, g_0_xxzzzz_0_xxyzzzzz_0, g_0_xxzzzz_0_xxyzzzzz_1, g_0_xxzzzz_0_xxzzzzz_1, g_0_xxzzzz_0_xxzzzzzz_0, g_0_xxzzzz_0_xxzzzzzz_1, g_0_xxzzzz_0_xyyyyyy_1, g_0_xxzzzz_0_xyyyyyyy_0, g_0_xxzzzz_0_xyyyyyyy_1, g_0_xxzzzz_0_xyyyyyyz_0, g_0_xxzzzz_0_xyyyyyyz_1, g_0_xxzzzz_0_xyyyyyz_1, g_0_xxzzzz_0_xyyyyyzz_0, g_0_xxzzzz_0_xyyyyyzz_1, g_0_xxzzzz_0_xyyyyzz_1, g_0_xxzzzz_0_xyyyyzzz_0, g_0_xxzzzz_0_xyyyyzzz_1, g_0_xxzzzz_0_xyyyzzz_1, g_0_xxzzzz_0_xyyyzzzz_0, g_0_xxzzzz_0_xyyyzzzz_1, g_0_xxzzzz_0_xyyzzzz_1, g_0_xxzzzz_0_xyyzzzzz_0, g_0_xxzzzz_0_xyyzzzzz_1, g_0_xxzzzz_0_xyzzzzz_1, g_0_xxzzzz_0_xyzzzzzz_0, g_0_xxzzzz_0_xyzzzzzz_1, g_0_xxzzzz_0_xzzzzzz_1, g_0_xxzzzz_0_xzzzzzzz_0, g_0_xxzzzz_0_xzzzzzzz_1, g_0_xxzzzz_0_yyyyyyy_1, g_0_xxzzzz_0_yyyyyyyy_0, g_0_xxzzzz_0_yyyyyyyy_1, g_0_xxzzzz_0_yyyyyyyz_0, g_0_xxzzzz_0_yyyyyyyz_1, g_0_xxzzzz_0_yyyyyyz_1, g_0_xxzzzz_0_yyyyyyzz_0, g_0_xxzzzz_0_yyyyyyzz_1, g_0_xxzzzz_0_yyyyyzz_1, g_0_xxzzzz_0_yyyyyzzz_0, g_0_xxzzzz_0_yyyyyzzz_1, g_0_xxzzzz_0_yyyyzzz_1, g_0_xxzzzz_0_yyyyzzzz_0, g_0_xxzzzz_0_yyyyzzzz_1, g_0_xxzzzz_0_yyyzzzz_1, g_0_xxzzzz_0_yyyzzzzz_0, g_0_xxzzzz_0_yyyzzzzz_1, g_0_xxzzzz_0_yyzzzzz_1, g_0_xxzzzz_0_yyzzzzzz_0, g_0_xxzzzz_0_yyzzzzzz_1, g_0_xxzzzz_0_yzzzzzz_1, g_0_xxzzzz_0_yzzzzzzz_0, g_0_xxzzzz_0_yzzzzzzz_1, g_0_xxzzzz_0_zzzzzzz_1, g_0_xxzzzz_0_zzzzzzzz_0, g_0_xxzzzz_0_zzzzzzzz_1, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xxyzzzz_0_xxxxxxxx_0[i] = g_0_xxzzzz_0_xxxxxxxx_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxxxy_0[i] = g_0_xxzzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxxy_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxxxz_0[i] = g_0_xxzzzz_0_xxxxxxxz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_xxzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxyy_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxxyz_0[i] = g_0_xxzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxxyz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxxzz_0[i] = g_0_xxzzzz_0_xxxxxxzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxyyy_0[i] = 3.0 * g_0_xxzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxyyy_0[i] * pb_y + g_0_xxzzzz_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxyyz_0[i] = 2.0 * g_0_xxzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxyyz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxyzz_0[i] = g_0_xxzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxxyzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxxzzz_0[i] = g_0_xxzzzz_0_xxxxxzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_xxzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyyyy_0[i] * pb_y + g_0_xxzzzz_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxyyyz_0[i] = 3.0 * g_0_xxzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyyyz_0[i] * pb_y + g_0_xxzzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxyyzz_0[i] = 2.0 * g_0_xxzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyyzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxyzzz_0[i] = g_0_xxzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxxyzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxxzzzz_0[i] = g_0_xxzzzz_0_xxxxzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxyyyyy_0[i] = 5.0 * g_0_xxzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyyyy_0[i] * pb_y + g_0_xxzzzz_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxyyyyz_0[i] = 4.0 * g_0_xxzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyyyz_0[i] * pb_y + g_0_xxzzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_xxzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyyzz_0[i] * pb_y + g_0_xxzzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxyyzzz_0[i] = 2.0 * g_0_xxzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyyzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxyzzzz_0[i] = g_0_xxzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxxyzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxxzzzzz_0[i] = g_0_xxzzzz_0_xxxzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyyyyyy_0[i] = 6.0 * g_0_xxzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyyyy_0[i] * pb_y + g_0_xxzzzz_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyyyyyz_0[i] = 5.0 * g_0_xxzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyyyz_0[i] * pb_y + g_0_xxzzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyyyyzz_0[i] = 4.0 * g_0_xxzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyyzz_0[i] * pb_y + g_0_xxzzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyyyzzz_0[i] = 3.0 * g_0_xxzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyyzzz_0[i] * pb_y + g_0_xxzzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_xxzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyyzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxyzzzzz_0[i] = g_0_xxzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xxyzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xxzzzzzz_0[i] = g_0_xxzzzz_0_xxzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyyyyyy_0[i] = 7.0 * g_0_xxzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyyyy_0[i] * pb_y + g_0_xxzzzz_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyyyyyz_0[i] = 6.0 * g_0_xxzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyyyz_0[i] * pb_y + g_0_xxzzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyyyyzz_0[i] = 5.0 * g_0_xxzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyyzz_0[i] * pb_y + g_0_xxzzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyyyzzz_0[i] = 4.0 * g_0_xxzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyyzzz_0[i] * pb_y + g_0_xxzzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyyzzzz_0[i] = 3.0 * g_0_xxzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyyzzzz_0[i] * pb_y + g_0_xxzzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyyzzzzz_0[i] = 2.0 * g_0_xxzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyyzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xyzzzzzz_0[i] = g_0_xxzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_xyzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_xzzzzzzz_0[i] = g_0_xxzzzz_0_xzzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyyyyyy_0[i] = 8.0 * g_0_xxzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyyyyyy_0[i] * pb_y + g_0_xxzzzz_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyyyyyz_0[i] = 7.0 * g_0_xxzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyyyyyz_0[i] * pb_y + g_0_xxzzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyyyyzz_0[i] = 6.0 * g_0_xxzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyyyyzz_0[i] * pb_y + g_0_xxzzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyyyzzz_0[i] = 5.0 * g_0_xxzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyyyzzz_0[i] * pb_y + g_0_xxzzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyyzzzz_0[i] = 4.0 * g_0_xxzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyyzzzz_0[i] * pb_y + g_0_xxzzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyyzzzzz_0[i] = 3.0 * g_0_xxzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyyzzzzz_0[i] * pb_y + g_0_xxzzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yyzzzzzz_0[i] = 2.0 * g_0_xxzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yyzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_yzzzzzzz_0[i] = g_0_xxzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xxzzzz_0_yzzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_xxyzzzz_0_zzzzzzzz_0[i] = g_0_xxzzzz_0_zzzzzzzz_0[i] * pb_y + g_0_xxzzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 900-945 components of targeted buffer : SKSL

    auto g_0_xxzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 900);

    auto g_0_xxzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 901);

    auto g_0_xxzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 902);

    auto g_0_xxzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 903);

    auto g_0_xxzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 904);

    auto g_0_xxzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 905);

    auto g_0_xxzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 906);

    auto g_0_xxzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 907);

    auto g_0_xxzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 908);

    auto g_0_xxzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 909);

    auto g_0_xxzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 910);

    auto g_0_xxzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 911);

    auto g_0_xxzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 912);

    auto g_0_xxzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 913);

    auto g_0_xxzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 914);

    auto g_0_xxzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 915);

    auto g_0_xxzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 916);

    auto g_0_xxzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 917);

    auto g_0_xxzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 918);

    auto g_0_xxzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 919);

    auto g_0_xxzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 920);

    auto g_0_xxzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 921);

    auto g_0_xxzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 922);

    auto g_0_xxzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 923);

    auto g_0_xxzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 924);

    auto g_0_xxzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 925);

    auto g_0_xxzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 926);

    auto g_0_xxzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 927);

    auto g_0_xxzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 928);

    auto g_0_xxzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 929);

    auto g_0_xxzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 930);

    auto g_0_xxzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 931);

    auto g_0_xxzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 932);

    auto g_0_xxzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 933);

    auto g_0_xxzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 934);

    auto g_0_xxzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 935);

    auto g_0_xxzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 936);

    auto g_0_xxzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 937);

    auto g_0_xxzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 938);

    auto g_0_xxzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 939);

    auto g_0_xxzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 940);

    auto g_0_xxzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 941);

    auto g_0_xxzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 942);

    auto g_0_xxzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 943);

    auto g_0_xxzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 944);

    #pragma omp simd aligned(g_0_xxzzz_0_xxxxxxxx_0, g_0_xxzzz_0_xxxxxxxx_1, g_0_xxzzz_0_xxxxxxxy_0, g_0_xxzzz_0_xxxxxxxy_1, g_0_xxzzz_0_xxxxxxyy_0, g_0_xxzzz_0_xxxxxxyy_1, g_0_xxzzz_0_xxxxxyyy_0, g_0_xxzzz_0_xxxxxyyy_1, g_0_xxzzz_0_xxxxyyyy_0, g_0_xxzzz_0_xxxxyyyy_1, g_0_xxzzz_0_xxxyyyyy_0, g_0_xxzzz_0_xxxyyyyy_1, g_0_xxzzz_0_xxyyyyyy_0, g_0_xxzzz_0_xxyyyyyy_1, g_0_xxzzz_0_xyyyyyyy_0, g_0_xxzzz_0_xyyyyyyy_1, g_0_xxzzzz_0_xxxxxxxx_0, g_0_xxzzzz_0_xxxxxxxx_1, g_0_xxzzzz_0_xxxxxxxy_0, g_0_xxzzzz_0_xxxxxxxy_1, g_0_xxzzzz_0_xxxxxxyy_0, g_0_xxzzzz_0_xxxxxxyy_1, g_0_xxzzzz_0_xxxxxyyy_0, g_0_xxzzzz_0_xxxxxyyy_1, g_0_xxzzzz_0_xxxxyyyy_0, g_0_xxzzzz_0_xxxxyyyy_1, g_0_xxzzzz_0_xxxyyyyy_0, g_0_xxzzzz_0_xxxyyyyy_1, g_0_xxzzzz_0_xxyyyyyy_0, g_0_xxzzzz_0_xxyyyyyy_1, g_0_xxzzzz_0_xyyyyyyy_0, g_0_xxzzzz_0_xyyyyyyy_1, g_0_xxzzzzz_0_xxxxxxxx_0, g_0_xxzzzzz_0_xxxxxxxy_0, g_0_xxzzzzz_0_xxxxxxxz_0, g_0_xxzzzzz_0_xxxxxxyy_0, g_0_xxzzzzz_0_xxxxxxyz_0, g_0_xxzzzzz_0_xxxxxxzz_0, g_0_xxzzzzz_0_xxxxxyyy_0, g_0_xxzzzzz_0_xxxxxyyz_0, g_0_xxzzzzz_0_xxxxxyzz_0, g_0_xxzzzzz_0_xxxxxzzz_0, g_0_xxzzzzz_0_xxxxyyyy_0, g_0_xxzzzzz_0_xxxxyyyz_0, g_0_xxzzzzz_0_xxxxyyzz_0, g_0_xxzzzzz_0_xxxxyzzz_0, g_0_xxzzzzz_0_xxxxzzzz_0, g_0_xxzzzzz_0_xxxyyyyy_0, g_0_xxzzzzz_0_xxxyyyyz_0, g_0_xxzzzzz_0_xxxyyyzz_0, g_0_xxzzzzz_0_xxxyyzzz_0, g_0_xxzzzzz_0_xxxyzzzz_0, g_0_xxzzzzz_0_xxxzzzzz_0, g_0_xxzzzzz_0_xxyyyyyy_0, g_0_xxzzzzz_0_xxyyyyyz_0, g_0_xxzzzzz_0_xxyyyyzz_0, g_0_xxzzzzz_0_xxyyyzzz_0, g_0_xxzzzzz_0_xxyyzzzz_0, g_0_xxzzzzz_0_xxyzzzzz_0, g_0_xxzzzzz_0_xxzzzzzz_0, g_0_xxzzzzz_0_xyyyyyyy_0, g_0_xxzzzzz_0_xyyyyyyz_0, g_0_xxzzzzz_0_xyyyyyzz_0, g_0_xxzzzzz_0_xyyyyzzz_0, g_0_xxzzzzz_0_xyyyzzzz_0, g_0_xxzzzzz_0_xyyzzzzz_0, g_0_xxzzzzz_0_xyzzzzzz_0, g_0_xxzzzzz_0_xzzzzzzz_0, g_0_xxzzzzz_0_yyyyyyyy_0, g_0_xxzzzzz_0_yyyyyyyz_0, g_0_xxzzzzz_0_yyyyyyzz_0, g_0_xxzzzzz_0_yyyyyzzz_0, g_0_xxzzzzz_0_yyyyzzzz_0, g_0_xxzzzzz_0_yyyzzzzz_0, g_0_xxzzzzz_0_yyzzzzzz_0, g_0_xxzzzzz_0_yzzzzzzz_0, g_0_xxzzzzz_0_zzzzzzzz_0, g_0_xzzzzz_0_xxxxxxxz_0, g_0_xzzzzz_0_xxxxxxxz_1, g_0_xzzzzz_0_xxxxxxyz_0, g_0_xzzzzz_0_xxxxxxyz_1, g_0_xzzzzz_0_xxxxxxz_1, g_0_xzzzzz_0_xxxxxxzz_0, g_0_xzzzzz_0_xxxxxxzz_1, g_0_xzzzzz_0_xxxxxyyz_0, g_0_xzzzzz_0_xxxxxyyz_1, g_0_xzzzzz_0_xxxxxyz_1, g_0_xzzzzz_0_xxxxxyzz_0, g_0_xzzzzz_0_xxxxxyzz_1, g_0_xzzzzz_0_xxxxxzz_1, g_0_xzzzzz_0_xxxxxzzz_0, g_0_xzzzzz_0_xxxxxzzz_1, g_0_xzzzzz_0_xxxxyyyz_0, g_0_xzzzzz_0_xxxxyyyz_1, g_0_xzzzzz_0_xxxxyyz_1, g_0_xzzzzz_0_xxxxyyzz_0, g_0_xzzzzz_0_xxxxyyzz_1, g_0_xzzzzz_0_xxxxyzz_1, g_0_xzzzzz_0_xxxxyzzz_0, g_0_xzzzzz_0_xxxxyzzz_1, g_0_xzzzzz_0_xxxxzzz_1, g_0_xzzzzz_0_xxxxzzzz_0, g_0_xzzzzz_0_xxxxzzzz_1, g_0_xzzzzz_0_xxxyyyyz_0, g_0_xzzzzz_0_xxxyyyyz_1, g_0_xzzzzz_0_xxxyyyz_1, g_0_xzzzzz_0_xxxyyyzz_0, g_0_xzzzzz_0_xxxyyyzz_1, g_0_xzzzzz_0_xxxyyzz_1, g_0_xzzzzz_0_xxxyyzzz_0, g_0_xzzzzz_0_xxxyyzzz_1, g_0_xzzzzz_0_xxxyzzz_1, g_0_xzzzzz_0_xxxyzzzz_0, g_0_xzzzzz_0_xxxyzzzz_1, g_0_xzzzzz_0_xxxzzzz_1, g_0_xzzzzz_0_xxxzzzzz_0, g_0_xzzzzz_0_xxxzzzzz_1, g_0_xzzzzz_0_xxyyyyyz_0, g_0_xzzzzz_0_xxyyyyyz_1, g_0_xzzzzz_0_xxyyyyz_1, g_0_xzzzzz_0_xxyyyyzz_0, g_0_xzzzzz_0_xxyyyyzz_1, g_0_xzzzzz_0_xxyyyzz_1, g_0_xzzzzz_0_xxyyyzzz_0, g_0_xzzzzz_0_xxyyyzzz_1, g_0_xzzzzz_0_xxyyzzz_1, g_0_xzzzzz_0_xxyyzzzz_0, g_0_xzzzzz_0_xxyyzzzz_1, g_0_xzzzzz_0_xxyzzzz_1, g_0_xzzzzz_0_xxyzzzzz_0, g_0_xzzzzz_0_xxyzzzzz_1, g_0_xzzzzz_0_xxzzzzz_1, g_0_xzzzzz_0_xxzzzzzz_0, g_0_xzzzzz_0_xxzzzzzz_1, g_0_xzzzzz_0_xyyyyyyz_0, g_0_xzzzzz_0_xyyyyyyz_1, g_0_xzzzzz_0_xyyyyyz_1, g_0_xzzzzz_0_xyyyyyzz_0, g_0_xzzzzz_0_xyyyyyzz_1, g_0_xzzzzz_0_xyyyyzz_1, g_0_xzzzzz_0_xyyyyzzz_0, g_0_xzzzzz_0_xyyyyzzz_1, g_0_xzzzzz_0_xyyyzzz_1, g_0_xzzzzz_0_xyyyzzzz_0, g_0_xzzzzz_0_xyyyzzzz_1, g_0_xzzzzz_0_xyyzzzz_1, g_0_xzzzzz_0_xyyzzzzz_0, g_0_xzzzzz_0_xyyzzzzz_1, g_0_xzzzzz_0_xyzzzzz_1, g_0_xzzzzz_0_xyzzzzzz_0, g_0_xzzzzz_0_xyzzzzzz_1, g_0_xzzzzz_0_xzzzzzz_1, g_0_xzzzzz_0_xzzzzzzz_0, g_0_xzzzzz_0_xzzzzzzz_1, g_0_xzzzzz_0_yyyyyyyy_0, g_0_xzzzzz_0_yyyyyyyy_1, g_0_xzzzzz_0_yyyyyyyz_0, g_0_xzzzzz_0_yyyyyyyz_1, g_0_xzzzzz_0_yyyyyyz_1, g_0_xzzzzz_0_yyyyyyzz_0, g_0_xzzzzz_0_yyyyyyzz_1, g_0_xzzzzz_0_yyyyyzz_1, g_0_xzzzzz_0_yyyyyzzz_0, g_0_xzzzzz_0_yyyyyzzz_1, g_0_xzzzzz_0_yyyyzzz_1, g_0_xzzzzz_0_yyyyzzzz_0, g_0_xzzzzz_0_yyyyzzzz_1, g_0_xzzzzz_0_yyyzzzz_1, g_0_xzzzzz_0_yyyzzzzz_0, g_0_xzzzzz_0_yyyzzzzz_1, g_0_xzzzzz_0_yyzzzzz_1, g_0_xzzzzz_0_yyzzzzzz_0, g_0_xzzzzz_0_yyzzzzzz_1, g_0_xzzzzz_0_yzzzzzz_1, g_0_xzzzzz_0_yzzzzzzz_0, g_0_xzzzzz_0_yzzzzzzz_1, g_0_xzzzzz_0_zzzzzzz_1, g_0_xzzzzz_0_zzzzzzzz_0, g_0_xzzzzz_0_zzzzzzzz_1, g_0_zzzzz_0_xxxxxxxz_0, g_0_zzzzz_0_xxxxxxxz_1, g_0_zzzzz_0_xxxxxxyz_0, g_0_zzzzz_0_xxxxxxyz_1, g_0_zzzzz_0_xxxxxxzz_0, g_0_zzzzz_0_xxxxxxzz_1, g_0_zzzzz_0_xxxxxyyz_0, g_0_zzzzz_0_xxxxxyyz_1, g_0_zzzzz_0_xxxxxyzz_0, g_0_zzzzz_0_xxxxxyzz_1, g_0_zzzzz_0_xxxxxzzz_0, g_0_zzzzz_0_xxxxxzzz_1, g_0_zzzzz_0_xxxxyyyz_0, g_0_zzzzz_0_xxxxyyyz_1, g_0_zzzzz_0_xxxxyyzz_0, g_0_zzzzz_0_xxxxyyzz_1, g_0_zzzzz_0_xxxxyzzz_0, g_0_zzzzz_0_xxxxyzzz_1, g_0_zzzzz_0_xxxxzzzz_0, g_0_zzzzz_0_xxxxzzzz_1, g_0_zzzzz_0_xxxyyyyz_0, g_0_zzzzz_0_xxxyyyyz_1, g_0_zzzzz_0_xxxyyyzz_0, g_0_zzzzz_0_xxxyyyzz_1, g_0_zzzzz_0_xxxyyzzz_0, g_0_zzzzz_0_xxxyyzzz_1, g_0_zzzzz_0_xxxyzzzz_0, g_0_zzzzz_0_xxxyzzzz_1, g_0_zzzzz_0_xxxzzzzz_0, g_0_zzzzz_0_xxxzzzzz_1, g_0_zzzzz_0_xxyyyyyz_0, g_0_zzzzz_0_xxyyyyyz_1, g_0_zzzzz_0_xxyyyyzz_0, g_0_zzzzz_0_xxyyyyzz_1, g_0_zzzzz_0_xxyyyzzz_0, g_0_zzzzz_0_xxyyyzzz_1, g_0_zzzzz_0_xxyyzzzz_0, g_0_zzzzz_0_xxyyzzzz_1, g_0_zzzzz_0_xxyzzzzz_0, g_0_zzzzz_0_xxyzzzzz_1, g_0_zzzzz_0_xxzzzzzz_0, g_0_zzzzz_0_xxzzzzzz_1, g_0_zzzzz_0_xyyyyyyz_0, g_0_zzzzz_0_xyyyyyyz_1, g_0_zzzzz_0_xyyyyyzz_0, g_0_zzzzz_0_xyyyyyzz_1, g_0_zzzzz_0_xyyyyzzz_0, g_0_zzzzz_0_xyyyyzzz_1, g_0_zzzzz_0_xyyyzzzz_0, g_0_zzzzz_0_xyyyzzzz_1, g_0_zzzzz_0_xyyzzzzz_0, g_0_zzzzz_0_xyyzzzzz_1, g_0_zzzzz_0_xyzzzzzz_0, g_0_zzzzz_0_xyzzzzzz_1, g_0_zzzzz_0_xzzzzzzz_0, g_0_zzzzz_0_xzzzzzzz_1, g_0_zzzzz_0_yyyyyyyy_0, g_0_zzzzz_0_yyyyyyyy_1, g_0_zzzzz_0_yyyyyyyz_0, g_0_zzzzz_0_yyyyyyyz_1, g_0_zzzzz_0_yyyyyyzz_0, g_0_zzzzz_0_yyyyyyzz_1, g_0_zzzzz_0_yyyyyzzz_0, g_0_zzzzz_0_yyyyyzzz_1, g_0_zzzzz_0_yyyyzzzz_0, g_0_zzzzz_0_yyyyzzzz_1, g_0_zzzzz_0_yyyzzzzz_0, g_0_zzzzz_0_yyyzzzzz_1, g_0_zzzzz_0_yyzzzzzz_0, g_0_zzzzz_0_yyzzzzzz_1, g_0_zzzzz_0_yzzzzzzz_0, g_0_zzzzz_0_yzzzzzzz_1, g_0_zzzzz_0_zzzzzzzz_0, g_0_zzzzz_0_zzzzzzzz_1, wp_x, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_xxzzzzz_0_xxxxxxxx_0[i] = 4.0 * g_0_xxzzz_0_xxxxxxxx_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxxxxxx_0[i] * pb_z + g_0_xxzzzz_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxxxxxy_0[i] = 4.0 * g_0_xxzzz_0_xxxxxxxy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxxxxxy_0[i] * pb_z + g_0_xxzzzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxxxxxz_0[i] = g_0_zzzzz_0_xxxxxxxz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxxz_1[i] * fti_ab_0 + 7.0 * g_0_xzzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxxxz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxxxyy_0[i] = 4.0 * g_0_xxzzz_0_xxxxxxyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxxxxyy_0[i] * pb_z + g_0_xxzzzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxxxxyz_0[i] = g_0_zzzzz_0_xxxxxxyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxyz_1[i] * fti_ab_0 + 6.0 * g_0_xzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxxyz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxxxzz_0[i] = g_0_zzzzz_0_xxxxxxzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxzz_1[i] * fti_ab_0 + 6.0 * g_0_xzzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxxzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxxyyy_0[i] = 4.0 * g_0_xxzzz_0_xxxxxyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxxxyyy_0[i] * pb_z + g_0_xxzzzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxxxyyz_0[i] = g_0_zzzzz_0_xxxxxyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 5.0 * g_0_xzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxyyz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxxyzz_0[i] = g_0_zzzzz_0_xxxxxyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxyzz_1[i] * fti_ab_0 + 5.0 * g_0_xzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxyzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxxzzz_0[i] = g_0_zzzzz_0_xxxxxzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxzzz_1[i] * fti_ab_0 + 5.0 * g_0_xzzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxxzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_xxzzz_0_xxxxyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxxyyyy_0[i] * pb_z + g_0_xxzzzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxxyyyz_0[i] = g_0_zzzzz_0_xxxxyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 4.0 * g_0_xzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxyyyz_0[i] * pb_x + g_0_xzzzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxyyzz_0[i] = g_0_zzzzz_0_xxxxyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 4.0 * g_0_xzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxyyzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxyzzz_0[i] = g_0_zzzzz_0_xxxxyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyzzz_1[i] * fti_ab_0 + 4.0 * g_0_xzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxyzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxxzzzz_0[i] = g_0_zzzzz_0_xxxxzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_xzzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxxzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxyyyyy_0[i] = 4.0 * g_0_xxzzz_0_xxxyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxxyyyyy_0[i] * pb_z + g_0_xxzzzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxxyyyyz_0[i] = g_0_zzzzz_0_xxxyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 3.0 * g_0_xzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxyyyyz_0[i] * pb_x + g_0_xzzzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxyyyzz_0[i] = g_0_zzzzz_0_xxxyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_xzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxyyyzz_0[i] * pb_x + g_0_xzzzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxyyzzz_0[i] = g_0_zzzzz_0_xxxyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_xzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxyyzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxyzzzz_0[i] = g_0_zzzzz_0_xxxyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxyzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxxzzzzz_0[i] = g_0_zzzzz_0_xxxzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_xzzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxxzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxyyyyyy_0[i] = 4.0 * g_0_xxzzz_0_xxyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xxyyyyyy_0[i] * pb_z + g_0_xxzzzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xxyyyyyz_0[i] = g_0_zzzzz_0_xxyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxyyyyyz_0[i] * pb_x + g_0_xzzzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxyyyyzz_0[i] = g_0_zzzzz_0_xxyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxyyyyzz_0[i] * pb_x + g_0_xzzzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxyyyzzz_0[i] = g_0_zzzzz_0_xxyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxyyyzzz_0[i] * pb_x + g_0_xzzzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxyyzzzz_0[i] = g_0_zzzzz_0_xxyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxyyzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxyzzzzz_0[i] = g_0_zzzzz_0_xxyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxyzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xxzzzzzz_0[i] = g_0_zzzzz_0_xxzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_xzzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xxzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyyyyyyy_0[i] = 4.0 * g_0_xxzzz_0_xyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_xxzzz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_xxzzzz_0_xyyyyyyy_0[i] * pb_z + g_0_xxzzzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xxzzzzz_0_xyyyyyyz_0[i] = g_0_zzzzz_0_xyyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyyyyyyz_0[i] * pb_x + g_0_xzzzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyyyyyzz_0[i] = g_0_zzzzz_0_xyyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyyzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyyyyyzz_0[i] * pb_x + g_0_xzzzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyyyyzzz_0[i] = g_0_zzzzz_0_xyyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyyyyzzz_0[i] * pb_x + g_0_xzzzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyyyzzzz_0[i] = g_0_zzzzz_0_xyyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyyyzzzz_0[i] * pb_x + g_0_xzzzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyyzzzzz_0[i] = g_0_zzzzz_0_xyyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyyzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xyzzzzzz_0[i] = g_0_zzzzz_0_xyzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xyzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_xzzzzzzz_0[i] = g_0_zzzzz_0_xzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_xzzzzz_0_xzzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyyyyyy_0[i] = g_0_zzzzz_0_yyyyyyyy_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyyyy_0[i] * pb_x + g_0_xzzzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyyyyyz_0[i] = g_0_zzzzz_0_yyyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyyyz_0[i] * pb_x + g_0_xzzzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyyyyzz_0[i] = g_0_zzzzz_0_yyyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyyzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyyzz_0[i] * pb_x + g_0_xzzzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyyyzzz_0[i] = g_0_zzzzz_0_yyyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyyzzz_0[i] * pb_x + g_0_xzzzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyyzzzz_0[i] = g_0_zzzzz_0_yyyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyyzzzz_0[i] * pb_x + g_0_xzzzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyyzzzzz_0[i] = g_0_zzzzz_0_yyyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyyzzzzz_0[i] * pb_x + g_0_xzzzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yyzzzzzz_0[i] = g_0_zzzzz_0_yyzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyzzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yyzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_yzzzzzzz_0[i] = g_0_zzzzz_0_yzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_yzzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xxzzzzz_0_zzzzzzzz_0[i] = g_0_zzzzz_0_zzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_xzzzzz_0_zzzzzzzz_0[i] * pb_x + g_0_xzzzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 945-990 components of targeted buffer : SKSL

    auto g_0_xyyyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 945);

    auto g_0_xyyyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 946);

    auto g_0_xyyyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 947);

    auto g_0_xyyyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 948);

    auto g_0_xyyyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 949);

    auto g_0_xyyyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 950);

    auto g_0_xyyyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 951);

    auto g_0_xyyyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 952);

    auto g_0_xyyyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 953);

    auto g_0_xyyyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 954);

    auto g_0_xyyyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 955);

    auto g_0_xyyyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 956);

    auto g_0_xyyyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 957);

    auto g_0_xyyyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 958);

    auto g_0_xyyyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 959);

    auto g_0_xyyyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 960);

    auto g_0_xyyyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 961);

    auto g_0_xyyyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 962);

    auto g_0_xyyyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 963);

    auto g_0_xyyyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 964);

    auto g_0_xyyyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 965);

    auto g_0_xyyyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 966);

    auto g_0_xyyyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 967);

    auto g_0_xyyyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 968);

    auto g_0_xyyyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 969);

    auto g_0_xyyyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 970);

    auto g_0_xyyyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 971);

    auto g_0_xyyyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 972);

    auto g_0_xyyyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 973);

    auto g_0_xyyyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 974);

    auto g_0_xyyyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 975);

    auto g_0_xyyyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 976);

    auto g_0_xyyyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 977);

    auto g_0_xyyyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 978);

    auto g_0_xyyyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 979);

    auto g_0_xyyyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 980);

    auto g_0_xyyyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 981);

    auto g_0_xyyyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 982);

    auto g_0_xyyyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 983);

    auto g_0_xyyyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 984);

    auto g_0_xyyyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 985);

    auto g_0_xyyyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 986);

    auto g_0_xyyyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 987);

    auto g_0_xyyyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 988);

    auto g_0_xyyyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 989);

    #pragma omp simd aligned(g_0_xyyyyyy_0_xxxxxxxx_0, g_0_xyyyyyy_0_xxxxxxxy_0, g_0_xyyyyyy_0_xxxxxxxz_0, g_0_xyyyyyy_0_xxxxxxyy_0, g_0_xyyyyyy_0_xxxxxxyz_0, g_0_xyyyyyy_0_xxxxxxzz_0, g_0_xyyyyyy_0_xxxxxyyy_0, g_0_xyyyyyy_0_xxxxxyyz_0, g_0_xyyyyyy_0_xxxxxyzz_0, g_0_xyyyyyy_0_xxxxxzzz_0, g_0_xyyyyyy_0_xxxxyyyy_0, g_0_xyyyyyy_0_xxxxyyyz_0, g_0_xyyyyyy_0_xxxxyyzz_0, g_0_xyyyyyy_0_xxxxyzzz_0, g_0_xyyyyyy_0_xxxxzzzz_0, g_0_xyyyyyy_0_xxxyyyyy_0, g_0_xyyyyyy_0_xxxyyyyz_0, g_0_xyyyyyy_0_xxxyyyzz_0, g_0_xyyyyyy_0_xxxyyzzz_0, g_0_xyyyyyy_0_xxxyzzzz_0, g_0_xyyyyyy_0_xxxzzzzz_0, g_0_xyyyyyy_0_xxyyyyyy_0, g_0_xyyyyyy_0_xxyyyyyz_0, g_0_xyyyyyy_0_xxyyyyzz_0, g_0_xyyyyyy_0_xxyyyzzz_0, g_0_xyyyyyy_0_xxyyzzzz_0, g_0_xyyyyyy_0_xxyzzzzz_0, g_0_xyyyyyy_0_xxzzzzzz_0, g_0_xyyyyyy_0_xyyyyyyy_0, g_0_xyyyyyy_0_xyyyyyyz_0, g_0_xyyyyyy_0_xyyyyyzz_0, g_0_xyyyyyy_0_xyyyyzzz_0, g_0_xyyyyyy_0_xyyyzzzz_0, g_0_xyyyyyy_0_xyyzzzzz_0, g_0_xyyyyyy_0_xyzzzzzz_0, g_0_xyyyyyy_0_xzzzzzzz_0, g_0_xyyyyyy_0_yyyyyyyy_0, g_0_xyyyyyy_0_yyyyyyyz_0, g_0_xyyyyyy_0_yyyyyyzz_0, g_0_xyyyyyy_0_yyyyyzzz_0, g_0_xyyyyyy_0_yyyyzzzz_0, g_0_xyyyyyy_0_yyyzzzzz_0, g_0_xyyyyyy_0_yyzzzzzz_0, g_0_xyyyyyy_0_yzzzzzzz_0, g_0_xyyyyyy_0_zzzzzzzz_0, g_0_yyyyyy_0_xxxxxxx_1, g_0_yyyyyy_0_xxxxxxxx_0, g_0_yyyyyy_0_xxxxxxxx_1, g_0_yyyyyy_0_xxxxxxxy_0, g_0_yyyyyy_0_xxxxxxxy_1, g_0_yyyyyy_0_xxxxxxxz_0, g_0_yyyyyy_0_xxxxxxxz_1, g_0_yyyyyy_0_xxxxxxy_1, g_0_yyyyyy_0_xxxxxxyy_0, g_0_yyyyyy_0_xxxxxxyy_1, g_0_yyyyyy_0_xxxxxxyz_0, g_0_yyyyyy_0_xxxxxxyz_1, g_0_yyyyyy_0_xxxxxxz_1, g_0_yyyyyy_0_xxxxxxzz_0, g_0_yyyyyy_0_xxxxxxzz_1, g_0_yyyyyy_0_xxxxxyy_1, g_0_yyyyyy_0_xxxxxyyy_0, g_0_yyyyyy_0_xxxxxyyy_1, g_0_yyyyyy_0_xxxxxyyz_0, g_0_yyyyyy_0_xxxxxyyz_1, g_0_yyyyyy_0_xxxxxyz_1, g_0_yyyyyy_0_xxxxxyzz_0, g_0_yyyyyy_0_xxxxxyzz_1, g_0_yyyyyy_0_xxxxxzz_1, g_0_yyyyyy_0_xxxxxzzz_0, g_0_yyyyyy_0_xxxxxzzz_1, g_0_yyyyyy_0_xxxxyyy_1, g_0_yyyyyy_0_xxxxyyyy_0, g_0_yyyyyy_0_xxxxyyyy_1, g_0_yyyyyy_0_xxxxyyyz_0, g_0_yyyyyy_0_xxxxyyyz_1, g_0_yyyyyy_0_xxxxyyz_1, g_0_yyyyyy_0_xxxxyyzz_0, g_0_yyyyyy_0_xxxxyyzz_1, g_0_yyyyyy_0_xxxxyzz_1, g_0_yyyyyy_0_xxxxyzzz_0, g_0_yyyyyy_0_xxxxyzzz_1, g_0_yyyyyy_0_xxxxzzz_1, g_0_yyyyyy_0_xxxxzzzz_0, g_0_yyyyyy_0_xxxxzzzz_1, g_0_yyyyyy_0_xxxyyyy_1, g_0_yyyyyy_0_xxxyyyyy_0, g_0_yyyyyy_0_xxxyyyyy_1, g_0_yyyyyy_0_xxxyyyyz_0, g_0_yyyyyy_0_xxxyyyyz_1, g_0_yyyyyy_0_xxxyyyz_1, g_0_yyyyyy_0_xxxyyyzz_0, g_0_yyyyyy_0_xxxyyyzz_1, g_0_yyyyyy_0_xxxyyzz_1, g_0_yyyyyy_0_xxxyyzzz_0, g_0_yyyyyy_0_xxxyyzzz_1, g_0_yyyyyy_0_xxxyzzz_1, g_0_yyyyyy_0_xxxyzzzz_0, g_0_yyyyyy_0_xxxyzzzz_1, g_0_yyyyyy_0_xxxzzzz_1, g_0_yyyyyy_0_xxxzzzzz_0, g_0_yyyyyy_0_xxxzzzzz_1, g_0_yyyyyy_0_xxyyyyy_1, g_0_yyyyyy_0_xxyyyyyy_0, g_0_yyyyyy_0_xxyyyyyy_1, g_0_yyyyyy_0_xxyyyyyz_0, g_0_yyyyyy_0_xxyyyyyz_1, g_0_yyyyyy_0_xxyyyyz_1, g_0_yyyyyy_0_xxyyyyzz_0, g_0_yyyyyy_0_xxyyyyzz_1, g_0_yyyyyy_0_xxyyyzz_1, g_0_yyyyyy_0_xxyyyzzz_0, g_0_yyyyyy_0_xxyyyzzz_1, g_0_yyyyyy_0_xxyyzzz_1, g_0_yyyyyy_0_xxyyzzzz_0, g_0_yyyyyy_0_xxyyzzzz_1, g_0_yyyyyy_0_xxyzzzz_1, g_0_yyyyyy_0_xxyzzzzz_0, g_0_yyyyyy_0_xxyzzzzz_1, g_0_yyyyyy_0_xxzzzzz_1, g_0_yyyyyy_0_xxzzzzzz_0, g_0_yyyyyy_0_xxzzzzzz_1, g_0_yyyyyy_0_xyyyyyy_1, g_0_yyyyyy_0_xyyyyyyy_0, g_0_yyyyyy_0_xyyyyyyy_1, g_0_yyyyyy_0_xyyyyyyz_0, g_0_yyyyyy_0_xyyyyyyz_1, g_0_yyyyyy_0_xyyyyyz_1, g_0_yyyyyy_0_xyyyyyzz_0, g_0_yyyyyy_0_xyyyyyzz_1, g_0_yyyyyy_0_xyyyyzz_1, g_0_yyyyyy_0_xyyyyzzz_0, g_0_yyyyyy_0_xyyyyzzz_1, g_0_yyyyyy_0_xyyyzzz_1, g_0_yyyyyy_0_xyyyzzzz_0, g_0_yyyyyy_0_xyyyzzzz_1, g_0_yyyyyy_0_xyyzzzz_1, g_0_yyyyyy_0_xyyzzzzz_0, g_0_yyyyyy_0_xyyzzzzz_1, g_0_yyyyyy_0_xyzzzzz_1, g_0_yyyyyy_0_xyzzzzzz_0, g_0_yyyyyy_0_xyzzzzzz_1, g_0_yyyyyy_0_xzzzzzz_1, g_0_yyyyyy_0_xzzzzzzz_0, g_0_yyyyyy_0_xzzzzzzz_1, g_0_yyyyyy_0_yyyyyyy_1, g_0_yyyyyy_0_yyyyyyyy_0, g_0_yyyyyy_0_yyyyyyyy_1, g_0_yyyyyy_0_yyyyyyyz_0, g_0_yyyyyy_0_yyyyyyyz_1, g_0_yyyyyy_0_yyyyyyz_1, g_0_yyyyyy_0_yyyyyyzz_0, g_0_yyyyyy_0_yyyyyyzz_1, g_0_yyyyyy_0_yyyyyzz_1, g_0_yyyyyy_0_yyyyyzzz_0, g_0_yyyyyy_0_yyyyyzzz_1, g_0_yyyyyy_0_yyyyzzz_1, g_0_yyyyyy_0_yyyyzzzz_0, g_0_yyyyyy_0_yyyyzzzz_1, g_0_yyyyyy_0_yyyzzzz_1, g_0_yyyyyy_0_yyyzzzzz_0, g_0_yyyyyy_0_yyyzzzzz_1, g_0_yyyyyy_0_yyzzzzz_1, g_0_yyyyyy_0_yyzzzzzz_0, g_0_yyyyyy_0_yyzzzzzz_1, g_0_yyyyyy_0_yzzzzzz_1, g_0_yyyyyy_0_yzzzzzzz_0, g_0_yyyyyy_0_yzzzzzzz_1, g_0_yyyyyy_0_zzzzzzz_1, g_0_yyyyyy_0_zzzzzzzz_0, g_0_yyyyyy_0_zzzzzzzz_1, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyyyyyy_0_xxxxxxxx_0[i] = 8.0 * g_0_yyyyyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxxx_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxxxy_0[i] = 7.0 * g_0_yyyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxxy_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxxxz_0[i] = 7.0 * g_0_yyyyyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxxz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxxyy_0[i] = 6.0 * g_0_yyyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxyy_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxxyz_0[i] = 6.0 * g_0_yyyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxyz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxxzz_0[i] = 6.0 * g_0_yyyyyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxyyy_0[i] = 5.0 * g_0_yyyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyyy_0[i] * pb_x + g_0_yyyyyy_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxyyz_0[i] = 5.0 * g_0_yyyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyyz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxyzz_0[i] = 5.0 * g_0_yyyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxxzzz_0[i] = 5.0 * g_0_yyyyyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxyyyy_0[i] = 4.0 * g_0_yyyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyyy_0[i] * pb_x + g_0_yyyyyy_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxyyyz_0[i] = 4.0 * g_0_yyyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyyz_0[i] * pb_x + g_0_yyyyyy_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxyyzz_0[i] = 4.0 * g_0_yyyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxyzzz_0[i] = 4.0 * g_0_yyyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyyyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxyyyyy_0[i] = 3.0 * g_0_yyyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyyy_0[i] * pb_x + g_0_yyyyyy_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxyyyyz_0[i] = 3.0 * g_0_yyyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyyz_0[i] * pb_x + g_0_yyyyyy_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxyyyzz_0[i] = 3.0 * g_0_yyyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyzz_0[i] * pb_x + g_0_yyyyyy_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxyyzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxyzzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxxzzzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyyyyyy_0[i] = 2.0 * g_0_yyyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyyy_0[i] * pb_x + g_0_yyyyyy_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyyyyyz_0[i] = 2.0 * g_0_yyyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyyz_0[i] * pb_x + g_0_yyyyyy_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyyyyzz_0[i] = 2.0 * g_0_yyyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyzz_0[i] * pb_x + g_0_yyyyyy_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyyyzzz_0[i] = 2.0 * g_0_yyyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyzzz_0[i] * pb_x + g_0_yyyyyy_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyyzzzz_0[i] = 2.0 * g_0_yyyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxyzzzzz_0[i] = 2.0 * g_0_yyyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xxzzzzzz_0[i] = 2.0 * g_0_yyyyyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyyyyyy_0[i] = g_0_yyyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyyy_0[i] * pb_x + g_0_yyyyyy_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyyyyyz_0[i] = g_0_yyyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyyz_0[i] * pb_x + g_0_yyyyyy_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyyyyzz_0[i] = g_0_yyyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyzz_0[i] * pb_x + g_0_yyyyyy_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyyyzzz_0[i] = g_0_yyyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyzzz_0[i] * pb_x + g_0_yyyyyy_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyyzzzz_0[i] = g_0_yyyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyzzzz_0[i] * pb_x + g_0_yyyyyy_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyyzzzzz_0[i] = g_0_yyyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xyzzzzzz_0[i] = g_0_yyyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_xzzzzzzz_0[i] = g_0_yyyyyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xzzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyyyyyy_0[i] = g_0_yyyyyy_0_yyyyyyyy_0[i] * pb_x + g_0_yyyyyy_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyyyyyz_0[i] = g_0_yyyyyy_0_yyyyyyyz_0[i] * pb_x + g_0_yyyyyy_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyyyyzz_0[i] = g_0_yyyyyy_0_yyyyyyzz_0[i] * pb_x + g_0_yyyyyy_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyyyzzz_0[i] = g_0_yyyyyy_0_yyyyyzzz_0[i] * pb_x + g_0_yyyyyy_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyyzzzz_0[i] = g_0_yyyyyy_0_yyyyzzzz_0[i] * pb_x + g_0_yyyyyy_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyyzzzzz_0[i] = g_0_yyyyyy_0_yyyzzzzz_0[i] * pb_x + g_0_yyyyyy_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yyzzzzzz_0[i] = g_0_yyyyyy_0_yyzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_yzzzzzzz_0[i] = g_0_yyyyyy_0_yzzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyy_0_zzzzzzzz_0[i] = g_0_yyyyyy_0_zzzzzzzz_0[i] * pb_x + g_0_yyyyyy_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 990-1035 components of targeted buffer : SKSL

    auto g_0_xyyyyyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 990);

    auto g_0_xyyyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 991);

    auto g_0_xyyyyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 992);

    auto g_0_xyyyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 993);

    auto g_0_xyyyyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 994);

    auto g_0_xyyyyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 995);

    auto g_0_xyyyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 996);

    auto g_0_xyyyyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 997);

    auto g_0_xyyyyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 998);

    auto g_0_xyyyyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 999);

    auto g_0_xyyyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1000);

    auto g_0_xyyyyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1001);

    auto g_0_xyyyyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1002);

    auto g_0_xyyyyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1003);

    auto g_0_xyyyyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1004);

    auto g_0_xyyyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1005);

    auto g_0_xyyyyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1006);

    auto g_0_xyyyyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1007);

    auto g_0_xyyyyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1008);

    auto g_0_xyyyyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1009);

    auto g_0_xyyyyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1010);

    auto g_0_xyyyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1011);

    auto g_0_xyyyyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1012);

    auto g_0_xyyyyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1013);

    auto g_0_xyyyyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1014);

    auto g_0_xyyyyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1015);

    auto g_0_xyyyyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1016);

    auto g_0_xyyyyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1017);

    auto g_0_xyyyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1018);

    auto g_0_xyyyyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1019);

    auto g_0_xyyyyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1020);

    auto g_0_xyyyyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1021);

    auto g_0_xyyyyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1022);

    auto g_0_xyyyyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1023);

    auto g_0_xyyyyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1024);

    auto g_0_xyyyyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1025);

    auto g_0_xyyyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1026);

    auto g_0_xyyyyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1027);

    auto g_0_xyyyyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1028);

    auto g_0_xyyyyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1029);

    auto g_0_xyyyyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1030);

    auto g_0_xyyyyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1031);

    auto g_0_xyyyyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1032);

    auto g_0_xyyyyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1033);

    auto g_0_xyyyyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1034);

    #pragma omp simd aligned(g_0_xyyyyy_0_xxxxxxxx_0, g_0_xyyyyy_0_xxxxxxxx_1, g_0_xyyyyy_0_xxxxxxxy_0, g_0_xyyyyy_0_xxxxxxxy_1, g_0_xyyyyy_0_xxxxxxyy_0, g_0_xyyyyy_0_xxxxxxyy_1, g_0_xyyyyy_0_xxxxxyyy_0, g_0_xyyyyy_0_xxxxxyyy_1, g_0_xyyyyy_0_xxxxyyyy_0, g_0_xyyyyy_0_xxxxyyyy_1, g_0_xyyyyy_0_xxxyyyyy_0, g_0_xyyyyy_0_xxxyyyyy_1, g_0_xyyyyy_0_xxyyyyyy_0, g_0_xyyyyy_0_xxyyyyyy_1, g_0_xyyyyy_0_xyyyyyyy_0, g_0_xyyyyy_0_xyyyyyyy_1, g_0_xyyyyyz_0_xxxxxxxx_0, g_0_xyyyyyz_0_xxxxxxxy_0, g_0_xyyyyyz_0_xxxxxxxz_0, g_0_xyyyyyz_0_xxxxxxyy_0, g_0_xyyyyyz_0_xxxxxxyz_0, g_0_xyyyyyz_0_xxxxxxzz_0, g_0_xyyyyyz_0_xxxxxyyy_0, g_0_xyyyyyz_0_xxxxxyyz_0, g_0_xyyyyyz_0_xxxxxyzz_0, g_0_xyyyyyz_0_xxxxxzzz_0, g_0_xyyyyyz_0_xxxxyyyy_0, g_0_xyyyyyz_0_xxxxyyyz_0, g_0_xyyyyyz_0_xxxxyyzz_0, g_0_xyyyyyz_0_xxxxyzzz_0, g_0_xyyyyyz_0_xxxxzzzz_0, g_0_xyyyyyz_0_xxxyyyyy_0, g_0_xyyyyyz_0_xxxyyyyz_0, g_0_xyyyyyz_0_xxxyyyzz_0, g_0_xyyyyyz_0_xxxyyzzz_0, g_0_xyyyyyz_0_xxxyzzzz_0, g_0_xyyyyyz_0_xxxzzzzz_0, g_0_xyyyyyz_0_xxyyyyyy_0, g_0_xyyyyyz_0_xxyyyyyz_0, g_0_xyyyyyz_0_xxyyyyzz_0, g_0_xyyyyyz_0_xxyyyzzz_0, g_0_xyyyyyz_0_xxyyzzzz_0, g_0_xyyyyyz_0_xxyzzzzz_0, g_0_xyyyyyz_0_xxzzzzzz_0, g_0_xyyyyyz_0_xyyyyyyy_0, g_0_xyyyyyz_0_xyyyyyyz_0, g_0_xyyyyyz_0_xyyyyyzz_0, g_0_xyyyyyz_0_xyyyyzzz_0, g_0_xyyyyyz_0_xyyyzzzz_0, g_0_xyyyyyz_0_xyyzzzzz_0, g_0_xyyyyyz_0_xyzzzzzz_0, g_0_xyyyyyz_0_xzzzzzzz_0, g_0_xyyyyyz_0_yyyyyyyy_0, g_0_xyyyyyz_0_yyyyyyyz_0, g_0_xyyyyyz_0_yyyyyyzz_0, g_0_xyyyyyz_0_yyyyyzzz_0, g_0_xyyyyyz_0_yyyyzzzz_0, g_0_xyyyyyz_0_yyyzzzzz_0, g_0_xyyyyyz_0_yyzzzzzz_0, g_0_xyyyyyz_0_yzzzzzzz_0, g_0_xyyyyyz_0_zzzzzzzz_0, g_0_yyyyyz_0_xxxxxxxz_0, g_0_yyyyyz_0_xxxxxxxz_1, g_0_yyyyyz_0_xxxxxxyz_0, g_0_yyyyyz_0_xxxxxxyz_1, g_0_yyyyyz_0_xxxxxxz_1, g_0_yyyyyz_0_xxxxxxzz_0, g_0_yyyyyz_0_xxxxxxzz_1, g_0_yyyyyz_0_xxxxxyyz_0, g_0_yyyyyz_0_xxxxxyyz_1, g_0_yyyyyz_0_xxxxxyz_1, g_0_yyyyyz_0_xxxxxyzz_0, g_0_yyyyyz_0_xxxxxyzz_1, g_0_yyyyyz_0_xxxxxzz_1, g_0_yyyyyz_0_xxxxxzzz_0, g_0_yyyyyz_0_xxxxxzzz_1, g_0_yyyyyz_0_xxxxyyyz_0, g_0_yyyyyz_0_xxxxyyyz_1, g_0_yyyyyz_0_xxxxyyz_1, g_0_yyyyyz_0_xxxxyyzz_0, g_0_yyyyyz_0_xxxxyyzz_1, g_0_yyyyyz_0_xxxxyzz_1, g_0_yyyyyz_0_xxxxyzzz_0, g_0_yyyyyz_0_xxxxyzzz_1, g_0_yyyyyz_0_xxxxzzz_1, g_0_yyyyyz_0_xxxxzzzz_0, g_0_yyyyyz_0_xxxxzzzz_1, g_0_yyyyyz_0_xxxyyyyz_0, g_0_yyyyyz_0_xxxyyyyz_1, g_0_yyyyyz_0_xxxyyyz_1, g_0_yyyyyz_0_xxxyyyzz_0, g_0_yyyyyz_0_xxxyyyzz_1, g_0_yyyyyz_0_xxxyyzz_1, g_0_yyyyyz_0_xxxyyzzz_0, g_0_yyyyyz_0_xxxyyzzz_1, g_0_yyyyyz_0_xxxyzzz_1, g_0_yyyyyz_0_xxxyzzzz_0, g_0_yyyyyz_0_xxxyzzzz_1, g_0_yyyyyz_0_xxxzzzz_1, g_0_yyyyyz_0_xxxzzzzz_0, g_0_yyyyyz_0_xxxzzzzz_1, g_0_yyyyyz_0_xxyyyyyz_0, g_0_yyyyyz_0_xxyyyyyz_1, g_0_yyyyyz_0_xxyyyyz_1, g_0_yyyyyz_0_xxyyyyzz_0, g_0_yyyyyz_0_xxyyyyzz_1, g_0_yyyyyz_0_xxyyyzz_1, g_0_yyyyyz_0_xxyyyzzz_0, g_0_yyyyyz_0_xxyyyzzz_1, g_0_yyyyyz_0_xxyyzzz_1, g_0_yyyyyz_0_xxyyzzzz_0, g_0_yyyyyz_0_xxyyzzzz_1, g_0_yyyyyz_0_xxyzzzz_1, g_0_yyyyyz_0_xxyzzzzz_0, g_0_yyyyyz_0_xxyzzzzz_1, g_0_yyyyyz_0_xxzzzzz_1, g_0_yyyyyz_0_xxzzzzzz_0, g_0_yyyyyz_0_xxzzzzzz_1, g_0_yyyyyz_0_xyyyyyyz_0, g_0_yyyyyz_0_xyyyyyyz_1, g_0_yyyyyz_0_xyyyyyz_1, g_0_yyyyyz_0_xyyyyyzz_0, g_0_yyyyyz_0_xyyyyyzz_1, g_0_yyyyyz_0_xyyyyzz_1, g_0_yyyyyz_0_xyyyyzzz_0, g_0_yyyyyz_0_xyyyyzzz_1, g_0_yyyyyz_0_xyyyzzz_1, g_0_yyyyyz_0_xyyyzzzz_0, g_0_yyyyyz_0_xyyyzzzz_1, g_0_yyyyyz_0_xyyzzzz_1, g_0_yyyyyz_0_xyyzzzzz_0, g_0_yyyyyz_0_xyyzzzzz_1, g_0_yyyyyz_0_xyzzzzz_1, g_0_yyyyyz_0_xyzzzzzz_0, g_0_yyyyyz_0_xyzzzzzz_1, g_0_yyyyyz_0_xzzzzzz_1, g_0_yyyyyz_0_xzzzzzzz_0, g_0_yyyyyz_0_xzzzzzzz_1, g_0_yyyyyz_0_yyyyyyyy_0, g_0_yyyyyz_0_yyyyyyyy_1, g_0_yyyyyz_0_yyyyyyyz_0, g_0_yyyyyz_0_yyyyyyyz_1, g_0_yyyyyz_0_yyyyyyz_1, g_0_yyyyyz_0_yyyyyyzz_0, g_0_yyyyyz_0_yyyyyyzz_1, g_0_yyyyyz_0_yyyyyzz_1, g_0_yyyyyz_0_yyyyyzzz_0, g_0_yyyyyz_0_yyyyyzzz_1, g_0_yyyyyz_0_yyyyzzz_1, g_0_yyyyyz_0_yyyyzzzz_0, g_0_yyyyyz_0_yyyyzzzz_1, g_0_yyyyyz_0_yyyzzzz_1, g_0_yyyyyz_0_yyyzzzzz_0, g_0_yyyyyz_0_yyyzzzzz_1, g_0_yyyyyz_0_yyzzzzz_1, g_0_yyyyyz_0_yyzzzzzz_0, g_0_yyyyyz_0_yyzzzzzz_1, g_0_yyyyyz_0_yzzzzzz_1, g_0_yyyyyz_0_yzzzzzzz_0, g_0_yyyyyz_0_yzzzzzzz_1, g_0_yyyyyz_0_zzzzzzz_1, g_0_yyyyyz_0_zzzzzzzz_0, g_0_yyyyyz_0_zzzzzzzz_1, wp_x, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyyyyyz_0_xxxxxxxx_0[i] = g_0_xyyyyy_0_xxxxxxxx_0[i] * pb_z + g_0_xyyyyy_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxxxxxy_0[i] = g_0_xyyyyy_0_xxxxxxxy_0[i] * pb_z + g_0_xyyyyy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxxxxxz_0[i] = 7.0 * g_0_yyyyyz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxxxz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxxxyy_0[i] = g_0_xyyyyy_0_xxxxxxyy_0[i] * pb_z + g_0_xyyyyy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxxxxyz_0[i] = 6.0 * g_0_yyyyyz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxxyz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxxxzz_0[i] = 6.0 * g_0_yyyyyz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxxzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxxyyy_0[i] = g_0_xyyyyy_0_xxxxxyyy_0[i] * pb_z + g_0_xyyyyy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxxxyyz_0[i] = 5.0 * g_0_yyyyyz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxyyz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxxyzz_0[i] = 5.0 * g_0_yyyyyz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxyzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxxzzz_0[i] = 5.0 * g_0_yyyyyz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxxzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxyyyy_0[i] = g_0_xyyyyy_0_xxxxyyyy_0[i] * pb_z + g_0_xyyyyy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxxyyyz_0[i] = 4.0 * g_0_yyyyyz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxyyyz_0[i] * pb_x + g_0_yyyyyz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxyyzz_0[i] = 4.0 * g_0_yyyyyz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxyyzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxyzzz_0[i] = 4.0 * g_0_yyyyyz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxyzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyyyz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxxzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxyyyyy_0[i] = g_0_xyyyyy_0_xxxyyyyy_0[i] * pb_z + g_0_xyyyyy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxxyyyyz_0[i] = 3.0 * g_0_yyyyyz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxyyyyz_0[i] * pb_x + g_0_yyyyyz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxyyyzz_0[i] = 3.0 * g_0_yyyyyz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxyyyzz_0[i] * pb_x + g_0_yyyyyz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyyyyz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxyyzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxyzzzz_0[i] = 3.0 * g_0_yyyyyz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxyzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxxzzzzz_0[i] = 3.0 * g_0_yyyyyz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxxzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxyyyyyy_0[i] = g_0_xyyyyy_0_xxyyyyyy_0[i] * pb_z + g_0_xyyyyy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xxyyyyyz_0[i] = 2.0 * g_0_yyyyyz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxyyyyyz_0[i] * pb_x + g_0_yyyyyz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxyyyyzz_0[i] = 2.0 * g_0_yyyyyz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxyyyyzz_0[i] * pb_x + g_0_yyyyyz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxyyyzzz_0[i] = 2.0 * g_0_yyyyyz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxyyyzzz_0[i] * pb_x + g_0_yyyyyz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxyyzzzz_0[i] = 2.0 * g_0_yyyyyz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxyyzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxyzzzzz_0[i] = 2.0 * g_0_yyyyyz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxyzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xxzzzzzz_0[i] = 2.0 * g_0_yyyyyz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xxzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyyyyyyy_0[i] = g_0_xyyyyy_0_xyyyyyyy_0[i] * pb_z + g_0_xyyyyy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_xyyyyyz_0_xyyyyyyz_0[i] = g_0_yyyyyz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyyyyyyz_0[i] * pb_x + g_0_yyyyyz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyyyyyzz_0[i] = g_0_yyyyyz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyyyyyzz_0[i] * pb_x + g_0_yyyyyz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyyyyzzz_0[i] = g_0_yyyyyz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyyyyzzz_0[i] * pb_x + g_0_yyyyyz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyyyzzzz_0[i] = g_0_yyyyyz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyyyzzzz_0[i] * pb_x + g_0_yyyyyz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyyzzzzz_0[i] = g_0_yyyyyz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyyzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xyzzzzzz_0[i] = g_0_yyyyyz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xyzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_xzzzzzzz_0[i] = g_0_yyyyyz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyz_0_xzzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyyyyyy_0[i] = g_0_yyyyyz_0_yyyyyyyy_0[i] * pb_x + g_0_yyyyyz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyyyyyz_0[i] = g_0_yyyyyz_0_yyyyyyyz_0[i] * pb_x + g_0_yyyyyz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyyyyzz_0[i] = g_0_yyyyyz_0_yyyyyyzz_0[i] * pb_x + g_0_yyyyyz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyyyzzz_0[i] = g_0_yyyyyz_0_yyyyyzzz_0[i] * pb_x + g_0_yyyyyz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyyzzzz_0[i] = g_0_yyyyyz_0_yyyyzzzz_0[i] * pb_x + g_0_yyyyyz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyyzzzzz_0[i] = g_0_yyyyyz_0_yyyzzzzz_0[i] * pb_x + g_0_yyyyyz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yyzzzzzz_0[i] = g_0_yyyyyz_0_yyzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_yzzzzzzz_0[i] = g_0_yyyyyz_0_yzzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyyz_0_zzzzzzzz_0[i] = g_0_yyyyyz_0_zzzzzzzz_0[i] * pb_x + g_0_yyyyyz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1035-1080 components of targeted buffer : SKSL

    auto g_0_xyyyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1035);

    auto g_0_xyyyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1036);

    auto g_0_xyyyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1037);

    auto g_0_xyyyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1038);

    auto g_0_xyyyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1039);

    auto g_0_xyyyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1040);

    auto g_0_xyyyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1041);

    auto g_0_xyyyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1042);

    auto g_0_xyyyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1043);

    auto g_0_xyyyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1044);

    auto g_0_xyyyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1045);

    auto g_0_xyyyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1046);

    auto g_0_xyyyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1047);

    auto g_0_xyyyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1048);

    auto g_0_xyyyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1049);

    auto g_0_xyyyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1050);

    auto g_0_xyyyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1051);

    auto g_0_xyyyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1052);

    auto g_0_xyyyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1053);

    auto g_0_xyyyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1054);

    auto g_0_xyyyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1055);

    auto g_0_xyyyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1056);

    auto g_0_xyyyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1057);

    auto g_0_xyyyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1058);

    auto g_0_xyyyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1059);

    auto g_0_xyyyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1060);

    auto g_0_xyyyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1061);

    auto g_0_xyyyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1062);

    auto g_0_xyyyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1063);

    auto g_0_xyyyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1064);

    auto g_0_xyyyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1065);

    auto g_0_xyyyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1066);

    auto g_0_xyyyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1067);

    auto g_0_xyyyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1068);

    auto g_0_xyyyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1069);

    auto g_0_xyyyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1070);

    auto g_0_xyyyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1071);

    auto g_0_xyyyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1072);

    auto g_0_xyyyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1073);

    auto g_0_xyyyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1074);

    auto g_0_xyyyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1075);

    auto g_0_xyyyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1076);

    auto g_0_xyyyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1077);

    auto g_0_xyyyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1078);

    auto g_0_xyyyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1079);

    #pragma omp simd aligned(g_0_xyyyyzz_0_xxxxxxxx_0, g_0_xyyyyzz_0_xxxxxxxy_0, g_0_xyyyyzz_0_xxxxxxxz_0, g_0_xyyyyzz_0_xxxxxxyy_0, g_0_xyyyyzz_0_xxxxxxyz_0, g_0_xyyyyzz_0_xxxxxxzz_0, g_0_xyyyyzz_0_xxxxxyyy_0, g_0_xyyyyzz_0_xxxxxyyz_0, g_0_xyyyyzz_0_xxxxxyzz_0, g_0_xyyyyzz_0_xxxxxzzz_0, g_0_xyyyyzz_0_xxxxyyyy_0, g_0_xyyyyzz_0_xxxxyyyz_0, g_0_xyyyyzz_0_xxxxyyzz_0, g_0_xyyyyzz_0_xxxxyzzz_0, g_0_xyyyyzz_0_xxxxzzzz_0, g_0_xyyyyzz_0_xxxyyyyy_0, g_0_xyyyyzz_0_xxxyyyyz_0, g_0_xyyyyzz_0_xxxyyyzz_0, g_0_xyyyyzz_0_xxxyyzzz_0, g_0_xyyyyzz_0_xxxyzzzz_0, g_0_xyyyyzz_0_xxxzzzzz_0, g_0_xyyyyzz_0_xxyyyyyy_0, g_0_xyyyyzz_0_xxyyyyyz_0, g_0_xyyyyzz_0_xxyyyyzz_0, g_0_xyyyyzz_0_xxyyyzzz_0, g_0_xyyyyzz_0_xxyyzzzz_0, g_0_xyyyyzz_0_xxyzzzzz_0, g_0_xyyyyzz_0_xxzzzzzz_0, g_0_xyyyyzz_0_xyyyyyyy_0, g_0_xyyyyzz_0_xyyyyyyz_0, g_0_xyyyyzz_0_xyyyyyzz_0, g_0_xyyyyzz_0_xyyyyzzz_0, g_0_xyyyyzz_0_xyyyzzzz_0, g_0_xyyyyzz_0_xyyzzzzz_0, g_0_xyyyyzz_0_xyzzzzzz_0, g_0_xyyyyzz_0_xzzzzzzz_0, g_0_xyyyyzz_0_yyyyyyyy_0, g_0_xyyyyzz_0_yyyyyyyz_0, g_0_xyyyyzz_0_yyyyyyzz_0, g_0_xyyyyzz_0_yyyyyzzz_0, g_0_xyyyyzz_0_yyyyzzzz_0, g_0_xyyyyzz_0_yyyzzzzz_0, g_0_xyyyyzz_0_yyzzzzzz_0, g_0_xyyyyzz_0_yzzzzzzz_0, g_0_xyyyyzz_0_zzzzzzzz_0, g_0_yyyyzz_0_xxxxxxx_1, g_0_yyyyzz_0_xxxxxxxx_0, g_0_yyyyzz_0_xxxxxxxx_1, g_0_yyyyzz_0_xxxxxxxy_0, g_0_yyyyzz_0_xxxxxxxy_1, g_0_yyyyzz_0_xxxxxxxz_0, g_0_yyyyzz_0_xxxxxxxz_1, g_0_yyyyzz_0_xxxxxxy_1, g_0_yyyyzz_0_xxxxxxyy_0, g_0_yyyyzz_0_xxxxxxyy_1, g_0_yyyyzz_0_xxxxxxyz_0, g_0_yyyyzz_0_xxxxxxyz_1, g_0_yyyyzz_0_xxxxxxz_1, g_0_yyyyzz_0_xxxxxxzz_0, g_0_yyyyzz_0_xxxxxxzz_1, g_0_yyyyzz_0_xxxxxyy_1, g_0_yyyyzz_0_xxxxxyyy_0, g_0_yyyyzz_0_xxxxxyyy_1, g_0_yyyyzz_0_xxxxxyyz_0, g_0_yyyyzz_0_xxxxxyyz_1, g_0_yyyyzz_0_xxxxxyz_1, g_0_yyyyzz_0_xxxxxyzz_0, g_0_yyyyzz_0_xxxxxyzz_1, g_0_yyyyzz_0_xxxxxzz_1, g_0_yyyyzz_0_xxxxxzzz_0, g_0_yyyyzz_0_xxxxxzzz_1, g_0_yyyyzz_0_xxxxyyy_1, g_0_yyyyzz_0_xxxxyyyy_0, g_0_yyyyzz_0_xxxxyyyy_1, g_0_yyyyzz_0_xxxxyyyz_0, g_0_yyyyzz_0_xxxxyyyz_1, g_0_yyyyzz_0_xxxxyyz_1, g_0_yyyyzz_0_xxxxyyzz_0, g_0_yyyyzz_0_xxxxyyzz_1, g_0_yyyyzz_0_xxxxyzz_1, g_0_yyyyzz_0_xxxxyzzz_0, g_0_yyyyzz_0_xxxxyzzz_1, g_0_yyyyzz_0_xxxxzzz_1, g_0_yyyyzz_0_xxxxzzzz_0, g_0_yyyyzz_0_xxxxzzzz_1, g_0_yyyyzz_0_xxxyyyy_1, g_0_yyyyzz_0_xxxyyyyy_0, g_0_yyyyzz_0_xxxyyyyy_1, g_0_yyyyzz_0_xxxyyyyz_0, g_0_yyyyzz_0_xxxyyyyz_1, g_0_yyyyzz_0_xxxyyyz_1, g_0_yyyyzz_0_xxxyyyzz_0, g_0_yyyyzz_0_xxxyyyzz_1, g_0_yyyyzz_0_xxxyyzz_1, g_0_yyyyzz_0_xxxyyzzz_0, g_0_yyyyzz_0_xxxyyzzz_1, g_0_yyyyzz_0_xxxyzzz_1, g_0_yyyyzz_0_xxxyzzzz_0, g_0_yyyyzz_0_xxxyzzzz_1, g_0_yyyyzz_0_xxxzzzz_1, g_0_yyyyzz_0_xxxzzzzz_0, g_0_yyyyzz_0_xxxzzzzz_1, g_0_yyyyzz_0_xxyyyyy_1, g_0_yyyyzz_0_xxyyyyyy_0, g_0_yyyyzz_0_xxyyyyyy_1, g_0_yyyyzz_0_xxyyyyyz_0, g_0_yyyyzz_0_xxyyyyyz_1, g_0_yyyyzz_0_xxyyyyz_1, g_0_yyyyzz_0_xxyyyyzz_0, g_0_yyyyzz_0_xxyyyyzz_1, g_0_yyyyzz_0_xxyyyzz_1, g_0_yyyyzz_0_xxyyyzzz_0, g_0_yyyyzz_0_xxyyyzzz_1, g_0_yyyyzz_0_xxyyzzz_1, g_0_yyyyzz_0_xxyyzzzz_0, g_0_yyyyzz_0_xxyyzzzz_1, g_0_yyyyzz_0_xxyzzzz_1, g_0_yyyyzz_0_xxyzzzzz_0, g_0_yyyyzz_0_xxyzzzzz_1, g_0_yyyyzz_0_xxzzzzz_1, g_0_yyyyzz_0_xxzzzzzz_0, g_0_yyyyzz_0_xxzzzzzz_1, g_0_yyyyzz_0_xyyyyyy_1, g_0_yyyyzz_0_xyyyyyyy_0, g_0_yyyyzz_0_xyyyyyyy_1, g_0_yyyyzz_0_xyyyyyyz_0, g_0_yyyyzz_0_xyyyyyyz_1, g_0_yyyyzz_0_xyyyyyz_1, g_0_yyyyzz_0_xyyyyyzz_0, g_0_yyyyzz_0_xyyyyyzz_1, g_0_yyyyzz_0_xyyyyzz_1, g_0_yyyyzz_0_xyyyyzzz_0, g_0_yyyyzz_0_xyyyyzzz_1, g_0_yyyyzz_0_xyyyzzz_1, g_0_yyyyzz_0_xyyyzzzz_0, g_0_yyyyzz_0_xyyyzzzz_1, g_0_yyyyzz_0_xyyzzzz_1, g_0_yyyyzz_0_xyyzzzzz_0, g_0_yyyyzz_0_xyyzzzzz_1, g_0_yyyyzz_0_xyzzzzz_1, g_0_yyyyzz_0_xyzzzzzz_0, g_0_yyyyzz_0_xyzzzzzz_1, g_0_yyyyzz_0_xzzzzzz_1, g_0_yyyyzz_0_xzzzzzzz_0, g_0_yyyyzz_0_xzzzzzzz_1, g_0_yyyyzz_0_yyyyyyy_1, g_0_yyyyzz_0_yyyyyyyy_0, g_0_yyyyzz_0_yyyyyyyy_1, g_0_yyyyzz_0_yyyyyyyz_0, g_0_yyyyzz_0_yyyyyyyz_1, g_0_yyyyzz_0_yyyyyyz_1, g_0_yyyyzz_0_yyyyyyzz_0, g_0_yyyyzz_0_yyyyyyzz_1, g_0_yyyyzz_0_yyyyyzz_1, g_0_yyyyzz_0_yyyyyzzz_0, g_0_yyyyzz_0_yyyyyzzz_1, g_0_yyyyzz_0_yyyyzzz_1, g_0_yyyyzz_0_yyyyzzzz_0, g_0_yyyyzz_0_yyyyzzzz_1, g_0_yyyyzz_0_yyyzzzz_1, g_0_yyyyzz_0_yyyzzzzz_0, g_0_yyyyzz_0_yyyzzzzz_1, g_0_yyyyzz_0_yyzzzzz_1, g_0_yyyyzz_0_yyzzzzzz_0, g_0_yyyyzz_0_yyzzzzzz_1, g_0_yyyyzz_0_yzzzzzz_1, g_0_yyyyzz_0_yzzzzzzz_0, g_0_yyyyzz_0_yzzzzzzz_1, g_0_yyyyzz_0_zzzzzzz_1, g_0_yyyyzz_0_zzzzzzzz_0, g_0_yyyyzz_0_zzzzzzzz_1, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyyyyzz_0_xxxxxxxx_0[i] = 8.0 * g_0_yyyyzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxxx_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxxxy_0[i] = 7.0 * g_0_yyyyzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxxy_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxxxz_0[i] = 7.0 * g_0_yyyyzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxxz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxxyy_0[i] = 6.0 * g_0_yyyyzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxyy_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxxyz_0[i] = 6.0 * g_0_yyyyzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxyz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxxzz_0[i] = 6.0 * g_0_yyyyzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxyyy_0[i] = 5.0 * g_0_yyyyzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxyyy_0[i] * pb_x + g_0_yyyyzz_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxyyz_0[i] = 5.0 * g_0_yyyyzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxyyz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxyzz_0[i] = 5.0 * g_0_yyyyzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxyzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxxzzz_0[i] = 5.0 * g_0_yyyyzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxyyyy_0[i] = 4.0 * g_0_yyyyzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyyyy_0[i] * pb_x + g_0_yyyyzz_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxyyyz_0[i] = 4.0 * g_0_yyyyzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyyyz_0[i] * pb_x + g_0_yyyyzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxyyzz_0[i] = 4.0 * g_0_yyyyzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyyzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxyzzz_0[i] = 4.0 * g_0_yyyyzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyyzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxyyyyy_0[i] = 3.0 * g_0_yyyyzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyyyy_0[i] * pb_x + g_0_yyyyzz_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxyyyyz_0[i] = 3.0 * g_0_yyyyzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyyyz_0[i] * pb_x + g_0_yyyyzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxyyyzz_0[i] = 3.0 * g_0_yyyyzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyyzz_0[i] * pb_x + g_0_yyyyzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyyyzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxyzzzz_0[i] = 3.0 * g_0_yyyyzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxxzzzzz_0[i] = 3.0 * g_0_yyyyzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyyyyyy_0[i] = 2.0 * g_0_yyyyzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyyyy_0[i] * pb_x + g_0_yyyyzz_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyyyyyz_0[i] = 2.0 * g_0_yyyyzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyyyz_0[i] * pb_x + g_0_yyyyzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyyyyzz_0[i] = 2.0 * g_0_yyyyzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyyzz_0[i] * pb_x + g_0_yyyyzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyyyzzz_0[i] = 2.0 * g_0_yyyyzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyzzz_0[i] * pb_x + g_0_yyyyzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyyzzzz_0[i] = 2.0 * g_0_yyyyzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxyzzzzz_0[i] = 2.0 * g_0_yyyyzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xxzzzzzz_0[i] = 2.0 * g_0_yyyyzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyyyyyy_0[i] = g_0_yyyyzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyyyy_0[i] * pb_x + g_0_yyyyzz_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyyyyyz_0[i] = g_0_yyyyzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyyyz_0[i] * pb_x + g_0_yyyyzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyyyyzz_0[i] = g_0_yyyyzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyyzz_0[i] * pb_x + g_0_yyyyzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyyyzzz_0[i] = g_0_yyyyzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyzzz_0[i] * pb_x + g_0_yyyyzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyyzzzz_0[i] = g_0_yyyyzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyzzzz_0[i] * pb_x + g_0_yyyyzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyyzzzzz_0[i] = g_0_yyyyzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xyzzzzzz_0[i] = g_0_yyyyzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_xzzzzzzz_0[i] = g_0_yyyyzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xzzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyyyyyy_0[i] = g_0_yyyyzz_0_yyyyyyyy_0[i] * pb_x + g_0_yyyyzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyyyyyz_0[i] = g_0_yyyyzz_0_yyyyyyyz_0[i] * pb_x + g_0_yyyyzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyyyyzz_0[i] = g_0_yyyyzz_0_yyyyyyzz_0[i] * pb_x + g_0_yyyyzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyyyzzz_0[i] = g_0_yyyyzz_0_yyyyyzzz_0[i] * pb_x + g_0_yyyyzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyyzzzz_0[i] = g_0_yyyyzz_0_yyyyzzzz_0[i] * pb_x + g_0_yyyyzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyyzzzzz_0[i] = g_0_yyyyzz_0_yyyzzzzz_0[i] * pb_x + g_0_yyyyzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yyzzzzzz_0[i] = g_0_yyyyzz_0_yyzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_yzzzzzzz_0[i] = g_0_yyyyzz_0_yzzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyyzz_0_zzzzzzzz_0[i] = g_0_yyyyzz_0_zzzzzzzz_0[i] * pb_x + g_0_yyyyzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1080-1125 components of targeted buffer : SKSL

    auto g_0_xyyyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1080);

    auto g_0_xyyyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1081);

    auto g_0_xyyyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1082);

    auto g_0_xyyyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1083);

    auto g_0_xyyyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1084);

    auto g_0_xyyyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1085);

    auto g_0_xyyyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1086);

    auto g_0_xyyyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1087);

    auto g_0_xyyyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1088);

    auto g_0_xyyyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1089);

    auto g_0_xyyyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1090);

    auto g_0_xyyyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1091);

    auto g_0_xyyyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1092);

    auto g_0_xyyyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1093);

    auto g_0_xyyyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1094);

    auto g_0_xyyyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1095);

    auto g_0_xyyyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1096);

    auto g_0_xyyyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1097);

    auto g_0_xyyyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1098);

    auto g_0_xyyyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1099);

    auto g_0_xyyyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1100);

    auto g_0_xyyyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1101);

    auto g_0_xyyyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1102);

    auto g_0_xyyyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1103);

    auto g_0_xyyyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1104);

    auto g_0_xyyyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1105);

    auto g_0_xyyyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1106);

    auto g_0_xyyyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1107);

    auto g_0_xyyyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1108);

    auto g_0_xyyyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1109);

    auto g_0_xyyyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1110);

    auto g_0_xyyyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1111);

    auto g_0_xyyyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1112);

    auto g_0_xyyyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1113);

    auto g_0_xyyyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1114);

    auto g_0_xyyyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1115);

    auto g_0_xyyyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1116);

    auto g_0_xyyyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1117);

    auto g_0_xyyyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1118);

    auto g_0_xyyyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1119);

    auto g_0_xyyyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1120);

    auto g_0_xyyyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1121);

    auto g_0_xyyyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1122);

    auto g_0_xyyyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1123);

    auto g_0_xyyyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1124);

    #pragma omp simd aligned(g_0_xyyyzzz_0_xxxxxxxx_0, g_0_xyyyzzz_0_xxxxxxxy_0, g_0_xyyyzzz_0_xxxxxxxz_0, g_0_xyyyzzz_0_xxxxxxyy_0, g_0_xyyyzzz_0_xxxxxxyz_0, g_0_xyyyzzz_0_xxxxxxzz_0, g_0_xyyyzzz_0_xxxxxyyy_0, g_0_xyyyzzz_0_xxxxxyyz_0, g_0_xyyyzzz_0_xxxxxyzz_0, g_0_xyyyzzz_0_xxxxxzzz_0, g_0_xyyyzzz_0_xxxxyyyy_0, g_0_xyyyzzz_0_xxxxyyyz_0, g_0_xyyyzzz_0_xxxxyyzz_0, g_0_xyyyzzz_0_xxxxyzzz_0, g_0_xyyyzzz_0_xxxxzzzz_0, g_0_xyyyzzz_0_xxxyyyyy_0, g_0_xyyyzzz_0_xxxyyyyz_0, g_0_xyyyzzz_0_xxxyyyzz_0, g_0_xyyyzzz_0_xxxyyzzz_0, g_0_xyyyzzz_0_xxxyzzzz_0, g_0_xyyyzzz_0_xxxzzzzz_0, g_0_xyyyzzz_0_xxyyyyyy_0, g_0_xyyyzzz_0_xxyyyyyz_0, g_0_xyyyzzz_0_xxyyyyzz_0, g_0_xyyyzzz_0_xxyyyzzz_0, g_0_xyyyzzz_0_xxyyzzzz_0, g_0_xyyyzzz_0_xxyzzzzz_0, g_0_xyyyzzz_0_xxzzzzzz_0, g_0_xyyyzzz_0_xyyyyyyy_0, g_0_xyyyzzz_0_xyyyyyyz_0, g_0_xyyyzzz_0_xyyyyyzz_0, g_0_xyyyzzz_0_xyyyyzzz_0, g_0_xyyyzzz_0_xyyyzzzz_0, g_0_xyyyzzz_0_xyyzzzzz_0, g_0_xyyyzzz_0_xyzzzzzz_0, g_0_xyyyzzz_0_xzzzzzzz_0, g_0_xyyyzzz_0_yyyyyyyy_0, g_0_xyyyzzz_0_yyyyyyyz_0, g_0_xyyyzzz_0_yyyyyyzz_0, g_0_xyyyzzz_0_yyyyyzzz_0, g_0_xyyyzzz_0_yyyyzzzz_0, g_0_xyyyzzz_0_yyyzzzzz_0, g_0_xyyyzzz_0_yyzzzzzz_0, g_0_xyyyzzz_0_yzzzzzzz_0, g_0_xyyyzzz_0_zzzzzzzz_0, g_0_yyyzzz_0_xxxxxxx_1, g_0_yyyzzz_0_xxxxxxxx_0, g_0_yyyzzz_0_xxxxxxxx_1, g_0_yyyzzz_0_xxxxxxxy_0, g_0_yyyzzz_0_xxxxxxxy_1, g_0_yyyzzz_0_xxxxxxxz_0, g_0_yyyzzz_0_xxxxxxxz_1, g_0_yyyzzz_0_xxxxxxy_1, g_0_yyyzzz_0_xxxxxxyy_0, g_0_yyyzzz_0_xxxxxxyy_1, g_0_yyyzzz_0_xxxxxxyz_0, g_0_yyyzzz_0_xxxxxxyz_1, g_0_yyyzzz_0_xxxxxxz_1, g_0_yyyzzz_0_xxxxxxzz_0, g_0_yyyzzz_0_xxxxxxzz_1, g_0_yyyzzz_0_xxxxxyy_1, g_0_yyyzzz_0_xxxxxyyy_0, g_0_yyyzzz_0_xxxxxyyy_1, g_0_yyyzzz_0_xxxxxyyz_0, g_0_yyyzzz_0_xxxxxyyz_1, g_0_yyyzzz_0_xxxxxyz_1, g_0_yyyzzz_0_xxxxxyzz_0, g_0_yyyzzz_0_xxxxxyzz_1, g_0_yyyzzz_0_xxxxxzz_1, g_0_yyyzzz_0_xxxxxzzz_0, g_0_yyyzzz_0_xxxxxzzz_1, g_0_yyyzzz_0_xxxxyyy_1, g_0_yyyzzz_0_xxxxyyyy_0, g_0_yyyzzz_0_xxxxyyyy_1, g_0_yyyzzz_0_xxxxyyyz_0, g_0_yyyzzz_0_xxxxyyyz_1, g_0_yyyzzz_0_xxxxyyz_1, g_0_yyyzzz_0_xxxxyyzz_0, g_0_yyyzzz_0_xxxxyyzz_1, g_0_yyyzzz_0_xxxxyzz_1, g_0_yyyzzz_0_xxxxyzzz_0, g_0_yyyzzz_0_xxxxyzzz_1, g_0_yyyzzz_0_xxxxzzz_1, g_0_yyyzzz_0_xxxxzzzz_0, g_0_yyyzzz_0_xxxxzzzz_1, g_0_yyyzzz_0_xxxyyyy_1, g_0_yyyzzz_0_xxxyyyyy_0, g_0_yyyzzz_0_xxxyyyyy_1, g_0_yyyzzz_0_xxxyyyyz_0, g_0_yyyzzz_0_xxxyyyyz_1, g_0_yyyzzz_0_xxxyyyz_1, g_0_yyyzzz_0_xxxyyyzz_0, g_0_yyyzzz_0_xxxyyyzz_1, g_0_yyyzzz_0_xxxyyzz_1, g_0_yyyzzz_0_xxxyyzzz_0, g_0_yyyzzz_0_xxxyyzzz_1, g_0_yyyzzz_0_xxxyzzz_1, g_0_yyyzzz_0_xxxyzzzz_0, g_0_yyyzzz_0_xxxyzzzz_1, g_0_yyyzzz_0_xxxzzzz_1, g_0_yyyzzz_0_xxxzzzzz_0, g_0_yyyzzz_0_xxxzzzzz_1, g_0_yyyzzz_0_xxyyyyy_1, g_0_yyyzzz_0_xxyyyyyy_0, g_0_yyyzzz_0_xxyyyyyy_1, g_0_yyyzzz_0_xxyyyyyz_0, g_0_yyyzzz_0_xxyyyyyz_1, g_0_yyyzzz_0_xxyyyyz_1, g_0_yyyzzz_0_xxyyyyzz_0, g_0_yyyzzz_0_xxyyyyzz_1, g_0_yyyzzz_0_xxyyyzz_1, g_0_yyyzzz_0_xxyyyzzz_0, g_0_yyyzzz_0_xxyyyzzz_1, g_0_yyyzzz_0_xxyyzzz_1, g_0_yyyzzz_0_xxyyzzzz_0, g_0_yyyzzz_0_xxyyzzzz_1, g_0_yyyzzz_0_xxyzzzz_1, g_0_yyyzzz_0_xxyzzzzz_0, g_0_yyyzzz_0_xxyzzzzz_1, g_0_yyyzzz_0_xxzzzzz_1, g_0_yyyzzz_0_xxzzzzzz_0, g_0_yyyzzz_0_xxzzzzzz_1, g_0_yyyzzz_0_xyyyyyy_1, g_0_yyyzzz_0_xyyyyyyy_0, g_0_yyyzzz_0_xyyyyyyy_1, g_0_yyyzzz_0_xyyyyyyz_0, g_0_yyyzzz_0_xyyyyyyz_1, g_0_yyyzzz_0_xyyyyyz_1, g_0_yyyzzz_0_xyyyyyzz_0, g_0_yyyzzz_0_xyyyyyzz_1, g_0_yyyzzz_0_xyyyyzz_1, g_0_yyyzzz_0_xyyyyzzz_0, g_0_yyyzzz_0_xyyyyzzz_1, g_0_yyyzzz_0_xyyyzzz_1, g_0_yyyzzz_0_xyyyzzzz_0, g_0_yyyzzz_0_xyyyzzzz_1, g_0_yyyzzz_0_xyyzzzz_1, g_0_yyyzzz_0_xyyzzzzz_0, g_0_yyyzzz_0_xyyzzzzz_1, g_0_yyyzzz_0_xyzzzzz_1, g_0_yyyzzz_0_xyzzzzzz_0, g_0_yyyzzz_0_xyzzzzzz_1, g_0_yyyzzz_0_xzzzzzz_1, g_0_yyyzzz_0_xzzzzzzz_0, g_0_yyyzzz_0_xzzzzzzz_1, g_0_yyyzzz_0_yyyyyyy_1, g_0_yyyzzz_0_yyyyyyyy_0, g_0_yyyzzz_0_yyyyyyyy_1, g_0_yyyzzz_0_yyyyyyyz_0, g_0_yyyzzz_0_yyyyyyyz_1, g_0_yyyzzz_0_yyyyyyz_1, g_0_yyyzzz_0_yyyyyyzz_0, g_0_yyyzzz_0_yyyyyyzz_1, g_0_yyyzzz_0_yyyyyzz_1, g_0_yyyzzz_0_yyyyyzzz_0, g_0_yyyzzz_0_yyyyyzzz_1, g_0_yyyzzz_0_yyyyzzz_1, g_0_yyyzzz_0_yyyyzzzz_0, g_0_yyyzzz_0_yyyyzzzz_1, g_0_yyyzzz_0_yyyzzzz_1, g_0_yyyzzz_0_yyyzzzzz_0, g_0_yyyzzz_0_yyyzzzzz_1, g_0_yyyzzz_0_yyzzzzz_1, g_0_yyyzzz_0_yyzzzzzz_0, g_0_yyyzzz_0_yyzzzzzz_1, g_0_yyyzzz_0_yzzzzzz_1, g_0_yyyzzz_0_yzzzzzzz_0, g_0_yyyzzz_0_yzzzzzzz_1, g_0_yyyzzz_0_zzzzzzz_1, g_0_yyyzzz_0_zzzzzzzz_0, g_0_yyyzzz_0_zzzzzzzz_1, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyyyzzz_0_xxxxxxxx_0[i] = 8.0 * g_0_yyyzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxxx_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxxxy_0[i] = 7.0 * g_0_yyyzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxxy_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxxxz_0[i] = 7.0 * g_0_yyyzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxxz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxxyy_0[i] = 6.0 * g_0_yyyzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxyy_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxxyz_0[i] = 6.0 * g_0_yyyzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxyz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxxzz_0[i] = 6.0 * g_0_yyyzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxyyy_0[i] = 5.0 * g_0_yyyzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxyyy_0[i] * pb_x + g_0_yyyzzz_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxyyz_0[i] = 5.0 * g_0_yyyzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxyyz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxyzz_0[i] = 5.0 * g_0_yyyzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxyzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxxzzz_0[i] = 5.0 * g_0_yyyzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_yyyzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyyyy_0[i] * pb_x + g_0_yyyzzz_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxyyyz_0[i] = 4.0 * g_0_yyyzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyyyz_0[i] * pb_x + g_0_yyyzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxyyzz_0[i] = 4.0 * g_0_yyyzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyyzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxyzzz_0[i] = 4.0 * g_0_yyyzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_yyyzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyyyy_0[i] * pb_x + g_0_yyyzzz_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_yyyzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyyyz_0[i] * pb_x + g_0_yyyzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_yyyzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyyzz_0[i] * pb_x + g_0_yyyzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyyzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_yyyzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxxzzzzz_0[i] = 3.0 * g_0_yyyzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_yyyzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyyyy_0[i] * pb_x + g_0_yyyzzz_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_yyyzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyyyz_0[i] * pb_x + g_0_yyyzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_yyyzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyyzz_0[i] * pb_x + g_0_yyyzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_yyyzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyzzz_0[i] * pb_x + g_0_yyyzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_yyyzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_yyyzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xxzzzzzz_0[i] = 2.0 * g_0_yyyzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyyyyyy_0[i] = g_0_yyyzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyyyy_0[i] * pb_x + g_0_yyyzzz_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyyyyyz_0[i] = g_0_yyyzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyyyz_0[i] * pb_x + g_0_yyyzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyyyyzz_0[i] = g_0_yyyzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyyzz_0[i] * pb_x + g_0_yyyzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyyyzzz_0[i] = g_0_yyyzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyzzz_0[i] * pb_x + g_0_yyyzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyyzzzz_0[i] = g_0_yyyzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyzzzz_0[i] * pb_x + g_0_yyyzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyyzzzzz_0[i] = g_0_yyyzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xyzzzzzz_0[i] = g_0_yyyzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_xzzzzzzz_0[i] = g_0_yyyzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xzzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyyyyyy_0[i] = g_0_yyyzzz_0_yyyyyyyy_0[i] * pb_x + g_0_yyyzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyyyyyz_0[i] = g_0_yyyzzz_0_yyyyyyyz_0[i] * pb_x + g_0_yyyzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyyyyzz_0[i] = g_0_yyyzzz_0_yyyyyyzz_0[i] * pb_x + g_0_yyyzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyyyzzz_0[i] = g_0_yyyzzz_0_yyyyyzzz_0[i] * pb_x + g_0_yyyzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyyzzzz_0[i] = g_0_yyyzzz_0_yyyyzzzz_0[i] * pb_x + g_0_yyyzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyyzzzzz_0[i] = g_0_yyyzzz_0_yyyzzzzz_0[i] * pb_x + g_0_yyyzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yyzzzzzz_0[i] = g_0_yyyzzz_0_yyzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_yzzzzzzz_0[i] = g_0_yyyzzz_0_yzzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyyyzzz_0_zzzzzzzz_0[i] = g_0_yyyzzz_0_zzzzzzzz_0[i] * pb_x + g_0_yyyzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1125-1170 components of targeted buffer : SKSL

    auto g_0_xyyzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1125);

    auto g_0_xyyzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1126);

    auto g_0_xyyzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1127);

    auto g_0_xyyzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1128);

    auto g_0_xyyzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1129);

    auto g_0_xyyzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1130);

    auto g_0_xyyzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1131);

    auto g_0_xyyzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1132);

    auto g_0_xyyzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1133);

    auto g_0_xyyzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1134);

    auto g_0_xyyzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1135);

    auto g_0_xyyzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1136);

    auto g_0_xyyzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1137);

    auto g_0_xyyzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1138);

    auto g_0_xyyzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1139);

    auto g_0_xyyzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1140);

    auto g_0_xyyzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1141);

    auto g_0_xyyzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1142);

    auto g_0_xyyzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1143);

    auto g_0_xyyzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1144);

    auto g_0_xyyzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1145);

    auto g_0_xyyzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1146);

    auto g_0_xyyzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1147);

    auto g_0_xyyzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1148);

    auto g_0_xyyzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1149);

    auto g_0_xyyzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1150);

    auto g_0_xyyzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1151);

    auto g_0_xyyzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1152);

    auto g_0_xyyzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1153);

    auto g_0_xyyzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1154);

    auto g_0_xyyzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1155);

    auto g_0_xyyzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1156);

    auto g_0_xyyzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1157);

    auto g_0_xyyzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1158);

    auto g_0_xyyzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1159);

    auto g_0_xyyzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1160);

    auto g_0_xyyzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1161);

    auto g_0_xyyzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1162);

    auto g_0_xyyzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1163);

    auto g_0_xyyzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1164);

    auto g_0_xyyzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1165);

    auto g_0_xyyzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1166);

    auto g_0_xyyzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1167);

    auto g_0_xyyzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1168);

    auto g_0_xyyzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1169);

    #pragma omp simd aligned(g_0_xyyzzzz_0_xxxxxxxx_0, g_0_xyyzzzz_0_xxxxxxxy_0, g_0_xyyzzzz_0_xxxxxxxz_0, g_0_xyyzzzz_0_xxxxxxyy_0, g_0_xyyzzzz_0_xxxxxxyz_0, g_0_xyyzzzz_0_xxxxxxzz_0, g_0_xyyzzzz_0_xxxxxyyy_0, g_0_xyyzzzz_0_xxxxxyyz_0, g_0_xyyzzzz_0_xxxxxyzz_0, g_0_xyyzzzz_0_xxxxxzzz_0, g_0_xyyzzzz_0_xxxxyyyy_0, g_0_xyyzzzz_0_xxxxyyyz_0, g_0_xyyzzzz_0_xxxxyyzz_0, g_0_xyyzzzz_0_xxxxyzzz_0, g_0_xyyzzzz_0_xxxxzzzz_0, g_0_xyyzzzz_0_xxxyyyyy_0, g_0_xyyzzzz_0_xxxyyyyz_0, g_0_xyyzzzz_0_xxxyyyzz_0, g_0_xyyzzzz_0_xxxyyzzz_0, g_0_xyyzzzz_0_xxxyzzzz_0, g_0_xyyzzzz_0_xxxzzzzz_0, g_0_xyyzzzz_0_xxyyyyyy_0, g_0_xyyzzzz_0_xxyyyyyz_0, g_0_xyyzzzz_0_xxyyyyzz_0, g_0_xyyzzzz_0_xxyyyzzz_0, g_0_xyyzzzz_0_xxyyzzzz_0, g_0_xyyzzzz_0_xxyzzzzz_0, g_0_xyyzzzz_0_xxzzzzzz_0, g_0_xyyzzzz_0_xyyyyyyy_0, g_0_xyyzzzz_0_xyyyyyyz_0, g_0_xyyzzzz_0_xyyyyyzz_0, g_0_xyyzzzz_0_xyyyyzzz_0, g_0_xyyzzzz_0_xyyyzzzz_0, g_0_xyyzzzz_0_xyyzzzzz_0, g_0_xyyzzzz_0_xyzzzzzz_0, g_0_xyyzzzz_0_xzzzzzzz_0, g_0_xyyzzzz_0_yyyyyyyy_0, g_0_xyyzzzz_0_yyyyyyyz_0, g_0_xyyzzzz_0_yyyyyyzz_0, g_0_xyyzzzz_0_yyyyyzzz_0, g_0_xyyzzzz_0_yyyyzzzz_0, g_0_xyyzzzz_0_yyyzzzzz_0, g_0_xyyzzzz_0_yyzzzzzz_0, g_0_xyyzzzz_0_yzzzzzzz_0, g_0_xyyzzzz_0_zzzzzzzz_0, g_0_yyzzzz_0_xxxxxxx_1, g_0_yyzzzz_0_xxxxxxxx_0, g_0_yyzzzz_0_xxxxxxxx_1, g_0_yyzzzz_0_xxxxxxxy_0, g_0_yyzzzz_0_xxxxxxxy_1, g_0_yyzzzz_0_xxxxxxxz_0, g_0_yyzzzz_0_xxxxxxxz_1, g_0_yyzzzz_0_xxxxxxy_1, g_0_yyzzzz_0_xxxxxxyy_0, g_0_yyzzzz_0_xxxxxxyy_1, g_0_yyzzzz_0_xxxxxxyz_0, g_0_yyzzzz_0_xxxxxxyz_1, g_0_yyzzzz_0_xxxxxxz_1, g_0_yyzzzz_0_xxxxxxzz_0, g_0_yyzzzz_0_xxxxxxzz_1, g_0_yyzzzz_0_xxxxxyy_1, g_0_yyzzzz_0_xxxxxyyy_0, g_0_yyzzzz_0_xxxxxyyy_1, g_0_yyzzzz_0_xxxxxyyz_0, g_0_yyzzzz_0_xxxxxyyz_1, g_0_yyzzzz_0_xxxxxyz_1, g_0_yyzzzz_0_xxxxxyzz_0, g_0_yyzzzz_0_xxxxxyzz_1, g_0_yyzzzz_0_xxxxxzz_1, g_0_yyzzzz_0_xxxxxzzz_0, g_0_yyzzzz_0_xxxxxzzz_1, g_0_yyzzzz_0_xxxxyyy_1, g_0_yyzzzz_0_xxxxyyyy_0, g_0_yyzzzz_0_xxxxyyyy_1, g_0_yyzzzz_0_xxxxyyyz_0, g_0_yyzzzz_0_xxxxyyyz_1, g_0_yyzzzz_0_xxxxyyz_1, g_0_yyzzzz_0_xxxxyyzz_0, g_0_yyzzzz_0_xxxxyyzz_1, g_0_yyzzzz_0_xxxxyzz_1, g_0_yyzzzz_0_xxxxyzzz_0, g_0_yyzzzz_0_xxxxyzzz_1, g_0_yyzzzz_0_xxxxzzz_1, g_0_yyzzzz_0_xxxxzzzz_0, g_0_yyzzzz_0_xxxxzzzz_1, g_0_yyzzzz_0_xxxyyyy_1, g_0_yyzzzz_0_xxxyyyyy_0, g_0_yyzzzz_0_xxxyyyyy_1, g_0_yyzzzz_0_xxxyyyyz_0, g_0_yyzzzz_0_xxxyyyyz_1, g_0_yyzzzz_0_xxxyyyz_1, g_0_yyzzzz_0_xxxyyyzz_0, g_0_yyzzzz_0_xxxyyyzz_1, g_0_yyzzzz_0_xxxyyzz_1, g_0_yyzzzz_0_xxxyyzzz_0, g_0_yyzzzz_0_xxxyyzzz_1, g_0_yyzzzz_0_xxxyzzz_1, g_0_yyzzzz_0_xxxyzzzz_0, g_0_yyzzzz_0_xxxyzzzz_1, g_0_yyzzzz_0_xxxzzzz_1, g_0_yyzzzz_0_xxxzzzzz_0, g_0_yyzzzz_0_xxxzzzzz_1, g_0_yyzzzz_0_xxyyyyy_1, g_0_yyzzzz_0_xxyyyyyy_0, g_0_yyzzzz_0_xxyyyyyy_1, g_0_yyzzzz_0_xxyyyyyz_0, g_0_yyzzzz_0_xxyyyyyz_1, g_0_yyzzzz_0_xxyyyyz_1, g_0_yyzzzz_0_xxyyyyzz_0, g_0_yyzzzz_0_xxyyyyzz_1, g_0_yyzzzz_0_xxyyyzz_1, g_0_yyzzzz_0_xxyyyzzz_0, g_0_yyzzzz_0_xxyyyzzz_1, g_0_yyzzzz_0_xxyyzzz_1, g_0_yyzzzz_0_xxyyzzzz_0, g_0_yyzzzz_0_xxyyzzzz_1, g_0_yyzzzz_0_xxyzzzz_1, g_0_yyzzzz_0_xxyzzzzz_0, g_0_yyzzzz_0_xxyzzzzz_1, g_0_yyzzzz_0_xxzzzzz_1, g_0_yyzzzz_0_xxzzzzzz_0, g_0_yyzzzz_0_xxzzzzzz_1, g_0_yyzzzz_0_xyyyyyy_1, g_0_yyzzzz_0_xyyyyyyy_0, g_0_yyzzzz_0_xyyyyyyy_1, g_0_yyzzzz_0_xyyyyyyz_0, g_0_yyzzzz_0_xyyyyyyz_1, g_0_yyzzzz_0_xyyyyyz_1, g_0_yyzzzz_0_xyyyyyzz_0, g_0_yyzzzz_0_xyyyyyzz_1, g_0_yyzzzz_0_xyyyyzz_1, g_0_yyzzzz_0_xyyyyzzz_0, g_0_yyzzzz_0_xyyyyzzz_1, g_0_yyzzzz_0_xyyyzzz_1, g_0_yyzzzz_0_xyyyzzzz_0, g_0_yyzzzz_0_xyyyzzzz_1, g_0_yyzzzz_0_xyyzzzz_1, g_0_yyzzzz_0_xyyzzzzz_0, g_0_yyzzzz_0_xyyzzzzz_1, g_0_yyzzzz_0_xyzzzzz_1, g_0_yyzzzz_0_xyzzzzzz_0, g_0_yyzzzz_0_xyzzzzzz_1, g_0_yyzzzz_0_xzzzzzz_1, g_0_yyzzzz_0_xzzzzzzz_0, g_0_yyzzzz_0_xzzzzzzz_1, g_0_yyzzzz_0_yyyyyyy_1, g_0_yyzzzz_0_yyyyyyyy_0, g_0_yyzzzz_0_yyyyyyyy_1, g_0_yyzzzz_0_yyyyyyyz_0, g_0_yyzzzz_0_yyyyyyyz_1, g_0_yyzzzz_0_yyyyyyz_1, g_0_yyzzzz_0_yyyyyyzz_0, g_0_yyzzzz_0_yyyyyyzz_1, g_0_yyzzzz_0_yyyyyzz_1, g_0_yyzzzz_0_yyyyyzzz_0, g_0_yyzzzz_0_yyyyyzzz_1, g_0_yyzzzz_0_yyyyzzz_1, g_0_yyzzzz_0_yyyyzzzz_0, g_0_yyzzzz_0_yyyyzzzz_1, g_0_yyzzzz_0_yyyzzzz_1, g_0_yyzzzz_0_yyyzzzzz_0, g_0_yyzzzz_0_yyyzzzzz_1, g_0_yyzzzz_0_yyzzzzz_1, g_0_yyzzzz_0_yyzzzzzz_0, g_0_yyzzzz_0_yyzzzzzz_1, g_0_yyzzzz_0_yzzzzzz_1, g_0_yyzzzz_0_yzzzzzzz_0, g_0_yyzzzz_0_yzzzzzzz_1, g_0_yyzzzz_0_zzzzzzz_1, g_0_yyzzzz_0_zzzzzzzz_0, g_0_yyzzzz_0_zzzzzzzz_1, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyyzzzz_0_xxxxxxxx_0[i] = 8.0 * g_0_yyzzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxxx_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxxxy_0[i] = 7.0 * g_0_yyzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxxy_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxxxz_0[i] = 7.0 * g_0_yyzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxxz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxxyy_0[i] = 6.0 * g_0_yyzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxyy_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxxyz_0[i] = 6.0 * g_0_yyzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxyz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxxzz_0[i] = 6.0 * g_0_yyzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxyyy_0[i] = 5.0 * g_0_yyzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxyyy_0[i] * pb_x + g_0_yyzzzz_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxyyz_0[i] = 5.0 * g_0_yyzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxyyz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxyzz_0[i] = 5.0 * g_0_yyzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxyzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxxzzz_0[i] = 5.0 * g_0_yyzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_yyzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyyyy_0[i] * pb_x + g_0_yyzzzz_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxyyyz_0[i] = 4.0 * g_0_yyzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyyyz_0[i] * pb_x + g_0_yyzzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxyyzz_0[i] = 4.0 * g_0_yyzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyyzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxyzzz_0[i] = 4.0 * g_0_yyzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_yyzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyyyy_0[i] * pb_x + g_0_yyzzzz_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_yyzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyyyz_0[i] * pb_x + g_0_yyzzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_yyzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyyzz_0[i] * pb_x + g_0_yyzzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_yyzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxxzzzzz_0[i] = 3.0 * g_0_yyzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_yyzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyyyy_0[i] * pb_x + g_0_yyzzzz_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_yyzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyyyz_0[i] * pb_x + g_0_yyzzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_yyzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyyzz_0[i] * pb_x + g_0_yyzzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_yyzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyzzz_0[i] * pb_x + g_0_yyzzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_yyzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_yyzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xxzzzzzz_0[i] = 2.0 * g_0_yyzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyyyyyy_0[i] = g_0_yyzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyyyy_0[i] * pb_x + g_0_yyzzzz_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyyyyyz_0[i] = g_0_yyzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyyyz_0[i] * pb_x + g_0_yyzzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyyyyzz_0[i] = g_0_yyzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyyzz_0[i] * pb_x + g_0_yyzzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyyyzzz_0[i] = g_0_yyzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyzzz_0[i] * pb_x + g_0_yyzzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyyzzzz_0[i] = g_0_yyzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyzzzz_0[i] * pb_x + g_0_yyzzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyyzzzzz_0[i] = g_0_yyzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xyzzzzzz_0[i] = g_0_yyzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_xzzzzzzz_0[i] = g_0_yyzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xzzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyyyyyy_0[i] = g_0_yyzzzz_0_yyyyyyyy_0[i] * pb_x + g_0_yyzzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyyyyyz_0[i] = g_0_yyzzzz_0_yyyyyyyz_0[i] * pb_x + g_0_yyzzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyyyyzz_0[i] = g_0_yyzzzz_0_yyyyyyzz_0[i] * pb_x + g_0_yyzzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyyyzzz_0[i] = g_0_yyzzzz_0_yyyyyzzz_0[i] * pb_x + g_0_yyzzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyyzzzz_0[i] = g_0_yyzzzz_0_yyyyzzzz_0[i] * pb_x + g_0_yyzzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyyzzzzz_0[i] = g_0_yyzzzz_0_yyyzzzzz_0[i] * pb_x + g_0_yyzzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yyzzzzzz_0[i] = g_0_yyzzzz_0_yyzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_yzzzzzzz_0[i] = g_0_yyzzzz_0_yzzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyyzzzz_0_zzzzzzzz_0[i] = g_0_yyzzzz_0_zzzzzzzz_0[i] * pb_x + g_0_yyzzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1170-1215 components of targeted buffer : SKSL

    auto g_0_xyzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1170);

    auto g_0_xyzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1171);

    auto g_0_xyzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1172);

    auto g_0_xyzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1173);

    auto g_0_xyzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1174);

    auto g_0_xyzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1175);

    auto g_0_xyzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1176);

    auto g_0_xyzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1177);

    auto g_0_xyzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1178);

    auto g_0_xyzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1179);

    auto g_0_xyzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1180);

    auto g_0_xyzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1181);

    auto g_0_xyzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1182);

    auto g_0_xyzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1183);

    auto g_0_xyzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1184);

    auto g_0_xyzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1185);

    auto g_0_xyzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1186);

    auto g_0_xyzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1187);

    auto g_0_xyzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1188);

    auto g_0_xyzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1189);

    auto g_0_xyzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1190);

    auto g_0_xyzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1191);

    auto g_0_xyzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1192);

    auto g_0_xyzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1193);

    auto g_0_xyzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1194);

    auto g_0_xyzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1195);

    auto g_0_xyzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1196);

    auto g_0_xyzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1197);

    auto g_0_xyzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1198);

    auto g_0_xyzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1199);

    auto g_0_xyzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1200);

    auto g_0_xyzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1201);

    auto g_0_xyzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1202);

    auto g_0_xyzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1203);

    auto g_0_xyzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1204);

    auto g_0_xyzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1205);

    auto g_0_xyzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1206);

    auto g_0_xyzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1207);

    auto g_0_xyzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1208);

    auto g_0_xyzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1209);

    auto g_0_xyzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1210);

    auto g_0_xyzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1211);

    auto g_0_xyzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1212);

    auto g_0_xyzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1213);

    auto g_0_xyzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1214);

    #pragma omp simd aligned(g_0_xyzzzzz_0_xxxxxxxx_0, g_0_xyzzzzz_0_xxxxxxxy_0, g_0_xyzzzzz_0_xxxxxxxz_0, g_0_xyzzzzz_0_xxxxxxyy_0, g_0_xyzzzzz_0_xxxxxxyz_0, g_0_xyzzzzz_0_xxxxxxzz_0, g_0_xyzzzzz_0_xxxxxyyy_0, g_0_xyzzzzz_0_xxxxxyyz_0, g_0_xyzzzzz_0_xxxxxyzz_0, g_0_xyzzzzz_0_xxxxxzzz_0, g_0_xyzzzzz_0_xxxxyyyy_0, g_0_xyzzzzz_0_xxxxyyyz_0, g_0_xyzzzzz_0_xxxxyyzz_0, g_0_xyzzzzz_0_xxxxyzzz_0, g_0_xyzzzzz_0_xxxxzzzz_0, g_0_xyzzzzz_0_xxxyyyyy_0, g_0_xyzzzzz_0_xxxyyyyz_0, g_0_xyzzzzz_0_xxxyyyzz_0, g_0_xyzzzzz_0_xxxyyzzz_0, g_0_xyzzzzz_0_xxxyzzzz_0, g_0_xyzzzzz_0_xxxzzzzz_0, g_0_xyzzzzz_0_xxyyyyyy_0, g_0_xyzzzzz_0_xxyyyyyz_0, g_0_xyzzzzz_0_xxyyyyzz_0, g_0_xyzzzzz_0_xxyyyzzz_0, g_0_xyzzzzz_0_xxyyzzzz_0, g_0_xyzzzzz_0_xxyzzzzz_0, g_0_xyzzzzz_0_xxzzzzzz_0, g_0_xyzzzzz_0_xyyyyyyy_0, g_0_xyzzzzz_0_xyyyyyyz_0, g_0_xyzzzzz_0_xyyyyyzz_0, g_0_xyzzzzz_0_xyyyyzzz_0, g_0_xyzzzzz_0_xyyyzzzz_0, g_0_xyzzzzz_0_xyyzzzzz_0, g_0_xyzzzzz_0_xyzzzzzz_0, g_0_xyzzzzz_0_xzzzzzzz_0, g_0_xyzzzzz_0_yyyyyyyy_0, g_0_xyzzzzz_0_yyyyyyyz_0, g_0_xyzzzzz_0_yyyyyyzz_0, g_0_xyzzzzz_0_yyyyyzzz_0, g_0_xyzzzzz_0_yyyyzzzz_0, g_0_xyzzzzz_0_yyyzzzzz_0, g_0_xyzzzzz_0_yyzzzzzz_0, g_0_xyzzzzz_0_yzzzzzzz_0, g_0_xyzzzzz_0_zzzzzzzz_0, g_0_xzzzzz_0_xxxxxxxx_0, g_0_xzzzzz_0_xxxxxxxx_1, g_0_xzzzzz_0_xxxxxxxz_0, g_0_xzzzzz_0_xxxxxxxz_1, g_0_xzzzzz_0_xxxxxxzz_0, g_0_xzzzzz_0_xxxxxxzz_1, g_0_xzzzzz_0_xxxxxzzz_0, g_0_xzzzzz_0_xxxxxzzz_1, g_0_xzzzzz_0_xxxxzzzz_0, g_0_xzzzzz_0_xxxxzzzz_1, g_0_xzzzzz_0_xxxzzzzz_0, g_0_xzzzzz_0_xxxzzzzz_1, g_0_xzzzzz_0_xxzzzzzz_0, g_0_xzzzzz_0_xxzzzzzz_1, g_0_xzzzzz_0_xzzzzzzz_0, g_0_xzzzzz_0_xzzzzzzz_1, g_0_yzzzzz_0_xxxxxxxy_0, g_0_yzzzzz_0_xxxxxxxy_1, g_0_yzzzzz_0_xxxxxxy_1, g_0_yzzzzz_0_xxxxxxyy_0, g_0_yzzzzz_0_xxxxxxyy_1, g_0_yzzzzz_0_xxxxxxyz_0, g_0_yzzzzz_0_xxxxxxyz_1, g_0_yzzzzz_0_xxxxxyy_1, g_0_yzzzzz_0_xxxxxyyy_0, g_0_yzzzzz_0_xxxxxyyy_1, g_0_yzzzzz_0_xxxxxyyz_0, g_0_yzzzzz_0_xxxxxyyz_1, g_0_yzzzzz_0_xxxxxyz_1, g_0_yzzzzz_0_xxxxxyzz_0, g_0_yzzzzz_0_xxxxxyzz_1, g_0_yzzzzz_0_xxxxyyy_1, g_0_yzzzzz_0_xxxxyyyy_0, g_0_yzzzzz_0_xxxxyyyy_1, g_0_yzzzzz_0_xxxxyyyz_0, g_0_yzzzzz_0_xxxxyyyz_1, g_0_yzzzzz_0_xxxxyyz_1, g_0_yzzzzz_0_xxxxyyzz_0, g_0_yzzzzz_0_xxxxyyzz_1, g_0_yzzzzz_0_xxxxyzz_1, g_0_yzzzzz_0_xxxxyzzz_0, g_0_yzzzzz_0_xxxxyzzz_1, g_0_yzzzzz_0_xxxyyyy_1, g_0_yzzzzz_0_xxxyyyyy_0, g_0_yzzzzz_0_xxxyyyyy_1, g_0_yzzzzz_0_xxxyyyyz_0, g_0_yzzzzz_0_xxxyyyyz_1, g_0_yzzzzz_0_xxxyyyz_1, g_0_yzzzzz_0_xxxyyyzz_0, g_0_yzzzzz_0_xxxyyyzz_1, g_0_yzzzzz_0_xxxyyzz_1, g_0_yzzzzz_0_xxxyyzzz_0, g_0_yzzzzz_0_xxxyyzzz_1, g_0_yzzzzz_0_xxxyzzz_1, g_0_yzzzzz_0_xxxyzzzz_0, g_0_yzzzzz_0_xxxyzzzz_1, g_0_yzzzzz_0_xxyyyyy_1, g_0_yzzzzz_0_xxyyyyyy_0, g_0_yzzzzz_0_xxyyyyyy_1, g_0_yzzzzz_0_xxyyyyyz_0, g_0_yzzzzz_0_xxyyyyyz_1, g_0_yzzzzz_0_xxyyyyz_1, g_0_yzzzzz_0_xxyyyyzz_0, g_0_yzzzzz_0_xxyyyyzz_1, g_0_yzzzzz_0_xxyyyzz_1, g_0_yzzzzz_0_xxyyyzzz_0, g_0_yzzzzz_0_xxyyyzzz_1, g_0_yzzzzz_0_xxyyzzz_1, g_0_yzzzzz_0_xxyyzzzz_0, g_0_yzzzzz_0_xxyyzzzz_1, g_0_yzzzzz_0_xxyzzzz_1, g_0_yzzzzz_0_xxyzzzzz_0, g_0_yzzzzz_0_xxyzzzzz_1, g_0_yzzzzz_0_xyyyyyy_1, g_0_yzzzzz_0_xyyyyyyy_0, g_0_yzzzzz_0_xyyyyyyy_1, g_0_yzzzzz_0_xyyyyyyz_0, g_0_yzzzzz_0_xyyyyyyz_1, g_0_yzzzzz_0_xyyyyyz_1, g_0_yzzzzz_0_xyyyyyzz_0, g_0_yzzzzz_0_xyyyyyzz_1, g_0_yzzzzz_0_xyyyyzz_1, g_0_yzzzzz_0_xyyyyzzz_0, g_0_yzzzzz_0_xyyyyzzz_1, g_0_yzzzzz_0_xyyyzzz_1, g_0_yzzzzz_0_xyyyzzzz_0, g_0_yzzzzz_0_xyyyzzzz_1, g_0_yzzzzz_0_xyyzzzz_1, g_0_yzzzzz_0_xyyzzzzz_0, g_0_yzzzzz_0_xyyzzzzz_1, g_0_yzzzzz_0_xyzzzzz_1, g_0_yzzzzz_0_xyzzzzzz_0, g_0_yzzzzz_0_xyzzzzzz_1, g_0_yzzzzz_0_yyyyyyy_1, g_0_yzzzzz_0_yyyyyyyy_0, g_0_yzzzzz_0_yyyyyyyy_1, g_0_yzzzzz_0_yyyyyyyz_0, g_0_yzzzzz_0_yyyyyyyz_1, g_0_yzzzzz_0_yyyyyyz_1, g_0_yzzzzz_0_yyyyyyzz_0, g_0_yzzzzz_0_yyyyyyzz_1, g_0_yzzzzz_0_yyyyyzz_1, g_0_yzzzzz_0_yyyyyzzz_0, g_0_yzzzzz_0_yyyyyzzz_1, g_0_yzzzzz_0_yyyyzzz_1, g_0_yzzzzz_0_yyyyzzzz_0, g_0_yzzzzz_0_yyyyzzzz_1, g_0_yzzzzz_0_yyyzzzz_1, g_0_yzzzzz_0_yyyzzzzz_0, g_0_yzzzzz_0_yyyzzzzz_1, g_0_yzzzzz_0_yyzzzzz_1, g_0_yzzzzz_0_yyzzzzzz_0, g_0_yzzzzz_0_yyzzzzzz_1, g_0_yzzzzz_0_yzzzzzz_1, g_0_yzzzzz_0_yzzzzzzz_0, g_0_yzzzzz_0_yzzzzzzz_1, g_0_yzzzzz_0_zzzzzzzz_0, g_0_yzzzzz_0_zzzzzzzz_1, wp_x, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xyzzzzz_0_xxxxxxxx_0[i] = g_0_xzzzzz_0_xxxxxxxx_0[i] * pb_y + g_0_xzzzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxxxxxxy_0[i] = 7.0 * g_0_yzzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxxxy_0[i] * pb_x + g_0_yzzzzz_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxxxz_0[i] = g_0_xzzzzz_0_xxxxxxxz_0[i] * pb_y + g_0_xzzzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxxxxxyy_0[i] = 6.0 * g_0_yzzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxxyy_0[i] * pb_x + g_0_yzzzzz_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxxyz_0[i] = 6.0 * g_0_yzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxxyz_0[i] * pb_x + g_0_yzzzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxxzz_0[i] = g_0_xzzzzz_0_xxxxxxzz_0[i] * pb_y + g_0_xzzzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxxxxyyy_0[i] = 5.0 * g_0_yzzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxyyy_0[i] * pb_x + g_0_yzzzzz_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxyyz_0[i] = 5.0 * g_0_yzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxyyz_0[i] * pb_x + g_0_yzzzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxyzz_0[i] = 5.0 * g_0_yzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxyzz_0[i] * pb_x + g_0_yzzzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxxzzz_0[i] = g_0_xzzzzz_0_xxxxxzzz_0[i] * pb_y + g_0_xzzzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_yzzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyyyy_0[i] * pb_x + g_0_yzzzzz_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxyyyz_0[i] = 4.0 * g_0_yzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyyyz_0[i] * pb_x + g_0_yzzzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxyyzz_0[i] = 4.0 * g_0_yzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyyzz_0[i] * pb_x + g_0_yzzzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxyzzz_0[i] = 4.0 * g_0_yzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyzzz_0[i] * pb_x + g_0_yzzzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxxzzzz_0[i] = g_0_xzzzzz_0_xxxxzzzz_0[i] * pb_y + g_0_xzzzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_yzzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyyyy_0[i] * pb_x + g_0_yzzzzz_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_yzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyyyz_0[i] * pb_x + g_0_yzzzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_yzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyyzz_0[i] * pb_x + g_0_yzzzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_yzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyzzz_0[i] * pb_x + g_0_yzzzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_yzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyzzzz_0[i] * pb_x + g_0_yzzzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxxzzzzz_0[i] = g_0_xzzzzz_0_xxxzzzzz_0[i] * pb_y + g_0_xzzzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_yzzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyyyy_0[i] * pb_x + g_0_yzzzzz_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_yzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyyyz_0[i] * pb_x + g_0_yzzzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_yzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyyzz_0[i] * pb_x + g_0_yzzzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_yzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyzzz_0[i] * pb_x + g_0_yzzzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_yzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyzzzz_0[i] * pb_x + g_0_yzzzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_yzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyzzzzz_0[i] * pb_x + g_0_yzzzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xxzzzzzz_0[i] = g_0_xzzzzz_0_xxzzzzzz_0[i] * pb_y + g_0_xzzzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_xyyyyyyy_0[i] = g_0_yzzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyyyy_0[i] * pb_x + g_0_yzzzzz_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyyyyyyz_0[i] = g_0_yzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyyyz_0[i] * pb_x + g_0_yzzzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyyyyyzz_0[i] = g_0_yzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyyzz_0[i] * pb_x + g_0_yzzzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyyyyzzz_0[i] = g_0_yzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyzzz_0[i] * pb_x + g_0_yzzzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyyyzzzz_0[i] = g_0_yzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyzzzz_0[i] * pb_x + g_0_yzzzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyyzzzzz_0[i] = g_0_yzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyzzzzz_0[i] * pb_x + g_0_yzzzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xyzzzzzz_0[i] = g_0_yzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyzzzzzz_0[i] * pb_x + g_0_yzzzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_xzzzzzzz_0[i] = g_0_xzzzzz_0_xzzzzzzz_0[i] * pb_y + g_0_xzzzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_xyzzzzz_0_yyyyyyyy_0[i] = g_0_yzzzzz_0_yyyyyyyy_0[i] * pb_x + g_0_yzzzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyyyyyyz_0[i] = g_0_yzzzzz_0_yyyyyyyz_0[i] * pb_x + g_0_yzzzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyyyyyzz_0[i] = g_0_yzzzzz_0_yyyyyyzz_0[i] * pb_x + g_0_yzzzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyyyyzzz_0[i] = g_0_yzzzzz_0_yyyyyzzz_0[i] * pb_x + g_0_yzzzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyyyzzzz_0[i] = g_0_yzzzzz_0_yyyyzzzz_0[i] * pb_x + g_0_yzzzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyyzzzzz_0[i] = g_0_yzzzzz_0_yyyzzzzz_0[i] * pb_x + g_0_yzzzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yyzzzzzz_0[i] = g_0_yzzzzz_0_yyzzzzzz_0[i] * pb_x + g_0_yzzzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_yzzzzzzz_0[i] = g_0_yzzzzz_0_yzzzzzzz_0[i] * pb_x + g_0_yzzzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xyzzzzz_0_zzzzzzzz_0[i] = g_0_yzzzzz_0_zzzzzzzz_0[i] * pb_x + g_0_yzzzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1215-1260 components of targeted buffer : SKSL

    auto g_0_xzzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1215);

    auto g_0_xzzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1216);

    auto g_0_xzzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1217);

    auto g_0_xzzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1218);

    auto g_0_xzzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1219);

    auto g_0_xzzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1220);

    auto g_0_xzzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1221);

    auto g_0_xzzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1222);

    auto g_0_xzzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1223);

    auto g_0_xzzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1224);

    auto g_0_xzzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1225);

    auto g_0_xzzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1226);

    auto g_0_xzzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1227);

    auto g_0_xzzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1228);

    auto g_0_xzzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1229);

    auto g_0_xzzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1230);

    auto g_0_xzzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1231);

    auto g_0_xzzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1232);

    auto g_0_xzzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1233);

    auto g_0_xzzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1234);

    auto g_0_xzzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1235);

    auto g_0_xzzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1236);

    auto g_0_xzzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1237);

    auto g_0_xzzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1238);

    auto g_0_xzzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1239);

    auto g_0_xzzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1240);

    auto g_0_xzzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1241);

    auto g_0_xzzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1242);

    auto g_0_xzzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1243);

    auto g_0_xzzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1244);

    auto g_0_xzzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1245);

    auto g_0_xzzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1246);

    auto g_0_xzzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1247);

    auto g_0_xzzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1248);

    auto g_0_xzzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1249);

    auto g_0_xzzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1250);

    auto g_0_xzzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1251);

    auto g_0_xzzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1252);

    auto g_0_xzzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1253);

    auto g_0_xzzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1254);

    auto g_0_xzzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1255);

    auto g_0_xzzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1256);

    auto g_0_xzzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1257);

    auto g_0_xzzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1258);

    auto g_0_xzzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1259);

    #pragma omp simd aligned(g_0_xzzzzzz_0_xxxxxxxx_0, g_0_xzzzzzz_0_xxxxxxxy_0, g_0_xzzzzzz_0_xxxxxxxz_0, g_0_xzzzzzz_0_xxxxxxyy_0, g_0_xzzzzzz_0_xxxxxxyz_0, g_0_xzzzzzz_0_xxxxxxzz_0, g_0_xzzzzzz_0_xxxxxyyy_0, g_0_xzzzzzz_0_xxxxxyyz_0, g_0_xzzzzzz_0_xxxxxyzz_0, g_0_xzzzzzz_0_xxxxxzzz_0, g_0_xzzzzzz_0_xxxxyyyy_0, g_0_xzzzzzz_0_xxxxyyyz_0, g_0_xzzzzzz_0_xxxxyyzz_0, g_0_xzzzzzz_0_xxxxyzzz_0, g_0_xzzzzzz_0_xxxxzzzz_0, g_0_xzzzzzz_0_xxxyyyyy_0, g_0_xzzzzzz_0_xxxyyyyz_0, g_0_xzzzzzz_0_xxxyyyzz_0, g_0_xzzzzzz_0_xxxyyzzz_0, g_0_xzzzzzz_0_xxxyzzzz_0, g_0_xzzzzzz_0_xxxzzzzz_0, g_0_xzzzzzz_0_xxyyyyyy_0, g_0_xzzzzzz_0_xxyyyyyz_0, g_0_xzzzzzz_0_xxyyyyzz_0, g_0_xzzzzzz_0_xxyyyzzz_0, g_0_xzzzzzz_0_xxyyzzzz_0, g_0_xzzzzzz_0_xxyzzzzz_0, g_0_xzzzzzz_0_xxzzzzzz_0, g_0_xzzzzzz_0_xyyyyyyy_0, g_0_xzzzzzz_0_xyyyyyyz_0, g_0_xzzzzzz_0_xyyyyyzz_0, g_0_xzzzzzz_0_xyyyyzzz_0, g_0_xzzzzzz_0_xyyyzzzz_0, g_0_xzzzzzz_0_xyyzzzzz_0, g_0_xzzzzzz_0_xyzzzzzz_0, g_0_xzzzzzz_0_xzzzzzzz_0, g_0_xzzzzzz_0_yyyyyyyy_0, g_0_xzzzzzz_0_yyyyyyyz_0, g_0_xzzzzzz_0_yyyyyyzz_0, g_0_xzzzzzz_0_yyyyyzzz_0, g_0_xzzzzzz_0_yyyyzzzz_0, g_0_xzzzzzz_0_yyyzzzzz_0, g_0_xzzzzzz_0_yyzzzzzz_0, g_0_xzzzzzz_0_yzzzzzzz_0, g_0_xzzzzzz_0_zzzzzzzz_0, g_0_zzzzzz_0_xxxxxxx_1, g_0_zzzzzz_0_xxxxxxxx_0, g_0_zzzzzz_0_xxxxxxxx_1, g_0_zzzzzz_0_xxxxxxxy_0, g_0_zzzzzz_0_xxxxxxxy_1, g_0_zzzzzz_0_xxxxxxxz_0, g_0_zzzzzz_0_xxxxxxxz_1, g_0_zzzzzz_0_xxxxxxy_1, g_0_zzzzzz_0_xxxxxxyy_0, g_0_zzzzzz_0_xxxxxxyy_1, g_0_zzzzzz_0_xxxxxxyz_0, g_0_zzzzzz_0_xxxxxxyz_1, g_0_zzzzzz_0_xxxxxxz_1, g_0_zzzzzz_0_xxxxxxzz_0, g_0_zzzzzz_0_xxxxxxzz_1, g_0_zzzzzz_0_xxxxxyy_1, g_0_zzzzzz_0_xxxxxyyy_0, g_0_zzzzzz_0_xxxxxyyy_1, g_0_zzzzzz_0_xxxxxyyz_0, g_0_zzzzzz_0_xxxxxyyz_1, g_0_zzzzzz_0_xxxxxyz_1, g_0_zzzzzz_0_xxxxxyzz_0, g_0_zzzzzz_0_xxxxxyzz_1, g_0_zzzzzz_0_xxxxxzz_1, g_0_zzzzzz_0_xxxxxzzz_0, g_0_zzzzzz_0_xxxxxzzz_1, g_0_zzzzzz_0_xxxxyyy_1, g_0_zzzzzz_0_xxxxyyyy_0, g_0_zzzzzz_0_xxxxyyyy_1, g_0_zzzzzz_0_xxxxyyyz_0, g_0_zzzzzz_0_xxxxyyyz_1, g_0_zzzzzz_0_xxxxyyz_1, g_0_zzzzzz_0_xxxxyyzz_0, g_0_zzzzzz_0_xxxxyyzz_1, g_0_zzzzzz_0_xxxxyzz_1, g_0_zzzzzz_0_xxxxyzzz_0, g_0_zzzzzz_0_xxxxyzzz_1, g_0_zzzzzz_0_xxxxzzz_1, g_0_zzzzzz_0_xxxxzzzz_0, g_0_zzzzzz_0_xxxxzzzz_1, g_0_zzzzzz_0_xxxyyyy_1, g_0_zzzzzz_0_xxxyyyyy_0, g_0_zzzzzz_0_xxxyyyyy_1, g_0_zzzzzz_0_xxxyyyyz_0, g_0_zzzzzz_0_xxxyyyyz_1, g_0_zzzzzz_0_xxxyyyz_1, g_0_zzzzzz_0_xxxyyyzz_0, g_0_zzzzzz_0_xxxyyyzz_1, g_0_zzzzzz_0_xxxyyzz_1, g_0_zzzzzz_0_xxxyyzzz_0, g_0_zzzzzz_0_xxxyyzzz_1, g_0_zzzzzz_0_xxxyzzz_1, g_0_zzzzzz_0_xxxyzzzz_0, g_0_zzzzzz_0_xxxyzzzz_1, g_0_zzzzzz_0_xxxzzzz_1, g_0_zzzzzz_0_xxxzzzzz_0, g_0_zzzzzz_0_xxxzzzzz_1, g_0_zzzzzz_0_xxyyyyy_1, g_0_zzzzzz_0_xxyyyyyy_0, g_0_zzzzzz_0_xxyyyyyy_1, g_0_zzzzzz_0_xxyyyyyz_0, g_0_zzzzzz_0_xxyyyyyz_1, g_0_zzzzzz_0_xxyyyyz_1, g_0_zzzzzz_0_xxyyyyzz_0, g_0_zzzzzz_0_xxyyyyzz_1, g_0_zzzzzz_0_xxyyyzz_1, g_0_zzzzzz_0_xxyyyzzz_0, g_0_zzzzzz_0_xxyyyzzz_1, g_0_zzzzzz_0_xxyyzzz_1, g_0_zzzzzz_0_xxyyzzzz_0, g_0_zzzzzz_0_xxyyzzzz_1, g_0_zzzzzz_0_xxyzzzz_1, g_0_zzzzzz_0_xxyzzzzz_0, g_0_zzzzzz_0_xxyzzzzz_1, g_0_zzzzzz_0_xxzzzzz_1, g_0_zzzzzz_0_xxzzzzzz_0, g_0_zzzzzz_0_xxzzzzzz_1, g_0_zzzzzz_0_xyyyyyy_1, g_0_zzzzzz_0_xyyyyyyy_0, g_0_zzzzzz_0_xyyyyyyy_1, g_0_zzzzzz_0_xyyyyyyz_0, g_0_zzzzzz_0_xyyyyyyz_1, g_0_zzzzzz_0_xyyyyyz_1, g_0_zzzzzz_0_xyyyyyzz_0, g_0_zzzzzz_0_xyyyyyzz_1, g_0_zzzzzz_0_xyyyyzz_1, g_0_zzzzzz_0_xyyyyzzz_0, g_0_zzzzzz_0_xyyyyzzz_1, g_0_zzzzzz_0_xyyyzzz_1, g_0_zzzzzz_0_xyyyzzzz_0, g_0_zzzzzz_0_xyyyzzzz_1, g_0_zzzzzz_0_xyyzzzz_1, g_0_zzzzzz_0_xyyzzzzz_0, g_0_zzzzzz_0_xyyzzzzz_1, g_0_zzzzzz_0_xyzzzzz_1, g_0_zzzzzz_0_xyzzzzzz_0, g_0_zzzzzz_0_xyzzzzzz_1, g_0_zzzzzz_0_xzzzzzz_1, g_0_zzzzzz_0_xzzzzzzz_0, g_0_zzzzzz_0_xzzzzzzz_1, g_0_zzzzzz_0_yyyyyyy_1, g_0_zzzzzz_0_yyyyyyyy_0, g_0_zzzzzz_0_yyyyyyyy_1, g_0_zzzzzz_0_yyyyyyyz_0, g_0_zzzzzz_0_yyyyyyyz_1, g_0_zzzzzz_0_yyyyyyz_1, g_0_zzzzzz_0_yyyyyyzz_0, g_0_zzzzzz_0_yyyyyyzz_1, g_0_zzzzzz_0_yyyyyzz_1, g_0_zzzzzz_0_yyyyyzzz_0, g_0_zzzzzz_0_yyyyyzzz_1, g_0_zzzzzz_0_yyyyzzz_1, g_0_zzzzzz_0_yyyyzzzz_0, g_0_zzzzzz_0_yyyyzzzz_1, g_0_zzzzzz_0_yyyzzzz_1, g_0_zzzzzz_0_yyyzzzzz_0, g_0_zzzzzz_0_yyyzzzzz_1, g_0_zzzzzz_0_yyzzzzz_1, g_0_zzzzzz_0_yyzzzzzz_0, g_0_zzzzzz_0_yyzzzzzz_1, g_0_zzzzzz_0_yzzzzzz_1, g_0_zzzzzz_0_yzzzzzzz_0, g_0_zzzzzz_0_yzzzzzzz_1, g_0_zzzzzz_0_zzzzzzz_1, g_0_zzzzzz_0_zzzzzzzz_0, g_0_zzzzzz_0_zzzzzzzz_1, wp_x, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_xzzzzzz_0_xxxxxxxx_0[i] = 8.0 * g_0_zzzzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxxx_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxxx_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxxxy_0[i] = 7.0 * g_0_zzzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxxy_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxxy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxxxz_0[i] = 7.0 * g_0_zzzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxxz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxxz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxxyy_0[i] = 6.0 * g_0_zzzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxyy_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxxyz_0[i] = 6.0 * g_0_zzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxyz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxxzz_0[i] = 6.0 * g_0_zzzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxxzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxyyy_0[i] = 5.0 * g_0_zzzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyyy_0[i] * pb_x + g_0_zzzzzz_0_xxxxxyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxyyz_0[i] = 5.0 * g_0_zzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyyz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxyzz_0[i] = 5.0 * g_0_zzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxxzzz_0[i] = 5.0 * g_0_zzzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxxzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_zzzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyyy_0[i] * pb_x + g_0_zzzzzz_0_xxxxyyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxyyyz_0[i] = 4.0 * g_0_zzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyyz_0[i] * pb_x + g_0_zzzzzz_0_xxxxyyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxyyzz_0[i] = 4.0 * g_0_zzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxyyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxyzzz_0[i] = 4.0 * g_0_zzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxyzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxxzzzz_0[i] = 4.0 * g_0_zzzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxxzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_zzzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyyy_0[i] * pb_x + g_0_zzzzzz_0_xxxyyyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_zzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyyz_0[i] * pb_x + g_0_zzzzzz_0_xxxyyyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_zzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyzz_0[i] * pb_x + g_0_zzzzzz_0_xxxyyyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_zzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxyyzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_zzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxyzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxxzzzzz_0[i] = 3.0 * g_0_zzzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxxzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_zzzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyyy_0[i] * pb_x + g_0_zzzzzz_0_xxyyyyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_zzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyyz_0[i] * pb_x + g_0_zzzzzz_0_xxyyyyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_zzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyzz_0[i] * pb_x + g_0_zzzzzz_0_xxyyyyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_zzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyzzz_0[i] * pb_x + g_0_zzzzzz_0_xxyyyzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_zzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxyyzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_zzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxyzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xxzzzzzz_0[i] = 2.0 * g_0_zzzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xxzzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyyyyyy_0[i] = g_0_zzzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyyy_0[i] * pb_x + g_0_zzzzzz_0_xyyyyyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyyyyyz_0[i] = g_0_zzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyyz_0[i] * pb_x + g_0_zzzzzz_0_xyyyyyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyyyyzz_0[i] = g_0_zzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyzz_0[i] * pb_x + g_0_zzzzzz_0_xyyyyyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyyyzzz_0[i] = g_0_zzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyzzz_0[i] * pb_x + g_0_zzzzzz_0_xyyyyzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyyzzzz_0[i] = g_0_zzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyzzzz_0[i] * pb_x + g_0_zzzzzz_0_xyyyzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyyzzzzz_0[i] = g_0_zzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xyyzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xyzzzzzz_0[i] = g_0_zzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xyzzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_xzzzzzzz_0[i] = g_0_zzzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xzzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_xzzzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyyyyyy_0[i] = g_0_zzzzzz_0_yyyyyyyy_0[i] * pb_x + g_0_zzzzzz_0_yyyyyyyy_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyyyyyz_0[i] = g_0_zzzzzz_0_yyyyyyyz_0[i] * pb_x + g_0_zzzzzz_0_yyyyyyyz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyyyyzz_0[i] = g_0_zzzzzz_0_yyyyyyzz_0[i] * pb_x + g_0_zzzzzz_0_yyyyyyzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyyyzzz_0[i] = g_0_zzzzzz_0_yyyyyzzz_0[i] * pb_x + g_0_zzzzzz_0_yyyyyzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyyzzzz_0[i] = g_0_zzzzzz_0_yyyyzzzz_0[i] * pb_x + g_0_zzzzzz_0_yyyyzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyyzzzzz_0[i] = g_0_zzzzzz_0_yyyzzzzz_0[i] * pb_x + g_0_zzzzzz_0_yyyzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yyzzzzzz_0[i] = g_0_zzzzzz_0_yyzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_yyzzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_yzzzzzzz_0[i] = g_0_zzzzzz_0_yzzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_yzzzzzzz_1[i] * wp_x[i];

        g_0_xzzzzzz_0_zzzzzzzz_0[i] = g_0_zzzzzz_0_zzzzzzzz_0[i] * pb_x + g_0_zzzzzz_0_zzzzzzzz_1[i] * wp_x[i];
    }

    /// Set up 1260-1305 components of targeted buffer : SKSL

    auto g_0_yyyyyyy_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1260);

    auto g_0_yyyyyyy_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1261);

    auto g_0_yyyyyyy_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1262);

    auto g_0_yyyyyyy_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1263);

    auto g_0_yyyyyyy_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1264);

    auto g_0_yyyyyyy_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1265);

    auto g_0_yyyyyyy_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1266);

    auto g_0_yyyyyyy_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1267);

    auto g_0_yyyyyyy_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1268);

    auto g_0_yyyyyyy_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1269);

    auto g_0_yyyyyyy_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1270);

    auto g_0_yyyyyyy_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1271);

    auto g_0_yyyyyyy_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1272);

    auto g_0_yyyyyyy_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1273);

    auto g_0_yyyyyyy_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1274);

    auto g_0_yyyyyyy_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1275);

    auto g_0_yyyyyyy_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1276);

    auto g_0_yyyyyyy_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1277);

    auto g_0_yyyyyyy_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1278);

    auto g_0_yyyyyyy_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1279);

    auto g_0_yyyyyyy_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1280);

    auto g_0_yyyyyyy_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1281);

    auto g_0_yyyyyyy_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1282);

    auto g_0_yyyyyyy_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1283);

    auto g_0_yyyyyyy_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1284);

    auto g_0_yyyyyyy_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1285);

    auto g_0_yyyyyyy_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1286);

    auto g_0_yyyyyyy_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1287);

    auto g_0_yyyyyyy_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1288);

    auto g_0_yyyyyyy_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1289);

    auto g_0_yyyyyyy_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1290);

    auto g_0_yyyyyyy_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1291);

    auto g_0_yyyyyyy_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1292);

    auto g_0_yyyyyyy_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1293);

    auto g_0_yyyyyyy_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1294);

    auto g_0_yyyyyyy_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1295);

    auto g_0_yyyyyyy_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1296);

    auto g_0_yyyyyyy_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1297);

    auto g_0_yyyyyyy_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1298);

    auto g_0_yyyyyyy_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1299);

    auto g_0_yyyyyyy_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1300);

    auto g_0_yyyyyyy_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1301);

    auto g_0_yyyyyyy_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1302);

    auto g_0_yyyyyyy_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1303);

    auto g_0_yyyyyyy_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1304);

    #pragma omp simd aligned(g_0_yyyyy_0_xxxxxxxx_0, g_0_yyyyy_0_xxxxxxxx_1, g_0_yyyyy_0_xxxxxxxy_0, g_0_yyyyy_0_xxxxxxxy_1, g_0_yyyyy_0_xxxxxxxz_0, g_0_yyyyy_0_xxxxxxxz_1, g_0_yyyyy_0_xxxxxxyy_0, g_0_yyyyy_0_xxxxxxyy_1, g_0_yyyyy_0_xxxxxxyz_0, g_0_yyyyy_0_xxxxxxyz_1, g_0_yyyyy_0_xxxxxxzz_0, g_0_yyyyy_0_xxxxxxzz_1, g_0_yyyyy_0_xxxxxyyy_0, g_0_yyyyy_0_xxxxxyyy_1, g_0_yyyyy_0_xxxxxyyz_0, g_0_yyyyy_0_xxxxxyyz_1, g_0_yyyyy_0_xxxxxyzz_0, g_0_yyyyy_0_xxxxxyzz_1, g_0_yyyyy_0_xxxxxzzz_0, g_0_yyyyy_0_xxxxxzzz_1, g_0_yyyyy_0_xxxxyyyy_0, g_0_yyyyy_0_xxxxyyyy_1, g_0_yyyyy_0_xxxxyyyz_0, g_0_yyyyy_0_xxxxyyyz_1, g_0_yyyyy_0_xxxxyyzz_0, g_0_yyyyy_0_xxxxyyzz_1, g_0_yyyyy_0_xxxxyzzz_0, g_0_yyyyy_0_xxxxyzzz_1, g_0_yyyyy_0_xxxxzzzz_0, g_0_yyyyy_0_xxxxzzzz_1, g_0_yyyyy_0_xxxyyyyy_0, g_0_yyyyy_0_xxxyyyyy_1, g_0_yyyyy_0_xxxyyyyz_0, g_0_yyyyy_0_xxxyyyyz_1, g_0_yyyyy_0_xxxyyyzz_0, g_0_yyyyy_0_xxxyyyzz_1, g_0_yyyyy_0_xxxyyzzz_0, g_0_yyyyy_0_xxxyyzzz_1, g_0_yyyyy_0_xxxyzzzz_0, g_0_yyyyy_0_xxxyzzzz_1, g_0_yyyyy_0_xxxzzzzz_0, g_0_yyyyy_0_xxxzzzzz_1, g_0_yyyyy_0_xxyyyyyy_0, g_0_yyyyy_0_xxyyyyyy_1, g_0_yyyyy_0_xxyyyyyz_0, g_0_yyyyy_0_xxyyyyyz_1, g_0_yyyyy_0_xxyyyyzz_0, g_0_yyyyy_0_xxyyyyzz_1, g_0_yyyyy_0_xxyyyzzz_0, g_0_yyyyy_0_xxyyyzzz_1, g_0_yyyyy_0_xxyyzzzz_0, g_0_yyyyy_0_xxyyzzzz_1, g_0_yyyyy_0_xxyzzzzz_0, g_0_yyyyy_0_xxyzzzzz_1, g_0_yyyyy_0_xxzzzzzz_0, g_0_yyyyy_0_xxzzzzzz_1, g_0_yyyyy_0_xyyyyyyy_0, g_0_yyyyy_0_xyyyyyyy_1, g_0_yyyyy_0_xyyyyyyz_0, g_0_yyyyy_0_xyyyyyyz_1, g_0_yyyyy_0_xyyyyyzz_0, g_0_yyyyy_0_xyyyyyzz_1, g_0_yyyyy_0_xyyyyzzz_0, g_0_yyyyy_0_xyyyyzzz_1, g_0_yyyyy_0_xyyyzzzz_0, g_0_yyyyy_0_xyyyzzzz_1, g_0_yyyyy_0_xyyzzzzz_0, g_0_yyyyy_0_xyyzzzzz_1, g_0_yyyyy_0_xyzzzzzz_0, g_0_yyyyy_0_xyzzzzzz_1, g_0_yyyyy_0_xzzzzzzz_0, g_0_yyyyy_0_xzzzzzzz_1, g_0_yyyyy_0_yyyyyyyy_0, g_0_yyyyy_0_yyyyyyyy_1, g_0_yyyyy_0_yyyyyyyz_0, g_0_yyyyy_0_yyyyyyyz_1, g_0_yyyyy_0_yyyyyyzz_0, g_0_yyyyy_0_yyyyyyzz_1, g_0_yyyyy_0_yyyyyzzz_0, g_0_yyyyy_0_yyyyyzzz_1, g_0_yyyyy_0_yyyyzzzz_0, g_0_yyyyy_0_yyyyzzzz_1, g_0_yyyyy_0_yyyzzzzz_0, g_0_yyyyy_0_yyyzzzzz_1, g_0_yyyyy_0_yyzzzzzz_0, g_0_yyyyy_0_yyzzzzzz_1, g_0_yyyyy_0_yzzzzzzz_0, g_0_yyyyy_0_yzzzzzzz_1, g_0_yyyyy_0_zzzzzzzz_0, g_0_yyyyy_0_zzzzzzzz_1, g_0_yyyyyy_0_xxxxxxx_1, g_0_yyyyyy_0_xxxxxxxx_0, g_0_yyyyyy_0_xxxxxxxx_1, g_0_yyyyyy_0_xxxxxxxy_0, g_0_yyyyyy_0_xxxxxxxy_1, g_0_yyyyyy_0_xxxxxxxz_0, g_0_yyyyyy_0_xxxxxxxz_1, g_0_yyyyyy_0_xxxxxxy_1, g_0_yyyyyy_0_xxxxxxyy_0, g_0_yyyyyy_0_xxxxxxyy_1, g_0_yyyyyy_0_xxxxxxyz_0, g_0_yyyyyy_0_xxxxxxyz_1, g_0_yyyyyy_0_xxxxxxz_1, g_0_yyyyyy_0_xxxxxxzz_0, g_0_yyyyyy_0_xxxxxxzz_1, g_0_yyyyyy_0_xxxxxyy_1, g_0_yyyyyy_0_xxxxxyyy_0, g_0_yyyyyy_0_xxxxxyyy_1, g_0_yyyyyy_0_xxxxxyyz_0, g_0_yyyyyy_0_xxxxxyyz_1, g_0_yyyyyy_0_xxxxxyz_1, g_0_yyyyyy_0_xxxxxyzz_0, g_0_yyyyyy_0_xxxxxyzz_1, g_0_yyyyyy_0_xxxxxzz_1, g_0_yyyyyy_0_xxxxxzzz_0, g_0_yyyyyy_0_xxxxxzzz_1, g_0_yyyyyy_0_xxxxyyy_1, g_0_yyyyyy_0_xxxxyyyy_0, g_0_yyyyyy_0_xxxxyyyy_1, g_0_yyyyyy_0_xxxxyyyz_0, g_0_yyyyyy_0_xxxxyyyz_1, g_0_yyyyyy_0_xxxxyyz_1, g_0_yyyyyy_0_xxxxyyzz_0, g_0_yyyyyy_0_xxxxyyzz_1, g_0_yyyyyy_0_xxxxyzz_1, g_0_yyyyyy_0_xxxxyzzz_0, g_0_yyyyyy_0_xxxxyzzz_1, g_0_yyyyyy_0_xxxxzzz_1, g_0_yyyyyy_0_xxxxzzzz_0, g_0_yyyyyy_0_xxxxzzzz_1, g_0_yyyyyy_0_xxxyyyy_1, g_0_yyyyyy_0_xxxyyyyy_0, g_0_yyyyyy_0_xxxyyyyy_1, g_0_yyyyyy_0_xxxyyyyz_0, g_0_yyyyyy_0_xxxyyyyz_1, g_0_yyyyyy_0_xxxyyyz_1, g_0_yyyyyy_0_xxxyyyzz_0, g_0_yyyyyy_0_xxxyyyzz_1, g_0_yyyyyy_0_xxxyyzz_1, g_0_yyyyyy_0_xxxyyzzz_0, g_0_yyyyyy_0_xxxyyzzz_1, g_0_yyyyyy_0_xxxyzzz_1, g_0_yyyyyy_0_xxxyzzzz_0, g_0_yyyyyy_0_xxxyzzzz_1, g_0_yyyyyy_0_xxxzzzz_1, g_0_yyyyyy_0_xxxzzzzz_0, g_0_yyyyyy_0_xxxzzzzz_1, g_0_yyyyyy_0_xxyyyyy_1, g_0_yyyyyy_0_xxyyyyyy_0, g_0_yyyyyy_0_xxyyyyyy_1, g_0_yyyyyy_0_xxyyyyyz_0, g_0_yyyyyy_0_xxyyyyyz_1, g_0_yyyyyy_0_xxyyyyz_1, g_0_yyyyyy_0_xxyyyyzz_0, g_0_yyyyyy_0_xxyyyyzz_1, g_0_yyyyyy_0_xxyyyzz_1, g_0_yyyyyy_0_xxyyyzzz_0, g_0_yyyyyy_0_xxyyyzzz_1, g_0_yyyyyy_0_xxyyzzz_1, g_0_yyyyyy_0_xxyyzzzz_0, g_0_yyyyyy_0_xxyyzzzz_1, g_0_yyyyyy_0_xxyzzzz_1, g_0_yyyyyy_0_xxyzzzzz_0, g_0_yyyyyy_0_xxyzzzzz_1, g_0_yyyyyy_0_xxzzzzz_1, g_0_yyyyyy_0_xxzzzzzz_0, g_0_yyyyyy_0_xxzzzzzz_1, g_0_yyyyyy_0_xyyyyyy_1, g_0_yyyyyy_0_xyyyyyyy_0, g_0_yyyyyy_0_xyyyyyyy_1, g_0_yyyyyy_0_xyyyyyyz_0, g_0_yyyyyy_0_xyyyyyyz_1, g_0_yyyyyy_0_xyyyyyz_1, g_0_yyyyyy_0_xyyyyyzz_0, g_0_yyyyyy_0_xyyyyyzz_1, g_0_yyyyyy_0_xyyyyzz_1, g_0_yyyyyy_0_xyyyyzzz_0, g_0_yyyyyy_0_xyyyyzzz_1, g_0_yyyyyy_0_xyyyzzz_1, g_0_yyyyyy_0_xyyyzzzz_0, g_0_yyyyyy_0_xyyyzzzz_1, g_0_yyyyyy_0_xyyzzzz_1, g_0_yyyyyy_0_xyyzzzzz_0, g_0_yyyyyy_0_xyyzzzzz_1, g_0_yyyyyy_0_xyzzzzz_1, g_0_yyyyyy_0_xyzzzzzz_0, g_0_yyyyyy_0_xyzzzzzz_1, g_0_yyyyyy_0_xzzzzzz_1, g_0_yyyyyy_0_xzzzzzzz_0, g_0_yyyyyy_0_xzzzzzzz_1, g_0_yyyyyy_0_yyyyyyy_1, g_0_yyyyyy_0_yyyyyyyy_0, g_0_yyyyyy_0_yyyyyyyy_1, g_0_yyyyyy_0_yyyyyyyz_0, g_0_yyyyyy_0_yyyyyyyz_1, g_0_yyyyyy_0_yyyyyyz_1, g_0_yyyyyy_0_yyyyyyzz_0, g_0_yyyyyy_0_yyyyyyzz_1, g_0_yyyyyy_0_yyyyyzz_1, g_0_yyyyyy_0_yyyyyzzz_0, g_0_yyyyyy_0_yyyyyzzz_1, g_0_yyyyyy_0_yyyyzzz_1, g_0_yyyyyy_0_yyyyzzzz_0, g_0_yyyyyy_0_yyyyzzzz_1, g_0_yyyyyy_0_yyyzzzz_1, g_0_yyyyyy_0_yyyzzzzz_0, g_0_yyyyyy_0_yyyzzzzz_1, g_0_yyyyyy_0_yyzzzzz_1, g_0_yyyyyy_0_yyzzzzzz_0, g_0_yyyyyy_0_yyzzzzzz_1, g_0_yyyyyy_0_yzzzzzz_1, g_0_yyyyyy_0_yzzzzzzz_0, g_0_yyyyyy_0_yzzzzzzz_1, g_0_yyyyyy_0_zzzzzzz_1, g_0_yyyyyy_0_zzzzzzzz_0, g_0_yyyyyy_0_zzzzzzzz_1, g_0_yyyyyyy_0_xxxxxxxx_0, g_0_yyyyyyy_0_xxxxxxxy_0, g_0_yyyyyyy_0_xxxxxxxz_0, g_0_yyyyyyy_0_xxxxxxyy_0, g_0_yyyyyyy_0_xxxxxxyz_0, g_0_yyyyyyy_0_xxxxxxzz_0, g_0_yyyyyyy_0_xxxxxyyy_0, g_0_yyyyyyy_0_xxxxxyyz_0, g_0_yyyyyyy_0_xxxxxyzz_0, g_0_yyyyyyy_0_xxxxxzzz_0, g_0_yyyyyyy_0_xxxxyyyy_0, g_0_yyyyyyy_0_xxxxyyyz_0, g_0_yyyyyyy_0_xxxxyyzz_0, g_0_yyyyyyy_0_xxxxyzzz_0, g_0_yyyyyyy_0_xxxxzzzz_0, g_0_yyyyyyy_0_xxxyyyyy_0, g_0_yyyyyyy_0_xxxyyyyz_0, g_0_yyyyyyy_0_xxxyyyzz_0, g_0_yyyyyyy_0_xxxyyzzz_0, g_0_yyyyyyy_0_xxxyzzzz_0, g_0_yyyyyyy_0_xxxzzzzz_0, g_0_yyyyyyy_0_xxyyyyyy_0, g_0_yyyyyyy_0_xxyyyyyz_0, g_0_yyyyyyy_0_xxyyyyzz_0, g_0_yyyyyyy_0_xxyyyzzz_0, g_0_yyyyyyy_0_xxyyzzzz_0, g_0_yyyyyyy_0_xxyzzzzz_0, g_0_yyyyyyy_0_xxzzzzzz_0, g_0_yyyyyyy_0_xyyyyyyy_0, g_0_yyyyyyy_0_xyyyyyyz_0, g_0_yyyyyyy_0_xyyyyyzz_0, g_0_yyyyyyy_0_xyyyyzzz_0, g_0_yyyyyyy_0_xyyyzzzz_0, g_0_yyyyyyy_0_xyyzzzzz_0, g_0_yyyyyyy_0_xyzzzzzz_0, g_0_yyyyyyy_0_xzzzzzzz_0, g_0_yyyyyyy_0_yyyyyyyy_0, g_0_yyyyyyy_0_yyyyyyyz_0, g_0_yyyyyyy_0_yyyyyyzz_0, g_0_yyyyyyy_0_yyyyyzzz_0, g_0_yyyyyyy_0_yyyyzzzz_0, g_0_yyyyyyy_0_yyyzzzzz_0, g_0_yyyyyyy_0_yyzzzzzz_0, g_0_yyyyyyy_0_yzzzzzzz_0, g_0_yyyyyyy_0_zzzzzzzz_0, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_yyyyyyy_0_xxxxxxxx_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxxx_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxxxx_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxxxy_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxxy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxxy_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxxxz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxxz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxxxz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxxyy_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxyy_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxyy_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxxyz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxyz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxxzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxxzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxxzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxyyy_0[i] = 6.0 * g_0_yyyyy_0_xxxxxyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxyyy_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyyy_0[i] * pb_y + g_0_yyyyyy_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxyyz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxyyz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyyz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxyzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxyzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxxzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxxzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxxzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxyyyy_0[i] = 6.0 * g_0_yyyyy_0_xxxxyyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxyyyy_1[i] * fti_ab_0 + 4.0 * g_0_yyyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyyy_0[i] * pb_y + g_0_yyyyyy_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxyyyz_0[i] = 6.0 * g_0_yyyyy_0_xxxxyyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxyyyz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyyz_0[i] * pb_y + g_0_yyyyyy_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxyyzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxyyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxyzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxyzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxyzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxxzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxxzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxxzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxyyyyy_0[i] = 6.0 * g_0_yyyyy_0_xxxyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxyyyyy_1[i] * fti_ab_0 + 5.0 * g_0_yyyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyyy_0[i] * pb_y + g_0_yyyyyy_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxyyyyz_0[i] = 6.0 * g_0_yyyyy_0_xxxyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxyyyyz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyyz_0[i] * pb_y + g_0_yyyyyy_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxyyyzz_0[i] = 6.0 * g_0_yyyyy_0_xxxyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyzz_0[i] * pb_y + g_0_yyyyyy_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxyyzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxyzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxyzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxxzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxxzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxxzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyyyyyy_0[i] = 6.0 * g_0_yyyyy_0_xxyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyyyyyy_1[i] * fti_ab_0 + 6.0 * g_0_yyyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyyy_0[i] * pb_y + g_0_yyyyyy_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyyyyyz_0[i] = 6.0 * g_0_yyyyy_0_xxyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyyyyyz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyyz_0[i] * pb_y + g_0_yyyyyy_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyyyyzz_0[i] = 6.0 * g_0_yyyyy_0_xxyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyyyyzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyzz_0[i] * pb_y + g_0_yyyyyy_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyyyzzz_0[i] = 6.0 * g_0_yyyyy_0_xxyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyzzz_0[i] * pb_y + g_0_yyyyyy_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyyzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxyzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxyzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xxzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xxzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xxzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyyyyyy_0[i] = 6.0 * g_0_yyyyy_0_xyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyyyyyy_1[i] * fti_ab_0 + 7.0 * g_0_yyyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyyy_0[i] * pb_y + g_0_yyyyyy_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyyyyyz_0[i] = 6.0 * g_0_yyyyy_0_xyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyyyyyz_1[i] * fti_ab_0 + 6.0 * g_0_yyyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyyz_0[i] * pb_y + g_0_yyyyyy_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyyyyzz_0[i] = 6.0 * g_0_yyyyy_0_xyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyyyyzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyzz_0[i] * pb_y + g_0_yyyyyy_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyyyzzz_0[i] = 6.0 * g_0_yyyyy_0_xyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyyyzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyzzz_0[i] * pb_y + g_0_yyyyyy_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyyzzzz_0[i] = 6.0 * g_0_yyyyy_0_xyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyzzzz_0[i] * pb_y + g_0_yyyyyy_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyyzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xyzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_xzzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_xzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_xzzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyyyyyy_0[i] = 6.0 * g_0_yyyyy_0_yyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyyyyyy_1[i] * fti_ab_0 + 8.0 * g_0_yyyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyyyy_0[i] * pb_y + g_0_yyyyyy_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyyyyyz_0[i] = 6.0 * g_0_yyyyy_0_yyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyyyyyz_1[i] * fti_ab_0 + 7.0 * g_0_yyyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyyyz_0[i] * pb_y + g_0_yyyyyy_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyyyyzz_0[i] = 6.0 * g_0_yyyyy_0_yyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyyyyzz_1[i] * fti_ab_0 + 6.0 * g_0_yyyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyyzz_0[i] * pb_y + g_0_yyyyyy_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyyyzzz_0[i] = 6.0 * g_0_yyyyy_0_yyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyyyzzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyzzz_0[i] * pb_y + g_0_yyyyyy_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyyzzzz_0[i] = 6.0 * g_0_yyyyy_0_yyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyzzzz_0[i] * pb_y + g_0_yyyyyy_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyyzzzzz_0[i] = 6.0 * g_0_yyyyy_0_yyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyyzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyzzzzz_0[i] * pb_y + g_0_yyyyyy_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yyzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_yyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yyzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_yzzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_yzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yzzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyyy_0_zzzzzzzz_0[i] = 6.0 * g_0_yyyyy_0_zzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_yyyyy_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyyy_0_zzzzzzzz_0[i] * pb_y + g_0_yyyyyy_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1305-1350 components of targeted buffer : SKSL

    auto g_0_yyyyyyz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1305);

    auto g_0_yyyyyyz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1306);

    auto g_0_yyyyyyz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1307);

    auto g_0_yyyyyyz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1308);

    auto g_0_yyyyyyz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1309);

    auto g_0_yyyyyyz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1310);

    auto g_0_yyyyyyz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1311);

    auto g_0_yyyyyyz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1312);

    auto g_0_yyyyyyz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1313);

    auto g_0_yyyyyyz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1314);

    auto g_0_yyyyyyz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1315);

    auto g_0_yyyyyyz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1316);

    auto g_0_yyyyyyz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1317);

    auto g_0_yyyyyyz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1318);

    auto g_0_yyyyyyz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1319);

    auto g_0_yyyyyyz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1320);

    auto g_0_yyyyyyz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1321);

    auto g_0_yyyyyyz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1322);

    auto g_0_yyyyyyz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1323);

    auto g_0_yyyyyyz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1324);

    auto g_0_yyyyyyz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1325);

    auto g_0_yyyyyyz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1326);

    auto g_0_yyyyyyz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1327);

    auto g_0_yyyyyyz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1328);

    auto g_0_yyyyyyz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1329);

    auto g_0_yyyyyyz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1330);

    auto g_0_yyyyyyz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1331);

    auto g_0_yyyyyyz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1332);

    auto g_0_yyyyyyz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1333);

    auto g_0_yyyyyyz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1334);

    auto g_0_yyyyyyz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1335);

    auto g_0_yyyyyyz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1336);

    auto g_0_yyyyyyz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1337);

    auto g_0_yyyyyyz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1338);

    auto g_0_yyyyyyz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1339);

    auto g_0_yyyyyyz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1340);

    auto g_0_yyyyyyz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1341);

    auto g_0_yyyyyyz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1342);

    auto g_0_yyyyyyz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1343);

    auto g_0_yyyyyyz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1344);

    auto g_0_yyyyyyz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1345);

    auto g_0_yyyyyyz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1346);

    auto g_0_yyyyyyz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1347);

    auto g_0_yyyyyyz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1348);

    auto g_0_yyyyyyz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1349);

    #pragma omp simd aligned(g_0_yyyyyy_0_xxxxxxx_1, g_0_yyyyyy_0_xxxxxxxx_0, g_0_yyyyyy_0_xxxxxxxx_1, g_0_yyyyyy_0_xxxxxxxy_0, g_0_yyyyyy_0_xxxxxxxy_1, g_0_yyyyyy_0_xxxxxxxz_0, g_0_yyyyyy_0_xxxxxxxz_1, g_0_yyyyyy_0_xxxxxxy_1, g_0_yyyyyy_0_xxxxxxyy_0, g_0_yyyyyy_0_xxxxxxyy_1, g_0_yyyyyy_0_xxxxxxyz_0, g_0_yyyyyy_0_xxxxxxyz_1, g_0_yyyyyy_0_xxxxxxz_1, g_0_yyyyyy_0_xxxxxxzz_0, g_0_yyyyyy_0_xxxxxxzz_1, g_0_yyyyyy_0_xxxxxyy_1, g_0_yyyyyy_0_xxxxxyyy_0, g_0_yyyyyy_0_xxxxxyyy_1, g_0_yyyyyy_0_xxxxxyyz_0, g_0_yyyyyy_0_xxxxxyyz_1, g_0_yyyyyy_0_xxxxxyz_1, g_0_yyyyyy_0_xxxxxyzz_0, g_0_yyyyyy_0_xxxxxyzz_1, g_0_yyyyyy_0_xxxxxzz_1, g_0_yyyyyy_0_xxxxxzzz_0, g_0_yyyyyy_0_xxxxxzzz_1, g_0_yyyyyy_0_xxxxyyy_1, g_0_yyyyyy_0_xxxxyyyy_0, g_0_yyyyyy_0_xxxxyyyy_1, g_0_yyyyyy_0_xxxxyyyz_0, g_0_yyyyyy_0_xxxxyyyz_1, g_0_yyyyyy_0_xxxxyyz_1, g_0_yyyyyy_0_xxxxyyzz_0, g_0_yyyyyy_0_xxxxyyzz_1, g_0_yyyyyy_0_xxxxyzz_1, g_0_yyyyyy_0_xxxxyzzz_0, g_0_yyyyyy_0_xxxxyzzz_1, g_0_yyyyyy_0_xxxxzzz_1, g_0_yyyyyy_0_xxxxzzzz_0, g_0_yyyyyy_0_xxxxzzzz_1, g_0_yyyyyy_0_xxxyyyy_1, g_0_yyyyyy_0_xxxyyyyy_0, g_0_yyyyyy_0_xxxyyyyy_1, g_0_yyyyyy_0_xxxyyyyz_0, g_0_yyyyyy_0_xxxyyyyz_1, g_0_yyyyyy_0_xxxyyyz_1, g_0_yyyyyy_0_xxxyyyzz_0, g_0_yyyyyy_0_xxxyyyzz_1, g_0_yyyyyy_0_xxxyyzz_1, g_0_yyyyyy_0_xxxyyzzz_0, g_0_yyyyyy_0_xxxyyzzz_1, g_0_yyyyyy_0_xxxyzzz_1, g_0_yyyyyy_0_xxxyzzzz_0, g_0_yyyyyy_0_xxxyzzzz_1, g_0_yyyyyy_0_xxxzzzz_1, g_0_yyyyyy_0_xxxzzzzz_0, g_0_yyyyyy_0_xxxzzzzz_1, g_0_yyyyyy_0_xxyyyyy_1, g_0_yyyyyy_0_xxyyyyyy_0, g_0_yyyyyy_0_xxyyyyyy_1, g_0_yyyyyy_0_xxyyyyyz_0, g_0_yyyyyy_0_xxyyyyyz_1, g_0_yyyyyy_0_xxyyyyz_1, g_0_yyyyyy_0_xxyyyyzz_0, g_0_yyyyyy_0_xxyyyyzz_1, g_0_yyyyyy_0_xxyyyzz_1, g_0_yyyyyy_0_xxyyyzzz_0, g_0_yyyyyy_0_xxyyyzzz_1, g_0_yyyyyy_0_xxyyzzz_1, g_0_yyyyyy_0_xxyyzzzz_0, g_0_yyyyyy_0_xxyyzzzz_1, g_0_yyyyyy_0_xxyzzzz_1, g_0_yyyyyy_0_xxyzzzzz_0, g_0_yyyyyy_0_xxyzzzzz_1, g_0_yyyyyy_0_xxzzzzz_1, g_0_yyyyyy_0_xxzzzzzz_0, g_0_yyyyyy_0_xxzzzzzz_1, g_0_yyyyyy_0_xyyyyyy_1, g_0_yyyyyy_0_xyyyyyyy_0, g_0_yyyyyy_0_xyyyyyyy_1, g_0_yyyyyy_0_xyyyyyyz_0, g_0_yyyyyy_0_xyyyyyyz_1, g_0_yyyyyy_0_xyyyyyz_1, g_0_yyyyyy_0_xyyyyyzz_0, g_0_yyyyyy_0_xyyyyyzz_1, g_0_yyyyyy_0_xyyyyzz_1, g_0_yyyyyy_0_xyyyyzzz_0, g_0_yyyyyy_0_xyyyyzzz_1, g_0_yyyyyy_0_xyyyzzz_1, g_0_yyyyyy_0_xyyyzzzz_0, g_0_yyyyyy_0_xyyyzzzz_1, g_0_yyyyyy_0_xyyzzzz_1, g_0_yyyyyy_0_xyyzzzzz_0, g_0_yyyyyy_0_xyyzzzzz_1, g_0_yyyyyy_0_xyzzzzz_1, g_0_yyyyyy_0_xyzzzzzz_0, g_0_yyyyyy_0_xyzzzzzz_1, g_0_yyyyyy_0_xzzzzzz_1, g_0_yyyyyy_0_xzzzzzzz_0, g_0_yyyyyy_0_xzzzzzzz_1, g_0_yyyyyy_0_yyyyyyy_1, g_0_yyyyyy_0_yyyyyyyy_0, g_0_yyyyyy_0_yyyyyyyy_1, g_0_yyyyyy_0_yyyyyyyz_0, g_0_yyyyyy_0_yyyyyyyz_1, g_0_yyyyyy_0_yyyyyyz_1, g_0_yyyyyy_0_yyyyyyzz_0, g_0_yyyyyy_0_yyyyyyzz_1, g_0_yyyyyy_0_yyyyyzz_1, g_0_yyyyyy_0_yyyyyzzz_0, g_0_yyyyyy_0_yyyyyzzz_1, g_0_yyyyyy_0_yyyyzzz_1, g_0_yyyyyy_0_yyyyzzzz_0, g_0_yyyyyy_0_yyyyzzzz_1, g_0_yyyyyy_0_yyyzzzz_1, g_0_yyyyyy_0_yyyzzzzz_0, g_0_yyyyyy_0_yyyzzzzz_1, g_0_yyyyyy_0_yyzzzzz_1, g_0_yyyyyy_0_yyzzzzzz_0, g_0_yyyyyy_0_yyzzzzzz_1, g_0_yyyyyy_0_yzzzzzz_1, g_0_yyyyyy_0_yzzzzzzz_0, g_0_yyyyyy_0_yzzzzzzz_1, g_0_yyyyyy_0_zzzzzzz_1, g_0_yyyyyy_0_zzzzzzzz_0, g_0_yyyyyy_0_zzzzzzzz_1, g_0_yyyyyyz_0_xxxxxxxx_0, g_0_yyyyyyz_0_xxxxxxxy_0, g_0_yyyyyyz_0_xxxxxxxz_0, g_0_yyyyyyz_0_xxxxxxyy_0, g_0_yyyyyyz_0_xxxxxxyz_0, g_0_yyyyyyz_0_xxxxxxzz_0, g_0_yyyyyyz_0_xxxxxyyy_0, g_0_yyyyyyz_0_xxxxxyyz_0, g_0_yyyyyyz_0_xxxxxyzz_0, g_0_yyyyyyz_0_xxxxxzzz_0, g_0_yyyyyyz_0_xxxxyyyy_0, g_0_yyyyyyz_0_xxxxyyyz_0, g_0_yyyyyyz_0_xxxxyyzz_0, g_0_yyyyyyz_0_xxxxyzzz_0, g_0_yyyyyyz_0_xxxxzzzz_0, g_0_yyyyyyz_0_xxxyyyyy_0, g_0_yyyyyyz_0_xxxyyyyz_0, g_0_yyyyyyz_0_xxxyyyzz_0, g_0_yyyyyyz_0_xxxyyzzz_0, g_0_yyyyyyz_0_xxxyzzzz_0, g_0_yyyyyyz_0_xxxzzzzz_0, g_0_yyyyyyz_0_xxyyyyyy_0, g_0_yyyyyyz_0_xxyyyyyz_0, g_0_yyyyyyz_0_xxyyyyzz_0, g_0_yyyyyyz_0_xxyyyzzz_0, g_0_yyyyyyz_0_xxyyzzzz_0, g_0_yyyyyyz_0_xxyzzzzz_0, g_0_yyyyyyz_0_xxzzzzzz_0, g_0_yyyyyyz_0_xyyyyyyy_0, g_0_yyyyyyz_0_xyyyyyyz_0, g_0_yyyyyyz_0_xyyyyyzz_0, g_0_yyyyyyz_0_xyyyyzzz_0, g_0_yyyyyyz_0_xyyyzzzz_0, g_0_yyyyyyz_0_xyyzzzzz_0, g_0_yyyyyyz_0_xyzzzzzz_0, g_0_yyyyyyz_0_xzzzzzzz_0, g_0_yyyyyyz_0_yyyyyyyy_0, g_0_yyyyyyz_0_yyyyyyyz_0, g_0_yyyyyyz_0_yyyyyyzz_0, g_0_yyyyyyz_0_yyyyyzzz_0, g_0_yyyyyyz_0_yyyyzzzz_0, g_0_yyyyyyz_0_yyyzzzzz_0, g_0_yyyyyyz_0_yyzzzzzz_0, g_0_yyyyyyz_0_yzzzzzzz_0, g_0_yyyyyyz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_yyyyyyz_0_xxxxxxxx_0[i] = g_0_yyyyyy_0_xxxxxxxx_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxxxy_0[i] = g_0_yyyyyy_0_xxxxxxxy_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxxxz_0[i] = g_0_yyyyyy_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxxz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxxyy_0[i] = g_0_yyyyyy_0_xxxxxxyy_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxxyz_0[i] = g_0_yyyyyy_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxyz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxxzz_0[i] = 2.0 * g_0_yyyyyy_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxxzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxyyy_0[i] = g_0_yyyyyy_0_xxxxxyyy_0[i] * pb_z + g_0_yyyyyy_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxyyz_0[i] = g_0_yyyyyy_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyyz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxyzz_0[i] = 2.0 * g_0_yyyyyy_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxyzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxxzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxxzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxyyyy_0[i] = g_0_yyyyyy_0_xxxxyyyy_0[i] * pb_z + g_0_yyyyyy_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxyyyz_0[i] = g_0_yyyyyy_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyyz_0[i] * pb_z + g_0_yyyyyy_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxyyzz_0[i] = 2.0 * g_0_yyyyyy_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyyzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxyzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxyzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyyyy_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxxzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxyyyyy_0[i] = g_0_yyyyyy_0_xxxyyyyy_0[i] * pb_z + g_0_yyyyyy_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxyyyyz_0[i] = g_0_yyyyyy_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyyz_0[i] * pb_z + g_0_yyyyyy_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxyyyzz_0[i] = 2.0 * g_0_yyyyyy_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyyzz_0[i] * pb_z + g_0_yyyyyy_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyyzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxyzzzz_0[i] = 4.0 * g_0_yyyyyy_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxyzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxxzzzzz_0[i] = 5.0 * g_0_yyyyyy_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxxzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyyyyyy_0[i] = g_0_yyyyyy_0_xxyyyyyy_0[i] * pb_z + g_0_yyyyyy_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyyyyyz_0[i] = g_0_yyyyyy_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyyz_0[i] * pb_z + g_0_yyyyyy_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyyyyzz_0[i] = 2.0 * g_0_yyyyyy_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyyzz_0[i] * pb_z + g_0_yyyyyy_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyyyzzz_0[i] = 3.0 * g_0_yyyyyy_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyyzzz_0[i] * pb_z + g_0_yyyyyy_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyyzzzz_0[i] = 4.0 * g_0_yyyyyy_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyyzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxyzzzzz_0[i] = 5.0 * g_0_yyyyyy_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxyzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xxzzzzzz_0[i] = 6.0 * g_0_yyyyyy_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xxzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyyyyyy_0[i] = g_0_yyyyyy_0_xyyyyyyy_0[i] * pb_z + g_0_yyyyyy_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyyyyyz_0[i] = g_0_yyyyyy_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyyz_0[i] * pb_z + g_0_yyyyyy_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyyyyzz_0[i] = 2.0 * g_0_yyyyyy_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyyzz_0[i] * pb_z + g_0_yyyyyy_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyyyzzz_0[i] = 3.0 * g_0_yyyyyy_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyyzzz_0[i] * pb_z + g_0_yyyyyy_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyyzzzz_0[i] = 4.0 * g_0_yyyyyy_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyyzzzz_0[i] * pb_z + g_0_yyyyyy_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyyzzzzz_0[i] = 5.0 * g_0_yyyyyy_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyyzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xyzzzzzz_0[i] = 6.0 * g_0_yyyyyy_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xyzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_xzzzzzzz_0[i] = 7.0 * g_0_yyyyyy_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_xzzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyyyyyy_0[i] = g_0_yyyyyy_0_yyyyyyyy_0[i] * pb_z + g_0_yyyyyy_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyyyyyz_0[i] = g_0_yyyyyy_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyyyz_0[i] * pb_z + g_0_yyyyyy_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyyyyzz_0[i] = 2.0 * g_0_yyyyyy_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyyzz_0[i] * pb_z + g_0_yyyyyy_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyyyzzz_0[i] = 3.0 * g_0_yyyyyy_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyyzzz_0[i] * pb_z + g_0_yyyyyy_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyyzzzz_0[i] = 4.0 * g_0_yyyyyy_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyyzzzz_0[i] * pb_z + g_0_yyyyyy_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyyzzzzz_0[i] = 5.0 * g_0_yyyyyy_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyyzzzzz_0[i] * pb_z + g_0_yyyyyy_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yyzzzzzz_0[i] = 6.0 * g_0_yyyyyy_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yyzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_yzzzzzzz_0[i] = 7.0 * g_0_yyyyyy_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_yzzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_yyyyyyz_0_zzzzzzzz_0[i] = 8.0 * g_0_yyyyyy_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyyy_0_zzzzzzzz_0[i] * pb_z + g_0_yyyyyy_0_zzzzzzzz_1[i] * wp_z[i];
    }

    /// Set up 1350-1395 components of targeted buffer : SKSL

    auto g_0_yyyyyzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1350);

    auto g_0_yyyyyzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1351);

    auto g_0_yyyyyzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1352);

    auto g_0_yyyyyzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1353);

    auto g_0_yyyyyzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1354);

    auto g_0_yyyyyzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1355);

    auto g_0_yyyyyzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1356);

    auto g_0_yyyyyzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1357);

    auto g_0_yyyyyzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1358);

    auto g_0_yyyyyzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1359);

    auto g_0_yyyyyzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1360);

    auto g_0_yyyyyzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1361);

    auto g_0_yyyyyzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1362);

    auto g_0_yyyyyzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1363);

    auto g_0_yyyyyzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1364);

    auto g_0_yyyyyzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1365);

    auto g_0_yyyyyzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1366);

    auto g_0_yyyyyzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1367);

    auto g_0_yyyyyzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1368);

    auto g_0_yyyyyzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1369);

    auto g_0_yyyyyzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1370);

    auto g_0_yyyyyzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1371);

    auto g_0_yyyyyzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1372);

    auto g_0_yyyyyzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1373);

    auto g_0_yyyyyzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1374);

    auto g_0_yyyyyzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1375);

    auto g_0_yyyyyzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1376);

    auto g_0_yyyyyzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1377);

    auto g_0_yyyyyzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1378);

    auto g_0_yyyyyzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1379);

    auto g_0_yyyyyzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1380);

    auto g_0_yyyyyzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1381);

    auto g_0_yyyyyzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1382);

    auto g_0_yyyyyzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1383);

    auto g_0_yyyyyzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1384);

    auto g_0_yyyyyzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1385);

    auto g_0_yyyyyzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1386);

    auto g_0_yyyyyzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1387);

    auto g_0_yyyyyzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1388);

    auto g_0_yyyyyzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1389);

    auto g_0_yyyyyzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1390);

    auto g_0_yyyyyzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1391);

    auto g_0_yyyyyzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1392);

    auto g_0_yyyyyzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1393);

    auto g_0_yyyyyzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1394);

    #pragma omp simd aligned(g_0_yyyyy_0_xxxxxxxy_0, g_0_yyyyy_0_xxxxxxxy_1, g_0_yyyyy_0_xxxxxxyy_0, g_0_yyyyy_0_xxxxxxyy_1, g_0_yyyyy_0_xxxxxyyy_0, g_0_yyyyy_0_xxxxxyyy_1, g_0_yyyyy_0_xxxxyyyy_0, g_0_yyyyy_0_xxxxyyyy_1, g_0_yyyyy_0_xxxyyyyy_0, g_0_yyyyy_0_xxxyyyyy_1, g_0_yyyyy_0_xxyyyyyy_0, g_0_yyyyy_0_xxyyyyyy_1, g_0_yyyyy_0_xyyyyyyy_0, g_0_yyyyy_0_xyyyyyyy_1, g_0_yyyyy_0_yyyyyyyy_0, g_0_yyyyy_0_yyyyyyyy_1, g_0_yyyyyz_0_xxxxxxxy_0, g_0_yyyyyz_0_xxxxxxxy_1, g_0_yyyyyz_0_xxxxxxyy_0, g_0_yyyyyz_0_xxxxxxyy_1, g_0_yyyyyz_0_xxxxxyyy_0, g_0_yyyyyz_0_xxxxxyyy_1, g_0_yyyyyz_0_xxxxyyyy_0, g_0_yyyyyz_0_xxxxyyyy_1, g_0_yyyyyz_0_xxxyyyyy_0, g_0_yyyyyz_0_xxxyyyyy_1, g_0_yyyyyz_0_xxyyyyyy_0, g_0_yyyyyz_0_xxyyyyyy_1, g_0_yyyyyz_0_xyyyyyyy_0, g_0_yyyyyz_0_xyyyyyyy_1, g_0_yyyyyz_0_yyyyyyyy_0, g_0_yyyyyz_0_yyyyyyyy_1, g_0_yyyyyzz_0_xxxxxxxx_0, g_0_yyyyyzz_0_xxxxxxxy_0, g_0_yyyyyzz_0_xxxxxxxz_0, g_0_yyyyyzz_0_xxxxxxyy_0, g_0_yyyyyzz_0_xxxxxxyz_0, g_0_yyyyyzz_0_xxxxxxzz_0, g_0_yyyyyzz_0_xxxxxyyy_0, g_0_yyyyyzz_0_xxxxxyyz_0, g_0_yyyyyzz_0_xxxxxyzz_0, g_0_yyyyyzz_0_xxxxxzzz_0, g_0_yyyyyzz_0_xxxxyyyy_0, g_0_yyyyyzz_0_xxxxyyyz_0, g_0_yyyyyzz_0_xxxxyyzz_0, g_0_yyyyyzz_0_xxxxyzzz_0, g_0_yyyyyzz_0_xxxxzzzz_0, g_0_yyyyyzz_0_xxxyyyyy_0, g_0_yyyyyzz_0_xxxyyyyz_0, g_0_yyyyyzz_0_xxxyyyzz_0, g_0_yyyyyzz_0_xxxyyzzz_0, g_0_yyyyyzz_0_xxxyzzzz_0, g_0_yyyyyzz_0_xxxzzzzz_0, g_0_yyyyyzz_0_xxyyyyyy_0, g_0_yyyyyzz_0_xxyyyyyz_0, g_0_yyyyyzz_0_xxyyyyzz_0, g_0_yyyyyzz_0_xxyyyzzz_0, g_0_yyyyyzz_0_xxyyzzzz_0, g_0_yyyyyzz_0_xxyzzzzz_0, g_0_yyyyyzz_0_xxzzzzzz_0, g_0_yyyyyzz_0_xyyyyyyy_0, g_0_yyyyyzz_0_xyyyyyyz_0, g_0_yyyyyzz_0_xyyyyyzz_0, g_0_yyyyyzz_0_xyyyyzzz_0, g_0_yyyyyzz_0_xyyyzzzz_0, g_0_yyyyyzz_0_xyyzzzzz_0, g_0_yyyyyzz_0_xyzzzzzz_0, g_0_yyyyyzz_0_xzzzzzzz_0, g_0_yyyyyzz_0_yyyyyyyy_0, g_0_yyyyyzz_0_yyyyyyyz_0, g_0_yyyyyzz_0_yyyyyyzz_0, g_0_yyyyyzz_0_yyyyyzzz_0, g_0_yyyyyzz_0_yyyyzzzz_0, g_0_yyyyyzz_0_yyyzzzzz_0, g_0_yyyyyzz_0_yyzzzzzz_0, g_0_yyyyyzz_0_yzzzzzzz_0, g_0_yyyyyzz_0_zzzzzzzz_0, g_0_yyyyzz_0_xxxxxxxx_0, g_0_yyyyzz_0_xxxxxxxx_1, g_0_yyyyzz_0_xxxxxxxz_0, g_0_yyyyzz_0_xxxxxxxz_1, g_0_yyyyzz_0_xxxxxxyz_0, g_0_yyyyzz_0_xxxxxxyz_1, g_0_yyyyzz_0_xxxxxxz_1, g_0_yyyyzz_0_xxxxxxzz_0, g_0_yyyyzz_0_xxxxxxzz_1, g_0_yyyyzz_0_xxxxxyyz_0, g_0_yyyyzz_0_xxxxxyyz_1, g_0_yyyyzz_0_xxxxxyz_1, g_0_yyyyzz_0_xxxxxyzz_0, g_0_yyyyzz_0_xxxxxyzz_1, g_0_yyyyzz_0_xxxxxzz_1, g_0_yyyyzz_0_xxxxxzzz_0, g_0_yyyyzz_0_xxxxxzzz_1, g_0_yyyyzz_0_xxxxyyyz_0, g_0_yyyyzz_0_xxxxyyyz_1, g_0_yyyyzz_0_xxxxyyz_1, g_0_yyyyzz_0_xxxxyyzz_0, g_0_yyyyzz_0_xxxxyyzz_1, g_0_yyyyzz_0_xxxxyzz_1, g_0_yyyyzz_0_xxxxyzzz_0, g_0_yyyyzz_0_xxxxyzzz_1, g_0_yyyyzz_0_xxxxzzz_1, g_0_yyyyzz_0_xxxxzzzz_0, g_0_yyyyzz_0_xxxxzzzz_1, g_0_yyyyzz_0_xxxyyyyz_0, g_0_yyyyzz_0_xxxyyyyz_1, g_0_yyyyzz_0_xxxyyyz_1, g_0_yyyyzz_0_xxxyyyzz_0, g_0_yyyyzz_0_xxxyyyzz_1, g_0_yyyyzz_0_xxxyyzz_1, g_0_yyyyzz_0_xxxyyzzz_0, g_0_yyyyzz_0_xxxyyzzz_1, g_0_yyyyzz_0_xxxyzzz_1, g_0_yyyyzz_0_xxxyzzzz_0, g_0_yyyyzz_0_xxxyzzzz_1, g_0_yyyyzz_0_xxxzzzz_1, g_0_yyyyzz_0_xxxzzzzz_0, g_0_yyyyzz_0_xxxzzzzz_1, g_0_yyyyzz_0_xxyyyyyz_0, g_0_yyyyzz_0_xxyyyyyz_1, g_0_yyyyzz_0_xxyyyyz_1, g_0_yyyyzz_0_xxyyyyzz_0, g_0_yyyyzz_0_xxyyyyzz_1, g_0_yyyyzz_0_xxyyyzz_1, g_0_yyyyzz_0_xxyyyzzz_0, g_0_yyyyzz_0_xxyyyzzz_1, g_0_yyyyzz_0_xxyyzzz_1, g_0_yyyyzz_0_xxyyzzzz_0, g_0_yyyyzz_0_xxyyzzzz_1, g_0_yyyyzz_0_xxyzzzz_1, g_0_yyyyzz_0_xxyzzzzz_0, g_0_yyyyzz_0_xxyzzzzz_1, g_0_yyyyzz_0_xxzzzzz_1, g_0_yyyyzz_0_xxzzzzzz_0, g_0_yyyyzz_0_xxzzzzzz_1, g_0_yyyyzz_0_xyyyyyyz_0, g_0_yyyyzz_0_xyyyyyyz_1, g_0_yyyyzz_0_xyyyyyz_1, g_0_yyyyzz_0_xyyyyyzz_0, g_0_yyyyzz_0_xyyyyyzz_1, g_0_yyyyzz_0_xyyyyzz_1, g_0_yyyyzz_0_xyyyyzzz_0, g_0_yyyyzz_0_xyyyyzzz_1, g_0_yyyyzz_0_xyyyzzz_1, g_0_yyyyzz_0_xyyyzzzz_0, g_0_yyyyzz_0_xyyyzzzz_1, g_0_yyyyzz_0_xyyzzzz_1, g_0_yyyyzz_0_xyyzzzzz_0, g_0_yyyyzz_0_xyyzzzzz_1, g_0_yyyyzz_0_xyzzzzz_1, g_0_yyyyzz_0_xyzzzzzz_0, g_0_yyyyzz_0_xyzzzzzz_1, g_0_yyyyzz_0_xzzzzzz_1, g_0_yyyyzz_0_xzzzzzzz_0, g_0_yyyyzz_0_xzzzzzzz_1, g_0_yyyyzz_0_yyyyyyyz_0, g_0_yyyyzz_0_yyyyyyyz_1, g_0_yyyyzz_0_yyyyyyz_1, g_0_yyyyzz_0_yyyyyyzz_0, g_0_yyyyzz_0_yyyyyyzz_1, g_0_yyyyzz_0_yyyyyzz_1, g_0_yyyyzz_0_yyyyyzzz_0, g_0_yyyyzz_0_yyyyyzzz_1, g_0_yyyyzz_0_yyyyzzz_1, g_0_yyyyzz_0_yyyyzzzz_0, g_0_yyyyzz_0_yyyyzzzz_1, g_0_yyyyzz_0_yyyzzzz_1, g_0_yyyyzz_0_yyyzzzzz_0, g_0_yyyyzz_0_yyyzzzzz_1, g_0_yyyyzz_0_yyzzzzz_1, g_0_yyyyzz_0_yyzzzzzz_0, g_0_yyyyzz_0_yyzzzzzz_1, g_0_yyyyzz_0_yzzzzzz_1, g_0_yyyyzz_0_yzzzzzzz_0, g_0_yyyyzz_0_yzzzzzzz_1, g_0_yyyyzz_0_zzzzzzz_1, g_0_yyyyzz_0_zzzzzzzz_0, g_0_yyyyzz_0_zzzzzzzz_1, g_0_yyyzz_0_xxxxxxxx_0, g_0_yyyzz_0_xxxxxxxx_1, g_0_yyyzz_0_xxxxxxxz_0, g_0_yyyzz_0_xxxxxxxz_1, g_0_yyyzz_0_xxxxxxyz_0, g_0_yyyzz_0_xxxxxxyz_1, g_0_yyyzz_0_xxxxxxzz_0, g_0_yyyzz_0_xxxxxxzz_1, g_0_yyyzz_0_xxxxxyyz_0, g_0_yyyzz_0_xxxxxyyz_1, g_0_yyyzz_0_xxxxxyzz_0, g_0_yyyzz_0_xxxxxyzz_1, g_0_yyyzz_0_xxxxxzzz_0, g_0_yyyzz_0_xxxxxzzz_1, g_0_yyyzz_0_xxxxyyyz_0, g_0_yyyzz_0_xxxxyyyz_1, g_0_yyyzz_0_xxxxyyzz_0, g_0_yyyzz_0_xxxxyyzz_1, g_0_yyyzz_0_xxxxyzzz_0, g_0_yyyzz_0_xxxxyzzz_1, g_0_yyyzz_0_xxxxzzzz_0, g_0_yyyzz_0_xxxxzzzz_1, g_0_yyyzz_0_xxxyyyyz_0, g_0_yyyzz_0_xxxyyyyz_1, g_0_yyyzz_0_xxxyyyzz_0, g_0_yyyzz_0_xxxyyyzz_1, g_0_yyyzz_0_xxxyyzzz_0, g_0_yyyzz_0_xxxyyzzz_1, g_0_yyyzz_0_xxxyzzzz_0, g_0_yyyzz_0_xxxyzzzz_1, g_0_yyyzz_0_xxxzzzzz_0, g_0_yyyzz_0_xxxzzzzz_1, g_0_yyyzz_0_xxyyyyyz_0, g_0_yyyzz_0_xxyyyyyz_1, g_0_yyyzz_0_xxyyyyzz_0, g_0_yyyzz_0_xxyyyyzz_1, g_0_yyyzz_0_xxyyyzzz_0, g_0_yyyzz_0_xxyyyzzz_1, g_0_yyyzz_0_xxyyzzzz_0, g_0_yyyzz_0_xxyyzzzz_1, g_0_yyyzz_0_xxyzzzzz_0, g_0_yyyzz_0_xxyzzzzz_1, g_0_yyyzz_0_xxzzzzzz_0, g_0_yyyzz_0_xxzzzzzz_1, g_0_yyyzz_0_xyyyyyyz_0, g_0_yyyzz_0_xyyyyyyz_1, g_0_yyyzz_0_xyyyyyzz_0, g_0_yyyzz_0_xyyyyyzz_1, g_0_yyyzz_0_xyyyyzzz_0, g_0_yyyzz_0_xyyyyzzz_1, g_0_yyyzz_0_xyyyzzzz_0, g_0_yyyzz_0_xyyyzzzz_1, g_0_yyyzz_0_xyyzzzzz_0, g_0_yyyzz_0_xyyzzzzz_1, g_0_yyyzz_0_xyzzzzzz_0, g_0_yyyzz_0_xyzzzzzz_1, g_0_yyyzz_0_xzzzzzzz_0, g_0_yyyzz_0_xzzzzzzz_1, g_0_yyyzz_0_yyyyyyyz_0, g_0_yyyzz_0_yyyyyyyz_1, g_0_yyyzz_0_yyyyyyzz_0, g_0_yyyzz_0_yyyyyyzz_1, g_0_yyyzz_0_yyyyyzzz_0, g_0_yyyzz_0_yyyyyzzz_1, g_0_yyyzz_0_yyyyzzzz_0, g_0_yyyzz_0_yyyyzzzz_1, g_0_yyyzz_0_yyyzzzzz_0, g_0_yyyzz_0_yyyzzzzz_1, g_0_yyyzz_0_yyzzzzzz_0, g_0_yyyzz_0_yyzzzzzz_1, g_0_yyyzz_0_yzzzzzzz_0, g_0_yyyzz_0_yzzzzzzz_1, g_0_yyyzz_0_zzzzzzzz_0, g_0_yyyzz_0_zzzzzzzz_1, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_yyyyyzz_0_xxxxxxxx_0[i] = 4.0 * g_0_yyyzz_0_xxxxxxxx_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxxx_0[i] * pb_y + g_0_yyyyzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxxxy_0[i] = g_0_yyyyy_0_xxxxxxxy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxxxxxxy_0[i] * pb_z + g_0_yyyyyz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxxxxxxz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxxxz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxxz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxxyy_0[i] = g_0_yyyyy_0_xxxxxxyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxxxxxyy_0[i] * pb_z + g_0_yyyyyz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxxxxxyz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxxyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxxyz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxxzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxxzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxyyy_0[i] = g_0_yyyyy_0_xxxxxyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxxxxyyy_0[i] * pb_z + g_0_yyyyyz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxxxxyyz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxyyz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxyyz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxyzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxyzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxxyzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxxzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxxzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxyyyy_0[i] = g_0_yyyyy_0_xxxxyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxxxyyyy_0[i] * pb_z + g_0_yyyyyz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxxxyyyz_0[i] = 4.0 * g_0_yyyzz_0_xxxxyyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxyyyz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyyyz_0[i] * pb_y + g_0_yyyyzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxyyzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxyyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyyzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxyzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxyzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxyzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxxyzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxxzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxxzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxyyyyy_0[i] = g_0_yyyyy_0_xxxyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxxyyyyy_0[i] * pb_z + g_0_yyyyyz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxxyyyyz_0[i] = 4.0 * g_0_yyyzz_0_xxxyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxyyyyz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyyyz_0[i] * pb_y + g_0_yyyyzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxyyyzz_0[i] = 4.0 * g_0_yyyzz_0_xxxyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyyzz_0[i] * pb_y + g_0_yyyyzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxyyzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyyzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxyzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxyzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxxyzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxxzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxxzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxyyyyyy_0[i] = g_0_yyyyy_0_xxyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xxyyyyyy_0[i] * pb_z + g_0_yyyyyz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xxyyyyyz_0[i] = 4.0 * g_0_yyyzz_0_xxyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxyyyyyz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyyyz_0[i] * pb_y + g_0_yyyyzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxyyyyzz_0[i] = 4.0 * g_0_yyyzz_0_xxyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxyyyyzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyyzz_0[i] * pb_y + g_0_yyyyzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxyyyzzz_0[i] = 4.0 * g_0_yyyzz_0_xxyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyyzzz_0[i] * pb_y + g_0_yyyyzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxyyzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyyzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxyzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxyzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xxyzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xxzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xxzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyyyyyyy_0[i] = g_0_yyyyy_0_xyyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_xyyyyyyy_0[i] * pb_z + g_0_yyyyyz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_xyyyyyyz_0[i] = 4.0 * g_0_yyyzz_0_xyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyyyyyyz_1[i] * fti_ab_0 + 6.0 * g_0_yyyyzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyyyz_0[i] * pb_y + g_0_yyyyzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyyyyyzz_0[i] = 4.0 * g_0_yyyzz_0_xyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyyyyyzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyyzz_0[i] * pb_y + g_0_yyyyzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyyyyzzz_0[i] = 4.0 * g_0_yyyzz_0_xyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyyyyzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyyzzz_0[i] * pb_y + g_0_yyyyzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyyyzzzz_0[i] = 4.0 * g_0_yyyzz_0_xyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyyyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyyzzzz_0[i] * pb_y + g_0_yyyyzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyyzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyyzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xyzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_xyzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_xzzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_xzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_xzzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyyyyyyy_0[i] = g_0_yyyyy_0_yyyyyyyy_0[i] * fi_ab_0 - g_0_yyyyy_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_yyyyyz_0_yyyyyyyy_0[i] * pb_z + g_0_yyyyyz_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyyzz_0_yyyyyyyz_0[i] = 4.0 * g_0_yyyzz_0_yyyyyyyz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyyyyyyz_1[i] * fti_ab_0 + 7.0 * g_0_yyyyzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyyyyyyz_0[i] * pb_y + g_0_yyyyzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyyyyyzz_0[i] = 4.0 * g_0_yyyzz_0_yyyyyyzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyyyyyzz_1[i] * fti_ab_0 + 6.0 * g_0_yyyyzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyyyyyzz_0[i] * pb_y + g_0_yyyyzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyyyyzzz_0[i] = 4.0 * g_0_yyyzz_0_yyyyyzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyyyyzzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyyzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyyyyzzz_0[i] * pb_y + g_0_yyyyzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyyyzzzz_0[i] = 4.0 * g_0_yyyzz_0_yyyyzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyyzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyyyzzzz_0[i] * pb_y + g_0_yyyyzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyyzzzzz_0[i] = 4.0 * g_0_yyyzz_0_yyyzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyyzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyyzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyyzzzzz_0[i] * pb_y + g_0_yyyyzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yyzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_yyzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yyzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyyzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yyzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_yzzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_yzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyyzz_0_yzzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyyzz_0_zzzzzzzz_0[i] = 4.0 * g_0_yyyzz_0_zzzzzzzz_0[i] * fi_ab_0 - 4.0 * g_0_yyyzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_yyyyzz_0_zzzzzzzz_0[i] * pb_y + g_0_yyyyzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1395-1440 components of targeted buffer : SKSL

    auto g_0_yyyyzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1395);

    auto g_0_yyyyzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1396);

    auto g_0_yyyyzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1397);

    auto g_0_yyyyzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1398);

    auto g_0_yyyyzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1399);

    auto g_0_yyyyzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1400);

    auto g_0_yyyyzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1401);

    auto g_0_yyyyzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1402);

    auto g_0_yyyyzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1403);

    auto g_0_yyyyzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1404);

    auto g_0_yyyyzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1405);

    auto g_0_yyyyzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1406);

    auto g_0_yyyyzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1407);

    auto g_0_yyyyzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1408);

    auto g_0_yyyyzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1409);

    auto g_0_yyyyzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1410);

    auto g_0_yyyyzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1411);

    auto g_0_yyyyzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1412);

    auto g_0_yyyyzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1413);

    auto g_0_yyyyzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1414);

    auto g_0_yyyyzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1415);

    auto g_0_yyyyzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1416);

    auto g_0_yyyyzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1417);

    auto g_0_yyyyzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1418);

    auto g_0_yyyyzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1419);

    auto g_0_yyyyzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1420);

    auto g_0_yyyyzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1421);

    auto g_0_yyyyzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1422);

    auto g_0_yyyyzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1423);

    auto g_0_yyyyzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1424);

    auto g_0_yyyyzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1425);

    auto g_0_yyyyzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1426);

    auto g_0_yyyyzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1427);

    auto g_0_yyyyzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1428);

    auto g_0_yyyyzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1429);

    auto g_0_yyyyzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1430);

    auto g_0_yyyyzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1431);

    auto g_0_yyyyzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1432);

    auto g_0_yyyyzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1433);

    auto g_0_yyyyzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1434);

    auto g_0_yyyyzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1435);

    auto g_0_yyyyzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1436);

    auto g_0_yyyyzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1437);

    auto g_0_yyyyzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1438);

    auto g_0_yyyyzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1439);

    #pragma omp simd aligned(g_0_yyyyz_0_xxxxxxxy_0, g_0_yyyyz_0_xxxxxxxy_1, g_0_yyyyz_0_xxxxxxyy_0, g_0_yyyyz_0_xxxxxxyy_1, g_0_yyyyz_0_xxxxxyyy_0, g_0_yyyyz_0_xxxxxyyy_1, g_0_yyyyz_0_xxxxyyyy_0, g_0_yyyyz_0_xxxxyyyy_1, g_0_yyyyz_0_xxxyyyyy_0, g_0_yyyyz_0_xxxyyyyy_1, g_0_yyyyz_0_xxyyyyyy_0, g_0_yyyyz_0_xxyyyyyy_1, g_0_yyyyz_0_xyyyyyyy_0, g_0_yyyyz_0_xyyyyyyy_1, g_0_yyyyz_0_yyyyyyyy_0, g_0_yyyyz_0_yyyyyyyy_1, g_0_yyyyzz_0_xxxxxxxy_0, g_0_yyyyzz_0_xxxxxxxy_1, g_0_yyyyzz_0_xxxxxxyy_0, g_0_yyyyzz_0_xxxxxxyy_1, g_0_yyyyzz_0_xxxxxyyy_0, g_0_yyyyzz_0_xxxxxyyy_1, g_0_yyyyzz_0_xxxxyyyy_0, g_0_yyyyzz_0_xxxxyyyy_1, g_0_yyyyzz_0_xxxyyyyy_0, g_0_yyyyzz_0_xxxyyyyy_1, g_0_yyyyzz_0_xxyyyyyy_0, g_0_yyyyzz_0_xxyyyyyy_1, g_0_yyyyzz_0_xyyyyyyy_0, g_0_yyyyzz_0_xyyyyyyy_1, g_0_yyyyzz_0_yyyyyyyy_0, g_0_yyyyzz_0_yyyyyyyy_1, g_0_yyyyzzz_0_xxxxxxxx_0, g_0_yyyyzzz_0_xxxxxxxy_0, g_0_yyyyzzz_0_xxxxxxxz_0, g_0_yyyyzzz_0_xxxxxxyy_0, g_0_yyyyzzz_0_xxxxxxyz_0, g_0_yyyyzzz_0_xxxxxxzz_0, g_0_yyyyzzz_0_xxxxxyyy_0, g_0_yyyyzzz_0_xxxxxyyz_0, g_0_yyyyzzz_0_xxxxxyzz_0, g_0_yyyyzzz_0_xxxxxzzz_0, g_0_yyyyzzz_0_xxxxyyyy_0, g_0_yyyyzzz_0_xxxxyyyz_0, g_0_yyyyzzz_0_xxxxyyzz_0, g_0_yyyyzzz_0_xxxxyzzz_0, g_0_yyyyzzz_0_xxxxzzzz_0, g_0_yyyyzzz_0_xxxyyyyy_0, g_0_yyyyzzz_0_xxxyyyyz_0, g_0_yyyyzzz_0_xxxyyyzz_0, g_0_yyyyzzz_0_xxxyyzzz_0, g_0_yyyyzzz_0_xxxyzzzz_0, g_0_yyyyzzz_0_xxxzzzzz_0, g_0_yyyyzzz_0_xxyyyyyy_0, g_0_yyyyzzz_0_xxyyyyyz_0, g_0_yyyyzzz_0_xxyyyyzz_0, g_0_yyyyzzz_0_xxyyyzzz_0, g_0_yyyyzzz_0_xxyyzzzz_0, g_0_yyyyzzz_0_xxyzzzzz_0, g_0_yyyyzzz_0_xxzzzzzz_0, g_0_yyyyzzz_0_xyyyyyyy_0, g_0_yyyyzzz_0_xyyyyyyz_0, g_0_yyyyzzz_0_xyyyyyzz_0, g_0_yyyyzzz_0_xyyyyzzz_0, g_0_yyyyzzz_0_xyyyzzzz_0, g_0_yyyyzzz_0_xyyzzzzz_0, g_0_yyyyzzz_0_xyzzzzzz_0, g_0_yyyyzzz_0_xzzzzzzz_0, g_0_yyyyzzz_0_yyyyyyyy_0, g_0_yyyyzzz_0_yyyyyyyz_0, g_0_yyyyzzz_0_yyyyyyzz_0, g_0_yyyyzzz_0_yyyyyzzz_0, g_0_yyyyzzz_0_yyyyzzzz_0, g_0_yyyyzzz_0_yyyzzzzz_0, g_0_yyyyzzz_0_yyzzzzzz_0, g_0_yyyyzzz_0_yzzzzzzz_0, g_0_yyyyzzz_0_zzzzzzzz_0, g_0_yyyzzz_0_xxxxxxxx_0, g_0_yyyzzz_0_xxxxxxxx_1, g_0_yyyzzz_0_xxxxxxxz_0, g_0_yyyzzz_0_xxxxxxxz_1, g_0_yyyzzz_0_xxxxxxyz_0, g_0_yyyzzz_0_xxxxxxyz_1, g_0_yyyzzz_0_xxxxxxz_1, g_0_yyyzzz_0_xxxxxxzz_0, g_0_yyyzzz_0_xxxxxxzz_1, g_0_yyyzzz_0_xxxxxyyz_0, g_0_yyyzzz_0_xxxxxyyz_1, g_0_yyyzzz_0_xxxxxyz_1, g_0_yyyzzz_0_xxxxxyzz_0, g_0_yyyzzz_0_xxxxxyzz_1, g_0_yyyzzz_0_xxxxxzz_1, g_0_yyyzzz_0_xxxxxzzz_0, g_0_yyyzzz_0_xxxxxzzz_1, g_0_yyyzzz_0_xxxxyyyz_0, g_0_yyyzzz_0_xxxxyyyz_1, g_0_yyyzzz_0_xxxxyyz_1, g_0_yyyzzz_0_xxxxyyzz_0, g_0_yyyzzz_0_xxxxyyzz_1, g_0_yyyzzz_0_xxxxyzz_1, g_0_yyyzzz_0_xxxxyzzz_0, g_0_yyyzzz_0_xxxxyzzz_1, g_0_yyyzzz_0_xxxxzzz_1, g_0_yyyzzz_0_xxxxzzzz_0, g_0_yyyzzz_0_xxxxzzzz_1, g_0_yyyzzz_0_xxxyyyyz_0, g_0_yyyzzz_0_xxxyyyyz_1, g_0_yyyzzz_0_xxxyyyz_1, g_0_yyyzzz_0_xxxyyyzz_0, g_0_yyyzzz_0_xxxyyyzz_1, g_0_yyyzzz_0_xxxyyzz_1, g_0_yyyzzz_0_xxxyyzzz_0, g_0_yyyzzz_0_xxxyyzzz_1, g_0_yyyzzz_0_xxxyzzz_1, g_0_yyyzzz_0_xxxyzzzz_0, g_0_yyyzzz_0_xxxyzzzz_1, g_0_yyyzzz_0_xxxzzzz_1, g_0_yyyzzz_0_xxxzzzzz_0, g_0_yyyzzz_0_xxxzzzzz_1, g_0_yyyzzz_0_xxyyyyyz_0, g_0_yyyzzz_0_xxyyyyyz_1, g_0_yyyzzz_0_xxyyyyz_1, g_0_yyyzzz_0_xxyyyyzz_0, g_0_yyyzzz_0_xxyyyyzz_1, g_0_yyyzzz_0_xxyyyzz_1, g_0_yyyzzz_0_xxyyyzzz_0, g_0_yyyzzz_0_xxyyyzzz_1, g_0_yyyzzz_0_xxyyzzz_1, g_0_yyyzzz_0_xxyyzzzz_0, g_0_yyyzzz_0_xxyyzzzz_1, g_0_yyyzzz_0_xxyzzzz_1, g_0_yyyzzz_0_xxyzzzzz_0, g_0_yyyzzz_0_xxyzzzzz_1, g_0_yyyzzz_0_xxzzzzz_1, g_0_yyyzzz_0_xxzzzzzz_0, g_0_yyyzzz_0_xxzzzzzz_1, g_0_yyyzzz_0_xyyyyyyz_0, g_0_yyyzzz_0_xyyyyyyz_1, g_0_yyyzzz_0_xyyyyyz_1, g_0_yyyzzz_0_xyyyyyzz_0, g_0_yyyzzz_0_xyyyyyzz_1, g_0_yyyzzz_0_xyyyyzz_1, g_0_yyyzzz_0_xyyyyzzz_0, g_0_yyyzzz_0_xyyyyzzz_1, g_0_yyyzzz_0_xyyyzzz_1, g_0_yyyzzz_0_xyyyzzzz_0, g_0_yyyzzz_0_xyyyzzzz_1, g_0_yyyzzz_0_xyyzzzz_1, g_0_yyyzzz_0_xyyzzzzz_0, g_0_yyyzzz_0_xyyzzzzz_1, g_0_yyyzzz_0_xyzzzzz_1, g_0_yyyzzz_0_xyzzzzzz_0, g_0_yyyzzz_0_xyzzzzzz_1, g_0_yyyzzz_0_xzzzzzz_1, g_0_yyyzzz_0_xzzzzzzz_0, g_0_yyyzzz_0_xzzzzzzz_1, g_0_yyyzzz_0_yyyyyyyz_0, g_0_yyyzzz_0_yyyyyyyz_1, g_0_yyyzzz_0_yyyyyyz_1, g_0_yyyzzz_0_yyyyyyzz_0, g_0_yyyzzz_0_yyyyyyzz_1, g_0_yyyzzz_0_yyyyyzz_1, g_0_yyyzzz_0_yyyyyzzz_0, g_0_yyyzzz_0_yyyyyzzz_1, g_0_yyyzzz_0_yyyyzzz_1, g_0_yyyzzz_0_yyyyzzzz_0, g_0_yyyzzz_0_yyyyzzzz_1, g_0_yyyzzz_0_yyyzzzz_1, g_0_yyyzzz_0_yyyzzzzz_0, g_0_yyyzzz_0_yyyzzzzz_1, g_0_yyyzzz_0_yyzzzzz_1, g_0_yyyzzz_0_yyzzzzzz_0, g_0_yyyzzz_0_yyzzzzzz_1, g_0_yyyzzz_0_yzzzzzz_1, g_0_yyyzzz_0_yzzzzzzz_0, g_0_yyyzzz_0_yzzzzzzz_1, g_0_yyyzzz_0_zzzzzzz_1, g_0_yyyzzz_0_zzzzzzzz_0, g_0_yyyzzz_0_zzzzzzzz_1, g_0_yyzzz_0_xxxxxxxx_0, g_0_yyzzz_0_xxxxxxxx_1, g_0_yyzzz_0_xxxxxxxz_0, g_0_yyzzz_0_xxxxxxxz_1, g_0_yyzzz_0_xxxxxxyz_0, g_0_yyzzz_0_xxxxxxyz_1, g_0_yyzzz_0_xxxxxxzz_0, g_0_yyzzz_0_xxxxxxzz_1, g_0_yyzzz_0_xxxxxyyz_0, g_0_yyzzz_0_xxxxxyyz_1, g_0_yyzzz_0_xxxxxyzz_0, g_0_yyzzz_0_xxxxxyzz_1, g_0_yyzzz_0_xxxxxzzz_0, g_0_yyzzz_0_xxxxxzzz_1, g_0_yyzzz_0_xxxxyyyz_0, g_0_yyzzz_0_xxxxyyyz_1, g_0_yyzzz_0_xxxxyyzz_0, g_0_yyzzz_0_xxxxyyzz_1, g_0_yyzzz_0_xxxxyzzz_0, g_0_yyzzz_0_xxxxyzzz_1, g_0_yyzzz_0_xxxxzzzz_0, g_0_yyzzz_0_xxxxzzzz_1, g_0_yyzzz_0_xxxyyyyz_0, g_0_yyzzz_0_xxxyyyyz_1, g_0_yyzzz_0_xxxyyyzz_0, g_0_yyzzz_0_xxxyyyzz_1, g_0_yyzzz_0_xxxyyzzz_0, g_0_yyzzz_0_xxxyyzzz_1, g_0_yyzzz_0_xxxyzzzz_0, g_0_yyzzz_0_xxxyzzzz_1, g_0_yyzzz_0_xxxzzzzz_0, g_0_yyzzz_0_xxxzzzzz_1, g_0_yyzzz_0_xxyyyyyz_0, g_0_yyzzz_0_xxyyyyyz_1, g_0_yyzzz_0_xxyyyyzz_0, g_0_yyzzz_0_xxyyyyzz_1, g_0_yyzzz_0_xxyyyzzz_0, g_0_yyzzz_0_xxyyyzzz_1, g_0_yyzzz_0_xxyyzzzz_0, g_0_yyzzz_0_xxyyzzzz_1, g_0_yyzzz_0_xxyzzzzz_0, g_0_yyzzz_0_xxyzzzzz_1, g_0_yyzzz_0_xxzzzzzz_0, g_0_yyzzz_0_xxzzzzzz_1, g_0_yyzzz_0_xyyyyyyz_0, g_0_yyzzz_0_xyyyyyyz_1, g_0_yyzzz_0_xyyyyyzz_0, g_0_yyzzz_0_xyyyyyzz_1, g_0_yyzzz_0_xyyyyzzz_0, g_0_yyzzz_0_xyyyyzzz_1, g_0_yyzzz_0_xyyyzzzz_0, g_0_yyzzz_0_xyyyzzzz_1, g_0_yyzzz_0_xyyzzzzz_0, g_0_yyzzz_0_xyyzzzzz_1, g_0_yyzzz_0_xyzzzzzz_0, g_0_yyzzz_0_xyzzzzzz_1, g_0_yyzzz_0_xzzzzzzz_0, g_0_yyzzz_0_xzzzzzzz_1, g_0_yyzzz_0_yyyyyyyz_0, g_0_yyzzz_0_yyyyyyyz_1, g_0_yyzzz_0_yyyyyyzz_0, g_0_yyzzz_0_yyyyyyzz_1, g_0_yyzzz_0_yyyyyzzz_0, g_0_yyzzz_0_yyyyyzzz_1, g_0_yyzzz_0_yyyyzzzz_0, g_0_yyzzz_0_yyyyzzzz_1, g_0_yyzzz_0_yyyzzzzz_0, g_0_yyzzz_0_yyyzzzzz_1, g_0_yyzzz_0_yyzzzzzz_0, g_0_yyzzz_0_yyzzzzzz_1, g_0_yyzzz_0_yzzzzzzz_0, g_0_yyzzz_0_yzzzzzzz_1, g_0_yyzzz_0_zzzzzzzz_0, g_0_yyzzz_0_zzzzzzzz_1, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_yyyyzzz_0_xxxxxxxx_0[i] = 3.0 * g_0_yyzzz_0_xxxxxxxx_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxxx_0[i] * pb_y + g_0_yyyzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxxxy_0[i] = 2.0 * g_0_yyyyz_0_xxxxxxxy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxxy_0[i] * pb_z + g_0_yyyyzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxxxxxxz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxxxz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxxz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_yyyyz_0_xxxxxxyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxxyy_0[i] * pb_z + g_0_yyyyzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxxxxxyz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxxyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxxyz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxxzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxxzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxyyy_0[i] = 2.0 * g_0_yyyyz_0_xxxxxyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxxyyy_0[i] * pb_z + g_0_yyyyzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxxxxyyz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxyyz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxyzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxyzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxxyzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxxzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxxzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxyyyy_0[i] = 2.0 * g_0_yyyyz_0_xxxxyyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxxyyyy_0[i] * pb_z + g_0_yyyyzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxxxyyyz_0[i] = 3.0 * g_0_yyzzz_0_xxxxyyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 3.0 * g_0_yyyzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyyyz_0[i] * pb_y + g_0_yyyzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxyyzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxyyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyyzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxyzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxyzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxyzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxxyzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxxzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxxzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxyyyyy_0[i] = 2.0 * g_0_yyyyz_0_xxxyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxxyyyyy_0[i] * pb_z + g_0_yyyyzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxxyyyyz_0[i] = 3.0 * g_0_yyzzz_0_xxxyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 4.0 * g_0_yyyzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyyyz_0[i] * pb_y + g_0_yyyzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_yyzzz_0_xxxyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyyzz_0[i] * pb_y + g_0_yyyzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxyyzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyyzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxyzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxyzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxxyzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxxzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxxzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxyyyyyy_0[i] = 2.0 * g_0_yyyyz_0_xxyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xxyyyyyy_0[i] * pb_z + g_0_yyyyzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xxyyyyyz_0[i] = 3.0 * g_0_yyzzz_0_xxyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 5.0 * g_0_yyyzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyyyz_0[i] * pb_y + g_0_yyyzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxyyyyzz_0[i] = 3.0 * g_0_yyzzz_0_xxyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyyzz_0[i] * pb_y + g_0_yyyzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxyyyzzz_0[i] = 3.0 * g_0_yyzzz_0_xxyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyyzzz_0[i] * pb_y + g_0_yyyzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxyyzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyyzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxyzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxyzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xxyzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xxzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xxzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyyyyyyy_0[i] = 2.0 * g_0_yyyyz_0_xyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_xyyyyyyy_0[i] * pb_z + g_0_yyyyzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_xyyyyyyz_0[i] = 3.0 * g_0_yyzzz_0_xyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyyyyyyz_1[i] * fti_ab_0 + 6.0 * g_0_yyyzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyyyz_0[i] * pb_y + g_0_yyyzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyyyyyzz_0[i] = 3.0 * g_0_yyzzz_0_xyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyyyyyzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyyzz_0[i] * pb_y + g_0_yyyzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyyyyzzz_0[i] = 3.0 * g_0_yyzzz_0_xyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyyyyzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyyzzz_0[i] * pb_y + g_0_yyyzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyyyzzzz_0[i] = 3.0 * g_0_yyzzz_0_xyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyyyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyyzzzz_0[i] * pb_y + g_0_yyyzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyyzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyyzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xyzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_xyzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_xzzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_xzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_xzzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyyyyyyy_0[i] = 2.0 * g_0_yyyyz_0_yyyyyyyy_0[i] * fi_ab_0 - 2.0 * g_0_yyyyz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_yyyyzz_0_yyyyyyyy_0[i] * pb_z + g_0_yyyyzz_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_yyyyzzz_0_yyyyyyyz_0[i] = 3.0 * g_0_yyzzz_0_yyyyyyyz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyyyyyyz_1[i] * fti_ab_0 + 7.0 * g_0_yyyzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyyyyyyz_0[i] * pb_y + g_0_yyyzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyyyyyzz_0[i] = 3.0 * g_0_yyzzz_0_yyyyyyzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyyyyyzz_1[i] * fti_ab_0 + 6.0 * g_0_yyyzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyyyyyzz_0[i] * pb_y + g_0_yyyzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyyyyzzz_0[i] = 3.0 * g_0_yyzzz_0_yyyyyzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyyyyzzz_1[i] * fti_ab_0 + 5.0 * g_0_yyyzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyyyyzzz_0[i] * pb_y + g_0_yyyzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyyyzzzz_0[i] = 3.0 * g_0_yyzzz_0_yyyyzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyyzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyyyzzzz_0[i] * pb_y + g_0_yyyzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyyzzzzz_0[i] = 3.0 * g_0_yyzzz_0_yyyzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyyzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyyzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyyzzzzz_0[i] * pb_y + g_0_yyyzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yyzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_yyzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yyzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyyzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yyzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_yzzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_yzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyyzzz_0_yzzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yyyyzzz_0_zzzzzzzz_0[i] = 3.0 * g_0_yyzzz_0_zzzzzzzz_0[i] * fi_ab_0 - 3.0 * g_0_yyzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_yyyzzz_0_zzzzzzzz_0[i] * pb_y + g_0_yyyzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1440-1485 components of targeted buffer : SKSL

    auto g_0_yyyzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1440);

    auto g_0_yyyzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1441);

    auto g_0_yyyzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1442);

    auto g_0_yyyzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1443);

    auto g_0_yyyzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1444);

    auto g_0_yyyzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1445);

    auto g_0_yyyzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1446);

    auto g_0_yyyzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1447);

    auto g_0_yyyzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1448);

    auto g_0_yyyzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1449);

    auto g_0_yyyzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1450);

    auto g_0_yyyzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1451);

    auto g_0_yyyzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1452);

    auto g_0_yyyzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1453);

    auto g_0_yyyzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1454);

    auto g_0_yyyzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1455);

    auto g_0_yyyzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1456);

    auto g_0_yyyzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1457);

    auto g_0_yyyzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1458);

    auto g_0_yyyzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1459);

    auto g_0_yyyzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1460);

    auto g_0_yyyzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1461);

    auto g_0_yyyzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1462);

    auto g_0_yyyzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1463);

    auto g_0_yyyzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1464);

    auto g_0_yyyzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1465);

    auto g_0_yyyzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1466);

    auto g_0_yyyzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1467);

    auto g_0_yyyzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1468);

    auto g_0_yyyzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1469);

    auto g_0_yyyzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1470);

    auto g_0_yyyzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1471);

    auto g_0_yyyzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1472);

    auto g_0_yyyzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1473);

    auto g_0_yyyzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1474);

    auto g_0_yyyzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1475);

    auto g_0_yyyzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1476);

    auto g_0_yyyzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1477);

    auto g_0_yyyzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1478);

    auto g_0_yyyzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1479);

    auto g_0_yyyzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1480);

    auto g_0_yyyzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1481);

    auto g_0_yyyzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1482);

    auto g_0_yyyzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1483);

    auto g_0_yyyzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1484);

    #pragma omp simd aligned(g_0_yyyzz_0_xxxxxxxy_0, g_0_yyyzz_0_xxxxxxxy_1, g_0_yyyzz_0_xxxxxxyy_0, g_0_yyyzz_0_xxxxxxyy_1, g_0_yyyzz_0_xxxxxyyy_0, g_0_yyyzz_0_xxxxxyyy_1, g_0_yyyzz_0_xxxxyyyy_0, g_0_yyyzz_0_xxxxyyyy_1, g_0_yyyzz_0_xxxyyyyy_0, g_0_yyyzz_0_xxxyyyyy_1, g_0_yyyzz_0_xxyyyyyy_0, g_0_yyyzz_0_xxyyyyyy_1, g_0_yyyzz_0_xyyyyyyy_0, g_0_yyyzz_0_xyyyyyyy_1, g_0_yyyzz_0_yyyyyyyy_0, g_0_yyyzz_0_yyyyyyyy_1, g_0_yyyzzz_0_xxxxxxxy_0, g_0_yyyzzz_0_xxxxxxxy_1, g_0_yyyzzz_0_xxxxxxyy_0, g_0_yyyzzz_0_xxxxxxyy_1, g_0_yyyzzz_0_xxxxxyyy_0, g_0_yyyzzz_0_xxxxxyyy_1, g_0_yyyzzz_0_xxxxyyyy_0, g_0_yyyzzz_0_xxxxyyyy_1, g_0_yyyzzz_0_xxxyyyyy_0, g_0_yyyzzz_0_xxxyyyyy_1, g_0_yyyzzz_0_xxyyyyyy_0, g_0_yyyzzz_0_xxyyyyyy_1, g_0_yyyzzz_0_xyyyyyyy_0, g_0_yyyzzz_0_xyyyyyyy_1, g_0_yyyzzz_0_yyyyyyyy_0, g_0_yyyzzz_0_yyyyyyyy_1, g_0_yyyzzzz_0_xxxxxxxx_0, g_0_yyyzzzz_0_xxxxxxxy_0, g_0_yyyzzzz_0_xxxxxxxz_0, g_0_yyyzzzz_0_xxxxxxyy_0, g_0_yyyzzzz_0_xxxxxxyz_0, g_0_yyyzzzz_0_xxxxxxzz_0, g_0_yyyzzzz_0_xxxxxyyy_0, g_0_yyyzzzz_0_xxxxxyyz_0, g_0_yyyzzzz_0_xxxxxyzz_0, g_0_yyyzzzz_0_xxxxxzzz_0, g_0_yyyzzzz_0_xxxxyyyy_0, g_0_yyyzzzz_0_xxxxyyyz_0, g_0_yyyzzzz_0_xxxxyyzz_0, g_0_yyyzzzz_0_xxxxyzzz_0, g_0_yyyzzzz_0_xxxxzzzz_0, g_0_yyyzzzz_0_xxxyyyyy_0, g_0_yyyzzzz_0_xxxyyyyz_0, g_0_yyyzzzz_0_xxxyyyzz_0, g_0_yyyzzzz_0_xxxyyzzz_0, g_0_yyyzzzz_0_xxxyzzzz_0, g_0_yyyzzzz_0_xxxzzzzz_0, g_0_yyyzzzz_0_xxyyyyyy_0, g_0_yyyzzzz_0_xxyyyyyz_0, g_0_yyyzzzz_0_xxyyyyzz_0, g_0_yyyzzzz_0_xxyyyzzz_0, g_0_yyyzzzz_0_xxyyzzzz_0, g_0_yyyzzzz_0_xxyzzzzz_0, g_0_yyyzzzz_0_xxzzzzzz_0, g_0_yyyzzzz_0_xyyyyyyy_0, g_0_yyyzzzz_0_xyyyyyyz_0, g_0_yyyzzzz_0_xyyyyyzz_0, g_0_yyyzzzz_0_xyyyyzzz_0, g_0_yyyzzzz_0_xyyyzzzz_0, g_0_yyyzzzz_0_xyyzzzzz_0, g_0_yyyzzzz_0_xyzzzzzz_0, g_0_yyyzzzz_0_xzzzzzzz_0, g_0_yyyzzzz_0_yyyyyyyy_0, g_0_yyyzzzz_0_yyyyyyyz_0, g_0_yyyzzzz_0_yyyyyyzz_0, g_0_yyyzzzz_0_yyyyyzzz_0, g_0_yyyzzzz_0_yyyyzzzz_0, g_0_yyyzzzz_0_yyyzzzzz_0, g_0_yyyzzzz_0_yyzzzzzz_0, g_0_yyyzzzz_0_yzzzzzzz_0, g_0_yyyzzzz_0_zzzzzzzz_0, g_0_yyzzzz_0_xxxxxxxx_0, g_0_yyzzzz_0_xxxxxxxx_1, g_0_yyzzzz_0_xxxxxxxz_0, g_0_yyzzzz_0_xxxxxxxz_1, g_0_yyzzzz_0_xxxxxxyz_0, g_0_yyzzzz_0_xxxxxxyz_1, g_0_yyzzzz_0_xxxxxxz_1, g_0_yyzzzz_0_xxxxxxzz_0, g_0_yyzzzz_0_xxxxxxzz_1, g_0_yyzzzz_0_xxxxxyyz_0, g_0_yyzzzz_0_xxxxxyyz_1, g_0_yyzzzz_0_xxxxxyz_1, g_0_yyzzzz_0_xxxxxyzz_0, g_0_yyzzzz_0_xxxxxyzz_1, g_0_yyzzzz_0_xxxxxzz_1, g_0_yyzzzz_0_xxxxxzzz_0, g_0_yyzzzz_0_xxxxxzzz_1, g_0_yyzzzz_0_xxxxyyyz_0, g_0_yyzzzz_0_xxxxyyyz_1, g_0_yyzzzz_0_xxxxyyz_1, g_0_yyzzzz_0_xxxxyyzz_0, g_0_yyzzzz_0_xxxxyyzz_1, g_0_yyzzzz_0_xxxxyzz_1, g_0_yyzzzz_0_xxxxyzzz_0, g_0_yyzzzz_0_xxxxyzzz_1, g_0_yyzzzz_0_xxxxzzz_1, g_0_yyzzzz_0_xxxxzzzz_0, g_0_yyzzzz_0_xxxxzzzz_1, g_0_yyzzzz_0_xxxyyyyz_0, g_0_yyzzzz_0_xxxyyyyz_1, g_0_yyzzzz_0_xxxyyyz_1, g_0_yyzzzz_0_xxxyyyzz_0, g_0_yyzzzz_0_xxxyyyzz_1, g_0_yyzzzz_0_xxxyyzz_1, g_0_yyzzzz_0_xxxyyzzz_0, g_0_yyzzzz_0_xxxyyzzz_1, g_0_yyzzzz_0_xxxyzzz_1, g_0_yyzzzz_0_xxxyzzzz_0, g_0_yyzzzz_0_xxxyzzzz_1, g_0_yyzzzz_0_xxxzzzz_1, g_0_yyzzzz_0_xxxzzzzz_0, g_0_yyzzzz_0_xxxzzzzz_1, g_0_yyzzzz_0_xxyyyyyz_0, g_0_yyzzzz_0_xxyyyyyz_1, g_0_yyzzzz_0_xxyyyyz_1, g_0_yyzzzz_0_xxyyyyzz_0, g_0_yyzzzz_0_xxyyyyzz_1, g_0_yyzzzz_0_xxyyyzz_1, g_0_yyzzzz_0_xxyyyzzz_0, g_0_yyzzzz_0_xxyyyzzz_1, g_0_yyzzzz_0_xxyyzzz_1, g_0_yyzzzz_0_xxyyzzzz_0, g_0_yyzzzz_0_xxyyzzzz_1, g_0_yyzzzz_0_xxyzzzz_1, g_0_yyzzzz_0_xxyzzzzz_0, g_0_yyzzzz_0_xxyzzzzz_1, g_0_yyzzzz_0_xxzzzzz_1, g_0_yyzzzz_0_xxzzzzzz_0, g_0_yyzzzz_0_xxzzzzzz_1, g_0_yyzzzz_0_xyyyyyyz_0, g_0_yyzzzz_0_xyyyyyyz_1, g_0_yyzzzz_0_xyyyyyz_1, g_0_yyzzzz_0_xyyyyyzz_0, g_0_yyzzzz_0_xyyyyyzz_1, g_0_yyzzzz_0_xyyyyzz_1, g_0_yyzzzz_0_xyyyyzzz_0, g_0_yyzzzz_0_xyyyyzzz_1, g_0_yyzzzz_0_xyyyzzz_1, g_0_yyzzzz_0_xyyyzzzz_0, g_0_yyzzzz_0_xyyyzzzz_1, g_0_yyzzzz_0_xyyzzzz_1, g_0_yyzzzz_0_xyyzzzzz_0, g_0_yyzzzz_0_xyyzzzzz_1, g_0_yyzzzz_0_xyzzzzz_1, g_0_yyzzzz_0_xyzzzzzz_0, g_0_yyzzzz_0_xyzzzzzz_1, g_0_yyzzzz_0_xzzzzzz_1, g_0_yyzzzz_0_xzzzzzzz_0, g_0_yyzzzz_0_xzzzzzzz_1, g_0_yyzzzz_0_yyyyyyyz_0, g_0_yyzzzz_0_yyyyyyyz_1, g_0_yyzzzz_0_yyyyyyz_1, g_0_yyzzzz_0_yyyyyyzz_0, g_0_yyzzzz_0_yyyyyyzz_1, g_0_yyzzzz_0_yyyyyzz_1, g_0_yyzzzz_0_yyyyyzzz_0, g_0_yyzzzz_0_yyyyyzzz_1, g_0_yyzzzz_0_yyyyzzz_1, g_0_yyzzzz_0_yyyyzzzz_0, g_0_yyzzzz_0_yyyyzzzz_1, g_0_yyzzzz_0_yyyzzzz_1, g_0_yyzzzz_0_yyyzzzzz_0, g_0_yyzzzz_0_yyyzzzzz_1, g_0_yyzzzz_0_yyzzzzz_1, g_0_yyzzzz_0_yyzzzzzz_0, g_0_yyzzzz_0_yyzzzzzz_1, g_0_yyzzzz_0_yzzzzzz_1, g_0_yyzzzz_0_yzzzzzzz_0, g_0_yyzzzz_0_yzzzzzzz_1, g_0_yyzzzz_0_zzzzzzz_1, g_0_yyzzzz_0_zzzzzzzz_0, g_0_yyzzzz_0_zzzzzzzz_1, g_0_yzzzz_0_xxxxxxxx_0, g_0_yzzzz_0_xxxxxxxx_1, g_0_yzzzz_0_xxxxxxxz_0, g_0_yzzzz_0_xxxxxxxz_1, g_0_yzzzz_0_xxxxxxyz_0, g_0_yzzzz_0_xxxxxxyz_1, g_0_yzzzz_0_xxxxxxzz_0, g_0_yzzzz_0_xxxxxxzz_1, g_0_yzzzz_0_xxxxxyyz_0, g_0_yzzzz_0_xxxxxyyz_1, g_0_yzzzz_0_xxxxxyzz_0, g_0_yzzzz_0_xxxxxyzz_1, g_0_yzzzz_0_xxxxxzzz_0, g_0_yzzzz_0_xxxxxzzz_1, g_0_yzzzz_0_xxxxyyyz_0, g_0_yzzzz_0_xxxxyyyz_1, g_0_yzzzz_0_xxxxyyzz_0, g_0_yzzzz_0_xxxxyyzz_1, g_0_yzzzz_0_xxxxyzzz_0, g_0_yzzzz_0_xxxxyzzz_1, g_0_yzzzz_0_xxxxzzzz_0, g_0_yzzzz_0_xxxxzzzz_1, g_0_yzzzz_0_xxxyyyyz_0, g_0_yzzzz_0_xxxyyyyz_1, g_0_yzzzz_0_xxxyyyzz_0, g_0_yzzzz_0_xxxyyyzz_1, g_0_yzzzz_0_xxxyyzzz_0, g_0_yzzzz_0_xxxyyzzz_1, g_0_yzzzz_0_xxxyzzzz_0, g_0_yzzzz_0_xxxyzzzz_1, g_0_yzzzz_0_xxxzzzzz_0, g_0_yzzzz_0_xxxzzzzz_1, g_0_yzzzz_0_xxyyyyyz_0, g_0_yzzzz_0_xxyyyyyz_1, g_0_yzzzz_0_xxyyyyzz_0, g_0_yzzzz_0_xxyyyyzz_1, g_0_yzzzz_0_xxyyyzzz_0, g_0_yzzzz_0_xxyyyzzz_1, g_0_yzzzz_0_xxyyzzzz_0, g_0_yzzzz_0_xxyyzzzz_1, g_0_yzzzz_0_xxyzzzzz_0, g_0_yzzzz_0_xxyzzzzz_1, g_0_yzzzz_0_xxzzzzzz_0, g_0_yzzzz_0_xxzzzzzz_1, g_0_yzzzz_0_xyyyyyyz_0, g_0_yzzzz_0_xyyyyyyz_1, g_0_yzzzz_0_xyyyyyzz_0, g_0_yzzzz_0_xyyyyyzz_1, g_0_yzzzz_0_xyyyyzzz_0, g_0_yzzzz_0_xyyyyzzz_1, g_0_yzzzz_0_xyyyzzzz_0, g_0_yzzzz_0_xyyyzzzz_1, g_0_yzzzz_0_xyyzzzzz_0, g_0_yzzzz_0_xyyzzzzz_1, g_0_yzzzz_0_xyzzzzzz_0, g_0_yzzzz_0_xyzzzzzz_1, g_0_yzzzz_0_xzzzzzzz_0, g_0_yzzzz_0_xzzzzzzz_1, g_0_yzzzz_0_yyyyyyyz_0, g_0_yzzzz_0_yyyyyyyz_1, g_0_yzzzz_0_yyyyyyzz_0, g_0_yzzzz_0_yyyyyyzz_1, g_0_yzzzz_0_yyyyyzzz_0, g_0_yzzzz_0_yyyyyzzz_1, g_0_yzzzz_0_yyyyzzzz_0, g_0_yzzzz_0_yyyyzzzz_1, g_0_yzzzz_0_yyyzzzzz_0, g_0_yzzzz_0_yyyzzzzz_1, g_0_yzzzz_0_yyzzzzzz_0, g_0_yzzzz_0_yyzzzzzz_1, g_0_yzzzz_0_yzzzzzzz_0, g_0_yzzzz_0_yzzzzzzz_1, g_0_yzzzz_0_zzzzzzzz_0, g_0_yzzzz_0_zzzzzzzz_1, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_yyyzzzz_0_xxxxxxxx_0[i] = 2.0 * g_0_yzzzz_0_xxxxxxxx_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxxx_0[i] * pb_y + g_0_yyzzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxxxy_0[i] = 3.0 * g_0_yyyzz_0_xxxxxxxy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxxy_0[i] * pb_z + g_0_yyyzzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxxxxxxz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxxxz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxxz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxxyy_0[i] = 3.0 * g_0_yyyzz_0_xxxxxxyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxxyy_0[i] * pb_z + g_0_yyyzzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxxxxxyz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxxyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxxyz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxxzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxxzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxyyy_0[i] = 3.0 * g_0_yyyzz_0_xxxxxyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxxyyy_0[i] * pb_z + g_0_yyyzzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxxxxyyz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxyyz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxyzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxyzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxxyzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxxzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxxzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxyyyy_0[i] = 3.0 * g_0_yyyzz_0_xxxxyyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxxyyyy_0[i] * pb_z + g_0_yyyzzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxxxyyyz_0[i] = 2.0 * g_0_yzzzz_0_xxxxyyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 3.0 * g_0_yyzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyyyz_0[i] * pb_y + g_0_yyzzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxyyzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxyyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyyzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxyzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxyzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxyzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxxyzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxxzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxxzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxyyyyy_0[i] = 3.0 * g_0_yyyzz_0_xxxyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxxyyyyy_0[i] * pb_z + g_0_yyyzzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxxyyyyz_0[i] = 2.0 * g_0_yzzzz_0_xxxyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 4.0 * g_0_yyzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyyyz_0[i] * pb_y + g_0_yyzzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxyyyzz_0[i] = 2.0 * g_0_yzzzz_0_xxxyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_yyzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyyzz_0[i] * pb_y + g_0_yyzzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxyyzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyyzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxyzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxyzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxxyzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxxzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxxzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxyyyyyy_0[i] = 3.0 * g_0_yyyzz_0_xxyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xxyyyyyy_0[i] * pb_z + g_0_yyyzzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xxyyyyyz_0[i] = 2.0 * g_0_yzzzz_0_xxyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 5.0 * g_0_yyzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyyyz_0[i] * pb_y + g_0_yyzzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxyyyyzz_0[i] = 2.0 * g_0_yzzzz_0_xxyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 4.0 * g_0_yyzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyyzz_0[i] * pb_y + g_0_yyzzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxyyyzzz_0[i] = 2.0 * g_0_yzzzz_0_xxyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyyzzz_0[i] * pb_y + g_0_yyzzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyyzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxyzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxyzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xxyzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xxzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xxzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyyyyyyy_0[i] = 3.0 * g_0_yyyzz_0_xyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_xyyyyyyy_0[i] * pb_z + g_0_yyyzzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_xyyyyyyz_0[i] = 2.0 * g_0_yzzzz_0_xyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyyyyyyz_1[i] * fti_ab_0 + 6.0 * g_0_yyzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyyyz_0[i] * pb_y + g_0_yyzzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyyyyyzz_0[i] = 2.0 * g_0_yzzzz_0_xyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyyyyyzz_1[i] * fti_ab_0 + 5.0 * g_0_yyzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyyzz_0[i] * pb_y + g_0_yyzzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyyyyzzz_0[i] = 2.0 * g_0_yzzzz_0_xyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyyyyzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyyzzz_0[i] * pb_y + g_0_yyzzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyyyzzzz_0[i] = 2.0 * g_0_yzzzz_0_xyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyyyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyyzzzz_0[i] * pb_y + g_0_yyzzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyyzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyyzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xyzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_xyzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_xzzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_xzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_xzzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyyyyyyy_0[i] = 3.0 * g_0_yyyzz_0_yyyyyyyy_0[i] * fi_ab_0 - 3.0 * g_0_yyyzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_yyyzzz_0_yyyyyyyy_0[i] * pb_z + g_0_yyyzzz_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_yyyzzzz_0_yyyyyyyz_0[i] = 2.0 * g_0_yzzzz_0_yyyyyyyz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyyyyyyz_1[i] * fti_ab_0 + 7.0 * g_0_yyzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyyyyyyz_0[i] * pb_y + g_0_yyzzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyyyyyzz_0[i] = 2.0 * g_0_yzzzz_0_yyyyyyzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyyyyyzz_1[i] * fti_ab_0 + 6.0 * g_0_yyzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyyyyyzz_0[i] * pb_y + g_0_yyzzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyyyyzzz_0[i] = 2.0 * g_0_yzzzz_0_yyyyyzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyyyyzzz_1[i] * fti_ab_0 + 5.0 * g_0_yyzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyyyyzzz_0[i] * pb_y + g_0_yyzzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyyyzzzz_0[i] = 2.0 * g_0_yzzzz_0_yyyyzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_yyzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyyyzzzz_0[i] * pb_y + g_0_yyzzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyyzzzzz_0[i] = 2.0 * g_0_yzzzz_0_yyyzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyyzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yyzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyyzzzzz_0[i] * pb_y + g_0_yyzzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yyzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_yyzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yyzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yyzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yyzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_yzzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_yzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yyzzzz_0_yzzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yyyzzzz_0_zzzzzzzz_0[i] = 2.0 * g_0_yzzzz_0_zzzzzzzz_0[i] * fi_ab_0 - 2.0 * g_0_yzzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_yyzzzz_0_zzzzzzzz_0[i] * pb_y + g_0_yyzzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1485-1530 components of targeted buffer : SKSL

    auto g_0_yyzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1485);

    auto g_0_yyzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1486);

    auto g_0_yyzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1487);

    auto g_0_yyzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1488);

    auto g_0_yyzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1489);

    auto g_0_yyzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1490);

    auto g_0_yyzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1491);

    auto g_0_yyzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1492);

    auto g_0_yyzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1493);

    auto g_0_yyzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1494);

    auto g_0_yyzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1495);

    auto g_0_yyzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1496);

    auto g_0_yyzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1497);

    auto g_0_yyzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1498);

    auto g_0_yyzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1499);

    auto g_0_yyzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1500);

    auto g_0_yyzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1501);

    auto g_0_yyzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1502);

    auto g_0_yyzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1503);

    auto g_0_yyzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1504);

    auto g_0_yyzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1505);

    auto g_0_yyzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1506);

    auto g_0_yyzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1507);

    auto g_0_yyzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1508);

    auto g_0_yyzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1509);

    auto g_0_yyzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1510);

    auto g_0_yyzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1511);

    auto g_0_yyzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1512);

    auto g_0_yyzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1513);

    auto g_0_yyzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1514);

    auto g_0_yyzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1515);

    auto g_0_yyzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1516);

    auto g_0_yyzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1517);

    auto g_0_yyzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1518);

    auto g_0_yyzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1519);

    auto g_0_yyzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1520);

    auto g_0_yyzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1521);

    auto g_0_yyzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1522);

    auto g_0_yyzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1523);

    auto g_0_yyzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1524);

    auto g_0_yyzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1525);

    auto g_0_yyzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1526);

    auto g_0_yyzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1527);

    auto g_0_yyzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1528);

    auto g_0_yyzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1529);

    #pragma omp simd aligned(g_0_yyzzz_0_xxxxxxxy_0, g_0_yyzzz_0_xxxxxxxy_1, g_0_yyzzz_0_xxxxxxyy_0, g_0_yyzzz_0_xxxxxxyy_1, g_0_yyzzz_0_xxxxxyyy_0, g_0_yyzzz_0_xxxxxyyy_1, g_0_yyzzz_0_xxxxyyyy_0, g_0_yyzzz_0_xxxxyyyy_1, g_0_yyzzz_0_xxxyyyyy_0, g_0_yyzzz_0_xxxyyyyy_1, g_0_yyzzz_0_xxyyyyyy_0, g_0_yyzzz_0_xxyyyyyy_1, g_0_yyzzz_0_xyyyyyyy_0, g_0_yyzzz_0_xyyyyyyy_1, g_0_yyzzz_0_yyyyyyyy_0, g_0_yyzzz_0_yyyyyyyy_1, g_0_yyzzzz_0_xxxxxxxy_0, g_0_yyzzzz_0_xxxxxxxy_1, g_0_yyzzzz_0_xxxxxxyy_0, g_0_yyzzzz_0_xxxxxxyy_1, g_0_yyzzzz_0_xxxxxyyy_0, g_0_yyzzzz_0_xxxxxyyy_1, g_0_yyzzzz_0_xxxxyyyy_0, g_0_yyzzzz_0_xxxxyyyy_1, g_0_yyzzzz_0_xxxyyyyy_0, g_0_yyzzzz_0_xxxyyyyy_1, g_0_yyzzzz_0_xxyyyyyy_0, g_0_yyzzzz_0_xxyyyyyy_1, g_0_yyzzzz_0_xyyyyyyy_0, g_0_yyzzzz_0_xyyyyyyy_1, g_0_yyzzzz_0_yyyyyyyy_0, g_0_yyzzzz_0_yyyyyyyy_1, g_0_yyzzzzz_0_xxxxxxxx_0, g_0_yyzzzzz_0_xxxxxxxy_0, g_0_yyzzzzz_0_xxxxxxxz_0, g_0_yyzzzzz_0_xxxxxxyy_0, g_0_yyzzzzz_0_xxxxxxyz_0, g_0_yyzzzzz_0_xxxxxxzz_0, g_0_yyzzzzz_0_xxxxxyyy_0, g_0_yyzzzzz_0_xxxxxyyz_0, g_0_yyzzzzz_0_xxxxxyzz_0, g_0_yyzzzzz_0_xxxxxzzz_0, g_0_yyzzzzz_0_xxxxyyyy_0, g_0_yyzzzzz_0_xxxxyyyz_0, g_0_yyzzzzz_0_xxxxyyzz_0, g_0_yyzzzzz_0_xxxxyzzz_0, g_0_yyzzzzz_0_xxxxzzzz_0, g_0_yyzzzzz_0_xxxyyyyy_0, g_0_yyzzzzz_0_xxxyyyyz_0, g_0_yyzzzzz_0_xxxyyyzz_0, g_0_yyzzzzz_0_xxxyyzzz_0, g_0_yyzzzzz_0_xxxyzzzz_0, g_0_yyzzzzz_0_xxxzzzzz_0, g_0_yyzzzzz_0_xxyyyyyy_0, g_0_yyzzzzz_0_xxyyyyyz_0, g_0_yyzzzzz_0_xxyyyyzz_0, g_0_yyzzzzz_0_xxyyyzzz_0, g_0_yyzzzzz_0_xxyyzzzz_0, g_0_yyzzzzz_0_xxyzzzzz_0, g_0_yyzzzzz_0_xxzzzzzz_0, g_0_yyzzzzz_0_xyyyyyyy_0, g_0_yyzzzzz_0_xyyyyyyz_0, g_0_yyzzzzz_0_xyyyyyzz_0, g_0_yyzzzzz_0_xyyyyzzz_0, g_0_yyzzzzz_0_xyyyzzzz_0, g_0_yyzzzzz_0_xyyzzzzz_0, g_0_yyzzzzz_0_xyzzzzzz_0, g_0_yyzzzzz_0_xzzzzzzz_0, g_0_yyzzzzz_0_yyyyyyyy_0, g_0_yyzzzzz_0_yyyyyyyz_0, g_0_yyzzzzz_0_yyyyyyzz_0, g_0_yyzzzzz_0_yyyyyzzz_0, g_0_yyzzzzz_0_yyyyzzzz_0, g_0_yyzzzzz_0_yyyzzzzz_0, g_0_yyzzzzz_0_yyzzzzzz_0, g_0_yyzzzzz_0_yzzzzzzz_0, g_0_yyzzzzz_0_zzzzzzzz_0, g_0_yzzzzz_0_xxxxxxxx_0, g_0_yzzzzz_0_xxxxxxxx_1, g_0_yzzzzz_0_xxxxxxxz_0, g_0_yzzzzz_0_xxxxxxxz_1, g_0_yzzzzz_0_xxxxxxyz_0, g_0_yzzzzz_0_xxxxxxyz_1, g_0_yzzzzz_0_xxxxxxz_1, g_0_yzzzzz_0_xxxxxxzz_0, g_0_yzzzzz_0_xxxxxxzz_1, g_0_yzzzzz_0_xxxxxyyz_0, g_0_yzzzzz_0_xxxxxyyz_1, g_0_yzzzzz_0_xxxxxyz_1, g_0_yzzzzz_0_xxxxxyzz_0, g_0_yzzzzz_0_xxxxxyzz_1, g_0_yzzzzz_0_xxxxxzz_1, g_0_yzzzzz_0_xxxxxzzz_0, g_0_yzzzzz_0_xxxxxzzz_1, g_0_yzzzzz_0_xxxxyyyz_0, g_0_yzzzzz_0_xxxxyyyz_1, g_0_yzzzzz_0_xxxxyyz_1, g_0_yzzzzz_0_xxxxyyzz_0, g_0_yzzzzz_0_xxxxyyzz_1, g_0_yzzzzz_0_xxxxyzz_1, g_0_yzzzzz_0_xxxxyzzz_0, g_0_yzzzzz_0_xxxxyzzz_1, g_0_yzzzzz_0_xxxxzzz_1, g_0_yzzzzz_0_xxxxzzzz_0, g_0_yzzzzz_0_xxxxzzzz_1, g_0_yzzzzz_0_xxxyyyyz_0, g_0_yzzzzz_0_xxxyyyyz_1, g_0_yzzzzz_0_xxxyyyz_1, g_0_yzzzzz_0_xxxyyyzz_0, g_0_yzzzzz_0_xxxyyyzz_1, g_0_yzzzzz_0_xxxyyzz_1, g_0_yzzzzz_0_xxxyyzzz_0, g_0_yzzzzz_0_xxxyyzzz_1, g_0_yzzzzz_0_xxxyzzz_1, g_0_yzzzzz_0_xxxyzzzz_0, g_0_yzzzzz_0_xxxyzzzz_1, g_0_yzzzzz_0_xxxzzzz_1, g_0_yzzzzz_0_xxxzzzzz_0, g_0_yzzzzz_0_xxxzzzzz_1, g_0_yzzzzz_0_xxyyyyyz_0, g_0_yzzzzz_0_xxyyyyyz_1, g_0_yzzzzz_0_xxyyyyz_1, g_0_yzzzzz_0_xxyyyyzz_0, g_0_yzzzzz_0_xxyyyyzz_1, g_0_yzzzzz_0_xxyyyzz_1, g_0_yzzzzz_0_xxyyyzzz_0, g_0_yzzzzz_0_xxyyyzzz_1, g_0_yzzzzz_0_xxyyzzz_1, g_0_yzzzzz_0_xxyyzzzz_0, g_0_yzzzzz_0_xxyyzzzz_1, g_0_yzzzzz_0_xxyzzzz_1, g_0_yzzzzz_0_xxyzzzzz_0, g_0_yzzzzz_0_xxyzzzzz_1, g_0_yzzzzz_0_xxzzzzz_1, g_0_yzzzzz_0_xxzzzzzz_0, g_0_yzzzzz_0_xxzzzzzz_1, g_0_yzzzzz_0_xyyyyyyz_0, g_0_yzzzzz_0_xyyyyyyz_1, g_0_yzzzzz_0_xyyyyyz_1, g_0_yzzzzz_0_xyyyyyzz_0, g_0_yzzzzz_0_xyyyyyzz_1, g_0_yzzzzz_0_xyyyyzz_1, g_0_yzzzzz_0_xyyyyzzz_0, g_0_yzzzzz_0_xyyyyzzz_1, g_0_yzzzzz_0_xyyyzzz_1, g_0_yzzzzz_0_xyyyzzzz_0, g_0_yzzzzz_0_xyyyzzzz_1, g_0_yzzzzz_0_xyyzzzz_1, g_0_yzzzzz_0_xyyzzzzz_0, g_0_yzzzzz_0_xyyzzzzz_1, g_0_yzzzzz_0_xyzzzzz_1, g_0_yzzzzz_0_xyzzzzzz_0, g_0_yzzzzz_0_xyzzzzzz_1, g_0_yzzzzz_0_xzzzzzz_1, g_0_yzzzzz_0_xzzzzzzz_0, g_0_yzzzzz_0_xzzzzzzz_1, g_0_yzzzzz_0_yyyyyyyz_0, g_0_yzzzzz_0_yyyyyyyz_1, g_0_yzzzzz_0_yyyyyyz_1, g_0_yzzzzz_0_yyyyyyzz_0, g_0_yzzzzz_0_yyyyyyzz_1, g_0_yzzzzz_0_yyyyyzz_1, g_0_yzzzzz_0_yyyyyzzz_0, g_0_yzzzzz_0_yyyyyzzz_1, g_0_yzzzzz_0_yyyyzzz_1, g_0_yzzzzz_0_yyyyzzzz_0, g_0_yzzzzz_0_yyyyzzzz_1, g_0_yzzzzz_0_yyyzzzz_1, g_0_yzzzzz_0_yyyzzzzz_0, g_0_yzzzzz_0_yyyzzzzz_1, g_0_yzzzzz_0_yyzzzzz_1, g_0_yzzzzz_0_yyzzzzzz_0, g_0_yzzzzz_0_yyzzzzzz_1, g_0_yzzzzz_0_yzzzzzz_1, g_0_yzzzzz_0_yzzzzzzz_0, g_0_yzzzzz_0_yzzzzzzz_1, g_0_yzzzzz_0_zzzzzzz_1, g_0_yzzzzz_0_zzzzzzzz_0, g_0_yzzzzz_0_zzzzzzzz_1, g_0_zzzzz_0_xxxxxxxx_0, g_0_zzzzz_0_xxxxxxxx_1, g_0_zzzzz_0_xxxxxxxz_0, g_0_zzzzz_0_xxxxxxxz_1, g_0_zzzzz_0_xxxxxxyz_0, g_0_zzzzz_0_xxxxxxyz_1, g_0_zzzzz_0_xxxxxxzz_0, g_0_zzzzz_0_xxxxxxzz_1, g_0_zzzzz_0_xxxxxyyz_0, g_0_zzzzz_0_xxxxxyyz_1, g_0_zzzzz_0_xxxxxyzz_0, g_0_zzzzz_0_xxxxxyzz_1, g_0_zzzzz_0_xxxxxzzz_0, g_0_zzzzz_0_xxxxxzzz_1, g_0_zzzzz_0_xxxxyyyz_0, g_0_zzzzz_0_xxxxyyyz_1, g_0_zzzzz_0_xxxxyyzz_0, g_0_zzzzz_0_xxxxyyzz_1, g_0_zzzzz_0_xxxxyzzz_0, g_0_zzzzz_0_xxxxyzzz_1, g_0_zzzzz_0_xxxxzzzz_0, g_0_zzzzz_0_xxxxzzzz_1, g_0_zzzzz_0_xxxyyyyz_0, g_0_zzzzz_0_xxxyyyyz_1, g_0_zzzzz_0_xxxyyyzz_0, g_0_zzzzz_0_xxxyyyzz_1, g_0_zzzzz_0_xxxyyzzz_0, g_0_zzzzz_0_xxxyyzzz_1, g_0_zzzzz_0_xxxyzzzz_0, g_0_zzzzz_0_xxxyzzzz_1, g_0_zzzzz_0_xxxzzzzz_0, g_0_zzzzz_0_xxxzzzzz_1, g_0_zzzzz_0_xxyyyyyz_0, g_0_zzzzz_0_xxyyyyyz_1, g_0_zzzzz_0_xxyyyyzz_0, g_0_zzzzz_0_xxyyyyzz_1, g_0_zzzzz_0_xxyyyzzz_0, g_0_zzzzz_0_xxyyyzzz_1, g_0_zzzzz_0_xxyyzzzz_0, g_0_zzzzz_0_xxyyzzzz_1, g_0_zzzzz_0_xxyzzzzz_0, g_0_zzzzz_0_xxyzzzzz_1, g_0_zzzzz_0_xxzzzzzz_0, g_0_zzzzz_0_xxzzzzzz_1, g_0_zzzzz_0_xyyyyyyz_0, g_0_zzzzz_0_xyyyyyyz_1, g_0_zzzzz_0_xyyyyyzz_0, g_0_zzzzz_0_xyyyyyzz_1, g_0_zzzzz_0_xyyyyzzz_0, g_0_zzzzz_0_xyyyyzzz_1, g_0_zzzzz_0_xyyyzzzz_0, g_0_zzzzz_0_xyyyzzzz_1, g_0_zzzzz_0_xyyzzzzz_0, g_0_zzzzz_0_xyyzzzzz_1, g_0_zzzzz_0_xyzzzzzz_0, g_0_zzzzz_0_xyzzzzzz_1, g_0_zzzzz_0_xzzzzzzz_0, g_0_zzzzz_0_xzzzzzzz_1, g_0_zzzzz_0_yyyyyyyz_0, g_0_zzzzz_0_yyyyyyyz_1, g_0_zzzzz_0_yyyyyyzz_0, g_0_zzzzz_0_yyyyyyzz_1, g_0_zzzzz_0_yyyyyzzz_0, g_0_zzzzz_0_yyyyyzzz_1, g_0_zzzzz_0_yyyyzzzz_0, g_0_zzzzz_0_yyyyzzzz_1, g_0_zzzzz_0_yyyzzzzz_0, g_0_zzzzz_0_yyyzzzzz_1, g_0_zzzzz_0_yyzzzzzz_0, g_0_zzzzz_0_yyzzzzzz_1, g_0_zzzzz_0_yzzzzzzz_0, g_0_zzzzz_0_yzzzzzzz_1, g_0_zzzzz_0_zzzzzzzz_0, g_0_zzzzz_0_zzzzzzzz_1, wp_y, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_yyzzzzz_0_xxxxxxxx_0[i] = g_0_zzzzz_0_xxxxxxxx_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxxxx_0[i] * pb_y + g_0_yzzzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxxxy_0[i] = 4.0 * g_0_yyzzz_0_xxxxxxxy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxxy_0[i] * pb_z + g_0_yyzzzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxxxxxxz_0[i] = g_0_zzzzz_0_xxxxxxxz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxxxz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxxyy_0[i] = 4.0 * g_0_yyzzz_0_xxxxxxyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxxyy_0[i] * pb_z + g_0_yyzzzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxxxxxyz_0[i] = g_0_zzzzz_0_xxxxxxyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxxyz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxxzz_0[i] = g_0_zzzzz_0_xxxxxxzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxxzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxxzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxyyy_0[i] = 4.0 * g_0_yyzzz_0_xxxxxyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxxyyy_0[i] * pb_z + g_0_yyzzzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxxxxyyz_0[i] = g_0_zzzzz_0_xxxxxyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxyyz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxyyz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxyzz_0[i] = g_0_zzzzz_0_xxxxxyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxyzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxxyzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxxzzz_0[i] = g_0_zzzzz_0_xxxxxzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxxzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxxzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_yyzzz_0_xxxxyyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxxyyyy_0[i] * pb_z + g_0_yyzzzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxxxyyyz_0[i] = g_0_zzzzz_0_xxxxyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyyyz_1[i] * fti_ab_0 + 3.0 * g_0_yzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyyyz_0[i] * pb_y + g_0_yzzzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxyyzz_0[i] = g_0_zzzzz_0_xxxxyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyyzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxyzzz_0[i] = g_0_zzzzz_0_xxxxyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxyzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxxyzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxxzzzz_0[i] = g_0_zzzzz_0_xxxxzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxxzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxxzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxyyyyy_0[i] = 4.0 * g_0_yyzzz_0_xxxyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxxyyyyy_0[i] * pb_z + g_0_yyzzzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxxyyyyz_0[i] = g_0_zzzzz_0_xxxyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyyyz_1[i] * fti_ab_0 + 4.0 * g_0_yzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyyyz_0[i] * pb_y + g_0_yzzzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxyyyzz_0[i] = g_0_zzzzz_0_xxxyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 3.0 * g_0_yzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyyzz_0[i] * pb_y + g_0_yzzzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxyyzzz_0[i] = g_0_zzzzz_0_xxxyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyyzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxyzzzz_0[i] = g_0_zzzzz_0_xxxyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxyzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxxyzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxxzzzzz_0[i] = g_0_zzzzz_0_xxxzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxxzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxxzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxyyyyyy_0[i] = 4.0 * g_0_yyzzz_0_xxyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xxyyyyyy_0[i] * pb_z + g_0_yyzzzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xxyyyyyz_0[i] = g_0_zzzzz_0_xxyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyyyz_1[i] * fti_ab_0 + 5.0 * g_0_yzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyyyz_0[i] * pb_y + g_0_yzzzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxyyyyzz_0[i] = g_0_zzzzz_0_xxyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 4.0 * g_0_yzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyyzz_0[i] * pb_y + g_0_yzzzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxyyyzzz_0[i] = g_0_zzzzz_0_xxyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_yzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyyzzz_0[i] * pb_y + g_0_yzzzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxyyzzzz_0[i] = g_0_zzzzz_0_xxyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyyzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxyzzzzz_0[i] = g_0_zzzzz_0_xxyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxyzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xxyzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xxzzzzzz_0[i] = g_0_zzzzz_0_xxzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xxzzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xxzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyyyyyyy_0[i] = 4.0 * g_0_yyzzz_0_xyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_xyyyyyyy_0[i] * pb_z + g_0_yyzzzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_xyyyyyyz_0[i] = g_0_zzzzz_0_xyyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyyyz_1[i] * fti_ab_0 + 6.0 * g_0_yzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyyyz_0[i] * pb_y + g_0_yzzzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyyyyyzz_0[i] = g_0_zzzzz_0_xyyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyyzz_1[i] * fti_ab_0 + 5.0 * g_0_yzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyyzz_0[i] * pb_y + g_0_yzzzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyyyyzzz_0[i] = g_0_zzzzz_0_xyyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyyzzz_1[i] * fti_ab_0 + 4.0 * g_0_yzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyyzzz_0[i] * pb_y + g_0_yzzzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyyyzzzz_0[i] = g_0_zzzzz_0_xyyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyyzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyyzzzz_0[i] * pb_y + g_0_yzzzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyyzzzzz_0[i] = g_0_zzzzz_0_xyyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyyzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyyzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xyzzzzzz_0[i] = g_0_zzzzz_0_xyzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xyzzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_xyzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_xzzzzzzz_0[i] = g_0_zzzzz_0_xzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_xzzzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_xzzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyyyyyyy_0[i] = 4.0 * g_0_yyzzz_0_yyyyyyyy_0[i] * fi_ab_0 - 4.0 * g_0_yyzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_yyzzzz_0_yyyyyyyy_0[i] * pb_z + g_0_yyzzzz_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_yyzzzzz_0_yyyyyyyz_0[i] = g_0_zzzzz_0_yyyyyyyz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyyyz_1[i] * fti_ab_0 + 7.0 * g_0_yzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyyyyyyz_0[i] * pb_y + g_0_yzzzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyyyyyzz_0[i] = g_0_zzzzz_0_yyyyyyzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyyzz_1[i] * fti_ab_0 + 6.0 * g_0_yzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyyyyyzz_0[i] * pb_y + g_0_yzzzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyyyyzzz_0[i] = g_0_zzzzz_0_yyyyyzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyyzzz_1[i] * fti_ab_0 + 5.0 * g_0_yzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyyyyzzz_0[i] * pb_y + g_0_yzzzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyyyzzzz_0[i] = g_0_zzzzz_0_yyyyzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_yzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyyyzzzz_0[i] * pb_y + g_0_yzzzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyyzzzzz_0[i] = g_0_zzzzz_0_yyyzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyyzzzzz_1[i] * fti_ab_0 + 3.0 * g_0_yzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyyzzzzz_0[i] * pb_y + g_0_yzzzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yyzzzzzz_0[i] = g_0_zzzzz_0_yyzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yyzzzzzz_1[i] * fti_ab_0 + 2.0 * g_0_yzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yyzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_yzzzzzzz_0[i] = g_0_zzzzz_0_yzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_yzzzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_yzzzzz_0_yzzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yyzzzzz_0_zzzzzzzz_0[i] = g_0_zzzzz_0_zzzzzzzz_0[i] * fi_ab_0 - g_0_zzzzz_0_zzzzzzzz_1[i] * fti_ab_0 + g_0_yzzzzz_0_zzzzzzzz_0[i] * pb_y + g_0_yzzzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1530-1575 components of targeted buffer : SKSL

    auto g_0_yzzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1530);

    auto g_0_yzzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1531);

    auto g_0_yzzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1532);

    auto g_0_yzzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1533);

    auto g_0_yzzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1534);

    auto g_0_yzzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1535);

    auto g_0_yzzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1536);

    auto g_0_yzzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1537);

    auto g_0_yzzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1538);

    auto g_0_yzzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1539);

    auto g_0_yzzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1540);

    auto g_0_yzzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1541);

    auto g_0_yzzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1542);

    auto g_0_yzzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1543);

    auto g_0_yzzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1544);

    auto g_0_yzzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1545);

    auto g_0_yzzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1546);

    auto g_0_yzzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1547);

    auto g_0_yzzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1548);

    auto g_0_yzzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1549);

    auto g_0_yzzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1550);

    auto g_0_yzzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1551);

    auto g_0_yzzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1552);

    auto g_0_yzzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1553);

    auto g_0_yzzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1554);

    auto g_0_yzzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1555);

    auto g_0_yzzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1556);

    auto g_0_yzzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1557);

    auto g_0_yzzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1558);

    auto g_0_yzzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1559);

    auto g_0_yzzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1560);

    auto g_0_yzzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1561);

    auto g_0_yzzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1562);

    auto g_0_yzzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1563);

    auto g_0_yzzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1564);

    auto g_0_yzzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1565);

    auto g_0_yzzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1566);

    auto g_0_yzzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1567);

    auto g_0_yzzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1568);

    auto g_0_yzzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1569);

    auto g_0_yzzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1570);

    auto g_0_yzzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1571);

    auto g_0_yzzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1572);

    auto g_0_yzzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1573);

    auto g_0_yzzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1574);

    #pragma omp simd aligned(g_0_yzzzzzz_0_xxxxxxxx_0, g_0_yzzzzzz_0_xxxxxxxy_0, g_0_yzzzzzz_0_xxxxxxxz_0, g_0_yzzzzzz_0_xxxxxxyy_0, g_0_yzzzzzz_0_xxxxxxyz_0, g_0_yzzzzzz_0_xxxxxxzz_0, g_0_yzzzzzz_0_xxxxxyyy_0, g_0_yzzzzzz_0_xxxxxyyz_0, g_0_yzzzzzz_0_xxxxxyzz_0, g_0_yzzzzzz_0_xxxxxzzz_0, g_0_yzzzzzz_0_xxxxyyyy_0, g_0_yzzzzzz_0_xxxxyyyz_0, g_0_yzzzzzz_0_xxxxyyzz_0, g_0_yzzzzzz_0_xxxxyzzz_0, g_0_yzzzzzz_0_xxxxzzzz_0, g_0_yzzzzzz_0_xxxyyyyy_0, g_0_yzzzzzz_0_xxxyyyyz_0, g_0_yzzzzzz_0_xxxyyyzz_0, g_0_yzzzzzz_0_xxxyyzzz_0, g_0_yzzzzzz_0_xxxyzzzz_0, g_0_yzzzzzz_0_xxxzzzzz_0, g_0_yzzzzzz_0_xxyyyyyy_0, g_0_yzzzzzz_0_xxyyyyyz_0, g_0_yzzzzzz_0_xxyyyyzz_0, g_0_yzzzzzz_0_xxyyyzzz_0, g_0_yzzzzzz_0_xxyyzzzz_0, g_0_yzzzzzz_0_xxyzzzzz_0, g_0_yzzzzzz_0_xxzzzzzz_0, g_0_yzzzzzz_0_xyyyyyyy_0, g_0_yzzzzzz_0_xyyyyyyz_0, g_0_yzzzzzz_0_xyyyyyzz_0, g_0_yzzzzzz_0_xyyyyzzz_0, g_0_yzzzzzz_0_xyyyzzzz_0, g_0_yzzzzzz_0_xyyzzzzz_0, g_0_yzzzzzz_0_xyzzzzzz_0, g_0_yzzzzzz_0_xzzzzzzz_0, g_0_yzzzzzz_0_yyyyyyyy_0, g_0_yzzzzzz_0_yyyyyyyz_0, g_0_yzzzzzz_0_yyyyyyzz_0, g_0_yzzzzzz_0_yyyyyzzz_0, g_0_yzzzzzz_0_yyyyzzzz_0, g_0_yzzzzzz_0_yyyzzzzz_0, g_0_yzzzzzz_0_yyzzzzzz_0, g_0_yzzzzzz_0_yzzzzzzz_0, g_0_yzzzzzz_0_zzzzzzzz_0, g_0_zzzzzz_0_xxxxxxx_1, g_0_zzzzzz_0_xxxxxxxx_0, g_0_zzzzzz_0_xxxxxxxx_1, g_0_zzzzzz_0_xxxxxxxy_0, g_0_zzzzzz_0_xxxxxxxy_1, g_0_zzzzzz_0_xxxxxxxz_0, g_0_zzzzzz_0_xxxxxxxz_1, g_0_zzzzzz_0_xxxxxxy_1, g_0_zzzzzz_0_xxxxxxyy_0, g_0_zzzzzz_0_xxxxxxyy_1, g_0_zzzzzz_0_xxxxxxyz_0, g_0_zzzzzz_0_xxxxxxyz_1, g_0_zzzzzz_0_xxxxxxz_1, g_0_zzzzzz_0_xxxxxxzz_0, g_0_zzzzzz_0_xxxxxxzz_1, g_0_zzzzzz_0_xxxxxyy_1, g_0_zzzzzz_0_xxxxxyyy_0, g_0_zzzzzz_0_xxxxxyyy_1, g_0_zzzzzz_0_xxxxxyyz_0, g_0_zzzzzz_0_xxxxxyyz_1, g_0_zzzzzz_0_xxxxxyz_1, g_0_zzzzzz_0_xxxxxyzz_0, g_0_zzzzzz_0_xxxxxyzz_1, g_0_zzzzzz_0_xxxxxzz_1, g_0_zzzzzz_0_xxxxxzzz_0, g_0_zzzzzz_0_xxxxxzzz_1, g_0_zzzzzz_0_xxxxyyy_1, g_0_zzzzzz_0_xxxxyyyy_0, g_0_zzzzzz_0_xxxxyyyy_1, g_0_zzzzzz_0_xxxxyyyz_0, g_0_zzzzzz_0_xxxxyyyz_1, g_0_zzzzzz_0_xxxxyyz_1, g_0_zzzzzz_0_xxxxyyzz_0, g_0_zzzzzz_0_xxxxyyzz_1, g_0_zzzzzz_0_xxxxyzz_1, g_0_zzzzzz_0_xxxxyzzz_0, g_0_zzzzzz_0_xxxxyzzz_1, g_0_zzzzzz_0_xxxxzzz_1, g_0_zzzzzz_0_xxxxzzzz_0, g_0_zzzzzz_0_xxxxzzzz_1, g_0_zzzzzz_0_xxxyyyy_1, g_0_zzzzzz_0_xxxyyyyy_0, g_0_zzzzzz_0_xxxyyyyy_1, g_0_zzzzzz_0_xxxyyyyz_0, g_0_zzzzzz_0_xxxyyyyz_1, g_0_zzzzzz_0_xxxyyyz_1, g_0_zzzzzz_0_xxxyyyzz_0, g_0_zzzzzz_0_xxxyyyzz_1, g_0_zzzzzz_0_xxxyyzz_1, g_0_zzzzzz_0_xxxyyzzz_0, g_0_zzzzzz_0_xxxyyzzz_1, g_0_zzzzzz_0_xxxyzzz_1, g_0_zzzzzz_0_xxxyzzzz_0, g_0_zzzzzz_0_xxxyzzzz_1, g_0_zzzzzz_0_xxxzzzz_1, g_0_zzzzzz_0_xxxzzzzz_0, g_0_zzzzzz_0_xxxzzzzz_1, g_0_zzzzzz_0_xxyyyyy_1, g_0_zzzzzz_0_xxyyyyyy_0, g_0_zzzzzz_0_xxyyyyyy_1, g_0_zzzzzz_0_xxyyyyyz_0, g_0_zzzzzz_0_xxyyyyyz_1, g_0_zzzzzz_0_xxyyyyz_1, g_0_zzzzzz_0_xxyyyyzz_0, g_0_zzzzzz_0_xxyyyyzz_1, g_0_zzzzzz_0_xxyyyzz_1, g_0_zzzzzz_0_xxyyyzzz_0, g_0_zzzzzz_0_xxyyyzzz_1, g_0_zzzzzz_0_xxyyzzz_1, g_0_zzzzzz_0_xxyyzzzz_0, g_0_zzzzzz_0_xxyyzzzz_1, g_0_zzzzzz_0_xxyzzzz_1, g_0_zzzzzz_0_xxyzzzzz_0, g_0_zzzzzz_0_xxyzzzzz_1, g_0_zzzzzz_0_xxzzzzz_1, g_0_zzzzzz_0_xxzzzzzz_0, g_0_zzzzzz_0_xxzzzzzz_1, g_0_zzzzzz_0_xyyyyyy_1, g_0_zzzzzz_0_xyyyyyyy_0, g_0_zzzzzz_0_xyyyyyyy_1, g_0_zzzzzz_0_xyyyyyyz_0, g_0_zzzzzz_0_xyyyyyyz_1, g_0_zzzzzz_0_xyyyyyz_1, g_0_zzzzzz_0_xyyyyyzz_0, g_0_zzzzzz_0_xyyyyyzz_1, g_0_zzzzzz_0_xyyyyzz_1, g_0_zzzzzz_0_xyyyyzzz_0, g_0_zzzzzz_0_xyyyyzzz_1, g_0_zzzzzz_0_xyyyzzz_1, g_0_zzzzzz_0_xyyyzzzz_0, g_0_zzzzzz_0_xyyyzzzz_1, g_0_zzzzzz_0_xyyzzzz_1, g_0_zzzzzz_0_xyyzzzzz_0, g_0_zzzzzz_0_xyyzzzzz_1, g_0_zzzzzz_0_xyzzzzz_1, g_0_zzzzzz_0_xyzzzzzz_0, g_0_zzzzzz_0_xyzzzzzz_1, g_0_zzzzzz_0_xzzzzzz_1, g_0_zzzzzz_0_xzzzzzzz_0, g_0_zzzzzz_0_xzzzzzzz_1, g_0_zzzzzz_0_yyyyyyy_1, g_0_zzzzzz_0_yyyyyyyy_0, g_0_zzzzzz_0_yyyyyyyy_1, g_0_zzzzzz_0_yyyyyyyz_0, g_0_zzzzzz_0_yyyyyyyz_1, g_0_zzzzzz_0_yyyyyyz_1, g_0_zzzzzz_0_yyyyyyzz_0, g_0_zzzzzz_0_yyyyyyzz_1, g_0_zzzzzz_0_yyyyyzz_1, g_0_zzzzzz_0_yyyyyzzz_0, g_0_zzzzzz_0_yyyyyzzz_1, g_0_zzzzzz_0_yyyyzzz_1, g_0_zzzzzz_0_yyyyzzzz_0, g_0_zzzzzz_0_yyyyzzzz_1, g_0_zzzzzz_0_yyyzzzz_1, g_0_zzzzzz_0_yyyzzzzz_0, g_0_zzzzzz_0_yyyzzzzz_1, g_0_zzzzzz_0_yyzzzzz_1, g_0_zzzzzz_0_yyzzzzzz_0, g_0_zzzzzz_0_yyzzzzzz_1, g_0_zzzzzz_0_yzzzzzz_1, g_0_zzzzzz_0_yzzzzzzz_0, g_0_zzzzzz_0_yzzzzzzz_1, g_0_zzzzzz_0_zzzzzzz_1, g_0_zzzzzz_0_zzzzzzzz_0, g_0_zzzzzz_0_zzzzzzzz_1, wp_y, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        g_0_yzzzzzz_0_xxxxxxxx_0[i] = g_0_zzzzzz_0_xxxxxxxx_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxxx_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxxxy_0[i] = g_0_zzzzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxxy_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxxy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxxxz_0[i] = g_0_zzzzzz_0_xxxxxxxz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxxz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxxyy_0[i] = 2.0 * g_0_zzzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxyy_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxxyz_0[i] = g_0_zzzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxyz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxxzz_0[i] = g_0_zzzzzz_0_xxxxxxzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxxzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxyyy_0[i] = 3.0 * g_0_zzzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyyy_0[i] * pb_y + g_0_zzzzzz_0_xxxxxyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxyyz_0[i] = 2.0 * g_0_zzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyyz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxyzz_0[i] = g_0_zzzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxxzzz_0[i] = g_0_zzzzzz_0_xxxxxzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxxzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxyyyy_0[i] = 4.0 * g_0_zzzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyyy_0[i] * pb_y + g_0_zzzzzz_0_xxxxyyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxyyyz_0[i] = 3.0 * g_0_zzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyyz_0[i] * pb_y + g_0_zzzzzz_0_xxxxyyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxyyzz_0[i] = 2.0 * g_0_zzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxyyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxyzzz_0[i] = g_0_zzzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxyzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxxzzzz_0[i] = g_0_zzzzzz_0_xxxxzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxxzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxyyyyy_0[i] = 5.0 * g_0_zzzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyyy_0[i] * pb_y + g_0_zzzzzz_0_xxxyyyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxyyyyz_0[i] = 4.0 * g_0_zzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyyz_0[i] * pb_y + g_0_zzzzzz_0_xxxyyyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxyyyzz_0[i] = 3.0 * g_0_zzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyzz_0[i] * pb_y + g_0_zzzzzz_0_xxxyyyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxyyzzz_0[i] = 2.0 * g_0_zzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxyyzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxyzzzz_0[i] = g_0_zzzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxyzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxxzzzzz_0[i] = g_0_zzzzzz_0_xxxzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxxzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyyyyyy_0[i] = 6.0 * g_0_zzzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyyy_0[i] * pb_y + g_0_zzzzzz_0_xxyyyyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyyyyyz_0[i] = 5.0 * g_0_zzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyyz_0[i] * pb_y + g_0_zzzzzz_0_xxyyyyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyyyyzz_0[i] = 4.0 * g_0_zzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyzz_0[i] * pb_y + g_0_zzzzzz_0_xxyyyyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyyyzzz_0[i] = 3.0 * g_0_zzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyzzz_0[i] * pb_y + g_0_zzzzzz_0_xxyyyzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyyzzzz_0[i] = 2.0 * g_0_zzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxyyzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxyzzzzz_0[i] = g_0_zzzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxyzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xxzzzzzz_0[i] = g_0_zzzzzz_0_xxzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xxzzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyyyyyy_0[i] = 7.0 * g_0_zzzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyyy_0[i] * pb_y + g_0_zzzzzz_0_xyyyyyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyyyyyz_0[i] = 6.0 * g_0_zzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyyz_0[i] * pb_y + g_0_zzzzzz_0_xyyyyyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyyyyzz_0[i] = 5.0 * g_0_zzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyzz_0[i] * pb_y + g_0_zzzzzz_0_xyyyyyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyyyzzz_0[i] = 4.0 * g_0_zzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyzzz_0[i] * pb_y + g_0_zzzzzz_0_xyyyyzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyyzzzz_0[i] = 3.0 * g_0_zzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyzzzz_0[i] * pb_y + g_0_zzzzzz_0_xyyyzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyyzzzzz_0[i] = 2.0 * g_0_zzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xyyzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xyzzzzzz_0[i] = g_0_zzzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xyzzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_xzzzzzzz_0[i] = g_0_zzzzzz_0_xzzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_xzzzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyyyyyy_0[i] = 8.0 * g_0_zzzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyyyy_0[i] * pb_y + g_0_zzzzzz_0_yyyyyyyy_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyyyyyz_0[i] = 7.0 * g_0_zzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyyyz_0[i] * pb_y + g_0_zzzzzz_0_yyyyyyyz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyyyyzz_0[i] = 6.0 * g_0_zzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyyzz_0[i] * pb_y + g_0_zzzzzz_0_yyyyyyzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyyyzzz_0[i] = 5.0 * g_0_zzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyzzz_0[i] * pb_y + g_0_zzzzzz_0_yyyyyzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyyzzzz_0[i] = 4.0 * g_0_zzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyzzzz_0[i] * pb_y + g_0_zzzzzz_0_yyyyzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyyzzzzz_0[i] = 3.0 * g_0_zzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyzzzzz_0[i] * pb_y + g_0_zzzzzz_0_yyyzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yyzzzzzz_0[i] = 2.0 * g_0_zzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_yyzzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_yzzzzzzz_0[i] = g_0_zzzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yzzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_yzzzzzzz_1[i] * wp_y[i];

        g_0_yzzzzzz_0_zzzzzzzz_0[i] = g_0_zzzzzz_0_zzzzzzzz_0[i] * pb_y + g_0_zzzzzz_0_zzzzzzzz_1[i] * wp_y[i];
    }

    /// Set up 1575-1620 components of targeted buffer : SKSL

    auto g_0_zzzzzzz_0_xxxxxxxx_0 = pbuffer.data(idx_eri_0_sksl + 1575);

    auto g_0_zzzzzzz_0_xxxxxxxy_0 = pbuffer.data(idx_eri_0_sksl + 1576);

    auto g_0_zzzzzzz_0_xxxxxxxz_0 = pbuffer.data(idx_eri_0_sksl + 1577);

    auto g_0_zzzzzzz_0_xxxxxxyy_0 = pbuffer.data(idx_eri_0_sksl + 1578);

    auto g_0_zzzzzzz_0_xxxxxxyz_0 = pbuffer.data(idx_eri_0_sksl + 1579);

    auto g_0_zzzzzzz_0_xxxxxxzz_0 = pbuffer.data(idx_eri_0_sksl + 1580);

    auto g_0_zzzzzzz_0_xxxxxyyy_0 = pbuffer.data(idx_eri_0_sksl + 1581);

    auto g_0_zzzzzzz_0_xxxxxyyz_0 = pbuffer.data(idx_eri_0_sksl + 1582);

    auto g_0_zzzzzzz_0_xxxxxyzz_0 = pbuffer.data(idx_eri_0_sksl + 1583);

    auto g_0_zzzzzzz_0_xxxxxzzz_0 = pbuffer.data(idx_eri_0_sksl + 1584);

    auto g_0_zzzzzzz_0_xxxxyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1585);

    auto g_0_zzzzzzz_0_xxxxyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1586);

    auto g_0_zzzzzzz_0_xxxxyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1587);

    auto g_0_zzzzzzz_0_xxxxyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1588);

    auto g_0_zzzzzzz_0_xxxxzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1589);

    auto g_0_zzzzzzz_0_xxxyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1590);

    auto g_0_zzzzzzz_0_xxxyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1591);

    auto g_0_zzzzzzz_0_xxxyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1592);

    auto g_0_zzzzzzz_0_xxxyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1593);

    auto g_0_zzzzzzz_0_xxxyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1594);

    auto g_0_zzzzzzz_0_xxxzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1595);

    auto g_0_zzzzzzz_0_xxyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1596);

    auto g_0_zzzzzzz_0_xxyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1597);

    auto g_0_zzzzzzz_0_xxyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1598);

    auto g_0_zzzzzzz_0_xxyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1599);

    auto g_0_zzzzzzz_0_xxyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1600);

    auto g_0_zzzzzzz_0_xxyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1601);

    auto g_0_zzzzzzz_0_xxzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1602);

    auto g_0_zzzzzzz_0_xyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1603);

    auto g_0_zzzzzzz_0_xyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1604);

    auto g_0_zzzzzzz_0_xyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1605);

    auto g_0_zzzzzzz_0_xyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1606);

    auto g_0_zzzzzzz_0_xyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1607);

    auto g_0_zzzzzzz_0_xyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1608);

    auto g_0_zzzzzzz_0_xyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1609);

    auto g_0_zzzzzzz_0_xzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1610);

    auto g_0_zzzzzzz_0_yyyyyyyy_0 = pbuffer.data(idx_eri_0_sksl + 1611);

    auto g_0_zzzzzzz_0_yyyyyyyz_0 = pbuffer.data(idx_eri_0_sksl + 1612);

    auto g_0_zzzzzzz_0_yyyyyyzz_0 = pbuffer.data(idx_eri_0_sksl + 1613);

    auto g_0_zzzzzzz_0_yyyyyzzz_0 = pbuffer.data(idx_eri_0_sksl + 1614);

    auto g_0_zzzzzzz_0_yyyyzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1615);

    auto g_0_zzzzzzz_0_yyyzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1616);

    auto g_0_zzzzzzz_0_yyzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1617);

    auto g_0_zzzzzzz_0_yzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1618);

    auto g_0_zzzzzzz_0_zzzzzzzz_0 = pbuffer.data(idx_eri_0_sksl + 1619);

    #pragma omp simd aligned(g_0_zzzzz_0_xxxxxxxx_0, g_0_zzzzz_0_xxxxxxxx_1, g_0_zzzzz_0_xxxxxxxy_0, g_0_zzzzz_0_xxxxxxxy_1, g_0_zzzzz_0_xxxxxxxz_0, g_0_zzzzz_0_xxxxxxxz_1, g_0_zzzzz_0_xxxxxxyy_0, g_0_zzzzz_0_xxxxxxyy_1, g_0_zzzzz_0_xxxxxxyz_0, g_0_zzzzz_0_xxxxxxyz_1, g_0_zzzzz_0_xxxxxxzz_0, g_0_zzzzz_0_xxxxxxzz_1, g_0_zzzzz_0_xxxxxyyy_0, g_0_zzzzz_0_xxxxxyyy_1, g_0_zzzzz_0_xxxxxyyz_0, g_0_zzzzz_0_xxxxxyyz_1, g_0_zzzzz_0_xxxxxyzz_0, g_0_zzzzz_0_xxxxxyzz_1, g_0_zzzzz_0_xxxxxzzz_0, g_0_zzzzz_0_xxxxxzzz_1, g_0_zzzzz_0_xxxxyyyy_0, g_0_zzzzz_0_xxxxyyyy_1, g_0_zzzzz_0_xxxxyyyz_0, g_0_zzzzz_0_xxxxyyyz_1, g_0_zzzzz_0_xxxxyyzz_0, g_0_zzzzz_0_xxxxyyzz_1, g_0_zzzzz_0_xxxxyzzz_0, g_0_zzzzz_0_xxxxyzzz_1, g_0_zzzzz_0_xxxxzzzz_0, g_0_zzzzz_0_xxxxzzzz_1, g_0_zzzzz_0_xxxyyyyy_0, g_0_zzzzz_0_xxxyyyyy_1, g_0_zzzzz_0_xxxyyyyz_0, g_0_zzzzz_0_xxxyyyyz_1, g_0_zzzzz_0_xxxyyyzz_0, g_0_zzzzz_0_xxxyyyzz_1, g_0_zzzzz_0_xxxyyzzz_0, g_0_zzzzz_0_xxxyyzzz_1, g_0_zzzzz_0_xxxyzzzz_0, g_0_zzzzz_0_xxxyzzzz_1, g_0_zzzzz_0_xxxzzzzz_0, g_0_zzzzz_0_xxxzzzzz_1, g_0_zzzzz_0_xxyyyyyy_0, g_0_zzzzz_0_xxyyyyyy_1, g_0_zzzzz_0_xxyyyyyz_0, g_0_zzzzz_0_xxyyyyyz_1, g_0_zzzzz_0_xxyyyyzz_0, g_0_zzzzz_0_xxyyyyzz_1, g_0_zzzzz_0_xxyyyzzz_0, g_0_zzzzz_0_xxyyyzzz_1, g_0_zzzzz_0_xxyyzzzz_0, g_0_zzzzz_0_xxyyzzzz_1, g_0_zzzzz_0_xxyzzzzz_0, g_0_zzzzz_0_xxyzzzzz_1, g_0_zzzzz_0_xxzzzzzz_0, g_0_zzzzz_0_xxzzzzzz_1, g_0_zzzzz_0_xyyyyyyy_0, g_0_zzzzz_0_xyyyyyyy_1, g_0_zzzzz_0_xyyyyyyz_0, g_0_zzzzz_0_xyyyyyyz_1, g_0_zzzzz_0_xyyyyyzz_0, g_0_zzzzz_0_xyyyyyzz_1, g_0_zzzzz_0_xyyyyzzz_0, g_0_zzzzz_0_xyyyyzzz_1, g_0_zzzzz_0_xyyyzzzz_0, g_0_zzzzz_0_xyyyzzzz_1, g_0_zzzzz_0_xyyzzzzz_0, g_0_zzzzz_0_xyyzzzzz_1, g_0_zzzzz_0_xyzzzzzz_0, g_0_zzzzz_0_xyzzzzzz_1, g_0_zzzzz_0_xzzzzzzz_0, g_0_zzzzz_0_xzzzzzzz_1, g_0_zzzzz_0_yyyyyyyy_0, g_0_zzzzz_0_yyyyyyyy_1, g_0_zzzzz_0_yyyyyyyz_0, g_0_zzzzz_0_yyyyyyyz_1, g_0_zzzzz_0_yyyyyyzz_0, g_0_zzzzz_0_yyyyyyzz_1, g_0_zzzzz_0_yyyyyzzz_0, g_0_zzzzz_0_yyyyyzzz_1, g_0_zzzzz_0_yyyyzzzz_0, g_0_zzzzz_0_yyyyzzzz_1, g_0_zzzzz_0_yyyzzzzz_0, g_0_zzzzz_0_yyyzzzzz_1, g_0_zzzzz_0_yyzzzzzz_0, g_0_zzzzz_0_yyzzzzzz_1, g_0_zzzzz_0_yzzzzzzz_0, g_0_zzzzz_0_yzzzzzzz_1, g_0_zzzzz_0_zzzzzzzz_0, g_0_zzzzz_0_zzzzzzzz_1, g_0_zzzzzz_0_xxxxxxx_1, g_0_zzzzzz_0_xxxxxxxx_0, g_0_zzzzzz_0_xxxxxxxx_1, g_0_zzzzzz_0_xxxxxxxy_0, g_0_zzzzzz_0_xxxxxxxy_1, g_0_zzzzzz_0_xxxxxxxz_0, g_0_zzzzzz_0_xxxxxxxz_1, g_0_zzzzzz_0_xxxxxxy_1, g_0_zzzzzz_0_xxxxxxyy_0, g_0_zzzzzz_0_xxxxxxyy_1, g_0_zzzzzz_0_xxxxxxyz_0, g_0_zzzzzz_0_xxxxxxyz_1, g_0_zzzzzz_0_xxxxxxz_1, g_0_zzzzzz_0_xxxxxxzz_0, g_0_zzzzzz_0_xxxxxxzz_1, g_0_zzzzzz_0_xxxxxyy_1, g_0_zzzzzz_0_xxxxxyyy_0, g_0_zzzzzz_0_xxxxxyyy_1, g_0_zzzzzz_0_xxxxxyyz_0, g_0_zzzzzz_0_xxxxxyyz_1, g_0_zzzzzz_0_xxxxxyz_1, g_0_zzzzzz_0_xxxxxyzz_0, g_0_zzzzzz_0_xxxxxyzz_1, g_0_zzzzzz_0_xxxxxzz_1, g_0_zzzzzz_0_xxxxxzzz_0, g_0_zzzzzz_0_xxxxxzzz_1, g_0_zzzzzz_0_xxxxyyy_1, g_0_zzzzzz_0_xxxxyyyy_0, g_0_zzzzzz_0_xxxxyyyy_1, g_0_zzzzzz_0_xxxxyyyz_0, g_0_zzzzzz_0_xxxxyyyz_1, g_0_zzzzzz_0_xxxxyyz_1, g_0_zzzzzz_0_xxxxyyzz_0, g_0_zzzzzz_0_xxxxyyzz_1, g_0_zzzzzz_0_xxxxyzz_1, g_0_zzzzzz_0_xxxxyzzz_0, g_0_zzzzzz_0_xxxxyzzz_1, g_0_zzzzzz_0_xxxxzzz_1, g_0_zzzzzz_0_xxxxzzzz_0, g_0_zzzzzz_0_xxxxzzzz_1, g_0_zzzzzz_0_xxxyyyy_1, g_0_zzzzzz_0_xxxyyyyy_0, g_0_zzzzzz_0_xxxyyyyy_1, g_0_zzzzzz_0_xxxyyyyz_0, g_0_zzzzzz_0_xxxyyyyz_1, g_0_zzzzzz_0_xxxyyyz_1, g_0_zzzzzz_0_xxxyyyzz_0, g_0_zzzzzz_0_xxxyyyzz_1, g_0_zzzzzz_0_xxxyyzz_1, g_0_zzzzzz_0_xxxyyzzz_0, g_0_zzzzzz_0_xxxyyzzz_1, g_0_zzzzzz_0_xxxyzzz_1, g_0_zzzzzz_0_xxxyzzzz_0, g_0_zzzzzz_0_xxxyzzzz_1, g_0_zzzzzz_0_xxxzzzz_1, g_0_zzzzzz_0_xxxzzzzz_0, g_0_zzzzzz_0_xxxzzzzz_1, g_0_zzzzzz_0_xxyyyyy_1, g_0_zzzzzz_0_xxyyyyyy_0, g_0_zzzzzz_0_xxyyyyyy_1, g_0_zzzzzz_0_xxyyyyyz_0, g_0_zzzzzz_0_xxyyyyyz_1, g_0_zzzzzz_0_xxyyyyz_1, g_0_zzzzzz_0_xxyyyyzz_0, g_0_zzzzzz_0_xxyyyyzz_1, g_0_zzzzzz_0_xxyyyzz_1, g_0_zzzzzz_0_xxyyyzzz_0, g_0_zzzzzz_0_xxyyyzzz_1, g_0_zzzzzz_0_xxyyzzz_1, g_0_zzzzzz_0_xxyyzzzz_0, g_0_zzzzzz_0_xxyyzzzz_1, g_0_zzzzzz_0_xxyzzzz_1, g_0_zzzzzz_0_xxyzzzzz_0, g_0_zzzzzz_0_xxyzzzzz_1, g_0_zzzzzz_0_xxzzzzz_1, g_0_zzzzzz_0_xxzzzzzz_0, g_0_zzzzzz_0_xxzzzzzz_1, g_0_zzzzzz_0_xyyyyyy_1, g_0_zzzzzz_0_xyyyyyyy_0, g_0_zzzzzz_0_xyyyyyyy_1, g_0_zzzzzz_0_xyyyyyyz_0, g_0_zzzzzz_0_xyyyyyyz_1, g_0_zzzzzz_0_xyyyyyz_1, g_0_zzzzzz_0_xyyyyyzz_0, g_0_zzzzzz_0_xyyyyyzz_1, g_0_zzzzzz_0_xyyyyzz_1, g_0_zzzzzz_0_xyyyyzzz_0, g_0_zzzzzz_0_xyyyyzzz_1, g_0_zzzzzz_0_xyyyzzz_1, g_0_zzzzzz_0_xyyyzzzz_0, g_0_zzzzzz_0_xyyyzzzz_1, g_0_zzzzzz_0_xyyzzzz_1, g_0_zzzzzz_0_xyyzzzzz_0, g_0_zzzzzz_0_xyyzzzzz_1, g_0_zzzzzz_0_xyzzzzz_1, g_0_zzzzzz_0_xyzzzzzz_0, g_0_zzzzzz_0_xyzzzzzz_1, g_0_zzzzzz_0_xzzzzzz_1, g_0_zzzzzz_0_xzzzzzzz_0, g_0_zzzzzz_0_xzzzzzzz_1, g_0_zzzzzz_0_yyyyyyy_1, g_0_zzzzzz_0_yyyyyyyy_0, g_0_zzzzzz_0_yyyyyyyy_1, g_0_zzzzzz_0_yyyyyyyz_0, g_0_zzzzzz_0_yyyyyyyz_1, g_0_zzzzzz_0_yyyyyyz_1, g_0_zzzzzz_0_yyyyyyzz_0, g_0_zzzzzz_0_yyyyyyzz_1, g_0_zzzzzz_0_yyyyyzz_1, g_0_zzzzzz_0_yyyyyzzz_0, g_0_zzzzzz_0_yyyyyzzz_1, g_0_zzzzzz_0_yyyyzzz_1, g_0_zzzzzz_0_yyyyzzzz_0, g_0_zzzzzz_0_yyyyzzzz_1, g_0_zzzzzz_0_yyyzzzz_1, g_0_zzzzzz_0_yyyzzzzz_0, g_0_zzzzzz_0_yyyzzzzz_1, g_0_zzzzzz_0_yyzzzzz_1, g_0_zzzzzz_0_yyzzzzzz_0, g_0_zzzzzz_0_yyzzzzzz_1, g_0_zzzzzz_0_yzzzzzz_1, g_0_zzzzzz_0_yzzzzzzz_0, g_0_zzzzzz_0_yzzzzzzz_1, g_0_zzzzzz_0_zzzzzzz_1, g_0_zzzzzz_0_zzzzzzzz_0, g_0_zzzzzz_0_zzzzzzzz_1, g_0_zzzzzzz_0_xxxxxxxx_0, g_0_zzzzzzz_0_xxxxxxxy_0, g_0_zzzzzzz_0_xxxxxxxz_0, g_0_zzzzzzz_0_xxxxxxyy_0, g_0_zzzzzzz_0_xxxxxxyz_0, g_0_zzzzzzz_0_xxxxxxzz_0, g_0_zzzzzzz_0_xxxxxyyy_0, g_0_zzzzzzz_0_xxxxxyyz_0, g_0_zzzzzzz_0_xxxxxyzz_0, g_0_zzzzzzz_0_xxxxxzzz_0, g_0_zzzzzzz_0_xxxxyyyy_0, g_0_zzzzzzz_0_xxxxyyyz_0, g_0_zzzzzzz_0_xxxxyyzz_0, g_0_zzzzzzz_0_xxxxyzzz_0, g_0_zzzzzzz_0_xxxxzzzz_0, g_0_zzzzzzz_0_xxxyyyyy_0, g_0_zzzzzzz_0_xxxyyyyz_0, g_0_zzzzzzz_0_xxxyyyzz_0, g_0_zzzzzzz_0_xxxyyzzz_0, g_0_zzzzzzz_0_xxxyzzzz_0, g_0_zzzzzzz_0_xxxzzzzz_0, g_0_zzzzzzz_0_xxyyyyyy_0, g_0_zzzzzzz_0_xxyyyyyz_0, g_0_zzzzzzz_0_xxyyyyzz_0, g_0_zzzzzzz_0_xxyyyzzz_0, g_0_zzzzzzz_0_xxyyzzzz_0, g_0_zzzzzzz_0_xxyzzzzz_0, g_0_zzzzzzz_0_xxzzzzzz_0, g_0_zzzzzzz_0_xyyyyyyy_0, g_0_zzzzzzz_0_xyyyyyyz_0, g_0_zzzzzzz_0_xyyyyyzz_0, g_0_zzzzzzz_0_xyyyyzzz_0, g_0_zzzzzzz_0_xyyyzzzz_0, g_0_zzzzzzz_0_xyyzzzzz_0, g_0_zzzzzzz_0_xyzzzzzz_0, g_0_zzzzzzz_0_xzzzzzzz_0, g_0_zzzzzzz_0_yyyyyyyy_0, g_0_zzzzzzz_0_yyyyyyyz_0, g_0_zzzzzzz_0_yyyyyyzz_0, g_0_zzzzzzz_0_yyyyyzzz_0, g_0_zzzzzzz_0_yyyyzzzz_0, g_0_zzzzzzz_0_yyyzzzzz_0, g_0_zzzzzzz_0_yyzzzzzz_0, g_0_zzzzzzz_0_yzzzzzzz_0, g_0_zzzzzzz_0_zzzzzzzz_0, wp_z, c_exps, d_exps  : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        const double fi_ab_0 = 0.5 / (a_exp + b_exp);

        const double fi_abcd_0 = 0.5 / (a_exp + b_exp + c_exps[i] + d_exps[i]);

        const double fti_ab_0 = 2.0 * fi_abcd_0 * fi_ab_0 * (c_exps[i] + d_exps[i]);

        g_0_zzzzzzz_0_xxxxxxxx_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxxx_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxxx_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxxxx_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxxx_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxxxy_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxxy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxxy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxxxy_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxxy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxxxz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxxz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxxz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxxx_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxxz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxxz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxxyy_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxxyy_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxxyz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxxy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxyz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxxzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxxzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxxzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xxxxxxz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxxzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxxzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxyyy_0[i] = 6.0 * g_0_zzzzz_0_xxxxxyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxyyy_0[i] * pb_z + g_0_zzzzzz_0_xxxxxyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxyyz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxxyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyyz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxyzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xxxxxyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxyzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxxzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxxzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxxzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_xxxxxzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxxzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxxzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxyyyy_0[i] = 6.0 * g_0_zzzzz_0_xxxxyyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxyyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxyyyy_0[i] * pb_z + g_0_zzzzzz_0_xxxxyyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxyyyz_0[i] = 6.0 * g_0_zzzzz_0_xxxxyyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxyyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxxyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyyz_0[i] * pb_z + g_0_zzzzzz_0_xxxxyyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxyyzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxyyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxyyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xxxxyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyyzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxyyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxyzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxyzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxyzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_xxxxyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxyzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxyzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxxzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxxzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxxzzzz_1[i] * fti_ab_0 + 4.0 * g_0_zzzzzz_0_xxxxzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxxzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxxzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxyyyyy_0[i] = 6.0 * g_0_zzzzz_0_xxxyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxyyyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxyyyyy_0[i] * pb_z + g_0_zzzzzz_0_xxxyyyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxyyyyz_0[i] = 6.0 * g_0_zzzzz_0_xxxyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxyyyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxxyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyyz_0[i] * pb_z + g_0_zzzzzz_0_xxxyyyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxyyyzz_0[i] = 6.0 * g_0_zzzzz_0_xxxyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xxxyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyyzz_0[i] * pb_z + g_0_zzzzzz_0_xxxyyyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxyyzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_xxxyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyyzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxyyzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxyzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_zzzzzz_0_xxxyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxyzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxyzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxxzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxxzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxxzzzzz_1[i] * fti_ab_0 + 5.0 * g_0_zzzzzz_0_xxxzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxxzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxxzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyyyyyy_0[i] = 6.0 * g_0_zzzzz_0_xxyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyyyyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxyyyyyy_0[i] * pb_z + g_0_zzzzzz_0_xxyyyyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyyyyyz_0[i] = 6.0 * g_0_zzzzz_0_xxyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyyyyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xxyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyyz_0[i] * pb_z + g_0_zzzzzz_0_xxyyyyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyyyyzz_0[i] = 6.0 * g_0_zzzzz_0_xxyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xxyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyyzz_0[i] * pb_z + g_0_zzzzzz_0_xxyyyyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyyyzzz_0[i] = 6.0 * g_0_zzzzz_0_xxyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_xxyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyyzzz_0[i] * pb_z + g_0_zzzzzz_0_xxyyyzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyyzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_zzzzzz_0_xxyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyyzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxyyzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxyzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxyzzzzz_1[i] * fti_ab_0 + 5.0 * g_0_zzzzzz_0_xxyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxyzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxyzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xxzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xxzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xxzzzzzz_1[i] * fti_ab_0 + 6.0 * g_0_zzzzzz_0_xxzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xxzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xxzzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyyyyyy_0[i] = 6.0 * g_0_zzzzz_0_xyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyyyyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_xyyyyyyy_0[i] * pb_z + g_0_zzzzzz_0_xyyyyyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyyyyyz_0[i] = 6.0 * g_0_zzzzz_0_xyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyyyyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_xyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyyz_0[i] * pb_z + g_0_zzzzzz_0_xyyyyyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyyyyzz_0[i] = 6.0 * g_0_zzzzz_0_xyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_xyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyyzz_0[i] * pb_z + g_0_zzzzzz_0_xyyyyyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyyyzzz_0[i] = 6.0 * g_0_zzzzz_0_xyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_xyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyyzzz_0[i] * pb_z + g_0_zzzzzz_0_xyyyyzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyyzzzz_0[i] = 6.0 * g_0_zzzzz_0_xyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_zzzzzz_0_xyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyyzzzz_0[i] * pb_z + g_0_zzzzzz_0_xyyyzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyyzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyyzzzzz_1[i] * fti_ab_0 + 5.0 * g_0_zzzzzz_0_xyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyyzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xyyzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xyzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xyzzzzzz_1[i] * fti_ab_0 + 6.0 * g_0_zzzzzz_0_xyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xyzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xyzzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_xzzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_xzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_xzzzzzzz_1[i] * fti_ab_0 + 7.0 * g_0_zzzzzz_0_xzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_xzzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_xzzzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyyyyyy_0[i] = 6.0 * g_0_zzzzz_0_yyyyyyyy_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyyyyyy_1[i] * fti_ab_0 + g_0_zzzzzz_0_yyyyyyyy_0[i] * pb_z + g_0_zzzzzz_0_yyyyyyyy_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyyyyyz_0[i] = 6.0 * g_0_zzzzz_0_yyyyyyyz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyyyyyz_1[i] * fti_ab_0 + g_0_zzzzzz_0_yyyyyyy_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyyyz_0[i] * pb_z + g_0_zzzzzz_0_yyyyyyyz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyyyyzz_0[i] = 6.0 * g_0_zzzzz_0_yyyyyyzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyyyyzz_1[i] * fti_ab_0 + 2.0 * g_0_zzzzzz_0_yyyyyyz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyyzz_0[i] * pb_z + g_0_zzzzzz_0_yyyyyyzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyyyzzz_0[i] = 6.0 * g_0_zzzzz_0_yyyyyzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyyyzzz_1[i] * fti_ab_0 + 3.0 * g_0_zzzzzz_0_yyyyyzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyyzzz_0[i] * pb_z + g_0_zzzzzz_0_yyyyyzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyyzzzz_0[i] = 6.0 * g_0_zzzzz_0_yyyyzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyyzzzz_1[i] * fti_ab_0 + 4.0 * g_0_zzzzzz_0_yyyyzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyyzzzz_0[i] * pb_z + g_0_zzzzzz_0_yyyyzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyyzzzzz_0[i] = 6.0 * g_0_zzzzz_0_yyyzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyyzzzzz_1[i] * fti_ab_0 + 5.0 * g_0_zzzzzz_0_yyyzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyyzzzzz_0[i] * pb_z + g_0_zzzzzz_0_yyyzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yyzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_yyzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yyzzzzzz_1[i] * fti_ab_0 + 6.0 * g_0_zzzzzz_0_yyzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yyzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_yyzzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_yzzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_yzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_yzzzzzzz_1[i] * fti_ab_0 + 7.0 * g_0_zzzzzz_0_yzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_yzzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_yzzzzzzz_1[i] * wp_z[i];

        g_0_zzzzzzz_0_zzzzzzzz_0[i] = 6.0 * g_0_zzzzz_0_zzzzzzzz_0[i] * fi_ab_0 - 6.0 * g_0_zzzzz_0_zzzzzzzz_1[i] * fti_ab_0 + 8.0 * g_0_zzzzzz_0_zzzzzzz_1[i] * fi_abcd_0 + g_0_zzzzzz_0_zzzzzzzz_0[i] * pb_z + g_0_zzzzzz_0_zzzzzzzz_1[i] * wp_z[i];
    }
}

} // erirec namespace

