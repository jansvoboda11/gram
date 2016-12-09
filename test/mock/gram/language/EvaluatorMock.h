#ifndef GRAM_LANGUAGE_EVALUATOR_MOCK
#define GRAM_LANGUAGE_EVALUATOR_MOCK

#include <gmock/gmock.h>

#include <gram/language/Evaluator.h>

namespace gram {
namespace language {
/**
 * Mock.
 */
class EvaluatorMock : public Evaluator {
 public:
  MOCK_METHOD1(evaluate, int(gram::individual::Individual individual));
};
}
}

#endif // GRAM_LANGUAGE_EVALUATOR_MOCK
