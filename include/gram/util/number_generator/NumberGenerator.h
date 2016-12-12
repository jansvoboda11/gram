#ifndef GRAM_UTIL_NUMBER_GENERATOR
#define GRAM_UTIL_NUMBER_GENERATOR

namespace gram {
namespace util {
/**
 * Class.
 */
class NumberGenerator {
 public:
  virtual unsigned long generate() = 0;
  virtual std::vector<unsigned long> generate(int count) = 0;
};
}
}

#endif // GRAM_UTIL_NUMBER_GENERATOR
