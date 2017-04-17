#include <gram/individual/Individual.h>

#include <gram/error/FitnessNotCalculated.h>

using namespace gram;
using namespace std;

Individual::Individual(const Individual& individual)
    : genotype(individual.genotype),
      fitnessScore(individual.fitnessScore),
      fitnessCalculated(individual.fitnessCalculated) {
  //
}

Individual::Individual(const Genotype& genotype)
    : genotype(genotype), fitnessScore(0.0), fitnessCalculated(false) {
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
  fitnessCalculated = true;
}

string Individual::serialize(Mapper& mapper) const {
  return mapper.map(genotype);
}

double Individual::fitness() const {
  if (!fitnessCalculated) {
    throw FitnessNotCalculated();
  }

  return fitnessScore;
}

double Individual::hasFitnessCalculated() const {
  return fitnessCalculated;
}

bool Individual::operator==(const Individual& individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual& individual) const {
  return !operator==(individual);
}
