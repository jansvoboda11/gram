#ifndef GRAM_POPULATION_REPRODUCTION
#define GRAM_POPULATION_REPRODUCTION

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
class Reproduction {
 public:
  Reproduction(std::unique_ptr<IndividualSelector> selector,
               std::unique_ptr<Crossover> crossover,
               std::unique_ptr<Mutation> mutation);
  virtual ~Reproduction() = default;
  virtual Individuals reproduce(const Individuals &individuals) const;
 private:
  std::unique_ptr<IndividualSelector> selector;
  std::unique_ptr<Crossover> crossover;
  std::unique_ptr<Mutation> mutation;
};
}

#endif // GRAM_POPULATION_REPRODUCTION
