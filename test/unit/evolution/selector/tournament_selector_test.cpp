#include <gtest/gtest.h>

#include <gram/evolution/selector/TournamentSelector.h>
#include <gram/fake/util/FakeNumberGenerator.h>

using namespace gram::evolution;
using namespace gram::fake::util;
using namespace gram::individual;
using namespace gram::population;

TEST(tournament_selector_test, test_it_handles_empty_population) {
  Population population{};
  FakeNumberGenerator generator{};

  TournamentSelector selector(generator);

  ASSERT_THROW(selector.select(population), std::logic_error);
}

TEST(tournament_selector_test, test_it_select_the_only_individual) {
  Genotype genotype{0};
  Individual individual(genotype);
  Population population{individual};

  FakeNumberGenerator generator{};

  TournamentSelector selector(generator);

  ASSERT_EQ(individual, selector.select(population));
}

TEST(tournament_selector_test, test_it_selects_best_individual_from_randomly_selected_group) {
  Genotype firstGenotype{0};
  Genotype secondGenotype{1};
  Genotype thirdGenotype{2};
  Genotype fourthGenotype{3};
  Genotype fifthGenotype{4};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);
  Individual thirdIndividual(thirdGenotype);
  Individual fourthIndividual(fourthGenotype);
  Individual fifthIndividual(fifthGenotype);

  firstIndividual.setFitness(1.5);
  secondIndividual.setFitness(1.0);
  thirdIndividual.setFitness(0.5);
  fourthIndividual.setFitness(2.0);

  Population population{firstIndividual, secondIndividual, thirdIndividual, fourthIndividual};
  FakeNumberGenerator generator{1, 3};

  TournamentSelector selector(generator);

  ASSERT_EQ(secondIndividual, selector.select(population));
}
