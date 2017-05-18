#ifndef GRAM_POPULATION_INDIVIDUALS
#define GRAM_POPULATION_INDIVIDUALS

#include <memory>
#include <vector>

#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"

namespace gram {
/**
 * Class.
 */
class Individuals {
public:
  Individuals();
  Individuals(std::initializer_list<Individual> individuals);
  void addIndividual(Individual individual);
  const Individual& bestIndividual(IndividualComparer& comparer) const;
  Individual& operator[](unsigned long index);
  const Individual& operator[](unsigned long index) const;
  unsigned long size() const;
  bool empty() const;
  void reserve(unsigned long count);
  std::vector<Individual>::iterator begin();
  std::vector<Individual>::iterator end();
  std::vector<Individual>::const_iterator begin() const;
  std::vector<Individual>::const_iterator end() const;
  bool operator==(const Individuals& second) const;
  bool operator!=(const Individuals& second) const;

private:
  std::vector<Individual> individuals;
};
}

#endif // GRAM_POPULATION_INDIVIDUALS
