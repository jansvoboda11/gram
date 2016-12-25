#ifndef GRAM_LANGUAGE
#define GRAM_LANGUAGE

#include <gram/language/Grammar.h>
#include <gram/individual/Mapper.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class Language {
 public:
  Language(std::shared_ptr<Grammar> grammar, const gram::individual::Mapper &mapper);
  virtual ~Language() = default;
  virtual gram::individual::Phenotype expand(gram::individual::Genotype genotype) const;
 private:
  std::shared_ptr<Grammar> grammar;
  const gram::individual::Mapper &mapper;
};
}
}

#endif // GRAM_LANGUAGE
