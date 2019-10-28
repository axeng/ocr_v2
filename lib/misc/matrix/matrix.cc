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
#ifdef DEBUG
        if (height_index >= height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * width_ + width_index];
    }

    Matrix::data_t Matrix::at(size_t height_index, size_t width_index) const
    {
#ifdef DEBUG
        if (height_index >= height_)
            throw std::out_of_range("height_index out of range");
        if (width_index >= width_)
            throw std::out_of_range("width_index out of range");
#endif

        return data_[height_index * width_ + width_index];
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