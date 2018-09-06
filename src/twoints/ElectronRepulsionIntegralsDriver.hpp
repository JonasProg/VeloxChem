//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef ElectronRepulsionIntegralsDriver_hpp
#define ElectronRepulsionIntegralsDriver_hpp

#include <cstdint>

#include "mpi.h"

#include "Molecule.hpp"
#include "MolecularBasis.hpp"
#include "OutputStream.hpp"
#include "GtoPairsBlock.hpp"
#include "VecIndexes.hpp"

/**
 Class CElectronicRepulsionIntegralsDriver computes electron repulsion
 <f(r)g(r')| 1/|r-r'||h(r') i(r')> integrals.
 
 @author Z. Rinkevicius
 */
class CElectronRepulsionIntegralsDriver
{
    /**
     The rank of associated global MPI process.
     */
    int32_t _globRank;
    
    /**
     The total number of global MPI processes.
     */
    int32_t _globNodes;
    
    /**
     The rank of associated local MPI process.
     */
    int32_t _locRank;
    
    /**
     The total number of local MPI processes.
     */
    int32_t _locNodes;
    
    /**
     The flag for local execution mode.
     */
    bool _isLocalMode;
    
    /**
     Gets Obara-Saika bra side horizontal recursion pattern for specific
     combination of GTOs pairs blocks on bra and ket sides.
     
     @param braGtoPairsBlock the GTOs pairs block on bra side.
     @param ketGtoPairsBlock the GTOs pairs block on ket side.
     @return the vector of three indexes object with recursion pattern.
     */
    CVecFourIndexes _getBraHorizontalRecursionPattern(const CGtoPairsBlock& braGtoPairsBlock,
                                                      const CGtoPairsBlock& ketGtoPairsBlock) const;
    
    /**
     Gets Obara-Saika ket side horizontal recursion pattern for given set of leading terms.
     
     @param leadTerms the vector of leading terms in recursion pattern.
     @return the vector of three indexes object with recursion pattern.
     */
    CVecThreeIndexes _getKetHorizontalRecursionPattern(const CVecThreeIndexes& leadTerms) const;
    
    /**
     Gets Obara-Saika vertical recursion pattern for given set of leading terms.
     
     @param leadTerms the vector of leading terms in recursion pattern.
     @return the vector of three indexes object with recursion pattern.
     */
    CVecThreeIndexes _getVerticalRecursionPattern(const CVecThreeIndexes& leadTerms) const;
    
public:
    
    /**
     Creates an electron repulsion integrals driver object using MPI info.
     
     @param globRank the the rank of MPI process.
     @param globNodes the total number of MPI processes.
     @param comm the MPI communicator.
     */
    CElectronRepulsionIntegralsDriver(const int32_t  globRank,
                                      const int32_t  globNodes,
                                            MPI_Comm comm);
    
    /**
     Destroys an electron repulsion integrals driver object.
     */
    ~CElectronRepulsionIntegralsDriver();
    
    /**
     Computes electron repulsion integrals for molecule with specific AO basis
     set and process results according to provided distribution function.
     
     @param molecule the molecule.
     @param aoBasis the molecular AO basis.
     @param threshold the integrals cut-off threshold.
     @param oStream the output stream.
     @param comm the MPI communicator.
     */
    void  compute(const CMolecule&       molecule,
                  const CMolecularBasis& aoBasis,
                  const double           threshold,
                        COutputStream&   oStream,
                        MPI_Comm         comm) const;
    
    /**
     Computes electronic repulsion integrals for combination of GTOs pairs
     blocks.
     
     @param braGtoPairsBlock the GTOs pairsblock on bra side.
     @param ketGtoPairsBlock the GTOs pairs block on ket side.
     */
    void compElectronRepulsionForGtoPairsBlocks(const CGtoPairsBlock& braGtoPairsBlock,
                                                const CGtoPairsBlock& ketGtoPairsBlock) const;
};


#endif /* ElectronRepulsionIntegralsDriver_hpp */
