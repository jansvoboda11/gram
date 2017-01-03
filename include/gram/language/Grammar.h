#ifndef GRAM_LANGUAGE_GRAMMAR
#define GRAM_LANGUAGE_GRAMMAR

#include <gram/individual/Genotype.h>
#include <gram/individual/Phenotype.h>

namespace gram {
/**
 * Interface.
 */
class Grammar {
 public:
  virtual ~Grammar() = default;
  virtual Phenotype expand(const Genotype& genotype) = 0;
};
}

#endif // GRAM_LANGUAGE_GRAMMAR
