#include <gram/individual/mutation/CodonMutation.h>

using namespace gram;
using namespace std;

CodonMutation::CodonMutation(unique_ptr<BoolGenerator> boolGenerator, unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
  //
}

Genotype CodonMutation::apply(Genotype genotype) {
  for (auto& gene : genotype) {
    if (boolGenerator->generate()) {
      gene = numberGenerator->generate();
    }
  }

  return genotype;
}
