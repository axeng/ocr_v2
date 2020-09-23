#include "gtest/gtest.h"
#include "misc/random/uniform-random.hh"

namespace tests::unit_tests
{
    misc::random::UniformRandom<float> create_int_uniform_random_generator(float minimum, float maximum)
    {
        return misc::random::UniformRandom<float>(minimum, maximum);
    }

    TEST(LibRandom, uniform_random_range)
    {
        auto generator = create_int_uniform_random_generator(0, 1);

        for (size_t i = 0; i < 1000; i++)
        {
            const auto& random_number = generator();
            ASSERT_TRUE(random_number >= 0 && random_number < 1);
        }
    }
} // namespace tests::unit_tests