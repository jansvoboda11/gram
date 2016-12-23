#include <gram/individual/Mapper.h>

using namespace gram::language;
using namespace gram::individual;

Mapper::Mapper(std::shared_ptr<Grammar> grammar) : grammar(grammar) {
  //
}

Phenotype Mapper::map(Genotype mappedGenotype) const {
  Phenotype phenotype;
  std::shared_ptr<NonTerminal> nonTerminal = grammar->startSymbol();
  unsigned long geneCount = 0;

  return recursiveMap(phenotype, nonTerminal, mappedGenotype, geneCount);
}

Phenotype &Mapper::recursiveMap(Phenotype &phenotype, std::shared_ptr<NonTerminal> nonTerminal, Genotype genotype, unsigned long &geneCount) const {
  unsigned long gene = genotype[geneCount] % nonTerminal->size();

  std::shared_ptr<Option> option = nonTerminal->optionAt(gene);

  for (unsigned long i = 0; i < option->size(); i++) {
    if (option->hasTerminalAt(i)) {
      phenotype.addTerminal(option->terminalAt(i));
    } else {
      geneCount += 1;

      recursiveMap(phenotype, option->nonTerminalAt(i).lock(), genotype, geneCount);
    }
  }

  return phenotype;
}
