#include "gram/operator/mutation/CodonMutation.h"

#include <algorithm>

using namespace gram;
using namespace std;

CodonMutation::CodonMutation(unique_ptr<BernoulliStepGenerator> stepGenerator,
                             unique_ptr<NumberGenerator> numberGenerator)
    : stepGenerator(move(stepGenerator)), numberGenerator(move(numberGenerator)),
      step(this->stepGenerator->generateStep()) {
  //
}

Genotype CodonMutation::apply(Genotype genotype) {
  unsigned long currentCodon = 0;
  unsigned long codonCount = genotype.size();

  while (currentCodon + step < codonCount) {
    currentCodon += step;

    genotype[currentCodon] = numberGenerator->generate();

    currentCodon += 1;

    step = stepGenerator->generateStep();
  }

  step -= codonCount - currentCodon;

  return genotype;
}
