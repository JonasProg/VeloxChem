#ifndef ElectronRepulsionGeom1000ContrRecHPXX_hpp
#define ElectronRepulsionGeom1000ContrRecHPXX_hpp

#include <cstddef>

#include "Point.hpp"
#include "SimdArray.hpp"

namespace erirec { // erirec namespace

/// Computes (HP|1/|r-r'|XX)  integral derivatives for set of data buffers.
/// @param cbuffer The contracted integrals buffer.
/// @param idx_geom_10_hpxx The contracted integrals buffer.
/// @param idx_gpxx The contracted integrals buffer.
/// @param idx_geom_10_gpxx The contracted integrals buffer.
/// @param idx_geom_10_gdxx The contracted integrals buffer.
/// @param r_ab The Cartesian distance R(AB) = A - B.
/// @param c_angmom The angular momentum on center C.
/// @param d_angmom The angular momentum on center D.
auto
comp_bra_geom10_hrr_electron_repulsion_hpxx(CSimdArray<double>& cbuffer,
                                            const size_t idx_geom_10_hpxx,
                                            const size_t idx_gpxx,
                                            const size_t idx_geom_10_gpxx,
                                            const size_t idx_geom_10_gdxx,
                                            const TPoint<double>& r_ab,
                                            const int c_angmom,
                                            const int d_angmom) -> void;
} // erirec namespace

#endif /* ElectronRepulsionGeom1000ContrRecHPXX_hpp */
