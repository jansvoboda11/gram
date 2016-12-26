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
  Fake(Dtor(mapperMock));
  When(Method(mapperMock, map)).Return(phenotype);
  unique_ptr<Mapper> mapper(&mapperMock.get());

  Language language(grammar, move(mapper));

  ASSERT_EQ(phenotype, language.expand(Genotype({0, 1, 2})));
}
