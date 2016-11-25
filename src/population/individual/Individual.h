#ifndef GRAM_INDIVIDUAL_INDIVIDUAL
#define GRAM_INDIVIDUAL_INDIVIDUAL

#include <population/individual/Genotype.h>
#include <population/individual/Phenotype.h>

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
class Individual {
 public:
  Individual();
 private:
  Genotype genotype;
  Phenotype phenotype;
};
}
}
}

#endif // GRAM_INDIVIDUAL_INDIVIDUAL
