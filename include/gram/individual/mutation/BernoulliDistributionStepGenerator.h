#ifndef GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR
#define GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR

#include <gram/random/number_generator/NumberGenerator.h>
#include <gram/util/Probability.h>

#include <memory>

namespace gram {
/**
 * Class.
 */
class BernoulliDistributionStepGenerator {
 public:
  BernoulliDistributionStepGenerator(Probability probability, std::unique_ptr<NumberGenerator> numberGenerator);
  virtual ~BernoulliDistributionStepGenerator() = default;
  virtual unsigned long generateStep();
 private:
  Probability probability;
  std::unique_ptr<NumberGenerator> numberGenerator;
  double divisor;
};
}

#endif // GRAM_INDIVIDUAL_BERNOULLI_DISTRIBUTION_STEP_GENERATOR
