#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator, unsigned long genotypeSize)
    : numberGenerator(move(numberGenerator)), genotypeSize(genotypeSize) {
  //
}

Population RandomInitializer::initialize(unsigned long populationSize, shared_ptr<Reproducer> reproducer) const {
  Individuals individuals;
  individuals.reserve(populationSize);

  for (unsigned long i = 0; i < populationSize; i++) {
    Genotype genotype = numberGenerator->generateMany(genotypeSize);

    individuals.addIndividual(Individual(genotype));
  }

  return Population(individuals, reproducer, 0);
}
