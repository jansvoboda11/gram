#include <util/FakeNumberGenerator.h>

using namespace gram::fake::util;

FakeNumberGenerator::FakeNumberGenerator(std::vector<int> numbers) : numbers(numbers), count(0) {
  //
}

int FakeNumberGenerator::generate() {
  int number = numbers[count];

  count = (count + 1) % numbers.size();

  return number;
}
