#include <gtest/gtest.h>

#include <gram/grammar/Rule.h>

using namespace gram::grammar;

TEST(rule_test, test_it_accepts_terminals) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Rule rule;
  rule.addTerminal(firstTerminal);
  rule.addTerminal(secondTerminal);

  ASSERT_TRUE(rule.hasTerminalAt(0));
  ASSERT_TRUE(rule.hasTerminalAt(1));
  ASSERT_EQ(firstTerminal, rule.terminalAt(0));
  ASSERT_EQ(secondTerminal, rule.terminalAt(1));
}

TEST(rule_test, test_it_accepts_nonterminals) {
  Terminal terminal("terminal");

  Rule innerRule;
  innerRule.addTerminal(terminal);

  NonTerminal nonTerminal;
  nonTerminal.addRule(innerRule);

  Rule rule;
  rule.addNonTerminal(nonTerminal);

  ASSERT_TRUE(rule.hasNonTerminalAt(0));
  ASSERT_EQ(nonTerminal, rule.nonTerminalAt(0));
}

TEST(rule_test, test_it_accepts_both_terminals_and_nonterminals) {
  Terminal terminal("regular");
  Terminal innerTerminal("inner");

  Rule innerRule;
  innerRule.addTerminal(innerTerminal);

  NonTerminal nonTerminal;
  nonTerminal.addRule(innerRule);

  Rule rule;
  rule.addTerminal(terminal);
  rule.addNonTerminal(nonTerminal);

  ASSERT_TRUE(rule.hasTerminalAt(0));
  ASSERT_TRUE(rule.hasNonTerminalAt(1));
  ASSERT_EQ(terminal, rule.terminalAt(0));
  ASSERT_EQ(nonTerminal, rule.nonTerminalAt(1));
}

TEST(rule_test, test_it_recognizes_two_equal_rules) {
  Terminal firstTerminal("test");
  Terminal secondTerminal("test");

  Rule firstRule;
  firstRule.addTerminal(firstTerminal);

  Rule secondRule;
  secondRule.addTerminal(secondTerminal);

  ASSERT_TRUE(firstRule == secondRule);
}

TEST(rule_test, test_it_recognizes_two_different_rules) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  Rule firstRule;
  firstRule.addTerminal(firstTerminal);

  Rule secondRule;
  secondRule.addTerminal(secondTerminal);

  ASSERT_TRUE(firstRule != secondRule);
}
