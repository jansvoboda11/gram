#ifndef GRAM_MULTI_THREAD_EVALUATION_DRIVER
#define GRAM_MULTI_THREAD_EVALUATION_DRIVER

#include <memory>
#include <vector>

#include "gram/evaluation/Evaluator.h"
#include "gram/evaluation/driver/EvaluationDriver.h"
#include "gram/evaluation/driver/SingleThreadDriver.h"
#include "gram/language/mapper/Mapper.h"
#include "gram/population/Individuals.h"

namespace gram {
/**
 * Class.
 */
class MultiThreadDriver : public EvaluationDriver {
public:
  MultiThreadDriver(std::vector<std::unique_ptr<SingleThreadDriver>> drivers);
  void evaluate(Individuals& individuals) override;

private:
  std::vector<std::unique_ptr<SingleThreadDriver>> drivers;
  void launchEvaluator(Individuals& individuals, unsigned long threadNumber);
};
}

#endif
