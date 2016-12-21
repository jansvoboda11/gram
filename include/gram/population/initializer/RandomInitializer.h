#ifndef GRAM_POPULATION_INITIALIZER_RANDOM
#define GRAM_POPULATION_INITIALIZER_RANDOM

#include <memory>

#include <gram/population/initializer/Initializer.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class RandomInitializer : public Initializer {
 public:
  RandomInitializer(std::unique_ptr<gram::util::NumberGenerator> generator,
                    std::shared_ptr<gram::language::Language> language,
                    int individualSize);
  Population initialize(int individualCount);
 private:
  std::unique_ptr<gram::util::NumberGenerator> generator;
  std::shared_ptr<gram::language::Language> language;
  int individualSize;
};
}
}

#endif // GRAM_POPULATION_INITIALIZER_RANDOM
