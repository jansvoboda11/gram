#ifndef GRAM_INDIVIDUAL_MOCK
#define GRAM_INDIVIDUAL_MOCK

#include <gmock/gmock.h>

#include <gram/individual/Individual.h>

namespace gram {
namespace individual {
/**
 * Mock.
 */
class IndividualMock : public Individual {
 public:
  IndividualMock() : Individual(Genotype{}) {};
  MOCK_METHOD0(getFitness, double());
};
}
}

#endif // GRAM_INDIVIDUAL_MOCK
