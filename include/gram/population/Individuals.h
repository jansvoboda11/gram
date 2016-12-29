#ifndef GRAM_POPULATION_INDIVIDUALS
#define GRAM_POPULATION_INDIVIDUALS

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>

namespace gram {
/**
 * Class.
 */
class Individuals {
 public:
  Individuals();
  Individuals(std::initializer_list<std::shared_ptr<Individual>> individuals);
  void addIndividual(std::shared_ptr<Individual> individual);
  Individual& bestIndividual() const;
  Individual& operator[](unsigned long index) const;
  unsigned long size() const;
  std::vector<std::shared_ptr<Individual>>::iterator begin();
  std::vector<std::shared_ptr<Individual>>::iterator end();
 private:
  std::vector<std::shared_ptr<Individual>> individuals;
};
}

#endif // GRAM_POPULATION_INDIVIDUALS
