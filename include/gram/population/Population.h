#ifndef GRAM_POPULATION_POPULATION
#define GRAM_POPULATION_POPULATION

#include <vector>

#include <gram/individual/Individual.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Population {
 public:
  Population();
  Population(std::vector<gram::individual::Individual> individuals);
  Population(std::initializer_list<gram::individual::Individual> individuals);
  gram::individual::Individual &bestIndividual();
  void addIndividual(gram::individual::Individual individual);
  unsigned long size();
  gram::individual::Individual &operator[](unsigned long index);
  std::vector<gram::individual::Individual>::iterator begin() noexcept;
  std::vector<gram::individual::Individual>::iterator end() noexcept;
 private:
  std::vector<gram::individual::Individual> individuals;
};
}
}

#endif // GRAM_POPULATION_POPULATION
