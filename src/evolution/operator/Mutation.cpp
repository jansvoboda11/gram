#include <gram/evolution/operator/Mutation.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

Mutation::Mutation(std::unique_ptr<BoolGenerator> boolGenerator, std::unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(std::move(boolGenerator)), numberGenerator(std::move(numberGenerator)) {
  //
}

Genotype Mutation::apply(Genotype genotype) {
  if (!boolGenerator->generate()) {
    return genotype;
  }

  unsigned long index = numberGenerator->generate() % genotype.size();
  unsigned long value = numberGenerator->generate();

  genotype[index] = value;

  return genotype;
}
