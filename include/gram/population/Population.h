#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/comparer/IndividualComparer.h>
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
  const Individual& bestIndividual(IndividualComparer& comparer) const;
  const Individual& individualWithLowestFitness() const;
  const Individual& individualWithHighestFitness() const;
  double bestFitness(IndividualComparer& comparer) const;
  double lowestFitness() const;
  double highestFitness() const;
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
