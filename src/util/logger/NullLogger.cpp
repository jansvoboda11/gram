#include "gram/util/logger/NullLogger.h"

#include "gram/population/Population.h"

using namespace gram;

void NullLogger::logProgress(const Population& population) {
  static_cast<void>(population);

  //
}

void NullLogger::logResult(const Population& population) {
  static_cast<void>(population);

  //
}
