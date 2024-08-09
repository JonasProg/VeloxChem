#include "NuclearPotentialGeom010PrimRecPS.hpp"

namespace npotrec {  // npotrec namespace

auto
comp_prim_nuclear_potential_geom_010_ps(CSimdArray<double>&       pbuffer,
                                        const size_t              idx_npot_geom_010_0_ps,
                                        const size_t              idx_npot_1_ss,
                                        const size_t              idx_npot_geom_010_0_ss,
                                        const size_t              idx_npot_geom_010_1_ss,
                                        const CSimdArray<double>& factors,
                                        const size_t              idx_rpa,
                                        const size_t              idx_rpc) -> void
{
    const auto nelems = pbuffer.number_of_active_elements();

    // Set up R(PA) distances

    auto pa_x = factors.data(idx_rpa);

    auto pa_y = factors.data(idx_rpa + 1);

    auto pa_z = factors.data(idx_rpa + 2);

    // Set up R(PC) distances

    auto pc_x = factors.data(idx_rpc);

    auto pc_y = factors.data(idx_rpc + 1);

    auto pc_z = factors.data(idx_rpc + 2);

    // Set up components of auxiliary buffer : SS

    auto ta_0_0_1 = pbuffer.data(idx_npot_1_ss);

    // Set up components of auxiliary buffer : SS

    auto ta1_x_0_0_0 = pbuffer.data(idx_npot_geom_010_0_ss);

    auto ta1_y_0_0_0 = pbuffer.data(idx_npot_geom_010_0_ss + 1);

    auto ta1_z_0_0_0 = pbuffer.data(idx_npot_geom_010_0_ss + 2);

    // Set up components of auxiliary buffer : SS

    auto ta1_x_0_0_1 = pbuffer.data(idx_npot_geom_010_1_ss);

    auto ta1_y_0_0_1 = pbuffer.data(idx_npot_geom_010_1_ss + 1);

    auto ta1_z_0_0_1 = pbuffer.data(idx_npot_geom_010_1_ss + 2);

    // Set up components of targeted buffer : PS

    auto ta1_x_x_0_0 = pbuffer.data(idx_npot_geom_010_0_ps);

    auto ta1_x_y_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 1);

    auto ta1_x_z_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 2);

    auto ta1_y_x_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 3);

    auto ta1_y_y_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 4);

    auto ta1_y_z_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 5);

    auto ta1_z_x_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 6);

    auto ta1_z_y_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 7);

    auto ta1_z_z_0_0 = pbuffer.data(idx_npot_geom_010_0_ps + 8);

#pragma omp simd aligned(pa_x,            \
                             pa_y,        \
                             pa_z,        \
                             pc_x,        \
                             pc_y,        \
                             pc_z,        \
                             ta1_x_0_0_0, \
                             ta1_x_0_0_1, \
                             ta1_x_x_0_0, \
                             ta1_x_y_0_0, \
                             ta1_x_z_0_0, \
                             ta1_y_0_0_0, \
                             ta1_y_0_0_1, \
                             ta1_y_x_0_0, \
                             ta1_y_y_0_0, \
                             ta1_y_z_0_0, \
                             ta1_z_0_0_0, \
                             ta1_z_0_0_1, \
                             ta1_z_x_0_0, \
                             ta1_z_y_0_0, \
                             ta1_z_z_0_0, \
                             ta_0_0_1 : 64)
    for (size_t i = 0; i < nelems; i++)
    {
        ta1_x_x_0_0[i] = ta_0_0_1[i] + ta1_x_0_0_0[i] * pa_x[i] - ta1_x_0_0_1[i] * pc_x[i];

        ta1_x_y_0_0[i] = ta1_x_0_0_0[i] * pa_y[i] - ta1_x_0_0_1[i] * pc_y[i];

        ta1_x_z_0_0[i] = ta1_x_0_0_0[i] * pa_z[i] - ta1_x_0_0_1[i] * pc_z[i];

        ta1_y_x_0_0[i] = ta1_y_0_0_0[i] * pa_x[i] - ta1_y_0_0_1[i] * pc_x[i];

        ta1_y_y_0_0[i] = ta_0_0_1[i] + ta1_y_0_0_0[i] * pa_y[i] - ta1_y_0_0_1[i] * pc_y[i];

        ta1_y_z_0_0[i] = ta1_y_0_0_0[i] * pa_z[i] - ta1_y_0_0_1[i] * pc_z[i];

        ta1_z_x_0_0[i] = ta1_z_0_0_0[i] * pa_x[i] - ta1_z_0_0_1[i] * pc_x[i];

        ta1_z_y_0_0[i] = ta1_z_0_0_0[i] * pa_y[i] - ta1_z_0_0_1[i] * pc_y[i];

        ta1_z_z_0_0[i] = ta_0_0_1[i] + ta1_z_0_0_0[i] * pa_z[i] - ta1_z_0_0_1[i] * pc_z[i];
    }
}

}  // namespace npotrec
