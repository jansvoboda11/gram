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
  Mapper(gram::grammar::Grammar grammar);
  Phenotype map(Genotype genotype);
 private:
  gram::grammar::Grammar grammar;
  Phenotype phenotype;
  Phenotype recursiveMap(Genotype genotype, int geneCount, std::shared_ptr<gram::grammar::Rule> rule);
};
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
