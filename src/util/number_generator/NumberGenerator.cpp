#include <gram/util/number_generator/NumberGenerator.h>

using namespace gram;
using namespace std;

vector<unsigned long> NumberGenerator::generateMany(unsigned long count) {
  vector<unsigned long> numbers;
  numbers.reserve(count);

  for (unsigned long i = 0; i < count; i++) {
    unsigned long number = generate();

    numbers.push_back(number);
  }

  return numbers;
}
