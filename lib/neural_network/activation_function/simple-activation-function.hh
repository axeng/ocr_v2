#pragma once

#include "neural_network/activation_function/activation-function.hh"

namespace neural_network::activation_function
{
    class SimpleActivationFunction : public ActivationFunction
    {
    public:
        virtual float activate(float value) const = 0;
        virtual float activate_prime(float value) const = 0;

        void apply_function_in_place(matrix_t& values) const override;
        void apply_function_prime_in_place(matrix_t& values) const override;
    };
} // namespace neural_network::activation_function

#include "neural_network/activation_function/simple-activation-function.hxx"