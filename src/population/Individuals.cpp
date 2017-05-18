#include "gram/population/Individuals.h"

#include <memory>

#include "gram/error/NoIndividuals.h"
#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"

using namespace gram;
using namespace std;

Individuals::Individuals() : individuals({}) {
  //
}

Individuals::Individuals(std::initializer_list<Individual> individuals) : individuals(move(individuals)) {
  //
}

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

const Individual &Individuals::operator[](unsigned long index) const {
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

bool Individuals::operator==(const Individuals &second) const {
  if (size() != second.size()) {
    return false;
  }

  for (unsigned long i = 0; i < size(); i++) {
    if (operator[](i) != second[i]) {
      return false;
    }
  }

  return true;
}

bool Individuals::operator!=(const Individuals &second) const {
  return !operator==(second);
}
