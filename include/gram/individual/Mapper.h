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
  Mapper(Genotype genotype, gram::grammar::Grammar grammar);
  Phenotype map();
 private:
  Phenotype phenotype;
  Genotype genotype;
  gram::grammar::Grammar grammar;
  int geneCount;
  Phenotype recursiveMap(gram::grammar::Rule rule);
};
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
