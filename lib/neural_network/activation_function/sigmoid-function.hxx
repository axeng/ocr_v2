#pragma once

#include <cmath>

#include "neural_network/activation_function/sigmoid-function.hh"

namespace neural_network::activation_function
{
    inline float SigmoidFunction::activate(float value) const
    {
        return 1 / (1 + exp(-value));
    }

    inline float SigmoidFunction::activate_prime(float value) const
    {
        return value * (1 - value);
    }
} // namespace neural_network::activation_function