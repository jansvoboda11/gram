#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/Population.h>

using namespace gram::individual;
using namespace gram::population;
using namespace gram::language;

using namespace fakeit;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  std::vector<std::shared_ptr<Individual>> individuals;

  Mock<Generator> generatorMock;
  Fake(Dtor(generatorMock));
  auto generator = std::shared_ptr<Generator>(&generatorMock.get());

  Population population(individuals, generator);

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;

  Fake(Dtor(individual1Mock));
  Fake(Dtor(individual2Mock));
  Fake(Dtor(individual3Mock));

  When(Method(individual1Mock, fitness)).AlwaysReturn(1.0);
  When(Method(individual2Mock, fitness)).AlwaysReturn(0.5);
  When(Method(individual3Mock, fitness)).AlwaysReturn(2.0);

  auto individual1 = std::shared_ptr<Individual>(&individual1Mock.get());
  auto individual2 = std::shared_ptr<Individual>(&individual2Mock.get());
  auto individual3 = std::shared_ptr<Individual>(&individual3Mock.get());

  std::vector<std::shared_ptr<Individual>> individuals{individual1, individual2, individual3};

  Mock<Generator> generatorMock;
  Fake(Dtor(generatorMock));
  auto generator = std::shared_ptr<Generator>(&generatorMock.get());

  Population population(individuals, generator);

  ASSERT_EQ(individual2, population.bestIndividual());
}
