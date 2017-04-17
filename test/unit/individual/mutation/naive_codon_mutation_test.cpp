#include "gram/individual/mutation/NaiveCodonMutation.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("naive codon mutation is not always performed", "[naive_codon_mutation]") {
  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock, generate)).AlwaysReturn(false);
  auto boolGenerator = unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  NaiveCodonMutation mutation(move(boolGenerator), move(numberGenerator));

  Genotype genotype({1, 1, 1});

  REQUIRE(Genotype({1, 1, 1}) == mutation.apply(genotype));
}

TEST_CASE("naive codon mutation mutates a gene", "[naive_codon_mutation]") {
  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock, generate)).Return(true).Return(false).Return(true);
  auto boolGenerator = unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(2).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  NaiveCodonMutation mutation(move(boolGenerator), move(numberGenerator));

  Genotype genotype({1, 1, 1});

  REQUIRE(Genotype({2, 1, 3}) == mutation.apply(genotype));
}
