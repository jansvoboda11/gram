#include <gtest/gtest.h>

#include <gram/population/Population.h>
#include <gram/individual/IndividualMock.h>

using namespace gram::individual;
using namespace gram::population;

using ::testing::NiceMock;
using ::testing::Return;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  auto individual1 = std::make_shared<NiceMock<IndividualMock>>();
  auto individual2 = std::make_shared<NiceMock<IndividualMock>>();
  auto individual3 = std::make_shared<NiceMock<IndividualMock>>();

  ON_CALL(*individual1, getFitness())
      .WillByDefault(Return(1.0));
  ON_CALL(*individual2, getFitness())
      .WillByDefault(Return(0.5));
  ON_CALL(*individual3, getFitness())
      .WillByDefault(Return(2.0));

  Population population{individual1, individual2, individual3};

  std::shared_ptr<Individual> bestIndividual = population.bestIndividual();

  ASSERT_EQ(individual2, bestIndividual);
}
