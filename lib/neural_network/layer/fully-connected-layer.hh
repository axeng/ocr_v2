#pragma once

#include "neural_network/activation_function/activation-function.hh"
#include "neural_network/layer/layer.hh"

namespace neural_network::layer
{
    class FullyConnectedLayer : public Layer
    {
    public:
        using activation_function_t = neural_network::activation_function::ActivationFunction;

        FullyConnectedLayer(const activation_function_t& activation_function,
                            size_t previous_layer_size,
                            size_t neuron_count);

        void forward_propagation(const Layer& previous_layer) override;

    private:
        const activation_function_t& activation_function_;
        matrix_t weights_;
        matrix_t biases_;
    };
} // namespace neural_network::layer