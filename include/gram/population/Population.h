#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include "gram/individual/Individual.h"
#include "gram/operator/selector/comparer/IndividualComparer.h"
#include "gram/population/Individuals.h"
#include "gram/population/reproducer/Reproducer.h"

namespace gram {
/**
 * Class.
 */
class Population {
public:
  Population(Individuals individuals, std::unique_ptr<Reproducer> reproducer, unsigned long generationNumber);
  Population(Population&&) = default;
  unsigned long generationNumber() const;
  const Individual& bestIndividual(IndividualComparer& comparer) const;
  const Individual& individualWithLowestFitness() const;
  const Individual& individualWithHighestFitness() const;
  Fitness bestFitness(IndividualComparer& comparer) const;
  Fitness lowestFitness() const;
  Fitness highestFitness() const;
  Individuals& allIndividuals();
  Individual& operator[](unsigned long index);
  std::vector<Individual>::iterator begin();
  std::vector<Individual>::iterator end();
  std::vector<Individual>::const_iterator begin() const;
  std::vector<Individual>::const_iterator end() const;
  unsigned long size() const;
  void reproduce();
  virtual ~Population() = default;

private:
  Individuals individuals;
  std::unique_ptr<Reproducer> reproducer;
  unsigned long number;
};
}

#endif
