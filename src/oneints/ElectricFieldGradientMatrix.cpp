//
//                           VELOXCHEM 1.0-RC2
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

#include "ElectricFieldGradientMatrix.hpp"

CElectricFieldGradientMatrix::CElectricFieldGradientMatrix()
{
}

CElectricFieldGradientMatrix::CElectricFieldGradientMatrix(const CDenseMatrix& xxMatrix,
                                                           const CDenseMatrix& xyMatrix,
                                                           const CDenseMatrix& xzMatrix,
                                                           const CDenseMatrix& yyMatrix,
                                                           const CDenseMatrix& yzMatrix,
                                                           const CDenseMatrix& zzMatrix)

    : _xxMatrix(xxMatrix)

    , _xyMatrix(xyMatrix)

    , _xzMatrix(xzMatrix)

    , _yyMatrix(yyMatrix)

    , _yzMatrix(yzMatrix)

    , _zzMatrix(zzMatrix)
{
}

CElectricFieldGradientMatrix::CElectricFieldGradientMatrix(const CElectricFieldGradientMatrix& source)

    : _xxMatrix(source._xxMatrix)

    , _xyMatrix(source._xyMatrix)

    , _xzMatrix(source._xzMatrix)

    , _yyMatrix(source._yyMatrix)

    , _yzMatrix(source._yzMatrix)

    , _zzMatrix(source._zzMatrix)
{
}

CElectricFieldGradientMatrix::CElectricFieldGradientMatrix(CElectricFieldGradientMatrix&& source) noexcept

    : _xxMatrix(std::move(source._xxMatrix))

    , _xyMatrix(std::move(source._xyMatrix))

    , _xzMatrix(std::move(source._xzMatrix))

    , _yyMatrix(std::move(source._yyMatrix))

    , _yzMatrix(std::move(source._yzMatrix))

    , _zzMatrix(std::move(source._zzMatrix))
{
}

CElectricFieldGradientMatrix::~CElectricFieldGradientMatrix()
{
}

CElectricFieldGradientMatrix&
CElectricFieldGradientMatrix::operator=(const CElectricFieldGradientMatrix& source)
{
    if (this == &source) return *this;

    _xxMatrix = source._xxMatrix;

    _xyMatrix = source._xyMatrix;

    _xzMatrix = source._xzMatrix;

    _yyMatrix = source._yyMatrix;

    _yzMatrix = source._yzMatrix;

    _zzMatrix = source._zzMatrix;

    return *this;
}

CElectricFieldGradientMatrix&
CElectricFieldGradientMatrix::operator=(CElectricFieldGradientMatrix&& source) noexcept
{
    if (this == &source) return *this;

    _xxMatrix = std::move(source._xxMatrix);

    _xyMatrix = std::move(source._xyMatrix);

    _xzMatrix = std::move(source._xzMatrix);

    _yyMatrix = std::move(source._yyMatrix);

    _yzMatrix = std::move(source._yzMatrix);

    _zzMatrix = std::move(source._zzMatrix);

    return *this;
}

bool
CElectricFieldGradientMatrix::operator==(const CElectricFieldGradientMatrix& other) const
{
    if (_xxMatrix != other._xxMatrix) return false;

    if (_xyMatrix != other._xyMatrix) return false;

    if (_xzMatrix != other._xzMatrix) return false;

    if (_yyMatrix != other._yyMatrix) return false;

    if (_yzMatrix != other._yzMatrix) return false;

    if (_zzMatrix != other._zzMatrix) return false;

    return true;
}

bool
CElectricFieldGradientMatrix::operator!=(const CElectricFieldGradientMatrix& other) const
{
    return !(*this == other);
}

std::string
CElectricFieldGradientMatrix::getStringForComponentXX() const
{
    return _xxMatrix.getString();
}

std::string
CElectricFieldGradientMatrix::getStringForComponentXY() const
{
    return _xyMatrix.getString();
}

std::string
CElectricFieldGradientMatrix::getStringForComponentXZ() const
{
    return _xzMatrix.getString();
}

std::string
CElectricFieldGradientMatrix::getStringForComponentYY() const
{
    return _yyMatrix.getString();
}

std::string
CElectricFieldGradientMatrix::getStringForComponentYZ() const
{
    return _yzMatrix.getString();
}

std::string
CElectricFieldGradientMatrix::getStringForComponentZZ() const
{
    return _zzMatrix.getString();
}

int32_t
CElectricFieldGradientMatrix::getNumberOfRows() const
{
    return _xxMatrix.getNumberOfRows();
}

int32_t
CElectricFieldGradientMatrix::getNumberOfColumns() const
{
    return _xxMatrix.getNumberOfColumns();
}

int32_t
CElectricFieldGradientMatrix::getNumberOfElements() const
{
    return _xxMatrix.getNumberOfElements();
}

const double*
CElectricFieldGradientMatrix::xxvalues() const
{
    return _xxMatrix.values();
}

const double*
CElectricFieldGradientMatrix::xyvalues() const
{
    return _xyMatrix.values();
}

const double*
CElectricFieldGradientMatrix::xzvalues() const
{
    return _xzMatrix.values();
}

const double*
CElectricFieldGradientMatrix::yyvalues() const
{
    return _yyMatrix.values();
}

const double*
CElectricFieldGradientMatrix::yzvalues() const
{
    return _yzMatrix.values();
}

const double*
CElectricFieldGradientMatrix::zzvalues() const
{
    return _zzMatrix.values();
}

std::ostream&
operator<<(std::ostream& output, const CElectricFieldGradientMatrix& source)
{
    output << std::endl;

    output << "[CElectricFieldGradientMatrix (Object):" << &source << "]" << std::endl;

    output << "_xxMatrix: " << source._xxMatrix << std::endl;

    output << "_xyMatrix: " << source._xyMatrix << std::endl;

    output << "_xzMatrix: " << source._xzMatrix << std::endl;

    output << "_yyMatrix: " << source._yyMatrix << std::endl;

    output << "_yzMatrix: " << source._yzMatrix << std::endl;

    output << "_zzMatrix: " << source._zzMatrix << std::endl;

    return output;
}
