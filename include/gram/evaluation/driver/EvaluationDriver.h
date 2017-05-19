#ifndef GRAM_EVALUATION_DRIVER
#define GRAM_EVALUATION_DRIVER

#include "gram/population/Individuals.h"

namespace gram {
/**
 * Interface.
 */
class EvaluationDriver {
public:
  virtual ~EvaluationDriver() = default;
  virtual void evaluate(Individuals& individuals) = 0;
};
}

#endif
