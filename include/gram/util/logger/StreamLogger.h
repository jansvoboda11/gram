#ifndef GRAM_UTIL_STREAM_LOGGER
#define GRAM_UTIL_STREAM_LOGGER

#include <gram/util/logger/Logger.h>

#include <ostream>

namespace gram {
/**
 * Class.
 */
class StreamLogger : public Logger {
 public:
  StreamLogger(std::ostream& stream);
  void log(Population& population);
 private:
  std::ostream& stream;
};
}

#endif // GRAM_UTIL_STREAM_LOGGER
