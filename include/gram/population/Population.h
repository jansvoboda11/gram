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
  double bestFitness() const;
  const Individual& bestIndividual() const;
  Individual& operator[](unsigned long index);
  std::vector<Individual>::iterator begin();
  std::vector<Individual>::iterator end();
  std::vector<Individual>::const_iterator begin() const;
  std::vector<Individual>::const_iterator end() const;
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
