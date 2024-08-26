#include "MatrixFunc.hpp"

#include <algorithm>

#include "CustomViews.hpp"
#include "TensorComponents.hpp"

namespace matfunc {  // matfunc namespace

auto
make_matrix(const CMolecularBasis& basis, const mat_t mtype) -> CMatrix
{
    if ((mtype == mat_t::symmetric) || (mtype == mat_t::antisymmetric))
    {
        auto matrix = CMatrix();

        matrix.set_type(mtype);

        std::ranges::for_each(views::triangular(basis.max_angular_momentum() + 1), [&](const auto& index) {
            const auto [i, j]       = index;
            const size_t bra_off    = basis.dimensions_of_basis(i);
            const size_t bra_ncgtos = basis.number_of_basis_functions(i) * tensor::number_of_spherical_components(std::array<int, 1>{i});
            const size_t ket_off    = basis.dimensions_of_basis(j);
            const size_t ket_ncgtos = basis.number_of_basis_functions(j) * tensor::number_of_spherical_components(std::array<int, 1>{j});
            matrix.add({bra_off, ket_off, bra_ncgtos, ket_ncgtos}, {i, j});
        });

        return matrix;
    }
    else
    {
        return matfunc::make_matrix(basis, basis);
    }
}

auto
make_matrix(const CMolecularBasis& bra_basis, const CMolecularBasis& ket_basis) -> CMatrix
{
    auto matrix = CMatrix();

    matrix.set_type(mat_t::general);

    std::ranges::for_each(views::rectangular(bra_basis.max_angular_momentum() + 1, ket_basis.max_angular_momentum() + 1), [&](const auto& index) {
        const auto [i, j]       = index;
        const size_t bra_off    = bra_basis.dimensions_of_basis(i);
        const size_t bra_ncgtos = bra_basis.number_of_basis_functions(i) * tensor::number_of_spherical_components(std::array<int, 1>{i});
        const size_t ket_off    = ket_basis.dimensions_of_basis(j);
        const size_t ket_ncgtos = ket_basis.number_of_basis_functions(j) * tensor::number_of_spherical_components(std::array<int, 1>{j});
        matrix.add({bra_off, ket_off, bra_ncgtos, ket_ncgtos}, {i, j});
    });

    return matrix;
}

}  // namespace matfunc
