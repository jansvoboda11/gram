#include <catch.hpp>

#include <gram/language/parser/BnfRuleParser.h>

using namespace gram;
using namespace std;

TEST_CASE("BNF rule parser pareses rule with one terminal", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule = grammar.startRule();

  REQUIRE(rule->size() == 1);
  REQUIRE(rule->optionAt(0).hasTerminalAt(0));
  REQUIRE(rule->optionAt(0).terminalAt(0)->getValue() == "hello");
}

TEST_CASE("BNF rule parser parses rule with multiple terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule = grammar.startRule();

  REQUIRE(rule->size() == 1);
  REQUIRE(rule->optionAt(0).hasTerminalAt(0));
  REQUIRE(rule->optionAt(0).hasTerminalAt(1));
  REQUIRE(rule->optionAt(0).terminalAt(0)->getValue() == "hello");
  REQUIRE(rule->optionAt(0).terminalAt(1)->getValue() == "world");
}

TEST_CASE("BNF rule parser parses rule with multiple terminal options", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules = "<rule> ::= \"hello\" \"world\" | \"she said\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule = grammar.startRule();

  REQUIRE(rule->size() == 2);
  REQUIRE(rule->optionAt(0).hasTerminalAt(0));
  REQUIRE(rule->optionAt(0).hasTerminalAt(1));
  REQUIRE(rule->optionAt(1).hasTerminalAt(0));
  REQUIRE(rule->optionAt(0).terminalAt(0)->getValue() == "hello");
  REQUIRE(rule->optionAt(0).terminalAt(1)->getValue() == "world");
  REQUIRE(rule->optionAt(1).terminalAt(0)->getValue() == "she said");
}

TEST_CASE("BNF rule parser parses multiple rules with terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2>\n"
          "<rule2> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule1 = grammar.startRule();
  REQUIRE(rule1->size() == 1);
  REQUIRE(rule1->optionAt(0).hasNonTerminalAt(0));

  Rule& rule2 = rule1->optionAt(0).nonTerminalAt(0)->toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2.optionAt(0).hasTerminalAt(0));
  REQUIRE(rule2.optionAt(0).terminalAt(0)->getValue() == "hello");
}

TEST_CASE("BNF rule parser parses rules with terminals and non-terminals", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "<rule1> ::= <rule2> \"world\" | \"she\" \"said\"\n"
      "<rule2> ::= \"hello\"";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule1 = grammar.startRule();
  REQUIRE(rule1->size() == 2);

  REQUIRE(rule1->optionAt(0).hasNonTerminalAt(0));
  REQUIRE(rule1->optionAt(0).hasTerminalAt(1));
  REQUIRE(rule1->optionAt(0).terminalAt(1)->getValue() == "world");

  REQUIRE(rule1->optionAt(1).hasTerminalAt(0));
  REQUIRE(rule1->optionAt(1).terminalAt(0)->getValue() == "she");
  REQUIRE(rule1->optionAt(1).hasTerminalAt(1));
  REQUIRE(rule1->optionAt(1).terminalAt(1)->getValue() == "said");

  Rule& rule2 = rule1->optionAt(0).nonTerminalAt(0)->toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2.optionAt(0).hasTerminalAt(0));
  REQUIRE(rule2.optionAt(0).terminalAt(0)->getValue() == "hello");
}

TEST_CASE("BNF rule parser parses rules with extra whitespace", "[bnf_rule_parser]") {
  BnfRuleParser parser;

  string rules =
      "    <start>::= \"world\"  |<next> \n"
      " \n"
      "<next> ::= \"hello\"\n"
      "\n";

  ContextFreeGrammar grammar = parser.parse(rules);

  shared_ptr<Rule> rule1 = grammar.startRule();
  REQUIRE(rule1->size() == 2);
  REQUIRE(rule1->optionAt(0).hasTerminalAt(0));
  REQUIRE(rule1->optionAt(0).terminalAt(0)->getValue() == "world");
  REQUIRE(rule1->optionAt(1).hasNonTerminalAt(0));

  Rule& rule2 = rule1->optionAt(1).nonTerminalAt(0)->toRule();
  REQUIRE(rule2.size() == 1);
  REQUIRE(rule2.optionAt(0).hasTerminalAt(0));
  REQUIRE(rule2.optionAt(0).terminalAt(0)->getValue() == "hello");
}
