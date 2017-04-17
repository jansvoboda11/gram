#include "gram/evaluation/driver/SingleThreadDriver.h"

#include <algorithm>

#include "gram/individual/Individual.h"

namespace gram {
class Population;
}

using namespace gram;
using namespace std;

SingleThreadDriver::SingleThreadDriver(unique_ptr<Evaluator> evaluator) : evaluator(move(evaluator)) {
  //
}

void SingleThreadDriver::evaluate(Population& population) {
  for (auto& individual : population) {
    individual.evaluate(*evaluator);
  }
}
