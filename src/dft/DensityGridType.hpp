//
//                           VELOXCHEM 1.0-RC
//         ----------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact
//
//  SPDX-License-Identifier: LGPL-3.0-or-later
//
//  This file is part of VeloxChem.
//
//  VeloxChem is free software: you can redistribute it and/or modify it under
//  the terms of the GNU Lesser General Public License as published by the Free
//  Software Foundation, either version 3 of the License, or (at your option)
//  any later version.
//
//  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
//  License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

#ifndef DensityGridType_hpp
#define DensityGridType_hpp

#include <string>
#include "StringFormat.hpp"

/**
 Enumerate class dengrid:
 
 Defines supported density grid type keys:
 dengrid::ab        - the rho_alpha, rho_beta density grid
 dengrid::lima      - the lim rho_alpha -> 0 density grid
 dengrid::limb      - the lim rho_beta -> 0 density grid
 dengrid::undefined - thr undefined density grid
 */
enum class dengrid
{
    ab, lima, limb, undefined
};

/**
 Converts enumerate class value to its string label.
 
 @param key the enumerate class value.
 @return the label of enumerate class value.
 */
inline std::string
to_string(const dengrid key)
{
    if (key == dengrid::ab) return std::string("AB");
    
    if (key == dengrid::lima) return std::string("LIM_A");
    
    if (key == dengrid::limb) return std::string("LIM_B");
    
    return std::string("UNKNOWN");
}

/**
 Converts string label to its enumerate class value.
 
 @param label the label of enumerate class value.
 @return functional the enumerate class value.
 */
inline dengrid
to_dengrid(const std::string label)
{
    if (fstr::upcase(label) == "AB")  return dengrid::ab;
    
    if (fstr::upcase(label) == "LIMA")  return dengrid::lima;
    
    if (fstr::upcase(label) == "LIMB") return dengrid::limb;
    
    return dengrid::undefined;
}

#endif /* DensityGridType_hpp */
