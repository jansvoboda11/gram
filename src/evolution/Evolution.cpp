#include <gram/evolution/Evolution.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;

Individual Evolution::run(int populationSize, int iterationCount) {
  Population population = initializer->initialize(populationSize);
  processor->process(population);

  for (int i = 0; i < iterationCount; i++) {
    if (population.bestIndividual()->getFitness() == 0) {
      break;
    }

    population = generator->generateSuccessor(population);

    processor->process(population);
  }

  return *population.bestIndividual();
}

void Evolution::setInitializer(Initializer *newInitializer) {
  initializer = newInitializer;
}

void Evolution::setProcessor(Processor *newProcessor) {
  processor = newProcessor;
}

void Evolution::setGenerator(Generator *newGenerator) {
  generator = newGenerator;
}
