/**
 ** @file neural-network/neural-network.hh
 ** @brief Declaration neural_network::NeuralNetwork
 */

#pragma once

#include <vector>

#include "misc/matrix/matrix.hh"
#include "neural_network/activation_function/activation-function.hh"
#include "neural_network/layer/fully-connected-layer.hh"
#include "neural_network/layer/layer.hh"

namespace neural_network
{
    /// Neural Network data structure
    class NeuralNetwork
    {
    public:
        using layer_t = neural_network::layer::Layer;
        using fully_connected_layer_t = neural_network::layer::FullyConnectedLayer;
        using matrix_t = misc::matrix::Matrix;
        using activation_function_t = neural_network::activation_function::ActivationFunction;

        NeuralNetwork() = default;

    private:
        void forward_propagation(const matrix_t& inputs);

        std::vector<layer_t> layers_;
    };
} // namespace neural_network