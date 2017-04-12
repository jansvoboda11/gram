#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/individual/mutation/CodonMutation.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("codon mutation is not always performed", "[codon_mutation]") {
  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock, generate)).AlwaysReturn(false);
  auto boolGenerator = unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  CodonMutation mutation(move(boolGenerator), move(numberGenerator));

  Genotype genotype({1, 1, 1});

  REQUIRE(Genotype({1, 1, 1}) == mutation.apply(genotype));
}

TEST_CASE("codon mutation mutates a gene", "[codon_mutation]") {
  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock, generate)).Return(true).Return(false).Return(true);
  auto boolGenerator = unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(2).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  CodonMutation mutation(move(boolGenerator), move(numberGenerator));

  Genotype genotype({1, 1, 1});

  REQUIRE(Genotype({2, 1, 3}) == mutation.apply(genotype));
}
