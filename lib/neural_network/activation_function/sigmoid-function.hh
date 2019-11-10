#pragma once

#include "neural_network/activation_function/activation-function.hh"

namespace neural_network::activation_function
{
    class SigmoidFunction : public ActivationFunction
    {
    public:
        float activate(float x) const override;
        float activate_prime(float x) const override;
    };
} // namespace neural_network::activation_function

#include "neural_network/activation_function/sigmoid-function.hxx"