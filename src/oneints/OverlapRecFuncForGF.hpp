//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include<cstdint>

#include "MemBlock2D.hpp"
#include "GtoBlock.hpp"

namespace ovlrecfunc { // ovlrecfunc namespace

    /**
    Computes batch of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF(      CMemBlock2D<double>& primBuffer,
                          const CMemBlock2D<double>& auxBuffer,
                          const CMemBlock2D<double>& osFactors,
                          const CMemBlock2D<double>& paDistances,
                          const CMemBlock2D<double>& pbDistances,
                          const CGtoBlock&           braGtoBlock,
                          const CGtoBlock&           ketGtoBlock,
                          const int32_t              iContrGto);

    /**
    Computes sub-batch (0,10) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_0_10(      CMemBlock2D<double>& primBuffer,
                               const CMemBlock2D<double>& auxBuffer,
                               const CMemBlock2D<double>& osFactors,
                               const CMemBlock2D<double>& paDistances,
                               const CMemBlock2D<double>& pbDistances,
                               const CGtoBlock&           braGtoBlock,
                               const CGtoBlock&           ketGtoBlock,
                               const int32_t              iContrGto);

    /**
    Computes sub-batch (10,20) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_10_20(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (20,30) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_20_30(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (30,40) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_30_40(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (40,50) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_40_50(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (50,60) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_50_60(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (60,70) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_60_70(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (70,80) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_70_80(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (80,90) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_80_90(      CMemBlock2D<double>& primBuffer,
                                const CMemBlock2D<double>& auxBuffer,
                                const CMemBlock2D<double>& osFactors,
                                const CMemBlock2D<double>& paDistances,
                                const CMemBlock2D<double>& pbDistances,
                                const CGtoBlock&           braGtoBlock,
                                const CGtoBlock&           ketGtoBlock,
                                const int32_t              iContrGto);

    /**
    Computes sub-batch (90,100) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_90_100(      CMemBlock2D<double>& primBuffer,
                                 const CMemBlock2D<double>& auxBuffer,
                                 const CMemBlock2D<double>& osFactors,
                                 const CMemBlock2D<double>& paDistances,
                                 const CMemBlock2D<double>& pbDistances,
                                 const CGtoBlock&           braGtoBlock,
                                 const CGtoBlock&           ketGtoBlock,
                                 const int32_t              iContrGto);

    /**
    Computes sub-batch (100,110) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_100_110(      CMemBlock2D<double>& primBuffer,
                                  const CMemBlock2D<double>& auxBuffer,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pbDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto);

    /**
    Computes sub-batch (110,120) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_110_120(      CMemBlock2D<double>& primBuffer,
                                  const CMemBlock2D<double>& auxBuffer,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pbDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto);

    /**
    Computes sub-batch (120,130) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_120_130(      CMemBlock2D<double>& primBuffer,
                                  const CMemBlock2D<double>& auxBuffer,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pbDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto);

    /**
    Computes sub-batch (130,140) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_130_140(      CMemBlock2D<double>& primBuffer,
                                  const CMemBlock2D<double>& auxBuffer,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pbDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto);

    /**
    Computes sub-batch (140,150) of primitive (G||F) overlap integrals and stores
    results in primitives buffer.

    @param primBuffer the primitives buffer.
    @param auxBuffer the auxilaries buffer.
    @param osFactors the Obara-Saika recursion factors.
    @param paDistances the vector of distances R(PA) = P - A.
    @param pbDistances the vector of distances R(PB) = P - B.
    @param braGtoBlock the GTOs block on bra side.
    @param ketGtoBlock the GTOs block on ket side.
    @param iContrGto the index of contracted GTO on bra side.
    */
    void compOverlapForGF_140_150(      CMemBlock2D<double>& primBuffer,
                                  const CMemBlock2D<double>& auxBuffer,
                                  const CMemBlock2D<double>& osFactors,
                                  const CMemBlock2D<double>& paDistances,
                                  const CMemBlock2D<double>& pbDistances,
                                  const CGtoBlock&           braGtoBlock,
                                  const CGtoBlock&           ketGtoBlock,
                                  const int32_t              iContrGto);


} // ovlrecfunc namespace

