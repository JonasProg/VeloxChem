#ifndef ElectronRepulsionGeom1010RecDPPD_hpp
#define ElectronRepulsionGeom1010RecDPPD_hpp

#include <array>
#include <cstddef>
#include <utility>

#include "ElectronRepulsionGeom0010ContrRecXXPD.hpp"
#include "ElectronRepulsionGeom1010ContrRecDPXX.hpp"
#include "ElectronRepulsionGeom1010ContrRecPDXX.hpp"
#include "ElectronRepulsionGeom1010ContrRecPPXX.hpp"
#include "ElectronRepulsionGeom1010ContrRecSDXX.hpp"
#include "ElectronRepulsionGeom1010ContrRecSFXX.hpp"
#include "ElectronRepulsionGeom1010ContrRecSPXX.hpp"
#include "ElectronRepulsionContrRecPPXX.hpp"
#include "ElectronRepulsionPrimRecSDSD.hpp"
#include "ElectronRepulsionPrimRecSDSF.hpp"
#include "ElectronRepulsionPrimRecSDSG.hpp"
#include "ElectronRepulsionPrimRecSDSP.hpp"
#include "ElectronRepulsionPrimRecSDSS.hpp"
#include "ElectronRepulsionPrimRecSFSD.hpp"
#include "ElectronRepulsionPrimRecSFSF.hpp"
#include "ElectronRepulsionPrimRecSFSG.hpp"
#include "ElectronRepulsionPrimRecSFSP.hpp"
#include "ElectronRepulsionPrimRecSGSD.hpp"
#include "ElectronRepulsionPrimRecSGSF.hpp"
#include "ElectronRepulsionPrimRecSGSG.hpp"
#include "ElectronRepulsionPrimRecSPSD.hpp"
#include "ElectronRepulsionPrimRecSPSF.hpp"
#include "ElectronRepulsionPrimRecSPSG.hpp"
#include "ElectronRepulsionPrimRecSPSP.hpp"
#include "ElectronRepulsionPrimRecSPSS.hpp"
#include "ElectronRepulsionPrimRecSSSD.hpp"
#include "ElectronRepulsionPrimRecSSSF.hpp"
#include "ElectronRepulsionPrimRecSSSG.hpp"
#include "ElectronRepulsionPrimRecSSSP.hpp"
#include "ElectronRepulsionPrimRecSSSS.hpp"
#include "SimdArray.hpp"
#include "BoysFunc.hpp"
#include "T4CUtils.hpp"
#include "T2CUtils.hpp"
#include "BatchFunc.hpp"
#include "GtoPairBlock.hpp"

namespace erirec { // erirec namespace

/// @brief Computes d^(1)/dA^(1)d^(1)/dC^(1)(DP|1/|r-r'||PD)  integral derivatives.
/// @param distributor The pointer to Fock matrix/matrices distributor.
/// @param bra_gto_pair_block The GTOs pair block on bra side.
/// @param ket_gto_pair_block The GTOs pair block on ket side.
/// @param bra_indices The range [bra_first, bra_last) of basis function pairs on bra side.
/// @param ket_indices The range [ket_first, ket_last) of basis function pairs on ket side.
template <class T>
inline auto
comp_electron_repulsion_geom1010_dppd(T& distributor,
                                      const CGtoPairBlock& bra_gto_pair_block,
                                      const CGtoPairBlock& ket_gto_pair_block,
                                      const std::pair<size_t, size_t>& bra_indices,
                                      const std::pair<size_t, size_t>& ket_indices) -> void
{
    // intialize GTOs pair data on bra side

    const auto a_coords = bra_gto_pair_block.bra_coordinates();

    const auto b_coords = bra_gto_pair_block.ket_coordinates();

    const auto a_vec_exps = bra_gto_pair_block.bra_exponents();

    const auto b_vec_exps = bra_gto_pair_block.ket_exponents();

    const auto ab_vec_norms = bra_gto_pair_block.normalization_factors();

    const auto ab_vec_ovls = bra_gto_pair_block.overlap_factors();

    const auto a_indices = bra_gto_pair_block.bra_orbital_indices();

    const auto b_indices = bra_gto_pair_block.ket_orbital_indices();

    const auto bra_ncgtos = bra_gto_pair_block.number_of_contracted_pairs();

    const auto bra_npgtos = bra_gto_pair_block.number_of_primitive_pairs();

    // intialize GTOs data on ket side

    const auto c_coords = ket_gto_pair_block.bra_coordinates();

    const auto d_coords = ket_gto_pair_block.ket_coordinates();

    const auto c_vec_exps = ket_gto_pair_block.bra_exponents();

    const auto d_vec_exps = ket_gto_pair_block.ket_exponents();

    const auto cd_vec_norms = ket_gto_pair_block.normalization_factors();

    const auto cd_vec_ovls = ket_gto_pair_block.overlap_factors();

    const auto c_indices = ket_gto_pair_block.bra_orbital_indices();

    const auto d_indices = ket_gto_pair_block.ket_orbital_indices();

    const auto ket_npgtos = ket_gto_pair_block.number_of_primitive_pairs();

    // allocate aligned 2D arrays for ket side

    CSimdArray<double> pfactors(29, ket_npgtos);

    CSimdArray<double> cfactors(9, 1);

    // allocate aligned primitive integrals

    CSimdArray<double> pbuffer(2330, ket_npgtos);

    // allocate aligned Cartesian integrals

    CSimdArray<double> cbuffer(1591, 1);

    // allocate aligned contracted integrals

    CSimdArray<double> ckbuffer(4386, 1);

    // allocate aligned half transformed integrals

    CSimdArray<double> skbuffer(10980, 1);

    // allocate aligned spherical integrals

    CSimdArray<double> sbuffer(2025, 1);

    // setup Boys fuction data

    const CBoysFunc<8> bf_table;

    CSimdArray<double> bf_data(10, ket_npgtos);

    // set up ket partitioning

    const auto ket_dim = ket_indices.second - ket_indices.first;

    const auto ket_blocks = batch::number_of_batches(ket_dim, simd::width<double>());

    for (size_t i = 0; i < ket_blocks; i++)
    {
        auto ket_range = batch::batch_range(i, ket_dim, simd::width<double>(), ket_indices.first);

        pfactors.load(c_vec_exps, ket_range, 0, ket_npgtos);

        pfactors.load(d_vec_exps, ket_range, 1, ket_npgtos);

        pfactors.load(cd_vec_ovls, ket_range, 2, ket_npgtos);

        pfactors.load(cd_vec_norms, ket_range, 3, ket_npgtos);

        pfactors.replicate_points(c_coords, ket_range, 4, ket_npgtos);

        pfactors.replicate_points(d_coords, ket_range, 7, ket_npgtos);

        cfactors.replicate_points(c_coords, ket_range, 0, 1);

        cfactors.replicate_points(d_coords, ket_range, 3, 1);

        t4cfunc::comp_distances_cd(cfactors, 6, 0, 3);

        // set up active SIMD width

        const auto ket_width = ket_range.second - ket_range.first;

        pbuffer.set_active_width(ket_width);

        cbuffer.set_active_width(ket_width);

        ckbuffer.set_active_width(ket_width);

        skbuffer.set_active_width(ket_width);

        sbuffer.set_active_width(ket_width);

        bf_data.set_active_width(ket_width);

        // loop over basis function pairs on bra side

        for (auto j = bra_indices.first; j < bra_indices.second; j++)
        {
            // zero integral buffers

            cbuffer.zero();

            ckbuffer.zero();

            skbuffer.zero();

            sbuffer.zero();

            // set up coordinates on bra side

            const auto r_a = a_coords[j];

            const auto r_b = b_coords[j];

            const auto a_xyz = r_a.coordinates();

            const auto b_xyz = r_b.coordinates();

            const auto r_ab = TPoint<double>({a_xyz[0] - b_xyz[0], a_xyz[1] - b_xyz[1], a_xyz[2] - b_xyz[2]});

            for (int k = 0; k < bra_npgtos; k++)
            {
                const auto a_exp = a_vec_exps[k * bra_ncgtos + j];

                const auto b_exp = b_vec_exps[k * bra_ncgtos + j];

                const auto ab_norm = ab_vec_norms[k * bra_ncgtos + j];

                const auto ab_ovl = ab_vec_ovls[k * bra_ncgtos + j];

                const auto p_x = (a_xyz[0] * a_exp + b_xyz[0] * b_exp) / (a_exp + b_exp);

                const auto p_y = (a_xyz[1] * a_exp + b_xyz[1] * b_exp) / (a_exp + b_exp);

                const auto p_z = (a_xyz[2] * a_exp + b_xyz[2] * b_exp) / (a_exp + b_exp);

                const auto r_p = TPoint<double>({p_x, p_y, p_z});

                const auto pb_x = p_x - b_xyz[0];

                const auto pb_y = p_y - b_xyz[1];

                const auto pb_z = p_z - b_xyz[2];

                const auto r_pb = TPoint<double>({pb_x, pb_y, pb_z});

                t4cfunc::comp_coordinates_q(pfactors, 10, 4, 7);

                t4cfunc::comp_distances_pq(pfactors, 13, 10, r_p);

                t4cfunc::comp_coordinates_w(pfactors, 17, 10, r_p, a_exp, b_exp);

                t4cfunc::comp_distances_qd(pfactors, 20, 10, 7);

                t4cfunc::comp_distances_wq(pfactors, 23, 17, 10);

                t4cfunc::comp_distances_wp(pfactors, 26, 17, r_p);

                t4cfunc::comp_boys_args(bf_data, 9, pfactors, 13, a_exp, b_exp);

                bf_table.compute(bf_data, 0, 9);

                t4cfunc::comp_ovl_factors(pfactors, 16, 2, 3, ab_ovl, ab_norm, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 0, pfactors, 16, bf_data, 0);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 1, pfactors, 16, bf_data, 1);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 2, pfactors, 16, bf_data, 2);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 3, pfactors, 16, bf_data, 3);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 4, pfactors, 16, bf_data, 4);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 5, pfactors, 16, bf_data, 5);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 6, pfactors, 16, bf_data, 6);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 7, pfactors, 16, bf_data, 7);

                erirec::comp_prim_electron_repulsion_ssss(pbuffer, 8, pfactors, 16, bf_data, 8);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 9, 0, 1, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 12, 1, 2, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 15, 2, 3, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 18, 3, 4, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 21, 4, 5, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 24, 5, 6, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 27, 6, 7, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssp(pbuffer, 30, 7, 8, pfactors, 20, 23);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 33, 0, 1, 9, 12, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 39, 1, 2, 12, 15, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 45, 2, 3, 15, 18, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 51, 3, 4, 18, 21, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 57, 4, 5, 21, 24, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 63, 5, 6, 24, 27, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssd(pbuffer, 69, 6, 7, 27, 30, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 75, 9, 12, 33, 39, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 85, 12, 15, 39, 45, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 95, 15, 18, 45, 51, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 105, 18, 21, 51, 57, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 115, 21, 24, 57, 63, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssf(pbuffer, 125, 24, 27, 63, 69, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssg(pbuffer, 135, 33, 39, 75, 85, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssg(pbuffer, 150, 39, 45, 85, 95, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssg(pbuffer, 165, 45, 51, 95, 105, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssg(pbuffer, 180, 51, 57, 105, 115, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sssg(pbuffer, 195, 57, 63, 115, 125, pfactors, 20, 23, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spss(pbuffer, 210, 2, 3, pfactors, 26, r_pb);

                erirec::comp_prim_electron_repulsion_spss(pbuffer, 213, 3, 4, pfactors, 26, r_pb);

                erirec::comp_prim_electron_repulsion_spsp(pbuffer, 216, 2, 12, 15, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsp(pbuffer, 225, 3, 15, 18, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsp(pbuffer, 234, 4, 18, 21, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsd(pbuffer, 243, 12, 33, 39, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsd(pbuffer, 261, 15, 39, 45, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsd(pbuffer, 279, 18, 45, 51, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsd(pbuffer, 297, 21, 51, 57, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsf(pbuffer, 315, 39, 75, 85, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsf(pbuffer, 345, 45, 85, 95, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsf(pbuffer, 375, 51, 95, 105, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsf(pbuffer, 405, 57, 105, 115, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsg(pbuffer, 435, 85, 135, 150, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsg(pbuffer, 480, 95, 150, 165, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsg(pbuffer, 525, 105, 165, 180, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_spsg(pbuffer, 570, 115, 180, 195, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdss(pbuffer, 615, 2, 3, 210, 213, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsp(pbuffer, 621, 12, 15, 210, 216, 225, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsp(pbuffer, 639, 15, 18, 213, 225, 234, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsd(pbuffer, 657, 33, 39, 216, 243, 261, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsd(pbuffer, 693, 39, 45, 225, 261, 279, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsd(pbuffer, 729, 45, 51, 234, 279, 297, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsf(pbuffer, 765, 75, 85, 261, 315, 345, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsf(pbuffer, 825, 85, 95, 279, 345, 375, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsf(pbuffer, 885, 95, 105, 297, 375, 405, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsg(pbuffer, 945, 135, 150, 345, 435, 480, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsg(pbuffer, 1035, 150, 165, 375, 480, 525, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sdsg(pbuffer, 1125, 165, 180, 405, 525, 570, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsp(pbuffer, 1215, 216, 225, 615, 621, 639, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsd(pbuffer, 1245, 243, 261, 621, 657, 693, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsd(pbuffer, 1305, 261, 279, 639, 693, 729, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsf(pbuffer, 1365, 315, 345, 693, 765, 825, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsf(pbuffer, 1465, 345, 375, 729, 825, 885, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsg(pbuffer, 1565, 435, 480, 825, 945, 1035, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sfsg(pbuffer, 1715, 480, 525, 885, 1035, 1125, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sgsd(pbuffer, 1865, 657, 693, 1215, 1245, 1305, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sgsf(pbuffer, 1955, 765, 825, 1305, 1365, 1465, pfactors, 26, r_pb, a_exp, b_exp);

                erirec::comp_prim_electron_repulsion_sgsg(pbuffer, 2105, 945, 1035, 1465, 1565, 1715, pfactors, 26, r_pb, a_exp, b_exp);

                t2cfunc::reduce(cbuffer, 0, pbuffer, 243, 18, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 18, pbuffer, 657, 36, ket_width, ket_npgtos);

                pbuffer.scale(2.0 * a_exp, {243, 261});

                pbuffer.scale(2.0 * a_exp, {657, 693});

                pbuffer.scale(2.0 * a_exp, {1245, 1305});

                pbuffer.scale(2.0 * a_exp, {1865, 1955});

                t2cfunc::reduce(cbuffer, 333, pbuffer, 243, 18, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 351, pbuffer, 657, 36, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 387, pbuffer, 1245, 60, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 447, pbuffer, 1865, 90, ket_width, ket_npgtos);

                pbuffer.scale(pfactors, 0, 1.0 / a_exp, {243, 261});

                pbuffer.scale(pfactors, 0, 2.0, {315, 345});

                pbuffer.scale(pfactors, 0, 2.0, {435, 480});

                pbuffer.scale(pfactors, 0, 1.0 / a_exp, {657, 693});

                pbuffer.scale(pfactors, 0, 2.0, {765, 825});

                pbuffer.scale(pfactors, 0, 2.0, {945, 1035});

                t2cfunc::reduce(cbuffer, 54, pbuffer, 243, 18, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 72, pbuffer, 315, 30, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 102, pbuffer, 435, 45, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 147, pbuffer, 657, 36, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 183, pbuffer, 765, 60, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 243, pbuffer, 945, 90, ket_width, ket_npgtos);

                pbuffer.scale(2.0 * a_exp, {243, 261});

                pbuffer.scale(2.0 * a_exp, {315, 345});

                pbuffer.scale(2.0 * a_exp, {435, 480});

                pbuffer.scale(2.0 * a_exp, {657, 693});

                pbuffer.scale(2.0 * a_exp, {765, 825});

                pbuffer.scale(2.0 * a_exp, {945, 1035});

                pbuffer.scale(pfactors, 0, 2.0, {1245, 1305});

                pbuffer.scale(pfactors, 0, 4.0 * a_exp, {1365, 1465});

                pbuffer.scale(pfactors, 0, 4.0 * a_exp, {1565, 1715});

                pbuffer.scale(pfactors, 0, 2.0, {1865, 1955});

                pbuffer.scale(pfactors, 0, 4.0 * a_exp, {1955, 2105});

                pbuffer.scale(pfactors, 0, 4.0 * a_exp, {2105, 2330});

                t2cfunc::reduce(cbuffer, 537, pbuffer, 243, 18, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 555, pbuffer, 315, 30, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 585, pbuffer, 435, 45, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 630, pbuffer, 657, 36, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 666, pbuffer, 765, 60, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 726, pbuffer, 945, 90, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 816, pbuffer, 1245, 60, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 876, pbuffer, 1365, 100, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 976, pbuffer, 1565, 150, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 1126, pbuffer, 1865, 90, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 1216, pbuffer, 1955, 150, ket_width, ket_npgtos);

                t2cfunc::reduce(cbuffer, 1366, pbuffer, 2105, 225, ket_width, ket_npgtos);

            }

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 0, cbuffer, 54, 72, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 54, cbuffer, 72, 102, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 144, cbuffer, 0, 0, 54, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 306, cbuffer, 147, 183, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 414, cbuffer, 183, 243, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 594, cbuffer, 18, 306, 414, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 918, cbuffer, 537, 555, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 972, cbuffer, 555, 585, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 1062, cbuffer, 333, 918, 972, cfactors, 6, 0, 1);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 1224, cbuffer, 630, 666, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 1332, cbuffer, 666, 726, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 1512, cbuffer, 351, 1224, 1332, cfactors, 6, 0, 2);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 1836, cbuffer, 816, 876, cfactors, 6, 0, 3);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 2016, cbuffer, 876, 976, cfactors, 6, 0, 3);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 2316, cbuffer, 387, 1836, 2016, cfactors, 6, 0, 3);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsd(ckbuffer, 2856, cbuffer, 1126, 1216, cfactors, 6, 0, 4);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxsf(ckbuffer, 3126, cbuffer, 1216, 1366, cfactors, 6, 0, 4);

            erirec::comp_ket_geom10_hrr_electron_repulsion_xxpd(ckbuffer, 3576, cbuffer, 447, 2856, 3126, cfactors, 6, 0, 4);

            t4cfunc::ket_transform<1, 2>(skbuffer, 0, ckbuffer, 144, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 45, ckbuffer, 198, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 90, ckbuffer, 252, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 540, ckbuffer, 594, 0, 2);

            t4cfunc::ket_transform<1, 2>(skbuffer, 630, ckbuffer, 702, 0, 2);

            t4cfunc::ket_transform<1, 2>(skbuffer, 720, ckbuffer, 810, 0, 2);

            //t4cfunc::ket_transform<1, 2>(skbuffer, 2970, ckbuffer, 0, 1, 1);

            //t4cfunc::ket_transform<1, 2>(skbuffer, 3105, ckbuffer, 162, 1, 1);

            //t4cfunc::ket_transform<1, 2>(skbuffer, 3240, ckbuffer, 324, 1, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9450, ckbuffer, 1062, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9495, ckbuffer, 1116, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9540, ckbuffer, 1170, 0, 1);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9585, ckbuffer, 1512, 0, 2);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9675, ckbuffer, 1620, 0, 2);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9765, ckbuffer, 1728, 0, 2);

            t4cfunc::ket_transform<1, 2>(skbuffer, 9855, ckbuffer, 2316, 0, 3);

            t4cfunc::ket_transform<1, 2>(skbuffer, 10005, ckbuffer, 2496, 0, 3);

            t4cfunc::ket_transform<1, 2>(skbuffer, 10155, ckbuffer, 2676, 0, 3);

            t4cfunc::ket_transform<1, 2>(skbuffer, 10305, ckbuffer, 3576, 0, 4);

            t4cfunc::ket_transform<1, 2>(skbuffer, 10530, ckbuffer, 3846, 0, 4);

            t4cfunc::ket_transform<1, 2>(skbuffer, 10755, ckbuffer, 4116, 0, 4);
            
            erirec::comp_bra_hrr_electron_repulsion_ppxx(skbuffer, 2970, 0, 540, r_ab, 1, 2);
            
            erirec::comp_bra_hrr_electron_repulsion_ppxx(skbuffer, 3105, 45, 630, r_ab, 1, 2);
            
            erirec::comp_bra_hrr_electron_repulsion_ppxx(skbuffer, 3240, 90, 720, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_spxx(skbuffer, 135, 9450, 9585, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_sdxx(skbuffer, 810, 9585, 9855, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_sfxx(skbuffer, 1620, 9855, 10305, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_ppxx(skbuffer, 3375, 0, 135, 810, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_pdxx(skbuffer, 4590, 540, 810, 1620, r_ab, 1, 2);

            erirec::comp_bra_geom1010_hrr_electron_repulsion_dpxx(skbuffer, 7020, 2970, 3375, 4590, r_ab, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 0, skbuffer, 7020, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 225, skbuffer, 7290, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 450, skbuffer, 7560, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 675, skbuffer, 7830, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 900, skbuffer, 8100, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 1125, skbuffer, 8370, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 1350, skbuffer, 8640, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 1575, skbuffer, 8910, 1, 2);

            t4cfunc::bra_transform<2, 1>(sbuffer, 1800, skbuffer, 9180, 1, 2);

            distributor.distribute(sbuffer, 0, a_indices, b_indices, c_indices, d_indices, 2, 1, 1, 2, j, ket_range);
        }
    }

}

} // erirec namespace

#endif /* ElectronRepulsionGeom1010RecDPPD_hpp */
