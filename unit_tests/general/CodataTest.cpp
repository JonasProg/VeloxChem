//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "CodataTest.hpp"

#include "Codata.hpp"

TEST_F(CCodataTest, GetBohrValueInAngstroms)
{
    ASSERT_NEAR(0.52917721092, units::getBohrValueInAngstroms(), 1.0e-13);
}

TEST_F(CCodataTest, GetHartreeValueInElectronVolts)
{
    ASSERT_NEAR(27.21138505, units::getHartreeValueInElectronVolts(), 1.0e-13);
}
