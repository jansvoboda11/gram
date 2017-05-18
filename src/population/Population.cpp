#include "gram/population/Population.h"

#include "gram/individual/Individual.h"
#include "gram/operator/selector/comparer/HighFitnessComparer.h"
#include "gram/operator/selector/comparer/IndividualComparer.h"
#include "gram/operator/selector/comparer/LowFitnessComparer.h"
#include "gram/population/Individuals.h"
#include "gram/population/reproducer/Reproducer.h"

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, unique_ptr<Reproducer> reproducer, unsigned long generationNumber)
    : individuals(individuals), reproducer(move(reproducer)), number(generationNumber) {
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

Individuals& Population::allIndividuals() {
  return individuals;
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

void Population::reproduce() {
  individuals = reproducer->reproduce(individuals);

  number += 1;
}
