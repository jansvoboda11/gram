#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/language/Language.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(language_test, test_it_expands_genotype) {
  Mock<Grammar> grammarMock;
  Fake(Dtor(grammarMock));
  auto grammar = shared_ptr<Grammar>(&grammarMock.get());

  Terminal terminal("hello");
  Phenotype phenotype;
  phenotype.addTerminal(terminal);

  Mock<Mapper> mapperMock;
  When(Method(mapperMock, map)).Return(phenotype);

  Language language(grammar, mapperMock.get());

  ASSERT_EQ(phenotype, language.expand(Genotype({0, 1, 2})));
}
