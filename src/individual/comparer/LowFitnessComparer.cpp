#include <gram/individual/comparer/LowFitnessComparer.h>

using namespace gram;

bool LowFitnessComparer::isFirstFitter(const Individual& first, const Individual& second) const {
  return first.fitness() < second.fitness();
}
