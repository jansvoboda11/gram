#include <gram/individual/operator/Mutation.h>

using namespace gram;
using namespace std;

Mutation::Mutation(unique_ptr<BoolGenerator> boolGenerator, unique_ptr<NumberGenerator> numberGenerator)
    : boolGenerator(move(boolGenerator)), numberGenerator(move(numberGenerator)) {
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
