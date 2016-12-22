#ifndef GRAM_UTIL_NUMBER_GENERATOR
#define GRAM_UTIL_NUMBER_GENERATOR

namespace gram {
namespace util {
/**
 * Interface.
 */
class NumberGenerator {
 public:
  virtual ~NumberGenerator() = default;
  virtual unsigned long generate() = 0;
  virtual std::vector<unsigned long> generateMany(unsigned long count) = 0;
};
}
}

#endif // GRAM_UTIL_NUMBER_GENERATOR
