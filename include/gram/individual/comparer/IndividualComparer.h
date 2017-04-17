#ifndef GRAM_INDIVIDUAL_COMPARER
#define GRAM_INDIVIDUAL_COMPARER

#include "gram/individual/Individual.h"

namespace gram {
/**
 * Interface.
 */
class IndividualComparer {
 public:
  virtual bool isFirstFitter(const Individual& first, const Individual& second) const = 0;
};
}

#endif // GRAM_INDIVIDUAL_COMPARER
