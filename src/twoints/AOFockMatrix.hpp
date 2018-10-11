//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#ifndef AOFockMatrix_hpp
#define AOFockMatrix_hpp

#include <cstdint>
#include <vector>

#include "DenseMatrix.hpp"
#include "FockMatrixType.hpp"
#include "AODensityMatrix.hpp"

/**
 Class CAOFockMatrix stores set of AO Fock matrices and provides set of methods
 for handling of AO Fock matrices data.
 
 @author Z. Rinkevicius
 */
class CAOFockMatrix
{
    /**
     The set of Fock matrices.
     */
    std::vector<CDenseMatrix> _fockMatrices;
    
    /**
     The set of Fock matrices types.
     */
    std::vector<fockmat> _fockTypes;
    
    /**
     The scaling factors for exchange contributions.
     */
    std::vector<double> _scaleFactors;
    
    /**
     The set of identifiers of density matrices used to construct Fock matrices.
     */
    std::vector<int32_t> _idDensityMatrices;
    
public:
    
    /**
     Creates an empty AO Fock matrix object.
     */
    CAOFockMatrix();
    
    /**
     Creates a AO Fock matrix object.
     
     @param fockMatrices the set of Fock matrices.
     @param fockTypes the set of Fock matrices types.
     @param scaleFactors the set of scaling factors for exchange contributions.
     @param idDensityMatrices the set of identifiers used to construct Fock
            matrices.
     */
    CAOFockMatrix(const std::vector<CDenseMatrix>& fockMatrices,
                  const std::vector<fockmat>&      fockTypes,
                  const std::vector<double>&       scaleFactors,
                  const std::vector<int32_t>&      idDensityMatrices);
    
    /**
     Creates a AO Fock matrix object.
     
     @param aoDensityMatrix the AO density matrix.
     */
    CAOFockMatrix(const CAODensityMatrix& aoDensityMatrix);
    
    /**
     Creates a AO Fock matrix object by copying other AO Fock matrix object.
     
     @param source the AO Fock matrix object.
     */
    CAOFockMatrix(const CAOFockMatrix& source);
    
    /**
     Creates a AO Fock matrix object by moving other AO Fock matrix object.
     
     @param source the AO Fock matrix object.
     */
    CAOFockMatrix(CAOFockMatrix&& source) noexcept;
    
    /**
     Destroys a AO Fock matrix object.
     */
    ~CAOFockMatrix();
    
    /**
     Assigns a AO Fock matrix object by copying other AO Fock matrix object.
     
     @param source the AO Fock matrix object.
     */
    CAOFockMatrix& operator=(const CAOFockMatrix& source);
    
    /**
     Assigns a AO Fock matrix object by moving other AO Fock matrix object.
     
     @param source the AO Fock matrix object.
     */
    CAOFockMatrix& operator=(CAOFockMatrix&& source) noexcept;
    
    /**
     Compares AO Fock matrix object with other AO Fock matrix object.
     
     @param other the AO Fock matrix object.
     @return true if AO Fock matrix objects are equal, false otherwise.
     */
    bool operator==(const CAOFockMatrix& other) const;
    
    /**
     Compares AO Fock matrix object with other AO Fock matrix object.
     
     @param other the AO Fock matrix object.
     @return true if AO Fock matrix objects are not equal, false otherwise.
     */
    bool operator!=(const CAOFockMatrix& other) const;
    
    
    /**
     Resets all elements of AO Fock matrix to zero.
     */
    void zero();
    
    /**
     Gets number of Fock matrices.
     
     @return the number of Fock matrices.
     */
    int32_t getNumberOfFockMatrices() const;
    
    /**
     Gets number of rows in specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the number of rows.
     */
    int32_t getNumberOfRows(const int32_t iFockMatrix) const;
    
    /**
     Gets number of columns in specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the number of columns.
     */
    int32_t getNumberOfColumns(const int32_t iFockMatrix) const;
    
    /**
     Gets number of elements in specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the number of elements.
     */
    int32_t getNumberOfElements(const int32_t iFockMatrix) const;
    
    /**
     Gets constant pointer to first element of specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the constant pointer to first element of Fock matrix.
     */
    const double* getFock(const int32_t iFockMatrix) const;
    
    /**
     Gets pointer to first element of specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the pointer to first element of Fock matrix.
     */
    double* getFock(const int32_t iFockMatrix);
    
    /**
     Gets type of specific Fock matrix.

     @param iFockMatrix the index of Fock matrix.
     @return the type of Fock matrix.
     */
    fockmat getFockType(const int32_t iFockMatrix) const;
    
    /**
     Gets scaling factor of exchange contribution for specific Fock matrix.
     
     @param iFockMatrix the index of Fock matrix.
     @return the scaling factor.
     */
    double getScaleFactor(const int32_t iFockMatrix) const;
    
    /**
     Gets identifier of AO density matrix used to construct specific Fock matrix.

     @param iFockMatrix the index of Fock matrix.
     @return the identifier of density matrix.
     */
    int32_t getDensityIdentifier(const int32_t iFockMatrix) const;
    
    /**
     Gets string representation of density matrix object.

     @return the string representation of density matrix.
     */
    std::string getString() const;
    
    /**
     Converts AO Fock matrix object to text output and insert it into output
     text stream.
     
     @param output the output text stream.
     @param source the AO Fock matrix object.
     */
    friend std::ostream& operator<<(      std::ostream&     output,
                                    const CAOFockMatrix& source);
};


#endif /* AOFockMatrix_hpp */
