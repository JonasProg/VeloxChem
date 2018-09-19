//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "MathConstTest.hpp"

#include "MathConst.hpp"

TEST_F(CMathConstTest, GetPiValue)
{
    ASSERT_NEAR(3.14159265358979323846, mathconst::getPiValue(), 1.0e-13);
}
