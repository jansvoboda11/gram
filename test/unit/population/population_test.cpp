#include <gtest/gtest.h>

#include <gram/population/Population.h>
#include <gram/individual/IndividualMock.h>

using namespace gram::individual;
using namespace gram::population;

using ::testing::AtLeast;
using ::testing::Return;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  auto individual1 = std::make_shared<IndividualMock>();
  auto individual2 = std::make_shared<IndividualMock>();
  auto individual3 = std::make_shared<IndividualMock>();

  EXPECT_CALL(*individual1, getFitness())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(1.0));
  EXPECT_CALL(*individual2, getFitness())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(0.5));
  EXPECT_CALL(*individual3, getFitness())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(2.0));

  Population population{individual1, individual2, individual3};

  ASSERT_EQ(individual2, population.bestIndividual());
}
