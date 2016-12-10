#ifndef GRAM_EVOLUTION_INDIVIDUAL_SELECTOR_MOCK
#define GRAM_EVOLUTION_INDIVIDUAL_SELECTOR_MOCK

#include <gmock/gmock.h>

#include <gram/evolution/selector/IndividualSelector.h>

namespace gram {
namespace evolution {
/**
 * Mock.
 */
class IndividualSelectorMock : public IndividualSelector {
 public:
  MOCK_METHOD1(select, gram::individual::Individual(gram::population::Population population));
};
}
}

#endif // GRAM_EVOLUTION_INDIVIDUAL_SELECTOR_MOCK
