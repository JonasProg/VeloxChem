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

#include "FourIndexesTest.hpp"

#include "FourIndexes.hpp"

TEST_F(CFourIndexesTest, DefaultConstructor)
{
    CFourIndexes ida(-1, -1, -1, -1);

    CFourIndexes idb;

    ASSERT_EQ(ida, idb);
}

TEST_F(CFourIndexesTest, CopyConstructor)
{
    CFourIndexes ida(2, 7, 3, 4);

    CFourIndexes idb(ida);

    ASSERT_EQ(ida, idb);
}

TEST_F(CFourIndexesTest, MoveConstructor)
{
    CFourIndexes ida(2, 7, 3, 4);

    CFourIndexes idb(CFourIndexes(2, 7, 3, 4));

    ASSERT_EQ(ida, idb);
}

TEST_F(CFourIndexesTest, CopyAssignment)
{
    CFourIndexes ida(2, 7, 3, 8);

    CFourIndexes idb = ida;

    ASSERT_EQ(ida, idb);
}

TEST_F(CFourIndexesTest, MoveAssignment)
{
    CFourIndexes ida(2, 7, 3, 1);

    CFourIndexes idb = CFourIndexes(2, 7, 3, 1);

    ASSERT_EQ(ida, idb);
}

TEST_F(CFourIndexesTest, Shift)
{
    CFourIndexes ida(2, 7, 0, 3);

    ida.shift(2, 0);

    ASSERT_EQ(ida, CFourIndexes(4, 7, 0, 3));

    ida.shift(-2, 1);

    ASSERT_EQ(ida, CFourIndexes(4, 5, 0, 3));

    ida.shift(3, 2);

    ASSERT_EQ(ida, CFourIndexes(4, 5, 3, 3));

    ida.shift(2, 3);

    ASSERT_EQ(ida, CFourIndexes(4, 5, 3, 5));

    ida.shift(2, -1);

    ASSERT_EQ(ida, CFourIndexes(4, 5, 3, 5));

    ida.shift(2, 4);

    ASSERT_EQ(ida, CFourIndexes(4, 5, 3, 5));
}

TEST_F(CFourIndexesTest, First)
{
    CFourIndexes ida(2, 7, 1, 3);

    ASSERT_EQ(2, ida.first());

    CFourIndexes idb(3, 2, 4, 7);

    ASSERT_EQ(3, idb.first());
}

TEST_F(CFourIndexesTest, Second)
{
    CFourIndexes ida(2, 7, 1, 3);

    ASSERT_EQ(7, ida.second());

    CFourIndexes idb(3, 2, 4, 7);

    ASSERT_EQ(2, idb.second());
}

TEST_F(CFourIndexesTest, Third)
{
    CFourIndexes ida(2, 7, 1, 3);

    ASSERT_EQ(1, ida.third());

    CFourIndexes idb(3, 2, 4, 7);

    ASSERT_EQ(4, idb.third());
}

TEST_F(CFourIndexesTest, Fourth)
{
    CFourIndexes ida(2, 7, 1, 3);

    ASSERT_EQ(3, ida.fourth());

    CFourIndexes idb(3, 2, 4, 7);

    ASSERT_EQ(7, idb.fourth());
}

TEST_F(CFourIndexesTest, IsValidQuadruple)
{
    CFourIndexes ida(2, 7, 0, 3);

    ASSERT_TRUE(ida.isValidQuadruple());

    CFourIndexes idb(3, -3, 1, 0);

    ASSERT_FALSE(idb.isValidQuadruple());

    CFourIndexes idc(-3, 0, 1, 2);

    ASSERT_FALSE(idc.isValidQuadruple());

    CFourIndexes idd(3, 0, -1, 2);

    ASSERT_FALSE(idd.isValidQuadruple());

    CFourIndexes ide(3, 0, 1, -2);

    ASSERT_FALSE(ide.isValidQuadruple());

    CFourIndexes idf(0, 0, 0, 0);

    ASSERT_TRUE(idf.isValidQuadruple());
}

TEST_F(CFourIndexesTest, Value)
{
    CFourIndexes ida(2, 7, 0, 3);

    ASSERT_EQ(2, ida.value(0));

    ASSERT_EQ(7, ida.value(1));

    ASSERT_EQ(0, ida.value(2));

    ASSERT_EQ(3, ida.value(3));

    ASSERT_EQ(-1, ida.value(-2));

    ASSERT_EQ(-1, ida.value(4));
}
