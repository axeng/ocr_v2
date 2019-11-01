#include "matrix.hh"
namespace misc::matrix
{
    Matrix hadamard_product(Matrix lhs, const Matrix& rhs);
    // only for between row and column vectors
    Matrix kronecker_product(const Matrix& lhs, const Matrix& rhs);
    Matrix horizontal_concatenate(const Matrix& lhs, const Matrix& rhs);
} // namespace misc::matrix