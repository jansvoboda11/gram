#include <catch.hpp>

#include <gram/language/mapper/ContextFreeMapper.h>

using namespace Catch::Matchers;
using namespace gram;
using namespace std;

TEST_CASE("context-free mapper maps a terminal", "[context-free_mapper]") {
  Terminal terminal("test");
  auto option = make_shared<Option>();
  auto startSymbol = make_shared<NonTerminal>();

  option->addTerminal(terminal);
  startSymbol->addOption(option);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule("rule", startSymbol);

  Genotype genotype({0});

  ContextFreeMapper mapper(grammar, 1);

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal);

  REQUIRE(mapper.map(genotype) == expectedPhenotype);
}

TEST_CASE("context-free mapper maps a non-terminal", "[context-free_mapper]") {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  auto startSymbol = make_shared<NonTerminal>();

  startSymbol->addOption(option1);
  startSymbol->addOption(option2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule("rule", startSymbol);

  Genotype genotype{1};

  ContextFreeMapper mapper(grammar, 1);

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal2);

  REQUIRE(mapper.map(genotype) == expectedPhenotype);
}

TEST_CASE("context-free mapper maps linear grammar", "[context-free_mapper]") {
  Terminal digit0("0");
  Terminal digit1("1");
  Terminal digit2("2");
  Terminal digit3("3");
  Terminal digit4("4");
  Terminal digit5("5");
  Terminal digit6("6");
  Terminal digit7("7");
  Terminal digit8("8");
  Terminal digit9("9");

  auto option0 = make_shared<Option>();
  auto option1 = make_shared<Option>();
  auto option2 = make_shared<Option>();
  auto option3 = make_shared<Option>();
  auto option4 = make_shared<Option>();
  auto option5 = make_shared<Option>();
  auto option6 = make_shared<Option>();
  auto option7 = make_shared<Option>();
  auto option8 = make_shared<Option>();
  auto option9 = make_shared<Option>();

  option0->addTerminal(digit0);
  option1->addTerminal(digit1);
  option2->addTerminal(digit2);
  option3->addTerminal(digit3);
  option4->addTerminal(digit4);
  option5->addTerminal(digit5);
  option6->addTerminal(digit6);
  option7->addTerminal(digit7);
  option8->addTerminal(digit8);
  option9->addTerminal(digit9);

  auto digit = make_shared<NonTerminal>();
  digit->addOption(option0);
  digit->addOption(option1);
  digit->addOption(option2);
  digit->addOption(option3);
  digit->addOption(option4);
  digit->addOption(option5);
  digit->addOption(option6);
  digit->addOption(option7);
  digit->addOption(option8);
  digit->addOption(option9);

  auto startSymbol = make_shared<NonTerminal>();

  auto digitOption = make_shared<Option>();
  digitOption->addNonTerminal(digit);

  auto numberOption = make_shared<Option>();
  numberOption->addNonTerminal(digit);
  numberOption->addNonTerminal(startSymbol);

  startSymbol->addOption(digitOption);
  startSymbol->addOption(numberOption);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule("number", startSymbol);
  grammar->addRule("digit", digit);

  ContextFreeMapper mapper(grammar, 1);

  Phenotype phenotype = mapper.map(Genotype({7, 16, 11, 25, 0, 39}));

  REQUIRE(phenotype.serialize() == "659");
}

TEST_CASE("context-free mapper wraps the genotype", "[context-free_mapper]") {
  auto rule1 = make_shared<NonTerminal>();
  auto rule2 = make_shared<NonTerminal>();

  auto option1 = make_shared<Option>();
  option1->addNonTerminal(rule2);
  rule1->addOption(option1);

  auto option2 = make_shared<Option>();
  option2->addTerminal(Terminal("hello"));
  rule2->addOption(option2);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule("rule1", rule1);

  ContextFreeMapper mapper(grammar, 1);

  Phenotype phenotype = mapper.map(Genotype({0}));

  REQUIRE(phenotype.serialize() == "hello");
}

TEST_CASE("context-free mapper respects wrapping limit", "[context-free_mapper]") {
  auto rule = make_shared<NonTerminal>();

  auto option = make_shared<Option>();
  option->addNonTerminal(rule);
  rule->addOption(option);

  auto grammar = make_shared<ContextFreeGrammar>();
  grammar->addRule("rule", rule);

  ContextFreeMapper mapper(grammar, 2);

  REQUIRE_THROWS_WITH(mapper.map(Genotype({0, 0, 0})),
                      Contains("Wrapping limit exceeded during genotype-phenotype mapping."));
}
