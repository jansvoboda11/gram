#include <gram/util/bool_generator/TwisterBoolGenerator.h>
#include <gram/util/number_generator/TwisterNumberGenerator.h>

using namespace gram::util;

TwisterBoolGenerator::TwisterBoolGenerator(double probability)
    : probability(probability), max(std::numeric_limits<unsigned long>::max()) {
  generator = std::make_unique<TwisterNumberGenerator>(max);
}

bool TwisterBoolGenerator::generate() {
  unsigned long number = generator->generate();

  return number <= probability * max;
}

std::vector<bool> TwisterBoolGenerator::generateMany(int count) {
  std::vector<bool> values;

  for (int i = 0; i < count; i++) {
    values.push_back(generate());
  }

  return values;
}
