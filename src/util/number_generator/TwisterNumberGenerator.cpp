#include <gram/util/number_generator/TwisterNumberGenerator.h>

using namespace gram;
using namespace std;

TwisterNumberGenerator::TwisterNumberGenerator(unsigned long max) {
  // todo: make it possible to provide own seed
  random_device device;
  mt19937 twister(device());
  uniform_int_distribution<unsigned long> uniform(0, max);

  generator = twister;
  distribution = uniform;
}

unsigned long TwisterNumberGenerator::generate() {
  return distribution(generator);
}

unsigned long TwisterNumberGenerator::getMax() {
  return max;
}
