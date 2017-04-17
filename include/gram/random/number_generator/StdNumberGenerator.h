#ifndef GRAM_MINIMAL_RANDOM_NUMBER_GENERATOR
#define GRAM_MINIMAL_RANDOM_NUMBER_GENERATOR

#include <random>

#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Template class.
 */
template <typename T>
class StdNumberGenerator : public NumberGenerator {
 public:
  StdNumberGenerator<T>();
  StdNumberGenerator(unsigned long seed, unsigned long max);
  static StdNumberGenerator withSeed(unsigned long seed);
  static StdNumberGenerator withMax(unsigned long max);
  unsigned long generate();
  unsigned long getMax();
 private:
  T generator;
  std::uniform_int_distribution<unsigned long> distribution;
  unsigned long max;
};
}

template <typename T>
gram::StdNumberGenerator<T>::StdNumberGenerator() : max(std::numeric_limits<unsigned long>::max()) {
  std::random_device device;
  unsigned long seed = device();

  generator = T(seed);
  distribution = std::uniform_int_distribution<unsigned long>(0, max);
}

template <typename T>
gram::StdNumberGenerator<T>::StdNumberGenerator(unsigned long seed, unsigned long max) : max(max) {
  generator = T(seed);
  distribution = std::uniform_int_distribution<unsigned long>(0, max);
}

template <typename T>
gram::StdNumberGenerator<T> gram::StdNumberGenerator<T>::withSeed(unsigned long seed) {
  unsigned long max = std::numeric_limits<unsigned long>::max();

  return StdNumberGenerator(seed, max);
}

template <typename T>
gram::StdNumberGenerator<T> gram::StdNumberGenerator<T>::withMax(unsigned long max) {
  std::random_device device;
  unsigned long seed = device();

  return StdNumberGenerator(seed, max);
}

template <typename T>
unsigned long gram::StdNumberGenerator<T>::generate() {
  return distribution(generator);
}

template <typename T>
unsigned long gram::StdNumberGenerator<T>::getMax() {
  return max;
}

#endif // GRAM_MINIMAL_RANDOM_NUMBER_GENERATOR
