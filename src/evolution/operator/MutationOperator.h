#ifndef GRAM_EVOLUTION_MUTATION_OPERATOR
#define GRAM_EVOLUTION_MUTATION_OPERATOR

#include "Operator.h"

namespace gram {
namespace evolution {
/**
 * Class.
 */
class MutationOperator : public Operator {
 public:
  MutationOperator(gram::population::individual::Genotype genotype);
  gram::population::individual::Genotype apply();
 private:
  gram::population::individual::Genotype genotype;
};
}
}

#endif // GRAM_EVOLUTION_MUTATION_OPERATOR
