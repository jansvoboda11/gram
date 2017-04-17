#include "gram/util/logger/NullLogger.h"

namespace gram {
class Population;
}

using namespace gram;

void NullLogger::logProgress(const Population& population) {
  //
}

void NullLogger::logResult(const Population& population) {
  //
}
