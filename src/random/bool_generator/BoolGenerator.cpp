#include "gram/random/bool_generator/BoolGenerator.h"

#include <algorithm>

#include "gram/random/number_generator/NumberGenerator.h"
#include "gram/random/Probability.h"

using namespace gram;
using namespace std;

BoolGenerator::BoolGenerator(unique_ptr<NumberGenerator> numberGenerator, Probability probability)
    : numberGenerator(move(numberGenerator)), probability(probability) {
  //
}

bool BoolGenerator::generate() const {
  unsigned long number = numberGenerator->generate();

  return number <= probability.getValue() * numberGenerator->getMax();
}
