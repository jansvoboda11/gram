#ifndef GRAM_LANGUAGE_MAPPER
#define GRAM_LANGUAGE_MAPPER

#include "gram/individual/Genotype.h"
#include "gram/individual/Phenotype.h"

namespace gram {
/**
 * Interface.
 */
class Mapper {
public:
  virtual Phenotype map(const Genotype& genotype) = 0;
};
}

#endif // GRAM_LANGUAGE_MAPPER
