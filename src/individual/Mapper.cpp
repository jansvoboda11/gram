#include <gram/individual/Mapper.h>

using namespace gram::language;
using namespace gram::individual;

Mapper::Mapper(std::shared_ptr<Grammar> grammar) : grammar(grammar) {
  //
}

Phenotype Mapper::map(Genotype mappedGenotype) const {
  Phenotype phenotype;
  std::shared_ptr<NonTerminal> nonTerminal = grammar->startSymbol();

  return recursiveMap(phenotype, nonTerminal, mappedGenotype, 0);
}

Phenotype &Mapper::recursiveMap(Phenotype &phenotype, std::shared_ptr<NonTerminal> nonTerminal, Genotype genotype, int geneCount) const {
  unsigned long gene = genotype[geneCount] % nonTerminal->size();

  std::shared_ptr<Option> option = nonTerminal->optionAt(gene);

  for (unsigned long i = 0; i < option->size(); i++) {
    if (option->hasTerminalAt(i)) {
      phenotype.addTerminal(option->terminalAt(i));
    } else {
      recursiveMap(phenotype, option->nonTerminalAt(gene), genotype, geneCount + 1);
    }
  }

  return phenotype;
}
