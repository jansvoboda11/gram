#ifndef GRAM_CROSSOVER
#define GRAM_CROSSOVER

#include "gram/individual/Genotype.h"

namespace gram {
/**
 * Interface.
 */
class Crossover {
public:
  virtual ~Crossover() = default;
  virtual Genotype apply(const Genotype& first, const Genotype& second) = 0;
};
}

#endif
