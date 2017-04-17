#include "gram/evaluation/driver/MultiThreadDriver.h"

#include <algorithm>
#include <functional>
#include <thread>

#include "gram/individual/Individual.h"
#include "gram/population/Population.h"

using namespace gram;
using namespace std;

MultiThreadDriver::MultiThreadDriver(vector<unique_ptr<Evaluator>> evaluators) : evaluators(move(evaluators)) {
  //
}

void MultiThreadDriver::evaluate(Population& population) {
  unsigned long newThreadCount = evaluators.size() - 1;

  vector<thread> evaluatorsThreads;
  evaluatorsThreads.reserve(newThreadCount);

  for (unsigned long i = 0; i < newThreadCount; i++) {
    evaluatorsThreads.push_back(thread(&MultiThreadDriver::launchEvaluator, this, ref(population), i));
  }

  launchEvaluator(population, newThreadCount);

  for (auto& evaluatorThread : evaluatorsThreads) {
    evaluatorThread.join();
  }
}

void MultiThreadDriver::launchEvaluator(Population& population, unsigned long threadNumber) {
  Evaluator& evaluator = *evaluators[threadNumber];
  bool isLastEvaluator = threadNumber == evaluators.size() - 1;

  unsigned long threadCount = evaluators.size();

  unsigned long batchSize = population.size() / threadCount;
  unsigned long lowerIndex = threadNumber * batchSize;
  unsigned long upperLimit = isLastEvaluator ? population.size() : lowerIndex + batchSize;

  for (unsigned long i = lowerIndex; i < upperLimit; i++) {
    population[i].evaluate(evaluator);
  }
}
