#pragma once

#include "misc/matrix/matrix.hh"

namespace neural_network::layer
{
    class Layer
    {
    public:
        using matrix_t = misc::matrix::Matrix;

        virtual matrix_t
        forward_propagation(const matrix_t& previous_values) = 0;

        virtual size_t get_size() const = 0;
    };
} // namespace neural_network::layer