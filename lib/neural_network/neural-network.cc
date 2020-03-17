/**
 ** @file neural-network/neural-network.cc
 ** @brief Implementation of neural_network::NeuralNetwork
 */

#include "neural_network/neural-network.hh"

namespace neural_network
{
    NeuralNetwork::NeuralNetwork(size_t input_size)
        : input_size_(input_size)
    {}

    void NeuralNetwork::add_layer(const NeuralNetwork::layer_t& layer)
    {
        this->layers_.emplace_back(layer);
    }

    void NeuralNetwork::add_fully_connected_layer(const NeuralNetwork::activation_function_t& activation_function,
                                                  size_t neuron_count)
    {
        if (this->layers_.empty())
        {
            auto layer = fully_connected_layer_t(activation_function, this->input_size_, neuron_count);
            this->add_layer(layer);
        }
    }

    /*NeuralNetwork::matrix_t NeuralNetwork::forward_propagation(const matrix_t& inputs)
    {}*/
} // namespace neural_network