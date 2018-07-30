//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef GenFunc_hpp
#define GenFunc_hpp

#include <cstdint>

#include "MemBlock2D.hpp"
#include "SphericalMomentum.hpp"
#include "VecIndexes.hpp"
#include "GtoBlock.hpp"

namespace genfunc { // genfunc namespace
    
    /**
     Contracts primitive data vectors to contracted data vectors.

     @param contrData the contracted data vectors.
     @param primData the primitive data vectors.
     @param primIndex the index of first primitive data vector.
     @param startPositions the vector of start positions in contraction pattern.
     @param endPositions the vector of end positions in contractrion pattern.
     @param nElements the number of elements in individual contracted data
            vector.
     @param nBlocks the number of contracted vectors.
     */
    void contract(      CMemBlock2D<double>& contrData,
                  const CMemBlock2D<double>& primData,
                  const int32_t              primIndex,
                  const int32_t*             startPositions,
                  const int32_t*             endPositions,
                  const int32_t              nElements,
                  const int32_t              nBlocks);
    
    
    /**
     Contracts primitive data vectors to contracted data vectors using two step
     procedure. NOTE: Primitive data is destroyed during contraction process.

     @param contrData the contracted data vectors.
     @param primData the primitive data vectors.
     @param primIndex the index of first primitive data vector.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void contract(      CMemBlock2D<double>& contrData,
                        CMemBlock2D<double>& primData,
                  const int32_t              primIndex,
                  const CGtoBlock&           braGtoBlock,
                  const CGtoBlock&           ketGtoBlock,
                  const int32_t              iContrGto);
    
    /**
     Transforms Cartesian data vectors to spherical data vectors.

     @param spherData the spherical data vectors.
     @param cartData the Cartesian data vectors.
     @param spherMomentum the spherical momentum object.
     @param nElements the number elements in individual data vector.
     @param nBlocks the number of data vectors per spherical momentum component.
     */
    void transform(     CMemBlock2D<double>& spherData,
                  const CMemBlock2D<double>& cartData,
                  const CSphericalMomentum&  spherMomentum,
                  const int32_t              nElements,
                  const int32_t              nBlocks);
    
    /**
     Transforms Cartesian integrals to spherical integrals.
     
     @param spherData the spherical data vectors.
     @param cartData the Cartesian data vectors.
     @param braMomentum the spherical momentum object for bra side.
     @param ketMomentum the spherical momentum object for ket side.
     @param nElements the number elements in individual data vector.
     */
    void transform(      CMemBlock2D<double>& spherData,
                   const CMemBlock2D<double>& cartData,
                   const CSphericalMomentum&  braMomentum,
                   const CSphericalMomentum&  ketMomentum,
                   const int32_t              nElements);
    
    /**
     Checks if two indexes object is inside vector of two indexes objects.

     @param vector the vector of two indexes objects.
     @param pair the two indexes object.
     @return true if two indexes object is found in vector of two indexes
             objects, false - otherwise.
     */
    bool isInVector(const CVecTwoIndexes& vector,
                    const CTwoIndexes&    pair);
    
    /**
     Conditionally adds two indexes object to vector of two indexes objects.
     Addition is skipped if two indexes object is not valid indexing pair or
     is already resides in vector of two indexes objects.

     @param vector the vector of two indexes objects.
     @param pair the two indexes object.
     @return true if two indexes object is added to vector of two indexes
             objects, false otherwise.
     */
    bool addValidAndUniquePair(      CVecTwoIndexes& vector,
                               const CTwoIndexes&    pair);
    
    /**
     Finds index from vector of indexes associated with two indexes object in
     vector of two indexes objects.

     @param indexes the vector of indexes.
     @param vector the vector of two indexes objects.
     @param pair the two indexes object.
     @return the index assocated with two indexes object.
     */
    int32_t findPairIndex(const std::vector<int32_t>& indexes,
                          const CVecTwoIndexes&       vector,
                          const CTwoIndexes&          pair);

} // genfunc namespace

#endif /* GenFunc_hpp */
