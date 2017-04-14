#include <gram/language/mapper/ContextFreeMapper.h>

using namespace gram;
using namespace std;

ContextFreeMapper::ContextFreeMapper(shared_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit)
    : grammar(grammar), wrappingLimit(wrappingLimit) {
  symbols.reserve(512);
}

Phenotype ContextFreeMapper::map(const Genotype& genotype) {
  symbols.clear();

  Phenotype phenotype;

  unsigned long wrappings = 0;
  unsigned long codonIndex = 0;

  Rule& startRule = grammar->startRule();
  unsigned long optionIndex = genotype[codonIndex] % startRule.size();
  Option& startOption = startRule[optionIndex];
  pushOption(startOption);
  codonIndex += 1;

  while (!symbols.empty()) {
    auto symbol = symbols.back();
    symbols.pop_back();

    if (symbol->isTerminal()) {
      auto terminal = symbol->toTerminal();
      phenotype += terminal.getValue();
    } else {
      if (codonIndex == genotype.size()) {
        codonIndex = 0;
        wrappings += 1;

        if (wrappings > wrappingLimit) {
          throw logic_error("Wrapping limit exceeded during genotype-phenotype mapping.");
        }
      }

      auto nonTerminal = symbol->toNonTerminal();
      Rule& rule = nonTerminal.toRule();
      optionIndex = genotype[codonIndex] % rule.size();
      Option& option = rule[optionIndex];
      pushOption(option);
      codonIndex += 1;
    }
  }

  return phenotype;
}

void ContextFreeMapper::pushOption(Option& option) {
  auto& optionSymbols = option.getSymbols();
  unsigned long optionSize = optionSymbols.size();

  for (long i = optionSize - 1; i >= 0; i--) {
    symbols.push_back(optionSymbols[i]);
  }
}