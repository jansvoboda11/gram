#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator, unsigned long size)
    : numberGenerator(move(numberGenerator)), size(size) {
  //
}

Population RandomInitializer::initialize(unsigned long count, shared_ptr<Reproducer> reproducer) const {
  Individuals individuals;
  individuals.reserve(count);

  for (unsigned long i = 0; i < count; i++) {
    Genotype genotype = numberGenerator->generateMany(size);

    individuals.addIndividual(Individual(genotype));
  }

  return Population(individuals, reproducer, 0);
}
