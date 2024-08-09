#include "GeomDeriv1010OfScalarForPDPD.hpp"

namespace t4c_geom { // t4c_geom namespace

auto
comp_geom1010_pdpd_0(CSimdArray<double>& buffer_1010_pdpd,
                     const CSimdArray<double>& buffer_sdsd,
                     const CSimdArray<double>& buffer_sddd,
                     const CSimdArray<double>& buffer_ddsd,
                     const CSimdArray<double>& buffer_dddd,
                     const double a_exp,
                     const double* c_exps) -> void
{
    const auto ndims = buffer_1010_pdpd.number_of_columns();

    /// Set up components of auxilary buffer : buffer_sdsd

    auto g_0_xx_0_xx = buffer_sdsd[0];

    auto g_0_xx_0_xy = buffer_sdsd[1];

    auto g_0_xx_0_xz = buffer_sdsd[2];

    auto g_0_xx_0_yy = buffer_sdsd[3];

    auto g_0_xx_0_yz = buffer_sdsd[4];

    auto g_0_xx_0_zz = buffer_sdsd[5];

    auto g_0_xy_0_xx = buffer_sdsd[6];

    auto g_0_xy_0_xy = buffer_sdsd[7];

    auto g_0_xy_0_xz = buffer_sdsd[8];

    auto g_0_xy_0_yy = buffer_sdsd[9];

    auto g_0_xy_0_yz = buffer_sdsd[10];

    auto g_0_xy_0_zz = buffer_sdsd[11];

    auto g_0_xz_0_xx = buffer_sdsd[12];

    auto g_0_xz_0_xy = buffer_sdsd[13];

    auto g_0_xz_0_xz = buffer_sdsd[14];

    auto g_0_xz_0_yy = buffer_sdsd[15];

    auto g_0_xz_0_yz = buffer_sdsd[16];

    auto g_0_xz_0_zz = buffer_sdsd[17];

    auto g_0_yy_0_xx = buffer_sdsd[18];

    auto g_0_yy_0_xy = buffer_sdsd[19];

    auto g_0_yy_0_xz = buffer_sdsd[20];

    auto g_0_yy_0_yy = buffer_sdsd[21];

    auto g_0_yy_0_yz = buffer_sdsd[22];

    auto g_0_yy_0_zz = buffer_sdsd[23];

    auto g_0_yz_0_xx = buffer_sdsd[24];

    auto g_0_yz_0_xy = buffer_sdsd[25];

    auto g_0_yz_0_xz = buffer_sdsd[26];

    auto g_0_yz_0_yy = buffer_sdsd[27];

    auto g_0_yz_0_yz = buffer_sdsd[28];

    auto g_0_yz_0_zz = buffer_sdsd[29];

    auto g_0_zz_0_xx = buffer_sdsd[30];

    auto g_0_zz_0_xy = buffer_sdsd[31];

    auto g_0_zz_0_xz = buffer_sdsd[32];

    auto g_0_zz_0_yy = buffer_sdsd[33];

    auto g_0_zz_0_yz = buffer_sdsd[34];

    auto g_0_zz_0_zz = buffer_sdsd[35];

    /// Set up components of auxilary buffer : buffer_sddd

    auto g_0_xx_xx_xx = buffer_sddd[0];

    auto g_0_xx_xx_xy = buffer_sddd[1];

    auto g_0_xx_xx_xz = buffer_sddd[2];

    auto g_0_xx_xx_yy = buffer_sddd[3];

    auto g_0_xx_xx_yz = buffer_sddd[4];

    auto g_0_xx_xx_zz = buffer_sddd[5];

    auto g_0_xx_xy_xx = buffer_sddd[6];

    auto g_0_xx_xy_xy = buffer_sddd[7];

    auto g_0_xx_xy_xz = buffer_sddd[8];

    auto g_0_xx_xy_yy = buffer_sddd[9];

    auto g_0_xx_xy_yz = buffer_sddd[10];

    auto g_0_xx_xy_zz = buffer_sddd[11];

    auto g_0_xx_xz_xx = buffer_sddd[12];

    auto g_0_xx_xz_xy = buffer_sddd[13];

    auto g_0_xx_xz_xz = buffer_sddd[14];

    auto g_0_xx_xz_yy = buffer_sddd[15];

    auto g_0_xx_xz_yz = buffer_sddd[16];

    auto g_0_xx_xz_zz = buffer_sddd[17];

    auto g_0_xx_yy_xx = buffer_sddd[18];

    auto g_0_xx_yy_xy = buffer_sddd[19];

    auto g_0_xx_yy_xz = buffer_sddd[20];

    auto g_0_xx_yy_yy = buffer_sddd[21];

    auto g_0_xx_yy_yz = buffer_sddd[22];

    auto g_0_xx_yy_zz = buffer_sddd[23];

    auto g_0_xx_yz_xx = buffer_sddd[24];

    auto g_0_xx_yz_xy = buffer_sddd[25];

    auto g_0_xx_yz_xz = buffer_sddd[26];

    auto g_0_xx_yz_yy = buffer_sddd[27];

    auto g_0_xx_yz_yz = buffer_sddd[28];

    auto g_0_xx_yz_zz = buffer_sddd[29];

    auto g_0_xx_zz_xx = buffer_sddd[30];

    auto g_0_xx_zz_xy = buffer_sddd[31];

    auto g_0_xx_zz_xz = buffer_sddd[32];

    auto g_0_xx_zz_yy = buffer_sddd[33];

    auto g_0_xx_zz_yz = buffer_sddd[34];

    auto g_0_xx_zz_zz = buffer_sddd[35];

    auto g_0_xy_xx_xx = buffer_sddd[36];

    auto g_0_xy_xx_xy = buffer_sddd[37];

    auto g_0_xy_xx_xz = buffer_sddd[38];

    auto g_0_xy_xx_yy = buffer_sddd[39];

    auto g_0_xy_xx_yz = buffer_sddd[40];

    auto g_0_xy_xx_zz = buffer_sddd[41];

    auto g_0_xy_xy_xx = buffer_sddd[42];

    auto g_0_xy_xy_xy = buffer_sddd[43];

    auto g_0_xy_xy_xz = buffer_sddd[44];

    auto g_0_xy_xy_yy = buffer_sddd[45];

    auto g_0_xy_xy_yz = buffer_sddd[46];

    auto g_0_xy_xy_zz = buffer_sddd[47];

    auto g_0_xy_xz_xx = buffer_sddd[48];

    auto g_0_xy_xz_xy = buffer_sddd[49];

    auto g_0_xy_xz_xz = buffer_sddd[50];

    auto g_0_xy_xz_yy = buffer_sddd[51];

    auto g_0_xy_xz_yz = buffer_sddd[52];

    auto g_0_xy_xz_zz = buffer_sddd[53];

    auto g_0_xy_yy_xx = buffer_sddd[54];

    auto g_0_xy_yy_xy = buffer_sddd[55];

    auto g_0_xy_yy_xz = buffer_sddd[56];

    auto g_0_xy_yy_yy = buffer_sddd[57];

    auto g_0_xy_yy_yz = buffer_sddd[58];

    auto g_0_xy_yy_zz = buffer_sddd[59];

    auto g_0_xy_yz_xx = buffer_sddd[60];

    auto g_0_xy_yz_xy = buffer_sddd[61];

    auto g_0_xy_yz_xz = buffer_sddd[62];

    auto g_0_xy_yz_yy = buffer_sddd[63];

    auto g_0_xy_yz_yz = buffer_sddd[64];

    auto g_0_xy_yz_zz = buffer_sddd[65];

    auto g_0_xy_zz_xx = buffer_sddd[66];

    auto g_0_xy_zz_xy = buffer_sddd[67];

    auto g_0_xy_zz_xz = buffer_sddd[68];

    auto g_0_xy_zz_yy = buffer_sddd[69];

    auto g_0_xy_zz_yz = buffer_sddd[70];

    auto g_0_xy_zz_zz = buffer_sddd[71];

    auto g_0_xz_xx_xx = buffer_sddd[72];

    auto g_0_xz_xx_xy = buffer_sddd[73];

    auto g_0_xz_xx_xz = buffer_sddd[74];

    auto g_0_xz_xx_yy = buffer_sddd[75];

    auto g_0_xz_xx_yz = buffer_sddd[76];

    auto g_0_xz_xx_zz = buffer_sddd[77];

    auto g_0_xz_xy_xx = buffer_sddd[78];

    auto g_0_xz_xy_xy = buffer_sddd[79];

    auto g_0_xz_xy_xz = buffer_sddd[80];

    auto g_0_xz_xy_yy = buffer_sddd[81];

    auto g_0_xz_xy_yz = buffer_sddd[82];

    auto g_0_xz_xy_zz = buffer_sddd[83];

    auto g_0_xz_xz_xx = buffer_sddd[84];

    auto g_0_xz_xz_xy = buffer_sddd[85];

    auto g_0_xz_xz_xz = buffer_sddd[86];

    auto g_0_xz_xz_yy = buffer_sddd[87];

    auto g_0_xz_xz_yz = buffer_sddd[88];

    auto g_0_xz_xz_zz = buffer_sddd[89];

    auto g_0_xz_yy_xx = buffer_sddd[90];

    auto g_0_xz_yy_xy = buffer_sddd[91];

    auto g_0_xz_yy_xz = buffer_sddd[92];

    auto g_0_xz_yy_yy = buffer_sddd[93];

    auto g_0_xz_yy_yz = buffer_sddd[94];

    auto g_0_xz_yy_zz = buffer_sddd[95];

    auto g_0_xz_yz_xx = buffer_sddd[96];

    auto g_0_xz_yz_xy = buffer_sddd[97];

    auto g_0_xz_yz_xz = buffer_sddd[98];

    auto g_0_xz_yz_yy = buffer_sddd[99];

    auto g_0_xz_yz_yz = buffer_sddd[100];

    auto g_0_xz_yz_zz = buffer_sddd[101];

    auto g_0_xz_zz_xx = buffer_sddd[102];

    auto g_0_xz_zz_xy = buffer_sddd[103];

    auto g_0_xz_zz_xz = buffer_sddd[104];

    auto g_0_xz_zz_yy = buffer_sddd[105];

    auto g_0_xz_zz_yz = buffer_sddd[106];

    auto g_0_xz_zz_zz = buffer_sddd[107];

    auto g_0_yy_xx_xx = buffer_sddd[108];

    auto g_0_yy_xx_xy = buffer_sddd[109];

    auto g_0_yy_xx_xz = buffer_sddd[110];

    auto g_0_yy_xx_yy = buffer_sddd[111];

    auto g_0_yy_xx_yz = buffer_sddd[112];

    auto g_0_yy_xx_zz = buffer_sddd[113];

    auto g_0_yy_xy_xx = buffer_sddd[114];

    auto g_0_yy_xy_xy = buffer_sddd[115];

    auto g_0_yy_xy_xz = buffer_sddd[116];

    auto g_0_yy_xy_yy = buffer_sddd[117];

    auto g_0_yy_xy_yz = buffer_sddd[118];

    auto g_0_yy_xy_zz = buffer_sddd[119];

    auto g_0_yy_xz_xx = buffer_sddd[120];

    auto g_0_yy_xz_xy = buffer_sddd[121];

    auto g_0_yy_xz_xz = buffer_sddd[122];

    auto g_0_yy_xz_yy = buffer_sddd[123];

    auto g_0_yy_xz_yz = buffer_sddd[124];

    auto g_0_yy_xz_zz = buffer_sddd[125];

    auto g_0_yy_yy_xx = buffer_sddd[126];

    auto g_0_yy_yy_xy = buffer_sddd[127];

    auto g_0_yy_yy_xz = buffer_sddd[128];

    auto g_0_yy_yy_yy = buffer_sddd[129];

    auto g_0_yy_yy_yz = buffer_sddd[130];

    auto g_0_yy_yy_zz = buffer_sddd[131];

    auto g_0_yy_yz_xx = buffer_sddd[132];

    auto g_0_yy_yz_xy = buffer_sddd[133];

    auto g_0_yy_yz_xz = buffer_sddd[134];

    auto g_0_yy_yz_yy = buffer_sddd[135];

    auto g_0_yy_yz_yz = buffer_sddd[136];

    auto g_0_yy_yz_zz = buffer_sddd[137];

    auto g_0_yy_zz_xx = buffer_sddd[138];

    auto g_0_yy_zz_xy = buffer_sddd[139];

    auto g_0_yy_zz_xz = buffer_sddd[140];

    auto g_0_yy_zz_yy = buffer_sddd[141];

    auto g_0_yy_zz_yz = buffer_sddd[142];

    auto g_0_yy_zz_zz = buffer_sddd[143];

    auto g_0_yz_xx_xx = buffer_sddd[144];

    auto g_0_yz_xx_xy = buffer_sddd[145];

    auto g_0_yz_xx_xz = buffer_sddd[146];

    auto g_0_yz_xx_yy = buffer_sddd[147];

    auto g_0_yz_xx_yz = buffer_sddd[148];

    auto g_0_yz_xx_zz = buffer_sddd[149];

    auto g_0_yz_xy_xx = buffer_sddd[150];

    auto g_0_yz_xy_xy = buffer_sddd[151];

    auto g_0_yz_xy_xz = buffer_sddd[152];

    auto g_0_yz_xy_yy = buffer_sddd[153];

    auto g_0_yz_xy_yz = buffer_sddd[154];

    auto g_0_yz_xy_zz = buffer_sddd[155];

    auto g_0_yz_xz_xx = buffer_sddd[156];

    auto g_0_yz_xz_xy = buffer_sddd[157];

    auto g_0_yz_xz_xz = buffer_sddd[158];

    auto g_0_yz_xz_yy = buffer_sddd[159];

    auto g_0_yz_xz_yz = buffer_sddd[160];

    auto g_0_yz_xz_zz = buffer_sddd[161];

    auto g_0_yz_yy_xx = buffer_sddd[162];

    auto g_0_yz_yy_xy = buffer_sddd[163];

    auto g_0_yz_yy_xz = buffer_sddd[164];

    auto g_0_yz_yy_yy = buffer_sddd[165];

    auto g_0_yz_yy_yz = buffer_sddd[166];

    auto g_0_yz_yy_zz = buffer_sddd[167];

    auto g_0_yz_yz_xx = buffer_sddd[168];

    auto g_0_yz_yz_xy = buffer_sddd[169];

    auto g_0_yz_yz_xz = buffer_sddd[170];

    auto g_0_yz_yz_yy = buffer_sddd[171];

    auto g_0_yz_yz_yz = buffer_sddd[172];

    auto g_0_yz_yz_zz = buffer_sddd[173];

    auto g_0_yz_zz_xx = buffer_sddd[174];

    auto g_0_yz_zz_xy = buffer_sddd[175];

    auto g_0_yz_zz_xz = buffer_sddd[176];

    auto g_0_yz_zz_yy = buffer_sddd[177];

    auto g_0_yz_zz_yz = buffer_sddd[178];

    auto g_0_yz_zz_zz = buffer_sddd[179];

    auto g_0_zz_xx_xx = buffer_sddd[180];

    auto g_0_zz_xx_xy = buffer_sddd[181];

    auto g_0_zz_xx_xz = buffer_sddd[182];

    auto g_0_zz_xx_yy = buffer_sddd[183];

    auto g_0_zz_xx_yz = buffer_sddd[184];

    auto g_0_zz_xx_zz = buffer_sddd[185];

    auto g_0_zz_xy_xx = buffer_sddd[186];

    auto g_0_zz_xy_xy = buffer_sddd[187];

    auto g_0_zz_xy_xz = buffer_sddd[188];

    auto g_0_zz_xy_yy = buffer_sddd[189];

    auto g_0_zz_xy_yz = buffer_sddd[190];

    auto g_0_zz_xy_zz = buffer_sddd[191];

    auto g_0_zz_xz_xx = buffer_sddd[192];

    auto g_0_zz_xz_xy = buffer_sddd[193];

    auto g_0_zz_xz_xz = buffer_sddd[194];

    auto g_0_zz_xz_yy = buffer_sddd[195];

    auto g_0_zz_xz_yz = buffer_sddd[196];

    auto g_0_zz_xz_zz = buffer_sddd[197];

    auto g_0_zz_yy_xx = buffer_sddd[198];

    auto g_0_zz_yy_xy = buffer_sddd[199];

    auto g_0_zz_yy_xz = buffer_sddd[200];

    auto g_0_zz_yy_yy = buffer_sddd[201];

    auto g_0_zz_yy_yz = buffer_sddd[202];

    auto g_0_zz_yy_zz = buffer_sddd[203];

    auto g_0_zz_yz_xx = buffer_sddd[204];

    auto g_0_zz_yz_xy = buffer_sddd[205];

    auto g_0_zz_yz_xz = buffer_sddd[206];

    auto g_0_zz_yz_yy = buffer_sddd[207];

    auto g_0_zz_yz_yz = buffer_sddd[208];

    auto g_0_zz_yz_zz = buffer_sddd[209];

    auto g_0_zz_zz_xx = buffer_sddd[210];

    auto g_0_zz_zz_xy = buffer_sddd[211];

    auto g_0_zz_zz_xz = buffer_sddd[212];

    auto g_0_zz_zz_yy = buffer_sddd[213];

    auto g_0_zz_zz_yz = buffer_sddd[214];

    auto g_0_zz_zz_zz = buffer_sddd[215];

    /// Set up components of auxilary buffer : buffer_ddsd

    auto g_xx_xx_0_xx = buffer_ddsd[0];

    auto g_xx_xx_0_xy = buffer_ddsd[1];

    auto g_xx_xx_0_xz = buffer_ddsd[2];

    auto g_xx_xx_0_yy = buffer_ddsd[3];

    auto g_xx_xx_0_yz = buffer_ddsd[4];

    auto g_xx_xx_0_zz = buffer_ddsd[5];

    auto g_xx_xy_0_xx = buffer_ddsd[6];

    auto g_xx_xy_0_xy = buffer_ddsd[7];

    auto g_xx_xy_0_xz = buffer_ddsd[8];

    auto g_xx_xy_0_yy = buffer_ddsd[9];

    auto g_xx_xy_0_yz = buffer_ddsd[10];

    auto g_xx_xy_0_zz = buffer_ddsd[11];

    auto g_xx_xz_0_xx = buffer_ddsd[12];

    auto g_xx_xz_0_xy = buffer_ddsd[13];

    auto g_xx_xz_0_xz = buffer_ddsd[14];

    auto g_xx_xz_0_yy = buffer_ddsd[15];

    auto g_xx_xz_0_yz = buffer_ddsd[16];

    auto g_xx_xz_0_zz = buffer_ddsd[17];

    auto g_xx_yy_0_xx = buffer_ddsd[18];

    auto g_xx_yy_0_xy = buffer_ddsd[19];

    auto g_xx_yy_0_xz = buffer_ddsd[20];

    auto g_xx_yy_0_yy = buffer_ddsd[21];

    auto g_xx_yy_0_yz = buffer_ddsd[22];

    auto g_xx_yy_0_zz = buffer_ddsd[23];

    auto g_xx_yz_0_xx = buffer_ddsd[24];

    auto g_xx_yz_0_xy = buffer_ddsd[25];

    auto g_xx_yz_0_xz = buffer_ddsd[26];

    auto g_xx_yz_0_yy = buffer_ddsd[27];

    auto g_xx_yz_0_yz = buffer_ddsd[28];

    auto g_xx_yz_0_zz = buffer_ddsd[29];

    auto g_xx_zz_0_xx = buffer_ddsd[30];

    auto g_xx_zz_0_xy = buffer_ddsd[31];

    auto g_xx_zz_0_xz = buffer_ddsd[32];

    auto g_xx_zz_0_yy = buffer_ddsd[33];

    auto g_xx_zz_0_yz = buffer_ddsd[34];

    auto g_xx_zz_0_zz = buffer_ddsd[35];

    auto g_xy_xx_0_xx = buffer_ddsd[36];

    auto g_xy_xx_0_xy = buffer_ddsd[37];

    auto g_xy_xx_0_xz = buffer_ddsd[38];

    auto g_xy_xx_0_yy = buffer_ddsd[39];

    auto g_xy_xx_0_yz = buffer_ddsd[40];

    auto g_xy_xx_0_zz = buffer_ddsd[41];

    auto g_xy_xy_0_xx = buffer_ddsd[42];

    auto g_xy_xy_0_xy = buffer_ddsd[43];

    auto g_xy_xy_0_xz = buffer_ddsd[44];

    auto g_xy_xy_0_yy = buffer_ddsd[45];

    auto g_xy_xy_0_yz = buffer_ddsd[46];

    auto g_xy_xy_0_zz = buffer_ddsd[47];

    auto g_xy_xz_0_xx = buffer_ddsd[48];

    auto g_xy_xz_0_xy = buffer_ddsd[49];

    auto g_xy_xz_0_xz = buffer_ddsd[50];

    auto g_xy_xz_0_yy = buffer_ddsd[51];

    auto g_xy_xz_0_yz = buffer_ddsd[52];

    auto g_xy_xz_0_zz = buffer_ddsd[53];

    auto g_xy_yy_0_xx = buffer_ddsd[54];

    auto g_xy_yy_0_xy = buffer_ddsd[55];

    auto g_xy_yy_0_xz = buffer_ddsd[56];

    auto g_xy_yy_0_yy = buffer_ddsd[57];

    auto g_xy_yy_0_yz = buffer_ddsd[58];

    auto g_xy_yy_0_zz = buffer_ddsd[59];

    auto g_xy_yz_0_xx = buffer_ddsd[60];

    auto g_xy_yz_0_xy = buffer_ddsd[61];

    auto g_xy_yz_0_xz = buffer_ddsd[62];

    auto g_xy_yz_0_yy = buffer_ddsd[63];

    auto g_xy_yz_0_yz = buffer_ddsd[64];

    auto g_xy_yz_0_zz = buffer_ddsd[65];

    auto g_xy_zz_0_xx = buffer_ddsd[66];

    auto g_xy_zz_0_xy = buffer_ddsd[67];

    auto g_xy_zz_0_xz = buffer_ddsd[68];

    auto g_xy_zz_0_yy = buffer_ddsd[69];

    auto g_xy_zz_0_yz = buffer_ddsd[70];

    auto g_xy_zz_0_zz = buffer_ddsd[71];

    auto g_xz_xx_0_xx = buffer_ddsd[72];

    auto g_xz_xx_0_xy = buffer_ddsd[73];

    auto g_xz_xx_0_xz = buffer_ddsd[74];

    auto g_xz_xx_0_yy = buffer_ddsd[75];

    auto g_xz_xx_0_yz = buffer_ddsd[76];

    auto g_xz_xx_0_zz = buffer_ddsd[77];

    auto g_xz_xy_0_xx = buffer_ddsd[78];

    auto g_xz_xy_0_xy = buffer_ddsd[79];

    auto g_xz_xy_0_xz = buffer_ddsd[80];

    auto g_xz_xy_0_yy = buffer_ddsd[81];

    auto g_xz_xy_0_yz = buffer_ddsd[82];

    auto g_xz_xy_0_zz = buffer_ddsd[83];

    auto g_xz_xz_0_xx = buffer_ddsd[84];

    auto g_xz_xz_0_xy = buffer_ddsd[85];

    auto g_xz_xz_0_xz = buffer_ddsd[86];

    auto g_xz_xz_0_yy = buffer_ddsd[87];

    auto g_xz_xz_0_yz = buffer_ddsd[88];

    auto g_xz_xz_0_zz = buffer_ddsd[89];

    auto g_xz_yy_0_xx = buffer_ddsd[90];

    auto g_xz_yy_0_xy = buffer_ddsd[91];

    auto g_xz_yy_0_xz = buffer_ddsd[92];

    auto g_xz_yy_0_yy = buffer_ddsd[93];

    auto g_xz_yy_0_yz = buffer_ddsd[94];

    auto g_xz_yy_0_zz = buffer_ddsd[95];

    auto g_xz_yz_0_xx = buffer_ddsd[96];

    auto g_xz_yz_0_xy = buffer_ddsd[97];

    auto g_xz_yz_0_xz = buffer_ddsd[98];

    auto g_xz_yz_0_yy = buffer_ddsd[99];

    auto g_xz_yz_0_yz = buffer_ddsd[100];

    auto g_xz_yz_0_zz = buffer_ddsd[101];

    auto g_xz_zz_0_xx = buffer_ddsd[102];

    auto g_xz_zz_0_xy = buffer_ddsd[103];

    auto g_xz_zz_0_xz = buffer_ddsd[104];

    auto g_xz_zz_0_yy = buffer_ddsd[105];

    auto g_xz_zz_0_yz = buffer_ddsd[106];

    auto g_xz_zz_0_zz = buffer_ddsd[107];

    auto g_yy_xx_0_xx = buffer_ddsd[108];

    auto g_yy_xx_0_xy = buffer_ddsd[109];

    auto g_yy_xx_0_xz = buffer_ddsd[110];

    auto g_yy_xx_0_yy = buffer_ddsd[111];

    auto g_yy_xx_0_yz = buffer_ddsd[112];

    auto g_yy_xx_0_zz = buffer_ddsd[113];

    auto g_yy_xy_0_xx = buffer_ddsd[114];

    auto g_yy_xy_0_xy = buffer_ddsd[115];

    auto g_yy_xy_0_xz = buffer_ddsd[116];

    auto g_yy_xy_0_yy = buffer_ddsd[117];

    auto g_yy_xy_0_yz = buffer_ddsd[118];

    auto g_yy_xy_0_zz = buffer_ddsd[119];

    auto g_yy_xz_0_xx = buffer_ddsd[120];

    auto g_yy_xz_0_xy = buffer_ddsd[121];

    auto g_yy_xz_0_xz = buffer_ddsd[122];

    auto g_yy_xz_0_yy = buffer_ddsd[123];

    auto g_yy_xz_0_yz = buffer_ddsd[124];

    auto g_yy_xz_0_zz = buffer_ddsd[125];

    auto g_yy_yy_0_xx = buffer_ddsd[126];

    auto g_yy_yy_0_xy = buffer_ddsd[127];

    auto g_yy_yy_0_xz = buffer_ddsd[128];

    auto g_yy_yy_0_yy = buffer_ddsd[129];

    auto g_yy_yy_0_yz = buffer_ddsd[130];

    auto g_yy_yy_0_zz = buffer_ddsd[131];

    auto g_yy_yz_0_xx = buffer_ddsd[132];

    auto g_yy_yz_0_xy = buffer_ddsd[133];

    auto g_yy_yz_0_xz = buffer_ddsd[134];

    auto g_yy_yz_0_yy = buffer_ddsd[135];

    auto g_yy_yz_0_yz = buffer_ddsd[136];

    auto g_yy_yz_0_zz = buffer_ddsd[137];

    auto g_yy_zz_0_xx = buffer_ddsd[138];

    auto g_yy_zz_0_xy = buffer_ddsd[139];

    auto g_yy_zz_0_xz = buffer_ddsd[140];

    auto g_yy_zz_0_yy = buffer_ddsd[141];

    auto g_yy_zz_0_yz = buffer_ddsd[142];

    auto g_yy_zz_0_zz = buffer_ddsd[143];

    auto g_yz_xx_0_xx = buffer_ddsd[144];

    auto g_yz_xx_0_xy = buffer_ddsd[145];

    auto g_yz_xx_0_xz = buffer_ddsd[146];

    auto g_yz_xx_0_yy = buffer_ddsd[147];

    auto g_yz_xx_0_yz = buffer_ddsd[148];

    auto g_yz_xx_0_zz = buffer_ddsd[149];

    auto g_yz_xy_0_xx = buffer_ddsd[150];

    auto g_yz_xy_0_xy = buffer_ddsd[151];

    auto g_yz_xy_0_xz = buffer_ddsd[152];

    auto g_yz_xy_0_yy = buffer_ddsd[153];

    auto g_yz_xy_0_yz = buffer_ddsd[154];

    auto g_yz_xy_0_zz = buffer_ddsd[155];

    auto g_yz_xz_0_xx = buffer_ddsd[156];

    auto g_yz_xz_0_xy = buffer_ddsd[157];

    auto g_yz_xz_0_xz = buffer_ddsd[158];

    auto g_yz_xz_0_yy = buffer_ddsd[159];

    auto g_yz_xz_0_yz = buffer_ddsd[160];

    auto g_yz_xz_0_zz = buffer_ddsd[161];

    auto g_yz_yy_0_xx = buffer_ddsd[162];

    auto g_yz_yy_0_xy = buffer_ddsd[163];

    auto g_yz_yy_0_xz = buffer_ddsd[164];

    auto g_yz_yy_0_yy = buffer_ddsd[165];

    auto g_yz_yy_0_yz = buffer_ddsd[166];

    auto g_yz_yy_0_zz = buffer_ddsd[167];

    auto g_yz_yz_0_xx = buffer_ddsd[168];

    auto g_yz_yz_0_xy = buffer_ddsd[169];

    auto g_yz_yz_0_xz = buffer_ddsd[170];

    auto g_yz_yz_0_yy = buffer_ddsd[171];

    auto g_yz_yz_0_yz = buffer_ddsd[172];

    auto g_yz_yz_0_zz = buffer_ddsd[173];

    auto g_yz_zz_0_xx = buffer_ddsd[174];

    auto g_yz_zz_0_xy = buffer_ddsd[175];

    auto g_yz_zz_0_xz = buffer_ddsd[176];

    auto g_yz_zz_0_yy = buffer_ddsd[177];

    auto g_yz_zz_0_yz = buffer_ddsd[178];

    auto g_yz_zz_0_zz = buffer_ddsd[179];

    auto g_zz_xx_0_xx = buffer_ddsd[180];

    auto g_zz_xx_0_xy = buffer_ddsd[181];

    auto g_zz_xx_0_xz = buffer_ddsd[182];

    auto g_zz_xx_0_yy = buffer_ddsd[183];

    auto g_zz_xx_0_yz = buffer_ddsd[184];

    auto g_zz_xx_0_zz = buffer_ddsd[185];

    auto g_zz_xy_0_xx = buffer_ddsd[186];

    auto g_zz_xy_0_xy = buffer_ddsd[187];

    auto g_zz_xy_0_xz = buffer_ddsd[188];

    auto g_zz_xy_0_yy = buffer_ddsd[189];

    auto g_zz_xy_0_yz = buffer_ddsd[190];

    auto g_zz_xy_0_zz = buffer_ddsd[191];

    auto g_zz_xz_0_xx = buffer_ddsd[192];

    auto g_zz_xz_0_xy = buffer_ddsd[193];

    auto g_zz_xz_0_xz = buffer_ddsd[194];

    auto g_zz_xz_0_yy = buffer_ddsd[195];

    auto g_zz_xz_0_yz = buffer_ddsd[196];

    auto g_zz_xz_0_zz = buffer_ddsd[197];

    auto g_zz_yy_0_xx = buffer_ddsd[198];

    auto g_zz_yy_0_xy = buffer_ddsd[199];

    auto g_zz_yy_0_xz = buffer_ddsd[200];

    auto g_zz_yy_0_yy = buffer_ddsd[201];

    auto g_zz_yy_0_yz = buffer_ddsd[202];

    auto g_zz_yy_0_zz = buffer_ddsd[203];

    auto g_zz_yz_0_xx = buffer_ddsd[204];

    auto g_zz_yz_0_xy = buffer_ddsd[205];

    auto g_zz_yz_0_xz = buffer_ddsd[206];

    auto g_zz_yz_0_yy = buffer_ddsd[207];

    auto g_zz_yz_0_yz = buffer_ddsd[208];

    auto g_zz_yz_0_zz = buffer_ddsd[209];

    auto g_zz_zz_0_xx = buffer_ddsd[210];

    auto g_zz_zz_0_xy = buffer_ddsd[211];

    auto g_zz_zz_0_xz = buffer_ddsd[212];

    auto g_zz_zz_0_yy = buffer_ddsd[213];

    auto g_zz_zz_0_yz = buffer_ddsd[214];

    auto g_zz_zz_0_zz = buffer_ddsd[215];

    /// Set up components of auxilary buffer : buffer_dddd

    auto g_xx_xx_xx_xx = buffer_dddd[0];

    auto g_xx_xx_xx_xy = buffer_dddd[1];

    auto g_xx_xx_xx_xz = buffer_dddd[2];

    auto g_xx_xx_xx_yy = buffer_dddd[3];

    auto g_xx_xx_xx_yz = buffer_dddd[4];

    auto g_xx_xx_xx_zz = buffer_dddd[5];

    auto g_xx_xx_xy_xx = buffer_dddd[6];

    auto g_xx_xx_xy_xy = buffer_dddd[7];

    auto g_xx_xx_xy_xz = buffer_dddd[8];

    auto g_xx_xx_xy_yy = buffer_dddd[9];

    auto g_xx_xx_xy_yz = buffer_dddd[10];

    auto g_xx_xx_xy_zz = buffer_dddd[11];

    auto g_xx_xx_xz_xx = buffer_dddd[12];

    auto g_xx_xx_xz_xy = buffer_dddd[13];

    auto g_xx_xx_xz_xz = buffer_dddd[14];

    auto g_xx_xx_xz_yy = buffer_dddd[15];

    auto g_xx_xx_xz_yz = buffer_dddd[16];

    auto g_xx_xx_xz_zz = buffer_dddd[17];

    auto g_xx_xx_yy_xx = buffer_dddd[18];

    auto g_xx_xx_yy_xy = buffer_dddd[19];

    auto g_xx_xx_yy_xz = buffer_dddd[20];

    auto g_xx_xx_yy_yy = buffer_dddd[21];

    auto g_xx_xx_yy_yz = buffer_dddd[22];

    auto g_xx_xx_yy_zz = buffer_dddd[23];

    auto g_xx_xx_yz_xx = buffer_dddd[24];

    auto g_xx_xx_yz_xy = buffer_dddd[25];

    auto g_xx_xx_yz_xz = buffer_dddd[26];

    auto g_xx_xx_yz_yy = buffer_dddd[27];

    auto g_xx_xx_yz_yz = buffer_dddd[28];

    auto g_xx_xx_yz_zz = buffer_dddd[29];

    auto g_xx_xx_zz_xx = buffer_dddd[30];

    auto g_xx_xx_zz_xy = buffer_dddd[31];

    auto g_xx_xx_zz_xz = buffer_dddd[32];

    auto g_xx_xx_zz_yy = buffer_dddd[33];

    auto g_xx_xx_zz_yz = buffer_dddd[34];

    auto g_xx_xx_zz_zz = buffer_dddd[35];

    auto g_xx_xy_xx_xx = buffer_dddd[36];

    auto g_xx_xy_xx_xy = buffer_dddd[37];

    auto g_xx_xy_xx_xz = buffer_dddd[38];

    auto g_xx_xy_xx_yy = buffer_dddd[39];

    auto g_xx_xy_xx_yz = buffer_dddd[40];

    auto g_xx_xy_xx_zz = buffer_dddd[41];

    auto g_xx_xy_xy_xx = buffer_dddd[42];

    auto g_xx_xy_xy_xy = buffer_dddd[43];

    auto g_xx_xy_xy_xz = buffer_dddd[44];

    auto g_xx_xy_xy_yy = buffer_dddd[45];

    auto g_xx_xy_xy_yz = buffer_dddd[46];

    auto g_xx_xy_xy_zz = buffer_dddd[47];

    auto g_xx_xy_xz_xx = buffer_dddd[48];

    auto g_xx_xy_xz_xy = buffer_dddd[49];

    auto g_xx_xy_xz_xz = buffer_dddd[50];

    auto g_xx_xy_xz_yy = buffer_dddd[51];

    auto g_xx_xy_xz_yz = buffer_dddd[52];

    auto g_xx_xy_xz_zz = buffer_dddd[53];

    auto g_xx_xy_yy_xx = buffer_dddd[54];

    auto g_xx_xy_yy_xy = buffer_dddd[55];

    auto g_xx_xy_yy_xz = buffer_dddd[56];

    auto g_xx_xy_yy_yy = buffer_dddd[57];

    auto g_xx_xy_yy_yz = buffer_dddd[58];

    auto g_xx_xy_yy_zz = buffer_dddd[59];

    auto g_xx_xy_yz_xx = buffer_dddd[60];

    auto g_xx_xy_yz_xy = buffer_dddd[61];

    auto g_xx_xy_yz_xz = buffer_dddd[62];

    auto g_xx_xy_yz_yy = buffer_dddd[63];

    auto g_xx_xy_yz_yz = buffer_dddd[64];

    auto g_xx_xy_yz_zz = buffer_dddd[65];

    auto g_xx_xy_zz_xx = buffer_dddd[66];

    auto g_xx_xy_zz_xy = buffer_dddd[67];

    auto g_xx_xy_zz_xz = buffer_dddd[68];

    auto g_xx_xy_zz_yy = buffer_dddd[69];

    auto g_xx_xy_zz_yz = buffer_dddd[70];

    auto g_xx_xy_zz_zz = buffer_dddd[71];

    auto g_xx_xz_xx_xx = buffer_dddd[72];

    auto g_xx_xz_xx_xy = buffer_dddd[73];

    auto g_xx_xz_xx_xz = buffer_dddd[74];

    auto g_xx_xz_xx_yy = buffer_dddd[75];

    auto g_xx_xz_xx_yz = buffer_dddd[76];

    auto g_xx_xz_xx_zz = buffer_dddd[77];

    auto g_xx_xz_xy_xx = buffer_dddd[78];

    auto g_xx_xz_xy_xy = buffer_dddd[79];

    auto g_xx_xz_xy_xz = buffer_dddd[80];

    auto g_xx_xz_xy_yy = buffer_dddd[81];

    auto g_xx_xz_xy_yz = buffer_dddd[82];

    auto g_xx_xz_xy_zz = buffer_dddd[83];

    auto g_xx_xz_xz_xx = buffer_dddd[84];

    auto g_xx_xz_xz_xy = buffer_dddd[85];

    auto g_xx_xz_xz_xz = buffer_dddd[86];

    auto g_xx_xz_xz_yy = buffer_dddd[87];

    auto g_xx_xz_xz_yz = buffer_dddd[88];

    auto g_xx_xz_xz_zz = buffer_dddd[89];

    auto g_xx_xz_yy_xx = buffer_dddd[90];

    auto g_xx_xz_yy_xy = buffer_dddd[91];

    auto g_xx_xz_yy_xz = buffer_dddd[92];

    auto g_xx_xz_yy_yy = buffer_dddd[93];

    auto g_xx_xz_yy_yz = buffer_dddd[94];

    auto g_xx_xz_yy_zz = buffer_dddd[95];

    auto g_xx_xz_yz_xx = buffer_dddd[96];

    auto g_xx_xz_yz_xy = buffer_dddd[97];

    auto g_xx_xz_yz_xz = buffer_dddd[98];

    auto g_xx_xz_yz_yy = buffer_dddd[99];

    auto g_xx_xz_yz_yz = buffer_dddd[100];

    auto g_xx_xz_yz_zz = buffer_dddd[101];

    auto g_xx_xz_zz_xx = buffer_dddd[102];

    auto g_xx_xz_zz_xy = buffer_dddd[103];

    auto g_xx_xz_zz_xz = buffer_dddd[104];

    auto g_xx_xz_zz_yy = buffer_dddd[105];

    auto g_xx_xz_zz_yz = buffer_dddd[106];

    auto g_xx_xz_zz_zz = buffer_dddd[107];

    auto g_xx_yy_xx_xx = buffer_dddd[108];

    auto g_xx_yy_xx_xy = buffer_dddd[109];

    auto g_xx_yy_xx_xz = buffer_dddd[110];

    auto g_xx_yy_xx_yy = buffer_dddd[111];

    auto g_xx_yy_xx_yz = buffer_dddd[112];

    auto g_xx_yy_xx_zz = buffer_dddd[113];

    auto g_xx_yy_xy_xx = buffer_dddd[114];

    auto g_xx_yy_xy_xy = buffer_dddd[115];

    auto g_xx_yy_xy_xz = buffer_dddd[116];

    auto g_xx_yy_xy_yy = buffer_dddd[117];

    auto g_xx_yy_xy_yz = buffer_dddd[118];

    auto g_xx_yy_xy_zz = buffer_dddd[119];

    auto g_xx_yy_xz_xx = buffer_dddd[120];

    auto g_xx_yy_xz_xy = buffer_dddd[121];

    auto g_xx_yy_xz_xz = buffer_dddd[122];

    auto g_xx_yy_xz_yy = buffer_dddd[123];

    auto g_xx_yy_xz_yz = buffer_dddd[124];

    auto g_xx_yy_xz_zz = buffer_dddd[125];

    auto g_xx_yy_yy_xx = buffer_dddd[126];

    auto g_xx_yy_yy_xy = buffer_dddd[127];

    auto g_xx_yy_yy_xz = buffer_dddd[128];

    auto g_xx_yy_yy_yy = buffer_dddd[129];

    auto g_xx_yy_yy_yz = buffer_dddd[130];

    auto g_xx_yy_yy_zz = buffer_dddd[131];

    auto g_xx_yy_yz_xx = buffer_dddd[132];

    auto g_xx_yy_yz_xy = buffer_dddd[133];

    auto g_xx_yy_yz_xz = buffer_dddd[134];

    auto g_xx_yy_yz_yy = buffer_dddd[135];

    auto g_xx_yy_yz_yz = buffer_dddd[136];

    auto g_xx_yy_yz_zz = buffer_dddd[137];

    auto g_xx_yy_zz_xx = buffer_dddd[138];

    auto g_xx_yy_zz_xy = buffer_dddd[139];

    auto g_xx_yy_zz_xz = buffer_dddd[140];

    auto g_xx_yy_zz_yy = buffer_dddd[141];

    auto g_xx_yy_zz_yz = buffer_dddd[142];

    auto g_xx_yy_zz_zz = buffer_dddd[143];

    auto g_xx_yz_xx_xx = buffer_dddd[144];

    auto g_xx_yz_xx_xy = buffer_dddd[145];

    auto g_xx_yz_xx_xz = buffer_dddd[146];

    auto g_xx_yz_xx_yy = buffer_dddd[147];

    auto g_xx_yz_xx_yz = buffer_dddd[148];

    auto g_xx_yz_xx_zz = buffer_dddd[149];

    auto g_xx_yz_xy_xx = buffer_dddd[150];

    auto g_xx_yz_xy_xy = buffer_dddd[151];

    auto g_xx_yz_xy_xz = buffer_dddd[152];

    auto g_xx_yz_xy_yy = buffer_dddd[153];

    auto g_xx_yz_xy_yz = buffer_dddd[154];

    auto g_xx_yz_xy_zz = buffer_dddd[155];

    auto g_xx_yz_xz_xx = buffer_dddd[156];

    auto g_xx_yz_xz_xy = buffer_dddd[157];

    auto g_xx_yz_xz_xz = buffer_dddd[158];

    auto g_xx_yz_xz_yy = buffer_dddd[159];

    auto g_xx_yz_xz_yz = buffer_dddd[160];

    auto g_xx_yz_xz_zz = buffer_dddd[161];

    auto g_xx_yz_yy_xx = buffer_dddd[162];

    auto g_xx_yz_yy_xy = buffer_dddd[163];

    auto g_xx_yz_yy_xz = buffer_dddd[164];

    auto g_xx_yz_yy_yy = buffer_dddd[165];

    auto g_xx_yz_yy_yz = buffer_dddd[166];

    auto g_xx_yz_yy_zz = buffer_dddd[167];

    auto g_xx_yz_yz_xx = buffer_dddd[168];

    auto g_xx_yz_yz_xy = buffer_dddd[169];

    auto g_xx_yz_yz_xz = buffer_dddd[170];

    auto g_xx_yz_yz_yy = buffer_dddd[171];

    auto g_xx_yz_yz_yz = buffer_dddd[172];

    auto g_xx_yz_yz_zz = buffer_dddd[173];

    auto g_xx_yz_zz_xx = buffer_dddd[174];

    auto g_xx_yz_zz_xy = buffer_dddd[175];

    auto g_xx_yz_zz_xz = buffer_dddd[176];

    auto g_xx_yz_zz_yy = buffer_dddd[177];

    auto g_xx_yz_zz_yz = buffer_dddd[178];

    auto g_xx_yz_zz_zz = buffer_dddd[179];

    auto g_xx_zz_xx_xx = buffer_dddd[180];

    auto g_xx_zz_xx_xy = buffer_dddd[181];

    auto g_xx_zz_xx_xz = buffer_dddd[182];

    auto g_xx_zz_xx_yy = buffer_dddd[183];

    auto g_xx_zz_xx_yz = buffer_dddd[184];

    auto g_xx_zz_xx_zz = buffer_dddd[185];

    auto g_xx_zz_xy_xx = buffer_dddd[186];

    auto g_xx_zz_xy_xy = buffer_dddd[187];

    auto g_xx_zz_xy_xz = buffer_dddd[188];

    auto g_xx_zz_xy_yy = buffer_dddd[189];

    auto g_xx_zz_xy_yz = buffer_dddd[190];

    auto g_xx_zz_xy_zz = buffer_dddd[191];

    auto g_xx_zz_xz_xx = buffer_dddd[192];

    auto g_xx_zz_xz_xy = buffer_dddd[193];

    auto g_xx_zz_xz_xz = buffer_dddd[194];

    auto g_xx_zz_xz_yy = buffer_dddd[195];

    auto g_xx_zz_xz_yz = buffer_dddd[196];

    auto g_xx_zz_xz_zz = buffer_dddd[197];

    auto g_xx_zz_yy_xx = buffer_dddd[198];

    auto g_xx_zz_yy_xy = buffer_dddd[199];

    auto g_xx_zz_yy_xz = buffer_dddd[200];

    auto g_xx_zz_yy_yy = buffer_dddd[201];

    auto g_xx_zz_yy_yz = buffer_dddd[202];

    auto g_xx_zz_yy_zz = buffer_dddd[203];

    auto g_xx_zz_yz_xx = buffer_dddd[204];

    auto g_xx_zz_yz_xy = buffer_dddd[205];

    auto g_xx_zz_yz_xz = buffer_dddd[206];

    auto g_xx_zz_yz_yy = buffer_dddd[207];

    auto g_xx_zz_yz_yz = buffer_dddd[208];

    auto g_xx_zz_yz_zz = buffer_dddd[209];

    auto g_xx_zz_zz_xx = buffer_dddd[210];

    auto g_xx_zz_zz_xy = buffer_dddd[211];

    auto g_xx_zz_zz_xz = buffer_dddd[212];

    auto g_xx_zz_zz_yy = buffer_dddd[213];

    auto g_xx_zz_zz_yz = buffer_dddd[214];

    auto g_xx_zz_zz_zz = buffer_dddd[215];

    auto g_xy_xx_xx_xx = buffer_dddd[216];

    auto g_xy_xx_xx_xy = buffer_dddd[217];

    auto g_xy_xx_xx_xz = buffer_dddd[218];

    auto g_xy_xx_xx_yy = buffer_dddd[219];

    auto g_xy_xx_xx_yz = buffer_dddd[220];

    auto g_xy_xx_xx_zz = buffer_dddd[221];

    auto g_xy_xx_xy_xx = buffer_dddd[222];

    auto g_xy_xx_xy_xy = buffer_dddd[223];

    auto g_xy_xx_xy_xz = buffer_dddd[224];

    auto g_xy_xx_xy_yy = buffer_dddd[225];

    auto g_xy_xx_xy_yz = buffer_dddd[226];

    auto g_xy_xx_xy_zz = buffer_dddd[227];

    auto g_xy_xx_xz_xx = buffer_dddd[228];

    auto g_xy_xx_xz_xy = buffer_dddd[229];

    auto g_xy_xx_xz_xz = buffer_dddd[230];

    auto g_xy_xx_xz_yy = buffer_dddd[231];

    auto g_xy_xx_xz_yz = buffer_dddd[232];

    auto g_xy_xx_xz_zz = buffer_dddd[233];

    auto g_xy_xx_yy_xx = buffer_dddd[234];

    auto g_xy_xx_yy_xy = buffer_dddd[235];

    auto g_xy_xx_yy_xz = buffer_dddd[236];

    auto g_xy_xx_yy_yy = buffer_dddd[237];

    auto g_xy_xx_yy_yz = buffer_dddd[238];

    auto g_xy_xx_yy_zz = buffer_dddd[239];

    auto g_xy_xx_yz_xx = buffer_dddd[240];

    auto g_xy_xx_yz_xy = buffer_dddd[241];

    auto g_xy_xx_yz_xz = buffer_dddd[242];

    auto g_xy_xx_yz_yy = buffer_dddd[243];

    auto g_xy_xx_yz_yz = buffer_dddd[244];

    auto g_xy_xx_yz_zz = buffer_dddd[245];

    auto g_xy_xx_zz_xx = buffer_dddd[246];

    auto g_xy_xx_zz_xy = buffer_dddd[247];

    auto g_xy_xx_zz_xz = buffer_dddd[248];

    auto g_xy_xx_zz_yy = buffer_dddd[249];

    auto g_xy_xx_zz_yz = buffer_dddd[250];

    auto g_xy_xx_zz_zz = buffer_dddd[251];

    auto g_xy_xy_xx_xx = buffer_dddd[252];

    auto g_xy_xy_xx_xy = buffer_dddd[253];

    auto g_xy_xy_xx_xz = buffer_dddd[254];

    auto g_xy_xy_xx_yy = buffer_dddd[255];

    auto g_xy_xy_xx_yz = buffer_dddd[256];

    auto g_xy_xy_xx_zz = buffer_dddd[257];

    auto g_xy_xy_xy_xx = buffer_dddd[258];

    auto g_xy_xy_xy_xy = buffer_dddd[259];

    auto g_xy_xy_xy_xz = buffer_dddd[260];

    auto g_xy_xy_xy_yy = buffer_dddd[261];

    auto g_xy_xy_xy_yz = buffer_dddd[262];

    auto g_xy_xy_xy_zz = buffer_dddd[263];

    auto g_xy_xy_xz_xx = buffer_dddd[264];

    auto g_xy_xy_xz_xy = buffer_dddd[265];

    auto g_xy_xy_xz_xz = buffer_dddd[266];

    auto g_xy_xy_xz_yy = buffer_dddd[267];

    auto g_xy_xy_xz_yz = buffer_dddd[268];

    auto g_xy_xy_xz_zz = buffer_dddd[269];

    auto g_xy_xy_yy_xx = buffer_dddd[270];

    auto g_xy_xy_yy_xy = buffer_dddd[271];

    auto g_xy_xy_yy_xz = buffer_dddd[272];

    auto g_xy_xy_yy_yy = buffer_dddd[273];

    auto g_xy_xy_yy_yz = buffer_dddd[274];

    auto g_xy_xy_yy_zz = buffer_dddd[275];

    auto g_xy_xy_yz_xx = buffer_dddd[276];

    auto g_xy_xy_yz_xy = buffer_dddd[277];

    auto g_xy_xy_yz_xz = buffer_dddd[278];

    auto g_xy_xy_yz_yy = buffer_dddd[279];

    auto g_xy_xy_yz_yz = buffer_dddd[280];

    auto g_xy_xy_yz_zz = buffer_dddd[281];

    auto g_xy_xy_zz_xx = buffer_dddd[282];

    auto g_xy_xy_zz_xy = buffer_dddd[283];

    auto g_xy_xy_zz_xz = buffer_dddd[284];

    auto g_xy_xy_zz_yy = buffer_dddd[285];

    auto g_xy_xy_zz_yz = buffer_dddd[286];

    auto g_xy_xy_zz_zz = buffer_dddd[287];

    auto g_xy_xz_xx_xx = buffer_dddd[288];

    auto g_xy_xz_xx_xy = buffer_dddd[289];

    auto g_xy_xz_xx_xz = buffer_dddd[290];

    auto g_xy_xz_xx_yy = buffer_dddd[291];

    auto g_xy_xz_xx_yz = buffer_dddd[292];

    auto g_xy_xz_xx_zz = buffer_dddd[293];

    auto g_xy_xz_xy_xx = buffer_dddd[294];

    auto g_xy_xz_xy_xy = buffer_dddd[295];

    auto g_xy_xz_xy_xz = buffer_dddd[296];

    auto g_xy_xz_xy_yy = buffer_dddd[297];

    auto g_xy_xz_xy_yz = buffer_dddd[298];

    auto g_xy_xz_xy_zz = buffer_dddd[299];

    auto g_xy_xz_xz_xx = buffer_dddd[300];

    auto g_xy_xz_xz_xy = buffer_dddd[301];

    auto g_xy_xz_xz_xz = buffer_dddd[302];

    auto g_xy_xz_xz_yy = buffer_dddd[303];

    auto g_xy_xz_xz_yz = buffer_dddd[304];

    auto g_xy_xz_xz_zz = buffer_dddd[305];

    auto g_xy_xz_yy_xx = buffer_dddd[306];

    auto g_xy_xz_yy_xy = buffer_dddd[307];

    auto g_xy_xz_yy_xz = buffer_dddd[308];

    auto g_xy_xz_yy_yy = buffer_dddd[309];

    auto g_xy_xz_yy_yz = buffer_dddd[310];

    auto g_xy_xz_yy_zz = buffer_dddd[311];

    auto g_xy_xz_yz_xx = buffer_dddd[312];

    auto g_xy_xz_yz_xy = buffer_dddd[313];

    auto g_xy_xz_yz_xz = buffer_dddd[314];

    auto g_xy_xz_yz_yy = buffer_dddd[315];

    auto g_xy_xz_yz_yz = buffer_dddd[316];

    auto g_xy_xz_yz_zz = buffer_dddd[317];

    auto g_xy_xz_zz_xx = buffer_dddd[318];

    auto g_xy_xz_zz_xy = buffer_dddd[319];

    auto g_xy_xz_zz_xz = buffer_dddd[320];

    auto g_xy_xz_zz_yy = buffer_dddd[321];

    auto g_xy_xz_zz_yz = buffer_dddd[322];

    auto g_xy_xz_zz_zz = buffer_dddd[323];

    auto g_xy_yy_xx_xx = buffer_dddd[324];

    auto g_xy_yy_xx_xy = buffer_dddd[325];

    auto g_xy_yy_xx_xz = buffer_dddd[326];

    auto g_xy_yy_xx_yy = buffer_dddd[327];

    auto g_xy_yy_xx_yz = buffer_dddd[328];

    auto g_xy_yy_xx_zz = buffer_dddd[329];

    auto g_xy_yy_xy_xx = buffer_dddd[330];

    auto g_xy_yy_xy_xy = buffer_dddd[331];

    auto g_xy_yy_xy_xz = buffer_dddd[332];

    auto g_xy_yy_xy_yy = buffer_dddd[333];

    auto g_xy_yy_xy_yz = buffer_dddd[334];

    auto g_xy_yy_xy_zz = buffer_dddd[335];

    auto g_xy_yy_xz_xx = buffer_dddd[336];

    auto g_xy_yy_xz_xy = buffer_dddd[337];

    auto g_xy_yy_xz_xz = buffer_dddd[338];

    auto g_xy_yy_xz_yy = buffer_dddd[339];

    auto g_xy_yy_xz_yz = buffer_dddd[340];

    auto g_xy_yy_xz_zz = buffer_dddd[341];

    auto g_xy_yy_yy_xx = buffer_dddd[342];

    auto g_xy_yy_yy_xy = buffer_dddd[343];

    auto g_xy_yy_yy_xz = buffer_dddd[344];

    auto g_xy_yy_yy_yy = buffer_dddd[345];

    auto g_xy_yy_yy_yz = buffer_dddd[346];

    auto g_xy_yy_yy_zz = buffer_dddd[347];

    auto g_xy_yy_yz_xx = buffer_dddd[348];

    auto g_xy_yy_yz_xy = buffer_dddd[349];

    auto g_xy_yy_yz_xz = buffer_dddd[350];

    auto g_xy_yy_yz_yy = buffer_dddd[351];

    auto g_xy_yy_yz_yz = buffer_dddd[352];

    auto g_xy_yy_yz_zz = buffer_dddd[353];

    auto g_xy_yy_zz_xx = buffer_dddd[354];

    auto g_xy_yy_zz_xy = buffer_dddd[355];

    auto g_xy_yy_zz_xz = buffer_dddd[356];

    auto g_xy_yy_zz_yy = buffer_dddd[357];

    auto g_xy_yy_zz_yz = buffer_dddd[358];

    auto g_xy_yy_zz_zz = buffer_dddd[359];

    auto g_xy_yz_xx_xx = buffer_dddd[360];

    auto g_xy_yz_xx_xy = buffer_dddd[361];

    auto g_xy_yz_xx_xz = buffer_dddd[362];

    auto g_xy_yz_xx_yy = buffer_dddd[363];

    auto g_xy_yz_xx_yz = buffer_dddd[364];

    auto g_xy_yz_xx_zz = buffer_dddd[365];

    auto g_xy_yz_xy_xx = buffer_dddd[366];

    auto g_xy_yz_xy_xy = buffer_dddd[367];

    auto g_xy_yz_xy_xz = buffer_dddd[368];

    auto g_xy_yz_xy_yy = buffer_dddd[369];

    auto g_xy_yz_xy_yz = buffer_dddd[370];

    auto g_xy_yz_xy_zz = buffer_dddd[371];

    auto g_xy_yz_xz_xx = buffer_dddd[372];

    auto g_xy_yz_xz_xy = buffer_dddd[373];

    auto g_xy_yz_xz_xz = buffer_dddd[374];

    auto g_xy_yz_xz_yy = buffer_dddd[375];

    auto g_xy_yz_xz_yz = buffer_dddd[376];

    auto g_xy_yz_xz_zz = buffer_dddd[377];

    auto g_xy_yz_yy_xx = buffer_dddd[378];

    auto g_xy_yz_yy_xy = buffer_dddd[379];

    auto g_xy_yz_yy_xz = buffer_dddd[380];

    auto g_xy_yz_yy_yy = buffer_dddd[381];

    auto g_xy_yz_yy_yz = buffer_dddd[382];

    auto g_xy_yz_yy_zz = buffer_dddd[383];

    auto g_xy_yz_yz_xx = buffer_dddd[384];

    auto g_xy_yz_yz_xy = buffer_dddd[385];

    auto g_xy_yz_yz_xz = buffer_dddd[386];

    auto g_xy_yz_yz_yy = buffer_dddd[387];

    auto g_xy_yz_yz_yz = buffer_dddd[388];

    auto g_xy_yz_yz_zz = buffer_dddd[389];

    auto g_xy_yz_zz_xx = buffer_dddd[390];

    auto g_xy_yz_zz_xy = buffer_dddd[391];

    auto g_xy_yz_zz_xz = buffer_dddd[392];

    auto g_xy_yz_zz_yy = buffer_dddd[393];

    auto g_xy_yz_zz_yz = buffer_dddd[394];

    auto g_xy_yz_zz_zz = buffer_dddd[395];

    auto g_xy_zz_xx_xx = buffer_dddd[396];

    auto g_xy_zz_xx_xy = buffer_dddd[397];

    auto g_xy_zz_xx_xz = buffer_dddd[398];

    auto g_xy_zz_xx_yy = buffer_dddd[399];

    auto g_xy_zz_xx_yz = buffer_dddd[400];

    auto g_xy_zz_xx_zz = buffer_dddd[401];

    auto g_xy_zz_xy_xx = buffer_dddd[402];

    auto g_xy_zz_xy_xy = buffer_dddd[403];

    auto g_xy_zz_xy_xz = buffer_dddd[404];

    auto g_xy_zz_xy_yy = buffer_dddd[405];

    auto g_xy_zz_xy_yz = buffer_dddd[406];

    auto g_xy_zz_xy_zz = buffer_dddd[407];

    auto g_xy_zz_xz_xx = buffer_dddd[408];

    auto g_xy_zz_xz_xy = buffer_dddd[409];

    auto g_xy_zz_xz_xz = buffer_dddd[410];

    auto g_xy_zz_xz_yy = buffer_dddd[411];

    auto g_xy_zz_xz_yz = buffer_dddd[412];

    auto g_xy_zz_xz_zz = buffer_dddd[413];

    auto g_xy_zz_yy_xx = buffer_dddd[414];

    auto g_xy_zz_yy_xy = buffer_dddd[415];

    auto g_xy_zz_yy_xz = buffer_dddd[416];

    auto g_xy_zz_yy_yy = buffer_dddd[417];

    auto g_xy_zz_yy_yz = buffer_dddd[418];

    auto g_xy_zz_yy_zz = buffer_dddd[419];

    auto g_xy_zz_yz_xx = buffer_dddd[420];

    auto g_xy_zz_yz_xy = buffer_dddd[421];

    auto g_xy_zz_yz_xz = buffer_dddd[422];

    auto g_xy_zz_yz_yy = buffer_dddd[423];

    auto g_xy_zz_yz_yz = buffer_dddd[424];

    auto g_xy_zz_yz_zz = buffer_dddd[425];

    auto g_xy_zz_zz_xx = buffer_dddd[426];

    auto g_xy_zz_zz_xy = buffer_dddd[427];

    auto g_xy_zz_zz_xz = buffer_dddd[428];

    auto g_xy_zz_zz_yy = buffer_dddd[429];

    auto g_xy_zz_zz_yz = buffer_dddd[430];

    auto g_xy_zz_zz_zz = buffer_dddd[431];

    auto g_xz_xx_xx_xx = buffer_dddd[432];

    auto g_xz_xx_xx_xy = buffer_dddd[433];

    auto g_xz_xx_xx_xz = buffer_dddd[434];

    auto g_xz_xx_xx_yy = buffer_dddd[435];

    auto g_xz_xx_xx_yz = buffer_dddd[436];

    auto g_xz_xx_xx_zz = buffer_dddd[437];

    auto g_xz_xx_xy_xx = buffer_dddd[438];

    auto g_xz_xx_xy_xy = buffer_dddd[439];

    auto g_xz_xx_xy_xz = buffer_dddd[440];

    auto g_xz_xx_xy_yy = buffer_dddd[441];

    auto g_xz_xx_xy_yz = buffer_dddd[442];

    auto g_xz_xx_xy_zz = buffer_dddd[443];

    auto g_xz_xx_xz_xx = buffer_dddd[444];

    auto g_xz_xx_xz_xy = buffer_dddd[445];

    auto g_xz_xx_xz_xz = buffer_dddd[446];

    auto g_xz_xx_xz_yy = buffer_dddd[447];

    auto g_xz_xx_xz_yz = buffer_dddd[448];

    auto g_xz_xx_xz_zz = buffer_dddd[449];

    auto g_xz_xx_yy_xx = buffer_dddd[450];

    auto g_xz_xx_yy_xy = buffer_dddd[451];

    auto g_xz_xx_yy_xz = buffer_dddd[452];

    auto g_xz_xx_yy_yy = buffer_dddd[453];

    auto g_xz_xx_yy_yz = buffer_dddd[454];

    auto g_xz_xx_yy_zz = buffer_dddd[455];

    auto g_xz_xx_yz_xx = buffer_dddd[456];

    auto g_xz_xx_yz_xy = buffer_dddd[457];

    auto g_xz_xx_yz_xz = buffer_dddd[458];

    auto g_xz_xx_yz_yy = buffer_dddd[459];

    auto g_xz_xx_yz_yz = buffer_dddd[460];

    auto g_xz_xx_yz_zz = buffer_dddd[461];

    auto g_xz_xx_zz_xx = buffer_dddd[462];

    auto g_xz_xx_zz_xy = buffer_dddd[463];

    auto g_xz_xx_zz_xz = buffer_dddd[464];

    auto g_xz_xx_zz_yy = buffer_dddd[465];

    auto g_xz_xx_zz_yz = buffer_dddd[466];

    auto g_xz_xx_zz_zz = buffer_dddd[467];

    auto g_xz_xy_xx_xx = buffer_dddd[468];

    auto g_xz_xy_xx_xy = buffer_dddd[469];

    auto g_xz_xy_xx_xz = buffer_dddd[470];

    auto g_xz_xy_xx_yy = buffer_dddd[471];

    auto g_xz_xy_xx_yz = buffer_dddd[472];

    auto g_xz_xy_xx_zz = buffer_dddd[473];

    auto g_xz_xy_xy_xx = buffer_dddd[474];

    auto g_xz_xy_xy_xy = buffer_dddd[475];

    auto g_xz_xy_xy_xz = buffer_dddd[476];

    auto g_xz_xy_xy_yy = buffer_dddd[477];

    auto g_xz_xy_xy_yz = buffer_dddd[478];

    auto g_xz_xy_xy_zz = buffer_dddd[479];

    auto g_xz_xy_xz_xx = buffer_dddd[480];

    auto g_xz_xy_xz_xy = buffer_dddd[481];

    auto g_xz_xy_xz_xz = buffer_dddd[482];

    auto g_xz_xy_xz_yy = buffer_dddd[483];

    auto g_xz_xy_xz_yz = buffer_dddd[484];

    auto g_xz_xy_xz_zz = buffer_dddd[485];

    auto g_xz_xy_yy_xx = buffer_dddd[486];

    auto g_xz_xy_yy_xy = buffer_dddd[487];

    auto g_xz_xy_yy_xz = buffer_dddd[488];

    auto g_xz_xy_yy_yy = buffer_dddd[489];

    auto g_xz_xy_yy_yz = buffer_dddd[490];

    auto g_xz_xy_yy_zz = buffer_dddd[491];

    auto g_xz_xy_yz_xx = buffer_dddd[492];

    auto g_xz_xy_yz_xy = buffer_dddd[493];

    auto g_xz_xy_yz_xz = buffer_dddd[494];

    auto g_xz_xy_yz_yy = buffer_dddd[495];

    auto g_xz_xy_yz_yz = buffer_dddd[496];

    auto g_xz_xy_yz_zz = buffer_dddd[497];

    auto g_xz_xy_zz_xx = buffer_dddd[498];

    auto g_xz_xy_zz_xy = buffer_dddd[499];

    auto g_xz_xy_zz_xz = buffer_dddd[500];

    auto g_xz_xy_zz_yy = buffer_dddd[501];

    auto g_xz_xy_zz_yz = buffer_dddd[502];

    auto g_xz_xy_zz_zz = buffer_dddd[503];

    auto g_xz_xz_xx_xx = buffer_dddd[504];

    auto g_xz_xz_xx_xy = buffer_dddd[505];

    auto g_xz_xz_xx_xz = buffer_dddd[506];

    auto g_xz_xz_xx_yy = buffer_dddd[507];

    auto g_xz_xz_xx_yz = buffer_dddd[508];

    auto g_xz_xz_xx_zz = buffer_dddd[509];

    auto g_xz_xz_xy_xx = buffer_dddd[510];

    auto g_xz_xz_xy_xy = buffer_dddd[511];

    auto g_xz_xz_xy_xz = buffer_dddd[512];

    auto g_xz_xz_xy_yy = buffer_dddd[513];

    auto g_xz_xz_xy_yz = buffer_dddd[514];

    auto g_xz_xz_xy_zz = buffer_dddd[515];

    auto g_xz_xz_xz_xx = buffer_dddd[516];

    auto g_xz_xz_xz_xy = buffer_dddd[517];

    auto g_xz_xz_xz_xz = buffer_dddd[518];

    auto g_xz_xz_xz_yy = buffer_dddd[519];

    auto g_xz_xz_xz_yz = buffer_dddd[520];

    auto g_xz_xz_xz_zz = buffer_dddd[521];

    auto g_xz_xz_yy_xx = buffer_dddd[522];

    auto g_xz_xz_yy_xy = buffer_dddd[523];

    auto g_xz_xz_yy_xz = buffer_dddd[524];

    auto g_xz_xz_yy_yy = buffer_dddd[525];

    auto g_xz_xz_yy_yz = buffer_dddd[526];

    auto g_xz_xz_yy_zz = buffer_dddd[527];

    auto g_xz_xz_yz_xx = buffer_dddd[528];

    auto g_xz_xz_yz_xy = buffer_dddd[529];

    auto g_xz_xz_yz_xz = buffer_dddd[530];

    auto g_xz_xz_yz_yy = buffer_dddd[531];

    auto g_xz_xz_yz_yz = buffer_dddd[532];

    auto g_xz_xz_yz_zz = buffer_dddd[533];

    auto g_xz_xz_zz_xx = buffer_dddd[534];

    auto g_xz_xz_zz_xy = buffer_dddd[535];

    auto g_xz_xz_zz_xz = buffer_dddd[536];

    auto g_xz_xz_zz_yy = buffer_dddd[537];

    auto g_xz_xz_zz_yz = buffer_dddd[538];

    auto g_xz_xz_zz_zz = buffer_dddd[539];

    auto g_xz_yy_xx_xx = buffer_dddd[540];

    auto g_xz_yy_xx_xy = buffer_dddd[541];

    auto g_xz_yy_xx_xz = buffer_dddd[542];

    auto g_xz_yy_xx_yy = buffer_dddd[543];

    auto g_xz_yy_xx_yz = buffer_dddd[544];

    auto g_xz_yy_xx_zz = buffer_dddd[545];

    auto g_xz_yy_xy_xx = buffer_dddd[546];

    auto g_xz_yy_xy_xy = buffer_dddd[547];

    auto g_xz_yy_xy_xz = buffer_dddd[548];

    auto g_xz_yy_xy_yy = buffer_dddd[549];

    auto g_xz_yy_xy_yz = buffer_dddd[550];

    auto g_xz_yy_xy_zz = buffer_dddd[551];

    auto g_xz_yy_xz_xx = buffer_dddd[552];

    auto g_xz_yy_xz_xy = buffer_dddd[553];

    auto g_xz_yy_xz_xz = buffer_dddd[554];

    auto g_xz_yy_xz_yy = buffer_dddd[555];

    auto g_xz_yy_xz_yz = buffer_dddd[556];

    auto g_xz_yy_xz_zz = buffer_dddd[557];

    auto g_xz_yy_yy_xx = buffer_dddd[558];

    auto g_xz_yy_yy_xy = buffer_dddd[559];

    auto g_xz_yy_yy_xz = buffer_dddd[560];

    auto g_xz_yy_yy_yy = buffer_dddd[561];

    auto g_xz_yy_yy_yz = buffer_dddd[562];

    auto g_xz_yy_yy_zz = buffer_dddd[563];

    auto g_xz_yy_yz_xx = buffer_dddd[564];

    auto g_xz_yy_yz_xy = buffer_dddd[565];

    auto g_xz_yy_yz_xz = buffer_dddd[566];

    auto g_xz_yy_yz_yy = buffer_dddd[567];

    auto g_xz_yy_yz_yz = buffer_dddd[568];

    auto g_xz_yy_yz_zz = buffer_dddd[569];

    auto g_xz_yy_zz_xx = buffer_dddd[570];

    auto g_xz_yy_zz_xy = buffer_dddd[571];

    auto g_xz_yy_zz_xz = buffer_dddd[572];

    auto g_xz_yy_zz_yy = buffer_dddd[573];

    auto g_xz_yy_zz_yz = buffer_dddd[574];

    auto g_xz_yy_zz_zz = buffer_dddd[575];

    auto g_xz_yz_xx_xx = buffer_dddd[576];

    auto g_xz_yz_xx_xy = buffer_dddd[577];

    auto g_xz_yz_xx_xz = buffer_dddd[578];

    auto g_xz_yz_xx_yy = buffer_dddd[579];

    auto g_xz_yz_xx_yz = buffer_dddd[580];

    auto g_xz_yz_xx_zz = buffer_dddd[581];

    auto g_xz_yz_xy_xx = buffer_dddd[582];

    auto g_xz_yz_xy_xy = buffer_dddd[583];

    auto g_xz_yz_xy_xz = buffer_dddd[584];

    auto g_xz_yz_xy_yy = buffer_dddd[585];

    auto g_xz_yz_xy_yz = buffer_dddd[586];

    auto g_xz_yz_xy_zz = buffer_dddd[587];

    auto g_xz_yz_xz_xx = buffer_dddd[588];

    auto g_xz_yz_xz_xy = buffer_dddd[589];

    auto g_xz_yz_xz_xz = buffer_dddd[590];

    auto g_xz_yz_xz_yy = buffer_dddd[591];

    auto g_xz_yz_xz_yz = buffer_dddd[592];

    auto g_xz_yz_xz_zz = buffer_dddd[593];

    auto g_xz_yz_yy_xx = buffer_dddd[594];

    auto g_xz_yz_yy_xy = buffer_dddd[595];

    auto g_xz_yz_yy_xz = buffer_dddd[596];

    auto g_xz_yz_yy_yy = buffer_dddd[597];

    auto g_xz_yz_yy_yz = buffer_dddd[598];

    auto g_xz_yz_yy_zz = buffer_dddd[599];

    auto g_xz_yz_yz_xx = buffer_dddd[600];

    auto g_xz_yz_yz_xy = buffer_dddd[601];

    auto g_xz_yz_yz_xz = buffer_dddd[602];

    auto g_xz_yz_yz_yy = buffer_dddd[603];

    auto g_xz_yz_yz_yz = buffer_dddd[604];

    auto g_xz_yz_yz_zz = buffer_dddd[605];

    auto g_xz_yz_zz_xx = buffer_dddd[606];

    auto g_xz_yz_zz_xy = buffer_dddd[607];

    auto g_xz_yz_zz_xz = buffer_dddd[608];

    auto g_xz_yz_zz_yy = buffer_dddd[609];

    auto g_xz_yz_zz_yz = buffer_dddd[610];

    auto g_xz_yz_zz_zz = buffer_dddd[611];

    auto g_xz_zz_xx_xx = buffer_dddd[612];

    auto g_xz_zz_xx_xy = buffer_dddd[613];

    auto g_xz_zz_xx_xz = buffer_dddd[614];

    auto g_xz_zz_xx_yy = buffer_dddd[615];

    auto g_xz_zz_xx_yz = buffer_dddd[616];

    auto g_xz_zz_xx_zz = buffer_dddd[617];

    auto g_xz_zz_xy_xx = buffer_dddd[618];

    auto g_xz_zz_xy_xy = buffer_dddd[619];

    auto g_xz_zz_xy_xz = buffer_dddd[620];

    auto g_xz_zz_xy_yy = buffer_dddd[621];

    auto g_xz_zz_xy_yz = buffer_dddd[622];

    auto g_xz_zz_xy_zz = buffer_dddd[623];

    auto g_xz_zz_xz_xx = buffer_dddd[624];

    auto g_xz_zz_xz_xy = buffer_dddd[625];

    auto g_xz_zz_xz_xz = buffer_dddd[626];

    auto g_xz_zz_xz_yy = buffer_dddd[627];

    auto g_xz_zz_xz_yz = buffer_dddd[628];

    auto g_xz_zz_xz_zz = buffer_dddd[629];

    auto g_xz_zz_yy_xx = buffer_dddd[630];

    auto g_xz_zz_yy_xy = buffer_dddd[631];

    auto g_xz_zz_yy_xz = buffer_dddd[632];

    auto g_xz_zz_yy_yy = buffer_dddd[633];

    auto g_xz_zz_yy_yz = buffer_dddd[634];

    auto g_xz_zz_yy_zz = buffer_dddd[635];

    auto g_xz_zz_yz_xx = buffer_dddd[636];

    auto g_xz_zz_yz_xy = buffer_dddd[637];

    auto g_xz_zz_yz_xz = buffer_dddd[638];

    auto g_xz_zz_yz_yy = buffer_dddd[639];

    auto g_xz_zz_yz_yz = buffer_dddd[640];

    auto g_xz_zz_yz_zz = buffer_dddd[641];

    auto g_xz_zz_zz_xx = buffer_dddd[642];

    auto g_xz_zz_zz_xy = buffer_dddd[643];

    auto g_xz_zz_zz_xz = buffer_dddd[644];

    auto g_xz_zz_zz_yy = buffer_dddd[645];

    auto g_xz_zz_zz_yz = buffer_dddd[646];

    auto g_xz_zz_zz_zz = buffer_dddd[647];

    auto g_yy_xx_xx_xx = buffer_dddd[648];

    auto g_yy_xx_xx_xy = buffer_dddd[649];

    auto g_yy_xx_xx_xz = buffer_dddd[650];

    auto g_yy_xx_xx_yy = buffer_dddd[651];

    auto g_yy_xx_xx_yz = buffer_dddd[652];

    auto g_yy_xx_xx_zz = buffer_dddd[653];

    auto g_yy_xx_xy_xx = buffer_dddd[654];

    auto g_yy_xx_xy_xy = buffer_dddd[655];

    auto g_yy_xx_xy_xz = buffer_dddd[656];

    auto g_yy_xx_xy_yy = buffer_dddd[657];

    auto g_yy_xx_xy_yz = buffer_dddd[658];

    auto g_yy_xx_xy_zz = buffer_dddd[659];

    auto g_yy_xx_xz_xx = buffer_dddd[660];

    auto g_yy_xx_xz_xy = buffer_dddd[661];

    auto g_yy_xx_xz_xz = buffer_dddd[662];

    auto g_yy_xx_xz_yy = buffer_dddd[663];

    auto g_yy_xx_xz_yz = buffer_dddd[664];

    auto g_yy_xx_xz_zz = buffer_dddd[665];

    auto g_yy_xx_yy_xx = buffer_dddd[666];

    auto g_yy_xx_yy_xy = buffer_dddd[667];

    auto g_yy_xx_yy_xz = buffer_dddd[668];

    auto g_yy_xx_yy_yy = buffer_dddd[669];

    auto g_yy_xx_yy_yz = buffer_dddd[670];

    auto g_yy_xx_yy_zz = buffer_dddd[671];

    auto g_yy_xx_yz_xx = buffer_dddd[672];

    auto g_yy_xx_yz_xy = buffer_dddd[673];

    auto g_yy_xx_yz_xz = buffer_dddd[674];

    auto g_yy_xx_yz_yy = buffer_dddd[675];

    auto g_yy_xx_yz_yz = buffer_dddd[676];

    auto g_yy_xx_yz_zz = buffer_dddd[677];

    auto g_yy_xx_zz_xx = buffer_dddd[678];

    auto g_yy_xx_zz_xy = buffer_dddd[679];

    auto g_yy_xx_zz_xz = buffer_dddd[680];

    auto g_yy_xx_zz_yy = buffer_dddd[681];

    auto g_yy_xx_zz_yz = buffer_dddd[682];

    auto g_yy_xx_zz_zz = buffer_dddd[683];

    auto g_yy_xy_xx_xx = buffer_dddd[684];

    auto g_yy_xy_xx_xy = buffer_dddd[685];

    auto g_yy_xy_xx_xz = buffer_dddd[686];

    auto g_yy_xy_xx_yy = buffer_dddd[687];

    auto g_yy_xy_xx_yz = buffer_dddd[688];

    auto g_yy_xy_xx_zz = buffer_dddd[689];

    auto g_yy_xy_xy_xx = buffer_dddd[690];

    auto g_yy_xy_xy_xy = buffer_dddd[691];

    auto g_yy_xy_xy_xz = buffer_dddd[692];

    auto g_yy_xy_xy_yy = buffer_dddd[693];

    auto g_yy_xy_xy_yz = buffer_dddd[694];

    auto g_yy_xy_xy_zz = buffer_dddd[695];

    auto g_yy_xy_xz_xx = buffer_dddd[696];

    auto g_yy_xy_xz_xy = buffer_dddd[697];

    auto g_yy_xy_xz_xz = buffer_dddd[698];

    auto g_yy_xy_xz_yy = buffer_dddd[699];

    auto g_yy_xy_xz_yz = buffer_dddd[700];

    auto g_yy_xy_xz_zz = buffer_dddd[701];

    auto g_yy_xy_yy_xx = buffer_dddd[702];

    auto g_yy_xy_yy_xy = buffer_dddd[703];

    auto g_yy_xy_yy_xz = buffer_dddd[704];

    auto g_yy_xy_yy_yy = buffer_dddd[705];

    auto g_yy_xy_yy_yz = buffer_dddd[706];

    auto g_yy_xy_yy_zz = buffer_dddd[707];

    auto g_yy_xy_yz_xx = buffer_dddd[708];

    auto g_yy_xy_yz_xy = buffer_dddd[709];

    auto g_yy_xy_yz_xz = buffer_dddd[710];

    auto g_yy_xy_yz_yy = buffer_dddd[711];

    auto g_yy_xy_yz_yz = buffer_dddd[712];

    auto g_yy_xy_yz_zz = buffer_dddd[713];

    auto g_yy_xy_zz_xx = buffer_dddd[714];

    auto g_yy_xy_zz_xy = buffer_dddd[715];

    auto g_yy_xy_zz_xz = buffer_dddd[716];

    auto g_yy_xy_zz_yy = buffer_dddd[717];

    auto g_yy_xy_zz_yz = buffer_dddd[718];

    auto g_yy_xy_zz_zz = buffer_dddd[719];

    auto g_yy_xz_xx_xx = buffer_dddd[720];

    auto g_yy_xz_xx_xy = buffer_dddd[721];

    auto g_yy_xz_xx_xz = buffer_dddd[722];

    auto g_yy_xz_xx_yy = buffer_dddd[723];

    auto g_yy_xz_xx_yz = buffer_dddd[724];

    auto g_yy_xz_xx_zz = buffer_dddd[725];

    auto g_yy_xz_xy_xx = buffer_dddd[726];

    auto g_yy_xz_xy_xy = buffer_dddd[727];

    auto g_yy_xz_xy_xz = buffer_dddd[728];

    auto g_yy_xz_xy_yy = buffer_dddd[729];

    auto g_yy_xz_xy_yz = buffer_dddd[730];

    auto g_yy_xz_xy_zz = buffer_dddd[731];

    auto g_yy_xz_xz_xx = buffer_dddd[732];

    auto g_yy_xz_xz_xy = buffer_dddd[733];

    auto g_yy_xz_xz_xz = buffer_dddd[734];

    auto g_yy_xz_xz_yy = buffer_dddd[735];

    auto g_yy_xz_xz_yz = buffer_dddd[736];

    auto g_yy_xz_xz_zz = buffer_dddd[737];

    auto g_yy_xz_yy_xx = buffer_dddd[738];

    auto g_yy_xz_yy_xy = buffer_dddd[739];

    auto g_yy_xz_yy_xz = buffer_dddd[740];

    auto g_yy_xz_yy_yy = buffer_dddd[741];

    auto g_yy_xz_yy_yz = buffer_dddd[742];

    auto g_yy_xz_yy_zz = buffer_dddd[743];

    auto g_yy_xz_yz_xx = buffer_dddd[744];

    auto g_yy_xz_yz_xy = buffer_dddd[745];

    auto g_yy_xz_yz_xz = buffer_dddd[746];

    auto g_yy_xz_yz_yy = buffer_dddd[747];

    auto g_yy_xz_yz_yz = buffer_dddd[748];

    auto g_yy_xz_yz_zz = buffer_dddd[749];

    auto g_yy_xz_zz_xx = buffer_dddd[750];

    auto g_yy_xz_zz_xy = buffer_dddd[751];

    auto g_yy_xz_zz_xz = buffer_dddd[752];

    auto g_yy_xz_zz_yy = buffer_dddd[753];

    auto g_yy_xz_zz_yz = buffer_dddd[754];

    auto g_yy_xz_zz_zz = buffer_dddd[755];

    auto g_yy_yy_xx_xx = buffer_dddd[756];

    auto g_yy_yy_xx_xy = buffer_dddd[757];

    auto g_yy_yy_xx_xz = buffer_dddd[758];

    auto g_yy_yy_xx_yy = buffer_dddd[759];

    auto g_yy_yy_xx_yz = buffer_dddd[760];

    auto g_yy_yy_xx_zz = buffer_dddd[761];

    auto g_yy_yy_xy_xx = buffer_dddd[762];

    auto g_yy_yy_xy_xy = buffer_dddd[763];

    auto g_yy_yy_xy_xz = buffer_dddd[764];

    auto g_yy_yy_xy_yy = buffer_dddd[765];

    auto g_yy_yy_xy_yz = buffer_dddd[766];

    auto g_yy_yy_xy_zz = buffer_dddd[767];

    auto g_yy_yy_xz_xx = buffer_dddd[768];

    auto g_yy_yy_xz_xy = buffer_dddd[769];

    auto g_yy_yy_xz_xz = buffer_dddd[770];

    auto g_yy_yy_xz_yy = buffer_dddd[771];

    auto g_yy_yy_xz_yz = buffer_dddd[772];

    auto g_yy_yy_xz_zz = buffer_dddd[773];

    auto g_yy_yy_yy_xx = buffer_dddd[774];

    auto g_yy_yy_yy_xy = buffer_dddd[775];

    auto g_yy_yy_yy_xz = buffer_dddd[776];

    auto g_yy_yy_yy_yy = buffer_dddd[777];

    auto g_yy_yy_yy_yz = buffer_dddd[778];

    auto g_yy_yy_yy_zz = buffer_dddd[779];

    auto g_yy_yy_yz_xx = buffer_dddd[780];

    auto g_yy_yy_yz_xy = buffer_dddd[781];

    auto g_yy_yy_yz_xz = buffer_dddd[782];

    auto g_yy_yy_yz_yy = buffer_dddd[783];

    auto g_yy_yy_yz_yz = buffer_dddd[784];

    auto g_yy_yy_yz_zz = buffer_dddd[785];

    auto g_yy_yy_zz_xx = buffer_dddd[786];

    auto g_yy_yy_zz_xy = buffer_dddd[787];

    auto g_yy_yy_zz_xz = buffer_dddd[788];

    auto g_yy_yy_zz_yy = buffer_dddd[789];

    auto g_yy_yy_zz_yz = buffer_dddd[790];

    auto g_yy_yy_zz_zz = buffer_dddd[791];

    auto g_yy_yz_xx_xx = buffer_dddd[792];

    auto g_yy_yz_xx_xy = buffer_dddd[793];

    auto g_yy_yz_xx_xz = buffer_dddd[794];

    auto g_yy_yz_xx_yy = buffer_dddd[795];

    auto g_yy_yz_xx_yz = buffer_dddd[796];

    auto g_yy_yz_xx_zz = buffer_dddd[797];

    auto g_yy_yz_xy_xx = buffer_dddd[798];

    auto g_yy_yz_xy_xy = buffer_dddd[799];

    auto g_yy_yz_xy_xz = buffer_dddd[800];

    auto g_yy_yz_xy_yy = buffer_dddd[801];

    auto g_yy_yz_xy_yz = buffer_dddd[802];

    auto g_yy_yz_xy_zz = buffer_dddd[803];

    auto g_yy_yz_xz_xx = buffer_dddd[804];

    auto g_yy_yz_xz_xy = buffer_dddd[805];

    auto g_yy_yz_xz_xz = buffer_dddd[806];

    auto g_yy_yz_xz_yy = buffer_dddd[807];

    auto g_yy_yz_xz_yz = buffer_dddd[808];

    auto g_yy_yz_xz_zz = buffer_dddd[809];

    auto g_yy_yz_yy_xx = buffer_dddd[810];

    auto g_yy_yz_yy_xy = buffer_dddd[811];

    auto g_yy_yz_yy_xz = buffer_dddd[812];

    auto g_yy_yz_yy_yy = buffer_dddd[813];

    auto g_yy_yz_yy_yz = buffer_dddd[814];

    auto g_yy_yz_yy_zz = buffer_dddd[815];

    auto g_yy_yz_yz_xx = buffer_dddd[816];

    auto g_yy_yz_yz_xy = buffer_dddd[817];

    auto g_yy_yz_yz_xz = buffer_dddd[818];

    auto g_yy_yz_yz_yy = buffer_dddd[819];

    auto g_yy_yz_yz_yz = buffer_dddd[820];

    auto g_yy_yz_yz_zz = buffer_dddd[821];

    auto g_yy_yz_zz_xx = buffer_dddd[822];

    auto g_yy_yz_zz_xy = buffer_dddd[823];

    auto g_yy_yz_zz_xz = buffer_dddd[824];

    auto g_yy_yz_zz_yy = buffer_dddd[825];

    auto g_yy_yz_zz_yz = buffer_dddd[826];

    auto g_yy_yz_zz_zz = buffer_dddd[827];

    auto g_yy_zz_xx_xx = buffer_dddd[828];

    auto g_yy_zz_xx_xy = buffer_dddd[829];

    auto g_yy_zz_xx_xz = buffer_dddd[830];

    auto g_yy_zz_xx_yy = buffer_dddd[831];

    auto g_yy_zz_xx_yz = buffer_dddd[832];

    auto g_yy_zz_xx_zz = buffer_dddd[833];

    auto g_yy_zz_xy_xx = buffer_dddd[834];

    auto g_yy_zz_xy_xy = buffer_dddd[835];

    auto g_yy_zz_xy_xz = buffer_dddd[836];

    auto g_yy_zz_xy_yy = buffer_dddd[837];

    auto g_yy_zz_xy_yz = buffer_dddd[838];

    auto g_yy_zz_xy_zz = buffer_dddd[839];

    auto g_yy_zz_xz_xx = buffer_dddd[840];

    auto g_yy_zz_xz_xy = buffer_dddd[841];

    auto g_yy_zz_xz_xz = buffer_dddd[842];

    auto g_yy_zz_xz_yy = buffer_dddd[843];

    auto g_yy_zz_xz_yz = buffer_dddd[844];

    auto g_yy_zz_xz_zz = buffer_dddd[845];

    auto g_yy_zz_yy_xx = buffer_dddd[846];

    auto g_yy_zz_yy_xy = buffer_dddd[847];

    auto g_yy_zz_yy_xz = buffer_dddd[848];

    auto g_yy_zz_yy_yy = buffer_dddd[849];

    auto g_yy_zz_yy_yz = buffer_dddd[850];

    auto g_yy_zz_yy_zz = buffer_dddd[851];

    auto g_yy_zz_yz_xx = buffer_dddd[852];

    auto g_yy_zz_yz_xy = buffer_dddd[853];

    auto g_yy_zz_yz_xz = buffer_dddd[854];

    auto g_yy_zz_yz_yy = buffer_dddd[855];

    auto g_yy_zz_yz_yz = buffer_dddd[856];

    auto g_yy_zz_yz_zz = buffer_dddd[857];

    auto g_yy_zz_zz_xx = buffer_dddd[858];

    auto g_yy_zz_zz_xy = buffer_dddd[859];

    auto g_yy_zz_zz_xz = buffer_dddd[860];

    auto g_yy_zz_zz_yy = buffer_dddd[861];

    auto g_yy_zz_zz_yz = buffer_dddd[862];

    auto g_yy_zz_zz_zz = buffer_dddd[863];

    auto g_yz_xx_xx_xx = buffer_dddd[864];

    auto g_yz_xx_xx_xy = buffer_dddd[865];

    auto g_yz_xx_xx_xz = buffer_dddd[866];

    auto g_yz_xx_xx_yy = buffer_dddd[867];

    auto g_yz_xx_xx_yz = buffer_dddd[868];

    auto g_yz_xx_xx_zz = buffer_dddd[869];

    auto g_yz_xx_xy_xx = buffer_dddd[870];

    auto g_yz_xx_xy_xy = buffer_dddd[871];

    auto g_yz_xx_xy_xz = buffer_dddd[872];

    auto g_yz_xx_xy_yy = buffer_dddd[873];

    auto g_yz_xx_xy_yz = buffer_dddd[874];

    auto g_yz_xx_xy_zz = buffer_dddd[875];

    auto g_yz_xx_xz_xx = buffer_dddd[876];

    auto g_yz_xx_xz_xy = buffer_dddd[877];

    auto g_yz_xx_xz_xz = buffer_dddd[878];

    auto g_yz_xx_xz_yy = buffer_dddd[879];

    auto g_yz_xx_xz_yz = buffer_dddd[880];

    auto g_yz_xx_xz_zz = buffer_dddd[881];

    auto g_yz_xx_yy_xx = buffer_dddd[882];

    auto g_yz_xx_yy_xy = buffer_dddd[883];

    auto g_yz_xx_yy_xz = buffer_dddd[884];

    auto g_yz_xx_yy_yy = buffer_dddd[885];

    auto g_yz_xx_yy_yz = buffer_dddd[886];

    auto g_yz_xx_yy_zz = buffer_dddd[887];

    auto g_yz_xx_yz_xx = buffer_dddd[888];

    auto g_yz_xx_yz_xy = buffer_dddd[889];

    auto g_yz_xx_yz_xz = buffer_dddd[890];

    auto g_yz_xx_yz_yy = buffer_dddd[891];

    auto g_yz_xx_yz_yz = buffer_dddd[892];

    auto g_yz_xx_yz_zz = buffer_dddd[893];

    auto g_yz_xx_zz_xx = buffer_dddd[894];

    auto g_yz_xx_zz_xy = buffer_dddd[895];

    auto g_yz_xx_zz_xz = buffer_dddd[896];

    auto g_yz_xx_zz_yy = buffer_dddd[897];

    auto g_yz_xx_zz_yz = buffer_dddd[898];

    auto g_yz_xx_zz_zz = buffer_dddd[899];

    auto g_yz_xy_xx_xx = buffer_dddd[900];

    auto g_yz_xy_xx_xy = buffer_dddd[901];

    auto g_yz_xy_xx_xz = buffer_dddd[902];

    auto g_yz_xy_xx_yy = buffer_dddd[903];

    auto g_yz_xy_xx_yz = buffer_dddd[904];

    auto g_yz_xy_xx_zz = buffer_dddd[905];

    auto g_yz_xy_xy_xx = buffer_dddd[906];

    auto g_yz_xy_xy_xy = buffer_dddd[907];

    auto g_yz_xy_xy_xz = buffer_dddd[908];

    auto g_yz_xy_xy_yy = buffer_dddd[909];

    auto g_yz_xy_xy_yz = buffer_dddd[910];

    auto g_yz_xy_xy_zz = buffer_dddd[911];

    auto g_yz_xy_xz_xx = buffer_dddd[912];

    auto g_yz_xy_xz_xy = buffer_dddd[913];

    auto g_yz_xy_xz_xz = buffer_dddd[914];

    auto g_yz_xy_xz_yy = buffer_dddd[915];

    auto g_yz_xy_xz_yz = buffer_dddd[916];

    auto g_yz_xy_xz_zz = buffer_dddd[917];

    auto g_yz_xy_yy_xx = buffer_dddd[918];

    auto g_yz_xy_yy_xy = buffer_dddd[919];

    auto g_yz_xy_yy_xz = buffer_dddd[920];

    auto g_yz_xy_yy_yy = buffer_dddd[921];

    auto g_yz_xy_yy_yz = buffer_dddd[922];

    auto g_yz_xy_yy_zz = buffer_dddd[923];

    auto g_yz_xy_yz_xx = buffer_dddd[924];

    auto g_yz_xy_yz_xy = buffer_dddd[925];

    auto g_yz_xy_yz_xz = buffer_dddd[926];

    auto g_yz_xy_yz_yy = buffer_dddd[927];

    auto g_yz_xy_yz_yz = buffer_dddd[928];

    auto g_yz_xy_yz_zz = buffer_dddd[929];

    auto g_yz_xy_zz_xx = buffer_dddd[930];

    auto g_yz_xy_zz_xy = buffer_dddd[931];

    auto g_yz_xy_zz_xz = buffer_dddd[932];

    auto g_yz_xy_zz_yy = buffer_dddd[933];

    auto g_yz_xy_zz_yz = buffer_dddd[934];

    auto g_yz_xy_zz_zz = buffer_dddd[935];

    auto g_yz_xz_xx_xx = buffer_dddd[936];

    auto g_yz_xz_xx_xy = buffer_dddd[937];

    auto g_yz_xz_xx_xz = buffer_dddd[938];

    auto g_yz_xz_xx_yy = buffer_dddd[939];

    auto g_yz_xz_xx_yz = buffer_dddd[940];

    auto g_yz_xz_xx_zz = buffer_dddd[941];

    auto g_yz_xz_xy_xx = buffer_dddd[942];

    auto g_yz_xz_xy_xy = buffer_dddd[943];

    auto g_yz_xz_xy_xz = buffer_dddd[944];

    auto g_yz_xz_xy_yy = buffer_dddd[945];

    auto g_yz_xz_xy_yz = buffer_dddd[946];

    auto g_yz_xz_xy_zz = buffer_dddd[947];

    auto g_yz_xz_xz_xx = buffer_dddd[948];

    auto g_yz_xz_xz_xy = buffer_dddd[949];

    auto g_yz_xz_xz_xz = buffer_dddd[950];

    auto g_yz_xz_xz_yy = buffer_dddd[951];

    auto g_yz_xz_xz_yz = buffer_dddd[952];

    auto g_yz_xz_xz_zz = buffer_dddd[953];

    auto g_yz_xz_yy_xx = buffer_dddd[954];

    auto g_yz_xz_yy_xy = buffer_dddd[955];

    auto g_yz_xz_yy_xz = buffer_dddd[956];

    auto g_yz_xz_yy_yy = buffer_dddd[957];

    auto g_yz_xz_yy_yz = buffer_dddd[958];

    auto g_yz_xz_yy_zz = buffer_dddd[959];

    auto g_yz_xz_yz_xx = buffer_dddd[960];

    auto g_yz_xz_yz_xy = buffer_dddd[961];

    auto g_yz_xz_yz_xz = buffer_dddd[962];

    auto g_yz_xz_yz_yy = buffer_dddd[963];

    auto g_yz_xz_yz_yz = buffer_dddd[964];

    auto g_yz_xz_yz_zz = buffer_dddd[965];

    auto g_yz_xz_zz_xx = buffer_dddd[966];

    auto g_yz_xz_zz_xy = buffer_dddd[967];

    auto g_yz_xz_zz_xz = buffer_dddd[968];

    auto g_yz_xz_zz_yy = buffer_dddd[969];

    auto g_yz_xz_zz_yz = buffer_dddd[970];

    auto g_yz_xz_zz_zz = buffer_dddd[971];

    auto g_yz_yy_xx_xx = buffer_dddd[972];

    auto g_yz_yy_xx_xy = buffer_dddd[973];

    auto g_yz_yy_xx_xz = buffer_dddd[974];

    auto g_yz_yy_xx_yy = buffer_dddd[975];

    auto g_yz_yy_xx_yz = buffer_dddd[976];

    auto g_yz_yy_xx_zz = buffer_dddd[977];

    auto g_yz_yy_xy_xx = buffer_dddd[978];

    auto g_yz_yy_xy_xy = buffer_dddd[979];

    auto g_yz_yy_xy_xz = buffer_dddd[980];

    auto g_yz_yy_xy_yy = buffer_dddd[981];

    auto g_yz_yy_xy_yz = buffer_dddd[982];

    auto g_yz_yy_xy_zz = buffer_dddd[983];

    auto g_yz_yy_xz_xx = buffer_dddd[984];

    auto g_yz_yy_xz_xy = buffer_dddd[985];

    auto g_yz_yy_xz_xz = buffer_dddd[986];

    auto g_yz_yy_xz_yy = buffer_dddd[987];

    auto g_yz_yy_xz_yz = buffer_dddd[988];

    auto g_yz_yy_xz_zz = buffer_dddd[989];

    auto g_yz_yy_yy_xx = buffer_dddd[990];

    auto g_yz_yy_yy_xy = buffer_dddd[991];

    auto g_yz_yy_yy_xz = buffer_dddd[992];

    auto g_yz_yy_yy_yy = buffer_dddd[993];

    auto g_yz_yy_yy_yz = buffer_dddd[994];

    auto g_yz_yy_yy_zz = buffer_dddd[995];

    auto g_yz_yy_yz_xx = buffer_dddd[996];

    auto g_yz_yy_yz_xy = buffer_dddd[997];

    auto g_yz_yy_yz_xz = buffer_dddd[998];

    auto g_yz_yy_yz_yy = buffer_dddd[999];

    auto g_yz_yy_yz_yz = buffer_dddd[1000];

    auto g_yz_yy_yz_zz = buffer_dddd[1001];

    auto g_yz_yy_zz_xx = buffer_dddd[1002];

    auto g_yz_yy_zz_xy = buffer_dddd[1003];

    auto g_yz_yy_zz_xz = buffer_dddd[1004];

    auto g_yz_yy_zz_yy = buffer_dddd[1005];

    auto g_yz_yy_zz_yz = buffer_dddd[1006];

    auto g_yz_yy_zz_zz = buffer_dddd[1007];

    auto g_yz_yz_xx_xx = buffer_dddd[1008];

    auto g_yz_yz_xx_xy = buffer_dddd[1009];

    auto g_yz_yz_xx_xz = buffer_dddd[1010];

    auto g_yz_yz_xx_yy = buffer_dddd[1011];

    auto g_yz_yz_xx_yz = buffer_dddd[1012];

    auto g_yz_yz_xx_zz = buffer_dddd[1013];

    auto g_yz_yz_xy_xx = buffer_dddd[1014];

    auto g_yz_yz_xy_xy = buffer_dddd[1015];

    auto g_yz_yz_xy_xz = buffer_dddd[1016];

    auto g_yz_yz_xy_yy = buffer_dddd[1017];

    auto g_yz_yz_xy_yz = buffer_dddd[1018];

    auto g_yz_yz_xy_zz = buffer_dddd[1019];

    auto g_yz_yz_xz_xx = buffer_dddd[1020];

    auto g_yz_yz_xz_xy = buffer_dddd[1021];

    auto g_yz_yz_xz_xz = buffer_dddd[1022];

    auto g_yz_yz_xz_yy = buffer_dddd[1023];

    auto g_yz_yz_xz_yz = buffer_dddd[1024];

    auto g_yz_yz_xz_zz = buffer_dddd[1025];

    auto g_yz_yz_yy_xx = buffer_dddd[1026];

    auto g_yz_yz_yy_xy = buffer_dddd[1027];

    auto g_yz_yz_yy_xz = buffer_dddd[1028];

    auto g_yz_yz_yy_yy = buffer_dddd[1029];

    auto g_yz_yz_yy_yz = buffer_dddd[1030];

    auto g_yz_yz_yy_zz = buffer_dddd[1031];

    auto g_yz_yz_yz_xx = buffer_dddd[1032];

    auto g_yz_yz_yz_xy = buffer_dddd[1033];

    auto g_yz_yz_yz_xz = buffer_dddd[1034];

    auto g_yz_yz_yz_yy = buffer_dddd[1035];

    auto g_yz_yz_yz_yz = buffer_dddd[1036];

    auto g_yz_yz_yz_zz = buffer_dddd[1037];

    auto g_yz_yz_zz_xx = buffer_dddd[1038];

    auto g_yz_yz_zz_xy = buffer_dddd[1039];

    auto g_yz_yz_zz_xz = buffer_dddd[1040];

    auto g_yz_yz_zz_yy = buffer_dddd[1041];

    auto g_yz_yz_zz_yz = buffer_dddd[1042];

    auto g_yz_yz_zz_zz = buffer_dddd[1043];

    auto g_yz_zz_xx_xx = buffer_dddd[1044];

    auto g_yz_zz_xx_xy = buffer_dddd[1045];

    auto g_yz_zz_xx_xz = buffer_dddd[1046];

    auto g_yz_zz_xx_yy = buffer_dddd[1047];

    auto g_yz_zz_xx_yz = buffer_dddd[1048];

    auto g_yz_zz_xx_zz = buffer_dddd[1049];

    auto g_yz_zz_xy_xx = buffer_dddd[1050];

    auto g_yz_zz_xy_xy = buffer_dddd[1051];

    auto g_yz_zz_xy_xz = buffer_dddd[1052];

    auto g_yz_zz_xy_yy = buffer_dddd[1053];

    auto g_yz_zz_xy_yz = buffer_dddd[1054];

    auto g_yz_zz_xy_zz = buffer_dddd[1055];

    auto g_yz_zz_xz_xx = buffer_dddd[1056];

    auto g_yz_zz_xz_xy = buffer_dddd[1057];

    auto g_yz_zz_xz_xz = buffer_dddd[1058];

    auto g_yz_zz_xz_yy = buffer_dddd[1059];

    auto g_yz_zz_xz_yz = buffer_dddd[1060];

    auto g_yz_zz_xz_zz = buffer_dddd[1061];

    auto g_yz_zz_yy_xx = buffer_dddd[1062];

    auto g_yz_zz_yy_xy = buffer_dddd[1063];

    auto g_yz_zz_yy_xz = buffer_dddd[1064];

    auto g_yz_zz_yy_yy = buffer_dddd[1065];

    auto g_yz_zz_yy_yz = buffer_dddd[1066];

    auto g_yz_zz_yy_zz = buffer_dddd[1067];

    auto g_yz_zz_yz_xx = buffer_dddd[1068];

    auto g_yz_zz_yz_xy = buffer_dddd[1069];

    auto g_yz_zz_yz_xz = buffer_dddd[1070];

    auto g_yz_zz_yz_yy = buffer_dddd[1071];

    auto g_yz_zz_yz_yz = buffer_dddd[1072];

    auto g_yz_zz_yz_zz = buffer_dddd[1073];

    auto g_yz_zz_zz_xx = buffer_dddd[1074];

    auto g_yz_zz_zz_xy = buffer_dddd[1075];

    auto g_yz_zz_zz_xz = buffer_dddd[1076];

    auto g_yz_zz_zz_yy = buffer_dddd[1077];

    auto g_yz_zz_zz_yz = buffer_dddd[1078];

    auto g_yz_zz_zz_zz = buffer_dddd[1079];

    auto g_zz_xx_xx_xx = buffer_dddd[1080];

    auto g_zz_xx_xx_xy = buffer_dddd[1081];

    auto g_zz_xx_xx_xz = buffer_dddd[1082];

    auto g_zz_xx_xx_yy = buffer_dddd[1083];

    auto g_zz_xx_xx_yz = buffer_dddd[1084];

    auto g_zz_xx_xx_zz = buffer_dddd[1085];

    auto g_zz_xx_xy_xx = buffer_dddd[1086];

    auto g_zz_xx_xy_xy = buffer_dddd[1087];

    auto g_zz_xx_xy_xz = buffer_dddd[1088];

    auto g_zz_xx_xy_yy = buffer_dddd[1089];

    auto g_zz_xx_xy_yz = buffer_dddd[1090];

    auto g_zz_xx_xy_zz = buffer_dddd[1091];

    auto g_zz_xx_xz_xx = buffer_dddd[1092];

    auto g_zz_xx_xz_xy = buffer_dddd[1093];

    auto g_zz_xx_xz_xz = buffer_dddd[1094];

    auto g_zz_xx_xz_yy = buffer_dddd[1095];

    auto g_zz_xx_xz_yz = buffer_dddd[1096];

    auto g_zz_xx_xz_zz = buffer_dddd[1097];

    auto g_zz_xx_yy_xx = buffer_dddd[1098];

    auto g_zz_xx_yy_xy = buffer_dddd[1099];

    auto g_zz_xx_yy_xz = buffer_dddd[1100];

    auto g_zz_xx_yy_yy = buffer_dddd[1101];

    auto g_zz_xx_yy_yz = buffer_dddd[1102];

    auto g_zz_xx_yy_zz = buffer_dddd[1103];

    auto g_zz_xx_yz_xx = buffer_dddd[1104];

    auto g_zz_xx_yz_xy = buffer_dddd[1105];

    auto g_zz_xx_yz_xz = buffer_dddd[1106];

    auto g_zz_xx_yz_yy = buffer_dddd[1107];

    auto g_zz_xx_yz_yz = buffer_dddd[1108];

    auto g_zz_xx_yz_zz = buffer_dddd[1109];

    auto g_zz_xx_zz_xx = buffer_dddd[1110];

    auto g_zz_xx_zz_xy = buffer_dddd[1111];

    auto g_zz_xx_zz_xz = buffer_dddd[1112];

    auto g_zz_xx_zz_yy = buffer_dddd[1113];

    auto g_zz_xx_zz_yz = buffer_dddd[1114];

    auto g_zz_xx_zz_zz = buffer_dddd[1115];

    auto g_zz_xy_xx_xx = buffer_dddd[1116];

    auto g_zz_xy_xx_xy = buffer_dddd[1117];

    auto g_zz_xy_xx_xz = buffer_dddd[1118];

    auto g_zz_xy_xx_yy = buffer_dddd[1119];

    auto g_zz_xy_xx_yz = buffer_dddd[1120];

    auto g_zz_xy_xx_zz = buffer_dddd[1121];

    auto g_zz_xy_xy_xx = buffer_dddd[1122];

    auto g_zz_xy_xy_xy = buffer_dddd[1123];

    auto g_zz_xy_xy_xz = buffer_dddd[1124];

    auto g_zz_xy_xy_yy = buffer_dddd[1125];

    auto g_zz_xy_xy_yz = buffer_dddd[1126];

    auto g_zz_xy_xy_zz = buffer_dddd[1127];

    auto g_zz_xy_xz_xx = buffer_dddd[1128];

    auto g_zz_xy_xz_xy = buffer_dddd[1129];

    auto g_zz_xy_xz_xz = buffer_dddd[1130];

    auto g_zz_xy_xz_yy = buffer_dddd[1131];

    auto g_zz_xy_xz_yz = buffer_dddd[1132];

    auto g_zz_xy_xz_zz = buffer_dddd[1133];

    auto g_zz_xy_yy_xx = buffer_dddd[1134];

    auto g_zz_xy_yy_xy = buffer_dddd[1135];

    auto g_zz_xy_yy_xz = buffer_dddd[1136];

    auto g_zz_xy_yy_yy = buffer_dddd[1137];

    auto g_zz_xy_yy_yz = buffer_dddd[1138];

    auto g_zz_xy_yy_zz = buffer_dddd[1139];

    auto g_zz_xy_yz_xx = buffer_dddd[1140];

    auto g_zz_xy_yz_xy = buffer_dddd[1141];

    auto g_zz_xy_yz_xz = buffer_dddd[1142];

    auto g_zz_xy_yz_yy = buffer_dddd[1143];

    auto g_zz_xy_yz_yz = buffer_dddd[1144];

    auto g_zz_xy_yz_zz = buffer_dddd[1145];

    auto g_zz_xy_zz_xx = buffer_dddd[1146];

    auto g_zz_xy_zz_xy = buffer_dddd[1147];

    auto g_zz_xy_zz_xz = buffer_dddd[1148];

    auto g_zz_xy_zz_yy = buffer_dddd[1149];

    auto g_zz_xy_zz_yz = buffer_dddd[1150];

    auto g_zz_xy_zz_zz = buffer_dddd[1151];

    auto g_zz_xz_xx_xx = buffer_dddd[1152];

    auto g_zz_xz_xx_xy = buffer_dddd[1153];

    auto g_zz_xz_xx_xz = buffer_dddd[1154];

    auto g_zz_xz_xx_yy = buffer_dddd[1155];

    auto g_zz_xz_xx_yz = buffer_dddd[1156];

    auto g_zz_xz_xx_zz = buffer_dddd[1157];

    auto g_zz_xz_xy_xx = buffer_dddd[1158];

    auto g_zz_xz_xy_xy = buffer_dddd[1159];

    auto g_zz_xz_xy_xz = buffer_dddd[1160];

    auto g_zz_xz_xy_yy = buffer_dddd[1161];

    auto g_zz_xz_xy_yz = buffer_dddd[1162];

    auto g_zz_xz_xy_zz = buffer_dddd[1163];

    auto g_zz_xz_xz_xx = buffer_dddd[1164];

    auto g_zz_xz_xz_xy = buffer_dddd[1165];

    auto g_zz_xz_xz_xz = buffer_dddd[1166];

    auto g_zz_xz_xz_yy = buffer_dddd[1167];

    auto g_zz_xz_xz_yz = buffer_dddd[1168];

    auto g_zz_xz_xz_zz = buffer_dddd[1169];

    auto g_zz_xz_yy_xx = buffer_dddd[1170];

    auto g_zz_xz_yy_xy = buffer_dddd[1171];

    auto g_zz_xz_yy_xz = buffer_dddd[1172];

    auto g_zz_xz_yy_yy = buffer_dddd[1173];

    auto g_zz_xz_yy_yz = buffer_dddd[1174];

    auto g_zz_xz_yy_zz = buffer_dddd[1175];

    auto g_zz_xz_yz_xx = buffer_dddd[1176];

    auto g_zz_xz_yz_xy = buffer_dddd[1177];

    auto g_zz_xz_yz_xz = buffer_dddd[1178];

    auto g_zz_xz_yz_yy = buffer_dddd[1179];

    auto g_zz_xz_yz_yz = buffer_dddd[1180];

    auto g_zz_xz_yz_zz = buffer_dddd[1181];

    auto g_zz_xz_zz_xx = buffer_dddd[1182];

    auto g_zz_xz_zz_xy = buffer_dddd[1183];

    auto g_zz_xz_zz_xz = buffer_dddd[1184];

    auto g_zz_xz_zz_yy = buffer_dddd[1185];

    auto g_zz_xz_zz_yz = buffer_dddd[1186];

    auto g_zz_xz_zz_zz = buffer_dddd[1187];

    auto g_zz_yy_xx_xx = buffer_dddd[1188];

    auto g_zz_yy_xx_xy = buffer_dddd[1189];

    auto g_zz_yy_xx_xz = buffer_dddd[1190];

    auto g_zz_yy_xx_yy = buffer_dddd[1191];

    auto g_zz_yy_xx_yz = buffer_dddd[1192];

    auto g_zz_yy_xx_zz = buffer_dddd[1193];

    auto g_zz_yy_xy_xx = buffer_dddd[1194];

    auto g_zz_yy_xy_xy = buffer_dddd[1195];

    auto g_zz_yy_xy_xz = buffer_dddd[1196];

    auto g_zz_yy_xy_yy = buffer_dddd[1197];

    auto g_zz_yy_xy_yz = buffer_dddd[1198];

    auto g_zz_yy_xy_zz = buffer_dddd[1199];

    auto g_zz_yy_xz_xx = buffer_dddd[1200];

    auto g_zz_yy_xz_xy = buffer_dddd[1201];

    auto g_zz_yy_xz_xz = buffer_dddd[1202];

    auto g_zz_yy_xz_yy = buffer_dddd[1203];

    auto g_zz_yy_xz_yz = buffer_dddd[1204];

    auto g_zz_yy_xz_zz = buffer_dddd[1205];

    auto g_zz_yy_yy_xx = buffer_dddd[1206];

    auto g_zz_yy_yy_xy = buffer_dddd[1207];

    auto g_zz_yy_yy_xz = buffer_dddd[1208];

    auto g_zz_yy_yy_yy = buffer_dddd[1209];

    auto g_zz_yy_yy_yz = buffer_dddd[1210];

    auto g_zz_yy_yy_zz = buffer_dddd[1211];

    auto g_zz_yy_yz_xx = buffer_dddd[1212];

    auto g_zz_yy_yz_xy = buffer_dddd[1213];

    auto g_zz_yy_yz_xz = buffer_dddd[1214];

    auto g_zz_yy_yz_yy = buffer_dddd[1215];

    auto g_zz_yy_yz_yz = buffer_dddd[1216];

    auto g_zz_yy_yz_zz = buffer_dddd[1217];

    auto g_zz_yy_zz_xx = buffer_dddd[1218];

    auto g_zz_yy_zz_xy = buffer_dddd[1219];

    auto g_zz_yy_zz_xz = buffer_dddd[1220];

    auto g_zz_yy_zz_yy = buffer_dddd[1221];

    auto g_zz_yy_zz_yz = buffer_dddd[1222];

    auto g_zz_yy_zz_zz = buffer_dddd[1223];

    auto g_zz_yz_xx_xx = buffer_dddd[1224];

    auto g_zz_yz_xx_xy = buffer_dddd[1225];

    auto g_zz_yz_xx_xz = buffer_dddd[1226];

    auto g_zz_yz_xx_yy = buffer_dddd[1227];

    auto g_zz_yz_xx_yz = buffer_dddd[1228];

    auto g_zz_yz_xx_zz = buffer_dddd[1229];

    auto g_zz_yz_xy_xx = buffer_dddd[1230];

    auto g_zz_yz_xy_xy = buffer_dddd[1231];

    auto g_zz_yz_xy_xz = buffer_dddd[1232];

    auto g_zz_yz_xy_yy = buffer_dddd[1233];

    auto g_zz_yz_xy_yz = buffer_dddd[1234];

    auto g_zz_yz_xy_zz = buffer_dddd[1235];

    auto g_zz_yz_xz_xx = buffer_dddd[1236];

    auto g_zz_yz_xz_xy = buffer_dddd[1237];

    auto g_zz_yz_xz_xz = buffer_dddd[1238];

    auto g_zz_yz_xz_yy = buffer_dddd[1239];

    auto g_zz_yz_xz_yz = buffer_dddd[1240];

    auto g_zz_yz_xz_zz = buffer_dddd[1241];

    auto g_zz_yz_yy_xx = buffer_dddd[1242];

    auto g_zz_yz_yy_xy = buffer_dddd[1243];

    auto g_zz_yz_yy_xz = buffer_dddd[1244];

    auto g_zz_yz_yy_yy = buffer_dddd[1245];

    auto g_zz_yz_yy_yz = buffer_dddd[1246];

    auto g_zz_yz_yy_zz = buffer_dddd[1247];

    auto g_zz_yz_yz_xx = buffer_dddd[1248];

    auto g_zz_yz_yz_xy = buffer_dddd[1249];

    auto g_zz_yz_yz_xz = buffer_dddd[1250];

    auto g_zz_yz_yz_yy = buffer_dddd[1251];

    auto g_zz_yz_yz_yz = buffer_dddd[1252];

    auto g_zz_yz_yz_zz = buffer_dddd[1253];

    auto g_zz_yz_zz_xx = buffer_dddd[1254];

    auto g_zz_yz_zz_xy = buffer_dddd[1255];

    auto g_zz_yz_zz_xz = buffer_dddd[1256];

    auto g_zz_yz_zz_yy = buffer_dddd[1257];

    auto g_zz_yz_zz_yz = buffer_dddd[1258];

    auto g_zz_yz_zz_zz = buffer_dddd[1259];

    auto g_zz_zz_xx_xx = buffer_dddd[1260];

    auto g_zz_zz_xx_xy = buffer_dddd[1261];

    auto g_zz_zz_xx_xz = buffer_dddd[1262];

    auto g_zz_zz_xx_yy = buffer_dddd[1263];

    auto g_zz_zz_xx_yz = buffer_dddd[1264];

    auto g_zz_zz_xx_zz = buffer_dddd[1265];

    auto g_zz_zz_xy_xx = buffer_dddd[1266];

    auto g_zz_zz_xy_xy = buffer_dddd[1267];

    auto g_zz_zz_xy_xz = buffer_dddd[1268];

    auto g_zz_zz_xy_yy = buffer_dddd[1269];

    auto g_zz_zz_xy_yz = buffer_dddd[1270];

    auto g_zz_zz_xy_zz = buffer_dddd[1271];

    auto g_zz_zz_xz_xx = buffer_dddd[1272];

    auto g_zz_zz_xz_xy = buffer_dddd[1273];

    auto g_zz_zz_xz_xz = buffer_dddd[1274];

    auto g_zz_zz_xz_yy = buffer_dddd[1275];

    auto g_zz_zz_xz_yz = buffer_dddd[1276];

    auto g_zz_zz_xz_zz = buffer_dddd[1277];

    auto g_zz_zz_yy_xx = buffer_dddd[1278];

    auto g_zz_zz_yy_xy = buffer_dddd[1279];

    auto g_zz_zz_yy_xz = buffer_dddd[1280];

    auto g_zz_zz_yy_yy = buffer_dddd[1281];

    auto g_zz_zz_yy_yz = buffer_dddd[1282];

    auto g_zz_zz_yy_zz = buffer_dddd[1283];

    auto g_zz_zz_yz_xx = buffer_dddd[1284];

    auto g_zz_zz_yz_xy = buffer_dddd[1285];

    auto g_zz_zz_yz_xz = buffer_dddd[1286];

    auto g_zz_zz_yz_yy = buffer_dddd[1287];

    auto g_zz_zz_yz_yz = buffer_dddd[1288];

    auto g_zz_zz_yz_zz = buffer_dddd[1289];

    auto g_zz_zz_zz_xx = buffer_dddd[1290];

    auto g_zz_zz_zz_xy = buffer_dddd[1291];

    auto g_zz_zz_zz_xz = buffer_dddd[1292];

    auto g_zz_zz_zz_yy = buffer_dddd[1293];

    auto g_zz_zz_zz_yz = buffer_dddd[1294];

    auto g_zz_zz_zz_zz = buffer_dddd[1295];

    /// Set up components of integrals buffer : buffer_1010_pdpd

    auto g_x_0_x_0_x_xx_x_xx = buffer_1010_pdpd[0];

    auto g_x_0_x_0_x_xx_x_xy = buffer_1010_pdpd[1];

    auto g_x_0_x_0_x_xx_x_xz = buffer_1010_pdpd[2];

    auto g_x_0_x_0_x_xx_x_yy = buffer_1010_pdpd[3];

    auto g_x_0_x_0_x_xx_x_yz = buffer_1010_pdpd[4];

    auto g_x_0_x_0_x_xx_x_zz = buffer_1010_pdpd[5];

    auto g_x_0_x_0_x_xx_y_xx = buffer_1010_pdpd[6];

    auto g_x_0_x_0_x_xx_y_xy = buffer_1010_pdpd[7];

    auto g_x_0_x_0_x_xx_y_xz = buffer_1010_pdpd[8];

    auto g_x_0_x_0_x_xx_y_yy = buffer_1010_pdpd[9];

    auto g_x_0_x_0_x_xx_y_yz = buffer_1010_pdpd[10];

    auto g_x_0_x_0_x_xx_y_zz = buffer_1010_pdpd[11];

    auto g_x_0_x_0_x_xx_z_xx = buffer_1010_pdpd[12];

    auto g_x_0_x_0_x_xx_z_xy = buffer_1010_pdpd[13];

    auto g_x_0_x_0_x_xx_z_xz = buffer_1010_pdpd[14];

    auto g_x_0_x_0_x_xx_z_yy = buffer_1010_pdpd[15];

    auto g_x_0_x_0_x_xx_z_yz = buffer_1010_pdpd[16];

    auto g_x_0_x_0_x_xx_z_zz = buffer_1010_pdpd[17];

    auto g_x_0_x_0_x_xy_x_xx = buffer_1010_pdpd[18];

    auto g_x_0_x_0_x_xy_x_xy = buffer_1010_pdpd[19];

    auto g_x_0_x_0_x_xy_x_xz = buffer_1010_pdpd[20];

    auto g_x_0_x_0_x_xy_x_yy = buffer_1010_pdpd[21];

    auto g_x_0_x_0_x_xy_x_yz = buffer_1010_pdpd[22];

    auto g_x_0_x_0_x_xy_x_zz = buffer_1010_pdpd[23];

    auto g_x_0_x_0_x_xy_y_xx = buffer_1010_pdpd[24];

    auto g_x_0_x_0_x_xy_y_xy = buffer_1010_pdpd[25];

    auto g_x_0_x_0_x_xy_y_xz = buffer_1010_pdpd[26];

    auto g_x_0_x_0_x_xy_y_yy = buffer_1010_pdpd[27];

    auto g_x_0_x_0_x_xy_y_yz = buffer_1010_pdpd[28];

    auto g_x_0_x_0_x_xy_y_zz = buffer_1010_pdpd[29];

    auto g_x_0_x_0_x_xy_z_xx = buffer_1010_pdpd[30];

    auto g_x_0_x_0_x_xy_z_xy = buffer_1010_pdpd[31];

    auto g_x_0_x_0_x_xy_z_xz = buffer_1010_pdpd[32];

    auto g_x_0_x_0_x_xy_z_yy = buffer_1010_pdpd[33];

    auto g_x_0_x_0_x_xy_z_yz = buffer_1010_pdpd[34];

    auto g_x_0_x_0_x_xy_z_zz = buffer_1010_pdpd[35];

    auto g_x_0_x_0_x_xz_x_xx = buffer_1010_pdpd[36];

    auto g_x_0_x_0_x_xz_x_xy = buffer_1010_pdpd[37];

    auto g_x_0_x_0_x_xz_x_xz = buffer_1010_pdpd[38];

    auto g_x_0_x_0_x_xz_x_yy = buffer_1010_pdpd[39];

    auto g_x_0_x_0_x_xz_x_yz = buffer_1010_pdpd[40];

    auto g_x_0_x_0_x_xz_x_zz = buffer_1010_pdpd[41];

    auto g_x_0_x_0_x_xz_y_xx = buffer_1010_pdpd[42];

    auto g_x_0_x_0_x_xz_y_xy = buffer_1010_pdpd[43];

    auto g_x_0_x_0_x_xz_y_xz = buffer_1010_pdpd[44];

    auto g_x_0_x_0_x_xz_y_yy = buffer_1010_pdpd[45];

    auto g_x_0_x_0_x_xz_y_yz = buffer_1010_pdpd[46];

    auto g_x_0_x_0_x_xz_y_zz = buffer_1010_pdpd[47];

    auto g_x_0_x_0_x_xz_z_xx = buffer_1010_pdpd[48];

    auto g_x_0_x_0_x_xz_z_xy = buffer_1010_pdpd[49];

    auto g_x_0_x_0_x_xz_z_xz = buffer_1010_pdpd[50];

    auto g_x_0_x_0_x_xz_z_yy = buffer_1010_pdpd[51];

    auto g_x_0_x_0_x_xz_z_yz = buffer_1010_pdpd[52];

    auto g_x_0_x_0_x_xz_z_zz = buffer_1010_pdpd[53];

    auto g_x_0_x_0_x_yy_x_xx = buffer_1010_pdpd[54];

    auto g_x_0_x_0_x_yy_x_xy = buffer_1010_pdpd[55];

    auto g_x_0_x_0_x_yy_x_xz = buffer_1010_pdpd[56];

    auto g_x_0_x_0_x_yy_x_yy = buffer_1010_pdpd[57];

    auto g_x_0_x_0_x_yy_x_yz = buffer_1010_pdpd[58];

    auto g_x_0_x_0_x_yy_x_zz = buffer_1010_pdpd[59];

    auto g_x_0_x_0_x_yy_y_xx = buffer_1010_pdpd[60];

    auto g_x_0_x_0_x_yy_y_xy = buffer_1010_pdpd[61];

    auto g_x_0_x_0_x_yy_y_xz = buffer_1010_pdpd[62];

    auto g_x_0_x_0_x_yy_y_yy = buffer_1010_pdpd[63];

    auto g_x_0_x_0_x_yy_y_yz = buffer_1010_pdpd[64];

    auto g_x_0_x_0_x_yy_y_zz = buffer_1010_pdpd[65];

    auto g_x_0_x_0_x_yy_z_xx = buffer_1010_pdpd[66];

    auto g_x_0_x_0_x_yy_z_xy = buffer_1010_pdpd[67];

    auto g_x_0_x_0_x_yy_z_xz = buffer_1010_pdpd[68];

    auto g_x_0_x_0_x_yy_z_yy = buffer_1010_pdpd[69];

    auto g_x_0_x_0_x_yy_z_yz = buffer_1010_pdpd[70];

    auto g_x_0_x_0_x_yy_z_zz = buffer_1010_pdpd[71];

    auto g_x_0_x_0_x_yz_x_xx = buffer_1010_pdpd[72];

    auto g_x_0_x_0_x_yz_x_xy = buffer_1010_pdpd[73];

    auto g_x_0_x_0_x_yz_x_xz = buffer_1010_pdpd[74];

    auto g_x_0_x_0_x_yz_x_yy = buffer_1010_pdpd[75];

    auto g_x_0_x_0_x_yz_x_yz = buffer_1010_pdpd[76];

    auto g_x_0_x_0_x_yz_x_zz = buffer_1010_pdpd[77];

    auto g_x_0_x_0_x_yz_y_xx = buffer_1010_pdpd[78];

    auto g_x_0_x_0_x_yz_y_xy = buffer_1010_pdpd[79];

    auto g_x_0_x_0_x_yz_y_xz = buffer_1010_pdpd[80];

    auto g_x_0_x_0_x_yz_y_yy = buffer_1010_pdpd[81];

    auto g_x_0_x_0_x_yz_y_yz = buffer_1010_pdpd[82];

    auto g_x_0_x_0_x_yz_y_zz = buffer_1010_pdpd[83];

    auto g_x_0_x_0_x_yz_z_xx = buffer_1010_pdpd[84];

    auto g_x_0_x_0_x_yz_z_xy = buffer_1010_pdpd[85];

    auto g_x_0_x_0_x_yz_z_xz = buffer_1010_pdpd[86];

    auto g_x_0_x_0_x_yz_z_yy = buffer_1010_pdpd[87];

    auto g_x_0_x_0_x_yz_z_yz = buffer_1010_pdpd[88];

    auto g_x_0_x_0_x_yz_z_zz = buffer_1010_pdpd[89];

    auto g_x_0_x_0_x_zz_x_xx = buffer_1010_pdpd[90];

    auto g_x_0_x_0_x_zz_x_xy = buffer_1010_pdpd[91];

    auto g_x_0_x_0_x_zz_x_xz = buffer_1010_pdpd[92];

    auto g_x_0_x_0_x_zz_x_yy = buffer_1010_pdpd[93];

    auto g_x_0_x_0_x_zz_x_yz = buffer_1010_pdpd[94];

    auto g_x_0_x_0_x_zz_x_zz = buffer_1010_pdpd[95];

    auto g_x_0_x_0_x_zz_y_xx = buffer_1010_pdpd[96];

    auto g_x_0_x_0_x_zz_y_xy = buffer_1010_pdpd[97];

    auto g_x_0_x_0_x_zz_y_xz = buffer_1010_pdpd[98];

    auto g_x_0_x_0_x_zz_y_yy = buffer_1010_pdpd[99];

    auto g_x_0_x_0_x_zz_y_yz = buffer_1010_pdpd[100];

    auto g_x_0_x_0_x_zz_y_zz = buffer_1010_pdpd[101];

    auto g_x_0_x_0_x_zz_z_xx = buffer_1010_pdpd[102];

    auto g_x_0_x_0_x_zz_z_xy = buffer_1010_pdpd[103];

    auto g_x_0_x_0_x_zz_z_xz = buffer_1010_pdpd[104];

    auto g_x_0_x_0_x_zz_z_yy = buffer_1010_pdpd[105];

    auto g_x_0_x_0_x_zz_z_yz = buffer_1010_pdpd[106];

    auto g_x_0_x_0_x_zz_z_zz = buffer_1010_pdpd[107];

    auto g_x_0_x_0_y_xx_x_xx = buffer_1010_pdpd[108];

    auto g_x_0_x_0_y_xx_x_xy = buffer_1010_pdpd[109];

    auto g_x_0_x_0_y_xx_x_xz = buffer_1010_pdpd[110];

    auto g_x_0_x_0_y_xx_x_yy = buffer_1010_pdpd[111];

    auto g_x_0_x_0_y_xx_x_yz = buffer_1010_pdpd[112];

    auto g_x_0_x_0_y_xx_x_zz = buffer_1010_pdpd[113];

    auto g_x_0_x_0_y_xx_y_xx = buffer_1010_pdpd[114];

    auto g_x_0_x_0_y_xx_y_xy = buffer_1010_pdpd[115];

    auto g_x_0_x_0_y_xx_y_xz = buffer_1010_pdpd[116];

    auto g_x_0_x_0_y_xx_y_yy = buffer_1010_pdpd[117];

    auto g_x_0_x_0_y_xx_y_yz = buffer_1010_pdpd[118];

    auto g_x_0_x_0_y_xx_y_zz = buffer_1010_pdpd[119];

    auto g_x_0_x_0_y_xx_z_xx = buffer_1010_pdpd[120];

    auto g_x_0_x_0_y_xx_z_xy = buffer_1010_pdpd[121];

    auto g_x_0_x_0_y_xx_z_xz = buffer_1010_pdpd[122];

    auto g_x_0_x_0_y_xx_z_yy = buffer_1010_pdpd[123];

    auto g_x_0_x_0_y_xx_z_yz = buffer_1010_pdpd[124];

    auto g_x_0_x_0_y_xx_z_zz = buffer_1010_pdpd[125];

    auto g_x_0_x_0_y_xy_x_xx = buffer_1010_pdpd[126];

    auto g_x_0_x_0_y_xy_x_xy = buffer_1010_pdpd[127];

    auto g_x_0_x_0_y_xy_x_xz = buffer_1010_pdpd[128];

    auto g_x_0_x_0_y_xy_x_yy = buffer_1010_pdpd[129];

    auto g_x_0_x_0_y_xy_x_yz = buffer_1010_pdpd[130];

    auto g_x_0_x_0_y_xy_x_zz = buffer_1010_pdpd[131];

    auto g_x_0_x_0_y_xy_y_xx = buffer_1010_pdpd[132];

    auto g_x_0_x_0_y_xy_y_xy = buffer_1010_pdpd[133];

    auto g_x_0_x_0_y_xy_y_xz = buffer_1010_pdpd[134];

    auto g_x_0_x_0_y_xy_y_yy = buffer_1010_pdpd[135];

    auto g_x_0_x_0_y_xy_y_yz = buffer_1010_pdpd[136];

    auto g_x_0_x_0_y_xy_y_zz = buffer_1010_pdpd[137];

    auto g_x_0_x_0_y_xy_z_xx = buffer_1010_pdpd[138];

    auto g_x_0_x_0_y_xy_z_xy = buffer_1010_pdpd[139];

    auto g_x_0_x_0_y_xy_z_xz = buffer_1010_pdpd[140];

    auto g_x_0_x_0_y_xy_z_yy = buffer_1010_pdpd[141];

    auto g_x_0_x_0_y_xy_z_yz = buffer_1010_pdpd[142];

    auto g_x_0_x_0_y_xy_z_zz = buffer_1010_pdpd[143];

    auto g_x_0_x_0_y_xz_x_xx = buffer_1010_pdpd[144];

    auto g_x_0_x_0_y_xz_x_xy = buffer_1010_pdpd[145];

    auto g_x_0_x_0_y_xz_x_xz = buffer_1010_pdpd[146];

    auto g_x_0_x_0_y_xz_x_yy = buffer_1010_pdpd[147];

    auto g_x_0_x_0_y_xz_x_yz = buffer_1010_pdpd[148];

    auto g_x_0_x_0_y_xz_x_zz = buffer_1010_pdpd[149];

    auto g_x_0_x_0_y_xz_y_xx = buffer_1010_pdpd[150];

    auto g_x_0_x_0_y_xz_y_xy = buffer_1010_pdpd[151];

    auto g_x_0_x_0_y_xz_y_xz = buffer_1010_pdpd[152];

    auto g_x_0_x_0_y_xz_y_yy = buffer_1010_pdpd[153];

    auto g_x_0_x_0_y_xz_y_yz = buffer_1010_pdpd[154];

    auto g_x_0_x_0_y_xz_y_zz = buffer_1010_pdpd[155];

    auto g_x_0_x_0_y_xz_z_xx = buffer_1010_pdpd[156];

    auto g_x_0_x_0_y_xz_z_xy = buffer_1010_pdpd[157];

    auto g_x_0_x_0_y_xz_z_xz = buffer_1010_pdpd[158];

    auto g_x_0_x_0_y_xz_z_yy = buffer_1010_pdpd[159];

    auto g_x_0_x_0_y_xz_z_yz = buffer_1010_pdpd[160];

    auto g_x_0_x_0_y_xz_z_zz = buffer_1010_pdpd[161];

    auto g_x_0_x_0_y_yy_x_xx = buffer_1010_pdpd[162];

    auto g_x_0_x_0_y_yy_x_xy = buffer_1010_pdpd[163];

    auto g_x_0_x_0_y_yy_x_xz = buffer_1010_pdpd[164];

    auto g_x_0_x_0_y_yy_x_yy = buffer_1010_pdpd[165];

    auto g_x_0_x_0_y_yy_x_yz = buffer_1010_pdpd[166];

    auto g_x_0_x_0_y_yy_x_zz = buffer_1010_pdpd[167];

    auto g_x_0_x_0_y_yy_y_xx = buffer_1010_pdpd[168];

    auto g_x_0_x_0_y_yy_y_xy = buffer_1010_pdpd[169];

    auto g_x_0_x_0_y_yy_y_xz = buffer_1010_pdpd[170];

    auto g_x_0_x_0_y_yy_y_yy = buffer_1010_pdpd[171];

    auto g_x_0_x_0_y_yy_y_yz = buffer_1010_pdpd[172];

    auto g_x_0_x_0_y_yy_y_zz = buffer_1010_pdpd[173];

    auto g_x_0_x_0_y_yy_z_xx = buffer_1010_pdpd[174];

    auto g_x_0_x_0_y_yy_z_xy = buffer_1010_pdpd[175];

    auto g_x_0_x_0_y_yy_z_xz = buffer_1010_pdpd[176];

    auto g_x_0_x_0_y_yy_z_yy = buffer_1010_pdpd[177];

    auto g_x_0_x_0_y_yy_z_yz = buffer_1010_pdpd[178];

    auto g_x_0_x_0_y_yy_z_zz = buffer_1010_pdpd[179];

    auto g_x_0_x_0_y_yz_x_xx = buffer_1010_pdpd[180];

    auto g_x_0_x_0_y_yz_x_xy = buffer_1010_pdpd[181];

    auto g_x_0_x_0_y_yz_x_xz = buffer_1010_pdpd[182];

    auto g_x_0_x_0_y_yz_x_yy = buffer_1010_pdpd[183];

    auto g_x_0_x_0_y_yz_x_yz = buffer_1010_pdpd[184];

    auto g_x_0_x_0_y_yz_x_zz = buffer_1010_pdpd[185];

    auto g_x_0_x_0_y_yz_y_xx = buffer_1010_pdpd[186];

    auto g_x_0_x_0_y_yz_y_xy = buffer_1010_pdpd[187];

    auto g_x_0_x_0_y_yz_y_xz = buffer_1010_pdpd[188];

    auto g_x_0_x_0_y_yz_y_yy = buffer_1010_pdpd[189];

    auto g_x_0_x_0_y_yz_y_yz = buffer_1010_pdpd[190];

    auto g_x_0_x_0_y_yz_y_zz = buffer_1010_pdpd[191];

    auto g_x_0_x_0_y_yz_z_xx = buffer_1010_pdpd[192];

    auto g_x_0_x_0_y_yz_z_xy = buffer_1010_pdpd[193];

    auto g_x_0_x_0_y_yz_z_xz = buffer_1010_pdpd[194];

    auto g_x_0_x_0_y_yz_z_yy = buffer_1010_pdpd[195];

    auto g_x_0_x_0_y_yz_z_yz = buffer_1010_pdpd[196];

    auto g_x_0_x_0_y_yz_z_zz = buffer_1010_pdpd[197];

    auto g_x_0_x_0_y_zz_x_xx = buffer_1010_pdpd[198];

    auto g_x_0_x_0_y_zz_x_xy = buffer_1010_pdpd[199];

    auto g_x_0_x_0_y_zz_x_xz = buffer_1010_pdpd[200];

    auto g_x_0_x_0_y_zz_x_yy = buffer_1010_pdpd[201];

    auto g_x_0_x_0_y_zz_x_yz = buffer_1010_pdpd[202];

    auto g_x_0_x_0_y_zz_x_zz = buffer_1010_pdpd[203];

    auto g_x_0_x_0_y_zz_y_xx = buffer_1010_pdpd[204];

    auto g_x_0_x_0_y_zz_y_xy = buffer_1010_pdpd[205];

    auto g_x_0_x_0_y_zz_y_xz = buffer_1010_pdpd[206];

    auto g_x_0_x_0_y_zz_y_yy = buffer_1010_pdpd[207];

    auto g_x_0_x_0_y_zz_y_yz = buffer_1010_pdpd[208];

    auto g_x_0_x_0_y_zz_y_zz = buffer_1010_pdpd[209];

    auto g_x_0_x_0_y_zz_z_xx = buffer_1010_pdpd[210];

    auto g_x_0_x_0_y_zz_z_xy = buffer_1010_pdpd[211];

    auto g_x_0_x_0_y_zz_z_xz = buffer_1010_pdpd[212];

    auto g_x_0_x_0_y_zz_z_yy = buffer_1010_pdpd[213];

    auto g_x_0_x_0_y_zz_z_yz = buffer_1010_pdpd[214];

    auto g_x_0_x_0_y_zz_z_zz = buffer_1010_pdpd[215];

    auto g_x_0_x_0_z_xx_x_xx = buffer_1010_pdpd[216];

    auto g_x_0_x_0_z_xx_x_xy = buffer_1010_pdpd[217];

    auto g_x_0_x_0_z_xx_x_xz = buffer_1010_pdpd[218];

    auto g_x_0_x_0_z_xx_x_yy = buffer_1010_pdpd[219];

    auto g_x_0_x_0_z_xx_x_yz = buffer_1010_pdpd[220];

    auto g_x_0_x_0_z_xx_x_zz = buffer_1010_pdpd[221];

    auto g_x_0_x_0_z_xx_y_xx = buffer_1010_pdpd[222];

    auto g_x_0_x_0_z_xx_y_xy = buffer_1010_pdpd[223];

    auto g_x_0_x_0_z_xx_y_xz = buffer_1010_pdpd[224];

    auto g_x_0_x_0_z_xx_y_yy = buffer_1010_pdpd[225];

    auto g_x_0_x_0_z_xx_y_yz = buffer_1010_pdpd[226];

    auto g_x_0_x_0_z_xx_y_zz = buffer_1010_pdpd[227];

    auto g_x_0_x_0_z_xx_z_xx = buffer_1010_pdpd[228];

    auto g_x_0_x_0_z_xx_z_xy = buffer_1010_pdpd[229];

    auto g_x_0_x_0_z_xx_z_xz = buffer_1010_pdpd[230];

    auto g_x_0_x_0_z_xx_z_yy = buffer_1010_pdpd[231];

    auto g_x_0_x_0_z_xx_z_yz = buffer_1010_pdpd[232];

    auto g_x_0_x_0_z_xx_z_zz = buffer_1010_pdpd[233];

    auto g_x_0_x_0_z_xy_x_xx = buffer_1010_pdpd[234];

    auto g_x_0_x_0_z_xy_x_xy = buffer_1010_pdpd[235];

    auto g_x_0_x_0_z_xy_x_xz = buffer_1010_pdpd[236];

    auto g_x_0_x_0_z_xy_x_yy = buffer_1010_pdpd[237];

    auto g_x_0_x_0_z_xy_x_yz = buffer_1010_pdpd[238];

    auto g_x_0_x_0_z_xy_x_zz = buffer_1010_pdpd[239];

    auto g_x_0_x_0_z_xy_y_xx = buffer_1010_pdpd[240];

    auto g_x_0_x_0_z_xy_y_xy = buffer_1010_pdpd[241];

    auto g_x_0_x_0_z_xy_y_xz = buffer_1010_pdpd[242];

    auto g_x_0_x_0_z_xy_y_yy = buffer_1010_pdpd[243];

    auto g_x_0_x_0_z_xy_y_yz = buffer_1010_pdpd[244];

    auto g_x_0_x_0_z_xy_y_zz = buffer_1010_pdpd[245];

    auto g_x_0_x_0_z_xy_z_xx = buffer_1010_pdpd[246];

    auto g_x_0_x_0_z_xy_z_xy = buffer_1010_pdpd[247];

    auto g_x_0_x_0_z_xy_z_xz = buffer_1010_pdpd[248];

    auto g_x_0_x_0_z_xy_z_yy = buffer_1010_pdpd[249];

    auto g_x_0_x_0_z_xy_z_yz = buffer_1010_pdpd[250];

    auto g_x_0_x_0_z_xy_z_zz = buffer_1010_pdpd[251];

    auto g_x_0_x_0_z_xz_x_xx = buffer_1010_pdpd[252];

    auto g_x_0_x_0_z_xz_x_xy = buffer_1010_pdpd[253];

    auto g_x_0_x_0_z_xz_x_xz = buffer_1010_pdpd[254];

    auto g_x_0_x_0_z_xz_x_yy = buffer_1010_pdpd[255];

    auto g_x_0_x_0_z_xz_x_yz = buffer_1010_pdpd[256];

    auto g_x_0_x_0_z_xz_x_zz = buffer_1010_pdpd[257];

    auto g_x_0_x_0_z_xz_y_xx = buffer_1010_pdpd[258];

    auto g_x_0_x_0_z_xz_y_xy = buffer_1010_pdpd[259];

    auto g_x_0_x_0_z_xz_y_xz = buffer_1010_pdpd[260];

    auto g_x_0_x_0_z_xz_y_yy = buffer_1010_pdpd[261];

    auto g_x_0_x_0_z_xz_y_yz = buffer_1010_pdpd[262];

    auto g_x_0_x_0_z_xz_y_zz = buffer_1010_pdpd[263];

    auto g_x_0_x_0_z_xz_z_xx = buffer_1010_pdpd[264];

    auto g_x_0_x_0_z_xz_z_xy = buffer_1010_pdpd[265];

    auto g_x_0_x_0_z_xz_z_xz = buffer_1010_pdpd[266];

    auto g_x_0_x_0_z_xz_z_yy = buffer_1010_pdpd[267];

    auto g_x_0_x_0_z_xz_z_yz = buffer_1010_pdpd[268];

    auto g_x_0_x_0_z_xz_z_zz = buffer_1010_pdpd[269];

    auto g_x_0_x_0_z_yy_x_xx = buffer_1010_pdpd[270];

    auto g_x_0_x_0_z_yy_x_xy = buffer_1010_pdpd[271];

    auto g_x_0_x_0_z_yy_x_xz = buffer_1010_pdpd[272];

    auto g_x_0_x_0_z_yy_x_yy = buffer_1010_pdpd[273];

    auto g_x_0_x_0_z_yy_x_yz = buffer_1010_pdpd[274];

    auto g_x_0_x_0_z_yy_x_zz = buffer_1010_pdpd[275];

    auto g_x_0_x_0_z_yy_y_xx = buffer_1010_pdpd[276];

    auto g_x_0_x_0_z_yy_y_xy = buffer_1010_pdpd[277];

    auto g_x_0_x_0_z_yy_y_xz = buffer_1010_pdpd[278];

    auto g_x_0_x_0_z_yy_y_yy = buffer_1010_pdpd[279];

    auto g_x_0_x_0_z_yy_y_yz = buffer_1010_pdpd[280];

    auto g_x_0_x_0_z_yy_y_zz = buffer_1010_pdpd[281];

    auto g_x_0_x_0_z_yy_z_xx = buffer_1010_pdpd[282];

    auto g_x_0_x_0_z_yy_z_xy = buffer_1010_pdpd[283];

    auto g_x_0_x_0_z_yy_z_xz = buffer_1010_pdpd[284];

    auto g_x_0_x_0_z_yy_z_yy = buffer_1010_pdpd[285];

    auto g_x_0_x_0_z_yy_z_yz = buffer_1010_pdpd[286];

    auto g_x_0_x_0_z_yy_z_zz = buffer_1010_pdpd[287];

    auto g_x_0_x_0_z_yz_x_xx = buffer_1010_pdpd[288];

    auto g_x_0_x_0_z_yz_x_xy = buffer_1010_pdpd[289];

    auto g_x_0_x_0_z_yz_x_xz = buffer_1010_pdpd[290];

    auto g_x_0_x_0_z_yz_x_yy = buffer_1010_pdpd[291];

    auto g_x_0_x_0_z_yz_x_yz = buffer_1010_pdpd[292];

    auto g_x_0_x_0_z_yz_x_zz = buffer_1010_pdpd[293];

    auto g_x_0_x_0_z_yz_y_xx = buffer_1010_pdpd[294];

    auto g_x_0_x_0_z_yz_y_xy = buffer_1010_pdpd[295];

    auto g_x_0_x_0_z_yz_y_xz = buffer_1010_pdpd[296];

    auto g_x_0_x_0_z_yz_y_yy = buffer_1010_pdpd[297];

    auto g_x_0_x_0_z_yz_y_yz = buffer_1010_pdpd[298];

    auto g_x_0_x_0_z_yz_y_zz = buffer_1010_pdpd[299];

    auto g_x_0_x_0_z_yz_z_xx = buffer_1010_pdpd[300];

    auto g_x_0_x_0_z_yz_z_xy = buffer_1010_pdpd[301];

    auto g_x_0_x_0_z_yz_z_xz = buffer_1010_pdpd[302];

    auto g_x_0_x_0_z_yz_z_yy = buffer_1010_pdpd[303];

    auto g_x_0_x_0_z_yz_z_yz = buffer_1010_pdpd[304];

    auto g_x_0_x_0_z_yz_z_zz = buffer_1010_pdpd[305];

    auto g_x_0_x_0_z_zz_x_xx = buffer_1010_pdpd[306];

    auto g_x_0_x_0_z_zz_x_xy = buffer_1010_pdpd[307];

    auto g_x_0_x_0_z_zz_x_xz = buffer_1010_pdpd[308];

    auto g_x_0_x_0_z_zz_x_yy = buffer_1010_pdpd[309];

    auto g_x_0_x_0_z_zz_x_yz = buffer_1010_pdpd[310];

    auto g_x_0_x_0_z_zz_x_zz = buffer_1010_pdpd[311];

    auto g_x_0_x_0_z_zz_y_xx = buffer_1010_pdpd[312];

    auto g_x_0_x_0_z_zz_y_xy = buffer_1010_pdpd[313];

    auto g_x_0_x_0_z_zz_y_xz = buffer_1010_pdpd[314];

    auto g_x_0_x_0_z_zz_y_yy = buffer_1010_pdpd[315];

    auto g_x_0_x_0_z_zz_y_yz = buffer_1010_pdpd[316];

    auto g_x_0_x_0_z_zz_y_zz = buffer_1010_pdpd[317];

    auto g_x_0_x_0_z_zz_z_xx = buffer_1010_pdpd[318];

    auto g_x_0_x_0_z_zz_z_xy = buffer_1010_pdpd[319];

    auto g_x_0_x_0_z_zz_z_xz = buffer_1010_pdpd[320];

    auto g_x_0_x_0_z_zz_z_yy = buffer_1010_pdpd[321];

    auto g_x_0_x_0_z_zz_z_yz = buffer_1010_pdpd[322];

    auto g_x_0_x_0_z_zz_z_zz = buffer_1010_pdpd[323];

    auto g_x_0_y_0_x_xx_x_xx = buffer_1010_pdpd[324];

    auto g_x_0_y_0_x_xx_x_xy = buffer_1010_pdpd[325];

    auto g_x_0_y_0_x_xx_x_xz = buffer_1010_pdpd[326];

    auto g_x_0_y_0_x_xx_x_yy = buffer_1010_pdpd[327];

    auto g_x_0_y_0_x_xx_x_yz = buffer_1010_pdpd[328];

    auto g_x_0_y_0_x_xx_x_zz = buffer_1010_pdpd[329];

    auto g_x_0_y_0_x_xx_y_xx = buffer_1010_pdpd[330];

    auto g_x_0_y_0_x_xx_y_xy = buffer_1010_pdpd[331];

    auto g_x_0_y_0_x_xx_y_xz = buffer_1010_pdpd[332];

    auto g_x_0_y_0_x_xx_y_yy = buffer_1010_pdpd[333];

    auto g_x_0_y_0_x_xx_y_yz = buffer_1010_pdpd[334];

    auto g_x_0_y_0_x_xx_y_zz = buffer_1010_pdpd[335];

    auto g_x_0_y_0_x_xx_z_xx = buffer_1010_pdpd[336];

    auto g_x_0_y_0_x_xx_z_xy = buffer_1010_pdpd[337];

    auto g_x_0_y_0_x_xx_z_xz = buffer_1010_pdpd[338];

    auto g_x_0_y_0_x_xx_z_yy = buffer_1010_pdpd[339];

    auto g_x_0_y_0_x_xx_z_yz = buffer_1010_pdpd[340];

    auto g_x_0_y_0_x_xx_z_zz = buffer_1010_pdpd[341];

    auto g_x_0_y_0_x_xy_x_xx = buffer_1010_pdpd[342];

    auto g_x_0_y_0_x_xy_x_xy = buffer_1010_pdpd[343];

    auto g_x_0_y_0_x_xy_x_xz = buffer_1010_pdpd[344];

    auto g_x_0_y_0_x_xy_x_yy = buffer_1010_pdpd[345];

    auto g_x_0_y_0_x_xy_x_yz = buffer_1010_pdpd[346];

    auto g_x_0_y_0_x_xy_x_zz = buffer_1010_pdpd[347];

    auto g_x_0_y_0_x_xy_y_xx = buffer_1010_pdpd[348];

    auto g_x_0_y_0_x_xy_y_xy = buffer_1010_pdpd[349];

    auto g_x_0_y_0_x_xy_y_xz = buffer_1010_pdpd[350];

    auto g_x_0_y_0_x_xy_y_yy = buffer_1010_pdpd[351];

    auto g_x_0_y_0_x_xy_y_yz = buffer_1010_pdpd[352];

    auto g_x_0_y_0_x_xy_y_zz = buffer_1010_pdpd[353];

    auto g_x_0_y_0_x_xy_z_xx = buffer_1010_pdpd[354];

    auto g_x_0_y_0_x_xy_z_xy = buffer_1010_pdpd[355];

    auto g_x_0_y_0_x_xy_z_xz = buffer_1010_pdpd[356];

    auto g_x_0_y_0_x_xy_z_yy = buffer_1010_pdpd[357];

    auto g_x_0_y_0_x_xy_z_yz = buffer_1010_pdpd[358];

    auto g_x_0_y_0_x_xy_z_zz = buffer_1010_pdpd[359];

    auto g_x_0_y_0_x_xz_x_xx = buffer_1010_pdpd[360];

    auto g_x_0_y_0_x_xz_x_xy = buffer_1010_pdpd[361];

    auto g_x_0_y_0_x_xz_x_xz = buffer_1010_pdpd[362];

    auto g_x_0_y_0_x_xz_x_yy = buffer_1010_pdpd[363];

    auto g_x_0_y_0_x_xz_x_yz = buffer_1010_pdpd[364];

    auto g_x_0_y_0_x_xz_x_zz = buffer_1010_pdpd[365];

    auto g_x_0_y_0_x_xz_y_xx = buffer_1010_pdpd[366];

    auto g_x_0_y_0_x_xz_y_xy = buffer_1010_pdpd[367];

    auto g_x_0_y_0_x_xz_y_xz = buffer_1010_pdpd[368];

    auto g_x_0_y_0_x_xz_y_yy = buffer_1010_pdpd[369];

    auto g_x_0_y_0_x_xz_y_yz = buffer_1010_pdpd[370];

    auto g_x_0_y_0_x_xz_y_zz = buffer_1010_pdpd[371];

    auto g_x_0_y_0_x_xz_z_xx = buffer_1010_pdpd[372];

    auto g_x_0_y_0_x_xz_z_xy = buffer_1010_pdpd[373];

    auto g_x_0_y_0_x_xz_z_xz = buffer_1010_pdpd[374];

    auto g_x_0_y_0_x_xz_z_yy = buffer_1010_pdpd[375];

    auto g_x_0_y_0_x_xz_z_yz = buffer_1010_pdpd[376];

    auto g_x_0_y_0_x_xz_z_zz = buffer_1010_pdpd[377];

    auto g_x_0_y_0_x_yy_x_xx = buffer_1010_pdpd[378];

    auto g_x_0_y_0_x_yy_x_xy = buffer_1010_pdpd[379];

    auto g_x_0_y_0_x_yy_x_xz = buffer_1010_pdpd[380];

    auto g_x_0_y_0_x_yy_x_yy = buffer_1010_pdpd[381];

    auto g_x_0_y_0_x_yy_x_yz = buffer_1010_pdpd[382];

    auto g_x_0_y_0_x_yy_x_zz = buffer_1010_pdpd[383];

    auto g_x_0_y_0_x_yy_y_xx = buffer_1010_pdpd[384];

    auto g_x_0_y_0_x_yy_y_xy = buffer_1010_pdpd[385];

    auto g_x_0_y_0_x_yy_y_xz = buffer_1010_pdpd[386];

    auto g_x_0_y_0_x_yy_y_yy = buffer_1010_pdpd[387];

    auto g_x_0_y_0_x_yy_y_yz = buffer_1010_pdpd[388];

    auto g_x_0_y_0_x_yy_y_zz = buffer_1010_pdpd[389];

    auto g_x_0_y_0_x_yy_z_xx = buffer_1010_pdpd[390];

    auto g_x_0_y_0_x_yy_z_xy = buffer_1010_pdpd[391];

    auto g_x_0_y_0_x_yy_z_xz = buffer_1010_pdpd[392];

    auto g_x_0_y_0_x_yy_z_yy = buffer_1010_pdpd[393];

    auto g_x_0_y_0_x_yy_z_yz = buffer_1010_pdpd[394];

    auto g_x_0_y_0_x_yy_z_zz = buffer_1010_pdpd[395];

    auto g_x_0_y_0_x_yz_x_xx = buffer_1010_pdpd[396];

    auto g_x_0_y_0_x_yz_x_xy = buffer_1010_pdpd[397];

    auto g_x_0_y_0_x_yz_x_xz = buffer_1010_pdpd[398];

    auto g_x_0_y_0_x_yz_x_yy = buffer_1010_pdpd[399];

    auto g_x_0_y_0_x_yz_x_yz = buffer_1010_pdpd[400];

    auto g_x_0_y_0_x_yz_x_zz = buffer_1010_pdpd[401];

    auto g_x_0_y_0_x_yz_y_xx = buffer_1010_pdpd[402];

    auto g_x_0_y_0_x_yz_y_xy = buffer_1010_pdpd[403];

    auto g_x_0_y_0_x_yz_y_xz = buffer_1010_pdpd[404];

    auto g_x_0_y_0_x_yz_y_yy = buffer_1010_pdpd[405];

    auto g_x_0_y_0_x_yz_y_yz = buffer_1010_pdpd[406];

    auto g_x_0_y_0_x_yz_y_zz = buffer_1010_pdpd[407];

    auto g_x_0_y_0_x_yz_z_xx = buffer_1010_pdpd[408];

    auto g_x_0_y_0_x_yz_z_xy = buffer_1010_pdpd[409];

    auto g_x_0_y_0_x_yz_z_xz = buffer_1010_pdpd[410];

    auto g_x_0_y_0_x_yz_z_yy = buffer_1010_pdpd[411];

    auto g_x_0_y_0_x_yz_z_yz = buffer_1010_pdpd[412];

    auto g_x_0_y_0_x_yz_z_zz = buffer_1010_pdpd[413];

    auto g_x_0_y_0_x_zz_x_xx = buffer_1010_pdpd[414];

    auto g_x_0_y_0_x_zz_x_xy = buffer_1010_pdpd[415];

    auto g_x_0_y_0_x_zz_x_xz = buffer_1010_pdpd[416];

    auto g_x_0_y_0_x_zz_x_yy = buffer_1010_pdpd[417];

    auto g_x_0_y_0_x_zz_x_yz = buffer_1010_pdpd[418];

    auto g_x_0_y_0_x_zz_x_zz = buffer_1010_pdpd[419];

    auto g_x_0_y_0_x_zz_y_xx = buffer_1010_pdpd[420];

    auto g_x_0_y_0_x_zz_y_xy = buffer_1010_pdpd[421];

    auto g_x_0_y_0_x_zz_y_xz = buffer_1010_pdpd[422];

    auto g_x_0_y_0_x_zz_y_yy = buffer_1010_pdpd[423];

    auto g_x_0_y_0_x_zz_y_yz = buffer_1010_pdpd[424];

    auto g_x_0_y_0_x_zz_y_zz = buffer_1010_pdpd[425];

    auto g_x_0_y_0_x_zz_z_xx = buffer_1010_pdpd[426];

    auto g_x_0_y_0_x_zz_z_xy = buffer_1010_pdpd[427];

    auto g_x_0_y_0_x_zz_z_xz = buffer_1010_pdpd[428];

    auto g_x_0_y_0_x_zz_z_yy = buffer_1010_pdpd[429];

    auto g_x_0_y_0_x_zz_z_yz = buffer_1010_pdpd[430];

    auto g_x_0_y_0_x_zz_z_zz = buffer_1010_pdpd[431];

    auto g_x_0_y_0_y_xx_x_xx = buffer_1010_pdpd[432];

    auto g_x_0_y_0_y_xx_x_xy = buffer_1010_pdpd[433];

    auto g_x_0_y_0_y_xx_x_xz = buffer_1010_pdpd[434];

    auto g_x_0_y_0_y_xx_x_yy = buffer_1010_pdpd[435];

    auto g_x_0_y_0_y_xx_x_yz = buffer_1010_pdpd[436];

    auto g_x_0_y_0_y_xx_x_zz = buffer_1010_pdpd[437];

    auto g_x_0_y_0_y_xx_y_xx = buffer_1010_pdpd[438];

    auto g_x_0_y_0_y_xx_y_xy = buffer_1010_pdpd[439];

    auto g_x_0_y_0_y_xx_y_xz = buffer_1010_pdpd[440];

    auto g_x_0_y_0_y_xx_y_yy = buffer_1010_pdpd[441];

    auto g_x_0_y_0_y_xx_y_yz = buffer_1010_pdpd[442];

    auto g_x_0_y_0_y_xx_y_zz = buffer_1010_pdpd[443];

    auto g_x_0_y_0_y_xx_z_xx = buffer_1010_pdpd[444];

    auto g_x_0_y_0_y_xx_z_xy = buffer_1010_pdpd[445];

    auto g_x_0_y_0_y_xx_z_xz = buffer_1010_pdpd[446];

    auto g_x_0_y_0_y_xx_z_yy = buffer_1010_pdpd[447];

    auto g_x_0_y_0_y_xx_z_yz = buffer_1010_pdpd[448];

    auto g_x_0_y_0_y_xx_z_zz = buffer_1010_pdpd[449];

    auto g_x_0_y_0_y_xy_x_xx = buffer_1010_pdpd[450];

    auto g_x_0_y_0_y_xy_x_xy = buffer_1010_pdpd[451];

    auto g_x_0_y_0_y_xy_x_xz = buffer_1010_pdpd[452];

    auto g_x_0_y_0_y_xy_x_yy = buffer_1010_pdpd[453];

    auto g_x_0_y_0_y_xy_x_yz = buffer_1010_pdpd[454];

    auto g_x_0_y_0_y_xy_x_zz = buffer_1010_pdpd[455];

    auto g_x_0_y_0_y_xy_y_xx = buffer_1010_pdpd[456];

    auto g_x_0_y_0_y_xy_y_xy = buffer_1010_pdpd[457];

    auto g_x_0_y_0_y_xy_y_xz = buffer_1010_pdpd[458];

    auto g_x_0_y_0_y_xy_y_yy = buffer_1010_pdpd[459];

    auto g_x_0_y_0_y_xy_y_yz = buffer_1010_pdpd[460];

    auto g_x_0_y_0_y_xy_y_zz = buffer_1010_pdpd[461];

    auto g_x_0_y_0_y_xy_z_xx = buffer_1010_pdpd[462];

    auto g_x_0_y_0_y_xy_z_xy = buffer_1010_pdpd[463];

    auto g_x_0_y_0_y_xy_z_xz = buffer_1010_pdpd[464];

    auto g_x_0_y_0_y_xy_z_yy = buffer_1010_pdpd[465];

    auto g_x_0_y_0_y_xy_z_yz = buffer_1010_pdpd[466];

    auto g_x_0_y_0_y_xy_z_zz = buffer_1010_pdpd[467];

    auto g_x_0_y_0_y_xz_x_xx = buffer_1010_pdpd[468];

    auto g_x_0_y_0_y_xz_x_xy = buffer_1010_pdpd[469];

    auto g_x_0_y_0_y_xz_x_xz = buffer_1010_pdpd[470];

    auto g_x_0_y_0_y_xz_x_yy = buffer_1010_pdpd[471];

    auto g_x_0_y_0_y_xz_x_yz = buffer_1010_pdpd[472];

    auto g_x_0_y_0_y_xz_x_zz = buffer_1010_pdpd[473];

    auto g_x_0_y_0_y_xz_y_xx = buffer_1010_pdpd[474];

    auto g_x_0_y_0_y_xz_y_xy = buffer_1010_pdpd[475];

    auto g_x_0_y_0_y_xz_y_xz = buffer_1010_pdpd[476];

    auto g_x_0_y_0_y_xz_y_yy = buffer_1010_pdpd[477];

    auto g_x_0_y_0_y_xz_y_yz = buffer_1010_pdpd[478];

    auto g_x_0_y_0_y_xz_y_zz = buffer_1010_pdpd[479];

    auto g_x_0_y_0_y_xz_z_xx = buffer_1010_pdpd[480];

    auto g_x_0_y_0_y_xz_z_xy = buffer_1010_pdpd[481];

    auto g_x_0_y_0_y_xz_z_xz = buffer_1010_pdpd[482];

    auto g_x_0_y_0_y_xz_z_yy = buffer_1010_pdpd[483];

    auto g_x_0_y_0_y_xz_z_yz = buffer_1010_pdpd[484];

    auto g_x_0_y_0_y_xz_z_zz = buffer_1010_pdpd[485];

    auto g_x_0_y_0_y_yy_x_xx = buffer_1010_pdpd[486];

    auto g_x_0_y_0_y_yy_x_xy = buffer_1010_pdpd[487];

    auto g_x_0_y_0_y_yy_x_xz = buffer_1010_pdpd[488];

    auto g_x_0_y_0_y_yy_x_yy = buffer_1010_pdpd[489];

    auto g_x_0_y_0_y_yy_x_yz = buffer_1010_pdpd[490];

    auto g_x_0_y_0_y_yy_x_zz = buffer_1010_pdpd[491];

    auto g_x_0_y_0_y_yy_y_xx = buffer_1010_pdpd[492];

    auto g_x_0_y_0_y_yy_y_xy = buffer_1010_pdpd[493];

    auto g_x_0_y_0_y_yy_y_xz = buffer_1010_pdpd[494];

    auto g_x_0_y_0_y_yy_y_yy = buffer_1010_pdpd[495];

    auto g_x_0_y_0_y_yy_y_yz = buffer_1010_pdpd[496];

    auto g_x_0_y_0_y_yy_y_zz = buffer_1010_pdpd[497];

    auto g_x_0_y_0_y_yy_z_xx = buffer_1010_pdpd[498];

    auto g_x_0_y_0_y_yy_z_xy = buffer_1010_pdpd[499];

    auto g_x_0_y_0_y_yy_z_xz = buffer_1010_pdpd[500];

    auto g_x_0_y_0_y_yy_z_yy = buffer_1010_pdpd[501];

    auto g_x_0_y_0_y_yy_z_yz = buffer_1010_pdpd[502];

    auto g_x_0_y_0_y_yy_z_zz = buffer_1010_pdpd[503];

    auto g_x_0_y_0_y_yz_x_xx = buffer_1010_pdpd[504];

    auto g_x_0_y_0_y_yz_x_xy = buffer_1010_pdpd[505];

    auto g_x_0_y_0_y_yz_x_xz = buffer_1010_pdpd[506];

    auto g_x_0_y_0_y_yz_x_yy = buffer_1010_pdpd[507];

    auto g_x_0_y_0_y_yz_x_yz = buffer_1010_pdpd[508];

    auto g_x_0_y_0_y_yz_x_zz = buffer_1010_pdpd[509];

    auto g_x_0_y_0_y_yz_y_xx = buffer_1010_pdpd[510];

    auto g_x_0_y_0_y_yz_y_xy = buffer_1010_pdpd[511];

    auto g_x_0_y_0_y_yz_y_xz = buffer_1010_pdpd[512];

    auto g_x_0_y_0_y_yz_y_yy = buffer_1010_pdpd[513];

    auto g_x_0_y_0_y_yz_y_yz = buffer_1010_pdpd[514];

    auto g_x_0_y_0_y_yz_y_zz = buffer_1010_pdpd[515];

    auto g_x_0_y_0_y_yz_z_xx = buffer_1010_pdpd[516];

    auto g_x_0_y_0_y_yz_z_xy = buffer_1010_pdpd[517];

    auto g_x_0_y_0_y_yz_z_xz = buffer_1010_pdpd[518];

    auto g_x_0_y_0_y_yz_z_yy = buffer_1010_pdpd[519];

    auto g_x_0_y_0_y_yz_z_yz = buffer_1010_pdpd[520];

    auto g_x_0_y_0_y_yz_z_zz = buffer_1010_pdpd[521];

    auto g_x_0_y_0_y_zz_x_xx = buffer_1010_pdpd[522];

    auto g_x_0_y_0_y_zz_x_xy = buffer_1010_pdpd[523];

    auto g_x_0_y_0_y_zz_x_xz = buffer_1010_pdpd[524];

    auto g_x_0_y_0_y_zz_x_yy = buffer_1010_pdpd[525];

    auto g_x_0_y_0_y_zz_x_yz = buffer_1010_pdpd[526];

    auto g_x_0_y_0_y_zz_x_zz = buffer_1010_pdpd[527];

    auto g_x_0_y_0_y_zz_y_xx = buffer_1010_pdpd[528];

    auto g_x_0_y_0_y_zz_y_xy = buffer_1010_pdpd[529];

    auto g_x_0_y_0_y_zz_y_xz = buffer_1010_pdpd[530];

    auto g_x_0_y_0_y_zz_y_yy = buffer_1010_pdpd[531];

    auto g_x_0_y_0_y_zz_y_yz = buffer_1010_pdpd[532];

    auto g_x_0_y_0_y_zz_y_zz = buffer_1010_pdpd[533];

    auto g_x_0_y_0_y_zz_z_xx = buffer_1010_pdpd[534];

    auto g_x_0_y_0_y_zz_z_xy = buffer_1010_pdpd[535];

    auto g_x_0_y_0_y_zz_z_xz = buffer_1010_pdpd[536];

    auto g_x_0_y_0_y_zz_z_yy = buffer_1010_pdpd[537];

    auto g_x_0_y_0_y_zz_z_yz = buffer_1010_pdpd[538];

    auto g_x_0_y_0_y_zz_z_zz = buffer_1010_pdpd[539];

    auto g_x_0_y_0_z_xx_x_xx = buffer_1010_pdpd[540];

    auto g_x_0_y_0_z_xx_x_xy = buffer_1010_pdpd[541];

    auto g_x_0_y_0_z_xx_x_xz = buffer_1010_pdpd[542];

    auto g_x_0_y_0_z_xx_x_yy = buffer_1010_pdpd[543];

    auto g_x_0_y_0_z_xx_x_yz = buffer_1010_pdpd[544];

    auto g_x_0_y_0_z_xx_x_zz = buffer_1010_pdpd[545];

    auto g_x_0_y_0_z_xx_y_xx = buffer_1010_pdpd[546];

    auto g_x_0_y_0_z_xx_y_xy = buffer_1010_pdpd[547];

    auto g_x_0_y_0_z_xx_y_xz = buffer_1010_pdpd[548];

    auto g_x_0_y_0_z_xx_y_yy = buffer_1010_pdpd[549];

    auto g_x_0_y_0_z_xx_y_yz = buffer_1010_pdpd[550];

    auto g_x_0_y_0_z_xx_y_zz = buffer_1010_pdpd[551];

    auto g_x_0_y_0_z_xx_z_xx = buffer_1010_pdpd[552];

    auto g_x_0_y_0_z_xx_z_xy = buffer_1010_pdpd[553];

    auto g_x_0_y_0_z_xx_z_xz = buffer_1010_pdpd[554];

    auto g_x_0_y_0_z_xx_z_yy = buffer_1010_pdpd[555];

    auto g_x_0_y_0_z_xx_z_yz = buffer_1010_pdpd[556];

    auto g_x_0_y_0_z_xx_z_zz = buffer_1010_pdpd[557];

    auto g_x_0_y_0_z_xy_x_xx = buffer_1010_pdpd[558];

    auto g_x_0_y_0_z_xy_x_xy = buffer_1010_pdpd[559];

    auto g_x_0_y_0_z_xy_x_xz = buffer_1010_pdpd[560];

    auto g_x_0_y_0_z_xy_x_yy = buffer_1010_pdpd[561];

    auto g_x_0_y_0_z_xy_x_yz = buffer_1010_pdpd[562];

    auto g_x_0_y_0_z_xy_x_zz = buffer_1010_pdpd[563];

    auto g_x_0_y_0_z_xy_y_xx = buffer_1010_pdpd[564];

    auto g_x_0_y_0_z_xy_y_xy = buffer_1010_pdpd[565];

    auto g_x_0_y_0_z_xy_y_xz = buffer_1010_pdpd[566];

    auto g_x_0_y_0_z_xy_y_yy = buffer_1010_pdpd[567];

    auto g_x_0_y_0_z_xy_y_yz = buffer_1010_pdpd[568];

    auto g_x_0_y_0_z_xy_y_zz = buffer_1010_pdpd[569];

    auto g_x_0_y_0_z_xy_z_xx = buffer_1010_pdpd[570];

    auto g_x_0_y_0_z_xy_z_xy = buffer_1010_pdpd[571];

    auto g_x_0_y_0_z_xy_z_xz = buffer_1010_pdpd[572];

    auto g_x_0_y_0_z_xy_z_yy = buffer_1010_pdpd[573];

    auto g_x_0_y_0_z_xy_z_yz = buffer_1010_pdpd[574];

    auto g_x_0_y_0_z_xy_z_zz = buffer_1010_pdpd[575];

    auto g_x_0_y_0_z_xz_x_xx = buffer_1010_pdpd[576];

    auto g_x_0_y_0_z_xz_x_xy = buffer_1010_pdpd[577];

    auto g_x_0_y_0_z_xz_x_xz = buffer_1010_pdpd[578];

    auto g_x_0_y_0_z_xz_x_yy = buffer_1010_pdpd[579];

    auto g_x_0_y_0_z_xz_x_yz = buffer_1010_pdpd[580];

    auto g_x_0_y_0_z_xz_x_zz = buffer_1010_pdpd[581];

    auto g_x_0_y_0_z_xz_y_xx = buffer_1010_pdpd[582];

    auto g_x_0_y_0_z_xz_y_xy = buffer_1010_pdpd[583];

    auto g_x_0_y_0_z_xz_y_xz = buffer_1010_pdpd[584];

    auto g_x_0_y_0_z_xz_y_yy = buffer_1010_pdpd[585];

    auto g_x_0_y_0_z_xz_y_yz = buffer_1010_pdpd[586];

    auto g_x_0_y_0_z_xz_y_zz = buffer_1010_pdpd[587];

    auto g_x_0_y_0_z_xz_z_xx = buffer_1010_pdpd[588];

    auto g_x_0_y_0_z_xz_z_xy = buffer_1010_pdpd[589];

    auto g_x_0_y_0_z_xz_z_xz = buffer_1010_pdpd[590];

    auto g_x_0_y_0_z_xz_z_yy = buffer_1010_pdpd[591];

    auto g_x_0_y_0_z_xz_z_yz = buffer_1010_pdpd[592];

    auto g_x_0_y_0_z_xz_z_zz = buffer_1010_pdpd[593];

    auto g_x_0_y_0_z_yy_x_xx = buffer_1010_pdpd[594];

    auto g_x_0_y_0_z_yy_x_xy = buffer_1010_pdpd[595];

    auto g_x_0_y_0_z_yy_x_xz = buffer_1010_pdpd[596];

    auto g_x_0_y_0_z_yy_x_yy = buffer_1010_pdpd[597];

    auto g_x_0_y_0_z_yy_x_yz = buffer_1010_pdpd[598];

    auto g_x_0_y_0_z_yy_x_zz = buffer_1010_pdpd[599];

    auto g_x_0_y_0_z_yy_y_xx = buffer_1010_pdpd[600];

    auto g_x_0_y_0_z_yy_y_xy = buffer_1010_pdpd[601];

    auto g_x_0_y_0_z_yy_y_xz = buffer_1010_pdpd[602];

    auto g_x_0_y_0_z_yy_y_yy = buffer_1010_pdpd[603];

    auto g_x_0_y_0_z_yy_y_yz = buffer_1010_pdpd[604];

    auto g_x_0_y_0_z_yy_y_zz = buffer_1010_pdpd[605];

    auto g_x_0_y_0_z_yy_z_xx = buffer_1010_pdpd[606];

    auto g_x_0_y_0_z_yy_z_xy = buffer_1010_pdpd[607];

    auto g_x_0_y_0_z_yy_z_xz = buffer_1010_pdpd[608];

    auto g_x_0_y_0_z_yy_z_yy = buffer_1010_pdpd[609];

    auto g_x_0_y_0_z_yy_z_yz = buffer_1010_pdpd[610];

    auto g_x_0_y_0_z_yy_z_zz = buffer_1010_pdpd[611];

    auto g_x_0_y_0_z_yz_x_xx = buffer_1010_pdpd[612];

    auto g_x_0_y_0_z_yz_x_xy = buffer_1010_pdpd[613];

    auto g_x_0_y_0_z_yz_x_xz = buffer_1010_pdpd[614];

    auto g_x_0_y_0_z_yz_x_yy = buffer_1010_pdpd[615];

    auto g_x_0_y_0_z_yz_x_yz = buffer_1010_pdpd[616];

    auto g_x_0_y_0_z_yz_x_zz = buffer_1010_pdpd[617];

    auto g_x_0_y_0_z_yz_y_xx = buffer_1010_pdpd[618];

    auto g_x_0_y_0_z_yz_y_xy = buffer_1010_pdpd[619];

    auto g_x_0_y_0_z_yz_y_xz = buffer_1010_pdpd[620];

    auto g_x_0_y_0_z_yz_y_yy = buffer_1010_pdpd[621];

    auto g_x_0_y_0_z_yz_y_yz = buffer_1010_pdpd[622];

    auto g_x_0_y_0_z_yz_y_zz = buffer_1010_pdpd[623];

    auto g_x_0_y_0_z_yz_z_xx = buffer_1010_pdpd[624];

    auto g_x_0_y_0_z_yz_z_xy = buffer_1010_pdpd[625];

    auto g_x_0_y_0_z_yz_z_xz = buffer_1010_pdpd[626];

    auto g_x_0_y_0_z_yz_z_yy = buffer_1010_pdpd[627];

    auto g_x_0_y_0_z_yz_z_yz = buffer_1010_pdpd[628];

    auto g_x_0_y_0_z_yz_z_zz = buffer_1010_pdpd[629];

    auto g_x_0_y_0_z_zz_x_xx = buffer_1010_pdpd[630];

    auto g_x_0_y_0_z_zz_x_xy = buffer_1010_pdpd[631];

    auto g_x_0_y_0_z_zz_x_xz = buffer_1010_pdpd[632];

    auto g_x_0_y_0_z_zz_x_yy = buffer_1010_pdpd[633];

    auto g_x_0_y_0_z_zz_x_yz = buffer_1010_pdpd[634];

    auto g_x_0_y_0_z_zz_x_zz = buffer_1010_pdpd[635];

    auto g_x_0_y_0_z_zz_y_xx = buffer_1010_pdpd[636];

    auto g_x_0_y_0_z_zz_y_xy = buffer_1010_pdpd[637];

    auto g_x_0_y_0_z_zz_y_xz = buffer_1010_pdpd[638];

    auto g_x_0_y_0_z_zz_y_yy = buffer_1010_pdpd[639];

    auto g_x_0_y_0_z_zz_y_yz = buffer_1010_pdpd[640];

    auto g_x_0_y_0_z_zz_y_zz = buffer_1010_pdpd[641];

    auto g_x_0_y_0_z_zz_z_xx = buffer_1010_pdpd[642];

    auto g_x_0_y_0_z_zz_z_xy = buffer_1010_pdpd[643];

    auto g_x_0_y_0_z_zz_z_xz = buffer_1010_pdpd[644];

    auto g_x_0_y_0_z_zz_z_yy = buffer_1010_pdpd[645];

    auto g_x_0_y_0_z_zz_z_yz = buffer_1010_pdpd[646];

    auto g_x_0_y_0_z_zz_z_zz = buffer_1010_pdpd[647];

    auto g_x_0_z_0_x_xx_x_xx = buffer_1010_pdpd[648];

    auto g_x_0_z_0_x_xx_x_xy = buffer_1010_pdpd[649];

    auto g_x_0_z_0_x_xx_x_xz = buffer_1010_pdpd[650];

    auto g_x_0_z_0_x_xx_x_yy = buffer_1010_pdpd[651];

    auto g_x_0_z_0_x_xx_x_yz = buffer_1010_pdpd[652];

    auto g_x_0_z_0_x_xx_x_zz = buffer_1010_pdpd[653];

    auto g_x_0_z_0_x_xx_y_xx = buffer_1010_pdpd[654];

    auto g_x_0_z_0_x_xx_y_xy = buffer_1010_pdpd[655];

    auto g_x_0_z_0_x_xx_y_xz = buffer_1010_pdpd[656];

    auto g_x_0_z_0_x_xx_y_yy = buffer_1010_pdpd[657];

    auto g_x_0_z_0_x_xx_y_yz = buffer_1010_pdpd[658];

    auto g_x_0_z_0_x_xx_y_zz = buffer_1010_pdpd[659];

    auto g_x_0_z_0_x_xx_z_xx = buffer_1010_pdpd[660];

    auto g_x_0_z_0_x_xx_z_xy = buffer_1010_pdpd[661];

    auto g_x_0_z_0_x_xx_z_xz = buffer_1010_pdpd[662];

    auto g_x_0_z_0_x_xx_z_yy = buffer_1010_pdpd[663];

    auto g_x_0_z_0_x_xx_z_yz = buffer_1010_pdpd[664];

    auto g_x_0_z_0_x_xx_z_zz = buffer_1010_pdpd[665];

    auto g_x_0_z_0_x_xy_x_xx = buffer_1010_pdpd[666];

    auto g_x_0_z_0_x_xy_x_xy = buffer_1010_pdpd[667];

    auto g_x_0_z_0_x_xy_x_xz = buffer_1010_pdpd[668];

    auto g_x_0_z_0_x_xy_x_yy = buffer_1010_pdpd[669];

    auto g_x_0_z_0_x_xy_x_yz = buffer_1010_pdpd[670];

    auto g_x_0_z_0_x_xy_x_zz = buffer_1010_pdpd[671];

    auto g_x_0_z_0_x_xy_y_xx = buffer_1010_pdpd[672];

    auto g_x_0_z_0_x_xy_y_xy = buffer_1010_pdpd[673];

    auto g_x_0_z_0_x_xy_y_xz = buffer_1010_pdpd[674];

    auto g_x_0_z_0_x_xy_y_yy = buffer_1010_pdpd[675];

    auto g_x_0_z_0_x_xy_y_yz = buffer_1010_pdpd[676];

    auto g_x_0_z_0_x_xy_y_zz = buffer_1010_pdpd[677];

    auto g_x_0_z_0_x_xy_z_xx = buffer_1010_pdpd[678];

    auto g_x_0_z_0_x_xy_z_xy = buffer_1010_pdpd[679];

    auto g_x_0_z_0_x_xy_z_xz = buffer_1010_pdpd[680];

    auto g_x_0_z_0_x_xy_z_yy = buffer_1010_pdpd[681];

    auto g_x_0_z_0_x_xy_z_yz = buffer_1010_pdpd[682];

    auto g_x_0_z_0_x_xy_z_zz = buffer_1010_pdpd[683];

    auto g_x_0_z_0_x_xz_x_xx = buffer_1010_pdpd[684];

    auto g_x_0_z_0_x_xz_x_xy = buffer_1010_pdpd[685];

    auto g_x_0_z_0_x_xz_x_xz = buffer_1010_pdpd[686];

    auto g_x_0_z_0_x_xz_x_yy = buffer_1010_pdpd[687];

    auto g_x_0_z_0_x_xz_x_yz = buffer_1010_pdpd[688];

    auto g_x_0_z_0_x_xz_x_zz = buffer_1010_pdpd[689];

    auto g_x_0_z_0_x_xz_y_xx = buffer_1010_pdpd[690];

    auto g_x_0_z_0_x_xz_y_xy = buffer_1010_pdpd[691];

    auto g_x_0_z_0_x_xz_y_xz = buffer_1010_pdpd[692];

    auto g_x_0_z_0_x_xz_y_yy = buffer_1010_pdpd[693];

    auto g_x_0_z_0_x_xz_y_yz = buffer_1010_pdpd[694];

    auto g_x_0_z_0_x_xz_y_zz = buffer_1010_pdpd[695];

    auto g_x_0_z_0_x_xz_z_xx = buffer_1010_pdpd[696];

    auto g_x_0_z_0_x_xz_z_xy = buffer_1010_pdpd[697];

    auto g_x_0_z_0_x_xz_z_xz = buffer_1010_pdpd[698];

    auto g_x_0_z_0_x_xz_z_yy = buffer_1010_pdpd[699];

    auto g_x_0_z_0_x_xz_z_yz = buffer_1010_pdpd[700];

    auto g_x_0_z_0_x_xz_z_zz = buffer_1010_pdpd[701];

    auto g_x_0_z_0_x_yy_x_xx = buffer_1010_pdpd[702];

    auto g_x_0_z_0_x_yy_x_xy = buffer_1010_pdpd[703];

    auto g_x_0_z_0_x_yy_x_xz = buffer_1010_pdpd[704];

    auto g_x_0_z_0_x_yy_x_yy = buffer_1010_pdpd[705];

    auto g_x_0_z_0_x_yy_x_yz = buffer_1010_pdpd[706];

    auto g_x_0_z_0_x_yy_x_zz = buffer_1010_pdpd[707];

    auto g_x_0_z_0_x_yy_y_xx = buffer_1010_pdpd[708];

    auto g_x_0_z_0_x_yy_y_xy = buffer_1010_pdpd[709];

    auto g_x_0_z_0_x_yy_y_xz = buffer_1010_pdpd[710];

    auto g_x_0_z_0_x_yy_y_yy = buffer_1010_pdpd[711];

    auto g_x_0_z_0_x_yy_y_yz = buffer_1010_pdpd[712];

    auto g_x_0_z_0_x_yy_y_zz = buffer_1010_pdpd[713];

    auto g_x_0_z_0_x_yy_z_xx = buffer_1010_pdpd[714];

    auto g_x_0_z_0_x_yy_z_xy = buffer_1010_pdpd[715];

    auto g_x_0_z_0_x_yy_z_xz = buffer_1010_pdpd[716];

    auto g_x_0_z_0_x_yy_z_yy = buffer_1010_pdpd[717];

    auto g_x_0_z_0_x_yy_z_yz = buffer_1010_pdpd[718];

    auto g_x_0_z_0_x_yy_z_zz = buffer_1010_pdpd[719];

    auto g_x_0_z_0_x_yz_x_xx = buffer_1010_pdpd[720];

    auto g_x_0_z_0_x_yz_x_xy = buffer_1010_pdpd[721];

    auto g_x_0_z_0_x_yz_x_xz = buffer_1010_pdpd[722];

    auto g_x_0_z_0_x_yz_x_yy = buffer_1010_pdpd[723];

    auto g_x_0_z_0_x_yz_x_yz = buffer_1010_pdpd[724];

    auto g_x_0_z_0_x_yz_x_zz = buffer_1010_pdpd[725];

    auto g_x_0_z_0_x_yz_y_xx = buffer_1010_pdpd[726];

    auto g_x_0_z_0_x_yz_y_xy = buffer_1010_pdpd[727];

    auto g_x_0_z_0_x_yz_y_xz = buffer_1010_pdpd[728];

    auto g_x_0_z_0_x_yz_y_yy = buffer_1010_pdpd[729];

    auto g_x_0_z_0_x_yz_y_yz = buffer_1010_pdpd[730];

    auto g_x_0_z_0_x_yz_y_zz = buffer_1010_pdpd[731];

    auto g_x_0_z_0_x_yz_z_xx = buffer_1010_pdpd[732];

    auto g_x_0_z_0_x_yz_z_xy = buffer_1010_pdpd[733];

    auto g_x_0_z_0_x_yz_z_xz = buffer_1010_pdpd[734];

    auto g_x_0_z_0_x_yz_z_yy = buffer_1010_pdpd[735];

    auto g_x_0_z_0_x_yz_z_yz = buffer_1010_pdpd[736];

    auto g_x_0_z_0_x_yz_z_zz = buffer_1010_pdpd[737];

    auto g_x_0_z_0_x_zz_x_xx = buffer_1010_pdpd[738];

    auto g_x_0_z_0_x_zz_x_xy = buffer_1010_pdpd[739];

    auto g_x_0_z_0_x_zz_x_xz = buffer_1010_pdpd[740];

    auto g_x_0_z_0_x_zz_x_yy = buffer_1010_pdpd[741];

    auto g_x_0_z_0_x_zz_x_yz = buffer_1010_pdpd[742];

    auto g_x_0_z_0_x_zz_x_zz = buffer_1010_pdpd[743];

    auto g_x_0_z_0_x_zz_y_xx = buffer_1010_pdpd[744];

    auto g_x_0_z_0_x_zz_y_xy = buffer_1010_pdpd[745];

    auto g_x_0_z_0_x_zz_y_xz = buffer_1010_pdpd[746];

    auto g_x_0_z_0_x_zz_y_yy = buffer_1010_pdpd[747];

    auto g_x_0_z_0_x_zz_y_yz = buffer_1010_pdpd[748];

    auto g_x_0_z_0_x_zz_y_zz = buffer_1010_pdpd[749];

    auto g_x_0_z_0_x_zz_z_xx = buffer_1010_pdpd[750];

    auto g_x_0_z_0_x_zz_z_xy = buffer_1010_pdpd[751];

    auto g_x_0_z_0_x_zz_z_xz = buffer_1010_pdpd[752];

    auto g_x_0_z_0_x_zz_z_yy = buffer_1010_pdpd[753];

    auto g_x_0_z_0_x_zz_z_yz = buffer_1010_pdpd[754];

    auto g_x_0_z_0_x_zz_z_zz = buffer_1010_pdpd[755];

    auto g_x_0_z_0_y_xx_x_xx = buffer_1010_pdpd[756];

    auto g_x_0_z_0_y_xx_x_xy = buffer_1010_pdpd[757];

    auto g_x_0_z_0_y_xx_x_xz = buffer_1010_pdpd[758];

    auto g_x_0_z_0_y_xx_x_yy = buffer_1010_pdpd[759];

    auto g_x_0_z_0_y_xx_x_yz = buffer_1010_pdpd[760];

    auto g_x_0_z_0_y_xx_x_zz = buffer_1010_pdpd[761];

    auto g_x_0_z_0_y_xx_y_xx = buffer_1010_pdpd[762];

    auto g_x_0_z_0_y_xx_y_xy = buffer_1010_pdpd[763];

    auto g_x_0_z_0_y_xx_y_xz = buffer_1010_pdpd[764];

    auto g_x_0_z_0_y_xx_y_yy = buffer_1010_pdpd[765];

    auto g_x_0_z_0_y_xx_y_yz = buffer_1010_pdpd[766];

    auto g_x_0_z_0_y_xx_y_zz = buffer_1010_pdpd[767];

    auto g_x_0_z_0_y_xx_z_xx = buffer_1010_pdpd[768];

    auto g_x_0_z_0_y_xx_z_xy = buffer_1010_pdpd[769];

    auto g_x_0_z_0_y_xx_z_xz = buffer_1010_pdpd[770];

    auto g_x_0_z_0_y_xx_z_yy = buffer_1010_pdpd[771];

    auto g_x_0_z_0_y_xx_z_yz = buffer_1010_pdpd[772];

    auto g_x_0_z_0_y_xx_z_zz = buffer_1010_pdpd[773];

    auto g_x_0_z_0_y_xy_x_xx = buffer_1010_pdpd[774];

    auto g_x_0_z_0_y_xy_x_xy = buffer_1010_pdpd[775];

    auto g_x_0_z_0_y_xy_x_xz = buffer_1010_pdpd[776];

    auto g_x_0_z_0_y_xy_x_yy = buffer_1010_pdpd[777];

    auto g_x_0_z_0_y_xy_x_yz = buffer_1010_pdpd[778];

    auto g_x_0_z_0_y_xy_x_zz = buffer_1010_pdpd[779];

    auto g_x_0_z_0_y_xy_y_xx = buffer_1010_pdpd[780];

    auto g_x_0_z_0_y_xy_y_xy = buffer_1010_pdpd[781];

    auto g_x_0_z_0_y_xy_y_xz = buffer_1010_pdpd[782];

    auto g_x_0_z_0_y_xy_y_yy = buffer_1010_pdpd[783];

    auto g_x_0_z_0_y_xy_y_yz = buffer_1010_pdpd[784];

    auto g_x_0_z_0_y_xy_y_zz = buffer_1010_pdpd[785];

    auto g_x_0_z_0_y_xy_z_xx = buffer_1010_pdpd[786];

    auto g_x_0_z_0_y_xy_z_xy = buffer_1010_pdpd[787];

    auto g_x_0_z_0_y_xy_z_xz = buffer_1010_pdpd[788];

    auto g_x_0_z_0_y_xy_z_yy = buffer_1010_pdpd[789];

    auto g_x_0_z_0_y_xy_z_yz = buffer_1010_pdpd[790];

    auto g_x_0_z_0_y_xy_z_zz = buffer_1010_pdpd[791];

    auto g_x_0_z_0_y_xz_x_xx = buffer_1010_pdpd[792];

    auto g_x_0_z_0_y_xz_x_xy = buffer_1010_pdpd[793];

    auto g_x_0_z_0_y_xz_x_xz = buffer_1010_pdpd[794];

    auto g_x_0_z_0_y_xz_x_yy = buffer_1010_pdpd[795];

    auto g_x_0_z_0_y_xz_x_yz = buffer_1010_pdpd[796];

    auto g_x_0_z_0_y_xz_x_zz = buffer_1010_pdpd[797];

    auto g_x_0_z_0_y_xz_y_xx = buffer_1010_pdpd[798];

    auto g_x_0_z_0_y_xz_y_xy = buffer_1010_pdpd[799];

    auto g_x_0_z_0_y_xz_y_xz = buffer_1010_pdpd[800];

    auto g_x_0_z_0_y_xz_y_yy = buffer_1010_pdpd[801];

    auto g_x_0_z_0_y_xz_y_yz = buffer_1010_pdpd[802];

    auto g_x_0_z_0_y_xz_y_zz = buffer_1010_pdpd[803];

    auto g_x_0_z_0_y_xz_z_xx = buffer_1010_pdpd[804];

    auto g_x_0_z_0_y_xz_z_xy = buffer_1010_pdpd[805];

    auto g_x_0_z_0_y_xz_z_xz = buffer_1010_pdpd[806];

    auto g_x_0_z_0_y_xz_z_yy = buffer_1010_pdpd[807];

    auto g_x_0_z_0_y_xz_z_yz = buffer_1010_pdpd[808];

    auto g_x_0_z_0_y_xz_z_zz = buffer_1010_pdpd[809];

    auto g_x_0_z_0_y_yy_x_xx = buffer_1010_pdpd[810];

    auto g_x_0_z_0_y_yy_x_xy = buffer_1010_pdpd[811];

    auto g_x_0_z_0_y_yy_x_xz = buffer_1010_pdpd[812];

    auto g_x_0_z_0_y_yy_x_yy = buffer_1010_pdpd[813];

    auto g_x_0_z_0_y_yy_x_yz = buffer_1010_pdpd[814];

    auto g_x_0_z_0_y_yy_x_zz = buffer_1010_pdpd[815];

    auto g_x_0_z_0_y_yy_y_xx = buffer_1010_pdpd[816];

    auto g_x_0_z_0_y_yy_y_xy = buffer_1010_pdpd[817];

    auto g_x_0_z_0_y_yy_y_xz = buffer_1010_pdpd[818];

    auto g_x_0_z_0_y_yy_y_yy = buffer_1010_pdpd[819];

    auto g_x_0_z_0_y_yy_y_yz = buffer_1010_pdpd[820];

    auto g_x_0_z_0_y_yy_y_zz = buffer_1010_pdpd[821];

    auto g_x_0_z_0_y_yy_z_xx = buffer_1010_pdpd[822];

    auto g_x_0_z_0_y_yy_z_xy = buffer_1010_pdpd[823];

    auto g_x_0_z_0_y_yy_z_xz = buffer_1010_pdpd[824];

    auto g_x_0_z_0_y_yy_z_yy = buffer_1010_pdpd[825];

    auto g_x_0_z_0_y_yy_z_yz = buffer_1010_pdpd[826];

    auto g_x_0_z_0_y_yy_z_zz = buffer_1010_pdpd[827];

    auto g_x_0_z_0_y_yz_x_xx = buffer_1010_pdpd[828];

    auto g_x_0_z_0_y_yz_x_xy = buffer_1010_pdpd[829];

    auto g_x_0_z_0_y_yz_x_xz = buffer_1010_pdpd[830];

    auto g_x_0_z_0_y_yz_x_yy = buffer_1010_pdpd[831];

    auto g_x_0_z_0_y_yz_x_yz = buffer_1010_pdpd[832];

    auto g_x_0_z_0_y_yz_x_zz = buffer_1010_pdpd[833];

    auto g_x_0_z_0_y_yz_y_xx = buffer_1010_pdpd[834];

    auto g_x_0_z_0_y_yz_y_xy = buffer_1010_pdpd[835];

    auto g_x_0_z_0_y_yz_y_xz = buffer_1010_pdpd[836];

    auto g_x_0_z_0_y_yz_y_yy = buffer_1010_pdpd[837];

    auto g_x_0_z_0_y_yz_y_yz = buffer_1010_pdpd[838];

    auto g_x_0_z_0_y_yz_y_zz = buffer_1010_pdpd[839];

    auto g_x_0_z_0_y_yz_z_xx = buffer_1010_pdpd[840];

    auto g_x_0_z_0_y_yz_z_xy = buffer_1010_pdpd[841];

    auto g_x_0_z_0_y_yz_z_xz = buffer_1010_pdpd[842];

    auto g_x_0_z_0_y_yz_z_yy = buffer_1010_pdpd[843];

    auto g_x_0_z_0_y_yz_z_yz = buffer_1010_pdpd[844];

    auto g_x_0_z_0_y_yz_z_zz = buffer_1010_pdpd[845];

    auto g_x_0_z_0_y_zz_x_xx = buffer_1010_pdpd[846];

    auto g_x_0_z_0_y_zz_x_xy = buffer_1010_pdpd[847];

    auto g_x_0_z_0_y_zz_x_xz = buffer_1010_pdpd[848];

    auto g_x_0_z_0_y_zz_x_yy = buffer_1010_pdpd[849];

    auto g_x_0_z_0_y_zz_x_yz = buffer_1010_pdpd[850];

    auto g_x_0_z_0_y_zz_x_zz = buffer_1010_pdpd[851];

    auto g_x_0_z_0_y_zz_y_xx = buffer_1010_pdpd[852];

    auto g_x_0_z_0_y_zz_y_xy = buffer_1010_pdpd[853];

    auto g_x_0_z_0_y_zz_y_xz = buffer_1010_pdpd[854];

    auto g_x_0_z_0_y_zz_y_yy = buffer_1010_pdpd[855];

    auto g_x_0_z_0_y_zz_y_yz = buffer_1010_pdpd[856];

    auto g_x_0_z_0_y_zz_y_zz = buffer_1010_pdpd[857];

    auto g_x_0_z_0_y_zz_z_xx = buffer_1010_pdpd[858];

    auto g_x_0_z_0_y_zz_z_xy = buffer_1010_pdpd[859];

    auto g_x_0_z_0_y_zz_z_xz = buffer_1010_pdpd[860];

    auto g_x_0_z_0_y_zz_z_yy = buffer_1010_pdpd[861];

    auto g_x_0_z_0_y_zz_z_yz = buffer_1010_pdpd[862];

    auto g_x_0_z_0_y_zz_z_zz = buffer_1010_pdpd[863];

    auto g_x_0_z_0_z_xx_x_xx = buffer_1010_pdpd[864];

    auto g_x_0_z_0_z_xx_x_xy = buffer_1010_pdpd[865];

    auto g_x_0_z_0_z_xx_x_xz = buffer_1010_pdpd[866];

    auto g_x_0_z_0_z_xx_x_yy = buffer_1010_pdpd[867];

    auto g_x_0_z_0_z_xx_x_yz = buffer_1010_pdpd[868];

    auto g_x_0_z_0_z_xx_x_zz = buffer_1010_pdpd[869];

    auto g_x_0_z_0_z_xx_y_xx = buffer_1010_pdpd[870];

    auto g_x_0_z_0_z_xx_y_xy = buffer_1010_pdpd[871];

    auto g_x_0_z_0_z_xx_y_xz = buffer_1010_pdpd[872];

    auto g_x_0_z_0_z_xx_y_yy = buffer_1010_pdpd[873];

    auto g_x_0_z_0_z_xx_y_yz = buffer_1010_pdpd[874];

    auto g_x_0_z_0_z_xx_y_zz = buffer_1010_pdpd[875];

    auto g_x_0_z_0_z_xx_z_xx = buffer_1010_pdpd[876];

    auto g_x_0_z_0_z_xx_z_xy = buffer_1010_pdpd[877];

    auto g_x_0_z_0_z_xx_z_xz = buffer_1010_pdpd[878];

    auto g_x_0_z_0_z_xx_z_yy = buffer_1010_pdpd[879];

    auto g_x_0_z_0_z_xx_z_yz = buffer_1010_pdpd[880];

    auto g_x_0_z_0_z_xx_z_zz = buffer_1010_pdpd[881];

    auto g_x_0_z_0_z_xy_x_xx = buffer_1010_pdpd[882];

    auto g_x_0_z_0_z_xy_x_xy = buffer_1010_pdpd[883];

    auto g_x_0_z_0_z_xy_x_xz = buffer_1010_pdpd[884];

    auto g_x_0_z_0_z_xy_x_yy = buffer_1010_pdpd[885];

    auto g_x_0_z_0_z_xy_x_yz = buffer_1010_pdpd[886];

    auto g_x_0_z_0_z_xy_x_zz = buffer_1010_pdpd[887];

    auto g_x_0_z_0_z_xy_y_xx = buffer_1010_pdpd[888];

    auto g_x_0_z_0_z_xy_y_xy = buffer_1010_pdpd[889];

    auto g_x_0_z_0_z_xy_y_xz = buffer_1010_pdpd[890];

    auto g_x_0_z_0_z_xy_y_yy = buffer_1010_pdpd[891];

    auto g_x_0_z_0_z_xy_y_yz = buffer_1010_pdpd[892];

    auto g_x_0_z_0_z_xy_y_zz = buffer_1010_pdpd[893];

    auto g_x_0_z_0_z_xy_z_xx = buffer_1010_pdpd[894];

    auto g_x_0_z_0_z_xy_z_xy = buffer_1010_pdpd[895];

    auto g_x_0_z_0_z_xy_z_xz = buffer_1010_pdpd[896];

    auto g_x_0_z_0_z_xy_z_yy = buffer_1010_pdpd[897];

    auto g_x_0_z_0_z_xy_z_yz = buffer_1010_pdpd[898];

    auto g_x_0_z_0_z_xy_z_zz = buffer_1010_pdpd[899];

    auto g_x_0_z_0_z_xz_x_xx = buffer_1010_pdpd[900];

    auto g_x_0_z_0_z_xz_x_xy = buffer_1010_pdpd[901];

    auto g_x_0_z_0_z_xz_x_xz = buffer_1010_pdpd[902];

    auto g_x_0_z_0_z_xz_x_yy = buffer_1010_pdpd[903];

    auto g_x_0_z_0_z_xz_x_yz = buffer_1010_pdpd[904];

    auto g_x_0_z_0_z_xz_x_zz = buffer_1010_pdpd[905];

    auto g_x_0_z_0_z_xz_y_xx = buffer_1010_pdpd[906];

    auto g_x_0_z_0_z_xz_y_xy = buffer_1010_pdpd[907];

    auto g_x_0_z_0_z_xz_y_xz = buffer_1010_pdpd[908];

    auto g_x_0_z_0_z_xz_y_yy = buffer_1010_pdpd[909];

    auto g_x_0_z_0_z_xz_y_yz = buffer_1010_pdpd[910];

    auto g_x_0_z_0_z_xz_y_zz = buffer_1010_pdpd[911];

    auto g_x_0_z_0_z_xz_z_xx = buffer_1010_pdpd[912];

    auto g_x_0_z_0_z_xz_z_xy = buffer_1010_pdpd[913];

    auto g_x_0_z_0_z_xz_z_xz = buffer_1010_pdpd[914];

    auto g_x_0_z_0_z_xz_z_yy = buffer_1010_pdpd[915];

    auto g_x_0_z_0_z_xz_z_yz = buffer_1010_pdpd[916];

    auto g_x_0_z_0_z_xz_z_zz = buffer_1010_pdpd[917];

    auto g_x_0_z_0_z_yy_x_xx = buffer_1010_pdpd[918];

    auto g_x_0_z_0_z_yy_x_xy = buffer_1010_pdpd[919];

    auto g_x_0_z_0_z_yy_x_xz = buffer_1010_pdpd[920];

    auto g_x_0_z_0_z_yy_x_yy = buffer_1010_pdpd[921];

    auto g_x_0_z_0_z_yy_x_yz = buffer_1010_pdpd[922];

    auto g_x_0_z_0_z_yy_x_zz = buffer_1010_pdpd[923];

    auto g_x_0_z_0_z_yy_y_xx = buffer_1010_pdpd[924];

    auto g_x_0_z_0_z_yy_y_xy = buffer_1010_pdpd[925];

    auto g_x_0_z_0_z_yy_y_xz = buffer_1010_pdpd[926];

    auto g_x_0_z_0_z_yy_y_yy = buffer_1010_pdpd[927];

    auto g_x_0_z_0_z_yy_y_yz = buffer_1010_pdpd[928];

    auto g_x_0_z_0_z_yy_y_zz = buffer_1010_pdpd[929];

    auto g_x_0_z_0_z_yy_z_xx = buffer_1010_pdpd[930];

    auto g_x_0_z_0_z_yy_z_xy = buffer_1010_pdpd[931];

    auto g_x_0_z_0_z_yy_z_xz = buffer_1010_pdpd[932];

    auto g_x_0_z_0_z_yy_z_yy = buffer_1010_pdpd[933];

    auto g_x_0_z_0_z_yy_z_yz = buffer_1010_pdpd[934];

    auto g_x_0_z_0_z_yy_z_zz = buffer_1010_pdpd[935];

    auto g_x_0_z_0_z_yz_x_xx = buffer_1010_pdpd[936];

    auto g_x_0_z_0_z_yz_x_xy = buffer_1010_pdpd[937];

    auto g_x_0_z_0_z_yz_x_xz = buffer_1010_pdpd[938];

    auto g_x_0_z_0_z_yz_x_yy = buffer_1010_pdpd[939];

    auto g_x_0_z_0_z_yz_x_yz = buffer_1010_pdpd[940];

    auto g_x_0_z_0_z_yz_x_zz = buffer_1010_pdpd[941];

    auto g_x_0_z_0_z_yz_y_xx = buffer_1010_pdpd[942];

    auto g_x_0_z_0_z_yz_y_xy = buffer_1010_pdpd[943];

    auto g_x_0_z_0_z_yz_y_xz = buffer_1010_pdpd[944];

    auto g_x_0_z_0_z_yz_y_yy = buffer_1010_pdpd[945];

    auto g_x_0_z_0_z_yz_y_yz = buffer_1010_pdpd[946];

    auto g_x_0_z_0_z_yz_y_zz = buffer_1010_pdpd[947];

    auto g_x_0_z_0_z_yz_z_xx = buffer_1010_pdpd[948];

    auto g_x_0_z_0_z_yz_z_xy = buffer_1010_pdpd[949];

    auto g_x_0_z_0_z_yz_z_xz = buffer_1010_pdpd[950];

    auto g_x_0_z_0_z_yz_z_yy = buffer_1010_pdpd[951];

    auto g_x_0_z_0_z_yz_z_yz = buffer_1010_pdpd[952];

    auto g_x_0_z_0_z_yz_z_zz = buffer_1010_pdpd[953];

    auto g_x_0_z_0_z_zz_x_xx = buffer_1010_pdpd[954];

    auto g_x_0_z_0_z_zz_x_xy = buffer_1010_pdpd[955];

    auto g_x_0_z_0_z_zz_x_xz = buffer_1010_pdpd[956];

    auto g_x_0_z_0_z_zz_x_yy = buffer_1010_pdpd[957];

    auto g_x_0_z_0_z_zz_x_yz = buffer_1010_pdpd[958];

    auto g_x_0_z_0_z_zz_x_zz = buffer_1010_pdpd[959];

    auto g_x_0_z_0_z_zz_y_xx = buffer_1010_pdpd[960];

    auto g_x_0_z_0_z_zz_y_xy = buffer_1010_pdpd[961];

    auto g_x_0_z_0_z_zz_y_xz = buffer_1010_pdpd[962];

    auto g_x_0_z_0_z_zz_y_yy = buffer_1010_pdpd[963];

    auto g_x_0_z_0_z_zz_y_yz = buffer_1010_pdpd[964];

    auto g_x_0_z_0_z_zz_y_zz = buffer_1010_pdpd[965];

    auto g_x_0_z_0_z_zz_z_xx = buffer_1010_pdpd[966];

    auto g_x_0_z_0_z_zz_z_xy = buffer_1010_pdpd[967];

    auto g_x_0_z_0_z_zz_z_xz = buffer_1010_pdpd[968];

    auto g_x_0_z_0_z_zz_z_yy = buffer_1010_pdpd[969];

    auto g_x_0_z_0_z_zz_z_yz = buffer_1010_pdpd[970];

    auto g_x_0_z_0_z_zz_z_zz = buffer_1010_pdpd[971];

    auto g_y_0_x_0_x_xx_x_xx = buffer_1010_pdpd[972];

    auto g_y_0_x_0_x_xx_x_xy = buffer_1010_pdpd[973];

    auto g_y_0_x_0_x_xx_x_xz = buffer_1010_pdpd[974];

    auto g_y_0_x_0_x_xx_x_yy = buffer_1010_pdpd[975];

    auto g_y_0_x_0_x_xx_x_yz = buffer_1010_pdpd[976];

    auto g_y_0_x_0_x_xx_x_zz = buffer_1010_pdpd[977];

    auto g_y_0_x_0_x_xx_y_xx = buffer_1010_pdpd[978];

    auto g_y_0_x_0_x_xx_y_xy = buffer_1010_pdpd[979];

    auto g_y_0_x_0_x_xx_y_xz = buffer_1010_pdpd[980];

    auto g_y_0_x_0_x_xx_y_yy = buffer_1010_pdpd[981];

    auto g_y_0_x_0_x_xx_y_yz = buffer_1010_pdpd[982];

    auto g_y_0_x_0_x_xx_y_zz = buffer_1010_pdpd[983];

    auto g_y_0_x_0_x_xx_z_xx = buffer_1010_pdpd[984];

    auto g_y_0_x_0_x_xx_z_xy = buffer_1010_pdpd[985];

    auto g_y_0_x_0_x_xx_z_xz = buffer_1010_pdpd[986];

    auto g_y_0_x_0_x_xx_z_yy = buffer_1010_pdpd[987];

    auto g_y_0_x_0_x_xx_z_yz = buffer_1010_pdpd[988];

    auto g_y_0_x_0_x_xx_z_zz = buffer_1010_pdpd[989];

    auto g_y_0_x_0_x_xy_x_xx = buffer_1010_pdpd[990];

    auto g_y_0_x_0_x_xy_x_xy = buffer_1010_pdpd[991];

    auto g_y_0_x_0_x_xy_x_xz = buffer_1010_pdpd[992];

    auto g_y_0_x_0_x_xy_x_yy = buffer_1010_pdpd[993];

    auto g_y_0_x_0_x_xy_x_yz = buffer_1010_pdpd[994];

    auto g_y_0_x_0_x_xy_x_zz = buffer_1010_pdpd[995];

    auto g_y_0_x_0_x_xy_y_xx = buffer_1010_pdpd[996];

    auto g_y_0_x_0_x_xy_y_xy = buffer_1010_pdpd[997];

    auto g_y_0_x_0_x_xy_y_xz = buffer_1010_pdpd[998];

    auto g_y_0_x_0_x_xy_y_yy = buffer_1010_pdpd[999];

    auto g_y_0_x_0_x_xy_y_yz = buffer_1010_pdpd[1000];

    auto g_y_0_x_0_x_xy_y_zz = buffer_1010_pdpd[1001];

    auto g_y_0_x_0_x_xy_z_xx = buffer_1010_pdpd[1002];

    auto g_y_0_x_0_x_xy_z_xy = buffer_1010_pdpd[1003];

    auto g_y_0_x_0_x_xy_z_xz = buffer_1010_pdpd[1004];

    auto g_y_0_x_0_x_xy_z_yy = buffer_1010_pdpd[1005];

    auto g_y_0_x_0_x_xy_z_yz = buffer_1010_pdpd[1006];

    auto g_y_0_x_0_x_xy_z_zz = buffer_1010_pdpd[1007];

    auto g_y_0_x_0_x_xz_x_xx = buffer_1010_pdpd[1008];

    auto g_y_0_x_0_x_xz_x_xy = buffer_1010_pdpd[1009];

    auto g_y_0_x_0_x_xz_x_xz = buffer_1010_pdpd[1010];

    auto g_y_0_x_0_x_xz_x_yy = buffer_1010_pdpd[1011];

    auto g_y_0_x_0_x_xz_x_yz = buffer_1010_pdpd[1012];

    auto g_y_0_x_0_x_xz_x_zz = buffer_1010_pdpd[1013];

    auto g_y_0_x_0_x_xz_y_xx = buffer_1010_pdpd[1014];

    auto g_y_0_x_0_x_xz_y_xy = buffer_1010_pdpd[1015];

    auto g_y_0_x_0_x_xz_y_xz = buffer_1010_pdpd[1016];

    auto g_y_0_x_0_x_xz_y_yy = buffer_1010_pdpd[1017];

    auto g_y_0_x_0_x_xz_y_yz = buffer_1010_pdpd[1018];

    auto g_y_0_x_0_x_xz_y_zz = buffer_1010_pdpd[1019];

    auto g_y_0_x_0_x_xz_z_xx = buffer_1010_pdpd[1020];

    auto g_y_0_x_0_x_xz_z_xy = buffer_1010_pdpd[1021];

    auto g_y_0_x_0_x_xz_z_xz = buffer_1010_pdpd[1022];

    auto g_y_0_x_0_x_xz_z_yy = buffer_1010_pdpd[1023];

    auto g_y_0_x_0_x_xz_z_yz = buffer_1010_pdpd[1024];

    auto g_y_0_x_0_x_xz_z_zz = buffer_1010_pdpd[1025];

    auto g_y_0_x_0_x_yy_x_xx = buffer_1010_pdpd[1026];

    auto g_y_0_x_0_x_yy_x_xy = buffer_1010_pdpd[1027];

    auto g_y_0_x_0_x_yy_x_xz = buffer_1010_pdpd[1028];

    auto g_y_0_x_0_x_yy_x_yy = buffer_1010_pdpd[1029];

    auto g_y_0_x_0_x_yy_x_yz = buffer_1010_pdpd[1030];

    auto g_y_0_x_0_x_yy_x_zz = buffer_1010_pdpd[1031];

    auto g_y_0_x_0_x_yy_y_xx = buffer_1010_pdpd[1032];

    auto g_y_0_x_0_x_yy_y_xy = buffer_1010_pdpd[1033];

    auto g_y_0_x_0_x_yy_y_xz = buffer_1010_pdpd[1034];

    auto g_y_0_x_0_x_yy_y_yy = buffer_1010_pdpd[1035];

    auto g_y_0_x_0_x_yy_y_yz = buffer_1010_pdpd[1036];

    auto g_y_0_x_0_x_yy_y_zz = buffer_1010_pdpd[1037];

    auto g_y_0_x_0_x_yy_z_xx = buffer_1010_pdpd[1038];

    auto g_y_0_x_0_x_yy_z_xy = buffer_1010_pdpd[1039];

    auto g_y_0_x_0_x_yy_z_xz = buffer_1010_pdpd[1040];

    auto g_y_0_x_0_x_yy_z_yy = buffer_1010_pdpd[1041];

    auto g_y_0_x_0_x_yy_z_yz = buffer_1010_pdpd[1042];

    auto g_y_0_x_0_x_yy_z_zz = buffer_1010_pdpd[1043];

    auto g_y_0_x_0_x_yz_x_xx = buffer_1010_pdpd[1044];

    auto g_y_0_x_0_x_yz_x_xy = buffer_1010_pdpd[1045];

    auto g_y_0_x_0_x_yz_x_xz = buffer_1010_pdpd[1046];

    auto g_y_0_x_0_x_yz_x_yy = buffer_1010_pdpd[1047];

    auto g_y_0_x_0_x_yz_x_yz = buffer_1010_pdpd[1048];

    auto g_y_0_x_0_x_yz_x_zz = buffer_1010_pdpd[1049];

    auto g_y_0_x_0_x_yz_y_xx = buffer_1010_pdpd[1050];

    auto g_y_0_x_0_x_yz_y_xy = buffer_1010_pdpd[1051];

    auto g_y_0_x_0_x_yz_y_xz = buffer_1010_pdpd[1052];

    auto g_y_0_x_0_x_yz_y_yy = buffer_1010_pdpd[1053];

    auto g_y_0_x_0_x_yz_y_yz = buffer_1010_pdpd[1054];

    auto g_y_0_x_0_x_yz_y_zz = buffer_1010_pdpd[1055];

    auto g_y_0_x_0_x_yz_z_xx = buffer_1010_pdpd[1056];

    auto g_y_0_x_0_x_yz_z_xy = buffer_1010_pdpd[1057];

    auto g_y_0_x_0_x_yz_z_xz = buffer_1010_pdpd[1058];

    auto g_y_0_x_0_x_yz_z_yy = buffer_1010_pdpd[1059];

    auto g_y_0_x_0_x_yz_z_yz = buffer_1010_pdpd[1060];

    auto g_y_0_x_0_x_yz_z_zz = buffer_1010_pdpd[1061];

    auto g_y_0_x_0_x_zz_x_xx = buffer_1010_pdpd[1062];

    auto g_y_0_x_0_x_zz_x_xy = buffer_1010_pdpd[1063];

    auto g_y_0_x_0_x_zz_x_xz = buffer_1010_pdpd[1064];

    auto g_y_0_x_0_x_zz_x_yy = buffer_1010_pdpd[1065];

    auto g_y_0_x_0_x_zz_x_yz = buffer_1010_pdpd[1066];

    auto g_y_0_x_0_x_zz_x_zz = buffer_1010_pdpd[1067];

    auto g_y_0_x_0_x_zz_y_xx = buffer_1010_pdpd[1068];

    auto g_y_0_x_0_x_zz_y_xy = buffer_1010_pdpd[1069];

    auto g_y_0_x_0_x_zz_y_xz = buffer_1010_pdpd[1070];

    auto g_y_0_x_0_x_zz_y_yy = buffer_1010_pdpd[1071];

    auto g_y_0_x_0_x_zz_y_yz = buffer_1010_pdpd[1072];

    auto g_y_0_x_0_x_zz_y_zz = buffer_1010_pdpd[1073];

    auto g_y_0_x_0_x_zz_z_xx = buffer_1010_pdpd[1074];

    auto g_y_0_x_0_x_zz_z_xy = buffer_1010_pdpd[1075];

    auto g_y_0_x_0_x_zz_z_xz = buffer_1010_pdpd[1076];

    auto g_y_0_x_0_x_zz_z_yy = buffer_1010_pdpd[1077];

    auto g_y_0_x_0_x_zz_z_yz = buffer_1010_pdpd[1078];

    auto g_y_0_x_0_x_zz_z_zz = buffer_1010_pdpd[1079];

    auto g_y_0_x_0_y_xx_x_xx = buffer_1010_pdpd[1080];

    auto g_y_0_x_0_y_xx_x_xy = buffer_1010_pdpd[1081];

    auto g_y_0_x_0_y_xx_x_xz = buffer_1010_pdpd[1082];

    auto g_y_0_x_0_y_xx_x_yy = buffer_1010_pdpd[1083];

    auto g_y_0_x_0_y_xx_x_yz = buffer_1010_pdpd[1084];

    auto g_y_0_x_0_y_xx_x_zz = buffer_1010_pdpd[1085];

    auto g_y_0_x_0_y_xx_y_xx = buffer_1010_pdpd[1086];

    auto g_y_0_x_0_y_xx_y_xy = buffer_1010_pdpd[1087];

    auto g_y_0_x_0_y_xx_y_xz = buffer_1010_pdpd[1088];

    auto g_y_0_x_0_y_xx_y_yy = buffer_1010_pdpd[1089];

    auto g_y_0_x_0_y_xx_y_yz = buffer_1010_pdpd[1090];

    auto g_y_0_x_0_y_xx_y_zz = buffer_1010_pdpd[1091];

    auto g_y_0_x_0_y_xx_z_xx = buffer_1010_pdpd[1092];

    auto g_y_0_x_0_y_xx_z_xy = buffer_1010_pdpd[1093];

    auto g_y_0_x_0_y_xx_z_xz = buffer_1010_pdpd[1094];

    auto g_y_0_x_0_y_xx_z_yy = buffer_1010_pdpd[1095];

    auto g_y_0_x_0_y_xx_z_yz = buffer_1010_pdpd[1096];

    auto g_y_0_x_0_y_xx_z_zz = buffer_1010_pdpd[1097];

    auto g_y_0_x_0_y_xy_x_xx = buffer_1010_pdpd[1098];

    auto g_y_0_x_0_y_xy_x_xy = buffer_1010_pdpd[1099];

    auto g_y_0_x_0_y_xy_x_xz = buffer_1010_pdpd[1100];

    auto g_y_0_x_0_y_xy_x_yy = buffer_1010_pdpd[1101];

    auto g_y_0_x_0_y_xy_x_yz = buffer_1010_pdpd[1102];

    auto g_y_0_x_0_y_xy_x_zz = buffer_1010_pdpd[1103];

    auto g_y_0_x_0_y_xy_y_xx = buffer_1010_pdpd[1104];

    auto g_y_0_x_0_y_xy_y_xy = buffer_1010_pdpd[1105];

    auto g_y_0_x_0_y_xy_y_xz = buffer_1010_pdpd[1106];

    auto g_y_0_x_0_y_xy_y_yy = buffer_1010_pdpd[1107];

    auto g_y_0_x_0_y_xy_y_yz = buffer_1010_pdpd[1108];

    auto g_y_0_x_0_y_xy_y_zz = buffer_1010_pdpd[1109];

    auto g_y_0_x_0_y_xy_z_xx = buffer_1010_pdpd[1110];

    auto g_y_0_x_0_y_xy_z_xy = buffer_1010_pdpd[1111];

    auto g_y_0_x_0_y_xy_z_xz = buffer_1010_pdpd[1112];

    auto g_y_0_x_0_y_xy_z_yy = buffer_1010_pdpd[1113];

    auto g_y_0_x_0_y_xy_z_yz = buffer_1010_pdpd[1114];

    auto g_y_0_x_0_y_xy_z_zz = buffer_1010_pdpd[1115];

    auto g_y_0_x_0_y_xz_x_xx = buffer_1010_pdpd[1116];

    auto g_y_0_x_0_y_xz_x_xy = buffer_1010_pdpd[1117];

    auto g_y_0_x_0_y_xz_x_xz = buffer_1010_pdpd[1118];

    auto g_y_0_x_0_y_xz_x_yy = buffer_1010_pdpd[1119];

    auto g_y_0_x_0_y_xz_x_yz = buffer_1010_pdpd[1120];

    auto g_y_0_x_0_y_xz_x_zz = buffer_1010_pdpd[1121];

    auto g_y_0_x_0_y_xz_y_xx = buffer_1010_pdpd[1122];

    auto g_y_0_x_0_y_xz_y_xy = buffer_1010_pdpd[1123];

    auto g_y_0_x_0_y_xz_y_xz = buffer_1010_pdpd[1124];

    auto g_y_0_x_0_y_xz_y_yy = buffer_1010_pdpd[1125];

    auto g_y_0_x_0_y_xz_y_yz = buffer_1010_pdpd[1126];

    auto g_y_0_x_0_y_xz_y_zz = buffer_1010_pdpd[1127];

    auto g_y_0_x_0_y_xz_z_xx = buffer_1010_pdpd[1128];

    auto g_y_0_x_0_y_xz_z_xy = buffer_1010_pdpd[1129];

    auto g_y_0_x_0_y_xz_z_xz = buffer_1010_pdpd[1130];

    auto g_y_0_x_0_y_xz_z_yy = buffer_1010_pdpd[1131];

    auto g_y_0_x_0_y_xz_z_yz = buffer_1010_pdpd[1132];

    auto g_y_0_x_0_y_xz_z_zz = buffer_1010_pdpd[1133];

    auto g_y_0_x_0_y_yy_x_xx = buffer_1010_pdpd[1134];

    auto g_y_0_x_0_y_yy_x_xy = buffer_1010_pdpd[1135];

    auto g_y_0_x_0_y_yy_x_xz = buffer_1010_pdpd[1136];

    auto g_y_0_x_0_y_yy_x_yy = buffer_1010_pdpd[1137];

    auto g_y_0_x_0_y_yy_x_yz = buffer_1010_pdpd[1138];

    auto g_y_0_x_0_y_yy_x_zz = buffer_1010_pdpd[1139];

    auto g_y_0_x_0_y_yy_y_xx = buffer_1010_pdpd[1140];

    auto g_y_0_x_0_y_yy_y_xy = buffer_1010_pdpd[1141];

    auto g_y_0_x_0_y_yy_y_xz = buffer_1010_pdpd[1142];

    auto g_y_0_x_0_y_yy_y_yy = buffer_1010_pdpd[1143];

    auto g_y_0_x_0_y_yy_y_yz = buffer_1010_pdpd[1144];

    auto g_y_0_x_0_y_yy_y_zz = buffer_1010_pdpd[1145];

    auto g_y_0_x_0_y_yy_z_xx = buffer_1010_pdpd[1146];

    auto g_y_0_x_0_y_yy_z_xy = buffer_1010_pdpd[1147];

    auto g_y_0_x_0_y_yy_z_xz = buffer_1010_pdpd[1148];

    auto g_y_0_x_0_y_yy_z_yy = buffer_1010_pdpd[1149];

    auto g_y_0_x_0_y_yy_z_yz = buffer_1010_pdpd[1150];

    auto g_y_0_x_0_y_yy_z_zz = buffer_1010_pdpd[1151];

    auto g_y_0_x_0_y_yz_x_xx = buffer_1010_pdpd[1152];

    auto g_y_0_x_0_y_yz_x_xy = buffer_1010_pdpd[1153];

    auto g_y_0_x_0_y_yz_x_xz = buffer_1010_pdpd[1154];

    auto g_y_0_x_0_y_yz_x_yy = buffer_1010_pdpd[1155];

    auto g_y_0_x_0_y_yz_x_yz = buffer_1010_pdpd[1156];

    auto g_y_0_x_0_y_yz_x_zz = buffer_1010_pdpd[1157];

    auto g_y_0_x_0_y_yz_y_xx = buffer_1010_pdpd[1158];

    auto g_y_0_x_0_y_yz_y_xy = buffer_1010_pdpd[1159];

    auto g_y_0_x_0_y_yz_y_xz = buffer_1010_pdpd[1160];

    auto g_y_0_x_0_y_yz_y_yy = buffer_1010_pdpd[1161];

    auto g_y_0_x_0_y_yz_y_yz = buffer_1010_pdpd[1162];

    auto g_y_0_x_0_y_yz_y_zz = buffer_1010_pdpd[1163];

    auto g_y_0_x_0_y_yz_z_xx = buffer_1010_pdpd[1164];

    auto g_y_0_x_0_y_yz_z_xy = buffer_1010_pdpd[1165];

    auto g_y_0_x_0_y_yz_z_xz = buffer_1010_pdpd[1166];

    auto g_y_0_x_0_y_yz_z_yy = buffer_1010_pdpd[1167];

    auto g_y_0_x_0_y_yz_z_yz = buffer_1010_pdpd[1168];

    auto g_y_0_x_0_y_yz_z_zz = buffer_1010_pdpd[1169];

    auto g_y_0_x_0_y_zz_x_xx = buffer_1010_pdpd[1170];

    auto g_y_0_x_0_y_zz_x_xy = buffer_1010_pdpd[1171];

    auto g_y_0_x_0_y_zz_x_xz = buffer_1010_pdpd[1172];

    auto g_y_0_x_0_y_zz_x_yy = buffer_1010_pdpd[1173];

    auto g_y_0_x_0_y_zz_x_yz = buffer_1010_pdpd[1174];

    auto g_y_0_x_0_y_zz_x_zz = buffer_1010_pdpd[1175];

    auto g_y_0_x_0_y_zz_y_xx = buffer_1010_pdpd[1176];

    auto g_y_0_x_0_y_zz_y_xy = buffer_1010_pdpd[1177];

    auto g_y_0_x_0_y_zz_y_xz = buffer_1010_pdpd[1178];

    auto g_y_0_x_0_y_zz_y_yy = buffer_1010_pdpd[1179];

    auto g_y_0_x_0_y_zz_y_yz = buffer_1010_pdpd[1180];

    auto g_y_0_x_0_y_zz_y_zz = buffer_1010_pdpd[1181];

    auto g_y_0_x_0_y_zz_z_xx = buffer_1010_pdpd[1182];

    auto g_y_0_x_0_y_zz_z_xy = buffer_1010_pdpd[1183];

    auto g_y_0_x_0_y_zz_z_xz = buffer_1010_pdpd[1184];

    auto g_y_0_x_0_y_zz_z_yy = buffer_1010_pdpd[1185];

    auto g_y_0_x_0_y_zz_z_yz = buffer_1010_pdpd[1186];

    auto g_y_0_x_0_y_zz_z_zz = buffer_1010_pdpd[1187];

    auto g_y_0_x_0_z_xx_x_xx = buffer_1010_pdpd[1188];

    auto g_y_0_x_0_z_xx_x_xy = buffer_1010_pdpd[1189];

    auto g_y_0_x_0_z_xx_x_xz = buffer_1010_pdpd[1190];

    auto g_y_0_x_0_z_xx_x_yy = buffer_1010_pdpd[1191];

    auto g_y_0_x_0_z_xx_x_yz = buffer_1010_pdpd[1192];

    auto g_y_0_x_0_z_xx_x_zz = buffer_1010_pdpd[1193];

    auto g_y_0_x_0_z_xx_y_xx = buffer_1010_pdpd[1194];

    auto g_y_0_x_0_z_xx_y_xy = buffer_1010_pdpd[1195];

    auto g_y_0_x_0_z_xx_y_xz = buffer_1010_pdpd[1196];

    auto g_y_0_x_0_z_xx_y_yy = buffer_1010_pdpd[1197];

    auto g_y_0_x_0_z_xx_y_yz = buffer_1010_pdpd[1198];

    auto g_y_0_x_0_z_xx_y_zz = buffer_1010_pdpd[1199];

    auto g_y_0_x_0_z_xx_z_xx = buffer_1010_pdpd[1200];

    auto g_y_0_x_0_z_xx_z_xy = buffer_1010_pdpd[1201];

    auto g_y_0_x_0_z_xx_z_xz = buffer_1010_pdpd[1202];

    auto g_y_0_x_0_z_xx_z_yy = buffer_1010_pdpd[1203];

    auto g_y_0_x_0_z_xx_z_yz = buffer_1010_pdpd[1204];

    auto g_y_0_x_0_z_xx_z_zz = buffer_1010_pdpd[1205];

    auto g_y_0_x_0_z_xy_x_xx = buffer_1010_pdpd[1206];

    auto g_y_0_x_0_z_xy_x_xy = buffer_1010_pdpd[1207];

    auto g_y_0_x_0_z_xy_x_xz = buffer_1010_pdpd[1208];

    auto g_y_0_x_0_z_xy_x_yy = buffer_1010_pdpd[1209];

    auto g_y_0_x_0_z_xy_x_yz = buffer_1010_pdpd[1210];

    auto g_y_0_x_0_z_xy_x_zz = buffer_1010_pdpd[1211];

    auto g_y_0_x_0_z_xy_y_xx = buffer_1010_pdpd[1212];

    auto g_y_0_x_0_z_xy_y_xy = buffer_1010_pdpd[1213];

    auto g_y_0_x_0_z_xy_y_xz = buffer_1010_pdpd[1214];

    auto g_y_0_x_0_z_xy_y_yy = buffer_1010_pdpd[1215];

    auto g_y_0_x_0_z_xy_y_yz = buffer_1010_pdpd[1216];

    auto g_y_0_x_0_z_xy_y_zz = buffer_1010_pdpd[1217];

    auto g_y_0_x_0_z_xy_z_xx = buffer_1010_pdpd[1218];

    auto g_y_0_x_0_z_xy_z_xy = buffer_1010_pdpd[1219];

    auto g_y_0_x_0_z_xy_z_xz = buffer_1010_pdpd[1220];

    auto g_y_0_x_0_z_xy_z_yy = buffer_1010_pdpd[1221];

    auto g_y_0_x_0_z_xy_z_yz = buffer_1010_pdpd[1222];

    auto g_y_0_x_0_z_xy_z_zz = buffer_1010_pdpd[1223];

    auto g_y_0_x_0_z_xz_x_xx = buffer_1010_pdpd[1224];

    auto g_y_0_x_0_z_xz_x_xy = buffer_1010_pdpd[1225];

    auto g_y_0_x_0_z_xz_x_xz = buffer_1010_pdpd[1226];

    auto g_y_0_x_0_z_xz_x_yy = buffer_1010_pdpd[1227];

    auto g_y_0_x_0_z_xz_x_yz = buffer_1010_pdpd[1228];

    auto g_y_0_x_0_z_xz_x_zz = buffer_1010_pdpd[1229];

    auto g_y_0_x_0_z_xz_y_xx = buffer_1010_pdpd[1230];

    auto g_y_0_x_0_z_xz_y_xy = buffer_1010_pdpd[1231];

    auto g_y_0_x_0_z_xz_y_xz = buffer_1010_pdpd[1232];

    auto g_y_0_x_0_z_xz_y_yy = buffer_1010_pdpd[1233];

    auto g_y_0_x_0_z_xz_y_yz = buffer_1010_pdpd[1234];

    auto g_y_0_x_0_z_xz_y_zz = buffer_1010_pdpd[1235];

    auto g_y_0_x_0_z_xz_z_xx = buffer_1010_pdpd[1236];

    auto g_y_0_x_0_z_xz_z_xy = buffer_1010_pdpd[1237];

    auto g_y_0_x_0_z_xz_z_xz = buffer_1010_pdpd[1238];

    auto g_y_0_x_0_z_xz_z_yy = buffer_1010_pdpd[1239];

    auto g_y_0_x_0_z_xz_z_yz = buffer_1010_pdpd[1240];

    auto g_y_0_x_0_z_xz_z_zz = buffer_1010_pdpd[1241];

    auto g_y_0_x_0_z_yy_x_xx = buffer_1010_pdpd[1242];

    auto g_y_0_x_0_z_yy_x_xy = buffer_1010_pdpd[1243];

    auto g_y_0_x_0_z_yy_x_xz = buffer_1010_pdpd[1244];

    auto g_y_0_x_0_z_yy_x_yy = buffer_1010_pdpd[1245];

    auto g_y_0_x_0_z_yy_x_yz = buffer_1010_pdpd[1246];

    auto g_y_0_x_0_z_yy_x_zz = buffer_1010_pdpd[1247];

    auto g_y_0_x_0_z_yy_y_xx = buffer_1010_pdpd[1248];

    auto g_y_0_x_0_z_yy_y_xy = buffer_1010_pdpd[1249];

    auto g_y_0_x_0_z_yy_y_xz = buffer_1010_pdpd[1250];

    auto g_y_0_x_0_z_yy_y_yy = buffer_1010_pdpd[1251];

    auto g_y_0_x_0_z_yy_y_yz = buffer_1010_pdpd[1252];

    auto g_y_0_x_0_z_yy_y_zz = buffer_1010_pdpd[1253];

    auto g_y_0_x_0_z_yy_z_xx = buffer_1010_pdpd[1254];

    auto g_y_0_x_0_z_yy_z_xy = buffer_1010_pdpd[1255];

    auto g_y_0_x_0_z_yy_z_xz = buffer_1010_pdpd[1256];

    auto g_y_0_x_0_z_yy_z_yy = buffer_1010_pdpd[1257];

    auto g_y_0_x_0_z_yy_z_yz = buffer_1010_pdpd[1258];

    auto g_y_0_x_0_z_yy_z_zz = buffer_1010_pdpd[1259];

    auto g_y_0_x_0_z_yz_x_xx = buffer_1010_pdpd[1260];

    auto g_y_0_x_0_z_yz_x_xy = buffer_1010_pdpd[1261];

    auto g_y_0_x_0_z_yz_x_xz = buffer_1010_pdpd[1262];

    auto g_y_0_x_0_z_yz_x_yy = buffer_1010_pdpd[1263];

    auto g_y_0_x_0_z_yz_x_yz = buffer_1010_pdpd[1264];

    auto g_y_0_x_0_z_yz_x_zz = buffer_1010_pdpd[1265];

    auto g_y_0_x_0_z_yz_y_xx = buffer_1010_pdpd[1266];

    auto g_y_0_x_0_z_yz_y_xy = buffer_1010_pdpd[1267];

    auto g_y_0_x_0_z_yz_y_xz = buffer_1010_pdpd[1268];

    auto g_y_0_x_0_z_yz_y_yy = buffer_1010_pdpd[1269];

    auto g_y_0_x_0_z_yz_y_yz = buffer_1010_pdpd[1270];

    auto g_y_0_x_0_z_yz_y_zz = buffer_1010_pdpd[1271];

    auto g_y_0_x_0_z_yz_z_xx = buffer_1010_pdpd[1272];

    auto g_y_0_x_0_z_yz_z_xy = buffer_1010_pdpd[1273];

    auto g_y_0_x_0_z_yz_z_xz = buffer_1010_pdpd[1274];

    auto g_y_0_x_0_z_yz_z_yy = buffer_1010_pdpd[1275];

    auto g_y_0_x_0_z_yz_z_yz = buffer_1010_pdpd[1276];

    auto g_y_0_x_0_z_yz_z_zz = buffer_1010_pdpd[1277];

    auto g_y_0_x_0_z_zz_x_xx = buffer_1010_pdpd[1278];

    auto g_y_0_x_0_z_zz_x_xy = buffer_1010_pdpd[1279];

    auto g_y_0_x_0_z_zz_x_xz = buffer_1010_pdpd[1280];

    auto g_y_0_x_0_z_zz_x_yy = buffer_1010_pdpd[1281];

    auto g_y_0_x_0_z_zz_x_yz = buffer_1010_pdpd[1282];

    auto g_y_0_x_0_z_zz_x_zz = buffer_1010_pdpd[1283];

    auto g_y_0_x_0_z_zz_y_xx = buffer_1010_pdpd[1284];

    auto g_y_0_x_0_z_zz_y_xy = buffer_1010_pdpd[1285];

    auto g_y_0_x_0_z_zz_y_xz = buffer_1010_pdpd[1286];

    auto g_y_0_x_0_z_zz_y_yy = buffer_1010_pdpd[1287];

    auto g_y_0_x_0_z_zz_y_yz = buffer_1010_pdpd[1288];

    auto g_y_0_x_0_z_zz_y_zz = buffer_1010_pdpd[1289];

    auto g_y_0_x_0_z_zz_z_xx = buffer_1010_pdpd[1290];

    auto g_y_0_x_0_z_zz_z_xy = buffer_1010_pdpd[1291];

    auto g_y_0_x_0_z_zz_z_xz = buffer_1010_pdpd[1292];

    auto g_y_0_x_0_z_zz_z_yy = buffer_1010_pdpd[1293];

    auto g_y_0_x_0_z_zz_z_yz = buffer_1010_pdpd[1294];

    auto g_y_0_x_0_z_zz_z_zz = buffer_1010_pdpd[1295];

    auto g_y_0_y_0_x_xx_x_xx = buffer_1010_pdpd[1296];

    auto g_y_0_y_0_x_xx_x_xy = buffer_1010_pdpd[1297];

    auto g_y_0_y_0_x_xx_x_xz = buffer_1010_pdpd[1298];

    auto g_y_0_y_0_x_xx_x_yy = buffer_1010_pdpd[1299];

    auto g_y_0_y_0_x_xx_x_yz = buffer_1010_pdpd[1300];

    auto g_y_0_y_0_x_xx_x_zz = buffer_1010_pdpd[1301];

    auto g_y_0_y_0_x_xx_y_xx = buffer_1010_pdpd[1302];

    auto g_y_0_y_0_x_xx_y_xy = buffer_1010_pdpd[1303];

    auto g_y_0_y_0_x_xx_y_xz = buffer_1010_pdpd[1304];

    auto g_y_0_y_0_x_xx_y_yy = buffer_1010_pdpd[1305];

    auto g_y_0_y_0_x_xx_y_yz = buffer_1010_pdpd[1306];

    auto g_y_0_y_0_x_xx_y_zz = buffer_1010_pdpd[1307];

    auto g_y_0_y_0_x_xx_z_xx = buffer_1010_pdpd[1308];

    auto g_y_0_y_0_x_xx_z_xy = buffer_1010_pdpd[1309];

    auto g_y_0_y_0_x_xx_z_xz = buffer_1010_pdpd[1310];

    auto g_y_0_y_0_x_xx_z_yy = buffer_1010_pdpd[1311];

    auto g_y_0_y_0_x_xx_z_yz = buffer_1010_pdpd[1312];

    auto g_y_0_y_0_x_xx_z_zz = buffer_1010_pdpd[1313];

    auto g_y_0_y_0_x_xy_x_xx = buffer_1010_pdpd[1314];

    auto g_y_0_y_0_x_xy_x_xy = buffer_1010_pdpd[1315];

    auto g_y_0_y_0_x_xy_x_xz = buffer_1010_pdpd[1316];

    auto g_y_0_y_0_x_xy_x_yy = buffer_1010_pdpd[1317];

    auto g_y_0_y_0_x_xy_x_yz = buffer_1010_pdpd[1318];

    auto g_y_0_y_0_x_xy_x_zz = buffer_1010_pdpd[1319];

    auto g_y_0_y_0_x_xy_y_xx = buffer_1010_pdpd[1320];

    auto g_y_0_y_0_x_xy_y_xy = buffer_1010_pdpd[1321];

    auto g_y_0_y_0_x_xy_y_xz = buffer_1010_pdpd[1322];

    auto g_y_0_y_0_x_xy_y_yy = buffer_1010_pdpd[1323];

    auto g_y_0_y_0_x_xy_y_yz = buffer_1010_pdpd[1324];

    auto g_y_0_y_0_x_xy_y_zz = buffer_1010_pdpd[1325];

    auto g_y_0_y_0_x_xy_z_xx = buffer_1010_pdpd[1326];

    auto g_y_0_y_0_x_xy_z_xy = buffer_1010_pdpd[1327];

    auto g_y_0_y_0_x_xy_z_xz = buffer_1010_pdpd[1328];

    auto g_y_0_y_0_x_xy_z_yy = buffer_1010_pdpd[1329];

    auto g_y_0_y_0_x_xy_z_yz = buffer_1010_pdpd[1330];

    auto g_y_0_y_0_x_xy_z_zz = buffer_1010_pdpd[1331];

    auto g_y_0_y_0_x_xz_x_xx = buffer_1010_pdpd[1332];

    auto g_y_0_y_0_x_xz_x_xy = buffer_1010_pdpd[1333];

    auto g_y_0_y_0_x_xz_x_xz = buffer_1010_pdpd[1334];

    auto g_y_0_y_0_x_xz_x_yy = buffer_1010_pdpd[1335];

    auto g_y_0_y_0_x_xz_x_yz = buffer_1010_pdpd[1336];

    auto g_y_0_y_0_x_xz_x_zz = buffer_1010_pdpd[1337];

    auto g_y_0_y_0_x_xz_y_xx = buffer_1010_pdpd[1338];

    auto g_y_0_y_0_x_xz_y_xy = buffer_1010_pdpd[1339];

    auto g_y_0_y_0_x_xz_y_xz = buffer_1010_pdpd[1340];

    auto g_y_0_y_0_x_xz_y_yy = buffer_1010_pdpd[1341];

    auto g_y_0_y_0_x_xz_y_yz = buffer_1010_pdpd[1342];

    auto g_y_0_y_0_x_xz_y_zz = buffer_1010_pdpd[1343];

    auto g_y_0_y_0_x_xz_z_xx = buffer_1010_pdpd[1344];

    auto g_y_0_y_0_x_xz_z_xy = buffer_1010_pdpd[1345];

    auto g_y_0_y_0_x_xz_z_xz = buffer_1010_pdpd[1346];

    auto g_y_0_y_0_x_xz_z_yy = buffer_1010_pdpd[1347];

    auto g_y_0_y_0_x_xz_z_yz = buffer_1010_pdpd[1348];

    auto g_y_0_y_0_x_xz_z_zz = buffer_1010_pdpd[1349];

    auto g_y_0_y_0_x_yy_x_xx = buffer_1010_pdpd[1350];

    auto g_y_0_y_0_x_yy_x_xy = buffer_1010_pdpd[1351];

    auto g_y_0_y_0_x_yy_x_xz = buffer_1010_pdpd[1352];

    auto g_y_0_y_0_x_yy_x_yy = buffer_1010_pdpd[1353];

    auto g_y_0_y_0_x_yy_x_yz = buffer_1010_pdpd[1354];

    auto g_y_0_y_0_x_yy_x_zz = buffer_1010_pdpd[1355];

    auto g_y_0_y_0_x_yy_y_xx = buffer_1010_pdpd[1356];

    auto g_y_0_y_0_x_yy_y_xy = buffer_1010_pdpd[1357];

    auto g_y_0_y_0_x_yy_y_xz = buffer_1010_pdpd[1358];

    auto g_y_0_y_0_x_yy_y_yy = buffer_1010_pdpd[1359];

    auto g_y_0_y_0_x_yy_y_yz = buffer_1010_pdpd[1360];

    auto g_y_0_y_0_x_yy_y_zz = buffer_1010_pdpd[1361];

    auto g_y_0_y_0_x_yy_z_xx = buffer_1010_pdpd[1362];

    auto g_y_0_y_0_x_yy_z_xy = buffer_1010_pdpd[1363];

    auto g_y_0_y_0_x_yy_z_xz = buffer_1010_pdpd[1364];

    auto g_y_0_y_0_x_yy_z_yy = buffer_1010_pdpd[1365];

    auto g_y_0_y_0_x_yy_z_yz = buffer_1010_pdpd[1366];

    auto g_y_0_y_0_x_yy_z_zz = buffer_1010_pdpd[1367];

    auto g_y_0_y_0_x_yz_x_xx = buffer_1010_pdpd[1368];

    auto g_y_0_y_0_x_yz_x_xy = buffer_1010_pdpd[1369];

    auto g_y_0_y_0_x_yz_x_xz = buffer_1010_pdpd[1370];

    auto g_y_0_y_0_x_yz_x_yy = buffer_1010_pdpd[1371];

    auto g_y_0_y_0_x_yz_x_yz = buffer_1010_pdpd[1372];

    auto g_y_0_y_0_x_yz_x_zz = buffer_1010_pdpd[1373];

    auto g_y_0_y_0_x_yz_y_xx = buffer_1010_pdpd[1374];

    auto g_y_0_y_0_x_yz_y_xy = buffer_1010_pdpd[1375];

    auto g_y_0_y_0_x_yz_y_xz = buffer_1010_pdpd[1376];

    auto g_y_0_y_0_x_yz_y_yy = buffer_1010_pdpd[1377];

    auto g_y_0_y_0_x_yz_y_yz = buffer_1010_pdpd[1378];

    auto g_y_0_y_0_x_yz_y_zz = buffer_1010_pdpd[1379];

    auto g_y_0_y_0_x_yz_z_xx = buffer_1010_pdpd[1380];

    auto g_y_0_y_0_x_yz_z_xy = buffer_1010_pdpd[1381];

    auto g_y_0_y_0_x_yz_z_xz = buffer_1010_pdpd[1382];

    auto g_y_0_y_0_x_yz_z_yy = buffer_1010_pdpd[1383];

    auto g_y_0_y_0_x_yz_z_yz = buffer_1010_pdpd[1384];

    auto g_y_0_y_0_x_yz_z_zz = buffer_1010_pdpd[1385];

    auto g_y_0_y_0_x_zz_x_xx = buffer_1010_pdpd[1386];

    auto g_y_0_y_0_x_zz_x_xy = buffer_1010_pdpd[1387];

    auto g_y_0_y_0_x_zz_x_xz = buffer_1010_pdpd[1388];

    auto g_y_0_y_0_x_zz_x_yy = buffer_1010_pdpd[1389];

    auto g_y_0_y_0_x_zz_x_yz = buffer_1010_pdpd[1390];

    auto g_y_0_y_0_x_zz_x_zz = buffer_1010_pdpd[1391];

    auto g_y_0_y_0_x_zz_y_xx = buffer_1010_pdpd[1392];

    auto g_y_0_y_0_x_zz_y_xy = buffer_1010_pdpd[1393];

    auto g_y_0_y_0_x_zz_y_xz = buffer_1010_pdpd[1394];

    auto g_y_0_y_0_x_zz_y_yy = buffer_1010_pdpd[1395];

    auto g_y_0_y_0_x_zz_y_yz = buffer_1010_pdpd[1396];

    auto g_y_0_y_0_x_zz_y_zz = buffer_1010_pdpd[1397];

    auto g_y_0_y_0_x_zz_z_xx = buffer_1010_pdpd[1398];

    auto g_y_0_y_0_x_zz_z_xy = buffer_1010_pdpd[1399];

    auto g_y_0_y_0_x_zz_z_xz = buffer_1010_pdpd[1400];

    auto g_y_0_y_0_x_zz_z_yy = buffer_1010_pdpd[1401];

    auto g_y_0_y_0_x_zz_z_yz = buffer_1010_pdpd[1402];

    auto g_y_0_y_0_x_zz_z_zz = buffer_1010_pdpd[1403];

    auto g_y_0_y_0_y_xx_x_xx = buffer_1010_pdpd[1404];

    auto g_y_0_y_0_y_xx_x_xy = buffer_1010_pdpd[1405];

    auto g_y_0_y_0_y_xx_x_xz = buffer_1010_pdpd[1406];

    auto g_y_0_y_0_y_xx_x_yy = buffer_1010_pdpd[1407];

    auto g_y_0_y_0_y_xx_x_yz = buffer_1010_pdpd[1408];

    auto g_y_0_y_0_y_xx_x_zz = buffer_1010_pdpd[1409];

    auto g_y_0_y_0_y_xx_y_xx = buffer_1010_pdpd[1410];

    auto g_y_0_y_0_y_xx_y_xy = buffer_1010_pdpd[1411];

    auto g_y_0_y_0_y_xx_y_xz = buffer_1010_pdpd[1412];

    auto g_y_0_y_0_y_xx_y_yy = buffer_1010_pdpd[1413];

    auto g_y_0_y_0_y_xx_y_yz = buffer_1010_pdpd[1414];

    auto g_y_0_y_0_y_xx_y_zz = buffer_1010_pdpd[1415];

    auto g_y_0_y_0_y_xx_z_xx = buffer_1010_pdpd[1416];

    auto g_y_0_y_0_y_xx_z_xy = buffer_1010_pdpd[1417];

    auto g_y_0_y_0_y_xx_z_xz = buffer_1010_pdpd[1418];

    auto g_y_0_y_0_y_xx_z_yy = buffer_1010_pdpd[1419];

    auto g_y_0_y_0_y_xx_z_yz = buffer_1010_pdpd[1420];

    auto g_y_0_y_0_y_xx_z_zz = buffer_1010_pdpd[1421];

    auto g_y_0_y_0_y_xy_x_xx = buffer_1010_pdpd[1422];

    auto g_y_0_y_0_y_xy_x_xy = buffer_1010_pdpd[1423];

    auto g_y_0_y_0_y_xy_x_xz = buffer_1010_pdpd[1424];

    auto g_y_0_y_0_y_xy_x_yy = buffer_1010_pdpd[1425];

    auto g_y_0_y_0_y_xy_x_yz = buffer_1010_pdpd[1426];

    auto g_y_0_y_0_y_xy_x_zz = buffer_1010_pdpd[1427];

    auto g_y_0_y_0_y_xy_y_xx = buffer_1010_pdpd[1428];

    auto g_y_0_y_0_y_xy_y_xy = buffer_1010_pdpd[1429];

    auto g_y_0_y_0_y_xy_y_xz = buffer_1010_pdpd[1430];

    auto g_y_0_y_0_y_xy_y_yy = buffer_1010_pdpd[1431];

    auto g_y_0_y_0_y_xy_y_yz = buffer_1010_pdpd[1432];

    auto g_y_0_y_0_y_xy_y_zz = buffer_1010_pdpd[1433];

    auto g_y_0_y_0_y_xy_z_xx = buffer_1010_pdpd[1434];

    auto g_y_0_y_0_y_xy_z_xy = buffer_1010_pdpd[1435];

    auto g_y_0_y_0_y_xy_z_xz = buffer_1010_pdpd[1436];

    auto g_y_0_y_0_y_xy_z_yy = buffer_1010_pdpd[1437];

    auto g_y_0_y_0_y_xy_z_yz = buffer_1010_pdpd[1438];

    auto g_y_0_y_0_y_xy_z_zz = buffer_1010_pdpd[1439];

    auto g_y_0_y_0_y_xz_x_xx = buffer_1010_pdpd[1440];

    auto g_y_0_y_0_y_xz_x_xy = buffer_1010_pdpd[1441];

    auto g_y_0_y_0_y_xz_x_xz = buffer_1010_pdpd[1442];

    auto g_y_0_y_0_y_xz_x_yy = buffer_1010_pdpd[1443];

    auto g_y_0_y_0_y_xz_x_yz = buffer_1010_pdpd[1444];

    auto g_y_0_y_0_y_xz_x_zz = buffer_1010_pdpd[1445];

    auto g_y_0_y_0_y_xz_y_xx = buffer_1010_pdpd[1446];

    auto g_y_0_y_0_y_xz_y_xy = buffer_1010_pdpd[1447];

    auto g_y_0_y_0_y_xz_y_xz = buffer_1010_pdpd[1448];

    auto g_y_0_y_0_y_xz_y_yy = buffer_1010_pdpd[1449];

    auto g_y_0_y_0_y_xz_y_yz = buffer_1010_pdpd[1450];

    auto g_y_0_y_0_y_xz_y_zz = buffer_1010_pdpd[1451];

    auto g_y_0_y_0_y_xz_z_xx = buffer_1010_pdpd[1452];

    auto g_y_0_y_0_y_xz_z_xy = buffer_1010_pdpd[1453];

    auto g_y_0_y_0_y_xz_z_xz = buffer_1010_pdpd[1454];

    auto g_y_0_y_0_y_xz_z_yy = buffer_1010_pdpd[1455];

    auto g_y_0_y_0_y_xz_z_yz = buffer_1010_pdpd[1456];

    auto g_y_0_y_0_y_xz_z_zz = buffer_1010_pdpd[1457];

    auto g_y_0_y_0_y_yy_x_xx = buffer_1010_pdpd[1458];

    auto g_y_0_y_0_y_yy_x_xy = buffer_1010_pdpd[1459];

    auto g_y_0_y_0_y_yy_x_xz = buffer_1010_pdpd[1460];

    auto g_y_0_y_0_y_yy_x_yy = buffer_1010_pdpd[1461];

    auto g_y_0_y_0_y_yy_x_yz = buffer_1010_pdpd[1462];

    auto g_y_0_y_0_y_yy_x_zz = buffer_1010_pdpd[1463];

    auto g_y_0_y_0_y_yy_y_xx = buffer_1010_pdpd[1464];

    auto g_y_0_y_0_y_yy_y_xy = buffer_1010_pdpd[1465];

    auto g_y_0_y_0_y_yy_y_xz = buffer_1010_pdpd[1466];

    auto g_y_0_y_0_y_yy_y_yy = buffer_1010_pdpd[1467];

    auto g_y_0_y_0_y_yy_y_yz = buffer_1010_pdpd[1468];

    auto g_y_0_y_0_y_yy_y_zz = buffer_1010_pdpd[1469];

    auto g_y_0_y_0_y_yy_z_xx = buffer_1010_pdpd[1470];

    auto g_y_0_y_0_y_yy_z_xy = buffer_1010_pdpd[1471];

    auto g_y_0_y_0_y_yy_z_xz = buffer_1010_pdpd[1472];

    auto g_y_0_y_0_y_yy_z_yy = buffer_1010_pdpd[1473];

    auto g_y_0_y_0_y_yy_z_yz = buffer_1010_pdpd[1474];

    auto g_y_0_y_0_y_yy_z_zz = buffer_1010_pdpd[1475];

    auto g_y_0_y_0_y_yz_x_xx = buffer_1010_pdpd[1476];

    auto g_y_0_y_0_y_yz_x_xy = buffer_1010_pdpd[1477];

    auto g_y_0_y_0_y_yz_x_xz = buffer_1010_pdpd[1478];

    auto g_y_0_y_0_y_yz_x_yy = buffer_1010_pdpd[1479];

    auto g_y_0_y_0_y_yz_x_yz = buffer_1010_pdpd[1480];

    auto g_y_0_y_0_y_yz_x_zz = buffer_1010_pdpd[1481];

    auto g_y_0_y_0_y_yz_y_xx = buffer_1010_pdpd[1482];

    auto g_y_0_y_0_y_yz_y_xy = buffer_1010_pdpd[1483];

    auto g_y_0_y_0_y_yz_y_xz = buffer_1010_pdpd[1484];

    auto g_y_0_y_0_y_yz_y_yy = buffer_1010_pdpd[1485];

    auto g_y_0_y_0_y_yz_y_yz = buffer_1010_pdpd[1486];

    auto g_y_0_y_0_y_yz_y_zz = buffer_1010_pdpd[1487];

    auto g_y_0_y_0_y_yz_z_xx = buffer_1010_pdpd[1488];

    auto g_y_0_y_0_y_yz_z_xy = buffer_1010_pdpd[1489];

    auto g_y_0_y_0_y_yz_z_xz = buffer_1010_pdpd[1490];

    auto g_y_0_y_0_y_yz_z_yy = buffer_1010_pdpd[1491];

    auto g_y_0_y_0_y_yz_z_yz = buffer_1010_pdpd[1492];

    auto g_y_0_y_0_y_yz_z_zz = buffer_1010_pdpd[1493];

    auto g_y_0_y_0_y_zz_x_xx = buffer_1010_pdpd[1494];

    auto g_y_0_y_0_y_zz_x_xy = buffer_1010_pdpd[1495];

    auto g_y_0_y_0_y_zz_x_xz = buffer_1010_pdpd[1496];

    auto g_y_0_y_0_y_zz_x_yy = buffer_1010_pdpd[1497];

    auto g_y_0_y_0_y_zz_x_yz = buffer_1010_pdpd[1498];

    auto g_y_0_y_0_y_zz_x_zz = buffer_1010_pdpd[1499];

    auto g_y_0_y_0_y_zz_y_xx = buffer_1010_pdpd[1500];

    auto g_y_0_y_0_y_zz_y_xy = buffer_1010_pdpd[1501];

    auto g_y_0_y_0_y_zz_y_xz = buffer_1010_pdpd[1502];

    auto g_y_0_y_0_y_zz_y_yy = buffer_1010_pdpd[1503];

    auto g_y_0_y_0_y_zz_y_yz = buffer_1010_pdpd[1504];

    auto g_y_0_y_0_y_zz_y_zz = buffer_1010_pdpd[1505];

    auto g_y_0_y_0_y_zz_z_xx = buffer_1010_pdpd[1506];

    auto g_y_0_y_0_y_zz_z_xy = buffer_1010_pdpd[1507];

    auto g_y_0_y_0_y_zz_z_xz = buffer_1010_pdpd[1508];

    auto g_y_0_y_0_y_zz_z_yy = buffer_1010_pdpd[1509];

    auto g_y_0_y_0_y_zz_z_yz = buffer_1010_pdpd[1510];

    auto g_y_0_y_0_y_zz_z_zz = buffer_1010_pdpd[1511];

    auto g_y_0_y_0_z_xx_x_xx = buffer_1010_pdpd[1512];

    auto g_y_0_y_0_z_xx_x_xy = buffer_1010_pdpd[1513];

    auto g_y_0_y_0_z_xx_x_xz = buffer_1010_pdpd[1514];

    auto g_y_0_y_0_z_xx_x_yy = buffer_1010_pdpd[1515];

    auto g_y_0_y_0_z_xx_x_yz = buffer_1010_pdpd[1516];

    auto g_y_0_y_0_z_xx_x_zz = buffer_1010_pdpd[1517];

    auto g_y_0_y_0_z_xx_y_xx = buffer_1010_pdpd[1518];

    auto g_y_0_y_0_z_xx_y_xy = buffer_1010_pdpd[1519];

    auto g_y_0_y_0_z_xx_y_xz = buffer_1010_pdpd[1520];

    auto g_y_0_y_0_z_xx_y_yy = buffer_1010_pdpd[1521];

    auto g_y_0_y_0_z_xx_y_yz = buffer_1010_pdpd[1522];

    auto g_y_0_y_0_z_xx_y_zz = buffer_1010_pdpd[1523];

    auto g_y_0_y_0_z_xx_z_xx = buffer_1010_pdpd[1524];

    auto g_y_0_y_0_z_xx_z_xy = buffer_1010_pdpd[1525];

    auto g_y_0_y_0_z_xx_z_xz = buffer_1010_pdpd[1526];

    auto g_y_0_y_0_z_xx_z_yy = buffer_1010_pdpd[1527];

    auto g_y_0_y_0_z_xx_z_yz = buffer_1010_pdpd[1528];

    auto g_y_0_y_0_z_xx_z_zz = buffer_1010_pdpd[1529];

    auto g_y_0_y_0_z_xy_x_xx = buffer_1010_pdpd[1530];

    auto g_y_0_y_0_z_xy_x_xy = buffer_1010_pdpd[1531];

    auto g_y_0_y_0_z_xy_x_xz = buffer_1010_pdpd[1532];

    auto g_y_0_y_0_z_xy_x_yy = buffer_1010_pdpd[1533];

    auto g_y_0_y_0_z_xy_x_yz = buffer_1010_pdpd[1534];

    auto g_y_0_y_0_z_xy_x_zz = buffer_1010_pdpd[1535];

    auto g_y_0_y_0_z_xy_y_xx = buffer_1010_pdpd[1536];

    auto g_y_0_y_0_z_xy_y_xy = buffer_1010_pdpd[1537];

    auto g_y_0_y_0_z_xy_y_xz = buffer_1010_pdpd[1538];

    auto g_y_0_y_0_z_xy_y_yy = buffer_1010_pdpd[1539];

    auto g_y_0_y_0_z_xy_y_yz = buffer_1010_pdpd[1540];

    auto g_y_0_y_0_z_xy_y_zz = buffer_1010_pdpd[1541];

    auto g_y_0_y_0_z_xy_z_xx = buffer_1010_pdpd[1542];

    auto g_y_0_y_0_z_xy_z_xy = buffer_1010_pdpd[1543];

    auto g_y_0_y_0_z_xy_z_xz = buffer_1010_pdpd[1544];

    auto g_y_0_y_0_z_xy_z_yy = buffer_1010_pdpd[1545];

    auto g_y_0_y_0_z_xy_z_yz = buffer_1010_pdpd[1546];

    auto g_y_0_y_0_z_xy_z_zz = buffer_1010_pdpd[1547];

    auto g_y_0_y_0_z_xz_x_xx = buffer_1010_pdpd[1548];

    auto g_y_0_y_0_z_xz_x_xy = buffer_1010_pdpd[1549];

    auto g_y_0_y_0_z_xz_x_xz = buffer_1010_pdpd[1550];

    auto g_y_0_y_0_z_xz_x_yy = buffer_1010_pdpd[1551];

    auto g_y_0_y_0_z_xz_x_yz = buffer_1010_pdpd[1552];

    auto g_y_0_y_0_z_xz_x_zz = buffer_1010_pdpd[1553];

    auto g_y_0_y_0_z_xz_y_xx = buffer_1010_pdpd[1554];

    auto g_y_0_y_0_z_xz_y_xy = buffer_1010_pdpd[1555];

    auto g_y_0_y_0_z_xz_y_xz = buffer_1010_pdpd[1556];

    auto g_y_0_y_0_z_xz_y_yy = buffer_1010_pdpd[1557];

    auto g_y_0_y_0_z_xz_y_yz = buffer_1010_pdpd[1558];

    auto g_y_0_y_0_z_xz_y_zz = buffer_1010_pdpd[1559];

    auto g_y_0_y_0_z_xz_z_xx = buffer_1010_pdpd[1560];

    auto g_y_0_y_0_z_xz_z_xy = buffer_1010_pdpd[1561];

    auto g_y_0_y_0_z_xz_z_xz = buffer_1010_pdpd[1562];

    auto g_y_0_y_0_z_xz_z_yy = buffer_1010_pdpd[1563];

    auto g_y_0_y_0_z_xz_z_yz = buffer_1010_pdpd[1564];

    auto g_y_0_y_0_z_xz_z_zz = buffer_1010_pdpd[1565];

    auto g_y_0_y_0_z_yy_x_xx = buffer_1010_pdpd[1566];

    auto g_y_0_y_0_z_yy_x_xy = buffer_1010_pdpd[1567];

    auto g_y_0_y_0_z_yy_x_xz = buffer_1010_pdpd[1568];

    auto g_y_0_y_0_z_yy_x_yy = buffer_1010_pdpd[1569];

    auto g_y_0_y_0_z_yy_x_yz = buffer_1010_pdpd[1570];

    auto g_y_0_y_0_z_yy_x_zz = buffer_1010_pdpd[1571];

    auto g_y_0_y_0_z_yy_y_xx = buffer_1010_pdpd[1572];

    auto g_y_0_y_0_z_yy_y_xy = buffer_1010_pdpd[1573];

    auto g_y_0_y_0_z_yy_y_xz = buffer_1010_pdpd[1574];

    auto g_y_0_y_0_z_yy_y_yy = buffer_1010_pdpd[1575];

    auto g_y_0_y_0_z_yy_y_yz = buffer_1010_pdpd[1576];

    auto g_y_0_y_0_z_yy_y_zz = buffer_1010_pdpd[1577];

    auto g_y_0_y_0_z_yy_z_xx = buffer_1010_pdpd[1578];

    auto g_y_0_y_0_z_yy_z_xy = buffer_1010_pdpd[1579];

    auto g_y_0_y_0_z_yy_z_xz = buffer_1010_pdpd[1580];

    auto g_y_0_y_0_z_yy_z_yy = buffer_1010_pdpd[1581];

    auto g_y_0_y_0_z_yy_z_yz = buffer_1010_pdpd[1582];

    auto g_y_0_y_0_z_yy_z_zz = buffer_1010_pdpd[1583];

    auto g_y_0_y_0_z_yz_x_xx = buffer_1010_pdpd[1584];

    auto g_y_0_y_0_z_yz_x_xy = buffer_1010_pdpd[1585];

    auto g_y_0_y_0_z_yz_x_xz = buffer_1010_pdpd[1586];

    auto g_y_0_y_0_z_yz_x_yy = buffer_1010_pdpd[1587];

    auto g_y_0_y_0_z_yz_x_yz = buffer_1010_pdpd[1588];

    auto g_y_0_y_0_z_yz_x_zz = buffer_1010_pdpd[1589];

    auto g_y_0_y_0_z_yz_y_xx = buffer_1010_pdpd[1590];

    auto g_y_0_y_0_z_yz_y_xy = buffer_1010_pdpd[1591];

    auto g_y_0_y_0_z_yz_y_xz = buffer_1010_pdpd[1592];

    auto g_y_0_y_0_z_yz_y_yy = buffer_1010_pdpd[1593];

    auto g_y_0_y_0_z_yz_y_yz = buffer_1010_pdpd[1594];

    auto g_y_0_y_0_z_yz_y_zz = buffer_1010_pdpd[1595];

    auto g_y_0_y_0_z_yz_z_xx = buffer_1010_pdpd[1596];

    auto g_y_0_y_0_z_yz_z_xy = buffer_1010_pdpd[1597];

    auto g_y_0_y_0_z_yz_z_xz = buffer_1010_pdpd[1598];

    auto g_y_0_y_0_z_yz_z_yy = buffer_1010_pdpd[1599];

    auto g_y_0_y_0_z_yz_z_yz = buffer_1010_pdpd[1600];

    auto g_y_0_y_0_z_yz_z_zz = buffer_1010_pdpd[1601];

    auto g_y_0_y_0_z_zz_x_xx = buffer_1010_pdpd[1602];

    auto g_y_0_y_0_z_zz_x_xy = buffer_1010_pdpd[1603];

    auto g_y_0_y_0_z_zz_x_xz = buffer_1010_pdpd[1604];

    auto g_y_0_y_0_z_zz_x_yy = buffer_1010_pdpd[1605];

    auto g_y_0_y_0_z_zz_x_yz = buffer_1010_pdpd[1606];

    auto g_y_0_y_0_z_zz_x_zz = buffer_1010_pdpd[1607];

    auto g_y_0_y_0_z_zz_y_xx = buffer_1010_pdpd[1608];

    auto g_y_0_y_0_z_zz_y_xy = buffer_1010_pdpd[1609];

    auto g_y_0_y_0_z_zz_y_xz = buffer_1010_pdpd[1610];

    auto g_y_0_y_0_z_zz_y_yy = buffer_1010_pdpd[1611];

    auto g_y_0_y_0_z_zz_y_yz = buffer_1010_pdpd[1612];

    auto g_y_0_y_0_z_zz_y_zz = buffer_1010_pdpd[1613];

    auto g_y_0_y_0_z_zz_z_xx = buffer_1010_pdpd[1614];

    auto g_y_0_y_0_z_zz_z_xy = buffer_1010_pdpd[1615];

    auto g_y_0_y_0_z_zz_z_xz = buffer_1010_pdpd[1616];

    auto g_y_0_y_0_z_zz_z_yy = buffer_1010_pdpd[1617];

    auto g_y_0_y_0_z_zz_z_yz = buffer_1010_pdpd[1618];

    auto g_y_0_y_0_z_zz_z_zz = buffer_1010_pdpd[1619];

    auto g_y_0_z_0_x_xx_x_xx = buffer_1010_pdpd[1620];

    auto g_y_0_z_0_x_xx_x_xy = buffer_1010_pdpd[1621];

    auto g_y_0_z_0_x_xx_x_xz = buffer_1010_pdpd[1622];

    auto g_y_0_z_0_x_xx_x_yy = buffer_1010_pdpd[1623];

    auto g_y_0_z_0_x_xx_x_yz = buffer_1010_pdpd[1624];

    auto g_y_0_z_0_x_xx_x_zz = buffer_1010_pdpd[1625];

    auto g_y_0_z_0_x_xx_y_xx = buffer_1010_pdpd[1626];

    auto g_y_0_z_0_x_xx_y_xy = buffer_1010_pdpd[1627];

    auto g_y_0_z_0_x_xx_y_xz = buffer_1010_pdpd[1628];

    auto g_y_0_z_0_x_xx_y_yy = buffer_1010_pdpd[1629];

    auto g_y_0_z_0_x_xx_y_yz = buffer_1010_pdpd[1630];

    auto g_y_0_z_0_x_xx_y_zz = buffer_1010_pdpd[1631];

    auto g_y_0_z_0_x_xx_z_xx = buffer_1010_pdpd[1632];

    auto g_y_0_z_0_x_xx_z_xy = buffer_1010_pdpd[1633];

    auto g_y_0_z_0_x_xx_z_xz = buffer_1010_pdpd[1634];

    auto g_y_0_z_0_x_xx_z_yy = buffer_1010_pdpd[1635];

    auto g_y_0_z_0_x_xx_z_yz = buffer_1010_pdpd[1636];

    auto g_y_0_z_0_x_xx_z_zz = buffer_1010_pdpd[1637];

    auto g_y_0_z_0_x_xy_x_xx = buffer_1010_pdpd[1638];

    auto g_y_0_z_0_x_xy_x_xy = buffer_1010_pdpd[1639];

    auto g_y_0_z_0_x_xy_x_xz = buffer_1010_pdpd[1640];

    auto g_y_0_z_0_x_xy_x_yy = buffer_1010_pdpd[1641];

    auto g_y_0_z_0_x_xy_x_yz = buffer_1010_pdpd[1642];

    auto g_y_0_z_0_x_xy_x_zz = buffer_1010_pdpd[1643];

    auto g_y_0_z_0_x_xy_y_xx = buffer_1010_pdpd[1644];

    auto g_y_0_z_0_x_xy_y_xy = buffer_1010_pdpd[1645];

    auto g_y_0_z_0_x_xy_y_xz = buffer_1010_pdpd[1646];

    auto g_y_0_z_0_x_xy_y_yy = buffer_1010_pdpd[1647];

    auto g_y_0_z_0_x_xy_y_yz = buffer_1010_pdpd[1648];

    auto g_y_0_z_0_x_xy_y_zz = buffer_1010_pdpd[1649];

    auto g_y_0_z_0_x_xy_z_xx = buffer_1010_pdpd[1650];

    auto g_y_0_z_0_x_xy_z_xy = buffer_1010_pdpd[1651];

    auto g_y_0_z_0_x_xy_z_xz = buffer_1010_pdpd[1652];

    auto g_y_0_z_0_x_xy_z_yy = buffer_1010_pdpd[1653];

    auto g_y_0_z_0_x_xy_z_yz = buffer_1010_pdpd[1654];

    auto g_y_0_z_0_x_xy_z_zz = buffer_1010_pdpd[1655];

    auto g_y_0_z_0_x_xz_x_xx = buffer_1010_pdpd[1656];

    auto g_y_0_z_0_x_xz_x_xy = buffer_1010_pdpd[1657];

    auto g_y_0_z_0_x_xz_x_xz = buffer_1010_pdpd[1658];

    auto g_y_0_z_0_x_xz_x_yy = buffer_1010_pdpd[1659];

    auto g_y_0_z_0_x_xz_x_yz = buffer_1010_pdpd[1660];

    auto g_y_0_z_0_x_xz_x_zz = buffer_1010_pdpd[1661];

    auto g_y_0_z_0_x_xz_y_xx = buffer_1010_pdpd[1662];

    auto g_y_0_z_0_x_xz_y_xy = buffer_1010_pdpd[1663];

    auto g_y_0_z_0_x_xz_y_xz = buffer_1010_pdpd[1664];

    auto g_y_0_z_0_x_xz_y_yy = buffer_1010_pdpd[1665];

    auto g_y_0_z_0_x_xz_y_yz = buffer_1010_pdpd[1666];

    auto g_y_0_z_0_x_xz_y_zz = buffer_1010_pdpd[1667];

    auto g_y_0_z_0_x_xz_z_xx = buffer_1010_pdpd[1668];

    auto g_y_0_z_0_x_xz_z_xy = buffer_1010_pdpd[1669];

    auto g_y_0_z_0_x_xz_z_xz = buffer_1010_pdpd[1670];

    auto g_y_0_z_0_x_xz_z_yy = buffer_1010_pdpd[1671];

    auto g_y_0_z_0_x_xz_z_yz = buffer_1010_pdpd[1672];

    auto g_y_0_z_0_x_xz_z_zz = buffer_1010_pdpd[1673];

    auto g_y_0_z_0_x_yy_x_xx = buffer_1010_pdpd[1674];

    auto g_y_0_z_0_x_yy_x_xy = buffer_1010_pdpd[1675];

    auto g_y_0_z_0_x_yy_x_xz = buffer_1010_pdpd[1676];

    auto g_y_0_z_0_x_yy_x_yy = buffer_1010_pdpd[1677];

    auto g_y_0_z_0_x_yy_x_yz = buffer_1010_pdpd[1678];

    auto g_y_0_z_0_x_yy_x_zz = buffer_1010_pdpd[1679];

    auto g_y_0_z_0_x_yy_y_xx = buffer_1010_pdpd[1680];

    auto g_y_0_z_0_x_yy_y_xy = buffer_1010_pdpd[1681];

    auto g_y_0_z_0_x_yy_y_xz = buffer_1010_pdpd[1682];

    auto g_y_0_z_0_x_yy_y_yy = buffer_1010_pdpd[1683];

    auto g_y_0_z_0_x_yy_y_yz = buffer_1010_pdpd[1684];

    auto g_y_0_z_0_x_yy_y_zz = buffer_1010_pdpd[1685];

    auto g_y_0_z_0_x_yy_z_xx = buffer_1010_pdpd[1686];

    auto g_y_0_z_0_x_yy_z_xy = buffer_1010_pdpd[1687];

    auto g_y_0_z_0_x_yy_z_xz = buffer_1010_pdpd[1688];

    auto g_y_0_z_0_x_yy_z_yy = buffer_1010_pdpd[1689];

    auto g_y_0_z_0_x_yy_z_yz = buffer_1010_pdpd[1690];

    auto g_y_0_z_0_x_yy_z_zz = buffer_1010_pdpd[1691];

    auto g_y_0_z_0_x_yz_x_xx = buffer_1010_pdpd[1692];

    auto g_y_0_z_0_x_yz_x_xy = buffer_1010_pdpd[1693];

    auto g_y_0_z_0_x_yz_x_xz = buffer_1010_pdpd[1694];

    auto g_y_0_z_0_x_yz_x_yy = buffer_1010_pdpd[1695];

    auto g_y_0_z_0_x_yz_x_yz = buffer_1010_pdpd[1696];

    auto g_y_0_z_0_x_yz_x_zz = buffer_1010_pdpd[1697];

    auto g_y_0_z_0_x_yz_y_xx = buffer_1010_pdpd[1698];

    auto g_y_0_z_0_x_yz_y_xy = buffer_1010_pdpd[1699];

    auto g_y_0_z_0_x_yz_y_xz = buffer_1010_pdpd[1700];

    auto g_y_0_z_0_x_yz_y_yy = buffer_1010_pdpd[1701];

    auto g_y_0_z_0_x_yz_y_yz = buffer_1010_pdpd[1702];

    auto g_y_0_z_0_x_yz_y_zz = buffer_1010_pdpd[1703];

    auto g_y_0_z_0_x_yz_z_xx = buffer_1010_pdpd[1704];

    auto g_y_0_z_0_x_yz_z_xy = buffer_1010_pdpd[1705];

    auto g_y_0_z_0_x_yz_z_xz = buffer_1010_pdpd[1706];

    auto g_y_0_z_0_x_yz_z_yy = buffer_1010_pdpd[1707];

    auto g_y_0_z_0_x_yz_z_yz = buffer_1010_pdpd[1708];

    auto g_y_0_z_0_x_yz_z_zz = buffer_1010_pdpd[1709];

    auto g_y_0_z_0_x_zz_x_xx = buffer_1010_pdpd[1710];

    auto g_y_0_z_0_x_zz_x_xy = buffer_1010_pdpd[1711];

    auto g_y_0_z_0_x_zz_x_xz = buffer_1010_pdpd[1712];

    auto g_y_0_z_0_x_zz_x_yy = buffer_1010_pdpd[1713];

    auto g_y_0_z_0_x_zz_x_yz = buffer_1010_pdpd[1714];

    auto g_y_0_z_0_x_zz_x_zz = buffer_1010_pdpd[1715];

    auto g_y_0_z_0_x_zz_y_xx = buffer_1010_pdpd[1716];

    auto g_y_0_z_0_x_zz_y_xy = buffer_1010_pdpd[1717];

    auto g_y_0_z_0_x_zz_y_xz = buffer_1010_pdpd[1718];

    auto g_y_0_z_0_x_zz_y_yy = buffer_1010_pdpd[1719];

    auto g_y_0_z_0_x_zz_y_yz = buffer_1010_pdpd[1720];

    auto g_y_0_z_0_x_zz_y_zz = buffer_1010_pdpd[1721];

    auto g_y_0_z_0_x_zz_z_xx = buffer_1010_pdpd[1722];

    auto g_y_0_z_0_x_zz_z_xy = buffer_1010_pdpd[1723];

    auto g_y_0_z_0_x_zz_z_xz = buffer_1010_pdpd[1724];

    auto g_y_0_z_0_x_zz_z_yy = buffer_1010_pdpd[1725];

    auto g_y_0_z_0_x_zz_z_yz = buffer_1010_pdpd[1726];

    auto g_y_0_z_0_x_zz_z_zz = buffer_1010_pdpd[1727];

    auto g_y_0_z_0_y_xx_x_xx = buffer_1010_pdpd[1728];

    auto g_y_0_z_0_y_xx_x_xy = buffer_1010_pdpd[1729];

    auto g_y_0_z_0_y_xx_x_xz = buffer_1010_pdpd[1730];

    auto g_y_0_z_0_y_xx_x_yy = buffer_1010_pdpd[1731];

    auto g_y_0_z_0_y_xx_x_yz = buffer_1010_pdpd[1732];

    auto g_y_0_z_0_y_xx_x_zz = buffer_1010_pdpd[1733];

    auto g_y_0_z_0_y_xx_y_xx = buffer_1010_pdpd[1734];

    auto g_y_0_z_0_y_xx_y_xy = buffer_1010_pdpd[1735];

    auto g_y_0_z_0_y_xx_y_xz = buffer_1010_pdpd[1736];

    auto g_y_0_z_0_y_xx_y_yy = buffer_1010_pdpd[1737];

    auto g_y_0_z_0_y_xx_y_yz = buffer_1010_pdpd[1738];

    auto g_y_0_z_0_y_xx_y_zz = buffer_1010_pdpd[1739];

    auto g_y_0_z_0_y_xx_z_xx = buffer_1010_pdpd[1740];

    auto g_y_0_z_0_y_xx_z_xy = buffer_1010_pdpd[1741];

    auto g_y_0_z_0_y_xx_z_xz = buffer_1010_pdpd[1742];

    auto g_y_0_z_0_y_xx_z_yy = buffer_1010_pdpd[1743];

    auto g_y_0_z_0_y_xx_z_yz = buffer_1010_pdpd[1744];

    auto g_y_0_z_0_y_xx_z_zz = buffer_1010_pdpd[1745];

    auto g_y_0_z_0_y_xy_x_xx = buffer_1010_pdpd[1746];

    auto g_y_0_z_0_y_xy_x_xy = buffer_1010_pdpd[1747];

    auto g_y_0_z_0_y_xy_x_xz = buffer_1010_pdpd[1748];

    auto g_y_0_z_0_y_xy_x_yy = buffer_1010_pdpd[1749];

    auto g_y_0_z_0_y_xy_x_yz = buffer_1010_pdpd[1750];

    auto g_y_0_z_0_y_xy_x_zz = buffer_1010_pdpd[1751];

    auto g_y_0_z_0_y_xy_y_xx = buffer_1010_pdpd[1752];

    auto g_y_0_z_0_y_xy_y_xy = buffer_1010_pdpd[1753];

    auto g_y_0_z_0_y_xy_y_xz = buffer_1010_pdpd[1754];

    auto g_y_0_z_0_y_xy_y_yy = buffer_1010_pdpd[1755];

    auto g_y_0_z_0_y_xy_y_yz = buffer_1010_pdpd[1756];

    auto g_y_0_z_0_y_xy_y_zz = buffer_1010_pdpd[1757];

    auto g_y_0_z_0_y_xy_z_xx = buffer_1010_pdpd[1758];

    auto g_y_0_z_0_y_xy_z_xy = buffer_1010_pdpd[1759];

    auto g_y_0_z_0_y_xy_z_xz = buffer_1010_pdpd[1760];

    auto g_y_0_z_0_y_xy_z_yy = buffer_1010_pdpd[1761];

    auto g_y_0_z_0_y_xy_z_yz = buffer_1010_pdpd[1762];

    auto g_y_0_z_0_y_xy_z_zz = buffer_1010_pdpd[1763];

    auto g_y_0_z_0_y_xz_x_xx = buffer_1010_pdpd[1764];

    auto g_y_0_z_0_y_xz_x_xy = buffer_1010_pdpd[1765];

    auto g_y_0_z_0_y_xz_x_xz = buffer_1010_pdpd[1766];

    auto g_y_0_z_0_y_xz_x_yy = buffer_1010_pdpd[1767];

    auto g_y_0_z_0_y_xz_x_yz = buffer_1010_pdpd[1768];

    auto g_y_0_z_0_y_xz_x_zz = buffer_1010_pdpd[1769];

    auto g_y_0_z_0_y_xz_y_xx = buffer_1010_pdpd[1770];

    auto g_y_0_z_0_y_xz_y_xy = buffer_1010_pdpd[1771];

    auto g_y_0_z_0_y_xz_y_xz = buffer_1010_pdpd[1772];

    auto g_y_0_z_0_y_xz_y_yy = buffer_1010_pdpd[1773];

    auto g_y_0_z_0_y_xz_y_yz = buffer_1010_pdpd[1774];

    auto g_y_0_z_0_y_xz_y_zz = buffer_1010_pdpd[1775];

    auto g_y_0_z_0_y_xz_z_xx = buffer_1010_pdpd[1776];

    auto g_y_0_z_0_y_xz_z_xy = buffer_1010_pdpd[1777];

    auto g_y_0_z_0_y_xz_z_xz = buffer_1010_pdpd[1778];

    auto g_y_0_z_0_y_xz_z_yy = buffer_1010_pdpd[1779];

    auto g_y_0_z_0_y_xz_z_yz = buffer_1010_pdpd[1780];

    auto g_y_0_z_0_y_xz_z_zz = buffer_1010_pdpd[1781];

    auto g_y_0_z_0_y_yy_x_xx = buffer_1010_pdpd[1782];

    auto g_y_0_z_0_y_yy_x_xy = buffer_1010_pdpd[1783];

    auto g_y_0_z_0_y_yy_x_xz = buffer_1010_pdpd[1784];

    auto g_y_0_z_0_y_yy_x_yy = buffer_1010_pdpd[1785];

    auto g_y_0_z_0_y_yy_x_yz = buffer_1010_pdpd[1786];

    auto g_y_0_z_0_y_yy_x_zz = buffer_1010_pdpd[1787];

    auto g_y_0_z_0_y_yy_y_xx = buffer_1010_pdpd[1788];

    auto g_y_0_z_0_y_yy_y_xy = buffer_1010_pdpd[1789];

    auto g_y_0_z_0_y_yy_y_xz = buffer_1010_pdpd[1790];

    auto g_y_0_z_0_y_yy_y_yy = buffer_1010_pdpd[1791];

    auto g_y_0_z_0_y_yy_y_yz = buffer_1010_pdpd[1792];

    auto g_y_0_z_0_y_yy_y_zz = buffer_1010_pdpd[1793];

    auto g_y_0_z_0_y_yy_z_xx = buffer_1010_pdpd[1794];

    auto g_y_0_z_0_y_yy_z_xy = buffer_1010_pdpd[1795];

    auto g_y_0_z_0_y_yy_z_xz = buffer_1010_pdpd[1796];

    auto g_y_0_z_0_y_yy_z_yy = buffer_1010_pdpd[1797];

    auto g_y_0_z_0_y_yy_z_yz = buffer_1010_pdpd[1798];

    auto g_y_0_z_0_y_yy_z_zz = buffer_1010_pdpd[1799];

    auto g_y_0_z_0_y_yz_x_xx = buffer_1010_pdpd[1800];

    auto g_y_0_z_0_y_yz_x_xy = buffer_1010_pdpd[1801];

    auto g_y_0_z_0_y_yz_x_xz = buffer_1010_pdpd[1802];

    auto g_y_0_z_0_y_yz_x_yy = buffer_1010_pdpd[1803];

    auto g_y_0_z_0_y_yz_x_yz = buffer_1010_pdpd[1804];

    auto g_y_0_z_0_y_yz_x_zz = buffer_1010_pdpd[1805];

    auto g_y_0_z_0_y_yz_y_xx = buffer_1010_pdpd[1806];

    auto g_y_0_z_0_y_yz_y_xy = buffer_1010_pdpd[1807];

    auto g_y_0_z_0_y_yz_y_xz = buffer_1010_pdpd[1808];

    auto g_y_0_z_0_y_yz_y_yy = buffer_1010_pdpd[1809];

    auto g_y_0_z_0_y_yz_y_yz = buffer_1010_pdpd[1810];

    auto g_y_0_z_0_y_yz_y_zz = buffer_1010_pdpd[1811];

    auto g_y_0_z_0_y_yz_z_xx = buffer_1010_pdpd[1812];

    auto g_y_0_z_0_y_yz_z_xy = buffer_1010_pdpd[1813];

    auto g_y_0_z_0_y_yz_z_xz = buffer_1010_pdpd[1814];

    auto g_y_0_z_0_y_yz_z_yy = buffer_1010_pdpd[1815];

    auto g_y_0_z_0_y_yz_z_yz = buffer_1010_pdpd[1816];

    auto g_y_0_z_0_y_yz_z_zz = buffer_1010_pdpd[1817];

    auto g_y_0_z_0_y_zz_x_xx = buffer_1010_pdpd[1818];

    auto g_y_0_z_0_y_zz_x_xy = buffer_1010_pdpd[1819];

    auto g_y_0_z_0_y_zz_x_xz = buffer_1010_pdpd[1820];

    auto g_y_0_z_0_y_zz_x_yy = buffer_1010_pdpd[1821];

    auto g_y_0_z_0_y_zz_x_yz = buffer_1010_pdpd[1822];

    auto g_y_0_z_0_y_zz_x_zz = buffer_1010_pdpd[1823];

    auto g_y_0_z_0_y_zz_y_xx = buffer_1010_pdpd[1824];

    auto g_y_0_z_0_y_zz_y_xy = buffer_1010_pdpd[1825];

    auto g_y_0_z_0_y_zz_y_xz = buffer_1010_pdpd[1826];

    auto g_y_0_z_0_y_zz_y_yy = buffer_1010_pdpd[1827];

    auto g_y_0_z_0_y_zz_y_yz = buffer_1010_pdpd[1828];

    auto g_y_0_z_0_y_zz_y_zz = buffer_1010_pdpd[1829];

    auto g_y_0_z_0_y_zz_z_xx = buffer_1010_pdpd[1830];

    auto g_y_0_z_0_y_zz_z_xy = buffer_1010_pdpd[1831];

    auto g_y_0_z_0_y_zz_z_xz = buffer_1010_pdpd[1832];

    auto g_y_0_z_0_y_zz_z_yy = buffer_1010_pdpd[1833];

    auto g_y_0_z_0_y_zz_z_yz = buffer_1010_pdpd[1834];

    auto g_y_0_z_0_y_zz_z_zz = buffer_1010_pdpd[1835];

    auto g_y_0_z_0_z_xx_x_xx = buffer_1010_pdpd[1836];

    auto g_y_0_z_0_z_xx_x_xy = buffer_1010_pdpd[1837];

    auto g_y_0_z_0_z_xx_x_xz = buffer_1010_pdpd[1838];

    auto g_y_0_z_0_z_xx_x_yy = buffer_1010_pdpd[1839];

    auto g_y_0_z_0_z_xx_x_yz = buffer_1010_pdpd[1840];

    auto g_y_0_z_0_z_xx_x_zz = buffer_1010_pdpd[1841];

    auto g_y_0_z_0_z_xx_y_xx = buffer_1010_pdpd[1842];

    auto g_y_0_z_0_z_xx_y_xy = buffer_1010_pdpd[1843];

    auto g_y_0_z_0_z_xx_y_xz = buffer_1010_pdpd[1844];

    auto g_y_0_z_0_z_xx_y_yy = buffer_1010_pdpd[1845];

    auto g_y_0_z_0_z_xx_y_yz = buffer_1010_pdpd[1846];

    auto g_y_0_z_0_z_xx_y_zz = buffer_1010_pdpd[1847];

    auto g_y_0_z_0_z_xx_z_xx = buffer_1010_pdpd[1848];

    auto g_y_0_z_0_z_xx_z_xy = buffer_1010_pdpd[1849];

    auto g_y_0_z_0_z_xx_z_xz = buffer_1010_pdpd[1850];

    auto g_y_0_z_0_z_xx_z_yy = buffer_1010_pdpd[1851];

    auto g_y_0_z_0_z_xx_z_yz = buffer_1010_pdpd[1852];

    auto g_y_0_z_0_z_xx_z_zz = buffer_1010_pdpd[1853];

    auto g_y_0_z_0_z_xy_x_xx = buffer_1010_pdpd[1854];

    auto g_y_0_z_0_z_xy_x_xy = buffer_1010_pdpd[1855];

    auto g_y_0_z_0_z_xy_x_xz = buffer_1010_pdpd[1856];

    auto g_y_0_z_0_z_xy_x_yy = buffer_1010_pdpd[1857];

    auto g_y_0_z_0_z_xy_x_yz = buffer_1010_pdpd[1858];

    auto g_y_0_z_0_z_xy_x_zz = buffer_1010_pdpd[1859];

    auto g_y_0_z_0_z_xy_y_xx = buffer_1010_pdpd[1860];

    auto g_y_0_z_0_z_xy_y_xy = buffer_1010_pdpd[1861];

    auto g_y_0_z_0_z_xy_y_xz = buffer_1010_pdpd[1862];

    auto g_y_0_z_0_z_xy_y_yy = buffer_1010_pdpd[1863];

    auto g_y_0_z_0_z_xy_y_yz = buffer_1010_pdpd[1864];

    auto g_y_0_z_0_z_xy_y_zz = buffer_1010_pdpd[1865];

    auto g_y_0_z_0_z_xy_z_xx = buffer_1010_pdpd[1866];

    auto g_y_0_z_0_z_xy_z_xy = buffer_1010_pdpd[1867];

    auto g_y_0_z_0_z_xy_z_xz = buffer_1010_pdpd[1868];

    auto g_y_0_z_0_z_xy_z_yy = buffer_1010_pdpd[1869];

    auto g_y_0_z_0_z_xy_z_yz = buffer_1010_pdpd[1870];

    auto g_y_0_z_0_z_xy_z_zz = buffer_1010_pdpd[1871];

    auto g_y_0_z_0_z_xz_x_xx = buffer_1010_pdpd[1872];

    auto g_y_0_z_0_z_xz_x_xy = buffer_1010_pdpd[1873];

    auto g_y_0_z_0_z_xz_x_xz = buffer_1010_pdpd[1874];

    auto g_y_0_z_0_z_xz_x_yy = buffer_1010_pdpd[1875];

    auto g_y_0_z_0_z_xz_x_yz = buffer_1010_pdpd[1876];

    auto g_y_0_z_0_z_xz_x_zz = buffer_1010_pdpd[1877];

    auto g_y_0_z_0_z_xz_y_xx = buffer_1010_pdpd[1878];

    auto g_y_0_z_0_z_xz_y_xy = buffer_1010_pdpd[1879];

    auto g_y_0_z_0_z_xz_y_xz = buffer_1010_pdpd[1880];

    auto g_y_0_z_0_z_xz_y_yy = buffer_1010_pdpd[1881];

    auto g_y_0_z_0_z_xz_y_yz = buffer_1010_pdpd[1882];

    auto g_y_0_z_0_z_xz_y_zz = buffer_1010_pdpd[1883];

    auto g_y_0_z_0_z_xz_z_xx = buffer_1010_pdpd[1884];

    auto g_y_0_z_0_z_xz_z_xy = buffer_1010_pdpd[1885];

    auto g_y_0_z_0_z_xz_z_xz = buffer_1010_pdpd[1886];

    auto g_y_0_z_0_z_xz_z_yy = buffer_1010_pdpd[1887];

    auto g_y_0_z_0_z_xz_z_yz = buffer_1010_pdpd[1888];

    auto g_y_0_z_0_z_xz_z_zz = buffer_1010_pdpd[1889];

    auto g_y_0_z_0_z_yy_x_xx = buffer_1010_pdpd[1890];

    auto g_y_0_z_0_z_yy_x_xy = buffer_1010_pdpd[1891];

    auto g_y_0_z_0_z_yy_x_xz = buffer_1010_pdpd[1892];

    auto g_y_0_z_0_z_yy_x_yy = buffer_1010_pdpd[1893];

    auto g_y_0_z_0_z_yy_x_yz = buffer_1010_pdpd[1894];

    auto g_y_0_z_0_z_yy_x_zz = buffer_1010_pdpd[1895];

    auto g_y_0_z_0_z_yy_y_xx = buffer_1010_pdpd[1896];

    auto g_y_0_z_0_z_yy_y_xy = buffer_1010_pdpd[1897];

    auto g_y_0_z_0_z_yy_y_xz = buffer_1010_pdpd[1898];

    auto g_y_0_z_0_z_yy_y_yy = buffer_1010_pdpd[1899];

    auto g_y_0_z_0_z_yy_y_yz = buffer_1010_pdpd[1900];

    auto g_y_0_z_0_z_yy_y_zz = buffer_1010_pdpd[1901];

    auto g_y_0_z_0_z_yy_z_xx = buffer_1010_pdpd[1902];

    auto g_y_0_z_0_z_yy_z_xy = buffer_1010_pdpd[1903];

    auto g_y_0_z_0_z_yy_z_xz = buffer_1010_pdpd[1904];

    auto g_y_0_z_0_z_yy_z_yy = buffer_1010_pdpd[1905];

    auto g_y_0_z_0_z_yy_z_yz = buffer_1010_pdpd[1906];

    auto g_y_0_z_0_z_yy_z_zz = buffer_1010_pdpd[1907];

    auto g_y_0_z_0_z_yz_x_xx = buffer_1010_pdpd[1908];

    auto g_y_0_z_0_z_yz_x_xy = buffer_1010_pdpd[1909];

    auto g_y_0_z_0_z_yz_x_xz = buffer_1010_pdpd[1910];

    auto g_y_0_z_0_z_yz_x_yy = buffer_1010_pdpd[1911];

    auto g_y_0_z_0_z_yz_x_yz = buffer_1010_pdpd[1912];

    auto g_y_0_z_0_z_yz_x_zz = buffer_1010_pdpd[1913];

    auto g_y_0_z_0_z_yz_y_xx = buffer_1010_pdpd[1914];

    auto g_y_0_z_0_z_yz_y_xy = buffer_1010_pdpd[1915];

    auto g_y_0_z_0_z_yz_y_xz = buffer_1010_pdpd[1916];

    auto g_y_0_z_0_z_yz_y_yy = buffer_1010_pdpd[1917];

    auto g_y_0_z_0_z_yz_y_yz = buffer_1010_pdpd[1918];

    auto g_y_0_z_0_z_yz_y_zz = buffer_1010_pdpd[1919];

    auto g_y_0_z_0_z_yz_z_xx = buffer_1010_pdpd[1920];

    auto g_y_0_z_0_z_yz_z_xy = buffer_1010_pdpd[1921];

    auto g_y_0_z_0_z_yz_z_xz = buffer_1010_pdpd[1922];

    auto g_y_0_z_0_z_yz_z_yy = buffer_1010_pdpd[1923];

    auto g_y_0_z_0_z_yz_z_yz = buffer_1010_pdpd[1924];

    auto g_y_0_z_0_z_yz_z_zz = buffer_1010_pdpd[1925];

    auto g_y_0_z_0_z_zz_x_xx = buffer_1010_pdpd[1926];

    auto g_y_0_z_0_z_zz_x_xy = buffer_1010_pdpd[1927];

    auto g_y_0_z_0_z_zz_x_xz = buffer_1010_pdpd[1928];

    auto g_y_0_z_0_z_zz_x_yy = buffer_1010_pdpd[1929];

    auto g_y_0_z_0_z_zz_x_yz = buffer_1010_pdpd[1930];

    auto g_y_0_z_0_z_zz_x_zz = buffer_1010_pdpd[1931];

    auto g_y_0_z_0_z_zz_y_xx = buffer_1010_pdpd[1932];

    auto g_y_0_z_0_z_zz_y_xy = buffer_1010_pdpd[1933];

    auto g_y_0_z_0_z_zz_y_xz = buffer_1010_pdpd[1934];

    auto g_y_0_z_0_z_zz_y_yy = buffer_1010_pdpd[1935];

    auto g_y_0_z_0_z_zz_y_yz = buffer_1010_pdpd[1936];

    auto g_y_0_z_0_z_zz_y_zz = buffer_1010_pdpd[1937];

    auto g_y_0_z_0_z_zz_z_xx = buffer_1010_pdpd[1938];

    auto g_y_0_z_0_z_zz_z_xy = buffer_1010_pdpd[1939];

    auto g_y_0_z_0_z_zz_z_xz = buffer_1010_pdpd[1940];

    auto g_y_0_z_0_z_zz_z_yy = buffer_1010_pdpd[1941];

    auto g_y_0_z_0_z_zz_z_yz = buffer_1010_pdpd[1942];

    auto g_y_0_z_0_z_zz_z_zz = buffer_1010_pdpd[1943];

    auto g_z_0_x_0_x_xx_x_xx = buffer_1010_pdpd[1944];

    auto g_z_0_x_0_x_xx_x_xy = buffer_1010_pdpd[1945];

    auto g_z_0_x_0_x_xx_x_xz = buffer_1010_pdpd[1946];

    auto g_z_0_x_0_x_xx_x_yy = buffer_1010_pdpd[1947];

    auto g_z_0_x_0_x_xx_x_yz = buffer_1010_pdpd[1948];

    auto g_z_0_x_0_x_xx_x_zz = buffer_1010_pdpd[1949];

    auto g_z_0_x_0_x_xx_y_xx = buffer_1010_pdpd[1950];

    auto g_z_0_x_0_x_xx_y_xy = buffer_1010_pdpd[1951];

    auto g_z_0_x_0_x_xx_y_xz = buffer_1010_pdpd[1952];

    auto g_z_0_x_0_x_xx_y_yy = buffer_1010_pdpd[1953];

    auto g_z_0_x_0_x_xx_y_yz = buffer_1010_pdpd[1954];

    auto g_z_0_x_0_x_xx_y_zz = buffer_1010_pdpd[1955];

    auto g_z_0_x_0_x_xx_z_xx = buffer_1010_pdpd[1956];

    auto g_z_0_x_0_x_xx_z_xy = buffer_1010_pdpd[1957];

    auto g_z_0_x_0_x_xx_z_xz = buffer_1010_pdpd[1958];

    auto g_z_0_x_0_x_xx_z_yy = buffer_1010_pdpd[1959];

    auto g_z_0_x_0_x_xx_z_yz = buffer_1010_pdpd[1960];

    auto g_z_0_x_0_x_xx_z_zz = buffer_1010_pdpd[1961];

    auto g_z_0_x_0_x_xy_x_xx = buffer_1010_pdpd[1962];

    auto g_z_0_x_0_x_xy_x_xy = buffer_1010_pdpd[1963];

    auto g_z_0_x_0_x_xy_x_xz = buffer_1010_pdpd[1964];

    auto g_z_0_x_0_x_xy_x_yy = buffer_1010_pdpd[1965];

    auto g_z_0_x_0_x_xy_x_yz = buffer_1010_pdpd[1966];

    auto g_z_0_x_0_x_xy_x_zz = buffer_1010_pdpd[1967];

    auto g_z_0_x_0_x_xy_y_xx = buffer_1010_pdpd[1968];

    auto g_z_0_x_0_x_xy_y_xy = buffer_1010_pdpd[1969];

    auto g_z_0_x_0_x_xy_y_xz = buffer_1010_pdpd[1970];

    auto g_z_0_x_0_x_xy_y_yy = buffer_1010_pdpd[1971];

    auto g_z_0_x_0_x_xy_y_yz = buffer_1010_pdpd[1972];

    auto g_z_0_x_0_x_xy_y_zz = buffer_1010_pdpd[1973];

    auto g_z_0_x_0_x_xy_z_xx = buffer_1010_pdpd[1974];

    auto g_z_0_x_0_x_xy_z_xy = buffer_1010_pdpd[1975];

    auto g_z_0_x_0_x_xy_z_xz = buffer_1010_pdpd[1976];

    auto g_z_0_x_0_x_xy_z_yy = buffer_1010_pdpd[1977];

    auto g_z_0_x_0_x_xy_z_yz = buffer_1010_pdpd[1978];

    auto g_z_0_x_0_x_xy_z_zz = buffer_1010_pdpd[1979];

    auto g_z_0_x_0_x_xz_x_xx = buffer_1010_pdpd[1980];

    auto g_z_0_x_0_x_xz_x_xy = buffer_1010_pdpd[1981];

    auto g_z_0_x_0_x_xz_x_xz = buffer_1010_pdpd[1982];

    auto g_z_0_x_0_x_xz_x_yy = buffer_1010_pdpd[1983];

    auto g_z_0_x_0_x_xz_x_yz = buffer_1010_pdpd[1984];

    auto g_z_0_x_0_x_xz_x_zz = buffer_1010_pdpd[1985];

    auto g_z_0_x_0_x_xz_y_xx = buffer_1010_pdpd[1986];

    auto g_z_0_x_0_x_xz_y_xy = buffer_1010_pdpd[1987];

    auto g_z_0_x_0_x_xz_y_xz = buffer_1010_pdpd[1988];

    auto g_z_0_x_0_x_xz_y_yy = buffer_1010_pdpd[1989];

    auto g_z_0_x_0_x_xz_y_yz = buffer_1010_pdpd[1990];

    auto g_z_0_x_0_x_xz_y_zz = buffer_1010_pdpd[1991];

    auto g_z_0_x_0_x_xz_z_xx = buffer_1010_pdpd[1992];

    auto g_z_0_x_0_x_xz_z_xy = buffer_1010_pdpd[1993];

    auto g_z_0_x_0_x_xz_z_xz = buffer_1010_pdpd[1994];

    auto g_z_0_x_0_x_xz_z_yy = buffer_1010_pdpd[1995];

    auto g_z_0_x_0_x_xz_z_yz = buffer_1010_pdpd[1996];

    auto g_z_0_x_0_x_xz_z_zz = buffer_1010_pdpd[1997];

    auto g_z_0_x_0_x_yy_x_xx = buffer_1010_pdpd[1998];

    auto g_z_0_x_0_x_yy_x_xy = buffer_1010_pdpd[1999];

    auto g_z_0_x_0_x_yy_x_xz = buffer_1010_pdpd[2000];

    auto g_z_0_x_0_x_yy_x_yy = buffer_1010_pdpd[2001];

    auto g_z_0_x_0_x_yy_x_yz = buffer_1010_pdpd[2002];

    auto g_z_0_x_0_x_yy_x_zz = buffer_1010_pdpd[2003];

    auto g_z_0_x_0_x_yy_y_xx = buffer_1010_pdpd[2004];

    auto g_z_0_x_0_x_yy_y_xy = buffer_1010_pdpd[2005];

    auto g_z_0_x_0_x_yy_y_xz = buffer_1010_pdpd[2006];

    auto g_z_0_x_0_x_yy_y_yy = buffer_1010_pdpd[2007];

    auto g_z_0_x_0_x_yy_y_yz = buffer_1010_pdpd[2008];

    auto g_z_0_x_0_x_yy_y_zz = buffer_1010_pdpd[2009];

    auto g_z_0_x_0_x_yy_z_xx = buffer_1010_pdpd[2010];

    auto g_z_0_x_0_x_yy_z_xy = buffer_1010_pdpd[2011];

    auto g_z_0_x_0_x_yy_z_xz = buffer_1010_pdpd[2012];

    auto g_z_0_x_0_x_yy_z_yy = buffer_1010_pdpd[2013];

    auto g_z_0_x_0_x_yy_z_yz = buffer_1010_pdpd[2014];

    auto g_z_0_x_0_x_yy_z_zz = buffer_1010_pdpd[2015];

    auto g_z_0_x_0_x_yz_x_xx = buffer_1010_pdpd[2016];

    auto g_z_0_x_0_x_yz_x_xy = buffer_1010_pdpd[2017];

    auto g_z_0_x_0_x_yz_x_xz = buffer_1010_pdpd[2018];

    auto g_z_0_x_0_x_yz_x_yy = buffer_1010_pdpd[2019];

    auto g_z_0_x_0_x_yz_x_yz = buffer_1010_pdpd[2020];

    auto g_z_0_x_0_x_yz_x_zz = buffer_1010_pdpd[2021];

    auto g_z_0_x_0_x_yz_y_xx = buffer_1010_pdpd[2022];

    auto g_z_0_x_0_x_yz_y_xy = buffer_1010_pdpd[2023];

    auto g_z_0_x_0_x_yz_y_xz = buffer_1010_pdpd[2024];

    auto g_z_0_x_0_x_yz_y_yy = buffer_1010_pdpd[2025];

    auto g_z_0_x_0_x_yz_y_yz = buffer_1010_pdpd[2026];

    auto g_z_0_x_0_x_yz_y_zz = buffer_1010_pdpd[2027];

    auto g_z_0_x_0_x_yz_z_xx = buffer_1010_pdpd[2028];

    auto g_z_0_x_0_x_yz_z_xy = buffer_1010_pdpd[2029];

    auto g_z_0_x_0_x_yz_z_xz = buffer_1010_pdpd[2030];

    auto g_z_0_x_0_x_yz_z_yy = buffer_1010_pdpd[2031];

    auto g_z_0_x_0_x_yz_z_yz = buffer_1010_pdpd[2032];

    auto g_z_0_x_0_x_yz_z_zz = buffer_1010_pdpd[2033];

    auto g_z_0_x_0_x_zz_x_xx = buffer_1010_pdpd[2034];

    auto g_z_0_x_0_x_zz_x_xy = buffer_1010_pdpd[2035];

    auto g_z_0_x_0_x_zz_x_xz = buffer_1010_pdpd[2036];

    auto g_z_0_x_0_x_zz_x_yy = buffer_1010_pdpd[2037];

    auto g_z_0_x_0_x_zz_x_yz = buffer_1010_pdpd[2038];

    auto g_z_0_x_0_x_zz_x_zz = buffer_1010_pdpd[2039];

    auto g_z_0_x_0_x_zz_y_xx = buffer_1010_pdpd[2040];

    auto g_z_0_x_0_x_zz_y_xy = buffer_1010_pdpd[2041];

    auto g_z_0_x_0_x_zz_y_xz = buffer_1010_pdpd[2042];

    auto g_z_0_x_0_x_zz_y_yy = buffer_1010_pdpd[2043];

    auto g_z_0_x_0_x_zz_y_yz = buffer_1010_pdpd[2044];

    auto g_z_0_x_0_x_zz_y_zz = buffer_1010_pdpd[2045];

    auto g_z_0_x_0_x_zz_z_xx = buffer_1010_pdpd[2046];

    auto g_z_0_x_0_x_zz_z_xy = buffer_1010_pdpd[2047];

    auto g_z_0_x_0_x_zz_z_xz = buffer_1010_pdpd[2048];

    auto g_z_0_x_0_x_zz_z_yy = buffer_1010_pdpd[2049];

    auto g_z_0_x_0_x_zz_z_yz = buffer_1010_pdpd[2050];

    auto g_z_0_x_0_x_zz_z_zz = buffer_1010_pdpd[2051];

    auto g_z_0_x_0_y_xx_x_xx = buffer_1010_pdpd[2052];

    auto g_z_0_x_0_y_xx_x_xy = buffer_1010_pdpd[2053];

    auto g_z_0_x_0_y_xx_x_xz = buffer_1010_pdpd[2054];

    auto g_z_0_x_0_y_xx_x_yy = buffer_1010_pdpd[2055];

    auto g_z_0_x_0_y_xx_x_yz = buffer_1010_pdpd[2056];

    auto g_z_0_x_0_y_xx_x_zz = buffer_1010_pdpd[2057];

    auto g_z_0_x_0_y_xx_y_xx = buffer_1010_pdpd[2058];

    auto g_z_0_x_0_y_xx_y_xy = buffer_1010_pdpd[2059];

    auto g_z_0_x_0_y_xx_y_xz = buffer_1010_pdpd[2060];

    auto g_z_0_x_0_y_xx_y_yy = buffer_1010_pdpd[2061];

    auto g_z_0_x_0_y_xx_y_yz = buffer_1010_pdpd[2062];

    auto g_z_0_x_0_y_xx_y_zz = buffer_1010_pdpd[2063];

    auto g_z_0_x_0_y_xx_z_xx = buffer_1010_pdpd[2064];

    auto g_z_0_x_0_y_xx_z_xy = buffer_1010_pdpd[2065];

    auto g_z_0_x_0_y_xx_z_xz = buffer_1010_pdpd[2066];

    auto g_z_0_x_0_y_xx_z_yy = buffer_1010_pdpd[2067];

    auto g_z_0_x_0_y_xx_z_yz = buffer_1010_pdpd[2068];

    auto g_z_0_x_0_y_xx_z_zz = buffer_1010_pdpd[2069];

    auto g_z_0_x_0_y_xy_x_xx = buffer_1010_pdpd[2070];

    auto g_z_0_x_0_y_xy_x_xy = buffer_1010_pdpd[2071];

    auto g_z_0_x_0_y_xy_x_xz = buffer_1010_pdpd[2072];

    auto g_z_0_x_0_y_xy_x_yy = buffer_1010_pdpd[2073];

    auto g_z_0_x_0_y_xy_x_yz = buffer_1010_pdpd[2074];

    auto g_z_0_x_0_y_xy_x_zz = buffer_1010_pdpd[2075];

    auto g_z_0_x_0_y_xy_y_xx = buffer_1010_pdpd[2076];

    auto g_z_0_x_0_y_xy_y_xy = buffer_1010_pdpd[2077];

    auto g_z_0_x_0_y_xy_y_xz = buffer_1010_pdpd[2078];

    auto g_z_0_x_0_y_xy_y_yy = buffer_1010_pdpd[2079];

    auto g_z_0_x_0_y_xy_y_yz = buffer_1010_pdpd[2080];

    auto g_z_0_x_0_y_xy_y_zz = buffer_1010_pdpd[2081];

    auto g_z_0_x_0_y_xy_z_xx = buffer_1010_pdpd[2082];

    auto g_z_0_x_0_y_xy_z_xy = buffer_1010_pdpd[2083];

    auto g_z_0_x_0_y_xy_z_xz = buffer_1010_pdpd[2084];

    auto g_z_0_x_0_y_xy_z_yy = buffer_1010_pdpd[2085];

    auto g_z_0_x_0_y_xy_z_yz = buffer_1010_pdpd[2086];

    auto g_z_0_x_0_y_xy_z_zz = buffer_1010_pdpd[2087];

    auto g_z_0_x_0_y_xz_x_xx = buffer_1010_pdpd[2088];

    auto g_z_0_x_0_y_xz_x_xy = buffer_1010_pdpd[2089];

    auto g_z_0_x_0_y_xz_x_xz = buffer_1010_pdpd[2090];

    auto g_z_0_x_0_y_xz_x_yy = buffer_1010_pdpd[2091];

    auto g_z_0_x_0_y_xz_x_yz = buffer_1010_pdpd[2092];

    auto g_z_0_x_0_y_xz_x_zz = buffer_1010_pdpd[2093];

    auto g_z_0_x_0_y_xz_y_xx = buffer_1010_pdpd[2094];

    auto g_z_0_x_0_y_xz_y_xy = buffer_1010_pdpd[2095];

    auto g_z_0_x_0_y_xz_y_xz = buffer_1010_pdpd[2096];

    auto g_z_0_x_0_y_xz_y_yy = buffer_1010_pdpd[2097];

    auto g_z_0_x_0_y_xz_y_yz = buffer_1010_pdpd[2098];

    auto g_z_0_x_0_y_xz_y_zz = buffer_1010_pdpd[2099];

    auto g_z_0_x_0_y_xz_z_xx = buffer_1010_pdpd[2100];

    auto g_z_0_x_0_y_xz_z_xy = buffer_1010_pdpd[2101];

    auto g_z_0_x_0_y_xz_z_xz = buffer_1010_pdpd[2102];

    auto g_z_0_x_0_y_xz_z_yy = buffer_1010_pdpd[2103];

    auto g_z_0_x_0_y_xz_z_yz = buffer_1010_pdpd[2104];

    auto g_z_0_x_0_y_xz_z_zz = buffer_1010_pdpd[2105];

    auto g_z_0_x_0_y_yy_x_xx = buffer_1010_pdpd[2106];

    auto g_z_0_x_0_y_yy_x_xy = buffer_1010_pdpd[2107];

    auto g_z_0_x_0_y_yy_x_xz = buffer_1010_pdpd[2108];

    auto g_z_0_x_0_y_yy_x_yy = buffer_1010_pdpd[2109];

    auto g_z_0_x_0_y_yy_x_yz = buffer_1010_pdpd[2110];

    auto g_z_0_x_0_y_yy_x_zz = buffer_1010_pdpd[2111];

    auto g_z_0_x_0_y_yy_y_xx = buffer_1010_pdpd[2112];

    auto g_z_0_x_0_y_yy_y_xy = buffer_1010_pdpd[2113];

    auto g_z_0_x_0_y_yy_y_xz = buffer_1010_pdpd[2114];

    auto g_z_0_x_0_y_yy_y_yy = buffer_1010_pdpd[2115];

    auto g_z_0_x_0_y_yy_y_yz = buffer_1010_pdpd[2116];

    auto g_z_0_x_0_y_yy_y_zz = buffer_1010_pdpd[2117];

    auto g_z_0_x_0_y_yy_z_xx = buffer_1010_pdpd[2118];

    auto g_z_0_x_0_y_yy_z_xy = buffer_1010_pdpd[2119];

    auto g_z_0_x_0_y_yy_z_xz = buffer_1010_pdpd[2120];

    auto g_z_0_x_0_y_yy_z_yy = buffer_1010_pdpd[2121];

    auto g_z_0_x_0_y_yy_z_yz = buffer_1010_pdpd[2122];

    auto g_z_0_x_0_y_yy_z_zz = buffer_1010_pdpd[2123];

    auto g_z_0_x_0_y_yz_x_xx = buffer_1010_pdpd[2124];

    auto g_z_0_x_0_y_yz_x_xy = buffer_1010_pdpd[2125];

    auto g_z_0_x_0_y_yz_x_xz = buffer_1010_pdpd[2126];

    auto g_z_0_x_0_y_yz_x_yy = buffer_1010_pdpd[2127];

    auto g_z_0_x_0_y_yz_x_yz = buffer_1010_pdpd[2128];

    auto g_z_0_x_0_y_yz_x_zz = buffer_1010_pdpd[2129];

    auto g_z_0_x_0_y_yz_y_xx = buffer_1010_pdpd[2130];

    auto g_z_0_x_0_y_yz_y_xy = buffer_1010_pdpd[2131];

    auto g_z_0_x_0_y_yz_y_xz = buffer_1010_pdpd[2132];

    auto g_z_0_x_0_y_yz_y_yy = buffer_1010_pdpd[2133];

    auto g_z_0_x_0_y_yz_y_yz = buffer_1010_pdpd[2134];

    auto g_z_0_x_0_y_yz_y_zz = buffer_1010_pdpd[2135];

    auto g_z_0_x_0_y_yz_z_xx = buffer_1010_pdpd[2136];

    auto g_z_0_x_0_y_yz_z_xy = buffer_1010_pdpd[2137];

    auto g_z_0_x_0_y_yz_z_xz = buffer_1010_pdpd[2138];

    auto g_z_0_x_0_y_yz_z_yy = buffer_1010_pdpd[2139];

    auto g_z_0_x_0_y_yz_z_yz = buffer_1010_pdpd[2140];

    auto g_z_0_x_0_y_yz_z_zz = buffer_1010_pdpd[2141];

    auto g_z_0_x_0_y_zz_x_xx = buffer_1010_pdpd[2142];

    auto g_z_0_x_0_y_zz_x_xy = buffer_1010_pdpd[2143];

    auto g_z_0_x_0_y_zz_x_xz = buffer_1010_pdpd[2144];

    auto g_z_0_x_0_y_zz_x_yy = buffer_1010_pdpd[2145];

    auto g_z_0_x_0_y_zz_x_yz = buffer_1010_pdpd[2146];

    auto g_z_0_x_0_y_zz_x_zz = buffer_1010_pdpd[2147];

    auto g_z_0_x_0_y_zz_y_xx = buffer_1010_pdpd[2148];

    auto g_z_0_x_0_y_zz_y_xy = buffer_1010_pdpd[2149];

    auto g_z_0_x_0_y_zz_y_xz = buffer_1010_pdpd[2150];

    auto g_z_0_x_0_y_zz_y_yy = buffer_1010_pdpd[2151];

    auto g_z_0_x_0_y_zz_y_yz = buffer_1010_pdpd[2152];

    auto g_z_0_x_0_y_zz_y_zz = buffer_1010_pdpd[2153];

    auto g_z_0_x_0_y_zz_z_xx = buffer_1010_pdpd[2154];

    auto g_z_0_x_0_y_zz_z_xy = buffer_1010_pdpd[2155];

    auto g_z_0_x_0_y_zz_z_xz = buffer_1010_pdpd[2156];

    auto g_z_0_x_0_y_zz_z_yy = buffer_1010_pdpd[2157];

    auto g_z_0_x_0_y_zz_z_yz = buffer_1010_pdpd[2158];

    auto g_z_0_x_0_y_zz_z_zz = buffer_1010_pdpd[2159];

    auto g_z_0_x_0_z_xx_x_xx = buffer_1010_pdpd[2160];

    auto g_z_0_x_0_z_xx_x_xy = buffer_1010_pdpd[2161];

    auto g_z_0_x_0_z_xx_x_xz = buffer_1010_pdpd[2162];

    auto g_z_0_x_0_z_xx_x_yy = buffer_1010_pdpd[2163];

    auto g_z_0_x_0_z_xx_x_yz = buffer_1010_pdpd[2164];

    auto g_z_0_x_0_z_xx_x_zz = buffer_1010_pdpd[2165];

    auto g_z_0_x_0_z_xx_y_xx = buffer_1010_pdpd[2166];

    auto g_z_0_x_0_z_xx_y_xy = buffer_1010_pdpd[2167];

    auto g_z_0_x_0_z_xx_y_xz = buffer_1010_pdpd[2168];

    auto g_z_0_x_0_z_xx_y_yy = buffer_1010_pdpd[2169];

    auto g_z_0_x_0_z_xx_y_yz = buffer_1010_pdpd[2170];

    auto g_z_0_x_0_z_xx_y_zz = buffer_1010_pdpd[2171];

    auto g_z_0_x_0_z_xx_z_xx = buffer_1010_pdpd[2172];

    auto g_z_0_x_0_z_xx_z_xy = buffer_1010_pdpd[2173];

    auto g_z_0_x_0_z_xx_z_xz = buffer_1010_pdpd[2174];

    auto g_z_0_x_0_z_xx_z_yy = buffer_1010_pdpd[2175];

    auto g_z_0_x_0_z_xx_z_yz = buffer_1010_pdpd[2176];

    auto g_z_0_x_0_z_xx_z_zz = buffer_1010_pdpd[2177];

    auto g_z_0_x_0_z_xy_x_xx = buffer_1010_pdpd[2178];

    auto g_z_0_x_0_z_xy_x_xy = buffer_1010_pdpd[2179];

    auto g_z_0_x_0_z_xy_x_xz = buffer_1010_pdpd[2180];

    auto g_z_0_x_0_z_xy_x_yy = buffer_1010_pdpd[2181];

    auto g_z_0_x_0_z_xy_x_yz = buffer_1010_pdpd[2182];

    auto g_z_0_x_0_z_xy_x_zz = buffer_1010_pdpd[2183];

    auto g_z_0_x_0_z_xy_y_xx = buffer_1010_pdpd[2184];

    auto g_z_0_x_0_z_xy_y_xy = buffer_1010_pdpd[2185];

    auto g_z_0_x_0_z_xy_y_xz = buffer_1010_pdpd[2186];

    auto g_z_0_x_0_z_xy_y_yy = buffer_1010_pdpd[2187];

    auto g_z_0_x_0_z_xy_y_yz = buffer_1010_pdpd[2188];

    auto g_z_0_x_0_z_xy_y_zz = buffer_1010_pdpd[2189];

    auto g_z_0_x_0_z_xy_z_xx = buffer_1010_pdpd[2190];

    auto g_z_0_x_0_z_xy_z_xy = buffer_1010_pdpd[2191];

    auto g_z_0_x_0_z_xy_z_xz = buffer_1010_pdpd[2192];

    auto g_z_0_x_0_z_xy_z_yy = buffer_1010_pdpd[2193];

    auto g_z_0_x_0_z_xy_z_yz = buffer_1010_pdpd[2194];

    auto g_z_0_x_0_z_xy_z_zz = buffer_1010_pdpd[2195];

    auto g_z_0_x_0_z_xz_x_xx = buffer_1010_pdpd[2196];

    auto g_z_0_x_0_z_xz_x_xy = buffer_1010_pdpd[2197];

    auto g_z_0_x_0_z_xz_x_xz = buffer_1010_pdpd[2198];

    auto g_z_0_x_0_z_xz_x_yy = buffer_1010_pdpd[2199];

    auto g_z_0_x_0_z_xz_x_yz = buffer_1010_pdpd[2200];

    auto g_z_0_x_0_z_xz_x_zz = buffer_1010_pdpd[2201];

    auto g_z_0_x_0_z_xz_y_xx = buffer_1010_pdpd[2202];

    auto g_z_0_x_0_z_xz_y_xy = buffer_1010_pdpd[2203];

    auto g_z_0_x_0_z_xz_y_xz = buffer_1010_pdpd[2204];

    auto g_z_0_x_0_z_xz_y_yy = buffer_1010_pdpd[2205];

    auto g_z_0_x_0_z_xz_y_yz = buffer_1010_pdpd[2206];

    auto g_z_0_x_0_z_xz_y_zz = buffer_1010_pdpd[2207];

    auto g_z_0_x_0_z_xz_z_xx = buffer_1010_pdpd[2208];

    auto g_z_0_x_0_z_xz_z_xy = buffer_1010_pdpd[2209];

    auto g_z_0_x_0_z_xz_z_xz = buffer_1010_pdpd[2210];

    auto g_z_0_x_0_z_xz_z_yy = buffer_1010_pdpd[2211];

    auto g_z_0_x_0_z_xz_z_yz = buffer_1010_pdpd[2212];

    auto g_z_0_x_0_z_xz_z_zz = buffer_1010_pdpd[2213];

    auto g_z_0_x_0_z_yy_x_xx = buffer_1010_pdpd[2214];

    auto g_z_0_x_0_z_yy_x_xy = buffer_1010_pdpd[2215];

    auto g_z_0_x_0_z_yy_x_xz = buffer_1010_pdpd[2216];

    auto g_z_0_x_0_z_yy_x_yy = buffer_1010_pdpd[2217];

    auto g_z_0_x_0_z_yy_x_yz = buffer_1010_pdpd[2218];

    auto g_z_0_x_0_z_yy_x_zz = buffer_1010_pdpd[2219];

    auto g_z_0_x_0_z_yy_y_xx = buffer_1010_pdpd[2220];

    auto g_z_0_x_0_z_yy_y_xy = buffer_1010_pdpd[2221];

    auto g_z_0_x_0_z_yy_y_xz = buffer_1010_pdpd[2222];

    auto g_z_0_x_0_z_yy_y_yy = buffer_1010_pdpd[2223];

    auto g_z_0_x_0_z_yy_y_yz = buffer_1010_pdpd[2224];

    auto g_z_0_x_0_z_yy_y_zz = buffer_1010_pdpd[2225];

    auto g_z_0_x_0_z_yy_z_xx = buffer_1010_pdpd[2226];

    auto g_z_0_x_0_z_yy_z_xy = buffer_1010_pdpd[2227];

    auto g_z_0_x_0_z_yy_z_xz = buffer_1010_pdpd[2228];

    auto g_z_0_x_0_z_yy_z_yy = buffer_1010_pdpd[2229];

    auto g_z_0_x_0_z_yy_z_yz = buffer_1010_pdpd[2230];

    auto g_z_0_x_0_z_yy_z_zz = buffer_1010_pdpd[2231];

    auto g_z_0_x_0_z_yz_x_xx = buffer_1010_pdpd[2232];

    auto g_z_0_x_0_z_yz_x_xy = buffer_1010_pdpd[2233];

    auto g_z_0_x_0_z_yz_x_xz = buffer_1010_pdpd[2234];

    auto g_z_0_x_0_z_yz_x_yy = buffer_1010_pdpd[2235];

    auto g_z_0_x_0_z_yz_x_yz = buffer_1010_pdpd[2236];

    auto g_z_0_x_0_z_yz_x_zz = buffer_1010_pdpd[2237];

    auto g_z_0_x_0_z_yz_y_xx = buffer_1010_pdpd[2238];

    auto g_z_0_x_0_z_yz_y_xy = buffer_1010_pdpd[2239];

    auto g_z_0_x_0_z_yz_y_xz = buffer_1010_pdpd[2240];

    auto g_z_0_x_0_z_yz_y_yy = buffer_1010_pdpd[2241];

    auto g_z_0_x_0_z_yz_y_yz = buffer_1010_pdpd[2242];

    auto g_z_0_x_0_z_yz_y_zz = buffer_1010_pdpd[2243];

    auto g_z_0_x_0_z_yz_z_xx = buffer_1010_pdpd[2244];

    auto g_z_0_x_0_z_yz_z_xy = buffer_1010_pdpd[2245];

    auto g_z_0_x_0_z_yz_z_xz = buffer_1010_pdpd[2246];

    auto g_z_0_x_0_z_yz_z_yy = buffer_1010_pdpd[2247];

    auto g_z_0_x_0_z_yz_z_yz = buffer_1010_pdpd[2248];

    auto g_z_0_x_0_z_yz_z_zz = buffer_1010_pdpd[2249];

    auto g_z_0_x_0_z_zz_x_xx = buffer_1010_pdpd[2250];

    auto g_z_0_x_0_z_zz_x_xy = buffer_1010_pdpd[2251];

    auto g_z_0_x_0_z_zz_x_xz = buffer_1010_pdpd[2252];

    auto g_z_0_x_0_z_zz_x_yy = buffer_1010_pdpd[2253];

    auto g_z_0_x_0_z_zz_x_yz = buffer_1010_pdpd[2254];

    auto g_z_0_x_0_z_zz_x_zz = buffer_1010_pdpd[2255];

    auto g_z_0_x_0_z_zz_y_xx = buffer_1010_pdpd[2256];

    auto g_z_0_x_0_z_zz_y_xy = buffer_1010_pdpd[2257];

    auto g_z_0_x_0_z_zz_y_xz = buffer_1010_pdpd[2258];

    auto g_z_0_x_0_z_zz_y_yy = buffer_1010_pdpd[2259];

    auto g_z_0_x_0_z_zz_y_yz = buffer_1010_pdpd[2260];

    auto g_z_0_x_0_z_zz_y_zz = buffer_1010_pdpd[2261];

    auto g_z_0_x_0_z_zz_z_xx = buffer_1010_pdpd[2262];

    auto g_z_0_x_0_z_zz_z_xy = buffer_1010_pdpd[2263];

    auto g_z_0_x_0_z_zz_z_xz = buffer_1010_pdpd[2264];

    auto g_z_0_x_0_z_zz_z_yy = buffer_1010_pdpd[2265];

    auto g_z_0_x_0_z_zz_z_yz = buffer_1010_pdpd[2266];

    auto g_z_0_x_0_z_zz_z_zz = buffer_1010_pdpd[2267];

    auto g_z_0_y_0_x_xx_x_xx = buffer_1010_pdpd[2268];

    auto g_z_0_y_0_x_xx_x_xy = buffer_1010_pdpd[2269];

    auto g_z_0_y_0_x_xx_x_xz = buffer_1010_pdpd[2270];

    auto g_z_0_y_0_x_xx_x_yy = buffer_1010_pdpd[2271];

    auto g_z_0_y_0_x_xx_x_yz = buffer_1010_pdpd[2272];

    auto g_z_0_y_0_x_xx_x_zz = buffer_1010_pdpd[2273];

    auto g_z_0_y_0_x_xx_y_xx = buffer_1010_pdpd[2274];

    auto g_z_0_y_0_x_xx_y_xy = buffer_1010_pdpd[2275];

    auto g_z_0_y_0_x_xx_y_xz = buffer_1010_pdpd[2276];

    auto g_z_0_y_0_x_xx_y_yy = buffer_1010_pdpd[2277];

    auto g_z_0_y_0_x_xx_y_yz = buffer_1010_pdpd[2278];

    auto g_z_0_y_0_x_xx_y_zz = buffer_1010_pdpd[2279];

    auto g_z_0_y_0_x_xx_z_xx = buffer_1010_pdpd[2280];

    auto g_z_0_y_0_x_xx_z_xy = buffer_1010_pdpd[2281];

    auto g_z_0_y_0_x_xx_z_xz = buffer_1010_pdpd[2282];

    auto g_z_0_y_0_x_xx_z_yy = buffer_1010_pdpd[2283];

    auto g_z_0_y_0_x_xx_z_yz = buffer_1010_pdpd[2284];

    auto g_z_0_y_0_x_xx_z_zz = buffer_1010_pdpd[2285];

    auto g_z_0_y_0_x_xy_x_xx = buffer_1010_pdpd[2286];

    auto g_z_0_y_0_x_xy_x_xy = buffer_1010_pdpd[2287];

    auto g_z_0_y_0_x_xy_x_xz = buffer_1010_pdpd[2288];

    auto g_z_0_y_0_x_xy_x_yy = buffer_1010_pdpd[2289];

    auto g_z_0_y_0_x_xy_x_yz = buffer_1010_pdpd[2290];

    auto g_z_0_y_0_x_xy_x_zz = buffer_1010_pdpd[2291];

    auto g_z_0_y_0_x_xy_y_xx = buffer_1010_pdpd[2292];

    auto g_z_0_y_0_x_xy_y_xy = buffer_1010_pdpd[2293];

    auto g_z_0_y_0_x_xy_y_xz = buffer_1010_pdpd[2294];

    auto g_z_0_y_0_x_xy_y_yy = buffer_1010_pdpd[2295];

    auto g_z_0_y_0_x_xy_y_yz = buffer_1010_pdpd[2296];

    auto g_z_0_y_0_x_xy_y_zz = buffer_1010_pdpd[2297];

    auto g_z_0_y_0_x_xy_z_xx = buffer_1010_pdpd[2298];

    auto g_z_0_y_0_x_xy_z_xy = buffer_1010_pdpd[2299];

    auto g_z_0_y_0_x_xy_z_xz = buffer_1010_pdpd[2300];

    auto g_z_0_y_0_x_xy_z_yy = buffer_1010_pdpd[2301];

    auto g_z_0_y_0_x_xy_z_yz = buffer_1010_pdpd[2302];

    auto g_z_0_y_0_x_xy_z_zz = buffer_1010_pdpd[2303];

    auto g_z_0_y_0_x_xz_x_xx = buffer_1010_pdpd[2304];

    auto g_z_0_y_0_x_xz_x_xy = buffer_1010_pdpd[2305];

    auto g_z_0_y_0_x_xz_x_xz = buffer_1010_pdpd[2306];

    auto g_z_0_y_0_x_xz_x_yy = buffer_1010_pdpd[2307];

    auto g_z_0_y_0_x_xz_x_yz = buffer_1010_pdpd[2308];

    auto g_z_0_y_0_x_xz_x_zz = buffer_1010_pdpd[2309];

    auto g_z_0_y_0_x_xz_y_xx = buffer_1010_pdpd[2310];

    auto g_z_0_y_0_x_xz_y_xy = buffer_1010_pdpd[2311];

    auto g_z_0_y_0_x_xz_y_xz = buffer_1010_pdpd[2312];

    auto g_z_0_y_0_x_xz_y_yy = buffer_1010_pdpd[2313];

    auto g_z_0_y_0_x_xz_y_yz = buffer_1010_pdpd[2314];

    auto g_z_0_y_0_x_xz_y_zz = buffer_1010_pdpd[2315];

    auto g_z_0_y_0_x_xz_z_xx = buffer_1010_pdpd[2316];

    auto g_z_0_y_0_x_xz_z_xy = buffer_1010_pdpd[2317];

    auto g_z_0_y_0_x_xz_z_xz = buffer_1010_pdpd[2318];

    auto g_z_0_y_0_x_xz_z_yy = buffer_1010_pdpd[2319];

    auto g_z_0_y_0_x_xz_z_yz = buffer_1010_pdpd[2320];

    auto g_z_0_y_0_x_xz_z_zz = buffer_1010_pdpd[2321];

    auto g_z_0_y_0_x_yy_x_xx = buffer_1010_pdpd[2322];

    auto g_z_0_y_0_x_yy_x_xy = buffer_1010_pdpd[2323];

    auto g_z_0_y_0_x_yy_x_xz = buffer_1010_pdpd[2324];

    auto g_z_0_y_0_x_yy_x_yy = buffer_1010_pdpd[2325];

    auto g_z_0_y_0_x_yy_x_yz = buffer_1010_pdpd[2326];

    auto g_z_0_y_0_x_yy_x_zz = buffer_1010_pdpd[2327];

    auto g_z_0_y_0_x_yy_y_xx = buffer_1010_pdpd[2328];

    auto g_z_0_y_0_x_yy_y_xy = buffer_1010_pdpd[2329];

    auto g_z_0_y_0_x_yy_y_xz = buffer_1010_pdpd[2330];

    auto g_z_0_y_0_x_yy_y_yy = buffer_1010_pdpd[2331];

    auto g_z_0_y_0_x_yy_y_yz = buffer_1010_pdpd[2332];

    auto g_z_0_y_0_x_yy_y_zz = buffer_1010_pdpd[2333];

    auto g_z_0_y_0_x_yy_z_xx = buffer_1010_pdpd[2334];

    auto g_z_0_y_0_x_yy_z_xy = buffer_1010_pdpd[2335];

    auto g_z_0_y_0_x_yy_z_xz = buffer_1010_pdpd[2336];

    auto g_z_0_y_0_x_yy_z_yy = buffer_1010_pdpd[2337];

    auto g_z_0_y_0_x_yy_z_yz = buffer_1010_pdpd[2338];

    auto g_z_0_y_0_x_yy_z_zz = buffer_1010_pdpd[2339];

    auto g_z_0_y_0_x_yz_x_xx = buffer_1010_pdpd[2340];

    auto g_z_0_y_0_x_yz_x_xy = buffer_1010_pdpd[2341];

    auto g_z_0_y_0_x_yz_x_xz = buffer_1010_pdpd[2342];

    auto g_z_0_y_0_x_yz_x_yy = buffer_1010_pdpd[2343];

    auto g_z_0_y_0_x_yz_x_yz = buffer_1010_pdpd[2344];

    auto g_z_0_y_0_x_yz_x_zz = buffer_1010_pdpd[2345];

    auto g_z_0_y_0_x_yz_y_xx = buffer_1010_pdpd[2346];

    auto g_z_0_y_0_x_yz_y_xy = buffer_1010_pdpd[2347];

    auto g_z_0_y_0_x_yz_y_xz = buffer_1010_pdpd[2348];

    auto g_z_0_y_0_x_yz_y_yy = buffer_1010_pdpd[2349];

    auto g_z_0_y_0_x_yz_y_yz = buffer_1010_pdpd[2350];

    auto g_z_0_y_0_x_yz_y_zz = buffer_1010_pdpd[2351];

    auto g_z_0_y_0_x_yz_z_xx = buffer_1010_pdpd[2352];

    auto g_z_0_y_0_x_yz_z_xy = buffer_1010_pdpd[2353];

    auto g_z_0_y_0_x_yz_z_xz = buffer_1010_pdpd[2354];

    auto g_z_0_y_0_x_yz_z_yy = buffer_1010_pdpd[2355];

    auto g_z_0_y_0_x_yz_z_yz = buffer_1010_pdpd[2356];

    auto g_z_0_y_0_x_yz_z_zz = buffer_1010_pdpd[2357];

    auto g_z_0_y_0_x_zz_x_xx = buffer_1010_pdpd[2358];

    auto g_z_0_y_0_x_zz_x_xy = buffer_1010_pdpd[2359];

    auto g_z_0_y_0_x_zz_x_xz = buffer_1010_pdpd[2360];

    auto g_z_0_y_0_x_zz_x_yy = buffer_1010_pdpd[2361];

    auto g_z_0_y_0_x_zz_x_yz = buffer_1010_pdpd[2362];

    auto g_z_0_y_0_x_zz_x_zz = buffer_1010_pdpd[2363];

    auto g_z_0_y_0_x_zz_y_xx = buffer_1010_pdpd[2364];

    auto g_z_0_y_0_x_zz_y_xy = buffer_1010_pdpd[2365];

    auto g_z_0_y_0_x_zz_y_xz = buffer_1010_pdpd[2366];

    auto g_z_0_y_0_x_zz_y_yy = buffer_1010_pdpd[2367];

    auto g_z_0_y_0_x_zz_y_yz = buffer_1010_pdpd[2368];

    auto g_z_0_y_0_x_zz_y_zz = buffer_1010_pdpd[2369];

    auto g_z_0_y_0_x_zz_z_xx = buffer_1010_pdpd[2370];

    auto g_z_0_y_0_x_zz_z_xy = buffer_1010_pdpd[2371];

    auto g_z_0_y_0_x_zz_z_xz = buffer_1010_pdpd[2372];

    auto g_z_0_y_0_x_zz_z_yy = buffer_1010_pdpd[2373];

    auto g_z_0_y_0_x_zz_z_yz = buffer_1010_pdpd[2374];

    auto g_z_0_y_0_x_zz_z_zz = buffer_1010_pdpd[2375];

    auto g_z_0_y_0_y_xx_x_xx = buffer_1010_pdpd[2376];

    auto g_z_0_y_0_y_xx_x_xy = buffer_1010_pdpd[2377];

    auto g_z_0_y_0_y_xx_x_xz = buffer_1010_pdpd[2378];

    auto g_z_0_y_0_y_xx_x_yy = buffer_1010_pdpd[2379];

    auto g_z_0_y_0_y_xx_x_yz = buffer_1010_pdpd[2380];

    auto g_z_0_y_0_y_xx_x_zz = buffer_1010_pdpd[2381];

    auto g_z_0_y_0_y_xx_y_xx = buffer_1010_pdpd[2382];

    auto g_z_0_y_0_y_xx_y_xy = buffer_1010_pdpd[2383];

    auto g_z_0_y_0_y_xx_y_xz = buffer_1010_pdpd[2384];

    auto g_z_0_y_0_y_xx_y_yy = buffer_1010_pdpd[2385];

    auto g_z_0_y_0_y_xx_y_yz = buffer_1010_pdpd[2386];

    auto g_z_0_y_0_y_xx_y_zz = buffer_1010_pdpd[2387];

    auto g_z_0_y_0_y_xx_z_xx = buffer_1010_pdpd[2388];

    auto g_z_0_y_0_y_xx_z_xy = buffer_1010_pdpd[2389];

    auto g_z_0_y_0_y_xx_z_xz = buffer_1010_pdpd[2390];

    auto g_z_0_y_0_y_xx_z_yy = buffer_1010_pdpd[2391];

    auto g_z_0_y_0_y_xx_z_yz = buffer_1010_pdpd[2392];

    auto g_z_0_y_0_y_xx_z_zz = buffer_1010_pdpd[2393];

    auto g_z_0_y_0_y_xy_x_xx = buffer_1010_pdpd[2394];

    auto g_z_0_y_0_y_xy_x_xy = buffer_1010_pdpd[2395];

    auto g_z_0_y_0_y_xy_x_xz = buffer_1010_pdpd[2396];

    auto g_z_0_y_0_y_xy_x_yy = buffer_1010_pdpd[2397];

    auto g_z_0_y_0_y_xy_x_yz = buffer_1010_pdpd[2398];

    auto g_z_0_y_0_y_xy_x_zz = buffer_1010_pdpd[2399];

    auto g_z_0_y_0_y_xy_y_xx = buffer_1010_pdpd[2400];

    auto g_z_0_y_0_y_xy_y_xy = buffer_1010_pdpd[2401];

    auto g_z_0_y_0_y_xy_y_xz = buffer_1010_pdpd[2402];

    auto g_z_0_y_0_y_xy_y_yy = buffer_1010_pdpd[2403];

    auto g_z_0_y_0_y_xy_y_yz = buffer_1010_pdpd[2404];

    auto g_z_0_y_0_y_xy_y_zz = buffer_1010_pdpd[2405];

    auto g_z_0_y_0_y_xy_z_xx = buffer_1010_pdpd[2406];

    auto g_z_0_y_0_y_xy_z_xy = buffer_1010_pdpd[2407];

    auto g_z_0_y_0_y_xy_z_xz = buffer_1010_pdpd[2408];

    auto g_z_0_y_0_y_xy_z_yy = buffer_1010_pdpd[2409];

    auto g_z_0_y_0_y_xy_z_yz = buffer_1010_pdpd[2410];

    auto g_z_0_y_0_y_xy_z_zz = buffer_1010_pdpd[2411];

    auto g_z_0_y_0_y_xz_x_xx = buffer_1010_pdpd[2412];

    auto g_z_0_y_0_y_xz_x_xy = buffer_1010_pdpd[2413];

    auto g_z_0_y_0_y_xz_x_xz = buffer_1010_pdpd[2414];

    auto g_z_0_y_0_y_xz_x_yy = buffer_1010_pdpd[2415];

    auto g_z_0_y_0_y_xz_x_yz = buffer_1010_pdpd[2416];

    auto g_z_0_y_0_y_xz_x_zz = buffer_1010_pdpd[2417];

    auto g_z_0_y_0_y_xz_y_xx = buffer_1010_pdpd[2418];

    auto g_z_0_y_0_y_xz_y_xy = buffer_1010_pdpd[2419];

    auto g_z_0_y_0_y_xz_y_xz = buffer_1010_pdpd[2420];

    auto g_z_0_y_0_y_xz_y_yy = buffer_1010_pdpd[2421];

    auto g_z_0_y_0_y_xz_y_yz = buffer_1010_pdpd[2422];

    auto g_z_0_y_0_y_xz_y_zz = buffer_1010_pdpd[2423];

    auto g_z_0_y_0_y_xz_z_xx = buffer_1010_pdpd[2424];

    auto g_z_0_y_0_y_xz_z_xy = buffer_1010_pdpd[2425];

    auto g_z_0_y_0_y_xz_z_xz = buffer_1010_pdpd[2426];

    auto g_z_0_y_0_y_xz_z_yy = buffer_1010_pdpd[2427];

    auto g_z_0_y_0_y_xz_z_yz = buffer_1010_pdpd[2428];

    auto g_z_0_y_0_y_xz_z_zz = buffer_1010_pdpd[2429];

    auto g_z_0_y_0_y_yy_x_xx = buffer_1010_pdpd[2430];

    auto g_z_0_y_0_y_yy_x_xy = buffer_1010_pdpd[2431];

    auto g_z_0_y_0_y_yy_x_xz = buffer_1010_pdpd[2432];

    auto g_z_0_y_0_y_yy_x_yy = buffer_1010_pdpd[2433];

    auto g_z_0_y_0_y_yy_x_yz = buffer_1010_pdpd[2434];

    auto g_z_0_y_0_y_yy_x_zz = buffer_1010_pdpd[2435];

    auto g_z_0_y_0_y_yy_y_xx = buffer_1010_pdpd[2436];

    auto g_z_0_y_0_y_yy_y_xy = buffer_1010_pdpd[2437];

    auto g_z_0_y_0_y_yy_y_xz = buffer_1010_pdpd[2438];

    auto g_z_0_y_0_y_yy_y_yy = buffer_1010_pdpd[2439];

    auto g_z_0_y_0_y_yy_y_yz = buffer_1010_pdpd[2440];

    auto g_z_0_y_0_y_yy_y_zz = buffer_1010_pdpd[2441];

    auto g_z_0_y_0_y_yy_z_xx = buffer_1010_pdpd[2442];

    auto g_z_0_y_0_y_yy_z_xy = buffer_1010_pdpd[2443];

    auto g_z_0_y_0_y_yy_z_xz = buffer_1010_pdpd[2444];

    auto g_z_0_y_0_y_yy_z_yy = buffer_1010_pdpd[2445];

    auto g_z_0_y_0_y_yy_z_yz = buffer_1010_pdpd[2446];

    auto g_z_0_y_0_y_yy_z_zz = buffer_1010_pdpd[2447];

    auto g_z_0_y_0_y_yz_x_xx = buffer_1010_pdpd[2448];

    auto g_z_0_y_0_y_yz_x_xy = buffer_1010_pdpd[2449];

    auto g_z_0_y_0_y_yz_x_xz = buffer_1010_pdpd[2450];

    auto g_z_0_y_0_y_yz_x_yy = buffer_1010_pdpd[2451];

    auto g_z_0_y_0_y_yz_x_yz = buffer_1010_pdpd[2452];

    auto g_z_0_y_0_y_yz_x_zz = buffer_1010_pdpd[2453];

    auto g_z_0_y_0_y_yz_y_xx = buffer_1010_pdpd[2454];

    auto g_z_0_y_0_y_yz_y_xy = buffer_1010_pdpd[2455];

    auto g_z_0_y_0_y_yz_y_xz = buffer_1010_pdpd[2456];

    auto g_z_0_y_0_y_yz_y_yy = buffer_1010_pdpd[2457];

    auto g_z_0_y_0_y_yz_y_yz = buffer_1010_pdpd[2458];

    auto g_z_0_y_0_y_yz_y_zz = buffer_1010_pdpd[2459];

    auto g_z_0_y_0_y_yz_z_xx = buffer_1010_pdpd[2460];

    auto g_z_0_y_0_y_yz_z_xy = buffer_1010_pdpd[2461];

    auto g_z_0_y_0_y_yz_z_xz = buffer_1010_pdpd[2462];

    auto g_z_0_y_0_y_yz_z_yy = buffer_1010_pdpd[2463];

    auto g_z_0_y_0_y_yz_z_yz = buffer_1010_pdpd[2464];

    auto g_z_0_y_0_y_yz_z_zz = buffer_1010_pdpd[2465];

    auto g_z_0_y_0_y_zz_x_xx = buffer_1010_pdpd[2466];

    auto g_z_0_y_0_y_zz_x_xy = buffer_1010_pdpd[2467];

    auto g_z_0_y_0_y_zz_x_xz = buffer_1010_pdpd[2468];

    auto g_z_0_y_0_y_zz_x_yy = buffer_1010_pdpd[2469];

    auto g_z_0_y_0_y_zz_x_yz = buffer_1010_pdpd[2470];

    auto g_z_0_y_0_y_zz_x_zz = buffer_1010_pdpd[2471];

    auto g_z_0_y_0_y_zz_y_xx = buffer_1010_pdpd[2472];

    auto g_z_0_y_0_y_zz_y_xy = buffer_1010_pdpd[2473];

    auto g_z_0_y_0_y_zz_y_xz = buffer_1010_pdpd[2474];

    auto g_z_0_y_0_y_zz_y_yy = buffer_1010_pdpd[2475];

    auto g_z_0_y_0_y_zz_y_yz = buffer_1010_pdpd[2476];

    auto g_z_0_y_0_y_zz_y_zz = buffer_1010_pdpd[2477];

    auto g_z_0_y_0_y_zz_z_xx = buffer_1010_pdpd[2478];

    auto g_z_0_y_0_y_zz_z_xy = buffer_1010_pdpd[2479];

    auto g_z_0_y_0_y_zz_z_xz = buffer_1010_pdpd[2480];

    auto g_z_0_y_0_y_zz_z_yy = buffer_1010_pdpd[2481];

    auto g_z_0_y_0_y_zz_z_yz = buffer_1010_pdpd[2482];

    auto g_z_0_y_0_y_zz_z_zz = buffer_1010_pdpd[2483];

    auto g_z_0_y_0_z_xx_x_xx = buffer_1010_pdpd[2484];

    auto g_z_0_y_0_z_xx_x_xy = buffer_1010_pdpd[2485];

    auto g_z_0_y_0_z_xx_x_xz = buffer_1010_pdpd[2486];

    auto g_z_0_y_0_z_xx_x_yy = buffer_1010_pdpd[2487];

    auto g_z_0_y_0_z_xx_x_yz = buffer_1010_pdpd[2488];

    auto g_z_0_y_0_z_xx_x_zz = buffer_1010_pdpd[2489];

    auto g_z_0_y_0_z_xx_y_xx = buffer_1010_pdpd[2490];

    auto g_z_0_y_0_z_xx_y_xy = buffer_1010_pdpd[2491];

    auto g_z_0_y_0_z_xx_y_xz = buffer_1010_pdpd[2492];

    auto g_z_0_y_0_z_xx_y_yy = buffer_1010_pdpd[2493];

    auto g_z_0_y_0_z_xx_y_yz = buffer_1010_pdpd[2494];

    auto g_z_0_y_0_z_xx_y_zz = buffer_1010_pdpd[2495];

    auto g_z_0_y_0_z_xx_z_xx = buffer_1010_pdpd[2496];

    auto g_z_0_y_0_z_xx_z_xy = buffer_1010_pdpd[2497];

    auto g_z_0_y_0_z_xx_z_xz = buffer_1010_pdpd[2498];

    auto g_z_0_y_0_z_xx_z_yy = buffer_1010_pdpd[2499];

    auto g_z_0_y_0_z_xx_z_yz = buffer_1010_pdpd[2500];

    auto g_z_0_y_0_z_xx_z_zz = buffer_1010_pdpd[2501];

    auto g_z_0_y_0_z_xy_x_xx = buffer_1010_pdpd[2502];

    auto g_z_0_y_0_z_xy_x_xy = buffer_1010_pdpd[2503];

    auto g_z_0_y_0_z_xy_x_xz = buffer_1010_pdpd[2504];

    auto g_z_0_y_0_z_xy_x_yy = buffer_1010_pdpd[2505];

    auto g_z_0_y_0_z_xy_x_yz = buffer_1010_pdpd[2506];

    auto g_z_0_y_0_z_xy_x_zz = buffer_1010_pdpd[2507];

    auto g_z_0_y_0_z_xy_y_xx = buffer_1010_pdpd[2508];

    auto g_z_0_y_0_z_xy_y_xy = buffer_1010_pdpd[2509];

    auto g_z_0_y_0_z_xy_y_xz = buffer_1010_pdpd[2510];

    auto g_z_0_y_0_z_xy_y_yy = buffer_1010_pdpd[2511];

    auto g_z_0_y_0_z_xy_y_yz = buffer_1010_pdpd[2512];

    auto g_z_0_y_0_z_xy_y_zz = buffer_1010_pdpd[2513];

    auto g_z_0_y_0_z_xy_z_xx = buffer_1010_pdpd[2514];

    auto g_z_0_y_0_z_xy_z_xy = buffer_1010_pdpd[2515];

    auto g_z_0_y_0_z_xy_z_xz = buffer_1010_pdpd[2516];

    auto g_z_0_y_0_z_xy_z_yy = buffer_1010_pdpd[2517];

    auto g_z_0_y_0_z_xy_z_yz = buffer_1010_pdpd[2518];

    auto g_z_0_y_0_z_xy_z_zz = buffer_1010_pdpd[2519];

    auto g_z_0_y_0_z_xz_x_xx = buffer_1010_pdpd[2520];

    auto g_z_0_y_0_z_xz_x_xy = buffer_1010_pdpd[2521];

    auto g_z_0_y_0_z_xz_x_xz = buffer_1010_pdpd[2522];

    auto g_z_0_y_0_z_xz_x_yy = buffer_1010_pdpd[2523];

    auto g_z_0_y_0_z_xz_x_yz = buffer_1010_pdpd[2524];

    auto g_z_0_y_0_z_xz_x_zz = buffer_1010_pdpd[2525];

    auto g_z_0_y_0_z_xz_y_xx = buffer_1010_pdpd[2526];

    auto g_z_0_y_0_z_xz_y_xy = buffer_1010_pdpd[2527];

    auto g_z_0_y_0_z_xz_y_xz = buffer_1010_pdpd[2528];

    auto g_z_0_y_0_z_xz_y_yy = buffer_1010_pdpd[2529];

    auto g_z_0_y_0_z_xz_y_yz = buffer_1010_pdpd[2530];

    auto g_z_0_y_0_z_xz_y_zz = buffer_1010_pdpd[2531];

    auto g_z_0_y_0_z_xz_z_xx = buffer_1010_pdpd[2532];

    auto g_z_0_y_0_z_xz_z_xy = buffer_1010_pdpd[2533];

    auto g_z_0_y_0_z_xz_z_xz = buffer_1010_pdpd[2534];

    auto g_z_0_y_0_z_xz_z_yy = buffer_1010_pdpd[2535];

    auto g_z_0_y_0_z_xz_z_yz = buffer_1010_pdpd[2536];

    auto g_z_0_y_0_z_xz_z_zz = buffer_1010_pdpd[2537];

    auto g_z_0_y_0_z_yy_x_xx = buffer_1010_pdpd[2538];

    auto g_z_0_y_0_z_yy_x_xy = buffer_1010_pdpd[2539];

    auto g_z_0_y_0_z_yy_x_xz = buffer_1010_pdpd[2540];

    auto g_z_0_y_0_z_yy_x_yy = buffer_1010_pdpd[2541];

    auto g_z_0_y_0_z_yy_x_yz = buffer_1010_pdpd[2542];

    auto g_z_0_y_0_z_yy_x_zz = buffer_1010_pdpd[2543];

    auto g_z_0_y_0_z_yy_y_xx = buffer_1010_pdpd[2544];

    auto g_z_0_y_0_z_yy_y_xy = buffer_1010_pdpd[2545];

    auto g_z_0_y_0_z_yy_y_xz = buffer_1010_pdpd[2546];

    auto g_z_0_y_0_z_yy_y_yy = buffer_1010_pdpd[2547];

    auto g_z_0_y_0_z_yy_y_yz = buffer_1010_pdpd[2548];

    auto g_z_0_y_0_z_yy_y_zz = buffer_1010_pdpd[2549];

    auto g_z_0_y_0_z_yy_z_xx = buffer_1010_pdpd[2550];

    auto g_z_0_y_0_z_yy_z_xy = buffer_1010_pdpd[2551];

    auto g_z_0_y_0_z_yy_z_xz = buffer_1010_pdpd[2552];

    auto g_z_0_y_0_z_yy_z_yy = buffer_1010_pdpd[2553];

    auto g_z_0_y_0_z_yy_z_yz = buffer_1010_pdpd[2554];

    auto g_z_0_y_0_z_yy_z_zz = buffer_1010_pdpd[2555];

    auto g_z_0_y_0_z_yz_x_xx = buffer_1010_pdpd[2556];

    auto g_z_0_y_0_z_yz_x_xy = buffer_1010_pdpd[2557];

    auto g_z_0_y_0_z_yz_x_xz = buffer_1010_pdpd[2558];

    auto g_z_0_y_0_z_yz_x_yy = buffer_1010_pdpd[2559];

    auto g_z_0_y_0_z_yz_x_yz = buffer_1010_pdpd[2560];

    auto g_z_0_y_0_z_yz_x_zz = buffer_1010_pdpd[2561];

    auto g_z_0_y_0_z_yz_y_xx = buffer_1010_pdpd[2562];

    auto g_z_0_y_0_z_yz_y_xy = buffer_1010_pdpd[2563];

    auto g_z_0_y_0_z_yz_y_xz = buffer_1010_pdpd[2564];

    auto g_z_0_y_0_z_yz_y_yy = buffer_1010_pdpd[2565];

    auto g_z_0_y_0_z_yz_y_yz = buffer_1010_pdpd[2566];

    auto g_z_0_y_0_z_yz_y_zz = buffer_1010_pdpd[2567];

    auto g_z_0_y_0_z_yz_z_xx = buffer_1010_pdpd[2568];

    auto g_z_0_y_0_z_yz_z_xy = buffer_1010_pdpd[2569];

    auto g_z_0_y_0_z_yz_z_xz = buffer_1010_pdpd[2570];

    auto g_z_0_y_0_z_yz_z_yy = buffer_1010_pdpd[2571];

    auto g_z_0_y_0_z_yz_z_yz = buffer_1010_pdpd[2572];

    auto g_z_0_y_0_z_yz_z_zz = buffer_1010_pdpd[2573];

    auto g_z_0_y_0_z_zz_x_xx = buffer_1010_pdpd[2574];

    auto g_z_0_y_0_z_zz_x_xy = buffer_1010_pdpd[2575];

    auto g_z_0_y_0_z_zz_x_xz = buffer_1010_pdpd[2576];

    auto g_z_0_y_0_z_zz_x_yy = buffer_1010_pdpd[2577];

    auto g_z_0_y_0_z_zz_x_yz = buffer_1010_pdpd[2578];

    auto g_z_0_y_0_z_zz_x_zz = buffer_1010_pdpd[2579];

    auto g_z_0_y_0_z_zz_y_xx = buffer_1010_pdpd[2580];

    auto g_z_0_y_0_z_zz_y_xy = buffer_1010_pdpd[2581];

    auto g_z_0_y_0_z_zz_y_xz = buffer_1010_pdpd[2582];

    auto g_z_0_y_0_z_zz_y_yy = buffer_1010_pdpd[2583];

    auto g_z_0_y_0_z_zz_y_yz = buffer_1010_pdpd[2584];

    auto g_z_0_y_0_z_zz_y_zz = buffer_1010_pdpd[2585];

    auto g_z_0_y_0_z_zz_z_xx = buffer_1010_pdpd[2586];

    auto g_z_0_y_0_z_zz_z_xy = buffer_1010_pdpd[2587];

    auto g_z_0_y_0_z_zz_z_xz = buffer_1010_pdpd[2588];

    auto g_z_0_y_0_z_zz_z_yy = buffer_1010_pdpd[2589];

    auto g_z_0_y_0_z_zz_z_yz = buffer_1010_pdpd[2590];

    auto g_z_0_y_0_z_zz_z_zz = buffer_1010_pdpd[2591];

    auto g_z_0_z_0_x_xx_x_xx = buffer_1010_pdpd[2592];

    auto g_z_0_z_0_x_xx_x_xy = buffer_1010_pdpd[2593];

    auto g_z_0_z_0_x_xx_x_xz = buffer_1010_pdpd[2594];

    auto g_z_0_z_0_x_xx_x_yy = buffer_1010_pdpd[2595];

    auto g_z_0_z_0_x_xx_x_yz = buffer_1010_pdpd[2596];

    auto g_z_0_z_0_x_xx_x_zz = buffer_1010_pdpd[2597];

    auto g_z_0_z_0_x_xx_y_xx = buffer_1010_pdpd[2598];

    auto g_z_0_z_0_x_xx_y_xy = buffer_1010_pdpd[2599];

    auto g_z_0_z_0_x_xx_y_xz = buffer_1010_pdpd[2600];

    auto g_z_0_z_0_x_xx_y_yy = buffer_1010_pdpd[2601];

    auto g_z_0_z_0_x_xx_y_yz = buffer_1010_pdpd[2602];

    auto g_z_0_z_0_x_xx_y_zz = buffer_1010_pdpd[2603];

    auto g_z_0_z_0_x_xx_z_xx = buffer_1010_pdpd[2604];

    auto g_z_0_z_0_x_xx_z_xy = buffer_1010_pdpd[2605];

    auto g_z_0_z_0_x_xx_z_xz = buffer_1010_pdpd[2606];

    auto g_z_0_z_0_x_xx_z_yy = buffer_1010_pdpd[2607];

    auto g_z_0_z_0_x_xx_z_yz = buffer_1010_pdpd[2608];

    auto g_z_0_z_0_x_xx_z_zz = buffer_1010_pdpd[2609];

    auto g_z_0_z_0_x_xy_x_xx = buffer_1010_pdpd[2610];

    auto g_z_0_z_0_x_xy_x_xy = buffer_1010_pdpd[2611];

    auto g_z_0_z_0_x_xy_x_xz = buffer_1010_pdpd[2612];

    auto g_z_0_z_0_x_xy_x_yy = buffer_1010_pdpd[2613];

    auto g_z_0_z_0_x_xy_x_yz = buffer_1010_pdpd[2614];

    auto g_z_0_z_0_x_xy_x_zz = buffer_1010_pdpd[2615];

    auto g_z_0_z_0_x_xy_y_xx = buffer_1010_pdpd[2616];

    auto g_z_0_z_0_x_xy_y_xy = buffer_1010_pdpd[2617];

    auto g_z_0_z_0_x_xy_y_xz = buffer_1010_pdpd[2618];

    auto g_z_0_z_0_x_xy_y_yy = buffer_1010_pdpd[2619];

    auto g_z_0_z_0_x_xy_y_yz = buffer_1010_pdpd[2620];

    auto g_z_0_z_0_x_xy_y_zz = buffer_1010_pdpd[2621];

    auto g_z_0_z_0_x_xy_z_xx = buffer_1010_pdpd[2622];

    auto g_z_0_z_0_x_xy_z_xy = buffer_1010_pdpd[2623];

    auto g_z_0_z_0_x_xy_z_xz = buffer_1010_pdpd[2624];

    auto g_z_0_z_0_x_xy_z_yy = buffer_1010_pdpd[2625];

    auto g_z_0_z_0_x_xy_z_yz = buffer_1010_pdpd[2626];

    auto g_z_0_z_0_x_xy_z_zz = buffer_1010_pdpd[2627];

    auto g_z_0_z_0_x_xz_x_xx = buffer_1010_pdpd[2628];

    auto g_z_0_z_0_x_xz_x_xy = buffer_1010_pdpd[2629];

    auto g_z_0_z_0_x_xz_x_xz = buffer_1010_pdpd[2630];

    auto g_z_0_z_0_x_xz_x_yy = buffer_1010_pdpd[2631];

    auto g_z_0_z_0_x_xz_x_yz = buffer_1010_pdpd[2632];

    auto g_z_0_z_0_x_xz_x_zz = buffer_1010_pdpd[2633];

    auto g_z_0_z_0_x_xz_y_xx = buffer_1010_pdpd[2634];

    auto g_z_0_z_0_x_xz_y_xy = buffer_1010_pdpd[2635];

    auto g_z_0_z_0_x_xz_y_xz = buffer_1010_pdpd[2636];

    auto g_z_0_z_0_x_xz_y_yy = buffer_1010_pdpd[2637];

    auto g_z_0_z_0_x_xz_y_yz = buffer_1010_pdpd[2638];

    auto g_z_0_z_0_x_xz_y_zz = buffer_1010_pdpd[2639];

    auto g_z_0_z_0_x_xz_z_xx = buffer_1010_pdpd[2640];

    auto g_z_0_z_0_x_xz_z_xy = buffer_1010_pdpd[2641];

    auto g_z_0_z_0_x_xz_z_xz = buffer_1010_pdpd[2642];

    auto g_z_0_z_0_x_xz_z_yy = buffer_1010_pdpd[2643];

    auto g_z_0_z_0_x_xz_z_yz = buffer_1010_pdpd[2644];

    auto g_z_0_z_0_x_xz_z_zz = buffer_1010_pdpd[2645];

    auto g_z_0_z_0_x_yy_x_xx = buffer_1010_pdpd[2646];

    auto g_z_0_z_0_x_yy_x_xy = buffer_1010_pdpd[2647];

    auto g_z_0_z_0_x_yy_x_xz = buffer_1010_pdpd[2648];

    auto g_z_0_z_0_x_yy_x_yy = buffer_1010_pdpd[2649];

    auto g_z_0_z_0_x_yy_x_yz = buffer_1010_pdpd[2650];

    auto g_z_0_z_0_x_yy_x_zz = buffer_1010_pdpd[2651];

    auto g_z_0_z_0_x_yy_y_xx = buffer_1010_pdpd[2652];

    auto g_z_0_z_0_x_yy_y_xy = buffer_1010_pdpd[2653];

    auto g_z_0_z_0_x_yy_y_xz = buffer_1010_pdpd[2654];

    auto g_z_0_z_0_x_yy_y_yy = buffer_1010_pdpd[2655];

    auto g_z_0_z_0_x_yy_y_yz = buffer_1010_pdpd[2656];

    auto g_z_0_z_0_x_yy_y_zz = buffer_1010_pdpd[2657];

    auto g_z_0_z_0_x_yy_z_xx = buffer_1010_pdpd[2658];

    auto g_z_0_z_0_x_yy_z_xy = buffer_1010_pdpd[2659];

    auto g_z_0_z_0_x_yy_z_xz = buffer_1010_pdpd[2660];

    auto g_z_0_z_0_x_yy_z_yy = buffer_1010_pdpd[2661];

    auto g_z_0_z_0_x_yy_z_yz = buffer_1010_pdpd[2662];

    auto g_z_0_z_0_x_yy_z_zz = buffer_1010_pdpd[2663];

    auto g_z_0_z_0_x_yz_x_xx = buffer_1010_pdpd[2664];

    auto g_z_0_z_0_x_yz_x_xy = buffer_1010_pdpd[2665];

    auto g_z_0_z_0_x_yz_x_xz = buffer_1010_pdpd[2666];

    auto g_z_0_z_0_x_yz_x_yy = buffer_1010_pdpd[2667];

    auto g_z_0_z_0_x_yz_x_yz = buffer_1010_pdpd[2668];

    auto g_z_0_z_0_x_yz_x_zz = buffer_1010_pdpd[2669];

    auto g_z_0_z_0_x_yz_y_xx = buffer_1010_pdpd[2670];

    auto g_z_0_z_0_x_yz_y_xy = buffer_1010_pdpd[2671];

    auto g_z_0_z_0_x_yz_y_xz = buffer_1010_pdpd[2672];

    auto g_z_0_z_0_x_yz_y_yy = buffer_1010_pdpd[2673];

    auto g_z_0_z_0_x_yz_y_yz = buffer_1010_pdpd[2674];

    auto g_z_0_z_0_x_yz_y_zz = buffer_1010_pdpd[2675];

    auto g_z_0_z_0_x_yz_z_xx = buffer_1010_pdpd[2676];

    auto g_z_0_z_0_x_yz_z_xy = buffer_1010_pdpd[2677];

    auto g_z_0_z_0_x_yz_z_xz = buffer_1010_pdpd[2678];

    auto g_z_0_z_0_x_yz_z_yy = buffer_1010_pdpd[2679];

    auto g_z_0_z_0_x_yz_z_yz = buffer_1010_pdpd[2680];

    auto g_z_0_z_0_x_yz_z_zz = buffer_1010_pdpd[2681];

    auto g_z_0_z_0_x_zz_x_xx = buffer_1010_pdpd[2682];

    auto g_z_0_z_0_x_zz_x_xy = buffer_1010_pdpd[2683];

    auto g_z_0_z_0_x_zz_x_xz = buffer_1010_pdpd[2684];

    auto g_z_0_z_0_x_zz_x_yy = buffer_1010_pdpd[2685];

    auto g_z_0_z_0_x_zz_x_yz = buffer_1010_pdpd[2686];

    auto g_z_0_z_0_x_zz_x_zz = buffer_1010_pdpd[2687];

    auto g_z_0_z_0_x_zz_y_xx = buffer_1010_pdpd[2688];

    auto g_z_0_z_0_x_zz_y_xy = buffer_1010_pdpd[2689];

    auto g_z_0_z_0_x_zz_y_xz = buffer_1010_pdpd[2690];

    auto g_z_0_z_0_x_zz_y_yy = buffer_1010_pdpd[2691];

    auto g_z_0_z_0_x_zz_y_yz = buffer_1010_pdpd[2692];

    auto g_z_0_z_0_x_zz_y_zz = buffer_1010_pdpd[2693];

    auto g_z_0_z_0_x_zz_z_xx = buffer_1010_pdpd[2694];

    auto g_z_0_z_0_x_zz_z_xy = buffer_1010_pdpd[2695];

    auto g_z_0_z_0_x_zz_z_xz = buffer_1010_pdpd[2696];

    auto g_z_0_z_0_x_zz_z_yy = buffer_1010_pdpd[2697];

    auto g_z_0_z_0_x_zz_z_yz = buffer_1010_pdpd[2698];

    auto g_z_0_z_0_x_zz_z_zz = buffer_1010_pdpd[2699];

    auto g_z_0_z_0_y_xx_x_xx = buffer_1010_pdpd[2700];

    auto g_z_0_z_0_y_xx_x_xy = buffer_1010_pdpd[2701];

    auto g_z_0_z_0_y_xx_x_xz = buffer_1010_pdpd[2702];

    auto g_z_0_z_0_y_xx_x_yy = buffer_1010_pdpd[2703];

    auto g_z_0_z_0_y_xx_x_yz = buffer_1010_pdpd[2704];

    auto g_z_0_z_0_y_xx_x_zz = buffer_1010_pdpd[2705];

    auto g_z_0_z_0_y_xx_y_xx = buffer_1010_pdpd[2706];

    auto g_z_0_z_0_y_xx_y_xy = buffer_1010_pdpd[2707];

    auto g_z_0_z_0_y_xx_y_xz = buffer_1010_pdpd[2708];

    auto g_z_0_z_0_y_xx_y_yy = buffer_1010_pdpd[2709];

    auto g_z_0_z_0_y_xx_y_yz = buffer_1010_pdpd[2710];

    auto g_z_0_z_0_y_xx_y_zz = buffer_1010_pdpd[2711];

    auto g_z_0_z_0_y_xx_z_xx = buffer_1010_pdpd[2712];

    auto g_z_0_z_0_y_xx_z_xy = buffer_1010_pdpd[2713];

    auto g_z_0_z_0_y_xx_z_xz = buffer_1010_pdpd[2714];

    auto g_z_0_z_0_y_xx_z_yy = buffer_1010_pdpd[2715];

    auto g_z_0_z_0_y_xx_z_yz = buffer_1010_pdpd[2716];

    auto g_z_0_z_0_y_xx_z_zz = buffer_1010_pdpd[2717];

    auto g_z_0_z_0_y_xy_x_xx = buffer_1010_pdpd[2718];

    auto g_z_0_z_0_y_xy_x_xy = buffer_1010_pdpd[2719];

    auto g_z_0_z_0_y_xy_x_xz = buffer_1010_pdpd[2720];

    auto g_z_0_z_0_y_xy_x_yy = buffer_1010_pdpd[2721];

    auto g_z_0_z_0_y_xy_x_yz = buffer_1010_pdpd[2722];

    auto g_z_0_z_0_y_xy_x_zz = buffer_1010_pdpd[2723];

    auto g_z_0_z_0_y_xy_y_xx = buffer_1010_pdpd[2724];

    auto g_z_0_z_0_y_xy_y_xy = buffer_1010_pdpd[2725];

    auto g_z_0_z_0_y_xy_y_xz = buffer_1010_pdpd[2726];

    auto g_z_0_z_0_y_xy_y_yy = buffer_1010_pdpd[2727];

    auto g_z_0_z_0_y_xy_y_yz = buffer_1010_pdpd[2728];

    auto g_z_0_z_0_y_xy_y_zz = buffer_1010_pdpd[2729];

    auto g_z_0_z_0_y_xy_z_xx = buffer_1010_pdpd[2730];

    auto g_z_0_z_0_y_xy_z_xy = buffer_1010_pdpd[2731];

    auto g_z_0_z_0_y_xy_z_xz = buffer_1010_pdpd[2732];

    auto g_z_0_z_0_y_xy_z_yy = buffer_1010_pdpd[2733];

    auto g_z_0_z_0_y_xy_z_yz = buffer_1010_pdpd[2734];

    auto g_z_0_z_0_y_xy_z_zz = buffer_1010_pdpd[2735];

    auto g_z_0_z_0_y_xz_x_xx = buffer_1010_pdpd[2736];

    auto g_z_0_z_0_y_xz_x_xy = buffer_1010_pdpd[2737];

    auto g_z_0_z_0_y_xz_x_xz = buffer_1010_pdpd[2738];

    auto g_z_0_z_0_y_xz_x_yy = buffer_1010_pdpd[2739];

    auto g_z_0_z_0_y_xz_x_yz = buffer_1010_pdpd[2740];

    auto g_z_0_z_0_y_xz_x_zz = buffer_1010_pdpd[2741];

    auto g_z_0_z_0_y_xz_y_xx = buffer_1010_pdpd[2742];

    auto g_z_0_z_0_y_xz_y_xy = buffer_1010_pdpd[2743];

    auto g_z_0_z_0_y_xz_y_xz = buffer_1010_pdpd[2744];

    auto g_z_0_z_0_y_xz_y_yy = buffer_1010_pdpd[2745];

    auto g_z_0_z_0_y_xz_y_yz = buffer_1010_pdpd[2746];

    auto g_z_0_z_0_y_xz_y_zz = buffer_1010_pdpd[2747];

    auto g_z_0_z_0_y_xz_z_xx = buffer_1010_pdpd[2748];

    auto g_z_0_z_0_y_xz_z_xy = buffer_1010_pdpd[2749];

    auto g_z_0_z_0_y_xz_z_xz = buffer_1010_pdpd[2750];

    auto g_z_0_z_0_y_xz_z_yy = buffer_1010_pdpd[2751];

    auto g_z_0_z_0_y_xz_z_yz = buffer_1010_pdpd[2752];

    auto g_z_0_z_0_y_xz_z_zz = buffer_1010_pdpd[2753];

    auto g_z_0_z_0_y_yy_x_xx = buffer_1010_pdpd[2754];

    auto g_z_0_z_0_y_yy_x_xy = buffer_1010_pdpd[2755];

    auto g_z_0_z_0_y_yy_x_xz = buffer_1010_pdpd[2756];

    auto g_z_0_z_0_y_yy_x_yy = buffer_1010_pdpd[2757];

    auto g_z_0_z_0_y_yy_x_yz = buffer_1010_pdpd[2758];

    auto g_z_0_z_0_y_yy_x_zz = buffer_1010_pdpd[2759];

    auto g_z_0_z_0_y_yy_y_xx = buffer_1010_pdpd[2760];

    auto g_z_0_z_0_y_yy_y_xy = buffer_1010_pdpd[2761];

    auto g_z_0_z_0_y_yy_y_xz = buffer_1010_pdpd[2762];

    auto g_z_0_z_0_y_yy_y_yy = buffer_1010_pdpd[2763];

    auto g_z_0_z_0_y_yy_y_yz = buffer_1010_pdpd[2764];

    auto g_z_0_z_0_y_yy_y_zz = buffer_1010_pdpd[2765];

    auto g_z_0_z_0_y_yy_z_xx = buffer_1010_pdpd[2766];

    auto g_z_0_z_0_y_yy_z_xy = buffer_1010_pdpd[2767];

    auto g_z_0_z_0_y_yy_z_xz = buffer_1010_pdpd[2768];

    auto g_z_0_z_0_y_yy_z_yy = buffer_1010_pdpd[2769];

    auto g_z_0_z_0_y_yy_z_yz = buffer_1010_pdpd[2770];

    auto g_z_0_z_0_y_yy_z_zz = buffer_1010_pdpd[2771];

    auto g_z_0_z_0_y_yz_x_xx = buffer_1010_pdpd[2772];

    auto g_z_0_z_0_y_yz_x_xy = buffer_1010_pdpd[2773];

    auto g_z_0_z_0_y_yz_x_xz = buffer_1010_pdpd[2774];

    auto g_z_0_z_0_y_yz_x_yy = buffer_1010_pdpd[2775];

    auto g_z_0_z_0_y_yz_x_yz = buffer_1010_pdpd[2776];

    auto g_z_0_z_0_y_yz_x_zz = buffer_1010_pdpd[2777];

    auto g_z_0_z_0_y_yz_y_xx = buffer_1010_pdpd[2778];

    auto g_z_0_z_0_y_yz_y_xy = buffer_1010_pdpd[2779];

    auto g_z_0_z_0_y_yz_y_xz = buffer_1010_pdpd[2780];

    auto g_z_0_z_0_y_yz_y_yy = buffer_1010_pdpd[2781];

    auto g_z_0_z_0_y_yz_y_yz = buffer_1010_pdpd[2782];

    auto g_z_0_z_0_y_yz_y_zz = buffer_1010_pdpd[2783];

    auto g_z_0_z_0_y_yz_z_xx = buffer_1010_pdpd[2784];

    auto g_z_0_z_0_y_yz_z_xy = buffer_1010_pdpd[2785];

    auto g_z_0_z_0_y_yz_z_xz = buffer_1010_pdpd[2786];

    auto g_z_0_z_0_y_yz_z_yy = buffer_1010_pdpd[2787];

    auto g_z_0_z_0_y_yz_z_yz = buffer_1010_pdpd[2788];

    auto g_z_0_z_0_y_yz_z_zz = buffer_1010_pdpd[2789];

    auto g_z_0_z_0_y_zz_x_xx = buffer_1010_pdpd[2790];

    auto g_z_0_z_0_y_zz_x_xy = buffer_1010_pdpd[2791];

    auto g_z_0_z_0_y_zz_x_xz = buffer_1010_pdpd[2792];

    auto g_z_0_z_0_y_zz_x_yy = buffer_1010_pdpd[2793];

    auto g_z_0_z_0_y_zz_x_yz = buffer_1010_pdpd[2794];

    auto g_z_0_z_0_y_zz_x_zz = buffer_1010_pdpd[2795];

    auto g_z_0_z_0_y_zz_y_xx = buffer_1010_pdpd[2796];

    auto g_z_0_z_0_y_zz_y_xy = buffer_1010_pdpd[2797];

    auto g_z_0_z_0_y_zz_y_xz = buffer_1010_pdpd[2798];

    auto g_z_0_z_0_y_zz_y_yy = buffer_1010_pdpd[2799];

    auto g_z_0_z_0_y_zz_y_yz = buffer_1010_pdpd[2800];

    auto g_z_0_z_0_y_zz_y_zz = buffer_1010_pdpd[2801];

    auto g_z_0_z_0_y_zz_z_xx = buffer_1010_pdpd[2802];

    auto g_z_0_z_0_y_zz_z_xy = buffer_1010_pdpd[2803];

    auto g_z_0_z_0_y_zz_z_xz = buffer_1010_pdpd[2804];

    auto g_z_0_z_0_y_zz_z_yy = buffer_1010_pdpd[2805];

    auto g_z_0_z_0_y_zz_z_yz = buffer_1010_pdpd[2806];

    auto g_z_0_z_0_y_zz_z_zz = buffer_1010_pdpd[2807];

    auto g_z_0_z_0_z_xx_x_xx = buffer_1010_pdpd[2808];

    auto g_z_0_z_0_z_xx_x_xy = buffer_1010_pdpd[2809];

    auto g_z_0_z_0_z_xx_x_xz = buffer_1010_pdpd[2810];

    auto g_z_0_z_0_z_xx_x_yy = buffer_1010_pdpd[2811];

    auto g_z_0_z_0_z_xx_x_yz = buffer_1010_pdpd[2812];

    auto g_z_0_z_0_z_xx_x_zz = buffer_1010_pdpd[2813];

    auto g_z_0_z_0_z_xx_y_xx = buffer_1010_pdpd[2814];

    auto g_z_0_z_0_z_xx_y_xy = buffer_1010_pdpd[2815];

    auto g_z_0_z_0_z_xx_y_xz = buffer_1010_pdpd[2816];

    auto g_z_0_z_0_z_xx_y_yy = buffer_1010_pdpd[2817];

    auto g_z_0_z_0_z_xx_y_yz = buffer_1010_pdpd[2818];

    auto g_z_0_z_0_z_xx_y_zz = buffer_1010_pdpd[2819];

    auto g_z_0_z_0_z_xx_z_xx = buffer_1010_pdpd[2820];

    auto g_z_0_z_0_z_xx_z_xy = buffer_1010_pdpd[2821];

    auto g_z_0_z_0_z_xx_z_xz = buffer_1010_pdpd[2822];

    auto g_z_0_z_0_z_xx_z_yy = buffer_1010_pdpd[2823];

    auto g_z_0_z_0_z_xx_z_yz = buffer_1010_pdpd[2824];

    auto g_z_0_z_0_z_xx_z_zz = buffer_1010_pdpd[2825];

    auto g_z_0_z_0_z_xy_x_xx = buffer_1010_pdpd[2826];

    auto g_z_0_z_0_z_xy_x_xy = buffer_1010_pdpd[2827];

    auto g_z_0_z_0_z_xy_x_xz = buffer_1010_pdpd[2828];

    auto g_z_0_z_0_z_xy_x_yy = buffer_1010_pdpd[2829];

    auto g_z_0_z_0_z_xy_x_yz = buffer_1010_pdpd[2830];

    auto g_z_0_z_0_z_xy_x_zz = buffer_1010_pdpd[2831];

    auto g_z_0_z_0_z_xy_y_xx = buffer_1010_pdpd[2832];

    auto g_z_0_z_0_z_xy_y_xy = buffer_1010_pdpd[2833];

    auto g_z_0_z_0_z_xy_y_xz = buffer_1010_pdpd[2834];

    auto g_z_0_z_0_z_xy_y_yy = buffer_1010_pdpd[2835];

    auto g_z_0_z_0_z_xy_y_yz = buffer_1010_pdpd[2836];

    auto g_z_0_z_0_z_xy_y_zz = buffer_1010_pdpd[2837];

    auto g_z_0_z_0_z_xy_z_xx = buffer_1010_pdpd[2838];

    auto g_z_0_z_0_z_xy_z_xy = buffer_1010_pdpd[2839];

    auto g_z_0_z_0_z_xy_z_xz = buffer_1010_pdpd[2840];

    auto g_z_0_z_0_z_xy_z_yy = buffer_1010_pdpd[2841];

    auto g_z_0_z_0_z_xy_z_yz = buffer_1010_pdpd[2842];

    auto g_z_0_z_0_z_xy_z_zz = buffer_1010_pdpd[2843];

    auto g_z_0_z_0_z_xz_x_xx = buffer_1010_pdpd[2844];

    auto g_z_0_z_0_z_xz_x_xy = buffer_1010_pdpd[2845];

    auto g_z_0_z_0_z_xz_x_xz = buffer_1010_pdpd[2846];

    auto g_z_0_z_0_z_xz_x_yy = buffer_1010_pdpd[2847];

    auto g_z_0_z_0_z_xz_x_yz = buffer_1010_pdpd[2848];

    auto g_z_0_z_0_z_xz_x_zz = buffer_1010_pdpd[2849];

    auto g_z_0_z_0_z_xz_y_xx = buffer_1010_pdpd[2850];

    auto g_z_0_z_0_z_xz_y_xy = buffer_1010_pdpd[2851];

    auto g_z_0_z_0_z_xz_y_xz = buffer_1010_pdpd[2852];

    auto g_z_0_z_0_z_xz_y_yy = buffer_1010_pdpd[2853];

    auto g_z_0_z_0_z_xz_y_yz = buffer_1010_pdpd[2854];

    auto g_z_0_z_0_z_xz_y_zz = buffer_1010_pdpd[2855];

    auto g_z_0_z_0_z_xz_z_xx = buffer_1010_pdpd[2856];

    auto g_z_0_z_0_z_xz_z_xy = buffer_1010_pdpd[2857];

    auto g_z_0_z_0_z_xz_z_xz = buffer_1010_pdpd[2858];

    auto g_z_0_z_0_z_xz_z_yy = buffer_1010_pdpd[2859];

    auto g_z_0_z_0_z_xz_z_yz = buffer_1010_pdpd[2860];

    auto g_z_0_z_0_z_xz_z_zz = buffer_1010_pdpd[2861];

    auto g_z_0_z_0_z_yy_x_xx = buffer_1010_pdpd[2862];

    auto g_z_0_z_0_z_yy_x_xy = buffer_1010_pdpd[2863];

    auto g_z_0_z_0_z_yy_x_xz = buffer_1010_pdpd[2864];

    auto g_z_0_z_0_z_yy_x_yy = buffer_1010_pdpd[2865];

    auto g_z_0_z_0_z_yy_x_yz = buffer_1010_pdpd[2866];

    auto g_z_0_z_0_z_yy_x_zz = buffer_1010_pdpd[2867];

    auto g_z_0_z_0_z_yy_y_xx = buffer_1010_pdpd[2868];

    auto g_z_0_z_0_z_yy_y_xy = buffer_1010_pdpd[2869];

    auto g_z_0_z_0_z_yy_y_xz = buffer_1010_pdpd[2870];

    auto g_z_0_z_0_z_yy_y_yy = buffer_1010_pdpd[2871];

    auto g_z_0_z_0_z_yy_y_yz = buffer_1010_pdpd[2872];

    auto g_z_0_z_0_z_yy_y_zz = buffer_1010_pdpd[2873];

    auto g_z_0_z_0_z_yy_z_xx = buffer_1010_pdpd[2874];

    auto g_z_0_z_0_z_yy_z_xy = buffer_1010_pdpd[2875];

    auto g_z_0_z_0_z_yy_z_xz = buffer_1010_pdpd[2876];

    auto g_z_0_z_0_z_yy_z_yy = buffer_1010_pdpd[2877];

    auto g_z_0_z_0_z_yy_z_yz = buffer_1010_pdpd[2878];

    auto g_z_0_z_0_z_yy_z_zz = buffer_1010_pdpd[2879];

    auto g_z_0_z_0_z_yz_x_xx = buffer_1010_pdpd[2880];

    auto g_z_0_z_0_z_yz_x_xy = buffer_1010_pdpd[2881];

    auto g_z_0_z_0_z_yz_x_xz = buffer_1010_pdpd[2882];

    auto g_z_0_z_0_z_yz_x_yy = buffer_1010_pdpd[2883];

    auto g_z_0_z_0_z_yz_x_yz = buffer_1010_pdpd[2884];

    auto g_z_0_z_0_z_yz_x_zz = buffer_1010_pdpd[2885];

    auto g_z_0_z_0_z_yz_y_xx = buffer_1010_pdpd[2886];

    auto g_z_0_z_0_z_yz_y_xy = buffer_1010_pdpd[2887];

    auto g_z_0_z_0_z_yz_y_xz = buffer_1010_pdpd[2888];

    auto g_z_0_z_0_z_yz_y_yy = buffer_1010_pdpd[2889];

    auto g_z_0_z_0_z_yz_y_yz = buffer_1010_pdpd[2890];

    auto g_z_0_z_0_z_yz_y_zz = buffer_1010_pdpd[2891];

    auto g_z_0_z_0_z_yz_z_xx = buffer_1010_pdpd[2892];

    auto g_z_0_z_0_z_yz_z_xy = buffer_1010_pdpd[2893];

    auto g_z_0_z_0_z_yz_z_xz = buffer_1010_pdpd[2894];

    auto g_z_0_z_0_z_yz_z_yy = buffer_1010_pdpd[2895];

    auto g_z_0_z_0_z_yz_z_yz = buffer_1010_pdpd[2896];

    auto g_z_0_z_0_z_yz_z_zz = buffer_1010_pdpd[2897];

    auto g_z_0_z_0_z_zz_x_xx = buffer_1010_pdpd[2898];

    auto g_z_0_z_0_z_zz_x_xy = buffer_1010_pdpd[2899];

    auto g_z_0_z_0_z_zz_x_xz = buffer_1010_pdpd[2900];

    auto g_z_0_z_0_z_zz_x_yy = buffer_1010_pdpd[2901];

    auto g_z_0_z_0_z_zz_x_yz = buffer_1010_pdpd[2902];

    auto g_z_0_z_0_z_zz_x_zz = buffer_1010_pdpd[2903];

    auto g_z_0_z_0_z_zz_y_xx = buffer_1010_pdpd[2904];

    auto g_z_0_z_0_z_zz_y_xy = buffer_1010_pdpd[2905];

    auto g_z_0_z_0_z_zz_y_xz = buffer_1010_pdpd[2906];

    auto g_z_0_z_0_z_zz_y_yy = buffer_1010_pdpd[2907];

    auto g_z_0_z_0_z_zz_y_yz = buffer_1010_pdpd[2908];

    auto g_z_0_z_0_z_zz_y_zz = buffer_1010_pdpd[2909];

    auto g_z_0_z_0_z_zz_z_xx = buffer_1010_pdpd[2910];

    auto g_z_0_z_0_z_zz_z_xy = buffer_1010_pdpd[2911];

    auto g_z_0_z_0_z_zz_z_xz = buffer_1010_pdpd[2912];

    auto g_z_0_z_0_z_zz_z_yy = buffer_1010_pdpd[2913];

    auto g_z_0_z_0_z_zz_z_yz = buffer_1010_pdpd[2914];

    auto g_z_0_z_0_z_zz_z_zz = buffer_1010_pdpd[2915];

    // integrals block (0-6)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_xx_xx, g_0_xx_xx_xy, g_0_xx_xx_xz, g_0_xx_xx_yy, g_0_xx_xx_yz, g_0_xx_xx_zz, g_x_0_x_0_x_xx_x_xx, g_x_0_x_0_x_xx_x_xy, g_x_0_x_0_x_xx_x_xz, g_x_0_x_0_x_xx_x_yy, g_x_0_x_0_x_xx_x_yz, g_x_0_x_0_x_xx_x_zz, g_xx_xx_0_xx, g_xx_xx_0_xy, g_xx_xx_0_xz, g_xx_xx_0_yy, g_xx_xx_0_yz, g_xx_xx_0_zz, g_xx_xx_xx_xx, g_xx_xx_xx_xy, g_xx_xx_xx_xz, g_xx_xx_xx_yy, g_xx_xx_xx_yz, g_xx_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xx_x_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_xx_xx[i] * c_exps[i] - 2.0 * g_xx_xx_0_xx[i] * a_exp + 4.0 * g_xx_xx_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_x_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_xx_xy[i] * c_exps[i] - 2.0 * g_xx_xx_0_xy[i] * a_exp + 4.0 * g_xx_xx_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_x_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_xx_xz[i] * c_exps[i] - 2.0 * g_xx_xx_0_xz[i] * a_exp + 4.0 * g_xx_xx_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_x_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_xx_yy[i] * c_exps[i] - 2.0 * g_xx_xx_0_yy[i] * a_exp + 4.0 * g_xx_xx_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_x_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_xx_yz[i] * c_exps[i] - 2.0 * g_xx_xx_0_yz[i] * a_exp + 4.0 * g_xx_xx_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_x_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_xx_zz[i] * c_exps[i] - 2.0 * g_xx_xx_0_zz[i] * a_exp + 4.0 * g_xx_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (6-12)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_x_0_x_0_x_xx_y_xx, g_x_0_x_0_x_xx_y_xy, g_x_0_x_0_x_xx_y_xz, g_x_0_x_0_x_xx_y_yy, g_x_0_x_0_x_xx_y_yz, g_x_0_x_0_x_xx_y_zz, g_xx_xx_xy_xx, g_xx_xx_xy_xy, g_xx_xx_xy_xz, g_xx_xx_xy_yy, g_xx_xx_xy_yz, g_xx_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xx_y_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_y_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_y_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_y_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_y_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_y_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (12-18)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_x_0_x_0_x_xx_z_xx, g_x_0_x_0_x_xx_z_xy, g_x_0_x_0_x_xx_z_xz, g_x_0_x_0_x_xx_z_yy, g_x_0_x_0_x_xx_z_yz, g_x_0_x_0_x_xx_z_zz, g_xx_xx_xz_xx, g_xx_xx_xz_xy, g_xx_xx_xz_xz, g_xx_xx_xz_yy, g_xx_xx_xz_yz, g_xx_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xx_z_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_z_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_z_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_z_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_z_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xx_z_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (18-24)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_xx_xx, g_0_xy_xx_xy, g_0_xy_xx_xz, g_0_xy_xx_yy, g_0_xy_xx_yz, g_0_xy_xx_zz, g_x_0_x_0_x_xy_x_xx, g_x_0_x_0_x_xy_x_xy, g_x_0_x_0_x_xy_x_xz, g_x_0_x_0_x_xy_x_yy, g_x_0_x_0_x_xy_x_yz, g_x_0_x_0_x_xy_x_zz, g_xx_xy_0_xx, g_xx_xy_0_xy, g_xx_xy_0_xz, g_xx_xy_0_yy, g_xx_xy_0_yz, g_xx_xy_0_zz, g_xx_xy_xx_xx, g_xx_xy_xx_xy, g_xx_xy_xx_xz, g_xx_xy_xx_yy, g_xx_xy_xx_yz, g_xx_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xy_x_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_xx_xx[i] * c_exps[i] - 2.0 * g_xx_xy_0_xx[i] * a_exp + 4.0 * g_xx_xy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_x_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_xx_xy[i] * c_exps[i] - 2.0 * g_xx_xy_0_xy[i] * a_exp + 4.0 * g_xx_xy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_x_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_xx_xz[i] * c_exps[i] - 2.0 * g_xx_xy_0_xz[i] * a_exp + 4.0 * g_xx_xy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_x_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_xx_yy[i] * c_exps[i] - 2.0 * g_xx_xy_0_yy[i] * a_exp + 4.0 * g_xx_xy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_x_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_xx_yz[i] * c_exps[i] - 2.0 * g_xx_xy_0_yz[i] * a_exp + 4.0 * g_xx_xy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_x_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_xx_zz[i] * c_exps[i] - 2.0 * g_xx_xy_0_zz[i] * a_exp + 4.0 * g_xx_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (24-30)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_x_0_x_0_x_xy_y_xx, g_x_0_x_0_x_xy_y_xy, g_x_0_x_0_x_xy_y_xz, g_x_0_x_0_x_xy_y_yy, g_x_0_x_0_x_xy_y_yz, g_x_0_x_0_x_xy_y_zz, g_xx_xy_xy_xx, g_xx_xy_xy_xy, g_xx_xy_xy_xz, g_xx_xy_xy_yy, g_xx_xy_xy_yz, g_xx_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xy_y_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_y_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_y_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_y_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_y_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_y_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (30-36)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_x_0_x_0_x_xy_z_xx, g_x_0_x_0_x_xy_z_xy, g_x_0_x_0_x_xy_z_xz, g_x_0_x_0_x_xy_z_yy, g_x_0_x_0_x_xy_z_yz, g_x_0_x_0_x_xy_z_zz, g_xx_xy_xz_xx, g_xx_xy_xz_xy, g_xx_xy_xz_xz, g_xx_xy_xz_yy, g_xx_xy_xz_yz, g_xx_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xy_z_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_z_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_z_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_z_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_z_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xy_z_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (36-42)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_xx_xx, g_0_xz_xx_xy, g_0_xz_xx_xz, g_0_xz_xx_yy, g_0_xz_xx_yz, g_0_xz_xx_zz, g_x_0_x_0_x_xz_x_xx, g_x_0_x_0_x_xz_x_xy, g_x_0_x_0_x_xz_x_xz, g_x_0_x_0_x_xz_x_yy, g_x_0_x_0_x_xz_x_yz, g_x_0_x_0_x_xz_x_zz, g_xx_xz_0_xx, g_xx_xz_0_xy, g_xx_xz_0_xz, g_xx_xz_0_yy, g_xx_xz_0_yz, g_xx_xz_0_zz, g_xx_xz_xx_xx, g_xx_xz_xx_xy, g_xx_xz_xx_xz, g_xx_xz_xx_yy, g_xx_xz_xx_yz, g_xx_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xz_x_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_xx_xx[i] * c_exps[i] - 2.0 * g_xx_xz_0_xx[i] * a_exp + 4.0 * g_xx_xz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_x_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_xx_xy[i] * c_exps[i] - 2.0 * g_xx_xz_0_xy[i] * a_exp + 4.0 * g_xx_xz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_x_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_xx_xz[i] * c_exps[i] - 2.0 * g_xx_xz_0_xz[i] * a_exp + 4.0 * g_xx_xz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_x_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_xx_yy[i] * c_exps[i] - 2.0 * g_xx_xz_0_yy[i] * a_exp + 4.0 * g_xx_xz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_x_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_xx_yz[i] * c_exps[i] - 2.0 * g_xx_xz_0_yz[i] * a_exp + 4.0 * g_xx_xz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_x_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_xx_zz[i] * c_exps[i] - 2.0 * g_xx_xz_0_zz[i] * a_exp + 4.0 * g_xx_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (42-48)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_x_0_x_0_x_xz_y_xx, g_x_0_x_0_x_xz_y_xy, g_x_0_x_0_x_xz_y_xz, g_x_0_x_0_x_xz_y_yy, g_x_0_x_0_x_xz_y_yz, g_x_0_x_0_x_xz_y_zz, g_xx_xz_xy_xx, g_xx_xz_xy_xy, g_xx_xz_xy_xz, g_xx_xz_xy_yy, g_xx_xz_xy_yz, g_xx_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xz_y_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_y_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_y_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_y_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_y_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_y_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (48-54)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_x_0_x_0_x_xz_z_xx, g_x_0_x_0_x_xz_z_xy, g_x_0_x_0_x_xz_z_xz, g_x_0_x_0_x_xz_z_yy, g_x_0_x_0_x_xz_z_yz, g_x_0_x_0_x_xz_z_zz, g_xx_xz_xz_xx, g_xx_xz_xz_xy, g_xx_xz_xz_xz, g_xx_xz_xz_yy, g_xx_xz_xz_yz, g_xx_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_xz_z_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_z_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_z_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_z_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_z_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_xz_z_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (54-60)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_xx_xx, g_0_yy_xx_xy, g_0_yy_xx_xz, g_0_yy_xx_yy, g_0_yy_xx_yz, g_0_yy_xx_zz, g_x_0_x_0_x_yy_x_xx, g_x_0_x_0_x_yy_x_xy, g_x_0_x_0_x_yy_x_xz, g_x_0_x_0_x_yy_x_yy, g_x_0_x_0_x_yy_x_yz, g_x_0_x_0_x_yy_x_zz, g_xx_yy_0_xx, g_xx_yy_0_xy, g_xx_yy_0_xz, g_xx_yy_0_yy, g_xx_yy_0_yz, g_xx_yy_0_zz, g_xx_yy_xx_xx, g_xx_yy_xx_xy, g_xx_yy_xx_xz, g_xx_yy_xx_yy, g_xx_yy_xx_yz, g_xx_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yy_x_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_xx_xx[i] * c_exps[i] - 2.0 * g_xx_yy_0_xx[i] * a_exp + 4.0 * g_xx_yy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_x_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_xx_xy[i] * c_exps[i] - 2.0 * g_xx_yy_0_xy[i] * a_exp + 4.0 * g_xx_yy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_x_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_xx_xz[i] * c_exps[i] - 2.0 * g_xx_yy_0_xz[i] * a_exp + 4.0 * g_xx_yy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_x_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_xx_yy[i] * c_exps[i] - 2.0 * g_xx_yy_0_yy[i] * a_exp + 4.0 * g_xx_yy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_x_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_xx_yz[i] * c_exps[i] - 2.0 * g_xx_yy_0_yz[i] * a_exp + 4.0 * g_xx_yy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_x_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_xx_zz[i] * c_exps[i] - 2.0 * g_xx_yy_0_zz[i] * a_exp + 4.0 * g_xx_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (60-66)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_x_0_x_0_x_yy_y_xx, g_x_0_x_0_x_yy_y_xy, g_x_0_x_0_x_yy_y_xz, g_x_0_x_0_x_yy_y_yy, g_x_0_x_0_x_yy_y_yz, g_x_0_x_0_x_yy_y_zz, g_xx_yy_xy_xx, g_xx_yy_xy_xy, g_xx_yy_xy_xz, g_xx_yy_xy_yy, g_xx_yy_xy_yz, g_xx_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yy_y_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_y_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_y_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_y_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_xx_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_y_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_y_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (66-72)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_x_0_x_0_x_yy_z_xx, g_x_0_x_0_x_yy_z_xy, g_x_0_x_0_x_yy_z_xz, g_x_0_x_0_x_yy_z_yy, g_x_0_x_0_x_yy_z_yz, g_x_0_x_0_x_yy_z_zz, g_xx_yy_xz_xx, g_xx_yy_xz_xy, g_xx_yy_xz_xz, g_xx_yy_xz_yy, g_xx_yy_xz_yz, g_xx_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yy_z_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_z_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_z_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_z_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_xx_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_z_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yy_z_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (72-78)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_xx_xx, g_0_yz_xx_xy, g_0_yz_xx_xz, g_0_yz_xx_yy, g_0_yz_xx_yz, g_0_yz_xx_zz, g_x_0_x_0_x_yz_x_xx, g_x_0_x_0_x_yz_x_xy, g_x_0_x_0_x_yz_x_xz, g_x_0_x_0_x_yz_x_yy, g_x_0_x_0_x_yz_x_yz, g_x_0_x_0_x_yz_x_zz, g_xx_yz_0_xx, g_xx_yz_0_xy, g_xx_yz_0_xz, g_xx_yz_0_yy, g_xx_yz_0_yz, g_xx_yz_0_zz, g_xx_yz_xx_xx, g_xx_yz_xx_xy, g_xx_yz_xx_xz, g_xx_yz_xx_yy, g_xx_yz_xx_yz, g_xx_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yz_x_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_xx_xx[i] * c_exps[i] - 2.0 * g_xx_yz_0_xx[i] * a_exp + 4.0 * g_xx_yz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_x_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_xx_xy[i] * c_exps[i] - 2.0 * g_xx_yz_0_xy[i] * a_exp + 4.0 * g_xx_yz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_x_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_xx_xz[i] * c_exps[i] - 2.0 * g_xx_yz_0_xz[i] * a_exp + 4.0 * g_xx_yz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_x_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_xx_yy[i] * c_exps[i] - 2.0 * g_xx_yz_0_yy[i] * a_exp + 4.0 * g_xx_yz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_x_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_xx_yz[i] * c_exps[i] - 2.0 * g_xx_yz_0_yz[i] * a_exp + 4.0 * g_xx_yz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_x_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_xx_zz[i] * c_exps[i] - 2.0 * g_xx_yz_0_zz[i] * a_exp + 4.0 * g_xx_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (78-84)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_x_0_x_0_x_yz_y_xx, g_x_0_x_0_x_yz_y_xy, g_x_0_x_0_x_yz_y_xz, g_x_0_x_0_x_yz_y_yy, g_x_0_x_0_x_yz_y_yz, g_x_0_x_0_x_yz_y_zz, g_xx_yz_xy_xx, g_xx_yz_xy_xy, g_xx_yz_xy_xz, g_xx_yz_xy_yy, g_xx_yz_xy_yz, g_xx_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yz_y_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_y_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_y_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_y_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_y_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_y_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (84-90)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_x_0_x_0_x_yz_z_xx, g_x_0_x_0_x_yz_z_xy, g_x_0_x_0_x_yz_z_xz, g_x_0_x_0_x_yz_z_yy, g_x_0_x_0_x_yz_z_yz, g_x_0_x_0_x_yz_z_zz, g_xx_yz_xz_xx, g_xx_yz_xz_xy, g_xx_yz_xz_xz, g_xx_yz_xz_yy, g_xx_yz_xz_yz, g_xx_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_yz_z_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_z_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_z_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_z_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_z_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_yz_z_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (90-96)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_xx_xx, g_0_zz_xx_xy, g_0_zz_xx_xz, g_0_zz_xx_yy, g_0_zz_xx_yz, g_0_zz_xx_zz, g_x_0_x_0_x_zz_x_xx, g_x_0_x_0_x_zz_x_xy, g_x_0_x_0_x_zz_x_xz, g_x_0_x_0_x_zz_x_yy, g_x_0_x_0_x_zz_x_yz, g_x_0_x_0_x_zz_x_zz, g_xx_zz_0_xx, g_xx_zz_0_xy, g_xx_zz_0_xz, g_xx_zz_0_yy, g_xx_zz_0_yz, g_xx_zz_0_zz, g_xx_zz_xx_xx, g_xx_zz_xx_xy, g_xx_zz_xx_xz, g_xx_zz_xx_yy, g_xx_zz_xx_yz, g_xx_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_zz_x_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_xx_xx[i] * c_exps[i] - 2.0 * g_xx_zz_0_xx[i] * a_exp + 4.0 * g_xx_zz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_x_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_xx_xy[i] * c_exps[i] - 2.0 * g_xx_zz_0_xy[i] * a_exp + 4.0 * g_xx_zz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_x_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_xx_xz[i] * c_exps[i] - 2.0 * g_xx_zz_0_xz[i] * a_exp + 4.0 * g_xx_zz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_x_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_xx_yy[i] * c_exps[i] - 2.0 * g_xx_zz_0_yy[i] * a_exp + 4.0 * g_xx_zz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_x_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_xx_yz[i] * c_exps[i] - 2.0 * g_xx_zz_0_yz[i] * a_exp + 4.0 * g_xx_zz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_x_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_xx_zz[i] * c_exps[i] - 2.0 * g_xx_zz_0_zz[i] * a_exp + 4.0 * g_xx_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (96-102)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_x_0_x_0_x_zz_y_xx, g_x_0_x_0_x_zz_y_xy, g_x_0_x_0_x_zz_y_xz, g_x_0_x_0_x_zz_y_yy, g_x_0_x_0_x_zz_y_yz, g_x_0_x_0_x_zz_y_zz, g_xx_zz_xy_xx, g_xx_zz_xy_xy, g_xx_zz_xy_xz, g_xx_zz_xy_yy, g_xx_zz_xy_yz, g_xx_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_zz_y_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_y_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_y_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_y_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_y_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_y_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (102-108)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_x_0_x_0_x_zz_z_xx, g_x_0_x_0_x_zz_z_xy, g_x_0_x_0_x_zz_z_xz, g_x_0_x_0_x_zz_z_yy, g_x_0_x_0_x_zz_z_yz, g_x_0_x_0_x_zz_z_zz, g_xx_zz_xz_xx, g_xx_zz_xz_xy, g_xx_zz_xz_xz, g_xx_zz_xz_yy, g_xx_zz_xz_yz, g_xx_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_x_zz_z_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_z_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_z_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_z_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_z_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_x_zz_z_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (108-114)

    #pragma omp simd aligned(g_x_0_x_0_y_xx_x_xx, g_x_0_x_0_y_xx_x_xy, g_x_0_x_0_y_xx_x_xz, g_x_0_x_0_y_xx_x_yy, g_x_0_x_0_y_xx_x_yz, g_x_0_x_0_y_xx_x_zz, g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_xx_xx, g_xy_xx_xx_xy, g_xy_xx_xx_xz, g_xy_xx_xx_yy, g_xy_xx_xx_yz, g_xy_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xx_x_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_x_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_x_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_x_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_x_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_x_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (114-120)

    #pragma omp simd aligned(g_x_0_x_0_y_xx_y_xx, g_x_0_x_0_y_xx_y_xy, g_x_0_x_0_y_xx_y_xz, g_x_0_x_0_y_xx_y_yy, g_x_0_x_0_y_xx_y_yz, g_x_0_x_0_y_xx_y_zz, g_xy_xx_xy_xx, g_xy_xx_xy_xy, g_xy_xx_xy_xz, g_xy_xx_xy_yy, g_xy_xx_xy_yz, g_xy_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xx_y_xx[i] = 4.0 * g_xy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_y_xy[i] = 4.0 * g_xy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_y_xz[i] = 4.0 * g_xy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_y_yy[i] = 4.0 * g_xy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_y_yz[i] = 4.0 * g_xy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_y_zz[i] = 4.0 * g_xy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (120-126)

    #pragma omp simd aligned(g_x_0_x_0_y_xx_z_xx, g_x_0_x_0_y_xx_z_xy, g_x_0_x_0_y_xx_z_xz, g_x_0_x_0_y_xx_z_yy, g_x_0_x_0_y_xx_z_yz, g_x_0_x_0_y_xx_z_zz, g_xy_xx_xz_xx, g_xy_xx_xz_xy, g_xy_xx_xz_xz, g_xy_xx_xz_yy, g_xy_xx_xz_yz, g_xy_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xx_z_xx[i] = 4.0 * g_xy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_z_xy[i] = 4.0 * g_xy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_z_xz[i] = 4.0 * g_xy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_z_yy[i] = 4.0 * g_xy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_z_yz[i] = 4.0 * g_xy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xx_z_zz[i] = 4.0 * g_xy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (126-132)

    #pragma omp simd aligned(g_x_0_x_0_y_xy_x_xx, g_x_0_x_0_y_xy_x_xy, g_x_0_x_0_y_xy_x_xz, g_x_0_x_0_y_xy_x_yy, g_x_0_x_0_y_xy_x_yz, g_x_0_x_0_y_xy_x_zz, g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_xx_xx, g_xy_xy_xx_xy, g_xy_xy_xx_xz, g_xy_xy_xx_yy, g_xy_xy_xx_yz, g_xy_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xy_x_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_x_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_x_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_x_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_x_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_x_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (132-138)

    #pragma omp simd aligned(g_x_0_x_0_y_xy_y_xx, g_x_0_x_0_y_xy_y_xy, g_x_0_x_0_y_xy_y_xz, g_x_0_x_0_y_xy_y_yy, g_x_0_x_0_y_xy_y_yz, g_x_0_x_0_y_xy_y_zz, g_xy_xy_xy_xx, g_xy_xy_xy_xy, g_xy_xy_xy_xz, g_xy_xy_xy_yy, g_xy_xy_xy_yz, g_xy_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xy_y_xx[i] = 4.0 * g_xy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_y_xy[i] = 4.0 * g_xy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_y_xz[i] = 4.0 * g_xy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_y_yy[i] = 4.0 * g_xy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_y_yz[i] = 4.0 * g_xy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_y_zz[i] = 4.0 * g_xy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (138-144)

    #pragma omp simd aligned(g_x_0_x_0_y_xy_z_xx, g_x_0_x_0_y_xy_z_xy, g_x_0_x_0_y_xy_z_xz, g_x_0_x_0_y_xy_z_yy, g_x_0_x_0_y_xy_z_yz, g_x_0_x_0_y_xy_z_zz, g_xy_xy_xz_xx, g_xy_xy_xz_xy, g_xy_xy_xz_xz, g_xy_xy_xz_yy, g_xy_xy_xz_yz, g_xy_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xy_z_xx[i] = 4.0 * g_xy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_z_xy[i] = 4.0 * g_xy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_z_xz[i] = 4.0 * g_xy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_z_yy[i] = 4.0 * g_xy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_z_yz[i] = 4.0 * g_xy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xy_z_zz[i] = 4.0 * g_xy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (144-150)

    #pragma omp simd aligned(g_x_0_x_0_y_xz_x_xx, g_x_0_x_0_y_xz_x_xy, g_x_0_x_0_y_xz_x_xz, g_x_0_x_0_y_xz_x_yy, g_x_0_x_0_y_xz_x_yz, g_x_0_x_0_y_xz_x_zz, g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_xx_xx, g_xy_xz_xx_xy, g_xy_xz_xx_xz, g_xy_xz_xx_yy, g_xy_xz_xx_yz, g_xy_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xz_x_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_x_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_x_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_x_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_x_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_x_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (150-156)

    #pragma omp simd aligned(g_x_0_x_0_y_xz_y_xx, g_x_0_x_0_y_xz_y_xy, g_x_0_x_0_y_xz_y_xz, g_x_0_x_0_y_xz_y_yy, g_x_0_x_0_y_xz_y_yz, g_x_0_x_0_y_xz_y_zz, g_xy_xz_xy_xx, g_xy_xz_xy_xy, g_xy_xz_xy_xz, g_xy_xz_xy_yy, g_xy_xz_xy_yz, g_xy_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xz_y_xx[i] = 4.0 * g_xy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_y_xy[i] = 4.0 * g_xy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_y_xz[i] = 4.0 * g_xy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_y_yy[i] = 4.0 * g_xy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_y_yz[i] = 4.0 * g_xy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_y_zz[i] = 4.0 * g_xy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (156-162)

    #pragma omp simd aligned(g_x_0_x_0_y_xz_z_xx, g_x_0_x_0_y_xz_z_xy, g_x_0_x_0_y_xz_z_xz, g_x_0_x_0_y_xz_z_yy, g_x_0_x_0_y_xz_z_yz, g_x_0_x_0_y_xz_z_zz, g_xy_xz_xz_xx, g_xy_xz_xz_xy, g_xy_xz_xz_xz, g_xy_xz_xz_yy, g_xy_xz_xz_yz, g_xy_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_xz_z_xx[i] = 4.0 * g_xy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_z_xy[i] = 4.0 * g_xy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_z_xz[i] = 4.0 * g_xy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_z_yy[i] = 4.0 * g_xy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_z_yz[i] = 4.0 * g_xy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_xz_z_zz[i] = 4.0 * g_xy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (162-168)

    #pragma omp simd aligned(g_x_0_x_0_y_yy_x_xx, g_x_0_x_0_y_yy_x_xy, g_x_0_x_0_y_yy_x_xz, g_x_0_x_0_y_yy_x_yy, g_x_0_x_0_y_yy_x_yz, g_x_0_x_0_y_yy_x_zz, g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_xx_xx, g_xy_yy_xx_xy, g_xy_yy_xx_xz, g_xy_yy_xx_yy, g_xy_yy_xx_yz, g_xy_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yy_x_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_x_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_x_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_x_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_x_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_x_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (168-174)

    #pragma omp simd aligned(g_x_0_x_0_y_yy_y_xx, g_x_0_x_0_y_yy_y_xy, g_x_0_x_0_y_yy_y_xz, g_x_0_x_0_y_yy_y_yy, g_x_0_x_0_y_yy_y_yz, g_x_0_x_0_y_yy_y_zz, g_xy_yy_xy_xx, g_xy_yy_xy_xy, g_xy_yy_xy_xz, g_xy_yy_xy_yy, g_xy_yy_xy_yz, g_xy_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yy_y_xx[i] = 4.0 * g_xy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_y_xy[i] = 4.0 * g_xy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_y_xz[i] = 4.0 * g_xy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_y_yy[i] = 4.0 * g_xy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_y_yz[i] = 4.0 * g_xy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_y_zz[i] = 4.0 * g_xy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (174-180)

    #pragma omp simd aligned(g_x_0_x_0_y_yy_z_xx, g_x_0_x_0_y_yy_z_xy, g_x_0_x_0_y_yy_z_xz, g_x_0_x_0_y_yy_z_yy, g_x_0_x_0_y_yy_z_yz, g_x_0_x_0_y_yy_z_zz, g_xy_yy_xz_xx, g_xy_yy_xz_xy, g_xy_yy_xz_xz, g_xy_yy_xz_yy, g_xy_yy_xz_yz, g_xy_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yy_z_xx[i] = 4.0 * g_xy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_z_xy[i] = 4.0 * g_xy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_z_xz[i] = 4.0 * g_xy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_z_yy[i] = 4.0 * g_xy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_z_yz[i] = 4.0 * g_xy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yy_z_zz[i] = 4.0 * g_xy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (180-186)

    #pragma omp simd aligned(g_x_0_x_0_y_yz_x_xx, g_x_0_x_0_y_yz_x_xy, g_x_0_x_0_y_yz_x_xz, g_x_0_x_0_y_yz_x_yy, g_x_0_x_0_y_yz_x_yz, g_x_0_x_0_y_yz_x_zz, g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_xx_xx, g_xy_yz_xx_xy, g_xy_yz_xx_xz, g_xy_yz_xx_yy, g_xy_yz_xx_yz, g_xy_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yz_x_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_x_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_x_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_x_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_x_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_x_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (186-192)

    #pragma omp simd aligned(g_x_0_x_0_y_yz_y_xx, g_x_0_x_0_y_yz_y_xy, g_x_0_x_0_y_yz_y_xz, g_x_0_x_0_y_yz_y_yy, g_x_0_x_0_y_yz_y_yz, g_x_0_x_0_y_yz_y_zz, g_xy_yz_xy_xx, g_xy_yz_xy_xy, g_xy_yz_xy_xz, g_xy_yz_xy_yy, g_xy_yz_xy_yz, g_xy_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yz_y_xx[i] = 4.0 * g_xy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_y_xy[i] = 4.0 * g_xy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_y_xz[i] = 4.0 * g_xy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_y_yy[i] = 4.0 * g_xy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_y_yz[i] = 4.0 * g_xy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_y_zz[i] = 4.0 * g_xy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (192-198)

    #pragma omp simd aligned(g_x_0_x_0_y_yz_z_xx, g_x_0_x_0_y_yz_z_xy, g_x_0_x_0_y_yz_z_xz, g_x_0_x_0_y_yz_z_yy, g_x_0_x_0_y_yz_z_yz, g_x_0_x_0_y_yz_z_zz, g_xy_yz_xz_xx, g_xy_yz_xz_xy, g_xy_yz_xz_xz, g_xy_yz_xz_yy, g_xy_yz_xz_yz, g_xy_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_yz_z_xx[i] = 4.0 * g_xy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_z_xy[i] = 4.0 * g_xy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_z_xz[i] = 4.0 * g_xy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_z_yy[i] = 4.0 * g_xy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_z_yz[i] = 4.0 * g_xy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_yz_z_zz[i] = 4.0 * g_xy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (198-204)

    #pragma omp simd aligned(g_x_0_x_0_y_zz_x_xx, g_x_0_x_0_y_zz_x_xy, g_x_0_x_0_y_zz_x_xz, g_x_0_x_0_y_zz_x_yy, g_x_0_x_0_y_zz_x_yz, g_x_0_x_0_y_zz_x_zz, g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_xx_xx, g_xy_zz_xx_xy, g_xy_zz_xx_xz, g_xy_zz_xx_yy, g_xy_zz_xx_yz, g_xy_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_zz_x_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_x_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_x_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_x_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_x_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_x_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (204-210)

    #pragma omp simd aligned(g_x_0_x_0_y_zz_y_xx, g_x_0_x_0_y_zz_y_xy, g_x_0_x_0_y_zz_y_xz, g_x_0_x_0_y_zz_y_yy, g_x_0_x_0_y_zz_y_yz, g_x_0_x_0_y_zz_y_zz, g_xy_zz_xy_xx, g_xy_zz_xy_xy, g_xy_zz_xy_xz, g_xy_zz_xy_yy, g_xy_zz_xy_yz, g_xy_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_zz_y_xx[i] = 4.0 * g_xy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_y_xy[i] = 4.0 * g_xy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_y_xz[i] = 4.0 * g_xy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_y_yy[i] = 4.0 * g_xy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_y_yz[i] = 4.0 * g_xy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_y_zz[i] = 4.0 * g_xy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (210-216)

    #pragma omp simd aligned(g_x_0_x_0_y_zz_z_xx, g_x_0_x_0_y_zz_z_xy, g_x_0_x_0_y_zz_z_xz, g_x_0_x_0_y_zz_z_yy, g_x_0_x_0_y_zz_z_yz, g_x_0_x_0_y_zz_z_zz, g_xy_zz_xz_xx, g_xy_zz_xz_xy, g_xy_zz_xz_xz, g_xy_zz_xz_yy, g_xy_zz_xz_yz, g_xy_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_y_zz_z_xx[i] = 4.0 * g_xy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_z_xy[i] = 4.0 * g_xy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_z_xz[i] = 4.0 * g_xy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_z_yy[i] = 4.0 * g_xy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_z_yz[i] = 4.0 * g_xy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_y_zz_z_zz[i] = 4.0 * g_xy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (216-222)

    #pragma omp simd aligned(g_x_0_x_0_z_xx_x_xx, g_x_0_x_0_z_xx_x_xy, g_x_0_x_0_z_xx_x_xz, g_x_0_x_0_z_xx_x_yy, g_x_0_x_0_z_xx_x_yz, g_x_0_x_0_z_xx_x_zz, g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_xx_xx, g_xz_xx_xx_xy, g_xz_xx_xx_xz, g_xz_xx_xx_yy, g_xz_xx_xx_yz, g_xz_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xx_x_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_x_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_x_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_x_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_x_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_x_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (222-228)

    #pragma omp simd aligned(g_x_0_x_0_z_xx_y_xx, g_x_0_x_0_z_xx_y_xy, g_x_0_x_0_z_xx_y_xz, g_x_0_x_0_z_xx_y_yy, g_x_0_x_0_z_xx_y_yz, g_x_0_x_0_z_xx_y_zz, g_xz_xx_xy_xx, g_xz_xx_xy_xy, g_xz_xx_xy_xz, g_xz_xx_xy_yy, g_xz_xx_xy_yz, g_xz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xx_y_xx[i] = 4.0 * g_xz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_y_xy[i] = 4.0 * g_xz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_y_xz[i] = 4.0 * g_xz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_y_yy[i] = 4.0 * g_xz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_y_yz[i] = 4.0 * g_xz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_y_zz[i] = 4.0 * g_xz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (228-234)

    #pragma omp simd aligned(g_x_0_x_0_z_xx_z_xx, g_x_0_x_0_z_xx_z_xy, g_x_0_x_0_z_xx_z_xz, g_x_0_x_0_z_xx_z_yy, g_x_0_x_0_z_xx_z_yz, g_x_0_x_0_z_xx_z_zz, g_xz_xx_xz_xx, g_xz_xx_xz_xy, g_xz_xx_xz_xz, g_xz_xx_xz_yy, g_xz_xx_xz_yz, g_xz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xx_z_xx[i] = 4.0 * g_xz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_z_xy[i] = 4.0 * g_xz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_z_xz[i] = 4.0 * g_xz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_z_yy[i] = 4.0 * g_xz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_z_yz[i] = 4.0 * g_xz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xx_z_zz[i] = 4.0 * g_xz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (234-240)

    #pragma omp simd aligned(g_x_0_x_0_z_xy_x_xx, g_x_0_x_0_z_xy_x_xy, g_x_0_x_0_z_xy_x_xz, g_x_0_x_0_z_xy_x_yy, g_x_0_x_0_z_xy_x_yz, g_x_0_x_0_z_xy_x_zz, g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_xx_xx, g_xz_xy_xx_xy, g_xz_xy_xx_xz, g_xz_xy_xx_yy, g_xz_xy_xx_yz, g_xz_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xy_x_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_x_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_x_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_x_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_x_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_x_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (240-246)

    #pragma omp simd aligned(g_x_0_x_0_z_xy_y_xx, g_x_0_x_0_z_xy_y_xy, g_x_0_x_0_z_xy_y_xz, g_x_0_x_0_z_xy_y_yy, g_x_0_x_0_z_xy_y_yz, g_x_0_x_0_z_xy_y_zz, g_xz_xy_xy_xx, g_xz_xy_xy_xy, g_xz_xy_xy_xz, g_xz_xy_xy_yy, g_xz_xy_xy_yz, g_xz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xy_y_xx[i] = 4.0 * g_xz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_y_xy[i] = 4.0 * g_xz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_y_xz[i] = 4.0 * g_xz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_y_yy[i] = 4.0 * g_xz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_y_yz[i] = 4.0 * g_xz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_y_zz[i] = 4.0 * g_xz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (246-252)

    #pragma omp simd aligned(g_x_0_x_0_z_xy_z_xx, g_x_0_x_0_z_xy_z_xy, g_x_0_x_0_z_xy_z_xz, g_x_0_x_0_z_xy_z_yy, g_x_0_x_0_z_xy_z_yz, g_x_0_x_0_z_xy_z_zz, g_xz_xy_xz_xx, g_xz_xy_xz_xy, g_xz_xy_xz_xz, g_xz_xy_xz_yy, g_xz_xy_xz_yz, g_xz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xy_z_xx[i] = 4.0 * g_xz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_z_xy[i] = 4.0 * g_xz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_z_xz[i] = 4.0 * g_xz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_z_yy[i] = 4.0 * g_xz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_z_yz[i] = 4.0 * g_xz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xy_z_zz[i] = 4.0 * g_xz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (252-258)

    #pragma omp simd aligned(g_x_0_x_0_z_xz_x_xx, g_x_0_x_0_z_xz_x_xy, g_x_0_x_0_z_xz_x_xz, g_x_0_x_0_z_xz_x_yy, g_x_0_x_0_z_xz_x_yz, g_x_0_x_0_z_xz_x_zz, g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_xx_xx, g_xz_xz_xx_xy, g_xz_xz_xx_xz, g_xz_xz_xx_yy, g_xz_xz_xx_yz, g_xz_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xz_x_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_x_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_x_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_x_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_x_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_x_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (258-264)

    #pragma omp simd aligned(g_x_0_x_0_z_xz_y_xx, g_x_0_x_0_z_xz_y_xy, g_x_0_x_0_z_xz_y_xz, g_x_0_x_0_z_xz_y_yy, g_x_0_x_0_z_xz_y_yz, g_x_0_x_0_z_xz_y_zz, g_xz_xz_xy_xx, g_xz_xz_xy_xy, g_xz_xz_xy_xz, g_xz_xz_xy_yy, g_xz_xz_xy_yz, g_xz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xz_y_xx[i] = 4.0 * g_xz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_y_xy[i] = 4.0 * g_xz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_y_xz[i] = 4.0 * g_xz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_y_yy[i] = 4.0 * g_xz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_y_yz[i] = 4.0 * g_xz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_y_zz[i] = 4.0 * g_xz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (264-270)

    #pragma omp simd aligned(g_x_0_x_0_z_xz_z_xx, g_x_0_x_0_z_xz_z_xy, g_x_0_x_0_z_xz_z_xz, g_x_0_x_0_z_xz_z_yy, g_x_0_x_0_z_xz_z_yz, g_x_0_x_0_z_xz_z_zz, g_xz_xz_xz_xx, g_xz_xz_xz_xy, g_xz_xz_xz_xz, g_xz_xz_xz_yy, g_xz_xz_xz_yz, g_xz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_xz_z_xx[i] = 4.0 * g_xz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_z_xy[i] = 4.0 * g_xz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_z_xz[i] = 4.0 * g_xz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_z_yy[i] = 4.0 * g_xz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_z_yz[i] = 4.0 * g_xz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_xz_z_zz[i] = 4.0 * g_xz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (270-276)

    #pragma omp simd aligned(g_x_0_x_0_z_yy_x_xx, g_x_0_x_0_z_yy_x_xy, g_x_0_x_0_z_yy_x_xz, g_x_0_x_0_z_yy_x_yy, g_x_0_x_0_z_yy_x_yz, g_x_0_x_0_z_yy_x_zz, g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_xx_xx, g_xz_yy_xx_xy, g_xz_yy_xx_xz, g_xz_yy_xx_yy, g_xz_yy_xx_yz, g_xz_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yy_x_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_x_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_x_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_x_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_x_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_x_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (276-282)

    #pragma omp simd aligned(g_x_0_x_0_z_yy_y_xx, g_x_0_x_0_z_yy_y_xy, g_x_0_x_0_z_yy_y_xz, g_x_0_x_0_z_yy_y_yy, g_x_0_x_0_z_yy_y_yz, g_x_0_x_0_z_yy_y_zz, g_xz_yy_xy_xx, g_xz_yy_xy_xy, g_xz_yy_xy_xz, g_xz_yy_xy_yy, g_xz_yy_xy_yz, g_xz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yy_y_xx[i] = 4.0 * g_xz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_y_xy[i] = 4.0 * g_xz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_y_xz[i] = 4.0 * g_xz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_y_yy[i] = 4.0 * g_xz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_y_yz[i] = 4.0 * g_xz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_y_zz[i] = 4.0 * g_xz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (282-288)

    #pragma omp simd aligned(g_x_0_x_0_z_yy_z_xx, g_x_0_x_0_z_yy_z_xy, g_x_0_x_0_z_yy_z_xz, g_x_0_x_0_z_yy_z_yy, g_x_0_x_0_z_yy_z_yz, g_x_0_x_0_z_yy_z_zz, g_xz_yy_xz_xx, g_xz_yy_xz_xy, g_xz_yy_xz_xz, g_xz_yy_xz_yy, g_xz_yy_xz_yz, g_xz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yy_z_xx[i] = 4.0 * g_xz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_z_xy[i] = 4.0 * g_xz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_z_xz[i] = 4.0 * g_xz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_z_yy[i] = 4.0 * g_xz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_z_yz[i] = 4.0 * g_xz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yy_z_zz[i] = 4.0 * g_xz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (288-294)

    #pragma omp simd aligned(g_x_0_x_0_z_yz_x_xx, g_x_0_x_0_z_yz_x_xy, g_x_0_x_0_z_yz_x_xz, g_x_0_x_0_z_yz_x_yy, g_x_0_x_0_z_yz_x_yz, g_x_0_x_0_z_yz_x_zz, g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_xx_xx, g_xz_yz_xx_xy, g_xz_yz_xx_xz, g_xz_yz_xx_yy, g_xz_yz_xx_yz, g_xz_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yz_x_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_x_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_x_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_x_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_x_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_x_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (294-300)

    #pragma omp simd aligned(g_x_0_x_0_z_yz_y_xx, g_x_0_x_0_z_yz_y_xy, g_x_0_x_0_z_yz_y_xz, g_x_0_x_0_z_yz_y_yy, g_x_0_x_0_z_yz_y_yz, g_x_0_x_0_z_yz_y_zz, g_xz_yz_xy_xx, g_xz_yz_xy_xy, g_xz_yz_xy_xz, g_xz_yz_xy_yy, g_xz_yz_xy_yz, g_xz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yz_y_xx[i] = 4.0 * g_xz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_y_xy[i] = 4.0 * g_xz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_y_xz[i] = 4.0 * g_xz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_y_yy[i] = 4.0 * g_xz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_y_yz[i] = 4.0 * g_xz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_y_zz[i] = 4.0 * g_xz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (300-306)

    #pragma omp simd aligned(g_x_0_x_0_z_yz_z_xx, g_x_0_x_0_z_yz_z_xy, g_x_0_x_0_z_yz_z_xz, g_x_0_x_0_z_yz_z_yy, g_x_0_x_0_z_yz_z_yz, g_x_0_x_0_z_yz_z_zz, g_xz_yz_xz_xx, g_xz_yz_xz_xy, g_xz_yz_xz_xz, g_xz_yz_xz_yy, g_xz_yz_xz_yz, g_xz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_yz_z_xx[i] = 4.0 * g_xz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_z_xy[i] = 4.0 * g_xz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_z_xz[i] = 4.0 * g_xz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_z_yy[i] = 4.0 * g_xz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_z_yz[i] = 4.0 * g_xz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_yz_z_zz[i] = 4.0 * g_xz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (306-312)

    #pragma omp simd aligned(g_x_0_x_0_z_zz_x_xx, g_x_0_x_0_z_zz_x_xy, g_x_0_x_0_z_zz_x_xz, g_x_0_x_0_z_zz_x_yy, g_x_0_x_0_z_zz_x_yz, g_x_0_x_0_z_zz_x_zz, g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_xx_xx, g_xz_zz_xx_xy, g_xz_zz_xx_xz, g_xz_zz_xx_yy, g_xz_zz_xx_yz, g_xz_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_zz_x_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_xx_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_x_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_xx_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_x_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_xx_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_x_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_xx_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_x_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_xx_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_x_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (312-318)

    #pragma omp simd aligned(g_x_0_x_0_z_zz_y_xx, g_x_0_x_0_z_zz_y_xy, g_x_0_x_0_z_zz_y_xz, g_x_0_x_0_z_zz_y_yy, g_x_0_x_0_z_zz_y_yz, g_x_0_x_0_z_zz_y_zz, g_xz_zz_xy_xx, g_xz_zz_xy_xy, g_xz_zz_xy_xz, g_xz_zz_xy_yy, g_xz_zz_xy_yz, g_xz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_zz_y_xx[i] = 4.0 * g_xz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_y_xy[i] = 4.0 * g_xz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_y_xz[i] = 4.0 * g_xz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_y_yy[i] = 4.0 * g_xz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_y_yz[i] = 4.0 * g_xz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_y_zz[i] = 4.0 * g_xz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (318-324)

    #pragma omp simd aligned(g_x_0_x_0_z_zz_z_xx, g_x_0_x_0_z_zz_z_xy, g_x_0_x_0_z_zz_z_xz, g_x_0_x_0_z_zz_z_yy, g_x_0_x_0_z_zz_z_yz, g_x_0_x_0_z_zz_z_zz, g_xz_zz_xz_xx, g_xz_zz_xz_xy, g_xz_zz_xz_xz, g_xz_zz_xz_yy, g_xz_zz_xz_yz, g_xz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_x_0_z_zz_z_xx[i] = 4.0 * g_xz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_z_xy[i] = 4.0 * g_xz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_z_xz[i] = 4.0 * g_xz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_z_yy[i] = 4.0 * g_xz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_z_yz[i] = 4.0 * g_xz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_x_0_z_zz_z_zz[i] = 4.0 * g_xz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (324-330)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_x_0_y_0_x_xx_x_xx, g_x_0_y_0_x_xx_x_xy, g_x_0_y_0_x_xx_x_xz, g_x_0_y_0_x_xx_x_yy, g_x_0_y_0_x_xx_x_yz, g_x_0_y_0_x_xx_x_zz, g_xx_xx_xy_xx, g_xx_xx_xy_xy, g_xx_xx_xy_xz, g_xx_xx_xy_yy, g_xx_xx_xy_yz, g_xx_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xx_x_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_x_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_x_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_x_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_x_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_x_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (330-336)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_yy_xx, g_0_xx_yy_xy, g_0_xx_yy_xz, g_0_xx_yy_yy, g_0_xx_yy_yz, g_0_xx_yy_zz, g_x_0_y_0_x_xx_y_xx, g_x_0_y_0_x_xx_y_xy, g_x_0_y_0_x_xx_y_xz, g_x_0_y_0_x_xx_y_yy, g_x_0_y_0_x_xx_y_yz, g_x_0_y_0_x_xx_y_zz, g_xx_xx_0_xx, g_xx_xx_0_xy, g_xx_xx_0_xz, g_xx_xx_0_yy, g_xx_xx_0_yz, g_xx_xx_0_zz, g_xx_xx_yy_xx, g_xx_xx_yy_xy, g_xx_xx_yy_xz, g_xx_xx_yy_yy, g_xx_xx_yy_yz, g_xx_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xx_y_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_yy_xx[i] * c_exps[i] - 2.0 * g_xx_xx_0_xx[i] * a_exp + 4.0 * g_xx_xx_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_y_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_yy_xy[i] * c_exps[i] - 2.0 * g_xx_xx_0_xy[i] * a_exp + 4.0 * g_xx_xx_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_y_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_yy_xz[i] * c_exps[i] - 2.0 * g_xx_xx_0_xz[i] * a_exp + 4.0 * g_xx_xx_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_y_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_yy_yy[i] * c_exps[i] - 2.0 * g_xx_xx_0_yy[i] * a_exp + 4.0 * g_xx_xx_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_y_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_yy_yz[i] * c_exps[i] - 2.0 * g_xx_xx_0_yz[i] * a_exp + 4.0 * g_xx_xx_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_y_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_yy_zz[i] * c_exps[i] - 2.0 * g_xx_xx_0_zz[i] * a_exp + 4.0 * g_xx_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (336-342)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_x_0_y_0_x_xx_z_xx, g_x_0_y_0_x_xx_z_xy, g_x_0_y_0_x_xx_z_xz, g_x_0_y_0_x_xx_z_yy, g_x_0_y_0_x_xx_z_yz, g_x_0_y_0_x_xx_z_zz, g_xx_xx_yz_xx, g_xx_xx_yz_xy, g_xx_xx_yz_xz, g_xx_xx_yz_yy, g_xx_xx_yz_yz, g_xx_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xx_z_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_z_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_z_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_z_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_z_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xx_z_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (342-348)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_x_0_y_0_x_xy_x_xx, g_x_0_y_0_x_xy_x_xy, g_x_0_y_0_x_xy_x_xz, g_x_0_y_0_x_xy_x_yy, g_x_0_y_0_x_xy_x_yz, g_x_0_y_0_x_xy_x_zz, g_xx_xy_xy_xx, g_xx_xy_xy_xy, g_xx_xy_xy_xz, g_xx_xy_xy_yy, g_xx_xy_xy_yz, g_xx_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xy_x_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_x_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_x_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_x_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_x_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_x_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (348-354)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_yy_xx, g_0_xy_yy_xy, g_0_xy_yy_xz, g_0_xy_yy_yy, g_0_xy_yy_yz, g_0_xy_yy_zz, g_x_0_y_0_x_xy_y_xx, g_x_0_y_0_x_xy_y_xy, g_x_0_y_0_x_xy_y_xz, g_x_0_y_0_x_xy_y_yy, g_x_0_y_0_x_xy_y_yz, g_x_0_y_0_x_xy_y_zz, g_xx_xy_0_xx, g_xx_xy_0_xy, g_xx_xy_0_xz, g_xx_xy_0_yy, g_xx_xy_0_yz, g_xx_xy_0_zz, g_xx_xy_yy_xx, g_xx_xy_yy_xy, g_xx_xy_yy_xz, g_xx_xy_yy_yy, g_xx_xy_yy_yz, g_xx_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xy_y_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_yy_xx[i] * c_exps[i] - 2.0 * g_xx_xy_0_xx[i] * a_exp + 4.0 * g_xx_xy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_y_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_yy_xy[i] * c_exps[i] - 2.0 * g_xx_xy_0_xy[i] * a_exp + 4.0 * g_xx_xy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_y_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_yy_xz[i] * c_exps[i] - 2.0 * g_xx_xy_0_xz[i] * a_exp + 4.0 * g_xx_xy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_y_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_yy_yy[i] * c_exps[i] - 2.0 * g_xx_xy_0_yy[i] * a_exp + 4.0 * g_xx_xy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_y_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_yy_yz[i] * c_exps[i] - 2.0 * g_xx_xy_0_yz[i] * a_exp + 4.0 * g_xx_xy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_y_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_yy_zz[i] * c_exps[i] - 2.0 * g_xx_xy_0_zz[i] * a_exp + 4.0 * g_xx_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (354-360)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_x_0_y_0_x_xy_z_xx, g_x_0_y_0_x_xy_z_xy, g_x_0_y_0_x_xy_z_xz, g_x_0_y_0_x_xy_z_yy, g_x_0_y_0_x_xy_z_yz, g_x_0_y_0_x_xy_z_zz, g_xx_xy_yz_xx, g_xx_xy_yz_xy, g_xx_xy_yz_xz, g_xx_xy_yz_yy, g_xx_xy_yz_yz, g_xx_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xy_z_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_z_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_z_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_z_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_z_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xy_z_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (360-366)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_x_0_y_0_x_xz_x_xx, g_x_0_y_0_x_xz_x_xy, g_x_0_y_0_x_xz_x_xz, g_x_0_y_0_x_xz_x_yy, g_x_0_y_0_x_xz_x_yz, g_x_0_y_0_x_xz_x_zz, g_xx_xz_xy_xx, g_xx_xz_xy_xy, g_xx_xz_xy_xz, g_xx_xz_xy_yy, g_xx_xz_xy_yz, g_xx_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xz_x_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_x_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_x_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_x_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_x_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_x_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (366-372)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_yy_xx, g_0_xz_yy_xy, g_0_xz_yy_xz, g_0_xz_yy_yy, g_0_xz_yy_yz, g_0_xz_yy_zz, g_x_0_y_0_x_xz_y_xx, g_x_0_y_0_x_xz_y_xy, g_x_0_y_0_x_xz_y_xz, g_x_0_y_0_x_xz_y_yy, g_x_0_y_0_x_xz_y_yz, g_x_0_y_0_x_xz_y_zz, g_xx_xz_0_xx, g_xx_xz_0_xy, g_xx_xz_0_xz, g_xx_xz_0_yy, g_xx_xz_0_yz, g_xx_xz_0_zz, g_xx_xz_yy_xx, g_xx_xz_yy_xy, g_xx_xz_yy_xz, g_xx_xz_yy_yy, g_xx_xz_yy_yz, g_xx_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xz_y_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_yy_xx[i] * c_exps[i] - 2.0 * g_xx_xz_0_xx[i] * a_exp + 4.0 * g_xx_xz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_y_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_yy_xy[i] * c_exps[i] - 2.0 * g_xx_xz_0_xy[i] * a_exp + 4.0 * g_xx_xz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_y_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_yy_xz[i] * c_exps[i] - 2.0 * g_xx_xz_0_xz[i] * a_exp + 4.0 * g_xx_xz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_y_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_yy_yy[i] * c_exps[i] - 2.0 * g_xx_xz_0_yy[i] * a_exp + 4.0 * g_xx_xz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_y_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_yy_yz[i] * c_exps[i] - 2.0 * g_xx_xz_0_yz[i] * a_exp + 4.0 * g_xx_xz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_y_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_yy_zz[i] * c_exps[i] - 2.0 * g_xx_xz_0_zz[i] * a_exp + 4.0 * g_xx_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (372-378)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_x_0_y_0_x_xz_z_xx, g_x_0_y_0_x_xz_z_xy, g_x_0_y_0_x_xz_z_xz, g_x_0_y_0_x_xz_z_yy, g_x_0_y_0_x_xz_z_yz, g_x_0_y_0_x_xz_z_zz, g_xx_xz_yz_xx, g_xx_xz_yz_xy, g_xx_xz_yz_xz, g_xx_xz_yz_yy, g_xx_xz_yz_yz, g_xx_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_xz_z_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_z_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_z_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_z_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_z_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_xz_z_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (378-384)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_x_0_y_0_x_yy_x_xx, g_x_0_y_0_x_yy_x_xy, g_x_0_y_0_x_yy_x_xz, g_x_0_y_0_x_yy_x_yy, g_x_0_y_0_x_yy_x_yz, g_x_0_y_0_x_yy_x_zz, g_xx_yy_xy_xx, g_xx_yy_xy_xy, g_xx_yy_xy_xz, g_xx_yy_xy_yy, g_xx_yy_xy_yz, g_xx_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yy_x_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_x_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_x_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_x_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_xx_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_x_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_x_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_xx_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (384-390)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_yy_xx, g_0_yy_yy_xy, g_0_yy_yy_xz, g_0_yy_yy_yy, g_0_yy_yy_yz, g_0_yy_yy_zz, g_x_0_y_0_x_yy_y_xx, g_x_0_y_0_x_yy_y_xy, g_x_0_y_0_x_yy_y_xz, g_x_0_y_0_x_yy_y_yy, g_x_0_y_0_x_yy_y_yz, g_x_0_y_0_x_yy_y_zz, g_xx_yy_0_xx, g_xx_yy_0_xy, g_xx_yy_0_xz, g_xx_yy_0_yy, g_xx_yy_0_yz, g_xx_yy_0_zz, g_xx_yy_yy_xx, g_xx_yy_yy_xy, g_xx_yy_yy_xz, g_xx_yy_yy_yy, g_xx_yy_yy_yz, g_xx_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yy_y_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_yy_xx[i] * c_exps[i] - 2.0 * g_xx_yy_0_xx[i] * a_exp + 4.0 * g_xx_yy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_y_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_yy_xy[i] * c_exps[i] - 2.0 * g_xx_yy_0_xy[i] * a_exp + 4.0 * g_xx_yy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_y_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_yy_xz[i] * c_exps[i] - 2.0 * g_xx_yy_0_xz[i] * a_exp + 4.0 * g_xx_yy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_y_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_yy_yy[i] * c_exps[i] - 2.0 * g_xx_yy_0_yy[i] * a_exp + 4.0 * g_xx_yy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_y_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_yy_yz[i] * c_exps[i] - 2.0 * g_xx_yy_0_yz[i] * a_exp + 4.0 * g_xx_yy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_y_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_yy_zz[i] * c_exps[i] - 2.0 * g_xx_yy_0_zz[i] * a_exp + 4.0 * g_xx_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (390-396)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_x_0_y_0_x_yy_z_xx, g_x_0_y_0_x_yy_z_xy, g_x_0_y_0_x_yy_z_xz, g_x_0_y_0_x_yy_z_yy, g_x_0_y_0_x_yy_z_yz, g_x_0_y_0_x_yy_z_zz, g_xx_yy_yz_xx, g_xx_yy_yz_xy, g_xx_yy_yz_xz, g_xx_yy_yz_yy, g_xx_yy_yz_yz, g_xx_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yy_z_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_z_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_z_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_z_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_xx_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_z_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yy_z_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (396-402)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_x_0_y_0_x_yz_x_xx, g_x_0_y_0_x_yz_x_xy, g_x_0_y_0_x_yz_x_xz, g_x_0_y_0_x_yz_x_yy, g_x_0_y_0_x_yz_x_yz, g_x_0_y_0_x_yz_x_zz, g_xx_yz_xy_xx, g_xx_yz_xy_xy, g_xx_yz_xy_xz, g_xx_yz_xy_yy, g_xx_yz_xy_yz, g_xx_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yz_x_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_x_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_x_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_x_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_x_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_x_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (402-408)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_yy_xx, g_0_yz_yy_xy, g_0_yz_yy_xz, g_0_yz_yy_yy, g_0_yz_yy_yz, g_0_yz_yy_zz, g_x_0_y_0_x_yz_y_xx, g_x_0_y_0_x_yz_y_xy, g_x_0_y_0_x_yz_y_xz, g_x_0_y_0_x_yz_y_yy, g_x_0_y_0_x_yz_y_yz, g_x_0_y_0_x_yz_y_zz, g_xx_yz_0_xx, g_xx_yz_0_xy, g_xx_yz_0_xz, g_xx_yz_0_yy, g_xx_yz_0_yz, g_xx_yz_0_zz, g_xx_yz_yy_xx, g_xx_yz_yy_xy, g_xx_yz_yy_xz, g_xx_yz_yy_yy, g_xx_yz_yy_yz, g_xx_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yz_y_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_yy_xx[i] * c_exps[i] - 2.0 * g_xx_yz_0_xx[i] * a_exp + 4.0 * g_xx_yz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_y_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_yy_xy[i] * c_exps[i] - 2.0 * g_xx_yz_0_xy[i] * a_exp + 4.0 * g_xx_yz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_y_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_yy_xz[i] * c_exps[i] - 2.0 * g_xx_yz_0_xz[i] * a_exp + 4.0 * g_xx_yz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_y_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_yy_yy[i] * c_exps[i] - 2.0 * g_xx_yz_0_yy[i] * a_exp + 4.0 * g_xx_yz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_y_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_yy_yz[i] * c_exps[i] - 2.0 * g_xx_yz_0_yz[i] * a_exp + 4.0 * g_xx_yz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_y_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_yy_zz[i] * c_exps[i] - 2.0 * g_xx_yz_0_zz[i] * a_exp + 4.0 * g_xx_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (408-414)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_x_0_y_0_x_yz_z_xx, g_x_0_y_0_x_yz_z_xy, g_x_0_y_0_x_yz_z_xz, g_x_0_y_0_x_yz_z_yy, g_x_0_y_0_x_yz_z_yz, g_x_0_y_0_x_yz_z_zz, g_xx_yz_yz_xx, g_xx_yz_yz_xy, g_xx_yz_yz_xz, g_xx_yz_yz_yy, g_xx_yz_yz_yz, g_xx_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_yz_z_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_z_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_z_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_z_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_z_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_yz_z_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (414-420)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_x_0_y_0_x_zz_x_xx, g_x_0_y_0_x_zz_x_xy, g_x_0_y_0_x_zz_x_xz, g_x_0_y_0_x_zz_x_yy, g_x_0_y_0_x_zz_x_yz, g_x_0_y_0_x_zz_x_zz, g_xx_zz_xy_xx, g_xx_zz_xy_xy, g_xx_zz_xy_xz, g_xx_zz_xy_yy, g_xx_zz_xy_yz, g_xx_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_zz_x_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_x_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_x_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_x_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_xx_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_x_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_x_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_xx_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (420-426)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_yy_xx, g_0_zz_yy_xy, g_0_zz_yy_xz, g_0_zz_yy_yy, g_0_zz_yy_yz, g_0_zz_yy_zz, g_x_0_y_0_x_zz_y_xx, g_x_0_y_0_x_zz_y_xy, g_x_0_y_0_x_zz_y_xz, g_x_0_y_0_x_zz_y_yy, g_x_0_y_0_x_zz_y_yz, g_x_0_y_0_x_zz_y_zz, g_xx_zz_0_xx, g_xx_zz_0_xy, g_xx_zz_0_xz, g_xx_zz_0_yy, g_xx_zz_0_yz, g_xx_zz_0_zz, g_xx_zz_yy_xx, g_xx_zz_yy_xy, g_xx_zz_yy_xz, g_xx_zz_yy_yy, g_xx_zz_yy_yz, g_xx_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_zz_y_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_yy_xx[i] * c_exps[i] - 2.0 * g_xx_zz_0_xx[i] * a_exp + 4.0 * g_xx_zz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_y_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_yy_xy[i] * c_exps[i] - 2.0 * g_xx_zz_0_xy[i] * a_exp + 4.0 * g_xx_zz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_y_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_yy_xz[i] * c_exps[i] - 2.0 * g_xx_zz_0_xz[i] * a_exp + 4.0 * g_xx_zz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_y_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_yy_yy[i] * c_exps[i] - 2.0 * g_xx_zz_0_yy[i] * a_exp + 4.0 * g_xx_zz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_y_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_yy_yz[i] * c_exps[i] - 2.0 * g_xx_zz_0_yz[i] * a_exp + 4.0 * g_xx_zz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_y_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_yy_zz[i] * c_exps[i] - 2.0 * g_xx_zz_0_zz[i] * a_exp + 4.0 * g_xx_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (426-432)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_x_0_y_0_x_zz_z_xx, g_x_0_y_0_x_zz_z_xy, g_x_0_y_0_x_zz_z_xz, g_x_0_y_0_x_zz_z_yy, g_x_0_y_0_x_zz_z_yz, g_x_0_y_0_x_zz_z_zz, g_xx_zz_yz_xx, g_xx_zz_yz_xy, g_xx_zz_yz_xz, g_xx_zz_yz_yy, g_xx_zz_yz_yz, g_xx_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_x_zz_z_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_z_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_z_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_z_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_z_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_x_zz_z_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (432-438)

    #pragma omp simd aligned(g_x_0_y_0_y_xx_x_xx, g_x_0_y_0_y_xx_x_xy, g_x_0_y_0_y_xx_x_xz, g_x_0_y_0_y_xx_x_yy, g_x_0_y_0_y_xx_x_yz, g_x_0_y_0_y_xx_x_zz, g_xy_xx_xy_xx, g_xy_xx_xy_xy, g_xy_xx_xy_xz, g_xy_xx_xy_yy, g_xy_xx_xy_yz, g_xy_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xx_x_xx[i] = 4.0 * g_xy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_x_xy[i] = 4.0 * g_xy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_x_xz[i] = 4.0 * g_xy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_x_yy[i] = 4.0 * g_xy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_x_yz[i] = 4.0 * g_xy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_x_zz[i] = 4.0 * g_xy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (438-444)

    #pragma omp simd aligned(g_x_0_y_0_y_xx_y_xx, g_x_0_y_0_y_xx_y_xy, g_x_0_y_0_y_xx_y_xz, g_x_0_y_0_y_xx_y_yy, g_x_0_y_0_y_xx_y_yz, g_x_0_y_0_y_xx_y_zz, g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_yy_xx, g_xy_xx_yy_xy, g_xy_xx_yy_xz, g_xy_xx_yy_yy, g_xy_xx_yy_yz, g_xy_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xx_y_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_y_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_y_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_y_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_y_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_y_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (444-450)

    #pragma omp simd aligned(g_x_0_y_0_y_xx_z_xx, g_x_0_y_0_y_xx_z_xy, g_x_0_y_0_y_xx_z_xz, g_x_0_y_0_y_xx_z_yy, g_x_0_y_0_y_xx_z_yz, g_x_0_y_0_y_xx_z_zz, g_xy_xx_yz_xx, g_xy_xx_yz_xy, g_xy_xx_yz_xz, g_xy_xx_yz_yy, g_xy_xx_yz_yz, g_xy_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xx_z_xx[i] = 4.0 * g_xy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_z_xy[i] = 4.0 * g_xy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_z_xz[i] = 4.0 * g_xy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_z_yy[i] = 4.0 * g_xy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_z_yz[i] = 4.0 * g_xy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xx_z_zz[i] = 4.0 * g_xy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (450-456)

    #pragma omp simd aligned(g_x_0_y_0_y_xy_x_xx, g_x_0_y_0_y_xy_x_xy, g_x_0_y_0_y_xy_x_xz, g_x_0_y_0_y_xy_x_yy, g_x_0_y_0_y_xy_x_yz, g_x_0_y_0_y_xy_x_zz, g_xy_xy_xy_xx, g_xy_xy_xy_xy, g_xy_xy_xy_xz, g_xy_xy_xy_yy, g_xy_xy_xy_yz, g_xy_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xy_x_xx[i] = 4.0 * g_xy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_x_xy[i] = 4.0 * g_xy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_x_xz[i] = 4.0 * g_xy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_x_yy[i] = 4.0 * g_xy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_x_yz[i] = 4.0 * g_xy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_x_zz[i] = 4.0 * g_xy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (456-462)

    #pragma omp simd aligned(g_x_0_y_0_y_xy_y_xx, g_x_0_y_0_y_xy_y_xy, g_x_0_y_0_y_xy_y_xz, g_x_0_y_0_y_xy_y_yy, g_x_0_y_0_y_xy_y_yz, g_x_0_y_0_y_xy_y_zz, g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_yy_xx, g_xy_xy_yy_xy, g_xy_xy_yy_xz, g_xy_xy_yy_yy, g_xy_xy_yy_yz, g_xy_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xy_y_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_y_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_y_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_y_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_y_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_y_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (462-468)

    #pragma omp simd aligned(g_x_0_y_0_y_xy_z_xx, g_x_0_y_0_y_xy_z_xy, g_x_0_y_0_y_xy_z_xz, g_x_0_y_0_y_xy_z_yy, g_x_0_y_0_y_xy_z_yz, g_x_0_y_0_y_xy_z_zz, g_xy_xy_yz_xx, g_xy_xy_yz_xy, g_xy_xy_yz_xz, g_xy_xy_yz_yy, g_xy_xy_yz_yz, g_xy_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xy_z_xx[i] = 4.0 * g_xy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_z_xy[i] = 4.0 * g_xy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_z_xz[i] = 4.0 * g_xy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_z_yy[i] = 4.0 * g_xy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_z_yz[i] = 4.0 * g_xy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xy_z_zz[i] = 4.0 * g_xy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (468-474)

    #pragma omp simd aligned(g_x_0_y_0_y_xz_x_xx, g_x_0_y_0_y_xz_x_xy, g_x_0_y_0_y_xz_x_xz, g_x_0_y_0_y_xz_x_yy, g_x_0_y_0_y_xz_x_yz, g_x_0_y_0_y_xz_x_zz, g_xy_xz_xy_xx, g_xy_xz_xy_xy, g_xy_xz_xy_xz, g_xy_xz_xy_yy, g_xy_xz_xy_yz, g_xy_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xz_x_xx[i] = 4.0 * g_xy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_x_xy[i] = 4.0 * g_xy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_x_xz[i] = 4.0 * g_xy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_x_yy[i] = 4.0 * g_xy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_x_yz[i] = 4.0 * g_xy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_x_zz[i] = 4.0 * g_xy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (474-480)

    #pragma omp simd aligned(g_x_0_y_0_y_xz_y_xx, g_x_0_y_0_y_xz_y_xy, g_x_0_y_0_y_xz_y_xz, g_x_0_y_0_y_xz_y_yy, g_x_0_y_0_y_xz_y_yz, g_x_0_y_0_y_xz_y_zz, g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_yy_xx, g_xy_xz_yy_xy, g_xy_xz_yy_xz, g_xy_xz_yy_yy, g_xy_xz_yy_yz, g_xy_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xz_y_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_y_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_y_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_y_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_y_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_y_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (480-486)

    #pragma omp simd aligned(g_x_0_y_0_y_xz_z_xx, g_x_0_y_0_y_xz_z_xy, g_x_0_y_0_y_xz_z_xz, g_x_0_y_0_y_xz_z_yy, g_x_0_y_0_y_xz_z_yz, g_x_0_y_0_y_xz_z_zz, g_xy_xz_yz_xx, g_xy_xz_yz_xy, g_xy_xz_yz_xz, g_xy_xz_yz_yy, g_xy_xz_yz_yz, g_xy_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_xz_z_xx[i] = 4.0 * g_xy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_z_xy[i] = 4.0 * g_xy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_z_xz[i] = 4.0 * g_xy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_z_yy[i] = 4.0 * g_xy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_z_yz[i] = 4.0 * g_xy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_xz_z_zz[i] = 4.0 * g_xy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (486-492)

    #pragma omp simd aligned(g_x_0_y_0_y_yy_x_xx, g_x_0_y_0_y_yy_x_xy, g_x_0_y_0_y_yy_x_xz, g_x_0_y_0_y_yy_x_yy, g_x_0_y_0_y_yy_x_yz, g_x_0_y_0_y_yy_x_zz, g_xy_yy_xy_xx, g_xy_yy_xy_xy, g_xy_yy_xy_xz, g_xy_yy_xy_yy, g_xy_yy_xy_yz, g_xy_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yy_x_xx[i] = 4.0 * g_xy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_x_xy[i] = 4.0 * g_xy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_x_xz[i] = 4.0 * g_xy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_x_yy[i] = 4.0 * g_xy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_x_yz[i] = 4.0 * g_xy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_x_zz[i] = 4.0 * g_xy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (492-498)

    #pragma omp simd aligned(g_x_0_y_0_y_yy_y_xx, g_x_0_y_0_y_yy_y_xy, g_x_0_y_0_y_yy_y_xz, g_x_0_y_0_y_yy_y_yy, g_x_0_y_0_y_yy_y_yz, g_x_0_y_0_y_yy_y_zz, g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_yy_xx, g_xy_yy_yy_xy, g_xy_yy_yy_xz, g_xy_yy_yy_yy, g_xy_yy_yy_yz, g_xy_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yy_y_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_y_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_y_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_y_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_y_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_y_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (498-504)

    #pragma omp simd aligned(g_x_0_y_0_y_yy_z_xx, g_x_0_y_0_y_yy_z_xy, g_x_0_y_0_y_yy_z_xz, g_x_0_y_0_y_yy_z_yy, g_x_0_y_0_y_yy_z_yz, g_x_0_y_0_y_yy_z_zz, g_xy_yy_yz_xx, g_xy_yy_yz_xy, g_xy_yy_yz_xz, g_xy_yy_yz_yy, g_xy_yy_yz_yz, g_xy_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yy_z_xx[i] = 4.0 * g_xy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_z_xy[i] = 4.0 * g_xy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_z_xz[i] = 4.0 * g_xy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_z_yy[i] = 4.0 * g_xy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_z_yz[i] = 4.0 * g_xy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yy_z_zz[i] = 4.0 * g_xy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (504-510)

    #pragma omp simd aligned(g_x_0_y_0_y_yz_x_xx, g_x_0_y_0_y_yz_x_xy, g_x_0_y_0_y_yz_x_xz, g_x_0_y_0_y_yz_x_yy, g_x_0_y_0_y_yz_x_yz, g_x_0_y_0_y_yz_x_zz, g_xy_yz_xy_xx, g_xy_yz_xy_xy, g_xy_yz_xy_xz, g_xy_yz_xy_yy, g_xy_yz_xy_yz, g_xy_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yz_x_xx[i] = 4.0 * g_xy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_x_xy[i] = 4.0 * g_xy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_x_xz[i] = 4.0 * g_xy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_x_yy[i] = 4.0 * g_xy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_x_yz[i] = 4.0 * g_xy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_x_zz[i] = 4.0 * g_xy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (510-516)

    #pragma omp simd aligned(g_x_0_y_0_y_yz_y_xx, g_x_0_y_0_y_yz_y_xy, g_x_0_y_0_y_yz_y_xz, g_x_0_y_0_y_yz_y_yy, g_x_0_y_0_y_yz_y_yz, g_x_0_y_0_y_yz_y_zz, g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_yy_xx, g_xy_yz_yy_xy, g_xy_yz_yy_xz, g_xy_yz_yy_yy, g_xy_yz_yy_yz, g_xy_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yz_y_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_y_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_y_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_y_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_y_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_y_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (516-522)

    #pragma omp simd aligned(g_x_0_y_0_y_yz_z_xx, g_x_0_y_0_y_yz_z_xy, g_x_0_y_0_y_yz_z_xz, g_x_0_y_0_y_yz_z_yy, g_x_0_y_0_y_yz_z_yz, g_x_0_y_0_y_yz_z_zz, g_xy_yz_yz_xx, g_xy_yz_yz_xy, g_xy_yz_yz_xz, g_xy_yz_yz_yy, g_xy_yz_yz_yz, g_xy_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_yz_z_xx[i] = 4.0 * g_xy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_z_xy[i] = 4.0 * g_xy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_z_xz[i] = 4.0 * g_xy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_z_yy[i] = 4.0 * g_xy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_z_yz[i] = 4.0 * g_xy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_yz_z_zz[i] = 4.0 * g_xy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (522-528)

    #pragma omp simd aligned(g_x_0_y_0_y_zz_x_xx, g_x_0_y_0_y_zz_x_xy, g_x_0_y_0_y_zz_x_xz, g_x_0_y_0_y_zz_x_yy, g_x_0_y_0_y_zz_x_yz, g_x_0_y_0_y_zz_x_zz, g_xy_zz_xy_xx, g_xy_zz_xy_xy, g_xy_zz_xy_xz, g_xy_zz_xy_yy, g_xy_zz_xy_yz, g_xy_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_zz_x_xx[i] = 4.0 * g_xy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_x_xy[i] = 4.0 * g_xy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_x_xz[i] = 4.0 * g_xy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_x_yy[i] = 4.0 * g_xy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_x_yz[i] = 4.0 * g_xy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_x_zz[i] = 4.0 * g_xy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (528-534)

    #pragma omp simd aligned(g_x_0_y_0_y_zz_y_xx, g_x_0_y_0_y_zz_y_xy, g_x_0_y_0_y_zz_y_xz, g_x_0_y_0_y_zz_y_yy, g_x_0_y_0_y_zz_y_yz, g_x_0_y_0_y_zz_y_zz, g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_yy_xx, g_xy_zz_yy_xy, g_xy_zz_yy_xz, g_xy_zz_yy_yy, g_xy_zz_yy_yz, g_xy_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_zz_y_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_y_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_y_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_y_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_y_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_y_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (534-540)

    #pragma omp simd aligned(g_x_0_y_0_y_zz_z_xx, g_x_0_y_0_y_zz_z_xy, g_x_0_y_0_y_zz_z_xz, g_x_0_y_0_y_zz_z_yy, g_x_0_y_0_y_zz_z_yz, g_x_0_y_0_y_zz_z_zz, g_xy_zz_yz_xx, g_xy_zz_yz_xy, g_xy_zz_yz_xz, g_xy_zz_yz_yy, g_xy_zz_yz_yz, g_xy_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_y_zz_z_xx[i] = 4.0 * g_xy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_z_xy[i] = 4.0 * g_xy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_z_xz[i] = 4.0 * g_xy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_z_yy[i] = 4.0 * g_xy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_z_yz[i] = 4.0 * g_xy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_y_zz_z_zz[i] = 4.0 * g_xy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (540-546)

    #pragma omp simd aligned(g_x_0_y_0_z_xx_x_xx, g_x_0_y_0_z_xx_x_xy, g_x_0_y_0_z_xx_x_xz, g_x_0_y_0_z_xx_x_yy, g_x_0_y_0_z_xx_x_yz, g_x_0_y_0_z_xx_x_zz, g_xz_xx_xy_xx, g_xz_xx_xy_xy, g_xz_xx_xy_xz, g_xz_xx_xy_yy, g_xz_xx_xy_yz, g_xz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xx_x_xx[i] = 4.0 * g_xz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_x_xy[i] = 4.0 * g_xz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_x_xz[i] = 4.0 * g_xz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_x_yy[i] = 4.0 * g_xz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_x_yz[i] = 4.0 * g_xz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_x_zz[i] = 4.0 * g_xz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (546-552)

    #pragma omp simd aligned(g_x_0_y_0_z_xx_y_xx, g_x_0_y_0_z_xx_y_xy, g_x_0_y_0_z_xx_y_xz, g_x_0_y_0_z_xx_y_yy, g_x_0_y_0_z_xx_y_yz, g_x_0_y_0_z_xx_y_zz, g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_yy_xx, g_xz_xx_yy_xy, g_xz_xx_yy_xz, g_xz_xx_yy_yy, g_xz_xx_yy_yz, g_xz_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xx_y_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_y_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_y_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_y_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_y_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_y_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (552-558)

    #pragma omp simd aligned(g_x_0_y_0_z_xx_z_xx, g_x_0_y_0_z_xx_z_xy, g_x_0_y_0_z_xx_z_xz, g_x_0_y_0_z_xx_z_yy, g_x_0_y_0_z_xx_z_yz, g_x_0_y_0_z_xx_z_zz, g_xz_xx_yz_xx, g_xz_xx_yz_xy, g_xz_xx_yz_xz, g_xz_xx_yz_yy, g_xz_xx_yz_yz, g_xz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xx_z_xx[i] = 4.0 * g_xz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_z_xy[i] = 4.0 * g_xz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_z_xz[i] = 4.0 * g_xz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_z_yy[i] = 4.0 * g_xz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_z_yz[i] = 4.0 * g_xz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xx_z_zz[i] = 4.0 * g_xz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (558-564)

    #pragma omp simd aligned(g_x_0_y_0_z_xy_x_xx, g_x_0_y_0_z_xy_x_xy, g_x_0_y_0_z_xy_x_xz, g_x_0_y_0_z_xy_x_yy, g_x_0_y_0_z_xy_x_yz, g_x_0_y_0_z_xy_x_zz, g_xz_xy_xy_xx, g_xz_xy_xy_xy, g_xz_xy_xy_xz, g_xz_xy_xy_yy, g_xz_xy_xy_yz, g_xz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xy_x_xx[i] = 4.0 * g_xz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_x_xy[i] = 4.0 * g_xz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_x_xz[i] = 4.0 * g_xz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_x_yy[i] = 4.0 * g_xz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_x_yz[i] = 4.0 * g_xz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_x_zz[i] = 4.0 * g_xz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (564-570)

    #pragma omp simd aligned(g_x_0_y_0_z_xy_y_xx, g_x_0_y_0_z_xy_y_xy, g_x_0_y_0_z_xy_y_xz, g_x_0_y_0_z_xy_y_yy, g_x_0_y_0_z_xy_y_yz, g_x_0_y_0_z_xy_y_zz, g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_yy_xx, g_xz_xy_yy_xy, g_xz_xy_yy_xz, g_xz_xy_yy_yy, g_xz_xy_yy_yz, g_xz_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xy_y_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_y_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_y_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_y_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_y_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_y_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (570-576)

    #pragma omp simd aligned(g_x_0_y_0_z_xy_z_xx, g_x_0_y_0_z_xy_z_xy, g_x_0_y_0_z_xy_z_xz, g_x_0_y_0_z_xy_z_yy, g_x_0_y_0_z_xy_z_yz, g_x_0_y_0_z_xy_z_zz, g_xz_xy_yz_xx, g_xz_xy_yz_xy, g_xz_xy_yz_xz, g_xz_xy_yz_yy, g_xz_xy_yz_yz, g_xz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xy_z_xx[i] = 4.0 * g_xz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_z_xy[i] = 4.0 * g_xz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_z_xz[i] = 4.0 * g_xz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_z_yy[i] = 4.0 * g_xz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_z_yz[i] = 4.0 * g_xz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xy_z_zz[i] = 4.0 * g_xz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (576-582)

    #pragma omp simd aligned(g_x_0_y_0_z_xz_x_xx, g_x_0_y_0_z_xz_x_xy, g_x_0_y_0_z_xz_x_xz, g_x_0_y_0_z_xz_x_yy, g_x_0_y_0_z_xz_x_yz, g_x_0_y_0_z_xz_x_zz, g_xz_xz_xy_xx, g_xz_xz_xy_xy, g_xz_xz_xy_xz, g_xz_xz_xy_yy, g_xz_xz_xy_yz, g_xz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xz_x_xx[i] = 4.0 * g_xz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_x_xy[i] = 4.0 * g_xz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_x_xz[i] = 4.0 * g_xz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_x_yy[i] = 4.0 * g_xz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_x_yz[i] = 4.0 * g_xz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_x_zz[i] = 4.0 * g_xz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (582-588)

    #pragma omp simd aligned(g_x_0_y_0_z_xz_y_xx, g_x_0_y_0_z_xz_y_xy, g_x_0_y_0_z_xz_y_xz, g_x_0_y_0_z_xz_y_yy, g_x_0_y_0_z_xz_y_yz, g_x_0_y_0_z_xz_y_zz, g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_yy_xx, g_xz_xz_yy_xy, g_xz_xz_yy_xz, g_xz_xz_yy_yy, g_xz_xz_yy_yz, g_xz_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xz_y_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_y_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_y_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_y_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_y_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_y_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (588-594)

    #pragma omp simd aligned(g_x_0_y_0_z_xz_z_xx, g_x_0_y_0_z_xz_z_xy, g_x_0_y_0_z_xz_z_xz, g_x_0_y_0_z_xz_z_yy, g_x_0_y_0_z_xz_z_yz, g_x_0_y_0_z_xz_z_zz, g_xz_xz_yz_xx, g_xz_xz_yz_xy, g_xz_xz_yz_xz, g_xz_xz_yz_yy, g_xz_xz_yz_yz, g_xz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_xz_z_xx[i] = 4.0 * g_xz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_z_xy[i] = 4.0 * g_xz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_z_xz[i] = 4.0 * g_xz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_z_yy[i] = 4.0 * g_xz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_z_yz[i] = 4.0 * g_xz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_xz_z_zz[i] = 4.0 * g_xz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (594-600)

    #pragma omp simd aligned(g_x_0_y_0_z_yy_x_xx, g_x_0_y_0_z_yy_x_xy, g_x_0_y_0_z_yy_x_xz, g_x_0_y_0_z_yy_x_yy, g_x_0_y_0_z_yy_x_yz, g_x_0_y_0_z_yy_x_zz, g_xz_yy_xy_xx, g_xz_yy_xy_xy, g_xz_yy_xy_xz, g_xz_yy_xy_yy, g_xz_yy_xy_yz, g_xz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yy_x_xx[i] = 4.0 * g_xz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_x_xy[i] = 4.0 * g_xz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_x_xz[i] = 4.0 * g_xz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_x_yy[i] = 4.0 * g_xz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_x_yz[i] = 4.0 * g_xz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_x_zz[i] = 4.0 * g_xz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (600-606)

    #pragma omp simd aligned(g_x_0_y_0_z_yy_y_xx, g_x_0_y_0_z_yy_y_xy, g_x_0_y_0_z_yy_y_xz, g_x_0_y_0_z_yy_y_yy, g_x_0_y_0_z_yy_y_yz, g_x_0_y_0_z_yy_y_zz, g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_yy_xx, g_xz_yy_yy_xy, g_xz_yy_yy_xz, g_xz_yy_yy_yy, g_xz_yy_yy_yz, g_xz_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yy_y_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_y_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_y_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_y_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_y_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_y_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (606-612)

    #pragma omp simd aligned(g_x_0_y_0_z_yy_z_xx, g_x_0_y_0_z_yy_z_xy, g_x_0_y_0_z_yy_z_xz, g_x_0_y_0_z_yy_z_yy, g_x_0_y_0_z_yy_z_yz, g_x_0_y_0_z_yy_z_zz, g_xz_yy_yz_xx, g_xz_yy_yz_xy, g_xz_yy_yz_xz, g_xz_yy_yz_yy, g_xz_yy_yz_yz, g_xz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yy_z_xx[i] = 4.0 * g_xz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_z_xy[i] = 4.0 * g_xz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_z_xz[i] = 4.0 * g_xz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_z_yy[i] = 4.0 * g_xz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_z_yz[i] = 4.0 * g_xz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yy_z_zz[i] = 4.0 * g_xz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (612-618)

    #pragma omp simd aligned(g_x_0_y_0_z_yz_x_xx, g_x_0_y_0_z_yz_x_xy, g_x_0_y_0_z_yz_x_xz, g_x_0_y_0_z_yz_x_yy, g_x_0_y_0_z_yz_x_yz, g_x_0_y_0_z_yz_x_zz, g_xz_yz_xy_xx, g_xz_yz_xy_xy, g_xz_yz_xy_xz, g_xz_yz_xy_yy, g_xz_yz_xy_yz, g_xz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yz_x_xx[i] = 4.0 * g_xz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_x_xy[i] = 4.0 * g_xz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_x_xz[i] = 4.0 * g_xz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_x_yy[i] = 4.0 * g_xz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_x_yz[i] = 4.0 * g_xz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_x_zz[i] = 4.0 * g_xz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (618-624)

    #pragma omp simd aligned(g_x_0_y_0_z_yz_y_xx, g_x_0_y_0_z_yz_y_xy, g_x_0_y_0_z_yz_y_xz, g_x_0_y_0_z_yz_y_yy, g_x_0_y_0_z_yz_y_yz, g_x_0_y_0_z_yz_y_zz, g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_yy_xx, g_xz_yz_yy_xy, g_xz_yz_yy_xz, g_xz_yz_yy_yy, g_xz_yz_yy_yz, g_xz_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yz_y_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_y_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_y_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_y_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_y_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_y_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (624-630)

    #pragma omp simd aligned(g_x_0_y_0_z_yz_z_xx, g_x_0_y_0_z_yz_z_xy, g_x_0_y_0_z_yz_z_xz, g_x_0_y_0_z_yz_z_yy, g_x_0_y_0_z_yz_z_yz, g_x_0_y_0_z_yz_z_zz, g_xz_yz_yz_xx, g_xz_yz_yz_xy, g_xz_yz_yz_xz, g_xz_yz_yz_yy, g_xz_yz_yz_yz, g_xz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_yz_z_xx[i] = 4.0 * g_xz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_z_xy[i] = 4.0 * g_xz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_z_xz[i] = 4.0 * g_xz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_z_yy[i] = 4.0 * g_xz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_z_yz[i] = 4.0 * g_xz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_yz_z_zz[i] = 4.0 * g_xz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (630-636)

    #pragma omp simd aligned(g_x_0_y_0_z_zz_x_xx, g_x_0_y_0_z_zz_x_xy, g_x_0_y_0_z_zz_x_xz, g_x_0_y_0_z_zz_x_yy, g_x_0_y_0_z_zz_x_yz, g_x_0_y_0_z_zz_x_zz, g_xz_zz_xy_xx, g_xz_zz_xy_xy, g_xz_zz_xy_xz, g_xz_zz_xy_yy, g_xz_zz_xy_yz, g_xz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_zz_x_xx[i] = 4.0 * g_xz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_x_xy[i] = 4.0 * g_xz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_x_xz[i] = 4.0 * g_xz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_x_yy[i] = 4.0 * g_xz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_x_yz[i] = 4.0 * g_xz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_x_zz[i] = 4.0 * g_xz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (636-642)

    #pragma omp simd aligned(g_x_0_y_0_z_zz_y_xx, g_x_0_y_0_z_zz_y_xy, g_x_0_y_0_z_zz_y_xz, g_x_0_y_0_z_zz_y_yy, g_x_0_y_0_z_zz_y_yz, g_x_0_y_0_z_zz_y_zz, g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_yy_xx, g_xz_zz_yy_xy, g_xz_zz_yy_xz, g_xz_zz_yy_yy, g_xz_zz_yy_yz, g_xz_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_zz_y_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_yy_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_y_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_yy_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_y_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_yy_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_y_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_yy_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_y_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_yy_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_y_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (642-648)

    #pragma omp simd aligned(g_x_0_y_0_z_zz_z_xx, g_x_0_y_0_z_zz_z_xy, g_x_0_y_0_z_zz_z_xz, g_x_0_y_0_z_zz_z_yy, g_x_0_y_0_z_zz_z_yz, g_x_0_y_0_z_zz_z_zz, g_xz_zz_yz_xx, g_xz_zz_yz_xy, g_xz_zz_yz_xz, g_xz_zz_yz_yy, g_xz_zz_yz_yz, g_xz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_y_0_z_zz_z_xx[i] = 4.0 * g_xz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_z_xy[i] = 4.0 * g_xz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_z_xz[i] = 4.0 * g_xz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_z_yy[i] = 4.0 * g_xz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_z_yz[i] = 4.0 * g_xz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_y_0_z_zz_z_zz[i] = 4.0 * g_xz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (648-654)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_x_0_z_0_x_xx_x_xx, g_x_0_z_0_x_xx_x_xy, g_x_0_z_0_x_xx_x_xz, g_x_0_z_0_x_xx_x_yy, g_x_0_z_0_x_xx_x_yz, g_x_0_z_0_x_xx_x_zz, g_xx_xx_xz_xx, g_xx_xx_xz_xy, g_xx_xx_xz_xz, g_xx_xx_xz_yy, g_xx_xx_xz_yz, g_xx_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xx_x_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_x_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_x_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_x_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_x_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_x_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (654-660)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_x_0_z_0_x_xx_y_xx, g_x_0_z_0_x_xx_y_xy, g_x_0_z_0_x_xx_y_xz, g_x_0_z_0_x_xx_y_yy, g_x_0_z_0_x_xx_y_yz, g_x_0_z_0_x_xx_y_zz, g_xx_xx_yz_xx, g_xx_xx_yz_xy, g_xx_xx_yz_xz, g_xx_xx_yz_yy, g_xx_xx_yz_yz, g_xx_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xx_y_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_y_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_y_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_y_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_y_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_y_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (660-666)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_zz_xx, g_0_xx_zz_xy, g_0_xx_zz_xz, g_0_xx_zz_yy, g_0_xx_zz_yz, g_0_xx_zz_zz, g_x_0_z_0_x_xx_z_xx, g_x_0_z_0_x_xx_z_xy, g_x_0_z_0_x_xx_z_xz, g_x_0_z_0_x_xx_z_yy, g_x_0_z_0_x_xx_z_yz, g_x_0_z_0_x_xx_z_zz, g_xx_xx_0_xx, g_xx_xx_0_xy, g_xx_xx_0_xz, g_xx_xx_0_yy, g_xx_xx_0_yz, g_xx_xx_0_zz, g_xx_xx_zz_xx, g_xx_xx_zz_xy, g_xx_xx_zz_xz, g_xx_xx_zz_yy, g_xx_xx_zz_yz, g_xx_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xx_z_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_zz_xx[i] * c_exps[i] - 2.0 * g_xx_xx_0_xx[i] * a_exp + 4.0 * g_xx_xx_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_z_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_zz_xy[i] * c_exps[i] - 2.0 * g_xx_xx_0_xy[i] * a_exp + 4.0 * g_xx_xx_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_z_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_zz_xz[i] * c_exps[i] - 2.0 * g_xx_xx_0_xz[i] * a_exp + 4.0 * g_xx_xx_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_z_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_zz_yy[i] * c_exps[i] - 2.0 * g_xx_xx_0_yy[i] * a_exp + 4.0 * g_xx_xx_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_z_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_zz_yz[i] * c_exps[i] - 2.0 * g_xx_xx_0_yz[i] * a_exp + 4.0 * g_xx_xx_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xx_z_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_zz_zz[i] * c_exps[i] - 2.0 * g_xx_xx_0_zz[i] * a_exp + 4.0 * g_xx_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (666-672)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_x_0_z_0_x_xy_x_xx, g_x_0_z_0_x_xy_x_xy, g_x_0_z_0_x_xy_x_xz, g_x_0_z_0_x_xy_x_yy, g_x_0_z_0_x_xy_x_yz, g_x_0_z_0_x_xy_x_zz, g_xx_xy_xz_xx, g_xx_xy_xz_xy, g_xx_xy_xz_xz, g_xx_xy_xz_yy, g_xx_xy_xz_yz, g_xx_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xy_x_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_x_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_x_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_x_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_x_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_x_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (672-678)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_x_0_z_0_x_xy_y_xx, g_x_0_z_0_x_xy_y_xy, g_x_0_z_0_x_xy_y_xz, g_x_0_z_0_x_xy_y_yy, g_x_0_z_0_x_xy_y_yz, g_x_0_z_0_x_xy_y_zz, g_xx_xy_yz_xx, g_xx_xy_yz_xy, g_xx_xy_yz_xz, g_xx_xy_yz_yy, g_xx_xy_yz_yz, g_xx_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xy_y_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_y_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_y_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_y_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_y_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_y_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (678-684)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_zz_xx, g_0_xy_zz_xy, g_0_xy_zz_xz, g_0_xy_zz_yy, g_0_xy_zz_yz, g_0_xy_zz_zz, g_x_0_z_0_x_xy_z_xx, g_x_0_z_0_x_xy_z_xy, g_x_0_z_0_x_xy_z_xz, g_x_0_z_0_x_xy_z_yy, g_x_0_z_0_x_xy_z_yz, g_x_0_z_0_x_xy_z_zz, g_xx_xy_0_xx, g_xx_xy_0_xy, g_xx_xy_0_xz, g_xx_xy_0_yy, g_xx_xy_0_yz, g_xx_xy_0_zz, g_xx_xy_zz_xx, g_xx_xy_zz_xy, g_xx_xy_zz_xz, g_xx_xy_zz_yy, g_xx_xy_zz_yz, g_xx_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xy_z_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_zz_xx[i] * c_exps[i] - 2.0 * g_xx_xy_0_xx[i] * a_exp + 4.0 * g_xx_xy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_z_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_zz_xy[i] * c_exps[i] - 2.0 * g_xx_xy_0_xy[i] * a_exp + 4.0 * g_xx_xy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_z_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_zz_xz[i] * c_exps[i] - 2.0 * g_xx_xy_0_xz[i] * a_exp + 4.0 * g_xx_xy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_z_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_zz_yy[i] * c_exps[i] - 2.0 * g_xx_xy_0_yy[i] * a_exp + 4.0 * g_xx_xy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_z_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_zz_yz[i] * c_exps[i] - 2.0 * g_xx_xy_0_yz[i] * a_exp + 4.0 * g_xx_xy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xy_z_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_zz_zz[i] * c_exps[i] - 2.0 * g_xx_xy_0_zz[i] * a_exp + 4.0 * g_xx_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (684-690)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_x_0_z_0_x_xz_x_xx, g_x_0_z_0_x_xz_x_xy, g_x_0_z_0_x_xz_x_xz, g_x_0_z_0_x_xz_x_yy, g_x_0_z_0_x_xz_x_yz, g_x_0_z_0_x_xz_x_zz, g_xx_xz_xz_xx, g_xx_xz_xz_xy, g_xx_xz_xz_xz, g_xx_xz_xz_yy, g_xx_xz_xz_yz, g_xx_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xz_x_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_x_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_x_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_x_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_x_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_x_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (690-696)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_x_0_z_0_x_xz_y_xx, g_x_0_z_0_x_xz_y_xy, g_x_0_z_0_x_xz_y_xz, g_x_0_z_0_x_xz_y_yy, g_x_0_z_0_x_xz_y_yz, g_x_0_z_0_x_xz_y_zz, g_xx_xz_yz_xx, g_xx_xz_yz_xy, g_xx_xz_yz_xz, g_xx_xz_yz_yy, g_xx_xz_yz_yz, g_xx_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xz_y_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_y_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_y_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_y_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_y_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_y_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (696-702)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_zz_xx, g_0_xz_zz_xy, g_0_xz_zz_xz, g_0_xz_zz_yy, g_0_xz_zz_yz, g_0_xz_zz_zz, g_x_0_z_0_x_xz_z_xx, g_x_0_z_0_x_xz_z_xy, g_x_0_z_0_x_xz_z_xz, g_x_0_z_0_x_xz_z_yy, g_x_0_z_0_x_xz_z_yz, g_x_0_z_0_x_xz_z_zz, g_xx_xz_0_xx, g_xx_xz_0_xy, g_xx_xz_0_xz, g_xx_xz_0_yy, g_xx_xz_0_yz, g_xx_xz_0_zz, g_xx_xz_zz_xx, g_xx_xz_zz_xy, g_xx_xz_zz_xz, g_xx_xz_zz_yy, g_xx_xz_zz_yz, g_xx_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_xz_z_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_zz_xx[i] * c_exps[i] - 2.0 * g_xx_xz_0_xx[i] * a_exp + 4.0 * g_xx_xz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_z_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_zz_xy[i] * c_exps[i] - 2.0 * g_xx_xz_0_xy[i] * a_exp + 4.0 * g_xx_xz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_z_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_zz_xz[i] * c_exps[i] - 2.0 * g_xx_xz_0_xz[i] * a_exp + 4.0 * g_xx_xz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_z_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_zz_yy[i] * c_exps[i] - 2.0 * g_xx_xz_0_yy[i] * a_exp + 4.0 * g_xx_xz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_z_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_zz_yz[i] * c_exps[i] - 2.0 * g_xx_xz_0_yz[i] * a_exp + 4.0 * g_xx_xz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_xz_z_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_zz_zz[i] * c_exps[i] - 2.0 * g_xx_xz_0_zz[i] * a_exp + 4.0 * g_xx_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (702-708)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_x_0_z_0_x_yy_x_xx, g_x_0_z_0_x_yy_x_xy, g_x_0_z_0_x_yy_x_xz, g_x_0_z_0_x_yy_x_yy, g_x_0_z_0_x_yy_x_yz, g_x_0_z_0_x_yy_x_zz, g_xx_yy_xz_xx, g_xx_yy_xz_xy, g_xx_yy_xz_xz, g_xx_yy_xz_yy, g_xx_yy_xz_yz, g_xx_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yy_x_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_x_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_x_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_x_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_xx_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_x_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_x_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_xx_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (708-714)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_x_0_z_0_x_yy_y_xx, g_x_0_z_0_x_yy_y_xy, g_x_0_z_0_x_yy_y_xz, g_x_0_z_0_x_yy_y_yy, g_x_0_z_0_x_yy_y_yz, g_x_0_z_0_x_yy_y_zz, g_xx_yy_yz_xx, g_xx_yy_yz_xy, g_xx_yy_yz_xz, g_xx_yy_yz_yy, g_xx_yy_yz_yz, g_xx_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yy_y_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_y_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_y_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_y_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_xx_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_y_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_y_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_xx_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (714-720)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_zz_xx, g_0_yy_zz_xy, g_0_yy_zz_xz, g_0_yy_zz_yy, g_0_yy_zz_yz, g_0_yy_zz_zz, g_x_0_z_0_x_yy_z_xx, g_x_0_z_0_x_yy_z_xy, g_x_0_z_0_x_yy_z_xz, g_x_0_z_0_x_yy_z_yy, g_x_0_z_0_x_yy_z_yz, g_x_0_z_0_x_yy_z_zz, g_xx_yy_0_xx, g_xx_yy_0_xy, g_xx_yy_0_xz, g_xx_yy_0_yy, g_xx_yy_0_yz, g_xx_yy_0_zz, g_xx_yy_zz_xx, g_xx_yy_zz_xy, g_xx_yy_zz_xz, g_xx_yy_zz_yy, g_xx_yy_zz_yz, g_xx_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yy_z_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_zz_xx[i] * c_exps[i] - 2.0 * g_xx_yy_0_xx[i] * a_exp + 4.0 * g_xx_yy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_z_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_zz_xy[i] * c_exps[i] - 2.0 * g_xx_yy_0_xy[i] * a_exp + 4.0 * g_xx_yy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_z_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_zz_xz[i] * c_exps[i] - 2.0 * g_xx_yy_0_xz[i] * a_exp + 4.0 * g_xx_yy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_z_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_zz_yy[i] * c_exps[i] - 2.0 * g_xx_yy_0_yy[i] * a_exp + 4.0 * g_xx_yy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_z_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_zz_yz[i] * c_exps[i] - 2.0 * g_xx_yy_0_yz[i] * a_exp + 4.0 * g_xx_yy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yy_z_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_zz_zz[i] * c_exps[i] - 2.0 * g_xx_yy_0_zz[i] * a_exp + 4.0 * g_xx_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (720-726)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_x_0_z_0_x_yz_x_xx, g_x_0_z_0_x_yz_x_xy, g_x_0_z_0_x_yz_x_xz, g_x_0_z_0_x_yz_x_yy, g_x_0_z_0_x_yz_x_yz, g_x_0_z_0_x_yz_x_zz, g_xx_yz_xz_xx, g_xx_yz_xz_xy, g_xx_yz_xz_xz, g_xx_yz_xz_yy, g_xx_yz_xz_yz, g_xx_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yz_x_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_x_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_x_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_x_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_x_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_x_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (726-732)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_x_0_z_0_x_yz_y_xx, g_x_0_z_0_x_yz_y_xy, g_x_0_z_0_x_yz_y_xz, g_x_0_z_0_x_yz_y_yy, g_x_0_z_0_x_yz_y_yz, g_x_0_z_0_x_yz_y_zz, g_xx_yz_yz_xx, g_xx_yz_yz_xy, g_xx_yz_yz_xz, g_xx_yz_yz_yy, g_xx_yz_yz_yz, g_xx_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yz_y_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_y_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_y_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_y_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_y_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_y_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (732-738)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_zz_xx, g_0_yz_zz_xy, g_0_yz_zz_xz, g_0_yz_zz_yy, g_0_yz_zz_yz, g_0_yz_zz_zz, g_x_0_z_0_x_yz_z_xx, g_x_0_z_0_x_yz_z_xy, g_x_0_z_0_x_yz_z_xz, g_x_0_z_0_x_yz_z_yy, g_x_0_z_0_x_yz_z_yz, g_x_0_z_0_x_yz_z_zz, g_xx_yz_0_xx, g_xx_yz_0_xy, g_xx_yz_0_xz, g_xx_yz_0_yy, g_xx_yz_0_yz, g_xx_yz_0_zz, g_xx_yz_zz_xx, g_xx_yz_zz_xy, g_xx_yz_zz_xz, g_xx_yz_zz_yy, g_xx_yz_zz_yz, g_xx_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_yz_z_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_zz_xx[i] * c_exps[i] - 2.0 * g_xx_yz_0_xx[i] * a_exp + 4.0 * g_xx_yz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_z_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_zz_xy[i] * c_exps[i] - 2.0 * g_xx_yz_0_xy[i] * a_exp + 4.0 * g_xx_yz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_z_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_zz_xz[i] * c_exps[i] - 2.0 * g_xx_yz_0_xz[i] * a_exp + 4.0 * g_xx_yz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_z_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_zz_yy[i] * c_exps[i] - 2.0 * g_xx_yz_0_yy[i] * a_exp + 4.0 * g_xx_yz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_z_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_zz_yz[i] * c_exps[i] - 2.0 * g_xx_yz_0_yz[i] * a_exp + 4.0 * g_xx_yz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_yz_z_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_zz_zz[i] * c_exps[i] - 2.0 * g_xx_yz_0_zz[i] * a_exp + 4.0 * g_xx_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (738-744)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_x_0_z_0_x_zz_x_xx, g_x_0_z_0_x_zz_x_xy, g_x_0_z_0_x_zz_x_xz, g_x_0_z_0_x_zz_x_yy, g_x_0_z_0_x_zz_x_yz, g_x_0_z_0_x_zz_x_zz, g_xx_zz_xz_xx, g_xx_zz_xz_xy, g_xx_zz_xz_xz, g_xx_zz_xz_yy, g_xx_zz_xz_yz, g_xx_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_zz_x_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_x_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_x_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_x_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_xx_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_x_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_x_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_xx_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (744-750)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_x_0_z_0_x_zz_y_xx, g_x_0_z_0_x_zz_y_xy, g_x_0_z_0_x_zz_y_xz, g_x_0_z_0_x_zz_y_yy, g_x_0_z_0_x_zz_y_yz, g_x_0_z_0_x_zz_y_zz, g_xx_zz_yz_xx, g_xx_zz_yz_xy, g_xx_zz_yz_xz, g_xx_zz_yz_yy, g_xx_zz_yz_yz, g_xx_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_zz_y_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_y_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_y_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_y_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_xx_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_y_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_y_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_xx_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (750-756)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_zz_xx, g_0_zz_zz_xy, g_0_zz_zz_xz, g_0_zz_zz_yy, g_0_zz_zz_yz, g_0_zz_zz_zz, g_x_0_z_0_x_zz_z_xx, g_x_0_z_0_x_zz_z_xy, g_x_0_z_0_x_zz_z_xz, g_x_0_z_0_x_zz_z_yy, g_x_0_z_0_x_zz_z_yz, g_x_0_z_0_x_zz_z_zz, g_xx_zz_0_xx, g_xx_zz_0_xy, g_xx_zz_0_xz, g_xx_zz_0_yy, g_xx_zz_0_yz, g_xx_zz_0_zz, g_xx_zz_zz_xx, g_xx_zz_zz_xy, g_xx_zz_zz_xz, g_xx_zz_zz_yy, g_xx_zz_zz_yz, g_xx_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_x_zz_z_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_zz_xx[i] * c_exps[i] - 2.0 * g_xx_zz_0_xx[i] * a_exp + 4.0 * g_xx_zz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_z_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_zz_xy[i] * c_exps[i] - 2.0 * g_xx_zz_0_xy[i] * a_exp + 4.0 * g_xx_zz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_z_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_zz_xz[i] * c_exps[i] - 2.0 * g_xx_zz_0_xz[i] * a_exp + 4.0 * g_xx_zz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_z_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_zz_yy[i] * c_exps[i] - 2.0 * g_xx_zz_0_yy[i] * a_exp + 4.0 * g_xx_zz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_z_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_zz_yz[i] * c_exps[i] - 2.0 * g_xx_zz_0_yz[i] * a_exp + 4.0 * g_xx_zz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_x_zz_z_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_zz_zz[i] * c_exps[i] - 2.0 * g_xx_zz_0_zz[i] * a_exp + 4.0 * g_xx_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (756-762)

    #pragma omp simd aligned(g_x_0_z_0_y_xx_x_xx, g_x_0_z_0_y_xx_x_xy, g_x_0_z_0_y_xx_x_xz, g_x_0_z_0_y_xx_x_yy, g_x_0_z_0_y_xx_x_yz, g_x_0_z_0_y_xx_x_zz, g_xy_xx_xz_xx, g_xy_xx_xz_xy, g_xy_xx_xz_xz, g_xy_xx_xz_yy, g_xy_xx_xz_yz, g_xy_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xx_x_xx[i] = 4.0 * g_xy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_x_xy[i] = 4.0 * g_xy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_x_xz[i] = 4.0 * g_xy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_x_yy[i] = 4.0 * g_xy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_x_yz[i] = 4.0 * g_xy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_x_zz[i] = 4.0 * g_xy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (762-768)

    #pragma omp simd aligned(g_x_0_z_0_y_xx_y_xx, g_x_0_z_0_y_xx_y_xy, g_x_0_z_0_y_xx_y_xz, g_x_0_z_0_y_xx_y_yy, g_x_0_z_0_y_xx_y_yz, g_x_0_z_0_y_xx_y_zz, g_xy_xx_yz_xx, g_xy_xx_yz_xy, g_xy_xx_yz_xz, g_xy_xx_yz_yy, g_xy_xx_yz_yz, g_xy_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xx_y_xx[i] = 4.0 * g_xy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_y_xy[i] = 4.0 * g_xy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_y_xz[i] = 4.0 * g_xy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_y_yy[i] = 4.0 * g_xy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_y_yz[i] = 4.0 * g_xy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_y_zz[i] = 4.0 * g_xy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (768-774)

    #pragma omp simd aligned(g_x_0_z_0_y_xx_z_xx, g_x_0_z_0_y_xx_z_xy, g_x_0_z_0_y_xx_z_xz, g_x_0_z_0_y_xx_z_yy, g_x_0_z_0_y_xx_z_yz, g_x_0_z_0_y_xx_z_zz, g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_zz_xx, g_xy_xx_zz_xy, g_xy_xx_zz_xz, g_xy_xx_zz_yy, g_xy_xx_zz_yz, g_xy_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xx_z_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_z_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_z_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_z_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_z_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xx_z_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (774-780)

    #pragma omp simd aligned(g_x_0_z_0_y_xy_x_xx, g_x_0_z_0_y_xy_x_xy, g_x_0_z_0_y_xy_x_xz, g_x_0_z_0_y_xy_x_yy, g_x_0_z_0_y_xy_x_yz, g_x_0_z_0_y_xy_x_zz, g_xy_xy_xz_xx, g_xy_xy_xz_xy, g_xy_xy_xz_xz, g_xy_xy_xz_yy, g_xy_xy_xz_yz, g_xy_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xy_x_xx[i] = 4.0 * g_xy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_x_xy[i] = 4.0 * g_xy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_x_xz[i] = 4.0 * g_xy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_x_yy[i] = 4.0 * g_xy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_x_yz[i] = 4.0 * g_xy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_x_zz[i] = 4.0 * g_xy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (780-786)

    #pragma omp simd aligned(g_x_0_z_0_y_xy_y_xx, g_x_0_z_0_y_xy_y_xy, g_x_0_z_0_y_xy_y_xz, g_x_0_z_0_y_xy_y_yy, g_x_0_z_0_y_xy_y_yz, g_x_0_z_0_y_xy_y_zz, g_xy_xy_yz_xx, g_xy_xy_yz_xy, g_xy_xy_yz_xz, g_xy_xy_yz_yy, g_xy_xy_yz_yz, g_xy_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xy_y_xx[i] = 4.0 * g_xy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_y_xy[i] = 4.0 * g_xy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_y_xz[i] = 4.0 * g_xy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_y_yy[i] = 4.0 * g_xy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_y_yz[i] = 4.0 * g_xy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_y_zz[i] = 4.0 * g_xy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (786-792)

    #pragma omp simd aligned(g_x_0_z_0_y_xy_z_xx, g_x_0_z_0_y_xy_z_xy, g_x_0_z_0_y_xy_z_xz, g_x_0_z_0_y_xy_z_yy, g_x_0_z_0_y_xy_z_yz, g_x_0_z_0_y_xy_z_zz, g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_zz_xx, g_xy_xy_zz_xy, g_xy_xy_zz_xz, g_xy_xy_zz_yy, g_xy_xy_zz_yz, g_xy_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xy_z_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_z_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_z_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_z_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_z_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xy_z_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (792-798)

    #pragma omp simd aligned(g_x_0_z_0_y_xz_x_xx, g_x_0_z_0_y_xz_x_xy, g_x_0_z_0_y_xz_x_xz, g_x_0_z_0_y_xz_x_yy, g_x_0_z_0_y_xz_x_yz, g_x_0_z_0_y_xz_x_zz, g_xy_xz_xz_xx, g_xy_xz_xz_xy, g_xy_xz_xz_xz, g_xy_xz_xz_yy, g_xy_xz_xz_yz, g_xy_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xz_x_xx[i] = 4.0 * g_xy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_x_xy[i] = 4.0 * g_xy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_x_xz[i] = 4.0 * g_xy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_x_yy[i] = 4.0 * g_xy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_x_yz[i] = 4.0 * g_xy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_x_zz[i] = 4.0 * g_xy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (798-804)

    #pragma omp simd aligned(g_x_0_z_0_y_xz_y_xx, g_x_0_z_0_y_xz_y_xy, g_x_0_z_0_y_xz_y_xz, g_x_0_z_0_y_xz_y_yy, g_x_0_z_0_y_xz_y_yz, g_x_0_z_0_y_xz_y_zz, g_xy_xz_yz_xx, g_xy_xz_yz_xy, g_xy_xz_yz_xz, g_xy_xz_yz_yy, g_xy_xz_yz_yz, g_xy_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xz_y_xx[i] = 4.0 * g_xy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_y_xy[i] = 4.0 * g_xy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_y_xz[i] = 4.0 * g_xy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_y_yy[i] = 4.0 * g_xy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_y_yz[i] = 4.0 * g_xy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_y_zz[i] = 4.0 * g_xy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (804-810)

    #pragma omp simd aligned(g_x_0_z_0_y_xz_z_xx, g_x_0_z_0_y_xz_z_xy, g_x_0_z_0_y_xz_z_xz, g_x_0_z_0_y_xz_z_yy, g_x_0_z_0_y_xz_z_yz, g_x_0_z_0_y_xz_z_zz, g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_zz_xx, g_xy_xz_zz_xy, g_xy_xz_zz_xz, g_xy_xz_zz_yy, g_xy_xz_zz_yz, g_xy_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_xz_z_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_z_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_z_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_z_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_z_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_xz_z_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (810-816)

    #pragma omp simd aligned(g_x_0_z_0_y_yy_x_xx, g_x_0_z_0_y_yy_x_xy, g_x_0_z_0_y_yy_x_xz, g_x_0_z_0_y_yy_x_yy, g_x_0_z_0_y_yy_x_yz, g_x_0_z_0_y_yy_x_zz, g_xy_yy_xz_xx, g_xy_yy_xz_xy, g_xy_yy_xz_xz, g_xy_yy_xz_yy, g_xy_yy_xz_yz, g_xy_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yy_x_xx[i] = 4.0 * g_xy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_x_xy[i] = 4.0 * g_xy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_x_xz[i] = 4.0 * g_xy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_x_yy[i] = 4.0 * g_xy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_x_yz[i] = 4.0 * g_xy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_x_zz[i] = 4.0 * g_xy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (816-822)

    #pragma omp simd aligned(g_x_0_z_0_y_yy_y_xx, g_x_0_z_0_y_yy_y_xy, g_x_0_z_0_y_yy_y_xz, g_x_0_z_0_y_yy_y_yy, g_x_0_z_0_y_yy_y_yz, g_x_0_z_0_y_yy_y_zz, g_xy_yy_yz_xx, g_xy_yy_yz_xy, g_xy_yy_yz_xz, g_xy_yy_yz_yy, g_xy_yy_yz_yz, g_xy_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yy_y_xx[i] = 4.0 * g_xy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_y_xy[i] = 4.0 * g_xy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_y_xz[i] = 4.0 * g_xy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_y_yy[i] = 4.0 * g_xy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_y_yz[i] = 4.0 * g_xy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_y_zz[i] = 4.0 * g_xy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (822-828)

    #pragma omp simd aligned(g_x_0_z_0_y_yy_z_xx, g_x_0_z_0_y_yy_z_xy, g_x_0_z_0_y_yy_z_xz, g_x_0_z_0_y_yy_z_yy, g_x_0_z_0_y_yy_z_yz, g_x_0_z_0_y_yy_z_zz, g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_zz_xx, g_xy_yy_zz_xy, g_xy_yy_zz_xz, g_xy_yy_zz_yy, g_xy_yy_zz_yz, g_xy_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yy_z_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_z_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_z_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_z_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_z_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yy_z_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (828-834)

    #pragma omp simd aligned(g_x_0_z_0_y_yz_x_xx, g_x_0_z_0_y_yz_x_xy, g_x_0_z_0_y_yz_x_xz, g_x_0_z_0_y_yz_x_yy, g_x_0_z_0_y_yz_x_yz, g_x_0_z_0_y_yz_x_zz, g_xy_yz_xz_xx, g_xy_yz_xz_xy, g_xy_yz_xz_xz, g_xy_yz_xz_yy, g_xy_yz_xz_yz, g_xy_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yz_x_xx[i] = 4.0 * g_xy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_x_xy[i] = 4.0 * g_xy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_x_xz[i] = 4.0 * g_xy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_x_yy[i] = 4.0 * g_xy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_x_yz[i] = 4.0 * g_xy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_x_zz[i] = 4.0 * g_xy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (834-840)

    #pragma omp simd aligned(g_x_0_z_0_y_yz_y_xx, g_x_0_z_0_y_yz_y_xy, g_x_0_z_0_y_yz_y_xz, g_x_0_z_0_y_yz_y_yy, g_x_0_z_0_y_yz_y_yz, g_x_0_z_0_y_yz_y_zz, g_xy_yz_yz_xx, g_xy_yz_yz_xy, g_xy_yz_yz_xz, g_xy_yz_yz_yy, g_xy_yz_yz_yz, g_xy_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yz_y_xx[i] = 4.0 * g_xy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_y_xy[i] = 4.0 * g_xy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_y_xz[i] = 4.0 * g_xy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_y_yy[i] = 4.0 * g_xy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_y_yz[i] = 4.0 * g_xy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_y_zz[i] = 4.0 * g_xy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (840-846)

    #pragma omp simd aligned(g_x_0_z_0_y_yz_z_xx, g_x_0_z_0_y_yz_z_xy, g_x_0_z_0_y_yz_z_xz, g_x_0_z_0_y_yz_z_yy, g_x_0_z_0_y_yz_z_yz, g_x_0_z_0_y_yz_z_zz, g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_zz_xx, g_xy_yz_zz_xy, g_xy_yz_zz_xz, g_xy_yz_zz_yy, g_xy_yz_zz_yz, g_xy_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_yz_z_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_z_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_z_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_z_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_z_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_yz_z_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (846-852)

    #pragma omp simd aligned(g_x_0_z_0_y_zz_x_xx, g_x_0_z_0_y_zz_x_xy, g_x_0_z_0_y_zz_x_xz, g_x_0_z_0_y_zz_x_yy, g_x_0_z_0_y_zz_x_yz, g_x_0_z_0_y_zz_x_zz, g_xy_zz_xz_xx, g_xy_zz_xz_xy, g_xy_zz_xz_xz, g_xy_zz_xz_yy, g_xy_zz_xz_yz, g_xy_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_zz_x_xx[i] = 4.0 * g_xy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_x_xy[i] = 4.0 * g_xy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_x_xz[i] = 4.0 * g_xy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_x_yy[i] = 4.0 * g_xy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_x_yz[i] = 4.0 * g_xy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_x_zz[i] = 4.0 * g_xy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (852-858)

    #pragma omp simd aligned(g_x_0_z_0_y_zz_y_xx, g_x_0_z_0_y_zz_y_xy, g_x_0_z_0_y_zz_y_xz, g_x_0_z_0_y_zz_y_yy, g_x_0_z_0_y_zz_y_yz, g_x_0_z_0_y_zz_y_zz, g_xy_zz_yz_xx, g_xy_zz_yz_xy, g_xy_zz_yz_xz, g_xy_zz_yz_yy, g_xy_zz_yz_yz, g_xy_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_zz_y_xx[i] = 4.0 * g_xy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_y_xy[i] = 4.0 * g_xy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_y_xz[i] = 4.0 * g_xy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_y_yy[i] = 4.0 * g_xy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_y_yz[i] = 4.0 * g_xy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_y_zz[i] = 4.0 * g_xy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (858-864)

    #pragma omp simd aligned(g_x_0_z_0_y_zz_z_xx, g_x_0_z_0_y_zz_z_xy, g_x_0_z_0_y_zz_z_xz, g_x_0_z_0_y_zz_z_yy, g_x_0_z_0_y_zz_z_yz, g_x_0_z_0_y_zz_z_zz, g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_zz_xx, g_xy_zz_zz_xy, g_xy_zz_zz_xz, g_xy_zz_zz_yy, g_xy_zz_zz_yz, g_xy_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_y_zz_z_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_z_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_z_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_z_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_z_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_y_zz_z_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (864-870)

    #pragma omp simd aligned(g_x_0_z_0_z_xx_x_xx, g_x_0_z_0_z_xx_x_xy, g_x_0_z_0_z_xx_x_xz, g_x_0_z_0_z_xx_x_yy, g_x_0_z_0_z_xx_x_yz, g_x_0_z_0_z_xx_x_zz, g_xz_xx_xz_xx, g_xz_xx_xz_xy, g_xz_xx_xz_xz, g_xz_xx_xz_yy, g_xz_xx_xz_yz, g_xz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xx_x_xx[i] = 4.0 * g_xz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_x_xy[i] = 4.0 * g_xz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_x_xz[i] = 4.0 * g_xz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_x_yy[i] = 4.0 * g_xz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_x_yz[i] = 4.0 * g_xz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_x_zz[i] = 4.0 * g_xz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (870-876)

    #pragma omp simd aligned(g_x_0_z_0_z_xx_y_xx, g_x_0_z_0_z_xx_y_xy, g_x_0_z_0_z_xx_y_xz, g_x_0_z_0_z_xx_y_yy, g_x_0_z_0_z_xx_y_yz, g_x_0_z_0_z_xx_y_zz, g_xz_xx_yz_xx, g_xz_xx_yz_xy, g_xz_xx_yz_xz, g_xz_xx_yz_yy, g_xz_xx_yz_yz, g_xz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xx_y_xx[i] = 4.0 * g_xz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_y_xy[i] = 4.0 * g_xz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_y_xz[i] = 4.0 * g_xz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_y_yy[i] = 4.0 * g_xz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_y_yz[i] = 4.0 * g_xz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_y_zz[i] = 4.0 * g_xz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (876-882)

    #pragma omp simd aligned(g_x_0_z_0_z_xx_z_xx, g_x_0_z_0_z_xx_z_xy, g_x_0_z_0_z_xx_z_xz, g_x_0_z_0_z_xx_z_yy, g_x_0_z_0_z_xx_z_yz, g_x_0_z_0_z_xx_z_zz, g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_zz_xx, g_xz_xx_zz_xy, g_xz_xx_zz_xz, g_xz_xx_zz_yy, g_xz_xx_zz_yz, g_xz_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xx_z_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_z_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_z_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_z_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_z_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xx_z_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (882-888)

    #pragma omp simd aligned(g_x_0_z_0_z_xy_x_xx, g_x_0_z_0_z_xy_x_xy, g_x_0_z_0_z_xy_x_xz, g_x_0_z_0_z_xy_x_yy, g_x_0_z_0_z_xy_x_yz, g_x_0_z_0_z_xy_x_zz, g_xz_xy_xz_xx, g_xz_xy_xz_xy, g_xz_xy_xz_xz, g_xz_xy_xz_yy, g_xz_xy_xz_yz, g_xz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xy_x_xx[i] = 4.0 * g_xz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_x_xy[i] = 4.0 * g_xz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_x_xz[i] = 4.0 * g_xz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_x_yy[i] = 4.0 * g_xz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_x_yz[i] = 4.0 * g_xz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_x_zz[i] = 4.0 * g_xz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (888-894)

    #pragma omp simd aligned(g_x_0_z_0_z_xy_y_xx, g_x_0_z_0_z_xy_y_xy, g_x_0_z_0_z_xy_y_xz, g_x_0_z_0_z_xy_y_yy, g_x_0_z_0_z_xy_y_yz, g_x_0_z_0_z_xy_y_zz, g_xz_xy_yz_xx, g_xz_xy_yz_xy, g_xz_xy_yz_xz, g_xz_xy_yz_yy, g_xz_xy_yz_yz, g_xz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xy_y_xx[i] = 4.0 * g_xz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_y_xy[i] = 4.0 * g_xz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_y_xz[i] = 4.0 * g_xz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_y_yy[i] = 4.0 * g_xz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_y_yz[i] = 4.0 * g_xz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_y_zz[i] = 4.0 * g_xz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (894-900)

    #pragma omp simd aligned(g_x_0_z_0_z_xy_z_xx, g_x_0_z_0_z_xy_z_xy, g_x_0_z_0_z_xy_z_xz, g_x_0_z_0_z_xy_z_yy, g_x_0_z_0_z_xy_z_yz, g_x_0_z_0_z_xy_z_zz, g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_zz_xx, g_xz_xy_zz_xy, g_xz_xy_zz_xz, g_xz_xy_zz_yy, g_xz_xy_zz_yz, g_xz_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xy_z_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_z_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_z_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_z_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_z_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xy_z_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (900-906)

    #pragma omp simd aligned(g_x_0_z_0_z_xz_x_xx, g_x_0_z_0_z_xz_x_xy, g_x_0_z_0_z_xz_x_xz, g_x_0_z_0_z_xz_x_yy, g_x_0_z_0_z_xz_x_yz, g_x_0_z_0_z_xz_x_zz, g_xz_xz_xz_xx, g_xz_xz_xz_xy, g_xz_xz_xz_xz, g_xz_xz_xz_yy, g_xz_xz_xz_yz, g_xz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xz_x_xx[i] = 4.0 * g_xz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_x_xy[i] = 4.0 * g_xz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_x_xz[i] = 4.0 * g_xz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_x_yy[i] = 4.0 * g_xz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_x_yz[i] = 4.0 * g_xz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_x_zz[i] = 4.0 * g_xz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (906-912)

    #pragma omp simd aligned(g_x_0_z_0_z_xz_y_xx, g_x_0_z_0_z_xz_y_xy, g_x_0_z_0_z_xz_y_xz, g_x_0_z_0_z_xz_y_yy, g_x_0_z_0_z_xz_y_yz, g_x_0_z_0_z_xz_y_zz, g_xz_xz_yz_xx, g_xz_xz_yz_xy, g_xz_xz_yz_xz, g_xz_xz_yz_yy, g_xz_xz_yz_yz, g_xz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xz_y_xx[i] = 4.0 * g_xz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_y_xy[i] = 4.0 * g_xz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_y_xz[i] = 4.0 * g_xz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_y_yy[i] = 4.0 * g_xz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_y_yz[i] = 4.0 * g_xz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_y_zz[i] = 4.0 * g_xz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (912-918)

    #pragma omp simd aligned(g_x_0_z_0_z_xz_z_xx, g_x_0_z_0_z_xz_z_xy, g_x_0_z_0_z_xz_z_xz, g_x_0_z_0_z_xz_z_yy, g_x_0_z_0_z_xz_z_yz, g_x_0_z_0_z_xz_z_zz, g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_zz_xx, g_xz_xz_zz_xy, g_xz_xz_zz_xz, g_xz_xz_zz_yy, g_xz_xz_zz_yz, g_xz_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_xz_z_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_z_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_z_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_z_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_z_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_xz_z_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (918-924)

    #pragma omp simd aligned(g_x_0_z_0_z_yy_x_xx, g_x_0_z_0_z_yy_x_xy, g_x_0_z_0_z_yy_x_xz, g_x_0_z_0_z_yy_x_yy, g_x_0_z_0_z_yy_x_yz, g_x_0_z_0_z_yy_x_zz, g_xz_yy_xz_xx, g_xz_yy_xz_xy, g_xz_yy_xz_xz, g_xz_yy_xz_yy, g_xz_yy_xz_yz, g_xz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yy_x_xx[i] = 4.0 * g_xz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_x_xy[i] = 4.0 * g_xz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_x_xz[i] = 4.0 * g_xz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_x_yy[i] = 4.0 * g_xz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_x_yz[i] = 4.0 * g_xz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_x_zz[i] = 4.0 * g_xz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (924-930)

    #pragma omp simd aligned(g_x_0_z_0_z_yy_y_xx, g_x_0_z_0_z_yy_y_xy, g_x_0_z_0_z_yy_y_xz, g_x_0_z_0_z_yy_y_yy, g_x_0_z_0_z_yy_y_yz, g_x_0_z_0_z_yy_y_zz, g_xz_yy_yz_xx, g_xz_yy_yz_xy, g_xz_yy_yz_xz, g_xz_yy_yz_yy, g_xz_yy_yz_yz, g_xz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yy_y_xx[i] = 4.0 * g_xz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_y_xy[i] = 4.0 * g_xz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_y_xz[i] = 4.0 * g_xz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_y_yy[i] = 4.0 * g_xz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_y_yz[i] = 4.0 * g_xz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_y_zz[i] = 4.0 * g_xz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (930-936)

    #pragma omp simd aligned(g_x_0_z_0_z_yy_z_xx, g_x_0_z_0_z_yy_z_xy, g_x_0_z_0_z_yy_z_xz, g_x_0_z_0_z_yy_z_yy, g_x_0_z_0_z_yy_z_yz, g_x_0_z_0_z_yy_z_zz, g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_zz_xx, g_xz_yy_zz_xy, g_xz_yy_zz_xz, g_xz_yy_zz_yy, g_xz_yy_zz_yz, g_xz_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yy_z_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_z_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_z_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_z_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_z_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yy_z_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (936-942)

    #pragma omp simd aligned(g_x_0_z_0_z_yz_x_xx, g_x_0_z_0_z_yz_x_xy, g_x_0_z_0_z_yz_x_xz, g_x_0_z_0_z_yz_x_yy, g_x_0_z_0_z_yz_x_yz, g_x_0_z_0_z_yz_x_zz, g_xz_yz_xz_xx, g_xz_yz_xz_xy, g_xz_yz_xz_xz, g_xz_yz_xz_yy, g_xz_yz_xz_yz, g_xz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yz_x_xx[i] = 4.0 * g_xz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_x_xy[i] = 4.0 * g_xz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_x_xz[i] = 4.0 * g_xz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_x_yy[i] = 4.0 * g_xz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_x_yz[i] = 4.0 * g_xz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_x_zz[i] = 4.0 * g_xz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (942-948)

    #pragma omp simd aligned(g_x_0_z_0_z_yz_y_xx, g_x_0_z_0_z_yz_y_xy, g_x_0_z_0_z_yz_y_xz, g_x_0_z_0_z_yz_y_yy, g_x_0_z_0_z_yz_y_yz, g_x_0_z_0_z_yz_y_zz, g_xz_yz_yz_xx, g_xz_yz_yz_xy, g_xz_yz_yz_xz, g_xz_yz_yz_yy, g_xz_yz_yz_yz, g_xz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yz_y_xx[i] = 4.0 * g_xz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_y_xy[i] = 4.0 * g_xz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_y_xz[i] = 4.0 * g_xz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_y_yy[i] = 4.0 * g_xz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_y_yz[i] = 4.0 * g_xz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_y_zz[i] = 4.0 * g_xz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (948-954)

    #pragma omp simd aligned(g_x_0_z_0_z_yz_z_xx, g_x_0_z_0_z_yz_z_xy, g_x_0_z_0_z_yz_z_xz, g_x_0_z_0_z_yz_z_yy, g_x_0_z_0_z_yz_z_yz, g_x_0_z_0_z_yz_z_zz, g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_zz_xx, g_xz_yz_zz_xy, g_xz_yz_zz_xz, g_xz_yz_zz_yy, g_xz_yz_zz_yz, g_xz_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_yz_z_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_z_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_z_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_z_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_z_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_yz_z_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (954-960)

    #pragma omp simd aligned(g_x_0_z_0_z_zz_x_xx, g_x_0_z_0_z_zz_x_xy, g_x_0_z_0_z_zz_x_xz, g_x_0_z_0_z_zz_x_yy, g_x_0_z_0_z_zz_x_yz, g_x_0_z_0_z_zz_x_zz, g_xz_zz_xz_xx, g_xz_zz_xz_xy, g_xz_zz_xz_xz, g_xz_zz_xz_yy, g_xz_zz_xz_yz, g_xz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_zz_x_xx[i] = 4.0 * g_xz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_x_xy[i] = 4.0 * g_xz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_x_xz[i] = 4.0 * g_xz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_x_yy[i] = 4.0 * g_xz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_x_yz[i] = 4.0 * g_xz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_x_zz[i] = 4.0 * g_xz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (960-966)

    #pragma omp simd aligned(g_x_0_z_0_z_zz_y_xx, g_x_0_z_0_z_zz_y_xy, g_x_0_z_0_z_zz_y_xz, g_x_0_z_0_z_zz_y_yy, g_x_0_z_0_z_zz_y_yz, g_x_0_z_0_z_zz_y_zz, g_xz_zz_yz_xx, g_xz_zz_yz_xy, g_xz_zz_yz_xz, g_xz_zz_yz_yy, g_xz_zz_yz_yz, g_xz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_zz_y_xx[i] = 4.0 * g_xz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_y_xy[i] = 4.0 * g_xz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_y_xz[i] = 4.0 * g_xz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_y_yy[i] = 4.0 * g_xz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_y_yz[i] = 4.0 * g_xz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_y_zz[i] = 4.0 * g_xz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (966-972)

    #pragma omp simd aligned(g_x_0_z_0_z_zz_z_xx, g_x_0_z_0_z_zz_z_xy, g_x_0_z_0_z_zz_z_xz, g_x_0_z_0_z_zz_z_yy, g_x_0_z_0_z_zz_z_yz, g_x_0_z_0_z_zz_z_zz, g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_zz_xx, g_xz_zz_zz_xy, g_xz_zz_zz_xz, g_xz_zz_zz_yy, g_xz_zz_zz_yz, g_xz_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_x_0_z_0_z_zz_z_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_zz_xx[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_z_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_zz_xy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_z_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_zz_xz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_z_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_zz_yy[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_z_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_zz_yz[i] * a_exp * c_exps[i];

        g_x_0_z_0_z_zz_z_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (972-978)

    #pragma omp simd aligned(g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_xx_xx, g_xy_xx_xx_xy, g_xy_xx_xx_xz, g_xy_xx_xx_yy, g_xy_xx_xx_yz, g_xy_xx_xx_zz, g_y_0_x_0_x_xx_x_xx, g_y_0_x_0_x_xx_x_xy, g_y_0_x_0_x_xx_x_xz, g_y_0_x_0_x_xx_x_yy, g_y_0_x_0_x_xx_x_yz, g_y_0_x_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xx_x_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_x_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_x_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_x_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_x_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_x_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (978-984)

    #pragma omp simd aligned(g_xy_xx_xy_xx, g_xy_xx_xy_xy, g_xy_xx_xy_xz, g_xy_xx_xy_yy, g_xy_xx_xy_yz, g_xy_xx_xy_zz, g_y_0_x_0_x_xx_y_xx, g_y_0_x_0_x_xx_y_xy, g_y_0_x_0_x_xx_y_xz, g_y_0_x_0_x_xx_y_yy, g_y_0_x_0_x_xx_y_yz, g_y_0_x_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xx_y_xx[i] = 4.0 * g_xy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_y_xy[i] = 4.0 * g_xy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_y_xz[i] = 4.0 * g_xy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_y_yy[i] = 4.0 * g_xy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_y_yz[i] = 4.0 * g_xy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_y_zz[i] = 4.0 * g_xy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (984-990)

    #pragma omp simd aligned(g_xy_xx_xz_xx, g_xy_xx_xz_xy, g_xy_xx_xz_xz, g_xy_xx_xz_yy, g_xy_xx_xz_yz, g_xy_xx_xz_zz, g_y_0_x_0_x_xx_z_xx, g_y_0_x_0_x_xx_z_xy, g_y_0_x_0_x_xx_z_xz, g_y_0_x_0_x_xx_z_yy, g_y_0_x_0_x_xx_z_yz, g_y_0_x_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xx_z_xx[i] = 4.0 * g_xy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_z_xy[i] = 4.0 * g_xy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_z_xz[i] = 4.0 * g_xy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_z_yy[i] = 4.0 * g_xy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_z_yz[i] = 4.0 * g_xy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xx_z_zz[i] = 4.0 * g_xy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (990-996)

    #pragma omp simd aligned(g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_xx_xx, g_xy_xy_xx_xy, g_xy_xy_xx_xz, g_xy_xy_xx_yy, g_xy_xy_xx_yz, g_xy_xy_xx_zz, g_y_0_x_0_x_xy_x_xx, g_y_0_x_0_x_xy_x_xy, g_y_0_x_0_x_xy_x_xz, g_y_0_x_0_x_xy_x_yy, g_y_0_x_0_x_xy_x_yz, g_y_0_x_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xy_x_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_x_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_x_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_x_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_x_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_x_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (996-1002)

    #pragma omp simd aligned(g_xy_xy_xy_xx, g_xy_xy_xy_xy, g_xy_xy_xy_xz, g_xy_xy_xy_yy, g_xy_xy_xy_yz, g_xy_xy_xy_zz, g_y_0_x_0_x_xy_y_xx, g_y_0_x_0_x_xy_y_xy, g_y_0_x_0_x_xy_y_xz, g_y_0_x_0_x_xy_y_yy, g_y_0_x_0_x_xy_y_yz, g_y_0_x_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xy_y_xx[i] = 4.0 * g_xy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_y_xy[i] = 4.0 * g_xy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_y_xz[i] = 4.0 * g_xy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_y_yy[i] = 4.0 * g_xy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_y_yz[i] = 4.0 * g_xy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_y_zz[i] = 4.0 * g_xy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1002-1008)

    #pragma omp simd aligned(g_xy_xy_xz_xx, g_xy_xy_xz_xy, g_xy_xy_xz_xz, g_xy_xy_xz_yy, g_xy_xy_xz_yz, g_xy_xy_xz_zz, g_y_0_x_0_x_xy_z_xx, g_y_0_x_0_x_xy_z_xy, g_y_0_x_0_x_xy_z_xz, g_y_0_x_0_x_xy_z_yy, g_y_0_x_0_x_xy_z_yz, g_y_0_x_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xy_z_xx[i] = 4.0 * g_xy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_z_xy[i] = 4.0 * g_xy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_z_xz[i] = 4.0 * g_xy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_z_yy[i] = 4.0 * g_xy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_z_yz[i] = 4.0 * g_xy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xy_z_zz[i] = 4.0 * g_xy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1008-1014)

    #pragma omp simd aligned(g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_xx_xx, g_xy_xz_xx_xy, g_xy_xz_xx_xz, g_xy_xz_xx_yy, g_xy_xz_xx_yz, g_xy_xz_xx_zz, g_y_0_x_0_x_xz_x_xx, g_y_0_x_0_x_xz_x_xy, g_y_0_x_0_x_xz_x_xz, g_y_0_x_0_x_xz_x_yy, g_y_0_x_0_x_xz_x_yz, g_y_0_x_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xz_x_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_x_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_x_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_x_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_x_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_x_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1014-1020)

    #pragma omp simd aligned(g_xy_xz_xy_xx, g_xy_xz_xy_xy, g_xy_xz_xy_xz, g_xy_xz_xy_yy, g_xy_xz_xy_yz, g_xy_xz_xy_zz, g_y_0_x_0_x_xz_y_xx, g_y_0_x_0_x_xz_y_xy, g_y_0_x_0_x_xz_y_xz, g_y_0_x_0_x_xz_y_yy, g_y_0_x_0_x_xz_y_yz, g_y_0_x_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xz_y_xx[i] = 4.0 * g_xy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_y_xy[i] = 4.0 * g_xy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_y_xz[i] = 4.0 * g_xy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_y_yy[i] = 4.0 * g_xy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_y_yz[i] = 4.0 * g_xy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_y_zz[i] = 4.0 * g_xy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1020-1026)

    #pragma omp simd aligned(g_xy_xz_xz_xx, g_xy_xz_xz_xy, g_xy_xz_xz_xz, g_xy_xz_xz_yy, g_xy_xz_xz_yz, g_xy_xz_xz_zz, g_y_0_x_0_x_xz_z_xx, g_y_0_x_0_x_xz_z_xy, g_y_0_x_0_x_xz_z_xz, g_y_0_x_0_x_xz_z_yy, g_y_0_x_0_x_xz_z_yz, g_y_0_x_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_xz_z_xx[i] = 4.0 * g_xy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_z_xy[i] = 4.0 * g_xy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_z_xz[i] = 4.0 * g_xy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_z_yy[i] = 4.0 * g_xy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_z_yz[i] = 4.0 * g_xy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_xz_z_zz[i] = 4.0 * g_xy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1026-1032)

    #pragma omp simd aligned(g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_xx_xx, g_xy_yy_xx_xy, g_xy_yy_xx_xz, g_xy_yy_xx_yy, g_xy_yy_xx_yz, g_xy_yy_xx_zz, g_y_0_x_0_x_yy_x_xx, g_y_0_x_0_x_yy_x_xy, g_y_0_x_0_x_yy_x_xz, g_y_0_x_0_x_yy_x_yy, g_y_0_x_0_x_yy_x_yz, g_y_0_x_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yy_x_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_x_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_x_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_x_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_x_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_x_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1032-1038)

    #pragma omp simd aligned(g_xy_yy_xy_xx, g_xy_yy_xy_xy, g_xy_yy_xy_xz, g_xy_yy_xy_yy, g_xy_yy_xy_yz, g_xy_yy_xy_zz, g_y_0_x_0_x_yy_y_xx, g_y_0_x_0_x_yy_y_xy, g_y_0_x_0_x_yy_y_xz, g_y_0_x_0_x_yy_y_yy, g_y_0_x_0_x_yy_y_yz, g_y_0_x_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yy_y_xx[i] = 4.0 * g_xy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_y_xy[i] = 4.0 * g_xy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_y_xz[i] = 4.0 * g_xy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_y_yy[i] = 4.0 * g_xy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_y_yz[i] = 4.0 * g_xy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_y_zz[i] = 4.0 * g_xy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1038-1044)

    #pragma omp simd aligned(g_xy_yy_xz_xx, g_xy_yy_xz_xy, g_xy_yy_xz_xz, g_xy_yy_xz_yy, g_xy_yy_xz_yz, g_xy_yy_xz_zz, g_y_0_x_0_x_yy_z_xx, g_y_0_x_0_x_yy_z_xy, g_y_0_x_0_x_yy_z_xz, g_y_0_x_0_x_yy_z_yy, g_y_0_x_0_x_yy_z_yz, g_y_0_x_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yy_z_xx[i] = 4.0 * g_xy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_z_xy[i] = 4.0 * g_xy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_z_xz[i] = 4.0 * g_xy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_z_yy[i] = 4.0 * g_xy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_z_yz[i] = 4.0 * g_xy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yy_z_zz[i] = 4.0 * g_xy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1044-1050)

    #pragma omp simd aligned(g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_xx_xx, g_xy_yz_xx_xy, g_xy_yz_xx_xz, g_xy_yz_xx_yy, g_xy_yz_xx_yz, g_xy_yz_xx_zz, g_y_0_x_0_x_yz_x_xx, g_y_0_x_0_x_yz_x_xy, g_y_0_x_0_x_yz_x_xz, g_y_0_x_0_x_yz_x_yy, g_y_0_x_0_x_yz_x_yz, g_y_0_x_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yz_x_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_x_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_x_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_x_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_x_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_x_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1050-1056)

    #pragma omp simd aligned(g_xy_yz_xy_xx, g_xy_yz_xy_xy, g_xy_yz_xy_xz, g_xy_yz_xy_yy, g_xy_yz_xy_yz, g_xy_yz_xy_zz, g_y_0_x_0_x_yz_y_xx, g_y_0_x_0_x_yz_y_xy, g_y_0_x_0_x_yz_y_xz, g_y_0_x_0_x_yz_y_yy, g_y_0_x_0_x_yz_y_yz, g_y_0_x_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yz_y_xx[i] = 4.0 * g_xy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_y_xy[i] = 4.0 * g_xy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_y_xz[i] = 4.0 * g_xy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_y_yy[i] = 4.0 * g_xy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_y_yz[i] = 4.0 * g_xy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_y_zz[i] = 4.0 * g_xy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1056-1062)

    #pragma omp simd aligned(g_xy_yz_xz_xx, g_xy_yz_xz_xy, g_xy_yz_xz_xz, g_xy_yz_xz_yy, g_xy_yz_xz_yz, g_xy_yz_xz_zz, g_y_0_x_0_x_yz_z_xx, g_y_0_x_0_x_yz_z_xy, g_y_0_x_0_x_yz_z_xz, g_y_0_x_0_x_yz_z_yy, g_y_0_x_0_x_yz_z_yz, g_y_0_x_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_yz_z_xx[i] = 4.0 * g_xy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_z_xy[i] = 4.0 * g_xy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_z_xz[i] = 4.0 * g_xy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_z_yy[i] = 4.0 * g_xy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_z_yz[i] = 4.0 * g_xy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_yz_z_zz[i] = 4.0 * g_xy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1062-1068)

    #pragma omp simd aligned(g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_xx_xx, g_xy_zz_xx_xy, g_xy_zz_xx_xz, g_xy_zz_xx_yy, g_xy_zz_xx_yz, g_xy_zz_xx_zz, g_y_0_x_0_x_zz_x_xx, g_y_0_x_0_x_zz_x_xy, g_y_0_x_0_x_zz_x_xz, g_y_0_x_0_x_zz_x_yy, g_y_0_x_0_x_zz_x_yz, g_y_0_x_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_zz_x_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_x_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_x_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_x_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_x_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_x_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1068-1074)

    #pragma omp simd aligned(g_xy_zz_xy_xx, g_xy_zz_xy_xy, g_xy_zz_xy_xz, g_xy_zz_xy_yy, g_xy_zz_xy_yz, g_xy_zz_xy_zz, g_y_0_x_0_x_zz_y_xx, g_y_0_x_0_x_zz_y_xy, g_y_0_x_0_x_zz_y_xz, g_y_0_x_0_x_zz_y_yy, g_y_0_x_0_x_zz_y_yz, g_y_0_x_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_zz_y_xx[i] = 4.0 * g_xy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_y_xy[i] = 4.0 * g_xy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_y_xz[i] = 4.0 * g_xy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_y_yy[i] = 4.0 * g_xy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_y_yz[i] = 4.0 * g_xy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_y_zz[i] = 4.0 * g_xy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1074-1080)

    #pragma omp simd aligned(g_xy_zz_xz_xx, g_xy_zz_xz_xy, g_xy_zz_xz_xz, g_xy_zz_xz_yy, g_xy_zz_xz_yz, g_xy_zz_xz_zz, g_y_0_x_0_x_zz_z_xx, g_y_0_x_0_x_zz_z_xy, g_y_0_x_0_x_zz_z_xz, g_y_0_x_0_x_zz_z_yy, g_y_0_x_0_x_zz_z_yz, g_y_0_x_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_x_zz_z_xx[i] = 4.0 * g_xy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_z_xy[i] = 4.0 * g_xy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_z_xz[i] = 4.0 * g_xy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_z_yy[i] = 4.0 * g_xy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_z_yz[i] = 4.0 * g_xy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_x_zz_z_zz[i] = 4.0 * g_xy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1080-1086)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_xx_xx, g_0_xx_xx_xy, g_0_xx_xx_xz, g_0_xx_xx_yy, g_0_xx_xx_yz, g_0_xx_xx_zz, g_y_0_x_0_y_xx_x_xx, g_y_0_x_0_y_xx_x_xy, g_y_0_x_0_y_xx_x_xz, g_y_0_x_0_y_xx_x_yy, g_y_0_x_0_y_xx_x_yz, g_y_0_x_0_y_xx_x_zz, g_yy_xx_0_xx, g_yy_xx_0_xy, g_yy_xx_0_xz, g_yy_xx_0_yy, g_yy_xx_0_yz, g_yy_xx_0_zz, g_yy_xx_xx_xx, g_yy_xx_xx_xy, g_yy_xx_xx_xz, g_yy_xx_xx_yy, g_yy_xx_xx_yz, g_yy_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xx_x_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_xx_xx[i] * c_exps[i] - 2.0 * g_yy_xx_0_xx[i] * a_exp + 4.0 * g_yy_xx_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_x_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_xx_xy[i] * c_exps[i] - 2.0 * g_yy_xx_0_xy[i] * a_exp + 4.0 * g_yy_xx_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_x_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_xx_xz[i] * c_exps[i] - 2.0 * g_yy_xx_0_xz[i] * a_exp + 4.0 * g_yy_xx_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_x_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_xx_yy[i] * c_exps[i] - 2.0 * g_yy_xx_0_yy[i] * a_exp + 4.0 * g_yy_xx_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_x_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_xx_yz[i] * c_exps[i] - 2.0 * g_yy_xx_0_yz[i] * a_exp + 4.0 * g_yy_xx_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_x_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_xx_zz[i] * c_exps[i] - 2.0 * g_yy_xx_0_zz[i] * a_exp + 4.0 * g_yy_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1086-1092)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_y_0_x_0_y_xx_y_xx, g_y_0_x_0_y_xx_y_xy, g_y_0_x_0_y_xx_y_xz, g_y_0_x_0_y_xx_y_yy, g_y_0_x_0_y_xx_y_yz, g_y_0_x_0_y_xx_y_zz, g_yy_xx_xy_xx, g_yy_xx_xy_xy, g_yy_xx_xy_xz, g_yy_xx_xy_yy, g_yy_xx_xy_yz, g_yy_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xx_y_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_y_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_y_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_y_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_y_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_y_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1092-1098)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_y_0_x_0_y_xx_z_xx, g_y_0_x_0_y_xx_z_xy, g_y_0_x_0_y_xx_z_xz, g_y_0_x_0_y_xx_z_yy, g_y_0_x_0_y_xx_z_yz, g_y_0_x_0_y_xx_z_zz, g_yy_xx_xz_xx, g_yy_xx_xz_xy, g_yy_xx_xz_xz, g_yy_xx_xz_yy, g_yy_xx_xz_yz, g_yy_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xx_z_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_z_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_z_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_z_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_z_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xx_z_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1098-1104)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_xx_xx, g_0_xy_xx_xy, g_0_xy_xx_xz, g_0_xy_xx_yy, g_0_xy_xx_yz, g_0_xy_xx_zz, g_y_0_x_0_y_xy_x_xx, g_y_0_x_0_y_xy_x_xy, g_y_0_x_0_y_xy_x_xz, g_y_0_x_0_y_xy_x_yy, g_y_0_x_0_y_xy_x_yz, g_y_0_x_0_y_xy_x_zz, g_yy_xy_0_xx, g_yy_xy_0_xy, g_yy_xy_0_xz, g_yy_xy_0_yy, g_yy_xy_0_yz, g_yy_xy_0_zz, g_yy_xy_xx_xx, g_yy_xy_xx_xy, g_yy_xy_xx_xz, g_yy_xy_xx_yy, g_yy_xy_xx_yz, g_yy_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xy_x_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_xx_xx[i] * c_exps[i] - 2.0 * g_yy_xy_0_xx[i] * a_exp + 4.0 * g_yy_xy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_x_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_xx_xy[i] * c_exps[i] - 2.0 * g_yy_xy_0_xy[i] * a_exp + 4.0 * g_yy_xy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_x_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_xx_xz[i] * c_exps[i] - 2.0 * g_yy_xy_0_xz[i] * a_exp + 4.0 * g_yy_xy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_x_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_xx_yy[i] * c_exps[i] - 2.0 * g_yy_xy_0_yy[i] * a_exp + 4.0 * g_yy_xy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_x_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_xx_yz[i] * c_exps[i] - 2.0 * g_yy_xy_0_yz[i] * a_exp + 4.0 * g_yy_xy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_x_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_xx_zz[i] * c_exps[i] - 2.0 * g_yy_xy_0_zz[i] * a_exp + 4.0 * g_yy_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1104-1110)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_y_0_x_0_y_xy_y_xx, g_y_0_x_0_y_xy_y_xy, g_y_0_x_0_y_xy_y_xz, g_y_0_x_0_y_xy_y_yy, g_y_0_x_0_y_xy_y_yz, g_y_0_x_0_y_xy_y_zz, g_yy_xy_xy_xx, g_yy_xy_xy_xy, g_yy_xy_xy_xz, g_yy_xy_xy_yy, g_yy_xy_xy_yz, g_yy_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xy_y_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_y_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_y_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_y_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_y_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_y_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1110-1116)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_y_0_x_0_y_xy_z_xx, g_y_0_x_0_y_xy_z_xy, g_y_0_x_0_y_xy_z_xz, g_y_0_x_0_y_xy_z_yy, g_y_0_x_0_y_xy_z_yz, g_y_0_x_0_y_xy_z_zz, g_yy_xy_xz_xx, g_yy_xy_xz_xy, g_yy_xy_xz_xz, g_yy_xy_xz_yy, g_yy_xy_xz_yz, g_yy_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xy_z_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_z_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_z_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_z_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_z_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xy_z_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1116-1122)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_xx_xx, g_0_xz_xx_xy, g_0_xz_xx_xz, g_0_xz_xx_yy, g_0_xz_xx_yz, g_0_xz_xx_zz, g_y_0_x_0_y_xz_x_xx, g_y_0_x_0_y_xz_x_xy, g_y_0_x_0_y_xz_x_xz, g_y_0_x_0_y_xz_x_yy, g_y_0_x_0_y_xz_x_yz, g_y_0_x_0_y_xz_x_zz, g_yy_xz_0_xx, g_yy_xz_0_xy, g_yy_xz_0_xz, g_yy_xz_0_yy, g_yy_xz_0_yz, g_yy_xz_0_zz, g_yy_xz_xx_xx, g_yy_xz_xx_xy, g_yy_xz_xx_xz, g_yy_xz_xx_yy, g_yy_xz_xx_yz, g_yy_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xz_x_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_xx_xx[i] * c_exps[i] - 2.0 * g_yy_xz_0_xx[i] * a_exp + 4.0 * g_yy_xz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_x_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_xx_xy[i] * c_exps[i] - 2.0 * g_yy_xz_0_xy[i] * a_exp + 4.0 * g_yy_xz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_x_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_xx_xz[i] * c_exps[i] - 2.0 * g_yy_xz_0_xz[i] * a_exp + 4.0 * g_yy_xz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_x_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_xx_yy[i] * c_exps[i] - 2.0 * g_yy_xz_0_yy[i] * a_exp + 4.0 * g_yy_xz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_x_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_xx_yz[i] * c_exps[i] - 2.0 * g_yy_xz_0_yz[i] * a_exp + 4.0 * g_yy_xz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_x_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_xx_zz[i] * c_exps[i] - 2.0 * g_yy_xz_0_zz[i] * a_exp + 4.0 * g_yy_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1122-1128)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_y_0_x_0_y_xz_y_xx, g_y_0_x_0_y_xz_y_xy, g_y_0_x_0_y_xz_y_xz, g_y_0_x_0_y_xz_y_yy, g_y_0_x_0_y_xz_y_yz, g_y_0_x_0_y_xz_y_zz, g_yy_xz_xy_xx, g_yy_xz_xy_xy, g_yy_xz_xy_xz, g_yy_xz_xy_yy, g_yy_xz_xy_yz, g_yy_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xz_y_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_y_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_y_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_y_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_y_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_y_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1128-1134)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_y_0_x_0_y_xz_z_xx, g_y_0_x_0_y_xz_z_xy, g_y_0_x_0_y_xz_z_xz, g_y_0_x_0_y_xz_z_yy, g_y_0_x_0_y_xz_z_yz, g_y_0_x_0_y_xz_z_zz, g_yy_xz_xz_xx, g_yy_xz_xz_xy, g_yy_xz_xz_xz, g_yy_xz_xz_yy, g_yy_xz_xz_yz, g_yy_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_xz_z_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_z_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_z_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_z_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_z_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_xz_z_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1134-1140)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_xx_xx, g_0_yy_xx_xy, g_0_yy_xx_xz, g_0_yy_xx_yy, g_0_yy_xx_yz, g_0_yy_xx_zz, g_y_0_x_0_y_yy_x_xx, g_y_0_x_0_y_yy_x_xy, g_y_0_x_0_y_yy_x_xz, g_y_0_x_0_y_yy_x_yy, g_y_0_x_0_y_yy_x_yz, g_y_0_x_0_y_yy_x_zz, g_yy_yy_0_xx, g_yy_yy_0_xy, g_yy_yy_0_xz, g_yy_yy_0_yy, g_yy_yy_0_yz, g_yy_yy_0_zz, g_yy_yy_xx_xx, g_yy_yy_xx_xy, g_yy_yy_xx_xz, g_yy_yy_xx_yy, g_yy_yy_xx_yz, g_yy_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yy_x_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_xx_xx[i] * c_exps[i] - 2.0 * g_yy_yy_0_xx[i] * a_exp + 4.0 * g_yy_yy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_x_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_xx_xy[i] * c_exps[i] - 2.0 * g_yy_yy_0_xy[i] * a_exp + 4.0 * g_yy_yy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_x_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_xx_xz[i] * c_exps[i] - 2.0 * g_yy_yy_0_xz[i] * a_exp + 4.0 * g_yy_yy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_x_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_xx_yy[i] * c_exps[i] - 2.0 * g_yy_yy_0_yy[i] * a_exp + 4.0 * g_yy_yy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_x_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_xx_yz[i] * c_exps[i] - 2.0 * g_yy_yy_0_yz[i] * a_exp + 4.0 * g_yy_yy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_x_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_xx_zz[i] * c_exps[i] - 2.0 * g_yy_yy_0_zz[i] * a_exp + 4.0 * g_yy_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1140-1146)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_y_0_x_0_y_yy_y_xx, g_y_0_x_0_y_yy_y_xy, g_y_0_x_0_y_yy_y_xz, g_y_0_x_0_y_yy_y_yy, g_y_0_x_0_y_yy_y_yz, g_y_0_x_0_y_yy_y_zz, g_yy_yy_xy_xx, g_yy_yy_xy_xy, g_yy_yy_xy_xz, g_yy_yy_xy_yy, g_yy_yy_xy_yz, g_yy_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yy_y_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_y_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_y_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_y_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_yy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_y_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_y_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1146-1152)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_y_0_x_0_y_yy_z_xx, g_y_0_x_0_y_yy_z_xy, g_y_0_x_0_y_yy_z_xz, g_y_0_x_0_y_yy_z_yy, g_y_0_x_0_y_yy_z_yz, g_y_0_x_0_y_yy_z_zz, g_yy_yy_xz_xx, g_yy_yy_xz_xy, g_yy_yy_xz_xz, g_yy_yy_xz_yy, g_yy_yy_xz_yz, g_yy_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yy_z_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_z_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_z_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_z_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_yy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_z_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yy_z_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1152-1158)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_xx_xx, g_0_yz_xx_xy, g_0_yz_xx_xz, g_0_yz_xx_yy, g_0_yz_xx_yz, g_0_yz_xx_zz, g_y_0_x_0_y_yz_x_xx, g_y_0_x_0_y_yz_x_xy, g_y_0_x_0_y_yz_x_xz, g_y_0_x_0_y_yz_x_yy, g_y_0_x_0_y_yz_x_yz, g_y_0_x_0_y_yz_x_zz, g_yy_yz_0_xx, g_yy_yz_0_xy, g_yy_yz_0_xz, g_yy_yz_0_yy, g_yy_yz_0_yz, g_yy_yz_0_zz, g_yy_yz_xx_xx, g_yy_yz_xx_xy, g_yy_yz_xx_xz, g_yy_yz_xx_yy, g_yy_yz_xx_yz, g_yy_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yz_x_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_xx_xx[i] * c_exps[i] - 2.0 * g_yy_yz_0_xx[i] * a_exp + 4.0 * g_yy_yz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_x_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_xx_xy[i] * c_exps[i] - 2.0 * g_yy_yz_0_xy[i] * a_exp + 4.0 * g_yy_yz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_x_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_xx_xz[i] * c_exps[i] - 2.0 * g_yy_yz_0_xz[i] * a_exp + 4.0 * g_yy_yz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_x_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_xx_yy[i] * c_exps[i] - 2.0 * g_yy_yz_0_yy[i] * a_exp + 4.0 * g_yy_yz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_x_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_xx_yz[i] * c_exps[i] - 2.0 * g_yy_yz_0_yz[i] * a_exp + 4.0 * g_yy_yz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_x_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_xx_zz[i] * c_exps[i] - 2.0 * g_yy_yz_0_zz[i] * a_exp + 4.0 * g_yy_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1158-1164)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_y_0_x_0_y_yz_y_xx, g_y_0_x_0_y_yz_y_xy, g_y_0_x_0_y_yz_y_xz, g_y_0_x_0_y_yz_y_yy, g_y_0_x_0_y_yz_y_yz, g_y_0_x_0_y_yz_y_zz, g_yy_yz_xy_xx, g_yy_yz_xy_xy, g_yy_yz_xy_xz, g_yy_yz_xy_yy, g_yy_yz_xy_yz, g_yy_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yz_y_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_y_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_y_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_y_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_y_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_y_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1164-1170)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_y_0_x_0_y_yz_z_xx, g_y_0_x_0_y_yz_z_xy, g_y_0_x_0_y_yz_z_xz, g_y_0_x_0_y_yz_z_yy, g_y_0_x_0_y_yz_z_yz, g_y_0_x_0_y_yz_z_zz, g_yy_yz_xz_xx, g_yy_yz_xz_xy, g_yy_yz_xz_xz, g_yy_yz_xz_yy, g_yy_yz_xz_yz, g_yy_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_yz_z_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_z_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_z_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_z_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_z_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_yz_z_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1170-1176)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_xx_xx, g_0_zz_xx_xy, g_0_zz_xx_xz, g_0_zz_xx_yy, g_0_zz_xx_yz, g_0_zz_xx_zz, g_y_0_x_0_y_zz_x_xx, g_y_0_x_0_y_zz_x_xy, g_y_0_x_0_y_zz_x_xz, g_y_0_x_0_y_zz_x_yy, g_y_0_x_0_y_zz_x_yz, g_y_0_x_0_y_zz_x_zz, g_yy_zz_0_xx, g_yy_zz_0_xy, g_yy_zz_0_xz, g_yy_zz_0_yy, g_yy_zz_0_yz, g_yy_zz_0_zz, g_yy_zz_xx_xx, g_yy_zz_xx_xy, g_yy_zz_xx_xz, g_yy_zz_xx_yy, g_yy_zz_xx_yz, g_yy_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_zz_x_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_xx_xx[i] * c_exps[i] - 2.0 * g_yy_zz_0_xx[i] * a_exp + 4.0 * g_yy_zz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_x_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_xx_xy[i] * c_exps[i] - 2.0 * g_yy_zz_0_xy[i] * a_exp + 4.0 * g_yy_zz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_x_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_xx_xz[i] * c_exps[i] - 2.0 * g_yy_zz_0_xz[i] * a_exp + 4.0 * g_yy_zz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_x_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_xx_yy[i] * c_exps[i] - 2.0 * g_yy_zz_0_yy[i] * a_exp + 4.0 * g_yy_zz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_x_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_xx_yz[i] * c_exps[i] - 2.0 * g_yy_zz_0_yz[i] * a_exp + 4.0 * g_yy_zz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_x_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_xx_zz[i] * c_exps[i] - 2.0 * g_yy_zz_0_zz[i] * a_exp + 4.0 * g_yy_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1176-1182)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_y_0_x_0_y_zz_y_xx, g_y_0_x_0_y_zz_y_xy, g_y_0_x_0_y_zz_y_xz, g_y_0_x_0_y_zz_y_yy, g_y_0_x_0_y_zz_y_yz, g_y_0_x_0_y_zz_y_zz, g_yy_zz_xy_xx, g_yy_zz_xy_xy, g_yy_zz_xy_xz, g_yy_zz_xy_yy, g_yy_zz_xy_yz, g_yy_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_zz_y_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_y_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_y_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_y_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_y_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_y_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1182-1188)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_y_0_x_0_y_zz_z_xx, g_y_0_x_0_y_zz_z_xy, g_y_0_x_0_y_zz_z_xz, g_y_0_x_0_y_zz_z_yy, g_y_0_x_0_y_zz_z_yz, g_y_0_x_0_y_zz_z_zz, g_yy_zz_xz_xx, g_yy_zz_xz_xy, g_yy_zz_xz_xz, g_yy_zz_xz_yy, g_yy_zz_xz_yz, g_yy_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_y_zz_z_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_z_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_z_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_z_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_z_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_y_zz_z_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1188-1194)

    #pragma omp simd aligned(g_y_0_x_0_z_xx_x_xx, g_y_0_x_0_z_xx_x_xy, g_y_0_x_0_z_xx_x_xz, g_y_0_x_0_z_xx_x_yy, g_y_0_x_0_z_xx_x_yz, g_y_0_x_0_z_xx_x_zz, g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_xx_xx, g_yz_xx_xx_xy, g_yz_xx_xx_xz, g_yz_xx_xx_yy, g_yz_xx_xx_yz, g_yz_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xx_x_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_x_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_x_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_x_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_x_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_x_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1194-1200)

    #pragma omp simd aligned(g_y_0_x_0_z_xx_y_xx, g_y_0_x_0_z_xx_y_xy, g_y_0_x_0_z_xx_y_xz, g_y_0_x_0_z_xx_y_yy, g_y_0_x_0_z_xx_y_yz, g_y_0_x_0_z_xx_y_zz, g_yz_xx_xy_xx, g_yz_xx_xy_xy, g_yz_xx_xy_xz, g_yz_xx_xy_yy, g_yz_xx_xy_yz, g_yz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xx_y_xx[i] = 4.0 * g_yz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_y_xy[i] = 4.0 * g_yz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_y_xz[i] = 4.0 * g_yz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_y_yy[i] = 4.0 * g_yz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_y_yz[i] = 4.0 * g_yz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_y_zz[i] = 4.0 * g_yz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1200-1206)

    #pragma omp simd aligned(g_y_0_x_0_z_xx_z_xx, g_y_0_x_0_z_xx_z_xy, g_y_0_x_0_z_xx_z_xz, g_y_0_x_0_z_xx_z_yy, g_y_0_x_0_z_xx_z_yz, g_y_0_x_0_z_xx_z_zz, g_yz_xx_xz_xx, g_yz_xx_xz_xy, g_yz_xx_xz_xz, g_yz_xx_xz_yy, g_yz_xx_xz_yz, g_yz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xx_z_xx[i] = 4.0 * g_yz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_z_xy[i] = 4.0 * g_yz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_z_xz[i] = 4.0 * g_yz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_z_yy[i] = 4.0 * g_yz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_z_yz[i] = 4.0 * g_yz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xx_z_zz[i] = 4.0 * g_yz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1206-1212)

    #pragma omp simd aligned(g_y_0_x_0_z_xy_x_xx, g_y_0_x_0_z_xy_x_xy, g_y_0_x_0_z_xy_x_xz, g_y_0_x_0_z_xy_x_yy, g_y_0_x_0_z_xy_x_yz, g_y_0_x_0_z_xy_x_zz, g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_xx_xx, g_yz_xy_xx_xy, g_yz_xy_xx_xz, g_yz_xy_xx_yy, g_yz_xy_xx_yz, g_yz_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xy_x_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_x_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_x_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_x_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_x_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_x_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1212-1218)

    #pragma omp simd aligned(g_y_0_x_0_z_xy_y_xx, g_y_0_x_0_z_xy_y_xy, g_y_0_x_0_z_xy_y_xz, g_y_0_x_0_z_xy_y_yy, g_y_0_x_0_z_xy_y_yz, g_y_0_x_0_z_xy_y_zz, g_yz_xy_xy_xx, g_yz_xy_xy_xy, g_yz_xy_xy_xz, g_yz_xy_xy_yy, g_yz_xy_xy_yz, g_yz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xy_y_xx[i] = 4.0 * g_yz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_y_xy[i] = 4.0 * g_yz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_y_xz[i] = 4.0 * g_yz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_y_yy[i] = 4.0 * g_yz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_y_yz[i] = 4.0 * g_yz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_y_zz[i] = 4.0 * g_yz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1218-1224)

    #pragma omp simd aligned(g_y_0_x_0_z_xy_z_xx, g_y_0_x_0_z_xy_z_xy, g_y_0_x_0_z_xy_z_xz, g_y_0_x_0_z_xy_z_yy, g_y_0_x_0_z_xy_z_yz, g_y_0_x_0_z_xy_z_zz, g_yz_xy_xz_xx, g_yz_xy_xz_xy, g_yz_xy_xz_xz, g_yz_xy_xz_yy, g_yz_xy_xz_yz, g_yz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xy_z_xx[i] = 4.0 * g_yz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_z_xy[i] = 4.0 * g_yz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_z_xz[i] = 4.0 * g_yz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_z_yy[i] = 4.0 * g_yz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_z_yz[i] = 4.0 * g_yz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xy_z_zz[i] = 4.0 * g_yz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1224-1230)

    #pragma omp simd aligned(g_y_0_x_0_z_xz_x_xx, g_y_0_x_0_z_xz_x_xy, g_y_0_x_0_z_xz_x_xz, g_y_0_x_0_z_xz_x_yy, g_y_0_x_0_z_xz_x_yz, g_y_0_x_0_z_xz_x_zz, g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_xx_xx, g_yz_xz_xx_xy, g_yz_xz_xx_xz, g_yz_xz_xx_yy, g_yz_xz_xx_yz, g_yz_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xz_x_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_x_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_x_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_x_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_x_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_x_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1230-1236)

    #pragma omp simd aligned(g_y_0_x_0_z_xz_y_xx, g_y_0_x_0_z_xz_y_xy, g_y_0_x_0_z_xz_y_xz, g_y_0_x_0_z_xz_y_yy, g_y_0_x_0_z_xz_y_yz, g_y_0_x_0_z_xz_y_zz, g_yz_xz_xy_xx, g_yz_xz_xy_xy, g_yz_xz_xy_xz, g_yz_xz_xy_yy, g_yz_xz_xy_yz, g_yz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xz_y_xx[i] = 4.0 * g_yz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_y_xy[i] = 4.0 * g_yz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_y_xz[i] = 4.0 * g_yz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_y_yy[i] = 4.0 * g_yz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_y_yz[i] = 4.0 * g_yz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_y_zz[i] = 4.0 * g_yz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1236-1242)

    #pragma omp simd aligned(g_y_0_x_0_z_xz_z_xx, g_y_0_x_0_z_xz_z_xy, g_y_0_x_0_z_xz_z_xz, g_y_0_x_0_z_xz_z_yy, g_y_0_x_0_z_xz_z_yz, g_y_0_x_0_z_xz_z_zz, g_yz_xz_xz_xx, g_yz_xz_xz_xy, g_yz_xz_xz_xz, g_yz_xz_xz_yy, g_yz_xz_xz_yz, g_yz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_xz_z_xx[i] = 4.0 * g_yz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_z_xy[i] = 4.0 * g_yz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_z_xz[i] = 4.0 * g_yz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_z_yy[i] = 4.0 * g_yz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_z_yz[i] = 4.0 * g_yz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_xz_z_zz[i] = 4.0 * g_yz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1242-1248)

    #pragma omp simd aligned(g_y_0_x_0_z_yy_x_xx, g_y_0_x_0_z_yy_x_xy, g_y_0_x_0_z_yy_x_xz, g_y_0_x_0_z_yy_x_yy, g_y_0_x_0_z_yy_x_yz, g_y_0_x_0_z_yy_x_zz, g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_xx_xx, g_yz_yy_xx_xy, g_yz_yy_xx_xz, g_yz_yy_xx_yy, g_yz_yy_xx_yz, g_yz_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yy_x_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_x_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_x_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_x_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_x_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_x_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1248-1254)

    #pragma omp simd aligned(g_y_0_x_0_z_yy_y_xx, g_y_0_x_0_z_yy_y_xy, g_y_0_x_0_z_yy_y_xz, g_y_0_x_0_z_yy_y_yy, g_y_0_x_0_z_yy_y_yz, g_y_0_x_0_z_yy_y_zz, g_yz_yy_xy_xx, g_yz_yy_xy_xy, g_yz_yy_xy_xz, g_yz_yy_xy_yy, g_yz_yy_xy_yz, g_yz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yy_y_xx[i] = 4.0 * g_yz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_y_xy[i] = 4.0 * g_yz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_y_xz[i] = 4.0 * g_yz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_y_yy[i] = 4.0 * g_yz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_y_yz[i] = 4.0 * g_yz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_y_zz[i] = 4.0 * g_yz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1254-1260)

    #pragma omp simd aligned(g_y_0_x_0_z_yy_z_xx, g_y_0_x_0_z_yy_z_xy, g_y_0_x_0_z_yy_z_xz, g_y_0_x_0_z_yy_z_yy, g_y_0_x_0_z_yy_z_yz, g_y_0_x_0_z_yy_z_zz, g_yz_yy_xz_xx, g_yz_yy_xz_xy, g_yz_yy_xz_xz, g_yz_yy_xz_yy, g_yz_yy_xz_yz, g_yz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yy_z_xx[i] = 4.0 * g_yz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_z_xy[i] = 4.0 * g_yz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_z_xz[i] = 4.0 * g_yz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_z_yy[i] = 4.0 * g_yz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_z_yz[i] = 4.0 * g_yz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yy_z_zz[i] = 4.0 * g_yz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1260-1266)

    #pragma omp simd aligned(g_y_0_x_0_z_yz_x_xx, g_y_0_x_0_z_yz_x_xy, g_y_0_x_0_z_yz_x_xz, g_y_0_x_0_z_yz_x_yy, g_y_0_x_0_z_yz_x_yz, g_y_0_x_0_z_yz_x_zz, g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_xx_xx, g_yz_yz_xx_xy, g_yz_yz_xx_xz, g_yz_yz_xx_yy, g_yz_yz_xx_yz, g_yz_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yz_x_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_x_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_x_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_x_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_x_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_x_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1266-1272)

    #pragma omp simd aligned(g_y_0_x_0_z_yz_y_xx, g_y_0_x_0_z_yz_y_xy, g_y_0_x_0_z_yz_y_xz, g_y_0_x_0_z_yz_y_yy, g_y_0_x_0_z_yz_y_yz, g_y_0_x_0_z_yz_y_zz, g_yz_yz_xy_xx, g_yz_yz_xy_xy, g_yz_yz_xy_xz, g_yz_yz_xy_yy, g_yz_yz_xy_yz, g_yz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yz_y_xx[i] = 4.0 * g_yz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_y_xy[i] = 4.0 * g_yz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_y_xz[i] = 4.0 * g_yz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_y_yy[i] = 4.0 * g_yz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_y_yz[i] = 4.0 * g_yz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_y_zz[i] = 4.0 * g_yz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1272-1278)

    #pragma omp simd aligned(g_y_0_x_0_z_yz_z_xx, g_y_0_x_0_z_yz_z_xy, g_y_0_x_0_z_yz_z_xz, g_y_0_x_0_z_yz_z_yy, g_y_0_x_0_z_yz_z_yz, g_y_0_x_0_z_yz_z_zz, g_yz_yz_xz_xx, g_yz_yz_xz_xy, g_yz_yz_xz_xz, g_yz_yz_xz_yy, g_yz_yz_xz_yz, g_yz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_yz_z_xx[i] = 4.0 * g_yz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_z_xy[i] = 4.0 * g_yz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_z_xz[i] = 4.0 * g_yz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_z_yy[i] = 4.0 * g_yz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_z_yz[i] = 4.0 * g_yz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_yz_z_zz[i] = 4.0 * g_yz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1278-1284)

    #pragma omp simd aligned(g_y_0_x_0_z_zz_x_xx, g_y_0_x_0_z_zz_x_xy, g_y_0_x_0_z_zz_x_xz, g_y_0_x_0_z_zz_x_yy, g_y_0_x_0_z_zz_x_yz, g_y_0_x_0_z_zz_x_zz, g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_xx_xx, g_yz_zz_xx_xy, g_yz_zz_xx_xz, g_yz_zz_xx_yy, g_yz_zz_xx_yz, g_yz_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_zz_x_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_xx_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_x_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_xx_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_x_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_xx_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_x_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_xx_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_x_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_xx_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_x_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1284-1290)

    #pragma omp simd aligned(g_y_0_x_0_z_zz_y_xx, g_y_0_x_0_z_zz_y_xy, g_y_0_x_0_z_zz_y_xz, g_y_0_x_0_z_zz_y_yy, g_y_0_x_0_z_zz_y_yz, g_y_0_x_0_z_zz_y_zz, g_yz_zz_xy_xx, g_yz_zz_xy_xy, g_yz_zz_xy_xz, g_yz_zz_xy_yy, g_yz_zz_xy_yz, g_yz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_zz_y_xx[i] = 4.0 * g_yz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_y_xy[i] = 4.0 * g_yz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_y_xz[i] = 4.0 * g_yz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_y_yy[i] = 4.0 * g_yz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_y_yz[i] = 4.0 * g_yz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_y_zz[i] = 4.0 * g_yz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1290-1296)

    #pragma omp simd aligned(g_y_0_x_0_z_zz_z_xx, g_y_0_x_0_z_zz_z_xy, g_y_0_x_0_z_zz_z_xz, g_y_0_x_0_z_zz_z_yy, g_y_0_x_0_z_zz_z_yz, g_y_0_x_0_z_zz_z_zz, g_yz_zz_xz_xx, g_yz_zz_xz_xy, g_yz_zz_xz_xz, g_yz_zz_xz_yy, g_yz_zz_xz_yz, g_yz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_x_0_z_zz_z_xx[i] = 4.0 * g_yz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_z_xy[i] = 4.0 * g_yz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_z_xz[i] = 4.0 * g_yz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_z_yy[i] = 4.0 * g_yz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_z_yz[i] = 4.0 * g_yz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_x_0_z_zz_z_zz[i] = 4.0 * g_yz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1296-1302)

    #pragma omp simd aligned(g_xy_xx_xy_xx, g_xy_xx_xy_xy, g_xy_xx_xy_xz, g_xy_xx_xy_yy, g_xy_xx_xy_yz, g_xy_xx_xy_zz, g_y_0_y_0_x_xx_x_xx, g_y_0_y_0_x_xx_x_xy, g_y_0_y_0_x_xx_x_xz, g_y_0_y_0_x_xx_x_yy, g_y_0_y_0_x_xx_x_yz, g_y_0_y_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xx_x_xx[i] = 4.0 * g_xy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_x_xy[i] = 4.0 * g_xy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_x_xz[i] = 4.0 * g_xy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_x_yy[i] = 4.0 * g_xy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_x_yz[i] = 4.0 * g_xy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_x_zz[i] = 4.0 * g_xy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1302-1308)

    #pragma omp simd aligned(g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_yy_xx, g_xy_xx_yy_xy, g_xy_xx_yy_xz, g_xy_xx_yy_yy, g_xy_xx_yy_yz, g_xy_xx_yy_zz, g_y_0_y_0_x_xx_y_xx, g_y_0_y_0_x_xx_y_xy, g_y_0_y_0_x_xx_y_xz, g_y_0_y_0_x_xx_y_yy, g_y_0_y_0_x_xx_y_yz, g_y_0_y_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xx_y_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_y_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_y_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_y_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_y_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_y_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1308-1314)

    #pragma omp simd aligned(g_xy_xx_yz_xx, g_xy_xx_yz_xy, g_xy_xx_yz_xz, g_xy_xx_yz_yy, g_xy_xx_yz_yz, g_xy_xx_yz_zz, g_y_0_y_0_x_xx_z_xx, g_y_0_y_0_x_xx_z_xy, g_y_0_y_0_x_xx_z_xz, g_y_0_y_0_x_xx_z_yy, g_y_0_y_0_x_xx_z_yz, g_y_0_y_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xx_z_xx[i] = 4.0 * g_xy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_z_xy[i] = 4.0 * g_xy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_z_xz[i] = 4.0 * g_xy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_z_yy[i] = 4.0 * g_xy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_z_yz[i] = 4.0 * g_xy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xx_z_zz[i] = 4.0 * g_xy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1314-1320)

    #pragma omp simd aligned(g_xy_xy_xy_xx, g_xy_xy_xy_xy, g_xy_xy_xy_xz, g_xy_xy_xy_yy, g_xy_xy_xy_yz, g_xy_xy_xy_zz, g_y_0_y_0_x_xy_x_xx, g_y_0_y_0_x_xy_x_xy, g_y_0_y_0_x_xy_x_xz, g_y_0_y_0_x_xy_x_yy, g_y_0_y_0_x_xy_x_yz, g_y_0_y_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xy_x_xx[i] = 4.0 * g_xy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_x_xy[i] = 4.0 * g_xy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_x_xz[i] = 4.0 * g_xy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_x_yy[i] = 4.0 * g_xy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_x_yz[i] = 4.0 * g_xy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_x_zz[i] = 4.0 * g_xy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1320-1326)

    #pragma omp simd aligned(g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_yy_xx, g_xy_xy_yy_xy, g_xy_xy_yy_xz, g_xy_xy_yy_yy, g_xy_xy_yy_yz, g_xy_xy_yy_zz, g_y_0_y_0_x_xy_y_xx, g_y_0_y_0_x_xy_y_xy, g_y_0_y_0_x_xy_y_xz, g_y_0_y_0_x_xy_y_yy, g_y_0_y_0_x_xy_y_yz, g_y_0_y_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xy_y_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_y_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_y_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_y_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_y_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_y_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1326-1332)

    #pragma omp simd aligned(g_xy_xy_yz_xx, g_xy_xy_yz_xy, g_xy_xy_yz_xz, g_xy_xy_yz_yy, g_xy_xy_yz_yz, g_xy_xy_yz_zz, g_y_0_y_0_x_xy_z_xx, g_y_0_y_0_x_xy_z_xy, g_y_0_y_0_x_xy_z_xz, g_y_0_y_0_x_xy_z_yy, g_y_0_y_0_x_xy_z_yz, g_y_0_y_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xy_z_xx[i] = 4.0 * g_xy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_z_xy[i] = 4.0 * g_xy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_z_xz[i] = 4.0 * g_xy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_z_yy[i] = 4.0 * g_xy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_z_yz[i] = 4.0 * g_xy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xy_z_zz[i] = 4.0 * g_xy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1332-1338)

    #pragma omp simd aligned(g_xy_xz_xy_xx, g_xy_xz_xy_xy, g_xy_xz_xy_xz, g_xy_xz_xy_yy, g_xy_xz_xy_yz, g_xy_xz_xy_zz, g_y_0_y_0_x_xz_x_xx, g_y_0_y_0_x_xz_x_xy, g_y_0_y_0_x_xz_x_xz, g_y_0_y_0_x_xz_x_yy, g_y_0_y_0_x_xz_x_yz, g_y_0_y_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xz_x_xx[i] = 4.0 * g_xy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_x_xy[i] = 4.0 * g_xy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_x_xz[i] = 4.0 * g_xy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_x_yy[i] = 4.0 * g_xy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_x_yz[i] = 4.0 * g_xy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_x_zz[i] = 4.0 * g_xy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1338-1344)

    #pragma omp simd aligned(g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_yy_xx, g_xy_xz_yy_xy, g_xy_xz_yy_xz, g_xy_xz_yy_yy, g_xy_xz_yy_yz, g_xy_xz_yy_zz, g_y_0_y_0_x_xz_y_xx, g_y_0_y_0_x_xz_y_xy, g_y_0_y_0_x_xz_y_xz, g_y_0_y_0_x_xz_y_yy, g_y_0_y_0_x_xz_y_yz, g_y_0_y_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xz_y_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_y_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_y_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_y_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_y_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_y_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1344-1350)

    #pragma omp simd aligned(g_xy_xz_yz_xx, g_xy_xz_yz_xy, g_xy_xz_yz_xz, g_xy_xz_yz_yy, g_xy_xz_yz_yz, g_xy_xz_yz_zz, g_y_0_y_0_x_xz_z_xx, g_y_0_y_0_x_xz_z_xy, g_y_0_y_0_x_xz_z_xz, g_y_0_y_0_x_xz_z_yy, g_y_0_y_0_x_xz_z_yz, g_y_0_y_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_xz_z_xx[i] = 4.0 * g_xy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_z_xy[i] = 4.0 * g_xy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_z_xz[i] = 4.0 * g_xy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_z_yy[i] = 4.0 * g_xy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_z_yz[i] = 4.0 * g_xy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_xz_z_zz[i] = 4.0 * g_xy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1350-1356)

    #pragma omp simd aligned(g_xy_yy_xy_xx, g_xy_yy_xy_xy, g_xy_yy_xy_xz, g_xy_yy_xy_yy, g_xy_yy_xy_yz, g_xy_yy_xy_zz, g_y_0_y_0_x_yy_x_xx, g_y_0_y_0_x_yy_x_xy, g_y_0_y_0_x_yy_x_xz, g_y_0_y_0_x_yy_x_yy, g_y_0_y_0_x_yy_x_yz, g_y_0_y_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yy_x_xx[i] = 4.0 * g_xy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_x_xy[i] = 4.0 * g_xy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_x_xz[i] = 4.0 * g_xy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_x_yy[i] = 4.0 * g_xy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_x_yz[i] = 4.0 * g_xy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_x_zz[i] = 4.0 * g_xy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1356-1362)

    #pragma omp simd aligned(g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_yy_xx, g_xy_yy_yy_xy, g_xy_yy_yy_xz, g_xy_yy_yy_yy, g_xy_yy_yy_yz, g_xy_yy_yy_zz, g_y_0_y_0_x_yy_y_xx, g_y_0_y_0_x_yy_y_xy, g_y_0_y_0_x_yy_y_xz, g_y_0_y_0_x_yy_y_yy, g_y_0_y_0_x_yy_y_yz, g_y_0_y_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yy_y_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_y_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_y_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_y_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_y_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_y_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1362-1368)

    #pragma omp simd aligned(g_xy_yy_yz_xx, g_xy_yy_yz_xy, g_xy_yy_yz_xz, g_xy_yy_yz_yy, g_xy_yy_yz_yz, g_xy_yy_yz_zz, g_y_0_y_0_x_yy_z_xx, g_y_0_y_0_x_yy_z_xy, g_y_0_y_0_x_yy_z_xz, g_y_0_y_0_x_yy_z_yy, g_y_0_y_0_x_yy_z_yz, g_y_0_y_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yy_z_xx[i] = 4.0 * g_xy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_z_xy[i] = 4.0 * g_xy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_z_xz[i] = 4.0 * g_xy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_z_yy[i] = 4.0 * g_xy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_z_yz[i] = 4.0 * g_xy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yy_z_zz[i] = 4.0 * g_xy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1368-1374)

    #pragma omp simd aligned(g_xy_yz_xy_xx, g_xy_yz_xy_xy, g_xy_yz_xy_xz, g_xy_yz_xy_yy, g_xy_yz_xy_yz, g_xy_yz_xy_zz, g_y_0_y_0_x_yz_x_xx, g_y_0_y_0_x_yz_x_xy, g_y_0_y_0_x_yz_x_xz, g_y_0_y_0_x_yz_x_yy, g_y_0_y_0_x_yz_x_yz, g_y_0_y_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yz_x_xx[i] = 4.0 * g_xy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_x_xy[i] = 4.0 * g_xy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_x_xz[i] = 4.0 * g_xy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_x_yy[i] = 4.0 * g_xy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_x_yz[i] = 4.0 * g_xy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_x_zz[i] = 4.0 * g_xy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1374-1380)

    #pragma omp simd aligned(g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_yy_xx, g_xy_yz_yy_xy, g_xy_yz_yy_xz, g_xy_yz_yy_yy, g_xy_yz_yy_yz, g_xy_yz_yy_zz, g_y_0_y_0_x_yz_y_xx, g_y_0_y_0_x_yz_y_xy, g_y_0_y_0_x_yz_y_xz, g_y_0_y_0_x_yz_y_yy, g_y_0_y_0_x_yz_y_yz, g_y_0_y_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yz_y_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_y_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_y_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_y_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_y_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_y_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1380-1386)

    #pragma omp simd aligned(g_xy_yz_yz_xx, g_xy_yz_yz_xy, g_xy_yz_yz_xz, g_xy_yz_yz_yy, g_xy_yz_yz_yz, g_xy_yz_yz_zz, g_y_0_y_0_x_yz_z_xx, g_y_0_y_0_x_yz_z_xy, g_y_0_y_0_x_yz_z_xz, g_y_0_y_0_x_yz_z_yy, g_y_0_y_0_x_yz_z_yz, g_y_0_y_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_yz_z_xx[i] = 4.0 * g_xy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_z_xy[i] = 4.0 * g_xy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_z_xz[i] = 4.0 * g_xy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_z_yy[i] = 4.0 * g_xy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_z_yz[i] = 4.0 * g_xy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_yz_z_zz[i] = 4.0 * g_xy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1386-1392)

    #pragma omp simd aligned(g_xy_zz_xy_xx, g_xy_zz_xy_xy, g_xy_zz_xy_xz, g_xy_zz_xy_yy, g_xy_zz_xy_yz, g_xy_zz_xy_zz, g_y_0_y_0_x_zz_x_xx, g_y_0_y_0_x_zz_x_xy, g_y_0_y_0_x_zz_x_xz, g_y_0_y_0_x_zz_x_yy, g_y_0_y_0_x_zz_x_yz, g_y_0_y_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_zz_x_xx[i] = 4.0 * g_xy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_x_xy[i] = 4.0 * g_xy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_x_xz[i] = 4.0 * g_xy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_x_yy[i] = 4.0 * g_xy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_x_yz[i] = 4.0 * g_xy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_x_zz[i] = 4.0 * g_xy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1392-1398)

    #pragma omp simd aligned(g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_yy_xx, g_xy_zz_yy_xy, g_xy_zz_yy_xz, g_xy_zz_yy_yy, g_xy_zz_yy_yz, g_xy_zz_yy_zz, g_y_0_y_0_x_zz_y_xx, g_y_0_y_0_x_zz_y_xy, g_y_0_y_0_x_zz_y_xz, g_y_0_y_0_x_zz_y_yy, g_y_0_y_0_x_zz_y_yz, g_y_0_y_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_zz_y_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_y_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_y_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_y_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_y_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_y_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1398-1404)

    #pragma omp simd aligned(g_xy_zz_yz_xx, g_xy_zz_yz_xy, g_xy_zz_yz_xz, g_xy_zz_yz_yy, g_xy_zz_yz_yz, g_xy_zz_yz_zz, g_y_0_y_0_x_zz_z_xx, g_y_0_y_0_x_zz_z_xy, g_y_0_y_0_x_zz_z_xz, g_y_0_y_0_x_zz_z_yy, g_y_0_y_0_x_zz_z_yz, g_y_0_y_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_x_zz_z_xx[i] = 4.0 * g_xy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_z_xy[i] = 4.0 * g_xy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_z_xz[i] = 4.0 * g_xy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_z_yy[i] = 4.0 * g_xy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_z_yz[i] = 4.0 * g_xy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_x_zz_z_zz[i] = 4.0 * g_xy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1404-1410)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_y_0_y_0_y_xx_x_xx, g_y_0_y_0_y_xx_x_xy, g_y_0_y_0_y_xx_x_xz, g_y_0_y_0_y_xx_x_yy, g_y_0_y_0_y_xx_x_yz, g_y_0_y_0_y_xx_x_zz, g_yy_xx_xy_xx, g_yy_xx_xy_xy, g_yy_xx_xy_xz, g_yy_xx_xy_yy, g_yy_xx_xy_yz, g_yy_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xx_x_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_x_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_x_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_x_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_x_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_x_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1410-1416)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_yy_xx, g_0_xx_yy_xy, g_0_xx_yy_xz, g_0_xx_yy_yy, g_0_xx_yy_yz, g_0_xx_yy_zz, g_y_0_y_0_y_xx_y_xx, g_y_0_y_0_y_xx_y_xy, g_y_0_y_0_y_xx_y_xz, g_y_0_y_0_y_xx_y_yy, g_y_0_y_0_y_xx_y_yz, g_y_0_y_0_y_xx_y_zz, g_yy_xx_0_xx, g_yy_xx_0_xy, g_yy_xx_0_xz, g_yy_xx_0_yy, g_yy_xx_0_yz, g_yy_xx_0_zz, g_yy_xx_yy_xx, g_yy_xx_yy_xy, g_yy_xx_yy_xz, g_yy_xx_yy_yy, g_yy_xx_yy_yz, g_yy_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xx_y_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_yy_xx[i] * c_exps[i] - 2.0 * g_yy_xx_0_xx[i] * a_exp + 4.0 * g_yy_xx_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_y_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_yy_xy[i] * c_exps[i] - 2.0 * g_yy_xx_0_xy[i] * a_exp + 4.0 * g_yy_xx_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_y_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_yy_xz[i] * c_exps[i] - 2.0 * g_yy_xx_0_xz[i] * a_exp + 4.0 * g_yy_xx_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_y_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_yy_yy[i] * c_exps[i] - 2.0 * g_yy_xx_0_yy[i] * a_exp + 4.0 * g_yy_xx_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_y_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_yy_yz[i] * c_exps[i] - 2.0 * g_yy_xx_0_yz[i] * a_exp + 4.0 * g_yy_xx_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_y_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_yy_zz[i] * c_exps[i] - 2.0 * g_yy_xx_0_zz[i] * a_exp + 4.0 * g_yy_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1416-1422)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_y_0_y_0_y_xx_z_xx, g_y_0_y_0_y_xx_z_xy, g_y_0_y_0_y_xx_z_xz, g_y_0_y_0_y_xx_z_yy, g_y_0_y_0_y_xx_z_yz, g_y_0_y_0_y_xx_z_zz, g_yy_xx_yz_xx, g_yy_xx_yz_xy, g_yy_xx_yz_xz, g_yy_xx_yz_yy, g_yy_xx_yz_yz, g_yy_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xx_z_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_z_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_z_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_z_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_z_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xx_z_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1422-1428)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_y_0_y_0_y_xy_x_xx, g_y_0_y_0_y_xy_x_xy, g_y_0_y_0_y_xy_x_xz, g_y_0_y_0_y_xy_x_yy, g_y_0_y_0_y_xy_x_yz, g_y_0_y_0_y_xy_x_zz, g_yy_xy_xy_xx, g_yy_xy_xy_xy, g_yy_xy_xy_xz, g_yy_xy_xy_yy, g_yy_xy_xy_yz, g_yy_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xy_x_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_x_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_x_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_x_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_x_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_x_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1428-1434)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_yy_xx, g_0_xy_yy_xy, g_0_xy_yy_xz, g_0_xy_yy_yy, g_0_xy_yy_yz, g_0_xy_yy_zz, g_y_0_y_0_y_xy_y_xx, g_y_0_y_0_y_xy_y_xy, g_y_0_y_0_y_xy_y_xz, g_y_0_y_0_y_xy_y_yy, g_y_0_y_0_y_xy_y_yz, g_y_0_y_0_y_xy_y_zz, g_yy_xy_0_xx, g_yy_xy_0_xy, g_yy_xy_0_xz, g_yy_xy_0_yy, g_yy_xy_0_yz, g_yy_xy_0_zz, g_yy_xy_yy_xx, g_yy_xy_yy_xy, g_yy_xy_yy_xz, g_yy_xy_yy_yy, g_yy_xy_yy_yz, g_yy_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xy_y_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_yy_xx[i] * c_exps[i] - 2.0 * g_yy_xy_0_xx[i] * a_exp + 4.0 * g_yy_xy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_y_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_yy_xy[i] * c_exps[i] - 2.0 * g_yy_xy_0_xy[i] * a_exp + 4.0 * g_yy_xy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_y_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_yy_xz[i] * c_exps[i] - 2.0 * g_yy_xy_0_xz[i] * a_exp + 4.0 * g_yy_xy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_y_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_yy_yy[i] * c_exps[i] - 2.0 * g_yy_xy_0_yy[i] * a_exp + 4.0 * g_yy_xy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_y_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_yy_yz[i] * c_exps[i] - 2.0 * g_yy_xy_0_yz[i] * a_exp + 4.0 * g_yy_xy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_y_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_yy_zz[i] * c_exps[i] - 2.0 * g_yy_xy_0_zz[i] * a_exp + 4.0 * g_yy_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1434-1440)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_y_0_y_0_y_xy_z_xx, g_y_0_y_0_y_xy_z_xy, g_y_0_y_0_y_xy_z_xz, g_y_0_y_0_y_xy_z_yy, g_y_0_y_0_y_xy_z_yz, g_y_0_y_0_y_xy_z_zz, g_yy_xy_yz_xx, g_yy_xy_yz_xy, g_yy_xy_yz_xz, g_yy_xy_yz_yy, g_yy_xy_yz_yz, g_yy_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xy_z_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_z_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_z_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_z_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_z_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xy_z_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1440-1446)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_y_0_y_0_y_xz_x_xx, g_y_0_y_0_y_xz_x_xy, g_y_0_y_0_y_xz_x_xz, g_y_0_y_0_y_xz_x_yy, g_y_0_y_0_y_xz_x_yz, g_y_0_y_0_y_xz_x_zz, g_yy_xz_xy_xx, g_yy_xz_xy_xy, g_yy_xz_xy_xz, g_yy_xz_xy_yy, g_yy_xz_xy_yz, g_yy_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xz_x_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_x_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_x_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_x_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_x_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_x_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1446-1452)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_yy_xx, g_0_xz_yy_xy, g_0_xz_yy_xz, g_0_xz_yy_yy, g_0_xz_yy_yz, g_0_xz_yy_zz, g_y_0_y_0_y_xz_y_xx, g_y_0_y_0_y_xz_y_xy, g_y_0_y_0_y_xz_y_xz, g_y_0_y_0_y_xz_y_yy, g_y_0_y_0_y_xz_y_yz, g_y_0_y_0_y_xz_y_zz, g_yy_xz_0_xx, g_yy_xz_0_xy, g_yy_xz_0_xz, g_yy_xz_0_yy, g_yy_xz_0_yz, g_yy_xz_0_zz, g_yy_xz_yy_xx, g_yy_xz_yy_xy, g_yy_xz_yy_xz, g_yy_xz_yy_yy, g_yy_xz_yy_yz, g_yy_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xz_y_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_yy_xx[i] * c_exps[i] - 2.0 * g_yy_xz_0_xx[i] * a_exp + 4.0 * g_yy_xz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_y_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_yy_xy[i] * c_exps[i] - 2.0 * g_yy_xz_0_xy[i] * a_exp + 4.0 * g_yy_xz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_y_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_yy_xz[i] * c_exps[i] - 2.0 * g_yy_xz_0_xz[i] * a_exp + 4.0 * g_yy_xz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_y_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_yy_yy[i] * c_exps[i] - 2.0 * g_yy_xz_0_yy[i] * a_exp + 4.0 * g_yy_xz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_y_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_yy_yz[i] * c_exps[i] - 2.0 * g_yy_xz_0_yz[i] * a_exp + 4.0 * g_yy_xz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_y_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_yy_zz[i] * c_exps[i] - 2.0 * g_yy_xz_0_zz[i] * a_exp + 4.0 * g_yy_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1452-1458)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_y_0_y_0_y_xz_z_xx, g_y_0_y_0_y_xz_z_xy, g_y_0_y_0_y_xz_z_xz, g_y_0_y_0_y_xz_z_yy, g_y_0_y_0_y_xz_z_yz, g_y_0_y_0_y_xz_z_zz, g_yy_xz_yz_xx, g_yy_xz_yz_xy, g_yy_xz_yz_xz, g_yy_xz_yz_yy, g_yy_xz_yz_yz, g_yy_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_xz_z_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_z_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_z_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_z_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_z_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_xz_z_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1458-1464)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_y_0_y_0_y_yy_x_xx, g_y_0_y_0_y_yy_x_xy, g_y_0_y_0_y_yy_x_xz, g_y_0_y_0_y_yy_x_yy, g_y_0_y_0_y_yy_x_yz, g_y_0_y_0_y_yy_x_zz, g_yy_yy_xy_xx, g_yy_yy_xy_xy, g_yy_yy_xy_xz, g_yy_yy_xy_yy, g_yy_yy_xy_yz, g_yy_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yy_x_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_x_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_x_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_x_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_yy_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_x_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_x_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_yy_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1464-1470)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_yy_xx, g_0_yy_yy_xy, g_0_yy_yy_xz, g_0_yy_yy_yy, g_0_yy_yy_yz, g_0_yy_yy_zz, g_y_0_y_0_y_yy_y_xx, g_y_0_y_0_y_yy_y_xy, g_y_0_y_0_y_yy_y_xz, g_y_0_y_0_y_yy_y_yy, g_y_0_y_0_y_yy_y_yz, g_y_0_y_0_y_yy_y_zz, g_yy_yy_0_xx, g_yy_yy_0_xy, g_yy_yy_0_xz, g_yy_yy_0_yy, g_yy_yy_0_yz, g_yy_yy_0_zz, g_yy_yy_yy_xx, g_yy_yy_yy_xy, g_yy_yy_yy_xz, g_yy_yy_yy_yy, g_yy_yy_yy_yz, g_yy_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yy_y_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_yy_xx[i] * c_exps[i] - 2.0 * g_yy_yy_0_xx[i] * a_exp + 4.0 * g_yy_yy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_y_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_yy_xy[i] * c_exps[i] - 2.0 * g_yy_yy_0_xy[i] * a_exp + 4.0 * g_yy_yy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_y_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_yy_xz[i] * c_exps[i] - 2.0 * g_yy_yy_0_xz[i] * a_exp + 4.0 * g_yy_yy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_y_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_yy_yy[i] * c_exps[i] - 2.0 * g_yy_yy_0_yy[i] * a_exp + 4.0 * g_yy_yy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_y_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_yy_yz[i] * c_exps[i] - 2.0 * g_yy_yy_0_yz[i] * a_exp + 4.0 * g_yy_yy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_y_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_yy_zz[i] * c_exps[i] - 2.0 * g_yy_yy_0_zz[i] * a_exp + 4.0 * g_yy_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1470-1476)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_y_0_y_0_y_yy_z_xx, g_y_0_y_0_y_yy_z_xy, g_y_0_y_0_y_yy_z_xz, g_y_0_y_0_y_yy_z_yy, g_y_0_y_0_y_yy_z_yz, g_y_0_y_0_y_yy_z_zz, g_yy_yy_yz_xx, g_yy_yy_yz_xy, g_yy_yy_yz_xz, g_yy_yy_yz_yy, g_yy_yy_yz_yz, g_yy_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yy_z_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_z_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_z_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_z_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_yy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_z_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yy_z_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1476-1482)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_y_0_y_0_y_yz_x_xx, g_y_0_y_0_y_yz_x_xy, g_y_0_y_0_y_yz_x_xz, g_y_0_y_0_y_yz_x_yy, g_y_0_y_0_y_yz_x_yz, g_y_0_y_0_y_yz_x_zz, g_yy_yz_xy_xx, g_yy_yz_xy_xy, g_yy_yz_xy_xz, g_yy_yz_xy_yy, g_yy_yz_xy_yz, g_yy_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yz_x_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_x_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_x_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_x_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_x_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_x_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1482-1488)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_yy_xx, g_0_yz_yy_xy, g_0_yz_yy_xz, g_0_yz_yy_yy, g_0_yz_yy_yz, g_0_yz_yy_zz, g_y_0_y_0_y_yz_y_xx, g_y_0_y_0_y_yz_y_xy, g_y_0_y_0_y_yz_y_xz, g_y_0_y_0_y_yz_y_yy, g_y_0_y_0_y_yz_y_yz, g_y_0_y_0_y_yz_y_zz, g_yy_yz_0_xx, g_yy_yz_0_xy, g_yy_yz_0_xz, g_yy_yz_0_yy, g_yy_yz_0_yz, g_yy_yz_0_zz, g_yy_yz_yy_xx, g_yy_yz_yy_xy, g_yy_yz_yy_xz, g_yy_yz_yy_yy, g_yy_yz_yy_yz, g_yy_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yz_y_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_yy_xx[i] * c_exps[i] - 2.0 * g_yy_yz_0_xx[i] * a_exp + 4.0 * g_yy_yz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_y_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_yy_xy[i] * c_exps[i] - 2.0 * g_yy_yz_0_xy[i] * a_exp + 4.0 * g_yy_yz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_y_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_yy_xz[i] * c_exps[i] - 2.0 * g_yy_yz_0_xz[i] * a_exp + 4.0 * g_yy_yz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_y_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_yy_yy[i] * c_exps[i] - 2.0 * g_yy_yz_0_yy[i] * a_exp + 4.0 * g_yy_yz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_y_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_yy_yz[i] * c_exps[i] - 2.0 * g_yy_yz_0_yz[i] * a_exp + 4.0 * g_yy_yz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_y_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_yy_zz[i] * c_exps[i] - 2.0 * g_yy_yz_0_zz[i] * a_exp + 4.0 * g_yy_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1488-1494)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_y_0_y_0_y_yz_z_xx, g_y_0_y_0_y_yz_z_xy, g_y_0_y_0_y_yz_z_xz, g_y_0_y_0_y_yz_z_yy, g_y_0_y_0_y_yz_z_yz, g_y_0_y_0_y_yz_z_zz, g_yy_yz_yz_xx, g_yy_yz_yz_xy, g_yy_yz_yz_xz, g_yy_yz_yz_yy, g_yy_yz_yz_yz, g_yy_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_yz_z_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_z_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_z_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_z_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_z_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_yz_z_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1494-1500)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_y_0_y_0_y_zz_x_xx, g_y_0_y_0_y_zz_x_xy, g_y_0_y_0_y_zz_x_xz, g_y_0_y_0_y_zz_x_yy, g_y_0_y_0_y_zz_x_yz, g_y_0_y_0_y_zz_x_zz, g_yy_zz_xy_xx, g_yy_zz_xy_xy, g_yy_zz_xy_xz, g_yy_zz_xy_yy, g_yy_zz_xy_yz, g_yy_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_zz_x_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_x_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_x_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_x_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_yy_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_x_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_x_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_yy_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1500-1506)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_yy_xx, g_0_zz_yy_xy, g_0_zz_yy_xz, g_0_zz_yy_yy, g_0_zz_yy_yz, g_0_zz_yy_zz, g_y_0_y_0_y_zz_y_xx, g_y_0_y_0_y_zz_y_xy, g_y_0_y_0_y_zz_y_xz, g_y_0_y_0_y_zz_y_yy, g_y_0_y_0_y_zz_y_yz, g_y_0_y_0_y_zz_y_zz, g_yy_zz_0_xx, g_yy_zz_0_xy, g_yy_zz_0_xz, g_yy_zz_0_yy, g_yy_zz_0_yz, g_yy_zz_0_zz, g_yy_zz_yy_xx, g_yy_zz_yy_xy, g_yy_zz_yy_xz, g_yy_zz_yy_yy, g_yy_zz_yy_yz, g_yy_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_zz_y_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_yy_xx[i] * c_exps[i] - 2.0 * g_yy_zz_0_xx[i] * a_exp + 4.0 * g_yy_zz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_y_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_yy_xy[i] * c_exps[i] - 2.0 * g_yy_zz_0_xy[i] * a_exp + 4.0 * g_yy_zz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_y_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_yy_xz[i] * c_exps[i] - 2.0 * g_yy_zz_0_xz[i] * a_exp + 4.0 * g_yy_zz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_y_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_yy_yy[i] * c_exps[i] - 2.0 * g_yy_zz_0_yy[i] * a_exp + 4.0 * g_yy_zz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_y_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_yy_yz[i] * c_exps[i] - 2.0 * g_yy_zz_0_yz[i] * a_exp + 4.0 * g_yy_zz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_y_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_yy_zz[i] * c_exps[i] - 2.0 * g_yy_zz_0_zz[i] * a_exp + 4.0 * g_yy_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1506-1512)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_y_0_y_0_y_zz_z_xx, g_y_0_y_0_y_zz_z_xy, g_y_0_y_0_y_zz_z_xz, g_y_0_y_0_y_zz_z_yy, g_y_0_y_0_y_zz_z_yz, g_y_0_y_0_y_zz_z_zz, g_yy_zz_yz_xx, g_yy_zz_yz_xy, g_yy_zz_yz_xz, g_yy_zz_yz_yy, g_yy_zz_yz_yz, g_yy_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_y_zz_z_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_z_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_z_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_z_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_z_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_y_zz_z_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1512-1518)

    #pragma omp simd aligned(g_y_0_y_0_z_xx_x_xx, g_y_0_y_0_z_xx_x_xy, g_y_0_y_0_z_xx_x_xz, g_y_0_y_0_z_xx_x_yy, g_y_0_y_0_z_xx_x_yz, g_y_0_y_0_z_xx_x_zz, g_yz_xx_xy_xx, g_yz_xx_xy_xy, g_yz_xx_xy_xz, g_yz_xx_xy_yy, g_yz_xx_xy_yz, g_yz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xx_x_xx[i] = 4.0 * g_yz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_x_xy[i] = 4.0 * g_yz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_x_xz[i] = 4.0 * g_yz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_x_yy[i] = 4.0 * g_yz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_x_yz[i] = 4.0 * g_yz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_x_zz[i] = 4.0 * g_yz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1518-1524)

    #pragma omp simd aligned(g_y_0_y_0_z_xx_y_xx, g_y_0_y_0_z_xx_y_xy, g_y_0_y_0_z_xx_y_xz, g_y_0_y_0_z_xx_y_yy, g_y_0_y_0_z_xx_y_yz, g_y_0_y_0_z_xx_y_zz, g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_yy_xx, g_yz_xx_yy_xy, g_yz_xx_yy_xz, g_yz_xx_yy_yy, g_yz_xx_yy_yz, g_yz_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xx_y_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_y_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_y_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_y_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_y_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_y_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1524-1530)

    #pragma omp simd aligned(g_y_0_y_0_z_xx_z_xx, g_y_0_y_0_z_xx_z_xy, g_y_0_y_0_z_xx_z_xz, g_y_0_y_0_z_xx_z_yy, g_y_0_y_0_z_xx_z_yz, g_y_0_y_0_z_xx_z_zz, g_yz_xx_yz_xx, g_yz_xx_yz_xy, g_yz_xx_yz_xz, g_yz_xx_yz_yy, g_yz_xx_yz_yz, g_yz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xx_z_xx[i] = 4.0 * g_yz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_z_xy[i] = 4.0 * g_yz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_z_xz[i] = 4.0 * g_yz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_z_yy[i] = 4.0 * g_yz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_z_yz[i] = 4.0 * g_yz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xx_z_zz[i] = 4.0 * g_yz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1530-1536)

    #pragma omp simd aligned(g_y_0_y_0_z_xy_x_xx, g_y_0_y_0_z_xy_x_xy, g_y_0_y_0_z_xy_x_xz, g_y_0_y_0_z_xy_x_yy, g_y_0_y_0_z_xy_x_yz, g_y_0_y_0_z_xy_x_zz, g_yz_xy_xy_xx, g_yz_xy_xy_xy, g_yz_xy_xy_xz, g_yz_xy_xy_yy, g_yz_xy_xy_yz, g_yz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xy_x_xx[i] = 4.0 * g_yz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_x_xy[i] = 4.0 * g_yz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_x_xz[i] = 4.0 * g_yz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_x_yy[i] = 4.0 * g_yz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_x_yz[i] = 4.0 * g_yz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_x_zz[i] = 4.0 * g_yz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1536-1542)

    #pragma omp simd aligned(g_y_0_y_0_z_xy_y_xx, g_y_0_y_0_z_xy_y_xy, g_y_0_y_0_z_xy_y_xz, g_y_0_y_0_z_xy_y_yy, g_y_0_y_0_z_xy_y_yz, g_y_0_y_0_z_xy_y_zz, g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_yy_xx, g_yz_xy_yy_xy, g_yz_xy_yy_xz, g_yz_xy_yy_yy, g_yz_xy_yy_yz, g_yz_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xy_y_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_y_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_y_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_y_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_y_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_y_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1542-1548)

    #pragma omp simd aligned(g_y_0_y_0_z_xy_z_xx, g_y_0_y_0_z_xy_z_xy, g_y_0_y_0_z_xy_z_xz, g_y_0_y_0_z_xy_z_yy, g_y_0_y_0_z_xy_z_yz, g_y_0_y_0_z_xy_z_zz, g_yz_xy_yz_xx, g_yz_xy_yz_xy, g_yz_xy_yz_xz, g_yz_xy_yz_yy, g_yz_xy_yz_yz, g_yz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xy_z_xx[i] = 4.0 * g_yz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_z_xy[i] = 4.0 * g_yz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_z_xz[i] = 4.0 * g_yz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_z_yy[i] = 4.0 * g_yz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_z_yz[i] = 4.0 * g_yz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xy_z_zz[i] = 4.0 * g_yz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1548-1554)

    #pragma omp simd aligned(g_y_0_y_0_z_xz_x_xx, g_y_0_y_0_z_xz_x_xy, g_y_0_y_0_z_xz_x_xz, g_y_0_y_0_z_xz_x_yy, g_y_0_y_0_z_xz_x_yz, g_y_0_y_0_z_xz_x_zz, g_yz_xz_xy_xx, g_yz_xz_xy_xy, g_yz_xz_xy_xz, g_yz_xz_xy_yy, g_yz_xz_xy_yz, g_yz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xz_x_xx[i] = 4.0 * g_yz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_x_xy[i] = 4.0 * g_yz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_x_xz[i] = 4.0 * g_yz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_x_yy[i] = 4.0 * g_yz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_x_yz[i] = 4.0 * g_yz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_x_zz[i] = 4.0 * g_yz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1554-1560)

    #pragma omp simd aligned(g_y_0_y_0_z_xz_y_xx, g_y_0_y_0_z_xz_y_xy, g_y_0_y_0_z_xz_y_xz, g_y_0_y_0_z_xz_y_yy, g_y_0_y_0_z_xz_y_yz, g_y_0_y_0_z_xz_y_zz, g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_yy_xx, g_yz_xz_yy_xy, g_yz_xz_yy_xz, g_yz_xz_yy_yy, g_yz_xz_yy_yz, g_yz_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xz_y_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_y_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_y_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_y_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_y_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_y_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1560-1566)

    #pragma omp simd aligned(g_y_0_y_0_z_xz_z_xx, g_y_0_y_0_z_xz_z_xy, g_y_0_y_0_z_xz_z_xz, g_y_0_y_0_z_xz_z_yy, g_y_0_y_0_z_xz_z_yz, g_y_0_y_0_z_xz_z_zz, g_yz_xz_yz_xx, g_yz_xz_yz_xy, g_yz_xz_yz_xz, g_yz_xz_yz_yy, g_yz_xz_yz_yz, g_yz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_xz_z_xx[i] = 4.0 * g_yz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_z_xy[i] = 4.0 * g_yz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_z_xz[i] = 4.0 * g_yz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_z_yy[i] = 4.0 * g_yz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_z_yz[i] = 4.0 * g_yz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_xz_z_zz[i] = 4.0 * g_yz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1566-1572)

    #pragma omp simd aligned(g_y_0_y_0_z_yy_x_xx, g_y_0_y_0_z_yy_x_xy, g_y_0_y_0_z_yy_x_xz, g_y_0_y_0_z_yy_x_yy, g_y_0_y_0_z_yy_x_yz, g_y_0_y_0_z_yy_x_zz, g_yz_yy_xy_xx, g_yz_yy_xy_xy, g_yz_yy_xy_xz, g_yz_yy_xy_yy, g_yz_yy_xy_yz, g_yz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yy_x_xx[i] = 4.0 * g_yz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_x_xy[i] = 4.0 * g_yz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_x_xz[i] = 4.0 * g_yz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_x_yy[i] = 4.0 * g_yz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_x_yz[i] = 4.0 * g_yz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_x_zz[i] = 4.0 * g_yz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1572-1578)

    #pragma omp simd aligned(g_y_0_y_0_z_yy_y_xx, g_y_0_y_0_z_yy_y_xy, g_y_0_y_0_z_yy_y_xz, g_y_0_y_0_z_yy_y_yy, g_y_0_y_0_z_yy_y_yz, g_y_0_y_0_z_yy_y_zz, g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_yy_xx, g_yz_yy_yy_xy, g_yz_yy_yy_xz, g_yz_yy_yy_yy, g_yz_yy_yy_yz, g_yz_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yy_y_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_y_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_y_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_y_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_y_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_y_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1578-1584)

    #pragma omp simd aligned(g_y_0_y_0_z_yy_z_xx, g_y_0_y_0_z_yy_z_xy, g_y_0_y_0_z_yy_z_xz, g_y_0_y_0_z_yy_z_yy, g_y_0_y_0_z_yy_z_yz, g_y_0_y_0_z_yy_z_zz, g_yz_yy_yz_xx, g_yz_yy_yz_xy, g_yz_yy_yz_xz, g_yz_yy_yz_yy, g_yz_yy_yz_yz, g_yz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yy_z_xx[i] = 4.0 * g_yz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_z_xy[i] = 4.0 * g_yz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_z_xz[i] = 4.0 * g_yz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_z_yy[i] = 4.0 * g_yz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_z_yz[i] = 4.0 * g_yz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yy_z_zz[i] = 4.0 * g_yz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1584-1590)

    #pragma omp simd aligned(g_y_0_y_0_z_yz_x_xx, g_y_0_y_0_z_yz_x_xy, g_y_0_y_0_z_yz_x_xz, g_y_0_y_0_z_yz_x_yy, g_y_0_y_0_z_yz_x_yz, g_y_0_y_0_z_yz_x_zz, g_yz_yz_xy_xx, g_yz_yz_xy_xy, g_yz_yz_xy_xz, g_yz_yz_xy_yy, g_yz_yz_xy_yz, g_yz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yz_x_xx[i] = 4.0 * g_yz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_x_xy[i] = 4.0 * g_yz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_x_xz[i] = 4.0 * g_yz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_x_yy[i] = 4.0 * g_yz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_x_yz[i] = 4.0 * g_yz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_x_zz[i] = 4.0 * g_yz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1590-1596)

    #pragma omp simd aligned(g_y_0_y_0_z_yz_y_xx, g_y_0_y_0_z_yz_y_xy, g_y_0_y_0_z_yz_y_xz, g_y_0_y_0_z_yz_y_yy, g_y_0_y_0_z_yz_y_yz, g_y_0_y_0_z_yz_y_zz, g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_yy_xx, g_yz_yz_yy_xy, g_yz_yz_yy_xz, g_yz_yz_yy_yy, g_yz_yz_yy_yz, g_yz_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yz_y_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_y_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_y_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_y_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_y_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_y_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1596-1602)

    #pragma omp simd aligned(g_y_0_y_0_z_yz_z_xx, g_y_0_y_0_z_yz_z_xy, g_y_0_y_0_z_yz_z_xz, g_y_0_y_0_z_yz_z_yy, g_y_0_y_0_z_yz_z_yz, g_y_0_y_0_z_yz_z_zz, g_yz_yz_yz_xx, g_yz_yz_yz_xy, g_yz_yz_yz_xz, g_yz_yz_yz_yy, g_yz_yz_yz_yz, g_yz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_yz_z_xx[i] = 4.0 * g_yz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_z_xy[i] = 4.0 * g_yz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_z_xz[i] = 4.0 * g_yz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_z_yy[i] = 4.0 * g_yz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_z_yz[i] = 4.0 * g_yz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_yz_z_zz[i] = 4.0 * g_yz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1602-1608)

    #pragma omp simd aligned(g_y_0_y_0_z_zz_x_xx, g_y_0_y_0_z_zz_x_xy, g_y_0_y_0_z_zz_x_xz, g_y_0_y_0_z_zz_x_yy, g_y_0_y_0_z_zz_x_yz, g_y_0_y_0_z_zz_x_zz, g_yz_zz_xy_xx, g_yz_zz_xy_xy, g_yz_zz_xy_xz, g_yz_zz_xy_yy, g_yz_zz_xy_yz, g_yz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_zz_x_xx[i] = 4.0 * g_yz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_x_xy[i] = 4.0 * g_yz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_x_xz[i] = 4.0 * g_yz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_x_yy[i] = 4.0 * g_yz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_x_yz[i] = 4.0 * g_yz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_x_zz[i] = 4.0 * g_yz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1608-1614)

    #pragma omp simd aligned(g_y_0_y_0_z_zz_y_xx, g_y_0_y_0_z_zz_y_xy, g_y_0_y_0_z_zz_y_xz, g_y_0_y_0_z_zz_y_yy, g_y_0_y_0_z_zz_y_yz, g_y_0_y_0_z_zz_y_zz, g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_yy_xx, g_yz_zz_yy_xy, g_yz_zz_yy_xz, g_yz_zz_yy_yy, g_yz_zz_yy_yz, g_yz_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_zz_y_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_yy_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_y_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_yy_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_y_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_yy_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_y_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_yy_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_y_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_yy_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_y_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1614-1620)

    #pragma omp simd aligned(g_y_0_y_0_z_zz_z_xx, g_y_0_y_0_z_zz_z_xy, g_y_0_y_0_z_zz_z_xz, g_y_0_y_0_z_zz_z_yy, g_y_0_y_0_z_zz_z_yz, g_y_0_y_0_z_zz_z_zz, g_yz_zz_yz_xx, g_yz_zz_yz_xy, g_yz_zz_yz_xz, g_yz_zz_yz_yy, g_yz_zz_yz_yz, g_yz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_y_0_z_zz_z_xx[i] = 4.0 * g_yz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_z_xy[i] = 4.0 * g_yz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_z_xz[i] = 4.0 * g_yz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_z_yy[i] = 4.0 * g_yz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_z_yz[i] = 4.0 * g_yz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_y_0_z_zz_z_zz[i] = 4.0 * g_yz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1620-1626)

    #pragma omp simd aligned(g_xy_xx_xz_xx, g_xy_xx_xz_xy, g_xy_xx_xz_xz, g_xy_xx_xz_yy, g_xy_xx_xz_yz, g_xy_xx_xz_zz, g_y_0_z_0_x_xx_x_xx, g_y_0_z_0_x_xx_x_xy, g_y_0_z_0_x_xx_x_xz, g_y_0_z_0_x_xx_x_yy, g_y_0_z_0_x_xx_x_yz, g_y_0_z_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xx_x_xx[i] = 4.0 * g_xy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_x_xy[i] = 4.0 * g_xy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_x_xz[i] = 4.0 * g_xy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_x_yy[i] = 4.0 * g_xy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_x_yz[i] = 4.0 * g_xy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_x_zz[i] = 4.0 * g_xy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1626-1632)

    #pragma omp simd aligned(g_xy_xx_yz_xx, g_xy_xx_yz_xy, g_xy_xx_yz_xz, g_xy_xx_yz_yy, g_xy_xx_yz_yz, g_xy_xx_yz_zz, g_y_0_z_0_x_xx_y_xx, g_y_0_z_0_x_xx_y_xy, g_y_0_z_0_x_xx_y_xz, g_y_0_z_0_x_xx_y_yy, g_y_0_z_0_x_xx_y_yz, g_y_0_z_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xx_y_xx[i] = 4.0 * g_xy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_y_xy[i] = 4.0 * g_xy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_y_xz[i] = 4.0 * g_xy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_y_yy[i] = 4.0 * g_xy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_y_yz[i] = 4.0 * g_xy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_y_zz[i] = 4.0 * g_xy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1632-1638)

    #pragma omp simd aligned(g_xy_xx_0_xx, g_xy_xx_0_xy, g_xy_xx_0_xz, g_xy_xx_0_yy, g_xy_xx_0_yz, g_xy_xx_0_zz, g_xy_xx_zz_xx, g_xy_xx_zz_xy, g_xy_xx_zz_xz, g_xy_xx_zz_yy, g_xy_xx_zz_yz, g_xy_xx_zz_zz, g_y_0_z_0_x_xx_z_xx, g_y_0_z_0_x_xx_z_xy, g_y_0_z_0_x_xx_z_xz, g_y_0_z_0_x_xx_z_yy, g_y_0_z_0_x_xx_z_yz, g_y_0_z_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xx_z_xx[i] = -2.0 * g_xy_xx_0_xx[i] * a_exp + 4.0 * g_xy_xx_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_z_xy[i] = -2.0 * g_xy_xx_0_xy[i] * a_exp + 4.0 * g_xy_xx_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_z_xz[i] = -2.0 * g_xy_xx_0_xz[i] * a_exp + 4.0 * g_xy_xx_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_z_yy[i] = -2.0 * g_xy_xx_0_yy[i] * a_exp + 4.0 * g_xy_xx_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_z_yz[i] = -2.0 * g_xy_xx_0_yz[i] * a_exp + 4.0 * g_xy_xx_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xx_z_zz[i] = -2.0 * g_xy_xx_0_zz[i] * a_exp + 4.0 * g_xy_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1638-1644)

    #pragma omp simd aligned(g_xy_xy_xz_xx, g_xy_xy_xz_xy, g_xy_xy_xz_xz, g_xy_xy_xz_yy, g_xy_xy_xz_yz, g_xy_xy_xz_zz, g_y_0_z_0_x_xy_x_xx, g_y_0_z_0_x_xy_x_xy, g_y_0_z_0_x_xy_x_xz, g_y_0_z_0_x_xy_x_yy, g_y_0_z_0_x_xy_x_yz, g_y_0_z_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xy_x_xx[i] = 4.0 * g_xy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_x_xy[i] = 4.0 * g_xy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_x_xz[i] = 4.0 * g_xy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_x_yy[i] = 4.0 * g_xy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_x_yz[i] = 4.0 * g_xy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_x_zz[i] = 4.0 * g_xy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1644-1650)

    #pragma omp simd aligned(g_xy_xy_yz_xx, g_xy_xy_yz_xy, g_xy_xy_yz_xz, g_xy_xy_yz_yy, g_xy_xy_yz_yz, g_xy_xy_yz_zz, g_y_0_z_0_x_xy_y_xx, g_y_0_z_0_x_xy_y_xy, g_y_0_z_0_x_xy_y_xz, g_y_0_z_0_x_xy_y_yy, g_y_0_z_0_x_xy_y_yz, g_y_0_z_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xy_y_xx[i] = 4.0 * g_xy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_y_xy[i] = 4.0 * g_xy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_y_xz[i] = 4.0 * g_xy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_y_yy[i] = 4.0 * g_xy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_y_yz[i] = 4.0 * g_xy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_y_zz[i] = 4.0 * g_xy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1650-1656)

    #pragma omp simd aligned(g_xy_xy_0_xx, g_xy_xy_0_xy, g_xy_xy_0_xz, g_xy_xy_0_yy, g_xy_xy_0_yz, g_xy_xy_0_zz, g_xy_xy_zz_xx, g_xy_xy_zz_xy, g_xy_xy_zz_xz, g_xy_xy_zz_yy, g_xy_xy_zz_yz, g_xy_xy_zz_zz, g_y_0_z_0_x_xy_z_xx, g_y_0_z_0_x_xy_z_xy, g_y_0_z_0_x_xy_z_xz, g_y_0_z_0_x_xy_z_yy, g_y_0_z_0_x_xy_z_yz, g_y_0_z_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xy_z_xx[i] = -2.0 * g_xy_xy_0_xx[i] * a_exp + 4.0 * g_xy_xy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_z_xy[i] = -2.0 * g_xy_xy_0_xy[i] * a_exp + 4.0 * g_xy_xy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_z_xz[i] = -2.0 * g_xy_xy_0_xz[i] * a_exp + 4.0 * g_xy_xy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_z_yy[i] = -2.0 * g_xy_xy_0_yy[i] * a_exp + 4.0 * g_xy_xy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_z_yz[i] = -2.0 * g_xy_xy_0_yz[i] * a_exp + 4.0 * g_xy_xy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xy_z_zz[i] = -2.0 * g_xy_xy_0_zz[i] * a_exp + 4.0 * g_xy_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1656-1662)

    #pragma omp simd aligned(g_xy_xz_xz_xx, g_xy_xz_xz_xy, g_xy_xz_xz_xz, g_xy_xz_xz_yy, g_xy_xz_xz_yz, g_xy_xz_xz_zz, g_y_0_z_0_x_xz_x_xx, g_y_0_z_0_x_xz_x_xy, g_y_0_z_0_x_xz_x_xz, g_y_0_z_0_x_xz_x_yy, g_y_0_z_0_x_xz_x_yz, g_y_0_z_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xz_x_xx[i] = 4.0 * g_xy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_x_xy[i] = 4.0 * g_xy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_x_xz[i] = 4.0 * g_xy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_x_yy[i] = 4.0 * g_xy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_x_yz[i] = 4.0 * g_xy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_x_zz[i] = 4.0 * g_xy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1662-1668)

    #pragma omp simd aligned(g_xy_xz_yz_xx, g_xy_xz_yz_xy, g_xy_xz_yz_xz, g_xy_xz_yz_yy, g_xy_xz_yz_yz, g_xy_xz_yz_zz, g_y_0_z_0_x_xz_y_xx, g_y_0_z_0_x_xz_y_xy, g_y_0_z_0_x_xz_y_xz, g_y_0_z_0_x_xz_y_yy, g_y_0_z_0_x_xz_y_yz, g_y_0_z_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xz_y_xx[i] = 4.0 * g_xy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_y_xy[i] = 4.0 * g_xy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_y_xz[i] = 4.0 * g_xy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_y_yy[i] = 4.0 * g_xy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_y_yz[i] = 4.0 * g_xy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_y_zz[i] = 4.0 * g_xy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1668-1674)

    #pragma omp simd aligned(g_xy_xz_0_xx, g_xy_xz_0_xy, g_xy_xz_0_xz, g_xy_xz_0_yy, g_xy_xz_0_yz, g_xy_xz_0_zz, g_xy_xz_zz_xx, g_xy_xz_zz_xy, g_xy_xz_zz_xz, g_xy_xz_zz_yy, g_xy_xz_zz_yz, g_xy_xz_zz_zz, g_y_0_z_0_x_xz_z_xx, g_y_0_z_0_x_xz_z_xy, g_y_0_z_0_x_xz_z_xz, g_y_0_z_0_x_xz_z_yy, g_y_0_z_0_x_xz_z_yz, g_y_0_z_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_xz_z_xx[i] = -2.0 * g_xy_xz_0_xx[i] * a_exp + 4.0 * g_xy_xz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_z_xy[i] = -2.0 * g_xy_xz_0_xy[i] * a_exp + 4.0 * g_xy_xz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_z_xz[i] = -2.0 * g_xy_xz_0_xz[i] * a_exp + 4.0 * g_xy_xz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_z_yy[i] = -2.0 * g_xy_xz_0_yy[i] * a_exp + 4.0 * g_xy_xz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_z_yz[i] = -2.0 * g_xy_xz_0_yz[i] * a_exp + 4.0 * g_xy_xz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_xz_z_zz[i] = -2.0 * g_xy_xz_0_zz[i] * a_exp + 4.0 * g_xy_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1674-1680)

    #pragma omp simd aligned(g_xy_yy_xz_xx, g_xy_yy_xz_xy, g_xy_yy_xz_xz, g_xy_yy_xz_yy, g_xy_yy_xz_yz, g_xy_yy_xz_zz, g_y_0_z_0_x_yy_x_xx, g_y_0_z_0_x_yy_x_xy, g_y_0_z_0_x_yy_x_xz, g_y_0_z_0_x_yy_x_yy, g_y_0_z_0_x_yy_x_yz, g_y_0_z_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yy_x_xx[i] = 4.0 * g_xy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_x_xy[i] = 4.0 * g_xy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_x_xz[i] = 4.0 * g_xy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_x_yy[i] = 4.0 * g_xy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_x_yz[i] = 4.0 * g_xy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_x_zz[i] = 4.0 * g_xy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1680-1686)

    #pragma omp simd aligned(g_xy_yy_yz_xx, g_xy_yy_yz_xy, g_xy_yy_yz_xz, g_xy_yy_yz_yy, g_xy_yy_yz_yz, g_xy_yy_yz_zz, g_y_0_z_0_x_yy_y_xx, g_y_0_z_0_x_yy_y_xy, g_y_0_z_0_x_yy_y_xz, g_y_0_z_0_x_yy_y_yy, g_y_0_z_0_x_yy_y_yz, g_y_0_z_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yy_y_xx[i] = 4.0 * g_xy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_y_xy[i] = 4.0 * g_xy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_y_xz[i] = 4.0 * g_xy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_y_yy[i] = 4.0 * g_xy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_y_yz[i] = 4.0 * g_xy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_y_zz[i] = 4.0 * g_xy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1686-1692)

    #pragma omp simd aligned(g_xy_yy_0_xx, g_xy_yy_0_xy, g_xy_yy_0_xz, g_xy_yy_0_yy, g_xy_yy_0_yz, g_xy_yy_0_zz, g_xy_yy_zz_xx, g_xy_yy_zz_xy, g_xy_yy_zz_xz, g_xy_yy_zz_yy, g_xy_yy_zz_yz, g_xy_yy_zz_zz, g_y_0_z_0_x_yy_z_xx, g_y_0_z_0_x_yy_z_xy, g_y_0_z_0_x_yy_z_xz, g_y_0_z_0_x_yy_z_yy, g_y_0_z_0_x_yy_z_yz, g_y_0_z_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yy_z_xx[i] = -2.0 * g_xy_yy_0_xx[i] * a_exp + 4.0 * g_xy_yy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_z_xy[i] = -2.0 * g_xy_yy_0_xy[i] * a_exp + 4.0 * g_xy_yy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_z_xz[i] = -2.0 * g_xy_yy_0_xz[i] * a_exp + 4.0 * g_xy_yy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_z_yy[i] = -2.0 * g_xy_yy_0_yy[i] * a_exp + 4.0 * g_xy_yy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_z_yz[i] = -2.0 * g_xy_yy_0_yz[i] * a_exp + 4.0 * g_xy_yy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yy_z_zz[i] = -2.0 * g_xy_yy_0_zz[i] * a_exp + 4.0 * g_xy_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1692-1698)

    #pragma omp simd aligned(g_xy_yz_xz_xx, g_xy_yz_xz_xy, g_xy_yz_xz_xz, g_xy_yz_xz_yy, g_xy_yz_xz_yz, g_xy_yz_xz_zz, g_y_0_z_0_x_yz_x_xx, g_y_0_z_0_x_yz_x_xy, g_y_0_z_0_x_yz_x_xz, g_y_0_z_0_x_yz_x_yy, g_y_0_z_0_x_yz_x_yz, g_y_0_z_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yz_x_xx[i] = 4.0 * g_xy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_x_xy[i] = 4.0 * g_xy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_x_xz[i] = 4.0 * g_xy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_x_yy[i] = 4.0 * g_xy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_x_yz[i] = 4.0 * g_xy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_x_zz[i] = 4.0 * g_xy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1698-1704)

    #pragma omp simd aligned(g_xy_yz_yz_xx, g_xy_yz_yz_xy, g_xy_yz_yz_xz, g_xy_yz_yz_yy, g_xy_yz_yz_yz, g_xy_yz_yz_zz, g_y_0_z_0_x_yz_y_xx, g_y_0_z_0_x_yz_y_xy, g_y_0_z_0_x_yz_y_xz, g_y_0_z_0_x_yz_y_yy, g_y_0_z_0_x_yz_y_yz, g_y_0_z_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yz_y_xx[i] = 4.0 * g_xy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_y_xy[i] = 4.0 * g_xy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_y_xz[i] = 4.0 * g_xy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_y_yy[i] = 4.0 * g_xy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_y_yz[i] = 4.0 * g_xy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_y_zz[i] = 4.0 * g_xy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1704-1710)

    #pragma omp simd aligned(g_xy_yz_0_xx, g_xy_yz_0_xy, g_xy_yz_0_xz, g_xy_yz_0_yy, g_xy_yz_0_yz, g_xy_yz_0_zz, g_xy_yz_zz_xx, g_xy_yz_zz_xy, g_xy_yz_zz_xz, g_xy_yz_zz_yy, g_xy_yz_zz_yz, g_xy_yz_zz_zz, g_y_0_z_0_x_yz_z_xx, g_y_0_z_0_x_yz_z_xy, g_y_0_z_0_x_yz_z_xz, g_y_0_z_0_x_yz_z_yy, g_y_0_z_0_x_yz_z_yz, g_y_0_z_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_yz_z_xx[i] = -2.0 * g_xy_yz_0_xx[i] * a_exp + 4.0 * g_xy_yz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_z_xy[i] = -2.0 * g_xy_yz_0_xy[i] * a_exp + 4.0 * g_xy_yz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_z_xz[i] = -2.0 * g_xy_yz_0_xz[i] * a_exp + 4.0 * g_xy_yz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_z_yy[i] = -2.0 * g_xy_yz_0_yy[i] * a_exp + 4.0 * g_xy_yz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_z_yz[i] = -2.0 * g_xy_yz_0_yz[i] * a_exp + 4.0 * g_xy_yz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_yz_z_zz[i] = -2.0 * g_xy_yz_0_zz[i] * a_exp + 4.0 * g_xy_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1710-1716)

    #pragma omp simd aligned(g_xy_zz_xz_xx, g_xy_zz_xz_xy, g_xy_zz_xz_xz, g_xy_zz_xz_yy, g_xy_zz_xz_yz, g_xy_zz_xz_zz, g_y_0_z_0_x_zz_x_xx, g_y_0_z_0_x_zz_x_xy, g_y_0_z_0_x_zz_x_xz, g_y_0_z_0_x_zz_x_yy, g_y_0_z_0_x_zz_x_yz, g_y_0_z_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_zz_x_xx[i] = 4.0 * g_xy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_x_xy[i] = 4.0 * g_xy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_x_xz[i] = 4.0 * g_xy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_x_yy[i] = 4.0 * g_xy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_x_yz[i] = 4.0 * g_xy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_x_zz[i] = 4.0 * g_xy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1716-1722)

    #pragma omp simd aligned(g_xy_zz_yz_xx, g_xy_zz_yz_xy, g_xy_zz_yz_xz, g_xy_zz_yz_yy, g_xy_zz_yz_yz, g_xy_zz_yz_zz, g_y_0_z_0_x_zz_y_xx, g_y_0_z_0_x_zz_y_xy, g_y_0_z_0_x_zz_y_xz, g_y_0_z_0_x_zz_y_yy, g_y_0_z_0_x_zz_y_yz, g_y_0_z_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_zz_y_xx[i] = 4.0 * g_xy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_y_xy[i] = 4.0 * g_xy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_y_xz[i] = 4.0 * g_xy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_y_yy[i] = 4.0 * g_xy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_y_yz[i] = 4.0 * g_xy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_y_zz[i] = 4.0 * g_xy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1722-1728)

    #pragma omp simd aligned(g_xy_zz_0_xx, g_xy_zz_0_xy, g_xy_zz_0_xz, g_xy_zz_0_yy, g_xy_zz_0_yz, g_xy_zz_0_zz, g_xy_zz_zz_xx, g_xy_zz_zz_xy, g_xy_zz_zz_xz, g_xy_zz_zz_yy, g_xy_zz_zz_yz, g_xy_zz_zz_zz, g_y_0_z_0_x_zz_z_xx, g_y_0_z_0_x_zz_z_xy, g_y_0_z_0_x_zz_z_xz, g_y_0_z_0_x_zz_z_yy, g_y_0_z_0_x_zz_z_yz, g_y_0_z_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_x_zz_z_xx[i] = -2.0 * g_xy_zz_0_xx[i] * a_exp + 4.0 * g_xy_zz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_z_xy[i] = -2.0 * g_xy_zz_0_xy[i] * a_exp + 4.0 * g_xy_zz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_z_xz[i] = -2.0 * g_xy_zz_0_xz[i] * a_exp + 4.0 * g_xy_zz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_z_yy[i] = -2.0 * g_xy_zz_0_yy[i] * a_exp + 4.0 * g_xy_zz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_z_yz[i] = -2.0 * g_xy_zz_0_yz[i] * a_exp + 4.0 * g_xy_zz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_x_zz_z_zz[i] = -2.0 * g_xy_zz_0_zz[i] * a_exp + 4.0 * g_xy_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1728-1734)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_y_0_z_0_y_xx_x_xx, g_y_0_z_0_y_xx_x_xy, g_y_0_z_0_y_xx_x_xz, g_y_0_z_0_y_xx_x_yy, g_y_0_z_0_y_xx_x_yz, g_y_0_z_0_y_xx_x_zz, g_yy_xx_xz_xx, g_yy_xx_xz_xy, g_yy_xx_xz_xz, g_yy_xx_xz_yy, g_yy_xx_xz_yz, g_yy_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xx_x_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_x_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_x_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_x_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_x_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_x_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1734-1740)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_y_0_z_0_y_xx_y_xx, g_y_0_z_0_y_xx_y_xy, g_y_0_z_0_y_xx_y_xz, g_y_0_z_0_y_xx_y_yy, g_y_0_z_0_y_xx_y_yz, g_y_0_z_0_y_xx_y_zz, g_yy_xx_yz_xx, g_yy_xx_yz_xy, g_yy_xx_yz_xz, g_yy_xx_yz_yy, g_yy_xx_yz_yz, g_yy_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xx_y_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_y_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_y_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_y_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_y_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_y_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1740-1746)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_zz_xx, g_0_xx_zz_xy, g_0_xx_zz_xz, g_0_xx_zz_yy, g_0_xx_zz_yz, g_0_xx_zz_zz, g_y_0_z_0_y_xx_z_xx, g_y_0_z_0_y_xx_z_xy, g_y_0_z_0_y_xx_z_xz, g_y_0_z_0_y_xx_z_yy, g_y_0_z_0_y_xx_z_yz, g_y_0_z_0_y_xx_z_zz, g_yy_xx_0_xx, g_yy_xx_0_xy, g_yy_xx_0_xz, g_yy_xx_0_yy, g_yy_xx_0_yz, g_yy_xx_0_zz, g_yy_xx_zz_xx, g_yy_xx_zz_xy, g_yy_xx_zz_xz, g_yy_xx_zz_yy, g_yy_xx_zz_yz, g_yy_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xx_z_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_zz_xx[i] * c_exps[i] - 2.0 * g_yy_xx_0_xx[i] * a_exp + 4.0 * g_yy_xx_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_z_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_zz_xy[i] * c_exps[i] - 2.0 * g_yy_xx_0_xy[i] * a_exp + 4.0 * g_yy_xx_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_z_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_zz_xz[i] * c_exps[i] - 2.0 * g_yy_xx_0_xz[i] * a_exp + 4.0 * g_yy_xx_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_z_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_zz_yy[i] * c_exps[i] - 2.0 * g_yy_xx_0_yy[i] * a_exp + 4.0 * g_yy_xx_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_z_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_zz_yz[i] * c_exps[i] - 2.0 * g_yy_xx_0_yz[i] * a_exp + 4.0 * g_yy_xx_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xx_z_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_zz_zz[i] * c_exps[i] - 2.0 * g_yy_xx_0_zz[i] * a_exp + 4.0 * g_yy_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1746-1752)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_y_0_z_0_y_xy_x_xx, g_y_0_z_0_y_xy_x_xy, g_y_0_z_0_y_xy_x_xz, g_y_0_z_0_y_xy_x_yy, g_y_0_z_0_y_xy_x_yz, g_y_0_z_0_y_xy_x_zz, g_yy_xy_xz_xx, g_yy_xy_xz_xy, g_yy_xy_xz_xz, g_yy_xy_xz_yy, g_yy_xy_xz_yz, g_yy_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xy_x_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_x_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_x_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_x_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_x_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_x_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1752-1758)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_y_0_z_0_y_xy_y_xx, g_y_0_z_0_y_xy_y_xy, g_y_0_z_0_y_xy_y_xz, g_y_0_z_0_y_xy_y_yy, g_y_0_z_0_y_xy_y_yz, g_y_0_z_0_y_xy_y_zz, g_yy_xy_yz_xx, g_yy_xy_yz_xy, g_yy_xy_yz_xz, g_yy_xy_yz_yy, g_yy_xy_yz_yz, g_yy_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xy_y_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_y_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_y_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_y_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_y_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_y_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1758-1764)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_zz_xx, g_0_xy_zz_xy, g_0_xy_zz_xz, g_0_xy_zz_yy, g_0_xy_zz_yz, g_0_xy_zz_zz, g_y_0_z_0_y_xy_z_xx, g_y_0_z_0_y_xy_z_xy, g_y_0_z_0_y_xy_z_xz, g_y_0_z_0_y_xy_z_yy, g_y_0_z_0_y_xy_z_yz, g_y_0_z_0_y_xy_z_zz, g_yy_xy_0_xx, g_yy_xy_0_xy, g_yy_xy_0_xz, g_yy_xy_0_yy, g_yy_xy_0_yz, g_yy_xy_0_zz, g_yy_xy_zz_xx, g_yy_xy_zz_xy, g_yy_xy_zz_xz, g_yy_xy_zz_yy, g_yy_xy_zz_yz, g_yy_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xy_z_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_zz_xx[i] * c_exps[i] - 2.0 * g_yy_xy_0_xx[i] * a_exp + 4.0 * g_yy_xy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_z_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_zz_xy[i] * c_exps[i] - 2.0 * g_yy_xy_0_xy[i] * a_exp + 4.0 * g_yy_xy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_z_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_zz_xz[i] * c_exps[i] - 2.0 * g_yy_xy_0_xz[i] * a_exp + 4.0 * g_yy_xy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_z_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_zz_yy[i] * c_exps[i] - 2.0 * g_yy_xy_0_yy[i] * a_exp + 4.0 * g_yy_xy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_z_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_zz_yz[i] * c_exps[i] - 2.0 * g_yy_xy_0_yz[i] * a_exp + 4.0 * g_yy_xy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xy_z_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_zz_zz[i] * c_exps[i] - 2.0 * g_yy_xy_0_zz[i] * a_exp + 4.0 * g_yy_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1764-1770)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_y_0_z_0_y_xz_x_xx, g_y_0_z_0_y_xz_x_xy, g_y_0_z_0_y_xz_x_xz, g_y_0_z_0_y_xz_x_yy, g_y_0_z_0_y_xz_x_yz, g_y_0_z_0_y_xz_x_zz, g_yy_xz_xz_xx, g_yy_xz_xz_xy, g_yy_xz_xz_xz, g_yy_xz_xz_yy, g_yy_xz_xz_yz, g_yy_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xz_x_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_x_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_x_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_x_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_x_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_x_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1770-1776)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_y_0_z_0_y_xz_y_xx, g_y_0_z_0_y_xz_y_xy, g_y_0_z_0_y_xz_y_xz, g_y_0_z_0_y_xz_y_yy, g_y_0_z_0_y_xz_y_yz, g_y_0_z_0_y_xz_y_zz, g_yy_xz_yz_xx, g_yy_xz_yz_xy, g_yy_xz_yz_xz, g_yy_xz_yz_yy, g_yy_xz_yz_yz, g_yy_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xz_y_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_y_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_y_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_y_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_y_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_y_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1776-1782)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_zz_xx, g_0_xz_zz_xy, g_0_xz_zz_xz, g_0_xz_zz_yy, g_0_xz_zz_yz, g_0_xz_zz_zz, g_y_0_z_0_y_xz_z_xx, g_y_0_z_0_y_xz_z_xy, g_y_0_z_0_y_xz_z_xz, g_y_0_z_0_y_xz_z_yy, g_y_0_z_0_y_xz_z_yz, g_y_0_z_0_y_xz_z_zz, g_yy_xz_0_xx, g_yy_xz_0_xy, g_yy_xz_0_xz, g_yy_xz_0_yy, g_yy_xz_0_yz, g_yy_xz_0_zz, g_yy_xz_zz_xx, g_yy_xz_zz_xy, g_yy_xz_zz_xz, g_yy_xz_zz_yy, g_yy_xz_zz_yz, g_yy_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_xz_z_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_zz_xx[i] * c_exps[i] - 2.0 * g_yy_xz_0_xx[i] * a_exp + 4.0 * g_yy_xz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_z_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_zz_xy[i] * c_exps[i] - 2.0 * g_yy_xz_0_xy[i] * a_exp + 4.0 * g_yy_xz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_z_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_zz_xz[i] * c_exps[i] - 2.0 * g_yy_xz_0_xz[i] * a_exp + 4.0 * g_yy_xz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_z_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_zz_yy[i] * c_exps[i] - 2.0 * g_yy_xz_0_yy[i] * a_exp + 4.0 * g_yy_xz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_z_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_zz_yz[i] * c_exps[i] - 2.0 * g_yy_xz_0_yz[i] * a_exp + 4.0 * g_yy_xz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_xz_z_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_zz_zz[i] * c_exps[i] - 2.0 * g_yy_xz_0_zz[i] * a_exp + 4.0 * g_yy_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1782-1788)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_y_0_z_0_y_yy_x_xx, g_y_0_z_0_y_yy_x_xy, g_y_0_z_0_y_yy_x_xz, g_y_0_z_0_y_yy_x_yy, g_y_0_z_0_y_yy_x_yz, g_y_0_z_0_y_yy_x_zz, g_yy_yy_xz_xx, g_yy_yy_xz_xy, g_yy_yy_xz_xz, g_yy_yy_xz_yy, g_yy_yy_xz_yz, g_yy_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yy_x_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_x_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_x_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_x_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_yy_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_x_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_x_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_yy_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1788-1794)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_y_0_z_0_y_yy_y_xx, g_y_0_z_0_y_yy_y_xy, g_y_0_z_0_y_yy_y_xz, g_y_0_z_0_y_yy_y_yy, g_y_0_z_0_y_yy_y_yz, g_y_0_z_0_y_yy_y_zz, g_yy_yy_yz_xx, g_yy_yy_yz_xy, g_yy_yy_yz_xz, g_yy_yy_yz_yy, g_yy_yy_yz_yz, g_yy_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yy_y_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_y_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_y_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_y_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_yy_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_y_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_y_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_yy_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1794-1800)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_zz_xx, g_0_yy_zz_xy, g_0_yy_zz_xz, g_0_yy_zz_yy, g_0_yy_zz_yz, g_0_yy_zz_zz, g_y_0_z_0_y_yy_z_xx, g_y_0_z_0_y_yy_z_xy, g_y_0_z_0_y_yy_z_xz, g_y_0_z_0_y_yy_z_yy, g_y_0_z_0_y_yy_z_yz, g_y_0_z_0_y_yy_z_zz, g_yy_yy_0_xx, g_yy_yy_0_xy, g_yy_yy_0_xz, g_yy_yy_0_yy, g_yy_yy_0_yz, g_yy_yy_0_zz, g_yy_yy_zz_xx, g_yy_yy_zz_xy, g_yy_yy_zz_xz, g_yy_yy_zz_yy, g_yy_yy_zz_yz, g_yy_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yy_z_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_zz_xx[i] * c_exps[i] - 2.0 * g_yy_yy_0_xx[i] * a_exp + 4.0 * g_yy_yy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_z_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_zz_xy[i] * c_exps[i] - 2.0 * g_yy_yy_0_xy[i] * a_exp + 4.0 * g_yy_yy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_z_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_zz_xz[i] * c_exps[i] - 2.0 * g_yy_yy_0_xz[i] * a_exp + 4.0 * g_yy_yy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_z_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_zz_yy[i] * c_exps[i] - 2.0 * g_yy_yy_0_yy[i] * a_exp + 4.0 * g_yy_yy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_z_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_zz_yz[i] * c_exps[i] - 2.0 * g_yy_yy_0_yz[i] * a_exp + 4.0 * g_yy_yy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yy_z_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_zz_zz[i] * c_exps[i] - 2.0 * g_yy_yy_0_zz[i] * a_exp + 4.0 * g_yy_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1800-1806)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_y_0_z_0_y_yz_x_xx, g_y_0_z_0_y_yz_x_xy, g_y_0_z_0_y_yz_x_xz, g_y_0_z_0_y_yz_x_yy, g_y_0_z_0_y_yz_x_yz, g_y_0_z_0_y_yz_x_zz, g_yy_yz_xz_xx, g_yy_yz_xz_xy, g_yy_yz_xz_xz, g_yy_yz_xz_yy, g_yy_yz_xz_yz, g_yy_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yz_x_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_x_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_x_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_x_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_x_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_x_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1806-1812)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_y_0_z_0_y_yz_y_xx, g_y_0_z_0_y_yz_y_xy, g_y_0_z_0_y_yz_y_xz, g_y_0_z_0_y_yz_y_yy, g_y_0_z_0_y_yz_y_yz, g_y_0_z_0_y_yz_y_zz, g_yy_yz_yz_xx, g_yy_yz_yz_xy, g_yy_yz_yz_xz, g_yy_yz_yz_yy, g_yy_yz_yz_yz, g_yy_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yz_y_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_y_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_y_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_y_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_y_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_y_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1812-1818)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_zz_xx, g_0_yz_zz_xy, g_0_yz_zz_xz, g_0_yz_zz_yy, g_0_yz_zz_yz, g_0_yz_zz_zz, g_y_0_z_0_y_yz_z_xx, g_y_0_z_0_y_yz_z_xy, g_y_0_z_0_y_yz_z_xz, g_y_0_z_0_y_yz_z_yy, g_y_0_z_0_y_yz_z_yz, g_y_0_z_0_y_yz_z_zz, g_yy_yz_0_xx, g_yy_yz_0_xy, g_yy_yz_0_xz, g_yy_yz_0_yy, g_yy_yz_0_yz, g_yy_yz_0_zz, g_yy_yz_zz_xx, g_yy_yz_zz_xy, g_yy_yz_zz_xz, g_yy_yz_zz_yy, g_yy_yz_zz_yz, g_yy_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_yz_z_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_zz_xx[i] * c_exps[i] - 2.0 * g_yy_yz_0_xx[i] * a_exp + 4.0 * g_yy_yz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_z_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_zz_xy[i] * c_exps[i] - 2.0 * g_yy_yz_0_xy[i] * a_exp + 4.0 * g_yy_yz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_z_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_zz_xz[i] * c_exps[i] - 2.0 * g_yy_yz_0_xz[i] * a_exp + 4.0 * g_yy_yz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_z_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_zz_yy[i] * c_exps[i] - 2.0 * g_yy_yz_0_yy[i] * a_exp + 4.0 * g_yy_yz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_z_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_zz_yz[i] * c_exps[i] - 2.0 * g_yy_yz_0_yz[i] * a_exp + 4.0 * g_yy_yz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_yz_z_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_zz_zz[i] * c_exps[i] - 2.0 * g_yy_yz_0_zz[i] * a_exp + 4.0 * g_yy_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1818-1824)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_y_0_z_0_y_zz_x_xx, g_y_0_z_0_y_zz_x_xy, g_y_0_z_0_y_zz_x_xz, g_y_0_z_0_y_zz_x_yy, g_y_0_z_0_y_zz_x_yz, g_y_0_z_0_y_zz_x_zz, g_yy_zz_xz_xx, g_yy_zz_xz_xy, g_yy_zz_xz_xz, g_yy_zz_xz_yy, g_yy_zz_xz_yz, g_yy_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_zz_x_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_x_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_x_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_x_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_yy_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_x_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_x_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_yy_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1824-1830)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_y_0_z_0_y_zz_y_xx, g_y_0_z_0_y_zz_y_xy, g_y_0_z_0_y_zz_y_xz, g_y_0_z_0_y_zz_y_yy, g_y_0_z_0_y_zz_y_yz, g_y_0_z_0_y_zz_y_zz, g_yy_zz_yz_xx, g_yy_zz_yz_xy, g_yy_zz_yz_xz, g_yy_zz_yz_yy, g_yy_zz_yz_yz, g_yy_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_zz_y_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_y_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_y_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_y_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_yy_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_y_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_y_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_yy_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1830-1836)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_zz_xx, g_0_zz_zz_xy, g_0_zz_zz_xz, g_0_zz_zz_yy, g_0_zz_zz_yz, g_0_zz_zz_zz, g_y_0_z_0_y_zz_z_xx, g_y_0_z_0_y_zz_z_xy, g_y_0_z_0_y_zz_z_xz, g_y_0_z_0_y_zz_z_yy, g_y_0_z_0_y_zz_z_yz, g_y_0_z_0_y_zz_z_zz, g_yy_zz_0_xx, g_yy_zz_0_xy, g_yy_zz_0_xz, g_yy_zz_0_yy, g_yy_zz_0_yz, g_yy_zz_0_zz, g_yy_zz_zz_xx, g_yy_zz_zz_xy, g_yy_zz_zz_xz, g_yy_zz_zz_yy, g_yy_zz_zz_yz, g_yy_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_y_zz_z_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_zz_xx[i] * c_exps[i] - 2.0 * g_yy_zz_0_xx[i] * a_exp + 4.0 * g_yy_zz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_z_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_zz_xy[i] * c_exps[i] - 2.0 * g_yy_zz_0_xy[i] * a_exp + 4.0 * g_yy_zz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_z_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_zz_xz[i] * c_exps[i] - 2.0 * g_yy_zz_0_xz[i] * a_exp + 4.0 * g_yy_zz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_z_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_zz_yy[i] * c_exps[i] - 2.0 * g_yy_zz_0_yy[i] * a_exp + 4.0 * g_yy_zz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_z_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_zz_yz[i] * c_exps[i] - 2.0 * g_yy_zz_0_yz[i] * a_exp + 4.0 * g_yy_zz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_y_zz_z_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_zz_zz[i] * c_exps[i] - 2.0 * g_yy_zz_0_zz[i] * a_exp + 4.0 * g_yy_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1836-1842)

    #pragma omp simd aligned(g_y_0_z_0_z_xx_x_xx, g_y_0_z_0_z_xx_x_xy, g_y_0_z_0_z_xx_x_xz, g_y_0_z_0_z_xx_x_yy, g_y_0_z_0_z_xx_x_yz, g_y_0_z_0_z_xx_x_zz, g_yz_xx_xz_xx, g_yz_xx_xz_xy, g_yz_xx_xz_xz, g_yz_xx_xz_yy, g_yz_xx_xz_yz, g_yz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xx_x_xx[i] = 4.0 * g_yz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_x_xy[i] = 4.0 * g_yz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_x_xz[i] = 4.0 * g_yz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_x_yy[i] = 4.0 * g_yz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_x_yz[i] = 4.0 * g_yz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_x_zz[i] = 4.0 * g_yz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1842-1848)

    #pragma omp simd aligned(g_y_0_z_0_z_xx_y_xx, g_y_0_z_0_z_xx_y_xy, g_y_0_z_0_z_xx_y_xz, g_y_0_z_0_z_xx_y_yy, g_y_0_z_0_z_xx_y_yz, g_y_0_z_0_z_xx_y_zz, g_yz_xx_yz_xx, g_yz_xx_yz_xy, g_yz_xx_yz_xz, g_yz_xx_yz_yy, g_yz_xx_yz_yz, g_yz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xx_y_xx[i] = 4.0 * g_yz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_y_xy[i] = 4.0 * g_yz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_y_xz[i] = 4.0 * g_yz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_y_yy[i] = 4.0 * g_yz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_y_yz[i] = 4.0 * g_yz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_y_zz[i] = 4.0 * g_yz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1848-1854)

    #pragma omp simd aligned(g_y_0_z_0_z_xx_z_xx, g_y_0_z_0_z_xx_z_xy, g_y_0_z_0_z_xx_z_xz, g_y_0_z_0_z_xx_z_yy, g_y_0_z_0_z_xx_z_yz, g_y_0_z_0_z_xx_z_zz, g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_zz_xx, g_yz_xx_zz_xy, g_yz_xx_zz_xz, g_yz_xx_zz_yy, g_yz_xx_zz_yz, g_yz_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xx_z_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_z_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_z_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_z_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_z_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xx_z_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1854-1860)

    #pragma omp simd aligned(g_y_0_z_0_z_xy_x_xx, g_y_0_z_0_z_xy_x_xy, g_y_0_z_0_z_xy_x_xz, g_y_0_z_0_z_xy_x_yy, g_y_0_z_0_z_xy_x_yz, g_y_0_z_0_z_xy_x_zz, g_yz_xy_xz_xx, g_yz_xy_xz_xy, g_yz_xy_xz_xz, g_yz_xy_xz_yy, g_yz_xy_xz_yz, g_yz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xy_x_xx[i] = 4.0 * g_yz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_x_xy[i] = 4.0 * g_yz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_x_xz[i] = 4.0 * g_yz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_x_yy[i] = 4.0 * g_yz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_x_yz[i] = 4.0 * g_yz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_x_zz[i] = 4.0 * g_yz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1860-1866)

    #pragma omp simd aligned(g_y_0_z_0_z_xy_y_xx, g_y_0_z_0_z_xy_y_xy, g_y_0_z_0_z_xy_y_xz, g_y_0_z_0_z_xy_y_yy, g_y_0_z_0_z_xy_y_yz, g_y_0_z_0_z_xy_y_zz, g_yz_xy_yz_xx, g_yz_xy_yz_xy, g_yz_xy_yz_xz, g_yz_xy_yz_yy, g_yz_xy_yz_yz, g_yz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xy_y_xx[i] = 4.0 * g_yz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_y_xy[i] = 4.0 * g_yz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_y_xz[i] = 4.0 * g_yz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_y_yy[i] = 4.0 * g_yz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_y_yz[i] = 4.0 * g_yz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_y_zz[i] = 4.0 * g_yz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1866-1872)

    #pragma omp simd aligned(g_y_0_z_0_z_xy_z_xx, g_y_0_z_0_z_xy_z_xy, g_y_0_z_0_z_xy_z_xz, g_y_0_z_0_z_xy_z_yy, g_y_0_z_0_z_xy_z_yz, g_y_0_z_0_z_xy_z_zz, g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_zz_xx, g_yz_xy_zz_xy, g_yz_xy_zz_xz, g_yz_xy_zz_yy, g_yz_xy_zz_yz, g_yz_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xy_z_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_z_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_z_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_z_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_z_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xy_z_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1872-1878)

    #pragma omp simd aligned(g_y_0_z_0_z_xz_x_xx, g_y_0_z_0_z_xz_x_xy, g_y_0_z_0_z_xz_x_xz, g_y_0_z_0_z_xz_x_yy, g_y_0_z_0_z_xz_x_yz, g_y_0_z_0_z_xz_x_zz, g_yz_xz_xz_xx, g_yz_xz_xz_xy, g_yz_xz_xz_xz, g_yz_xz_xz_yy, g_yz_xz_xz_yz, g_yz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xz_x_xx[i] = 4.0 * g_yz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_x_xy[i] = 4.0 * g_yz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_x_xz[i] = 4.0 * g_yz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_x_yy[i] = 4.0 * g_yz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_x_yz[i] = 4.0 * g_yz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_x_zz[i] = 4.0 * g_yz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1878-1884)

    #pragma omp simd aligned(g_y_0_z_0_z_xz_y_xx, g_y_0_z_0_z_xz_y_xy, g_y_0_z_0_z_xz_y_xz, g_y_0_z_0_z_xz_y_yy, g_y_0_z_0_z_xz_y_yz, g_y_0_z_0_z_xz_y_zz, g_yz_xz_yz_xx, g_yz_xz_yz_xy, g_yz_xz_yz_xz, g_yz_xz_yz_yy, g_yz_xz_yz_yz, g_yz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xz_y_xx[i] = 4.0 * g_yz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_y_xy[i] = 4.0 * g_yz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_y_xz[i] = 4.0 * g_yz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_y_yy[i] = 4.0 * g_yz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_y_yz[i] = 4.0 * g_yz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_y_zz[i] = 4.0 * g_yz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1884-1890)

    #pragma omp simd aligned(g_y_0_z_0_z_xz_z_xx, g_y_0_z_0_z_xz_z_xy, g_y_0_z_0_z_xz_z_xz, g_y_0_z_0_z_xz_z_yy, g_y_0_z_0_z_xz_z_yz, g_y_0_z_0_z_xz_z_zz, g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_zz_xx, g_yz_xz_zz_xy, g_yz_xz_zz_xz, g_yz_xz_zz_yy, g_yz_xz_zz_yz, g_yz_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_xz_z_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_z_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_z_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_z_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_z_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_xz_z_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1890-1896)

    #pragma omp simd aligned(g_y_0_z_0_z_yy_x_xx, g_y_0_z_0_z_yy_x_xy, g_y_0_z_0_z_yy_x_xz, g_y_0_z_0_z_yy_x_yy, g_y_0_z_0_z_yy_x_yz, g_y_0_z_0_z_yy_x_zz, g_yz_yy_xz_xx, g_yz_yy_xz_xy, g_yz_yy_xz_xz, g_yz_yy_xz_yy, g_yz_yy_xz_yz, g_yz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yy_x_xx[i] = 4.0 * g_yz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_x_xy[i] = 4.0 * g_yz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_x_xz[i] = 4.0 * g_yz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_x_yy[i] = 4.0 * g_yz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_x_yz[i] = 4.0 * g_yz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_x_zz[i] = 4.0 * g_yz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1896-1902)

    #pragma omp simd aligned(g_y_0_z_0_z_yy_y_xx, g_y_0_z_0_z_yy_y_xy, g_y_0_z_0_z_yy_y_xz, g_y_0_z_0_z_yy_y_yy, g_y_0_z_0_z_yy_y_yz, g_y_0_z_0_z_yy_y_zz, g_yz_yy_yz_xx, g_yz_yy_yz_xy, g_yz_yy_yz_xz, g_yz_yy_yz_yy, g_yz_yy_yz_yz, g_yz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yy_y_xx[i] = 4.0 * g_yz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_y_xy[i] = 4.0 * g_yz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_y_xz[i] = 4.0 * g_yz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_y_yy[i] = 4.0 * g_yz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_y_yz[i] = 4.0 * g_yz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_y_zz[i] = 4.0 * g_yz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1902-1908)

    #pragma omp simd aligned(g_y_0_z_0_z_yy_z_xx, g_y_0_z_0_z_yy_z_xy, g_y_0_z_0_z_yy_z_xz, g_y_0_z_0_z_yy_z_yy, g_y_0_z_0_z_yy_z_yz, g_y_0_z_0_z_yy_z_zz, g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_zz_xx, g_yz_yy_zz_xy, g_yz_yy_zz_xz, g_yz_yy_zz_yy, g_yz_yy_zz_yz, g_yz_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yy_z_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_z_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_z_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_z_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_z_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yy_z_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1908-1914)

    #pragma omp simd aligned(g_y_0_z_0_z_yz_x_xx, g_y_0_z_0_z_yz_x_xy, g_y_0_z_0_z_yz_x_xz, g_y_0_z_0_z_yz_x_yy, g_y_0_z_0_z_yz_x_yz, g_y_0_z_0_z_yz_x_zz, g_yz_yz_xz_xx, g_yz_yz_xz_xy, g_yz_yz_xz_xz, g_yz_yz_xz_yy, g_yz_yz_xz_yz, g_yz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yz_x_xx[i] = 4.0 * g_yz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_x_xy[i] = 4.0 * g_yz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_x_xz[i] = 4.0 * g_yz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_x_yy[i] = 4.0 * g_yz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_x_yz[i] = 4.0 * g_yz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_x_zz[i] = 4.0 * g_yz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1914-1920)

    #pragma omp simd aligned(g_y_0_z_0_z_yz_y_xx, g_y_0_z_0_z_yz_y_xy, g_y_0_z_0_z_yz_y_xz, g_y_0_z_0_z_yz_y_yy, g_y_0_z_0_z_yz_y_yz, g_y_0_z_0_z_yz_y_zz, g_yz_yz_yz_xx, g_yz_yz_yz_xy, g_yz_yz_yz_xz, g_yz_yz_yz_yy, g_yz_yz_yz_yz, g_yz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yz_y_xx[i] = 4.0 * g_yz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_y_xy[i] = 4.0 * g_yz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_y_xz[i] = 4.0 * g_yz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_y_yy[i] = 4.0 * g_yz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_y_yz[i] = 4.0 * g_yz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_y_zz[i] = 4.0 * g_yz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1920-1926)

    #pragma omp simd aligned(g_y_0_z_0_z_yz_z_xx, g_y_0_z_0_z_yz_z_xy, g_y_0_z_0_z_yz_z_xz, g_y_0_z_0_z_yz_z_yy, g_y_0_z_0_z_yz_z_yz, g_y_0_z_0_z_yz_z_zz, g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_zz_xx, g_yz_yz_zz_xy, g_yz_yz_zz_xz, g_yz_yz_zz_yy, g_yz_yz_zz_yz, g_yz_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_yz_z_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_z_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_z_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_z_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_z_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_yz_z_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1926-1932)

    #pragma omp simd aligned(g_y_0_z_0_z_zz_x_xx, g_y_0_z_0_z_zz_x_xy, g_y_0_z_0_z_zz_x_xz, g_y_0_z_0_z_zz_x_yy, g_y_0_z_0_z_zz_x_yz, g_y_0_z_0_z_zz_x_zz, g_yz_zz_xz_xx, g_yz_zz_xz_xy, g_yz_zz_xz_xz, g_yz_zz_xz_yy, g_yz_zz_xz_yz, g_yz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_zz_x_xx[i] = 4.0 * g_yz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_x_xy[i] = 4.0 * g_yz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_x_xz[i] = 4.0 * g_yz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_x_yy[i] = 4.0 * g_yz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_x_yz[i] = 4.0 * g_yz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_x_zz[i] = 4.0 * g_yz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1932-1938)

    #pragma omp simd aligned(g_y_0_z_0_z_zz_y_xx, g_y_0_z_0_z_zz_y_xy, g_y_0_z_0_z_zz_y_xz, g_y_0_z_0_z_zz_y_yy, g_y_0_z_0_z_zz_y_yz, g_y_0_z_0_z_zz_y_zz, g_yz_zz_yz_xx, g_yz_zz_yz_xy, g_yz_zz_yz_xz, g_yz_zz_yz_yy, g_yz_zz_yz_yz, g_yz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_zz_y_xx[i] = 4.0 * g_yz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_y_xy[i] = 4.0 * g_yz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_y_xz[i] = 4.0 * g_yz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_y_yy[i] = 4.0 * g_yz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_y_yz[i] = 4.0 * g_yz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_y_zz[i] = 4.0 * g_yz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1938-1944)

    #pragma omp simd aligned(g_y_0_z_0_z_zz_z_xx, g_y_0_z_0_z_zz_z_xy, g_y_0_z_0_z_zz_z_xz, g_y_0_z_0_z_zz_z_yy, g_y_0_z_0_z_zz_z_yz, g_y_0_z_0_z_zz_z_zz, g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_zz_xx, g_yz_zz_zz_xy, g_yz_zz_zz_xz, g_yz_zz_zz_yy, g_yz_zz_zz_yz, g_yz_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_y_0_z_0_z_zz_z_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_zz_xx[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_z_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_zz_xy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_z_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_zz_xz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_z_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_zz_yy[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_z_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_zz_yz[i] * a_exp * c_exps[i];

        g_y_0_z_0_z_zz_z_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1944-1950)

    #pragma omp simd aligned(g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_xx_xx, g_xz_xx_xx_xy, g_xz_xx_xx_xz, g_xz_xx_xx_yy, g_xz_xx_xx_yz, g_xz_xx_xx_zz, g_z_0_x_0_x_xx_x_xx, g_z_0_x_0_x_xx_x_xy, g_z_0_x_0_x_xx_x_xz, g_z_0_x_0_x_xx_x_yy, g_z_0_x_0_x_xx_x_yz, g_z_0_x_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xx_x_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_x_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_x_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_x_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_x_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_x_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1950-1956)

    #pragma omp simd aligned(g_xz_xx_xy_xx, g_xz_xx_xy_xy, g_xz_xx_xy_xz, g_xz_xx_xy_yy, g_xz_xx_xy_yz, g_xz_xx_xy_zz, g_z_0_x_0_x_xx_y_xx, g_z_0_x_0_x_xx_y_xy, g_z_0_x_0_x_xx_y_xz, g_z_0_x_0_x_xx_y_yy, g_z_0_x_0_x_xx_y_yz, g_z_0_x_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xx_y_xx[i] = 4.0 * g_xz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_y_xy[i] = 4.0 * g_xz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_y_xz[i] = 4.0 * g_xz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_y_yy[i] = 4.0 * g_xz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_y_yz[i] = 4.0 * g_xz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_y_zz[i] = 4.0 * g_xz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1956-1962)

    #pragma omp simd aligned(g_xz_xx_xz_xx, g_xz_xx_xz_xy, g_xz_xx_xz_xz, g_xz_xx_xz_yy, g_xz_xx_xz_yz, g_xz_xx_xz_zz, g_z_0_x_0_x_xx_z_xx, g_z_0_x_0_x_xx_z_xy, g_z_0_x_0_x_xx_z_xz, g_z_0_x_0_x_xx_z_yy, g_z_0_x_0_x_xx_z_yz, g_z_0_x_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xx_z_xx[i] = 4.0 * g_xz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_z_xy[i] = 4.0 * g_xz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_z_xz[i] = 4.0 * g_xz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_z_yy[i] = 4.0 * g_xz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_z_yz[i] = 4.0 * g_xz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xx_z_zz[i] = 4.0 * g_xz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1962-1968)

    #pragma omp simd aligned(g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_xx_xx, g_xz_xy_xx_xy, g_xz_xy_xx_xz, g_xz_xy_xx_yy, g_xz_xy_xx_yz, g_xz_xy_xx_zz, g_z_0_x_0_x_xy_x_xx, g_z_0_x_0_x_xy_x_xy, g_z_0_x_0_x_xy_x_xz, g_z_0_x_0_x_xy_x_yy, g_z_0_x_0_x_xy_x_yz, g_z_0_x_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xy_x_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_x_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_x_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_x_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_x_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_x_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1968-1974)

    #pragma omp simd aligned(g_xz_xy_xy_xx, g_xz_xy_xy_xy, g_xz_xy_xy_xz, g_xz_xy_xy_yy, g_xz_xy_xy_yz, g_xz_xy_xy_zz, g_z_0_x_0_x_xy_y_xx, g_z_0_x_0_x_xy_y_xy, g_z_0_x_0_x_xy_y_xz, g_z_0_x_0_x_xy_y_yy, g_z_0_x_0_x_xy_y_yz, g_z_0_x_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xy_y_xx[i] = 4.0 * g_xz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_y_xy[i] = 4.0 * g_xz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_y_xz[i] = 4.0 * g_xz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_y_yy[i] = 4.0 * g_xz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_y_yz[i] = 4.0 * g_xz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_y_zz[i] = 4.0 * g_xz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1974-1980)

    #pragma omp simd aligned(g_xz_xy_xz_xx, g_xz_xy_xz_xy, g_xz_xy_xz_xz, g_xz_xy_xz_yy, g_xz_xy_xz_yz, g_xz_xy_xz_zz, g_z_0_x_0_x_xy_z_xx, g_z_0_x_0_x_xy_z_xy, g_z_0_x_0_x_xy_z_xz, g_z_0_x_0_x_xy_z_yy, g_z_0_x_0_x_xy_z_yz, g_z_0_x_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xy_z_xx[i] = 4.0 * g_xz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_z_xy[i] = 4.0 * g_xz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_z_xz[i] = 4.0 * g_xz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_z_yy[i] = 4.0 * g_xz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_z_yz[i] = 4.0 * g_xz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xy_z_zz[i] = 4.0 * g_xz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1980-1986)

    #pragma omp simd aligned(g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_xx_xx, g_xz_xz_xx_xy, g_xz_xz_xx_xz, g_xz_xz_xx_yy, g_xz_xz_xx_yz, g_xz_xz_xx_zz, g_z_0_x_0_x_xz_x_xx, g_z_0_x_0_x_xz_x_xy, g_z_0_x_0_x_xz_x_xz, g_z_0_x_0_x_xz_x_yy, g_z_0_x_0_x_xz_x_yz, g_z_0_x_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xz_x_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_x_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_x_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_x_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_x_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_x_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1986-1992)

    #pragma omp simd aligned(g_xz_xz_xy_xx, g_xz_xz_xy_xy, g_xz_xz_xy_xz, g_xz_xz_xy_yy, g_xz_xz_xy_yz, g_xz_xz_xy_zz, g_z_0_x_0_x_xz_y_xx, g_z_0_x_0_x_xz_y_xy, g_z_0_x_0_x_xz_y_xz, g_z_0_x_0_x_xz_y_yy, g_z_0_x_0_x_xz_y_yz, g_z_0_x_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xz_y_xx[i] = 4.0 * g_xz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_y_xy[i] = 4.0 * g_xz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_y_xz[i] = 4.0 * g_xz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_y_yy[i] = 4.0 * g_xz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_y_yz[i] = 4.0 * g_xz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_y_zz[i] = 4.0 * g_xz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1992-1998)

    #pragma omp simd aligned(g_xz_xz_xz_xx, g_xz_xz_xz_xy, g_xz_xz_xz_xz, g_xz_xz_xz_yy, g_xz_xz_xz_yz, g_xz_xz_xz_zz, g_z_0_x_0_x_xz_z_xx, g_z_0_x_0_x_xz_z_xy, g_z_0_x_0_x_xz_z_xz, g_z_0_x_0_x_xz_z_yy, g_z_0_x_0_x_xz_z_yz, g_z_0_x_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_xz_z_xx[i] = 4.0 * g_xz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_z_xy[i] = 4.0 * g_xz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_z_xz[i] = 4.0 * g_xz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_z_yy[i] = 4.0 * g_xz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_z_yz[i] = 4.0 * g_xz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_xz_z_zz[i] = 4.0 * g_xz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (1998-2004)

    #pragma omp simd aligned(g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_xx_xx, g_xz_yy_xx_xy, g_xz_yy_xx_xz, g_xz_yy_xx_yy, g_xz_yy_xx_yz, g_xz_yy_xx_zz, g_z_0_x_0_x_yy_x_xx, g_z_0_x_0_x_yy_x_xy, g_z_0_x_0_x_yy_x_xz, g_z_0_x_0_x_yy_x_yy, g_z_0_x_0_x_yy_x_yz, g_z_0_x_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yy_x_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_x_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_x_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_x_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_x_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_x_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2004-2010)

    #pragma omp simd aligned(g_xz_yy_xy_xx, g_xz_yy_xy_xy, g_xz_yy_xy_xz, g_xz_yy_xy_yy, g_xz_yy_xy_yz, g_xz_yy_xy_zz, g_z_0_x_0_x_yy_y_xx, g_z_0_x_0_x_yy_y_xy, g_z_0_x_0_x_yy_y_xz, g_z_0_x_0_x_yy_y_yy, g_z_0_x_0_x_yy_y_yz, g_z_0_x_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yy_y_xx[i] = 4.0 * g_xz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_y_xy[i] = 4.0 * g_xz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_y_xz[i] = 4.0 * g_xz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_y_yy[i] = 4.0 * g_xz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_y_yz[i] = 4.0 * g_xz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_y_zz[i] = 4.0 * g_xz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2010-2016)

    #pragma omp simd aligned(g_xz_yy_xz_xx, g_xz_yy_xz_xy, g_xz_yy_xz_xz, g_xz_yy_xz_yy, g_xz_yy_xz_yz, g_xz_yy_xz_zz, g_z_0_x_0_x_yy_z_xx, g_z_0_x_0_x_yy_z_xy, g_z_0_x_0_x_yy_z_xz, g_z_0_x_0_x_yy_z_yy, g_z_0_x_0_x_yy_z_yz, g_z_0_x_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yy_z_xx[i] = 4.0 * g_xz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_z_xy[i] = 4.0 * g_xz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_z_xz[i] = 4.0 * g_xz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_z_yy[i] = 4.0 * g_xz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_z_yz[i] = 4.0 * g_xz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yy_z_zz[i] = 4.0 * g_xz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2016-2022)

    #pragma omp simd aligned(g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_xx_xx, g_xz_yz_xx_xy, g_xz_yz_xx_xz, g_xz_yz_xx_yy, g_xz_yz_xx_yz, g_xz_yz_xx_zz, g_z_0_x_0_x_yz_x_xx, g_z_0_x_0_x_yz_x_xy, g_z_0_x_0_x_yz_x_xz, g_z_0_x_0_x_yz_x_yy, g_z_0_x_0_x_yz_x_yz, g_z_0_x_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yz_x_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_x_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_x_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_x_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_x_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_x_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2022-2028)

    #pragma omp simd aligned(g_xz_yz_xy_xx, g_xz_yz_xy_xy, g_xz_yz_xy_xz, g_xz_yz_xy_yy, g_xz_yz_xy_yz, g_xz_yz_xy_zz, g_z_0_x_0_x_yz_y_xx, g_z_0_x_0_x_yz_y_xy, g_z_0_x_0_x_yz_y_xz, g_z_0_x_0_x_yz_y_yy, g_z_0_x_0_x_yz_y_yz, g_z_0_x_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yz_y_xx[i] = 4.0 * g_xz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_y_xy[i] = 4.0 * g_xz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_y_xz[i] = 4.0 * g_xz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_y_yy[i] = 4.0 * g_xz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_y_yz[i] = 4.0 * g_xz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_y_zz[i] = 4.0 * g_xz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2028-2034)

    #pragma omp simd aligned(g_xz_yz_xz_xx, g_xz_yz_xz_xy, g_xz_yz_xz_xz, g_xz_yz_xz_yy, g_xz_yz_xz_yz, g_xz_yz_xz_zz, g_z_0_x_0_x_yz_z_xx, g_z_0_x_0_x_yz_z_xy, g_z_0_x_0_x_yz_z_xz, g_z_0_x_0_x_yz_z_yy, g_z_0_x_0_x_yz_z_yz, g_z_0_x_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_yz_z_xx[i] = 4.0 * g_xz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_z_xy[i] = 4.0 * g_xz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_z_xz[i] = 4.0 * g_xz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_z_yy[i] = 4.0 * g_xz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_z_yz[i] = 4.0 * g_xz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_yz_z_zz[i] = 4.0 * g_xz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2034-2040)

    #pragma omp simd aligned(g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_xx_xx, g_xz_zz_xx_xy, g_xz_zz_xx_xz, g_xz_zz_xx_yy, g_xz_zz_xx_yz, g_xz_zz_xx_zz, g_z_0_x_0_x_zz_x_xx, g_z_0_x_0_x_zz_x_xy, g_z_0_x_0_x_zz_x_xz, g_z_0_x_0_x_zz_x_yy, g_z_0_x_0_x_zz_x_yz, g_z_0_x_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_zz_x_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_x_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_x_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_x_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_x_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_x_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2040-2046)

    #pragma omp simd aligned(g_xz_zz_xy_xx, g_xz_zz_xy_xy, g_xz_zz_xy_xz, g_xz_zz_xy_yy, g_xz_zz_xy_yz, g_xz_zz_xy_zz, g_z_0_x_0_x_zz_y_xx, g_z_0_x_0_x_zz_y_xy, g_z_0_x_0_x_zz_y_xz, g_z_0_x_0_x_zz_y_yy, g_z_0_x_0_x_zz_y_yz, g_z_0_x_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_zz_y_xx[i] = 4.0 * g_xz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_y_xy[i] = 4.0 * g_xz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_y_xz[i] = 4.0 * g_xz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_y_yy[i] = 4.0 * g_xz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_y_yz[i] = 4.0 * g_xz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_y_zz[i] = 4.0 * g_xz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2046-2052)

    #pragma omp simd aligned(g_xz_zz_xz_xx, g_xz_zz_xz_xy, g_xz_zz_xz_xz, g_xz_zz_xz_yy, g_xz_zz_xz_yz, g_xz_zz_xz_zz, g_z_0_x_0_x_zz_z_xx, g_z_0_x_0_x_zz_z_xy, g_z_0_x_0_x_zz_z_xz, g_z_0_x_0_x_zz_z_yy, g_z_0_x_0_x_zz_z_yz, g_z_0_x_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_x_zz_z_xx[i] = 4.0 * g_xz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_z_xy[i] = 4.0 * g_xz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_z_xz[i] = 4.0 * g_xz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_z_yy[i] = 4.0 * g_xz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_z_yz[i] = 4.0 * g_xz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_x_zz_z_zz[i] = 4.0 * g_xz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2052-2058)

    #pragma omp simd aligned(g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_xx_xx, g_yz_xx_xx_xy, g_yz_xx_xx_xz, g_yz_xx_xx_yy, g_yz_xx_xx_yz, g_yz_xx_xx_zz, g_z_0_x_0_y_xx_x_xx, g_z_0_x_0_y_xx_x_xy, g_z_0_x_0_y_xx_x_xz, g_z_0_x_0_y_xx_x_yy, g_z_0_x_0_y_xx_x_yz, g_z_0_x_0_y_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xx_x_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_x_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_x_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_x_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_x_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_x_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2058-2064)

    #pragma omp simd aligned(g_yz_xx_xy_xx, g_yz_xx_xy_xy, g_yz_xx_xy_xz, g_yz_xx_xy_yy, g_yz_xx_xy_yz, g_yz_xx_xy_zz, g_z_0_x_0_y_xx_y_xx, g_z_0_x_0_y_xx_y_xy, g_z_0_x_0_y_xx_y_xz, g_z_0_x_0_y_xx_y_yy, g_z_0_x_0_y_xx_y_yz, g_z_0_x_0_y_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xx_y_xx[i] = 4.0 * g_yz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_y_xy[i] = 4.0 * g_yz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_y_xz[i] = 4.0 * g_yz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_y_yy[i] = 4.0 * g_yz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_y_yz[i] = 4.0 * g_yz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_y_zz[i] = 4.0 * g_yz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2064-2070)

    #pragma omp simd aligned(g_yz_xx_xz_xx, g_yz_xx_xz_xy, g_yz_xx_xz_xz, g_yz_xx_xz_yy, g_yz_xx_xz_yz, g_yz_xx_xz_zz, g_z_0_x_0_y_xx_z_xx, g_z_0_x_0_y_xx_z_xy, g_z_0_x_0_y_xx_z_xz, g_z_0_x_0_y_xx_z_yy, g_z_0_x_0_y_xx_z_yz, g_z_0_x_0_y_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xx_z_xx[i] = 4.0 * g_yz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_z_xy[i] = 4.0 * g_yz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_z_xz[i] = 4.0 * g_yz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_z_yy[i] = 4.0 * g_yz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_z_yz[i] = 4.0 * g_yz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xx_z_zz[i] = 4.0 * g_yz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2070-2076)

    #pragma omp simd aligned(g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_xx_xx, g_yz_xy_xx_xy, g_yz_xy_xx_xz, g_yz_xy_xx_yy, g_yz_xy_xx_yz, g_yz_xy_xx_zz, g_z_0_x_0_y_xy_x_xx, g_z_0_x_0_y_xy_x_xy, g_z_0_x_0_y_xy_x_xz, g_z_0_x_0_y_xy_x_yy, g_z_0_x_0_y_xy_x_yz, g_z_0_x_0_y_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xy_x_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_x_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_x_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_x_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_x_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_x_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2076-2082)

    #pragma omp simd aligned(g_yz_xy_xy_xx, g_yz_xy_xy_xy, g_yz_xy_xy_xz, g_yz_xy_xy_yy, g_yz_xy_xy_yz, g_yz_xy_xy_zz, g_z_0_x_0_y_xy_y_xx, g_z_0_x_0_y_xy_y_xy, g_z_0_x_0_y_xy_y_xz, g_z_0_x_0_y_xy_y_yy, g_z_0_x_0_y_xy_y_yz, g_z_0_x_0_y_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xy_y_xx[i] = 4.0 * g_yz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_y_xy[i] = 4.0 * g_yz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_y_xz[i] = 4.0 * g_yz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_y_yy[i] = 4.0 * g_yz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_y_yz[i] = 4.0 * g_yz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_y_zz[i] = 4.0 * g_yz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2082-2088)

    #pragma omp simd aligned(g_yz_xy_xz_xx, g_yz_xy_xz_xy, g_yz_xy_xz_xz, g_yz_xy_xz_yy, g_yz_xy_xz_yz, g_yz_xy_xz_zz, g_z_0_x_0_y_xy_z_xx, g_z_0_x_0_y_xy_z_xy, g_z_0_x_0_y_xy_z_xz, g_z_0_x_0_y_xy_z_yy, g_z_0_x_0_y_xy_z_yz, g_z_0_x_0_y_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xy_z_xx[i] = 4.0 * g_yz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_z_xy[i] = 4.0 * g_yz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_z_xz[i] = 4.0 * g_yz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_z_yy[i] = 4.0 * g_yz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_z_yz[i] = 4.0 * g_yz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xy_z_zz[i] = 4.0 * g_yz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2088-2094)

    #pragma omp simd aligned(g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_xx_xx, g_yz_xz_xx_xy, g_yz_xz_xx_xz, g_yz_xz_xx_yy, g_yz_xz_xx_yz, g_yz_xz_xx_zz, g_z_0_x_0_y_xz_x_xx, g_z_0_x_0_y_xz_x_xy, g_z_0_x_0_y_xz_x_xz, g_z_0_x_0_y_xz_x_yy, g_z_0_x_0_y_xz_x_yz, g_z_0_x_0_y_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xz_x_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_x_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_x_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_x_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_x_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_x_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2094-2100)

    #pragma omp simd aligned(g_yz_xz_xy_xx, g_yz_xz_xy_xy, g_yz_xz_xy_xz, g_yz_xz_xy_yy, g_yz_xz_xy_yz, g_yz_xz_xy_zz, g_z_0_x_0_y_xz_y_xx, g_z_0_x_0_y_xz_y_xy, g_z_0_x_0_y_xz_y_xz, g_z_0_x_0_y_xz_y_yy, g_z_0_x_0_y_xz_y_yz, g_z_0_x_0_y_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xz_y_xx[i] = 4.0 * g_yz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_y_xy[i] = 4.0 * g_yz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_y_xz[i] = 4.0 * g_yz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_y_yy[i] = 4.0 * g_yz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_y_yz[i] = 4.0 * g_yz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_y_zz[i] = 4.0 * g_yz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2100-2106)

    #pragma omp simd aligned(g_yz_xz_xz_xx, g_yz_xz_xz_xy, g_yz_xz_xz_xz, g_yz_xz_xz_yy, g_yz_xz_xz_yz, g_yz_xz_xz_zz, g_z_0_x_0_y_xz_z_xx, g_z_0_x_0_y_xz_z_xy, g_z_0_x_0_y_xz_z_xz, g_z_0_x_0_y_xz_z_yy, g_z_0_x_0_y_xz_z_yz, g_z_0_x_0_y_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_xz_z_xx[i] = 4.0 * g_yz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_z_xy[i] = 4.0 * g_yz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_z_xz[i] = 4.0 * g_yz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_z_yy[i] = 4.0 * g_yz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_z_yz[i] = 4.0 * g_yz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_xz_z_zz[i] = 4.0 * g_yz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2106-2112)

    #pragma omp simd aligned(g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_xx_xx, g_yz_yy_xx_xy, g_yz_yy_xx_xz, g_yz_yy_xx_yy, g_yz_yy_xx_yz, g_yz_yy_xx_zz, g_z_0_x_0_y_yy_x_xx, g_z_0_x_0_y_yy_x_xy, g_z_0_x_0_y_yy_x_xz, g_z_0_x_0_y_yy_x_yy, g_z_0_x_0_y_yy_x_yz, g_z_0_x_0_y_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yy_x_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_x_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_x_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_x_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_x_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_x_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2112-2118)

    #pragma omp simd aligned(g_yz_yy_xy_xx, g_yz_yy_xy_xy, g_yz_yy_xy_xz, g_yz_yy_xy_yy, g_yz_yy_xy_yz, g_yz_yy_xy_zz, g_z_0_x_0_y_yy_y_xx, g_z_0_x_0_y_yy_y_xy, g_z_0_x_0_y_yy_y_xz, g_z_0_x_0_y_yy_y_yy, g_z_0_x_0_y_yy_y_yz, g_z_0_x_0_y_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yy_y_xx[i] = 4.0 * g_yz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_y_xy[i] = 4.0 * g_yz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_y_xz[i] = 4.0 * g_yz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_y_yy[i] = 4.0 * g_yz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_y_yz[i] = 4.0 * g_yz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_y_zz[i] = 4.0 * g_yz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2118-2124)

    #pragma omp simd aligned(g_yz_yy_xz_xx, g_yz_yy_xz_xy, g_yz_yy_xz_xz, g_yz_yy_xz_yy, g_yz_yy_xz_yz, g_yz_yy_xz_zz, g_z_0_x_0_y_yy_z_xx, g_z_0_x_0_y_yy_z_xy, g_z_0_x_0_y_yy_z_xz, g_z_0_x_0_y_yy_z_yy, g_z_0_x_0_y_yy_z_yz, g_z_0_x_0_y_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yy_z_xx[i] = 4.0 * g_yz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_z_xy[i] = 4.0 * g_yz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_z_xz[i] = 4.0 * g_yz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_z_yy[i] = 4.0 * g_yz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_z_yz[i] = 4.0 * g_yz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yy_z_zz[i] = 4.0 * g_yz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2124-2130)

    #pragma omp simd aligned(g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_xx_xx, g_yz_yz_xx_xy, g_yz_yz_xx_xz, g_yz_yz_xx_yy, g_yz_yz_xx_yz, g_yz_yz_xx_zz, g_z_0_x_0_y_yz_x_xx, g_z_0_x_0_y_yz_x_xy, g_z_0_x_0_y_yz_x_xz, g_z_0_x_0_y_yz_x_yy, g_z_0_x_0_y_yz_x_yz, g_z_0_x_0_y_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yz_x_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_x_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_x_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_x_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_x_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_x_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2130-2136)

    #pragma omp simd aligned(g_yz_yz_xy_xx, g_yz_yz_xy_xy, g_yz_yz_xy_xz, g_yz_yz_xy_yy, g_yz_yz_xy_yz, g_yz_yz_xy_zz, g_z_0_x_0_y_yz_y_xx, g_z_0_x_0_y_yz_y_xy, g_z_0_x_0_y_yz_y_xz, g_z_0_x_0_y_yz_y_yy, g_z_0_x_0_y_yz_y_yz, g_z_0_x_0_y_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yz_y_xx[i] = 4.0 * g_yz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_y_xy[i] = 4.0 * g_yz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_y_xz[i] = 4.0 * g_yz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_y_yy[i] = 4.0 * g_yz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_y_yz[i] = 4.0 * g_yz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_y_zz[i] = 4.0 * g_yz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2136-2142)

    #pragma omp simd aligned(g_yz_yz_xz_xx, g_yz_yz_xz_xy, g_yz_yz_xz_xz, g_yz_yz_xz_yy, g_yz_yz_xz_yz, g_yz_yz_xz_zz, g_z_0_x_0_y_yz_z_xx, g_z_0_x_0_y_yz_z_xy, g_z_0_x_0_y_yz_z_xz, g_z_0_x_0_y_yz_z_yy, g_z_0_x_0_y_yz_z_yz, g_z_0_x_0_y_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_yz_z_xx[i] = 4.0 * g_yz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_z_xy[i] = 4.0 * g_yz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_z_xz[i] = 4.0 * g_yz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_z_yy[i] = 4.0 * g_yz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_z_yz[i] = 4.0 * g_yz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_yz_z_zz[i] = 4.0 * g_yz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2142-2148)

    #pragma omp simd aligned(g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_xx_xx, g_yz_zz_xx_xy, g_yz_zz_xx_xz, g_yz_zz_xx_yy, g_yz_zz_xx_yz, g_yz_zz_xx_zz, g_z_0_x_0_y_zz_x_xx, g_z_0_x_0_y_zz_x_xy, g_z_0_x_0_y_zz_x_xz, g_z_0_x_0_y_zz_x_yy, g_z_0_x_0_y_zz_x_yz, g_z_0_x_0_y_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_zz_x_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_x_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_x_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_x_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_x_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_x_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2148-2154)

    #pragma omp simd aligned(g_yz_zz_xy_xx, g_yz_zz_xy_xy, g_yz_zz_xy_xz, g_yz_zz_xy_yy, g_yz_zz_xy_yz, g_yz_zz_xy_zz, g_z_0_x_0_y_zz_y_xx, g_z_0_x_0_y_zz_y_xy, g_z_0_x_0_y_zz_y_xz, g_z_0_x_0_y_zz_y_yy, g_z_0_x_0_y_zz_y_yz, g_z_0_x_0_y_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_zz_y_xx[i] = 4.0 * g_yz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_y_xy[i] = 4.0 * g_yz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_y_xz[i] = 4.0 * g_yz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_y_yy[i] = 4.0 * g_yz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_y_yz[i] = 4.0 * g_yz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_y_zz[i] = 4.0 * g_yz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2154-2160)

    #pragma omp simd aligned(g_yz_zz_xz_xx, g_yz_zz_xz_xy, g_yz_zz_xz_xz, g_yz_zz_xz_yy, g_yz_zz_xz_yz, g_yz_zz_xz_zz, g_z_0_x_0_y_zz_z_xx, g_z_0_x_0_y_zz_z_xy, g_z_0_x_0_y_zz_z_xz, g_z_0_x_0_y_zz_z_yy, g_z_0_x_0_y_zz_z_yz, g_z_0_x_0_y_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_y_zz_z_xx[i] = 4.0 * g_yz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_z_xy[i] = 4.0 * g_yz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_z_xz[i] = 4.0 * g_yz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_z_yy[i] = 4.0 * g_yz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_z_yz[i] = 4.0 * g_yz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_y_zz_z_zz[i] = 4.0 * g_yz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2160-2166)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_xx_xx, g_0_xx_xx_xy, g_0_xx_xx_xz, g_0_xx_xx_yy, g_0_xx_xx_yz, g_0_xx_xx_zz, g_z_0_x_0_z_xx_x_xx, g_z_0_x_0_z_xx_x_xy, g_z_0_x_0_z_xx_x_xz, g_z_0_x_0_z_xx_x_yy, g_z_0_x_0_z_xx_x_yz, g_z_0_x_0_z_xx_x_zz, g_zz_xx_0_xx, g_zz_xx_0_xy, g_zz_xx_0_xz, g_zz_xx_0_yy, g_zz_xx_0_yz, g_zz_xx_0_zz, g_zz_xx_xx_xx, g_zz_xx_xx_xy, g_zz_xx_xx_xz, g_zz_xx_xx_yy, g_zz_xx_xx_yz, g_zz_xx_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xx_x_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_xx_xx[i] * c_exps[i] - 2.0 * g_zz_xx_0_xx[i] * a_exp + 4.0 * g_zz_xx_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_x_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_xx_xy[i] * c_exps[i] - 2.0 * g_zz_xx_0_xy[i] * a_exp + 4.0 * g_zz_xx_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_x_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_xx_xz[i] * c_exps[i] - 2.0 * g_zz_xx_0_xz[i] * a_exp + 4.0 * g_zz_xx_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_x_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_xx_yy[i] * c_exps[i] - 2.0 * g_zz_xx_0_yy[i] * a_exp + 4.0 * g_zz_xx_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_x_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_xx_yz[i] * c_exps[i] - 2.0 * g_zz_xx_0_yz[i] * a_exp + 4.0 * g_zz_xx_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_x_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_xx_zz[i] * c_exps[i] - 2.0 * g_zz_xx_0_zz[i] * a_exp + 4.0 * g_zz_xx_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2166-2172)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_z_0_x_0_z_xx_y_xx, g_z_0_x_0_z_xx_y_xy, g_z_0_x_0_z_xx_y_xz, g_z_0_x_0_z_xx_y_yy, g_z_0_x_0_z_xx_y_yz, g_z_0_x_0_z_xx_y_zz, g_zz_xx_xy_xx, g_zz_xx_xy_xy, g_zz_xx_xy_xz, g_zz_xx_xy_yy, g_zz_xx_xy_yz, g_zz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xx_y_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_y_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_y_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_y_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_y_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_y_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2172-2178)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_z_0_x_0_z_xx_z_xx, g_z_0_x_0_z_xx_z_xy, g_z_0_x_0_z_xx_z_xz, g_z_0_x_0_z_xx_z_yy, g_z_0_x_0_z_xx_z_yz, g_z_0_x_0_z_xx_z_zz, g_zz_xx_xz_xx, g_zz_xx_xz_xy, g_zz_xx_xz_xz, g_zz_xx_xz_yy, g_zz_xx_xz_yz, g_zz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xx_z_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_z_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_z_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_z_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_z_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xx_z_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2178-2184)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_xx_xx, g_0_xy_xx_xy, g_0_xy_xx_xz, g_0_xy_xx_yy, g_0_xy_xx_yz, g_0_xy_xx_zz, g_z_0_x_0_z_xy_x_xx, g_z_0_x_0_z_xy_x_xy, g_z_0_x_0_z_xy_x_xz, g_z_0_x_0_z_xy_x_yy, g_z_0_x_0_z_xy_x_yz, g_z_0_x_0_z_xy_x_zz, g_zz_xy_0_xx, g_zz_xy_0_xy, g_zz_xy_0_xz, g_zz_xy_0_yy, g_zz_xy_0_yz, g_zz_xy_0_zz, g_zz_xy_xx_xx, g_zz_xy_xx_xy, g_zz_xy_xx_xz, g_zz_xy_xx_yy, g_zz_xy_xx_yz, g_zz_xy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xy_x_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_xx_xx[i] * c_exps[i] - 2.0 * g_zz_xy_0_xx[i] * a_exp + 4.0 * g_zz_xy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_x_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_xx_xy[i] * c_exps[i] - 2.0 * g_zz_xy_0_xy[i] * a_exp + 4.0 * g_zz_xy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_x_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_xx_xz[i] * c_exps[i] - 2.0 * g_zz_xy_0_xz[i] * a_exp + 4.0 * g_zz_xy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_x_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_xx_yy[i] * c_exps[i] - 2.0 * g_zz_xy_0_yy[i] * a_exp + 4.0 * g_zz_xy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_x_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_xx_yz[i] * c_exps[i] - 2.0 * g_zz_xy_0_yz[i] * a_exp + 4.0 * g_zz_xy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_x_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_xx_zz[i] * c_exps[i] - 2.0 * g_zz_xy_0_zz[i] * a_exp + 4.0 * g_zz_xy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2184-2190)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_z_0_x_0_z_xy_y_xx, g_z_0_x_0_z_xy_y_xy, g_z_0_x_0_z_xy_y_xz, g_z_0_x_0_z_xy_y_yy, g_z_0_x_0_z_xy_y_yz, g_z_0_x_0_z_xy_y_zz, g_zz_xy_xy_xx, g_zz_xy_xy_xy, g_zz_xy_xy_xz, g_zz_xy_xy_yy, g_zz_xy_xy_yz, g_zz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xy_y_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_y_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_y_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_y_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_y_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_y_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2190-2196)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_z_0_x_0_z_xy_z_xx, g_z_0_x_0_z_xy_z_xy, g_z_0_x_0_z_xy_z_xz, g_z_0_x_0_z_xy_z_yy, g_z_0_x_0_z_xy_z_yz, g_z_0_x_0_z_xy_z_zz, g_zz_xy_xz_xx, g_zz_xy_xz_xy, g_zz_xy_xz_xz, g_zz_xy_xz_yy, g_zz_xy_xz_yz, g_zz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xy_z_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_z_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_z_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_z_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_z_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xy_z_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2196-2202)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_xx_xx, g_0_xz_xx_xy, g_0_xz_xx_xz, g_0_xz_xx_yy, g_0_xz_xx_yz, g_0_xz_xx_zz, g_z_0_x_0_z_xz_x_xx, g_z_0_x_0_z_xz_x_xy, g_z_0_x_0_z_xz_x_xz, g_z_0_x_0_z_xz_x_yy, g_z_0_x_0_z_xz_x_yz, g_z_0_x_0_z_xz_x_zz, g_zz_xz_0_xx, g_zz_xz_0_xy, g_zz_xz_0_xz, g_zz_xz_0_yy, g_zz_xz_0_yz, g_zz_xz_0_zz, g_zz_xz_xx_xx, g_zz_xz_xx_xy, g_zz_xz_xx_xz, g_zz_xz_xx_yy, g_zz_xz_xx_yz, g_zz_xz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xz_x_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_xx_xx[i] * c_exps[i] - 2.0 * g_zz_xz_0_xx[i] * a_exp + 4.0 * g_zz_xz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_x_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_xx_xy[i] * c_exps[i] - 2.0 * g_zz_xz_0_xy[i] * a_exp + 4.0 * g_zz_xz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_x_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_xx_xz[i] * c_exps[i] - 2.0 * g_zz_xz_0_xz[i] * a_exp + 4.0 * g_zz_xz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_x_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_xx_yy[i] * c_exps[i] - 2.0 * g_zz_xz_0_yy[i] * a_exp + 4.0 * g_zz_xz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_x_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_xx_yz[i] * c_exps[i] - 2.0 * g_zz_xz_0_yz[i] * a_exp + 4.0 * g_zz_xz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_x_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_xx_zz[i] * c_exps[i] - 2.0 * g_zz_xz_0_zz[i] * a_exp + 4.0 * g_zz_xz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2202-2208)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_z_0_x_0_z_xz_y_xx, g_z_0_x_0_z_xz_y_xy, g_z_0_x_0_z_xz_y_xz, g_z_0_x_0_z_xz_y_yy, g_z_0_x_0_z_xz_y_yz, g_z_0_x_0_z_xz_y_zz, g_zz_xz_xy_xx, g_zz_xz_xy_xy, g_zz_xz_xy_xz, g_zz_xz_xy_yy, g_zz_xz_xy_yz, g_zz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xz_y_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_y_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_y_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_y_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_y_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_y_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2208-2214)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_z_0_x_0_z_xz_z_xx, g_z_0_x_0_z_xz_z_xy, g_z_0_x_0_z_xz_z_xz, g_z_0_x_0_z_xz_z_yy, g_z_0_x_0_z_xz_z_yz, g_z_0_x_0_z_xz_z_zz, g_zz_xz_xz_xx, g_zz_xz_xz_xy, g_zz_xz_xz_xz, g_zz_xz_xz_yy, g_zz_xz_xz_yz, g_zz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_xz_z_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_z_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_z_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_z_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_z_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_xz_z_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2214-2220)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_xx_xx, g_0_yy_xx_xy, g_0_yy_xx_xz, g_0_yy_xx_yy, g_0_yy_xx_yz, g_0_yy_xx_zz, g_z_0_x_0_z_yy_x_xx, g_z_0_x_0_z_yy_x_xy, g_z_0_x_0_z_yy_x_xz, g_z_0_x_0_z_yy_x_yy, g_z_0_x_0_z_yy_x_yz, g_z_0_x_0_z_yy_x_zz, g_zz_yy_0_xx, g_zz_yy_0_xy, g_zz_yy_0_xz, g_zz_yy_0_yy, g_zz_yy_0_yz, g_zz_yy_0_zz, g_zz_yy_xx_xx, g_zz_yy_xx_xy, g_zz_yy_xx_xz, g_zz_yy_xx_yy, g_zz_yy_xx_yz, g_zz_yy_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yy_x_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_xx_xx[i] * c_exps[i] - 2.0 * g_zz_yy_0_xx[i] * a_exp + 4.0 * g_zz_yy_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_x_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_xx_xy[i] * c_exps[i] - 2.0 * g_zz_yy_0_xy[i] * a_exp + 4.0 * g_zz_yy_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_x_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_xx_xz[i] * c_exps[i] - 2.0 * g_zz_yy_0_xz[i] * a_exp + 4.0 * g_zz_yy_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_x_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_xx_yy[i] * c_exps[i] - 2.0 * g_zz_yy_0_yy[i] * a_exp + 4.0 * g_zz_yy_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_x_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_xx_yz[i] * c_exps[i] - 2.0 * g_zz_yy_0_yz[i] * a_exp + 4.0 * g_zz_yy_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_x_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_xx_zz[i] * c_exps[i] - 2.0 * g_zz_yy_0_zz[i] * a_exp + 4.0 * g_zz_yy_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2220-2226)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_z_0_x_0_z_yy_y_xx, g_z_0_x_0_z_yy_y_xy, g_z_0_x_0_z_yy_y_xz, g_z_0_x_0_z_yy_y_yy, g_z_0_x_0_z_yy_y_yz, g_z_0_x_0_z_yy_y_zz, g_zz_yy_xy_xx, g_zz_yy_xy_xy, g_zz_yy_xy_xz, g_zz_yy_xy_yy, g_zz_yy_xy_yz, g_zz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yy_y_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_y_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_y_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_y_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_zz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_y_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_y_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2226-2232)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_z_0_x_0_z_yy_z_xx, g_z_0_x_0_z_yy_z_xy, g_z_0_x_0_z_yy_z_xz, g_z_0_x_0_z_yy_z_yy, g_z_0_x_0_z_yy_z_yz, g_z_0_x_0_z_yy_z_zz, g_zz_yy_xz_xx, g_zz_yy_xz_xy, g_zz_yy_xz_xz, g_zz_yy_xz_yy, g_zz_yy_xz_yz, g_zz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yy_z_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_z_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_z_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_z_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_zz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_z_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yy_z_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2232-2238)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_xx_xx, g_0_yz_xx_xy, g_0_yz_xx_xz, g_0_yz_xx_yy, g_0_yz_xx_yz, g_0_yz_xx_zz, g_z_0_x_0_z_yz_x_xx, g_z_0_x_0_z_yz_x_xy, g_z_0_x_0_z_yz_x_xz, g_z_0_x_0_z_yz_x_yy, g_z_0_x_0_z_yz_x_yz, g_z_0_x_0_z_yz_x_zz, g_zz_yz_0_xx, g_zz_yz_0_xy, g_zz_yz_0_xz, g_zz_yz_0_yy, g_zz_yz_0_yz, g_zz_yz_0_zz, g_zz_yz_xx_xx, g_zz_yz_xx_xy, g_zz_yz_xx_xz, g_zz_yz_xx_yy, g_zz_yz_xx_yz, g_zz_yz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yz_x_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_xx_xx[i] * c_exps[i] - 2.0 * g_zz_yz_0_xx[i] * a_exp + 4.0 * g_zz_yz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_x_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_xx_xy[i] * c_exps[i] - 2.0 * g_zz_yz_0_xy[i] * a_exp + 4.0 * g_zz_yz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_x_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_xx_xz[i] * c_exps[i] - 2.0 * g_zz_yz_0_xz[i] * a_exp + 4.0 * g_zz_yz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_x_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_xx_yy[i] * c_exps[i] - 2.0 * g_zz_yz_0_yy[i] * a_exp + 4.0 * g_zz_yz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_x_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_xx_yz[i] * c_exps[i] - 2.0 * g_zz_yz_0_yz[i] * a_exp + 4.0 * g_zz_yz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_x_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_xx_zz[i] * c_exps[i] - 2.0 * g_zz_yz_0_zz[i] * a_exp + 4.0 * g_zz_yz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2238-2244)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_z_0_x_0_z_yz_y_xx, g_z_0_x_0_z_yz_y_xy, g_z_0_x_0_z_yz_y_xz, g_z_0_x_0_z_yz_y_yy, g_z_0_x_0_z_yz_y_yz, g_z_0_x_0_z_yz_y_zz, g_zz_yz_xy_xx, g_zz_yz_xy_xy, g_zz_yz_xy_xz, g_zz_yz_xy_yy, g_zz_yz_xy_yz, g_zz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yz_y_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_y_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_y_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_y_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_y_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_y_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2244-2250)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_z_0_x_0_z_yz_z_xx, g_z_0_x_0_z_yz_z_xy, g_z_0_x_0_z_yz_z_xz, g_z_0_x_0_z_yz_z_yy, g_z_0_x_0_z_yz_z_yz, g_z_0_x_0_z_yz_z_zz, g_zz_yz_xz_xx, g_zz_yz_xz_xy, g_zz_yz_xz_xz, g_zz_yz_xz_yy, g_zz_yz_xz_yz, g_zz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_yz_z_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_z_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_z_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_z_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_z_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_yz_z_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2250-2256)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_xx_xx, g_0_zz_xx_xy, g_0_zz_xx_xz, g_0_zz_xx_yy, g_0_zz_xx_yz, g_0_zz_xx_zz, g_z_0_x_0_z_zz_x_xx, g_z_0_x_0_z_zz_x_xy, g_z_0_x_0_z_zz_x_xz, g_z_0_x_0_z_zz_x_yy, g_z_0_x_0_z_zz_x_yz, g_z_0_x_0_z_zz_x_zz, g_zz_zz_0_xx, g_zz_zz_0_xy, g_zz_zz_0_xz, g_zz_zz_0_yy, g_zz_zz_0_yz, g_zz_zz_0_zz, g_zz_zz_xx_xx, g_zz_zz_xx_xy, g_zz_zz_xx_xz, g_zz_zz_xx_yy, g_zz_zz_xx_yz, g_zz_zz_xx_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_zz_x_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_xx_xx[i] * c_exps[i] - 2.0 * g_zz_zz_0_xx[i] * a_exp + 4.0 * g_zz_zz_xx_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_x_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_xx_xy[i] * c_exps[i] - 2.0 * g_zz_zz_0_xy[i] * a_exp + 4.0 * g_zz_zz_xx_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_x_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_xx_xz[i] * c_exps[i] - 2.0 * g_zz_zz_0_xz[i] * a_exp + 4.0 * g_zz_zz_xx_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_x_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_xx_yy[i] * c_exps[i] - 2.0 * g_zz_zz_0_yy[i] * a_exp + 4.0 * g_zz_zz_xx_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_x_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_xx_yz[i] * c_exps[i] - 2.0 * g_zz_zz_0_yz[i] * a_exp + 4.0 * g_zz_zz_xx_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_x_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_xx_zz[i] * c_exps[i] - 2.0 * g_zz_zz_0_zz[i] * a_exp + 4.0 * g_zz_zz_xx_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2256-2262)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_z_0_x_0_z_zz_y_xx, g_z_0_x_0_z_zz_y_xy, g_z_0_x_0_z_zz_y_xz, g_z_0_x_0_z_zz_y_yy, g_z_0_x_0_z_zz_y_yz, g_z_0_x_0_z_zz_y_zz, g_zz_zz_xy_xx, g_zz_zz_xy_xy, g_zz_zz_xy_xz, g_zz_zz_xy_yy, g_zz_zz_xy_yz, g_zz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_zz_y_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_y_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_y_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_y_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_y_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_y_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2262-2268)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_z_0_x_0_z_zz_z_xx, g_z_0_x_0_z_zz_z_xy, g_z_0_x_0_z_zz_z_xz, g_z_0_x_0_z_zz_z_yy, g_z_0_x_0_z_zz_z_yz, g_z_0_x_0_z_zz_z_zz, g_zz_zz_xz_xx, g_zz_zz_xz_xy, g_zz_zz_xz_xz, g_zz_zz_xz_yy, g_zz_zz_xz_yz, g_zz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_x_0_z_zz_z_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_z_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_z_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_z_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_z_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_x_0_z_zz_z_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2268-2274)

    #pragma omp simd aligned(g_xz_xx_xy_xx, g_xz_xx_xy_xy, g_xz_xx_xy_xz, g_xz_xx_xy_yy, g_xz_xx_xy_yz, g_xz_xx_xy_zz, g_z_0_y_0_x_xx_x_xx, g_z_0_y_0_x_xx_x_xy, g_z_0_y_0_x_xx_x_xz, g_z_0_y_0_x_xx_x_yy, g_z_0_y_0_x_xx_x_yz, g_z_0_y_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xx_x_xx[i] = 4.0 * g_xz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_x_xy[i] = 4.0 * g_xz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_x_xz[i] = 4.0 * g_xz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_x_yy[i] = 4.0 * g_xz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_x_yz[i] = 4.0 * g_xz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_x_zz[i] = 4.0 * g_xz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2274-2280)

    #pragma omp simd aligned(g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_yy_xx, g_xz_xx_yy_xy, g_xz_xx_yy_xz, g_xz_xx_yy_yy, g_xz_xx_yy_yz, g_xz_xx_yy_zz, g_z_0_y_0_x_xx_y_xx, g_z_0_y_0_x_xx_y_xy, g_z_0_y_0_x_xx_y_xz, g_z_0_y_0_x_xx_y_yy, g_z_0_y_0_x_xx_y_yz, g_z_0_y_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xx_y_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_y_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_y_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_y_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_y_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_y_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2280-2286)

    #pragma omp simd aligned(g_xz_xx_yz_xx, g_xz_xx_yz_xy, g_xz_xx_yz_xz, g_xz_xx_yz_yy, g_xz_xx_yz_yz, g_xz_xx_yz_zz, g_z_0_y_0_x_xx_z_xx, g_z_0_y_0_x_xx_z_xy, g_z_0_y_0_x_xx_z_xz, g_z_0_y_0_x_xx_z_yy, g_z_0_y_0_x_xx_z_yz, g_z_0_y_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xx_z_xx[i] = 4.0 * g_xz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_z_xy[i] = 4.0 * g_xz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_z_xz[i] = 4.0 * g_xz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_z_yy[i] = 4.0 * g_xz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_z_yz[i] = 4.0 * g_xz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xx_z_zz[i] = 4.0 * g_xz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2286-2292)

    #pragma omp simd aligned(g_xz_xy_xy_xx, g_xz_xy_xy_xy, g_xz_xy_xy_xz, g_xz_xy_xy_yy, g_xz_xy_xy_yz, g_xz_xy_xy_zz, g_z_0_y_0_x_xy_x_xx, g_z_0_y_0_x_xy_x_xy, g_z_0_y_0_x_xy_x_xz, g_z_0_y_0_x_xy_x_yy, g_z_0_y_0_x_xy_x_yz, g_z_0_y_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xy_x_xx[i] = 4.0 * g_xz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_x_xy[i] = 4.0 * g_xz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_x_xz[i] = 4.0 * g_xz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_x_yy[i] = 4.0 * g_xz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_x_yz[i] = 4.0 * g_xz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_x_zz[i] = 4.0 * g_xz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2292-2298)

    #pragma omp simd aligned(g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_yy_xx, g_xz_xy_yy_xy, g_xz_xy_yy_xz, g_xz_xy_yy_yy, g_xz_xy_yy_yz, g_xz_xy_yy_zz, g_z_0_y_0_x_xy_y_xx, g_z_0_y_0_x_xy_y_xy, g_z_0_y_0_x_xy_y_xz, g_z_0_y_0_x_xy_y_yy, g_z_0_y_0_x_xy_y_yz, g_z_0_y_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xy_y_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_y_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_y_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_y_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_y_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_y_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2298-2304)

    #pragma omp simd aligned(g_xz_xy_yz_xx, g_xz_xy_yz_xy, g_xz_xy_yz_xz, g_xz_xy_yz_yy, g_xz_xy_yz_yz, g_xz_xy_yz_zz, g_z_0_y_0_x_xy_z_xx, g_z_0_y_0_x_xy_z_xy, g_z_0_y_0_x_xy_z_xz, g_z_0_y_0_x_xy_z_yy, g_z_0_y_0_x_xy_z_yz, g_z_0_y_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xy_z_xx[i] = 4.0 * g_xz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_z_xy[i] = 4.0 * g_xz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_z_xz[i] = 4.0 * g_xz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_z_yy[i] = 4.0 * g_xz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_z_yz[i] = 4.0 * g_xz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xy_z_zz[i] = 4.0 * g_xz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2304-2310)

    #pragma omp simd aligned(g_xz_xz_xy_xx, g_xz_xz_xy_xy, g_xz_xz_xy_xz, g_xz_xz_xy_yy, g_xz_xz_xy_yz, g_xz_xz_xy_zz, g_z_0_y_0_x_xz_x_xx, g_z_0_y_0_x_xz_x_xy, g_z_0_y_0_x_xz_x_xz, g_z_0_y_0_x_xz_x_yy, g_z_0_y_0_x_xz_x_yz, g_z_0_y_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xz_x_xx[i] = 4.0 * g_xz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_x_xy[i] = 4.0 * g_xz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_x_xz[i] = 4.0 * g_xz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_x_yy[i] = 4.0 * g_xz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_x_yz[i] = 4.0 * g_xz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_x_zz[i] = 4.0 * g_xz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2310-2316)

    #pragma omp simd aligned(g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_yy_xx, g_xz_xz_yy_xy, g_xz_xz_yy_xz, g_xz_xz_yy_yy, g_xz_xz_yy_yz, g_xz_xz_yy_zz, g_z_0_y_0_x_xz_y_xx, g_z_0_y_0_x_xz_y_xy, g_z_0_y_0_x_xz_y_xz, g_z_0_y_0_x_xz_y_yy, g_z_0_y_0_x_xz_y_yz, g_z_0_y_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xz_y_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_y_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_y_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_y_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_y_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_y_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2316-2322)

    #pragma omp simd aligned(g_xz_xz_yz_xx, g_xz_xz_yz_xy, g_xz_xz_yz_xz, g_xz_xz_yz_yy, g_xz_xz_yz_yz, g_xz_xz_yz_zz, g_z_0_y_0_x_xz_z_xx, g_z_0_y_0_x_xz_z_xy, g_z_0_y_0_x_xz_z_xz, g_z_0_y_0_x_xz_z_yy, g_z_0_y_0_x_xz_z_yz, g_z_0_y_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_xz_z_xx[i] = 4.0 * g_xz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_z_xy[i] = 4.0 * g_xz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_z_xz[i] = 4.0 * g_xz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_z_yy[i] = 4.0 * g_xz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_z_yz[i] = 4.0 * g_xz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_xz_z_zz[i] = 4.0 * g_xz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2322-2328)

    #pragma omp simd aligned(g_xz_yy_xy_xx, g_xz_yy_xy_xy, g_xz_yy_xy_xz, g_xz_yy_xy_yy, g_xz_yy_xy_yz, g_xz_yy_xy_zz, g_z_0_y_0_x_yy_x_xx, g_z_0_y_0_x_yy_x_xy, g_z_0_y_0_x_yy_x_xz, g_z_0_y_0_x_yy_x_yy, g_z_0_y_0_x_yy_x_yz, g_z_0_y_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yy_x_xx[i] = 4.0 * g_xz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_x_xy[i] = 4.0 * g_xz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_x_xz[i] = 4.0 * g_xz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_x_yy[i] = 4.0 * g_xz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_x_yz[i] = 4.0 * g_xz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_x_zz[i] = 4.0 * g_xz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2328-2334)

    #pragma omp simd aligned(g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_yy_xx, g_xz_yy_yy_xy, g_xz_yy_yy_xz, g_xz_yy_yy_yy, g_xz_yy_yy_yz, g_xz_yy_yy_zz, g_z_0_y_0_x_yy_y_xx, g_z_0_y_0_x_yy_y_xy, g_z_0_y_0_x_yy_y_xz, g_z_0_y_0_x_yy_y_yy, g_z_0_y_0_x_yy_y_yz, g_z_0_y_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yy_y_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_y_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_y_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_y_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_y_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_y_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2334-2340)

    #pragma omp simd aligned(g_xz_yy_yz_xx, g_xz_yy_yz_xy, g_xz_yy_yz_xz, g_xz_yy_yz_yy, g_xz_yy_yz_yz, g_xz_yy_yz_zz, g_z_0_y_0_x_yy_z_xx, g_z_0_y_0_x_yy_z_xy, g_z_0_y_0_x_yy_z_xz, g_z_0_y_0_x_yy_z_yy, g_z_0_y_0_x_yy_z_yz, g_z_0_y_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yy_z_xx[i] = 4.0 * g_xz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_z_xy[i] = 4.0 * g_xz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_z_xz[i] = 4.0 * g_xz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_z_yy[i] = 4.0 * g_xz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_z_yz[i] = 4.0 * g_xz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yy_z_zz[i] = 4.0 * g_xz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2340-2346)

    #pragma omp simd aligned(g_xz_yz_xy_xx, g_xz_yz_xy_xy, g_xz_yz_xy_xz, g_xz_yz_xy_yy, g_xz_yz_xy_yz, g_xz_yz_xy_zz, g_z_0_y_0_x_yz_x_xx, g_z_0_y_0_x_yz_x_xy, g_z_0_y_0_x_yz_x_xz, g_z_0_y_0_x_yz_x_yy, g_z_0_y_0_x_yz_x_yz, g_z_0_y_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yz_x_xx[i] = 4.0 * g_xz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_x_xy[i] = 4.0 * g_xz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_x_xz[i] = 4.0 * g_xz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_x_yy[i] = 4.0 * g_xz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_x_yz[i] = 4.0 * g_xz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_x_zz[i] = 4.0 * g_xz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2346-2352)

    #pragma omp simd aligned(g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_yy_xx, g_xz_yz_yy_xy, g_xz_yz_yy_xz, g_xz_yz_yy_yy, g_xz_yz_yy_yz, g_xz_yz_yy_zz, g_z_0_y_0_x_yz_y_xx, g_z_0_y_0_x_yz_y_xy, g_z_0_y_0_x_yz_y_xz, g_z_0_y_0_x_yz_y_yy, g_z_0_y_0_x_yz_y_yz, g_z_0_y_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yz_y_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_y_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_y_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_y_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_y_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_y_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2352-2358)

    #pragma omp simd aligned(g_xz_yz_yz_xx, g_xz_yz_yz_xy, g_xz_yz_yz_xz, g_xz_yz_yz_yy, g_xz_yz_yz_yz, g_xz_yz_yz_zz, g_z_0_y_0_x_yz_z_xx, g_z_0_y_0_x_yz_z_xy, g_z_0_y_0_x_yz_z_xz, g_z_0_y_0_x_yz_z_yy, g_z_0_y_0_x_yz_z_yz, g_z_0_y_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_yz_z_xx[i] = 4.0 * g_xz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_z_xy[i] = 4.0 * g_xz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_z_xz[i] = 4.0 * g_xz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_z_yy[i] = 4.0 * g_xz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_z_yz[i] = 4.0 * g_xz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_yz_z_zz[i] = 4.0 * g_xz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2358-2364)

    #pragma omp simd aligned(g_xz_zz_xy_xx, g_xz_zz_xy_xy, g_xz_zz_xy_xz, g_xz_zz_xy_yy, g_xz_zz_xy_yz, g_xz_zz_xy_zz, g_z_0_y_0_x_zz_x_xx, g_z_0_y_0_x_zz_x_xy, g_z_0_y_0_x_zz_x_xz, g_z_0_y_0_x_zz_x_yy, g_z_0_y_0_x_zz_x_yz, g_z_0_y_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_zz_x_xx[i] = 4.0 * g_xz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_x_xy[i] = 4.0 * g_xz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_x_xz[i] = 4.0 * g_xz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_x_yy[i] = 4.0 * g_xz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_x_yz[i] = 4.0 * g_xz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_x_zz[i] = 4.0 * g_xz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2364-2370)

    #pragma omp simd aligned(g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_yy_xx, g_xz_zz_yy_xy, g_xz_zz_yy_xz, g_xz_zz_yy_yy, g_xz_zz_yy_yz, g_xz_zz_yy_zz, g_z_0_y_0_x_zz_y_xx, g_z_0_y_0_x_zz_y_xy, g_z_0_y_0_x_zz_y_xz, g_z_0_y_0_x_zz_y_yy, g_z_0_y_0_x_zz_y_yz, g_z_0_y_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_zz_y_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_y_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_y_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_y_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_y_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_y_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2370-2376)

    #pragma omp simd aligned(g_xz_zz_yz_xx, g_xz_zz_yz_xy, g_xz_zz_yz_xz, g_xz_zz_yz_yy, g_xz_zz_yz_yz, g_xz_zz_yz_zz, g_z_0_y_0_x_zz_z_xx, g_z_0_y_0_x_zz_z_xy, g_z_0_y_0_x_zz_z_xz, g_z_0_y_0_x_zz_z_yy, g_z_0_y_0_x_zz_z_yz, g_z_0_y_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_x_zz_z_xx[i] = 4.0 * g_xz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_z_xy[i] = 4.0 * g_xz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_z_xz[i] = 4.0 * g_xz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_z_yy[i] = 4.0 * g_xz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_z_yz[i] = 4.0 * g_xz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_x_zz_z_zz[i] = 4.0 * g_xz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2376-2382)

    #pragma omp simd aligned(g_yz_xx_xy_xx, g_yz_xx_xy_xy, g_yz_xx_xy_xz, g_yz_xx_xy_yy, g_yz_xx_xy_yz, g_yz_xx_xy_zz, g_z_0_y_0_y_xx_x_xx, g_z_0_y_0_y_xx_x_xy, g_z_0_y_0_y_xx_x_xz, g_z_0_y_0_y_xx_x_yy, g_z_0_y_0_y_xx_x_yz, g_z_0_y_0_y_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xx_x_xx[i] = 4.0 * g_yz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_x_xy[i] = 4.0 * g_yz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_x_xz[i] = 4.0 * g_yz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_x_yy[i] = 4.0 * g_yz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_x_yz[i] = 4.0 * g_yz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_x_zz[i] = 4.0 * g_yz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2382-2388)

    #pragma omp simd aligned(g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_yy_xx, g_yz_xx_yy_xy, g_yz_xx_yy_xz, g_yz_xx_yy_yy, g_yz_xx_yy_yz, g_yz_xx_yy_zz, g_z_0_y_0_y_xx_y_xx, g_z_0_y_0_y_xx_y_xy, g_z_0_y_0_y_xx_y_xz, g_z_0_y_0_y_xx_y_yy, g_z_0_y_0_y_xx_y_yz, g_z_0_y_0_y_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xx_y_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_y_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_y_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_y_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_y_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_y_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2388-2394)

    #pragma omp simd aligned(g_yz_xx_yz_xx, g_yz_xx_yz_xy, g_yz_xx_yz_xz, g_yz_xx_yz_yy, g_yz_xx_yz_yz, g_yz_xx_yz_zz, g_z_0_y_0_y_xx_z_xx, g_z_0_y_0_y_xx_z_xy, g_z_0_y_0_y_xx_z_xz, g_z_0_y_0_y_xx_z_yy, g_z_0_y_0_y_xx_z_yz, g_z_0_y_0_y_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xx_z_xx[i] = 4.0 * g_yz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_z_xy[i] = 4.0 * g_yz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_z_xz[i] = 4.0 * g_yz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_z_yy[i] = 4.0 * g_yz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_z_yz[i] = 4.0 * g_yz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xx_z_zz[i] = 4.0 * g_yz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2394-2400)

    #pragma omp simd aligned(g_yz_xy_xy_xx, g_yz_xy_xy_xy, g_yz_xy_xy_xz, g_yz_xy_xy_yy, g_yz_xy_xy_yz, g_yz_xy_xy_zz, g_z_0_y_0_y_xy_x_xx, g_z_0_y_0_y_xy_x_xy, g_z_0_y_0_y_xy_x_xz, g_z_0_y_0_y_xy_x_yy, g_z_0_y_0_y_xy_x_yz, g_z_0_y_0_y_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xy_x_xx[i] = 4.0 * g_yz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_x_xy[i] = 4.0 * g_yz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_x_xz[i] = 4.0 * g_yz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_x_yy[i] = 4.0 * g_yz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_x_yz[i] = 4.0 * g_yz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_x_zz[i] = 4.0 * g_yz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2400-2406)

    #pragma omp simd aligned(g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_yy_xx, g_yz_xy_yy_xy, g_yz_xy_yy_xz, g_yz_xy_yy_yy, g_yz_xy_yy_yz, g_yz_xy_yy_zz, g_z_0_y_0_y_xy_y_xx, g_z_0_y_0_y_xy_y_xy, g_z_0_y_0_y_xy_y_xz, g_z_0_y_0_y_xy_y_yy, g_z_0_y_0_y_xy_y_yz, g_z_0_y_0_y_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xy_y_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_y_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_y_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_y_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_y_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_y_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2406-2412)

    #pragma omp simd aligned(g_yz_xy_yz_xx, g_yz_xy_yz_xy, g_yz_xy_yz_xz, g_yz_xy_yz_yy, g_yz_xy_yz_yz, g_yz_xy_yz_zz, g_z_0_y_0_y_xy_z_xx, g_z_0_y_0_y_xy_z_xy, g_z_0_y_0_y_xy_z_xz, g_z_0_y_0_y_xy_z_yy, g_z_0_y_0_y_xy_z_yz, g_z_0_y_0_y_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xy_z_xx[i] = 4.0 * g_yz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_z_xy[i] = 4.0 * g_yz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_z_xz[i] = 4.0 * g_yz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_z_yy[i] = 4.0 * g_yz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_z_yz[i] = 4.0 * g_yz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xy_z_zz[i] = 4.0 * g_yz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2412-2418)

    #pragma omp simd aligned(g_yz_xz_xy_xx, g_yz_xz_xy_xy, g_yz_xz_xy_xz, g_yz_xz_xy_yy, g_yz_xz_xy_yz, g_yz_xz_xy_zz, g_z_0_y_0_y_xz_x_xx, g_z_0_y_0_y_xz_x_xy, g_z_0_y_0_y_xz_x_xz, g_z_0_y_0_y_xz_x_yy, g_z_0_y_0_y_xz_x_yz, g_z_0_y_0_y_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xz_x_xx[i] = 4.0 * g_yz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_x_xy[i] = 4.0 * g_yz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_x_xz[i] = 4.0 * g_yz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_x_yy[i] = 4.0 * g_yz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_x_yz[i] = 4.0 * g_yz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_x_zz[i] = 4.0 * g_yz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2418-2424)

    #pragma omp simd aligned(g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_yy_xx, g_yz_xz_yy_xy, g_yz_xz_yy_xz, g_yz_xz_yy_yy, g_yz_xz_yy_yz, g_yz_xz_yy_zz, g_z_0_y_0_y_xz_y_xx, g_z_0_y_0_y_xz_y_xy, g_z_0_y_0_y_xz_y_xz, g_z_0_y_0_y_xz_y_yy, g_z_0_y_0_y_xz_y_yz, g_z_0_y_0_y_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xz_y_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_y_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_y_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_y_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_y_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_y_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2424-2430)

    #pragma omp simd aligned(g_yz_xz_yz_xx, g_yz_xz_yz_xy, g_yz_xz_yz_xz, g_yz_xz_yz_yy, g_yz_xz_yz_yz, g_yz_xz_yz_zz, g_z_0_y_0_y_xz_z_xx, g_z_0_y_0_y_xz_z_xy, g_z_0_y_0_y_xz_z_xz, g_z_0_y_0_y_xz_z_yy, g_z_0_y_0_y_xz_z_yz, g_z_0_y_0_y_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_xz_z_xx[i] = 4.0 * g_yz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_z_xy[i] = 4.0 * g_yz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_z_xz[i] = 4.0 * g_yz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_z_yy[i] = 4.0 * g_yz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_z_yz[i] = 4.0 * g_yz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_xz_z_zz[i] = 4.0 * g_yz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2430-2436)

    #pragma omp simd aligned(g_yz_yy_xy_xx, g_yz_yy_xy_xy, g_yz_yy_xy_xz, g_yz_yy_xy_yy, g_yz_yy_xy_yz, g_yz_yy_xy_zz, g_z_0_y_0_y_yy_x_xx, g_z_0_y_0_y_yy_x_xy, g_z_0_y_0_y_yy_x_xz, g_z_0_y_0_y_yy_x_yy, g_z_0_y_0_y_yy_x_yz, g_z_0_y_0_y_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yy_x_xx[i] = 4.0 * g_yz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_x_xy[i] = 4.0 * g_yz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_x_xz[i] = 4.0 * g_yz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_x_yy[i] = 4.0 * g_yz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_x_yz[i] = 4.0 * g_yz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_x_zz[i] = 4.0 * g_yz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2436-2442)

    #pragma omp simd aligned(g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_yy_xx, g_yz_yy_yy_xy, g_yz_yy_yy_xz, g_yz_yy_yy_yy, g_yz_yy_yy_yz, g_yz_yy_yy_zz, g_z_0_y_0_y_yy_y_xx, g_z_0_y_0_y_yy_y_xy, g_z_0_y_0_y_yy_y_xz, g_z_0_y_0_y_yy_y_yy, g_z_0_y_0_y_yy_y_yz, g_z_0_y_0_y_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yy_y_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_y_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_y_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_y_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_y_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_y_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2442-2448)

    #pragma omp simd aligned(g_yz_yy_yz_xx, g_yz_yy_yz_xy, g_yz_yy_yz_xz, g_yz_yy_yz_yy, g_yz_yy_yz_yz, g_yz_yy_yz_zz, g_z_0_y_0_y_yy_z_xx, g_z_0_y_0_y_yy_z_xy, g_z_0_y_0_y_yy_z_xz, g_z_0_y_0_y_yy_z_yy, g_z_0_y_0_y_yy_z_yz, g_z_0_y_0_y_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yy_z_xx[i] = 4.0 * g_yz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_z_xy[i] = 4.0 * g_yz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_z_xz[i] = 4.0 * g_yz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_z_yy[i] = 4.0 * g_yz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_z_yz[i] = 4.0 * g_yz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yy_z_zz[i] = 4.0 * g_yz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2448-2454)

    #pragma omp simd aligned(g_yz_yz_xy_xx, g_yz_yz_xy_xy, g_yz_yz_xy_xz, g_yz_yz_xy_yy, g_yz_yz_xy_yz, g_yz_yz_xy_zz, g_z_0_y_0_y_yz_x_xx, g_z_0_y_0_y_yz_x_xy, g_z_0_y_0_y_yz_x_xz, g_z_0_y_0_y_yz_x_yy, g_z_0_y_0_y_yz_x_yz, g_z_0_y_0_y_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yz_x_xx[i] = 4.0 * g_yz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_x_xy[i] = 4.0 * g_yz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_x_xz[i] = 4.0 * g_yz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_x_yy[i] = 4.0 * g_yz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_x_yz[i] = 4.0 * g_yz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_x_zz[i] = 4.0 * g_yz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2454-2460)

    #pragma omp simd aligned(g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_yy_xx, g_yz_yz_yy_xy, g_yz_yz_yy_xz, g_yz_yz_yy_yy, g_yz_yz_yy_yz, g_yz_yz_yy_zz, g_z_0_y_0_y_yz_y_xx, g_z_0_y_0_y_yz_y_xy, g_z_0_y_0_y_yz_y_xz, g_z_0_y_0_y_yz_y_yy, g_z_0_y_0_y_yz_y_yz, g_z_0_y_0_y_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yz_y_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_y_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_y_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_y_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_y_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_y_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2460-2466)

    #pragma omp simd aligned(g_yz_yz_yz_xx, g_yz_yz_yz_xy, g_yz_yz_yz_xz, g_yz_yz_yz_yy, g_yz_yz_yz_yz, g_yz_yz_yz_zz, g_z_0_y_0_y_yz_z_xx, g_z_0_y_0_y_yz_z_xy, g_z_0_y_0_y_yz_z_xz, g_z_0_y_0_y_yz_z_yy, g_z_0_y_0_y_yz_z_yz, g_z_0_y_0_y_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_yz_z_xx[i] = 4.0 * g_yz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_z_xy[i] = 4.0 * g_yz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_z_xz[i] = 4.0 * g_yz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_z_yy[i] = 4.0 * g_yz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_z_yz[i] = 4.0 * g_yz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_yz_z_zz[i] = 4.0 * g_yz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2466-2472)

    #pragma omp simd aligned(g_yz_zz_xy_xx, g_yz_zz_xy_xy, g_yz_zz_xy_xz, g_yz_zz_xy_yy, g_yz_zz_xy_yz, g_yz_zz_xy_zz, g_z_0_y_0_y_zz_x_xx, g_z_0_y_0_y_zz_x_xy, g_z_0_y_0_y_zz_x_xz, g_z_0_y_0_y_zz_x_yy, g_z_0_y_0_y_zz_x_yz, g_z_0_y_0_y_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_zz_x_xx[i] = 4.0 * g_yz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_x_xy[i] = 4.0 * g_yz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_x_xz[i] = 4.0 * g_yz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_x_yy[i] = 4.0 * g_yz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_x_yz[i] = 4.0 * g_yz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_x_zz[i] = 4.0 * g_yz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2472-2478)

    #pragma omp simd aligned(g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_yy_xx, g_yz_zz_yy_xy, g_yz_zz_yy_xz, g_yz_zz_yy_yy, g_yz_zz_yy_yz, g_yz_zz_yy_zz, g_z_0_y_0_y_zz_y_xx, g_z_0_y_0_y_zz_y_xy, g_z_0_y_0_y_zz_y_xz, g_z_0_y_0_y_zz_y_yy, g_z_0_y_0_y_zz_y_yz, g_z_0_y_0_y_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_zz_y_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_y_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_y_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_y_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_y_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_y_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2478-2484)

    #pragma omp simd aligned(g_yz_zz_yz_xx, g_yz_zz_yz_xy, g_yz_zz_yz_xz, g_yz_zz_yz_yy, g_yz_zz_yz_yz, g_yz_zz_yz_zz, g_z_0_y_0_y_zz_z_xx, g_z_0_y_0_y_zz_z_xy, g_z_0_y_0_y_zz_z_xz, g_z_0_y_0_y_zz_z_yy, g_z_0_y_0_y_zz_z_yz, g_z_0_y_0_y_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_y_zz_z_xx[i] = 4.0 * g_yz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_z_xy[i] = 4.0 * g_yz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_z_xz[i] = 4.0 * g_yz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_z_yy[i] = 4.0 * g_yz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_z_yz[i] = 4.0 * g_yz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_y_zz_z_zz[i] = 4.0 * g_yz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2484-2490)

    #pragma omp simd aligned(g_0_xx_xy_xx, g_0_xx_xy_xy, g_0_xx_xy_xz, g_0_xx_xy_yy, g_0_xx_xy_yz, g_0_xx_xy_zz, g_z_0_y_0_z_xx_x_xx, g_z_0_y_0_z_xx_x_xy, g_z_0_y_0_z_xx_x_xz, g_z_0_y_0_z_xx_x_yy, g_z_0_y_0_z_xx_x_yz, g_z_0_y_0_z_xx_x_zz, g_zz_xx_xy_xx, g_zz_xx_xy_xy, g_zz_xx_xy_xz, g_zz_xx_xy_yy, g_zz_xx_xy_yz, g_zz_xx_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xx_x_xx[i] = -2.0 * g_0_xx_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_x_xy[i] = -2.0 * g_0_xx_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_x_xz[i] = -2.0 * g_0_xx_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_x_yy[i] = -2.0 * g_0_xx_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xx_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_x_yz[i] = -2.0 * g_0_xx_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_x_zz[i] = -2.0 * g_0_xx_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xx_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2490-2496)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_yy_xx, g_0_xx_yy_xy, g_0_xx_yy_xz, g_0_xx_yy_yy, g_0_xx_yy_yz, g_0_xx_yy_zz, g_z_0_y_0_z_xx_y_xx, g_z_0_y_0_z_xx_y_xy, g_z_0_y_0_z_xx_y_xz, g_z_0_y_0_z_xx_y_yy, g_z_0_y_0_z_xx_y_yz, g_z_0_y_0_z_xx_y_zz, g_zz_xx_0_xx, g_zz_xx_0_xy, g_zz_xx_0_xz, g_zz_xx_0_yy, g_zz_xx_0_yz, g_zz_xx_0_zz, g_zz_xx_yy_xx, g_zz_xx_yy_xy, g_zz_xx_yy_xz, g_zz_xx_yy_yy, g_zz_xx_yy_yz, g_zz_xx_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xx_y_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_yy_xx[i] * c_exps[i] - 2.0 * g_zz_xx_0_xx[i] * a_exp + 4.0 * g_zz_xx_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_y_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_yy_xy[i] * c_exps[i] - 2.0 * g_zz_xx_0_xy[i] * a_exp + 4.0 * g_zz_xx_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_y_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_yy_xz[i] * c_exps[i] - 2.0 * g_zz_xx_0_xz[i] * a_exp + 4.0 * g_zz_xx_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_y_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_yy_yy[i] * c_exps[i] - 2.0 * g_zz_xx_0_yy[i] * a_exp + 4.0 * g_zz_xx_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_y_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_yy_yz[i] * c_exps[i] - 2.0 * g_zz_xx_0_yz[i] * a_exp + 4.0 * g_zz_xx_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_y_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_yy_zz[i] * c_exps[i] - 2.0 * g_zz_xx_0_zz[i] * a_exp + 4.0 * g_zz_xx_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2496-2502)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_z_0_y_0_z_xx_z_xx, g_z_0_y_0_z_xx_z_xy, g_z_0_y_0_z_xx_z_xz, g_z_0_y_0_z_xx_z_yy, g_z_0_y_0_z_xx_z_yz, g_z_0_y_0_z_xx_z_zz, g_zz_xx_yz_xx, g_zz_xx_yz_xy, g_zz_xx_yz_xz, g_zz_xx_yz_yy, g_zz_xx_yz_yz, g_zz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xx_z_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_z_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_z_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_z_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_z_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xx_z_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2502-2508)

    #pragma omp simd aligned(g_0_xy_xy_xx, g_0_xy_xy_xy, g_0_xy_xy_xz, g_0_xy_xy_yy, g_0_xy_xy_yz, g_0_xy_xy_zz, g_z_0_y_0_z_xy_x_xx, g_z_0_y_0_z_xy_x_xy, g_z_0_y_0_z_xy_x_xz, g_z_0_y_0_z_xy_x_yy, g_z_0_y_0_z_xy_x_yz, g_z_0_y_0_z_xy_x_zz, g_zz_xy_xy_xx, g_zz_xy_xy_xy, g_zz_xy_xy_xz, g_zz_xy_xy_yy, g_zz_xy_xy_yz, g_zz_xy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xy_x_xx[i] = -2.0 * g_0_xy_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_x_xy[i] = -2.0 * g_0_xy_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_x_xz[i] = -2.0 * g_0_xy_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_x_yy[i] = -2.0 * g_0_xy_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_x_yz[i] = -2.0 * g_0_xy_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_x_zz[i] = -2.0 * g_0_xy_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2508-2514)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_yy_xx, g_0_xy_yy_xy, g_0_xy_yy_xz, g_0_xy_yy_yy, g_0_xy_yy_yz, g_0_xy_yy_zz, g_z_0_y_0_z_xy_y_xx, g_z_0_y_0_z_xy_y_xy, g_z_0_y_0_z_xy_y_xz, g_z_0_y_0_z_xy_y_yy, g_z_0_y_0_z_xy_y_yz, g_z_0_y_0_z_xy_y_zz, g_zz_xy_0_xx, g_zz_xy_0_xy, g_zz_xy_0_xz, g_zz_xy_0_yy, g_zz_xy_0_yz, g_zz_xy_0_zz, g_zz_xy_yy_xx, g_zz_xy_yy_xy, g_zz_xy_yy_xz, g_zz_xy_yy_yy, g_zz_xy_yy_yz, g_zz_xy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xy_y_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_yy_xx[i] * c_exps[i] - 2.0 * g_zz_xy_0_xx[i] * a_exp + 4.0 * g_zz_xy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_y_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_yy_xy[i] * c_exps[i] - 2.0 * g_zz_xy_0_xy[i] * a_exp + 4.0 * g_zz_xy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_y_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_yy_xz[i] * c_exps[i] - 2.0 * g_zz_xy_0_xz[i] * a_exp + 4.0 * g_zz_xy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_y_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_yy_yy[i] * c_exps[i] - 2.0 * g_zz_xy_0_yy[i] * a_exp + 4.0 * g_zz_xy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_y_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_yy_yz[i] * c_exps[i] - 2.0 * g_zz_xy_0_yz[i] * a_exp + 4.0 * g_zz_xy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_y_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_yy_zz[i] * c_exps[i] - 2.0 * g_zz_xy_0_zz[i] * a_exp + 4.0 * g_zz_xy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2514-2520)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_z_0_y_0_z_xy_z_xx, g_z_0_y_0_z_xy_z_xy, g_z_0_y_0_z_xy_z_xz, g_z_0_y_0_z_xy_z_yy, g_z_0_y_0_z_xy_z_yz, g_z_0_y_0_z_xy_z_zz, g_zz_xy_yz_xx, g_zz_xy_yz_xy, g_zz_xy_yz_xz, g_zz_xy_yz_yy, g_zz_xy_yz_yz, g_zz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xy_z_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_z_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_z_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_z_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_z_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xy_z_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2520-2526)

    #pragma omp simd aligned(g_0_xz_xy_xx, g_0_xz_xy_xy, g_0_xz_xy_xz, g_0_xz_xy_yy, g_0_xz_xy_yz, g_0_xz_xy_zz, g_z_0_y_0_z_xz_x_xx, g_z_0_y_0_z_xz_x_xy, g_z_0_y_0_z_xz_x_xz, g_z_0_y_0_z_xz_x_yy, g_z_0_y_0_z_xz_x_yz, g_z_0_y_0_z_xz_x_zz, g_zz_xz_xy_xx, g_zz_xz_xy_xy, g_zz_xz_xy_xz, g_zz_xz_xy_yy, g_zz_xz_xy_yz, g_zz_xz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xz_x_xx[i] = -2.0 * g_0_xz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_x_xy[i] = -2.0 * g_0_xz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_x_xz[i] = -2.0 * g_0_xz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_x_yy[i] = -2.0 * g_0_xz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_xz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_x_yz[i] = -2.0 * g_0_xz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_x_zz[i] = -2.0 * g_0_xz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_xz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2526-2532)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_yy_xx, g_0_xz_yy_xy, g_0_xz_yy_xz, g_0_xz_yy_yy, g_0_xz_yy_yz, g_0_xz_yy_zz, g_z_0_y_0_z_xz_y_xx, g_z_0_y_0_z_xz_y_xy, g_z_0_y_0_z_xz_y_xz, g_z_0_y_0_z_xz_y_yy, g_z_0_y_0_z_xz_y_yz, g_z_0_y_0_z_xz_y_zz, g_zz_xz_0_xx, g_zz_xz_0_xy, g_zz_xz_0_xz, g_zz_xz_0_yy, g_zz_xz_0_yz, g_zz_xz_0_zz, g_zz_xz_yy_xx, g_zz_xz_yy_xy, g_zz_xz_yy_xz, g_zz_xz_yy_yy, g_zz_xz_yy_yz, g_zz_xz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xz_y_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_yy_xx[i] * c_exps[i] - 2.0 * g_zz_xz_0_xx[i] * a_exp + 4.0 * g_zz_xz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_y_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_yy_xy[i] * c_exps[i] - 2.0 * g_zz_xz_0_xy[i] * a_exp + 4.0 * g_zz_xz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_y_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_yy_xz[i] * c_exps[i] - 2.0 * g_zz_xz_0_xz[i] * a_exp + 4.0 * g_zz_xz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_y_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_yy_yy[i] * c_exps[i] - 2.0 * g_zz_xz_0_yy[i] * a_exp + 4.0 * g_zz_xz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_y_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_yy_yz[i] * c_exps[i] - 2.0 * g_zz_xz_0_yz[i] * a_exp + 4.0 * g_zz_xz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_y_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_yy_zz[i] * c_exps[i] - 2.0 * g_zz_xz_0_zz[i] * a_exp + 4.0 * g_zz_xz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2532-2538)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_z_0_y_0_z_xz_z_xx, g_z_0_y_0_z_xz_z_xy, g_z_0_y_0_z_xz_z_xz, g_z_0_y_0_z_xz_z_yy, g_z_0_y_0_z_xz_z_yz, g_z_0_y_0_z_xz_z_zz, g_zz_xz_yz_xx, g_zz_xz_yz_xy, g_zz_xz_yz_xz, g_zz_xz_yz_yy, g_zz_xz_yz_yz, g_zz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_xz_z_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_z_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_z_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_z_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_z_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_xz_z_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2538-2544)

    #pragma omp simd aligned(g_0_yy_xy_xx, g_0_yy_xy_xy, g_0_yy_xy_xz, g_0_yy_xy_yy, g_0_yy_xy_yz, g_0_yy_xy_zz, g_z_0_y_0_z_yy_x_xx, g_z_0_y_0_z_yy_x_xy, g_z_0_y_0_z_yy_x_xz, g_z_0_y_0_z_yy_x_yy, g_z_0_y_0_z_yy_x_yz, g_z_0_y_0_z_yy_x_zz, g_zz_yy_xy_xx, g_zz_yy_xy_xy, g_zz_yy_xy_xz, g_zz_yy_xy_yy, g_zz_yy_xy_yz, g_zz_yy_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yy_x_xx[i] = -2.0 * g_0_yy_xy_xx[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_x_xy[i] = -2.0 * g_0_yy_xy_xy[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_x_xz[i] = -2.0 * g_0_yy_xy_xz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_x_yy[i] = -2.0 * g_0_yy_xy_yy[i] * c_exps[i] + 4.0 * g_zz_yy_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_x_yz[i] = -2.0 * g_0_yy_xy_yz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_x_zz[i] = -2.0 * g_0_yy_xy_zz[i] * c_exps[i] + 4.0 * g_zz_yy_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2544-2550)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_yy_xx, g_0_yy_yy_xy, g_0_yy_yy_xz, g_0_yy_yy_yy, g_0_yy_yy_yz, g_0_yy_yy_zz, g_z_0_y_0_z_yy_y_xx, g_z_0_y_0_z_yy_y_xy, g_z_0_y_0_z_yy_y_xz, g_z_0_y_0_z_yy_y_yy, g_z_0_y_0_z_yy_y_yz, g_z_0_y_0_z_yy_y_zz, g_zz_yy_0_xx, g_zz_yy_0_xy, g_zz_yy_0_xz, g_zz_yy_0_yy, g_zz_yy_0_yz, g_zz_yy_0_zz, g_zz_yy_yy_xx, g_zz_yy_yy_xy, g_zz_yy_yy_xz, g_zz_yy_yy_yy, g_zz_yy_yy_yz, g_zz_yy_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yy_y_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_yy_xx[i] * c_exps[i] - 2.0 * g_zz_yy_0_xx[i] * a_exp + 4.0 * g_zz_yy_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_y_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_yy_xy[i] * c_exps[i] - 2.0 * g_zz_yy_0_xy[i] * a_exp + 4.0 * g_zz_yy_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_y_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_yy_xz[i] * c_exps[i] - 2.0 * g_zz_yy_0_xz[i] * a_exp + 4.0 * g_zz_yy_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_y_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_yy_yy[i] * c_exps[i] - 2.0 * g_zz_yy_0_yy[i] * a_exp + 4.0 * g_zz_yy_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_y_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_yy_yz[i] * c_exps[i] - 2.0 * g_zz_yy_0_yz[i] * a_exp + 4.0 * g_zz_yy_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_y_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_yy_zz[i] * c_exps[i] - 2.0 * g_zz_yy_0_zz[i] * a_exp + 4.0 * g_zz_yy_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2550-2556)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_z_0_y_0_z_yy_z_xx, g_z_0_y_0_z_yy_z_xy, g_z_0_y_0_z_yy_z_xz, g_z_0_y_0_z_yy_z_yy, g_z_0_y_0_z_yy_z_yz, g_z_0_y_0_z_yy_z_zz, g_zz_yy_yz_xx, g_zz_yy_yz_xy, g_zz_yy_yz_xz, g_zz_yy_yz_yy, g_zz_yy_yz_yz, g_zz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yy_z_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_z_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_z_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_z_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_zz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_z_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yy_z_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2556-2562)

    #pragma omp simd aligned(g_0_yz_xy_xx, g_0_yz_xy_xy, g_0_yz_xy_xz, g_0_yz_xy_yy, g_0_yz_xy_yz, g_0_yz_xy_zz, g_z_0_y_0_z_yz_x_xx, g_z_0_y_0_z_yz_x_xy, g_z_0_y_0_z_yz_x_xz, g_z_0_y_0_z_yz_x_yy, g_z_0_y_0_z_yz_x_yz, g_z_0_y_0_z_yz_x_zz, g_zz_yz_xy_xx, g_zz_yz_xy_xy, g_zz_yz_xy_xz, g_zz_yz_xy_yy, g_zz_yz_xy_yz, g_zz_yz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yz_x_xx[i] = -2.0 * g_0_yz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_x_xy[i] = -2.0 * g_0_yz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_x_xz[i] = -2.0 * g_0_yz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_x_yy[i] = -2.0 * g_0_yz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_yz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_x_yz[i] = -2.0 * g_0_yz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_x_zz[i] = -2.0 * g_0_yz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_yz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2562-2568)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_yy_xx, g_0_yz_yy_xy, g_0_yz_yy_xz, g_0_yz_yy_yy, g_0_yz_yy_yz, g_0_yz_yy_zz, g_z_0_y_0_z_yz_y_xx, g_z_0_y_0_z_yz_y_xy, g_z_0_y_0_z_yz_y_xz, g_z_0_y_0_z_yz_y_yy, g_z_0_y_0_z_yz_y_yz, g_z_0_y_0_z_yz_y_zz, g_zz_yz_0_xx, g_zz_yz_0_xy, g_zz_yz_0_xz, g_zz_yz_0_yy, g_zz_yz_0_yz, g_zz_yz_0_zz, g_zz_yz_yy_xx, g_zz_yz_yy_xy, g_zz_yz_yy_xz, g_zz_yz_yy_yy, g_zz_yz_yy_yz, g_zz_yz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yz_y_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_yy_xx[i] * c_exps[i] - 2.0 * g_zz_yz_0_xx[i] * a_exp + 4.0 * g_zz_yz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_y_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_yy_xy[i] * c_exps[i] - 2.0 * g_zz_yz_0_xy[i] * a_exp + 4.0 * g_zz_yz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_y_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_yy_xz[i] * c_exps[i] - 2.0 * g_zz_yz_0_xz[i] * a_exp + 4.0 * g_zz_yz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_y_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_yy_yy[i] * c_exps[i] - 2.0 * g_zz_yz_0_yy[i] * a_exp + 4.0 * g_zz_yz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_y_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_yy_yz[i] * c_exps[i] - 2.0 * g_zz_yz_0_yz[i] * a_exp + 4.0 * g_zz_yz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_y_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_yy_zz[i] * c_exps[i] - 2.0 * g_zz_yz_0_zz[i] * a_exp + 4.0 * g_zz_yz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2568-2574)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_z_0_y_0_z_yz_z_xx, g_z_0_y_0_z_yz_z_xy, g_z_0_y_0_z_yz_z_xz, g_z_0_y_0_z_yz_z_yy, g_z_0_y_0_z_yz_z_yz, g_z_0_y_0_z_yz_z_zz, g_zz_yz_yz_xx, g_zz_yz_yz_xy, g_zz_yz_yz_xz, g_zz_yz_yz_yy, g_zz_yz_yz_yz, g_zz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_yz_z_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_z_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_z_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_z_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_z_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_yz_z_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2574-2580)

    #pragma omp simd aligned(g_0_zz_xy_xx, g_0_zz_xy_xy, g_0_zz_xy_xz, g_0_zz_xy_yy, g_0_zz_xy_yz, g_0_zz_xy_zz, g_z_0_y_0_z_zz_x_xx, g_z_0_y_0_z_zz_x_xy, g_z_0_y_0_z_zz_x_xz, g_z_0_y_0_z_zz_x_yy, g_z_0_y_0_z_zz_x_yz, g_z_0_y_0_z_zz_x_zz, g_zz_zz_xy_xx, g_zz_zz_xy_xy, g_zz_zz_xy_xz, g_zz_zz_xy_yy, g_zz_zz_xy_yz, g_zz_zz_xy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_zz_x_xx[i] = -2.0 * g_0_zz_xy_xx[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_x_xy[i] = -2.0 * g_0_zz_xy_xy[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_x_xz[i] = -2.0 * g_0_zz_xy_xz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_x_yy[i] = -2.0 * g_0_zz_xy_yy[i] * c_exps[i] + 4.0 * g_zz_zz_xy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_x_yz[i] = -2.0 * g_0_zz_xy_yz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_x_zz[i] = -2.0 * g_0_zz_xy_zz[i] * c_exps[i] + 4.0 * g_zz_zz_xy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2580-2586)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_yy_xx, g_0_zz_yy_xy, g_0_zz_yy_xz, g_0_zz_yy_yy, g_0_zz_yy_yz, g_0_zz_yy_zz, g_z_0_y_0_z_zz_y_xx, g_z_0_y_0_z_zz_y_xy, g_z_0_y_0_z_zz_y_xz, g_z_0_y_0_z_zz_y_yy, g_z_0_y_0_z_zz_y_yz, g_z_0_y_0_z_zz_y_zz, g_zz_zz_0_xx, g_zz_zz_0_xy, g_zz_zz_0_xz, g_zz_zz_0_yy, g_zz_zz_0_yz, g_zz_zz_0_zz, g_zz_zz_yy_xx, g_zz_zz_yy_xy, g_zz_zz_yy_xz, g_zz_zz_yy_yy, g_zz_zz_yy_yz, g_zz_zz_yy_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_zz_y_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_yy_xx[i] * c_exps[i] - 2.0 * g_zz_zz_0_xx[i] * a_exp + 4.0 * g_zz_zz_yy_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_y_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_yy_xy[i] * c_exps[i] - 2.0 * g_zz_zz_0_xy[i] * a_exp + 4.0 * g_zz_zz_yy_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_y_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_yy_xz[i] * c_exps[i] - 2.0 * g_zz_zz_0_xz[i] * a_exp + 4.0 * g_zz_zz_yy_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_y_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_yy_yy[i] * c_exps[i] - 2.0 * g_zz_zz_0_yy[i] * a_exp + 4.0 * g_zz_zz_yy_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_y_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_yy_yz[i] * c_exps[i] - 2.0 * g_zz_zz_0_yz[i] * a_exp + 4.0 * g_zz_zz_yy_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_y_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_yy_zz[i] * c_exps[i] - 2.0 * g_zz_zz_0_zz[i] * a_exp + 4.0 * g_zz_zz_yy_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2586-2592)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_z_0_y_0_z_zz_z_xx, g_z_0_y_0_z_zz_z_xy, g_z_0_y_0_z_zz_z_xz, g_z_0_y_0_z_zz_z_yy, g_z_0_y_0_z_zz_z_yz, g_z_0_y_0_z_zz_z_zz, g_zz_zz_yz_xx, g_zz_zz_yz_xy, g_zz_zz_yz_xz, g_zz_zz_yz_yy, g_zz_zz_yz_yz, g_zz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_y_0_z_zz_z_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_z_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_z_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_z_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_z_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_y_0_z_zz_z_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2592-2598)

    #pragma omp simd aligned(g_xz_xx_xz_xx, g_xz_xx_xz_xy, g_xz_xx_xz_xz, g_xz_xx_xz_yy, g_xz_xx_xz_yz, g_xz_xx_xz_zz, g_z_0_z_0_x_xx_x_xx, g_z_0_z_0_x_xx_x_xy, g_z_0_z_0_x_xx_x_xz, g_z_0_z_0_x_xx_x_yy, g_z_0_z_0_x_xx_x_yz, g_z_0_z_0_x_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xx_x_xx[i] = 4.0 * g_xz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_x_xy[i] = 4.0 * g_xz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_x_xz[i] = 4.0 * g_xz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_x_yy[i] = 4.0 * g_xz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_x_yz[i] = 4.0 * g_xz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_x_zz[i] = 4.0 * g_xz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2598-2604)

    #pragma omp simd aligned(g_xz_xx_yz_xx, g_xz_xx_yz_xy, g_xz_xx_yz_xz, g_xz_xx_yz_yy, g_xz_xx_yz_yz, g_xz_xx_yz_zz, g_z_0_z_0_x_xx_y_xx, g_z_0_z_0_x_xx_y_xy, g_z_0_z_0_x_xx_y_xz, g_z_0_z_0_x_xx_y_yy, g_z_0_z_0_x_xx_y_yz, g_z_0_z_0_x_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xx_y_xx[i] = 4.0 * g_xz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_y_xy[i] = 4.0 * g_xz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_y_xz[i] = 4.0 * g_xz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_y_yy[i] = 4.0 * g_xz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_y_yz[i] = 4.0 * g_xz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_y_zz[i] = 4.0 * g_xz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2604-2610)

    #pragma omp simd aligned(g_xz_xx_0_xx, g_xz_xx_0_xy, g_xz_xx_0_xz, g_xz_xx_0_yy, g_xz_xx_0_yz, g_xz_xx_0_zz, g_xz_xx_zz_xx, g_xz_xx_zz_xy, g_xz_xx_zz_xz, g_xz_xx_zz_yy, g_xz_xx_zz_yz, g_xz_xx_zz_zz, g_z_0_z_0_x_xx_z_xx, g_z_0_z_0_x_xx_z_xy, g_z_0_z_0_x_xx_z_xz, g_z_0_z_0_x_xx_z_yy, g_z_0_z_0_x_xx_z_yz, g_z_0_z_0_x_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xx_z_xx[i] = -2.0 * g_xz_xx_0_xx[i] * a_exp + 4.0 * g_xz_xx_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_z_xy[i] = -2.0 * g_xz_xx_0_xy[i] * a_exp + 4.0 * g_xz_xx_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_z_xz[i] = -2.0 * g_xz_xx_0_xz[i] * a_exp + 4.0 * g_xz_xx_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_z_yy[i] = -2.0 * g_xz_xx_0_yy[i] * a_exp + 4.0 * g_xz_xx_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_z_yz[i] = -2.0 * g_xz_xx_0_yz[i] * a_exp + 4.0 * g_xz_xx_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xx_z_zz[i] = -2.0 * g_xz_xx_0_zz[i] * a_exp + 4.0 * g_xz_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2610-2616)

    #pragma omp simd aligned(g_xz_xy_xz_xx, g_xz_xy_xz_xy, g_xz_xy_xz_xz, g_xz_xy_xz_yy, g_xz_xy_xz_yz, g_xz_xy_xz_zz, g_z_0_z_0_x_xy_x_xx, g_z_0_z_0_x_xy_x_xy, g_z_0_z_0_x_xy_x_xz, g_z_0_z_0_x_xy_x_yy, g_z_0_z_0_x_xy_x_yz, g_z_0_z_0_x_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xy_x_xx[i] = 4.0 * g_xz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_x_xy[i] = 4.0 * g_xz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_x_xz[i] = 4.0 * g_xz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_x_yy[i] = 4.0 * g_xz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_x_yz[i] = 4.0 * g_xz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_x_zz[i] = 4.0 * g_xz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2616-2622)

    #pragma omp simd aligned(g_xz_xy_yz_xx, g_xz_xy_yz_xy, g_xz_xy_yz_xz, g_xz_xy_yz_yy, g_xz_xy_yz_yz, g_xz_xy_yz_zz, g_z_0_z_0_x_xy_y_xx, g_z_0_z_0_x_xy_y_xy, g_z_0_z_0_x_xy_y_xz, g_z_0_z_0_x_xy_y_yy, g_z_0_z_0_x_xy_y_yz, g_z_0_z_0_x_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xy_y_xx[i] = 4.0 * g_xz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_y_xy[i] = 4.0 * g_xz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_y_xz[i] = 4.0 * g_xz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_y_yy[i] = 4.0 * g_xz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_y_yz[i] = 4.0 * g_xz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_y_zz[i] = 4.0 * g_xz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2622-2628)

    #pragma omp simd aligned(g_xz_xy_0_xx, g_xz_xy_0_xy, g_xz_xy_0_xz, g_xz_xy_0_yy, g_xz_xy_0_yz, g_xz_xy_0_zz, g_xz_xy_zz_xx, g_xz_xy_zz_xy, g_xz_xy_zz_xz, g_xz_xy_zz_yy, g_xz_xy_zz_yz, g_xz_xy_zz_zz, g_z_0_z_0_x_xy_z_xx, g_z_0_z_0_x_xy_z_xy, g_z_0_z_0_x_xy_z_xz, g_z_0_z_0_x_xy_z_yy, g_z_0_z_0_x_xy_z_yz, g_z_0_z_0_x_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xy_z_xx[i] = -2.0 * g_xz_xy_0_xx[i] * a_exp + 4.0 * g_xz_xy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_z_xy[i] = -2.0 * g_xz_xy_0_xy[i] * a_exp + 4.0 * g_xz_xy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_z_xz[i] = -2.0 * g_xz_xy_0_xz[i] * a_exp + 4.0 * g_xz_xy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_z_yy[i] = -2.0 * g_xz_xy_0_yy[i] * a_exp + 4.0 * g_xz_xy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_z_yz[i] = -2.0 * g_xz_xy_0_yz[i] * a_exp + 4.0 * g_xz_xy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xy_z_zz[i] = -2.0 * g_xz_xy_0_zz[i] * a_exp + 4.0 * g_xz_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2628-2634)

    #pragma omp simd aligned(g_xz_xz_xz_xx, g_xz_xz_xz_xy, g_xz_xz_xz_xz, g_xz_xz_xz_yy, g_xz_xz_xz_yz, g_xz_xz_xz_zz, g_z_0_z_0_x_xz_x_xx, g_z_0_z_0_x_xz_x_xy, g_z_0_z_0_x_xz_x_xz, g_z_0_z_0_x_xz_x_yy, g_z_0_z_0_x_xz_x_yz, g_z_0_z_0_x_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xz_x_xx[i] = 4.0 * g_xz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_x_xy[i] = 4.0 * g_xz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_x_xz[i] = 4.0 * g_xz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_x_yy[i] = 4.0 * g_xz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_x_yz[i] = 4.0 * g_xz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_x_zz[i] = 4.0 * g_xz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2634-2640)

    #pragma omp simd aligned(g_xz_xz_yz_xx, g_xz_xz_yz_xy, g_xz_xz_yz_xz, g_xz_xz_yz_yy, g_xz_xz_yz_yz, g_xz_xz_yz_zz, g_z_0_z_0_x_xz_y_xx, g_z_0_z_0_x_xz_y_xy, g_z_0_z_0_x_xz_y_xz, g_z_0_z_0_x_xz_y_yy, g_z_0_z_0_x_xz_y_yz, g_z_0_z_0_x_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xz_y_xx[i] = 4.0 * g_xz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_y_xy[i] = 4.0 * g_xz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_y_xz[i] = 4.0 * g_xz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_y_yy[i] = 4.0 * g_xz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_y_yz[i] = 4.0 * g_xz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_y_zz[i] = 4.0 * g_xz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2640-2646)

    #pragma omp simd aligned(g_xz_xz_0_xx, g_xz_xz_0_xy, g_xz_xz_0_xz, g_xz_xz_0_yy, g_xz_xz_0_yz, g_xz_xz_0_zz, g_xz_xz_zz_xx, g_xz_xz_zz_xy, g_xz_xz_zz_xz, g_xz_xz_zz_yy, g_xz_xz_zz_yz, g_xz_xz_zz_zz, g_z_0_z_0_x_xz_z_xx, g_z_0_z_0_x_xz_z_xy, g_z_0_z_0_x_xz_z_xz, g_z_0_z_0_x_xz_z_yy, g_z_0_z_0_x_xz_z_yz, g_z_0_z_0_x_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_xz_z_xx[i] = -2.0 * g_xz_xz_0_xx[i] * a_exp + 4.0 * g_xz_xz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_z_xy[i] = -2.0 * g_xz_xz_0_xy[i] * a_exp + 4.0 * g_xz_xz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_z_xz[i] = -2.0 * g_xz_xz_0_xz[i] * a_exp + 4.0 * g_xz_xz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_z_yy[i] = -2.0 * g_xz_xz_0_yy[i] * a_exp + 4.0 * g_xz_xz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_z_yz[i] = -2.0 * g_xz_xz_0_yz[i] * a_exp + 4.0 * g_xz_xz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_xz_z_zz[i] = -2.0 * g_xz_xz_0_zz[i] * a_exp + 4.0 * g_xz_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2646-2652)

    #pragma omp simd aligned(g_xz_yy_xz_xx, g_xz_yy_xz_xy, g_xz_yy_xz_xz, g_xz_yy_xz_yy, g_xz_yy_xz_yz, g_xz_yy_xz_zz, g_z_0_z_0_x_yy_x_xx, g_z_0_z_0_x_yy_x_xy, g_z_0_z_0_x_yy_x_xz, g_z_0_z_0_x_yy_x_yy, g_z_0_z_0_x_yy_x_yz, g_z_0_z_0_x_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yy_x_xx[i] = 4.0 * g_xz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_x_xy[i] = 4.0 * g_xz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_x_xz[i] = 4.0 * g_xz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_x_yy[i] = 4.0 * g_xz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_x_yz[i] = 4.0 * g_xz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_x_zz[i] = 4.0 * g_xz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2652-2658)

    #pragma omp simd aligned(g_xz_yy_yz_xx, g_xz_yy_yz_xy, g_xz_yy_yz_xz, g_xz_yy_yz_yy, g_xz_yy_yz_yz, g_xz_yy_yz_zz, g_z_0_z_0_x_yy_y_xx, g_z_0_z_0_x_yy_y_xy, g_z_0_z_0_x_yy_y_xz, g_z_0_z_0_x_yy_y_yy, g_z_0_z_0_x_yy_y_yz, g_z_0_z_0_x_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yy_y_xx[i] = 4.0 * g_xz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_y_xy[i] = 4.0 * g_xz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_y_xz[i] = 4.0 * g_xz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_y_yy[i] = 4.0 * g_xz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_y_yz[i] = 4.0 * g_xz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_y_zz[i] = 4.0 * g_xz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2658-2664)

    #pragma omp simd aligned(g_xz_yy_0_xx, g_xz_yy_0_xy, g_xz_yy_0_xz, g_xz_yy_0_yy, g_xz_yy_0_yz, g_xz_yy_0_zz, g_xz_yy_zz_xx, g_xz_yy_zz_xy, g_xz_yy_zz_xz, g_xz_yy_zz_yy, g_xz_yy_zz_yz, g_xz_yy_zz_zz, g_z_0_z_0_x_yy_z_xx, g_z_0_z_0_x_yy_z_xy, g_z_0_z_0_x_yy_z_xz, g_z_0_z_0_x_yy_z_yy, g_z_0_z_0_x_yy_z_yz, g_z_0_z_0_x_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yy_z_xx[i] = -2.0 * g_xz_yy_0_xx[i] * a_exp + 4.0 * g_xz_yy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_z_xy[i] = -2.0 * g_xz_yy_0_xy[i] * a_exp + 4.0 * g_xz_yy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_z_xz[i] = -2.0 * g_xz_yy_0_xz[i] * a_exp + 4.0 * g_xz_yy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_z_yy[i] = -2.0 * g_xz_yy_0_yy[i] * a_exp + 4.0 * g_xz_yy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_z_yz[i] = -2.0 * g_xz_yy_0_yz[i] * a_exp + 4.0 * g_xz_yy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yy_z_zz[i] = -2.0 * g_xz_yy_0_zz[i] * a_exp + 4.0 * g_xz_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2664-2670)

    #pragma omp simd aligned(g_xz_yz_xz_xx, g_xz_yz_xz_xy, g_xz_yz_xz_xz, g_xz_yz_xz_yy, g_xz_yz_xz_yz, g_xz_yz_xz_zz, g_z_0_z_0_x_yz_x_xx, g_z_0_z_0_x_yz_x_xy, g_z_0_z_0_x_yz_x_xz, g_z_0_z_0_x_yz_x_yy, g_z_0_z_0_x_yz_x_yz, g_z_0_z_0_x_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yz_x_xx[i] = 4.0 * g_xz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_x_xy[i] = 4.0 * g_xz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_x_xz[i] = 4.0 * g_xz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_x_yy[i] = 4.0 * g_xz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_x_yz[i] = 4.0 * g_xz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_x_zz[i] = 4.0 * g_xz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2670-2676)

    #pragma omp simd aligned(g_xz_yz_yz_xx, g_xz_yz_yz_xy, g_xz_yz_yz_xz, g_xz_yz_yz_yy, g_xz_yz_yz_yz, g_xz_yz_yz_zz, g_z_0_z_0_x_yz_y_xx, g_z_0_z_0_x_yz_y_xy, g_z_0_z_0_x_yz_y_xz, g_z_0_z_0_x_yz_y_yy, g_z_0_z_0_x_yz_y_yz, g_z_0_z_0_x_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yz_y_xx[i] = 4.0 * g_xz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_y_xy[i] = 4.0 * g_xz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_y_xz[i] = 4.0 * g_xz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_y_yy[i] = 4.0 * g_xz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_y_yz[i] = 4.0 * g_xz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_y_zz[i] = 4.0 * g_xz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2676-2682)

    #pragma omp simd aligned(g_xz_yz_0_xx, g_xz_yz_0_xy, g_xz_yz_0_xz, g_xz_yz_0_yy, g_xz_yz_0_yz, g_xz_yz_0_zz, g_xz_yz_zz_xx, g_xz_yz_zz_xy, g_xz_yz_zz_xz, g_xz_yz_zz_yy, g_xz_yz_zz_yz, g_xz_yz_zz_zz, g_z_0_z_0_x_yz_z_xx, g_z_0_z_0_x_yz_z_xy, g_z_0_z_0_x_yz_z_xz, g_z_0_z_0_x_yz_z_yy, g_z_0_z_0_x_yz_z_yz, g_z_0_z_0_x_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_yz_z_xx[i] = -2.0 * g_xz_yz_0_xx[i] * a_exp + 4.0 * g_xz_yz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_z_xy[i] = -2.0 * g_xz_yz_0_xy[i] * a_exp + 4.0 * g_xz_yz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_z_xz[i] = -2.0 * g_xz_yz_0_xz[i] * a_exp + 4.0 * g_xz_yz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_z_yy[i] = -2.0 * g_xz_yz_0_yy[i] * a_exp + 4.0 * g_xz_yz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_z_yz[i] = -2.0 * g_xz_yz_0_yz[i] * a_exp + 4.0 * g_xz_yz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_yz_z_zz[i] = -2.0 * g_xz_yz_0_zz[i] * a_exp + 4.0 * g_xz_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2682-2688)

    #pragma omp simd aligned(g_xz_zz_xz_xx, g_xz_zz_xz_xy, g_xz_zz_xz_xz, g_xz_zz_xz_yy, g_xz_zz_xz_yz, g_xz_zz_xz_zz, g_z_0_z_0_x_zz_x_xx, g_z_0_z_0_x_zz_x_xy, g_z_0_z_0_x_zz_x_xz, g_z_0_z_0_x_zz_x_yy, g_z_0_z_0_x_zz_x_yz, g_z_0_z_0_x_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_zz_x_xx[i] = 4.0 * g_xz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_x_xy[i] = 4.0 * g_xz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_x_xz[i] = 4.0 * g_xz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_x_yy[i] = 4.0 * g_xz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_x_yz[i] = 4.0 * g_xz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_x_zz[i] = 4.0 * g_xz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2688-2694)

    #pragma omp simd aligned(g_xz_zz_yz_xx, g_xz_zz_yz_xy, g_xz_zz_yz_xz, g_xz_zz_yz_yy, g_xz_zz_yz_yz, g_xz_zz_yz_zz, g_z_0_z_0_x_zz_y_xx, g_z_0_z_0_x_zz_y_xy, g_z_0_z_0_x_zz_y_xz, g_z_0_z_0_x_zz_y_yy, g_z_0_z_0_x_zz_y_yz, g_z_0_z_0_x_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_zz_y_xx[i] = 4.0 * g_xz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_y_xy[i] = 4.0 * g_xz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_y_xz[i] = 4.0 * g_xz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_y_yy[i] = 4.0 * g_xz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_y_yz[i] = 4.0 * g_xz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_y_zz[i] = 4.0 * g_xz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2694-2700)

    #pragma omp simd aligned(g_xz_zz_0_xx, g_xz_zz_0_xy, g_xz_zz_0_xz, g_xz_zz_0_yy, g_xz_zz_0_yz, g_xz_zz_0_zz, g_xz_zz_zz_xx, g_xz_zz_zz_xy, g_xz_zz_zz_xz, g_xz_zz_zz_yy, g_xz_zz_zz_yz, g_xz_zz_zz_zz, g_z_0_z_0_x_zz_z_xx, g_z_0_z_0_x_zz_z_xy, g_z_0_z_0_x_zz_z_xz, g_z_0_z_0_x_zz_z_yy, g_z_0_z_0_x_zz_z_yz, g_z_0_z_0_x_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_x_zz_z_xx[i] = -2.0 * g_xz_zz_0_xx[i] * a_exp + 4.0 * g_xz_zz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_z_xy[i] = -2.0 * g_xz_zz_0_xy[i] * a_exp + 4.0 * g_xz_zz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_z_xz[i] = -2.0 * g_xz_zz_0_xz[i] * a_exp + 4.0 * g_xz_zz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_z_yy[i] = -2.0 * g_xz_zz_0_yy[i] * a_exp + 4.0 * g_xz_zz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_z_yz[i] = -2.0 * g_xz_zz_0_yz[i] * a_exp + 4.0 * g_xz_zz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_x_zz_z_zz[i] = -2.0 * g_xz_zz_0_zz[i] * a_exp + 4.0 * g_xz_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2700-2706)

    #pragma omp simd aligned(g_yz_xx_xz_xx, g_yz_xx_xz_xy, g_yz_xx_xz_xz, g_yz_xx_xz_yy, g_yz_xx_xz_yz, g_yz_xx_xz_zz, g_z_0_z_0_y_xx_x_xx, g_z_0_z_0_y_xx_x_xy, g_z_0_z_0_y_xx_x_xz, g_z_0_z_0_y_xx_x_yy, g_z_0_z_0_y_xx_x_yz, g_z_0_z_0_y_xx_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xx_x_xx[i] = 4.0 * g_yz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_x_xy[i] = 4.0 * g_yz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_x_xz[i] = 4.0 * g_yz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_x_yy[i] = 4.0 * g_yz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_x_yz[i] = 4.0 * g_yz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_x_zz[i] = 4.0 * g_yz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2706-2712)

    #pragma omp simd aligned(g_yz_xx_yz_xx, g_yz_xx_yz_xy, g_yz_xx_yz_xz, g_yz_xx_yz_yy, g_yz_xx_yz_yz, g_yz_xx_yz_zz, g_z_0_z_0_y_xx_y_xx, g_z_0_z_0_y_xx_y_xy, g_z_0_z_0_y_xx_y_xz, g_z_0_z_0_y_xx_y_yy, g_z_0_z_0_y_xx_y_yz, g_z_0_z_0_y_xx_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xx_y_xx[i] = 4.0 * g_yz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_y_xy[i] = 4.0 * g_yz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_y_xz[i] = 4.0 * g_yz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_y_yy[i] = 4.0 * g_yz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_y_yz[i] = 4.0 * g_yz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_y_zz[i] = 4.0 * g_yz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2712-2718)

    #pragma omp simd aligned(g_yz_xx_0_xx, g_yz_xx_0_xy, g_yz_xx_0_xz, g_yz_xx_0_yy, g_yz_xx_0_yz, g_yz_xx_0_zz, g_yz_xx_zz_xx, g_yz_xx_zz_xy, g_yz_xx_zz_xz, g_yz_xx_zz_yy, g_yz_xx_zz_yz, g_yz_xx_zz_zz, g_z_0_z_0_y_xx_z_xx, g_z_0_z_0_y_xx_z_xy, g_z_0_z_0_y_xx_z_xz, g_z_0_z_0_y_xx_z_yy, g_z_0_z_0_y_xx_z_yz, g_z_0_z_0_y_xx_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xx_z_xx[i] = -2.0 * g_yz_xx_0_xx[i] * a_exp + 4.0 * g_yz_xx_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_z_xy[i] = -2.0 * g_yz_xx_0_xy[i] * a_exp + 4.0 * g_yz_xx_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_z_xz[i] = -2.0 * g_yz_xx_0_xz[i] * a_exp + 4.0 * g_yz_xx_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_z_yy[i] = -2.0 * g_yz_xx_0_yy[i] * a_exp + 4.0 * g_yz_xx_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_z_yz[i] = -2.0 * g_yz_xx_0_yz[i] * a_exp + 4.0 * g_yz_xx_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xx_z_zz[i] = -2.0 * g_yz_xx_0_zz[i] * a_exp + 4.0 * g_yz_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2718-2724)

    #pragma omp simd aligned(g_yz_xy_xz_xx, g_yz_xy_xz_xy, g_yz_xy_xz_xz, g_yz_xy_xz_yy, g_yz_xy_xz_yz, g_yz_xy_xz_zz, g_z_0_z_0_y_xy_x_xx, g_z_0_z_0_y_xy_x_xy, g_z_0_z_0_y_xy_x_xz, g_z_0_z_0_y_xy_x_yy, g_z_0_z_0_y_xy_x_yz, g_z_0_z_0_y_xy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xy_x_xx[i] = 4.0 * g_yz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_x_xy[i] = 4.0 * g_yz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_x_xz[i] = 4.0 * g_yz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_x_yy[i] = 4.0 * g_yz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_x_yz[i] = 4.0 * g_yz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_x_zz[i] = 4.0 * g_yz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2724-2730)

    #pragma omp simd aligned(g_yz_xy_yz_xx, g_yz_xy_yz_xy, g_yz_xy_yz_xz, g_yz_xy_yz_yy, g_yz_xy_yz_yz, g_yz_xy_yz_zz, g_z_0_z_0_y_xy_y_xx, g_z_0_z_0_y_xy_y_xy, g_z_0_z_0_y_xy_y_xz, g_z_0_z_0_y_xy_y_yy, g_z_0_z_0_y_xy_y_yz, g_z_0_z_0_y_xy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xy_y_xx[i] = 4.0 * g_yz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_y_xy[i] = 4.0 * g_yz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_y_xz[i] = 4.0 * g_yz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_y_yy[i] = 4.0 * g_yz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_y_yz[i] = 4.0 * g_yz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_y_zz[i] = 4.0 * g_yz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2730-2736)

    #pragma omp simd aligned(g_yz_xy_0_xx, g_yz_xy_0_xy, g_yz_xy_0_xz, g_yz_xy_0_yy, g_yz_xy_0_yz, g_yz_xy_0_zz, g_yz_xy_zz_xx, g_yz_xy_zz_xy, g_yz_xy_zz_xz, g_yz_xy_zz_yy, g_yz_xy_zz_yz, g_yz_xy_zz_zz, g_z_0_z_0_y_xy_z_xx, g_z_0_z_0_y_xy_z_xy, g_z_0_z_0_y_xy_z_xz, g_z_0_z_0_y_xy_z_yy, g_z_0_z_0_y_xy_z_yz, g_z_0_z_0_y_xy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xy_z_xx[i] = -2.0 * g_yz_xy_0_xx[i] * a_exp + 4.0 * g_yz_xy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_z_xy[i] = -2.0 * g_yz_xy_0_xy[i] * a_exp + 4.0 * g_yz_xy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_z_xz[i] = -2.0 * g_yz_xy_0_xz[i] * a_exp + 4.0 * g_yz_xy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_z_yy[i] = -2.0 * g_yz_xy_0_yy[i] * a_exp + 4.0 * g_yz_xy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_z_yz[i] = -2.0 * g_yz_xy_0_yz[i] * a_exp + 4.0 * g_yz_xy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xy_z_zz[i] = -2.0 * g_yz_xy_0_zz[i] * a_exp + 4.0 * g_yz_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2736-2742)

    #pragma omp simd aligned(g_yz_xz_xz_xx, g_yz_xz_xz_xy, g_yz_xz_xz_xz, g_yz_xz_xz_yy, g_yz_xz_xz_yz, g_yz_xz_xz_zz, g_z_0_z_0_y_xz_x_xx, g_z_0_z_0_y_xz_x_xy, g_z_0_z_0_y_xz_x_xz, g_z_0_z_0_y_xz_x_yy, g_z_0_z_0_y_xz_x_yz, g_z_0_z_0_y_xz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xz_x_xx[i] = 4.0 * g_yz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_x_xy[i] = 4.0 * g_yz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_x_xz[i] = 4.0 * g_yz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_x_yy[i] = 4.0 * g_yz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_x_yz[i] = 4.0 * g_yz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_x_zz[i] = 4.0 * g_yz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2742-2748)

    #pragma omp simd aligned(g_yz_xz_yz_xx, g_yz_xz_yz_xy, g_yz_xz_yz_xz, g_yz_xz_yz_yy, g_yz_xz_yz_yz, g_yz_xz_yz_zz, g_z_0_z_0_y_xz_y_xx, g_z_0_z_0_y_xz_y_xy, g_z_0_z_0_y_xz_y_xz, g_z_0_z_0_y_xz_y_yy, g_z_0_z_0_y_xz_y_yz, g_z_0_z_0_y_xz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xz_y_xx[i] = 4.0 * g_yz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_y_xy[i] = 4.0 * g_yz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_y_xz[i] = 4.0 * g_yz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_y_yy[i] = 4.0 * g_yz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_y_yz[i] = 4.0 * g_yz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_y_zz[i] = 4.0 * g_yz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2748-2754)

    #pragma omp simd aligned(g_yz_xz_0_xx, g_yz_xz_0_xy, g_yz_xz_0_xz, g_yz_xz_0_yy, g_yz_xz_0_yz, g_yz_xz_0_zz, g_yz_xz_zz_xx, g_yz_xz_zz_xy, g_yz_xz_zz_xz, g_yz_xz_zz_yy, g_yz_xz_zz_yz, g_yz_xz_zz_zz, g_z_0_z_0_y_xz_z_xx, g_z_0_z_0_y_xz_z_xy, g_z_0_z_0_y_xz_z_xz, g_z_0_z_0_y_xz_z_yy, g_z_0_z_0_y_xz_z_yz, g_z_0_z_0_y_xz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_xz_z_xx[i] = -2.0 * g_yz_xz_0_xx[i] * a_exp + 4.0 * g_yz_xz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_z_xy[i] = -2.0 * g_yz_xz_0_xy[i] * a_exp + 4.0 * g_yz_xz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_z_xz[i] = -2.0 * g_yz_xz_0_xz[i] * a_exp + 4.0 * g_yz_xz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_z_yy[i] = -2.0 * g_yz_xz_0_yy[i] * a_exp + 4.0 * g_yz_xz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_z_yz[i] = -2.0 * g_yz_xz_0_yz[i] * a_exp + 4.0 * g_yz_xz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_xz_z_zz[i] = -2.0 * g_yz_xz_0_zz[i] * a_exp + 4.0 * g_yz_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2754-2760)

    #pragma omp simd aligned(g_yz_yy_xz_xx, g_yz_yy_xz_xy, g_yz_yy_xz_xz, g_yz_yy_xz_yy, g_yz_yy_xz_yz, g_yz_yy_xz_zz, g_z_0_z_0_y_yy_x_xx, g_z_0_z_0_y_yy_x_xy, g_z_0_z_0_y_yy_x_xz, g_z_0_z_0_y_yy_x_yy, g_z_0_z_0_y_yy_x_yz, g_z_0_z_0_y_yy_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yy_x_xx[i] = 4.0 * g_yz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_x_xy[i] = 4.0 * g_yz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_x_xz[i] = 4.0 * g_yz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_x_yy[i] = 4.0 * g_yz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_x_yz[i] = 4.0 * g_yz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_x_zz[i] = 4.0 * g_yz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2760-2766)

    #pragma omp simd aligned(g_yz_yy_yz_xx, g_yz_yy_yz_xy, g_yz_yy_yz_xz, g_yz_yy_yz_yy, g_yz_yy_yz_yz, g_yz_yy_yz_zz, g_z_0_z_0_y_yy_y_xx, g_z_0_z_0_y_yy_y_xy, g_z_0_z_0_y_yy_y_xz, g_z_0_z_0_y_yy_y_yy, g_z_0_z_0_y_yy_y_yz, g_z_0_z_0_y_yy_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yy_y_xx[i] = 4.0 * g_yz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_y_xy[i] = 4.0 * g_yz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_y_xz[i] = 4.0 * g_yz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_y_yy[i] = 4.0 * g_yz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_y_yz[i] = 4.0 * g_yz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_y_zz[i] = 4.0 * g_yz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2766-2772)

    #pragma omp simd aligned(g_yz_yy_0_xx, g_yz_yy_0_xy, g_yz_yy_0_xz, g_yz_yy_0_yy, g_yz_yy_0_yz, g_yz_yy_0_zz, g_yz_yy_zz_xx, g_yz_yy_zz_xy, g_yz_yy_zz_xz, g_yz_yy_zz_yy, g_yz_yy_zz_yz, g_yz_yy_zz_zz, g_z_0_z_0_y_yy_z_xx, g_z_0_z_0_y_yy_z_xy, g_z_0_z_0_y_yy_z_xz, g_z_0_z_0_y_yy_z_yy, g_z_0_z_0_y_yy_z_yz, g_z_0_z_0_y_yy_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yy_z_xx[i] = -2.0 * g_yz_yy_0_xx[i] * a_exp + 4.0 * g_yz_yy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_z_xy[i] = -2.0 * g_yz_yy_0_xy[i] * a_exp + 4.0 * g_yz_yy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_z_xz[i] = -2.0 * g_yz_yy_0_xz[i] * a_exp + 4.0 * g_yz_yy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_z_yy[i] = -2.0 * g_yz_yy_0_yy[i] * a_exp + 4.0 * g_yz_yy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_z_yz[i] = -2.0 * g_yz_yy_0_yz[i] * a_exp + 4.0 * g_yz_yy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yy_z_zz[i] = -2.0 * g_yz_yy_0_zz[i] * a_exp + 4.0 * g_yz_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2772-2778)

    #pragma omp simd aligned(g_yz_yz_xz_xx, g_yz_yz_xz_xy, g_yz_yz_xz_xz, g_yz_yz_xz_yy, g_yz_yz_xz_yz, g_yz_yz_xz_zz, g_z_0_z_0_y_yz_x_xx, g_z_0_z_0_y_yz_x_xy, g_z_0_z_0_y_yz_x_xz, g_z_0_z_0_y_yz_x_yy, g_z_0_z_0_y_yz_x_yz, g_z_0_z_0_y_yz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yz_x_xx[i] = 4.0 * g_yz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_x_xy[i] = 4.0 * g_yz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_x_xz[i] = 4.0 * g_yz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_x_yy[i] = 4.0 * g_yz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_x_yz[i] = 4.0 * g_yz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_x_zz[i] = 4.0 * g_yz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2778-2784)

    #pragma omp simd aligned(g_yz_yz_yz_xx, g_yz_yz_yz_xy, g_yz_yz_yz_xz, g_yz_yz_yz_yy, g_yz_yz_yz_yz, g_yz_yz_yz_zz, g_z_0_z_0_y_yz_y_xx, g_z_0_z_0_y_yz_y_xy, g_z_0_z_0_y_yz_y_xz, g_z_0_z_0_y_yz_y_yy, g_z_0_z_0_y_yz_y_yz, g_z_0_z_0_y_yz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yz_y_xx[i] = 4.0 * g_yz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_y_xy[i] = 4.0 * g_yz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_y_xz[i] = 4.0 * g_yz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_y_yy[i] = 4.0 * g_yz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_y_yz[i] = 4.0 * g_yz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_y_zz[i] = 4.0 * g_yz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2784-2790)

    #pragma omp simd aligned(g_yz_yz_0_xx, g_yz_yz_0_xy, g_yz_yz_0_xz, g_yz_yz_0_yy, g_yz_yz_0_yz, g_yz_yz_0_zz, g_yz_yz_zz_xx, g_yz_yz_zz_xy, g_yz_yz_zz_xz, g_yz_yz_zz_yy, g_yz_yz_zz_yz, g_yz_yz_zz_zz, g_z_0_z_0_y_yz_z_xx, g_z_0_z_0_y_yz_z_xy, g_z_0_z_0_y_yz_z_xz, g_z_0_z_0_y_yz_z_yy, g_z_0_z_0_y_yz_z_yz, g_z_0_z_0_y_yz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_yz_z_xx[i] = -2.0 * g_yz_yz_0_xx[i] * a_exp + 4.0 * g_yz_yz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_z_xy[i] = -2.0 * g_yz_yz_0_xy[i] * a_exp + 4.0 * g_yz_yz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_z_xz[i] = -2.0 * g_yz_yz_0_xz[i] * a_exp + 4.0 * g_yz_yz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_z_yy[i] = -2.0 * g_yz_yz_0_yy[i] * a_exp + 4.0 * g_yz_yz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_z_yz[i] = -2.0 * g_yz_yz_0_yz[i] * a_exp + 4.0 * g_yz_yz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_yz_z_zz[i] = -2.0 * g_yz_yz_0_zz[i] * a_exp + 4.0 * g_yz_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2790-2796)

    #pragma omp simd aligned(g_yz_zz_xz_xx, g_yz_zz_xz_xy, g_yz_zz_xz_xz, g_yz_zz_xz_yy, g_yz_zz_xz_yz, g_yz_zz_xz_zz, g_z_0_z_0_y_zz_x_xx, g_z_0_z_0_y_zz_x_xy, g_z_0_z_0_y_zz_x_xz, g_z_0_z_0_y_zz_x_yy, g_z_0_z_0_y_zz_x_yz, g_z_0_z_0_y_zz_x_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_zz_x_xx[i] = 4.0 * g_yz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_x_xy[i] = 4.0 * g_yz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_x_xz[i] = 4.0 * g_yz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_x_yy[i] = 4.0 * g_yz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_x_yz[i] = 4.0 * g_yz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_x_zz[i] = 4.0 * g_yz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2796-2802)

    #pragma omp simd aligned(g_yz_zz_yz_xx, g_yz_zz_yz_xy, g_yz_zz_yz_xz, g_yz_zz_yz_yy, g_yz_zz_yz_yz, g_yz_zz_yz_zz, g_z_0_z_0_y_zz_y_xx, g_z_0_z_0_y_zz_y_xy, g_z_0_z_0_y_zz_y_xz, g_z_0_z_0_y_zz_y_yy, g_z_0_z_0_y_zz_y_yz, g_z_0_z_0_y_zz_y_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_zz_y_xx[i] = 4.0 * g_yz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_y_xy[i] = 4.0 * g_yz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_y_xz[i] = 4.0 * g_yz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_y_yy[i] = 4.0 * g_yz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_y_yz[i] = 4.0 * g_yz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_y_zz[i] = 4.0 * g_yz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2802-2808)

    #pragma omp simd aligned(g_yz_zz_0_xx, g_yz_zz_0_xy, g_yz_zz_0_xz, g_yz_zz_0_yy, g_yz_zz_0_yz, g_yz_zz_0_zz, g_yz_zz_zz_xx, g_yz_zz_zz_xy, g_yz_zz_zz_xz, g_yz_zz_zz_yy, g_yz_zz_zz_yz, g_yz_zz_zz_zz, g_z_0_z_0_y_zz_z_xx, g_z_0_z_0_y_zz_z_xy, g_z_0_z_0_y_zz_z_xz, g_z_0_z_0_y_zz_z_yy, g_z_0_z_0_y_zz_z_yz, g_z_0_z_0_y_zz_z_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_y_zz_z_xx[i] = -2.0 * g_yz_zz_0_xx[i] * a_exp + 4.0 * g_yz_zz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_z_xy[i] = -2.0 * g_yz_zz_0_xy[i] * a_exp + 4.0 * g_yz_zz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_z_xz[i] = -2.0 * g_yz_zz_0_xz[i] * a_exp + 4.0 * g_yz_zz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_z_yy[i] = -2.0 * g_yz_zz_0_yy[i] * a_exp + 4.0 * g_yz_zz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_z_yz[i] = -2.0 * g_yz_zz_0_yz[i] * a_exp + 4.0 * g_yz_zz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_y_zz_z_zz[i] = -2.0 * g_yz_zz_0_zz[i] * a_exp + 4.0 * g_yz_zz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2808-2814)

    #pragma omp simd aligned(g_0_xx_xz_xx, g_0_xx_xz_xy, g_0_xx_xz_xz, g_0_xx_xz_yy, g_0_xx_xz_yz, g_0_xx_xz_zz, g_z_0_z_0_z_xx_x_xx, g_z_0_z_0_z_xx_x_xy, g_z_0_z_0_z_xx_x_xz, g_z_0_z_0_z_xx_x_yy, g_z_0_z_0_z_xx_x_yz, g_z_0_z_0_z_xx_x_zz, g_zz_xx_xz_xx, g_zz_xx_xz_xy, g_zz_xx_xz_xz, g_zz_xx_xz_yy, g_zz_xx_xz_yz, g_zz_xx_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xx_x_xx[i] = -2.0 * g_0_xx_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_x_xy[i] = -2.0 * g_0_xx_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_x_xz[i] = -2.0 * g_0_xx_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_x_yy[i] = -2.0 * g_0_xx_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xx_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_x_yz[i] = -2.0 * g_0_xx_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_x_zz[i] = -2.0 * g_0_xx_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xx_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2814-2820)

    #pragma omp simd aligned(g_0_xx_yz_xx, g_0_xx_yz_xy, g_0_xx_yz_xz, g_0_xx_yz_yy, g_0_xx_yz_yz, g_0_xx_yz_zz, g_z_0_z_0_z_xx_y_xx, g_z_0_z_0_z_xx_y_xy, g_z_0_z_0_z_xx_y_xz, g_z_0_z_0_z_xx_y_yy, g_z_0_z_0_z_xx_y_yz, g_z_0_z_0_z_xx_y_zz, g_zz_xx_yz_xx, g_zz_xx_yz_xy, g_zz_xx_yz_xz, g_zz_xx_yz_yy, g_zz_xx_yz_yz, g_zz_xx_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xx_y_xx[i] = -2.0 * g_0_xx_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_y_xy[i] = -2.0 * g_0_xx_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_y_xz[i] = -2.0 * g_0_xx_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_y_yy[i] = -2.0 * g_0_xx_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xx_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_y_yz[i] = -2.0 * g_0_xx_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_y_zz[i] = -2.0 * g_0_xx_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xx_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2820-2826)

    #pragma omp simd aligned(g_0_xx_0_xx, g_0_xx_0_xy, g_0_xx_0_xz, g_0_xx_0_yy, g_0_xx_0_yz, g_0_xx_0_zz, g_0_xx_zz_xx, g_0_xx_zz_xy, g_0_xx_zz_xz, g_0_xx_zz_yy, g_0_xx_zz_yz, g_0_xx_zz_zz, g_z_0_z_0_z_xx_z_xx, g_z_0_z_0_z_xx_z_xy, g_z_0_z_0_z_xx_z_xz, g_z_0_z_0_z_xx_z_yy, g_z_0_z_0_z_xx_z_yz, g_z_0_z_0_z_xx_z_zz, g_zz_xx_0_xx, g_zz_xx_0_xy, g_zz_xx_0_xz, g_zz_xx_0_yy, g_zz_xx_0_yz, g_zz_xx_0_zz, g_zz_xx_zz_xx, g_zz_xx_zz_xy, g_zz_xx_zz_xz, g_zz_xx_zz_yy, g_zz_xx_zz_yz, g_zz_xx_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xx_z_xx[i] = g_0_xx_0_xx[i] - 2.0 * g_0_xx_zz_xx[i] * c_exps[i] - 2.0 * g_zz_xx_0_xx[i] * a_exp + 4.0 * g_zz_xx_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_z_xy[i] = g_0_xx_0_xy[i] - 2.0 * g_0_xx_zz_xy[i] * c_exps[i] - 2.0 * g_zz_xx_0_xy[i] * a_exp + 4.0 * g_zz_xx_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_z_xz[i] = g_0_xx_0_xz[i] - 2.0 * g_0_xx_zz_xz[i] * c_exps[i] - 2.0 * g_zz_xx_0_xz[i] * a_exp + 4.0 * g_zz_xx_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_z_yy[i] = g_0_xx_0_yy[i] - 2.0 * g_0_xx_zz_yy[i] * c_exps[i] - 2.0 * g_zz_xx_0_yy[i] * a_exp + 4.0 * g_zz_xx_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_z_yz[i] = g_0_xx_0_yz[i] - 2.0 * g_0_xx_zz_yz[i] * c_exps[i] - 2.0 * g_zz_xx_0_yz[i] * a_exp + 4.0 * g_zz_xx_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xx_z_zz[i] = g_0_xx_0_zz[i] - 2.0 * g_0_xx_zz_zz[i] * c_exps[i] - 2.0 * g_zz_xx_0_zz[i] * a_exp + 4.0 * g_zz_xx_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2826-2832)

    #pragma omp simd aligned(g_0_xy_xz_xx, g_0_xy_xz_xy, g_0_xy_xz_xz, g_0_xy_xz_yy, g_0_xy_xz_yz, g_0_xy_xz_zz, g_z_0_z_0_z_xy_x_xx, g_z_0_z_0_z_xy_x_xy, g_z_0_z_0_z_xy_x_xz, g_z_0_z_0_z_xy_x_yy, g_z_0_z_0_z_xy_x_yz, g_z_0_z_0_z_xy_x_zz, g_zz_xy_xz_xx, g_zz_xy_xz_xy, g_zz_xy_xz_xz, g_zz_xy_xz_yy, g_zz_xy_xz_yz, g_zz_xy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xy_x_xx[i] = -2.0 * g_0_xy_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_x_xy[i] = -2.0 * g_0_xy_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_x_xz[i] = -2.0 * g_0_xy_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_x_yy[i] = -2.0 * g_0_xy_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_x_yz[i] = -2.0 * g_0_xy_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_x_zz[i] = -2.0 * g_0_xy_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2832-2838)

    #pragma omp simd aligned(g_0_xy_yz_xx, g_0_xy_yz_xy, g_0_xy_yz_xz, g_0_xy_yz_yy, g_0_xy_yz_yz, g_0_xy_yz_zz, g_z_0_z_0_z_xy_y_xx, g_z_0_z_0_z_xy_y_xy, g_z_0_z_0_z_xy_y_xz, g_z_0_z_0_z_xy_y_yy, g_z_0_z_0_z_xy_y_yz, g_z_0_z_0_z_xy_y_zz, g_zz_xy_yz_xx, g_zz_xy_yz_xy, g_zz_xy_yz_xz, g_zz_xy_yz_yy, g_zz_xy_yz_yz, g_zz_xy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xy_y_xx[i] = -2.0 * g_0_xy_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_y_xy[i] = -2.0 * g_0_xy_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_y_xz[i] = -2.0 * g_0_xy_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_y_yy[i] = -2.0 * g_0_xy_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_y_yz[i] = -2.0 * g_0_xy_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_y_zz[i] = -2.0 * g_0_xy_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2838-2844)

    #pragma omp simd aligned(g_0_xy_0_xx, g_0_xy_0_xy, g_0_xy_0_xz, g_0_xy_0_yy, g_0_xy_0_yz, g_0_xy_0_zz, g_0_xy_zz_xx, g_0_xy_zz_xy, g_0_xy_zz_xz, g_0_xy_zz_yy, g_0_xy_zz_yz, g_0_xy_zz_zz, g_z_0_z_0_z_xy_z_xx, g_z_0_z_0_z_xy_z_xy, g_z_0_z_0_z_xy_z_xz, g_z_0_z_0_z_xy_z_yy, g_z_0_z_0_z_xy_z_yz, g_z_0_z_0_z_xy_z_zz, g_zz_xy_0_xx, g_zz_xy_0_xy, g_zz_xy_0_xz, g_zz_xy_0_yy, g_zz_xy_0_yz, g_zz_xy_0_zz, g_zz_xy_zz_xx, g_zz_xy_zz_xy, g_zz_xy_zz_xz, g_zz_xy_zz_yy, g_zz_xy_zz_yz, g_zz_xy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xy_z_xx[i] = g_0_xy_0_xx[i] - 2.0 * g_0_xy_zz_xx[i] * c_exps[i] - 2.0 * g_zz_xy_0_xx[i] * a_exp + 4.0 * g_zz_xy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_z_xy[i] = g_0_xy_0_xy[i] - 2.0 * g_0_xy_zz_xy[i] * c_exps[i] - 2.0 * g_zz_xy_0_xy[i] * a_exp + 4.0 * g_zz_xy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_z_xz[i] = g_0_xy_0_xz[i] - 2.0 * g_0_xy_zz_xz[i] * c_exps[i] - 2.0 * g_zz_xy_0_xz[i] * a_exp + 4.0 * g_zz_xy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_z_yy[i] = g_0_xy_0_yy[i] - 2.0 * g_0_xy_zz_yy[i] * c_exps[i] - 2.0 * g_zz_xy_0_yy[i] * a_exp + 4.0 * g_zz_xy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_z_yz[i] = g_0_xy_0_yz[i] - 2.0 * g_0_xy_zz_yz[i] * c_exps[i] - 2.0 * g_zz_xy_0_yz[i] * a_exp + 4.0 * g_zz_xy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xy_z_zz[i] = g_0_xy_0_zz[i] - 2.0 * g_0_xy_zz_zz[i] * c_exps[i] - 2.0 * g_zz_xy_0_zz[i] * a_exp + 4.0 * g_zz_xy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2844-2850)

    #pragma omp simd aligned(g_0_xz_xz_xx, g_0_xz_xz_xy, g_0_xz_xz_xz, g_0_xz_xz_yy, g_0_xz_xz_yz, g_0_xz_xz_zz, g_z_0_z_0_z_xz_x_xx, g_z_0_z_0_z_xz_x_xy, g_z_0_z_0_z_xz_x_xz, g_z_0_z_0_z_xz_x_yy, g_z_0_z_0_z_xz_x_yz, g_z_0_z_0_z_xz_x_zz, g_zz_xz_xz_xx, g_zz_xz_xz_xy, g_zz_xz_xz_xz, g_zz_xz_xz_yy, g_zz_xz_xz_yz, g_zz_xz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xz_x_xx[i] = -2.0 * g_0_xz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_x_xy[i] = -2.0 * g_0_xz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_x_xz[i] = -2.0 * g_0_xz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_x_yy[i] = -2.0 * g_0_xz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_xz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_x_yz[i] = -2.0 * g_0_xz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_x_zz[i] = -2.0 * g_0_xz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_xz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2850-2856)

    #pragma omp simd aligned(g_0_xz_yz_xx, g_0_xz_yz_xy, g_0_xz_yz_xz, g_0_xz_yz_yy, g_0_xz_yz_yz, g_0_xz_yz_zz, g_z_0_z_0_z_xz_y_xx, g_z_0_z_0_z_xz_y_xy, g_z_0_z_0_z_xz_y_xz, g_z_0_z_0_z_xz_y_yy, g_z_0_z_0_z_xz_y_yz, g_z_0_z_0_z_xz_y_zz, g_zz_xz_yz_xx, g_zz_xz_yz_xy, g_zz_xz_yz_xz, g_zz_xz_yz_yy, g_zz_xz_yz_yz, g_zz_xz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xz_y_xx[i] = -2.0 * g_0_xz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_y_xy[i] = -2.0 * g_0_xz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_y_xz[i] = -2.0 * g_0_xz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_y_yy[i] = -2.0 * g_0_xz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_xz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_y_yz[i] = -2.0 * g_0_xz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_y_zz[i] = -2.0 * g_0_xz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_xz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2856-2862)

    #pragma omp simd aligned(g_0_xz_0_xx, g_0_xz_0_xy, g_0_xz_0_xz, g_0_xz_0_yy, g_0_xz_0_yz, g_0_xz_0_zz, g_0_xz_zz_xx, g_0_xz_zz_xy, g_0_xz_zz_xz, g_0_xz_zz_yy, g_0_xz_zz_yz, g_0_xz_zz_zz, g_z_0_z_0_z_xz_z_xx, g_z_0_z_0_z_xz_z_xy, g_z_0_z_0_z_xz_z_xz, g_z_0_z_0_z_xz_z_yy, g_z_0_z_0_z_xz_z_yz, g_z_0_z_0_z_xz_z_zz, g_zz_xz_0_xx, g_zz_xz_0_xy, g_zz_xz_0_xz, g_zz_xz_0_yy, g_zz_xz_0_yz, g_zz_xz_0_zz, g_zz_xz_zz_xx, g_zz_xz_zz_xy, g_zz_xz_zz_xz, g_zz_xz_zz_yy, g_zz_xz_zz_yz, g_zz_xz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_xz_z_xx[i] = g_0_xz_0_xx[i] - 2.0 * g_0_xz_zz_xx[i] * c_exps[i] - 2.0 * g_zz_xz_0_xx[i] * a_exp + 4.0 * g_zz_xz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_z_xy[i] = g_0_xz_0_xy[i] - 2.0 * g_0_xz_zz_xy[i] * c_exps[i] - 2.0 * g_zz_xz_0_xy[i] * a_exp + 4.0 * g_zz_xz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_z_xz[i] = g_0_xz_0_xz[i] - 2.0 * g_0_xz_zz_xz[i] * c_exps[i] - 2.0 * g_zz_xz_0_xz[i] * a_exp + 4.0 * g_zz_xz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_z_yy[i] = g_0_xz_0_yy[i] - 2.0 * g_0_xz_zz_yy[i] * c_exps[i] - 2.0 * g_zz_xz_0_yy[i] * a_exp + 4.0 * g_zz_xz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_z_yz[i] = g_0_xz_0_yz[i] - 2.0 * g_0_xz_zz_yz[i] * c_exps[i] - 2.0 * g_zz_xz_0_yz[i] * a_exp + 4.0 * g_zz_xz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_xz_z_zz[i] = g_0_xz_0_zz[i] - 2.0 * g_0_xz_zz_zz[i] * c_exps[i] - 2.0 * g_zz_xz_0_zz[i] * a_exp + 4.0 * g_zz_xz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2862-2868)

    #pragma omp simd aligned(g_0_yy_xz_xx, g_0_yy_xz_xy, g_0_yy_xz_xz, g_0_yy_xz_yy, g_0_yy_xz_yz, g_0_yy_xz_zz, g_z_0_z_0_z_yy_x_xx, g_z_0_z_0_z_yy_x_xy, g_z_0_z_0_z_yy_x_xz, g_z_0_z_0_z_yy_x_yy, g_z_0_z_0_z_yy_x_yz, g_z_0_z_0_z_yy_x_zz, g_zz_yy_xz_xx, g_zz_yy_xz_xy, g_zz_yy_xz_xz, g_zz_yy_xz_yy, g_zz_yy_xz_yz, g_zz_yy_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yy_x_xx[i] = -2.0 * g_0_yy_xz_xx[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_x_xy[i] = -2.0 * g_0_yy_xz_xy[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_x_xz[i] = -2.0 * g_0_yy_xz_xz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_x_yy[i] = -2.0 * g_0_yy_xz_yy[i] * c_exps[i] + 4.0 * g_zz_yy_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_x_yz[i] = -2.0 * g_0_yy_xz_yz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_x_zz[i] = -2.0 * g_0_yy_xz_zz[i] * c_exps[i] + 4.0 * g_zz_yy_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2868-2874)

    #pragma omp simd aligned(g_0_yy_yz_xx, g_0_yy_yz_xy, g_0_yy_yz_xz, g_0_yy_yz_yy, g_0_yy_yz_yz, g_0_yy_yz_zz, g_z_0_z_0_z_yy_y_xx, g_z_0_z_0_z_yy_y_xy, g_z_0_z_0_z_yy_y_xz, g_z_0_z_0_z_yy_y_yy, g_z_0_z_0_z_yy_y_yz, g_z_0_z_0_z_yy_y_zz, g_zz_yy_yz_xx, g_zz_yy_yz_xy, g_zz_yy_yz_xz, g_zz_yy_yz_yy, g_zz_yy_yz_yz, g_zz_yy_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yy_y_xx[i] = -2.0 * g_0_yy_yz_xx[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_y_xy[i] = -2.0 * g_0_yy_yz_xy[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_y_xz[i] = -2.0 * g_0_yy_yz_xz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_y_yy[i] = -2.0 * g_0_yy_yz_yy[i] * c_exps[i] + 4.0 * g_zz_yy_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_y_yz[i] = -2.0 * g_0_yy_yz_yz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_y_zz[i] = -2.0 * g_0_yy_yz_zz[i] * c_exps[i] + 4.0 * g_zz_yy_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2874-2880)

    #pragma omp simd aligned(g_0_yy_0_xx, g_0_yy_0_xy, g_0_yy_0_xz, g_0_yy_0_yy, g_0_yy_0_yz, g_0_yy_0_zz, g_0_yy_zz_xx, g_0_yy_zz_xy, g_0_yy_zz_xz, g_0_yy_zz_yy, g_0_yy_zz_yz, g_0_yy_zz_zz, g_z_0_z_0_z_yy_z_xx, g_z_0_z_0_z_yy_z_xy, g_z_0_z_0_z_yy_z_xz, g_z_0_z_0_z_yy_z_yy, g_z_0_z_0_z_yy_z_yz, g_z_0_z_0_z_yy_z_zz, g_zz_yy_0_xx, g_zz_yy_0_xy, g_zz_yy_0_xz, g_zz_yy_0_yy, g_zz_yy_0_yz, g_zz_yy_0_zz, g_zz_yy_zz_xx, g_zz_yy_zz_xy, g_zz_yy_zz_xz, g_zz_yy_zz_yy, g_zz_yy_zz_yz, g_zz_yy_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yy_z_xx[i] = g_0_yy_0_xx[i] - 2.0 * g_0_yy_zz_xx[i] * c_exps[i] - 2.0 * g_zz_yy_0_xx[i] * a_exp + 4.0 * g_zz_yy_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_z_xy[i] = g_0_yy_0_xy[i] - 2.0 * g_0_yy_zz_xy[i] * c_exps[i] - 2.0 * g_zz_yy_0_xy[i] * a_exp + 4.0 * g_zz_yy_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_z_xz[i] = g_0_yy_0_xz[i] - 2.0 * g_0_yy_zz_xz[i] * c_exps[i] - 2.0 * g_zz_yy_0_xz[i] * a_exp + 4.0 * g_zz_yy_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_z_yy[i] = g_0_yy_0_yy[i] - 2.0 * g_0_yy_zz_yy[i] * c_exps[i] - 2.0 * g_zz_yy_0_yy[i] * a_exp + 4.0 * g_zz_yy_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_z_yz[i] = g_0_yy_0_yz[i] - 2.0 * g_0_yy_zz_yz[i] * c_exps[i] - 2.0 * g_zz_yy_0_yz[i] * a_exp + 4.0 * g_zz_yy_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yy_z_zz[i] = g_0_yy_0_zz[i] - 2.0 * g_0_yy_zz_zz[i] * c_exps[i] - 2.0 * g_zz_yy_0_zz[i] * a_exp + 4.0 * g_zz_yy_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2880-2886)

    #pragma omp simd aligned(g_0_yz_xz_xx, g_0_yz_xz_xy, g_0_yz_xz_xz, g_0_yz_xz_yy, g_0_yz_xz_yz, g_0_yz_xz_zz, g_z_0_z_0_z_yz_x_xx, g_z_0_z_0_z_yz_x_xy, g_z_0_z_0_z_yz_x_xz, g_z_0_z_0_z_yz_x_yy, g_z_0_z_0_z_yz_x_yz, g_z_0_z_0_z_yz_x_zz, g_zz_yz_xz_xx, g_zz_yz_xz_xy, g_zz_yz_xz_xz, g_zz_yz_xz_yy, g_zz_yz_xz_yz, g_zz_yz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yz_x_xx[i] = -2.0 * g_0_yz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_x_xy[i] = -2.0 * g_0_yz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_x_xz[i] = -2.0 * g_0_yz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_x_yy[i] = -2.0 * g_0_yz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_yz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_x_yz[i] = -2.0 * g_0_yz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_x_zz[i] = -2.0 * g_0_yz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_yz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2886-2892)

    #pragma omp simd aligned(g_0_yz_yz_xx, g_0_yz_yz_xy, g_0_yz_yz_xz, g_0_yz_yz_yy, g_0_yz_yz_yz, g_0_yz_yz_zz, g_z_0_z_0_z_yz_y_xx, g_z_0_z_0_z_yz_y_xy, g_z_0_z_0_z_yz_y_xz, g_z_0_z_0_z_yz_y_yy, g_z_0_z_0_z_yz_y_yz, g_z_0_z_0_z_yz_y_zz, g_zz_yz_yz_xx, g_zz_yz_yz_xy, g_zz_yz_yz_xz, g_zz_yz_yz_yy, g_zz_yz_yz_yz, g_zz_yz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yz_y_xx[i] = -2.0 * g_0_yz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_y_xy[i] = -2.0 * g_0_yz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_y_xz[i] = -2.0 * g_0_yz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_y_yy[i] = -2.0 * g_0_yz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_yz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_y_yz[i] = -2.0 * g_0_yz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_y_zz[i] = -2.0 * g_0_yz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_yz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2892-2898)

    #pragma omp simd aligned(g_0_yz_0_xx, g_0_yz_0_xy, g_0_yz_0_xz, g_0_yz_0_yy, g_0_yz_0_yz, g_0_yz_0_zz, g_0_yz_zz_xx, g_0_yz_zz_xy, g_0_yz_zz_xz, g_0_yz_zz_yy, g_0_yz_zz_yz, g_0_yz_zz_zz, g_z_0_z_0_z_yz_z_xx, g_z_0_z_0_z_yz_z_xy, g_z_0_z_0_z_yz_z_xz, g_z_0_z_0_z_yz_z_yy, g_z_0_z_0_z_yz_z_yz, g_z_0_z_0_z_yz_z_zz, g_zz_yz_0_xx, g_zz_yz_0_xy, g_zz_yz_0_xz, g_zz_yz_0_yy, g_zz_yz_0_yz, g_zz_yz_0_zz, g_zz_yz_zz_xx, g_zz_yz_zz_xy, g_zz_yz_zz_xz, g_zz_yz_zz_yy, g_zz_yz_zz_yz, g_zz_yz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_yz_z_xx[i] = g_0_yz_0_xx[i] - 2.0 * g_0_yz_zz_xx[i] * c_exps[i] - 2.0 * g_zz_yz_0_xx[i] * a_exp + 4.0 * g_zz_yz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_z_xy[i] = g_0_yz_0_xy[i] - 2.0 * g_0_yz_zz_xy[i] * c_exps[i] - 2.0 * g_zz_yz_0_xy[i] * a_exp + 4.0 * g_zz_yz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_z_xz[i] = g_0_yz_0_xz[i] - 2.0 * g_0_yz_zz_xz[i] * c_exps[i] - 2.0 * g_zz_yz_0_xz[i] * a_exp + 4.0 * g_zz_yz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_z_yy[i] = g_0_yz_0_yy[i] - 2.0 * g_0_yz_zz_yy[i] * c_exps[i] - 2.0 * g_zz_yz_0_yy[i] * a_exp + 4.0 * g_zz_yz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_z_yz[i] = g_0_yz_0_yz[i] - 2.0 * g_0_yz_zz_yz[i] * c_exps[i] - 2.0 * g_zz_yz_0_yz[i] * a_exp + 4.0 * g_zz_yz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_yz_z_zz[i] = g_0_yz_0_zz[i] - 2.0 * g_0_yz_zz_zz[i] * c_exps[i] - 2.0 * g_zz_yz_0_zz[i] * a_exp + 4.0 * g_zz_yz_zz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2898-2904)

    #pragma omp simd aligned(g_0_zz_xz_xx, g_0_zz_xz_xy, g_0_zz_xz_xz, g_0_zz_xz_yy, g_0_zz_xz_yz, g_0_zz_xz_zz, g_z_0_z_0_z_zz_x_xx, g_z_0_z_0_z_zz_x_xy, g_z_0_z_0_z_zz_x_xz, g_z_0_z_0_z_zz_x_yy, g_z_0_z_0_z_zz_x_yz, g_z_0_z_0_z_zz_x_zz, g_zz_zz_xz_xx, g_zz_zz_xz_xy, g_zz_zz_xz_xz, g_zz_zz_xz_yy, g_zz_zz_xz_yz, g_zz_zz_xz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_zz_x_xx[i] = -2.0 * g_0_zz_xz_xx[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_x_xy[i] = -2.0 * g_0_zz_xz_xy[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_x_xz[i] = -2.0 * g_0_zz_xz_xz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_x_yy[i] = -2.0 * g_0_zz_xz_yy[i] * c_exps[i] + 4.0 * g_zz_zz_xz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_x_yz[i] = -2.0 * g_0_zz_xz_yz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_x_zz[i] = -2.0 * g_0_zz_xz_zz[i] * c_exps[i] + 4.0 * g_zz_zz_xz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2904-2910)

    #pragma omp simd aligned(g_0_zz_yz_xx, g_0_zz_yz_xy, g_0_zz_yz_xz, g_0_zz_yz_yy, g_0_zz_yz_yz, g_0_zz_yz_zz, g_z_0_z_0_z_zz_y_xx, g_z_0_z_0_z_zz_y_xy, g_z_0_z_0_z_zz_y_xz, g_z_0_z_0_z_zz_y_yy, g_z_0_z_0_z_zz_y_yz, g_z_0_z_0_z_zz_y_zz, g_zz_zz_yz_xx, g_zz_zz_yz_xy, g_zz_zz_yz_xz, g_zz_zz_yz_yy, g_zz_zz_yz_yz, g_zz_zz_yz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_zz_y_xx[i] = -2.0 * g_0_zz_yz_xx[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_y_xy[i] = -2.0 * g_0_zz_yz_xy[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_y_xz[i] = -2.0 * g_0_zz_yz_xz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_y_yy[i] = -2.0 * g_0_zz_yz_yy[i] * c_exps[i] + 4.0 * g_zz_zz_yz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_y_yz[i] = -2.0 * g_0_zz_yz_yz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_y_zz[i] = -2.0 * g_0_zz_yz_zz[i] * c_exps[i] + 4.0 * g_zz_zz_yz_zz[i] * a_exp * c_exps[i];
    }
    // integrals block (2910-2916)

    #pragma omp simd aligned(g_0_zz_0_xx, g_0_zz_0_xy, g_0_zz_0_xz, g_0_zz_0_yy, g_0_zz_0_yz, g_0_zz_0_zz, g_0_zz_zz_xx, g_0_zz_zz_xy, g_0_zz_zz_xz, g_0_zz_zz_yy, g_0_zz_zz_yz, g_0_zz_zz_zz, g_z_0_z_0_z_zz_z_xx, g_z_0_z_0_z_zz_z_xy, g_z_0_z_0_z_zz_z_xz, g_z_0_z_0_z_zz_z_yy, g_z_0_z_0_z_zz_z_yz, g_z_0_z_0_z_zz_z_zz, g_zz_zz_0_xx, g_zz_zz_0_xy, g_zz_zz_0_xz, g_zz_zz_0_yy, g_zz_zz_0_yz, g_zz_zz_0_zz, g_zz_zz_zz_xx, g_zz_zz_zz_xy, g_zz_zz_zz_xz, g_zz_zz_zz_yy, g_zz_zz_zz_yz, g_zz_zz_zz_zz, c_exps  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_z_0_z_0_z_zz_z_xx[i] = g_0_zz_0_xx[i] - 2.0 * g_0_zz_zz_xx[i] * c_exps[i] - 2.0 * g_zz_zz_0_xx[i] * a_exp + 4.0 * g_zz_zz_zz_xx[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_z_xy[i] = g_0_zz_0_xy[i] - 2.0 * g_0_zz_zz_xy[i] * c_exps[i] - 2.0 * g_zz_zz_0_xy[i] * a_exp + 4.0 * g_zz_zz_zz_xy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_z_xz[i] = g_0_zz_0_xz[i] - 2.0 * g_0_zz_zz_xz[i] * c_exps[i] - 2.0 * g_zz_zz_0_xz[i] * a_exp + 4.0 * g_zz_zz_zz_xz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_z_yy[i] = g_0_zz_0_yy[i] - 2.0 * g_0_zz_zz_yy[i] * c_exps[i] - 2.0 * g_zz_zz_0_yy[i] * a_exp + 4.0 * g_zz_zz_zz_yy[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_z_yz[i] = g_0_zz_0_yz[i] - 2.0 * g_0_zz_zz_yz[i] * c_exps[i] - 2.0 * g_zz_zz_0_yz[i] * a_exp + 4.0 * g_zz_zz_zz_yz[i] * a_exp * c_exps[i];

        g_z_0_z_0_z_zz_z_zz[i] = g_0_zz_0_zz[i] - 2.0 * g_0_zz_zz_zz[i] * c_exps[i] - 2.0 * g_zz_zz_0_zz[i] * a_exp + 4.0 * g_zz_zz_zz_zz[i] * a_exp * c_exps[i];
    }
}

} // t4c_geom namespace

