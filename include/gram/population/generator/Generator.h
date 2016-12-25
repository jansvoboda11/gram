#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

#include <memory>
#include <vector>

#include <gram/population/selector/IndividualSelector.h>
#include <gram/individual/Individual.h>
#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>

namespace gram {
/**
 * Class.
 */
class Generator {
 public:
  Generator(IndividualSelector &selector, Crossover &crossover, Mutation &mutation);
  virtual ~Generator() = default;
  virtual std::vector<std::shared_ptr<Individual>> generateSuccessor(std::vector<std::shared_ptr<Individual>> individuals);
 private:
  IndividualSelector &selector;
  Crossover &crossover;
  Mutation &mutation;
  std::vector<std::shared_ptr<Individual>> selectParents(std::vector<std::shared_ptr<Individual>> individuals);
  std::vector<std::shared_ptr<Individual>> createChildren(std::vector<std::shared_ptr<Individual>> parents);
  void mutateChildren(std::vector<std::shared_ptr<Individual>> children);
};
}

#endif // GRAM_POPULATION_GENERATOR
