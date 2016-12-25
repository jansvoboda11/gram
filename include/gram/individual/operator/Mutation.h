#ifndef GRAM_INDIVIDUAL_MUTATION_OPERATOR
#define GRAM_INDIVIDUAL_MUTATION_OPERATOR

#include <memory>

#include <gram/individual/Genotype.h>
#include <gram/util/bool_generator/BoolGenerator.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class Mutation {
 public:
  Mutation(std::unique_ptr<BoolGenerator> boolGenerator, std::unique_ptr<NumberGenerator> numberGenerator);
  virtual Genotype apply(Genotype genotype);
 private:
  std::unique_ptr<BoolGenerator> boolGenerator;
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_MUTATION_OPERATOR
