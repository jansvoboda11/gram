#include "MutationOperator.h"

using namespace gram::evolution;
using namespace gram::population::individual;

MutationOperator::MutationOperator(Genotype genotype) : genotype(genotype) {
  //
}

Genotype MutationOperator::apply() {
  return Genotype(std::vector<int>());
}
