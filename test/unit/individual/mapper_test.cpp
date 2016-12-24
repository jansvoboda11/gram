#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/Mapper.h>

using namespace gram::language;
using namespace gram::individual;

using namespace fakeit;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");
  auto option = std::make_shared<Option>();
  auto startSymbol = std::make_shared<NonTerminal>();

  option->addTerminal(terminal);
  startSymbol->addOption(option);

  auto grammar = std::make_shared<Grammar>();
  grammar->addRule("rule", startSymbol);

  Mapper mapper(grammar);

  Genotype genotype({0});

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal);

  ASSERT_EQ(expectedPhenotype, mapper.map(genotype));
}

TEST(mapper_test, test_it_maps_nonterminal) {
  Terminal terminal1("first");
  Terminal terminal2("second");

  auto option1 = std::make_shared<Option>();
  auto option2 = std::make_shared<Option>();

  option1->addTerminal(terminal1);
  option2->addTerminal(terminal2);

  auto startSymbol = std::make_shared<NonTerminal>();

  startSymbol->addOption(option1);
  startSymbol->addOption(option2);

  auto grammar = std::make_shared<Grammar>();
  grammar->addRule("rule", startSymbol);

  Mapper mapper(grammar);

  Genotype genotype{1};

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal2);

  ASSERT_EQ(expectedPhenotype, mapper.map(genotype));
}

TEST(mapper_test, test_it_maps_linear_grammar) {
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

  auto option0 = std::make_shared<Option>();
  auto option1 = std::make_shared<Option>();
  auto option2 = std::make_shared<Option>();
  auto option3 = std::make_shared<Option>();
  auto option4 = std::make_shared<Option>();
  auto option5 = std::make_shared<Option>();
  auto option6 = std::make_shared<Option>();
  auto option7 = std::make_shared<Option>();
  auto option8 = std::make_shared<Option>();
  auto option9 = std::make_shared<Option>();

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

  auto digit = std::make_shared<NonTerminal>();
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

  auto startSymbol = std::make_shared<NonTerminal>();

  auto digitOption = std::make_shared<Option>();
  digitOption->addNonTerminal(digit);

  auto numberOption = std::make_shared<Option>();
  numberOption->addNonTerminal(digit);
  numberOption->addNonTerminal(startSymbol);

  startSymbol->addOption(digitOption);
  startSymbol->addOption(numberOption);

  auto grammar = std::make_shared<Grammar>();
  grammar->addRule("number", startSymbol);
  grammar->addRule("digit", digit);

  Mapper mapper(grammar);

  Phenotype phenotype = mapper.map(Genotype({7, 16, 11, 25, 0, 39}));

  ASSERT_EQ("659", phenotype.serialize());
}
