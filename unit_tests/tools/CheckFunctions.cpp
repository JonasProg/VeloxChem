//
//                           VELOXCHEM 1.0-RC
//      ---------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2020 by VeloxChem developers. All rights reserved.
//  Contact: https://veloxchem.org/contact

#include "CheckFunctions.hpp"

#include "gtest/gtest.h"

namespace vlxtest {  // namespace

void
compare(const std::vector<double>& aVector, const double* bVector)
{
    vlxtest::compare(aVector, bVector, 1.0e-13);
}

void
compare(const std::vector<double>& aVector, const double* bVector, const double threshod)
{
    for (size_t i = 0; i < aVector.size(); i++)
    {
        ASSERT_NEAR(aVector[i], bVector[i], threshod);
    }
}

void
compare(const std::vector<int32_t>& aVector, const int32_t* bVector)
{
    for (size_t i = 0; i < aVector.size(); i++)
    {
        ASSERT_EQ(aVector[i], bVector[i]);
    }
}

void
compare(const int32_t* aVector, const int32_t* bVector, const int32_t nElements)
{
    for (int32_t i = 0; i < nElements; i++)
    {
        ASSERT_EQ(aVector[i], bVector[i]);
    }
}

void
compare(const double* aVector, const double* bVector, const int32_t nElements)
{
    for (int32_t i = 0; i < nElements; i++)
    {
        ASSERT_NEAR(aVector[i], bVector[i], 1.0e-13);
    }
}

void
compare(const std::vector<double>& aVector, const std::vector<double>& bVector)
{
    ASSERT_EQ(aVector.size(), bVector.size());

    if (aVector.size() == bVector.size())
    {
        for (size_t i = 0; i < aVector.size(); i++)
        {
            ASSERT_NEAR(aVector[i], bVector[i], 1.0e-13);
        }
    }
}

void
compare(const std::vector<int32_t>& aVector, const std::vector<int32_t>& bVector)
{
    ASSERT_EQ(aVector.size(), bVector.size());

    if (aVector.size() == bVector.size())
    {
        for (size_t i = 0; i < aVector.size(); i++)
        {
            ASSERT_EQ(aVector[i], bVector[i]);
        }
    }
}

void
checkNorm(const double* aVector, const int32_t nElements)
{
    double fsum = 0.0;

    for (int32_t i = 0; i < nElements; i++)
        fsum += aVector[i];

    ASSERT_NEAR(fsum, 1.0, 1.0e-13);
}

}  // namespace vlxtest
