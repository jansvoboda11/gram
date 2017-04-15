#ifndef GRAM_INDIVIDUAL_CODON_MUTATION
#define GRAM_INDIVIDUAL_CODON_MUTATION

#include <memory>

#include <gram/individual/mutation/Mutation.h>
#include <gram/util/bool_generator/BoolGenerator.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class CodonMutation : public Mutation {
 public:
  CodonMutation(std::unique_ptr<BoolGenerator> boolGenerator, std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(Genotype genotype);
 private:
  std::unique_ptr<BoolGenerator> boolGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_CODON_MUTATION
