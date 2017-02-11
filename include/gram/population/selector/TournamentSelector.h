#ifndef GRAM_EVOLUTION_TOURNAMENT_SELECTOR
#define GRAM_EVOLUTION_TOURNAMENT_SELECTOR

#include <memory>

#include <gram/individual/Individual.h>
#include <gram/population/selector/IndividualSelector.h>

namespace gram {
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
 public:
  TournamentSelector(std::unique_ptr<NumberGenerator> numberGenerator);
  Individual select(const Individuals& individuals) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_EVOLUTION_TOURNAMENT_SELECTOR
