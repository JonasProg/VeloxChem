#ifndef ElectronRepulsionPrimRecSGSI_hpp
#define ElectronRepulsionPrimRecSGSI_hpp

#include <cstddef>

#include "Point.hpp"
#include "SimdArray.hpp"

namespace erirec { // erirec namespace

/// Computes [SG|1/|r-r'||SI]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_eri_0_sgsi The index of integral in primitive integrals buffer.
/// @param idx_eri_0_sdsi The primitive integrals buffer.
/// @param idx_eri_1_sdsi The primitive integrals buffer.
/// @param idx_eri_1_sfsh The primitive integrals buffer.
/// @param idx_eri_0_sfsi The primitive integrals buffer.
/// @param idx_eri_1_sfsi The primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_wp The vector of distances R(WP) = W - P.
/// @param r_pb The Cartesiandistances R(PB) = P - B.
/// @param a_exp The exponent on center A.
/// @param b_exp The exponent on center B.
auto
comp_prim_electron_repulsion_sgsi(CSimdArray<double>& pbuffer,
                                  const size_t idx_eri_0_sgsi,
                                  size_t idx_eri_0_sdsi,
                                  size_t idx_eri_1_sdsi,
                                  size_t idx_eri_1_sfsh,
                                  size_t idx_eri_0_sfsi,
                                  size_t idx_eri_1_sfsi,
                                  CSimdArray<double>& factors,
                                  const size_t idx_wp,
                                  const TPoint<double>& r_pb,
                                  const double a_exp,
                                  const double b_exp) -> void;
} // erirec namespace

#endif /* ElectronRepulsionPrimRecSGSI_hpp */
