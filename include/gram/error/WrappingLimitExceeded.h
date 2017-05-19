#ifndef GRAM_WRAPPING_LIMIT_EXCEEDED
#define GRAM_WRAPPING_LIMIT_EXCEEDED

#include <stdexcept>

namespace gram {
/**
 * Exception.
 */
class WrappingLimitExceeded : std::out_of_range {
public:
  WrappingLimitExceeded(unsigned long limit);
};
}

#endif
