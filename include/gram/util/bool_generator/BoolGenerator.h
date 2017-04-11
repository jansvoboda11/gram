#ifndef GRAM_UTIL_BOOL_GENERATOR
#define GRAM_UTIL_BOOL_GENERATOR

#include <gram/util/number_generator/NumberGenerator.h>

#include <memory>
#include <vector>

namespace gram {
/**
 * Abstract class.
 */
class BoolGenerator {
 public:
  BoolGenerator(std::unique_ptr<NumberGenerator> numberGenerator, double probability);
  virtual ~BoolGenerator() = default;
  virtual bool generate() const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
  double probability;
};
}

#endif // GRAM_UTIL_BOOL_GENERATOR
