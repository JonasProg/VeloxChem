//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef PartitionFunc_hpp
#define PartitionFunc_hpp

#include <cstdint>

#include "MemBlock2D.hpp"

namespace partfunc { // partfunc namespace
    
    /**
     Applies SSF partitioning scheme to selecte grid weights.
     Reference: R. E. Stratmann, G. E. Scuseria, and M. J. Frisch, Chem. Phys.
     Lett., 213 (257), 1996.

     @param rawGridPoints the raw grid points.
     @param minDistance the distance to closest neighbouring atom.
     @param gridOffset the atom grid points offset in raw grid points.
     @param nGridPoints the number of grid points.
     @param atomCoordinatesX the vector of Cartesian X coordinates of atoms.
     @param atomCoordinatesY the vector of Cartesian Y coordinates of atoms.
     @param atomCoordinatesZ the vector of Cartesian Z coordinates of atoms.
     @param nAtoms the number of atoms.
     @param idAtomic the index of atom.
     */
    void ssf(      CMemBlock2D<double>* rawGridPoints,
             const double               minDistance,
             const int32_t              gridOffset,
             const int32_t              nGridPoints,
             const double*              atomCoordinatesX,
             const double*              atomCoordinatesY,
             const double*              atomCoordinatesZ,
             const int32_t              nAtoms,
             const int32_t              idAtomic);
    
    /**
     Computes polynomial weight function in eliptical coordinates. See Eq. 14
     in R. E. Stratmann, G. E. Scuseria, and M. J. Frisch, Chem. Phys. Lett.,
     213 (257), 1996.

     @param eRadius the eliptical coordinate.
     @return the polynomial weight.
     */
    double zeta(const double eRadius);
    
} // partfunc namespace

#endif /* PartitionFunc_hpp */
