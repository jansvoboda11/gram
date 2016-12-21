#ifndef GRAM_POPULATION_INITIALIZER_RANDOM
#define GRAM_POPULATION_INITIALIZER_RANDOM

#include <gram/population/initializer/Initializer.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class RandomInitializer : public Initializer {
 public:
  RandomInitializer(gram::util::NumberGenerator &generator, gram::language::Language &language, int individualSize);
  Population initialize(int individualCount);
 private:
  gram::util::NumberGenerator &generator;
  gram::language::Language &language;
  int individualSize;
};
}
}

#endif // GRAM_POPULATION_INITIALIZER_RANDOM
