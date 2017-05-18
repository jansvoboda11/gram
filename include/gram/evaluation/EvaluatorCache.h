#ifndef GRAM_EVALUATOR_CACHE
#define GRAM_EVALUATOR_CACHE

#include <memory>
#include <unordered_map>

#include "gram/evaluation/Evaluator.h"

namespace gram {
/**
 * Class.
 */
class EvaluatorCache : public Evaluator {
public:
  EvaluatorCache(std::unique_ptr<Evaluator> evaluator);
  double evaluate(const Phenotype& phenotype) noexcept override;

private:
  std::unique_ptr<Evaluator> evaluator;
  std::unordered_map<Phenotype, double> cache;
};
}

#endif // GRAM_EVALUATOR_CACHE
