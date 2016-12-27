#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(vector<shared_ptr<Individual>> individuals, shared_ptr<Generator> generator)
    : individuals(individuals), generator(generator) {
  //
}

double Population::bestFitness() const {
  return bestIndividual().fitness();
}

Individual& Population::bestIndividual() const {
  if (individuals.size() == 0) {
    throw logic_error("The population is empty.");
  }

  Individual& best = *individuals[0];
  double bestFitness = best.fitness();

  for (int i = 1; i < individuals.size(); i++) {
    Individual& individual = *individuals[i];
    double individualFitness = individual.fitness();

    if (individualFitness < bestFitness) {
      best = individual;
      bestFitness = individualFitness;
    }
  }

  return best;
}

void Population::process(const Processor& processor, int goal) {
  for (auto &individual : individuals) {
    individual->process(processor, goal);
  }
}

Population Population::successor() const {
  vector<shared_ptr<Individual>> successors = generator->generateSuccessor(individuals);

  return Population(successors, generator);
}

Individual& Population::operator[](unsigned long index) {
  return *individuals[index];
}
