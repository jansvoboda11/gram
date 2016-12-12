#ifndef GRAM_POPULATION_POPULATION
#define GRAM_POPULATION_POPULATION

#include <memory>
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
  Population(std::vector<std::shared_ptr<gram::individual::Individual>> individuals);
  Population(std::initializer_list<std::shared_ptr<gram::individual::Individual>> individuals);
  std::shared_ptr<gram::individual::Individual> bestIndividual();
  unsigned long size();
  std::shared_ptr<gram::individual::Individual> &operator[](unsigned long index);
  std::vector<std::shared_ptr<gram::individual::Individual>>::iterator begin() noexcept;
  std::vector<std::shared_ptr<gram::individual::Individual>>::iterator end() noexcept;
 private:
  std::vector<std::shared_ptr<gram::individual::Individual>> individuals;
};
}
}

#endif // GRAM_POPULATION_POPULATION
