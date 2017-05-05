#ifndef GRAM_EVALUATION_DRIVER
#define GRAM_EVALUATION_DRIVER

#include "gram/population/Population.h"

namespace gram {
/**
 * Interface.
 */
class EvaluationDriver {
public:
  virtual void evaluate(Population& population) = 0;
};
}

#endif // GRAM_EVALUATION_DRIVER
