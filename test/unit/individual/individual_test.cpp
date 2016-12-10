#include <gtest/gtest.h>

#include <gram/individual/Individual.h>

using namespace gram::individual;

TEST(individual_test, test_it_returns_valid_fitness) {
  Genotype genotype{1, 2, 3};

  Individual individual(genotype);

  individual.setFitness(1.5);
  double fitness = individual.getFitness();

  ASSERT_EQ(1.5, fitness);
}

TEST(individual_test, test_it_rejects_negative_fitness) {
  Genotype genotype{1, 2, 3};

  Individual individual(genotype);

  ASSERT_THROW(individual.setFitness(-1), std::logic_error);
}

TEST(individual_test, test_it_does_not_return_fitness_if_not_calculated) {
  Genotype genotype{1, 2, 3};

  Individual individual(genotype);

  ASSERT_THROW(individual.getFitness(), std::logic_error);
}

TEST(individual_test, test_it_recognizes_two_equal_objects) {
  Genotype genotype{1, 2, 3};

  Individual individual1(genotype);
  Individual individual2(genotype);

  ASSERT_TRUE(individual1 == individual2);
}

TEST(individual_test, test_it_recognizes_two_different_objects) {
  Genotype genotype1{1, 2, 3};
  Genotype genotype2{3, 2, 1};

  Individual individual1(genotype1);
  Individual individual2(genotype2);

  ASSERT_TRUE(individual1 != individual2);
}
