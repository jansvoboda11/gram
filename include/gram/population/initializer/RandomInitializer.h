#ifndef GRAM_POPULATION_RANDOM_INITIALIZER
#define GRAM_POPULATION_RANDOM_INITIALIZER

#include <memory>

#include <gram/population/initializer/Initializer.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class RandomInitializer : public Initializer {
 public:
  RandomInitializer(std::unique_ptr<NumberGenerator> numberGenerator,
                    std::shared_ptr<Language> language,
                    unsigned long individualSize);
  Population initialize(unsigned long individualCount, std::shared_ptr<Generator> generator) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
  std::shared_ptr<Language> language;
  unsigned long individualSize;
};
}

#endif // GRAM_POPULATION_RANDOM_INITIALIZER
