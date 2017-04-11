#include <gram/evaluation/driver/MultiThreadDriver.h>

using namespace gram;
using namespace std;

MultiThreadDriver::MultiThreadDriver(unique_ptr <Evaluator> evaluator, unsigned long threadCount)
    : evaluator(move(evaluator)), threadCount(threadCount) {
  if (threadCount <= 0) {
    throw logic_error("Thread count must be greater than zero.");
  }
}

void MultiThreadDriver::evaluate(Population& population) {
  // todo: implement
}
