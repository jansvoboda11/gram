#ifndef GRAM_INDIVIDUAL_FAST_CODON_MUTATION
#define GRAM_INDIVIDUAL_FAST_CODON_MUTATION

#include <memory>

#include "gram/individual/Genotype.h"
#include "gram/individual/mutation/BernoulliDistributionStepGenerator.h"
#include "gram/individual/mutation/Mutation.h"
#include "gram/random/bool_generator/BoolGenerator.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class FastCodonMutation : public Mutation {
 public:
  FastCodonMutation(std::unique_ptr<BernoulliDistributionStepGenerator> stepGenerator,
                    std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(Genotype genotype);
 private:
  std::unique_ptr<BernoulliDistributionStepGenerator> stepGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
  unsigned long step;
};
}

#endif // GRAM_INDIVIDUAL_FAST_CODON_MUTATION
