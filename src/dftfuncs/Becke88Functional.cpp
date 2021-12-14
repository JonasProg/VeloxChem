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

#include "Becke88Functional.hpp"

#include <cmath>

#include "MathConst.hpp"

namespace vxcfuncs {  // vxcfuncs namespace
   
    CXCFunctional
    setBecke88Functional()
    {
        return CXCFunctional({"Becke88"}, xcfun::gga, 0.0, {setPrimitiveBecke88Functional()}, {1.0});
    }
    
    CPrimitiveFunctional
    setPrimitiveBecke88Functional()
    {
        return CPrimitiveFunctional({"Becke88"}, xcfun::gga,
                                    &vxcfuncs::Becke88FuncGradientAB,
                                    &vxcfuncs::Becke88FuncGradientA,
                                    &vxcfuncs::Becke88FuncGradientB,
                                    &vxcfuncs::Becke88FuncHessianAB,
                                    &vxcfuncs::Becke88FuncHessianA,
                                    &vxcfuncs::Becke88FuncHessianB,
                                    &vxcfuncs::Becke88FuncCubicHessianAB,
                                    &vxcfuncs::Becke88FuncCubicHessianA,
                                    &vxcfuncs::Becke88FuncCubicHessianB); 
    }
    
    void
    Becke88FuncGradientAB(      CXCGradientGrid& xcGradientGrid,
                          const double           factor,
                          const CDensityGrid&    densityGrid)
    {
        // functional prefactors
        
        double fb = 0.0042; 

        double fp = 4.0 / 3.0;
        
        double fre = -factor * fb;
        
        // determine number of grid points
        
        auto ngpoints = densityGrid.getNumberOfGridPoints();
        
        // set up pointers to density grid data
        
        auto rhoa = densityGrid.alphaDensity(0);
        
        auto rhob = densityGrid.betaDensity(0);
        
        auto grada = densityGrid.alphaDensityGradient(0);
        
        auto gradb = densityGrid.betaDensityGradient(0);
        
        // set up pointers to functional data
        
        auto fexc = xcGradientGrid.xcFunctionalValues();
        
        auto grhoa = xcGradientGrid.xcGradientValues(xcvars::rhoa);
        
        auto grhob = xcGradientGrid.xcGradientValues(xcvars::rhob);
        
        auto ggrada = xcGradientGrid.xcGradientValues(xcvars::grada);
        
        auto ggradb = xcGradientGrid.xcGradientValues(xcvars::gradb);
        
        #pragma omp simd aligned(rhoa, rhob, grada, gradb, fexc, grhoa, grhob, ggrada, ggradb: VLX_ALIGN)
        for (int32_t i = 0; i < ngpoints; i++)
        {
            double ra = std::pow(rhoa[i], fp);
            
            double xa = grada[i] / ra;
            
            double faa10 = -fp * xa / rhoa[i];
            
            double rb = std::pow(rhob[i], fp);
            
            double xb = gradb[i] / rb;
            
            double fab10 = -fp * xb / rhob[i];
    
            double fda = 1.0 + 6.0 * xa * fb * std::asinh(xa);
            
            double fea = ra * xa * xa / fda;
            
            double fsqa = std::sqrt(1.0 + xa * xa);
            
            double ffa = -xa * fb / fda;
            
            double ff1a = fb * (6.0 * xa * xa * fb - fsqa) / (fsqa * fda * fda);
            
            double fdb = 1.0 + 6.0 * xb * fb * std::asinh(xb);
            
            double feb = rb * xb * xb / fdb;
            
            double fsqb = std::sqrt(1.0 + xb * xb);
            
            double ffb = -xb * fb / fdb;
            
            double ff1b = fb * (6.0 * xb * xb * fb - fsqb) / (fsqb * fdb * fdb);

            fexc[i] += fre * (fea + feb);
            
            grhoa[i] += factor * grada[i] * ff1a * faa10;
            
            ggrada[i] += factor*(ffa + xa * ff1a);
            
            grhob[i] += factor * gradb[i] * ff1b * fab10;
            
            ggradb[i] += factor * (ffb + xb * ff1b);
        }
    }
    
    void
    Becke88FuncGradientA(      CXCGradientGrid& xcGradientGrid,
                         const double           factor,
                         const CDensityGrid&    densityGrid)
    {
                // functional prefactors
        
        double fb = 0.0042; 

        double fp = 4.0 / 3.0;
        
        double fre = -factor * fb;
        
        // determine number of grid points
        
        auto ngpoints = densityGrid.getNumberOfGridPoints();
        
        // set up pointers to density grid data
        
        auto rhob = densityGrid.betaDensity(0);
        
        auto gradb = densityGrid.betaDensityGradient(0);
        
        // set up pointers to functional data
        
        auto fexc = xcGradientGrid.xcFunctionalValues();
        
        auto grhob = xcGradientGrid.xcGradientValues(xcvars::rhob);
                
        auto ggradb = xcGradientGrid.xcGradientValues(xcvars::gradb);
        
        #pragma omp simd aligned(rhob, gradb, fexc, grhob, ggradb: VLX_ALIGN)
        for (int32_t i = 0; i < ngpoints; i++)
        {
            
            double rb = std::pow(rhob[i], fp);
            
            double xb = gradb[i] / rb;
            
            double fab10 = -fp * xb / rhob[i];
                       
            double fdb = 1.0 + 6.0 * xb * fb * std::asinh(xb);
            
            double feb = rb * xb * xb / fdb;
            
            double fsqb = std::sqrt(1.0 + xb * xb);
            
            double ffb = -xb * fb / fdb;
            
            double ff1b = fb * (6.0 * xb * xb * fb - fsqb) / (fsqb * fdb * fdb);

            fexc[i] += fre * (feb);
            
            grhob[i] += factor * gradb[i] * ff1b * fab10;
            
            ggradb[i] += factor * (ffb + xb * ff1b);
         }
    }
    void
    Becke88FuncGradientB(      CXCGradientGrid& xcGradientGrid,
                         const double           factor,
                         const CDensityGrid&    densityGrid)
    {
               // functional prefactors
        
        double fb = 0.0042; 
        
        double fp = 4.0 / 3.0;
        
        double fre = -factor * fb;
        
        // determine number of grid points
        
        auto ngpoints = densityGrid.getNumberOfGridPoints();
        
        // set up pointers to density grid data
        
        auto rhoa = densityGrid.alphaDensity(0);
        
        auto grada = densityGrid.alphaDensityGradient(0);
        
        // set up pointers to functional data
        
        auto fexc = xcGradientGrid.xcFunctionalValues();
        
        auto grhoa = xcGradientGrid.xcGradientValues(xcvars::rhoa);
                
        auto ggrada = xcGradientGrid.xcGradientValues(xcvars::grada);
                
        #pragma omp simd aligned(rhoa, grada, fexc, grhoa, ggrada: VLX_ALIGN)
        for (int32_t i = 0; i < ngpoints; i++)
        {
            double ra = std::pow(rhoa[i], fp);
            
            double xa = grada[i] / ra;

            double faa10 = -fp * xa / rhoa[i];
            
            double fda = 1.0 + 6.0 * xa * fb * std::asinh(xa);
            
            double fea = ra * xa * xa / fda;
            
            double fsqa = std::sqrt(1.0 + xa * xa);
            
            double ffa = -xa * fb / fda;
            
            double ff1a = fb * (6.0 * xa * xa * fb - fsqa) / (fsqa * fda * fda);

            fexc[i] += fre * (fea);
            
            grhoa[i] += factor * grada[i] * ff1a * faa10;
            
            ggrada[i] += factor*(ffa + xa * ff1a);

        }
    }
    
    void Becke88FuncHessianAB(      CXCHessianGrid& xcHessianGrid,
                              const double          factor,
                              const CDensityGrid&   densityGrid)
    {
        // functional prefactors
        
        double fb = 0.0042;
        
        double fp = 4.0 / 3.0;
        
        // determine number of grid points
        
        auto ngpoints = densityGrid.getNumberOfGridPoints();
        
        // set up pointers to density grid data
        
        auto rhoa = densityGrid.alphaDensity(0);
        
        //auto rhob = densityGrid.betaDensity(0);
        
        auto grada = densityGrid.alphaDensityGradient(0);
        
        //auto gradb = densityGrid.betaDensityGradient(0);
        
        // set up pointers to functional data
        
        auto grho_aa = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::rhoa);
        
        //auto grho_bb = xcHessianGrid.xcHessianValues(xcvars::rhob, xcvars::rhob);
        
        auto gmix_aa = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::grada);
        
        //auto gmix_bb = xcHessianGrid.xcHessianValues(xcvars::rhob, xcvars::gradb);
        
        auto ggrad_aa = xcHessianGrid.xcHessianValues(xcvars::grada, xcvars::grada);
        
        //auto ggrad_bb = xcHessianGrid.xcHessianValues(xcvars::gradb, xcvars::gradb);
        
        #pragma omp simd aligned(rhoa, grada, grho_aa, gmix_aa, ggrad_aa: VLX_ALIGN)
        for (int32_t i = 0; i < ngpoints; i++)
        {
            double ra = std::pow(rhoa[i], fp);
            
            double xa = grada[i] / ra;
            
            double xa2 = xa * xa;
            
            double xa3 = xa * xa2;
            
            double xa4 = xa3 * xa;
            
            double asha = std::asinh(xa);
            
            double alpha10 = -fp * xa / rhoa[i];
            
            double alpha20 = -7.0 / 3.0 * alpha10 / rhoa[i];
            
            double alpha01 = 1.0 / ra;
            
            double alpha11 = -fp * alpha01 / rhoa[i];
            
            double alpha10_2 = alpha10 * alpha10;
            
            double sq1a2 = std::sqrt(1.0 + xa2);
            
            double denom = 1.0 + 6.0 * xa * fb * asha;
            
            double denom2 = denom * denom;
            
            double denom3 = denom2 * denom;
            
            double ff1 = fb * (6 * xa2 * fb - sq1a2) / (sq1a2 * denom2);
                
            double ff2 = (6.0 * fb * fb * (4.0 * xa + xa3*(3.0 - 12.0 * sq1a2 * fb) + 2.0 * (std::pow(1.0 + xa2, 1.5) - 3.0 * xa4 * fb) * asha)) / (std::pow(1.0 + xa2, 1.5) * denom3);
            
            gmix_aa[i] += factor* (ff1 * alpha10 + grada[i] * (ff2 * alpha10* alpha01 + ff1 * alpha11));
            
            grho_aa[i] += factor * grada[i] * (ff2 * alpha10_2 + ff1 * alpha20);
            
            ggrad_aa[i] += factor * (2.0 * ff1 * alpha01 + grada[i] * (ff2 * alpha01 * alpha01));
            
            // FIX ME: Add beta part
        }
    }
    
    void Becke88FuncHessianA(      CXCHessianGrid& xcHessianGrid,
                             const double          factor,
                             const CDensityGrid&   densityGrid)
    {
        
    }
    
    void Becke88FuncHessianB(      CXCHessianGrid& xcHessianGrid,
                             const double          factor,
                             const CDensityGrid&   densityGrid)
    {
        
    }
    
    void Becke88FuncCubicHessianAB(     CXCCubicHessianGrid& xcCubicHessianGrid,
                                  const double          factor,
                                  const CDensityGrid&   densityGrid)
    {
     // functional prefactors
        
        // determine number of grid points
        
        auto ngpoints = densityGrid.getNumberOfGridPoints();
        
        // set up pointers to density grid data
        
        auto rhoa = densityGrid.alphaDensity(0);
        
        auto rhob = densityGrid.betaDensity(0);
        
        auto grada = densityGrid.alphaDensityGradient(0);
        
        auto gradb = densityGrid.betaDensityGradient(0);
        
        // set up pointers to functional data

        auto gmix_aaa = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhoa, xcvars::rhoa, xcvars::grada);

        auto ggradmix_aaa = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhoa, xcvars::grada, xcvars::grada);
        
        auto ghro_aaa = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhoa, xcvars::rhoa, xcvars::rhoa);
        
        auto ggrad_aaa = xcCubicHessianGrid.xcCubicHessianValues(xcvars::grada, xcvars::grada, xcvars::grada);        

        auto gmix_bbb = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhob, xcvars::rhob, xcvars::gradb);

        auto ggradmix_bbb = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhob, xcvars::gradb, xcvars::gradb);
        
        auto ghro_bbb = xcCubicHessianGrid.xcCubicHessianValues(xcvars::rhob, xcvars::rhob, xcvars::rhob);
        
        auto ggrad_bbb = xcCubicHessianGrid.xcCubicHessianValues(xcvars::gradb, xcvars::gradb, xcvars::gradb);

        double fp = 4.0/3.0;
        
        double fb = 0.0042;

        #pragma omp simd aligned(rhoa,rhob, grada, gradb, gmix_aaa, ggradmix_aaa : VLX_ALIGN)

        for (int32_t i = 0; i < ngpoints; i++)
        {

            // Alpha 

            double ra = std::pow(rhoa[i], -fp);
            
            double xa = grada[i] / ra;
            
            double xa2 = xa * xa;
            
            double xa3 = xa * xa2;
            
            double xa4 = xa3 * xa;

            double xa5 = xa4 * xa;
            
            double asha = std::asinh(xa);

            double asha2 = asha * asha;
            
            double alpha10_a = -fp * xa / rhoa[i];
            
            double alpha20_a = -7.0 / 3.0 * alpha10_a / rhoa[i];

            double alpha21_a = alpha20_a / grada[i];
            
            double alpha30_a = -10.0 / 3.0 * alpha20_a / rhoa[i];

            double alpha01_a = 1.0 / ra;
            
            double alpha11_a = -fp * alpha01_a / rhoa[i];
            
            double alpha10_2_a = alpha10_a * alpha10_a;
            
            double sq1a2_a = std::sqrt(1.0 + xa2);
            
            double denom_a = 1.0 + 6.0 * xa * fb * asha;
            
            double denom2_a = denom_a * denom_a;
            
            double denom3_a = denom2_a * denom_a;

            double denom4_a = denom3_a*denom_a;
            
            double ff1_a = fb * (6 * xa2 * fb - sq1a2_a) / (sq1a2_a * denom2_a);
            
            double ff2_a = (6.0 * fb * fb * (4.0 * xa + xa3*(3.0 - 12.0 * sq1a2_a * fb) 
            
                        + 2.0 * (std::pow(1.0 + xa2, 1.5) - 3.0 * xa4 * fb) * asha)) / (std::pow(1.0 + xa2, 1.5) * denom3_a);
            
            double ff3_a = (6*fb*(6 + 5*xa2 + 2*xa4  - 12*xa*(6 + 16*xa2 + 7*xa4)*fb*asha 
	    
                         + 36*sq1a2_a*fb*(-xa2*(3 + 2*xa2) + 6*xa5*fb*asha - std::pow(1 + xa2,2.0)*asha2)

                        +  36*xa4*fb*(6*(1 + xa2) + (-1 + 2*xa2)*asha2)))/(std::pow(1 + xa2,2.5)*denom4_a);


            // Beta
            
            double rb = std::pow(rhob[i], -fp);
            
            double xb = gradb[i] / rb;
            
            double xb2 = xb * xb;
            
            double xb3 = xb * xb2;
            
            double xb4 = xb3 * xb;

            double xb5 = xb4 * xb;
            
            double ashb = std::asinh(xb);

            double ashb2 = ashb * ashb;
            
            double alpha10_b = -fp * xb / rhob[i];
            
            double alpha20_b = -7.0 / 3.0 * alpha10_b / rhob[i];

            double alpha21_b = alpha20_b / gradb[i];
            
            double alpha30_b = -10.0 / 3.0 * alpha20_b / rhob[i];

            double alpha01_b = 1.0 / rb;
            
            double alpha11_b = -fp * alpha01_b / rhob[i];
            
            double alpha10_2_b = alpha10_b * alpha10_b;
            
            double sq1a2_b = std::sqrt(1.0 + xb2);
            
            double denom_b = 1.0 + 6.0 * xb * fb * ashb;
            
            double denom2_b = denom_b * denom_b;
            
            double denom3_b = denom2_b * denom_b;

            double denom4_b = denom3_b*denom_b;
            
            double ff1_b = fb * (6 * xb2 * fb - sq1a2_b) / (sq1a2_b * denom2_b);
            
            double ff2_b = (6.0 * fb * fb * (4.0 * xb + xb3*(3.0 - 12.0 * sq1a2_b * fb) 
            
                        + 2.0 * (std::pow(1.0 + xb2, 1.5) - 3.0 * xb4 * fb) * ashb)) / (std::pow(1.0 + xb2, 1.5) * denom3_b);
            
            double ff3_b = (6*fb*(6 + 5*xb2 + 2*xb4  - 12*xb*(6 + 16*xb2 + 7*xb4)*fb*ashb 
	    
                         + 36*sq1a2_b*fb*(-xb2*(3 + 2*xb2) + 6*xb5*fb*ashb - std::pow(1 + xb2,2.0)*ashb2)

                        +  36*xb4*fb*(6*(1 + xb2) + (-1 + 2*xb2)*ashb2)))/(std::pow(1 + xb2,2.5)*denom4_b);


            // Alpha

            gmix_aaa[i] += factor*(ff2_a*alpha10_2_a + ff1_a * alpha20_a + grada[i]*(ff3_a*alpha10_2_a*alpha01_a 
            + 2*ff2_a*alpha11_a*alpha10_a + ff2_a*alpha20_a*alpha01_a + ff1_a*alpha21_a));

            ggradmix_aaa[i] += factor*(2*ff2_a*alpha10_a*alpha01_a + 2*ff1_a*alpha11_a + grada[i]*(ff3_a*alpha01_a*alpha01_a*alpha10_a + 
                                 2*ff2_a*alpha11_a*alpha01_a));
            
            ghro_aaa[i] += factor*grada[i]*(ff3_a * alpha10_2_a*alpha10_a + 3*ff2_a*alpha10_a*alpha20_a + ff1_a*alpha30_a);

            // Beta 

            gmix_bbb[i] += factor*(ff2_b*alpha10_2_b + ff1_b * alpha20_b + gradb[i]*(ff3_b*alpha10_2_b*alpha01_b 
            + 2*ff2_b*alpha11_b*alpha10_b + ff2_b*alpha20_b*alpha01_b + ff1_b*alpha21_b));

            ggradmix_bbb[i] += factor*(2*ff2_b*alpha10_b*alpha01_b + 2*ff1_b*alpha11_b + gradb[i]*(ff3_b*alpha01_b*alpha01_b*alpha10_b + 
                                 2*ff2_b*alpha11_b*alpha01_b));
            
            ghro_bbb[i] += factor*gradb[i]*(ff3_b * alpha10_2_b*alpha10_b + 3*ff2_b*alpha10_b*alpha20_b + ff1_b*alpha30_b);
        }
    }

    void Becke88FuncCubicHessianA(     CXCCubicHessianGrid& xcCubicHessianGrid,
                                  const double          factor,
                                  const CDensityGrid&   densityGrid)
    {


    }

    void Becke88FuncCubicHessianB(     CXCCubicHessianGrid& xcCubicHessianGrid,
                                  const double          factor,
                                  const CDensityGrid&   densityGrid)
    {

    }

}  // namespace vxcfuncs
