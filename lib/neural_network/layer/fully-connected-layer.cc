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

    FullyConnectedLayer::matrix_t FullyConnectedLayer::forward_propagation(const matrix_t& previous_values)
    {
        auto values = previous_values * this->weights_;
        values += this->biases_;
        values.apply([&](const matrix_t::data_t& element) { return this->activation_function_.activate(element); });

        return values;
    }

    size_t FullyConnectedLayer::get_size() const
    {
        return this->weights_.get_width();
    }
} // namespace neural_network::layer