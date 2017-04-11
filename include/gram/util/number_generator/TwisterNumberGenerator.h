#ifndef GRAM_UTIL_NUMBER_GENERATOR_TWISTER
#define GRAM_UTIL_NUMBER_GENERATOR_TWISTER

#include <gram/util/number_generator/NumberGenerator.h>

#include <random>

namespace gram {
/**
 * Class.
 */
class TwisterNumberGenerator : public NumberGenerator {
 public:
  TwisterNumberGenerator(unsigned long max = std::numeric_limits<unsigned long>::max());
  unsigned long generate();
  unsigned long getMax();
 private:
  std::mt19937 generator;
  std::uniform_int_distribution<unsigned long> distribution;
  unsigned long max;
};
}

#endif // GRAM_UTIL_NUMBER_GENERATOR_TWISTER
