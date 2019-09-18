//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef DeviceFunc_hpp
#define DeviceFunc_hpp

#include <cstdint>

namespace gpu {

/**
 Sets up requested  CUDA compute capable device.

 @param iDevice the identifier of CUDA compute capable device.
 */
void setDevice(const int32_t iDevice);
}

#endif
