#include <gtest/gtest.h>

#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");

  auto option = std::make_shared<Option>();
  option->addTerminal(terminal);

  auto startSymbol = std::make_shared<NonTerminal>();
  startSymbol->addOption(option);

  Grammar grammar(startSymbol);

  Genotype genotype{0};

  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mapper mapper(grammar);
  Phenotype mapped = mapper.map(genotype);

  ASSERT_EQ(phenotype, mapped);
}

TEST(mapper_test, test_it_maps_nonterminal) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  auto firstOption = std::make_shared<Option>();
  firstOption->addTerminal(firstTerminal);

  auto secondRule = std::make_shared<Option>();
  secondRule->addTerminal(secondTerminal);

  auto startSymbol = std::make_shared<NonTerminal>();
  startSymbol->addOption(firstOption);
  startSymbol->addOption(secondRule);

  Grammar grammar(startSymbol);

  Genotype genotype{1};

  Phenotype phenotype;
  phenotype.addTerminal(secondTerminal);

  Mapper mapper(grammar);
  Phenotype mapped = mapper.map(genotype);

  ASSERT_EQ(phenotype, mapped);
}
