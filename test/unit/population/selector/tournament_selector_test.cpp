#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/selector/TournamentSelector.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  vector<shared_ptr<Individual>> individuals;

  TournamentSelector selector(move(numberGenerator));

  ASSERT_THROW(selector.select(individuals), logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  Mock<Individual> individual;
  Fake(Dtor(individual));
  auto sharedIndividual = shared_ptr<Individual>(&individual.get());

  vector<shared_ptr<Individual>> individuals{sharedIndividual};

  TournamentSelector selector(move(numberGenerator));

  ASSERT_EQ(*sharedIndividual, *selector.select(individuals));
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  When(Method(numberGeneratorMock, generate)).Return(1).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;
  Mock<Individual> individual4Mock;

  Fake(Dtor(individual1Mock));
  Fake(Dtor(individual2Mock));
  Fake(Dtor(individual3Mock));
  Fake(Dtor(individual4Mock));

  When(Method(individual1Mock, fitness)).AlwaysReturn(0.0);
  When(Method(individual2Mock, fitness)).AlwaysReturn(1.0);
  When(Method(individual3Mock, fitness)).AlwaysReturn(2.0);
  When(Method(individual4Mock, fitness)).AlwaysReturn(3.0);

  auto individual1 = shared_ptr<Individual>(&individual1Mock.get());
  auto individual2 = shared_ptr<Individual>(&individual2Mock.get());
  auto individual3 = shared_ptr<Individual>(&individual3Mock.get());
  auto individual4 = shared_ptr<Individual>(&individual4Mock.get());

  vector<shared_ptr<Individual>> individuals{individual1, individual2, individual3, individual4};

  TournamentSelector selector(move(numberGenerator));

  ASSERT_EQ(*individual2, *selector.select(individuals));
}
