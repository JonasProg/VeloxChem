#ifndef MathFunc_hpp
#define MathFunc_hpp

#include <array>
#include <cmath>
#include <vector>

#include "CustomConstrains.hpp"

namespace mathfunc {  // mathfunc

/// @brief Compares two floating point values.
/// @tparam T The floating point type.
/// @param flhs The left-hand-side floating point value to compare.
/// @param frhs The rigth-hand-side floating point value to compare.
/// @param rtol The relative tollerance.
/// @param atol The absolute tollerance.
/// @return True if floating point values are equal, False otherwise.
template <FloatingPoint T>
inline auto
equal(const T flhs, const T frhs, const T rtol, const T atol) -> bool
{
    return std::fabs(flhs - frhs) < std::max(atol, rtol * std::max(std::fabs(flhs), std::fabs(frhs)));
}

/// @brief Gets upper triangular matrix linearized index (column wise scheme).
/// @param i The index of row in matrix.
/// @param j The index of collumn in matrix.
/// @return The linearized index.
template <Integral T>
inline auto
uplo_index(const T i, const T j) -> T
{
    return i + j * (j + 1) / 2;
}

}  // namespace mathfunc

#endif /* MathFunc_hpp */
