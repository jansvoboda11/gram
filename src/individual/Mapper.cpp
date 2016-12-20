#include <gram/individual/Mapper.h>

using namespace gram::grammar;
using namespace gram::individual;

Mapper::Mapper(Grammar grammar) : grammar(grammar), genotype(), geneCount(0) {
  //
}

Phenotype Mapper::map(Genotype mappedGenotype) {
  genotype = mappedGenotype;
  geneCount = 0;

  Phenotype phenotype;
  std::shared_ptr<NonTerminal> nonTerminal = grammar.startSymbol();

  return recursiveMap(phenotype, nonTerminal);
}

Phenotype &Mapper::recursiveMap(Phenotype &phenotype, std::shared_ptr<NonTerminal> nonTerminal) {
  unsigned long gene = genotype[geneCount] % nonTerminal->size();
  geneCount += 1;

  std::shared_ptr<Option> option = nonTerminal->optionAt(gene);

  for (unsigned long i = 0; i < option->size(); i++) {
    if (option->hasTerminalAt(i)) {
      phenotype.addTerminal(option->terminalAt(i));
    } else {
      recursiveMap(phenotype, option->nonTerminalAt(gene));
    }
  }

  return phenotype;
}
