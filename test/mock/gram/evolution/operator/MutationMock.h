#ifndef GRAM_OPERATOR_MUTATION_MOCK
#define GRAM_OPERATOR_MUTATION_MOCK

#include <gmock/gmock.h>

#include <gram/evolution/operator/Mutation.h>

namespace gram {
namespace evolution {
/**
 * Mock.
 */
class MutationMock : public Mutation {
 public:
  MOCK_METHOD1(apply, gram::individual::Genotype(gram::individual::Genotype genotype));
};
}
}

#endif // GRAM_OPERATOR_MUTATION_MOCK
