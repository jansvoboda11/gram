#include <gram/language/Language.h>

using namespace gram;
using namespace std;

Language::Language(shared_ptr<Grammar> grammar, Mapper const &mapper)
    : grammar(grammar), mapper(mapper) {
  //
}

Phenotype Language::expand(Genotype genotype) const {
  return mapper.map(genotype);
}
