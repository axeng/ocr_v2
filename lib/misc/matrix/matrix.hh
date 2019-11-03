/**
 ** @file misc/matrix/matrix.hh
 ** @brief Declaration of misc::matrix::Matrix
 ** @author Axen Georget
 */

#pragma once

#include <functional>
#include <ostream>
#include <vector>

#include "misc/random/uniform-random.hh"

namespace misc::matrix
{
    /// Matrix data structure
    class Matrix
    {
    public:
        /// Type of the data stored in the matrix
        using data_t = float;
        /// Type of the uniform distribution random number generator
        using uniform_random_t = misc::random::UniformRandom<data_t>;

        /** @name Constructors
         ** \{ */

        /** @brief Instantiate a new matrix full of zeros
         ** @param height The height of the matrix
         ** @param width The width of the matrix
         */
        Matrix(size_t height, size_t width);

        /** @brief Instantiate a new matrix
         ** @param height The height of the matrix
         ** @param width The width of the matrix
         ** @param value The default value to fill the matrix with
         */
        Matrix(size_t height, size_t width, data_t value);

        /** @brief Instantiate a new matrix with random values
         ** @param height The height of the matrix
         ** @param width The width of the matrix
         ** @param min_value The minimum value to fill the matrix with
         ** @param max_value The maximum value to fill the matrix with
         */
        Matrix(size_t height, size_t width, data_t min_value, data_t max_value);

        /** \} */

        /** @name Matrix Operations
         ** \{ */

        /** @brief Return a transpose of the matrix
         ** @return The new transposed matrix
         */
        Matrix transpose() const;

        /** @brief Compute the hadamard product on the matrix in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference for the current matrix
         */
        Matrix& hadamard_product(const Matrix& rhs);

        /** @brief Apply a function to every element in the matrix in place
         ** @param function The function to apply
         ** @return The reference for the current matrix
         */
        Matrix& apply(std::function<data_t(data_t)> function);

        /** @brief Compute a classic addition in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference for the current matrix
         */
        Matrix& operator+=(const Matrix& rhs);

        /** @brief Compute a classic addition of two matrix
         ** @param lhs The matrix at the left of the operator
         ** @param rhs The matrix at the right of the operator
         ** @return The new matrix containing the result of the operation
         */
        friend Matrix operator+(Matrix lhs, const Matrix& rhs);

        /** @brief Compute a classic subtraction in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference for the current matrix
         */
        Matrix& operator-=(const Matrix& rhs);

        /** @brief Compute a classic subtraction of two matrix
         ** @param lhs The matrix at the left of the operator
         ** @param rhs The matrix at the right of the operator
         ** @return The new matrix containing the result of the operation
         */
        friend Matrix operator-(Matrix lhs, const Matrix& rhs);

        /** @brief Multiplication of each element of the matrix with a scalar in
         ** place
         ** @param scalar The scalar
         ** @return The reference for the current matrix
         */
        Matrix& operator*=(const data_t& scalar);

        /** @brief Multiplication of each element of the matrix with a scalar
         ** @param matrix The matrix
         ** @param scalar The scalar
         ** @return The new matrix containing the result of the operation
         */
        friend Matrix operator*(Matrix matrix, const data_t& scalar);

        /** @brief Division of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference for the current matrix
         */
        Matrix& operator/=(const data_t& scalar);

        /** @brief Division of each element of the matrix with a scalar
         ** @param matrix The matrix
         ** @param scalar The scalar
         ** @return The new matrix containing the result of the operation
         */
        friend Matrix operator/(Matrix matrix, const data_t& scalar);

        /** @brief Compute a classic multiplication of two matrix
         ** @param lhs The matrix at the left of the operator
         ** @param rhs The matrix at the right of the operator
         ** @return The new matrix containing the result of the operation
         */
        friend Matrix operator*(Matrix lhs, const Matrix& rhs);

        /** @brief Print a matrix
         ** @param os The stream to print on
         ** @param matrix The matrix to print
         ** @return The reference to the stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

        /** \} */

        /** @name Accessors
         ** \{ */

        /** @brief Return the height of the matrix
         ** @return The matrix height
         */
        size_t get_height() const;

        /** @brief Return the width of the matrix
         ** @return The matrix width
         */
        size_t get_width() const;

        /** @brief Access an element of the matrix
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The reference to the element
         */
        data_t& at(size_t height_index, size_t width_index);

        /** @brief Return an element of the matrix
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The element
         */
        data_t at(size_t height_index, size_t width_index) const;

        /** \} */

    private:
        /// The matrix height
        const size_t height_;
        /// The matrix width
        const size_t width_;

        /// The matrix data
        std::vector<data_t> data_;
    };
} // namespace misc::matrix