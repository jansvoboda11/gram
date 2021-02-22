#ifndef GRAM_LOGGER
#define GRAM_LOGGER

#include "gram/population/Population.h"

namespace gram {
/**
 * Interface.
 */
class Logger {
public:
  virtual ~Logger() = default;
  virtual void logProgress(const Population& population) = 0;
  virtual void logResult(const Population& population) = 0;
};
}

#endif
