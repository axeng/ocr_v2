/**
 ** @file misc/singleton/singleton.hxx
 ** @brief Inline methods of misc::singleton::Singleton
 */

#pragma once

#include "misc/singleton/singleton.hh"

namespace misc::singleton
{
    template <typename T>
    T& Singleton<T>::instance()
    {
        static T instance;
        return instance;
    }
}