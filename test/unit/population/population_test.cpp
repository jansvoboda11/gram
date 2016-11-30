#include <gtest/gtest.h>

#include <gram/population/Population.h>

using namespace gram::population;
using namespace gram::individual;

TEST(population_test, test_it_accepts_individuals) {
  Genotype firstGenotype{1, 2, 3};
  Genotype secondGenotype{4, 5, 6};

  Individual firstIndividual(firstGenotype);
  Individual secondIndividual(secondGenotype);

  std::vector<Individual> individuals{firstIndividual, secondIndividual};

  Population population(individuals);

  ASSERT_EQ(firstIndividual, population[0]);
  ASSERT_EQ(secondIndividual, population[1]);
}
