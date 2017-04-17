#ifndef GRAM_POPULATION_RANDOM_INITIALIZER
#define GRAM_POPULATION_RANDOM_INITIALIZER

#include <memory>

#include "gram/population/Population.h"
#include "gram/population/initializer/Initializer.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
class Reproducer;
/**
 * Class.
 */
class RandomInitializer : public Initializer {
 public:
  RandomInitializer(std::unique_ptr<NumberGenerator> numberGenerator, unsigned long genotypeSize);
  Population initialize(unsigned long populationSize, std::shared_ptr<Reproducer> reproducer) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
  unsigned long genotypeSize;
};
}

#endif // GRAM_POPULATION_RANDOM_INITIALIZER
