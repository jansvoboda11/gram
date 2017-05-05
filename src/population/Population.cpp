#include "gram/population/Population.h"

#include "gram/individual/Individual.h"
#include "gram/individual/comparer/HighFitnessComparer.h"
#include "gram/individual/comparer/IndividualComparer.h"
#include "gram/individual/comparer/LowFitnessComparer.h"
#include "gram/population/Individuals.h"
#include "gram/population/reproducer/Reproducer.h"

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Reproducer> reproducer, unsigned long generationNumber)
    : individuals(individuals), reproducer(reproducer), number(generationNumber) {
  //
}

unsigned long Population::generationNumber() const {
  return number;
}

const Individual& Population::bestIndividual(IndividualComparer& comparer) const {
  return individuals.bestIndividual(comparer);
}

const Individual& Population::individualWithLowestFitness() const {
  LowFitnessComparer comparer;

  return bestIndividual(comparer);
}

const Individual& Population::individualWithHighestFitness() const {
  HighFitnessComparer comparer;

  return bestIndividual(comparer);
}

double Population::bestFitness(IndividualComparer& comparer) const {
  return bestIndividual(comparer).fitness();
}

double Population::lowestFitness() const {
  LowFitnessComparer comparer;

  return bestFitness(comparer);
}

double Population::highestFitness() const {
  HighFitnessComparer comparer;

  return bestFitness(comparer);
}

Individual& Population::operator[](unsigned long index) {
  return individuals[index];
}

vector<Individual>::iterator Population::begin() {
  return individuals.begin();
}

vector<Individual>::iterator Population::end() {
  return individuals.end();
}

vector<Individual>::const_iterator Population::begin() const {
  return individuals.begin();
}

vector<Individual>::const_iterator Population::end() const {
  return individuals.end();
}

unsigned long Population::size() const {
  return individuals.size();
}

Population Population::reproduce() {
  Individuals successors = reproducer->reproduce(individuals);

  return Population(successors, reproducer, number + 1);
}
