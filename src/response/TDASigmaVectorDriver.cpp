//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "TDASigmaVectorDriver.hpp"

#include "AOFockMatrix.hpp"
#include "ElectronRepulsionIntegralsDriver.hpp"

CTDASigmaVectorDriver::CTDASigmaVectorDriver(const int32_t  globRank,
                                             const int32_t  globNodes,
                                                   MPI_Comm comm)

    : _globRank(globRank)

    , _globNodes(globNodes)

    , _isLocalMode(false)
{
    _locRank  = mpi::rank(comm);
    
    _locNodes = mpi::nodes(comm);
    
    _isLocalMode = !mpi::compare(comm, MPI_COMM_WORLD);
}

CTDASigmaVectorDriver::~CTDASigmaVectorDriver()
{
    
}

std::vector<CDenseMatrix>
CTDASigmaVectorDriver::compute(const std::vector<CExcitationVector>& zVectors,
                               const CScreeningContainer&            screeningContainer,
                               const CMolecularOrbitals&             molecularOrbitals,
                               const CMolecule&                      molecule,
                               const CMolecularBasis&                basis,
                                     MPI_Comm                        comm) const
{
    auto sig_vecs = _allocSigmaVectors(zVectors);
 
    _addCanonicalFockContribution(sig_vecs, zVectors, molecularOrbitals);
    
    _addFirstOrderFockContribution(sig_vecs, zVectors, screeningContainer,
                                   molecularOrbitals, molecule, basis, comm);
    
    return sig_vecs;
}

std::vector<CDenseMatrix>
CTDASigmaVectorDriver::_allocSigmaVectors(const std::vector<CExcitationVector>& zVectors) const
{
    std::vector<CDenseMatrix> sig_vecs;
    
    // determine number of sigma vectors
    
    auto nvecs = static_cast<int32_t>(zVectors.size());
    
    if (nvecs > 0)
    {
        // allocate sigma vectors
        
        for (int32_t i = 0; i < nvecs; i++)
        {
            auto ndim = zVectors[i].getNumberOfExcitations();
            
            sig_vecs.push_back(CDenseMatrix(ndim, 1));
        }
        
        // zero sigma vectors
        
        for (int32_t i = 0; i < nvecs; i++)
        {
            sig_vecs[i].zero();
        }
    }
    
    return sig_vecs;
}

void
CTDASigmaVectorDriver::_addCanonicalFockContribution(      std::vector<CDenseMatrix>&      sigmaVectors,
                                                     const std::vector<CExcitationVector>& zVectors,
                                                     const CMolecularOrbitals&             molecularOrbitals) const
{
    for (size_t i = 0; i < sigmaVectors.size(); i++)
    {
        // set up pointers to canonical Fock eigenvalues
        
        auto beigs = zVectors[i].getBraEnergies(molecularOrbitals);
        
        auto keigs = zVectors[i].getKetEnergies(molecularOrbitals);
        
        // set up pointers to creation/anihilation operator indexes
        
        auto bidx = zVectors[i].getBraIndexes();
        
        auto kidx = zVectors[i].getKetIndexes();
        
        // set up pointer to sigma and Z vector values
        
        auto sigdat = sigmaVectors[i].values();
        
        auto zdat = zVectors[i].getCoefficientsZ();
        
        // add diagonal (e_a - e_i) z_ia contribution
        
        auto ndim = sigmaVectors[i].getNumberOfRows();
        
        for (int32_t j = 0; j < ndim; j++)
        {
            sigdat[j] += (keigs[kidx[j]] - beigs[bidx[j]]) * zdat[j];
        }
    }
}

void
CTDASigmaVectorDriver::_addFirstOrderFockContribution(      std::vector<CDenseMatrix>&      sigmaVectors,
                                                      const std::vector<CExcitationVector>& zVectors,
                                                      const CScreeningContainer&            screeningContainer,
                                                      const CMolecularOrbitals&             molecularOrbitals,
                                                      const CMolecule&                      molecule,
                                                      const CMolecularBasis&                basis,
                                                            MPI_Comm                        comm) const
{
    auto nvecs = static_cast<int32_t>(sigmaVectors.size());
    
    // create first order transformed density
    
    CAODensityMatrix denmat;
    
    denmat.setDensityType(denmat::rgen); 
    
    for (int32_t i = 0; i < nvecs; i++)
    {
        denmat.append(zVectors[i].getDensityZ(molecularOrbitals));
    }
    
    denmat.broadcast(_locRank, comm);
    
    // compute AO Fock matrices
    
    CAOFockMatrix faomat(denmat);
    
    CElectronRepulsionIntegralsDriver eri_drv(_locRank, _locNodes, comm);
    
    eri_drv.compute(faomat, denmat, molecule, basis, screeningContainer, comm);
    
    faomat.reduce_sum(_locRank, _locNodes, comm);
    
    // add contributions to sigma vectors on master node
    
    if (_locRank == mpi::master())
    {
        for (int32_t i = 0; i < nvecs; i++)
        {
            // compute MO Fock matrix
            
            auto fmomat = molecularOrbitals.transform(faomat.getReferenceToFock(i),
                                                      szblock::aa);
            
            // set up pointers to creation/anihilation operator indexes
            
            auto bidx = zVectors[i].getBraIndexes();
            
            auto kidx = zVectors[i].getKetIndexes();
            
            // set up pointer to sigma vector values
            
            auto sigdat = sigmaVectors[i].values();
            
            // add first order Fock contribution
            
            auto fdat = fmomat.values();
            
            auto ncol = fmomat.getNumberOfColumns();
            
            auto ndim = sigmaVectors[i].getNumberOfRows();
            
            for (int32_t j = 0; j < ndim; j++)
            {
                sigdat[j] += fdat[bidx[j] * ncol + kidx[j]];
            }
        }
    }
}
