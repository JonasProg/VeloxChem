//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "MolecularBasis.hpp"

#include "StringFormat.hpp"
#include "ChemicalElement.hpp"
#include "AngularMomentum.hpp"
#include "MpiFunc.hpp"

CMolecularBasis::CMolecularBasis()

    : _maxAngularMomentum(-1)
{

}

CMolecularBasis::CMolecularBasis(const CMolecularBasis& source)

    : _atomicBasisSets(source._atomicBasisSets)

    , _maxAngularMomentum(source._maxAngularMomentum)

    , _label(source._label)
{

}

CMolecularBasis::CMolecularBasis(CMolecularBasis&& source) noexcept

    : _atomicBasisSets(std::move(source._atomicBasisSets))

    , _maxAngularMomentum(std::move(source._maxAngularMomentum))

    , _label(std::move(source._label))
{

}

CMolecularBasis::~CMolecularBasis()
{

}

CMolecularBasis&
CMolecularBasis::operator=(const CMolecularBasis& source)
{
    if (this == &source) return *this;

    _atomicBasisSets = source._atomicBasisSets;

    _maxAngularMomentum = source._maxAngularMomentum;

    _label = source._label;

    return *this;
}

CMolecularBasis&
CMolecularBasis::operator=(CMolecularBasis&& source) noexcept
{
    if (this == &source) return *this;

    _atomicBasisSets = std::move(source._atomicBasisSets);

    _maxAngularMomentum = std::move(source._maxAngularMomentum);

    _label = std::move(source._label);

    return *this;
}

bool
CMolecularBasis::operator==(const CMolecularBasis& other) const
{
    if (_atomicBasisSets.size() != other._atomicBasisSets.size()) return false;

    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        if (_atomicBasisSets[i] != other._atomicBasisSets[i]) return false;
    }

    if (_maxAngularMomentum != other._maxAngularMomentum) return false;

    if (_label != other._label) return false;

    return true;
}

bool
CMolecularBasis::operator!=(const CMolecularBasis& other) const
{
    return !(*this == other);
}

void
CMolecularBasis::setMaxAngularMomentum(const int32_t maxAngularMomentum)
{
    _maxAngularMomentum = maxAngularMomentum;
}

void
CMolecularBasis::setLabel(const std::string& label)
{
    _label = label;
}

void
CMolecularBasis::addAtomBasis(const CAtomBasis& atomBasis)
{
    _atomicBasisSets.push_back(atomBasis);

    auto mAngularMomentum = atomBasis.getMaxAngularMomentum();

    if (mAngularMomentum > _maxAngularMomentum)
    {
        _maxAngularMomentum = mAngularMomentum;
    }
}

int32_t
CMolecularBasis::getMaxAngularMomentum() const
{
    return _maxAngularMomentum;
}

int32_t
CMolecularBasis::getMaxAngularMomentum(const int32_t idElemental) const
{
    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        if (_atomicBasisSets[i].getIdElemental() == idElemental)
        {
            return _atomicBasisSets[i].getMaxAngularMomentum();
        }
    }

    return -1;
}

std::string
CMolecularBasis::getLabel() const
{
    return _label;
}

int32_t
CMolecularBasis::getNumberOfBasisFunctions(const int32_t idElemental,
                                           const int32_t angularMomentum) const
{
    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        if (_atomicBasisSets[i].getIdElemental() == idElemental)
        {
            return _atomicBasisSets[i].getNumberOfBasisFunctions(angularMomentum);
        }
    }

    return 0;
}

int32_t
CMolecularBasis::getNumberOfBasisFunctions(const CMolecule& molecule,
                                           const int32_t    angularMomentum) const
{
    int32_t nbfucs = 0;

    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        nbfucs += molecule.getNumberOfAtoms(_atomicBasisSets[i].getIdElemental())

                * _atomicBasisSets[i].getNumberOfBasisFunctions(angularMomentum);
    }

    return nbfucs;
}

int32_t
CMolecularBasis::getNumberOfPrimitiveBasisFunctions(const CMolecule& molecule,
                                                    const int32_t    angularMomentum) const
{
    int32_t npfuncs = 0;

    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        npfuncs += molecule.getNumberOfAtoms(_atomicBasisSets[i].getIdElemental())

                 * _atomicBasisSets[i].getNumberOfPrimitiveFunctions(angularMomentum);
    }

    return npfuncs;
}

int32_t
CMolecularBasis::getDimensionsOfBasis(const CMolecule& molecule) const
{
    int32_t ndim = 0;

    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        auto idelem = _atomicBasisSets[i].getIdElemental();

        auto natoms = molecule.getNumberOfAtoms(idelem);

        auto mang = _atomicBasisSets[i].getMaxAngularMomentum();

        for (int32_t j = 0; j <= mang; j++)
        {
            ndim += natoms * angmom::to_SphericalComponents(j)

                  * _atomicBasisSets[i].getNumberOfBasisFunctions(j);
        }
    }

    return ndim;
}

int32_t
CMolecularBasis::getDimensionsOfPrimitiveBasis(const CMolecule& molecule) const
{
    int32_t ndim = 0;

    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        auto idelem = _atomicBasisSets[i].getIdElemental();

        auto natoms = molecule.getNumberOfAtoms(idelem);

        auto mang = _atomicBasisSets[i].getMaxAngularMomentum();

        for (int32_t j = 0; j <= mang; j++)
        {
            ndim += natoms * angmom::to_SphericalComponents(j)

                  * _atomicBasisSets[i].getNumberOfPrimitiveFunctions(j);
        }
    }

    return ndim;
}

CAtomBasis
CMolecularBasis::getAtomBasis(const int32_t idElemental) const
{
    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        if (_atomicBasisSets[i].getIdElemental() == idElemental)
        {
            return _atomicBasisSets[i];
        }
    }

    return CAtomBasis();
}

std::vector<CBasisFunction>
CMolecularBasis::getBasisFunctions(const int32_t idElemental,
                                   const int32_t angularMomentum) const
{
    for (size_t i = 0; i < _atomicBasisSets.size(); i++)
    {
        if (_atomicBasisSets[i].getIdElemental() == idElemental)
        {
            return _atomicBasisSets[i].getBasisFunctions(angularMomentum);
        }
    }

    return std::vector<CBasisFunction>();
}

void
CMolecularBasis::printBasis(const char*          title,
                            const CMolecule&     molecule,
                                  COutputStream& oStream) const
{
    std::string str("Molecular Basis (");

    str.append(title);

    str.append(")");

    oStream << fmt::header;

    oStream << str << fmt::end;

    oStream << std::string(str.size() + 2, '=') << fmt::end << fmt::blank;

    str.assign("Basis: ");

    str.append(_label);

    oStream << fstr::format(str, 54, fmt::left) << fmt::end << fmt::blank;

    oStream << "  Atom ";

    oStream << fstr::format(std::string("Contracted GTOs"), 25, fmt::left);

    oStream << fstr::format(std::string("Primitive GTOs"), 25, fmt::left);

    oStream << fmt::end << fmt::blank;

    for (auto i = _atomicBasisSets.cbegin(); i != _atomicBasisSets.cend(); ++i)
    {
        std::string lbl("  ");

        CChemicalElement ce;

        ce.setAtomType(i->getIdElemental());

        lbl.append(ce.getName());

        oStream << fstr::format(lbl, 6, fmt::left);

        oStream << fstr::format(i->getContractionString(), 25, fmt::left);

        oStream << fstr::format(i->getPrimitivesString(), 25, fmt::left);

        oStream << fmt::end;
    }

    oStream << fmt::blank;

    str.assign("Contracted Basis Functions : ");

    str.append(std::to_string(getDimensionsOfBasis(molecule)));

    oStream << fstr::format(str, 54, fmt::left) << fmt::end;

    str.assign("Primitive Basis Functions  : ");

    str.append(std::to_string(getDimensionsOfPrimitiveBasis(molecule)));

    oStream << fstr::format(str, 54, fmt::left) << fmt::end << fmt::blank;
}

void
CMolecularBasis::broadcast(int32_t  rank,
                           MPI_Comm comm)
{
    if (ENABLE_MPI)
    {
        mpi::bcast(_maxAngularMomentum, comm);

        mpi::bcast(_label, rank, comm);

        int32_t natombases = static_cast<int32_t>(_atomicBasisSets.size());

        mpi::bcast(natombases, comm);

        for (int32_t i = 0; i < natombases; i++)
        {
            CAtomBasis atmbasis;

            if (rank == mpi::master()) atmbasis = _atomicBasisSets[i];

            atmbasis.broadcast(rank, comm);

            if (rank != mpi::master()) addAtomBasis(atmbasis);
            
            MPI_Barrier(comm);
        }
    }
}

std::ostream&
operator<<(      std::ostream&    output, 
           const CMolecularBasis& source)
{
    output << std::endl;

    output << "[CMolecularBasis (Object):" << &source << "]" << std::endl;

    output << "_label: " << source._label << std::endl;

    output << "_maxAngularMomentum: " << source._maxAngularMomentum;

    output << std::endl;

    output << "_atomicBasisSets: " << std::endl;

    for (size_t i = 0; i < source._atomicBasisSets.size(); i++)
    {
        output << "_atomicBasisSets[" << i << "]: "<< std::endl;

        output << source._atomicBasisSets[i] << std::endl;
    }

    return output;
}
