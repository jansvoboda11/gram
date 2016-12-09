#ifndef GRAM_FAKE_BOOL_GENERATOR
#define GRAM_FAKE_BOOL_GENERATOR

#include <vector>

#include <gram/util/BoolGenerator.h>

namespace gram {
namespace fake {
namespace util {
/**
 * Class.
 */
class FakeBoolGenerator : public gram::util::BoolGenerator {
 public:
  FakeBoolGenerator();
  FakeBoolGenerator(std::initializer_list<bool> booleans);
  bool generate();
  std::vector<bool> generate(int count);
 private:
  std::vector<bool> booleans;
  unsigned long count;
};
}
}
}

#endif // GRAM_FAKE_BOOL_GENERATOR
