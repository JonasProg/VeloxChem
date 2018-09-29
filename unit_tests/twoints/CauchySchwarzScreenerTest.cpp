//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "CauchySchwarzScreenerTest.hpp"

#include "CauchySchwarzScreener.hpp"
#include "GtoBlock.hpp"
#include "GtoPairsBlock.hpp"
#include "MoleculeSetter.hpp"
#include "MolecularBasisSetter.hpp"
#include "CheckFunctions.hpp"

TEST_F(CCauchySchwarzScreenerTest, DefaultConstructor)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CMemBlock<double> bqvals;
    
    CCauchySchwarzScreener qscra;
    
    CCauchySchwarzScreener qscrb(bqvals, bqvals, bpairs, bpairs, ericut::qq,
                                 1.0e-13);
    
    ASSERT_EQ(qscra, qscrb);
}

TEST_F(CCauchySchwarzScreenerTest, CopyConstructor)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    CCauchySchwarzScreener qscrb(qscra);
    
    ASSERT_EQ(qscra, qscrb);
}

TEST_F(CCauchySchwarzScreenerTest, MoveConstructor)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    CCauchySchwarzScreener qscrb(CCauchySchwarzScreener(bqvals, kqvals, bpairs,
                                                        kpairs, ericut::qq,
                                                        1.0e-13));
    
    ASSERT_EQ(qscra, qscrb);
}

TEST_F(CCauchySchwarzScreenerTest, CopyAssignment)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    CCauchySchwarzScreener qscrb = qscra;
    
    ASSERT_EQ(qscra, qscrb);
}

TEST_F(CCauchySchwarzScreenerTest, MoveAssignment)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    CCauchySchwarzScreener qscrb = CCauchySchwarzScreener(bqvals, kqvals, bpairs,
                                                          kpairs, ericut::qq,
                                                          1.0e-13);
    
    ASSERT_EQ(qscra, qscrb);
}

TEST_F(CCauchySchwarzScreenerTest, SetAndGetScreeningScheme)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CMemBlock<double> bqvals;
    
    CCauchySchwarzScreener qscra(bqvals, bqvals, bpairs, bpairs, ericut::qq,
                                 3.0e-11);
    
    ASSERT_EQ(qscra.getScreeningScheme(), ericut::qq);
    
    qscra.setScreeningScheme(ericut::qqr);
    
    ASSERT_EQ(qscra.getScreeningScheme(), ericut::qqr);
}

TEST_F(CCauchySchwarzScreenerTest, SetAndGetThreshold)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CMemBlock<double> bqvals;
    
    CCauchySchwarzScreener qscra(bqvals, bqvals, bpairs, bpairs, ericut::qq,
                                 3.0e-11);
    
    ASSERT_NEAR(qscra.getThreshold(), 3.0e-11, 1.0e-13);
    
    qscra.setThreshold(0.079); 
    
    ASSERT_NEAR(qscra.getThreshold(), 0.079, 1.0e-13);
}

TEST_F(CCauchySchwarzScreenerTest, GetBraQValues)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    vlxtest::compare({1.0, 2.0, 3.0, 4.0}, qscra.getBraQValues());
}

TEST_F(CCauchySchwarzScreenerTest, GetKetQValues)
{
    auto mlih = vlxmol::getTestLiH();
    
    auto mbas = vlxbas::getTestBasisForLiH();
    
    CGtoBlock bgtos(mlih, mbas, 0);
    
    CGtoBlock kgtos(mlih, mbas, 1);
    
    CGtoPairsBlock bpairs(bgtos, kgtos, 1.0e-13);
    
    CGtoPairsBlock kpairs(bgtos, 1.0e-13);
    
    CMemBlock<double> bqvals({1.0, 2.0, 3.0, 4.0});
    
    CMemBlock<double> kqvals({0.0, 1.0, 2.0, 7.0, 7.0, 2.0});
    
    CCauchySchwarzScreener qscra(bqvals, kqvals, bpairs, kpairs, ericut::qq,
                                 1.0e-13);
    
    vlxtest::compare({0.0, 1.0, 2.0, 7.0, 7.0, 2.0}, qscra.getKetQValues());
}
