#ifndef ElectricDipoleMomentumSumRecGD_hpp
#define ElectricDipoleMomentumSumRecGD_hpp

#include <cstddef>
#include <array>
#include <utility>

#include "GtoBlock.hpp"
#include "SimdArray.hpp"
#include "OverlapPrimRecSS.hpp"
#include "ElectricDipoleMomentumPrimRecSS.hpp"
#include "OverlapPrimRecSP.hpp"
#include "ElectricDipoleMomentumPrimRecSP.hpp"
#include "OverlapPrimRecSD.hpp"
#include "ElectricDipoleMomentumPrimRecSD.hpp"
#include "OverlapPrimRecPS.hpp"
#include "ElectricDipoleMomentumPrimRecPS.hpp"
#include "OverlapPrimRecPP.hpp"
#include "ElectricDipoleMomentumPrimRecPP.hpp"
#include "OverlapPrimRecPD.hpp"
#include "ElectricDipoleMomentumPrimRecPD.hpp"
#include "OverlapPrimRecDS.hpp"
#include "ElectricDipoleMomentumPrimRecDS.hpp"
#include "OverlapPrimRecDP.hpp"
#include "ElectricDipoleMomentumPrimRecDP.hpp"
#include "OverlapPrimRecDD.hpp"
#include "ElectricDipoleMomentumPrimRecDD.hpp"
#include "ElectricDipoleMomentumPrimRecFS.hpp"
#include "OverlapPrimRecFP.hpp"
#include "ElectricDipoleMomentumPrimRecFP.hpp"
#include "OverlapPrimRecFD.hpp"
#include "ElectricDipoleMomentumPrimRecFD.hpp"
#include "ElectricDipoleMomentumPrimRecGP.hpp"
#include "OverlapPrimRecGD.hpp"
#include "ElectricDipoleMomentumPrimRecGD.hpp"
#include "ElectricDipoleMomentumPrimRecHD.hpp"
#include "GeometricalDerivatives1X0ForGY.hpp"

#include "T2CUtils.hpp"
#include "T2CTransform.hpp"
#include "BatchFunc.hpp"

namespace diprec { // diprec namespace

/// @brief Computes (d^(1)/dA^(1)G|r|D)  integrals for pair of basis functions blocks.
/// @param distributor The integrals distributor.
/// @param bra_gto_block The basis functions block on bra side.
/// @param ket_gto_block The basis functions block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis functions on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis functions on ket side.
/// @param bra_eq_ket True if basis functions blocks on bra and ket are the same, False otherwise.
template <class T>
auto
comp_sum_electric_dipole_momentum_geom_10_gd(T& distributor,
                                             const CGtoBlock& bra_gto_block,
                                             const CGtoBlock& ket_gto_block,
                                             const std::pair<size_t, size_t>& bra_indices,
                                             const std::pair<size_t, size_t>& ket_indices,
                                             const bool bra_eq_ket) -> void
{
    // intialize external coordinate(s)

    const auto coords = distributor.coordinates();

    // intialize GTOs data on bra side

    const auto bra_gto_coords = bra_gto_block.coordinates();

    const auto bra_gto_exps = bra_gto_block.exponents();

    const auto bra_gto_norms = bra_gto_block.normalization_factors();

    const auto bra_gto_indices = bra_gto_block.orbital_indices();

    const auto bra_ncgtos = bra_gto_block.number_of_basis_functions();

    const auto bra_npgtos = bra_gto_block.number_of_primitives();

    // intialize GTOs data on ket side

    const auto ket_gto_coords = ket_gto_block.coordinates();

    const auto ket_gto_exps = ket_gto_block.exponents();

    const auto ket_gto_norms = ket_gto_block.normalization_factors();

    const auto ket_gto_indices = ket_gto_block.orbital_indices();

    const auto ket_npgtos = ket_gto_block.number_of_primitives();

    // allocate aligned 2D arrays for ket side

    CSimdArray<double> factors(20, ket_npgtos);

    // allocate aligned primitive integrals

    CSimdArray<double> pbuffer(2473, ket_npgtos);

    // allocate aligned contracted integrals

    CSimdArray<double> cbuffer(810, 1);

    CSimdArray<double> sbuffer(405, 1);

    // set up ket partitioning

    const auto ket_dim = ket_indices.second - ket_indices.first;

    const auto ket_blocks = batch::number_of_batches(ket_dim, simd::width<double>());

    for (size_t i = 0; i < ket_blocks; i++)
    {
        auto ket_range = batch::batch_range(i, ket_dim, simd::width<double>(), ket_indices.first);

        factors.load(ket_gto_exps, ket_range, 0, ket_npgtos);

        factors.load(ket_gto_norms, ket_range, 1, ket_npgtos);

        factors.replicate_points(ket_gto_coords, ket_range, 2, ket_npgtos);

        // set up active SIMD width

        const auto ket_width = ket_range.second - ket_range.first;

        sbuffer.set_active_width(ket_width);

        cbuffer.set_active_width(ket_width);

        pbuffer.set_active_width(ket_width);

        // loop over contracted basis functions on bra side

        for (auto j = bra_indices.first; j < bra_indices.second; j++)
        {
            cbuffer.zero();

            sbuffer.zero();

            const auto r_a = bra_gto_coords[j];

            t2cfunc::comp_distances_ab(factors, 5, 2, r_a);

            for (size_t k = 0; k < bra_npgtos; k++)
            {
                const auto a_exp = bra_gto_exps[k * bra_ncgtos + j];

                const auto a_norm = bra_gto_norms[k * bra_ncgtos + j];

                t2cfunc::comp_coordinates_p(factors, 8, 2, r_a, a_exp);

                t2cfunc::comp_distances_pa_from_p(factors, 11 , 8, r_a);

                t2cfunc::comp_distances_pb_from_p(factors, 14 , 8, 2);

                ovlrec::comp_prim_overlap_ss(pbuffer, 0, factors, a_exp, a_norm);

                diprec::comp_prim_electric_dipole_momentum_ss(pbuffer, 1, 0, factors, 17);

                for (size_t l = 0; l < coords.size(); l++)
                {
                    t2cfunc::comp_distances_pc(factors, 17, 8, coords[l]);

                    ovlrec::comp_prim_overlap_sp(pbuffer, 4, 0, factors, 14);

                    diprec::comp_prim_electric_dipole_momentum_sp(pbuffer, 7, 0, 1, factors, 14, a_exp);

                    ovlrec::comp_prim_overlap_sd(pbuffer, 16, 0, 4, factors, 14, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_sd(pbuffer, 22, 1, 4, 7, factors, 14, a_exp);

                    ovlrec::comp_prim_overlap_ps(pbuffer, 40, 0, factors, 11);

                    diprec::comp_prim_electric_dipole_momentum_ps(pbuffer, 43, 0, 1, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_pp(pbuffer, 52, 0, 4, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_pp(pbuffer, 61, 1, 4, 7, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_pd(pbuffer, 88, 4, 16, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_pd(pbuffer, 106, 7, 16, 22, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_ds(pbuffer, 160, 0, 40, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_ds(pbuffer, 166, 1, 40, 43, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_dp(pbuffer, 184, 4, 40, 52, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_dp(pbuffer, 202, 7, 43, 52, 61, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_dd(pbuffer, 256, 16, 52, 88, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_dd(pbuffer, 292, 22, 61, 88, 106, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_fs(pbuffer, 400, 43, 160, 166, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_fp(pbuffer, 430, 52, 160, 184, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_fp(pbuffer, 460, 61, 166, 184, 202, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_fd(pbuffer, 550, 88, 184, 256, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_fd(pbuffer, 610, 106, 202, 256, 292, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_gp(pbuffer, 790, 202, 400, 430, 460, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_gd(pbuffer, 925, 256, 430, 550, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_gd(pbuffer, 1015, 292, 460, 550, 610, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_hd(pbuffer, 1285, 610, 790, 925, 1015, factors, 11, a_exp);

                    t2cgeom::comp_prim_op_geom_10_gx(pbuffer, 1663, 610, 1285, 3, 6, a_exp);

                    t2cfunc::reduce(cbuffer, pbuffer, 0, ket_width, ket_npgtos);
                }
            }

            t2cfunc::transform<4, 2>(sbuffer, cbuffer);

            distributor.distribute(sbuffer, bra_gto_indices, ket_gto_indices, 4, 2, j, ket_range, bra_eq_ket);
        }
    }
}

} // diprec namespace

#endif /* ElectricDipoleMomentumSumRecGD_hpp */
