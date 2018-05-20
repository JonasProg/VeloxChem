//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef MatOrder_hpp
#define MatOrder_hpp

/**
 Enumerate class matorder:
 
 Defines all allowed key values for matrix data ordering in memory:
 matorder::col_major - the column major ordering of data
 matorder::row_major - the row major ordering of data
 */

enum class matorder : int32_t
{
    col_major,
    row_major
};


#endif /* MatOrder_hpp */
