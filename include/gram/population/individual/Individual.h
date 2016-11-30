#ifndef GRAM_INDIVIDUAL_INDIVIDUAL
#define GRAM_INDIVIDUAL_INDIVIDUAL

#include <gram/population/individual/Genotype.h>
#include <gram/population/individual/Phenotype.h>

namespace gram {
namespace population {
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
}

#endif // GRAM_INDIVIDUAL_INDIVIDUAL
