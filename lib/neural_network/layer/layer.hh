#pragma once

#include <optional>

#include "misc/matrix/matrix.hh"

namespace neural_network::layer
{
    class Layer
    {
    public:
        using matrix_t = misc::matrix::Matrix;

        virtual void forward_propagation(const Layer& previous_layer) = 0;

        const matrix_t& get_values() const;
        void set_values(const matrix_t& values);

    protected:
        std::optional<matrix_t> values_;
    };
} // namespace neural_network::layer

#include "neural_network/layer/layer.hxx"