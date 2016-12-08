#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

Mapper::Mapper(gram::grammar::Grammar grammar) : grammar(grammar), phenotype() {
  //
}

Phenotype Mapper::map(Genotype genotype) {
  std::shared_ptr<Rule> rule = grammar.getStartRule();

  return recursiveMap(genotype, 0, rule);
}

Phenotype Mapper::recursiveMap(Genotype genotype, int geneCount, std::shared_ptr<Rule> rule) {
  for (int i = 0; i < rule->size(); i++) {
    if (rule->hasTerminalAt(i)) {
      phenotype.addTerminal(rule->terminalAt(i));
    } else {
      std::shared_ptr<NonTerminal> nonTerminal = rule->nonTerminalAt(i);

      int gene = genotype[geneCount];
      geneCount += 1;

      recursiveMap(genotype, geneCount, nonTerminal->ruleAt(gene));
    }
  }

  return phenotype;
}
