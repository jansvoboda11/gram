#ifndef GRAM_POPULATION_INDIVIDUAL_SELECTOR
#define GRAM_POPULATION_INDIVIDUAL_SELECTOR

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>

namespace gram {
namespace population {
/**
 * Interface.
 */
class IndividualSelector {
 public:
  virtual std::shared_ptr<gram::individual::Individual> select(std::vector<std::shared_ptr<gram::individual::Individual>> population) = 0;
};
}
}

#endif // GRAM_POPULATION_INDIVIDUAL_SELECTOR
