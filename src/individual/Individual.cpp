#include <gram/individual/Individual.h>

using namespace gram::language;
using namespace gram::individual;

Individual::Individual(Genotype genotype, std::shared_ptr<Language> language)
    : genotype(genotype), language(language), phenotype(), fitness(-1.0) {
  phenotype = language->expand(genotype);
}

std::shared_ptr<Individual> Individual::mateWith(std::shared_ptr<Individual> partner, Crossover &crossover) {
  Genotype childGenotype = crossover.apply(genotype, partner->genotype);

  return std::make_shared<Individual>(childGenotype, language);
}

void Individual::mutate(Mutation &mutation) {
  genotype = mutation.apply(genotype);
}

std::string Individual::serialize() {
  return phenotype.serialize();
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
