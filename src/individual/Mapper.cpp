#include <gram/individual/Mapper.h>

using namespace gram::language;
using namespace gram::individual;

Mapper::Mapper(std::shared_ptr<Grammar> grammar) : grammar(grammar) {
  //
}

Phenotype Mapper::map(Genotype mappedGenotype) const {
  Phenotype phenotype;
  std::shared_ptr<NonTerminal> nonTerminal = grammar->startRule();
  unsigned long geneCount = 0;

  // todo: convert to iterative algorithm
  return recursiveMap(phenotype, nonTerminal, mappedGenotype, geneCount);
}

Phenotype &Mapper::recursiveMap(Phenotype &phenotype, std::shared_ptr<NonTerminal> nonTerminal, Genotype genotype, unsigned long &geneCount) const {
  // todo: handle infinite genotype more gracefully
  if (geneCount > 100) {
    return phenotype;
  }

  unsigned long geneIndex = geneCount % genotype.size();
  unsigned long gene = genotype[geneIndex] % nonTerminal->size();

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
