#include <gtest/gtest.h>

#include <gram/fake/util/FakeBoolGenerator.h>

using namespace gram::fake::util;

TEST(bool_generator_test, test_it_returns_given_values) {
  FakeBoolGenerator generator{true, false, true};

  ASSERT_TRUE(generator.generate());
  ASSERT_FALSE(generator.generate());
  ASSERT_TRUE(generator.generate());
}

TEST(bool_generator_test, test_it_wraps_given_values) {
  FakeBoolGenerator generator{true, false, true};

  ASSERT_TRUE(generator.generate());
  ASSERT_FALSE(generator.generate());
  ASSERT_TRUE(generator.generate());
  ASSERT_TRUE(generator.generate());
  ASSERT_FALSE(generator.generate());
  ASSERT_TRUE(generator.generate());
}

TEST(bool_generator_test, test_it_returns_batch_of_values) {
  FakeBoolGenerator generator{true, false, true};

  std::vector<bool> expectedValues{true, false, true, true, false};

  ASSERT_EQ(expectedValues, generator.generate(5));
}
