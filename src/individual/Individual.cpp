#include <gram/individual/Individual.h>

using namespace gram;
using namespace std;

Individual::Individual(Genotype genotype, shared_ptr<Language> language)
    : genotype(genotype), language(language), fitness_(-1.0) {
  //
}

shared_ptr<Individual> Individual::mateWith(shared_ptr<Individual> partner, Crossover &crossover) {
  Genotype childGenotype = crossover.apply(genotype, partner->genotype);

  return make_shared<Individual>(childGenotype, language);
}

void Individual::mutate(Mutation &mutation) {
  genotype = mutation.apply(genotype);
}

void Individual::process(shared_ptr<Processor> processor, int goal) {
  string program = serialize();

  double fitness = processor->process(program, goal);

  if (fitness < 0) {
    throw logic_error("Fitness cannot be negative.");
  }

  fitness_ = fitness;
}

string Individual::serialize() {
  Phenotype phenotype = language->expand(genotype);

  return phenotype.serialize();
}

double Individual::fitness() {
  if (fitness_ < 0) {
    throw logic_error("Fitness of the individual has not been calculated yet.");
  }

  return fitness_;
}

bool Individual::operator==(const Individual &individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual &individual) const {
  return !operator==(individual);
}
