#ifndef GRAM_INDIVIDUAL_MUTATION_OPERATOR
#define GRAM_INDIVIDUAL_MUTATION_OPERATOR

#include <gram/individual/Genotype.h>

namespace gram {
/**
 * Interface.
 */
class Mutation {
 public:
  virtual Genotype apply(Genotype genotype) const = 0;
};
}

#endif // GRAM_INDIVIDUAL_MUTATION_OPERATOR
