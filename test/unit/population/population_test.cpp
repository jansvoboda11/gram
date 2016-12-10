#include <gtest/gtest.h>

#include <gram/population/Population.h>

using namespace gram::individual;
using namespace gram::population;

TEST(population_test, test_it_does_not_return_best_individual_when_empty) {
  Population population;

  ASSERT_THROW(population.bestIndividual(), std::logic_error);
}

TEST(population_test, test_it_returns_best_individual) {
  Genotype firstGenotype{0};
  Genotype secondGenotype{1};
  Genotype thirdGenotype{2};

  auto firstIndividual = std::make_shared<Individual>(firstGenotype);
  auto secondIndividual = std::make_shared<Individual>(secondGenotype);
  auto thirdIndividual = std::make_shared<Individual>(thirdGenotype);

  firstIndividual->setFitness(1.0);
  secondIndividual->setFitness(0.5);
  thirdIndividual->setFitness(2.0);

  Population population{firstIndividual, secondIndividual, thirdIndividual};

  ASSERT_EQ(secondIndividual, population.bestIndividual());
}
