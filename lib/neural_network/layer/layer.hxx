#pragma once

#include "neural_network/layer/layer.hh"

namespace neural_network::layer
{
    inline const Layer::matrix_t& Layer::get_values() const
    {
#ifndef RELEASE
        if (!this->values_.has_value())
            throw std::bad_optional_access();
#endif

        return *this->values_;
    }

    inline void Layer::set_values(const matrix_t& values)
    {
        this->values_.emplace(values);
    }
} // namespace neural_network::layer