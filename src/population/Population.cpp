#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Generator> generator)
    : individuals(individuals), generator(generator) {
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
  for (auto &individual : individuals) {
    individual->process(processor, goal);
  }
}

Population Population::successor() const {
  Individuals successors = generator->generateSuccessor(individuals);

  return Population(successors, generator);
}
