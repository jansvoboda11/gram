#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

Mapper::Mapper(gram::grammar::Grammar grammar) : grammar(grammar), genotype(), geneCount(0) {
  //
}

Phenotype Mapper::map(Genotype mappedGenotype) {
  genotype = mappedGenotype;
  geneCount = 0;

  Phenotype phenotype;
  std::shared_ptr<Rule> rule = grammar.getStartRule();

  return recursiveMap(phenotype, rule);
}

Phenotype &Mapper::recursiveMap(Phenotype &phenotype, std::shared_ptr<Rule> rule) {
  for (int i = 0; i < rule->size(); i++) {
    if (rule->hasTerminalAt(i)) {
      phenotype.addTerminal(rule->terminalAt(i));
    } else {
      std::shared_ptr<NonTerminal> nonTerminal = rule->nonTerminalAt(i);

      unsigned long gene = genotype[geneCount] % nonTerminal->ruleCount();
      geneCount += 1;

      recursiveMap(phenotype, nonTerminal->ruleAt(gene));
    }
  }

  return phenotype;
}
