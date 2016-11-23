#ifndef GRAM_INDIVIDUAL_GENOTYPE
#define GRAM_INDIVIDUAL_GENOTYPE

#include <vector>

namespace gram {
namespace population {
namespace individual {
/**
 * Structure.
 */
struct Genotype {
  Genotype(std::vector<int> values);
  std::vector<int> values;
};
}
}
}

#endif // GRAM_INDIVIDUAL_GENOTYPE
