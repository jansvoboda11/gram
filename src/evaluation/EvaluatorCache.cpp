#include "gram/evaluation/EvaluatorCache.h"

using namespace gram;
using namespace std;

EvaluatorCache::EvaluatorCache(unique_ptr<Evaluator> evaluator) : evaluator(move(evaluator)) {
  //
}

Fitness EvaluatorCache::evaluate(const Phenotype& phenotype) noexcept {
  auto cacheItem = cache.find(phenotype);

  if (cacheItem == cache.end()) {
    Fitness fitness = evaluator->evaluate(phenotype);

    cache.insert({phenotype, fitness});

    return fitness;
  }

  return cacheItem->second;
}
