#ifndef NuclearPotentialPrimRecGF
#define NuclearPotentialPrimRecGF

#include "SimdArray.hpp"

namespace npotrec {  // npotrec namespace

/// @brief Computes primitive [G|A|F]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_npot_0_gf The index of integral in primitive integrals buffer.
/// @param idx_npot_0_df The index of integral in primitive integrals buffer.
/// @param idx_npot_1_df The index of integral in primitive integrals buffer.
/// @param idx_npot_0_fd The index of integral in primitive integrals buffer.
/// @param idx_npot_1_fd The index of integral in primitive integrals buffer.
/// @param idx_npot_0_ff The index of integral in primitive integrals buffer.
/// @param idx_npot_1_ff The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param idx_rpc The vector of distances R(PC) = P - C.
/// @param a_exp The primitive basis function exponent on center A.
auto comp_prim_nuclear_potential_gf(CSimdArray<double>&       pbuffer,
                                    const size_t              idx_npot_0_gf,
                                    const size_t              idx_npot_0_df,
                                    const size_t              idx_npot_1_df,
                                    const size_t              idx_npot_0_fd,
                                    const size_t              idx_npot_1_fd,
                                    const size_t              idx_npot_0_ff,
                                    const size_t              idx_npot_1_ff,
                                    const CSimdArray<double>& factors,
                                    const size_t              idx_rpa,
                                    const size_t              idx_rpc,
                                    const double              a_exp) -> void;
}  // namespace npotrec

#endif /* NuclearPotentialPrimRecGF */
