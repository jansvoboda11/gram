#include <gram/population/Initializer.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::util;

Initializer::Initializer(NumberGenerator &generator, int individualSize)
    : generator(generator), individualSize(individualSize) {
  //
}

Population Initializer::initialize(int individualCount) {
  std::vector<Individual> individuals;

  for (int i = 0; i < individualCount; i++) {
    Genotype genotype = generator.generate(individualSize);

    Individual individual(genotype);

    individuals.push_back(individual);
  }

  return Population(individuals);
}
