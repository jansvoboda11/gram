#ifndef GRAM_MULTI_THREAD_EVALUATION_DRIVER
#define GRAM_MULTI_THREAD_EVALUATION_DRIVER

#include <memory>

#include <gram/evaluation/driver/EvaluationDriver.h>
#include <gram/evaluation/MultiThreadEvaluator.h>

namespace gram {
/**
 * Class.
 */
class MultiThreadDriver : public EvaluationDriver {
 public:
  MultiThreadDriver(std::unique_ptr<MultiThreadEvaluator> evaluator, unsigned long threadCount);
  void evaluate(Population& population);
  void launchEvaluator(Population& population, unsigned long threadNumber);
 private:
  std::vector<std::unique_ptr<MultiThreadEvaluator>> evaluators;
  unsigned long threadCount;
};
}

#endif // GRAM_MULTI_THREAD_EVALUATION_DRIVER
