#include <gram/util/logger/StreamLogger.h>

using namespace gram;
using namespace std;

StreamLogger::StreamLogger(ostream& stream, shared_ptr<Mapper> mapper) : stream(stream), mapper(mapper) {
  //
}

void StreamLogger::log(Population& population) {
  // todo: log something meaningful

  stream << "StreamLogger" << endl;
}
