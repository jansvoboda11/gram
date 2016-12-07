#ifndef GRAM_EVOLUTION_SELECTOR_TOURNAMENT
#define GRAM_EVOLUTION_SELECTOR_TOURNAMENT

#include <gram/evolution/selector/IndividualSelector.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
 public:
  TournamentSelector(gram::population::Population population, gram::util::NumberGenerator &generator);
  gram::individual::Individual select();
};
}
}

#endif // GRAM_EVOLUTION_SELECTOR_TOURNAMENT
