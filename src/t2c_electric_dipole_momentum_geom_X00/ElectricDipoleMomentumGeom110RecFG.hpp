#ifndef ElectricDipoleMomentumGeom110RecFG_hpp
#define ElectricDipoleMomentumGeom110RecFG_hpp

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
#include "OverlapPrimRecSF.hpp"
#include "ElectricDipoleMomentumPrimRecSF.hpp"
#include "OverlapPrimRecSG.hpp"
#include "ElectricDipoleMomentumPrimRecSG.hpp"
#include "ElectricDipoleMomentumPrimRecPP.hpp"
#include "OverlapPrimRecPD.hpp"
#include "ElectricDipoleMomentumPrimRecPD.hpp"
#include "OverlapPrimRecPF.hpp"
#include "ElectricDipoleMomentumPrimRecPF.hpp"
#include "OverlapPrimRecPG.hpp"
#include "ElectricDipoleMomentumPrimRecPG.hpp"
#include "ElectricDipoleMomentumPrimRecDD.hpp"
#include "OverlapPrimRecDF.hpp"
#include "ElectricDipoleMomentumPrimRecDF.hpp"
#include "OverlapPrimRecDG.hpp"
#include "ElectricDipoleMomentumPrimRecDG.hpp"
#include "ElectricDipoleMomentumPrimRecFF.hpp"
#include "OverlapPrimRecFG.hpp"
#include "ElectricDipoleMomentumPrimRecFG.hpp"
#include "ElectricDipoleMomentumPrimRecGG.hpp"
#include "GeometricalDerivatives1X0ForFY.hpp"

#include "T2CUtils.hpp"
#include "T2CTransform.hpp"
#include "BatchFunc.hpp"

namespace diprec { // diprec namespace

/// @brief Computes (d^(1)/dA^(1)F|r|G)  integrals for pair of basis functions blocks.
/// @param distributor The integrals distributor.
/// @param bra_gto_block The basis functions block on bra side.
/// @param ket_gto_block The basis functions block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis functions on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis functions on ket side.
/// @param bra_eq_ket True if basis functions blocks on bra and ket are the same, False otherwise.
template <class T>
auto
comp_electric_dipole_momentum_geom_10_fg(T& distributor,
                                         const CGtoBlock& bra_gto_block,
                                         const CGtoBlock& ket_gto_block,
                                         const std::pair<size_t, size_t>& bra_indices,
                                         const std::pair<size_t, size_t>& ket_indices,
                                         const bool bra_eq_ket) -> void
{
    // intialize external coordinate(s)

    const auto r_c = distributor.coordinates()[0];

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

    CSimdArray<double> pbuffer(4172, ket_npgtos);

    // allocate aligned contracted integrals

    CSimdArray<double> cbuffer(1350, 1);

    CSimdArray<double> sbuffer(567, 1);

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

                t2cfunc::comp_distances_pc(factors, 17, 8, r_c);

                ovlrec::comp_prim_overlap_ss(pbuffer, 0, factors, a_exp, a_norm);

                diprec::comp_prim_electric_dipole_momentum_ss(pbuffer, 1, 0, factors, 17);

                ovlrec::comp_prim_overlap_sp(pbuffer, 4, 0, factors, 14);

                diprec::comp_prim_electric_dipole_momentum_sp(pbuffer, 7, 0, 1, factors, 14, a_exp);

                ovlrec::comp_prim_overlap_sd(pbuffer, 16, 0, 4, factors, 14, a_exp);

                diprec::comp_prim_electric_dipole_momentum_sd(pbuffer, 22, 1, 4, 7, factors, 14, a_exp);

                ovlrec::comp_prim_overlap_sf(pbuffer, 40, 4, 16, factors, 14, a_exp);

                diprec::comp_prim_electric_dipole_momentum_sf(pbuffer, 50, 7, 16, 22, factors, 14, a_exp);

                ovlrec::comp_prim_overlap_sg(pbuffer, 80, 16, 40, factors, 14, a_exp);

                diprec::comp_prim_electric_dipole_momentum_sg(pbuffer, 95, 22, 40, 50, factors, 14, a_exp);

                diprec::comp_prim_electric_dipole_momentum_pp(pbuffer, 140, 1, 4, 7, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_pd(pbuffer, 167, 4, 16, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_pd(pbuffer, 185, 7, 16, 22, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_pf(pbuffer, 239, 16, 40, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_pf(pbuffer, 269, 22, 40, 50, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_pg(pbuffer, 359, 40, 80, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_pg(pbuffer, 404, 50, 80, 95, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_dd(pbuffer, 539, 22, 140, 167, 185, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_df(pbuffer, 647, 40, 167, 239, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_df(pbuffer, 707, 50, 185, 239, 269, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_dg(pbuffer, 887, 80, 239, 359, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_dg(pbuffer, 977, 95, 269, 359, 404, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_ff(pbuffer, 1247, 269, 539, 647, 707, factors, 11, a_exp);

                ovlrec::comp_prim_overlap_fg(pbuffer, 1547, 359, 647, 887, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_fg(pbuffer, 1697, 404, 707, 887, 977, factors, 11, a_exp);

                diprec::comp_prim_electric_dipole_momentum_gg(pbuffer, 2147, 977, 1247, 1547, 1697, factors, 11, a_exp);

                t2cgeom::comp_prim_op_geom_10_fx(pbuffer, 2822, 977, 2147, 3, 15, a_exp);

                t2cfunc::reduce(cbuffer, pbuffer, 2822, ket_width, ket_npgtos);
            }

            t2cfunc::transform<3, 4>(sbuffer, cbuffer);

            distributor.distribute(sbuffer, bra_gto_indices, ket_gto_indices, 3, 4, j, ket_range, bra_eq_ket);
        }
    }
}

} // diprec namespace

#endif /* ElectricDipoleMomentumGeom110RecFG_hpp */
