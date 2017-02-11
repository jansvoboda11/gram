#include <gram/population/selector/RouletteSelector.h>

using namespace gram;
using namespace std;

RouletteSelector::RouletteSelector(unique_ptr<NumberGenerator> numberGenerator)
    : numberGenerator(move(numberGenerator)) {
  //
}

Individual RouletteSelector::select(const Individuals& individuals) const {
  // todo: implementation

  return individuals[0];
}
