#ifndef GRAM_LANGUAGE
#define GRAM_LANGUAGE

#include <gram/grammar/Grammar.h>
#include <gram/individual/Mapper.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class Language {
 public:
  Language(const gram::grammar::Grammar &grammar, const gram::individual::Mapper &mapper);
  gram::individual::Phenotype expand(gram::individual::Genotype genotype) const;
 private:
  const gram::grammar::Grammar &grammar;
  const gram::individual::Mapper &mapper;
};
}
}

#endif // GRAM_LANGUAGE
