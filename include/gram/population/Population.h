#ifndef GRAM_POPULATION_POPULATION
#define GRAM_POPULATION_POPULATION

#include <gram/population/individual/Individual.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Population {
 public:
  Population(std::vector<gram::population::individual::Individual> individuals);
  gram::population::individual::Individual &operator[](int index);
 private:
  std::vector<gram::population::individual::Individual> individuals;
};
}
}

#endif // GRAM_POPULATION_POPULATION
