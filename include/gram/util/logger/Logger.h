#ifndef GRAM_UTIL_LOGGER
#define GRAM_UTIL_LOGGER

#include <gram/population/Population.h>

namespace gram {
/**
 * Interface.
 */
class Logger {
 public:
  virtual void log(Population& population) = 0;
};
}

#endif // GRAM_UTIL_LOGGER
