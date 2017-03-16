#include <gram/individual/Individual.h>

using namespace gram;
using namespace std;

Individual::Individual(const Individual& individual)
    : genotype(individual.genotype), grammar(individual.grammar), fitness_(individual.fitness_) {
  //
}

Individual::Individual(const Genotype& genotype, shared_ptr<Grammar> grammar)
    : genotype(genotype), grammar(grammar), fitness_(-1.0) {
  //
}

Individual& Individual::operator=(const Individual& individual) {
  genotype = individual.genotype;
  grammar = individual.grammar;
  fitness_ = individual.fitness_;

  return *this;
}

Individual Individual::mateWith(const Individual& partner, const Crossover& crossover) const {
  Genotype childGenotype = crossover.apply(genotype, partner.genotype);

  return Individual(childGenotype, grammar);
}

void Individual::mutate(const Mutation& mutation) {
  genotype = mutation.apply(genotype);
}

void Individual::evaluate(Evaluator& evaluator) {
  string program = serialize();

  double fitness = evaluator.evaluate(program);

  if (fitness < 0.0) {
    throw logic_error("Fitness cannot be negative.");
  }

  fitness_ = fitness;
}

string Individual::serialize() const {
  Phenotype phenotype = grammar->expand(genotype);

  return phenotype.serialize();
}

double Individual::fitness() const {
  if (fitness_ < 0.0) {
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
