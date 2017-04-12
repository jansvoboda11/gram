#include <gram/util/number_generator/MinimalNumberGenerator.h>

using namespace gram;
using namespace std;

MinimalNumberGenerator::MinimalNumberGenerator(unsigned long max) : max(max) {
  // todo: make it possible to provide own seed
  random_device device;
  minstd_rand minimal(device());
  uniform_int_distribution<unsigned long> uniform(0, max);

  generator = minimal;
  distribution = uniform;
}

unsigned long MinimalNumberGenerator::generate() {
  return distribution(generator);
}

unsigned long MinimalNumberGenerator::getMax() {
  return max;
}
