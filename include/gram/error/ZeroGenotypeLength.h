#ifndef GRAM_ERROR_ZERO_GENOTYPE_LENGTH
#define GRAM_ERROR_ZERO_GENOTYPE_LENGTH

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

#endif // GRAM_ERROR_ZERO_GENOTYPE_LENGTH
