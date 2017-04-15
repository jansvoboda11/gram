#include <gram/individual/crossover/OnePointCrossover.h>

using namespace gram;
using namespace std;

OnePointCrossover::OnePointCrossover(unique_ptr<NumberGenerator> numberGenerator)
    : numberGenerator(move(numberGenerator)) {
  //
}

Genotype OnePointCrossover::apply(const Genotype& first, const Genotype& second) {
  unsigned long smallerSize = min(first.size(), second.size());
  unsigned long point = numberGenerator->generate() % (smallerSize + 1);

  Genotype firstPart(first.begin(), first.begin() + point);
  Genotype secondPart(second.begin() + point, second.end());

  Genotype createdGenotype(firstPart);
  createdGenotype.insert(createdGenotype.end(), secondPart.begin(), secondPart.end());

  return createdGenotype;
}
