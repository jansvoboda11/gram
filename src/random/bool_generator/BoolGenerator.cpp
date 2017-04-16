#include <gram/random/bool_generator/BoolGenerator.h>

#include <limits>

using namespace gram;
using namespace std;

BoolGenerator::BoolGenerator(unique_ptr<NumberGenerator> numberGenerator, double probability)
    : numberGenerator(move(numberGenerator)), probability(probability) {
  //
}

bool BoolGenerator::generate() const {
  unsigned long number = numberGenerator->generate();

  return number <= probability * numberGenerator->getMax();
}
