#include "StringDiffEvaluator.h"

#include <memory>
#include <string>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Fitness.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/mapper/ContextFreeMapper.h"

using namespace gram;
using namespace std;

StringDiffEvaluator::StringDiffEvaluator(string desired) : desired(desired) {
  //
}

Fitness StringDiffEvaluator::evaluate(const Phenotype& phenotype) noexcept {
  try {
    return calculateFitness(phenotype);
  } catch (...) {
    return 1000;
  }
}

Fitness StringDiffEvaluator::calculateFitness(string program) {
  unsigned long shorter = min(desired.length(), program.length());
  unsigned long longer = max(desired.length(), program.length());

  Fitness fitness(longer - shorter);

  for (unsigned long i = 0; i < shorter; i++) {
    if (program[i] != desired[i]) {
      fitness += 1;
    }
  }

  return fitness;
}
