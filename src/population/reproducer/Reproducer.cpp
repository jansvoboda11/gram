#include <gram/population/reproducer/Reproducer.h>

using namespace gram;
using namespace std;

Reproducer::Reproducer(unique_ptr<IndividualSelector> selector,
                       unique_ptr<Crossover> crossover,
                       unique_ptr<Mutation> mutation)
    : selector(move(selector)), crossover(move(crossover)), mutation(move(mutation)) {
  //
}

Individuals Reproducer::reproduce(const Individuals& individuals) const {
  unsigned long size = individuals.size();
  
  Individuals children;
  children.reserve(size);

  for (unsigned long i = 0; i < size - 1; i++) {
    Individual parent1 = selector->select(individuals);
    Individual parent2 = selector->select(individuals);

    while (parent2 == parent1) {
      parent2 = selector->select(individuals);
    }

    Individual child = parent1.mateWith(parent2, *crossover);
    children.addIndividual(make_shared<Individual>(child));
  }

  Individual best = individuals.bestIndividual();
  children.addIndividual(make_shared<Individual>(best));

  for (auto &child : children) {
    child->mutate(*mutation);
  }

  return children;
}
