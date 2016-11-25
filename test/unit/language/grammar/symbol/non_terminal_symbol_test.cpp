#include <gtest/gtest.h>

#include <language/grammar/symbol/NonTerminal.h>

using namespace gram::language::grammar;

TEST(non_terminal_symbol_test, test_it_accepts_rule) {
  Terminal terminal("test");

  Rule rule;
  rule.addTerminal(terminal);

  NonTerminal nonTerminal;
  nonTerminal.addRule(rule);

  ASSERT_EQ(rule, nonTerminal.ruleAt(0));
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_equal_objects) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  Rule firstRule;
  firstRule.addTerminal(firstTerminal);
  Rule secondRule;
  secondRule.addTerminal(secondTerminal);

  NonTerminal firstNonTerminal;
  firstNonTerminal.addRule(firstRule);
  NonTerminal secondNonTerminal;
  secondNonTerminal.addRule(secondRule);

  ASSERT_TRUE(firstNonTerminal == secondNonTerminal);
}

TEST(non_terminal_symbol_test, test_it_recognizes_two_different_objects) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Rule firstRule;
  firstRule.addTerminal(firstTerminal);
  Rule secondRule;
  secondRule.addTerminal(secondTerminal);

  NonTerminal firstNonTerminal;
  firstNonTerminal.addRule(firstRule);
  NonTerminal secondNonTerminal;
  secondNonTerminal.addRule(secondRule);

  ASSERT_TRUE(firstNonTerminal != secondNonTerminal);
}
