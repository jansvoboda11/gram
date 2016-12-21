#ifndef GRAM_EVOLUTION_INDIVIDUAL_SELECTOR
#define GRAM_EVOLUTION_INDIVIDUAL_SELECTOR

#include <memory>

#include <gram/population/Population.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Interface.
 */
class IndividualSelector {
 public:
  virtual std::shared_ptr<gram::individual::Individual> select(gram::population::Population population) = 0;
};
}
}

#endif // GRAM_EVOLUTION_INDIVIDUAL_SELECTOR
