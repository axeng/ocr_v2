#include <iostream>
#include <misc/matrix/lib-matrix.hh>
#include <misc/matrix/matrix.hh>

float hyperbolic_tangent(float x)
{
    return (tanh(x) + 1) / 2;
}

float hyperbolic_tangent_derivate(float x)
{
    return (1 - pow(tan(x), 2)) / 2;
}

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float sigmoid_prime(float x)
{
    return x * (1 - x);
}

float sigmoid_prime_if_not_sigmoid_results(float x)
{
    return sigmoid(x) * (1 - sigmoid(x));
}

int main()
{
    using matrix_t = misc::matrix::Matrix;

    float learning_rate = 0.8;
    int inputs_count = 2;
    int hidden_layer_neurons_count = 3;
    int outputs_neurons_count = 2;
    int training_data_count = 4;

    // INITIALISATION
    matrix_t weight_layer_1_2(inputs_count, hidden_layer_neurons_count, -1, 1);
    matrix_t weight_layer_2_3(hidden_layer_neurons_count, outputs_neurons_count, -1, 1);

    matrix_t bias_layer_2(1, hidden_layer_neurons_count, 0);
    matrix_t bias_layer_3(1, outputs_neurons_count, 0);

    matrix_t inputs(training_data_count, inputs_count);
    inputs.at(0, 0) = 0;
    inputs.at(0, 1) = 0;
    inputs.at(1, 0) = 0;
    inputs.at(1, 1) = 1;
    inputs.at(2, 0) = 1;
    inputs.at(2, 1) = 0;
    inputs.at(3, 0) = 1;
    inputs.at(3, 1) = 1;

    matrix_t outputs(training_data_count, outputs_neurons_count);
    outputs.at(0, 0) = 1;
    outputs.at(0, 1) = 0;
    outputs.at(1, 0) = 0;
    outputs.at(1, 1) = 1;
    outputs.at(2, 0) = 0;
    outputs.at(2, 1) = 1;
    outputs.at(3, 0) = 1;
    outputs.at(3, 1) = 0;

    int nb_epoch = 1000;
    for (int epoch = 0; epoch < nb_epoch; epoch++)
    {
        // FEED-FORWARD
        auto layer_2 = inputs * weight_layer_1_2;
        layer_2 += bias_layer_2;
        layer_2.apply(sigmoid);

        auto layer_3 = layer_2 * weight_layer_2_3;
        layer_3 += bias_layer_3;

        // SOFTMAX CALCULATIONS
        auto layer_3_exps =
            misc::matrix::apply(layer_3, [](misc::matrix::Matrix::data_t element) { return exp(element); });

        auto sum_layer_3_exps = layer_3_exps.rows_sum();

        for (size_t i = 0; i < layer_3_exps.get_height(); i++)
        {
            for (size_t j = 0; j < layer_3_exps.get_width(); j++)
            {
                layer_3.at(i, j) = layer_3_exps.at(i, j) / sum_layer_3_exps.at(i, 0);
            }
        }

        // ERROR (LOSS) CALCULATION
        // categorical cross-entropy formula:
        // -sum(for each output node i)(y(i) * log(yHat(i)))
        // calculate the error over all the training data: do the mean of the
        // cross- entropy

        // first remove the element where y(i) = 0
        auto interesting_softmax = misc::matrix::hadamard_product(layer_3, outputs).rows_sum();

        // apply the log
        interesting_softmax.apply([](matrix_t::data_t element) { return -log(element); });

        // do the mean for all the training inputs
        auto error = interesting_softmax.sum() / training_data_count;

        if (epoch == nb_epoch - 1)
        {
            std::cout << layer_3 << std::endl;
            std::cout << outputs << std::endl;
            std::cout << "error: " << error << std::endl;
        }

        // BACK PROPAGATION
        // Cross Entropy
        auto layer_3_delta = layer_3 - outputs;
        layer_3_delta /= training_data_count;

        auto layer_2_delta = layer_3_delta * weight_layer_2_3.transpose();
        layer_2_delta.hadamard_product(misc::matrix::apply(layer_2, sigmoid_prime));

        weight_layer_2_3 -= (layer_2.transpose() * layer_3_delta) * learning_rate;
        bias_layer_3 -= layer_3_delta.columns_sum() * learning_rate;
        weight_layer_1_2 -= (inputs.transpose() * layer_2_delta) * learning_rate;
        bias_layer_2 -= layer_2_delta.columns_sum() * learning_rate;
    }
}