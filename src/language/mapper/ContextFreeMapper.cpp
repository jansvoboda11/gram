#include <gram/language/mapper/ContextFreeMapper.h>

using namespace gram;
using namespace std;

ContextFreeMapper::ContextFreeMapper(shared_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit)
    : grammar(grammar), wrappingLimit(wrappingLimit) {
  //
}

Phenotype ContextFreeMapper::map(const Genotype& genotype) {
  Phenotype phenotype;
  unsigned long geneNumber = 0;

  return recursiveMap(phenotype, *grammar->startRule(), genotype, geneNumber);
}

Phenotype& ContextFreeMapper::recursiveMap(Phenotype& phenotype,
                                           const Rule& rule,
                                           const Genotype& genotype,
                                           unsigned long& geneNumber) {
  if (isWrappingEvent(genotype, geneNumber) && exceededWrappingLimit(genotype, geneNumber)) {
    throw logic_error("Wrapping limit exceeded during genotype-phenotype mapping. ("
                      "limit: " + to_string(wrappingLimit) + ", "
                      "derivation: " + to_string(geneNumber + 1) + ", "
                      "genotype length: " + to_string(genotype.size()) + ")");
  }

  unsigned long geneIndex = geneNumber % genotype.size();
  unsigned long gene = genotype[geneIndex] % rule.size();

  Option& option = rule.optionAt(gene);

  for (unsigned long i = 0; i < option.size(); i++) {
    if (option.hasTerminalAt(i)) {
      phenotype.addTerminal(option.terminalAt(i));
    } else {
      geneNumber += 1;

      recursiveMap(phenotype, option.nonTerminalAt(i)->toRule(), genotype, geneNumber);
    }
  }

  return phenotype;
}

bool ContextFreeMapper::isWrappingEvent(const Genotype& genotype, unsigned long geneNumber) {
  unsigned long geneIndex = geneNumber % genotype.size();

  return geneIndex == 0 && geneNumber != 0;
}

bool ContextFreeMapper::exceededWrappingLimit(const Genotype& genotype, unsigned long geneNumber) {
  return (geneNumber / genotype.size()) > wrappingLimit;
}
