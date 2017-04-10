#include <gram/individual/Individual.h>

using namespace gram;
using namespace std;

Individual::Individual(const Individual& individual)
    : genotype(individual.genotype), fitness(individual.fitness) {
  //
}

Individual::Individual(const Genotype& genotype)
    : genotype(genotype), fitness(-1.0) {
  //
}

Individual& Individual::operator=(const Individual& individual) {
  genotype = individual.genotype;
  fitness = individual.fitness;

  return *this;
}

Individual Individual::mateWith(const Individual& partner, const Crossover& crossover) const {
  Genotype childGenotype = crossover.apply(genotype, partner.genotype);

  return Individual(childGenotype);
}

void Individual::mutate(const Mutation& mutation) {
  genotype = mutation.apply(genotype);
}

void Individual::evaluate(Evaluator& evaluator) {
  fitness = evaluator.evaluate(*this);
}

std::string Individual::serialize(Mapper& mapper) const {
  Phenotype phenotype = mapper.map(genotype);

  return phenotype.serialize();
}

double Individual::getFitness() const {
  if (fitness < 0.0) {
    throw logic_error("Fitness of the individual has not been calculated yet.");
  }

  return fitness;
}

bool Individual::operator==(const Individual& individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual& individual) const {
  return !operator==(individual);
}
