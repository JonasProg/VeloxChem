//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2019 by VeloxChem developers. All rights reserved.

#include "AOFockMatrix.hpp"

#include <cmath>

#include "DenseLinearAlgebra.hpp"

CAOFockMatrix::CAOFockMatrix()
{
    
}

CAOFockMatrix::CAOFockMatrix(const std::vector<CDenseMatrix>& fockMatrices,
                             const std::vector<fockmat>&      fockTypes,
                             const std::vector<double>&       scaleFactors,
                             const std::vector<int32_t>&      idDensityMatrices)

    : _fockMatrices(fockMatrices)

    , _fockTypes(fockTypes)

    , _scaleFactors(scaleFactors)

    , _idDensityMatrices(idDensityMatrices)
{
    
}

CAOFockMatrix::CAOFockMatrix(const CAODensityMatrix& aoDensityMatrix)
{
    auto dmtyp = aoDensityMatrix.getDensityType();
    
    for (int32_t i = 0; i < aoDensityMatrix.getNumberOfDensityMatrices(); i++)
    {
        // set up dimensions of Fock matrix
        
        auto nrow = aoDensityMatrix.getNumberOfRows(i);
        
        auto ncol = aoDensityMatrix.getNumberOfColumns(i);
        
        // spin restricted closed-shell Hatree-Fock
        
        if (dmtyp == denmat::rest)
        {
            _fockMatrices.push_back(CDenseMatrix(nrow, ncol));
            
            _fockTypes.push_back(fockmat::restjk);
            
            _scaleFactors.push_back(1.0);
            
            _idDensityMatrices.push_back(i);
        }
        
        // spin restricted AO to MO transformation
        
        if (dmtyp == denmat::rmoij)
        {
            _fockMatrices.push_back(CDenseMatrix(nrow, ncol));
            
            _fockTypes.push_back(fockmat::rgenk);
            
            _scaleFactors.push_back(1.0);
            
            _idDensityMatrices.push_back(i);
        }
        
        // spin restricted general Fock matrix
        
        if (dmtyp == denmat::rgen)
        {
            _fockMatrices.push_back(CDenseMatrix(nrow, ncol));
            
            _fockTypes.push_back(fockmat::rgenjk);
            
            _scaleFactors.push_back(1.0);
            
            _idDensityMatrices.push_back(i);
        }
        
        // FIX ME: Add unrestricted open-shell Hatree-Fock
    }
}

CAOFockMatrix::CAOFockMatrix(const CAOFockMatrix& source)

    : _fockMatrices(source._fockMatrices)

    , _fockTypes(source._fockTypes)

    , _scaleFactors(source._scaleFactors)

    , _idDensityMatrices(source._idDensityMatrices)
{
    
}

CAOFockMatrix::CAOFockMatrix(CAOFockMatrix&& source) noexcept

    : _fockMatrices(std::move(source._fockMatrices))

    , _fockTypes(std::move(source._fockTypes))

    , _scaleFactors(std::move(source._scaleFactors))

    , _idDensityMatrices(std::move(source._idDensityMatrices))
{
    
}

CAOFockMatrix::~CAOFockMatrix()
{
    
}

CAOFockMatrix&
CAOFockMatrix::operator=(const CAOFockMatrix& source)
{
    if (this == &source) return *this;
    
    _fockMatrices = source._fockMatrices;
    
    _fockTypes = source._fockTypes;
    
    _scaleFactors = source._scaleFactors;
    
    _idDensityMatrices = source._idDensityMatrices;
    
    return *this;
}

CAOFockMatrix&
CAOFockMatrix::operator=(CAOFockMatrix&& source) noexcept
{
    if (this == &source) return *this;
    
    _fockMatrices = std::move(source._fockMatrices);
    
    _fockTypes = std::move(source._fockTypes);
    
    _scaleFactors = std::move(source._scaleFactors);
    
    _idDensityMatrices = std::move(source._idDensityMatrices);
    
    return *this;
}

bool
CAOFockMatrix::operator==(const CAOFockMatrix& other) const
{
    if (_fockMatrices.size() != other._fockMatrices.size()) return false;
    
    for (size_t i = 0; i < _fockMatrices.size(); i++)
    {
        if (_fockMatrices[i] != other._fockMatrices[i]) return false;
    }
    
    if (_fockTypes.size() != other._fockTypes.size()) return false;
    
    for (size_t i = 0; i < _fockTypes.size(); i++)
    {
        if (_fockTypes[i] != other._fockTypes[i]) return false;
    }
    
    if (_scaleFactors.size() != other._scaleFactors.size()) return false;
    
    for (size_t i = 0; i < _scaleFactors.size(); i++)
    {
        if (std::fabs(_scaleFactors[i] - other._scaleFactors[i]) > 1.0e-13) return false;
    }
    
    if (_idDensityMatrices.size() != other._idDensityMatrices.size()) return false;
    
    for (size_t i = 0; i < _idDensityMatrices.size(); i++)
    {
        if (_idDensityMatrices[i] != other._idDensityMatrices[i]) return false;
    }
    
    return true;
}

bool
CAOFockMatrix::operator!=(const CAOFockMatrix& other) const
{
    return !(*this == other);
}

void
CAOFockMatrix::setFockType(const fockmat& fockType,
                           const int32_t  iFockMatrix,
                           const bool     beta)
{
    if (isRestricted())
    {
        _fockTypes[iFockMatrix] = fockType;
    }
    else if (!beta)
    {
        _fockTypes[2 * iFockMatrix] = fockType;
    }
    else
    {
        _fockTypes[2 * iFockMatrix + 1] = fockType;
    }
}

void
CAOFockMatrix::zero()
{
    for (size_t i = 0; i < _fockMatrices.size(); i++)
    {
        _fockMatrices[i].zero(); 
    }
}

void
CAOFockMatrix::symmetrize()
{
    for (int32_t i = 0; i < getNumberOfFockMatrices(); i++)
    {
        if (isSymmetric(i)) _fockMatrices[i].symmetrize();
        
        // FIX ME: Add antisymmetric matrices
    }
}

void
CAOFockMatrix::add(const CAOFockMatrix& source)
{
    for (int32_t i = 0; i < getNumberOfFockMatrices(); i++)
    {
        _fockMatrices[i] = denblas::addAB(_fockMatrices[i],
                                          source._fockMatrices[i], 1.0);
    }
}

void
CAOFockMatrix::addCoreHamiltonian(const CKineticEnergyMatrix&    kineticEnergyMatrix,
                                  const CNuclearPotentialMatrix& nuclearPotentialMatrix,
                                  const int32_t                  iFockMatrix)
{
    // set up pointer to kinetic energy matrix
    
    auto pkin = kineticEnergyMatrix.values();
    
    // set up pointer to nuclear potential matrix
    
    auto pnucpot = nuclearPotentialMatrix.values();
    
    // set up pointer to Fock matrix
    
    auto pfock = _fockMatrices[iFockMatrix].values();
    
    // add core Hamiltonian contributions
    
    auto ndim = _fockMatrices[iFockMatrix].getNumberOfElements();
    
    #pragma omp simd aligned(pfock, pkin, pnucpot: VLX_ALIGN)
    for (int32_t i = 0; i < ndim; i++)
    {
        pfock[i] += pkin[i] - pnucpot[i];
    }
}

void
CAOFockMatrix::addOneElectronMatrix(const CDenseMatrix& oneElectronMatrix,
                                    const int32_t       iFockMatrix)
{
    // set up pointer to one electron matrix
    
    auto pone = oneElectronMatrix.values();
    
    // set up pointer to Fock matrix
    
    auto pfock = _fockMatrices[iFockMatrix].values();
    
    // add one electron operator contribution contributions
    
    auto ndim = _fockMatrices[iFockMatrix].getNumberOfElements();
    
    #pragma omp simd aligned(pfock, pone: VLX_ALIGN)
    for (int32_t i = 0; i < ndim; i++)
    {
        pfock[i] += pone[i];
    }
}

void
CAOFockMatrix::reduce_sum(int32_t  rank,
                          int32_t  nodes,
                          MPI_Comm comm)
{
    for (size_t i = 0; i < _fockMatrices.size(); i++)
    {
        _fockMatrices[i].reduce_sum(rank, nodes, comm);
        
        MPI_Barrier(comm);
    }
}

bool
CAOFockMatrix::isRestricted() const
{
    for (size_t i = 0; i < _fockMatrices.size(); i++)
    {
        auto focktype_str = to_string(_fockTypes[i]);

        if (focktype_str.find(std::string("Restricted")) != std::string::npos)
        {
            return true;
        }

        if (focktype_str.find(std::string("Unrestricted")) != std::string::npos)
        {
            return false;
        }
    }

    return true;
}

int32_t
CAOFockMatrix::getNumberOfFockMatrices() const
{
    if (isRestricted())
    {
        return static_cast<int32_t>(_fockMatrices.size());
    }
    else
    {
        return static_cast<int32_t>(_fockMatrices.size()) / 2;
    }
}


int32_t
CAOFockMatrix::getNumberOfRows(const int32_t iFockMatrix) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _fockMatrices[iFockMatrix].getNumberOfRows();
        }
        else
        {
            return _fockMatrices[2 * iFockMatrix].getNumberOfRows();
        }
    }
    
    return 0;
}

int32_t
CAOFockMatrix::getNumberOfColumns(const int32_t iFockMatrix) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _fockMatrices[iFockMatrix].getNumberOfColumns();
        }
        else
        {
            return _fockMatrices[2 * iFockMatrix].getNumberOfColumns();
        }
    }
    
    return 0;
}

int32_t
CAOFockMatrix::getNumberOfElements(const int32_t iFockMatrix) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _fockMatrices[iFockMatrix].getNumberOfElements();
        }
        else
        {
            return _fockMatrices[2 * iFockMatrix].getNumberOfElements();
        }
    }
    
    return 0;
}

const double*
CAOFockMatrix::getFock(const int32_t iFockMatrix, const bool beta) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _fockMatrices[iFockMatrix].values();
        }
        else if (!beta)
        {
            return _fockMatrices[2 * iFockMatrix].values();
        }
        else
        {
            return _fockMatrices[2 * iFockMatrix + 1].values();
        }
    }
    
    return nullptr;
}

double*
CAOFockMatrix::getFock(const int32_t iFockMatrix, const bool beta)
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _fockMatrices[iFockMatrix].values();
        }
        else if (!beta)
        {
            return _fockMatrices[2 * iFockMatrix].values();
        }
        else
        {
            return _fockMatrices[2 * iFockMatrix + 1].values();
        }
    }
    
    return nullptr;
}

const CDenseMatrix&
CAOFockMatrix::getReferenceToFock(const int32_t iFockMatrix, const bool beta) const
{
    if (isRestricted())
    {
        return _fockMatrices[iFockMatrix];
    }
    else if (!beta)
    {
        return _fockMatrices[2 * iFockMatrix];
    }
    else
    {
        return _fockMatrices[2 * iFockMatrix + 1];
    }
}

fockmat
CAOFockMatrix::getFockType(const int32_t iFockMatrix, const bool beta) const
{
    if (isRestricted())
    {
        return _fockTypes[iFockMatrix];
    }
    else if (!beta)
    {
        return _fockTypes[2 * iFockMatrix];
    }
    else
    {
        return _fockTypes[2 * iFockMatrix + 1];
    }
}

double
CAOFockMatrix::getScaleFactor(const int32_t iFockMatrix, const bool beta) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _scaleFactors[iFockMatrix];
        }
        else if (!beta)
        {
            return _scaleFactors[2 * iFockMatrix];
        }
        else
        {
            return _scaleFactors[2 * iFockMatrix + 1];
        }
    }
    
    return 0.0;
}

int32_t
CAOFockMatrix::getDensityIdentifier(const int32_t iFockMatrix, const bool beta) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        if (isRestricted())
        {
            return _idDensityMatrices[iFockMatrix];
        }
        else if (!beta)
        {
            return _idDensityMatrices[2 * iFockMatrix];
        }
        else
        {
            return _idDensityMatrices[2 * iFockMatrix + 1];
        }
    }
    
    return -1;
}

bool
CAOFockMatrix::isSymmetric(const int32_t iFockMatrix) const
{
    if (iFockMatrix < getNumberOfFockMatrices())
    {
        // check if Fock matrix is square
        
        if (_fockMatrices[iFockMatrix].getNumberOfRows() != _fockMatrices[iFockMatrix].getNumberOfColumns())
        {
            return false;
        }
    
        // determine symmetry by Fock matrix type 
        
        auto fcktyp = _fockTypes[iFockMatrix];
    
        if (fcktyp == fockmat::restjk) return true;
    
        if (fcktyp == fockmat::restjkx) return true;
    
        if (fcktyp == fockmat::restj) return true;
    
        if (fcktyp == fockmat::restk) return true;
    
        if (fcktyp == fockmat::restkx) return true;

        if (fcktyp == fockmat::unrestjk) return true;
    }
    
    return false;
}

double
CAOFockMatrix::getElectronicEnergy(const int32_t           iFockMatrix,
                                   const CAODensityMatrix& aoDensityMatrix,
                                   const int32_t           iDensityMatrix) const
{
    if ((iFockMatrix < getNumberOfFockMatrices()) && (iDensityMatrix < aoDensityMatrix.getNumberOfMatrices()))
    {
        if (isRestricted())
        {
            return denblas::trace(_fockMatrices[iFockMatrix], aoDensityMatrix.getReferenceToDensity(iDensityMatrix));
        }
        else
        {
            // TODO: add unrestricted electronic energy
            return 0.0;
        }
    }
    
    return 0.0; 
}

std::string
CAOFockMatrix::getString() const
{
    std::string dmat_str;
    
    for (size_t i = 0; i < _fockMatrices.size(); i++)
    {
        dmat_str += "Fock Type: " + to_string(_fockTypes[i]) + "\n";
 
        dmat_str += "Density Identifier: " + std::to_string(_idDensityMatrices[i]) + "\n";
        
        dmat_str += _fockMatrices[i].getString();
    }
    
    return dmat_str;
}

std::ostream&
operator<<(      std::ostream&     output,
           const CAOFockMatrix& source)
{
    output << std::endl;
    
    output << "[CAOFockMatrix (Object):" << &source << "]" << std::endl;
    
    output << "_fockMatrices: " << std::endl;
    
    for (size_t i = 0; i < source._fockMatrices.size(); i++)
    {
        output << "_fockMatrices[" << i << "]: " << std::endl;
        
        output << source._fockMatrices[i] << std::endl;
    }
    
    output << "_fockTypes: " << std::endl;
    
    for (size_t i = 0; i < source._fockTypes.size(); i++)
    {
        output << "_fockTypes[" << i << "]: ";
        
        output << to_string(source._fockTypes[i]) << std::endl;
    }
    
    output << "_scaleFactors: " << std::endl;
    
    for (size_t i = 0; i < source._fockTypes.size(); i++)
    {
        output << "_scaleFactors[" << i << "]: ";
        
        output << source._scaleFactors[i] << std::endl;
    }
    
    output << "_idDensityMatrices: " << std::endl;
    
    for (size_t i = 0; i < source._idDensityMatrices.size(); i++)
    {
        output << "_idDensityMatrices[" << i << "]: ";
        
        output << source._idDensityMatrices[i] << std::endl;
    }

    return output;
}
