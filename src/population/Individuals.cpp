#include <gram/population/Individuals.h>

using namespace gram;
using namespace std;

Individuals::Individuals() {
  //
}

Individuals::Individuals(initializer_list<shared_ptr<Individual>> individuals)
    : individuals(individuals) {
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
    if (individual->fitness() < bestIndividual->fitness()) {
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

vector<shared_ptr<Individual>>::iterator Individuals::begin() {
  return individuals.begin();
}

vector<shared_ptr<Individual>>::iterator Individuals::end() {
  return individuals.end();
}
