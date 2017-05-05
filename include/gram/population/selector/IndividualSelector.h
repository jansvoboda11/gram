#ifndef GRAM_POPULATION_INDIVIDUAL_SELECTOR
#define GRAM_POPULATION_INDIVIDUAL_SELECTOR

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
  virtual Individual& select(Individuals& individuals) = 0;
};
}

#endif // GRAM_POPULATION_INDIVIDUAL_SELECTOR
