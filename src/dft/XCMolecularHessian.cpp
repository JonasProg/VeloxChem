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

#include "XCMolecularHessian.hpp"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "AODensityMatrix.hpp"
#include "AngularMomentum.hpp"
#include "DenseLinearAlgebra.hpp"
#include "DensityGridGenerator.hpp"
#include "DensityGridType.hpp"
#include "FunctionalParser.hpp"
#include "GridScreener.hpp"
#include "GtoEvaluator.hpp"
#include "SubMatrix.hpp"
#include "XCFuncType.hpp"

CXCMolecularHessian::CXCMolecularHessian(MPI_Comm comm)

    : _screeningThresholdForGTOValues(1.0e-12)
{
    _locRank = mpi::rank(comm);

    _locNodes = mpi::nodes(comm);

    _locComm = comm;
}

CDenseMatrix
CXCMolecularHessian::integrateVxcHessian(const CMolecule&        molecule,
                                         const CMolecularBasis&  basis,
                                         const CAODensityMatrix& gsDensityMatrix,
                                         const CMolecularGrid&   molecularGrid,
                                         const std::string&      xcFuncLabel) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (gsDensityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
            return _integrateVxcHessianForLDA(molecule, basis, gsDensityMatrix, molecularGrid, fvxc);
        }
        else
        {
            std::string errxcfuntype("XCMolecularHessian.integrateVxcHessian: Only implemented for LDA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCMolecularHessian.integrateVxcHessian: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    return CDenseMatrix();
}

CDenseMatrix
CXCMolecularHessian::integrateFxcHessian(const CMolecule&        molecule,
                                         const CMolecularBasis&  basis,
                                         const CAODensityMatrix& gsDensityMatrix,
                                         const CMolecularGrid&   molecularGrid,
                                         const std::string&      xcFuncLabel) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (gsDensityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
            return _integrateFxcHessianForLDA(molecule, basis, gsDensityMatrix, molecularGrid, fvxc);
        }
        else
        {
            std::string errxcfuntype("XCMolecularHessian.integrateFxcHessian: Only implemented for LDA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCMolecularHessian.integrateFxcHessian: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    return CDenseMatrix();
}

std::vector<CDenseMatrix>
CXCMolecularHessian::integrateVxcFockGradient(const CMolecule&        molecule,
                                              const CMolecularBasis&  basis,
                                              const CAODensityMatrix& gsDensityMatrix,
                                              const CMolecularGrid&   molecularGrid,
                                              const std::string&      xcFuncLabel,
                                              const int32_t           atomIdx) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (gsDensityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
            return _integrateVxcFockGradientForLDA(molecule, basis, gsDensityMatrix, molecularGrid, fvxc, atomIdx);
        }
        else
        {
            std::string errxcfuntype("XCMolecularHessian.integrateVxcFockGradient: Only implemented for LDA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCMolecularHessian.integrateVxcFockGradient: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    return std::vector<CDenseMatrix>();
}

std::vector<CDenseMatrix>
CXCMolecularHessian::integrateFxcFockGradient(const CMolecule&        molecule,
                                              const CMolecularBasis&  basis,
                                              const CAODensityMatrix& gsDensityMatrix,
                                              const CMolecularGrid&   molecularGrid,
                                              const std::string&      xcFuncLabel,
                                              const int32_t           atomIdx) const
{
    auto fvxc = vxcfuncs::getExchangeCorrelationFunctional(xcFuncLabel);

    auto xcfuntype = fvxc.getFunctionalType();

    if (gsDensityMatrix.isClosedShell())
    {
        if (xcfuntype == xcfun::lda)
        {
            return _integrateFxcFockGradientForLDA(molecule, basis, gsDensityMatrix, molecularGrid, fvxc, atomIdx);
        }
        else
        {
            std::string errxcfuntype("XCMolecularHessian.integrateFxcFockGradient: Only implemented for LDA");

            errors::assertMsgCritical(false, errxcfuntype);
        }
    }
    else
    {
        std::string erropenshell("XCMolecularHessian.integrateFxcFockGradient: Not implemented for open-shell");

        errors::assertMsgCritical(false, erropenshell);
    }

    return std::vector<CDenseMatrix>();
}

CDenseMatrix
CXCMolecularHessian::_integrateVxcHessianForLDA(const CMolecule&        molecule,
                                                const CMolecularBasis&  basis,
                                                const CAODensityMatrix& gsDensityMatrix,
                                                const CMolecularGrid&   molecularGrid,
                                                const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // molecular gradient

    auto natoms = molecule.getNumberOfAtoms();

    CMemBlock2D<double> molhess_threads((natoms * 3) * (natoms * 3), nthreads);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoxx(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaozz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> vrho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> weighted_vrho(molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho  = rho_data.data();
    auto vrho = vrho_data.data();

    auto w0 = weighted_vrho.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 2, _screeningThresholdForGTOValues, boxdim);  // 2nd order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForMetaGGA(gaos,
                                                 gaox,
                                                 gaoy,
                                                 gaoz,
                                                 gaoxx,
                                                 gaoxy,
                                                 gaoxz,
                                                 gaoyy,
                                                 gaoyz,
                                                 gaozz,
                                                 gtovec,
                                                 xcoords,
                                                 ycoords,
                                                 zcoords,
                                                 gridblockpos,
                                                 grid_batch_offset,
                                                 grid_batch_size,
                                                 skip_cgto_ids);
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

            auto gaoxx_nu = gaoxx.data(nu);
            auto gaoxy_nu = gaoxy.data(nu);
            auto gaoxz_nu = gaoxz.data(nu);
            auto gaoyy_nu = gaoyy.data(nu);
            auto gaoyz_nu = gaoyz.data(nu);
            auto gaozz_nu = gaozz.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxx_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoyy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoyz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaozz_nu[g]) > _screeningThresholdForGTOValues))
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

        CDenseMatrix mat_chi_xx(aocount, npoints);
        CDenseMatrix mat_chi_xy(aocount, npoints);
        CDenseMatrix mat_chi_xz(aocount, npoints);
        CDenseMatrix mat_chi_yy(aocount, npoints);
        CDenseMatrix mat_chi_yz(aocount, npoints);
        CDenseMatrix mat_chi_zz(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_xx.row(i), gaoxx.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xy.row(i), gaoxy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xz.row(i), gaoxz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yy.row(i), gaoyy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yz.row(i), gaoyz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_zz.row(i), gaozz.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        dengridgen::generateDensityForLDA(rho, npoints, mat_chi, gs_sub_dens_mat, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_vxc_for_lda(npoints, rho, vrho);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // eq.(26), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid matmul");

        auto D_val = gs_sub_dens_mat.values();

        auto mat_F = denblas::multAB(gs_sub_dens_mat, mat_chi);

        timer.stop("Density grad. grid matmul");

        // eq.(34), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid rho");

        auto naos = mat_chi.getNumberOfRows();

        auto F_val = mat_F.values();

        auto chi_x_val = mat_chi_x.values();
        auto chi_y_val = mat_chi_y.values();
        auto chi_z_val = mat_chi_z.values();

        auto chi_xx_val = mat_chi_xx.values();
        auto chi_xy_val = mat_chi_xy.values();
        auto chi_xz_val = mat_chi_xz.values();
        auto chi_yy_val = mat_chi_yy.values();
        auto chi_yz_val = mat_chi_yz.values();
        auto chi_zz_val = mat_chi_zz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            auto gatm = molhess_threads.data(thread_id);

            #pragma omp simd aligned(local_weights, vrho, w0 : VLX_ALIGN)
            for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
            {
                w0[g] = local_weights[g] * vrho[2 * g + 0];
            }

            for (int32_t mu = 0; mu < naos; mu++)
            {
                auto iatom = ao_to_atom_ids[aoinds[mu]];

                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto mu_offset = mu * npoints;

                double gatmxx = 0.0, gatmxy = 0.0, gatmxz = 0.0;
                double gatmyx = 0.0, gatmyy = 0.0, gatmyz = 0.0;
                double gatmzx = 0.0, gatmzy = 0.0, gatmzz = 0.0;

                #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) \
                        aligned(w0, F_val, chi_xx_val, chi_xy_val, chi_xz_val, chi_yy_val, chi_yz_val, chi_zz_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto mu_g = mu_offset + g;

                    gatmxx += w0[g] * (F_val[mu_g] * chi_xx_val[mu_g]);
                    gatmxy += w0[g] * (F_val[mu_g] * chi_xy_val[mu_g]);
                    gatmxz += w0[g] * (F_val[mu_g] * chi_xz_val[mu_g]);

                    gatmyx += w0[g] * (F_val[mu_g] * chi_xy_val[mu_g]);
                    gatmyy += w0[g] * (F_val[mu_g] * chi_yy_val[mu_g]);
                    gatmyz += w0[g] * (F_val[mu_g] * chi_yz_val[mu_g]);

                    gatmzx += w0[g] * (F_val[mu_g] * chi_xz_val[mu_g]);
                    gatmzy += w0[g] * (F_val[mu_g] * chi_yz_val[mu_g]);
                    gatmzz += w0[g] * (F_val[mu_g] * chi_zz_val[mu_g]);
                }

                // factor of 2 from differentiation
                // factor of 2 from sum of alpha and beta contributions

                gatm[ix * (natoms * 3) + ix] += 4.0 * gatmxx;
                gatm[ix * (natoms * 3) + iy] += 4.0 * gatmxy;
                gatm[ix * (natoms * 3) + iz] += 4.0 * gatmxz;

                gatm[iy * (natoms * 3) + ix] += 4.0 * gatmyx;
                gatm[iy * (natoms * 3) + iy] += 4.0 * gatmyy;
                gatm[iy * (natoms * 3) + iz] += 4.0 * gatmyz;

                gatm[iz * (natoms * 3) + ix] += 4.0 * gatmzx;
                gatm[iz * (natoms * 3) + iy] += 4.0 * gatmzy;
                gatm[iz * (natoms * 3) + iz] += 4.0 * gatmzz;
            }

            for (int32_t mu = 0; mu < naos; mu++)
            {
                auto iatom = ao_to_atom_ids[aoinds[mu]];

                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto mu_offset = mu * npoints;

                for (int32_t nu = 0; nu < naos; nu++)
                {
                    auto jatom = ao_to_atom_ids[aoinds[nu]];

                    // only consider the upper triangular part, e.g. iatom <= jatom

                    if (iatom > jatom) continue;

                    auto jx = jatom * 3 + 0;
                    auto jy = jatom * 3 + 1;
                    auto jz = jatom * 3 + 2;

                    auto nu_offset = nu * npoints;

                    auto D_mn = D_val[mu * naos + nu];

                    double gatmxx = 0.0, gatmxy = 0.0, gatmxz = 0.0;
                    double gatmyx = 0.0, gatmyy = 0.0, gatmyz = 0.0;
                    double gatmzx = 0.0, gatmzy = 0.0, gatmzz = 0.0;

                    #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) \
                            aligned(w0, chi_x_val, chi_y_val, chi_z_val : VLX_ALIGN)
                    for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                    {
                        auto mu_g = mu_offset + g;
                        auto nu_g = nu_offset + g;

                        gatmxx += w0[g] * chi_x_val[mu_g] * chi_x_val[nu_g];
                        gatmxy += w0[g] * chi_x_val[mu_g] * chi_y_val[nu_g];
                        gatmxz += w0[g] * chi_x_val[mu_g] * chi_z_val[nu_g];

                        gatmyx += w0[g] * chi_y_val[mu_g] * chi_x_val[nu_g];
                        gatmyy += w0[g] * chi_y_val[mu_g] * chi_y_val[nu_g];
                        gatmyz += w0[g] * chi_y_val[mu_g] * chi_z_val[nu_g];

                        gatmzx += w0[g] * chi_z_val[mu_g] * chi_x_val[nu_g];
                        gatmzy += w0[g] * chi_z_val[mu_g] * chi_y_val[nu_g];
                        gatmzz += w0[g] * chi_z_val[mu_g] * chi_z_val[nu_g];
                    }

                    // factor of 2 from differentiation
                    // factor of 2 from sum of alpha and beta contributions

                    gatm[ix * (natoms * 3) + jx] += 4.0 * gatmxx * D_mn;
                    gatm[ix * (natoms * 3) + jy] += 4.0 * gatmxy * D_mn;
                    gatm[ix * (natoms * 3) + jz] += 4.0 * gatmxz * D_mn;

                    gatm[iy * (natoms * 3) + jx] += 4.0 * gatmyx * D_mn;
                    gatm[iy * (natoms * 3) + jy] += 4.0 * gatmyy * D_mn;
                    gatm[iy * (natoms * 3) + jz] += 4.0 * gatmyz * D_mn;

                    gatm[iz * (natoms * 3) + jx] += 4.0 * gatmzx * D_mn;
                    gatm[iz * (natoms * 3) + jy] += 4.0 * gatmzy * D_mn;
                    gatm[iz * (natoms * 3) + jz] += 4.0 * gatmzz * D_mn;
                }
            }
        }

        timer.stop("Density grad. grid rho");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;

    CDenseMatrix molhess(natoms * 3, natoms * 3);

    for (int32_t iatom = 0; iatom < natoms; iatom++)
    {
        auto ix = iatom * 3 + 0;
        auto iy = iatom * 3 + 1;
        auto iz = iatom * 3 + 2;

        for (int32_t jatom = iatom; jatom < natoms; jatom++)
        {
            auto jx = jatom * 3 + 0;
            auto jy = jatom * 3 + 1;
            auto jz = jatom * 3 + 2;

            for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
            {
                molhess.row(ix)[jx] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jx];
                molhess.row(ix)[jy] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jy];
                molhess.row(ix)[jz] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jz];

                molhess.row(iy)[jx] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jx];
                molhess.row(iy)[jy] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jy];
                molhess.row(iy)[jz] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jz];

                molhess.row(iz)[jx] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jx];
                molhess.row(iz)[jy] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jy];
                molhess.row(iz)[jz] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jz];
            }

            if (jatom != iatom)
            {
                molhess.row(jx)[ix] = molhess.row(ix)[jx];
                molhess.row(jx)[iy] = molhess.row(iy)[jx];
                molhess.row(jx)[iz] = molhess.row(iz)[jx];

                molhess.row(jy)[ix] = molhess.row(ix)[jy];
                molhess.row(jy)[iy] = molhess.row(iy)[jy];
                molhess.row(jy)[iz] = molhess.row(iz)[jy];

                molhess.row(jz)[ix] = molhess.row(ix)[jz];
                molhess.row(jz)[iy] = molhess.row(iy)[jz];
                molhess.row(jz)[iz] = molhess.row(iz)[jz];
            }
        }
    }

    return molhess;
}

CDenseMatrix
CXCMolecularHessian::_integrateVxcHessianForGGA(const CMolecule&        molecule,
                                                const CMolecularBasis&  basis,
                                                const CAODensityMatrix& gsDensityMatrix,
                                                const CMolecularGrid&   molecularGrid,
                                                const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // molecular gradient

    auto natoms = molecule.getNumberOfAtoms();

    CMemBlock2D<double> molhess_threads((natoms * 3) * (natoms * 3), nthreads);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoxx(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaozz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoxxx(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxxy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxxz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxyy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxyz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxzz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyyy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyyz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyzz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaozzz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> rhograd_data(6 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> sigma_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> vrho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> vsigma_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> weighted_vrho(molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> weighted_vnabla_x(molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> weighted_vnabla_y(molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> weighted_vnabla_z(molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho     = rho_data.data();
    auto rhograd = rhograd_data.data();
    auto sigma   = sigma_data.data();

    auto vrho   = vrho_data.data();
    auto vsigma = vsigma_data.data();

    auto w0 = weighted_vrho.data();
    auto wx = weighted_vnabla_x.data();
    auto wy = weighted_vnabla_y.data();
    auto wz = weighted_vnabla_z.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 2, _screeningThresholdForGTOValues, boxdim);  // 2nd order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForThirdOrder(gaos,
                                                    gaox,
                                                    gaoy,
                                                    gaoz,
                                                    gaoxx,
                                                    gaoxy,
                                                    gaoxz,
                                                    gaoyy,
                                                    gaoyz,
                                                    gaozz,
                                                    gaoxxx,
                                                    gaoxxy,
                                                    gaoxxz,
                                                    gaoxyy,
                                                    gaoxyz,
                                                    gaoxzz,
                                                    gaoyyy,
                                                    gaoyyz,
                                                    gaoyzz,
                                                    gaozzz,
                                                    gtovec,
                                                    xcoords,
                                                    ycoords,
                                                    zcoords,
                                                    gridblockpos,
                                                    grid_batch_offset,
                                                    grid_batch_size,
                                                    skip_cgto_ids);
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

            auto gaoxx_nu = gaoxx.data(nu);
            auto gaoxy_nu = gaoxy.data(nu);
            auto gaoxz_nu = gaoxz.data(nu);
            auto gaoyy_nu = gaoyy.data(nu);
            auto gaoyz_nu = gaoyz.data(nu);
            auto gaozz_nu = gaozz.data(nu);

            auto gaoxxx_nu = gaoxxx.data(nu);
            auto gaoxxy_nu = gaoxxy.data(nu);
            auto gaoxxz_nu = gaoxxz.data(nu);
            auto gaoxyy_nu = gaoxyy.data(nu);
            auto gaoxyz_nu = gaoxyz.data(nu);
            auto gaoxzz_nu = gaoxzz.data(nu);
            auto gaoyyy_nu = gaoyyy.data(nu);
            auto gaoyyz_nu = gaoyyz.data(nu);
            auto gaoyzz_nu = gaoyzz.data(nu);
            auto gaozzz_nu = gaozzz.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxx_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoyy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoyz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaozz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxxx_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxxy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxxz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxyy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxyz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxzz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoyyy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoyyz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoyzz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaozzz_nu[g]) > _screeningThresholdForGTOValues))
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

        CDenseMatrix mat_chi_xx(aocount, npoints);
        CDenseMatrix mat_chi_xy(aocount, npoints);
        CDenseMatrix mat_chi_xz(aocount, npoints);
        CDenseMatrix mat_chi_yy(aocount, npoints);
        CDenseMatrix mat_chi_yz(aocount, npoints);
        CDenseMatrix mat_chi_zz(aocount, npoints);

        CDenseMatrix mat_chi_xxx(aocount, npoints);
        CDenseMatrix mat_chi_xxy(aocount, npoints);
        CDenseMatrix mat_chi_xxz(aocount, npoints);
        CDenseMatrix mat_chi_xyy(aocount, npoints);
        CDenseMatrix mat_chi_xyz(aocount, npoints);
        CDenseMatrix mat_chi_xzz(aocount, npoints);
        CDenseMatrix mat_chi_yyy(aocount, npoints);
        CDenseMatrix mat_chi_yyz(aocount, npoints);
        CDenseMatrix mat_chi_yzz(aocount, npoints);
        CDenseMatrix mat_chi_zzz(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_xx.row(i), gaoxx.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xy.row(i), gaoxy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xz.row(i), gaoxz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yy.row(i), gaoyy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yz.row(i), gaoyz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_zz.row(i), gaozz.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_xxx.row(i), gaoxxx.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xxy.row(i), gaoxxy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xxz.row(i), gaoxxz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xyy.row(i), gaoxyy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xyz.row(i), gaoxyz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xzz.row(i), gaoxzz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yyy.row(i), gaoyyy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yyz.row(i), gaoyyz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yzz.row(i), gaoyzz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_zzz.row(i), gaozzz.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        dengridgen::generateDensityForGGA(rho, rhograd, sigma, npoints, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z, gs_sub_dens_mat, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_vxc_for_gga(npoints, rho, sigma, vrho, vsigma);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // eq.(26), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid matmul");

        auto D_val = gs_sub_dens_mat.values();

        auto mat_F = denblas::multAB(gs_sub_dens_mat, mat_chi);

        auto mat_F_x = denblas::multAB(gs_sub_dens_mat, mat_chi_x);
        auto mat_F_y = denblas::multAB(gs_sub_dens_mat, mat_chi_y);
        auto mat_F_z = denblas::multAB(gs_sub_dens_mat, mat_chi_z);

        timer.stop("Density grad. grid matmul");

        // eq.(34), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid rho");

        auto naos = mat_chi.getNumberOfRows();

        auto F_val = mat_F.values();

        auto F_x_val = mat_F_x.values();
        auto F_y_val = mat_F_y.values();
        auto F_z_val = mat_F_z.values();

        auto chi_x_val = mat_chi_x.values();
        auto chi_y_val = mat_chi_y.values();
        auto chi_z_val = mat_chi_z.values();

        auto chi_xx_val = mat_chi_xx.values();
        auto chi_xy_val = mat_chi_xy.values();
        auto chi_xz_val = mat_chi_xz.values();
        auto chi_yy_val = mat_chi_yy.values();
        auto chi_yz_val = mat_chi_yz.values();
        auto chi_zz_val = mat_chi_zz.values();

        auto chi_xxx_val = mat_chi_xxx.values();
        auto chi_xxy_val = mat_chi_xxy.values();
        auto chi_xxz_val = mat_chi_xxz.values();
        auto chi_xyy_val = mat_chi_xyy.values();
        auto chi_xyz_val = mat_chi_xyz.values();
        auto chi_xzz_val = mat_chi_xzz.values();
        auto chi_yyy_val = mat_chi_yyy.values();
        auto chi_yyz_val = mat_chi_yyz.values();
        auto chi_yzz_val = mat_chi_yzz.values();
        auto chi_zzz_val = mat_chi_zzz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            auto gatm = molhess_threads.data(thread_id);

            #pragma omp simd aligned(local_weights, rhograd, vrho, vsigma, w0, wx, wy, wz : VLX_ALIGN)
            for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
            {
                w0[g] = local_weights[g] * vrho[2 * g + 0];

                auto vx = 2.0 * vsigma[3 * g + 0] * rhograd[6 * g + 0] + vsigma[3 * g + 1] * rhograd[6 * g + 3];
                auto vy = 2.0 * vsigma[3 * g + 0] * rhograd[6 * g + 1] + vsigma[3 * g + 1] * rhograd[6 * g + 4];
                auto vz = 2.0 * vsigma[3 * g + 0] * rhograd[6 * g + 2] + vsigma[3 * g + 1] * rhograd[6 * g + 5];

                wx[g] = local_weights[g] * vx;
                wy[g] = local_weights[g] * vy;
                wz[g] = local_weights[g] * vz;
            }

            for (int32_t mu = 0; mu < naos; mu++)
            {
                auto iatom = ao_to_atom_ids[aoinds[mu]];

                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto mu_offset = mu * npoints;

                double gatmxx = 0.0, gatmxy = 0.0, gatmxz = 0.0;
                double gatmyx = 0.0, gatmyy = 0.0, gatmyz = 0.0;
                double gatmzx = 0.0, gatmzy = 0.0, gatmzz = 0.0;

                #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) \
                        aligned(w0, wx, wy, wz, F_val, F_x_val, F_y_val, F_z_val, \
                        chi_xx_val, chi_xy_val, chi_xz_val, chi_yy_val, chi_yz_val, chi_zz_val, \
                        chi_xxx_val, chi_xxy_val, chi_xxz_val, chi_xyy_val, chi_xyz_val, \
                        chi_xzz_val, chi_yyy_val, chi_yyz_val, chi_yzz_val, chi_zzz_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto mu_g = mu_offset + g;

                    double gdenxx = 0.0, gdenxy = 0.0, gdenxz = 0.0;
                    double gdenyx = 0.0, gdenyy = 0.0, gdenyz = 0.0;
                    double gdenzx = 0.0, gdenzy = 0.0, gdenzz = 0.0;

                    gdenxx += F_val[mu_g] * chi_xx_val[mu_g];
                    gdenxy += F_val[mu_g] * chi_xy_val[mu_g];
                    gdenxz += F_val[mu_g] * chi_xz_val[mu_g];

                    gdenyx += F_val[mu_g] * chi_xy_val[mu_g];
                    gdenyy += F_val[mu_g] * chi_yy_val[mu_g];
                    gdenyz += F_val[mu_g] * chi_yz_val[mu_g];

                    gdenzx += F_val[mu_g] * chi_xz_val[mu_g];
                    gdenzy += F_val[mu_g] * chi_yz_val[mu_g];
                    gdenzz += F_val[mu_g] * chi_zz_val[mu_g];

                    // === x ===

                    double gdenxxx = 0.0, gdenxxy = 0.0, gdenxxz = 0.0;
                    double gdenyxx = 0.0, gdenyxy = 0.0, gdenyxz = 0.0;
                    double gdenzxx = 0.0, gdenzxy = 0.0, gdenzxz = 0.0;

                    gdenxxx += F_x_val[mu_g] * chi_xx_val[mu_g] + F_val[mu_g] * chi_xxx_val[mu_g];
                    gdenxxy += F_x_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xxy_val[mu_g];
                    gdenxxz += F_x_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xxz_val[mu_g];

                    gdenyxx += F_y_val[mu_g] * chi_xx_val[mu_g] + F_val[mu_g] * chi_xxy_val[mu_g];
                    gdenyxy += F_y_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xyy_val[mu_g];
                    gdenyxz += F_y_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];

                    gdenzxx += F_z_val[mu_g] * chi_xx_val[mu_g] + F_val[mu_g] * chi_xxz_val[mu_g];
                    gdenzxy += F_z_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];
                    gdenzxz += F_z_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xzz_val[mu_g];

                    // === y ===

                    double gdenxyx = 0.0, gdenxyy = 0.0, gdenxyz = 0.0;
                    double gdenyyx = 0.0, gdenyyy = 0.0, gdenyyz = 0.0;
                    double gdenzyx = 0.0, gdenzyy = 0.0, gdenzyz = 0.0;

                    gdenxyx += F_x_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xxy_val[mu_g];
                    gdenxyy += F_x_val[mu_g] * chi_yy_val[mu_g] + F_val[mu_g] * chi_xyy_val[mu_g];
                    gdenxyz += F_x_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];

                    gdenyyx += F_y_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xyy_val[mu_g];
                    gdenyyy += F_y_val[mu_g] * chi_yy_val[mu_g] + F_val[mu_g] * chi_yyy_val[mu_g];
                    gdenyyz += F_y_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_yyz_val[mu_g];

                    gdenzyx += F_z_val[mu_g] * chi_xy_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];
                    gdenzyy += F_z_val[mu_g] * chi_yy_val[mu_g] + F_val[mu_g] * chi_yyz_val[mu_g];
                    gdenzyz += F_z_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_yzz_val[mu_g];

                    // === z ===

                    double gdenxzx = 0.0, gdenxzy = 0.0, gdenxzz = 0.0;
                    double gdenyzx = 0.0, gdenyzy = 0.0, gdenyzz = 0.0;
                    double gdenzzx = 0.0, gdenzzy = 0.0, gdenzzz = 0.0;

                    gdenxzx += F_x_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xxz_val[mu_g];
                    gdenxzy += F_x_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];
                    gdenxzz += F_x_val[mu_g] * chi_zz_val[mu_g] + F_val[mu_g] * chi_xzz_val[mu_g];

                    gdenyzx += F_y_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xyz_val[mu_g];
                    gdenyzy += F_y_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_yyz_val[mu_g];
                    gdenyzz += F_y_val[mu_g] * chi_zz_val[mu_g] + F_val[mu_g] * chi_yzz_val[mu_g];

                    gdenzzx += F_z_val[mu_g] * chi_xz_val[mu_g] + F_val[mu_g] * chi_xzz_val[mu_g];
                    gdenzzy += F_z_val[mu_g] * chi_yz_val[mu_g] + F_val[mu_g] * chi_yzz_val[mu_g];
                    gdenzzz += F_z_val[mu_g] * chi_zz_val[mu_g] + F_val[mu_g] * chi_zzz_val[mu_g];

                    gatmxx += w0[g] * gdenxx + (wx[g] * gdenxxx + wy[g] * gdenyxx + wz[g] * gdenzxx);
                    gatmxy += w0[g] * gdenxy + (wx[g] * gdenxxy + wy[g] * gdenyxy + wz[g] * gdenzxy);
                    gatmxz += w0[g] * gdenxz + (wx[g] * gdenxxz + wy[g] * gdenyxz + wz[g] * gdenzxz);

                    gatmyx += w0[g] * gdenyx + (wx[g] * gdenxyx + wy[g] * gdenyyx + wz[g] * gdenzyx);
                    gatmyy += w0[g] * gdenyy + (wx[g] * gdenxyy + wy[g] * gdenyyy + wz[g] * gdenzyy);
                    gatmyz += w0[g] * gdenyz + (wx[g] * gdenxyz + wy[g] * gdenyyz + wz[g] * gdenzyz);

                    gatmzx += w0[g] * gdenzx + (wx[g] * gdenxzx + wy[g] * gdenyzx + wz[g] * gdenzzx);
                    gatmzy += w0[g] * gdenzy + (wx[g] * gdenxzy + wy[g] * gdenyzy + wz[g] * gdenzzy);
                    gatmzz += w0[g] * gdenzz + (wx[g] * gdenxzz + wy[g] * gdenyzz + wz[g] * gdenzzz);
                }

                // factor of 2 from differentiation
                // factor of 2 from sum of alpha and beta contributions

                gatm[ix * (natoms * 3) + ix] += 4.0 * gatmxx;
                gatm[ix * (natoms * 3) + iy] += 4.0 * gatmxy;
                gatm[ix * (natoms * 3) + iz] += 4.0 * gatmxz;

                gatm[iy * (natoms * 3) + ix] += 4.0 * gatmyx;
                gatm[iy * (natoms * 3) + iy] += 4.0 * gatmyy;
                gatm[iy * (natoms * 3) + iz] += 4.0 * gatmyz;

                gatm[iz * (natoms * 3) + ix] += 4.0 * gatmzx;
                gatm[iz * (natoms * 3) + iy] += 4.0 * gatmzy;
                gatm[iz * (natoms * 3) + iz] += 4.0 * gatmzz;
            }

            for (int32_t mu = 0; mu < naos; mu++)
            {
                auto iatom = ao_to_atom_ids[aoinds[mu]];

                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto mu_offset = mu * npoints;

                for (int32_t nu = 0; nu < naos; nu++)
                {
                    auto jatom = ao_to_atom_ids[aoinds[nu]];

                    // only consider the upper triangular part, e.g. iatom <= jatom

                    if (iatom > jatom) continue;

                    auto jx = jatom * 3 + 0;
                    auto jy = jatom * 3 + 1;
                    auto jz = jatom * 3 + 2;

                    auto nu_offset = nu * npoints;

                    auto D_mn = D_val[mu * naos + nu];

                    double gatmxx = 0.0, gatmxy = 0.0, gatmxz = 0.0;
                    double gatmyx = 0.0, gatmyy = 0.0, gatmyz = 0.0;
                    double gatmzx = 0.0, gatmzy = 0.0, gatmzz = 0.0;

                    #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) \
                            aligned(w0, wx, wy, wz, chi_x_val, chi_y_val, chi_z_val, \
                            chi_xx_val, chi_xy_val, chi_xz_val, chi_yy_val, chi_yz_val, chi_zz_val : VLX_ALIGN)
                    for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                    {
                        auto mu_g = mu_offset + g;
                        auto nu_g = nu_offset + g;

                        double gxx = 0.0, gxy = 0.0, gxz = 0.0;
                        double gyx = 0.0, gyy = 0.0, gyz = 0.0;
                        double gzx = 0.0, gzy = 0.0, gzz = 0.0;

                        gxx += chi_x_val[mu_g] * chi_x_val[nu_g];
                        gxy += chi_x_val[mu_g] * chi_y_val[nu_g];
                        gxz += chi_x_val[mu_g] * chi_z_val[nu_g];

                        gyx += chi_y_val[mu_g] * chi_x_val[nu_g];
                        gyy += chi_y_val[mu_g] * chi_y_val[nu_g];
                        gyz += chi_y_val[mu_g] * chi_z_val[nu_g];

                        gzx += chi_z_val[mu_g] * chi_x_val[nu_g];
                        gzy += chi_z_val[mu_g] * chi_y_val[nu_g];
                        gzz += chi_z_val[mu_g] * chi_z_val[nu_g];

                        // === x ===

                        double gxxx = 0.0, gxxy = 0.0, gxxz = 0.0;
                        double gyxx = 0.0, gyxy = 0.0, gyxz = 0.0;
                        double gzxx = 0.0, gzxy = 0.0, gzxz = 0.0;

                        gxxx += chi_xx_val[mu_g] * chi_x_val[nu_g];
                        gxxy += chi_xx_val[mu_g] * chi_y_val[nu_g];
                        gxxz += chi_xx_val[mu_g] * chi_z_val[nu_g];
                        gyxx += chi_xy_val[mu_g] * chi_x_val[nu_g];
                        gyxy += chi_xy_val[mu_g] * chi_y_val[nu_g];
                        gyxz += chi_xy_val[mu_g] * chi_z_val[nu_g];
                        gzxx += chi_xz_val[mu_g] * chi_x_val[nu_g];
                        gzxy += chi_xz_val[mu_g] * chi_y_val[nu_g];
                        gzxz += chi_xz_val[mu_g] * chi_z_val[nu_g];

                        gxxx += chi_x_val[mu_g] * chi_xx_val[nu_g];
                        gxxy += chi_x_val[mu_g] * chi_xy_val[nu_g];
                        gxxz += chi_x_val[mu_g] * chi_xz_val[nu_g];
                        gyxx += chi_x_val[mu_g] * chi_xy_val[nu_g];
                        gyxy += chi_x_val[mu_g] * chi_yy_val[nu_g];
                        gyxz += chi_x_val[mu_g] * chi_yz_val[nu_g];
                        gzxx += chi_x_val[mu_g] * chi_xz_val[nu_g];
                        gzxy += chi_x_val[mu_g] * chi_yz_val[nu_g];
                        gzxz += chi_x_val[mu_g] * chi_zz_val[nu_g];

                        // === y ===

                        double gxyx = 0.0, gxyy = 0.0, gxyz = 0.0;
                        double gyyx = 0.0, gyyy = 0.0, gyyz = 0.0;
                        double gzyx = 0.0, gzyy = 0.0, gzyz = 0.0;

                        gxyx += chi_xy_val[mu_g] * chi_x_val[nu_g];
                        gxyy += chi_xy_val[mu_g] * chi_y_val[nu_g];
                        gxyz += chi_xy_val[mu_g] * chi_z_val[nu_g];
                        gyyx += chi_yy_val[mu_g] * chi_x_val[nu_g];
                        gyyy += chi_yy_val[mu_g] * chi_y_val[nu_g];
                        gyyz += chi_yy_val[mu_g] * chi_z_val[nu_g];
                        gzyx += chi_yz_val[mu_g] * chi_x_val[nu_g];
                        gzyy += chi_yz_val[mu_g] * chi_y_val[nu_g];
                        gzyz += chi_yz_val[mu_g] * chi_z_val[nu_g];

                        gxyx += chi_y_val[mu_g] * chi_xx_val[nu_g];
                        gxyy += chi_y_val[mu_g] * chi_xy_val[nu_g];
                        gxyz += chi_y_val[mu_g] * chi_xz_val[nu_g];
                        gyyx += chi_y_val[mu_g] * chi_xy_val[nu_g];
                        gyyy += chi_y_val[mu_g] * chi_yy_val[nu_g];
                        gyyz += chi_y_val[mu_g] * chi_yz_val[nu_g];
                        gzyx += chi_y_val[mu_g] * chi_xz_val[nu_g];
                        gzyy += chi_y_val[mu_g] * chi_yz_val[nu_g];
                        gzyz += chi_y_val[mu_g] * chi_zz_val[nu_g];

                        // === z ===

                        double gxzx = 0.0, gxzy = 0.0, gxzz = 0.0;
                        double gyzx = 0.0, gyzy = 0.0, gyzz = 0.0;
                        double gzzx = 0.0, gzzy = 0.0, gzzz = 0.0;

                        gxzx += chi_xz_val[mu_g] * chi_x_val[nu_g];
                        gxzy += chi_xz_val[mu_g] * chi_y_val[nu_g];
                        gxzz += chi_xz_val[mu_g] * chi_z_val[nu_g];
                        gyzx += chi_yz_val[mu_g] * chi_x_val[nu_g];
                        gyzy += chi_yz_val[mu_g] * chi_y_val[nu_g];
                        gyzz += chi_yz_val[mu_g] * chi_z_val[nu_g];
                        gzzx += chi_zz_val[mu_g] * chi_x_val[nu_g];
                        gzzy += chi_zz_val[mu_g] * chi_y_val[nu_g];
                        gzzz += chi_zz_val[mu_g] * chi_z_val[nu_g];

                        gxzx += chi_z_val[mu_g] * chi_xx_val[nu_g];
                        gxzy += chi_z_val[mu_g] * chi_xy_val[nu_g];
                        gxzz += chi_z_val[mu_g] * chi_xz_val[nu_g];
                        gyzx += chi_z_val[mu_g] * chi_xy_val[nu_g];
                        gyzy += chi_z_val[mu_g] * chi_yy_val[nu_g];
                        gyzz += chi_z_val[mu_g] * chi_yz_val[nu_g];
                        gzzx += chi_z_val[mu_g] * chi_xz_val[nu_g];
                        gzzy += chi_z_val[mu_g] * chi_yz_val[nu_g];
                        gzzz += chi_z_val[mu_g] * chi_zz_val[nu_g];

                        gatmxx += w0[g] * gxx + (wx[g] * gxxx + wy[g] * gyxx + wz[g] * gzxx);
                        gatmxy += w0[g] * gxy + (wx[g] * gxxy + wy[g] * gyxy + wz[g] * gzxy);
                        gatmxz += w0[g] * gxz + (wx[g] * gxxz + wy[g] * gyxz + wz[g] * gzxz);

                        gatmyx += w0[g] * gyx + (wx[g] * gxyx + wy[g] * gyyx + wz[g] * gzyx);
                        gatmyy += w0[g] * gyy + (wx[g] * gxyy + wy[g] * gyyy + wz[g] * gzyy);
                        gatmyz += w0[g] * gyz + (wx[g] * gxyz + wy[g] * gyyz + wz[g] * gzyz);

                        gatmzx += w0[g] * gzx + (wx[g] * gxzx + wy[g] * gyzx + wz[g] * gzzx);
                        gatmzy += w0[g] * gzy + (wx[g] * gxzy + wy[g] * gyzy + wz[g] * gzzy);
                        gatmzz += w0[g] * gzz + (wx[g] * gxzz + wy[g] * gyzz + wz[g] * gzzz);
                    }

                    // factor of 2 from differentiation
                    // factor of 2 from sum of alpha and beta contributions

                    gatm[ix * (natoms * 3) + jx] += 4.0 * gatmxx * D_mn;
                    gatm[ix * (natoms * 3) + jy] += 4.0 * gatmxy * D_mn;
                    gatm[ix * (natoms * 3) + jz] += 4.0 * gatmxz * D_mn;

                    gatm[iy * (natoms * 3) + jx] += 4.0 * gatmyx * D_mn;
                    gatm[iy * (natoms * 3) + jy] += 4.0 * gatmyy * D_mn;
                    gatm[iy * (natoms * 3) + jz] += 4.0 * gatmyz * D_mn;

                    gatm[iz * (natoms * 3) + jx] += 4.0 * gatmzx * D_mn;
                    gatm[iz * (natoms * 3) + jy] += 4.0 * gatmzy * D_mn;
                    gatm[iz * (natoms * 3) + jz] += 4.0 * gatmzz * D_mn;
                }
            }
        }

        timer.stop("Density grad. grid rho");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;

    CDenseMatrix molhess(natoms * 3, natoms * 3);

    for (int32_t iatom = 0; iatom < natoms; iatom++)
    {
        auto ix = iatom * 3 + 0;
        auto iy = iatom * 3 + 1;
        auto iz = iatom * 3 + 2;

        for (int32_t jatom = iatom; jatom < natoms; jatom++)
        {
            auto jx = jatom * 3 + 0;
            auto jy = jatom * 3 + 1;
            auto jz = jatom * 3 + 2;

            for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
            {
                molhess.row(ix)[jx] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jx];
                molhess.row(ix)[jy] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jy];
                molhess.row(ix)[jz] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jz];

                molhess.row(iy)[jx] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jx];
                molhess.row(iy)[jy] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jy];
                molhess.row(iy)[jz] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jz];

                molhess.row(iz)[jx] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jx];
                molhess.row(iz)[jy] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jy];
                molhess.row(iz)[jz] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jz];
            }

            if (jatom != iatom)
            {
                molhess.row(jx)[ix] = molhess.row(ix)[jx];
                molhess.row(jx)[iy] = molhess.row(iy)[jx];
                molhess.row(jx)[iz] = molhess.row(iz)[jx];

                molhess.row(jy)[ix] = molhess.row(ix)[jy];
                molhess.row(jy)[iy] = molhess.row(iy)[jy];
                molhess.row(jy)[iz] = molhess.row(iz)[jy];

                molhess.row(jz)[ix] = molhess.row(ix)[jz];
                molhess.row(jz)[iy] = molhess.row(iy)[jz];
                molhess.row(jz)[iz] = molhess.row(iz)[jz];
            }
        }
    }

    return molhess;
}

CDenseMatrix
CXCMolecularHessian::_integrateFxcHessianForLDA(const CMolecule&        molecule,
                                                const CMolecularBasis&  basis,
                                                const CAODensityMatrix& gsDensityMatrix,
                                                const CMolecularGrid&   molecularGrid,
                                                const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // molecular Hessian

    auto natoms = molecule.getNumberOfAtoms();

    CMemBlock2D<double> molhess_threads(natoms * 3 * natoms * 3, nthreads);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> v2rho2_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho    = rho_data.data();
    auto v2rho2 = v2rho2_data.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 1, _screeningThresholdForGTOValues, boxdim);  // 1st order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForGGA(
                gaos, gaox, gaoy, gaoz, gtovec, xcoords, ycoords, zcoords, gridblockpos, grid_batch_offset, grid_batch_size, skip_cgto_ids);
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
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues))
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

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        dengridgen::generateDensityForLDA(rho, npoints, mat_chi, gs_sub_dens_mat, timer);

        // generate density gradient grid

        timer.start("Density grad. grid prep.");

        CDenseMatrix dengradx(natoms, npoints);
        CDenseMatrix dengrady(natoms, npoints);
        CDenseMatrix dengradz(natoms, npoints);

        timer.stop("Density grad. grid prep.");

        // eq.(26), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid matmul");

        auto mat_F = denblas::multAB(gs_sub_dens_mat, mat_chi);

        timer.stop("Density grad. grid matmul");

        // eq.(34), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid rho");

        auto naos = mat_chi.getNumberOfRows();

        auto F_val = mat_F.values();

        auto chi_x_val = mat_chi_x.values();
        auto chi_y_val = mat_chi_y.values();
        auto chi_z_val = mat_chi_z.values();

        auto gdenx = dengradx.values();
        auto gdeny = dengrady.values();
        auto gdenz = dengradz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            for (int32_t nu = 0; nu < naos; nu++)
            {
                auto atomidx = ao_to_atom_ids[aoinds[nu]];

                auto atom_offset = atomidx * npoints;

                auto nu_offset = nu * npoints;

                #pragma omp simd aligned(gdenx, gdeny, gdenz, F_val, chi_x_val, chi_y_val, chi_z_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto atom_g = atom_offset + g;

                    auto nu_g = nu_offset + g;

                    gdenx[atom_g] -= 2.0 * F_val[nu_g] * chi_x_val[nu_g];
                    gdeny[atom_g] -= 2.0 * F_val[nu_g] * chi_y_val[nu_g];
                    gdenz[atom_g] -= 2.0 * F_val[nu_g] * chi_z_val[nu_g];
                }
            }
        }

        timer.stop("Density grad. grid rho");

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_fxc_for_lda(npoints, rho, v2rho2);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // eq.(32), JCTC 2021, 17, 1512-1521

        timer.start("Accumulate gradient");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            auto gatm = molhess_threads.data(thread_id);

            for (int32_t iatom = 0; iatom < natoms; iatom++)
            {
                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto i_offset = iatom * npoints;

                for (int32_t jatom = iatom; jatom < natoms; jatom++)
                {
                    auto jx = jatom * 3 + 0;
                    auto jy = jatom * 3 + 1;
                    auto jz = jatom * 3 + 2;

                    auto j_offset = jatom * npoints;

                    double gatmxx = 0.0, gatmyx = 0.0, gatmzx = 0.0;
                    double gatmxy = 0.0, gatmyy = 0.0, gatmzy = 0.0;
                    double gatmxz = 0.0, gatmyz = 0.0, gatmzz = 0.0;

                    #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) aligned(local_weights, \
                            v2rho2, gdenx, gdeny, gdenz : VLX_ALIGN)
                    for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                    {
                        auto ig = i_offset + g;
                        auto jg = j_offset + g;

                        double prefac = local_weights[g] * (v2rho2[3 * g + 0] + v2rho2[3 * g + 1]);

                        gatmxx += prefac * gdenx[ig] * gdenx[jg];
                        gatmxy += prefac * gdenx[ig] * gdeny[jg];
                        gatmxz += prefac * gdenx[ig] * gdenz[jg];

                        gatmyx += prefac * gdeny[ig] * gdenx[jg];
                        gatmyy += prefac * gdeny[ig] * gdeny[jg];
                        gatmyz += prefac * gdeny[ig] * gdenz[jg];

                        gatmzx += prefac * gdenz[ig] * gdenx[jg];
                        gatmzy += prefac * gdenz[ig] * gdeny[jg];
                        gatmzz += prefac * gdenz[ig] * gdenz[jg];
                    }

                    // factor of 2 from sum of alpha and beta contributions

                    gatm[ix * (natoms * 3) + jx] += 2.0 * gatmxx;
                    gatm[ix * (natoms * 3) + jy] += 2.0 * gatmxy;
                    gatm[ix * (natoms * 3) + jz] += 2.0 * gatmxz;

                    gatm[iy * (natoms * 3) + jx] += 2.0 * gatmyx;
                    gatm[iy * (natoms * 3) + jy] += 2.0 * gatmyy;
                    gatm[iy * (natoms * 3) + jz] += 2.0 * gatmyz;

                    gatm[iz * (natoms * 3) + jx] += 2.0 * gatmzx;
                    gatm[iz * (natoms * 3) + jy] += 2.0 * gatmzy;
                    gatm[iz * (natoms * 3) + jz] += 2.0 * gatmzz;
                }
            }
        }

        timer.stop("Accumulate gradient");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;

    CDenseMatrix molhess(natoms * 3, natoms * 3);

    for (int32_t iatom = 0; iatom < natoms; iatom++)
    {
        auto ix = iatom * 3 + 0;
        auto iy = iatom * 3 + 1;
        auto iz = iatom * 3 + 2;

        for (int32_t jatom = iatom; jatom < natoms; jatom++)
        {
            auto jx = jatom * 3 + 0;
            auto jy = jatom * 3 + 1;
            auto jz = jatom * 3 + 2;

            for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
            {
                molhess.row(ix)[jx] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jx];
                molhess.row(ix)[jy] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jy];
                molhess.row(ix)[jz] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jz];

                molhess.row(iy)[jx] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jx];
                molhess.row(iy)[jy] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jy];
                molhess.row(iy)[jz] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jz];

                molhess.row(iz)[jx] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jx];
                molhess.row(iz)[jy] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jy];
                molhess.row(iz)[jz] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jz];
            }

            if (jatom != iatom)
            {
                molhess.row(jx)[ix] = molhess.row(ix)[jx];
                molhess.row(jx)[iy] = molhess.row(iy)[jx];
                molhess.row(jx)[iz] = molhess.row(iz)[jx];

                molhess.row(jy)[ix] = molhess.row(ix)[jy];
                molhess.row(jy)[iy] = molhess.row(iy)[jy];
                molhess.row(jy)[iz] = molhess.row(iz)[jy];

                molhess.row(jz)[ix] = molhess.row(ix)[jz];
                molhess.row(jz)[iy] = molhess.row(iy)[jz];
                molhess.row(jz)[iz] = molhess.row(iz)[jz];
            }
        }
    }

    return molhess;
}

CDenseMatrix
CXCMolecularHessian::_integrateFxcHessianForGGA(const CMolecule&        molecule,
                                                const CMolecularBasis&  basis,
                                                const CAODensityMatrix& gsDensityMatrix,
                                                const CMolecularGrid&   molecularGrid,
                                                const CXCFunctional&    xcFunctional) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // molecular Hessian

    auto natoms = molecule.getNumberOfAtoms();

    CMemBlock2D<double> molhess_threads(natoms * 3 * natoms * 3, nthreads);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaoxx(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoxz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoyz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaozz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> rhograd_data(6 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> sigma_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> vrho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> vsigma_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> v2rho2_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> v2rhosigma_data(6 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> v2sigma2_data(6 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho     = rho_data.data();
    auto rhograd = rhograd_data.data();
    auto sigma   = sigma_data.data();

    auto vrho   = vrho_data.data();
    auto vsigma = vsigma_data.data();

    auto v2rho2     = v2rho2_data.data();
    auto v2rhosigma = v2rhosigma_data.data();
    auto v2sigma2   = v2sigma2_data.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 2, _screeningThresholdForGTOValues, boxdim);  // 2nd order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForMetaGGA(gaos,
                                                 gaox,
                                                 gaoy,
                                                 gaoz,
                                                 gaoxx,
                                                 gaoxy,
                                                 gaoxz,
                                                 gaoyy,
                                                 gaoyz,
                                                 gaozz,
                                                 gtovec,
                                                 xcoords,
                                                 ycoords,
                                                 zcoords,
                                                 gridblockpos,
                                                 grid_batch_offset,
                                                 grid_batch_size,
                                                 skip_cgto_ids);
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

            auto gaoxx_nu = gaoxx.data(nu);
            auto gaoxy_nu = gaoxy.data(nu);
            auto gaoxz_nu = gaoxz.data(nu);
            auto gaoyy_nu = gaoyy.data(nu);
            auto gaoyz_nu = gaoyz.data(nu);
            auto gaozz_nu = gaozz.data(nu);

            for (int32_t g = 0; g < npoints; g++)
            {
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxx_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoxy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoxz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoyy_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoyz_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaozz_nu[g]) > _screeningThresholdForGTOValues))
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

        CDenseMatrix mat_chi_xx(aocount, npoints);
        CDenseMatrix mat_chi_xy(aocount, npoints);
        CDenseMatrix mat_chi_xz(aocount, npoints);
        CDenseMatrix mat_chi_yy(aocount, npoints);
        CDenseMatrix mat_chi_yz(aocount, npoints);
        CDenseMatrix mat_chi_zz(aocount, npoints);

        for (int32_t i = 0; i < aocount; i++)
        {
            std::memcpy(mat_chi.row(i), gaos.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));

            std::memcpy(mat_chi_xx.row(i), gaoxx.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xy.row(i), gaoxy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_xz.row(i), gaoxz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yy.row(i), gaoyy.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_yz.row(i), gaoyz.data(aoinds[i]), npoints * sizeof(double));
            std::memcpy(mat_chi_zz.row(i), gaozz.data(aoinds[i]), npoints * sizeof(double));
        }

        timer.stop("GTO screening");

        // generate sub density matrix

        timer.start("Density matrix slicing");

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        dengridgen::generateDensityForGGA(rho, rhograd, sigma, npoints, mat_chi, mat_chi_x, mat_chi_y, mat_chi_z, gs_sub_dens_mat, timer);

        // generate density gradient grid

        timer.start("Density grad. grid prep.");

        CDenseMatrix dengradx(natoms, npoints);
        CDenseMatrix dengrady(natoms, npoints);
        CDenseMatrix dengradz(natoms, npoints);

        CDenseMatrix dengradxx(natoms, npoints);
        CDenseMatrix dengradxy(natoms, npoints);
        CDenseMatrix dengradxz(natoms, npoints);

        CDenseMatrix dengradyx(natoms, npoints);
        CDenseMatrix dengradyy(natoms, npoints);
        CDenseMatrix dengradyz(natoms, npoints);

        CDenseMatrix dengradzx(natoms, npoints);
        CDenseMatrix dengradzy(natoms, npoints);
        CDenseMatrix dengradzz(natoms, npoints);

        timer.stop("Density grad. grid prep.");

        // eq.(26), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid matmul");

        auto mat_F = denblas::multAB(gs_sub_dens_mat, mat_chi);

        auto mat_F_x = denblas::multAB(gs_sub_dens_mat, mat_chi_x);
        auto mat_F_y = denblas::multAB(gs_sub_dens_mat, mat_chi_y);
        auto mat_F_z = denblas::multAB(gs_sub_dens_mat, mat_chi_z);

        timer.stop("Density grad. grid matmul");

        // eq.(34), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid rho");

        auto naos = mat_chi.getNumberOfRows();

        auto F_val = mat_F.values();

        auto F_x_val = mat_F_x.values();
        auto F_y_val = mat_F_y.values();
        auto F_z_val = mat_F_z.values();

        auto chi_x_val = mat_chi_x.values();
        auto chi_y_val = mat_chi_y.values();
        auto chi_z_val = mat_chi_z.values();

        auto chi_xx_val = mat_chi_xx.values();
        auto chi_xy_val = mat_chi_xy.values();
        auto chi_xz_val = mat_chi_xz.values();
        auto chi_yy_val = mat_chi_yy.values();
        auto chi_yz_val = mat_chi_yz.values();
        auto chi_zz_val = mat_chi_zz.values();

        auto gdenx = dengradx.values();
        auto gdeny = dengrady.values();
        auto gdenz = dengradz.values();

        auto gdenxx = dengradxx.values();
        auto gdenxy = dengradxy.values();
        auto gdenxz = dengradxz.values();

        auto gdenyx = dengradyx.values();
        auto gdenyy = dengradyy.values();
        auto gdenyz = dengradyz.values();

        auto gdenzx = dengradzx.values();
        auto gdenzy = dengradzy.values();
        auto gdenzz = dengradzz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            for (int32_t nu = 0; nu < naos; nu++)
            {
                auto atomidx = ao_to_atom_ids[aoinds[nu]];

                auto atom_offset = atomidx * npoints;

                auto nu_offset = nu * npoints;

                #pragma omp simd aligned(gdenx, gdeny, gdenz, \
                        gdenxx, gdenxy, gdenxz, gdenyx, gdenyy, gdenyz, gdenzx, gdenzy, gdenzz, \
                        F_val, F_x_val, F_y_val, F_z_val, chi_x_val, chi_y_val, chi_z_val, \
                        chi_xx_val, chi_xy_val, chi_xz_val, chi_yy_val, chi_yz_val, chi_zz_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto atom_g = atom_offset + g;

                    auto nu_g = nu_offset + g;

                    gdenx[atom_g] -= 2.0 * F_val[nu_g] * chi_x_val[nu_g];
                    gdeny[atom_g] -= 2.0 * F_val[nu_g] * chi_y_val[nu_g];
                    gdenz[atom_g] -= 2.0 * F_val[nu_g] * chi_z_val[nu_g];

                    gdenxx[atom_g] -= 2.0 * (F_x_val[nu_g] * chi_x_val[nu_g] + F_val[nu_g] * chi_xx_val[nu_g]);
                    gdenxy[atom_g] -= 2.0 * (F_x_val[nu_g] * chi_y_val[nu_g] + F_val[nu_g] * chi_xy_val[nu_g]);
                    gdenxz[atom_g] -= 2.0 * (F_x_val[nu_g] * chi_z_val[nu_g] + F_val[nu_g] * chi_xz_val[nu_g]);

                    gdenyx[atom_g] -= 2.0 * (F_y_val[nu_g] * chi_x_val[nu_g] + F_val[nu_g] * chi_xy_val[nu_g]);
                    gdenyy[atom_g] -= 2.0 * (F_y_val[nu_g] * chi_y_val[nu_g] + F_val[nu_g] * chi_yy_val[nu_g]);
                    gdenyz[atom_g] -= 2.0 * (F_y_val[nu_g] * chi_z_val[nu_g] + F_val[nu_g] * chi_yz_val[nu_g]);

                    gdenzx[atom_g] -= 2.0 * (F_z_val[nu_g] * chi_x_val[nu_g] + F_val[nu_g] * chi_xz_val[nu_g]);
                    gdenzy[atom_g] -= 2.0 * (F_z_val[nu_g] * chi_y_val[nu_g] + F_val[nu_g] * chi_yz_val[nu_g]);
                    gdenzz[atom_g] -= 2.0 * (F_z_val[nu_g] * chi_z_val[nu_g] + F_val[nu_g] * chi_zz_val[nu_g]);
                }
            }
        }

        timer.stop("Density grad. grid rho");

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_vxc_for_gga(npoints, rho, sigma, vrho, vsigma);

        xcFunctional.compute_fxc_for_gga(npoints, rho, sigma, v2rho2, v2rhosigma, v2sigma2);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // eq.(32), JCTC 2021, 17, 1512-1521

        timer.start("Accumulate gradient");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            auto gatm = molhess_threads.data(thread_id);

            for (int32_t iatom = 0; iatom < natoms; iatom++)
            {
                auto ix = iatom * 3 + 0;
                auto iy = iatom * 3 + 1;
                auto iz = iatom * 3 + 2;

                auto i_offset = iatom * npoints;

                for (int32_t jatom = iatom; jatom < natoms; jatom++)
                {
                    auto jx = jatom * 3 + 0;
                    auto jy = jatom * 3 + 1;
                    auto jz = jatom * 3 + 2;

                    auto j_offset = jatom * npoints;

                    if (jatom != iatom) continue;

                    double gatmxx = 0.0, gatmyx = 0.0, gatmzx = 0.0;
                    double gatmxy = 0.0, gatmyy = 0.0, gatmzy = 0.0;
                    double gatmxz = 0.0, gatmyz = 0.0, gatmzz = 0.0;

                    #pragma omp simd reduction(+ : gatmxx, gatmxy, gatmxz, gatmyx, gatmyy, gatmyz, gatmzx, gatmzy, gatmzz) \
                            aligned(local_weights, rhograd, vsigma, v2rho2, v2rhosigma, v2sigma2, gdenx, gdeny, gdenz, \
                            gdenxx, gdenxy, gdenxz, gdenyx, gdenyy, gdenyz, gdenzx, gdenzy, gdenzz : VLX_ALIGN)
                    for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                    {
                        auto ig = i_offset + g;
                        auto jg = j_offset + g;

                        double w = local_weights[g];

                        double prefac = w * (v2rho2[3 * g + 0] + v2rho2[3 * g + 1]);

                        gatmxx += prefac * gdenx[ig] * gdenx[jg];
                        gatmxy += prefac * gdenx[ig] * gdeny[jg];
                        gatmxz += prefac * gdenx[ig] * gdenz[jg];

                        gatmyx += prefac * gdeny[ig] * gdenx[jg];
                        gatmyy += prefac * gdeny[ig] * gdeny[jg];
                        gatmyz += prefac * gdeny[ig] * gdenz[jg];

                        gatmzx += prefac * gdenz[ig] * gdenx[jg];
                        gatmzy += prefac * gdenz[ig] * gdeny[jg];
                        gatmzz += prefac * gdenz[ig] * gdenz[jg];

                        // TODO add other contributions
                    }

                    // factor of 2 from sum of alpha and beta contributions

                    gatm[ix * (natoms * 3) + jx] += 2.0 * gatmxx;
                    gatm[ix * (natoms * 3) + jy] += 2.0 * gatmxy;
                    gatm[ix * (natoms * 3) + jz] += 2.0 * gatmxz;

                    gatm[iy * (natoms * 3) + jx] += 2.0 * gatmyx;
                    gatm[iy * (natoms * 3) + jy] += 2.0 * gatmyy;
                    gatm[iy * (natoms * 3) + jz] += 2.0 * gatmyz;

                    gatm[iz * (natoms * 3) + jx] += 2.0 * gatmzx;
                    gatm[iz * (natoms * 3) + jy] += 2.0 * gatmzy;
                    gatm[iz * (natoms * 3) + jz] += 2.0 * gatmzz;
                }
            }
        }

        timer.stop("Accumulate gradient");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;

    CDenseMatrix molhess(natoms * 3, natoms * 3);

    for (int32_t iatom = 0; iatom < natoms; iatom++)
    {
        auto ix = iatom * 3 + 0;
        auto iy = iatom * 3 + 1;
        auto iz = iatom * 3 + 2;

        for (int32_t jatom = iatom; jatom < natoms; jatom++)
        {
            auto jx = jatom * 3 + 0;
            auto jy = jatom * 3 + 1;
            auto jz = jatom * 3 + 2;

            for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
            {
                molhess.row(ix)[jx] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jx];
                molhess.row(ix)[jy] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jy];
                molhess.row(ix)[jz] += molhess_threads.data(thread_id)[ix * (natoms * 3) + jz];

                molhess.row(iy)[jx] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jx];
                molhess.row(iy)[jy] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jy];
                molhess.row(iy)[jz] += molhess_threads.data(thread_id)[iy * (natoms * 3) + jz];

                molhess.row(iz)[jx] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jx];
                molhess.row(iz)[jy] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jy];
                molhess.row(iz)[jz] += molhess_threads.data(thread_id)[iz * (natoms * 3) + jz];
            }

            if (jatom != iatom)
            {
                molhess.row(jx)[ix] = molhess.row(ix)[jx];
                molhess.row(jx)[iy] = molhess.row(iy)[jx];
                molhess.row(jx)[iz] = molhess.row(iz)[jx];

                molhess.row(jy)[ix] = molhess.row(ix)[jy];
                molhess.row(jy)[iy] = molhess.row(iy)[jy];
                molhess.row(jy)[iz] = molhess.row(iz)[jy];

                molhess.row(jz)[ix] = molhess.row(ix)[jz];
                molhess.row(jz)[iy] = molhess.row(iy)[jz];
                molhess.row(jz)[iz] = molhess.row(iz)[jz];
            }
        }
    }

    return molhess;
}

std::vector<CDenseMatrix>
CXCMolecularHessian::_integrateVxcFockGradientForLDA(const CMolecule&        molecule,
                                                     const CMolecularBasis&  basis,
                                                     const CAODensityMatrix& gsDensityMatrix,
                                                     const CMolecularGrid&   molecularGrid,
                                                     const CXCFunctional&    xcFunctional,
                                                     const int32_t           atomIdx) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    std::vector<CMultiTimer> omptimers(nthreads);

    // Vxc Fock gradeints (in x,y,z directions)

    std::vector<CDenseMatrix> vxcgrads;

    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));
    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));
    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> vrho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho  = rho_data.data();
    auto vrho = vrho_data.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 1, _screeningThresholdForGTOValues, boxdim);  // 1st order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            omptimers[thread_id].start("gtoeval");

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForGGA(
                gaos, gaox, gaoy, gaoz, gtovec, xcoords, ycoords, zcoords, gridblockpos, grid_batch_offset, grid_batch_size, skip_cgto_ids);

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
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues))
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

            auto iatom = ao_to_atom_ids[aoinds[i]];

            if (iatom == atomIdx)
            {
                std::memcpy(mat_chi_x.row(i), gaox.data(aoinds[i]), npoints * sizeof(double));
                std::memcpy(mat_chi_y.row(i), gaoy.data(aoinds[i]), npoints * sizeof(double));
                std::memcpy(mat_chi_z.row(i), gaoz.data(aoinds[i]), npoints * sizeof(double));
            }
        }

        timer.stop("GTO screening");

        if (aocount == 0) continue;

        // generate sub density matrix and density grid

        timer.start("Density matrix slicing");

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        dengridgen::generateDensityForLDA(rho, npoints, mat_chi, gs_sub_dens_mat, timer);

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_vxc_for_lda(npoints, rho, vrho);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // compute partial contribution to Vxc Fock gradient and distribute partial
        // Vxc Fock gradient to full matrix

        // eq.(30), JCTC 2021, 17, 1512-1521

        timer.start("Vxc matrix G");

        auto chi_val = mat_chi.values();

        CDenseMatrix vxc_w(aocount, npoints);

        auto vxc_w_val = vxc_w.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto nthreads = omp_get_max_threads();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            for (int32_t nu = 0; nu < aocount; nu++)
            {
                auto nu_offset = nu * npoints;

                #pragma omp simd aligned(local_weights, vrho, vxc_w_val, chi_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto prefac = local_weights[g] * vrho[2 * g + 0];

                    vxc_w_val[nu_offset + g] = -1.0 * prefac * chi_val[nu_offset + g];
                }
            }
        }

        timer.stop("Vxc matrix G");

        // eq.(31), JCTC 2021, 17, 1512-1521

        timer.start("Vxc matrix matmul");

        auto vxc_gx = denblas::multABt(mat_chi_x, vxc_w);
        auto vxc_gy = denblas::multABt(mat_chi_y, vxc_w);
        auto vxc_gz = denblas::multABt(mat_chi_z, vxc_w);

        vxc_gx.symmetrize();
        vxc_gy.symmetrize();
        vxc_gz.symmetrize();

        timer.stop("Vxc matrix matmul");

        timer.start("Vxc matrix dist.");

        submat::distributeSubMatrixToDenseMatrix(vxcgrads[0], vxc_gx, aoinds, aocount, naos);
        submat::distributeSubMatrixToDenseMatrix(vxcgrads[1], vxc_gy, aoinds, aocount, naos);
        submat::distributeSubMatrixToDenseMatrix(vxcgrads[2], vxc_gz, aoinds, aocount, naos);

        timer.stop("Vxc matrix dist.");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;
    // std::cout << "OpenMP timing" << std::endl;
    // for (int32_t thread_id = 0; thread_id < nthreads; thread_id++)
    //{
    //     std::cout << "Thread " << thread_id << std::endl;
    //     std::cout << omptimers[thread_id].getSummary() << std::endl;
    // }

    return vxcgrads;
}

std::vector<CDenseMatrix>
CXCMolecularHessian::_integrateFxcFockGradientForLDA(const CMolecule&        molecule,
                                                     const CMolecularBasis&  basis,
                                                     const CAODensityMatrix& gsDensityMatrix,
                                                     const CMolecularGrid&   molecularGrid,
                                                     const CXCFunctional&    xcFunctional,
                                                     const int32_t           atomIdx) const
{
    CMultiTimer timer;

    timer.start("Total timing");

    timer.start("Preparation");

    auto nthreads = omp_get_max_threads();

    // Fxc contribution to Vxc Fock gradeints (in x,y,z directions)

    std::vector<CDenseMatrix> vxcgrads;

    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));
    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));
    vxcgrads.push_back(CDenseMatrix(gsDensityMatrix.getNumberOfRows(0), gsDensityMatrix.getNumberOfColumns(0)));

    // GTOs container and number of AOs

    CGtoContainer* gtovec = new CGtoContainer(molecule, basis);

    auto naos = gtovec->getNumberOfAtomicOrbitals();

    // AO-to-atom mapping

    std::vector<int32_t> ao_to_atom_ids(naos);

    _computeAOtoAtomMapping(ao_to_atom_ids, molecule, basis);

    // molecular gradient

    auto natoms = molecule.getNumberOfAtoms();

    CMemBlock2D<double> molhess_threads(natoms * 3 * natoms * 3, nthreads);

    // memory blocks for GTOs on grid points

    CMemBlock2D<double> gaos(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    CMemBlock2D<double> gaox(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoy(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);
    CMemBlock2D<double> gaoz(molecularGrid.getMaxNumberOfGridPointsPerBox(), naos);

    // indices for keeping track of GTOs

    // skip_cgto_ids: whether a CGTO should be skipped
    // skip_ao_ids: whether an AO should be skipped
    // aoinds: mapping between AO indices before and after screening

    CMemBlock<int32_t> skip_cgto_ids(naos);  // note: naos >= ncgtos

    CMemBlock<int32_t> skip_ao_ids(naos);

    std::vector<int32_t> aoinds(naos);

    // density and functional derivatives

    CMemBlock<double> local_weights_data(molecularGrid.getMaxNumberOfGridPointsPerBox());

    CMemBlock<double> rho_data(2 * molecularGrid.getMaxNumberOfGridPointsPerBox());
    CMemBlock<double> v2rho2_data(3 * molecularGrid.getMaxNumberOfGridPointsPerBox());

    auto local_weights = local_weights_data.data();

    auto rho    = rho_data.data();
    auto v2rho2 = v2rho2_data.data();

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

        auto boxdim = gtoeval::getGridBoxDimension(gridblockpos, npoints, xcoords, ycoords, zcoords);

        // pre-screening of GTOs

        timer.start("GTO pre-screening");

        gtoeval::preScreenGtos(skip_cgto_ids, skip_ao_ids, gtovec, 1, _screeningThresholdForGTOValues, boxdim);  // 1st order GTO derivative

        timer.stop("GTO pre-screening");

        // GTO values on grid points

        timer.start("OMP GTO evaluation");

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            gtoeval::computeGtosValuesForGGA(
                gaos, gaox, gaoy, gaoz, gtovec, xcoords, ycoords, zcoords, gridblockpos, grid_batch_offset, grid_batch_size, skip_cgto_ids);
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
                if ((std::fabs(gaos_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaox_nu[g]) > _screeningThresholdForGTOValues) ||
                    (std::fabs(gaoy_nu[g]) > _screeningThresholdForGTOValues) || (std::fabs(gaoz_nu[g]) > _screeningThresholdForGTOValues))
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

        auto gs_sub_dens_mat = submat::getSubDensityMatrix(gsDensityMatrix, 0, "ALPHA", aoinds, aocount, naos);

        timer.stop("Density matrix slicing");

        // generate density grid

        dengridgen::generateDensityForLDA(rho, npoints, mat_chi, gs_sub_dens_mat, timer);

        // generate density gradient grid

        timer.start("Density grad. grid prep.");

        CDenseMatrix dengradx(1, npoints);
        CDenseMatrix dengrady(1, npoints);
        CDenseMatrix dengradz(1, npoints);

        timer.stop("Density grad. grid prep.");

        // eq.(26), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid matmul");

        auto mat_F = denblas::multAB(gs_sub_dens_mat, mat_chi);

        timer.stop("Density grad. grid matmul");

        // eq.(34), JCTC 2021, 17, 1512-1521

        timer.start("Density grad. grid rho");

        auto naos = mat_chi.getNumberOfRows();

        auto F_val = mat_F.values();

        auto chi_x_val = mat_chi_x.values();
        auto chi_y_val = mat_chi_y.values();
        auto chi_z_val = mat_chi_z.values();

        auto gdenx = dengradx.values();
        auto gdeny = dengrady.values();
        auto gdenz = dengradz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            for (int32_t nu = 0; nu < naos; nu++)
            {
                auto iatom = ao_to_atom_ids[aoinds[nu]];

                if (iatom != atomIdx) continue;

                auto nu_offset = nu * npoints;

                #pragma omp simd aligned(gdenx, gdeny, gdenz, F_val, chi_x_val, chi_y_val, chi_z_val : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto nu_g = nu_offset + g;

                    gdenx[g] -= 2.0 * F_val[nu_g] * chi_x_val[nu_g];
                    gdeny[g] -= 2.0 * F_val[nu_g] * chi_y_val[nu_g];
                    gdenz[g] -= 2.0 * F_val[nu_g] * chi_z_val[nu_g];
                }
            }
        }

        timer.stop("Density grad. grid rho");

        // compute exchange-correlation functional derivative

        timer.start("XC functional eval.");

        xcFunctional.compute_fxc_for_lda(npoints, rho, v2rho2);

        gridscreen::copyWeights(local_weights, gridblockpos, weights, npoints);

        timer.stop("XC functional eval.");

        // compute partial contribution to Vxc Fock gradient and distribute partial
        // Vxc Fock gradient to full matrix

        // eq.(30), JCTC 2021, 17, 1512-1521

        timer.start("Vxc matrix G");

        auto chi_val = mat_chi.values();

        CDenseMatrix vxc_wx(aocount, npoints);
        CDenseMatrix vxc_wy(aocount, npoints);
        CDenseMatrix vxc_wz(aocount, npoints);

        auto vxc_wx_val = vxc_wx.values();
        auto vxc_wy_val = vxc_wy.values();
        auto vxc_wz_val = vxc_wz.values();

        #pragma omp parallel
        {
            auto thread_id = omp_get_thread_num();

            auto nthreads = omp_get_max_threads();

            auto grid_batch_size = mpi::batch_size(npoints, thread_id, nthreads);

            auto grid_batch_offset = mpi::batch_offset(npoints, thread_id, nthreads);

            for (int32_t nu = 0; nu < aocount; nu++)
            {
                auto nu_offset = nu * npoints;

                #pragma omp simd aligned(local_weights, v2rho2, chi_val, \
                        vxc_wx_val, vxc_wy_val, vxc_wz_val, gdenx, gdeny, gdenz : VLX_ALIGN)
                for (int32_t g = grid_batch_offset; g < grid_batch_offset + grid_batch_size; g++)
                {
                    auto nu_g = nu_offset + g;

                    auto prefac = local_weights[g] * (v2rho2[3 * g + 0] + v2rho2[3 * g + 1]) * chi_val[nu_g];

                    vxc_wx_val[nu_g] = prefac * gdenx[g];
                    vxc_wy_val[nu_g] = prefac * gdeny[g];
                    vxc_wz_val[nu_g] = prefac * gdenz[g];
                }
            }
        }

        timer.stop("Vxc matrix G");

        // eq.(31), JCTC 2021, 17, 1512-1521

        timer.start("Vxc matrix matmul");

        auto vxc_gx = denblas::multABt(mat_chi, vxc_wx);
        auto vxc_gy = denblas::multABt(mat_chi, vxc_wy);
        auto vxc_gz = denblas::multABt(mat_chi, vxc_wz);

        vxc_gx.symmetrizeAndScale(0.5);
        vxc_gy.symmetrizeAndScale(0.5);
        vxc_gz.symmetrizeAndScale(0.5);

        timer.stop("Vxc matrix matmul");

        timer.start("Vxc matrix dist.");

        submat::distributeSubMatrixToDenseMatrix(vxcgrads[0], vxc_gx, aoinds, aocount, naos);
        submat::distributeSubMatrixToDenseMatrix(vxcgrads[1], vxc_gy, aoinds, aocount, naos);
        submat::distributeSubMatrixToDenseMatrix(vxcgrads[2], vxc_gz, aoinds, aocount, naos);

        timer.stop("Vxc matrix dist.");
    }

    // destroy GTOs container

    delete gtovec;

    timer.stop("Total timing");

    // std::cout << "Timing of new integrator" << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << timer.getSummary() << std::endl;

    return vxcgrads;
}

void
CXCMolecularHessian::_computeAOtoAtomMapping(std::vector<int32_t>& ao_to_atom_ids, const CMolecule& molecule, const CMolecularBasis& basis) const
{
    for (int32_t iatom = 0; iatom < molecule.getNumberOfAtoms(); iatom++)
    {
        CGtoContainer* atomgtovec = new CGtoContainer(molecule, basis, iatom, 1);

        for (int32_t i = 0; i < atomgtovec->getNumberOfGtoBlocks(); i++)
        {
            auto bgtos = atomgtovec->getGtoBlock(i);

            auto bang = bgtos.getAngularMomentum();

            auto bnspher = angmom::to_SphericalComponents(bang);

            for (int32_t j = 0; j < bgtos.getNumberOfContrGtos(); j++)
            {
                for (int32_t k = 0; k < bnspher; k++)
                {
                    auto idx = bgtos.getIdentifiers(k)[j];

                    ao_to_atom_ids[idx] = iatom;
                }
            }
        }

        delete atomgtovec;
    }
}
