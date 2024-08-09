#ifndef GeomDeriv1000OfScalarForSDPD_hpp
#define GeomDeriv1000OfScalarForSDPD_hpp

#include "SimdArray.hpp"

namespace t4c_geom { // t4c_geom namespace

/// Computes d^(1)/dA^(1)[SD|G|PD]  integrals for arbitrary scalar operator G.
/// - Parameter buffer_1000_sdpd: the integral geometrical derivatives buffer.
/// - Parameter buffer_pdpd: the primitive integrals buffer.
/// - Parameter a_exp: the exponent on center A.
auto
comp_geom1000_sdpd_0(CSimdArray<double>& buffer_1000_sdpd,
                     const CSimdArray<double>& buffer_pdpd,
                     const double a_exp) -> void;

} // t4c_geom namespace

#endif /* GeomDeriv1000OfScalarForSDPD_hpp */
