//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef OverlapRecFunc_hpp
#define OverlapRecFunc_hpp

#include "MemBlock2D.hpp"
#include "GtoBlock.hpp"
#include "VecIndexes.hpp"

namespace ovlrecfunc { // ovlrecfunc namespace
    
    /**
     Computes batch of primitive (S|S) overlap integrals and stores results in
     primitives buffer.

     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param abDistances the vector of distances R(AB) = A - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForSS(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  abDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (S|P) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param pbDistances the vector of distances R(PB) = P - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForSP(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  pbDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (P|S) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForPS(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (P|P) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForPP(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (S|D) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param pbDistances the vector of distances R(PB) = P - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForSD(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  pbDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (D|S) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForDS(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (P|D) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForPD(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    // FIX ME: d,p
    
    
    /**
     Computes batch of primitive (D|D) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForDD(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (S|F) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param pbDistances the vector of distances R(PB) = P - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForSF(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  pbDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (F|S) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForFS(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (P|F) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForPF(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (D|F) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForDF(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (F|F) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForFF(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (S|G) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param pbDistances the vector of distances R(PB) = P - B.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForSG(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  pbDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (G|S) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForGS(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (P|G) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForPG(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (D|G) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForDG(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (F|G) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForFG(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);
    
    /**
     Computes batch of primitive (G|G) overlap integrals and stores results in
     primitives buffer.
     
     @param primBuffer the primitives buffer.
     @param recPattern the recursion pattern.
     @param recIndexes the indexes of data blocks in recursion pattern.
     @param osFactors the Obara-Saika recursion factors.
     @param paDistances the vector of distances R(PA) = P - A.
     @param braGtoBlock the GTOs block on bra side.
     @param ketGtoBlock the GTOs block on ket side.
     @param iContrGto the index of contracted GTO on bra side.
     */
    void compOverlapForGG(      CMemBlock2D<double>&  primBuffer,
                          const CVecTwoIndexes&       recPattern,
                          const std::vector<int32_t>& recIndexes,
                          const CMemBlock2D<double>&  osFactors,
                          const CMemBlock2D<double>&  paDistances,
                          const CGtoBlock&            braGtoBlock,
                          const CGtoBlock&            ketGtoBlock,
                          const int32_t               iContrGto);

} // ovlrecfunc namespace

#endif /* OverlapRecFunc_hpp */
