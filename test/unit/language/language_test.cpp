#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/language/Language.h>

using namespace gram::language;
using namespace gram::individual;

using namespace fakeit;

TEST(language_test, test_it_expands_genotype) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  auto grammar = std::shared_ptr<Grammar>(&grammarMock.get());

  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mock<Mapper> mapperMock;
  When(Method(mapperMock, map)).Return(phenotype);

  Language language(grammar, mapperMock.get());

  Phenotype expanded = language.expand(Genotype({0, 1, 2}));

  Verify(Method(mapperMock, map).Using(Genotype({0, 1, 2})));
  ASSERT_EQ(phenotype, expanded);
}

TEST(language_test, test_it_serializes_genotype) {
  //
}
