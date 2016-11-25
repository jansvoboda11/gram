#include <population/individual/Mapper.h>

using namespace gram::language::grammar;
using namespace gram::population::individual;

Mapper::Mapper(Genotype genotype, gram::language::grammar::Grammar grammar)
    : phenotype(), genotype(genotype), grammar(grammar), geneCount(0) {
  //
}

Phenotype Mapper::map() {
  Rule rule = grammar.getStartRule();

  return recursiveMap(rule);
}

Phenotype Mapper::recursiveMap(Rule rule) {
  for (int i = 0; i < rule.size(); i++) {
    if (rule.hasTerminalAt(i)) {
      phenotype.addTerminal(rule.terminalAt(i));
    } else {
      NonTerminal &nonTerminal = rule.nonTerminalAt(i);

      int gene = genotype[geneCount];
      geneCount += 1;

      recursiveMap(nonTerminal.ruleAt(gene));
    }
  }

  return phenotype;
}
