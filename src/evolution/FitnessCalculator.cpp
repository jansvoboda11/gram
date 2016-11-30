#include <gram/evolution/FitnessCalculator.h>

using namespace gram::evolution;

FitnessCalculator::FitnessCalculator(double width) : width(width) {
  //
}

double FitnessCalculator::calculate(int desired, int actual) {
  double base = (1 / width) * (actual + desired);

  return base * base;
}
