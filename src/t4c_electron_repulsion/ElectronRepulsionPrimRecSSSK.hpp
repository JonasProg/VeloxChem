#ifndef ElectronRepulsionPrimRecSSSK_hpp
#define ElectronRepulsionPrimRecSSSK_hpp

#include <cstddef>

#include "Point.hpp"
#include "SimdArray.hpp"

namespace erirec { // erirec namespace

/// Computes [SS|1/|r-r'||SK]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_eri_0_sssk The index of integral in primitive integrals buffer.
/// @param idx_eri_0_sssh The primitive integrals buffer.
/// @param idx_eri_1_sssh The primitive integrals buffer.
/// @param idx_eri_0_sssi The primitive integrals buffer.
/// @param idx_eri_1_sssi The primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_qd The vector of distances R(QD) = Q - D.
/// @param idx_wq The vector of distances R(WQ) = W - Q.
/// @param a_exp The exponent on center A.
/// @param b_exp The exponent on center B.
auto
comp_prim_electron_repulsion_sssk(CSimdArray<double>& pbuffer,
                                  const size_t idx_eri_0_sssk,
                                  size_t idx_eri_0_sssh,
                                  size_t idx_eri_1_sssh,
                                  size_t idx_eri_0_sssi,
                                  size_t idx_eri_1_sssi,
                                  CSimdArray<double>& factors,
                                  const size_t idx_qd,
                                  const size_t idx_wq,
                                  const double a_exp,
                                  const double b_exp) -> void;
} // erirec namespace

#endif /* ElectronRepulsionPrimRecSSSK_hpp */
