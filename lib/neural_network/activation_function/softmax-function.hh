#pragma once

#include "neural_network/activation_function/activation-function.hh"

namespace neural_network::activation_function
{
    class SoftmaxFunction
        : public ActivationFunction
        , public misc::singleton::Singleton<SoftmaxFunction>
    {
        friend class misc::singleton::Singleton<SoftmaxFunction>;

    public:
        void apply_function_in_place(matrix_t& values) const override;
        void apply_function_prime_in_place(matrix_t& values) const override;

    private:
        SoftmaxFunction() = default;
    };
} // namespace neural_network::activation_function

#include "neural_network/activation_function/softmax-function.hxx"