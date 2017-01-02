#include <gram/Evolution.h>

using namespace gram;
using namespace std;

Evolution::Evolution(unique_ptr<Evaluator> evaluator) : evaluator(move(evaluator)) {
  //
}

Individual Evolution::run(Population& population) const {
  population.evaluate(*evaluator);

  while (population.bestFitness() > 0.0) {
    population = population.reproduce();

    population.evaluate(*evaluator);
  }

  return population.bestIndividual();
}
