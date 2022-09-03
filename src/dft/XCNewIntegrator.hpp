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

#ifndef XCNewIntegrator_hpp
#define XCNewIntegrator_hpp

#include <list>
#include <array>
#include <string>

#include "AODensityMatrix.hpp"
#include "AOKohnShamMatrix.hpp"
#include "DenseMatrix.hpp"
#include "GridBox.hpp"
#include "GtoContainer.hpp"
#include "MemBlock2D.hpp"
#include "MolecularGrid.hpp"
#include "MolecularBasis.hpp"
#include "Molecule.hpp"
#include "MultiTimer.hpp"
#include "XCGradientGrid.hpp"

/**
 Class CXCNewIntegrator implements XC integrator.

 @author X. Li
 */
class CXCNewIntegrator
{
    /**
     The rank of associated local MPI process.
     */
    int32_t _locRank;

    /**
     The total number of local MPI processes.
     */
    int32_t _locNodes;

    /**
     The MPI communicator.
     */
    MPI_Comm _locComm;

    /**
     Timers for DFT integration.
     */
    std::list<CTimer> _timers;

    /**
     Generates density grid.

     @param npoints the number of grid points.
     @param gtoValuesOnGridPoints the GTO values on grid points.
     @param densityMatrix the AO density matrix.
     @param xcFunType the type of exchange-correlation functional.
     @param timer the timer.
     @return the density grid.
     */
    CDensityGrid _generateDensityGrid(const int32_t           npoints,
                                      const CDenseMatrix&     gtoValuesOnGridPoints,
                                      const CAODensityMatrix& densityMatrix,
                                      const xcfun             xcFunType,
                                      CMultiTimer&            timer) const;

    /**
     Integrates first-order exchnage-correlation functional contribution to AO
     Kohn-Sham matrix.

     @param npoints the number of grid points.
     @param xcoords the X coordinates of grid points.
     @param ycoords the Y coordinates of grid points.
     @param zcoords the Z coordinates of grid points.
     @param weights the weights of grid points.
     @param gtoValuesOnGridPoints the label of exchange-correlation functional.
     @param xcGradientGrid the exchange-correlation gradient grid.
     @param timer the timer.
     @return the AO Kohn-Sham matrix as a CDenseMatrix object.
     */
    CDenseMatrix _integratePartialVxcFockForLDA(const int32_t          npoints,
                                                const double*          xcoords,
                                                const double*          ycoords,
                                                const double*          zcoords,
                                                const double*          weights,
                                                const CDenseMatrix&    gtoValuesOnGridPoints,
                                                const CXCGradientGrid& xcGradientGrid,
                                                CMultiTimer&           timer) const;

   public:
    /**
     Creates an XC integrator object using MPI info.

     @param comm the MPI communicator.
     */
    CXCNewIntegrator(MPI_Comm comm);

    /**
     Destroys an XC integrator object.
     */
    ~CXCNewIntegrator();

    /**
     Integrates first-order exchnage-correlation functional contribution to AO
     Kohn-Sham matrix.

     @param molecule the molecule.
     @param basis the molecular basis.
     @param densityMatrix the AO density matrix object.
     @param molecularGrid the molecular grid.
     @param xcFuncLabel the label of exchange-correlation functional.
     @return the AO Kohn-Sham matrix.
     */
    CAOKohnShamMatrix integrateVxcFock(const CMolecule&        molecule,
                                       const CMolecularBasis&  basis,
                                       const CAODensityMatrix& densityMatrix,
                                       const CMolecularGrid&   molecularGrid,
                                       const std::string&      xcFuncLabel) const;
};

#endif /* XCNewIntegrator_hpp */
