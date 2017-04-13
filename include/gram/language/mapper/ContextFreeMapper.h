#ifndef GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
#define GRAM_LANGUAGE_CONTEXT_FREE_MAPPER

#include <gram/language/grammar/ContextFreeGrammar.h>
#include <gram/individual/Individual.h>

namespace gram {
/**
 * Class.
 */
class ContextFreeMapper : public Mapper {
 public:
  ContextFreeMapper(std::shared_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit);
  Phenotype map(const Genotype& genotype);
 private:
  std::shared_ptr<ContextFreeGrammar> grammar;
  unsigned long wrappingLimit;
  Phenotype& recursiveMap(Phenotype& phenotype,
                          const Rule& rule,
                          const Genotype& genotype,
                          unsigned long& geneNumber);
  bool isWrappingEvent(unsigned long geneIndex, unsigned long geneNumber);
  bool exceededWrappingLimit(const Genotype& genotype, unsigned long geneNumber);
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
