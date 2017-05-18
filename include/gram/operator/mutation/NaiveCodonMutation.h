#ifndef GRAM_INDIVIDUAL_CODON_MUTATION
#define GRAM_INDIVIDUAL_CODON_MUTATION

#include <memory>

#include "gram/individual/Genotype.h"
#include "Mutation.h"
#include "gram/random/bool_generator/BoolGenerator.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class NaiveCodonMutation : public Mutation {
public:
  NaiveCodonMutation(std::unique_ptr<BoolGenerator> boolGenerator, std::unique_ptr<NumberGenerator> numberGenerator);
  Genotype apply(Genotype genotype);

private:
  std::unique_ptr<BoolGenerator> boolGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_CODON_MUTATION
