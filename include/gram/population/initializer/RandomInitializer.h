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
                    unsigned long size);
  Population initialize(unsigned long count, std::shared_ptr<Reproduction> reproduction) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
  std::shared_ptr<Language> language;
  unsigned long size;
};
}

#endif // GRAM_POPULATION_RANDOM_INITIALIZER
