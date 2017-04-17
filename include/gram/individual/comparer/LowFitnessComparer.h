#ifndef GRAM_INDIVIDUAL_LOW_FITNESS_COMPARER
#define GRAM_INDIVIDUAL_LOW_FITNESS_COMPARER

#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"

namespace gram {
/**
 * Class.
 */
class LowFitnessComparer : public IndividualComparer {
 public:
  bool isFirstFitter(const Individual& first, const Individual& second) const;
};
}

#endif // GRAM_INDIVIDUAL_LOW_FITNESS_COMPARER
