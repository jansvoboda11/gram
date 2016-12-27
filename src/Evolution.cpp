#include <gram/Evolution.h>

using namespace gram;
using namespace std;

Evolution::Evolution(unique_ptr<Processor> processor) : processor(move(processor)) {
  //
}

Individual Evolution::run(Population &population, int goal) const {
  population.process(*processor, goal);

  while (population.bestFitness() > 0.0) {
    population = population.successor();

    population.process(*processor, goal);
  }

  return population.bestIndividual();
}
