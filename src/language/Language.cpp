#include <gram/language/Language.h>

using namespace gram::language;
using namespace gram::grammar;
using namespace gram::individual;

Language::Language(Grammar const &grammar, Mapper const &mapper) : grammar(grammar), mapper(mapper) {
  //
}

Phenotype Language::expand(Genotype genotype) const {
  return mapper.map(genotype);
}
