#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <gram/individual/Genotype.h>
#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>
#include <gram/language/Language.h>
#include <gram/individual/processor/Processor.h>

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
  void process(std::shared_ptr<gram::individual::Processor> processor, int goal);
  std::string serialize();
  Genotype genotype();
  virtual double fitness();
  bool operator==(const Individual &individual) const;
  bool operator!=(const Individual &individual) const;
 private:
  Genotype genotype_;
  std::shared_ptr<gram::language::Language> language;
  double fitness_;
};
}
}

#endif // GRAM_INDIVIDUAL
