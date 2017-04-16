#include <gram/individual/Individual.h>

using namespace gram;
using namespace std;

Individual::Individual(const Individual& individual)
    : genotype(individual.genotype), fitnessScore(individual.fitnessScore) {
  //
}

Individual::Individual(const Genotype& genotype)
    : genotype(genotype), fitnessScore(-1.0) {
  //
}

Individual Individual::mateWith(const Individual& partner, Crossover& crossover) const {
  Genotype childGenotype = crossover.apply(genotype, partner.genotype);

  return Individual(childGenotype);
}

void Individual::mutate(Mutation& mutation) {
  genotype = mutation.apply(genotype);
}

void Individual::evaluate(Evaluator& evaluator) {
  fitnessScore = evaluator.evaluate(genotype);
}

string Individual::serialize(Mapper& mapper) const {
  return mapper.map(genotype);
}

double Individual::fitness() const {
  if (fitnessScore < 0.0) {
    throw logic_error("Fitness of the individual has not been calculated yet.");
  }

  return fitnessScore;
}

bool Individual::operator==(const Individual& individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual& individual) const {
  return !operator==(individual);
}
