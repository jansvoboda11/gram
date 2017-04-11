#include <gram/evaluation/driver/MultiThreadDriver.h>

#include <thread>

using namespace gram;

MultiThreadDriver::MultiThreadDriver(std::unique_ptr<MultiThreadEvaluator> evaluator, unsigned long threadCount)
    : threadCount(threadCount) {
  if (threadCount <= 0) {
    throw std::logic_error("Thread count must be greater than zero.");
  }

  evaluators.reserve(threadCount);

  for (unsigned long i = 0; i < threadCount; i++) {
    evaluators.push_back(evaluator->clone());
  }
}

void MultiThreadDriver::evaluate(Population& population) {
  unsigned long newThreadCount = threadCount - 1;

  std::vector<std::thread> threads;
  threads.reserve(newThreadCount);

  for (unsigned long i = 0; i < newThreadCount; i++) {
    threads.push_back(std::thread(&MultiThreadDriver::launchEvaluator, this, std::ref(population), i));
  }

  launchEvaluator(population, newThreadCount);

  for (auto& thread : threads) {
    thread.join();
  }
}

void MultiThreadDriver::launchEvaluator(Population& population, unsigned long threadNumber) {
  MultiThreadEvaluator& evaluator = *evaluators[threadNumber];

  unsigned long batchSize = population.size() / threadCount;

  unsigned long lowerLimit = threadNumber * batchSize;
  unsigned long upperBound = lowerLimit + batchSize;

  for (unsigned long i = lowerLimit; i < upperBound; i++) {
    population[i].evaluate(evaluator);
  }
}
