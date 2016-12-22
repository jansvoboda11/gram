#ifndef GRAM_POPULATION_GENERATOR
#define GRAM_POPULATION_GENERATOR

#include <memory>
#include <vector>

#include <gram/population/selector/IndividualSelector.h>
#include <gram/individual/Individual.h>
#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Generator {
 public:
  Generator(gram::population::IndividualSelector &selector, gram::individual::Crossover &crossover, gram::individual::Mutation &mutation);
  virtual ~Generator() = default;
  virtual std::vector<std::shared_ptr<gram::individual::Individual>> generateSuccessor(std::vector<std::shared_ptr<gram::individual::Individual>> individuals);
 private:
  gram::population::IndividualSelector &selector;
  gram::individual::Crossover &crossover;
  gram::individual::Mutation &mutation;
  std::vector<std::shared_ptr<gram::individual::Individual>> selectParents(std::vector<std::shared_ptr<gram::individual::Individual>> individuals);
  std::vector<std::shared_ptr<gram::individual::Individual>> createChildren(std::vector<std::shared_ptr<gram::individual::Individual>> parents);
  void mutateChildren(std::vector<std::shared_ptr<gram::individual::Individual>> children);
};
}
}

#endif // GRAM_POPULATION_GENERATOR
