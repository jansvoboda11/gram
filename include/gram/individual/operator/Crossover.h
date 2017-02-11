#ifndef GRAM_INDIVIDUAL_CROSSOVER_OPERATOR
#define GRAM_INDIVIDUAL_CROSSOVER_OPERATOR

#include <gram/individual/Genotype.h>

namespace gram {
/**
 * Interface.
 */
class Crossover {
 public:
  virtual Genotype apply(const Genotype& first, const Genotype& second) const = 0;
};
}

#endif // GRAM_INDIVIDUAL_CROSSOVER_OPERATOR
