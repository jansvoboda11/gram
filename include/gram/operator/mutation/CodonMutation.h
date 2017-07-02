#ifndef GRAM_CODON_MUTATION
#define GRAM_CODON_MUTATION

#include <memory>

#include "gram/individual/Genotype.h"
#include "gram/operator/mutation/BernoulliStepGenerator.h"
#include "gram/operator/mutation/Mutation.h"
#include "gram/random/bool_generator/BoolGenerator.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class CodonMutation : public Mutation {
public:
  CodonMutation(std::unique_ptr<BernoulliStepGenerator> stepGenerator,
                std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(Genotype genotype) override;

private:
  std::unique_ptr<BernoulliStepGenerator> stepGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
  unsigned long step;
};
}

#endif
