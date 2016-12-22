#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>
#include <gram/population/generator/Generator.h>
#include <gram/individual/processor/Processor.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Population {
 public:
  Population(std::vector<std::shared_ptr<gram::individual::Individual>> individuals, std::shared_ptr<Generator> generator);
  double bestFitness();
  std::shared_ptr<gram::individual::Individual> bestIndividual();
  void process(std::shared_ptr<gram::individual::Processor> processor, int goal);
  Population successor();
  std::shared_ptr<gram::individual::Individual> &operator[](unsigned long index);
 private:
  std::vector<std::shared_ptr<gram::individual::Individual>> individuals_;
  std::shared_ptr<gram::individual::Individual> bestIndividual_;
  std::shared_ptr<gram::population::Generator> generator_;
};
}
}

#endif // GRAM_POPULATION
