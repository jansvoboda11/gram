#include <gram/population/initializer/RandomInitializer.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::util;

RandomInitializer::RandomInitializer(NumberGenerator &generator, int individualSize)
    : generator(generator), individualSize(individualSize) {
  //
}

Population RandomInitializer::initialize(int individualCount) {
  std::vector<Individual> individuals;

  for (int i = 0; i < individualCount; i++) {
    Genotype genotype = generator.generate(individualSize);

    Individual individual(genotype);

    individuals.push_back(individual);
  }

  return Population(individuals);
}
