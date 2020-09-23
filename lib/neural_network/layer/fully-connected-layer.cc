#include "neural_network/layer/fully-connected-layer.hh"

namespace neural_network::layer
{
    FullyConnectedLayer::FullyConnectedLayer(const activation_function_t& activation_function,
                                             size_t previous_layer_size,
                                             size_t neuron_count)
        : activation_function_(activation_function)
        , weights_(previous_layer_size, neuron_count, -1, 1)
        , biases_(1, neuron_count, 0)
    {}

    void FullyConnectedLayer::forward_propagation(const Layer& previous_layer)
    {
        this->values_.emplace(previous_layer.get_values() * this->weights_);
        *this->values_ += this->biases_;
        this->activation_function_.apply_function_in_place(*this->values_);
    }
} // namespace neural_network::layer