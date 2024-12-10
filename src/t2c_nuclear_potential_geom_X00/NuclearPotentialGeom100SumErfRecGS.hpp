#ifndef NuclearPotentialGeom100SumErfRecGS_hpp
#define NuclearPotentialGeom100SumErfRecGS_hpp

#include <cstddef>
#include <array>
#include <vector>
#include <utility>

#include "GtoBlock.hpp"
#include "SimdArray.hpp"
#include "OverlapPrimRecSS.hpp"
#include "NuclearPotentialPrimRecSS.hpp"
#include "NuclearPotentialPrimRecPS.hpp"
#include "NuclearPotentialPrimRecDS.hpp"
#include "NuclearPotentialPrimRecFS.hpp"
#include "NuclearPotentialPrimRecGS.hpp"
#include "NuclearPotentialPrimRecHS.hpp"
#include "GeometricalDerivatives1X0ForGY.hpp"

#include "BoysFunc.hpp"
#include "T2CUtils.hpp"
#include "T2CTransform.hpp"
#include "BatchFunc.hpp"

namespace npotrec { // npotrec namespace

/// @brief Computes (d^(1)/dA^(1)G|Erf(A)|S)  integrals for pair of basis functions blocks.
/// @param distributor The integrals distributor.
/// @param omegas The vector of range-separation factors.
/// @param bra_gto_block The basis functions block on bra side.
/// @param ket_gto_block The basis functions block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis functions on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis functions on ket side.
/// @param bra_eq_ket True if basis functions blocks on bra and ket are the same, False otherwise.
template <class T>
auto
comp_sum_erf_nuclear_potential_geom_10_gs(T& distributor,
                                          const std::vector<double>& omegas,
                                          const CGtoBlock& bra_gto_block,
                                          const CGtoBlock& ket_gto_block,
                                          const std::pair<size_t, size_t>& bra_indices,
                                          const std::pair<size_t, size_t>& ket_indices,
                                          const bool bra_eq_ket) -> void
{
    // intialize external coordinate(s)

    const auto coords = distributor.coordinates();

    // intialize external charge(s)

    const auto charges = distributor.data();

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

    CSimdArray<double> pbuffer(172, ket_npgtos);

    // allocate aligned contracted integrals

    CSimdArray<double> cbuffer(45, 1);

    CSimdArray<double> sbuffer(27, 1);

    // setup Boys function data

    const CBoysFunc<5> bf_table;

    CSimdArray<double> bf_data(7, ket_npgtos);

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

        bf_data.set_active_width(ket_width);

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

                ovlrec::comp_prim_overlap_ss(pbuffer, 0, factors, a_exp, a_norm);

                for (size_t l = 0; l < coords.size(); l++)
                {
                    t2cfunc::comp_distances_pc(factors, 14, 8, coords[l]);

                    t2cfunc::comp_boys_args(bf_data, 5, factors, 14, a_exp, omegas[l]);

                    bf_table.compute(bf_data, 0, 5, factors, a_exp, omegas[l]);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 1, 0, bf_data, 0, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 2, 0, bf_data, 1, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 3, 0, bf_data, 2, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 4, 0, bf_data, 3, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 5, 0, bf_data, 4, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ss(pbuffer, 6, 0, bf_data, 5, factors, a_exp);

                    npotrec::comp_prim_nuclear_potential_ps(pbuffer, 7, 1, 2, factors, 11, 14);

                    npotrec::comp_prim_nuclear_potential_ps(pbuffer, 10, 2, 3, factors, 11, 14);

                    npotrec::comp_prim_nuclear_potential_ps(pbuffer, 13, 3, 4, factors, 11, 14);

                    npotrec::comp_prim_nuclear_potential_ps(pbuffer, 16, 4, 5, factors, 11, 14);

                    npotrec::comp_prim_nuclear_potential_ps(pbuffer, 19, 5, 6, factors, 11, 14);

                    npotrec::comp_prim_nuclear_potential_ds(pbuffer, 22, 1, 2, 7, 10, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_ds(pbuffer, 28, 2, 3, 10, 13, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_ds(pbuffer, 34, 3, 4, 13, 16, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_ds(pbuffer, 40, 4, 5, 16, 19, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_fs(pbuffer, 46, 7, 10, 22, 28, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_fs(pbuffer, 56, 10, 13, 28, 34, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_fs(pbuffer, 66, 13, 16, 34, 40, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_gs(pbuffer, 76, 22, 28, 46, 56, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_gs(pbuffer, 91, 28, 34, 56, 66, factors, 11, 14, a_exp);

                    npotrec::comp_prim_nuclear_potential_hs(pbuffer, 106, 46, 56, 76, 91, factors, 11, 14, a_exp);

                    t2cgeom::comp_prim_op_geom_10_gx(pbuffer, 127, 46, 106, 1, 1, a_exp);

                    t2cfunc::reduce(cbuffer, pbuffer, 127, charges[l], ket_width, ket_npgtos);
                }
            }

            t2cfunc::transform<4, 0>(sbuffer, cbuffer);

            distributor.distribute(sbuffer, bra_gto_indices, ket_gto_indices, 4, 0, j, ket_range, bra_eq_ket);
        }
    }
}

} // npotrec namespace

#endif /* NuclearPotentialGeom100SumErfRecGS_hpp */
