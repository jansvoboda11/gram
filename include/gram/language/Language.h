#ifndef GRAM_LANGUAGE
#define GRAM_LANGUAGE

#include <gram/language/Grammar.h>
#include <gram/individual/Mapper.h>

namespace gram {
/**
 * Class.
 */
class Language {
 public:
  Language(std::shared_ptr<Grammar> grammar, const Mapper &mapper);
  virtual ~Language() = default;
  virtual Phenotype expand(Genotype genotype) const;
 private:
  std::shared_ptr<Grammar> grammar;
  const Mapper &mapper;
};
}

#endif // GRAM_LANGUAGE
