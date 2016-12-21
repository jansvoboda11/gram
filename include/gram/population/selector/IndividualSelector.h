#ifndef GRAM_POPULATION_INDIVIDUAL_SELECTOR
#define GRAM_POPULATION_INDIVIDUAL_SELECTOR

#include <memory>

#include <gram/population/Population.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace population {
/**
 * Interface.
 */
class IndividualSelector {
 public:
  virtual std::shared_ptr<gram::individual::Individual> select(Population population) = 0;
};
}
}

#endif // GRAM_POPULATION_INDIVIDUAL_SELECTOR
