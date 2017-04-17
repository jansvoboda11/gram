#include "gram/individual/mutation/BernoulliDistributionStepGenerator.h"

#include <algorithm>
#include <cmath>
#include <limits>

using namespace gram;
using namespace std;

BernoulliDistributionStepGenerator::BernoulliDistributionStepGenerator(Probability probability,
                                                                       unique_ptr<NumberGenerator> numberGenerator)
    : probability(probability), numberGenerator(move(numberGenerator)), divisor(log(1 - probability.getValue())) {
  //
}

unsigned long BernoulliDistributionStepGenerator::generateStep() {
  double random = static_cast<double>(numberGenerator->generate()) / static_cast<double>(numberGenerator->getMax());

  double dividend = log(1.0 - random);

  double result = floor(dividend / divisor);

  unsigned long maxInt = numeric_limits<unsigned long>::max();

  if (result > static_cast<double>(maxInt)) {
    return maxInt;
  }

  return static_cast<unsigned long>(result);
}
