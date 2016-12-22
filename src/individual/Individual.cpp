#include <gram/individual/Individual.h>

using namespace gram::language;
using namespace gram::individual;

Individual::Individual(Genotype genotype, std::shared_ptr<Language> language)
    : genotype_(genotype), language(language), fitness(-1.0) {
  //
}

std::shared_ptr<Individual> Individual::mateWith(std::shared_ptr<Individual> partner, Crossover &crossover) {
  Genotype childGenotype = crossover.apply(genotype_, partner->genotype_);

  return std::make_shared<Individual>(childGenotype, language);
}

void Individual::mutate(Mutation &mutation) {
  genotype_ = mutation.apply(genotype_);
}

std::string Individual::serialize() {
  return language->serialize(genotype_);
}

Genotype Individual::genotype() {
  return genotype_;
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
  return genotype_ == individual.genotype_;
}

bool Individual::operator!=(const Individual &individual) const {
  return !operator==(individual);
}
