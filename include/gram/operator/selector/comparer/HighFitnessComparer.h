#ifndef GRAM_INDIVIDUAL_HIGH_FITNESS_COMPARER
#define GRAM_INDIVIDUAL_HIGH_FITNESS_COMPARER

#include "gram/individual/Individual.h"
#include "IndividualComparer.h"

namespace gram {
/**
 * Class.
 */
class HighFitnessComparer : public IndividualComparer {
public:
  bool isFirstFitter(const Individual& first, const Individual& second) const override;
};
}

#endif // GRAM_INDIVIDUAL_HIGH_FITNESS_COMPARER
