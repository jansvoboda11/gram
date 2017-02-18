#include <gram/individual/mutation/NumberMutation.h>

using namespace gram;
using namespace std;

NumberMutation::NumberMutation(unique_ptr<BoolGenerator> boolGenerator, unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
  //
}

Genotype NumberMutation::apply(Genotype genotype) const {
  if (!boolGenerator->generate()) {
    return genotype;
  }

  unsigned long index = numberGenerator->generate() % genotype.size();
  unsigned long value = numberGenerator->generate();

  genotype[index] = value;

  return genotype;
}
