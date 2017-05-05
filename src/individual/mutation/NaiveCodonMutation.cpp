#include "gram/individual/mutation/NaiveCodonMutation.h"

#include <algorithm>

using namespace gram;
using namespace std;

NaiveCodonMutation::NaiveCodonMutation(unique_ptr<BoolGenerator> boolGenerator,
                                       unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
  //
}

Genotype NaiveCodonMutation::apply(Genotype genotype) {
  for (auto& codon : genotype) {
    if (boolGenerator->generate()) {
      codon = numberGenerator->generate();
    }
  }

  return genotype;
}
