#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

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
class Generator {
 public:
  Generator(std::unique_ptr<IndividualSelector> selector,
            std::unique_ptr<Crossover> crossover,
            std::unique_ptr<Mutation> mutation);
  virtual ~Generator() = default;
  virtual Individuals generateSuccessor(const Individuals &individuals) const;
 private:
  std::unique_ptr<IndividualSelector> selector;
  std::unique_ptr<Crossover> crossover;
  std::unique_ptr<Mutation> mutation;
};
}

#endif // GRAM_POPULATION_GENERATOR
