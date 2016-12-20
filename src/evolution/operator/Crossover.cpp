#include <gram/evolution/operator/Crossover.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

Crossover::Crossover(NumberGenerator &generator) : generator(generator) {
  //
}

Genotype Crossover::apply(Genotype first, Genotype second) {
  unsigned long smallerSize = std::min(first.size(), second.size());
  unsigned long point = generator.generate() % (smallerSize + 1);

  Genotype firstPart(first.begin(), first.begin() + point);
  Genotype secondPart(second.begin() + point, second.end());

  Genotype createdGenotype(firstPart);
  createdGenotype.insert(createdGenotype.end(), secondPart.begin(), secondPart.end());

  return createdGenotype;
}
