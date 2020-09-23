/**
 ** @file neural-network/neural-network.cc
 ** @brief Implementation of neural_network::NeuralNetwork
 */

#include "neural_network/neural-network.hh"

namespace neural_network
{
    void NeuralNetwork::forward_propagation(const NeuralNetwork::matrix_t& inputs)
    {
        this->layers_[0].set_values(inputs);

        for (size_t i = 1; i < this->layers_.size(); i++)
        {
            auto& previous_layer = this->layers_[i - 1];
            auto& current_layer = this->layers_[i];

            current_layer.forward_propagation(previous_layer);
        }
    }
} // namespace neural_network