//
//                             VELOXCHEM
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2019 by VeloxChem developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "VisualizationDriver.hpp"

#include <cmath>

#include "SphericalMomentum.hpp"
#include "BasisFunction.hpp"
#include "MolecularBasis.hpp"
#include "ErrorHandler.hpp"

CVisualizationDriver::CVisualizationDriver()
{
    
}

CVisualizationDriver::~CVisualizationDriver()
{
    
}

std::vector<std::vector<int32_t>>
CVisualizationDriver::_buildCartesianAngularMomentum(int32_t angl) const
{
    std::vector<std::vector<int32_t>> lmn;

    // lexical order of Cartesian angular momentum
    // 1S: 0
    // 3P: x,y,z
    // 6D: xx,xy,xz,yy,yz,zz
    // 10F: ...

    for (int32_t i = 0; i <= angl; i++)
    {
        int32_t lx = angl - i;

        for (int32_t j = 0; j <= i; j++)
        {
            int32_t ly = i - j;

            int32_t lz = j;

            lmn.push_back(std::vector<int32_t>({lx, ly, lz}));
        }
    }

    return lmn;
}

std::vector<double>
CVisualizationDriver::_compPhiAtomicOrbitals(const CMolecule&       molecule,
                                             const CMolecularBasis& basis,
                                             const double           xp,
                                             const double           yp,
                                             const double           zp) const
{
    auto natoms = molecule.getNumberOfAtoms();

    auto max_angl = basis.getMolecularMaxAngularMomentum(molecule);

    std::vector<double> phi;

    // azimuthal quantum number: s,p,d,f,...

    for (int32_t aoidx = 0, angl = 0; angl <= max_angl; angl++)
    {
        CSphericalMomentum sphmom (angl);

        auto nsph = sphmom.getNumberOfComponents();

        auto lmn = _buildCartesianAngularMomentum(angl);

        // magnetic quantum number: s,p-1,p0,p+1,d-2,d-1,d0,d+1,d+2,...

        for (int32_t isph = 0; isph < nsph; isph++)
        {
            // prepare Cartesian components

            std::vector<double> fcarts, lx, ly, lz;

            auto ncomp = sphmom.getNumberOfFactors(isph);
            
            for (int32_t icomp = 0; icomp < ncomp; icomp++)
            {
                fcarts.push_back(sphmom.getFactors(isph)[icomp]);

                auto cartind = sphmom.getIndexes(isph)[icomp];

                lx.push_back(lmn[cartind][0]);

                ly.push_back(lmn[cartind][1]);

                lz.push_back(lmn[cartind][2]);
            }

            // go through atoms

            for (int32_t atomidx = 0; atomidx < natoms; atomidx++)
            {
                // process coordinates

                double rx = xp - molecule.getCoordinatesX()[atomidx];

                double ry = yp - molecule.getCoordinatesY()[atomidx];

                double rz = zp - molecule.getCoordinatesZ()[atomidx];

                double r2 = rx * rx + ry * ry + rz * rz;

                // process atomic orbitals

                auto idelem = molecule.getIdsElemental()[atomidx];

                auto nao = basis.getNumberOfBasisFunctions(idelem, angl);

                auto basisfunc = basis.getBasisFunctions(idelem, angl);

                for (int32_t i = 0; i < nao; i++, aoidx++)
                {
                    double phiao = 0.0;

                    // process primitives

                    auto nprims = basisfunc[i].getNumberOfPrimitiveFunctions();

                    auto exponents = basisfunc[i].getExponents();

                    auto normcoefs = basisfunc[i].getNormalizationFactors();

                    for (int32_t iprim = 0; iprim < nprims; iprim++)
                    {
                        double expon = std::exp(-exponents[iprim] * r2);

                        double coef1 = normcoefs[iprim];

                        // transform from Cartesian to spherical harmonics

                        for (int32_t icomp = 0; icomp < ncomp; icomp++)
                        {
                            double coef2 = coef1 * fcarts[icomp];

                            double powxyz = std::pow(rx, lx[icomp])
                                          * std::pow(ry, ly[icomp])
                                          * std::pow(rz, lz[icomp]);

                            phiao += coef2 * powxyz * expon;
                        }
                    }

                    phi.push_back(phiao);
                }
            }
        }
    }

    return phi;
}

double
CVisualizationDriver::compute(const CMolecule&          molecule,
                              const CMolecularBasis&    basis,
                              const CMolecularOrbitals& mo,
                              const int32_t             moidx,
                              const std::string&        mospin,
                              const double              xp,
                              const double              yp,
                              const double              zp) const
{
    double psi = 0.0;

    auto phi = _compPhiAtomicOrbitals(molecule, basis, xp, yp, zp);

    const int32_t nao = (int32_t)(phi.size());

    auto morows = mo.getNumberOfRows();

    auto mocols = mo.getNumberOfColumns();

    std::string errnao  ("getPsiMolecularOrbital - Inconsistent number of AOs");

    std::string erridx  ("getPsiMolecularOrbital - Invalid MO index");

    std::string errspin ("getPsiMolecularOrbital - Invalid MO spin");

    errors::assertMsgCritical(morows == nao, errnao);

    errors::assertMsgCritical(0 <= moidx && moidx < mocols, erridx);

    const bool alphaspin = (mospin == std::string("alpha") ||
                            mospin == std::string("a"));

    const bool betaspin  = (mospin == std::string("beta") ||
                            mospin == std::string("b"));

    errors::assertMsgCritical(alphaspin || betaspin, errspin);

    auto mocoefs = alphaspin ? mo.alphaOrbitals() : mo.betaOrbitals();

    for (int32_t aoidx = 0; aoidx < nao; aoidx++)
    {
        double mocoef = mocoefs[aoidx * mocols + moidx];

        psi += mocoef * phi[aoidx];
    }

    return psi;
}

double
CVisualizationDriver::compute(const CMolecule&        molecule,
                              const CMolecularBasis&  basis,
                              const CAODensityMatrix& density,
                              const int32_t           denidx,
                              const std::string&      denspin,
                              const double            xp,
                              const double            yp,
                              const double            zp) const
{
    double psi = 0.0;

    auto phi = _compPhiAtomicOrbitals(molecule, basis, xp, yp, zp);

    int32_t nao = (int32_t)(phi.size());

    auto denrows = density.getNumberOfRows(denidx);

    auto dencols = density.getNumberOfColumns(denidx);

    std::string errnao  ("getPsiDensity - Inconsistent number of AOs");

    std::string erridx  ("getPsiDensity - Invalid density matrix index");

    std::string errspin ("getPsiDensity - Invalid density matrix spin");

    errors::assertMsgCritical(denrows == nao && dencols == nao, errnao);

    auto numdens = density.getNumberOfDensityMatrices();

    errors::assertMsgCritical(0 <= denidx && denidx < numdens, erridx);

    const bool alphaspin = (denspin == std::string("alpha") ||
                            denspin == std::string("a"));

    const bool betaspin  = (denspin == std::string("beta") ||
                            denspin == std::string("b"));

    errors::assertMsgCritical(alphaspin || betaspin, errspin);

    auto rho = alphaspin ? density.alphaDensity(denidx) :
               density.betaDensity(denidx);

    for (int32_t iao = 0; iao < nao; iao++)
    {
        for (int32_t jao = 0; jao < nao; jao++)
        {
            psi += phi[iao] * rho[iao * nao + jao] * phi[jao];
        }
    }

    return psi;
}
