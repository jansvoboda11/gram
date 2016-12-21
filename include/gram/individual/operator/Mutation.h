#ifndef GRAM_EVOLUTION_OPERATOR_MUTATION
#define GRAM_EVOLUTION_OPERATOR_MUTATION

#include <memory>

#include <gram/individual/Genotype.h>
#include <gram/util/bool_generator/BoolGenerator.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Mutation {
 public:
  Mutation(std::unique_ptr<gram::util::BoolGenerator> boolGenerator,
           std::unique_ptr<gram::util::NumberGenerator> numberGenerator);
  virtual gram::individual::Genotype apply(gram::individual::Genotype genotype);
 private:
  std::unique_ptr<gram::util::BoolGenerator> boolGenerator;
  std::unique_ptr<gram::util::NumberGenerator> numberGenerator;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR_MUTATION
