#include <gram/language/Language.h>

using namespace gram;
using namespace std;

Language::Language(shared_ptr<Grammar> grammar, unique_ptr<Mapper> mapper)
    : grammar(grammar), mapper(move(mapper)) {
  //
}

Phenotype Language::expand(Genotype genotype) const {
  return mapper->map(genotype);
}
