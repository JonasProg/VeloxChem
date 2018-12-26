//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#include "OverlapIntegralsDriver.hpp"

#include "OneIntsFunc.hpp"
#include "AngularMomentum.hpp"
#include "OverlapRecFunc.hpp"
#include "GenFunc.hpp"
#include "MemBlock.hpp"
#include "SystemClock.hpp"
#include "StringFormat.hpp"

COverlapIntegralsDriver::COverlapIntegralsDriver(const int32_t  globRank,
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

COverlapIntegralsDriver::~COverlapIntegralsDriver()
{
    
}

COverlapMatrix
COverlapIntegralsDriver::compute(const CMolecule&       molecule,
                                 const CMolecularBasis& basis,
                                       MPI_Comm         comm) const 
{
    CSystemClock timer;
    
    COverlapMatrix ovlmat;
    
    if (_locRank == mpi::master())
    {
        // set up GTOs container
        
        CGtoContainer bracontr(molecule, basis);
        
        // compute overlap integrals
        
        ovlmat = _compOverlapIntegrals(&bracontr, &bracontr);
    }
    
    return ovlmat;
}

COverlapMatrix
COverlapIntegralsDriver::compute(const CMolecule&       molecule,
                                 const CMolecularBasis& braBasis,
                                 const CMolecularBasis& ketBasis,
                                       MPI_Comm         comm) const
{
    COverlapMatrix ovlmat;
    
    if (_locRank == mpi::master())
    {
        // set up GTOs containers
        
        CGtoContainer bracontr(molecule, braBasis);
        
        CGtoContainer ketcontr(molecule, ketBasis);
        
        // compute overlap integrals
        
        ovlmat = _compOverlapIntegrals(&bracontr, &ketcontr);
    }
    
    return ovlmat;
}

COverlapMatrix
COverlapIntegralsDriver::compute(const CMolecule&       braMolecule,
                                 const CMolecule&       ketMolecule,
                                 const CMolecularBasis& basis,
                                       MPI_Comm         comm) const
{
    COverlapMatrix ovlmat;
    
    if (_locRank == mpi::master())
    {
        // set up GTOs containers
        
        CGtoContainer bracontr(braMolecule, basis);
        
        CGtoContainer ketcontr(ketMolecule, basis);
        
        // compute overlap integrals
        
        ovlmat = _compOverlapIntegrals(&bracontr, &ketcontr);
    }
    
    return ovlmat;
}

COverlapMatrix
COverlapIntegralsDriver::compute(const CMolecule&       braMolecule,
                                 const CMolecule&       ketMolecule,
                                 const CMolecularBasis& braBasis,
                                 const CMolecularBasis& ketBasis,
                                       MPI_Comm         comm) const
{
    COverlapMatrix ovlmat;
    
    if (_locRank == mpi::master())
    {
        // set up GTOs containers
        
        CGtoContainer bracontr(braMolecule, braBasis);
        
        CGtoContainer ketcontr(ketMolecule, ketBasis);
        
        // compute overlap integrals
        
        ovlmat = _compOverlapIntegrals(&bracontr, &ketcontr);
    }
    
    return ovlmat;
}

void
COverlapIntegralsDriver::compute(      double*    intsBatch,
                                 const CGtoBlock& braGtoBlock,
                                 const CGtoBlock& ketGtoBlock) const
{
    // determine dimensions of integrals batch
    
    auto nrow = angmom::to_SphericalComponents(braGtoBlock.getAngularMomentum())
    
              * braGtoBlock.getNumberOfContrGtos();
    
    auto ncol = angmom::to_SphericalComponents(ketGtoBlock.getAngularMomentum())
    
              * ketGtoBlock.getNumberOfContrGtos();
    
    // set up distribution pattern
    
    COneIntsDistribution dist(intsBatch, nrow, ncol, dist1e::batch);
    
    // compute overlap integrals
    
    _compOverlapForGtoBlocks(&dist, braGtoBlock, ketGtoBlock);
}

COverlapMatrix
COverlapIntegralsDriver::_compOverlapIntegrals(const CGtoContainer* braGtoContainer,
                                               const CGtoContainer* ketGtoContainer) const
{
    // check if GTOs containers are same on bra and ket sides
    
    auto symbk = ((*braGtoContainer) == (*ketGtoContainer));
    
    // determine dimensions of overlap matrix
    
    auto nrow = braGtoContainer->getNumberOfAtomicOrbitals();
    
    auto ncol = ketGtoContainer->getNumberOfAtomicOrbitals();
    
    // allocate dense matrix for overlap integrals
    
    CDenseMatrix ovlmat(nrow, ncol);
    
    // set up distributio pattern
    
    dist1e dstyp = (symbk) ? dist1e::symsq : dist1e::rect;
    
    COneIntsDistribution* distpat = new COneIntsDistribution(ovlmat.values(),
                                                             nrow, ncol, dstyp);
    
    // compute overlap integral blocks
    
    #pragma omp parallel shared(braGtoContainer, ketGtoContainer, distpat, symbk)
    {
        #pragma omp single nowait
        {
            // determine number of GTOs blocks in bra/ket sides
            
            auto nbra = braGtoContainer->getNumberOfGtoBlocks();
            
            auto nket = ketGtoContainer->getNumberOfGtoBlocks();
            
            // loop over pairs of GTOs blocks
            
            for (int32_t i = 0; i < nbra; i++)
            {
                auto bgtos = braGtoContainer->getGtoBlock(i);
                
                auto joff = (symbk) ? i : 0;
                
                for (int32_t j = joff; j < nket; j++)
                {
                    #pragma omp task firstprivate(j)
                    {
                        auto kgtos = ketGtoContainer->getGtoBlock(j);
                        
                        _compOverlapForGtoBlocks(distpat, bgtos, kgtos);
                    }
                }
            }
        }
    }
    
    // deallocate distribution pattern
    
    delete distpat;
    
    return COverlapMatrix(ovlmat);
}

void
COverlapIntegralsDriver::_compOverlapForGtoBlocks(      COneIntsDistribution* distPattern,
                                                  const CGtoBlock&            braGtoBlock,
                                                  const CGtoBlock&            ketGtoBlock) const
{
    // copy GTOs blocks for bra and ket sides
    
    auto bragtos = braGtoBlock;
    
    auto ketgtos = ketGtoBlock;
    
    // copy distribution pattern
    
    auto distpat = *distPattern;
    
    // set up spherical angular momentum for bra and ket sides
    
    CSphericalMomentum bmom(bragtos.getAngularMomentum());
    
    CSphericalMomentum kmom(ketgtos.getAngularMomentum());
    
    // allocate prefactors used in Obara-Saika recursion
    
    auto pdim = ketgtos.getNumberOfPrimGtos();
    
    CMemBlock2D<double> rab(pdim, 3);
    
    auto pmax = bragtos.getMaxContractionDepth();
    
    CMemBlock2D<double> rfacts(pdim, 2 * pmax);
    
    CMemBlock2D<double> rpa(pdim, 3 * pmax);
    
    CMemBlock2D<double> rpb(pdim, 3 * pmax);
    
    // generate recursion pattern
    
    auto recvec = _getRecursionPattern(bragtos, ketgtos);
    
    // set up angular momentum data
    
    auto bang = bragtos.getAngularMomentum();
    
    auto kang = ketgtos.getAngularMomentum();
    
    // set up primitives buffer indexes
    
    std::vector<int32_t> recidx;
    
    auto nblk = _getIndexesForRecursionPattern(recidx, recvec, pmax);
    
    auto pidx = genfunc::findPairIndex(recidx, recvec, {bang, kang});
    
    // allocate primitives integrals buffer
    
    CMemBlock2D<double> pbuffer(pdim, nblk);
    
    // set up contracted GTOs dimensions
    
    auto ngfunc = bragtos.getMaxNumberContrFunctions();
    
    auto kdim = ketgtos.getNumberOfContrGtos();
    
    // allocate contracted Cartesian integrals buffer
    
    auto ncart = angmom::to_CartesianComponents(bang, kang);
    
    CMemBlock2D<double> cartbuffer(kdim * ngfunc, ncart);
    
    // allocate contracted spherical integrals buffer
    
    auto nspher = angmom::to_SphericalComponents(bang, kang);
    
    CMemBlock2D<double> spherbuffer(kdim * ngfunc, nspher);
    
    // determine bra and ket sides symmetry
    
    bool symbk = (bragtos == ketgtos);
    
    // contraction pattern on bra side
    
    auto sbcpos = bragtos.getContrStartPositions();
    
    auto ebcpos = bragtos.getContrEndPositions();

    for (int32_t i = 0; i < bragtos.getNumberOfRedContrGtos(); i++)
    {
        auto bgfunc = ebcpos[i] - sbcpos[i];
        
        // compute distances: R(AB) = A - B
        
        intsfunc::compDistancesAB(rab, bragtos, ketgtos, i);
        
        // compute Obara-Saika recursion factors
        
        intsfunc::compFactorsForOverlap(rfacts, bragtos, ketgtos, i);
        
        // compute distances: R(PA) = P - A
        
        intsfunc::compDistancesPA(rpa, rab, rfacts, 2, bragtos, ketgtos, i);
        
        // compute distances: R(PB) = P - B
        
        intsfunc::compDistancesPB(rpb, rab, rfacts, 2, bragtos, ketgtos, i);
        
        // compite primitive overlap integrals
        
        _compPrimOverlapInts(pbuffer, recvec, recidx, rfacts, rab, rpa, rpb,
                             bragtos, ketgtos, i);
        
        // contract primitive overlap integrals
        
        genfunc::contract(cartbuffer, pbuffer, pidx, bragtos, ketgtos, i);
        
        // transform Cartesian to spherical integrals
        
        genfunc::transform(spherbuffer, cartbuffer, bmom, kmom, 0, 0,
                           bgfunc * kdim);
        
        // add batch of integrals to integrals matrix
        
        distpat.distribute(spherbuffer, bragtos, ketgtos, symbk, i);
    }
}

void
COverlapIntegralsDriver::_compPrimOverlapInts(      CMemBlock2D<double>&  primBuffer,
                                              const CVecTwoIndexes&       recPattern,
                                              const std::vector<int32_t>& recIndexes,
                                              const CMemBlock2D<double>&  osFactors,
                                              const CMemBlock2D<double>&  abDistances,
                                              const CMemBlock2D<double>&  paDistances,
                                              const CMemBlock2D<double>&  pbDistances,
                                              const CGtoBlock&            braGtoBlock,
                                              const CGtoBlock&            ketGtoBlock,
                                              const int32_t               iContrGto) const
{
    // compute (s|s) integrals
    
    ovlrecfunc::compOverlapForSS(primBuffer, recPattern, recIndexes, osFactors,
                                 abDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (s|p) integrals
    
    ovlrecfunc::compOverlapForSP(primBuffer, recPattern, recIndexes, pbDistances,
                                 braGtoBlock, ketGtoBlock, iContrGto);
    
    // compute (p|s) integrals
    
    ovlrecfunc::compOverlapForPS(primBuffer, recPattern, recIndexes, paDistances,
                                 braGtoBlock, ketGtoBlock, iContrGto);
    
    // compute (p|p) integrals
    
    ovlrecfunc::compOverlapForPP(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (s|d) integrals
    
    ovlrecfunc::compOverlapForSD(primBuffer, recPattern, recIndexes, osFactors,
                                 pbDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);

    // compute (d|s) integrals
    
    ovlrecfunc::compOverlapForDS(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (p|d) integrals
    
    ovlrecfunc::compOverlapForPD(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (d|p) integrals
    
    ovlrecfunc::compOverlapForDP(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (d|d) integrals
    
    ovlrecfunc::compOverlapForDD(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (s|f) integrals
    
    ovlrecfunc::compOverlapForSF(primBuffer, recPattern, recIndexes, osFactors,
                                 pbDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (f|s) integrals
    
    ovlrecfunc::compOverlapForFS(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (p|f) integrals
    
    ovlrecfunc::compOverlapForPF(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (f|p) integrals
    
    ovlrecfunc::compOverlapForFP(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (d|f) integrals
    
    ovlrecfunc::compOverlapForDF(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (f|d) integrals
    
    ovlrecfunc::compOverlapForFD(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);

    // compute (f|f) integrals
    
    ovlrecfunc::compOverlapForFF(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (s|g) integrals
    
    ovlrecfunc::compOverlapForSG(primBuffer, recPattern, recIndexes, osFactors,
                                 pbDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (g|s) integrals
    
    ovlrecfunc::compOverlapForGS(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (p|g) integrals
   
    ovlrecfunc::compOverlapForPG(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (g|p) integrals
    
    ovlrecfunc::compOverlapForGP(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (d|g) integrals
    
    ovlrecfunc::compOverlapForDG(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (g|d) integrals
    
    ovlrecfunc::compOverlapForGD(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (f|g) integrals
    
    ovlrecfunc::compOverlapForFG(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);
    
    // compute (g|f) integrals
    
    ovlrecfunc::compOverlapForGF(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);

    // compute (g|g) integrals
    
    ovlrecfunc::compOverlapForGG(primBuffer, recPattern, recIndexes, osFactors,
                                 paDistances, braGtoBlock, ketGtoBlock,
                                 iContrGto);

    // NOTE: add l > 4 recursion here
}

CVecTwoIndexes
COverlapIntegralsDriver::_getRecursionPattern(const CGtoBlock& braGtoBlock,
                                              const CGtoBlock& ketGtoBlock) const
{
    // set up angular momentum
    
    auto bang = braGtoBlock.getAngularMomentum();
    
    auto kang = ketGtoBlock.getAngularMomentum();
 
    // set up recursion buffer
    
    CVecTwoIndexes recvec;
    
    recvec.reserve((bang + 1) * (kang + 1));
    
    // set up indexing counters
    
    int32_t spos = 0;
    
    int32_t epos = 1;
    
    // set up initial state of recursion buffer
    
    recvec.push_back(CTwoIndexes(bang, kang));
    
    while (true)
    {
        // internal new recursion terms counter
        
        int32_t nterms = 0;
        
        // generate bra and ket Obara-Saika recursion terms
        
        for (int32_t i = spos; i < epos; i++)
        {
            CTwoIndexes cidx(recvec[i]);
        
            if (cidx.first() != 0)
            {
                // general recursion for bra and ket sides
                
                // (a - 1 | b) term
            
                CTwoIndexes t1idx(cidx.first() - 1,  cidx.second());
            
                if (genfunc::addValidAndUniquePair(recvec, t1idx)) nterms++;
            
                // (a - 2 | b) term
            
                CTwoIndexes t2idx(cidx.first() - 2,  cidx.second());
            
                if (genfunc::addValidAndUniquePair(recvec, t2idx)) nterms++;
            
                // (a - 1 | b - 1) term
            
                CTwoIndexes tkidx(cidx.first() - 1,  cidx.second() - 1);
            
                if (genfunc::addValidAndUniquePair(recvec, tkidx)) nterms++;
            }
            else
            {
                // reduced recursion for ket side
                
                // (0 | b - 1) term
                
                CTwoIndexes t1idx(cidx.first(),  cidx.second() - 1);
                
                if (genfunc::addValidAndUniquePair(recvec, t1idx)) nterms++;
                
                // (0 | b - 2) term
                
                CTwoIndexes t2idx(cidx.first(),  cidx.second() - 2);
                
                if (genfunc::addValidAndUniquePair(recvec, t2idx)) nterms++;
            }
                
        }
        
        // break loop, all recursion terms are generrated
        
        if (nterms == 0) break;
        
        // update counters
        
        spos  = epos;
        
        epos += nterms;
    }
    
    return recvec;
}


int32_t
COverlapIntegralsDriver::_getIndexesForRecursionPattern(      std::vector<int32_t>& recIndexes,
                                                        const CVecTwoIndexes&       recPattern,
                                                        const int32_t               maxPrimGtos) const
{
    // clear vector and reserve memory
    
    recIndexes.clear();
    
    recIndexes.reserve(recPattern.size() + 1);
 
    // loop over recursion pattern
    
    int32_t nblk = 0;
    
    for (size_t i = 0; i < recPattern.size(); i++)
    {
        recIndexes.push_back(nblk);
        
        nblk += maxPrimGtos * angmom::to_CartesianComponents(recPattern[i].first(),
                                                             recPattern[i].second());
    }
    
    return nblk;
}
