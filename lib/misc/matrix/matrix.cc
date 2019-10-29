#include "matrix.hh"

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

    Matrix Matrix::transpose() const
    {
        Matrix newMatrix(this->width_, this->height_);

        for (size_t height_index = 0; height_index < this->height_;
             height_index++)
        {
            for (size_t width_index = 0; width_index < this->width_;
                 width_index++)
            {
                newMatrix.at(width_index, height_index) =
                    this->at(height_index, width_index);
            }
        }

        return newMatrix;
    }

    Matrix& Matrix::operator+=(const Matrix& rhs)
    {
#ifndef RELEASE
        if (this->height_ != rhs.height_ || this->width_ != rhs.width_)
            throw std::invalid_argument("the matrix must be of the same size");
#endif

        for (size_t index = 0; index < this->height_ * this->width_; index++)
            this->data_[index] += rhs.data_[index];

        return *this;
    }

    Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    Matrix& Matrix::operator*=(const Matrix::data_t& scalar)
    {
        for (size_t index = 0; index < this->height_ * this->width_; index++)
            this->data_[index] *= scalar;

        return *this;
    }

    Matrix operator*(Matrix matrix, const Matrix::data_t& scalar)
    {
        matrix *= scalar;
        return matrix;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (size_t height_index = 0; height_index < matrix.height_;
             height_index++)
        {
            os << "| ";

            for (size_t width_index = 0; width_index < matrix.width_;
                 width_index++)
            {
                os << matrix.at(height_index, width_index) << " ";
            }

            os << "|" << std::endl;
        }

        return os;
    }
} // namespace misc::matrix