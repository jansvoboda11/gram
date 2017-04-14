#include <gram/population/selector/RouletteSelector.h>

using namespace gram;
using namespace std;

RouletteSelector::RouletteSelector(unique_ptr<NumberGenerator> numberGenerator)
    : numberGenerator(move(numberGenerator)) {
  //
}

Individual& RouletteSelector::select(Individuals& individuals) {
  // todo: implementation

  return individuals[0];
}
