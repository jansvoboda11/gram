#ifndef GRAM_FAKE_NUMBER_GENERATOR
#define GRAM_FAKE_NUMBER_GENERATOR

#include <vector>

#include <util/NumberGenerator.h>

namespace gram {
namespace fake {
namespace util {
/**
 * Class.
 */
class FakeNumberGenerator : public gram::util::NumberGenerator {
 public:
  FakeNumberGenerator(std::initializer_list<int> numbers);
  int generate();
  std::vector<int> generate(int count);
 private:
  std::vector<int> numbers;
  unsigned long count;
};
}
}
}

#endif // GRAM_FAKE_NUMBER_GENERATOR
