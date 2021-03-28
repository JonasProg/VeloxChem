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

#include "FockContainer.hpp"

CFockContainer::CFockContainer()

    : _subFockMatrices({})
{
    
}

CFockContainer::CFockContainer(const std::vector<CFockSubMatrix>& subFockMatrices)

    : _subFockMatrices(subFockMatrices)
{
    
}

CFockContainer::CFockContainer(const CAOFockMatrix*  aoFockMatrix,
                               const CGtoPairsBlock& braGtoPairsBlock,
                               const CGtoPairsBlock& ketGtoPairsBlock)
{
    auto nfock = aoFockMatrix->getNumberOfFockMatrices();
    
    if (aoFockMatrix->isClosedShell())
    {
        for (int32_t i = 0; i < nfock; i++)
        {
            _subFockMatrices.push_back(CFockSubMatrix(braGtoPairsBlock,
                                                      ketGtoPairsBlock,
                                                      aoFockMatrix->getFockType(i)));
        }
    }
    else
    {
        for (int32_t i = 0; i < nfock; i++)
        {
            _subFockMatrices.push_back(CFockSubMatrix(braGtoPairsBlock,
                                                      ketGtoPairsBlock,
                                                      aoFockMatrix->getFockType(i, "alpha")));

            _subFockMatrices.push_back(CFockSubMatrix(braGtoPairsBlock,
                                                      ketGtoPairsBlock,
                                                      aoFockMatrix->getFockType(i, "beta")));
        }
    }
}

CFockContainer::CFockContainer(const CFockContainer& source)

    : _subFockMatrices(source._subFockMatrices)
{
    
}

CFockContainer::CFockContainer(CFockContainer&& source) noexcept

    : _subFockMatrices(std::move(source._subFockMatrices))
{
    
}

CFockContainer::~CFockContainer()
{
    
}

CFockContainer&
CFockContainer::operator=(const CFockContainer& source)
{
    if (this == &source) return *this;
    
    _subFockMatrices = source._subFockMatrices;
    
    return *this;
}

CFockContainer&
CFockContainer::operator=(CFockContainer&& source) noexcept
{
    if (this == &source) return *this;
    
    _subFockMatrices = std::move(source._subFockMatrices);
    
    return *this;
}

bool
CFockContainer::operator==(const CFockContainer& other) const
{
    if (_subFockMatrices.size() != other._subFockMatrices.size())
    {
        return false;
    }
    
    for (size_t i = 0; i < _subFockMatrices.size(); i++)
    {
        if (_subFockMatrices[i] != other._subFockMatrices[i]) return false;
    }
    
    return true;
}

bool
CFockContainer::operator!=(const CFockContainer& other) const
{
    return !(*this == other);
}

void
CFockContainer::accumulate(CAOFockMatrix* aoFockMatrix)
{
    auto nfock = aoFockMatrix->getNumberOfFockMatrices();
    
    if (aoFockMatrix->isClosedShell())
    {
        for (int32_t i = 0; i < nfock; i++)
        {
            _subFockMatrices[i].accumulate(aoFockMatrix->getFock(i),
                                           aoFockMatrix->getNumberOfColumns(i),
                                           aoFockMatrix->getFockType(i));
        }
    }
    else
    {
        for (int32_t i = 0; i < nfock; i++)
        {
            _subFockMatrices[2 * i].accumulate(aoFockMatrix->getFock(i, "alpha"),
                                               aoFockMatrix->getNumberOfColumns(i),
                                               aoFockMatrix->getFockType(i, "alpha"));

            _subFockMatrices[2 * i + 1].accumulate(aoFockMatrix->getFock(i, "beta"),
                                                   aoFockMatrix->getNumberOfColumns(i),
                                                   aoFockMatrix->getFockType(i, "beta"));
        }
    }
}

double*
CFockContainer::getSubMatrixData(const int32_t iFockMatrix,
                                 const int32_t iSubMatrix,
                                 const int32_t iComponent)
{
    return _subFockMatrices[iFockMatrix].getSubMatrixData(iSubMatrix,
                                                          iComponent);
}

const int32_t*
CFockContainer::getStartPositionsA(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getStartPositionsA();
}

const int32_t*
CFockContainer::getStartPositionsB(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getStartPositionsB();
}

const int32_t*
CFockContainer::getStartPositionsC(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getStartPositionsC();
}

const int32_t*
CFockContainer::getStartPositionsD(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getStartPositionsD();
}

int32_t
CFockContainer::getDimensionsA(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getDimensionsA();
}

int32_t
CFockContainer::getDimensionsB(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getDimensionsB();
}

int32_t
CFockContainer::getDimensionsC(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getDimensionsC();
}

int32_t
CFockContainer::getDimensionsD(const int32_t iFockMatrix) const
{
    return _subFockMatrices[iFockMatrix].getDimensionsD();
}

std::ostream&
operator<<(      std::ostream&   output,
           const CFockContainer& source)
{
    output << std::endl;
    
    output << "[CFockContainer (Object):" << &source << "]" << std::endl;
    
    output << "_subFockMatrices: " << std::endl;
    
    for (size_t i = 0; i < source._subFockMatrices.size(); i++)
    {
        output << "_subFockMatrices[" << i << "]: " << std::endl;
        
        output << source._subFockMatrices[i] << std::endl;
    }
    
    return output;
}
