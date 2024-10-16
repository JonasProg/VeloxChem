//
//                              VELOXCHEM
//         ----------------------------------------------------
//                     An Electronic Structure Code
//
//  Copyright © 2018-2024 by VeloxChem developers. All rights reserved.
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

#ifndef MemAlloc_hpp
#define MemAlloc_hpp

#ifdef _MSC_VER
#include <malloc.h>
#else
#include <cstdlib>
#endif
#include <cstddef>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>

#ifdef ENABLE_MKL
#include <mkl_service.h>  // needed for mkl_malloc and mkl_free
#endif

#include "ErrorHandler.hpp"

namespace mem {

namespace detail {

/** Aligned malloc to be used.
 *
 * - When linking against MKL, use `mkl_malloc`. Otherwise:
 *   * On Windows, use the intrinsic `_aligned_malloc`. See:
 * https://developercommunity.visualstudio.com/t/c17-stdaligned-alloc%E7%BC%BA%E5%A4%B1/468021
 *   * On Linux, use `::posix_memalign`
 */
inline auto __vlx_malloc =
#ifdef ENABLE_MKL
    [](size_t count_bytes, size_t alignment) -> void * {
        return mkl_malloc(count_bytes, static_cast<int>(alignment));
    };
#else  // ENABLE_MKL
#ifdef _MSC_VER
    _aligned_malloc;
#else  // _MSC_VER
    [](size_t count_bytes, size_t alignment) -> void * {
        void *ptr = nullptr;
        auto ierr = ::posix_memalign(&ptr, alignment, count_bytes);
        errors::assertMsgCritical(ierr == 0, "posix_memalign failed");
        return ptr;
    };
#endif
#endif

/** Aligned free to be used.
 *
 * - When linking against MKL, use `mkl_free`. Otherwise:
 *   * On Windows, use the intrinsic `_aligned_free`. See:
 * https://developercommunity.visualstudio.com/t/c17-stdaligned-alloc%E7%BC%BA%E5%A4%B1/468021
 *   * On Linux, use `::free`
 */
inline auto __vlx_free =
#ifdef ENABLE_MKL
    mkl_free;
#else  // ENABLE_MKL
#ifdef _MSC_VER
    _aligned_free;
#else  // _MSC_VER
    ::free;
#endif
#endif

/** Aligned allocation of given type on the host.
 *
 * @tparam T scalar type of the allocation.
 * @param[in] alignment desired alignment of allocation.
 * @param[in] count number of element in allocation, including padding.
 * @return pointer to the allocation
 *
 * @note Alignment must be a power of 2.
 */
template <typename T>
auto
allocate(size_t alignment, size_t count) -> T *
{
    if (count == 0)
    {
        return nullptr;
    }

    // check that alignment is a power of 2
    // http://www.graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
    errors::assertMsgCritical((alignment && !(alignment & (alignment - 1))), std::string(__func__) + ": alignment must be a power of 2");

    // check that we are not trying to allocate too big a chunk
    if (count > std::numeric_limits<size_t>::max() / sizeof(T))
    {
        // equivalent of: throw std::bad_array_new_length();
        errors::assertMsgCritical(false, std::string(__func__) + ": you cannot allocate a memory block with " + std::to_string(count) + " elements");

        // the useless return statement is to avoid warnings from the compiler
        return nullptr;
    }

    if (auto p = static_cast<T *>(__vlx_malloc(count * sizeof(T), alignment)))
    {
        return p;
    }
    else
    {
        // equivalent of: throw std::bad_alloc();
        errors::assertMsgCritical(false, std::string(__func__) + ": aligned allocation failed");

        // the useless return statement is to avoid warnings from the compiler
        return nullptr;
    }
}

/** Deallocate chunk of memory of given type on host.
 *
 * @tparam T type of chunk.
 * @param[in] p the pointer to the memory chunk.
 */
template <typename T>
auto
deallocate(T *p) noexcept -> void
{
    if (p)
    {
        __vlx_free(p);
        p = nullptr;
    }
}

}  // namespace detail

template <typename T>
auto
malloc(size_t count) -> T *
{
    return detail::allocate<T>(VLX_ALIGN, static_cast<size_t>(count));
}

template <typename T>
auto
free(T *pointer) -> void
{
    detail::deallocate(pointer);
}

}  // namespace mem

#endif /* MemAlloc_hpp */
