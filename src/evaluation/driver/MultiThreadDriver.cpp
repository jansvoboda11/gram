#include "gram/evaluation/driver/MultiThreadDriver.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

#include "gram/evaluation/driver/SingleThreadDriver.h"
#include "gram/individual/Individual.h"
#include "gram/population/Individuals.h"

using namespace gram;
using namespace std;

MultiThreadDriver::MultiThreadDriver(vector<unique_ptr<SingleThreadDriver>> drivers)
    : drivers(move(drivers)) {
  //
}

void MultiThreadDriver::evaluate(Individuals& individuals) {
  unsigned long newThreadCount = drivers.size() - 1;

  vector<thread> evaluatorsThreads;
  evaluatorsThreads.reserve(newThreadCount);

  for (unsigned long i = 0; i < newThreadCount; i++) {
    evaluatorsThreads.push_back(thread(&MultiThreadDriver::launchEvaluator, this, ref(individuals), i));
  }

  launchEvaluator(individuals, newThreadCount);

  for (auto& evaluatorThread : evaluatorsThreads) {
    evaluatorThread.join();
  }
}

void MultiThreadDriver::launchEvaluator(Individuals& individuals, unsigned long threadNumber) {
  unique_ptr<SingleThreadDriver>& driver = drivers[threadNumber];
  bool isLastEvaluator = threadNumber == drivers.size() - 1;

  unsigned long threadCount = drivers.size();

  unsigned long batchSize = individuals.size() / threadCount;
  unsigned long lowerIndex = threadNumber * batchSize;
  unsigned long upperLimit = isLastEvaluator ? individuals.size() : lowerIndex + batchSize;

  for (unsigned long i = lowerIndex; i < upperLimit; i++) {
    driver->evaluateOne(individuals[i]);
  }
}
