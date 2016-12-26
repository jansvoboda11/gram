#ifndef GRAM_POPULATION_INDIVIDUAL_SELECTOR
#define GRAM_POPULATION_INDIVIDUAL_SELECTOR

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>

namespace gram {
/**
 * Interface.
 */
class IndividualSelector {
 public:
  virtual std::shared_ptr<Individual> select(std::vector<std::shared_ptr<Individual>> population) const = 0;
};
}

#endif // GRAM_POPULATION_INDIVIDUAL_SELECTOR
