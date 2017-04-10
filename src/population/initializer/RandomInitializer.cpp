#include <gram/population/initializer/RandomInitializer.h>

using namespace gram;
using namespace std;

RandomInitializer::RandomInitializer(unique_ptr<NumberGenerator> numberGenerator,
                                     shared_ptr<Grammar> grammar,
                                     unsigned long size)
    : numberGenerator(move(numberGenerator)), grammar(grammar), size(size) {
  //
}

Population RandomInitializer::initialize(unsigned long count, shared_ptr<Reproducer> reproducer) const {
  Individuals individuals;
  individuals.reserve(count);

  for (unsigned long i = 0; i < count; i++) {
    Genotype genotype = numberGenerator->generateMany(size);

    individuals.addIndividual(make_shared<Individual>(genotype, grammar));
  }

  return Population(individuals, reproducer, 0);
}
