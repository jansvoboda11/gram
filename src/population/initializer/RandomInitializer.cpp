#include <gram/population/initializer/RandomInitializer.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::language;
using namespace gram::util;

RandomInitializer::RandomInitializer(std::unique_ptr<NumberGenerator> numberGenerator, std::shared_ptr<Language> language, unsigned long individualSize)
    : numberGenerator(std::move(numberGenerator)), language(language), individualSize(individualSize) {
  //
}

Population RandomInitializer::initialize(unsigned long individualCount, std::shared_ptr<Generator> generator) {
  std::vector<std::shared_ptr<Individual>> individuals;

  for (unsigned long i = 0; i < individualCount; i++) {
    Genotype genotype = numberGenerator->generateMany(individualSize);

    auto individual = std::make_shared<Individual>(genotype, language);

    individuals.push_back(individual);
  }

  return Population(individuals, generator);
}
