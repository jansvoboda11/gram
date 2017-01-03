#include <gram/language/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

ContextFreeGrammar::ContextFreeGrammar() : start(), rules() {
  //
}

Phenotype ContextFreeGrammar::expand(const Genotype& genotype) {
  Phenotype phenotype;
  unsigned long geneCount = 0;

  return recursiveExpand(phenotype, *start, genotype, geneCount);
}

void ContextFreeGrammar::addRule(string name, shared_ptr<NonTerminal> rule) {
  rules[name] = rule;

  if (!start) {
    start = rule;
  }
}

shared_ptr<NonTerminal> ContextFreeGrammar::ruleNamed(string name) {
  shared_ptr<NonTerminal>& rule = rules[name];

  if (!rule) {
    rule = make_shared<NonTerminal>();
  }

  if (!start) {
    start = rule;
  }

  return rule;
}

shared_ptr<NonTerminal> ContextFreeGrammar::startRule() const {
  if (!start) {
    throw logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

Phenotype& ContextFreeGrammar::recursiveExpand(Phenotype& phenotype,
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

      recursiveExpand(phenotype, option.nonTerminalAt(i), genotype, geneCount);
    }
  }

  return phenotype;
}
