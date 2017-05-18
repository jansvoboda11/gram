#ifndef GRAM_EVALUATOR
#define GRAM_EVALUATOR

#include "gram/individual/Fitness.h"
#include "gram/individual/Phenotype.h"

namespace gram {
/**
 * Interface.
 */
class Evaluator {
public:
  virtual ~Evaluator() = default;
  virtual Fitness evaluate(const Phenotype& phenotype) noexcept = 0;
};
}

#endif // GRAM_LANGUAGE_EVALUATOR
