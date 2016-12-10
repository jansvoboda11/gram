#include <gram/population/Population.h>

#include <stdexcept>

using namespace gram::individual;
using namespace gram::population;

Population::Population() : individuals() {
  //
}

Population::Population(std::vector<std::shared_ptr<Individual>> individuals) : individuals(individuals) {
  //
}

Population::Population(std::initializer_list<std::shared_ptr<Individual>> individuals) : individuals{individuals} {
  //
}

std::shared_ptr<Individual> Population::bestIndividual() {
  if (individuals.size() == 0) {
    throw std::logic_error("The population is empty.");
  }

  std::shared_ptr<Individual> best = individuals[0];

  for (int i = 1; i < individuals.size(); i++) {
    if (individuals[i]->getFitness() < best->getFitness()) {
      best = individuals[i];
    }
  }

  return best;
}

void Population::addIndividual(std::shared_ptr<Individual> individual) {
  individuals.push_back(individual);
}

unsigned long Population::size() {
  return individuals.size();
}

std::shared_ptr<Individual> Population::operator[](unsigned long index) {
  return individuals[index];
}

std::vector<std::shared_ptr<Individual>>::iterator Population::begin() noexcept {
  return individuals.begin();
}

std::vector<std::shared_ptr<Individual>>::iterator Population::end() noexcept {
  return individuals.end();
}
