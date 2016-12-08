#include <gtest/gtest.h>

#include <gram/grammar/symbol/Option.h>

using namespace gram::grammar;

TEST(option_test, test_it_accepts_terminals) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Option option;
  option.addTerminal(firstTerminal);
  option.addTerminal(secondTerminal);

  ASSERT_TRUE(option.hasTerminalAt(0));
  ASSERT_TRUE(option.hasTerminalAt(1));
  ASSERT_EQ(firstTerminal, option.terminalAt(0));
  ASSERT_EQ(secondTerminal, option.terminalAt(1));
}

TEST(option_test, test_it_accepts_nonterminals) {
  Terminal terminal("terminal");

  auto innerOption = std::make_shared<Option>();
  innerOption->addTerminal(terminal);

  auto nonTerminal = std::make_shared<NonTerminal>();
  nonTerminal->addOption(innerOption);

  Option option;
  option.addNonTerminal(nonTerminal);

  ASSERT_TRUE(option.hasNonTerminalAt(0));
  ASSERT_EQ(nonTerminal, option.nonTerminalAt(0));
}

TEST(option_test, test_it_accepts_both_terminals_and_nonterminals) {
  Terminal terminal("regular");
  Terminal innerTerminal("inner");

  auto innerOption = std::make_shared<Option>();
  innerOption->addTerminal(innerTerminal);

  auto nonTerminal = std::make_shared<NonTerminal>();
  nonTerminal->addOption(innerOption);

  Option option;
  option.addTerminal(terminal);
  option.addNonTerminal(nonTerminal);

  ASSERT_TRUE(option.hasTerminalAt(0));
  ASSERT_TRUE(option.hasNonTerminalAt(1));
  ASSERT_EQ(terminal, option.terminalAt(0));
  ASSERT_EQ(nonTerminal, option.nonTerminalAt(1));
}

TEST(option_test, test_it_recognizes_two_equal_options) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  Option firstOption;
  firstOption.addTerminal(firstTerminal);

  Option secondOption;
  secondOption.addTerminal(secondTerminal);

  ASSERT_TRUE(firstOption == secondOption);
}

TEST(option_test, test_it_recognizes_two_different_options) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Option firstOption;
  firstOption.addTerminal(firstTerminal);

  Option secondOption;
  secondOption.addTerminal(secondTerminal);

  ASSERT_TRUE(firstOption != secondOption);
}
