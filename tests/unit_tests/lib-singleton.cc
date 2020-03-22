#include "gtest/gtest.h"
#include "misc/singleton/singleton.hh"

namespace tests::unit_tests
{
    TEST(LibSingleton, basic_singleton)
    {
        auto& vector = misc::singleton::Singleton<std::vector<int>>::instance();
        vector.push_back(1);
        vector.push_back(2);

        const auto& vector_size = misc::singleton::Singleton<std::vector<int>>::instance().size();
        ASSERT_EQ(2, vector_size);
    }
} // namespace tests::unit_tests