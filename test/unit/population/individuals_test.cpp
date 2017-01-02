#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/population/Individuals.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(individuals_test, test_it_handles_no_individuals) {
  Individuals individuals;

  ASSERT_THROW(individuals.bestIndividual(), logic_error);
}

TEST(individuals_test, test_it_recognizes_the_fittest_individual) {
  Mock<Individual> individual1Mock;
  Mock<Individual> individual2Mock;
  Mock<Individual> individual3Mock;

  When(Method(individual1Mock, fitness)).AlwaysReturn(1.0);
  When(Method(individual2Mock, fitness)).AlwaysReturn(0.5);
  When(Method(individual3Mock, fitness)).AlwaysReturn(2.0);

  Individual individual1 = individual1Mock.get();
  Individual individual2 = individual2Mock.get();
  Individual individual3 = individual3Mock.get();

  auto sharedIndividual1 = make_shared<Individual>(individual1);
  auto sharedIndividual2 = make_shared<Individual>(individual2);
  auto sharedIndividual3 = make_shared<Individual>(individual3);

  Individuals individuals;
  individuals.addIndividual(sharedIndividual1);
  individuals.addIndividual(sharedIndividual2);
  individuals.addIndividual(sharedIndividual3);

  ASSERT_EQ(individual2, individuals.bestIndividual());
}
