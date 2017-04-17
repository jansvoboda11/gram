#include "gram/individual/mutation/CodonMutation.h"

#include <algorithm>

using namespace gram;
using namespace std;

CodonMutation::CodonMutation(unique_ptr<BoolGenerator> boolGenerator, unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
  //
}

Genotype CodonMutation::apply(Genotype genotype) {
  for (auto& codon : genotype) {
    if (boolGenerator->generate()) {
      codon = numberGenerator->generate();
    }
  }

  return genotype;
}
