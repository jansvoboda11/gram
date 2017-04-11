#ifndef GRAM_EVALUATOR
#define GRAM_EVALUATOR

#include <gram/individual/Individual.h>

namespace gram {
// Forward declaration.
class Individual;
/**
 * Class.
 */
class Evaluator {
 public:
  virtual ~Evaluator() = default;
  virtual double evaluate(Individual& individual) = 0;
};
}

#endif // GRAM_LANGUAGE_EVALUATOR
