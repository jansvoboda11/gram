#ifndef GRAM_MAPPER
#define GRAM_MAPPER

#include "gram/individual/Genotype.h"
#include "gram/individual/Phenotype.h"

namespace gram {
/**
 * Interface.
 */
class Mapper {
public:
  virtual ~Mapper() = default;
  virtual Phenotype map(const Genotype& genotype) = 0;
};
}

#endif
