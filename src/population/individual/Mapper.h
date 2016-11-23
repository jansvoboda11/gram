#ifndef GRAM_INDIVIDUAL_MAPPER
#define GRAM_INDIVIDUAL_MAPPER

#include "Genotype.h"
#include "Phenotype.h"

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
class Mapper {
 public:
  Phenotype map(Genotype genotype);
};
}
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
