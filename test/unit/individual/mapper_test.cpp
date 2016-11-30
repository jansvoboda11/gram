#include <gtest/gtest.h>

#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");

  Rule startRule;
  startRule.addTerminal(terminal);

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

  Rule firstRule;
  firstRule.addTerminal(firstTerminal);

  Rule secondRule;
  secondRule.addTerminal(secondTerminal);

  NonTerminal nonTerminal;
  nonTerminal.addRule(firstRule);
  nonTerminal.addRule(secondRule);

  Rule startRule;
  startRule.addNonTerminal(nonTerminal);

  Grammar grammar(startRule);

  Genotype genotype{1};

  Phenotype phenotype;
  phenotype.addTerminal(secondTerminal);

  Mapper mapper(genotype, grammar);
  Phenotype mapped = mapper.map();

  ASSERT_EQ(phenotype, mapped);
}
