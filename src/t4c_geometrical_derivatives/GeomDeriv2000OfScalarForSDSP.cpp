#include "GeomDeriv2000OfScalarForSDSP.hpp"

namespace t4c_geom { // t4c_geom namespace

auto
comp_geom2000_sdsp_0(CSimdArray<double>& buffer_2000_sdsp,
                     const CSimdArray<double>& buffer_sdsp,
                     const CSimdArray<double>& buffer_ddsp,
                     const double a_exp) -> void
{
    const auto ndims = buffer_2000_sdsp.number_of_columns();

    /// Set up components of auxilary buffer : buffer_sdsp

    auto g_0_xx_0_x = buffer_sdsp[0];

    auto g_0_xx_0_y = buffer_sdsp[1];

    auto g_0_xx_0_z = buffer_sdsp[2];

    auto g_0_xy_0_x = buffer_sdsp[3];

    auto g_0_xy_0_y = buffer_sdsp[4];

    auto g_0_xy_0_z = buffer_sdsp[5];

    auto g_0_xz_0_x = buffer_sdsp[6];

    auto g_0_xz_0_y = buffer_sdsp[7];

    auto g_0_xz_0_z = buffer_sdsp[8];

    auto g_0_yy_0_x = buffer_sdsp[9];

    auto g_0_yy_0_y = buffer_sdsp[10];

    auto g_0_yy_0_z = buffer_sdsp[11];

    auto g_0_yz_0_x = buffer_sdsp[12];

    auto g_0_yz_0_y = buffer_sdsp[13];

    auto g_0_yz_0_z = buffer_sdsp[14];

    auto g_0_zz_0_x = buffer_sdsp[15];

    auto g_0_zz_0_y = buffer_sdsp[16];

    auto g_0_zz_0_z = buffer_sdsp[17];

    /// Set up components of auxilary buffer : buffer_ddsp

    auto g_xx_xx_0_x = buffer_ddsp[0];

    auto g_xx_xx_0_y = buffer_ddsp[1];

    auto g_xx_xx_0_z = buffer_ddsp[2];

    auto g_xx_xy_0_x = buffer_ddsp[3];

    auto g_xx_xy_0_y = buffer_ddsp[4];

    auto g_xx_xy_0_z = buffer_ddsp[5];

    auto g_xx_xz_0_x = buffer_ddsp[6];

    auto g_xx_xz_0_y = buffer_ddsp[7];

    auto g_xx_xz_0_z = buffer_ddsp[8];

    auto g_xx_yy_0_x = buffer_ddsp[9];

    auto g_xx_yy_0_y = buffer_ddsp[10];

    auto g_xx_yy_0_z = buffer_ddsp[11];

    auto g_xx_yz_0_x = buffer_ddsp[12];

    auto g_xx_yz_0_y = buffer_ddsp[13];

    auto g_xx_yz_0_z = buffer_ddsp[14];

    auto g_xx_zz_0_x = buffer_ddsp[15];

    auto g_xx_zz_0_y = buffer_ddsp[16];

    auto g_xx_zz_0_z = buffer_ddsp[17];

    auto g_xy_xx_0_x = buffer_ddsp[18];

    auto g_xy_xx_0_y = buffer_ddsp[19];

    auto g_xy_xx_0_z = buffer_ddsp[20];

    auto g_xy_xy_0_x = buffer_ddsp[21];

    auto g_xy_xy_0_y = buffer_ddsp[22];

    auto g_xy_xy_0_z = buffer_ddsp[23];

    auto g_xy_xz_0_x = buffer_ddsp[24];

    auto g_xy_xz_0_y = buffer_ddsp[25];

    auto g_xy_xz_0_z = buffer_ddsp[26];

    auto g_xy_yy_0_x = buffer_ddsp[27];

    auto g_xy_yy_0_y = buffer_ddsp[28];

    auto g_xy_yy_0_z = buffer_ddsp[29];

    auto g_xy_yz_0_x = buffer_ddsp[30];

    auto g_xy_yz_0_y = buffer_ddsp[31];

    auto g_xy_yz_0_z = buffer_ddsp[32];

    auto g_xy_zz_0_x = buffer_ddsp[33];

    auto g_xy_zz_0_y = buffer_ddsp[34];

    auto g_xy_zz_0_z = buffer_ddsp[35];

    auto g_xz_xx_0_x = buffer_ddsp[36];

    auto g_xz_xx_0_y = buffer_ddsp[37];

    auto g_xz_xx_0_z = buffer_ddsp[38];

    auto g_xz_xy_0_x = buffer_ddsp[39];

    auto g_xz_xy_0_y = buffer_ddsp[40];

    auto g_xz_xy_0_z = buffer_ddsp[41];

    auto g_xz_xz_0_x = buffer_ddsp[42];

    auto g_xz_xz_0_y = buffer_ddsp[43];

    auto g_xz_xz_0_z = buffer_ddsp[44];

    auto g_xz_yy_0_x = buffer_ddsp[45];

    auto g_xz_yy_0_y = buffer_ddsp[46];

    auto g_xz_yy_0_z = buffer_ddsp[47];

    auto g_xz_yz_0_x = buffer_ddsp[48];

    auto g_xz_yz_0_y = buffer_ddsp[49];

    auto g_xz_yz_0_z = buffer_ddsp[50];

    auto g_xz_zz_0_x = buffer_ddsp[51];

    auto g_xz_zz_0_y = buffer_ddsp[52];

    auto g_xz_zz_0_z = buffer_ddsp[53];

    auto g_yy_xx_0_x = buffer_ddsp[54];

    auto g_yy_xx_0_y = buffer_ddsp[55];

    auto g_yy_xx_0_z = buffer_ddsp[56];

    auto g_yy_xy_0_x = buffer_ddsp[57];

    auto g_yy_xy_0_y = buffer_ddsp[58];

    auto g_yy_xy_0_z = buffer_ddsp[59];

    auto g_yy_xz_0_x = buffer_ddsp[60];

    auto g_yy_xz_0_y = buffer_ddsp[61];

    auto g_yy_xz_0_z = buffer_ddsp[62];

    auto g_yy_yy_0_x = buffer_ddsp[63];

    auto g_yy_yy_0_y = buffer_ddsp[64];

    auto g_yy_yy_0_z = buffer_ddsp[65];

    auto g_yy_yz_0_x = buffer_ddsp[66];

    auto g_yy_yz_0_y = buffer_ddsp[67];

    auto g_yy_yz_0_z = buffer_ddsp[68];

    auto g_yy_zz_0_x = buffer_ddsp[69];

    auto g_yy_zz_0_y = buffer_ddsp[70];

    auto g_yy_zz_0_z = buffer_ddsp[71];

    auto g_yz_xx_0_x = buffer_ddsp[72];

    auto g_yz_xx_0_y = buffer_ddsp[73];

    auto g_yz_xx_0_z = buffer_ddsp[74];

    auto g_yz_xy_0_x = buffer_ddsp[75];

    auto g_yz_xy_0_y = buffer_ddsp[76];

    auto g_yz_xy_0_z = buffer_ddsp[77];

    auto g_yz_xz_0_x = buffer_ddsp[78];

    auto g_yz_xz_0_y = buffer_ddsp[79];

    auto g_yz_xz_0_z = buffer_ddsp[80];

    auto g_yz_yy_0_x = buffer_ddsp[81];

    auto g_yz_yy_0_y = buffer_ddsp[82];

    auto g_yz_yy_0_z = buffer_ddsp[83];

    auto g_yz_yz_0_x = buffer_ddsp[84];

    auto g_yz_yz_0_y = buffer_ddsp[85];

    auto g_yz_yz_0_z = buffer_ddsp[86];

    auto g_yz_zz_0_x = buffer_ddsp[87];

    auto g_yz_zz_0_y = buffer_ddsp[88];

    auto g_yz_zz_0_z = buffer_ddsp[89];

    auto g_zz_xx_0_x = buffer_ddsp[90];

    auto g_zz_xx_0_y = buffer_ddsp[91];

    auto g_zz_xx_0_z = buffer_ddsp[92];

    auto g_zz_xy_0_x = buffer_ddsp[93];

    auto g_zz_xy_0_y = buffer_ddsp[94];

    auto g_zz_xy_0_z = buffer_ddsp[95];

    auto g_zz_xz_0_x = buffer_ddsp[96];

    auto g_zz_xz_0_y = buffer_ddsp[97];

    auto g_zz_xz_0_z = buffer_ddsp[98];

    auto g_zz_yy_0_x = buffer_ddsp[99];

    auto g_zz_yy_0_y = buffer_ddsp[100];

    auto g_zz_yy_0_z = buffer_ddsp[101];

    auto g_zz_yz_0_x = buffer_ddsp[102];

    auto g_zz_yz_0_y = buffer_ddsp[103];

    auto g_zz_yz_0_z = buffer_ddsp[104];

    auto g_zz_zz_0_x = buffer_ddsp[105];

    auto g_zz_zz_0_y = buffer_ddsp[106];

    auto g_zz_zz_0_z = buffer_ddsp[107];

    /// Set up components of integrals buffer : buffer_2000_sdsp

    auto g_xx_0_0_0_0_xx_0_x = buffer_2000_sdsp[0];

    auto g_xx_0_0_0_0_xx_0_y = buffer_2000_sdsp[1];

    auto g_xx_0_0_0_0_xx_0_z = buffer_2000_sdsp[2];

    auto g_xx_0_0_0_0_xy_0_x = buffer_2000_sdsp[3];

    auto g_xx_0_0_0_0_xy_0_y = buffer_2000_sdsp[4];

    auto g_xx_0_0_0_0_xy_0_z = buffer_2000_sdsp[5];

    auto g_xx_0_0_0_0_xz_0_x = buffer_2000_sdsp[6];

    auto g_xx_0_0_0_0_xz_0_y = buffer_2000_sdsp[7];

    auto g_xx_0_0_0_0_xz_0_z = buffer_2000_sdsp[8];

    auto g_xx_0_0_0_0_yy_0_x = buffer_2000_sdsp[9];

    auto g_xx_0_0_0_0_yy_0_y = buffer_2000_sdsp[10];

    auto g_xx_0_0_0_0_yy_0_z = buffer_2000_sdsp[11];

    auto g_xx_0_0_0_0_yz_0_x = buffer_2000_sdsp[12];

    auto g_xx_0_0_0_0_yz_0_y = buffer_2000_sdsp[13];

    auto g_xx_0_0_0_0_yz_0_z = buffer_2000_sdsp[14];

    auto g_xx_0_0_0_0_zz_0_x = buffer_2000_sdsp[15];

    auto g_xx_0_0_0_0_zz_0_y = buffer_2000_sdsp[16];

    auto g_xx_0_0_0_0_zz_0_z = buffer_2000_sdsp[17];

    auto g_xy_0_0_0_0_xx_0_x = buffer_2000_sdsp[18];

    auto g_xy_0_0_0_0_xx_0_y = buffer_2000_sdsp[19];

    auto g_xy_0_0_0_0_xx_0_z = buffer_2000_sdsp[20];

    auto g_xy_0_0_0_0_xy_0_x = buffer_2000_sdsp[21];

    auto g_xy_0_0_0_0_xy_0_y = buffer_2000_sdsp[22];

    auto g_xy_0_0_0_0_xy_0_z = buffer_2000_sdsp[23];

    auto g_xy_0_0_0_0_xz_0_x = buffer_2000_sdsp[24];

    auto g_xy_0_0_0_0_xz_0_y = buffer_2000_sdsp[25];

    auto g_xy_0_0_0_0_xz_0_z = buffer_2000_sdsp[26];

    auto g_xy_0_0_0_0_yy_0_x = buffer_2000_sdsp[27];

    auto g_xy_0_0_0_0_yy_0_y = buffer_2000_sdsp[28];

    auto g_xy_0_0_0_0_yy_0_z = buffer_2000_sdsp[29];

    auto g_xy_0_0_0_0_yz_0_x = buffer_2000_sdsp[30];

    auto g_xy_0_0_0_0_yz_0_y = buffer_2000_sdsp[31];

    auto g_xy_0_0_0_0_yz_0_z = buffer_2000_sdsp[32];

    auto g_xy_0_0_0_0_zz_0_x = buffer_2000_sdsp[33];

    auto g_xy_0_0_0_0_zz_0_y = buffer_2000_sdsp[34];

    auto g_xy_0_0_0_0_zz_0_z = buffer_2000_sdsp[35];

    auto g_xz_0_0_0_0_xx_0_x = buffer_2000_sdsp[36];

    auto g_xz_0_0_0_0_xx_0_y = buffer_2000_sdsp[37];

    auto g_xz_0_0_0_0_xx_0_z = buffer_2000_sdsp[38];

    auto g_xz_0_0_0_0_xy_0_x = buffer_2000_sdsp[39];

    auto g_xz_0_0_0_0_xy_0_y = buffer_2000_sdsp[40];

    auto g_xz_0_0_0_0_xy_0_z = buffer_2000_sdsp[41];

    auto g_xz_0_0_0_0_xz_0_x = buffer_2000_sdsp[42];

    auto g_xz_0_0_0_0_xz_0_y = buffer_2000_sdsp[43];

    auto g_xz_0_0_0_0_xz_0_z = buffer_2000_sdsp[44];

    auto g_xz_0_0_0_0_yy_0_x = buffer_2000_sdsp[45];

    auto g_xz_0_0_0_0_yy_0_y = buffer_2000_sdsp[46];

    auto g_xz_0_0_0_0_yy_0_z = buffer_2000_sdsp[47];

    auto g_xz_0_0_0_0_yz_0_x = buffer_2000_sdsp[48];

    auto g_xz_0_0_0_0_yz_0_y = buffer_2000_sdsp[49];

    auto g_xz_0_0_0_0_yz_0_z = buffer_2000_sdsp[50];

    auto g_xz_0_0_0_0_zz_0_x = buffer_2000_sdsp[51];

    auto g_xz_0_0_0_0_zz_0_y = buffer_2000_sdsp[52];

    auto g_xz_0_0_0_0_zz_0_z = buffer_2000_sdsp[53];

    auto g_yy_0_0_0_0_xx_0_x = buffer_2000_sdsp[54];

    auto g_yy_0_0_0_0_xx_0_y = buffer_2000_sdsp[55];

    auto g_yy_0_0_0_0_xx_0_z = buffer_2000_sdsp[56];

    auto g_yy_0_0_0_0_xy_0_x = buffer_2000_sdsp[57];

    auto g_yy_0_0_0_0_xy_0_y = buffer_2000_sdsp[58];

    auto g_yy_0_0_0_0_xy_0_z = buffer_2000_sdsp[59];

    auto g_yy_0_0_0_0_xz_0_x = buffer_2000_sdsp[60];

    auto g_yy_0_0_0_0_xz_0_y = buffer_2000_sdsp[61];

    auto g_yy_0_0_0_0_xz_0_z = buffer_2000_sdsp[62];

    auto g_yy_0_0_0_0_yy_0_x = buffer_2000_sdsp[63];

    auto g_yy_0_0_0_0_yy_0_y = buffer_2000_sdsp[64];

    auto g_yy_0_0_0_0_yy_0_z = buffer_2000_sdsp[65];

    auto g_yy_0_0_0_0_yz_0_x = buffer_2000_sdsp[66];

    auto g_yy_0_0_0_0_yz_0_y = buffer_2000_sdsp[67];

    auto g_yy_0_0_0_0_yz_0_z = buffer_2000_sdsp[68];

    auto g_yy_0_0_0_0_zz_0_x = buffer_2000_sdsp[69];

    auto g_yy_0_0_0_0_zz_0_y = buffer_2000_sdsp[70];

    auto g_yy_0_0_0_0_zz_0_z = buffer_2000_sdsp[71];

    auto g_yz_0_0_0_0_xx_0_x = buffer_2000_sdsp[72];

    auto g_yz_0_0_0_0_xx_0_y = buffer_2000_sdsp[73];

    auto g_yz_0_0_0_0_xx_0_z = buffer_2000_sdsp[74];

    auto g_yz_0_0_0_0_xy_0_x = buffer_2000_sdsp[75];

    auto g_yz_0_0_0_0_xy_0_y = buffer_2000_sdsp[76];

    auto g_yz_0_0_0_0_xy_0_z = buffer_2000_sdsp[77];

    auto g_yz_0_0_0_0_xz_0_x = buffer_2000_sdsp[78];

    auto g_yz_0_0_0_0_xz_0_y = buffer_2000_sdsp[79];

    auto g_yz_0_0_0_0_xz_0_z = buffer_2000_sdsp[80];

    auto g_yz_0_0_0_0_yy_0_x = buffer_2000_sdsp[81];

    auto g_yz_0_0_0_0_yy_0_y = buffer_2000_sdsp[82];

    auto g_yz_0_0_0_0_yy_0_z = buffer_2000_sdsp[83];

    auto g_yz_0_0_0_0_yz_0_x = buffer_2000_sdsp[84];

    auto g_yz_0_0_0_0_yz_0_y = buffer_2000_sdsp[85];

    auto g_yz_0_0_0_0_yz_0_z = buffer_2000_sdsp[86];

    auto g_yz_0_0_0_0_zz_0_x = buffer_2000_sdsp[87];

    auto g_yz_0_0_0_0_zz_0_y = buffer_2000_sdsp[88];

    auto g_yz_0_0_0_0_zz_0_z = buffer_2000_sdsp[89];

    auto g_zz_0_0_0_0_xx_0_x = buffer_2000_sdsp[90];

    auto g_zz_0_0_0_0_xx_0_y = buffer_2000_sdsp[91];

    auto g_zz_0_0_0_0_xx_0_z = buffer_2000_sdsp[92];

    auto g_zz_0_0_0_0_xy_0_x = buffer_2000_sdsp[93];

    auto g_zz_0_0_0_0_xy_0_y = buffer_2000_sdsp[94];

    auto g_zz_0_0_0_0_xy_0_z = buffer_2000_sdsp[95];

    auto g_zz_0_0_0_0_xz_0_x = buffer_2000_sdsp[96];

    auto g_zz_0_0_0_0_xz_0_y = buffer_2000_sdsp[97];

    auto g_zz_0_0_0_0_xz_0_z = buffer_2000_sdsp[98];

    auto g_zz_0_0_0_0_yy_0_x = buffer_2000_sdsp[99];

    auto g_zz_0_0_0_0_yy_0_y = buffer_2000_sdsp[100];

    auto g_zz_0_0_0_0_yy_0_z = buffer_2000_sdsp[101];

    auto g_zz_0_0_0_0_yz_0_x = buffer_2000_sdsp[102];

    auto g_zz_0_0_0_0_yz_0_y = buffer_2000_sdsp[103];

    auto g_zz_0_0_0_0_yz_0_z = buffer_2000_sdsp[104];

    auto g_zz_0_0_0_0_zz_0_x = buffer_2000_sdsp[105];

    auto g_zz_0_0_0_0_zz_0_y = buffer_2000_sdsp[106];

    auto g_zz_0_0_0_0_zz_0_z = buffer_2000_sdsp[107];

    // integrals block (0-3)

    #pragma omp simd aligned(g_0_xx_0_x, g_0_xx_0_y, g_0_xx_0_z, g_xx_0_0_0_0_xx_0_x, g_xx_0_0_0_0_xx_0_y, g_xx_0_0_0_0_xx_0_z, g_xx_xx_0_x, g_xx_xx_0_y, g_xx_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_xx_0_x[i] = -2.0 * g_0_xx_0_x[i] * a_exp + 4.0 * g_xx_xx_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xx_0_y[i] = -2.0 * g_0_xx_0_y[i] * a_exp + 4.0 * g_xx_xx_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xx_0_z[i] = -2.0 * g_0_xx_0_z[i] * a_exp + 4.0 * g_xx_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (3-6)

    #pragma omp simd aligned(g_0_xy_0_x, g_0_xy_0_y, g_0_xy_0_z, g_xx_0_0_0_0_xy_0_x, g_xx_0_0_0_0_xy_0_y, g_xx_0_0_0_0_xy_0_z, g_xx_xy_0_x, g_xx_xy_0_y, g_xx_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_xy_0_x[i] = -2.0 * g_0_xy_0_x[i] * a_exp + 4.0 * g_xx_xy_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xy_0_y[i] = -2.0 * g_0_xy_0_y[i] * a_exp + 4.0 * g_xx_xy_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xy_0_z[i] = -2.0 * g_0_xy_0_z[i] * a_exp + 4.0 * g_xx_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (6-9)

    #pragma omp simd aligned(g_0_xz_0_x, g_0_xz_0_y, g_0_xz_0_z, g_xx_0_0_0_0_xz_0_x, g_xx_0_0_0_0_xz_0_y, g_xx_0_0_0_0_xz_0_z, g_xx_xz_0_x, g_xx_xz_0_y, g_xx_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_xz_0_x[i] = -2.0 * g_0_xz_0_x[i] * a_exp + 4.0 * g_xx_xz_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xz_0_y[i] = -2.0 * g_0_xz_0_y[i] * a_exp + 4.0 * g_xx_xz_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_xz_0_z[i] = -2.0 * g_0_xz_0_z[i] * a_exp + 4.0 * g_xx_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (9-12)

    #pragma omp simd aligned(g_0_yy_0_x, g_0_yy_0_y, g_0_yy_0_z, g_xx_0_0_0_0_yy_0_x, g_xx_0_0_0_0_yy_0_y, g_xx_0_0_0_0_yy_0_z, g_xx_yy_0_x, g_xx_yy_0_y, g_xx_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_yy_0_x[i] = -2.0 * g_0_yy_0_x[i] * a_exp + 4.0 * g_xx_yy_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_yy_0_y[i] = -2.0 * g_0_yy_0_y[i] * a_exp + 4.0 * g_xx_yy_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_yy_0_z[i] = -2.0 * g_0_yy_0_z[i] * a_exp + 4.0 * g_xx_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (12-15)

    #pragma omp simd aligned(g_0_yz_0_x, g_0_yz_0_y, g_0_yz_0_z, g_xx_0_0_0_0_yz_0_x, g_xx_0_0_0_0_yz_0_y, g_xx_0_0_0_0_yz_0_z, g_xx_yz_0_x, g_xx_yz_0_y, g_xx_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_yz_0_x[i] = -2.0 * g_0_yz_0_x[i] * a_exp + 4.0 * g_xx_yz_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_yz_0_y[i] = -2.0 * g_0_yz_0_y[i] * a_exp + 4.0 * g_xx_yz_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_yz_0_z[i] = -2.0 * g_0_yz_0_z[i] * a_exp + 4.0 * g_xx_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (15-18)

    #pragma omp simd aligned(g_0_zz_0_x, g_0_zz_0_y, g_0_zz_0_z, g_xx_0_0_0_0_zz_0_x, g_xx_0_0_0_0_zz_0_y, g_xx_0_0_0_0_zz_0_z, g_xx_zz_0_x, g_xx_zz_0_y, g_xx_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xx_0_0_0_0_zz_0_x[i] = -2.0 * g_0_zz_0_x[i] * a_exp + 4.0 * g_xx_zz_0_x[i] * a_exp * a_exp;

        g_xx_0_0_0_0_zz_0_y[i] = -2.0 * g_0_zz_0_y[i] * a_exp + 4.0 * g_xx_zz_0_y[i] * a_exp * a_exp;

        g_xx_0_0_0_0_zz_0_z[i] = -2.0 * g_0_zz_0_z[i] * a_exp + 4.0 * g_xx_zz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (18-21)

    #pragma omp simd aligned(g_xy_0_0_0_0_xx_0_x, g_xy_0_0_0_0_xx_0_y, g_xy_0_0_0_0_xx_0_z, g_xy_xx_0_x, g_xy_xx_0_y, g_xy_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_xx_0_x[i] = 4.0 * g_xy_xx_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xx_0_y[i] = 4.0 * g_xy_xx_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xx_0_z[i] = 4.0 * g_xy_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (21-24)

    #pragma omp simd aligned(g_xy_0_0_0_0_xy_0_x, g_xy_0_0_0_0_xy_0_y, g_xy_0_0_0_0_xy_0_z, g_xy_xy_0_x, g_xy_xy_0_y, g_xy_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_xy_0_x[i] = 4.0 * g_xy_xy_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xy_0_y[i] = 4.0 * g_xy_xy_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xy_0_z[i] = 4.0 * g_xy_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (24-27)

    #pragma omp simd aligned(g_xy_0_0_0_0_xz_0_x, g_xy_0_0_0_0_xz_0_y, g_xy_0_0_0_0_xz_0_z, g_xy_xz_0_x, g_xy_xz_0_y, g_xy_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_xz_0_x[i] = 4.0 * g_xy_xz_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xz_0_y[i] = 4.0 * g_xy_xz_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_xz_0_z[i] = 4.0 * g_xy_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (27-30)

    #pragma omp simd aligned(g_xy_0_0_0_0_yy_0_x, g_xy_0_0_0_0_yy_0_y, g_xy_0_0_0_0_yy_0_z, g_xy_yy_0_x, g_xy_yy_0_y, g_xy_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_yy_0_x[i] = 4.0 * g_xy_yy_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_yy_0_y[i] = 4.0 * g_xy_yy_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_yy_0_z[i] = 4.0 * g_xy_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (30-33)

    #pragma omp simd aligned(g_xy_0_0_0_0_yz_0_x, g_xy_0_0_0_0_yz_0_y, g_xy_0_0_0_0_yz_0_z, g_xy_yz_0_x, g_xy_yz_0_y, g_xy_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_yz_0_x[i] = 4.0 * g_xy_yz_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_yz_0_y[i] = 4.0 * g_xy_yz_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_yz_0_z[i] = 4.0 * g_xy_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (33-36)

    #pragma omp simd aligned(g_xy_0_0_0_0_zz_0_x, g_xy_0_0_0_0_zz_0_y, g_xy_0_0_0_0_zz_0_z, g_xy_zz_0_x, g_xy_zz_0_y, g_xy_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xy_0_0_0_0_zz_0_x[i] = 4.0 * g_xy_zz_0_x[i] * a_exp * a_exp;

        g_xy_0_0_0_0_zz_0_y[i] = 4.0 * g_xy_zz_0_y[i] * a_exp * a_exp;

        g_xy_0_0_0_0_zz_0_z[i] = 4.0 * g_xy_zz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (36-39)

    #pragma omp simd aligned(g_xz_0_0_0_0_xx_0_x, g_xz_0_0_0_0_xx_0_y, g_xz_0_0_0_0_xx_0_z, g_xz_xx_0_x, g_xz_xx_0_y, g_xz_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_xx_0_x[i] = 4.0 * g_xz_xx_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xx_0_y[i] = 4.0 * g_xz_xx_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xx_0_z[i] = 4.0 * g_xz_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (39-42)

    #pragma omp simd aligned(g_xz_0_0_0_0_xy_0_x, g_xz_0_0_0_0_xy_0_y, g_xz_0_0_0_0_xy_0_z, g_xz_xy_0_x, g_xz_xy_0_y, g_xz_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_xy_0_x[i] = 4.0 * g_xz_xy_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xy_0_y[i] = 4.0 * g_xz_xy_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xy_0_z[i] = 4.0 * g_xz_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (42-45)

    #pragma omp simd aligned(g_xz_0_0_0_0_xz_0_x, g_xz_0_0_0_0_xz_0_y, g_xz_0_0_0_0_xz_0_z, g_xz_xz_0_x, g_xz_xz_0_y, g_xz_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_xz_0_x[i] = 4.0 * g_xz_xz_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xz_0_y[i] = 4.0 * g_xz_xz_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_xz_0_z[i] = 4.0 * g_xz_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (45-48)

    #pragma omp simd aligned(g_xz_0_0_0_0_yy_0_x, g_xz_0_0_0_0_yy_0_y, g_xz_0_0_0_0_yy_0_z, g_xz_yy_0_x, g_xz_yy_0_y, g_xz_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_yy_0_x[i] = 4.0 * g_xz_yy_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_yy_0_y[i] = 4.0 * g_xz_yy_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_yy_0_z[i] = 4.0 * g_xz_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (48-51)

    #pragma omp simd aligned(g_xz_0_0_0_0_yz_0_x, g_xz_0_0_0_0_yz_0_y, g_xz_0_0_0_0_yz_0_z, g_xz_yz_0_x, g_xz_yz_0_y, g_xz_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_yz_0_x[i] = 4.0 * g_xz_yz_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_yz_0_y[i] = 4.0 * g_xz_yz_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_yz_0_z[i] = 4.0 * g_xz_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (51-54)

    #pragma omp simd aligned(g_xz_0_0_0_0_zz_0_x, g_xz_0_0_0_0_zz_0_y, g_xz_0_0_0_0_zz_0_z, g_xz_zz_0_x, g_xz_zz_0_y, g_xz_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_xz_0_0_0_0_zz_0_x[i] = 4.0 * g_xz_zz_0_x[i] * a_exp * a_exp;

        g_xz_0_0_0_0_zz_0_y[i] = 4.0 * g_xz_zz_0_y[i] * a_exp * a_exp;

        g_xz_0_0_0_0_zz_0_z[i] = 4.0 * g_xz_zz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (54-57)

    #pragma omp simd aligned(g_0_xx_0_x, g_0_xx_0_y, g_0_xx_0_z, g_yy_0_0_0_0_xx_0_x, g_yy_0_0_0_0_xx_0_y, g_yy_0_0_0_0_xx_0_z, g_yy_xx_0_x, g_yy_xx_0_y, g_yy_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_xx_0_x[i] = -2.0 * g_0_xx_0_x[i] * a_exp + 4.0 * g_yy_xx_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xx_0_y[i] = -2.0 * g_0_xx_0_y[i] * a_exp + 4.0 * g_yy_xx_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xx_0_z[i] = -2.0 * g_0_xx_0_z[i] * a_exp + 4.0 * g_yy_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (57-60)

    #pragma omp simd aligned(g_0_xy_0_x, g_0_xy_0_y, g_0_xy_0_z, g_yy_0_0_0_0_xy_0_x, g_yy_0_0_0_0_xy_0_y, g_yy_0_0_0_0_xy_0_z, g_yy_xy_0_x, g_yy_xy_0_y, g_yy_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_xy_0_x[i] = -2.0 * g_0_xy_0_x[i] * a_exp + 4.0 * g_yy_xy_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xy_0_y[i] = -2.0 * g_0_xy_0_y[i] * a_exp + 4.0 * g_yy_xy_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xy_0_z[i] = -2.0 * g_0_xy_0_z[i] * a_exp + 4.0 * g_yy_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (60-63)

    #pragma omp simd aligned(g_0_xz_0_x, g_0_xz_0_y, g_0_xz_0_z, g_yy_0_0_0_0_xz_0_x, g_yy_0_0_0_0_xz_0_y, g_yy_0_0_0_0_xz_0_z, g_yy_xz_0_x, g_yy_xz_0_y, g_yy_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_xz_0_x[i] = -2.0 * g_0_xz_0_x[i] * a_exp + 4.0 * g_yy_xz_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xz_0_y[i] = -2.0 * g_0_xz_0_y[i] * a_exp + 4.0 * g_yy_xz_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_xz_0_z[i] = -2.0 * g_0_xz_0_z[i] * a_exp + 4.0 * g_yy_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (63-66)

    #pragma omp simd aligned(g_0_yy_0_x, g_0_yy_0_y, g_0_yy_0_z, g_yy_0_0_0_0_yy_0_x, g_yy_0_0_0_0_yy_0_y, g_yy_0_0_0_0_yy_0_z, g_yy_yy_0_x, g_yy_yy_0_y, g_yy_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_yy_0_x[i] = -2.0 * g_0_yy_0_x[i] * a_exp + 4.0 * g_yy_yy_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_yy_0_y[i] = -2.0 * g_0_yy_0_y[i] * a_exp + 4.0 * g_yy_yy_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_yy_0_z[i] = -2.0 * g_0_yy_0_z[i] * a_exp + 4.0 * g_yy_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (66-69)

    #pragma omp simd aligned(g_0_yz_0_x, g_0_yz_0_y, g_0_yz_0_z, g_yy_0_0_0_0_yz_0_x, g_yy_0_0_0_0_yz_0_y, g_yy_0_0_0_0_yz_0_z, g_yy_yz_0_x, g_yy_yz_0_y, g_yy_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_yz_0_x[i] = -2.0 * g_0_yz_0_x[i] * a_exp + 4.0 * g_yy_yz_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_yz_0_y[i] = -2.0 * g_0_yz_0_y[i] * a_exp + 4.0 * g_yy_yz_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_yz_0_z[i] = -2.0 * g_0_yz_0_z[i] * a_exp + 4.0 * g_yy_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (69-72)

    #pragma omp simd aligned(g_0_zz_0_x, g_0_zz_0_y, g_0_zz_0_z, g_yy_0_0_0_0_zz_0_x, g_yy_0_0_0_0_zz_0_y, g_yy_0_0_0_0_zz_0_z, g_yy_zz_0_x, g_yy_zz_0_y, g_yy_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yy_0_0_0_0_zz_0_x[i] = -2.0 * g_0_zz_0_x[i] * a_exp + 4.0 * g_yy_zz_0_x[i] * a_exp * a_exp;

        g_yy_0_0_0_0_zz_0_y[i] = -2.0 * g_0_zz_0_y[i] * a_exp + 4.0 * g_yy_zz_0_y[i] * a_exp * a_exp;

        g_yy_0_0_0_0_zz_0_z[i] = -2.0 * g_0_zz_0_z[i] * a_exp + 4.0 * g_yy_zz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (72-75)

    #pragma omp simd aligned(g_yz_0_0_0_0_xx_0_x, g_yz_0_0_0_0_xx_0_y, g_yz_0_0_0_0_xx_0_z, g_yz_xx_0_x, g_yz_xx_0_y, g_yz_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_xx_0_x[i] = 4.0 * g_yz_xx_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xx_0_y[i] = 4.0 * g_yz_xx_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xx_0_z[i] = 4.0 * g_yz_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (75-78)

    #pragma omp simd aligned(g_yz_0_0_0_0_xy_0_x, g_yz_0_0_0_0_xy_0_y, g_yz_0_0_0_0_xy_0_z, g_yz_xy_0_x, g_yz_xy_0_y, g_yz_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_xy_0_x[i] = 4.0 * g_yz_xy_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xy_0_y[i] = 4.0 * g_yz_xy_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xy_0_z[i] = 4.0 * g_yz_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (78-81)

    #pragma omp simd aligned(g_yz_0_0_0_0_xz_0_x, g_yz_0_0_0_0_xz_0_y, g_yz_0_0_0_0_xz_0_z, g_yz_xz_0_x, g_yz_xz_0_y, g_yz_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_xz_0_x[i] = 4.0 * g_yz_xz_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xz_0_y[i] = 4.0 * g_yz_xz_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_xz_0_z[i] = 4.0 * g_yz_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (81-84)

    #pragma omp simd aligned(g_yz_0_0_0_0_yy_0_x, g_yz_0_0_0_0_yy_0_y, g_yz_0_0_0_0_yy_0_z, g_yz_yy_0_x, g_yz_yy_0_y, g_yz_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_yy_0_x[i] = 4.0 * g_yz_yy_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_yy_0_y[i] = 4.0 * g_yz_yy_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_yy_0_z[i] = 4.0 * g_yz_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (84-87)

    #pragma omp simd aligned(g_yz_0_0_0_0_yz_0_x, g_yz_0_0_0_0_yz_0_y, g_yz_0_0_0_0_yz_0_z, g_yz_yz_0_x, g_yz_yz_0_y, g_yz_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_yz_0_x[i] = 4.0 * g_yz_yz_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_yz_0_y[i] = 4.0 * g_yz_yz_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_yz_0_z[i] = 4.0 * g_yz_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (87-90)

    #pragma omp simd aligned(g_yz_0_0_0_0_zz_0_x, g_yz_0_0_0_0_zz_0_y, g_yz_0_0_0_0_zz_0_z, g_yz_zz_0_x, g_yz_zz_0_y, g_yz_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_yz_0_0_0_0_zz_0_x[i] = 4.0 * g_yz_zz_0_x[i] * a_exp * a_exp;

        g_yz_0_0_0_0_zz_0_y[i] = 4.0 * g_yz_zz_0_y[i] * a_exp * a_exp;

        g_yz_0_0_0_0_zz_0_z[i] = 4.0 * g_yz_zz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (90-93)

    #pragma omp simd aligned(g_0_xx_0_x, g_0_xx_0_y, g_0_xx_0_z, g_zz_0_0_0_0_xx_0_x, g_zz_0_0_0_0_xx_0_y, g_zz_0_0_0_0_xx_0_z, g_zz_xx_0_x, g_zz_xx_0_y, g_zz_xx_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_xx_0_x[i] = -2.0 * g_0_xx_0_x[i] * a_exp + 4.0 * g_zz_xx_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xx_0_y[i] = -2.0 * g_0_xx_0_y[i] * a_exp + 4.0 * g_zz_xx_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xx_0_z[i] = -2.0 * g_0_xx_0_z[i] * a_exp + 4.0 * g_zz_xx_0_z[i] * a_exp * a_exp;
    }
    // integrals block (93-96)

    #pragma omp simd aligned(g_0_xy_0_x, g_0_xy_0_y, g_0_xy_0_z, g_zz_0_0_0_0_xy_0_x, g_zz_0_0_0_0_xy_0_y, g_zz_0_0_0_0_xy_0_z, g_zz_xy_0_x, g_zz_xy_0_y, g_zz_xy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_xy_0_x[i] = -2.0 * g_0_xy_0_x[i] * a_exp + 4.0 * g_zz_xy_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xy_0_y[i] = -2.0 * g_0_xy_0_y[i] * a_exp + 4.0 * g_zz_xy_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xy_0_z[i] = -2.0 * g_0_xy_0_z[i] * a_exp + 4.0 * g_zz_xy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (96-99)

    #pragma omp simd aligned(g_0_xz_0_x, g_0_xz_0_y, g_0_xz_0_z, g_zz_0_0_0_0_xz_0_x, g_zz_0_0_0_0_xz_0_y, g_zz_0_0_0_0_xz_0_z, g_zz_xz_0_x, g_zz_xz_0_y, g_zz_xz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_xz_0_x[i] = -2.0 * g_0_xz_0_x[i] * a_exp + 4.0 * g_zz_xz_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xz_0_y[i] = -2.0 * g_0_xz_0_y[i] * a_exp + 4.0 * g_zz_xz_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_xz_0_z[i] = -2.0 * g_0_xz_0_z[i] * a_exp + 4.0 * g_zz_xz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (99-102)

    #pragma omp simd aligned(g_0_yy_0_x, g_0_yy_0_y, g_0_yy_0_z, g_zz_0_0_0_0_yy_0_x, g_zz_0_0_0_0_yy_0_y, g_zz_0_0_0_0_yy_0_z, g_zz_yy_0_x, g_zz_yy_0_y, g_zz_yy_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_yy_0_x[i] = -2.0 * g_0_yy_0_x[i] * a_exp + 4.0 * g_zz_yy_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_yy_0_y[i] = -2.0 * g_0_yy_0_y[i] * a_exp + 4.0 * g_zz_yy_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_yy_0_z[i] = -2.0 * g_0_yy_0_z[i] * a_exp + 4.0 * g_zz_yy_0_z[i] * a_exp * a_exp;
    }
    // integrals block (102-105)

    #pragma omp simd aligned(g_0_yz_0_x, g_0_yz_0_y, g_0_yz_0_z, g_zz_0_0_0_0_yz_0_x, g_zz_0_0_0_0_yz_0_y, g_zz_0_0_0_0_yz_0_z, g_zz_yz_0_x, g_zz_yz_0_y, g_zz_yz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_yz_0_x[i] = -2.0 * g_0_yz_0_x[i] * a_exp + 4.0 * g_zz_yz_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_yz_0_y[i] = -2.0 * g_0_yz_0_y[i] * a_exp + 4.0 * g_zz_yz_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_yz_0_z[i] = -2.0 * g_0_yz_0_z[i] * a_exp + 4.0 * g_zz_yz_0_z[i] * a_exp * a_exp;
    }
    // integrals block (105-108)

    #pragma omp simd aligned(g_0_zz_0_x, g_0_zz_0_y, g_0_zz_0_z, g_zz_0_0_0_0_zz_0_x, g_zz_0_0_0_0_zz_0_y, g_zz_0_0_0_0_zz_0_z, g_zz_zz_0_x, g_zz_zz_0_y, g_zz_zz_0_z  : 64)
    for (size_t i = 0; i < ndims; i++)
    {
        g_zz_0_0_0_0_zz_0_x[i] = -2.0 * g_0_zz_0_x[i] * a_exp + 4.0 * g_zz_zz_0_x[i] * a_exp * a_exp;

        g_zz_0_0_0_0_zz_0_y[i] = -2.0 * g_0_zz_0_y[i] * a_exp + 4.0 * g_zz_zz_0_y[i] * a_exp * a_exp;

        g_zz_0_0_0_0_zz_0_z[i] = -2.0 * g_0_zz_0_z[i] * a_exp + 4.0 * g_zz_zz_0_z[i] * a_exp * a_exp;
    }
}

} // t4c_geom namespace

