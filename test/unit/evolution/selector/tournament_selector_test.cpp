#include <gtest/gtest.h>

#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/util/NumberGeneratorMock.h>
#include <gram/individual/IndividualMock.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;

using ::testing::Return;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Population population{};

  NumberGeneratorMock generator;
  EXPECT_CALL(generator, generate())
      .Times(0);

  TournamentSelector selector(generator);

  ASSERT_THROW(selector.select(population), std::logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Genotype genotype{};
  auto individual = std::make_shared<Individual>(genotype);
  Population population{individual};

  NumberGeneratorMock generator;
  EXPECT_CALL(generator, generate())
      .Times(0);

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual, selectedIndividual);
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  NumberGeneratorMock generator;
  EXPECT_CALL(generator, generate())
      .Times(2)
      .WillOnce(Return(1))
      .WillOnce(Return(3));

  auto individual1 = std::make_shared<IndividualMock>();
  auto individual2 = std::make_shared<IndividualMock>();
  auto individual3 = std::make_shared<IndividualMock>();
  auto individual4 = std::make_shared<IndividualMock>();

  EXPECT_CALL(*individual1, getFitness())
      .Times(0);
  EXPECT_CALL(*individual2, getFitness())
      .Times(1)
      .WillOnce(Return(1.0));
  EXPECT_CALL(*individual3, getFitness())
      .Times(0);
  EXPECT_CALL(*individual4, getFitness())
      .Times(1)
      .WillOnce(Return(2.0));

  Population population{individual1, individual2, individual3, individual4};

  TournamentSelector selector(generator);

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual2, selectedIndividual);
}
