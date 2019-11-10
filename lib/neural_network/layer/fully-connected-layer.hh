#pragma once

#include "neural_network/activation_function/activation-function.hh"
#include "neural_network/layer/layer.hh"

namespace neural_network::layer
{
    class FullyConnectedLayer : public Layer
    {
    public:
        using activation_function_t =
            neural_network::activation_function::ActivationFunction;

        FullyConnectedLayer(const activation_function_t& activation_function,
                            const Layer& previous_layer,
                            size_t neuron_count);

        matrix_t forward_propagation(const matrix_t& previous_values) override;
        size_t get_size() const override;

    private:
        const activation_function_t& activation_function_;
        matrix_t weights_;
        matrix_t biases_;
    };
} // namespace neural_network::layer