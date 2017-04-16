#include <gram/individual/comparer/HighFitnessComparer.h>

using namespace gram;

bool HighFitnessComparer::isFirstFitter(const Individual& first, const Individual& second) const {
  return first.fitness() > first.fitness();
}
