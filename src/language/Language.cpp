#include <gram/language/Language.h>

using namespace gram::language;
using namespace gram::individual;

Language::Language(std::shared_ptr<Grammar> grammar, Mapper const &mapper)
    : grammar(grammar), mapper(mapper) {
  //
}

Phenotype Language::expand(Genotype genotype) const {
  return mapper.map(genotype);
}

std::string Language::serialize(gram::individual::Genotype genotype) const {
  return expand(genotype).serialize();
}
