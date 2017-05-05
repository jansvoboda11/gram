#ifndef GRAM_POPULATION_REPRODUCER
#define GRAM_POPULATION_REPRODUCER

#include "gram/population/Individuals.h"

namespace gram {
/**
 * Interface.
 */
class Reproducer {
public:
  virtual ~Reproducer() = default;
  virtual Individuals reproduce(Individuals& individuals) = 0;
};
}

#endif // GRAM_POPULATION_REPRODUCER
