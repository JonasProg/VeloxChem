//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef OverlapIntegralsDriver_hpp
#define OverlapIntegralsDriver_hpp

#include "mpi.h"

#include "OutputStream.hpp"
#include "Molecule.hpp"
#include "MolecularBasis.hpp"
#include "OutputStream.hpp"
#include "ExecMode.hpp"
#include "OverlapMatrix.hpp"
#include "GtoContainer.hpp"
#include "VecIndexes.hpp"
#include "SparseMatrix.hpp"

/**
 Class COverlapIntegralsDriver computes one-electron integrals.
 
 @author Z. Rinkevicius
 */
class COverlapIntegralsDriver
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
     Comutes overlap integrals for pair of GTOs containers.

     @param braGtoContainer the GTOs container for bra side.
     @param ketGtoContainer the GTOs container for ket side.
     @return the overlap matrix object.
     */
    COverlapMatrix _compOverlapIntegrals(const CGtoContainer* braGtoContainer,
                                         const CGtoContainer* ketGtoContainer) const;
    
    /**
     Computes overlap integrals for specific pair of GTOs blocks.

     @param sparseBuffer the buffer of sparce matrices.
     @param braGtoContainer the GTOs container for bra side.
     @param iBraGtoBlock the index of GTOs block object in GTOs container for
            bra side.
     @param ketGtoContainer the GTOs container for ket side.
     @param iKetGtoBlock the index of GTOs block object in GTOs container for
            ket side.
     */
    void _compOverlapForGtoBlocks(      CSparseMatrix* sparseBuffer,
                                  const CGtoContainer* braGtoContainer,
                                  const int32_t        iBraGtoBlock,
                                  const CGtoContainer* ketGtoContainer,
                                  const int32_t        iKetGtoBlock) const;
    
    /**
     Computes batch of primitive overlap integrals using Obara-Saika recursion
     and stores results in primitives buffer.
     
     Batch size: (one contracted GTO on bra side) x (all contracted GTOs on ket side).

     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param abDistances the vector of distances R(AB) = A - B.
     @param paDistances the vector of distances R(PA) = P - A.
     @param pbDistances the vector of distances R(PB) = P - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void _compPrimOverlapInts(      CMemBlock2D<double>&  primBuffer,
                              const CVecTwoIndexes&       recPattern,
                              const std::vector<int32_t>& recIndexes,
                              const CMemBlock2D<double>&  osFactors,
                              const CMemBlock2D<double>&  abDistances,
                              const CMemBlock2D<double>&  paDistances,
                              const CMemBlock2D<double>&  pbDistances,
                              const CGtoBlock&            braGtoBlock,
                              const CGtoBlock&            ketGtoBlock,
                              const int32_t               iContrGto) const;
    
    /**
     Gets Obara-Saika recursion pattern for specific combination of GTOs blocks
     on bra and ket sides.

     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @return the vector of two indexes object with recursion pattern.
     */
    CVecTwoIndexes _getRecursionPattern(const CGtoBlock& braGtoBlock,
                                        const CGtoBlock& ketGtoBlock) const;
    
    /**
     Gets vector of unified indexes of primitive GTOs buffer for specific
     Obara-Saika recursion pattern.

     @param recIndexes the vector of starting indexes of data blocks in recursion
            pattern.
     @param recPattern the recursion pattern.
     @param maxPrimGtos the maximum number of primitive GTOs in contracted
            GTO on bra side.
     @return the total number of blocks in recursion pattern.
     */
    int32_t _getIndexesForRecursionPattern(      std::vector<int32_t>& recIndexes,
                                           const CVecTwoIndexes&       recPattern,
                                           const int32_t               maxPrimGtos) const;
    
    /**
     Creates buffer of sparse matrices for all allowed combinations of GTOs
     blocks from GTOs containers on bra and ket sides.

     @param braGtoContainer the GTOs container for bra side.
     @param ketGtoContainer the GTOs container for ket side.
     @return the vector of sparse matrices.
     */
    CSparseMatrix* _createSparseBuffer(const CGtoContainer* braGtoContainer,
                                       const CGtoContainer* ketGtoContainer) const;

public:
    
    /**
     Creates a overlap integrals driver object using MPI info.
     
     @param globRank the the rank of MPI process.
     @param globNodes the total number of MPI processes.
     @param comm the MPI communicator.
     */
    COverlapIntegralsDriver(const int32_t  globRank,
                            const int32_t  globNodes,
                                  MPI_Comm comm);
    
    /**
     Destroys a overlap integrals driver object.
     */
    ~COverlapIntegralsDriver();
    
    /**
     Computes overlap integrals for molecule in specific basis set and stores
     results in overlap matrix object.

     @param molecule the molecule.
     @param basis the molecular basis.
     @param comm the MPI communicator.
     @return the overlap matrix object.
     */
    COverlapMatrix compute(const CMolecule&       molecule,
                           const CMolecularBasis& basis,
                                 MPI_Comm         comm) const;
    
    /**
     Computes overlap integrals for molecule in two basis sets and stores
     results in overlap matrix object.
     
     @param molecule the molecule.
     @param braBasis the molecular basis for bra side of overlap matrix.
     @param ketBasis the molecular basis for ket side of overlap matrix.
     @param comm the MPI communicator.
     @return the overlap matrix object.
     */
    COverlapMatrix compute(const CMolecule&       molecule,
                           const CMolecularBasis& braBasis,
                           const CMolecularBasis& ketBasis,
                                 MPI_Comm         comm) const;
    
    /**
     Computes overlap integrals for two molecules in basis set and stores
     results in overlap matrix object.
     
     @param braMolecule the molecule for bra side of overlap matrix.
     @param ketMolecule the molecule for ket side of overlap matrix.
     @param basis the molecular basis.
     @param comm the MPI communicator.
     @return the overlap matrix object.
     */
    COverlapMatrix compute(const CMolecule&       braMolecule,
                           const CMolecule&       ketMolecule,
                           const CMolecularBasis& basis,
                                 MPI_Comm         comm) const;
    
    /**
     Computes overlap integrals for two molecules in different basis sets and
     stores results in overlap matrix object.
     
     @param braMolecule the molecule for bra side of overlap matrix.
     @param ketMolecule the molecule for ket side of overlap matrix.
     @param braBasis the molecular basis for bra side of overlap matrix.
     @param ketBasis the molecular basis for ket side of overlap matrix.
     @param comm the MPI communicator.
     @return the overlap matrix object.
     */
    COverlapMatrix compute(const CMolecule&       braMolecule,
                           const CMolecule&       ketMolecule,
                           const CMolecularBasis& braBasis,
                           const CMolecularBasis& ketBasis,
                                 MPI_Comm         comm) const;
};

#endif /* OverlapIntegralsDriver_hpp */
