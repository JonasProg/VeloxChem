//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.
//  Contact: Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.

#ifndef ExcitationVector_hpp
#define ExcitationVector_hpp

#include <cstdint>
#include <ostream>
#include <vector>
#include <string>

#include "SpinBlock.hpp"
#include "MemBlock.hpp"
#include "AODensityMatrix.hpp"
#include "MolecularOrbitals.hpp"
#include "DenseMatrix.hpp"

/**
Class CExcitationVector class stores information on one particle excitation and
provides set of methods for manipulating their data.

@author Z. Rinkevicius
*/
class CExcitationVector
{
    /**
     The type of generating excitations.
     */
    szblock _excitationType;
    
    /**
     The vector of molecular orbital indexes for bra side.
     */
    CMemBlock<int32_t> _braIndexes;
    
    /**
     The vector of molecular orbital indexes for ket side.
     */
    CMemBlock<int32_t> _ketIndexes;
    
    /**
     The vector of Z coefficients associated with one particle excitations.
     */
    CMemBlock<double> _zCoefficents;
    
    /**
     The vector of Y coefficients associated with one particle deexcitations.
     */
    CMemBlock<double> _yCoefficents;
    
    /**
     Converts index of molecular orbital to unified index of Z or Y matrix.

     @param identifiers the vector of molecular orbital indexes.
     @param index the index of molecular orbital.
     @return the converted index.
     */
    int32_t _convertIdentifier(const std::vector<int32_t>& identifiers,
                               const int32_t               index) const;
    
    /**
     Gets subset of molecular orbitals corresponding to unique list of
     anihilation operators from molecular orbitals object.

     @param molecularOrbitals the molecular orbitals.
     @param identifiers the vector of molecular orbital indexes.
     @return the dense matrix with selected molecular orbitals
     */
    CDenseMatrix _getBraOrbitals(const CMolecularOrbitals&   molecularOrbitals,
                                 const std::vector<int32_t>& identifiers) const;
    
    /**
     Gets subset of molecular orbitals corresponding to unique list of creation
     operators from molecular orbitals object.
     
     @param molecularOrbitals the molecular orbitals.
     @param identifiers the vector of molecular orbital indexes.
     @return the dense matrix with selected molecular orbitals
     */
    CDenseMatrix _getKetOrbitals(const CMolecularOrbitals&   molecularOrbitals,
                                 const std::vector<int32_t>& identifiers) const;
    
public:
    
    /**
     Creates an empty excitation vector object.
     */
    CExcitationVector();
    
    /**
     Creates a excitation vector object.
     
     @param excitationType the single particle excitation type.
     @param braIndexes the vector of molecular orbital indexes on bra side.
     @param ketIndexes the vector of molecular orbital indexes on ket side.
     @param zCoefficients the vector of Z coefficients associates with single
            particle excitations.
     @param yCoefficients the vector of Y coefficients associates with single
            particle de-excitations.
     */
    CExcitationVector(const szblock               excitationType,
                      const std::vector<int32_t>& braIndexes,
                      const std::vector<int32_t>& ketIndexes,
                      const std::vector<double>&  zCoefficients,
                      const std::vector<double>&  yCoefficients);
    
    /**
     Creates a excitation vector object.
     
     @param excitationType the single particle excitation type.
     @param braStartPosition the start position in molecular orbital space on
            bra side.
     @param braEndPosition the end position in molecular orbital space on bra
            side.
     @param ketStartPosition the start position in molecular orbital space on
            ket side.
     @param ketEndPosition the end position in molecular orbital space on ket
            side.
     @param isTammDancoff the flag for enabling Tamm-Dancoff approximation.
     */
    CExcitationVector(const szblock excitationType,
                      const int32_t braStartPosition,
                      const int32_t braEndPosition,
                      const int32_t ketStartPosition,
                      const int32_t ketEndPosition,
                      const bool    isTammDancoff);
    
    /**
     Creates a excitation vector object.
     
     @param excitationType the single particle excitation type.
     @param braStartPosition the start position in molecular orbital space on
            bra side.
     @param braEndPosition the end position in molecular orbital space on bra
            side.
     @param ketStartPosition the start position in molecular orbital space on
            ket side.
     @param ketEndPosition the end position in molecular orbital space on ket
            side.
     */
    CExcitationVector(const szblock excitationType,
                      const int32_t braStartPosition,
                      const int32_t braEndPosition,
                      const int32_t ketStartPosition,
                      const int32_t ketEndPosition);
    
    /**
     Creates a excitation vector object by copying other excitation vector object.
     
     @param source the excitation vector object.
     */
    CExcitationVector(const CExcitationVector& source);
    
    /**
     Creates a excitation vector object by moving other excitation vector object.
     
     @param source the excitation vector object.
     */
    CExcitationVector(CExcitationVector&& source) noexcept;
    
    /**
     Destroys a excitation vector object.
     */
    ~CExcitationVector();
    
    /**
     Assigns a excitation vector object by copying other excitation vector object.
     
     @param source the excitation vector object.
     */
    CExcitationVector& operator=(const CExcitationVector& source);
    
    /**
     Assigns a excitation vector object by moving other excitation vector object.
     
     @param source the excitation vector object.
     */
    CExcitationVector& operator=(CExcitationVector&& source) noexcept;
    
    /**
     Compares excitation vector object with other excitation vector object.
     
     @param other the excitation vector object.
     @return true if excitation vector objects are equal, false otherwise.
     */
    bool operator==(const CExcitationVector& other) const;
    
    /**
     Compares excitation vector object with other excitation vector object.
     
     @param other the excitation vector object.
     @return true if excitation vector objects are not equal, false otherwise.
     */
    bool operator!=(const CExcitationVector& other) const;
    
    /**
     Sets Z and Y coefficient vectors.

     @param zCoefficients the Z coefficients vector.
     @param yCoefficients the Y coefficients vector.
     */
    void setCoefficientsZY(const CMemBlock<double>& zCoefficients,
                           const CMemBlock<double>& yCoefficients);
    
    /**
     Sets specific element of Z coefficients vector.

     @param zValue the value of Z coefficient.
     @param iCoefficient the index of Z coefficient.
     */
    void setCoefficientZ(const double  zValue,
                         const int32_t iCoefficient);
    
    /**
     Sets specific element of Y coefficients vector.
     
     @param yValue the value of Y coefficient.
     @param iCoefficient the index of Y coefficient.
     */
    void setCoefficientY(const double  yValue,
                         const int32_t iCoefficient);
    
    /**
     Gets pointer to first element of Z coefficients vector.

     @return the pointer to first element of Z coefficients vector.
     */
    double* getCoefficientsZ();
    
    /**
     Gets constant pointer to first element of Z coefficients vector.
     
     @return the constant pointer to first element of Z coefficients vector.
     */
    const double* getCoefficientsZ() const;
    
    /**
     Gets pointer to first element of Y coefficients vector.
     
     @return the pointer to first element of Y coefficients vector.
     */
    double* getCoefficientsY();
    
    /**
     Gets constant pointer to first element of Y coefficients vector.
     
     @return the constant pointer to first element of Y coefficients vector.
     */
    const double* getCoefficientsY() const;
    
    /**
     Gets number of one particle excitations in excitations vector.

     @return the number of one particle excitations.
     */
    int32_t getNumberOfExcitations() const;
    
    /**
     Gets vector of unique molecular orbitals indexes associated with creation
     operator in one particle excitations vector.

     @return the vector of unique indexes.
     */
    std::vector<int32_t> getBraUniqueIndexes() const;
    
    /**
     Gets vector of unique molecular orbitals indexes associated with
     anihilation operator in one particle excitations vector.
     
     @return the vector of unique indexes.
     */
    std::vector<int32_t> getKetUniqueIndexes() const;
    
    /**
     Transforms Z vector to matrix (occ, virt) format.

     @return the dense matrix.
     */
    CDenseMatrix getMatrixZ() const;
    
    /**
     Transforms Y vector to matrix (virt, occ) format.
     
     @return the dense matrix.
     */
    CDenseMatrix getMatrixY() const;
    
    /**
     Transforms Z vector to AO density matrix.
     
     @return the AO density matrix.
     */
    CAODensityMatrix getDensityZ(const CMolecularOrbitals& molecularOrbitals) const;
    
    /**
     Transforms Y vector to AO density matrix.
     
     @return the AO density matrix.
     */
    CAODensityMatrix getDensityY(const CMolecularOrbitals& molecularOrbitals) const;
    
    /**
     Converts excitation vector object to it's string representation.

     @return the string representation of excitation vector object.
     */
    std::string getString() const;
    
    /**
     Converts excitation vector object to text output and insert it into output
     text stream.
     
     @param output the output text stream.
     @param source the excitation vector object.
     */
    friend std::ostream& operator<<(      std::ostream&      output,
                                    const CExcitationVector& source);
};

#endif /* ExcitationVector_hpp */
