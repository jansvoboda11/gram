#ifndef GRAM_EVOLUTION_CROSSOVER_OPERATOR
#define GRAM_EVOLUTION_CROSSOVER_OPERATOR

#include <population/individual/Genotype.h>
#include <util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Crossover {
 public:
  Crossover(gram::util::NumberGenerator &generator);
  gram::population::individual::Genotype apply(gram::population::individual::Genotype first,
                                               gram::population::individual::Genotype second);
 private:
  gram::util::NumberGenerator &generator;
};
}
}

#endif // GRAM_EVOLUTION_CROSSOVER_OPERATOR
