#include <gtest/gtest.h>

#include <gram/language/parser/BnfRuleParser.h>

using namespace gram;
using namespace std;

TEST(bnf_rule_parser_test, test_it_parses_rule_with_single_terminal) {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule = grammar.startRule();

  ASSERT_EQ(1, rule->size());
  ASSERT_TRUE(rule->optionAt(0).hasTerminalAt(0));
  ASSERT_EQ("hello", rule->optionAt(0).terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_rule_with_multiple_terminals) {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\"";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule = grammar.startRule();

  ASSERT_EQ(1, rule->size());
  ASSERT_TRUE(rule->optionAt(0).hasTerminalAt(0));
  ASSERT_TRUE(rule->optionAt(0).hasTerminalAt(1));
  ASSERT_EQ("hello", rule->optionAt(0).terminalAt(0).value());
  ASSERT_EQ("world", rule->optionAt(0).terminalAt(1).value());
}

TEST(bnf_rule_parser_test, test_it_parses_rule_with_multiple_terminal_options) {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\" | \"she said\"";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule = grammar.startRule();

  ASSERT_EQ(2, rule->size());
  ASSERT_TRUE(rule->optionAt(0).hasTerminalAt(0));
  ASSERT_TRUE(rule->optionAt(0).hasTerminalAt(1));
  ASSERT_EQ("hello", rule->optionAt(0).terminalAt(0).value());
  ASSERT_EQ("world", rule->optionAt(0).terminalAt(1).value());
  ASSERT_TRUE(rule->optionAt(1).hasTerminalAt(0));
  ASSERT_EQ("she said", rule->optionAt(1).terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_multiple_rules) {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2>\n"
          "<rule2> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule1 = grammar.startRule();
  ASSERT_EQ(1, rule1->size());
  ASSERT_TRUE(rule1->optionAt(0).hasNonTerminalAt(0));

  NonTerminal rule2 = rule1->optionAt(0).nonTerminalAt(0);
  ASSERT_EQ(1, rule2.size());
  ASSERT_TRUE(rule2.optionAt(0).hasTerminalAt(0));
  ASSERT_EQ("hello", rule2.optionAt(0).terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_multiple_rules_with_both_terminals_and_nonterminals) {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2> \"world\" | \"she\" \"said\"\n"
          "<rule2> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule1 = grammar.startRule();
  ASSERT_EQ(2, rule1->size());

  ASSERT_TRUE(rule1->optionAt(0).hasNonTerminalAt(0));
  ASSERT_TRUE(rule1->optionAt(0).hasTerminalAt(1));
  ASSERT_EQ("world", rule1->optionAt(0).terminalAt(1).value());

  ASSERT_TRUE(rule1->optionAt(1).hasTerminalAt(0));
  ASSERT_EQ("she", rule1->optionAt(1).terminalAt(0).value());
  ASSERT_TRUE(rule1->optionAt(1).hasTerminalAt(1));
  ASSERT_EQ("said", rule1->optionAt(1).terminalAt(1).value());

  NonTerminal rule2 = rule1->optionAt(0).nonTerminalAt(0);
  ASSERT_EQ(1, rule2.size());
  ASSERT_TRUE(rule2.optionAt(0).hasTerminalAt(0));
  ASSERT_EQ("hello", rule2.optionAt(0).terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_handles_whitespace_correctly) {
  BnfRuleParser parser;

  string rules =
      "    <start>::= \"world\"  |<next> \n"
          " \n"
          "<next> ::= \"hello\"\n"
          "\n";

  Grammar grammar = parser.parse(rules);

  shared_ptr<NonTerminal> rule1 = grammar.startRule();
  ASSERT_EQ(2, rule1->size());
  ASSERT_TRUE(rule1->optionAt(0).hasTerminalAt(0));
  ASSERT_EQ("world", rule1->optionAt(0).terminalAt(0).value());
  ASSERT_TRUE(rule1->optionAt(1).hasNonTerminalAt(0));

  NonTerminal rule2 = rule1->optionAt(1).nonTerminalAt(0);
  ASSERT_EQ(1, rule2.size());
  ASSERT_TRUE(rule2.optionAt(0).hasTerminalAt(0));
  ASSERT_EQ("hello", rule2.optionAt(0).terminalAt(0).value());
}
