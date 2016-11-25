#ifndef GRAM_EVOLUTION_OPERATOR
#define GRAM_EVOLUTION_OPERATOR

#include <population/individual/Genotype.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Operator {
 public:
  virtual population::individual::Genotype apply() = 0;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR
