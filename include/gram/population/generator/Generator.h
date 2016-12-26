#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

#include <memory>
#include <vector>

#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>
#include <gram/individual/Individual.h>
#include <gram/population/selector/IndividualSelector.h>

namespace gram {
/**
 * Class.
 */
class Generator {
 public:
  Generator(IndividualSelector &selector, Crossover &crossover, Mutation &mutation);
  virtual ~Generator() = default;
  virtual std::vector<std::shared_ptr<Individual>> generateSuccessor(std::vector<std::shared_ptr<Individual>> individuals) const;
 private:
  IndividualSelector &selector;
  Crossover &crossover;
  Mutation &mutation;
  std::vector<std::shared_ptr<Individual>> selectParents(std::vector<std::shared_ptr<Individual>> individuals) const;
  std::vector<std::shared_ptr<Individual>> createChildren(std::vector<std::shared_ptr<Individual>> parents) const;
  void mutateChildren(std::vector<std::shared_ptr<Individual>> children) const;
};
}

#endif // GRAM_POPULATION_GENERATOR
