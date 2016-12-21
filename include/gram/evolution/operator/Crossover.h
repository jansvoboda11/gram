#ifndef GRAM_EVOLUTION_OPERATOR_CROSSOVER
#define GRAM_EVOLUTION_OPERATOR_CROSSOVER

#include <memory>

#include <gram/individual/Genotype.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Crossover {
 public:
  Crossover(std::unique_ptr<gram::util::NumberGenerator> generator);
  virtual gram::individual::Genotype apply(gram::individual::Genotype first, gram::individual::Genotype second);
 private:
  std::unique_ptr<gram::util::NumberGenerator> generator;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR_CROSSOVER
