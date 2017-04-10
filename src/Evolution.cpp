#include <gram/Evolution.h>

using namespace gram;
using namespace std;

Evolution::Evolution(unique_ptr<Evaluator> evaluator, unique_ptr<Logger> logger)
    : evaluator(move(evaluator)), logger(move(logger)) {
  //
}

Individual Evolution::run(Population& population) const {
  population.evaluate(*evaluator);

  logger->log(population);

  while (population.bestFitness() > 0.0) {
    population = population.reproduce();

    population.evaluate(*evaluator);

    logger->log(population);
  }

  return population.bestIndividual();
}
