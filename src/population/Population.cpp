#include <gram/population/Population.h>

using namespace gram::individual;
using namespace gram::population;

Population::Population(std::vector<std::shared_ptr<Individual>> individuals, std::shared_ptr<Generator> generator)
    : individuals_(individuals), generator_(generator) {
  //
}

double Population::bestFitness() {
  return 0.0;
}

std::shared_ptr<Individual> Population::bestIndividual() {
  if (individuals_.size() == 0) {
    throw std::logic_error("The population is empty.");
  }

  std::shared_ptr<Individual> best = individuals_[0];
  double bestFitness = individuals_[0]->fitness();

  for (int i = 1; i < individuals_.size(); i++) {
    std::shared_ptr<Individual> individual = individuals_[i];
    double individualFitness = individual->fitness();

    if (individualFitness < bestFitness) {
      best = individuals_[i];
      bestFitness = individualFitness;
    }
  }

  return best;
}

void Population::process(std::shared_ptr<Processor> processor, int goal) {
  for (auto &individual : individuals_) {
    individual->process(processor, goal);
  }
}

Population Population::successor() {
  std::vector<std::shared_ptr<gram::individual::Individual>> individuals = generator_->generateSuccessor(individuals_);

  return Population(individuals, generator_);
}

std::shared_ptr<Individual> &Population::operator[](unsigned long index) {
  return individuals_[index];
}
