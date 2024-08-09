#ifndef GeomDeriv1100OfScalarForDDDD_hpp
#define GeomDeriv1100OfScalarForDDDD_hpp

#include "SimdArray.hpp"

namespace t4c_geom { // t4c_geom namespace

/// Computes d^(1)/dA^(1)d^(1)/dB^(1)[DD|G|DD]  integrals for arbitrary scalar operator G.
/// - Parameter buffer_1100_dddd: the integral geometrical derivatives buffer.
/// - Parameter buffer_ppdd: the primitive integrals buffer.
/// - Parameter buffer_pfdd: the primitive integrals buffer.
/// - Parameter buffer_fpdd: the primitive integrals buffer.
/// - Parameter buffer_ffdd: the primitive integrals buffer.
/// - Parameter a_exp: the exponent on center A.
/// - Parameter b_exp: the exponent on center B.
auto
comp_geom1100_dddd_0(CSimdArray<double>& buffer_1100_dddd,
                     const CSimdArray<double>& buffer_ppdd,
                     const CSimdArray<double>& buffer_pfdd,
                     const CSimdArray<double>& buffer_fpdd,
                     const CSimdArray<double>& buffer_ffdd,
                     const double a_exp,
                     const double b_exp) -> void;

} // t4c_geom namespace

#endif /* GeomDeriv1100OfScalarForDDDD_hpp */
