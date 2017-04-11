#ifndef GRAM_MULTI_THREAD_DRIVER
#define GRAM_MULTI_THREAD_DRIVER

#include <memory>

#include <gram/evaluation/driver/EvaluationDriver.h>
#include <gram/evaluation/Evaluator.h>

namespace gram {
/**
 * Class.
 */
class MultiThreadDriver : public EvaluationDriver {
 public:
  MultiThreadDriver(std::unique_ptr<Evaluator> evaluator, unsigned long threadCount);
  void evaluate(Population& population);
 private:
  std::unique_ptr<Evaluator> evaluator;
  unsigned long threadCount;
};
}

#endif // GRAM_MULTI_THREAD_DRIVER
