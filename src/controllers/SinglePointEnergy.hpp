//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef SinglePointEnergy_hpp
#define SinglePointEnergy_hpp

#include <string>

#include "BaseJob.hpp"
#include "InputData.hpp"
#include "OutputStream.hpp"
#include "Molecule.hpp"

/**
 Class CSinglePointEnergy manages single point energy computation job for case
 of single molecule.
 
 @author Z. Rinkevicius
 */
class CSinglePointEnergy : public CBaseJob
{
    /**
     The molecular data.
     */
    CMolecule _molecule;      

    //CMolecularBasis _aoBasis;  // ao basis set

    //CMolecularBasis _riBasis;  // ri basis set

    //CAODensityMatrix _density;

    /**
     Prints start message for single point energy job to output stream.

     @param oStream the output stream.
     */
    void _startHeader(COutputStream& oStream) const;

public:
    
    /**
     Creates a single point energy computation job object.
     
     @param globRank the the rank of MPI process.
     @param globNodes the total number of MPI processes.
     */
    CSinglePointEnergy(const int32_t globRank, const int32_t globNodes);

    /**
     Sets parameters of single point energy computation job.

     @param pathToBasisSets the path to basis set library.
     @param inputData the input data object.
     @param oStream the output stream.
     */
    void set(const std::string& pathToBasisSets, const CInputData& inputData,
             COutputStream& oStream) override;

    /**
     Executes a single point energy computation job.

     @param oStream the output stream.
     */
    void run(COutputStream& oStream) override;
};

#endif /* SinglePointEnergy_hpp */
