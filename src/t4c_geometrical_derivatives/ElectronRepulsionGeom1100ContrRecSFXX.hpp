#ifndef ElectronRepulsionGeom1100ContrRecSFXX_hpp
#define ElectronRepulsionGeom1100ContrRecSFXX_hpp

#include <cstddef>

#include "Point.hpp"
#include "SimdArray.hpp"

namespace erirec { // erirec namespace

/// Computes (SF|1/|r-r'|XX)  integral derivatives for set of data buffers.
/// @param cbuffer The contracted integrals buffer.
/// @param idx_geom_11_sfxx The contracted integrals buffer.
/// @param idx_sfxx The contracted integrals buffer.
/// @param idx_geom_01_sfxx The contracted integrals buffer.
/// @param idx_geom_01_sgxx The contracted integrals buffer.
/// @param r_ab The Cartesian distance R(AB) = A - B.
/// @param c_angmom The angular momentum on center C.
/// @param d_angmom The angular momentum on center D.
auto
comp_bra_geom11_hrr_electron_repulsion_sfxx(CSimdArray<double>& cbuffer,
                                            const size_t idx_geom_11_sfxx,
                                            const size_t idx_sfxx,
                                            const size_t idx_geom_01_sfxx,
                                            const size_t idx_geom_01_sgxx,
                                            const TPoint<double>& r_ab,
                                            const int c_angmom,
                                            const int d_angmom) -> void;
} // erirec namespace

#endif /* ElectronRepulsionGeom1100ContrRecSFXX_hpp */
