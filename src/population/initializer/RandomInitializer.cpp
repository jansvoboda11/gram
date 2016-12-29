#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator,
                                     shared_ptr<Language> language,
                                     unsigned long size)
    : numberGenerator(move(numberGenerator)), language(language), size(size) {
  //
}

Population RandomInitializer::initialize(unsigned long count, shared_ptr<Reproduction> reproduction) const {
  Individuals individuals;

  for (unsigned long i = 0; i < count; i++) {
    Genotype genotype = numberGenerator->generateMany(size);

    individuals.addIndividual(make_shared<Individual>(genotype, language));
  }

  return Population(individuals, reproduction);
}
