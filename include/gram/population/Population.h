#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>
#include <gram/population/generator/Generator.h>
#include <gram/individual/processor/Processor.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(std::vector<std::shared_ptr<Individual>> individuals, std::shared_ptr<Generator> generator);
  double bestFitness();
  std::shared_ptr<Individual> bestIndividual();
  void process(std::shared_ptr<Processor> processor, int goal);
  Population successor();
  std::shared_ptr<Individual> &operator[](unsigned long index);
 private:
  std::vector<std::shared_ptr<Individual>> individuals_;
  std::shared_ptr<Individual> bestIndividual_;
  std::shared_ptr<Generator> generator_;
};
}

#endif // GRAM_POPULATION
