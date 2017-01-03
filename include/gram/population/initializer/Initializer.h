#ifndef GRAM_POPULATION_INITIALIZER
#define GRAM_POPULATION_INITIALIZER

#include <gram/population/Population.h>

namespace gram {
/**
 * Interface.
 */
class Initializer {
 public:
  virtual Population initialize(unsigned long count, std::shared_ptr<Reproducer> reproducer) const = 0;
};
}

#endif // GRAM_POPULATION_INITIALIZER
