#pragma once

#include "misc/matrix/matrix.hh"

namespace neural_network::activation_function
{
    class ActivationFunction
    {
    public:
        using matrix_t = misc::matrix::Matrix;

        matrix_t apply_function(matrix_t values) const;
        virtual void apply_function_in_place(matrix_t& values) const = 0;

        matrix_t apply_function_prime(matrix_t values) const;
        virtual void apply_function_prime_in_place(matrix_t& values) const = 0;
    };
} // namespace neural_network::activation_function

#include "neural_network/activation_function/activation-function.hxx"