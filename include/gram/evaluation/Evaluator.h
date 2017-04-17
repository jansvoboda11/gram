#ifndef GRAM_EVALUATOR
#define GRAM_EVALUATOR

#include "gram/individual/Genotype.h"

namespace gram {
/**
 * Class.
 */
class Evaluator {
 public:
  virtual ~Evaluator() = default;
  virtual double evaluate(const Genotype& genotype) noexcept = 0;
};
}

#endif // GRAM_LANGUAGE_EVALUATOR
