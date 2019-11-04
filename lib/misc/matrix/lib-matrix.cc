/**
 ** @file misc/matrix/lib-matrix.cc
 ** @brief Implementation of functions related with misc::matrix::Matrix class
 ** @author Axen Georget
 */

#include "lib-matrix.hh"

namespace misc::matrix
{
    Matrix hadamard_product(Matrix lhs, const Matrix& rhs)
    {
        lhs.hadamard_product(rhs);
        return lhs;
    }

    Matrix apply(Matrix matrix,
                 const std::function<Matrix::data_t(Matrix::data_t)>& function)
    {
        matrix.apply(function);
        return matrix;
    }

    Matrix kronecker_product(const Matrix& lhs, const Matrix& rhs)
    {
#ifndef RELEASE
        if (lhs.get_height() != 1)
        {
            throw std::invalid_argument(
                "the first matrix must be a row vector");
        }
        if (rhs.get_width() != 1)
        {
            throw std::invalid_argument(
                "the second matrix must be a column vector");
        }
#endif

        Matrix new_matrix(rhs.get_height(), lhs.get_width());

        for (size_t i = 0; i < rhs.get_height(); i++)
        {
            for (size_t j = 0; j < lhs.get_width(); j++)
                new_matrix.at(i, j) = lhs.at(0, j) * rhs.at(i, 0);
        }

        return new_matrix;
    }

    Matrix horizontal_concatenate(const Matrix& lhs, const Matrix& rhs)
    {
#ifndef RELEASE
        if (lhs.get_height() != rhs.get_height())
        {
            throw std::invalid_argument(
                "the two matrix must have the same height");
        }
#endif

        Matrix new_matrix(lhs.get_height(), lhs.get_width() + rhs.get_width());

        for (size_t i = 0; i < lhs.get_height(); i++)
        {
            for (size_t j = 0; j < lhs.get_width(); j++)
                new_matrix.at(i, j) = lhs.at(i, j);
        }

        for (size_t i = 0; i < rhs.get_height(); i++)
        {
            for (size_t j = 0; j < rhs.get_width(); j++)
                new_matrix.at(i, j + lhs.get_width()) = rhs.at(i, j);
        }

        return new_matrix;
    }
} // namespace misc::matrix