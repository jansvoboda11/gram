#ifndef GRAM_EVOLUTION_SELECTOR_TOURNAMENT
#define GRAM_EVOLUTION_SELECTOR_TOURNAMENT

#include <memory>

#include <gram/population/selector/IndividualSelector.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
 public:
  TournamentSelector(std::unique_ptr<gram::util::NumberGenerator> generator);
  std::shared_ptr<gram::individual::Individual> select(gram::population::Population population);
 private:
  std::unique_ptr<gram::util::NumberGenerator> generator;
};
}
}

#endif // GRAM_EVOLUTION_SELECTOR_TOURNAMENT