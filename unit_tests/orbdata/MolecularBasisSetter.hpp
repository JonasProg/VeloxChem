//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#ifndef MolecularBasisSetter_hpp
#define MolecularBasisSetter_hpp

#include "MolecularBasis.hpp"

namespace vlxbas {  // vlxbas namespace

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

}  // namespace vlxbas

#endif /* MolecularBasisSetter_hpp */
