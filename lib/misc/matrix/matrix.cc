/**
 ** @file misc/matrix/matrix.cc
 ** @brief Implementation of misc::matrix::Matrix
 ** @author Axen Georget
 */

#include "matrix.hh"

#include <iomanip>

#include "misc/random/uniform-random.hh"

namespace misc::matrix
{
    Matrix::Matrix(size_t height, size_t width)
        : Matrix(height, width, 0)
    {}

    Matrix::Matrix(size_t height, size_t width, data_t value)
        : height_(height)
        , width_(width)
        , data_(width * height, value)
    {}

    Matrix::Matrix(size_t height,
                   size_t width,
                   data_t min_value,
                   data_t max_value)
        : height_(height)
        , width_(width)
        , data_(width * height)
    {
        std::generate_n(this->data_.begin(),
                        width * height,
                        uniform_random_t(min_value, max_value));
    }

    Matrix Matrix::transpose() const
    {
        Matrix new_matrix(this->width_, this->height_);

        for (size_t i = 0; i < this->height_; i++)
        {
            for (size_t j = 0; j < this->width_; j++)
                new_matrix.at(j, i) = this->at(i, j);
        }

        return new_matrix;
    }

    Matrix& Matrix::hadamard_product(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t i = 0; i < this->data_.size(); i++)
            this->data_[i] *= rhs.data_[i];

        return *this;
    }

    Matrix& Matrix::apply(const std::function<data_t(data_t)>& function)
    {
        for (auto& element : this->data_)
            element = function(element);

        return *this;
    }

    Matrix::data_t Matrix::sum() const
    {
        data_t sum = 0;

        for (const auto& element : this->data_)
            sum += element;

        return sum;
    }

    Matrix Matrix::columns_sum() const
    {
        Matrix row_matrix(1, this->width_, 0);

        for (size_t i = 0; i < this->height_; i++)
        {
            for (size_t j = 0; j < this->width_; j++)
                row_matrix.at(0, j) += this->at(i, j);
        }

        return row_matrix;
    }

    Matrix Matrix::rows_sum() const
    {
        Matrix column_matrix(this->height_, 1, 0);

        for (size_t i = 0; i < this->height_; i++)
        {
            for (size_t j = 0; j < this->width_; j++)
                column_matrix.at(i, 0) += this->at(i, j);
        }

        return column_matrix;
    }

    Matrix& Matrix::operator+=(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t i = 0; i < this->data_.size(); i++)
            this->data_[i] += rhs.data_[i];

        return *this;
    }

    Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    Matrix& Matrix::operator-=(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t i = 0; i < this->data_.size(); i++)
            this->data_[i] -= rhs.data_[i];

        return *this;
    }

    Matrix operator-(Matrix lhs, const Matrix& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    Matrix& Matrix::operator*=(const Matrix::data_t& scalar)
    {
        for (auto& element : this->data_)
            element *= scalar;

        return *this;
    }

    Matrix operator*(Matrix matrix, const Matrix::data_t& scalar)
    {
        matrix *= scalar;
        return matrix;
    }

    Matrix& Matrix::operator/=(const Matrix::data_t& scalar)
    {
        for (auto& element : this->data_)
            element /= scalar;

        return *this;
    }

    Matrix operator/(Matrix matrix, const Matrix::data_t& scalar)
    {
        matrix /= scalar;
        return matrix;
    }

    Matrix operator*(Matrix lhs, const Matrix& rhs)
    {
#ifndef RELEASE
        if (lhs.width_ != rhs.height_)
        {
            throw std::invalid_argument("matrix multiplication can not be "
                                        "performed on those two matrix");
        }
#endif

        Matrix new_matrix(lhs.height_, rhs.width_, 0);

        for (size_t i = 0; i < lhs.height_; i++)
        {
            for (size_t j = 0; j < rhs.width_; j++)
            {
                for (size_t k = 0; k < lhs.width_; k++)
                    new_matrix.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
            }
        }

        return new_matrix;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (size_t i = 0; i < matrix.height_; i++)
        {
            os << "| ";

            for (size_t j = 0; j < matrix.width_; j++)
            {
                os << std::fixed << std::setw(7) << std::setprecision(4)
                   << matrix.at(i, j) << " ";
            }

            os << "|" << std::endl;
        }

        return os;
    }

    size_t Matrix::get_height() const
    {
        return this->height_;
    }

    size_t Matrix::get_width() const
    {
        return this->width_;
    }

    Matrix::data_t& Matrix::at(size_t height_index, size_t width_index)
    {
#ifndef RELEASE
        if (height_index >= this->height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= this->width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * this->width_ + width_index];
    }

    Matrix::data_t Matrix::at(size_t height_index, size_t width_index) const
    {
#ifndef RELEASE
        if (height_index >= this->height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= this->width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * this->width_ + width_index];
    }
} // namespace misc::matrix