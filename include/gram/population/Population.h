#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/processor/Processor.h>
#include <gram/individual/Individual.h>
#include <gram/population/generator/Generator.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(std::vector<std::shared_ptr<Individual>> individuals, std::shared_ptr<Generator> generator);
  double bestFitness() const;
  std::shared_ptr<Individual> bestIndividual() const;
  void process(Processor const& processor, int goal);
  Population successor() const;
  std::shared_ptr<Individual> &operator[](unsigned long index);
 private:
  std::vector<std::shared_ptr<Individual>> individuals_;
  std::shared_ptr<Individual> bestIndividual_;
  std::shared_ptr<Generator> generator_;
};
}

#endif // GRAM_POPULATION
