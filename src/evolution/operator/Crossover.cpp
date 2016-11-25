#include <evolution/operator/Crossover.h>

using namespace gram::evolution;
using namespace gram::population::individual;

Crossover::Crossover(gram::util::NumberGenerator &generator) : generator(generator) {
  //
}

Genotype Crossover::apply(Genotype first, Genotype second) {
  unsigned long smallerSize = std::min(first.size(), second.size());
  unsigned long point = generator.generate() % (smallerSize + 1);

  std::vector<int> firstGenes = first.genes();
  std::vector<int> secondGenes = second.genes();

  std::vector<int> firstPart(firstGenes.begin(), firstGenes.begin() + point);
  std::vector<int> secondPart(secondGenes.begin() + point, secondGenes.end());

  std::vector<int> newGenes(firstPart);
  newGenes.insert(newGenes.end(), secondPart.begin(), secondPart.end());

  return Genotype(newGenes);
}
