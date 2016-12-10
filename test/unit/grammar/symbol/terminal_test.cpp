#include <gtest/gtest.h>

#include <gram/grammar/symbol/Terminal.h>

using namespace gram::grammar;

TEST(terminal_test, test_it_recognizes_two_equal_objects) {
  Terminal terminal1("test");
  Terminal terminal2("test");

  ASSERT_TRUE(terminal1 == terminal2);
}

TEST(terminal_test, test_it_recognizes_two_different_objects) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  ASSERT_TRUE(terminal1 != terminal2);
}
