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

  Genotype firstGenotype{0, 1, 2};
  Genotype secondGenotype{3, 0, 1};
  Genotype thirdGenotype{2, 3, 0};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);
  Individual thirdIndividual(thirdGenotype);

  RandomInitializer initializer(numberGenerator, 3);
  Population population = initializer.initialize(3);

  ASSERT_EQ(firstIndividual, population[0]);
  ASSERT_EQ(secondIndividual, population[1]);
  ASSERT_EQ(thirdIndividual, population[2]);
}
