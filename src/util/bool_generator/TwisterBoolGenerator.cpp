#include <gram/util/bool_generator/TwisterBoolGenerator.h>

#include <gram/util/number_generator/TwisterNumberGenerator.h>

using namespace gram;
using namespace std;

TwisterBoolGenerator::TwisterBoolGenerator(double probability)
    : probability(probability), max(numeric_limits<unsigned long>::max()) {
  generator = make_unique<TwisterNumberGenerator>(max);
}

bool TwisterBoolGenerator::generate() const {
  unsigned long number = generator->generate();

  return number <= probability * max;
}

vector<bool> TwisterBoolGenerator::generateMany(unsigned long count) const {
  vector<bool> values;

  for (unsigned long i = 0; i < count; i++) {
    values.push_back(generate());
  }

  return values;
}
