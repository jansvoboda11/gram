#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <memory>

#include <gram/population/Population.h>
#include <gram/util/logger/Logger.h>

namespace gram {
/**
 * Class.
 */
class Evolution {
 public:
  Evolution(std::unique_ptr<Evaluator> evaluator, std::unique_ptr<Logger> logger);
  Individual run(Population& population) const;
  Individual run(Population& population, bool (*successCondition)(Population&)) const;
 private:
  std::unique_ptr<Evaluator> evaluator;
  std::unique_ptr<Logger> logger;
};
}

#endif // GRAM_EVOLUTION_EVOLUTION
