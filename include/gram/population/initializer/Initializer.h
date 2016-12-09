#ifndef GRAM_POPULATION_INITIALIZER
#define GRAM_POPULATION_INITIALIZER

#include <gram/population/Population.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Initializer {
 public:
  virtual Population initialize(int individualCount) = 0;
};
}
}

#endif // GRAM_POPULATION_INITIALIZER
