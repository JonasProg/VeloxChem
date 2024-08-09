#ifndef GeometricalDerivatives1X1ForDG_hpp
#define GeometricalDerivatives1X1ForDG_hpp

#include "SimdArray.hpp"

namespace t2cgeom { // t2cgeom namespace

/// @brief Computes [d^(1)/dA^(1)D|R|d^(1)/dB^(1)G]  integrals for arbitrary operator R.
/// @param pbuffer The primitive integrals buffer.
/// @param idx_op_geom_101_dg The index of integral in primitive integrals buffer.
/// @param idx_op_geom_001_pg The index of integral in primitive integrals buffer.
/// @param idx_op_geom_001_fg The index of integral in primitive integrals buffer.
/// @param op_comps The number of operator components.
/// @param factors The primitive factors buffer.
/// @param a_exp The exponent on center A.
auto
comp_prim_op_geom_11_dg(CSimdArray<double>& pbuffer,
                        const size_t idx_op_geom_101_dg,
                        const size_t idx_op_pf,
                        const size_t idx_op_ph,
                        const size_t idx_op_ff,
                        const size_t idx_op_fh,
                        const size_t op_comps,
                        const CSimdArray<double>& factors,
                        const double a_exp) -> void;

} // t2cgeom namespace

#endif /* GeometricalDerivatives1X1ForDG_hpp */
