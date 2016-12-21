#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

#include <memory>

#include <gram/population/Population.h>
#include <gram/population/selector/IndividualSelector.h>
#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Generator {
 public:
  Generator(gram::evolution::IndividualSelector &selector,
            gram::evolution::Crossover &crossover,
            gram::evolution::Mutation &mutation);
  virtual Population generateSuccessor(Population &population);
 private:
  gram::evolution::IndividualSelector &selector;
  gram::evolution::Crossover &crossover;
  gram::evolution::Mutation &mutation;
  std::vector<std::shared_ptr<gram::individual::Individual>> selectParents(Population &oldPopulation);
  std::vector<std::shared_ptr<gram::individual::Individual>> createChildren(std::vector<std::shared_ptr<gram::individual::Individual>> parents);
  void mutateChildren(std::vector<std::shared_ptr<gram::individual::Individual>> children);
};
}
}

#endif // GRAM_POPULATION_GENERATOR
