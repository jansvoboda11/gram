#ifndef GRAM_LANGUAGE_MOCK
#define GRAM_LANGUAGE_MOCK

#include <gmock/gmock.h>

#include <gram/language/Language.h>

namespace gram {
namespace language {
/**
 * Mock.
 */
class LanguageMock : public Language {
 public:
  LanguageMock(gram::grammar::Grammar const &grammar, gram::individual::Mapper const &mapper) : Language(grammar, mapper) {};
  MOCK_METHOD1(expand, gram::individual::Phenotype(gram::individual::Genotype genotype));
};
}
}

#endif // GRAM_LANGUAGE_MOCK
