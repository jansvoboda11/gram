#include <gtest/gtest.h>

#include <gram/evolution/operator/Mutation.h>
#include <gram/util/BoolGeneratorMock.h>
#include <gram/util/NumberGeneratorMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

using ::testing::NiceMock;
using ::testing::Return;

TEST(mutation_operator_test, test_it_does_not_always_mutate) {
  Genotype genotype{1, 1, 1};

  NiceMock<BoolGeneratorMock> boolGenerator;
  ON_CALL(boolGenerator, generate())
      .WillByDefault(Return(false));

  NiceMock<NumberGeneratorMock> numberGenerator;

  Mutation mutation(boolGenerator, numberGenerator);

  Genotype mutatedGenotype = mutation.apply(genotype);

  Genotype expectedGenotype{1, 1, 1};
  ASSERT_EQ(expectedGenotype, mutatedGenotype);
}

TEST(mutation_operator_test, test_it_mutates_one_gene) {
  Genotype genotype{1, 1, 1};

  NiceMock<BoolGeneratorMock> boolGenerator;
  ON_CALL(boolGenerator, generate())
      .WillByDefault(Return(true));

  NiceMock<NumberGeneratorMock> numberGenerator;
  EXPECT_CALL(numberGenerator, generate())
      .WillOnce(Return(2))
      .WillOnce(Return(3));

  Mutation mutation(boolGenerator, numberGenerator);

  Genotype mutatedGenotype = mutation.apply(genotype);

  Genotype expectedGenotype{1, 1, 3};
  ASSERT_EQ(expectedGenotype, mutatedGenotype);
}
