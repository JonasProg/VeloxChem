#ifndef EriGeom4000Func_hpp
#define EriGeom4000Func_hpp

#include <array>

#include "GtoPairBlock.hpp"

/*

#include "ElectronRepulsionG4000DDDD.hpp"
#include "ElectronRepulsionG4000DDPD.hpp"
#include "ElectronRepulsionG4000DDPP.hpp"
#include "ElectronRepulsionG4000DDSD.hpp"
#include "ElectronRepulsionG4000DDSP.hpp"
#include "ElectronRepulsionG4000DDSS.hpp"
#include "ElectronRepulsionG4000PDDD.hpp"
#include "ElectronRepulsionG4000PDPD.hpp"
#include "ElectronRepulsionG4000PDPP.hpp"
#include "ElectronRepulsionG4000PDSD.hpp"
#include "ElectronRepulsionG4000PDSP.hpp"
#include "ElectronRepulsionG4000PDSS.hpp"
#include "ElectronRepulsionG4000PPDD.hpp"
#include "ElectronRepulsionG4000PPPD.hpp"
#include "ElectronRepulsionG4000PPPP.hpp"
#include "ElectronRepulsionG4000PPSD.hpp"
#include "ElectronRepulsionG4000PPSP.hpp"
#include "ElectronRepulsionG4000PPSS.hpp"
#include "ElectronRepulsionG4000SDDD.hpp"
#include "ElectronRepulsionG4000SDPD.hpp"
#include "ElectronRepulsionG4000SDPP.hpp"
#include "ElectronRepulsionG4000SDSD.hpp"
#include "ElectronRepulsionG4000SDSP.hpp"
#include "ElectronRepulsionG4000SDSS.hpp"
#include "ElectronRepulsionG4000SPDD.hpp"
#include "ElectronRepulsionG4000SPPD.hpp"
#include "ElectronRepulsionG4000SPPP.hpp"
#include "ElectronRepulsionG4000SPSD.hpp"
#include "ElectronRepulsionG4000SPSP.hpp"
#include "ElectronRepulsionG4000SPSS.hpp"
#include "ElectronRepulsionG4000SSDD.hpp"
#include "ElectronRepulsionG4000SSPD.hpp"
#include "ElectronRepulsionG4000SSPP.hpp"
#include "ElectronRepulsionG4000SSSD.hpp"
#include "ElectronRepulsionG4000SSSP.hpp"
*/

namespace eri_g4000 {  // eri_g4000 namespace

template <class T>
inline auto
compute(T*                        distributor,
        const CGtoPairBlock&      bra_gto_pair_block,
        const CGtoPairBlock&      ket_gto_pair_block,
        const std::array<int, 2>& bra_range,
        const std::array<int, 2>& ket_range) -> void
{
    const auto bra_angmoms = bra_gto_pair_block.angular_momentums();

    const auto ket_angmoms = ket_gto_pair_block.angular_momentums();

    /*

        // (SS|SS)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_ssss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SS|SP)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_sssp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SS|SD)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_sssd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SS|PP)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_sspp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SS|PD)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_sspd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SS|DD)
        if ((bra_angmoms == std::array<int, 2>({0, 0})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_ssdd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SP|SS)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_spss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SP|SP)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_spsp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SP|SD)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_spsd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SP|PP)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_sppp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SP|PD)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_sppd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SP|DD)
        if ((bra_angmoms == std::array<int, 2>({0, 1})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_spdd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SD|SS)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_sdss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SD|SP)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_sdsp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SD|SD)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_sdsd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SD|PP)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_sdpp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (SD|PD)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_sdpd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (SD|DD)
        if ((bra_angmoms == std::array<int, 2>({0, 2})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_sddd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PP|SS)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_ppss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PP|SP)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_ppsp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PP|SD)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_ppsd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PP|PP)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_pppp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PP|PD)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_pppd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PP|DD)
        if ((bra_angmoms == std::array<int, 2>({1, 1})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_ppdd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PD|SS)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_pdss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PD|SP)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_pdsp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PD|SD)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_pdsd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PD|PP)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_pdpp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (PD|PD)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_pdpd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (PD|DD)
        if ((bra_angmoms == std::array<int, 2>({1, 2})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_pddd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (DD|SS)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 0})))
        {
            eri_g4000::comp_electron_repulsion_ddss(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (DD|SP)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 1})))
        {
            eri_g4000::comp_electron_repulsion_ddsp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (DD|SD)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({0, 2})))
        {
            eri_g4000::comp_electron_repulsion_ddsd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (DD|PP)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 1})))
        {
            eri_g4000::comp_electron_repulsion_ddpp(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }


        // (DD|PD)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({1, 2})))
        {
            eri_g4000::comp_electron_repulsion_ddpd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }

        // (DD|DD)
        if ((bra_angmoms == std::array<int, 2>({2, 2})) &&
            (ket_angmoms == std::array<int, 2>({2, 2})))
        {
            eri_g4000::comp_electron_repulsion_dddd(distributor, bra_gto_pair_block, ket_gto_pair_block, bra_range, ket_range);

            return;
        }
    */

    /// Add other angular momenta or autogen
}

}  // namespace eri_g4000

#endif /* EriGeom4000Func_hpp */