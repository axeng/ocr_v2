#pragma once

#include <ostream>
#include <vector>

namespace misc::matrix
{
    class Matrix
    {
    public:
        using data_t = float;

        Matrix(size_t height, size_t width);
        Matrix(size_t height, size_t width, data_t value);

        data_t& at(size_t height_index, size_t width_index);
        data_t at(size_t height_index, size_t width_index) const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    private:
        const size_t height_;
        const size_t width_;

        std::vector<data_t> data_;
    };
} // namespace misc::matrix