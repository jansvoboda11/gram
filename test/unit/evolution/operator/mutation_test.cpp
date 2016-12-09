#include <gtest/gtest.h>

#include <gram/evolution/operator/Mutation.h>
#include <gram/util/BoolGeneratorMock.h>
#include <gram/util/NumberGeneratorMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

using ::testing::Return;

TEST(mutation_operator_test, test_it_does_not_always_mutate) {
  Genotype genotype{1, 1, 1};

  BoolGeneratorMock boolGenerator;
  EXPECT_CALL(boolGenerator, generate())
      .Times(1)
      .WillOnce(Return(false));

  NumberGeneratorMock numberGenerator;
  EXPECT_CALL(numberGenerator, generate())
      .Times(0);

  Mutation mutation(boolGenerator, numberGenerator);

  ASSERT_EQ(genotype, mutation.apply(genotype));
}

TEST(mutation_operator_test, test_it_mutates_one_gene) {
  Genotype genotype{1, 1, 1};
  Genotype expectedGenotype{1, 1, 3};

  BoolGeneratorMock boolGenerator;
  EXPECT_CALL(boolGenerator, generate())
      .Times(1)
      .WillOnce(Return(true));

  NumberGeneratorMock numberGenerator;
  EXPECT_CALL(numberGenerator, generate())
      .Times(2)
      .WillOnce(Return(2))
      .WillOnce(Return(3));

  Mutation mutation(boolGenerator, numberGenerator);

  ASSERT_EQ(expectedGenotype, mutation.apply(genotype));
}
