#ifndef GRAM_MULTI_THREAD_EVALUATION_DRIVER
#define GRAM_MULTI_THREAD_EVALUATION_DRIVER

#include <memory>
#include <vector>

#include "gram/evaluation/Evaluator.h"
#include "gram/evaluation/driver/EvaluationDriver.h"

namespace gram {
class Population;
/**
 * Class.
 */
class MultiThreadDriver : public EvaluationDriver {
 public:
  MultiThreadDriver(std::vector<std::unique_ptr<Evaluator>> evaluators);
  void evaluate(Population& population);
 private:
  std::vector<std::unique_ptr<Evaluator>> evaluators;
  void launchEvaluator(Population& population, unsigned long threadNumber);
};
}

#endif // GRAM_MULTI_THREAD_EVALUATION_DRIVER
