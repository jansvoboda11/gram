#include <gtest/gtest.h>

#include <gram/grammar/symbol/NonTerminal.h>

using namespace gram::grammar;

TEST(non_terminal_symbol_test, test_it_accepts_rule) {
  Terminal terminal("test");

  auto rule = std::make_shared<Rule>();
  rule->addTerminal(terminal);

  NonTerminal nonTerminal;
  nonTerminal.addRule(rule);

  ASSERT_EQ(rule, nonTerminal.ruleAt(0));
}

TEST(non_terminal_symbol_test, test_it_handles_recursive_rule) {
  Terminal terminal("test");

  auto rule = std::make_shared<Rule>();
  rule->addTerminal(terminal);

  auto nonTerminal = std::make_shared<NonTerminal>();
  nonTerminal->addRule(rule);

  rule->addNonTerminal(nonTerminal);

  ASSERT_TRUE(nonTerminal->ruleAt(0)->hasNonTerminalAt(1));
  ASSERT_EQ(nonTerminal, nonTerminal->ruleAt(0)->nonTerminalAt(1));
}

TEST(non_terminal_symbol_test, test_it_returns_rule_count) {
  auto firstRule = std::make_shared<Rule>();
  auto secondRule = std::make_shared<Rule>();

  NonTerminal nonTerminal;
  nonTerminal.addRule(firstRule);
  nonTerminal.addRule(secondRule);

  ASSERT_EQ(2, nonTerminal.ruleCount());
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_equal_objects) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  auto firstRule = std::make_shared<Rule>();
  firstRule->addTerminal(firstTerminal);
  auto secondRule = std::make_shared<Rule>();
  secondRule->addTerminal(secondTerminal);

  NonTerminal firstNonTerminal;
  firstNonTerminal.addRule(firstRule);
  NonTerminal secondNonTerminal;
  secondNonTerminal.addRule(secondRule);

  ASSERT_TRUE(firstNonTerminal == secondNonTerminal);
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_different_objects) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  auto firstRule = std::make_shared<Rule>();
  firstRule->addTerminal(firstTerminal);
  auto secondRule = std::make_shared<Rule>();
  secondRule->addTerminal(secondTerminal);

  auto firstNonTerminal = std::make_shared<NonTerminal>();
  firstNonTerminal->addRule(firstRule);
  auto secondNonTerminal = std::make_shared<NonTerminal>();
  secondNonTerminal->addRule(secondRule);

  ASSERT_TRUE(firstNonTerminal != secondNonTerminal);
}
