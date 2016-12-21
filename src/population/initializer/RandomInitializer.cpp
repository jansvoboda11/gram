#include <gram/population/initializer/RandomInitializer.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::util;

RandomInitializer::RandomInitializer(std::unique_ptr<NumberGenerator> generator, gram::language::Language &language, int individualSize)
    : generator(std::move(generator)), language(language), individualSize(individualSize) {
  //
}

Population RandomInitializer::initialize(int individualCount) {
  std::vector<std::shared_ptr<Individual>> individuals;

  for (int i = 0; i < individualCount; i++) {
    Genotype genotype = generator->generateMany(individualSize);

    auto individual = std::make_shared<Individual>(genotype, language);

    individuals.push_back(individual);
  }

  return Population(individuals);
}
