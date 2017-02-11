#ifndef GRAM_UTIL_NUMBER_GENERATOR_TWISTER
#define GRAM_UTIL_NUMBER_GENERATOR_TWISTER

#include <random>

#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class TwisterNumberGenerator : public NumberGenerator {
 public:
  TwisterNumberGenerator(unsigned long max = std::numeric_limits<unsigned long>::max());
  unsigned long generate();
  std::vector<unsigned long> generateMany(unsigned long count);
 private:
  std::mt19937 generator;
  std::uniform_int_distribution<unsigned long> distribution;
};
}

#endif // GRAM_UTIL_NUMBER_GENERATOR_TWISTER
