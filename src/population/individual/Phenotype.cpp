#include "Phenotype.h"

using namespace gram::language::grammar;
using namespace gram::population::individual;

Phenotype::Phenotype(std::vector<TerminalSymbol> terminals)
    : terminals(terminals) {
  //
}

std::string Phenotype::serialize() {
  return std::string();
}
