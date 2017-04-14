#include <catch.hpp>

#include <gram/language/mapper/ContextFreeMapper.h>

using namespace Catch::Matchers;
using namespace gram;
using namespace std;

TEST_CASE("context-free mapper maps a terminal", "[context-free_mapper]") {
//  <rule> ::= "terminal"
  auto terminal = make_shared<Terminal>("terminal");
  auto rule = make_unique<Rule>("rule");
  auto option = make_shared<Option>();

  option->addTerminal(terminal);
  rule->addOption(option);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule(move(rule));

  Genotype genotype({0});

  ContextFreeMapper mapper(grammar, 1);

  Phenotype expectedPhenotype;
  expectedPhenotype += terminal->getValue();

  REQUIRE(mapper.map(genotype) == expectedPhenotype);
}

TEST_CASE("context-free mapper maps a non-terminal", "[context-free_mapper]") {
//  <rule1> ::= <rule2>
//  <rule2> ::= "terminal"

  auto rule1 = make_unique<Rule>("rule1");
  auto rule2 = make_unique<Rule>("rule2");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  auto terminal = make_shared<Terminal>("terminal");
  auto nonTerminal = make_shared<NonTerminal>(*rule2);

  option1->addNonTerminal(nonTerminal);
  option2->addTerminal(terminal);

  rule1->addOption(option1);
  rule2->addOption(option2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule(move(rule1));
  grammar->addRule(move(rule2));

  Genotype genotype{0};

  ContextFreeMapper mapper(grammar, 1);

  Phenotype expectedPhenotype;
  expectedPhenotype += terminal->getValue();

  REQUIRE(mapper.map(genotype) == expectedPhenotype);
}

TEST_CASE("context-free mapper maps a recursive grammar", "[context-free_mapper]") {
//  <number> ::= <digit> <number> | <digit>
//  <digit> ::= "0" | "1"

  auto digit0 = make_shared<Terminal>("0");
  auto digit1 = make_shared<Terminal>("1");

  auto option0 = make_shared<Option>();
  auto option1 = make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);

  auto digit = make_unique<Rule>("digit");
  auto digitNonTerminal = make_shared<NonTerminal>(*digit);

  digit->addOption(option0);
  digit->addOption(option1);

  auto number = make_unique<Rule>("number");
  auto numberNonTerminal = make_shared<NonTerminal>(*number);

  auto numberOption1 = make_shared<Option>();
  auto numberOption2 = make_shared<Option>();

  numberOption1->addNonTerminal(digitNonTerminal);
  numberOption1->addNonTerminal(numberNonTerminal);
  numberOption2->addNonTerminal(digitNonTerminal);

  number->addOption(numberOption1);
  number->addOption(numberOption2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule(move(number));
  grammar->addRule(move(digit));

  ContextFreeMapper mapper(grammar, 1);

  Phenotype phenotype = mapper.map(Genotype({0, 0, 1, 1}));

  REQUIRE(phenotype == "01");
}

TEST_CASE("context-free mapper wraps the genotype", "[context-free_mapper]") {
//  <number> ::= <digit> <number> | <digit>
//  <digit> ::= "0" | "1"

  auto digit0 = make_shared<Terminal>("0");
  auto digit1 = make_shared<Terminal>("1");

  auto option0 = make_shared<Option>();
  auto option1 = make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);

  auto digit = make_unique<Rule>("digit");
  auto digitNonTerminal = make_shared<NonTerminal>(*digit);

  digit->addOption(option0);
  digit->addOption(option1);

  auto number = make_unique<Rule>("number");
  auto numberNonTerminal = make_shared<NonTerminal>(*number);

  auto numberOption1 = make_shared<Option>();
  auto numberOption2 = make_shared<Option>();

  numberOption1->addNonTerminal(digitNonTerminal);
  numberOption1->addNonTerminal(numberNonTerminal);
  numberOption2->addNonTerminal(digitNonTerminal);

  number->addOption(numberOption1);
  number->addOption(numberOption2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule(move(number));
  grammar->addRule(move(digit));

  ContextFreeMapper mapper(grammar, 1);

  Phenotype phenotype = mapper.map(Genotype({0, 1, 1}));

  REQUIRE(phenotype == "10");
}

TEST_CASE("context-free mapper respects wrapping limit", "[context-free_mapper]") {
//  <number> ::= <digit> <number> | <digit>
//  <digit> ::= "0" | "1"

  auto digit0 = make_shared<Terminal>("0");
  auto digit1 = make_shared<Terminal>("1");

  auto option0 = make_shared<Option>();
  auto option1 = make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);

  auto digit = make_unique<Rule>("digit");
  auto digitNonTerminal = make_shared<NonTerminal>(*digit);

  digit->addOption(option0);
  digit->addOption(option1);

  auto number = make_unique<Rule>("number");
  auto numberNonTerminal = make_shared<NonTerminal>(*number);

  auto numberOption1 = make_shared<Option>();
  auto numberOption2 = make_shared<Option>();

  numberOption1->addNonTerminal(digitNonTerminal);
  numberOption1->addNonTerminal(numberNonTerminal);
  numberOption2->addNonTerminal(digitNonTerminal);

  number->addOption(numberOption1);
  number->addOption(numberOption2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule(move(number));
  grammar->addRule(move(digit));

  ContextFreeMapper mapper(grammar, 1);

  REQUIRE_THROWS_WITH(mapper.map(Genotype({0, 0, 0})),
                      Contains("Wrapping limit exceeded during genotype-phenotype mapping."));
}
