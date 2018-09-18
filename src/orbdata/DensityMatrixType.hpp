//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef DensityMatrixType_hpp
#define DensityMatrixType_hpp

#include <string>

/**
 Enumerate class denmat:
 
 Defines supported density matrix types:
 denmat::rest   - the restricted density matrix
 denmat::unrest - the unrestricted density matrix
 */
enum class denmat
{
    rest,
    unrest
};

/**
 Converts enumerate class value to it's string label.
 
 @param denMatrix the enumerate class value.
 @return the label of enumerate class value.
 */
inline std::string to_string(const denmat denMatrix)
{
    if (denMatrix == denmat::rest)
    {
        return std::string("Restricted Density Matrix");
    }
    
    if (denMatrix == denmat::unrest)
    {
        return std::string("Unrestricted Density Matrix");
    }
   
    return std::string("UNKNOWN");
}

#endif /* DensityMatrixType_hpp */
