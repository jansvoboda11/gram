#include <catch.hpp>
#include <fakeit.hpp>

#include <gram/individual/mutation/FastCodonMutation.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST_CASE("fast codon mutation mutates single codon in genotype", "[fast_codon_mutation]") {
  Mock<BernoulliDistributionStepGenerator> stepGeneratorMock;
  Fake(Dtor(stepGeneratorMock));
  When(Method(stepGeneratorMock, generateStep)).Return(2).Return(100);
  auto stepGenerator = unique_ptr<BernoulliDistributionStepGenerator>(&stepGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  FastCodonMutation mutation(move(stepGenerator), move(numberGenerator));

  REQUIRE(mutation.apply(Genotype{0, 0, 0, 0}) == Genotype({0, 0, 1, 0}));
}

TEST_CASE("fast codon mutation mutates a series of genotypes", "[fast_codon_mutation]") {
  Mock<BernoulliDistributionStepGenerator> stepGeneratorMock;
  Fake(Dtor(stepGeneratorMock));
  When(Method(stepGeneratorMock, generateStep)).Return(6).Return(3).Return(100);
  auto stepGenerator = unique_ptr<BernoulliDistributionStepGenerator>(&stepGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).AlwaysReturn(1);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  FastCodonMutation mutation(move(stepGenerator), move(numberGenerator));

  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 0, 0}));
  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 1, 0}));
  REQUIRE(mutation.apply(Genotype({0, 0, 0, 0})) == Genotype({0, 0, 1, 0}));
}
