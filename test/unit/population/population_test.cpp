#include <gtest/gtest.h>

#include <gram/population/Population.h>

using namespace gram::individual;
using namespace gram::population;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  Genotype genotype;

  Individual firstIndividual({1});
  Individual secondIndividual(genotype);
  Individual thirdIndividual(genotype);

  firstIndividual.setFitness(1.0);
  secondIndividual.setFitness(0.5);
  thirdIndividual.setFitness(2.0);

  Population population{firstIndividual, secondIndividual, thirdIndividual};

  ASSERT_EQ(secondIndividual, population.bestIndividual());
}
