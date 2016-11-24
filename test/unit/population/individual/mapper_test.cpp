#include <gtest/gtest.h>

#include <language/grammar/symbol/NonTerminal.h>
#include <language/grammar/Grammar.h>
#include <population/individual/Genotype.h>
#include <population/individual/Mapper.h>

using namespace gram::language::grammar;
using namespace gram::population::individual;

TEST(mapper_test, test_it_maps_one_terminal) {
  Terminal terminal("test");

  Rule startRule;
  startRule.addTerminal(terminal);

  Grammar grammar(startRule);

  std::vector<int> numbers{0};
  Genotype genotype(numbers);

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

  std::vector<int> numbers{1};
  Genotype genotype(numbers);

  Phenotype phenotype;
  phenotype.addTerminal(secondTerminal);

  Mapper mapper(genotype, grammar);
  Phenotype mapped = mapper.map();

  ASSERT_EQ(phenotype, mapped);
}
