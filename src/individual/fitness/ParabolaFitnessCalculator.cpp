#include <gram/individual/fitness/ParabolaFitnessCalculator.h>

using namespace gram;

ParabolaFitnessCalculator::ParabolaFitnessCalculator(double width) : width(width) {
  //
}

double ParabolaFitnessCalculator::calculate(int desired, int actual) const {
  double base = (1 / width) * (actual - desired);

  return base * base;
}
