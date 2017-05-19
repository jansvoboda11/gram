#ifndef GRAM_REPRODUCER
#define GRAM_REPRODUCER

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

#endif
