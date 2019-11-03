/**
 ** @file misc/matrix/lib-matrix.hh
 ** @brief Declaration of functions related with misc::matrix::Matrix class
 ** @author Axen Georget
 */

#include "matrix.hh"

namespace misc::matrix
{
    /** @brief Compute the hadamard product on the matrix
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    Matrix hadamard_product(Matrix lhs, const Matrix& rhs);

    /** @brief Compute the kronecker product on the matrix
     ** @param lhs The row vector at the left of the operator
     ** @param rhs The column vector at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    Matrix kronecker_product(const Matrix& lhs, const Matrix& rhs);

    /** @brief Concatenate two matrix horizontally
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    Matrix horizontal_concatenate(const Matrix& lhs, const Matrix& rhs);
} // namespace misc::matrix