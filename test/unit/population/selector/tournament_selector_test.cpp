#include <gtest/gtest.h>

#include <gram/population/selector/TournamentSelector.h>

#include "../../../lib/fakeit/fakeit.hpp"

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;
using namespace gram::language;

using namespace fakeit;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Population population{};

  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&mock.get());

  TournamentSelector selector(std::move(numberGenerator));

  ASSERT_THROW(selector.select(population), std::logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Genotype genotype{0};

  Mock<Individual> individual;
  Fake(Dtor(individual));

  auto sharedIndividual = std::shared_ptr<Individual>(&individual.get());

  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&mock.get());

  Population population{sharedIndividual};

  TournamentSelector selector(std::move(numberGenerator));

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual.get(), *selectedIndividual);
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1).Return(3);

  auto numberGenerator = std::unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;
  Mock<Individual> individual4Mock;

  Fake(Dtor(individual1Mock));
  Fake(Dtor(individual2Mock));
  Fake(Dtor(individual3Mock));
  Fake(Dtor(individual4Mock));

  When(Method(individual1Mock, getFitness)).Return(0.0);
  When(Method(individual2Mock, getFitness)).Return(1.0);
  When(Method(individual3Mock, getFitness)).Return(2.0);
  When(Method(individual4Mock, getFitness)).Return(3.0);

  auto individual1 = std::shared_ptr<Individual>(&individual1Mock.get());
  auto individual2 = std::shared_ptr<Individual>(&individual2Mock.get());
  auto individual3 = std::shared_ptr<Individual>(&individual3Mock.get());
  auto individual4 = std::shared_ptr<Individual>(&individual4Mock.get());

  Population population{individual1, individual2, individual3, individual4};

  TournamentSelector selector(std::move(numberGenerator));

  std::shared_ptr<Individual> selectedIndividual = selector.select(population);

  ASSERT_EQ(individual2, selectedIndividual);
}
