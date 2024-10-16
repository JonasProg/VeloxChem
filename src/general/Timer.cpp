//
//                              VELOXCHEM
//         ----------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2024 by VeloxChem developers. All rights reserved.
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

#include "Timer.hpp"

#include <iomanip>
#include <sstream>

CTimer::CTimer()
{
    reset();
}

void
CTimer::reset()
{
#ifndef _MSC_VER
    auto t0 = std::chrono::steady_clock::now();

    _duration = t0 - t0;
#else
    _duration = 0.0;
#endif

    _started = false;
}

void
CTimer::start()
{
    if (!_started)
    {
#ifndef _MSC_VER
        _startTime = std::chrono::steady_clock::now();
#else
        _startTime = 0.0;
#endif

        _started = true;
    }
}

void
CTimer::stop()
{
    if (_started)
    {
#ifndef _MSC_VER
        _duration += std::chrono::steady_clock::now() - _startTime;
#endif

        _started = false;
    }
}

std::string
CTimer::getElapsedTime() const
{
    std::stringstream ss;

#ifndef _MSC_VER
    auto duration_double = std::chrono::duration_cast<std::chrono::duration<double>>(_duration);

    ss << std::fixed << std::setw(15) << std::setprecision(3) << duration_double.count() << " sec";
#else
    ss << "         N/A";
#endif

    return ss.str();
}
