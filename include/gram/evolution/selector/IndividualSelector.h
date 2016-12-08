#ifndef GRAM_EVOLUTION_INDIVIDUAL_SELECTOR
#define GRAM_EVOLUTION_INDIVIDUAL_SELECTOR

#include <gram/population/Population.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class IndividualSelector {
 public:
  virtual gram::individual::Individual select(gram::population::Population population) = 0;
};
}
}

#endif // GRAM_EVOLUTION_INDIVIDUAL_SELECTOR
