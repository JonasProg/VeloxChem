//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "SinglePointEnergy.hpp"

#include "MpiFunc.hpp"
//#include "MolXYZReader.hpp"
//#include "BasisReader.hpp"
//#include "AtomicDensityReader.hpp"

//#include "GridDriver.hpp"
//#include "DensityGridDriver.hpp"
//#include "XCFuncType.hpp"

#include <iostream>

CSinglePointEnergy::CSinglePointEnergy(const int32_t globRank,
                                       const int32_t globNodes)

    : CBaseJob(globRank, globNodes)
{

}

void CSinglePointEnergy::set(const std::string& pathToBasisSets,
                             const CInputData& inputData,
                             COutputStream& oStream)
{
    if (_globRank == mpi::master()) _startHeader(oStream);

    // read molecular geometry
//
//    if (_globRank == mpi::master())
//    {
//        CMolXYZReader rdrMolXYZ;
//
//        rdrMolXYZ.parse(_molecule, inputData, oStream);
//
//        _state = rdrMolXYZ.getState();
//    }
//
//    mpi::bcast_bool(_state, _globRank, MPI_COMM_WORLD);
//
//    // broadcast molecular geometry
//
//    _molecule.broadcast(_globRank, MPI_COMM_WORLD);
//
//    if (!_state) return;
//
//    // print molecular geometry
//
//    if (_globRank == mpi::master())
//    {
//        _molecule.printGeometry(oStream);
//
//        _state = _molecule.checkProximity(0.1, oStream);
//    }
//
//    mpi::bcast_bool(_state, _globRank, MPI_COMM_WORLD);
//
//    if (!_state) return;
//
//    // read AO basis from basis set library
//
//    if (_globRank == mpi::master())
//    {
//        CBasisReader rdrAOBasis;
//
//        rdrAOBasis.parse(inputData, oStream);
//
//         _state = rdrAOBasis.getState();
//
//        if (_state)
//        {
//             _aoBasis = rdrAOBasis.getAOBasis(pathToBasisSets, _molecule,
//                                              oStream);
//        }
//
//        _state = rdrAOBasis.getState();
//    }
//
//    mpi::bcast_bool(_state, _globRank, MPI_COMM_WORLD);
//
//    if (!_state) return;
//
//    // broadcast AO basis
//
//    _aoBasis.broadcast(_globRank, MPI_COMM_WORLD);
//
//    // print atomic orbitals i.e. AO basis
//
//    if (_globRank == mpi::master())
//    {
//        _aoBasis.printBasis("Atomic Orbitals", _molecule, oStream);
//    }
//
//    if (_globRank == mpi::master())
//    {
//        // TODO: move to proper initial guess object
//
//        //CAtomicDensityReader adrdr;
//
//        //_density = adrdr.getAtomicDensities(pathToBasisSets, _molecule, _aoBasis, oStream);
//
//        //_state = adrdr.getState();
//    }
//
//    mpi::bcast_bool(_state, _globRank, MPI_COMM_WORLD);
//
//    if (!_state) return;

    // TODO: add other keywords...
}

void CSinglePointEnergy::run(COutputStream& oStream)
{
//    // generate molecular grid
//
//    CGridDriver drvGrid(_globRank, _globNodes, MPI_COMM_WORLD);
//
//    auto molGrid = drvGrid.generate(_molecule, oStream, MPI_COMM_WORLD);
//
//    std::cout << "Before: Rank: " << _globRank << " Grid. Points: " << molGrid.getNumberOfGridPoints() << std::endl;
//
//    molGrid.distribute(_globRank, _globNodes, MPI_COMM_WORLD);
//
//    std::cout << "After: Rank: " << _globRank << " Grid. Points: " << molGrid.getNumberOfGridPoints() << std::endl;
//
//    // generate density grid
//
//    CDensityGridDriver drvDenGrid(_globRank, _globNodes, MPI_COMM_WORLD);
//
//    drvDenGrid.generate(_molecule, _aoBasis, molGrid, xcfun::lda, oStream, MPI_COMM_WORLD);
}

void CSinglePointEnergy::_startHeader(COutputStream& oStream) const
{
    oStream << fmt::header;

    oStream << "==============================================";

    oStream << fmt::end;

    oStream << "=   Single Point Energy For Single Molecule  =";

    oStream << fmt::end;

    oStream << "==============================================" ;

    oStream << fmt::end  << fmt::blank;
}
