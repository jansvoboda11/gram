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
  Individual& bestIndividual() const;
  void process(const Processor& processor, int goal);
  Population successor() const;
  Individual& operator[](unsigned long index);
 private:
  std::vector<std::shared_ptr<Individual>> individuals;
  std::shared_ptr<Generator> generator;
};
}

#endif // GRAM_POPULATION
