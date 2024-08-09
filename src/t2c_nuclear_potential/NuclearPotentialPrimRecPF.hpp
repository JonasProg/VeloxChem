#ifndef NuclearPotentialPrimRecPF
#define NuclearPotentialPrimRecPF

#include "SimdArray.hpp"

namespace npotrec {  // npotrec namespace

/// @brief Computes primitive [P|A|F]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_npot_0_pf The index of integral in primitive integrals buffer.
/// @param idx_npot_0_sd The index of integral in primitive integrals buffer.
/// @param idx_npot_1_sd The index of integral in primitive integrals buffer.
/// @param idx_npot_0_sf The index of integral in primitive integrals buffer.
/// @param idx_npot_1_sf The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param idx_rpc The vector of distances R(PC) = P - C.
/// @param a_exp The primitive basis function exponent on center A.
auto comp_prim_nuclear_potential_pf(CSimdArray<double>&       pbuffer,
                                    const size_t              idx_npot_0_pf,
                                    const size_t              idx_npot_0_sd,
                                    const size_t              idx_npot_1_sd,
                                    const size_t              idx_npot_0_sf,
                                    const size_t              idx_npot_1_sf,
                                    const CSimdArray<double>& factors,
                                    const size_t              idx_rpa,
                                    const size_t              idx_rpc,
                                    const double              a_exp) -> void;
}  // namespace npotrec

#endif /* NuclearPotentialPrimRecPF */
