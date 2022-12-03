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

#ifndef XCNewFunctional_hpp
#define XCNewFunctional_hpp

#include <xc.h>

#include <cstdint>
#include <functional>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

#include "Buffer.hpp"
#include "DensityGrid.hpp"
#include "XCCubicHessianGrid.hpp"
#include "XCFuncType.hpp"
#include "XCGradientGrid.hpp"
#include "XCHessianGrid.hpp"

using Component = std::tuple<double, xc_func_type>;

/**
 * Class CXCNewFunctional is a wrapper to the C functions and structs provided by LibXC.
 *
 * - The primitive functionals offered by LibXC are **always** initialized as
 *   spin-polarized.
 * - The functionals in the mix must be **all** of the same family.
 *
 * @author R. Di Remigio Eikås, Z. Rinkevicius
 */
class CXCNewFunctional
{
   private:
    /** @{ Exchange-correlation family. */
    /** Whether the functional is of local-density approximation type. */
    bool _isLDA{false};

    /** Whether the functional is of generalized-gradient approximation type. */
    bool _isGGA{false};

    /** Whether the functional is of meta-generalized-gradient approximation type. */
    bool _isMetaGGA{false};

    /** Whether the functional is of global hybrid type. */
    bool _isGlobalHybrid{false};

    /** Whether the functional is of range-separated hybrid type. */
    bool _isRangeSeparatedHybrid{false};
    /** }@ */

    /** @{ Available derivative orders. */
    /** Whether has zeroth-order derivatives available. */
    bool _hasExc{true};

    /** Whether has first-order derivatives available. */
    bool _hasVxc{true};

    /** Whether has second-order derivatives available. */
    bool _hasFxc{true};

    /** Whether has third-order derivatives available. */
    bool _hasKxc{true};

    /** Whether has fourth-order derivatives available. */
    bool _hasLxc{true};
    /** }@ */

    /** Leading dimension for initial allocation of staging buffer. */
    int32_t _ldStaging{(1 << 10)};

    /** Buffer to stage output results from LibXC invocations. */
    double* _stagingBuffer{nullptr};

    /** The functional components and their coefficients. */
    std::vector<Component> _components;

    /** The fraction of exact Hatree-Fock exchange in functional. */
    double _fractionOfExactExchange{0.0};

   public:
    /** Creates an exchange-correlation functional object.
     *
     * @param[in] labels list of labels of component exchange and correlation functionals.
     * @param[in] coeffs list of coefficients for the components of the functional.
     */
    CXCNewFunctional(const std::vector<std::string>& labels, const std::vector<double>& coeffs, const double fractionOfExactExchange);

    /** Copy-constructor.
     *
     * @param[in] src the exchange-correlation functional.
     */
    CXCNewFunctional(const CXCNewFunctional& src);

    /** Move-constructor.
     *
     * @param[in] src the exchange-correlation functional object.
     */
    CXCNewFunctional(CXCNewFunctional&& src) noexcept;

    /** Destroys an exchange-correlation functional object. */
    ~CXCNewFunctional();

    /** Copy-assignment operator.
     *
     * @param[in] src the exchange-correlation functional object.
     */
    auto operator=(const CXCNewFunctional& src) -> CXCNewFunctional&;

    /** Move-assignment operator.
     *
     * @param[in] src the exchange-correlation functional object.
     */
    auto operator=(CXCNewFunctional&& src) noexcept -> CXCNewFunctional&;

    /** Equality operator.
     *
     * @param[in] other the exchange-correlation functional object.
     * @return true if exchange-correlation functional objects are equal, false otherwise.
     */
    auto operator==(const CXCNewFunctional& other) const -> bool;

    /** Inequality operator.
     *
     * @param[in] other the exchange-correlation functional object.
     * @return true if exchange-correlation functional objects are different, false otherwise.
     */
    auto operator!=(const CXCNewFunctional& other) const -> bool;

    /** String representation of primitive functional. */
    auto repr() const -> std::string;

    /**@{ LDA computational functions. These are wrappers around `xc_lda_*` functions in LibXC. */
    /** Computes values and first derivative of LDA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in,out] exc values of the exchange-correlation kernel. Size: np.
     * @param[in,out] vrho values of the first derivative of the
     * exchange-correlation kernel wrt density. Size: 2*np, order: [(0), (1)].
     *
     * @note Wrapper to `xc_lda_exc_vxc`
     */
    auto compute_exc_vxc_for_lda(int32_t np, const double* rho, double* exc, double* vrho) const -> void;

    /** Computes second derivative of LDA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in,out] v2rho2 values of the second derivative of the
     * exchange-correlation kernel wrt density. Size: 3*np, order:
     * [(0, 0), (0, 1), (1, 1)].
     *
     * @note Wrapper to `xc_lda_fxc`
     */
    auto compute_fxc_for_lda(int32_t np, const double* rho, double* v2rho2) const -> void;

    /** Computes third derivative of LDA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in,out] v3rho3 values of the third derivative of the
     * exchange-correlation kernel wrt density. Size: 4*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 1, 1), (1, 1, 1)].
     *
     * @note Wrapper to `xc_lda_kxc`
     */
    auto compute_kxc_for_lda(int32_t np, const double* rho, double* v3rho3) const -> void;

    /** Computes fourth derivative of LDA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in,out] v4rho4 values of the fourth derivative of the
     * exchange-correlation kernel wrt density. Size: 5*np, order:
     * [(0, 0, 0, 0), (0, 0, 0, 1), (0 0, 1, 1), (0, 1, 1, 1), (1, 1, 1, 1)].
     *
     * @note Wrapper to `xc_lda_lxc`
     */
    auto compute_lxc_for_lda(int32_t np, const double* rho, double* v4rho4) const -> void;
    /**}@*/

    /**@{ GGA computational functions. These are wrappers around `xc_gga_*` functions in LibXC. */
    /** Computes values and first derivative of GGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] exc values of the exchange-correlation kernel. Size: np.
     * @param[in,out] vrho values of the first derivative of the
     * exchange-correlation kernel wrt density. Size: 2*np, order: [(0), (1)].
     * @param[in,out] vsigma values of the first derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 3*np, order: [(0), (1), (2)].
     *
     * @note Wrapper to `xc_gga_exc_vxc`
     */
    auto compute_exc_vxc_for_gga(int32_t np, const double* rho, const double* sigma, double* exc, double* vrho, double* vsigma) const -> void;

    /** Computes second derivative of GGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v2rho2 values of the second derivative of the
     * exchange-correlation kernel wrt density. Size: 3*np, order:
     * [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v2rhosigma values of the second derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 6*np, order:
     * [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)].
     * @param[in,out] v2sigma2 values of the second derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 6*np, order:
     * [(0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2)].
     *
     * @note Wrapper to `xc_gga_fxc`
     */
    auto compute_fxc_for_gga(int32_t np, const double* rho, const double* sigma, double* v2rho2, double* v2rhosigma, double* v2sigma2) const -> void;

    /** Computes third derivative of GGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v3rho3 values of the third derivative of the
     * exchange-correlation kernel wrt density. Size: 4*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 1, 1), (1, 1, 1)].
     * @param[in,out] v3rho2sigma values of the third derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 9*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2),
     *  (0, 1, 0), (0, 1, 1), (0, 1, 2),
     *  (1, 1, 0), (1, 1, 1), (1, 1, 2)]
     * @param[in,out] v3rhosigma2 values of the third derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 12*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 1, 1), (0, 1, 2), (0, 2, 2),
     *  (1, 0, 0), (1, 0, 1), (1, 0, 2), (1, 1, 1), (1, 1, 2), (1, 2, 2)]
     * @param[in,out] v3sigma3 values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 10*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 1, 1), (0, 1, 2), (0, 2, 2), (1, 1, 1), (1, 1, 2), (1, 2, 2), (2, 2, 2)]
     *
     * @note Wrapper to `xc_gga_kxc`
     */
    auto compute_kxc_for_gga(int32_t       np,
                             const double* rho,
                             const double* sigma,
                             double*       v3rho3,
                             double*       v3rho2sigma,
                             double*       v3rhosigma2,
                             double*       v3sigma3) const -> void;

    /** Computes fourth derivative of GGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v4rho4 values of the fourth derivative of the
     * exchange-correlation kernel wrt density. Size: 5*np, order:
     * [(0,0,0,0), (0,0,0,1), (0,0,1,1), (0,1,1,1), (1,1,1,1)].
     * @param[in,out] v4rho3sigma values of the fourth derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 12*np, order:
     * [(0,0,0,0), (0,0,0,1), (0,0,0,2),
     *  (0,0,1,0), (0,0,1,1), (0,0,1,2),
     *  (0,1,1,0), (0,1,1,1), (0,1,1,2),
     *  (1,1,1,0), (1,1,1,1), (1,1,1,2)]
     * @param[in,out] v4rho2sigma2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 18*np, order:
     * (Note: the ordering in the online docs is wrong!)
     * [(0,0,0,0), (0,0,0,1), (0,0,0,2), (0,0,1,1), (0,0,1,2), (0,0,2,2),
     *  (0,1,0,0), (0,1,0,1), (0,1,0,2), (0,1,1,1), (0,1,1,2), (0,1,2,2),
     *  (1,1,0,0), (1,1,0,1), (1,1,0,2), (1,1,1,1), (1,1,1,2), (1,1,2,2)]
     * @param[in,out] v4rhosigma3 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 20*np, order:
     * [(0,0,0,0),(0,0,0,1),(0,0,0,2),(0,0,1,1),(0,0,1,2),(0,0,2,2),(0,1,1,1),(0,1,1,2),(0,1,2,2),(0,2,2,2),
     *  (1,0,0,0),(1,0,0,1),(1,0,0,2),(1,0,1,1),(1,0,1,2),(1,0,2,2),(1,1,1,1),(1,1,1,2),(1,1,2,2),(1,2,2,2)]
     * @param[in,out] v4sigma4 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 15*np, order:
     * [(0,0,0,0),(0,0,0,1),(0,0,0,2),(0,0,1,1),(0,0,1,2),(0,0,2,2),(0,1,1,1),(0,1,1,2),
     *  (0,1,2,2),(0,2,2,2),(1,1,1,1),(1,1,1,2),(1,1,2,2),(1,2,2,2),(2,2,2,2)]
     *
     * @note Wrapper to `xc_gga_lxc`
     */
    auto compute_lxc_for_gga(int32_t       np,
                             const double* rho,
                             const double* sigma,
                             double*       v4rho4,
                             double*       v4rho3sigma,
                             double*       v4rho2sigma2,
                             double*       v4rhosigma3,
                             double*       v4sigma4) const -> void;
    /**}@*/

    /**@{ metaGGA computational functions. These are wrappers around `xc_mgga_*` functions in LibXC. */
    /** Computes values and first derivative of metaGGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in] lapl values of the density Laplacian at grid points. Order: [(0), (1)].
     * @param[in] tau values of the kinetic energy density at grid points. Order: [(0), (1)].
     * @param[in,out] exc values of the exchange-correlation kernel. Size: np.
     * @param[in,out] vrho values of the first derivative of the
     * exchange-correlation kernel wrt density. Size: 2*np, order: [(0), (1)].
     * @param[in,out] vsigma values of the first derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 3*np, order: [(0), (1), (2)].
     * @param[in,out] vlapl values of the first derivative of the
     * exchange-correlation kernel wrt density Laplacian. Size: 2*np, order: [(0), (1)].
     * @param[in,out] vtau alues of the first derivative of the
     * exchange-correlation kernel wrt kinetic energy density. Size: 2*np, order: [(0), (1)].
     *
     * @note Wrapper to `xc_mgga_exc_vxc`
     */
    auto compute_exc_vxc_for_mgga(int32_t       np,
                                  const double* rho,
                                  const double* sigma,
                                  const double* lapl,
                                  const double* tau,
                                  double*       exc,
                                  double*       vrho,
                                  double*       vsigma,
                                  double*       vlapl,
                                  double*       vtau) const -> void;

    /** Computes second derivative of metaGGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in] lapl values of the density Laplacian at grid points. Order: [(0), (1)].
     * @param[in] tau values of the kinetic energy density at grid points. Order: [(0), (1)].
     * @param[in,out] v2rho2 values of the second derivative of the
     * exchange-correlation kernel wrt density. Size: 3*np, order:
     * [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v2rhosigma values of the second derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 6*np, order:
     * [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)].
     * @param[in,out] v2rholapl values of the second derivative of the
     * exchange-correlation kernel wrt density and density Laplacian. Size: 4*np, order:
     * TODO Figure out ordering!
     * @param[in,out] v2rhotau values of the second derivative of the
     * exchange-correlation kernel wrt density and kinetic energy density. Size: 4*np, order:
     * TODO Figure out ordering!
     * @param[in,out] v2sigma2 values of the second derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 6*np, order:
     * [(0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2)].
     * @param[in,out] v2sigmalapl values of the second derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 6*np, order:
     * TODO Figure out ordering!
     * @param[in,out] v2sigmatau values of the second derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v2lapl2 values of the second derivative of the
     * exchange-correlation kernel wrt density Laplacian. Size: 3*np, order:
     * TODO Figure out ordering
     * @param[in,out] v2lapltau values of the second derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 4*np, order:
     * TODO Figure out ordering
     * @param[in,out] v2tau2 values of the second derivative of the
     * exchange-correlation kernel wrt kinetic energy density. Size: 3*np, order:
     * TODO Figure out ordering
     *
     * @note Wrapper to `xc_mgga_fxc`
     */
    auto compute_fxc_for_mgga(int32_t       np,
                              const double* rho,
                              const double* sigma,
                              const double* lapl,
                              const double* tau,
                              double*       v2rho2,
                              double*       v2rhosigma,
                              double*       v2rholapl,
                              double*       v2rhotau,
                              double*       v2sigma2,
                              double*       v2sigmalapl,
                              double*       v2sigmatau,
                              double*       v2lapl2,
                              double*       v2lapltau,
                              double*       v2tau2) const -> void;

    /** Computes third derivative of metaGGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v3rho3 values of the third derivative of the
     * exchange-correlation kernel wrt density. Size: 4*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 1, 1), (1, 1, 1)].
     * @param[in,out] v3rho2sigma values of the third derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 9*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 1, 0), (0, 1, 1), (0, 1, 2), (1, 1, 0), (1, 1, 1), (1, 1, 2)]
     * @param[in,out] v3rho2lapl values of the third derivative of the
     * exchange-correlation kernel wrt density and density Laplacian. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rho2tau values of the third derivative of the
     * exchange-correlation kernel wrt density and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rhosigma2 values of the third derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 12*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 1, 1), (0, 1, 2), (0, 2, 2), (1, 0, 0), (1, 0, 1), (1, 0, 2), (1, 1, 1), (1, 1, 2), (1, 2, 2)]
     * @param[in,out] v3rhosigmalapl values of the third derivative of the
     * exchange-correlation kernel wrt density, contracted gradients,, and density Laplacian. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rhosigmatau values of the third derivative of the
     * exchange-correlation kernel wrt density, contracted gradients, and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rholapl2 values of the third derivative of the
     * exchange-correlation kernel wrt density and density Laplacian. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rholapltau values of the third derivative of the
     * exchange-correlation kernel wrt density, density Laplacian, and kinetic energy density. Size: 8*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3rhotau2 values of the third derivative of the
     * exchange-correlation kernel wrt density and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v3sigma3 values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 10*np, order:
     * [(0, 0, 0), (0, 0, 1), (0, 0, 2), (0, 1, 1), (0, 1, 2), (0, 2, 2), (1, 1, 1), (1, 1, 2), (1, 2, 2), (2, 2, 2)]
     * @param[in,out] v3sigma2lapl values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 12*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3sigma2tau values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3sigmalapl2 values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 9*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3sigmalapltau values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients, density Laplacian, and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3sigmatau2 values of the third derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 9*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3lapl3 values of the third derivative of the
     * exchange-correlation kernel wrt density Laplacian. Size: 4*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3lapl2tau values of the third derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3lapltau2 values of the third derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering.
     * @param[in,out] v3tau3 values of the third derivative of the
     * exchange-correlation kernel wrt kinetic energy density. Size: 4*np, order:
     * TODO Figure out ordering.
     *
     * @note Wrapper to `xc_mgga_kxc`
     */
    auto compute_kxc_for_mgga(int32_t       np,
                              const double* rho,
                              const double* sigma,
                              const double* lapl,
                              const double* tau,
                              double*       v3rho3,
                              double*       v3rho2sigma,
                              double*       v3rho2lapl,
                              double*       v3rho2tau,
                              double*       v3rhosigma2,
                              double*       v3rhosigmalapl,
                              double*       v3rhosigmatau,
                              double*       v3rholapl2,
                              double*       v3rholapltau,
                              double*       v3rhotau2,
                              double*       v3sigma3,
                              double*       v3sigma2lapl,
                              double*       v3sigma2tau,
                              double*       v3sigmalapl2,
                              double*       v3sigmalapltau,
                              double*       v3sigmatau2,
                              double*       v3lapl3,
                              double*       v3lapl2tau,
                              double*       v3lapltau2,
                              double*       v3tau3) const -> void;

    /** Computes fourth derivative of metaGGA exchange-correlation functional on grid.
     *
     * @param[in] np number of grid points.
     * @param[in] rho values of the density at grid points. Order: [(0), (1)].
     * @param[in] sigma values of the contracted gradient of density at grid points. Order: [(0, 0), (0, 1), (1, 1)].
     * @param[in,out] v4rho4 values of the fourth derivative of the
     * exchange-correlation kernel wrt density. Size: 5*np, order:
     * [(0, 0, 0, 0), (0, 0, 0, 1), (0 0, 1, 1), (0, 1, 1, 1), (1, 1, 1, 1)].
     * @param[in,out] v4rho3sigma values of the fourth derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 12*np, order:
     * [(0, 0, 0, 0), (0, 0, 0, 1), (0, 0, 0, 2), (0, 0, 1, 0), (0, 0, 1, 1), (0, 0, 1, 2), (0, 1, 1, 0), (0, 1, 1, 1), (0, 1, 1, 2), (1, 1, 1, 0),
     * (1, 1, 1, 1), (1, 1, 1, 2)]
     * @param[in,out] v4rho3lapl values of the fourth derivative of the
     * exchange-correlation kernel wrt density and density Laplacian. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rho3tau values of the fourth derivative of the
     * exchange-correlation kernel wrt density and kinetic energy density. Size: 6*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rho2sigma2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density and contracted gradients. Size: 18*np, order:
     * TODO figure out the ordering (the one in the online docs is wrong!)
     * @param[in,out] v4rho2sigmalapl values of the fourth derivative of the
     * exchange-correlation kernel wrt
     * TODO Figure out ordering
     * @param[in,out] v4rho2sigmatau values of the fourth derivative of the
     * exchange-correlation kernel wrt
     * TODO Figure out ordering
     * @param[in,out] v4rho2lapl2 values of the fourth derivative of the
     * exchange-correlation kernel wrt
     * TODO Figure out ordering
     * @param[in,out] v4rho2lapltau values of the fourth derivative of the
     * exchange-correlation kernel wrt
     * TODO Figure out ordering
     * @param[in,out] v4rho2tau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt
     * TODO Figure out ordering
     * @param[in,out] v4rhosigma3 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 20*np, order:
     * [(0, 0, 0, 0), (0, 0, 0, 1), (0, 0, 0, 2), (0, 0, 1, 1), (0, 0, 1, 2), (0, 0, 2, 2), (0, 1, 1, 1), (0, 1, 1, 2), (0, 1, 2, 2), (0, 2, 2, 2),
     * (1, 0, 0, 0), (1, 0, 0, 1), (1, 0, 0, 2), (1, 0, 1, 1), (1, 0, 1, 2), (1, 0, 2, 2), (1, 1, 1, 1), (1, 1, 1, 2), (1, 1, 2, 2), (1, 2, 2, 2)]
     * @param[in,out] v4rhosigma2lapl values of the fourth derivative of the
     * exchange-correlation kernel wrt density, contracted gradients and density Laplacian. Size: 36*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rhosigma2tau values of the fourth derivative of the
     * exchange-correlation kernel wrt density, contracted gradients and kinetic energy density. Size: 36*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rhosigmalapl2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density, contracted gradients and density Laplacian. Size: 18*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rhosigmalapltau values of the fourth derivative of the
     * exchange-correlation kernel wrt density, contracted gradients, density Laplacian, and kinetic energy density. Size: 24*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rhosigmatau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density, contracted gradients, and kinetic energy density. Size: 36*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rholapl3 values of the fourth derivative of the
     * exchange-correlation kernel wrt density and density Laplacian. Size: 8*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rholapl2tau values of the fourth derivative of the
     * exchange-correlation kernel wrt density, density Laplacian, and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rholapltau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density, density Laplacian, and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4rhotau3 values of the fourth derivative of the
     * exchange-correlation kernel wrt density and kinetic energy density. Size: 8*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigma4 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients. Size: 15*np, order:
     * [(0, 0, 0, 0), (0, 0, 0, 1), (0, 0, 0, 2), (0, 0, 1, 1), (0, 0, 1, 2), (0, 0, 2, 2), (0, 1, 1, 1), (0, 1, 1, 2), (0, 1, 2, 2), (0, 2, 2, 2),
     * (1, 1, 1, 1), (1, 1, 1, 2), (1, 1, 2, 2), (1, 2, 2, 2), (2, 2, 2, 2)]
     * @param[in,out] v4sigma3lapl values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 20*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigma3tau values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 30*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigma2lapl2 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 18*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigma2lapltau values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients, density Laplacian, and kinetic energy density. Size: 24*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigma2tau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 18*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigmalapl3 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigmalapl2tau values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients, density Laplacian, and kinetic energy density. Size: 18*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigmalapltau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients, density Laplacian, and kinetic energy density. Size: 18*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4sigmatau3 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and kinetic energy density. Size: 12*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4lapl4 values of the fourth derivative of the
     * exchange-correlation kernel wrt contracted gradients and density Laplacian. Size: 5*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4lapl3tau values of the fourth derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 8*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4lapl2tau2 values of the fourth derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 9*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4lapltau3 values of the fourth derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 8*np, order:
     * TODO Figure out ordering
     * @param[in,out] v4tau4 values of the fourth derivative of the
     * exchange-correlation kernel wrt density Laplacian and kinetic energy density. Size: 5*np, order:
     * TODO Figure out ordering
     *
     * @note Wrapper to `xc_mgga_lxc`
     */
    auto compute_lxc_for_mgga(int32_t       np,
                              const double* rho,
                              const double* sigma,
                              const double* lapl,
                              const double* tau,
                              double*       v4rho4,
                              double*       v4rho3sigma,
                              double*       v4rho3lapl,
                              double*       v4rho3tau,
                              double*       v4rho2sigma2,
                              double*       v4rho2sigmalapl,
                              double*       v4rho2sigmatau,
                              double*       v4rho2lapl2,
                              double*       v4rho2lapltau,
                              double*       v4rho2tau2,
                              double*       v4rhosigma3,
                              double*       v4rhosigma2lapl,
                              double*       v4rhosigma2tau,
                              double*       v4rhosigmalapl2,
                              double*       v4rhosigmalapltau,
                              double*       v4rhosigmatau2,
                              double*       v4rholapl3,
                              double*       v4rholapl2tau,
                              double*       v4rholapltau2,
                              double*       v4rhotau3,
                              double*       v4sigma4,
                              double*       v4sigma3lapl,
                              double*       v4sigma3tau,
                              double*       v4sigma2lapl2,
                              double*       v4sigma2lapltau,
                              double*       v4sigma2tau2,
                              double*       v4sigmalapl3,
                              double*       v4sigmalapl2tau,
                              double*       v4sigmalapltau2,
                              double*       v4sigmatau3,
                              double*       v4lapl4,
                              double*       v4lapl3tau,
                              double*       v4lapl2tau2,
                              double*       v4lapltau3,
                              double*       v4tau4) const -> void;
    /**}@*/
};

#endif /* XCNewFunctional_hpp */
