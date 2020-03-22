#pragma once

#include "neural_network/activation_function/simple-activation-function.hh"

namespace neural_network::activation_function
{
    inline void SimpleActivationFunction::apply_function_in_place(matrix_t& values) const
    {
        values.apply([&](const matrix_t::data_t& element) { return this->activate(element); });
    }

    inline void SimpleActivationFunction::apply_function_prime_in_place(matrix_t& values) const
    {
        values.apply([&](const matrix_t::data_t& element) { return this->activate_prime(element); });
    }
} // namespace neural_network::activation_function