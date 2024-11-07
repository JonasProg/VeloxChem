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

#include "CubicGrid.hpp"

#include <cstring>
#include <string>
#include <vector>

#include "ErrorHandler.hpp"

CCubicGrid::CCubicGrid()

    : _origin{0.0, 0.0, 0.0}

    , _stepSize{0.0, 0.0, 0.0}

    , _numPoints{0, 0, 0}

    , _values{std::vector<double>()}
{
}

CCubicGrid::CCubicGrid(const std::array<double, 3>& origin, const std::array<double, 3>& stepSize, const std::array<int, 3>& numPoints)

    : _origin(origin)

    , _stepSize(stepSize)

    , _numPoints(numPoints)
{
    std::string errmsg("CubicGrid: Incorrect dimension");

    errors::assertMsgCritical(_origin.size() == 3, errmsg);

    errors::assertMsgCritical(_stepSize.size() == 3, errmsg);

    errors::assertMsgCritical(_numPoints.size() == 3, errmsg);

    _values = std::vector<double>(numPoints[0] * numPoints[1] * numPoints[2]);
}

CCubicGrid::CCubicGrid(const CCubicGrid& source)

    : _origin(source._origin)

    , _stepSize(source._stepSize)

    , _numPoints(source._numPoints)

    , _values(source._values)
{
}

CCubicGrid::CCubicGrid(CCubicGrid&& source) noexcept

    : _origin(std::move(source._origin))

    , _stepSize(std::move(source._stepSize))

    , _numPoints(std::move(source._numPoints))

    , _values(std::move(source._values))
{
}

CCubicGrid::~CCubicGrid()
{
}

CCubicGrid&
CCubicGrid::operator=(const CCubicGrid& source)
{
    if (this == &source) return *this;

    _origin = source._origin;

    _stepSize = source._stepSize;

    _numPoints = source._numPoints;

    _values = source._values;

    return *this;
}

CCubicGrid&
CCubicGrid::operator=(CCubicGrid&& source) noexcept
{
    if (this == &source) return *this;

    _origin = std::move(source._origin);

    _stepSize = std::move(source._stepSize);

    _numPoints = std::move(source._numPoints);

    _values = std::move(source._values);

    return *this;
}

bool
CCubicGrid::operator==(const CCubicGrid& other) const
{
    if (_origin != other._origin) return false;

    if (_stepSize != other._stepSize) return false;

    if (_numPoints != other._numPoints) return false;

    if (_values != other._values) return false;

    return true;
}

bool
CCubicGrid::operator!=(const CCubicGrid& other) const
{
    return !(*this == other);
}

std::array<double, 3>
CCubicGrid::getOrigin() const
{
    return _origin;
}

std::array<double, 3>
CCubicGrid::getStepSize() const
{
    return _stepSize;
}

std::array<int, 3>
CCubicGrid::getNumPoints() const
{
    return _numPoints;
}

const double*
CCubicGrid::values() const
{
    return _values.data();
}

double*
CCubicGrid::values()
{
    return _values.data();
}

void
CCubicGrid::setValues(const std::vector<double> vals)
{
    std::string errmsg("CubicGrid.set_values: Inconsistent number of grid points");

    auto npoints = _numPoints[0] * _numPoints[1] * _numPoints[2];

    errors::assertMsgCritical(npoints == static_cast<int>(vals.size()), errmsg);

    std::memcpy(_values.data(), vals.data(), npoints * sizeof(double));
}
