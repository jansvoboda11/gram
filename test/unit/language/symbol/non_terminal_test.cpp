#include <gtest/gtest.h>

#include <gram/language/symbol/NonTerminal.h>

using namespace gram;
using namespace std;

TEST(non_terminal_test, test_it_accepts_option) {
  Terminal terminal("test");

  auto option = make_shared<Option>();
  option->addTerminal(terminal);

  NonTerminal nonTerminal;

  nonTerminal.addOption(option);

  ASSERT_EQ(*option, nonTerminal.optionAt(0));
}

TEST(non_terminal_test, test_it_handles_recursive_option) {
  Terminal terminal("test");

  auto option = make_shared<Option>();
  option->addTerminal(terminal);

  auto nonTerminal = make_shared<NonTerminal>();

  nonTerminal->addOption(option);
  option->addNonTerminal(nonTerminal);

  ASSERT_TRUE(nonTerminal->optionAt(0).hasNonTerminalAt(1));
  ASSERT_EQ(nonTerminal, nonTerminal->optionAt(0).nonTerminalAt(1).lock());
}

TEST(non_terminal_test, test_it_returns_option_count) {
  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  NonTerminal nonTerminal;

  nonTerminal.addOption(option1);
  nonTerminal.addOption(option2);

  ASSERT_EQ(2, nonTerminal.size());
}

TEST(non_terminal_test, test_it_recognizes_two_equal_objects) {
  Terminal terminal1("test");
  Terminal terminal2("test");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  NonTerminal nonTerminal1;
  NonTerminal nonTerminal2;

  nonTerminal1.addOption(option1);
  nonTerminal2.addOption(option2);

  ASSERT_TRUE(nonTerminal1 == nonTerminal2);
}

TEST(non_terminal_test, test_it_recognizes_two_different_objects) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  NonTerminal nonTerminal1;
  NonTerminal nonTerminal2;

  nonTerminal1.addOption(option1);
  nonTerminal2.addOption(option2);

  ASSERT_TRUE(nonTerminal1 != nonTerminal2);
}
