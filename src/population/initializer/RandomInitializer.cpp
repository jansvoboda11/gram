#include "gram/population/initializer/RandomInitializer.h"

#include <algorithm>

#include "gram/error/NoIndividuals.h"
#include "gram/error/ZeroGenotypeLength.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
class Reproducer;
}

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator, unsigned long genotypeSize)
    : numberGenerator(move(numberGenerator)), genotypeSize(genotypeSize) {
  if (genotypeSize == 0) {
    throw ZeroGenotypeLength();
  }
}

Population RandomInitializer::initialize(unsigned long populationSize, shared_ptr<Reproducer> reproducer) const {
  if (populationSize == 0) {
    throw NoIndividuals();
  }

  Individuals individuals;
  individuals.reserve(populationSize);

  for (unsigned long i = 0; i < populationSize; i++) {
    Genotype genotype = numberGenerator->generateMany(genotypeSize);

    individuals.addIndividual(Individual(genotype));
  }

  return Population(individuals, reproducer, 0);
}
