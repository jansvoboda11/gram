#include "Mapper.h"

using namespace gram::language::grammar;
using namespace gram::population::individual;

Phenotype Mapper::map(Genotype genotype) {
  return Phenotype(std::vector<TerminalSymbol>());
}
