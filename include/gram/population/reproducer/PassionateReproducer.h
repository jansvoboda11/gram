#ifndef GRAM_PASSIONATE_REPRODUCER
#define GRAM_PASSIONATE_REPRODUCER

#include <memory>

#include "gram/individual/Individual.h"
#include "gram/operator/crossover/Crossover.h"
#include "gram/operator/mutation/Mutation.h"
#include "gram/operator/selector/IndividualSelector.h"
#include "gram/population/Individuals.h"
#include "gram/population/reproducer/Reproducer.h"

namespace gram {
/**
 * Class.
 */
class PassionateReproducer : public Reproducer {
public:
  PassionateReproducer(std::unique_ptr<IndividualSelector> selector, std::unique_ptr<Crossover> crossover,
                       std::unique_ptr<Mutation> mutation);
  Individuals reproduce(Individuals& individuals) override;

private:
  std::unique_ptr<IndividualSelector> selector;
  std::unique_ptr<Crossover> crossover;
  std::unique_ptr<Mutation> mutation;
  Individual createChild(Individuals& individuals);
};
}

#endif
