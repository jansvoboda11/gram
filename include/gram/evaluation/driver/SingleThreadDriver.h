#ifndef GRAM_SINGLE_THREAD_EVALUATION_DRIVER
#define GRAM_SINGLE_THREAD_EVALUATION_DRIVER

#include <memory>

#include "gram/evaluation/Evaluator.h"
#include "gram/evaluation/driver/EvaluationDriver.h"
#include "gram/language/mapper/Mapper.h"
#include "gram/population/Individuals.h"

namespace gram {
/**
 * Class.
 */
class SingleThreadDriver : public EvaluationDriver {
public:
  SingleThreadDriver(std::unique_ptr<Mapper> mapper, std::unique_ptr<Evaluator> evaluator);
  void evaluate(Individuals& individuals) override;
  virtual void evaluateOne(Individual& individual);

private:
  std::unique_ptr<Mapper> mapper;
  std::unique_ptr<Evaluator> evaluator;
};
}

#endif // GRAM_SINGLE_THREAD_EVALUATION_DRIVER
