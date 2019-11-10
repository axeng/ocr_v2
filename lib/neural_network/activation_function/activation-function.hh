#pragma once

namespace neural_network::activation_function
{
    class ActivationFunction
    {
    public:
        virtual float activate(float x) const = 0;
        virtual float activate_prime(float x) const = 0;
    };
} // namespace neural_network::activation_function