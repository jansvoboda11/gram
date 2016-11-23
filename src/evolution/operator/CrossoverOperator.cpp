#include "CrossoverOperator.h"

using namespace gram::evolution;
using namespace gram::population::individual;

CrossoverOperator::CrossoverOperator(Genotype first, Genotype second)
    : first(first), second(second) {
  //
}

Genotype CrossoverOperator::apply() {
  return Genotype(std::vector<int>());
}
