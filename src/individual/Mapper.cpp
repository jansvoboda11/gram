#include <gram/individual/Mapper.h>

using namespace gram;
using namespace std;

Mapper::Mapper(shared_ptr<Grammar> grammar) : grammar(grammar) {
  //
}

Phenotype Mapper::map(const Genotype& genotype) const {
  Phenotype phenotype;
  NonTerminal nonTerminal = *grammar->startRule();
  unsigned long geneCount = 0;

  // todo: convert to iterative algorithm
  return recursiveMap(phenotype, nonTerminal, genotype, geneCount);
}

Phenotype& Mapper::recursiveMap(Phenotype& phenotype,
                                const NonTerminal& nonTerminal,
                                const Genotype& genotype,
                                unsigned long& geneCount) const {
  // todo: handle infinite genotype more gracefully
  if (geneCount > 100) {
    return phenotype;
  }

  unsigned long geneIndex = geneCount % genotype.size();
  unsigned long gene = genotype[geneIndex] % nonTerminal.size();

  Option option = nonTerminal.optionAt(gene);

  for (unsigned long i = 0; i < option.size(); i++) {
    if (option.hasTerminalAt(i)) {
      phenotype.addTerminal(option.terminalAt(i));
    } else {
      geneCount += 1;

      recursiveMap(phenotype, option.nonTerminalAt(i), genotype, geneCount);
    }
  }

  return phenotype;
}
