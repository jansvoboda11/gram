#include <gtest/gtest.h>

#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");

  auto startRule = std::make_shared<Rule>();
  startRule->addTerminal(terminal);

  Grammar grammar(startRule);

  Genotype genotype{0};

  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mapper mapper(genotype, grammar);
  Phenotype mapped = mapper.map();

  ASSERT_EQ(phenotype, mapped);
}

TEST(mapper_test, test_it_maps_nonterminal) {
  Terminal firstTerminal("first");
  Terminal secondTerminal("second");

  auto firstRule = std::make_shared<Rule>();
  firstRule->addTerminal(firstTerminal);

  auto secondRule = std::make_shared<Rule>();
  secondRule->addTerminal(secondTerminal);

  auto nonTerminal = std::make_shared<NonTerminal>();
  nonTerminal->addRule(firstRule);
  nonTerminal->addRule(secondRule);

  auto startRule = std::make_shared<Rule>();
  startRule->addNonTerminal(nonTerminal);

  Grammar grammar(startRule);

  Genotype genotype{1};

  Phenotype phenotype;
  phenotype.addTerminal(secondTerminal);

  Mapper mapper(genotype, grammar);
  Phenotype mapped = mapper.map();

  ASSERT_EQ(phenotype, mapped);
}
