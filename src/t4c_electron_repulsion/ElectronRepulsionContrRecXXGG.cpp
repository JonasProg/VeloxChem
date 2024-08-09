#include "ElectronRepulsionContrRecXXGG.hpp"

#include "TensorComponents.hpp"

namespace erirec { // erirec namespace

auto
comp_ket_hrr_electron_repulsion_xxgg(CSimdArray<double>& contr_buffer_xxgg,
                                     const CSimdArray<double>& contr_buffer_xxfg,
                                     const CSimdArray<double>& contr_buffer_xxfh,
                                     const double* cd_x,
                                     const double* cd_y,
                                     const double* cd_z,
                                     const int a_angmom,
                                     const int b_angmom) -> void
{
    const auto ndims = contr_buffer_xxgg.number_of_columns();

    const auto acomps = tensor::number_of_cartesian_components(a_angmom);

    const auto bcomps = tensor::number_of_cartesian_components(b_angmom);

    for (int i = 0; i < acomps; i++)
    {
        for (int j = 0; j < bcomps; j++)
        {
            /// Set up components of auxilary buffer : contr_buffer_xxfg

            const auto fg_off = (i * bcomps + j) * 150;

            auto g_xxx_xxxx = contr_buffer_xxfg[fg_off + 0];

            auto g_xxx_xxxy = contr_buffer_xxfg[fg_off + 1];

            auto g_xxx_xxxz = contr_buffer_xxfg[fg_off + 2];

            auto g_xxx_xxyy = contr_buffer_xxfg[fg_off + 3];

            auto g_xxx_xxyz = contr_buffer_xxfg[fg_off + 4];

            auto g_xxx_xxzz = contr_buffer_xxfg[fg_off + 5];

            auto g_xxx_xyyy = contr_buffer_xxfg[fg_off + 6];

            auto g_xxx_xyyz = contr_buffer_xxfg[fg_off + 7];

            auto g_xxx_xyzz = contr_buffer_xxfg[fg_off + 8];

            auto g_xxx_xzzz = contr_buffer_xxfg[fg_off + 9];

            auto g_xxx_yyyy = contr_buffer_xxfg[fg_off + 10];

            auto g_xxx_yyyz = contr_buffer_xxfg[fg_off + 11];

            auto g_xxx_yyzz = contr_buffer_xxfg[fg_off + 12];

            auto g_xxx_yzzz = contr_buffer_xxfg[fg_off + 13];

            auto g_xxx_zzzz = contr_buffer_xxfg[fg_off + 14];

            auto g_xxy_xxxx = contr_buffer_xxfg[fg_off + 15];

            auto g_xxy_xxxy = contr_buffer_xxfg[fg_off + 16];

            auto g_xxy_xxxz = contr_buffer_xxfg[fg_off + 17];

            auto g_xxy_xxyy = contr_buffer_xxfg[fg_off + 18];

            auto g_xxy_xxyz = contr_buffer_xxfg[fg_off + 19];

            auto g_xxy_xxzz = contr_buffer_xxfg[fg_off + 20];

            auto g_xxy_xyyy = contr_buffer_xxfg[fg_off + 21];

            auto g_xxy_xyyz = contr_buffer_xxfg[fg_off + 22];

            auto g_xxy_xyzz = contr_buffer_xxfg[fg_off + 23];

            auto g_xxy_xzzz = contr_buffer_xxfg[fg_off + 24];

            auto g_xxy_yyyy = contr_buffer_xxfg[fg_off + 25];

            auto g_xxy_yyyz = contr_buffer_xxfg[fg_off + 26];

            auto g_xxy_yyzz = contr_buffer_xxfg[fg_off + 27];

            auto g_xxy_yzzz = contr_buffer_xxfg[fg_off + 28];

            auto g_xxy_zzzz = contr_buffer_xxfg[fg_off + 29];

            auto g_xxz_xxxx = contr_buffer_xxfg[fg_off + 30];

            auto g_xxz_xxxy = contr_buffer_xxfg[fg_off + 31];

            auto g_xxz_xxxz = contr_buffer_xxfg[fg_off + 32];

            auto g_xxz_xxyy = contr_buffer_xxfg[fg_off + 33];

            auto g_xxz_xxyz = contr_buffer_xxfg[fg_off + 34];

            auto g_xxz_xxzz = contr_buffer_xxfg[fg_off + 35];

            auto g_xxz_xyyy = contr_buffer_xxfg[fg_off + 36];

            auto g_xxz_xyyz = contr_buffer_xxfg[fg_off + 37];

            auto g_xxz_xyzz = contr_buffer_xxfg[fg_off + 38];

            auto g_xxz_xzzz = contr_buffer_xxfg[fg_off + 39];

            auto g_xxz_yyyy = contr_buffer_xxfg[fg_off + 40];

            auto g_xxz_yyyz = contr_buffer_xxfg[fg_off + 41];

            auto g_xxz_yyzz = contr_buffer_xxfg[fg_off + 42];

            auto g_xxz_yzzz = contr_buffer_xxfg[fg_off + 43];

            auto g_xxz_zzzz = contr_buffer_xxfg[fg_off + 44];

            auto g_xyy_xxxx = contr_buffer_xxfg[fg_off + 45];

            auto g_xyy_xxxy = contr_buffer_xxfg[fg_off + 46];

            auto g_xyy_xxxz = contr_buffer_xxfg[fg_off + 47];

            auto g_xyy_xxyy = contr_buffer_xxfg[fg_off + 48];

            auto g_xyy_xxyz = contr_buffer_xxfg[fg_off + 49];

            auto g_xyy_xxzz = contr_buffer_xxfg[fg_off + 50];

            auto g_xyy_xyyy = contr_buffer_xxfg[fg_off + 51];

            auto g_xyy_xyyz = contr_buffer_xxfg[fg_off + 52];

            auto g_xyy_xyzz = contr_buffer_xxfg[fg_off + 53];

            auto g_xyy_xzzz = contr_buffer_xxfg[fg_off + 54];

            auto g_xyy_yyyy = contr_buffer_xxfg[fg_off + 55];

            auto g_xyy_yyyz = contr_buffer_xxfg[fg_off + 56];

            auto g_xyy_yyzz = contr_buffer_xxfg[fg_off + 57];

            auto g_xyy_yzzz = contr_buffer_xxfg[fg_off + 58];

            auto g_xyy_zzzz = contr_buffer_xxfg[fg_off + 59];

            auto g_xyz_xxxx = contr_buffer_xxfg[fg_off + 60];

            auto g_xyz_xxxy = contr_buffer_xxfg[fg_off + 61];

            auto g_xyz_xxxz = contr_buffer_xxfg[fg_off + 62];

            auto g_xyz_xxyy = contr_buffer_xxfg[fg_off + 63];

            auto g_xyz_xxyz = contr_buffer_xxfg[fg_off + 64];

            auto g_xyz_xxzz = contr_buffer_xxfg[fg_off + 65];

            auto g_xyz_xyyy = contr_buffer_xxfg[fg_off + 66];

            auto g_xyz_xyyz = contr_buffer_xxfg[fg_off + 67];

            auto g_xyz_xyzz = contr_buffer_xxfg[fg_off + 68];

            auto g_xyz_xzzz = contr_buffer_xxfg[fg_off + 69];

            auto g_xyz_yyyy = contr_buffer_xxfg[fg_off + 70];

            auto g_xyz_yyyz = contr_buffer_xxfg[fg_off + 71];

            auto g_xyz_yyzz = contr_buffer_xxfg[fg_off + 72];

            auto g_xyz_yzzz = contr_buffer_xxfg[fg_off + 73];

            auto g_xyz_zzzz = contr_buffer_xxfg[fg_off + 74];

            auto g_xzz_xxxx = contr_buffer_xxfg[fg_off + 75];

            auto g_xzz_xxxy = contr_buffer_xxfg[fg_off + 76];

            auto g_xzz_xxxz = contr_buffer_xxfg[fg_off + 77];

            auto g_xzz_xxyy = contr_buffer_xxfg[fg_off + 78];

            auto g_xzz_xxyz = contr_buffer_xxfg[fg_off + 79];

            auto g_xzz_xxzz = contr_buffer_xxfg[fg_off + 80];

            auto g_xzz_xyyy = contr_buffer_xxfg[fg_off + 81];

            auto g_xzz_xyyz = contr_buffer_xxfg[fg_off + 82];

            auto g_xzz_xyzz = contr_buffer_xxfg[fg_off + 83];

            auto g_xzz_xzzz = contr_buffer_xxfg[fg_off + 84];

            auto g_xzz_yyyy = contr_buffer_xxfg[fg_off + 85];

            auto g_xzz_yyyz = contr_buffer_xxfg[fg_off + 86];

            auto g_xzz_yyzz = contr_buffer_xxfg[fg_off + 87];

            auto g_xzz_yzzz = contr_buffer_xxfg[fg_off + 88];

            auto g_xzz_zzzz = contr_buffer_xxfg[fg_off + 89];

            auto g_yyy_xxxx = contr_buffer_xxfg[fg_off + 90];

            auto g_yyy_xxxy = contr_buffer_xxfg[fg_off + 91];

            auto g_yyy_xxxz = contr_buffer_xxfg[fg_off + 92];

            auto g_yyy_xxyy = contr_buffer_xxfg[fg_off + 93];

            auto g_yyy_xxyz = contr_buffer_xxfg[fg_off + 94];

            auto g_yyy_xxzz = contr_buffer_xxfg[fg_off + 95];

            auto g_yyy_xyyy = contr_buffer_xxfg[fg_off + 96];

            auto g_yyy_xyyz = contr_buffer_xxfg[fg_off + 97];

            auto g_yyy_xyzz = contr_buffer_xxfg[fg_off + 98];

            auto g_yyy_xzzz = contr_buffer_xxfg[fg_off + 99];

            auto g_yyy_yyyy = contr_buffer_xxfg[fg_off + 100];

            auto g_yyy_yyyz = contr_buffer_xxfg[fg_off + 101];

            auto g_yyy_yyzz = contr_buffer_xxfg[fg_off + 102];

            auto g_yyy_yzzz = contr_buffer_xxfg[fg_off + 103];

            auto g_yyy_zzzz = contr_buffer_xxfg[fg_off + 104];

            auto g_yyz_xxxx = contr_buffer_xxfg[fg_off + 105];

            auto g_yyz_xxxy = contr_buffer_xxfg[fg_off + 106];

            auto g_yyz_xxxz = contr_buffer_xxfg[fg_off + 107];

            auto g_yyz_xxyy = contr_buffer_xxfg[fg_off + 108];

            auto g_yyz_xxyz = contr_buffer_xxfg[fg_off + 109];

            auto g_yyz_xxzz = contr_buffer_xxfg[fg_off + 110];

            auto g_yyz_xyyy = contr_buffer_xxfg[fg_off + 111];

            auto g_yyz_xyyz = contr_buffer_xxfg[fg_off + 112];

            auto g_yyz_xyzz = contr_buffer_xxfg[fg_off + 113];

            auto g_yyz_xzzz = contr_buffer_xxfg[fg_off + 114];

            auto g_yyz_yyyy = contr_buffer_xxfg[fg_off + 115];

            auto g_yyz_yyyz = contr_buffer_xxfg[fg_off + 116];

            auto g_yyz_yyzz = contr_buffer_xxfg[fg_off + 117];

            auto g_yyz_yzzz = contr_buffer_xxfg[fg_off + 118];

            auto g_yyz_zzzz = contr_buffer_xxfg[fg_off + 119];

            auto g_yzz_xxxx = contr_buffer_xxfg[fg_off + 120];

            auto g_yzz_xxxy = contr_buffer_xxfg[fg_off + 121];

            auto g_yzz_xxxz = contr_buffer_xxfg[fg_off + 122];

            auto g_yzz_xxyy = contr_buffer_xxfg[fg_off + 123];

            auto g_yzz_xxyz = contr_buffer_xxfg[fg_off + 124];

            auto g_yzz_xxzz = contr_buffer_xxfg[fg_off + 125];

            auto g_yzz_xyyy = contr_buffer_xxfg[fg_off + 126];

            auto g_yzz_xyyz = contr_buffer_xxfg[fg_off + 127];

            auto g_yzz_xyzz = contr_buffer_xxfg[fg_off + 128];

            auto g_yzz_xzzz = contr_buffer_xxfg[fg_off + 129];

            auto g_yzz_yyyy = contr_buffer_xxfg[fg_off + 130];

            auto g_yzz_yyyz = contr_buffer_xxfg[fg_off + 131];

            auto g_yzz_yyzz = contr_buffer_xxfg[fg_off + 132];

            auto g_yzz_yzzz = contr_buffer_xxfg[fg_off + 133];

            auto g_yzz_zzzz = contr_buffer_xxfg[fg_off + 134];

            auto g_zzz_xxxx = contr_buffer_xxfg[fg_off + 135];

            auto g_zzz_xxxy = contr_buffer_xxfg[fg_off + 136];

            auto g_zzz_xxxz = contr_buffer_xxfg[fg_off + 137];

            auto g_zzz_xxyy = contr_buffer_xxfg[fg_off + 138];

            auto g_zzz_xxyz = contr_buffer_xxfg[fg_off + 139];

            auto g_zzz_xxzz = contr_buffer_xxfg[fg_off + 140];

            auto g_zzz_xyyy = contr_buffer_xxfg[fg_off + 141];

            auto g_zzz_xyyz = contr_buffer_xxfg[fg_off + 142];

            auto g_zzz_xyzz = contr_buffer_xxfg[fg_off + 143];

            auto g_zzz_xzzz = contr_buffer_xxfg[fg_off + 144];

            auto g_zzz_yyyy = contr_buffer_xxfg[fg_off + 145];

            auto g_zzz_yyyz = contr_buffer_xxfg[fg_off + 146];

            auto g_zzz_yyzz = contr_buffer_xxfg[fg_off + 147];

            auto g_zzz_yzzz = contr_buffer_xxfg[fg_off + 148];

            auto g_zzz_zzzz = contr_buffer_xxfg[fg_off + 149];

            /// Set up components of auxilary buffer : contr_buffer_xxfh

            const auto fh_off = (i * bcomps + j) * 210;

            auto g_xxx_xxxxx = contr_buffer_xxfh[fh_off + 0];

            auto g_xxx_xxxxy = contr_buffer_xxfh[fh_off + 1];

            auto g_xxx_xxxxz = contr_buffer_xxfh[fh_off + 2];

            auto g_xxx_xxxyy = contr_buffer_xxfh[fh_off + 3];

            auto g_xxx_xxxyz = contr_buffer_xxfh[fh_off + 4];

            auto g_xxx_xxxzz = contr_buffer_xxfh[fh_off + 5];

            auto g_xxx_xxyyy = contr_buffer_xxfh[fh_off + 6];

            auto g_xxx_xxyyz = contr_buffer_xxfh[fh_off + 7];

            auto g_xxx_xxyzz = contr_buffer_xxfh[fh_off + 8];

            auto g_xxx_xxzzz = contr_buffer_xxfh[fh_off + 9];

            auto g_xxx_xyyyy = contr_buffer_xxfh[fh_off + 10];

            auto g_xxx_xyyyz = contr_buffer_xxfh[fh_off + 11];

            auto g_xxx_xyyzz = contr_buffer_xxfh[fh_off + 12];

            auto g_xxx_xyzzz = contr_buffer_xxfh[fh_off + 13];

            auto g_xxx_xzzzz = contr_buffer_xxfh[fh_off + 14];

            auto g_xxy_xxxxx = contr_buffer_xxfh[fh_off + 21];

            auto g_xxy_xxxxy = contr_buffer_xxfh[fh_off + 22];

            auto g_xxy_xxxxz = contr_buffer_xxfh[fh_off + 23];

            auto g_xxy_xxxyy = contr_buffer_xxfh[fh_off + 24];

            auto g_xxy_xxxyz = contr_buffer_xxfh[fh_off + 25];

            auto g_xxy_xxxzz = contr_buffer_xxfh[fh_off + 26];

            auto g_xxy_xxyyy = contr_buffer_xxfh[fh_off + 27];

            auto g_xxy_xxyyz = contr_buffer_xxfh[fh_off + 28];

            auto g_xxy_xxyzz = contr_buffer_xxfh[fh_off + 29];

            auto g_xxy_xxzzz = contr_buffer_xxfh[fh_off + 30];

            auto g_xxy_xyyyy = contr_buffer_xxfh[fh_off + 31];

            auto g_xxy_xyyyz = contr_buffer_xxfh[fh_off + 32];

            auto g_xxy_xyyzz = contr_buffer_xxfh[fh_off + 33];

            auto g_xxy_xyzzz = contr_buffer_xxfh[fh_off + 34];

            auto g_xxy_xzzzz = contr_buffer_xxfh[fh_off + 35];

            auto g_xxz_xxxxx = contr_buffer_xxfh[fh_off + 42];

            auto g_xxz_xxxxy = contr_buffer_xxfh[fh_off + 43];

            auto g_xxz_xxxxz = contr_buffer_xxfh[fh_off + 44];

            auto g_xxz_xxxyy = contr_buffer_xxfh[fh_off + 45];

            auto g_xxz_xxxyz = contr_buffer_xxfh[fh_off + 46];

            auto g_xxz_xxxzz = contr_buffer_xxfh[fh_off + 47];

            auto g_xxz_xxyyy = contr_buffer_xxfh[fh_off + 48];

            auto g_xxz_xxyyz = contr_buffer_xxfh[fh_off + 49];

            auto g_xxz_xxyzz = contr_buffer_xxfh[fh_off + 50];

            auto g_xxz_xxzzz = contr_buffer_xxfh[fh_off + 51];

            auto g_xxz_xyyyy = contr_buffer_xxfh[fh_off + 52];

            auto g_xxz_xyyyz = contr_buffer_xxfh[fh_off + 53];

            auto g_xxz_xyyzz = contr_buffer_xxfh[fh_off + 54];

            auto g_xxz_xyzzz = contr_buffer_xxfh[fh_off + 55];

            auto g_xxz_xzzzz = contr_buffer_xxfh[fh_off + 56];

            auto g_xyy_xxxxx = contr_buffer_xxfh[fh_off + 63];

            auto g_xyy_xxxxy = contr_buffer_xxfh[fh_off + 64];

            auto g_xyy_xxxxz = contr_buffer_xxfh[fh_off + 65];

            auto g_xyy_xxxyy = contr_buffer_xxfh[fh_off + 66];

            auto g_xyy_xxxyz = contr_buffer_xxfh[fh_off + 67];

            auto g_xyy_xxxzz = contr_buffer_xxfh[fh_off + 68];

            auto g_xyy_xxyyy = contr_buffer_xxfh[fh_off + 69];

            auto g_xyy_xxyyz = contr_buffer_xxfh[fh_off + 70];

            auto g_xyy_xxyzz = contr_buffer_xxfh[fh_off + 71];

            auto g_xyy_xxzzz = contr_buffer_xxfh[fh_off + 72];

            auto g_xyy_xyyyy = contr_buffer_xxfh[fh_off + 73];

            auto g_xyy_xyyyz = contr_buffer_xxfh[fh_off + 74];

            auto g_xyy_xyyzz = contr_buffer_xxfh[fh_off + 75];

            auto g_xyy_xyzzz = contr_buffer_xxfh[fh_off + 76];

            auto g_xyy_xzzzz = contr_buffer_xxfh[fh_off + 77];

            auto g_xyz_xxxxx = contr_buffer_xxfh[fh_off + 84];

            auto g_xyz_xxxxy = contr_buffer_xxfh[fh_off + 85];

            auto g_xyz_xxxxz = contr_buffer_xxfh[fh_off + 86];

            auto g_xyz_xxxyy = contr_buffer_xxfh[fh_off + 87];

            auto g_xyz_xxxyz = contr_buffer_xxfh[fh_off + 88];

            auto g_xyz_xxxzz = contr_buffer_xxfh[fh_off + 89];

            auto g_xyz_xxyyy = contr_buffer_xxfh[fh_off + 90];

            auto g_xyz_xxyyz = contr_buffer_xxfh[fh_off + 91];

            auto g_xyz_xxyzz = contr_buffer_xxfh[fh_off + 92];

            auto g_xyz_xxzzz = contr_buffer_xxfh[fh_off + 93];

            auto g_xyz_xyyyy = contr_buffer_xxfh[fh_off + 94];

            auto g_xyz_xyyyz = contr_buffer_xxfh[fh_off + 95];

            auto g_xyz_xyyzz = contr_buffer_xxfh[fh_off + 96];

            auto g_xyz_xyzzz = contr_buffer_xxfh[fh_off + 97];

            auto g_xyz_xzzzz = contr_buffer_xxfh[fh_off + 98];

            auto g_xzz_xxxxx = contr_buffer_xxfh[fh_off + 105];

            auto g_xzz_xxxxy = contr_buffer_xxfh[fh_off + 106];

            auto g_xzz_xxxxz = contr_buffer_xxfh[fh_off + 107];

            auto g_xzz_xxxyy = contr_buffer_xxfh[fh_off + 108];

            auto g_xzz_xxxyz = contr_buffer_xxfh[fh_off + 109];

            auto g_xzz_xxxzz = contr_buffer_xxfh[fh_off + 110];

            auto g_xzz_xxyyy = contr_buffer_xxfh[fh_off + 111];

            auto g_xzz_xxyyz = contr_buffer_xxfh[fh_off + 112];

            auto g_xzz_xxyzz = contr_buffer_xxfh[fh_off + 113];

            auto g_xzz_xxzzz = contr_buffer_xxfh[fh_off + 114];

            auto g_xzz_xyyyy = contr_buffer_xxfh[fh_off + 115];

            auto g_xzz_xyyyz = contr_buffer_xxfh[fh_off + 116];

            auto g_xzz_xyyzz = contr_buffer_xxfh[fh_off + 117];

            auto g_xzz_xyzzz = contr_buffer_xxfh[fh_off + 118];

            auto g_xzz_xzzzz = contr_buffer_xxfh[fh_off + 119];

            auto g_yyy_xxxxx = contr_buffer_xxfh[fh_off + 126];

            auto g_yyy_xxxxy = contr_buffer_xxfh[fh_off + 127];

            auto g_yyy_xxxxz = contr_buffer_xxfh[fh_off + 128];

            auto g_yyy_xxxyy = contr_buffer_xxfh[fh_off + 129];

            auto g_yyy_xxxyz = contr_buffer_xxfh[fh_off + 130];

            auto g_yyy_xxxzz = contr_buffer_xxfh[fh_off + 131];

            auto g_yyy_xxyyy = contr_buffer_xxfh[fh_off + 132];

            auto g_yyy_xxyyz = contr_buffer_xxfh[fh_off + 133];

            auto g_yyy_xxyzz = contr_buffer_xxfh[fh_off + 134];

            auto g_yyy_xxzzz = contr_buffer_xxfh[fh_off + 135];

            auto g_yyy_xyyyy = contr_buffer_xxfh[fh_off + 136];

            auto g_yyy_xyyyz = contr_buffer_xxfh[fh_off + 137];

            auto g_yyy_xyyzz = contr_buffer_xxfh[fh_off + 138];

            auto g_yyy_xyzzz = contr_buffer_xxfh[fh_off + 139];

            auto g_yyy_xzzzz = contr_buffer_xxfh[fh_off + 140];

            auto g_yyy_yyyyy = contr_buffer_xxfh[fh_off + 141];

            auto g_yyy_yyyyz = contr_buffer_xxfh[fh_off + 142];

            auto g_yyy_yyyzz = contr_buffer_xxfh[fh_off + 143];

            auto g_yyy_yyzzz = contr_buffer_xxfh[fh_off + 144];

            auto g_yyy_yzzzz = contr_buffer_xxfh[fh_off + 145];

            auto g_yyz_xxxxx = contr_buffer_xxfh[fh_off + 147];

            auto g_yyz_xxxxy = contr_buffer_xxfh[fh_off + 148];

            auto g_yyz_xxxxz = contr_buffer_xxfh[fh_off + 149];

            auto g_yyz_xxxyy = contr_buffer_xxfh[fh_off + 150];

            auto g_yyz_xxxyz = contr_buffer_xxfh[fh_off + 151];

            auto g_yyz_xxxzz = contr_buffer_xxfh[fh_off + 152];

            auto g_yyz_xxyyy = contr_buffer_xxfh[fh_off + 153];

            auto g_yyz_xxyyz = contr_buffer_xxfh[fh_off + 154];

            auto g_yyz_xxyzz = contr_buffer_xxfh[fh_off + 155];

            auto g_yyz_xxzzz = contr_buffer_xxfh[fh_off + 156];

            auto g_yyz_xyyyy = contr_buffer_xxfh[fh_off + 157];

            auto g_yyz_xyyyz = contr_buffer_xxfh[fh_off + 158];

            auto g_yyz_xyyzz = contr_buffer_xxfh[fh_off + 159];

            auto g_yyz_xyzzz = contr_buffer_xxfh[fh_off + 160];

            auto g_yyz_xzzzz = contr_buffer_xxfh[fh_off + 161];

            auto g_yyz_yyyyy = contr_buffer_xxfh[fh_off + 162];

            auto g_yyz_yyyyz = contr_buffer_xxfh[fh_off + 163];

            auto g_yyz_yyyzz = contr_buffer_xxfh[fh_off + 164];

            auto g_yyz_yyzzz = contr_buffer_xxfh[fh_off + 165];

            auto g_yyz_yzzzz = contr_buffer_xxfh[fh_off + 166];

            auto g_yzz_xxxxx = contr_buffer_xxfh[fh_off + 168];

            auto g_yzz_xxxxy = contr_buffer_xxfh[fh_off + 169];

            auto g_yzz_xxxxz = contr_buffer_xxfh[fh_off + 170];

            auto g_yzz_xxxyy = contr_buffer_xxfh[fh_off + 171];

            auto g_yzz_xxxyz = contr_buffer_xxfh[fh_off + 172];

            auto g_yzz_xxxzz = contr_buffer_xxfh[fh_off + 173];

            auto g_yzz_xxyyy = contr_buffer_xxfh[fh_off + 174];

            auto g_yzz_xxyyz = contr_buffer_xxfh[fh_off + 175];

            auto g_yzz_xxyzz = contr_buffer_xxfh[fh_off + 176];

            auto g_yzz_xxzzz = contr_buffer_xxfh[fh_off + 177];

            auto g_yzz_xyyyy = contr_buffer_xxfh[fh_off + 178];

            auto g_yzz_xyyyz = contr_buffer_xxfh[fh_off + 179];

            auto g_yzz_xyyzz = contr_buffer_xxfh[fh_off + 180];

            auto g_yzz_xyzzz = contr_buffer_xxfh[fh_off + 181];

            auto g_yzz_xzzzz = contr_buffer_xxfh[fh_off + 182];

            auto g_yzz_yyyyy = contr_buffer_xxfh[fh_off + 183];

            auto g_yzz_yyyyz = contr_buffer_xxfh[fh_off + 184];

            auto g_yzz_yyyzz = contr_buffer_xxfh[fh_off + 185];

            auto g_yzz_yyzzz = contr_buffer_xxfh[fh_off + 186];

            auto g_yzz_yzzzz = contr_buffer_xxfh[fh_off + 187];

            auto g_zzz_xxxxx = contr_buffer_xxfh[fh_off + 189];

            auto g_zzz_xxxxy = contr_buffer_xxfh[fh_off + 190];

            auto g_zzz_xxxxz = contr_buffer_xxfh[fh_off + 191];

            auto g_zzz_xxxyy = contr_buffer_xxfh[fh_off + 192];

            auto g_zzz_xxxyz = contr_buffer_xxfh[fh_off + 193];

            auto g_zzz_xxxzz = contr_buffer_xxfh[fh_off + 194];

            auto g_zzz_xxyyy = contr_buffer_xxfh[fh_off + 195];

            auto g_zzz_xxyyz = contr_buffer_xxfh[fh_off + 196];

            auto g_zzz_xxyzz = contr_buffer_xxfh[fh_off + 197];

            auto g_zzz_xxzzz = contr_buffer_xxfh[fh_off + 198];

            auto g_zzz_xyyyy = contr_buffer_xxfh[fh_off + 199];

            auto g_zzz_xyyyz = contr_buffer_xxfh[fh_off + 200];

            auto g_zzz_xyyzz = contr_buffer_xxfh[fh_off + 201];

            auto g_zzz_xyzzz = contr_buffer_xxfh[fh_off + 202];

            auto g_zzz_xzzzz = contr_buffer_xxfh[fh_off + 203];

            auto g_zzz_yyyyy = contr_buffer_xxfh[fh_off + 204];

            auto g_zzz_yyyyz = contr_buffer_xxfh[fh_off + 205];

            auto g_zzz_yyyzz = contr_buffer_xxfh[fh_off + 206];

            auto g_zzz_yyzzz = contr_buffer_xxfh[fh_off + 207];

            auto g_zzz_yzzzz = contr_buffer_xxfh[fh_off + 208];

            auto g_zzz_zzzzz = contr_buffer_xxfh[fh_off + 209];

            /// set up bra offset for contr_buffer_xxgg

            const auto gg_off = (i * bcomps + j) * 225;

            /// Set up 0-15 components of targeted buffer : contr_buffer_xxgg

            auto g_xxxx_xxxx = contr_buffer_xxgg[gg_off + 0];

            auto g_xxxx_xxxy = contr_buffer_xxgg[gg_off + 1];

            auto g_xxxx_xxxz = contr_buffer_xxgg[gg_off + 2];

            auto g_xxxx_xxyy = contr_buffer_xxgg[gg_off + 3];

            auto g_xxxx_xxyz = contr_buffer_xxgg[gg_off + 4];

            auto g_xxxx_xxzz = contr_buffer_xxgg[gg_off + 5];

            auto g_xxxx_xyyy = contr_buffer_xxgg[gg_off + 6];

            auto g_xxxx_xyyz = contr_buffer_xxgg[gg_off + 7];

            auto g_xxxx_xyzz = contr_buffer_xxgg[gg_off + 8];

            auto g_xxxx_xzzz = contr_buffer_xxgg[gg_off + 9];

            auto g_xxxx_yyyy = contr_buffer_xxgg[gg_off + 10];

            auto g_xxxx_yyyz = contr_buffer_xxgg[gg_off + 11];

            auto g_xxxx_yyzz = contr_buffer_xxgg[gg_off + 12];

            auto g_xxxx_yzzz = contr_buffer_xxgg[gg_off + 13];

            auto g_xxxx_zzzz = contr_buffer_xxgg[gg_off + 14];

            #pragma omp simd aligned(cd_x, g_xxx_xxxx, g_xxx_xxxxx, g_xxx_xxxxy, g_xxx_xxxxz, g_xxx_xxxy, g_xxx_xxxyy, g_xxx_xxxyz, g_xxx_xxxz, g_xxx_xxxzz, g_xxx_xxyy, g_xxx_xxyyy, g_xxx_xxyyz, g_xxx_xxyz, g_xxx_xxyzz, g_xxx_xxzz, g_xxx_xxzzz, g_xxx_xyyy, g_xxx_xyyyy, g_xxx_xyyyz, g_xxx_xyyz, g_xxx_xyyzz, g_xxx_xyzz, g_xxx_xyzzz, g_xxx_xzzz, g_xxx_xzzzz, g_xxx_yyyy, g_xxx_yyyz, g_xxx_yyzz, g_xxx_yzzz, g_xxx_zzzz, g_xxxx_xxxx, g_xxxx_xxxy, g_xxxx_xxxz, g_xxxx_xxyy, g_xxxx_xxyz, g_xxxx_xxzz, g_xxxx_xyyy, g_xxxx_xyyz, g_xxxx_xyzz, g_xxxx_xzzz, g_xxxx_yyyy, g_xxxx_yyyz, g_xxxx_yyzz, g_xxxx_yzzz, g_xxxx_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxxx_xxxx[k] = -g_xxx_xxxx[k] * cd_x[k] + g_xxx_xxxxx[k];

                g_xxxx_xxxy[k] = -g_xxx_xxxy[k] * cd_x[k] + g_xxx_xxxxy[k];

                g_xxxx_xxxz[k] = -g_xxx_xxxz[k] * cd_x[k] + g_xxx_xxxxz[k];

                g_xxxx_xxyy[k] = -g_xxx_xxyy[k] * cd_x[k] + g_xxx_xxxyy[k];

                g_xxxx_xxyz[k] = -g_xxx_xxyz[k] * cd_x[k] + g_xxx_xxxyz[k];

                g_xxxx_xxzz[k] = -g_xxx_xxzz[k] * cd_x[k] + g_xxx_xxxzz[k];

                g_xxxx_xyyy[k] = -g_xxx_xyyy[k] * cd_x[k] + g_xxx_xxyyy[k];

                g_xxxx_xyyz[k] = -g_xxx_xyyz[k] * cd_x[k] + g_xxx_xxyyz[k];

                g_xxxx_xyzz[k] = -g_xxx_xyzz[k] * cd_x[k] + g_xxx_xxyzz[k];

                g_xxxx_xzzz[k] = -g_xxx_xzzz[k] * cd_x[k] + g_xxx_xxzzz[k];

                g_xxxx_yyyy[k] = -g_xxx_yyyy[k] * cd_x[k] + g_xxx_xyyyy[k];

                g_xxxx_yyyz[k] = -g_xxx_yyyz[k] * cd_x[k] + g_xxx_xyyyz[k];

                g_xxxx_yyzz[k] = -g_xxx_yyzz[k] * cd_x[k] + g_xxx_xyyzz[k];

                g_xxxx_yzzz[k] = -g_xxx_yzzz[k] * cd_x[k] + g_xxx_xyzzz[k];

                g_xxxx_zzzz[k] = -g_xxx_zzzz[k] * cd_x[k] + g_xxx_xzzzz[k];
            }

            /// Set up 15-30 components of targeted buffer : contr_buffer_xxgg

            auto g_xxxy_xxxx = contr_buffer_xxgg[gg_off + 15];

            auto g_xxxy_xxxy = contr_buffer_xxgg[gg_off + 16];

            auto g_xxxy_xxxz = contr_buffer_xxgg[gg_off + 17];

            auto g_xxxy_xxyy = contr_buffer_xxgg[gg_off + 18];

            auto g_xxxy_xxyz = contr_buffer_xxgg[gg_off + 19];

            auto g_xxxy_xxzz = contr_buffer_xxgg[gg_off + 20];

            auto g_xxxy_xyyy = contr_buffer_xxgg[gg_off + 21];

            auto g_xxxy_xyyz = contr_buffer_xxgg[gg_off + 22];

            auto g_xxxy_xyzz = contr_buffer_xxgg[gg_off + 23];

            auto g_xxxy_xzzz = contr_buffer_xxgg[gg_off + 24];

            auto g_xxxy_yyyy = contr_buffer_xxgg[gg_off + 25];

            auto g_xxxy_yyyz = contr_buffer_xxgg[gg_off + 26];

            auto g_xxxy_yyzz = contr_buffer_xxgg[gg_off + 27];

            auto g_xxxy_yzzz = contr_buffer_xxgg[gg_off + 28];

            auto g_xxxy_zzzz = contr_buffer_xxgg[gg_off + 29];

            #pragma omp simd aligned(cd_x, g_xxxy_xxxx, g_xxxy_xxxy, g_xxxy_xxxz, g_xxxy_xxyy, g_xxxy_xxyz, g_xxxy_xxzz, g_xxxy_xyyy, g_xxxy_xyyz, g_xxxy_xyzz, g_xxxy_xzzz, g_xxxy_yyyy, g_xxxy_yyyz, g_xxxy_yyzz, g_xxxy_yzzz, g_xxxy_zzzz, g_xxy_xxxx, g_xxy_xxxxx, g_xxy_xxxxy, g_xxy_xxxxz, g_xxy_xxxy, g_xxy_xxxyy, g_xxy_xxxyz, g_xxy_xxxz, g_xxy_xxxzz, g_xxy_xxyy, g_xxy_xxyyy, g_xxy_xxyyz, g_xxy_xxyz, g_xxy_xxyzz, g_xxy_xxzz, g_xxy_xxzzz, g_xxy_xyyy, g_xxy_xyyyy, g_xxy_xyyyz, g_xxy_xyyz, g_xxy_xyyzz, g_xxy_xyzz, g_xxy_xyzzz, g_xxy_xzzz, g_xxy_xzzzz, g_xxy_yyyy, g_xxy_yyyz, g_xxy_yyzz, g_xxy_yzzz, g_xxy_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxxy_xxxx[k] = -g_xxy_xxxx[k] * cd_x[k] + g_xxy_xxxxx[k];

                g_xxxy_xxxy[k] = -g_xxy_xxxy[k] * cd_x[k] + g_xxy_xxxxy[k];

                g_xxxy_xxxz[k] = -g_xxy_xxxz[k] * cd_x[k] + g_xxy_xxxxz[k];

                g_xxxy_xxyy[k] = -g_xxy_xxyy[k] * cd_x[k] + g_xxy_xxxyy[k];

                g_xxxy_xxyz[k] = -g_xxy_xxyz[k] * cd_x[k] + g_xxy_xxxyz[k];

                g_xxxy_xxzz[k] = -g_xxy_xxzz[k] * cd_x[k] + g_xxy_xxxzz[k];

                g_xxxy_xyyy[k] = -g_xxy_xyyy[k] * cd_x[k] + g_xxy_xxyyy[k];

                g_xxxy_xyyz[k] = -g_xxy_xyyz[k] * cd_x[k] + g_xxy_xxyyz[k];

                g_xxxy_xyzz[k] = -g_xxy_xyzz[k] * cd_x[k] + g_xxy_xxyzz[k];

                g_xxxy_xzzz[k] = -g_xxy_xzzz[k] * cd_x[k] + g_xxy_xxzzz[k];

                g_xxxy_yyyy[k] = -g_xxy_yyyy[k] * cd_x[k] + g_xxy_xyyyy[k];

                g_xxxy_yyyz[k] = -g_xxy_yyyz[k] * cd_x[k] + g_xxy_xyyyz[k];

                g_xxxy_yyzz[k] = -g_xxy_yyzz[k] * cd_x[k] + g_xxy_xyyzz[k];

                g_xxxy_yzzz[k] = -g_xxy_yzzz[k] * cd_x[k] + g_xxy_xyzzz[k];

                g_xxxy_zzzz[k] = -g_xxy_zzzz[k] * cd_x[k] + g_xxy_xzzzz[k];
            }

            /// Set up 30-45 components of targeted buffer : contr_buffer_xxgg

            auto g_xxxz_xxxx = contr_buffer_xxgg[gg_off + 30];

            auto g_xxxz_xxxy = contr_buffer_xxgg[gg_off + 31];

            auto g_xxxz_xxxz = contr_buffer_xxgg[gg_off + 32];

            auto g_xxxz_xxyy = contr_buffer_xxgg[gg_off + 33];

            auto g_xxxz_xxyz = contr_buffer_xxgg[gg_off + 34];

            auto g_xxxz_xxzz = contr_buffer_xxgg[gg_off + 35];

            auto g_xxxz_xyyy = contr_buffer_xxgg[gg_off + 36];

            auto g_xxxz_xyyz = contr_buffer_xxgg[gg_off + 37];

            auto g_xxxz_xyzz = contr_buffer_xxgg[gg_off + 38];

            auto g_xxxz_xzzz = contr_buffer_xxgg[gg_off + 39];

            auto g_xxxz_yyyy = contr_buffer_xxgg[gg_off + 40];

            auto g_xxxz_yyyz = contr_buffer_xxgg[gg_off + 41];

            auto g_xxxz_yyzz = contr_buffer_xxgg[gg_off + 42];

            auto g_xxxz_yzzz = contr_buffer_xxgg[gg_off + 43];

            auto g_xxxz_zzzz = contr_buffer_xxgg[gg_off + 44];

            #pragma omp simd aligned(cd_x, g_xxxz_xxxx, g_xxxz_xxxy, g_xxxz_xxxz, g_xxxz_xxyy, g_xxxz_xxyz, g_xxxz_xxzz, g_xxxz_xyyy, g_xxxz_xyyz, g_xxxz_xyzz, g_xxxz_xzzz, g_xxxz_yyyy, g_xxxz_yyyz, g_xxxz_yyzz, g_xxxz_yzzz, g_xxxz_zzzz, g_xxz_xxxx, g_xxz_xxxxx, g_xxz_xxxxy, g_xxz_xxxxz, g_xxz_xxxy, g_xxz_xxxyy, g_xxz_xxxyz, g_xxz_xxxz, g_xxz_xxxzz, g_xxz_xxyy, g_xxz_xxyyy, g_xxz_xxyyz, g_xxz_xxyz, g_xxz_xxyzz, g_xxz_xxzz, g_xxz_xxzzz, g_xxz_xyyy, g_xxz_xyyyy, g_xxz_xyyyz, g_xxz_xyyz, g_xxz_xyyzz, g_xxz_xyzz, g_xxz_xyzzz, g_xxz_xzzz, g_xxz_xzzzz, g_xxz_yyyy, g_xxz_yyyz, g_xxz_yyzz, g_xxz_yzzz, g_xxz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxxz_xxxx[k] = -g_xxz_xxxx[k] * cd_x[k] + g_xxz_xxxxx[k];

                g_xxxz_xxxy[k] = -g_xxz_xxxy[k] * cd_x[k] + g_xxz_xxxxy[k];

                g_xxxz_xxxz[k] = -g_xxz_xxxz[k] * cd_x[k] + g_xxz_xxxxz[k];

                g_xxxz_xxyy[k] = -g_xxz_xxyy[k] * cd_x[k] + g_xxz_xxxyy[k];

                g_xxxz_xxyz[k] = -g_xxz_xxyz[k] * cd_x[k] + g_xxz_xxxyz[k];

                g_xxxz_xxzz[k] = -g_xxz_xxzz[k] * cd_x[k] + g_xxz_xxxzz[k];

                g_xxxz_xyyy[k] = -g_xxz_xyyy[k] * cd_x[k] + g_xxz_xxyyy[k];

                g_xxxz_xyyz[k] = -g_xxz_xyyz[k] * cd_x[k] + g_xxz_xxyyz[k];

                g_xxxz_xyzz[k] = -g_xxz_xyzz[k] * cd_x[k] + g_xxz_xxyzz[k];

                g_xxxz_xzzz[k] = -g_xxz_xzzz[k] * cd_x[k] + g_xxz_xxzzz[k];

                g_xxxz_yyyy[k] = -g_xxz_yyyy[k] * cd_x[k] + g_xxz_xyyyy[k];

                g_xxxz_yyyz[k] = -g_xxz_yyyz[k] * cd_x[k] + g_xxz_xyyyz[k];

                g_xxxz_yyzz[k] = -g_xxz_yyzz[k] * cd_x[k] + g_xxz_xyyzz[k];

                g_xxxz_yzzz[k] = -g_xxz_yzzz[k] * cd_x[k] + g_xxz_xyzzz[k];

                g_xxxz_zzzz[k] = -g_xxz_zzzz[k] * cd_x[k] + g_xxz_xzzzz[k];
            }

            /// Set up 45-60 components of targeted buffer : contr_buffer_xxgg

            auto g_xxyy_xxxx = contr_buffer_xxgg[gg_off + 45];

            auto g_xxyy_xxxy = contr_buffer_xxgg[gg_off + 46];

            auto g_xxyy_xxxz = contr_buffer_xxgg[gg_off + 47];

            auto g_xxyy_xxyy = contr_buffer_xxgg[gg_off + 48];

            auto g_xxyy_xxyz = contr_buffer_xxgg[gg_off + 49];

            auto g_xxyy_xxzz = contr_buffer_xxgg[gg_off + 50];

            auto g_xxyy_xyyy = contr_buffer_xxgg[gg_off + 51];

            auto g_xxyy_xyyz = contr_buffer_xxgg[gg_off + 52];

            auto g_xxyy_xyzz = contr_buffer_xxgg[gg_off + 53];

            auto g_xxyy_xzzz = contr_buffer_xxgg[gg_off + 54];

            auto g_xxyy_yyyy = contr_buffer_xxgg[gg_off + 55];

            auto g_xxyy_yyyz = contr_buffer_xxgg[gg_off + 56];

            auto g_xxyy_yyzz = contr_buffer_xxgg[gg_off + 57];

            auto g_xxyy_yzzz = contr_buffer_xxgg[gg_off + 58];

            auto g_xxyy_zzzz = contr_buffer_xxgg[gg_off + 59];

            #pragma omp simd aligned(cd_x, g_xxyy_xxxx, g_xxyy_xxxy, g_xxyy_xxxz, g_xxyy_xxyy, g_xxyy_xxyz, g_xxyy_xxzz, g_xxyy_xyyy, g_xxyy_xyyz, g_xxyy_xyzz, g_xxyy_xzzz, g_xxyy_yyyy, g_xxyy_yyyz, g_xxyy_yyzz, g_xxyy_yzzz, g_xxyy_zzzz, g_xyy_xxxx, g_xyy_xxxxx, g_xyy_xxxxy, g_xyy_xxxxz, g_xyy_xxxy, g_xyy_xxxyy, g_xyy_xxxyz, g_xyy_xxxz, g_xyy_xxxzz, g_xyy_xxyy, g_xyy_xxyyy, g_xyy_xxyyz, g_xyy_xxyz, g_xyy_xxyzz, g_xyy_xxzz, g_xyy_xxzzz, g_xyy_xyyy, g_xyy_xyyyy, g_xyy_xyyyz, g_xyy_xyyz, g_xyy_xyyzz, g_xyy_xyzz, g_xyy_xyzzz, g_xyy_xzzz, g_xyy_xzzzz, g_xyy_yyyy, g_xyy_yyyz, g_xyy_yyzz, g_xyy_yzzz, g_xyy_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxyy_xxxx[k] = -g_xyy_xxxx[k] * cd_x[k] + g_xyy_xxxxx[k];

                g_xxyy_xxxy[k] = -g_xyy_xxxy[k] * cd_x[k] + g_xyy_xxxxy[k];

                g_xxyy_xxxz[k] = -g_xyy_xxxz[k] * cd_x[k] + g_xyy_xxxxz[k];

                g_xxyy_xxyy[k] = -g_xyy_xxyy[k] * cd_x[k] + g_xyy_xxxyy[k];

                g_xxyy_xxyz[k] = -g_xyy_xxyz[k] * cd_x[k] + g_xyy_xxxyz[k];

                g_xxyy_xxzz[k] = -g_xyy_xxzz[k] * cd_x[k] + g_xyy_xxxzz[k];

                g_xxyy_xyyy[k] = -g_xyy_xyyy[k] * cd_x[k] + g_xyy_xxyyy[k];

                g_xxyy_xyyz[k] = -g_xyy_xyyz[k] * cd_x[k] + g_xyy_xxyyz[k];

                g_xxyy_xyzz[k] = -g_xyy_xyzz[k] * cd_x[k] + g_xyy_xxyzz[k];

                g_xxyy_xzzz[k] = -g_xyy_xzzz[k] * cd_x[k] + g_xyy_xxzzz[k];

                g_xxyy_yyyy[k] = -g_xyy_yyyy[k] * cd_x[k] + g_xyy_xyyyy[k];

                g_xxyy_yyyz[k] = -g_xyy_yyyz[k] * cd_x[k] + g_xyy_xyyyz[k];

                g_xxyy_yyzz[k] = -g_xyy_yyzz[k] * cd_x[k] + g_xyy_xyyzz[k];

                g_xxyy_yzzz[k] = -g_xyy_yzzz[k] * cd_x[k] + g_xyy_xyzzz[k];

                g_xxyy_zzzz[k] = -g_xyy_zzzz[k] * cd_x[k] + g_xyy_xzzzz[k];
            }

            /// Set up 60-75 components of targeted buffer : contr_buffer_xxgg

            auto g_xxyz_xxxx = contr_buffer_xxgg[gg_off + 60];

            auto g_xxyz_xxxy = contr_buffer_xxgg[gg_off + 61];

            auto g_xxyz_xxxz = contr_buffer_xxgg[gg_off + 62];

            auto g_xxyz_xxyy = contr_buffer_xxgg[gg_off + 63];

            auto g_xxyz_xxyz = contr_buffer_xxgg[gg_off + 64];

            auto g_xxyz_xxzz = contr_buffer_xxgg[gg_off + 65];

            auto g_xxyz_xyyy = contr_buffer_xxgg[gg_off + 66];

            auto g_xxyz_xyyz = contr_buffer_xxgg[gg_off + 67];

            auto g_xxyz_xyzz = contr_buffer_xxgg[gg_off + 68];

            auto g_xxyz_xzzz = contr_buffer_xxgg[gg_off + 69];

            auto g_xxyz_yyyy = contr_buffer_xxgg[gg_off + 70];

            auto g_xxyz_yyyz = contr_buffer_xxgg[gg_off + 71];

            auto g_xxyz_yyzz = contr_buffer_xxgg[gg_off + 72];

            auto g_xxyz_yzzz = contr_buffer_xxgg[gg_off + 73];

            auto g_xxyz_zzzz = contr_buffer_xxgg[gg_off + 74];

            #pragma omp simd aligned(cd_x, g_xxyz_xxxx, g_xxyz_xxxy, g_xxyz_xxxz, g_xxyz_xxyy, g_xxyz_xxyz, g_xxyz_xxzz, g_xxyz_xyyy, g_xxyz_xyyz, g_xxyz_xyzz, g_xxyz_xzzz, g_xxyz_yyyy, g_xxyz_yyyz, g_xxyz_yyzz, g_xxyz_yzzz, g_xxyz_zzzz, g_xyz_xxxx, g_xyz_xxxxx, g_xyz_xxxxy, g_xyz_xxxxz, g_xyz_xxxy, g_xyz_xxxyy, g_xyz_xxxyz, g_xyz_xxxz, g_xyz_xxxzz, g_xyz_xxyy, g_xyz_xxyyy, g_xyz_xxyyz, g_xyz_xxyz, g_xyz_xxyzz, g_xyz_xxzz, g_xyz_xxzzz, g_xyz_xyyy, g_xyz_xyyyy, g_xyz_xyyyz, g_xyz_xyyz, g_xyz_xyyzz, g_xyz_xyzz, g_xyz_xyzzz, g_xyz_xzzz, g_xyz_xzzzz, g_xyz_yyyy, g_xyz_yyyz, g_xyz_yyzz, g_xyz_yzzz, g_xyz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxyz_xxxx[k] = -g_xyz_xxxx[k] * cd_x[k] + g_xyz_xxxxx[k];

                g_xxyz_xxxy[k] = -g_xyz_xxxy[k] * cd_x[k] + g_xyz_xxxxy[k];

                g_xxyz_xxxz[k] = -g_xyz_xxxz[k] * cd_x[k] + g_xyz_xxxxz[k];

                g_xxyz_xxyy[k] = -g_xyz_xxyy[k] * cd_x[k] + g_xyz_xxxyy[k];

                g_xxyz_xxyz[k] = -g_xyz_xxyz[k] * cd_x[k] + g_xyz_xxxyz[k];

                g_xxyz_xxzz[k] = -g_xyz_xxzz[k] * cd_x[k] + g_xyz_xxxzz[k];

                g_xxyz_xyyy[k] = -g_xyz_xyyy[k] * cd_x[k] + g_xyz_xxyyy[k];

                g_xxyz_xyyz[k] = -g_xyz_xyyz[k] * cd_x[k] + g_xyz_xxyyz[k];

                g_xxyz_xyzz[k] = -g_xyz_xyzz[k] * cd_x[k] + g_xyz_xxyzz[k];

                g_xxyz_xzzz[k] = -g_xyz_xzzz[k] * cd_x[k] + g_xyz_xxzzz[k];

                g_xxyz_yyyy[k] = -g_xyz_yyyy[k] * cd_x[k] + g_xyz_xyyyy[k];

                g_xxyz_yyyz[k] = -g_xyz_yyyz[k] * cd_x[k] + g_xyz_xyyyz[k];

                g_xxyz_yyzz[k] = -g_xyz_yyzz[k] * cd_x[k] + g_xyz_xyyzz[k];

                g_xxyz_yzzz[k] = -g_xyz_yzzz[k] * cd_x[k] + g_xyz_xyzzz[k];

                g_xxyz_zzzz[k] = -g_xyz_zzzz[k] * cd_x[k] + g_xyz_xzzzz[k];
            }

            /// Set up 75-90 components of targeted buffer : contr_buffer_xxgg

            auto g_xxzz_xxxx = contr_buffer_xxgg[gg_off + 75];

            auto g_xxzz_xxxy = contr_buffer_xxgg[gg_off + 76];

            auto g_xxzz_xxxz = contr_buffer_xxgg[gg_off + 77];

            auto g_xxzz_xxyy = contr_buffer_xxgg[gg_off + 78];

            auto g_xxzz_xxyz = contr_buffer_xxgg[gg_off + 79];

            auto g_xxzz_xxzz = contr_buffer_xxgg[gg_off + 80];

            auto g_xxzz_xyyy = contr_buffer_xxgg[gg_off + 81];

            auto g_xxzz_xyyz = contr_buffer_xxgg[gg_off + 82];

            auto g_xxzz_xyzz = contr_buffer_xxgg[gg_off + 83];

            auto g_xxzz_xzzz = contr_buffer_xxgg[gg_off + 84];

            auto g_xxzz_yyyy = contr_buffer_xxgg[gg_off + 85];

            auto g_xxzz_yyyz = contr_buffer_xxgg[gg_off + 86];

            auto g_xxzz_yyzz = contr_buffer_xxgg[gg_off + 87];

            auto g_xxzz_yzzz = contr_buffer_xxgg[gg_off + 88];

            auto g_xxzz_zzzz = contr_buffer_xxgg[gg_off + 89];

            #pragma omp simd aligned(cd_x, g_xxzz_xxxx, g_xxzz_xxxy, g_xxzz_xxxz, g_xxzz_xxyy, g_xxzz_xxyz, g_xxzz_xxzz, g_xxzz_xyyy, g_xxzz_xyyz, g_xxzz_xyzz, g_xxzz_xzzz, g_xxzz_yyyy, g_xxzz_yyyz, g_xxzz_yyzz, g_xxzz_yzzz, g_xxzz_zzzz, g_xzz_xxxx, g_xzz_xxxxx, g_xzz_xxxxy, g_xzz_xxxxz, g_xzz_xxxy, g_xzz_xxxyy, g_xzz_xxxyz, g_xzz_xxxz, g_xzz_xxxzz, g_xzz_xxyy, g_xzz_xxyyy, g_xzz_xxyyz, g_xzz_xxyz, g_xzz_xxyzz, g_xzz_xxzz, g_xzz_xxzzz, g_xzz_xyyy, g_xzz_xyyyy, g_xzz_xyyyz, g_xzz_xyyz, g_xzz_xyyzz, g_xzz_xyzz, g_xzz_xyzzz, g_xzz_xzzz, g_xzz_xzzzz, g_xzz_yyyy, g_xzz_yyyz, g_xzz_yyzz, g_xzz_yzzz, g_xzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xxzz_xxxx[k] = -g_xzz_xxxx[k] * cd_x[k] + g_xzz_xxxxx[k];

                g_xxzz_xxxy[k] = -g_xzz_xxxy[k] * cd_x[k] + g_xzz_xxxxy[k];

                g_xxzz_xxxz[k] = -g_xzz_xxxz[k] * cd_x[k] + g_xzz_xxxxz[k];

                g_xxzz_xxyy[k] = -g_xzz_xxyy[k] * cd_x[k] + g_xzz_xxxyy[k];

                g_xxzz_xxyz[k] = -g_xzz_xxyz[k] * cd_x[k] + g_xzz_xxxyz[k];

                g_xxzz_xxzz[k] = -g_xzz_xxzz[k] * cd_x[k] + g_xzz_xxxzz[k];

                g_xxzz_xyyy[k] = -g_xzz_xyyy[k] * cd_x[k] + g_xzz_xxyyy[k];

                g_xxzz_xyyz[k] = -g_xzz_xyyz[k] * cd_x[k] + g_xzz_xxyyz[k];

                g_xxzz_xyzz[k] = -g_xzz_xyzz[k] * cd_x[k] + g_xzz_xxyzz[k];

                g_xxzz_xzzz[k] = -g_xzz_xzzz[k] * cd_x[k] + g_xzz_xxzzz[k];

                g_xxzz_yyyy[k] = -g_xzz_yyyy[k] * cd_x[k] + g_xzz_xyyyy[k];

                g_xxzz_yyyz[k] = -g_xzz_yyyz[k] * cd_x[k] + g_xzz_xyyyz[k];

                g_xxzz_yyzz[k] = -g_xzz_yyzz[k] * cd_x[k] + g_xzz_xyyzz[k];

                g_xxzz_yzzz[k] = -g_xzz_yzzz[k] * cd_x[k] + g_xzz_xyzzz[k];

                g_xxzz_zzzz[k] = -g_xzz_zzzz[k] * cd_x[k] + g_xzz_xzzzz[k];
            }

            /// Set up 90-105 components of targeted buffer : contr_buffer_xxgg

            auto g_xyyy_xxxx = contr_buffer_xxgg[gg_off + 90];

            auto g_xyyy_xxxy = contr_buffer_xxgg[gg_off + 91];

            auto g_xyyy_xxxz = contr_buffer_xxgg[gg_off + 92];

            auto g_xyyy_xxyy = contr_buffer_xxgg[gg_off + 93];

            auto g_xyyy_xxyz = contr_buffer_xxgg[gg_off + 94];

            auto g_xyyy_xxzz = contr_buffer_xxgg[gg_off + 95];

            auto g_xyyy_xyyy = contr_buffer_xxgg[gg_off + 96];

            auto g_xyyy_xyyz = contr_buffer_xxgg[gg_off + 97];

            auto g_xyyy_xyzz = contr_buffer_xxgg[gg_off + 98];

            auto g_xyyy_xzzz = contr_buffer_xxgg[gg_off + 99];

            auto g_xyyy_yyyy = contr_buffer_xxgg[gg_off + 100];

            auto g_xyyy_yyyz = contr_buffer_xxgg[gg_off + 101];

            auto g_xyyy_yyzz = contr_buffer_xxgg[gg_off + 102];

            auto g_xyyy_yzzz = contr_buffer_xxgg[gg_off + 103];

            auto g_xyyy_zzzz = contr_buffer_xxgg[gg_off + 104];

            #pragma omp simd aligned(cd_x, g_xyyy_xxxx, g_xyyy_xxxy, g_xyyy_xxxz, g_xyyy_xxyy, g_xyyy_xxyz, g_xyyy_xxzz, g_xyyy_xyyy, g_xyyy_xyyz, g_xyyy_xyzz, g_xyyy_xzzz, g_xyyy_yyyy, g_xyyy_yyyz, g_xyyy_yyzz, g_xyyy_yzzz, g_xyyy_zzzz, g_yyy_xxxx, g_yyy_xxxxx, g_yyy_xxxxy, g_yyy_xxxxz, g_yyy_xxxy, g_yyy_xxxyy, g_yyy_xxxyz, g_yyy_xxxz, g_yyy_xxxzz, g_yyy_xxyy, g_yyy_xxyyy, g_yyy_xxyyz, g_yyy_xxyz, g_yyy_xxyzz, g_yyy_xxzz, g_yyy_xxzzz, g_yyy_xyyy, g_yyy_xyyyy, g_yyy_xyyyz, g_yyy_xyyz, g_yyy_xyyzz, g_yyy_xyzz, g_yyy_xyzzz, g_yyy_xzzz, g_yyy_xzzzz, g_yyy_yyyy, g_yyy_yyyz, g_yyy_yyzz, g_yyy_yzzz, g_yyy_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xyyy_xxxx[k] = -g_yyy_xxxx[k] * cd_x[k] + g_yyy_xxxxx[k];

                g_xyyy_xxxy[k] = -g_yyy_xxxy[k] * cd_x[k] + g_yyy_xxxxy[k];

                g_xyyy_xxxz[k] = -g_yyy_xxxz[k] * cd_x[k] + g_yyy_xxxxz[k];

                g_xyyy_xxyy[k] = -g_yyy_xxyy[k] * cd_x[k] + g_yyy_xxxyy[k];

                g_xyyy_xxyz[k] = -g_yyy_xxyz[k] * cd_x[k] + g_yyy_xxxyz[k];

                g_xyyy_xxzz[k] = -g_yyy_xxzz[k] * cd_x[k] + g_yyy_xxxzz[k];

                g_xyyy_xyyy[k] = -g_yyy_xyyy[k] * cd_x[k] + g_yyy_xxyyy[k];

                g_xyyy_xyyz[k] = -g_yyy_xyyz[k] * cd_x[k] + g_yyy_xxyyz[k];

                g_xyyy_xyzz[k] = -g_yyy_xyzz[k] * cd_x[k] + g_yyy_xxyzz[k];

                g_xyyy_xzzz[k] = -g_yyy_xzzz[k] * cd_x[k] + g_yyy_xxzzz[k];

                g_xyyy_yyyy[k] = -g_yyy_yyyy[k] * cd_x[k] + g_yyy_xyyyy[k];

                g_xyyy_yyyz[k] = -g_yyy_yyyz[k] * cd_x[k] + g_yyy_xyyyz[k];

                g_xyyy_yyzz[k] = -g_yyy_yyzz[k] * cd_x[k] + g_yyy_xyyzz[k];

                g_xyyy_yzzz[k] = -g_yyy_yzzz[k] * cd_x[k] + g_yyy_xyzzz[k];

                g_xyyy_zzzz[k] = -g_yyy_zzzz[k] * cd_x[k] + g_yyy_xzzzz[k];
            }

            /// Set up 105-120 components of targeted buffer : contr_buffer_xxgg

            auto g_xyyz_xxxx = contr_buffer_xxgg[gg_off + 105];

            auto g_xyyz_xxxy = contr_buffer_xxgg[gg_off + 106];

            auto g_xyyz_xxxz = contr_buffer_xxgg[gg_off + 107];

            auto g_xyyz_xxyy = contr_buffer_xxgg[gg_off + 108];

            auto g_xyyz_xxyz = contr_buffer_xxgg[gg_off + 109];

            auto g_xyyz_xxzz = contr_buffer_xxgg[gg_off + 110];

            auto g_xyyz_xyyy = contr_buffer_xxgg[gg_off + 111];

            auto g_xyyz_xyyz = contr_buffer_xxgg[gg_off + 112];

            auto g_xyyz_xyzz = contr_buffer_xxgg[gg_off + 113];

            auto g_xyyz_xzzz = contr_buffer_xxgg[gg_off + 114];

            auto g_xyyz_yyyy = contr_buffer_xxgg[gg_off + 115];

            auto g_xyyz_yyyz = contr_buffer_xxgg[gg_off + 116];

            auto g_xyyz_yyzz = contr_buffer_xxgg[gg_off + 117];

            auto g_xyyz_yzzz = contr_buffer_xxgg[gg_off + 118];

            auto g_xyyz_zzzz = contr_buffer_xxgg[gg_off + 119];

            #pragma omp simd aligned(cd_x, g_xyyz_xxxx, g_xyyz_xxxy, g_xyyz_xxxz, g_xyyz_xxyy, g_xyyz_xxyz, g_xyyz_xxzz, g_xyyz_xyyy, g_xyyz_xyyz, g_xyyz_xyzz, g_xyyz_xzzz, g_xyyz_yyyy, g_xyyz_yyyz, g_xyyz_yyzz, g_xyyz_yzzz, g_xyyz_zzzz, g_yyz_xxxx, g_yyz_xxxxx, g_yyz_xxxxy, g_yyz_xxxxz, g_yyz_xxxy, g_yyz_xxxyy, g_yyz_xxxyz, g_yyz_xxxz, g_yyz_xxxzz, g_yyz_xxyy, g_yyz_xxyyy, g_yyz_xxyyz, g_yyz_xxyz, g_yyz_xxyzz, g_yyz_xxzz, g_yyz_xxzzz, g_yyz_xyyy, g_yyz_xyyyy, g_yyz_xyyyz, g_yyz_xyyz, g_yyz_xyyzz, g_yyz_xyzz, g_yyz_xyzzz, g_yyz_xzzz, g_yyz_xzzzz, g_yyz_yyyy, g_yyz_yyyz, g_yyz_yyzz, g_yyz_yzzz, g_yyz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xyyz_xxxx[k] = -g_yyz_xxxx[k] * cd_x[k] + g_yyz_xxxxx[k];

                g_xyyz_xxxy[k] = -g_yyz_xxxy[k] * cd_x[k] + g_yyz_xxxxy[k];

                g_xyyz_xxxz[k] = -g_yyz_xxxz[k] * cd_x[k] + g_yyz_xxxxz[k];

                g_xyyz_xxyy[k] = -g_yyz_xxyy[k] * cd_x[k] + g_yyz_xxxyy[k];

                g_xyyz_xxyz[k] = -g_yyz_xxyz[k] * cd_x[k] + g_yyz_xxxyz[k];

                g_xyyz_xxzz[k] = -g_yyz_xxzz[k] * cd_x[k] + g_yyz_xxxzz[k];

                g_xyyz_xyyy[k] = -g_yyz_xyyy[k] * cd_x[k] + g_yyz_xxyyy[k];

                g_xyyz_xyyz[k] = -g_yyz_xyyz[k] * cd_x[k] + g_yyz_xxyyz[k];

                g_xyyz_xyzz[k] = -g_yyz_xyzz[k] * cd_x[k] + g_yyz_xxyzz[k];

                g_xyyz_xzzz[k] = -g_yyz_xzzz[k] * cd_x[k] + g_yyz_xxzzz[k];

                g_xyyz_yyyy[k] = -g_yyz_yyyy[k] * cd_x[k] + g_yyz_xyyyy[k];

                g_xyyz_yyyz[k] = -g_yyz_yyyz[k] * cd_x[k] + g_yyz_xyyyz[k];

                g_xyyz_yyzz[k] = -g_yyz_yyzz[k] * cd_x[k] + g_yyz_xyyzz[k];

                g_xyyz_yzzz[k] = -g_yyz_yzzz[k] * cd_x[k] + g_yyz_xyzzz[k];

                g_xyyz_zzzz[k] = -g_yyz_zzzz[k] * cd_x[k] + g_yyz_xzzzz[k];
            }

            /// Set up 120-135 components of targeted buffer : contr_buffer_xxgg

            auto g_xyzz_xxxx = contr_buffer_xxgg[gg_off + 120];

            auto g_xyzz_xxxy = contr_buffer_xxgg[gg_off + 121];

            auto g_xyzz_xxxz = contr_buffer_xxgg[gg_off + 122];

            auto g_xyzz_xxyy = contr_buffer_xxgg[gg_off + 123];

            auto g_xyzz_xxyz = contr_buffer_xxgg[gg_off + 124];

            auto g_xyzz_xxzz = contr_buffer_xxgg[gg_off + 125];

            auto g_xyzz_xyyy = contr_buffer_xxgg[gg_off + 126];

            auto g_xyzz_xyyz = contr_buffer_xxgg[gg_off + 127];

            auto g_xyzz_xyzz = contr_buffer_xxgg[gg_off + 128];

            auto g_xyzz_xzzz = contr_buffer_xxgg[gg_off + 129];

            auto g_xyzz_yyyy = contr_buffer_xxgg[gg_off + 130];

            auto g_xyzz_yyyz = contr_buffer_xxgg[gg_off + 131];

            auto g_xyzz_yyzz = contr_buffer_xxgg[gg_off + 132];

            auto g_xyzz_yzzz = contr_buffer_xxgg[gg_off + 133];

            auto g_xyzz_zzzz = contr_buffer_xxgg[gg_off + 134];

            #pragma omp simd aligned(cd_x, g_xyzz_xxxx, g_xyzz_xxxy, g_xyzz_xxxz, g_xyzz_xxyy, g_xyzz_xxyz, g_xyzz_xxzz, g_xyzz_xyyy, g_xyzz_xyyz, g_xyzz_xyzz, g_xyzz_xzzz, g_xyzz_yyyy, g_xyzz_yyyz, g_xyzz_yyzz, g_xyzz_yzzz, g_xyzz_zzzz, g_yzz_xxxx, g_yzz_xxxxx, g_yzz_xxxxy, g_yzz_xxxxz, g_yzz_xxxy, g_yzz_xxxyy, g_yzz_xxxyz, g_yzz_xxxz, g_yzz_xxxzz, g_yzz_xxyy, g_yzz_xxyyy, g_yzz_xxyyz, g_yzz_xxyz, g_yzz_xxyzz, g_yzz_xxzz, g_yzz_xxzzz, g_yzz_xyyy, g_yzz_xyyyy, g_yzz_xyyyz, g_yzz_xyyz, g_yzz_xyyzz, g_yzz_xyzz, g_yzz_xyzzz, g_yzz_xzzz, g_yzz_xzzzz, g_yzz_yyyy, g_yzz_yyyz, g_yzz_yyzz, g_yzz_yzzz, g_yzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xyzz_xxxx[k] = -g_yzz_xxxx[k] * cd_x[k] + g_yzz_xxxxx[k];

                g_xyzz_xxxy[k] = -g_yzz_xxxy[k] * cd_x[k] + g_yzz_xxxxy[k];

                g_xyzz_xxxz[k] = -g_yzz_xxxz[k] * cd_x[k] + g_yzz_xxxxz[k];

                g_xyzz_xxyy[k] = -g_yzz_xxyy[k] * cd_x[k] + g_yzz_xxxyy[k];

                g_xyzz_xxyz[k] = -g_yzz_xxyz[k] * cd_x[k] + g_yzz_xxxyz[k];

                g_xyzz_xxzz[k] = -g_yzz_xxzz[k] * cd_x[k] + g_yzz_xxxzz[k];

                g_xyzz_xyyy[k] = -g_yzz_xyyy[k] * cd_x[k] + g_yzz_xxyyy[k];

                g_xyzz_xyyz[k] = -g_yzz_xyyz[k] * cd_x[k] + g_yzz_xxyyz[k];

                g_xyzz_xyzz[k] = -g_yzz_xyzz[k] * cd_x[k] + g_yzz_xxyzz[k];

                g_xyzz_xzzz[k] = -g_yzz_xzzz[k] * cd_x[k] + g_yzz_xxzzz[k];

                g_xyzz_yyyy[k] = -g_yzz_yyyy[k] * cd_x[k] + g_yzz_xyyyy[k];

                g_xyzz_yyyz[k] = -g_yzz_yyyz[k] * cd_x[k] + g_yzz_xyyyz[k];

                g_xyzz_yyzz[k] = -g_yzz_yyzz[k] * cd_x[k] + g_yzz_xyyzz[k];

                g_xyzz_yzzz[k] = -g_yzz_yzzz[k] * cd_x[k] + g_yzz_xyzzz[k];

                g_xyzz_zzzz[k] = -g_yzz_zzzz[k] * cd_x[k] + g_yzz_xzzzz[k];
            }

            /// Set up 135-150 components of targeted buffer : contr_buffer_xxgg

            auto g_xzzz_xxxx = contr_buffer_xxgg[gg_off + 135];

            auto g_xzzz_xxxy = contr_buffer_xxgg[gg_off + 136];

            auto g_xzzz_xxxz = contr_buffer_xxgg[gg_off + 137];

            auto g_xzzz_xxyy = contr_buffer_xxgg[gg_off + 138];

            auto g_xzzz_xxyz = contr_buffer_xxgg[gg_off + 139];

            auto g_xzzz_xxzz = contr_buffer_xxgg[gg_off + 140];

            auto g_xzzz_xyyy = contr_buffer_xxgg[gg_off + 141];

            auto g_xzzz_xyyz = contr_buffer_xxgg[gg_off + 142];

            auto g_xzzz_xyzz = contr_buffer_xxgg[gg_off + 143];

            auto g_xzzz_xzzz = contr_buffer_xxgg[gg_off + 144];

            auto g_xzzz_yyyy = contr_buffer_xxgg[gg_off + 145];

            auto g_xzzz_yyyz = contr_buffer_xxgg[gg_off + 146];

            auto g_xzzz_yyzz = contr_buffer_xxgg[gg_off + 147];

            auto g_xzzz_yzzz = contr_buffer_xxgg[gg_off + 148];

            auto g_xzzz_zzzz = contr_buffer_xxgg[gg_off + 149];

            #pragma omp simd aligned(cd_x, g_xzzz_xxxx, g_xzzz_xxxy, g_xzzz_xxxz, g_xzzz_xxyy, g_xzzz_xxyz, g_xzzz_xxzz, g_xzzz_xyyy, g_xzzz_xyyz, g_xzzz_xyzz, g_xzzz_xzzz, g_xzzz_yyyy, g_xzzz_yyyz, g_xzzz_yyzz, g_xzzz_yzzz, g_xzzz_zzzz, g_zzz_xxxx, g_zzz_xxxxx, g_zzz_xxxxy, g_zzz_xxxxz, g_zzz_xxxy, g_zzz_xxxyy, g_zzz_xxxyz, g_zzz_xxxz, g_zzz_xxxzz, g_zzz_xxyy, g_zzz_xxyyy, g_zzz_xxyyz, g_zzz_xxyz, g_zzz_xxyzz, g_zzz_xxzz, g_zzz_xxzzz, g_zzz_xyyy, g_zzz_xyyyy, g_zzz_xyyyz, g_zzz_xyyz, g_zzz_xyyzz, g_zzz_xyzz, g_zzz_xyzzz, g_zzz_xzzz, g_zzz_xzzzz, g_zzz_yyyy, g_zzz_yyyz, g_zzz_yyzz, g_zzz_yzzz, g_zzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_xzzz_xxxx[k] = -g_zzz_xxxx[k] * cd_x[k] + g_zzz_xxxxx[k];

                g_xzzz_xxxy[k] = -g_zzz_xxxy[k] * cd_x[k] + g_zzz_xxxxy[k];

                g_xzzz_xxxz[k] = -g_zzz_xxxz[k] * cd_x[k] + g_zzz_xxxxz[k];

                g_xzzz_xxyy[k] = -g_zzz_xxyy[k] * cd_x[k] + g_zzz_xxxyy[k];

                g_xzzz_xxyz[k] = -g_zzz_xxyz[k] * cd_x[k] + g_zzz_xxxyz[k];

                g_xzzz_xxzz[k] = -g_zzz_xxzz[k] * cd_x[k] + g_zzz_xxxzz[k];

                g_xzzz_xyyy[k] = -g_zzz_xyyy[k] * cd_x[k] + g_zzz_xxyyy[k];

                g_xzzz_xyyz[k] = -g_zzz_xyyz[k] * cd_x[k] + g_zzz_xxyyz[k];

                g_xzzz_xyzz[k] = -g_zzz_xyzz[k] * cd_x[k] + g_zzz_xxyzz[k];

                g_xzzz_xzzz[k] = -g_zzz_xzzz[k] * cd_x[k] + g_zzz_xxzzz[k];

                g_xzzz_yyyy[k] = -g_zzz_yyyy[k] * cd_x[k] + g_zzz_xyyyy[k];

                g_xzzz_yyyz[k] = -g_zzz_yyyz[k] * cd_x[k] + g_zzz_xyyyz[k];

                g_xzzz_yyzz[k] = -g_zzz_yyzz[k] * cd_x[k] + g_zzz_xyyzz[k];

                g_xzzz_yzzz[k] = -g_zzz_yzzz[k] * cd_x[k] + g_zzz_xyzzz[k];

                g_xzzz_zzzz[k] = -g_zzz_zzzz[k] * cd_x[k] + g_zzz_xzzzz[k];
            }

            /// Set up 150-165 components of targeted buffer : contr_buffer_xxgg

            auto g_yyyy_xxxx = contr_buffer_xxgg[gg_off + 150];

            auto g_yyyy_xxxy = contr_buffer_xxgg[gg_off + 151];

            auto g_yyyy_xxxz = contr_buffer_xxgg[gg_off + 152];

            auto g_yyyy_xxyy = contr_buffer_xxgg[gg_off + 153];

            auto g_yyyy_xxyz = contr_buffer_xxgg[gg_off + 154];

            auto g_yyyy_xxzz = contr_buffer_xxgg[gg_off + 155];

            auto g_yyyy_xyyy = contr_buffer_xxgg[gg_off + 156];

            auto g_yyyy_xyyz = contr_buffer_xxgg[gg_off + 157];

            auto g_yyyy_xyzz = contr_buffer_xxgg[gg_off + 158];

            auto g_yyyy_xzzz = contr_buffer_xxgg[gg_off + 159];

            auto g_yyyy_yyyy = contr_buffer_xxgg[gg_off + 160];

            auto g_yyyy_yyyz = contr_buffer_xxgg[gg_off + 161];

            auto g_yyyy_yyzz = contr_buffer_xxgg[gg_off + 162];

            auto g_yyyy_yzzz = contr_buffer_xxgg[gg_off + 163];

            auto g_yyyy_zzzz = contr_buffer_xxgg[gg_off + 164];

            #pragma omp simd aligned(cd_y, g_yyy_xxxx, g_yyy_xxxxy, g_yyy_xxxy, g_yyy_xxxyy, g_yyy_xxxyz, g_yyy_xxxz, g_yyy_xxyy, g_yyy_xxyyy, g_yyy_xxyyz, g_yyy_xxyz, g_yyy_xxyzz, g_yyy_xxzz, g_yyy_xyyy, g_yyy_xyyyy, g_yyy_xyyyz, g_yyy_xyyz, g_yyy_xyyzz, g_yyy_xyzz, g_yyy_xyzzz, g_yyy_xzzz, g_yyy_yyyy, g_yyy_yyyyy, g_yyy_yyyyz, g_yyy_yyyz, g_yyy_yyyzz, g_yyy_yyzz, g_yyy_yyzzz, g_yyy_yzzz, g_yyy_yzzzz, g_yyy_zzzz, g_yyyy_xxxx, g_yyyy_xxxy, g_yyyy_xxxz, g_yyyy_xxyy, g_yyyy_xxyz, g_yyyy_xxzz, g_yyyy_xyyy, g_yyyy_xyyz, g_yyyy_xyzz, g_yyyy_xzzz, g_yyyy_yyyy, g_yyyy_yyyz, g_yyyy_yyzz, g_yyyy_yzzz, g_yyyy_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_yyyy_xxxx[k] = -g_yyy_xxxx[k] * cd_y[k] + g_yyy_xxxxy[k];

                g_yyyy_xxxy[k] = -g_yyy_xxxy[k] * cd_y[k] + g_yyy_xxxyy[k];

                g_yyyy_xxxz[k] = -g_yyy_xxxz[k] * cd_y[k] + g_yyy_xxxyz[k];

                g_yyyy_xxyy[k] = -g_yyy_xxyy[k] * cd_y[k] + g_yyy_xxyyy[k];

                g_yyyy_xxyz[k] = -g_yyy_xxyz[k] * cd_y[k] + g_yyy_xxyyz[k];

                g_yyyy_xxzz[k] = -g_yyy_xxzz[k] * cd_y[k] + g_yyy_xxyzz[k];

                g_yyyy_xyyy[k] = -g_yyy_xyyy[k] * cd_y[k] + g_yyy_xyyyy[k];

                g_yyyy_xyyz[k] = -g_yyy_xyyz[k] * cd_y[k] + g_yyy_xyyyz[k];

                g_yyyy_xyzz[k] = -g_yyy_xyzz[k] * cd_y[k] + g_yyy_xyyzz[k];

                g_yyyy_xzzz[k] = -g_yyy_xzzz[k] * cd_y[k] + g_yyy_xyzzz[k];

                g_yyyy_yyyy[k] = -g_yyy_yyyy[k] * cd_y[k] + g_yyy_yyyyy[k];

                g_yyyy_yyyz[k] = -g_yyy_yyyz[k] * cd_y[k] + g_yyy_yyyyz[k];

                g_yyyy_yyzz[k] = -g_yyy_yyzz[k] * cd_y[k] + g_yyy_yyyzz[k];

                g_yyyy_yzzz[k] = -g_yyy_yzzz[k] * cd_y[k] + g_yyy_yyzzz[k];

                g_yyyy_zzzz[k] = -g_yyy_zzzz[k] * cd_y[k] + g_yyy_yzzzz[k];
            }

            /// Set up 165-180 components of targeted buffer : contr_buffer_xxgg

            auto g_yyyz_xxxx = contr_buffer_xxgg[gg_off + 165];

            auto g_yyyz_xxxy = contr_buffer_xxgg[gg_off + 166];

            auto g_yyyz_xxxz = contr_buffer_xxgg[gg_off + 167];

            auto g_yyyz_xxyy = contr_buffer_xxgg[gg_off + 168];

            auto g_yyyz_xxyz = contr_buffer_xxgg[gg_off + 169];

            auto g_yyyz_xxzz = contr_buffer_xxgg[gg_off + 170];

            auto g_yyyz_xyyy = contr_buffer_xxgg[gg_off + 171];

            auto g_yyyz_xyyz = contr_buffer_xxgg[gg_off + 172];

            auto g_yyyz_xyzz = contr_buffer_xxgg[gg_off + 173];

            auto g_yyyz_xzzz = contr_buffer_xxgg[gg_off + 174];

            auto g_yyyz_yyyy = contr_buffer_xxgg[gg_off + 175];

            auto g_yyyz_yyyz = contr_buffer_xxgg[gg_off + 176];

            auto g_yyyz_yyzz = contr_buffer_xxgg[gg_off + 177];

            auto g_yyyz_yzzz = contr_buffer_xxgg[gg_off + 178];

            auto g_yyyz_zzzz = contr_buffer_xxgg[gg_off + 179];

            #pragma omp simd aligned(cd_y, g_yyyz_xxxx, g_yyyz_xxxy, g_yyyz_xxxz, g_yyyz_xxyy, g_yyyz_xxyz, g_yyyz_xxzz, g_yyyz_xyyy, g_yyyz_xyyz, g_yyyz_xyzz, g_yyyz_xzzz, g_yyyz_yyyy, g_yyyz_yyyz, g_yyyz_yyzz, g_yyyz_yzzz, g_yyyz_zzzz, g_yyz_xxxx, g_yyz_xxxxy, g_yyz_xxxy, g_yyz_xxxyy, g_yyz_xxxyz, g_yyz_xxxz, g_yyz_xxyy, g_yyz_xxyyy, g_yyz_xxyyz, g_yyz_xxyz, g_yyz_xxyzz, g_yyz_xxzz, g_yyz_xyyy, g_yyz_xyyyy, g_yyz_xyyyz, g_yyz_xyyz, g_yyz_xyyzz, g_yyz_xyzz, g_yyz_xyzzz, g_yyz_xzzz, g_yyz_yyyy, g_yyz_yyyyy, g_yyz_yyyyz, g_yyz_yyyz, g_yyz_yyyzz, g_yyz_yyzz, g_yyz_yyzzz, g_yyz_yzzz, g_yyz_yzzzz, g_yyz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_yyyz_xxxx[k] = -g_yyz_xxxx[k] * cd_y[k] + g_yyz_xxxxy[k];

                g_yyyz_xxxy[k] = -g_yyz_xxxy[k] * cd_y[k] + g_yyz_xxxyy[k];

                g_yyyz_xxxz[k] = -g_yyz_xxxz[k] * cd_y[k] + g_yyz_xxxyz[k];

                g_yyyz_xxyy[k] = -g_yyz_xxyy[k] * cd_y[k] + g_yyz_xxyyy[k];

                g_yyyz_xxyz[k] = -g_yyz_xxyz[k] * cd_y[k] + g_yyz_xxyyz[k];

                g_yyyz_xxzz[k] = -g_yyz_xxzz[k] * cd_y[k] + g_yyz_xxyzz[k];

                g_yyyz_xyyy[k] = -g_yyz_xyyy[k] * cd_y[k] + g_yyz_xyyyy[k];

                g_yyyz_xyyz[k] = -g_yyz_xyyz[k] * cd_y[k] + g_yyz_xyyyz[k];

                g_yyyz_xyzz[k] = -g_yyz_xyzz[k] * cd_y[k] + g_yyz_xyyzz[k];

                g_yyyz_xzzz[k] = -g_yyz_xzzz[k] * cd_y[k] + g_yyz_xyzzz[k];

                g_yyyz_yyyy[k] = -g_yyz_yyyy[k] * cd_y[k] + g_yyz_yyyyy[k];

                g_yyyz_yyyz[k] = -g_yyz_yyyz[k] * cd_y[k] + g_yyz_yyyyz[k];

                g_yyyz_yyzz[k] = -g_yyz_yyzz[k] * cd_y[k] + g_yyz_yyyzz[k];

                g_yyyz_yzzz[k] = -g_yyz_yzzz[k] * cd_y[k] + g_yyz_yyzzz[k];

                g_yyyz_zzzz[k] = -g_yyz_zzzz[k] * cd_y[k] + g_yyz_yzzzz[k];
            }

            /// Set up 180-195 components of targeted buffer : contr_buffer_xxgg

            auto g_yyzz_xxxx = contr_buffer_xxgg[gg_off + 180];

            auto g_yyzz_xxxy = contr_buffer_xxgg[gg_off + 181];

            auto g_yyzz_xxxz = contr_buffer_xxgg[gg_off + 182];

            auto g_yyzz_xxyy = contr_buffer_xxgg[gg_off + 183];

            auto g_yyzz_xxyz = contr_buffer_xxgg[gg_off + 184];

            auto g_yyzz_xxzz = contr_buffer_xxgg[gg_off + 185];

            auto g_yyzz_xyyy = contr_buffer_xxgg[gg_off + 186];

            auto g_yyzz_xyyz = contr_buffer_xxgg[gg_off + 187];

            auto g_yyzz_xyzz = contr_buffer_xxgg[gg_off + 188];

            auto g_yyzz_xzzz = contr_buffer_xxgg[gg_off + 189];

            auto g_yyzz_yyyy = contr_buffer_xxgg[gg_off + 190];

            auto g_yyzz_yyyz = contr_buffer_xxgg[gg_off + 191];

            auto g_yyzz_yyzz = contr_buffer_xxgg[gg_off + 192];

            auto g_yyzz_yzzz = contr_buffer_xxgg[gg_off + 193];

            auto g_yyzz_zzzz = contr_buffer_xxgg[gg_off + 194];

            #pragma omp simd aligned(cd_y, g_yyzz_xxxx, g_yyzz_xxxy, g_yyzz_xxxz, g_yyzz_xxyy, g_yyzz_xxyz, g_yyzz_xxzz, g_yyzz_xyyy, g_yyzz_xyyz, g_yyzz_xyzz, g_yyzz_xzzz, g_yyzz_yyyy, g_yyzz_yyyz, g_yyzz_yyzz, g_yyzz_yzzz, g_yyzz_zzzz, g_yzz_xxxx, g_yzz_xxxxy, g_yzz_xxxy, g_yzz_xxxyy, g_yzz_xxxyz, g_yzz_xxxz, g_yzz_xxyy, g_yzz_xxyyy, g_yzz_xxyyz, g_yzz_xxyz, g_yzz_xxyzz, g_yzz_xxzz, g_yzz_xyyy, g_yzz_xyyyy, g_yzz_xyyyz, g_yzz_xyyz, g_yzz_xyyzz, g_yzz_xyzz, g_yzz_xyzzz, g_yzz_xzzz, g_yzz_yyyy, g_yzz_yyyyy, g_yzz_yyyyz, g_yzz_yyyz, g_yzz_yyyzz, g_yzz_yyzz, g_yzz_yyzzz, g_yzz_yzzz, g_yzz_yzzzz, g_yzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_yyzz_xxxx[k] = -g_yzz_xxxx[k] * cd_y[k] + g_yzz_xxxxy[k];

                g_yyzz_xxxy[k] = -g_yzz_xxxy[k] * cd_y[k] + g_yzz_xxxyy[k];

                g_yyzz_xxxz[k] = -g_yzz_xxxz[k] * cd_y[k] + g_yzz_xxxyz[k];

                g_yyzz_xxyy[k] = -g_yzz_xxyy[k] * cd_y[k] + g_yzz_xxyyy[k];

                g_yyzz_xxyz[k] = -g_yzz_xxyz[k] * cd_y[k] + g_yzz_xxyyz[k];

                g_yyzz_xxzz[k] = -g_yzz_xxzz[k] * cd_y[k] + g_yzz_xxyzz[k];

                g_yyzz_xyyy[k] = -g_yzz_xyyy[k] * cd_y[k] + g_yzz_xyyyy[k];

                g_yyzz_xyyz[k] = -g_yzz_xyyz[k] * cd_y[k] + g_yzz_xyyyz[k];

                g_yyzz_xyzz[k] = -g_yzz_xyzz[k] * cd_y[k] + g_yzz_xyyzz[k];

                g_yyzz_xzzz[k] = -g_yzz_xzzz[k] * cd_y[k] + g_yzz_xyzzz[k];

                g_yyzz_yyyy[k] = -g_yzz_yyyy[k] * cd_y[k] + g_yzz_yyyyy[k];

                g_yyzz_yyyz[k] = -g_yzz_yyyz[k] * cd_y[k] + g_yzz_yyyyz[k];

                g_yyzz_yyzz[k] = -g_yzz_yyzz[k] * cd_y[k] + g_yzz_yyyzz[k];

                g_yyzz_yzzz[k] = -g_yzz_yzzz[k] * cd_y[k] + g_yzz_yyzzz[k];

                g_yyzz_zzzz[k] = -g_yzz_zzzz[k] * cd_y[k] + g_yzz_yzzzz[k];
            }

            /// Set up 195-210 components of targeted buffer : contr_buffer_xxgg

            auto g_yzzz_xxxx = contr_buffer_xxgg[gg_off + 195];

            auto g_yzzz_xxxy = contr_buffer_xxgg[gg_off + 196];

            auto g_yzzz_xxxz = contr_buffer_xxgg[gg_off + 197];

            auto g_yzzz_xxyy = contr_buffer_xxgg[gg_off + 198];

            auto g_yzzz_xxyz = contr_buffer_xxgg[gg_off + 199];

            auto g_yzzz_xxzz = contr_buffer_xxgg[gg_off + 200];

            auto g_yzzz_xyyy = contr_buffer_xxgg[gg_off + 201];

            auto g_yzzz_xyyz = contr_buffer_xxgg[gg_off + 202];

            auto g_yzzz_xyzz = contr_buffer_xxgg[gg_off + 203];

            auto g_yzzz_xzzz = contr_buffer_xxgg[gg_off + 204];

            auto g_yzzz_yyyy = contr_buffer_xxgg[gg_off + 205];

            auto g_yzzz_yyyz = contr_buffer_xxgg[gg_off + 206];

            auto g_yzzz_yyzz = contr_buffer_xxgg[gg_off + 207];

            auto g_yzzz_yzzz = contr_buffer_xxgg[gg_off + 208];

            auto g_yzzz_zzzz = contr_buffer_xxgg[gg_off + 209];

            #pragma omp simd aligned(cd_y, g_yzzz_xxxx, g_yzzz_xxxy, g_yzzz_xxxz, g_yzzz_xxyy, g_yzzz_xxyz, g_yzzz_xxzz, g_yzzz_xyyy, g_yzzz_xyyz, g_yzzz_xyzz, g_yzzz_xzzz, g_yzzz_yyyy, g_yzzz_yyyz, g_yzzz_yyzz, g_yzzz_yzzz, g_yzzz_zzzz, g_zzz_xxxx, g_zzz_xxxxy, g_zzz_xxxy, g_zzz_xxxyy, g_zzz_xxxyz, g_zzz_xxxz, g_zzz_xxyy, g_zzz_xxyyy, g_zzz_xxyyz, g_zzz_xxyz, g_zzz_xxyzz, g_zzz_xxzz, g_zzz_xyyy, g_zzz_xyyyy, g_zzz_xyyyz, g_zzz_xyyz, g_zzz_xyyzz, g_zzz_xyzz, g_zzz_xyzzz, g_zzz_xzzz, g_zzz_yyyy, g_zzz_yyyyy, g_zzz_yyyyz, g_zzz_yyyz, g_zzz_yyyzz, g_zzz_yyzz, g_zzz_yyzzz, g_zzz_yzzz, g_zzz_yzzzz, g_zzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_yzzz_xxxx[k] = -g_zzz_xxxx[k] * cd_y[k] + g_zzz_xxxxy[k];

                g_yzzz_xxxy[k] = -g_zzz_xxxy[k] * cd_y[k] + g_zzz_xxxyy[k];

                g_yzzz_xxxz[k] = -g_zzz_xxxz[k] * cd_y[k] + g_zzz_xxxyz[k];

                g_yzzz_xxyy[k] = -g_zzz_xxyy[k] * cd_y[k] + g_zzz_xxyyy[k];

                g_yzzz_xxyz[k] = -g_zzz_xxyz[k] * cd_y[k] + g_zzz_xxyyz[k];

                g_yzzz_xxzz[k] = -g_zzz_xxzz[k] * cd_y[k] + g_zzz_xxyzz[k];

                g_yzzz_xyyy[k] = -g_zzz_xyyy[k] * cd_y[k] + g_zzz_xyyyy[k];

                g_yzzz_xyyz[k] = -g_zzz_xyyz[k] * cd_y[k] + g_zzz_xyyyz[k];

                g_yzzz_xyzz[k] = -g_zzz_xyzz[k] * cd_y[k] + g_zzz_xyyzz[k];

                g_yzzz_xzzz[k] = -g_zzz_xzzz[k] * cd_y[k] + g_zzz_xyzzz[k];

                g_yzzz_yyyy[k] = -g_zzz_yyyy[k] * cd_y[k] + g_zzz_yyyyy[k];

                g_yzzz_yyyz[k] = -g_zzz_yyyz[k] * cd_y[k] + g_zzz_yyyyz[k];

                g_yzzz_yyzz[k] = -g_zzz_yyzz[k] * cd_y[k] + g_zzz_yyyzz[k];

                g_yzzz_yzzz[k] = -g_zzz_yzzz[k] * cd_y[k] + g_zzz_yyzzz[k];

                g_yzzz_zzzz[k] = -g_zzz_zzzz[k] * cd_y[k] + g_zzz_yzzzz[k];
            }

            /// Set up 210-225 components of targeted buffer : contr_buffer_xxgg

            auto g_zzzz_xxxx = contr_buffer_xxgg[gg_off + 210];

            auto g_zzzz_xxxy = contr_buffer_xxgg[gg_off + 211];

            auto g_zzzz_xxxz = contr_buffer_xxgg[gg_off + 212];

            auto g_zzzz_xxyy = contr_buffer_xxgg[gg_off + 213];

            auto g_zzzz_xxyz = contr_buffer_xxgg[gg_off + 214];

            auto g_zzzz_xxzz = contr_buffer_xxgg[gg_off + 215];

            auto g_zzzz_xyyy = contr_buffer_xxgg[gg_off + 216];

            auto g_zzzz_xyyz = contr_buffer_xxgg[gg_off + 217];

            auto g_zzzz_xyzz = contr_buffer_xxgg[gg_off + 218];

            auto g_zzzz_xzzz = contr_buffer_xxgg[gg_off + 219];

            auto g_zzzz_yyyy = contr_buffer_xxgg[gg_off + 220];

            auto g_zzzz_yyyz = contr_buffer_xxgg[gg_off + 221];

            auto g_zzzz_yyzz = contr_buffer_xxgg[gg_off + 222];

            auto g_zzzz_yzzz = contr_buffer_xxgg[gg_off + 223];

            auto g_zzzz_zzzz = contr_buffer_xxgg[gg_off + 224];

            #pragma omp simd aligned(cd_z, g_zzz_xxxx, g_zzz_xxxxz, g_zzz_xxxy, g_zzz_xxxyz, g_zzz_xxxz, g_zzz_xxxzz, g_zzz_xxyy, g_zzz_xxyyz, g_zzz_xxyz, g_zzz_xxyzz, g_zzz_xxzz, g_zzz_xxzzz, g_zzz_xyyy, g_zzz_xyyyz, g_zzz_xyyz, g_zzz_xyyzz, g_zzz_xyzz, g_zzz_xyzzz, g_zzz_xzzz, g_zzz_xzzzz, g_zzz_yyyy, g_zzz_yyyyz, g_zzz_yyyz, g_zzz_yyyzz, g_zzz_yyzz, g_zzz_yyzzz, g_zzz_yzzz, g_zzz_yzzzz, g_zzz_zzzz, g_zzz_zzzzz, g_zzzz_xxxx, g_zzzz_xxxy, g_zzzz_xxxz, g_zzzz_xxyy, g_zzzz_xxyz, g_zzzz_xxzz, g_zzzz_xyyy, g_zzzz_xyyz, g_zzzz_xyzz, g_zzzz_xzzz, g_zzzz_yyyy, g_zzzz_yyyz, g_zzzz_yyzz, g_zzzz_yzzz, g_zzzz_zzzz  : 64)
            for (int k = 0; k < ndims; k++)
            {
                g_zzzz_xxxx[k] = -g_zzz_xxxx[k] * cd_z[k] + g_zzz_xxxxz[k];

                g_zzzz_xxxy[k] = -g_zzz_xxxy[k] * cd_z[k] + g_zzz_xxxyz[k];

                g_zzzz_xxxz[k] = -g_zzz_xxxz[k] * cd_z[k] + g_zzz_xxxzz[k];

                g_zzzz_xxyy[k] = -g_zzz_xxyy[k] * cd_z[k] + g_zzz_xxyyz[k];

                g_zzzz_xxyz[k] = -g_zzz_xxyz[k] * cd_z[k] + g_zzz_xxyzz[k];

                g_zzzz_xxzz[k] = -g_zzz_xxzz[k] * cd_z[k] + g_zzz_xxzzz[k];

                g_zzzz_xyyy[k] = -g_zzz_xyyy[k] * cd_z[k] + g_zzz_xyyyz[k];

                g_zzzz_xyyz[k] = -g_zzz_xyyz[k] * cd_z[k] + g_zzz_xyyzz[k];

                g_zzzz_xyzz[k] = -g_zzz_xyzz[k] * cd_z[k] + g_zzz_xyzzz[k];

                g_zzzz_xzzz[k] = -g_zzz_xzzz[k] * cd_z[k] + g_zzz_xzzzz[k];

                g_zzzz_yyyy[k] = -g_zzz_yyyy[k] * cd_z[k] + g_zzz_yyyyz[k];

                g_zzzz_yyyz[k] = -g_zzz_yyyz[k] * cd_z[k] + g_zzz_yyyzz[k];

                g_zzzz_yyzz[k] = -g_zzz_yyzz[k] * cd_z[k] + g_zzz_yyzzz[k];

                g_zzzz_yzzz[k] = -g_zzz_yzzz[k] * cd_z[k] + g_zzz_yzzzz[k];

                g_zzzz_zzzz[k] = -g_zzz_zzzz[k] * cd_z[k] + g_zzz_zzzzz[k];
            }
        }
    }
}

} // erirec namespace

