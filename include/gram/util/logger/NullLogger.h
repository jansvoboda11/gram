#ifndef GRAM_UTIL_NULL_LOGGER
#define GRAM_UTIL_NULL_LOGGER

#include <gram/util/logger/Logger.h>

namespace gram {
/**
 * Class.
 */
class NullLogger : public Logger {
 public:
  void log(Population& population);
};
}

#endif // GRAM_UTIL_NULL_LOGGER
