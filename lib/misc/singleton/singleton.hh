/**
 ** @file misc/singleton/singleton.hh
 ** @brief Declaration of misc::singleton::Singleton
 */

#pragma once

namespace misc::singleton
{
    /// Singleton data structure
    template <typename T>
    class Singleton
    {
    public:
        // Make the Singleton non-copiable
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        /**
         ** @brief Return the instance of the object
         ** @return The instance
         */
        static T& instance();

    protected:
        /// @brief Instantiate a new Singleton
        Singleton() = default;
    };
} // namespace misc::singleton

#include "misc/singleton/singleton.hxx"