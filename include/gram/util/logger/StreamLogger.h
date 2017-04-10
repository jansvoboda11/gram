#ifndef GRAM_UTIL_STREAM_LOGGER
#define GRAM_UTIL_STREAM_LOGGER

#include <gram/language/Mapper.h>
#include <gram/util/logger/Logger.h>

#include <memory>
#include <ostream>

namespace gram {
/**
 * Class.
 */
class StreamLogger : public Logger {
 public:
  StreamLogger(std::ostream& stream, std::shared_ptr<Mapper> mapper);
  void log(Population& population);
 private:
  std::ostream& stream;
  std::shared_ptr<Mapper> mapper;
};
}

#endif // GRAM_UTIL_STREAM_LOGGER
