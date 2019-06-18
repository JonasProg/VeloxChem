//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "NuclearPotentialMatrix.hpp"

#include "DenseLinearAlgebra.hpp"

CNuclearPotentialMatrix::CNuclearPotentialMatrix()
{
}

CNuclearPotentialMatrix::CNuclearPotentialMatrix(const CDenseMatrix& matrix)

    : _matrix(matrix)
{
}

CNuclearPotentialMatrix::CNuclearPotentialMatrix(const CNuclearPotentialMatrix& source)

    : _matrix(source._matrix)
{
}

CNuclearPotentialMatrix::CNuclearPotentialMatrix(CNuclearPotentialMatrix&& source) noexcept

    : _matrix(std::move(source._matrix))
{
}

CNuclearPotentialMatrix::~CNuclearPotentialMatrix()
{
}

CNuclearPotentialMatrix&
CNuclearPotentialMatrix::operator=(const CNuclearPotentialMatrix& source)
{
    if (this == &source) return *this;

    _matrix = source._matrix;

    return *this;
}

CNuclearPotentialMatrix&
CNuclearPotentialMatrix::operator=(CNuclearPotentialMatrix&& source) noexcept
{
    if (this == &source) return *this;

    _matrix = std::move(source._matrix);

    return *this;
}

bool
CNuclearPotentialMatrix::operator==(const CNuclearPotentialMatrix& other) const
{
    if (_matrix != other._matrix) return false;

    return true;
}

bool
CNuclearPotentialMatrix::operator!=(const CNuclearPotentialMatrix& other) const
{
    return !(*this == other);
}

std::string
CNuclearPotentialMatrix::getString() const
{
    return _matrix.getString();
}

int32_t
CNuclearPotentialMatrix::getNumberOfRows() const
{
    return _matrix.getNumberOfRows();
}

int32_t
CNuclearPotentialMatrix::getNumberOfColumns() const
{
    return _matrix.getNumberOfColumns();
}

int32_t
CNuclearPotentialMatrix::getNumberOfElements() const
{
    return _matrix.getNumberOfElements();
}

const double*
CNuclearPotentialMatrix::values() const
{
    return _matrix.values();
}

double
CNuclearPotentialMatrix::getNuclearPotentialEnergy(const CAODensityMatrix& aoDensityMatrix, const int32_t iDensityMatrix) const
{
    if (iDensityMatrix < aoDensityMatrix.getNumberOfMatrices())
    {
        if (aoDensityMatrix.getDensityType() == denmat::rest)
        {
            return denblas::trace(_matrix, aoDensityMatrix.getReferenceToDensity(iDensityMatrix));
        }
        else
        {
            auto idensity_a = 2 * iDensityMatrix;

            auto idensity_b = 2 * iDensityMatrix + 1;

            auto e_a = 0.5 * denblas::trace(_matrix, aoDensityMatrix.getReferenceToDensity(idensity_a));

            auto e_b = 0.5 * denblas::trace(_matrix, aoDensityMatrix.getReferenceToDensity(idensity_b));

            return e_a + e_b;
        }
    }

    return 0;
}

std::ostream&
operator<<(std::ostream& output, const CNuclearPotentialMatrix& source)
{
    output << std::endl;

    output << "[CNuclearPotentialMatrix (Object):" << &source << "]" << std::endl;

    output << "_matrix: " << source._matrix << std::endl;

    return output;
}
