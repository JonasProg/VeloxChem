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

#include "XCNewIntegrator.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <omp.h>

#include "AngularMomentum.hpp"
#include "DenseLinearAlgebra.hpp"
#include "DensityGridGenerator.hpp"
#include "DensityGridType.hpp"
#include "FunctionalParser.hpp"
#include "GtoEvaluator.hpp"
#include "XCFuncType.hpp"
#include "XCVarsType.hpp"

CXCNewIntegrator::CXCNewIntegrator(MPI_Comm comm)

    : _screeningThresholdForGTOValues(1.0e-12)
{
    _locRank = mpi::rank(comm);

    _locNodes = mpi::nodes(comm);

    _locComm = comm;
}

CXCNewIntegrator::~CXCNewIntegrator()
{
}

CAOKohnShamMatrix
CXCNewIntegrator::integrateVxcFock(const CMolecule&        molecule,
                                   const CMolecularBasis&  basis,
                                   const CAODensityMatrix& densityMatrix,
                                   const CMolecularGrid&   molecularGrid,
                                   const std::string&      xcFuncLabel) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (densityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
           return _integrateVxcFockForLDA(molecule, basis, densityMatrix, molecularGrid, fvxc);
        }
        else if (xcfuntype == xcfun::gga)
        {
           return _integrateVxcFockForGGA(molecule, basis, densityMatrix, molecularGrid, fvxc);
        }
        else
        {
            std::string errxcfuntype("XCNewIntegrator.integrateVxcFock: Only implemented for LDA/GGA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCNewIntegrator.integrateVxcFock: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    return CAOKohnShamMatrix();
}

void
CXCNewIntegrator::integrateFxcFock(CAOFockMatrix&          aoFockMatrix,
                                   const CMolecule&        molecule,
                                   const CMolecularBasis&  basis,
                                   const CAODensityMatrix& rwDensityMatrix,
                                   const CAODensityMatrix& gsDensityMatrix,
                                   const CMolecularGrid&   molecularGrid,
                                   const std::string&      xcFuncLabel) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (rwDensityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
           _integrateFxcFockForLDA(aoFockMatrix, molecule, basis, rwDensityMatrix, gsDensityMatrix, molecularGrid, fvxc);
        }
        else if (xcfuntype == xcfun::gga)
        {
           _integrateFxcFockForGGA(aoFockMatrix, molecule, basis, rwDensityMatrix, gsDensityMatrix, molecularGrid, fvxc);
        }
        else
        {
            std::string errxcfuntype("XCNewIntegrator.integrateFxcFock: Only implemented for LDA/GGA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCNewIntegrator.integrateFxcFock: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }
}

CAOKohnShamMatrix
CXCNewIntegrator::_integrateVxcFockForLDA(const CMolecule&        molecule,
                                          const CMolecularBasis&  basis,
                                          const CAODensityMatrix& densityMatrix,
                                          const CMolecularGrid&   molecularGrid,
                                          const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    std::vector<CMultiTimer> omptimers(nthreads);

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // Kohn-Sham matrix

    CAOKohnShamMatrix mat_Vxc(densityMatrix.getNumberOfRows(0), densityMatrix.getNumberOfColumns(0), true);

    mat_Vxc.zero();

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos); // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // initial values for XC energy and number of electrons

    double nele = 0.0, xcene = 0.0;

    // coordinates and weights of grid points

    auto xcoords = molecularGrid.getCoordinatesX();

    auto ycoords = molecularGrid.getCoordinatesY();

    auto zcoords = molecularGrid.getCoordinatesZ();

    auto weights = molecularGrid.getWeights();

    // counts and displacements of grid points in boxes

    auto counts = molecularGrid.getGridPointCounts();

    auto displacements = molecularGrid.getGridPointDisplacements();

    timer.stop("Preparation");

    for (int32_t box_id = 0; box_id < counts.size(); box_id++)
    {
        // grid points in box

        auto npoints = counts.data()[box_id];

        auto gridblockpos = displacements.data()[box_id];

        // dimension of grid box

        auto boxdim = _getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        _preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 0, boxdim);

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            omptimers[thread_id].start("gtoeval");

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForLDA(gaos, gtovec, xcoords, ycoords, zcoords, gridblockpos,

                                             grid_batch_offset, grid_batch_size, skip_cgto_ids);

            omptimers[thread_id].stop("gtoeval");
        }

        timer.stop("OMP GTO evaluation");

        timer.start("GTO screening");

        int32_t aocount = 0;

        for (int32_t nu = 0; nu < naos; nu++)
        {
            if (skip_ao_ids.data()[nu]) continue;

            bool skip = true;

            auto gaos_nu = gaos.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if (std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues)
                {
                    skip = false;

                    break;
                }
            }

            if (!skip)
            {
                aoinds[aocount] = nu;

                ++aocount;
            }
        }

        CDenseMatrix mat_chi(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto sub_dens_mat = _getSubDensityMatrix(densityMatrix, 0, aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        auto xcfuntype = xcFunctional.getFunctionalType();

        auto dengrid = dengridgen::generateDensityGridForLDA(npoints, mat_chi, sub_dens_mat, xcfuntype, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        CXCGradientGrid vxcgrid(npoints, dengrid.getDensityGridType(), xcfuntype);

        xcFunctional.compute(vxcgrid, dengrid);

        timer.stop("XC functional eval.");

        // compute partial contribution to Vxc matrix

        auto partial_mat_Vxc = _integratePartialVxcFockForLDA(gridblockpos, npoints, weights, mat_chi, vxcgrid, timer);

        // distribute partial Vxc to full Vxc

        timer.start("Vxc matrix dist.");

        _distributeVxcMatrix(mat_Vxc, partial_mat_Vxc, aoinds, aocount, naos);

        timer.stop("Vxc matrix dist.");

        // compute partial contribution to XC energy

        timer.start("XC energy");

        auto rhoa = dengrid.alphaDensity(0);

        auto rhob = dengrid.betaDensity(0);

        auto efunc = vxcgrid.xcFunctionalValues();

        for (int32_t g = 0; g < npoints; g++)
        {
            nele += weights[gridblockpos + g] * (rhoa[g] + rhob[g]);

            xcene += weights[gridblockpos + g] * efunc[g];
        }

        timer.stop("XC energy");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    std::cout << "Timing of new integrator" << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << timer.getSummary() << std::endl;

    std::cout << "OpenMP timing" << std::endl;

    for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
    {
        std::cout << "Thread " << thread_id << std::endl;

        std::cout << omptimers[thread_id].getSummary() << std::endl;
    }

    mat_Vxc.setNumberOfElectrons(nele);

    mat_Vxc.setExchangeCorrelationEnergy(xcene);

    return mat_Vxc;
}

CAOKohnShamMatrix
CXCNewIntegrator::_integrateVxcFockForGGA(const CMolecule&        molecule,
                                          const CMolecularBasis&  basis,
                                          const CAODensityMatrix& densityMatrix,
                                          const CMolecularGrid&   molecularGrid,
                                          const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    std::vector<CMultiTimer> omptimers(nthreads);

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // Kohn-Sham matrix

    CAOKohnShamMatrix mat_Vxc(densityMatrix.getNumberOfRows(0), densityMatrix.getNumberOfColumns(0), true);

    mat_Vxc.zero();

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos); // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // initial values for XC energy and number of electrons

    double nele = 0.0, xcene = 0.0;

    // coordinates and weights of grid points

    auto xcoords = molecularGrid.getCoordinatesX();

    auto ycoords = molecularGrid.getCoordinatesY();

    auto zcoords = molecularGrid.getCoordinatesZ();

    auto weights = molecularGrid.getWeights();

    // counts and displacements of grid points in boxes

    auto counts = molecularGrid.getGridPointCounts();

    auto displacements = molecularGrid.getGridPointDisplacements();

    timer.stop("Preparation");

    for (int32_t box_id = 0; box_id < counts.size(); box_id++)
    {
        // grid points in box

        auto npoints = counts.data()[box_id];

        auto gridblockpos = displacements.data()[box_id];

        // dimension of grid box

        auto boxdim = _getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        _preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 1, boxdim);

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            omptimers[thread_id].start("gtoeval");

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForGGA(gaos, gaox, gaoy, gaoz, gtovec, xcoords, ycoords, zcoords, gridblockpos,

                                             grid_batch_offset, grid_batch_size, skip_cgto_ids);

            omptimers[thread_id].stop("gtoeval");
        }

        timer.stop("OMP GTO evaluation");

        timer.start("GTO screening");

        int32_t aocount = 0;

        for (int32_t nu = 0; nu < naos; nu++)
        {
            if (skip_ao_ids.data()[nu]) continue;

            bool skip = true;

            auto gaos_nu = gaos.data(nu);

            auto gaox_nu = gaox.data(nu);

            auto gaoy_nu = gaoy.data(nu);

            auto gaoz_nu = gaoz.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues))
                {
                    skip = false;

                    break;
                }
            }

            if (!skip)
            {
                aoinds[aocount] = nu;

                ++aocount;
            }
        }

        CDenseMatrix mat_chi(aocount, npoints);

        CDenseMatrix mat_chi_x(aocount, npoints);

        CDenseMatrix mat_chi_y(aocount, npoints);

        CDenseMatrix mat_chi_z(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto sub_dens_mat = _getSubDensityMatrix(densityMatrix, 0, aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        auto xcfuntype = xcFunctional.getFunctionalType();

        auto dengrid = dengridgen::generateDensityGridForGGA(npoints, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z,

                                                             sub_dens_mat, xcfuntype, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        CXCGradientGrid vxcgrid(npoints, dengrid.getDensityGridType(), xcfuntype);

        xcFunctional.compute(vxcgrid, dengrid);

        timer.stop("XC functional eval.");

        // compute partial contribution to Vxc matrix

        auto partial_mat_Vxc = _integratePartialVxcFockForGGA(gridblockpos, npoints, weights, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z,
                                                              vxcgrid, dengrid, timer);

        // distribute partial Vxc to full Vxc

        timer.start("Vxc matrix dist.");

        _distributeVxcMatrix(mat_Vxc, partial_mat_Vxc, aoinds, aocount, naos);

        timer.stop("Vxc matrix dist.");

        // compute partial contribution to XC energy

        timer.start("XC energy");

        auto rhoa = dengrid.alphaDensity(0);

        auto rhob = dengrid.betaDensity(0);

        auto efunc = vxcgrid.xcFunctionalValues();

        for (int32_t g = 0; g < npoints; g++)
        {
            nele += weights[gridblockpos + g] * (rhoa[g] + rhob[g]);

            xcene += weights[gridblockpos + g] * efunc[g];
        }

        timer.stop("XC energy");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    std::cout << "Timing of new integrator" << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << timer.getSummary() << std::endl;

    std::cout << "OpenMP timing" << std::endl;

    for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
    {
        std::cout << "Thread " << thread_id << std::endl;

        std::cout << omptimers[thread_id].getSummary() << std::endl;
    }

    mat_Vxc.setNumberOfElectrons(nele);

    mat_Vxc.setExchangeCorrelationEnergy(xcene);

    return mat_Vxc;
}

void
CXCNewIntegrator::_integrateFxcFockForLDA(CAOFockMatrix&          aoFockMatrix,
                                          const CMolecule&        molecule,
                                          const CMolecularBasis&  basis,
                                          const CAODensityMatrix& rwDensityMatrix,
                                          const CAODensityMatrix& gsDensityMatrix,
                                          const CMolecularGrid&   molecularGrid,
                                          const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    std::vector<CMultiTimer> omptimers(nthreads);

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos); // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // coordinates and weights of grid points

    auto xcoords = molecularGrid.getCoordinatesX();

    auto ycoords = molecularGrid.getCoordinatesY();

    auto zcoords = molecularGrid.getCoordinatesZ();

    auto weights = molecularGrid.getWeights();

    // counts and displacements of grid points in boxes

    auto counts = molecularGrid.getGridPointCounts();

    auto displacements = molecularGrid.getGridPointDisplacements();

    timer.stop("Preparation");

    for (int32_t box_id = 0; box_id < counts.size(); box_id++)
    {
        // grid points in box

        auto npoints = counts.data()[box_id];

        auto gridblockpos = displacements.data()[box_id];

        // dimension of grid box

        auto boxdim = _getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        _preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 0, boxdim);

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            omptimers[thread_id].start("gtoeval");

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForLDA(gaos, gtovec, xcoords, ycoords, zcoords, gridblockpos,

                                             grid_batch_offset, grid_batch_size, skip_cgto_ids);

            omptimers[thread_id].stop("gtoeval");
        }

        timer.stop("OMP GTO evaluation");

        timer.start("GTO screening");

        int32_t aocount = 0;

        for (int32_t nu = 0; nu < naos; nu++)
        {
            if (skip_ao_ids.data()[nu]) continue;

            bool skip = true;

            auto gaos_nu = gaos.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if (std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues)
                {
                    skip = false;

                    break;
                }
            }

            if (!skip)
            {
                aoinds[aocount] = nu;

                ++aocount;
            }
        }

        CDenseMatrix mat_chi(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto sub_dens_mat = _getSubDensityMatrix(gsDensityMatrix, 0, aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        auto xcfuntype = xcFunctional.getFunctionalType();

        auto gsdengrid = dengridgen::generateDensityGridForLDA(npoints, mat_chi, sub_dens_mat, xcfuntype, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        CXCHessianGrid vxc2grid(npoints, gsdengrid.getDensityGridType(), xcfuntype);

        xcFunctional.compute(vxc2grid, gsdengrid);

        timer.stop("XC functional eval.");

        // go through rhow density matrices

        for (int32_t idensity = 0; idensity < rwDensityMatrix.getNumberOfDensityMatrices(); idensity++)
        {
            // generate sub density matrix

            timer.start("Density matrix slicing");

            auto sub_dens_mat = _getSubDensityMatrix(rwDensityMatrix, idensity, aoinds, aocount, naos);

            timer.stop("Density matrix slicing");

            // generate density grid

            auto xcfuntype = xcFunctional.getFunctionalType();

            auto rwdengrid = dengridgen::generateDensityGridForLDA(npoints, mat_chi, sub_dens_mat, xcfuntype, timer);

            // compute partial contribution to Fxc matrix

            auto partial_mat_Fxc = _integratePartialFxcFockForLDA(gridblockpos, npoints, weights, mat_chi,

                                                                  vxc2grid, rwdengrid, timer);

            // distribute partial Fxc to full Fxc

            timer.start("Fxc matrix dist.");

            _distributeFxcMatrix(aoFockMatrix, idensity, partial_mat_Fxc, aoinds, aocount, naos);

            timer.stop("Fxc matrix dist.");
        }
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    std::cout << "Timing of new integrator" << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << timer.getSummary() << std::endl;

    std::cout << "OpenMP timing" << std::endl;

    for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
    {
        std::cout << "Thread " << thread_id << std::endl;

        std::cout << omptimers[thread_id].getSummary() << std::endl;
    }
}

void
CXCNewIntegrator::_integrateFxcFockForGGA(CAOFockMatrix&          aoFockMatrix,
                                          const CMolecule&        molecule,
                                          const CMolecularBasis&  basis,
                                          const CAODensityMatrix& rwDensityMatrix,
                                          const CAODensityMatrix& gsDensityMatrix,
                                          const CMolecularGrid&   molecularGrid,
                                          const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    std::vector<CMultiTimer> omptimers(nthreads);

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos); // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // coordinates and weights of grid points

    auto xcoords = molecularGrid.getCoordinatesX();

    auto ycoords = molecularGrid.getCoordinatesY();

    auto zcoords = molecularGrid.getCoordinatesZ();

    auto weights = molecularGrid.getWeights();

    // counts and displacements of grid points in boxes

    auto counts = molecularGrid.getGridPointCounts();

    auto displacements = molecularGrid.getGridPointDisplacements();

    timer.stop("Preparation");

    for (int32_t box_id = 0; box_id < counts.size(); box_id++)
    {
        // grid points in box

        auto npoints = counts.data()[box_id];

        auto gridblockpos = displacements.data()[box_id];

        // dimension of grid box

        auto boxdim = _getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        _preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 1, boxdim);

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            omptimers[thread_id].start("gtoeval");

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForGGA(gaos, gaox, gaoy, gaoz, gtovec, xcoords, ycoords, zcoords, gridblockpos,

                                             grid_batch_offset, grid_batch_size, skip_cgto_ids);

            omptimers[thread_id].stop("gtoeval");
        }

        timer.stop("OMP GTO evaluation");

        timer.start("GTO screening");

        int32_t aocount = 0;

        for (int32_t nu = 0; nu < naos; nu++)
        {
            if (skip_ao_ids.data()[nu]) continue;

            bool skip = true;

            auto gaos_nu = gaos.data(nu);

            auto gaox_nu = gaox.data(nu);

            auto gaoy_nu = gaoy.data(nu);

            auto gaoz_nu = gaoz.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues))
                {
                    skip = false;

                    break;
                }
            }

            if (!skip)
            {
                aoinds[aocount] = nu;

                ++aocount;
            }
        }

        CDenseMatrix mat_chi(aocount, npoints);

        CDenseMatrix mat_chi_x(aocount, npoints);

        CDenseMatrix mat_chi_y(aocount, npoints);

        CDenseMatrix mat_chi_z(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto sub_dens_mat = _getSubDensityMatrix(gsDensityMatrix, 0, aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        auto xcfuntype = xcFunctional.getFunctionalType();

        auto gsdengrid = dengridgen::generateDensityGridForGGA(npoints, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z,

                                                               sub_dens_mat, xcfuntype, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        CXCGradientGrid vxcgrid(npoints, gsdengrid.getDensityGridType(), xcfuntype);

        CXCHessianGrid vxc2grid(npoints, gsdengrid.getDensityGridType(), xcfuntype);

        xcFunctional.compute(vxcgrid, gsdengrid);

        xcFunctional.compute(vxc2grid, gsdengrid);

        timer.stop("XC functional eval.");

        // go through rhow density matrices

        for (int32_t idensity = 0; idensity < rwDensityMatrix.getNumberOfDensityMatrices(); idensity++)
        {
            // generate sub density matrix

            timer.start("Density matrix slicing");

            auto sub_dens_mat = _getSubDensityMatrix(rwDensityMatrix, idensity, aoinds, aocount, naos);

            timer.stop("Density matrix slicing");

            // generate density grid

            auto xcfuntype = xcFunctional.getFunctionalType();

            auto rwdengrid = dengridgen::generateDensityGridForGGA(npoints, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z,

                                                                   sub_dens_mat, xcfuntype, timer);

            // compute partial contribution to Fxc matrix

            auto partial_mat_Fxc = _integratePartialFxcFockForGGA(gridblockpos, npoints, weights, mat_chi,

                                                                  mat_chi_x, mat_chi_y, mat_chi_z,

                                                                  vxcgrid, vxc2grid, rwdengrid, gsdengrid, timer);

            // distribute partial Fxc to full Fock matrix

            timer.start("Fxc matrix dist.");

            _distributeFxcMatrix(aoFockMatrix, idensity, partial_mat_Fxc, aoinds, aocount, naos);

            timer.stop("Fxc matrix dist.");
        }
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    std::cout << "Timing of new integrator" << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << timer.getSummary() << std::endl;

    std::cout << "OpenMP timing" << std::endl;

    for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
    {
        std::cout << "Thread " << thread_id << std::endl;

        std::cout << omptimers[thread_id].getSummary() << std::endl;
    }
}

std::array<double, 6>
CXCNewIntegrator::_getGridBoxDimension(const int32_t gridBlockPosition,
                                       const int32_t nGridPoints,
                                       const double* xcoords,
                                       const double* ycoords,
                                       const double* zcoords) const
{
    double xmin = xcoords[gridBlockPosition], ymin = ycoords[gridBlockPosition], zmin = zcoords[gridBlockPosition];

    double xmax = xcoords[gridBlockPosition], ymax = ycoords[gridBlockPosition], zmax = zcoords[gridBlockPosition];

    for (int32_t g = 0; g < nGridPoints; g++)
    {
        xmin = std::min(xmin, xcoords[gridBlockPosition + g]);

        ymin = std::min(ymin, ycoords[gridBlockPosition + g]);

        zmin = std::min(zmin, zcoords[gridBlockPosition + g]);

        xmax = std::max(xmax, xcoords[gridBlockPosition + g]);

        ymax = std::max(ymax, ycoords[gridBlockPosition + g]);

        zmax = std::max(zmax, zcoords[gridBlockPosition + g]);
    }

    return std::array<double, 6>({xmin, ymin, zmin, xmax, ymax, zmax});
}

void
CXCNewIntegrator::_preScreenGtos(CMemBlock<int32_t>&          skipCgtoIds,
                                 CMemBlock<int32_t>&          skipAOIds,
                                 const CGtoContainer*         gtoContainer,
                                 const int32_t                gtoDeriv,
                                 const std::array<double, 6>& boxDimension) const
{
    skipCgtoIds.zero();

    skipAOIds.zero();

    double xmin = boxDimension[0], ymin = boxDimension[1], zmin = boxDimension[2];

    double xmax = boxDimension[3], ymax = boxDimension[4], zmax = boxDimension[5];

    for (int32_t i = 0, cgto_count = 0; i < gtoContainer->getNumberOfGtoBlocks(); i++)
    {
        auto bgtos = gtoContainer->getGtoBlock(i);

        auto bang = bgtos.getAngularMomentum();

        auto bfnorms = bgtos.getNormFactors();

        auto bfexps = bgtos.getExponents();

        auto bfx = bgtos.getCoordinatesX();

        auto bfy = bgtos.getCoordinatesY();

        auto bfz = bgtos.getCoordinatesZ();

        auto spos = bgtos.getStartPositions();

        auto epos = bgtos.getEndPositions();

        // loop over contracted GTOs

        for (int32_t j = 0; j < bgtos.getNumberOfContrGtos(); j++, cgto_count++)
        {
            // contracted GTO screening

            auto firstprim = spos[j];

            double rx = std::max({xmin - bfx[firstprim], bfx[firstprim] - xmax, 0.0});

            double ry = std::max({ymin - bfy[firstprim], bfy[firstprim] - ymax, 0.0});

            double rz = std::max({zmin - bfz[firstprim], bfz[firstprim] - zmax, 0.0});

            auto r2 = rx * rx + ry * ry + rz * rz;

            if (r2 > 1.0)
            {
                auto minexp = bfexps[firstprim];

                auto maxexp = bfexps[firstprim];

                auto maxcoef = std::fabs(bfnorms[firstprim]);

                for (int32_t iprim = spos[j]; iprim < epos[j]; iprim++)
                {
                    auto bexp = bfexps[iprim];

                    auto bnorm = std::fabs(bfnorms[iprim]);

                    minexp = std::min(minexp, bexp);

                    maxexp = std::max(maxexp, bexp);

                    maxcoef = std::max(maxcoef, bnorm);
                }

                // gto  :           r^{ang}   |C| exp(-alpha r^2)
                // gto_m:           r^{ang-1} |C| exp(-alpha r^2)
                // gto_p: (2 alpha) r^{ang+1} |C| exp(-alpha r^2)

                auto gtolimit = maxcoef * std::exp(-minexp * r2);

                auto r = std::sqrt(r2);

                for (int32_t ipow = 0; ipow < bang; ipow++) gtolimit *= r;

                if (gtoDeriv == 1) gtolimit = std::max(gtolimit, 2.0 * maxexp * r * gtolimit);

                if (gtolimit < _screeningThresholdForGTOValues)
                {
                    skipCgtoIds.data()[cgto_count] = 1;

                    auto bnspher = angmom::to_SphericalComponents(bang);

                    for (int32_t k = 0; k < bnspher; k++)
                    {
                        auto ao_idx = (bgtos.getIdentifiers(k))[j];

                        skipAOIds.data()[ao_idx] = 1;
                    }
                }
            }
        }
    }
}

CDenseMatrix
CXCNewIntegrator::_getSubDensityMatrix(const CAODensityMatrix&     densityMatrix,
                                       const int32_t               densityIndex,
                                       const std::vector<int32_t>& aoIndices,
                                       const int32_t               aoCount,
                                       const int32_t               nAOs) const
{
    if (aoCount <= nAOs)
    {
        CDenseMatrix sub_dens(aoCount, aoCount);

        const CDenseMatrix& dens = densityMatrix.getReferenceToDensity(densityIndex);

        for (int32_t i = 0; i < aoCount; i++)
        {
            auto sub_dens_row = sub_dens.row(i);

            auto dens_row = dens.row(aoIndices[i]);

            for (int32_t j = 0; j < aoCount; j++)
            {
                sub_dens_row[j] = dens_row[aoIndices[j]];
            }
        }

        return sub_dens;
    }

    return CDenseMatrix();
}

CDenseMatrix
CXCNewIntegrator::_integratePartialVxcFockForLDA(const int32_t          gridBlockPosition,
                                                 const int32_t          npoints,
                                                 const double*          weights,
                                                 const CDenseMatrix&    gtoValues,
                                                 const CXCGradientGrid& xcGradientGrid,
                                                 CMultiTimer&           timer) const
{
    // GTO values on grid points

    const CDenseMatrix& mat_chi = gtoValues;

    // exchange-correlation functional derivative

    auto grhoa = xcGradientGrid.xcGradientValues(xcvars::rhoa);

    // eq.(30), JCTC 2021, 17, 1512-1521

    timer.start("Vxc matrix G");

    auto naos = mat_chi.getNumberOfRows();

    CDenseMatrix mat_G(naos, npoints);

    mat_G.zero();

    for (int32_t nu = 0; nu < naos; nu++)
    {
        auto G_nu = mat_G.row(nu);

        auto chi_nu = mat_chi.row(nu);

        for (int32_t g = 0; g < npoints; g++)
        {
            G_nu[g] = weights[gridBlockPosition + g] * grhoa[g] * chi_nu[g];
        }
    }

    timer.stop("Vxc matrix G");

    // eq.(31), JCTC 2021, 17, 1512-1521

    timer.start("Vxc matrix matmul");

    auto mat_Vxc = denblas::multABt(mat_chi, mat_G);

    timer.stop("Vxc matrix matmul");

    return mat_Vxc;
}

CDenseMatrix
CXCNewIntegrator::_integratePartialVxcFockForGGA(const int32_t          gridblockpos,
                                                 const int32_t          npoints,
                                                 const double*          weights,
                                                 const CDenseMatrix&    gtoValues,
                                                 const CDenseMatrix&    gtoValuesX,
                                                 const CDenseMatrix&    gtoValuesY,
                                                 const CDenseMatrix&    gtoValuesZ,
                                                 const CXCGradientGrid& xcGradientGrid,
                                                 const CDensityGrid&    densityGrid,
                                                 CMultiTimer&           timer) const
{
    // GTO values on grid points

    const CDenseMatrix& mat_chi = gtoValues;

    const CDenseMatrix& mat_chi_x = gtoValuesX;

    const CDenseMatrix& mat_chi_y = gtoValuesY;

    const CDenseMatrix& mat_chi_z = gtoValuesZ;

    // exchange-correlation functional derivative

    auto grhoa = xcGradientGrid.xcGradientValues(xcvars::rhoa);

    auto ggrada = xcGradientGrid.xcGradientValues(xcvars::grada);

    auto ggradab = xcGradientGrid.xcGradientValues(xcvars::gradab);

    // pointers to density gradient norms

    auto ngrada = densityGrid.alphaDensityGradient(0);

    auto gradax = densityGrid.alphaDensityGradientX(0);

    auto graday = densityGrid.alphaDensityGradientY(0);

    auto gradaz = densityGrid.alphaDensityGradientZ(0);

    // eq.(30), JCTC 2021, 17, 1512-1521

    timer.start("Vxc matrix G");

    auto naos = mat_chi.getNumberOfRows();

    CDenseMatrix mat_G(naos, npoints);

    CDenseMatrix mat_G_gga(naos, npoints);

    mat_G.zero();

    mat_G_gga.zero();

    for (int32_t nu = 0; nu < naos; nu++)
    {
        auto G_nu = mat_G.row(nu);

        auto G_gga_nu = mat_G_gga.row(nu);

        auto chi_nu = mat_chi.row(nu);

        auto chi_x_nu = mat_chi_x.row(nu);

        auto chi_y_nu = mat_chi_y.row(nu);

        auto chi_z_nu = mat_chi_z.row(nu);

        for (int32_t g = 0; g < npoints; g++)
        {
            G_nu[g] = weights[gridblockpos + g] * grhoa[g] * chi_nu[g];

            G_gga_nu[g] = weights[gridblockpos + g] * (ggrada[g] / ngrada[g] + ggradab[g]) *

                          (gradax[g] * chi_x_nu[g] + graday[g] * chi_y_nu[g] + gradaz[g] * chi_z_nu[g]);
        }
    }

    timer.stop("Vxc matrix G");

    // eq.(31), JCTC 2021, 17, 1512-1521

    timer.start("Vxc matrix matmul");

    auto mat_Vxc = denblas::multABt(mat_chi, denblas::addAB(mat_G, mat_G_gga, 2.0));

    mat_Vxc.symmetrizeAndScale(0.5);

    timer.stop("Vxc matrix matmul");

    return mat_Vxc;
}

CDenseMatrix
CXCNewIntegrator::_integratePartialFxcFockForLDA(const int32_t         gridBlockPosition,
                                                 const int32_t         npoints,
                                                 const double*         weights,
                                                 const CDenseMatrix&   gtoValues,
                                                 const CXCHessianGrid& xcHessianGrid,
                                                 const CDensityGrid&   rwDensityGrid,
                                                 CMultiTimer&          timer) const
{
    // GTO values on grid points

    const CDenseMatrix& mat_chi = gtoValues;

    // pointers to exchange-correlation functional derivative

    auto grho_aa = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::rhoa);

    auto grho_ab = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::rhob);

    // pointers to perturbed density

    auto rhowa = rwDensityGrid.alphaDensity(0);

    auto rhowb = rwDensityGrid.betaDensity(0);

    // eq.(30), JCTC 2021, 17, 1512-1521

    timer.start("Fxc matrix G");

    auto naos = mat_chi.getNumberOfRows();

    CDenseMatrix mat_G(naos, npoints);

    mat_G.zero();

    for (int32_t nu = 0; nu < naos; nu++)
    {
        auto G_nu = mat_G.row(nu);

        auto chi_nu = mat_chi.row(nu);

        for (int32_t g = 0; g < npoints; g++)
        {
            G_nu[g] = weights[gridBlockPosition + g] *

                      (grho_aa[g] * rhowa[g] + grho_ab[g] * rhowb[g]) * chi_nu[g];
        }
    }

    timer.stop("Fxc matrix G");

    // eq.(31), JCTC 2021, 17, 1512-1521

    timer.start("Fxc matrix matmul");

    auto mat_Fxc = denblas::multABt(mat_chi, mat_G);

    timer.stop("Fxc matrix matmul");

    return mat_Fxc;
}

CDenseMatrix
CXCNewIntegrator::_integratePartialFxcFockForGGA(const int32_t          gridblockpos,
                                                 const int32_t          npoints,
                                                 const double*          weights,
                                                 const CDenseMatrix&    gtoValues,
                                                 const CDenseMatrix&    gtoValuesX,
                                                 const CDenseMatrix&    gtoValuesY,
                                                 const CDenseMatrix&    gtoValuesZ,
                                                 const CXCGradientGrid& xcGradientGrid,
                                                 const CXCHessianGrid&  xcHessianGrid,
                                                 const CDensityGrid&    rwDensityGrid,
                                                 const CDensityGrid&    gsDensityGrid,
                                                 CMultiTimer&           timer) const
{
    // GTO values on grid points

    auto chi_val = gtoValues.values();

    auto chi_x_val = gtoValuesX.values();

    auto chi_y_val = gtoValuesY.values();

    auto chi_z_val = gtoValuesZ.values();

    // pointers to exchange-correlation functional derrivatives

    auto grho_aa = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::rhoa);

    auto grho_ab = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::rhob);

    auto gmix_aa = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::grada);

    auto gmix_ab = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::gradb);

    auto gmix_ac = xcHessianGrid.xcHessianValues(xcvars::rhoa, xcvars::gradab);

    auto gmix_bc = xcHessianGrid.xcHessianValues(xcvars::rhob, xcvars::gradab);

    auto ggrad_aa = xcHessianGrid.xcHessianValues(xcvars::grada, xcvars::grada);

    auto ggrad_ab = xcHessianGrid.xcHessianValues(xcvars::grada, xcvars::gradb);

    auto ggrad_ac = xcHessianGrid.xcHessianValues(xcvars::grada, xcvars::gradab);

    auto ggrad_bc = xcHessianGrid.xcHessianValues(xcvars::gradb, xcvars::gradab);

    auto ggrad_cc = xcHessianGrid.xcHessianValues(xcvars::gradab, xcvars::gradab);

    auto ggrad_a = xcGradientGrid.xcGradientValues(xcvars::grada);

    auto ggrad_c = xcGradientGrid.xcGradientValues(xcvars::gradab);

    // pointers to ground state density gradient norms

    auto ngrada = gsDensityGrid.alphaDensityGradient(0);

    auto ngradb = gsDensityGrid.betaDensityGradient(0);

    auto grada_x = gsDensityGrid.alphaDensityGradientX(0);

    auto grada_y = gsDensityGrid.alphaDensityGradientY(0);

    auto grada_z = gsDensityGrid.alphaDensityGradientZ(0);

    auto gradb_x = gsDensityGrid.betaDensityGradientX(0);

    auto gradb_y = gsDensityGrid.betaDensityGradientY(0);

    auto gradb_z = gsDensityGrid.betaDensityGradientZ(0);

    // pointers to perturbed density gradient norms

    auto rhowa = rwDensityGrid.alphaDensity(0);

    auto rhowb = rwDensityGrid.betaDensity(0);

    auto gradwa_x = rwDensityGrid.alphaDensityGradientX(0);

    auto gradwa_y = rwDensityGrid.alphaDensityGradientY(0);

    auto gradwa_z = rwDensityGrid.alphaDensityGradientZ(0);

    auto gradwb_x = rwDensityGrid.betaDensityGradientX(0);

    auto gradwb_y = rwDensityGrid.betaDensityGradientY(0);

    auto gradwb_z = rwDensityGrid.betaDensityGradientZ(0);

    // eq.(30), JCTC 2021, 17, 1512-1521

    timer.start("Fxc matrix G");

    auto naos = gtoValues.getNumberOfRows();

    CDenseMatrix mat_G(naos, npoints);

    CDenseMatrix mat_G_gga(naos, npoints);

    mat_G.zero();

    mat_G_gga.zero();

    auto G_val = mat_G.values();

    auto G_gga_val = mat_G_gga.values();

    #pragma omp parallel
    {
        auto thread_id = omp_get_thread_num();

        auto nthreads = omp_get_max_threads();

        auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

        auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

        for (int32_t nu = 0; nu < naos; nu++)
        {
            auto nu_offset = nu * npoints;

            #pragma omp simd aligned(weights, ggrad_a, ggrad_c, grho_aa, grho_ab, \
                    gmix_aa, gmix_ab, gmix_ac, gmix_bc, ggrad_aa, ggrad_ab, ggrad_ac, ggrad_bc, ggrad_cc, \
                    ngrada, ngradb, grada_x, grada_y, grada_z, gradb_x, gradb_y, gradb_z, rhowa, rhowb, \
                    gradwa_x, gradwa_y, gradwa_z, gradwb_x, gradwb_y, gradwb_z, \
                    G_val, G_gga_val, chi_val, chi_x_val, chi_y_val, chi_z_val : VLX_ALIGN)
            for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
            {
                double w = weights[gridblockpos + g];

                double znva = 1.0 / ngrada[g];

                double znvb = 1.0 / ngradb[g];

                double rxa = znva * grada_x[g];

                double rya = znva * grada_y[g];

                double rza = znva * grada_z[g];

                double rxb = znvb * gradb_x[g];

                double ryb = znvb * gradb_y[g];

                double rzb = znvb * gradb_z[g];

                double rxwa = gradwa_x[g];

                double rywa = gradwa_y[g];

                double rzwa = gradwa_z[g];

                double rxwb = gradwb_x[g];

                double rywb = gradwb_y[g];

                double rzwb = gradwb_z[g];

                //  variations of functionals variables

                double zetaa = rxwa * rxa + rywa * rya + rzwa * rza;

                double zetab = rxwb * rxb + rywb * ryb + rzwb * rzb;

                double zetac = grada_x[g] * rxwb + grada_y[g] * rywb + grada_z[g] * rzwb +

                               gradb_x[g] * rxwa + gradb_y[g] * rywa + gradb_z[g] * rzwa;

                // first contribution

                double fac0 = gmix_aa[g] * zetaa + gmix_ab[g] * zetab + gmix_ac[g] * zetac +

                              grho_aa[g] * rhowa[g] + grho_ab[g] * rhowb[g];

                G_val[nu_offset + g] = w * fac0 * chi_val[nu_offset + g];

                double xcomp = 0.0, ycomp = 0.0, zcomp = 0.0;

                // second contribution

                double facr = gmix_aa[g] * rhowa[g] + gmix_ab[g] * rhowb[g] +

                              ggrad_aa[g] * zetaa + ggrad_ab[g] * zetab + ggrad_ac[g] * zetac;

                xcomp += facr * rxa;

                ycomp += facr * rya;

                zcomp += facr * rza;

                // third contribution

                double facz = gmix_ac[g] * rhowa[g] + gmix_bc[g] * rhowb[g] +

                              ggrad_ac[g] * zetaa + ggrad_bc[g] * zetab + ggrad_cc[g] * zetac;

                xcomp += facz * grada_x[g];

                ycomp += facz * grada_y[g];

                zcomp += facz * grada_z[g];

                // fourth contribution

                xcomp += znva * ggrad_a[g] * (rxwa - rxa * zetaa);

                ycomp += znva * ggrad_a[g] * (rywa - rya * zetaa);

                zcomp += znva * ggrad_a[g] * (rzwa - rza * zetaa);

                // fifth contribution

                xcomp += ggrad_c[g] * rxwa;

                ycomp += ggrad_c[g] * rywa;

                zcomp += ggrad_c[g] * rzwa;

                G_gga_val[nu_offset + g] = w * (xcomp * chi_x_val[nu_offset + g] +

                                                ycomp * chi_y_val[nu_offset + g] +

                                                zcomp * chi_z_val[nu_offset + g]);
            }
        }
    }

    timer.stop("Fxc matrix G");

    // eq.(31), JCTC 2021, 17, 1512-1521

    timer.start("Fxc matrix matmul");

    auto mat_Fxc = denblas::multABt(gtoValues, mat_G);

    auto mat_Fxc_gga = denblas::multABt(gtoValues, mat_G_gga);

    mat_Fxc_gga.symmetrize();  // matrix + matrix.T

    mat_Fxc = denblas::addAB(mat_Fxc, mat_Fxc_gga, 1.0);

    timer.stop("Fxc matrix matmul");

    return mat_Fxc;
}

void
CXCNewIntegrator::_distributeVxcMatrix(CAOKohnShamMatrix&          matVxc,
                                       const CDenseMatrix&         partialMatVxc,
                                       const std::vector<int32_t>& aoIndices,
                                       const int32_t               aoCount,
                                       const int32_t               nAOs) const
{
    if (aoCount <= nAOs)
    {
        for (int32_t row = 0; row < partialMatVxc.getNumberOfRows(); row++)
        {
            auto row_orig = aoIndices[row];

            auto matVxc_row_orig = matVxc.getMatrix(0) + row_orig * nAOs;

            auto partialMatVxc_row = partialMatVxc.row(row);

            for (int32_t col = 0; col < partialMatVxc.getNumberOfColumns(); col++)
            {
                auto col_orig = aoIndices[col];

                matVxc_row_orig[col_orig] += partialMatVxc_row[col];
            }
        }
    }
}

void
CXCNewIntegrator::_distributeFxcMatrix(CAOFockMatrix&              aoFockMatrix,
                                       const int32_t               fockIndex,
                                       const CDenseMatrix&         partialMatFxc,
                                       const std::vector<int32_t>& aoIndices,
                                       const int32_t               aoCount,
                                       const int32_t               nAOs) const
{
    if (aoCount <= nAOs)
    {
        for (int32_t row = 0; row < partialMatFxc.getNumberOfRows(); row++)
        {
            auto row_orig = aoIndices[row];

            auto fock_row_orig = aoFockMatrix.getFock(fockIndex, "ALPHA") + row_orig * nAOs;

            auto partialMatFxc_row = partialMatFxc.row(row);

            for (int32_t col = 0; col < partialMatFxc.getNumberOfColumns(); col++)
            {
                auto col_orig = aoIndices[col];

                fock_row_orig[col_orig] += partialMatFxc_row[col];
            }
        }
    }
}
