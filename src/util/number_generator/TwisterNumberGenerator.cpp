#include <gram/util/number_generator/TwisterNumberGenerator.h>

using namespace gram::util;

TwisterNumberGenerator::TwisterNumberGenerator(unsigned long max) {
  std::random_device device;
  std::mt19937 twister(device());
  std::uniform_int_distribution<unsigned long> uniform(0, max);

  generator = twister;
  distribution = uniform;
}

unsigned long TwisterNumberGenerator::generate() {
  return distribution(generator);
}

std::vector<unsigned long> TwisterNumberGenerator::generateMany(unsigned long count) {
  std::vector<unsigned long> numbers;

  for (unsigned long i = 0; i < count; i++) {
    unsigned long number = generate();

    numbers.push_back(number);
  }

  return numbers;
}
