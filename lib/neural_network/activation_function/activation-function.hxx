#pragma once

#include "neural_network/activation_function/activation-function.hh"

namespace neural_network::activation_function
{
    inline ActivationFunction::matrix_t ActivationFunction::apply_function(matrix_t values) const
    {
        this->apply_function_in_place(values);
        return values;
    }

    inline ActivationFunction::matrix_t ActivationFunction::apply_function_prime(matrix_t values) const
    {
        this->apply_function_prime_in_place(values);
        return values;
    }
} // namespace neural_network::activation_function