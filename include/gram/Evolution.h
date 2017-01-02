#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <memory>

#include <gram/population/Population.h>

namespace gram {
/**
 * Class.
 */
class Evolution {
 public:
  Evolution(std::unique_ptr<Evaluator> evaluator);
  Individual run(Population& population) const;
 private:
  std::unique_ptr<Evaluator> evaluator;
};
}

#endif // GRAM_EVOLUTION_EVOLUTION
