#include <gram/individual/mutation/NumberMutation.h>

using namespace gram;
using namespace std;

NumberMutation::NumberMutation(unique_ptr<BoolGenerator> boolGenerator, unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
  //
}

Genotype NumberMutation::apply(Genotype genotype) const {
  for (auto &gene : genotype) {
    if (boolGenerator->generate()) {
      gene = numberGenerator->generate();
    }
  }

  return genotype;
}
