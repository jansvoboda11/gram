#ifndef GRAM_INDIVIDUAL_CROSSOVER
#define GRAM_INDIVIDUAL_CROSSOVER

#include "gram/individual/Genotype.h"

namespace gram {
/**
 * Interface.
 */
class Crossover {
 public:
  virtual Genotype apply(const Genotype& first, const Genotype& second) = 0;
};
}

#endif // GRAM_INDIVIDUAL_CROSSOVER
