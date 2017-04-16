#ifndef GRAM_ERROR_INVALID_PROBABILITY
#define GRAM_ERROR_INVALID_PROBABILITY

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class InvalidProbability : std::domain_error {
 public:
  InvalidProbability();
};
}

#endif // GRAM_ERROR_INVALID_PROBABILITY
