//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include "SinglePointEnergy.hpp"

#include "MpiFunc.hpp"
#include "MolXYZReader.hpp"
#include "BasisReader.hpp"
//#include "AtomicDensityReader.hpp"

#include "GridDriver.hpp"
#include "DensityGridDriver.hpp"
#include "XCFuncType.hpp"

#include "OverlapIntegralsDriver.hpp"
#include "KineticEnergyIntegralsDriver.hpp"
#include "NuclearPotentialIntegralsDriver.hpp"

#include "MemBlock2D.hpp"

#include <iostream>

CSinglePointEnergy::CSinglePointEnergy(const int32_t  globRank,
                                       const int32_t  globNodes,
                                       const execmode runMode)

    : CBaseJob(globRank, globNodes, runMode)
{

}

void
CSinglePointEnergy::set(const std::string&   pathToBasisSets,
                        const CInputData&    inputData,
                              COutputStream& oStream)
{
    if (_globRank == mpi::master()) _startHeader(oStream);
    
    // read molecular geometry
    
    if (_globRank == mpi::master())
    {
        CMolXYZReader rdrmolxyz;

        rdrmolxyz.parse(_molecule, inputData, oStream);

        _state = rdrmolxyz.getState();
    }

    mpi::bcast(_state, _globRank, MPI_COMM_WORLD);
    
    if (!_state) return;

    // broadcast molecular geometry

    _molecule.broadcast(_globRank, MPI_COMM_WORLD);

    // print molecular geometry

    if (_globRank == mpi::master())
    {
        _molecule.printGeometry(oStream);

        _state = _molecule.checkProximity(0.1, oStream);
    }

    oStream.flush();
    
    mpi::bcast(_state, _globRank, MPI_COMM_WORLD);

    if (!_state) return;
    
    // read AO basis from basis set library

    if (_globRank == mpi::master())
    {
        CBasisReader rdraobasis;

        rdraobasis.parse(inputData, oStream);

         _state = rdraobasis.getState();

        if (_state)
        {
             _aoBasis = rdraobasis.getAOBasis(pathToBasisSets, _molecule,
                                              oStream);
        }

        _state = rdraobasis.getState();
    }

    mpi::bcast(_state, _globRank, MPI_COMM_WORLD);

    if (!_state) return;

    // broadcast AO basis

    _aoBasis.broadcast(_globRank, MPI_COMM_WORLD);

    // print atomic orbitals i.e. AO basis

    if (_globRank == mpi::master()) _aoBasis.printBasis("Atomic Orbitals",
                                                        _molecule, oStream);

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

void
CSinglePointEnergy::run(COutputStream& oStream,
                        MPI_Comm       comm)
{
    // generate molecular grid

    CGridDriver drvgrid(_globRank, _globNodes, _runMode, comm);

    auto molgrid = drvgrid.generate(_molecule, oStream, comm);

    molgrid.distribute(_globRank, _globNodes, comm);
    
    // compute overlap integrals
    
    COverlapIntegralsDriver ovldrv(_globRank, _globNodes, comm);
    
    auto ovlmat = ovldrv.compute(_molecule, _aoBasis, comm);
    
    // compute kinetic energy integrals
    
    CKineticEnergyIntegralsDriver kindrv(_globRank, _globNodes, comm);
    
    auto kinmat = kindrv.compute(_molecule, _aoBasis, comm);
    
    CNuclearPotentialIntegralsDriver nucpotdrv(_globRank, _globNodes, comm);
    
    auto nucpotmat = nucpotdrv.compute(_molecule, _aoBasis, comm);

    // generate density grid

    //CDensityGridDriver drvDenGrid(_globRank, _globNodes, _runMode, comm);

    //drvDenGrid.generate(_molecule, _aoBasis, molgrid, xcfun::mgga, oStream, comm);
}

void
CSinglePointEnergy::_startHeader(COutputStream& oStream) const
{
    oStream << fmt::header;

    oStream << "==============================================";

    oStream << fmt::end;

    oStream << "=   Single Point Energy For Single Molecule  =";

    oStream << fmt::end;

    oStream << "==============================================" ;

    oStream << fmt::end  << fmt::blank;
}
