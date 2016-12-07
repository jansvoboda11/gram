#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

Mapper::Mapper(Genotype genotype, gram::grammar::Grammar grammar)
    : phenotype(), genotype(genotype), grammar(grammar), geneCount(0) {
  //
}

Phenotype Mapper::map() {
  std::weak_ptr<Rule> rule = grammar.getStartRule();

  return recursiveMap(rule);
}

Phenotype Mapper::recursiveMap(std::weak_ptr<Rule> rule) {
  std::shared_ptr<Rule> sharedRule = rule.lock();

  for (int i = 0; i < sharedRule->size(); i++) {
    if (sharedRule->hasTerminalAt(i)) {
      phenotype.addTerminal(sharedRule->terminalAt(i));
    } else {
      std::shared_ptr<NonTerminal> nonTerminal = sharedRule->nonTerminalAt(i);

      int gene = genotype[geneCount];
      geneCount += 1;

      recursiveMap(nonTerminal->ruleAt(gene));
    }
  }

  return phenotype;
}
