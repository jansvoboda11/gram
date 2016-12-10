#include <gtest/gtest.h>

#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");
  auto option = std::make_shared<Option>();
  auto startSymbol = std::make_shared<NonTerminal>();

  option->addTerminal(terminal);
  startSymbol->addOption(option);

  Grammar grammar(startSymbol);
  Genotype genotype{0};

  Mapper mapper(grammar);

  Phenotype mapped = mapper.map(genotype);

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal);
  ASSERT_EQ(expectedPhenotype, mapped);
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

  Grammar grammar(startSymbol);
  Genotype genotype{1};

  Mapper mapper(grammar);

  Phenotype mapped = mapper.map(genotype);

  Phenotype expectedPhenotype;
  expectedPhenotype.addTerminal(terminal2);
  ASSERT_EQ(expectedPhenotype, mapped);
}
