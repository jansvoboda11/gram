#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(vector<shared_ptr<Individual>> individuals, shared_ptr<Generator> generator)
    : individuals_(individuals), generator_(generator) {
  //
}

double Population::bestFitness() const {
  return bestIndividual()->fitness();
}

shared_ptr<Individual> Population::bestIndividual() const {
  if (individuals_.size() == 0) {
    throw logic_error("The population is empty.");
  }

  shared_ptr<Individual> best = individuals_[0];
  double bestFitness = individuals_[0]->fitness();

  for (int i = 1; i < individuals_.size(); i++) {
    shared_ptr<Individual> individual = individuals_[i];
    double individualFitness = individual->fitness();

    if (individualFitness < bestFitness) {
      best = individuals_[i];
      bestFitness = individualFitness;
    }
  }

  return best;
}

void Population::process(Processor const& processor, int goal) {
  for (auto &individual : individuals_) {
    individual->process(processor, goal);
  }
}

Population Population::successor() const {
  vector<shared_ptr<Individual>> individuals = generator_->generateSuccessor(individuals_);

  return Population(individuals, generator_);
}

shared_ptr<Individual> &Population::operator[](unsigned long index) {
  return individuals_[index];
}
