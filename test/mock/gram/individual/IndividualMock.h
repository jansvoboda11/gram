#ifndef GRAM_INDIVIDUAL_MOCK
#define GRAM_INDIVIDUAL_MOCK

#include <gmock/gmock.h>

#include <gram/individual/Individual.h>
#include <gram/language/Language.h>

namespace gram {
namespace individual {
/**
 * Mock.
 */
class IndividualMock : public Individual {
 public:
  IndividualMock(Genotype genotype, const gram::language::Language &language) : Individual(genotype, language) {};
  MOCK_METHOD0(getFitness, double());
};
}
}

#endif // GRAM_INDIVIDUAL_MOCK
