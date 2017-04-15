#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <memory>

#include <gram/evaluation/Evaluator.h>
#include <gram/individual/crossover/Crossover.h>
#include <gram/individual/mutation/Mutation.h>
#include <gram/individual/Genotype.h>
#include <gram/language/mapper/Mapper.h>

namespace gram {
/**
 * Class.
 */
class Individual {
 public:
  Individual(const Individual& individual);
  Individual(const Genotype& genotype);
  Individual& operator=(const Individual& individual);
  virtual ~Individual() = default;
  Individual mateWith(const Individual& partner, Crossover& crossover) const;
  void mutate(Mutation& mutation);
  void evaluate(Evaluator& evaluator);
  std::string serialize(Mapper& mapper) const;
  virtual double fitness() const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;
 private:
  Genotype genotype;
  double fitnessScore;
};
}

#endif // GRAM_INDIVIDUAL
