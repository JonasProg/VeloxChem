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

#include "ErrorHandler.hpp"

namespace gpu {

/**
 Sets up context of requested  CUDA compute capable device.

 @param iDevice the identifier of CUDA compute capable device.
 */
void set_device(const int32_t iDevice);
    
/**
 Synchronizes CUDA compute capable device.
*/
void synchronize_device();
    
/**
 Allocates CUDA compute device memory.

 @param pointer the pointer to device memory.
 @param dataPitch the pointer  to pitch of device memory.
 @param dataWidth the width of data.
 @param dataHeight the height  of data.
 */
void allocate_device_memory(void**  pointer,
                            size_t* dataPitch,
                            size_t  dataWidth,
                            size_t  dataHeight);

/**
 Frees CUDA compute device memory.

 @param pointer the pointer to device memory.
 */
void free_device_memory(void* pointer);

/**
 Copies 2D data from host memory to device memory.

 @param destination the pointer to device memory.
 @param destinationPitch the pitch of device memory.
 @param source the pointer to host memory.
 @param sourcePitch the pitch of host memory.
 @param dataWidth the width of data.
 @param dataHeight the height of data.
 */
void copy_to_device_memory(      void*  destination,
                                 size_t destinationPitch,
                           const void*  source,
                                 size_t sourcePitch,
                                 size_t dataWidth,
                                 size_t dataHeight);

/**
 Copies 2D data from device memory to host memory.

 @param destination the pointer to host memory.
 @param destinationPitch the pitch of host memory.
 @param source the pointer to device memory.
 @param sourcePitch the pitch of device memory.
 @param dataWidth the width of data.
 @param dataHeight the height of data.
 */
void copy_from_device_memory(      void* destination,
                                 size_t  destinationPitch,
                             const void* source,
                                 size_t  sourcePitch,
                                 size_t  dataWidth,
                                 size_t  dataHeight);
}

#endif
