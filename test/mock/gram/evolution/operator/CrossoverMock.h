#ifndef GRAM_OPERATOR_CROSSOVER_MOCK
#define GRAM_OPERATOR_CROSSOVER_MOCK

#include <gmock/gmock.h>

#include <gram/evolution/operator/Crossover.h>

namespace gram {
namespace evolution {
/**
 * Mock.
 */
class CrossoverMock : public Crossover {
 public:
  MOCK_METHOD2(apply, gram::individual::Genotype(gram::individual::Genotype first, gram::individual::Genotype second));
};
}
}

#endif // GRAM_OPERATOR_CROSSOVER_MOCK
