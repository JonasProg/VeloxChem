//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "OverlapMatrixTest.hpp"

#include "OverlapMatrix.hpp"

TEST_F(COverlapMatrixTest, DefaultConstructor)
{
    COverlapMatrix smata;
    
    COverlapMatrix smatb(CSparseMatrix(0, 0, 1.0e-13));
    
    ASSERT_EQ(smata, smatb);
}

TEST_F(COverlapMatrixTest, CopyConstructor)
{
    CSparseMatrix ma({1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0,
                      8.0, -5.0}, {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4},
                     {0, 1, 2, 0, 1, 2, 3, 4, 9, 2, 3, 1, 4}, 5, 5, 1.0e-13);
    
    COverlapMatrix smata(ma);
    
    COverlapMatrix smatb(smata);
    
    ASSERT_EQ(smata, smatb);
}

TEST_F(COverlapMatrixTest, MoveConstructor)
{
    CSparseMatrix ma({1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0,
                      8.0, -5.0}, {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4},
                     {0, 1, 2, 0, 1, 2, 3, 4, 9, 2, 3, 1, 4}, 5, 5, 1.0e-13);
    
    COverlapMatrix smata(ma);
    
    COverlapMatrix smatb(COverlapMatrix({ma}));
    
    ASSERT_EQ(smata, smatb);
}

TEST_F(COverlapMatrixTest, CopyAssignment)
{
    CSparseMatrix ma({1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0,
                      8.0, -5.0}, {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4},
                     {0, 1, 2, 0, 1, 2, 3, 4, 9, 2, 3, 1, 4}, 5, 5, 1.0e-13);
    
    COverlapMatrix smata(ma);
    
    COverlapMatrix smatb = smata;
    
    ASSERT_EQ(smata, smatb);
}

TEST_F(COverlapMatrixTest, MoveAssignment)
{
    CSparseMatrix ma({1.0, -1.0, -3.0, -2.0, 5.0, 4.0, 6.0, 4.0, -4.0, 2.0, 7.0,
                      8.0, -5.0}, {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4},
                     {0, 1, 2, 0, 1, 2, 3, 4, 9, 2, 3, 1, 4}, 5, 5, 1.0e-13);
    
    COverlapMatrix smata(ma);
    
    COverlapMatrix smatb(COverlapMatrix({ma}));
    
    ASSERT_EQ(smata, smatb);
}
