#ifndef GRAM_EVOLUTION_CROSSOVER_OPERATOR
#define GRAM_EVOLUTION_CROSSOVER_OPERATOR

#include "Operator.h"

namespace gram {
namespace evolution {
/**
 * Class.
 */
class CrossoverOperator : public Operator {
 public:
  CrossoverOperator(gram::population::individual::Genotype first,
                    gram::population::individual::Genotype second);
  gram::population::individual::Genotype apply();
 private:
  gram::population::individual::Genotype first;
  gram::population::individual::Genotype second;
};
}
}

#endif // GRAM_EVOLUTION_CROSSOVER_OPERATOR
