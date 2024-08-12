#ifndef NuclearPotentialPrimRecFH
#define NuclearPotentialPrimRecFH

#include "SimdArray.hpp"

namespace npotrec { // npotrec namespace

/// @brief Computes primitive [F|A|H]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_npot_0_fh The index of integral in primitive integrals buffer.
/// @param idx_npot_0_ph The index of integral in primitive integrals buffer.
/// @param idx_npot_1_ph The index of integral in primitive integrals buffer.
/// @param idx_npot_0_dg The index of integral in primitive integrals buffer.
/// @param idx_npot_1_dg The index of integral in primitive integrals buffer.
/// @param idx_npot_0_dh The index of integral in primitive integrals buffer.
/// @param idx_npot_1_dh The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param idx_rpc The vector of distances R(PC) = P - C.
/// @param a_exp The primitive basis function exponent on center A.
auto
comp_prim_nuclear_potential_fh(CSimdArray<double>& pbuffer, 
                               const size_t idx_npot_0_fh,
                               const size_t idx_npot_0_ph,
                               const size_t idx_npot_1_ph,
                               const size_t idx_npot_0_dg,
                               const size_t idx_npot_1_dg,
                               const size_t idx_npot_0_dh,
                               const size_t idx_npot_1_dh,
                               const CSimdArray<double>& factors,
                               const size_t idx_rpa,
                               const size_t idx_rpc,
                               const double a_exp) -> void;
} // npotrec namespace

#endif /* NuclearPotentialPrimRecFH */
