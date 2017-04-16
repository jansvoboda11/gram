#include <gram/util/Probability.h>

#include <gram/error/InvalidProbability.h>

using namespace gram;

Probability::Probability(double value) : value(value) {
  if (value < 0.0 || value > 1.0) {
    throw InvalidProbability();
  }
}

double Probability::getValue() const {
  return value;
}
