#ifndef GRAM_EVOLUTION_SELECTOR_TOURNAMENT
#define GRAM_EVOLUTION_SELECTOR_TOURNAMENT

#include <memory>

#include <gram/individual/Individual.h>
#include <gram/population/selector/IndividualSelector.h>

namespace gram {
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
 public:
  TournamentSelector(std::unique_ptr<NumberGenerator> generator);
  std::shared_ptr<Individual> select(std::vector<std::shared_ptr<Individual>> individuals);
 private:
  std::unique_ptr<NumberGenerator> generator;
};
}

#endif // GRAM_EVOLUTION_SELECTOR_TOURNAMENT
