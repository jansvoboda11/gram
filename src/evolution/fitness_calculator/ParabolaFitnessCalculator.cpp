#include <gram/individual/fitness/ParabolaFitnessCalculator.h>

using namespace gram::evolution;

ParabolaFitnessCalculator::ParabolaFitnessCalculator(double width) : width(width) {
  //
}

double ParabolaFitnessCalculator::calculate(int desired, int actual) {
  double base = (1 / width) * (actual - desired);

  return base * base;
}
