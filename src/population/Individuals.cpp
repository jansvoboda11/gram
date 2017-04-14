#include <gram/population/Individuals.h>

using namespace gram;
using namespace std;

void Individuals::addIndividual(Individual individual) {
  individuals.push_back(individual);
}

Individual& Individuals::bestIndividual() {
  if (individuals.empty()) {
    throw logic_error("There are no individuals.");
  }

  Individual& bestIndividual = individuals[0];

  for (auto& individual : individuals) {
    if (individual.getFitness() < bestIndividual.getFitness()) {
      bestIndividual = individual;
    }
  }

  return bestIndividual;
}

Individual& Individuals::operator[](unsigned long index) {
  return individuals[index];
}

unsigned long Individuals::size() const {
  return individuals.size();
}

void Individuals::reserve(unsigned long count) {
  individuals.reserve(count);
}

vector<Individual>::iterator Individuals::begin() {
  return individuals.begin();
}

vector<Individual>::iterator Individuals::end() {
  return individuals.end();
}
