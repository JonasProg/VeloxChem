//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "VisualizationDriverTest.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#include "VisualizationDriver.hpp"
#include "MathConst.hpp"
#include "MoleculeSetter.hpp"
#include "MolecularBasisSetter.hpp"
#include "MolecularOrbitals.hpp"
#include "AODensityMatrix.hpp"

TEST_F(CVisualizationDriverTest, Helium)
{
    // predefined variables

    double mocoef = 0.5;

    double xp = 0.1;

    double yp = 0.2;

    double zp = 0.3;

    // molecular orbital

    CDenseMatrix ma({mocoef}, 1, 1);
    
    std::vector<double> ea({0.1});
    
    CMolecularOrbitals moa({ma}, {ea}, molorb::rest);

    // psi from manual calculation

    std::vector<double> expons ({3.836000000000e+01, 5.770000000000e+00,
                                 1.240000000000e+00, 2.976000000000e-01});

    std::vector<double> coefs  ({2.380900000000e-02, 1.548910000000e-01,
                                 4.699870000000e-01, 5.130270000000e-01});

    for (size_t i = 0; i < expons.size(); i++)
    {
        double normfac = std::pow(2.0 * expons[i] / mathconst::getPiValue(), 0.75);

        coefs[i] *= normfac;
    }

    double ovl = 0.0;

    for (size_t i = 0; i < expons.size(); i++)
    {
        double ci = coefs[i];

        double ei = expons[i];

        for (size_t j = i; j < expons.size(); j++)
        {
            double cij = ci * coefs[j];

            double eij = ei + expons[j];

            double f = (j == i) ? 1.0 : 2.0;

            ovl += f * cij * std::pow(mathconst::getPiValue() / eij, 1.5);
        }
    }

    ovl = 1.0 / std::sqrt(ovl);

    for (size_t i = 0; i < expons.size(); i++)
    {
        coefs[i] *= ovl;
    }

    double r2 = xp * xp + yp * yp + zp * zp;

    double mypsi = 0.0;

    for (size_t i = 0; i < expons.size(); i++)
    {
        mypsi += mocoef * coefs[i] * std::exp(-expons[i] * r2);
    }

    // psi from getPsiMolecularOrbital

    auto mol = vlxmol::getMoleculeHeAtom();
    
    auto basis = vlxbas::getMinimalBasisForHeAtom();

    CVisualizationDriver visdrv;

    auto psi = visdrv.compute(mol, basis, moa, 0, "a", xp, yp, zp);

    ASSERT_NEAR(mypsi, psi, 1.0e-13);

    // density matrix

    CDenseMatrix da({mocoef * mocoef}, 1, 1);
    
    CAODensityMatrix dena({da}, denmat::rest);

    auto psi2 = visdrv.compute(mol, basis, dena, 0, "a", xp, yp, zp);

    ASSERT_NEAR(psi*psi, psi2, 1.0e-13);
}
