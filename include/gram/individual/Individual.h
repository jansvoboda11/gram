#ifndef GRAM_INDIVIDUAL
#define GRAM_INDIVIDUAL

#include <gram/individual/operator/Crossover.h>
#include <gram/individual/operator/Mutation.h>
#include <gram/individual/processor/Processor.h>
#include <gram/individual/Genotype.h>
#include <gram/language/Language.h>

namespace gram {
/**
 * Class.
 */
class Individual {
 public:
  Individual(Individual const& individual);
  Individual(Genotype const& genotype, std::shared_ptr<Language> language);
  Individual& operator=(const Individual& individual);
  virtual ~Individual() = default;
  Individual mateWith(Individual const& partner, Crossover const& crossover) const;
  void mutate(Mutation const& mutation);
  void process(Processor const& processor, int goal);
  std::string serialize() const;
  virtual double fitness() const;
  bool operator==(const Individual& individual) const;
  bool operator!=(const Individual& individual) const;
 private:
  Genotype genotype;
  std::shared_ptr<Language> language;
  double fitness_;
};
}

#endif // GRAM_INDIVIDUAL
