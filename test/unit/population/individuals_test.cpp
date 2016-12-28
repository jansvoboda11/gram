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
  Mock<Individual> individual1;
  Mock<Individual> individual2;
  Mock<Individual> individual3;

  When(Method(individual1, fitness)).AlwaysReturn(1.0);
  When(Method(individual2, fitness)).AlwaysReturn(0.5);
  When(Method(individual3, fitness)).AlwaysReturn(2.0);

  auto sharedIndividual1 = make_shared<Individual>(individual1.get());
  auto sharedIndividual2 = make_shared<Individual>(individual2.get());
  auto sharedIndividual3 = make_shared<Individual>(individual3.get());

  Individuals individuals({sharedIndividual1, sharedIndividual2, sharedIndividual3});

  ASSERT_EQ(*sharedIndividual2, individuals.bestIndividual());
}
