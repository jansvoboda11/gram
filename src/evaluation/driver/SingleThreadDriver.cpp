#include "gram/evaluation/driver/SingleThreadDriver.h"

#include <algorithm>
#include <limits>

#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"
#include "gram/error/WrappingLimitExceeded.h"

using namespace gram;
using namespace std;

SingleThreadDriver::SingleThreadDriver(unique_ptr<Mapper> mapper, unique_ptr<Evaluator> evaluator, bool isMin) 
    : mapper(move(mapper)), evaluator(move(evaluator)), searchMin(isMin)  {
  //
}

void SingleThreadDriver::evaluate(Individuals& individuals) {
  for (auto& individual : individuals) {
    evaluateOne(individual);
  }
}

void SingleThreadDriver::evaluateOne(Individual& individual) {
  Fitness fitness;

  try{

    Phenotype phenotype = individual.serialize(*mapper);

    fitness = evaluator->evaluate(phenotype);
  }
  catch (WrappingLimitExceeded& e){

     fitness = searchMin ? numeric_limits<Fitness>::max() : numeric_limits<Fitness>::min();
  }

  individual.assignFitness(fitness);
}
