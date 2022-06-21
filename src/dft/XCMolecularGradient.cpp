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

#include "XCMolecularGradient.hpp"

#include <string>

#include "DensityGradientGridDriver.hpp"
#include "DensityGridDriver.hpp"
#include "DensityGridQuad.hpp"
#include "ErrorHandler.hpp"
#include "FunctionalParser.hpp"
#include "GtoFunc.hpp"
#include "MpiFunc.hpp"
#include "OMPTasks.hpp"

CXCMolecularGradient::CXCMolecularGradient(MPI_Comm comm)
{
    _locRank = mpi::rank(comm);

    _locNodes = mpi::nodes(comm);

    _locComm = comm;

    _thresholdOfDensity = 1.0e-13;
}

CXCMolecularGradient::~CXCMolecularGradient()
{
}

CDenseMatrix
CXCMolecularGradient::integrateVxcGradient(const std::vector<int32_t>& idsAtomic,
                                           const CAODensityMatrix&     aoDensityMatrix,
                                           const CMolecule&            molecule,
                                           const CMolecularBasis&      basis,
                                           const CMolecularGrid&       molecularGrid,
                                           const std::string&          xcFuncLabel) const
{
    return integrateVxcGradient(idsAtomic, aoDensityMatrix, aoDensityMatrix, molecule, basis, molecularGrid, xcFuncLabel);
}

CDenseMatrix
CXCMolecularGradient::integrateVxcGradient(const std::vector<int32_t>& idsAtomic,
                                           const CAODensityMatrix&     rwDensityMatrix,
                                           const CAODensityMatrix&     gsDensityMatrix,
                                           const CMolecule&            molecule,
                                           const CMolecularBasis&      basis,
                                           const CMolecularGrid&       molecularGrid,
                                           const std::string&          xcFuncLabel) const
{
    // parse exchange-correlation functional data

    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    // generate reference density grid

    CDensityGridDriver dgdrv(_locComm);

    auto refdengrid = dgdrv.generate(gsDensityMatrix, molecule, basis, molecularGrid, fvxc.getFunctionalType());

    // create molecular gradient

    const auto natoms = static_cast<int32_t>(idsAtomic.size());

    CDenseMatrix molgrad(3, natoms);

    auto mgradx = molgrad.row(0);

    auto mgrady = molgrad.row(1);

    auto mgradz = molgrad.row(2);

    if (rwDensityMatrix.isClosedShell())
    {
        // generate screened molecular and density grids

        CMolecularGrid mgrid(molecularGrid);

        CDensityGrid dgrid;

        refdengrid.getScreenedGridsPair(dgrid, mgrid, 0, _thresholdOfDensity, fvxc.getFunctionalType());

        auto gw = mgrid.getWeights();

        const auto gpoints = mgrid.getNumberOfGridPoints();

        // allocate XC gradient grid

        CXCGradientGrid vxcgrid(mgrid.getNumberOfGridPoints(), dgrid.getDensityGridType(), fvxc.getFunctionalType());

        // compute exchange-correlation functional first derrivatives

        fvxc.compute(vxcgrid, dgrid);

        auto grhoa = vxcgrid.xcGradientValues(xcvars::rhoa);

        auto ggrada = vxcgrid.xcGradientValues(xcvars::grada);

        auto ggradab = vxcgrid.xcGradientValues(xcvars::gradab);

        auto ngrada = dgrid.alphaDensityGradient(0);

        auto gradax = dgrid.alphaDensityGradientX(0);

        auto graday = dgrid.alphaDensityGradientY(0);

        auto gradaz = dgrid.alphaDensityGradientZ(0);

        // set up density gradient grid driver

        CDensityGradientGridDriver graddrv(_locComm);

        for (int32_t i = 0; i < natoms; i++)
        {
            auto gradgrid = graddrv.generate(rwDensityMatrix, molecule, basis, mgrid, fvxc.getFunctionalType(), idsAtomic[i]);

            // set up pointers to density gradient grid

            const auto gdenx = gradgrid.getComponent(0);

            const auto gdeny = gradgrid.getComponent(1);

            const auto gdenz = gradgrid.getComponent(2);

            // compute LDA contribution to molecular gradient

            double gatmx = 0.0;

            double gatmy = 0.0;

            double gatmz = 0.0;

            for (int32_t j = 0; j < gpoints; j++)
            {
                gatmx += gw[j] * grhoa[j] * gdenx[j];

                gatmy += gw[j] * grhoa[j] * gdeny[j];

                gatmz += gw[j] * grhoa[j] * gdenz[j];
            }

            // compute GGA contribution to molecular gradient

            if (fvxc.getFunctionalType() == xcfun::gga)
            {
                const auto gdenxx = gradgrid.getComponent(3);

                const auto gdenxy = gradgrid.getComponent(4);

                const auto gdenxz = gradgrid.getComponent(5);

                const auto gdenyx = gradgrid.getComponent(6);

                const auto gdenyy = gradgrid.getComponent(7);

                const auto gdenyz = gradgrid.getComponent(8);

                const auto gdenzx = gradgrid.getComponent(9);

                const auto gdenzy = gradgrid.getComponent(10);

                const auto gdenzz = gradgrid.getComponent(11);

                for (int32_t j = 0; j < gpoints; j++)
                {
                    double fgrd = gw[j] * (ggrada[j] / ngrada[j] + ggradab[j]);

                    gatmx += fgrd * (gradax[j] * gdenxx[j] + graday[j] * gdenxy[j] + gradaz[j] * gdenxz[j]);

                    gatmy += fgrd * (gradax[j] * gdenyx[j] + graday[j] * gdenyy[j] + gradaz[j] * gdenyz[j]);

                    gatmz += fgrd * (gradax[j] * gdenzx[j] + graday[j] * gdenzy[j] + gradaz[j] * gdenzz[j]);
                }
            }

            // factor of 2 from sum of alpha and beta contributions

            mgradx[i] = 2.0 * gatmx;

            mgrady[i] = 2.0 * gatmy;

            mgradz[i] = 2.0 * gatmz;
        }
    }
    else
    {
        // not implemented

        std::string erropenshell("XCMolecularGradient.integrateVxcGradient: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    // done with molecular gradient

    CDenseMatrix molgrad_T(natoms, 3);

    for (int32_t i = 0; i < natoms; i++)
    {
        for (int32_t d = 0; d < 3; d++)
        {
            molgrad_T.row(i)[d] = molgrad.row(d)[i];
        }
    }

    return molgrad_T;
}

CDenseMatrix
CXCMolecularGradient::integrateFxcGradient(const std::vector<int32_t>& idsAtomic,
                                           const CAODensityMatrix&     rwDensityMatrix1,
                                           const CAODensityMatrix&     rwDensityMatrix2,
                                           const CAODensityMatrix&     gsDensityMatrix,
                                           const CMolecule&            molecule,
                                           const CMolecularBasis&      basis,
                                           const CMolecularGrid&       molecularGrid,
                                           const std::string&          xcFuncLabel) const
{
    // parse exchange-correlation functional data

    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    // generate reference density grid

    CDensityGridDriver dgdrv(_locComm);

    auto refdengrid = dgdrv.generate(gsDensityMatrix, molecule, basis, molecularGrid, fvxc.getFunctionalType());

    // create molecular gradient

    const auto natoms = static_cast<int32_t>(idsAtomic.size());

    CDenseMatrix molgrad(3, natoms);

    auto mgradx = molgrad.row(0);

    auto mgrady = molgrad.row(1);

    auto mgradz = molgrad.row(2);

    if (rwDensityMatrix1.isClosedShell())
    {
        // generate screened molecular and density grids

        CMolecularGrid mgrid(molecularGrid);

        CDensityGrid gsdengrid;

        refdengrid.getScreenedGridsPair(gsdengrid, mgrid, 0, _thresholdOfDensity, fvxc.getFunctionalType());

        auto gw = mgrid.getWeights();

        const auto gpoints = mgrid.getNumberOfGridPoints();

        // allocate XC gradient grid

        CXCGradientGrid vxcgrid(mgrid.getNumberOfGridPoints(), gsdengrid.getDensityGridType(), fvxc.getFunctionalType());

        CXCHessianGrid vxc2grid(mgrid.getNumberOfGridPoints(), gsdengrid.getDensityGridType(), fvxc.getFunctionalType());

        // compute exchange-correlation functional first derrivatives

        fvxc.compute(vxcgrid, gsdengrid);

        fvxc.compute(vxc2grid, gsdengrid);

        auto rwdengrid = dgdrv.generate(rwDensityMatrix1, molecule, basis, mgrid, fvxc.getFunctionalType());

        // auto grhoa = vxcgrid.xcGradientValues(xcvars::rhoa);

        // auto ggrada = vxcgrid.xcGradientValues(xcvars::grada);

        // auto ggradab = vxcgrid.xcGradientValues(xcvars::gradab);

        auto grho_aa = vxc2grid.xcHessianValues(xcvars::rhoa, xcvars::rhoa);

        auto grho_ab = vxc2grid.xcHessianValues(xcvars::rhoa, xcvars::rhob);

        // auto ngrada = gsdengrid.alphaDensityGradient(0);

        // auto gradax = gsdengrid.alphaDensityGradientX(0);

        // auto graday = gsdengrid.alphaDensityGradientY(0);

        // auto gradaz = gsdengrid.alphaDensityGradientZ(0);

        auto rhowa = rwdengrid.alphaDensity(0);

        auto rhowb = rwdengrid.betaDensity(0);

        // set up density gradient grid driver

        CDensityGradientGridDriver graddrv(_locComm);

        for (int32_t i = 0; i < natoms; i++)
        {
            auto gradgrid = graddrv.generate(rwDensityMatrix2, molecule, basis, mgrid, fvxc.getFunctionalType(), idsAtomic[i]);

            // set up pointers to density gradient grid

            const auto gdenx = gradgrid.getComponent(0);

            const auto gdeny = gradgrid.getComponent(1);

            const auto gdenz = gradgrid.getComponent(2);

            // compute LDA contribution to molecular gradient

            double gatmx = 0.0;

            double gatmy = 0.0;

            double gatmz = 0.0;

            double gwlda;

            for (int32_t j = 0; j < gpoints; j++)
            {
                gwlda = gw[j] * (grho_aa[j] * rhowa[j] + grho_ab[j] * rhowb[j]);

                gatmx += gwlda * gdenx[j];

                gatmy += gwlda * gdeny[j];

                gatmz += gwlda * gdenz[j];
            }

            /* compute GGA contribution to molecular gradient

            if (fvxc.getFunctionalType() == xcfun::gga)
            {
                const auto gdenxx = gradgrid.getComponent(3);

                const auto gdenxy = gradgrid.getComponent(4);

                const auto gdenxz = gradgrid.getComponent(5);

                const auto gdenyx = gradgrid.getComponent(6);

                const auto gdenyy = gradgrid.getComponent(7);

                const auto gdenyz = gradgrid.getComponent(8);

                const auto gdenzx = gradgrid.getComponent(9);

                const auto gdenzy = gradgrid.getComponent(10);

                const auto gdenzz = gradgrid.getComponent(11);

                for (int32_t j = 0; j < gpoints; j++)
                {
                    double fgrd = gw[j] * (ggrada[j] / ngrada[j] + ggradab[j]);

                    gatmx += fgrd * (gradax[j] * gdenxx[j] + graday[j] * gdenxy[j] + gradaz[j] * gdenxz[j]);

                    gatmy += fgrd * (gradax[j] * gdenyx[j] + graday[j] * gdenyy[j] + gradaz[j] * gdenyz[j]);

                    gatmz += fgrd * (gradax[j] * gdenzx[j] + graday[j] * gdenzy[j] + gradaz[j] * gdenzz[j]);
                }
            }

            */

            // factor of 2 from sum of alpha and beta contributions

            mgradx[i] = 2.0 * gatmx;

            mgrady[i] = 2.0 * gatmy;

            mgradz[i] = 2.0 * gatmz;
        }
    }
    else
    {
        // not implemented

        std::string erropenshell("XCMolecularGradient.integrateFxcGradient: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    // done with molecular gradient

    CDenseMatrix molgrad_T(natoms, 3);

    for (int32_t i = 0; i < natoms; i++)
    {
        for (int32_t d = 0; d < 3; d++)
        {
            molgrad_T.row(i)[d] = molgrad.row(d)[i];
        }
    }

    return molgrad_T;
}

CDenseMatrix
CXCMolecularGradient::integrateGxcGradient(const std::vector<int32_t>& idsAtomic,
                                           const CAODensityMatrix&     rwDensityMatrix,
                                           const CAODensityMatrix&     rw2DensityMatrix,
                                           const CAODensityMatrix&     gsDensityMatrix,
                                           const CMolecule&            molecule,
                                           const CMolecularBasis&      basis,
                                           const CMolecularGrid&       molecularGrid,
                                           const std::string&          xcFuncLabel) const
{
    // parse exchange-correlation functional data

    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    // generate reference density grid

    CDensityGridDriver dgdrv(_locComm);

    auto refdengrid = dgdrv.generate(gsDensityMatrix, molecule, basis, molecularGrid, fvxc.getFunctionalType());

    // create molecular gradient

    const auto natoms = static_cast<int32_t>(idsAtomic.size());

    CDenseMatrix molgrad(3, natoms);

    auto mgradx = molgrad.row(0);

    auto mgrady = molgrad.row(1);

    auto mgradz = molgrad.row(2);

    if (rwDensityMatrix.isClosedShell())
    {
        // generate screened molecular and density grids

        CMolecularGrid mgrid(molecularGrid);

        CDensityGrid gsdengrid;

        refdengrid.getScreenedGridsPair(gsdengrid, mgrid, 0, _thresholdOfDensity, fvxc.getFunctionalType());

        auto gw = mgrid.getWeights();

        const auto gpoints = mgrid.getNumberOfGridPoints();

        // allocate XC gradient grid

        CXCGradientGrid vxcgrid(mgrid.getNumberOfGridPoints(), gsdengrid.getDensityGridType(), fvxc.getFunctionalType());

        CXCHessianGrid vxc2grid(mgrid.getNumberOfGridPoints(), gsdengrid.getDensityGridType(), fvxc.getFunctionalType());

        CXCCubicHessianGrid vxc3grid(mgrid.getNumberOfGridPoints(), gsdengrid.getDensityGridType(), fvxc.getFunctionalType());

        // compute exchange-correlation functional first derrivatives

        fvxc.compute(vxcgrid, gsdengrid);

        fvxc.compute(vxc2grid, gsdengrid);

        fvxc.compute(vxc3grid, gsdengrid);

        auto rwdengrid = dgdrv.generate(rwDensityMatrix, molecule, basis, mgrid, fvxc.getFunctionalType());

        auto rw2dengrid = dgdrv.generate(rw2DensityMatrix, molecule, basis, mgrid, fvxc.getFunctionalType());

        auto rwdengridc =
            CDensityGridQuad(mgrid.getNumberOfGridPoints(), rw2DensityMatrix.getNumberOfDensityMatrices(), fvxc.getFunctionalType(), dengrid::ab);

        // Compute all and store all products of first-order transformed denisites

        rwdengridc.DensityProd(rwdengridc, mgrid, rwdengrid, fvxc.getFunctionalType(), rw2DensityMatrix.getNumberOfDensityMatrices(), "QRF");

        // auto grhoa = vxcgrid.xcGradientValues(xcvars::rhoa);

        // auto ggrada = vxcgrid.xcGradientValues(xcvars::grada);

        // auto ggradab = vxcgrid.xcGradientValues(xcvars::gradab);

        // auto grho_aa = vxc2grid.xcHessianValues(xcvars::rhoa, xcvars::rhoa);

        // auto grho_ab = vxc2grid.xcHessianValues(xcvars::rhoa, xcvars::rhob);

        auto grho_aaa = vxc3grid.xcCubicHessianValues(xcvars::rhoa, xcvars::rhoa, xcvars::rhoa);

        auto grho_aab = vxc3grid.xcCubicHessianValues(xcvars::rhoa, xcvars::rhoa, xcvars::rhob);

        auto grho_abb = vxc3grid.xcCubicHessianValues(xcvars::rhoa, xcvars::rhob, xcvars::rhob);

        // auto ngrada = gsdengrid.alphaDensityGradient(0);

        // auto gradax = gsdengrid.alphaDensityGradientX(0);

        // auto graday = gsdengrid.alphaDensityGradientY(0);

        // auto gradaz = gsdengrid.alphaDensityGradientZ(0);

        // auto rhowa = rwdengrid.alphaDensity(0);

        // auto rhowb = rwdengrid.betaDensity(0);

        auto rhow1a = rwdengridc.rhow1rhow2(0);

        // set up density gradient grid driver

        CDensityGradientGridDriver graddrv(_locComm);

        for (int32_t i = 0; i < natoms; i++)
        {
            auto gradgrid = graddrv.generate(gsDensityMatrix, molecule, basis, mgrid, fvxc.getFunctionalType(), idsAtomic[i]);

            // set up pointers to density gradient grid

            const auto gdenx = gradgrid.getComponent(0);

            const auto gdeny = gradgrid.getComponent(1);

            const auto gdenz = gradgrid.getComponent(2);

            // compute LDA contribution to molecular gradient

            double gatmx = 0.0;

            double gatmy = 0.0;

            double gatmz = 0.0;

            double gwlda;

            for (int32_t j = 0; j < gpoints; j++)
            {
                gwlda = gw[j] * (grho_aaa[j] + grho_aab[j] + grho_aab[j] + grho_abb[j]) * rhow1a[j];

                gatmx += gwlda * gdenx[j];

                gatmy += gwlda * gdeny[j];

                gatmz += gwlda * gdenz[j];
            }

            /* compute GGA contribution to molecular gradient

            if (fvxc.getFunctionalType() == xcfun::gga)
            {
                const auto gdenxx = gradgrid.getComponent(3);

                const auto gdenxy = gradgrid.getComponent(4);

                const auto gdenxz = gradgrid.getComponent(5);

                const auto gdenyx = gradgrid.getComponent(6);

                const auto gdenyy = gradgrid.getComponent(7);

                const auto gdenyz = gradgrid.getComponent(8);

                const auto gdenzx = gradgrid.getComponent(9);

                const auto gdenzy = gradgrid.getComponent(10);

                const auto gdenzz = gradgrid.getComponent(11);

                for (int32_t j = 0; j < gpoints; j++)
                {
                    double fgrd = gw[j] * (ggrada[j] / ngrada[j] + ggradab[j]);

                    gatmx += fgrd * (gradax[j] * gdenxx[j] + graday[j] * gdenxy[j] + gradaz[j] * gdenxz[j]);

                    gatmy += fgrd * (gradax[j] * gdenyx[j] + graday[j] * gdenyy[j] + gradaz[j] * gdenyz[j]);

                    gatmz += fgrd * (gradax[j] * gdenzx[j] + graday[j] * gdenzy[j] + gradaz[j] * gdenzz[j]);
                }
            }

            */

            // factor of 2 from sum of alpha and beta contributions

            mgradx[i] = 2.0 * gatmx;

            mgrady[i] = 2.0 * gatmy;

            mgradz[i] = 2.0 * gatmz;
        }
    }
    else
    {
        // not implemented

        std::string erropenshell("XCMolecularGradient.integrateGxcGradient: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    // done with molecular gradient

    CDenseMatrix molgrad_T(natoms, 3);

    for (int32_t i = 0; i < natoms; i++)
    {
        for (int32_t d = 0; d < 3; d++)
        {
            molgrad_T.row(i)[d] = molgrad.row(d)[i];
        }
    }

    return molgrad_T;
}
