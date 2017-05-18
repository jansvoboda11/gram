#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <memory>

#include "gram/individual/Genotype.h"
#include "gram/individual/Phenotype.h"
#include "gram/individual/crossover/Crossover.h"
#include "gram/individual/mutation/Mutation.h"
#include "gram/language/mapper/Mapper.h"

namespace gram {
/**
 * Class.
 */
class Individual {
public:
  Individual(const Individual& individual);
  Individual(const Genotype& genotype);
  Individual mateWith(const Individual& partner, Crossover& crossover) const;
  void mutate(Mutation& mutation);
  void assignFitness(double fitness);
  double fitness() const;
  bool hasFitnessCalculated() const;
  Phenotype serialize(Mapper& mapper) const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;

private:
  Genotype genotype;
  double fitnessScore;
  bool fitnessCalculated;
};
}

#endif // GRAM_INDIVIDUAL
