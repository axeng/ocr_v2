/**
 ** @file misc/random/uniform-random.hh
 ** @brief Declaration of misc::random::UniformRandom
 */

#pragma once

#include <random>

namespace misc::random
{
    /// Uniform Distribution Random real number generator
    template <typename T>
    class UniformRandom
    {
    public:
        /** @name Constructor
         ** \{ */

        /** @brief Instantiate a new random generator
         ** @param height The height of the matrix
         ** @param width The width of the matrix
         */
        UniformRandom(T minimum, T maximum);

        /** \} */

        /** @name Operator
         ** \{ */

        /** @brief Generate a new random number
         ** @return The random number
         */
        T operator()();

        /** \} */

    private:
        /// The random engine
        std::mt19937 random_engine_;
        /// The distribution
        std::uniform_real_distribution<T> distribution_;
    };
} // namespace misc::random

#include "misc/random/uniform-random.hxx"