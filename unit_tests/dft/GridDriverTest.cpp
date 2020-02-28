//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "GridDriverTest.hpp"

#include <cmath>

#include "GridDriver.hpp"
#include "MathConst.hpp"
#include "MoleculeSetter.hpp"
#include "MpiFunc.hpp"

TEST_F(CGridDriverTest, DefaultConstructor)
{
    CGridDriver gdrv(MPI_COMM_WORLD);

    gdrv.setLevel(6);

    auto mlih = vlxmol::getMoleculeLiH();

    auto mgrid = gdrv.generate(mlih);

    auto npnt = mgrid.getNumberOfGridPoints();

    EXPECT_EQ(741140, npnt);

    auto rx = mgrid.getCoordinatesX();

    auto ry = mgrid.getCoordinatesY();

    auto rz = mgrid.getCoordinatesZ();

    auto w = mgrid.getWeights();

    double fa = 0.0;

    double fb = 0.0;

    double fab = 0.0;

    for (int32_t i = 0; i < npnt; i++)
    {
        auto r2a = rx[i] * rx[i] + ry[i] * ry[i] + rz[i] * rz[i];

        fa += w[i] * std::exp(-2.3 * r2a);

        auto r2b = rx[i] * rx[i] + ry[i] * ry[i]

                   + (rz[i] - 1.20) * (rz[i] - 1.20);

        fb += w[i] * std::exp(-0.5 * r2b);

        fab += w[i] * std::exp(-2.3 * r2a) * std::exp(-0.5 * r2b);
    }

    EXPECT_NEAR(fa, 1.5963681525241624, 1.0e-10);

    EXPECT_NEAR(fb, 15.749609945385632, 1.0e-10);

    EXPECT_NEAR(fab, 0.65786017622805693, 1.0e-10);
}
