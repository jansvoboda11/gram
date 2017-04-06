#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/selector/TournamentSelector.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Individuals individuals;

  TournamentSelector selector(2, move(numberGenerator));

  ASSERT_THROW(selector.select(individuals), logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Mock<NumberGenerator> numberGeneratorMock;
  Fake(Dtor(numberGeneratorMock));
  auto numberGenerator = unique_ptr<NumberGenerator>(&numberGeneratorMock.get());

  Mock<Individual> individualMock;
  Individual individual = individualMock.get();
  auto sharedIndividual = make_shared<Individual>(individual);

  Individuals individuals;
  individuals.addIndividual(sharedIndividual);

  TournamentSelector selector(2, move(numberGenerator));

  ASSERT_EQ(individual, selector.select(individuals));
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

  When(Method(individual1Mock, fitness)).AlwaysReturn(0.0);
  When(Method(individual2Mock, fitness)).AlwaysReturn(1.0);
  When(Method(individual3Mock, fitness)).AlwaysReturn(2.0);
  When(Method(individual4Mock, fitness)).AlwaysReturn(3.0);

  Individual individual1 = individual1Mock.get();
  Individual individual2 = individual2Mock.get();
  Individual individual3 = individual3Mock.get();
  Individual individual4 = individual4Mock.get();

  auto sharedIndividual1 = make_shared<Individual>(individual1);
  auto sharedIndividual2 = make_shared<Individual>(individual2);
  auto sharedIndividual3 = make_shared<Individual>(individual3);
  auto sharedIndividual4 = make_shared<Individual>(individual4);

  Individuals individuals;
  individuals.addIndividual(sharedIndividual1);
  individuals.addIndividual(sharedIndividual2);
  individuals.addIndividual(sharedIndividual3);
  individuals.addIndividual(sharedIndividual4);

  TournamentSelector selector(2, move(numberGenerator));

  ASSERT_EQ(individual2, selector.select(individuals));
}
