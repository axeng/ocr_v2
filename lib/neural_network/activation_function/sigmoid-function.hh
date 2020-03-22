#pragma once

#include "neural_network/activation_function/simple-activation-function.hh"

namespace neural_network::activation_function
{
    class SigmoidFunction
        : public SimpleActivationFunction
        , public misc::singleton::Singleton<SigmoidFunction>
    {
        friend class misc::singleton::Singleton<SigmoidFunction>;

    public:
        float activate(float value) const override;
        float activate_prime(float values) const override;

    private:
        SigmoidFunction() = default;
    };
} // namespace neural_network::activation_function

#include "neural_network/activation_function/sigmoid-function.hxx"