//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "MolecularGrid.hpp"

CMolecularGrid::CMolecularGrid()

    : _isDistributed(false)
{
}

CMolecularGrid::CMolecularGrid(const CMemBlock2D<double>& gridPoints)

    : _isDistributed(false)

    , _gridPoints(gridPoints)
{
}

CMolecularGrid::CMolecularGrid(const CMolecularGrid& source)

    : _isDistributed(source._isDistributed)

    , _gridPoints(source._gridPoints)
{
}

CMolecularGrid::CMolecularGrid(CMolecularGrid&& source) noexcept

    : _isDistributed(std::move(source._isDistributed))

    , _gridPoints(std::move(source._gridPoints))
{
}

CMolecularGrid::~CMolecularGrid()
{
}

CMolecularGrid&
CMolecularGrid::operator=(const CMolecularGrid& source)
{
    if (this == &source) return *this;

    _isDistributed = source._isDistributed;

    _gridPoints = source._gridPoints;

    return *this;
}

CMolecularGrid&
CMolecularGrid::operator=(CMolecularGrid&& source) noexcept
{
    if (this == &source) return *this;

    _isDistributed = std::move(source._isDistributed);

    _gridPoints = std::move(source._gridPoints);

    return *this;
}

bool
CMolecularGrid::operator==(const CMolecularGrid& other) const
{
    if (_isDistributed != other._isDistributed) return false;

    if (_gridPoints != other._gridPoints) return false;

    return true;
}

bool
CMolecularGrid::operator!=(const CMolecularGrid& other) const
{
    return !(*this == other);
}

void
CMolecularGrid::slice(const int32_t nGridPoints)
{
    if (nGridPoints < getNumberOfGridPoints())
    {
        _gridPoints = _gridPoints.slice(0, nGridPoints); 
    }
}

int32_t
CMolecularGrid::getNumberOfGridPoints() const
{
    return _gridPoints.size(0);
}

const double*
CMolecularGrid::getCoordinatesX() const
{
    return _gridPoints.data(0);
}

double*
CMolecularGrid::getCoordinatesX()
{
    return _gridPoints.data(0);
}

const double*
CMolecularGrid::getCoordinatesY() const
{
    return _gridPoints.data(1);
}

double*
CMolecularGrid::getCoordinatesY()
{
    return _gridPoints.data(1);
}

const double*
CMolecularGrid::getCoordinatesZ() const
{
    return _gridPoints.data(2);
}

double*
CMolecularGrid::getCoordinatesZ()
{
    return _gridPoints.data(2);
}

const double*
CMolecularGrid::getWeights() const
{
    return _gridPoints.data(3);
}

double*
CMolecularGrid::getWeights()
{
    return _gridPoints.data(3);
}

void
CMolecularGrid::distribute(int32_t rank, int32_t nodes, MPI_Comm comm)
{
    if (!_isDistributed)
    {
        _isDistributed = true;

        _gridPoints.scatter(rank, nodes, comm);
    }
}

std::ostream&
operator<<(std::ostream& output, const CMolecularGrid& source)
{
    output << std::endl;
    
    output << "[CMolecularGrid (Object):" << &source << "]" << std::endl;

    output << "_isDistributed: " << source._isDistributed << std::endl;

    output << "_gridPoints: " << std::endl;

    output << source._gridPoints << std::endl;

    return output;
}
