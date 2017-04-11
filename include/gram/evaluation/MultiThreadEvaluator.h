#ifndef GRAM_MULTI_THREAD_EVALUATOR
#define GRAM_MULTI_THREAD_EVALUATOR

#include <gram/evaluation/Evaluator.h>

namespace gram {
/**
 * Interface.
 */
class MultiThreadEvaluator : public Evaluator {
 public:
  virtual std::unique_ptr<MultiThreadEvaluator> clone() = 0;
};
}

#endif // GRAM_MULTI_THREAD_EVALUATOR
