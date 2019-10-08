//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "DeviceProp.hpp"
 
#include <cmath>
#include <sstream>
#include <string>

#include "StringFormat.hpp"

namespace gpu {  // gpu namespace

void
get_devices_property(std::vector<std::string>& namesOfDevices,
                    std::vector<int32_t>&     globalMemoryOfDevices,
                    std::vector<int32_t>&     computeMajorCapabilityOfDevices,
                    std::vector<int32_t>&     computeMinorCapabilityOfDevices)
{
#ifdef ENABLE_GPU

    int devcnt = 0;

    cudaGetDeviceCount(&devcnt);

    for (int i = 0; i < devcnt; i++)
    {
        cudaDeviceProp prop;

        cudaGetDeviceProperties(&prop, i);

        // NOTE: compute capability below 3.0 is not supported

        if (prop.major < 3) return;

        namesOfDevices.push_back(std::string(prop.name));

        auto globalMemInMB = prop.totalGlobalMem / (1024u * 1024u);

        globalMemoryOfDevices.push_back(static_cast<int32_t>(globalMemInMB));

        computeMajorCapabilityOfDevices.push_back(static_cast<int32_t>(prop.major));

        computeMinorCapabilityOfDevices.push_back(static_cast<int32_t>(prop.minor));
    }
#endif
}

}  // namespace gpu
