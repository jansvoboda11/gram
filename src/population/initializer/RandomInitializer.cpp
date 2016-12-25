#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator, shared_ptr<Language> language, unsigned long individualSize)
    : numberGenerator(move(numberGenerator)), language(language), individualSize(individualSize) {
  //
}

Population RandomInitializer::initialize(unsigned long individualCount, shared_ptr<Generator> generator) {
  vector<shared_ptr<Individual>> individuals;

  for (unsigned long i = 0; i < individualCount; i++) {
    Genotype genotype = numberGenerator->generateMany(individualSize);

    auto individual = make_shared<Individual>(genotype, language);

    individuals.push_back(individual);
  }

  return Population(individuals, generator);
}
