#ifndef KineticEnergyPrimRecPG
#define KineticEnergyPrimRecPG

#include "SimdArray.hpp"

namespace kinrec {  // kinrec namespace

/// @brief Computes primitive [P|T|G]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_kin_pg The index of integral in primitive integrals buffer.
/// @param idx_kin_sf The index of integral in primitive integrals buffer.
/// @param idx_kin_sg The index of integral in primitive integrals buffer.
/// @param idx_ovl_pg The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param a_exp The primitive basis function exponent on center A.
auto comp_prim_kinetic_energy_pg(CSimdArray<double>&       pbuffer,
                                 const size_t              idx_kin_pg,
                                 const size_t              idx_kin_sf,
                                 const size_t              idx_kin_sg,
                                 const size_t              idx_ovl_pg,
                                 const CSimdArray<double>& factors,
                                 const size_t              idx_rpa,
                                 const double              a_exp) -> void;
}  // namespace kinrec

#endif /* KineticEnergyPrimRecPG */
