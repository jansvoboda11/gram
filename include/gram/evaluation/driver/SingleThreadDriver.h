#ifndef GRAM_SINGLE_THREAD_EVALUATION_DRIVER
#define GRAM_SINGLE_THREAD_EVALUATION_DRIVER

#include <memory>

#include <gram/evaluation/driver/EvaluationDriver.h>
#include <gram/evaluation/Evaluator.h>

namespace gram {
/**
 * Class.
 */
class SingleThreadDriver : public EvaluationDriver {
 public:
  SingleThreadDriver(std::unique_ptr<Evaluator> evaluator);
  void evaluate(Population& population);
 private:
  std::unique_ptr<Evaluator> evaluator;
};
}

#endif // GRAM_SINGLE_THREAD_EVALUATION_DRIVER
