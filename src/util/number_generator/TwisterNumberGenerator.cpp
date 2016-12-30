#include <gram/util/number_generator/TwisterNumberGenerator.h>

using namespace gram;
using namespace std;

TwisterNumberGenerator::TwisterNumberGenerator(unsigned long max) {
  random_device device;
  mt19937 twister(device());
  uniform_int_distribution<unsigned long> uniform(0, max);

  generator = twister;
  distribution = uniform;
}

unsigned long TwisterNumberGenerator::generate() {
  return distribution(generator);
}

vector<unsigned long> TwisterNumberGenerator::generateMany(unsigned long count) {
  vector<unsigned long> numbers;
  numbers.reserve(count);

  for (unsigned long i = 0; i < count; i++) {
    unsigned long number = generate();

    numbers.push_back(number);
  }

  return numbers;
}
