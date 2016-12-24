#include <gtest/gtest.h>

#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::language;

TEST(bnf_rule_parser_test, test_it_parses_rule_with_single_terminal) {
  BnfRuleParser parser;

  std::string rules = "<rule> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  ASSERT_EQ(1, grammar.startSymbol()->size());
  ASSERT_TRUE(grammar.startSymbol()->optionAt(0)->hasTerminalAt(0));
  ASSERT_EQ("hello", grammar.startSymbol()->optionAt(0)->terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_rule_with_multiple_terminals) {
  BnfRuleParser parser;

  std::string rules = "<rule> ::= \"hello\" \"world\"";

  Grammar grammar = parser.parse(rules);

  ASSERT_EQ(1, grammar.startSymbol()->size());
  ASSERT_TRUE(grammar.startSymbol()->optionAt(0)->hasTerminalAt(0));
  ASSERT_TRUE(grammar.startSymbol()->optionAt(0)->hasTerminalAt(1));
  ASSERT_EQ("hello", grammar.startSymbol()->optionAt(0)->terminalAt(0).value());
  ASSERT_EQ("world", grammar.startSymbol()->optionAt(0)->terminalAt(1).value());
}

TEST(bnf_rule_parser_test, test_it_parses_rule_with_multiple_terminal_options) {
  BnfRuleParser parser;

  std::string rules = "<rule> ::= \"hello\" \"world\" | \"she said\"";

  Grammar grammar = parser.parse(rules);

  ASSERT_EQ(2, grammar.startSymbol()->size());
  ASSERT_TRUE(grammar.startSymbol()->optionAt(0)->hasTerminalAt(0));
  ASSERT_TRUE(grammar.startSymbol()->optionAt(0)->hasTerminalAt(1));
  ASSERT_EQ("hello", grammar.startSymbol()->optionAt(0)->terminalAt(0).value());
  ASSERT_EQ("world", grammar.startSymbol()->optionAt(0)->terminalAt(1).value());
  ASSERT_TRUE(grammar.startSymbol()->optionAt(1)->hasTerminalAt(0));
  ASSERT_EQ("she said", grammar.startSymbol()->optionAt(1)->terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_multiple_rules) {
  BnfRuleParser parser;

  std::string rules = "<rule1> ::= <rule2>\n"
                      "<rule2> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  std::shared_ptr<NonTerminal> rule1 = grammar.startSymbol();
  ASSERT_EQ(1, rule1->size());
  ASSERT_TRUE(rule1->optionAt(0)->hasNonTerminalAt(0));

  std::shared_ptr<NonTerminal> rule2 = rule1->optionAt(0)->nonTerminalAt(0).lock();
  ASSERT_EQ(1, rule2->size());
  ASSERT_TRUE(rule2->optionAt(0)->hasTerminalAt(0));
  ASSERT_EQ("hello", rule2->optionAt(0)->terminalAt(0).value());
}

TEST(bnf_rule_parser_test, test_it_parses_multiple_rules_with_both_terminals_and_nonterminals) {
  BnfRuleParser parser;

  std::string rules = "<rule1> ::= <rule2> \"world\" | \"she\" \"said\"\n"
                      "<rule2> ::= \"hello\"";

  Grammar grammar = parser.parse(rules);

  std::shared_ptr<NonTerminal> rule1 = grammar.startSymbol();
  ASSERT_EQ(2, rule1->size());

  ASSERT_TRUE(rule1->optionAt(0)->hasNonTerminalAt(0));
  ASSERT_TRUE(rule1->optionAt(0)->hasTerminalAt(1));
  ASSERT_EQ("world", rule1->optionAt(0)->terminalAt(1).value());

  ASSERT_TRUE(rule1->optionAt(1)->hasTerminalAt(0));
  ASSERT_EQ("she", rule1->optionAt(1)->terminalAt(0).value());
  ASSERT_TRUE(rule1->optionAt(1)->hasTerminalAt(1));
  ASSERT_EQ("said", rule1->optionAt(1)->terminalAt(1).value());

  std::shared_ptr<NonTerminal> rule2 = rule1->optionAt(0)->nonTerminalAt(0).lock();
  ASSERT_EQ(1, rule2->size());
  ASSERT_TRUE(rule2->optionAt(0)->hasTerminalAt(0));
  ASSERT_EQ("hello", rule2->optionAt(0)->terminalAt(0).value());
}
