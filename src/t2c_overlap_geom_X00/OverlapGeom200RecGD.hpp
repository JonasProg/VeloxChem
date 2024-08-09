#ifndef OverlapGeom200RecGD_hpp
#define OverlapGeom200RecGD_hpp

#include <cstddef>
#include <array>
#include <utility>

#include "GtoBlock.hpp"
#include "SimdArray.hpp"
#include "OverlapPrimRecSS.hpp"
#include "OverlapPrimRecSP.hpp"
#include "OverlapPrimRecSD.hpp"
#include "OverlapPrimRecPS.hpp"
#include "OverlapPrimRecPP.hpp"
#include "OverlapPrimRecPD.hpp"
#include "OverlapPrimRecDS.hpp"
#include "OverlapPrimRecDP.hpp"
#include "OverlapPrimRecDD.hpp"
#include "OverlapPrimRecFS.hpp"
#include "OverlapPrimRecFP.hpp"
#include "OverlapPrimRecFD.hpp"
#include "OverlapPrimRecGS.hpp"
#include "OverlapPrimRecGP.hpp"
#include "OverlapPrimRecGD.hpp"
#include "OverlapPrimRecHP.hpp"
#include "OverlapPrimRecHD.hpp"
#include "OverlapPrimRecID.hpp"
#include "GeometricalDerivatives2X0ForGY.hpp"

#include "T2CUtils.hpp"
#include "T2CTransform.hpp"
#include "BatchFunc.hpp"

namespace ovlrec { // ovlrec namespace

/// @brief Computes (d^(2)/dA^(2)G|D)  integrals for pair of basis functions blocks.
/// @param distributor The integrals distributor.
/// @param bra_gto_block The basis functions block on bra side.
/// @param ket_gto_block The basis functions block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis functions on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis functions on ket side.
/// @param bra_eq_ket True if basis functions blocks on bra and ket are the same, False otherwise.
template <class T>
auto
comp_overlap_geom_20_gd(T& distributor,
                        const CGtoBlock& bra_gto_block,
                        const CGtoBlock& ket_gto_block,
                        const std::pair<size_t, size_t>& bra_indices,
                        const std::pair<size_t, size_t>& ket_indices,
                        const bool bra_eq_ket) -> void
{
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

    CSimdArray<double> factors(14, ket_npgtos);

    // allocate aligned primitive integrals

    CSimdArray<double> pbuffer(1247, ket_npgtos);

    // allocate aligned contracted integrals

    CSimdArray<double> cbuffer(540, 1);

    CSimdArray<double> sbuffer(270, 1);

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

                t2cfunc::comp_distances_pa(factors, 8, 5, a_exp);

                t2cfunc::comp_distances_pb(factors, 11, 5, a_exp);

                ovlrec::comp_prim_overlap_ss(pbuffer, 0, factors, a_exp, a_norm);

                ovlrec::comp_prim_overlap_sp(pbuffer, 1, 0, factors, 11);

                ovlrec::comp_prim_overlap_sd(pbuffer, 4, 0, 1, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_ps(pbuffer, 10, 0, factors, 8);

                ovlrec::comp_prim_overlap_pp(pbuffer, 13, 0, 1, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_pd(pbuffer, 22, 1, 4, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_ds(pbuffer, 40, 0, 10, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_dp(pbuffer, 46, 1, 10, 13, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_dd(pbuffer, 64, 4, 13, 22, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_fs(pbuffer, 100, 10, 40, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_fp(pbuffer, 110, 13, 40, 46, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_fd(pbuffer, 140, 22, 46, 64, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_gs(pbuffer, 200, 40, 100, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_gp(pbuffer, 215, 46, 100, 110, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_gd(pbuffer, 260, 64, 110, 140, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_hp(pbuffer, 350, 110, 200, 215, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_hd(pbuffer, 413, 140, 215, 260, factors, 8, a_exp);

                ovlrec::comp_prim_overlap_id(pbuffer, 539, 260, 350, 413, factors, 8, a_exp);

                t2cgeom::comp_prim_op_geom_20_gx(pbuffer, 707, 64, 260, 539, 1, 6, a_exp);

                t2cfunc::reduce(cbuffer, pbuffer, 0, ket_width, ket_npgtos);
            }

            t2cfunc::transform<4, 2>(sbuffer, cbuffer);

            distributor.distribute(sbuffer, bra_gto_indices, ket_gto_indices, 4, 2, j, ket_range, bra_eq_ket);
        }
    }
}

} // ovlrec namespace

#endif /* OverlapGeom200RecGD_hpp */
