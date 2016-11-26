#ifndef GRAM_UTIL_NUMBER_GENERATOR
#define GRAM_UTIL_NUMBER_GENERATOR

namespace gram {
namespace util {
/**
 * Class.
 */
class NumberGenerator {
 public:
  virtual int generate() = 0;
  virtual std::vector<int> generate(int count) = 0;
};
}
}

#endif // GRAM_UTIL_NUMBER_GENERATOR
