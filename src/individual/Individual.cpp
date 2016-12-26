#include <gram/individual/Individual.h>

using namespace gram;
using namespace std;

Individual::Individual(Individual const& individual)
    : genotype(individual.genotype), language(individual.language), fitness_(individual.fitness_) {
  //
}

Individual::Individual(Genotype const& genotype, shared_ptr<Language> language)
    : genotype(genotype), language(language), fitness_(-1.0) {
  //
}

Individual& Individual::operator=(const Individual& individual) {
  genotype = individual.genotype;
  language = individual.language;
  fitness_ = individual.fitness_;

  return *this;
}

Individual Individual::mateWith(Individual const& partner, Crossover const& crossover) const {
  Genotype childGenotype = crossover.apply(genotype, partner.genotype);

  return Individual(childGenotype, language);
}

void Individual::mutate(Mutation const& mutation) {
  genotype = mutation.apply(genotype);
}

void Individual::process(Processor const& processor, int goal) {
  string program = serialize();

  double fitness = processor.process(program, goal);

  if (fitness < 0) {
    throw logic_error("Fitness cannot be negative.");
  }

  fitness_ = fitness;
}

string Individual::serialize() const {
  Phenotype phenotype = language->expand(genotype);

  return phenotype.serialize();
}

double Individual::fitness() const {
  if (fitness_ < 0) {
    throw logic_error("Fitness of the individual has not been calculated yet.");
  }

  return fitness_;
}

bool Individual::operator==(const Individual& individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual& individual) const {
  return !operator==(individual);
}
