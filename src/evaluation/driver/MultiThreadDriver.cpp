#include "gram/evaluation/driver/MultiThreadDriver.h"

#include <algorithm>
#include <functional>
#include <thread>

#include "gram/individual/Individual.h"
#include "gram/population/Population.h"

using namespace gram;
using namespace std;

MultiThreadDriver::MultiThreadDriver(vector<unique_ptr<Evaluator>> evaluators)
    : evaluators(move(evaluators)) {
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

  unsigned long batchSize = population.size() / evaluators.size();

  unsigned long lowerLimit = threadNumber * batchSize;
  unsigned long upperBound = lowerLimit + batchSize;

  for (unsigned long i = lowerLimit; i < upperBound; i++) {
    population[i].evaluate(evaluator);
  }
}
