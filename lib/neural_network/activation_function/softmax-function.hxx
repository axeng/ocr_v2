#pragma once

#include "misc/matrix/lib-matrix.hh"
#include "neural_network/activation_function/softmax-function.hh"

namespace neural_network::activation_function
{
    inline void SoftmaxFunction::apply_function_in_place(matrix_t& values) const
    {
        const auto& values_exp = misc::matrix::apply(values, [](matrix_t::data_t element) { return exp(element); });
        const auto& exp_rows_sum = values_exp.rows_sum();

        for (size_t i = 0; i < values.get_height(); i++)
        {
            for (size_t j = 0; j < values.get_width(); j++)
            {
                values.at(i, j) = values_exp.at(i, j) / exp_rows_sum.at(i, 0);
            }
        }
    }

    inline void SoftmaxFunction::apply_function_prime_in_place(matrix_t&) const
    {}
}; // namespace neural_network::activation_function