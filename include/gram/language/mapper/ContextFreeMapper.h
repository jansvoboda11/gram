#ifndef GRAM_CONTEXT_FREE_MAPPER
#define GRAM_CONTEXT_FREE_MAPPER

#include <memory>
#include <stack>
#include <vector>

#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/grammar/ContextFreeGrammar.h"
#include "gram/language/mapper/Mapper.h"
#include "gram/language/symbol/Option.h"
#include "gram/language/symbol/Symbol.h"

namespace gram {
/**
 * Class.
 */
class ContextFreeMapper : public Mapper {
public:
  ContextFreeMapper(std::unique_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit);
  Phenotype map(const Genotype& genotype) override;

private:
  std::unique_ptr<ContextFreeGrammar> grammar;
  unsigned long wrappingLimit;
  std::vector<Symbol*> symbols; // does not hold any state
  void pushOption(Option& option);
};
}

#endif
