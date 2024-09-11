#ifndef DiagonalElectronRepulsionFunc_hpp
#define DiagonalElectronRepulsionFunc_hpp

#include <cstddef>
#include <array>
#include <utility>

#include "GtoPairBlock.hpp"

#include "ElectronRepulsionDiagRecSSSS.hpp"
#include "ElectronRepulsionDiagRecSPSP.hpp"
#include "ElectronRepulsionDiagRecSDSD.hpp"
#include "ElectronRepulsionDiagRecPPPP.hpp"
#include "ElectronRepulsionDiagRecSFSF.hpp"
#include "ElectronRepulsionDiagRecPDPD.hpp"
#include "ElectronRepulsionDiagRecSGSG.hpp"
#include "ElectronRepulsionDiagRecPFPF.hpp"
#include "ElectronRepulsionDiagRecDDDD.hpp"
#include "ElectronRepulsionDiagRecPGPG.hpp"
#include "ElectronRepulsionDiagRecDFDF.hpp"
#include "ElectronRepulsionDiagRecFFFF.hpp"
#include "ElectronRepulsionDiagRecDGDG.hpp"
#include "ElectronRepulsionDiagRecFGFG.hpp"
#include "ElectronRepulsionDiagRecGGGG.hpp"

namespace erifunc {  // erifunc namespace

/// @brief Computes vector of largest of Cartesian integral components of requested four center integral.
/// @param distributor  The pointer to distributor of Fock matrix or Fock matrices.
/// @param gto_pair_block  The GTOs pair block to compute Fock matrix or Fock matrices.
/// @param range  The range [first, last) for bra and ket computations.
template<class T>
inline auto
diag_compute(      T&                  distributor,
             const CGtoPairBlock&      gto_pair_block,
             const std::pair<size_t, size_t>& range) -> void
{
    const auto angmoms = gto_pair_block.angular_momentums();
    
    // angular order - 0

    if (angmoms == std::pair<size_t, size_t>({0, 0}))
    {
        erirec::comp_diag_electron_repulsion_ssss(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 1
    
    if (angmoms == std::pair<size_t, size_t>({0, 1}))
    {
        erirec::comp_diag_electron_repulsion_spsp(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 2
    
    if (angmoms == std::pair<size_t, size_t>({0, 2}))
    {
        erirec::comp_diag_electron_repulsion_sdsd(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({1, 1}))
    {
        erirec::comp_diag_electron_repulsion_pppp(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 3
    
    if (angmoms == std::pair<size_t, size_t>({0, 3}))
    {
        erirec::comp_diag_electron_repulsion_sfsf(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({1, 2}))
    {
        erirec::comp_diag_electron_repulsion_pdpd(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 4
    
    if (angmoms == std::pair<size_t, size_t>({0, 4}))
    {
        erirec::comp_diag_electron_repulsion_sgsg(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({1, 3}))
    {
        erirec::comp_diag_electron_repulsion_pfpf(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({2, 2}))
    {
        erirec::comp_diag_electron_repulsion_dddd(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 5
    
    if (angmoms == std::pair<size_t, size_t>({1, 4}))
    {
        erirec::comp_diag_electron_repulsion_pgpg(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({2, 3}))
    {
        erirec::comp_diag_electron_repulsion_dfdf(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 6
    
    if (angmoms == std::pair<size_t, size_t>({2, 4}))
    {
        erirec::comp_diag_electron_repulsion_dgdg(distributor, gto_pair_block, range);
        
        return;
    }
    
    if (angmoms == std::pair<size_t, size_t>({3, 3}))
    {
        erirec::comp_diag_electron_repulsion_ffff(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 7
    
    if (angmoms == std::pair<size_t, size_t>({3, 4}))
    {
        erirec::comp_diag_electron_repulsion_fgfg(distributor, gto_pair_block, range);
        
        return;
    }
    
    // angular order - 8
    
    if (angmoms == std::pair<size_t, size_t>({4, 4}))
    {
        erirec::comp_diag_electron_repulsion_gggg(distributor, gto_pair_block, range);
        
        return;
    }
}

}  // namespace erifunc

#endif /* DiagonalElectronRepulsionFunc_hpp */
