#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Reproducer> reproducer)
    : individuals(individuals), reproducer(reproducer) {
  //
}

double Population::bestFitness() const {
  return bestIndividual().fitness();
}

Individual& Population::bestIndividual() const {
  return individuals.bestIndividual();
}

Individual& Population::operator[](unsigned long index) const {
  return individuals[index];
}

unsigned long Population::size() const {
  return individuals.size();
}

void Population::process(const Processor& processor, int goal) {
  for (auto& individual : individuals) {
    individual->process(processor, goal);
  }
}

Population Population::reproduce() const {
  Individuals successors = reproducer->reproduce(individuals);

  return Population(successors, reproducer);
}
