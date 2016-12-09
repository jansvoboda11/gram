#ifndef GRAM_POPULATION_INITIALIZER_RANDOM
#define GRAM_POPULATION_INITIALIZER_RANDOM

#include <gram/population/initializer/Initializer.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class RandomInitializer : public Initializer {
 public:
  RandomInitializer(gram::util::NumberGenerator &generator, int individualSize);
  Population initialize(int individualCount);
 private:
  gram::util::NumberGenerator &generator;
  int individualSize;
};
}
}

#endif // GRAM_POPULATION_INITIALIZER_RANDOM
