#ifndef ElectronRepulsionRecFGSS_hpp
#define ElectronRepulsionRecFGSS_hpp

#include <array>

#include "ElectronRepulsionContrRecDGXX.hpp"
#include "ElectronRepulsionContrRecDHXX.hpp"
#include "ElectronRepulsionContrRecFGXX.hpp"
#include "ElectronRepulsionContrRecPGXX.hpp"
#include "ElectronRepulsionContrRecPHXX.hpp"
#include "ElectronRepulsionContrRecPIXX.hpp"
#include "ElectronRepulsionPrimRecSDSS.hpp"
#include "ElectronRepulsionPrimRecSFSS.hpp"
#include "ElectronRepulsionPrimRecSGSS.hpp"
#include "ElectronRepulsionPrimRecSHSS.hpp"
#include "ElectronRepulsionPrimRecSISS.hpp"
#include "ElectronRepulsionPrimRecSKSS.hpp"
#include "ElectronRepulsionPrimRecSPSS.hpp"
#include "ElectronRepulsionPrimRecSSSS.hpp"
#include "SimdArray.hpp"
#include "BoysFunc.hpp"
#include "T4CUtils.hpp"
#include "T2CUtils.hpp"
#include "GtoPairBlock.hpp"

namespace erirec { // erirec namespace

/// Computes (FG|1/|r-r'||SS)  integrals for two GTOs pair blocks.
/// - Parameter distributor: the pointer to Fock matrix/matrices distributor.
/// - Parameter bra_gto_pair_block: the GTOs pair block on bra side.
/// - Parameter ket_gto_pair_block: the GTOs pair block on ket side.
/// - Parameter bra_indices: the range [bra_first, bra_last) of GTOs on bra side.
/// - Parameter ket_indices: the range [ket_first, ket_last) of GTOs on ket side.
template <class T>
auto
comp_electron_repulsion_fgss(T* distributor,
                             const CGtoPairBlock& bra_gto_pair_block,
                             const CGtoPairBlock& ket_gto_pair_block,
                             const std::array<int, 2>& bra_indices,
                             const std::array<int, 2>& ket_indices) -> void
{
    // intialize GTOs pair data on bra side

    const auto a_coords_x = bra_gto_pair_block.bra_coordinates_x();

    const auto a_coords_y = bra_gto_pair_block.bra_coordinates_y();

    const auto a_coords_z = bra_gto_pair_block.bra_coordinates_z();

    const auto b_coords_x = bra_gto_pair_block.ket_coordinates_x();

    const auto b_coords_y = bra_gto_pair_block.ket_coordinates_y();

    const auto b_coords_z = bra_gto_pair_block.ket_coordinates_z();

    const auto a_vec_exps = bra_gto_pair_block.bra_exponents();

    const auto b_vec_exps = bra_gto_pair_block.ket_exponents();

    const auto ab_vec_norms = bra_gto_pair_block.normalization_factors();

    const auto ab_vec_ovls = bra_gto_pair_block.overlap_factors();

    const auto a_indices = bra_gto_pair_block.bra_orbital_indices();

    const auto b_indices = bra_gto_pair_block.ket_orbital_indices();

    const auto bra_ncgtos = bra_gto_pair_block.number_of_contracted_pairs();

    const auto bra_npgtos = bra_gto_pair_block.number_of_primitive_pairs();

    // intialize GTOs data on ket side

    const auto c_coords_x = ket_gto_pair_block.bra_coordinates_x();

    const auto c_coords_y = ket_gto_pair_block.bra_coordinates_y();

    const auto c_coords_z = ket_gto_pair_block.bra_coordinates_z();

    const auto d_coords_x = ket_gto_pair_block.ket_coordinates_x();

    const auto d_coords_y = ket_gto_pair_block.ket_coordinates_y();

    const auto d_coords_z = ket_gto_pair_block.ket_coordinates_z();

    const auto c_vec_exps = ket_gto_pair_block.bra_exponents();

    const auto d_vec_exps = ket_gto_pair_block.ket_exponents();

    const auto cd_vec_norms = ket_gto_pair_block.normalization_factors();

    const auto cd_vec_ovls = ket_gto_pair_block.overlap_factors();

    const auto c_indices = ket_gto_pair_block.bra_orbital_indices();

    const auto d_indices = ket_gto_pair_block.ket_orbital_indices();

    const auto ket_npgtos = ket_gto_pair_block.number_of_primitive_pairs();

    // set up dimensions of bra and ket ranges

    const auto bra_dim = bra_indices[1] - bra_indices[0];

    const auto ket_dim = ket_indices[1] - ket_indices[0];

    // allocate aligned 2D arrays for ket side

    const auto ket_pdim = ket_dim * ket_npgtos;

    CSimdArray<double> c_x(1, ket_pdim);

    CSimdArray<double> c_y(1, ket_pdim);

    CSimdArray<double> c_z(1, ket_pdim);

    CSimdArray<double> d_x(1, ket_pdim);

    CSimdArray<double> d_y(1, ket_pdim);

    CSimdArray<double> d_z(1, ket_pdim);

    CSimdArray<double> c_exps(1, ket_pdim);

    CSimdArray<double> d_exps(1, ket_pdim);

    CSimdArray<double> cd_norms(1, ket_pdim);

    CSimdArray<double> cd_ovls(1, ket_pdim);

     // load GTOs data for ket side

    c_x.replicate(c_coords_x, ket_indices, ket_npgtos);

    c_y.replicate(c_coords_y, ket_indices, ket_npgtos);

    c_z.replicate(c_coords_z, ket_indices, ket_npgtos);

    d_x.replicate(d_coords_x, ket_indices, ket_npgtos);

    d_y.replicate(d_coords_y, ket_indices, ket_npgtos);

    d_z.replicate(d_coords_z, ket_indices, ket_npgtos);

    c_exps.load(c_vec_exps, ket_indices, ket_npgtos);

    d_exps.load(d_vec_exps, ket_indices, ket_npgtos);

    cd_norms.load(cd_vec_norms, ket_indices, ket_npgtos);

    cd_ovls.load(cd_vec_ovls, ket_indices, ket_npgtos);

    // allocate aligned coordinates of Q center

    CSimdArray<double> q_x(1, ket_pdim);

    CSimdArray<double> q_y(1, ket_pdim);

    CSimdArray<double> q_z(1, ket_pdim);

    // allocate aligned coordinates of W center

    CSimdArray<double> w_x(1, ket_pdim);

    CSimdArray<double> w_y(1, ket_pdim);

    CSimdArray<double> w_z(1, ket_pdim);

    // allocate aligned distances R(PQ) = P - Q

    CSimdArray<double> pq_x(1, ket_pdim);

    CSimdArray<double> pq_y(1, ket_pdim);

    CSimdArray<double> pq_z(1, ket_pdim);

    // allocate aligned distances R(WP) = W - P

    CSimdArray<double> wp_x(1, ket_pdim);

    CSimdArray<double> wp_y(1, ket_pdim);

    CSimdArray<double> wp_z(1, ket_pdim);

    // allocate combined overlap factor

    CSimdArray<double> fss_abcd(1, ket_pdim);

    // allocate aligned primitive integrals

    CSimdArray<double> prim_buffer_0_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_1_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_2_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_3_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_4_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_5_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_6_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_7_ssss(1, ket_pdim);

    CSimdArray<double> prim_buffer_0_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_1_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_2_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_3_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_4_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_5_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_6_spss(3, ket_pdim);

    CSimdArray<double> prim_buffer_0_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_1_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_2_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_3_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_4_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_5_sdss(6, ket_pdim);

    CSimdArray<double> prim_buffer_0_sfss(10, ket_pdim);

    CSimdArray<double> prim_buffer_1_sfss(10, ket_pdim);

    CSimdArray<double> prim_buffer_2_sfss(10, ket_pdim);

    CSimdArray<double> prim_buffer_3_sfss(10, ket_pdim);

    CSimdArray<double> prim_buffer_4_sfss(10, ket_pdim);

    CSimdArray<double> prim_buffer_0_sgss(15, ket_pdim);

    CSimdArray<double> prim_buffer_1_sgss(15, ket_pdim);

    CSimdArray<double> prim_buffer_2_sgss(15, ket_pdim);

    CSimdArray<double> prim_buffer_3_sgss(15, ket_pdim);

    CSimdArray<double> prim_buffer_0_shss(21, ket_pdim);

    CSimdArray<double> prim_buffer_1_shss(21, ket_pdim);

    CSimdArray<double> prim_buffer_2_shss(21, ket_pdim);

    CSimdArray<double> prim_buffer_0_siss(28, ket_pdim);

    CSimdArray<double> prim_buffer_1_siss(28, ket_pdim);

    CSimdArray<double> prim_buffer_0_skss(36, ket_pdim);

    // allocate aligned Cartesian integrals

    CSimdArray<double> cart_buffer_0_sgss(15, ket_dim);

    CSimdArray<double> cart_buffer_0_shss(21, ket_dim);

    CSimdArray<double> cart_buffer_0_siss(28, ket_dim);

    CSimdArray<double> cart_buffer_0_skss(36, ket_dim);

    // allocate aligned half transformed integrals

    CSimdArray<double> ket_spher_buffer_0_sgss(15, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_shss(21, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_siss(28, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_skss(36, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_pgss(45, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_phss(63, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_piss(84, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_dgss(90, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_dhss(126, ket_dim);

    CSimdArray<double> ket_spher_buffer_0_fgss(150, ket_dim);

    // allocate aligned spherical integrals

    CSimdArray<double> spher_buffer_0_fgss(63, ket_dim);

    // allocate accumulation buffer for integrals

    CSimdArray<double> buffer(bra_dim * 63, ket_dim);

    // setup Boys fuction data

    const CBoysFunc<7> bf_table;

    CSimdArray<double> bf_args(1, ket_pdim);

    CSimdArray<double> bf_values(8, ket_pdim);

    // loop over contracted GTOs on bra side

    for (auto i = bra_indices[0]; i < bra_indices[1]; i++)
    {
        // zero integral buffers

        cart_buffer_0_sgss.zero();

        cart_buffer_0_shss.zero();

        cart_buffer_0_siss.zero();

        cart_buffer_0_skss.zero();

        ket_spher_buffer_0_sgss.zero();

        ket_spher_buffer_0_shss.zero();

        ket_spher_buffer_0_siss.zero();

        ket_spher_buffer_0_skss.zero();

        ket_spher_buffer_0_pgss.zero();

        ket_spher_buffer_0_phss.zero();

        ket_spher_buffer_0_piss.zero();

        ket_spher_buffer_0_dgss.zero();

        ket_spher_buffer_0_dhss.zero();

        ket_spher_buffer_0_fgss.zero();

        spher_buffer_0_fgss.zero();

        // set up coordinates on bra side

        const auto a_x = a_coords_x[i];

        const auto a_y = a_coords_y[i];

        const auto a_z = a_coords_z[i];

        const auto b_x = b_coords_x[i];

        const auto b_y = b_coords_y[i];

        const auto b_z = b_coords_z[i];

        // set up distances on bra side

        const auto ab_x = a_x - b_x;

        const auto ab_y = a_y - b_y;

        const auto ab_z = a_z - b_z;

        for (int j = 0; j < bra_npgtos; j++)
        {
            const auto a_exp = a_vec_exps[j * bra_ncgtos + i];

            const auto b_exp = b_vec_exps[j * bra_ncgtos + i];

            const auto ab_norm = ab_vec_norms[j * bra_ncgtos + i];

            const auto ab_ovl = ab_vec_ovls[j * bra_ncgtos + i];

            const auto p_x = (a_x * a_exp + b_x * b_exp) / (a_exp + b_exp);

            const auto p_y = (a_y * a_exp + b_y * b_exp) / (a_exp + b_exp);

            const auto p_z = (a_z * a_exp + b_z * b_exp) / (a_exp + b_exp);

            const auto pb_x = p_x - b_x;

            const auto pb_y = p_y - b_y;

            const auto pb_z = p_z - b_z;

            t4cfunc::comp_coordinates_q(q_x[0], q_y[0], q_z[0], c_x[0], c_y[0], c_z[0], d_x[0], d_y[0], d_z[0], c_exps[0], d_exps[0], ket_pdim);

            t4cfunc::comp_coordinates_w(w_x[0], w_y[0], w_z[0], p_x, p_y, p_z, q_x[0], q_y[0], q_z[0], a_exp, b_exp, c_exps[0], d_exps[0], ket_pdim);

            t4cfunc::comp_distances_pq(pq_x[0], pq_y[0], pq_z[0], p_x, p_y, p_z, q_x[0], q_y[0], q_z[0], ket_pdim);

            t4cfunc::comp_distances_wp(wp_x[0], wp_y[0], wp_z[0], w_x[0], w_y[0], w_z[0], p_x, p_y, p_z, ket_pdim);

            t4cfunc::comp_boys_args(bf_args, pq_x[0], pq_y[0], pq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            bf_table.compute(bf_values, bf_args);

            t4cfunc::comp_ovl_factors(fss_abcd, ab_ovl, cd_ovls[0], ab_norm, cd_norms[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_0_ssss, fss_abcd[0], bf_values[0]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_1_ssss, fss_abcd[0], bf_values[1]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_2_ssss, fss_abcd[0], bf_values[2]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_3_ssss, fss_abcd[0], bf_values[3]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_4_ssss, fss_abcd[0], bf_values[4]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_5_ssss, fss_abcd[0], bf_values[5]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_6_ssss, fss_abcd[0], bf_values[6]);

            erirec::comp_prim_electron_repulsion_ssss(prim_buffer_7_ssss, fss_abcd[0], bf_values[7]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_0_spss, prim_buffer_0_ssss, prim_buffer_1_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_1_spss, prim_buffer_1_ssss, prim_buffer_2_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_2_spss, prim_buffer_2_ssss, prim_buffer_3_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_3_spss, prim_buffer_3_ssss, prim_buffer_4_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_4_spss, prim_buffer_4_ssss, prim_buffer_5_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_5_spss, prim_buffer_5_ssss, prim_buffer_6_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_6_spss, prim_buffer_6_ssss, prim_buffer_7_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_0_sdss, prim_buffer_0_ssss, prim_buffer_1_ssss, prim_buffer_0_spss, prim_buffer_1_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_1_sdss, prim_buffer_1_ssss, prim_buffer_2_ssss, prim_buffer_1_spss, prim_buffer_2_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_2_sdss, prim_buffer_2_ssss, prim_buffer_3_ssss, prim_buffer_2_spss, prim_buffer_3_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_3_sdss, prim_buffer_3_ssss, prim_buffer_4_ssss, prim_buffer_3_spss, prim_buffer_4_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_4_sdss, prim_buffer_4_ssss, prim_buffer_5_ssss, prim_buffer_4_spss, prim_buffer_5_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdss(prim_buffer_5_sdss, prim_buffer_5_ssss, prim_buffer_6_ssss, prim_buffer_5_spss, prim_buffer_6_spss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfss(prim_buffer_0_sfss, prim_buffer_0_spss, prim_buffer_1_spss, prim_buffer_0_sdss, prim_buffer_1_sdss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfss(prim_buffer_1_sfss, prim_buffer_1_spss, prim_buffer_2_spss, prim_buffer_1_sdss, prim_buffer_2_sdss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfss(prim_buffer_2_sfss, prim_buffer_2_spss, prim_buffer_3_spss, prim_buffer_2_sdss, prim_buffer_3_sdss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfss(prim_buffer_3_sfss, prim_buffer_3_spss, prim_buffer_4_spss, prim_buffer_3_sdss, prim_buffer_4_sdss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfss(prim_buffer_4_sfss, prim_buffer_4_spss, prim_buffer_5_spss, prim_buffer_4_sdss, prim_buffer_5_sdss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sgss(prim_buffer_0_sgss, prim_buffer_0_sdss, prim_buffer_1_sdss, prim_buffer_0_sfss, prim_buffer_1_sfss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sgss(prim_buffer_1_sgss, prim_buffer_1_sdss, prim_buffer_2_sdss, prim_buffer_1_sfss, prim_buffer_2_sfss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sgss(prim_buffer_2_sgss, prim_buffer_2_sdss, prim_buffer_3_sdss, prim_buffer_2_sfss, prim_buffer_3_sfss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sgss(prim_buffer_3_sgss, prim_buffer_3_sdss, prim_buffer_4_sdss, prim_buffer_3_sfss, prim_buffer_4_sfss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_shss(prim_buffer_0_shss, prim_buffer_0_sfss, prim_buffer_1_sfss, prim_buffer_0_sgss, prim_buffer_1_sgss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_shss(prim_buffer_1_shss, prim_buffer_1_sfss, prim_buffer_2_sfss, prim_buffer_1_sgss, prim_buffer_2_sgss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_shss(prim_buffer_2_shss, prim_buffer_2_sfss, prim_buffer_3_sfss, prim_buffer_2_sgss, prim_buffer_3_sgss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_siss(prim_buffer_0_siss, prim_buffer_0_sgss, prim_buffer_1_sgss, prim_buffer_0_shss, prim_buffer_1_shss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_siss(prim_buffer_1_siss, prim_buffer_1_sgss, prim_buffer_2_sgss, prim_buffer_1_shss, prim_buffer_2_shss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_skss(prim_buffer_0_skss, prim_buffer_0_shss, prim_buffer_1_shss, prim_buffer_0_siss, prim_buffer_1_siss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            t2cfunc::reduce(cart_buffer_0_sgss, prim_buffer_0_sgss, ket_dim, ket_npgtos);

            t2cfunc::reduce(cart_buffer_0_shss, prim_buffer_0_shss, ket_dim, ket_npgtos);

            t2cfunc::reduce(cart_buffer_0_siss, prim_buffer_0_siss, ket_dim, ket_npgtos);

            t2cfunc::reduce(cart_buffer_0_skss, prim_buffer_0_skss, ket_dim, ket_npgtos);

        }

        t4cfunc::ket_transform<0, 0>(ket_spher_buffer_0_sgss, cart_buffer_0_sgss, 0, 4);

        t4cfunc::ket_transform<0, 0>(ket_spher_buffer_0_shss, cart_buffer_0_shss, 0, 5);

        t4cfunc::ket_transform<0, 0>(ket_spher_buffer_0_siss, cart_buffer_0_siss, 0, 6);

        t4cfunc::ket_transform<0, 0>(ket_spher_buffer_0_skss, cart_buffer_0_skss, 0, 7);

        erirec::comp_bra_hrr_electron_repulsion_pgxx(ket_spher_buffer_0_pgss, ket_spher_buffer_0_sgss, ket_spher_buffer_0_shss, ab_x, ab_y, ab_z, 0, 0);

        erirec::comp_bra_hrr_electron_repulsion_phxx(ket_spher_buffer_0_phss, ket_spher_buffer_0_shss, ket_spher_buffer_0_siss, ab_x, ab_y, ab_z, 0, 0);

        erirec::comp_bra_hrr_electron_repulsion_pixx(ket_spher_buffer_0_piss, ket_spher_buffer_0_siss, ket_spher_buffer_0_skss, ab_x, ab_y, ab_z, 0, 0);

        erirec::comp_bra_hrr_electron_repulsion_dgxx(ket_spher_buffer_0_dgss, ket_spher_buffer_0_pgss, ket_spher_buffer_0_phss, ab_x, ab_y, ab_z, 0, 0);

        erirec::comp_bra_hrr_electron_repulsion_dhxx(ket_spher_buffer_0_dhss, ket_spher_buffer_0_phss, ket_spher_buffer_0_piss, ab_x, ab_y, ab_z, 0, 0);

        erirec::comp_bra_hrr_electron_repulsion_fgxx(ket_spher_buffer_0_fgss, ket_spher_buffer_0_dgss, ket_spher_buffer_0_dhss, ab_x, ab_y, ab_z, 0, 0);

        t4cfunc::bra_transform<3, 4>(spher_buffer_0_fgss, ket_spher_buffer_0_fgss, 0, 0);

        t4cfunc::store_values(buffer, spher_buffer_0_fgss, 63 * (i - bra_indices[0]));
    }

    distributor->distribute(buffer, a_indices, b_indices, c_indices, d_indices, 3, 4, 0, 0, bra_indices, ket_indices);
}

} // erirec namespace

#endif /* ElectronRepulsionRecFGSS_hpp */
