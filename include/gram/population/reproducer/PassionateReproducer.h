#ifndef GRAM_POPULATION_PASSIONATE_REPRODUCER
#define GRAM_POPULATION_PASSIONATE_REPRODUCER

#include <gram/population/reproducer/Reproducer.h>
#include <gram/population/selector/IndividualSelector.h>

namespace gram {
/**
 * Class.
 */
class PassionateReproducer : public Reproducer {
 public:
  PassionateReproducer(std::unique_ptr<IndividualSelector> selector,
  std::unique_ptr<Crossover> crossover,
      std::unique_ptr<Mutation> mutation);
  Individuals reproduce(Individuals& individuals);
 private:
  std::unique_ptr<IndividualSelector> selector;
  std::unique_ptr<Crossover> crossover;
  std::unique_ptr<Mutation> mutation;
};
}

#endif // GRAM_POPULATION_PASSIONATE_REPRODUCER
