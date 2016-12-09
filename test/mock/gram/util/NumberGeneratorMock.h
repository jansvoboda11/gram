#ifndef GRAM_UTIL_NUMBER_GENERATOR_MOCK
#define GRAM_UTIL_NUMBER_GENERATOR_MOCK

#include <gmock/gmock.h>

#include <gram/util/NumberGenerator.h>

namespace gram {
namespace util {
/**
 * Mock.
 */
class NumberGeneratorMock : public NumberGenerator {
 public:
  MOCK_METHOD0(generate, int());
  MOCK_METHOD1(generate, std::vector<int>(int count));
};
}
}

#endif // GRAM_UTIL_NUMBER_GENERATOR_MOCK
