#ifndef KineticEnergyPrimRecII
#define KineticEnergyPrimRecII

#include "SimdArray.hpp"

namespace kinrec { // kinrec namespace

/// @brief Computes primitive [I|T|I]  integrals for set of data buffers.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_kin_ii The index of integral in primitive integrals buffer.
/// @param idx_ovl_gi The index of integral in primitive integrals buffer.
/// @param idx_kin_gi The index of integral in primitive integrals buffer.
/// @param idx_kin_hh The index of integral in primitive integrals buffer.
/// @param idx_kin_hi The index of integral in primitive integrals buffer.
/// @param idx_ovl_ii The index of integral in primitive integrals buffer.
/// @param factors The primitive factors buffer.
/// @param idx_rpa The vector of distances R(PA) = P - A.
/// @param a_exp The primitive basis function exponent on center A.
auto
comp_prim_kinetic_energy_ii(CSimdArray<double>& pbuffer, 
                            const size_t idx_kin_ii,
                            const size_t idx_ovl_gi,
                            const size_t idx_kin_gi,
                            const size_t idx_kin_hh,
                            const size_t idx_kin_hi,
                            const size_t idx_ovl_ii,
                            const CSimdArray<double>& factors,
                            const size_t idx_rpa,
                            const double a_exp) -> void;
} // kinrec namespace

#endif /* KineticEnergyPrimRecII */
