#ifndef GRAM_MINIMAL_NUMBER_GENERATOR
#define GRAM_MINIMAL_NUMBER_GENERATOR

#include <gram/util/number_generator/NumberGenerator.h>

#include <random>

namespace gram {
/**
 * Class.
 */
class MinimalNumberGenerator : public NumberGenerator {
 public:
  MinimalNumberGenerator(unsigned long max = std::numeric_limits<unsigned long>::max());
  unsigned long generate();
  unsigned long getMax();
 private:
  std::minstd_rand generator;
  std::uniform_int_distribution<unsigned long> distribution;
  unsigned long max;
};
}

#endif // GRAM_MINIMAL_NUMBER_GENERATOR
