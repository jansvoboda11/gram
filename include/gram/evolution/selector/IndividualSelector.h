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
  IndividualSelector(gram::population::Population population, gram::util::NumberGenerator &generator);
  virtual gram::individual::Individual select() = 0;
 protected:
  gram::population::Population population;
  gram::util::NumberGenerator &generator;
};
}
}

#endif // GRAM_EVOLUTION_INDIVIDUAL_SELECTOR
