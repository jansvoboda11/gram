#include <gtest/gtest.h>

#include <evolution/operator/Mutation.h>
#include <util/FakeNumberGenerator.h>

using namespace gram::evolution;
using namespace gram::population::individual;
using namespace gram::fake::util;

TEST(number_generator_test, test_it_returns_given_numbers) {
  std::vector<int> numbers{0, 1, 2};

  FakeNumberGenerator generator(numbers);

  ASSERT_EQ(0, generator.generate());
  ASSERT_EQ(1, generator.generate());
  ASSERT_EQ(2, generator.generate());
}

TEST(number_generator_test, test_it_wraps_given_numbers) {
  std::vector<int> numbers{0, 1, 2};

  FakeNumberGenerator generator(numbers);

  ASSERT_EQ(0, generator.generate());
  ASSERT_EQ(1, generator.generate());
  ASSERT_EQ(2, generator.generate());
  ASSERT_EQ(0, generator.generate());
  ASSERT_EQ(1, generator.generate());
  ASSERT_EQ(2, generator.generate());
}
