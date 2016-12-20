#include <gram/individual/Individual.h>

using namespace gram::grammar;
using namespace gram::individual;

Individual::Individual(Genotype genotype) : genotype(genotype), phenotype(), fitness(-1.0) {
  //
}

void Individual::map(Mapper mapper) {
  phenotype = mapper.map(genotype);
}

Genotype Individual::getGenotype() {
  return genotype;
}

Phenotype Individual::getPhenotype() {
  return phenotype;
}

void Individual::setGenotype(Genotype newGenotype) {
  genotype = newGenotype;
}

void Individual::setFitness(double calculatedFitness) {
  if (calculatedFitness < 0) {
    throw std::logic_error("Fitness of an individual cannot be negative.");
  }

  fitness = calculatedFitness;
}

double Individual::getFitness() {
  if (fitness < 0) {
    throw std::logic_error("Fitness of the individual has not been calculated yet.");
  }

  return fitness;
}

bool Individual::operator==(const Individual &individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual &individual) const {
  return !operator==(individual);
}
