#include "gram/Evolution.h"

#include <algorithm>

#include "gram/evaluation/driver/EvaluationDriver.h"
#include "gram/population/Population.h"
#include "gram/util/logger/Logger.h"

using namespace gram;
using namespace std;

Evolution::Evolution(unique_ptr<EvaluationDriver> evaluationDriver, unique_ptr<Logger> logger)
    : evaluationDriver(move(evaluationDriver)), logger(move(logger)) {
  //
}

Population Evolution::run(Population& population, function<bool(Population&)>& successCondition) const {
  evaluationDriver->evaluate(population);

  while (!successCondition(population)) {
    logger->logProgress(population);

    population = population.reproduce();

    evaluationDriver->evaluate(population);
  }

  logger->logResult(population);

  return population;
}
