#include <gram/fake/util/FakeBoolGenerator.h>

using namespace gram::fake::util;

FakeBoolGenerator::FakeBoolGenerator(std::initializer_list<bool> booleans) : booleans(booleans), count(0) {
  //
}

bool FakeBoolGenerator::generate() {
  bool number = booleans[count];

  count = (count + 1) % booleans.size();

  return number;
}

std::vector<bool> FakeBoolGenerator::generate(int count) {
  std::vector<bool> booleans;

  for (int i = 0; i < count; i++) {
    booleans.push_back(generate());
  }

  return booleans;
}
