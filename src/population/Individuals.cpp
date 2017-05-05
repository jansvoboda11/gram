#include "gram/population/Individuals.h"

#include <memory>

#include "gram/error/NoIndividuals.h"
#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"

using namespace gram;
using namespace std;

void Individuals::addIndividual(Individual individual) {
  individuals.push_back(individual);
}

const Individual& Individuals::bestIndividual(IndividualComparer& comparer) const {
  if (individuals.empty()) {
    throw NoIndividuals();
  }

  unsigned long individualsCount = individuals.size();
  unsigned long bestIndex = 0;

  for (unsigned long i = 0; i < individualsCount; i++) {
    if (comparer.isFirstFitter(individuals[i], individuals[bestIndex])) {
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

bool Individuals::empty() const {
  return individuals.empty();
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

vector<Individual>::const_iterator Individuals::begin() const {
  return individuals.begin();
}

vector<Individual>::const_iterator Individuals::end() const {
  return individuals.end();
}
