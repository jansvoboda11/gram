#include <gram/population/Individuals.h>

using namespace gram;
using namespace std;

void Individuals::addIndividual(Individual individual) {
  individuals.push_back(individual);
}

const Individual& Individuals::bestIndividual() const {
  if (individuals.empty()) {
    throw logic_error("There are no individuals.");
  }

  unsigned long individualsCount = individuals.size();
  unsigned long bestIndex = 0;

  for (unsigned long i = 0; i < individualsCount; i++) {
    if (individuals[i].fitness() < individuals[bestIndex].fitness()) {
      bestIndex = i;
    }
  }

  return individuals[bestIndex];
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
