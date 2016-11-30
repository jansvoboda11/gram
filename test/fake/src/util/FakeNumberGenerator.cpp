#include <gram/fake/util/FakeNumberGenerator.h>

using namespace gram::fake::util;

FakeNumberGenerator::FakeNumberGenerator(std::initializer_list<int> numbers) : numbers(numbers), count(0) {
  //
}

int FakeNumberGenerator::generate() {
  int number = numbers[count];

  count = (count + 1) % numbers.size();

  return number;
}

std::vector<int> FakeNumberGenerator::generate(int count) {
  std::vector<int> numbers;

  for (int i = 0; i < count; i++) {
    numbers.push_back(generate());
  }

  return numbers;
}
