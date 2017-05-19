#ifndef GRAM_INVALID_PROBABILITY
#define GRAM_INVALID_PROBABILITY

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

#endif
