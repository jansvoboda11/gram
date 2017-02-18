#ifndef GRAM_EVOLUTION_ROULETTE_SELECTOR
#define GRAM_EVOLUTION_ROULETTE_SELECTOR

#include <memory>

#include <gram/individual/Individual.h>
#include <gram/population/selector/IndividualSelector.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class RouletteSelector : public IndividualSelector {
 public:
  RouletteSelector(std::unique_ptr<NumberGenerator> numberGenerator);
  Individual select(const Individuals& individuals) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_EVOLUTION_ROULETTE_SELECTOR
