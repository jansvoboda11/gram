#ifndef GRAM_ZERO_GENOTYPE_LENGTH
#define GRAM_ZERO_GENOTYPE_LENGTH

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class ZeroGenotypeLength : public std::length_error {
public:
  ZeroGenotypeLength();
};
}

#endif
