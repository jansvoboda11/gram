#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>
#include <gram/population/reproducer/Reproducer.h>
#include <gram/population/Individuals.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(Individuals individuals, std::shared_ptr<Reproducer> reproducer, unsigned long generationNumber);
  unsigned long generationNumber() const;
  double bestFitness();
  Individual& bestIndividual();
  Individual& operator[](unsigned long index);
  std::vector<Individual>::iterator begin();
  std::vector<Individual>::iterator end();
  unsigned long size() const;
  Population reproduce();
  virtual ~Population() = default;
 private:
  Individuals individuals;
  std::shared_ptr<Reproducer> reproducer;
  unsigned long number;
};
}

#endif // GRAM_POPULATION
