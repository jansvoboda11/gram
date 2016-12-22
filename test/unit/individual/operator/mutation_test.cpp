#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/operator/Mutation.h>

using namespace gram::individual;
using namespace gram::util;

using namespace fakeit;

TEST(mutation_operator_test, test_it_does_not_always_mutate) {
  Genotype genotype{1, 1, 1};

  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock,generate)).Return(false);

  auto boolGenerator = std::unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mutation mutation(std::move(boolGenerator), std::move(numberGenerator));

  Genotype mutatedGenotype = mutation.apply(genotype);

  Genotype expectedGenotype{1, 1, 1};
  ASSERT_EQ(expectedGenotype, mutatedGenotype);
}

TEST(mutation_operator_test, test_it_mutates_one_gene) {
  Genotype genotype{1, 1, 1};

  Mock<BoolGenerator> boolGeneratorMock;
  Fake(Dtor(boolGeneratorMock));
  When(Method(boolGeneratorMock,generate)).Return(true);

  auto boolGenerator = std::unique_ptr<BoolGenerator>(&boolGeneratorMock.get());

  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(2).Return(3);

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mutation mutation(std::move(boolGenerator), std::move(numberGenerator));

  Genotype mutatedGenotype = mutation.apply(genotype);

  Genotype expectedGenotype{1, 1, 3};
  ASSERT_EQ(expectedGenotype, mutatedGenotype);
}
