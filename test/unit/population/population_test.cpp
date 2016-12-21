#include <gtest/gtest.h>

#include <gram/population/Population.h>

#include "../../lib/fakeit/fakeit.hpp"

using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;
using namespace gram::grammar;

using namespace fakeit;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;

  Fake(Dtor(individual1Mock));
  Fake(Dtor(individual2Mock));
  Fake(Dtor(individual3Mock));

  When(Method(individual1Mock, getFitness)).AlwaysReturn(1.0);
  When(Method(individual2Mock, getFitness)).AlwaysReturn(0.5);
  When(Method(individual3Mock, getFitness)).AlwaysReturn(2.0);

  auto individual1 = std::shared_ptr<Individual>(&individual1Mock.get());
  auto individual2 = std::shared_ptr<Individual>(&individual2Mock.get());
  auto individual3 = std::shared_ptr<Individual>(&individual3Mock.get());

  Population population{individual1, individual2, individual3};

  std::shared_ptr<Individual> bestIndividual = population.bestIndividual();

  ASSERT_EQ(individual2, bestIndividual);
}
