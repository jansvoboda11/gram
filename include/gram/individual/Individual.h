#ifndef GRAM_INDIVIDUAL_INDIVIDUAL
#define GRAM_INDIVIDUAL_INDIVIDUAL

#include <gram/individual/Genotype.h>
#include <gram/individual/Phenotype.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Individual {
 public:
  Individual(Genotype genotype);
  bool operator==(const Individual &individual) const;
  bool operator!=(const Individual &individual) const;
 private:
  Genotype genotype;
  Phenotype phenotype;
};
}
}

#endif // GRAM_INDIVIDUAL_INDIVIDUAL
