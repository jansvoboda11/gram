#ifndef GRAM_UTIL_BOOL_GENERATOR_MOCK
#define GRAM_UTIL_BOOL_GENERATOR_MOCK

#include <gmock/gmock.h>

#include <gram/util/BoolGenerator.h>

namespace gram {
namespace util {
/**
 * Mock.
 */
class BoolGeneratorMock : public BoolGenerator {
 public:
  MOCK_METHOD0(generate, bool());
  MOCK_METHOD1(generate, std::vector<bool>(int count));
};
}
}

#endif // GRAM_UTIL_BOOL_GENERATOR_MOCK
