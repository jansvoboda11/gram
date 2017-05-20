#include "gram/language/mapper/ContextFreeMapper.h"

#include <catch.hpp>

#include "gram/error/WrappingLimitExceeded.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/grammar/ContextFreeGrammar.h"
#include "gram/language/symbol/NonTerminal.h"
#include "gram/language/symbol/Option.h"
#include "gram/language/symbol/Rule.h"
#include "gram/language/symbol/Terminal.h"

using namespace Catch::Matchers;
using namespace gram;
using namespace std;

TEST_CASE("context-free mapper maps a terminal", "[context-free_mapper]") {
  // <rule> ::= "terminal"

  auto terminal = make_unique<Terminal>("terminal");
  auto rule = make_unique<Rule>("rule");
  auto option = make_unique<Option>();

  option->addTerminal(move(terminal));
  rule->addOption(move(option));

  auto grammar = make_unique<ContextFreeGrammar>();
  grammar->addRule(move(rule));

  Genotype genotype({0});

  ContextFreeMapper mapper(move(grammar), 1);

  REQUIRE(mapper.map(genotype) == Phenotype("terminal"));
}

TEST_CASE("context-free mapper maps a non-terminal", "[context-free_mapper]") {
  // <rule1> ::= <rule2>
  // <rule2> ::= "terminal"

  auto rule1 = make_unique<Rule>("rule1");
  auto rule2 = make_unique<Rule>("rule2");

  auto option1 = make_unique<Option>();
  auto option2 = make_unique<Option>();

  auto terminal = make_unique<Terminal>("terminal");
  auto nonTerminal = make_unique<NonTerminal>(*rule2);

  option1->addNonTerminal(move(nonTerminal));
  option2->addTerminal(move(terminal));

  rule1->addOption(move(option1));
  rule2->addOption(move(option2));

  auto grammar = make_unique<ContextFreeGrammar>();
  grammar->addRule(move(rule1));
  grammar->addRule(move(rule2));

  Genotype genotype{0};

  ContextFreeMapper mapper(move(grammar), 1);

  REQUIRE(mapper.map(genotype) == Phenotype("terminal"));
}

TEST_CASE("context-free mapper handles more complex grammar", "[context-free-mapper[") {
  // <number> ::= <digit> <number> | <digit>
  // <digit> ::= "0" | "1"

  auto digit0 = make_unique<Terminal>("0");
  auto digit1 = make_unique<Terminal>("1");

  auto option0 = make_unique<Option>();
  auto option1 = make_unique<Option>();

  option0->addTerminal(move(digit0));
  option1->addTerminal(move(digit1));

  auto digit = make_unique<Rule>("digit");
  auto digitNonTerminal1 = make_unique<NonTerminal>(*digit);
  auto digitNonTerminal2 = make_unique<NonTerminal>(*digit);

  digit->addOption(move(option0));
  digit->addOption(move(option1));

  auto number = make_unique<Rule>("number");
  auto numberNonTerminal = make_unique<NonTerminal>(*number);

  auto numberOption1 = make_unique<Option>();
  auto numberOption2 = make_unique<Option>();

  numberOption1->addNonTerminal(move(digitNonTerminal1));
  numberOption1->addNonTerminal(move(numberNonTerminal));
  numberOption2->addNonTerminal(move(digitNonTerminal2));

  number->addOption(move(numberOption1));
  number->addOption(move(numberOption2));

  auto grammar = make_unique<ContextFreeGrammar>();
  grammar->addRule(move(number));
  grammar->addRule(move(digit));

  SECTION("context-free mapper maps a recursive grammar") {
    ContextFreeMapper mapper(move(grammar), 1);

    REQUIRE(mapper.map(Genotype({0, 0, 1, 1})) == Phenotype("01"));
  }

  SECTION("context-free mapper wraps the genotype") {
    ContextFreeMapper mapper(move(grammar), 1);

    REQUIRE(mapper.map(Genotype({0, 1, 1})) == Phenotype("10"));
  }

  SECTION("context-free mapper respects wrapping limit") {
    ContextFreeMapper mapper(move(grammar), 1);

    REQUIRE_THROWS_AS(mapper.map(Genotype({0, 0, 0})), WrappingLimitExceeded);
  }
}
