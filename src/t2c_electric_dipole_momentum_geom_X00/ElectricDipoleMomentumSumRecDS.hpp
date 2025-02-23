#ifndef ElectricDipoleMomentumSumRecDS_hpp
#define ElectricDipoleMomentumSumRecDS_hpp

#include <array>
#include <cstddef>
#include <utility>

#include "BatchFunc.hpp"
#include "ElectricDipoleMomentumPrimRecDS.hpp"
#include "ElectricDipoleMomentumPrimRecFS.hpp"
#include "ElectricDipoleMomentumPrimRecPS.hpp"
#include "ElectricDipoleMomentumPrimRecSS.hpp"
#include "GeometricalDerivatives1X0ForDY.hpp"
#include "GtoBlock.hpp"
#include "OverlapPrimRecDS.hpp"
#include "OverlapPrimRecPS.hpp"
#include "OverlapPrimRecSS.hpp"
#include "SimdArray.hpp"
#include "T2CTransform.hpp"
#include "T2CUtils.hpp"

namespace diprec {  // diprec namespace

/// @brief Computes (d^(1)/dA^(1)D|r|S)  integrals for pair of basis functions blocks.
/// @param distributor The integrals distributor.
/// @param bra_gto_block The basis functions block on bra side.
/// @param ket_gto_block The basis functions block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis functions on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis functions on ket side.
/// @param bra_eq_ket True if basis functions blocks on bra and ket are the same, False otherwise.
template <class T>
auto
comp_sum_electric_dipole_momentum_geom_10_ds(T&                               distributor,
                                             const CGtoBlock&                 bra_gto_block,
                                             const CGtoBlock&                 ket_gto_block,
                                             const std::pair<size_t, size_t>& bra_indices,
                                             const std::pair<size_t, size_t>& ket_indices,
                                             const bool                       bra_eq_ket) -> void
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

    CSimdArray<double> factors(17, ket_npgtos);

    // allocate aligned primitive integrals

    CSimdArray<double> pbuffer(124, ket_npgtos);

    // allocate aligned contracted integrals

    CSimdArray<double> cbuffer(54, 1);

    CSimdArray<double> sbuffer(45, 1);

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

                t2cfunc::comp_distances_pa_from_p(factors, 11, 8, r_a);

                ovlrec::comp_prim_overlap_ss(pbuffer, 0, factors, a_exp, a_norm);

                diprec::comp_prim_electric_dipole_momentum_ss(pbuffer, 1, 0, factors, 14);

                for (size_t l = 0; l < coords.size(); l++)
                {
                    t2cfunc::comp_distances_pc(factors, 14, 8, coords[l]);

                    ovlrec::comp_prim_overlap_ps(pbuffer, 4, 0, factors, 11);

                    diprec::comp_prim_electric_dipole_momentum_ps(pbuffer, 7, 0, 1, factors, 11, a_exp);

                    ovlrec::comp_prim_overlap_ds(pbuffer, 16, 0, 4, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_ds(pbuffer, 22, 1, 4, 7, factors, 11, a_exp);

                    diprec::comp_prim_electric_dipole_momentum_fs(pbuffer, 40, 7, 16, 22, factors, 11, a_exp);

                    t2cgeom::comp_prim_op_geom_10_dx(pbuffer, 70, 7, 40, 3, 1, a_exp);

                    t2cfunc::reduce(cbuffer, pbuffer, 0, ket_width, ket_npgtos);
                }
            }

            t2cfunc::transform<2, 0>(sbuffer, cbuffer);

            distributor.distribute(sbuffer, bra_gto_indices, ket_gto_indices, 2, 0, j, ket_range, bra_eq_ket);
        }
    }
}

}  // namespace diprec

#endif /* ElectricDipoleMomentumSumRecDS_hpp */
