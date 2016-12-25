#include <gram/individual/operator/Crossover.h>

using namespace gram;
using namespace std;

Crossover::Crossover(unique_ptr<NumberGenerator> generator) : generator(move(generator)) {
  //
}

Genotype Crossover::apply(Genotype first, Genotype second) {
  unsigned long smallerSize = min(first.size(), second.size());
  unsigned long point = generator->generate() % (smallerSize + 1);

  Genotype firstPart(first.begin(), first.begin() + point);
  Genotype secondPart(second.begin() + point, second.end());

  Genotype createdGenotype(firstPart);
  createdGenotype.insert(createdGenotype.end(), secondPart.begin(), secondPart.end());

  return createdGenotype;
}
