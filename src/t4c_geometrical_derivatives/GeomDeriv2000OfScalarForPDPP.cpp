#include "GeomDeriv2000OfScalarForPDPP.hpp"

namespace t4c_geom { // t4c_geom namespace

auto
comp_geom2000_pdpp_0(CSimdArray<double>& buffer_2000_pdpp,
                     const CSimdArray<double>& buffer_pdpp,
                     const CSimdArray<double>& buffer_fdpp,
                     const double a_exp) -> void
{
    const auto ndims = buffer_2000_pdpp.number_of_columns();

    /// Set up components of auxilary buffer : buffer_pdpp

    auto g_x_xx_x_x = buffer_pdpp[0];

    auto g_x_xx_x_y = buffer_pdpp[1];

    auto g_x_xx_x_z = buffer_pdpp[2];

    auto g_x_xx_y_x = buffer_pdpp[3];

    auto g_x_xx_y_y = buffer_pdpp[4];

    auto g_x_xx_y_z = buffer_pdpp[5];

    auto g_x_xx_z_x = buffer_pdpp[6];

    auto g_x_xx_z_y = buffer_pdpp[7];

    auto g_x_xx_z_z = buffer_pdpp[8];

    auto g_x_xy_x_x = buffer_pdpp[9];

    auto g_x_xy_x_y = buffer_pdpp[10];

    auto g_x_xy_x_z = buffer_pdpp[11];

    auto g_x_xy_y_x = buffer_pdpp[12];

    auto g_x_xy_y_y = buffer_pdpp[13];

    auto g_x_xy_y_z = buffer_pdpp[14];

    auto g_x_xy_z_x = buffer_pdpp[15];

    auto g_x_xy_z_y = buffer_pdpp[16];

    auto g_x_xy_z_z = buffer_pdpp[17];

    auto g_x_xz_x_x = buffer_pdpp[18];

    auto g_x_xz_x_y = buffer_pdpp[19];

    auto g_x_xz_x_z = buffer_pdpp[20];

    auto g_x_xz_y_x = buffer_pdpp[21];

    auto g_x_xz_y_y = buffer_pdpp[22];

    auto g_x_xz_y_z = buffer_pdpp[23];

    auto g_x_xz_z_x = buffer_pdpp[24];

    auto g_x_xz_z_y = buffer_pdpp[25];

    auto g_x_xz_z_z = buffer_pdpp[26];

    auto g_x_yy_x_x = buffer_pdpp[27];

    auto g_x_yy_x_y = buffer_pdpp[28];

    auto g_x_yy_x_z = buffer_pdpp[29];

    auto g_x_yy_y_x = buffer_pdpp[30];

    auto g_x_yy_y_y = buffer_pdpp[31];

    auto g_x_yy_y_z = buffer_pdpp[32];

    auto g_x_yy_z_x = buffer_pdpp[33];

    auto g_x_yy_z_y = buffer_pdpp[34];

    auto g_x_yy_z_z = buffer_pdpp[35];

    auto g_x_yz_x_x = buffer_pdpp[36];

    auto g_x_yz_x_y = buffer_pdpp[37];

    auto g_x_yz_x_z = buffer_pdpp[38];

    auto g_x_yz_y_x = buffer_pdpp[39];

    auto g_x_yz_y_y = buffer_pdpp[40];

    auto g_x_yz_y_z = buffer_pdpp[41];

    auto g_x_yz_z_x = buffer_pdpp[42];

    auto g_x_yz_z_y = buffer_pdpp[43];

    auto g_x_yz_z_z = buffer_pdpp[44];

    auto g_x_zz_x_x = buffer_pdpp[45];

    auto g_x_zz_x_y = buffer_pdpp[46];

    auto g_x_zz_x_z = buffer_pdpp[47];

    auto g_x_zz_y_x = buffer_pdpp[48];

    auto g_x_zz_y_y = buffer_pdpp[49];

    auto g_x_zz_y_z = buffer_pdpp[50];

    auto g_x_zz_z_x = buffer_pdpp[51];

    auto g_x_zz_z_y = buffer_pdpp[52];

    auto g_x_zz_z_z = buffer_pdpp[53];

    auto g_y_xx_x_x = buffer_pdpp[54];

    auto g_y_xx_x_y = buffer_pdpp[55];

    auto g_y_xx_x_z = buffer_pdpp[56];

    auto g_y_xx_y_x = buffer_pdpp[57];

    auto g_y_xx_y_y = buffer_pdpp[58];

    auto g_y_xx_y_z = buffer_pdpp[59];

    auto g_y_xx_z_x = buffer_pdpp[60];

    auto g_y_xx_z_y = buffer_pdpp[61];

    auto g_y_xx_z_z = buffer_pdpp[62];

    auto g_y_xy_x_x = buffer_pdpp[63];

    auto g_y_xy_x_y = buffer_pdpp[64];

    auto g_y_xy_x_z = buffer_pdpp[65];

    auto g_y_xy_y_x = buffer_pdpp[66];

    auto g_y_xy_y_y = buffer_pdpp[67];

    auto g_y_xy_y_z = buffer_pdpp[68];

    auto g_y_xy_z_x = buffer_pdpp[69];

    auto g_y_xy_z_y = buffer_pdpp[70];

    auto g_y_xy_z_z = buffer_pdpp[71];

    auto g_y_xz_x_x = buffer_pdpp[72];

    auto g_y_xz_x_y = buffer_pdpp[73];

    auto g_y_xz_x_z = buffer_pdpp[74];

    auto g_y_xz_y_x = buffer_pdpp[75];

    auto g_y_xz_y_y = buffer_pdpp[76];

    auto g_y_xz_y_z = buffer_pdpp[77];

    auto g_y_xz_z_x = buffer_pdpp[78];

    auto g_y_xz_z_y = buffer_pdpp[79];

    auto g_y_xz_z_z = buffer_pdpp[80];

    auto g_y_yy_x_x = buffer_pdpp[81];

    auto g_y_yy_x_y = buffer_pdpp[82];

    auto g_y_yy_x_z = buffer_pdpp[83];

    auto g_y_yy_y_x = buffer_pdpp[84];

    auto g_y_yy_y_y = buffer_pdpp[85];

    auto g_y_yy_y_z = buffer_pdpp[86];

    auto g_y_yy_z_x = buffer_pdpp[87];

    auto g_y_yy_z_y = buffer_pdpp[88];

    auto g_y_yy_z_z = buffer_pdpp[89];

    auto g_y_yz_x_x = buffer_pdpp[90];

    auto g_y_yz_x_y = buffer_pdpp[91];

    auto g_y_yz_x_z = buffer_pdpp[92];

    auto g_y_yz_y_x = buffer_pdpp[93];

    auto g_y_yz_y_y = buffer_pdpp[94];

    auto g_y_yz_y_z = buffer_pdpp[95];

    auto g_y_yz_z_x = buffer_pdpp[96];

    auto g_y_yz_z_y = buffer_pdpp[97];

    auto g_y_yz_z_z = buffer_pdpp[98];

    auto g_y_zz_x_x = buffer_pdpp[99];

    auto g_y_zz_x_y = buffer_pdpp[100];

    auto g_y_zz_x_z = buffer_pdpp[101];

    auto g_y_zz_y_x = buffer_pdpp[102];

    auto g_y_zz_y_y = buffer_pdpp[103];

    auto g_y_zz_y_z = buffer_pdpp[104];

    auto g_y_zz_z_x = buffer_pdpp[105];

    auto g_y_zz_z_y = buffer_pdpp[106];

    auto g_y_zz_z_z = buffer_pdpp[107];

    auto g_z_xx_x_x = buffer_pdpp[108];

    auto g_z_xx_x_y = buffer_pdpp[109];

    auto g_z_xx_x_z = buffer_pdpp[110];

    auto g_z_xx_y_x = buffer_pdpp[111];

    auto g_z_xx_y_y = buffer_pdpp[112];

    auto g_z_xx_y_z = buffer_pdpp[113];

    auto g_z_xx_z_x = buffer_pdpp[114];

    auto g_z_xx_z_y = buffer_pdpp[115];

    auto g_z_xx_z_z = buffer_pdpp[116];

    auto g_z_xy_x_x = buffer_pdpp[117];

    auto g_z_xy_x_y = buffer_pdpp[118];

    auto g_z_xy_x_z = buffer_pdpp[119];

    auto g_z_xy_y_x = buffer_pdpp[120];

    auto g_z_xy_y_y = buffer_pdpp[121];

    auto g_z_xy_y_z = buffer_pdpp[122];

    auto g_z_xy_z_x = buffer_pdpp[123];

    auto g_z_xy_z_y = buffer_pdpp[124];

    auto g_z_xy_z_z = buffer_pdpp[125];

    auto g_z_xz_x_x = buffer_pdpp[126];

    auto g_z_xz_x_y = buffer_pdpp[127];

    auto g_z_xz_x_z = buffer_pdpp[128];

    auto g_z_xz_y_x = buffer_pdpp[129];

    auto g_z_xz_y_y = buffer_pdpp[130];

    auto g_z_xz_y_z = buffer_pdpp[131];

    auto g_z_xz_z_x = buffer_pdpp[132];

    auto g_z_xz_z_y = buffer_pdpp[133];

    auto g_z_xz_z_z = buffer_pdpp[134];

    auto g_z_yy_x_x = buffer_pdpp[135];

    auto g_z_yy_x_y = buffer_pdpp[136];

    auto g_z_yy_x_z = buffer_pdpp[137];

    auto g_z_yy_y_x = buffer_pdpp[138];

    auto g_z_yy_y_y = buffer_pdpp[139];

    auto g_z_yy_y_z = buffer_pdpp[140];

    auto g_z_yy_z_x = buffer_pdpp[141];

    auto g_z_yy_z_y = buffer_pdpp[142];

    auto g_z_yy_z_z = buffer_pdpp[143];

    auto g_z_yz_x_x = buffer_pdpp[144];

    auto g_z_yz_x_y = buffer_pdpp[145];

    auto g_z_yz_x_z = buffer_pdpp[146];

    auto g_z_yz_y_x = buffer_pdpp[147];

    auto g_z_yz_y_y = buffer_pdpp[148];

    auto g_z_yz_y_z = buffer_pdpp[149];

    auto g_z_yz_z_x = buffer_pdpp[150];

    auto g_z_yz_z_y = buffer_pdpp[151];

    auto g_z_yz_z_z = buffer_pdpp[152];

    auto g_z_zz_x_x = buffer_pdpp[153];

    auto g_z_zz_x_y = buffer_pdpp[154];

    auto g_z_zz_x_z = buffer_pdpp[155];

    auto g_z_zz_y_x = buffer_pdpp[156];

    auto g_z_zz_y_y = buffer_pdpp[157];

    auto g_z_zz_y_z = buffer_pdpp[158];

    auto g_z_zz_z_x = buffer_pdpp[159];

    auto g_z_zz_z_y = buffer_pdpp[160];

    auto g_z_zz_z_z = buffer_pdpp[161];

    /// Set up components of auxilary buffer : buffer_fdpp

    auto g_xxx_xx_x_x = buffer_fdpp[0];

    auto g_xxx_xx_x_y = buffer_fdpp[1];

    auto g_xxx_xx_x_z = buffer_fdpp[2];

    auto g_xxx_xx_y_x = buffer_fdpp[3];

    auto g_xxx_xx_y_y = buffer_fdpp[4];

    auto g_xxx_xx_y_z = buffer_fdpp[5];

    auto g_xxx_xx_z_x = buffer_fdpp[6];

    auto g_xxx_xx_z_y = buffer_fdpp[7];

    auto g_xxx_xx_z_z = buffer_fdpp[8];

    auto g_xxx_xy_x_x = buffer_fdpp[9];

    auto g_xxx_xy_x_y = buffer_fdpp[10];

    auto g_xxx_xy_x_z = buffer_fdpp[11];

    auto g_xxx_xy_y_x = buffer_fdpp[12];

    auto g_xxx_xy_y_y = buffer_fdpp[13];

    auto g_xxx_xy_y_z = buffer_fdpp[14];

    auto g_xxx_xy_z_x = buffer_fdpp[15];

    auto g_xxx_xy_z_y = buffer_fdpp[16];

    auto g_xxx_xy_z_z = buffer_fdpp[17];

    auto g_xxx_xz_x_x = buffer_fdpp[18];

    auto g_xxx_xz_x_y = buffer_fdpp[19];

    auto g_xxx_xz_x_z = buffer_fdpp[20];

    auto g_xxx_xz_y_x = buffer_fdpp[21];

    auto g_xxx_xz_y_y = buffer_fdpp[22];

    auto g_xxx_xz_y_z = buffer_fdpp[23];

    auto g_xxx_xz_z_x = buffer_fdpp[24];

    auto g_xxx_xz_z_y = buffer_fdpp[25];

    auto g_xxx_xz_z_z = buffer_fdpp[26];

    auto g_xxx_yy_x_x = buffer_fdpp[27];

    auto g_xxx_yy_x_y = buffer_fdpp[28];

    auto g_xxx_yy_x_z = buffer_fdpp[29];

    auto g_xxx_yy_y_x = buffer_fdpp[30];

    auto g_xxx_yy_y_y = buffer_fdpp[31];

    auto g_xxx_yy_y_z = buffer_fdpp[32];

    auto g_xxx_yy_z_x = buffer_fdpp[33];

    auto g_xxx_yy_z_y = buffer_fdpp[34];

    auto g_xxx_yy_z_z = buffer_fdpp[35];

    auto g_xxx_yz_x_x = buffer_fdpp[36];

    auto g_xxx_yz_x_y = buffer_fdpp[37];

    auto g_xxx_yz_x_z = buffer_fdpp[38];

    auto g_xxx_yz_y_x = buffer_fdpp[39];

    auto g_xxx_yz_y_y = buffer_fdpp[40];

    auto g_xxx_yz_y_z = buffer_fdpp[41];

    auto g_xxx_yz_z_x = buffer_fdpp[42];

    auto g_xxx_yz_z_y = buffer_fdpp[43];

    auto g_xxx_yz_z_z = buffer_fdpp[44];

    auto g_xxx_zz_x_x = buffer_fdpp[45];

    auto g_xxx_zz_x_y = buffer_fdpp[46];

    auto g_xxx_zz_x_z = buffer_fdpp[47];

    auto g_xxx_zz_y_x = buffer_fdpp[48];

    auto g_xxx_zz_y_y = buffer_fdpp[49];

    auto g_xxx_zz_y_z = buffer_fdpp[50];

    auto g_xxx_zz_z_x = buffer_fdpp[51];

    auto g_xxx_zz_z_y = buffer_fdpp[52];

    auto g_xxx_zz_z_z = buffer_fdpp[53];

    auto g_xxy_xx_x_x = buffer_fdpp[54];

    auto g_xxy_xx_x_y = buffer_fdpp[55];

    auto g_xxy_xx_x_z = buffer_fdpp[56];

    auto g_xxy_xx_y_x = buffer_fdpp[57];

    auto g_xxy_xx_y_y = buffer_fdpp[58];

    auto g_xxy_xx_y_z = buffer_fdpp[59];

    auto g_xxy_xx_z_x = buffer_fdpp[60];

    auto g_xxy_xx_z_y = buffer_fdpp[61];

    auto g_xxy_xx_z_z = buffer_fdpp[62];

    auto g_xxy_xy_x_x = buffer_fdpp[63];

    auto g_xxy_xy_x_y = buffer_fdpp[64];

    auto g_xxy_xy_x_z = buffer_fdpp[65];

    auto g_xxy_xy_y_x = buffer_fdpp[66];

    auto g_xxy_xy_y_y = buffer_fdpp[67];

    auto g_xxy_xy_y_z = buffer_fdpp[68];

    auto g_xxy_xy_z_x = buffer_fdpp[69];

    auto g_xxy_xy_z_y = buffer_fdpp[70];

    auto g_xxy_xy_z_z = buffer_fdpp[71];

    auto g_xxy_xz_x_x = buffer_fdpp[72];

    auto g_xxy_xz_x_y = buffer_fdpp[73];

    auto g_xxy_xz_x_z = buffer_fdpp[74];

    auto g_xxy_xz_y_x = buffer_fdpp[75];

    auto g_xxy_xz_y_y = buffer_fdpp[76];

    auto g_xxy_xz_y_z = buffer_fdpp[77];

    auto g_xxy_xz_z_x = buffer_fdpp[78];

    auto g_xxy_xz_z_y = buffer_fdpp[79];

    auto g_xxy_xz_z_z = buffer_fdpp[80];

    auto g_xxy_yy_x_x = buffer_fdpp[81];

    auto g_xxy_yy_x_y = buffer_fdpp[82];

    auto g_xxy_yy_x_z = buffer_fdpp[83];

    auto g_xxy_yy_y_x = buffer_fdpp[84];

    auto g_xxy_yy_y_y = buffer_fdpp[85];

    auto g_xxy_yy_y_z = buffer_fdpp[86];

    auto g_xxy_yy_z_x = buffer_fdpp[87];

    auto g_xxy_yy_z_y = buffer_fdpp[88];

    auto g_xxy_yy_z_z = buffer_fdpp[89];

    auto g_xxy_yz_x_x = buffer_fdpp[90];

    auto g_xxy_yz_x_y = buffer_fdpp[91];

    auto g_xxy_yz_x_z = buffer_fdpp[92];

    auto g_xxy_yz_y_x = buffer_fdpp[93];

    auto g_xxy_yz_y_y = buffer_fdpp[94];

    auto g_xxy_yz_y_z = buffer_fdpp[95];

    auto g_xxy_yz_z_x = buffer_fdpp[96];

    auto g_xxy_yz_z_y = buffer_fdpp[97];

    auto g_xxy_yz_z_z = buffer_fdpp[98];

    auto g_xxy_zz_x_x = buffer_fdpp[99];

    auto g_xxy_zz_x_y = buffer_fdpp[100];

    auto g_xxy_zz_x_z = buffer_fdpp[101];

    auto g_xxy_zz_y_x = buffer_fdpp[102];

    auto g_xxy_zz_y_y = buffer_fdpp[103];

    auto g_xxy_zz_y_z = buffer_fdpp[104];

    auto g_xxy_zz_z_x = buffer_fdpp[105];

    auto g_xxy_zz_z_y = buffer_fdpp[106];

    auto g_xxy_zz_z_z = buffer_fdpp[107];

    auto g_xxz_xx_x_x = buffer_fdpp[108];

    auto g_xxz_xx_x_y = buffer_fdpp[109];

    auto g_xxz_xx_x_z = buffer_fdpp[110];

    auto g_xxz_xx_y_x = buffer_fdpp[111];

    auto g_xxz_xx_y_y = buffer_fdpp[112];

    auto g_xxz_xx_y_z = buffer_fdpp[113];

    auto g_xxz_xx_z_x = buffer_fdpp[114];

    auto g_xxz_xx_z_y = buffer_fdpp[115];

    auto g_xxz_xx_z_z = buffer_fdpp[116];

    auto g_xxz_xy_x_x = buffer_fdpp[117];

    auto g_xxz_xy_x_y = buffer_fdpp[118];

    auto g_xxz_xy_x_z = buffer_fdpp[119];

    auto g_xxz_xy_y_x = buffer_fdpp[120];

    auto g_xxz_xy_y_y = buffer_fdpp[121];

    auto g_xxz_xy_y_z = buffer_fdpp[122];

    auto g_xxz_xy_z_x = buffer_fdpp[123];

    auto g_xxz_xy_z_y = buffer_fdpp[124];

    auto g_xxz_xy_z_z = buffer_fdpp[125];

    auto g_xxz_xz_x_x = buffer_fdpp[126];

    auto g_xxz_xz_x_y = buffer_fdpp[127];

    auto g_xxz_xz_x_z = buffer_fdpp[128];

    auto g_xxz_xz_y_x = buffer_fdpp[129];

    auto g_xxz_xz_y_y = buffer_fdpp[130];

    auto g_xxz_xz_y_z = buffer_fdpp[131];

    auto g_xxz_xz_z_x = buffer_fdpp[132];

    auto g_xxz_xz_z_y = buffer_fdpp[133];

    auto g_xxz_xz_z_z = buffer_fdpp[134];

    auto g_xxz_yy_x_x = buffer_fdpp[135];

    auto g_xxz_yy_x_y = buffer_fdpp[136];

    auto g_xxz_yy_x_z = buffer_fdpp[137];

    auto g_xxz_yy_y_x = buffer_fdpp[138];

    auto g_xxz_yy_y_y = buffer_fdpp[139];

    auto g_xxz_yy_y_z = buffer_fdpp[140];

    auto g_xxz_yy_z_x = buffer_fdpp[141];

    auto g_xxz_yy_z_y = buffer_fdpp[142];

    auto g_xxz_yy_z_z = buffer_fdpp[143];

    auto g_xxz_yz_x_x = buffer_fdpp[144];

    auto g_xxz_yz_x_y = buffer_fdpp[145];

    auto g_xxz_yz_x_z = buffer_fdpp[146];

    auto g_xxz_yz_y_x = buffer_fdpp[147];

    auto g_xxz_yz_y_y = buffer_fdpp[148];

    auto g_xxz_yz_y_z = buffer_fdpp[149];

    auto g_xxz_yz_z_x = buffer_fdpp[150];

    auto g_xxz_yz_z_y = buffer_fdpp[151];

    auto g_xxz_yz_z_z = buffer_fdpp[152];

    auto g_xxz_zz_x_x = buffer_fdpp[153];

    auto g_xxz_zz_x_y = buffer_fdpp[154];

    auto g_xxz_zz_x_z = buffer_fdpp[155];

    auto g_xxz_zz_y_x = buffer_fdpp[156];

    auto g_xxz_zz_y_y = buffer_fdpp[157];

    auto g_xxz_zz_y_z = buffer_fdpp[158];

    auto g_xxz_zz_z_x = buffer_fdpp[159];

    auto g_xxz_zz_z_y = buffer_fdpp[160];

    auto g_xxz_zz_z_z = buffer_fdpp[161];

    auto g_xyy_xx_x_x = buffer_fdpp[162];

    auto g_xyy_xx_x_y = buffer_fdpp[163];

    auto g_xyy_xx_x_z = buffer_fdpp[164];

    auto g_xyy_xx_y_x = buffer_fdpp[165];

    auto g_xyy_xx_y_y = buffer_fdpp[166];

    auto g_xyy_xx_y_z = buffer_fdpp[167];

    auto g_xyy_xx_z_x = buffer_fdpp[168];

    auto g_xyy_xx_z_y = buffer_fdpp[169];

    auto g_xyy_xx_z_z = buffer_fdpp[170];

    auto g_xyy_xy_x_x = buffer_fdpp[171];

    auto g_xyy_xy_x_y = buffer_fdpp[172];

    auto g_xyy_xy_x_z = buffer_fdpp[173];

    auto g_xyy_xy_y_x = buffer_fdpp[174];

    auto g_xyy_xy_y_y = buffer_fdpp[175];

    auto g_xyy_xy_y_z = buffer_fdpp[176];

    auto g_xyy_xy_z_x = buffer_fdpp[177];

    auto g_xyy_xy_z_y = buffer_fdpp[178];

    auto g_xyy_xy_z_z = buffer_fdpp[179];

    auto g_xyy_xz_x_x = buffer_fdpp[180];

    auto g_xyy_xz_x_y = buffer_fdpp[181];

    auto g_xyy_xz_x_z = buffer_fdpp[182];

    auto g_xyy_xz_y_x = buffer_fdpp[183];

    auto g_xyy_xz_y_y = buffer_fdpp[184];

    auto g_xyy_xz_y_z = buffer_fdpp[185];

    auto g_xyy_xz_z_x = buffer_fdpp[186];

    auto g_xyy_xz_z_y = buffer_fdpp[187];

    auto g_xyy_xz_z_z = buffer_fdpp[188];

    auto g_xyy_yy_x_x = buffer_fdpp[189];

    auto g_xyy_yy_x_y = buffer_fdpp[190];

    auto g_xyy_yy_x_z = buffer_fdpp[191];

    auto g_xyy_yy_y_x = buffer_fdpp[192];

    auto g_xyy_yy_y_y = buffer_fdpp[193];

    auto g_xyy_yy_y_z = buffer_fdpp[194];

    auto g_xyy_yy_z_x = buffer_fdpp[195];

    auto g_xyy_yy_z_y = buffer_fdpp[196];

    auto g_xyy_yy_z_z = buffer_fdpp[197];

    auto g_xyy_yz_x_x = buffer_fdpp[198];

    auto g_xyy_yz_x_y = buffer_fdpp[199];

    auto g_xyy_yz_x_z = buffer_fdpp[200];

    auto g_xyy_yz_y_x = buffer_fdpp[201];

    auto g_xyy_yz_y_y = buffer_fdpp[202];

    auto g_xyy_yz_y_z = buffer_fdpp[203];

    auto g_xyy_yz_z_x = buffer_fdpp[204];

    auto g_xyy_yz_z_y = buffer_fdpp[205];

    auto g_xyy_yz_z_z = buffer_fdpp[206];

    auto g_xyy_zz_x_x = buffer_fdpp[207];

    auto g_xyy_zz_x_y = buffer_fdpp[208];

    auto g_xyy_zz_x_z = buffer_fdpp[209];

    auto g_xyy_zz_y_x = buffer_fdpp[210];

    auto g_xyy_zz_y_y = buffer_fdpp[211];

    auto g_xyy_zz_y_z = buffer_fdpp[212];

    auto g_xyy_zz_z_x = buffer_fdpp[213];

    auto g_xyy_zz_z_y = buffer_fdpp[214];

    auto g_xyy_zz_z_z = buffer_fdpp[215];

    auto g_xyz_xx_x_x = buffer_fdpp[216];

    auto g_xyz_xx_x_y = buffer_fdpp[217];

    auto g_xyz_xx_x_z = buffer_fdpp[218];

    auto g_xyz_xx_y_x = buffer_fdpp[219];

    auto g_xyz_xx_y_y = buffer_fdpp[220];

    auto g_xyz_xx_y_z = buffer_fdpp[221];

    auto g_xyz_xx_z_x = buffer_fdpp[222];

    auto g_xyz_xx_z_y = buffer_fdpp[223];

    auto g_xyz_xx_z_z = buffer_fdpp[224];

    auto g_xyz_xy_x_x = buffer_fdpp[225];

    auto g_xyz_xy_x_y = buffer_fdpp[226];

    auto g_xyz_xy_x_z = buffer_fdpp[227];

    auto g_xyz_xy_y_x = buffer_fdpp[228];

    auto g_xyz_xy_y_y = buffer_fdpp[229];

    auto g_xyz_xy_y_z = buffer_fdpp[230];

    auto g_xyz_xy_z_x = buffer_fdpp[231];

    auto g_xyz_xy_z_y = buffer_fdpp[232];

    auto g_xyz_xy_z_z = buffer_fdpp[233];

    auto g_xyz_xz_x_x = buffer_fdpp[234];

    auto g_xyz_xz_x_y = buffer_fdpp[235];

    auto g_xyz_xz_x_z = buffer_fdpp[236];

    auto g_xyz_xz_y_x = buffer_fdpp[237];

    auto g_xyz_xz_y_y = buffer_fdpp[238];

    auto g_xyz_xz_y_z = buffer_fdpp[239];

    auto g_xyz_xz_z_x = buffer_fdpp[240];

    auto g_xyz_xz_z_y = buffer_fdpp[241];

    auto g_xyz_xz_z_z = buffer_fdpp[242];

    auto g_xyz_yy_x_x = buffer_fdpp[243];

    auto g_xyz_yy_x_y = buffer_fdpp[244];

    auto g_xyz_yy_x_z = buffer_fdpp[245];

    auto g_xyz_yy_y_x = buffer_fdpp[246];

    auto g_xyz_yy_y_y = buffer_fdpp[247];

    auto g_xyz_yy_y_z = buffer_fdpp[248];

    auto g_xyz_yy_z_x = buffer_fdpp[249];

    auto g_xyz_yy_z_y = buffer_fdpp[250];

    auto g_xyz_yy_z_z = buffer_fdpp[251];

    auto g_xyz_yz_x_x = buffer_fdpp[252];

    auto g_xyz_yz_x_y = buffer_fdpp[253];

    auto g_xyz_yz_x_z = buffer_fdpp[254];

    auto g_xyz_yz_y_x = buffer_fdpp[255];

    auto g_xyz_yz_y_y = buffer_fdpp[256];

    auto g_xyz_yz_y_z = buffer_fdpp[257];

    auto g_xyz_yz_z_x = buffer_fdpp[258];

    auto g_xyz_yz_z_y = buffer_fdpp[259];

    auto g_xyz_yz_z_z = buffer_fdpp[260];

    auto g_xyz_zz_x_x = buffer_fdpp[261];

    auto g_xyz_zz_x_y = buffer_fdpp[262];

    auto g_xyz_zz_x_z = buffer_fdpp[263];

    auto g_xyz_zz_y_x = buffer_fdpp[264];

    auto g_xyz_zz_y_y = buffer_fdpp[265];

    auto g_xyz_zz_y_z = buffer_fdpp[266];

    auto g_xyz_zz_z_x = buffer_fdpp[267];

    auto g_xyz_zz_z_y = buffer_fdpp[268];

    auto g_xyz_zz_z_z = buffer_fdpp[269];

    auto g_xzz_xx_x_x = buffer_fdpp[270];

    auto g_xzz_xx_x_y = buffer_fdpp[271];

    auto g_xzz_xx_x_z = buffer_fdpp[272];

    auto g_xzz_xx_y_x = buffer_fdpp[273];

    auto g_xzz_xx_y_y = buffer_fdpp[274];

    auto g_xzz_xx_y_z = buffer_fdpp[275];

    auto g_xzz_xx_z_x = buffer_fdpp[276];

    auto g_xzz_xx_z_y = buffer_fdpp[277];

    auto g_xzz_xx_z_z = buffer_fdpp[278];

    auto g_xzz_xy_x_x = buffer_fdpp[279];

    auto g_xzz_xy_x_y = buffer_fdpp[280];

    auto g_xzz_xy_x_z = buffer_fdpp[281];

    auto g_xzz_xy_y_x = buffer_fdpp[282];

    auto g_xzz_xy_y_y = buffer_fdpp[283];

    auto g_xzz_xy_y_z = buffer_fdpp[284];

    auto g_xzz_xy_z_x = buffer_fdpp[285];

    auto g_xzz_xy_z_y = buffer_fdpp[286];

    auto g_xzz_xy_z_z = buffer_fdpp[287];

    auto g_xzz_xz_x_x = buffer_fdpp[288];

    auto g_xzz_xz_x_y = buffer_fdpp[289];

    auto g_xzz_xz_x_z = buffer_fdpp[290];

    auto g_xzz_xz_y_x = buffer_fdpp[291];

    auto g_xzz_xz_y_y = buffer_fdpp[292];

    auto g_xzz_xz_y_z = buffer_fdpp[293];

    auto g_xzz_xz_z_x = buffer_fdpp[294];

    auto g_xzz_xz_z_y = buffer_fdpp[295];

    auto g_xzz_xz_z_z = buffer_fdpp[296];

    auto g_xzz_yy_x_x = buffer_fdpp[297];

    auto g_xzz_yy_x_y = buffer_fdpp[298];

    auto g_xzz_yy_x_z = buffer_fdpp[299];

    auto g_xzz_yy_y_x = buffer_fdpp[300];

    auto g_xzz_yy_y_y = buffer_fdpp[301];

    auto g_xzz_yy_y_z = buffer_fdpp[302];

    auto g_xzz_yy_z_x = buffer_fdpp[303];

    auto g_xzz_yy_z_y = buffer_fdpp[304];

    auto g_xzz_yy_z_z = buffer_fdpp[305];

    auto g_xzz_yz_x_x = buffer_fdpp[306];

    auto g_xzz_yz_x_y = buffer_fdpp[307];

    auto g_xzz_yz_x_z = buffer_fdpp[308];

    auto g_xzz_yz_y_x = buffer_fdpp[309];

    auto g_xzz_yz_y_y = buffer_fdpp[310];

    auto g_xzz_yz_y_z = buffer_fdpp[311];

    auto g_xzz_yz_z_x = buffer_fdpp[312];

    auto g_xzz_yz_z_y = buffer_fdpp[313];

    auto g_xzz_yz_z_z = buffer_fdpp[314];

    auto g_xzz_zz_x_x = buffer_fdpp[315];

    auto g_xzz_zz_x_y = buffer_fdpp[316];

    auto g_xzz_zz_x_z = buffer_fdpp[317];

    auto g_xzz_zz_y_x = buffer_fdpp[318];

    auto g_xzz_zz_y_y = buffer_fdpp[319];

    auto g_xzz_zz_y_z = buffer_fdpp[320];

    auto g_xzz_zz_z_x = buffer_fdpp[321];

    auto g_xzz_zz_z_y = buffer_fdpp[322];

    auto g_xzz_zz_z_z = buffer_fdpp[323];

    auto g_yyy_xx_x_x = buffer_fdpp[324];

    auto g_yyy_xx_x_y = buffer_fdpp[325];

    auto g_yyy_xx_x_z = buffer_fdpp[326];

    auto g_yyy_xx_y_x = buffer_fdpp[327];

    auto g_yyy_xx_y_y = buffer_fdpp[328];

    auto g_yyy_xx_y_z = buffer_fdpp[329];

    auto g_yyy_xx_z_x = buffer_fdpp[330];

    auto g_yyy_xx_z_y = buffer_fdpp[331];

    auto g_yyy_xx_z_z = buffer_fdpp[332];

    auto g_yyy_xy_x_x = buffer_fdpp[333];

    auto g_yyy_xy_x_y = buffer_fdpp[334];

    auto g_yyy_xy_x_z = buffer_fdpp[335];

    auto g_yyy_xy_y_x = buffer_fdpp[336];

    auto g_yyy_xy_y_y = buffer_fdpp[337];

    auto g_yyy_xy_y_z = buffer_fdpp[338];

    auto g_yyy_xy_z_x = buffer_fdpp[339];

    auto g_yyy_xy_z_y = buffer_fdpp[340];

    auto g_yyy_xy_z_z = buffer_fdpp[341];

    auto g_yyy_xz_x_x = buffer_fdpp[342];

    auto g_yyy_xz_x_y = buffer_fdpp[343];

    auto g_yyy_xz_x_z = buffer_fdpp[344];

    auto g_yyy_xz_y_x = buffer_fdpp[345];

    auto g_yyy_xz_y_y = buffer_fdpp[346];

    auto g_yyy_xz_y_z = buffer_fdpp[347];

    auto g_yyy_xz_z_x = buffer_fdpp[348];

    auto g_yyy_xz_z_y = buffer_fdpp[349];

    auto g_yyy_xz_z_z = buffer_fdpp[350];

    auto g_yyy_yy_x_x = buffer_fdpp[351];

    auto g_yyy_yy_x_y = buffer_fdpp[352];

    auto g_yyy_yy_x_z = buffer_fdpp[353];

    auto g_yyy_yy_y_x = buffer_fdpp[354];

    auto g_yyy_yy_y_y = buffer_fdpp[355];

    auto g_yyy_yy_y_z = buffer_fdpp[356];

    auto g_yyy_yy_z_x = buffer_fdpp[357];

    auto g_yyy_yy_z_y = buffer_fdpp[358];

    auto g_yyy_yy_z_z = buffer_fdpp[359];

    auto g_yyy_yz_x_x = buffer_fdpp[360];

    auto g_yyy_yz_x_y = buffer_fdpp[361];

    auto g_yyy_yz_x_z = buffer_fdpp[362];

    auto g_yyy_yz_y_x = buffer_fdpp[363];

    auto g_yyy_yz_y_y = buffer_fdpp[364];

    auto g_yyy_yz_y_z = buffer_fdpp[365];

    auto g_yyy_yz_z_x = buffer_fdpp[366];

    auto g_yyy_yz_z_y = buffer_fdpp[367];

    auto g_yyy_yz_z_z = buffer_fdpp[368];

    auto g_yyy_zz_x_x = buffer_fdpp[369];

    auto g_yyy_zz_x_y = buffer_fdpp[370];

    auto g_yyy_zz_x_z = buffer_fdpp[371];

    auto g_yyy_zz_y_x = buffer_fdpp[372];

    auto g_yyy_zz_y_y = buffer_fdpp[373];

    auto g_yyy_zz_y_z = buffer_fdpp[374];

    auto g_yyy_zz_z_x = buffer_fdpp[375];

    auto g_yyy_zz_z_y = buffer_fdpp[376];

    auto g_yyy_zz_z_z = buffer_fdpp[377];

    auto g_yyz_xx_x_x = buffer_fdpp[378];

    auto g_yyz_xx_x_y = buffer_fdpp[379];

    auto g_yyz_xx_x_z = buffer_fdpp[380];

    auto g_yyz_xx_y_x = buffer_fdpp[381];

    auto g_yyz_xx_y_y = buffer_fdpp[382];

    auto g_yyz_xx_y_z = buffer_fdpp[383];

    auto g_yyz_xx_z_x = buffer_fdpp[384];

    auto g_yyz_xx_z_y = buffer_fdpp[385];

    auto g_yyz_xx_z_z = buffer_fdpp[386];

    auto g_yyz_xy_x_x = buffer_fdpp[387];

    auto g_yyz_xy_x_y = buffer_fdpp[388];

    auto g_yyz_xy_x_z = buffer_fdpp[389];

    auto g_yyz_xy_y_x = buffer_fdpp[390];

    auto g_yyz_xy_y_y = buffer_fdpp[391];

    auto g_yyz_xy_y_z = buffer_fdpp[392];

    auto g_yyz_xy_z_x = buffer_fdpp[393];

    auto g_yyz_xy_z_y = buffer_fdpp[394];

    auto g_yyz_xy_z_z = buffer_fdpp[395];

    auto g_yyz_xz_x_x = buffer_fdpp[396];

    auto g_yyz_xz_x_y = buffer_fdpp[397];

    auto g_yyz_xz_x_z = buffer_fdpp[398];

    auto g_yyz_xz_y_x = buffer_fdpp[399];

    auto g_yyz_xz_y_y = buffer_fdpp[400];

    auto g_yyz_xz_y_z = buffer_fdpp[401];

    auto g_yyz_xz_z_x = buffer_fdpp[402];

    auto g_yyz_xz_z_y = buffer_fdpp[403];

    auto g_yyz_xz_z_z = buffer_fdpp[404];

    auto g_yyz_yy_x_x = buffer_fdpp[405];

    auto g_yyz_yy_x_y = buffer_fdpp[406];

    auto g_yyz_yy_x_z = buffer_fdpp[407];

    auto g_yyz_yy_y_x = buffer_fdpp[408];

    auto g_yyz_yy_y_y = buffer_fdpp[409];

    auto g_yyz_yy_y_z = buffer_fdpp[410];

    auto g_yyz_yy_z_x = buffer_fdpp[411];

    auto g_yyz_yy_z_y = buffer_fdpp[412];

    auto g_yyz_yy_z_z = buffer_fdpp[413];

    auto g_yyz_yz_x_x = buffer_fdpp[414];

    auto g_yyz_yz_x_y = buffer_fdpp[415];

    auto g_yyz_yz_x_z = buffer_fdpp[416];

    auto g_yyz_yz_y_x = buffer_fdpp[417];

    auto g_yyz_yz_y_y = buffer_fdpp[418];

    auto g_yyz_yz_y_z = buffer_fdpp[419];

    auto g_yyz_yz_z_x = buffer_fdpp[420];

    auto g_yyz_yz_z_y = buffer_fdpp[421];

    auto g_yyz_yz_z_z = buffer_fdpp[422];

    auto g_yyz_zz_x_x = buffer_fdpp[423];

    auto g_yyz_zz_x_y = buffer_fdpp[424];

    auto g_yyz_zz_x_z = buffer_fdpp[425];

    auto g_yyz_zz_y_x = buffer_fdpp[426];

    auto g_yyz_zz_y_y = buffer_fdpp[427];

    auto g_yyz_zz_y_z = buffer_fdpp[428];

    auto g_yyz_zz_z_x = buffer_fdpp[429];

    auto g_yyz_zz_z_y = buffer_fdpp[430];

    auto g_yyz_zz_z_z = buffer_fdpp[431];

    auto g_yzz_xx_x_x = buffer_fdpp[432];

    auto g_yzz_xx_x_y = buffer_fdpp[433];

    auto g_yzz_xx_x_z = buffer_fdpp[434];

    auto g_yzz_xx_y_x = buffer_fdpp[435];

    auto g_yzz_xx_y_y = buffer_fdpp[436];

    auto g_yzz_xx_y_z = buffer_fdpp[437];

    auto g_yzz_xx_z_x = buffer_fdpp[438];

    auto g_yzz_xx_z_y = buffer_fdpp[439];

    auto g_yzz_xx_z_z = buffer_fdpp[440];

    auto g_yzz_xy_x_x = buffer_fdpp[441];

    auto g_yzz_xy_x_y = buffer_fdpp[442];

    auto g_yzz_xy_x_z = buffer_fdpp[443];

    auto g_yzz_xy_y_x = buffer_fdpp[444];

    auto g_yzz_xy_y_y = buffer_fdpp[445];

    auto g_yzz_xy_y_z = buffer_fdpp[446];

    auto g_yzz_xy_z_x = buffer_fdpp[447];

    auto g_yzz_xy_z_y = buffer_fdpp[448];

    auto g_yzz_xy_z_z = buffer_fdpp[449];

    auto g_yzz_xz_x_x = buffer_fdpp[450];

    auto g_yzz_xz_x_y = buffer_fdpp[451];

    auto g_yzz_xz_x_z = buffer_fdpp[452];

    auto g_yzz_xz_y_x = buffer_fdpp[453];

    auto g_yzz_xz_y_y = buffer_fdpp[454];

    auto g_yzz_xz_y_z = buffer_fdpp[455];

    auto g_yzz_xz_z_x = buffer_fdpp[456];

    auto g_yzz_xz_z_y = buffer_fdpp[457];

    auto g_yzz_xz_z_z = buffer_fdpp[458];

    auto g_yzz_yy_x_x = buffer_fdpp[459];

    auto g_yzz_yy_x_y = buffer_fdpp[460];

    auto g_yzz_yy_x_z = buffer_fdpp[461];

    auto g_yzz_yy_y_x = buffer_fdpp[462];

    auto g_yzz_yy_y_y = buffer_fdpp[463];

    auto g_yzz_yy_y_z = buffer_fdpp[464];

    auto g_yzz_yy_z_x = buffer_fdpp[465];

    auto g_yzz_yy_z_y = buffer_fdpp[466];

    auto g_yzz_yy_z_z = buffer_fdpp[467];

    auto g_yzz_yz_x_x = buffer_fdpp[468];

    auto g_yzz_yz_x_y = buffer_fdpp[469];

    auto g_yzz_yz_x_z = buffer_fdpp[470];

    auto g_yzz_yz_y_x = buffer_fdpp[471];

    auto g_yzz_yz_y_y = buffer_fdpp[472];

    auto g_yzz_yz_y_z = buffer_fdpp[473];

    auto g_yzz_yz_z_x = buffer_fdpp[474];

    auto g_yzz_yz_z_y = buffer_fdpp[475];

    auto g_yzz_yz_z_z = buffer_fdpp[476];

    auto g_yzz_zz_x_x = buffer_fdpp[477];

    auto g_yzz_zz_x_y = buffer_fdpp[478];

    auto g_yzz_zz_x_z = buffer_fdpp[479];

    auto g_yzz_zz_y_x = buffer_fdpp[480];

    auto g_yzz_zz_y_y = buffer_fdpp[481];

    auto g_yzz_zz_y_z = buffer_fdpp[482];

    auto g_yzz_zz_z_x = buffer_fdpp[483];

    auto g_yzz_zz_z_y = buffer_fdpp[484];

    auto g_yzz_zz_z_z = buffer_fdpp[485];

    auto g_zzz_xx_x_x = buffer_fdpp[486];

    auto g_zzz_xx_x_y = buffer_fdpp[487];

    auto g_zzz_xx_x_z = buffer_fdpp[488];

    auto g_zzz_xx_y_x = buffer_fdpp[489];

    auto g_zzz_xx_y_y = buffer_fdpp[490];

    auto g_zzz_xx_y_z = buffer_fdpp[491];

    auto g_zzz_xx_z_x = buffer_fdpp[492];

    auto g_zzz_xx_z_y = buffer_fdpp[493];

    auto g_zzz_xx_z_z = buffer_fdpp[494];

    auto g_zzz_xy_x_x = buffer_fdpp[495];

    auto g_zzz_xy_x_y = buffer_fdpp[496];

    auto g_zzz_xy_x_z = buffer_fdpp[497];

    auto g_zzz_xy_y_x = buffer_fdpp[498];

    auto g_zzz_xy_y_y = buffer_fdpp[499];

    auto g_zzz_xy_y_z = buffer_fdpp[500];

    auto g_zzz_xy_z_x = buffer_fdpp[501];

    auto g_zzz_xy_z_y = buffer_fdpp[502];

    auto g_zzz_xy_z_z = buffer_fdpp[503];

    auto g_zzz_xz_x_x = buffer_fdpp[504];

    auto g_zzz_xz_x_y = buffer_fdpp[505];

    auto g_zzz_xz_x_z = buffer_fdpp[506];

    auto g_zzz_xz_y_x = buffer_fdpp[507];

    auto g_zzz_xz_y_y = buffer_fdpp[508];

    auto g_zzz_xz_y_z = buffer_fdpp[509];

    auto g_zzz_xz_z_x = buffer_fdpp[510];

    auto g_zzz_xz_z_y = buffer_fdpp[511];

    auto g_zzz_xz_z_z = buffer_fdpp[512];

    auto g_zzz_yy_x_x = buffer_fdpp[513];

    auto g_zzz_yy_x_y = buffer_fdpp[514];

    auto g_zzz_yy_x_z = buffer_fdpp[515];

    auto g_zzz_yy_y_x = buffer_fdpp[516];

    auto g_zzz_yy_y_y = buffer_fdpp[517];

    auto g_zzz_yy_y_z = buffer_fdpp[518];

    auto g_zzz_yy_z_x = buffer_fdpp[519];

    auto g_zzz_yy_z_y = buffer_fdpp[520];

    auto g_zzz_yy_z_z = buffer_fdpp[521];

    auto g_zzz_yz_x_x = buffer_fdpp[522];

    auto g_zzz_yz_x_y = buffer_fdpp[523];

    auto g_zzz_yz_x_z = buffer_fdpp[524];

    auto g_zzz_yz_y_x = buffer_fdpp[525];

    auto g_zzz_yz_y_y = buffer_fdpp[526];

    auto g_zzz_yz_y_z = buffer_fdpp[527];

    auto g_zzz_yz_z_x = buffer_fdpp[528];

    auto g_zzz_yz_z_y = buffer_fdpp[529];

    auto g_zzz_yz_z_z = buffer_fdpp[530];

    auto g_zzz_zz_x_x = buffer_fdpp[531];

    auto g_zzz_zz_x_y = buffer_fdpp[532];

    auto g_zzz_zz_x_z = buffer_fdpp[533];

    auto g_zzz_zz_y_x = buffer_fdpp[534];

    auto g_zzz_zz_y_y = buffer_fdpp[535];

    auto g_zzz_zz_y_z = buffer_fdpp[536];

    auto g_zzz_zz_z_x = buffer_fdpp[537];

    auto g_zzz_zz_z_y = buffer_fdpp[538];

    auto g_zzz_zz_z_z = buffer_fdpp[539];

    /// Set up components of integrals buffer : buffer_2000_pdpp

    auto g_xx_0_0_0_x_xx_x_x = buffer_2000_pdpp[0];

    auto g_xx_0_0_0_x_xx_x_y = buffer_2000_pdpp[1];

    auto g_xx_0_0_0_x_xx_x_z = buffer_2000_pdpp[2];

    auto g_xx_0_0_0_x_xx_y_x = buffer_2000_pdpp[3];

    auto g_xx_0_0_0_x_xx_y_y = buffer_2000_pdpp[4];

    auto g_xx_0_0_0_x_xx_y_z = buffer_2000_pdpp[5];

    auto g_xx_0_0_0_x_xx_z_x = buffer_2000_pdpp[6];

    auto g_xx_0_0_0_x_xx_z_y = buffer_2000_pdpp[7];

    auto g_xx_0_0_0_x_xx_z_z = buffer_2000_pdpp[8];

    auto g_xx_0_0_0_x_xy_x_x = buffer_2000_pdpp[9];

    auto g_xx_0_0_0_x_xy_x_y = buffer_2000_pdpp[10];

    auto g_xx_0_0_0_x_xy_x_z = buffer_2000_pdpp[11];

    auto g_xx_0_0_0_x_xy_y_x = buffer_2000_pdpp[12];

    auto g_xx_0_0_0_x_xy_y_y = buffer_2000_pdpp[13];

    auto g_xx_0_0_0_x_xy_y_z = buffer_2000_pdpp[14];

    auto g_xx_0_0_0_x_xy_z_x = buffer_2000_pdpp[15];

    auto g_xx_0_0_0_x_xy_z_y = buffer_2000_pdpp[16];

    auto g_xx_0_0_0_x_xy_z_z = buffer_2000_pdpp[17];

    auto g_xx_0_0_0_x_xz_x_x = buffer_2000_pdpp[18];

    auto g_xx_0_0_0_x_xz_x_y = buffer_2000_pdpp[19];

    auto g_xx_0_0_0_x_xz_x_z = buffer_2000_pdpp[20];

    auto g_xx_0_0_0_x_xz_y_x = buffer_2000_pdpp[21];

    auto g_xx_0_0_0_x_xz_y_y = buffer_2000_pdpp[22];

    auto g_xx_0_0_0_x_xz_y_z = buffer_2000_pdpp[23];

    auto g_xx_0_0_0_x_xz_z_x = buffer_2000_pdpp[24];

    auto g_xx_0_0_0_x_xz_z_y = buffer_2000_pdpp[25];

    auto g_xx_0_0_0_x_xz_z_z = buffer_2000_pdpp[26];

    auto g_xx_0_0_0_x_yy_x_x = buffer_2000_pdpp[27];

    auto g_xx_0_0_0_x_yy_x_y = buffer_2000_pdpp[28];

    auto g_xx_0_0_0_x_yy_x_z = buffer_2000_pdpp[29];

    auto g_xx_0_0_0_x_yy_y_x = buffer_2000_pdpp[30];

    auto g_xx_0_0_0_x_yy_y_y = buffer_2000_pdpp[31];

    auto g_xx_0_0_0_x_yy_y_z = buffer_2000_pdpp[32];

    auto g_xx_0_0_0_x_yy_z_x = buffer_2000_pdpp[33];

    auto g_xx_0_0_0_x_yy_z_y = buffer_2000_pdpp[34];

    auto g_xx_0_0_0_x_yy_z_z = buffer_2000_pdpp[35];

    auto g_xx_0_0_0_x_yz_x_x = buffer_2000_pdpp[36];

    auto g_xx_0_0_0_x_yz_x_y = buffer_2000_pdpp[37];

    auto g_xx_0_0_0_x_yz_x_z = buffer_2000_pdpp[38];

    auto g_xx_0_0_0_x_yz_y_x = buffer_2000_pdpp[39];

    auto g_xx_0_0_0_x_yz_y_y = buffer_2000_pdpp[40];

    auto g_xx_0_0_0_x_yz_y_z = buffer_2000_pdpp[41];

    auto g_xx_0_0_0_x_yz_z_x = buffer_2000_pdpp[42];

    auto g_xx_0_0_0_x_yz_z_y = buffer_2000_pdpp[43];

    auto g_xx_0_0_0_x_yz_z_z = buffer_2000_pdpp[44];

    auto g_xx_0_0_0_x_zz_x_x = buffer_2000_pdpp[45];

    auto g_xx_0_0_0_x_zz_x_y = buffer_2000_pdpp[46];

    auto g_xx_0_0_0_x_zz_x_z = buffer_2000_pdpp[47];

    auto g_xx_0_0_0_x_zz_y_x = buffer_2000_pdpp[48];

    auto g_xx_0_0_0_x_zz_y_y = buffer_2000_pdpp[49];

    auto g_xx_0_0_0_x_zz_y_z = buffer_2000_pdpp[50];

    auto g_xx_0_0_0_x_zz_z_x = buffer_2000_pdpp[51];

    auto g_xx_0_0_0_x_zz_z_y = buffer_2000_pdpp[52];

    auto g_xx_0_0_0_x_zz_z_z = buffer_2000_pdpp[53];

    auto g_xx_0_0_0_y_xx_x_x = buffer_2000_pdpp[54];

    auto g_xx_0_0_0_y_xx_x_y = buffer_2000_pdpp[55];

    auto g_xx_0_0_0_y_xx_x_z = buffer_2000_pdpp[56];

    auto g_xx_0_0_0_y_xx_y_x = buffer_2000_pdpp[57];

    auto g_xx_0_0_0_y_xx_y_y = buffer_2000_pdpp[58];

    auto g_xx_0_0_0_y_xx_y_z = buffer_2000_pdpp[59];

    auto g_xx_0_0_0_y_xx_z_x = buffer_2000_pdpp[60];

    auto g_xx_0_0_0_y_xx_z_y = buffer_2000_pdpp[61];

    auto g_xx_0_0_0_y_xx_z_z = buffer_2000_pdpp[62];

    auto g_xx_0_0_0_y_xy_x_x = buffer_2000_pdpp[63];

    auto g_xx_0_0_0_y_xy_x_y = buffer_2000_pdpp[64];

    auto g_xx_0_0_0_y_xy_x_z = buffer_2000_pdpp[65];

    auto g_xx_0_0_0_y_xy_y_x = buffer_2000_pdpp[66];

    auto g_xx_0_0_0_y_xy_y_y = buffer_2000_pdpp[67];

    auto g_xx_0_0_0_y_xy_y_z = buffer_2000_pdpp[68];

    auto g_xx_0_0_0_y_xy_z_x = buffer_2000_pdpp[69];

    auto g_xx_0_0_0_y_xy_z_y = buffer_2000_pdpp[70];

    auto g_xx_0_0_0_y_xy_z_z = buffer_2000_pdpp[71];

    auto g_xx_0_0_0_y_xz_x_x = buffer_2000_pdpp[72];

    auto g_xx_0_0_0_y_xz_x_y = buffer_2000_pdpp[73];

    auto g_xx_0_0_0_y_xz_x_z = buffer_2000_pdpp[74];

    auto g_xx_0_0_0_y_xz_y_x = buffer_2000_pdpp[75];

    auto g_xx_0_0_0_y_xz_y_y = buffer_2000_pdpp[76];

    auto g_xx_0_0_0_y_xz_y_z = buffer_2000_pdpp[77];

    auto g_xx_0_0_0_y_xz_z_x = buffer_2000_pdpp[78];

    auto g_xx_0_0_0_y_xz_z_y = buffer_2000_pdpp[79];

    auto g_xx_0_0_0_y_xz_z_z = buffer_2000_pdpp[80];

    auto g_xx_0_0_0_y_yy_x_x = buffer_2000_pdpp[81];

    auto g_xx_0_0_0_y_yy_x_y = buffer_2000_pdpp[82];

    auto g_xx_0_0_0_y_yy_x_z = buffer_2000_pdpp[83];

    auto g_xx_0_0_0_y_yy_y_x = buffer_2000_pdpp[84];

    auto g_xx_0_0_0_y_yy_y_y = buffer_2000_pdpp[85];

    auto g_xx_0_0_0_y_yy_y_z = buffer_2000_pdpp[86];

    auto g_xx_0_0_0_y_yy_z_x = buffer_2000_pdpp[87];

    auto g_xx_0_0_0_y_yy_z_y = buffer_2000_pdpp[88];

    auto g_xx_0_0_0_y_yy_z_z = buffer_2000_pdpp[89];

    auto g_xx_0_0_0_y_yz_x_x = buffer_2000_pdpp[90];

    auto g_xx_0_0_0_y_yz_x_y = buffer_2000_pdpp[91];

    auto g_xx_0_0_0_y_yz_x_z = buffer_2000_pdpp[92];

    auto g_xx_0_0_0_y_yz_y_x = buffer_2000_pdpp[93];

    auto g_xx_0_0_0_y_yz_y_y = buffer_2000_pdpp[94];

    auto g_xx_0_0_0_y_yz_y_z = buffer_2000_pdpp[95];

    auto g_xx_0_0_0_y_yz_z_x = buffer_2000_pdpp[96];

    auto g_xx_0_0_0_y_yz_z_y = buffer_2000_pdpp[97];

    auto g_xx_0_0_0_y_yz_z_z = buffer_2000_pdpp[98];

    auto g_xx_0_0_0_y_zz_x_x = buffer_2000_pdpp[99];

    auto g_xx_0_0_0_y_zz_x_y = buffer_2000_pdpp[100];

    auto g_xx_0_0_0_y_zz_x_z = buffer_2000_pdpp[101];

    auto g_xx_0_0_0_y_zz_y_x = buffer_2000_pdpp[102];

    auto g_xx_0_0_0_y_zz_y_y = buffer_2000_pdpp[103];

    auto g_xx_0_0_0_y_zz_y_z = buffer_2000_pdpp[104];

    auto g_xx_0_0_0_y_zz_z_x = buffer_2000_pdpp[105];

    auto g_xx_0_0_0_y_zz_z_y = buffer_2000_pdpp[106];

    auto g_xx_0_0_0_y_zz_z_z = buffer_2000_pdpp[107];

    auto g_xx_0_0_0_z_xx_x_x = buffer_2000_pdpp[108];

    auto g_xx_0_0_0_z_xx_x_y = buffer_2000_pdpp[109];

    auto g_xx_0_0_0_z_xx_x_z = buffer_2000_pdpp[110];

    auto g_xx_0_0_0_z_xx_y_x = buffer_2000_pdpp[111];

    auto g_xx_0_0_0_z_xx_y_y = buffer_2000_pdpp[112];

    auto g_xx_0_0_0_z_xx_y_z = buffer_2000_pdpp[113];

    auto g_xx_0_0_0_z_xx_z_x = buffer_2000_pdpp[114];

    auto g_xx_0_0_0_z_xx_z_y = buffer_2000_pdpp[115];

    auto g_xx_0_0_0_z_xx_z_z = buffer_2000_pdpp[116];

    auto g_xx_0_0_0_z_xy_x_x = buffer_2000_pdpp[117];

    auto g_xx_0_0_0_z_xy_x_y = buffer_2000_pdpp[118];

    auto g_xx_0_0_0_z_xy_x_z = buffer_2000_pdpp[119];

    auto g_xx_0_0_0_z_xy_y_x = buffer_2000_pdpp[120];

    auto g_xx_0_0_0_z_xy_y_y = buffer_2000_pdpp[121];

    auto g_xx_0_0_0_z_xy_y_z = buffer_2000_pdpp[122];

    auto g_xx_0_0_0_z_xy_z_x = buffer_2000_pdpp[123];

    auto g_xx_0_0_0_z_xy_z_y = buffer_2000_pdpp[124];

    auto g_xx_0_0_0_z_xy_z_z = buffer_2000_pdpp[125];

    auto g_xx_0_0_0_z_xz_x_x = buffer_2000_pdpp[126];

    auto g_xx_0_0_0_z_xz_x_y = buffer_2000_pdpp[127];

    auto g_xx_0_0_0_z_xz_x_z = buffer_2000_pdpp[128];

    auto g_xx_0_0_0_z_xz_y_x = buffer_2000_pdpp[129];

    auto g_xx_0_0_0_z_xz_y_y = buffer_2000_pdpp[130];

    auto g_xx_0_0_0_z_xz_y_z = buffer_2000_pdpp[131];

    auto g_xx_0_0_0_z_xz_z_x = buffer_2000_pdpp[132];

    auto g_xx_0_0_0_z_xz_z_y = buffer_2000_pdpp[133];

    auto g_xx_0_0_0_z_xz_z_z = buffer_2000_pdpp[134];

    auto g_xx_0_0_0_z_yy_x_x = buffer_2000_pdpp[135];

    auto g_xx_0_0_0_z_yy_x_y = buffer_2000_pdpp[136];

    auto g_xx_0_0_0_z_yy_x_z = buffer_2000_pdpp[137];

    auto g_xx_0_0_0_z_yy_y_x = buffer_2000_pdpp[138];

    auto g_xx_0_0_0_z_yy_y_y = buffer_2000_pdpp[139];

    auto g_xx_0_0_0_z_yy_y_z = buffer_2000_pdpp[140];

    auto g_xx_0_0_0_z_yy_z_x = buffer_2000_pdpp[141];

    auto g_xx_0_0_0_z_yy_z_y = buffer_2000_pdpp[142];

    auto g_xx_0_0_0_z_yy_z_z = buffer_2000_pdpp[143];

    auto g_xx_0_0_0_z_yz_x_x = buffer_2000_pdpp[144];

    auto g_xx_0_0_0_z_yz_x_y = buffer_2000_pdpp[145];

    auto g_xx_0_0_0_z_yz_x_z = buffer_2000_pdpp[146];

    auto g_xx_0_0_0_z_yz_y_x = buffer_2000_pdpp[147];

    auto g_xx_0_0_0_z_yz_y_y = buffer_2000_pdpp[148];

    auto g_xx_0_0_0_z_yz_y_z = buffer_2000_pdpp[149];

    auto g_xx_0_0_0_z_yz_z_x = buffer_2000_pdpp[150];

    auto g_xx_0_0_0_z_yz_z_y = buffer_2000_pdpp[151];

    auto g_xx_0_0_0_z_yz_z_z = buffer_2000_pdpp[152];

    auto g_xx_0_0_0_z_zz_x_x = buffer_2000_pdpp[153];

    auto g_xx_0_0_0_z_zz_x_y = buffer_2000_pdpp[154];

    auto g_xx_0_0_0_z_zz_x_z = buffer_2000_pdpp[155];

    auto g_xx_0_0_0_z_zz_y_x = buffer_2000_pdpp[156];

    auto g_xx_0_0_0_z_zz_y_y = buffer_2000_pdpp[157];

    auto g_xx_0_0_0_z_zz_y_z = buffer_2000_pdpp[158];

    auto g_xx_0_0_0_z_zz_z_x = buffer_2000_pdpp[159];

    auto g_xx_0_0_0_z_zz_z_y = buffer_2000_pdpp[160];

    auto g_xx_0_0_0_z_zz_z_z = buffer_2000_pdpp[161];

    auto g_xy_0_0_0_x_xx_x_x = buffer_2000_pdpp[162];

    auto g_xy_0_0_0_x_xx_x_y = buffer_2000_pdpp[163];

    auto g_xy_0_0_0_x_xx_x_z = buffer_2000_pdpp[164];

    auto g_xy_0_0_0_x_xx_y_x = buffer_2000_pdpp[165];

    auto g_xy_0_0_0_x_xx_y_y = buffer_2000_pdpp[166];

    auto g_xy_0_0_0_x_xx_y_z = buffer_2000_pdpp[167];

    auto g_xy_0_0_0_x_xx_z_x = buffer_2000_pdpp[168];

    auto g_xy_0_0_0_x_xx_z_y = buffer_2000_pdpp[169];

    auto g_xy_0_0_0_x_xx_z_z = buffer_2000_pdpp[170];

    auto g_xy_0_0_0_x_xy_x_x = buffer_2000_pdpp[171];

    auto g_xy_0_0_0_x_xy_x_y = buffer_2000_pdpp[172];

    auto g_xy_0_0_0_x_xy_x_z = buffer_2000_pdpp[173];

    auto g_xy_0_0_0_x_xy_y_x = buffer_2000_pdpp[174];

    auto g_xy_0_0_0_x_xy_y_y = buffer_2000_pdpp[175];

    auto g_xy_0_0_0_x_xy_y_z = buffer_2000_pdpp[176];

    auto g_xy_0_0_0_x_xy_z_x = buffer_2000_pdpp[177];

    auto g_xy_0_0_0_x_xy_z_y = buffer_2000_pdpp[178];

    auto g_xy_0_0_0_x_xy_z_z = buffer_2000_pdpp[179];

    auto g_xy_0_0_0_x_xz_x_x = buffer_2000_pdpp[180];

    auto g_xy_0_0_0_x_xz_x_y = buffer_2000_pdpp[181];

    auto g_xy_0_0_0_x_xz_x_z = buffer_2000_pdpp[182];

    auto g_xy_0_0_0_x_xz_y_x = buffer_2000_pdpp[183];

    auto g_xy_0_0_0_x_xz_y_y = buffer_2000_pdpp[184];

    auto g_xy_0_0_0_x_xz_y_z = buffer_2000_pdpp[185];

    auto g_xy_0_0_0_x_xz_z_x = buffer_2000_pdpp[186];

    auto g_xy_0_0_0_x_xz_z_y = buffer_2000_pdpp[187];

    auto g_xy_0_0_0_x_xz_z_z = buffer_2000_pdpp[188];

    auto g_xy_0_0_0_x_yy_x_x = buffer_2000_pdpp[189];

    auto g_xy_0_0_0_x_yy_x_y = buffer_2000_pdpp[190];

    auto g_xy_0_0_0_x_yy_x_z = buffer_2000_pdpp[191];

    auto g_xy_0_0_0_x_yy_y_x = buffer_2000_pdpp[192];

    auto g_xy_0_0_0_x_yy_y_y = buffer_2000_pdpp[193];

    auto g_xy_0_0_0_x_yy_y_z = buffer_2000_pdpp[194];

    auto g_xy_0_0_0_x_yy_z_x = buffer_2000_pdpp[195];

    auto g_xy_0_0_0_x_yy_z_y = buffer_2000_pdpp[196];

    auto g_xy_0_0_0_x_yy_z_z = buffer_2000_pdpp[197];

    auto g_xy_0_0_0_x_yz_x_x = buffer_2000_pdpp[198];

    auto g_xy_0_0_0_x_yz_x_y = buffer_2000_pdpp[199];

    auto g_xy_0_0_0_x_yz_x_z = buffer_2000_pdpp[200];

    auto g_xy_0_0_0_x_yz_y_x = buffer_2000_pdpp[201];

    auto g_xy_0_0_0_x_yz_y_y = buffer_2000_pdpp[202];

    auto g_xy_0_0_0_x_yz_y_z = buffer_2000_pdpp[203];

    auto g_xy_0_0_0_x_yz_z_x = buffer_2000_pdpp[204];

    auto g_xy_0_0_0_x_yz_z_y = buffer_2000_pdpp[205];

    auto g_xy_0_0_0_x_yz_z_z = buffer_2000_pdpp[206];

    auto g_xy_0_0_0_x_zz_x_x = buffer_2000_pdpp[207];

    auto g_xy_0_0_0_x_zz_x_y = buffer_2000_pdpp[208];

    auto g_xy_0_0_0_x_zz_x_z = buffer_2000_pdpp[209];

    auto g_xy_0_0_0_x_zz_y_x = buffer_2000_pdpp[210];

    auto g_xy_0_0_0_x_zz_y_y = buffer_2000_pdpp[211];

    auto g_xy_0_0_0_x_zz_y_z = buffer_2000_pdpp[212];

    auto g_xy_0_0_0_x_zz_z_x = buffer_2000_pdpp[213];

    auto g_xy_0_0_0_x_zz_z_y = buffer_2000_pdpp[214];

    auto g_xy_0_0_0_x_zz_z_z = buffer_2000_pdpp[215];

    auto g_xy_0_0_0_y_xx_x_x = buffer_2000_pdpp[216];

    auto g_xy_0_0_0_y_xx_x_y = buffer_2000_pdpp[217];

    auto g_xy_0_0_0_y_xx_x_z = buffer_2000_pdpp[218];

    auto g_xy_0_0_0_y_xx_y_x = buffer_2000_pdpp[219];

    auto g_xy_0_0_0_y_xx_y_y = buffer_2000_pdpp[220];

    auto g_xy_0_0_0_y_xx_y_z = buffer_2000_pdpp[221];

    auto g_xy_0_0_0_y_xx_z_x = buffer_2000_pdpp[222];

    auto g_xy_0_0_0_y_xx_z_y = buffer_2000_pdpp[223];

    auto g_xy_0_0_0_y_xx_z_z = buffer_2000_pdpp[224];

    auto g_xy_0_0_0_y_xy_x_x = buffer_2000_pdpp[225];

    auto g_xy_0_0_0_y_xy_x_y = buffer_2000_pdpp[226];

    auto g_xy_0_0_0_y_xy_x_z = buffer_2000_pdpp[227];

    auto g_xy_0_0_0_y_xy_y_x = buffer_2000_pdpp[228];

    auto g_xy_0_0_0_y_xy_y_y = buffer_2000_pdpp[229];

    auto g_xy_0_0_0_y_xy_y_z = buffer_2000_pdpp[230];

    auto g_xy_0_0_0_y_xy_z_x = buffer_2000_pdpp[231];

    auto g_xy_0_0_0_y_xy_z_y = buffer_2000_pdpp[232];

    auto g_xy_0_0_0_y_xy_z_z = buffer_2000_pdpp[233];

    auto g_xy_0_0_0_y_xz_x_x = buffer_2000_pdpp[234];

    auto g_xy_0_0_0_y_xz_x_y = buffer_2000_pdpp[235];

    auto g_xy_0_0_0_y_xz_x_z = buffer_2000_pdpp[236];

    auto g_xy_0_0_0_y_xz_y_x = buffer_2000_pdpp[237];

    auto g_xy_0_0_0_y_xz_y_y = buffer_2000_pdpp[238];

    auto g_xy_0_0_0_y_xz_y_z = buffer_2000_pdpp[239];

    auto g_xy_0_0_0_y_xz_z_x = buffer_2000_pdpp[240];

    auto g_xy_0_0_0_y_xz_z_y = buffer_2000_pdpp[241];

    auto g_xy_0_0_0_y_xz_z_z = buffer_2000_pdpp[242];

    auto g_xy_0_0_0_y_yy_x_x = buffer_2000_pdpp[243];

    auto g_xy_0_0_0_y_yy_x_y = buffer_2000_pdpp[244];

    auto g_xy_0_0_0_y_yy_x_z = buffer_2000_pdpp[245];

    auto g_xy_0_0_0_y_yy_y_x = buffer_2000_pdpp[246];

    auto g_xy_0_0_0_y_yy_y_y = buffer_2000_pdpp[247];

    auto g_xy_0_0_0_y_yy_y_z = buffer_2000_pdpp[248];

    auto g_xy_0_0_0_y_yy_z_x = buffer_2000_pdpp[249];

    auto g_xy_0_0_0_y_yy_z_y = buffer_2000_pdpp[250];

    auto g_xy_0_0_0_y_yy_z_z = buffer_2000_pdpp[251];

    auto g_xy_0_0_0_y_yz_x_x = buffer_2000_pdpp[252];

    auto g_xy_0_0_0_y_yz_x_y = buffer_2000_pdpp[253];

    auto g_xy_0_0_0_y_yz_x_z = buffer_2000_pdpp[254];

    auto g_xy_0_0_0_y_yz_y_x = buffer_2000_pdpp[255];

    auto g_xy_0_0_0_y_yz_y_y = buffer_2000_pdpp[256];

    auto g_xy_0_0_0_y_yz_y_z = buffer_2000_pdpp[257];

    auto g_xy_0_0_0_y_yz_z_x = buffer_2000_pdpp[258];

    auto g_xy_0_0_0_y_yz_z_y = buffer_2000_pdpp[259];

    auto g_xy_0_0_0_y_yz_z_z = buffer_2000_pdpp[260];

    auto g_xy_0_0_0_y_zz_x_x = buffer_2000_pdpp[261];

    auto g_xy_0_0_0_y_zz_x_y = buffer_2000_pdpp[262];

    auto g_xy_0_0_0_y_zz_x_z = buffer_2000_pdpp[263];

    auto g_xy_0_0_0_y_zz_y_x = buffer_2000_pdpp[264];

    auto g_xy_0_0_0_y_zz_y_y = buffer_2000_pdpp[265];

    auto g_xy_0_0_0_y_zz_y_z = buffer_2000_pdpp[266];

    auto g_xy_0_0_0_y_zz_z_x = buffer_2000_pdpp[267];

    auto g_xy_0_0_0_y_zz_z_y = buffer_2000_pdpp[268];

    auto g_xy_0_0_0_y_zz_z_z = buffer_2000_pdpp[269];

    auto g_xy_0_0_0_z_xx_x_x = buffer_2000_pdpp[270];

    auto g_xy_0_0_0_z_xx_x_y = buffer_2000_pdpp[271];

    auto g_xy_0_0_0_z_xx_x_z = buffer_2000_pdpp[272];

    auto g_xy_0_0_0_z_xx_y_x = buffer_2000_pdpp[273];

    auto g_xy_0_0_0_z_xx_y_y = buffer_2000_pdpp[274];

    auto g_xy_0_0_0_z_xx_y_z = buffer_2000_pdpp[275];

    auto g_xy_0_0_0_z_xx_z_x = buffer_2000_pdpp[276];

    auto g_xy_0_0_0_z_xx_z_y = buffer_2000_pdpp[277];

    auto g_xy_0_0_0_z_xx_z_z = buffer_2000_pdpp[278];

    auto g_xy_0_0_0_z_xy_x_x = buffer_2000_pdpp[279];

    auto g_xy_0_0_0_z_xy_x_y = buffer_2000_pdpp[280];

    auto g_xy_0_0_0_z_xy_x_z = buffer_2000_pdpp[281];

    auto g_xy_0_0_0_z_xy_y_x = buffer_2000_pdpp[282];

    auto g_xy_0_0_0_z_xy_y_y = buffer_2000_pdpp[283];

    auto g_xy_0_0_0_z_xy_y_z = buffer_2000_pdpp[284];

    auto g_xy_0_0_0_z_xy_z_x = buffer_2000_pdpp[285];

    auto g_xy_0_0_0_z_xy_z_y = buffer_2000_pdpp[286];

    auto g_xy_0_0_0_z_xy_z_z = buffer_2000_pdpp[287];

    auto g_xy_0_0_0_z_xz_x_x = buffer_2000_pdpp[288];

    auto g_xy_0_0_0_z_xz_x_y = buffer_2000_pdpp[289];

    auto g_xy_0_0_0_z_xz_x_z = buffer_2000_pdpp[290];

    auto g_xy_0_0_0_z_xz_y_x = buffer_2000_pdpp[291];

    auto g_xy_0_0_0_z_xz_y_y = buffer_2000_pdpp[292];

    auto g_xy_0_0_0_z_xz_y_z = buffer_2000_pdpp[293];

    auto g_xy_0_0_0_z_xz_z_x = buffer_2000_pdpp[294];

    auto g_xy_0_0_0_z_xz_z_y = buffer_2000_pdpp[295];

    auto g_xy_0_0_0_z_xz_z_z = buffer_2000_pdpp[296];

    auto g_xy_0_0_0_z_yy_x_x = buffer_2000_pdpp[297];

    auto g_xy_0_0_0_z_yy_x_y = buffer_2000_pdpp[298];

    auto g_xy_0_0_0_z_yy_x_z = buffer_2000_pdpp[299];

    auto g_xy_0_0_0_z_yy_y_x = buffer_2000_pdpp[300];

    auto g_xy_0_0_0_z_yy_y_y = buffer_2000_pdpp[301];

    auto g_xy_0_0_0_z_yy_y_z = buffer_2000_pdpp[302];

    auto g_xy_0_0_0_z_yy_z_x = buffer_2000_pdpp[303];

    auto g_xy_0_0_0_z_yy_z_y = buffer_2000_pdpp[304];

    auto g_xy_0_0_0_z_yy_z_z = buffer_2000_pdpp[305];

    auto g_xy_0_0_0_z_yz_x_x = buffer_2000_pdpp[306];

    auto g_xy_0_0_0_z_yz_x_y = buffer_2000_pdpp[307];

    auto g_xy_0_0_0_z_yz_x_z = buffer_2000_pdpp[308];

    auto g_xy_0_0_0_z_yz_y_x = buffer_2000_pdpp[309];

    auto g_xy_0_0_0_z_yz_y_y = buffer_2000_pdpp[310];

    auto g_xy_0_0_0_z_yz_y_z = buffer_2000_pdpp[311];

    auto g_xy_0_0_0_z_yz_z_x = buffer_2000_pdpp[312];

    auto g_xy_0_0_0_z_yz_z_y = buffer_2000_pdpp[313];

    auto g_xy_0_0_0_z_yz_z_z = buffer_2000_pdpp[314];

    auto g_xy_0_0_0_z_zz_x_x = buffer_2000_pdpp[315];

    auto g_xy_0_0_0_z_zz_x_y = buffer_2000_pdpp[316];

    auto g_xy_0_0_0_z_zz_x_z = buffer_2000_pdpp[317];

    auto g_xy_0_0_0_z_zz_y_x = buffer_2000_pdpp[318];

    auto g_xy_0_0_0_z_zz_y_y = buffer_2000_pdpp[319];

    auto g_xy_0_0_0_z_zz_y_z = buffer_2000_pdpp[320];

    auto g_xy_0_0_0_z_zz_z_x = buffer_2000_pdpp[321];

    auto g_xy_0_0_0_z_zz_z_y = buffer_2000_pdpp[322];

    auto g_xy_0_0_0_z_zz_z_z = buffer_2000_pdpp[323];

    auto g_xz_0_0_0_x_xx_x_x = buffer_2000_pdpp[324];

    auto g_xz_0_0_0_x_xx_x_y = buffer_2000_pdpp[325];

    auto g_xz_0_0_0_x_xx_x_z = buffer_2000_pdpp[326];

    auto g_xz_0_0_0_x_xx_y_x = buffer_2000_pdpp[327];

    auto g_xz_0_0_0_x_xx_y_y = buffer_2000_pdpp[328];

    auto g_xz_0_0_0_x_xx_y_z = buffer_2000_pdpp[329];

    auto g_xz_0_0_0_x_xx_z_x = buffer_2000_pdpp[330];

    auto g_xz_0_0_0_x_xx_z_y = buffer_2000_pdpp[331];

    auto g_xz_0_0_0_x_xx_z_z = buffer_2000_pdpp[332];

    auto g_xz_0_0_0_x_xy_x_x = buffer_2000_pdpp[333];

    auto g_xz_0_0_0_x_xy_x_y = buffer_2000_pdpp[334];

    auto g_xz_0_0_0_x_xy_x_z = buffer_2000_pdpp[335];

    auto g_xz_0_0_0_x_xy_y_x = buffer_2000_pdpp[336];

    auto g_xz_0_0_0_x_xy_y_y = buffer_2000_pdpp[337];

    auto g_xz_0_0_0_x_xy_y_z = buffer_2000_pdpp[338];

    auto g_xz_0_0_0_x_xy_z_x = buffer_2000_pdpp[339];

    auto g_xz_0_0_0_x_xy_z_y = buffer_2000_pdpp[340];

    auto g_xz_0_0_0_x_xy_z_z = buffer_2000_pdpp[341];

    auto g_xz_0_0_0_x_xz_x_x = buffer_2000_pdpp[342];

    auto g_xz_0_0_0_x_xz_x_y = buffer_2000_pdpp[343];

    auto g_xz_0_0_0_x_xz_x_z = buffer_2000_pdpp[344];

    auto g_xz_0_0_0_x_xz_y_x = buffer_2000_pdpp[345];

    auto g_xz_0_0_0_x_xz_y_y = buffer_2000_pdpp[346];

    auto g_xz_0_0_0_x_xz_y_z = buffer_2000_pdpp[347];

    auto g_xz_0_0_0_x_xz_z_x = buffer_2000_pdpp[348];

    auto g_xz_0_0_0_x_xz_z_y = buffer_2000_pdpp[349];

    auto g_xz_0_0_0_x_xz_z_z = buffer_2000_pdpp[350];

    auto g_xz_0_0_0_x_yy_x_x = buffer_2000_pdpp[351];

    auto g_xz_0_0_0_x_yy_x_y = buffer_2000_pdpp[352];

    auto g_xz_0_0_0_x_yy_x_z = buffer_2000_pdpp[353];

    auto g_xz_0_0_0_x_yy_y_x = buffer_2000_pdpp[354];

    auto g_xz_0_0_0_x_yy_y_y = buffer_2000_pdpp[355];

    auto g_xz_0_0_0_x_yy_y_z = buffer_2000_pdpp[356];

    auto g_xz_0_0_0_x_yy_z_x = buffer_2000_pdpp[357];

    auto g_xz_0_0_0_x_yy_z_y = buffer_2000_pdpp[358];

    auto g_xz_0_0_0_x_yy_z_z = buffer_2000_pdpp[359];

    auto g_xz_0_0_0_x_yz_x_x = buffer_2000_pdpp[360];

    auto g_xz_0_0_0_x_yz_x_y = buffer_2000_pdpp[361];

    auto g_xz_0_0_0_x_yz_x_z = buffer_2000_pdpp[362];

    auto g_xz_0_0_0_x_yz_y_x = buffer_2000_pdpp[363];

    auto g_xz_0_0_0_x_yz_y_y = buffer_2000_pdpp[364];

    auto g_xz_0_0_0_x_yz_y_z = buffer_2000_pdpp[365];

    auto g_xz_0_0_0_x_yz_z_x = buffer_2000_pdpp[366];

    auto g_xz_0_0_0_x_yz_z_y = buffer_2000_pdpp[367];

    auto g_xz_0_0_0_x_yz_z_z = buffer_2000_pdpp[368];

    auto g_xz_0_0_0_x_zz_x_x = buffer_2000_pdpp[369];

    auto g_xz_0_0_0_x_zz_x_y = buffer_2000_pdpp[370];

    auto g_xz_0_0_0_x_zz_x_z = buffer_2000_pdpp[371];

    auto g_xz_0_0_0_x_zz_y_x = buffer_2000_pdpp[372];

    auto g_xz_0_0_0_x_zz_y_y = buffer_2000_pdpp[373];

    auto g_xz_0_0_0_x_zz_y_z = buffer_2000_pdpp[374];

    auto g_xz_0_0_0_x_zz_z_x = buffer_2000_pdpp[375];

    auto g_xz_0_0_0_x_zz_z_y = buffer_2000_pdpp[376];

    auto g_xz_0_0_0_x_zz_z_z = buffer_2000_pdpp[377];

    auto g_xz_0_0_0_y_xx_x_x = buffer_2000_pdpp[378];

    auto g_xz_0_0_0_y_xx_x_y = buffer_2000_pdpp[379];

    auto g_xz_0_0_0_y_xx_x_z = buffer_2000_pdpp[380];

    auto g_xz_0_0_0_y_xx_y_x = buffer_2000_pdpp[381];

    auto g_xz_0_0_0_y_xx_y_y = buffer_2000_pdpp[382];

    auto g_xz_0_0_0_y_xx_y_z = buffer_2000_pdpp[383];

    auto g_xz_0_0_0_y_xx_z_x = buffer_2000_pdpp[384];

    auto g_xz_0_0_0_y_xx_z_y = buffer_2000_pdpp[385];

    auto g_xz_0_0_0_y_xx_z_z = buffer_2000_pdpp[386];

    auto g_xz_0_0_0_y_xy_x_x = buffer_2000_pdpp[387];

    auto g_xz_0_0_0_y_xy_x_y = buffer_2000_pdpp[388];

    auto g_xz_0_0_0_y_xy_x_z = buffer_2000_pdpp[389];

    auto g_xz_0_0_0_y_xy_y_x = buffer_2000_pdpp[390];

    auto g_xz_0_0_0_y_xy_y_y = buffer_2000_pdpp[391];

    auto g_xz_0_0_0_y_xy_y_z = buffer_2000_pdpp[392];

    auto g_xz_0_0_0_y_xy_z_x = buffer_2000_pdpp[393];

    auto g_xz_0_0_0_y_xy_z_y = buffer_2000_pdpp[394];

    auto g_xz_0_0_0_y_xy_z_z = buffer_2000_pdpp[395];

    auto g_xz_0_0_0_y_xz_x_x = buffer_2000_pdpp[396];

    auto g_xz_0_0_0_y_xz_x_y = buffer_2000_pdpp[397];

    auto g_xz_0_0_0_y_xz_x_z = buffer_2000_pdpp[398];

    auto g_xz_0_0_0_y_xz_y_x = buffer_2000_pdpp[399];

    auto g_xz_0_0_0_y_xz_y_y = buffer_2000_pdpp[400];

    auto g_xz_0_0_0_y_xz_y_z = buffer_2000_pdpp[401];

    auto g_xz_0_0_0_y_xz_z_x = buffer_2000_pdpp[402];

    auto g_xz_0_0_0_y_xz_z_y = buffer_2000_pdpp[403];

    auto g_xz_0_0_0_y_xz_z_z = buffer_2000_pdpp[404];

    auto g_xz_0_0_0_y_yy_x_x = buffer_2000_pdpp[405];

    auto g_xz_0_0_0_y_yy_x_y = buffer_2000_pdpp[406];

    auto g_xz_0_0_0_y_yy_x_z = buffer_2000_pdpp[407];

    auto g_xz_0_0_0_y_yy_y_x = buffer_2000_pdpp[408];

    auto g_xz_0_0_0_y_yy_y_y = buffer_2000_pdpp[409];

    auto g_xz_0_0_0_y_yy_y_z = buffer_2000_pdpp[410];

    auto g_xz_0_0_0_y_yy_z_x = buffer_2000_pdpp[411];

    auto g_xz_0_0_0_y_yy_z_y = buffer_2000_pdpp[412];

    auto g_xz_0_0_0_y_yy_z_z = buffer_2000_pdpp[413];

    auto g_xz_0_0_0_y_yz_x_x = buffer_2000_pdpp[414];

    auto g_xz_0_0_0_y_yz_x_y = buffer_2000_pdpp[415];

    auto g_xz_0_0_0_y_yz_x_z = buffer_2000_pdpp[416];

    auto g_xz_0_0_0_y_yz_y_x = buffer_2000_pdpp[417];

    auto g_xz_0_0_0_y_yz_y_y = buffer_2000_pdpp[418];

    auto g_xz_0_0_0_y_yz_y_z = buffer_2000_pdpp[419];

    auto g_xz_0_0_0_y_yz_z_x = buffer_2000_pdpp[420];

    auto g_xz_0_0_0_y_yz_z_y = buffer_2000_pdpp[421];

    auto g_xz_0_0_0_y_yz_z_z = buffer_2000_pdpp[422];

    auto g_xz_0_0_0_y_zz_x_x = buffer_2000_pdpp[423];

    auto g_xz_0_0_0_y_zz_x_y = buffer_2000_pdpp[424];

    auto g_xz_0_0_0_y_zz_x_z = buffer_2000_pdpp[425];

    auto g_xz_0_0_0_y_zz_y_x = buffer_2000_pdpp[426];

    auto g_xz_0_0_0_y_zz_y_y = buffer_2000_pdpp[427];

    auto g_xz_0_0_0_y_zz_y_z = buffer_2000_pdpp[428];

    auto g_xz_0_0_0_y_zz_z_x = buffer_2000_pdpp[429];

    auto g_xz_0_0_0_y_zz_z_y = buffer_2000_pdpp[430];

    auto g_xz_0_0_0_y_zz_z_z = buffer_2000_pdpp[431];

    auto g_xz_0_0_0_z_xx_x_x = buffer_2000_pdpp[432];

    auto g_xz_0_0_0_z_xx_x_y = buffer_2000_pdpp[433];

    auto g_xz_0_0_0_z_xx_x_z = buffer_2000_pdpp[434];

    auto g_xz_0_0_0_z_xx_y_x = buffer_2000_pdpp[435];

    auto g_xz_0_0_0_z_xx_y_y = buffer_2000_pdpp[436];

    auto g_xz_0_0_0_z_xx_y_z = buffer_2000_pdpp[437];

    auto g_xz_0_0_0_z_xx_z_x = buffer_2000_pdpp[438];

    auto g_xz_0_0_0_z_xx_z_y = buffer_2000_pdpp[439];

    auto g_xz_0_0_0_z_xx_z_z = buffer_2000_pdpp[440];

    auto g_xz_0_0_0_z_xy_x_x = buffer_2000_pdpp[441];

    auto g_xz_0_0_0_z_xy_x_y = buffer_2000_pdpp[442];

    auto g_xz_0_0_0_z_xy_x_z = buffer_2000_pdpp[443];

    auto g_xz_0_0_0_z_xy_y_x = buffer_2000_pdpp[444];

    auto g_xz_0_0_0_z_xy_y_y = buffer_2000_pdpp[445];

    auto g_xz_0_0_0_z_xy_y_z = buffer_2000_pdpp[446];

    auto g_xz_0_0_0_z_xy_z_x = buffer_2000_pdpp[447];

    auto g_xz_0_0_0_z_xy_z_y = buffer_2000_pdpp[448];

    auto g_xz_0_0_0_z_xy_z_z = buffer_2000_pdpp[449];

    auto g_xz_0_0_0_z_xz_x_x = buffer_2000_pdpp[450];

    auto g_xz_0_0_0_z_xz_x_y = buffer_2000_pdpp[451];

    auto g_xz_0_0_0_z_xz_x_z = buffer_2000_pdpp[452];

    auto g_xz_0_0_0_z_xz_y_x = buffer_2000_pdpp[453];

    auto g_xz_0_0_0_z_xz_y_y = buffer_2000_pdpp[454];

    auto g_xz_0_0_0_z_xz_y_z = buffer_2000_pdpp[455];

    auto g_xz_0_0_0_z_xz_z_x = buffer_2000_pdpp[456];

    auto g_xz_0_0_0_z_xz_z_y = buffer_2000_pdpp[457];

    auto g_xz_0_0_0_z_xz_z_z = buffer_2000_pdpp[458];

    auto g_xz_0_0_0_z_yy_x_x = buffer_2000_pdpp[459];

    auto g_xz_0_0_0_z_yy_x_y = buffer_2000_pdpp[460];

    auto g_xz_0_0_0_z_yy_x_z = buffer_2000_pdpp[461];

    auto g_xz_0_0_0_z_yy_y_x = buffer_2000_pdpp[462];

    auto g_xz_0_0_0_z_yy_y_y = buffer_2000_pdpp[463];

    auto g_xz_0_0_0_z_yy_y_z = buffer_2000_pdpp[464];

    auto g_xz_0_0_0_z_yy_z_x = buffer_2000_pdpp[465];

    auto g_xz_0_0_0_z_yy_z_y = buffer_2000_pdpp[466];

    auto g_xz_0_0_0_z_yy_z_z = buffer_2000_pdpp[467];

    auto g_xz_0_0_0_z_yz_x_x = buffer_2000_pdpp[468];

    auto g_xz_0_0_0_z_yz_x_y = buffer_2000_pdpp[469];

    auto g_xz_0_0_0_z_yz_x_z = buffer_2000_pdpp[470];

    auto g_xz_0_0_0_z_yz_y_x = buffer_2000_pdpp[471];

    auto g_xz_0_0_0_z_yz_y_y = buffer_2000_pdpp[472];

    auto g_xz_0_0_0_z_yz_y_z = buffer_2000_pdpp[473];

    auto g_xz_0_0_0_z_yz_z_x = buffer_2000_pdpp[474];

    auto g_xz_0_0_0_z_yz_z_y = buffer_2000_pdpp[475];

    auto g_xz_0_0_0_z_yz_z_z = buffer_2000_pdpp[476];

    auto g_xz_0_0_0_z_zz_x_x = buffer_2000_pdpp[477];

    auto g_xz_0_0_0_z_zz_x_y = buffer_2000_pdpp[478];

    auto g_xz_0_0_0_z_zz_x_z = buffer_2000_pdpp[479];

    auto g_xz_0_0_0_z_zz_y_x = buffer_2000_pdpp[480];

    auto g_xz_0_0_0_z_zz_y_y = buffer_2000_pdpp[481];

    auto g_xz_0_0_0_z_zz_y_z = buffer_2000_pdpp[482];

    auto g_xz_0_0_0_z_zz_z_x = buffer_2000_pdpp[483];

    auto g_xz_0_0_0_z_zz_z_y = buffer_2000_pdpp[484];

    auto g_xz_0_0_0_z_zz_z_z = buffer_2000_pdpp[485];

    auto g_yy_0_0_0_x_xx_x_x = buffer_2000_pdpp[486];

    auto g_yy_0_0_0_x_xx_x_y = buffer_2000_pdpp[487];

    auto g_yy_0_0_0_x_xx_x_z = buffer_2000_pdpp[488];

    auto g_yy_0_0_0_x_xx_y_x = buffer_2000_pdpp[489];

    auto g_yy_0_0_0_x_xx_y_y = buffer_2000_pdpp[490];

    auto g_yy_0_0_0_x_xx_y_z = buffer_2000_pdpp[491];

    auto g_yy_0_0_0_x_xx_z_x = buffer_2000_pdpp[492];

    auto g_yy_0_0_0_x_xx_z_y = buffer_2000_pdpp[493];

    auto g_yy_0_0_0_x_xx_z_z = buffer_2000_pdpp[494];

    auto g_yy_0_0_0_x_xy_x_x = buffer_2000_pdpp[495];

    auto g_yy_0_0_0_x_xy_x_y = buffer_2000_pdpp[496];

    auto g_yy_0_0_0_x_xy_x_z = buffer_2000_pdpp[497];

    auto g_yy_0_0_0_x_xy_y_x = buffer_2000_pdpp[498];

    auto g_yy_0_0_0_x_xy_y_y = buffer_2000_pdpp[499];

    auto g_yy_0_0_0_x_xy_y_z = buffer_2000_pdpp[500];

    auto g_yy_0_0_0_x_xy_z_x = buffer_2000_pdpp[501];

    auto g_yy_0_0_0_x_xy_z_y = buffer_2000_pdpp[502];

    auto g_yy_0_0_0_x_xy_z_z = buffer_2000_pdpp[503];

    auto g_yy_0_0_0_x_xz_x_x = buffer_2000_pdpp[504];

    auto g_yy_0_0_0_x_xz_x_y = buffer_2000_pdpp[505];

    auto g_yy_0_0_0_x_xz_x_z = buffer_2000_pdpp[506];

    auto g_yy_0_0_0_x_xz_y_x = buffer_2000_pdpp[507];

    auto g_yy_0_0_0_x_xz_y_y = buffer_2000_pdpp[508];

    auto g_yy_0_0_0_x_xz_y_z = buffer_2000_pdpp[509];

    auto g_yy_0_0_0_x_xz_z_x = buffer_2000_pdpp[510];

    auto g_yy_0_0_0_x_xz_z_y = buffer_2000_pdpp[511];

    auto g_yy_0_0_0_x_xz_z_z = buffer_2000_pdpp[512];

    auto g_yy_0_0_0_x_yy_x_x = buffer_2000_pdpp[513];

    auto g_yy_0_0_0_x_yy_x_y = buffer_2000_pdpp[514];

    auto g_yy_0_0_0_x_yy_x_z = buffer_2000_pdpp[515];

    auto g_yy_0_0_0_x_yy_y_x = buffer_2000_pdpp[516];

    auto g_yy_0_0_0_x_yy_y_y = buffer_2000_pdpp[517];

    auto g_yy_0_0_0_x_yy_y_z = buffer_2000_pdpp[518];

    auto g_yy_0_0_0_x_yy_z_x = buffer_2000_pdpp[519];

    auto g_yy_0_0_0_x_yy_z_y = buffer_2000_pdpp[520];

    auto g_yy_0_0_0_x_yy_z_z = buffer_2000_pdpp[521];

    auto g_yy_0_0_0_x_yz_x_x = buffer_2000_pdpp[522];

    auto g_yy_0_0_0_x_yz_x_y = buffer_2000_pdpp[523];

    auto g_yy_0_0_0_x_yz_x_z = buffer_2000_pdpp[524];

    auto g_yy_0_0_0_x_yz_y_x = buffer_2000_pdpp[525];

    auto g_yy_0_0_0_x_yz_y_y = buffer_2000_pdpp[526];

    auto g_yy_0_0_0_x_yz_y_z = buffer_2000_pdpp[527];

    auto g_yy_0_0_0_x_yz_z_x = buffer_2000_pdpp[528];

    auto g_yy_0_0_0_x_yz_z_y = buffer_2000_pdpp[529];

    auto g_yy_0_0_0_x_yz_z_z = buffer_2000_pdpp[530];

    auto g_yy_0_0_0_x_zz_x_x = buffer_2000_pdpp[531];

    auto g_yy_0_0_0_x_zz_x_y = buffer_2000_pdpp[532];

    auto g_yy_0_0_0_x_zz_x_z = buffer_2000_pdpp[533];

    auto g_yy_0_0_0_x_zz_y_x = buffer_2000_pdpp[534];

    auto g_yy_0_0_0_x_zz_y_y = buffer_2000_pdpp[535];

    auto g_yy_0_0_0_x_zz_y_z = buffer_2000_pdpp[536];

    auto g_yy_0_0_0_x_zz_z_x = buffer_2000_pdpp[537];

    auto g_yy_0_0_0_x_zz_z_y = buffer_2000_pdpp[538];

    auto g_yy_0_0_0_x_zz_z_z = buffer_2000_pdpp[539];

    auto g_yy_0_0_0_y_xx_x_x = buffer_2000_pdpp[540];

    auto g_yy_0_0_0_y_xx_x_y = buffer_2000_pdpp[541];

    auto g_yy_0_0_0_y_xx_x_z = buffer_2000_pdpp[542];

    auto g_yy_0_0_0_y_xx_y_x = buffer_2000_pdpp[543];

    auto g_yy_0_0_0_y_xx_y_y = buffer_2000_pdpp[544];

    auto g_yy_0_0_0_y_xx_y_z = buffer_2000_pdpp[545];

    auto g_yy_0_0_0_y_xx_z_x = buffer_2000_pdpp[546];

    auto g_yy_0_0_0_y_xx_z_y = buffer_2000_pdpp[547];

    auto g_yy_0_0_0_y_xx_z_z = buffer_2000_pdpp[548];

    auto g_yy_0_0_0_y_xy_x_x = buffer_2000_pdpp[549];

    auto g_yy_0_0_0_y_xy_x_y = buffer_2000_pdpp[550];

    auto g_yy_0_0_0_y_xy_x_z = buffer_2000_pdpp[551];

    auto g_yy_0_0_0_y_xy_y_x = buffer_2000_pdpp[552];

    auto g_yy_0_0_0_y_xy_y_y = buffer_2000_pdpp[553];

    auto g_yy_0_0_0_y_xy_y_z = buffer_2000_pdpp[554];

    auto g_yy_0_0_0_y_xy_z_x = buffer_2000_pdpp[555];

    auto g_yy_0_0_0_y_xy_z_y = buffer_2000_pdpp[556];

    auto g_yy_0_0_0_y_xy_z_z = buffer_2000_pdpp[557];

    auto g_yy_0_0_0_y_xz_x_x = buffer_2000_pdpp[558];

    auto g_yy_0_0_0_y_xz_x_y = buffer_2000_pdpp[559];

    auto g_yy_0_0_0_y_xz_x_z = buffer_2000_pdpp[560];

    auto g_yy_0_0_0_y_xz_y_x = buffer_2000_pdpp[561];

    auto g_yy_0_0_0_y_xz_y_y = buffer_2000_pdpp[562];

    auto g_yy_0_0_0_y_xz_y_z = buffer_2000_pdpp[563];

    auto g_yy_0_0_0_y_xz_z_x = buffer_2000_pdpp[564];

    auto g_yy_0_0_0_y_xz_z_y = buffer_2000_pdpp[565];

    auto g_yy_0_0_0_y_xz_z_z = buffer_2000_pdpp[566];

    auto g_yy_0_0_0_y_yy_x_x = buffer_2000_pdpp[567];

    auto g_yy_0_0_0_y_yy_x_y = buffer_2000_pdpp[568];

    auto g_yy_0_0_0_y_yy_x_z = buffer_2000_pdpp[569];

    auto g_yy_0_0_0_y_yy_y_x = buffer_2000_pdpp[570];

    auto g_yy_0_0_0_y_yy_y_y = buffer_2000_pdpp[571];

    auto g_yy_0_0_0_y_yy_y_z = buffer_2000_pdpp[572];

    auto g_yy_0_0_0_y_yy_z_x = buffer_2000_pdpp[573];

    auto g_yy_0_0_0_y_yy_z_y = buffer_2000_pdpp[574];

    auto g_yy_0_0_0_y_yy_z_z = buffer_2000_pdpp[575];

    auto g_yy_0_0_0_y_yz_x_x = buffer_2000_pdpp[576];

    auto g_yy_0_0_0_y_yz_x_y = buffer_2000_pdpp[577];

    auto g_yy_0_0_0_y_yz_x_z = buffer_2000_pdpp[578];

    auto g_yy_0_0_0_y_yz_y_x = buffer_2000_pdpp[579];

    auto g_yy_0_0_0_y_yz_y_y = buffer_2000_pdpp[580];

    auto g_yy_0_0_0_y_yz_y_z = buffer_2000_pdpp[581];

    auto g_yy_0_0_0_y_yz_z_x = buffer_2000_pdpp[582];

    auto g_yy_0_0_0_y_yz_z_y = buffer_2000_pdpp[583];

    auto g_yy_0_0_0_y_yz_z_z = buffer_2000_pdpp[584];

    auto g_yy_0_0_0_y_zz_x_x = buffer_2000_pdpp[585];

    auto g_yy_0_0_0_y_zz_x_y = buffer_2000_pdpp[586];

    auto g_yy_0_0_0_y_zz_x_z = buffer_2000_pdpp[587];

    auto g_yy_0_0_0_y_zz_y_x = buffer_2000_pdpp[588];

    auto g_yy_0_0_0_y_zz_y_y = buffer_2000_pdpp[589];

    auto g_yy_0_0_0_y_zz_y_z = buffer_2000_pdpp[590];

    auto g_yy_0_0_0_y_zz_z_x = buffer_2000_pdpp[591];

    auto g_yy_0_0_0_y_zz_z_y = buffer_2000_pdpp[592];

    auto g_yy_0_0_0_y_zz_z_z = buffer_2000_pdpp[593];

    auto g_yy_0_0_0_z_xx_x_x = buffer_2000_pdpp[594];

    auto g_yy_0_0_0_z_xx_x_y = buffer_2000_pdpp[595];

    auto g_yy_0_0_0_z_xx_x_z = buffer_2000_pdpp[596];

    auto g_yy_0_0_0_z_xx_y_x = buffer_2000_pdpp[597];

    auto g_yy_0_0_0_z_xx_y_y = buffer_2000_pdpp[598];

    auto g_yy_0_0_0_z_xx_y_z = buffer_2000_pdpp[599];

    auto g_yy_0_0_0_z_xx_z_x = buffer_2000_pdpp[600];

    auto g_yy_0_0_0_z_xx_z_y = buffer_2000_pdpp[601];

    auto g_yy_0_0_0_z_xx_z_z = buffer_2000_pdpp[602];

    auto g_yy_0_0_0_z_xy_x_x = buffer_2000_pdpp[603];

    auto g_yy_0_0_0_z_xy_x_y = buffer_2000_pdpp[604];

    auto g_yy_0_0_0_z_xy_x_z = buffer_2000_pdpp[605];

    auto g_yy_0_0_0_z_xy_y_x = buffer_2000_pdpp[606];

    auto g_yy_0_0_0_z_xy_y_y = buffer_2000_pdpp[607];

    auto g_yy_0_0_0_z_xy_y_z = buffer_2000_pdpp[608];

    auto g_yy_0_0_0_z_xy_z_x = buffer_2000_pdpp[609];

    auto g_yy_0_0_0_z_xy_z_y = buffer_2000_pdpp[610];

    auto g_yy_0_0_0_z_xy_z_z = buffer_2000_pdpp[611];

    auto g_yy_0_0_0_z_xz_x_x = buffer_2000_pdpp[612];

    auto g_yy_0_0_0_z_xz_x_y = buffer_2000_pdpp[613];

    auto g_yy_0_0_0_z_xz_x_z = buffer_2000_pdpp[614];

    auto g_yy_0_0_0_z_xz_y_x = buffer_2000_pdpp[615];

    auto g_yy_0_0_0_z_xz_y_y = buffer_2000_pdpp[616];

    auto g_yy_0_0_0_z_xz_y_z = buffer_2000_pdpp[617];

    auto g_yy_0_0_0_z_xz_z_x = buffer_2000_pdpp[618];

    auto g_yy_0_0_0_z_xz_z_y = buffer_2000_pdpp[619];

    auto g_yy_0_0_0_z_xz_z_z = buffer_2000_pdpp[620];

    auto g_yy_0_0_0_z_yy_x_x = buffer_2000_pdpp[621];

    auto g_yy_0_0_0_z_yy_x_y = buffer_2000_pdpp[622];

    auto g_yy_0_0_0_z_yy_x_z = buffer_2000_pdpp[623];

    auto g_yy_0_0_0_z_yy_y_x = buffer_2000_pdpp[624];

    auto g_yy_0_0_0_z_yy_y_y = buffer_2000_pdpp[625];

    auto g_yy_0_0_0_z_yy_y_z = buffer_2000_pdpp[626];

    auto g_yy_0_0_0_z_yy_z_x = buffer_2000_pdpp[627];

    auto g_yy_0_0_0_z_yy_z_y = buffer_2000_pdpp[628];

    auto g_yy_0_0_0_z_yy_z_z = buffer_2000_pdpp[629];

    auto g_yy_0_0_0_z_yz_x_x = buffer_2000_pdpp[630];

    auto g_yy_0_0_0_z_yz_x_y = buffer_2000_pdpp[631];

    auto g_yy_0_0_0_z_yz_x_z = buffer_2000_pdpp[632];

    auto g_yy_0_0_0_z_yz_y_x = buffer_2000_pdpp[633];

    auto g_yy_0_0_0_z_yz_y_y = buffer_2000_pdpp[634];

    auto g_yy_0_0_0_z_yz_y_z = buffer_2000_pdpp[635];

    auto g_yy_0_0_0_z_yz_z_x = buffer_2000_pdpp[636];

    auto g_yy_0_0_0_z_yz_z_y = buffer_2000_pdpp[637];

    auto g_yy_0_0_0_z_yz_z_z = buffer_2000_pdpp[638];

    auto g_yy_0_0_0_z_zz_x_x = buffer_2000_pdpp[639];

    auto g_yy_0_0_0_z_zz_x_y = buffer_2000_pdpp[640];

    auto g_yy_0_0_0_z_zz_x_z = buffer_2000_pdpp[641];

    auto g_yy_0_0_0_z_zz_y_x = buffer_2000_pdpp[642];

    auto g_yy_0_0_0_z_zz_y_y = buffer_2000_pdpp[643];

    auto g_yy_0_0_0_z_zz_y_z = buffer_2000_pdpp[644];

    auto g_yy_0_0_0_z_zz_z_x = buffer_2000_pdpp[645];

    auto g_yy_0_0_0_z_zz_z_y = buffer_2000_pdpp[646];

    auto g_yy_0_0_0_z_zz_z_z = buffer_2000_pdpp[647];

    auto g_yz_0_0_0_x_xx_x_x = buffer_2000_pdpp[648];

    auto g_yz_0_0_0_x_xx_x_y = buffer_2000_pdpp[649];

    auto g_yz_0_0_0_x_xx_x_z = buffer_2000_pdpp[650];

    auto g_yz_0_0_0_x_xx_y_x = buffer_2000_pdpp[651];

    auto g_yz_0_0_0_x_xx_y_y = buffer_2000_pdpp[652];

    auto g_yz_0_0_0_x_xx_y_z = buffer_2000_pdpp[653];

    auto g_yz_0_0_0_x_xx_z_x = buffer_2000_pdpp[654];

    auto g_yz_0_0_0_x_xx_z_y = buffer_2000_pdpp[655];

    auto g_yz_0_0_0_x_xx_z_z = buffer_2000_pdpp[656];

    auto g_yz_0_0_0_x_xy_x_x = buffer_2000_pdpp[657];

    auto g_yz_0_0_0_x_xy_x_y = buffer_2000_pdpp[658];

    auto g_yz_0_0_0_x_xy_x_z = buffer_2000_pdpp[659];

    auto g_yz_0_0_0_x_xy_y_x = buffer_2000_pdpp[660];

    auto g_yz_0_0_0_x_xy_y_y = buffer_2000_pdpp[661];

    auto g_yz_0_0_0_x_xy_y_z = buffer_2000_pdpp[662];

    auto g_yz_0_0_0_x_xy_z_x = buffer_2000_pdpp[663];

    auto g_yz_0_0_0_x_xy_z_y = buffer_2000_pdpp[664];

    auto g_yz_0_0_0_x_xy_z_z = buffer_2000_pdpp[665];

    auto g_yz_0_0_0_x_xz_x_x = buffer_2000_pdpp[666];

    auto g_yz_0_0_0_x_xz_x_y = buffer_2000_pdpp[667];

    auto g_yz_0_0_0_x_xz_x_z = buffer_2000_pdpp[668];

    auto g_yz_0_0_0_x_xz_y_x = buffer_2000_pdpp[669];

    auto g_yz_0_0_0_x_xz_y_y = buffer_2000_pdpp[670];

    auto g_yz_0_0_0_x_xz_y_z = buffer_2000_pdpp[671];

    auto g_yz_0_0_0_x_xz_z_x = buffer_2000_pdpp[672];

    auto g_yz_0_0_0_x_xz_z_y = buffer_2000_pdpp[673];

    auto g_yz_0_0_0_x_xz_z_z = buffer_2000_pdpp[674];

    auto g_yz_0_0_0_x_yy_x_x = buffer_2000_pdpp[675];

    auto g_yz_0_0_0_x_yy_x_y = buffer_2000_pdpp[676];

    auto g_yz_0_0_0_x_yy_x_z = buffer_2000_pdpp[677];

    auto g_yz_0_0_0_x_yy_y_x = buffer_2000_pdpp[678];

    auto g_yz_0_0_0_x_yy_y_y = buffer_2000_pdpp[679];

    auto g_yz_0_0_0_x_yy_y_z = buffer_2000_pdpp[680];

    auto g_yz_0_0_0_x_yy_z_x = buffer_2000_pdpp[681];

    auto g_yz_0_0_0_x_yy_z_y = buffer_2000_pdpp[682];

    auto g_yz_0_0_0_x_yy_z_z = buffer_2000_pdpp[683];

    auto g_yz_0_0_0_x_yz_x_x = buffer_2000_pdpp[684];

    auto g_yz_0_0_0_x_yz_x_y = buffer_2000_pdpp[685];

    auto g_yz_0_0_0_x_yz_x_z = buffer_2000_pdpp[686];

    auto g_yz_0_0_0_x_yz_y_x = buffer_2000_pdpp[687];

    auto g_yz_0_0_0_x_yz_y_y = buffer_2000_pdpp[688];

    auto g_yz_0_0_0_x_yz_y_z = buffer_2000_pdpp[689];

    auto g_yz_0_0_0_x_yz_z_x = buffer_2000_pdpp[690];

    auto g_yz_0_0_0_x_yz_z_y = buffer_2000_pdpp[691];

    auto g_yz_0_0_0_x_yz_z_z = buffer_2000_pdpp[692];

    auto g_yz_0_0_0_x_zz_x_x = buffer_2000_pdpp[693];

    auto g_yz_0_0_0_x_zz_x_y = buffer_2000_pdpp[694];

    auto g_yz_0_0_0_x_zz_x_z = buffer_2000_pdpp[695];

    auto g_yz_0_0_0_x_zz_y_x = buffer_2000_pdpp[696];

    auto g_yz_0_0_0_x_zz_y_y = buffer_2000_pdpp[697];

    auto g_yz_0_0_0_x_zz_y_z = buffer_2000_pdpp[698];

    auto g_yz_0_0_0_x_zz_z_x = buffer_2000_pdpp[699];

    auto g_yz_0_0_0_x_zz_z_y = buffer_2000_pdpp[700];

    auto g_yz_0_0_0_x_zz_z_z = buffer_2000_pdpp[701];

    auto g_yz_0_0_0_y_xx_x_x = buffer_2000_pdpp[702];

    auto g_yz_0_0_0_y_xx_x_y = buffer_2000_pdpp[703];

    auto g_yz_0_0_0_y_xx_x_z = buffer_2000_pdpp[704];

    auto g_yz_0_0_0_y_xx_y_x = buffer_2000_pdpp[705];

    auto g_yz_0_0_0_y_xx_y_y = buffer_2000_pdpp[706];

    auto g_yz_0_0_0_y_xx_y_z = buffer_2000_pdpp[707];

    auto g_yz_0_0_0_y_xx_z_x = buffer_2000_pdpp[708];

    auto g_yz_0_0_0_y_xx_z_y = buffer_2000_pdpp[709];

    auto g_yz_0_0_0_y_xx_z_z = buffer_2000_pdpp[710];

    auto g_yz_0_0_0_y_xy_x_x = buffer_2000_pdpp[711];

    auto g_yz_0_0_0_y_xy_x_y = buffer_2000_pdpp[712];

    auto g_yz_0_0_0_y_xy_x_z = buffer_2000_pdpp[713];

    auto g_yz_0_0_0_y_xy_y_x = buffer_2000_pdpp[714];

    auto g_yz_0_0_0_y_xy_y_y = buffer_2000_pdpp[715];

    auto g_yz_0_0_0_y_xy_y_z = buffer_2000_pdpp[716];

    auto g_yz_0_0_0_y_xy_z_x = buffer_2000_pdpp[717];

    auto g_yz_0_0_0_y_xy_z_y = buffer_2000_pdpp[718];

    auto g_yz_0_0_0_y_xy_z_z = buffer_2000_pdpp[719];

    auto g_yz_0_0_0_y_xz_x_x = buffer_2000_pdpp[720];

    auto g_yz_0_0_0_y_xz_x_y = buffer_2000_pdpp[721];

    auto g_yz_0_0_0_y_xz_x_z = buffer_2000_pdpp[722];

    auto g_yz_0_0_0_y_xz_y_x = buffer_2000_pdpp[723];

    auto g_yz_0_0_0_y_xz_y_y = buffer_2000_pdpp[724];

    auto g_yz_0_0_0_y_xz_y_z = buffer_2000_pdpp[725];

    auto g_yz_0_0_0_y_xz_z_x = buffer_2000_pdpp[726];

    auto g_yz_0_0_0_y_xz_z_y = buffer_2000_pdpp[727];

    auto g_yz_0_0_0_y_xz_z_z = buffer_2000_pdpp[728];

    auto g_yz_0_0_0_y_yy_x_x = buffer_2000_pdpp[729];

    auto g_yz_0_0_0_y_yy_x_y = buffer_2000_pdpp[730];

    auto g_yz_0_0_0_y_yy_x_z = buffer_2000_pdpp[731];

    auto g_yz_0_0_0_y_yy_y_x = buffer_2000_pdpp[732];

    auto g_yz_0_0_0_y_yy_y_y = buffer_2000_pdpp[733];

    auto g_yz_0_0_0_y_yy_y_z = buffer_2000_pdpp[734];

    auto g_yz_0_0_0_y_yy_z_x = buffer_2000_pdpp[735];

    auto g_yz_0_0_0_y_yy_z_y = buffer_2000_pdpp[736];

    auto g_yz_0_0_0_y_yy_z_z = buffer_2000_pdpp[737];

    auto g_yz_0_0_0_y_yz_x_x = buffer_2000_pdpp[738];

    auto g_yz_0_0_0_y_yz_x_y = buffer_2000_pdpp[739];

    auto g_yz_0_0_0_y_yz_x_z = buffer_2000_pdpp[740];

    auto g_yz_0_0_0_y_yz_y_x = buffer_2000_pdpp[741];

    auto g_yz_0_0_0_y_yz_y_y = buffer_2000_pdpp[742];

    auto g_yz_0_0_0_y_yz_y_z = buffer_2000_pdpp[743];

    auto g_yz_0_0_0_y_yz_z_x = buffer_2000_pdpp[744];

    auto g_yz_0_0_0_y_yz_z_y = buffer_2000_pdpp[745];

    auto g_yz_0_0_0_y_yz_z_z = buffer_2000_pdpp[746];

    auto g_yz_0_0_0_y_zz_x_x = buffer_2000_pdpp[747];

    auto g_yz_0_0_0_y_zz_x_y = buffer_2000_pdpp[748];

    auto g_yz_0_0_0_y_zz_x_z = buffer_2000_pdpp[749];

    auto g_yz_0_0_0_y_zz_y_x = buffer_2000_pdpp[750];

    auto g_yz_0_0_0_y_zz_y_y = buffer_2000_pdpp[751];

    auto g_yz_0_0_0_y_zz_y_z = buffer_2000_pdpp[752];

    auto g_yz_0_0_0_y_zz_z_x = buffer_2000_pdpp[753];

    auto g_yz_0_0_0_y_zz_z_y = buffer_2000_pdpp[754];

    auto g_yz_0_0_0_y_zz_z_z = buffer_2000_pdpp[755];

    auto g_yz_0_0_0_z_xx_x_x = buffer_2000_pdpp[756];

    auto g_yz_0_0_0_z_xx_x_y = buffer_2000_pdpp[757];

    auto g_yz_0_0_0_z_xx_x_z = buffer_2000_pdpp[758];

    auto g_yz_0_0_0_z_xx_y_x = buffer_2000_pdpp[759];

    auto g_yz_0_0_0_z_xx_y_y = buffer_2000_pdpp[760];

    auto g_yz_0_0_0_z_xx_y_z = buffer_2000_pdpp[761];

    auto g_yz_0_0_0_z_xx_z_x = buffer_2000_pdpp[762];

    auto g_yz_0_0_0_z_xx_z_y = buffer_2000_pdpp[763];

    auto g_yz_0_0_0_z_xx_z_z = buffer_2000_pdpp[764];

    auto g_yz_0_0_0_z_xy_x_x = buffer_2000_pdpp[765];

    auto g_yz_0_0_0_z_xy_x_y = buffer_2000_pdpp[766];

    auto g_yz_0_0_0_z_xy_x_z = buffer_2000_pdpp[767];

    auto g_yz_0_0_0_z_xy_y_x = buffer_2000_pdpp[768];

    auto g_yz_0_0_0_z_xy_y_y = buffer_2000_pdpp[769];

    auto g_yz_0_0_0_z_xy_y_z = buffer_2000_pdpp[770];

    auto g_yz_0_0_0_z_xy_z_x = buffer_2000_pdpp[771];

    auto g_yz_0_0_0_z_xy_z_y = buffer_2000_pdpp[772];

    auto g_yz_0_0_0_z_xy_z_z = buffer_2000_pdpp[773];

    auto g_yz_0_0_0_z_xz_x_x = buffer_2000_pdpp[774];

    auto g_yz_0_0_0_z_xz_x_y = buffer_2000_pdpp[775];

    auto g_yz_0_0_0_z_xz_x_z = buffer_2000_pdpp[776];

    auto g_yz_0_0_0_z_xz_y_x = buffer_2000_pdpp[777];

    auto g_yz_0_0_0_z_xz_y_y = buffer_2000_pdpp[778];

    auto g_yz_0_0_0_z_xz_y_z = buffer_2000_pdpp[779];

    auto g_yz_0_0_0_z_xz_z_x = buffer_2000_pdpp[780];

    auto g_yz_0_0_0_z_xz_z_y = buffer_2000_pdpp[781];

    auto g_yz_0_0_0_z_xz_z_z = buffer_2000_pdpp[782];

    auto g_yz_0_0_0_z_yy_x_x = buffer_2000_pdpp[783];

    auto g_yz_0_0_0_z_yy_x_y = buffer_2000_pdpp[784];

    auto g_yz_0_0_0_z_yy_x_z = buffer_2000_pdpp[785];

    auto g_yz_0_0_0_z_yy_y_x = buffer_2000_pdpp[786];

    auto g_yz_0_0_0_z_yy_y_y = buffer_2000_pdpp[787];

    auto g_yz_0_0_0_z_yy_y_z = buffer_2000_pdpp[788];

    auto g_yz_0_0_0_z_yy_z_x = buffer_2000_pdpp[789];

    auto g_yz_0_0_0_z_yy_z_y = buffer_2000_pdpp[790];

    auto g_yz_0_0_0_z_yy_z_z = buffer_2000_pdpp[791];

    auto g_yz_0_0_0_z_yz_x_x = buffer_2000_pdpp[792];

    auto g_yz_0_0_0_z_yz_x_y = buffer_2000_pdpp[793];

    auto g_yz_0_0_0_z_yz_x_z = buffer_2000_pdpp[794];

    auto g_yz_0_0_0_z_yz_y_x = buffer_2000_pdpp[795];

    auto g_yz_0_0_0_z_yz_y_y = buffer_2000_pdpp[796];

    auto g_yz_0_0_0_z_yz_y_z = buffer_2000_pdpp[797];

    auto g_yz_0_0_0_z_yz_z_x = buffer_2000_pdpp[798];

    auto g_yz_0_0_0_z_yz_z_y = buffer_2000_pdpp[799];

    auto g_yz_0_0_0_z_yz_z_z = buffer_2000_pdpp[800];

    auto g_yz_0_0_0_z_zz_x_x = buffer_2000_pdpp[801];

    auto g_yz_0_0_0_z_zz_x_y = buffer_2000_pdpp[802];

    auto g_yz_0_0_0_z_zz_x_z = buffer_2000_pdpp[803];

    auto g_yz_0_0_0_z_zz_y_x = buffer_2000_pdpp[804];

    auto g_yz_0_0_0_z_zz_y_y = buffer_2000_pdpp[805];

    auto g_yz_0_0_0_z_zz_y_z = buffer_2000_pdpp[806];

    auto g_yz_0_0_0_z_zz_z_x = buffer_2000_pdpp[807];

    auto g_yz_0_0_0_z_zz_z_y = buffer_2000_pdpp[808];

    auto g_yz_0_0_0_z_zz_z_z = buffer_2000_pdpp[809];

    auto g_zz_0_0_0_x_xx_x_x = buffer_2000_pdpp[810];

    auto g_zz_0_0_0_x_xx_x_y = buffer_2000_pdpp[811];

    auto g_zz_0_0_0_x_xx_x_z = buffer_2000_pdpp[812];

    auto g_zz_0_0_0_x_xx_y_x = buffer_2000_pdpp[813];

    auto g_zz_0_0_0_x_xx_y_y = buffer_2000_pdpp[814];

    auto g_zz_0_0_0_x_xx_y_z = buffer_2000_pdpp[815];

    auto g_zz_0_0_0_x_xx_z_x = buffer_2000_pdpp[816];

    auto g_zz_0_0_0_x_xx_z_y = buffer_2000_pdpp[817];

    auto g_zz_0_0_0_x_xx_z_z = buffer_2000_pdpp[818];

    auto g_zz_0_0_0_x_xy_x_x = buffer_2000_pdpp[819];

    auto g_zz_0_0_0_x_xy_x_y = buffer_2000_pdpp[820];

    auto g_zz_0_0_0_x_xy_x_z = buffer_2000_pdpp[821];

    auto g_zz_0_0_0_x_xy_y_x = buffer_2000_pdpp[822];

    auto g_zz_0_0_0_x_xy_y_y = buffer_2000_pdpp[823];

    auto g_zz_0_0_0_x_xy_y_z = buffer_2000_pdpp[824];

    auto g_zz_0_0_0_x_xy_z_x = buffer_2000_pdpp[825];

    auto g_zz_0_0_0_x_xy_z_y = buffer_2000_pdpp[826];

    auto g_zz_0_0_0_x_xy_z_z = buffer_2000_pdpp[827];

    auto g_zz_0_0_0_x_xz_x_x = buffer_2000_pdpp[828];

    auto g_zz_0_0_0_x_xz_x_y = buffer_2000_pdpp[829];

    auto g_zz_0_0_0_x_xz_x_z = buffer_2000_pdpp[830];

    auto g_zz_0_0_0_x_xz_y_x = buffer_2000_pdpp[831];

    auto g_zz_0_0_0_x_xz_y_y = buffer_2000_pdpp[832];

    auto g_zz_0_0_0_x_xz_y_z = buffer_2000_pdpp[833];

    auto g_zz_0_0_0_x_xz_z_x = buffer_2000_pdpp[834];

    auto g_zz_0_0_0_x_xz_z_y = buffer_2000_pdpp[835];

    auto g_zz_0_0_0_x_xz_z_z = buffer_2000_pdpp[836];

    auto g_zz_0_0_0_x_yy_x_x = buffer_2000_pdpp[837];

    auto g_zz_0_0_0_x_yy_x_y = buffer_2000_pdpp[838];

    auto g_zz_0_0_0_x_yy_x_z = buffer_2000_pdpp[839];

    auto g_zz_0_0_0_x_yy_y_x = buffer_2000_pdpp[840];

    auto g_zz_0_0_0_x_yy_y_y = buffer_2000_pdpp[841];

    auto g_zz_0_0_0_x_yy_y_z = buffer_2000_pdpp[842];

    auto g_zz_0_0_0_x_yy_z_x = buffer_2000_pdpp[843];

    auto g_zz_0_0_0_x_yy_z_y = buffer_2000_pdpp[844];

    auto g_zz_0_0_0_x_yy_z_z = buffer_2000_pdpp[845];

    auto g_zz_0_0_0_x_yz_x_x = buffer_2000_pdpp[846];

    auto g_zz_0_0_0_x_yz_x_y = buffer_2000_pdpp[847];

    auto g_zz_0_0_0_x_yz_x_z = buffer_2000_pdpp[848];

    auto g_zz_0_0_0_x_yz_y_x = buffer_2000_pdpp[849];

    auto g_zz_0_0_0_x_yz_y_y = buffer_2000_pdpp[850];

    auto g_zz_0_0_0_x_yz_y_z = buffer_2000_pdpp[851];

    auto g_zz_0_0_0_x_yz_z_x = buffer_2000_pdpp[852];

    auto g_zz_0_0_0_x_yz_z_y = buffer_2000_pdpp[853];

    auto g_zz_0_0_0_x_yz_z_z = buffer_2000_pdpp[854];

    auto g_zz_0_0_0_x_zz_x_x = buffer_2000_pdpp[855];

    auto g_zz_0_0_0_x_zz_x_y = buffer_2000_pdpp[856];

    auto g_zz_0_0_0_x_zz_x_z = buffer_2000_pdpp[857];

    auto g_zz_0_0_0_x_zz_y_x = buffer_2000_pdpp[858];

    auto g_zz_0_0_0_x_zz_y_y = buffer_2000_pdpp[859];

    auto g_zz_0_0_0_x_zz_y_z = buffer_2000_pdpp[860];

    auto g_zz_0_0_0_x_zz_z_x = buffer_2000_pdpp[861];

    auto g_zz_0_0_0_x_zz_z_y = buffer_2000_pdpp[862];

    auto g_zz_0_0_0_x_zz_z_z = buffer_2000_pdpp[863];

    auto g_zz_0_0_0_y_xx_x_x = buffer_2000_pdpp[864];

    auto g_zz_0_0_0_y_xx_x_y = buffer_2000_pdpp[865];

    auto g_zz_0_0_0_y_xx_x_z = buffer_2000_pdpp[866];

    auto g_zz_0_0_0_y_xx_y_x = buffer_2000_pdpp[867];

    auto g_zz_0_0_0_y_xx_y_y = buffer_2000_pdpp[868];

    auto g_zz_0_0_0_y_xx_y_z = buffer_2000_pdpp[869];

    auto g_zz_0_0_0_y_xx_z_x = buffer_2000_pdpp[870];

    auto g_zz_0_0_0_y_xx_z_y = buffer_2000_pdpp[871];

    auto g_zz_0_0_0_y_xx_z_z = buffer_2000_pdpp[872];

    auto g_zz_0_0_0_y_xy_x_x = buffer_2000_pdpp[873];

    auto g_zz_0_0_0_y_xy_x_y = buffer_2000_pdpp[874];

    auto g_zz_0_0_0_y_xy_x_z = buffer_2000_pdpp[875];

    auto g_zz_0_0_0_y_xy_y_x = buffer_2000_pdpp[876];

    auto g_zz_0_0_0_y_xy_y_y = buffer_2000_pdpp[877];

    auto g_zz_0_0_0_y_xy_y_z = buffer_2000_pdpp[878];

    auto g_zz_0_0_0_y_xy_z_x = buffer_2000_pdpp[879];

    auto g_zz_0_0_0_y_xy_z_y = buffer_2000_pdpp[880];

    auto g_zz_0_0_0_y_xy_z_z = buffer_2000_pdpp[881];

    auto g_zz_0_0_0_y_xz_x_x = buffer_2000_pdpp[882];

    auto g_zz_0_0_0_y_xz_x_y = buffer_2000_pdpp[883];

    auto g_zz_0_0_0_y_xz_x_z = buffer_2000_pdpp[884];

    auto g_zz_0_0_0_y_xz_y_x = buffer_2000_pdpp[885];

    auto g_zz_0_0_0_y_xz_y_y = buffer_2000_pdpp[886];

    auto g_zz_0_0_0_y_xz_y_z = buffer_2000_pdpp[887];

    auto g_zz_0_0_0_y_xz_z_x = buffer_2000_pdpp[888];

    auto g_zz_0_0_0_y_xz_z_y = buffer_2000_pdpp[889];

    auto g_zz_0_0_0_y_xz_z_z = buffer_2000_pdpp[890];

    auto g_zz_0_0_0_y_yy_x_x = buffer_2000_pdpp[891];

    auto g_zz_0_0_0_y_yy_x_y = buffer_2000_pdpp[892];

    auto g_zz_0_0_0_y_yy_x_z = buffer_2000_pdpp[893];

    auto g_zz_0_0_0_y_yy_y_x = buffer_2000_pdpp[894];

    auto g_zz_0_0_0_y_yy_y_y = buffer_2000_pdpp[895];

    auto g_zz_0_0_0_y_yy_y_z = buffer_2000_pdpp[896];

    auto g_zz_0_0_0_y_yy_z_x = buffer_2000_pdpp[897];

    auto g_zz_0_0_0_y_yy_z_y = buffer_2000_pdpp[898];

    auto g_zz_0_0_0_y_yy_z_z = buffer_2000_pdpp[899];

    auto g_zz_0_0_0_y_yz_x_x = buffer_2000_pdpp[900];

    auto g_zz_0_0_0_y_yz_x_y = buffer_2000_pdpp[901];

    auto g_zz_0_0_0_y_yz_x_z = buffer_2000_pdpp[902];

    auto g_zz_0_0_0_y_yz_y_x = buffer_2000_pdpp[903];

    auto g_zz_0_0_0_y_yz_y_y = buffer_2000_pdpp[904];

    auto g_zz_0_0_0_y_yz_y_z = buffer_2000_pdpp[905];

    auto g_zz_0_0_0_y_yz_z_x = buffer_2000_pdpp[906];

    auto g_zz_0_0_0_y_yz_z_y = buffer_2000_pdpp[907];

    auto g_zz_0_0_0_y_yz_z_z = buffer_2000_pdpp[908];

    auto g_zz_0_0_0_y_zz_x_x = buffer_2000_pdpp[909];

    auto g_zz_0_0_0_y_zz_x_y = buffer_2000_pdpp[910];

    auto g_zz_0_0_0_y_zz_x_z = buffer_2000_pdpp[911];

    auto g_zz_0_0_0_y_zz_y_x = buffer_2000_pdpp[912];

    auto g_zz_0_0_0_y_zz_y_y = buffer_2000_pdpp[913];

    auto g_zz_0_0_0_y_zz_y_z = buffer_2000_pdpp[914];

    auto g_zz_0_0_0_y_zz_z_x = buffer_2000_pdpp[915];

    auto g_zz_0_0_0_y_zz_z_y = buffer_2000_pdpp[916];

    auto g_zz_0_0_0_y_zz_z_z = buffer_2000_pdpp[917];

    auto g_zz_0_0_0_z_xx_x_x = buffer_2000_pdpp[918];

    auto g_zz_0_0_0_z_xx_x_y = buffer_2000_pdpp[919];

    auto g_zz_0_0_0_z_xx_x_z = buffer_2000_pdpp[920];

    auto g_zz_0_0_0_z_xx_y_x = buffer_2000_pdpp[921];

    auto g_zz_0_0_0_z_xx_y_y = buffer_2000_pdpp[922];

    auto g_zz_0_0_0_z_xx_y_z = buffer_2000_pdpp[923];

    auto g_zz_0_0_0_z_xx_z_x = buffer_2000_pdpp[924];

    auto g_zz_0_0_0_z_xx_z_y = buffer_2000_pdpp[925];

    auto g_zz_0_0_0_z_xx_z_z = buffer_2000_pdpp[926];

    auto g_zz_0_0_0_z_xy_x_x = buffer_2000_pdpp[927];

    auto g_zz_0_0_0_z_xy_x_y = buffer_2000_pdpp[928];

    auto g_zz_0_0_0_z_xy_x_z = buffer_2000_pdpp[929];

    auto g_zz_0_0_0_z_xy_y_x = buffer_2000_pdpp[930];

    auto g_zz_0_0_0_z_xy_y_y = buffer_2000_pdpp[931];

    auto g_zz_0_0_0_z_xy_y_z = buffer_2000_pdpp[932];

    auto g_zz_0_0_0_z_xy_z_x = buffer_2000_pdpp[933];

    auto g_zz_0_0_0_z_xy_z_y = buffer_2000_pdpp[934];

    auto g_zz_0_0_0_z_xy_z_z = buffer_2000_pdpp[935];

    auto g_zz_0_0_0_z_xz_x_x = buffer_2000_pdpp[936];

    auto g_zz_0_0_0_z_xz_x_y = buffer_2000_pdpp[937];

    auto g_zz_0_0_0_z_xz_x_z = buffer_2000_pdpp[938];

    auto g_zz_0_0_0_z_xz_y_x = buffer_2000_pdpp[939];

    auto g_zz_0_0_0_z_xz_y_y = buffer_2000_pdpp[940];

    auto g_zz_0_0_0_z_xz_y_z = buffer_2000_pdpp[941];

    auto g_zz_0_0_0_z_xz_z_x = buffer_2000_pdpp[942];

    auto g_zz_0_0_0_z_xz_z_y = buffer_2000_pdpp[943];

    auto g_zz_0_0_0_z_xz_z_z = buffer_2000_pdpp[944];

    auto g_zz_0_0_0_z_yy_x_x = buffer_2000_pdpp[945];

    auto g_zz_0_0_0_z_yy_x_y = buffer_2000_pdpp[946];

    auto g_zz_0_0_0_z_yy_x_z = buffer_2000_pdpp[947];

    auto g_zz_0_0_0_z_yy_y_x = buffer_2000_pdpp[948];

    auto g_zz_0_0_0_z_yy_y_y = buffer_2000_pdpp[949];

    auto g_zz_0_0_0_z_yy_y_z = buffer_2000_pdpp[950];

    auto g_zz_0_0_0_z_yy_z_x = buffer_2000_pdpp[951];

    auto g_zz_0_0_0_z_yy_z_y = buffer_2000_pdpp[952];

    auto g_zz_0_0_0_z_yy_z_z = buffer_2000_pdpp[953];

    auto g_zz_0_0_0_z_yz_x_x = buffer_2000_pdpp[954];

    auto g_zz_0_0_0_z_yz_x_y = buffer_2000_pdpp[955];

    auto g_zz_0_0_0_z_yz_x_z = buffer_2000_pdpp[956];

    auto g_zz_0_0_0_z_yz_y_x = buffer_2000_pdpp[957];

    auto g_zz_0_0_0_z_yz_y_y = buffer_2000_pdpp[958];

    auto g_zz_0_0_0_z_yz_y_z = buffer_2000_pdpp[959];

    auto g_zz_0_0_0_z_yz_z_x = buffer_2000_pdpp[960];

    auto g_zz_0_0_0_z_yz_z_y = buffer_2000_pdpp[961];

    auto g_zz_0_0_0_z_yz_z_z = buffer_2000_pdpp[962];

    auto g_zz_0_0_0_z_zz_x_x = buffer_2000_pdpp[963];

    auto g_zz_0_0_0_z_zz_x_y = buffer_2000_pdpp[964];

    auto g_zz_0_0_0_z_zz_x_z = buffer_2000_pdpp[965];

    auto g_zz_0_0_0_z_zz_y_x = buffer_2000_pdpp[966];

    auto g_zz_0_0_0_z_zz_y_y = buffer_2000_pdpp[967];

    auto g_zz_0_0_0_z_zz_y_z = buffer_2000_pdpp[968];

    auto g_zz_0_0_0_z_zz_z_x = buffer_2000_pdpp[969];

    auto g_zz_0_0_0_z_zz_z_y = buffer_2000_pdpp[970];

    auto g_zz_0_0_0_z_zz_z_z = buffer_2000_pdpp[971];

    // integrals block (0-3)

    #pragma omp simd aligned(g_x_xx_x_x, g_x_xx_x_y, g_x_xx_x_z, g_xx_0_0_0_x_xx_x_x, g_xx_0_0_0_x_xx_x_y, g_xx_0_0_0_x_xx_x_z, g_xxx_xx_x_x, g_xxx_xx_x_y, g_xxx_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xx_x_x[i] = -6.0 * g_x_xx_x_x[i] * a_exp + 4.0 * g_xxx_xx_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_x_y[i] = -6.0 * g_x_xx_x_y[i] * a_exp + 4.0 * g_xxx_xx_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_x_z[i] = -6.0 * g_x_xx_x_z[i] * a_exp + 4.0 * g_xxx_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (3-6)

    #pragma omp simd aligned(g_x_xx_y_x, g_x_xx_y_y, g_x_xx_y_z, g_xx_0_0_0_x_xx_y_x, g_xx_0_0_0_x_xx_y_y, g_xx_0_0_0_x_xx_y_z, g_xxx_xx_y_x, g_xxx_xx_y_y, g_xxx_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xx_y_x[i] = -6.0 * g_x_xx_y_x[i] * a_exp + 4.0 * g_xxx_xx_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_y_y[i] = -6.0 * g_x_xx_y_y[i] * a_exp + 4.0 * g_xxx_xx_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_y_z[i] = -6.0 * g_x_xx_y_z[i] * a_exp + 4.0 * g_xxx_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (6-9)

    #pragma omp simd aligned(g_x_xx_z_x, g_x_xx_z_y, g_x_xx_z_z, g_xx_0_0_0_x_xx_z_x, g_xx_0_0_0_x_xx_z_y, g_xx_0_0_0_x_xx_z_z, g_xxx_xx_z_x, g_xxx_xx_z_y, g_xxx_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xx_z_x[i] = -6.0 * g_x_xx_z_x[i] * a_exp + 4.0 * g_xxx_xx_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_z_y[i] = -6.0 * g_x_xx_z_y[i] * a_exp + 4.0 * g_xxx_xx_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xx_z_z[i] = -6.0 * g_x_xx_z_z[i] * a_exp + 4.0 * g_xxx_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (9-12)

    #pragma omp simd aligned(g_x_xy_x_x, g_x_xy_x_y, g_x_xy_x_z, g_xx_0_0_0_x_xy_x_x, g_xx_0_0_0_x_xy_x_y, g_xx_0_0_0_x_xy_x_z, g_xxx_xy_x_x, g_xxx_xy_x_y, g_xxx_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xy_x_x[i] = -6.0 * g_x_xy_x_x[i] * a_exp + 4.0 * g_xxx_xy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_x_y[i] = -6.0 * g_x_xy_x_y[i] * a_exp + 4.0 * g_xxx_xy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_x_z[i] = -6.0 * g_x_xy_x_z[i] * a_exp + 4.0 * g_xxx_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (12-15)

    #pragma omp simd aligned(g_x_xy_y_x, g_x_xy_y_y, g_x_xy_y_z, g_xx_0_0_0_x_xy_y_x, g_xx_0_0_0_x_xy_y_y, g_xx_0_0_0_x_xy_y_z, g_xxx_xy_y_x, g_xxx_xy_y_y, g_xxx_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xy_y_x[i] = -6.0 * g_x_xy_y_x[i] * a_exp + 4.0 * g_xxx_xy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_y_y[i] = -6.0 * g_x_xy_y_y[i] * a_exp + 4.0 * g_xxx_xy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_y_z[i] = -6.0 * g_x_xy_y_z[i] * a_exp + 4.0 * g_xxx_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (15-18)

    #pragma omp simd aligned(g_x_xy_z_x, g_x_xy_z_y, g_x_xy_z_z, g_xx_0_0_0_x_xy_z_x, g_xx_0_0_0_x_xy_z_y, g_xx_0_0_0_x_xy_z_z, g_xxx_xy_z_x, g_xxx_xy_z_y, g_xxx_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xy_z_x[i] = -6.0 * g_x_xy_z_x[i] * a_exp + 4.0 * g_xxx_xy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_z_y[i] = -6.0 * g_x_xy_z_y[i] * a_exp + 4.0 * g_xxx_xy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xy_z_z[i] = -6.0 * g_x_xy_z_z[i] * a_exp + 4.0 * g_xxx_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (18-21)

    #pragma omp simd aligned(g_x_xz_x_x, g_x_xz_x_y, g_x_xz_x_z, g_xx_0_0_0_x_xz_x_x, g_xx_0_0_0_x_xz_x_y, g_xx_0_0_0_x_xz_x_z, g_xxx_xz_x_x, g_xxx_xz_x_y, g_xxx_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xz_x_x[i] = -6.0 * g_x_xz_x_x[i] * a_exp + 4.0 * g_xxx_xz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_x_y[i] = -6.0 * g_x_xz_x_y[i] * a_exp + 4.0 * g_xxx_xz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_x_z[i] = -6.0 * g_x_xz_x_z[i] * a_exp + 4.0 * g_xxx_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (21-24)

    #pragma omp simd aligned(g_x_xz_y_x, g_x_xz_y_y, g_x_xz_y_z, g_xx_0_0_0_x_xz_y_x, g_xx_0_0_0_x_xz_y_y, g_xx_0_0_0_x_xz_y_z, g_xxx_xz_y_x, g_xxx_xz_y_y, g_xxx_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xz_y_x[i] = -6.0 * g_x_xz_y_x[i] * a_exp + 4.0 * g_xxx_xz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_y_y[i] = -6.0 * g_x_xz_y_y[i] * a_exp + 4.0 * g_xxx_xz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_y_z[i] = -6.0 * g_x_xz_y_z[i] * a_exp + 4.0 * g_xxx_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (24-27)

    #pragma omp simd aligned(g_x_xz_z_x, g_x_xz_z_y, g_x_xz_z_z, g_xx_0_0_0_x_xz_z_x, g_xx_0_0_0_x_xz_z_y, g_xx_0_0_0_x_xz_z_z, g_xxx_xz_z_x, g_xxx_xz_z_y, g_xxx_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_xz_z_x[i] = -6.0 * g_x_xz_z_x[i] * a_exp + 4.0 * g_xxx_xz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_z_y[i] = -6.0 * g_x_xz_z_y[i] * a_exp + 4.0 * g_xxx_xz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_xz_z_z[i] = -6.0 * g_x_xz_z_z[i] * a_exp + 4.0 * g_xxx_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (27-30)

    #pragma omp simd aligned(g_x_yy_x_x, g_x_yy_x_y, g_x_yy_x_z, g_xx_0_0_0_x_yy_x_x, g_xx_0_0_0_x_yy_x_y, g_xx_0_0_0_x_yy_x_z, g_xxx_yy_x_x, g_xxx_yy_x_y, g_xxx_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yy_x_x[i] = -6.0 * g_x_yy_x_x[i] * a_exp + 4.0 * g_xxx_yy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_x_y[i] = -6.0 * g_x_yy_x_y[i] * a_exp + 4.0 * g_xxx_yy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_x_z[i] = -6.0 * g_x_yy_x_z[i] * a_exp + 4.0 * g_xxx_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (30-33)

    #pragma omp simd aligned(g_x_yy_y_x, g_x_yy_y_y, g_x_yy_y_z, g_xx_0_0_0_x_yy_y_x, g_xx_0_0_0_x_yy_y_y, g_xx_0_0_0_x_yy_y_z, g_xxx_yy_y_x, g_xxx_yy_y_y, g_xxx_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yy_y_x[i] = -6.0 * g_x_yy_y_x[i] * a_exp + 4.0 * g_xxx_yy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_y_y[i] = -6.0 * g_x_yy_y_y[i] * a_exp + 4.0 * g_xxx_yy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_y_z[i] = -6.0 * g_x_yy_y_z[i] * a_exp + 4.0 * g_xxx_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (33-36)

    #pragma omp simd aligned(g_x_yy_z_x, g_x_yy_z_y, g_x_yy_z_z, g_xx_0_0_0_x_yy_z_x, g_xx_0_0_0_x_yy_z_y, g_xx_0_0_0_x_yy_z_z, g_xxx_yy_z_x, g_xxx_yy_z_y, g_xxx_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yy_z_x[i] = -6.0 * g_x_yy_z_x[i] * a_exp + 4.0 * g_xxx_yy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_z_y[i] = -6.0 * g_x_yy_z_y[i] * a_exp + 4.0 * g_xxx_yy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yy_z_z[i] = -6.0 * g_x_yy_z_z[i] * a_exp + 4.0 * g_xxx_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (36-39)

    #pragma omp simd aligned(g_x_yz_x_x, g_x_yz_x_y, g_x_yz_x_z, g_xx_0_0_0_x_yz_x_x, g_xx_0_0_0_x_yz_x_y, g_xx_0_0_0_x_yz_x_z, g_xxx_yz_x_x, g_xxx_yz_x_y, g_xxx_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yz_x_x[i] = -6.0 * g_x_yz_x_x[i] * a_exp + 4.0 * g_xxx_yz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_x_y[i] = -6.0 * g_x_yz_x_y[i] * a_exp + 4.0 * g_xxx_yz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_x_z[i] = -6.0 * g_x_yz_x_z[i] * a_exp + 4.0 * g_xxx_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (39-42)

    #pragma omp simd aligned(g_x_yz_y_x, g_x_yz_y_y, g_x_yz_y_z, g_xx_0_0_0_x_yz_y_x, g_xx_0_0_0_x_yz_y_y, g_xx_0_0_0_x_yz_y_z, g_xxx_yz_y_x, g_xxx_yz_y_y, g_xxx_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yz_y_x[i] = -6.0 * g_x_yz_y_x[i] * a_exp + 4.0 * g_xxx_yz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_y_y[i] = -6.0 * g_x_yz_y_y[i] * a_exp + 4.0 * g_xxx_yz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_y_z[i] = -6.0 * g_x_yz_y_z[i] * a_exp + 4.0 * g_xxx_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (42-45)

    #pragma omp simd aligned(g_x_yz_z_x, g_x_yz_z_y, g_x_yz_z_z, g_xx_0_0_0_x_yz_z_x, g_xx_0_0_0_x_yz_z_y, g_xx_0_0_0_x_yz_z_z, g_xxx_yz_z_x, g_xxx_yz_z_y, g_xxx_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_yz_z_x[i] = -6.0 * g_x_yz_z_x[i] * a_exp + 4.0 * g_xxx_yz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_z_y[i] = -6.0 * g_x_yz_z_y[i] * a_exp + 4.0 * g_xxx_yz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_yz_z_z[i] = -6.0 * g_x_yz_z_z[i] * a_exp + 4.0 * g_xxx_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (45-48)

    #pragma omp simd aligned(g_x_zz_x_x, g_x_zz_x_y, g_x_zz_x_z, g_xx_0_0_0_x_zz_x_x, g_xx_0_0_0_x_zz_x_y, g_xx_0_0_0_x_zz_x_z, g_xxx_zz_x_x, g_xxx_zz_x_y, g_xxx_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_zz_x_x[i] = -6.0 * g_x_zz_x_x[i] * a_exp + 4.0 * g_xxx_zz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_x_y[i] = -6.0 * g_x_zz_x_y[i] * a_exp + 4.0 * g_xxx_zz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_x_z[i] = -6.0 * g_x_zz_x_z[i] * a_exp + 4.0 * g_xxx_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (48-51)

    #pragma omp simd aligned(g_x_zz_y_x, g_x_zz_y_y, g_x_zz_y_z, g_xx_0_0_0_x_zz_y_x, g_xx_0_0_0_x_zz_y_y, g_xx_0_0_0_x_zz_y_z, g_xxx_zz_y_x, g_xxx_zz_y_y, g_xxx_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_zz_y_x[i] = -6.0 * g_x_zz_y_x[i] * a_exp + 4.0 * g_xxx_zz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_y_y[i] = -6.0 * g_x_zz_y_y[i] * a_exp + 4.0 * g_xxx_zz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_y_z[i] = -6.0 * g_x_zz_y_z[i] * a_exp + 4.0 * g_xxx_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (51-54)

    #pragma omp simd aligned(g_x_zz_z_x, g_x_zz_z_y, g_x_zz_z_z, g_xx_0_0_0_x_zz_z_x, g_xx_0_0_0_x_zz_z_y, g_xx_0_0_0_x_zz_z_z, g_xxx_zz_z_x, g_xxx_zz_z_y, g_xxx_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_x_zz_z_x[i] = -6.0 * g_x_zz_z_x[i] * a_exp + 4.0 * g_xxx_zz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_z_y[i] = -6.0 * g_x_zz_z_y[i] * a_exp + 4.0 * g_xxx_zz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_x_zz_z_z[i] = -6.0 * g_x_zz_z_z[i] * a_exp + 4.0 * g_xxx_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (54-57)

    #pragma omp simd aligned(g_xx_0_0_0_y_xx_x_x, g_xx_0_0_0_y_xx_x_y, g_xx_0_0_0_y_xx_x_z, g_xxy_xx_x_x, g_xxy_xx_x_y, g_xxy_xx_x_z, g_y_xx_x_x, g_y_xx_x_y, g_y_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xx_x_x[i] = -2.0 * g_y_xx_x_x[i] * a_exp + 4.0 * g_xxy_xx_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_x_y[i] = -2.0 * g_y_xx_x_y[i] * a_exp + 4.0 * g_xxy_xx_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_x_z[i] = -2.0 * g_y_xx_x_z[i] * a_exp + 4.0 * g_xxy_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (57-60)

    #pragma omp simd aligned(g_xx_0_0_0_y_xx_y_x, g_xx_0_0_0_y_xx_y_y, g_xx_0_0_0_y_xx_y_z, g_xxy_xx_y_x, g_xxy_xx_y_y, g_xxy_xx_y_z, g_y_xx_y_x, g_y_xx_y_y, g_y_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xx_y_x[i] = -2.0 * g_y_xx_y_x[i] * a_exp + 4.0 * g_xxy_xx_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_y_y[i] = -2.0 * g_y_xx_y_y[i] * a_exp + 4.0 * g_xxy_xx_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_y_z[i] = -2.0 * g_y_xx_y_z[i] * a_exp + 4.0 * g_xxy_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (60-63)

    #pragma omp simd aligned(g_xx_0_0_0_y_xx_z_x, g_xx_0_0_0_y_xx_z_y, g_xx_0_0_0_y_xx_z_z, g_xxy_xx_z_x, g_xxy_xx_z_y, g_xxy_xx_z_z, g_y_xx_z_x, g_y_xx_z_y, g_y_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xx_z_x[i] = -2.0 * g_y_xx_z_x[i] * a_exp + 4.0 * g_xxy_xx_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_z_y[i] = -2.0 * g_y_xx_z_y[i] * a_exp + 4.0 * g_xxy_xx_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xx_z_z[i] = -2.0 * g_y_xx_z_z[i] * a_exp + 4.0 * g_xxy_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (63-66)

    #pragma omp simd aligned(g_xx_0_0_0_y_xy_x_x, g_xx_0_0_0_y_xy_x_y, g_xx_0_0_0_y_xy_x_z, g_xxy_xy_x_x, g_xxy_xy_x_y, g_xxy_xy_x_z, g_y_xy_x_x, g_y_xy_x_y, g_y_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xy_x_x[i] = -2.0 * g_y_xy_x_x[i] * a_exp + 4.0 * g_xxy_xy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_x_y[i] = -2.0 * g_y_xy_x_y[i] * a_exp + 4.0 * g_xxy_xy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_x_z[i] = -2.0 * g_y_xy_x_z[i] * a_exp + 4.0 * g_xxy_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (66-69)

    #pragma omp simd aligned(g_xx_0_0_0_y_xy_y_x, g_xx_0_0_0_y_xy_y_y, g_xx_0_0_0_y_xy_y_z, g_xxy_xy_y_x, g_xxy_xy_y_y, g_xxy_xy_y_z, g_y_xy_y_x, g_y_xy_y_y, g_y_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xy_y_x[i] = -2.0 * g_y_xy_y_x[i] * a_exp + 4.0 * g_xxy_xy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_y_y[i] = -2.0 * g_y_xy_y_y[i] * a_exp + 4.0 * g_xxy_xy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_y_z[i] = -2.0 * g_y_xy_y_z[i] * a_exp + 4.0 * g_xxy_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (69-72)

    #pragma omp simd aligned(g_xx_0_0_0_y_xy_z_x, g_xx_0_0_0_y_xy_z_y, g_xx_0_0_0_y_xy_z_z, g_xxy_xy_z_x, g_xxy_xy_z_y, g_xxy_xy_z_z, g_y_xy_z_x, g_y_xy_z_y, g_y_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xy_z_x[i] = -2.0 * g_y_xy_z_x[i] * a_exp + 4.0 * g_xxy_xy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_z_y[i] = -2.0 * g_y_xy_z_y[i] * a_exp + 4.0 * g_xxy_xy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xy_z_z[i] = -2.0 * g_y_xy_z_z[i] * a_exp + 4.0 * g_xxy_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (72-75)

    #pragma omp simd aligned(g_xx_0_0_0_y_xz_x_x, g_xx_0_0_0_y_xz_x_y, g_xx_0_0_0_y_xz_x_z, g_xxy_xz_x_x, g_xxy_xz_x_y, g_xxy_xz_x_z, g_y_xz_x_x, g_y_xz_x_y, g_y_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xz_x_x[i] = -2.0 * g_y_xz_x_x[i] * a_exp + 4.0 * g_xxy_xz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_x_y[i] = -2.0 * g_y_xz_x_y[i] * a_exp + 4.0 * g_xxy_xz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_x_z[i] = -2.0 * g_y_xz_x_z[i] * a_exp + 4.0 * g_xxy_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (75-78)

    #pragma omp simd aligned(g_xx_0_0_0_y_xz_y_x, g_xx_0_0_0_y_xz_y_y, g_xx_0_0_0_y_xz_y_z, g_xxy_xz_y_x, g_xxy_xz_y_y, g_xxy_xz_y_z, g_y_xz_y_x, g_y_xz_y_y, g_y_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xz_y_x[i] = -2.0 * g_y_xz_y_x[i] * a_exp + 4.0 * g_xxy_xz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_y_y[i] = -2.0 * g_y_xz_y_y[i] * a_exp + 4.0 * g_xxy_xz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_y_z[i] = -2.0 * g_y_xz_y_z[i] * a_exp + 4.0 * g_xxy_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (78-81)

    #pragma omp simd aligned(g_xx_0_0_0_y_xz_z_x, g_xx_0_0_0_y_xz_z_y, g_xx_0_0_0_y_xz_z_z, g_xxy_xz_z_x, g_xxy_xz_z_y, g_xxy_xz_z_z, g_y_xz_z_x, g_y_xz_z_y, g_y_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_xz_z_x[i] = -2.0 * g_y_xz_z_x[i] * a_exp + 4.0 * g_xxy_xz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_z_y[i] = -2.0 * g_y_xz_z_y[i] * a_exp + 4.0 * g_xxy_xz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_xz_z_z[i] = -2.0 * g_y_xz_z_z[i] * a_exp + 4.0 * g_xxy_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (81-84)

    #pragma omp simd aligned(g_xx_0_0_0_y_yy_x_x, g_xx_0_0_0_y_yy_x_y, g_xx_0_0_0_y_yy_x_z, g_xxy_yy_x_x, g_xxy_yy_x_y, g_xxy_yy_x_z, g_y_yy_x_x, g_y_yy_x_y, g_y_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yy_x_x[i] = -2.0 * g_y_yy_x_x[i] * a_exp + 4.0 * g_xxy_yy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_x_y[i] = -2.0 * g_y_yy_x_y[i] * a_exp + 4.0 * g_xxy_yy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_x_z[i] = -2.0 * g_y_yy_x_z[i] * a_exp + 4.0 * g_xxy_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (84-87)

    #pragma omp simd aligned(g_xx_0_0_0_y_yy_y_x, g_xx_0_0_0_y_yy_y_y, g_xx_0_0_0_y_yy_y_z, g_xxy_yy_y_x, g_xxy_yy_y_y, g_xxy_yy_y_z, g_y_yy_y_x, g_y_yy_y_y, g_y_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yy_y_x[i] = -2.0 * g_y_yy_y_x[i] * a_exp + 4.0 * g_xxy_yy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_y_y[i] = -2.0 * g_y_yy_y_y[i] * a_exp + 4.0 * g_xxy_yy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_y_z[i] = -2.0 * g_y_yy_y_z[i] * a_exp + 4.0 * g_xxy_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (87-90)

    #pragma omp simd aligned(g_xx_0_0_0_y_yy_z_x, g_xx_0_0_0_y_yy_z_y, g_xx_0_0_0_y_yy_z_z, g_xxy_yy_z_x, g_xxy_yy_z_y, g_xxy_yy_z_z, g_y_yy_z_x, g_y_yy_z_y, g_y_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yy_z_x[i] = -2.0 * g_y_yy_z_x[i] * a_exp + 4.0 * g_xxy_yy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_z_y[i] = -2.0 * g_y_yy_z_y[i] * a_exp + 4.0 * g_xxy_yy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yy_z_z[i] = -2.0 * g_y_yy_z_z[i] * a_exp + 4.0 * g_xxy_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (90-93)

    #pragma omp simd aligned(g_xx_0_0_0_y_yz_x_x, g_xx_0_0_0_y_yz_x_y, g_xx_0_0_0_y_yz_x_z, g_xxy_yz_x_x, g_xxy_yz_x_y, g_xxy_yz_x_z, g_y_yz_x_x, g_y_yz_x_y, g_y_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yz_x_x[i] = -2.0 * g_y_yz_x_x[i] * a_exp + 4.0 * g_xxy_yz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_x_y[i] = -2.0 * g_y_yz_x_y[i] * a_exp + 4.0 * g_xxy_yz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_x_z[i] = -2.0 * g_y_yz_x_z[i] * a_exp + 4.0 * g_xxy_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (93-96)

    #pragma omp simd aligned(g_xx_0_0_0_y_yz_y_x, g_xx_0_0_0_y_yz_y_y, g_xx_0_0_0_y_yz_y_z, g_xxy_yz_y_x, g_xxy_yz_y_y, g_xxy_yz_y_z, g_y_yz_y_x, g_y_yz_y_y, g_y_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yz_y_x[i] = -2.0 * g_y_yz_y_x[i] * a_exp + 4.0 * g_xxy_yz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_y_y[i] = -2.0 * g_y_yz_y_y[i] * a_exp + 4.0 * g_xxy_yz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_y_z[i] = -2.0 * g_y_yz_y_z[i] * a_exp + 4.0 * g_xxy_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (96-99)

    #pragma omp simd aligned(g_xx_0_0_0_y_yz_z_x, g_xx_0_0_0_y_yz_z_y, g_xx_0_0_0_y_yz_z_z, g_xxy_yz_z_x, g_xxy_yz_z_y, g_xxy_yz_z_z, g_y_yz_z_x, g_y_yz_z_y, g_y_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_yz_z_x[i] = -2.0 * g_y_yz_z_x[i] * a_exp + 4.0 * g_xxy_yz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_z_y[i] = -2.0 * g_y_yz_z_y[i] * a_exp + 4.0 * g_xxy_yz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_yz_z_z[i] = -2.0 * g_y_yz_z_z[i] * a_exp + 4.0 * g_xxy_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (99-102)

    #pragma omp simd aligned(g_xx_0_0_0_y_zz_x_x, g_xx_0_0_0_y_zz_x_y, g_xx_0_0_0_y_zz_x_z, g_xxy_zz_x_x, g_xxy_zz_x_y, g_xxy_zz_x_z, g_y_zz_x_x, g_y_zz_x_y, g_y_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_zz_x_x[i] = -2.0 * g_y_zz_x_x[i] * a_exp + 4.0 * g_xxy_zz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_x_y[i] = -2.0 * g_y_zz_x_y[i] * a_exp + 4.0 * g_xxy_zz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_x_z[i] = -2.0 * g_y_zz_x_z[i] * a_exp + 4.0 * g_xxy_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (102-105)

    #pragma omp simd aligned(g_xx_0_0_0_y_zz_y_x, g_xx_0_0_0_y_zz_y_y, g_xx_0_0_0_y_zz_y_z, g_xxy_zz_y_x, g_xxy_zz_y_y, g_xxy_zz_y_z, g_y_zz_y_x, g_y_zz_y_y, g_y_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_zz_y_x[i] = -2.0 * g_y_zz_y_x[i] * a_exp + 4.0 * g_xxy_zz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_y_y[i] = -2.0 * g_y_zz_y_y[i] * a_exp + 4.0 * g_xxy_zz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_y_z[i] = -2.0 * g_y_zz_y_z[i] * a_exp + 4.0 * g_xxy_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (105-108)

    #pragma omp simd aligned(g_xx_0_0_0_y_zz_z_x, g_xx_0_0_0_y_zz_z_y, g_xx_0_0_0_y_zz_z_z, g_xxy_zz_z_x, g_xxy_zz_z_y, g_xxy_zz_z_z, g_y_zz_z_x, g_y_zz_z_y, g_y_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_y_zz_z_x[i] = -2.0 * g_y_zz_z_x[i] * a_exp + 4.0 * g_xxy_zz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_z_y[i] = -2.0 * g_y_zz_z_y[i] * a_exp + 4.0 * g_xxy_zz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_y_zz_z_z[i] = -2.0 * g_y_zz_z_z[i] * a_exp + 4.0 * g_xxy_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (108-111)

    #pragma omp simd aligned(g_xx_0_0_0_z_xx_x_x, g_xx_0_0_0_z_xx_x_y, g_xx_0_0_0_z_xx_x_z, g_xxz_xx_x_x, g_xxz_xx_x_y, g_xxz_xx_x_z, g_z_xx_x_x, g_z_xx_x_y, g_z_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xx_x_x[i] = -2.0 * g_z_xx_x_x[i] * a_exp + 4.0 * g_xxz_xx_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_x_y[i] = -2.0 * g_z_xx_x_y[i] * a_exp + 4.0 * g_xxz_xx_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_x_z[i] = -2.0 * g_z_xx_x_z[i] * a_exp + 4.0 * g_xxz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (111-114)

    #pragma omp simd aligned(g_xx_0_0_0_z_xx_y_x, g_xx_0_0_0_z_xx_y_y, g_xx_0_0_0_z_xx_y_z, g_xxz_xx_y_x, g_xxz_xx_y_y, g_xxz_xx_y_z, g_z_xx_y_x, g_z_xx_y_y, g_z_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xx_y_x[i] = -2.0 * g_z_xx_y_x[i] * a_exp + 4.0 * g_xxz_xx_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_y_y[i] = -2.0 * g_z_xx_y_y[i] * a_exp + 4.0 * g_xxz_xx_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_y_z[i] = -2.0 * g_z_xx_y_z[i] * a_exp + 4.0 * g_xxz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (114-117)

    #pragma omp simd aligned(g_xx_0_0_0_z_xx_z_x, g_xx_0_0_0_z_xx_z_y, g_xx_0_0_0_z_xx_z_z, g_xxz_xx_z_x, g_xxz_xx_z_y, g_xxz_xx_z_z, g_z_xx_z_x, g_z_xx_z_y, g_z_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xx_z_x[i] = -2.0 * g_z_xx_z_x[i] * a_exp + 4.0 * g_xxz_xx_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_z_y[i] = -2.0 * g_z_xx_z_y[i] * a_exp + 4.0 * g_xxz_xx_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xx_z_z[i] = -2.0 * g_z_xx_z_z[i] * a_exp + 4.0 * g_xxz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (117-120)

    #pragma omp simd aligned(g_xx_0_0_0_z_xy_x_x, g_xx_0_0_0_z_xy_x_y, g_xx_0_0_0_z_xy_x_z, g_xxz_xy_x_x, g_xxz_xy_x_y, g_xxz_xy_x_z, g_z_xy_x_x, g_z_xy_x_y, g_z_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xy_x_x[i] = -2.0 * g_z_xy_x_x[i] * a_exp + 4.0 * g_xxz_xy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_x_y[i] = -2.0 * g_z_xy_x_y[i] * a_exp + 4.0 * g_xxz_xy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_x_z[i] = -2.0 * g_z_xy_x_z[i] * a_exp + 4.0 * g_xxz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (120-123)

    #pragma omp simd aligned(g_xx_0_0_0_z_xy_y_x, g_xx_0_0_0_z_xy_y_y, g_xx_0_0_0_z_xy_y_z, g_xxz_xy_y_x, g_xxz_xy_y_y, g_xxz_xy_y_z, g_z_xy_y_x, g_z_xy_y_y, g_z_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xy_y_x[i] = -2.0 * g_z_xy_y_x[i] * a_exp + 4.0 * g_xxz_xy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_y_y[i] = -2.0 * g_z_xy_y_y[i] * a_exp + 4.0 * g_xxz_xy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_y_z[i] = -2.0 * g_z_xy_y_z[i] * a_exp + 4.0 * g_xxz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (123-126)

    #pragma omp simd aligned(g_xx_0_0_0_z_xy_z_x, g_xx_0_0_0_z_xy_z_y, g_xx_0_0_0_z_xy_z_z, g_xxz_xy_z_x, g_xxz_xy_z_y, g_xxz_xy_z_z, g_z_xy_z_x, g_z_xy_z_y, g_z_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xy_z_x[i] = -2.0 * g_z_xy_z_x[i] * a_exp + 4.0 * g_xxz_xy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_z_y[i] = -2.0 * g_z_xy_z_y[i] * a_exp + 4.0 * g_xxz_xy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xy_z_z[i] = -2.0 * g_z_xy_z_z[i] * a_exp + 4.0 * g_xxz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (126-129)

    #pragma omp simd aligned(g_xx_0_0_0_z_xz_x_x, g_xx_0_0_0_z_xz_x_y, g_xx_0_0_0_z_xz_x_z, g_xxz_xz_x_x, g_xxz_xz_x_y, g_xxz_xz_x_z, g_z_xz_x_x, g_z_xz_x_y, g_z_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xz_x_x[i] = -2.0 * g_z_xz_x_x[i] * a_exp + 4.0 * g_xxz_xz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_x_y[i] = -2.0 * g_z_xz_x_y[i] * a_exp + 4.0 * g_xxz_xz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_x_z[i] = -2.0 * g_z_xz_x_z[i] * a_exp + 4.0 * g_xxz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (129-132)

    #pragma omp simd aligned(g_xx_0_0_0_z_xz_y_x, g_xx_0_0_0_z_xz_y_y, g_xx_0_0_0_z_xz_y_z, g_xxz_xz_y_x, g_xxz_xz_y_y, g_xxz_xz_y_z, g_z_xz_y_x, g_z_xz_y_y, g_z_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xz_y_x[i] = -2.0 * g_z_xz_y_x[i] * a_exp + 4.0 * g_xxz_xz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_y_y[i] = -2.0 * g_z_xz_y_y[i] * a_exp + 4.0 * g_xxz_xz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_y_z[i] = -2.0 * g_z_xz_y_z[i] * a_exp + 4.0 * g_xxz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (132-135)

    #pragma omp simd aligned(g_xx_0_0_0_z_xz_z_x, g_xx_0_0_0_z_xz_z_y, g_xx_0_0_0_z_xz_z_z, g_xxz_xz_z_x, g_xxz_xz_z_y, g_xxz_xz_z_z, g_z_xz_z_x, g_z_xz_z_y, g_z_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_xz_z_x[i] = -2.0 * g_z_xz_z_x[i] * a_exp + 4.0 * g_xxz_xz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_z_y[i] = -2.0 * g_z_xz_z_y[i] * a_exp + 4.0 * g_xxz_xz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_xz_z_z[i] = -2.0 * g_z_xz_z_z[i] * a_exp + 4.0 * g_xxz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (135-138)

    #pragma omp simd aligned(g_xx_0_0_0_z_yy_x_x, g_xx_0_0_0_z_yy_x_y, g_xx_0_0_0_z_yy_x_z, g_xxz_yy_x_x, g_xxz_yy_x_y, g_xxz_yy_x_z, g_z_yy_x_x, g_z_yy_x_y, g_z_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yy_x_x[i] = -2.0 * g_z_yy_x_x[i] * a_exp + 4.0 * g_xxz_yy_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_x_y[i] = -2.0 * g_z_yy_x_y[i] * a_exp + 4.0 * g_xxz_yy_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_x_z[i] = -2.0 * g_z_yy_x_z[i] * a_exp + 4.0 * g_xxz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (138-141)

    #pragma omp simd aligned(g_xx_0_0_0_z_yy_y_x, g_xx_0_0_0_z_yy_y_y, g_xx_0_0_0_z_yy_y_z, g_xxz_yy_y_x, g_xxz_yy_y_y, g_xxz_yy_y_z, g_z_yy_y_x, g_z_yy_y_y, g_z_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yy_y_x[i] = -2.0 * g_z_yy_y_x[i] * a_exp + 4.0 * g_xxz_yy_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_y_y[i] = -2.0 * g_z_yy_y_y[i] * a_exp + 4.0 * g_xxz_yy_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_y_z[i] = -2.0 * g_z_yy_y_z[i] * a_exp + 4.0 * g_xxz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (141-144)

    #pragma omp simd aligned(g_xx_0_0_0_z_yy_z_x, g_xx_0_0_0_z_yy_z_y, g_xx_0_0_0_z_yy_z_z, g_xxz_yy_z_x, g_xxz_yy_z_y, g_xxz_yy_z_z, g_z_yy_z_x, g_z_yy_z_y, g_z_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yy_z_x[i] = -2.0 * g_z_yy_z_x[i] * a_exp + 4.0 * g_xxz_yy_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_z_y[i] = -2.0 * g_z_yy_z_y[i] * a_exp + 4.0 * g_xxz_yy_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yy_z_z[i] = -2.0 * g_z_yy_z_z[i] * a_exp + 4.0 * g_xxz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (144-147)

    #pragma omp simd aligned(g_xx_0_0_0_z_yz_x_x, g_xx_0_0_0_z_yz_x_y, g_xx_0_0_0_z_yz_x_z, g_xxz_yz_x_x, g_xxz_yz_x_y, g_xxz_yz_x_z, g_z_yz_x_x, g_z_yz_x_y, g_z_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yz_x_x[i] = -2.0 * g_z_yz_x_x[i] * a_exp + 4.0 * g_xxz_yz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_x_y[i] = -2.0 * g_z_yz_x_y[i] * a_exp + 4.0 * g_xxz_yz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_x_z[i] = -2.0 * g_z_yz_x_z[i] * a_exp + 4.0 * g_xxz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (147-150)

    #pragma omp simd aligned(g_xx_0_0_0_z_yz_y_x, g_xx_0_0_0_z_yz_y_y, g_xx_0_0_0_z_yz_y_z, g_xxz_yz_y_x, g_xxz_yz_y_y, g_xxz_yz_y_z, g_z_yz_y_x, g_z_yz_y_y, g_z_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yz_y_x[i] = -2.0 * g_z_yz_y_x[i] * a_exp + 4.0 * g_xxz_yz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_y_y[i] = -2.0 * g_z_yz_y_y[i] * a_exp + 4.0 * g_xxz_yz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_y_z[i] = -2.0 * g_z_yz_y_z[i] * a_exp + 4.0 * g_xxz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (150-153)

    #pragma omp simd aligned(g_xx_0_0_0_z_yz_z_x, g_xx_0_0_0_z_yz_z_y, g_xx_0_0_0_z_yz_z_z, g_xxz_yz_z_x, g_xxz_yz_z_y, g_xxz_yz_z_z, g_z_yz_z_x, g_z_yz_z_y, g_z_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_yz_z_x[i] = -2.0 * g_z_yz_z_x[i] * a_exp + 4.0 * g_xxz_yz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_z_y[i] = -2.0 * g_z_yz_z_y[i] * a_exp + 4.0 * g_xxz_yz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_yz_z_z[i] = -2.0 * g_z_yz_z_z[i] * a_exp + 4.0 * g_xxz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (153-156)

    #pragma omp simd aligned(g_xx_0_0_0_z_zz_x_x, g_xx_0_0_0_z_zz_x_y, g_xx_0_0_0_z_zz_x_z, g_xxz_zz_x_x, g_xxz_zz_x_y, g_xxz_zz_x_z, g_z_zz_x_x, g_z_zz_x_y, g_z_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_zz_x_x[i] = -2.0 * g_z_zz_x_x[i] * a_exp + 4.0 * g_xxz_zz_x_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_x_y[i] = -2.0 * g_z_zz_x_y[i] * a_exp + 4.0 * g_xxz_zz_x_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_x_z[i] = -2.0 * g_z_zz_x_z[i] * a_exp + 4.0 * g_xxz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (156-159)

    #pragma omp simd aligned(g_xx_0_0_0_z_zz_y_x, g_xx_0_0_0_z_zz_y_y, g_xx_0_0_0_z_zz_y_z, g_xxz_zz_y_x, g_xxz_zz_y_y, g_xxz_zz_y_z, g_z_zz_y_x, g_z_zz_y_y, g_z_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_zz_y_x[i] = -2.0 * g_z_zz_y_x[i] * a_exp + 4.0 * g_xxz_zz_y_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_y_y[i] = -2.0 * g_z_zz_y_y[i] * a_exp + 4.0 * g_xxz_zz_y_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_y_z[i] = -2.0 * g_z_zz_y_z[i] * a_exp + 4.0 * g_xxz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (159-162)

    #pragma omp simd aligned(g_xx_0_0_0_z_zz_z_x, g_xx_0_0_0_z_zz_z_y, g_xx_0_0_0_z_zz_z_z, g_xxz_zz_z_x, g_xxz_zz_z_y, g_xxz_zz_z_z, g_z_zz_z_x, g_z_zz_z_y, g_z_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_z_zz_z_x[i] = -2.0 * g_z_zz_z_x[i] * a_exp + 4.0 * g_xxz_zz_z_x[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_z_y[i] = -2.0 * g_z_zz_z_y[i] * a_exp + 4.0 * g_xxz_zz_z_y[i] * a_exp * a_exp;

        g_xx_0_0_0_z_zz_z_z[i] = -2.0 * g_z_zz_z_z[i] * a_exp + 4.0 * g_xxz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (162-165)

    #pragma omp simd aligned(g_xxy_xx_x_x, g_xxy_xx_x_y, g_xxy_xx_x_z, g_xy_0_0_0_x_xx_x_x, g_xy_0_0_0_x_xx_x_y, g_xy_0_0_0_x_xx_x_z, g_y_xx_x_x, g_y_xx_x_y, g_y_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xx_x_x[i] = -2.0 * g_y_xx_x_x[i] * a_exp + 4.0 * g_xxy_xx_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_x_y[i] = -2.0 * g_y_xx_x_y[i] * a_exp + 4.0 * g_xxy_xx_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_x_z[i] = -2.0 * g_y_xx_x_z[i] * a_exp + 4.0 * g_xxy_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (165-168)

    #pragma omp simd aligned(g_xxy_xx_y_x, g_xxy_xx_y_y, g_xxy_xx_y_z, g_xy_0_0_0_x_xx_y_x, g_xy_0_0_0_x_xx_y_y, g_xy_0_0_0_x_xx_y_z, g_y_xx_y_x, g_y_xx_y_y, g_y_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xx_y_x[i] = -2.0 * g_y_xx_y_x[i] * a_exp + 4.0 * g_xxy_xx_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_y_y[i] = -2.0 * g_y_xx_y_y[i] * a_exp + 4.0 * g_xxy_xx_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_y_z[i] = -2.0 * g_y_xx_y_z[i] * a_exp + 4.0 * g_xxy_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (168-171)

    #pragma omp simd aligned(g_xxy_xx_z_x, g_xxy_xx_z_y, g_xxy_xx_z_z, g_xy_0_0_0_x_xx_z_x, g_xy_0_0_0_x_xx_z_y, g_xy_0_0_0_x_xx_z_z, g_y_xx_z_x, g_y_xx_z_y, g_y_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xx_z_x[i] = -2.0 * g_y_xx_z_x[i] * a_exp + 4.0 * g_xxy_xx_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_z_y[i] = -2.0 * g_y_xx_z_y[i] * a_exp + 4.0 * g_xxy_xx_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xx_z_z[i] = -2.0 * g_y_xx_z_z[i] * a_exp + 4.0 * g_xxy_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (171-174)

    #pragma omp simd aligned(g_xxy_xy_x_x, g_xxy_xy_x_y, g_xxy_xy_x_z, g_xy_0_0_0_x_xy_x_x, g_xy_0_0_0_x_xy_x_y, g_xy_0_0_0_x_xy_x_z, g_y_xy_x_x, g_y_xy_x_y, g_y_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xy_x_x[i] = -2.0 * g_y_xy_x_x[i] * a_exp + 4.0 * g_xxy_xy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_x_y[i] = -2.0 * g_y_xy_x_y[i] * a_exp + 4.0 * g_xxy_xy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_x_z[i] = -2.0 * g_y_xy_x_z[i] * a_exp + 4.0 * g_xxy_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (174-177)

    #pragma omp simd aligned(g_xxy_xy_y_x, g_xxy_xy_y_y, g_xxy_xy_y_z, g_xy_0_0_0_x_xy_y_x, g_xy_0_0_0_x_xy_y_y, g_xy_0_0_0_x_xy_y_z, g_y_xy_y_x, g_y_xy_y_y, g_y_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xy_y_x[i] = -2.0 * g_y_xy_y_x[i] * a_exp + 4.0 * g_xxy_xy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_y_y[i] = -2.0 * g_y_xy_y_y[i] * a_exp + 4.0 * g_xxy_xy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_y_z[i] = -2.0 * g_y_xy_y_z[i] * a_exp + 4.0 * g_xxy_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (177-180)

    #pragma omp simd aligned(g_xxy_xy_z_x, g_xxy_xy_z_y, g_xxy_xy_z_z, g_xy_0_0_0_x_xy_z_x, g_xy_0_0_0_x_xy_z_y, g_xy_0_0_0_x_xy_z_z, g_y_xy_z_x, g_y_xy_z_y, g_y_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xy_z_x[i] = -2.0 * g_y_xy_z_x[i] * a_exp + 4.0 * g_xxy_xy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_z_y[i] = -2.0 * g_y_xy_z_y[i] * a_exp + 4.0 * g_xxy_xy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xy_z_z[i] = -2.0 * g_y_xy_z_z[i] * a_exp + 4.0 * g_xxy_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (180-183)

    #pragma omp simd aligned(g_xxy_xz_x_x, g_xxy_xz_x_y, g_xxy_xz_x_z, g_xy_0_0_0_x_xz_x_x, g_xy_0_0_0_x_xz_x_y, g_xy_0_0_0_x_xz_x_z, g_y_xz_x_x, g_y_xz_x_y, g_y_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xz_x_x[i] = -2.0 * g_y_xz_x_x[i] * a_exp + 4.0 * g_xxy_xz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_x_y[i] = -2.0 * g_y_xz_x_y[i] * a_exp + 4.0 * g_xxy_xz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_x_z[i] = -2.0 * g_y_xz_x_z[i] * a_exp + 4.0 * g_xxy_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (183-186)

    #pragma omp simd aligned(g_xxy_xz_y_x, g_xxy_xz_y_y, g_xxy_xz_y_z, g_xy_0_0_0_x_xz_y_x, g_xy_0_0_0_x_xz_y_y, g_xy_0_0_0_x_xz_y_z, g_y_xz_y_x, g_y_xz_y_y, g_y_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xz_y_x[i] = -2.0 * g_y_xz_y_x[i] * a_exp + 4.0 * g_xxy_xz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_y_y[i] = -2.0 * g_y_xz_y_y[i] * a_exp + 4.0 * g_xxy_xz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_y_z[i] = -2.0 * g_y_xz_y_z[i] * a_exp + 4.0 * g_xxy_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (186-189)

    #pragma omp simd aligned(g_xxy_xz_z_x, g_xxy_xz_z_y, g_xxy_xz_z_z, g_xy_0_0_0_x_xz_z_x, g_xy_0_0_0_x_xz_z_y, g_xy_0_0_0_x_xz_z_z, g_y_xz_z_x, g_y_xz_z_y, g_y_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_xz_z_x[i] = -2.0 * g_y_xz_z_x[i] * a_exp + 4.0 * g_xxy_xz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_z_y[i] = -2.0 * g_y_xz_z_y[i] * a_exp + 4.0 * g_xxy_xz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_xz_z_z[i] = -2.0 * g_y_xz_z_z[i] * a_exp + 4.0 * g_xxy_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (189-192)

    #pragma omp simd aligned(g_xxy_yy_x_x, g_xxy_yy_x_y, g_xxy_yy_x_z, g_xy_0_0_0_x_yy_x_x, g_xy_0_0_0_x_yy_x_y, g_xy_0_0_0_x_yy_x_z, g_y_yy_x_x, g_y_yy_x_y, g_y_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yy_x_x[i] = -2.0 * g_y_yy_x_x[i] * a_exp + 4.0 * g_xxy_yy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_x_y[i] = -2.0 * g_y_yy_x_y[i] * a_exp + 4.0 * g_xxy_yy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_x_z[i] = -2.0 * g_y_yy_x_z[i] * a_exp + 4.0 * g_xxy_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (192-195)

    #pragma omp simd aligned(g_xxy_yy_y_x, g_xxy_yy_y_y, g_xxy_yy_y_z, g_xy_0_0_0_x_yy_y_x, g_xy_0_0_0_x_yy_y_y, g_xy_0_0_0_x_yy_y_z, g_y_yy_y_x, g_y_yy_y_y, g_y_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yy_y_x[i] = -2.0 * g_y_yy_y_x[i] * a_exp + 4.0 * g_xxy_yy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_y_y[i] = -2.0 * g_y_yy_y_y[i] * a_exp + 4.0 * g_xxy_yy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_y_z[i] = -2.0 * g_y_yy_y_z[i] * a_exp + 4.0 * g_xxy_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (195-198)

    #pragma omp simd aligned(g_xxy_yy_z_x, g_xxy_yy_z_y, g_xxy_yy_z_z, g_xy_0_0_0_x_yy_z_x, g_xy_0_0_0_x_yy_z_y, g_xy_0_0_0_x_yy_z_z, g_y_yy_z_x, g_y_yy_z_y, g_y_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yy_z_x[i] = -2.0 * g_y_yy_z_x[i] * a_exp + 4.0 * g_xxy_yy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_z_y[i] = -2.0 * g_y_yy_z_y[i] * a_exp + 4.0 * g_xxy_yy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yy_z_z[i] = -2.0 * g_y_yy_z_z[i] * a_exp + 4.0 * g_xxy_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (198-201)

    #pragma omp simd aligned(g_xxy_yz_x_x, g_xxy_yz_x_y, g_xxy_yz_x_z, g_xy_0_0_0_x_yz_x_x, g_xy_0_0_0_x_yz_x_y, g_xy_0_0_0_x_yz_x_z, g_y_yz_x_x, g_y_yz_x_y, g_y_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yz_x_x[i] = -2.0 * g_y_yz_x_x[i] * a_exp + 4.0 * g_xxy_yz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_x_y[i] = -2.0 * g_y_yz_x_y[i] * a_exp + 4.0 * g_xxy_yz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_x_z[i] = -2.0 * g_y_yz_x_z[i] * a_exp + 4.0 * g_xxy_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (201-204)

    #pragma omp simd aligned(g_xxy_yz_y_x, g_xxy_yz_y_y, g_xxy_yz_y_z, g_xy_0_0_0_x_yz_y_x, g_xy_0_0_0_x_yz_y_y, g_xy_0_0_0_x_yz_y_z, g_y_yz_y_x, g_y_yz_y_y, g_y_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yz_y_x[i] = -2.0 * g_y_yz_y_x[i] * a_exp + 4.0 * g_xxy_yz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_y_y[i] = -2.0 * g_y_yz_y_y[i] * a_exp + 4.0 * g_xxy_yz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_y_z[i] = -2.0 * g_y_yz_y_z[i] * a_exp + 4.0 * g_xxy_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (204-207)

    #pragma omp simd aligned(g_xxy_yz_z_x, g_xxy_yz_z_y, g_xxy_yz_z_z, g_xy_0_0_0_x_yz_z_x, g_xy_0_0_0_x_yz_z_y, g_xy_0_0_0_x_yz_z_z, g_y_yz_z_x, g_y_yz_z_y, g_y_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_yz_z_x[i] = -2.0 * g_y_yz_z_x[i] * a_exp + 4.0 * g_xxy_yz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_z_y[i] = -2.0 * g_y_yz_z_y[i] * a_exp + 4.0 * g_xxy_yz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_yz_z_z[i] = -2.0 * g_y_yz_z_z[i] * a_exp + 4.0 * g_xxy_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (207-210)

    #pragma omp simd aligned(g_xxy_zz_x_x, g_xxy_zz_x_y, g_xxy_zz_x_z, g_xy_0_0_0_x_zz_x_x, g_xy_0_0_0_x_zz_x_y, g_xy_0_0_0_x_zz_x_z, g_y_zz_x_x, g_y_zz_x_y, g_y_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_zz_x_x[i] = -2.0 * g_y_zz_x_x[i] * a_exp + 4.0 * g_xxy_zz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_x_y[i] = -2.0 * g_y_zz_x_y[i] * a_exp + 4.0 * g_xxy_zz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_x_z[i] = -2.0 * g_y_zz_x_z[i] * a_exp + 4.0 * g_xxy_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (210-213)

    #pragma omp simd aligned(g_xxy_zz_y_x, g_xxy_zz_y_y, g_xxy_zz_y_z, g_xy_0_0_0_x_zz_y_x, g_xy_0_0_0_x_zz_y_y, g_xy_0_0_0_x_zz_y_z, g_y_zz_y_x, g_y_zz_y_y, g_y_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_zz_y_x[i] = -2.0 * g_y_zz_y_x[i] * a_exp + 4.0 * g_xxy_zz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_y_y[i] = -2.0 * g_y_zz_y_y[i] * a_exp + 4.0 * g_xxy_zz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_y_z[i] = -2.0 * g_y_zz_y_z[i] * a_exp + 4.0 * g_xxy_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (213-216)

    #pragma omp simd aligned(g_xxy_zz_z_x, g_xxy_zz_z_y, g_xxy_zz_z_z, g_xy_0_0_0_x_zz_z_x, g_xy_0_0_0_x_zz_z_y, g_xy_0_0_0_x_zz_z_z, g_y_zz_z_x, g_y_zz_z_y, g_y_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_x_zz_z_x[i] = -2.0 * g_y_zz_z_x[i] * a_exp + 4.0 * g_xxy_zz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_z_y[i] = -2.0 * g_y_zz_z_y[i] * a_exp + 4.0 * g_xxy_zz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_x_zz_z_z[i] = -2.0 * g_y_zz_z_z[i] * a_exp + 4.0 * g_xxy_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (216-219)

    #pragma omp simd aligned(g_x_xx_x_x, g_x_xx_x_y, g_x_xx_x_z, g_xy_0_0_0_y_xx_x_x, g_xy_0_0_0_y_xx_x_y, g_xy_0_0_0_y_xx_x_z, g_xyy_xx_x_x, g_xyy_xx_x_y, g_xyy_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xx_x_x[i] = -2.0 * g_x_xx_x_x[i] * a_exp + 4.0 * g_xyy_xx_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_x_y[i] = -2.0 * g_x_xx_x_y[i] * a_exp + 4.0 * g_xyy_xx_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_x_z[i] = -2.0 * g_x_xx_x_z[i] * a_exp + 4.0 * g_xyy_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (219-222)

    #pragma omp simd aligned(g_x_xx_y_x, g_x_xx_y_y, g_x_xx_y_z, g_xy_0_0_0_y_xx_y_x, g_xy_0_0_0_y_xx_y_y, g_xy_0_0_0_y_xx_y_z, g_xyy_xx_y_x, g_xyy_xx_y_y, g_xyy_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xx_y_x[i] = -2.0 * g_x_xx_y_x[i] * a_exp + 4.0 * g_xyy_xx_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_y_y[i] = -2.0 * g_x_xx_y_y[i] * a_exp + 4.0 * g_xyy_xx_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_y_z[i] = -2.0 * g_x_xx_y_z[i] * a_exp + 4.0 * g_xyy_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (222-225)

    #pragma omp simd aligned(g_x_xx_z_x, g_x_xx_z_y, g_x_xx_z_z, g_xy_0_0_0_y_xx_z_x, g_xy_0_0_0_y_xx_z_y, g_xy_0_0_0_y_xx_z_z, g_xyy_xx_z_x, g_xyy_xx_z_y, g_xyy_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xx_z_x[i] = -2.0 * g_x_xx_z_x[i] * a_exp + 4.0 * g_xyy_xx_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_z_y[i] = -2.0 * g_x_xx_z_y[i] * a_exp + 4.0 * g_xyy_xx_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xx_z_z[i] = -2.0 * g_x_xx_z_z[i] * a_exp + 4.0 * g_xyy_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (225-228)

    #pragma omp simd aligned(g_x_xy_x_x, g_x_xy_x_y, g_x_xy_x_z, g_xy_0_0_0_y_xy_x_x, g_xy_0_0_0_y_xy_x_y, g_xy_0_0_0_y_xy_x_z, g_xyy_xy_x_x, g_xyy_xy_x_y, g_xyy_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xy_x_x[i] = -2.0 * g_x_xy_x_x[i] * a_exp + 4.0 * g_xyy_xy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_x_y[i] = -2.0 * g_x_xy_x_y[i] * a_exp + 4.0 * g_xyy_xy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_x_z[i] = -2.0 * g_x_xy_x_z[i] * a_exp + 4.0 * g_xyy_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (228-231)

    #pragma omp simd aligned(g_x_xy_y_x, g_x_xy_y_y, g_x_xy_y_z, g_xy_0_0_0_y_xy_y_x, g_xy_0_0_0_y_xy_y_y, g_xy_0_0_0_y_xy_y_z, g_xyy_xy_y_x, g_xyy_xy_y_y, g_xyy_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xy_y_x[i] = -2.0 * g_x_xy_y_x[i] * a_exp + 4.0 * g_xyy_xy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_y_y[i] = -2.0 * g_x_xy_y_y[i] * a_exp + 4.0 * g_xyy_xy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_y_z[i] = -2.0 * g_x_xy_y_z[i] * a_exp + 4.0 * g_xyy_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (231-234)

    #pragma omp simd aligned(g_x_xy_z_x, g_x_xy_z_y, g_x_xy_z_z, g_xy_0_0_0_y_xy_z_x, g_xy_0_0_0_y_xy_z_y, g_xy_0_0_0_y_xy_z_z, g_xyy_xy_z_x, g_xyy_xy_z_y, g_xyy_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xy_z_x[i] = -2.0 * g_x_xy_z_x[i] * a_exp + 4.0 * g_xyy_xy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_z_y[i] = -2.0 * g_x_xy_z_y[i] * a_exp + 4.0 * g_xyy_xy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xy_z_z[i] = -2.0 * g_x_xy_z_z[i] * a_exp + 4.0 * g_xyy_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (234-237)

    #pragma omp simd aligned(g_x_xz_x_x, g_x_xz_x_y, g_x_xz_x_z, g_xy_0_0_0_y_xz_x_x, g_xy_0_0_0_y_xz_x_y, g_xy_0_0_0_y_xz_x_z, g_xyy_xz_x_x, g_xyy_xz_x_y, g_xyy_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xz_x_x[i] = -2.0 * g_x_xz_x_x[i] * a_exp + 4.0 * g_xyy_xz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_x_y[i] = -2.0 * g_x_xz_x_y[i] * a_exp + 4.0 * g_xyy_xz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_x_z[i] = -2.0 * g_x_xz_x_z[i] * a_exp + 4.0 * g_xyy_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (237-240)

    #pragma omp simd aligned(g_x_xz_y_x, g_x_xz_y_y, g_x_xz_y_z, g_xy_0_0_0_y_xz_y_x, g_xy_0_0_0_y_xz_y_y, g_xy_0_0_0_y_xz_y_z, g_xyy_xz_y_x, g_xyy_xz_y_y, g_xyy_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xz_y_x[i] = -2.0 * g_x_xz_y_x[i] * a_exp + 4.0 * g_xyy_xz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_y_y[i] = -2.0 * g_x_xz_y_y[i] * a_exp + 4.0 * g_xyy_xz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_y_z[i] = -2.0 * g_x_xz_y_z[i] * a_exp + 4.0 * g_xyy_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (240-243)

    #pragma omp simd aligned(g_x_xz_z_x, g_x_xz_z_y, g_x_xz_z_z, g_xy_0_0_0_y_xz_z_x, g_xy_0_0_0_y_xz_z_y, g_xy_0_0_0_y_xz_z_z, g_xyy_xz_z_x, g_xyy_xz_z_y, g_xyy_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_xz_z_x[i] = -2.0 * g_x_xz_z_x[i] * a_exp + 4.0 * g_xyy_xz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_z_y[i] = -2.0 * g_x_xz_z_y[i] * a_exp + 4.0 * g_xyy_xz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_xz_z_z[i] = -2.0 * g_x_xz_z_z[i] * a_exp + 4.0 * g_xyy_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (243-246)

    #pragma omp simd aligned(g_x_yy_x_x, g_x_yy_x_y, g_x_yy_x_z, g_xy_0_0_0_y_yy_x_x, g_xy_0_0_0_y_yy_x_y, g_xy_0_0_0_y_yy_x_z, g_xyy_yy_x_x, g_xyy_yy_x_y, g_xyy_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yy_x_x[i] = -2.0 * g_x_yy_x_x[i] * a_exp + 4.0 * g_xyy_yy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_x_y[i] = -2.0 * g_x_yy_x_y[i] * a_exp + 4.0 * g_xyy_yy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_x_z[i] = -2.0 * g_x_yy_x_z[i] * a_exp + 4.0 * g_xyy_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (246-249)

    #pragma omp simd aligned(g_x_yy_y_x, g_x_yy_y_y, g_x_yy_y_z, g_xy_0_0_0_y_yy_y_x, g_xy_0_0_0_y_yy_y_y, g_xy_0_0_0_y_yy_y_z, g_xyy_yy_y_x, g_xyy_yy_y_y, g_xyy_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yy_y_x[i] = -2.0 * g_x_yy_y_x[i] * a_exp + 4.0 * g_xyy_yy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_y_y[i] = -2.0 * g_x_yy_y_y[i] * a_exp + 4.0 * g_xyy_yy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_y_z[i] = -2.0 * g_x_yy_y_z[i] * a_exp + 4.0 * g_xyy_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (249-252)

    #pragma omp simd aligned(g_x_yy_z_x, g_x_yy_z_y, g_x_yy_z_z, g_xy_0_0_0_y_yy_z_x, g_xy_0_0_0_y_yy_z_y, g_xy_0_0_0_y_yy_z_z, g_xyy_yy_z_x, g_xyy_yy_z_y, g_xyy_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yy_z_x[i] = -2.0 * g_x_yy_z_x[i] * a_exp + 4.0 * g_xyy_yy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_z_y[i] = -2.0 * g_x_yy_z_y[i] * a_exp + 4.0 * g_xyy_yy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yy_z_z[i] = -2.0 * g_x_yy_z_z[i] * a_exp + 4.0 * g_xyy_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (252-255)

    #pragma omp simd aligned(g_x_yz_x_x, g_x_yz_x_y, g_x_yz_x_z, g_xy_0_0_0_y_yz_x_x, g_xy_0_0_0_y_yz_x_y, g_xy_0_0_0_y_yz_x_z, g_xyy_yz_x_x, g_xyy_yz_x_y, g_xyy_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yz_x_x[i] = -2.0 * g_x_yz_x_x[i] * a_exp + 4.0 * g_xyy_yz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_x_y[i] = -2.0 * g_x_yz_x_y[i] * a_exp + 4.0 * g_xyy_yz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_x_z[i] = -2.0 * g_x_yz_x_z[i] * a_exp + 4.0 * g_xyy_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (255-258)

    #pragma omp simd aligned(g_x_yz_y_x, g_x_yz_y_y, g_x_yz_y_z, g_xy_0_0_0_y_yz_y_x, g_xy_0_0_0_y_yz_y_y, g_xy_0_0_0_y_yz_y_z, g_xyy_yz_y_x, g_xyy_yz_y_y, g_xyy_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yz_y_x[i] = -2.0 * g_x_yz_y_x[i] * a_exp + 4.0 * g_xyy_yz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_y_y[i] = -2.0 * g_x_yz_y_y[i] * a_exp + 4.0 * g_xyy_yz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_y_z[i] = -2.0 * g_x_yz_y_z[i] * a_exp + 4.0 * g_xyy_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (258-261)

    #pragma omp simd aligned(g_x_yz_z_x, g_x_yz_z_y, g_x_yz_z_z, g_xy_0_0_0_y_yz_z_x, g_xy_0_0_0_y_yz_z_y, g_xy_0_0_0_y_yz_z_z, g_xyy_yz_z_x, g_xyy_yz_z_y, g_xyy_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_yz_z_x[i] = -2.0 * g_x_yz_z_x[i] * a_exp + 4.0 * g_xyy_yz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_z_y[i] = -2.0 * g_x_yz_z_y[i] * a_exp + 4.0 * g_xyy_yz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_yz_z_z[i] = -2.0 * g_x_yz_z_z[i] * a_exp + 4.0 * g_xyy_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (261-264)

    #pragma omp simd aligned(g_x_zz_x_x, g_x_zz_x_y, g_x_zz_x_z, g_xy_0_0_0_y_zz_x_x, g_xy_0_0_0_y_zz_x_y, g_xy_0_0_0_y_zz_x_z, g_xyy_zz_x_x, g_xyy_zz_x_y, g_xyy_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_zz_x_x[i] = -2.0 * g_x_zz_x_x[i] * a_exp + 4.0 * g_xyy_zz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_x_y[i] = -2.0 * g_x_zz_x_y[i] * a_exp + 4.0 * g_xyy_zz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_x_z[i] = -2.0 * g_x_zz_x_z[i] * a_exp + 4.0 * g_xyy_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (264-267)

    #pragma omp simd aligned(g_x_zz_y_x, g_x_zz_y_y, g_x_zz_y_z, g_xy_0_0_0_y_zz_y_x, g_xy_0_0_0_y_zz_y_y, g_xy_0_0_0_y_zz_y_z, g_xyy_zz_y_x, g_xyy_zz_y_y, g_xyy_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_zz_y_x[i] = -2.0 * g_x_zz_y_x[i] * a_exp + 4.0 * g_xyy_zz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_y_y[i] = -2.0 * g_x_zz_y_y[i] * a_exp + 4.0 * g_xyy_zz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_y_z[i] = -2.0 * g_x_zz_y_z[i] * a_exp + 4.0 * g_xyy_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (267-270)

    #pragma omp simd aligned(g_x_zz_z_x, g_x_zz_z_y, g_x_zz_z_z, g_xy_0_0_0_y_zz_z_x, g_xy_0_0_0_y_zz_z_y, g_xy_0_0_0_y_zz_z_z, g_xyy_zz_z_x, g_xyy_zz_z_y, g_xyy_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_y_zz_z_x[i] = -2.0 * g_x_zz_z_x[i] * a_exp + 4.0 * g_xyy_zz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_z_y[i] = -2.0 * g_x_zz_z_y[i] * a_exp + 4.0 * g_xyy_zz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_y_zz_z_z[i] = -2.0 * g_x_zz_z_z[i] * a_exp + 4.0 * g_xyy_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (270-273)

    #pragma omp simd aligned(g_xy_0_0_0_z_xx_x_x, g_xy_0_0_0_z_xx_x_y, g_xy_0_0_0_z_xx_x_z, g_xyz_xx_x_x, g_xyz_xx_x_y, g_xyz_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xx_x_x[i] = 4.0 * g_xyz_xx_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_x_y[i] = 4.0 * g_xyz_xx_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_x_z[i] = 4.0 * g_xyz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (273-276)

    #pragma omp simd aligned(g_xy_0_0_0_z_xx_y_x, g_xy_0_0_0_z_xx_y_y, g_xy_0_0_0_z_xx_y_z, g_xyz_xx_y_x, g_xyz_xx_y_y, g_xyz_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xx_y_x[i] = 4.0 * g_xyz_xx_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_y_y[i] = 4.0 * g_xyz_xx_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_y_z[i] = 4.0 * g_xyz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (276-279)

    #pragma omp simd aligned(g_xy_0_0_0_z_xx_z_x, g_xy_0_0_0_z_xx_z_y, g_xy_0_0_0_z_xx_z_z, g_xyz_xx_z_x, g_xyz_xx_z_y, g_xyz_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xx_z_x[i] = 4.0 * g_xyz_xx_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_z_y[i] = 4.0 * g_xyz_xx_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xx_z_z[i] = 4.0 * g_xyz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (279-282)

    #pragma omp simd aligned(g_xy_0_0_0_z_xy_x_x, g_xy_0_0_0_z_xy_x_y, g_xy_0_0_0_z_xy_x_z, g_xyz_xy_x_x, g_xyz_xy_x_y, g_xyz_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xy_x_x[i] = 4.0 * g_xyz_xy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_x_y[i] = 4.0 * g_xyz_xy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_x_z[i] = 4.0 * g_xyz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (282-285)

    #pragma omp simd aligned(g_xy_0_0_0_z_xy_y_x, g_xy_0_0_0_z_xy_y_y, g_xy_0_0_0_z_xy_y_z, g_xyz_xy_y_x, g_xyz_xy_y_y, g_xyz_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xy_y_x[i] = 4.0 * g_xyz_xy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_y_y[i] = 4.0 * g_xyz_xy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_y_z[i] = 4.0 * g_xyz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (285-288)

    #pragma omp simd aligned(g_xy_0_0_0_z_xy_z_x, g_xy_0_0_0_z_xy_z_y, g_xy_0_0_0_z_xy_z_z, g_xyz_xy_z_x, g_xyz_xy_z_y, g_xyz_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xy_z_x[i] = 4.0 * g_xyz_xy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_z_y[i] = 4.0 * g_xyz_xy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xy_z_z[i] = 4.0 * g_xyz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (288-291)

    #pragma omp simd aligned(g_xy_0_0_0_z_xz_x_x, g_xy_0_0_0_z_xz_x_y, g_xy_0_0_0_z_xz_x_z, g_xyz_xz_x_x, g_xyz_xz_x_y, g_xyz_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xz_x_x[i] = 4.0 * g_xyz_xz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_x_y[i] = 4.0 * g_xyz_xz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_x_z[i] = 4.0 * g_xyz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (291-294)

    #pragma omp simd aligned(g_xy_0_0_0_z_xz_y_x, g_xy_0_0_0_z_xz_y_y, g_xy_0_0_0_z_xz_y_z, g_xyz_xz_y_x, g_xyz_xz_y_y, g_xyz_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xz_y_x[i] = 4.0 * g_xyz_xz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_y_y[i] = 4.0 * g_xyz_xz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_y_z[i] = 4.0 * g_xyz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (294-297)

    #pragma omp simd aligned(g_xy_0_0_0_z_xz_z_x, g_xy_0_0_0_z_xz_z_y, g_xy_0_0_0_z_xz_z_z, g_xyz_xz_z_x, g_xyz_xz_z_y, g_xyz_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_xz_z_x[i] = 4.0 * g_xyz_xz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_z_y[i] = 4.0 * g_xyz_xz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_xz_z_z[i] = 4.0 * g_xyz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (297-300)

    #pragma omp simd aligned(g_xy_0_0_0_z_yy_x_x, g_xy_0_0_0_z_yy_x_y, g_xy_0_0_0_z_yy_x_z, g_xyz_yy_x_x, g_xyz_yy_x_y, g_xyz_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yy_x_x[i] = 4.0 * g_xyz_yy_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_x_y[i] = 4.0 * g_xyz_yy_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_x_z[i] = 4.0 * g_xyz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (300-303)

    #pragma omp simd aligned(g_xy_0_0_0_z_yy_y_x, g_xy_0_0_0_z_yy_y_y, g_xy_0_0_0_z_yy_y_z, g_xyz_yy_y_x, g_xyz_yy_y_y, g_xyz_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yy_y_x[i] = 4.0 * g_xyz_yy_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_y_y[i] = 4.0 * g_xyz_yy_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_y_z[i] = 4.0 * g_xyz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (303-306)

    #pragma omp simd aligned(g_xy_0_0_0_z_yy_z_x, g_xy_0_0_0_z_yy_z_y, g_xy_0_0_0_z_yy_z_z, g_xyz_yy_z_x, g_xyz_yy_z_y, g_xyz_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yy_z_x[i] = 4.0 * g_xyz_yy_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_z_y[i] = 4.0 * g_xyz_yy_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yy_z_z[i] = 4.0 * g_xyz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (306-309)

    #pragma omp simd aligned(g_xy_0_0_0_z_yz_x_x, g_xy_0_0_0_z_yz_x_y, g_xy_0_0_0_z_yz_x_z, g_xyz_yz_x_x, g_xyz_yz_x_y, g_xyz_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yz_x_x[i] = 4.0 * g_xyz_yz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_x_y[i] = 4.0 * g_xyz_yz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_x_z[i] = 4.0 * g_xyz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (309-312)

    #pragma omp simd aligned(g_xy_0_0_0_z_yz_y_x, g_xy_0_0_0_z_yz_y_y, g_xy_0_0_0_z_yz_y_z, g_xyz_yz_y_x, g_xyz_yz_y_y, g_xyz_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yz_y_x[i] = 4.0 * g_xyz_yz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_y_y[i] = 4.0 * g_xyz_yz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_y_z[i] = 4.0 * g_xyz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (312-315)

    #pragma omp simd aligned(g_xy_0_0_0_z_yz_z_x, g_xy_0_0_0_z_yz_z_y, g_xy_0_0_0_z_yz_z_z, g_xyz_yz_z_x, g_xyz_yz_z_y, g_xyz_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_yz_z_x[i] = 4.0 * g_xyz_yz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_z_y[i] = 4.0 * g_xyz_yz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_yz_z_z[i] = 4.0 * g_xyz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (315-318)

    #pragma omp simd aligned(g_xy_0_0_0_z_zz_x_x, g_xy_0_0_0_z_zz_x_y, g_xy_0_0_0_z_zz_x_z, g_xyz_zz_x_x, g_xyz_zz_x_y, g_xyz_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_zz_x_x[i] = 4.0 * g_xyz_zz_x_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_x_y[i] = 4.0 * g_xyz_zz_x_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_x_z[i] = 4.0 * g_xyz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (318-321)

    #pragma omp simd aligned(g_xy_0_0_0_z_zz_y_x, g_xy_0_0_0_z_zz_y_y, g_xy_0_0_0_z_zz_y_z, g_xyz_zz_y_x, g_xyz_zz_y_y, g_xyz_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_zz_y_x[i] = 4.0 * g_xyz_zz_y_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_y_y[i] = 4.0 * g_xyz_zz_y_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_y_z[i] = 4.0 * g_xyz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (321-324)

    #pragma omp simd aligned(g_xy_0_0_0_z_zz_z_x, g_xy_0_0_0_z_zz_z_y, g_xy_0_0_0_z_zz_z_z, g_xyz_zz_z_x, g_xyz_zz_z_y, g_xyz_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_z_zz_z_x[i] = 4.0 * g_xyz_zz_z_x[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_z_y[i] = 4.0 * g_xyz_zz_z_y[i] * a_exp * a_exp;

        g_xy_0_0_0_z_zz_z_z[i] = 4.0 * g_xyz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (324-327)

    #pragma omp simd aligned(g_xxz_xx_x_x, g_xxz_xx_x_y, g_xxz_xx_x_z, g_xz_0_0_0_x_xx_x_x, g_xz_0_0_0_x_xx_x_y, g_xz_0_0_0_x_xx_x_z, g_z_xx_x_x, g_z_xx_x_y, g_z_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xx_x_x[i] = -2.0 * g_z_xx_x_x[i] * a_exp + 4.0 * g_xxz_xx_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_x_y[i] = -2.0 * g_z_xx_x_y[i] * a_exp + 4.0 * g_xxz_xx_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_x_z[i] = -2.0 * g_z_xx_x_z[i] * a_exp + 4.0 * g_xxz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (327-330)

    #pragma omp simd aligned(g_xxz_xx_y_x, g_xxz_xx_y_y, g_xxz_xx_y_z, g_xz_0_0_0_x_xx_y_x, g_xz_0_0_0_x_xx_y_y, g_xz_0_0_0_x_xx_y_z, g_z_xx_y_x, g_z_xx_y_y, g_z_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xx_y_x[i] = -2.0 * g_z_xx_y_x[i] * a_exp + 4.0 * g_xxz_xx_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_y_y[i] = -2.0 * g_z_xx_y_y[i] * a_exp + 4.0 * g_xxz_xx_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_y_z[i] = -2.0 * g_z_xx_y_z[i] * a_exp + 4.0 * g_xxz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (330-333)

    #pragma omp simd aligned(g_xxz_xx_z_x, g_xxz_xx_z_y, g_xxz_xx_z_z, g_xz_0_0_0_x_xx_z_x, g_xz_0_0_0_x_xx_z_y, g_xz_0_0_0_x_xx_z_z, g_z_xx_z_x, g_z_xx_z_y, g_z_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xx_z_x[i] = -2.0 * g_z_xx_z_x[i] * a_exp + 4.0 * g_xxz_xx_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_z_y[i] = -2.0 * g_z_xx_z_y[i] * a_exp + 4.0 * g_xxz_xx_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xx_z_z[i] = -2.0 * g_z_xx_z_z[i] * a_exp + 4.0 * g_xxz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (333-336)

    #pragma omp simd aligned(g_xxz_xy_x_x, g_xxz_xy_x_y, g_xxz_xy_x_z, g_xz_0_0_0_x_xy_x_x, g_xz_0_0_0_x_xy_x_y, g_xz_0_0_0_x_xy_x_z, g_z_xy_x_x, g_z_xy_x_y, g_z_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xy_x_x[i] = -2.0 * g_z_xy_x_x[i] * a_exp + 4.0 * g_xxz_xy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_x_y[i] = -2.0 * g_z_xy_x_y[i] * a_exp + 4.0 * g_xxz_xy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_x_z[i] = -2.0 * g_z_xy_x_z[i] * a_exp + 4.0 * g_xxz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (336-339)

    #pragma omp simd aligned(g_xxz_xy_y_x, g_xxz_xy_y_y, g_xxz_xy_y_z, g_xz_0_0_0_x_xy_y_x, g_xz_0_0_0_x_xy_y_y, g_xz_0_0_0_x_xy_y_z, g_z_xy_y_x, g_z_xy_y_y, g_z_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xy_y_x[i] = -2.0 * g_z_xy_y_x[i] * a_exp + 4.0 * g_xxz_xy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_y_y[i] = -2.0 * g_z_xy_y_y[i] * a_exp + 4.0 * g_xxz_xy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_y_z[i] = -2.0 * g_z_xy_y_z[i] * a_exp + 4.0 * g_xxz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (339-342)

    #pragma omp simd aligned(g_xxz_xy_z_x, g_xxz_xy_z_y, g_xxz_xy_z_z, g_xz_0_0_0_x_xy_z_x, g_xz_0_0_0_x_xy_z_y, g_xz_0_0_0_x_xy_z_z, g_z_xy_z_x, g_z_xy_z_y, g_z_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xy_z_x[i] = -2.0 * g_z_xy_z_x[i] * a_exp + 4.0 * g_xxz_xy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_z_y[i] = -2.0 * g_z_xy_z_y[i] * a_exp + 4.0 * g_xxz_xy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xy_z_z[i] = -2.0 * g_z_xy_z_z[i] * a_exp + 4.0 * g_xxz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (342-345)

    #pragma omp simd aligned(g_xxz_xz_x_x, g_xxz_xz_x_y, g_xxz_xz_x_z, g_xz_0_0_0_x_xz_x_x, g_xz_0_0_0_x_xz_x_y, g_xz_0_0_0_x_xz_x_z, g_z_xz_x_x, g_z_xz_x_y, g_z_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xz_x_x[i] = -2.0 * g_z_xz_x_x[i] * a_exp + 4.0 * g_xxz_xz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_x_y[i] = -2.0 * g_z_xz_x_y[i] * a_exp + 4.0 * g_xxz_xz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_x_z[i] = -2.0 * g_z_xz_x_z[i] * a_exp + 4.0 * g_xxz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (345-348)

    #pragma omp simd aligned(g_xxz_xz_y_x, g_xxz_xz_y_y, g_xxz_xz_y_z, g_xz_0_0_0_x_xz_y_x, g_xz_0_0_0_x_xz_y_y, g_xz_0_0_0_x_xz_y_z, g_z_xz_y_x, g_z_xz_y_y, g_z_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xz_y_x[i] = -2.0 * g_z_xz_y_x[i] * a_exp + 4.0 * g_xxz_xz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_y_y[i] = -2.0 * g_z_xz_y_y[i] * a_exp + 4.0 * g_xxz_xz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_y_z[i] = -2.0 * g_z_xz_y_z[i] * a_exp + 4.0 * g_xxz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (348-351)

    #pragma omp simd aligned(g_xxz_xz_z_x, g_xxz_xz_z_y, g_xxz_xz_z_z, g_xz_0_0_0_x_xz_z_x, g_xz_0_0_0_x_xz_z_y, g_xz_0_0_0_x_xz_z_z, g_z_xz_z_x, g_z_xz_z_y, g_z_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_xz_z_x[i] = -2.0 * g_z_xz_z_x[i] * a_exp + 4.0 * g_xxz_xz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_z_y[i] = -2.0 * g_z_xz_z_y[i] * a_exp + 4.0 * g_xxz_xz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_xz_z_z[i] = -2.0 * g_z_xz_z_z[i] * a_exp + 4.0 * g_xxz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (351-354)

    #pragma omp simd aligned(g_xxz_yy_x_x, g_xxz_yy_x_y, g_xxz_yy_x_z, g_xz_0_0_0_x_yy_x_x, g_xz_0_0_0_x_yy_x_y, g_xz_0_0_0_x_yy_x_z, g_z_yy_x_x, g_z_yy_x_y, g_z_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yy_x_x[i] = -2.0 * g_z_yy_x_x[i] * a_exp + 4.0 * g_xxz_yy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_x_y[i] = -2.0 * g_z_yy_x_y[i] * a_exp + 4.0 * g_xxz_yy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_x_z[i] = -2.0 * g_z_yy_x_z[i] * a_exp + 4.0 * g_xxz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (354-357)

    #pragma omp simd aligned(g_xxz_yy_y_x, g_xxz_yy_y_y, g_xxz_yy_y_z, g_xz_0_0_0_x_yy_y_x, g_xz_0_0_0_x_yy_y_y, g_xz_0_0_0_x_yy_y_z, g_z_yy_y_x, g_z_yy_y_y, g_z_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yy_y_x[i] = -2.0 * g_z_yy_y_x[i] * a_exp + 4.0 * g_xxz_yy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_y_y[i] = -2.0 * g_z_yy_y_y[i] * a_exp + 4.0 * g_xxz_yy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_y_z[i] = -2.0 * g_z_yy_y_z[i] * a_exp + 4.0 * g_xxz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (357-360)

    #pragma omp simd aligned(g_xxz_yy_z_x, g_xxz_yy_z_y, g_xxz_yy_z_z, g_xz_0_0_0_x_yy_z_x, g_xz_0_0_0_x_yy_z_y, g_xz_0_0_0_x_yy_z_z, g_z_yy_z_x, g_z_yy_z_y, g_z_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yy_z_x[i] = -2.0 * g_z_yy_z_x[i] * a_exp + 4.0 * g_xxz_yy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_z_y[i] = -2.0 * g_z_yy_z_y[i] * a_exp + 4.0 * g_xxz_yy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yy_z_z[i] = -2.0 * g_z_yy_z_z[i] * a_exp + 4.0 * g_xxz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (360-363)

    #pragma omp simd aligned(g_xxz_yz_x_x, g_xxz_yz_x_y, g_xxz_yz_x_z, g_xz_0_0_0_x_yz_x_x, g_xz_0_0_0_x_yz_x_y, g_xz_0_0_0_x_yz_x_z, g_z_yz_x_x, g_z_yz_x_y, g_z_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yz_x_x[i] = -2.0 * g_z_yz_x_x[i] * a_exp + 4.0 * g_xxz_yz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_x_y[i] = -2.0 * g_z_yz_x_y[i] * a_exp + 4.0 * g_xxz_yz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_x_z[i] = -2.0 * g_z_yz_x_z[i] * a_exp + 4.0 * g_xxz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (363-366)

    #pragma omp simd aligned(g_xxz_yz_y_x, g_xxz_yz_y_y, g_xxz_yz_y_z, g_xz_0_0_0_x_yz_y_x, g_xz_0_0_0_x_yz_y_y, g_xz_0_0_0_x_yz_y_z, g_z_yz_y_x, g_z_yz_y_y, g_z_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yz_y_x[i] = -2.0 * g_z_yz_y_x[i] * a_exp + 4.0 * g_xxz_yz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_y_y[i] = -2.0 * g_z_yz_y_y[i] * a_exp + 4.0 * g_xxz_yz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_y_z[i] = -2.0 * g_z_yz_y_z[i] * a_exp + 4.0 * g_xxz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (366-369)

    #pragma omp simd aligned(g_xxz_yz_z_x, g_xxz_yz_z_y, g_xxz_yz_z_z, g_xz_0_0_0_x_yz_z_x, g_xz_0_0_0_x_yz_z_y, g_xz_0_0_0_x_yz_z_z, g_z_yz_z_x, g_z_yz_z_y, g_z_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_yz_z_x[i] = -2.0 * g_z_yz_z_x[i] * a_exp + 4.0 * g_xxz_yz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_z_y[i] = -2.0 * g_z_yz_z_y[i] * a_exp + 4.0 * g_xxz_yz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_yz_z_z[i] = -2.0 * g_z_yz_z_z[i] * a_exp + 4.0 * g_xxz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (369-372)

    #pragma omp simd aligned(g_xxz_zz_x_x, g_xxz_zz_x_y, g_xxz_zz_x_z, g_xz_0_0_0_x_zz_x_x, g_xz_0_0_0_x_zz_x_y, g_xz_0_0_0_x_zz_x_z, g_z_zz_x_x, g_z_zz_x_y, g_z_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_zz_x_x[i] = -2.0 * g_z_zz_x_x[i] * a_exp + 4.0 * g_xxz_zz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_x_y[i] = -2.0 * g_z_zz_x_y[i] * a_exp + 4.0 * g_xxz_zz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_x_z[i] = -2.0 * g_z_zz_x_z[i] * a_exp + 4.0 * g_xxz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (372-375)

    #pragma omp simd aligned(g_xxz_zz_y_x, g_xxz_zz_y_y, g_xxz_zz_y_z, g_xz_0_0_0_x_zz_y_x, g_xz_0_0_0_x_zz_y_y, g_xz_0_0_0_x_zz_y_z, g_z_zz_y_x, g_z_zz_y_y, g_z_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_zz_y_x[i] = -2.0 * g_z_zz_y_x[i] * a_exp + 4.0 * g_xxz_zz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_y_y[i] = -2.0 * g_z_zz_y_y[i] * a_exp + 4.0 * g_xxz_zz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_y_z[i] = -2.0 * g_z_zz_y_z[i] * a_exp + 4.0 * g_xxz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (375-378)

    #pragma omp simd aligned(g_xxz_zz_z_x, g_xxz_zz_z_y, g_xxz_zz_z_z, g_xz_0_0_0_x_zz_z_x, g_xz_0_0_0_x_zz_z_y, g_xz_0_0_0_x_zz_z_z, g_z_zz_z_x, g_z_zz_z_y, g_z_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_x_zz_z_x[i] = -2.0 * g_z_zz_z_x[i] * a_exp + 4.0 * g_xxz_zz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_z_y[i] = -2.0 * g_z_zz_z_y[i] * a_exp + 4.0 * g_xxz_zz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_x_zz_z_z[i] = -2.0 * g_z_zz_z_z[i] * a_exp + 4.0 * g_xxz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (378-381)

    #pragma omp simd aligned(g_xyz_xx_x_x, g_xyz_xx_x_y, g_xyz_xx_x_z, g_xz_0_0_0_y_xx_x_x, g_xz_0_0_0_y_xx_x_y, g_xz_0_0_0_y_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xx_x_x[i] = 4.0 * g_xyz_xx_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_x_y[i] = 4.0 * g_xyz_xx_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_x_z[i] = 4.0 * g_xyz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (381-384)

    #pragma omp simd aligned(g_xyz_xx_y_x, g_xyz_xx_y_y, g_xyz_xx_y_z, g_xz_0_0_0_y_xx_y_x, g_xz_0_0_0_y_xx_y_y, g_xz_0_0_0_y_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xx_y_x[i] = 4.0 * g_xyz_xx_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_y_y[i] = 4.0 * g_xyz_xx_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_y_z[i] = 4.0 * g_xyz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (384-387)

    #pragma omp simd aligned(g_xyz_xx_z_x, g_xyz_xx_z_y, g_xyz_xx_z_z, g_xz_0_0_0_y_xx_z_x, g_xz_0_0_0_y_xx_z_y, g_xz_0_0_0_y_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xx_z_x[i] = 4.0 * g_xyz_xx_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_z_y[i] = 4.0 * g_xyz_xx_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xx_z_z[i] = 4.0 * g_xyz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (387-390)

    #pragma omp simd aligned(g_xyz_xy_x_x, g_xyz_xy_x_y, g_xyz_xy_x_z, g_xz_0_0_0_y_xy_x_x, g_xz_0_0_0_y_xy_x_y, g_xz_0_0_0_y_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xy_x_x[i] = 4.0 * g_xyz_xy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_x_y[i] = 4.0 * g_xyz_xy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_x_z[i] = 4.0 * g_xyz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (390-393)

    #pragma omp simd aligned(g_xyz_xy_y_x, g_xyz_xy_y_y, g_xyz_xy_y_z, g_xz_0_0_0_y_xy_y_x, g_xz_0_0_0_y_xy_y_y, g_xz_0_0_0_y_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xy_y_x[i] = 4.0 * g_xyz_xy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_y_y[i] = 4.0 * g_xyz_xy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_y_z[i] = 4.0 * g_xyz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (393-396)

    #pragma omp simd aligned(g_xyz_xy_z_x, g_xyz_xy_z_y, g_xyz_xy_z_z, g_xz_0_0_0_y_xy_z_x, g_xz_0_0_0_y_xy_z_y, g_xz_0_0_0_y_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xy_z_x[i] = 4.0 * g_xyz_xy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_z_y[i] = 4.0 * g_xyz_xy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xy_z_z[i] = 4.0 * g_xyz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (396-399)

    #pragma omp simd aligned(g_xyz_xz_x_x, g_xyz_xz_x_y, g_xyz_xz_x_z, g_xz_0_0_0_y_xz_x_x, g_xz_0_0_0_y_xz_x_y, g_xz_0_0_0_y_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xz_x_x[i] = 4.0 * g_xyz_xz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_x_y[i] = 4.0 * g_xyz_xz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_x_z[i] = 4.0 * g_xyz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (399-402)

    #pragma omp simd aligned(g_xyz_xz_y_x, g_xyz_xz_y_y, g_xyz_xz_y_z, g_xz_0_0_0_y_xz_y_x, g_xz_0_0_0_y_xz_y_y, g_xz_0_0_0_y_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xz_y_x[i] = 4.0 * g_xyz_xz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_y_y[i] = 4.0 * g_xyz_xz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_y_z[i] = 4.0 * g_xyz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (402-405)

    #pragma omp simd aligned(g_xyz_xz_z_x, g_xyz_xz_z_y, g_xyz_xz_z_z, g_xz_0_0_0_y_xz_z_x, g_xz_0_0_0_y_xz_z_y, g_xz_0_0_0_y_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_xz_z_x[i] = 4.0 * g_xyz_xz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_z_y[i] = 4.0 * g_xyz_xz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_xz_z_z[i] = 4.0 * g_xyz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (405-408)

    #pragma omp simd aligned(g_xyz_yy_x_x, g_xyz_yy_x_y, g_xyz_yy_x_z, g_xz_0_0_0_y_yy_x_x, g_xz_0_0_0_y_yy_x_y, g_xz_0_0_0_y_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yy_x_x[i] = 4.0 * g_xyz_yy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_x_y[i] = 4.0 * g_xyz_yy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_x_z[i] = 4.0 * g_xyz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (408-411)

    #pragma omp simd aligned(g_xyz_yy_y_x, g_xyz_yy_y_y, g_xyz_yy_y_z, g_xz_0_0_0_y_yy_y_x, g_xz_0_0_0_y_yy_y_y, g_xz_0_0_0_y_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yy_y_x[i] = 4.0 * g_xyz_yy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_y_y[i] = 4.0 * g_xyz_yy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_y_z[i] = 4.0 * g_xyz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (411-414)

    #pragma omp simd aligned(g_xyz_yy_z_x, g_xyz_yy_z_y, g_xyz_yy_z_z, g_xz_0_0_0_y_yy_z_x, g_xz_0_0_0_y_yy_z_y, g_xz_0_0_0_y_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yy_z_x[i] = 4.0 * g_xyz_yy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_z_y[i] = 4.0 * g_xyz_yy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yy_z_z[i] = 4.0 * g_xyz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (414-417)

    #pragma omp simd aligned(g_xyz_yz_x_x, g_xyz_yz_x_y, g_xyz_yz_x_z, g_xz_0_0_0_y_yz_x_x, g_xz_0_0_0_y_yz_x_y, g_xz_0_0_0_y_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yz_x_x[i] = 4.0 * g_xyz_yz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_x_y[i] = 4.0 * g_xyz_yz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_x_z[i] = 4.0 * g_xyz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (417-420)

    #pragma omp simd aligned(g_xyz_yz_y_x, g_xyz_yz_y_y, g_xyz_yz_y_z, g_xz_0_0_0_y_yz_y_x, g_xz_0_0_0_y_yz_y_y, g_xz_0_0_0_y_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yz_y_x[i] = 4.0 * g_xyz_yz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_y_y[i] = 4.0 * g_xyz_yz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_y_z[i] = 4.0 * g_xyz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (420-423)

    #pragma omp simd aligned(g_xyz_yz_z_x, g_xyz_yz_z_y, g_xyz_yz_z_z, g_xz_0_0_0_y_yz_z_x, g_xz_0_0_0_y_yz_z_y, g_xz_0_0_0_y_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_yz_z_x[i] = 4.0 * g_xyz_yz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_z_y[i] = 4.0 * g_xyz_yz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_yz_z_z[i] = 4.0 * g_xyz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (423-426)

    #pragma omp simd aligned(g_xyz_zz_x_x, g_xyz_zz_x_y, g_xyz_zz_x_z, g_xz_0_0_0_y_zz_x_x, g_xz_0_0_0_y_zz_x_y, g_xz_0_0_0_y_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_zz_x_x[i] = 4.0 * g_xyz_zz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_x_y[i] = 4.0 * g_xyz_zz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_x_z[i] = 4.0 * g_xyz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (426-429)

    #pragma omp simd aligned(g_xyz_zz_y_x, g_xyz_zz_y_y, g_xyz_zz_y_z, g_xz_0_0_0_y_zz_y_x, g_xz_0_0_0_y_zz_y_y, g_xz_0_0_0_y_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_zz_y_x[i] = 4.0 * g_xyz_zz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_y_y[i] = 4.0 * g_xyz_zz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_y_z[i] = 4.0 * g_xyz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (429-432)

    #pragma omp simd aligned(g_xyz_zz_z_x, g_xyz_zz_z_y, g_xyz_zz_z_z, g_xz_0_0_0_y_zz_z_x, g_xz_0_0_0_y_zz_z_y, g_xz_0_0_0_y_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_y_zz_z_x[i] = 4.0 * g_xyz_zz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_z_y[i] = 4.0 * g_xyz_zz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_y_zz_z_z[i] = 4.0 * g_xyz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (432-435)

    #pragma omp simd aligned(g_x_xx_x_x, g_x_xx_x_y, g_x_xx_x_z, g_xz_0_0_0_z_xx_x_x, g_xz_0_0_0_z_xx_x_y, g_xz_0_0_0_z_xx_x_z, g_xzz_xx_x_x, g_xzz_xx_x_y, g_xzz_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xx_x_x[i] = -2.0 * g_x_xx_x_x[i] * a_exp + 4.0 * g_xzz_xx_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_x_y[i] = -2.0 * g_x_xx_x_y[i] * a_exp + 4.0 * g_xzz_xx_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_x_z[i] = -2.0 * g_x_xx_x_z[i] * a_exp + 4.0 * g_xzz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (435-438)

    #pragma omp simd aligned(g_x_xx_y_x, g_x_xx_y_y, g_x_xx_y_z, g_xz_0_0_0_z_xx_y_x, g_xz_0_0_0_z_xx_y_y, g_xz_0_0_0_z_xx_y_z, g_xzz_xx_y_x, g_xzz_xx_y_y, g_xzz_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xx_y_x[i] = -2.0 * g_x_xx_y_x[i] * a_exp + 4.0 * g_xzz_xx_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_y_y[i] = -2.0 * g_x_xx_y_y[i] * a_exp + 4.0 * g_xzz_xx_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_y_z[i] = -2.0 * g_x_xx_y_z[i] * a_exp + 4.0 * g_xzz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (438-441)

    #pragma omp simd aligned(g_x_xx_z_x, g_x_xx_z_y, g_x_xx_z_z, g_xz_0_0_0_z_xx_z_x, g_xz_0_0_0_z_xx_z_y, g_xz_0_0_0_z_xx_z_z, g_xzz_xx_z_x, g_xzz_xx_z_y, g_xzz_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xx_z_x[i] = -2.0 * g_x_xx_z_x[i] * a_exp + 4.0 * g_xzz_xx_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_z_y[i] = -2.0 * g_x_xx_z_y[i] * a_exp + 4.0 * g_xzz_xx_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xx_z_z[i] = -2.0 * g_x_xx_z_z[i] * a_exp + 4.0 * g_xzz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (441-444)

    #pragma omp simd aligned(g_x_xy_x_x, g_x_xy_x_y, g_x_xy_x_z, g_xz_0_0_0_z_xy_x_x, g_xz_0_0_0_z_xy_x_y, g_xz_0_0_0_z_xy_x_z, g_xzz_xy_x_x, g_xzz_xy_x_y, g_xzz_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xy_x_x[i] = -2.0 * g_x_xy_x_x[i] * a_exp + 4.0 * g_xzz_xy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_x_y[i] = -2.0 * g_x_xy_x_y[i] * a_exp + 4.0 * g_xzz_xy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_x_z[i] = -2.0 * g_x_xy_x_z[i] * a_exp + 4.0 * g_xzz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (444-447)

    #pragma omp simd aligned(g_x_xy_y_x, g_x_xy_y_y, g_x_xy_y_z, g_xz_0_0_0_z_xy_y_x, g_xz_0_0_0_z_xy_y_y, g_xz_0_0_0_z_xy_y_z, g_xzz_xy_y_x, g_xzz_xy_y_y, g_xzz_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xy_y_x[i] = -2.0 * g_x_xy_y_x[i] * a_exp + 4.0 * g_xzz_xy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_y_y[i] = -2.0 * g_x_xy_y_y[i] * a_exp + 4.0 * g_xzz_xy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_y_z[i] = -2.0 * g_x_xy_y_z[i] * a_exp + 4.0 * g_xzz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (447-450)

    #pragma omp simd aligned(g_x_xy_z_x, g_x_xy_z_y, g_x_xy_z_z, g_xz_0_0_0_z_xy_z_x, g_xz_0_0_0_z_xy_z_y, g_xz_0_0_0_z_xy_z_z, g_xzz_xy_z_x, g_xzz_xy_z_y, g_xzz_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xy_z_x[i] = -2.0 * g_x_xy_z_x[i] * a_exp + 4.0 * g_xzz_xy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_z_y[i] = -2.0 * g_x_xy_z_y[i] * a_exp + 4.0 * g_xzz_xy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xy_z_z[i] = -2.0 * g_x_xy_z_z[i] * a_exp + 4.0 * g_xzz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (450-453)

    #pragma omp simd aligned(g_x_xz_x_x, g_x_xz_x_y, g_x_xz_x_z, g_xz_0_0_0_z_xz_x_x, g_xz_0_0_0_z_xz_x_y, g_xz_0_0_0_z_xz_x_z, g_xzz_xz_x_x, g_xzz_xz_x_y, g_xzz_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xz_x_x[i] = -2.0 * g_x_xz_x_x[i] * a_exp + 4.0 * g_xzz_xz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_x_y[i] = -2.0 * g_x_xz_x_y[i] * a_exp + 4.0 * g_xzz_xz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_x_z[i] = -2.0 * g_x_xz_x_z[i] * a_exp + 4.0 * g_xzz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (453-456)

    #pragma omp simd aligned(g_x_xz_y_x, g_x_xz_y_y, g_x_xz_y_z, g_xz_0_0_0_z_xz_y_x, g_xz_0_0_0_z_xz_y_y, g_xz_0_0_0_z_xz_y_z, g_xzz_xz_y_x, g_xzz_xz_y_y, g_xzz_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xz_y_x[i] = -2.0 * g_x_xz_y_x[i] * a_exp + 4.0 * g_xzz_xz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_y_y[i] = -2.0 * g_x_xz_y_y[i] * a_exp + 4.0 * g_xzz_xz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_y_z[i] = -2.0 * g_x_xz_y_z[i] * a_exp + 4.0 * g_xzz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (456-459)

    #pragma omp simd aligned(g_x_xz_z_x, g_x_xz_z_y, g_x_xz_z_z, g_xz_0_0_0_z_xz_z_x, g_xz_0_0_0_z_xz_z_y, g_xz_0_0_0_z_xz_z_z, g_xzz_xz_z_x, g_xzz_xz_z_y, g_xzz_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_xz_z_x[i] = -2.0 * g_x_xz_z_x[i] * a_exp + 4.0 * g_xzz_xz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_z_y[i] = -2.0 * g_x_xz_z_y[i] * a_exp + 4.0 * g_xzz_xz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_xz_z_z[i] = -2.0 * g_x_xz_z_z[i] * a_exp + 4.0 * g_xzz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (459-462)

    #pragma omp simd aligned(g_x_yy_x_x, g_x_yy_x_y, g_x_yy_x_z, g_xz_0_0_0_z_yy_x_x, g_xz_0_0_0_z_yy_x_y, g_xz_0_0_0_z_yy_x_z, g_xzz_yy_x_x, g_xzz_yy_x_y, g_xzz_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yy_x_x[i] = -2.0 * g_x_yy_x_x[i] * a_exp + 4.0 * g_xzz_yy_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_x_y[i] = -2.0 * g_x_yy_x_y[i] * a_exp + 4.0 * g_xzz_yy_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_x_z[i] = -2.0 * g_x_yy_x_z[i] * a_exp + 4.0 * g_xzz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (462-465)

    #pragma omp simd aligned(g_x_yy_y_x, g_x_yy_y_y, g_x_yy_y_z, g_xz_0_0_0_z_yy_y_x, g_xz_0_0_0_z_yy_y_y, g_xz_0_0_0_z_yy_y_z, g_xzz_yy_y_x, g_xzz_yy_y_y, g_xzz_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yy_y_x[i] = -2.0 * g_x_yy_y_x[i] * a_exp + 4.0 * g_xzz_yy_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_y_y[i] = -2.0 * g_x_yy_y_y[i] * a_exp + 4.0 * g_xzz_yy_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_y_z[i] = -2.0 * g_x_yy_y_z[i] * a_exp + 4.0 * g_xzz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (465-468)

    #pragma omp simd aligned(g_x_yy_z_x, g_x_yy_z_y, g_x_yy_z_z, g_xz_0_0_0_z_yy_z_x, g_xz_0_0_0_z_yy_z_y, g_xz_0_0_0_z_yy_z_z, g_xzz_yy_z_x, g_xzz_yy_z_y, g_xzz_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yy_z_x[i] = -2.0 * g_x_yy_z_x[i] * a_exp + 4.0 * g_xzz_yy_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_z_y[i] = -2.0 * g_x_yy_z_y[i] * a_exp + 4.0 * g_xzz_yy_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yy_z_z[i] = -2.0 * g_x_yy_z_z[i] * a_exp + 4.0 * g_xzz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (468-471)

    #pragma omp simd aligned(g_x_yz_x_x, g_x_yz_x_y, g_x_yz_x_z, g_xz_0_0_0_z_yz_x_x, g_xz_0_0_0_z_yz_x_y, g_xz_0_0_0_z_yz_x_z, g_xzz_yz_x_x, g_xzz_yz_x_y, g_xzz_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yz_x_x[i] = -2.0 * g_x_yz_x_x[i] * a_exp + 4.0 * g_xzz_yz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_x_y[i] = -2.0 * g_x_yz_x_y[i] * a_exp + 4.0 * g_xzz_yz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_x_z[i] = -2.0 * g_x_yz_x_z[i] * a_exp + 4.0 * g_xzz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (471-474)

    #pragma omp simd aligned(g_x_yz_y_x, g_x_yz_y_y, g_x_yz_y_z, g_xz_0_0_0_z_yz_y_x, g_xz_0_0_0_z_yz_y_y, g_xz_0_0_0_z_yz_y_z, g_xzz_yz_y_x, g_xzz_yz_y_y, g_xzz_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yz_y_x[i] = -2.0 * g_x_yz_y_x[i] * a_exp + 4.0 * g_xzz_yz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_y_y[i] = -2.0 * g_x_yz_y_y[i] * a_exp + 4.0 * g_xzz_yz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_y_z[i] = -2.0 * g_x_yz_y_z[i] * a_exp + 4.0 * g_xzz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (474-477)

    #pragma omp simd aligned(g_x_yz_z_x, g_x_yz_z_y, g_x_yz_z_z, g_xz_0_0_0_z_yz_z_x, g_xz_0_0_0_z_yz_z_y, g_xz_0_0_0_z_yz_z_z, g_xzz_yz_z_x, g_xzz_yz_z_y, g_xzz_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_yz_z_x[i] = -2.0 * g_x_yz_z_x[i] * a_exp + 4.0 * g_xzz_yz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_z_y[i] = -2.0 * g_x_yz_z_y[i] * a_exp + 4.0 * g_xzz_yz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_yz_z_z[i] = -2.0 * g_x_yz_z_z[i] * a_exp + 4.0 * g_xzz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (477-480)

    #pragma omp simd aligned(g_x_zz_x_x, g_x_zz_x_y, g_x_zz_x_z, g_xz_0_0_0_z_zz_x_x, g_xz_0_0_0_z_zz_x_y, g_xz_0_0_0_z_zz_x_z, g_xzz_zz_x_x, g_xzz_zz_x_y, g_xzz_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_zz_x_x[i] = -2.0 * g_x_zz_x_x[i] * a_exp + 4.0 * g_xzz_zz_x_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_x_y[i] = -2.0 * g_x_zz_x_y[i] * a_exp + 4.0 * g_xzz_zz_x_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_x_z[i] = -2.0 * g_x_zz_x_z[i] * a_exp + 4.0 * g_xzz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (480-483)

    #pragma omp simd aligned(g_x_zz_y_x, g_x_zz_y_y, g_x_zz_y_z, g_xz_0_0_0_z_zz_y_x, g_xz_0_0_0_z_zz_y_y, g_xz_0_0_0_z_zz_y_z, g_xzz_zz_y_x, g_xzz_zz_y_y, g_xzz_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_zz_y_x[i] = -2.0 * g_x_zz_y_x[i] * a_exp + 4.0 * g_xzz_zz_y_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_y_y[i] = -2.0 * g_x_zz_y_y[i] * a_exp + 4.0 * g_xzz_zz_y_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_y_z[i] = -2.0 * g_x_zz_y_z[i] * a_exp + 4.0 * g_xzz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (483-486)

    #pragma omp simd aligned(g_x_zz_z_x, g_x_zz_z_y, g_x_zz_z_z, g_xz_0_0_0_z_zz_z_x, g_xz_0_0_0_z_zz_z_y, g_xz_0_0_0_z_zz_z_z, g_xzz_zz_z_x, g_xzz_zz_z_y, g_xzz_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_z_zz_z_x[i] = -2.0 * g_x_zz_z_x[i] * a_exp + 4.0 * g_xzz_zz_z_x[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_z_y[i] = -2.0 * g_x_zz_z_y[i] * a_exp + 4.0 * g_xzz_zz_z_y[i] * a_exp * a_exp;

        g_xz_0_0_0_z_zz_z_z[i] = -2.0 * g_x_zz_z_z[i] * a_exp + 4.0 * g_xzz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (486-489)

    #pragma omp simd aligned(g_x_xx_x_x, g_x_xx_x_y, g_x_xx_x_z, g_xyy_xx_x_x, g_xyy_xx_x_y, g_xyy_xx_x_z, g_yy_0_0_0_x_xx_x_x, g_yy_0_0_0_x_xx_x_y, g_yy_0_0_0_x_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xx_x_x[i] = -2.0 * g_x_xx_x_x[i] * a_exp + 4.0 * g_xyy_xx_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_x_y[i] = -2.0 * g_x_xx_x_y[i] * a_exp + 4.0 * g_xyy_xx_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_x_z[i] = -2.0 * g_x_xx_x_z[i] * a_exp + 4.0 * g_xyy_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (489-492)

    #pragma omp simd aligned(g_x_xx_y_x, g_x_xx_y_y, g_x_xx_y_z, g_xyy_xx_y_x, g_xyy_xx_y_y, g_xyy_xx_y_z, g_yy_0_0_0_x_xx_y_x, g_yy_0_0_0_x_xx_y_y, g_yy_0_0_0_x_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xx_y_x[i] = -2.0 * g_x_xx_y_x[i] * a_exp + 4.0 * g_xyy_xx_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_y_y[i] = -2.0 * g_x_xx_y_y[i] * a_exp + 4.0 * g_xyy_xx_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_y_z[i] = -2.0 * g_x_xx_y_z[i] * a_exp + 4.0 * g_xyy_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (492-495)

    #pragma omp simd aligned(g_x_xx_z_x, g_x_xx_z_y, g_x_xx_z_z, g_xyy_xx_z_x, g_xyy_xx_z_y, g_xyy_xx_z_z, g_yy_0_0_0_x_xx_z_x, g_yy_0_0_0_x_xx_z_y, g_yy_0_0_0_x_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xx_z_x[i] = -2.0 * g_x_xx_z_x[i] * a_exp + 4.0 * g_xyy_xx_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_z_y[i] = -2.0 * g_x_xx_z_y[i] * a_exp + 4.0 * g_xyy_xx_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xx_z_z[i] = -2.0 * g_x_xx_z_z[i] * a_exp + 4.0 * g_xyy_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (495-498)

    #pragma omp simd aligned(g_x_xy_x_x, g_x_xy_x_y, g_x_xy_x_z, g_xyy_xy_x_x, g_xyy_xy_x_y, g_xyy_xy_x_z, g_yy_0_0_0_x_xy_x_x, g_yy_0_0_0_x_xy_x_y, g_yy_0_0_0_x_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xy_x_x[i] = -2.0 * g_x_xy_x_x[i] * a_exp + 4.0 * g_xyy_xy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_x_y[i] = -2.0 * g_x_xy_x_y[i] * a_exp + 4.0 * g_xyy_xy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_x_z[i] = -2.0 * g_x_xy_x_z[i] * a_exp + 4.0 * g_xyy_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (498-501)

    #pragma omp simd aligned(g_x_xy_y_x, g_x_xy_y_y, g_x_xy_y_z, g_xyy_xy_y_x, g_xyy_xy_y_y, g_xyy_xy_y_z, g_yy_0_0_0_x_xy_y_x, g_yy_0_0_0_x_xy_y_y, g_yy_0_0_0_x_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xy_y_x[i] = -2.0 * g_x_xy_y_x[i] * a_exp + 4.0 * g_xyy_xy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_y_y[i] = -2.0 * g_x_xy_y_y[i] * a_exp + 4.0 * g_xyy_xy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_y_z[i] = -2.0 * g_x_xy_y_z[i] * a_exp + 4.0 * g_xyy_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (501-504)

    #pragma omp simd aligned(g_x_xy_z_x, g_x_xy_z_y, g_x_xy_z_z, g_xyy_xy_z_x, g_xyy_xy_z_y, g_xyy_xy_z_z, g_yy_0_0_0_x_xy_z_x, g_yy_0_0_0_x_xy_z_y, g_yy_0_0_0_x_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xy_z_x[i] = -2.0 * g_x_xy_z_x[i] * a_exp + 4.0 * g_xyy_xy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_z_y[i] = -2.0 * g_x_xy_z_y[i] * a_exp + 4.0 * g_xyy_xy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xy_z_z[i] = -2.0 * g_x_xy_z_z[i] * a_exp + 4.0 * g_xyy_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (504-507)

    #pragma omp simd aligned(g_x_xz_x_x, g_x_xz_x_y, g_x_xz_x_z, g_xyy_xz_x_x, g_xyy_xz_x_y, g_xyy_xz_x_z, g_yy_0_0_0_x_xz_x_x, g_yy_0_0_0_x_xz_x_y, g_yy_0_0_0_x_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xz_x_x[i] = -2.0 * g_x_xz_x_x[i] * a_exp + 4.0 * g_xyy_xz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_x_y[i] = -2.0 * g_x_xz_x_y[i] * a_exp + 4.0 * g_xyy_xz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_x_z[i] = -2.0 * g_x_xz_x_z[i] * a_exp + 4.0 * g_xyy_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (507-510)

    #pragma omp simd aligned(g_x_xz_y_x, g_x_xz_y_y, g_x_xz_y_z, g_xyy_xz_y_x, g_xyy_xz_y_y, g_xyy_xz_y_z, g_yy_0_0_0_x_xz_y_x, g_yy_0_0_0_x_xz_y_y, g_yy_0_0_0_x_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xz_y_x[i] = -2.0 * g_x_xz_y_x[i] * a_exp + 4.0 * g_xyy_xz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_y_y[i] = -2.0 * g_x_xz_y_y[i] * a_exp + 4.0 * g_xyy_xz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_y_z[i] = -2.0 * g_x_xz_y_z[i] * a_exp + 4.0 * g_xyy_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (510-513)

    #pragma omp simd aligned(g_x_xz_z_x, g_x_xz_z_y, g_x_xz_z_z, g_xyy_xz_z_x, g_xyy_xz_z_y, g_xyy_xz_z_z, g_yy_0_0_0_x_xz_z_x, g_yy_0_0_0_x_xz_z_y, g_yy_0_0_0_x_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_xz_z_x[i] = -2.0 * g_x_xz_z_x[i] * a_exp + 4.0 * g_xyy_xz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_z_y[i] = -2.0 * g_x_xz_z_y[i] * a_exp + 4.0 * g_xyy_xz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_xz_z_z[i] = -2.0 * g_x_xz_z_z[i] * a_exp + 4.0 * g_xyy_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (513-516)

    #pragma omp simd aligned(g_x_yy_x_x, g_x_yy_x_y, g_x_yy_x_z, g_xyy_yy_x_x, g_xyy_yy_x_y, g_xyy_yy_x_z, g_yy_0_0_0_x_yy_x_x, g_yy_0_0_0_x_yy_x_y, g_yy_0_0_0_x_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yy_x_x[i] = -2.0 * g_x_yy_x_x[i] * a_exp + 4.0 * g_xyy_yy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_x_y[i] = -2.0 * g_x_yy_x_y[i] * a_exp + 4.0 * g_xyy_yy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_x_z[i] = -2.0 * g_x_yy_x_z[i] * a_exp + 4.0 * g_xyy_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (516-519)

    #pragma omp simd aligned(g_x_yy_y_x, g_x_yy_y_y, g_x_yy_y_z, g_xyy_yy_y_x, g_xyy_yy_y_y, g_xyy_yy_y_z, g_yy_0_0_0_x_yy_y_x, g_yy_0_0_0_x_yy_y_y, g_yy_0_0_0_x_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yy_y_x[i] = -2.0 * g_x_yy_y_x[i] * a_exp + 4.0 * g_xyy_yy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_y_y[i] = -2.0 * g_x_yy_y_y[i] * a_exp + 4.0 * g_xyy_yy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_y_z[i] = -2.0 * g_x_yy_y_z[i] * a_exp + 4.0 * g_xyy_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (519-522)

    #pragma omp simd aligned(g_x_yy_z_x, g_x_yy_z_y, g_x_yy_z_z, g_xyy_yy_z_x, g_xyy_yy_z_y, g_xyy_yy_z_z, g_yy_0_0_0_x_yy_z_x, g_yy_0_0_0_x_yy_z_y, g_yy_0_0_0_x_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yy_z_x[i] = -2.0 * g_x_yy_z_x[i] * a_exp + 4.0 * g_xyy_yy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_z_y[i] = -2.0 * g_x_yy_z_y[i] * a_exp + 4.0 * g_xyy_yy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yy_z_z[i] = -2.0 * g_x_yy_z_z[i] * a_exp + 4.0 * g_xyy_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (522-525)

    #pragma omp simd aligned(g_x_yz_x_x, g_x_yz_x_y, g_x_yz_x_z, g_xyy_yz_x_x, g_xyy_yz_x_y, g_xyy_yz_x_z, g_yy_0_0_0_x_yz_x_x, g_yy_0_0_0_x_yz_x_y, g_yy_0_0_0_x_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yz_x_x[i] = -2.0 * g_x_yz_x_x[i] * a_exp + 4.0 * g_xyy_yz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_x_y[i] = -2.0 * g_x_yz_x_y[i] * a_exp + 4.0 * g_xyy_yz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_x_z[i] = -2.0 * g_x_yz_x_z[i] * a_exp + 4.0 * g_xyy_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (525-528)

    #pragma omp simd aligned(g_x_yz_y_x, g_x_yz_y_y, g_x_yz_y_z, g_xyy_yz_y_x, g_xyy_yz_y_y, g_xyy_yz_y_z, g_yy_0_0_0_x_yz_y_x, g_yy_0_0_0_x_yz_y_y, g_yy_0_0_0_x_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yz_y_x[i] = -2.0 * g_x_yz_y_x[i] * a_exp + 4.0 * g_xyy_yz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_y_y[i] = -2.0 * g_x_yz_y_y[i] * a_exp + 4.0 * g_xyy_yz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_y_z[i] = -2.0 * g_x_yz_y_z[i] * a_exp + 4.0 * g_xyy_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (528-531)

    #pragma omp simd aligned(g_x_yz_z_x, g_x_yz_z_y, g_x_yz_z_z, g_xyy_yz_z_x, g_xyy_yz_z_y, g_xyy_yz_z_z, g_yy_0_0_0_x_yz_z_x, g_yy_0_0_0_x_yz_z_y, g_yy_0_0_0_x_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_yz_z_x[i] = -2.0 * g_x_yz_z_x[i] * a_exp + 4.0 * g_xyy_yz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_z_y[i] = -2.0 * g_x_yz_z_y[i] * a_exp + 4.0 * g_xyy_yz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_yz_z_z[i] = -2.0 * g_x_yz_z_z[i] * a_exp + 4.0 * g_xyy_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (531-534)

    #pragma omp simd aligned(g_x_zz_x_x, g_x_zz_x_y, g_x_zz_x_z, g_xyy_zz_x_x, g_xyy_zz_x_y, g_xyy_zz_x_z, g_yy_0_0_0_x_zz_x_x, g_yy_0_0_0_x_zz_x_y, g_yy_0_0_0_x_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_zz_x_x[i] = -2.0 * g_x_zz_x_x[i] * a_exp + 4.0 * g_xyy_zz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_x_y[i] = -2.0 * g_x_zz_x_y[i] * a_exp + 4.0 * g_xyy_zz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_x_z[i] = -2.0 * g_x_zz_x_z[i] * a_exp + 4.0 * g_xyy_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (534-537)

    #pragma omp simd aligned(g_x_zz_y_x, g_x_zz_y_y, g_x_zz_y_z, g_xyy_zz_y_x, g_xyy_zz_y_y, g_xyy_zz_y_z, g_yy_0_0_0_x_zz_y_x, g_yy_0_0_0_x_zz_y_y, g_yy_0_0_0_x_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_zz_y_x[i] = -2.0 * g_x_zz_y_x[i] * a_exp + 4.0 * g_xyy_zz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_y_y[i] = -2.0 * g_x_zz_y_y[i] * a_exp + 4.0 * g_xyy_zz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_y_z[i] = -2.0 * g_x_zz_y_z[i] * a_exp + 4.0 * g_xyy_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (537-540)

    #pragma omp simd aligned(g_x_zz_z_x, g_x_zz_z_y, g_x_zz_z_z, g_xyy_zz_z_x, g_xyy_zz_z_y, g_xyy_zz_z_z, g_yy_0_0_0_x_zz_z_x, g_yy_0_0_0_x_zz_z_y, g_yy_0_0_0_x_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_x_zz_z_x[i] = -2.0 * g_x_zz_z_x[i] * a_exp + 4.0 * g_xyy_zz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_z_y[i] = -2.0 * g_x_zz_z_y[i] * a_exp + 4.0 * g_xyy_zz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_x_zz_z_z[i] = -2.0 * g_x_zz_z_z[i] * a_exp + 4.0 * g_xyy_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (540-543)

    #pragma omp simd aligned(g_y_xx_x_x, g_y_xx_x_y, g_y_xx_x_z, g_yy_0_0_0_y_xx_x_x, g_yy_0_0_0_y_xx_x_y, g_yy_0_0_0_y_xx_x_z, g_yyy_xx_x_x, g_yyy_xx_x_y, g_yyy_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xx_x_x[i] = -6.0 * g_y_xx_x_x[i] * a_exp + 4.0 * g_yyy_xx_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_x_y[i] = -6.0 * g_y_xx_x_y[i] * a_exp + 4.0 * g_yyy_xx_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_x_z[i] = -6.0 * g_y_xx_x_z[i] * a_exp + 4.0 * g_yyy_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (543-546)

    #pragma omp simd aligned(g_y_xx_y_x, g_y_xx_y_y, g_y_xx_y_z, g_yy_0_0_0_y_xx_y_x, g_yy_0_0_0_y_xx_y_y, g_yy_0_0_0_y_xx_y_z, g_yyy_xx_y_x, g_yyy_xx_y_y, g_yyy_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xx_y_x[i] = -6.0 * g_y_xx_y_x[i] * a_exp + 4.0 * g_yyy_xx_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_y_y[i] = -6.0 * g_y_xx_y_y[i] * a_exp + 4.0 * g_yyy_xx_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_y_z[i] = -6.0 * g_y_xx_y_z[i] * a_exp + 4.0 * g_yyy_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (546-549)

    #pragma omp simd aligned(g_y_xx_z_x, g_y_xx_z_y, g_y_xx_z_z, g_yy_0_0_0_y_xx_z_x, g_yy_0_0_0_y_xx_z_y, g_yy_0_0_0_y_xx_z_z, g_yyy_xx_z_x, g_yyy_xx_z_y, g_yyy_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xx_z_x[i] = -6.0 * g_y_xx_z_x[i] * a_exp + 4.0 * g_yyy_xx_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_z_y[i] = -6.0 * g_y_xx_z_y[i] * a_exp + 4.0 * g_yyy_xx_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xx_z_z[i] = -6.0 * g_y_xx_z_z[i] * a_exp + 4.0 * g_yyy_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (549-552)

    #pragma omp simd aligned(g_y_xy_x_x, g_y_xy_x_y, g_y_xy_x_z, g_yy_0_0_0_y_xy_x_x, g_yy_0_0_0_y_xy_x_y, g_yy_0_0_0_y_xy_x_z, g_yyy_xy_x_x, g_yyy_xy_x_y, g_yyy_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xy_x_x[i] = -6.0 * g_y_xy_x_x[i] * a_exp + 4.0 * g_yyy_xy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_x_y[i] = -6.0 * g_y_xy_x_y[i] * a_exp + 4.0 * g_yyy_xy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_x_z[i] = -6.0 * g_y_xy_x_z[i] * a_exp + 4.0 * g_yyy_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (552-555)

    #pragma omp simd aligned(g_y_xy_y_x, g_y_xy_y_y, g_y_xy_y_z, g_yy_0_0_0_y_xy_y_x, g_yy_0_0_0_y_xy_y_y, g_yy_0_0_0_y_xy_y_z, g_yyy_xy_y_x, g_yyy_xy_y_y, g_yyy_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xy_y_x[i] = -6.0 * g_y_xy_y_x[i] * a_exp + 4.0 * g_yyy_xy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_y_y[i] = -6.0 * g_y_xy_y_y[i] * a_exp + 4.0 * g_yyy_xy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_y_z[i] = -6.0 * g_y_xy_y_z[i] * a_exp + 4.0 * g_yyy_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (555-558)

    #pragma omp simd aligned(g_y_xy_z_x, g_y_xy_z_y, g_y_xy_z_z, g_yy_0_0_0_y_xy_z_x, g_yy_0_0_0_y_xy_z_y, g_yy_0_0_0_y_xy_z_z, g_yyy_xy_z_x, g_yyy_xy_z_y, g_yyy_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xy_z_x[i] = -6.0 * g_y_xy_z_x[i] * a_exp + 4.0 * g_yyy_xy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_z_y[i] = -6.0 * g_y_xy_z_y[i] * a_exp + 4.0 * g_yyy_xy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xy_z_z[i] = -6.0 * g_y_xy_z_z[i] * a_exp + 4.0 * g_yyy_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (558-561)

    #pragma omp simd aligned(g_y_xz_x_x, g_y_xz_x_y, g_y_xz_x_z, g_yy_0_0_0_y_xz_x_x, g_yy_0_0_0_y_xz_x_y, g_yy_0_0_0_y_xz_x_z, g_yyy_xz_x_x, g_yyy_xz_x_y, g_yyy_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xz_x_x[i] = -6.0 * g_y_xz_x_x[i] * a_exp + 4.0 * g_yyy_xz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_x_y[i] = -6.0 * g_y_xz_x_y[i] * a_exp + 4.0 * g_yyy_xz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_x_z[i] = -6.0 * g_y_xz_x_z[i] * a_exp + 4.0 * g_yyy_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (561-564)

    #pragma omp simd aligned(g_y_xz_y_x, g_y_xz_y_y, g_y_xz_y_z, g_yy_0_0_0_y_xz_y_x, g_yy_0_0_0_y_xz_y_y, g_yy_0_0_0_y_xz_y_z, g_yyy_xz_y_x, g_yyy_xz_y_y, g_yyy_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xz_y_x[i] = -6.0 * g_y_xz_y_x[i] * a_exp + 4.0 * g_yyy_xz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_y_y[i] = -6.0 * g_y_xz_y_y[i] * a_exp + 4.0 * g_yyy_xz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_y_z[i] = -6.0 * g_y_xz_y_z[i] * a_exp + 4.0 * g_yyy_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (564-567)

    #pragma omp simd aligned(g_y_xz_z_x, g_y_xz_z_y, g_y_xz_z_z, g_yy_0_0_0_y_xz_z_x, g_yy_0_0_0_y_xz_z_y, g_yy_0_0_0_y_xz_z_z, g_yyy_xz_z_x, g_yyy_xz_z_y, g_yyy_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_xz_z_x[i] = -6.0 * g_y_xz_z_x[i] * a_exp + 4.0 * g_yyy_xz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_z_y[i] = -6.0 * g_y_xz_z_y[i] * a_exp + 4.0 * g_yyy_xz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_xz_z_z[i] = -6.0 * g_y_xz_z_z[i] * a_exp + 4.0 * g_yyy_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (567-570)

    #pragma omp simd aligned(g_y_yy_x_x, g_y_yy_x_y, g_y_yy_x_z, g_yy_0_0_0_y_yy_x_x, g_yy_0_0_0_y_yy_x_y, g_yy_0_0_0_y_yy_x_z, g_yyy_yy_x_x, g_yyy_yy_x_y, g_yyy_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yy_x_x[i] = -6.0 * g_y_yy_x_x[i] * a_exp + 4.0 * g_yyy_yy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_x_y[i] = -6.0 * g_y_yy_x_y[i] * a_exp + 4.0 * g_yyy_yy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_x_z[i] = -6.0 * g_y_yy_x_z[i] * a_exp + 4.0 * g_yyy_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (570-573)

    #pragma omp simd aligned(g_y_yy_y_x, g_y_yy_y_y, g_y_yy_y_z, g_yy_0_0_0_y_yy_y_x, g_yy_0_0_0_y_yy_y_y, g_yy_0_0_0_y_yy_y_z, g_yyy_yy_y_x, g_yyy_yy_y_y, g_yyy_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yy_y_x[i] = -6.0 * g_y_yy_y_x[i] * a_exp + 4.0 * g_yyy_yy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_y_y[i] = -6.0 * g_y_yy_y_y[i] * a_exp + 4.0 * g_yyy_yy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_y_z[i] = -6.0 * g_y_yy_y_z[i] * a_exp + 4.0 * g_yyy_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (573-576)

    #pragma omp simd aligned(g_y_yy_z_x, g_y_yy_z_y, g_y_yy_z_z, g_yy_0_0_0_y_yy_z_x, g_yy_0_0_0_y_yy_z_y, g_yy_0_0_0_y_yy_z_z, g_yyy_yy_z_x, g_yyy_yy_z_y, g_yyy_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yy_z_x[i] = -6.0 * g_y_yy_z_x[i] * a_exp + 4.0 * g_yyy_yy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_z_y[i] = -6.0 * g_y_yy_z_y[i] * a_exp + 4.0 * g_yyy_yy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yy_z_z[i] = -6.0 * g_y_yy_z_z[i] * a_exp + 4.0 * g_yyy_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (576-579)

    #pragma omp simd aligned(g_y_yz_x_x, g_y_yz_x_y, g_y_yz_x_z, g_yy_0_0_0_y_yz_x_x, g_yy_0_0_0_y_yz_x_y, g_yy_0_0_0_y_yz_x_z, g_yyy_yz_x_x, g_yyy_yz_x_y, g_yyy_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yz_x_x[i] = -6.0 * g_y_yz_x_x[i] * a_exp + 4.0 * g_yyy_yz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_x_y[i] = -6.0 * g_y_yz_x_y[i] * a_exp + 4.0 * g_yyy_yz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_x_z[i] = -6.0 * g_y_yz_x_z[i] * a_exp + 4.0 * g_yyy_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (579-582)

    #pragma omp simd aligned(g_y_yz_y_x, g_y_yz_y_y, g_y_yz_y_z, g_yy_0_0_0_y_yz_y_x, g_yy_0_0_0_y_yz_y_y, g_yy_0_0_0_y_yz_y_z, g_yyy_yz_y_x, g_yyy_yz_y_y, g_yyy_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yz_y_x[i] = -6.0 * g_y_yz_y_x[i] * a_exp + 4.0 * g_yyy_yz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_y_y[i] = -6.0 * g_y_yz_y_y[i] * a_exp + 4.0 * g_yyy_yz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_y_z[i] = -6.0 * g_y_yz_y_z[i] * a_exp + 4.0 * g_yyy_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (582-585)

    #pragma omp simd aligned(g_y_yz_z_x, g_y_yz_z_y, g_y_yz_z_z, g_yy_0_0_0_y_yz_z_x, g_yy_0_0_0_y_yz_z_y, g_yy_0_0_0_y_yz_z_z, g_yyy_yz_z_x, g_yyy_yz_z_y, g_yyy_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_yz_z_x[i] = -6.0 * g_y_yz_z_x[i] * a_exp + 4.0 * g_yyy_yz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_z_y[i] = -6.0 * g_y_yz_z_y[i] * a_exp + 4.0 * g_yyy_yz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_yz_z_z[i] = -6.0 * g_y_yz_z_z[i] * a_exp + 4.0 * g_yyy_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (585-588)

    #pragma omp simd aligned(g_y_zz_x_x, g_y_zz_x_y, g_y_zz_x_z, g_yy_0_0_0_y_zz_x_x, g_yy_0_0_0_y_zz_x_y, g_yy_0_0_0_y_zz_x_z, g_yyy_zz_x_x, g_yyy_zz_x_y, g_yyy_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_zz_x_x[i] = -6.0 * g_y_zz_x_x[i] * a_exp + 4.0 * g_yyy_zz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_x_y[i] = -6.0 * g_y_zz_x_y[i] * a_exp + 4.0 * g_yyy_zz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_x_z[i] = -6.0 * g_y_zz_x_z[i] * a_exp + 4.0 * g_yyy_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (588-591)

    #pragma omp simd aligned(g_y_zz_y_x, g_y_zz_y_y, g_y_zz_y_z, g_yy_0_0_0_y_zz_y_x, g_yy_0_0_0_y_zz_y_y, g_yy_0_0_0_y_zz_y_z, g_yyy_zz_y_x, g_yyy_zz_y_y, g_yyy_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_zz_y_x[i] = -6.0 * g_y_zz_y_x[i] * a_exp + 4.0 * g_yyy_zz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_y_y[i] = -6.0 * g_y_zz_y_y[i] * a_exp + 4.0 * g_yyy_zz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_y_z[i] = -6.0 * g_y_zz_y_z[i] * a_exp + 4.0 * g_yyy_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (591-594)

    #pragma omp simd aligned(g_y_zz_z_x, g_y_zz_z_y, g_y_zz_z_z, g_yy_0_0_0_y_zz_z_x, g_yy_0_0_0_y_zz_z_y, g_yy_0_0_0_y_zz_z_z, g_yyy_zz_z_x, g_yyy_zz_z_y, g_yyy_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_y_zz_z_x[i] = -6.0 * g_y_zz_z_x[i] * a_exp + 4.0 * g_yyy_zz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_z_y[i] = -6.0 * g_y_zz_z_y[i] * a_exp + 4.0 * g_yyy_zz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_y_zz_z_z[i] = -6.0 * g_y_zz_z_z[i] * a_exp + 4.0 * g_yyy_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (594-597)

    #pragma omp simd aligned(g_yy_0_0_0_z_xx_x_x, g_yy_0_0_0_z_xx_x_y, g_yy_0_0_0_z_xx_x_z, g_yyz_xx_x_x, g_yyz_xx_x_y, g_yyz_xx_x_z, g_z_xx_x_x, g_z_xx_x_y, g_z_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xx_x_x[i] = -2.0 * g_z_xx_x_x[i] * a_exp + 4.0 * g_yyz_xx_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_x_y[i] = -2.0 * g_z_xx_x_y[i] * a_exp + 4.0 * g_yyz_xx_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_x_z[i] = -2.0 * g_z_xx_x_z[i] * a_exp + 4.0 * g_yyz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (597-600)

    #pragma omp simd aligned(g_yy_0_0_0_z_xx_y_x, g_yy_0_0_0_z_xx_y_y, g_yy_0_0_0_z_xx_y_z, g_yyz_xx_y_x, g_yyz_xx_y_y, g_yyz_xx_y_z, g_z_xx_y_x, g_z_xx_y_y, g_z_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xx_y_x[i] = -2.0 * g_z_xx_y_x[i] * a_exp + 4.0 * g_yyz_xx_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_y_y[i] = -2.0 * g_z_xx_y_y[i] * a_exp + 4.0 * g_yyz_xx_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_y_z[i] = -2.0 * g_z_xx_y_z[i] * a_exp + 4.0 * g_yyz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (600-603)

    #pragma omp simd aligned(g_yy_0_0_0_z_xx_z_x, g_yy_0_0_0_z_xx_z_y, g_yy_0_0_0_z_xx_z_z, g_yyz_xx_z_x, g_yyz_xx_z_y, g_yyz_xx_z_z, g_z_xx_z_x, g_z_xx_z_y, g_z_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xx_z_x[i] = -2.0 * g_z_xx_z_x[i] * a_exp + 4.0 * g_yyz_xx_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_z_y[i] = -2.0 * g_z_xx_z_y[i] * a_exp + 4.0 * g_yyz_xx_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xx_z_z[i] = -2.0 * g_z_xx_z_z[i] * a_exp + 4.0 * g_yyz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (603-606)

    #pragma omp simd aligned(g_yy_0_0_0_z_xy_x_x, g_yy_0_0_0_z_xy_x_y, g_yy_0_0_0_z_xy_x_z, g_yyz_xy_x_x, g_yyz_xy_x_y, g_yyz_xy_x_z, g_z_xy_x_x, g_z_xy_x_y, g_z_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xy_x_x[i] = -2.0 * g_z_xy_x_x[i] * a_exp + 4.0 * g_yyz_xy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_x_y[i] = -2.0 * g_z_xy_x_y[i] * a_exp + 4.0 * g_yyz_xy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_x_z[i] = -2.0 * g_z_xy_x_z[i] * a_exp + 4.0 * g_yyz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (606-609)

    #pragma omp simd aligned(g_yy_0_0_0_z_xy_y_x, g_yy_0_0_0_z_xy_y_y, g_yy_0_0_0_z_xy_y_z, g_yyz_xy_y_x, g_yyz_xy_y_y, g_yyz_xy_y_z, g_z_xy_y_x, g_z_xy_y_y, g_z_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xy_y_x[i] = -2.0 * g_z_xy_y_x[i] * a_exp + 4.0 * g_yyz_xy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_y_y[i] = -2.0 * g_z_xy_y_y[i] * a_exp + 4.0 * g_yyz_xy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_y_z[i] = -2.0 * g_z_xy_y_z[i] * a_exp + 4.0 * g_yyz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (609-612)

    #pragma omp simd aligned(g_yy_0_0_0_z_xy_z_x, g_yy_0_0_0_z_xy_z_y, g_yy_0_0_0_z_xy_z_z, g_yyz_xy_z_x, g_yyz_xy_z_y, g_yyz_xy_z_z, g_z_xy_z_x, g_z_xy_z_y, g_z_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xy_z_x[i] = -2.0 * g_z_xy_z_x[i] * a_exp + 4.0 * g_yyz_xy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_z_y[i] = -2.0 * g_z_xy_z_y[i] * a_exp + 4.0 * g_yyz_xy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xy_z_z[i] = -2.0 * g_z_xy_z_z[i] * a_exp + 4.0 * g_yyz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (612-615)

    #pragma omp simd aligned(g_yy_0_0_0_z_xz_x_x, g_yy_0_0_0_z_xz_x_y, g_yy_0_0_0_z_xz_x_z, g_yyz_xz_x_x, g_yyz_xz_x_y, g_yyz_xz_x_z, g_z_xz_x_x, g_z_xz_x_y, g_z_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xz_x_x[i] = -2.0 * g_z_xz_x_x[i] * a_exp + 4.0 * g_yyz_xz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_x_y[i] = -2.0 * g_z_xz_x_y[i] * a_exp + 4.0 * g_yyz_xz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_x_z[i] = -2.0 * g_z_xz_x_z[i] * a_exp + 4.0 * g_yyz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (615-618)

    #pragma omp simd aligned(g_yy_0_0_0_z_xz_y_x, g_yy_0_0_0_z_xz_y_y, g_yy_0_0_0_z_xz_y_z, g_yyz_xz_y_x, g_yyz_xz_y_y, g_yyz_xz_y_z, g_z_xz_y_x, g_z_xz_y_y, g_z_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xz_y_x[i] = -2.0 * g_z_xz_y_x[i] * a_exp + 4.0 * g_yyz_xz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_y_y[i] = -2.0 * g_z_xz_y_y[i] * a_exp + 4.0 * g_yyz_xz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_y_z[i] = -2.0 * g_z_xz_y_z[i] * a_exp + 4.0 * g_yyz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (618-621)

    #pragma omp simd aligned(g_yy_0_0_0_z_xz_z_x, g_yy_0_0_0_z_xz_z_y, g_yy_0_0_0_z_xz_z_z, g_yyz_xz_z_x, g_yyz_xz_z_y, g_yyz_xz_z_z, g_z_xz_z_x, g_z_xz_z_y, g_z_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_xz_z_x[i] = -2.0 * g_z_xz_z_x[i] * a_exp + 4.0 * g_yyz_xz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_z_y[i] = -2.0 * g_z_xz_z_y[i] * a_exp + 4.0 * g_yyz_xz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_xz_z_z[i] = -2.0 * g_z_xz_z_z[i] * a_exp + 4.0 * g_yyz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (621-624)

    #pragma omp simd aligned(g_yy_0_0_0_z_yy_x_x, g_yy_0_0_0_z_yy_x_y, g_yy_0_0_0_z_yy_x_z, g_yyz_yy_x_x, g_yyz_yy_x_y, g_yyz_yy_x_z, g_z_yy_x_x, g_z_yy_x_y, g_z_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yy_x_x[i] = -2.0 * g_z_yy_x_x[i] * a_exp + 4.0 * g_yyz_yy_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_x_y[i] = -2.0 * g_z_yy_x_y[i] * a_exp + 4.0 * g_yyz_yy_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_x_z[i] = -2.0 * g_z_yy_x_z[i] * a_exp + 4.0 * g_yyz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (624-627)

    #pragma omp simd aligned(g_yy_0_0_0_z_yy_y_x, g_yy_0_0_0_z_yy_y_y, g_yy_0_0_0_z_yy_y_z, g_yyz_yy_y_x, g_yyz_yy_y_y, g_yyz_yy_y_z, g_z_yy_y_x, g_z_yy_y_y, g_z_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yy_y_x[i] = -2.0 * g_z_yy_y_x[i] * a_exp + 4.0 * g_yyz_yy_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_y_y[i] = -2.0 * g_z_yy_y_y[i] * a_exp + 4.0 * g_yyz_yy_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_y_z[i] = -2.0 * g_z_yy_y_z[i] * a_exp + 4.0 * g_yyz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (627-630)

    #pragma omp simd aligned(g_yy_0_0_0_z_yy_z_x, g_yy_0_0_0_z_yy_z_y, g_yy_0_0_0_z_yy_z_z, g_yyz_yy_z_x, g_yyz_yy_z_y, g_yyz_yy_z_z, g_z_yy_z_x, g_z_yy_z_y, g_z_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yy_z_x[i] = -2.0 * g_z_yy_z_x[i] * a_exp + 4.0 * g_yyz_yy_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_z_y[i] = -2.0 * g_z_yy_z_y[i] * a_exp + 4.0 * g_yyz_yy_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yy_z_z[i] = -2.0 * g_z_yy_z_z[i] * a_exp + 4.0 * g_yyz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (630-633)

    #pragma omp simd aligned(g_yy_0_0_0_z_yz_x_x, g_yy_0_0_0_z_yz_x_y, g_yy_0_0_0_z_yz_x_z, g_yyz_yz_x_x, g_yyz_yz_x_y, g_yyz_yz_x_z, g_z_yz_x_x, g_z_yz_x_y, g_z_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yz_x_x[i] = -2.0 * g_z_yz_x_x[i] * a_exp + 4.0 * g_yyz_yz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_x_y[i] = -2.0 * g_z_yz_x_y[i] * a_exp + 4.0 * g_yyz_yz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_x_z[i] = -2.0 * g_z_yz_x_z[i] * a_exp + 4.0 * g_yyz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (633-636)

    #pragma omp simd aligned(g_yy_0_0_0_z_yz_y_x, g_yy_0_0_0_z_yz_y_y, g_yy_0_0_0_z_yz_y_z, g_yyz_yz_y_x, g_yyz_yz_y_y, g_yyz_yz_y_z, g_z_yz_y_x, g_z_yz_y_y, g_z_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yz_y_x[i] = -2.0 * g_z_yz_y_x[i] * a_exp + 4.0 * g_yyz_yz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_y_y[i] = -2.0 * g_z_yz_y_y[i] * a_exp + 4.0 * g_yyz_yz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_y_z[i] = -2.0 * g_z_yz_y_z[i] * a_exp + 4.0 * g_yyz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (636-639)

    #pragma omp simd aligned(g_yy_0_0_0_z_yz_z_x, g_yy_0_0_0_z_yz_z_y, g_yy_0_0_0_z_yz_z_z, g_yyz_yz_z_x, g_yyz_yz_z_y, g_yyz_yz_z_z, g_z_yz_z_x, g_z_yz_z_y, g_z_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_yz_z_x[i] = -2.0 * g_z_yz_z_x[i] * a_exp + 4.0 * g_yyz_yz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_z_y[i] = -2.0 * g_z_yz_z_y[i] * a_exp + 4.0 * g_yyz_yz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_yz_z_z[i] = -2.0 * g_z_yz_z_z[i] * a_exp + 4.0 * g_yyz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (639-642)

    #pragma omp simd aligned(g_yy_0_0_0_z_zz_x_x, g_yy_0_0_0_z_zz_x_y, g_yy_0_0_0_z_zz_x_z, g_yyz_zz_x_x, g_yyz_zz_x_y, g_yyz_zz_x_z, g_z_zz_x_x, g_z_zz_x_y, g_z_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_zz_x_x[i] = -2.0 * g_z_zz_x_x[i] * a_exp + 4.0 * g_yyz_zz_x_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_x_y[i] = -2.0 * g_z_zz_x_y[i] * a_exp + 4.0 * g_yyz_zz_x_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_x_z[i] = -2.0 * g_z_zz_x_z[i] * a_exp + 4.0 * g_yyz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (642-645)

    #pragma omp simd aligned(g_yy_0_0_0_z_zz_y_x, g_yy_0_0_0_z_zz_y_y, g_yy_0_0_0_z_zz_y_z, g_yyz_zz_y_x, g_yyz_zz_y_y, g_yyz_zz_y_z, g_z_zz_y_x, g_z_zz_y_y, g_z_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_zz_y_x[i] = -2.0 * g_z_zz_y_x[i] * a_exp + 4.0 * g_yyz_zz_y_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_y_y[i] = -2.0 * g_z_zz_y_y[i] * a_exp + 4.0 * g_yyz_zz_y_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_y_z[i] = -2.0 * g_z_zz_y_z[i] * a_exp + 4.0 * g_yyz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (645-648)

    #pragma omp simd aligned(g_yy_0_0_0_z_zz_z_x, g_yy_0_0_0_z_zz_z_y, g_yy_0_0_0_z_zz_z_z, g_yyz_zz_z_x, g_yyz_zz_z_y, g_yyz_zz_z_z, g_z_zz_z_x, g_z_zz_z_y, g_z_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_z_zz_z_x[i] = -2.0 * g_z_zz_z_x[i] * a_exp + 4.0 * g_yyz_zz_z_x[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_z_y[i] = -2.0 * g_z_zz_z_y[i] * a_exp + 4.0 * g_yyz_zz_z_y[i] * a_exp * a_exp;

        g_yy_0_0_0_z_zz_z_z[i] = -2.0 * g_z_zz_z_z[i] * a_exp + 4.0 * g_yyz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (648-651)

    #pragma omp simd aligned(g_xyz_xx_x_x, g_xyz_xx_x_y, g_xyz_xx_x_z, g_yz_0_0_0_x_xx_x_x, g_yz_0_0_0_x_xx_x_y, g_yz_0_0_0_x_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xx_x_x[i] = 4.0 * g_xyz_xx_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_x_y[i] = 4.0 * g_xyz_xx_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_x_z[i] = 4.0 * g_xyz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (651-654)

    #pragma omp simd aligned(g_xyz_xx_y_x, g_xyz_xx_y_y, g_xyz_xx_y_z, g_yz_0_0_0_x_xx_y_x, g_yz_0_0_0_x_xx_y_y, g_yz_0_0_0_x_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xx_y_x[i] = 4.0 * g_xyz_xx_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_y_y[i] = 4.0 * g_xyz_xx_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_y_z[i] = 4.0 * g_xyz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (654-657)

    #pragma omp simd aligned(g_xyz_xx_z_x, g_xyz_xx_z_y, g_xyz_xx_z_z, g_yz_0_0_0_x_xx_z_x, g_yz_0_0_0_x_xx_z_y, g_yz_0_0_0_x_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xx_z_x[i] = 4.0 * g_xyz_xx_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_z_y[i] = 4.0 * g_xyz_xx_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xx_z_z[i] = 4.0 * g_xyz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (657-660)

    #pragma omp simd aligned(g_xyz_xy_x_x, g_xyz_xy_x_y, g_xyz_xy_x_z, g_yz_0_0_0_x_xy_x_x, g_yz_0_0_0_x_xy_x_y, g_yz_0_0_0_x_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xy_x_x[i] = 4.0 * g_xyz_xy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_x_y[i] = 4.0 * g_xyz_xy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_x_z[i] = 4.0 * g_xyz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (660-663)

    #pragma omp simd aligned(g_xyz_xy_y_x, g_xyz_xy_y_y, g_xyz_xy_y_z, g_yz_0_0_0_x_xy_y_x, g_yz_0_0_0_x_xy_y_y, g_yz_0_0_0_x_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xy_y_x[i] = 4.0 * g_xyz_xy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_y_y[i] = 4.0 * g_xyz_xy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_y_z[i] = 4.0 * g_xyz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (663-666)

    #pragma omp simd aligned(g_xyz_xy_z_x, g_xyz_xy_z_y, g_xyz_xy_z_z, g_yz_0_0_0_x_xy_z_x, g_yz_0_0_0_x_xy_z_y, g_yz_0_0_0_x_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xy_z_x[i] = 4.0 * g_xyz_xy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_z_y[i] = 4.0 * g_xyz_xy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xy_z_z[i] = 4.0 * g_xyz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (666-669)

    #pragma omp simd aligned(g_xyz_xz_x_x, g_xyz_xz_x_y, g_xyz_xz_x_z, g_yz_0_0_0_x_xz_x_x, g_yz_0_0_0_x_xz_x_y, g_yz_0_0_0_x_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xz_x_x[i] = 4.0 * g_xyz_xz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_x_y[i] = 4.0 * g_xyz_xz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_x_z[i] = 4.0 * g_xyz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (669-672)

    #pragma omp simd aligned(g_xyz_xz_y_x, g_xyz_xz_y_y, g_xyz_xz_y_z, g_yz_0_0_0_x_xz_y_x, g_yz_0_0_0_x_xz_y_y, g_yz_0_0_0_x_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xz_y_x[i] = 4.0 * g_xyz_xz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_y_y[i] = 4.0 * g_xyz_xz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_y_z[i] = 4.0 * g_xyz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (672-675)

    #pragma omp simd aligned(g_xyz_xz_z_x, g_xyz_xz_z_y, g_xyz_xz_z_z, g_yz_0_0_0_x_xz_z_x, g_yz_0_0_0_x_xz_z_y, g_yz_0_0_0_x_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_xz_z_x[i] = 4.0 * g_xyz_xz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_z_y[i] = 4.0 * g_xyz_xz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_xz_z_z[i] = 4.0 * g_xyz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (675-678)

    #pragma omp simd aligned(g_xyz_yy_x_x, g_xyz_yy_x_y, g_xyz_yy_x_z, g_yz_0_0_0_x_yy_x_x, g_yz_0_0_0_x_yy_x_y, g_yz_0_0_0_x_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yy_x_x[i] = 4.0 * g_xyz_yy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_x_y[i] = 4.0 * g_xyz_yy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_x_z[i] = 4.0 * g_xyz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (678-681)

    #pragma omp simd aligned(g_xyz_yy_y_x, g_xyz_yy_y_y, g_xyz_yy_y_z, g_yz_0_0_0_x_yy_y_x, g_yz_0_0_0_x_yy_y_y, g_yz_0_0_0_x_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yy_y_x[i] = 4.0 * g_xyz_yy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_y_y[i] = 4.0 * g_xyz_yy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_y_z[i] = 4.0 * g_xyz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (681-684)

    #pragma omp simd aligned(g_xyz_yy_z_x, g_xyz_yy_z_y, g_xyz_yy_z_z, g_yz_0_0_0_x_yy_z_x, g_yz_0_0_0_x_yy_z_y, g_yz_0_0_0_x_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yy_z_x[i] = 4.0 * g_xyz_yy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_z_y[i] = 4.0 * g_xyz_yy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yy_z_z[i] = 4.0 * g_xyz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (684-687)

    #pragma omp simd aligned(g_xyz_yz_x_x, g_xyz_yz_x_y, g_xyz_yz_x_z, g_yz_0_0_0_x_yz_x_x, g_yz_0_0_0_x_yz_x_y, g_yz_0_0_0_x_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yz_x_x[i] = 4.0 * g_xyz_yz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_x_y[i] = 4.0 * g_xyz_yz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_x_z[i] = 4.0 * g_xyz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (687-690)

    #pragma omp simd aligned(g_xyz_yz_y_x, g_xyz_yz_y_y, g_xyz_yz_y_z, g_yz_0_0_0_x_yz_y_x, g_yz_0_0_0_x_yz_y_y, g_yz_0_0_0_x_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yz_y_x[i] = 4.0 * g_xyz_yz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_y_y[i] = 4.0 * g_xyz_yz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_y_z[i] = 4.0 * g_xyz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (690-693)

    #pragma omp simd aligned(g_xyz_yz_z_x, g_xyz_yz_z_y, g_xyz_yz_z_z, g_yz_0_0_0_x_yz_z_x, g_yz_0_0_0_x_yz_z_y, g_yz_0_0_0_x_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_yz_z_x[i] = 4.0 * g_xyz_yz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_z_y[i] = 4.0 * g_xyz_yz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_yz_z_z[i] = 4.0 * g_xyz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (693-696)

    #pragma omp simd aligned(g_xyz_zz_x_x, g_xyz_zz_x_y, g_xyz_zz_x_z, g_yz_0_0_0_x_zz_x_x, g_yz_0_0_0_x_zz_x_y, g_yz_0_0_0_x_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_zz_x_x[i] = 4.0 * g_xyz_zz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_x_y[i] = 4.0 * g_xyz_zz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_x_z[i] = 4.0 * g_xyz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (696-699)

    #pragma omp simd aligned(g_xyz_zz_y_x, g_xyz_zz_y_y, g_xyz_zz_y_z, g_yz_0_0_0_x_zz_y_x, g_yz_0_0_0_x_zz_y_y, g_yz_0_0_0_x_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_zz_y_x[i] = 4.0 * g_xyz_zz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_y_y[i] = 4.0 * g_xyz_zz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_y_z[i] = 4.0 * g_xyz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (699-702)

    #pragma omp simd aligned(g_xyz_zz_z_x, g_xyz_zz_z_y, g_xyz_zz_z_z, g_yz_0_0_0_x_zz_z_x, g_yz_0_0_0_x_zz_z_y, g_yz_0_0_0_x_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_x_zz_z_x[i] = 4.0 * g_xyz_zz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_z_y[i] = 4.0 * g_xyz_zz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_x_zz_z_z[i] = 4.0 * g_xyz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (702-705)

    #pragma omp simd aligned(g_yyz_xx_x_x, g_yyz_xx_x_y, g_yyz_xx_x_z, g_yz_0_0_0_y_xx_x_x, g_yz_0_0_0_y_xx_x_y, g_yz_0_0_0_y_xx_x_z, g_z_xx_x_x, g_z_xx_x_y, g_z_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xx_x_x[i] = -2.0 * g_z_xx_x_x[i] * a_exp + 4.0 * g_yyz_xx_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_x_y[i] = -2.0 * g_z_xx_x_y[i] * a_exp + 4.0 * g_yyz_xx_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_x_z[i] = -2.0 * g_z_xx_x_z[i] * a_exp + 4.0 * g_yyz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (705-708)

    #pragma omp simd aligned(g_yyz_xx_y_x, g_yyz_xx_y_y, g_yyz_xx_y_z, g_yz_0_0_0_y_xx_y_x, g_yz_0_0_0_y_xx_y_y, g_yz_0_0_0_y_xx_y_z, g_z_xx_y_x, g_z_xx_y_y, g_z_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xx_y_x[i] = -2.0 * g_z_xx_y_x[i] * a_exp + 4.0 * g_yyz_xx_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_y_y[i] = -2.0 * g_z_xx_y_y[i] * a_exp + 4.0 * g_yyz_xx_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_y_z[i] = -2.0 * g_z_xx_y_z[i] * a_exp + 4.0 * g_yyz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (708-711)

    #pragma omp simd aligned(g_yyz_xx_z_x, g_yyz_xx_z_y, g_yyz_xx_z_z, g_yz_0_0_0_y_xx_z_x, g_yz_0_0_0_y_xx_z_y, g_yz_0_0_0_y_xx_z_z, g_z_xx_z_x, g_z_xx_z_y, g_z_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xx_z_x[i] = -2.0 * g_z_xx_z_x[i] * a_exp + 4.0 * g_yyz_xx_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_z_y[i] = -2.0 * g_z_xx_z_y[i] * a_exp + 4.0 * g_yyz_xx_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xx_z_z[i] = -2.0 * g_z_xx_z_z[i] * a_exp + 4.0 * g_yyz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (711-714)

    #pragma omp simd aligned(g_yyz_xy_x_x, g_yyz_xy_x_y, g_yyz_xy_x_z, g_yz_0_0_0_y_xy_x_x, g_yz_0_0_0_y_xy_x_y, g_yz_0_0_0_y_xy_x_z, g_z_xy_x_x, g_z_xy_x_y, g_z_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xy_x_x[i] = -2.0 * g_z_xy_x_x[i] * a_exp + 4.0 * g_yyz_xy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_x_y[i] = -2.0 * g_z_xy_x_y[i] * a_exp + 4.0 * g_yyz_xy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_x_z[i] = -2.0 * g_z_xy_x_z[i] * a_exp + 4.0 * g_yyz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (714-717)

    #pragma omp simd aligned(g_yyz_xy_y_x, g_yyz_xy_y_y, g_yyz_xy_y_z, g_yz_0_0_0_y_xy_y_x, g_yz_0_0_0_y_xy_y_y, g_yz_0_0_0_y_xy_y_z, g_z_xy_y_x, g_z_xy_y_y, g_z_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xy_y_x[i] = -2.0 * g_z_xy_y_x[i] * a_exp + 4.0 * g_yyz_xy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_y_y[i] = -2.0 * g_z_xy_y_y[i] * a_exp + 4.0 * g_yyz_xy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_y_z[i] = -2.0 * g_z_xy_y_z[i] * a_exp + 4.0 * g_yyz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (717-720)

    #pragma omp simd aligned(g_yyz_xy_z_x, g_yyz_xy_z_y, g_yyz_xy_z_z, g_yz_0_0_0_y_xy_z_x, g_yz_0_0_0_y_xy_z_y, g_yz_0_0_0_y_xy_z_z, g_z_xy_z_x, g_z_xy_z_y, g_z_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xy_z_x[i] = -2.0 * g_z_xy_z_x[i] * a_exp + 4.0 * g_yyz_xy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_z_y[i] = -2.0 * g_z_xy_z_y[i] * a_exp + 4.0 * g_yyz_xy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xy_z_z[i] = -2.0 * g_z_xy_z_z[i] * a_exp + 4.0 * g_yyz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (720-723)

    #pragma omp simd aligned(g_yyz_xz_x_x, g_yyz_xz_x_y, g_yyz_xz_x_z, g_yz_0_0_0_y_xz_x_x, g_yz_0_0_0_y_xz_x_y, g_yz_0_0_0_y_xz_x_z, g_z_xz_x_x, g_z_xz_x_y, g_z_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xz_x_x[i] = -2.0 * g_z_xz_x_x[i] * a_exp + 4.0 * g_yyz_xz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_x_y[i] = -2.0 * g_z_xz_x_y[i] * a_exp + 4.0 * g_yyz_xz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_x_z[i] = -2.0 * g_z_xz_x_z[i] * a_exp + 4.0 * g_yyz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (723-726)

    #pragma omp simd aligned(g_yyz_xz_y_x, g_yyz_xz_y_y, g_yyz_xz_y_z, g_yz_0_0_0_y_xz_y_x, g_yz_0_0_0_y_xz_y_y, g_yz_0_0_0_y_xz_y_z, g_z_xz_y_x, g_z_xz_y_y, g_z_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xz_y_x[i] = -2.0 * g_z_xz_y_x[i] * a_exp + 4.0 * g_yyz_xz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_y_y[i] = -2.0 * g_z_xz_y_y[i] * a_exp + 4.0 * g_yyz_xz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_y_z[i] = -2.0 * g_z_xz_y_z[i] * a_exp + 4.0 * g_yyz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (726-729)

    #pragma omp simd aligned(g_yyz_xz_z_x, g_yyz_xz_z_y, g_yyz_xz_z_z, g_yz_0_0_0_y_xz_z_x, g_yz_0_0_0_y_xz_z_y, g_yz_0_0_0_y_xz_z_z, g_z_xz_z_x, g_z_xz_z_y, g_z_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_xz_z_x[i] = -2.0 * g_z_xz_z_x[i] * a_exp + 4.0 * g_yyz_xz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_z_y[i] = -2.0 * g_z_xz_z_y[i] * a_exp + 4.0 * g_yyz_xz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_xz_z_z[i] = -2.0 * g_z_xz_z_z[i] * a_exp + 4.0 * g_yyz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (729-732)

    #pragma omp simd aligned(g_yyz_yy_x_x, g_yyz_yy_x_y, g_yyz_yy_x_z, g_yz_0_0_0_y_yy_x_x, g_yz_0_0_0_y_yy_x_y, g_yz_0_0_0_y_yy_x_z, g_z_yy_x_x, g_z_yy_x_y, g_z_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yy_x_x[i] = -2.0 * g_z_yy_x_x[i] * a_exp + 4.0 * g_yyz_yy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_x_y[i] = -2.0 * g_z_yy_x_y[i] * a_exp + 4.0 * g_yyz_yy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_x_z[i] = -2.0 * g_z_yy_x_z[i] * a_exp + 4.0 * g_yyz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (732-735)

    #pragma omp simd aligned(g_yyz_yy_y_x, g_yyz_yy_y_y, g_yyz_yy_y_z, g_yz_0_0_0_y_yy_y_x, g_yz_0_0_0_y_yy_y_y, g_yz_0_0_0_y_yy_y_z, g_z_yy_y_x, g_z_yy_y_y, g_z_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yy_y_x[i] = -2.0 * g_z_yy_y_x[i] * a_exp + 4.0 * g_yyz_yy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_y_y[i] = -2.0 * g_z_yy_y_y[i] * a_exp + 4.0 * g_yyz_yy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_y_z[i] = -2.0 * g_z_yy_y_z[i] * a_exp + 4.0 * g_yyz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (735-738)

    #pragma omp simd aligned(g_yyz_yy_z_x, g_yyz_yy_z_y, g_yyz_yy_z_z, g_yz_0_0_0_y_yy_z_x, g_yz_0_0_0_y_yy_z_y, g_yz_0_0_0_y_yy_z_z, g_z_yy_z_x, g_z_yy_z_y, g_z_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yy_z_x[i] = -2.0 * g_z_yy_z_x[i] * a_exp + 4.0 * g_yyz_yy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_z_y[i] = -2.0 * g_z_yy_z_y[i] * a_exp + 4.0 * g_yyz_yy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yy_z_z[i] = -2.0 * g_z_yy_z_z[i] * a_exp + 4.0 * g_yyz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (738-741)

    #pragma omp simd aligned(g_yyz_yz_x_x, g_yyz_yz_x_y, g_yyz_yz_x_z, g_yz_0_0_0_y_yz_x_x, g_yz_0_0_0_y_yz_x_y, g_yz_0_0_0_y_yz_x_z, g_z_yz_x_x, g_z_yz_x_y, g_z_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yz_x_x[i] = -2.0 * g_z_yz_x_x[i] * a_exp + 4.0 * g_yyz_yz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_x_y[i] = -2.0 * g_z_yz_x_y[i] * a_exp + 4.0 * g_yyz_yz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_x_z[i] = -2.0 * g_z_yz_x_z[i] * a_exp + 4.0 * g_yyz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (741-744)

    #pragma omp simd aligned(g_yyz_yz_y_x, g_yyz_yz_y_y, g_yyz_yz_y_z, g_yz_0_0_0_y_yz_y_x, g_yz_0_0_0_y_yz_y_y, g_yz_0_0_0_y_yz_y_z, g_z_yz_y_x, g_z_yz_y_y, g_z_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yz_y_x[i] = -2.0 * g_z_yz_y_x[i] * a_exp + 4.0 * g_yyz_yz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_y_y[i] = -2.0 * g_z_yz_y_y[i] * a_exp + 4.0 * g_yyz_yz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_y_z[i] = -2.0 * g_z_yz_y_z[i] * a_exp + 4.0 * g_yyz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (744-747)

    #pragma omp simd aligned(g_yyz_yz_z_x, g_yyz_yz_z_y, g_yyz_yz_z_z, g_yz_0_0_0_y_yz_z_x, g_yz_0_0_0_y_yz_z_y, g_yz_0_0_0_y_yz_z_z, g_z_yz_z_x, g_z_yz_z_y, g_z_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_yz_z_x[i] = -2.0 * g_z_yz_z_x[i] * a_exp + 4.0 * g_yyz_yz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_z_y[i] = -2.0 * g_z_yz_z_y[i] * a_exp + 4.0 * g_yyz_yz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_yz_z_z[i] = -2.0 * g_z_yz_z_z[i] * a_exp + 4.0 * g_yyz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (747-750)

    #pragma omp simd aligned(g_yyz_zz_x_x, g_yyz_zz_x_y, g_yyz_zz_x_z, g_yz_0_0_0_y_zz_x_x, g_yz_0_0_0_y_zz_x_y, g_yz_0_0_0_y_zz_x_z, g_z_zz_x_x, g_z_zz_x_y, g_z_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_zz_x_x[i] = -2.0 * g_z_zz_x_x[i] * a_exp + 4.0 * g_yyz_zz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_x_y[i] = -2.0 * g_z_zz_x_y[i] * a_exp + 4.0 * g_yyz_zz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_x_z[i] = -2.0 * g_z_zz_x_z[i] * a_exp + 4.0 * g_yyz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (750-753)

    #pragma omp simd aligned(g_yyz_zz_y_x, g_yyz_zz_y_y, g_yyz_zz_y_z, g_yz_0_0_0_y_zz_y_x, g_yz_0_0_0_y_zz_y_y, g_yz_0_0_0_y_zz_y_z, g_z_zz_y_x, g_z_zz_y_y, g_z_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_zz_y_x[i] = -2.0 * g_z_zz_y_x[i] * a_exp + 4.0 * g_yyz_zz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_y_y[i] = -2.0 * g_z_zz_y_y[i] * a_exp + 4.0 * g_yyz_zz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_y_z[i] = -2.0 * g_z_zz_y_z[i] * a_exp + 4.0 * g_yyz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (753-756)

    #pragma omp simd aligned(g_yyz_zz_z_x, g_yyz_zz_z_y, g_yyz_zz_z_z, g_yz_0_0_0_y_zz_z_x, g_yz_0_0_0_y_zz_z_y, g_yz_0_0_0_y_zz_z_z, g_z_zz_z_x, g_z_zz_z_y, g_z_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_y_zz_z_x[i] = -2.0 * g_z_zz_z_x[i] * a_exp + 4.0 * g_yyz_zz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_z_y[i] = -2.0 * g_z_zz_z_y[i] * a_exp + 4.0 * g_yyz_zz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_y_zz_z_z[i] = -2.0 * g_z_zz_z_z[i] * a_exp + 4.0 * g_yyz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (756-759)

    #pragma omp simd aligned(g_y_xx_x_x, g_y_xx_x_y, g_y_xx_x_z, g_yz_0_0_0_z_xx_x_x, g_yz_0_0_0_z_xx_x_y, g_yz_0_0_0_z_xx_x_z, g_yzz_xx_x_x, g_yzz_xx_x_y, g_yzz_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xx_x_x[i] = -2.0 * g_y_xx_x_x[i] * a_exp + 4.0 * g_yzz_xx_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_x_y[i] = -2.0 * g_y_xx_x_y[i] * a_exp + 4.0 * g_yzz_xx_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_x_z[i] = -2.0 * g_y_xx_x_z[i] * a_exp + 4.0 * g_yzz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (759-762)

    #pragma omp simd aligned(g_y_xx_y_x, g_y_xx_y_y, g_y_xx_y_z, g_yz_0_0_0_z_xx_y_x, g_yz_0_0_0_z_xx_y_y, g_yz_0_0_0_z_xx_y_z, g_yzz_xx_y_x, g_yzz_xx_y_y, g_yzz_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xx_y_x[i] = -2.0 * g_y_xx_y_x[i] * a_exp + 4.0 * g_yzz_xx_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_y_y[i] = -2.0 * g_y_xx_y_y[i] * a_exp + 4.0 * g_yzz_xx_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_y_z[i] = -2.0 * g_y_xx_y_z[i] * a_exp + 4.0 * g_yzz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (762-765)

    #pragma omp simd aligned(g_y_xx_z_x, g_y_xx_z_y, g_y_xx_z_z, g_yz_0_0_0_z_xx_z_x, g_yz_0_0_0_z_xx_z_y, g_yz_0_0_0_z_xx_z_z, g_yzz_xx_z_x, g_yzz_xx_z_y, g_yzz_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xx_z_x[i] = -2.0 * g_y_xx_z_x[i] * a_exp + 4.0 * g_yzz_xx_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_z_y[i] = -2.0 * g_y_xx_z_y[i] * a_exp + 4.0 * g_yzz_xx_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xx_z_z[i] = -2.0 * g_y_xx_z_z[i] * a_exp + 4.0 * g_yzz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (765-768)

    #pragma omp simd aligned(g_y_xy_x_x, g_y_xy_x_y, g_y_xy_x_z, g_yz_0_0_0_z_xy_x_x, g_yz_0_0_0_z_xy_x_y, g_yz_0_0_0_z_xy_x_z, g_yzz_xy_x_x, g_yzz_xy_x_y, g_yzz_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xy_x_x[i] = -2.0 * g_y_xy_x_x[i] * a_exp + 4.0 * g_yzz_xy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_x_y[i] = -2.0 * g_y_xy_x_y[i] * a_exp + 4.0 * g_yzz_xy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_x_z[i] = -2.0 * g_y_xy_x_z[i] * a_exp + 4.0 * g_yzz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (768-771)

    #pragma omp simd aligned(g_y_xy_y_x, g_y_xy_y_y, g_y_xy_y_z, g_yz_0_0_0_z_xy_y_x, g_yz_0_0_0_z_xy_y_y, g_yz_0_0_0_z_xy_y_z, g_yzz_xy_y_x, g_yzz_xy_y_y, g_yzz_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xy_y_x[i] = -2.0 * g_y_xy_y_x[i] * a_exp + 4.0 * g_yzz_xy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_y_y[i] = -2.0 * g_y_xy_y_y[i] * a_exp + 4.0 * g_yzz_xy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_y_z[i] = -2.0 * g_y_xy_y_z[i] * a_exp + 4.0 * g_yzz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (771-774)

    #pragma omp simd aligned(g_y_xy_z_x, g_y_xy_z_y, g_y_xy_z_z, g_yz_0_0_0_z_xy_z_x, g_yz_0_0_0_z_xy_z_y, g_yz_0_0_0_z_xy_z_z, g_yzz_xy_z_x, g_yzz_xy_z_y, g_yzz_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xy_z_x[i] = -2.0 * g_y_xy_z_x[i] * a_exp + 4.0 * g_yzz_xy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_z_y[i] = -2.0 * g_y_xy_z_y[i] * a_exp + 4.0 * g_yzz_xy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xy_z_z[i] = -2.0 * g_y_xy_z_z[i] * a_exp + 4.0 * g_yzz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (774-777)

    #pragma omp simd aligned(g_y_xz_x_x, g_y_xz_x_y, g_y_xz_x_z, g_yz_0_0_0_z_xz_x_x, g_yz_0_0_0_z_xz_x_y, g_yz_0_0_0_z_xz_x_z, g_yzz_xz_x_x, g_yzz_xz_x_y, g_yzz_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xz_x_x[i] = -2.0 * g_y_xz_x_x[i] * a_exp + 4.0 * g_yzz_xz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_x_y[i] = -2.0 * g_y_xz_x_y[i] * a_exp + 4.0 * g_yzz_xz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_x_z[i] = -2.0 * g_y_xz_x_z[i] * a_exp + 4.0 * g_yzz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (777-780)

    #pragma omp simd aligned(g_y_xz_y_x, g_y_xz_y_y, g_y_xz_y_z, g_yz_0_0_0_z_xz_y_x, g_yz_0_0_0_z_xz_y_y, g_yz_0_0_0_z_xz_y_z, g_yzz_xz_y_x, g_yzz_xz_y_y, g_yzz_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xz_y_x[i] = -2.0 * g_y_xz_y_x[i] * a_exp + 4.0 * g_yzz_xz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_y_y[i] = -2.0 * g_y_xz_y_y[i] * a_exp + 4.0 * g_yzz_xz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_y_z[i] = -2.0 * g_y_xz_y_z[i] * a_exp + 4.0 * g_yzz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (780-783)

    #pragma omp simd aligned(g_y_xz_z_x, g_y_xz_z_y, g_y_xz_z_z, g_yz_0_0_0_z_xz_z_x, g_yz_0_0_0_z_xz_z_y, g_yz_0_0_0_z_xz_z_z, g_yzz_xz_z_x, g_yzz_xz_z_y, g_yzz_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_xz_z_x[i] = -2.0 * g_y_xz_z_x[i] * a_exp + 4.0 * g_yzz_xz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_z_y[i] = -2.0 * g_y_xz_z_y[i] * a_exp + 4.0 * g_yzz_xz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_xz_z_z[i] = -2.0 * g_y_xz_z_z[i] * a_exp + 4.0 * g_yzz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (783-786)

    #pragma omp simd aligned(g_y_yy_x_x, g_y_yy_x_y, g_y_yy_x_z, g_yz_0_0_0_z_yy_x_x, g_yz_0_0_0_z_yy_x_y, g_yz_0_0_0_z_yy_x_z, g_yzz_yy_x_x, g_yzz_yy_x_y, g_yzz_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yy_x_x[i] = -2.0 * g_y_yy_x_x[i] * a_exp + 4.0 * g_yzz_yy_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_x_y[i] = -2.0 * g_y_yy_x_y[i] * a_exp + 4.0 * g_yzz_yy_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_x_z[i] = -2.0 * g_y_yy_x_z[i] * a_exp + 4.0 * g_yzz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (786-789)

    #pragma omp simd aligned(g_y_yy_y_x, g_y_yy_y_y, g_y_yy_y_z, g_yz_0_0_0_z_yy_y_x, g_yz_0_0_0_z_yy_y_y, g_yz_0_0_0_z_yy_y_z, g_yzz_yy_y_x, g_yzz_yy_y_y, g_yzz_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yy_y_x[i] = -2.0 * g_y_yy_y_x[i] * a_exp + 4.0 * g_yzz_yy_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_y_y[i] = -2.0 * g_y_yy_y_y[i] * a_exp + 4.0 * g_yzz_yy_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_y_z[i] = -2.0 * g_y_yy_y_z[i] * a_exp + 4.0 * g_yzz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (789-792)

    #pragma omp simd aligned(g_y_yy_z_x, g_y_yy_z_y, g_y_yy_z_z, g_yz_0_0_0_z_yy_z_x, g_yz_0_0_0_z_yy_z_y, g_yz_0_0_0_z_yy_z_z, g_yzz_yy_z_x, g_yzz_yy_z_y, g_yzz_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yy_z_x[i] = -2.0 * g_y_yy_z_x[i] * a_exp + 4.0 * g_yzz_yy_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_z_y[i] = -2.0 * g_y_yy_z_y[i] * a_exp + 4.0 * g_yzz_yy_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yy_z_z[i] = -2.0 * g_y_yy_z_z[i] * a_exp + 4.0 * g_yzz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (792-795)

    #pragma omp simd aligned(g_y_yz_x_x, g_y_yz_x_y, g_y_yz_x_z, g_yz_0_0_0_z_yz_x_x, g_yz_0_0_0_z_yz_x_y, g_yz_0_0_0_z_yz_x_z, g_yzz_yz_x_x, g_yzz_yz_x_y, g_yzz_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yz_x_x[i] = -2.0 * g_y_yz_x_x[i] * a_exp + 4.0 * g_yzz_yz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_x_y[i] = -2.0 * g_y_yz_x_y[i] * a_exp + 4.0 * g_yzz_yz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_x_z[i] = -2.0 * g_y_yz_x_z[i] * a_exp + 4.0 * g_yzz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (795-798)

    #pragma omp simd aligned(g_y_yz_y_x, g_y_yz_y_y, g_y_yz_y_z, g_yz_0_0_0_z_yz_y_x, g_yz_0_0_0_z_yz_y_y, g_yz_0_0_0_z_yz_y_z, g_yzz_yz_y_x, g_yzz_yz_y_y, g_yzz_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yz_y_x[i] = -2.0 * g_y_yz_y_x[i] * a_exp + 4.0 * g_yzz_yz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_y_y[i] = -2.0 * g_y_yz_y_y[i] * a_exp + 4.0 * g_yzz_yz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_y_z[i] = -2.0 * g_y_yz_y_z[i] * a_exp + 4.0 * g_yzz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (798-801)

    #pragma omp simd aligned(g_y_yz_z_x, g_y_yz_z_y, g_y_yz_z_z, g_yz_0_0_0_z_yz_z_x, g_yz_0_0_0_z_yz_z_y, g_yz_0_0_0_z_yz_z_z, g_yzz_yz_z_x, g_yzz_yz_z_y, g_yzz_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_yz_z_x[i] = -2.0 * g_y_yz_z_x[i] * a_exp + 4.0 * g_yzz_yz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_z_y[i] = -2.0 * g_y_yz_z_y[i] * a_exp + 4.0 * g_yzz_yz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_yz_z_z[i] = -2.0 * g_y_yz_z_z[i] * a_exp + 4.0 * g_yzz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (801-804)

    #pragma omp simd aligned(g_y_zz_x_x, g_y_zz_x_y, g_y_zz_x_z, g_yz_0_0_0_z_zz_x_x, g_yz_0_0_0_z_zz_x_y, g_yz_0_0_0_z_zz_x_z, g_yzz_zz_x_x, g_yzz_zz_x_y, g_yzz_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_zz_x_x[i] = -2.0 * g_y_zz_x_x[i] * a_exp + 4.0 * g_yzz_zz_x_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_x_y[i] = -2.0 * g_y_zz_x_y[i] * a_exp + 4.0 * g_yzz_zz_x_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_x_z[i] = -2.0 * g_y_zz_x_z[i] * a_exp + 4.0 * g_yzz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (804-807)

    #pragma omp simd aligned(g_y_zz_y_x, g_y_zz_y_y, g_y_zz_y_z, g_yz_0_0_0_z_zz_y_x, g_yz_0_0_0_z_zz_y_y, g_yz_0_0_0_z_zz_y_z, g_yzz_zz_y_x, g_yzz_zz_y_y, g_yzz_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_zz_y_x[i] = -2.0 * g_y_zz_y_x[i] * a_exp + 4.0 * g_yzz_zz_y_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_y_y[i] = -2.0 * g_y_zz_y_y[i] * a_exp + 4.0 * g_yzz_zz_y_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_y_z[i] = -2.0 * g_y_zz_y_z[i] * a_exp + 4.0 * g_yzz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (807-810)

    #pragma omp simd aligned(g_y_zz_z_x, g_y_zz_z_y, g_y_zz_z_z, g_yz_0_0_0_z_zz_z_x, g_yz_0_0_0_z_zz_z_y, g_yz_0_0_0_z_zz_z_z, g_yzz_zz_z_x, g_yzz_zz_z_y, g_yzz_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_z_zz_z_x[i] = -2.0 * g_y_zz_z_x[i] * a_exp + 4.0 * g_yzz_zz_z_x[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_z_y[i] = -2.0 * g_y_zz_z_y[i] * a_exp + 4.0 * g_yzz_zz_z_y[i] * a_exp * a_exp;

        g_yz_0_0_0_z_zz_z_z[i] = -2.0 * g_y_zz_z_z[i] * a_exp + 4.0 * g_yzz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (810-813)

    #pragma omp simd aligned(g_x_xx_x_x, g_x_xx_x_y, g_x_xx_x_z, g_xzz_xx_x_x, g_xzz_xx_x_y, g_xzz_xx_x_z, g_zz_0_0_0_x_xx_x_x, g_zz_0_0_0_x_xx_x_y, g_zz_0_0_0_x_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xx_x_x[i] = -2.0 * g_x_xx_x_x[i] * a_exp + 4.0 * g_xzz_xx_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_x_y[i] = -2.0 * g_x_xx_x_y[i] * a_exp + 4.0 * g_xzz_xx_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_x_z[i] = -2.0 * g_x_xx_x_z[i] * a_exp + 4.0 * g_xzz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (813-816)

    #pragma omp simd aligned(g_x_xx_y_x, g_x_xx_y_y, g_x_xx_y_z, g_xzz_xx_y_x, g_xzz_xx_y_y, g_xzz_xx_y_z, g_zz_0_0_0_x_xx_y_x, g_zz_0_0_0_x_xx_y_y, g_zz_0_0_0_x_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xx_y_x[i] = -2.0 * g_x_xx_y_x[i] * a_exp + 4.0 * g_xzz_xx_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_y_y[i] = -2.0 * g_x_xx_y_y[i] * a_exp + 4.0 * g_xzz_xx_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_y_z[i] = -2.0 * g_x_xx_y_z[i] * a_exp + 4.0 * g_xzz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (816-819)

    #pragma omp simd aligned(g_x_xx_z_x, g_x_xx_z_y, g_x_xx_z_z, g_xzz_xx_z_x, g_xzz_xx_z_y, g_xzz_xx_z_z, g_zz_0_0_0_x_xx_z_x, g_zz_0_0_0_x_xx_z_y, g_zz_0_0_0_x_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xx_z_x[i] = -2.0 * g_x_xx_z_x[i] * a_exp + 4.0 * g_xzz_xx_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_z_y[i] = -2.0 * g_x_xx_z_y[i] * a_exp + 4.0 * g_xzz_xx_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xx_z_z[i] = -2.0 * g_x_xx_z_z[i] * a_exp + 4.0 * g_xzz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (819-822)

    #pragma omp simd aligned(g_x_xy_x_x, g_x_xy_x_y, g_x_xy_x_z, g_xzz_xy_x_x, g_xzz_xy_x_y, g_xzz_xy_x_z, g_zz_0_0_0_x_xy_x_x, g_zz_0_0_0_x_xy_x_y, g_zz_0_0_0_x_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xy_x_x[i] = -2.0 * g_x_xy_x_x[i] * a_exp + 4.0 * g_xzz_xy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_x_y[i] = -2.0 * g_x_xy_x_y[i] * a_exp + 4.0 * g_xzz_xy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_x_z[i] = -2.0 * g_x_xy_x_z[i] * a_exp + 4.0 * g_xzz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (822-825)

    #pragma omp simd aligned(g_x_xy_y_x, g_x_xy_y_y, g_x_xy_y_z, g_xzz_xy_y_x, g_xzz_xy_y_y, g_xzz_xy_y_z, g_zz_0_0_0_x_xy_y_x, g_zz_0_0_0_x_xy_y_y, g_zz_0_0_0_x_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xy_y_x[i] = -2.0 * g_x_xy_y_x[i] * a_exp + 4.0 * g_xzz_xy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_y_y[i] = -2.0 * g_x_xy_y_y[i] * a_exp + 4.0 * g_xzz_xy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_y_z[i] = -2.0 * g_x_xy_y_z[i] * a_exp + 4.0 * g_xzz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (825-828)

    #pragma omp simd aligned(g_x_xy_z_x, g_x_xy_z_y, g_x_xy_z_z, g_xzz_xy_z_x, g_xzz_xy_z_y, g_xzz_xy_z_z, g_zz_0_0_0_x_xy_z_x, g_zz_0_0_0_x_xy_z_y, g_zz_0_0_0_x_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xy_z_x[i] = -2.0 * g_x_xy_z_x[i] * a_exp + 4.0 * g_xzz_xy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_z_y[i] = -2.0 * g_x_xy_z_y[i] * a_exp + 4.0 * g_xzz_xy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xy_z_z[i] = -2.0 * g_x_xy_z_z[i] * a_exp + 4.0 * g_xzz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (828-831)

    #pragma omp simd aligned(g_x_xz_x_x, g_x_xz_x_y, g_x_xz_x_z, g_xzz_xz_x_x, g_xzz_xz_x_y, g_xzz_xz_x_z, g_zz_0_0_0_x_xz_x_x, g_zz_0_0_0_x_xz_x_y, g_zz_0_0_0_x_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xz_x_x[i] = -2.0 * g_x_xz_x_x[i] * a_exp + 4.0 * g_xzz_xz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_x_y[i] = -2.0 * g_x_xz_x_y[i] * a_exp + 4.0 * g_xzz_xz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_x_z[i] = -2.0 * g_x_xz_x_z[i] * a_exp + 4.0 * g_xzz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (831-834)

    #pragma omp simd aligned(g_x_xz_y_x, g_x_xz_y_y, g_x_xz_y_z, g_xzz_xz_y_x, g_xzz_xz_y_y, g_xzz_xz_y_z, g_zz_0_0_0_x_xz_y_x, g_zz_0_0_0_x_xz_y_y, g_zz_0_0_0_x_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xz_y_x[i] = -2.0 * g_x_xz_y_x[i] * a_exp + 4.0 * g_xzz_xz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_y_y[i] = -2.0 * g_x_xz_y_y[i] * a_exp + 4.0 * g_xzz_xz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_y_z[i] = -2.0 * g_x_xz_y_z[i] * a_exp + 4.0 * g_xzz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (834-837)

    #pragma omp simd aligned(g_x_xz_z_x, g_x_xz_z_y, g_x_xz_z_z, g_xzz_xz_z_x, g_xzz_xz_z_y, g_xzz_xz_z_z, g_zz_0_0_0_x_xz_z_x, g_zz_0_0_0_x_xz_z_y, g_zz_0_0_0_x_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_xz_z_x[i] = -2.0 * g_x_xz_z_x[i] * a_exp + 4.0 * g_xzz_xz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_z_y[i] = -2.0 * g_x_xz_z_y[i] * a_exp + 4.0 * g_xzz_xz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_xz_z_z[i] = -2.0 * g_x_xz_z_z[i] * a_exp + 4.0 * g_xzz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (837-840)

    #pragma omp simd aligned(g_x_yy_x_x, g_x_yy_x_y, g_x_yy_x_z, g_xzz_yy_x_x, g_xzz_yy_x_y, g_xzz_yy_x_z, g_zz_0_0_0_x_yy_x_x, g_zz_0_0_0_x_yy_x_y, g_zz_0_0_0_x_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yy_x_x[i] = -2.0 * g_x_yy_x_x[i] * a_exp + 4.0 * g_xzz_yy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_x_y[i] = -2.0 * g_x_yy_x_y[i] * a_exp + 4.0 * g_xzz_yy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_x_z[i] = -2.0 * g_x_yy_x_z[i] * a_exp + 4.0 * g_xzz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (840-843)

    #pragma omp simd aligned(g_x_yy_y_x, g_x_yy_y_y, g_x_yy_y_z, g_xzz_yy_y_x, g_xzz_yy_y_y, g_xzz_yy_y_z, g_zz_0_0_0_x_yy_y_x, g_zz_0_0_0_x_yy_y_y, g_zz_0_0_0_x_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yy_y_x[i] = -2.0 * g_x_yy_y_x[i] * a_exp + 4.0 * g_xzz_yy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_y_y[i] = -2.0 * g_x_yy_y_y[i] * a_exp + 4.0 * g_xzz_yy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_y_z[i] = -2.0 * g_x_yy_y_z[i] * a_exp + 4.0 * g_xzz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (843-846)

    #pragma omp simd aligned(g_x_yy_z_x, g_x_yy_z_y, g_x_yy_z_z, g_xzz_yy_z_x, g_xzz_yy_z_y, g_xzz_yy_z_z, g_zz_0_0_0_x_yy_z_x, g_zz_0_0_0_x_yy_z_y, g_zz_0_0_0_x_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yy_z_x[i] = -2.0 * g_x_yy_z_x[i] * a_exp + 4.0 * g_xzz_yy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_z_y[i] = -2.0 * g_x_yy_z_y[i] * a_exp + 4.0 * g_xzz_yy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yy_z_z[i] = -2.0 * g_x_yy_z_z[i] * a_exp + 4.0 * g_xzz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (846-849)

    #pragma omp simd aligned(g_x_yz_x_x, g_x_yz_x_y, g_x_yz_x_z, g_xzz_yz_x_x, g_xzz_yz_x_y, g_xzz_yz_x_z, g_zz_0_0_0_x_yz_x_x, g_zz_0_0_0_x_yz_x_y, g_zz_0_0_0_x_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yz_x_x[i] = -2.0 * g_x_yz_x_x[i] * a_exp + 4.0 * g_xzz_yz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_x_y[i] = -2.0 * g_x_yz_x_y[i] * a_exp + 4.0 * g_xzz_yz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_x_z[i] = -2.0 * g_x_yz_x_z[i] * a_exp + 4.0 * g_xzz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (849-852)

    #pragma omp simd aligned(g_x_yz_y_x, g_x_yz_y_y, g_x_yz_y_z, g_xzz_yz_y_x, g_xzz_yz_y_y, g_xzz_yz_y_z, g_zz_0_0_0_x_yz_y_x, g_zz_0_0_0_x_yz_y_y, g_zz_0_0_0_x_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yz_y_x[i] = -2.0 * g_x_yz_y_x[i] * a_exp + 4.0 * g_xzz_yz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_y_y[i] = -2.0 * g_x_yz_y_y[i] * a_exp + 4.0 * g_xzz_yz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_y_z[i] = -2.0 * g_x_yz_y_z[i] * a_exp + 4.0 * g_xzz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (852-855)

    #pragma omp simd aligned(g_x_yz_z_x, g_x_yz_z_y, g_x_yz_z_z, g_xzz_yz_z_x, g_xzz_yz_z_y, g_xzz_yz_z_z, g_zz_0_0_0_x_yz_z_x, g_zz_0_0_0_x_yz_z_y, g_zz_0_0_0_x_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_yz_z_x[i] = -2.0 * g_x_yz_z_x[i] * a_exp + 4.0 * g_xzz_yz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_z_y[i] = -2.0 * g_x_yz_z_y[i] * a_exp + 4.0 * g_xzz_yz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_yz_z_z[i] = -2.0 * g_x_yz_z_z[i] * a_exp + 4.0 * g_xzz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (855-858)

    #pragma omp simd aligned(g_x_zz_x_x, g_x_zz_x_y, g_x_zz_x_z, g_xzz_zz_x_x, g_xzz_zz_x_y, g_xzz_zz_x_z, g_zz_0_0_0_x_zz_x_x, g_zz_0_0_0_x_zz_x_y, g_zz_0_0_0_x_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_zz_x_x[i] = -2.0 * g_x_zz_x_x[i] * a_exp + 4.0 * g_xzz_zz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_x_y[i] = -2.0 * g_x_zz_x_y[i] * a_exp + 4.0 * g_xzz_zz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_x_z[i] = -2.0 * g_x_zz_x_z[i] * a_exp + 4.0 * g_xzz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (858-861)

    #pragma omp simd aligned(g_x_zz_y_x, g_x_zz_y_y, g_x_zz_y_z, g_xzz_zz_y_x, g_xzz_zz_y_y, g_xzz_zz_y_z, g_zz_0_0_0_x_zz_y_x, g_zz_0_0_0_x_zz_y_y, g_zz_0_0_0_x_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_zz_y_x[i] = -2.0 * g_x_zz_y_x[i] * a_exp + 4.0 * g_xzz_zz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_y_y[i] = -2.0 * g_x_zz_y_y[i] * a_exp + 4.0 * g_xzz_zz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_y_z[i] = -2.0 * g_x_zz_y_z[i] * a_exp + 4.0 * g_xzz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (861-864)

    #pragma omp simd aligned(g_x_zz_z_x, g_x_zz_z_y, g_x_zz_z_z, g_xzz_zz_z_x, g_xzz_zz_z_y, g_xzz_zz_z_z, g_zz_0_0_0_x_zz_z_x, g_zz_0_0_0_x_zz_z_y, g_zz_0_0_0_x_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_x_zz_z_x[i] = -2.0 * g_x_zz_z_x[i] * a_exp + 4.0 * g_xzz_zz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_z_y[i] = -2.0 * g_x_zz_z_y[i] * a_exp + 4.0 * g_xzz_zz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_x_zz_z_z[i] = -2.0 * g_x_zz_z_z[i] * a_exp + 4.0 * g_xzz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (864-867)

    #pragma omp simd aligned(g_y_xx_x_x, g_y_xx_x_y, g_y_xx_x_z, g_yzz_xx_x_x, g_yzz_xx_x_y, g_yzz_xx_x_z, g_zz_0_0_0_y_xx_x_x, g_zz_0_0_0_y_xx_x_y, g_zz_0_0_0_y_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xx_x_x[i] = -2.0 * g_y_xx_x_x[i] * a_exp + 4.0 * g_yzz_xx_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_x_y[i] = -2.0 * g_y_xx_x_y[i] * a_exp + 4.0 * g_yzz_xx_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_x_z[i] = -2.0 * g_y_xx_x_z[i] * a_exp + 4.0 * g_yzz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (867-870)

    #pragma omp simd aligned(g_y_xx_y_x, g_y_xx_y_y, g_y_xx_y_z, g_yzz_xx_y_x, g_yzz_xx_y_y, g_yzz_xx_y_z, g_zz_0_0_0_y_xx_y_x, g_zz_0_0_0_y_xx_y_y, g_zz_0_0_0_y_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xx_y_x[i] = -2.0 * g_y_xx_y_x[i] * a_exp + 4.0 * g_yzz_xx_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_y_y[i] = -2.0 * g_y_xx_y_y[i] * a_exp + 4.0 * g_yzz_xx_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_y_z[i] = -2.0 * g_y_xx_y_z[i] * a_exp + 4.0 * g_yzz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (870-873)

    #pragma omp simd aligned(g_y_xx_z_x, g_y_xx_z_y, g_y_xx_z_z, g_yzz_xx_z_x, g_yzz_xx_z_y, g_yzz_xx_z_z, g_zz_0_0_0_y_xx_z_x, g_zz_0_0_0_y_xx_z_y, g_zz_0_0_0_y_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xx_z_x[i] = -2.0 * g_y_xx_z_x[i] * a_exp + 4.0 * g_yzz_xx_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_z_y[i] = -2.0 * g_y_xx_z_y[i] * a_exp + 4.0 * g_yzz_xx_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xx_z_z[i] = -2.0 * g_y_xx_z_z[i] * a_exp + 4.0 * g_yzz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (873-876)

    #pragma omp simd aligned(g_y_xy_x_x, g_y_xy_x_y, g_y_xy_x_z, g_yzz_xy_x_x, g_yzz_xy_x_y, g_yzz_xy_x_z, g_zz_0_0_0_y_xy_x_x, g_zz_0_0_0_y_xy_x_y, g_zz_0_0_0_y_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xy_x_x[i] = -2.0 * g_y_xy_x_x[i] * a_exp + 4.0 * g_yzz_xy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_x_y[i] = -2.0 * g_y_xy_x_y[i] * a_exp + 4.0 * g_yzz_xy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_x_z[i] = -2.0 * g_y_xy_x_z[i] * a_exp + 4.0 * g_yzz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (876-879)

    #pragma omp simd aligned(g_y_xy_y_x, g_y_xy_y_y, g_y_xy_y_z, g_yzz_xy_y_x, g_yzz_xy_y_y, g_yzz_xy_y_z, g_zz_0_0_0_y_xy_y_x, g_zz_0_0_0_y_xy_y_y, g_zz_0_0_0_y_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xy_y_x[i] = -2.0 * g_y_xy_y_x[i] * a_exp + 4.0 * g_yzz_xy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_y_y[i] = -2.0 * g_y_xy_y_y[i] * a_exp + 4.0 * g_yzz_xy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_y_z[i] = -2.0 * g_y_xy_y_z[i] * a_exp + 4.0 * g_yzz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (879-882)

    #pragma omp simd aligned(g_y_xy_z_x, g_y_xy_z_y, g_y_xy_z_z, g_yzz_xy_z_x, g_yzz_xy_z_y, g_yzz_xy_z_z, g_zz_0_0_0_y_xy_z_x, g_zz_0_0_0_y_xy_z_y, g_zz_0_0_0_y_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xy_z_x[i] = -2.0 * g_y_xy_z_x[i] * a_exp + 4.0 * g_yzz_xy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_z_y[i] = -2.0 * g_y_xy_z_y[i] * a_exp + 4.0 * g_yzz_xy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xy_z_z[i] = -2.0 * g_y_xy_z_z[i] * a_exp + 4.0 * g_yzz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (882-885)

    #pragma omp simd aligned(g_y_xz_x_x, g_y_xz_x_y, g_y_xz_x_z, g_yzz_xz_x_x, g_yzz_xz_x_y, g_yzz_xz_x_z, g_zz_0_0_0_y_xz_x_x, g_zz_0_0_0_y_xz_x_y, g_zz_0_0_0_y_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xz_x_x[i] = -2.0 * g_y_xz_x_x[i] * a_exp + 4.0 * g_yzz_xz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_x_y[i] = -2.0 * g_y_xz_x_y[i] * a_exp + 4.0 * g_yzz_xz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_x_z[i] = -2.0 * g_y_xz_x_z[i] * a_exp + 4.0 * g_yzz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (885-888)

    #pragma omp simd aligned(g_y_xz_y_x, g_y_xz_y_y, g_y_xz_y_z, g_yzz_xz_y_x, g_yzz_xz_y_y, g_yzz_xz_y_z, g_zz_0_0_0_y_xz_y_x, g_zz_0_0_0_y_xz_y_y, g_zz_0_0_0_y_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xz_y_x[i] = -2.0 * g_y_xz_y_x[i] * a_exp + 4.0 * g_yzz_xz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_y_y[i] = -2.0 * g_y_xz_y_y[i] * a_exp + 4.0 * g_yzz_xz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_y_z[i] = -2.0 * g_y_xz_y_z[i] * a_exp + 4.0 * g_yzz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (888-891)

    #pragma omp simd aligned(g_y_xz_z_x, g_y_xz_z_y, g_y_xz_z_z, g_yzz_xz_z_x, g_yzz_xz_z_y, g_yzz_xz_z_z, g_zz_0_0_0_y_xz_z_x, g_zz_0_0_0_y_xz_z_y, g_zz_0_0_0_y_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_xz_z_x[i] = -2.0 * g_y_xz_z_x[i] * a_exp + 4.0 * g_yzz_xz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_z_y[i] = -2.0 * g_y_xz_z_y[i] * a_exp + 4.0 * g_yzz_xz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_xz_z_z[i] = -2.0 * g_y_xz_z_z[i] * a_exp + 4.0 * g_yzz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (891-894)

    #pragma omp simd aligned(g_y_yy_x_x, g_y_yy_x_y, g_y_yy_x_z, g_yzz_yy_x_x, g_yzz_yy_x_y, g_yzz_yy_x_z, g_zz_0_0_0_y_yy_x_x, g_zz_0_0_0_y_yy_x_y, g_zz_0_0_0_y_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yy_x_x[i] = -2.0 * g_y_yy_x_x[i] * a_exp + 4.0 * g_yzz_yy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_x_y[i] = -2.0 * g_y_yy_x_y[i] * a_exp + 4.0 * g_yzz_yy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_x_z[i] = -2.0 * g_y_yy_x_z[i] * a_exp + 4.0 * g_yzz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (894-897)

    #pragma omp simd aligned(g_y_yy_y_x, g_y_yy_y_y, g_y_yy_y_z, g_yzz_yy_y_x, g_yzz_yy_y_y, g_yzz_yy_y_z, g_zz_0_0_0_y_yy_y_x, g_zz_0_0_0_y_yy_y_y, g_zz_0_0_0_y_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yy_y_x[i] = -2.0 * g_y_yy_y_x[i] * a_exp + 4.0 * g_yzz_yy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_y_y[i] = -2.0 * g_y_yy_y_y[i] * a_exp + 4.0 * g_yzz_yy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_y_z[i] = -2.0 * g_y_yy_y_z[i] * a_exp + 4.0 * g_yzz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (897-900)

    #pragma omp simd aligned(g_y_yy_z_x, g_y_yy_z_y, g_y_yy_z_z, g_yzz_yy_z_x, g_yzz_yy_z_y, g_yzz_yy_z_z, g_zz_0_0_0_y_yy_z_x, g_zz_0_0_0_y_yy_z_y, g_zz_0_0_0_y_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yy_z_x[i] = -2.0 * g_y_yy_z_x[i] * a_exp + 4.0 * g_yzz_yy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_z_y[i] = -2.0 * g_y_yy_z_y[i] * a_exp + 4.0 * g_yzz_yy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yy_z_z[i] = -2.0 * g_y_yy_z_z[i] * a_exp + 4.0 * g_yzz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (900-903)

    #pragma omp simd aligned(g_y_yz_x_x, g_y_yz_x_y, g_y_yz_x_z, g_yzz_yz_x_x, g_yzz_yz_x_y, g_yzz_yz_x_z, g_zz_0_0_0_y_yz_x_x, g_zz_0_0_0_y_yz_x_y, g_zz_0_0_0_y_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yz_x_x[i] = -2.0 * g_y_yz_x_x[i] * a_exp + 4.0 * g_yzz_yz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_x_y[i] = -2.0 * g_y_yz_x_y[i] * a_exp + 4.0 * g_yzz_yz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_x_z[i] = -2.0 * g_y_yz_x_z[i] * a_exp + 4.0 * g_yzz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (903-906)

    #pragma omp simd aligned(g_y_yz_y_x, g_y_yz_y_y, g_y_yz_y_z, g_yzz_yz_y_x, g_yzz_yz_y_y, g_yzz_yz_y_z, g_zz_0_0_0_y_yz_y_x, g_zz_0_0_0_y_yz_y_y, g_zz_0_0_0_y_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yz_y_x[i] = -2.0 * g_y_yz_y_x[i] * a_exp + 4.0 * g_yzz_yz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_y_y[i] = -2.0 * g_y_yz_y_y[i] * a_exp + 4.0 * g_yzz_yz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_y_z[i] = -2.0 * g_y_yz_y_z[i] * a_exp + 4.0 * g_yzz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (906-909)

    #pragma omp simd aligned(g_y_yz_z_x, g_y_yz_z_y, g_y_yz_z_z, g_yzz_yz_z_x, g_yzz_yz_z_y, g_yzz_yz_z_z, g_zz_0_0_0_y_yz_z_x, g_zz_0_0_0_y_yz_z_y, g_zz_0_0_0_y_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_yz_z_x[i] = -2.0 * g_y_yz_z_x[i] * a_exp + 4.0 * g_yzz_yz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_z_y[i] = -2.0 * g_y_yz_z_y[i] * a_exp + 4.0 * g_yzz_yz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_yz_z_z[i] = -2.0 * g_y_yz_z_z[i] * a_exp + 4.0 * g_yzz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (909-912)

    #pragma omp simd aligned(g_y_zz_x_x, g_y_zz_x_y, g_y_zz_x_z, g_yzz_zz_x_x, g_yzz_zz_x_y, g_yzz_zz_x_z, g_zz_0_0_0_y_zz_x_x, g_zz_0_0_0_y_zz_x_y, g_zz_0_0_0_y_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_zz_x_x[i] = -2.0 * g_y_zz_x_x[i] * a_exp + 4.0 * g_yzz_zz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_x_y[i] = -2.0 * g_y_zz_x_y[i] * a_exp + 4.0 * g_yzz_zz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_x_z[i] = -2.0 * g_y_zz_x_z[i] * a_exp + 4.0 * g_yzz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (912-915)

    #pragma omp simd aligned(g_y_zz_y_x, g_y_zz_y_y, g_y_zz_y_z, g_yzz_zz_y_x, g_yzz_zz_y_y, g_yzz_zz_y_z, g_zz_0_0_0_y_zz_y_x, g_zz_0_0_0_y_zz_y_y, g_zz_0_0_0_y_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_zz_y_x[i] = -2.0 * g_y_zz_y_x[i] * a_exp + 4.0 * g_yzz_zz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_y_y[i] = -2.0 * g_y_zz_y_y[i] * a_exp + 4.0 * g_yzz_zz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_y_z[i] = -2.0 * g_y_zz_y_z[i] * a_exp + 4.0 * g_yzz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (915-918)

    #pragma omp simd aligned(g_y_zz_z_x, g_y_zz_z_y, g_y_zz_z_z, g_yzz_zz_z_x, g_yzz_zz_z_y, g_yzz_zz_z_z, g_zz_0_0_0_y_zz_z_x, g_zz_0_0_0_y_zz_z_y, g_zz_0_0_0_y_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_y_zz_z_x[i] = -2.0 * g_y_zz_z_x[i] * a_exp + 4.0 * g_yzz_zz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_z_y[i] = -2.0 * g_y_zz_z_y[i] * a_exp + 4.0 * g_yzz_zz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_y_zz_z_z[i] = -2.0 * g_y_zz_z_z[i] * a_exp + 4.0 * g_yzz_zz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (918-921)

    #pragma omp simd aligned(g_z_xx_x_x, g_z_xx_x_y, g_z_xx_x_z, g_zz_0_0_0_z_xx_x_x, g_zz_0_0_0_z_xx_x_y, g_zz_0_0_0_z_xx_x_z, g_zzz_xx_x_x, g_zzz_xx_x_y, g_zzz_xx_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xx_x_x[i] = -6.0 * g_z_xx_x_x[i] * a_exp + 4.0 * g_zzz_xx_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_x_y[i] = -6.0 * g_z_xx_x_y[i] * a_exp + 4.0 * g_zzz_xx_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_x_z[i] = -6.0 * g_z_xx_x_z[i] * a_exp + 4.0 * g_zzz_xx_x_z[i] * a_exp * a_exp;
    }
    // integrals block (921-924)

    #pragma omp simd aligned(g_z_xx_y_x, g_z_xx_y_y, g_z_xx_y_z, g_zz_0_0_0_z_xx_y_x, g_zz_0_0_0_z_xx_y_y, g_zz_0_0_0_z_xx_y_z, g_zzz_xx_y_x, g_zzz_xx_y_y, g_zzz_xx_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xx_y_x[i] = -6.0 * g_z_xx_y_x[i] * a_exp + 4.0 * g_zzz_xx_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_y_y[i] = -6.0 * g_z_xx_y_y[i] * a_exp + 4.0 * g_zzz_xx_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_y_z[i] = -6.0 * g_z_xx_y_z[i] * a_exp + 4.0 * g_zzz_xx_y_z[i] * a_exp * a_exp;
    }
    // integrals block (924-927)

    #pragma omp simd aligned(g_z_xx_z_x, g_z_xx_z_y, g_z_xx_z_z, g_zz_0_0_0_z_xx_z_x, g_zz_0_0_0_z_xx_z_y, g_zz_0_0_0_z_xx_z_z, g_zzz_xx_z_x, g_zzz_xx_z_y, g_zzz_xx_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xx_z_x[i] = -6.0 * g_z_xx_z_x[i] * a_exp + 4.0 * g_zzz_xx_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_z_y[i] = -6.0 * g_z_xx_z_y[i] * a_exp + 4.0 * g_zzz_xx_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xx_z_z[i] = -6.0 * g_z_xx_z_z[i] * a_exp + 4.0 * g_zzz_xx_z_z[i] * a_exp * a_exp;
    }
    // integrals block (927-930)

    #pragma omp simd aligned(g_z_xy_x_x, g_z_xy_x_y, g_z_xy_x_z, g_zz_0_0_0_z_xy_x_x, g_zz_0_0_0_z_xy_x_y, g_zz_0_0_0_z_xy_x_z, g_zzz_xy_x_x, g_zzz_xy_x_y, g_zzz_xy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xy_x_x[i] = -6.0 * g_z_xy_x_x[i] * a_exp + 4.0 * g_zzz_xy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_x_y[i] = -6.0 * g_z_xy_x_y[i] * a_exp + 4.0 * g_zzz_xy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_x_z[i] = -6.0 * g_z_xy_x_z[i] * a_exp + 4.0 * g_zzz_xy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (930-933)

    #pragma omp simd aligned(g_z_xy_y_x, g_z_xy_y_y, g_z_xy_y_z, g_zz_0_0_0_z_xy_y_x, g_zz_0_0_0_z_xy_y_y, g_zz_0_0_0_z_xy_y_z, g_zzz_xy_y_x, g_zzz_xy_y_y, g_zzz_xy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xy_y_x[i] = -6.0 * g_z_xy_y_x[i] * a_exp + 4.0 * g_zzz_xy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_y_y[i] = -6.0 * g_z_xy_y_y[i] * a_exp + 4.0 * g_zzz_xy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_y_z[i] = -6.0 * g_z_xy_y_z[i] * a_exp + 4.0 * g_zzz_xy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (933-936)

    #pragma omp simd aligned(g_z_xy_z_x, g_z_xy_z_y, g_z_xy_z_z, g_zz_0_0_0_z_xy_z_x, g_zz_0_0_0_z_xy_z_y, g_zz_0_0_0_z_xy_z_z, g_zzz_xy_z_x, g_zzz_xy_z_y, g_zzz_xy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xy_z_x[i] = -6.0 * g_z_xy_z_x[i] * a_exp + 4.0 * g_zzz_xy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_z_y[i] = -6.0 * g_z_xy_z_y[i] * a_exp + 4.0 * g_zzz_xy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xy_z_z[i] = -6.0 * g_z_xy_z_z[i] * a_exp + 4.0 * g_zzz_xy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (936-939)

    #pragma omp simd aligned(g_z_xz_x_x, g_z_xz_x_y, g_z_xz_x_z, g_zz_0_0_0_z_xz_x_x, g_zz_0_0_0_z_xz_x_y, g_zz_0_0_0_z_xz_x_z, g_zzz_xz_x_x, g_zzz_xz_x_y, g_zzz_xz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xz_x_x[i] = -6.0 * g_z_xz_x_x[i] * a_exp + 4.0 * g_zzz_xz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_x_y[i] = -6.0 * g_z_xz_x_y[i] * a_exp + 4.0 * g_zzz_xz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_x_z[i] = -6.0 * g_z_xz_x_z[i] * a_exp + 4.0 * g_zzz_xz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (939-942)

    #pragma omp simd aligned(g_z_xz_y_x, g_z_xz_y_y, g_z_xz_y_z, g_zz_0_0_0_z_xz_y_x, g_zz_0_0_0_z_xz_y_y, g_zz_0_0_0_z_xz_y_z, g_zzz_xz_y_x, g_zzz_xz_y_y, g_zzz_xz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xz_y_x[i] = -6.0 * g_z_xz_y_x[i] * a_exp + 4.0 * g_zzz_xz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_y_y[i] = -6.0 * g_z_xz_y_y[i] * a_exp + 4.0 * g_zzz_xz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_y_z[i] = -6.0 * g_z_xz_y_z[i] * a_exp + 4.0 * g_zzz_xz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (942-945)

    #pragma omp simd aligned(g_z_xz_z_x, g_z_xz_z_y, g_z_xz_z_z, g_zz_0_0_0_z_xz_z_x, g_zz_0_0_0_z_xz_z_y, g_zz_0_0_0_z_xz_z_z, g_zzz_xz_z_x, g_zzz_xz_z_y, g_zzz_xz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_xz_z_x[i] = -6.0 * g_z_xz_z_x[i] * a_exp + 4.0 * g_zzz_xz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_z_y[i] = -6.0 * g_z_xz_z_y[i] * a_exp + 4.0 * g_zzz_xz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_xz_z_z[i] = -6.0 * g_z_xz_z_z[i] * a_exp + 4.0 * g_zzz_xz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (945-948)

    #pragma omp simd aligned(g_z_yy_x_x, g_z_yy_x_y, g_z_yy_x_z, g_zz_0_0_0_z_yy_x_x, g_zz_0_0_0_z_yy_x_y, g_zz_0_0_0_z_yy_x_z, g_zzz_yy_x_x, g_zzz_yy_x_y, g_zzz_yy_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yy_x_x[i] = -6.0 * g_z_yy_x_x[i] * a_exp + 4.0 * g_zzz_yy_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_x_y[i] = -6.0 * g_z_yy_x_y[i] * a_exp + 4.0 * g_zzz_yy_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_x_z[i] = -6.0 * g_z_yy_x_z[i] * a_exp + 4.0 * g_zzz_yy_x_z[i] * a_exp * a_exp;
    }
    // integrals block (948-951)

    #pragma omp simd aligned(g_z_yy_y_x, g_z_yy_y_y, g_z_yy_y_z, g_zz_0_0_0_z_yy_y_x, g_zz_0_0_0_z_yy_y_y, g_zz_0_0_0_z_yy_y_z, g_zzz_yy_y_x, g_zzz_yy_y_y, g_zzz_yy_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yy_y_x[i] = -6.0 * g_z_yy_y_x[i] * a_exp + 4.0 * g_zzz_yy_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_y_y[i] = -6.0 * g_z_yy_y_y[i] * a_exp + 4.0 * g_zzz_yy_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_y_z[i] = -6.0 * g_z_yy_y_z[i] * a_exp + 4.0 * g_zzz_yy_y_z[i] * a_exp * a_exp;
    }
    // integrals block (951-954)

    #pragma omp simd aligned(g_z_yy_z_x, g_z_yy_z_y, g_z_yy_z_z, g_zz_0_0_0_z_yy_z_x, g_zz_0_0_0_z_yy_z_y, g_zz_0_0_0_z_yy_z_z, g_zzz_yy_z_x, g_zzz_yy_z_y, g_zzz_yy_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yy_z_x[i] = -6.0 * g_z_yy_z_x[i] * a_exp + 4.0 * g_zzz_yy_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_z_y[i] = -6.0 * g_z_yy_z_y[i] * a_exp + 4.0 * g_zzz_yy_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yy_z_z[i] = -6.0 * g_z_yy_z_z[i] * a_exp + 4.0 * g_zzz_yy_z_z[i] * a_exp * a_exp;
    }
    // integrals block (954-957)

    #pragma omp simd aligned(g_z_yz_x_x, g_z_yz_x_y, g_z_yz_x_z, g_zz_0_0_0_z_yz_x_x, g_zz_0_0_0_z_yz_x_y, g_zz_0_0_0_z_yz_x_z, g_zzz_yz_x_x, g_zzz_yz_x_y, g_zzz_yz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yz_x_x[i] = -6.0 * g_z_yz_x_x[i] * a_exp + 4.0 * g_zzz_yz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_x_y[i] = -6.0 * g_z_yz_x_y[i] * a_exp + 4.0 * g_zzz_yz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_x_z[i] = -6.0 * g_z_yz_x_z[i] * a_exp + 4.0 * g_zzz_yz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (957-960)

    #pragma omp simd aligned(g_z_yz_y_x, g_z_yz_y_y, g_z_yz_y_z, g_zz_0_0_0_z_yz_y_x, g_zz_0_0_0_z_yz_y_y, g_zz_0_0_0_z_yz_y_z, g_zzz_yz_y_x, g_zzz_yz_y_y, g_zzz_yz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yz_y_x[i] = -6.0 * g_z_yz_y_x[i] * a_exp + 4.0 * g_zzz_yz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_y_y[i] = -6.0 * g_z_yz_y_y[i] * a_exp + 4.0 * g_zzz_yz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_y_z[i] = -6.0 * g_z_yz_y_z[i] * a_exp + 4.0 * g_zzz_yz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (960-963)

    #pragma omp simd aligned(g_z_yz_z_x, g_z_yz_z_y, g_z_yz_z_z, g_zz_0_0_0_z_yz_z_x, g_zz_0_0_0_z_yz_z_y, g_zz_0_0_0_z_yz_z_z, g_zzz_yz_z_x, g_zzz_yz_z_y, g_zzz_yz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_yz_z_x[i] = -6.0 * g_z_yz_z_x[i] * a_exp + 4.0 * g_zzz_yz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_z_y[i] = -6.0 * g_z_yz_z_y[i] * a_exp + 4.0 * g_zzz_yz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_yz_z_z[i] = -6.0 * g_z_yz_z_z[i] * a_exp + 4.0 * g_zzz_yz_z_z[i] * a_exp * a_exp;
    }
    // integrals block (963-966)

    #pragma omp simd aligned(g_z_zz_x_x, g_z_zz_x_y, g_z_zz_x_z, g_zz_0_0_0_z_zz_x_x, g_zz_0_0_0_z_zz_x_y, g_zz_0_0_0_z_zz_x_z, g_zzz_zz_x_x, g_zzz_zz_x_y, g_zzz_zz_x_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_zz_x_x[i] = -6.0 * g_z_zz_x_x[i] * a_exp + 4.0 * g_zzz_zz_x_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_x_y[i] = -6.0 * g_z_zz_x_y[i] * a_exp + 4.0 * g_zzz_zz_x_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_x_z[i] = -6.0 * g_z_zz_x_z[i] * a_exp + 4.0 * g_zzz_zz_x_z[i] * a_exp * a_exp;
    }
    // integrals block (966-969)

    #pragma omp simd aligned(g_z_zz_y_x, g_z_zz_y_y, g_z_zz_y_z, g_zz_0_0_0_z_zz_y_x, g_zz_0_0_0_z_zz_y_y, g_zz_0_0_0_z_zz_y_z, g_zzz_zz_y_x, g_zzz_zz_y_y, g_zzz_zz_y_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_zz_y_x[i] = -6.0 * g_z_zz_y_x[i] * a_exp + 4.0 * g_zzz_zz_y_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_y_y[i] = -6.0 * g_z_zz_y_y[i] * a_exp + 4.0 * g_zzz_zz_y_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_y_z[i] = -6.0 * g_z_zz_y_z[i] * a_exp + 4.0 * g_zzz_zz_y_z[i] * a_exp * a_exp;
    }
    // integrals block (969-972)

    #pragma omp simd aligned(g_z_zz_z_x, g_z_zz_z_y, g_z_zz_z_z, g_zz_0_0_0_z_zz_z_x, g_zz_0_0_0_z_zz_z_y, g_zz_0_0_0_z_zz_z_z, g_zzz_zz_z_x, g_zzz_zz_z_y, g_zzz_zz_z_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_z_zz_z_x[i] = -6.0 * g_z_zz_z_x[i] * a_exp + 4.0 * g_zzz_zz_z_x[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_z_y[i] = -6.0 * g_z_zz_z_y[i] * a_exp + 4.0 * g_zzz_zz_z_y[i] * a_exp * a_exp;

        g_zz_0_0_0_z_zz_z_z[i] = -6.0 * g_z_zz_z_z[i] * a_exp + 4.0 * g_zzz_zz_z_z[i] * a_exp * a_exp;
    }
}

} // t4c_geom namespace

