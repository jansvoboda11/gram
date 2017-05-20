#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <memory>

#include "gram/individual/Fitness.h"
#include "gram/individual/Genotype.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/mapper/Mapper.h"
#include "gram/operator/crossover/Crossover.h"
#include "gram/operator/mutation/Mutation.h"

namespace gram {
/**
 * Class.
 */
class Individual {
public:
  Individual(Genotype genotype);
  Individual mateWith(const Individual& partner, Crossover& crossover) const;
  void mutate(Mutation& mutation);
  void assignFitness(Fitness fitness);
  Fitness fitness() const;
  bool hasFitnessCalculated() const;
  Phenotype serialize(Mapper& mapper) const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;

private:
  Genotype genotype;
  Fitness fitnessScore;
  bool fitnessCalculated;
};
}

#endif
