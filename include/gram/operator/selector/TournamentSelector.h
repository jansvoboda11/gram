#ifndef GRAM_TOURNAMENT_SELECTOR
#define GRAM_TOURNAMENT_SELECTOR

#include <memory>

#include "gram/individual/Individual.h"
#include "gram/operator/selector/comparer/IndividualComparer.h"
#include "gram/population/Individuals.h"
#include "IndividualSelector.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
public:
  TournamentSelector(unsigned long tournamentSize, std::unique_ptr<NumberGenerator> numberGenerator,
                     std::unique_ptr<IndividualComparer> comparer);
  Individual& select(Individuals& individuals) override;

private:
  unsigned long tournamentSize;
  std::unique_ptr<NumberGenerator> numberGenerator;
  std::unique_ptr<IndividualComparer> comparer;
};
}

#endif
