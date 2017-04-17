#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <memory>
#include <string>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Genotype.h"
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
  virtual ~Individual() = default;
  Individual mateWith(const Individual& partner, Crossover& crossover) const;
  void mutate(Mutation& mutation);
  void evaluate(Evaluator& evaluator);
  virtual double fitness() const;
  virtual double hasFitnessCalculated() const;
  std::string serialize(Mapper& mapper) const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;
 private:
  Genotype genotype;
  double fitnessScore;
  bool fitnessCalculated;
};
}

#endif // GRAM_INDIVIDUAL
