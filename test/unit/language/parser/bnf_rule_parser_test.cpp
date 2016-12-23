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
