#ifndef GRAM_POPULATION_REPRODUCER
#define GRAM_POPULATION_REPRODUCER

#include <memory>
#include <vector>

#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>
#include <gram/individual/Individual.h>
#include <gram/population/selector/IndividualSelector.h>
#include <gram/population/Individuals.h>

namespace gram {
/**
 * Class.
 */
class Reproducer {
 public:
  Reproducer(std::unique_ptr<IndividualSelector> selector,
             std::unique_ptr<Crossover> crossover,
             std::unique_ptr<Mutation> mutation);
  virtual ~Reproducer() = default;
  virtual Individuals reproduce(const Individuals &individuals) const;
 private:
  std::unique_ptr<IndividualSelector> selector;
  std::unique_ptr<Crossover> crossover;
  std::unique_ptr<Mutation> mutation;
};
}

#endif // GRAM_POPULATION_REPRODUCER
