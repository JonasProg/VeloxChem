#ifndef ElectronRepulsionDiagRecPDPD_hpp
#define ElectronRepulsionDiagRecPDPD_hpp

#include <vector>
#include <array>

#include "ElectronRepulsionContrRecPDXX.hpp"
#include "ElectronRepulsionContrRecXXPD.hpp"
#include "ElectronRepulsionPrimRecSDSD.hpp"
#include "ElectronRepulsionPrimRecSDSF.hpp"
#include "ElectronRepulsionPrimRecSDSP.hpp"
#include "ElectronRepulsionPrimRecSFSD.hpp"
#include "ElectronRepulsionPrimRecSFSF.hpp"
#include "ElectronRepulsionPrimRecSPSD.hpp"
#include "ElectronRepulsionPrimRecSPSF.hpp"
#include "ElectronRepulsionPrimRecSPSP.hpp"
#include "ElectronRepulsionPrimRecSPSS.hpp"
#include "ElectronRepulsionPrimRecSSSD.hpp"
#include "ElectronRepulsionPrimRecSSSF.hpp"
#include "ElectronRepulsionPrimRecSSSP.hpp"
#include "ElectronRepulsionPrimRecSSSS.hpp"
#include "SimdArray.hpp"
#include "BoysFunc.hpp"
#include "T4CUtils.hpp"
#include "T2CUtils.hpp"
#include "GtoPairBlock.hpp"

namespace erirec { // erirec namespace

/// Computes (PD|1/|r-r'||PD)  integrals for GTOs pair block.
/// - Parameter distributor: the pointer to screening data distributor.
/// - Parameter gto_pair_block: the GTOs pair block.
/// - Parameter go_indices: the range [gto_first, gto_last) of GTOs on bra and ket sides.
template <class T>
auto
comp_diag_electron_repulsion_pdpd(T* distributor,
                                  const CGtoPairBlock& gto_pair_block,
                                  const std::array<int, 2>& gto_indices) -> void
{
    // intialize GTOs pair data

    const auto a_coords_x = gto_pair_block.bra_coordinates_x();

    const auto a_coords_y = gto_pair_block.bra_coordinates_y();

    const auto a_coords_z = gto_pair_block.bra_coordinates_z();

    const auto b_coords_x = gto_pair_block.ket_coordinates_x();

    const auto b_coords_y = gto_pair_block.ket_coordinates_y();

    const auto b_coords_z = gto_pair_block.ket_coordinates_z();

    const auto a_vec_exps = gto_pair_block.bra_exponents();

    const auto b_vec_exps = gto_pair_block.ket_exponents();

    const auto ab_vec_norms = gto_pair_block.normalization_factors();

    const auto ab_vec_ovls = gto_pair_block.overlap_factors();

    const auto a_indices = gto_pair_block.bra_orbital_indices();

    const auto b_indices = gto_pair_block.ket_orbital_indices();

    const auto ncgtos = gto_pair_block.number_of_contracted_pairs();

    const auto npgtos = gto_pair_block.number_of_primitive_pairs();

    // allocate aligned 2D arrays for ket side

    CSimdArray<double> c_x(1, npgtos);

    CSimdArray<double> c_y(1, npgtos);

    CSimdArray<double> c_z(1, npgtos);

    CSimdArray<double> d_x(1, npgtos);

    CSimdArray<double> d_y(1, npgtos);

    CSimdArray<double> d_z(1, npgtos);

    CSimdArray<double> c_exps(1, npgtos);

    CSimdArray<double> d_exps(1, npgtos);

    CSimdArray<double> cd_norms(1, npgtos);

    CSimdArray<double> cd_ovls(1, npgtos);

    // allocate aligned coordinates of Q center

    CSimdArray<double> q_x(1, npgtos);

    CSimdArray<double> q_y(1, npgtos);

    CSimdArray<double> q_z(1, npgtos);

    // allocate aligned coordinates of W center

    CSimdArray<double> w_x(1, npgtos);

    CSimdArray<double> w_y(1, npgtos);

    CSimdArray<double> w_z(1, npgtos);

    // allocate aligned distances R(PQ) = P - Q

    CSimdArray<double> pq_x(1, npgtos);

    CSimdArray<double> pq_y(1, npgtos);

    CSimdArray<double> pq_z(1, npgtos);

    // allocate aligned distances R(QD) = Q - D

    CSimdArray<double> qd_x(1, npgtos);

    CSimdArray<double> qd_y(1, npgtos);

    CSimdArray<double> qd_z(1, npgtos);

    // allocate aligned distances R(WQ) = W - Q

    CSimdArray<double> wq_x(1, npgtos);

    CSimdArray<double> wq_y(1, npgtos);

    CSimdArray<double> wq_z(1, npgtos);

    // allocate aligned distances R(WP) = W - P

    CSimdArray<double> wp_x(1, npgtos);

    CSimdArray<double> wp_y(1, npgtos);

    CSimdArray<double> wp_z(1, npgtos);

    // allocate combined overlap factor

    CSimdArray<double> fss_abcd(1, npgtos);

    // allocate and initialize aligned distances R(CD) = C - D

    CSimdArray<double> cd_x(1, 1);

    CSimdArray<double> cd_y(1, 1);

    CSimdArray<double> cd_z(1, 1);

    // allocate aligned primitive integrals

    CSimdArray<double> prim_buffer_0_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_1_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_2_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_3_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_4_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_5_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_6_ssss(1, npgtos);

    CSimdArray<double> prim_buffer_0_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_1_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_2_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_3_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_4_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_5_sssp(3, npgtos);

    CSimdArray<double> prim_buffer_0_sssd(6, npgtos);

    CSimdArray<double> prim_buffer_1_sssd(6, npgtos);

    CSimdArray<double> prim_buffer_2_sssd(6, npgtos);

    CSimdArray<double> prim_buffer_3_sssd(6, npgtos);

    CSimdArray<double> prim_buffer_4_sssd(6, npgtos);

    CSimdArray<double> prim_buffer_0_sssf(10, npgtos);

    CSimdArray<double> prim_buffer_1_sssf(10, npgtos);

    CSimdArray<double> prim_buffer_2_sssf(10, npgtos);

    CSimdArray<double> prim_buffer_3_sssf(10, npgtos);

    CSimdArray<double> prim_buffer_2_spss(3, npgtos);

    CSimdArray<double> prim_buffer_1_spsp(9, npgtos);

    CSimdArray<double> prim_buffer_2_spsp(9, npgtos);

    CSimdArray<double> prim_buffer_0_spsd(18, npgtos);

    CSimdArray<double> prim_buffer_1_spsd(18, npgtos);

    CSimdArray<double> prim_buffer_2_spsd(18, npgtos);

    CSimdArray<double> prim_buffer_0_spsf(30, npgtos);

    CSimdArray<double> prim_buffer_1_spsf(30, npgtos);

    CSimdArray<double> prim_buffer_2_spsf(30, npgtos);

    CSimdArray<double> prim_buffer_1_sdsp(18, npgtos);

    CSimdArray<double> prim_buffer_0_sdsd(36, npgtos);

    CSimdArray<double> prim_buffer_1_sdsd(36, npgtos);

    CSimdArray<double> prim_buffer_0_sdsf(60, npgtos);

    CSimdArray<double> prim_buffer_1_sdsf(60, npgtos);

    CSimdArray<double> prim_buffer_0_sfsd(60, npgtos);

    CSimdArray<double> prim_buffer_0_sfsf(100, npgtos);

    // allocate aligned Cartesian integrals

    CSimdArray<double> cart_buffer_0_sdsd(36, 1);

    CSimdArray<double> cart_buffer_0_sdsf(60, 1);

    CSimdArray<double> cart_buffer_0_sfsd(60, 1);

    CSimdArray<double> cart_buffer_0_sfsf(100, 1);

    // allocate aligned contracted integrals

    CSimdArray<double> contr_buffer_0_sdpd(108, 1);

    CSimdArray<double> contr_buffer_0_sfpd(180, 1);

    // allocate aligned half transformed integrals

    CSimdArray<double> ket_spher_buffer_0_sdpd(90, 1);

    CSimdArray<double> ket_spher_buffer_0_sfpd(150, 1);

    CSimdArray<double> ket_spher_buffer_0_pdpd(270, 1);

    // allocate aligned spherical integrals

    CSimdArray<double> spher_buffer_0_pdpd(225, 1);

    // setup Boys fuction data

    const CBoysFunc<6> bf_table;

    CSimdArray<double> bf_args(1, npgtos);

    CSimdArray<double> bf_values(7, npgtos);

    // allocate aligned array to store max. integral values

    const auto gto_dim = gto_indices[1] - gto_indices[0];

    std::vector<double> max_values(gto_dim, 0.0);

    // loop over contracted GTOs on bra and ket sides

    for (auto i = gto_indices[0]; i < gto_indices[1]; i++)
    {
        // set up indices on ket side

        std::array<int, 2> ket_indices({i, i + 1});

        // zero integral buffers

        cart_buffer_0_sdsd.zero();

        cart_buffer_0_sdsf.zero();

        cart_buffer_0_sfsd.zero();

        cart_buffer_0_sfsf.zero();

        ket_spher_buffer_0_sdpd.zero();

        ket_spher_buffer_0_sfpd.zero();

        ket_spher_buffer_0_pdpd.zero();

        spher_buffer_0_pdpd.zero();

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

         // load GTOs data for ket side

        c_x.replicate(a_coords_x, ket_indices, npgtos);

        c_y.replicate(a_coords_y, ket_indices, npgtos);

        c_z.replicate(a_coords_z, ket_indices, npgtos);

        d_x.replicate(b_coords_x, ket_indices, npgtos);

        d_y.replicate(b_coords_y, ket_indices, npgtos);

        d_z.replicate(b_coords_z, ket_indices, npgtos);

        c_exps.load(a_vec_exps, ket_indices, npgtos);

        d_exps.load(b_vec_exps, ket_indices, npgtos);

        cd_norms.load(ab_vec_norms, ket_indices, npgtos);

        cd_ovls.load(ab_vec_ovls, ket_indices, npgtos);

        // set up distances on bra side

        t4cfunc::comp_distances_cd(cd_x[0], cd_y[0], cd_z[0], c_x[0], c_y[0], c_z[0], d_x[0], d_y[0], d_z[0], 1);

        for (int j = 0; j < npgtos; j++)
        {
            const auto a_exp = a_vec_exps[j * ncgtos + i];

            const auto b_exp = b_vec_exps[j * ncgtos + i];

            const auto ab_norm = ab_vec_norms[j * ncgtos + i];

            const auto ab_ovl = ab_vec_ovls[j * ncgtos + i];

            const auto p_x = (a_x * a_exp + b_x * b_exp) / (a_exp + b_exp);

            const auto p_y = (a_y * a_exp + b_y * b_exp) / (a_exp + b_exp);

            const auto p_z = (a_z * a_exp + b_z * b_exp) / (a_exp + b_exp);

            const auto pb_x = p_x - b_x;

            const auto pb_y = p_y - b_y;

            const auto pb_z = p_z - b_z;

            t4cfunc::comp_coordinates_q(q_x[0], q_y[0], q_z[0], c_x[0], c_y[0], c_z[0], d_x[0], d_y[0], d_z[0], c_exps[0], d_exps[0], npgtos);

            t4cfunc::comp_coordinates_w(w_x[0], w_y[0], w_z[0], p_x, p_y, p_z, q_x[0], q_y[0], q_z[0], a_exp, b_exp, c_exps[0], d_exps[0], npgtos);

            t4cfunc::comp_distances_pq(pq_x[0], pq_y[0], pq_z[0], p_x, p_y, p_z, q_x[0], q_y[0], q_z[0], npgtos);

            t4cfunc::comp_distances_wq(wq_x[0], wq_y[0], wq_z[0], w_x[0], w_y[0], w_z[0], q_x[0], q_y[0], q_z[0], npgtos);

            t4cfunc::comp_distances_qd(qd_x[0], qd_y[0], qd_z[0], q_x[0], q_y[0], q_z[0], d_x[0], d_y[0], d_z[0], npgtos);

            t4cfunc::comp_distances_wp(wp_x[0], wp_y[0], wp_z[0], w_x[0], w_y[0], w_z[0], p_x, p_y, p_z, npgtos);

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

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_0_sssp, prim_buffer_0_ssss, prim_buffer_1_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_1_sssp, prim_buffer_1_ssss, prim_buffer_2_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_2_sssp, prim_buffer_2_ssss, prim_buffer_3_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_3_sssp, prim_buffer_3_ssss, prim_buffer_4_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_4_sssp, prim_buffer_4_ssss, prim_buffer_5_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssp(prim_buffer_5_sssp, prim_buffer_5_ssss, prim_buffer_6_ssss, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0]);

            erirec::comp_prim_electron_repulsion_sssd(prim_buffer_0_sssd, prim_buffer_0_ssss, prim_buffer_1_ssss, prim_buffer_0_sssp, prim_buffer_1_sssp, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssd(prim_buffer_1_sssd, prim_buffer_1_ssss, prim_buffer_2_ssss, prim_buffer_1_sssp, prim_buffer_2_sssp, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssd(prim_buffer_2_sssd, prim_buffer_2_ssss, prim_buffer_3_ssss, prim_buffer_2_sssp, prim_buffer_3_sssp, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssd(prim_buffer_3_sssd, prim_buffer_3_ssss, prim_buffer_4_ssss, prim_buffer_3_sssp, prim_buffer_4_sssp, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssd(prim_buffer_4_sssd, prim_buffer_4_ssss, prim_buffer_5_ssss, prim_buffer_4_sssp, prim_buffer_5_sssp, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssf(prim_buffer_0_sssf, prim_buffer_0_sssp, prim_buffer_1_sssp, prim_buffer_0_sssd, prim_buffer_1_sssd, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssf(prim_buffer_1_sssf, prim_buffer_1_sssp, prim_buffer_2_sssp, prim_buffer_1_sssd, prim_buffer_2_sssd, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssf(prim_buffer_2_sssf, prim_buffer_2_sssp, prim_buffer_3_sssp, prim_buffer_2_sssd, prim_buffer_3_sssd, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sssf(prim_buffer_3_sssf, prim_buffer_3_sssp, prim_buffer_4_sssp, prim_buffer_3_sssd, prim_buffer_4_sssd, qd_x[0], qd_y[0], qd_z[0], wq_x[0], wq_y[0], wq_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spss(prim_buffer_2_spss, prim_buffer_2_ssss, prim_buffer_3_ssss, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0]);

            erirec::comp_prim_electron_repulsion_spsp(prim_buffer_1_spsp, prim_buffer_2_ssss, prim_buffer_1_sssp, prim_buffer_2_sssp, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsp(prim_buffer_2_spsp, prim_buffer_3_ssss, prim_buffer_2_sssp, prim_buffer_3_sssp, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsd(prim_buffer_0_spsd, prim_buffer_1_sssp, prim_buffer_0_sssd, prim_buffer_1_sssd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsd(prim_buffer_1_spsd, prim_buffer_2_sssp, prim_buffer_1_sssd, prim_buffer_2_sssd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsd(prim_buffer_2_spsd, prim_buffer_3_sssp, prim_buffer_2_sssd, prim_buffer_3_sssd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsf(prim_buffer_0_spsf, prim_buffer_1_sssd, prim_buffer_0_sssf, prim_buffer_1_sssf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsf(prim_buffer_1_spsf, prim_buffer_2_sssd, prim_buffer_1_sssf, prim_buffer_2_sssf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_spsf(prim_buffer_2_spsf, prim_buffer_3_sssd, prim_buffer_2_sssf, prim_buffer_3_sssf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdsp(prim_buffer_1_sdsp, prim_buffer_1_sssp, prim_buffer_2_sssp, prim_buffer_2_spss, prim_buffer_1_spsp, prim_buffer_2_spsp, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdsd(prim_buffer_0_sdsd, prim_buffer_0_sssd, prim_buffer_1_sssd, prim_buffer_1_spsp, prim_buffer_0_spsd, prim_buffer_1_spsd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdsd(prim_buffer_1_sdsd, prim_buffer_1_sssd, prim_buffer_2_sssd, prim_buffer_2_spsp, prim_buffer_1_spsd, prim_buffer_2_spsd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdsf(prim_buffer_0_sdsf, prim_buffer_0_sssf, prim_buffer_1_sssf, prim_buffer_1_spsd, prim_buffer_0_spsf, prim_buffer_1_spsf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sdsf(prim_buffer_1_sdsf, prim_buffer_1_sssf, prim_buffer_2_sssf, prim_buffer_2_spsd, prim_buffer_1_spsf, prim_buffer_2_spsf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfsd(prim_buffer_0_sfsd, prim_buffer_0_spsd, prim_buffer_1_spsd, prim_buffer_1_sdsp, prim_buffer_0_sdsd, prim_buffer_1_sdsd, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            erirec::comp_prim_electron_repulsion_sfsf(prim_buffer_0_sfsf, prim_buffer_0_spsf, prim_buffer_1_spsf, prim_buffer_1_sdsd, prim_buffer_0_sdsf, prim_buffer_1_sdsf, pb_x, pb_y, pb_z, wp_x[0], wp_y[0], wp_z[0], a_exp, b_exp, c_exps[0], d_exps[0]);

            t2cfunc::reduce(cart_buffer_0_sdsd, prim_buffer_0_sdsd, 1, npgtos);

            t2cfunc::reduce(cart_buffer_0_sdsf, prim_buffer_0_sdsf, 1, npgtos);

            t2cfunc::reduce(cart_buffer_0_sfsd, prim_buffer_0_sfsd, 1, npgtos);

            t2cfunc::reduce(cart_buffer_0_sfsf, prim_buffer_0_sfsf, 1, npgtos);

        }

        erirec::comp_ket_hrr_electron_repulsion_xxpd(contr_buffer_0_sdpd, cart_buffer_0_sdsd, cart_buffer_0_sdsf, cd_x[0], cd_y[0], cd_z[0], 0, 2);

        erirec::comp_ket_hrr_electron_repulsion_xxpd(contr_buffer_0_sfpd, cart_buffer_0_sfsd, cart_buffer_0_sfsf, cd_x[0], cd_y[0], cd_z[0], 0, 3);

        t4cfunc::ket_transform<1, 2>(ket_spher_buffer_0_sdpd, contr_buffer_0_sdpd, 0, 2);

        t4cfunc::ket_transform<1, 2>(ket_spher_buffer_0_sfpd, contr_buffer_0_sfpd, 0, 3);

        erirec::comp_bra_hrr_electron_repulsion_pdxx(ket_spher_buffer_0_pdpd, ket_spher_buffer_0_sdpd, ket_spher_buffer_0_sfpd, ab_x, ab_y, ab_z, 1, 2);

        t4cfunc::bra_transform<1, 2>(spher_buffer_0_pdpd, ket_spher_buffer_0_pdpd, 1, 2);

        t4cfunc::update_max_values(max_values, spher_buffer_0_pdpd, i - gto_indices[0]); 
    }

    distributor->distribute(max_values, gto_indices);
}

} // erirec namespace

#endif /* ElectronRepulsionDiagRecPDPD_hpp */
