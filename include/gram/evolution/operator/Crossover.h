#ifndef GRAM_EVOLUTION_OPERATOR_CROSSOVER
#define GRAM_EVOLUTION_OPERATOR_CROSSOVER

#include <gram/individual/Genotype.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Crossover {
 public:
  Crossover(gram::util::NumberGenerator &generator);
  virtual gram::individual::Genotype apply(gram::individual::Genotype first, gram::individual::Genotype second);
 private:
  gram::util::NumberGenerator &generator;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR_CROSSOVER
