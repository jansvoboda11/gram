#ifndef GRAM_INDIVIDUAL_INDIVIDUAL
#define GRAM_INDIVIDUAL_INDIVIDUAL

#include <gram/individual/Genotype.h>
#include <gram/individual/Mapper.h>
#include <gram/individual/Phenotype.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Individual {
 public:
  Individual(Genotype genotype);
  void map(Mapper mapper);
  Genotype getGenotype();
  Phenotype getPhenotype();
  void setGenotype(Genotype newGenotype);
  void setFitness(double calculatedFitness);
  virtual double getFitness();
  bool operator==(const Individual &individual) const;
  bool operator!=(const Individual &individual) const;
 private:
  Genotype genotype;
  Phenotype phenotype;
  double fitness;
};
}
}

#endif // GRAM_INDIVIDUAL_INDIVIDUAL
