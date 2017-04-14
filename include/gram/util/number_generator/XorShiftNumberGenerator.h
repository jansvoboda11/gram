#ifndef GRAM_XOR_SHIFT_NUMBER_GENERATOR
#define GRAM_XOR_SHIFT_NUMBER_GENERATOR

#include <gram/util/number_generator/NumberGenerator.h>

#include <cstdint>

namespace gram {
/**
 * Class.
 */
class XorShiftNumberGenerator : public NumberGenerator {
 public:
  XorShiftNumberGenerator();
  unsigned long generate();
  unsigned long getMax();
 private:
  std::uint32_t state;
};
}

#endif // GRAM_XOR_SHIFT_NUMBER_GENERATOR
