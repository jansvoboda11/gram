#ifndef GRAM_INDIVIDUAL_MAPPER
#define GRAM_INDIVIDUAL_MAPPER

#include "../../language/grammar/Grammar.h"
#include "../../language/grammar/Rule.h"
#include "Genotype.h"
#include "Phenotype.h"

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
class Mapper {
 public:
  Mapper(Genotype genotype, gram::language::grammar::Grammar grammar);
  Phenotype map();
 private:
  Phenotype phenotype;
  Genotype genotype;
  gram::language::grammar::Grammar grammar;
  int geneCount;
  Phenotype recursiveMap(gram::language::grammar::Rule rule);
};
}
}
}

#endif // GRAM_INDIVIDUAL_MAPPER
