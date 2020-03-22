#pragma once

namespace misc::singleton
{
    // TODO DOCUMENTATION + TEST
    template <typename T>
    class Singleton
    {
    public:
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        static const T& instance();

    protected:
        Singleton() = default;
    };
} // namespace misc::singleton

#include "misc/singleton/singleton.hxx"