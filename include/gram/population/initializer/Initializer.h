#ifndef GRAM_INITIALIZER
#define GRAM_INITIALIZER

#include "gram/population/Population.h"

namespace gram {
/**
 * Interface.
 */
class Initializer {
public:
  virtual Population initialize(unsigned long count, std::unique_ptr<Reproducer> reproducer) const = 0;
};
}

#endif
