#ifndef GRAM_SELECTOR
#define GRAM_SELECTOR

#include <memory>
#include <vector>

#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"

namespace gram {
/**
 * Interface.
 */
class IndividualSelector {
public:
  virtual ~IndividualSelector() = default;
  virtual Individual& select(Individuals& individuals) = 0;
};
}

#endif
