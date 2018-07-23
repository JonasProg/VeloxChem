//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "MathFunc.hpp"

#include "MathConst.hpp"

namespace mathfunc { // mathfunc namespace

    void
    zero(      double* vector,
         const int32_t nElements)
    {
        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) vector[i] = 0.0;
    }
    
    void
    zero(      int32_t* vector,
         const int32_t nElements)
    {
        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) vector[i] = 0;
    }

    void
    set_to(      double* vector,
           const double  value,
           const int32_t nElements)
    {
        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) vector[i] = value;
    }
    
    void
    set_to(      int32_t* vector,
           const int32_t  value,
           const int32_t  nElements)
    {
        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) vector[i] = value;
    }

    double
    sum(const double* vector,
        const int32_t nElements)
    {
        double fsum = 0.0;

        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) fsum += vector[i];

        return fsum;
    }

    int32_t
    sum(const int32_t* vector,
        const int32_t  nElements)
    {
        int32_t isum = 0;

        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) isum += vector[i];

        return isum;
    }
    
    double
    max(const double* vector,
        const int32_t nElements)
    {
        double fmax = vector[0];
        
        for (int32_t i = 1; i < nElements; i++)
        {
            auto cmax = vector[i];
            
            if (cmax > fmax) fmax = cmax;
        }
        
        return fmax;
    }
    
    int32_t
    max(const int32_t* vector,
        const int32_t  nElements)
    {
        auto imax = vector[0];
        
        for (int32_t i = 1; i < nElements; i++)
        {
            auto cmax = vector[i];
            
            if (cmax > imax) imax= cmax;
        }
        
        return imax;
    }

    void
    normalize(      double* vector,
              const int32_t nElements)
    {
        auto factor = 1.0 / mathfunc::sum(vector, nElements);

        #pragma omp simd aligned(vector: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++) vector[i] *= factor;
    }

    void
    indexes(      int32_t* aVector,
            const int32_t* bVector,
            const int32_t  nElements)
    {
        int32_t index = 0;

        for (int32_t i = 0; i < nElements; i++)
        {
            aVector[i] = index;

            index += bVector[i];
        }
    }
    
    void
    distances(      double* abCoordsX,
                    double* abCoordsY,
                    double* abCoordsZ,
              const double  aCoordX,
              const double  aCoordY,
              const double  aCoordZ,
              const double* bCoordsX,
              const double* bCoordsY,
              const double* bCoordsZ,
              const int32_t nElements)
    {
        #pragma omp simd aligned(abCoordsX, abCoordsY, abCoordsZ, bCoordsX,\
                                 bCoordsY, bCoordsZ: VLX_ALIGN)
        for (int32_t i = 0; i < nElements; i++)
        {
            abCoordsX[i] = aCoordX - bCoordsX[i];
            
            abCoordsY[i] = aCoordY - bCoordsY[i];
            
            abCoordsZ[i] = aCoordZ - bCoordsZ[i];
        }
    }
    
    void
    quadChebyshevOfKindTwo(      double* coordinates,
                                 double* weights,
                           const int32_t nPoints)
    {
        // prefactor
        
        auto fstep = mathconst::getPiValue()
                   / (static_cast<double>(nPoints) + 1.0);
        
        // loop over grid points
        
        for (int32_t i = 1; i < nPoints + 1; i++)
        {
            auto farg = static_cast<double>(i) * fstep;
            
            coordinates[i - 1]  = std::cos(farg);
            
            auto warg= std::sin(farg);
            
            weights[i - 1] = fstep * warg * warg;
        }
    }
    
    void
    copy(      int32_t* aVector,
         const int32_t  aPosition,
         const int32_t* bVector,
         const int32_t  bPosition,
         const int32_t  nElements)
    {
        for (int32_t i = 0; i < nElements; i++)
        {
            aVector[aPosition + i] = bVector[bPosition + i];
        }
    }
    
    void
    copy(      double* aVector,
         const int32_t aPosition,
         const double* bVector,
         const int32_t bPosition,
         const int32_t nElements)
    {
        for (int32_t i = 0; i < nElements; i++)
        {
            aVector[aPosition + i] = bVector[bPosition + i];
        }
    }
    
} // mathfunc namespace


