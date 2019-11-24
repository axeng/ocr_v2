/**
 ** @file misc/random/uniform-random.hxx
 ** @brief Inline methods of misc::random::UniformRandom
 */

#pragma once

#include "misc/random/uniform-random.hh"

namespace misc::random
{
    template <typename T>
    UniformRandom<T>::UniformRandom(T minimum, T maximum)
        : random_engine_(std::random_device()())
        , distribution_(minimum, maximum)
    {}

    template <typename T>
    T UniformRandom<T>::operator()()
    {
        return this->distribution_(this->random_engine_);
    }
} // namespace misc::random