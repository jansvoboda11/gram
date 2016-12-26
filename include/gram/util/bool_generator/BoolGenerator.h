#ifndef GRAM_UTIL_BOOL_GENERATOR
#define GRAM_UTIL_BOOL_GENERATOR

#include <vector>

namespace gram {
/**
 * Interface.
 */
class BoolGenerator {
 public:
  virtual ~BoolGenerator() = default;
  virtual bool generate() const = 0;
  virtual std::vector<bool> generateMany(unsigned long count) const = 0;
};
}

#endif // GRAM_UTIL_BOOL_GENERATOR
