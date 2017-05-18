#include "gram/population/reproducer/PassionateReproducer.h"

#include <algorithm>
#include <memory>

#include "gram/individual/Individual.h"
#include "gram/operator/crossover/Crossover.h"
#include "gram/operator/mutation/Mutation.h"
#include "gram/operator/selector/IndividualSelector.h"
#include "gram/population/Individuals.h"
#include "gram/population/reproducer/Reproducer.h"

using namespace gram;
using namespace std;

PassionateReproducer::PassionateReproducer(unique_ptr<IndividualSelector> selector, unique_ptr<Crossover> crossover,
                                           unique_ptr<Mutation> mutation)
    : selector(move(selector)), crossover(move(crossover)), mutation(move(mutation)) {
  //
}

Individuals PassionateReproducer::reproduce(Individuals& individuals) {
  unsigned long size = individuals.size();

  Individuals children;
  children.reserve(size);

  for (unsigned long i = 0; i < size; i++) {
    Individual child = createChild(individuals);

    children.addIndividual(child);
  }

  return children;
}

Individual PassionateReproducer::createChild(Individuals& individuals) {
  Individual& parent1 = selector->select(individuals);
  Individual& parent2 = selector->select(individuals);

  Individual child = parent1.mateWith(parent2, *crossover);

  child.mutate(*mutation);

  return child;
}
