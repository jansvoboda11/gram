#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

#include <gram/population/Population.h>
#include <gram/evolution/selector/IndividualSelector.h>
#include <gram/evolution/operator/Crossover.h>
#include <gram/evolution/operator/Mutation.h>

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
  std::vector<gram::individual::Individual> selectParents(Population &oldPopulation);
  std::vector<gram::individual::Individual> createChildren(std::vector<gram::individual::Individual> parents);
  void mutateChildren(std::vector<gram::individual::Individual> &children);
};
}
}

#endif // GRAM_POPULATION_GENERATOR
