#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator,
                                     shared_ptr<Language> language,
                                     unsigned long size)
    : numberGenerator(move(numberGenerator)), language(language), size(size) {
  //
}

Population RandomInitializer::initialize(unsigned long count, shared_ptr<Generator> generator) const {
  vector<shared_ptr<Individual>> individuals;

  for (unsigned long i = 0; i < count; i++) {
    Genotype genotype = numberGenerator->generateMany(size);

    auto individual = make_shared<Individual>(genotype, language);

    individuals.push_back(individual);
  }

  return Population(individuals, generator);
}
