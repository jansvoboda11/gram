#ifndef GRAM_INDIVIDUAL_INDIVIDUAL
#define GRAM_INDIVIDUAL_INDIVIDUAL

#include <gram/evolution/operator/Crossover.h>
#include <gram/evolution/operator/Mutation.h>
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
  Individual(Genotype genotype, const gram::language::Language &language);
  virtual ~Individual() = default;
  std::shared_ptr<Individual> mateWith(std::shared_ptr<Individual> partner, gram::evolution::Crossover &crossover);
  void mutate(gram::evolution::Mutation &mutation);
  std::string serialize();
  void setFitness(double calculatedFitness);
  virtual double getFitness();
  bool operator==(const Individual &individual) const;
  bool operator!=(const Individual &individual) const;
 private:
  Genotype genotype;
  const gram::language::Language &language;
  Phenotype phenotype;
  double fitness;
};
}
}

#endif // GRAM_INDIVIDUAL_INDIVIDUAL
