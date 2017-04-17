#ifndef GRAM_INDIVIDUAL_MUTATION
#define GRAM_INDIVIDUAL_MUTATION

#include "gram/individual/Genotype.h"

namespace gram {
/**
 * Interface.
 */
class Mutation {
 public:
  virtual Genotype apply(Genotype genotype) = 0;
};
}

#endif // GRAM_INDIVIDUAL_MUTATION
