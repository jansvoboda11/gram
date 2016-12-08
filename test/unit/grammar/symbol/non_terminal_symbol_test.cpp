#include <gtest/gtest.h>

#include <gram/grammar/symbol/NonTerminal.h>

using namespace gram::grammar;

TEST(non_terminal_symbol_test, test_it_accepts_option) {
  Terminal terminal("test");

  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);

  NonTerminal nonTerminal;
  nonTerminal.addOption(option);

  ASSERT_EQ(option, nonTerminal.optionAt(0));
}

TEST(non_terminal_symbol_test, test_it_handles_recursive_option) {
  Terminal terminal("test");

  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);

  auto nonTerminal = std::make_shared<NonTerminal>();
  nonTerminal->addOption(option);

  option->addNonTerminal(nonTerminal);

  ASSERT_TRUE(nonTerminal->optionAt(0)->hasNonTerminalAt(1));
  ASSERT_EQ(nonTerminal, nonTerminal->optionAt(0)->nonTerminalAt(1));
}

TEST(non_terminal_symbol_test, test_it_returns_option_count) {
  auto firstOption = std::make_shared<Option>();
  auto secondOption = std::make_shared<Option>();

  NonTerminal nonTerminal;
  nonTerminal.addOption(firstOption);
  nonTerminal.addOption(secondOption);

  ASSERT_EQ(2, nonTerminal.optionCount());
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_equal_objects) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  auto firstOption = std::make_shared<Option>();
  firstOption->addTerminal(firstTerminal);
  auto secondOption = std::make_shared<Option>();
  secondOption->addTerminal(secondTerminal);

  NonTerminal firstNonTerminal;
  firstNonTerminal.addOption(firstOption);
  NonTerminal secondNonTerminal;
  secondNonTerminal.addOption(secondOption);

  ASSERT_TRUE(firstNonTerminal == secondNonTerminal);
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_different_objects) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  auto firstOption = std::make_shared<Option>();
  firstOption->addTerminal(firstTerminal);
  auto secondOption = std::make_shared<Option>();
  secondOption->addTerminal(secondTerminal);

  auto firstNonTerminal = std::make_shared<NonTerminal>();
  firstNonTerminal->addOption(firstOption);
  auto secondNonTerminal = std::make_shared<NonTerminal>();
  secondNonTerminal->addOption(secondOption);

  ASSERT_TRUE(firstNonTerminal != secondNonTerminal);
}
