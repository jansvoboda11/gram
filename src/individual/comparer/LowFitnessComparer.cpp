#include "gram/individual/comparer/LowFitnessComparer.h"

using namespace gram;

bool LowFitnessComparer::isFirstFitter(const Individual& first, const Individual& second) const {
  if (!first.hasFitnessCalculated()) {
    return false;
  }

  if (!second.hasFitnessCalculated()) {
    return true;
  }

  return first.fitness() < second.fitness();
}
