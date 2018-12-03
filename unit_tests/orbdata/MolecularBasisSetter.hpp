//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#ifndef MolecularBasisSetter_hpp
#define MolecularBasisSetter_hpp

#include "MolecularBasis.hpp"

namespace vlxbas { // vlxbas namespace
    
CMolecularBasis getMolecularBasisEmpty();

CMolecularBasis getMolecularBasisForLiH();
    
CMolecularBasis getMolecularBasisForLiHX();
    
CMolecularBasis getMolecularBasisForHeAtom();
    
CMolecularBasis getMolecularBasisSPDForHeAtom();

CMolecularBasis getMolecularBasisForH2O();

CMolecularBasis getMolecularBasisForH2Se();

CMolecularBasis getMinimalBasisForHeAtom();

CMolecularBasis getMinimalBasisForH2O();

CMolecularBasis getMinimalBasisForNH3CH4();
    
CMolecularBasis getTestBasisForLiH();
    
CMolecularBasis getReducedTestBasisForLiH();
    
CMolecularBasis getGenContrBasisForLiH();

} // vlxbas namespace

#endif /* MolecularBasisSetter_hpp */
