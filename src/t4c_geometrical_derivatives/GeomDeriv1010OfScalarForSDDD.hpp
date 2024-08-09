#ifndef GeomDeriv1010OfScalarForSDDD_hpp
#define GeomDeriv1010OfScalarForSDDD_hpp

#include "SimdArray.hpp"

namespace t4c_geom { // t4c_geom namespace

/// Computes d^(1)/dA^(1)d^(1)/dC^(1)[SD|G|DD]  integrals for arbitrary scalar operator G.
/// - Parameter buffer_1010_sddd: the integral geometrical derivatives buffer.
/// - Parameter buffer_pdpd: the primitive integrals buffer.
/// - Parameter buffer_pdfd: the primitive integrals buffer.
/// - Parameter a_exp: the exponent on center A.
/// - Parameter c_exps: the vector of exponents on center C.
auto
comp_geom1010_sddd_0(CSimdArray<double>& buffer_1010_sddd,
                     const CSimdArray<double>& buffer_pdpd,
                     const CSimdArray<double>& buffer_pdfd,
                     const double a_exp,
                     const double* c_exps) -> void;

} // t4c_geom namespace

#endif /* GeomDeriv1010OfScalarForSDDD_hpp */
