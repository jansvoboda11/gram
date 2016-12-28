#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/processor/Processor.h>
#include <gram/individual/Individual.h>
#include <gram/population/generator/Generator.h>
#include <gram/population/Individuals.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(Individuals individuals, std::shared_ptr<Generator> generator);
  double bestFitness() const;
  Individual bestIndividual() const;
  Individual at(unsigned long index) const;
  void process(const Processor& processor, int goal);
  Population successor() const;
 private:
  Individuals individuals;
  std::shared_ptr<Generator> generator;
};
}

#endif // GRAM_POPULATION
