//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "TwoIndexesTest.hpp"

#include "TwoIndexes.hpp"

TEST_F(CTwoIndexesTest, DefaultConstructor)
{
    CTwoIndexes ida(-1, -1);

    CTwoIndexes idb;

    ASSERT_EQ(ida, idb);
}

TEST_F(CTwoIndexesTest, CopyConstructor)
{
    CTwoIndexes ida(2, 7);

    CTwoIndexes idb(ida);

    ASSERT_EQ(ida, idb);
}

TEST_F(CTwoIndexesTest, MoveConstructor)
{
    CTwoIndexes ida(2, 7);

    CTwoIndexes idb(CTwoIndexes(2, 7));

    ASSERT_EQ(ida, idb);
}

TEST_F(CTwoIndexesTest, CopyAssignment)
{
    CTwoIndexes ida(2, 7);

    CTwoIndexes idb = ida;

    ASSERT_EQ(ida, idb);
}

TEST_F(CTwoIndexesTest, MoveAssignment)
{
    CTwoIndexes ida(2, 7);

    CTwoIndexes idb = CTwoIndexes(2, 7);

    ASSERT_EQ(ida, idb);
}


TEST_F(CTwoIndexesTest, First)
{
    CTwoIndexes ida(2, 7);

    ASSERT_EQ(2, ida.first());

    CTwoIndexes idb(3, 3);

    ASSERT_EQ(3, idb.first());
}

TEST_F(CTwoIndexesTest, Second)
{
    CTwoIndexes ida(2, 7);

    ASSERT_EQ(7, ida.second());

    CTwoIndexes idb(3, 3);

    ASSERT_EQ(3, idb.second());
}
