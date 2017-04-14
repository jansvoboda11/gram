#ifndef GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
#define GRAM_LANGUAGE_CONTEXT_FREE_MAPPER

#include <gram/language/grammar/ContextFreeGrammar.h>
#include <gram/individual/Individual.h>

#include <stack>

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
  void pushOption(std::stack<Symbol*>& symbols, Option& option) const;
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
