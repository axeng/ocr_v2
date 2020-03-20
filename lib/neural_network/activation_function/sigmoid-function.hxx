#pragma once

#include <cmath>

#include "neural_network/activation_function/sigmoid-function.hh"

namespace neural_network::activation_function
{
    inline float SigmoidFunction::activate(float x) const
    {
        return 1 / (1 + exp(-x));
    }

    inline float SigmoidFunction::activate_prime(float x) const
    {
        return x * (1 - x);
    }
} // namespace neural_network::activation_function