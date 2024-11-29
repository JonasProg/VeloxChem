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

#include "PairDensityPBE_X.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "MathConst.hpp"

namespace pdftpbe_x {  // pdftpbe_x namespace

void
compute_exc_vxc(const int np, const double* rho, const double* sigma, double* exc, double* vrho, double* vsigma)
{

   // Subroutine generated by xc_write in MultiPsi, copyright M.G. Delcey, 2024

   double kappa = 0.80400000000000005;

   double param_mu = 0.2195149727645171;

   double fre = -3.0/8.0*cbrt(3)/cbrt(M_PI);

   double x2s = (1.0/12.0)*pow(6, 2.0/3.0)/pow(M_PI, 2.0/3.0);

   for (int g = 0; g < np; g++)
   {
      double density = rho[2 * g + 0];

      if (density < 1.0e-16)
      {
         exc[g] = 0.0;

         vrho[2 * g + 0] = 0.0;
         vrho[2 * g + 1] = 0.0;

         vsigma[3 * g + 0] = 0.0;
         vsigma[3 * g + 1] = 0.0;
         vsigma[3 * g + 2] = 0.0;

         continue;
      }

      double pair_density = rho[2 * g + 1];

      double sig = sigma[3 * g + 0];

      double rho83 = 0.15749013123685915*pow(density, 8.0/3.0);

      double drho83_drho = 0.41997368329829105*pow(density, 5.0/3.0);

      double xfact = param_mu*sig*pow(x2s, 2)/(kappa*rho83);

      double dxfact_drho = -drho83_drho*param_mu*sig*pow(x2s, 2)/(kappa*pow(rho83, 2));

      double dxfact_dsig = param_mu*pow(x2s, 2)/(kappa*rho83);

      double fg_zeta = 0;

      double dfg_zeta_dsig = 0;

      double dfg_zeta_drho = 0;

      double dfg_zeta_dpi = 0;

      if (pair_density < -9.9999999999999998e-17)
      {
         double zeta = M_SQRT2*sqrt(-pair_density)/density;

         double dzeta_dpi = (1.0/2.0)*M_SQRT2*sqrt(-pair_density)/(density*pair_density);

         double dzeta_drho = -M_SQRT2*sqrt(-pair_density)/pow(density, 2);

         double xsa2 = 0.25/pow(zeta + 1, 2.0/3.0);

         double dxsa2_dzeta = -0.16666666666666666/pow(zeta + 1, 5.0/3.0);

         double dxsa2_dpi = dxsa2_dzeta*dzeta_dpi;

         double dxsa2_drho = dxsa2_dzeta*dzeta_drho;

         double fa = pow(zeta + 1, 4.0/3.0)/(xfact*xsa2 + 1);

         double dfa_dxsa2 = -xfact*pow(zeta + 1, 4.0/3.0)/pow(xfact*xsa2 + 1, 2);

         double dfa_dxfact = -xsa2*pow(zeta + 1, 4.0/3.0)/pow(xfact*xsa2 + 1, 2);

         double dfa_dzeta = (4.0/3.0)*cbrt(zeta + 1)/(xfact*xsa2 + 1);

         double dfa_dsig = dfa_dxfact*dxfact_dsig;

         double dfa_drho = dfa_dxfact*dxfact_drho + dfa_dxsa2*dxsa2_drho + dfa_dzeta*dzeta_drho;

         double dfa_dpi = dfa_dxsa2*dxsa2_dpi + dfa_dzeta*dzeta_dpi;

         fg_zeta = fa;

         dfg_zeta_drho = dfa_drho;

         dfg_zeta_dsig = dfa_dsig;

         dfg_zeta_dpi = dfa_dpi;

         if (1 - zeta > 1.0e-16)
         {
             double xsb2 = 0.25/pow(1 - zeta, 2.0/3.0);

             double dxsb2_dzeta = 0.16666666666666666/pow(1 - zeta, 5.0/3.0);

             double dxsb2_dpi = dxsb2_dzeta*dzeta_dpi;

             double dxsb2_drho = dxsb2_dzeta*dzeta_drho;

             double fb = pow(1 - zeta, 4.0/3.0)/(xfact*xsb2 + 1);

             double dfb_dxsb2 = -xfact*pow(1 - zeta, 4.0/3.0)/pow(xfact*xsb2 + 1, 2);

             double dfb_dxfact = -xsb2*pow(1 - zeta, 4.0/3.0)/pow(xfact*xsb2 + 1, 2);

             double dfb_dzeta = -4.0/3.0*cbrt(1 - zeta)/(xfact*xsb2 + 1);

             double dfb_dsig = dfb_dxfact*dxfact_dsig;

             double dfb_drho = dfb_dxfact*dxfact_drho + dfb_dxsb2*dxsb2_drho + dfb_dzeta*dzeta_drho;

             double dfb_dpi = dfb_dxsb2*dxsb2_dpi + dfb_dzeta*dzeta_dpi;

             fg_zeta += fb;

             dfg_zeta_drho += dfb_drho;

             dfg_zeta_dsig += dfb_dsig;

             dfg_zeta_dpi += dfb_dpi;
         }
      }
      else if (pair_density < 9.9999999999999998e-17)
      {
         double xdenom = 0.25*xfact + 1;

         double dxdenom_dxfact = 0.25;

         double dxdenom_drho = dxdenom_dxfact*dxfact_drho;

         double dxdenom_dsig = dxdenom_dxfact*dxfact_dsig;

         double fg0 = 2.0/xdenom;

         double dfg0_dxdenom = -2.0/pow(xdenom, 2);

         double dfg0_drho = dfg0_dxdenom*dxdenom_drho;

         double dfg0_dsig = dfg0_dxdenom*dxdenom_dsig;

         double fg1 = (4.0/9.0)/xdenom + (1.0/18.0)*xfact*(4 + xfact/xdenom)/pow(xdenom, 2);

         double dfg1_dxfact = (1.0/18.0)*(4 + xfact/xdenom)/pow(xdenom, 2) + (1.0/18.0)*xfact/pow(xdenom, 3);

         double dfg1_dxdenom = -(4.0/9.0)/pow(xdenom, 2) - 1.0/9.0*xfact*(4 + xfact/xdenom)/pow(xdenom, 3) - 1.0/18.0*pow(xfact, 2)/pow(xdenom, 4);

         double dfg1_drho = dfg1_dxdenom*dxdenom_drho + dfg1_dxfact*dxfact_drho;

         double dfg1_dsig = dfg1_dxdenom*dxdenom_dsig + dfg1_dxfact*dxfact_dsig;

         double zeta2 = -2*pair_density/pow(density, 2);

         double dzeta2_dpi = -2/pow(density, 2);

         double dzeta2_drho = 4*pair_density/pow(density, 3);

         fg_zeta = fg0 + fg1*zeta2;

         double dfg_zeta_dfg0 = 1;

         double dfg_zeta_dfg1 = zeta2;

         double dfg_zeta_dzeta2 = fg1;

         dfg_zeta_drho = dfg0_drho*dfg_zeta_dfg0 + dfg1_drho*dfg_zeta_dfg1 + dfg_zeta_dzeta2*dzeta2_drho;

         dfg_zeta_dpi = dfg_zeta_dzeta2*dzeta2_dpi;

         dfg_zeta_dsig = dfg0_dsig*dfg_zeta_dfg0 + dfg1_dsig*dfg_zeta_dfg1;

      }
      else
      {
         double eta = M_SQRT2*sqrt(pair_density)/density;

         double deta_dpi = (1.0/2.0)*M_SQRT2/(density*sqrt(pair_density));

         double deta_drho = -M_SQRT2*sqrt(pair_density)/pow(density, 2);

         double r = cbrt(pow(eta, 2) + 1);

         double dr_deta = (2.0/3.0)*eta/pow(pow(eta, 2) + 1, 2.0/3.0);

         double dr_dpi = deta_dpi*dr_deta;

         double dr_drho = deta_drho*dr_deta;

         double theta = 0.66666666666666663*atan(eta);

         double dtheta_deta = 0.66666666666666663/(pow(eta, 2) + 1);

         double dtheta_dpi = deta_dpi*dtheta_deta;

         double dtheta_drho = deta_drho*dtheta_deta;

         double denomR = 1 + 0.25*xfact*cos(theta)/r;

         double ddenomR_dr = -0.25*xfact*cos(theta)/pow(r, 2);

         double ddenomR_dxfact = 0.25*cos(theta)/r;

         double ddenomR_dtheta = -0.25*xfact*sin(theta)/r;

         double ddenomR_dsig = ddenomR_dxfact*dxfact_dsig;

         double ddenomR_drho = ddenomR_dr*dr_drho + ddenomR_dtheta*dtheta_drho + ddenomR_dxfact*dxfact_drho;

         double ddenomR_dpi = ddenomR_dr*dr_dpi + ddenomR_dtheta*dtheta_dpi;

         double denomI = -0.25*xfact*sin(theta)/r;

         double ddenomI_dr = 0.25*xfact*sin(theta)/pow(r, 2);

         double ddenomI_dxfact = -0.25*sin(theta)/r;

         double ddenomI_dtheta = -0.25*xfact*cos(theta)/r;

         double ddenomI_dsig = ddenomI_dxfact*dxfact_dsig;

         double ddenomI_drho = ddenomI_dr*dr_drho + ddenomI_dtheta*dtheta_drho + ddenomI_dxfact*dxfact_drho;

         double ddenomI_dpi = ddenomI_dr*dr_dpi + ddenomI_dtheta*dtheta_dpi;

         double rho43R = pow(r, 2)*cos(2*theta);

         double drho43R_dr = 2*r*cos(2*theta);

         double drho43R_dtheta = -2*pow(r, 2)*sin(2*theta);

         double drho43R_dpi = dr_dpi*drho43R_dr + drho43R_dtheta*dtheta_dpi;

         double drho43R_drho = dr_drho*drho43R_dr + drho43R_dtheta*dtheta_drho;

         double rho43I = pow(r, 2)*sin(2*theta);

         double drho43I_dr = 2*r*sin(2*theta);

         double drho43I_dtheta = 2*pow(r, 2)*cos(2*theta);

         double drho43I_dpi = dr_dpi*drho43I_dr + drho43I_dtheta*dtheta_dpi;

         double drho43I_drho = dr_drho*drho43I_dr + drho43I_dtheta*dtheta_drho;

         double denom2 = 1.0/(pow(denomI, 2) + pow(denomR, 2));

         double ddenom2_ddenomR = -2.0*denomR/pow(pow(denomI, 2) + pow(denomR, 2), 2);

         double ddenom2_ddenomI = -2.0*denomI/pow(pow(denomI, 2) + pow(denomR, 2), 2);

         double ddenom2_drho = ddenom2_ddenomI*ddenomI_drho + ddenom2_ddenomR*ddenomR_drho;

         double ddenom2_dsig = ddenom2_ddenomI*ddenomI_dsig + ddenom2_ddenomR*ddenomR_dsig;

         double ddenom2_dpi = ddenom2_ddenomI*ddenomI_dpi + ddenom2_ddenomR*ddenomR_dpi;

         fg_zeta = denom2*(2*denomI*rho43I + 2*denomR*rho43R);

         double dfg_zeta_ddenomR = 2*denom2*rho43R;

         double dfg_zeta_drho43R = 2*denom2*denomR;

         double dfg_zeta_ddenom2 = 2*denomI*rho43I + 2*denomR*rho43R;

         double dfg_zeta_ddenomI = 2*denom2*rho43I;

         double dfg_zeta_drho43I = 2*denom2*denomI;

         dfg_zeta_dsig = ddenom2_dsig*dfg_zeta_ddenom2 + ddenomI_dsig*dfg_zeta_ddenomI + ddenomR_dsig*dfg_zeta_ddenomR;

         dfg_zeta_drho = ddenom2_drho*dfg_zeta_ddenom2 + ddenomI_drho*dfg_zeta_ddenomI + ddenomR_drho*dfg_zeta_ddenomR + dfg_zeta_drho43I*drho43I_drho + dfg_zeta_drho43R*drho43R_drho;

         dfg_zeta_dpi = ddenom2_dpi*dfg_zeta_ddenom2 + ddenomI_dpi*dfg_zeta_ddenomI + ddenomR_dpi*dfg_zeta_ddenomR + dfg_zeta_drho43I*drho43I_dpi + dfg_zeta_drho43R*drho43R_dpi;

      }
      double dfzeta_drho = 0;

      double fzeta = 0;

      double dfzeta_dpi = 0;

      if (pair_density < -9.9999999999999998e-17)
      {
         double zeta = M_SQRT2*sqrt(-pair_density)/density;

         double dzeta_dpi = (1.0/2.0)*M_SQRT2*sqrt(-pair_density)/(density*pair_density);

         double dzeta_drho = -M_SQRT2*sqrt(-pair_density)/pow(density, 2);

         double dfzeta_dzeta = 0.0;

         if (1.0 - zeta > 1.0e-16)
         {
             fzeta = pow(1.0 - zeta, 4.0/3.0) + pow(zeta + 1.0, 4.0/3.0);

             dfzeta_dzeta = -4.0/3.0*cbrt(1.0 - zeta) + (4.0/3.0)*cbrt(zeta + 1.0);
         }
         else
         {
             fzeta = pow(zeta + 1.0, 4.0/3.0);

             dfzeta_dzeta = (4.0/3.0)*cbrt(zeta + 1.0);
         }

         dfzeta_dpi = dfzeta_dzeta*dzeta_dpi;

         dfzeta_drho = dfzeta_dzeta*dzeta_drho;

      }
      else if (pair_density < 9.9999999999999998e-17)
      {
         double zeta2 = -2*pair_density/pow(density, 2);

         double dzeta2_dpi = -2/pow(density, 2);

         double dzeta2_drho = 4*pair_density/pow(density, 3);

         fzeta = (10.0/243.0)*pow(zeta2, 2) + (4.0/9.0)*zeta2 + 2.0;

         double dfzeta_dzeta2 = (20.0/243.0)*zeta2 + 4.0/9.0;

         dfzeta_dpi = dfzeta_dzeta2*dzeta2_dpi;

         dfzeta_drho = dfzeta_dzeta2*dzeta2_drho;

      }
      else
      {
         double eta = M_SQRT2*sqrt(pair_density)/density;

         double deta_dpi = (1.0/2.0)*M_SQRT2/(density*sqrt(pair_density));

         double deta_drho = -M_SQRT2*sqrt(pair_density)/pow(density, 2);

         double theta = (4.0/3.0)*atan(eta);

         double dtheta_deta = (4.0/3.0)/(pow(eta, 2) + 1);

         double dtheta_dpi = deta_dpi*dtheta_deta;

         double dtheta_drho = deta_drho*dtheta_deta;

         fzeta = 2.0*pow(pow(eta, 2) + 1, 2.0/3.0)*cos(theta);

         double dfzeta_dtheta = -2.0*pow(pow(eta, 2) + 1, 2.0/3.0)*sin(theta);

         double dfzeta_deta = 2.6666666666666665*eta*cos(theta)/cbrt(pow(eta, 2) + 1);

         dfzeta_dpi = deta_dpi*dfzeta_deta + dfzeta_dtheta*dtheta_dpi;

         dfzeta_drho = deta_drho*dfzeta_deta + dfzeta_dtheta*dtheta_drho;

      }
      double ex_pbe = cbrt(density)*fre*(-fg_zeta*kappa + fzeta*(kappa + 1));

      double dex_pbe_dfg_zeta = -cbrt(density)*fre*kappa;

      double dex_pbe_dfzeta = cbrt(density)*fre*(kappa + 1);

      double dex_pbe_dsig = dex_pbe_dfg_zeta*dfg_zeta_dsig;

      double dex_pbe_dpi = dex_pbe_dfg_zeta*dfg_zeta_dpi + dex_pbe_dfzeta*dfzeta_dpi;

      double dex_pbe_drho = dex_pbe_dfg_zeta*dfg_zeta_drho + dex_pbe_dfzeta*dfzeta_drho + (1.0/3.0)*fre*(-fg_zeta*kappa + fzeta*(kappa + 1))/pow(density, 2.0/3.0);

      exc[g] =  ex_pbe;

      double dExc_dex_pbe = density;

      vsigma[3 * g + 0] =  dExc_dex_pbe*dex_pbe_dsig;

      vrho[2 * g + 1] =  dExc_dex_pbe*dex_pbe_dpi;

      vrho[2 * g + 0] =  dExc_dex_pbe*dex_pbe_drho + ex_pbe;

      //Currently, no explicit dependence
      vsigma[3 * g + 1] = 0.0;
      vsigma[3 * g + 2] = 0.0;

   }
}

}  // namespace pdftpbe_x
