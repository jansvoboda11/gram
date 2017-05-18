#include "gram/evaluation/driver/SingleThreadDriver.h"

#include <algorithm>

#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"

using namespace gram;
using namespace std;

SingleThreadDriver::SingleThreadDriver(unique_ptr<Mapper> mapper, unique_ptr<Evaluator> evaluator) 
    : mapper(move(mapper)), evaluator(move(evaluator)) {
  //
}

void SingleThreadDriver::evaluate(Individuals& individuals) {
  for (auto& individual : individuals) {
    evaluateOne(individual);
  }
}

void SingleThreadDriver::evaluateOne(Individual& individual) {
  Phenotype phenotype = individual.serialize(*mapper);

  Fitness fitness = evaluator->evaluate(phenotype);

  individual.assignFitness(fitness);
}
