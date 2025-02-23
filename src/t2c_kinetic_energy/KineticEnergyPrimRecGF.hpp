#ifndef KineticEnergyPrimRecGF
#define KineticEnergyPrimRecGF

#include "SimdArray.hpp"

namespace kinrec {  // kinrec namespace

/// @brief Computes primitive [G|T|F]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_kin_gf The index of integral in primitive integrals buffer.
/// @param idx_ovl_df The index of integral in primitive integrals buffer.
/// @param idx_kin_df The index of integral in primitive integrals buffer.
/// @param idx_kin_fd The index of integral in primitive integrals buffer.
/// @param idx_kin_ff The index of integral in primitive integrals buffer.
/// @param idx_ovl_gf The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param a_exp The primitive basis function exponent on center A.
auto comp_prim_kinetic_energy_gf(CSimdArray<double>&       pbuffer,
                                 const size_t              idx_kin_gf,
                                 const size_t              idx_ovl_df,
                                 const size_t              idx_kin_df,
                                 const size_t              idx_kin_fd,
                                 const size_t              idx_kin_ff,
                                 const size_t              idx_ovl_gf,
                                 const CSimdArray<double>& factors,
                                 const size_t              idx_rpa,
                                 const double              a_exp) -> void;
}  // namespace kinrec

#endif /* KineticEnergyPrimRecGF */
