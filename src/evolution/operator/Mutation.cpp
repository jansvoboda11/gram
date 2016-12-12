#include <gram/evolution/operator/Mutation.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

Mutation::Mutation(BoolGenerator &boolGenerator, NumberGenerator &numberGenerator)
    : boolGenerator(boolGenerator), numberGenerator(numberGenerator) {
  //
}

Genotype Mutation::apply(Genotype genotype) {
  if (!boolGenerator.generate()) {
    return genotype;
  }

  unsigned long index = numberGenerator.generate();
  unsigned long value = numberGenerator.generate();

  genotype[index] = value;

  return genotype;
}
