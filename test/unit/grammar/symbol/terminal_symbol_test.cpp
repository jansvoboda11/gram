#include <gtest/gtest.h>

#include <gram/grammar/symbol/Terminal.h>

using namespace gram::grammar;

TEST(terminal_symbol_test, test_it_creates_object_with_string) {
  std::string value("value");

  Terminal terminal(value);

  ASSERT_EQ(value, terminal.getValue());
}

TEST(terminal_symbol_test, test_it_recognizes_two_equal_objects) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  ASSERT_TRUE(firstTerminal == secondTerminal);
}

TEST(terminal_symbol_test, test_it_recognizes_two_different_objects) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  ASSERT_TRUE(firstTerminal != secondTerminal);
}
