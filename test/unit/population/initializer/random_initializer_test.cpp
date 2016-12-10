#include <gtest/gtest.h>

#include <gram/population/initializer/RandomInitializer.h>
#include <gram/util/NumberGeneratorMock.h>

using namespace gram::population;
using namespace gram::individual;
using namespace gram::util;

using ::testing::Return;

TEST(random_initializer_test, test_it_initializes_individuals_with_random_genotype) {
  NumberGeneratorMock numberGenerator;
  EXPECT_CALL(numberGenerator, generate(3))
      .Times(3)
      .WillOnce(Return(std::vector<int>{0, 1, 2}))
      .WillOnce(Return(std::vector<int>{3, 0, 1}))
      .WillOnce(Return(std::vector<int>{2, 3, 0}));

  Genotype genotype1{0, 1, 2};
  Genotype genotype2{3, 0, 1};
  Genotype genotype3{2, 3, 0};

  Individual individual1(genotype1);
  Individual individual2(genotype2);
  Individual individual3(genotype3);

  RandomInitializer initializer(numberGenerator, 3);
  Population population = initializer.initialize(3);

  ASSERT_EQ(individual1, *population[0]);
  ASSERT_EQ(individual2, *population[1]);
  ASSERT_EQ(individual3, *population[2]);
}
