#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>
#include <gram/individual/Genotype.h>
#include <gram/individual/Mapper.h>
#include <gram/individual/Phenotype.h>
#include <gram/language/Language.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Individual {
 public:
  Individual(Genotype genotype, std::shared_ptr<gram::language::Language> language);
  virtual ~Individual() = default;
  std::shared_ptr<Individual> mateWith(std::shared_ptr<Individual> partner, Crossover &crossover);
  void mutate(Mutation &mutation);
  std::string serialize();
  Genotype genotype();
  void setFitness(double calculatedFitness);
  virtual double getFitness();
  bool operator==(const Individual &individual) const;
  bool operator!=(const Individual &individual) const;
 private:
  Genotype genotype_;
  std::shared_ptr<gram::language::Language> language;
  Phenotype phenotype;
  double fitness;
};
}
}

#endif // GRAM_INDIVIDUAL
