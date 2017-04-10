#include <gram/population/Individuals.h>

using namespace gram;
using namespace std;

Individuals::Individuals() {
  //
}

void Individuals::addIndividual(shared_ptr<Individual> individual) {
  individuals.push_back(individual);
}

Individual& Individuals::bestIndividual() const {
  if (individuals.empty()) {
    throw logic_error("There are no individuals.");
  }

  shared_ptr<Individual> bestIndividual = individuals[0];

  for (auto& individual : individuals) {
    if (individual->getFitness() < bestIndividual->getFitness()) {
      bestIndividual = individual;
    }
  }

  return *bestIndividual;
}

Individual& Individuals::operator[](unsigned long index) const {
  return *individuals[index];
}

unsigned long Individuals::size() const {
  return individuals.size();
}

void Individuals::reserve(unsigned long count) {
  individuals.reserve(count);
}

vector<shared_ptr<Individual>>::iterator Individuals::begin() {
  return individuals.begin();
}

vector<shared_ptr<Individual>>::iterator Individuals::end() {
  return individuals.end();
}
