//
//                           VELOXCHEM 1.0-RC2
//         ----------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact
//
//  SPDX-License-Identifier: LGPL-3.0-or-later
//
//  This file is part of VeloxChem.
//
//  VeloxChem is free software: you can redistribute it and/or modify it under
//  the terms of the GNU Lesser General Public License as published by the Free
//  Software Foundation, either version 3 of the License, or (at your option)
//  any later version.
//
//  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
//  License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

#ifndef GridScreener_hpp
#define GridScreener_hpp

#include <cstdint>
#include <vector>

#include "DensityGrid.hpp"

namespace gridscreen {  // gridscreen namespace

/**
 Screens Vxc Fock for LDA.

 @param rho the density.
 @param exc the functional value.
 @param vrho the 1st-order functional derivative wrt density.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenVxcFockForLDA(double*       rho,
                         double*       exc,
                         double*       vrho,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Fxc Fock for LDA.

 @param rho the density.
 @param v2rho2 the 2nd-order functional derivative wrt density.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenFxcFockForLDA(double*       rho,
                         double*       v2rho2,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Vxc Fock for PLDA.

 @param rho the density.
 @param exc the functional value.
 @param vrho the 1st-order functional derivative wrt density.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenVxcFockForPLDA(double*       rho,
                          double*       exc,
                          double*       vrho,
                          const int32_t npoints,
                          const double  densityThreshold);

/*
 Screens Kxc Fock for LDA.

 @param rho the density.
 @param v2rho2 the 2nd-order functional derivative wrt rho.
 @param v3rho3 the 3rd-order functional derivative wrt rho.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenKxcFockForLDA(double*       rho,
                         double*       v2rho2,
                         double*       v3rho3,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Vxc Fock for GGA.

 @param rho the density.
 @param sigma the dot product of density gradient.
 @param exc the functional value.
 @param vrho the 1st-order functional derivative wrt rho.
 @param vsigma the 1st-order functional derivative wrt sigma.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenVxcFockForGGA(double*       rho,
                         double*       sigma,
                         double*       exc,
                         double*       vrho,
                         double*       vsigma,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Fxc Fock for GGA.

 @param rho the density.
 @param sigma the dot product of density gradient.
 @param vrho the 1st-order functional derivative wrt rho.
 @param vsigma the 1st-order functional derivative wrt sigma.
 @param v2rho2 the 2nd-order functional derivative wrt rho.
 @param v2rhosigma the 2nd-order functional derivative wrt rho and sigma.
 @param v2sigma2 the 2nd-order functional derivative wrt sigma.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenFxcFockForGGA(double*       rho,
                         double*       sigma,
                         double*       vrho,
                         double*       vsigma,
                         double*       v2rho2,
                         double*       v2rhosigma,
                         double*       v2sigma2,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Kxc Fock for GGA.

 @param rho the density.
 @param sigma the dot product of density gradient.
 @param vrho the 1st-order functional derivative wrt rho.
 @param vsigma the 1st-order functional derivative wrt sigma.
 @param v2rho2 the 2nd-order functional derivative wrt rho.
 @param v2rhosigma the 2nd-order functional derivative wrt rho and sigma.
 @param v2sigma2 the 2nd-order functional derivative wrt sigma.
 @param v3rho2 the 3rd-order functional derivative wrt rho.
 @param v3rho2sigma the 3rd-order functional derivative wrt rho and sigma.
 @param v3rhosigma2 the 3rd-order functional derivative wrt rho and sigma.
 @param v3sigma2 the 3rd-order functional derivative wrt sigma.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenKxcFockForGGA(double*       rho,
                         double*       sigma,
                         double*       vrho,
                         double*       vsigma,
                         double*       v2rho2,
                         double*       v2rhosigma,
                         double*       v2sigma2,
                         double*       v3rho3,
                         double*       v3rho2sigma,
                         double*       v3rhosigma2,
                         double*       v3sigma3,
                         const int32_t npoints,
                         const double  densityThreshold);

/**
 Screens Vxc Fock for meta-GGA.

 @param rho the density.
 @param sigma the dot product of density gradient.
 @param vrho the 1st-order functional derivative wrt rho.
 @param vsigma the 1st-order functional derivative wrt sigma.
 @param vlapl the 1st-order functional derivative wrt laplacian.
 @param vtau the 1st-order functional derivative wrt tau.
 @param npoints the number of grid points.
 @param densityThreshold the threshold for density grid screening.
 */
void screenVxcFockForMGGA(double*       rho,
                          double*       sigma,
                          double*       exc,
                          double*       vrho,
                          double*       vsigma,
                          double*       vlapl,
                          double*       vtau,
                          const int32_t npoints,
                          const double  densityThreshold);

/**
 Copies weights.

 @param screenedWeights pointer to the screened weights.
 @param gridBlockPosition the starting position of the grid box.
 @param weights pointer to the original weights of all grid points.
 @param nScreenedGridPoints the number of grid points after screening.
 */
void
copyWeights(double*       screenedWeights,
            const int32_t gridBlockPosition,
            const double* weights,
            const int32_t nGridPoints);

}  // namespace gridscreen

#endif /* GridScreener_hpp */
