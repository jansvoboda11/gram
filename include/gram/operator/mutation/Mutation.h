#ifndef GRAM_MUTATION
#define GRAM_MUTATION

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

#endif
