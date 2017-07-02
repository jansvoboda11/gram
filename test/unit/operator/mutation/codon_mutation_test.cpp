#include "gram/operator/mutation/CodonMutation.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("codon mutation mutates single codon in genotype", "[codon_mutation]") {
  Mock<BernoulliStepGenerator> stepGeneratorMock;
  Fake(Dtor(stepGeneratorMock));
  When(Method(stepGeneratorMock, generateStep)).Return(2).Return(100);
  auto stepGenerator = unique_ptr<BernoulliStepGenerator>(&stepGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  CodonMutation mutation(move(stepGenerator), move(numberGenerator));

  REQUIRE(mutation.apply(Genotype{0, 0, 0, 0}) == Genotype({0, 0, 1, 0}));
}

TEST_CASE("codon mutation mutates a series of genotypes", "[codon_mutation]") {
  Mock<BernoulliStepGenerator> stepGeneratorMock;
  Fake(Dtor(stepGeneratorMock));
  When(Method(stepGeneratorMock, generateStep)).Return(6).Return(3).Return(100);
  auto stepGenerator = unique_ptr<BernoulliStepGenerator>(&stepGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).AlwaysReturn(1);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  CodonMutation mutation(move(stepGenerator), move(numberGenerator));

  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 0, 0}));
  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 1, 0}));
  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 1, 0}));
}
