#ifndef GRAM_INDIVIDUAL_MAPPER
#define GRAM_INDIVIDUAL_MAPPER

#include <gram/language/Grammar.h>
#include <gram/individual/Genotype.h>
#include <gram/individual/Phenotype.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Mapper {
 public:
  Mapper(std::shared_ptr<gram::language::Grammar> grammar);
  virtual Phenotype map(Genotype genotype) const;
 private:
  std::shared_ptr<gram::language::Grammar> grammar;
  Phenotype &recursiveMap(Phenotype &phenotype,
                          std::shared_ptr<gram::language::NonTerminal> nonTerminal,
                          Genotype genotype,
                          int geneCount) const;
};
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
