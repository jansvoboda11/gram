#ifndef GRAM_UTIL_NULL_LOGGER
#define GRAM_UTIL_NULL_LOGGER

#include "gram/util/logger/Logger.h"

namespace gram {
/**
 * Class.
 */
class Population;

class NullLogger : public Logger {
 public:
  void logProgress(const Population& population);
  void logResult(const Population& population);
};
}

#endif // GRAM_UTIL_NULL_LOGGER
