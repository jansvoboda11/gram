#ifndef GRAM_INDIVIDUAL_MAPPER
#define GRAM_INDIVIDUAL_MAPPER

#include <gram/grammar/Grammar.h>
#include <gram/individual/Genotype.h>
#include <gram/individual/Phenotype.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Mapper {
 public:
  Mapper(std::shared_ptr<gram::grammar::Grammar> grammar);
  virtual Phenotype map(Genotype genotype) const;
 private:
  std::shared_ptr<gram::grammar::Grammar> grammar;
  Phenotype &recursiveMap(Phenotype &phenotype,
                          std::shared_ptr<gram::grammar::NonTerminal> nonTerminal,
                          Genotype genotype,
                          int geneCount) const;
};
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
