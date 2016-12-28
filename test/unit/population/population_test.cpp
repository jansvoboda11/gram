#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/Population.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Individuals individuals;

  Mock<Generator> generatorMock;
  Fake(Dtor(generatorMock));
  auto generator = shared_ptr<Generator>(&generatorMock.get());

  Population population(individuals, generator);

  ASSERT_THROW(population.bestIndividual(), logic_error);
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

  auto individual1 = shared_ptr<Individual>(&individual1Mock.get());
  auto individual2 = shared_ptr<Individual>(&individual2Mock.get());
  auto individual3 = shared_ptr<Individual>(&individual3Mock.get());

  Individuals individuals({individual1, individual2, individual3});

  Mock<Generator> generatorMock;
  Fake(Dtor(generatorMock));
  auto generator = shared_ptr<Generator>(&generatorMock.get());

  Population population(individuals, generator);

  ASSERT_EQ(*individual2, population.bestIndividual());
}
