#include <evolution/operator/Crossover.h>

using namespace gram::evolution;
using namespace gram::population::individual;

Crossover::Crossover(gram::util::NumberGenerator &generator) : generator(generator) {
  //
}

Genotype Crossover::apply(Genotype first, Genotype second) {
  return Genotype(std::vector<int>());
}
