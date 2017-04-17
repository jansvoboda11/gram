#include "gram/language/parser/BnfRuleParser.h"

#include <catch.hpp>

using namespace gram;
using namespace std;

TEST_CASE("BNF rule parser pareses rule with one terminal", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule = grammar.startRule();

  REQUIRE(rule.size() == 1);
  REQUIRE(rule[0][0].isTerminal());
}

TEST_CASE("BNF rule parser parses rule with multiple terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule = grammar.startRule();

  REQUIRE(rule.size() == 1);
  REQUIRE(rule[0][0].isTerminal());
  REQUIRE(rule[0][1].isTerminal());
}

TEST_CASE("BNF rule parser parses rule with multiple terminal options", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\" | \"she said\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule = grammar.startRule();

  REQUIRE(rule.size() == 2);
  REQUIRE(rule[0][0].isTerminal());
  REQUIRE(rule[0][1].isTerminal());
  REQUIRE(rule[1][0].isTerminal());
}

TEST_CASE("BNF rule parser parses multiple rules with terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2>\n"
          "<rule2> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule1 = grammar.startRule();
  REQUIRE(rule1.size() == 1);
  REQUIRE(rule1[0][0].isNonTerminal());

  Rule& rule2 = rule1[0][0].toNonTerminal().toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2[0][0].isTerminal());
}

TEST_CASE("BNF rule parser parses rules with terminals and non-terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2> \"world\" | \"she\" \"said\"\n"
      "<rule2> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule1 = grammar.startRule();
  REQUIRE(rule1.size() == 2);

  REQUIRE(rule1[0][0].isNonTerminal());
  REQUIRE(rule1[0][1].isTerminal());

  REQUIRE(rule1[1][0].isTerminal());
  REQUIRE(rule1[1][1].isTerminal());

  Rule& rule2 = rule1[0][0].toNonTerminal().toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2[0][0].isTerminal());
}

TEST_CASE("BNF rule parser parses rules with extra whitespace", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "    <start>::= \"world\"  |<next> \n"
      " \n"
      "<next> ::= \"hello\"\n"
      "\n";

  ContextFreeGrammar grammar = parser.parse(rules);

  Rule& rule1 = grammar.startRule();
  REQUIRE(rule1.size() == 2);
  REQUIRE(rule1[0][0].isTerminal());
  REQUIRE(rule1[1][0].isNonTerminal());

  Rule& rule2 = rule1[1][0].toNonTerminal().toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2[0][0].isTerminal());
}
