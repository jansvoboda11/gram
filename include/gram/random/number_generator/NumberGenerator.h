#ifndef GRAM_RANDOM_NUMBER_GENERATOR
#define GRAM_RANDOM_NUMBER_GENERATOR

#include <vector>

namespace gram {
/**
 * Abstract class.
 */
class NumberGenerator {
 public:
  virtual ~NumberGenerator() = default;
  virtual unsigned long generate() = 0;
  virtual std::vector<unsigned long> generateMany(unsigned long count);
  virtual unsigned long getMax() = 0;
};
}

#endif // GRAM_RANDOM_NUMBER_GENERATOR
