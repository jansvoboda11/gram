#include <gram/individual/operator/InverseOnePointCrossover.h>

using namespace gram;
using namespace std;

InverseOnePointCrossover::InverseOnePointCrossover(unique_ptr<NumberGenerator> numberGenerator)
    : numberGenerator(move(numberGenerator)) {
  //
}

Genotype InverseOnePointCrossover::apply(const Genotype& first, const Genotype& second) const {
  unsigned long biggerSize = max(first.size(), second.size());
  unsigned long point = numberGenerator->generate() % (biggerSize + 1);

  Genotype firstPart(first.begin(), first.begin() + min(first.size(), point));
  Genotype secondPart(second.begin(), second.begin() + min(second.size(), point));

  Genotype createdGenotype(firstPart);
  createdGenotype.insert(createdGenotype.end(), secondPart.begin(), secondPart.end());

  return createdGenotype;
}
