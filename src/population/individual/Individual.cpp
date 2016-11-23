#include "Individual.h"

using namespace gram::language::grammar;
using namespace gram::population::individual;

Individual::Individual()
    : genotype(std::vector<int>(0)), phenotype(std::vector<TerminalSymbol>()) {
  //
}
