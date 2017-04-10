#include <gram/language/mapper/ContextFreeMapper.h>

using namespace gram;
using namespace std;

ContextFreeMapper::ContextFreeMapper(shared_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit)
    : grammar(grammar), wrappingLimit(wrappingLimit) {
  //
}

Phenotype ContextFreeMapper::map(const Genotype& genotype) {
  Phenotype phenotype;
  unsigned long geneCount = 0;

  return recursiveMap(phenotype, *grammar->startRule(), genotype, geneCount);
}

Phenotype& ContextFreeMapper::recursiveMap(Phenotype& phenotype,
                                           const NonTerminal& nonTerminal,
                                           const Genotype& genotype,
                                           unsigned long& geneCount) {
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
