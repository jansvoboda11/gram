#include <gram/population/Population.h>

#include <stdexcept>

using namespace gram::individual;
using namespace gram::population;

Population::Population() : individuals() {
  //
}

Population::Population(std::vector<Individual> individuals) : individuals(individuals) {
  //
}

Population::Population(std::initializer_list<Individual> individuals) : individuals{individuals} {
  //
}

Individual &Population::bestIndividual() {
  if (individuals.size() == 0) {
    throw std::logic_error("The population is empty.");
  }

  Individual &best = individuals[0];

  for (int i = 1; i < individuals.size(); i++) {
    if (individuals[i].getFitness() < best.getFitness()) {
      best = individuals[i];
    }
  }

  return best;
}

void Population::addIndividual(Individual individual) {
  individuals.push_back(individual);
}

unsigned long Population::size() {
  return individuals.size();
}

gram::individual::Individual &Population::operator[](unsigned long index) {
  return individuals[index];
}

std::vector<Individual>::iterator Population::begin() noexcept {
  return individuals.begin();
}

std::vector<Individual>::iterator Population::end() noexcept {
  return individuals.end();
}
