#ifndef GRAM_LANGUAGE
#define GRAM_LANGUAGE

#include <gram/individual/Mapper.h>
#include <gram/language/Grammar.h>

namespace gram {
/**
 * Class.
 */
class Language {
 public:
  Language(std::shared_ptr<Grammar> grammar, std::unique_ptr<Mapper> mapper);
  virtual ~Language() = default;
  virtual Phenotype expand(Genotype genotype) const;
 private:
  std::shared_ptr<Grammar> grammar;
  std::unique_ptr<Mapper> mapper;
};
}

#endif // GRAM_LANGUAGE
