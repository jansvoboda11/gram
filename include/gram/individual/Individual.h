#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <memory>

#include <gram/individual/crossover/Crossover.h>
#include <gram/individual/mutation/Mutation.h>
#include <gram/individual/Genotype.h>
#include <gram/language/Evaluator.h>
#include <gram/language/Mapper.h>

namespace gram {
// Forward declaration.
class Evaluator;
/**
 * Class.
 */
class Individual {
 public:
  Individual(const Individual& individual);
  Individual(const Genotype& genotype);
  Individual& operator=(const Individual& individual);
  virtual ~Individual() = default;
  Individual mateWith(const Individual& partner, const Crossover& crossover) const;
  void mutate(const Mutation& mutation);
  void evaluate(Evaluator& evaluator);
  std::string serialize(Mapper& mapper) const;
  virtual double getFitness() const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;
 private:
  Genotype genotype;
  double fitness;
};
}

#endif // GRAM_INDIVIDUAL
