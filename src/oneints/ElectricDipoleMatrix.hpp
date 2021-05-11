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

#ifndef ElectricDipoleMatrix_hpp
#define ElectricDipoleMatrix_hpp

#include <array>
#include <cstdint>
#include <string>

#include "CartesianComponents.hpp"
#include "DenseMatrix.hpp"

/**
 Class CElectricDipoleMatrix stores electric dipole matrix and provides
 set of methods for handling of electric dipole matrix data.

 @author Z. Rinkevicius
 */
class CElectricDipoleMatrix
{
    /**
     The X coordinate of electric dipole origin.
     */
    double _xOrigin;

    /**
     The Y coordinate of electric dipole origin.
     */
    double _yOrigin;

    /**
     The Z coordinate of electric dipole origin.
     */
    double _zOrigin;

    /**
     The generic dense x component of electric dipole matrix (rectangular or
     square).
     */
    CDenseMatrix _xMatrix;

    /**
     The generic dense Y component of electric dipole matrix (rectangular or
     square).
     */
    CDenseMatrix _yMatrix;

    /**
     The generic dense Z component of electric dipole matrix (rectangular or
     square).
     */
    CDenseMatrix _zMatrix;

   public:
    /**
     Creates an empty electric dipole  matrix object.
     */
    CElectricDipoleMatrix();

    /**
     Creates a electric dipole matrix object.

     @param xMatrix the dense matrix with X component of electric dipole
            integrals.
     @param yMatrix the dense matrix with Y component of electric dipole
            integrals.
     @param zMatrix the dense matrix with Z component of electric dipole
            integrals.
     @param xOrigin the Cartesian X coordinate of electric dipole origin.
     @param yOrigin the Cartesian Y coordinate of electric dipole origin.
     @param zOrigin the Cartesian Z coordinate of electric dipole origin.
     */
    CElectricDipoleMatrix(const CDenseMatrix& xMatrix,
                          const CDenseMatrix& yMatrix,
                          const CDenseMatrix& zMatrix,
                          const double        xOrigin,
                          const double        yOrigin,
                          const double        zOrigin);

    /**
     Creates a electric dipole matrix object.

     @param matrices cartesian componentes of the electric dipole integrals.
     @param origin the Cartesian coordinates of the electric dipole origin.
     */
    CElectricDipoleMatrix(const std::array<CDenseMatrix, 3>& matrices,
                          const std::array<double, 3>& origin);

    /**
     Creates a electric dipole matrix object by copying other electric dipole
     matrix object.

     @param source the electric dipole matrix object.
     */
    CElectricDipoleMatrix(const CElectricDipoleMatrix& source);

    /**
     Creates a electric dipole  matrix object by moving other electric dipole
     matrix object.

     @param source the electric dipole matrix object.
     */
    CElectricDipoleMatrix(CElectricDipoleMatrix&& source) noexcept;

    /**
     Destroys a electric dipole matrix object.
     */
    ~CElectricDipoleMatrix();

    /**
     Assigns a electric dipole  matrix object by copying other electric dipole
     matrix object.

     @param source the electric dipole matrix object.
     */
    CElectricDipoleMatrix& operator=(const CElectricDipoleMatrix& source);

    /**
     Assigns a electric dipole matrix object by moving other electric dipole
     matrix object.

     @param source the electric dipole matrix object.
     */
    CElectricDipoleMatrix& operator=(CElectricDipoleMatrix&& source) noexcept;

    /**
     Compares electric dipole matrix object with other electric dipole matrix
     object.

     @param other the electric dipole matrix object.
     @return true if electric dipole matrix objects are equal, false otherwise.
     */
    bool operator==(const CElectricDipoleMatrix& other) const;

    /**
     Compares electric dipole  matrix object with other electric dipole matrix
     object.

     @param other the electric dipole  matrix object.
     @return true if electric dipole  matrix objects are not equal, false
     otherwise.
     */
    bool operator!=(const CElectricDipoleMatrix& other) const;

    /**
     Sets coordinates of electric dipole origin.

     @param xOrigin the X coordinate of electric dipole origin.
     @param yOrigin the Y coordinate of electric dipole origin.
     @param zOrigin the Z coordinate of electric dipole origin.
     */
    void setOriginCoordinates(const double xOrigin, const double yOrigin, const double zOrigin);

    /**
     Sets coordinates of electric dipole origin.

     @param origin an array holding the Cartesian coordinates for the electric dipole origin.
     */
    void setOriginCoordinates(const std::array<double, 3>& origin);

    /**
     Gets string representation of electric dipole matrix.

     @return a string for printing the electric dipole matrix.
     */
    std::string getString() const;

    /**
     Gets string representation of X component of electric dipole matrix.

     @return a string for printing the X component of electric dipole matrix.
     */
    std::string getStringForComponentX() const;

    /**
     Gets string representation of Y component of electric dipole matrix.

     @return a string for printing the Y component of electric dipole matrix.
     */
    std::string getStringForComponentY() const;

    /**
     Gets string representation of Z component of electric dipole matrix.

     @return a string for printing the Z component of electric dipole matrix.
     */
    std::string getStringForComponentZ() const;

    /**
     Gets number of rows in electric dipole matrix.

     @return the number of rows.
     */
    int32_t getNumberOfRows() const;

    /**
     Gets number of columns in electric dipole matrix.

     @return the number of columns.
     */
    int32_t getNumberOfColumns() const;

    /**
     Gets number of elements in electric dipole matrix.

     @return the number of elements.
     */
    int32_t getNumberOfElements() const;

    /**
     Gets constant pointer to first element of X component of electric dipole
     matrix.

     @return the constant pointer to first element of X component of electric
     dipole matrix.
     */
    const double* xvalues() const;

    /**
     Gets constant pointer to first element of Y component of electric dipole
     matrix.

     @return the constant pointer to first element of Y component of electric
     dipole matrix.
     */
    const double* yvalues() const;

    /**
     Gets constant pointer to first element of Z component of electric dipole
     matrix.

     @return the constant pointer to first element of Z component of electric
     dipole matrix.
     */
    const double* zvalues() const;

    /**
     Gets constant pointer to first element of requested component of electric dipole
     matrix.

     @param cart requested Cartesian component of the electric dipole integrals matrix

     @return the constant pointer to first element of requested component of electric
     dipole matrix.
     */
    const double* values(cartesians cart) const;

    /**
     Gets constant pointer to first element of requested component of electric dipole
     matrix.

     @param cart requested Cartesian component of the electric dipole integrals matrix

     @return the constant pointer to first element of requested component of electric
     dipole matrix.
     */
    const double* values(int32_t cart) const;

    /**
     Gets coordinates of electric dipole origin.

     @return the coordinates of electric dipole origin.
     */
    std::array<double, 3> getOriginCoordinates() const;

    /**
     Gets X coordinate of electric dipole origin.

     @return the X coordinate of electric dipole origin.
     */
    double getOriginCoordinateX() const;

    /**
     Gets Y coordinate of electric dipole origin.

     @return the Y coordinate of electric dipole origin.
     */
    double getOriginCoordinateY() const;

    /**
     Gets Z coordinate of electric dipole origin.

     @return the Z coordinate of electric dipole origin.
     */
    double getOriginCoordinateZ() const;

    /**
     Converts electric dipole matrix object to text output.
     */
    std::string repr() const;
};

/**
 Converts electric dipole matrix object to text output and insert it into
 output text stream.

 @param output the output text stream.
 @param source the electric dipole matrix object.
 */
std::ostream& operator<<(std::ostream& output, const CElectricDipoleMatrix& source);

#endif /* ElectricDipoleMatrix_hpp */
