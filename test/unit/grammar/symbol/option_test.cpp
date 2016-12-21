#include <gtest/gtest.h>

#include <gram/language/symbol/Option.h>

using namespace gram::grammar;

TEST(option_test, test_it_accepts_terminals) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Option option;
  option.addTerminal(terminal1);
  option.addTerminal(terminal2);

  ASSERT_TRUE(option.hasTerminalAt(0));
  ASSERT_TRUE(option.hasTerminalAt(1));
  ASSERT_EQ(terminal1, option.terminalAt(0));
  ASSERT_EQ(terminal2, option.terminalAt(1));
}

TEST(option_test, test_it_accepts_nonterminals) {
  Terminal terminal("terminal");

  auto innerOption = std::make_shared<Option>();
  auto nonTerminal = std::make_shared<NonTerminal>();

  innerOption->addTerminal(terminal);
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
  auto nonTerminal = std::make_shared<NonTerminal>();

  innerOption->addTerminal(innerTerminal);
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
  Terminal terminal1("test");
  Terminal terminal2("test");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  ASSERT_TRUE(option1 == option2);
}

TEST(option_test, test_it_recognizes_two_different_options) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  Option option1;
  Option option2;

  option1.addTerminal(terminal1);
  option2.addTerminal(terminal2);

  ASSERT_TRUE(option1 != option2);
}
