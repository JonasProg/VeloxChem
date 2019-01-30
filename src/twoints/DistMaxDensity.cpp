//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "DistMaxDensity.hpp"

#include <cmath>

#include "AngularMomentum.hpp"

namespace distmaxden { // distmaxden namespace

    void
    getMaxRestDenJK(      CMemBlock<double>&   maxDensityElements,
                    const double*              densityMatrix,
                    const int32_t              nDensityColumns,
                    const CGtoPairsBlock&      braGtoPairsBlock,
                    const CGtoPairsBlock&      ketGtoPairsBlock,
                    const int32_t              nKetContrPairs,
                    const int32_t              iContrPair)
    {
        // set up angular momentum on bra
        
        auto aang = braGtoPairsBlock.getBraAngularMomentum();
        
        auto bang = braGtoPairsBlock.getKetAngularMomentum();
        
        // set up angular momentum on ket
        
        auto cang = ketGtoPairsBlock.getBraAngularMomentum();
        
        auto dang = ketGtoPairsBlock.getKetAngularMomentum();
        
        // set up number of angular components on bra
        
        auto acomp = angmom::to_SphericalComponents(aang);
        
        auto bcomp = angmom::to_SphericalComponents(bang);
        
        // set up number of angular components on ket
        
        auto ccomp = angmom::to_SphericalComponents(cang);
        
        auto dcomp = angmom::to_SphericalComponents(dang);
        
        // determine symmetry of angular components on bra side
        
        auto refp = (braGtoPairsBlock.getBraIdentifiers(0))[iContrPair];
        
        auto refq = (braGtoPairsBlock.getKetIdentifiers(0))[iContrPair];
        
        bool symbra = (refp == refq);
        
        // set up pointers to reference indexes on ket side
        
        auto prefk = ketGtoPairsBlock.getBraIdentifiers(0);
        
        auto prefl = ketGtoPairsBlock.getKetIdentifiers(0);
        
        // set up pointer to vector max. density elements
        
        auto mdenvec = maxDensityElements.data();
        
        // loop over angular components on bra side
        
        for (int32_t i = 0; i < acomp; i++)
        {
            // set up index P for bra side
            
            int32_t idp  = (braGtoPairsBlock.getBraIdentifiers(i))[iContrPair];
            
            // starting angular index of Q
            
            auto jstart = (symbra) ? i : 0;
            
            for (int32_t j = jstart; j < bcomp; j++)
            {
                // set up index Q for bra side
                
                int32_t idq = (braGtoPairsBlock.getKetIdentifiers(j))[iContrPair];
                
                // loop over angular components on ket side
                
                for (int32_t k = 0; k < ccomp; k++)
                {
                    // set up pointer to R indexes on ket side
                    
                    auto idxk = ketGtoPairsBlock.getBraIdentifiers(k);
                    
                    for (int32_t l = 0; l < dcomp; l++)
                    {
                        // set up pointer to S indexes on ket side
                        
                        auto idxl = ketGtoPairsBlock.getKetIdentifiers(l);
                        
                        // loop over pairs on ket side
                        
                        for (int32_t m = 0; m < nKetContrPairs; m++)
                        {
                            // symmetry restriction for ket angular components
                            
                            auto refr = prefk[m];
                            
                            auto refs = prefl[m];
                            
                            if ((refr == refs) && (l < k)) continue;
                            
                            // symmetry restriction for bra/ket angular componets
                            
                            bool braeqket = (refp == refr) && (refq == refs);
                            
                            if  (((k * dcomp + l) < (i * bcomp + j)) && braeqket) continue;
                            
                            // set up S and R indexes
                            
                            auto idr = idxk[m];
                            
                            auto ids = idxl[m];
                            
                            // Coulomb contributions
                            
                            auto mden = 4.0 * std::fabs(densityMatrix[idr * nDensityColumns + ids]);
                            
                            auto cden = 4.0 * std::fabs(densityMatrix[idp * nDensityColumns + idq]);
                            
                            if (cden > mden) mden = cden;
                            
                            // exchange contributions
                            
                            cden = std::fabs(densityMatrix[idq * nDensityColumns + ids]);
                            
                            if (cden > mden) mden = cden;
                            
                            cden = std::fabs(densityMatrix[idq * nDensityColumns + idr]);
                            
                            if (cden > mden) mden = cden;
                            
                            cden = std::fabs(densityMatrix[idp * nDensityColumns + ids]);
                            
                            if (cden > mden) mden = cden;
                            
                            cden = std::fabs(densityMatrix[idp * nDensityColumns + idr]);
                            
                            if (cden > mden) mden = cden;
                            
                            // copy max. density element
                            
                            if (mden > mdenvec[m]) mdenvec[m] = mden;
                        }
                    }
                }
            }
        }
    }
    
} // distmaxden namespace
