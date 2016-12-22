#ifndef GRAM_POPULATION_INITIALIZER
#define GRAM_POPULATION_INITIALIZER

#include <gram/population/Population.h>
#include <gram/language/Language.h>

namespace gram {
namespace population {
/**
 * Interface.
 */
class Initializer {
 public:
  virtual Population initialize(unsigned long individualCount, std::shared_ptr<Generator> generator) = 0;
};
}
}

#endif // GRAM_POPULATION_INITIALIZER
