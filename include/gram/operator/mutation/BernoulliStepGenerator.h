#ifndef GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR
#define GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR

#include <memory>

#include "gram/random/number_generator/NumberGenerator.h"
#include "gram/util/Probability.h"

namespace gram {
/**
 * Class.
 */
class BernoulliStepGenerator {
public:
  BernoulliStepGenerator(Probability probability, std::unique_ptr<NumberGenerator> numberGenerator);
  virtual ~BernoulliStepGenerator() = default;
  virtual unsigned long generateStep();

private:
  Probability probability;
  std::unique_ptr<NumberGenerator> numberGenerator;
  double divisor;
};
}

#endif // GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR
