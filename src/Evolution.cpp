#include <gram/Evolution.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;

Evolution::Evolution(std::shared_ptr<Processor> processor) : processor(processor) {
  //
}

Individual Evolution::run(Population &population, int goal) {
  population.process(processor, goal);

  while (population.bestFitness() > 0.0) {
    population = population.successor();

    population.process(processor, goal);
  }

  return *population.bestIndividual();
}
