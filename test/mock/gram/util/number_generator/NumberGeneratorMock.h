#ifndef GRAM_UTIL_NUMBER_GENERATOR_MOCK
#define GRAM_UTIL_NUMBER_GENERATOR_MOCK

#include <gmock/gmock.h>

#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace util {
/**
 * Mock.
 */
class NumberGeneratorMock : public NumberGenerator {
 public:
  MOCK_METHOD0(generate, unsigned long());
  MOCK_METHOD1(generate, std::vector<unsigned long>(int count));
};
}
}

#endif // GRAM_UTIL_NUMBER_GENERATOR_MOCK
