#ifndef GeomDeriv1000OfScalarForSPPD_hpp
#define GeomDeriv1000OfScalarForSPPD_hpp

#include "SimdArray.hpp"

namespace t4c_geom { // t4c_geom namespace

/// Computes d^(1)/dA^(1)[SP|G|PD]  integrals for arbitrary scalar operator G.
/// - Parameter buffer_1000_sppd: the integral geometrical derivatives buffer.
/// - Parameter buffer_pppd: the primitive integrals buffer.
/// - Parameter a_exp: the exponent on center A.
auto
comp_geom1000_sppd_0(CSimdArray<double>& buffer_1000_sppd,
                     const CSimdArray<double>& buffer_pppd,
                     const double a_exp) -> void;

} // t4c_geom namespace

#endif /* GeomDeriv1000OfScalarForSPPD_hpp */
