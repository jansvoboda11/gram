#include <gtest/gtest.h>

#include <gram/population/Population.h>
#include <gram/individual/IndividualMock.h>

#include "../GrammarTest.h"

using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::grammar;

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST_F(GrammarTest, test_it_returns_best_individual) {
  ON_CALL(*language, expand(_))
      .WillByDefault(Return(*phenotype));

  Genotype genotype{0};

  auto individual1 = std::make_shared<NiceMock<IndividualMock>>(genotype, *language);
  auto individual2 = std::make_shared<NiceMock<IndividualMock>>(genotype, *language);
  auto individual3 = std::make_shared<NiceMock<IndividualMock>>(genotype, *language);

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
