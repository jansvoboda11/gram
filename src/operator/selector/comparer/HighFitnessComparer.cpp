#include "gram/operator/selector/comparer/HighFitnessComparer.h"

using namespace gram;

bool HighFitnessComparer::isFirstFitter(const Individual& first, const Individual& second) const {
  if (!first.hasFitnessCalculated()) {
    return false;
  }

  if (!second.hasFitnessCalculated()) {
    return true;
  }

  return first.fitness() > second.fitness();
}
