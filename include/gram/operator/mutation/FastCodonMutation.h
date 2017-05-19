#ifndef GRAM_FAST_CODON_MUTATION
#define GRAM_FAST_CODON_MUTATION

#include <memory>

#include "gram/individual/Genotype.h"
#include "BernoulliStepGenerator.h"
#include "Mutation.h"
#include "gram/random/bool_generator/BoolGenerator.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class FastCodonMutation : public Mutation {
public:
  FastCodonMutation(std::unique_ptr<BernoulliStepGenerator> stepGenerator,
                    std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(Genotype genotype) override;

private:
  std::unique_ptr<BernoulliStepGenerator> stepGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
  unsigned long step;
};
}

#endif
