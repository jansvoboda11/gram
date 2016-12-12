#include <gtest/gtest.h>

#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/util/NumberGeneratorMock.h>
#include <gram/individual/IndividualMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;

using ::testing::NiceMock;
using ::testing::Return;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Population population{};

  NiceMock<NumberGeneratorMock> generator;

  TournamentSelector selector(generator);

  ASSERT_THROW(selector.select(population), std::logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Genotype genotype{};
  auto individual = std::make_shared<NiceMock<Individual>>(genotype);
  Population population{individual};

  NiceMock<NumberGeneratorMock> generator;

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual, selectedIndividual);
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  NiceMock<NumberGeneratorMock> generator;
  EXPECT_CALL(generator, generate())
      .WillOnce(Return(1))
      .WillOnce(Return(3));

  auto individual1 = std::make_shared<NiceMock<IndividualMock>>();
  auto individual2 = std::make_shared<NiceMock<IndividualMock>>();
  auto individual3 = std::make_shared<NiceMock<IndividualMock>>();
  auto individual4 = std::make_shared<NiceMock<IndividualMock>>();

  ON_CALL(*individual1, getFitness())
      .WillByDefault(Return(0.0));
  ON_CALL(*individual2, getFitness())
      .WillByDefault(Return(1.0));
  ON_CALL(*individual3, getFitness())
      .WillByDefault(Return(2.0));
  ON_CALL(*individual4, getFitness())
      .WillByDefault(Return(3.0));

  Population population{individual1, individual2, individual3, individual4};

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual2, selectedIndividual);
}
